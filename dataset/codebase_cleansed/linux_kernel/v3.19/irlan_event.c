void irlan_next_client_state(struct irlan_cb *self, IRLAN_STATE state)
{
pr_debug("%s(), %s\n", __func__ , irlan_state[state]);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
self->client.state = state;
}
void irlan_next_provider_state(struct irlan_cb *self, IRLAN_STATE state)
{
pr_debug("%s(), %s\n", __func__ , irlan_state[state]);
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
self->provider.state = state;
}
