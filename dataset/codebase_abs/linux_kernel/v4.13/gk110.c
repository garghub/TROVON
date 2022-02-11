void
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
static const struct {
T_1 V_7 ;
T_1 V_8 ;
} V_9 [] = {
{ 0x020520 , 0xfffffffc } ,
{ 0x020524 , 0xfffffffe } ,
{ 0x020524 , 0xfffffffc } ,
{ 0x020524 , 0xfffffff8 } ,
{ 0x020524 , 0xffffffe0 } ,
{ 0x020530 , 0xfffffffe } ,
{ 0x02052c , 0xfffffffa } ,
{ 0x02052c , 0xfffffff0 } ,
{ 0x02052c , 0xffffffc0 } ,
{ 0x02052c , 0xffffff00 } ,
{ 0x02052c , 0xfffffc00 } ,
{ 0x02052c , 0xfffcfc00 } ,
{ 0x02052c , 0xfff0fc00 } ,
{ 0x02052c , 0xff80fc00 } ,
{ 0x020528 , 0xfffffffe } ,
{ 0x020528 , 0xfffffffc } ,
} ;
int V_10 ;
F_2 ( V_5 , 0x000200 , 0x00001000 , 0x00000000 ) ;
F_3 ( V_5 , 0x000200 ) ;
F_2 ( V_5 , 0x000200 , 0x08000000 , 0x08000000 ) ;
F_4 ( 50 ) ;
F_2 ( V_5 , 0x10a78c , 0x00000002 , 0x00000002 ) ;
F_2 ( V_5 , 0x10a78c , 0x00000001 , 0x00000001 ) ;
F_2 ( V_5 , 0x10a78c , 0x00000001 , 0x00000000 ) ;
F_2 ( V_5 , 0x0206b4 , 0x00000000 , 0x00000000 ) ;
for ( V_10 = 0 ; V_10 < F_5 ( V_9 ) ; V_10 ++ ) {
F_6 ( V_5 , V_9 [ V_10 ] . V_7 , V_9 [ V_10 ] . V_8 ) ;
F_7 (device, 2000 ,
if (!(nvkm_rd32(device, magic[i].addr) & 0x80000000))
break;
) ;
}
F_2 ( V_5 , 0x10a78c , 0x00000002 , 0x00000000 ) ;
F_2 ( V_5 , 0x10a78c , 0x00000001 , 0x00000001 ) ;
F_2 ( V_5 , 0x10a78c , 0x00000001 , 0x00000000 ) ;
F_2 ( V_5 , 0x000200 , 0x08000000 , 0x00000000 ) ;
F_2 ( V_5 , 0x000200 , 0x00001000 , 0x00001000 ) ;
F_3 ( V_5 , 0x000200 ) ;
}
int
F_8 ( struct V_4 * V_5 , int V_11 , struct V_1 * * V_12 )
{
return F_9 ( & V_13 , V_5 , V_11 , V_12 ) ;
}
