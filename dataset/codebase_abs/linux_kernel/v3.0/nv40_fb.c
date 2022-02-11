void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_8 . V_9 [ V_3 ] ;
switch ( V_5 -> V_10 ) {
case 0x40 :
F_2 ( V_2 , F_3 ( V_3 ) , V_8 -> V_11 ) ;
F_2 ( V_2 , F_4 ( V_3 ) , V_8 -> V_12 ) ;
F_2 ( V_2 , F_5 ( V_3 ) , V_8 -> V_13 ) ;
break;
default:
F_2 ( V_2 , F_6 ( V_3 ) , V_8 -> V_11 ) ;
F_2 ( V_2 , F_7 ( V_3 ) , V_8 -> V_12 ) ;
F_2 ( V_2 , F_8 ( V_3 ) , V_8 -> V_13 ) ;
break;
}
}
static void
F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_16 . V_17 ;
if ( V_5 -> V_16 . type != V_18 ) {
F_2 ( V_2 , 0x100800 , 0x00000001 ) ;
return;
}
F_2 ( V_2 , 0x100800 , V_15 -> V_19 | 0x00000002 ) ;
F_10 ( V_2 , 0x10008c , 0x00000100 , 0x00000100 ) ;
F_2 ( V_2 , 0x100820 , 0x00000000 ) ;
}
static void
F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_15 = V_5 -> V_16 . V_17 ;
T_1 V_20 ;
if ( V_5 -> V_16 . type != V_18 ) {
F_2 ( V_2 , 0x100850 , 0x80000000 ) ;
F_2 ( V_2 , 0x100800 , 0x00000001 ) ;
return;
}
V_20 = F_12 ( V_2 , 0x10020c ) ;
V_20 -= ( ( V_15 -> V_19 >> 19 ) + 1 ) << 19 ;
F_2 ( V_2 , 0x100850 , 0x80000000 ) ;
F_2 ( V_2 , 0x100818 , V_5 -> V_16 . V_21 . V_13 ) ;
F_2 ( V_2 , 0x100804 , V_5 -> V_16 . V_22 ) ;
F_2 ( V_2 , 0x100850 , 0x00008000 ) ;
F_10 ( V_2 , 0x10008c , 0x00000200 , 0x00000200 ) ;
F_2 ( V_2 , 0x100820 , 0x00000000 ) ;
F_2 ( V_2 , 0x10082c , 0x00000001 ) ;
F_2 ( V_2 , 0x100800 , V_20 | 0x00000010 ) ;
}
int
F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_23 * V_24 = & V_5 -> V_25 . V_26 ;
T_2 V_27 ;
int V_3 ;
if ( V_5 -> V_10 != 0x40 && V_5 -> V_10 != 0x45 ) {
if ( F_14 ( V_2 ) )
F_11 ( V_2 ) ;
else
F_9 ( V_2 ) ;
}
switch ( V_5 -> V_10 ) {
case 0x40 :
case 0x45 :
V_27 = F_12 ( V_2 , V_28 ) ;
F_2 ( V_2 , V_28 , V_27 & ~ ( 1 << 15 ) ) ;
V_24 -> V_29 = V_30 ;
break;
case 0x46 :
case 0x47 :
case 0x49 :
case 0x4b :
case 0x4c :
V_24 -> V_29 = V_31 ;
break;
default:
V_24 -> V_29 = V_32 ;
break;
}
for ( V_3 = 0 ; V_3 < V_24 -> V_29 ; V_3 ++ )
V_24 -> V_33 ( V_2 , V_3 ) ;
return 0 ;
}
void
F_15 ( struct V_1 * V_2 )
{
}
