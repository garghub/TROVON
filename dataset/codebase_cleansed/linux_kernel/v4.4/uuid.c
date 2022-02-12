void class_uuid_unparse(class_uuid_t uu, struct obd_uuid *out)\r\n{\r\nsprintf(out->uuid, "%pU", uu);\r\n}
