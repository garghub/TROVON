struct pwm_device *pwm_request(int pwm_id, const char *label)
{
struct pwm_device *pwm;
int ret;
if (pwm_id < 0)
return NULL;
pwm = kzalloc(sizeof(*pwm), GFP_KERNEL);
if (!pwm)
return pwm;
pwm->id = pwm_id;
if (pwm->id >= ARRAY_SIZE(pwm_to_gptimer_per))
goto err;
pwm->pin = pwm_to_gptimer_per[pwm->id];
ret = peripheral_request(pwm->pin, label);
if (ret)
goto err;
return pwm;
err:
kfree(pwm);
return NULL;
}
void pwm_free(struct pwm_device *pwm)
{
peripheral_free(pwm->pin);
kfree(pwm);
}
int pwm_config(struct pwm_device *pwm, int duty_ns, int period_ns)
{
unsigned long period, duty;
unsigned long long val;
if (duty_ns < 0 || duty_ns > period_ns)
return -EINVAL;
val = (unsigned long long)get_sclk() * period_ns;
do_div(val, NSEC_PER_SEC);
period = val;
val = (unsigned long long)period * duty_ns;
do_div(val, period_ns);
duty = period - val;
if (duty >= period)
duty = period - 1;
set_gptimer_config(pwm->id, TIMER_MODE_PWM | TIMER_PERIOD_CNT);
set_gptimer_pwidth(pwm->id, duty);
set_gptimer_period(pwm->id, period);
return 0;
}
int pwm_enable(struct pwm_device *pwm)
{
enable_gptimer(pwm->id);
return 0;
}
void pwm_disable(struct pwm_device *pwm)
{
disable_gptimer(pwm->id);
}
