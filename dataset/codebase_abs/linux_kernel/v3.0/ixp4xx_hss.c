static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static inline void F_3 ( T_1 * V_5 , T_1 * V_6 , int V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_5 [ V_8 ] = F_4 ( V_6 [ V_8 ] ) ;
}
static void F_5 ( struct V_1 * V_1 , struct V_9 * V_9 , const char * V_10 )
{
T_1 * V_11 = ( T_1 * ) V_9 ;
if ( F_6 ( V_1 -> V_12 , V_9 , V_10 ) ) {
F_7 ( V_13 L_1
L_2 , V_1 -> V_14 , V_11 [ 0 ] , V_11 [ 1 ] ,
F_8 ( V_1 -> V_12 ) ) ;
F_9 () ;
}
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
int V_15 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_17 ;
V_9 . V_18 = V_1 -> V_14 ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_9 . V_20 >>= 2 ;
V_9 . V_20 |= V_21 << 30 ;
if ( V_15 % 16 == 15 ) {
V_9 . V_22 = V_23 + ( ( V_15 / 4 ) & ~ 3 ) ;
F_5 ( V_1 , & V_9 , L_3 ) ;
V_9 . V_22 += V_24 - V_23 ;
F_5 ( V_1 , & V_9 , L_4 ) ;
}
}
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_17 ;
V_9 . V_18 = V_1 -> V_14 ;
V_9 . V_22 = V_25 ;
V_9 . V_20 = V_26 | V_27 |
V_28 | V_29 ;
if ( V_1 -> V_30 == V_31 )
V_9 . V_20 |= V_32 ;
F_5 ( V_1 , & V_9 , L_5 ) ;
V_9 . V_22 = V_33 ;
V_9 . V_20 ^= V_28 | V_34 ;
F_5 ( V_1 , & V_9 , L_6 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_17 ;
V_9 . V_18 = V_1 -> V_14 ;
V_9 . V_22 = V_35 ;
V_9 . V_20 = ( V_1 -> V_36 ? V_37 : 0 ) |
( V_1 -> V_14 ? V_38 : 0 ) ;
F_5 ( V_1 , & V_9 , L_7 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_17 ;
V_9 . V_18 = V_1 -> V_14 ;
V_9 . V_22 = V_39 ;
V_9 . V_20 = V_1 -> V_40 ;
F_5 ( V_1 , & V_9 , L_8 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_17 ;
V_9 . V_18 = V_1 -> V_14 ;
V_9 . V_22 = V_41 ;
V_9 . V_42 = V_43 ;
V_9 . V_44 = V_45 - 1 ;
F_5 ( V_1 , & V_9 , L_9 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_17 ;
V_9 . V_18 = V_1 -> V_14 ;
V_9 . V_22 = V_46 ;
V_9 . V_42 = V_43 ;
V_9 . V_44 = V_45 - 1 ;
F_5 ( V_1 , & V_9 , L_10 ) ;
F_10 ( V_1 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_47 ;
V_9 . V_18 = V_1 -> V_14 ;
F_5 ( V_1 , & V_9 , L_11 ) ;
if ( F_12 ( V_1 -> V_12 , & V_9 , L_11 ) ||
V_9 . V_16 != V_47 || V_9 . V_20 ) {
F_7 ( V_13 L_12 ,
V_1 -> V_14 ) ;
F_9 () ;
}
F_12 ( V_1 -> V_12 , & V_9 , L_13 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_48 ;
V_9 . V_18 = V_1 -> V_14 ;
V_9 . V_49 = V_1 -> V_50 ;
V_9 . V_51 = V_1 -> V_50 | ( V_52 << 3 ) ;
F_5 ( V_1 , & V_9 , L_14 ) ;
}
static T_1 F_14 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_53 ;
V_9 . V_18 = V_1 -> V_14 ;
F_5 ( V_1 , & V_9 , L_15 ) ;
if ( F_12 ( V_1 -> V_12 , & V_9 , L_15 ) ) {
F_7 ( V_13 L_16 ,
V_1 -> V_14 ) ;
F_9 () ;
}
return V_9 . V_20 ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_54 ;
V_9 . V_18 = V_1 -> V_14 ;
V_9 . V_20 = 0 ;
F_5 ( V_1 , & V_9 , L_17 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_55 ;
V_9 . V_18 = V_1 -> V_14 ;
F_5 ( V_1 , & V_9 , L_18 ) ;
F_14 ( V_1 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
int V_56 ;
if ( V_1 -> V_57 )
return 0 ;
if ( ! F_18 ( V_1 -> V_12 ) &&
( V_56 = F_19 ( V_1 -> V_12 , F_8 ( V_1 -> V_12 ) ,
V_1 -> V_3 ) ) )
return V_56 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_16 = V_58 ;
V_9 . V_18 = V_1 -> V_14 ;
V_9 . V_49 = V_59 ;
F_5 ( V_1 , & V_9 , L_19 ) ;
V_9 . V_16 = V_60 ;
V_9 . V_49 = V_61 ;
F_5 ( V_1 , & V_9 , L_20 ) ;
V_9 . V_16 = V_62 ;
V_9 . V_49 = V_63 ;
F_5 ( V_1 , & V_9 , L_21 ) ;
V_9 . V_16 = V_64 ;
V_9 . V_42 = V_65 ;
F_5 ( V_1 , & V_9 , L_22 ) ;
V_9 . V_16 = V_66 ;
V_9 . V_20 = 0x7F7F7F7F ;
F_5 ( V_1 , & V_9 , L_23 ) ;
V_1 -> V_57 = 1 ;
return 0 ;
}
static inline void F_20 ( struct V_2 * V_3 , const char * V_67 ,
T_2 * V_68 , int V_69 )
{
#if V_70
int V_8 ;
F_7 ( V_71 L_24 , V_3 -> V_72 , V_67 , V_69 ) ;
for ( V_8 = 0 ; V_8 < V_69 ; V_8 ++ ) {
if ( V_8 >= V_70 )
break;
F_7 ( L_25 , ! ( V_8 % 4 ) ? L_26 : L_27 , V_68 [ V_8 ] ) ;
}
F_7 ( L_28 ) ;
#endif
}
static inline void F_21 ( T_1 V_73 , struct V_74 * V_74 )
{
#if V_75
F_7 ( V_71 L_29 ,
V_73 , V_74 -> V_76 , V_74 -> V_77 , V_74 -> V_78 ,
V_74 -> V_68 , V_74 -> V_79 , V_74 -> V_80 ) ;
#endif
}
static inline int F_22 ( unsigned int V_81 , struct V_1 * V_1 ,
int V_82 )
{
T_1 V_73 , V_83 , V_84 ;
struct V_74 * V_85 ;
if ( ! ( V_73 = F_23 ( V_81 ) ) )
return - 1 ;
F_24 ( V_73 & 0x1F ) ;
V_83 = V_82 ? F_25 ( V_1 , 0 ) : F_26 ( V_1 , 0 ) ;
V_85 = V_82 ? F_27 ( V_1 , 0 ) : F_28 ( V_1 , 0 ) ;
V_84 = ( V_73 - V_83 ) / sizeof( struct V_74 ) ;
F_24 ( V_84 >= ( V_82 ? V_86 : V_87 ) ) ;
F_21 ( V_73 , & V_85 [ V_84 ] ) ;
F_24 ( V_85 [ V_84 ] . V_76 ) ;
return V_84 ;
}
static inline void F_29 ( unsigned int V_81 , T_1 V_73 ,
struct V_74 * V_74 )
{
F_21 ( V_73 , V_74 ) ;
F_24 ( V_73 & 0x1F ) ;
F_30 ( V_81 , V_73 ) ;
}
static inline void F_31 ( struct V_1 * V_1 , struct V_74 * V_74 )
{
#ifdef F_32
F_33 ( & V_1 -> V_88 -> V_3 , V_74 -> V_68 ,
V_74 -> V_77 , V_89 ) ;
#else
F_33 ( & V_1 -> V_88 -> V_3 , V_74 -> V_68 & ~ 3 ,
F_34 ( ( V_74 -> V_68 & 3 ) + V_74 -> V_77 , 4 ) ,
V_89 ) ;
#endif
}
static void F_35 ( void * V_90 , int V_91 )
{
struct V_2 * V_88 = V_90 ;
struct V_1 * V_1 = F_1 ( V_88 ) ;
unsigned long V_92 ;
F_36 ( & V_93 , V_92 ) ;
V_1 -> V_91 = V_91 ;
if ( ! V_1 -> V_36 ) {
if ( V_91 )
F_37 ( V_88 ) ;
else
F_38 ( V_88 ) ;
}
F_39 ( & V_93 , V_92 ) ;
}
static void F_40 ( void * V_90 )
{
struct V_2 * V_3 = V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
#if V_94
F_7 ( V_71 L_30 , V_3 -> V_72 ) ;
#endif
F_41 ( V_95 [ V_1 -> V_14 ] . V_96 ) ;
F_42 ( & V_1 -> V_97 ) ;
}
static int F_43 ( struct V_98 * V_97 , int V_99 )
{
struct V_1 * V_1 = F_44 ( V_97 , struct V_1 , V_97 ) ;
struct V_2 * V_3 = V_1 -> V_88 ;
unsigned int V_100 = V_95 [ V_1 -> V_14 ] . V_96 ;
unsigned int V_101 = V_95 [ V_1 -> V_14 ] . V_102 ;
int V_103 = 0 ;
#if V_94
F_7 ( V_71 L_31 , V_3 -> V_72 ) ;
#endif
while ( V_103 < V_99 ) {
struct V_104 * V_105 ;
struct V_74 * V_74 ;
int V_106 ;
#ifdef F_32
struct V_104 * V_107 ;
T_1 V_73 ;
#endif
if ( ( V_106 = F_22 ( V_100 , V_1 , 0 ) ) < 0 ) {
#if V_94
F_7 ( V_71 L_32
L_33 , V_3 -> V_72 ) ;
#endif
F_45 ( V_97 ) ;
F_46 ( V_100 ) ;
if ( ! F_47 ( V_100 ) &&
F_48 ( V_97 ) ) {
#if V_94
F_7 ( V_71 L_32
L_34 ,
V_3 -> V_72 ) ;
#endif
F_41 ( V_100 ) ;
continue;
}
#if V_94
F_7 ( V_71 L_35 ,
V_3 -> V_72 ) ;
#endif
return V_103 ;
}
V_74 = F_28 ( V_1 , V_106 ) ;
#if 0
if (desc->error_count)
printk(KERN_DEBUG "%s: hss_hdlc_poll status 0x%02X"
" errors %u\n", dev->name, desc->status,
desc->error_count);
#endif
V_105 = NULL ;
switch ( V_74 -> V_79 ) {
case 0 :
#ifdef F_32
if ( ( V_105 = F_49 ( V_3 , V_108 ) ) != NULL ) {
V_73 = F_50 ( & V_3 -> V_3 , V_105 -> V_68 ,
V_108 ,
V_109 ) ;
if ( F_51 ( & V_3 -> V_3 , V_73 ) ) {
F_52 ( V_105 ) ;
V_105 = NULL ;
}
}
#else
V_105 = F_49 ( V_3 , V_74 -> V_78 ) ;
#endif
if ( ! V_105 )
V_3 -> V_110 . V_111 ++ ;
break;
case V_112 :
case V_113 :
V_3 -> V_110 . V_114 ++ ;
V_3 -> V_110 . V_115 ++ ;
break;
case V_116 :
V_3 -> V_110 . V_117 ++ ;
V_3 -> V_110 . V_115 ++ ;
break;
case V_118 :
V_3 -> V_110 . V_119 ++ ;
V_3 -> V_110 . V_115 ++ ;
break;
default:
F_7 ( V_120 L_36
L_37 , V_3 -> V_72 , V_74 -> V_79 ,
V_74 -> V_80 ) ;
V_3 -> V_110 . V_115 ++ ;
}
if ( ! V_105 ) {
V_74 -> V_77 = V_108 ;
V_74 -> V_78 = V_74 -> V_79 = 0 ;
F_29 ( V_101 , F_26 ( V_1 , V_106 ) , V_74 ) ;
continue;
}
#ifdef F_32
V_107 = V_105 ;
V_105 = V_1 -> V_121 [ V_106 ] ;
F_33 ( & V_3 -> V_3 , V_74 -> V_68 ,
V_108 , V_109 ) ;
#else
F_53 ( & V_3 -> V_3 , V_74 -> V_68 ,
V_108 , V_109 ) ;
F_3 ( ( T_1 * ) V_105 -> V_68 , ( T_1 * ) V_1 -> V_121 [ V_106 ] ,
F_34 ( V_74 -> V_78 , 4 ) / 4 ) ;
#endif
F_54 ( V_105 , V_74 -> V_78 ) ;
F_20 ( V_3 , L_38 , V_105 -> V_68 , V_105 -> V_69 ) ;
V_105 -> V_122 = F_55 ( V_105 , V_3 ) ;
V_3 -> V_110 . V_123 ++ ;
V_3 -> V_110 . V_124 += V_105 -> V_69 ;
F_56 ( V_105 ) ;
#ifdef F_32
V_1 -> V_121 [ V_106 ] = V_107 ;
V_74 -> V_68 = V_73 ;
#endif
V_74 -> V_77 = V_108 ;
V_74 -> V_78 = 0 ;
F_29 ( V_101 , F_26 ( V_1 , V_106 ) , V_74 ) ;
V_103 ++ ;
}
#if V_94
F_7 ( V_71 L_39 ) ;
#endif
return V_103 ;
}
static void F_57 ( void * V_90 )
{
struct V_2 * V_3 = V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_84 ;
#if V_125
F_7 (KERN_DEBUG DRV_NAME L_40 ) ;
#endif
while ( ( V_84 = F_22 ( V_95 [ V_1 -> V_14 ] . V_126 ,
V_1 , 1 ) ) >= 0 ) {
struct V_74 * V_74 ;
int V_127 ;
V_74 = F_27 ( V_1 , V_84 ) ;
V_3 -> V_110 . V_128 ++ ;
V_3 -> V_110 . V_129 += V_74 -> V_78 ;
F_31 ( V_1 , V_74 ) ;
#if V_125
F_7 ( V_71 L_41 ,
V_3 -> V_72 , V_1 -> V_130 [ V_84 ] ) ;
#endif
F_58 ( V_1 -> V_130 [ V_84 ] ) ;
V_1 -> V_130 [ V_84 ] = NULL ;
V_127 = F_59 ( V_1 -> V_131 -> V_132 ) ;
F_29 ( V_1 -> V_131 -> V_132 ,
F_25 ( V_1 , V_84 ) , V_74 ) ;
if ( V_127 ) {
#if V_125
F_7 ( V_71 L_42
L_43 , V_3 -> V_72 ) ;
#endif
F_60 ( V_3 ) ;
}
}
}
static int F_61 ( struct V_104 * V_105 , struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_132 = V_1 -> V_131 -> V_132 ;
int V_69 , V_133 , V_134 , V_106 ;
void * V_135 ;
T_1 V_73 ;
struct V_74 * V_74 ;
#if V_125
F_7 ( V_71 L_44 , V_3 -> V_72 ) ;
#endif
if ( F_62 ( V_105 -> V_69 > V_65 ) ) {
F_52 ( V_105 ) ;
V_3 -> V_110 . V_136 ++ ;
return V_137 ;
}
F_20 ( V_3 , L_45 , V_105 -> V_68 , V_105 -> V_69 ) ;
V_69 = V_105 -> V_69 ;
#ifdef F_32
V_133 = 0 ;
V_134 = V_69 ;
V_135 = V_105 -> V_68 ;
#else
V_133 = ( int ) V_105 -> V_68 & 3 ;
V_134 = F_34 ( V_133 + V_69 , 4 ) ;
if ( ! ( V_135 = F_63 ( V_134 , V_138 ) ) ) {
F_52 ( V_105 ) ;
V_3 -> V_110 . V_139 ++ ;
return V_137 ;
}
F_3 ( V_135 , ( T_1 * ) ( ( int ) V_105 -> V_68 & ~ 3 ) , V_134 / 4 ) ;
F_52 ( V_105 ) ;
#endif
V_73 = F_50 ( & V_3 -> V_3 , V_135 , V_134 , V_89 ) ;
if ( F_51 ( & V_3 -> V_3 , V_73 ) ) {
#ifdef F_32
F_52 ( V_105 ) ;
#else
F_64 ( V_135 ) ;
#endif
V_3 -> V_110 . V_139 ++ ;
return V_137 ;
}
V_106 = F_22 ( V_132 , V_1 , 1 ) ;
F_24 ( V_106 < 0 ) ;
V_74 = F_27 ( V_1 , V_106 ) ;
#ifdef F_32
V_1 -> V_130 [ V_106 ] = V_105 ;
#else
V_1 -> V_130 [ V_106 ] = V_135 ;
#endif
V_74 -> V_68 = V_73 + V_133 ;
V_74 -> V_77 = V_74 -> V_78 = V_69 ;
F_65 () ;
F_29 ( V_95 [ V_1 -> V_14 ] . V_140 , F_25 ( V_1 , V_106 ) , V_74 ) ;
if ( F_59 ( V_132 ) ) {
#if V_125
F_7 ( V_71 L_46 , V_3 -> V_72 ) ;
#endif
F_66 ( V_3 ) ;
if ( ! F_59 ( V_132 ) ) {
#if V_125
F_7 ( V_71 L_47 ,
V_3 -> V_72 ) ;
#endif
F_60 ( V_3 ) ;
}
}
#if V_125
F_7 ( V_71 L_48 , V_3 -> V_72 ) ;
#endif
return V_137 ;
}
static int F_67 ( struct V_1 * V_1 )
{
int V_56 ;
V_56 = F_68 ( V_95 [ V_1 -> V_14 ] . V_102 , V_87 , 0 , 0 ,
L_49 , V_1 -> V_88 -> V_72 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_68 ( V_95 [ V_1 -> V_14 ] . V_96 , V_87 , 0 , 0 ,
L_50 , V_1 -> V_88 -> V_72 ) ;
if ( V_56 )
goto V_141;
V_56 = F_68 ( V_95 [ V_1 -> V_14 ] . V_140 , V_86 , 0 , 0 ,
L_51 , V_1 -> V_88 -> V_72 ) ;
if ( V_56 )
goto V_142;
V_56 = F_68 ( V_1 -> V_131 -> V_132 , V_86 , 0 , 0 ,
L_52 , V_1 -> V_88 -> V_72 ) ;
if ( V_56 )
goto V_143;
V_56 = F_68 ( V_95 [ V_1 -> V_14 ] . V_126 , V_86 , 0 , 0 ,
L_53 , V_1 -> V_88 -> V_72 ) ;
if ( V_56 )
goto V_144;
return 0 ;
V_144:
F_69 ( V_1 -> V_131 -> V_132 ) ;
V_143:
F_69 ( V_95 [ V_1 -> V_14 ] . V_140 ) ;
V_142:
F_69 ( V_95 [ V_1 -> V_14 ] . V_96 ) ;
V_141:
F_69 ( V_95 [ V_1 -> V_14 ] . V_102 ) ;
F_7 ( V_71 L_54 ,
V_1 -> V_88 -> V_72 ) ;
return V_56 ;
}
static void F_70 ( struct V_1 * V_1 )
{
F_69 ( V_95 [ V_1 -> V_14 ] . V_102 ) ;
F_69 ( V_95 [ V_1 -> V_14 ] . V_96 ) ;
F_69 ( V_95 [ V_1 -> V_14 ] . V_126 ) ;
F_69 ( V_95 [ V_1 -> V_14 ] . V_140 ) ;
F_69 ( V_1 -> V_131 -> V_132 ) ;
}
static int F_71 ( struct V_1 * V_1 )
{
int V_8 ;
if ( ! V_145 )
if ( ! ( V_146 = F_72 ( V_147 , NULL ,
V_148 , 32 , 0 ) ) )
return - V_149 ;
if ( ! ( V_1 -> V_150 = F_73 ( V_146 , V_151 ,
& V_1 -> V_152 ) ) )
return - V_149 ;
memset ( V_1 -> V_150 , 0 , V_148 ) ;
memset ( V_1 -> V_121 , 0 , sizeof( V_1 -> V_121 ) ) ;
memset ( V_1 -> V_130 , 0 , sizeof( V_1 -> V_130 ) ) ;
for ( V_8 = 0 ; V_8 < V_87 ; V_8 ++ ) {
struct V_74 * V_74 = F_28 ( V_1 , V_8 ) ;
T_3 * V_153 ;
void * V_68 ;
#ifdef F_32
if ( ! ( V_153 = F_49 ( V_1 -> V_88 , V_108 ) ) )
return - V_149 ;
V_68 = V_153 -> V_68 ;
#else
if ( ! ( V_153 = F_63 ( V_108 , V_151 ) ) )
return - V_149 ;
V_68 = V_153 ;
#endif
V_74 -> V_77 = V_108 ;
V_74 -> V_68 = F_50 ( & V_1 -> V_88 -> V_3 , V_68 ,
V_108 , V_109 ) ;
if ( F_51 ( & V_1 -> V_88 -> V_3 , V_74 -> V_68 ) ) {
F_74 ( V_153 ) ;
return - V_154 ;
}
V_1 -> V_121 [ V_8 ] = V_153 ;
}
return 0 ;
}
static void F_75 ( struct V_1 * V_1 )
{
int V_8 ;
if ( V_1 -> V_150 ) {
for ( V_8 = 0 ; V_8 < V_87 ; V_8 ++ ) {
struct V_74 * V_74 = F_28 ( V_1 , V_8 ) ;
T_3 * V_153 = V_1 -> V_121 [ V_8 ] ;
if ( V_153 ) {
F_33 ( & V_1 -> V_88 -> V_3 ,
V_74 -> V_68 , V_108 ,
V_109 ) ;
F_74 ( V_153 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_86 ; V_8 ++ ) {
struct V_74 * V_74 = F_27 ( V_1 , V_8 ) ;
T_3 * V_153 = V_1 -> V_130 [ V_8 ] ;
if ( V_153 ) {
F_31 ( V_1 , V_74 ) ;
F_74 ( V_153 ) ;
}
}
F_76 ( V_146 , V_1 -> V_150 , V_1 -> V_152 ) ;
V_1 -> V_150 = NULL ;
}
if ( ! V_145 && V_146 ) {
F_77 ( V_146 ) ;
V_146 = NULL ;
}
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_92 ;
int V_8 , V_56 = 0 ;
if ( ( V_56 = F_79 ( V_3 ) ) )
return V_56 ;
if ( ( V_56 = F_17 ( V_1 ) ) )
goto V_155;
if ( ( V_56 = F_67 ( V_1 ) ) )
goto V_155;
if ( ( V_56 = F_71 ( V_1 ) ) )
goto V_156;
F_36 ( & V_93 , V_92 ) ;
if ( V_1 -> V_131 -> V_157 )
if ( ( V_56 = V_1 -> V_131 -> V_157 ( V_1 -> V_14 , V_3 ,
F_35 ) ) )
goto V_158;
F_39 ( & V_93 , V_92 ) ;
for ( V_8 = 0 ; V_8 < V_86 ; V_8 ++ )
F_29 ( V_1 -> V_131 -> V_132 ,
F_25 ( V_1 , V_8 ) , F_27 ( V_1 , V_8 ) ) ;
for ( V_8 = 0 ; V_8 < V_87 ; V_8 ++ )
F_29 ( V_95 [ V_1 -> V_14 ] . V_102 ,
F_26 ( V_1 , V_8 ) , F_28 ( V_1 , V_8 ) ) ;
F_80 ( & V_1 -> V_97 ) ;
F_81 ( V_3 ) ;
F_82 ( V_95 [ V_1 -> V_14 ] . V_96 , V_159 ,
F_40 , V_3 ) ;
F_82 ( V_95 [ V_1 -> V_14 ] . V_126 , V_159 ,
F_57 , V_3 ) ;
F_46 ( V_95 [ V_1 -> V_14 ] . V_126 ) ;
V_145 ++ ;
F_13 ( V_1 ) ;
F_11 ( V_1 ) ;
F_15 ( V_1 ) ;
F_42 ( & V_1 -> V_97 ) ;
return 0 ;
V_158:
F_39 ( & V_93 , V_92 ) ;
V_156:
F_75 ( V_1 ) ;
F_70 ( V_1 ) ;
V_155:
F_83 ( V_3 ) ;
return V_56 ;
}
static int F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_92 ;
int V_8 , V_160 = V_87 ;
F_36 ( & V_93 , V_92 ) ;
V_145 -- ;
F_41 ( V_95 [ V_1 -> V_14 ] . V_96 ) ;
F_66 ( V_3 ) ;
F_85 ( & V_1 -> V_97 ) ;
F_16 ( V_1 ) ;
while ( F_22 ( V_95 [ V_1 -> V_14 ] . V_102 , V_1 , 0 ) >= 0 )
V_160 -- ;
while ( F_22 ( V_95 [ V_1 -> V_14 ] . V_96 , V_1 , 0 ) >= 0 )
V_160 -- ;
if ( V_160 )
F_7 ( V_13 L_55
L_56 , V_3 -> V_72 , V_160 ) ;
V_160 = V_86 ;
while ( F_22 ( V_95 [ V_1 -> V_14 ] . V_140 , V_1 , 1 ) >= 0 )
V_160 -- ;
V_8 = 0 ;
do {
while ( F_22 ( V_1 -> V_131 -> V_132 , V_1 , 1 ) >= 0 )
V_160 -- ;
if ( ! V_160 )
break;
} while ( ++ V_8 < V_161 );
if ( V_160 )
F_7 ( V_13 L_57
L_58 , V_3 -> V_72 , V_160 ) ;
#if V_162
if ( ! V_160 )
F_7 ( V_71 L_59 , V_8 ) ;
#endif
F_41 ( V_95 [ V_1 -> V_14 ] . V_126 ) ;
if ( V_1 -> V_131 -> V_163 )
V_1 -> V_131 -> V_163 ( V_1 -> V_14 , V_3 ) ;
F_39 ( & V_93 , V_92 ) ;
F_75 ( V_1 ) ;
F_70 ( V_1 ) ;
F_83 ( V_3 ) ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 , unsigned short V_164 ,
unsigned short V_165 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_164 != V_166 )
return - V_167 ;
switch( V_165 ) {
case V_168 :
V_1 -> V_50 = 0 ;
return 0 ;
case V_169 :
V_1 -> V_50 = V_170 ;
return 0 ;
default:
return - V_167 ;
}
}
static T_1 F_87 ( T_1 V_171 , T_1 V_172 , T_1 V_173 , T_1 V_174 ,
T_1 * V_175 , T_1 * V_176 , T_1 * V_177 )
{
T_4 V_178 ;
T_1 V_179 ;
V_178 = V_180 * ( T_4 ) ( V_174 + 1 ) ;
F_88 ( V_178 , V_172 * ( V_174 + 1 ) + V_173 + 1 ) ;
V_179 = abs ( ( T_1 ) V_178 - V_171 ) ;
if ( V_179 < * V_176 ) {
* V_175 = V_178 ;
* V_176 = V_179 ;
* V_177 = ( V_172 << 22 ) | ( V_173 << 12 ) | V_174 ;
}
return V_179 ;
}
static void F_89 ( T_1 V_171 , T_1 * V_175 , T_1 * V_177 )
{
T_1 V_172 , V_173 , V_181 = 0xFFFFFFFF ;
V_172 = V_180 / V_171 ;
if ( V_172 > 0x3FF ) {
F_87 ( V_171 , 0x3FF , 1 , 1 , V_175 , & V_181 , V_177 ) ;
return;
}
if ( V_172 == 0 ) {
V_172 = 1 ;
V_171 = V_180 ;
}
if ( V_171 * V_172 == V_180 ) {
F_87 ( V_171 , V_172 - 1 , 1 , 1 , V_175 , & V_181 , V_177 ) ;
return;
}
for ( V_173 = 0 ; V_173 < 0x400 ; V_173 ++ ) {
T_4 V_174 = ( V_173 + 1 ) * ( T_4 ) V_171 ;
F_88 ( V_174 , V_180 - V_171 * V_172 ) ;
V_174 -- ;
if ( V_174 >= 0xFFF ) {
if ( V_173 == 0 &&
! F_87 ( V_171 , V_172 - 1 , 1 , 1 , V_175 , & V_181 , V_177 ) )
return;
F_87 ( V_171 , V_172 , V_173 , 0xFFF , V_175 , & V_181 , V_177 ) ;
return;
}
if ( ! F_87 ( V_171 , V_172 , V_173 , V_174 , V_175 , & V_181 , V_177 ) )
return;
if ( ! F_87 ( V_171 , V_172 , V_173 , V_174 + 1 , V_175 , & V_181 , V_177 ) )
return;
}
}
static int F_90 ( struct V_2 * V_3 , struct V_182 * V_183 , int V_16 )
{
const T_5 V_184 = sizeof( V_185 ) ;
V_185 V_186 ;
V_185 T_6 * line = V_183 -> V_187 . V_188 . V_189 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_92 ;
int V_190 ;
if ( V_16 != V_191 )
return F_91 ( V_3 , V_183 , V_16 ) ;
switch( V_183 -> V_187 . type ) {
case V_192 :
V_183 -> V_187 . type = V_193 ;
if ( V_183 -> V_187 . V_184 < V_184 ) {
V_183 -> V_187 . V_184 = V_184 ;
return - V_194 ;
}
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_30 = V_1 -> V_30 ;
V_186 . V_195 = V_1 -> V_195 ;
V_186 . V_36 = V_1 -> V_36 ;
if ( F_92 ( line , & V_186 , V_184 ) )
return - V_196 ;
return 0 ;
case V_197 :
case V_193 :
if( ! F_93 ( V_198 ) )
return - V_199 ;
if ( F_94 ( & V_186 , line , V_184 ) )
return - V_196 ;
V_190 = V_186 . V_30 ;
if ( V_1 -> V_131 -> V_200 )
V_190 = V_1 -> V_131 -> V_200 ( V_1 -> V_14 , V_190 ) ;
if ( V_190 != V_201 && V_190 != V_31 )
return - V_167 ;
if ( V_186 . V_36 != 0 && V_186 . V_36 != 1 )
return - V_167 ;
V_1 -> V_30 = V_190 ;
if ( V_190 == V_31 )
F_89 ( V_186 . V_195 , & V_1 -> V_195 ,
& V_1 -> V_40 ) ;
else {
V_1 -> V_195 = 0 ;
V_1 -> V_40 = V_202 ;
}
V_1 -> V_36 = V_186 . V_36 ;
F_36 ( & V_93 , V_92 ) ;
if ( V_3 -> V_92 & V_203 )
F_11 ( V_1 ) ;
if ( V_1 -> V_36 || V_1 -> V_91 )
F_37 ( V_1 -> V_88 ) ;
else
F_38 ( V_1 -> V_88 ) ;
F_39 ( & V_93 , V_92 ) ;
return 0 ;
default:
return F_91 ( V_3 , V_183 , V_16 ) ;
}
}
static int T_7 F_95 ( struct V_204 * V_90 )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
T_8 * V_205 ;
int V_56 ;
if ( ( V_1 = F_96 ( sizeof( * V_1 ) , V_151 ) ) == NULL )
return - V_149 ;
if ( ( V_1 -> V_12 = F_97 ( 0 ) ) == NULL ) {
V_56 = - V_206 ;
goto V_207;
}
if ( ( V_1 -> V_88 = V_3 = F_98 ( V_1 ) ) == NULL ) {
V_56 = - V_149 ;
goto V_208;
}
F_99 ( V_3 , & V_90 -> V_3 ) ;
V_205 = F_2 ( V_3 ) ;
V_205 -> V_209 = F_86 ;
V_205 -> V_210 = F_61 ;
V_3 -> V_211 = & V_212 ;
V_3 -> V_213 = 100 ;
V_1 -> V_30 = V_201 ;
V_1 -> V_195 = 0 ;
V_1 -> V_40 = V_202 ;
V_1 -> V_14 = V_90 -> V_14 ;
V_1 -> V_3 = & V_90 -> V_3 ;
V_1 -> V_131 = V_90 -> V_3 . V_214 ;
F_100 ( V_3 , & V_1 -> V_97 , F_43 , V_215 ) ;
if ( ( V_56 = F_101 ( V_3 ) ) )
goto V_216;
F_102 ( V_90 , V_1 ) ;
F_7 ( V_217 L_60 , V_3 -> V_72 , V_1 -> V_14 ) ;
return 0 ;
V_216:
F_103 ( V_3 ) ;
V_208:
F_104 ( V_1 -> V_12 ) ;
V_207:
F_64 ( V_1 ) ;
return V_56 ;
}
static int T_9 F_105 ( struct V_204 * V_90 )
{
struct V_1 * V_1 = F_106 ( V_90 ) ;
F_107 ( V_1 -> V_88 ) ;
F_103 ( V_1 -> V_88 ) ;
F_104 ( V_1 -> V_12 ) ;
F_102 ( V_90 , NULL ) ;
F_64 ( V_1 ) ;
return 0 ;
}
static int T_10 F_108 ( void )
{
if ( ( F_109 () &
( V_218 | V_219 ) ) !=
( V_218 | V_219 ) )
return - V_206 ;
F_110 ( & V_93 ) ;
return F_111 ( & V_220 ) ;
}
static void T_11 F_112 ( void )
{
F_113 ( & V_220 ) ;
}
