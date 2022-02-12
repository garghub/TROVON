bool ftrace_event_is_function(struct trace_event_call *call)
{
return call == &event_function;
}
