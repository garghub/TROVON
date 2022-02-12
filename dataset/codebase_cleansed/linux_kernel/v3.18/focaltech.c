int focaltech_detect(struct psmouse *psmouse, bool set_properties)
{
if (!psmouse_matches_pnp_id(psmouse, focaltech_pnp_ids))
return -ENODEV;
if (set_properties) {
psmouse->vendor = "FocalTech";
psmouse->name = "FocalTech Touchpad in mouse emulation mode";
}
return 0;
}
int focaltech_init(struct psmouse *psmouse)
{
ps2_command(&psmouse->ps2dev, NULL, PSMOUSE_CMD_RESET_DIS);
psmouse_reset(psmouse);
return 0;
}
