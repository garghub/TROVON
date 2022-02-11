static int
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
static const struct {
T_1 V_6 ;
T_1 V_7 ;
} V_8 [] = {
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
int V_9 ;
F_2 ( V_5 , 0x000200 , 0x08001000 , 0x00000000 ) ;
F_2 ( V_5 , 0x0206b4 , 0x00000000 , 0x00000000 ) ;
for ( V_9 = 0 ; V_9 < F_3 ( V_8 ) ; V_9 ++ ) {
F_4 ( V_5 , V_8 [ V_9 ] . V_6 , V_8 [ V_9 ] . V_7 ) ;
F_5 ( V_5 , V_8 [ V_9 ] . V_6 , 0x80000000 , 0x00000000 ) ;
}
return F_6 ( & V_5 -> V_10 , V_3 ) ;
}
