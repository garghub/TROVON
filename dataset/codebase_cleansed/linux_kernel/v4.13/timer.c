enum ia_css_err
ia_css_timer_get_current_tick(
struct ia_css_clock_tick *curr_ts) {
assert(curr_ts != NULL);
if (curr_ts == NULL) {
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
curr_ts->ticks = (clock_value_t)gp_timer_read(GP_TIMER_SEL);
return IA_CSS_SUCCESS;
}
