static int zero_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
if (argc != 0) {
ti->error = "No arguments required";
return -EINVAL;
}
ti->num_discard_bios = 1;
return 0;
}
static int zero_map(struct dm_target *ti, struct bio *bio)
{
switch (bio_op(bio)) {
case REQ_OP_READ:
if (bio->bi_opf & REQ_RAHEAD) {
return -EIO;
}
zero_fill_bio(bio);
break;
case REQ_OP_WRITE:
break;
default:
return -EIO;
}
bio_endio(bio);
return DM_MAPIO_SUBMITTED;
}
static int __init dm_zero_init(void)
{
int r = dm_register_target(&zero_target);
if (r < 0)
DMERR("register failed %d", r);
return r;
}
static void __exit dm_zero_exit(void)
{
dm_unregister_target(&zero_target);
}
