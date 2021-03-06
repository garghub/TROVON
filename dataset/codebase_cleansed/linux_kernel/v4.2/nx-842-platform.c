struct nx842_driver *nx842_platform_driver(void)
{
return driver;
}
bool nx842_platform_driver_set(struct nx842_driver *_driver)
{
bool ret = false;
spin_lock(&driver_lock);
if (!driver) {
driver = _driver;
ret = true;
} else
WARN(1, "can't set platform driver, already set to %s\n",
driver->name);
spin_unlock(&driver_lock);
return ret;
}
void nx842_platform_driver_unset(struct nx842_driver *_driver)
{
spin_lock(&driver_lock);
if (driver == _driver)
driver = NULL;
else if (driver)
WARN(1, "can't unset platform driver %s, currently set to %s\n",
_driver->name, driver->name);
else
WARN(1, "can't unset platform driver, already unset\n");
spin_unlock(&driver_lock);
}
bool nx842_platform_driver_get(void)
{
bool ret = false;
spin_lock(&driver_lock);
if (driver)
ret = try_module_get(driver->owner);
spin_unlock(&driver_lock);
return ret;
}
void nx842_platform_driver_put(void)
{
spin_lock(&driver_lock);
if (driver)
module_put(driver->owner);
spin_unlock(&driver_lock);
}
