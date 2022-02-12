int fdtv_register_rc(struct firedtv *fdtv, struct device *dev)
{
struct input_dev *idev;
int i, err;
idev = input_allocate_device();
if (!idev)
return -ENOMEM;
fdtv->remote_ctrl_dev = idev;
idev->name = "FireDTV remote control";
idev->dev.parent = dev;
idev->evbit[0] = BIT_MASK(EV_KEY);
idev->keycode = kmemdup(keytable, sizeof(keytable), GFP_KERNEL);
if (!idev->keycode) {
err = -ENOMEM;
goto fail;
}
idev->keycodesize = sizeof(keytable[0]);
idev->keycodemax = ARRAY_SIZE(keytable);
for (i = 0; i < ARRAY_SIZE(keytable); i++)
set_bit(keytable[i], idev->keybit);
err = input_register_device(idev);
if (err)
goto fail_free_keymap;
return 0;
fail_free_keymap:
kfree(idev->keycode);
fail:
input_free_device(idev);
return err;
}
void fdtv_unregister_rc(struct firedtv *fdtv)
{
cancel_work_sync(&fdtv->remote_ctrl_work);
kfree(fdtv->remote_ctrl_dev->keycode);
input_unregister_device(fdtv->remote_ctrl_dev);
}
void fdtv_handle_rc(struct firedtv *fdtv, unsigned int code)
{
struct input_dev *idev = fdtv->remote_ctrl_dev;
u16 *keycode = idev->keycode;
if (code >= 0x0300 && code <= 0x031f)
code = keycode[code - 0x0300];
else if (code >= 0x0340 && code <= 0x0354)
code = keycode[code - 0x0320];
else if (code >= 0x4501 && code <= 0x451f)
code = oldtable[code - 0x4501];
else if (code >= 0x4540 && code <= 0x4542)
code = oldtable[code - 0x4521];
else {
dev_dbg(fdtv->device,
"invalid key code 0x%04x from remote control\n",
code);
return;
}
input_report_key(idev, code, 1);
input_sync(idev);
input_report_key(idev, code, 0);
input_sync(idev);
}
