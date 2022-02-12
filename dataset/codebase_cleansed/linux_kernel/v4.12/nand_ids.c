const struct nand_manufacturer *nand_get_manufacturer(u8 id)
{
int i;
for (i = 0; i < ARRAY_SIZE(nand_manufacturers); i++)
if (nand_manufacturers[i].id == id)
return &nand_manufacturers[i];
return NULL;
}
