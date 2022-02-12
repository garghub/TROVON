int ftrace_event_is_function(struct ftrace_event_call *call)
{
return call == &event_function;
}
