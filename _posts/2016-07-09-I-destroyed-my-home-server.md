---
layout: post
title: I destroyed my home server
---

So today I saw [nextcloud](https://nextcloud.com/), and I started to install it immidiately. And I was quite lazy so I followed a tutorial, since I didn't really understand the install docs, since I was quite lazy, and also a little tired and maybe even a little neglectful.

[The tutorial](https://www.linux.com/learn/how-install-nextcloud-server-ubuntu) contained a script that is supposed to fix permissions in `/var/www/nextcloud`

This was the script:
{% highlight bash %}
#!/bin/bash

ocpath='/var/www/nextcloud'

htuser='www-data'

htgroup='www-data'

rootuser='root'


printf "Creating possible missing Directories\n"

mkdir -p $ocpath/data

mkdir -p $ocpath/assets

mkdir -p $ocpath/updater


printf "chmod Files and Directories\n"

find ${ocpath}/ -type f -print0 | xargs -0 chmod 0640

find ${ocpath}/ -type d -print0 | xargs -0 chmod 0750


printf "chown Directories\n"

chown -R ${rootuser}:${htgroup} ${ocpath}/

chown -R ${htuser}:${htgroup} ${ocpath}/apps/

chown -R ${htuser}:${htgroup} ${ocpath}/assets/

chown -R ${htuser}:${htgroup} ${ocpath}/config/

chown -R ${htuser}:${htgroup} ${ocpath}/data/

chown -R ${htuser}:${htgroup} ${ocpath}/themes/

chown -R ${htuser}:${htgroup} ${ocpath}/updater/


chmod +x ${ocpath}/occ


printf "chmod/chown .htaccess\n"

if [ -f ${ocpath}/.htaccess ]

then

 chmod 0644 ${ocpath}/.htaccess

 chown ${rootuser}:${htgroup} ${ocpath}/.htaccess

fi

if [ -f ${ocpath}/data/.htaccess ]

then

 chmod 0644 ${ocpath}/data/.htaccess

 chown ${rootuser}:${htgroup} ${ocpath}/data/.htaccess

fi
{% endhighlight %}

I pasted it into vim, saved it as `nextcloud_permissions.sh`, gave it the execution permissions(`chmod +x nextcloud_permissions.sh`) Then you're supposed to run it: `sudo ./nextcloud_permissions.sh`

But then I got a bunch of `access denied` and `permission insufficient`(or something) just hell. Then I ran it again: `/bin/something/sudo-: access denied`. My heart started to beat faster.

I tried to `ls`(list files): `/bin/something/ls-: access denied`. I tried to reconnect, but that didn't work. Then I realised I broke my server.

Later I found out what went wrong: I didn't notice is that I didn't copy/paste it correctly. This was the top of the file: `cpath='/var/www/nextcloud'`, instead of this: 

```
#!/bin/bash

ocpath='/var/www/nextcloud'
```

Notice the `cpath` instead of `ocpath`. And then notice this line: `chown -R ${rootuser}:${htgroup} ${ocpath}/`

The line changes the owner of the directory `${ocpath}/` to `${rootuser}:${htgroup}` recursively.

`ocpath` is undefined, resulting in outputting `${ocpath}` into nothing, meaning that what will be executed is this: `chown -R root:www-data /`

So every file on my system is now owned by root, by the group `www-data`. It's virtually impossible to get it working properly again. No warning was thrown because I used `sudo` - meaning let this program do whatever it wants to the system.

Thankfully, my smb shares are still up, so I cloned some backed up config files I got access too - and the faulty script. Tomorrow I'm going to copy some config files I didn't got access to. Probably in recovery mode or a live usb or something. Because I'm lazy.

I don goofed
