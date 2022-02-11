static inline T_1 F_1 ( long V_1 , int div )
{
long V_2 ;
if ( V_1 == 0 )
return 0 ;
V_2 = F_2 ( V_1 , 1 , 960000 ) * div ;
return F_2 ( ( 480000 + V_2 / 2 ) / V_2 , 1 , 255 ) ;
}
static T_2 F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 )
{
int V_8 = F_4 ( V_6 ) -> V_9 ;
struct V_10 * V_11 = F_5 ( V_4 ) ;
return sprintf ( V_7 , L_1 , F_6 ( V_11 -> V_12 [ V_8 ] ,
F_7 ( V_11 -> V_13 [ V_8 ] ) ) ) ;
}
static T_2 F_8 ( struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 )
{
int V_8 = F_4 ( V_6 ) -> V_9 ;
struct V_10 * V_11 = F_5 ( V_4 ) ;
return sprintf ( V_7 , L_1 , F_6 ( V_11 -> V_14 [ V_8 ] ,
F_7 ( V_11 -> V_13 [ V_8 ] ) ) ) ;
}
static T_2 F_9 ( struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 )
{
int V_8 = F_4 ( V_6 ) -> V_9 ;
struct V_10 * V_11 = F_5 ( V_4 ) ;
return sprintf ( V_7 , L_1 , F_7 ( V_11 -> V_13 [ V_8 ] ) ) ;
}
static T_2 F_10 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const char * V_7 , T_3 V_15 )
{
struct V_16 * V_17 = F_11 ( V_4 ) ;
struct V_10 * V_11 = F_12 ( V_17 ) ;
int V_8 = F_4 ( V_6 ) -> V_9 ;
int V_18 ;
unsigned long V_19 ;
int V_20 ;
V_20 = F_13 ( V_7 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_14 ( & V_11 -> V_21 ) ;
V_18 = F_15 ( V_17 , V_22 ) ;
V_11 -> V_14 [ V_8 ] = F_1 ( V_19 , F_7 ( V_11 -> V_13 [ V_8 ] ) ) ;
V_18 = ( V_18 & ( 0xff << ( 8 * V_8 ) ) )
| ( V_11 -> V_14 [ V_8 ] << ( 8 * ( 1 - V_8 ) ) ) ;
F_16 ( V_17 , V_22 , V_18 ) ;
V_11 -> V_23 = F_15 ( V_17 , V_24 ) ;
if ( V_11 -> V_14 [ V_8 ] == 0 )
V_11 -> V_25 &= ~ ( 0x20 << V_8 ) ;
else
V_11 -> V_25 |= ( 0x20 << V_8 ) ;
V_11 -> V_23 &= V_11 -> V_25 ;
F_16 ( V_17 , V_24 , V_11 -> V_23 ) ;
F_17 ( & V_11 -> V_21 ) ;
return V_15 ;
}
static T_2 F_18 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const char * V_7 , T_3 V_15 )
{
struct V_16 * V_17 = F_11 ( V_4 ) ;
struct V_10 * V_11 = F_12 ( V_17 ) ;
int V_8 = F_4 ( V_6 ) -> V_9 ;
int V_18 ;
unsigned long V_19 ;
int V_20 ;
V_20 = F_13 ( V_7 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
switch ( V_19 ) {
case 1 :
V_19 = 0 ;
break;
case 2 :
V_19 = 1 ;
break;
case 4 :
V_19 = 2 ;
break;
case 8 :
V_19 = 3 ;
break;
default:
F_19 ( V_4 ,
L_2 ,
V_19 ) ;
return - V_26 ;
}
F_14 ( & V_11 -> V_21 ) ;
V_18 = F_15 ( V_17 , V_27 ) ;
V_11 -> V_13 [ V_8 ] = V_19 ;
V_18 = ( V_18 & ~ ( 0xc0 >> ( 2 * V_8 ) ) )
| ( V_11 -> V_13 [ V_8 ] << ( 6 - 2 * V_8 ) ) ;
F_16 ( V_17 , V_27 , V_18 ) ;
F_17 ( & V_11 -> V_21 ) ;
return V_15 ;
}
static T_2 F_20 ( struct V_3 * V_4 , struct V_5 * V_6 ,
char * V_7 )
{
int V_28 = F_4 ( V_6 ) -> V_9 ;
struct V_10 * V_11 = F_5 ( V_4 ) ;
return sprintf ( V_7 , L_3 , ( V_11 -> V_29 >> V_28 ) & 1 ) ;
}
static T_2 F_21 ( struct V_3 * V_4 , struct V_5 * V_6 ,
char * V_7 )
{
int V_28 = F_4 ( V_6 ) -> V_9 ;
struct V_10 * V_11 = F_5 ( V_4 ) ;
return sprintf ( V_7 , L_3 , ( V_11 -> V_23 >> V_28 ) & 1 ) ;
}
static T_2 F_22 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const char * V_7 , T_3 V_15 )
{
struct V_16 * V_17 = F_11 ( V_4 ) ;
struct V_10 * V_11 = F_12 ( V_17 ) ;
int V_28 = F_4 ( V_6 ) -> V_9 ;
unsigned long V_30 ;
int V_20 ;
V_20 = F_13 ( V_7 , 10 , & V_30 ) ;
if ( V_20 )
return V_20 ;
if ( V_30 & ~ 1 )
return - V_26 ;
F_14 ( & V_11 -> V_21 ) ;
V_11 -> V_23 = F_15 ( V_17 , V_24 ) ;
if ( V_30 )
V_11 -> V_23 |= ( 1 << V_28 ) ;
else
V_11 -> V_23 &= ~ ( 1 << V_28 ) ;
F_16 ( V_17 , V_24 , V_11 -> V_23 ) ;
F_17 ( & V_11 -> V_21 ) ;
return V_15 ;
}
static int F_23 ( struct V_16 * V_17 , struct V_31 * V_32 )
{
struct V_33 * V_34 = V_17 -> V_34 ;
int V_35 ;
if ( ! F_24 ( V_34 , V_36 |
V_37 ) )
return - V_38 ;
if ( ( F_15 ( V_17 , V_39 ) != 0x80 )
|| ( F_15 ( V_17 , V_40 ) & 0x80 ) )
return - V_38 ;
V_35 = F_15 ( V_17 , V_41 ) ;
if ( V_35 != 0x00 && V_35 != 0x80 )
return - V_38 ;
F_25 ( V_32 -> type , L_4 , V_42 ) ;
return 0 ;
}
static int F_26 ( struct V_16 * V_17 ,
const struct V_43 * V_44 )
{
struct V_10 * V_11 ;
int V_20 , V_45 ;
V_11 = F_27 ( & V_17 -> V_4 , sizeof( struct V_10 ) ,
V_46 ) ;
if ( ! V_11 )
return - V_47 ;
F_28 ( V_17 , V_11 ) ;
V_45 = F_15 ( V_17 , V_41 ) ;
V_11 -> type = V_45 == 0x80 ? V_48 : V_49 ;
F_29 ( & V_11 -> V_21 ) ;
V_11 -> V_25 = 0xff ;
F_30 ( V_17 ) ;
V_20 = F_31 ( & V_17 -> V_4 . V_50 , & V_51 ) ;
if ( V_20 )
return V_20 ;
if ( V_11 -> type == V_48 ) {
V_20 = F_31 ( & V_17 -> V_4 . V_50 , & V_52 ) ;
if ( V_20 )
goto V_53;
}
V_11 -> V_54 = F_32 ( & V_17 -> V_4 ) ;
if ( F_33 ( V_11 -> V_54 ) ) {
V_20 = F_34 ( V_11 -> V_54 ) ;
goto V_53;
}
return 0 ;
V_53:
F_35 ( & V_17 -> V_4 . V_50 , & V_51 ) ;
if ( V_11 -> type == V_48 )
F_35 ( & V_17 -> V_4 . V_50 , & V_52 ) ;
return V_20 ;
}
static void F_30 ( struct V_16 * V_17 )
{
T_1 V_18 = F_15 ( V_17 , V_40 ) & 0x7f ;
F_16 ( V_17 , V_40 , ( V_18 &= 0x37 ) ) ;
F_16 ( V_17 , V_55 , 0x00 ) ;
F_16 ( V_17 , V_40 , 0x20 | V_18 ) ;
F_16 ( V_17 , V_40 , 0x40 | V_18 ) ;
}
static int F_36 ( struct V_16 * V_17 )
{
struct V_10 * V_11 = F_12 ( V_17 ) ;
F_37 ( V_11 -> V_54 ) ;
F_35 ( & V_17 -> V_4 . V_50 , & V_51 ) ;
if ( V_11 -> type == V_48 )
F_35 ( & V_17 -> V_4 . V_50 , & V_52 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 , T_1 V_56 )
{
if ( ( V_56 >= 0x07 ) && ( V_56 <= 0x0c ) )
return F_38 ( V_17 , V_56 ) ;
else
return F_39 ( V_17 , V_56 ) ;
}
static int F_16 ( struct V_16 * V_17 , T_1 V_56 , T_4 V_57 )
{
if ( ( V_56 >= 0x07 ) && ( V_56 <= 0x0c ) )
return F_40 ( V_17 , V_56 , V_57 ) ;
else
return F_41 ( V_17 , V_56 , V_57 ) ;
}
static struct V_10 * F_5 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = F_11 ( V_4 ) ;
struct V_10 * V_11 = F_12 ( V_17 ) ;
int V_19 ;
F_14 ( & V_11 -> V_21 ) ;
if ( F_42 ( V_58 , V_11 -> V_59 + V_60 + V_60 / 2 )
|| ! V_11 -> V_61 ) {
F_43 ( & V_17 -> V_4 , L_5 ) ;
V_11 -> V_29 = F_15 ( V_17 , V_62 ) ;
V_11 -> V_23 = F_15 ( V_17 , V_24 ) ;
V_19 = F_15 ( V_17 , V_63 ) ;
V_11 -> V_64 [ 0 ] = V_19 & 0xff ;
V_11 -> V_65 [ 0 ] = ( V_19 >> 8 ) & 0xff ;
V_19 = F_15 ( V_17 , V_66 ) ;
V_11 -> V_64 [ 1 ] = V_19 & 0xff ;
V_11 -> V_65 [ 1 ] = ( V_19 >> 8 ) & 0xff ;
V_19 = F_15 ( V_17 , V_67 ) ;
V_11 -> V_64 [ 2 ] = V_19 & 0xff ;
V_11 -> V_65 [ 2 ] = ( V_19 >> 8 ) & 0xff ;
V_19 = F_15 ( V_17 , V_68 ) ;
V_11 -> V_64 [ 3 ] = V_19 & 0xff ;
V_11 -> V_65 [ 3 ] = ( V_19 >> 8 ) & 0xff ;
V_19 = F_15 ( V_17 , V_69 ) ;
V_11 -> V_12 [ 0 ] = ( V_19 >> 8 ) & 0xff ;
V_11 -> V_12 [ 1 ] = V_19 & 0xff ;
V_19 = F_15 ( V_17 , V_22 ) ;
V_11 -> V_14 [ 0 ] = ( V_19 >> 8 ) & 0xff ;
V_11 -> V_14 [ 1 ] = V_19 & 0xff ;
V_11 -> V_70 = F_15 ( V_17 , V_71 ) ;
V_11 -> V_72 =
F_15 ( V_17 , V_73 ) ;
V_11 -> V_74 =
F_15 ( V_17 , V_75 ) ;
V_19 = F_15 ( V_17 , V_27 ) ;
V_11 -> V_13 [ 0 ] = ( V_19 >> 6 ) & 0x03 ;
V_11 -> V_13 [ 1 ] = ( V_19 >> 4 ) & 0x03 ;
V_11 -> V_76 = ( V_19 >> 3 ) & 0x01 ;
V_11 -> V_29 &= V_11 -> V_25 ;
V_19 = F_15 ( V_17 , V_40 ) ;
V_11 -> V_77 = ( V_19 >> 2 ) & 1 ;
if ( V_11 -> type != V_49 ) {
V_11 -> V_78 [ 0 ] =
F_15 ( V_17 , V_79 ) ;
V_11 -> V_78 [ 1 ] =
F_15 ( V_17 , V_80 ) ;
V_11 -> V_78 [ 2 ] =
F_15 ( V_17 , V_81 ) ;
}
V_11 -> V_78 [ 3 ] =
F_15 ( V_17 , V_82 ) ;
V_11 -> V_59 = V_58 ;
V_11 -> V_61 = 1 ;
}
F_17 ( & V_11 -> V_21 ) ;
return V_11 ;
}
