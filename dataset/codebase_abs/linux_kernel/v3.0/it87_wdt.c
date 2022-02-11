static inline void F_1 ( void )
{
F_2 ( 0x87 , V_1 ) ;
F_2 ( 0x01 , V_1 ) ;
F_2 ( 0x55 , V_1 ) ;
F_2 ( 0x55 , V_1 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 0x02 , V_1 ) ;
F_2 ( 0x02 , V_2 ) ;
}
static inline void F_4 ( int V_3 )
{
F_2 ( V_4 , V_1 ) ;
F_2 ( V_3 , V_2 ) ;
}
static inline int F_5 ( int V_5 )
{
F_2 ( V_5 , V_1 ) ;
return F_6 ( V_2 ) ;
}
static inline void F_7 ( int V_6 , int V_5 )
{
F_2 ( V_5 , V_1 ) ;
F_2 ( V_6 , V_2 ) ;
}
static inline int F_8 ( int V_5 )
{
int V_6 ;
F_2 ( V_5 ++ , V_1 ) ;
V_6 = F_6 ( V_2 ) << 8 ;
F_2 ( V_5 , V_1 ) ;
V_6 |= F_6 ( V_2 ) ;
return V_6 ;
}
static inline void F_9 ( int V_6 , int V_5 )
{
F_2 ( V_5 ++ , V_1 ) ;
F_2 ( V_6 >> 8 , V_2 ) ;
F_2 ( V_5 , V_1 ) ;
F_2 ( V_6 , V_2 ) ;
}
static void F_10 ( void )
{
unsigned char V_7 = V_8 ;
int V_9 = V_10 ;
if ( V_11 )
V_7 = 0 ;
if ( V_9 <= V_12 )
V_7 |= V_13 ;
else
V_9 /= 60 ;
if ( V_14 != V_15 )
V_7 |= V_16 ;
F_7 ( V_7 , V_17 ) ;
F_7 ( V_9 , V_18 ) ;
if ( V_12 > 255 )
F_7 ( V_9 >> 8 , V_19 ) ;
}
static int F_11 ( int V_20 )
{
V_20 += 59 ;
V_20 -= V_20 % 60 ;
return V_20 ;
}
static void F_12 ( void )
{
if ( F_13 ( V_21 , & V_22 ) )
F_6 ( V_23 ) ;
else
F_2 ( 0x55 , F_14 ( V_23 ) ) ;
F_15 ( V_24 , & V_22 ) ;
}
static void F_16 ( void )
{
unsigned long V_25 ;
F_17 ( & V_26 , V_25 ) ;
F_1 () ;
F_4 ( V_27 ) ;
if ( F_13 ( V_21 , & V_22 ) )
F_7 ( V_28 , V_29 ) ;
else
F_7 ( V_30 , V_29 ) ;
F_10 () ;
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
}
static void F_19 ( void )
{
unsigned long V_25 ;
F_17 ( & V_26 , V_25 ) ;
F_1 () ;
F_4 ( V_27 ) ;
F_7 ( 0x00 , V_29 ) ;
F_7 ( V_13 , V_17 ) ;
F_7 ( 0x00 , V_18 ) ;
if ( V_12 > 255 )
F_7 ( 0x00 , V_19 ) ;
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
}
static int F_20 ( int V_20 )
{
unsigned long V_25 ;
if ( V_20 < 1 || V_20 > V_12 * 60 )
return - V_31 ;
if ( V_20 > V_12 )
V_10 = F_11 ( V_20 ) ;
else
V_10 = V_20 ;
F_17 ( & V_26 , V_25 ) ;
if ( F_13 ( V_32 , & V_22 ) ) {
F_1 () ;
F_4 ( V_27 ) ;
F_10 () ;
F_3 () ;
}
F_18 ( & V_26 , V_25 ) ;
return 0 ;
}
static int F_21 ( int * V_33 )
{
unsigned long V_25 ;
* V_33 = 0 ;
if ( V_11 ) {
F_17 ( & V_26 , V_25 ) ;
F_1 () ;
F_4 ( V_27 ) ;
if ( F_5 ( V_29 ) & V_34 ) {
F_7 ( 0x00 , V_29 ) ;
F_22 ( V_32 , & V_22 ) ;
* V_33 |= V_35 ;
}
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
}
if ( F_23 ( V_24 , & V_22 ) )
* V_33 |= V_36 ;
if ( F_13 ( V_37 , & V_22 ) )
* V_33 |= V_38 ;
return 0 ;
}
static int F_24 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
if ( V_41 && F_25 ( V_42 , & V_22 ) )
return - V_43 ;
if ( ! F_25 ( V_32 , & V_22 ) ) {
if ( V_44 && ! F_25 ( V_45 , & V_22 ) )
F_26 ( V_46 ) ;
F_16 () ;
}
return F_27 ( V_39 , V_40 ) ;
}
static int F_28 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
if ( F_13 ( V_32 , & V_22 ) ) {
if ( F_23 ( V_37 , & V_22 ) ) {
F_19 () ;
F_22 ( V_32 , & V_22 ) ;
} else {
F_12 () ;
F_29 (KERN_CRIT PFX
L_1 ) ;
}
}
F_22 ( V_42 , & V_22 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_40 * V_40 , const char T_2 * V_47 ,
T_3 V_48 , T_4 * V_49 )
{
if ( V_48 ) {
F_22 ( V_37 , & V_22 ) ;
F_12 () ;
}
if ( ! V_44 ) {
T_3 V_50 ;
for ( V_50 = 0 ; V_50 != V_48 ; V_50 ++ ) {
char V_51 ;
if ( F_31 ( V_51 , V_47 + V_50 ) )
return - V_52 ;
if ( V_51 == V_53 )
F_15 ( V_37 , & V_22 ) ;
}
}
return V_48 ;
}
static long F_32 ( struct V_40 * V_40 , unsigned int V_54 , unsigned long V_55 )
{
int V_56 = 0 , V_33 , V_57 , V_58 ;
union {
struct V_59 T_2 * V_60 ;
int T_2 * V_61 ;
} V_62 ;
V_62 . V_61 = ( int T_2 * ) V_55 ;
switch ( V_54 ) {
case V_63 :
return F_33 ( V_62 . V_60 ,
& V_60 , sizeof( V_60 ) ) ? - V_52 : 0 ;
case V_64 :
F_21 ( & V_33 ) ;
return F_34 ( V_33 , V_62 . V_61 ) ;
case V_65 :
return F_34 ( 0 , V_62 . V_61 ) ;
case V_66 :
F_12 () ;
return 0 ;
case V_67 :
if ( F_31 ( V_57 , V_62 . V_61 ) )
return - V_52 ;
switch ( V_57 ) {
case V_68 :
if ( F_13 ( V_32 , & V_22 ) )
F_19 () ;
F_22 ( V_32 , & V_22 ) ;
return 0 ;
case V_69 :
if ( ! F_25 ( V_32 , & V_22 ) )
F_16 () ;
return 0 ;
default:
return - V_52 ;
}
case V_70 :
if ( F_31 ( V_58 , V_62 . V_61 ) )
return - V_52 ;
V_56 = F_20 ( V_58 ) ;
case V_71 :
if ( F_34 ( V_10 , V_62 . V_61 ) )
return - V_52 ;
return V_56 ;
default:
return - V_72 ;
}
}
static int F_35 ( struct V_73 * V_74 , unsigned long V_75 ,
void * V_76 )
{
if ( V_75 == V_77 || V_75 == V_78 )
F_19 () ;
return V_79 ;
}
static int T_5 F_36 ( void )
{
int V_56 = 0 ;
int V_80 = ! V_81 ;
T_6 V_82 ;
unsigned long V_25 ;
V_22 = 0 ;
F_17 ( & V_26 , V_25 ) ;
F_1 () ;
V_14 = F_8 ( V_83 ) ;
V_82 = F_5 ( V_84 ) & 0x0f ;
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
switch ( V_14 ) {
case V_85 :
V_12 = 255 ;
break;
case V_86 :
V_12 = ( V_82 < 8 ) ? 255 : 65535 ;
break;
case V_87 :
case V_88 :
V_12 = 65535 ;
break;
case V_89 :
case V_90 :
case V_15 :
V_12 = 65535 ;
V_80 = 0 ;
break;
case V_91 :
F_29 (KERN_ERR PFX
L_2 ,
chip_type, chip_rev) ;
return - V_92 ;
case V_93 :
F_29 (KERN_ERR PFX L_3 ) ;
return - V_92 ;
default:
F_29 (KERN_ERR PFX
L_4 ,
chip_type, chip_rev) ;
return - V_92 ;
}
F_17 ( & V_26 , V_25 ) ;
F_1 () ;
F_4 ( V_27 ) ;
F_7 ( V_13 , V_17 ) ;
F_7 ( 0x00 , V_29 ) ;
if ( V_80 ) {
F_4 ( V_94 ) ;
V_23 = F_8 ( V_95 ) ;
if ( ! V_23 ) {
V_23 = V_96 ;
F_9 ( V_23 , V_95 ) ;
}
V_97 = F_5 ( V_98 ) ;
F_7 ( 0x01 , V_98 ) ;
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
if ( F_37 ( V_23 , 1 , V_99 ) )
F_15 ( V_21 , & V_22 ) ;
else
V_56 = - V_100 ;
} else {
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
}
if ( ! F_13 ( V_21 , & V_22 ) ) {
if ( ! F_37 ( V_101 , 8 , V_99 ) ) {
if ( V_56 == - V_100 )
F_29 (KERN_ERR PFX
L_5
L_6 , base, CIR_BASE) ;
else
F_29 (KERN_ERR PFX
L_7 ,
CIR_BASE) ;
V_56 = - V_100 ;
goto V_102;
}
V_23 = V_101 ;
F_17 ( & V_26 , V_25 ) ;
F_1 () ;
F_4 ( V_103 ) ;
F_9 ( V_23 , V_95 ) ;
F_7 ( 0x00 , V_104 ) ;
V_105 = F_5 ( V_98 ) ;
F_7 ( 0x01 , V_98 ) ;
if ( V_56 == - V_100 ) {
F_4 ( V_94 ) ;
F_7 ( V_97 , V_98 ) ;
}
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
}
if ( V_10 < 1 || V_10 > V_12 * 60 ) {
V_10 = V_106 ;
F_29 (KERN_WARNING PFX
L_8 ,
DEFAULT_TIMEOUT) ;
}
if ( V_10 > V_12 )
V_10 = F_11 ( V_10 ) ;
V_56 = F_38 ( & V_107 ) ;
if ( V_56 ) {
F_29 (KERN_ERR PFX
L_9 , rc) ;
goto V_108;
}
V_56 = F_39 ( & V_109 ) ;
if ( V_56 ) {
F_29 (KERN_ERR PFX
L_10 ,
wdt_miscdev.minor, rc) ;
goto V_110;
}
if ( ! F_13 ( V_21 , & V_22 ) ) {
F_2 ( 0x00 , F_40 ( V_23 ) ) ;
F_2 ( 0xc0 , F_41 ( V_23 ) ) ;
F_2 ( 0x5c , F_42 ( V_23 ) ) ;
F_2 ( 0x10 , F_43 ( V_23 ) ) ;
F_2 ( 0x00 , F_44 ( V_23 ) ) ;
F_2 ( 0x01 , F_45 ( V_23 ) ) ;
F_2 ( 0x09 , F_43 ( V_23 ) ) ;
}
F_29 (KERN_INFO PFX L_11
L_12
L_13 , chip_type, chip_rev, timeout,
nowayout, testmode, exclusive, nogameport) ;
return 0 ;
V_110:
F_46 ( & V_107 ) ;
V_108:
F_47 ( V_23 , F_13 ( V_21 , & V_22 ) ? 1 : 8 ) ;
if ( ! F_13 ( V_21 , & V_22 ) ) {
F_17 ( & V_26 , V_25 ) ;
F_1 () ;
F_4 ( V_103 ) ;
F_7 ( V_105 , V_98 ) ;
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
}
V_102:
if ( V_80 ) {
F_17 ( & V_26 , V_25 ) ;
F_1 () ;
F_4 ( V_94 ) ;
F_7 ( V_97 , V_98 ) ;
F_3 () ;
F_18 ( & V_26 , V_25 ) ;
}
return V_56 ;
}
static void T_7 F_48 ( void )
{
unsigned long V_25 ;
int V_111 ;
V_111 = ! F_49 ( & V_26 , V_25 ) ;
F_1 () ;
F_4 ( V_27 ) ;
F_7 ( 0x00 , V_29 ) ;
F_7 ( 0x00 , V_17 ) ;
F_7 ( 0x00 , V_18 ) ;
if ( V_12 > 255 )
F_7 ( 0x00 , V_19 ) ;
if ( F_13 ( V_21 , & V_22 ) ) {
F_4 ( V_94 ) ;
F_7 ( V_97 , V_98 ) ;
} else {
F_4 ( V_103 ) ;
F_7 ( V_105 , V_98 ) ;
}
F_3 () ;
if ( ! V_111 )
F_18 ( & V_26 , V_25 ) ;
F_50 ( & V_109 ) ;
F_46 ( & V_107 ) ;
F_47 ( V_23 , F_13 ( V_21 , & V_22 ) ? 1 : 8 ) ;
}
