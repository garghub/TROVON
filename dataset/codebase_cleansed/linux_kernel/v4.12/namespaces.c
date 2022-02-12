struct namespaces *namespaces__new(struct namespaces_event *event)
{
struct namespaces *namespaces;
u64 link_info_size = ((event ? event->nr_namespaces : NR_NAMESPACES) *
sizeof(struct perf_ns_link_info));
namespaces = zalloc(sizeof(struct namespaces) + link_info_size);
if (!namespaces)
return NULL;
namespaces->end_time = -1;
if (event)
memcpy(namespaces->link_info, event->link_info, link_info_size);
return namespaces;
}
void namespaces__free(struct namespaces *namespaces)
{
free(namespaces);
}
