int readlines(char lines[][MAXLEN], int maxlines)
{
  int len, nlines;

  nlines = 0;
  while ((len = getline(lines[nlines], MAXLEN)) > 0)
    if (nlines >= maxlines)                         
      return -1;           
    else
      lines[nlines++][len - 1] = '\0'; 
  return nlines;
}
 