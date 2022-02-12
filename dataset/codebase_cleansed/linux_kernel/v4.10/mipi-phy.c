int mipi_dphy_timing_get_default(struct mipi_dphy_timing *timing,
unsigned long period)
{
timing->clkmiss = 0;
timing->clkpost = 70 + 52 * period;
timing->clkpre = 8;
timing->clkprepare = 65;
timing->clksettle = 95;
timing->clktermen = 0;
timing->clktrail = 80;
timing->clkzero = 260;
timing->dtermen = 0;
timing->eot = 0;
timing->hsexit = 120;
timing->hsprepare = 65 + 5 * period;
timing->hszero = 145 + 5 * period;
timing->hssettle = 85 + 6 * period;
timing->hsskip = 40;
timing->hstrail = max(4 * 8 * period, 60 + 4 * 4 * period);
timing->init = 100000;
timing->lpx = 60;
timing->taget = 5 * timing->lpx;
timing->tago = 4 * timing->lpx;
timing->tasure = 2 * timing->lpx;
timing->wakeup = 1000000;
return 0;
}
int mipi_dphy_timing_validate(struct mipi_dphy_timing *timing,
unsigned long period)
{
if (timing->clkmiss > 60)
return -EINVAL;
if (timing->clkpost < (60 + 52 * period))
return -EINVAL;
if (timing->clkpre < 8)
return -EINVAL;
if (timing->clkprepare < 38 || timing->clkprepare > 95)
return -EINVAL;
if (timing->clksettle < 95 || timing->clksettle > 300)
return -EINVAL;
if (timing->clktermen > 38)
return -EINVAL;
if (timing->clktrail < 60)
return -EINVAL;
if (timing->clkprepare + timing->clkzero < 300)
return -EINVAL;
if (timing->dtermen > 35 + 4 * period)
return -EINVAL;
if (timing->eot > 105 + 12 * period)
return -EINVAL;
if (timing->hsexit < 100)
return -EINVAL;
if (timing->hsprepare < 40 + 4 * period ||
timing->hsprepare > 85 + 6 * period)
return -EINVAL;
if (timing->hsprepare + timing->hszero < 145 + 10 * period)
return -EINVAL;
if ((timing->hssettle < 85 + 6 * period) ||
(timing->hssettle > 145 + 10 * period))
return -EINVAL;
if (timing->hsskip < 40 || timing->hsskip > 55 + 4 * period)
return -EINVAL;
if (timing->hstrail < max(8 * period, 60 + 4 * period))
return -EINVAL;
if (timing->init < 100000)
return -EINVAL;
if (timing->lpx < 50)
return -EINVAL;
if (timing->taget != 5 * timing->lpx)
return -EINVAL;
if (timing->tago != 4 * timing->lpx)
return -EINVAL;
if (timing->tasure < timing->lpx || timing->tasure > 2 * timing->lpx)
return -EINVAL;
if (timing->wakeup < 1000000)
return -EINVAL;
return 0;
}
