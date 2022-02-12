gdouble
type_util_guint64_to_gdouble(guint64 value)
{
if (value & G_GUINT64_CONSTANT (0x8000000000000000))
return (gdouble) ((gint64) value) + (gdouble) 18446744073709551616.;
else
return (gdouble) ((gint64) value);
}
guint64
type_util_gdouble_to_guint64(gdouble value)
{
if (value < (gdouble) 9223372036854775808.)
return ((guint64) ((gint64) value));
value -= (gdouble) 18446744073709551616.;
return ((guint64) ((gint64) value));
}
