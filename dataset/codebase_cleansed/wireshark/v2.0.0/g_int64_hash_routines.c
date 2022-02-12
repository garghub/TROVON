gboolean
g_int64_equal (gconstpointer v1,
gconstpointer v2)
{
return *((const gint64*) v1) == *((const gint64*) v2);
}
guint
g_int64_hash (gconstpointer v)
{
return (guint) *(const gint64*) v;
}
