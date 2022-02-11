static struct V_1 *
F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_2 + V_4 , V_5 ) ;
if ( V_3 ) {
F_3 ( V_3 , V_4 ) ;
F_4 ( V_3 ) ;
F_5 ( V_3 ) ;
V_3 -> V_6 = F_6 ( V_7 ) ;
F_7 ( V_3 ) ;
}
return V_3 ;
}
static struct V_8 *
F_8 ( struct V_9 * V_10 , T_2 V_11 )
{
struct V_12 * V_13 , * V_14 , * V_15 ;
struct V_8 * V_16 ;
V_13 = & V_10 -> V_17 ;
F_9 (pos, nx, head) {
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
if ( V_16 -> V_11 == V_11 ) {
F_11 ( V_14 ) ;
return V_16 ;
}
}
return NULL ;
}
static struct V_8 *
F_12 ( struct V_9 * V_10 , T_2 V_11 )
{
struct V_8 * V_16 ;
struct V_12 * V_13 , * V_14 , * V_15 ;
T_2 V_18 ;
V_18 = V_11 % V_19 ;
V_13 = & V_10 -> V_20 [ V_18 ] ;
F_9 (pos, nx, head) {
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
if ( V_16 -> V_11 == V_11 ) {
F_11 ( V_14 ) ;
return V_16 ;
}
}
return NULL ;
}
static int
F_13 ( struct V_9 * V_10 )
{
register T_1 V_18 ;
V_18 = V_21 & 0xffff ;
return V_18 |= ( ++ V_10 -> V_22 & 0x7fff ) << 16 ;
}
static T_2
F_14 ( struct V_9 * V_10 , struct V_23 * V_24 , struct V_25 * V_26 )
{
T_2 V_27 = F_13 ( V_10 ) ;
memcpy ( V_26 -> V_28 , V_24 -> V_29 -> V_30 -> V_31 , sizeof V_26 -> V_28 ) ;
memcpy ( V_26 -> V_32 , V_24 -> V_33 , sizeof V_26 -> V_32 ) ;
V_26 -> type = F_15 ( V_7 ) ;
V_26 -> V_34 = V_35 ;
V_26 -> V_36 = F_16 ( V_10 -> V_37 ) ;
V_26 -> V_38 = V_10 -> V_39 ;
V_26 -> V_40 = V_41 ;
V_26 -> V_11 = F_17 ( V_27 ) ;
return V_27 ;
}
static inline void
F_18 ( struct V_42 * V_43 , T_3 V_44 )
{
V_43 -> V_45 = V_44 ;
V_43 -> V_46 = V_44 >>= 8 ;
V_43 -> V_47 = V_44 >>= 8 ;
V_43 -> V_48 = V_44 >>= 8 ;
V_43 -> V_49 = V_44 >>= 8 ;
V_43 -> V_50 = V_44 >>= 8 ;
}
static struct V_51 *
F_19 ( struct V_23 * V_24 )
{
struct V_51 * V_29 ;
V_29 = V_24 -> V_29 ;
V_29 ++ ;
if ( V_29 >= & V_24 -> V_52 [ V_53 ] || V_29 -> V_30 == NULL )
V_29 = V_24 -> V_52 ;
if ( V_29 -> V_30 == NULL )
return NULL ;
return V_24 -> V_29 = V_29 ;
}
static void
F_20 ( struct V_9 * V_10 , struct V_1 * V_3 )
{
F_21 ( & V_10 -> V_54 , V_3 ) ;
}
static struct V_1 *
F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_3 = F_23 ( & V_10 -> V_54 ) ;
if ( V_3 && F_24 ( & F_25 ( V_3 ) -> V_55 ) == 1 ) {
F_26 ( V_3 , & V_10 -> V_54 ) ;
return V_3 ;
}
if ( F_27 ( & V_10 -> V_54 ) < V_56 &&
( V_3 = F_1 ( V_57 ) ) )
return V_3 ;
return NULL ;
}
void
F_28 ( struct V_8 * V_16 )
{
struct V_23 * V_24 ;
V_24 = V_16 -> V_24 ;
V_16 -> V_58 = NULL ;
memset ( & V_16 -> V_59 , 0 , sizeof( V_16 -> V_59 ) ) ;
V_16 -> V_60 = NULL ;
V_16 -> V_61 = 0 ;
F_29 ( & V_16 -> V_13 , & V_24 -> V_62 ) ;
}
static struct V_8 *
F_30 ( struct V_9 * V_10 , struct V_23 * V_24 )
{
struct V_8 * V_16 ;
struct V_1 * V_3 ;
struct V_12 * V_14 ;
if ( F_31 ( & V_24 -> V_62 ) ) {
if ( V_24 -> V_63 >= V_56 * 2 )
return NULL ;
V_16 = F_32 ( 1 , sizeof( * V_16 ) , V_5 ) ;
if ( V_16 == NULL )
return NULL ;
V_24 -> V_63 ++ ;
V_16 -> V_24 = V_24 ;
} else {
V_14 = V_24 -> V_62 . V_64 ;
F_11 ( V_14 ) ;
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
}
V_3 = V_16 -> V_3 ;
if ( V_3 == NULL ) {
V_16 -> V_3 = V_3 = F_1 ( V_57 ) ;
if ( ! V_3 ) {
V_65: F_28 ( V_16 ) ;
return NULL ;
}
}
if ( F_24 ( & F_25 ( V_3 ) -> V_55 ) != 1 ) {
V_3 = F_22 ( V_10 ) ;
if ( V_3 == NULL )
goto V_65;
F_20 ( V_10 , V_16 -> V_3 ) ;
V_16 -> V_3 = V_3 ;
}
V_3 -> V_66 -= V_3 -> V_67 ;
F_25 ( V_3 ) -> V_68 = V_3 -> V_67 = 0 ;
F_33 ( V_3 , 0 ) ;
return V_16 ;
}
static struct V_8 *
F_34 ( struct V_9 * V_10 )
{
struct V_8 * V_16 ;
struct V_23 * V_24 , * * V_69 ;
int V_70 = 0 ;
int V_71 ;
int V_72 ;
if ( ! V_10 -> V_73 || ! V_10 -> V_73 [ 0 ] ) {
F_35 ( V_74 L_1 ) ;
return NULL ;
}
V_69 = V_10 -> V_75 ;
for ( V_71 = 0 , V_72 = 0 ; ; ) {
V_69 ++ ;
if ( V_69 >= & V_10 -> V_73 [ V_10 -> V_76 ] || ! * V_69 )
V_69 = V_10 -> V_73 ;
V_24 = * V_69 ;
if ( ! V_24 -> V_77 ) {
V_72 = 1 ;
V_70 += V_24 -> V_78 ;
}
if ( V_24 -> V_78 < V_24 -> V_79
&& ( V_71 || ! V_24 -> V_77 )
&& V_24 -> V_29 -> V_30 ) {
V_16 = F_30 ( V_10 , V_24 ) ;
if ( V_16 ) {
F_19 ( V_24 ) ;
V_10 -> V_75 = V_69 ;
return V_16 ;
}
}
if ( V_69 == V_10 -> V_75 ) {
if ( ! V_71 && ! V_72 )
V_71 = 1 ;
else
break;
}
}
if ( V_70 == 0 ) {
V_10 -> V_80 ++ ;
V_10 -> V_61 |= V_81 ;
}
return NULL ;
}
static void
F_36 ( struct V_1 * V_3 , struct V_82 * V_82 , struct V_83 V_59 )
{
int V_84 = 0 ;
struct V_85 V_86 ;
F_37 (bv, bio, iter, iter)
F_38 ( V_3 , V_84 ++ , V_86 . V_87 ,
V_86 . V_88 , V_86 . V_89 ) ;
}
static void
F_39 ( struct V_8 * V_16 )
{
struct V_9 * V_10 = V_16 -> V_24 -> V_10 ;
T_2 V_18 ;
V_18 = V_16 -> V_11 % V_19 ;
F_40 ( & V_16 -> V_13 , & V_10 -> V_20 [ V_18 ] ) ;
}
static void
F_41 ( struct V_8 * V_16 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_42 * V_43 ;
struct V_1 * V_3 ;
char V_90 , V_91 ;
V_3 = V_16 -> V_3 ;
V_26 = (struct V_25 * ) F_42 ( V_3 ) ;
V_43 = (struct V_42 * ) ( V_26 + 1 ) ;
F_43 ( V_3 , sizeof( * V_26 ) + sizeof( * V_43 ) ) ;
memset ( V_26 , 0 , V_3 -> V_2 ) ;
V_90 = 0x10 ;
V_91 = 0x4 ;
V_24 = V_16 -> V_24 ;
V_16 -> V_11 = F_14 ( V_24 -> V_10 , V_24 , V_26 ) ;
F_39 ( V_16 ) ;
V_24 -> V_78 ++ ;
V_16 -> V_92 = 0 ;
V_16 -> V_93 = 0 ;
V_43 -> V_94 = V_16 -> V_59 . V_95 >> 9 ;
F_18 ( V_43 , V_16 -> V_59 . V_96 ) ;
if ( V_24 -> V_10 -> V_61 & V_97 ) {
V_43 -> V_98 |= V_99 ;
} else {
V_91 = 0 ;
V_43 -> V_48 &= 0x0f ;
V_43 -> V_48 |= 0xe0 ;
}
if ( V_16 -> V_58 && F_44 ( V_16 -> V_58 -> V_82 ) == V_100 ) {
F_36 ( V_3 , V_16 -> V_58 -> V_82 , V_16 -> V_59 ) ;
V_43 -> V_98 |= V_101 ;
V_3 -> V_2 += V_16 -> V_59 . V_95 ;
V_3 -> V_67 = V_16 -> V_59 . V_95 ;
V_3 -> V_66 += V_16 -> V_59 . V_95 ;
V_24 -> V_102 ++ ;
} else {
V_24 -> V_103 ++ ;
V_90 = 0 ;
}
V_43 -> V_104 = V_105 | V_90 | V_91 ;
V_3 -> V_106 = V_24 -> V_29 -> V_30 ;
}
static int
F_45 ( struct V_9 * V_10 )
{
struct V_8 * V_16 ;
struct V_58 * V_58 ;
struct V_1 * V_3 ;
struct V_107 V_108 ;
V_58 = F_46 ( V_10 ) ;
if ( V_58 == NULL )
return 0 ;
V_16 = F_34 ( V_10 ) ;
if ( V_16 == NULL )
return 0 ;
V_16 -> V_58 = V_58 ;
V_16 -> V_59 = V_58 -> V_59 ;
V_16 -> V_59 . V_95 = F_47 (unsigned long,
d->maxbcnt ?: DEFAULTBCNT,
f->iter.bi_size) ;
F_48 ( V_58 -> V_82 , & V_58 -> V_59 , V_16 -> V_59 . V_95 ) ;
if ( ! V_58 -> V_59 . V_95 )
V_10 -> V_109 . V_58 = NULL ;
V_58 -> V_110 += 1 ;
F_41 ( V_16 ) ;
V_3 = F_49 ( V_16 -> V_3 , V_5 ) ;
if ( V_3 ) {
F_50 ( & V_16 -> V_111 ) ;
V_16 -> V_112 = ( T_2 ) V_21 ;
F_51 ( & V_108 ) ;
F_21 ( & V_108 , V_3 ) ;
F_52 ( & V_108 ) ;
}
return 1 ;
}
static void
F_53 ( T_4 V_37 , unsigned char V_39 , struct V_107 * V_108 )
{
struct V_25 * V_26 ;
struct V_113 * V_114 ;
struct V_1 * V_3 ;
struct V_115 * V_29 ;
F_54 () ;
F_55 (&init_net, ifp) {
F_56 ( V_29 ) ;
if ( ! F_57 ( V_29 ) )
goto V_116;
V_3 = F_1 ( sizeof *V_26 + sizeof *V_114 ) ;
if ( V_3 == NULL ) {
F_35 ( V_117 L_2 ) ;
goto V_116;
}
F_43 ( V_3 , sizeof *V_26 + sizeof *V_114 ) ;
V_3 -> V_106 = V_29 ;
F_21 ( V_108 , V_3 ) ;
V_26 = (struct V_25 * ) F_42 ( V_3 ) ;
memset ( V_26 , 0 , sizeof *V_26 + sizeof *V_114 ) ;
memset ( V_26 -> V_32 , 0xff , sizeof V_26 -> V_32 ) ;
memcpy ( V_26 -> V_28 , V_29 -> V_31 , sizeof V_26 -> V_28 ) ;
V_26 -> type = F_15 ( V_7 ) ;
V_26 -> V_34 = V_35 ;
V_26 -> V_36 = F_16 ( V_37 ) ;
V_26 -> V_38 = V_39 ;
V_26 -> V_40 = V_118 ;
V_116:
F_58 ( V_29 ) ;
}
F_59 () ;
}
static void
F_60 ( struct V_9 * V_10 , struct V_8 * V_16 )
{
struct V_1 * V_3 ;
struct V_107 V_108 ;
struct V_25 * V_26 ;
struct V_23 * V_24 ;
char V_58 [ 128 ] ;
T_2 V_18 ;
V_24 = V_16 -> V_24 ;
V_18 = F_13 ( V_10 ) ;
V_3 = V_16 -> V_3 ;
if ( F_19 ( V_24 ) == NULL ) {
F_61 ( L_3 ) ;
F_62 ( V_16 , NULL ) ;
return;
}
V_26 = (struct V_25 * ) F_42 ( V_3 ) ;
if ( ! ( V_16 -> V_61 & V_119 ) ) {
snprintf ( V_58 , sizeof( V_58 ) ,
L_4 ,
L_5 , V_10 -> V_37 , V_10 -> V_39 ,
V_16 -> V_11 , V_21 , V_18 ,
V_26 -> V_28 , V_26 -> V_32 , V_24 -> V_78 ) ;
F_63 ( V_58 ) ;
}
V_16 -> V_11 = V_18 ;
F_39 ( V_16 ) ;
V_26 -> V_11 = F_17 ( V_18 ) ;
memcpy ( V_26 -> V_32 , V_24 -> V_33 , sizeof V_26 -> V_32 ) ;
memcpy ( V_26 -> V_28 , V_24 -> V_29 -> V_30 -> V_31 , sizeof V_26 -> V_28 ) ;
V_3 -> V_106 = V_24 -> V_29 -> V_30 ;
V_3 = F_49 ( V_3 , V_5 ) ;
if ( V_3 == NULL )
return;
F_50 ( & V_16 -> V_111 ) ;
V_16 -> V_112 = ( T_2 ) V_21 ;
F_51 ( & V_108 ) ;
F_21 ( & V_108 , V_3 ) ;
F_52 ( & V_108 ) ;
}
static int
F_64 ( struct V_8 * V_16 )
{
struct V_120 V_121 ;
int V_18 ;
F_50 ( & V_121 ) ;
V_18 = V_121 . V_122 - V_16 -> V_111 . V_122 ;
V_18 += ( V_121 . V_123 - V_16 -> V_111 . V_123 ) * V_124 ;
if ( V_18 < 0 )
V_18 = - V_18 ;
if ( V_18 > V_124 / 4 ) {
V_18 = ( ( T_2 ) V_21 ) - V_16 -> V_112 ;
V_18 *= V_124 / V_125 ;
}
return V_18 ;
}
static int
F_65 ( T_2 V_11 )
{
int V_18 ;
V_18 = V_21 & 0xffff ;
V_18 -= V_11 & 0xffff ;
if ( V_18 < 0 )
V_18 += 1 << 16 ;
return F_66 ( V_18 + 1 ) ;
}
static struct V_51 *
F_67 ( struct V_23 * V_24 , struct V_115 * V_30 )
{
struct V_51 * V_126 , * V_127 ;
V_126 = V_24 -> V_52 ;
V_127 = V_126 + V_53 ;
for (; V_126 < V_127 ; V_126 ++ )
if ( V_126 -> V_30 == V_30 )
return V_126 ;
return NULL ;
}
static void
F_68 ( struct V_23 * V_24 , struct V_51 * V_29 )
{
struct V_51 * V_127 ;
struct V_115 * V_30 ;
T_1 V_18 ;
V_30 = V_29 -> V_30 ;
V_127 = V_24 -> V_52 + V_53 - 1 ;
V_18 = ( V_127 - V_29 ) * sizeof *V_29 ;
memmove ( V_29 , V_29 + 1 , V_18 ) ;
V_127 -> V_30 = NULL ;
F_58 ( V_30 ) ;
}
static struct V_8 *
F_69 ( struct V_8 * V_16 )
{
struct V_8 * V_128 ;
struct V_1 * V_3 ;
V_128 = F_34 ( V_16 -> V_24 -> V_10 ) ;
if ( ! V_128 )
return NULL ;
if ( V_128 -> V_24 == V_16 -> V_24 ) {
F_28 ( V_128 ) ;
return NULL ;
}
V_3 = V_128 -> V_3 ;
V_128 -> V_3 = V_16 -> V_3 ;
V_128 -> V_58 = V_16 -> V_58 ;
V_128 -> V_59 = V_16 -> V_59 ;
V_128 -> V_92 = 0 ;
V_128 -> V_93 = V_16 -> V_93 ;
V_128 -> V_111 = V_16 -> V_111 ;
V_128 -> V_112 = V_16 -> V_112 ;
V_16 -> V_3 = V_3 ;
return V_128 ;
}
static void
F_70 ( struct V_23 * V_24 )
{
struct V_9 * V_10 ;
struct V_8 * V_16 ;
struct V_1 * V_3 ;
struct V_107 V_108 ;
T_5 V_18 , V_129 ;
int V_84 ;
V_10 = V_24 -> V_10 ;
V_16 = F_30 ( V_10 , V_24 ) ;
if ( ! V_16 ) {
F_71 ( L_6 ,
L_7 ,
V_24 -> V_33 ,
( long ) V_10 -> V_37 , V_10 -> V_39 ,
L_8 ) ;
return;
}
V_16 -> V_61 |= V_119 ;
F_19 ( V_24 ) ;
V_16 -> V_59 . V_95 = V_24 -> V_10 -> V_130 ? V_24 -> V_10 -> V_130 : V_131 ;
F_41 ( V_16 ) ;
V_3 = V_16 -> V_3 ;
for ( V_84 = 0 , V_18 = V_16 -> V_59 . V_95 ; V_18 > 0 ; ++ V_84 , V_18 -= V_129 ) {
if ( V_18 < V_132 )
V_129 = V_18 ;
else
V_129 = V_132 ;
F_38 ( V_3 , V_84 , V_133 , 0 , V_129 ) ;
}
V_3 -> V_2 += V_16 -> V_59 . V_95 ;
V_3 -> V_67 = V_16 -> V_59 . V_95 ;
V_3 -> V_66 += V_16 -> V_59 . V_95 ;
V_3 = F_49 ( V_16 -> V_3 , V_5 ) ;
if ( V_3 ) {
F_50 ( & V_16 -> V_111 ) ;
V_16 -> V_112 = ( T_2 ) V_21 ;
F_51 ( & V_108 ) ;
F_21 ( & V_108 , V_3 ) ;
F_52 ( & V_108 ) ;
}
}
static long
F_72 ( struct V_9 * V_10 )
{
long V_24 ;
V_24 = 2 * V_10 -> V_134 >> V_135 ;
V_24 += 8 * V_10 -> V_136 >> V_137 ;
if ( V_24 == 0 )
V_24 = 1 ;
return V_24 ;
}
static void
F_73 ( struct V_9 * V_10 )
{
struct V_23 * V_24 ;
struct V_8 * V_16 ;
struct V_8 * V_128 ;
struct V_12 * V_14 , * V_15 , * V_13 ;
int V_138 ;
int V_139 ;
F_74 ( V_10 , & V_139 ) ;
V_13 = & V_10 -> V_17 ;
F_9 (pos, nx, head) {
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
V_24 = V_16 -> V_24 ;
if ( V_24 -> V_77 ) {
if ( ! ( V_16 -> V_61 & V_119 ) ) {
V_128 = F_69 ( V_16 ) ;
if ( V_128 ) {
if ( V_24 -> V_140 == 0
&& V_139 > 0 ) {
F_70 ( V_24 ) ;
V_24 -> V_140 ++ ;
}
F_75 ( & V_16 -> V_13 , & V_128 -> V_13 ) ;
V_14 = & V_128 -> V_13 ;
F_28 ( V_16 ) ;
V_16 = V_128 ;
V_24 = V_16 -> V_24 ;
}
} else if ( V_139 < 1 ) {
goto V_141;
} else if ( F_64 ( V_16 ) < V_24 -> V_77 * F_72 ( V_10 ) ) {
continue;
}
} else if ( V_16 -> V_61 & V_119 ) {
V_141:
F_11 ( V_14 ) ;
F_28 ( V_16 ) ;
V_16 -> V_24 -> V_10 -> V_61 |= V_81 ;
continue;
}
if ( V_24 -> V_78 >= V_24 -> V_79 )
continue;
F_11 ( V_14 ) ;
V_24 -> V_78 ++ ;
if ( V_16 -> V_61 & V_119 )
V_24 -> V_140 ++ ;
V_138 = F_64 ( V_16 ) ;
V_16 -> V_92 += V_138 ;
V_16 -> V_93 += V_138 ;
F_60 ( V_10 , V_16 ) ;
}
}
static void
F_76 ( struct V_23 * V_24 )
{
int V_18 ;
V_18 = V_24 -> V_77 ++ ;
V_24 -> V_77 += V_24 -> V_77 * 2 ;
if ( V_18 > V_24 -> V_77 )
V_24 -> V_77 = V_18 ;
if ( V_24 -> V_77 > V_142 )
V_24 -> V_77 = V_142 ;
}
static int
F_74 ( struct V_9 * V_10 , int * V_139 )
{
int V_143 , V_144 ;
for ( V_143 = V_144 = 0 ; V_143 < V_10 -> V_76 && V_10 -> V_73 [ V_143 ] ; ++ V_143 )
if ( V_10 -> V_73 [ V_143 ] -> V_77 == 0 )
V_144 ++ ;
if ( V_139 )
* V_139 = V_144 ;
return V_143 ;
}
static void
F_77 ( T_1 V_145 )
{
struct V_9 * V_10 ;
struct V_23 * V_24 ;
struct V_51 * V_29 ;
struct V_8 * V_16 ;
struct V_12 * V_13 , * V_14 , * V_15 ;
F_78 ( V_146 ) ;
register long V_147 ;
T_1 V_61 , V_18 ;
int V_143 ;
int V_148 ;
int V_138 ;
V_10 = (struct V_9 * ) V_145 ;
F_79 ( & V_10 -> V_149 , V_61 ) ;
V_147 = F_72 ( V_10 ) ;
V_148 = F_74 ( V_10 , NULL ) ;
if ( V_10 -> V_61 & V_150 ) {
F_80 ( & V_10 -> V_149 , V_61 ) ;
return;
}
for ( V_143 = 0 ; V_143 < V_19 ; V_143 ++ ) {
V_13 = & V_10 -> V_20 [ V_143 ] ;
F_9 (pos, nx, head) {
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
if ( F_64 ( V_16 ) < V_147 )
break;
F_81 ( V_14 , & V_146 ) ;
}
}
while ( ! F_31 ( & V_146 ) ) {
V_14 = V_146 . V_64 ;
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
V_138 = F_64 ( V_16 ) ;
V_18 = V_16 -> V_93 + V_138 ;
V_18 /= V_124 ;
if ( V_151
&& V_18 > V_151
&& ! ( V_16 -> V_61 & V_119 ) ) {
F_82 ( & V_146 , & V_10 -> V_20 [ 0 ] ) ;
F_83 ( V_10 ) ;
goto V_152;
}
V_24 = V_16 -> V_24 ;
V_18 = V_16 -> V_92 + V_138 ;
V_18 /= V_124 ;
if ( V_151 && V_148 > 0
&& ( V_18 > V_151 / V_148 || V_18 > V_153 ) )
F_76 ( V_24 ) ;
if ( V_24 -> V_79 != 1 ) {
V_24 -> V_154 = V_24 -> V_79 / 2 ;
V_24 -> V_79 = 1 ;
}
if ( V_16 -> V_61 & V_119 ) {
V_24 -> V_140 -- ;
} else {
V_29 = F_67 ( V_24 , V_16 -> V_3 -> V_106 ) ;
if ( V_29 && ++ V_29 -> V_155 > ( V_24 -> V_156 << 1 )
&& ( V_29 != V_24 -> V_52 || V_24 -> V_52 [ 1 ] . V_30 ) ) {
F_68 ( V_24 , V_29 ) ;
V_29 = NULL ;
}
}
F_81 ( V_14 , & V_10 -> V_17 ) ;
V_24 -> V_78 -- ;
}
F_73 ( V_10 ) ;
V_152:
if ( ( V_10 -> V_61 & V_81 ) && V_10 -> V_157 ) {
V_10 -> V_61 &= ~ V_81 ;
V_10 -> V_157 -> V_158 ( V_10 -> V_157 ) ;
}
V_10 -> V_159 . V_160 = V_21 + V_161 ;
F_84 ( & V_10 -> V_159 ) ;
F_80 ( & V_10 -> V_149 , V_61 ) ;
}
static unsigned long
F_85 ( struct V_162 * V_163 )
{
struct V_82 * V_82 ;
unsigned long V_18 = 0 ;
F_86 (bio, r)
V_18 ++ ;
return V_18 ;
}
static void
F_87 ( struct V_82 * V_82 )
{
struct V_85 V_86 ;
struct V_164 * V_164 ;
struct V_83 V_59 ;
F_88 (bv, bio, iter) {
V_164 = F_89 ( V_86 . V_87 ) ;
F_90 ( & V_164 -> V_165 ) ;
}
}
static void
F_91 ( struct V_82 * V_82 )
{
struct V_164 * V_164 ;
struct V_85 V_86 ;
struct V_83 V_59 ;
F_88 (bv, bio, iter) {
V_164 = F_89 ( V_86 . V_87 ) ;
F_92 ( & V_164 -> V_165 ) ;
}
}
static void
F_93 ( struct V_58 * V_58 , struct V_162 * V_166 , struct V_82 * V_82 )
{
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_166 = V_166 ;
V_58 -> V_82 = V_82 ;
V_58 -> V_59 = V_82 -> V_167 ;
F_87 ( V_82 ) ;
}
static struct V_58 *
F_46 ( struct V_9 * V_10 )
{
struct V_162 * V_166 ;
struct V_168 * V_169 ;
struct V_58 * V_58 ;
struct V_82 * V_82 ;
V_169 = V_10 -> V_157 ;
if ( V_169 == NULL )
return NULL ;
if ( V_10 -> V_109 . V_58 )
return V_10 -> V_109 . V_58 ;
V_166 = V_10 -> V_109 . V_166 ;
if ( V_166 == NULL ) {
V_166 = F_94 ( V_169 ) ;
if ( V_166 == NULL )
return NULL ;
F_95 ( V_166 ) ;
V_10 -> V_109 . V_166 = V_166 ;
V_10 -> V_109 . V_170 = V_166 -> V_82 ;
V_166 -> V_171 = ( void * ) F_85 ( V_166 ) ;
}
V_58 = F_96 ( V_10 -> V_172 , V_5 ) ;
if ( V_58 == NULL ) {
F_71 ( L_9 ) ;
return NULL ;
}
V_82 = V_10 -> V_109 . V_170 ;
F_93 ( V_58 , V_166 , V_82 ) ;
V_82 = V_82 -> V_173 ;
V_10 -> V_109 . V_170 = V_82 ;
if ( V_82 == NULL )
V_10 -> V_109 . V_166 = NULL ;
return V_10 -> V_109 . V_58 = V_58 ;
}
void
F_97 ( struct V_9 * V_10 )
{
F_73 ( V_10 ) ;
while ( F_45 ( V_10 ) )
;
}
void
F_98 ( struct V_174 * V_175 )
{
struct V_9 * V_10 = F_99 ( V_175 , struct V_9 , V_175 ) ;
struct V_176 * V_177 ;
T_6 V_178 ;
if ( V_10 -> V_61 & V_179 )
F_100 ( V_10 ) ;
if ( V_10 -> V_61 & V_180 ) {
V_178 = F_101 ( V_10 -> V_181 ) ;
V_177 = F_102 ( V_10 -> V_181 , 0 ) ;
if ( V_177 ) {
F_103 ( & V_177 -> V_182 -> V_183 ) ;
F_104 ( V_177 -> V_182 , ( V_184 ) V_178 << 9 ) ;
F_105 ( & V_177 -> V_182 -> V_183 ) ;
F_106 ( V_177 ) ;
}
F_107 ( & V_10 -> V_149 ) ;
V_10 -> V_61 |= V_185 ;
V_10 -> V_61 &= ~ V_180 ;
F_108 ( & V_10 -> V_149 ) ;
}
}
static void
F_109 ( T_7 * V_186 , int V_187 )
{
T_7 V_188 ;
while ( V_187 -- > 0 ) {
V_188 = * V_186 ;
* V_186 ++ = V_188 >> 8 | V_188 << 8 ;
}
}
static void
F_110 ( struct V_9 * V_10 , struct V_23 * V_24 , unsigned char * V_186 )
{
T_6 V_178 ;
T_7 V_18 ;
V_18 = F_111 ( & V_186 [ 83 << 1 ] ) ;
V_18 |= F_111 ( & V_186 [ 86 << 1 ] ) ;
if ( V_18 & ( 1 << 10 ) ) {
V_10 -> V_61 |= V_97 ;
V_178 = F_112 ( & V_186 [ 100 << 1 ] ) ;
V_10 -> V_189 . V_190 = V_178 ;
V_10 -> V_189 . V_190 /= ( 255 * 63 ) ;
V_10 -> V_189 . V_191 = 255 ;
V_10 -> V_189 . V_192 = 63 ;
} else {
V_10 -> V_61 &= ~ V_97 ;
V_178 = F_113 ( & V_186 [ 60 << 1 ] ) ;
V_10 -> V_189 . V_190 = F_111 ( & V_186 [ 54 << 1 ] ) ;
V_10 -> V_189 . V_191 = F_111 ( & V_186 [ 55 << 1 ] ) ;
V_10 -> V_189 . V_192 = F_111 ( & V_186 [ 56 << 1 ] ) ;
}
F_109 ( ( T_7 * ) & V_186 [ 10 << 1 ] , 10 ) ;
F_109 ( ( T_7 * ) & V_186 [ 23 << 1 ] , 4 ) ;
F_109 ( ( T_7 * ) & V_186 [ 27 << 1 ] , 20 ) ;
memcpy ( V_10 -> V_193 , V_186 , sizeof( V_10 -> V_193 ) ) ;
if ( V_10 -> V_178 != V_178 )
F_35 ( V_117
L_10 ,
V_24 -> V_33 ,
V_10 -> V_37 , V_10 -> V_39 ,
V_10 -> V_194 , ( long long ) V_178 ) ;
V_10 -> V_178 = V_178 ;
V_10 -> V_189 . V_195 = 0 ;
if ( V_10 -> V_61 & ( V_179 | V_180 ) )
return;
if ( V_10 -> V_181 != NULL ) {
F_114 ( V_10 -> V_181 , V_178 ) ;
V_10 -> V_61 |= V_180 ;
} else
V_10 -> V_61 |= V_179 ;
F_115 ( & V_10 -> V_175 ) ;
}
static void
F_116 ( struct V_9 * V_10 , struct V_23 * V_24 , int V_196 )
{
register long V_18 ;
V_18 = V_196 ;
V_18 -= V_10 -> V_134 >> V_135 ;
V_10 -> V_134 += V_18 ;
if ( V_18 < 0 )
V_18 = - V_18 ;
V_18 -= V_10 -> V_136 >> V_137 ;
V_10 -> V_136 += V_18 ;
if ( ! V_24 || V_24 -> V_79 >= V_24 -> V_156 )
return;
if ( V_24 -> V_79 < V_24 -> V_154 )
V_24 -> V_79 += 1 ;
else if ( V_24 -> V_78 == V_24 -> V_79 && V_24 -> V_197 -- == 0 ) {
V_24 -> V_79 += 1 ;
V_24 -> V_197 = V_24 -> V_79 ;
}
}
static struct V_23 *
F_117 ( struct V_9 * V_10 , char * V_33 )
{
struct V_23 * * V_24 , * * V_127 ;
V_24 = V_10 -> V_73 ;
V_127 = V_24 + V_10 -> V_76 ;
for (; V_24 < V_127 && * V_24 ; V_24 ++ )
if ( memcmp ( ( * V_24 ) -> V_33 , V_33 , sizeof( ( * V_24 ) -> V_33 ) ) == 0 )
return * V_24 ;
return NULL ;
}
static void
F_118 ( struct V_1 * V_3 , struct V_82 * V_82 , struct V_83 V_59 , long V_198 )
{
int V_199 = 0 ;
struct V_85 V_86 ;
V_59 . V_95 = V_198 ;
F_37 (bv, bio, iter, iter) {
char * V_126 = F_119 ( V_86 . V_87 ) + V_86 . V_88 ;
F_120 ( V_3 , V_199 , V_126 , V_86 . V_89 ) ;
V_199 += V_86 . V_89 ;
}
}
void
F_121 ( struct V_9 * V_10 , struct V_162 * V_166 , int V_200 )
{
struct V_82 * V_82 ;
int V_201 ;
struct V_168 * V_169 ;
V_169 = V_10 -> V_157 ;
if ( V_166 == V_10 -> V_109 . V_166 )
V_10 -> V_109 . V_166 = NULL ;
do {
V_82 = V_166 -> V_82 ;
V_201 = ! V_200 && ! V_82 -> V_202 ;
} while ( F_122 ( V_166 , V_201 ? 0 : - V_203 , V_82 -> V_167 . V_95 ) );
if ( ! V_200 )
F_123 ( V_169 ) ;
}
static void
F_124 ( struct V_9 * V_10 , struct V_58 * V_58 )
{
struct V_162 * V_166 ;
unsigned long V_18 ;
if ( V_58 == V_10 -> V_109 . V_58 )
V_10 -> V_109 . V_58 = NULL ;
V_166 = V_58 -> V_166 ;
F_91 ( V_58 -> V_82 ) ;
F_125 ( V_58 , V_10 -> V_172 ) ;
V_18 = ( unsigned long ) V_166 -> V_171 ;
V_166 -> V_171 = ( void * ) -- V_18 ;
if ( V_18 == 0 )
F_121 ( V_10 , V_166 , 0 ) ;
}
static void
F_126 ( struct V_8 * V_16 )
{
struct V_25 * V_204 , * V_205 ;
struct V_42 * V_206 , * V_207 ;
struct V_58 * V_58 ;
struct V_1 * V_3 ;
struct V_23 * V_24 ;
struct V_51 * V_29 ;
struct V_9 * V_10 ;
long V_18 ;
int V_139 ;
if ( V_16 == NULL )
return;
V_24 = V_16 -> V_24 ;
V_10 = V_24 -> V_10 ;
V_3 = V_16 -> V_60 ;
V_58 = V_16 -> V_58 ;
if ( V_16 -> V_61 & V_119 )
goto V_152;
if ( ! V_3 )
goto V_208;
V_205 = (struct V_25 * ) F_42 ( V_16 -> V_3 ) ;
V_207 = (struct V_42 * ) ( V_205 + 1 ) ;
V_204 = (struct V_25 * ) V_3 -> V_209 ;
F_127 ( V_3 , sizeof( * V_204 ) ) ;
V_206 = (struct V_42 * ) V_3 -> V_209 ;
F_127 ( V_3 , sizeof( * V_206 ) ) ;
if ( V_206 -> V_104 & 0xa9 ) {
F_71 ( L_11 ,
V_207 -> V_104 , V_206 -> V_104 ,
V_10 -> V_37 , V_10 -> V_39 ) ;
V_208: if ( V_58 )
V_58 -> V_82 -> V_202 = - V_203 ;
goto V_152;
}
V_18 = V_207 -> V_94 << 9 ;
switch ( V_207 -> V_104 ) {
case V_105 :
case V_210 :
if ( V_3 -> V_2 < V_18 ) {
F_71 ( L_12 ,
L_13 ,
( long ) V_10 -> V_37 , V_10 -> V_39 ,
V_3 -> V_2 , V_18 ) ;
V_58 -> V_82 -> V_202 = - V_203 ;
break;
}
if ( V_18 > V_16 -> V_59 . V_95 ) {
F_128 ( L_14 ,
L_15 ,
( long ) V_10 -> V_37 , V_10 -> V_39 ,
V_18 , V_16 -> V_59 . V_95 ) ;
V_58 -> V_82 -> V_202 = - V_203 ;
break;
}
F_118 ( V_3 , V_16 -> V_58 -> V_82 , V_16 -> V_59 , V_18 ) ;
case V_211 :
case V_212 :
F_107 ( & V_10 -> V_149 ) ;
V_29 = F_67 ( V_24 , V_3 -> V_106 ) ;
if ( V_29 )
V_29 -> V_155 = 0 ;
F_108 ( & V_10 -> V_149 ) ;
break;
case V_213 :
if ( V_3 -> V_2 < 512 ) {
F_61 ( L_16 ,
L_17 ,
( long ) V_10 -> V_37 , V_10 -> V_39 ,
V_3 -> V_2 ) ;
break;
}
if ( F_129 ( V_3 ) )
break;
F_107 ( & V_10 -> V_149 ) ;
F_110 ( V_10 , V_24 , V_3 -> V_209 ) ;
F_108 ( & V_10 -> V_149 ) ;
break;
default:
F_61 ( L_18 ,
V_207 -> V_104 ,
F_130 ( F_131 ( & V_204 -> V_36 ) ) ,
V_204 -> V_38 ) ;
}
V_152:
F_107 ( & V_10 -> V_149 ) ;
if ( V_24 -> V_77 > 0
&& -- V_24 -> V_77 > 0
&& V_24 -> V_140 == 0 ) {
F_74 ( V_10 , & V_139 ) ;
if ( V_139 > 0 ) {
F_70 ( V_24 ) ;
V_24 -> V_140 ++ ;
}
}
F_28 ( V_16 ) ;
if ( V_58 && -- V_58 -> V_110 == 0 && V_58 -> V_59 . V_95 == 0 )
F_124 ( V_10 , V_58 ) ;
F_108 ( & V_10 -> V_149 ) ;
F_132 ( V_10 ) ;
F_133 ( V_3 ) ;
}
static int
F_134 ( int V_186 )
{
struct V_8 * V_16 ;
struct V_12 * V_14 ;
int V_143 ;
int V_214 ;
for ( V_143 = 0 ; ; ++ V_143 ) {
if ( V_143 == V_215 )
return 1 ;
if ( F_31 ( & V_216 [ V_186 ] . V_13 ) )
return 0 ;
V_14 = V_216 [ V_186 ] . V_13 . V_64 ;
F_11 ( V_14 ) ;
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
F_108 ( & V_216 [ V_186 ] . V_149 ) ;
F_126 ( V_16 ) ;
V_214 = V_16 -> V_24 -> V_10 -> V_39 % V_217 ;
if ( ! V_218 [ V_214 ] . V_219 ) {
F_135 ( V_186 != 0 ) ;
F_103 ( & V_220 ) ;
if ( ! V_218 [ V_214 ] . V_219
&& F_136 ( & V_218 [ V_214 ] ) == 0 )
V_218 [ V_214 ] . V_219 = 1 ;
F_105 ( & V_220 ) ;
}
F_107 ( & V_216 [ V_186 ] . V_149 ) ;
}
}
static int
F_137 ( void * V_145 )
{
struct V_221 * V_222 ;
F_138 ( V_223 , V_224 ) ;
int V_225 ;
V_222 = V_145 ;
V_224 -> V_61 |= V_226 ;
F_139 ( V_224 , - 10 ) ;
F_140 ( & V_222 -> V_227 ) ;
do {
F_107 ( V_222 -> V_149 ) ;
V_225 = V_222 -> V_228 ( V_222 -> V_186 ) ;
if ( ! V_225 ) {
F_141 ( V_222 -> V_229 , & V_223 ) ;
F_142 ( V_230 ) ;
}
F_108 ( V_222 -> V_149 ) ;
if ( ! V_225 ) {
F_143 () ;
F_144 ( V_222 -> V_229 , & V_223 ) ;
} else
F_145 () ;
} while ( ! F_146 () );
F_140 ( & V_222 -> V_227 ) ;
return 0 ;
}
void
F_147 ( struct V_221 * V_222 )
{
F_148 ( V_222 -> V_231 ) ;
F_149 ( & V_222 -> V_227 ) ;
}
int
F_136 ( struct V_221 * V_222 )
{
struct V_232 * V_231 ;
F_150 ( & V_222 -> V_227 ) ;
V_231 = F_151 ( F_137 , V_222 , L_19 , V_222 -> V_233 ) ;
if ( V_231 == NULL || F_152 ( V_231 ) )
return - V_234 ;
V_222 -> V_231 = V_231 ;
F_149 ( & V_222 -> V_227 ) ;
F_150 ( & V_222 -> V_227 ) ;
return 0 ;
}
static void
F_62 ( struct V_8 * V_16 , struct V_1 * V_3 )
{
int V_186 ;
T_1 V_61 ;
V_16 -> V_60 = V_3 ;
V_186 = V_16 -> V_24 -> V_10 -> V_39 % V_217 ;
F_79 ( & V_216 [ V_186 ] . V_149 , V_61 ) ;
if ( ! V_218 [ V_186 ] . V_219 ) {
F_80 ( & V_216 [ V_186 ] . V_149 , V_61 ) ;
V_186 = 0 ;
F_79 ( & V_216 [ V_186 ] . V_149 , V_61 ) ;
}
F_40 ( & V_16 -> V_13 , & V_216 [ V_186 ] . V_13 ) ;
F_80 ( & V_216 [ V_186 ] . V_149 , V_61 ) ;
F_153 ( & V_235 [ V_186 ] ) ;
}
struct V_1 *
F_154 ( struct V_1 * V_3 )
{
struct V_9 * V_10 ;
struct V_25 * V_26 ;
struct V_8 * V_16 ;
T_2 V_18 ;
T_1 V_61 ;
char V_236 [ 128 ] ;
T_7 V_37 ;
V_26 = (struct V_25 * ) V_3 -> V_209 ;
V_37 = F_130 ( F_131 ( & V_26 -> V_36 ) ) ;
V_10 = F_155 ( V_37 , V_26 -> V_38 , 0 ) ;
if ( V_10 == NULL ) {
snprintf ( V_236 , sizeof V_236 , L_20
L_21 ,
V_37 , V_26 -> V_38 ) ;
F_63 ( V_236 ) ;
return V_3 ;
}
F_79 ( & V_10 -> V_149 , V_61 ) ;
V_18 = F_156 ( F_131 ( & V_26 -> V_11 ) ) ;
V_16 = F_12 ( V_10 , V_18 ) ;
if ( V_16 ) {
F_116 ( V_10 , V_16 -> V_24 , F_64 ( V_16 ) ) ;
V_16 -> V_24 -> V_78 -- ;
if ( V_16 -> V_61 & V_119 )
V_16 -> V_24 -> V_140 -- ;
} else {
V_16 = F_8 ( V_10 , V_18 ) ;
if ( V_16 ) {
F_116 ( V_10 , NULL , F_64 ( V_16 ) ) ;
} else {
F_116 ( V_10 , NULL , F_65 ( V_18 ) ) ;
F_80 ( & V_10 -> V_149 , V_61 ) ;
F_132 ( V_10 ) ;
snprintf ( V_236 , sizeof( V_236 ) ,
L_22 ,
L_23 ,
F_157 ( & V_26 -> V_36 ) ,
V_26 -> V_38 ,
F_158 ( & V_26 -> V_11 ) ,
V_21 ,
V_26 -> V_28 ,
V_26 -> V_32 ) ;
F_63 ( V_236 ) ;
return V_3 ;
}
}
F_97 ( V_10 ) ;
F_80 ( & V_10 -> V_149 , V_61 ) ;
F_62 ( V_16 , V_3 ) ;
return NULL ;
}
void
F_159 ( T_4 V_37 , unsigned char V_39 )
{
struct V_107 V_108 ;
F_51 ( & V_108 ) ;
F_53 ( V_37 , V_39 , & V_108 ) ;
F_52 ( & V_108 ) ;
}
struct V_1 *
F_160 ( struct V_9 * V_10 )
{
struct V_25 * V_26 ;
struct V_42 * V_43 ;
struct V_8 * V_16 ;
struct V_1 * V_3 ;
struct V_23 * V_24 ;
V_16 = F_34 ( V_10 ) ;
if ( V_16 == NULL )
return NULL ;
V_24 = * V_10 -> V_75 ;
V_3 = V_16 -> V_3 ;
V_26 = (struct V_25 * ) F_42 ( V_3 ) ;
V_43 = (struct V_42 * ) ( V_26 + 1 ) ;
F_43 ( V_3 , sizeof *V_26 + sizeof *V_43 ) ;
memset ( V_26 , 0 , V_3 -> V_2 ) ;
V_16 -> V_11 = F_14 ( V_10 , V_24 , V_26 ) ;
F_39 ( V_16 ) ;
V_24 -> V_78 ++ ;
V_16 -> V_92 = 0 ;
V_16 -> V_93 = 0 ;
V_43 -> V_94 = 1 ;
V_43 -> V_104 = V_213 ;
V_43 -> V_48 = 0xa0 ;
V_3 -> V_106 = V_24 -> V_29 -> V_30 ;
V_10 -> V_134 = V_237 ;
V_10 -> V_136 = V_238 ;
V_10 -> V_159 . V_239 = F_77 ;
V_3 = F_49 ( V_3 , V_5 ) ;
if ( V_3 ) {
F_50 ( & V_16 -> V_111 ) ;
V_16 -> V_112 = ( T_2 ) V_21 ;
}
return V_3 ;
}
static struct V_23 * *
F_161 ( struct V_9 * V_10 )
{
T_1 V_240 , V_241 ;
struct V_23 * * V_69 ;
V_240 = V_10 -> V_76 ;
V_241 = V_240 * 2 ;
V_69 = F_32 ( V_241 , sizeof( * V_10 -> V_73 ) , V_5 ) ;
if ( ! V_69 )
return NULL ;
memmove ( V_69 , V_10 -> V_73 , sizeof( * V_10 -> V_73 ) * V_240 ) ;
V_10 -> V_75 = V_69 + ( V_10 -> V_75 - V_10 -> V_73 ) ;
F_162 ( V_10 -> V_73 ) ;
V_10 -> V_73 = V_69 ;
V_10 -> V_76 = V_241 ;
return & V_10 -> V_73 [ V_240 ] ;
}
static struct V_23 *
F_163 ( struct V_9 * V_10 , char * V_33 , T_1 V_156 )
{
struct V_23 * V_24 , * * V_69 , * * V_242 ;
V_69 = V_10 -> V_73 ;
V_242 = V_69 + V_10 -> V_76 ;
for (; V_69 < V_242 && * V_69 ; V_69 ++ )
;
if ( V_69 == V_242 ) {
V_69 = F_161 ( V_10 ) ;
if ( ! V_69 )
goto V_243;
}
V_24 = F_164 ( sizeof( * V_24 ) , V_5 ) ;
if ( ! V_24 )
goto V_243;
V_24 -> V_156 = V_156 ;
V_24 -> V_10 = V_10 ;
memcpy ( V_24 -> V_33 , V_33 , sizeof V_24 -> V_33 ) ;
V_24 -> V_29 = V_24 -> V_52 ;
F_165 ( V_24 ) ;
V_24 -> V_79 = V_24 -> V_156 / 2 ;
F_166 ( & V_24 -> V_62 ) ;
return * V_69 = V_24 ;
V_243:
F_61 ( L_24 ) ;
return NULL ;
}
static void
F_167 ( struct V_9 * V_10 )
{
struct V_23 * * V_24 , * * V_127 ;
int V_244 = 0 ;
V_24 = V_10 -> V_73 ;
V_127 = V_24 + V_10 -> V_76 ;
for (; V_24 < V_127 && * V_24 ; V_24 ++ )
if ( V_244 == 0 || V_244 > ( * V_24 ) -> V_245 )
V_244 = ( * V_24 ) -> V_245 ;
if ( V_244 != V_10 -> V_130 ) {
V_10 -> V_130 = V_244 ;
F_61 ( L_25 ,
V_10 -> V_37 , V_10 -> V_39 , V_244 ) ;
}
}
static void
F_168 ( struct V_23 * V_24 , struct V_115 * V_30 , int V_244 )
{
struct V_9 * V_10 ;
struct V_51 * V_126 , * V_127 ;
int V_245 ;
V_10 = V_24 -> V_10 ;
V_245 = V_244 ;
V_126 = V_24 -> V_52 ;
V_127 = V_126 + V_53 ;
for (; V_126 < V_127 ; V_126 ++ ) {
if ( V_126 -> V_30 == NULL )
break;
if ( V_126 -> V_30 == V_30 ) {
V_126 -> V_244 = V_244 ;
V_30 = NULL ;
} else if ( V_245 > V_126 -> V_244 )
V_245 = V_126 -> V_244 ;
}
if ( V_30 ) {
if ( V_126 == V_127 ) {
F_71 ( L_26 ) ;
return;
}
F_56 ( V_30 ) ;
V_126 -> V_30 = V_30 ;
V_126 -> V_244 = V_244 ;
}
V_24 -> V_245 = V_245 ;
F_167 ( V_10 ) ;
}
void
F_169 ( struct V_1 * V_3 )
{
struct V_9 * V_10 ;
struct V_25 * V_26 ;
struct V_113 * V_114 ;
struct V_23 * V_24 ;
T_1 V_61 , V_37 ;
struct V_1 * V_246 ;
struct V_107 V_108 ;
T_7 V_18 ;
V_246 = NULL ;
V_26 = (struct V_25 * ) F_42 ( V_3 ) ;
V_114 = (struct V_113 * ) ( V_26 + 1 ) ;
V_37 = F_157 ( & V_26 -> V_36 ) ;
if ( V_37 == 0xfff ) {
F_35 ( V_74 L_27
L_28 ) ;
return;
}
if ( V_37 == 0xffff ) {
F_61 ( L_29 ,
V_37 , ( int ) V_26 -> V_38 ) ;
return;
}
if ( V_26 -> V_38 == 0xff ) {
F_61 ( L_30 ,
V_37 , ( int ) V_26 -> V_38 ) ;
return;
}
V_18 = F_130 ( V_114 -> V_247 ) ;
if ( V_18 > V_248 )
V_18 = V_248 ;
V_10 = F_155 ( V_37 , V_26 -> V_38 , 1 ) ;
if ( V_10 == NULL ) {
F_61 ( L_31 ) ;
return;
}
F_79 ( & V_10 -> V_149 , V_61 ) ;
V_24 = F_117 ( V_10 , V_26 -> V_28 ) ;
if ( V_24 ) {
V_24 -> V_156 = V_18 ;
if ( V_18 < V_24 -> V_79 )
F_165 ( V_24 ) ;
} else {
V_24 = F_163 ( V_10 , V_26 -> V_28 , V_18 ) ;
if ( ! V_24 )
goto V_65;
}
V_18 = V_3 -> V_106 -> V_249 ;
V_18 -= sizeof( struct V_25 ) + sizeof( struct V_42 ) ;
V_18 /= 512 ;
if ( V_18 > V_114 -> V_94 )
V_18 = V_114 -> V_94 ;
V_18 = V_18 ? V_18 * 512 : V_131 ;
F_168 ( V_24 , V_3 -> V_106 , V_18 ) ;
if ( V_10 -> V_250 == 0 ) {
V_10 -> V_194 = F_130 ( V_114 -> V_251 ) ;
V_246 = F_160 ( V_10 ) ;
}
V_65:
F_80 ( & V_10 -> V_149 , V_61 ) ;
F_132 ( V_10 ) ;
if ( V_246 ) {
F_51 ( & V_108 ) ;
F_21 ( & V_108 , V_246 ) ;
F_52 ( & V_108 ) ;
}
}
void
F_165 ( struct V_23 * V_24 )
{
V_24 -> V_79 = 1 ;
V_24 -> V_154 = V_24 -> V_156 / 2 ;
V_24 -> V_197 = V_24 -> V_156 ;
}
void
F_170 ( struct V_9 * V_10 )
{
struct V_23 * * V_24 , * * V_242 ;
V_10 -> V_134 = V_237 ;
V_10 -> V_136 = V_238 ;
V_10 -> V_130 = 0 ;
V_24 = V_10 -> V_73 ;
V_242 = V_24 + V_10 -> V_76 ;
for (; V_24 < V_242 && * V_24 ; V_24 ++ )
F_165 ( * V_24 ) ;
}
void
F_171 ( struct V_9 * V_10 , struct V_58 * V_58 )
{
if ( V_58 == NULL )
return;
V_58 -> V_59 . V_95 = 0 ;
V_58 -> V_82 -> V_202 = - V_203 ;
if ( V_58 -> V_110 == 0 )
F_124 ( V_10 , V_58 ) ;
}
void
F_172 ( void )
{
int V_143 ;
for ( V_143 = 0 ; V_143 < V_217 ; V_143 ++ ) {
if ( V_218 [ V_143 ] . V_219 )
F_173 ( V_143 ) ;
}
}
void
F_173 ( int V_186 )
{
struct V_8 * V_16 ;
struct V_9 * V_10 ;
F_78 ( V_146 ) ;
struct V_12 * V_14 ;
struct V_1 * V_3 ;
T_1 V_61 ;
F_79 ( & V_216 [ V_186 ] . V_149 , V_61 ) ;
F_174 ( & V_216 [ V_186 ] . V_13 , & V_146 ) ;
F_80 ( & V_216 [ V_186 ] . V_149 , V_61 ) ;
while ( ! F_31 ( & V_146 ) ) {
V_14 = V_146 . V_64 ;
F_11 ( V_14 ) ;
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
V_10 = V_16 -> V_24 -> V_10 ;
V_3 = V_16 -> V_60 ;
F_79 ( & V_10 -> V_149 , V_61 ) ;
if ( V_16 -> V_58 ) {
V_16 -> V_58 -> V_110 -- ;
F_171 ( V_10 , V_16 -> V_58 ) ;
}
F_28 ( V_16 ) ;
F_80 ( & V_10 -> V_149 , V_61 ) ;
F_133 ( V_3 ) ;
F_132 ( V_10 ) ;
}
}
int T_8
F_175 ( void )
{
void * V_126 ;
int V_143 ;
int V_252 ;
V_126 = ( void * ) F_176 ( V_253 | V_254 ) ;
if ( ! V_126 )
return - V_234 ;
V_133 = F_177 ( V_126 ) ;
V_217 = F_178 () ;
V_216 = F_32 ( V_217 , sizeof( struct V_255 ) , V_253 ) ;
if ( ! V_216 )
return - V_234 ;
V_218 = F_32 ( V_217 , sizeof( struct V_221 ) , V_253 ) ;
if ( ! V_218 ) {
V_252 = - V_234 ;
goto V_256;
}
V_235 = F_32 ( V_217 , sizeof( V_257 ) , V_253 ) ;
if ( ! V_235 ) {
V_252 = - V_234 ;
goto V_258;
}
F_179 ( & V_220 ) ;
for ( V_143 = 0 ; V_143 < V_217 ; V_143 ++ ) {
F_166 ( & V_216 [ V_143 ] . V_13 ) ;
F_180 ( & V_216 [ V_143 ] . V_149 ) ;
F_181 ( & V_235 [ V_143 ] ) ;
snprintf ( V_218 [ V_143 ] . V_233 , sizeof( V_218 [ V_143 ] . V_233 ) , L_32 , V_143 ) ;
V_218 [ V_143 ] . V_228 = F_134 ;
V_218 [ V_143 ] . V_229 = & V_235 [ V_143 ] ;
V_218 [ V_143 ] . V_149 = & V_216 [ V_143 ] . V_149 ;
V_218 [ V_143 ] . V_186 = V_143 ;
V_218 [ V_143 ] . V_219 = 0 ;
}
V_218 [ 0 ] . V_219 = 1 ;
if ( F_136 ( & V_218 [ 0 ] ) ) {
V_252 = - V_234 ;
goto V_259;
}
return 0 ;
V_259:
F_162 ( V_235 ) ;
V_258:
F_162 ( V_218 ) ;
V_256:
F_162 ( V_216 ) ;
return V_252 ;
}
void
F_182 ( void )
{
int V_143 ;
for ( V_143 = 0 ; V_143 < V_217 ; V_143 ++ )
if ( V_218 [ V_143 ] . V_219 )
F_147 ( & V_218 [ V_143 ] ) ;
F_172 () ;
F_162 ( V_216 ) ;
F_162 ( V_218 ) ;
F_162 ( V_235 ) ;
F_183 ( ( unsigned long ) F_119 ( V_133 ) ) ;
V_133 = NULL ;
}
