static int c2_alloc_mqsp_chunk(struct c2_dev *c2dev, gfp_t gfp_mask,
struct sp_chunk **head)
{
int i;
struct sp_chunk *new_head;
dma_addr_t dma_addr;
new_head = dma_alloc_coherent(&c2dev->pcidev->dev, PAGE_SIZE,
&dma_addr, gfp_mask);
if (new_head == NULL)
return -ENOMEM;
new_head->dma_addr = dma_addr;
dma_unmap_addr_set(new_head, mapping, new_head->dma_addr);
new_head->next = NULL;
new_head->head = 0;
for (i = 0;
i < (PAGE_SIZE - sizeof(struct sp_chunk) -
sizeof(u16)) / sizeof(u16) - 1;
i++) {
new_head->shared_ptr[i] = i + 1;
}
new_head->shared_ptr[i] = 0xFFFF;
*head = new_head;
return 0;
}
int c2_init_mqsp_pool(struct c2_dev *c2dev, gfp_t gfp_mask,
struct sp_chunk **root)
{
return c2_alloc_mqsp_chunk(c2dev, gfp_mask, root);
}
void c2_free_mqsp_pool(struct c2_dev *c2dev, struct sp_chunk *root)
{
struct sp_chunk *next;
while (root) {
next = root->next;
dma_free_coherent(&c2dev->pcidev->dev, PAGE_SIZE, root,
dma_unmap_addr(root, mapping));
root = next;
}
}
__be16 *c2_alloc_mqsp(struct c2_dev *c2dev, struct sp_chunk *head,
dma_addr_t *dma_addr, gfp_t gfp_mask)
{
u16 mqsp;
while (head) {
mqsp = head->head;
if (mqsp != 0xFFFF) {
head->head = head->shared_ptr[mqsp];
break;
} else if (head->next == NULL) {
if (c2_alloc_mqsp_chunk(c2dev, gfp_mask, &head->next) ==
0) {
head = head->next;
mqsp = head->head;
head->head = head->shared_ptr[mqsp];
break;
} else
return NULL;
} else
head = head->next;
}
if (head) {
*dma_addr = head->dma_addr +
((unsigned long) &(head->shared_ptr[mqsp]) -
(unsigned long) head);
pr_debug("%s addr %p dma_addr %llx\n", __func__,
&(head->shared_ptr[mqsp]), (unsigned long long) *dma_addr);
return (__force __be16 *) &(head->shared_ptr[mqsp]);
}
return NULL;
}
void c2_free_mqsp(__be16 *mqsp)
{
struct sp_chunk *head;
u16 idx;
head = (struct sp_chunk *) ((unsigned long) mqsp & PAGE_MASK);
*mqsp = (__force __be16) head->head;
idx = (offset_in_page(mqsp)) >> 1;
idx -= (unsigned long) &(((struct sp_chunk *) 0)->shared_ptr[0]) >> 1;
head->shared_ptr[idx] = head->head;
head->head = idx;
}
