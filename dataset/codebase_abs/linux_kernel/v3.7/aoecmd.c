static struct V_1 *
F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 ) {
F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
V_3 -> V_5 = F_5 ( V_6 ) ;
F_6 ( V_3 ) ;
}
return V_3 ;
}
static struct V_7 *
F_7 ( struct V_8 * V_9 , T_2 V_10 )
{
struct V_7 * V_11 ;
struct V_12 * V_13 , * V_14 , * V_15 ;
T_2 V_16 ;
V_16 = V_10 % V_17 ;
V_13 = & V_9 -> V_18 [ V_16 ] ;
F_8 (pos, nx, head) {
V_11 = F_9 ( V_14 , struct V_7 , V_13 ) ;
if ( V_11 -> V_10 == V_10 ) {
F_10 ( V_14 ) ;
return V_11 ;
}
}
return NULL ;
}
static int
F_11 ( struct V_8 * V_9 )
{
register T_1 V_16 ;
V_16 = V_19 & 0xffff ;
return V_16 |= ( ++ V_9 -> V_20 & 0x7fff ) << 16 ;
}
static T_2
F_12 ( struct V_8 * V_9 , struct V_21 * V_22 , struct V_23 * V_24 )
{
T_2 V_25 = F_11 ( V_9 ) ;
memcpy ( V_24 -> V_26 , V_22 -> V_27 -> V_28 -> V_29 , sizeof V_24 -> V_26 ) ;
memcpy ( V_24 -> V_30 , V_22 -> V_31 , sizeof V_24 -> V_30 ) ;
V_24 -> type = F_13 ( V_6 ) ;
V_24 -> V_32 = V_33 ;
V_24 -> V_34 = F_14 ( V_9 -> V_35 ) ;
V_24 -> V_36 = V_9 -> V_37 ;
V_24 -> V_38 = V_39 ;
V_24 -> V_10 = F_15 ( V_25 ) ;
return V_25 ;
}
static inline void
F_16 ( struct V_40 * V_41 , T_3 V_42 )
{
V_41 -> V_43 = V_42 ;
V_41 -> V_44 = V_42 >>= 8 ;
V_41 -> V_45 = V_42 >>= 8 ;
V_41 -> V_46 = V_42 >>= 8 ;
V_41 -> V_47 = V_42 >>= 8 ;
V_41 -> V_48 = V_42 >>= 8 ;
}
static struct V_49 *
F_17 ( struct V_21 * V_22 )
{
struct V_49 * V_27 ;
V_27 = V_22 -> V_27 ;
V_27 ++ ;
if ( V_27 >= & V_22 -> V_50 [ V_51 ] || V_27 -> V_28 == NULL )
V_27 = V_22 -> V_50 ;
if ( V_27 -> V_28 == NULL )
return NULL ;
return V_22 -> V_27 = V_27 ;
}
static void
F_18 ( struct V_8 * V_9 , struct V_1 * V_3 )
{
F_19 ( & V_9 -> V_52 , V_3 ) ;
}
static struct V_1 *
F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_3 = F_21 ( & V_9 -> V_52 ) ;
if ( V_3 && F_22 ( & F_23 ( V_3 ) -> V_53 ) == 1 ) {
F_24 ( V_3 , & V_9 -> V_52 ) ;
return V_3 ;
}
if ( F_25 ( & V_9 -> V_52 ) < V_54 &&
( V_3 = F_1 ( V_55 ) ) )
return V_3 ;
return NULL ;
}
void
F_26 ( struct V_7 * V_11 )
{
struct V_21 * V_22 ;
V_22 = V_11 -> V_22 ;
V_11 -> V_56 = NULL ;
V_11 -> V_57 = NULL ;
V_11 -> V_58 = NULL ;
F_27 ( & V_11 -> V_13 , & V_22 -> V_59 ) ;
}
static struct V_7 *
F_28 ( struct V_8 * V_9 , struct V_21 * V_22 )
{
struct V_7 * V_11 ;
struct V_1 * V_3 ;
struct V_12 * V_14 ;
if ( F_29 ( & V_22 -> V_59 ) ) {
if ( V_22 -> V_60 >= V_54 * 2 )
return NULL ;
V_11 = F_30 ( 1 , sizeof( * V_11 ) , V_4 ) ;
if ( V_11 == NULL )
return NULL ;
V_22 -> V_60 ++ ;
V_11 -> V_22 = V_22 ;
} else {
V_14 = V_22 -> V_59 . V_61 ;
F_10 ( V_14 ) ;
V_11 = F_9 ( V_14 , struct V_7 , V_13 ) ;
}
V_3 = V_11 -> V_3 ;
if ( V_3 == NULL ) {
V_11 -> V_3 = V_3 = F_1 ( V_55 ) ;
if ( ! V_3 ) {
V_62: F_26 ( V_11 ) ;
return NULL ;
}
}
if ( F_22 ( & F_23 ( V_3 ) -> V_53 ) != 1 ) {
V_3 = F_20 ( V_9 ) ;
if ( V_3 == NULL )
goto V_62;
F_18 ( V_9 , V_11 -> V_3 ) ;
V_11 -> V_3 = V_3 ;
}
V_3 -> V_63 -= V_3 -> V_64 ;
F_23 ( V_3 ) -> V_65 = V_3 -> V_64 = 0 ;
F_31 ( V_3 , 0 ) ;
return V_11 ;
}
static struct V_7 *
F_32 ( struct V_8 * V_9 )
{
struct V_7 * V_11 ;
struct V_21 * V_22 , * * V_66 ;
int V_67 = 0 ;
if ( V_9 -> V_68 [ 0 ] == NULL ) {
F_33 ( V_69 L_1 ) ;
return NULL ;
}
V_66 = V_9 -> V_70 ;
for (; ; ) {
V_66 ++ ;
if ( V_66 >= & V_9 -> V_68 [ V_71 ] || ! * V_66 )
V_66 = V_9 -> V_68 ;
V_22 = * V_66 ;
V_67 += V_22 -> V_72 ;
if ( V_22 -> V_72 < V_22 -> V_73
&& V_22 != V_9 -> V_74
&& V_22 -> V_27 -> V_28 ) {
V_11 = F_28 ( V_9 , V_22 ) ;
if ( V_11 ) {
F_17 ( V_22 ) ;
V_9 -> V_70 = V_66 ;
return V_11 ;
}
}
if ( V_66 == V_9 -> V_70 )
break;
}
if ( V_67 == 0 ) {
V_9 -> V_75 ++ ;
V_9 -> V_76 |= V_77 ;
}
return NULL ;
}
static void
F_34 ( struct V_1 * V_3 , struct V_78 * V_57 , T_1 V_79 , T_1 V_80 )
{
int V_81 = 0 ;
T_1 V_82 ;
V_83:
V_82 = V_57 -> V_84 - ( V_79 - V_57 -> V_85 ) ;
if ( V_82 > V_80 )
V_82 = V_80 ;
F_35 ( V_3 , V_81 ++ , V_57 -> V_86 , V_79 , V_82 ) ;
V_80 -= V_82 ;
if ( V_80 <= 0 )
return;
V_57 ++ ;
V_79 = V_57 -> V_85 ;
goto V_83;
}
static void
F_36 ( struct V_7 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_22 -> V_9 ;
T_2 V_16 ;
V_16 = V_11 -> V_10 % V_17 ;
F_37 ( & V_11 -> V_13 , & V_9 -> V_18 [ V_16 ] ) ;
}
static int
F_38 ( struct V_8 * V_9 )
{
struct V_7 * V_11 ;
struct V_23 * V_24 ;
struct V_40 * V_41 ;
struct V_56 * V_56 ;
struct V_21 * V_22 ;
struct V_1 * V_3 ;
struct V_87 V_88 ;
T_1 V_89 , V_90 ;
char V_91 , V_92 ;
V_91 = 0x10 ;
V_92 = 0x4 ;
V_56 = F_39 ( V_9 ) ;
if ( V_56 == NULL )
return 0 ;
V_11 = F_32 ( V_9 ) ;
if ( V_11 == NULL )
return 0 ;
V_22 = * V_9 -> V_70 ;
V_89 = V_9 -> V_93 ;
if ( V_89 == 0 )
V_89 = V_94 ;
if ( V_89 > V_56 -> V_95 )
V_89 = V_56 -> V_95 ;
V_90 = V_89 ;
V_11 -> V_57 = V_56 -> V_57 ;
V_11 -> V_96 = V_11 -> V_57 -> V_85 + ( V_11 -> V_57 -> V_84 - V_56 -> V_97 ) ;
do {
if ( V_90 < V_56 -> V_97 ) {
V_56 -> V_97 -= V_90 ;
V_56 -> V_95 -= V_90 ;
break;
}
V_90 -= V_56 -> V_97 ;
V_56 -> V_95 -= V_56 -> V_97 ;
if ( V_56 -> V_95 == 0 ) {
V_9 -> V_98 . V_56 = NULL ;
break;
}
V_56 -> V_57 ++ ;
V_56 -> V_97 = V_56 -> V_57 -> V_84 ;
F_40 ( V_56 -> V_97 == 0 ) ;
} while ( V_90 );
V_3 = V_11 -> V_3 ;
V_24 = (struct V_23 * ) F_41 ( V_3 ) ;
V_41 = (struct V_40 * ) ( V_24 + 1 ) ;
F_42 ( V_3 , sizeof *V_24 + sizeof *V_41 ) ;
memset ( V_24 , 0 , V_3 -> V_2 ) ;
V_11 -> V_10 = F_12 ( V_9 , V_22 , V_24 ) ;
F_36 ( V_11 ) ;
V_22 -> V_72 ++ ;
V_11 -> V_99 = 0 ;
V_11 -> V_56 = V_56 ;
V_11 -> V_89 = V_89 ;
V_11 -> V_42 = V_56 -> V_100 ;
V_41 -> V_101 = V_89 >> 9 ;
F_16 ( V_41 , V_56 -> V_100 ) ;
if ( V_9 -> V_76 & V_102 ) {
V_41 -> V_103 |= V_104 ;
} else {
V_92 = 0 ;
V_41 -> V_46 &= 0x0f ;
V_41 -> V_46 |= 0xe0 ;
}
if ( F_43 ( V_56 -> V_105 ) == V_106 ) {
F_34 ( V_3 , V_11 -> V_57 , V_11 -> V_96 , V_89 ) ;
V_41 -> V_103 |= V_107 ;
V_3 -> V_2 += V_89 ;
V_3 -> V_64 = V_89 ;
V_3 -> V_63 += V_89 ;
V_22 -> V_108 ++ ;
} else {
V_22 -> V_109 ++ ;
V_91 = 0 ;
}
V_41 -> V_110 = V_111 | V_91 | V_92 ;
V_56 -> V_112 += 1 ;
V_56 -> V_100 += V_89 >> 9 ;
V_3 -> V_113 = V_22 -> V_27 -> V_28 ;
V_3 = F_44 ( V_3 , V_4 ) ;
if ( V_3 ) {
F_45 ( & V_88 ) ;
F_19 ( & V_88 , V_3 ) ;
F_46 ( & V_88 ) ;
}
return 1 ;
}
static void
F_47 ( T_4 V_35 , unsigned char V_37 , struct V_87 * V_88 )
{
struct V_23 * V_24 ;
struct V_114 * V_115 ;
struct V_1 * V_3 ;
struct V_116 * V_27 ;
F_48 () ;
F_49 (&init_net, ifp) {
F_50 ( V_27 ) ;
if ( ! F_51 ( V_27 ) )
goto V_117;
V_3 = F_1 ( sizeof *V_24 + sizeof *V_115 ) ;
if ( V_3 == NULL ) {
F_33 ( V_118 L_2 ) ;
goto V_117;
}
F_42 ( V_3 , sizeof *V_24 + sizeof *V_115 ) ;
V_3 -> V_113 = V_27 ;
F_19 ( V_88 , V_3 ) ;
V_24 = (struct V_23 * ) F_41 ( V_3 ) ;
memset ( V_24 , 0 , sizeof *V_24 + sizeof *V_115 ) ;
memset ( V_24 -> V_30 , 0xff , sizeof V_24 -> V_30 ) ;
memcpy ( V_24 -> V_26 , V_27 -> V_29 , sizeof V_24 -> V_26 ) ;
V_24 -> type = F_13 ( V_6 ) ;
V_24 -> V_32 = V_33 ;
V_24 -> V_34 = F_14 ( V_35 ) ;
V_24 -> V_36 = V_37 ;
V_24 -> V_38 = V_119 ;
V_117:
F_52 ( V_27 ) ;
}
F_53 () ;
}
static void
F_54 ( struct V_8 * V_9 , struct V_7 * V_11 )
{
struct V_1 * V_3 ;
struct V_87 V_88 ;
struct V_23 * V_24 ;
struct V_40 * V_41 ;
struct V_21 * V_22 ;
char V_56 [ 128 ] ;
T_2 V_16 ;
V_22 = V_11 -> V_22 ;
V_16 = F_11 ( V_9 ) ;
V_3 = V_11 -> V_3 ;
if ( F_17 ( V_22 ) == NULL ) {
F_55 ( L_3 ) ;
F_56 ( V_11 , NULL ) ;
return;
}
V_24 = (struct V_23 * ) F_41 ( V_3 ) ;
V_41 = (struct V_40 * ) ( V_24 + 1 ) ;
snprintf ( V_56 , sizeof V_56 ,
L_4 ,
L_5 , V_9 -> V_35 , V_9 -> V_37 , V_11 -> V_10 , V_19 , V_16 ,
V_24 -> V_26 , V_24 -> V_30 , V_22 -> V_72 ) ;
F_57 ( V_56 ) ;
V_11 -> V_10 = V_16 ;
F_36 ( V_11 ) ;
V_24 -> V_10 = F_15 ( V_16 ) ;
memcpy ( V_24 -> V_30 , V_22 -> V_31 , sizeof V_24 -> V_30 ) ;
memcpy ( V_24 -> V_26 , V_22 -> V_27 -> V_28 -> V_29 , sizeof V_24 -> V_26 ) ;
V_3 -> V_113 = V_22 -> V_27 -> V_28 ;
V_3 = F_44 ( V_3 , V_4 ) ;
if ( V_3 == NULL )
return;
F_45 ( & V_88 ) ;
F_19 ( & V_88 , V_3 ) ;
F_46 ( & V_88 ) ;
}
static int
F_58 ( T_2 V_10 )
{
int V_16 ;
V_16 = V_19 & 0xffff ;
V_16 -= V_10 & 0xffff ;
if ( V_16 < 0 )
V_16 += 1 << 16 ;
return V_16 ;
}
static struct V_49 *
F_59 ( struct V_21 * V_22 , struct V_116 * V_28 )
{
struct V_49 * V_120 , * V_121 ;
V_120 = V_22 -> V_50 ;
V_121 = V_120 + V_51 ;
for (; V_120 < V_121 ; V_120 ++ )
if ( V_120 -> V_28 == V_28 )
return V_120 ;
return NULL ;
}
static void
F_60 ( struct V_21 * V_22 , struct V_49 * V_27 )
{
struct V_49 * V_121 ;
struct V_116 * V_28 ;
T_1 V_16 ;
V_28 = V_27 -> V_28 ;
V_121 = V_22 -> V_50 + V_51 - 1 ;
V_16 = ( V_121 - V_27 ) * sizeof *V_27 ;
memmove ( V_27 , V_27 + 1 , V_16 ) ;
V_121 -> V_28 = NULL ;
F_52 ( V_28 ) ;
}
static int
F_61 ( struct V_8 * V_9 )
{
struct V_7 * V_11 , * V_122 ;
struct V_12 * V_15 , * V_14 , * V_13 ;
struct V_1 * V_3 ;
struct V_21 * V_123 = V_9 -> V_74 ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_17 ; V_124 ++ ) {
V_13 = & V_9 -> V_18 [ V_124 ] ;
F_8 (pos, nx, head) {
V_11 = F_9 ( V_14 , struct V_7 , V_13 ) ;
if ( V_11 -> V_22 != V_123 )
continue;
V_122 = F_32 ( V_9 ) ;
if ( ! V_122 )
return 0 ;
F_10 ( V_14 ) ;
V_3 = V_122 -> V_3 ;
V_122 -> V_3 = V_11 -> V_3 ;
V_122 -> V_56 = V_11 -> V_56 ;
V_122 -> V_89 = V_11 -> V_89 ;
V_122 -> V_42 = V_11 -> V_42 ;
V_122 -> V_57 = V_11 -> V_57 ;
V_122 -> V_96 = V_11 -> V_96 ;
V_122 -> V_99 = 0 ;
V_11 -> V_3 = V_3 ;
F_26 ( V_11 ) ;
V_123 -> V_72 -- ;
V_122 -> V_22 -> V_72 ++ ;
F_54 ( V_9 , V_122 ) ;
}
}
memset ( V_123 -> V_50 , 0 , sizeof V_123 -> V_50 ) ;
V_9 -> V_74 = NULL ;
return 1 ;
}
static inline unsigned char
F_62 ( unsigned char * V_125 ) {
struct V_23 * V_24 ;
struct V_40 * V_41 ;
V_24 = (struct V_23 * ) V_125 ;
V_41 = (struct V_40 * ) ( V_24 + 1 ) ;
return V_41 -> V_101 ;
}
static void
F_63 ( T_1 V_126 )
{
struct V_8 * V_9 ;
struct V_21 * V_22 , * * V_66 , * * V_127 ;
struct V_49 * V_27 ;
struct V_7 * V_11 ;
struct V_12 * V_13 , * V_14 , * V_15 ;
F_64 ( V_128 ) ;
register long V_129 ;
T_1 V_76 , V_16 ;
int V_124 ;
V_9 = (struct V_8 * ) V_126 ;
V_129 = V_9 -> V_130 ;
V_129 += V_129 >> 1 ;
F_65 ( & V_9 -> V_131 , V_76 ) ;
if ( V_9 -> V_76 & V_132 ) {
F_66 ( & V_9 -> V_131 , V_76 ) ;
return;
}
for ( V_124 = 0 ; V_124 < V_17 ; V_124 ++ ) {
V_13 = & V_9 -> V_18 [ V_124 ] ;
F_8 (pos, nx, head) {
V_11 = F_9 ( V_14 , struct V_7 , V_13 ) ;
if ( F_58 ( V_11 -> V_10 ) < V_129 )
break;
F_67 ( V_14 , & V_128 ) ;
}
}
V_66 = V_9 -> V_68 ;
V_127 = V_66 + V_9 -> V_133 ;
for (; V_66 < V_127 && ( V_22 = * V_66 ) ; V_66 ++ ) {
if ( V_22 -> V_72 == V_22 -> V_73
&& V_22 -> V_73 < V_22 -> V_134
&& ( V_19 - V_22 -> V_135 ) / V_136 > 10 ) {
V_22 -> V_73 ++ ;
V_22 -> V_135 = V_19 ;
}
}
if ( ! F_29 ( & V_128 ) ) {
V_16 = V_9 -> V_130 <<= 1 ;
if ( V_16 > V_137 )
V_9 -> V_130 = V_137 ;
}
while ( ! F_29 ( & V_128 ) ) {
V_14 = V_128 . V_61 ;
V_11 = F_9 ( V_14 , struct V_7 , V_13 ) ;
V_16 = V_11 -> V_99 += V_129 ;
V_16 /= V_136 ;
if ( V_16 > V_138 ) {
F_68 ( & V_128 , & V_9 -> V_18 [ 0 ] ) ;
F_69 ( V_9 ) ;
break;
}
F_10 ( V_14 ) ;
V_22 = V_11 -> V_22 ;
if ( V_16 > V_138 / 2 )
V_9 -> V_74 = V_22 ;
if ( V_22 -> V_72 == V_22 -> V_73 ) {
if ( V_22 -> V_73 > 1 )
V_22 -> V_73 -- ;
V_22 -> V_135 = V_19 ;
}
V_27 = F_59 ( V_22 , V_11 -> V_3 -> V_113 ) ;
if ( V_27 && ++ V_27 -> V_139 > ( V_22 -> V_134 << 1 )
&& ( V_27 != V_22 -> V_50 || V_22 -> V_50 [ 1 ] . V_28 ) ) {
F_60 ( V_22 , V_27 ) ;
V_27 = NULL ;
}
F_54 ( V_9 , V_11 ) ;
}
if ( ( V_9 -> V_76 & V_77 || V_9 -> V_74 ) && V_9 -> V_140 ) {
V_9 -> V_76 &= ~ V_77 ;
V_9 -> V_140 -> V_141 ( V_9 -> V_140 ) ;
}
V_9 -> V_142 . V_143 = V_19 + V_144 ;
F_70 ( & V_9 -> V_142 ) ;
F_66 ( & V_9 -> V_131 , V_76 ) ;
}
static unsigned long
F_71 ( struct V_145 * V_146 )
{
struct V_105 * V_105 ;
unsigned long V_16 = 0 ;
F_72 (bio, r)
V_16 ++ ;
return V_16 ;
}
static void
F_73 ( struct V_105 * V_105 )
{
struct V_78 * V_57 ;
struct V_147 * V_147 ;
int V_124 ;
F_74 (bv, bio, i) {
V_147 = V_57 -> V_86 ;
if ( F_75 ( F_76 ( V_147 ) ) )
if ( F_77 ( V_147 ) != V_147 ) {
F_78 ( L_6 ) ;
F_79 () ;
}
F_80 ( & V_147 -> V_148 ) ;
}
}
static void
F_81 ( struct V_105 * V_105 )
{
struct V_78 * V_57 ;
int V_124 ;
F_74 (bv, bio, i)
F_82 ( & V_57 -> V_86 -> V_148 ) ;
}
static void
F_83 ( struct V_56 * V_56 , struct V_145 * V_149 , struct V_105 * V_105 )
{
struct V_78 * V_57 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_56 -> V_149 = V_149 ;
V_56 -> V_105 = V_105 ;
V_56 -> V_95 = V_105 -> V_150 ;
V_56 -> V_100 = V_105 -> V_151 ;
F_73 ( V_105 ) ;
V_56 -> V_57 = V_57 = & V_105 -> V_152 [ V_105 -> V_153 ] ;
V_56 -> V_97 = V_57 -> V_84 ;
F_40 ( V_56 -> V_97 == 0 ) ;
}
static struct V_56 *
F_39 ( struct V_8 * V_9 )
{
struct V_145 * V_149 ;
struct V_154 * V_155 ;
struct V_56 * V_56 ;
struct V_105 * V_105 ;
V_155 = V_9 -> V_140 ;
if ( V_155 == NULL )
return NULL ;
if ( V_9 -> V_98 . V_56 )
return V_9 -> V_98 . V_56 ;
V_149 = V_9 -> V_98 . V_149 ;
if ( V_149 == NULL ) {
V_149 = F_84 ( V_155 ) ;
if ( V_149 == NULL )
return NULL ;
F_85 ( V_149 ) ;
V_9 -> V_98 . V_149 = V_149 ;
V_9 -> V_98 . V_156 = V_149 -> V_105 ;
V_149 -> V_157 = ( void * ) F_71 ( V_149 ) ;
}
V_56 = F_86 ( V_9 -> V_158 , V_4 ) ;
if ( V_56 == NULL ) {
F_87 ( L_7 ) ;
return NULL ;
}
V_105 = V_9 -> V_98 . V_156 ;
F_83 ( V_56 , V_149 , V_105 ) ;
V_105 = V_105 -> V_159 ;
V_9 -> V_98 . V_156 = V_105 ;
if ( V_105 == NULL )
V_9 -> V_98 . V_149 = NULL ;
return V_9 -> V_98 . V_56 = V_56 ;
}
void
F_88 ( struct V_8 * V_9 )
{
if ( V_9 -> V_74 && ! F_61 ( V_9 ) )
return;
while ( F_38 ( V_9 ) )
;
}
void
F_89 ( struct V_160 * V_161 )
{
struct V_8 * V_9 = F_90 ( V_161 , struct V_8 , V_161 ) ;
struct V_162 * V_163 ;
T_5 V_164 ;
if ( V_9 -> V_76 & V_165 )
F_91 ( V_9 ) ;
if ( V_9 -> V_76 & V_166 ) {
V_164 = F_92 ( V_9 -> V_167 ) ;
V_163 = F_93 ( V_9 -> V_167 , 0 ) ;
if ( V_163 ) {
F_94 ( & V_163 -> V_168 -> V_169 ) ;
F_95 ( V_163 -> V_168 , ( V_170 ) V_164 << 9 ) ;
F_96 ( & V_163 -> V_168 -> V_169 ) ;
F_97 ( V_163 ) ;
}
F_98 ( & V_9 -> V_131 ) ;
V_9 -> V_76 |= V_171 ;
V_9 -> V_76 &= ~ V_166 ;
F_99 ( & V_9 -> V_131 ) ;
}
}
static void
F_100 ( struct V_8 * V_9 , struct V_21 * V_22 , unsigned char * V_172 )
{
T_5 V_164 ;
T_6 V_16 ;
V_16 = F_101 ( & V_172 [ 83 << 1 ] ) ;
V_16 |= F_101 ( & V_172 [ 86 << 1 ] ) ;
if ( V_16 & ( 1 << 10 ) ) {
V_9 -> V_76 |= V_102 ;
V_164 = F_102 ( & V_172 [ 100 << 1 ] ) ;
V_9 -> V_173 . V_174 = V_164 ;
V_9 -> V_173 . V_174 /= ( 255 * 63 ) ;
V_9 -> V_173 . V_175 = 255 ;
V_9 -> V_173 . V_176 = 63 ;
} else {
V_9 -> V_76 &= ~ V_102 ;
V_164 = F_103 ( & V_172 [ 60 << 1 ] ) ;
V_9 -> V_173 . V_174 = F_101 ( & V_172 [ 54 << 1 ] ) ;
V_9 -> V_173 . V_175 = F_101 ( & V_172 [ 55 << 1 ] ) ;
V_9 -> V_173 . V_176 = F_101 ( & V_172 [ 56 << 1 ] ) ;
}
if ( V_9 -> V_164 != V_164 )
F_33 ( V_118
L_8 ,
V_22 -> V_31 ,
V_9 -> V_35 , V_9 -> V_37 ,
V_9 -> V_177 , ( long long ) V_164 ) ;
V_9 -> V_164 = V_164 ;
V_9 -> V_173 . V_178 = 0 ;
if ( V_9 -> V_76 & ( V_165 | V_166 ) )
return;
if ( V_9 -> V_167 != NULL ) {
F_104 ( V_9 -> V_167 , V_164 ) ;
V_9 -> V_76 |= V_166 ;
} else
V_9 -> V_76 |= V_165 ;
F_105 ( & V_9 -> V_161 ) ;
}
static void
F_106 ( struct V_8 * V_9 , int V_179 )
{
register long V_16 ;
V_16 = V_179 ;
if ( V_16 < 0 ) {
V_16 = - V_179 ;
if ( V_16 < V_180 )
V_16 = V_180 ;
else if ( V_16 > V_137 )
V_16 = V_137 ;
V_9 -> V_181 += ( V_16 - V_9 -> V_181 ) >> 1 ;
} else if ( V_16 < V_9 -> V_181 )
V_16 = V_9 -> V_181 ;
else if ( V_16 > V_137 )
V_16 = V_137 ;
V_16 -= V_9 -> V_130 ;
V_9 -> V_130 += V_16 >> 2 ;
}
static struct V_21 *
F_107 ( struct V_8 * V_9 , char * V_31 )
{
struct V_21 * * V_22 , * * V_121 ;
V_22 = V_9 -> V_68 ;
V_121 = V_22 + V_71 ;
for (; V_22 < V_121 && * V_22 ; V_22 ++ )
if ( memcmp ( ( * V_22 ) -> V_31 , V_31 , sizeof( ( * V_22 ) -> V_31 ) ) == 0 )
return * V_22 ;
return NULL ;
}
static void
F_108 ( struct V_78 * V_57 , T_1 V_79 , struct V_1 * V_3 , long V_80 )
{
T_1 V_82 ;
char * V_120 ;
int V_182 = 0 ;
V_83:
V_82 = V_57 -> V_84 - ( V_79 - V_57 -> V_85 ) ;
if ( V_82 > V_80 )
V_82 = V_80 ;
V_120 = F_109 ( V_57 -> V_86 ) + V_79 ;
F_110 ( V_3 , V_182 , V_120 , V_82 ) ;
V_182 += V_82 ;
V_80 -= V_82 ;
if ( V_80 <= 0 )
return;
V_57 ++ ;
V_79 = V_57 -> V_85 ;
goto V_83;
}
void
F_111 ( struct V_8 * V_9 , struct V_145 * V_149 , int V_183 )
{
struct V_105 * V_105 ;
int V_184 ;
struct V_154 * V_155 ;
V_155 = V_9 -> V_140 ;
if ( V_149 == V_9 -> V_98 . V_149 )
V_9 -> V_98 . V_149 = NULL ;
do {
V_105 = V_149 -> V_105 ;
V_184 = ! V_183 && F_112 ( V_185 , & V_105 -> V_186 ) ;
} while ( F_113 ( V_149 , V_184 ? 0 : - V_187 , V_105 -> V_150 ) );
if ( ! V_183 )
F_114 ( V_155 ) ;
}
static void
F_115 ( struct V_8 * V_9 , struct V_56 * V_56 )
{
struct V_145 * V_149 ;
unsigned long V_16 ;
if ( V_56 == V_9 -> V_98 . V_56 )
V_9 -> V_98 . V_56 = NULL ;
V_149 = V_56 -> V_149 ;
F_81 ( V_56 -> V_105 ) ;
F_116 ( V_56 , V_9 -> V_158 ) ;
V_16 = ( unsigned long ) V_149 -> V_157 ;
V_149 -> V_157 = ( void * ) -- V_16 ;
if ( V_16 == 0 )
F_111 ( V_9 , V_149 , 0 ) ;
}
static void
F_117 ( struct V_7 * V_11 )
{
struct V_23 * V_188 , * V_189 ;
struct V_40 * V_190 , * V_191 ;
struct V_56 * V_56 ;
struct V_1 * V_3 ;
struct V_21 * V_22 ;
struct V_49 * V_27 ;
struct V_8 * V_9 ;
long V_16 ;
if ( V_11 == NULL )
return;
V_22 = V_11 -> V_22 ;
V_9 = V_22 -> V_9 ;
V_189 = (struct V_23 * ) F_41 ( V_11 -> V_3 ) ;
V_191 = (struct V_40 * ) ( V_189 + 1 ) ;
V_56 = V_11 -> V_56 ;
V_3 = V_11 -> V_58 ;
if ( V_3 == NULL )
goto V_192;
V_188 = (struct V_23 * ) V_3 -> V_193 ;
F_118 ( V_3 , sizeof( * V_188 ) ) ;
V_190 = (struct V_40 * ) V_3 -> V_193 ;
F_118 ( V_3 , sizeof( * V_190 ) ) ;
if ( V_190 -> V_110 & 0xa9 ) {
F_87 ( L_9 ,
V_191 -> V_110 , V_190 -> V_110 ,
V_9 -> V_35 , V_9 -> V_37 ) ;
V_192: if ( V_56 )
F_119 ( V_185 , & V_56 -> V_105 -> V_186 ) ;
goto V_194;
}
V_16 = V_191 -> V_101 << 9 ;
switch ( V_191 -> V_110 ) {
case V_111 :
case V_195 :
if ( V_3 -> V_2 < V_16 ) {
F_87 ( L_10 ,
V_3 -> V_2 , V_16 ) ;
F_119 ( V_185 , & V_56 -> V_105 -> V_186 ) ;
break;
}
F_108 ( V_11 -> V_57 , V_11 -> V_96 , V_3 , V_16 ) ;
case V_196 :
case V_197 :
F_98 ( & V_9 -> V_131 ) ;
V_27 = F_59 ( V_22 , V_3 -> V_113 ) ;
if ( V_27 )
V_27 -> V_139 = 0 ;
if ( V_9 -> V_74 == V_22 )
V_9 -> V_74 = NULL ;
F_99 ( & V_9 -> V_131 ) ;
break;
case V_198 :
if ( V_3 -> V_2 < 512 ) {
F_55 ( L_11 ,
V_3 -> V_2 ) ;
break;
}
if ( F_120 ( V_3 ) )
break;
F_98 ( & V_9 -> V_131 ) ;
F_100 ( V_9 , V_22 , V_3 -> V_193 ) ;
F_99 ( & V_9 -> V_131 ) ;
break;
default:
F_55 ( L_12 ,
V_191 -> V_110 ,
F_121 ( F_122 ( & V_188 -> V_34 ) ) ,
V_188 -> V_36 ) ;
}
V_194:
F_98 ( & V_9 -> V_131 ) ;
F_26 ( V_11 ) ;
if ( V_56 && -- V_56 -> V_112 == 0 && V_56 -> V_95 == 0 )
F_115 ( V_9 , V_56 ) ;
F_88 ( V_9 ) ;
F_99 ( & V_9 -> V_131 ) ;
F_123 ( V_9 ) ;
F_124 ( V_3 ) ;
}
static int
F_125 ( void )
{
struct V_7 * V_11 ;
struct V_12 * V_14 ;
int V_124 ;
for ( V_124 = 0 ; ; ++ V_124 ) {
if ( V_124 == V_199 )
return 1 ;
if ( F_29 ( & V_200 . V_13 ) )
return 0 ;
V_14 = V_200 . V_13 . V_61 ;
F_10 ( V_14 ) ;
F_99 ( & V_200 . V_131 ) ;
V_11 = F_9 ( V_14 , struct V_7 , V_13 ) ;
F_117 ( V_11 ) ;
F_98 ( & V_200 . V_131 ) ;
}
}
static int
F_126 ( void * V_126 )
{
struct V_201 * V_202 ;
F_127 ( V_203 , V_204 ) ;
int V_205 ;
V_202 = V_126 ;
V_204 -> V_76 |= V_206 ;
F_128 ( V_204 , - 10 ) ;
F_129 ( & V_202 -> V_207 ) ;
do {
F_98 ( V_202 -> V_131 ) ;
V_205 = V_202 -> V_208 () ;
if ( ! V_205 ) {
F_130 ( V_202 -> V_209 , & V_203 ) ;
F_131 ( V_210 ) ;
}
F_99 ( V_202 -> V_131 ) ;
if ( ! V_205 ) {
F_132 () ;
F_133 ( V_202 -> V_209 , & V_203 ) ;
} else
F_134 () ;
} while ( ! F_135 () );
F_129 ( & V_202 -> V_207 ) ;
return 0 ;
}
void
F_136 ( struct V_201 * V_202 )
{
F_137 ( V_202 -> V_211 ) ;
F_138 ( & V_202 -> V_207 ) ;
}
int
F_139 ( struct V_201 * V_202 )
{
struct V_212 * V_211 ;
F_140 ( & V_202 -> V_207 ) ;
V_211 = F_141 ( F_126 , V_202 , V_202 -> V_213 ) ;
if ( V_211 == NULL || F_142 ( V_211 ) )
return - V_214 ;
V_202 -> V_211 = V_211 ;
F_138 ( & V_202 -> V_207 ) ;
F_140 ( & V_202 -> V_207 ) ;
return 0 ;
}
static void
F_56 ( struct V_7 * V_11 , struct V_1 * V_3 )
{
T_1 V_76 ;
V_11 -> V_58 = V_3 ;
F_65 ( & V_200 . V_131 , V_76 ) ;
F_37 ( & V_11 -> V_13 , & V_200 . V_13 ) ;
F_66 ( & V_200 . V_131 , V_76 ) ;
F_143 ( & V_215 ) ;
}
struct V_1 *
F_144 ( struct V_1 * V_3 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
struct V_7 * V_11 ;
struct V_21 * V_22 ;
T_2 V_16 ;
T_1 V_76 ;
char V_216 [ 128 ] ;
T_6 V_35 ;
V_24 = (struct V_23 * ) V_3 -> V_193 ;
V_35 = F_121 ( F_122 ( & V_24 -> V_34 ) ) ;
V_9 = F_145 ( V_35 , V_24 -> V_36 , 0 ) ;
if ( V_9 == NULL ) {
snprintf ( V_216 , sizeof V_216 , L_13
L_14 ,
V_35 , V_24 -> V_36 ) ;
F_57 ( V_216 ) ;
return V_3 ;
}
F_65 ( & V_9 -> V_131 , V_76 ) ;
V_16 = F_146 ( F_122 ( & V_24 -> V_10 ) ) ;
V_11 = F_7 ( V_9 , V_16 ) ;
if ( V_11 == NULL ) {
F_106 ( V_9 , - F_58 ( V_16 ) ) ;
F_66 ( & V_9 -> V_131 , V_76 ) ;
F_123 ( V_9 ) ;
snprintf ( V_216 , sizeof V_216 ,
L_15 ,
L_16 ,
F_147 ( & V_24 -> V_34 ) ,
V_24 -> V_36 ,
F_148 ( & V_24 -> V_10 ) ,
V_19 ) ;
F_57 ( V_216 ) ;
return V_3 ;
}
V_22 = V_11 -> V_22 ;
F_106 ( V_9 , F_58 ( V_11 -> V_10 ) ) ;
V_22 -> V_72 -- ;
F_88 ( V_9 ) ;
F_66 ( & V_9 -> V_131 , V_76 ) ;
F_56 ( V_11 , V_3 ) ;
return NULL ;
}
void
F_149 ( T_4 V_35 , unsigned char V_37 )
{
struct V_87 V_88 ;
F_45 ( & V_88 ) ;
F_47 ( V_35 , V_37 , & V_88 ) ;
F_46 ( & V_88 ) ;
}
struct V_1 *
F_150 ( struct V_8 * V_9 )
{
struct V_23 * V_24 ;
struct V_40 * V_41 ;
struct V_7 * V_11 ;
struct V_1 * V_3 ;
struct V_21 * V_22 ;
V_11 = F_32 ( V_9 ) ;
if ( V_11 == NULL )
return NULL ;
V_22 = * V_9 -> V_70 ;
V_3 = V_11 -> V_3 ;
V_24 = (struct V_23 * ) F_41 ( V_3 ) ;
V_41 = (struct V_40 * ) ( V_24 + 1 ) ;
F_42 ( V_3 , sizeof *V_24 + sizeof *V_41 ) ;
memset ( V_24 , 0 , V_3 -> V_2 ) ;
V_11 -> V_10 = F_12 ( V_9 , V_22 , V_24 ) ;
F_36 ( V_11 ) ;
V_22 -> V_72 ++ ;
V_11 -> V_99 = 0 ;
V_41 -> V_101 = 1 ;
V_41 -> V_110 = V_198 ;
V_41 -> V_46 = 0xa0 ;
V_3 -> V_113 = V_22 -> V_27 -> V_28 ;
V_9 -> V_130 = V_137 ;
V_9 -> V_142 . V_217 = F_63 ;
return F_44 ( V_3 , V_4 ) ;
}
static struct V_21 *
F_151 ( struct V_8 * V_9 , char * V_31 , T_1 V_134 )
{
struct V_21 * V_22 , * * V_66 , * * V_127 ;
V_66 = V_9 -> V_68 ;
V_127 = V_66 + V_71 ;
for (; V_66 < V_127 && * V_66 ; V_66 ++ )
;
if ( V_66 == V_127 ) {
F_33 ( V_118
L_17 ) ;
return NULL ;
}
V_22 = F_152 ( sizeof( * V_22 ) , V_4 ) ;
if ( ! V_22 ) {
F_33 ( V_118 L_18 ) ;
return NULL ;
}
V_9 -> V_133 ++ ;
V_22 -> V_134 = V_134 ;
V_22 -> V_9 = V_9 ;
memcpy ( V_22 -> V_31 , V_31 , sizeof V_22 -> V_31 ) ;
V_22 -> V_27 = V_22 -> V_50 ;
V_22 -> V_73 = V_22 -> V_134 ;
F_153 ( & V_22 -> V_59 ) ;
return * V_66 = V_22 ;
}
static void
F_154 ( struct V_8 * V_9 )
{
struct V_21 * * V_22 , * * V_121 ;
int V_89 = 0 ;
V_22 = V_9 -> V_68 ;
V_121 = V_22 + V_71 ;
for (; V_22 < V_121 && * V_22 ; V_22 ++ )
if ( V_89 == 0 || V_89 > ( * V_22 ) -> V_218 )
V_89 = ( * V_22 ) -> V_218 ;
if ( V_89 != V_9 -> V_93 ) {
V_9 -> V_93 = V_89 ;
F_55 ( L_19 ,
V_9 -> V_35 , V_9 -> V_37 , V_89 ) ;
}
}
static void
F_155 ( struct V_21 * V_22 , struct V_116 * V_28 , int V_89 )
{
struct V_8 * V_9 ;
struct V_49 * V_120 , * V_121 ;
int V_218 ;
V_9 = V_22 -> V_9 ;
V_218 = V_89 ;
V_120 = V_22 -> V_50 ;
V_121 = V_120 + V_51 ;
for (; V_120 < V_121 ; V_120 ++ ) {
if ( V_120 -> V_28 == NULL )
break;
if ( V_120 -> V_28 == V_28 ) {
V_120 -> V_89 = V_89 ;
V_28 = NULL ;
} else if ( V_218 > V_120 -> V_89 )
V_218 = V_120 -> V_89 ;
}
if ( V_28 ) {
if ( V_120 == V_121 ) {
F_87 ( L_20 ) ;
return;
}
F_50 ( V_28 ) ;
V_120 -> V_28 = V_28 ;
V_120 -> V_89 = V_89 ;
}
V_22 -> V_218 = V_218 ;
F_154 ( V_9 ) ;
}
void
F_156 ( struct V_1 * V_3 )
{
struct V_8 * V_9 ;
struct V_23 * V_24 ;
struct V_114 * V_115 ;
struct V_21 * V_22 ;
T_1 V_76 , V_35 ;
struct V_1 * V_219 ;
struct V_87 V_88 ;
T_6 V_16 ;
V_219 = NULL ;
V_24 = (struct V_23 * ) F_41 ( V_3 ) ;
V_115 = (struct V_114 * ) ( V_24 + 1 ) ;
V_35 = F_147 ( & V_24 -> V_34 ) ;
if ( V_35 == 0xfff ) {
F_33 ( V_69 L_21
L_22 ) ;
return;
}
if ( V_35 == 0xffff ) {
F_55 ( L_23 ,
V_35 , ( int ) V_24 -> V_36 ) ;
return;
}
if ( V_24 -> V_36 == 0xff ) {
F_55 ( L_24 ,
V_35 , ( int ) V_24 -> V_36 ) ;
return;
}
V_16 = F_121 ( V_115 -> V_220 ) ;
if ( V_16 > V_221 )
V_16 = V_221 ;
V_9 = F_145 ( V_35 , V_24 -> V_36 , 1 ) ;
if ( V_9 == NULL ) {
F_55 ( L_25 ) ;
return;
}
F_65 ( & V_9 -> V_131 , V_76 ) ;
V_22 = F_107 ( V_9 , V_24 -> V_26 ) ;
if ( ! V_22 ) {
V_22 = F_151 ( V_9 , V_24 -> V_26 , V_16 ) ;
if ( ! V_22 )
goto V_62;
}
V_16 = V_3 -> V_113 -> V_222 ;
V_16 -= sizeof( struct V_23 ) + sizeof( struct V_40 ) ;
V_16 /= 512 ;
if ( V_16 > V_115 -> V_101 )
V_16 = V_115 -> V_101 ;
V_16 = V_16 ? V_16 * 512 : V_94 ;
F_155 ( V_22 , V_3 -> V_113 , V_16 ) ;
if ( V_9 -> V_223 == 0 ) {
V_9 -> V_177 = F_121 ( V_115 -> V_224 ) ;
V_219 = F_150 ( V_9 ) ;
}
V_62:
F_66 ( & V_9 -> V_131 , V_76 ) ;
F_123 ( V_9 ) ;
if ( V_219 ) {
F_45 ( & V_88 ) ;
F_19 ( & V_88 , V_219 ) ;
F_46 ( & V_88 ) ;
}
}
void
F_157 ( struct V_8 * V_9 )
{
struct V_21 * * V_22 , * * V_127 ;
V_9 -> V_181 = V_180 ;
V_9 -> V_93 = 0 ;
V_22 = V_9 -> V_68 ;
V_127 = V_22 + V_71 ;
for (; V_22 < V_127 && * V_22 ; V_22 ++ )
( * V_22 ) -> V_73 = ( * V_22 ) -> V_134 ;
}
void
F_158 ( struct V_8 * V_9 , struct V_56 * V_56 )
{
if ( V_56 == NULL )
return;
V_56 -> V_95 = 0 ;
F_119 ( V_185 , & V_56 -> V_105 -> V_186 ) ;
if ( V_56 -> V_112 == 0 )
F_115 ( V_9 , V_56 ) ;
}
void
F_159 ( void )
{
struct V_7 * V_11 ;
struct V_8 * V_9 ;
F_64 ( V_128 ) ;
struct V_12 * V_14 ;
struct V_1 * V_3 ;
T_1 V_76 ;
F_65 ( & V_200 . V_131 , V_76 ) ;
F_160 ( & V_200 . V_13 , & V_128 ) ;
F_66 ( & V_200 . V_131 , V_76 ) ;
while ( ! F_29 ( & V_128 ) ) {
V_14 = V_128 . V_61 ;
F_10 ( V_14 ) ;
V_11 = F_9 ( V_14 , struct V_7 , V_13 ) ;
V_9 = V_11 -> V_22 -> V_9 ;
V_3 = V_11 -> V_58 ;
F_65 ( & V_9 -> V_131 , V_76 ) ;
if ( V_11 -> V_56 ) {
V_11 -> V_56 -> V_112 -- ;
F_158 ( V_9 , V_11 -> V_56 ) ;
}
F_26 ( V_11 ) ;
F_66 ( & V_9 -> V_131 , V_76 ) ;
F_124 ( V_3 ) ;
F_123 ( V_9 ) ;
}
}
int T_7
F_161 ( void )
{
F_153 ( & V_200 . V_13 ) ;
F_162 ( & V_200 . V_131 ) ;
F_163 ( & V_215 ) ;
V_225 . V_213 = L_26 ;
V_225 . V_208 = F_125 ;
V_225 . V_209 = & V_215 ;
V_225 . V_131 = & V_200 . V_131 ;
return F_139 ( & V_225 ) ;
}
void
F_164 ( void )
{
F_136 ( & V_225 ) ;
F_159 () ;
}
