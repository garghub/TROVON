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
F_7 ( L_1 ,
V_1 -> V_13 , V_11 [ 0 ] , V_11 [ 1 ] , F_8 ( V_1 -> V_12 ) ) ;
F_9 () ;
}
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
int V_14 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_16 ;
V_9 . V_17 = V_1 -> V_13 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
V_9 . V_19 >>= 2 ;
V_9 . V_19 |= V_20 << 30 ;
if ( V_14 % 16 == 15 ) {
V_9 . V_21 = V_22 + ( ( V_14 / 4 ) & ~ 3 ) ;
F_5 ( V_1 , & V_9 , L_2 ) ;
V_9 . V_21 += V_23 - V_22 ;
F_5 ( V_1 , & V_9 , L_3 ) ;
}
}
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_16 ;
V_9 . V_17 = V_1 -> V_13 ;
V_9 . V_21 = V_24 ;
V_9 . V_19 = V_25 | V_26 |
V_27 | V_28 ;
if ( V_1 -> V_29 == V_30 )
V_9 . V_19 |= V_31 ;
F_5 ( V_1 , & V_9 , L_4 ) ;
V_9 . V_21 = V_32 ;
V_9 . V_19 ^= V_27 | V_33 ;
F_5 ( V_1 , & V_9 , L_5 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_16 ;
V_9 . V_17 = V_1 -> V_13 ;
V_9 . V_21 = V_34 ;
V_9 . V_19 = ( V_1 -> V_35 ? V_36 : 0 ) |
( V_1 -> V_13 ? V_37 : 0 ) ;
F_5 ( V_1 , & V_9 , L_6 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_16 ;
V_9 . V_17 = V_1 -> V_13 ;
V_9 . V_21 = V_38 ;
V_9 . V_19 = V_1 -> V_39 ;
F_5 ( V_1 , & V_9 , L_7 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_16 ;
V_9 . V_17 = V_1 -> V_13 ;
V_9 . V_21 = V_40 ;
V_9 . V_41 = V_42 ;
V_9 . V_43 = V_44 - 1 ;
F_5 ( V_1 , & V_9 , L_8 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_16 ;
V_9 . V_17 = V_1 -> V_13 ;
V_9 . V_21 = V_45 ;
V_9 . V_41 = V_42 ;
V_9 . V_43 = V_44 - 1 ;
F_5 ( V_1 , & V_9 , L_9 ) ;
F_10 ( V_1 ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_46 ;
V_9 . V_17 = V_1 -> V_13 ;
F_5 ( V_1 , & V_9 , L_10 ) ;
if ( F_12 ( V_1 -> V_12 , & V_9 , L_10 ) ||
V_9 . V_15 != V_46 || V_9 . V_19 ) {
F_7 ( L_11 , V_1 -> V_13 ) ;
F_9 () ;
}
F_12 ( V_1 -> V_12 , & V_9 , L_12 ) ;
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_47 ;
V_9 . V_17 = V_1 -> V_13 ;
V_9 . V_48 = V_1 -> V_49 ;
V_9 . V_50 = V_1 -> V_49 | ( V_51 << 3 ) ;
F_5 ( V_1 , & V_9 , L_13 ) ;
}
static T_1 F_14 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_52 ;
V_9 . V_17 = V_1 -> V_13 ;
F_5 ( V_1 , & V_9 , L_14 ) ;
if ( F_12 ( V_1 -> V_12 , & V_9 , L_14 ) ) {
F_7 ( L_15 , V_1 -> V_13 ) ;
F_9 () ;
}
return V_9 . V_19 ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_53 ;
V_9 . V_17 = V_1 -> V_13 ;
V_9 . V_19 = 0 ;
F_5 ( V_1 , & V_9 , L_16 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_54 ;
V_9 . V_17 = V_1 -> V_13 ;
F_5 ( V_1 , & V_9 , L_17 ) ;
F_14 ( V_1 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_9 V_9 ;
int V_55 ;
if ( V_1 -> V_56 )
return 0 ;
if ( ! F_18 ( V_1 -> V_12 ) &&
( V_55 = F_19 ( V_1 -> V_12 , F_8 ( V_1 -> V_12 ) ,
V_1 -> V_3 ) ) )
return V_55 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_15 = V_57 ;
V_9 . V_17 = V_1 -> V_13 ;
V_9 . V_48 = V_58 ;
F_5 ( V_1 , & V_9 , L_18 ) ;
V_9 . V_15 = V_59 ;
V_9 . V_48 = V_60 ;
F_5 ( V_1 , & V_9 , L_19 ) ;
V_9 . V_15 = V_61 ;
V_9 . V_48 = V_62 ;
F_5 ( V_1 , & V_9 , L_20 ) ;
V_9 . V_15 = V_63 ;
V_9 . V_41 = V_64 ;
F_5 ( V_1 , & V_9 , L_21 ) ;
V_9 . V_15 = V_65 ;
V_9 . V_19 = 0x7F7F7F7F ;
F_5 ( V_1 , & V_9 , L_22 ) ;
V_1 -> V_56 = 1 ;
return 0 ;
}
static inline void F_20 ( struct V_2 * V_3 , const char * V_66 ,
T_2 * V_67 , int V_68 )
{
#if V_69
int V_8 ;
F_21 ( V_70 L_23 , V_3 -> V_71 , V_66 , V_68 ) ;
for ( V_8 = 0 ; V_8 < V_68 ; V_8 ++ ) {
if ( V_8 >= V_69 )
break;
F_21 ( L_24 , ! ( V_8 % 4 ) ? L_25 : L_26 , V_67 [ V_8 ] ) ;
}
F_21 ( L_27 ) ;
#endif
}
static inline void F_22 ( T_1 V_72 , struct V_73 * V_73 )
{
#if V_74
F_21 ( V_70 L_28 ,
V_72 , V_73 -> V_75 , V_73 -> V_76 , V_73 -> V_77 ,
V_73 -> V_67 , V_73 -> V_78 , V_73 -> V_79 ) ;
#endif
}
static inline int F_23 ( unsigned int V_80 , struct V_1 * V_1 ,
int V_81 )
{
T_1 V_72 , V_82 , V_83 ;
struct V_73 * V_84 ;
if ( ! ( V_72 = F_24 ( V_80 ) ) )
return - 1 ;
F_25 ( V_72 & 0x1F ) ;
V_82 = V_81 ? F_26 ( V_1 , 0 ) : F_27 ( V_1 , 0 ) ;
V_84 = V_81 ? F_28 ( V_1 , 0 ) : F_29 ( V_1 , 0 ) ;
V_83 = ( V_72 - V_82 ) / sizeof( struct V_73 ) ;
F_25 ( V_83 >= ( V_81 ? V_85 : V_86 ) ) ;
F_22 ( V_72 , & V_84 [ V_83 ] ) ;
F_25 ( V_84 [ V_83 ] . V_75 ) ;
return V_83 ;
}
static inline void F_30 ( unsigned int V_80 , T_1 V_72 ,
struct V_73 * V_73 )
{
F_22 ( V_72 , V_73 ) ;
F_25 ( V_72 & 0x1F ) ;
F_31 ( V_80 , V_72 ) ;
}
static inline void F_32 ( struct V_1 * V_1 , struct V_73 * V_73 )
{
#ifdef F_33
F_34 ( & V_1 -> V_87 -> V_3 , V_73 -> V_67 ,
V_73 -> V_76 , V_88 ) ;
#else
F_34 ( & V_1 -> V_87 -> V_3 , V_73 -> V_67 & ~ 3 ,
F_35 ( ( V_73 -> V_67 & 3 ) + V_73 -> V_76 , 4 ) ,
V_88 ) ;
#endif
}
static void F_36 ( void * V_89 , int V_90 )
{
struct V_2 * V_87 = V_89 ;
struct V_1 * V_1 = F_1 ( V_87 ) ;
unsigned long V_91 ;
F_37 ( & V_92 , V_91 ) ;
V_1 -> V_90 = V_90 ;
if ( ! V_1 -> V_35 ) {
if ( V_90 )
F_38 ( V_87 ) ;
else
F_39 ( V_87 ) ;
}
F_40 ( & V_92 , V_91 ) ;
}
static void F_41 ( void * V_89 )
{
struct V_2 * V_3 = V_89 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
#if V_93
F_21 ( V_70 L_29 , V_3 -> V_71 ) ;
#endif
F_42 ( V_94 [ V_1 -> V_13 ] . V_95 ) ;
F_43 ( & V_1 -> V_96 ) ;
}
static int F_44 ( struct V_97 * V_96 , int V_98 )
{
struct V_1 * V_1 = F_45 ( V_96 , struct V_1 , V_96 ) ;
struct V_2 * V_3 = V_1 -> V_87 ;
unsigned int V_99 = V_94 [ V_1 -> V_13 ] . V_95 ;
unsigned int V_100 = V_94 [ V_1 -> V_13 ] . V_101 ;
int V_102 = 0 ;
#if V_93
F_21 ( V_70 L_30 , V_3 -> V_71 ) ;
#endif
while ( V_102 < V_98 ) {
struct V_103 * V_104 ;
struct V_73 * V_73 ;
int V_105 ;
#ifdef F_33
struct V_103 * V_106 ;
T_1 V_72 ;
#endif
if ( ( V_105 = F_23 ( V_99 , V_1 , 0 ) ) < 0 ) {
#if V_93
F_21 ( V_70 L_31
L_32 , V_3 -> V_71 ) ;
#endif
F_46 ( V_96 ) ;
F_47 ( V_99 ) ;
if ( ! F_48 ( V_99 ) &&
F_49 ( V_96 ) ) {
#if V_93
F_21 ( V_70 L_31
L_33 ,
V_3 -> V_71 ) ;
#endif
F_42 ( V_99 ) ;
continue;
}
#if V_93
F_21 ( V_70 L_34 ,
V_3 -> V_71 ) ;
#endif
return V_102 ;
}
V_73 = F_29 ( V_1 , V_105 ) ;
#if 0
if (desc->error_count)
printk(KERN_DEBUG "%s: hss_hdlc_poll status 0x%02X"
" errors %u\n", dev->name, desc->status,
desc->error_count);
#endif
V_104 = NULL ;
switch ( V_73 -> V_78 ) {
case 0 :
#ifdef F_33
if ( ( V_104 = F_50 ( V_3 , V_107 ) ) != NULL ) {
V_72 = F_51 ( & V_3 -> V_3 , V_104 -> V_67 ,
V_107 ,
V_108 ) ;
if ( F_52 ( & V_3 -> V_3 , V_72 ) ) {
F_53 ( V_104 ) ;
V_104 = NULL ;
}
}
#else
V_104 = F_50 ( V_3 , V_73 -> V_77 ) ;
#endif
if ( ! V_104 )
V_3 -> V_109 . V_110 ++ ;
break;
case V_111 :
case V_112 :
V_3 -> V_109 . V_113 ++ ;
V_3 -> V_109 . V_114 ++ ;
break;
case V_115 :
V_3 -> V_109 . V_116 ++ ;
V_3 -> V_109 . V_114 ++ ;
break;
case V_117 :
V_3 -> V_109 . V_118 ++ ;
V_3 -> V_109 . V_114 ++ ;
break;
default:
F_54 ( V_3 , L_35 ,
V_73 -> V_78 , V_73 -> V_79 ) ;
V_3 -> V_109 . V_114 ++ ;
}
if ( ! V_104 ) {
V_73 -> V_76 = V_107 ;
V_73 -> V_77 = V_73 -> V_78 = 0 ;
F_30 ( V_100 , F_27 ( V_1 , V_105 ) , V_73 ) ;
continue;
}
#ifdef F_33
V_106 = V_104 ;
V_104 = V_1 -> V_119 [ V_105 ] ;
F_34 ( & V_3 -> V_3 , V_73 -> V_67 ,
V_107 , V_108 ) ;
#else
F_55 ( & V_3 -> V_3 , V_73 -> V_67 ,
V_107 , V_108 ) ;
F_3 ( ( T_1 * ) V_104 -> V_67 , ( T_1 * ) V_1 -> V_119 [ V_105 ] ,
F_35 ( V_73 -> V_77 , 4 ) / 4 ) ;
#endif
F_56 ( V_104 , V_73 -> V_77 ) ;
F_20 ( V_3 , L_36 , V_104 -> V_67 , V_104 -> V_68 ) ;
V_104 -> V_120 = F_57 ( V_104 , V_3 ) ;
V_3 -> V_109 . V_121 ++ ;
V_3 -> V_109 . V_122 += V_104 -> V_68 ;
F_58 ( V_104 ) ;
#ifdef F_33
V_1 -> V_119 [ V_105 ] = V_106 ;
V_73 -> V_67 = V_72 ;
#endif
V_73 -> V_76 = V_107 ;
V_73 -> V_77 = 0 ;
F_30 ( V_100 , F_27 ( V_1 , V_105 ) , V_73 ) ;
V_102 ++ ;
}
#if V_93
F_21 ( V_70 L_37 ) ;
#endif
return V_102 ;
}
static void F_59 ( void * V_89 )
{
struct V_2 * V_3 = V_89 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_83 ;
#if V_123
F_21 (KERN_DEBUG DRV_NAME L_38 ) ;
#endif
while ( ( V_83 = F_23 ( V_94 [ V_1 -> V_13 ] . V_124 ,
V_1 , 1 ) ) >= 0 ) {
struct V_73 * V_73 ;
int V_125 ;
V_73 = F_28 ( V_1 , V_83 ) ;
V_3 -> V_109 . V_126 ++ ;
V_3 -> V_109 . V_127 += V_73 -> V_77 ;
F_32 ( V_1 , V_73 ) ;
#if V_123
F_21 ( V_70 L_39 ,
V_3 -> V_71 , V_1 -> V_128 [ V_83 ] ) ;
#endif
F_60 ( V_1 -> V_128 [ V_83 ] ) ;
V_1 -> V_128 [ V_83 ] = NULL ;
V_125 = F_61 ( V_1 -> V_129 -> V_130 ) ;
F_30 ( V_1 -> V_129 -> V_130 ,
F_26 ( V_1 , V_83 ) , V_73 ) ;
if ( V_125 ) {
#if V_123
F_21 ( V_70 L_40
L_41 , V_3 -> V_71 ) ;
#endif
F_62 ( V_3 ) ;
}
}
}
static int F_63 ( struct V_103 * V_104 , struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_130 = V_1 -> V_129 -> V_130 ;
int V_68 , V_131 , V_132 , V_105 ;
void * V_133 ;
T_1 V_72 ;
struct V_73 * V_73 ;
#if V_123
F_21 ( V_70 L_42 , V_3 -> V_71 ) ;
#endif
if ( F_64 ( V_104 -> V_68 > V_64 ) ) {
F_53 ( V_104 ) ;
V_3 -> V_109 . V_134 ++ ;
return V_135 ;
}
F_20 ( V_3 , L_43 , V_104 -> V_67 , V_104 -> V_68 ) ;
V_68 = V_104 -> V_68 ;
#ifdef F_33
V_131 = 0 ;
V_132 = V_68 ;
V_133 = V_104 -> V_67 ;
#else
V_131 = ( int ) V_104 -> V_67 & 3 ;
V_132 = F_35 ( V_131 + V_68 , 4 ) ;
if ( ! ( V_133 = F_65 ( V_132 , V_136 ) ) ) {
F_53 ( V_104 ) ;
V_3 -> V_109 . V_137 ++ ;
return V_135 ;
}
F_3 ( V_133 , ( T_1 * ) ( ( int ) V_104 -> V_67 & ~ 3 ) , V_132 / 4 ) ;
F_53 ( V_104 ) ;
#endif
V_72 = F_51 ( & V_3 -> V_3 , V_133 , V_132 , V_88 ) ;
if ( F_52 ( & V_3 -> V_3 , V_72 ) ) {
#ifdef F_33
F_53 ( V_104 ) ;
#else
F_66 ( V_133 ) ;
#endif
V_3 -> V_109 . V_137 ++ ;
return V_135 ;
}
V_105 = F_23 ( V_130 , V_1 , 1 ) ;
F_25 ( V_105 < 0 ) ;
V_73 = F_28 ( V_1 , V_105 ) ;
#ifdef F_33
V_1 -> V_128 [ V_105 ] = V_104 ;
#else
V_1 -> V_128 [ V_105 ] = V_133 ;
#endif
V_73 -> V_67 = V_72 + V_131 ;
V_73 -> V_76 = V_73 -> V_77 = V_68 ;
F_67 () ;
F_30 ( V_94 [ V_1 -> V_13 ] . V_138 , F_26 ( V_1 , V_105 ) , V_73 ) ;
if ( F_61 ( V_130 ) ) {
#if V_123
F_21 ( V_70 L_44 , V_3 -> V_71 ) ;
#endif
F_68 ( V_3 ) ;
if ( ! F_61 ( V_130 ) ) {
#if V_123
F_21 ( V_70 L_45 ,
V_3 -> V_71 ) ;
#endif
F_62 ( V_3 ) ;
}
}
#if V_123
F_21 ( V_70 L_46 , V_3 -> V_71 ) ;
#endif
return V_135 ;
}
static int F_69 ( struct V_1 * V_1 )
{
int V_55 ;
V_55 = F_70 ( V_94 [ V_1 -> V_13 ] . V_101 , V_86 , 0 , 0 ,
L_47 , V_1 -> V_87 -> V_71 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_70 ( V_94 [ V_1 -> V_13 ] . V_95 , V_86 , 0 , 0 ,
L_48 , V_1 -> V_87 -> V_71 ) ;
if ( V_55 )
goto V_139;
V_55 = F_70 ( V_94 [ V_1 -> V_13 ] . V_138 , V_85 , 0 , 0 ,
L_49 , V_1 -> V_87 -> V_71 ) ;
if ( V_55 )
goto V_140;
V_55 = F_70 ( V_1 -> V_129 -> V_130 , V_85 , 0 , 0 ,
L_50 , V_1 -> V_87 -> V_71 ) ;
if ( V_55 )
goto V_141;
V_55 = F_70 ( V_94 [ V_1 -> V_13 ] . V_124 , V_85 , 0 , 0 ,
L_51 , V_1 -> V_87 -> V_71 ) ;
if ( V_55 )
goto V_142;
return 0 ;
V_142:
F_71 ( V_1 -> V_129 -> V_130 ) ;
V_141:
F_71 ( V_94 [ V_1 -> V_13 ] . V_138 ) ;
V_140:
F_71 ( V_94 [ V_1 -> V_13 ] . V_95 ) ;
V_139:
F_71 ( V_94 [ V_1 -> V_13 ] . V_101 ) ;
F_21 ( V_70 L_52 ,
V_1 -> V_87 -> V_71 ) ;
return V_55 ;
}
static void F_72 ( struct V_1 * V_1 )
{
F_71 ( V_94 [ V_1 -> V_13 ] . V_101 ) ;
F_71 ( V_94 [ V_1 -> V_13 ] . V_95 ) ;
F_71 ( V_94 [ V_1 -> V_13 ] . V_124 ) ;
F_71 ( V_94 [ V_1 -> V_13 ] . V_138 ) ;
F_71 ( V_1 -> V_129 -> V_130 ) ;
}
static int F_73 ( struct V_1 * V_1 )
{
int V_8 ;
if ( ! V_143 ) {
V_144 = F_74 ( V_145 , & V_1 -> V_87 -> V_3 ,
V_146 , 32 , 0 ) ;
if ( ! V_144 )
return - V_147 ;
}
if ( ! ( V_1 -> V_148 = F_75 ( V_144 , V_149 ,
& V_1 -> V_150 ) ) )
return - V_147 ;
memset ( V_1 -> V_148 , 0 , V_146 ) ;
memset ( V_1 -> V_119 , 0 , sizeof( V_1 -> V_119 ) ) ;
memset ( V_1 -> V_128 , 0 , sizeof( V_1 -> V_128 ) ) ;
for ( V_8 = 0 ; V_8 < V_86 ; V_8 ++ ) {
struct V_73 * V_73 = F_29 ( V_1 , V_8 ) ;
T_3 * V_151 ;
void * V_67 ;
#ifdef F_33
if ( ! ( V_151 = F_50 ( V_1 -> V_87 , V_107 ) ) )
return - V_147 ;
V_67 = V_151 -> V_67 ;
#else
if ( ! ( V_151 = F_65 ( V_107 , V_149 ) ) )
return - V_147 ;
V_67 = V_151 ;
#endif
V_73 -> V_76 = V_107 ;
V_73 -> V_67 = F_51 ( & V_1 -> V_87 -> V_3 , V_67 ,
V_107 , V_108 ) ;
if ( F_52 ( & V_1 -> V_87 -> V_3 , V_73 -> V_67 ) ) {
F_76 ( V_151 ) ;
return - V_152 ;
}
V_1 -> V_119 [ V_8 ] = V_151 ;
}
return 0 ;
}
static void F_77 ( struct V_1 * V_1 )
{
int V_8 ;
if ( V_1 -> V_148 ) {
for ( V_8 = 0 ; V_8 < V_86 ; V_8 ++ ) {
struct V_73 * V_73 = F_29 ( V_1 , V_8 ) ;
T_3 * V_151 = V_1 -> V_119 [ V_8 ] ;
if ( V_151 ) {
F_34 ( & V_1 -> V_87 -> V_3 ,
V_73 -> V_67 , V_107 ,
V_108 ) ;
F_76 ( V_151 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ ) {
struct V_73 * V_73 = F_28 ( V_1 , V_8 ) ;
T_3 * V_151 = V_1 -> V_128 [ V_8 ] ;
if ( V_151 ) {
F_32 ( V_1 , V_73 ) ;
F_76 ( V_151 ) ;
}
}
F_78 ( V_144 , V_1 -> V_148 , V_1 -> V_150 ) ;
V_1 -> V_148 = NULL ;
}
if ( ! V_143 && V_144 ) {
F_79 ( V_144 ) ;
V_144 = NULL ;
}
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_91 ;
int V_8 , V_55 = 0 ;
if ( ( V_55 = F_81 ( V_3 ) ) )
return V_55 ;
if ( ( V_55 = F_17 ( V_1 ) ) )
goto V_153;
if ( ( V_55 = F_69 ( V_1 ) ) )
goto V_153;
if ( ( V_55 = F_73 ( V_1 ) ) )
goto V_154;
F_37 ( & V_92 , V_91 ) ;
if ( V_1 -> V_129 -> V_155 )
if ( ( V_55 = V_1 -> V_129 -> V_155 ( V_1 -> V_13 , V_3 ,
F_36 ) ) )
goto V_156;
F_40 ( & V_92 , V_91 ) ;
for ( V_8 = 0 ; V_8 < V_85 ; V_8 ++ )
F_30 ( V_1 -> V_129 -> V_130 ,
F_26 ( V_1 , V_8 ) , F_28 ( V_1 , V_8 ) ) ;
for ( V_8 = 0 ; V_8 < V_86 ; V_8 ++ )
F_30 ( V_94 [ V_1 -> V_13 ] . V_101 ,
F_27 ( V_1 , V_8 ) , F_29 ( V_1 , V_8 ) ) ;
F_82 ( & V_1 -> V_96 ) ;
F_83 ( V_3 ) ;
F_84 ( V_94 [ V_1 -> V_13 ] . V_95 , V_157 ,
F_41 , V_3 ) ;
F_84 ( V_94 [ V_1 -> V_13 ] . V_124 , V_157 ,
F_59 , V_3 ) ;
F_47 ( V_94 [ V_1 -> V_13 ] . V_124 ) ;
V_143 ++ ;
F_13 ( V_1 ) ;
F_11 ( V_1 ) ;
F_15 ( V_1 ) ;
F_43 ( & V_1 -> V_96 ) ;
return 0 ;
V_156:
F_40 ( & V_92 , V_91 ) ;
V_154:
F_77 ( V_1 ) ;
F_72 ( V_1 ) ;
V_153:
F_85 ( V_3 ) ;
return V_55 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_91 ;
int V_8 , V_158 = V_86 ;
F_37 ( & V_92 , V_91 ) ;
V_143 -- ;
F_42 ( V_94 [ V_1 -> V_13 ] . V_95 ) ;
F_68 ( V_3 ) ;
F_87 ( & V_1 -> V_96 ) ;
F_16 ( V_1 ) ;
while ( F_23 ( V_94 [ V_1 -> V_13 ] . V_101 , V_1 , 0 ) >= 0 )
V_158 -- ;
while ( F_23 ( V_94 [ V_1 -> V_13 ] . V_95 , V_1 , 0 ) >= 0 )
V_158 -- ;
if ( V_158 )
F_88 ( V_3 , L_53 ,
V_158 ) ;
V_158 = V_85 ;
while ( F_23 ( V_94 [ V_1 -> V_13 ] . V_138 , V_1 , 1 ) >= 0 )
V_158 -- ;
V_8 = 0 ;
do {
while ( F_23 ( V_1 -> V_129 -> V_130 , V_1 , 1 ) >= 0 )
V_158 -- ;
if ( ! V_158 )
break;
} while ( ++ V_8 < V_159 );
if ( V_158 )
F_88 ( V_3 , L_54 ,
V_158 ) ;
#if V_160
if ( ! V_158 )
F_21 ( V_70 L_55 , V_8 ) ;
#endif
F_42 ( V_94 [ V_1 -> V_13 ] . V_124 ) ;
if ( V_1 -> V_129 -> V_161 )
V_1 -> V_129 -> V_161 ( V_1 -> V_13 , V_3 ) ;
F_40 ( & V_92 , V_91 ) ;
F_77 ( V_1 ) ;
F_72 ( V_1 ) ;
F_85 ( V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 , unsigned short V_162 ,
unsigned short V_163 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_162 != V_164 )
return - V_165 ;
switch( V_163 ) {
case V_166 :
V_1 -> V_49 = 0 ;
return 0 ;
case V_167 :
V_1 -> V_49 = V_168 ;
return 0 ;
default:
return - V_165 ;
}
}
static T_1 F_90 ( T_1 V_169 , T_1 V_170 , T_1 V_171 , T_1 V_172 ,
T_1 * V_173 , T_1 * V_174 , T_1 * V_175 )
{
T_4 V_176 ;
T_1 V_177 ;
V_176 = V_178 * ( T_4 ) ( V_172 + 1 ) ;
F_91 ( V_176 , V_170 * ( V_172 + 1 ) + V_171 + 1 ) ;
V_177 = abs ( ( T_1 ) V_176 - V_169 ) ;
if ( V_177 < * V_174 ) {
* V_173 = V_176 ;
* V_174 = V_177 ;
* V_175 = ( V_170 << 22 ) | ( V_171 << 12 ) | V_172 ;
}
return V_177 ;
}
static void F_92 ( T_1 V_169 , T_1 * V_173 , T_1 * V_175 )
{
T_1 V_170 , V_171 , V_179 = 0xFFFFFFFF ;
V_170 = V_178 / V_169 ;
if ( V_170 > 0x3FF ) {
F_90 ( V_169 , 0x3FF , 1 , 1 , V_173 , & V_179 , V_175 ) ;
return;
}
if ( V_170 == 0 ) {
V_170 = 1 ;
V_169 = V_178 ;
}
if ( V_169 * V_170 == V_178 ) {
F_90 ( V_169 , V_170 - 1 , 1 , 1 , V_173 , & V_179 , V_175 ) ;
return;
}
for ( V_171 = 0 ; V_171 < 0x400 ; V_171 ++ ) {
T_4 V_172 = ( V_171 + 1 ) * ( T_4 ) V_169 ;
F_91 ( V_172 , V_178 - V_169 * V_170 ) ;
V_172 -- ;
if ( V_172 >= 0xFFF ) {
if ( V_171 == 0 &&
! F_90 ( V_169 , V_170 - 1 , 1 , 1 , V_173 , & V_179 , V_175 ) )
return;
F_90 ( V_169 , V_170 , V_171 , 0xFFF , V_173 , & V_179 , V_175 ) ;
return;
}
if ( ! F_90 ( V_169 , V_170 , V_171 , V_172 , V_173 , & V_179 , V_175 ) )
return;
if ( ! F_90 ( V_169 , V_170 , V_171 , V_172 + 1 , V_173 , & V_179 , V_175 ) )
return;
}
}
static int F_93 ( struct V_2 * V_3 , struct V_180 * V_181 , int V_15 )
{
const T_5 V_182 = sizeof( V_183 ) ;
V_183 V_184 ;
V_183 T_6 * line = V_181 -> V_185 . V_186 . V_187 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_91 ;
int V_188 ;
if ( V_15 != V_189 )
return F_94 ( V_3 , V_181 , V_15 ) ;
switch( V_181 -> V_185 . type ) {
case V_190 :
V_181 -> V_185 . type = V_191 ;
if ( V_181 -> V_185 . V_182 < V_182 ) {
V_181 -> V_185 . V_182 = V_182 ;
return - V_192 ;
}
memset ( & V_184 , 0 , sizeof( V_184 ) ) ;
V_184 . V_29 = V_1 -> V_29 ;
V_184 . V_193 = V_1 -> V_193 ;
V_184 . V_35 = V_1 -> V_35 ;
if ( F_95 ( line , & V_184 , V_182 ) )
return - V_194 ;
return 0 ;
case V_195 :
case V_191 :
if( ! F_96 ( V_196 ) )
return - V_197 ;
if ( F_97 ( & V_184 , line , V_182 ) )
return - V_194 ;
V_188 = V_184 . V_29 ;
if ( V_1 -> V_129 -> V_198 )
V_188 = V_1 -> V_129 -> V_198 ( V_1 -> V_13 , V_188 ) ;
if ( V_188 != V_199 && V_188 != V_30 )
return - V_165 ;
if ( V_184 . V_35 != 0 && V_184 . V_35 != 1 )
return - V_165 ;
V_1 -> V_29 = V_188 ;
if ( V_188 == V_30 )
F_92 ( V_184 . V_193 , & V_1 -> V_193 ,
& V_1 -> V_39 ) ;
else {
V_1 -> V_193 = 0 ;
V_1 -> V_39 = V_200 ;
}
V_1 -> V_35 = V_184 . V_35 ;
F_37 ( & V_92 , V_91 ) ;
if ( V_3 -> V_91 & V_201 )
F_11 ( V_1 ) ;
if ( V_1 -> V_35 || V_1 -> V_90 )
F_38 ( V_1 -> V_87 ) ;
else
F_39 ( V_1 -> V_87 ) ;
F_40 ( & V_92 , V_91 ) ;
return 0 ;
default:
return F_94 ( V_3 , V_181 , V_15 ) ;
}
}
static int F_98 ( struct V_202 * V_89 )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
T_7 * V_203 ;
int V_55 ;
if ( ( V_1 = F_99 ( sizeof( * V_1 ) , V_149 ) ) == NULL )
return - V_147 ;
if ( ( V_1 -> V_12 = F_100 ( 0 ) ) == NULL ) {
V_55 = - V_204 ;
goto V_205;
}
if ( ( V_1 -> V_87 = V_3 = F_101 ( V_1 ) ) == NULL ) {
V_55 = - V_147 ;
goto V_206;
}
F_102 ( V_3 , & V_89 -> V_3 ) ;
V_203 = F_2 ( V_3 ) ;
V_203 -> V_207 = F_89 ;
V_203 -> V_208 = F_63 ;
V_3 -> V_209 = & V_210 ;
V_3 -> V_211 = 100 ;
V_1 -> V_29 = V_199 ;
V_1 -> V_193 = 0 ;
V_1 -> V_39 = V_200 ;
V_1 -> V_13 = V_89 -> V_13 ;
V_1 -> V_3 = & V_89 -> V_3 ;
V_1 -> V_129 = V_89 -> V_3 . V_212 ;
F_103 ( V_3 , & V_1 -> V_96 , F_44 , V_213 ) ;
if ( ( V_55 = F_104 ( V_3 ) ) )
goto V_214;
F_105 ( V_89 , V_1 ) ;
F_106 ( V_3 , L_56 ) ;
return 0 ;
V_214:
F_107 ( V_3 ) ;
V_206:
F_108 ( V_1 -> V_12 ) ;
V_205:
F_66 ( V_1 ) ;
return V_55 ;
}
static int F_109 ( struct V_202 * V_89 )
{
struct V_1 * V_1 = F_110 ( V_89 ) ;
F_111 ( V_1 -> V_87 ) ;
F_107 ( V_1 -> V_87 ) ;
F_108 ( V_1 -> V_12 ) ;
F_66 ( V_1 ) ;
return 0 ;
}
static int T_8 F_112 ( void )
{
if ( ( F_113 () &
( V_215 | V_216 ) ) !=
( V_215 | V_216 ) )
return - V_204 ;
F_114 ( & V_92 ) ;
return F_115 ( & V_217 ) ;
}
static void T_9 F_116 ( void )
{
F_117 ( & V_217 ) ;
}
