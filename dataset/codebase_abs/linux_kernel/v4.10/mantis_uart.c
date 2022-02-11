static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 , V_7 = 0 , V_8 = 0 ;
F_2 ( V_9 , 1 , L_1 ) ;
for ( V_6 = 0 ; V_6 < ( V_4 -> V_10 + 1 ) ; V_6 ++ ) {
int V_11 = F_3 ( V_12 ) ;
F_2 ( V_9 , 0 , L_2 , V_11 ) ;
V_7 = ( V_7 << 8 ) | ( V_11 & 0x3f ) ;
V_8 |= V_11 ;
if ( V_11 & ( 1 << 7 ) )
F_2 ( V_13 , 1 , L_3 ) ;
if ( V_11 & ( 1 << 6 ) )
F_2 ( V_13 , 1 , L_4 ) ;
}
F_2 ( V_9 , 0 , L_5 ) ;
if ( ( V_8 & 0xC0 ) == 0 )
F_4 ( V_2 , V_7 ) ;
}
static void F_5 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 , struct V_1 , V_16 ) ;
T_1 V_17 ;
V_17 = F_3 ( V_18 ) ;
if ( V_17 & V_19 )
F_2 ( V_13 , 1 , L_6 ) ;
while ( V_17 & V_20 ) {
F_1 ( V_2 ) ;
V_17 = F_3 ( V_18 ) ;
}
F_7 ( V_2 , V_21 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
T_1 V_24 ;
F_9 ( ( F_3 ( V_25 ) | ( V_23 -> V_26 & 0x3 ) ) , V_25 ) ;
V_24 = F_3 ( V_27 ) ;
switch ( V_23 -> V_28 ) {
case V_29 :
V_24 |= 0xd8 ;
break;
case V_30 :
V_24 |= 0x6c ;
break;
case V_31 :
V_24 |= 0x36 ;
break;
case V_32 :
V_24 |= 0x23 ;
break;
case V_33 :
V_24 |= 0x11 ;
break;
default:
return - V_34 ;
}
F_9 ( V_24 , V_27 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_22 V_23 ;
V_23 . V_28 = V_4 -> V_28 ;
V_23 . V_26 = V_4 -> V_26 ;
F_2 ( V_35 , 1 , L_7 ,
V_36 [ V_23 . V_28 ] . string ,
V_26 [ V_23 . V_26 ] . string ) ;
F_11 ( & V_2 -> V_16 , F_5 ) ;
F_9 ( F_3 ( V_25 ) & 0xffef , V_25 ) ;
F_8 ( V_2 , & V_23 ) ;
F_9 ( ( F_3 ( V_27 ) | ( V_4 -> V_10 << 8 ) ) , V_27 ) ;
F_9 ( ( F_3 ( V_25 ) | V_37 ) , V_25 ) ;
F_9 ( F_3 ( V_25 ) | V_38 , V_25 ) ;
F_7 ( V_2 , V_21 ) ;
F_12 ( & V_2 -> V_16 ) ;
F_2 ( V_9 , 1 , L_8 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_21 ) ;
F_9 ( F_3 ( V_25 ) & 0xffef , V_25 ) ;
F_15 ( & V_2 -> V_16 ) ;
}
