static inline T_1
F_1 ( long V_1 , int div )
{
if ( V_1 == 0 )
return 255 ;
V_1 = F_2 ( V_1 , 1 , 1000000 ) ;
return F_2 ( ( 1350000 + V_1 * div / 2 ) / ( V_1 * div ) , 1 , 254 ) ;
}
static inline long
F_3 ( T_1 V_2 , int div )
{
if ( V_2 == 0 )
return - 1 ;
if ( V_2 == 255 )
return 0 ;
return 1350000 / ( V_2 * div ) ;
}
static inline T_1
F_4 ( long V_2 , enum V_3 type )
{
int V_4 ;
V_2 = F_2 ( V_2 , 1 ,
( ( type == V_5
|| type == V_6 ) ? 8 : 128 ) ) >> 1 ;
for ( V_4 = 0 ; V_4 < 7 ; V_4 ++ ) {
if ( V_2 == 0 )
break;
V_2 >>= 1 ;
}
return V_4 ;
}
static T_2
F_5 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_17 = V_14 -> V_18 ;
T_4 V_2 ;
V_2 = F_8 ( V_11 , NULL , 10 ) ;
F_9 ( & V_16 -> V_19 ) ;
V_16 -> V_20 [ V_17 ] =
F_1 ( V_2 , F_10 ( V_16 -> V_21 [ V_17 ] ) ) ;
F_11 ( V_16 , F_12 ( V_17 ) ,
V_16 -> V_20 [ V_17 ] ) ;
F_13 ( & V_16 -> V_19 ) ;
return V_12 ;
}
static T_2
F_14 ( struct V_7 * V_8 , struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_1 , ( long ) F_16 ( V_16 -> V_22 , V_16 -> V_23 ) ) ;
}
static T_2
F_17 ( struct V_7 * V_8 , struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
return sprintf ( V_11 , L_1 , ( long ) V_16 -> V_23 ) ;
}
static T_2
F_18 ( struct V_7 * V_8 , struct V_9 * V_14 , const char * V_11 , T_3 V_12 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
T_4 V_2 ;
V_2 = F_8 ( V_11 , NULL , 10 ) ;
V_16 -> V_23 = V_2 ;
return V_12 ;
}
static T_2
F_19 ( struct V_7 * V_8 , struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_2 , V_16 -> V_24 ) ;
}
static T_2 F_20 ( struct V_7 * V_8 , struct V_9 * V_14 ,
char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
int V_25 = F_6 ( V_14 ) -> V_18 ;
return sprintf ( V_11 , L_2 , ( V_16 -> V_24 >> V_25 ) & 1 ) ;
}
static T_2 F_21 ( struct V_7 * V_8 ,
struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
int V_25 = ( V_16 -> type == V_5 ) ? 5 : 13 ;
return sprintf ( V_11 , L_2 , ( V_16 -> V_24 >> V_25 ) & 1 ) ;
}
static T_2 F_22 ( struct V_7 * V_8 , struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_1 ,
( long ) F_23 ( V_16 -> V_26 , V_16 -> type ) ) ;
}
static T_2
F_24 ( struct V_7 * V_8 , struct V_9 * V_14 ,
const char * V_11 , T_3 V_12 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
T_4 V_2 ;
V_2 = F_8 ( V_11 , NULL , 10 ) ;
F_9 ( & V_16 -> V_19 ) ;
V_16 -> V_26 &= 0x8000 ;
V_16 -> V_26 |= F_25 ( V_2 , V_16 -> type ) ;
F_11 ( V_16 , V_27 ,
V_16 -> V_26 & 0xff ) ;
F_11 ( V_16 , V_28 ,
( V_16 -> V_26 >> 8 ) & 0xff ) ;
if ( V_16 -> type != V_5 && V_16 -> type != V_6 ) {
F_11 ( V_16 , V_29 ,
( ( V_16 -> V_26 ) >> 16 ) & 0xff ) ;
}
F_13 ( & V_16 -> V_19 ) ;
return V_12 ;
}
static T_2 F_26 ( struct V_7 * V_8 , struct V_9 * V_14 ,
char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
int V_25 = F_6 ( V_14 ) -> V_18 ;
return sprintf ( V_11 , L_2 , ( V_16 -> V_26 >> V_25 ) & 1 ) ;
}
static T_2
F_27 ( struct V_7 * V_8 , struct V_9 * V_14 ,
const char * V_11 , T_3 V_12 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_25 = F_6 ( V_14 ) -> V_18 ;
unsigned long V_30 ;
T_1 V_31 ;
V_30 = F_8 ( V_11 , NULL , 10 ) ;
if ( V_30 & ~ 1 )
return - V_32 ;
F_9 ( & V_16 -> V_19 ) ;
if ( V_30 )
V_16 -> V_26 |= ( 1 << V_25 ) ;
else
V_16 -> V_26 &= ~ ( 1 << V_25 ) ;
if ( V_25 < 8 ) {
V_31 = F_28 ( V_16 , V_27 ) ;
if ( V_30 )
V_31 |= ( 1 << V_25 ) ;
else
V_31 &= ~ ( 1 << V_25 ) ;
F_11 ( V_16 , V_27 , V_31 ) ;
} else if ( V_25 < 16 ) {
V_31 = F_28 ( V_16 , V_28 ) ;
if ( V_30 )
V_31 |= ( 1 << ( V_25 - 8 ) ) ;
else
V_31 &= ~ ( 1 << ( V_25 - 8 ) ) ;
F_11 ( V_16 , V_28 , V_31 ) ;
} else {
V_31 = F_28 ( V_16 , V_29 ) ;
if ( V_30 )
V_31 |= ( 1 << ( V_25 - 16 ) ) ;
else
V_31 &= ~ ( 1 << ( V_25 - 16 ) ) ;
F_11 ( V_16 , V_29 , V_31 ) ;
}
F_13 ( & V_16 -> V_19 ) ;
return V_12 ;
}
static T_2 F_29 ( struct V_7 * V_8 ,
struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
int V_25 = ( V_16 -> type == V_5 ) ? 5 : 13 ;
return sprintf ( V_11 , L_2 , ( V_16 -> V_26 >> V_25 ) & 1 ) ;
}
static T_2
F_30 ( struct V_7 * V_8 , struct V_9 * V_10 , char * V_11 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_1 ,
( long ) F_10 ( V_16 -> V_21 [ V_14 -> V_18 ] ) ) ;
}
static T_2
F_31 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_7 ( V_8 ) ;
unsigned long V_33 ;
int V_17 = V_14 -> V_18 ;
T_1 V_31 ;
unsigned long V_2 = F_8 ( V_11 , NULL , 10 ) ;
F_9 ( & V_16 -> V_19 ) ;
V_33 = F_3 ( V_16 -> V_20 [ V_17 ] ,
F_10 ( V_16 -> V_21 [ V_17 ] ) ) ;
V_16 -> V_21 [ V_17 ] = F_4 ( V_2 , V_16 -> type ) ;
V_31 = ( F_28 ( V_16 , V_17 == 2 ? V_34 : V_35 )
& ( V_17 == 0 ? 0xcf : 0x3f ) )
| ( ( V_16 -> V_21 [ V_17 ] & 0x03 ) << ( V_17 == 0 ? 4 : 6 ) ) ;
F_11 ( V_16 , V_17 == 2 ? V_34 : V_35 , V_31 ) ;
if ( V_16 -> type != V_5 && V_16 -> type != V_6 ) {
V_31 = ( F_28 ( V_16 , V_36 )
& ~ ( 1 << ( 5 + V_17 ) ) )
| ( ( V_16 -> V_21 [ V_17 ] & 0x04 ) << ( 3 + V_17 ) ) ;
F_11 ( V_16 , V_36 , V_31 ) ;
}
V_16 -> V_20 [ V_17 ] = F_1 ( V_33 , F_10 ( V_16 -> V_21 [ V_17 ] ) ) ;
F_11 ( V_16 , F_12 ( V_17 ) , V_16 -> V_20 [ V_17 ] ) ;
F_13 ( & V_16 -> V_19 ) ;
return V_12 ;
}
static T_2
F_32 ( struct V_7 * V_8 , struct V_9 * V_10 , char * V_11 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_3 , ( int ) V_16 -> V_37 [ V_14 -> V_18 ] ) ;
}
static T_2
F_33 ( struct V_7 * V_8 , struct V_9 * V_10 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_3 , ( int ) V_16 -> V_38 ) ;
}
static T_2
F_34 ( struct V_7 * V_8 , struct V_9 * V_10 , const char * V_11 ,
T_3 V_12 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_17 = V_14 -> V_18 ;
T_4 V_2 ;
V_2 = F_8 ( V_11 , NULL , 10 ) ;
F_9 ( & V_16 -> V_19 ) ;
V_16 -> V_37 [ V_17 ] = F_2 ( V_2 , 0 , 255 ) ;
F_11 ( V_16 , V_39 [ V_17 ] , V_16 -> V_37 [ V_17 ] ) ;
F_13 ( & V_16 -> V_19 ) ;
return V_12 ;
}
static T_2
F_35 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
T_4 V_2 , V_31 ;
V_2 = F_8 ( V_11 , NULL , 10 ) ;
F_9 ( & V_16 -> V_19 ) ;
switch ( V_2 ) {
case 0 :
case 1 :
V_31 = F_28 ( V_16 , V_40 ) ;
F_11 ( V_16 , V_40 ,
( V_31 & 0xf7 ) | ( V_2 << 3 ) ) ;
V_31 = F_28 ( V_16 , V_41 ) ;
F_11 ( V_16 , V_41 ,
( V_31 & 0xef ) | ( ! V_2 << 4 ) ) ;
V_16 -> V_38 = V_2 ;
break;
default:
F_13 ( & V_16 -> V_19 ) ;
return - V_32 ;
}
F_13 ( & V_16 -> V_19 ) ;
return V_12 ;
}
static T_2
F_36 ( struct V_7 * V_8 , struct V_9 * V_10 , char * V_11 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_3 , ( int ) V_16 -> V_42 [ V_14 -> V_18 ] ) ;
}
static T_2
F_37 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_17 = V_14 -> V_18 ;
T_4 V_2 , V_43 ;
V_2 = F_8 ( V_11 , NULL , 10 ) ;
F_9 ( & V_16 -> V_19 ) ;
switch ( V_2 ) {
case 1 :
V_43 = F_28 ( V_16 , V_44 ) ;
F_11 ( V_16 , V_44 ,
V_43 | V_45 [ V_17 ] ) ;
V_43 = F_28 ( V_16 , V_46 ) ;
F_11 ( V_16 , V_46 ,
V_43 | V_47 [ V_17 ] ) ;
V_16 -> V_42 [ V_17 ] = V_2 ;
break;
case 2 :
V_43 = F_28 ( V_16 , V_44 ) ;
F_11 ( V_16 , V_44 ,
V_43 | V_45 [ V_17 ] ) ;
V_43 = F_28 ( V_16 , V_46 ) ;
F_11 ( V_16 , V_46 ,
V_43 & ~ V_47 [ V_17 ] ) ;
V_16 -> V_42 [ V_17 ] = V_2 ;
break;
case V_48 :
F_38 ( V_8 , L_4
L_5 , V_48 ) ;
case 4 :
V_43 = F_28 ( V_16 , V_44 ) ;
F_11 ( V_16 , V_44 ,
V_43 & ~ V_45 [ V_17 ] ) ;
V_16 -> V_42 [ V_17 ] = V_2 ;
break;
default:
F_39 ( V_8 , L_6 ,
( long ) V_2 ) ;
break;
}
F_13 ( & V_16 -> V_19 ) ;
return V_12 ;
}
static int
F_40 ( struct V_49 * V_50 )
{
int V_4 , V_51 = 0 , V_52 ;
int V_53 ;
int V_54 = V_50 -> V_55 ;
unsigned short V_56 [ 2 ] ;
struct V_57 * V_58 = V_50 -> V_58 ;
struct V_15 * V_16 = F_41 ( V_50 ) ;
enum V_3 V_59 = V_16 -> type ;
V_52 = F_42 ( V_58 ) ;
if ( V_60 [ 0 ] == V_52 && V_60 [ 1 ] == V_54 ) {
for ( V_4 = 2 ; V_4 <= 3 ; V_4 ++ ) {
if ( V_60 [ V_4 ] < 0x48 ||
V_60 [ V_4 ] > 0x4f ) {
F_39 ( & V_50 -> V_8 , L_7
L_8 ,
V_60 [ V_4 ] ) ;
V_53 = - V_32 ;
goto V_61;
}
}
F_11 ( V_16 , V_62 ,
( V_60 [ 2 ] & 0x07 ) |
( ( V_60 [ 3 ] & 0x07 ) << 4 ) ) ;
V_56 [ 0 ] = V_60 [ 2 ] ;
} else {
V_51 = F_28 ( V_16 , V_62 ) ;
V_56 [ 0 ] = 0x48 + ( V_51 & 0x07 ) ;
}
if ( V_59 != V_63 ) {
if ( V_60 [ 0 ] == V_52 &&
V_60 [ 1 ] == V_54 ) {
V_56 [ 1 ] = V_60 [ 3 ] ;
} else {
V_56 [ 1 ] = 0x48 + ( ( V_51 >> 4 ) & 0x07 ) ;
}
if ( V_56 [ 0 ] == V_56 [ 1 ] ) {
F_39 ( & V_50 -> V_8 ,
L_9 ,
V_56 [ 0 ] ) ;
V_53 = - V_64 ;
goto V_65;
}
}
for ( V_4 = 0 ; V_4 <= 1 ; V_4 ++ ) {
V_16 -> V_66 [ V_4 ] = F_43 ( V_58 , V_56 [ V_4 ] ) ;
if ( ! V_16 -> V_66 [ V_4 ] ) {
F_39 ( & V_50 -> V_8 , L_10
L_11
L_12 , V_4 , V_56 [ V_4 ] ) ;
V_53 = - V_67 ;
if ( V_4 == 1 )
goto V_68;
goto V_65;
}
if ( V_59 == V_63 )
break;
}
return 0 ;
V_68:
F_44 ( V_16 -> V_66 [ 0 ] ) ;
V_65:
V_61:
return V_53 ;
}
static int
F_45 ( struct V_7 * V_8 , int V_59 , int V_69 )
{
int V_53 ;
if ( ( V_53 = F_46 ( & V_8 -> V_70 , & V_71 ) ) )
return V_53 ;
if ( V_59 != V_63 ) {
if ( ( V_53 = F_47 ( V_8 ,
& V_72 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_74 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_75 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_76 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_77 . V_73 ) ) )
return V_53 ;
}
if ( V_59 != V_6 && V_59 != V_5 && V_59 != V_63 ) {
if ( ( V_53 = F_47 ( V_8 ,
& V_78 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_79 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_80 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_81 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_82 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_83 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_84 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_85 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_86 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_87 . V_73 ) ) )
return V_53 ;
}
if ( V_59 != V_63 ) {
if ( ( V_53 = F_47 ( V_8 ,
& V_88 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_89 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_90 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_91 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_92 . V_73 ) ) )
return V_53 ;
if ( V_59 != V_5 ) {
V_53 = F_48 ( & V_8 -> V_70 ,
& V_91 . V_73 . V_14 ,
V_93 | V_94 ) ;
if ( V_53 )
return V_53 ;
}
}
if ( V_59 != V_5 && V_59 != V_6 ) {
if ( ( V_53 = F_47 ( V_8 ,
& V_95 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_96 . V_73 ) )
|| ( V_53 = F_47 ( V_8 , & V_97 ) ) )
return V_53 ;
}
if ( V_59 == V_98 && ! V_69 ) {
if ( ( V_53 = F_47 ( V_8 ,
& V_99 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_100 . V_73 ) ) )
return V_53 ;
}
if ( V_59 != V_6 && V_59 != V_5 ) {
if ( ( V_53 = F_47 ( V_8 ,
& V_101 . V_73 ) )
|| ( V_53 = F_47 ( V_8 ,
& V_102 . V_73 ) ) )
return V_53 ;
if ( V_59 != V_63 ) {
if ( ( V_53 = F_47 ( V_8 ,
& V_103 . V_73 ) ) )
return V_53 ;
}
}
return 0 ;
}
static int
F_49 ( struct V_49 * V_104 , struct V_105 * V_106 )
{
int V_51 , V_107 ;
struct V_15 * V_108 = F_50 () ;
struct V_57 * V_58 = V_104 -> V_58 ;
int V_54 = V_104 -> V_55 ;
const char * V_109 ;
enum T_5 { V_110 , V_111 } V_112 ;
if ( ! F_51 ( V_58 , V_113 ) )
return - V_114 ;
if ( V_108 )
F_9 ( & V_108 -> V_19 ) ;
if ( F_52 ( V_104 , V_115 ) & 0x80 ) {
F_53 ( & V_58 -> V_8 ,
L_13 ) ;
goto V_116;
}
V_51 = F_52 ( V_104 , V_117 ) ;
V_107 = F_52 ( V_104 , V_118 ) ;
if ( ! ( V_51 & 0x07 ) &&
( ( ! ( V_51 & 0x80 ) && V_107 != 0xa3 && V_107 != 0xc3 ) ||
( ( V_51 & 0x80 ) && V_107 != 0x5c && V_107 != 0x12 ) ) ) {
F_53 ( & V_58 -> V_8 ,
L_14 ) ;
goto V_116;
}
if ( ( ! ( V_51 & 0x80 ) && V_107 == 0xa3 ) ||
( ( V_51 & 0x80 ) && V_107 == 0x5c ) ) {
if ( F_52 ( V_104 , V_119 )
!= V_54 ) {
F_53 ( & V_58 -> V_8 ,
L_15 ) ;
goto V_116;
}
}
F_54 ( V_104 , V_117 ,
( F_52 ( V_104 , V_117 )
& 0x78 ) | 0x80 ) ;
V_107 = F_52 ( V_104 , V_118 ) ;
if ( V_107 == 0x5c )
V_112 = V_110 ;
else if ( V_107 == 0x12 )
V_112 = V_111 ;
else {
F_53 ( & V_58 -> V_8 ,
L_16 ) ;
goto V_116;
}
V_51 = F_52 ( V_104 , V_120 ) ;
if ( ( V_51 == 0x10 || V_51 == 0x11 ) && V_112 == V_110 )
V_109 = L_17 ;
else if ( V_51 == 0x30 && V_112 == V_110 )
V_109 = L_18 ;
else if ( V_51 == 0x40 && V_112 == V_110 && V_54 == 0x2d )
V_109 = L_19 ;
else if ( V_51 == 0x31 )
V_109 = L_20 ;
else
goto V_116;
if ( V_51 <= 0x30 && F_55 ( V_104 , V_51 ) ) {
F_53 ( & V_58 -> V_8 , L_21
L_22 , V_54 ) ;
goto V_116;
}
if ( V_108 )
F_13 ( & V_108 -> V_19 ) ;
F_56 ( V_106 -> type , V_109 , V_121 ) ;
return 0 ;
V_116:
if ( V_108 )
F_13 ( & V_108 -> V_19 ) ;
return - V_114 ;
}
static int
F_57 ( struct V_49 * V_104 , const struct V_122 * V_52 )
{
struct V_7 * V_8 = & V_104 -> V_8 ;
struct V_15 * V_16 ;
int V_53 ;
V_16 = F_58 ( sizeof( struct V_15 ) , V_123 ) ;
if ( ! V_16 ) {
V_53 = - V_67 ;
goto V_124;
}
F_59 ( V_104 , V_16 ) ;
F_60 ( & V_16 -> V_125 ) ;
F_60 ( & V_16 -> V_19 ) ;
V_16 -> type = V_52 -> V_126 ;
V_16 -> V_104 = V_104 ;
V_53 = F_40 ( V_104 ) ;
if ( V_53 )
goto V_127;
F_61 ( V_8 ) ;
V_53 = F_45 ( V_8 , V_16 -> type , 0 ) ;
if ( V_53 )
goto V_128;
V_16 -> V_129 = F_62 ( V_8 ) ;
if ( F_63 ( V_16 -> V_129 ) ) {
V_53 = F_64 ( V_16 -> V_129 ) ;
goto V_128;
}
return 0 ;
V_128:
F_65 ( & V_8 -> V_70 , & V_71 ) ;
F_65 ( & V_8 -> V_70 , & V_130 ) ;
if ( V_16 -> V_66 [ 0 ] )
F_44 ( V_16 -> V_66 [ 0 ] ) ;
if ( V_16 -> V_66 [ 1 ] )
F_44 ( V_16 -> V_66 [ 1 ] ) ;
V_127:
F_66 ( V_16 ) ;
V_124:
return V_53 ;
}
static int
F_67 ( struct V_49 * V_104 )
{
struct V_15 * V_16 = F_41 ( V_104 ) ;
struct V_7 * V_8 = & V_104 -> V_8 ;
F_68 ( V_16 -> V_129 ) ;
F_65 ( & V_8 -> V_70 , & V_71 ) ;
F_65 ( & V_8 -> V_70 , & V_130 ) ;
if ( V_16 -> V_66 [ 0 ] )
F_44 ( V_16 -> V_66 [ 0 ] ) ;
if ( V_16 -> V_66 [ 1 ] )
F_44 ( V_16 -> V_66 [ 1 ] ) ;
F_66 ( V_16 ) ;
return 0 ;
}
static int
F_69 ( struct V_15 * V_16 , T_6 V_31 )
{
struct V_49 * V_104 = V_16 -> V_104 ;
int V_131 , V_132 ;
struct V_49 * V_133 ;
V_132 = ( V_31 >> 8 ) & 0x0f ;
if ( V_132 > 2 )
F_54 ( V_104 , V_117 ,
V_132 ) ;
if ( V_132 == 0 || V_132 > 2 ) {
V_131 = F_52 ( V_104 , V_31 & 0xff ) ;
} else {
V_133 = V_16 -> V_66 [ V_132 - 1 ] ;
switch ( V_31 & 0xff ) {
case 0x50 :
V_131 = F_70 ( F_71 ( V_133 , 0 ) ) ;
break;
case 0x52 :
V_131 = F_52 ( V_133 , 1 ) ;
break;
case 0x53 :
V_131 = F_70 ( F_71 ( V_133 , 2 ) ) ;
break;
case 0x55 :
default:
V_131 = F_70 ( F_71 ( V_133 , 3 ) ) ;
break;
}
}
if ( V_132 > 2 )
F_54 ( V_104 , V_117 , 0 ) ;
return V_131 ;
}
static int
F_72 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_134 )
{
struct V_49 * V_104 = V_16 -> V_104 ;
int V_132 ;
struct V_49 * V_133 ;
V_132 = ( V_31 >> 8 ) & 0x0f ;
if ( V_132 > 2 )
F_54 ( V_104 , V_117 ,
V_132 ) ;
if ( V_132 == 0 || V_132 > 2 ) {
F_54 ( V_104 , V_31 & 0xff ,
V_134 & 0xff ) ;
} else {
V_133 = V_16 -> V_66 [ V_132 - 1 ] ;
switch ( V_31 & 0xff ) {
case 0x52 :
F_54 ( V_133 , 1 , V_134 & 0xff ) ;
break;
case 0x53 :
F_73 ( V_133 , 2 , F_70 ( V_134 ) ) ;
break;
case 0x55 :
F_73 ( V_133 , 3 , F_70 ( V_134 ) ) ;
break;
}
}
if ( V_132 > 2 )
F_54 ( V_104 , V_117 , 0 ) ;
return 0 ;
}
static void
F_61 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_4 , V_135 ;
int type = V_16 -> type ;
T_1 V_43 ;
if ( V_136 && type != V_6 ) {
F_74 ( V_8 , L_23
L_24 ) ;
V_4 = F_28 ( V_16 , V_41 ) ;
V_135 = F_28 ( V_16 , V_40 ) ;
F_11 ( V_16 , V_115 , 0x80 ) ;
F_11 ( V_16 , V_41 , V_4 | 0x80 ) ;
F_11 ( V_16 , V_40 , V_135 ) ;
F_11 ( V_16 , V_28 , 0 ) ;
}
if ( V_137 && ! V_136 && type != V_6 ) {
V_4 = F_28 ( V_16 , V_41 ) ;
F_11 ( V_16 , V_41 , V_4 | 0x80 ) ;
}
V_16 -> V_23 = F_75 () ;
if ( ( type != V_5 ) && ( type != V_6 ) ) {
V_43 = F_28 ( V_16 , V_44 ) ;
for ( V_4 = 1 ; V_4 <= 3 ; V_4 ++ ) {
if ( ! ( V_43 & V_45 [ V_4 - 1 ] ) ) {
V_16 -> V_42 [ V_4 - 1 ] = 4 ;
} else {
if ( F_28
( V_16 ,
V_46 ) & V_47 [ V_4 - 1 ] )
V_16 -> V_42 [ V_4 - 1 ] = 1 ;
else
V_16 -> V_42 [ V_4 - 1 ] = 2 ;
}
if ( type == V_63 && V_4 == 2 )
break;
}
}
if ( V_137 && type != V_6 ) {
V_43 = F_28 ( V_16 , V_138 ) ;
if ( V_43 & 0x01 ) {
F_38 ( V_8 , L_25
L_26 ) ;
F_11 ( V_16 , V_138 ,
V_43 & 0xfe ) ;
}
if ( type != V_63 ) {
V_43 = F_28 ( V_16 ,
V_139 ) ;
if ( V_43 & 0x01 ) {
F_38 ( V_8 , L_27
L_28 ) ;
F_11 ( V_16 ,
V_139 , V_43 & 0xfe ) ;
}
}
}
F_11 ( V_16 , V_115 ,
( F_28 ( V_16 ,
V_115 ) & 0xf7 )
| 0x01 ) ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
V_16 -> V_20 [ V_4 ] = F_28 ( V_16 ,
F_12 ( V_4 ) ) ;
}
F_60 ( & V_16 -> V_19 ) ;
}
static struct V_15 * F_15 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
struct V_49 * V_104 = V_16 -> V_104 ;
int V_4 ;
F_9 ( & V_16 -> V_19 ) ;
if ( F_76 ( V_140 , V_16 -> V_141 + V_142 + V_142 / 2 )
|| ! V_16 -> V_143 ) {
F_53 ( V_8 , L_29 ) ;
for ( V_4 = 0 ; V_4 <= 8 ; V_4 ++ ) {
if ( V_16 -> type == V_63 && V_4 == 1 )
continue;
V_16 -> V_144 [ V_4 ] =
F_28 ( V_16 , F_77 ( V_4 ) ) ;
V_16 -> V_145 [ V_4 ] =
F_28 ( V_16 , F_78 ( V_4 ) ) ;
V_16 -> V_146 [ V_4 ] =
F_28 ( V_16 , F_79 ( V_4 ) ) ;
if ( ( V_16 -> type != V_98 ) && ( V_4 == 6 ) )
break;
}
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
V_16 -> V_147 [ V_4 ] =
F_28 ( V_16 , F_80 ( V_4 ) ) ;
V_16 -> V_20 [ V_4 ] =
F_28 ( V_16 , F_12 ( V_4 ) ) ;
}
if ( V_16 -> type != V_5 && V_16 -> type != V_6 ) {
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
V_16 -> V_37 [ V_4 ] =
F_28 ( V_16 ,
V_39 [ V_4 ] ) ;
if ( ( V_16 -> type != V_98 || ! V_104 )
&& V_4 == 1 )
break;
}
V_16 -> V_38 = ( F_28 ( V_16 ,
V_40 ) & 0x08 ) >> 3 ;
}
V_16 -> V_148 = F_28 ( V_16 , F_81 ( 1 ) ) ;
V_16 -> V_149 =
F_28 ( V_16 , F_82 ( 1 ) ) ;
V_16 -> V_150 =
F_28 ( V_16 , F_83 ( 1 ) ) ;
V_16 -> V_151 [ 0 ] =
F_28 ( V_16 , F_81 ( 2 ) ) ;
V_16 -> V_152 [ 0 ] =
F_28 ( V_16 , F_82 ( 2 ) ) ;
V_16 -> V_153 [ 0 ] =
F_28 ( V_16 , F_83 ( 2 ) ) ;
if ( V_16 -> type != V_63 ) {
V_16 -> V_151 [ 1 ] =
F_28 ( V_16 , F_81 ( 3 ) ) ;
V_16 -> V_152 [ 1 ] =
F_28 ( V_16 ,
F_82 ( 3 ) ) ;
V_16 -> V_153 [ 1 ] =
F_28 ( V_16 ,
F_83 ( 3 ) ) ;
}
V_4 = F_28 ( V_16 , V_35 ) ;
V_16 -> V_22 = V_4 & 0x0f ;
V_16 -> V_22 |= ( F_28 ( V_16 ,
V_154 ) & 0x01 ) << 4 ;
V_16 -> V_21 [ 0 ] = ( V_4 >> 4 ) & 0x03 ;
V_16 -> V_21 [ 1 ] = ( V_4 >> 6 ) & 0x03 ;
V_16 -> V_21 [ 2 ] = ( F_28 ( V_16 ,
V_34 ) >> 6 ) & 0x03 ;
if ( ( V_16 -> type != V_5 ) && ( V_16 -> type != V_6 ) ) {
V_4 = F_28 ( V_16 , V_36 ) ;
V_16 -> V_21 [ 0 ] |= ( V_4 >> 3 ) & 0x04 ;
V_16 -> V_21 [ 1 ] |= ( V_4 >> 4 ) & 0x04 ;
V_16 -> V_21 [ 2 ] |= ( V_4 >> 5 ) & 0x04 ;
}
if ( V_16 -> type == V_98 ) {
V_16 -> V_24 = F_28 ( V_16 ,
V_155 )
| ( F_28 ( V_16 ,
V_156 ) << 8 )
| ( F_28 ( V_16 ,
V_157 ) << 16 ) ;
} else if ( V_16 -> type == V_63 ) {
V_16 -> V_24 = F_28 ( V_16 ,
V_155 )
| ( F_28 ( V_16 ,
V_156 ) << 8 ) ;
} else {
V_16 -> V_24 = F_28 ( V_16 ,
V_158 )
| ( F_28 ( V_16 ,
V_159 ) << 8 ) ;
}
V_4 = F_28 ( V_16 , V_28 ) ;
V_16 -> V_26 = ( V_4 << 8 ) +
F_28 ( V_16 , V_27 ) ;
if ( ( V_16 -> type != V_5 ) && ( V_16 -> type != V_6 ) ) {
V_16 -> V_26 |=
F_28 ( V_16 ,
V_29 ) << 16 ;
}
V_16 -> V_141 = V_140 ;
V_16 -> V_143 = 1 ;
}
F_13 ( & V_16 -> V_19 ) ;
return V_16 ;
}
static T_2
F_84 ( struct V_7 * V_8 , struct V_9 * V_160 , char * V_11 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
return sprintf ( V_11 , L_30 , V_16 -> V_161 ) ;
}
static struct V_15 * F_50 ( void )
{
return V_162 ? F_85 ( V_162 ) : NULL ;
}
static int F_55 ( struct V_49 * V_104 , T_1 V_163 )
{
struct V_15 * V_108 ;
int V_4 ;
if ( ! V_162 )
return 0 ;
V_108 = F_85 ( V_162 ) ;
if ( F_28 ( V_108 , V_119 ) != V_104 -> V_55 )
return 0 ;
if ( F_28 ( V_108 , V_120 ) != V_163 )
return 0 ;
for ( V_4 = 0x2b ; V_4 <= 0x3d ; V_4 ++ ) {
if ( F_28 ( V_108 , V_4 ) !=
F_52 ( V_104 , V_4 ) )
return 0 ;
}
if ( F_28 ( V_108 , V_115 ) !=
F_52 ( V_104 , V_115 ) )
return 0 ;
for ( V_4 = 0x43 ; V_4 <= 0x46 ; V_4 ++ ) {
if ( F_28 ( V_108 , V_4 ) !=
F_52 ( V_104 , V_4 ) )
return 0 ;
}
return 1 ;
}
static int
F_86 ( struct V_15 * V_16 , T_6 V_31 )
{
int V_164 , V_131 ;
V_164 = ( ( ( V_31 & 0xff00 ) == 0x100 )
|| ( ( V_31 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_31 & 0x00ff ) == 0x50 )
|| ( ( V_31 & 0x00ff ) == 0x53 )
|| ( ( V_31 & 0x00ff ) == 0x55 ) ) ;
if ( V_31 & 0xff00 ) {
F_87 ( V_117 ,
V_16 -> V_165 + V_166 ) ;
F_87 ( V_31 >> 8 ,
V_16 -> V_165 + V_167 ) ;
}
F_87 ( V_31 & 0xff , V_16 -> V_165 + V_166 ) ;
V_131 = F_88 ( V_16 -> V_165 + V_167 ) ;
if ( V_164 ) {
F_87 ( ( V_31 & 0xff ) + 1 ,
V_16 -> V_165 + V_166 ) ;
V_131 =
( V_131 << 8 ) + F_88 ( V_16 -> V_165 +
V_167 ) ;
}
if ( V_31 & 0xff00 ) {
F_87 ( V_117 ,
V_16 -> V_165 + V_166 ) ;
F_87 ( 0 , V_16 -> V_165 + V_167 ) ;
}
return V_131 ;
}
static void
F_89 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_134 )
{
int V_164 ;
V_164 = ( ( ( V_31 & 0xff00 ) == 0x100 )
|| ( ( V_31 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_31 & 0x00ff ) == 0x53 )
|| ( ( V_31 & 0x00ff ) == 0x55 ) ) ;
if ( V_31 & 0xff00 ) {
F_87 ( V_117 ,
V_16 -> V_165 + V_166 ) ;
F_87 ( V_31 >> 8 ,
V_16 -> V_165 + V_167 ) ;
}
F_87 ( V_31 & 0xff , V_16 -> V_165 + V_166 ) ;
if ( V_164 ) {
F_87 ( V_134 >> 8 ,
V_16 -> V_165 + V_167 ) ;
F_87 ( ( V_31 & 0xff ) + 1 ,
V_16 -> V_165 + V_166 ) ;
}
F_87 ( V_134 & 0xff , V_16 -> V_165 + V_167 ) ;
if ( V_31 & 0xff00 ) {
F_87 ( V_117 ,
V_16 -> V_165 + V_166 ) ;
F_87 ( 0 , V_16 -> V_165 + V_167 ) ;
}
}
static int
F_28 ( struct V_15 * V_16 , T_6 V_31 )
{
struct V_49 * V_104 = V_16 -> V_104 ;
int V_131 ;
F_9 ( & V_16 -> V_125 ) ;
if ( V_104 )
V_131 = F_69 ( V_16 , V_31 ) ;
else
V_131 = F_86 ( V_16 , V_31 ) ;
F_13 ( & V_16 -> V_125 ) ;
return V_131 ;
}
static int
F_11 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_134 )
{
struct V_49 * V_104 = V_16 -> V_104 ;
F_9 ( & V_16 -> V_125 ) ;
if ( V_104 )
F_72 ( V_16 , V_31 , V_134 ) ;
else
F_89 ( V_16 , V_31 , V_134 ) ;
F_13 ( & V_16 -> V_125 ) ;
return 0 ;
}
static int T_7
F_90 ( struct V_168 * V_162 )
{
int V_53 , V_31 ;
struct V_15 * V_16 ;
struct V_169 * V_131 ;
V_131 = F_91 ( V_162 , V_170 , 0 ) ;
if ( ! F_92 ( V_131 -> V_171 + V_166 , 2 ,
L_17 ) ) {
V_53 = - V_64 ;
goto exit;
}
V_16 = F_58 ( sizeof( struct V_15 ) , V_123 ) ;
if ( ! V_16 ) {
V_53 = - V_67 ;
goto V_172;
}
F_60 ( & V_16 -> V_125 ) ;
V_16 -> V_165 = V_131 -> V_171 ;
F_93 ( V_162 , V_16 ) ;
V_31 = F_28 ( V_16 , V_120 ) ;
switch ( V_31 ) {
case 0x30 :
V_16 -> type = V_98 ;
V_16 -> V_161 = L_18 ;
break;
default:
V_16 -> type = V_5 ;
V_16 -> V_161 = L_17 ;
}
F_61 ( & V_162 -> V_8 ) ;
V_53 = F_45 ( & V_162 -> V_8 , V_16 -> type , 1 ) ;
if ( V_53 )
goto V_173;
V_53 = F_47 ( & V_162 -> V_8 , & V_174 ) ;
if ( V_53 )
goto V_173;
V_16 -> V_129 = F_62 ( & V_162 -> V_8 ) ;
if ( F_63 ( V_16 -> V_129 ) ) {
V_53 = F_64 ( V_16 -> V_129 ) ;
goto V_173;
}
return 0 ;
V_173:
F_65 ( & V_162 -> V_8 . V_70 , & V_71 ) ;
F_65 ( & V_162 -> V_8 . V_70 , & V_130 ) ;
F_94 ( & V_162 -> V_8 , & V_174 ) ;
F_66 ( V_16 ) ;
V_172:
F_95 ( V_131 -> V_171 + V_166 , 2 ) ;
exit:
return V_53 ;
}
static int T_8
F_96 ( struct V_168 * V_162 )
{
struct V_15 * V_16 = F_85 ( V_162 ) ;
F_68 ( V_16 -> V_129 ) ;
F_65 ( & V_162 -> V_8 . V_70 , & V_71 ) ;
F_65 ( & V_162 -> V_8 . V_70 , & V_130 ) ;
F_94 ( & V_162 -> V_8 , & V_174 ) ;
F_95 ( V_16 -> V_165 + V_166 , 2 ) ;
F_66 ( V_16 ) ;
return 0 ;
}
static int T_9
F_97 ( unsigned short V_54 )
{
int V_2 , V_175 , V_176 = 0 ;
int V_177 ;
for ( V_177 = V_54 ; V_177 < V_54 + V_178 ; V_177 ++ ) {
if ( ! F_92 ( V_177 , 1 , L_17 ) ) {
F_98 ( L_31 , V_177 ) ;
goto V_179;
}
}
#define F_99
V_2 = F_88 ( V_54 + 1 ) ;
if ( F_88 ( V_54 + 2 ) != V_2
|| F_88 ( V_54 + 3 ) != V_2
|| F_88 ( V_54 + 7 ) != V_2 ) {
F_98 ( L_32 , 1 ) ;
goto V_179;
}
#undef F_99
V_175 = F_88 ( V_54 + V_166 ) ;
if ( V_175 & 0x80 ) {
F_98 ( L_32 , 2 ) ;
goto V_179;
}
V_2 = ~ V_175 & 0x7f ;
F_87 ( V_2 , V_54 + V_166 ) ;
if ( F_88 ( V_54 + V_166 ) != ( V_2 | 0x80 ) ) {
F_87 ( V_175 , V_54 + V_166 ) ;
F_98 ( L_32 , 3 ) ;
goto V_179;
}
F_87 ( V_115 , V_54 + V_166 ) ;
V_2 = F_88 ( V_54 + V_167 ) ;
if ( V_2 & 0x80 ) {
F_98 ( L_32 , 4 ) ;
goto V_179;
}
F_87 ( V_117 , V_54 + V_166 ) ;
V_175 = F_88 ( V_54 + V_167 ) ;
F_87 ( V_118 , V_54 + V_166 ) ;
V_2 = F_88 ( V_54 + V_167 ) ;
if ( ( ! ( V_175 & 0x80 ) && ( V_2 != 0xa3 ) )
|| ( ( V_175 & 0x80 ) && ( V_2 != 0x5c ) ) ) {
F_98 ( L_32 , 5 ) ;
goto V_179;
}
F_87 ( V_119 , V_54 + V_166 ) ;
V_2 = F_88 ( V_54 + V_167 ) ;
if ( V_2 < 0x03 || V_2 > 0x77 ) {
F_98 ( L_32 , 6 ) ;
goto V_179;
}
if ( F_88 ( V_54 + V_166 ) & 0x80 ) {
F_98 ( L_32 , 7 ) ;
goto V_179;
}
F_87 ( V_117 , V_54 + V_166 ) ;
V_175 = F_88 ( V_54 + V_167 ) ;
F_87 ( V_175 & 0xf8 , V_54 + V_167 ) ;
F_87 ( V_120 , V_54 + V_166 ) ;
V_2 = F_88 ( V_54 + V_167 ) ;
if ( ( V_2 & 0xfe ) == 0x10
|| V_2 == 0x30 )
V_176 = 1 ;
if ( V_176 )
F_100 ( L_33 ,
V_2 == 0x30 ? L_34 : L_35 , ( int ) V_54 ) ;
V_179:
for ( V_177 -- ; V_177 >= V_54 ; V_177 -- )
F_95 ( V_177 , 1 ) ;
return V_176 ;
}
static int T_9
F_101 ( unsigned short V_54 )
{
struct V_169 V_131 = {
. V_171 = V_54 ,
. V_180 = V_54 + V_178 - 1 ,
. V_161 = L_17 ,
. V_181 = V_170 ,
} ;
int V_53 ;
V_162 = F_102 ( L_17 , V_54 ) ;
if ( ! V_162 ) {
V_53 = - V_67 ;
F_103 ( L_36 ) ;
goto exit;
}
V_53 = F_104 ( V_162 , & V_131 , 1 ) ;
if ( V_53 ) {
F_103 ( L_37 , V_53 ) ;
goto V_182;
}
V_53 = F_105 ( V_162 ) ;
if ( V_53 ) {
F_103 ( L_38 , V_53 ) ;
goto V_182;
}
return 0 ;
V_182:
F_106 ( V_162 ) ;
exit:
V_162 = NULL ;
return V_53 ;
}
static int T_9
F_107 ( void )
{
int V_131 ;
if ( F_97 ( V_183 ) ) {
V_131 = F_108 ( & V_184 ) ;
if ( V_131 )
goto exit;
V_131 = F_101 ( V_183 ) ;
if ( V_131 )
goto V_185;
}
return 0 ;
V_185:
F_109 ( & V_184 ) ;
exit:
return V_131 ;
}
static void
F_110 ( void )
{
if ( V_162 ) {
F_111 ( V_162 ) ;
F_109 ( & V_184 ) ;
}
}
static struct V_15 * F_50 ( void )
{
return NULL ;
}
static int
F_55 ( struct V_49 * V_104 , T_1 V_163 )
{
return 0 ;
}
static int
F_28 ( struct V_15 * V_16 , T_6 V_31 )
{
int V_131 ;
F_9 ( & V_16 -> V_125 ) ;
V_131 = F_69 ( V_16 , V_31 ) ;
F_13 ( & V_16 -> V_125 ) ;
return V_131 ;
}
static int
F_11 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_134 )
{
F_9 ( & V_16 -> V_125 ) ;
F_72 ( V_16 , V_31 , V_134 ) ;
F_13 ( & V_16 -> V_125 ) ;
return 0 ;
}
static int T_9
F_107 ( void )
{
return 0 ;
}
static void
F_110 ( void )
{
}
static int T_9
F_112 ( void )
{
int V_131 ;
V_131 = F_107 () ;
if ( V_131 )
goto exit;
V_131 = F_113 ( & V_186 ) ;
if ( V_131 )
goto V_187;
return 0 ;
V_187:
F_110 () ;
exit:
return V_131 ;
}
static void T_10
F_114 ( void )
{
F_110 () ;
F_115 ( & V_186 ) ;
}
