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
unsigned long V_19 = F_13 ( V_7 , NULL , 10 ) ;
F_14 ( & V_11 -> V_20 ) ;
V_18 = F_15 ( V_17 , V_21 ) ;
V_11 -> V_14 [ V_8 ] = F_1 ( V_19 , F_7 ( V_11 -> V_13 [ V_8 ] ) ) ;
V_18 = ( V_18 & ( 0xff << ( 8 * V_8 ) ) )
| ( V_11 -> V_14 [ V_8 ] << ( 8 * ( 1 - V_8 ) ) ) ;
F_16 ( V_17 , V_21 , V_18 ) ;
V_11 -> V_22 = F_15 ( V_17 , V_23 ) ;
if ( V_11 -> V_14 [ V_8 ] == 0 )
V_11 -> V_24 &= ~ ( 0x20 << V_8 ) ;
else
V_11 -> V_24 |= ( 0x20 << V_8 ) ;
V_11 -> V_22 &= V_11 -> V_24 ;
F_16 ( V_17 , V_23 , V_11 -> V_22 ) ;
F_17 ( & V_11 -> V_20 ) ;
return V_15 ;
}
static T_2 F_18 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const char * V_7 , T_3 V_15 )
{
struct V_16 * V_17 = F_11 ( V_4 ) ;
struct V_10 * V_11 = F_12 ( V_17 ) ;
int V_8 = F_4 ( V_6 ) -> V_9 ;
int V_18 ;
unsigned long V_19 = F_13 ( V_7 , NULL , 10 ) ;
switch ( V_19 ) {
case 1 : V_19 = 0 ; break;
case 2 : V_19 = 1 ; break;
case 4 : V_19 = 2 ; break;
case 8 : V_19 = 3 ; break;
default:
F_19 ( V_4 , L_2
L_3 , V_19 ) ;
return - V_25 ;
}
F_14 ( & V_11 -> V_20 ) ;
V_18 = F_15 ( V_17 , V_26 ) ;
V_11 -> V_13 [ V_8 ] = V_19 ;
V_18 = ( V_18 & ~ ( 0xc0 >> ( 2 * V_8 ) ) )
| ( V_11 -> V_13 [ V_8 ] << ( 6 - 2 * V_8 ) ) ;
F_16 ( V_17 , V_26 , V_18 ) ;
F_17 ( & V_11 -> V_20 ) ;
return V_15 ;
}
static T_2 F_20 ( struct V_3 * V_4 , struct V_5 * V_6 ,
char * V_7 )
{
int V_27 = F_4 ( V_6 ) -> V_9 ;
struct V_10 * V_11 = F_5 ( V_4 ) ;
return sprintf ( V_7 , L_4 , ( V_11 -> V_28 >> V_27 ) & 1 ) ;
}
static T_2 F_21 ( struct V_3 * V_4 , struct V_5 * V_6 ,
char * V_7 )
{
int V_27 = F_4 ( V_6 ) -> V_9 ;
struct V_10 * V_11 = F_5 ( V_4 ) ;
return sprintf ( V_7 , L_4 , ( V_11 -> V_22 >> V_27 ) & 1 ) ;
}
static T_2 F_22 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const char * V_7 , T_3 V_15 )
{
struct V_16 * V_17 = F_11 ( V_4 ) ;
struct V_10 * V_11 = F_12 ( V_17 ) ;
int V_27 = F_4 ( V_6 ) -> V_9 ;
unsigned long V_29 ;
V_29 = F_13 ( V_7 , NULL , 10 ) ;
if ( V_29 & ~ 1 )
return - V_25 ;
F_14 ( & V_11 -> V_20 ) ;
V_11 -> V_22 = F_15 ( V_17 , V_23 ) ;
if ( V_29 )
V_11 -> V_22 |= ( 1 << V_27 ) ;
else
V_11 -> V_22 &= ~ ( 1 << V_27 ) ;
F_16 ( V_17 , V_23 , V_11 -> V_22 ) ;
F_17 ( & V_11 -> V_20 ) ;
return V_15 ;
}
static int F_23 ( struct V_16 * V_17 , struct V_30 * V_31 )
{
struct V_32 * V_33 = V_17 -> V_33 ;
int V_34 ;
if ( ! F_24 ( V_33 , V_35 |
V_36 ) )
return - V_37 ;
if ( ( F_15 ( V_17 , V_38 ) != 0x80 )
|| ( F_15 ( V_17 , V_39 ) & 0x80 ) )
return - V_37 ;
V_34 = F_15 ( V_17 , V_40 ) ;
if ( V_34 != 0x00 && V_34 != 0x80 )
return - V_37 ;
F_25 ( V_31 -> type , L_5 , V_41 ) ;
return 0 ;
}
static int F_26 ( struct V_16 * V_17 ,
const struct V_42 * V_43 )
{
struct V_10 * V_11 ;
int V_44 , V_45 ;
V_11 = F_27 ( sizeof( struct V_10 ) , V_46 ) ;
if ( ! V_11 ) {
V_44 = - V_47 ;
goto exit;
}
F_28 ( V_17 , V_11 ) ;
V_45 = F_15 ( V_17 , V_40 ) ;
V_11 -> type = V_45 == 0x80 ? V_48 : V_49 ;
F_29 ( & V_11 -> V_20 ) ;
V_11 -> V_24 = 0xff ;
F_30 ( V_17 ) ;
if ( ( V_44 = F_31 ( & V_17 -> V_4 . V_50 , & V_51 ) ) )
goto V_52;
if ( V_11 -> type == V_48 )
if ( ( V_44 = F_31 ( & V_17 -> V_4 . V_50 ,
& V_53 ) ) )
goto V_54;
V_11 -> V_55 = F_32 ( & V_17 -> V_4 ) ;
if ( F_33 ( V_11 -> V_55 ) ) {
V_44 = F_34 ( V_11 -> V_55 ) ;
goto V_54;
}
return 0 ;
V_54:
F_35 ( & V_17 -> V_4 . V_50 , & V_51 ) ;
if ( V_11 -> type == V_48 )
F_35 ( & V_17 -> V_4 . V_50 , & V_53 ) ;
V_52:
F_36 ( V_11 ) ;
exit:
return V_44 ;
}
static void F_30 ( struct V_16 * V_17 )
{
T_1 V_18 = F_15 ( V_17 , V_39 ) & 0x7f ;
F_16 ( V_17 , V_39 , ( V_18 &= 0x37 ) ) ;
F_16 ( V_17 , V_56 , 0x00 ) ;
F_16 ( V_17 , V_39 , 0x20 | V_18 ) ;
F_16 ( V_17 , V_39 , 0x40 | V_18 ) ;
}
static int F_37 ( struct V_16 * V_17 )
{
struct V_10 * V_11 = F_12 ( V_17 ) ;
F_38 ( V_11 -> V_55 ) ;
F_35 ( & V_17 -> V_4 . V_50 , & V_51 ) ;
if ( V_11 -> type == V_48 )
F_35 ( & V_17 -> V_4 . V_50 , & V_53 ) ;
F_36 ( V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 , T_1 V_57 )
{
if ( ( V_57 >= 0x07 ) && ( V_57 <= 0x0c ) )
return F_39 ( F_40 ( V_17 , V_57 ) ) ;
else
return F_41 ( V_17 , V_57 ) ;
}
static int F_16 ( struct V_16 * V_17 , T_1 V_57 , T_4 V_58 )
{
if ( ( V_57 >= 0x07 ) && ( V_57 <= 0x0c ) )
return F_42 ( V_17 , V_57 , F_39 ( V_58 ) ) ;
else
return F_43 ( V_17 , V_57 , V_58 ) ;
}
static struct V_10 * F_5 ( struct V_3 * V_4 )
{
struct V_16 * V_17 = F_11 ( V_4 ) ;
struct V_10 * V_11 = F_12 ( V_17 ) ;
int V_19 ;
F_14 ( & V_11 -> V_20 ) ;
if ( F_44 ( V_59 , V_11 -> V_60 + V_61 + V_61 / 2 )
|| ! V_11 -> V_62 ) {
F_45 ( & V_17 -> V_4 , L_6 ) ;
V_11 -> V_28 = F_15 ( V_17 , V_63 ) ;
V_11 -> V_22 = F_15 ( V_17 , V_23 ) ;
V_19 = F_15 ( V_17 , V_64 ) ;
V_11 -> V_65 [ 0 ] = V_19 & 0xff ;
V_11 -> V_66 [ 0 ] = ( V_19 >> 8 ) & 0xff ;
V_19 = F_15 ( V_17 , V_67 ) ;
V_11 -> V_65 [ 1 ] = V_19 & 0xff ;
V_11 -> V_66 [ 1 ] = ( V_19 >> 8 ) & 0xff ;
V_19 = F_15 ( V_17 , V_68 ) ;
V_11 -> V_65 [ 2 ] = V_19 & 0xff ;
V_11 -> V_66 [ 2 ] = ( V_19 >> 8 ) & 0xff ;
V_19 = F_15 ( V_17 , V_69 ) ;
V_11 -> V_65 [ 3 ] = V_19 & 0xff ;
V_11 -> V_66 [ 3 ] = ( V_19 >> 8 ) & 0xff ;
V_19 = F_15 ( V_17 , V_70 ) ;
V_11 -> V_12 [ 0 ] = ( V_19 >> 8 ) & 0xff ;
V_11 -> V_12 [ 1 ] = V_19 & 0xff ;
V_19 = F_15 ( V_17 , V_21 ) ;
V_11 -> V_14 [ 0 ] = ( V_19 >> 8 ) & 0xff ;
V_11 -> V_14 [ 1 ] = V_19 & 0xff ;
V_11 -> V_71 = F_15 ( V_17 , V_72 ) ;
V_11 -> V_73 =
F_15 ( V_17 , V_74 ) ;
V_11 -> V_75 =
F_15 ( V_17 , V_76 ) ;
V_19 = F_15 ( V_17 , V_26 ) ;
V_11 -> V_13 [ 0 ] = ( V_19 >> 6 ) & 0x03 ;
V_11 -> V_13 [ 1 ] = ( V_19 >> 4 ) & 0x03 ;
V_11 -> V_77 = ( V_19 >> 3 ) & 0x01 ;
V_11 -> V_28 &= V_11 -> V_24 ;
V_19 = F_15 ( V_17 , V_39 ) ;
V_11 -> V_78 = ( V_19 >> 2 ) & 1 ;
if ( V_11 -> type != V_49 ) {
V_11 -> V_79 [ 0 ] =
F_15 ( V_17 , V_80 ) ;
V_11 -> V_79 [ 1 ] =
F_15 ( V_17 , V_81 ) ;
V_11 -> V_79 [ 2 ] =
F_15 ( V_17 , V_82 ) ;
}
V_11 -> V_79 [ 3 ] =
F_15 ( V_17 , V_83 ) ;
V_11 -> V_60 = V_59 ;
V_11 -> V_62 = 1 ;
}
F_17 ( & V_11 -> V_20 ) ;
return V_11 ;
}
static int T_5 F_46 ( void )
{
return F_47 ( & V_84 ) ;
}
static void T_6 F_48 ( void )
{
F_49 ( & V_84 ) ;
}
