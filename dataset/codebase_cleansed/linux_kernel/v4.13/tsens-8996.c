static int get_temp_8996(struct tsens_device *tmdev, int id, int *temp)
{
struct tsens_sensor *s = &tmdev->sensor[id];
u32 code;
unsigned int sensor_addr;
int last_temp = 0, last_temp2 = 0, last_temp3 = 0, ret;
sensor_addr = STATUS_OFFSET + s->hw_id * 4;
ret = regmap_read(tmdev->map, sensor_addr, &code);
if (ret)
return ret;
last_temp = code & LAST_TEMP_MASK;
if (code & STATUS_VALID_BIT)
goto done;
ret = regmap_read(tmdev->map, sensor_addr, &code);
if (ret)
return ret;
if (code & STATUS_VALID_BIT) {
last_temp = code & LAST_TEMP_MASK;
goto done;
} else {
last_temp2 = code & LAST_TEMP_MASK;
}
ret = regmap_read(tmdev->map, sensor_addr, &code);
if (ret)
return ret;
if (code & STATUS_VALID_BIT) {
last_temp = code & LAST_TEMP_MASK;
goto done;
} else {
last_temp3 = code & LAST_TEMP_MASK;
}
if (last_temp == last_temp2)
last_temp = last_temp2;
else if (last_temp2 == last_temp3)
last_temp = last_temp3;
done:
if (last_temp & CODE_SIGN_BIT)
last_temp |= ~CODE_SIGN_BIT;
*temp = last_temp * 100;
return 0;
}
