bool timerqueue_add(struct timerqueue_head *head, struct timerqueue_node *node)
{
struct rb_node **p = &head->head.rb_node;
struct rb_node *parent = NULL;
struct timerqueue_node *ptr;
WARN_ON_ONCE(!RB_EMPTY_NODE(&node->node));
while (*p) {
parent = *p;
ptr = rb_entry(parent, struct timerqueue_node, node);
if (node->expires.tv64 < ptr->expires.tv64)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
}
rb_link_node(&node->node, parent, p);
rb_insert_color(&node->node, &head->head);
if (!head->next || node->expires.tv64 < head->next->expires.tv64) {
head->next = node;
return true;
}
return false;
}
bool timerqueue_del(struct timerqueue_head *head, struct timerqueue_node *node)
{
WARN_ON_ONCE(RB_EMPTY_NODE(&node->node));
if (head->next == node) {
struct rb_node *rbn = rb_next(&node->node);
head->next = rbn ?
rb_entry(rbn, struct timerqueue_node, node) : NULL;
}
rb_erase(&node->node, &head->head);
RB_CLEAR_NODE(&node->node);
return head->next != NULL;
}
struct timerqueue_node *timerqueue_iterate_next(struct timerqueue_node *node)
{
struct rb_node *next;
if (!node)
return NULL;
next = rb_next(&node->node);
if (!next)
return NULL;
return container_of(next, struct timerqueue_node, node);
}
