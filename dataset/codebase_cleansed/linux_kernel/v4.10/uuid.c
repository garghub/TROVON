void class_uuid_unparse(class_uuid_t uu, struct obd_uuid *out)
{
sprintf(out->uuid, "%pU", uu);
}
