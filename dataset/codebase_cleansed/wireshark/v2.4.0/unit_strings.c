char* unit_name_string_get_value(guint32 value, unit_name_string* units)
{
if (units->plural == NULL)
return units->singular;
return plurality(value, units->singular, units->plural);
}
char* unit_name_string_get_value64(guint64 value, unit_name_string* units)
{
if (units->plural == NULL)
return units->singular;
return plurality(value, units->singular, units->plural);
}
char* unit_name_string_get_double(double value, unit_name_string* units)
{
if (units->plural == NULL)
return units->singular;
return plurality(value, units->singular, units->plural);
}
