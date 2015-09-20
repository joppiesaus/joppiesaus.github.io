# Made for joppiesaus.github.io
# Public Domain

import strutils, times

var title, permalink: string

echo("Title of your post? ")
title = readLine(stdin)
echo("And the permalink(file name)? ")
permalink = readLine(stdin)

writeFile(getDateStr() & '-' & permalink.replace(' ', '-'), "---\nlayout: post\ntitle: " & title & "\n---\n\n")

echo("Done!")
