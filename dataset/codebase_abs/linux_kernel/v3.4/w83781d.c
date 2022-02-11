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
unsigned long V_2 ;
int V_19 ;
V_19 = F_8 ( V_11 , 10 , & V_2 ) ;
if ( V_19 )
return V_19 ;
F_9 ( & V_16 -> V_20 ) ;
V_16 -> V_21 [ V_17 ] =
F_1 ( V_2 , F_10 ( V_16 -> V_22 [ V_17 ] ) ) ;
F_11 ( V_16 , F_12 ( V_17 ) ,
V_16 -> V_21 [ V_17 ] ) ;
F_13 ( & V_16 -> V_20 ) ;
return V_12 ;
}
static T_2
F_14 ( struct V_7 * V_8 , struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_1 , ( long ) F_16 ( V_16 -> V_23 , V_16 -> V_24 ) ) ;
}
static T_2
F_17 ( struct V_7 * V_8 , struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
return sprintf ( V_11 , L_1 , ( long ) V_16 -> V_24 ) ;
}
static T_2
F_18 ( struct V_7 * V_8 , struct V_9 * V_14 ,
const char * V_11 , T_3 V_12 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
unsigned long V_2 ;
int V_19 ;
V_19 = F_8 ( V_11 , 10 , & V_2 ) ;
if ( V_19 )
return V_19 ;
V_16 -> V_24 = F_2 ( V_2 , 0 , 255 ) ;
return V_12 ;
}
static T_2
F_19 ( struct V_7 * V_8 , struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_2 , V_16 -> V_25 ) ;
}
static T_2 F_20 ( struct V_7 * V_8 , struct V_9 * V_14 ,
char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
int V_26 = F_6 ( V_14 ) -> V_18 ;
return sprintf ( V_11 , L_2 , ( V_16 -> V_25 >> V_26 ) & 1 ) ;
}
static T_2 F_21 ( struct V_7 * V_8 ,
struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
int V_26 = ( V_16 -> type == V_5 ) ? 5 : 13 ;
return sprintf ( V_11 , L_2 , ( V_16 -> V_25 >> V_26 ) & 1 ) ;
}
static T_2 F_22 ( struct V_7 * V_8 ,
struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_1 ,
( long ) F_23 ( V_16 -> V_27 , V_16 -> type ) ) ;
}
static T_2
F_24 ( struct V_7 * V_8 , struct V_9 * V_14 ,
const char * V_11 , T_3 V_12 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
unsigned long V_2 ;
int V_19 ;
V_19 = F_8 ( V_11 , 10 , & V_2 ) ;
if ( V_19 )
return V_19 ;
F_9 ( & V_16 -> V_20 ) ;
V_16 -> V_27 &= 0x8000 ;
V_16 -> V_27 |= F_25 ( V_2 , V_16 -> type ) ;
F_11 ( V_16 , V_28 ,
V_16 -> V_27 & 0xff ) ;
F_11 ( V_16 , V_29 ,
( V_16 -> V_27 >> 8 ) & 0xff ) ;
if ( V_16 -> type != V_5 && V_16 -> type != V_6 ) {
F_11 ( V_16 , V_30 ,
( ( V_16 -> V_27 ) >> 16 ) & 0xff ) ;
}
F_13 ( & V_16 -> V_20 ) ;
return V_12 ;
}
static T_2 F_26 ( struct V_7 * V_8 , struct V_9 * V_14 ,
char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
int V_26 = F_6 ( V_14 ) -> V_18 ;
return sprintf ( V_11 , L_2 , ( V_16 -> V_27 >> V_26 ) & 1 ) ;
}
static T_2
F_27 ( struct V_7 * V_8 , struct V_9 * V_14 ,
const char * V_11 , T_3 V_12 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_26 = F_6 ( V_14 ) -> V_18 ;
T_1 V_31 ;
unsigned long V_32 ;
int V_19 ;
V_19 = F_8 ( V_11 , 10 , & V_32 ) ;
if ( V_19 )
return V_19 ;
if ( V_32 & ~ 1 )
return - V_33 ;
F_9 ( & V_16 -> V_20 ) ;
if ( V_32 )
V_16 -> V_27 |= ( 1 << V_26 ) ;
else
V_16 -> V_27 &= ~ ( 1 << V_26 ) ;
if ( V_26 < 8 ) {
V_31 = F_28 ( V_16 , V_28 ) ;
if ( V_32 )
V_31 |= ( 1 << V_26 ) ;
else
V_31 &= ~ ( 1 << V_26 ) ;
F_11 ( V_16 , V_28 , V_31 ) ;
} else if ( V_26 < 16 ) {
V_31 = F_28 ( V_16 , V_29 ) ;
if ( V_32 )
V_31 |= ( 1 << ( V_26 - 8 ) ) ;
else
V_31 &= ~ ( 1 << ( V_26 - 8 ) ) ;
F_11 ( V_16 , V_29 , V_31 ) ;
} else {
V_31 = F_28 ( V_16 , V_30 ) ;
if ( V_32 )
V_31 |= ( 1 << ( V_26 - 16 ) ) ;
else
V_31 &= ~ ( 1 << ( V_26 - 16 ) ) ;
F_11 ( V_16 , V_30 , V_31 ) ;
}
F_13 ( & V_16 -> V_20 ) ;
return V_12 ;
}
static T_2 F_29 ( struct V_7 * V_8 ,
struct V_9 * V_14 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
int V_26 = ( V_16 -> type == V_5 ) ? 5 : 13 ;
return sprintf ( V_11 , L_2 , ( V_16 -> V_27 >> V_26 ) & 1 ) ;
}
static T_2
F_30 ( struct V_7 * V_8 , struct V_9 * V_10 , char * V_11 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_1 ,
( long ) F_10 ( V_16 -> V_22 [ V_14 -> V_18 ] ) ) ;
}
static T_2
F_31 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_7 ( V_8 ) ;
unsigned long V_34 ;
int V_17 = V_14 -> V_18 ;
T_1 V_31 ;
unsigned long V_2 ;
int V_19 ;
V_19 = F_8 ( V_11 , 10 , & V_2 ) ;
if ( V_19 )
return V_19 ;
F_9 ( & V_16 -> V_20 ) ;
V_34 = F_3 ( V_16 -> V_21 [ V_17 ] ,
F_10 ( V_16 -> V_22 [ V_17 ] ) ) ;
V_16 -> V_22 [ V_17 ] = F_4 ( V_2 , V_16 -> type ) ;
V_31 = ( F_28 ( V_16 , V_17 == 2 ?
V_35 : V_36 )
& ( V_17 == 0 ? 0xcf : 0x3f ) )
| ( ( V_16 -> V_22 [ V_17 ] & 0x03 ) << ( V_17 == 0 ? 4 : 6 ) ) ;
F_11 ( V_16 , V_17 == 2 ?
V_35 : V_36 , V_31 ) ;
if ( V_16 -> type != V_5 && V_16 -> type != V_6 ) {
V_31 = ( F_28 ( V_16 , V_37 )
& ~ ( 1 << ( 5 + V_17 ) ) )
| ( ( V_16 -> V_22 [ V_17 ] & 0x04 ) << ( 3 + V_17 ) ) ;
F_11 ( V_16 , V_37 , V_31 ) ;
}
V_16 -> V_21 [ V_17 ] = F_1 ( V_34 , F_10 ( V_16 -> V_22 [ V_17 ] ) ) ;
F_11 ( V_16 , F_12 ( V_17 ) , V_16 -> V_21 [ V_17 ] ) ;
F_13 ( & V_16 -> V_20 ) ;
return V_12 ;
}
static T_2
F_32 ( struct V_7 * V_8 , struct V_9 * V_10 , char * V_11 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_3 , ( int ) V_16 -> V_38 [ V_14 -> V_18 ] ) ;
}
static T_2
F_33 ( struct V_7 * V_8 , struct V_9 * V_10 , char * V_11 )
{
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_3 , ( int ) V_16 -> V_39 ) ;
}
static T_2
F_34 ( struct V_7 * V_8 , struct V_9 * V_10 , const char * V_11 ,
T_3 V_12 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_17 = V_14 -> V_18 ;
unsigned long V_2 ;
int V_19 ;
V_19 = F_8 ( V_11 , 10 , & V_2 ) ;
if ( V_19 )
return V_19 ;
F_9 ( & V_16 -> V_20 ) ;
V_16 -> V_38 [ V_17 ] = F_2 ( V_2 , 0 , 255 ) ;
F_11 ( V_16 , V_40 [ V_17 ] , V_16 -> V_38 [ V_17 ] ) ;
F_13 ( & V_16 -> V_20 ) ;
return V_12 ;
}
static T_2
F_35 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
unsigned long V_2 ;
T_4 V_31 ;
int V_19 ;
V_19 = F_8 ( V_11 , 10 , & V_2 ) ;
if ( V_19 )
return V_19 ;
F_9 ( & V_16 -> V_20 ) ;
switch ( V_2 ) {
case 0 :
case 1 :
V_31 = F_28 ( V_16 , V_41 ) ;
F_11 ( V_16 , V_41 ,
( V_31 & 0xf7 ) | ( V_2 << 3 ) ) ;
V_31 = F_28 ( V_16 , V_42 ) ;
F_11 ( V_16 , V_42 ,
( V_31 & 0xef ) | ( ! V_2 << 4 ) ) ;
V_16 -> V_39 = V_2 ;
break;
default:
F_13 ( & V_16 -> V_20 ) ;
return - V_33 ;
}
F_13 ( & V_16 -> V_20 ) ;
return V_12 ;
}
static T_2
F_36 ( struct V_7 * V_8 , struct V_9 * V_10 , char * V_11 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_15 ( V_8 ) ;
return sprintf ( V_11 , L_3 , ( int ) V_16 -> V_43 [ V_14 -> V_18 ] ) ;
}
static T_2
F_37 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_13 * V_14 = F_6 ( V_10 ) ;
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_17 = V_14 -> V_18 ;
unsigned long V_2 ;
T_4 V_44 ;
int V_19 ;
V_19 = F_8 ( V_11 , 10 , & V_2 ) ;
if ( V_19 )
return V_19 ;
F_9 ( & V_16 -> V_20 ) ;
switch ( V_2 ) {
case 1 :
V_44 = F_28 ( V_16 , V_45 ) ;
F_11 ( V_16 , V_45 ,
V_44 | V_46 [ V_17 ] ) ;
V_44 = F_28 ( V_16 , V_47 ) ;
F_11 ( V_16 , V_47 ,
V_44 | V_48 [ V_17 ] ) ;
V_16 -> V_43 [ V_17 ] = V_2 ;
break;
case 2 :
V_44 = F_28 ( V_16 , V_45 ) ;
F_11 ( V_16 , V_45 ,
V_44 | V_46 [ V_17 ] ) ;
V_44 = F_28 ( V_16 , V_47 ) ;
F_11 ( V_16 , V_47 ,
V_44 & ~ V_48 [ V_17 ] ) ;
V_16 -> V_43 [ V_17 ] = V_2 ;
break;
case V_49 :
F_38 ( V_8 , L_4
L_5 , V_49 ) ;
case 4 :
V_44 = F_28 ( V_16 , V_45 ) ;
F_11 ( V_16 , V_45 ,
V_44 & ~ V_46 [ V_17 ] ) ;
V_16 -> V_43 [ V_17 ] = V_2 ;
break;
default:
F_39 ( V_8 , L_6 ,
( long ) V_2 ) ;
break;
}
F_13 ( & V_16 -> V_20 ) ;
return V_12 ;
}
static int
F_40 ( struct V_50 * V_51 )
{
int V_4 , V_52 = 0 , V_53 ;
int V_19 ;
int V_54 = V_51 -> V_55 ;
unsigned short V_56 [ 2 ] ;
struct V_57 * V_58 = V_51 -> V_58 ;
struct V_15 * V_16 = F_41 ( V_51 ) ;
enum V_3 V_59 = V_16 -> type ;
V_53 = F_42 ( V_58 ) ;
if ( V_60 [ 0 ] == V_53 && V_60 [ 1 ] == V_54 ) {
for ( V_4 = 2 ; V_4 <= 3 ; V_4 ++ ) {
if ( V_60 [ V_4 ] < 0x48 ||
V_60 [ V_4 ] > 0x4f ) {
F_39 ( & V_51 -> V_8 , L_7
L_8 ,
V_60 [ V_4 ] ) ;
V_19 = - V_33 ;
goto V_61;
}
}
F_11 ( V_16 , V_62 ,
( V_60 [ 2 ] & 0x07 ) |
( ( V_60 [ 3 ] & 0x07 ) << 4 ) ) ;
V_56 [ 0 ] = V_60 [ 2 ] ;
} else {
V_52 = F_28 ( V_16 , V_62 ) ;
V_56 [ 0 ] = 0x48 + ( V_52 & 0x07 ) ;
}
if ( V_59 != V_63 ) {
if ( V_60 [ 0 ] == V_53 &&
V_60 [ 1 ] == V_54 ) {
V_56 [ 1 ] = V_60 [ 3 ] ;
} else {
V_56 [ 1 ] = 0x48 + ( ( V_52 >> 4 ) & 0x07 ) ;
}
if ( V_56 [ 0 ] == V_56 [ 1 ] ) {
F_39 ( & V_51 -> V_8 ,
L_9 ,
V_56 [ 0 ] ) ;
V_19 = - V_64 ;
goto V_65;
}
}
for ( V_4 = 0 ; V_4 <= 1 ; V_4 ++ ) {
V_16 -> V_66 [ V_4 ] = F_43 ( V_58 , V_56 [ V_4 ] ) ;
if ( ! V_16 -> V_66 [ V_4 ] ) {
F_39 ( & V_51 -> V_8 , L_10
L_11
L_12 , V_4 , V_56 [ V_4 ] ) ;
V_19 = - V_67 ;
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
return V_19 ;
}
static int
F_45 ( struct V_7 * V_8 , int V_59 , int V_69 )
{
int V_19 ;
V_19 = F_46 ( & V_8 -> V_70 , & V_71 ) ;
if ( V_19 )
return V_19 ;
if ( V_59 != V_63 ) {
V_19 = F_46 ( & V_8 -> V_70 , & V_72 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_59 != V_6 && V_59 != V_5 && V_59 != V_63 ) {
V_19 = F_46 ( & V_8 -> V_70 , & V_73 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_59 != V_63 ) {
V_19 = F_46 ( & V_8 -> V_70 , & V_74 ) ;
if ( V_19 )
return V_19 ;
if ( V_59 != V_5 ) {
V_19 = F_47 ( & V_8 -> V_70 ,
& V_75 . V_76 . V_14 ,
V_77 | V_78 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_59 != V_5 && V_59 != V_6 ) {
V_19 = F_46 ( & V_8 -> V_70 , & V_79 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_59 == V_80 && ! V_69 ) {
V_19 = F_46 ( & V_8 -> V_70 , & V_81 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_59 != V_6 && V_59 != V_5 ) {
V_19 = F_48 ( V_8 ,
& V_82 . V_76 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_48 ( V_8 ,
& V_83 . V_76 ) ;
if ( V_19 )
return V_19 ;
if ( V_59 != V_63 ) {
V_19 = F_48 ( V_8 ,
& V_84 . V_76 ) ;
if ( V_19 )
return V_19 ;
}
}
return 0 ;
}
static int
F_49 ( struct V_50 * V_85 , struct V_86 * V_87 )
{
int V_52 , V_88 ;
struct V_15 * V_89 = F_50 () ;
struct V_57 * V_58 = V_85 -> V_58 ;
int V_54 = V_85 -> V_55 ;
const char * V_90 ;
enum T_5 { V_91 , V_92 } V_93 ;
if ( ! F_51 ( V_58 , V_94 ) )
return - V_95 ;
if ( V_89 )
F_9 ( & V_89 -> V_20 ) ;
if ( F_52 ( V_85 , V_96 ) & 0x80 ) {
F_53 ( & V_58 -> V_8 ,
L_13 ) ;
goto V_97;
}
V_52 = F_52 ( V_85 , V_98 ) ;
V_88 = F_52 ( V_85 , V_99 ) ;
if ( ! ( V_52 & 0x07 ) &&
( ( ! ( V_52 & 0x80 ) && V_88 != 0xa3 && V_88 != 0xc3 ) ||
( ( V_52 & 0x80 ) && V_88 != 0x5c && V_88 != 0x12 ) ) ) {
F_53 ( & V_58 -> V_8 ,
L_14 ) ;
goto V_97;
}
if ( ( ! ( V_52 & 0x80 ) && V_88 == 0xa3 ) ||
( ( V_52 & 0x80 ) && V_88 == 0x5c ) ) {
if ( F_52 ( V_85 , V_100 )
!= V_54 ) {
F_53 ( & V_58 -> V_8 ,
L_15 ) ;
goto V_97;
}
}
F_54 ( V_85 , V_98 ,
( F_52 ( V_85 , V_98 )
& 0x78 ) | 0x80 ) ;
V_88 = F_52 ( V_85 , V_99 ) ;
if ( V_88 == 0x5c )
V_93 = V_91 ;
else if ( V_88 == 0x12 )
V_93 = V_92 ;
else {
F_53 ( & V_58 -> V_8 ,
L_16 ) ;
goto V_97;
}
V_52 = F_52 ( V_85 , V_101 ) ;
if ( ( V_52 == 0x10 || V_52 == 0x11 ) && V_93 == V_91 )
V_90 = L_17 ;
else if ( V_52 == 0x30 && V_93 == V_91 )
V_90 = L_18 ;
else if ( V_52 == 0x40 && V_93 == V_91 && V_54 == 0x2d )
V_90 = L_19 ;
else if ( V_52 == 0x31 )
V_90 = L_20 ;
else
goto V_97;
if ( V_52 <= 0x30 && F_55 ( V_85 , V_52 ) ) {
F_53 ( & V_58 -> V_8 , L_21
L_22 , V_54 ) ;
goto V_97;
}
if ( V_89 )
F_13 ( & V_89 -> V_20 ) ;
F_56 ( V_87 -> type , V_90 , V_102 ) ;
return 0 ;
V_97:
if ( V_89 )
F_13 ( & V_89 -> V_20 ) ;
return - V_95 ;
}
static void F_57 ( struct V_7 * V_8 )
{
F_58 ( & V_8 -> V_70 , & V_71 ) ;
F_58 ( & V_8 -> V_70 , & V_72 ) ;
F_58 ( & V_8 -> V_70 , & V_73 ) ;
F_58 ( & V_8 -> V_70 , & V_74 ) ;
F_58 ( & V_8 -> V_70 , & V_79 ) ;
F_58 ( & V_8 -> V_70 , & V_81 ) ;
F_58 ( & V_8 -> V_70 , & V_103 ) ;
}
static int
F_59 ( struct V_50 * V_85 , const struct V_104 * V_53 )
{
struct V_7 * V_8 = & V_85 -> V_8 ;
struct V_15 * V_16 ;
int V_19 ;
V_16 = F_60 ( sizeof( struct V_15 ) , V_105 ) ;
if ( ! V_16 ) {
V_19 = - V_67 ;
goto V_106;
}
F_61 ( V_85 , V_16 ) ;
F_62 ( & V_16 -> V_107 ) ;
F_62 ( & V_16 -> V_20 ) ;
V_16 -> type = V_53 -> V_108 ;
V_16 -> V_85 = V_85 ;
V_19 = F_40 ( V_85 ) ;
if ( V_19 )
goto V_109;
F_63 ( V_8 ) ;
V_19 = F_45 ( V_8 , V_16 -> type , 0 ) ;
if ( V_19 )
goto V_110;
V_16 -> V_111 = F_64 ( V_8 ) ;
if ( F_65 ( V_16 -> V_111 ) ) {
V_19 = F_66 ( V_16 -> V_111 ) ;
goto V_110;
}
return 0 ;
V_110:
F_57 ( V_8 ) ;
if ( V_16 -> V_66 [ 0 ] )
F_44 ( V_16 -> V_66 [ 0 ] ) ;
if ( V_16 -> V_66 [ 1 ] )
F_44 ( V_16 -> V_66 [ 1 ] ) ;
V_109:
F_67 ( V_16 ) ;
V_106:
return V_19 ;
}
static int
F_68 ( struct V_50 * V_85 )
{
struct V_15 * V_16 = F_41 ( V_85 ) ;
struct V_7 * V_8 = & V_85 -> V_8 ;
F_69 ( V_16 -> V_111 ) ;
F_57 ( V_8 ) ;
if ( V_16 -> V_66 [ 0 ] )
F_44 ( V_16 -> V_66 [ 0 ] ) ;
if ( V_16 -> V_66 [ 1 ] )
F_44 ( V_16 -> V_66 [ 1 ] ) ;
F_67 ( V_16 ) ;
return 0 ;
}
static int
F_70 ( struct V_15 * V_16 , T_6 V_31 )
{
struct V_50 * V_85 = V_16 -> V_85 ;
int V_112 , V_113 ;
struct V_50 * V_114 ;
V_113 = ( V_31 >> 8 ) & 0x0f ;
if ( V_113 > 2 )
F_54 ( V_85 , V_98 ,
V_113 ) ;
if ( V_113 == 0 || V_113 > 2 ) {
V_112 = F_52 ( V_85 , V_31 & 0xff ) ;
} else {
V_114 = V_16 -> V_66 [ V_113 - 1 ] ;
switch ( V_31 & 0xff ) {
case 0x50 :
V_112 = F_71 ( V_114 , 0 ) ;
break;
case 0x52 :
V_112 = F_52 ( V_114 , 1 ) ;
break;
case 0x53 :
V_112 = F_71 ( V_114 , 2 ) ;
break;
case 0x55 :
default:
V_112 = F_71 ( V_114 , 3 ) ;
break;
}
}
if ( V_113 > 2 )
F_54 ( V_85 , V_98 , 0 ) ;
return V_112 ;
}
static int
F_72 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_115 )
{
struct V_50 * V_85 = V_16 -> V_85 ;
int V_113 ;
struct V_50 * V_114 ;
V_113 = ( V_31 >> 8 ) & 0x0f ;
if ( V_113 > 2 )
F_54 ( V_85 , V_98 ,
V_113 ) ;
if ( V_113 == 0 || V_113 > 2 ) {
F_54 ( V_85 , V_31 & 0xff ,
V_115 & 0xff ) ;
} else {
V_114 = V_16 -> V_66 [ V_113 - 1 ] ;
switch ( V_31 & 0xff ) {
case 0x52 :
F_54 ( V_114 , 1 , V_115 & 0xff ) ;
break;
case 0x53 :
F_73 ( V_114 , 2 , V_115 ) ;
break;
case 0x55 :
F_73 ( V_114 , 3 , V_115 ) ;
break;
}
}
if ( V_113 > 2 )
F_54 ( V_85 , V_98 , 0 ) ;
return 0 ;
}
static void
F_63 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_4 , V_116 ;
int type = V_16 -> type ;
T_1 V_44 ;
if ( V_117 && type != V_6 ) {
F_74 ( V_8 , L_23
L_24 ) ;
V_4 = F_28 ( V_16 , V_42 ) ;
V_116 = F_28 ( V_16 , V_41 ) ;
F_11 ( V_16 , V_96 , 0x80 ) ;
F_11 ( V_16 , V_42 , V_4 | 0x80 ) ;
F_11 ( V_16 , V_41 , V_116 ) ;
F_11 ( V_16 , V_29 , 0 ) ;
}
if ( V_118 && ! V_117 && type != V_6 ) {
V_4 = F_28 ( V_16 , V_42 ) ;
F_11 ( V_16 , V_42 , V_4 | 0x80 ) ;
}
V_16 -> V_24 = F_75 () ;
if ( ( type != V_5 ) && ( type != V_6 ) ) {
V_44 = F_28 ( V_16 , V_45 ) ;
for ( V_4 = 1 ; V_4 <= 3 ; V_4 ++ ) {
if ( ! ( V_44 & V_46 [ V_4 - 1 ] ) ) {
V_16 -> V_43 [ V_4 - 1 ] = 4 ;
} else {
if ( F_28
( V_16 ,
V_47 ) & V_48 [ V_4 - 1 ] )
V_16 -> V_43 [ V_4 - 1 ] = 1 ;
else
V_16 -> V_43 [ V_4 - 1 ] = 2 ;
}
if ( type == V_63 && V_4 == 2 )
break;
}
}
if ( V_118 && type != V_6 ) {
V_44 = F_28 ( V_16 , V_119 ) ;
if ( V_44 & 0x01 ) {
F_38 ( V_8 , L_25
L_26 ) ;
F_11 ( V_16 , V_119 ,
V_44 & 0xfe ) ;
}
if ( type != V_63 ) {
V_44 = F_28 ( V_16 ,
V_120 ) ;
if ( V_44 & 0x01 ) {
F_38 ( V_8 , L_27
L_28 ) ;
F_11 ( V_16 ,
V_120 , V_44 & 0xfe ) ;
}
}
}
F_11 ( V_16 , V_96 ,
( F_28 ( V_16 ,
V_96 ) & 0xf7 )
| 0x01 ) ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
V_16 -> V_21 [ V_4 ] = F_28 ( V_16 ,
F_12 ( V_4 ) ) ;
}
F_62 ( & V_16 -> V_20 ) ;
}
static struct V_15 * F_15 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
struct V_50 * V_85 = V_16 -> V_85 ;
int V_4 ;
F_9 ( & V_16 -> V_20 ) ;
if ( F_76 ( V_121 , V_16 -> V_122 + V_123 + V_123 / 2 )
|| ! V_16 -> V_124 ) {
F_53 ( V_8 , L_29 ) ;
for ( V_4 = 0 ; V_4 <= 8 ; V_4 ++ ) {
if ( V_16 -> type == V_63 && V_4 == 1 )
continue;
V_16 -> V_125 [ V_4 ] =
F_28 ( V_16 , F_77 ( V_4 ) ) ;
V_16 -> V_126 [ V_4 ] =
F_28 ( V_16 , F_78 ( V_4 ) ) ;
V_16 -> V_127 [ V_4 ] =
F_28 ( V_16 , F_79 ( V_4 ) ) ;
if ( ( V_16 -> type != V_80 ) && ( V_4 == 6 ) )
break;
}
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
V_16 -> V_128 [ V_4 ] =
F_28 ( V_16 , F_80 ( V_4 ) ) ;
V_16 -> V_21 [ V_4 ] =
F_28 ( V_16 , F_12 ( V_4 ) ) ;
}
if ( V_16 -> type != V_5 && V_16 -> type != V_6 ) {
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
V_16 -> V_38 [ V_4 ] =
F_28 ( V_16 ,
V_40 [ V_4 ] ) ;
if ( ( V_16 -> type != V_80 || ! V_85 )
&& V_4 == 1 )
break;
}
V_16 -> V_39 = ( F_28 ( V_16 ,
V_41 ) & 0x08 ) >> 3 ;
}
V_16 -> V_129 = F_28 ( V_16 , F_81 ( 1 ) ) ;
V_16 -> V_130 =
F_28 ( V_16 , F_82 ( 1 ) ) ;
V_16 -> V_131 =
F_28 ( V_16 , F_83 ( 1 ) ) ;
V_16 -> V_132 [ 0 ] =
F_28 ( V_16 , F_81 ( 2 ) ) ;
V_16 -> V_133 [ 0 ] =
F_28 ( V_16 , F_82 ( 2 ) ) ;
V_16 -> V_134 [ 0 ] =
F_28 ( V_16 , F_83 ( 2 ) ) ;
if ( V_16 -> type != V_63 ) {
V_16 -> V_132 [ 1 ] =
F_28 ( V_16 , F_81 ( 3 ) ) ;
V_16 -> V_133 [ 1 ] =
F_28 ( V_16 ,
F_82 ( 3 ) ) ;
V_16 -> V_134 [ 1 ] =
F_28 ( V_16 ,
F_83 ( 3 ) ) ;
}
V_4 = F_28 ( V_16 , V_36 ) ;
V_16 -> V_23 = V_4 & 0x0f ;
V_16 -> V_23 |= ( F_28 ( V_16 ,
V_135 ) & 0x01 ) << 4 ;
V_16 -> V_22 [ 0 ] = ( V_4 >> 4 ) & 0x03 ;
V_16 -> V_22 [ 1 ] = ( V_4 >> 6 ) & 0x03 ;
V_16 -> V_22 [ 2 ] = ( F_28 ( V_16 ,
V_35 ) >> 6 ) & 0x03 ;
if ( ( V_16 -> type != V_5 ) && ( V_16 -> type != V_6 ) ) {
V_4 = F_28 ( V_16 , V_37 ) ;
V_16 -> V_22 [ 0 ] |= ( V_4 >> 3 ) & 0x04 ;
V_16 -> V_22 [ 1 ] |= ( V_4 >> 4 ) & 0x04 ;
V_16 -> V_22 [ 2 ] |= ( V_4 >> 5 ) & 0x04 ;
}
if ( V_16 -> type == V_80 ) {
V_16 -> V_25 = F_28 ( V_16 ,
V_136 )
| ( F_28 ( V_16 ,
V_137 ) << 8 )
| ( F_28 ( V_16 ,
V_138 ) << 16 ) ;
} else if ( V_16 -> type == V_63 ) {
V_16 -> V_25 = F_28 ( V_16 ,
V_136 )
| ( F_28 ( V_16 ,
V_137 ) << 8 ) ;
} else {
V_16 -> V_25 = F_28 ( V_16 ,
V_139 )
| ( F_28 ( V_16 ,
V_140 ) << 8 ) ;
}
V_4 = F_28 ( V_16 , V_29 ) ;
V_16 -> V_27 = ( V_4 << 8 ) +
F_28 ( V_16 , V_28 ) ;
if ( ( V_16 -> type != V_5 ) && ( V_16 -> type != V_6 ) ) {
V_16 -> V_27 |=
F_28 ( V_16 ,
V_30 ) << 16 ;
}
V_16 -> V_122 = V_121 ;
V_16 -> V_124 = 1 ;
}
F_13 ( & V_16 -> V_20 ) ;
return V_16 ;
}
static T_2
F_84 ( struct V_7 * V_8 , struct V_9 * V_141 , char * V_11 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
return sprintf ( V_11 , L_30 , V_16 -> V_142 ) ;
}
static struct V_15 * F_50 ( void )
{
return V_143 ? F_85 ( V_143 ) : NULL ;
}
static int F_55 ( struct V_50 * V_85 , T_1 V_144 )
{
struct V_15 * V_89 ;
int V_4 ;
if ( ! V_143 )
return 0 ;
V_89 = F_85 ( V_143 ) ;
if ( F_28 ( V_89 , V_100 ) != V_85 -> V_55 )
return 0 ;
if ( F_28 ( V_89 , V_101 ) != V_144 )
return 0 ;
for ( V_4 = 0x2b ; V_4 <= 0x3d ; V_4 ++ ) {
if ( F_28 ( V_89 , V_4 ) !=
F_52 ( V_85 , V_4 ) )
return 0 ;
}
if ( F_28 ( V_89 , V_96 ) !=
F_52 ( V_85 , V_96 ) )
return 0 ;
for ( V_4 = 0x43 ; V_4 <= 0x46 ; V_4 ++ ) {
if ( F_28 ( V_89 , V_4 ) !=
F_52 ( V_85 , V_4 ) )
return 0 ;
}
return 1 ;
}
static int
F_86 ( struct V_15 * V_16 , T_6 V_31 )
{
int V_145 , V_112 ;
V_145 = ( ( ( V_31 & 0xff00 ) == 0x100 )
|| ( ( V_31 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_31 & 0x00ff ) == 0x50 )
|| ( ( V_31 & 0x00ff ) == 0x53 )
|| ( ( V_31 & 0x00ff ) == 0x55 ) ) ;
if ( V_31 & 0xff00 ) {
F_87 ( V_98 ,
V_16 -> V_146 + V_147 ) ;
F_87 ( V_31 >> 8 ,
V_16 -> V_146 + V_148 ) ;
}
F_87 ( V_31 & 0xff , V_16 -> V_146 + V_147 ) ;
V_112 = F_88 ( V_16 -> V_146 + V_148 ) ;
if ( V_145 ) {
F_87 ( ( V_31 & 0xff ) + 1 ,
V_16 -> V_146 + V_147 ) ;
V_112 =
( V_112 << 8 ) + F_88 ( V_16 -> V_146 +
V_148 ) ;
}
if ( V_31 & 0xff00 ) {
F_87 ( V_98 ,
V_16 -> V_146 + V_147 ) ;
F_87 ( 0 , V_16 -> V_146 + V_148 ) ;
}
return V_112 ;
}
static void
F_89 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_115 )
{
int V_145 ;
V_145 = ( ( ( V_31 & 0xff00 ) == 0x100 )
|| ( ( V_31 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_31 & 0x00ff ) == 0x53 )
|| ( ( V_31 & 0x00ff ) == 0x55 ) ) ;
if ( V_31 & 0xff00 ) {
F_87 ( V_98 ,
V_16 -> V_146 + V_147 ) ;
F_87 ( V_31 >> 8 ,
V_16 -> V_146 + V_148 ) ;
}
F_87 ( V_31 & 0xff , V_16 -> V_146 + V_147 ) ;
if ( V_145 ) {
F_87 ( V_115 >> 8 ,
V_16 -> V_146 + V_148 ) ;
F_87 ( ( V_31 & 0xff ) + 1 ,
V_16 -> V_146 + V_147 ) ;
}
F_87 ( V_115 & 0xff , V_16 -> V_146 + V_148 ) ;
if ( V_31 & 0xff00 ) {
F_87 ( V_98 ,
V_16 -> V_146 + V_147 ) ;
F_87 ( 0 , V_16 -> V_146 + V_148 ) ;
}
}
static int
F_28 ( struct V_15 * V_16 , T_6 V_31 )
{
struct V_50 * V_85 = V_16 -> V_85 ;
int V_112 ;
F_9 ( & V_16 -> V_107 ) ;
if ( V_85 )
V_112 = F_70 ( V_16 , V_31 ) ;
else
V_112 = F_86 ( V_16 , V_31 ) ;
F_13 ( & V_16 -> V_107 ) ;
return V_112 ;
}
static int
F_11 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_115 )
{
struct V_50 * V_85 = V_16 -> V_85 ;
F_9 ( & V_16 -> V_107 ) ;
if ( V_85 )
F_72 ( V_16 , V_31 , V_115 ) ;
else
F_89 ( V_16 , V_31 , V_115 ) ;
F_13 ( & V_16 -> V_107 ) ;
return 0 ;
}
static int T_7
F_90 ( struct V_149 * V_143 )
{
int V_19 , V_31 ;
struct V_15 * V_16 ;
struct V_150 * V_112 ;
V_112 = F_91 ( V_143 , V_151 , 0 ) ;
if ( ! F_92 ( V_112 -> V_152 + V_147 , 2 ,
L_17 ) ) {
V_19 = - V_64 ;
goto exit;
}
V_16 = F_60 ( sizeof( struct V_15 ) , V_105 ) ;
if ( ! V_16 ) {
V_19 = - V_67 ;
goto V_153;
}
F_62 ( & V_16 -> V_107 ) ;
V_16 -> V_146 = V_112 -> V_152 ;
F_93 ( V_143 , V_16 ) ;
V_31 = F_28 ( V_16 , V_101 ) ;
switch ( V_31 ) {
case 0x30 :
V_16 -> type = V_80 ;
V_16 -> V_142 = L_18 ;
break;
default:
V_16 -> type = V_5 ;
V_16 -> V_142 = L_17 ;
}
F_63 ( & V_143 -> V_8 ) ;
V_19 = F_45 ( & V_143 -> V_8 , V_16 -> type , 1 ) ;
if ( V_19 )
goto V_154;
V_19 = F_48 ( & V_143 -> V_8 , & V_155 ) ;
if ( V_19 )
goto V_154;
V_16 -> V_111 = F_64 ( & V_143 -> V_8 ) ;
if ( F_65 ( V_16 -> V_111 ) ) {
V_19 = F_66 ( V_16 -> V_111 ) ;
goto V_154;
}
return 0 ;
V_154:
F_57 ( & V_143 -> V_8 ) ;
F_94 ( & V_143 -> V_8 , & V_155 ) ;
F_67 ( V_16 ) ;
V_153:
F_95 ( V_112 -> V_152 + V_147 , 2 ) ;
exit:
return V_19 ;
}
static int T_8
F_96 ( struct V_149 * V_143 )
{
struct V_15 * V_16 = F_85 ( V_143 ) ;
F_69 ( V_16 -> V_111 ) ;
F_57 ( & V_143 -> V_8 ) ;
F_94 ( & V_143 -> V_8 , & V_155 ) ;
F_95 ( V_16 -> V_146 + V_147 , 2 ) ;
F_67 ( V_16 ) ;
return 0 ;
}
static int T_9
F_97 ( unsigned short V_54 )
{
int V_2 , V_156 , V_157 = 0 ;
int V_158 ;
for ( V_158 = V_54 ; V_158 < V_54 + V_159 ; V_158 ++ ) {
if ( ! F_92 ( V_158 , 1 , L_17 ) ) {
F_98 ( L_31 , V_158 ) ;
goto V_160;
}
}
#define F_99
V_2 = F_88 ( V_54 + 1 ) ;
if ( F_88 ( V_54 + 2 ) != V_2
|| F_88 ( V_54 + 3 ) != V_2
|| F_88 ( V_54 + 7 ) != V_2 ) {
F_98 ( L_32 , 1 ) ;
goto V_160;
}
#undef F_99
V_156 = F_88 ( V_54 + V_147 ) ;
if ( V_156 & 0x80 ) {
F_98 ( L_32 , 2 ) ;
goto V_160;
}
V_2 = ~ V_156 & 0x7f ;
F_87 ( V_2 , V_54 + V_147 ) ;
if ( F_88 ( V_54 + V_147 ) != ( V_2 | 0x80 ) ) {
F_87 ( V_156 , V_54 + V_147 ) ;
F_98 ( L_32 , 3 ) ;
goto V_160;
}
F_87 ( V_96 , V_54 + V_147 ) ;
V_2 = F_88 ( V_54 + V_148 ) ;
if ( V_2 & 0x80 ) {
F_98 ( L_32 , 4 ) ;
goto V_160;
}
F_87 ( V_98 , V_54 + V_147 ) ;
V_156 = F_88 ( V_54 + V_148 ) ;
F_87 ( V_99 , V_54 + V_147 ) ;
V_2 = F_88 ( V_54 + V_148 ) ;
if ( ( ! ( V_156 & 0x80 ) && ( V_2 != 0xa3 ) )
|| ( ( V_156 & 0x80 ) && ( V_2 != 0x5c ) ) ) {
F_98 ( L_32 , 5 ) ;
goto V_160;
}
F_87 ( V_100 , V_54 + V_147 ) ;
V_2 = F_88 ( V_54 + V_148 ) ;
if ( V_2 < 0x03 || V_2 > 0x77 ) {
F_98 ( L_32 , 6 ) ;
goto V_160;
}
if ( F_88 ( V_54 + V_147 ) & 0x80 ) {
F_98 ( L_32 , 7 ) ;
goto V_160;
}
F_87 ( V_98 , V_54 + V_147 ) ;
V_156 = F_88 ( V_54 + V_148 ) ;
F_87 ( V_156 & 0xf8 , V_54 + V_148 ) ;
F_87 ( V_101 , V_54 + V_147 ) ;
V_2 = F_88 ( V_54 + V_148 ) ;
if ( ( V_2 & 0xfe ) == 0x10
|| V_2 == 0x30 )
V_157 = 1 ;
if ( V_157 )
F_100 ( L_33 ,
V_2 == 0x30 ? L_34 : L_35 , ( int ) V_54 ) ;
V_160:
for ( V_158 -- ; V_158 >= V_54 ; V_158 -- )
F_95 ( V_158 , 1 ) ;
return V_157 ;
}
static int T_9
F_101 ( unsigned short V_54 )
{
struct V_150 V_112 = {
. V_152 = V_54 ,
. V_161 = V_54 + V_159 - 1 ,
. V_142 = L_17 ,
. V_162 = V_151 ,
} ;
int V_19 ;
V_143 = F_102 ( L_17 , V_54 ) ;
if ( ! V_143 ) {
V_19 = - V_67 ;
F_103 ( L_36 ) ;
goto exit;
}
V_19 = F_104 ( V_143 , & V_112 , 1 ) ;
if ( V_19 ) {
F_103 ( L_37 , V_19 ) ;
goto V_163;
}
V_19 = F_105 ( V_143 ) ;
if ( V_19 ) {
F_103 ( L_38 , V_19 ) ;
goto V_163;
}
return 0 ;
V_163:
F_106 ( V_143 ) ;
exit:
V_143 = NULL ;
return V_19 ;
}
static int T_9
F_107 ( void )
{
int V_112 ;
if ( F_97 ( V_164 ) ) {
V_112 = F_108 ( & V_165 ) ;
if ( V_112 )
goto exit;
V_112 = F_101 ( V_164 ) ;
if ( V_112 )
goto V_166;
}
return 0 ;
V_166:
F_109 ( & V_165 ) ;
exit:
return V_112 ;
}
static void
F_110 ( void )
{
if ( V_143 ) {
F_111 ( V_143 ) ;
F_109 ( & V_165 ) ;
}
}
static struct V_15 * F_50 ( void )
{
return NULL ;
}
static int
F_55 ( struct V_50 * V_85 , T_1 V_144 )
{
return 0 ;
}
static int
F_28 ( struct V_15 * V_16 , T_6 V_31 )
{
int V_112 ;
F_9 ( & V_16 -> V_107 ) ;
V_112 = F_70 ( V_16 , V_31 ) ;
F_13 ( & V_16 -> V_107 ) ;
return V_112 ;
}
static int
F_11 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_115 )
{
F_9 ( & V_16 -> V_107 ) ;
F_72 ( V_16 , V_31 , V_115 ) ;
F_13 ( & V_16 -> V_107 ) ;
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
int V_112 ;
V_112 = F_107 () ;
if ( V_112 )
goto exit;
V_112 = F_113 ( & V_167 ) ;
if ( V_112 )
goto V_168;
return 0 ;
V_168:
F_110 () ;
exit:
return V_112 ;
}
static void T_10
F_114 ( void )
{
F_110 () ;
F_115 ( & V_167 ) ;
}
