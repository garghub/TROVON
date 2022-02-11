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
struct V_52 V_53 , V_54 ;
long V_55 , V_56 ;
long V_57 , V_58 ;
T_1 V_59 ;
V_55 = F_13 ( V_15 ) ;
F_15 ( & V_53 ) ;
F_3 ( 0x01 , V_15 + 0x01 ) ;
V_59 = F_4 ( V_15 + 0x03 ) ;
F_5 ( L_6 , V_59 ) ;
F_3 ( V_59 | 0x40 , V_15 + 0x03 ) ;
F_16 ( 10 ) ;
V_56 = F_13 ( V_15 ) ;
F_15 ( & V_54 ) ;
F_3 ( 0x01 , V_15 + 0x01 ) ;
V_59 = F_4 ( V_15 + 0x03 ) ;
F_5 ( L_6 , V_59 ) ;
F_3 ( V_59 & ~ 0x40 , V_15 + 0x03 ) ;
V_58 = ( V_54 . V_60 - V_53 . V_60 ) * 1000000 +
( V_54 . V_61 - V_53 . V_61 ) ;
V_57 = ( ( V_55 - V_56 ) & 0x3fffffff ) / 10 *
( 10000000 / V_58 ) ;
F_5 ( L_7 , V_55 , V_56 ) ;
return V_57 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = F_18 ( V_2 ) ;
T_1 V_64 ;
if ( V_63 == NULL || ! F_19 ( V_63 , L_8 ) )
return;
if ( V_2 -> V_65 >= 0x03 ) {
F_20 ( V_2 , 0x40 , & V_64 ) ;
F_21 ( V_2 , 0x40 , ( V_64 | 0x01 ) ) ;
}
}
static int F_22 ( struct V_1 * V_17 )
{
const char * V_66 = V_67 ;
unsigned long V_15 = F_23 ( V_17 , 4 ) ;
unsigned long V_44 = V_15 + 0x08 ;
long V_57 , V_68 , V_69 ;
int V_70 , V_71 ;
T_1 V_72 , V_73 ;
if ( V_15 == 0 )
return - V_74 ;
#ifdef F_24
F_17 ( V_17 ) ;
#endif
switch( F_1 ( V_17 ) ) {
case 4 :
V_68 = 133333333 ;
break;
case 3 :
default:
V_68 = 100000000 ;
break;
}
V_57 = F_14 ( V_15 ) ;
F_12 ( V_75 L_9 ,
V_66 , F_25 ( V_17 ) , V_57 / 1000 ) ;
if ( F_26 ( V_57 < 5000000L || V_57 > 70000000L ) ) {
F_12 ( V_76 L_10
L_11 , V_66 , F_25 ( V_17 ) , V_57 ) ;
goto V_77;
}
#ifdef F_27
F_5 ( L_12 , V_68 ) ;
F_3 ( 0x02 , V_44 + 0x01 ) ;
V_72 = F_4 ( V_44 + 0x03 ) ;
F_3 ( 0x03 , V_44 + 0x01 ) ;
V_73 = F_4 ( V_44 + 0x03 ) ;
F_5 ( L_13 , V_72 , V_73 ) ;
#endif
V_69 = V_68 / ( V_57 / 1000 ) ;
if ( V_69 < 8600L ) {
V_71 = 0x0d ;
} else if ( V_69 < 12900L ) {
V_71 = 0x08 ;
} else if ( V_69 < 16100L ) {
V_71 = 0x06 ;
} else if ( V_69 < 64000L ) {
V_71 = 0x00 ;
} else {
F_12 ( V_76 L_14 ,
V_66 , F_25 ( V_17 ) , V_69 ) ;
goto V_77;
}
V_70 = ( V_69 * ( V_71 + 2 ) ) / 1000 - 2 ;
F_5 ( L_15 , V_70 , V_71 , V_69 ) ;
if ( F_26 ( V_70 < 0 || V_70 > 127 ) ) {
F_12 ( V_76 L_16 ,
V_66 , F_25 ( V_17 ) , V_70 ) ;
goto V_77;
}
V_72 = ( T_1 ) V_70 ;
V_73 = ( T_1 ) V_71 ;
F_5 ( L_17 , V_72 , V_73 ) ;
F_3 ( 0x02 , V_44 + 0x01 ) ;
F_3 ( V_72 , V_44 + 0x03 ) ;
F_3 ( 0x03 , V_44 + 0x01 ) ;
F_3 ( V_73 , V_44 + 0x03 ) ;
F_16 ( 30 ) ;
#ifdef F_27
F_3 ( 0x02 , V_44 + 0x01 ) ;
V_72 = F_4 ( V_44 + 0x03 ) ;
F_3 ( 0x03 , V_44 + 0x01 ) ;
V_73 = F_4 ( V_44 + 0x03 ) ;
F_5 ( L_13 , V_72 , V_73 ) ;
#endif
V_77:
return 0 ;
}
static struct V_1 * F_28 ( struct V_1 * V_17 )
{
struct V_1 * V_78 ;
V_78 = F_29 ( V_17 -> V_79 , F_30 ( F_31 ( V_17 -> V_80 ) + 1 ,
F_32 ( V_17 -> V_80 ) ) ) ;
if ( V_78 &&
V_78 -> V_81 == V_17 -> V_81 &&
V_78 -> V_4 == V_17 -> V_4 ) {
if ( V_78 -> V_82 != V_17 -> V_82 ) {
V_78 -> V_82 = V_17 -> V_82 ;
F_12 (KERN_INFO DRV_NAME L_18
L_19 , pci_name(dev)) ;
}
return V_78 ;
}
return NULL ;
}
static int F_33 ( struct V_1 * V_17 , const struct V_83 * V_84 )
{
const struct V_85 * V_86 = & V_87 [ V_84 -> V_88 ] ;
struct V_1 * V_89 = V_17 -> V_79 -> V_90 ;
if ( V_17 -> V_4 == V_10 && V_89 &&
V_89 -> V_81 == V_91 &&
V_89 -> V_4 == V_92 ) {
struct V_1 * V_78 ;
if ( F_31 ( V_17 -> V_80 ) & 2 )
return - V_93 ;
V_78 = F_28 ( V_17 ) ;
if ( V_78 ) {
int V_94 = F_34 ( V_17 , V_78 , V_86 , NULL ) ;
if ( V_94 < 0 )
F_35 ( V_78 ) ;
return V_94 ;
}
}
if ( V_17 -> V_4 == V_6 && V_89 &&
V_89 -> V_81 == V_95 &&
( V_89 -> V_4 == V_96 ||
V_89 -> V_4 == V_97 ) ) {
F_12 (KERN_INFO DRV_NAME L_20
L_21 , pci_name(dev)) ;
return - V_93 ;
}
return F_36 ( V_17 , V_86 , NULL ) ;
}
static void F_37 ( struct V_1 * V_17 )
{
struct V_98 * V_99 = F_38 ( V_17 ) ;
struct V_1 * V_78 = V_99 -> V_17 [ 1 ] ? F_8 ( V_99 -> V_17 [ 1 ] ) : NULL ;
F_39 ( V_17 ) ;
F_35 ( V_78 ) ;
}
static int T_5 F_40 ( void )
{
return F_41 ( & V_100 ) ;
}
static void T_6 F_42 ( void )
{
F_43 ( & V_100 ) ;
}
