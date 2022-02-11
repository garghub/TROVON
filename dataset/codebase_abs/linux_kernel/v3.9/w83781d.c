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
( ( type == V_5 || type == V_6 ) ? 8 : 128 ) ) >> 1 ;
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
int V_60 = 1 ;
V_53 = F_42 ( V_58 ) ;
if ( V_61 [ 0 ] == V_53 && V_61 [ 1 ] == V_54 ) {
for ( V_4 = 2 ; V_4 <= 3 ; V_4 ++ ) {
if ( V_61 [ V_4 ] < 0x48 ||
V_61 [ V_4 ] > 0x4f ) {
F_39 ( & V_51 -> V_8 , L_7
L_8 ,
V_61 [ V_4 ] ) ;
V_19 = - V_33 ;
goto V_62;
}
}
F_11 ( V_16 , V_63 ,
( V_61 [ 2 ] & 0x07 ) |
( ( V_61 [ 3 ] & 0x07 ) << 4 ) ) ;
V_56 [ 0 ] = V_61 [ 2 ] ;
} else {
V_52 = F_28 ( V_16 , V_63 ) ;
V_56 [ 0 ] = 0x48 + ( V_52 & 0x07 ) ;
}
if ( V_59 != V_64 ) {
V_60 = 2 ;
if ( V_61 [ 0 ] == V_53 &&
V_61 [ 1 ] == V_54 ) {
V_56 [ 1 ] = V_61 [ 3 ] ;
} else {
V_56 [ 1 ] = 0x48 + ( ( V_52 >> 4 ) & 0x07 ) ;
}
if ( V_56 [ 0 ] == V_56 [ 1 ] ) {
F_39 ( & V_51 -> V_8 ,
L_9 ,
V_56 [ 0 ] ) ;
V_19 = - V_65 ;
goto V_66;
}
}
for ( V_4 = 0 ; V_4 < V_60 ; V_4 ++ ) {
V_16 -> V_67 [ V_4 ] = F_43 ( V_58 , V_56 [ V_4 ] ) ;
if ( ! V_16 -> V_67 [ V_4 ] ) {
F_39 ( & V_51 -> V_8 , L_10
L_11
L_12 , V_4 , V_56 [ V_4 ] ) ;
V_19 = - V_68 ;
if ( V_4 == 1 )
goto V_69;
goto V_66;
}
}
return 0 ;
V_69:
F_44 ( V_16 -> V_67 [ 0 ] ) ;
V_66:
V_62:
return V_19 ;
}
static int
F_45 ( struct V_7 * V_8 , int V_59 , int V_70 )
{
int V_19 ;
V_19 = F_46 ( & V_8 -> V_71 , & V_72 ) ;
if ( V_19 )
return V_19 ;
if ( V_59 != V_64 ) {
V_19 = F_46 ( & V_8 -> V_71 , & V_73 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_59 != V_6 && V_59 != V_5 && V_59 != V_64 ) {
V_19 = F_46 ( & V_8 -> V_71 , & V_74 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_59 != V_64 ) {
V_19 = F_46 ( & V_8 -> V_71 , & V_75 ) ;
if ( V_19 )
return V_19 ;
if ( V_59 != V_5 ) {
V_19 = F_47 ( & V_8 -> V_71 ,
& V_76 . V_77 . V_14 ,
V_78 | V_79 ) ;
if ( V_19 )
return V_19 ;
}
}
if ( V_59 != V_5 && V_59 != V_6 ) {
V_19 = F_46 ( & V_8 -> V_71 , & V_80 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_59 == V_81 && ! V_70 ) {
V_19 = F_46 ( & V_8 -> V_71 , & V_82 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_59 != V_6 && V_59 != V_5 ) {
V_19 = F_48 ( V_8 ,
& V_83 . V_77 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_48 ( V_8 ,
& V_84 . V_77 ) ;
if ( V_19 )
return V_19 ;
if ( V_59 != V_64 ) {
V_19 = F_48 ( V_8 ,
& V_85 . V_77 ) ;
if ( V_19 )
return V_19 ;
}
}
return 0 ;
}
static int
F_49 ( struct V_50 * V_86 , struct V_87 * V_88 )
{
int V_52 , V_89 ;
struct V_15 * V_90 = F_50 () ;
struct V_57 * V_58 = V_86 -> V_58 ;
int V_54 = V_86 -> V_55 ;
const char * V_91 ;
enum T_5 { V_92 , V_93 } V_94 ;
if ( ! F_51 ( V_58 , V_95 ) )
return - V_96 ;
if ( V_90 )
F_9 ( & V_90 -> V_20 ) ;
if ( F_52 ( V_86 , V_97 ) & 0x80 ) {
F_53 ( & V_58 -> V_8 ,
L_13 ) ;
goto V_98;
}
V_52 = F_52 ( V_86 , V_99 ) ;
V_89 = F_52 ( V_86 , V_100 ) ;
if ( ! ( V_52 & 0x07 ) &&
( ( ! ( V_52 & 0x80 ) && V_89 != 0xa3 && V_89 != 0xc3 ) ||
( ( V_52 & 0x80 ) && V_89 != 0x5c && V_89 != 0x12 ) ) ) {
F_53 ( & V_58 -> V_8 ,
L_14 ) ;
goto V_98;
}
if ( ( ! ( V_52 & 0x80 ) && V_89 == 0xa3 ) ||
( ( V_52 & 0x80 ) && V_89 == 0x5c ) ) {
if ( F_52 ( V_86 , V_101 )
!= V_54 ) {
F_53 ( & V_58 -> V_8 ,
L_15 ) ;
goto V_98;
}
}
F_54 ( V_86 , V_99 ,
( F_52 ( V_86 , V_99 )
& 0x78 ) | 0x80 ) ;
V_89 = F_52 ( V_86 , V_100 ) ;
if ( V_89 == 0x5c )
V_94 = V_92 ;
else if ( V_89 == 0x12 )
V_94 = V_93 ;
else {
F_53 ( & V_58 -> V_8 ,
L_16 ) ;
goto V_98;
}
V_52 = F_52 ( V_86 , V_102 ) ;
if ( ( V_52 == 0x10 || V_52 == 0x11 ) && V_94 == V_92 )
V_91 = L_17 ;
else if ( V_52 == 0x30 && V_94 == V_92 )
V_91 = L_18 ;
else if ( V_52 == 0x40 && V_94 == V_92 && V_54 == 0x2d )
V_91 = L_19 ;
else if ( V_52 == 0x31 )
V_91 = L_20 ;
else
goto V_98;
if ( V_52 <= 0x30 && F_55 ( V_86 , V_52 ) ) {
F_53 ( & V_58 -> V_8 , L_21
L_22 , V_54 ) ;
goto V_98;
}
if ( V_90 )
F_13 ( & V_90 -> V_20 ) ;
F_56 ( V_88 -> type , V_91 , V_103 ) ;
return 0 ;
V_98:
if ( V_90 )
F_13 ( & V_90 -> V_20 ) ;
return - V_96 ;
}
static void F_57 ( struct V_7 * V_8 )
{
F_58 ( & V_8 -> V_71 , & V_72 ) ;
F_58 ( & V_8 -> V_71 , & V_73 ) ;
F_58 ( & V_8 -> V_71 , & V_74 ) ;
F_58 ( & V_8 -> V_71 , & V_75 ) ;
F_58 ( & V_8 -> V_71 , & V_80 ) ;
F_58 ( & V_8 -> V_71 , & V_82 ) ;
F_58 ( & V_8 -> V_71 , & V_104 ) ;
}
static int
F_59 ( struct V_50 * V_86 , const struct V_105 * V_53 )
{
struct V_7 * V_8 = & V_86 -> V_8 ;
struct V_15 * V_16 ;
int V_19 ;
V_16 = F_60 ( V_8 , sizeof( struct V_15 ) , V_106 ) ;
if ( ! V_16 )
return - V_68 ;
F_61 ( V_86 , V_16 ) ;
F_62 ( & V_16 -> V_107 ) ;
F_62 ( & V_16 -> V_20 ) ;
V_16 -> type = V_53 -> V_108 ;
V_16 -> V_86 = V_86 ;
V_19 = F_40 ( V_86 ) ;
if ( V_19 )
return V_19 ;
F_63 ( V_8 ) ;
V_19 = F_45 ( V_8 , V_16 -> type , 0 ) ;
if ( V_19 )
goto V_109;
V_16 -> V_110 = F_64 ( V_8 ) ;
if ( F_65 ( V_16 -> V_110 ) ) {
V_19 = F_66 ( V_16 -> V_110 ) ;
goto V_109;
}
return 0 ;
V_109:
F_57 ( V_8 ) ;
if ( V_16 -> V_67 [ 0 ] )
F_44 ( V_16 -> V_67 [ 0 ] ) ;
if ( V_16 -> V_67 [ 1 ] )
F_44 ( V_16 -> V_67 [ 1 ] ) ;
return V_19 ;
}
static int
F_67 ( struct V_50 * V_86 )
{
struct V_15 * V_16 = F_41 ( V_86 ) ;
struct V_7 * V_8 = & V_86 -> V_8 ;
F_68 ( V_16 -> V_110 ) ;
F_57 ( V_8 ) ;
if ( V_16 -> V_67 [ 0 ] )
F_44 ( V_16 -> V_67 [ 0 ] ) ;
if ( V_16 -> V_67 [ 1 ] )
F_44 ( V_16 -> V_67 [ 1 ] ) ;
return 0 ;
}
static int
F_69 ( struct V_15 * V_16 , T_6 V_31 )
{
struct V_50 * V_86 = V_16 -> V_86 ;
int V_111 , V_112 ;
struct V_50 * V_113 ;
V_112 = ( V_31 >> 8 ) & 0x0f ;
if ( V_112 > 2 )
F_54 ( V_86 , V_99 ,
V_112 ) ;
if ( V_112 == 0 || V_112 > 2 ) {
V_111 = F_52 ( V_86 , V_31 & 0xff ) ;
} else {
V_113 = V_16 -> V_67 [ V_112 - 1 ] ;
switch ( V_31 & 0xff ) {
case 0x50 :
V_111 = F_70 ( V_113 , 0 ) ;
break;
case 0x52 :
V_111 = F_52 ( V_113 , 1 ) ;
break;
case 0x53 :
V_111 = F_70 ( V_113 , 2 ) ;
break;
case 0x55 :
default:
V_111 = F_70 ( V_113 , 3 ) ;
break;
}
}
if ( V_112 > 2 )
F_54 ( V_86 , V_99 , 0 ) ;
return V_111 ;
}
static int
F_71 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_114 )
{
struct V_50 * V_86 = V_16 -> V_86 ;
int V_112 ;
struct V_50 * V_113 ;
V_112 = ( V_31 >> 8 ) & 0x0f ;
if ( V_112 > 2 )
F_54 ( V_86 , V_99 ,
V_112 ) ;
if ( V_112 == 0 || V_112 > 2 ) {
F_54 ( V_86 , V_31 & 0xff ,
V_114 & 0xff ) ;
} else {
V_113 = V_16 -> V_67 [ V_112 - 1 ] ;
switch ( V_31 & 0xff ) {
case 0x52 :
F_54 ( V_113 , 1 , V_114 & 0xff ) ;
break;
case 0x53 :
F_72 ( V_113 , 2 , V_114 ) ;
break;
case 0x55 :
F_72 ( V_113 , 3 , V_114 ) ;
break;
}
}
if ( V_112 > 2 )
F_54 ( V_86 , V_99 , 0 ) ;
return 0 ;
}
static void
F_63 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
int V_4 , V_115 ;
int type = V_16 -> type ;
T_1 V_44 ;
if ( V_116 && type != V_6 ) {
F_73 ( V_8 , L_23
L_24 ) ;
V_4 = F_28 ( V_16 , V_42 ) ;
V_115 = F_28 ( V_16 , V_41 ) ;
F_11 ( V_16 , V_97 , 0x80 ) ;
F_11 ( V_16 , V_42 , V_4 | 0x80 ) ;
F_11 ( V_16 , V_41 , V_115 ) ;
F_11 ( V_16 , V_29 , 0 ) ;
}
if ( V_117 && ! V_116 && type != V_6 ) {
V_4 = F_28 ( V_16 , V_42 ) ;
F_11 ( V_16 , V_42 , V_4 | 0x80 ) ;
}
V_16 -> V_24 = F_74 () ;
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
if ( type == V_64 && V_4 == 2 )
break;
}
}
if ( V_117 && type != V_6 ) {
V_44 = F_28 ( V_16 , V_118 ) ;
if ( V_44 & 0x01 ) {
F_38 ( V_8 , L_25
L_26 ) ;
F_11 ( V_16 , V_118 ,
V_44 & 0xfe ) ;
}
if ( type != V_64 ) {
V_44 = F_28 ( V_16 ,
V_119 ) ;
if ( V_44 & 0x01 ) {
F_38 ( V_8 , L_27
L_28 ) ;
F_11 ( V_16 ,
V_119 , V_44 & 0xfe ) ;
}
}
}
F_11 ( V_16 , V_97 ,
( F_28 ( V_16 ,
V_97 ) & 0xf7 )
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
struct V_50 * V_86 = V_16 -> V_86 ;
int V_4 ;
F_9 ( & V_16 -> V_20 ) ;
if ( F_75 ( V_120 , V_16 -> V_121 + V_122 + V_122 / 2 )
|| ! V_16 -> V_123 ) {
F_53 ( V_8 , L_29 ) ;
for ( V_4 = 0 ; V_4 <= 8 ; V_4 ++ ) {
if ( V_16 -> type == V_64 && V_4 == 1 )
continue;
V_16 -> V_124 [ V_4 ] =
F_28 ( V_16 , F_76 ( V_4 ) ) ;
V_16 -> V_125 [ V_4 ] =
F_28 ( V_16 , F_77 ( V_4 ) ) ;
V_16 -> V_126 [ V_4 ] =
F_28 ( V_16 , F_78 ( V_4 ) ) ;
if ( ( V_16 -> type != V_81 ) && ( V_4 == 6 ) )
break;
}
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
V_16 -> V_127 [ V_4 ] =
F_28 ( V_16 , F_79 ( V_4 ) ) ;
V_16 -> V_21 [ V_4 ] =
F_28 ( V_16 , F_12 ( V_4 ) ) ;
}
if ( V_16 -> type != V_5 && V_16 -> type != V_6 ) {
for ( V_4 = 0 ; V_4 < 4 ; V_4 ++ ) {
V_16 -> V_38 [ V_4 ] =
F_28 ( V_16 ,
V_40 [ V_4 ] ) ;
if ( ( V_16 -> type != V_81 || ! V_86 )
&& V_4 == 1 )
break;
}
V_16 -> V_39 = ( F_28 ( V_16 ,
V_41 ) & 0x08 ) >> 3 ;
}
V_16 -> V_128 = F_28 ( V_16 , F_80 ( 1 ) ) ;
V_16 -> V_129 =
F_28 ( V_16 , F_81 ( 1 ) ) ;
V_16 -> V_130 =
F_28 ( V_16 , F_82 ( 1 ) ) ;
V_16 -> V_131 [ 0 ] =
F_28 ( V_16 , F_80 ( 2 ) ) ;
V_16 -> V_132 [ 0 ] =
F_28 ( V_16 , F_81 ( 2 ) ) ;
V_16 -> V_133 [ 0 ] =
F_28 ( V_16 , F_82 ( 2 ) ) ;
if ( V_16 -> type != V_64 ) {
V_16 -> V_131 [ 1 ] =
F_28 ( V_16 , F_80 ( 3 ) ) ;
V_16 -> V_132 [ 1 ] =
F_28 ( V_16 ,
F_81 ( 3 ) ) ;
V_16 -> V_133 [ 1 ] =
F_28 ( V_16 ,
F_82 ( 3 ) ) ;
}
V_4 = F_28 ( V_16 , V_36 ) ;
V_16 -> V_23 = V_4 & 0x0f ;
V_16 -> V_23 |= ( F_28 ( V_16 ,
V_134 ) & 0x01 ) << 4 ;
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
if ( V_16 -> type == V_81 ) {
V_16 -> V_25 = F_28 ( V_16 ,
V_135 )
| ( F_28 ( V_16 ,
V_136 ) << 8 )
| ( F_28 ( V_16 ,
V_137 ) << 16 ) ;
} else if ( V_16 -> type == V_64 ) {
V_16 -> V_25 = F_28 ( V_16 ,
V_135 )
| ( F_28 ( V_16 ,
V_136 ) << 8 ) ;
} else {
V_16 -> V_25 = F_28 ( V_16 ,
V_138 )
| ( F_28 ( V_16 ,
V_139 ) << 8 ) ;
}
V_4 = F_28 ( V_16 , V_29 ) ;
V_16 -> V_27 = ( V_4 << 8 ) +
F_28 ( V_16 , V_28 ) ;
if ( ( V_16 -> type != V_5 ) && ( V_16 -> type != V_6 ) ) {
V_16 -> V_27 |=
F_28 ( V_16 ,
V_30 ) << 16 ;
}
V_16 -> V_121 = V_120 ;
V_16 -> V_123 = 1 ;
}
F_13 ( & V_16 -> V_20 ) ;
return V_16 ;
}
static T_2
F_83 ( struct V_7 * V_8 , struct V_9 * V_140 , char * V_11 )
{
struct V_15 * V_16 = F_7 ( V_8 ) ;
return sprintf ( V_11 , L_30 , V_16 -> V_141 ) ;
}
static struct V_15 * F_50 ( void )
{
return V_142 ? F_84 ( V_142 ) : NULL ;
}
static int F_55 ( struct V_50 * V_86 , T_1 V_143 )
{
struct V_15 * V_90 ;
int V_4 ;
if ( ! V_142 )
return 0 ;
V_90 = F_84 ( V_142 ) ;
if ( F_28 ( V_90 , V_101 ) != V_86 -> V_55 )
return 0 ;
if ( F_28 ( V_90 , V_102 ) != V_143 )
return 0 ;
for ( V_4 = 0x2b ; V_4 <= 0x3d ; V_4 ++ ) {
if ( F_28 ( V_90 , V_4 ) !=
F_52 ( V_86 , V_4 ) )
return 0 ;
}
if ( F_28 ( V_90 , V_97 ) !=
F_52 ( V_86 , V_97 ) )
return 0 ;
for ( V_4 = 0x43 ; V_4 <= 0x46 ; V_4 ++ ) {
if ( F_28 ( V_90 , V_4 ) !=
F_52 ( V_86 , V_4 ) )
return 0 ;
}
return 1 ;
}
static int
F_85 ( struct V_15 * V_16 , T_6 V_31 )
{
int V_144 , V_111 ;
V_144 = ( ( ( V_31 & 0xff00 ) == 0x100 )
|| ( ( V_31 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_31 & 0x00ff ) == 0x50 )
|| ( ( V_31 & 0x00ff ) == 0x53 )
|| ( ( V_31 & 0x00ff ) == 0x55 ) ) ;
if ( V_31 & 0xff00 ) {
F_86 ( V_99 ,
V_16 -> V_145 + V_146 ) ;
F_86 ( V_31 >> 8 ,
V_16 -> V_145 + V_147 ) ;
}
F_86 ( V_31 & 0xff , V_16 -> V_145 + V_146 ) ;
V_111 = F_87 ( V_16 -> V_145 + V_147 ) ;
if ( V_144 ) {
F_86 ( ( V_31 & 0xff ) + 1 ,
V_16 -> V_145 + V_146 ) ;
V_111 =
( V_111 << 8 ) + F_87 ( V_16 -> V_145 +
V_147 ) ;
}
if ( V_31 & 0xff00 ) {
F_86 ( V_99 ,
V_16 -> V_145 + V_146 ) ;
F_86 ( 0 , V_16 -> V_145 + V_147 ) ;
}
return V_111 ;
}
static void
F_88 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_114 )
{
int V_144 ;
V_144 = ( ( ( V_31 & 0xff00 ) == 0x100 )
|| ( ( V_31 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_31 & 0x00ff ) == 0x53 )
|| ( ( V_31 & 0x00ff ) == 0x55 ) ) ;
if ( V_31 & 0xff00 ) {
F_86 ( V_99 ,
V_16 -> V_145 + V_146 ) ;
F_86 ( V_31 >> 8 ,
V_16 -> V_145 + V_147 ) ;
}
F_86 ( V_31 & 0xff , V_16 -> V_145 + V_146 ) ;
if ( V_144 ) {
F_86 ( V_114 >> 8 ,
V_16 -> V_145 + V_147 ) ;
F_86 ( ( V_31 & 0xff ) + 1 ,
V_16 -> V_145 + V_146 ) ;
}
F_86 ( V_114 & 0xff , V_16 -> V_145 + V_147 ) ;
if ( V_31 & 0xff00 ) {
F_86 ( V_99 ,
V_16 -> V_145 + V_146 ) ;
F_86 ( 0 , V_16 -> V_145 + V_147 ) ;
}
}
static int
F_28 ( struct V_15 * V_16 , T_6 V_31 )
{
struct V_50 * V_86 = V_16 -> V_86 ;
int V_111 ;
F_9 ( & V_16 -> V_107 ) ;
if ( V_86 )
V_111 = F_69 ( V_16 , V_31 ) ;
else
V_111 = F_85 ( V_16 , V_31 ) ;
F_13 ( & V_16 -> V_107 ) ;
return V_111 ;
}
static int
F_11 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_114 )
{
struct V_50 * V_86 = V_16 -> V_86 ;
F_9 ( & V_16 -> V_107 ) ;
if ( V_86 )
F_71 ( V_16 , V_31 , V_114 ) ;
else
F_88 ( V_16 , V_31 , V_114 ) ;
F_13 ( & V_16 -> V_107 ) ;
return 0 ;
}
static int
F_89 ( struct V_148 * V_142 )
{
int V_19 , V_31 ;
struct V_15 * V_16 ;
struct V_149 * V_111 ;
V_111 = F_90 ( V_142 , V_150 , 0 ) ;
if ( ! F_91 ( & V_142 -> V_8 ,
V_111 -> V_151 + V_146 , 2 ,
L_17 ) )
return - V_65 ;
V_16 = F_60 ( & V_142 -> V_8 , sizeof( struct V_15 ) ,
V_106 ) ;
if ( ! V_16 )
return - V_68 ;
F_62 ( & V_16 -> V_107 ) ;
V_16 -> V_145 = V_111 -> V_151 ;
F_92 ( V_142 , V_16 ) ;
V_31 = F_28 ( V_16 , V_102 ) ;
switch ( V_31 ) {
case 0x30 :
V_16 -> type = V_81 ;
V_16 -> V_141 = L_18 ;
break;
default:
V_16 -> type = V_5 ;
V_16 -> V_141 = L_17 ;
}
F_63 ( & V_142 -> V_8 ) ;
V_19 = F_45 ( & V_142 -> V_8 , V_16 -> type , 1 ) ;
if ( V_19 )
goto V_109;
V_19 = F_48 ( & V_142 -> V_8 , & V_152 ) ;
if ( V_19 )
goto V_109;
V_16 -> V_110 = F_64 ( & V_142 -> V_8 ) ;
if ( F_65 ( V_16 -> V_110 ) ) {
V_19 = F_66 ( V_16 -> V_110 ) ;
goto V_109;
}
return 0 ;
V_109:
F_57 ( & V_142 -> V_8 ) ;
F_93 ( & V_142 -> V_8 , & V_152 ) ;
return V_19 ;
}
static int
F_94 ( struct V_148 * V_142 )
{
struct V_15 * V_16 = F_84 ( V_142 ) ;
F_68 ( V_16 -> V_110 ) ;
F_57 ( & V_142 -> V_8 ) ;
F_93 ( & V_142 -> V_8 , & V_152 ) ;
return 0 ;
}
static int T_7
F_95 ( unsigned short V_54 )
{
int V_2 , V_153 , V_154 = 0 ;
int V_155 ;
for ( V_155 = V_54 ; V_155 < V_54 + V_156 ; V_155 ++ ) {
if ( ! F_96 ( V_155 , 1 , L_17 ) ) {
F_97 ( L_31 , V_155 ) ;
goto V_157;
}
}
#define F_98
V_2 = F_87 ( V_54 + 1 ) ;
if ( F_87 ( V_54 + 2 ) != V_2
|| F_87 ( V_54 + 3 ) != V_2
|| F_87 ( V_54 + 7 ) != V_2 ) {
F_97 ( L_32 , 1 ) ;
goto V_157;
}
#undef F_98
V_153 = F_87 ( V_54 + V_146 ) ;
if ( V_153 & 0x80 ) {
F_97 ( L_32 , 2 ) ;
goto V_157;
}
V_2 = ~ V_153 & 0x7f ;
F_86 ( V_2 , V_54 + V_146 ) ;
if ( F_87 ( V_54 + V_146 ) != ( V_2 | 0x80 ) ) {
F_86 ( V_153 , V_54 + V_146 ) ;
F_97 ( L_32 , 3 ) ;
goto V_157;
}
F_86 ( V_97 , V_54 + V_146 ) ;
V_2 = F_87 ( V_54 + V_147 ) ;
if ( V_2 & 0x80 ) {
F_97 ( L_32 , 4 ) ;
goto V_157;
}
F_86 ( V_99 , V_54 + V_146 ) ;
V_153 = F_87 ( V_54 + V_147 ) ;
F_86 ( V_100 , V_54 + V_146 ) ;
V_2 = F_87 ( V_54 + V_147 ) ;
if ( ( ! ( V_153 & 0x80 ) && ( V_2 != 0xa3 ) )
|| ( ( V_153 & 0x80 ) && ( V_2 != 0x5c ) ) ) {
F_97 ( L_32 , 5 ) ;
goto V_157;
}
F_86 ( V_101 , V_54 + V_146 ) ;
V_2 = F_87 ( V_54 + V_147 ) ;
if ( V_2 < 0x03 || V_2 > 0x77 ) {
F_97 ( L_32 , 6 ) ;
goto V_157;
}
if ( F_87 ( V_54 + V_146 ) & 0x80 ) {
F_97 ( L_32 , 7 ) ;
goto V_157;
}
F_86 ( V_99 , V_54 + V_146 ) ;
V_153 = F_87 ( V_54 + V_147 ) ;
F_86 ( V_153 & 0xf8 , V_54 + V_147 ) ;
F_86 ( V_102 , V_54 + V_146 ) ;
V_2 = F_87 ( V_54 + V_147 ) ;
if ( ( V_2 & 0xfe ) == 0x10
|| V_2 == 0x30 )
V_154 = 1 ;
if ( V_154 )
F_99 ( L_33 ,
V_2 == 0x30 ? L_34 : L_35 , ( int ) V_54 ) ;
V_157:
for ( V_155 -- ; V_155 >= V_54 ; V_155 -- )
F_100 ( V_155 , 1 ) ;
return V_154 ;
}
static int T_7
F_101 ( unsigned short V_54 )
{
struct V_149 V_111 = {
. V_151 = V_54 ,
. V_158 = V_54 + V_156 - 1 ,
. V_141 = L_17 ,
. V_159 = V_150 ,
} ;
int V_19 ;
V_142 = F_102 ( L_17 , V_54 ) ;
if ( ! V_142 ) {
V_19 = - V_68 ;
F_103 ( L_36 ) ;
goto exit;
}
V_19 = F_104 ( V_142 , & V_111 , 1 ) ;
if ( V_19 ) {
F_103 ( L_37 , V_19 ) ;
goto V_160;
}
V_19 = F_105 ( V_142 ) ;
if ( V_19 ) {
F_103 ( L_38 , V_19 ) ;
goto V_160;
}
return 0 ;
V_160:
F_106 ( V_142 ) ;
exit:
V_142 = NULL ;
return V_19 ;
}
static int T_7
F_107 ( void )
{
int V_111 ;
if ( F_95 ( V_161 ) ) {
V_111 = F_108 ( & V_162 ) ;
if ( V_111 )
goto exit;
V_111 = F_101 ( V_161 ) ;
if ( V_111 )
goto V_163;
}
return 0 ;
V_163:
F_109 ( & V_162 ) ;
exit:
return V_111 ;
}
static void
F_110 ( void )
{
if ( V_142 ) {
F_111 ( V_142 ) ;
F_109 ( & V_162 ) ;
}
}
static struct V_15 * F_50 ( void )
{
return NULL ;
}
static int
F_55 ( struct V_50 * V_86 , T_1 V_143 )
{
return 0 ;
}
static int
F_28 ( struct V_15 * V_16 , T_6 V_31 )
{
int V_111 ;
F_9 ( & V_16 -> V_107 ) ;
V_111 = F_69 ( V_16 , V_31 ) ;
F_13 ( & V_16 -> V_107 ) ;
return V_111 ;
}
static int
F_11 ( struct V_15 * V_16 , T_6 V_31 , T_6 V_114 )
{
F_9 ( & V_16 -> V_107 ) ;
F_71 ( V_16 , V_31 , V_114 ) ;
F_13 ( & V_16 -> V_107 ) ;
return 0 ;
}
static int T_7
F_107 ( void )
{
return 0 ;
}
static void
F_110 ( void )
{
}
static int T_7
F_112 ( void )
{
int V_111 ;
V_111 = F_107 () ;
if ( V_111 )
goto exit;
V_111 = F_113 ( & V_164 ) ;
if ( V_111 )
goto V_165;
return 0 ;
V_165:
F_110 () ;
exit:
return V_111 ;
}
static void T_8
F_114 ( void )
{
F_110 () ;
F_115 ( & V_164 ) ;
}
