char *
CFString_to_C_string(CFStringRef cfstring)
{
CFIndex string_len;
char *string;
string_len = CFStringGetMaximumSizeForEncoding(CFStringGetLength(cfstring),
kCFStringEncodingUTF8);
string = (char *)g_malloc(string_len + 1);
if (!CFStringGetCString(cfstring, string, string_len + 1,
kCFStringEncodingUTF8)) {
g_free(string);
return NULL;
}
return string;
}
