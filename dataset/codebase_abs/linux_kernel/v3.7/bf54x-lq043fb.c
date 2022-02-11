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
if ( F_26 ( V_38 , V_40 , V_41 ) ) {
F_27 ( V_42 L_1 , V_38 ) ;
return - V_43 ;
}
if ( F_28 ( V_36 , V_41 ) ) {
F_27 ( V_42 L_2 ) ;
F_29 ( V_38 ) ;
return - V_43 ;
}
if ( ! V_18 ) {
T_1 V_44 [] = V_45 ;
if ( F_28 ( V_44 , V_41 ) ) {
F_27 ( V_42 L_2 ) ;
F_30 ( V_36 ) ;
F_29 ( V_38 ) ;
return - V_43 ;
}
}
return 0 ;
}
static void F_31 ( struct V_3 * V_4 )
{
T_1 V_36 [] = V_37 ;
F_29 ( V_4 -> V_39 -> V_38 ) ;
F_30 ( V_36 ) ;
if ( ! V_18 ) {
T_1 V_44 [] = V_45 ;
F_30 ( V_44 ) ;
}
}
static int F_32 ( struct V_46 * V_47 , int V_48 )
{
struct V_3 * V_4 = V_47 -> V_49 ;
F_33 ( & V_4 -> V_50 ) ;
V_4 -> V_51 ++ ;
if ( V_4 -> V_51 <= 1 ) {
F_16 ( 0 ) ;
F_34 () ;
F_17 ( V_4 ) ;
F_3 ( V_4 ) ;
F_35 ( V_24 ) ;
F_16 ( F_36 () | V_52 ) ;
}
F_37 ( & V_4 -> V_50 ) ;
return 0 ;
}
static int F_38 ( struct V_46 * V_47 , int V_48 )
{
struct V_3 * V_4 = V_47 -> V_49 ;
F_33 ( & V_4 -> V_50 ) ;
V_4 -> V_51 -- ;
if ( V_4 -> V_51 <= 0 ) {
F_16 ( 0 ) ;
F_34 () ;
F_39 ( V_24 ) ;
}
F_37 ( & V_4 -> V_50 ) ;
return 0 ;
}
static int F_40 ( struct V_53 * V_54 ,
struct V_46 * V_47 )
{
switch ( V_54 -> V_55 ) {
case 24 :
V_54 -> V_56 . V_57 = 16 ;
V_54 -> V_58 . V_57 = 8 ;
V_54 -> V_59 . V_57 = 0 ;
V_54 -> V_56 . V_60 = V_54 -> V_58 . V_60 = V_54 -> V_59 . V_60 = 8 ;
V_54 -> V_61 . V_57 = 0 ;
V_54 -> V_61 . V_60 = 0 ;
V_54 -> V_61 . V_62 = 0 ;
V_54 -> V_56 . V_62 = 0 ;
V_54 -> V_58 . V_62 = 0 ;
V_54 -> V_59 . V_62 = 0 ;
break;
default:
F_41 ( L_3 , V_63 ,
V_54 -> V_55 ) ;
return - V_64 ;
}
if ( V_47 -> V_54 . V_65 != V_54 -> V_65 || V_47 -> V_54 . V_66 != V_54 -> V_66 ||
V_47 -> V_54 . V_67 != V_54 -> V_67 ||
V_47 -> V_54 . V_68 != V_54 -> V_68 ) {
F_41 ( L_4 ,
V_63 , V_54 -> V_65 , V_54 -> V_66 ) ;
return - V_64 ;
}
if ( ( V_47 -> V_69 . V_70 * V_54 -> V_68 ) > V_47 -> V_69 . V_71 ) {
F_41 ( L_5 ,
V_63 , V_54 -> V_68 ) ;
return - V_72 ;
}
return 0 ;
}
int F_42 ( struct V_46 * V_47 , struct V_73 * V_74 )
{
if ( V_75 )
return 0 ;
else
return - V_64 ;
}
static int F_43 ( T_3 V_76 , T_3 V_56 , T_3 V_58 ,
T_3 V_59 , T_3 V_61 ,
struct V_46 * V_47 )
{
if ( V_76 >= V_77 )
return - V_64 ;
if ( V_47 -> V_54 . V_78 ) {
V_56 = V_58 = V_59 = ( V_56 * 77 + V_58 * 151 + V_59 * 28 ) >> 8 ;
}
if ( V_47 -> V_69 . V_79 == V_80 ) {
T_2 V_81 ;
if ( V_76 > 16 )
return - V_64 ;
V_56 >>= ( 16 - V_47 -> V_54 . V_56 . V_60 ) ;
V_58 >>= ( 16 - V_47 -> V_54 . V_58 . V_60 ) ;
V_59 >>= ( 16 - V_47 -> V_54 . V_59 . V_60 ) ;
V_81 = ( V_56 << V_47 -> V_54 . V_56 . V_57 ) |
( V_58 << V_47 -> V_54 . V_58 . V_57 ) |
( V_59 << V_47 -> V_54 . V_59 . V_57 ) ;
V_81 &= 0xFFFFFF ;
( ( T_2 * ) ( V_47 -> V_82 ) ) [ V_76 ] = V_81 ;
}
return 0 ;
}
static int F_44 ( struct V_83 * V_84 )
{
return 0 ;
}
static int F_45 ( struct V_85 * V_86 )
{
return 0 ;
}
static int F_46 ( struct V_85 * V_86 , int V_87 )
{
return 0 ;
}
static int F_47 ( struct V_85 * V_86 )
{
return 0 ;
}
static int F_48 ( struct V_85 * V_86 , int V_88 )
{
return 0 ;
}
static int F_49 ( struct V_85 * V_86 , struct V_46 * V_89 )
{
if ( ! V_89 || ( V_89 == & V_90 ) )
return 1 ;
return 0 ;
}
static T_4 F_50 ( int V_91 , void * V_92 )
{
T_1 V_93 = F_51 () ;
F_52 ( 0xFFFF ) ;
if ( V_93 ) {
F_16 ( F_36 () & ~ V_52 ) ;
F_39 ( V_24 ) ;
F_35 ( V_24 ) ;
F_16 ( F_36 () | V_52 ) ;
F_52 ( 0xFFFF ) ;
}
return V_94 ;
}
static int T_5 F_53 ( struct V_95 * V_96 )
{
#ifndef F_54
struct V_97 V_98 ;
#endif
struct V_3 * V_47 ;
struct V_46 * V_99 ;
int V_100 ;
F_27 (KERN_INFO DRIVER_NAME L_6 ) ;
if ( F_55 ( V_24 , L_7 ) < 0 ) {
F_27 (KERN_ERR DRIVER_NAME
L_8 ) ;
V_100 = - V_43 ;
goto V_101;
}
V_99 =
F_56 ( sizeof( struct V_3 ) , & V_96 -> V_86 ) ;
if ( ! V_99 ) {
V_100 = - V_72 ;
goto V_102;
}
V_47 = V_99 -> V_49 ;
V_47 -> V_103 = V_99 ;
V_47 -> V_86 = & V_96 -> V_86 ;
F_57 ( & V_47 -> V_50 ) ;
F_58 ( V_96 , V_99 ) ;
strcpy ( V_99 -> V_69 . V_104 , V_105 ) ;
V_47 -> V_39 = V_96 -> V_86 . V_106 ;
if ( V_47 -> V_39 == NULL ) {
F_59 ( & V_96 -> V_86 ,
L_9 ) ;
V_100 = - V_64 ;
goto V_107;
}
V_99 -> V_69 . type = V_108 ;
V_99 -> V_69 . V_109 = 0 ;
V_99 -> V_69 . V_110 = 0 ;
V_99 -> V_69 . V_111 = 0 ;
V_99 -> V_69 . V_112 = 0 ;
V_99 -> V_69 . V_113 = V_114 ;
V_99 -> V_69 . V_79 = V_80 ;
V_99 -> V_54 . V_115 = 0 ;
V_99 -> V_54 . V_116 = V_117 ;
V_99 -> V_54 . V_118 = V_47 -> V_39 -> V_118 ;
V_99 -> V_54 . V_119 = V_47 -> V_39 -> V_119 ;
V_99 -> V_54 . V_120 = 0 ;
V_99 -> V_54 . V_121 = V_122 ;
V_99 -> V_123 = & V_124 ;
V_99 -> V_125 = V_126 ;
V_99 -> V_54 . V_65 = V_47 -> V_39 -> V_65 . V_127 ;
V_99 -> V_54 . V_67 = V_47 -> V_39 -> V_65 . V_127 ;
V_99 -> V_54 . V_66 = V_47 -> V_39 -> V_66 . V_127 ;
V_99 -> V_54 . V_68 = V_47 -> V_39 -> V_66 . V_127 ;
V_99 -> V_54 . V_55 = V_47 -> V_39 -> V_128 . V_127 ;
V_99 -> V_54 . V_129 = 0 ;
V_99 -> V_54 . V_130 = 0 ;
V_99 -> V_54 . V_131 = 0 ;
V_99 -> V_54 . V_132 = 0 ;
V_99 -> V_54 . V_133 = 0 ;
V_99 -> V_54 . V_134 = 0 ;
V_99 -> V_54 . V_56 . V_57 = 16 ;
V_99 -> V_54 . V_58 . V_57 = 8 ;
V_99 -> V_54 . V_59 . V_57 = 0 ;
V_99 -> V_54 . V_61 . V_57 = 0 ;
V_99 -> V_54 . V_56 . V_60 = 8 ;
V_99 -> V_54 . V_58 . V_60 = 8 ;
V_99 -> V_54 . V_59 . V_60 = 8 ;
V_99 -> V_54 . V_61 . V_60 = 0 ;
V_99 -> V_69 . V_71 = V_47 -> V_39 -> V_65 . V_135 *
V_47 -> V_39 -> V_66 . V_135 * V_47 -> V_39 -> V_128 . V_135 / 8 ;
V_99 -> V_69 . V_70 = V_99 -> V_54 . V_67 *
V_99 -> V_54 . V_55 / 8 ;
V_47 -> V_35 =
F_60 ( NULL , V_99 -> V_69 . V_71 , & V_47 -> V_136 ,
V_137 ) ;
if ( NULL == V_47 -> V_35 ) {
F_27 (KERN_ERR DRIVER_NAME
L_10 ) ;
V_100 = - V_72 ;
goto V_107;
}
V_99 -> V_138 = ( void * ) V_47 -> V_35 ;
V_99 -> V_69 . V_139 = ( int ) V_47 -> V_35 ;
V_99 -> V_123 = & V_124 ;
V_99 -> V_82 = F_61 ( & V_96 -> V_86 , sizeof( T_2 ) * 16 ,
V_137 ) ;
if ( ! V_99 -> V_82 ) {
F_27 (KERN_ERR DRIVER_NAME
L_11 ) ;
V_100 = - V_72 ;
goto V_140;
}
if ( F_62 ( & V_99 -> V_141 , V_77 , 0 )
< 0 ) {
F_27 (KERN_ERR DRIVER_NAME
L_12 ,
BFIN_LCD_NBR_PALETTE_ENTRIES) ;
V_100 = - V_43 ;
goto V_140;
}
if ( F_25 ( V_47 ) ) {
F_27 (KERN_ERR DRIVER_NAME L_13 ) ;
V_100 = - V_43 ;
goto V_142;
}
V_47 -> V_91 = F_63 ( V_96 , 0 ) ;
if ( V_47 -> V_91 < 0 ) {
V_100 = - V_64 ;
goto V_143;
}
if ( F_64 ( V_47 -> V_91 , F_50 , 0 ,
L_14 , V_47 ) < 0 ) {
F_27 (KERN_ERR DRIVER_NAME
L_15 ) ;
V_100 = - V_43 ;
goto V_143;
}
if ( F_65 ( V_99 ) < 0 ) {
F_27 (KERN_ERR DRIVER_NAME
L_16 ) ;
V_100 = - V_64 ;
goto V_144;
}
#ifndef F_54
memset ( & V_98 , 0 , sizeof( struct V_97 ) ) ;
V_98 . type = V_145 ;
V_98 . V_146 = 255 ;
V_147 = F_66 ( L_17 , NULL , NULL ,
& V_148 , & V_98 ) ;
if ( F_67 ( V_147 ) ) {
F_27 (KERN_ERR DRIVER_NAME
L_18 ) ;
V_100 = - V_64 ;
F_68 ( V_99 ) ;
goto V_144;
}
V_149 = F_69 ( V_41 , & V_96 -> V_86 , NULL , & V_150 ) ;
V_149 -> V_98 . V_151 = 255 , F_27 ( V_152 L_19 ) ;
#endif
return 0 ;
V_144:
F_70 ( V_47 -> V_91 , V_47 ) ;
V_143:
F_31 ( V_47 ) ;
V_142:
F_71 ( & V_99 -> V_141 ) ;
V_140:
F_72 ( NULL , V_99 -> V_69 . V_71 , V_47 -> V_35 ,
V_47 -> V_136 ) ;
V_107:
F_73 ( V_99 ) ;
V_102:
F_74 ( V_24 ) ;
V_101:
F_58 ( V_96 , NULL ) ;
return V_100 ;
}
static int T_6 F_75 ( struct V_95 * V_96 )
{
struct V_46 * V_99 = F_76 ( V_96 ) ;
struct V_3 * V_47 = V_99 -> V_49 ;
F_74 ( V_24 ) ;
F_70 ( V_47 -> V_91 , V_47 ) ;
if ( V_47 -> V_35 != NULL )
F_72 ( NULL , V_99 -> V_69 . V_71 , V_47 -> V_35 ,
V_47 -> V_136 ) ;
F_71 ( & V_99 -> V_141 ) ;
#ifndef F_54
F_77 ( V_149 ) ;
F_78 ( V_147 ) ;
#endif
F_68 ( V_99 ) ;
F_31 ( V_47 ) ;
F_27 (KERN_INFO DRIVER_NAME L_20 ) ;
return 0 ;
}
static int F_79 ( struct V_95 * V_96 , T_7 V_153 )
{
struct V_46 * V_99 = F_76 ( V_96 ) ;
F_16 ( F_36 () & ~ V_52 ) ;
F_39 ( V_24 ) ;
F_52 ( 0xFFFF ) ;
return 0 ;
}
static int F_80 ( struct V_95 * V_96 )
{
struct V_46 * V_99 = F_76 ( V_96 ) ;
struct V_3 * V_47 = V_99 -> V_49 ;
if ( V_47 -> V_51 ) {
F_16 ( 0 ) ;
F_34 () ;
F_17 ( V_47 ) ;
F_3 ( V_47 ) ;
F_35 ( V_24 ) ;
F_16 ( F_36 () | V_52 ) ;
}
return 0 ;
}
static int T_8 F_81 ( void )
{
return F_82 ( & V_154 ) ;
}
static void T_9 F_83 ( void )
{
F_84 ( & V_154 ) ;
}
