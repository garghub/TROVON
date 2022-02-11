static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
switch( V_2 -> V_4 ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
V_3 = 4 ;
break;
case V_10 :
case V_11 :
V_3 = 3 ;
break;
default:
return 0 ;
}
return V_3 ;
}
static T_1 F_2 ( T_2 * V_12 , T_1 V_13 )
{
T_1 V_14 ;
F_3 ( V_13 , V_12 -> V_15 + 1 ) ;
V_14 = F_4 ( V_12 -> V_15 + 3 ) ;
F_5 ( L_1 , V_13 , V_14 ) ;
return V_14 ;
}
static void F_6 ( T_2 * V_12 , T_1 V_13 , T_1 V_14 )
{
F_3 ( V_13 , V_12 -> V_15 + 1 ) ;
F_3 ( V_14 , V_12 -> V_15 + 3 ) ;
F_5 ( L_1 , V_13 , V_14 ) ;
}
static void F_7 ( T_2 * V_12 , T_3 * V_16 )
{
struct V_1 * V_17 = F_8 ( V_12 -> V_17 ) ;
T_1 V_18 = ( V_16 -> V_19 & 1 ) ? 0x08 : 0x00 ;
const T_1 V_20 = V_16 -> V_21 ;
if ( F_1 ( V_17 ) == 4 ) {
T_1 V_3 = V_20 & 0x07 ;
if ( V_20 >= V_22 ) {
F_6 ( V_12 , 0x10 + V_18 ,
V_23 [ V_3 ] . V_24 ) ;
F_6 ( V_12 , 0x11 + V_18 ,
V_23 [ V_3 ] . V_25 ) ;
F_6 ( V_12 , 0x12 + V_18 ,
V_23 [ V_3 ] . V_26 ) ;
} else {
F_6 ( V_12 , 0x0e + V_18 ,
V_27 [ V_3 ] . V_28 ) ;
F_6 ( V_12 , 0x0f + V_18 ,
V_27 [ V_3 ] . V_29 ) ;
}
} else if ( V_20 == V_30 ) {
T_1 V_31 = F_2 ( V_12 , 0x10 + V_18 ) ;
F_6 ( V_12 , 0x10 + V_18 , V_31 & 0x7f ) ;
}
}
static void F_9 ( T_2 * V_12 , T_3 * V_16 )
{
struct V_1 * V_17 = F_8 ( V_12 -> V_17 ) ;
T_1 V_18 = ( V_16 -> V_19 & 1 ) ? 0x08 : 0x00 ;
const T_1 V_32 = V_16 -> V_33 - V_34 ;
if ( F_1 ( V_17 ) == 4 ) {
F_6 ( V_12 , 0x0c + V_18 , V_35 [ V_32 ] . V_36 ) ;
F_6 ( V_12 , 0x0d + V_18 , V_35 [ V_32 ] . V_37 ) ;
F_6 ( V_12 , 0x13 + V_18 , V_35 [ V_32 ] . V_38 ) ;
}
}
static T_1 F_10 ( T_2 * V_12 )
{
if ( F_2 ( V_12 , 0x0b ) & 0x04 )
return V_39 ;
else
return V_40 ;
}
static void F_11 ( T_3 * V_16 )
{
F_12 ( V_41 L_2 ,
V_16 -> V_12 -> V_42 ? L_3 : L_4 ) ;
}
static long F_13 ( T_4 V_15 )
{
T_4 V_43 = V_15 , V_44 = V_15 + 0x08 ;
T_1 V_45 , V_46 , V_47 , V_48 ;
long V_49 = 0 , V_50 ;
int V_51 = 3 ;
do {
V_50 = V_49 ;
F_3 ( 0x20 , V_43 + 0x01 ) ;
V_45 = F_4 ( V_43 + 0x03 ) ;
F_3 ( 0x21 , V_43 + 0x01 ) ;
V_46 = F_4 ( V_43 + 0x03 ) ;
F_3 ( 0x20 , V_44 + 0x01 ) ;
V_47 = F_4 ( V_44 + 0x03 ) ;
F_3 ( 0x21 , V_44 + 0x01 ) ;
V_48 = F_4 ( V_44 + 0x03 ) ;
V_49 = ( V_48 << 23 ) | ( V_47 << 15 ) | ( V_46 << 8 ) | V_45 ;
} while ( V_51 -- && ( ( ( V_50 ^ V_49 ) & 0x3fff8000 ) || V_50 < V_49 ) );
F_5 ( L_5 ,
V_45 , V_46 , V_47 , V_48 ) ;
return V_49 ;
}
static long F_14 ( unsigned long V_15 )
{
T_5 V_52 , V_53 ;
long V_54 , V_55 ;
long V_56 , V_57 ;
T_1 V_58 ;
V_54 = F_13 ( V_15 ) ;
V_52 = F_15 () ;
F_3 ( 0x01 , V_15 + 0x01 ) ;
V_58 = F_4 ( V_15 + 0x03 ) ;
F_5 ( L_6 , V_58 ) ;
F_3 ( V_58 | 0x40 , V_15 + 0x03 ) ;
F_16 ( 10 ) ;
V_55 = F_13 ( V_15 ) ;
V_53 = F_15 () ;
F_3 ( 0x01 , V_15 + 0x01 ) ;
V_58 = F_4 ( V_15 + 0x03 ) ;
F_5 ( L_6 , V_58 ) ;
F_3 ( V_58 & ~ 0x40 , V_15 + 0x03 ) ;
V_57 = F_17 ( V_53 , V_52 ) ;
V_56 = ( ( V_54 - V_55 ) & 0x3fffffff ) / 10 *
( 10000000 / V_57 ) ;
F_5 ( L_7 , V_54 , V_55 ) ;
return V_56 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_19 ( V_2 ) ;
T_1 V_61 ;
if ( V_60 == NULL || ! F_20 ( V_60 , L_8 ) )
return;
if ( V_2 -> V_62 >= 0x03 ) {
F_21 ( V_2 , 0x40 , & V_61 ) ;
F_22 ( V_2 , 0x40 , ( V_61 | 0x01 ) ) ;
}
}
static int F_23 ( struct V_1 * V_17 )
{
const char * V_63 = V_64 ;
unsigned long V_15 = F_24 ( V_17 , 4 ) ;
unsigned long V_44 = V_15 + 0x08 ;
long V_56 , V_65 , V_66 ;
int V_67 , V_68 ;
T_1 V_69 , V_70 ;
if ( V_15 == 0 )
return - V_71 ;
#ifdef F_25
F_18 ( V_17 ) ;
#endif
switch( F_1 ( V_17 ) ) {
case 4 :
V_65 = 133333333 ;
break;
case 3 :
default:
V_65 = 100000000 ;
break;
}
V_56 = F_14 ( V_15 ) ;
F_12 ( V_72 L_9 ,
V_63 , F_26 ( V_17 ) , V_56 / 1000 ) ;
if ( F_27 ( V_56 < 5000000L || V_56 > 70000000L ) ) {
F_12 ( V_73 L_10
L_11 , V_63 , F_26 ( V_17 ) , V_56 ) ;
goto V_74;
}
#ifdef F_28
F_5 ( L_12 , V_65 ) ;
F_3 ( 0x02 , V_44 + 0x01 ) ;
V_69 = F_4 ( V_44 + 0x03 ) ;
F_3 ( 0x03 , V_44 + 0x01 ) ;
V_70 = F_4 ( V_44 + 0x03 ) ;
F_5 ( L_13 , V_69 , V_70 ) ;
#endif
V_66 = V_65 / ( V_56 / 1000 ) ;
if ( V_66 < 8600L ) {
V_68 = 0x0d ;
} else if ( V_66 < 12900L ) {
V_68 = 0x08 ;
} else if ( V_66 < 16100L ) {
V_68 = 0x06 ;
} else if ( V_66 < 64000L ) {
V_68 = 0x00 ;
} else {
F_12 ( V_73 L_14 ,
V_63 , F_26 ( V_17 ) , V_66 ) ;
goto V_74;
}
V_67 = ( V_66 * ( V_68 + 2 ) ) / 1000 - 2 ;
F_5 ( L_15 , V_67 , V_68 , V_66 ) ;
if ( F_27 ( V_67 < 0 || V_67 > 127 ) ) {
F_12 ( V_73 L_16 ,
V_63 , F_26 ( V_17 ) , V_67 ) ;
goto V_74;
}
V_69 = ( T_1 ) V_67 ;
V_70 = ( T_1 ) V_68 ;
F_5 ( L_17 , V_69 , V_70 ) ;
F_3 ( 0x02 , V_44 + 0x01 ) ;
F_3 ( V_69 , V_44 + 0x03 ) ;
F_3 ( 0x03 , V_44 + 0x01 ) ;
F_3 ( V_70 , V_44 + 0x03 ) ;
F_16 ( 30 ) ;
#ifdef F_28
F_3 ( 0x02 , V_44 + 0x01 ) ;
V_69 = F_4 ( V_44 + 0x03 ) ;
F_3 ( 0x03 , V_44 + 0x01 ) ;
V_70 = F_4 ( V_44 + 0x03 ) ;
F_5 ( L_13 , V_69 , V_70 ) ;
#endif
V_74:
return 0 ;
}
static struct V_1 * F_29 ( struct V_1 * V_17 )
{
struct V_1 * V_75 ;
V_75 = F_30 ( V_17 -> V_76 , F_31 ( F_32 ( V_17 -> V_77 ) + 1 ,
F_33 ( V_17 -> V_77 ) ) ) ;
if ( V_75 &&
V_75 -> V_78 == V_17 -> V_78 &&
V_75 -> V_4 == V_17 -> V_4 ) {
if ( V_75 -> V_79 != V_17 -> V_79 ) {
V_75 -> V_79 = V_17 -> V_79 ;
F_12 (KERN_INFO DRV_NAME L_18
L_19 , pci_name(dev)) ;
}
return V_75 ;
}
return NULL ;
}
static int F_34 ( struct V_1 * V_17 , const struct V_80 * V_81 )
{
const struct V_82 * V_83 = & V_84 [ V_81 -> V_85 ] ;
struct V_1 * V_86 = V_17 -> V_76 -> V_87 ;
if ( V_17 -> V_4 == V_10 && V_86 &&
V_86 -> V_78 == V_88 &&
V_86 -> V_4 == V_89 ) {
struct V_1 * V_75 ;
if ( F_32 ( V_17 -> V_77 ) & 2 )
return - V_90 ;
V_75 = F_29 ( V_17 ) ;
if ( V_75 ) {
int V_91 = F_35 ( V_17 , V_75 , V_83 , NULL ) ;
if ( V_91 < 0 )
F_36 ( V_75 ) ;
return V_91 ;
}
}
if ( V_17 -> V_4 == V_6 && V_86 &&
V_86 -> V_78 == V_92 &&
( V_86 -> V_4 == V_93 ||
V_86 -> V_4 == V_94 ) ) {
F_12 (KERN_INFO DRV_NAME L_20
L_21 , pci_name(dev)) ;
return - V_90 ;
}
return F_37 ( V_17 , V_83 , NULL ) ;
}
static void F_38 ( struct V_1 * V_17 )
{
struct V_95 * V_96 = F_39 ( V_17 ) ;
struct V_1 * V_75 = V_96 -> V_17 [ 1 ] ? F_8 ( V_96 -> V_17 [ 1 ] ) : NULL ;
F_40 ( V_17 ) ;
F_36 ( V_75 ) ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_97 ) ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_97 ) ;
}
