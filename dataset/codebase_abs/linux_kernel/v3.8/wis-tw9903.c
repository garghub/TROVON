static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_5 [ V_6 ] != 0x00 ; V_6 += 2 )
if ( F_2 ( V_2 , V_5 [ V_6 ] , V_5 [ V_6 + 1 ] ) < 0 )
return - 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_7 , void * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
switch ( V_7 ) {
case V_11 :
{
int * V_12 = V_8 ;
F_2 ( V_2 , 0x02 , 0x40 | ( * V_12 << 1 ) ) ;
break;
}
#if 0
case DECODER_SET_RESOLUTION:
{
struct video_decoder_resolution *res = arg;
int hscale = 256 * 720 / (res->width - (res->width > 704 ? 0 : 8));
int vscale = 256 * (dec->norm & V4L2_STD_NTSC ? 240 : 288)
/ res->height;
u8 regs[] = {
0x0d, vscale & 0xff,
0x0f, hscale & 0xff,
0x0e, ((vscale & 0xf00) >> 4) | ((hscale & 0xf00) >> 8),
0x06, 0xc0,
0, 0,
};
printk(KERN_DEBUG "vscale is %04x, hscale is %04x\n",
vscale, hscale);
break;
}
#endif
case V_13 :
{
T_2 * V_12 = V_8 ;
T_1 V_5 [] = {
0x05 , * V_12 & V_14 ? 0x80 : 0x00 ,
0x07 , * V_12 & V_14 ? 0x02 : 0x12 ,
0x08 , * V_12 & V_14 ? 0x14 : 0x18 ,
0x09 , * V_12 & V_14 ? 0xf0 : 0x20 ,
0 , 0 ,
} ;
F_3 ( V_2 , V_5 ) ;
V_10 -> V_15 = * V_12 ;
break;
}
case V_16 :
{
struct V_17 * V_18 = V_8 ;
switch ( V_18 -> V_19 ) {
case V_20 :
V_18 -> type = V_21 ;
strncpy ( V_18 -> V_22 , L_1 , sizeof( V_18 -> V_22 ) ) ;
V_18 -> V_23 = - 128 ;
V_18 -> V_24 = 127 ;
V_18 -> V_25 = 1 ;
V_18 -> V_26 = 0x00 ;
V_18 -> V_27 = 0 ;
break;
case V_28 :
V_18 -> type = V_21 ;
strncpy ( V_18 -> V_22 , L_2 , sizeof( V_18 -> V_22 ) ) ;
V_18 -> V_23 = 0 ;
V_18 -> V_24 = 255 ;
V_18 -> V_25 = 1 ;
V_18 -> V_26 = 0x60 ;
V_18 -> V_27 = 0 ;
break;
#if 0
case V4L2_CID_SATURATION:
ctrl->type = V4L2_CTRL_TYPE_INTEGER;
strncpy(ctrl->name, "Saturation", sizeof(ctrl->name));
ctrl->minimum = 0;
ctrl->maximum = 127;
ctrl->step = 1;
ctrl->default_value = 64;
ctrl->flags = 0;
break;
#endif
case V_29 :
V_18 -> type = V_21 ;
strncpy ( V_18 -> V_22 , L_3 , sizeof( V_18 -> V_22 ) ) ;
V_18 -> V_23 = - 128 ;
V_18 -> V_24 = 127 ;
V_18 -> V_25 = 1 ;
V_18 -> V_26 = 0 ;
V_18 -> V_27 = 0 ;
break;
}
break;
}
case V_30 :
{
struct V_31 * V_18 = V_8 ;
switch ( V_18 -> V_19 ) {
case V_20 :
if ( V_18 -> V_4 > 127 )
V_10 -> V_32 = 127 ;
else if ( V_18 -> V_4 < - 128 )
V_10 -> V_32 = - 128 ;
else
V_10 -> V_32 = V_18 -> V_4 ;
F_1 ( V_2 , 0x10 , V_10 -> V_32 ) ;
break;
case V_28 :
if ( V_18 -> V_4 > 255 )
V_10 -> V_33 = 255 ;
else if ( V_18 -> V_4 < 0 )
V_10 -> V_33 = 0 ;
else
V_10 -> V_33 = V_18 -> V_4 ;
F_1 ( V_2 , 0x11 , V_10 -> V_33 ) ;
break;
#if 0
case V4L2_CID_SATURATION:
if (ctrl->value > 127)
dec->saturation = 127;
else if (ctrl->value < 0)
dec->saturation = 0;
else
dec->saturation = ctrl->value;
break;
#endif
case V_29 :
if ( V_18 -> V_4 > 127 )
V_10 -> V_34 = 127 ;
else if ( V_18 -> V_4 < - 128 )
V_10 -> V_34 = - 128 ;
else
V_10 -> V_34 = V_18 -> V_4 ;
F_1 ( V_2 , 0x15 , V_10 -> V_34 ) ;
break;
}
break;
}
case V_35 :
{
struct V_31 * V_18 = V_8 ;
switch ( V_18 -> V_19 ) {
case V_20 :
V_18 -> V_4 = V_10 -> V_32 ;
break;
case V_28 :
V_18 -> V_4 = V_10 -> V_33 ;
break;
#if 0
case V4L2_CID_SATURATION:
ctrl->value = dec->saturation;
break;
#endif
case V_29 :
V_18 -> V_4 = V_10 -> V_34 ;
break;
}
break;
}
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_36 * V_19 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_9 * V_10 ;
if ( ! F_7 ( V_38 , V_39 ) )
return - V_40 ;
V_10 = F_8 ( sizeof( struct V_9 ) , V_41 ) ;
if ( V_10 == NULL )
return - V_42 ;
V_10 -> V_15 = V_14 ;
V_10 -> V_32 = 0 ;
V_10 -> V_33 = 0x60 ;
V_10 -> V_34 = 0 ;
F_9 ( V_2 , V_10 ) ;
F_10 ( V_43
L_4 ,
V_2 -> V_44 , V_38 -> V_22 ) ;
if ( F_3 ( V_2 , V_45 ) < 0 ) {
F_10 ( V_46 L_5 ) ;
F_11 ( V_10 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
F_11 ( V_10 ) ;
return 0 ;
}
