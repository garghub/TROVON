static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( F_4 ( V_2 , V_3 ) ) | 0x80 , F_4 ( V_2 , V_3 ) ) ;
F_5 ( 5 ) ;
F_2 ( F_3 ( F_4 ( V_2 , V_3 ) ) & ~ 0x80 , F_4 ( V_2 , V_3 ) ) ;
}
static void F_6 ( struct V_4 * V_5 , unsigned int V_6 )
{
unsigned char V_7 , V_8 , V_9 ;
int V_10 , V_11 ;
if ( V_6 == 0 )
return;
if ( V_6 > 96000 )
V_9 = 2 ;
else if ( V_6 > 48000 )
V_9 = 1 ;
else
V_9 = 0 ;
if ( V_5 -> type == V_12 || V_5 -> type == V_13 ) {
V_10 = 2 ;
V_11 = 4 ;
} else {
V_10 = 1 ;
V_11 = 3 ;
}
V_8 = F_7 ( V_5 , 0 , V_10 ) ;
V_7 = ( V_8 >> V_11 ) & 0x03 ;
if ( V_7 == V_9 )
return;
F_8 ( V_5 , 1 ) ;
V_8 = F_7 ( V_5 , 0 , V_10 ) ;
V_8 &= ~ ( 0x03 << V_11 ) ;
V_8 |= V_9 << V_11 ;
F_9 ( V_5 , 0 , V_10 , V_8 ) ;
F_8 ( V_5 , 0 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_14 * V_15 , int clock , int V_17 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned int V_18 , V_19 ;
V_19 = 0 ;
if ( clock )
V_19 |= V_20 ;
if ( V_17 )
V_19 |= V_21 ;
V_18 = V_20 | V_21 ;
V_2 -> V_22 . V_23 &= ~ V_18 ;
V_2 -> V_22 . V_23 |= V_19 ;
F_15 ( V_2 , V_2 -> V_22 . V_23 ) ;
F_16 ( V_2 , ~ V_18 ) ;
}
static void F_17 ( struct V_14 * V_15 , int V_24 , int V_17 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned int V_19 = 0 ;
if ( V_24 )
V_19 |= V_20 ;
if ( V_17 )
V_19 |= V_21 ;
F_18 ( V_2 ,
V_21 |
V_20 , V_19 ) ;
F_19 ( 5 ) ;
}
static int F_20 ( struct V_14 * V_15 , int V_25 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_26 ;
if ( V_25 )
F_19 ( 5 ) ;
V_26 = F_21 ( V_2 , V_21 ) ? 1 : 0 ;
return V_26 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 ;
int V_31 ;
V_30 = F_23 ( sizeof( * V_30 ) , V_32 ) ;
if ( ! V_30 )
return - V_33 ;
V_2 -> V_30 = V_30 ;
V_31 = F_24 ( V_2 -> V_34 , L_1 , NULL , & V_2 -> V_35 ) ;
if ( V_31 < 0 )
return V_31 ;
V_2 -> V_35 -> V_16 = V_2 ;
V_2 -> V_35 -> V_36 . V_26 = & V_37 ;
V_31 = F_25 ( V_2 -> V_35 , L_2 , 0x40 , & V_30 -> V_38 ) ;
if ( V_31 < 0 )
return V_31 ;
V_28 -> V_34 = V_2 -> V_34 ;
V_28 -> V_39 = V_2 -> V_35 ;
V_28 -> V_40 = V_30 -> V_38 ;
V_30 -> V_41 = V_28 ;
F_26 ( V_28 ) ;
return 0 ;
}
static void F_27 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_1 * V_2 = V_5 -> V_16 [ 0 ] ;
int V_9 ;
F_6 ( V_5 , V_6 ) ;
F_18 ( V_2 , 1 << 8 , V_6 > 96000 ? 1 << 8 : 0 ) ;
if ( V_6 > 96000 )
V_9 = 2 ;
else if ( V_6 > 48000 )
V_9 = 1 ;
else
V_9 = 0 ;
F_18 ( V_2 , 3 << 9 , V_9 << 9 ) ;
F_18 ( V_2 , 1 << 11 , 0 ) ;
F_18 ( V_2 , 1 << 11 , 1 << 11 ) ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_22 ,
unsigned int V_17 , int V_42 )
{
for (; V_42 >= 0 ; V_42 -- ) {
V_22 &= ~ V_43 ;
F_29 ( V_2 , V_22 ) ;
F_19 ( 1 ) ;
if ( V_17 & ( 1 << V_42 ) )
V_22 |= V_44 ;
else
V_22 &= ~ V_44 ;
F_29 ( V_2 , V_22 ) ;
F_19 ( 1 ) ;
V_22 |= V_43 ;
F_29 ( V_2 , V_22 ) ;
F_19 ( 1 ) ;
}
}
static unsigned char F_30 ( struct V_1 * V_2 , unsigned int V_22 ,
int V_42 )
{
unsigned char V_17 = 0 ;
for (; V_42 >= 0 ; V_42 -- ) {
V_22 &= ~ V_43 ;
F_29 ( V_2 , V_22 ) ;
F_19 ( 1 ) ;
if ( F_31 ( V_2 ) & V_45 )
V_17 |= ( 1 << V_42 ) ;
F_19 ( 1 ) ;
V_22 |= V_43 ;
F_29 ( V_2 , V_22 ) ;
F_19 ( 1 ) ;
}
return V_17 ;
}
static unsigned int F_32 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
F_11 ( V_2 ) ;
V_8 = F_31 ( V_2 ) ;
V_8 |= V_43 ;
V_8 |= V_46 ;
V_8 &= ~ V_47 ;
F_29 ( V_2 , V_8 ) ;
F_19 ( 1 ) ;
return V_8 ;
}
static void F_33 ( struct V_1 * V_2 , unsigned int V_8 )
{
V_8 |= V_47 ;
V_8 |= V_46 ;
F_29 ( V_2 , V_8 ) ;
F_19 ( 1 ) ;
F_13 ( V_2 ) ;
}
static void F_34 ( void * V_16 , unsigned char V_48 ,
unsigned char V_17 )
{
struct V_1 * V_2 = V_16 ;
unsigned int V_8 , V_49 ;
V_8 = F_32 ( V_2 ) ;
V_49 = ( V_50 << 6 ) | 0x20 | ( V_48 & 0x1f ) ;
V_49 = ( V_49 << 8 ) | V_17 ;
F_28 ( V_2 , V_8 , V_49 , 15 ) ;
F_33 ( V_2 , V_8 ) ;
}
static unsigned char F_35 ( void * V_16 , unsigned char V_48 )
{
struct V_1 * V_2 = V_16 ;
unsigned int V_8 ;
unsigned char V_17 ;
V_8 = F_32 ( V_2 ) ;
F_28 ( V_2 , V_8 , ( V_50 << 6 ) | ( V_48 & 0x1f ) , 7 ) ;
V_17 = F_30 ( V_2 , V_8 , 7 ) ;
F_33 ( V_2 , V_8 ) ;
return V_17 ;
}
static int F_36 ( struct V_1 * V_2 )
{
static const unsigned char V_51 [] = {
V_52 | V_53 | V_54 | V_55 ,
V_56 ,
V_57 ,
V_58 | V_59 | F_37 ( 1 ) ,
0 ,
0
} ;
static const unsigned char V_60 [] = {
0x41 , 0x02 , 0x2c , 0x00 , 0x00
} ;
struct V_61 * V_5 ;
int V_31 ;
V_31 = F_38 ( V_2 -> V_34 ,
F_35 ,
F_34 ,
V_51 , V_60 ,
V_2 , & V_5 ) ;
V_5 -> V_62 = V_63 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_31 ;
switch ( V_2 -> V_64 . V_65 ) {
case V_66 :
V_2 -> V_67 = 8 ;
V_2 -> V_68 = 2 ;
V_2 -> V_22 . V_69 = F_1 ;
break;
case V_70 :
V_2 -> V_67 = 8 ;
V_2 -> V_68 = 2 ;
break;
case V_71 :
V_2 -> V_67 = 2 ;
V_2 -> V_68 = 2 ;
break;
default:
F_40 () ;
return - V_72 ;
}
V_5 = V_2 -> V_73 = F_41 ( 2 , sizeof( struct V_4 ) , V_32 ) ;
if ( ! V_5 )
return - V_33 ;
switch ( V_2 -> V_64 . V_65 ) {
case V_66 :
V_2 -> V_74 = 2 ;
V_31 = F_42 ( V_5 , & V_75 ,
& V_76 , V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_42 ( V_5 + 1 , & V_77 ,
& V_78 , V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
F_18 ( V_2 , V_79 ,
V_79 ) ;
break;
case V_70 :
V_2 -> V_74 = 2 ;
V_31 = F_42 ( V_5 , & V_80 ,
& V_81 , V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_42 ( V_5 + 1 , & V_82 ,
& V_83 , V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_22 ( V_2 , & V_84 ) ;
if ( V_31 < 0 )
return V_31 ;
F_18 ( V_2 , V_79 ,
V_79 ) ;
break;
case V_71 :
V_2 -> V_74 = 1 ;
V_31 = F_42 ( V_5 , & V_85 , & V_86 ,
V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
F_18 ( V_2 , V_79 ,
V_79 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
int V_31 ;
switch ( V_2 -> V_64 . V_65 ) {
case V_66 :
V_31 = F_44 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
break;
case V_70 :
V_31 = F_44 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_30 = V_2 -> V_30 ;
V_31 = F_45 ( V_30 -> V_41 ) ;
if ( V_31 < 0 )
return V_31 ;
break;
case V_71 :
V_31 = F_44 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_36 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
break;
}
return 0 ;
}
