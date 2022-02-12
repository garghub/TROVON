void
g_slist_free_full(GSList *list,
GDestroyNotify free_func)
{
g_slist_foreach(list, (GFunc)free_func, NULL);
g_slist_free(list);
}
void
g_list_free_full(GList *list,
GDestroyNotify free_func)
{
g_list_foreach(list, (GFunc)free_func, NULL);
g_list_free(list);
}
gint64 g_get_monotonic_time (void)
{
GTimeVal result;
g_get_current_time(&result);
return result.tv_sec*1000000 + result.tv_usec;
}
