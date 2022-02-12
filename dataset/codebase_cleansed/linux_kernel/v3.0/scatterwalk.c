void *scatterwalk_whichbuf(struct scatter_walk *walk, unsigned int nbytes, void *scratch)
{
if (nbytes <= walk->len_this_page &&
(((unsigned long)walk->data) & (PAGE_CACHE_SIZE - 1)) + nbytes <=
PAGE_CACHE_SIZE)
return walk->data;
else
return scratch;
}
static void memcpy_dir(void *buf, void *sgdata, size_t nbytes, int out)
{
if (out)
memcpy(sgdata, buf, nbytes);
else
memcpy(buf, sgdata, nbytes);
}
void scatterwalk_start(struct scatter_walk *walk, struct scatterlist *sg)
{
unsigned int rest_of_page;
walk->sg = sg;
walk->page = sg->page;
walk->len_this_segment = sg->length;
rest_of_page = PAGE_CACHE_SIZE - (sg->offset & (PAGE_CACHE_SIZE - 1));
walk->len_this_page = min(sg->length, rest_of_page);
walk->offset = sg->offset;
}
void scatterwalk_map(struct scatter_walk *walk, int out)
{
walk->data = crypto_kmap(walk->page, out) + walk->offset;
}
static void scatterwalk_pagedone(struct scatter_walk *walk, int out,
unsigned int more)
{
if (out)
flush_dcache_page(walk->page);
if (more) {
walk->len_this_segment -= walk->len_this_page;
if (walk->len_this_segment) {
walk->page++;
walk->len_this_page = min(walk->len_this_segment,
(unsigned)PAGE_CACHE_SIZE);
walk->offset = 0;
}
else
scatterwalk_start(walk, sg_next(walk->sg));
}
}
void scatterwalk_done(struct scatter_walk *walk, int out, int more)
{
crypto_kunmap(walk->data, out);
if (walk->len_this_page == 0 || !more)
scatterwalk_pagedone(walk, out, more);
}
int scatterwalk_copychunks(void *buf, struct scatter_walk *walk,
size_t nbytes, int out)
{
if (buf != walk->data) {
while (nbytes > walk->len_this_page) {
memcpy_dir(buf, walk->data, walk->len_this_page, out);
buf += walk->len_this_page;
nbytes -= walk->len_this_page;
crypto_kunmap(walk->data, out);
scatterwalk_pagedone(walk, out, 1);
scatterwalk_map(walk, out);
}
memcpy_dir(buf, walk->data, nbytes, out);
}
walk->offset += nbytes;
walk->len_this_page -= nbytes;
walk->len_this_segment -= nbytes;
return 0;
}
