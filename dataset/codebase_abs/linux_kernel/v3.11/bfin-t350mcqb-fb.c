static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
F_3 ( V_4 - 1 ) ;
F_4 ( V_5 ) ;
F_5 ( V_6 |
V_7 |
V_8 |
V_9 |
V_10 ) ;
}
static inline void F_6 ( void )
{
F_5 ( F_7 () & ~ V_11 ) ;
}
static inline void F_8 ( void )
{
F_5 ( F_7 () | V_11 ) ;
}
static void F_9 ( void )
{
unsigned long V_12 ;
F_10 ( V_12 ) ;
F_11 ( V_13 ) ;
F_11 ( V_14 ) ;
F_12 ( V_12 ) ;
}
static void F_13 ( void )
{
F_14 ( V_14 | V_13 ) ;
F_15 ( 0 , V_15 | V_16 |
V_17 | V_18 |
V_19 | V_20 ) ;
}
static void F_16 ( void )
{
F_13 () ;
F_17 ( V_21 , V_22 ) ;
F_18 ( V_21 , V_23 ) ;
F_19 ( V_21 , V_24 | V_25 |
V_26 | V_27 |
V_28 ) ;
F_17 ( V_29 , V_30 ) ;
F_18 ( V_29 , V_31 ) ;
F_19 ( V_29 , V_24 | V_25 |
V_26 | V_27 |
V_28 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_32 ,
F_22 ( V_33 , V_34 ,
V_35 , V_36 ,
V_37 ,
V_38 ) ) ;
F_23 ( V_32 , ( V_39 * V_40 ) / V_41 ) ;
F_24 ( V_32 , V_41 / 8 ) ;
F_25 ( V_32 , V_5 ) ;
F_26 ( V_32 , V_41 / 8 ) ;
F_27 ( V_32 , ( unsigned long ) V_2 -> V_42 ) ;
}
static int F_28 ( int V_43 )
{
if ( V_43 ) {
if ( F_29 ( V_44 , V_45 ) ) {
F_30 ( V_46 L_1 ) ;
return - V_47 ;
}
} else
F_31 ( V_44 ) ;
return 0 ;
}
static int F_32 ( struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_2 = V_49 -> V_51 ;
F_33 ( & V_2 -> V_52 ) ;
V_2 -> V_53 ++ ;
if ( V_2 -> V_53 <= 1 ) {
F_6 () ;
F_34 () ;
F_20 ( V_2 ) ;
F_1 ( V_2 ) ;
F_16 () ;
F_35 ( V_32 ) ;
F_8 () ;
F_9 () ;
}
F_36 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_37 ( struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_2 = V_49 -> V_51 ;
F_33 ( & V_2 -> V_52 ) ;
V_2 -> V_53 -- ;
if ( V_2 -> V_53 <= 0 ) {
F_6 () ;
F_34 () ;
F_38 ( V_32 ) ;
F_13 () ;
}
F_36 ( & V_2 -> V_52 ) ;
return 0 ;
}
static int F_39 ( struct V_54 * V_55 ,
struct V_48 * V_49 )
{
switch ( V_55 -> V_56 ) {
case 24 :
V_55 -> V_57 . V_58 = 0 ;
V_55 -> V_59 . V_58 = 8 ;
V_55 -> V_60 . V_58 = 16 ;
V_55 -> V_57 . V_61 = V_55 -> V_59 . V_61 = V_55 -> V_60 . V_61 = 8 ;
V_55 -> V_62 . V_58 = 0 ;
V_55 -> V_62 . V_61 = 0 ;
V_55 -> V_62 . V_63 = 0 ;
V_55 -> V_57 . V_63 = 0 ;
V_55 -> V_59 . V_63 = 0 ;
V_55 -> V_60 . V_63 = 0 ;
break;
default:
F_40 ( L_2 , V_64 ,
V_55 -> V_56 ) ;
return - V_65 ;
}
if ( V_49 -> V_55 . V_66 != V_55 -> V_66 || V_49 -> V_55 . V_67 != V_55 -> V_67 ||
V_49 -> V_55 . V_68 != V_55 -> V_68 ||
V_49 -> V_55 . V_69 != V_55 -> V_69 ) {
F_40 ( L_3 ,
V_64 , V_55 -> V_66 , V_55 -> V_67 ) ;
return - V_65 ;
}
if ( ( V_49 -> V_70 . V_71 * V_55 -> V_69 ) > V_49 -> V_70 . V_72 ) {
F_40 ( L_4 ,
V_64 , V_55 -> V_69 ) ;
return - V_73 ;
}
return 0 ;
}
int F_41 ( struct V_48 * V_49 , struct V_74 * V_75 )
{
if ( V_76 )
return 0 ;
else
return - V_65 ;
}
static int F_42 ( T_1 V_77 , T_1 V_57 , T_1 V_59 ,
T_1 V_60 , T_1 V_62 ,
struct V_48 * V_49 )
{
if ( V_77 >= V_78 )
return - V_65 ;
if ( V_49 -> V_55 . V_79 ) {
V_57 = V_59 = V_60 = ( V_57 * 77 + V_59 * 151 + V_60 * 28 ) >> 8 ;
}
if ( V_49 -> V_70 . V_80 == V_81 ) {
T_2 V_82 ;
if ( V_77 > 16 )
return - V_65 ;
V_57 >>= ( 16 - V_49 -> V_55 . V_57 . V_61 ) ;
V_59 >>= ( 16 - V_49 -> V_55 . V_59 . V_61 ) ;
V_60 >>= ( 16 - V_49 -> V_55 . V_60 . V_61 ) ;
V_82 = ( V_57 << V_49 -> V_55 . V_57 . V_58 ) |
( V_59 << V_49 -> V_55 . V_59 . V_58 ) |
( V_60 << V_49 -> V_55 . V_60 . V_58 ) ;
V_82 &= 0xFFFFFF ;
( ( T_2 * ) ( V_49 -> V_83 ) ) [ V_77 ] = V_82 ;
}
return 0 ;
}
static int F_43 ( struct V_84 * V_85 )
{
return 0 ;
}
static int F_44 ( struct V_86 * V_87 )
{
return 0 ;
}
static int F_45 ( struct V_86 * V_87 , int V_88 )
{
return 0 ;
}
static int F_46 ( struct V_86 * V_87 )
{
return 0 ;
}
static int F_47 ( struct V_86 * V_87 , int V_89 )
{
return 0 ;
}
static int F_48 ( struct V_86 * V_87 , struct V_48 * V_90 )
{
if ( ! V_90 || ( V_90 == & V_91 ) )
return 1 ;
return 0 ;
}
static T_3 F_49 ( int V_92 , void * V_93 )
{
T_4 V_94 = F_50 () ;
F_51 ( 0xFFFF ) ;
if ( V_94 ) {
F_6 () ;
F_38 ( V_32 ) ;
F_35 ( V_32 ) ;
F_8 () ;
F_51 ( 0xFFFF ) ;
}
return V_95 ;
}
static int F_52 ( struct V_96 * V_97 )
{
#ifndef F_53
struct V_98 V_99 ;
#endif
struct V_1 * V_49 ;
struct V_48 * V_100 ;
int V_101 ;
F_30 (KERN_INFO DRIVER_NAME L_5 ,
LCD_X_RES, LCD_Y_RES, LCD_BPP) ;
if ( F_54 ( V_32 , L_6 ) < 0 ) {
F_30 (KERN_ERR DRIVER_NAME
L_7 ) ;
V_101 = - V_47 ;
goto V_102;
}
V_100 =
F_55 ( sizeof( struct V_1 ) , & V_97 -> V_87 ) ;
if ( ! V_100 ) {
V_101 = - V_73 ;
goto V_103;
}
V_49 = V_100 -> V_51 ;
V_49 -> V_104 = V_100 ;
V_49 -> V_87 = & V_97 -> V_87 ;
F_56 ( & V_49 -> V_52 ) ;
F_57 ( V_97 , V_100 ) ;
strcpy ( V_100 -> V_70 . V_105 , V_106 ) ;
V_100 -> V_70 . type = V_107 ;
V_100 -> V_70 . V_108 = 0 ;
V_100 -> V_70 . V_109 = 0 ;
V_100 -> V_70 . V_110 = 0 ;
V_100 -> V_70 . V_111 = 0 ;
V_100 -> V_70 . V_112 = V_113 ;
V_100 -> V_70 . V_80 = V_81 ;
V_100 -> V_55 . V_114 = 0 ;
V_100 -> V_55 . V_115 = V_116 ;
V_100 -> V_55 . V_117 = 53 ;
V_100 -> V_55 . V_118 = 70 ;
V_100 -> V_55 . V_119 = 0 ;
V_100 -> V_55 . V_120 = V_121 ;
V_100 -> V_55 . V_66 = V_39 ;
V_100 -> V_55 . V_68 = V_39 ;
V_100 -> V_55 . V_67 = V_122 ;
V_100 -> V_55 . V_69 = V_122 ;
V_100 -> V_55 . V_56 = V_40 ;
V_100 -> V_55 . V_57 . V_58 = 0 ;
V_100 -> V_55 . V_59 . V_58 = 8 ;
V_100 -> V_55 . V_60 . V_58 = 16 ;
V_100 -> V_55 . V_62 . V_58 = 0 ;
V_100 -> V_55 . V_57 . V_61 = 8 ;
V_100 -> V_55 . V_59 . V_61 = 8 ;
V_100 -> V_55 . V_60 . V_61 = 8 ;
V_100 -> V_55 . V_62 . V_61 = 0 ;
V_100 -> V_70 . V_72 = V_39 * V_122 * V_40 / 8 ;
V_100 -> V_70 . V_71 = V_100 -> V_55 . V_68 *
V_100 -> V_55 . V_56 / 8 ;
V_100 -> V_123 = & V_124 ;
V_100 -> V_12 = V_125 ;
V_49 -> V_42 = F_58 ( NULL , V_100 -> V_70 . V_72 +
V_126 ,
& V_49 -> V_127 , V_128 ) ;
if ( NULL == V_49 -> V_42 ) {
F_30 (KERN_ERR DRIVER_NAME
L_8 ) ;
V_101 = - V_73 ;
goto V_129;
}
V_100 -> V_130 = ( void * ) V_49 -> V_42 + V_126 ;
V_100 -> V_70 . V_131 = ( int ) V_49 -> V_42 + V_126 ;
V_100 -> V_123 = & V_124 ;
V_100 -> V_83 = & V_49 -> V_132 ;
if ( F_59 ( & V_100 -> V_133 , V_78 , 0 )
< 0 ) {
F_30 (KERN_ERR DRIVER_NAME
L_9 ,
BFIN_LCD_NBR_PALETTE_ENTRIES) ;
V_101 = - V_47 ;
goto V_134;
}
if ( F_28 ( 1 ) ) {
F_30 (KERN_ERR DRIVER_NAME L_10 ) ;
V_101 = - V_47 ;
goto V_135;
}
V_49 -> V_92 = F_60 ( V_97 , 0 ) ;
if ( V_49 -> V_92 < 0 ) {
V_101 = - V_65 ;
goto V_136;
}
V_101 = F_61 ( V_49 -> V_92 , F_49 , 0 ,
L_11 , V_49 ) ;
if ( V_101 < 0 ) {
F_30 (KERN_ERR DRIVER_NAME
L_12 ) ;
goto V_136;
}
if ( F_62 ( V_100 ) < 0 ) {
F_30 (KERN_ERR DRIVER_NAME
L_13 ) ;
V_101 = - V_65 ;
goto V_137;
}
#ifndef F_53
memset ( & V_99 , 0 , sizeof( struct V_98 ) ) ;
V_99 . type = V_138 ;
V_99 . V_139 = 255 ;
V_140 = F_63 ( L_14 , NULL , NULL ,
& V_141 , & V_99 ) ;
if ( F_64 ( V_140 ) ) {
F_30 (KERN_ERR DRIVER_NAME
L_15 ) ;
V_101 = - V_65 ;
F_65 ( V_100 ) ;
goto V_137;
}
V_142 = F_66 ( V_45 , NULL , & V_143 ) ;
V_142 -> V_99 . V_144 = 255 , F_30 ( V_145 L_16 ) ;
#endif
return 0 ;
V_137:
F_67 ( V_49 -> V_92 , V_49 ) ;
V_136:
F_28 ( 0 ) ;
V_135:
F_68 ( & V_100 -> V_133 ) ;
V_134:
F_69 ( NULL , V_100 -> V_70 . V_72 + V_126 ,
V_49 -> V_42 , V_49 -> V_127 ) ;
V_129:
F_70 ( V_100 ) ;
V_103:
F_71 ( V_32 ) ;
V_102:
return V_101 ;
}
static int F_72 ( struct V_96 * V_97 )
{
struct V_48 * V_100 = F_73 ( V_97 ) ;
struct V_1 * V_49 = V_100 -> V_51 ;
F_65 ( V_100 ) ;
F_71 ( V_32 ) ;
F_67 ( V_49 -> V_92 , V_49 ) ;
if ( V_49 -> V_42 != NULL )
F_69 ( NULL , V_100 -> V_70 . V_72 +
V_126 , V_49 -> V_42 ,
V_49 -> V_127 ) ;
F_68 ( & V_100 -> V_133 ) ;
#ifndef F_53
F_74 ( V_142 ) ;
F_75 ( V_140 ) ;
#endif
F_28 ( 0 ) ;
F_70 ( V_100 ) ;
F_30 (KERN_INFO DRIVER_NAME L_17 ) ;
return 0 ;
}
static int F_76 ( struct V_96 * V_97 , T_5 V_146 )
{
struct V_48 * V_100 = F_73 ( V_97 ) ;
struct V_1 * V_2 = V_100 -> V_51 ;
if ( V_2 -> V_53 ) {
F_6 () ;
F_38 ( V_32 ) ;
F_13 () ;
F_51 ( - 1 ) ;
}
return 0 ;
}
static int F_77 ( struct V_96 * V_97 )
{
struct V_48 * V_100 = F_73 ( V_97 ) ;
struct V_1 * V_2 = V_100 -> V_51 ;
if ( V_2 -> V_53 ) {
F_20 ( V_2 ) ;
F_1 ( V_2 ) ;
F_16 () ;
F_35 ( V_32 ) ;
F_8 () ;
F_9 () ;
}
return 0 ;
}
static int T_6 F_78 ( void )
{
return F_79 ( & V_147 ) ;
}
static void T_7 F_80 ( void )
{
F_81 ( & V_147 ) ;
}
