static inline T_1 F_1 ( T_2 V_1 )
{
T_2 V_2 = F_2 () ;
return ( ( ( V_2 / V_1 ) / 2 ) - 1 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
T_1 V_5 = F_1 ( V_6 ) ;
F_4 ( V_7 ) ;
F_5 ( V_8 ) ;
F_6 ( V_9 ) ;
F_7 ( V_10 ) ;
F_8 ( V_11 ) ;
F_9 ( V_12 ) ;
F_10 ( V_13 ) ;
F_11 ( V_14 ) ;
F_12 ( V_15 ) ;
F_13 ( V_16 ) ;
F_14 ( V_17 ) ;
F_15 ( V_5 ) ;
if ( V_18 )
F_16 ( ( V_19 & ~ V_20 ) | V_21 |
V_22 ) ;
else
F_16 ( ( ( V_19 & ~ V_20 ) | V_23 ) &
~ V_22 ) ;
}
static int F_17 ( struct V_3 * V_4 )
{
F_18 ( V_24 ,
F_19 ( V_25 , V_26 ,
V_27 , V_28 ,
V_29 ,
V_30 ) ) ;
F_20 ( V_24 , ( V_31 * V_32 ) / V_33 ) ;
F_21 ( V_24 , V_33 / 8 ) ;
F_22 ( V_24 , V_34 ) ;
F_23 ( V_24 , V_33 / 8 ) ;
F_24 ( V_24 , ( unsigned long ) V_4 -> V_35 ) ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 )
{
T_1 V_36 [] = V_37 ;
T_1 V_38 = V_4 -> V_39 -> V_38 ;
if ( F_26 ( V_38 , V_40 ) ) {
F_27 ( V_41 L_1 , V_38 ) ;
return - V_42 ;
}
if ( F_28 ( V_36 , V_40 ) ) {
F_27 ( V_41 L_2 ) ;
F_29 ( V_38 ) ;
return - V_42 ;
}
if ( ! V_18 ) {
T_1 V_43 [] = V_44 ;
if ( F_28 ( V_43 , V_40 ) ) {
F_27 ( V_41 L_2 ) ;
F_30 ( V_36 ) ;
F_29 ( V_38 ) ;
return - V_42 ;
}
}
F_31 ( V_38 , 1 ) ;
return 0 ;
}
static void F_32 ( struct V_3 * V_4 )
{
T_1 V_36 [] = V_37 ;
F_29 ( V_4 -> V_39 -> V_38 ) ;
F_30 ( V_36 ) ;
if ( ! V_18 ) {
T_1 V_43 [] = V_44 ;
F_30 ( V_43 ) ;
}
}
static int F_33 ( struct V_45 * V_46 , int V_47 )
{
struct V_3 * V_4 = V_46 -> V_48 ;
F_34 ( & V_4 -> V_49 ) ;
V_4 -> V_50 ++ ;
if ( V_4 -> V_50 <= 1 ) {
F_16 ( 0 ) ;
F_35 () ;
F_17 ( V_4 ) ;
F_3 ( V_4 ) ;
F_36 ( V_24 ) ;
F_16 ( F_37 () | V_51 ) ;
}
F_38 ( & V_4 -> V_49 ) ;
return 0 ;
}
static int F_39 ( struct V_45 * V_46 , int V_47 )
{
struct V_3 * V_4 = V_46 -> V_48 ;
F_34 ( & V_4 -> V_49 ) ;
V_4 -> V_50 -- ;
if ( V_4 -> V_50 <= 0 ) {
F_16 ( 0 ) ;
F_35 () ;
F_40 ( V_24 ) ;
}
F_38 ( & V_4 -> V_49 ) ;
return 0 ;
}
static int F_41 ( struct V_52 * V_53 ,
struct V_45 * V_46 )
{
switch ( V_53 -> V_54 ) {
case 24 :
V_53 -> V_55 . V_56 = 16 ;
V_53 -> V_57 . V_56 = 8 ;
V_53 -> V_58 . V_56 = 0 ;
V_53 -> V_55 . V_59 = V_53 -> V_57 . V_59 = V_53 -> V_58 . V_59 = 8 ;
V_53 -> V_60 . V_56 = 0 ;
V_53 -> V_60 . V_59 = 0 ;
V_53 -> V_60 . V_61 = 0 ;
V_53 -> V_55 . V_61 = 0 ;
V_53 -> V_57 . V_61 = 0 ;
V_53 -> V_58 . V_61 = 0 ;
break;
default:
F_42 ( L_3 , V_62 ,
V_53 -> V_54 ) ;
return - V_63 ;
}
if ( V_46 -> V_53 . V_64 != V_53 -> V_64 || V_46 -> V_53 . V_65 != V_53 -> V_65 ||
V_46 -> V_53 . V_66 != V_53 -> V_66 ||
V_46 -> V_53 . V_67 != V_53 -> V_67 ) {
F_42 ( L_4 ,
V_62 , V_53 -> V_64 , V_53 -> V_65 ) ;
return - V_63 ;
}
if ( ( V_46 -> V_68 . V_69 * V_53 -> V_67 ) > V_46 -> V_68 . V_70 ) {
F_42 ( L_5 ,
V_62 , V_53 -> V_67 ) ;
return - V_71 ;
}
return 0 ;
}
int F_43 ( struct V_45 * V_46 , struct V_72 * V_73 )
{
if ( V_74 )
return 0 ;
else
return - V_63 ;
}
static int F_44 ( T_3 V_75 , T_3 V_55 , T_3 V_57 ,
T_3 V_58 , T_3 V_60 ,
struct V_45 * V_46 )
{
if ( V_75 >= V_76 )
return - V_63 ;
if ( V_46 -> V_53 . V_77 ) {
V_55 = V_57 = V_58 = ( V_55 * 77 + V_57 * 151 + V_58 * 28 ) >> 8 ;
}
if ( V_46 -> V_68 . V_78 == V_79 ) {
T_2 V_80 ;
if ( V_75 > 16 )
return - V_63 ;
V_55 >>= ( 16 - V_46 -> V_53 . V_55 . V_59 ) ;
V_57 >>= ( 16 - V_46 -> V_53 . V_57 . V_59 ) ;
V_58 >>= ( 16 - V_46 -> V_53 . V_58 . V_59 ) ;
V_80 = ( V_55 << V_46 -> V_53 . V_55 . V_56 ) |
( V_57 << V_46 -> V_53 . V_57 . V_56 ) |
( V_58 << V_46 -> V_53 . V_58 . V_56 ) ;
V_80 &= 0xFFFFFF ;
( ( T_2 * ) ( V_46 -> V_81 ) ) [ V_75 ] = V_80 ;
}
return 0 ;
}
static int F_45 ( struct V_82 * V_83 )
{
return 0 ;
}
static int F_46 ( struct V_84 * V_85 )
{
return 0 ;
}
static int F_47 ( struct V_84 * V_85 , int V_86 )
{
return 0 ;
}
static int F_48 ( struct V_84 * V_85 )
{
return 0 ;
}
static int F_49 ( struct V_84 * V_85 , int V_87 )
{
return 0 ;
}
static int F_50 ( struct V_84 * V_85 , struct V_45 * V_88 )
{
if ( ! V_88 || ( V_88 == & V_89 ) )
return 1 ;
return 0 ;
}
static T_4 F_51 ( int V_90 , void * V_91 )
{
T_1 V_92 = F_52 () ;
F_53 ( 0xFFFF ) ;
if ( V_92 ) {
F_16 ( F_37 () & ~ V_51 ) ;
F_40 ( V_24 ) ;
F_36 ( V_24 ) ;
F_16 ( F_37 () | V_51 ) ;
F_53 ( 0xFFFF ) ;
}
return V_93 ;
}
static int T_5 F_54 ( struct V_94 * V_95 )
{
#ifndef F_55
struct V_96 V_97 ;
#endif
struct V_3 * V_46 ;
struct V_45 * V_98 ;
int V_99 ;
F_27 (KERN_INFO DRIVER_NAME L_6 ) ;
if ( F_56 ( V_24 , L_7 ) < 0 ) {
F_27 (KERN_ERR DRIVER_NAME
L_8 ) ;
V_99 = - V_42 ;
goto V_100;
}
V_98 =
F_57 ( sizeof( struct V_3 ) , & V_95 -> V_85 ) ;
if ( ! V_98 ) {
V_99 = - V_71 ;
goto V_101;
}
V_46 = V_98 -> V_48 ;
V_46 -> V_102 = V_98 ;
V_46 -> V_85 = & V_95 -> V_85 ;
F_58 ( V_95 , V_98 ) ;
strcpy ( V_98 -> V_68 . V_103 , V_104 ) ;
V_46 -> V_39 = V_95 -> V_85 . V_105 ;
if ( V_46 -> V_39 == NULL ) {
F_59 ( & V_95 -> V_85 ,
L_9 ) ;
V_99 = - V_63 ;
goto V_106;
}
V_98 -> V_68 . type = V_107 ;
V_98 -> V_68 . V_108 = 0 ;
V_98 -> V_68 . V_109 = 0 ;
V_98 -> V_68 . V_110 = 0 ;
V_98 -> V_68 . V_111 = 0 ;
V_98 -> V_68 . V_112 = V_113 ;
V_98 -> V_68 . V_78 = V_79 ;
V_98 -> V_53 . V_114 = 0 ;
V_98 -> V_53 . V_115 = V_116 ;
V_98 -> V_53 . V_117 = V_46 -> V_39 -> V_117 ;
V_98 -> V_53 . V_118 = V_46 -> V_39 -> V_118 ;
V_98 -> V_53 . V_119 = 0 ;
V_98 -> V_53 . V_120 = V_121 ;
V_98 -> V_122 = & V_123 ;
V_98 -> V_124 = V_125 ;
V_98 -> V_53 . V_64 = V_46 -> V_39 -> V_64 . V_126 ;
V_98 -> V_53 . V_66 = V_46 -> V_39 -> V_64 . V_126 ;
V_98 -> V_53 . V_65 = V_46 -> V_39 -> V_65 . V_126 ;
V_98 -> V_53 . V_67 = V_46 -> V_39 -> V_65 . V_126 ;
V_98 -> V_53 . V_54 = V_46 -> V_39 -> V_127 . V_126 ;
V_98 -> V_53 . V_128 = 0 ;
V_98 -> V_53 . V_129 = 0 ;
V_98 -> V_53 . V_130 = 0 ;
V_98 -> V_53 . V_131 = 0 ;
V_98 -> V_53 . V_132 = 0 ;
V_98 -> V_53 . V_133 = 0 ;
V_98 -> V_53 . V_55 . V_56 = 16 ;
V_98 -> V_53 . V_57 . V_56 = 8 ;
V_98 -> V_53 . V_58 . V_56 = 0 ;
V_98 -> V_53 . V_60 . V_56 = 0 ;
V_98 -> V_53 . V_55 . V_59 = 8 ;
V_98 -> V_53 . V_57 . V_59 = 8 ;
V_98 -> V_53 . V_58 . V_59 = 8 ;
V_98 -> V_53 . V_60 . V_59 = 0 ;
V_98 -> V_68 . V_70 = V_46 -> V_39 -> V_64 . V_134 *
V_46 -> V_39 -> V_65 . V_134 * V_46 -> V_39 -> V_127 . V_134 / 8 ;
V_98 -> V_68 . V_69 = V_98 -> V_53 . V_66 *
V_98 -> V_53 . V_54 / 8 ;
V_46 -> V_35 =
F_60 ( NULL , V_98 -> V_68 . V_70 , & V_46 -> V_135 ,
V_136 ) ;
if ( NULL == V_46 -> V_35 ) {
F_27 (KERN_ERR DRIVER_NAME
L_10 ) ;
V_99 = - V_71 ;
goto V_106;
}
V_98 -> V_137 = ( void * ) V_46 -> V_35 ;
V_98 -> V_68 . V_138 = ( int ) V_46 -> V_35 ;
V_98 -> V_122 = & V_123 ;
V_98 -> V_81 = F_61 ( sizeof( T_2 ) * 16 , V_136 ) ;
if ( ! V_98 -> V_81 ) {
F_27 (KERN_ERR DRIVER_NAME
L_11 ) ;
V_99 = - V_71 ;
goto V_139;
}
if ( F_62 ( & V_98 -> V_140 , V_76 , 0 )
< 0 ) {
F_27 (KERN_ERR DRIVER_NAME
L_12 ,
BFIN_LCD_NBR_PALETTE_ENTRIES) ;
V_99 = - V_42 ;
goto V_141;
}
if ( F_25 ( V_46 ) ) {
F_27 (KERN_ERR DRIVER_NAME L_13 ) ;
V_99 = - V_42 ;
goto V_142;
}
V_46 -> V_90 = F_63 ( V_95 , 0 ) ;
if ( V_46 -> V_90 < 0 ) {
V_99 = - V_63 ;
goto V_143;
}
if ( F_64 ( V_46 -> V_90 , F_51 , 0 ,
L_14 , V_46 ) < 0 ) {
F_27 (KERN_ERR DRIVER_NAME
L_15 ) ;
V_99 = - V_42 ;
goto V_143;
}
if ( F_65 ( V_98 ) < 0 ) {
F_27 (KERN_ERR DRIVER_NAME
L_16 ) ;
V_99 = - V_63 ;
goto V_144;
}
#ifndef F_55
memset ( & V_97 , 0 , sizeof( struct V_96 ) ) ;
V_97 . type = V_145 ;
V_97 . V_146 = 255 ;
V_147 = F_66 ( L_17 , NULL , NULL ,
& V_148 , & V_97 ) ;
if ( F_67 ( V_147 ) ) {
F_27 (KERN_ERR DRIVER_NAME
L_18 ) ;
V_99 = - V_63 ;
F_68 ( V_98 ) ;
goto V_144;
}
V_149 = F_69 ( V_40 , & V_95 -> V_85 , NULL , & V_150 ) ;
V_149 -> V_97 . V_151 = 255 , F_27 ( V_152 L_19 ) ;
#endif
return 0 ;
V_144:
F_70 ( V_46 -> V_90 , V_46 ) ;
V_143:
F_32 ( V_46 ) ;
V_142:
F_71 ( & V_98 -> V_140 ) ;
V_141:
F_72 ( V_98 -> V_81 ) ;
V_139:
F_73 ( NULL , V_98 -> V_68 . V_70 , V_46 -> V_35 ,
V_46 -> V_135 ) ;
V_106:
F_74 ( V_98 ) ;
V_101:
F_75 ( V_24 ) ;
V_100:
F_58 ( V_95 , NULL ) ;
return V_99 ;
}
static int T_6 F_76 ( struct V_94 * V_95 )
{
struct V_45 * V_98 = F_77 ( V_95 ) ;
struct V_3 * V_46 = V_98 -> V_48 ;
F_75 ( V_24 ) ;
F_70 ( V_46 -> V_90 , V_46 ) ;
if ( V_46 -> V_35 != NULL )
F_73 ( NULL , V_98 -> V_68 . V_70 , V_46 -> V_35 ,
V_46 -> V_135 ) ;
F_72 ( V_98 -> V_81 ) ;
F_71 ( & V_98 -> V_140 ) ;
#ifndef F_55
F_78 ( V_149 ) ;
F_79 ( V_147 ) ;
#endif
F_68 ( V_98 ) ;
F_32 ( V_46 ) ;
F_27 (KERN_INFO DRIVER_NAME L_20 ) ;
return 0 ;
}
static int F_80 ( struct V_94 * V_95 , T_7 V_153 )
{
struct V_45 * V_98 = F_77 ( V_95 ) ;
F_16 ( F_37 () & ~ V_51 ) ;
F_40 ( V_24 ) ;
F_53 ( 0xFFFF ) ;
return 0 ;
}
static int F_81 ( struct V_94 * V_95 )
{
struct V_45 * V_98 = F_77 ( V_95 ) ;
struct V_3 * V_46 = V_98 -> V_48 ;
if ( V_46 -> V_50 ) {
F_16 ( 0 ) ;
F_35 () ;
F_17 ( V_46 ) ;
F_3 ( V_46 ) ;
F_36 ( V_24 ) ;
F_16 ( F_37 () | V_51 ) ;
}
return 0 ;
}
static int T_8 F_82 ( void )
{
return F_83 ( & V_154 ) ;
}
static void T_9 F_84 ( void )
{
F_85 ( & V_154 ) ;
}
