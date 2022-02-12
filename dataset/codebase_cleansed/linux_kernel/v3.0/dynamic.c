unsigned int create_irq_nr(unsigned int irq_want, int node)
{
int irq = irq_alloc_desc_at(irq_want, node);
if (irq < 0)
return 0;
activate_irq(irq);
return irq;
}
int create_irq(void)
{
int irq = irq_alloc_desc(numa_node_id());
if (irq >= 0)
activate_irq(irq);
return irq;
}
void destroy_irq(unsigned int irq)
{
irq_free_desc(irq);
}
void reserve_intc_vectors(struct intc_vect *vectors, unsigned int nr_vecs)
{
int i;
for (i = 0; i < nr_vecs; i++)
irq_reserve_irq(evt2irq(vectors[i].vect));
}
