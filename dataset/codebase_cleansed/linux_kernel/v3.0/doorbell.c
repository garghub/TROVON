int mlx4_ib_db_map_user(struct mlx4_ib_ucontext *context, unsigned long virt,
struct mlx4_db *db)
{
struct mlx4_ib_user_db_page *page;
struct ib_umem_chunk *chunk;
int err = 0;
mutex_lock(&context->db_page_mutex);
list_for_each_entry(page, &context->db_page_list, list)
if (page->user_virt == (virt & PAGE_MASK))
goto found;
page = kmalloc(sizeof *page, GFP_KERNEL);
if (!page) {
err = -ENOMEM;
goto out;
}
page->user_virt = (virt & PAGE_MASK);
page->refcnt = 0;
page->umem = ib_umem_get(&context->ibucontext, virt & PAGE_MASK,
PAGE_SIZE, 0, 0);
if (IS_ERR(page->umem)) {
err = PTR_ERR(page->umem);
kfree(page);
goto out;
}
list_add(&page->list, &context->db_page_list);
found:
chunk = list_entry(page->umem->chunk_list.next, struct ib_umem_chunk, list);
db->dma = sg_dma_address(chunk->page_list) + (virt & ~PAGE_MASK);
db->u.user_page = page;
++page->refcnt;
out:
mutex_unlock(&context->db_page_mutex);
return err;
}
void mlx4_ib_db_unmap_user(struct mlx4_ib_ucontext *context, struct mlx4_db *db)
{
mutex_lock(&context->db_page_mutex);
if (!--db->u.user_page->refcnt) {
list_del(&db->u.user_page->list);
ib_umem_release(db->u.user_page->umem);
kfree(db->u.user_page);
}
mutex_unlock(&context->db_page_mutex);
}
