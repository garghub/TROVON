static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , int V_4 , int V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
unsigned char V_8 [ 2 ] ;
F_5 ( 2 , V_9 , V_3 , L_1 ) ;
F_5 ( 1 , V_9 , V_3 , L_2 , V_4 , V_5 ) ;
V_8 [ 0 ] = V_4 ;
V_8 [ 1 ] = V_5 ;
if ( 2 != F_6 ( V_7 , V_8 , 2 ) ) {
F_7 ( V_3 , L_3 ,
V_4 , V_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
unsigned char V_11 [ 16 ] ;
F_5 ( 1 , V_9 , V_3 ,
L_4 ,
V_10 -> V_12 , V_10 -> V_13 , V_10 -> V_14 , V_10 -> V_15 , V_10 -> V_16 , V_10 -> V_17 ,
V_10 -> V_18 , V_10 -> V_19 , V_10 -> V_20 ) ;
V_11 [ 0 ] = V_21 ;
V_11 [ 1 ] = V_10 -> V_12 ;
V_11 [ 2 ] = V_10 -> V_13 ;
V_11 [ 3 ] = V_10 -> V_14 ;
V_11 [ 4 ] = V_10 -> V_15 ;
V_11 [ 5 ] = V_10 -> V_16 ;
V_11 [ 6 ] = V_10 -> V_17 ;
V_11 [ 7 ] = V_10 -> V_18 ;
V_11 [ 8 ] = V_10 -> V_19 ;
V_11 [ 9 ] = V_10 -> V_20 ;
if ( 10 != F_6 ( V_7 , V_11 , 10 ) ) {
F_7 ( V_3 , L_5 ) ;
return - 1 ;
}
return 0 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_5 ( 2 , V_9 , V_3 , L_6 ) ;
V_10 -> V_12 = V_22 |
V_23 |
V_24 ;
V_10 -> V_13 = 0x3b ;
if ( V_25 )
V_10 -> V_13 |= V_26 ;
V_10 -> V_27 = 1 ;
V_10 -> V_15 = V_28 ;
V_10 -> V_14 = V_29 ;
V_10 -> V_16 = V_30 ;
V_10 -> V_17 = V_30 ;
V_10 -> V_18 = V_30 ;
V_10 -> V_19 = V_30 ;
V_10 -> V_20 = V_25 ;
F_8 ( V_3 ) ;
}
static int F_10 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
switch ( V_32 -> V_33 ) {
case V_34 :
V_32 -> V_35 = V_10 -> V_27 ;
return 0 ;
case V_36 :
if ( ! V_37 ) {
V_32 -> V_35 = ( 0x6f - ( V_10 -> V_13 & 0x7F ) ) * 630 ;
} else {
V_32 -> V_35 = ( 0x6f - ( V_10 -> V_13 & 0x7F ) ) * 829 ;
}
return 0 ;
case V_38 :
{
if ( ( V_10 -> V_16 ) < ( V_10 -> V_18 ) )
V_32 -> V_35 = ( 32768 - 1057 * ( V_10 -> V_18 ) ) ;
else
V_32 -> V_35 = ( 32768 + 1057 * ( V_10 -> V_16 ) ) ;
return 0 ;
}
case V_39 :
{
int V_14 = V_10 -> V_14 ;
if( V_14 >= 0x8 )
V_14 = ~ ( V_14 - 0x8 ) & 0xf ;
V_32 -> V_35 = ( V_14 << 12 ) + ( V_14 << 8 ) + ( V_14 << 4 ) + ( V_14 ) ;
return 0 ;
}
case V_40 :
{
int V_15 = V_10 -> V_15 ;
if( V_15 >= 0x8 )
V_15 = ~ ( V_15 - 0x8 ) & 0xf ;
V_32 -> V_35 = ( V_15 << 12 ) + ( V_15 << 8 ) + ( V_15 << 4 ) + ( V_15 ) ;
return 0 ;
}
}
return - V_41 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_31 * V_32 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
switch ( V_32 -> V_33 ) {
case V_34 :
V_10 -> V_27 = V_32 -> V_35 ;
break;
case V_36 :
if( ! V_37 ) {
V_10 -> V_13 = 0x6f - ( ( V_32 -> V_35 ) / 630 ) ;
} else {
V_10 -> V_13 = 0x6f - ( ( V_32 -> V_35 ) / 829 ) ;
}
if ( V_25 )
V_10 -> V_13 |= V_26 ;
F_3 ( V_3 , V_42 , V_10 -> V_13 ) ;
return 0 ;
case V_38 :
if ( V_32 -> V_35 < 32768 ) {
V_10 -> V_19 = ( 32768 - V_32 -> V_35 ) / 1057 ;
V_10 -> V_18 = V_10 -> V_19 ;
V_10 -> V_17 = V_30 ;
V_10 -> V_16 = V_30 ;
} else if( V_32 -> V_35 > 32769 ) {
V_10 -> V_16 = ( V_32 -> V_35 - 32768 ) / 1057 ;
V_10 -> V_17 = V_10 -> V_16 ;
V_10 -> V_19 = V_30 ;
V_10 -> V_18 = V_30 ;
} else {
V_10 -> V_19 = V_30 ;
V_10 -> V_18 = V_30 ;
V_10 -> V_16 = V_30 ;
V_10 -> V_17 = V_30 ;
}
break;
case V_39 :
V_10 -> V_14 = V_32 -> V_35 >> 12 ;
if( V_10 -> V_14 >= 0x8 )
V_10 -> V_14 = ( ~ V_10 -> V_14 & 0xf ) + 0x8 ;
F_3 ( V_3 , V_43 , 0x10 | ( V_10 -> V_14 << 4 ) | V_10 -> V_15 ) ;
return 0 ;
case V_40 :
V_10 -> V_15 = V_32 -> V_35 >> 12 ;
if( V_10 -> V_15 >= 0x8 )
V_10 -> V_15 = ( ~ V_10 -> V_15 & 0xf ) + 0x8 ;
F_3 ( V_3 , V_43 , 0x10 | ( V_10 -> V_14 << 4 ) | V_10 -> V_15 ) ;
return 0 ;
default:
return - V_41 ;
}
if ( V_10 -> V_27 )
{
F_3 ( V_3 , V_44 , V_10 -> V_16 | V_45 ) ;
F_3 ( V_3 , V_46 , V_10 -> V_17 | V_45 ) ;
F_3 ( V_3 , V_47 , V_10 -> V_18 | V_45 ) ;
F_3 ( V_3 , V_48 , V_10 -> V_19 | V_45 ) ;
} else {
F_3 ( V_3 , V_44 , V_10 -> V_16 ) ;
F_3 ( V_3 , V_46 , V_10 -> V_17 ) ;
F_3 ( V_3 , V_47 , V_10 -> V_18 ) ;
F_3 ( V_3 , V_48 , V_10 -> V_19 ) ;
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_49 * V_50 )
{
switch ( V_50 -> V_33 ) {
case V_36 :
return F_13 ( V_50 , 0 , 65535 , 65535 / 100 , 58880 ) ;
case V_34 :
return F_13 ( V_50 , 0 , 1 , 1 , 0 ) ;
case V_38 :
case V_39 :
case V_40 :
return F_13 ( V_50 , 0 , 65535 , 65535 / 100 , 32768 ) ;
}
return - V_41 ;
}
static int F_14 ( struct V_6 * V_7 ,
const struct V_51 * V_33 )
{
struct V_1 * V_10 ;
struct V_2 * V_3 ;
F_15 ( V_7 , L_7 ,
V_7 -> V_52 << 1 , V_7 -> V_53 -> V_54 ) ;
V_10 = F_16 ( sizeof( * V_10 ) , V_55 ) ;
if ( ! V_10 )
return - V_56 ;
V_3 = & V_10 -> V_3 ;
F_17 ( V_3 , V_7 , & V_57 ) ;
if ( V_25 < 0 || V_25 > 15 ) {
F_18 ( V_3 , L_8 ) ;
if ( V_25 < 0 )
V_25 = 0 ;
if ( V_25 > 15 )
V_25 = 15 ;
}
F_9 ( V_3 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_20 ( V_7 ) ;
F_9 ( V_3 ) ;
F_21 ( V_3 ) ;
F_22 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_1 int F_23 ( void )
{
return F_24 ( & V_58 ) ;
}
static T_2 void F_25 ( void )
{
F_26 ( & V_58 ) ;
}
