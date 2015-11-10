---
layout: post
title: The great answer on stackoverflow
---

I recently found out that I got an "Great Answer" badge on [stackoverflow](http://stackoverflow.com). This means that I answered a question that has received a hundered upvotes - meaning that I helped many people with my answer.

[The question](http://stackoverflow.com/questions/1785744/) was about someone creating an instance of `Random` in a loop, then generating a random number with it but then he got every time the same result(in the loop). He wondered why, and how he could fix this. The question has now been viewed 63187 times.

[Then I posted](http://stackoverflow.com/a/18267477/2622807) somewhat irrelevantely this:
```c#
Random rand = new Random(Guid.NewGuid().GetHashCode());
```

And now it has 101 upvotes, and 2 downvotes.

Now, you may wonder, how did I come up with this?  Finding a solution to seeding a random generator that's not time-based and is still random and thus the result unique? This might be a little hacky, but this helped a lot of people for a lot of scenarios(like when two programs launch at roughly exact the same time).

I don't know. I was 14 back then and relatively new to programming - [my first code](http://web.archive.org/web/20151110205042/http://mcdzienny.cba.pl/viewtopic.php?f=19&t=1565) was almost  one year ago at that time(technically not my first, but that was the first time I _knew_ I was coding). My grammar was bad nor did I understand stackoverflow(not that I do now). This is magic to me.

This answer _does_ solve OPs problem, but not in a good way and without an explanation. I don't even know why I posted this and how I got there. The question already was roughly 4 years old already at that time.

All my other answers and questions arround that time weren't very high quality either.

I feel a little odd about the two downvotes: They took place the day before yesterday, which is pretty weird if you consider the timespan of this question.

I don't know. I do stuff on the internet, seemingly without any quality control, and sometimes something good happens with it.

Which brings me to the question: Why exactly do I have no quality control and should I do something about it?

Heh. I'm getting some more tea.