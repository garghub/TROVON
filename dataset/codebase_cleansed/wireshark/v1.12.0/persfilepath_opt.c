gboolean
persfilepath_opt(int opt _U_, const char *optstr)
{
gchar *p, *colonp;
colonp = strchr(optstr, ':');
if (colonp == NULL) {
return FALSE;
}
p = colonp;
*p++ = '\0';
while (isspace((guchar)*p))
p++;
if (*p == '\0') {
*colonp = ':';
return FALSE;
}
if(test_for_directory(p) != EISDIR) {
*colonp = ':';
return FALSE;
}
if (strcmp(optstr,"persconf") == 0) {
set_persconffile_dir(p);
} else if (strcmp(optstr,"persdata") == 0) {
set_persdatafile_dir(p);
} else {
return FALSE;
}
*colonp = ':';
return TRUE;
}
