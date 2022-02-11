static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_3 ( V_7 -> V_8 , V_7 -> V_9 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_12 = V_7 -> V_13 [ V_10 ] ;
if ( V_10 == 0 )
return sprintf ( V_5 , L_2 , F_6 ( V_12 ) ) ;
else
return sprintf ( V_5 , L_2 , F_7 ( V_12 ) ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_12 = V_7 -> V_14 [ V_10 ] ;
if ( V_10 == 0 )
return sprintf ( V_5 , L_2 , F_6 ( V_12 ) ) ;
else
return sprintf ( V_5 , L_2 , F_7 ( V_12 ) ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_12 = V_7 -> V_15 [ V_10 ] ;
if ( V_10 == 0 )
return sprintf ( V_5 , L_2 , F_6 ( V_12 ) ) ;
else
return sprintf ( V_5 , L_2 , F_7 ( V_12 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
long V_19 = F_13 ( V_5 , NULL , 10 ) ;
T_2 V_12 ;
F_14 ( & V_7 -> V_20 ) ;
if ( V_10 == 0 )
V_12 = F_15 ( V_19 ) ;
else
V_12 = F_16 ( V_19 ) ;
V_7 -> V_14 [ V_10 ] = V_12 ;
if ( V_10 < 4 )
F_17 ( V_18 , V_21 [ V_10 ] ,
( F_18 ( V_18 , V_21 [ V_10 ] )
& ~ 0xff ) | V_12 ) ;
else
F_17 ( V_18 , V_21 [ V_10 ] , V_12 ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
long V_19 = F_13 ( V_5 , NULL , 10 ) ;
T_2 V_12 ;
if ( V_10 == 0 )
V_12 = F_15 ( V_19 ) ;
else
V_12 = F_16 ( V_19 ) ;
F_14 ( & V_7 -> V_20 ) ;
V_7 -> V_15 [ V_10 ] = V_12 ;
if ( V_10 < 4 )
F_17 ( V_18 , V_22 [ V_10 ] ,
( F_18 ( V_18 , V_22 [ V_10 ] )
& ~ 0xff00 ) | ( V_12 << 8 ) ) ;
else
F_17 ( V_18 , V_22 [ V_10 ] , V_12 ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_22 ( V_7 -> V_23 [ V_10 ] ,
V_7 -> V_24 [ V_10 ] ) ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_22 ( V_7 -> V_25 [ V_10 ] ,
V_7 -> V_24 [ V_10 ] ) ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_25 ( V_7 -> V_24 [ V_10 ] ) ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_26 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
unsigned long V_19 = F_28 ( V_5 , NULL , 10 ) ;
T_2 V_12 ;
F_14 ( & V_7 -> V_20 ) ;
V_12 = F_29 ( V_19 , V_7 -> V_24 [ V_10 ] ) ;
V_7 -> V_25 [ V_10 ] = V_12 ;
if ( V_10 == 0 )
F_17 ( V_18 , V_27 ,
( F_18 ( V_18 , V_27 )
& ~ 0xff00 ) | ( V_12 << 8 ) ) ;
else
F_17 ( V_18 , V_27 ,
( F_18 ( V_18 , V_27 )
& ~ 0xff ) | V_12 ) ;
V_7 -> V_28 = F_18 ( V_18 , V_29 ) ;
if ( V_7 -> V_25 [ V_10 ] == 0 )
V_7 -> V_30 &= ( V_10 == 0 ) ? ~ 0x20 : ~ 0x40 ;
else
V_7 -> V_30 |= ( V_10 == 0 ) ? 0x20 : 0x40 ;
V_7 -> V_28 &= V_7 -> V_30 ;
F_17 ( V_18 , V_29 , V_7 -> V_28 ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
unsigned long V_19 = F_28 ( V_5 , NULL , 10 ) ;
T_2 V_12 ;
switch ( V_19 ) {
case 1 : V_12 = 0 ; break;
case 2 : V_12 = 1 ; break;
case 4 : V_12 = 2 ; break;
case 8 : V_12 = 3 ; break;
default:
F_31 ( & V_18 -> V_2 , L_3 , V_19 ) ;
return - V_31 ;
}
F_14 ( & V_7 -> V_20 ) ;
V_7 -> V_24 [ V_10 ] = V_12 ;
if ( V_10 == 0 )
F_17 ( V_18 , V_32 ,
( F_18 ( V_18 , V_32 )
& ~ 0xc0 ) | ( V_12 << 6 ) ) ;
else
F_17 ( V_18 , V_32 ,
( F_18 ( V_18 , V_32 )
& ~ 0x30 ) | ( V_12 << 4 ) ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
T_2 V_12 = F_28 ( V_5 , NULL , 10 ) ? 1 : 0 ;
F_14 ( & V_7 -> V_20 ) ;
V_7 -> V_26 = V_12 ;
F_17 ( V_18 , V_33 ,
( F_18 ( V_18 , V_33 )
& ~ 0x0c ) | ( V_12 << 2 ) ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_34 ( V_7 -> V_34 [ V_10 ] ) ) ;
}
static T_1 F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_34 ( V_7 -> V_35 [ V_10 ] ) ) ;
}
static T_1 F_36 ( struct V_1 * V_2 , struct V_3
* V_4 , char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_34 ( V_7 -> V_36 [ V_10 ] ) ) ;
}
static T_1 F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
long V_19 = F_13 ( V_5 , NULL , 10 ) ;
F_14 ( & V_7 -> V_20 ) ;
V_7 -> V_35 [ V_10 ] = F_38 ( V_19 ) ;
F_17 ( V_18 , V_37 [ V_10 ] , V_7 -> V_35 [ V_10 ] ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_39 ( struct V_1 * V_2 , struct V_3
* V_4 , const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
long V_19 = F_13 ( V_5 , NULL , 10 ) ;
F_14 ( & V_7 -> V_20 ) ;
V_7 -> V_36 [ V_10 ] = F_38 ( V_19 ) ;
F_17 ( V_18 , V_38 [ V_10 ] ,
V_7 -> V_36 [ V_10 ] ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_39 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 , struct V_3
* V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_40 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_28 ) ;
}
static T_1 F_43 ( struct V_1 * V_2 , struct V_3
* V_4 , const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
T_2 V_12 = F_28 ( V_5 , NULL , 10 ) ? 0 : 1 ;
F_14 ( & V_7 -> V_20 ) ;
V_7 -> V_40 = ! V_12 ;
F_17 ( V_18 , V_41 ,
( F_18 ( V_18 , V_41 )
& ~ 0x04 ) | ( V_12 << 2 ) ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
T_2 V_12 = F_28 ( V_5 , NULL , 10 ) ;
F_14 ( & V_7 -> V_20 ) ;
V_12 &= V_7 -> V_30 ;
V_7 -> V_28 = V_12 ;
F_17 ( V_18 , V_29 , V_12 ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static T_1 F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_42 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , ( V_7 -> V_39 >> V_42 ) & 1 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_43 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , ( V_7 -> V_28 >> V_43 ) & 1 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_43 = F_5 ( V_4 ) -> V_11 ;
unsigned long V_44 ;
V_44 = F_28 ( V_5 , NULL , 10 ) ;
if ( V_44 & ~ 1 )
return - V_31 ;
F_14 ( & V_7 -> V_20 ) ;
V_7 -> V_28 = F_18 ( V_18 , V_29 ) ;
if ( V_44 )
V_7 -> V_28 |= ( 1 << V_43 ) ;
else
V_7 -> V_28 &= ~ ( 1 << V_43 ) ;
F_17 ( V_18 , V_29 , V_7 -> V_28 ) ;
F_19 ( & V_7 -> V_20 ) ;
return V_16 ;
}
static int F_48 ( struct V_17 * V_18 , struct V_45 * V_46 )
{
struct V_47 * V_48 = V_18 -> V_48 ;
if ( ! F_49 ( V_48 , V_49 |
V_50 ) )
return - V_51 ;
if ( ( F_18 ( V_18 , V_52 ) != 0x20 ) ||
( ( F_18 ( V_18 , V_53 ) & 0x7f ) != 0x00 ) ||
( ( F_18 ( V_18 , V_54 ) & 0x80 ) != 0x00 ) ) {
F_50 ( & V_18 -> V_2 , L_4 ) ;
return - V_51 ;
}
F_51 ( V_46 -> type , L_5 , V_55 ) ;
return 0 ;
}
static int F_52 ( struct V_17 * V_18 ,
const struct V_56 * V_57 )
{
struct V_6 * V_7 ;
int V_58 ;
V_7 = F_53 ( sizeof( struct V_6 ) , V_59 ) ;
if ( ! V_7 ) {
V_58 = - V_60 ;
goto exit;
}
F_54 ( V_18 , V_7 ) ;
F_55 ( & V_7 -> V_20 ) ;
F_56 ( V_18 ) ;
if ( ( V_58 = F_57 ( & V_18 -> V_2 . V_61 , & V_62 ) ) )
goto V_63;
if ( V_7 -> V_64 ) {
if ( ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_65 . V_66 ) )
|| ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_67 . V_66 ) )
|| ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_68 . V_66 ) )
|| ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_69 . V_66 ) )
|| ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_70 . V_66 ) ) )
goto V_71;
} else {
if ( ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_72 . V_66 ) )
|| ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_73 . V_66 ) )
|| ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_74 . V_66 ) )
|| ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_75 . V_66 ) )
|| ( V_58 = F_58 ( & V_18 -> V_2 ,
& V_76 . V_66 ) ) )
goto V_71;
}
V_7 -> V_77 = F_59 ( & V_18 -> V_2 ) ;
if ( F_60 ( V_7 -> V_77 ) ) {
V_58 = F_61 ( V_7 -> V_77 ) ;
goto V_71;
}
return 0 ;
V_71:
F_62 ( & V_18 -> V_2 . V_61 , & V_62 ) ;
F_62 ( & V_18 -> V_2 . V_61 , & V_78 ) ;
V_63:
F_63 ( V_7 ) ;
exit:
return V_58 ;
}
static void F_56 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_12 ( V_18 ) ;
T_2 V_79 , V_80 ;
V_80 = V_79 = F_18 ( V_18 , V_54 ) ;
V_7 -> V_30 = 0xff ;
V_7 -> V_9 = F_64 () ;
if ( V_81 == 1 )
V_80 &= ~ 0x10 ;
else if ( V_81 == 2 )
V_80 |= 0x10 ;
V_7 -> V_64 = ! ( V_80 & 0x10 ) ;
if ( ! ( V_80 & 0x20 ) )
V_80 &= 0xf7 ;
V_80 |= 0x40 ;
if ( V_80 != V_79 )
F_17 ( V_18 , V_54 , V_80 ) ;
F_2 ( & ( V_18 -> V_2 ) ) ;
if ( V_7 -> V_25 [ 0 ] == 0 )
V_7 -> V_30 &= ~ 0x20 ;
if ( V_7 -> V_25 [ 1 ] == 0 )
V_7 -> V_30 &= ~ 0x40 ;
V_7 -> V_28 &= V_7 -> V_30 ;
F_17 ( V_18 , V_29 , V_7 -> V_28 ) ;
}
static int F_65 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_12 ( V_18 ) ;
F_66 ( V_7 -> V_77 ) ;
F_62 ( & V_18 -> V_2 . V_61 , & V_62 ) ;
F_62 ( & V_18 -> V_2 . V_61 , & V_78 ) ;
F_63 ( V_7 ) ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , T_2 V_82 )
{
if ( ( V_82 >= 0x07 ) && ( V_82 <= 0x0c ) )
return F_67 ( F_68 ( V_18 , V_82 ) ) ;
else
return F_69 ( V_18 , V_82 ) ;
}
static int F_17 ( struct V_17 * V_18 , T_2 V_82 , T_4 V_83 )
{
if ( ( V_82 >= 0x07 ) && ( V_82 <= 0x0c ) )
return F_70 ( V_18 , V_82 , F_67 ( V_83 ) ) ;
else
return F_71 ( V_18 , V_82 , V_83 ) ;
}
static struct V_6 * F_2 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_84 , V_85 ;
F_14 ( & V_7 -> V_20 ) ;
if ( F_72 ( V_86 , V_7 -> V_87 + 2 * V_88 ) || ! V_7 -> V_89 ) {
F_50 ( & V_18 -> V_2 , L_6 ) ;
V_7 -> V_39 = F_18 ( V_18 , V_90 ) ;
V_7 -> V_28 = F_18 ( V_18 , V_29 ) ;
V_7 -> V_8 = F_18 ( V_18 , V_91 ) & 0x1f ;
for ( V_85 = 0 ; V_85 < 4 ; V_85 ++ ) {
V_7 -> V_13 [ V_85 ] = F_18 ( V_18 ,
V_92 [ V_85 ] ) ;
V_84 = F_18 ( V_18 , V_93 [ V_85 ] ) ;
V_7 -> V_14 [ V_85 ] = V_84 & 0xff ;
V_7 -> V_15 [ V_85 ] = ( V_84 >> 8 ) & 0xff ;
}
V_84 = F_18 ( V_18 , V_94 ) ;
V_7 -> V_23 [ 0 ] = ( V_84 >> 8 ) & 0xff ;
V_7 -> V_23 [ 1 ] = V_84 & 0xff ;
V_84 = F_18 ( V_18 , V_27 ) ;
V_7 -> V_25 [ 0 ] = ( V_84 >> 8 ) & 0xff ;
V_7 -> V_25 [ 1 ] = V_84 & 0xff ;
V_7 -> V_34 [ 0 ] = F_18 ( V_18 ,
V_95 [ 0 ] ) ;
V_7 -> V_35 [ 0 ] = F_18 ( V_18 ,
V_37 [ 0 ] ) ;
V_7 -> V_36 [ 0 ] = F_18 ( V_18 ,
V_38 [ 0 ] ) ;
V_84 = F_18 ( V_18 , V_32 ) ;
V_7 -> V_24 [ 0 ] = ( V_84 >> 6 ) & 0x03 ;
V_7 -> V_24 [ 1 ] = ( V_84 >> 4 ) & 0x03 ;
V_7 -> V_26 = ( V_84 >> 2 ) & 0x01 ;
V_7 -> V_39 &= V_7 -> V_30 ;
V_84 = F_18 ( V_18 , V_54 ) ;
V_7 -> V_40 = ! ( ( V_84 >> 2 ) & 1 ) ;
if ( V_7 -> V_64 ) {
V_7 -> V_34 [ 1 ] = F_18 ( V_18 ,
V_95 [ 1 ] ) ;
V_7 -> V_35 [ 1 ] = F_18 ( V_18 ,
V_37 [ 1 ] ) ;
V_7 -> V_36 [ 1 ] = F_18 ( V_18 ,
V_38 [ 1 ] ) ;
} else {
V_7 -> V_13 [ 4 ] = F_18 ( V_18 ,
V_92 [ 4 ] ) ;
V_7 -> V_14 [ 4 ] = F_18 ( V_18 ,
V_21 [ 4 ] ) ;
V_7 -> V_15 [ 4 ] = F_18 ( V_18 ,
V_22 [ 4 ] ) ;
}
V_7 -> V_87 = V_86 ;
V_7 -> V_89 = 1 ;
}
F_19 ( & V_7 -> V_20 ) ;
return V_7 ;
}
static int T_5 F_73 ( void )
{
return F_74 ( & V_96 ) ;
}
static void T_6 F_75 ( void )
{
F_76 ( & V_96 ) ;
}
