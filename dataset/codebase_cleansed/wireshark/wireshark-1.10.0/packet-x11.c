static void atom(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
guint byte_order)
{
const char *interpretation = NULL;
guint32 v = VALUE32(tvb, *offsetp);
if (v >= 1 && v < array_length(atom_predefined_interpretation))
interpretation = atom_predefined_interpretation[v];
else if (v)
interpretation = "Not a predefined atom";
else {
header_field_info *hfi = proto_registrar_get_nth(hf);
if (hfi -> strings)
interpretation = try_val_to_str(v, cVALS(hfi -> strings));
}
if (!interpretation) interpretation = "error in Xlib client program ?";
proto_tree_add_uint_format(t, hf, tvb, *offsetp, 4, v, "%s: %u (%s)",
proto_registrar_get_nth(hf) -> name, v, interpretation);
*offsetp += 4;
}
static guint32 add_boolean(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf)
{
guint32 v = VALUE8(tvb, *offsetp);
proto_tree_add_boolean(t, hf, tvb, *offsetp, 1, v);
*offsetp += 1;
return v;
}
static void colorFlags(tvbuff_t *tvb, int *offsetp, proto_tree *t)
{
guint do_red_green_blue = VALUE8(tvb, *offsetp);
proto_item *ti;
proto_tree *tt;
if (do_red_green_blue) {
int sep = FALSE;
emem_strbuf_t *buffer = ep_strbuf_new_label("flags: ");
if (do_red_green_blue & 0x1) {
ep_strbuf_append(buffer, "DoRed");
sep = TRUE;
}
if (do_red_green_blue & 0x2) {
if (sep) ep_strbuf_append(buffer, " | ");
ep_strbuf_append(buffer, "DoGreen");
sep = TRUE;
}
if (do_red_green_blue & 0x4) {
if (sep) ep_strbuf_append(buffer, " | ");
ep_strbuf_append(buffer, "DoBlue");
sep = TRUE;
}
if (do_red_green_blue & 0xf8) {
if (sep) ep_strbuf_append(buffer, " + trash");
}
ti = proto_tree_add_uint_format(t, hf_x11_coloritem_flags, tvb, *offsetp, 1, do_red_green_blue,
"%s", buffer->str);
tt = proto_item_add_subtree(ti, ett_x11_color_flags);
if (do_red_green_blue & 0x1)
proto_tree_add_boolean(tt, hf_x11_coloritem_flags_do_red, tvb, *offsetp, 1,
do_red_green_blue & 0x1);
if (do_red_green_blue & 0x2)
proto_tree_add_boolean(tt, hf_x11_coloritem_flags_do_green, tvb, *offsetp, 1,
do_red_green_blue & 0x2);
if (do_red_green_blue & 0x4)
proto_tree_add_boolean(tt, hf_x11_coloritem_flags_do_blue, tvb, *offsetp, 1,
do_red_green_blue & 0x4);
if (do_red_green_blue & 0xf8)
proto_tree_add_boolean(tt, hf_x11_coloritem_flags_unused, tvb, *offsetp, 1,
do_red_green_blue & 0xf8);
} else
proto_tree_add_uint_format(t, hf_x11_coloritem_flags, tvb, *offsetp, 1, do_red_green_blue,
"flags: none");
*offsetp += 1;
}
static void gravity(tvbuff_t *tvb, int *offsetp, proto_tree *t,
int hf, const char *nullInterpretation)
{
guint8 v = VALUE8(tvb, *offsetp);
if (!v)
proto_tree_add_uint_format(t, hf, tvb, *offsetp, 1, v, "%s: 0 (%s)",
proto_registrar_get_nth(hf) -> name,
nullInterpretation);
else
proto_tree_add_uint(t, hf, tvb, *offsetp, 1, v);
*offsetp += 1;
}
static void listOfArc(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 8, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_arc);
while(length--) {
gint16 x = VALUE16(tvb, *offsetp);
gint16 y = VALUE16(tvb, *offsetp + 2);
guint16 width = VALUE16(tvb, *offsetp + 4);
guint16 height = VALUE16(tvb, *offsetp + 6);
gint16 angle1 = VALUE16(tvb, *offsetp + 8);
gint16 angle2 = VALUE16(tvb, *offsetp + 10);
proto_item *tti = proto_tree_add_none_format(tt, hf_x11_arc, tvb, *offsetp, 12,
"arc: %dx%d+%d+%d, angle %d -> %d (%f degrees -> %f degrees)",
width, height, x, y, angle1, angle2,
angle1 / 64.0, angle2 / 64.0);
proto_tree *ttt = proto_item_add_subtree(tti, ett_x11_arc);
proto_tree_add_int(ttt, hf_x11_arc_x, tvb, *offsetp, 2, x);
*offsetp += 2;
proto_tree_add_int(ttt, hf_x11_arc_y, tvb, *offsetp, 2, y);
*offsetp += 2;
proto_tree_add_uint(ttt, hf_x11_arc_width, tvb, *offsetp, 2, y);
*offsetp += 2;
proto_tree_add_uint(ttt, hf_x11_arc_height, tvb, *offsetp, 2, y);
*offsetp += 2;
proto_tree_add_int(ttt, hf_x11_arc_angle1, tvb, *offsetp, 2, y);
*offsetp += 2;
proto_tree_add_int(ttt, hf_x11_arc_angle2, tvb, *offsetp, 2, y);
*offsetp += 2;
}
}
static void listOfAtom(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 4, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_atom);
while(length--)
atom(tvb, offsetp, tt, hf_x11_properties_item, byte_order);
}
static void listOfByte(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int length, guint byte_order)
{
if (length <= 0) length = 1;
proto_tree_add_item(t, hf, tvb, *offsetp, length, byte_order);
*offsetp += length;
}
static void listOfCard16(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_item, int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 2, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_card32);
while(length--) {
proto_tree_add_uint(tt, hf_item, tvb, *offsetp, 2, VALUE16(tvb, *offsetp));
*offsetp += 2;
}
}
static void listOfInt16(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_item, int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 2, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_card32);
while(length--) {
proto_tree_add_int(tt, hf_item, tvb, *offsetp, 2, VALUE16(tvb, *offsetp));
*offsetp += 2;
}
}
static void listOfCard32(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_item, int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 4, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_card32);
while(length--) {
proto_tree_add_uint(tt, hf_item, tvb, *offsetp, 4, VALUE32(tvb, *offsetp));
*offsetp += 4;
}
}
static void listOfInt32(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_item, int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 4, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_card32);
while(length--) {
proto_tree_add_int(tt, hf_item, tvb, *offsetp, 4, VALUE32(tvb, *offsetp));
*offsetp += 4;
}
}
static void listOfFloat(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_item, int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 4, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_float);
while(length--) {
proto_tree_add_float(tt, hf_item, tvb, *offsetp, 4, FLOAT(tvb, *offsetp));
*offsetp += 4;
}
}
static void listOfDouble(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_item, int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 8, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_double);
while(length--) {
proto_tree_add_double(tt, hf_item, tvb, *offsetp, 8, DOUBLE(tvb, *offsetp));
*offsetp += 8;
}
}
static void listOfColorItem(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 8, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_color_item);
while(length--) {
proto_item *tti;
proto_tree *ttt;
guint do_red_green_blue;
guint16 red, green, blue;
emem_strbuf_t *buffer;
const char *sep;
buffer=ep_strbuf_new_label("colorItem ");
red = VALUE16(tvb, *offsetp + 4);
green = VALUE16(tvb, *offsetp + 6);
blue = VALUE16(tvb, *offsetp + 8);
do_red_green_blue = VALUE8(tvb, *offsetp + 10);
sep = "";
if (do_red_green_blue & 0x1) {
ep_strbuf_append_printf(buffer, "red = %d", red);
sep = ", ";
}
if (do_red_green_blue & 0x2) {
ep_strbuf_append_printf(buffer, "%sgreen = %d", sep, green);
sep = ", ";
}
if (do_red_green_blue & 0x4)
ep_strbuf_append_printf(buffer, "%sblue = %d", sep, blue);
tti = proto_tree_add_none_format(tt, hf_x11_coloritem, tvb, *offsetp, 12, "%s", buffer->str);
ttt = proto_item_add_subtree(tti, ett_x11_color_item);
proto_tree_add_item(ttt, hf_x11_coloritem_pixel, tvb, *offsetp, 4, byte_order);
*offsetp += 4;
proto_tree_add_item(ttt, hf_x11_coloritem_red, tvb, *offsetp, 2, byte_order);
*offsetp += 2;
proto_tree_add_item(ttt, hf_x11_coloritem_green, tvb, *offsetp, 2, byte_order);
*offsetp += 2;
proto_tree_add_item(ttt, hf_x11_coloritem_blue, tvb, *offsetp, 2, byte_order);
*offsetp += 2;
colorFlags(tvb, offsetp, ttt);
proto_tree_add_item(ttt, hf_x11_coloritem_unused, tvb, *offsetp, 1, byte_order);
*offsetp += 1;
}
}
static void
XConvertCase(register int sym, int *lower, int *upper)
{
*lower = sym;
*upper = sym;
switch(sym >> 8) {
case 0:
if ((sym >= XK_A) && (sym <= XK_Z))
*lower += (XK_a - XK_A);
else if ((sym >= XK_a) && (sym <= XK_z))
*upper -= (XK_a - XK_A);
else if ((sym >= XK_Agrave) && (sym <= XK_Odiaeresis))
*lower += (XK_agrave - XK_Agrave);
else if ((sym >= XK_agrave) && (sym <= XK_odiaeresis))
*upper -= (XK_agrave - XK_Agrave);
else if ((sym >= XK_Ooblique) && (sym <= XK_Thorn))
*lower += (XK_oslash - XK_Ooblique);
else if ((sym >= XK_oslash) && (sym <= XK_thorn))
*upper -= (XK_oslash - XK_Ooblique);
break;
case 1:
if (sym == XK_Aogonek)
*lower = XK_aogonek;
else if (sym >= XK_Lstroke && sym <= XK_Sacute)
*lower += (XK_lstroke - XK_Lstroke);
else if (sym >= XK_Scaron && sym <= XK_Zacute)
*lower += (XK_scaron - XK_Scaron);
else if (sym >= XK_Zcaron && sym <= XK_Zabovedot)
*lower += (XK_zcaron - XK_Zcaron);
else if (sym == XK_aogonek)
*upper = XK_Aogonek;
else if (sym >= XK_lstroke && sym <= XK_sacute)
*upper -= (XK_lstroke - XK_Lstroke);
else if (sym >= XK_scaron && sym <= XK_zacute)
*upper -= (XK_scaron - XK_Scaron);
else if (sym >= XK_zcaron && sym <= XK_zabovedot)
*upper -= (XK_zcaron - XK_Zcaron);
else if (sym >= XK_Racute && sym <= XK_Tcedilla)
*lower += (XK_racute - XK_Racute);
else if (sym >= XK_racute && sym <= XK_tcedilla)
*upper -= (XK_racute - XK_Racute);
break;
case 2:
if (sym >= XK_Hstroke && sym <= XK_Hcircumflex)
*lower += (XK_hstroke - XK_Hstroke);
else if (sym >= XK_Gbreve && sym <= XK_Jcircumflex)
*lower += (XK_gbreve - XK_Gbreve);
else if (sym >= XK_hstroke && sym <= XK_hcircumflex)
*upper -= (XK_hstroke - XK_Hstroke);
else if (sym >= XK_gbreve && sym <= XK_jcircumflex)
*upper -= (XK_gbreve - XK_Gbreve);
else if (sym >= XK_Cabovedot && sym <= XK_Scircumflex)
*lower += (XK_cabovedot - XK_Cabovedot);
else if (sym >= XK_cabovedot && sym <= XK_scircumflex)
*upper -= (XK_cabovedot - XK_Cabovedot);
break;
case 3:
if (sym >= XK_Rcedilla && sym <= XK_Tslash)
*lower += (XK_rcedilla - XK_Rcedilla);
else if (sym >= XK_rcedilla && sym <= XK_tslash)
*upper -= (XK_rcedilla - XK_Rcedilla);
else if (sym == XK_ENG)
*lower = XK_eng;
else if (sym == XK_eng)
*upper = XK_ENG;
else if (sym >= XK_Amacron && sym <= XK_Umacron)
*lower += (XK_amacron - XK_Amacron);
else if (sym >= XK_amacron && sym <= XK_umacron)
*upper -= (XK_amacron - XK_Amacron);
break;
case 6:
if (sym >= XK_Serbian_DJE && sym <= XK_Serbian_DZE)
*lower -= (XK_Serbian_DJE - XK_Serbian_dje);
else if (sym >= XK_Serbian_dje && sym <= XK_Serbian_dze)
*upper += (XK_Serbian_DJE - XK_Serbian_dje);
else if (sym >= XK_Cyrillic_YU && sym <= XK_Cyrillic_HARDSIGN)
*lower -= (XK_Cyrillic_YU - XK_Cyrillic_yu);
else if (sym >= XK_Cyrillic_yu && sym <= XK_Cyrillic_hardsign)
*upper += (XK_Cyrillic_YU - XK_Cyrillic_yu);
break;
case 7:
if (sym >= XK_Greek_ALPHAaccent && sym <= XK_Greek_OMEGAaccent)
*lower += (XK_Greek_alphaaccent - XK_Greek_ALPHAaccent);
else if (sym >= XK_Greek_alphaaccent && sym <= XK_Greek_omegaaccent &&
sym != XK_Greek_iotaaccentdieresis &&
sym != XK_Greek_upsilonaccentdieresis)
*upper -= (XK_Greek_alphaaccent - XK_Greek_ALPHAaccent);
else if (sym >= XK_Greek_ALPHA && sym <= XK_Greek_OMEGA)
*lower += (XK_Greek_alpha - XK_Greek_ALPHA);
else if (sym >= XK_Greek_alpha && sym <= XK_Greek_omega &&
sym != XK_Greek_finalsmallsigma)
*upper -= (XK_Greek_alpha - XK_Greek_ALPHA);
break;
}
}
static const char *
keycode2keysymString(int *keycodemap[256], int first_keycode,
int keysyms_per_keycode,
int *modifiermap[array_length(modifiers)],
int keycodes_per_modifier,
guint32 keycode, guint32 bitmask)
{
int *syms;
int groupmodkc, numlockkc, numlockmod, groupmod;
int lockmod_is_capslock = 0, lockmod_is_shiftlock = 0;
int lockmod_is_nosymbol = 1;
int modifier, kc, keysym;
if ((syms = keycodemap[keycode]) == NULL)
return "<Unknown>";
for (kc = first_keycode, groupmodkc = numlockkc = -1; kc < 256; ++kc)
for (keysym = 0; keysym < keysyms_per_keycode; ++keysym) {
if (keycodemap[kc] == NULL)
return "<Unknown>";
switch (keycodemap[kc][keysym]) {
case 0xff7e:
groupmodkc = kc;
break;
case 0xff7f:
numlockkc = kc;
break;
case 0xffe5:
lockmod_is_capslock = kc;
break;
case 0xffe6:
lockmod_is_shiftlock = kc;
break;
}
}
if (modifiermap[array_length(modifiers) - 1] == NULL)
return "<Unknown>";
for (modifier = 0, numlockmod = groupmod = -1;
modifier < (int)array_length(modifiers) && numlockmod == -1;
++modifier)
for (kc = 0; kc < keycodes_per_modifier; ++kc)
if (modifiermap[modifier][kc] == numlockkc)
numlockmod = modifier;
else if (modifiermap[modifier][kc] == groupmodkc)
groupmod = modifier;
for (kc = 0; kc < keycodes_per_modifier; ++kc)
if (modifiermap[1][kc] == lockmod_is_capslock) {
lockmod_is_shiftlock = lockmod_is_nosymbol = 0;
break;
}
else if (modifiermap[0][kc] == lockmod_is_shiftlock) {
lockmod_is_capslock = lockmod_is_nosymbol = 0;
break;
}
#if 0
if (numlockmod >= 0 && (bitmask & modifiermask[numlockmod])
&& ((syms[1] >= 0xff80
&& syms[1] <= 0xffbd)
|| (syms[1] >= 0x11000000
&& syms[1] <= 0x1100ffff))) {
if ((bitmask & ShiftMask) || lockmod_is_shiftlock)
return keysymString(syms[groupmod + 0]);
else
if (syms[groupmod + 1] == NoSymbol)
return keysymString(syms[groupmod + 0]);
else
return keysymString(syms[groupmod + 1]);
}
else if (!(bitmask & ShiftMask) && !(bitmask & LockMask))
return keysymString(syms[groupmod + 0]);
else if (!(bitmask & ShiftMask)
&& ((bitmask & LockMask) && lockmod_is_capslock))
if (islower(syms[groupmod + 0]))
return "Uppercase";
else
return keysymString(syms[groupmod + 0]);
else if ((bitmask & ShiftMask)
&& ((bitmask & LockMask) && lockmod_is_capslock))
if (islower(syms[groupmod + 1]))
return "Uppercase";
else
return keysymString(syms[groupmod + 1]);
else if ((bitmask & ShiftMask)
|| ((bitmask & LockMask) && lockmod_is_shiftlock))
return keysymString(syms[groupmod + 1]);
#else
while (keysyms_per_keycode > 2
&& keycodemap[keysyms_per_keycode - 1] == NoSymbol)
--keysyms_per_keycode;
if (keysyms_per_keycode > 2
&& (groupmod >= 0 && (modifiermask[groupmod] & bitmask))) {
syms += 2;
keysyms_per_keycode -= 2;
}
if (numlockmod >= 0 && (bitmask & modifiermask[numlockmod])
&& keysyms_per_keycode > 1
&& ((syms[1] >= 0xff80 && syms[1] <= 0xffbd)
|| (syms[1] >= 0x11000000 && syms[1] <= 0x1100ffff))) {
if ((bitmask & ShiftMask)
|| (bitmask & LockMask && lockmod_is_shiftlock))
keysym = syms[0];
else
keysym = syms[1];
}
else if (!(bitmask & ShiftMask)
&& (!(bitmask & LockMask) || lockmod_is_nosymbol)) {
if (keysyms_per_keycode == 1
|| (keysyms_per_keycode > 1 && syms[1] == NoSymbol)) {
int usym;
XConvertCase(syms[0], &keysym, &usym);
}
else
keysym = syms[0];
}
else if (!(bitmask & LockMask) || !lockmod_is_capslock) {
int lsym, usym = 0;
if (keysyms_per_keycode == 1
|| (keysyms_per_keycode > 1 && (usym = syms[1]) == NoSymbol))
XConvertCase(syms[0], &lsym, &usym);
keysym = usym;
}
else {
int lsym, usym = 0;
if (keysyms_per_keycode == 1
|| (keysyms_per_keycode > 1 && syms[1] == NoSymbol))
keysym = syms[0];
XConvertCase(keysym, &lsym, &usym);
if (!(bitmask & ShiftMask) && keysym != syms[0]
&& ((keysym != usym) || (lsym == usym)))
XConvertCase(syms[0], &lsym, &usym);
keysym = usym;
}
if (keysym == XK_VoidSymbol)
keysym = NoSymbol;
return ep_strdup_printf("%d, \"%s\"", keysym, keysymString(keysym));
#endif
}
static const char *keysymString(guint32 v)
{
#if 0
static GTree *keysymTable = NULL;
gpointer res;
if (!keysymTable) {
const value_string *p = x11_keysym_vals_source;
keysymTable = g_tree_new(compareGuint32);
for(; p -> strptr; p++)
g_tree_insert(keysymTable, GINT_TO_POINTER(p -> value), (gpointer) (p -> strptr) );
}
res = g_tree_lookup(keysymTable, GINT_TO_POINTER(v));
return res ? res : "<Unknown>";
#endif
return val_to_str_ext_const(v, &x11_keysym_vals_source_ext, "<Unknown>");
}
static void listOfKeycode(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int *modifiermap[], int keycodes_per_modifier,
guint byte_order _U_)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp,
(int)array_length(modifiers) * keycodes_per_modifier, ENC_NA);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_keycode);
size_t m;
for (m = 0; m < array_length(modifiers);
++m, *offsetp += keycodes_per_modifier) {
const guint8 *p;
proto_item *tikc;
int i;
p = tvb_get_ptr(tvb, *offsetp, keycodes_per_modifier);
modifiermap[m] = (int *)
g_malloc(sizeof(*modifiermap[m]) * keycodes_per_modifier);
tikc = proto_tree_add_bytes_format(tt, hf_x11_keycodes_item, tvb,
*offsetp, keycodes_per_modifier, p, "item: ");
for(i = 0; i < keycodes_per_modifier; ++i) {
guchar c = p[i];
if (c)
proto_item_append_text(tikc, " %s=%d", modifiers[m], c);
modifiermap[m][i] = c;
}
}
}
static void listOfKeysyms(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_item, int *keycodemap[256],
int keycode_first, int keycode_count,
int keysyms_per_keycode, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, keycode_count * keysyms_per_keycode * 4, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_keysyms);
proto_item *tti;
proto_tree *ttt;
int i, keycode;
DISSECTOR_ASSERT(keycode_first >= 0);
DISSECTOR_ASSERT(keycode_count >= 0);
for (keycode = keycode_first; keycode_count > 0;
++keycode, --keycode_count) {
if (keycode >= 256) {
proto_tree_add_text(tt, tvb, *offsetp, 4 * keysyms_per_keycode,
"keycode value %d is out of range", keycode);
*offsetp += 4 * keysyms_per_keycode;
continue;
}
tti = proto_tree_add_none_format(tt, hf_item, tvb, *offsetp,
4 * keysyms_per_keycode, "keysyms (keycode %d):", keycode);
ttt = proto_item_add_subtree(tti, ett_x11_keysym);
tvb_ensure_bytes_exist(tvb, *offsetp, 4 * keysyms_per_keycode);
keycodemap[keycode]
= (int *)g_malloc(sizeof(*keycodemap[keycode]) * keysyms_per_keycode);
for(i = 0; i < keysyms_per_keycode; ++i) {
guint32 v = VALUE32(tvb, *offsetp);
proto_item_append_text(tti, " %s", keysymString(v));
proto_tree_add_uint_format(ttt, hf_x11_keysyms_item_keysym,
tvb, *offsetp, 4, v,
"keysym (keycode %d): 0x%08x (%s)",
keycode, v, keysymString(v));
keycodemap[keycode][i] = v;
*offsetp += 4;
}
for (i = 1; i < keysyms_per_keycode; ++i)
if (keycodemap[keycode][i] != NoSymbol)
break;
if (i == keysyms_per_keycode) {
if (keysyms_per_keycode == 4) {
keycodemap[keycode][1] = NoSymbol;
keycodemap[keycode][2] = keycodemap[keycode][0];
keycodemap[keycode][3] = NoSymbol;
}
continue;
}
for (i = 2; i < keysyms_per_keycode; ++i)
if (keycodemap[keycode][i] != NoSymbol)
break;
if (i == keysyms_per_keycode) {
if (keysyms_per_keycode == 4) {
keycodemap[keycode][2] = keycodemap[keycode][0];
keycodemap[keycode][3] = keycodemap[keycode][1];
}
continue;
}
}
}
static void listOfPoint(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 4, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_point);
while(length--) {
gint16 x, y;
proto_item *tti;
proto_tree *ttt;
x = VALUE16(tvb, *offsetp);
y = VALUE16(tvb, *offsetp + 2);
tti = proto_tree_add_none_format(tt, hf_x11_point, tvb, *offsetp, 4, "point: (%d,%d)", x, y);
ttt = proto_item_add_subtree(tti, ett_x11_point);
proto_tree_add_int(ttt, hf_x11_point_x, tvb, *offsetp, 2, x);
*offsetp += 2;
proto_tree_add_int(ttt, hf_x11_point_y, tvb, *offsetp, 2, y);
*offsetp += 2;
}
}
static void listOfRectangle(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 8, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_rectangle);
while(length--) {
gint16 x, y;
guint width, height;
proto_item *tti;
proto_tree *ttt;
x = VALUE16(tvb, *offsetp);
y = VALUE16(tvb, *offsetp + 2);
width = VALUE16(tvb, *offsetp + 4);
height = VALUE16(tvb, *offsetp + 6);
tti = proto_tree_add_none_format(tt, hf_x11_rectangle, tvb, *offsetp, 8,
"rectangle: %dx%d+%d+%d", width, height, x, y);
ttt = proto_item_add_subtree(tti, ett_x11_rectangle);
proto_tree_add_int(ttt, hf_x11_rectangle_x, tvb, *offsetp, 2, x);
*offsetp += 2;
proto_tree_add_int(ttt, hf_x11_rectangle_y, tvb, *offsetp, 2, y);
*offsetp += 2;
proto_tree_add_uint(ttt, hf_x11_rectangle_width, tvb, *offsetp, 2, width);
*offsetp += 2;
proto_tree_add_uint(ttt, hf_x11_rectangle_height, tvb, *offsetp, 2, height);
*offsetp += 2;
}
}
static void listOfSegment(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int length, guint byte_order)
{
proto_item *ti = proto_tree_add_item(t, hf, tvb, *offsetp, length * 8, byte_order);
proto_tree *tt = proto_item_add_subtree(ti, ett_x11_list_of_segment);
while(length--) {
gint16 x1, y1, x2, y2;
proto_item *tti;
proto_tree *ttt;
x1 = VALUE16(tvb, *offsetp);
y1 = VALUE16(tvb, *offsetp + 2);
x2 = VALUE16(tvb, *offsetp + 4);
y2 = VALUE16(tvb, *offsetp + 6);
tti = proto_tree_add_none_format(tt, hf_x11_segment, tvb, *offsetp, 8,
"segment: (%d,%d)-(%d,%d)", x1, y1, x2, y2);
ttt = proto_item_add_subtree(tti, ett_x11_segment);
proto_tree_add_item(ttt, hf_x11_segment_x1, tvb, *offsetp, 2, byte_order);
*offsetp += 2;
proto_tree_add_item(ttt, hf_x11_segment_y1, tvb, *offsetp, 2, byte_order);
*offsetp += 2;
proto_tree_add_item(ttt, hf_x11_segment_x2, tvb, *offsetp, 2, byte_order);
*offsetp += 2;
proto_tree_add_item(ttt, hf_x11_segment_y2, tvb, *offsetp, 2, byte_order);
*offsetp += 2;
}
}
static void listOfString8(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_item, int length, guint byte_order)
{
char *s = NULL;
proto_item *ti;
proto_tree *tt;
int i;
int scanning_offset = *offsetp;
for(i = length; i; i--) {
int l;
l = tvb_get_guint8(tvb, scanning_offset);
scanning_offset += 1 + l;
}
ti = proto_tree_add_item(t, hf, tvb, *offsetp, scanning_offset - *offsetp, byte_order);
tt = proto_item_add_subtree(ti, ett_x11_list_of_string8);
while(length--) {
guint l = VALUE8(tvb, *offsetp);
s = tvb_get_ephemeral_string(tvb, *offsetp + 1, l);
proto_tree_add_string_format(tt, hf_item, tvb, *offsetp, l + 1, s, "\"%s\"", s);
*offsetp += l + 1;
}
}
static int stringIsActuallyAn8BitString(tvbuff_t *tvb, int offset, guint length)
{
if (length > STRING16_MAX_DISPLAYED_LENGTH) length = STRING16_MAX_DISPLAYED_LENGTH;
for(; length > 0; offset += 2, length--) {
if (tvb_get_guint8(tvb, offset))
return FALSE;
}
return TRUE;
}
static void string16_with_buffer_preallocated(tvbuff_t *tvb, proto_tree *t,
int hf, int hf_bytes,
int offset, guint length,
char **s, guint byte_order)
{
int truncated = FALSE;
guint l = length / 2;
if (stringIsActuallyAn8BitString(tvb, offset, l)) {
char *dp;
int soffset = offset;
if (l > STRING16_MAX_DISPLAYED_LENGTH) {
truncated = TRUE;
l = STRING16_MAX_DISPLAYED_LENGTH;
}
*s = (char *)ep_alloc(l + 3);
dp = *s;
*dp++ = '"';
if (truncated) l -= 3;
while(l--) {
soffset++;
*dp++ = tvb_get_guint8(tvb, soffset);
soffset++;
}
*dp++ = '"';
if (truncated) { *dp++ = '.'; *dp++ = '.'; *dp++ = '.'; }
*dp++ = '\0';
proto_tree_add_string_format(t, hf, tvb, offset, length, (gchar *)tvb_get_ptr(tvb, offset, length), "%s: %s",
proto_registrar_get_nth(hf) -> name, *s);
} else
proto_tree_add_item(t, hf_bytes, tvb, offset, length, byte_order);
}
static void listOfTextItem(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int sizeIs16, int next_offset, guint byte_order)
{
char *s = NULL;
proto_item *ti;
proto_tree *tt;
guint32 fid;
int scanning_offset = *offsetp;
int n = 0;
while(scanning_offset < next_offset) {
int l;
l = tvb_get_guint8(tvb, scanning_offset);
scanning_offset++;
if (!l) break;
n++;
scanning_offset += l == 255 ? 4 : l + (sizeIs16 ? l : 0) + 1;
}
ti = proto_tree_add_item(t, hf, tvb, *offsetp, scanning_offset - *offsetp, byte_order);
tt = proto_item_add_subtree(ti, ett_x11_list_of_text_item);
while(n--) {
guint l = VALUE8(tvb, *offsetp);
if (l == 255) {
fid = tvb_get_ntohl(tvb, *offsetp + 1);
proto_tree_add_uint(tt, hf_x11_textitem_font, tvb, *offsetp, 5, fid);
*offsetp += 5;
} else {
proto_item *tti;
proto_tree *ttt;
gint8 delta = VALUE8(tvb, *offsetp + 1);
if (sizeIs16) l += l;
s = tvb_get_ephemeral_string(tvb, *offsetp + 2, l);
tti = proto_tree_add_none_format(tt, hf_x11_textitem_string, tvb, *offsetp, l + 2,
"textitem (string): delta = %d, \"%s\"",
delta, s);
ttt = proto_item_add_subtree(tti, ett_x11_text_item);
proto_tree_add_item(ttt, hf_x11_textitem_string_delta, tvb, *offsetp + 1, 1, byte_order);
if (sizeIs16)
string16_with_buffer_preallocated(tvb, ttt, hf_x11_textitem_string_string16,
hf_x11_textitem_string_string16_bytes,
*offsetp + 2, l,
&s, byte_order);
else
proto_tree_add_string_format(ttt, hf_x11_textitem_string_string8, tvb,
*offsetp + 2, l, s, "\"%s\"", s);
*offsetp += l + 2;
}
}
}
static guint32 field8(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
guint byte_order)
{
guint32 v = VALUE8(tvb, *offsetp);
header_field_info *hfi = proto_registrar_get_nth(hf);
const gchar *enumValue = NULL;
if (hfi -> strings)
enumValue = try_val_to_str(v, cVALS(hfi -> strings));
if (enumValue)
proto_tree_add_uint_format(t, hf, tvb, *offsetp, 1, v,
hfi -> display == BASE_DEC ? "%s: %u (%s)" : "%s: 0x%02x (%s)",
hfi -> name, v, enumValue);
else
proto_tree_add_item(t, hf, tvb, *offsetp, 1, byte_order);
*offsetp += 1;
return v;
}
static guint32 field16(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
guint byte_order)
{
guint32 v = VALUE16(tvb, *offsetp);
header_field_info *hfi = proto_registrar_get_nth(hf);
const gchar *enumValue = NULL;
if (hfi -> strings)
enumValue = try_val_to_str(v, cVALS(hfi -> strings));
if (enumValue)
proto_tree_add_uint_format(t, hf, tvb, *offsetp, 2, v,
hfi -> display == BASE_DEC ? "%s: %u (%s)" : "%s: 0x%02x (%s)",
hfi -> name, v, enumValue);
else
proto_tree_add_item(t, hf, tvb, *offsetp, 2, byte_order);
*offsetp += 2;
return v;
}
static guint32 field32(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
guint byte_order)
{
guint32 v = VALUE32(tvb, *offsetp);
header_field_info *hfi = proto_registrar_get_nth(hf);
const gchar *enumValue = NULL;
const gchar *nameAsChar = hfi -> name;
if (hfi -> strings)
enumValue = try_val_to_str(v, cVALS(hfi -> strings));
if (enumValue)
proto_tree_add_uint_format(t, hf, tvb, *offsetp, 4, v,
hfi -> display == BASE_DEC ? "%s: %u (%s)" : "%s: 0x%08x (%s)",
nameAsChar, v, enumValue);
else
proto_tree_add_uint_format(t, hf, tvb, *offsetp, 4, v,
hfi -> display == BASE_DEC ? "%s: %u" : "%s: 0x%08x",
nameAsChar, v);
*offsetp += 4;
return v;
}
static void gcAttributes(tvbuff_t *tvb, int *offsetp, proto_tree *t,
guint byte_order)
{
BITMASK32(gc_value);
BITFIELD(ENUM8, gc_value_mask, function);
BITFIELD(CARD32, gc_value_mask, plane_mask);
BITFIELD(CARD32, gc_value_mask, foreground);
BITFIELD(CARD32, gc_value_mask, background);
BITFIELD(CARD16, gc_value_mask, line_width);
BITFIELD(ENUM8, gc_value_mask, line_style);
BITFIELD(ENUM8, gc_value_mask, cap_style);
BITFIELD(ENUM8, gc_value_mask, join_style);
BITFIELD(ENUM8, gc_value_mask, fill_style);
BITFIELD(ENUM8, gc_value_mask, fill_rule);
BITFIELD(PIXMAP, gc_value_mask, tile);
BITFIELD(PIXMAP, gc_value_mask, stipple);
BITFIELD(INT16, gc_value_mask, tile_stipple_x_origin);
BITFIELD(INT16, gc_value_mask, tile_stipple_y_origin);
BITFIELD(FONT, gc_value_mask, font);
BITFIELD(ENUM8, gc_value_mask, subwindow_mode);
BITFIELD(BOOL, gc_value_mask, graphics_exposures);
BITFIELD(INT16, gc_value_mask, clip_x_origin);
BITFIELD(INT16, gc_value_mask, clip_y_origin);
BITFIELD(PIXMAP, gc_value_mask, clip_mask);
BITFIELD(CARD16, gc_value_mask, dash_offset);
BITFIELD(CARD8, gc_value_mask, gc_dashes);
BITFIELD(ENUM8, gc_value_mask, arc_mode);
ENDBITMASK;
}
static void gcMask(tvbuff_t *tvb, int *offsetp, proto_tree *t,
guint byte_order)
{
BITMASK32(gc_value);
FLAG(gc_value, function);
FLAG(gc_value, plane_mask);
FLAG(gc_value, foreground);
FLAG(gc_value, background);
FLAG(gc_value, line_width);
FLAG(gc_value, line_style);
FLAG(gc_value, cap_style);
FLAG(gc_value, join_style);
FLAG(gc_value, fill_style);
FLAG(gc_value, fill_rule);
FLAG(gc_value, tile);
FLAG(gc_value, stipple);
FLAG(gc_value, tile_stipple_x_origin);
FLAG(gc_value, tile_stipple_y_origin);
FLAG(gc_value, font);
FLAG(gc_value, subwindow_mode);
FLAG(gc_value, graphics_exposures);
FLAG(gc_value, clip_x_origin);
FLAG(gc_value, clip_y_origin);
FLAG(gc_value, clip_mask);
FLAG(gc_value, dash_offset);
FLAG(gc_value, gc_dashes);
FLAG(gc_value, arc_mode);
ENDBITMASK;
}
static guint32 requestLength(tvbuff_t *tvb, int *offsetp, proto_tree *t,
guint byte_order)
{
guint32 res = VALUE16(tvb, *offsetp);
proto_tree_add_uint(t, hf_x11_request_length, tvb, *offsetp, 2, res);
*offsetp += 2;
return res * 4;
}
static void setOfEvent(tvbuff_t *tvb, int *offsetp, proto_tree *t,
guint byte_order)
{
BITMASK32(event);
FLAG(event, KeyPress);
FLAG(event, KeyRelease);
FLAG(event, ButtonPress);
FLAG(event, ButtonRelease);
FLAG(event, EnterWindow);
FLAG(event, LeaveWindow);
FLAG(event, PointerMotion);
FLAG(event, PointerMotionHint);
FLAG(event, Button1Motion);
FLAG(event, Button2Motion);
FLAG(event, Button3Motion);
FLAG(event, Button4Motion);
FLAG(event, Button5Motion);
FLAG(event, ButtonMotion);
FLAG(event, KeymapState);
FLAG(event, Exposure);
FLAG(event, VisibilityChange);
FLAG(event, StructureNotify);
FLAG(event, ResizeRedirect);
FLAG(event, SubstructureNotify);
FLAG(event, SubstructureRedirect);
FLAG(event, FocusChange);
FLAG(event, PropertyChange);
FLAG(event, ColormapChange);
FLAG(event, OwnerGrabButton);
FLAG_IF_NONZERO(event, erroneous_bits);
ENDBITMASK;
}
static void setOfDeviceEvent(tvbuff_t *tvb, int *offsetp, proto_tree *t,
guint byte_order)
{
BITMASK32(do_not_propagate);
FLAG(do_not_propagate, KeyPress);
FLAG(do_not_propagate, KeyRelease);
FLAG(do_not_propagate, ButtonPress);
FLAG(do_not_propagate, ButtonRelease);
FLAG(do_not_propagate, PointerMotion);
FLAG(do_not_propagate, Button1Motion);
FLAG(do_not_propagate, Button2Motion);
FLAG(do_not_propagate, Button3Motion);
FLAG(do_not_propagate, Button4Motion);
FLAG(do_not_propagate, Button5Motion);
FLAG(do_not_propagate, ButtonMotion);
FLAG_IF_NONZERO(do_not_propagate, erroneous_bits);
ENDBITMASK;
}
static void setOfKeyButMask(tvbuff_t *tvb, int *offsetp, proto_tree *t,
guint byte_order, gboolean butmask)
{
proto_item *ti;
guint32 bitmask_value;
int bitmask_offset;
int bitmask_size;
proto_tree *bitmask_tree;
bitmask_value = VALUE16(tvb, *offsetp);
bitmask_offset = *offsetp;
bitmask_size = 2;
if (!butmask && bitmask_value == 0x8000)
proto_tree_add_uint_format(t, hf_x11_modifiers_mask_AnyModifier, tvb, *offsetp, 2, 0x8000,
"modifiers-masks: 0x8000 (AnyModifier)");
else {
ti = proto_tree_add_uint(t, hf_x11_modifiers_mask, tvb, *offsetp, 2,
bitmask_value);
bitmask_tree = proto_item_add_subtree(ti, ett_x11_set_of_key_mask);
FLAG(modifiers, Shift);
FLAG(modifiers, Lock);
FLAG(modifiers, Control);
FLAG(modifiers, Mod1);
FLAG(modifiers, Mod2);
FLAG(modifiers, Mod3);
FLAG(modifiers, Mod4);
FLAG(modifiers, Mod5);
if (butmask) {
FLAG(modifiers, Button1);
FLAG(modifiers, Button2);
FLAG(modifiers, Button3);
FLAG(modifiers, Button4);
FLAG(modifiers, Button5);
}
if (butmask)
FLAG_IF_NONZERO(keybut, erroneous_bits);
else
FLAG_IF_NONZERO(modifiers, erroneous_bits);
}
*offsetp += 2;
}
static void setOfPointerEvent(tvbuff_t *tvb, int *offsetp, proto_tree *t,
guint byte_order)
{
BITMASK16(pointer_event);
FLAG(pointer_event, ButtonPress);
FLAG(pointer_event, ButtonRelease);
FLAG(pointer_event, EnterWindow);
FLAG(pointer_event, LeaveWindow);
FLAG(pointer_event, PointerMotion);
FLAG(pointer_event, PointerMotionHint);
FLAG(pointer_event, Button1Motion);
FLAG(pointer_event, Button2Motion);
FLAG(pointer_event, Button3Motion);
FLAG(pointer_event, Button4Motion);
FLAG(pointer_event, Button5Motion);
FLAG(pointer_event, ButtonMotion);
FLAG(pointer_event, KeymapState);
FLAG_IF_NONZERO(pointer_event, erroneous_bits);
ENDBITMASK;
}
static void string8(tvbuff_t *tvb, int *offsetp, proto_tree *t,
int hf, guint length)
{
proto_tree_add_item(t, hf, tvb, *offsetp, length, ENC_NA|ENC_ASCII);
*offsetp += length;
}
static void string16(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
int hf_bytes, guint length, guint byte_order)
{
char *s = NULL;
length += length;
string16_with_buffer_preallocated(tvb, t, hf, hf_bytes, *offsetp, length,
&s, byte_order);
*offsetp += length;
}
static void timestamp(tvbuff_t *tvb, int *offsetp, proto_tree *t, int hf,
guint byte_order)
{
guint32 v = VALUE32(tvb, *offsetp);
if (!v)
proto_tree_add_uint_format(t, hf, tvb, *offsetp, 4, 0, "%s: 0 (CurrentTime)",
proto_registrar_get_nth(hf) -> name);
else
proto_tree_add_uint(t, hf, tvb, *offsetp, 4, v);
*offsetp += 4;
}
static void windowAttributes(tvbuff_t *tvb, int *offsetp, proto_tree *t,
guint byte_order)
{
BITMASK32(window_value);
BITFIELD(PIXMAP, window_value_mask, background_pixmap);
BITFIELD(CARD32, window_value_mask, background_pixel);
BITFIELD(PIXMAP, window_value_mask, border_pixmap);
BITFIELD(CARD32, window_value_mask, border_pixel);
BITFIELD(BITGRAVITY, window_value_mask, bit_gravity);
BITFIELD(WINGRAVITY, window_value_mask, win_gravity);
BITFIELD(ENUM8, window_value_mask, backing_store);
BITFIELD(CARD32, window_value_mask, backing_planes);
BITFIELD(CARD32, window_value_mask, backing_pixel);
BITFIELD(BOOL, window_value_mask, override_redirect);
BITFIELD(BOOL, window_value_mask, save_under);
BITFIELD(SETofEVENT, window_value_mask, event_mask);
BITFIELD(SETofDEVICEEVENT, window_value_mask, do_not_propagate_mask);
BITFIELD(COLORMAP, window_value_mask, colormap);
BITFIELD(CURSOR, window_value_mask, cursor);
ENDBITMASK;
}
static void x11_init_protocol(void)
{
x11_conv_data_t *state;
for (state = x11_conv_data_list; state != NULL; ) {
x11_conv_data_t *last;
g_hash_table_destroy(state->seqtable);
g_hash_table_destroy(state->valtable);
last = state;
state = state->next;
g_free(last);
}
x11_conv_data_list = NULL;
}
static int numberOfBitSet(tvbuff_t *tvb, int offset, int maskLength)
{
int res = 0;
while(maskLength--) {
int c = tvb_get_guint8(tvb, offset);
offset++;
res += numberOfBitSetTable[c & 0xf] + numberOfBitSetTable[c >> 4];
}
return res;
}
static int listOfStringLengthConsistent(tvbuff_t *tvb, int offset, int length, int listLength)
{
if (listLength > length) return FALSE;
while(listLength--) {
int l;
if (!tvb_bytes_exist(tvb, offset, 1)) return TRUE;
l = tvb_get_guint8(tvb, offset);
if (!l) break;
l++;
if (l > length) return FALSE;
if (!tvb_bytes_exist(tvb, offset, l)) return TRUE;
offset += l;
length -= l;
}
if (length > 3) return FALSE;
return TRUE;
}
static int rounded4(int n)
{
int remainder = n % 4;
int res = n / 4;
if (remainder) res++;
return res;
}
static gboolean consistentWithOrder(int length, tvbuff_t *tvb, int offset, guint16 (*v16)(tvbuff_t *, const gint))
{
switch(tvb_get_guint8(tvb, offset)) {
case X_CreateWindow:
return !tvb_bytes_exist(tvb, offset, 32) || length == 8 + numberOfBitSet(tvb, offset + 7 * 4, 4);
case X_ChangeWindowAttributes:
case X_ChangeGC:
return !tvb_bytes_exist(tvb, offset, 12) || length == 3 + numberOfBitSet(tvb, offset + 8, 4);
case X_GetWindowAttributes:
case X_DestroyWindow:
case X_DestroySubwindows:
case X_ChangeSaveSet:
case X_MapWindow:
case X_MapSubwindows:
case X_UnmapWindow:
case X_UnmapSubwindows:
case X_CirculateWindow:
case X_GetGeometry:
case X_QueryTree:
case X_GetAtomName:
case X_ListProperties:
case X_GetSelectionOwner:
case X_UngrabPointer:
case X_UngrabKeyboard:
case X_AllowEvents:
case X_QueryPointer:
case X_CloseFont:
case X_QueryFont:
case X_FreePixmap:
case X_FreeGC:
case X_FreeColormap:
case X_InstallColormap:
case X_UninstallColormap:
case X_ListInstalledColormaps:
case X_FreeCursor:
case X_GetKeyboardMapping:
case X_KillClient:
return length == 2;
case X_ReparentWindow:
case X_SetSelectionOwner:
case X_ChangeActivePointerGrab:
case X_GrabKeyboard:
case X_GrabKey:
case X_GetMotionEvents:
case X_TranslateCoords:
case X_CreatePixmap:
case X_CopyGC:
case X_ClearArea:
case X_CreateColormap:
case X_AllocColor:
case X_AllocColorPlanes:
return length == 4;
case X_ConfigureWindow:
return !tvb_bytes_exist(tvb, offset, 10) || length == 3 + numberOfBitSet(tvb, offset + 8, 2);
case X_InternAtom:
case X_QueryExtension:
return !tvb_bytes_exist(tvb, offset, 6) || length == 2 + rounded4(v16(tvb, offset + 4));
case X_ChangeProperty:
{
int multiplier, type;
if (!tvb_bytes_exist(tvb, offset, 17)) return TRUE;
type = tvb_get_guint8(tvb, 16);
if (type != 8 && type != 16 && type != 32) return FALSE;
multiplier = type == 8 ? 1 : type == 16 ? 2 : 4;
if (!tvb_bytes_exist(tvb, offset, 24)) return TRUE;
return length == 6 + rounded4((v16 == tvb_get_letohs ? tvb_get_letohl : tvb_get_ntohl)(tvb, offset + 20) * multiplier);
}
case X_DeleteProperty:
case X_UngrabButton:
case X_UngrabKey:
case X_SetInputFocus:
case X_CopyColormapAndFree:
case X_AllocColorCells:
case X_QueryBestSize:
case X_ChangePointerControl:
case X_SetScreenSaver:
return length == 3;
case X_GetProperty:
case X_ConvertSelection:
case X_GrabPointer:
case X_GrabButton:
case X_WarpPointer:
return length == 6;
case X_SendEvent:
return length == 11;
case X_GrabServer:
case X_UngrabServer:
case X_GetInputFocus:
case X_QueryKeymap:
case X_GetFontPath:
case X_ListExtensions:
case X_GetKeyboardControl:
case X_Bell:
case X_GetPointerControl:
case X_GetScreenSaver:
case X_ListHosts:
case X_SetAccessControl:
case X_SetCloseDownMode:
case X_ForceScreenSaver:
case X_GetPointerMapping:
case X_GetModifierMapping:
return length == 1;
case X_OpenFont:
case X_AllocNamedColor:
case X_LookupColor:
return !tvb_bytes_exist(tvb, offset, 10) || length == 3 + rounded4(v16(tvb, offset + 8));
case X_QueryTextExtents:
return length >= 2;
case X_ListFonts:
case X_ListFontsWithInfo:
case X_ChangeHosts:
return !tvb_bytes_exist(tvb, offset, 8) || length == 2 + rounded4(v16(tvb, offset + 6));
case X_SetFontPath:
if (length < 2) return FALSE;
if (!tvb_bytes_exist(tvb, offset, 8)) return TRUE;
return listOfStringLengthConsistent(tvb, offset + 8, (length - 2) * 4, v16(tvb, offset + 4));
case X_CreateGC:
return !tvb_bytes_exist(tvb, offset, 16) || length == 4 + numberOfBitSet(tvb, offset + 12, 4);
case X_SetDashes:
return !tvb_bytes_exist(tvb, offset, 12) || length == 3 + rounded4(v16(tvb, offset + 10));
case X_SetClipRectangles:
case X_PolySegment:
case X_PolyRectangle:
case X_PolyFillRectangle:
return length >= 3 && (length - 3) % 2 == 0;
case X_CopyArea:
return length == 7;
case X_CopyPlane:
case X_CreateCursor:
case X_CreateGlyphCursor:
return length == 8;
case X_PolyPoint:
case X_PolyLine:
case X_FreeColors:
return length >= 3;
case X_PolyArc:
case X_PolyFillArc:
return length >= 3 && (length - 3) % 3 == 0;
case X_FillPoly:
case X_ImageText8:
return length >= 4;
case X_PutImage:
return length >= 6;
case X_GetImage:
case X_RecolorCursor:
return length == 5;
case X_PolyText8:
if (length < 4) return FALSE;
return TRUE;
case X_PolyText16:
if (length < 4) return FALSE;
return TRUE;
case X_ImageText16:
return length >= 4;
case X_StoreColors:
return length > 2 && (length - 2) % 3 == 0;
case X_StoreNamedColor:
return !tvb_bytes_exist(tvb, offset, 14) || length == 4 + rounded4(v16(tvb, offset + 12));
case X_QueryColors:
return length >= 2;
case X_ChangeKeyboardMapping:
return !tvb_bytes_exist(tvb, offset, 6) || length == 2 + tvb_get_guint8(tvb, 1) * tvb_get_guint8(tvb, 5);
case X_ChangeKeyboardControl:
return !tvb_bytes_exist(tvb, offset, 6) || length == 2 + numberOfBitSet(tvb, offset + 4, 2);
case X_RotateProperties:
return !tvb_bytes_exist(tvb, offset, 10) || length == 3 + v16(tvb, offset + 8);
case X_SetPointerMapping:
return length == 1 + rounded4(tvb_get_guint8(tvb, 1));
case X_SetModifierMapping:
return length == 1 + tvb_get_guint8(tvb, 1) * 2;
case X_NoOperation:
return length >= 1;
default:
return TRUE;
}
}
static int x_endian_match(tvbuff_t *tvb, guint16 (*v16)(tvbuff_t *, const gint))
{
int offset, nextoffset;
int atLeastOne = 0;
for(offset = 0; tvb_bytes_exist(tvb, offset, 4); offset = nextoffset) {
int length;
length = v16(tvb, offset + 2);
if (!length) return -1;
nextoffset = offset + length * 4;
if (!consistentWithOrder(length, tvb, offset, v16)) return -1;
atLeastOne = 1;
}
return atLeastOne;
}
static guint
guess_byte_ordering(tvbuff_t *tvb, packet_info *pinfo,
x11_conv_data_t *state)
{
int le, be;
guint decision;
if (state->byte_order == BYTE_ORDER_BE)
return ENC_BIG_ENDIAN;
else if (state->byte_order == BYTE_ORDER_LE)
return ENC_LITTLE_ENDIAN;
if (pinfo->srcport == pinfo->match_uint) {
return ENC_LITTLE_ENDIAN;
}
le = x_endian_match(tvb, tvb_get_letohs);
be = x_endian_match(tvb, tvb_get_ntohs);
if (le == be) {
if (!tvb_bytes_exist(tvb, 0, 4))
decision = ENC_LITTLE_ENDIAN;
else {
if (tvb_get_letohs(tvb, 2) <= tvb_get_ntohs(tvb, 2))
decision = ENC_LITTLE_ENDIAN;
else
decision = ENC_BIG_ENDIAN;
}
} else {
if (le >= be)
decision = ENC_LITTLE_ENDIAN;
else
decision = ENC_BIG_ENDIAN;
}
if ((le < 0 && be > 0) || (le > 0 && be < 0)) {
state->byte_order = (decision == ENC_BIG_ENDIAN) ? BYTE_ORDER_BE : BYTE_ORDER_LE;
}
return decision;
}
static void dissect_x11_initial_conn(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, x11_conv_data_t *state, guint byte_order)
{
int offset = 0;
int *offsetp = &offset;
proto_item *ti;
proto_tree *t;
guint16 auth_proto_name_length, auth_proto_data_length;
gint left;
ti = proto_tree_add_item(tree, proto_x11, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Request, Initial connection request");
t = proto_item_add_subtree(ti, ett_x11);
CARD8(byte_order);
UNUSED(1);
CARD16(protocol_major_version);
CARD16(protocol_minor_version);
auth_proto_name_length = CARD16(authorization_protocol_name_length);
auth_proto_data_length = CARD16(authorization_protocol_data_length);
UNUSED(2);
if (auth_proto_name_length != 0) {
STRING8(authorization_protocol_name, auth_proto_name_length);
offset = ROUND_LENGTH(offset);
}
if (auth_proto_data_length != 0) {
STRING8(authorization_protocol_data, auth_proto_data_length);
offset = ROUND_LENGTH(offset);
}
if ((left = tvb_reported_length_remaining(tvb, offset)) > 0)
proto_tree_add_item(t, hf_x11_undecoded, tvb, offset, left,
ENC_NA);
state->iconn_frame = pinfo->fd->num;
state->sequencenumber = 0;
g_hash_table_insert(state->seqtable, GINT_TO_POINTER(state->sequencenumber),
(int *)INITIAL_CONN);
}
static void dissect_x11_initial_reply(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, const char _U_ *sep, x11_conv_data_t *volatile state,
guint byte_order)
{
int offset = 0, *offsetp = &offset, left;
unsigned char success;
int length_of_vendor;
int length_of_reason;
proto_item *ti;
proto_tree *t;
ti = proto_tree_add_item(tree, proto_x11, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Reply, Initial connection reply");
t = proto_item_add_subtree(ti, ett_x11);
state->iconn_reply = pinfo->fd->num;
success = INT8(success);
if (success) {
UNUSED(1);
length_of_reason = 0;
}
else {
length_of_reason = INT8(length_of_reason);
}
INT16(protocol_major_version);
INT16(protocol_minor_version);
INT16(replylength);
if (success) {
INT32(release_number);
INT32(resource_id_base);
INT32(resource_id_mask);
INT32(motion_buffer_size);
length_of_vendor = INT16(length_of_vendor);
INT16(maximum_request_length);
INT8(number_of_screens_in_roots);
INT8(number_of_formats_in_pixmap_formats);
INT8(image_byte_order);
INT8(bitmap_format_bit_order);
INT8(bitmap_format_scanline_unit);
INT8(bitmap_format_scanline_pad);
INT8(min_keycode);
INT8(max_keycode);
UNUSED(4);
STRING8(vendor, length_of_vendor);
} else {
STRING8(reason, length_of_reason);
}
if ((left = tvb_reported_length_remaining(tvb, offset)) > 0)
UNDECODED(left);
}
static void set_handler(const char *name, void (*func)(tvbuff_t *tvb, packet_info *pinfo, int *offsetp, proto_tree *t, guint byte_order),
const char **errors,
const x11_event_info *event_info,
const x11_reply_info *reply_info)
{
g_hash_table_insert(extension_table, (gpointer)name, (gpointer)func);
g_hash_table_insert(error_table, (gpointer)name, (gpointer)errors);
g_hash_table_insert(event_table, (gpointer)name, (gpointer)event_info);
g_hash_table_insert(reply_table, (gpointer)name, (gpointer)reply_info);
}
static int popcount(unsigned int mask)
{
#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
return __builtin_popcount(mask);
#else
unsigned long y;
y = (mask >> 1) &033333333333;
y = mask - y - ((y >>1) & 033333333333);
return (((y + (y >> 3)) & 030707070707) % 077);
#endif
}
static void tryExtension(int opcode, tvbuff_t *tvb, packet_info *pinfo, int *offsetp, proto_tree *t,
x11_conv_data_t *state, guint byte_order)
{
const gchar *extension;
void (*func)(tvbuff_t *tvb, packet_info *pinfo, int *offsetp, proto_tree *t, guint byte_order);
extension = try_val_to_str(opcode, state->opcode_vals);
if (!extension)
return;
func = (void (*)(tvbuff_t *, packet_info *, int *, proto_tree *, guint))g_hash_table_lookup(extension_table, extension);
if (func)
func(tvb, pinfo, offsetp, t, byte_order);
}
static void tryExtensionReply(int opcode, tvbuff_t *tvb, packet_info *pinfo, int *offsetp, proto_tree *t,
x11_conv_data_t *state, guint byte_order)
{
void (*func)(tvbuff_t *tvb, packet_info *pinfo, int *offsetp, proto_tree *t, guint byte_order);
func = (void (*)(tvbuff_t *, packet_info *, int *, proto_tree *, guint))g_hash_table_lookup(state->reply_funcs, GINT_TO_POINTER(opcode));
if (func)
func(tvb, pinfo, offsetp, t, byte_order);
else
REPLYCONTENTS_COMMON();
}
static void tryExtensionEvent(int event, tvbuff_t *tvb, int *offsetp, proto_tree *t,
x11_conv_data_t *state, guint byte_order)
{
void (*func)(tvbuff_t *tvb, int *offsetp, proto_tree *t, guint byte_order);
func = (void (*)(tvbuff_t *, int *, proto_tree *, guint))g_hash_table_lookup(state->eventcode_funcs, GINT_TO_POINTER(event));
if (func)
func(tvb, offsetp, t, byte_order);
}
static void register_extension(x11_conv_data_t *state, value_string *vals_p,
int major_opcode, unsigned int first_event, unsigned int first_error)
{
const char **error_string;
x11_event_info *event_info;
x11_reply_info *reply_info;
int i;
vals_p->value = major_opcode;
error_string = (const char **)g_hash_table_lookup(error_table, vals_p->strptr);
while (error_string && *error_string && first_error <= LastExtensionError) {
for (i = 0; i <= LastExtensionError; i++) {
if (state->errorcode_vals[i].strptr == NULL) {
state->errorcode_vals[i].value = first_error;
state->errorcode_vals[i].strptr = *error_string;
break;
} else if (state->errorcode_vals[i].value == first_error) {
state->errorcode_vals[i].strptr = *error_string;
break;
}
}
first_error++;
error_string++;
}
event_info = (x11_event_info *)g_hash_table_lookup(event_table, vals_p->strptr);
while (event_info && event_info->name && first_event <= LastExtensionEvent) {
for (i = 0; i <= LastExtensionEvent; i++) {
if (state->eventcode_vals[i].strptr == NULL) {
state->eventcode_vals[i].value = first_event;
state->eventcode_vals[i].strptr = event_info->name;
break;
} else if (state->eventcode_vals[i].value == first_event) {
state->eventcode_vals[i].strptr = event_info->name;
break;
}
}
g_hash_table_insert(state->eventcode_funcs, GINT_TO_POINTER(first_event), (gpointer)event_info->dissect);
first_event++;
event_info++;
}
reply_info = (x11_reply_info *)g_hash_table_lookup(reply_table, vals_p->strptr);
if (reply_info)
for (i = 0; reply_info[i].dissect; i++)
g_hash_table_insert(state->reply_funcs,
GINT_TO_POINTER(major_opcode | (reply_info[i].minor << 8)),
(gpointer)reply_info[i].dissect);
}
static void dissect_x11_request(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, const char *sep, x11_conv_data_t *state,
guint byte_order)
{
int offset = 0;
int *offsetp = &offset;
int next_offset;
proto_item *ti;
proto_tree *t;
int length, opcode, i;
guint8 v8, v8_2, v8_3;
guint16 v16;
guint32 v32;
gint left;
gchar *name;
length = VALUE16(tvb, 2) * 4;
if (length < 4) {
return;
}
next_offset = offset + length;
ti = proto_tree_add_item(tree, proto_x11, tvb, 0, -1, ENC_NA);
t = proto_item_add_subtree(ti, ett_x11);
if (PACKET_IS_NEW(pinfo))
++state->sequencenumber;
OPCODE();
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %s", sep,
val_to_str(opcode, state->opcode_vals,
"<Unknown opcode %d>"));
proto_item_append_text(ti, ", Request, opcode: %d (%s)",
opcode, val_to_str(opcode, state->opcode_vals,
"<Unknown opcode %d>"));
switch(opcode) {
case X_QueryExtension:
v16 = VALUE16(tvb, 4);
name = tvb_get_seasonal_string(tvb, 8, v16);
i = 0;
while(i < MAX_OPCODES) {
if (state->opcode_vals[i].strptr == NULL) {
state->opcode_vals[i].strptr = name;
state->opcode_vals[i].value = -1;
g_hash_table_insert(state->valtable,
GINT_TO_POINTER(state->sequencenumber),
(int *)&state->opcode_vals[i]);
break;
} else if (strcmp(state->opcode_vals[i].strptr,
name) == 0) {
g_hash_table_insert(state->valtable,
GINT_TO_POINTER(state->sequencenumber),
(int *)&state->opcode_vals[i]);
break;
}
i++;
}
case X_AllocColor:
case X_AllocColorCells:
case X_AllocColorPlanes:
case X_AllocNamedColor:
case X_GetAtomName:
case X_GetFontPath:
case X_GetGeometry:
case X_GetImage:
case X_GetInputFocus:
case X_GetKeyboardControl:
case X_GetKeyboardMapping:
case X_GetModifierMapping:
case X_GetMotionEvents:
case X_GetPointerControl:
case X_GetPointerMapping:
case X_GetProperty:
case X_GetScreenSaver:
case X_GetSelectionOwner:
case X_GetWindowAttributes:
case X_GrabKeyboard:
case X_GrabPointer:
case X_InternAtom:
case X_ListExtensions:
case X_ListFonts:
case X_ListFontsWithInfo:
case X_ListHosts:
case X_ListInstalledColormaps:
case X_ListProperties:
case X_LookupColor:
case X_QueryBestSize:
case X_QueryColors:
case X_QueryFont:
case X_QueryKeymap:
case X_QueryPointer:
case X_QueryTextExtents:
case X_QueryTree:
case X_SetModifierMapping:
case X_SetPointerMapping:
case X_TranslateCoords:
g_hash_table_insert(state->seqtable,
GINT_TO_POINTER(state->sequencenumber),
GINT_TO_POINTER(opcode));
break;
default:
if (opcode >= X_FirstExtension && opcode <= X_LastExtension) {
guint32 minor;
minor = tvb_get_guint8(tvb, 1);
g_hash_table_insert(state->seqtable,
GINT_TO_POINTER(state->sequencenumber),
GINT_TO_POINTER(opcode | (minor << 8)));
}
break;
}
if (tree == NULL)
return;
switch(opcode) {
case X_CreateWindow:
CARD8(depth);
REQUEST_LENGTH();
WINDOW(wid);
WINDOW(parent);
INT16(x);
INT16(y);
CARD16(width);
CARD16(height);
CARD16(border_width);
ENUM16(window_class);
VISUALID(visual);
windowAttributes(tvb, offsetp, t, byte_order);
break;
case X_ChangeWindowAttributes:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
windowAttributes(tvb, offsetp, t, byte_order);
break;
case X_GetWindowAttributes:
case X_DestroyWindow:
case X_DestroySubwindows:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
break;
case X_ChangeSaveSet:
ENUM8(save_set_mode);
REQUEST_LENGTH();
WINDOW(window);
break;
case X_ReparentWindow:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
WINDOW(parent);
INT16(x);
INT16(y);
break;
case X_MapWindow:
case X_MapSubwindows:
case X_UnmapWindow:
case X_UnmapSubwindows:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
break;
case X_ConfigureWindow:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
BITMASK16(configure_window);
UNUSED(2);
BITFIELD(INT16, configure_window_mask, x);
BITFIELD(INT16, configure_window_mask, y);
BITFIELD(CARD16, configure_window_mask, width);
BITFIELD(CARD16, configure_window_mask, height);
BITFIELD(CARD16, configure_window_mask, border_width);
BITFIELD(WINDOW, configure_window_mask, sibling);
BITFIELD(ENUM8, configure_window_mask, stack_mode);
ENDBITMASK;
PAD();
break;
case X_CirculateWindow:
ENUM8(direction);
REQUEST_LENGTH();
WINDOW(window);
break;
case X_GetGeometry:
case X_QueryTree:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(drawable);
break;
case X_InternAtom:
BOOL(only_if_exists);
REQUEST_LENGTH();
v16 = FIELD16(name_length);
UNUSED(2);
STRING8(name, v16);
PAD();
break;
case X_GetAtomName:
UNUSED(1);
REQUEST_LENGTH();
ATOM(atom);
break;
case X_ChangeProperty:
ENUM8(mode);
REQUEST_LENGTH();
WINDOW(window);
ATOM(property);
ATOM(type);
v8 = CARD8(format);
UNUSED(3);
v32 = CARD32(data_length);
switch (v8) {
case 8:
if (v32)
LISTofBYTE(data, v32);
break;
case 16:
if (v32)
LISTofCARD16(data16, v32 * 2);
break;
case 32:
if (v32)
LISTofCARD32(data32, v32 * 4);
break;
default:
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN, "Invalid Format");
break;
}
PAD();
break;
case X_DeleteProperty:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
ATOM(property);
break;
case X_GetProperty:
BOOL(delete);
REQUEST_LENGTH();
WINDOW(window);
ATOM(property);
ATOM(get_property_type);
CARD32(long_offset);
CARD32(long_length);
break;
case X_ListProperties:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
break;
case X_SetSelectionOwner:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(owner);
ATOM(selection);
TIMESTAMP(time);
break;
case X_GetSelectionOwner:
UNUSED(1);
REQUEST_LENGTH();
ATOM(selection);
break;
case X_ConvertSelection:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(requestor);
ATOM(selection);
ATOM(target);
ATOM(property);
TIMESTAMP(time);
break;
case X_SendEvent:
BOOL(propagate);
REQUEST_LENGTH();
WINDOW(destination);
SETofEVENT(event_mask);
EVENT();
break;
case X_GrabPointer:
BOOL(owner_events);
REQUEST_LENGTH();
WINDOW(grab_window);
SETofPOINTEREVENT(pointer_event_mask);
ENUM8(pointer_mode);
ENUM8(keyboard_mode);
WINDOW(confine_to);
CURSOR(cursor);
TIMESTAMP(time);
break;
case X_UngrabPointer:
UNUSED(1);
REQUEST_LENGTH();
TIMESTAMP(time);
break;
case X_GrabButton:
BOOL(owner_events);
REQUEST_LENGTH();
WINDOW(grab_window);
SETofPOINTEREVENT(event_mask);
ENUM8(pointer_mode);
ENUM8(keyboard_mode);
WINDOW(confine_to);
CURSOR(cursor);
BUTTON(button);
UNUSED(1);
SETofKEYMASK(modifiers);
break;
case X_UngrabButton:
BUTTON(button);
REQUEST_LENGTH();
WINDOW(grab_window);
SETofKEYMASK(modifiers);
UNUSED(2);
break;
case X_ChangeActivePointerGrab:
UNUSED(1);
REQUEST_LENGTH();
CURSOR(cursor);
TIMESTAMP(time);
SETofPOINTEREVENT(event_mask);
UNUSED(2);
break;
case X_GrabKeyboard:
BOOL(owner_events);
REQUEST_LENGTH();
WINDOW(grab_window);
TIMESTAMP(time);
ENUM8(pointer_mode);
ENUM8(keyboard_mode);
UNUSED(2);
break;
case X_UngrabKeyboard:
UNUSED(1);
REQUEST_LENGTH();
TIMESTAMP(time);
break;
case X_GrabKey:
BOOL(owner_events);
REQUEST_LENGTH();
WINDOW(grab_window);
SETofKEYMASK(modifiers);
KEYCODE(key);
ENUM8(pointer_mode);
ENUM8(keyboard_mode);
UNUSED(3);
break;
case X_UngrabKey:
KEYCODE(key);
REQUEST_LENGTH();
WINDOW(grab_window);
SETofKEYMASK(modifiers);
UNUSED(2);
break;
case X_AllowEvents:
ENUM8(allow_events_mode);
REQUEST_LENGTH();
TIMESTAMP(time);
break;
case X_GrabServer:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_UngrabServer:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_QueryPointer:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
break;
case X_GetMotionEvents:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
TIMESTAMP(start);
TIMESTAMP(stop);
break;
case X_TranslateCoords:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(src_window);
WINDOW(dst_window);
INT16(src_x);
INT16(src_y);
break;
case X_WarpPointer:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(warp_pointer_src_window);
WINDOW(warp_pointer_dst_window);
INT16(src_x);
INT16(src_y);
CARD16(src_width);
CARD16(src_height);
INT16(dst_x);
INT16(dst_y);
break;
case X_SetInputFocus:
ENUM8(revert_to);
REQUEST_LENGTH();
WINDOW(focus);
TIMESTAMP(time);
break;
case X_GetInputFocus:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_QueryKeymap:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_OpenFont:
UNUSED(1);
REQUEST_LENGTH();
FONT(fid);
v16 = FIELD16(name_length);
UNUSED(2);
STRING8(name, v16);
PAD();
break;
case X_CloseFont:
UNUSED(1);
REQUEST_LENGTH();
FONT(font);
break;
case X_QueryFont:
UNUSED(1);
REQUEST_LENGTH();
FONTABLE(font);
break;
case X_QueryTextExtents:
v8 = BOOL(odd_length);
REQUEST_LENGTH();
FONTABLE(font);
STRING16(string16, (next_offset - offset - (v8 ? 2 : 0)) / 2);
PAD();
break;
case X_ListFonts:
UNUSED(1);
REQUEST_LENGTH();
CARD16(max_names);
v16 = FIELD16(pattern_length);
STRING8(pattern, v16);
PAD();
break;
case X_ListFontsWithInfo:
UNUSED(1);
REQUEST_LENGTH();
CARD16(max_names);
v16 = FIELD16(pattern_length);
STRING8(pattern, v16);
PAD();
break;
case X_SetFontPath:
UNUSED(1);
REQUEST_LENGTH();
v16 = CARD16(str_number_in_path);
UNUSED(2);
LISTofSTRING8(path, v16);
PAD();
break;
case X_GetFontPath:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_CreatePixmap:
CARD8(depth);
REQUEST_LENGTH();
PIXMAP(pid);
DRAWABLE(drawable);
CARD16(width);
CARD16(height);
break;
case X_FreePixmap:
UNUSED(1);
REQUEST_LENGTH();
PIXMAP(pixmap);
break;
case X_CreateGC:
UNUSED(1);
REQUEST_LENGTH();
GCONTEXT(cid);
DRAWABLE(drawable);
gcAttributes(tvb, offsetp, t, byte_order);
break;
case X_ChangeGC:
UNUSED(1);
REQUEST_LENGTH();
GCONTEXT(gc);
gcAttributes(tvb, offsetp, t, byte_order);
break;
case X_CopyGC:
UNUSED(1);
REQUEST_LENGTH();
GCONTEXT(src_gc);
GCONTEXT(dst_gc);
gcMask(tvb, offsetp, t, byte_order);
break;
case X_SetDashes:
UNUSED(1);
REQUEST_LENGTH();
GCONTEXT(gc);
CARD16(dash_offset);
v16 = FIELD16(dashes_length);
LISTofCARD8(dashes, v16);
PAD();
break;
case X_SetClipRectangles:
ENUM8(ordering);
REQUEST_LENGTH();
GCONTEXT(gc);
INT16(clip_x_origin);
INT16(clip_y_origin);
LISTofRECTANGLE(rectangles);
break;
case X_FreeGC:
UNUSED(1);
REQUEST_LENGTH();
GCONTEXT(gc);
break;
case X_ClearArea:
BOOL(exposures);
REQUEST_LENGTH();
WINDOW(window);
INT16(x);
INT16(y);
CARD16(width);
CARD16(height);
break;
case X_CopyArea:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(src_drawable);
DRAWABLE(dst_drawable);
GCONTEXT(gc);
INT16(src_x);
INT16(src_y);
INT16(dst_x);
INT16(dst_y);
CARD16(width);
CARD16(height);
break;
case X_CopyPlane:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(src_drawable);
DRAWABLE(dst_drawable);
GCONTEXT(gc);
INT16(src_x);
INT16(src_y);
INT16(dst_x);
INT16(dst_y);
CARD16(width);
CARD16(height);
CARD32(bit_plane);
break;
case X_PolyPoint:
ENUM8(coordinate_mode);
v16 = REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
LISTofPOINT(points, v16 - 12);
break;
case X_PolyLine:
ENUM8(coordinate_mode);
v16 = REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
LISTofPOINT(points, v16 - 12);
break;
case X_PolySegment:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
LISTofSEGMENT(segments);
break;
case X_PolyRectangle:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
LISTofRECTANGLE(rectangles);
break;
case X_PolyArc:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
LISTofARC(arcs);
break;
case X_FillPoly:
UNUSED(1);
v16 = REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
ENUM8(shape);
ENUM8(coordinate_mode);
UNUSED(2);
LISTofPOINT(points, v16 - 16);
break;
case X_PolyFillRectangle:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
LISTofRECTANGLE(rectangles);
break;
case X_PolyFillArc:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
LISTofARC(arcs);
break;
case X_PutImage:
ENUM8(image_format);
v16 = REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
CARD16(width);
CARD16(height);
INT16(dst_x);
INT16(dst_y);
CARD8(left_pad);
CARD8(depth);
UNUSED(2);
LISTofBYTE(data, v16 - 24);
PAD();
break;
case X_GetImage:
ENUM8(image_pixmap_format);
REQUEST_LENGTH();
DRAWABLE(drawable);
INT16(x);
INT16(y);
CARD16(width);
CARD16(height);
CARD32(plane_mask);
break;
case X_PolyText8:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
INT16(x);
INT16(y);
LISTofTEXTITEM8(items);
PAD();
break;
case X_PolyText16:
UNUSED(1);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
INT16(x);
INT16(y);
LISTofTEXTITEM16(items);
PAD();
break;
case X_ImageText8:
v8 = FIELD8(string_length);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
INT16(x);
INT16(y);
STRING8(string, v8);
PAD();
break;
case X_ImageText16:
v8 = FIELD8(string_length);
REQUEST_LENGTH();
DRAWABLE(drawable);
GCONTEXT(gc);
INT16(x);
INT16(y);
STRING16(string16, v8);
PAD();
break;
case X_CreateColormap:
ENUM8(alloc);
REQUEST_LENGTH();
COLORMAP(mid);
WINDOW(window);
VISUALID(visual);
break;
case X_FreeColormap:
UNUSED(1);
REQUEST_LENGTH();
COLORMAP(cmap);
break;
case X_CopyColormapAndFree:
UNUSED(1);
REQUEST_LENGTH();
COLORMAP(mid);
COLORMAP(src_cmap);
break;
case X_InstallColormap:
UNUSED(1);
REQUEST_LENGTH();
COLORMAP(cmap);
break;
case X_UninstallColormap:
UNUSED(1);
REQUEST_LENGTH();
COLORMAP(cmap);
break;
case X_ListInstalledColormaps:
UNUSED(1);
REQUEST_LENGTH();
WINDOW(window);
break;
case X_AllocColor:
UNUSED(1);
REQUEST_LENGTH();
COLORMAP(cmap);
CARD16(red);
CARD16(green);
CARD16(blue);
UNUSED(2);
break;
case X_AllocNamedColor:
UNUSED(1);
REQUEST_LENGTH();
COLORMAP(cmap);
v16 = FIELD16(name_length);
UNUSED(2);
STRING8(name, v16);
PAD();
break;
case X_AllocColorCells:
BOOL(contiguous);
REQUEST_LENGTH();
COLORMAP(cmap);
CARD16(colors);
CARD16(planes);
break;
case X_AllocColorPlanes:
BOOL(contiguous);
REQUEST_LENGTH();
COLORMAP(cmap);
CARD16(colors);
CARD16(reds);
CARD16(greens);
CARD16(blues);
break;
case X_FreeColors:
UNUSED(1);
v16 = REQUEST_LENGTH();
COLORMAP(cmap);
CARD32(plane_mask);
LISTofCARD32(pixels, v16 - 12);
break;
case X_StoreColors:
UNUSED(1);
v16 = REQUEST_LENGTH();
COLORMAP(cmap);
LISTofCOLORITEM(color_items, v16 - 8);
break;
case X_StoreNamedColor:
COLOR_FLAGS(color);
REQUEST_LENGTH();
COLORMAP(cmap);
CARD32(pixel);
v16 = FIELD16(name_length);
UNUSED(2);
STRING8(name, v16);
PAD();
break;
case X_QueryColors:
UNUSED(1);
v16 = REQUEST_LENGTH();
COLORMAP(cmap);
LISTofCARD32(pixels, v16 - 8);
break;
case X_LookupColor:
UNUSED(1);
REQUEST_LENGTH();
COLORMAP(cmap);
v16 = FIELD16(name_length);
UNUSED(2);
STRING8(name, v16);
PAD();
break;
case X_CreateCursor:
UNUSED(1);
REQUEST_LENGTH();
CURSOR(cid);
PIXMAP(source_pixmap);
PIXMAP(mask);
CARD16(fore_red);
CARD16(fore_green);
CARD16(fore_blue);
CARD16(back_red);
CARD16(back_green);
CARD16(back_blue);
CARD16(x);
CARD16(y);
break;
case X_CreateGlyphCursor:
UNUSED(1);
REQUEST_LENGTH();
CURSOR(cid);
FONT(source_font);
FONT(mask_font);
CARD16(source_char);
CARD16(mask_char);
CARD16(fore_red);
CARD16(fore_green);
CARD16(fore_blue);
CARD16(back_red);
CARD16(back_green);
CARD16(back_blue);
break;
case X_FreeCursor:
UNUSED(1);
REQUEST_LENGTH();
CURSOR(cursor);
break;
case X_RecolorCursor:
UNUSED(1);
REQUEST_LENGTH();
CURSOR(cursor);
CARD16(fore_red);
CARD16(fore_green);
CARD16(fore_blue);
CARD16(back_red);
CARD16(back_green);
CARD16(back_blue);
break;
case X_QueryBestSize:
ENUM8(class);
REQUEST_LENGTH();
DRAWABLE(drawable);
CARD16(width);
CARD16(height);
break;
case X_QueryExtension:
UNUSED(1);
REQUEST_LENGTH();
v16 = FIELD16(name_length);
UNUSED(2);
STRING8(name, v16);
PAD();
break;
case X_ListExtensions:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_ChangeKeyboardMapping:
v8 = FIELD8(keycode_count);
REQUEST_LENGTH();
v8_2 = KEYCODE(first_keycode);
v8_3 = FIELD8(keysyms_per_keycode);
UNUSED(2);
LISTofKEYSYM(keysyms, state->keycodemap, v8_2, v8, v8_3);
break;
case X_GetKeyboardMapping:
UNUSED(1);
REQUEST_LENGTH();
state->request.GetKeyboardMapping.first_keycode
= KEYCODE(first_keycode);
FIELD8(count);
UNUSED(2);
break;
case X_ChangeKeyboardControl:
UNUSED(1);
REQUEST_LENGTH();
BITMASK32(keyboard_value);
BITFIELD(INT8, keyboard_value_mask, key_click_percent);
BITFIELD(INT8, keyboard_value_mask, bell_percent);
BITFIELD(INT16, keyboard_value_mask, bell_pitch);
BITFIELD(INT16, keyboard_value_mask, bell_duration);
BITFIELD(INT16, keyboard_value_mask, led);
BITFIELD(ENUM8, keyboard_value_mask, led_mode);
BITFIELD(KEYCODE, keyboard_value_mask, keyboard_key);
BITFIELD(ENUM8, keyboard_value_mask, auto_repeat_mode);
ENDBITMASK;
break;
case X_GetKeyboardControl:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_Bell:
INT8(percent);
REQUEST_LENGTH();
break;
case X_ChangePointerControl:
UNUSED(1);
REQUEST_LENGTH();
INT16(acceleration_numerator);
INT16(acceleration_denominator);
INT16(threshold);
BOOL(do_acceleration);
BOOL(do_threshold);
break;
case X_GetPointerControl:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_SetScreenSaver:
UNUSED(1);
REQUEST_LENGTH();
INT16(timeout);
INT16(interval);
ENUM8(prefer_blanking);
ENUM8(allow_exposures);
UNUSED(2);
break;
case X_GetScreenSaver:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_ChangeHosts:
ENUM8(change_host_mode);
REQUEST_LENGTH();
v8 = ENUM8(family);
UNUSED(1);
v16 = CARD16(address_length);
if (v8 == FAMILY_INTERNET && v16 == 4) {
LISTofIPADDRESS(ip_address, v16);
} else
LISTofCARD8(address, v16);
break;
case X_ListHosts:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_SetAccessControl:
ENUM8(access_mode);
REQUEST_LENGTH();
break;
case X_SetCloseDownMode:
ENUM8(close_down_mode);
REQUEST_LENGTH();
break;
case X_KillClient:
UNUSED(1);
REQUEST_LENGTH();
CARD32(resource);
break;
case X_RotateProperties:
UNUSED(1);
v16 = REQUEST_LENGTH();
WINDOW(window);
CARD16(property_number);
INT16(delta);
LISTofATOM(properties, (v16 - 12));
break;
case X_ForceScreenSaver:
ENUM8(screen_saver_mode);
REQUEST_LENGTH();
break;
case X_SetPointerMapping:
v8 = FIELD8(map_length);
REQUEST_LENGTH();
LISTofCARD8(map, v8);
PAD();
break;
case X_GetPointerMapping:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_SetModifierMapping:
v8 = FIELD8(keycodes_per_modifier);
REQUEST_LENGTH();
LISTofKEYCODE(state->modifiermap, keycodes, v8);
break;
case X_GetModifierMapping:
UNUSED(1);
REQUEST_LENGTH();
break;
case X_NoOperation:
UNUSED(1);
REQUEST_LENGTH();
break;
default:
tryExtension(opcode, tvb, pinfo, offsetp, t, state, byte_order);
break;
}
if ((left = tvb_reported_length_remaining(tvb, offset)) > 0)
UNDECODED(left);
}
static void dissect_x11_requests(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree)
{
volatile int offset = 0;
int length_remaining;
volatile guint byte_order;
guint8 opcode;
volatile int plen;
proto_item *ti;
proto_tree *t;
volatile gboolean is_initial_creq;
guint16 auth_proto_len, auth_data_len;
const char *volatile sep = NULL;
conversation_t *conversation;
x11_conv_data_t *volatile state;
int length;
tvbuff_t *volatile next_tvb;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
length_remaining = tvb_ensure_length_remaining(tvb, offset);
if (x11_desegment && pinfo->can_desegment) {
if (length_remaining < 4) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
}
conversation = find_or_create_conversation(pinfo);
if ((state = (x11_conv_data_t *)conversation_get_proto_data(conversation, proto_x11))
== NULL)
state = x11_stateinit(conversation);
byte_order = guess_byte_ordering(tvb, pinfo, state);
opcode = VALUE8(tvb, 0);
plen = VALUE16(tvb, offset + 2);
if (plen == 0) {
ti = proto_tree_add_item(tree, proto_x11, tvb, offset, -1,
ENC_NA);
t = proto_item_add_subtree(ti, ett_x11);
proto_tree_add_text(t, tvb, offset, -1,
"Bogus request length (0)");
return;
}
if (state->iconn_frame == pinfo->fd->num ||
(g_hash_table_lookup(state->seqtable,
GINT_TO_POINTER(state->sequencenumber)) == (int *)NOTHING_SEEN &&
(opcode == 'B' || opcode == 'l') &&
(plen == 11 || plen == 2816))) {
is_initial_creq = TRUE;
if (state->byte_order == BYTE_ORDER_UNKNOWN) {
if (opcode == 'B') {
state->byte_order = BYTE_ORDER_BE;
byte_order = ENC_BIG_ENDIAN;
} else {
state->byte_order = BYTE_ORDER_LE;
byte_order = ENC_LITTLE_ENDIAN;
}
}
if (x11_desegment && pinfo->can_desegment) {
if (length_remaining < 10) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
}
auth_proto_len = VALUE16(tvb, offset + 6);
auth_data_len = VALUE16(tvb, offset + 8);
plen = 12 + ROUND_LENGTH(auth_proto_len) +
ROUND_LENGTH(auth_data_len);
} else {
is_initial_creq = FALSE;
plen *= 4;
}
if (x11_desegment && pinfo->can_desegment) {
if (length_remaining < plen) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = plen - length_remaining;
return;
}
}
length = length_remaining;
if (length > plen)
length = plen;
next_tvb = tvb_new_subset(tvb, offset, length, plen);
if (is_initial_creq) {
col_set_str(pinfo->cinfo, COL_INFO, "Initial connection request");
} else {
if (sep == NULL) {
col_set_str(pinfo->cinfo, COL_INFO, "Requests");
sep = ":";
}
}
TRY {
if (is_initial_creq) {
dissect_x11_initial_conn(next_tvb, pinfo, tree,
state, byte_order);
} else {
dissect_x11_request(next_tvb, pinfo, tree, sep,
state, byte_order);
}
}
CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
offset += plen;
sep = ",";
}
}
static x11_conv_data_t *
x11_stateinit(conversation_t *conversation)
{
x11_conv_data_t *state;
static x11_conv_data_t stateinit;
int i;
state = (x11_conv_data_t *)g_malloc(sizeof (x11_conv_data_t));
*state = stateinit;
state->next = x11_conv_data_list;
x11_conv_data_list = state;
for (i = 0; opcode_vals[i].strptr != NULL; i++) {
state->opcode_vals[i].value = opcode_vals[i].value;
state->opcode_vals[i].strptr = opcode_vals[i].strptr;
}
for (; i <= MAX_OPCODES; i++) {
state->opcode_vals[i].value = 0;
state->opcode_vals[i].strptr = NULL;
}
for (i = 0; errorcode_vals[i].strptr != NULL; i++) {
state->errorcode_vals[i].value = errorcode_vals[i].value;
state->errorcode_vals[i].strptr = errorcode_vals[i].strptr;
}
for (; i <= LastExtensionError + 1; i++) {
state->errorcode_vals[i].value = 0;
state->errorcode_vals[i].strptr = NULL;
}
for (i = 0; eventcode_vals[i].strptr != NULL; i++) {
state->eventcode_vals[i].value = eventcode_vals[i].value;
state->eventcode_vals[i].strptr = eventcode_vals[i].strptr;
}
for (; i <= LastExtensionEvent + 1; i++) {
state->eventcode_vals[i].value = 0;
state->eventcode_vals[i].strptr = NULL;
}
state->eventcode_funcs = g_hash_table_new(g_direct_hash, g_direct_equal);
state->reply_funcs = g_hash_table_new(g_direct_hash, g_direct_equal);
state->seqtable = g_hash_table_new(g_direct_hash, g_direct_equal);
state->valtable = g_hash_table_new(g_direct_hash, g_direct_equal);
g_hash_table_insert(state->seqtable, (int *)0, (int *)NOTHING_SEEN);
state->byte_order = BYTE_ORDER_UNKNOWN;
conversation_add_proto_data(conversation, proto_x11, state);
return state;
}
static void
dissect_x11_replies(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
volatile int offset, plen;
tvbuff_t * volatile next_tvb;
conversation_t *conversation;
x11_conv_data_t *volatile state;
volatile guint byte_order;
int length_remaining;
const char *volatile sep = NULL;
conversation = find_or_create_conversation(pinfo);
if ((state = (x11_conv_data_t *)conversation_get_proto_data(conversation, proto_x11))
== NULL) {
state = x11_stateinit(conversation);
}
byte_order = guess_byte_ordering(tvb, pinfo, state);
offset = 0;
while (tvb_reported_length_remaining(tvb, offset) != 0) {
length_remaining = tvb_ensure_length_remaining(tvb, offset);
if (x11_desegment && pinfo->can_desegment) {
if (length_remaining < 8) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
}
if (g_hash_table_lookup(state->seqtable,
GINT_TO_POINTER(state->sequencenumber)) == (int *)INITIAL_CONN
|| (state->iconn_reply == pinfo->fd->num)) {
plen = 8 + VALUE16(tvb, offset + 6) * 4;
HANDLE_REPLY(plen, length_remaining,
"Initial connection reply",
dissect_x11_initial_reply);
} else {
switch (tvb_get_guint8(tvb, offset)) {
case 0:
plen = 32;
HANDLE_REPLY(plen, length_remaining,
"Error", dissect_x11_error);
break;
case 1:
{
int tmp_plen;
tmp_plen = plen = 32 + VALUE32(tvb, offset + 4) * 4;
THROW_ON(tmp_plen < 32, ReportedBoundsError);
HANDLE_REPLY(plen, length_remaining,
"Reply", dissect_x11_reply);
break;
}
default:
plen = 32;
HANDLE_REPLY(plen, length_remaining,
"Event", dissect_x11_event);
break;
}
}
offset += plen;
}
return;
}
static void
dissect_x11_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const char *volatile sep, x11_conv_data_t *volatile state,
guint byte_order)
{
int offset = 0, *offsetp = &offset, length, left, opcode;
int major_opcode, sequence_number, first_error, first_event;
value_string *vals_p;
proto_item *ti;
proto_tree *t;
ti = proto_tree_add_item(tree, proto_x11, tvb, 0, -1, ENC_NA);
t = proto_item_add_subtree(ti, ett_x11);
sequence_number = VALUE16(tvb, offset + 2);
opcode = GPOINTER_TO_INT(g_hash_table_lookup(state->seqtable,
GINT_TO_POINTER(sequence_number)));
if (state->iconn_frame == 0 && state->resync == FALSE) {
state->sequencenumber = sequence_number;
state->resync = TRUE;
}
if (opcode == UNKNOWN_OPCODE) {
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO,
"%s to unknown request", sep);
proto_item_append_text(ti, ", Reply to unknown request");
} else {
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %s",
sep,
val_to_str(opcode & 0xFF, state->opcode_vals,
"<Unknown opcode %d>"));
if (opcode > 0xFF)
proto_item_append_text(ti, ", Reply, opcode: %d.%d (%s)",
opcode & 0xFF, opcode >> 8, val_to_str(opcode & 0xFF,
state->opcode_vals,
"<Unknown opcode %d>"));
else
proto_item_append_text(ti, ", Reply, opcode: %d (%s)",
opcode, val_to_str(opcode,
state->opcode_vals,
"<Unknown opcode %d>"));
}
switch (opcode) {
case X_QueryExtension:
if (!VALUE8(tvb, offset + 8)) {
break;
}
vals_p = (value_string *)g_hash_table_lookup(state->valtable,
GINT_TO_POINTER(sequence_number));
if (vals_p != NULL) {
major_opcode = VALUE8(tvb, offset + 9);
first_event = VALUE8(tvb, offset + 10);
first_error = VALUE8(tvb, offset + 11);
register_extension(state, vals_p, major_opcode, first_event, first_error);
g_hash_table_remove(state->valtable,
GINT_TO_POINTER(sequence_number));
}
break;
default:
break;
}
if (tree == NULL)
return;
switch (opcode) {
case X_GetWindowAttributes:
REPLYCONTENTS_COMMON();
break;
case X_GetGeometry:
REPLY(reply);
CARD8(depth);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
WINDOW(rootwindow);
INT16(x);
INT16(y);
CARD16(width);
CARD16(height);
CARD16(border_width);
UNUSED(10);
break;
case X_QueryTree:
REPLYCONTENTS_COMMON();
break;
case X_InternAtom:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
ATOM(atom);
UNUSED(20);
break;
case X_GetAtomName:
REPLYCONTENTS_COMMON();
break;
case X_GetProperty:
REPLY(reply);
CARD8(format);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
ATOM(get_property_type);
CARD32(bytes_after);
CARD32(valuelength);
UNUSED(12);
break;
case X_ListProperties:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
length = CARD16(property_number);
UNUSED(22);
LISTofATOM(properties, length*4);
break;
case X_GetSelectionOwner:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
WINDOW(owner);
UNUSED(20);
break;
case X_GrabPointer:
case X_GrabKeyboard:
REPLY(reply);
ENUM8(grab_status);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
UNUSED(24);
break;
case X_QueryPointer:
REPLY(reply);
BOOL(same_screen);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
WINDOW(rootwindow);
WINDOW(childwindow);
INT16(root_x);
INT16(root_y);
INT16(win_x);
INT16(win_y);
SETofKEYBUTMASK(mask);
UNUSED(6);
break;
case X_GetMotionEvents:
REPLYCONTENTS_COMMON();
break;
case X_TranslateCoords:
REPLY(reply);
BOOL(same_screen);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
WINDOW(childwindow);
INT16(dst_x);
INT16(dst_y);
UNUSED(16);
break;
case X_GetInputFocus:
REPLY(reply);
ENUM8(revert_to);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
WINDOW(focus);
UNUSED(20);
break;
case X_QueryKeymap:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
LISTofCARD8(keys, 32);
break;
case X_QueryFont:
case X_QueryTextExtents:
case X_ListFonts:
case X_GetImage:
case X_ListInstalledColormaps:
REPLYCONTENTS_COMMON();
break;
case X_AllocColor:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
CARD16(red);
CARD16(green);
CARD16(blue);
UNUSED(2);
CARD32(pixel);
UNUSED(12);
break;
case X_QueryColors:
REPLYCONTENTS_COMMON();
break;
case X_LookupColor:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
CARD16(exact_red);
CARD16(exact_green);
CARD16(exact_blue);
CARD16(visual_red);
CARD16(visual_green);
CARD16(visual_blue);
UNUSED(12);
break;
case X_QueryBestSize:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
CARD16(width);
CARD16(height);
UNUSED(20);
break;
case X_QueryExtension:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
BOOL(present);
CARD8(major_opcode);
CARD8(first_event);
CARD8(first_error);
UNUSED(20);
break;
case X_ListExtensions:
REPLYCONTENTS_COMMON();
break;
case X_GetKeyboardMapping:
state->first_keycode =
state->request.GetKeyboardMapping.first_keycode;
REPLY(reply);
state->keysyms_per_keycode =
FIELD8(keysyms_per_keycode);
SEQUENCENUMBER_REPLY(sequencenumber);
length = REPLYLENGTH(replylength);
UNUSED(24);
LISTofKEYSYM(keysyms, state->keycodemap,
state->request.GetKeyboardMapping.first_keycode,
state->keysyms_per_keycode ? length / state->keysyms_per_keycode : 0,
state->keysyms_per_keycode);
break;
case X_GetKeyboardControl:
REPLYCONTENTS_COMMON();
break;
case X_GetPointerControl:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
CARD16(acceleration_numerator);
CARD16(acceleration_denominator);
CARD16(threshold);
UNUSED(18);
break;
case X_GetScreenSaver:
REPLY(reply);
UNUSED(1);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
CARD16(timeout);
CARD16(interval);
ENUM8(prefer_blanking);
ENUM8(allow_exposures);
UNUSED(18);
break;
case X_ListHosts:
case X_SetPointerMapping:
case X_GetPointerMapping:
case X_SetModifierMapping:
REPLYCONTENTS_COMMON();
break;
case X_GetModifierMapping:
REPLY(reply);
state->keycodes_per_modifier =
FIELD8(keycodes_per_modifier);
SEQUENCENUMBER_REPLY(sequencenumber);
REPLYLENGTH(replylength);
UNUSED(24);
LISTofKEYCODE(state->modifiermap, keycodes,
state->keycodes_per_modifier);
break;
case UNKNOWN_OPCODE:
REPLYCONTENTS_COMMON();
break;
default:
tryExtensionReply(opcode, tvb, pinfo, offsetp, t, state, byte_order);
}
if ((left = tvb_reported_length_remaining(tvb, offset)) > 0)
UNDECODED(left);
}
static void
same_screen_focus(tvbuff_t *tvb, int *offsetp, proto_tree *t)
{
proto_item *ti;
guint32 bitmask_value;
int bitmask_offset;
int bitmask_size;
proto_tree *bitmask_tree;
bitmask_value = VALUE8(tvb, *offsetp);
bitmask_offset = *offsetp;
bitmask_size = 1;
ti = proto_tree_add_uint(t, hf_x11_same_screen_focus_mask, tvb, *offsetp, 1,
bitmask_value);
bitmask_tree = proto_item_add_subtree(ti, ett_x11_same_screen_focus);
FLAG(same_screen_focus, focus);
FLAG(same_screen_focus, same_screen);
*offsetp += 1;
}
static void
dissect_x11_event(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const char *volatile sep, x11_conv_data_t *volatile state,
guint byte_order)
{
unsigned char eventcode;
const char *sent;
proto_item *ti;
proto_tree *t;
ti = proto_tree_add_item(tree, proto_x11, tvb, 0, -1, ENC_NA);
t = proto_item_add_subtree(ti, ett_x11);
eventcode = tvb_get_guint8(tvb, 0);
sent = (eventcode & 0x80) ? "Sent-" : "";
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %s%s",
sep, sent,
val_to_str(eventcode & 0x7F, state->eventcode_vals,
"<Unknown eventcode %u>"));
proto_item_append_text(ti, ", Event, eventcode: %d (%s%s)",
eventcode, sent,
val_to_str(eventcode & 0x7F, state->eventcode_vals,
"<Unknown eventcode %u>"));
if (tree == NULL)
return;
decode_x11_event(tvb, eventcode, sent, t, state, byte_order);
return;
}
static void
decode_x11_event(tvbuff_t *tvb, unsigned char eventcode, const char *sent,
proto_tree *t, x11_conv_data_t *volatile state,
guint byte_order)
{
int offset = 0, *offsetp = &offset, left;
proto_tree_add_uint_format(t, hf_x11_eventcode, tvb, offset, 1,
eventcode,
"eventcode: %d (%s%s)",
eventcode, sent,
val_to_str(eventcode & 0x7F, state->eventcode_vals,
"<Unknown eventcode %u>"));
++offset;
switch (eventcode & 0x7F) {
case KeyPress:
case KeyRelease: {
int code, mask;
code = VALUE8(tvb, offset);
mask = VALUE16(tvb, 28);
KEYCODE_DECODED(keycode, code, mask);
CARD16(event_sequencenumber);
EVENTCONTENTS_COMMON();
BOOL(same_screen);
UNUSED(1);
break;
}
case ButtonPress:
case ButtonRelease:
BUTTON(eventbutton);
CARD16(event_sequencenumber);
EVENTCONTENTS_COMMON();
BOOL(same_screen);
UNUSED(1);
break;
case MotionNotify:
CARD8(detail);
CARD16(event_sequencenumber);
EVENTCONTENTS_COMMON();
BOOL(same_screen);
UNUSED(1);
break;
case EnterNotify:
case LeaveNotify:
ENUM8(event_detail);
CARD16(event_sequencenumber);
EVENTCONTENTS_COMMON();
ENUM8(grab_mode);
same_screen_focus(tvb, offsetp, t);
break;
case FocusIn:
case FocusOut:
ENUM8(focus_detail);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
ENUM8(focus_mode);
UNUSED(23);
break;
case KeymapNotify:
break;
case Expose:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
INT16(x);
INT16(y);
CARD16(width);
CARD16(height);
CARD16(count);
UNUSED(14);
break;
case GraphicsExpose:
UNUSED(1);
CARD16(event_sequencenumber);
DRAWABLE(drawable);
CARD16(x);
CARD16(y);
CARD16(width);
CARD16(height);
CARD16(minor_opcode);
CARD16(count);
CARD8(major_opcode);
UNUSED(11);
break;
case NoExpose:
UNUSED(1);
CARD16(event_sequencenumber);
DRAWABLE(drawable);
CARD16(minor_opcode);
CARD8(major_opcode);
UNUSED(21);
break;
case VisibilityNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
ENUM8(visibility_state);
UNUSED(23);
break;
case CreateNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(parent);
WINDOW(eventwindow);
INT16(x);
INT16(y);
CARD16(width);
CARD16(height);
CARD16(border_width);
BOOL(override_redirect);
UNUSED(9);
break;
case DestroyNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
WINDOW(window);
UNUSED(20);
break;
case UnmapNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
WINDOW(window);
BOOL(from_configure);
UNUSED(19);
break;
case MapNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
WINDOW(window);
BOOL(override_redirect);
UNUSED(19);
break;
case MapRequest:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(parent);
WINDOW(eventwindow);
UNUSED(20);
break;
case ReparentNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
WINDOW(window);
WINDOW(parent);
INT16(x);
INT16(y);
BOOL(override_redirect);
UNUSED(11);
break;
case ConfigureNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
WINDOW(window);
WINDOW(above_sibling);
INT16(x);
INT16(y);
CARD16(width);
CARD16(height);
CARD16(border_width);
BOOL(override_redirect);
UNUSED(5);
break;
case ConfigureRequest:
break;
case GravityNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
WINDOW(window);
INT16(x);
INT16(y);
UNUSED(16);
break;
case ResizeRequest:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
CARD16(width);
CARD16(height);
UNUSED(20);
break;
case CirculateNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
WINDOW(window);
UNUSED(4);
ENUM8(place);
UNUSED(15);
break;
case CirculateRequest:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(parent);
WINDOW(eventwindow);
UNUSED(4);
ENUM8(place);
UNUSED(15);
break;
case PropertyNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
ATOM(atom);
TIMESTAMP(time);
ENUM8(property_state);
UNUSED(15);
break;
case SelectionClear:
UNUSED(1);
CARD16(event_sequencenumber);
TIMESTAMP(time);
WINDOW(owner);
ATOM(selection);
UNUSED(16);
break;
case SelectionRequest:
UNUSED(1);
CARD16(event_sequencenumber);
TIMESTAMP(time);
WINDOW(owner);
WINDOW(requestor);
ATOM(selection);
ATOM(target);
ATOM(property);
UNUSED(4);
break;
case SelectionNotify:
UNUSED(1);
CARD16(event_sequencenumber);
TIMESTAMP(time);
WINDOW(requestor);
ATOM(selection);
ATOM(target);
ATOM(property);
UNUSED(8);
break;
case ColormapNotify:
UNUSED(1);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
COLORMAP(cmap);
BOOL(new);
ENUM8(colormap_state);
UNUSED(18);
break;
case ClientMessage:
CARD8(format);
CARD16(event_sequencenumber);
WINDOW(eventwindow);
ATOM(type);
LISTofBYTE(data, 20);
break;
case MappingNotify:
UNUSED(1);
CARD16(event_sequencenumber);
ENUM8(mapping_request);
CARD8(first_keycode);
CARD8(count);
UNUSED(25);
break;
default:
tryExtensionEvent(eventcode & 0x7F, tvb, offsetp, t, state, byte_order);
break;
}
if ((left = tvb_reported_length_remaining(tvb, offset)) > 0)
UNDECODED(left);
return;
}
static void
dissect_x11_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
const char *volatile sep, x11_conv_data_t *volatile state _U_,
guint byte_order)
{
int offset = 0, *offsetp = &offset, left;
unsigned char errorcode;
proto_item *ti;
proto_tree *t;
ti = proto_tree_add_item(tree, proto_x11, tvb, 0, -1, ENC_NA);
t = proto_item_add_subtree(ti, ett_x11);
CARD8(error);
errorcode = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, "%s %s",
sep, val_to_str(errorcode, state->errorcode_vals, "<Unknown errorcode %u>"));
proto_tree_add_uint_format(t, hf_x11_errorcode, tvb, offset, 1,
errorcode,
"errorcode: %d (%s)",
errorcode,
val_to_str(errorcode, state->errorcode_vals,
"<Unknown errorcode %u>"));
++offset;
proto_item_append_text(ti, ", Error, errorcode: %d (%s)",
errorcode, val_to_str(errorcode, state->errorcode_vals,
"<Unknown errorcode %u>"));
if (tree == NULL)
return;
CARD16(error_sequencenumber);
switch (errorcode) {
case BadValue:
CARD32(error_badvalue);
break;
default:
UNDECODED(4);
}
CARD16(minor_opcode);
CARD8(major_opcode);
if ((left = tvb_reported_length_remaining(tvb, offset)) > 0)
UNDECODED(left);
}
static void
dissect_x11(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "X11");
if (pinfo->match_uint == pinfo->srcport)
dissect_x11_replies(tvb, pinfo, tree);
else
dissect_x11_requests(tvb, pinfo, tree);
}
void proto_register_x11(void)
{
static hf_register_info hf[] = {
#include "x11-register-info.h"
};
static gint *ett[] = {
&ett_x11,
&ett_x11_color_flags,
&ett_x11_list_of_arc,
&ett_x11_arc,
&ett_x11_list_of_atom,
&ett_x11_list_of_card32,
&ett_x11_list_of_float,
&ett_x11_list_of_double,
&ett_x11_list_of_color_item,
&ett_x11_color_item,
&ett_x11_list_of_keycode,
&ett_x11_list_of_keysyms,
&ett_x11_keysym,
&ett_x11_list_of_point,
&ett_x11_point,
&ett_x11_list_of_rectangle,
&ett_x11_rectangle,
&ett_x11_list_of_segment,
&ett_x11_segment,
&ett_x11_list_of_string8,
&ett_x11_list_of_text_item,
&ett_x11_text_item,
&ett_x11_gc_value_mask,
&ett_x11_event_mask,
&ett_x11_do_not_propagate_mask,
&ett_x11_set_of_key_mask,
&ett_x11_pointer_event_mask,
&ett_x11_window_value_mask,
&ett_x11_configure_window_mask,
&ett_x11_keyboard_value_mask,
&ett_x11_same_screen_focus,
&ett_x11_event,
};
module_t *x11_module;
proto_x11 = proto_register_protocol("X11", "X11", "x11");
proto_register_field_array(proto_x11, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(x11_init_protocol);
extension_table = g_hash_table_new(g_str_hash, g_str_equal);
error_table = g_hash_table_new(g_str_hash, g_str_equal);
event_table = g_hash_table_new(g_str_hash, g_str_equal);
reply_table = g_hash_table_new(g_str_hash, g_str_equal);
register_x11_extensions();
x11_module = prefs_register_protocol(proto_x11, NULL);
prefs_register_bool_preference(x11_module, "desegment",
"Reassemble X11 messages spanning multiple TCP segments",
"Whether the X11 dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&x11_desegment);
}
void
proto_reg_handoff_x11(void)
{
dissector_handle_t x11_handle;
x11_handle = create_dissector_handle(dissect_x11, proto_x11);
dissector_add_uint("tcp.port", TCP_PORT_X11, x11_handle);
dissector_add_uint("tcp.port", TCP_PORT_X11_2, x11_handle);
dissector_add_uint("tcp.port", TCP_PORT_X11_3, x11_handle);
}
