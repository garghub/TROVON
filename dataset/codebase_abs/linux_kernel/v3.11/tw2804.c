static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
return F_2 ( V_2 , V_3 | ( V_5 << 6 ) , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_6 , T_1 V_5 )
{
int V_7 ;
int V_8 ;
for ( V_8 = 0 ; V_6 [ V_8 ] != 0xff ; V_8 += 2 ) {
V_7 = F_2 ( V_2 ,
V_6 [ V_8 ] | ( V_5 << 6 ) , V_6 [ V_8 + 1 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
return F_5 ( V_2 , ( V_3 ) | ( V_5 << 6 ) ) ;
}
static inline struct V_9 * F_6 ( struct V_10 * V_11 )
{
return F_7 ( V_11 , struct V_9 , V_11 ) ;
}
static inline struct V_9 * F_8 ( struct V_12 * V_13 )
{
return F_7 ( V_13 -> V_14 , struct V_9 , V_15 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_9 * V_16 = F_6 ( V_11 ) ;
F_10 ( V_11 , L_1 ,
V_16 -> V_17 & V_18 ? L_2 : L_3 ) ;
F_10 ( V_11 , L_4 , V_16 -> V_5 ) ;
F_10 ( V_11 , L_5 , V_16 -> V_19 ) ;
return F_11 ( V_11 ) ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_9 * V_16 = F_8 ( V_13 ) ;
struct V_1 * V_2 = F_13 ( & V_16 -> V_11 ) ;
switch ( V_13 -> V_20 ) {
case V_21 :
V_13 -> V_22 = F_4 ( V_2 , V_23 , 0 ) ;
return 0 ;
case V_24 :
V_13 -> V_22 = F_4 ( V_2 , V_25 , 0 ) ;
return 0 ;
case V_26 :
V_13 -> V_22 = F_4 ( V_2 , V_27 , 0 ) ;
return 0 ;
case V_28 :
V_13 -> V_22 = F_4 ( V_2 , V_29 , 0 ) ;
return 0 ;
}
return 0 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_9 * V_16 = F_8 ( V_13 ) ;
struct V_1 * V_2 = F_13 ( & V_16 -> V_11 ) ;
int V_30 ;
int V_3 ;
switch ( V_13 -> V_20 ) {
case V_31 :
V_30 = V_32 ;
V_3 = F_4 ( V_2 , V_30 , V_16 -> V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_13 -> V_22 == 0 )
V_3 &= ~ ( 1 << 7 ) ;
else
V_3 |= 1 << 7 ;
return F_1 ( V_2 , V_30 , V_3 , V_16 -> V_5 ) ;
case V_33 :
V_30 = V_34 ;
V_3 = F_4 ( V_2 , V_30 , V_16 -> V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = ( V_3 & ~ ( 0x03 ) ) | ( V_13 -> V_22 == 0 ? 0x02 : 0x03 ) ;
return F_1 ( V_2 , V_30 , V_3 , V_16 -> V_5 ) ;
case V_21 :
return F_1 ( V_2 , V_23 , V_13 -> V_22 , 0 ) ;
case V_24 :
return F_1 ( V_2 , V_25 , V_13 -> V_22 , 0 ) ;
case V_26 :
return F_1 ( V_2 , V_27 , V_13 -> V_22 , 0 ) ;
case V_28 :
return F_1 ( V_2 , V_29 , V_13 -> V_22 , 0 ) ;
case V_35 :
return F_1 ( V_2 , V_36 ,
V_13 -> V_22 , V_16 -> V_5 ) ;
case V_37 :
return F_1 ( V_2 , V_38 ,
V_13 -> V_22 , V_16 -> V_5 ) ;
case V_39 :
return F_1 ( V_2 , V_40 ,
V_13 -> V_22 , V_16 -> V_5 ) ;
case V_41 :
return F_1 ( V_2 , V_42 ,
V_13 -> V_22 , V_16 -> V_5 ) ;
default:
break;
}
return - V_43 ;
}
static int F_15 ( struct V_10 * V_11 , T_2 V_17 )
{
struct V_9 * V_44 = F_6 ( V_11 ) ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
bool V_45 = V_17 & V_18 ;
T_1 V_6 [] = {
0x01 , V_45 ? 0xc4 : 0x84 ,
0x09 , V_45 ? 0x07 : 0x04 ,
0x0a , V_45 ? 0xf0 : 0x20 ,
0x0b , V_45 ? 0x07 : 0x04 ,
0x0c , V_45 ? 0xf0 : 0x20 ,
0x0d , V_45 ? 0x40 : 0x4a ,
0x16 , V_45 ? 0x00 : 0x40 ,
0x17 , V_45 ? 0x00 : 0x40 ,
0x20 , V_45 ? 0x07 : 0x0f ,
0x21 , V_45 ? 0x07 : 0x0f ,
0xff , 0xff ,
} ;
F_3 ( V_2 , V_6 , V_44 -> V_5 ) ;
V_44 -> V_17 = V_17 ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 , T_3 V_19 , T_3 V_46 ,
T_3 V_47 )
{
struct V_9 * V_44 = F_6 ( V_11 ) ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_3 ;
if ( V_47 && V_47 - 1 != V_44 -> V_5 ) {
if ( V_47 > 4 ) {
F_17 ( & V_2 -> V_48 ,
L_6 , V_47 ) ;
return - V_43 ;
}
V_44 -> V_5 = V_47 - 1 ;
F_18 ( & V_2 -> V_48 , L_7 ,
V_44 -> V_5 ) ;
if ( V_44 -> V_5 == 0 &&
F_3 ( V_2 , V_49 , 0 ) < 0 ) {
F_17 ( & V_2 -> V_48 ,
L_8 ) ;
return - V_50 ;
}
if ( F_3 ( V_2 , V_51 , V_44 -> V_5 ) < 0 ) {
F_17 ( & V_2 -> V_48 ,
L_9 ,
V_44 -> V_5 ) ;
return - V_50 ;
}
}
if ( V_19 > 1 )
return - V_43 ;
if ( V_19 == V_44 -> V_19 )
return 0 ;
V_3 = F_4 ( V_2 , 0x22 , V_44 -> V_5 ) ;
if ( V_3 >= 0 ) {
if ( V_19 == 0 )
V_3 &= ~ ( 1 << 2 ) ;
else
V_3 |= 1 << 2 ;
V_3 = F_1 ( V_2 , 0x22 , V_3 , V_44 -> V_5 ) ;
}
if ( V_3 >= 0 )
V_44 -> V_19 = V_19 ;
else
return V_3 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_52 * V_20 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_9 * V_16 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
int V_55 ;
if ( ! F_20 ( V_54 , V_56 ) )
return - V_57 ;
V_16 = F_21 ( & V_2 -> V_48 , sizeof( * V_16 ) , V_58 ) ;
if ( V_16 == NULL )
return - V_59 ;
V_11 = & V_16 -> V_11 ;
F_22 ( V_11 , V_2 , & V_60 ) ;
V_16 -> V_5 = - 1 ;
V_16 -> V_17 = V_61 ;
F_23 ( & V_16 -> V_15 , 10 ) ;
F_24 ( & V_16 -> V_15 , & V_62 ,
V_35 , 0 , 255 , 1 , 128 ) ;
F_24 ( & V_16 -> V_15 , & V_62 ,
V_37 , 0 , 255 , 1 , 128 ) ;
F_24 ( & V_16 -> V_15 , & V_62 ,
V_39 , 0 , 255 , 1 , 128 ) ;
F_24 ( & V_16 -> V_15 , & V_62 ,
V_41 , 0 , 255 , 1 , 128 ) ;
F_24 ( & V_16 -> V_15 , & V_62 ,
V_33 , 0 , 1 , 1 , 0 ) ;
F_24 ( & V_16 -> V_15 , & V_62 ,
V_31 , 0 , 1 , 1 , 0 ) ;
V_13 = F_24 ( & V_16 -> V_15 , & V_62 ,
V_21 , 0 , 255 , 1 , 128 ) ;
if ( V_13 )
V_13 -> V_63 |= V_64 ;
V_13 = F_24 ( & V_16 -> V_15 , & V_62 ,
V_24 , 0 , 255 , 1 , 128 ) ;
if ( V_13 )
V_13 -> V_63 |= V_64 ;
V_13 = F_24 ( & V_16 -> V_15 , & V_62 ,
V_26 , 0 , 255 , 1 , 122 ) ;
if ( V_13 )
V_13 -> V_63 |= V_64 ;
V_13 = F_24 ( & V_16 -> V_15 , & V_62 ,
V_28 , 0 , 255 , 1 , 122 ) ;
if ( V_13 )
V_13 -> V_63 |= V_64 ;
V_11 -> V_65 = & V_16 -> V_15 ;
V_55 = V_16 -> V_15 . error ;
if ( V_55 ) {
F_25 ( & V_16 -> V_15 ) ;
return V_55 ;
}
F_26 ( V_2 , L_10 ,
V_2 -> V_30 << 1 , V_2 -> V_54 -> V_66 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_28 ( V_2 ) ;
struct V_9 * V_16 = F_6 ( V_11 ) ;
F_29 ( V_11 ) ;
F_25 ( & V_16 -> V_15 ) ;
return 0 ;
}
