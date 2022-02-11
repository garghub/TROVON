static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_2 V_9 ;
* V_3 = 0 ;
V_9 = F_3 ( V_5 , V_7 , V_10 ) ;
if ( ! ( V_9 & V_11 ) ) {
F_4 ( V_5 , L_1 , V_9 ) ;
return - V_12 ;
}
V_9 = F_3 ( V_5 , V_7 , V_13 ) ;
* V_3 = F_3 ( V_5 , V_7 , V_14 ) ;
* V_3 <<= 32 ;
* V_3 |= V_9 ;
F_5 ( V_5 , V_7 , V_10 ,
V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_2 V_9 ;
* V_3 = 0 ;
V_9 = F_3 ( V_5 , V_7 , V_15 ) ;
if ( ! ( V_9 & V_11 ) ) {
F_4 ( V_5 , L_2 , V_9 ) ;
return - V_12 ;
}
V_9 = F_3 ( V_5 , V_7 , V_16 ) ;
* V_3 = F_3 ( V_5 , V_7 , V_17 ) ;
* V_3 <<= 32 ;
* V_3 |= V_9 ;
F_5 ( V_5 , V_7 , V_15 , V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_2 V_19 = 0 ;
V_19 = F_3 ( V_5 , V_7 , V_20 ) ;
* V_18 = F_3 ( V_5 , V_7 , V_21 ) ;
* V_18 <<= 32 ;
* V_18 |= V_19 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
enum V_22 type )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_2 V_23 , V_24 ;
switch ( type ) {
case V_25 :
V_24 = 0x6AA ;
V_23 = 0x3EEE ;
break;
case V_26 :
V_24 = 0x6BF ;
V_23 = 0x3EFF ;
break;
case V_27 :
V_24 = 0x7EA ;
V_23 = 0x3FFE ;
break;
case V_28 :
V_24 = 0x7EE ;
V_23 = 0x3FFE ;
break;
default:
F_4 ( V_5 , L_3 , type ) ;
return - V_12 ;
}
F_5 ( V_5 , V_7 , V_29 , V_24 ) ;
F_5 ( V_5 , V_7 , V_30 , V_23 ) ;
F_5 ( V_5 , V_7 , V_31 , 0x1 ) ;
F_5 ( V_5 , V_7 , V_10 ,
V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_3 V_32 )
{
T_4 V_33 = 0 , V_9 , V_34 = 0 , V_35 , V_36 , V_37 , V_38 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_2 V_39 = 0 , V_40 ;
int V_41 = 1 ;
if ( V_32 < 0 ) {
V_32 = - V_32 ;
V_41 = 0 ;
}
if ( V_32 > 1 ) {
T_4 V_42 = V_32 , V_43 = 1 ;
for ( V_9 = 7 ; V_9 > 0 ; V_9 -- ) {
V_35 = F_10 ( V_9 * 1000000000 , V_32 ) ;
V_35 -= 8 ;
V_35 >>= 4 ;
if ( V_35 < 1 )
V_35 = 1 ;
if ( V_35 > 0xFFFFFFE )
V_35 = 0xFFFFFFE ;
V_36 = V_35 * 16 + 8 ;
V_37 = V_32 * V_36 - V_9 * 1000000000 ;
V_38 = V_37 + 16 * V_32 ;
if ( V_37 < 0 )
V_37 = - V_37 ;
if ( V_38 < 0 )
V_38 = - V_38 ;
if ( V_37 * ( V_36 + 16 ) > V_38 * V_36 ) {
V_35 ++ ;
V_36 += 16 ;
V_37 = V_38 ;
}
if ( V_42 * V_36 > V_37 * V_43 ) {
V_42 = V_37 ;
V_33 = V_9 ;
V_34 = V_35 ;
V_43 = V_36 ;
}
}
} else if ( V_32 == 1 ) {
V_33 = 4 ;
V_34 = 0xee6b27f ;
} else {
V_33 = 0 ;
V_34 = 0xFFFFFFF ;
}
V_39 = ( V_34 << V_44 ) |
( ( ( int ) V_33 ) << V_45 ) |
( ( ( int ) V_41 ) << V_46 ) ;
F_5 ( V_5 , V_7 , V_47 , 0x1 ) ;
V_40 = F_3 ( V_5 , V_7 , V_47 ) ;
if ( V_40 & 1 ) {
F_5 ( V_5 , V_7 , V_48 ,
V_39 ) ;
} else {
F_4 ( V_5 , L_4 ) ;
return - V_12 ;
}
F_5 ( V_5 , V_7 , V_47 , 0x0 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_5 ( V_5 , V_7 , V_29 , 0x7FF ) ;
F_5 ( V_5 , V_7 , V_30 , 0x3FFF ) ;
F_5 ( V_5 , V_7 , V_49 , 0x7FF ) ;
F_5 ( V_5 , V_7 , V_50 , 0x3FFF ) ;
F_5 ( V_5 , V_7 , V_51 , 7 ) ;
F_5 ( V_5 , V_7 , V_52 , 7 ) ;
F_5 ( V_5 , V_7 , V_53 , 0x1 ) ;
F_5 ( V_5 , V_7 , V_54 , 2 ) ;
F_5 ( V_5 , V_7 , V_55 , 0 ) ;
F_5 ( V_5 , V_7 , V_56 , 0 ) ;
F_5 ( V_5 , V_7 , V_54 , 4 ) ;
F_5 ( V_5 , V_7 , V_48 , 0x0 ) ;
F_5 ( V_5 , V_7 , V_47 , 0x0 ) ;
F_5 ( V_5 , V_7 , V_10 ,
V_11 ) ;
F_5 ( V_5 , V_7 , V_15 , V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_5 ( V_5 , V_7 , V_49 , 0x6AA ) ;
F_5 ( V_5 , V_7 , V_50 , 0x3EEE ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_5 ( V_5 , V_7 , V_29 , 0x7FF ) ;
F_5 ( V_5 , V_7 , V_30 , 0x3FFF ) ;
F_5 ( V_5 , V_7 , V_49 , 0x7FF ) ;
F_5 ( V_5 , V_7 , V_50 , 0x3FFF ) ;
F_5 ( V_5 , V_7 , V_52 , 0x0 ) ;
F_5 ( V_5 , V_7 , V_51 , 0x0 ) ;
return 0 ;
}
