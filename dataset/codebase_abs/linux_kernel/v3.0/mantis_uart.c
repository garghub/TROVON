int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 = 0 , V_8 ;
for ( V_8 = 0 ; V_8 < ( V_5 -> V_9 + 1 ) ; V_8 ++ ) {
V_7 = F_2 ( V_10 ) ;
if ( V_7 & V_11 ) {
F_3 ( V_12 , 1 , L_1 ) ;
}
V_3 [ V_8 ] = F_2 ( V_13 ) & 0x3f ;
F_3 ( V_14 , 1 , L_2 , V_3 [ V_8 ] & 0x3f ) ;
if ( V_3 [ V_8 ] & ( 1 << 7 ) ) {
F_3 ( V_12 , 1 , L_3 ) ;
return - V_15 ;
}
if ( V_3 [ V_8 ] & ( 1 << 6 ) ) {
F_3 ( V_12 , 1 , L_4 ) ;
return - V_15 ;
}
}
return 0 ;
}
static void F_4 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 , struct V_1 , V_18 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_19 [ 16 ] ;
int V_8 ;
F_1 ( V_2 , V_19 ) ;
for ( V_8 = 0 ; V_8 < ( V_5 -> V_9 + 1 ) ; V_8 ++ )
F_3 ( V_20 , 1 , L_5 , V_8 , V_19 [ V_8 ] ) ;
F_3 ( V_14 , 0 , L_6 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
T_2 V_23 ;
F_7 ( ( F_2 ( V_24 ) | ( V_22 -> V_25 & 0x3 ) ) , V_24 ) ;
V_23 = F_2 ( V_26 ) ;
switch ( V_22 -> V_27 ) {
case V_28 :
V_23 |= 0xd8 ;
break;
case V_29 :
V_23 |= 0x6c ;
break;
case V_30 :
V_23 |= 0x36 ;
break;
case V_31 :
V_23 |= 0x23 ;
break;
case V_32 :
V_23 |= 0x11 ;
break;
default:
return - V_15 ;
}
F_7 ( V_23 , V_26 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_21 V_22 ;
V_22 . V_27 = V_5 -> V_27 ;
V_22 . V_25 = V_5 -> V_25 ;
F_3 ( V_20 , 1 , L_7 ,
V_33 [ V_22 . V_27 ] . string ,
V_25 [ V_22 . V_25 ] . string ) ;
F_9 ( & V_2 -> V_34 ) ;
F_10 ( & V_2 -> V_35 ) ;
F_11 ( & V_2 -> V_18 , F_4 ) ;
F_7 ( F_2 ( V_24 ) & 0xffef , V_24 ) ;
F_6 ( V_2 , & V_22 ) ;
F_7 ( ( F_2 ( V_26 ) | ( V_5 -> V_9 << 8 ) ) , V_26 ) ;
F_7 ( ( F_2 ( V_24 ) | V_36 ) , V_24 ) ;
F_7 ( F_2 ( V_37 ) | 0x800 , V_37 ) ;
F_7 ( F_2 ( V_24 ) | V_38 , V_24 ) ;
F_12 ( & V_2 -> V_18 ) ;
F_3 ( V_14 , 1 , L_8 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_7 ( F_2 ( V_24 ) & 0xffef , V_24 ) ;
F_14 ( & V_2 -> V_18 ) ;
}
