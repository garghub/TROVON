static inline T_1 F_1 ( long V_1 , int div )
{
long V_2 ;
if ( V_1 == 0 )
return 0 ;
V_2 = F_2 ( V_1 , 1 , 960000 ) * div ;
return F_2 ( ( 480000 + V_2 / 2 ) / V_2 , 1 , 255 ) ;
}
static int F_3 ( struct V_3 * V_4 , T_1 V_5 )
{
if ( ( V_5 >= 0x07 ) && ( V_5 <= 0x0c ) )
return F_4 ( V_4 , V_5 ) ;
else
return F_5 ( V_4 , V_5 ) ;
}
static int F_6 ( struct V_3 * V_4 , T_1 V_5 , T_2 V_6 )
{
if ( ( V_5 >= 0x07 ) && ( V_5 <= 0x0c ) )
return F_7 ( V_4 , V_5 , V_6 ) ;
else
return F_8 ( V_4 , V_5 , V_6 ) ;
}
static struct V_7 * F_9 ( struct V_8 * V_9 )
{
struct V_7 * V_10 = F_10 ( V_9 ) ;
struct V_3 * V_4 = V_10 -> V_4 ;
int V_11 ;
F_11 ( & V_10 -> V_12 ) ;
if ( F_12 ( V_13 , V_10 -> V_14 + V_15 + V_15 / 2 )
|| ! V_10 -> V_16 ) {
F_13 ( & V_4 -> V_9 , L_1 ) ;
V_10 -> V_17 = F_3 ( V_4 , V_18 ) ;
V_10 -> V_19 = F_3 ( V_4 , V_20 ) ;
V_11 = F_3 ( V_4 , V_21 ) ;
V_10 -> V_22 [ 0 ] = V_11 & 0xff ;
V_10 -> V_23 [ 0 ] = ( V_11 >> 8 ) & 0xff ;
V_11 = F_3 ( V_4 , V_24 ) ;
V_10 -> V_22 [ 1 ] = V_11 & 0xff ;
V_10 -> V_23 [ 1 ] = ( V_11 >> 8 ) & 0xff ;
V_11 = F_3 ( V_4 , V_25 ) ;
V_10 -> V_22 [ 2 ] = V_11 & 0xff ;
V_10 -> V_23 [ 2 ] = ( V_11 >> 8 ) & 0xff ;
V_11 = F_3 ( V_4 , V_26 ) ;
V_10 -> V_22 [ 3 ] = V_11 & 0xff ;
V_10 -> V_23 [ 3 ] = ( V_11 >> 8 ) & 0xff ;
V_11 = F_3 ( V_4 , V_27 ) ;
V_10 -> V_28 [ 0 ] = ( V_11 >> 8 ) & 0xff ;
V_10 -> V_28 [ 1 ] = V_11 & 0xff ;
V_11 = F_3 ( V_4 , V_29 ) ;
V_10 -> V_30 [ 0 ] = ( V_11 >> 8 ) & 0xff ;
V_10 -> V_30 [ 1 ] = V_11 & 0xff ;
V_10 -> V_31 = F_3 ( V_4 , V_32 ) ;
V_10 -> V_33 =
F_3 ( V_4 , V_34 ) ;
V_10 -> V_35 =
F_3 ( V_4 , V_36 ) ;
V_11 = F_3 ( V_4 , V_37 ) ;
V_10 -> V_38 [ 0 ] = ( V_11 >> 6 ) & 0x03 ;
V_10 -> V_38 [ 1 ] = ( V_11 >> 4 ) & 0x03 ;
V_10 -> V_39 = ( V_11 >> 3 ) & 0x01 ;
V_10 -> V_17 &= V_10 -> V_40 ;
V_11 = F_3 ( V_4 , V_41 ) ;
V_10 -> V_42 = ( V_11 >> 2 ) & 1 ;
if ( V_10 -> type != V_43 ) {
V_10 -> V_44 [ 0 ] =
F_3 ( V_4 , V_45 ) ;
V_10 -> V_44 [ 1 ] =
F_3 ( V_4 , V_46 ) ;
V_10 -> V_44 [ 2 ] =
F_3 ( V_4 , V_47 ) ;
}
V_10 -> V_44 [ 3 ] =
F_3 ( V_4 , V_48 ) ;
V_10 -> V_14 = V_13 ;
V_10 -> V_16 = 1 ;
}
F_14 ( & V_10 -> V_12 ) ;
return V_10 ;
}
static T_3 F_15 ( struct V_8 * V_9 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_16 ( V_50 ) -> V_53 ;
struct V_7 * V_10 = F_9 ( V_9 ) ;
return sprintf ( V_51 , L_2 , F_17 ( V_10 -> V_28 [ V_52 ] ,
F_18 ( V_10 -> V_38 [ V_52 ] ) ) ) ;
}
static T_3 F_19 ( struct V_8 * V_9 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_16 ( V_50 ) -> V_53 ;
struct V_7 * V_10 = F_9 ( V_9 ) ;
return sprintf ( V_51 , L_2 , F_17 ( V_10 -> V_30 [ V_52 ] ,
F_18 ( V_10 -> V_38 [ V_52 ] ) ) ) ;
}
static T_3 F_20 ( struct V_8 * V_9 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_16 ( V_50 ) -> V_53 ;
struct V_7 * V_10 = F_9 ( V_9 ) ;
return sprintf ( V_51 , L_2 , F_18 ( V_10 -> V_38 [ V_52 ] ) ) ;
}
static T_3 F_21 ( struct V_8 * V_9 , struct V_49 * V_50 ,
const char * V_51 , T_4 V_54 )
{
struct V_7 * V_10 = F_10 ( V_9 ) ;
struct V_3 * V_4 = V_10 -> V_4 ;
int V_52 = F_16 ( V_50 ) -> V_53 ;
int V_55 ;
unsigned long V_11 ;
int V_56 ;
V_56 = F_22 ( V_51 , 10 , & V_11 ) ;
if ( V_56 )
return V_56 ;
F_11 ( & V_10 -> V_12 ) ;
V_55 = F_3 ( V_4 , V_29 ) ;
V_10 -> V_30 [ V_52 ] = F_1 ( V_11 , F_18 ( V_10 -> V_38 [ V_52 ] ) ) ;
V_55 = ( V_55 & ( 0xff << ( 8 * V_52 ) ) )
| ( V_10 -> V_30 [ V_52 ] << ( 8 * ( 1 - V_52 ) ) ) ;
F_6 ( V_4 , V_29 , V_55 ) ;
V_10 -> V_19 = F_3 ( V_4 , V_20 ) ;
if ( V_10 -> V_30 [ V_52 ] == 0 )
V_10 -> V_40 &= ~ ( 0x20 << V_52 ) ;
else
V_10 -> V_40 |= ( 0x20 << V_52 ) ;
V_10 -> V_19 &= V_10 -> V_40 ;
F_6 ( V_4 , V_20 , V_10 -> V_19 ) ;
F_14 ( & V_10 -> V_12 ) ;
return V_54 ;
}
static T_3 F_23 ( struct V_8 * V_9 , struct V_49 * V_50 ,
const char * V_51 , T_4 V_54 )
{
struct V_7 * V_10 = F_10 ( V_9 ) ;
struct V_3 * V_4 = V_10 -> V_4 ;
int V_52 = F_16 ( V_50 ) -> V_53 ;
int V_55 ;
unsigned long V_11 ;
int V_56 ;
V_56 = F_22 ( V_51 , 10 , & V_11 ) ;
if ( V_56 )
return V_56 ;
switch ( V_11 ) {
case 1 :
V_11 = 0 ;
break;
case 2 :
V_11 = 1 ;
break;
case 4 :
V_11 = 2 ;
break;
case 8 :
V_11 = 3 ;
break;
default:
F_24 ( V_9 ,
L_3 ,
V_11 ) ;
return - V_57 ;
}
F_11 ( & V_10 -> V_12 ) ;
V_55 = F_3 ( V_4 , V_37 ) ;
V_10 -> V_38 [ V_52 ] = V_11 ;
V_55 = ( V_55 & ~ ( 0xc0 >> ( 2 * V_52 ) ) )
| ( V_10 -> V_38 [ V_52 ] << ( 6 - 2 * V_52 ) ) ;
F_6 ( V_4 , V_37 , V_55 ) ;
F_14 ( & V_10 -> V_12 ) ;
return V_54 ;
}
static T_3 F_25 ( struct V_8 * V_9 , struct V_49 * V_50 ,
char * V_51 )
{
int V_58 = F_16 ( V_50 ) -> V_53 ;
struct V_7 * V_10 = F_9 ( V_9 ) ;
return sprintf ( V_51 , L_4 , ( V_10 -> V_17 >> V_58 ) & 1 ) ;
}
static T_3 F_26 ( struct V_8 * V_9 , struct V_49 * V_50 ,
char * V_51 )
{
int V_58 = F_16 ( V_50 ) -> V_53 ;
struct V_7 * V_10 = F_9 ( V_9 ) ;
return sprintf ( V_51 , L_4 , ( V_10 -> V_19 >> V_58 ) & 1 ) ;
}
static T_3 F_27 ( struct V_8 * V_9 , struct V_49 * V_50 ,
const char * V_51 , T_4 V_54 )
{
struct V_7 * V_10 = F_10 ( V_9 ) ;
struct V_3 * V_4 = V_10 -> V_4 ;
int V_58 = F_16 ( V_50 ) -> V_53 ;
unsigned long V_59 ;
int V_56 ;
V_56 = F_22 ( V_51 , 10 , & V_59 ) ;
if ( V_56 )
return V_56 ;
if ( V_59 & ~ 1 )
return - V_57 ;
F_11 ( & V_10 -> V_12 ) ;
V_10 -> V_19 = F_3 ( V_4 , V_20 ) ;
if ( V_59 )
V_10 -> V_19 |= ( 1 << V_58 ) ;
else
V_10 -> V_19 &= ~ ( 1 << V_58 ) ;
F_6 ( V_4 , V_20 , V_10 -> V_19 ) ;
F_14 ( & V_10 -> V_12 ) ;
return V_54 ;
}
static int F_28 ( struct V_3 * V_4 , struct V_60 * V_61 )
{
struct V_62 * V_63 = V_4 -> V_63 ;
int V_64 ;
if ( ! F_29 ( V_63 , V_65 |
V_66 ) )
return - V_67 ;
if ( ( F_3 ( V_4 , V_68 ) != 0x80 )
|| ( F_3 ( V_4 , V_41 ) & 0x80 ) )
return - V_67 ;
V_64 = F_3 ( V_4 , V_69 ) ;
if ( V_64 != 0x00 && V_64 != 0x80 )
return - V_67 ;
F_30 ( V_61 -> type , L_5 , V_70 ) ;
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
T_1 V_55 = F_3 ( V_4 , V_41 ) & 0x7f ;
F_6 ( V_4 , V_41 , ( V_55 &= 0x37 ) ) ;
F_6 ( V_4 , V_71 , 0x00 ) ;
F_6 ( V_4 , V_41 , 0x20 | V_55 ) ;
F_6 ( V_4 , V_41 , 0x40 | V_55 ) ;
}
static int F_32 ( struct V_3 * V_4 ,
const struct V_72 * V_73 )
{
struct V_8 * V_9 = & V_4 -> V_9 ;
struct V_8 * V_74 ;
struct V_7 * V_10 ;
int V_75 ;
V_10 = F_33 ( V_9 , sizeof( struct V_7 ) , V_76 ) ;
if ( ! V_10 )
return - V_77 ;
V_10 -> V_4 = V_4 ;
V_75 = F_3 ( V_4 , V_69 ) ;
V_10 -> type = V_75 == 0x80 ? V_78 : V_43 ;
F_34 ( & V_10 -> V_12 ) ;
V_10 -> V_40 = 0xff ;
F_31 ( V_4 ) ;
V_10 -> V_79 [ 0 ] = & V_80 ;
if ( V_10 -> type == V_78 )
V_10 -> V_79 [ 1 ] = & V_81 ;
V_74 = F_35 ( V_9 , V_4 -> V_82 ,
V_10 , V_10 -> V_79 ) ;
return F_36 ( V_74 ) ;
}
