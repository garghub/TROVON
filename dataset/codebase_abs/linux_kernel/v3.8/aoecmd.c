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
struct V_11 * V_12 , * V_13 , * V_14 ;
struct V_7 * V_15 ;
V_12 = & V_9 -> V_16 ;
F_8 (pos, nx, head) {
V_15 = F_9 ( V_13 , struct V_7 , V_12 ) ;
if ( V_15 -> V_10 == V_10 ) {
F_10 ( V_13 ) ;
return V_15 ;
}
}
return NULL ;
}
static struct V_7 *
F_11 ( struct V_8 * V_9 , T_2 V_10 )
{
struct V_7 * V_15 ;
struct V_11 * V_12 , * V_13 , * V_14 ;
T_2 V_17 ;
V_17 = V_10 % V_18 ;
V_12 = & V_9 -> V_19 [ V_17 ] ;
F_8 (pos, nx, head) {
V_15 = F_9 ( V_13 , struct V_7 , V_12 ) ;
if ( V_15 -> V_10 == V_10 ) {
F_10 ( V_13 ) ;
return V_15 ;
}
}
return NULL ;
}
static int
F_12 ( struct V_8 * V_9 )
{
register T_1 V_17 ;
V_17 = V_20 & 0xffff ;
return V_17 |= ( ++ V_9 -> V_21 & 0x7fff ) << 16 ;
}
static T_2
F_13 ( struct V_8 * V_9 , struct V_22 * V_23 , struct V_24 * V_25 )
{
T_2 V_26 = F_12 ( V_9 ) ;
memcpy ( V_25 -> V_27 , V_23 -> V_28 -> V_29 -> V_30 , sizeof V_25 -> V_27 ) ;
memcpy ( V_25 -> V_31 , V_23 -> V_32 , sizeof V_25 -> V_31 ) ;
V_25 -> type = F_14 ( V_6 ) ;
V_25 -> V_33 = V_34 ;
V_25 -> V_35 = F_15 ( V_9 -> V_36 ) ;
V_25 -> V_37 = V_9 -> V_38 ;
V_25 -> V_39 = V_40 ;
V_25 -> V_10 = F_16 ( V_26 ) ;
return V_26 ;
}
static inline void
F_17 ( struct V_41 * V_42 , T_3 V_43 )
{
V_42 -> V_44 = V_43 ;
V_42 -> V_45 = V_43 >>= 8 ;
V_42 -> V_46 = V_43 >>= 8 ;
V_42 -> V_47 = V_43 >>= 8 ;
V_42 -> V_48 = V_43 >>= 8 ;
V_42 -> V_49 = V_43 >>= 8 ;
}
static struct V_50 *
F_18 ( struct V_22 * V_23 )
{
struct V_50 * V_28 ;
V_28 = V_23 -> V_28 ;
V_28 ++ ;
if ( V_28 >= & V_23 -> V_51 [ V_52 ] || V_28 -> V_29 == NULL )
V_28 = V_23 -> V_51 ;
if ( V_28 -> V_29 == NULL )
return NULL ;
return V_23 -> V_28 = V_28 ;
}
static void
F_19 ( struct V_8 * V_9 , struct V_1 * V_3 )
{
F_20 ( & V_9 -> V_53 , V_3 ) ;
}
static struct V_1 *
F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_3 = F_22 ( & V_9 -> V_53 ) ;
if ( V_3 && F_23 ( & F_24 ( V_3 ) -> V_54 ) == 1 ) {
F_25 ( V_3 , & V_9 -> V_53 ) ;
return V_3 ;
}
if ( F_26 ( & V_9 -> V_53 ) < V_55 &&
( V_3 = F_1 ( V_56 ) ) )
return V_3 ;
return NULL ;
}
void
F_27 ( struct V_7 * V_15 )
{
struct V_22 * V_23 ;
V_23 = V_15 -> V_23 ;
V_15 -> V_57 = NULL ;
V_15 -> V_43 = 0 ;
V_15 -> V_58 = NULL ;
V_15 -> V_59 = NULL ;
V_15 -> V_60 = 0 ;
F_28 ( & V_15 -> V_12 , & V_23 -> V_61 ) ;
}
static struct V_7 *
F_29 ( struct V_8 * V_9 , struct V_22 * V_23 )
{
struct V_7 * V_15 ;
struct V_1 * V_3 ;
struct V_11 * V_13 ;
if ( F_30 ( & V_23 -> V_61 ) ) {
if ( V_23 -> V_62 >= V_55 * 2 )
return NULL ;
V_15 = F_31 ( 1 , sizeof( * V_15 ) , V_4 ) ;
if ( V_15 == NULL )
return NULL ;
V_23 -> V_62 ++ ;
V_15 -> V_23 = V_23 ;
} else {
V_13 = V_23 -> V_61 . V_63 ;
F_10 ( V_13 ) ;
V_15 = F_9 ( V_13 , struct V_7 , V_12 ) ;
}
V_3 = V_15 -> V_3 ;
if ( V_3 == NULL ) {
V_15 -> V_3 = V_3 = F_1 ( V_56 ) ;
if ( ! V_3 ) {
V_64: F_27 ( V_15 ) ;
return NULL ;
}
}
if ( F_23 ( & F_24 ( V_3 ) -> V_54 ) != 1 ) {
V_3 = F_21 ( V_9 ) ;
if ( V_3 == NULL )
goto V_64;
F_19 ( V_9 , V_15 -> V_3 ) ;
V_15 -> V_3 = V_3 ;
}
V_3 -> V_65 -= V_3 -> V_66 ;
F_24 ( V_3 ) -> V_67 = V_3 -> V_66 = 0 ;
F_32 ( V_3 , 0 ) ;
return V_15 ;
}
static struct V_7 *
F_33 ( struct V_8 * V_9 )
{
struct V_7 * V_15 ;
struct V_22 * V_23 , * * V_68 ;
int V_69 = 0 ;
int V_70 ;
int V_71 ;
if ( ! V_9 -> V_72 || ! V_9 -> V_72 [ 0 ] ) {
F_34 ( V_73 L_1 ) ;
return NULL ;
}
V_68 = V_9 -> V_74 ;
for ( V_70 = 0 , V_71 = 0 ; ; ) {
V_68 ++ ;
if ( V_68 >= & V_9 -> V_72 [ V_9 -> V_75 ] || ! * V_68 )
V_68 = V_9 -> V_72 ;
V_23 = * V_68 ;
if ( ! V_23 -> V_76 ) {
V_71 = 1 ;
V_69 += V_23 -> V_77 ;
}
if ( V_23 -> V_77 < V_23 -> V_78
&& ( V_70 || ! V_23 -> V_76 )
&& V_23 -> V_28 -> V_29 ) {
V_15 = F_29 ( V_9 , V_23 ) ;
if ( V_15 ) {
F_18 ( V_23 ) ;
V_9 -> V_74 = V_68 ;
return V_15 ;
}
}
if ( V_68 == V_9 -> V_74 ) {
if ( ! V_70 && ! V_71 )
V_70 = 1 ;
else
break;
}
}
if ( V_69 == 0 ) {
V_9 -> V_79 ++ ;
V_9 -> V_60 |= V_80 ;
}
return NULL ;
}
static void
F_35 ( struct V_1 * V_3 , struct V_81 * V_58 , T_1 V_82 , T_1 V_83 )
{
int V_84 = 0 ;
T_1 V_85 ;
V_86:
V_85 = V_58 -> V_87 - ( V_82 - V_58 -> V_88 ) ;
if ( V_85 > V_83 )
V_85 = V_83 ;
F_36 ( V_3 , V_84 ++ , V_58 -> V_89 , V_82 , V_85 ) ;
V_83 -= V_85 ;
if ( V_83 <= 0 )
return;
V_58 ++ ;
V_82 = V_58 -> V_88 ;
goto V_86;
}
static void
F_37 ( struct V_7 * V_15 )
{
struct V_8 * V_9 = V_15 -> V_23 -> V_9 ;
T_2 V_17 ;
V_17 = V_15 -> V_10 % V_18 ;
F_38 ( & V_15 -> V_12 , & V_9 -> V_19 [ V_17 ] ) ;
}
static void
F_39 ( struct V_7 * V_15 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_41 * V_42 ;
struct V_1 * V_3 ;
char V_90 , V_91 ;
V_3 = V_15 -> V_3 ;
V_25 = (struct V_24 * ) F_40 ( V_3 ) ;
V_42 = (struct V_41 * ) ( V_25 + 1 ) ;
F_41 ( V_3 , sizeof( * V_25 ) + sizeof( * V_42 ) ) ;
memset ( V_25 , 0 , V_3 -> V_2 ) ;
V_90 = 0x10 ;
V_91 = 0x4 ;
V_23 = V_15 -> V_23 ;
V_15 -> V_10 = F_13 ( V_23 -> V_9 , V_23 , V_25 ) ;
F_37 ( V_15 ) ;
V_23 -> V_77 ++ ;
V_15 -> V_92 = 0 ;
V_15 -> V_93 = 0 ;
if ( V_15 -> V_57 )
V_15 -> V_43 = V_15 -> V_57 -> V_94 ;
V_42 -> V_95 = V_15 -> V_96 >> 9 ;
F_17 ( V_42 , V_15 -> V_43 ) ;
if ( V_23 -> V_9 -> V_60 & V_97 ) {
V_42 -> V_98 |= V_99 ;
} else {
V_91 = 0 ;
V_42 -> V_47 &= 0x0f ;
V_42 -> V_47 |= 0xe0 ;
}
if ( V_15 -> V_57 && F_42 ( V_15 -> V_57 -> V_100 ) == V_101 ) {
F_35 ( V_3 , V_15 -> V_58 , V_15 -> V_102 , V_15 -> V_96 ) ;
V_42 -> V_98 |= V_103 ;
V_3 -> V_2 += V_15 -> V_96 ;
V_3 -> V_66 = V_15 -> V_96 ;
V_3 -> V_65 += V_15 -> V_96 ;
V_23 -> V_104 ++ ;
} else {
V_23 -> V_105 ++ ;
V_90 = 0 ;
}
V_42 -> V_106 = V_107 | V_90 | V_91 ;
V_3 -> V_108 = V_23 -> V_28 -> V_29 ;
}
static int
F_43 ( struct V_8 * V_9 )
{
struct V_7 * V_15 ;
struct V_57 * V_57 ;
struct V_22 * V_23 ;
struct V_1 * V_3 ;
struct V_109 V_110 ;
T_1 V_96 , V_111 ;
V_57 = F_44 ( V_9 ) ;
if ( V_57 == NULL )
return 0 ;
V_15 = F_33 ( V_9 ) ;
if ( V_15 == NULL )
return 0 ;
V_23 = * V_9 -> V_74 ;
V_96 = V_9 -> V_112 ;
if ( V_96 == 0 )
V_96 = V_113 ;
if ( V_96 > V_57 -> V_114 )
V_96 = V_57 -> V_114 ;
V_111 = V_96 ;
V_15 -> V_58 = V_57 -> V_58 ;
V_15 -> V_102 = V_15 -> V_58 -> V_88 + ( V_15 -> V_58 -> V_87 - V_57 -> V_115 ) ;
do {
if ( V_111 < V_57 -> V_115 ) {
V_57 -> V_115 -= V_111 ;
V_57 -> V_114 -= V_111 ;
break;
}
V_111 -= V_57 -> V_115 ;
V_57 -> V_114 -= V_57 -> V_115 ;
if ( V_57 -> V_114 == 0 ) {
V_9 -> V_116 . V_57 = NULL ;
break;
}
V_57 -> V_58 ++ ;
V_57 -> V_115 = V_57 -> V_58 -> V_87 ;
F_45 ( V_57 -> V_115 == 0 ) ;
} while ( V_111 );
V_15 -> V_57 = V_57 ;
V_15 -> V_96 = V_96 ;
F_39 ( V_15 ) ;
V_57 -> V_117 += 1 ;
V_57 -> V_94 += V_96 >> 9 ;
V_3 = F_46 ( V_15 -> V_3 , V_4 ) ;
if ( V_3 ) {
F_47 ( & V_15 -> V_118 ) ;
V_15 -> V_119 = ( T_2 ) V_20 ;
F_48 ( & V_110 ) ;
F_20 ( & V_110 , V_3 ) ;
F_49 ( & V_110 ) ;
}
return 1 ;
}
static void
F_50 ( T_4 V_36 , unsigned char V_38 , struct V_109 * V_110 )
{
struct V_24 * V_25 ;
struct V_120 * V_121 ;
struct V_1 * V_3 ;
struct V_122 * V_28 ;
F_51 () ;
F_52 (&init_net, ifp) {
F_53 ( V_28 ) ;
if ( ! F_54 ( V_28 ) )
goto V_123;
V_3 = F_1 ( sizeof *V_25 + sizeof *V_121 ) ;
if ( V_3 == NULL ) {
F_34 ( V_124 L_2 ) ;
goto V_123;
}
F_41 ( V_3 , sizeof *V_25 + sizeof *V_121 ) ;
V_3 -> V_108 = V_28 ;
F_20 ( V_110 , V_3 ) ;
V_25 = (struct V_24 * ) F_40 ( V_3 ) ;
memset ( V_25 , 0 , sizeof *V_25 + sizeof *V_121 ) ;
memset ( V_25 -> V_31 , 0xff , sizeof V_25 -> V_31 ) ;
memcpy ( V_25 -> V_27 , V_28 -> V_30 , sizeof V_25 -> V_27 ) ;
V_25 -> type = F_14 ( V_6 ) ;
V_25 -> V_33 = V_34 ;
V_25 -> V_35 = F_15 ( V_36 ) ;
V_25 -> V_37 = V_38 ;
V_25 -> V_39 = V_125 ;
V_123:
F_55 ( V_28 ) ;
}
F_56 () ;
}
static void
F_57 ( struct V_8 * V_9 , struct V_7 * V_15 )
{
struct V_1 * V_3 ;
struct V_109 V_110 ;
struct V_24 * V_25 ;
struct V_41 * V_42 ;
struct V_22 * V_23 ;
char V_57 [ 128 ] ;
T_2 V_17 ;
V_23 = V_15 -> V_23 ;
V_17 = F_12 ( V_9 ) ;
V_3 = V_15 -> V_3 ;
if ( F_18 ( V_23 ) == NULL ) {
F_58 ( L_3 ) ;
F_59 ( V_15 , NULL ) ;
return;
}
V_25 = (struct V_24 * ) F_40 ( V_3 ) ;
V_42 = (struct V_41 * ) ( V_25 + 1 ) ;
if ( ! ( V_15 -> V_60 & V_126 ) ) {
snprintf ( V_57 , sizeof( V_57 ) ,
L_4 ,
L_5 , V_9 -> V_36 , V_9 -> V_38 ,
V_15 -> V_10 , V_20 , V_17 ,
V_25 -> V_27 , V_25 -> V_31 , V_23 -> V_77 ) ;
F_60 ( V_57 ) ;
}
V_15 -> V_10 = V_17 ;
F_37 ( V_15 ) ;
V_25 -> V_10 = F_16 ( V_17 ) ;
memcpy ( V_25 -> V_31 , V_23 -> V_32 , sizeof V_25 -> V_31 ) ;
memcpy ( V_25 -> V_27 , V_23 -> V_28 -> V_29 -> V_30 , sizeof V_25 -> V_27 ) ;
V_3 -> V_108 = V_23 -> V_28 -> V_29 ;
V_3 = F_46 ( V_3 , V_4 ) ;
if ( V_3 == NULL )
return;
F_47 ( & V_15 -> V_118 ) ;
V_15 -> V_119 = ( T_2 ) V_20 ;
F_48 ( & V_110 ) ;
F_20 ( & V_110 , V_3 ) ;
F_49 ( & V_110 ) ;
}
static int
F_61 ( struct V_7 * V_15 )
{
struct V_127 V_128 ;
int V_17 ;
F_47 ( & V_128 ) ;
V_17 = V_128 . V_129 - V_15 -> V_118 . V_129 ;
V_17 += ( V_128 . V_130 - V_15 -> V_118 . V_130 ) * V_131 ;
if ( V_17 < 0 )
V_17 = - V_17 ;
if ( V_17 > V_131 / 4 ) {
V_17 = ( ( T_2 ) V_20 ) - V_15 -> V_119 ;
V_17 *= V_131 / V_132 ;
}
return V_17 ;
}
static int
F_62 ( T_2 V_10 )
{
int V_17 ;
V_17 = V_20 & 0xffff ;
V_17 -= V_10 & 0xffff ;
if ( V_17 < 0 )
V_17 += 1 << 16 ;
return F_63 ( V_17 + 1 ) ;
}
static struct V_50 *
F_64 ( struct V_22 * V_23 , struct V_122 * V_29 )
{
struct V_50 * V_133 , * V_134 ;
V_133 = V_23 -> V_51 ;
V_134 = V_133 + V_52 ;
for (; V_133 < V_134 ; V_133 ++ )
if ( V_133 -> V_29 == V_29 )
return V_133 ;
return NULL ;
}
static void
F_65 ( struct V_22 * V_23 , struct V_50 * V_28 )
{
struct V_50 * V_134 ;
struct V_122 * V_29 ;
T_1 V_17 ;
V_29 = V_28 -> V_29 ;
V_134 = V_23 -> V_51 + V_52 - 1 ;
V_17 = ( V_134 - V_28 ) * sizeof *V_28 ;
memmove ( V_28 , V_28 + 1 , V_17 ) ;
V_134 -> V_29 = NULL ;
F_55 ( V_29 ) ;
}
static struct V_7 *
F_66 ( struct V_7 * V_15 )
{
struct V_7 * V_135 ;
struct V_1 * V_3 ;
V_135 = F_33 ( V_15 -> V_23 -> V_9 ) ;
if ( ! V_135 )
return NULL ;
if ( V_135 -> V_23 == V_15 -> V_23 ) {
F_27 ( V_135 ) ;
return NULL ;
}
V_3 = V_135 -> V_3 ;
V_135 -> V_3 = V_15 -> V_3 ;
V_135 -> V_57 = V_15 -> V_57 ;
V_135 -> V_96 = V_15 -> V_96 ;
V_135 -> V_43 = V_15 -> V_43 ;
V_135 -> V_58 = V_15 -> V_58 ;
V_135 -> V_102 = V_15 -> V_102 ;
V_135 -> V_92 = 0 ;
V_135 -> V_93 = V_15 -> V_93 ;
V_135 -> V_118 = V_15 -> V_118 ;
V_135 -> V_119 = V_15 -> V_119 ;
V_15 -> V_3 = V_3 ;
return V_135 ;
}
static void
F_67 ( struct V_22 * V_23 )
{
struct V_8 * V_9 ;
struct V_7 * V_15 ;
struct V_1 * V_3 ;
struct V_109 V_110 ;
T_5 V_17 , V_136 ;
int V_84 ;
V_9 = V_23 -> V_9 ;
V_15 = F_29 ( V_9 , V_23 ) ;
if ( ! V_15 ) {
F_68 ( L_6 ,
L_7 ,
V_23 -> V_32 ,
( long ) V_9 -> V_36 , V_9 -> V_38 ,
L_8 ) ;
return;
}
V_15 -> V_60 |= V_126 ;
F_18 ( V_23 ) ;
V_15 -> V_96 = V_23 -> V_9 -> V_112 ? V_23 -> V_9 -> V_112 : V_113 ;
F_39 ( V_15 ) ;
V_3 = V_15 -> V_3 ;
for ( V_84 = 0 , V_17 = V_15 -> V_96 ; V_17 > 0 ; ++ V_84 , V_17 -= V_136 ) {
if ( V_17 < V_137 )
V_136 = V_17 ;
else
V_136 = V_137 ;
F_36 ( V_3 , V_84 , V_138 , 0 , V_136 ) ;
}
V_3 -> V_2 += V_15 -> V_96 ;
V_3 -> V_66 = V_15 -> V_96 ;
V_3 -> V_65 += V_15 -> V_96 ;
V_3 = F_46 ( V_15 -> V_3 , V_4 ) ;
if ( V_3 ) {
F_47 ( & V_15 -> V_118 ) ;
V_15 -> V_119 = ( T_2 ) V_20 ;
F_48 ( & V_110 ) ;
F_20 ( & V_110 , V_3 ) ;
F_49 ( & V_110 ) ;
}
}
static long
F_69 ( struct V_8 * V_9 )
{
long V_23 ;
V_23 = 2 * V_9 -> V_139 >> V_140 ;
V_23 += 8 * V_9 -> V_141 >> V_142 ;
if ( V_23 == 0 )
V_23 = 1 ;
return V_23 ;
}
static void
F_70 ( struct V_8 * V_9 )
{
struct V_22 * V_23 ;
struct V_7 * V_15 ;
struct V_7 * V_135 ;
struct V_11 * V_13 , * V_14 , * V_12 ;
int V_143 ;
int V_144 ;
F_71 ( V_9 , & V_144 ) ;
V_12 = & V_9 -> V_16 ;
F_8 (pos, nx, head) {
V_15 = F_9 ( V_13 , struct V_7 , V_12 ) ;
V_23 = V_15 -> V_23 ;
if ( V_23 -> V_76 ) {
if ( ! ( V_15 -> V_60 & V_126 ) ) {
V_135 = F_66 ( V_15 ) ;
if ( V_135 ) {
if ( V_23 -> V_145 == 0
&& V_144 > 0 ) {
F_67 ( V_23 ) ;
V_23 -> V_145 ++ ;
}
F_72 ( & V_15 -> V_12 , & V_135 -> V_12 ) ;
V_13 = & V_135 -> V_12 ;
F_27 ( V_15 ) ;
V_15 = V_135 ;
V_23 = V_15 -> V_23 ;
}
} else if ( V_144 < 1 ) {
goto V_146;
} else if ( F_61 ( V_15 ) < V_23 -> V_76 * F_69 ( V_9 ) ) {
continue;
}
} else if ( V_15 -> V_60 & V_126 ) {
V_146:
F_10 ( V_13 ) ;
F_27 ( V_15 ) ;
V_15 -> V_23 -> V_9 -> V_60 |= V_80 ;
continue;
}
if ( V_23 -> V_77 >= V_23 -> V_78 )
continue;
F_10 ( V_13 ) ;
V_23 -> V_77 ++ ;
if ( V_15 -> V_60 & V_126 )
V_23 -> V_145 ++ ;
V_143 = F_61 ( V_15 ) ;
V_15 -> V_92 += V_143 ;
V_15 -> V_93 += V_143 ;
F_57 ( V_9 , V_15 ) ;
}
}
static void
F_73 ( struct V_22 * V_23 )
{
int V_17 ;
V_17 = V_23 -> V_76 ++ ;
V_23 -> V_76 += V_23 -> V_76 * 2 ;
if ( V_17 > V_23 -> V_76 )
V_23 -> V_76 = V_17 ;
if ( V_23 -> V_76 > V_147 )
V_23 -> V_76 = V_147 ;
}
static int
F_71 ( struct V_8 * V_9 , int * V_144 )
{
int V_148 , V_149 ;
for ( V_148 = V_149 = 0 ; V_148 < V_9 -> V_75 && V_9 -> V_72 [ V_148 ] ; ++ V_148 )
if ( V_9 -> V_72 [ V_148 ] -> V_76 == 0 )
V_149 ++ ;
if ( V_144 )
* V_144 = V_149 ;
return V_148 ;
}
static void
F_74 ( T_1 V_150 )
{
struct V_8 * V_9 ;
struct V_22 * V_23 ;
struct V_50 * V_28 ;
struct V_7 * V_15 ;
struct V_11 * V_12 , * V_13 , * V_14 ;
F_75 ( V_151 ) ;
register long V_152 ;
T_1 V_60 , V_17 ;
int V_148 ;
int V_153 ;
int V_143 ;
V_9 = (struct V_8 * ) V_150 ;
F_76 ( & V_9 -> V_154 , V_60 ) ;
V_152 = F_69 ( V_9 ) ;
V_153 = F_71 ( V_9 , NULL ) ;
if ( V_9 -> V_60 & V_155 ) {
F_77 ( & V_9 -> V_154 , V_60 ) ;
return;
}
for ( V_148 = 0 ; V_148 < V_18 ; V_148 ++ ) {
V_12 = & V_9 -> V_19 [ V_148 ] ;
F_8 (pos, nx, head) {
V_15 = F_9 ( V_13 , struct V_7 , V_12 ) ;
if ( F_61 ( V_15 ) < V_152 )
break;
F_78 ( V_13 , & V_151 ) ;
}
}
while ( ! F_30 ( & V_151 ) ) {
V_13 = V_151 . V_63 ;
V_15 = F_9 ( V_13 , struct V_7 , V_12 ) ;
V_143 = F_61 ( V_15 ) ;
V_17 = V_15 -> V_93 + V_143 ;
V_17 /= V_131 ;
if ( V_156
&& V_17 > V_156
&& ! ( V_15 -> V_60 & V_126 ) ) {
F_79 ( & V_151 , & V_9 -> V_19 [ 0 ] ) ;
F_80 ( V_9 ) ;
goto V_157;
}
V_23 = V_15 -> V_23 ;
V_17 = V_15 -> V_92 + V_143 ;
V_17 /= V_131 ;
if ( V_156 && V_153 > 0
&& ( V_17 > V_156 / V_153 || V_17 > V_158 ) )
F_73 ( V_23 ) ;
if ( V_23 -> V_78 != 1 ) {
V_23 -> V_159 = V_23 -> V_78 / 2 ;
V_23 -> V_78 = 1 ;
}
if ( V_15 -> V_60 & V_126 ) {
V_23 -> V_145 -- ;
} else {
V_28 = F_64 ( V_23 , V_15 -> V_3 -> V_108 ) ;
if ( V_28 && ++ V_28 -> V_160 > ( V_23 -> V_161 << 1 )
&& ( V_28 != V_23 -> V_51 || V_23 -> V_51 [ 1 ] . V_29 ) ) {
F_65 ( V_23 , V_28 ) ;
V_28 = NULL ;
}
}
F_78 ( V_13 , & V_9 -> V_16 ) ;
V_23 -> V_77 -- ;
}
F_70 ( V_9 ) ;
V_157:
if ( ( V_9 -> V_60 & V_80 ) && V_9 -> V_162 ) {
V_9 -> V_60 &= ~ V_80 ;
V_9 -> V_162 -> V_163 ( V_9 -> V_162 ) ;
}
V_9 -> V_164 . V_165 = V_20 + V_166 ;
F_81 ( & V_9 -> V_164 ) ;
F_77 ( & V_9 -> V_154 , V_60 ) ;
}
static unsigned long
F_82 ( struct V_167 * V_168 )
{
struct V_100 * V_100 ;
unsigned long V_17 = 0 ;
F_83 (bio, r)
V_17 ++ ;
return V_17 ;
}
static void
F_84 ( struct V_100 * V_100 )
{
struct V_81 * V_58 ;
struct V_169 * V_169 ;
int V_148 ;
F_85 (bv, bio, i) {
V_169 = V_58 -> V_89 ;
if ( F_86 ( F_87 ( V_169 ) ) )
if ( F_88 ( V_169 ) != V_169 ) {
F_89 ( L_9 ) ;
F_90 () ;
}
F_91 ( & V_169 -> V_170 ) ;
}
}
static void
F_92 ( struct V_100 * V_100 )
{
struct V_81 * V_58 ;
int V_148 ;
F_85 (bv, bio, i)
F_93 ( & V_58 -> V_89 -> V_170 ) ;
}
static void
F_94 ( struct V_57 * V_57 , struct V_167 * V_171 , struct V_100 * V_100 )
{
struct V_81 * V_58 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_171 = V_171 ;
V_57 -> V_100 = V_100 ;
V_57 -> V_114 = V_100 -> V_172 ;
V_57 -> V_94 = V_100 -> V_173 ;
F_84 ( V_100 ) ;
V_57 -> V_58 = V_58 = & V_100 -> V_174 [ V_100 -> V_175 ] ;
V_57 -> V_115 = V_58 -> V_87 ;
F_45 ( V_57 -> V_115 == 0 ) ;
}
static struct V_57 *
F_44 ( struct V_8 * V_9 )
{
struct V_167 * V_171 ;
struct V_176 * V_177 ;
struct V_57 * V_57 ;
struct V_100 * V_100 ;
V_177 = V_9 -> V_162 ;
if ( V_177 == NULL )
return NULL ;
if ( V_9 -> V_116 . V_57 )
return V_9 -> V_116 . V_57 ;
V_171 = V_9 -> V_116 . V_171 ;
if ( V_171 == NULL ) {
V_171 = F_95 ( V_177 ) ;
if ( V_171 == NULL )
return NULL ;
F_96 ( V_171 ) ;
V_9 -> V_116 . V_171 = V_171 ;
V_9 -> V_116 . V_178 = V_171 -> V_100 ;
V_171 -> V_179 = ( void * ) F_82 ( V_171 ) ;
}
V_57 = F_97 ( V_9 -> V_180 , V_4 ) ;
if ( V_57 == NULL ) {
F_68 ( L_10 ) ;
return NULL ;
}
V_100 = V_9 -> V_116 . V_178 ;
F_94 ( V_57 , V_171 , V_100 ) ;
V_100 = V_100 -> V_181 ;
V_9 -> V_116 . V_178 = V_100 ;
if ( V_100 == NULL )
V_9 -> V_116 . V_171 = NULL ;
return V_9 -> V_116 . V_57 = V_57 ;
}
void
F_98 ( struct V_8 * V_9 )
{
F_70 ( V_9 ) ;
while ( F_43 ( V_9 ) )
;
}
void
F_99 ( struct V_182 * V_183 )
{
struct V_8 * V_9 = F_100 ( V_183 , struct V_8 , V_183 ) ;
struct V_184 * V_185 ;
T_6 V_186 ;
if ( V_9 -> V_60 & V_187 )
F_101 ( V_9 ) ;
if ( V_9 -> V_60 & V_188 ) {
V_186 = F_102 ( V_9 -> V_189 ) ;
V_185 = F_103 ( V_9 -> V_189 , 0 ) ;
if ( V_185 ) {
F_104 ( & V_185 -> V_190 -> V_191 ) ;
F_105 ( V_185 -> V_190 , ( V_192 ) V_186 << 9 ) ;
F_106 ( & V_185 -> V_190 -> V_191 ) ;
F_107 ( V_185 ) ;
}
F_108 ( & V_9 -> V_154 ) ;
V_9 -> V_60 |= V_193 ;
V_9 -> V_60 &= ~ V_188 ;
F_109 ( & V_9 -> V_154 ) ;
}
}
static void
F_110 ( T_7 * V_194 , int V_195 )
{
T_7 V_196 ;
while ( V_195 -- > 0 ) {
V_196 = * V_194 ;
* V_194 ++ = V_196 >> 8 | V_196 << 8 ;
}
}
static void
F_111 ( struct V_8 * V_9 , struct V_22 * V_23 , unsigned char * V_194 )
{
T_6 V_186 ;
T_7 V_17 ;
V_17 = F_112 ( & V_194 [ 83 << 1 ] ) ;
V_17 |= F_112 ( & V_194 [ 86 << 1 ] ) ;
if ( V_17 & ( 1 << 10 ) ) {
V_9 -> V_60 |= V_97 ;
V_186 = F_113 ( & V_194 [ 100 << 1 ] ) ;
V_9 -> V_197 . V_198 = V_186 ;
V_9 -> V_197 . V_198 /= ( 255 * 63 ) ;
V_9 -> V_197 . V_199 = 255 ;
V_9 -> V_197 . V_200 = 63 ;
} else {
V_9 -> V_60 &= ~ V_97 ;
V_186 = F_114 ( & V_194 [ 60 << 1 ] ) ;
V_9 -> V_197 . V_198 = F_112 ( & V_194 [ 54 << 1 ] ) ;
V_9 -> V_197 . V_199 = F_112 ( & V_194 [ 55 << 1 ] ) ;
V_9 -> V_197 . V_200 = F_112 ( & V_194 [ 56 << 1 ] ) ;
}
F_110 ( ( T_7 * ) & V_194 [ 10 << 1 ] , 10 ) ;
F_110 ( ( T_7 * ) & V_194 [ 23 << 1 ] , 4 ) ;
F_110 ( ( T_7 * ) & V_194 [ 27 << 1 ] , 20 ) ;
memcpy ( V_9 -> V_201 , V_194 , sizeof( V_9 -> V_201 ) ) ;
if ( V_9 -> V_186 != V_186 )
F_34 ( V_124
L_11 ,
V_23 -> V_32 ,
V_9 -> V_36 , V_9 -> V_38 ,
V_9 -> V_202 , ( long long ) V_186 ) ;
V_9 -> V_186 = V_186 ;
V_9 -> V_197 . V_203 = 0 ;
if ( V_9 -> V_60 & ( V_187 | V_188 ) )
return;
if ( V_9 -> V_189 != NULL ) {
F_115 ( V_9 -> V_189 , V_186 ) ;
V_9 -> V_60 |= V_188 ;
} else
V_9 -> V_60 |= V_187 ;
F_116 ( & V_9 -> V_183 ) ;
}
static void
F_117 ( struct V_8 * V_9 , struct V_22 * V_23 , int V_204 )
{
register long V_17 ;
V_17 = V_204 ;
V_17 -= V_9 -> V_139 >> V_140 ;
V_9 -> V_139 += V_17 ;
if ( V_17 < 0 )
V_17 = - V_17 ;
V_17 -= V_9 -> V_141 >> V_142 ;
V_9 -> V_141 += V_17 ;
if ( ! V_23 || V_23 -> V_78 >= V_23 -> V_161 )
return;
if ( V_23 -> V_78 < V_23 -> V_159 )
V_23 -> V_78 += 1 ;
else if ( V_23 -> V_77 == V_23 -> V_78 && V_23 -> V_205 -- == 0 ) {
V_23 -> V_78 += 1 ;
V_23 -> V_205 = V_23 -> V_78 ;
}
}
static struct V_22 *
F_118 ( struct V_8 * V_9 , char * V_32 )
{
struct V_22 * * V_23 , * * V_134 ;
V_23 = V_9 -> V_72 ;
V_134 = V_23 + V_9 -> V_75 ;
for (; V_23 < V_134 && * V_23 ; V_23 ++ )
if ( memcmp ( ( * V_23 ) -> V_32 , V_32 , sizeof( ( * V_23 ) -> V_32 ) ) == 0 )
return * V_23 ;
return NULL ;
}
static void
F_119 ( struct V_81 * V_58 , T_1 V_82 , struct V_1 * V_3 , long V_83 )
{
T_1 V_85 ;
char * V_133 ;
int V_206 = 0 ;
V_86:
V_85 = V_58 -> V_87 - ( V_82 - V_58 -> V_88 ) ;
if ( V_85 > V_83 )
V_85 = V_83 ;
V_133 = F_120 ( V_58 -> V_89 ) + V_82 ;
F_121 ( V_3 , V_206 , V_133 , V_85 ) ;
V_206 += V_85 ;
V_83 -= V_85 ;
if ( V_83 <= 0 )
return;
V_58 ++ ;
V_82 = V_58 -> V_88 ;
goto V_86;
}
void
F_122 ( struct V_8 * V_9 , struct V_167 * V_171 , int V_207 )
{
struct V_100 * V_100 ;
int V_208 ;
struct V_176 * V_177 ;
V_177 = V_9 -> V_162 ;
if ( V_171 == V_9 -> V_116 . V_171 )
V_9 -> V_116 . V_171 = NULL ;
do {
V_100 = V_171 -> V_100 ;
V_208 = ! V_207 && F_123 ( V_209 , & V_100 -> V_210 ) ;
} while ( F_124 ( V_171 , V_208 ? 0 : - V_211 , V_100 -> V_172 ) );
if ( ! V_207 )
F_125 ( V_177 ) ;
}
static void
F_126 ( struct V_8 * V_9 , struct V_57 * V_57 )
{
struct V_167 * V_171 ;
unsigned long V_17 ;
if ( V_57 == V_9 -> V_116 . V_57 )
V_9 -> V_116 . V_57 = NULL ;
V_171 = V_57 -> V_171 ;
F_92 ( V_57 -> V_100 ) ;
F_127 ( V_57 , V_9 -> V_180 ) ;
V_17 = ( unsigned long ) V_171 -> V_179 ;
V_171 -> V_179 = ( void * ) -- V_17 ;
if ( V_17 == 0 )
F_122 ( V_9 , V_171 , 0 ) ;
}
static void
F_128 ( struct V_7 * V_15 )
{
struct V_24 * V_212 , * V_213 ;
struct V_41 * V_214 , * V_215 ;
struct V_57 * V_57 ;
struct V_1 * V_3 ;
struct V_22 * V_23 ;
struct V_50 * V_28 ;
struct V_8 * V_9 ;
long V_17 ;
int V_144 ;
if ( V_15 == NULL )
return;
V_23 = V_15 -> V_23 ;
V_9 = V_23 -> V_9 ;
V_3 = V_15 -> V_59 ;
V_57 = V_15 -> V_57 ;
if ( V_15 -> V_60 & V_126 )
goto V_157;
if ( ! V_3 )
goto V_216;
V_213 = (struct V_24 * ) F_40 ( V_15 -> V_3 ) ;
V_215 = (struct V_41 * ) ( V_213 + 1 ) ;
V_212 = (struct V_24 * ) V_3 -> V_217 ;
F_129 ( V_3 , sizeof( * V_212 ) ) ;
V_214 = (struct V_41 * ) V_3 -> V_217 ;
F_129 ( V_3 , sizeof( * V_214 ) ) ;
if ( V_214 -> V_106 & 0xa9 ) {
F_68 ( L_12 ,
V_215 -> V_106 , V_214 -> V_106 ,
V_9 -> V_36 , V_9 -> V_38 ) ;
V_216: if ( V_57 )
F_130 ( V_209 , & V_57 -> V_100 -> V_210 ) ;
goto V_157;
}
V_17 = V_215 -> V_95 << 9 ;
switch ( V_215 -> V_106 ) {
case V_107 :
case V_218 :
if ( V_3 -> V_2 < V_17 ) {
F_68 ( L_13 ,
L_14 ,
( long ) V_9 -> V_36 , V_9 -> V_38 ,
V_3 -> V_2 , V_17 ) ;
F_130 ( V_209 , & V_57 -> V_100 -> V_210 ) ;
break;
}
F_119 ( V_15 -> V_58 , V_15 -> V_102 , V_3 , V_17 ) ;
case V_219 :
case V_220 :
F_108 ( & V_9 -> V_154 ) ;
V_28 = F_64 ( V_23 , V_3 -> V_108 ) ;
if ( V_28 )
V_28 -> V_160 = 0 ;
F_109 ( & V_9 -> V_154 ) ;
break;
case V_221 :
if ( V_3 -> V_2 < 512 ) {
F_58 ( L_15 ,
L_16 ,
( long ) V_9 -> V_36 , V_9 -> V_38 ,
V_3 -> V_2 ) ;
break;
}
if ( F_131 ( V_3 ) )
break;
F_108 ( & V_9 -> V_154 ) ;
F_111 ( V_9 , V_23 , V_3 -> V_217 ) ;
F_109 ( & V_9 -> V_154 ) ;
break;
default:
F_58 ( L_17 ,
V_215 -> V_106 ,
F_132 ( F_133 ( & V_212 -> V_35 ) ) ,
V_212 -> V_37 ) ;
}
V_157:
F_108 ( & V_9 -> V_154 ) ;
if ( V_23 -> V_76 > 0
&& -- V_23 -> V_76 > 0
&& V_23 -> V_145 == 0 ) {
F_71 ( V_9 , & V_144 ) ;
if ( V_144 > 0 ) {
F_67 ( V_23 ) ;
V_23 -> V_145 ++ ;
}
}
F_27 ( V_15 ) ;
if ( V_57 && -- V_57 -> V_117 == 0 && V_57 -> V_114 == 0 )
F_126 ( V_9 , V_57 ) ;
F_109 ( & V_9 -> V_154 ) ;
F_134 ( V_9 ) ;
F_135 ( V_3 ) ;
}
static int
F_136 ( void )
{
struct V_7 * V_15 ;
struct V_11 * V_13 ;
int V_148 ;
for ( V_148 = 0 ; ; ++ V_148 ) {
if ( V_148 == V_222 )
return 1 ;
if ( F_30 ( & V_223 . V_12 ) )
return 0 ;
V_13 = V_223 . V_12 . V_63 ;
F_10 ( V_13 ) ;
F_109 ( & V_223 . V_154 ) ;
V_15 = F_9 ( V_13 , struct V_7 , V_12 ) ;
F_128 ( V_15 ) ;
F_108 ( & V_223 . V_154 ) ;
}
}
static int
F_137 ( void * V_150 )
{
struct V_224 * V_225 ;
F_138 ( V_226 , V_227 ) ;
int V_228 ;
V_225 = V_150 ;
V_227 -> V_60 |= V_229 ;
F_139 ( V_227 , - 10 ) ;
F_140 ( & V_225 -> V_230 ) ;
do {
F_108 ( V_225 -> V_154 ) ;
V_228 = V_225 -> V_231 () ;
if ( ! V_228 ) {
F_141 ( V_225 -> V_232 , & V_226 ) ;
F_142 ( V_233 ) ;
}
F_109 ( V_225 -> V_154 ) ;
if ( ! V_228 ) {
F_143 () ;
F_144 ( V_225 -> V_232 , & V_226 ) ;
} else
F_145 () ;
} while ( ! F_146 () );
F_140 ( & V_225 -> V_230 ) ;
return 0 ;
}
void
F_147 ( struct V_224 * V_225 )
{
F_148 ( V_225 -> V_234 ) ;
F_149 ( & V_225 -> V_230 ) ;
}
int
F_150 ( struct V_224 * V_225 )
{
struct V_235 * V_234 ;
F_151 ( & V_225 -> V_230 ) ;
V_234 = F_152 ( F_137 , V_225 , V_225 -> V_236 ) ;
if ( V_234 == NULL || F_153 ( V_234 ) )
return - V_237 ;
V_225 -> V_234 = V_234 ;
F_149 ( & V_225 -> V_230 ) ;
F_151 ( & V_225 -> V_230 ) ;
return 0 ;
}
static void
F_59 ( struct V_7 * V_15 , struct V_1 * V_3 )
{
T_1 V_60 ;
V_15 -> V_59 = V_3 ;
F_76 ( & V_223 . V_154 , V_60 ) ;
F_38 ( & V_15 -> V_12 , & V_223 . V_12 ) ;
F_77 ( & V_223 . V_154 , V_60 ) ;
F_154 ( & V_238 ) ;
}
struct V_1 *
F_155 ( struct V_1 * V_3 )
{
struct V_8 * V_9 ;
struct V_24 * V_25 ;
struct V_7 * V_15 ;
T_2 V_17 ;
T_1 V_60 ;
char V_239 [ 128 ] ;
T_7 V_36 ;
V_25 = (struct V_24 * ) V_3 -> V_217 ;
V_36 = F_132 ( F_133 ( & V_25 -> V_35 ) ) ;
V_9 = F_156 ( V_36 , V_25 -> V_37 , 0 ) ;
if ( V_9 == NULL ) {
snprintf ( V_239 , sizeof V_239 , L_18
L_19 ,
V_36 , V_25 -> V_37 ) ;
F_60 ( V_239 ) ;
return V_3 ;
}
F_76 ( & V_9 -> V_154 , V_60 ) ;
V_17 = F_157 ( F_133 ( & V_25 -> V_10 ) ) ;
V_15 = F_11 ( V_9 , V_17 ) ;
if ( V_15 ) {
F_117 ( V_9 , V_15 -> V_23 , F_61 ( V_15 ) ) ;
V_15 -> V_23 -> V_77 -- ;
if ( V_15 -> V_60 & V_126 )
V_15 -> V_23 -> V_145 -- ;
} else {
V_15 = F_7 ( V_9 , V_17 ) ;
if ( V_15 ) {
F_117 ( V_9 , NULL , F_61 ( V_15 ) ) ;
} else {
F_117 ( V_9 , NULL , F_62 ( V_17 ) ) ;
F_77 ( & V_9 -> V_154 , V_60 ) ;
F_134 ( V_9 ) ;
snprintf ( V_239 , sizeof( V_239 ) ,
L_20 ,
L_21 ,
F_158 ( & V_25 -> V_35 ) ,
V_25 -> V_37 ,
F_159 ( & V_25 -> V_10 ) ,
V_20 ,
V_25 -> V_27 ,
V_25 -> V_31 ) ;
F_60 ( V_239 ) ;
return V_3 ;
}
}
F_98 ( V_9 ) ;
F_77 ( & V_9 -> V_154 , V_60 ) ;
F_59 ( V_15 , V_3 ) ;
return NULL ;
}
void
F_160 ( T_4 V_36 , unsigned char V_38 )
{
struct V_109 V_110 ;
F_48 ( & V_110 ) ;
F_50 ( V_36 , V_38 , & V_110 ) ;
F_49 ( & V_110 ) ;
}
struct V_1 *
F_161 ( struct V_8 * V_9 )
{
struct V_24 * V_25 ;
struct V_41 * V_42 ;
struct V_7 * V_15 ;
struct V_1 * V_3 ;
struct V_22 * V_23 ;
V_15 = F_33 ( V_9 ) ;
if ( V_15 == NULL )
return NULL ;
V_23 = * V_9 -> V_74 ;
V_3 = V_15 -> V_3 ;
V_25 = (struct V_24 * ) F_40 ( V_3 ) ;
V_42 = (struct V_41 * ) ( V_25 + 1 ) ;
F_41 ( V_3 , sizeof *V_25 + sizeof *V_42 ) ;
memset ( V_25 , 0 , V_3 -> V_2 ) ;
V_15 -> V_10 = F_13 ( V_9 , V_23 , V_25 ) ;
F_37 ( V_15 ) ;
V_23 -> V_77 ++ ;
V_15 -> V_92 = 0 ;
V_15 -> V_93 = 0 ;
V_42 -> V_95 = 1 ;
V_42 -> V_106 = V_221 ;
V_42 -> V_47 = 0xa0 ;
V_3 -> V_108 = V_23 -> V_28 -> V_29 ;
V_9 -> V_139 = V_240 ;
V_9 -> V_141 = V_241 ;
V_9 -> V_164 . V_242 = F_74 ;
V_3 = F_46 ( V_3 , V_4 ) ;
if ( V_3 ) {
F_47 ( & V_15 -> V_118 ) ;
V_15 -> V_119 = ( T_2 ) V_20 ;
}
return V_3 ;
}
static struct V_22 * *
F_162 ( struct V_8 * V_9 )
{
T_1 V_243 , V_244 ;
struct V_22 * * V_68 ;
V_243 = V_9 -> V_75 ;
V_244 = V_243 * 2 ;
V_68 = F_31 ( V_244 , sizeof( * V_9 -> V_72 ) , V_4 ) ;
if ( ! V_68 )
return NULL ;
memmove ( V_68 , V_9 -> V_72 , sizeof( * V_9 -> V_72 ) * V_243 ) ;
V_9 -> V_74 = V_68 + ( V_9 -> V_74 - V_9 -> V_72 ) ;
F_163 ( V_9 -> V_72 ) ;
V_9 -> V_72 = V_68 ;
V_9 -> V_75 = V_244 ;
return & V_9 -> V_72 [ V_243 ] ;
}
static struct V_22 *
F_164 ( struct V_8 * V_9 , char * V_32 , T_1 V_161 )
{
struct V_22 * V_23 , * * V_68 , * * V_245 ;
V_68 = V_9 -> V_72 ;
V_245 = V_68 + V_9 -> V_75 ;
for (; V_68 < V_245 && * V_68 ; V_68 ++ )
;
if ( V_68 == V_245 ) {
V_68 = F_162 ( V_9 ) ;
if ( ! V_68 )
goto V_246;
}
V_23 = F_165 ( sizeof( * V_23 ) , V_4 ) ;
if ( ! V_23 )
goto V_246;
V_23 -> V_161 = V_161 ;
V_23 -> V_9 = V_9 ;
memcpy ( V_23 -> V_32 , V_32 , sizeof V_23 -> V_32 ) ;
V_23 -> V_28 = V_23 -> V_51 ;
F_166 ( V_23 ) ;
V_23 -> V_78 = V_23 -> V_161 / 2 ;
F_167 ( & V_23 -> V_61 ) ;
return * V_68 = V_23 ;
V_246:
F_58 ( L_22 ) ;
return NULL ;
}
static void
F_168 ( struct V_8 * V_9 )
{
struct V_22 * * V_23 , * * V_134 ;
int V_96 = 0 ;
V_23 = V_9 -> V_72 ;
V_134 = V_23 + V_9 -> V_75 ;
for (; V_23 < V_134 && * V_23 ; V_23 ++ )
if ( V_96 == 0 || V_96 > ( * V_23 ) -> V_247 )
V_96 = ( * V_23 ) -> V_247 ;
if ( V_96 != V_9 -> V_112 ) {
V_9 -> V_112 = V_96 ;
F_58 ( L_23 ,
V_9 -> V_36 , V_9 -> V_38 , V_96 ) ;
}
}
static void
F_169 ( struct V_22 * V_23 , struct V_122 * V_29 , int V_96 )
{
struct V_8 * V_9 ;
struct V_50 * V_133 , * V_134 ;
int V_247 ;
V_9 = V_23 -> V_9 ;
V_247 = V_96 ;
V_133 = V_23 -> V_51 ;
V_134 = V_133 + V_52 ;
for (; V_133 < V_134 ; V_133 ++ ) {
if ( V_133 -> V_29 == NULL )
break;
if ( V_133 -> V_29 == V_29 ) {
V_133 -> V_96 = V_96 ;
V_29 = NULL ;
} else if ( V_247 > V_133 -> V_96 )
V_247 = V_133 -> V_96 ;
}
if ( V_29 ) {
if ( V_133 == V_134 ) {
F_68 ( L_24 ) ;
return;
}
F_53 ( V_29 ) ;
V_133 -> V_29 = V_29 ;
V_133 -> V_96 = V_96 ;
}
V_23 -> V_247 = V_247 ;
F_168 ( V_9 ) ;
}
void
F_170 ( struct V_1 * V_3 )
{
struct V_8 * V_9 ;
struct V_24 * V_25 ;
struct V_120 * V_121 ;
struct V_22 * V_23 ;
T_1 V_60 , V_36 ;
struct V_1 * V_248 ;
struct V_109 V_110 ;
T_7 V_17 ;
V_248 = NULL ;
V_25 = (struct V_24 * ) F_40 ( V_3 ) ;
V_121 = (struct V_120 * ) ( V_25 + 1 ) ;
V_36 = F_158 ( & V_25 -> V_35 ) ;
if ( V_36 == 0xfff ) {
F_34 ( V_73 L_25
L_26 ) ;
return;
}
if ( V_36 == 0xffff ) {
F_58 ( L_27 ,
V_36 , ( int ) V_25 -> V_37 ) ;
return;
}
if ( V_25 -> V_37 == 0xff ) {
F_58 ( L_28 ,
V_36 , ( int ) V_25 -> V_37 ) ;
return;
}
V_17 = F_132 ( V_121 -> V_249 ) ;
if ( V_17 > V_250 )
V_17 = V_250 ;
V_9 = F_156 ( V_36 , V_25 -> V_37 , 1 ) ;
if ( V_9 == NULL ) {
F_58 ( L_29 ) ;
return;
}
F_76 ( & V_9 -> V_154 , V_60 ) ;
V_23 = F_118 ( V_9 , V_25 -> V_27 ) ;
if ( V_23 ) {
V_23 -> V_161 = V_17 ;
if ( V_17 < V_23 -> V_78 )
F_166 ( V_23 ) ;
} else {
V_23 = F_164 ( V_9 , V_25 -> V_27 , V_17 ) ;
if ( ! V_23 )
goto V_64;
}
V_17 = V_3 -> V_108 -> V_251 ;
V_17 -= sizeof( struct V_24 ) + sizeof( struct V_41 ) ;
V_17 /= 512 ;
if ( V_17 > V_121 -> V_95 )
V_17 = V_121 -> V_95 ;
V_17 = V_17 ? V_17 * 512 : V_113 ;
F_169 ( V_23 , V_3 -> V_108 , V_17 ) ;
if ( V_9 -> V_252 == 0 ) {
V_9 -> V_202 = F_132 ( V_121 -> V_253 ) ;
V_248 = F_161 ( V_9 ) ;
}
V_64:
F_77 ( & V_9 -> V_154 , V_60 ) ;
F_134 ( V_9 ) ;
if ( V_248 ) {
F_48 ( & V_110 ) ;
F_20 ( & V_110 , V_248 ) ;
F_49 ( & V_110 ) ;
}
}
void
F_166 ( struct V_22 * V_23 )
{
V_23 -> V_78 = 1 ;
V_23 -> V_159 = V_23 -> V_161 / 2 ;
V_23 -> V_205 = V_23 -> V_161 ;
}
void
F_171 ( struct V_8 * V_9 )
{
struct V_22 * * V_23 , * * V_245 ;
V_9 -> V_139 = V_240 ;
V_9 -> V_141 = V_241 ;
V_9 -> V_112 = 0 ;
V_23 = V_9 -> V_72 ;
V_245 = V_23 + V_9 -> V_75 ;
for (; V_23 < V_245 && * V_23 ; V_23 ++ )
F_166 ( * V_23 ) ;
}
void
F_172 ( struct V_8 * V_9 , struct V_57 * V_57 )
{
if ( V_57 == NULL )
return;
V_57 -> V_114 = 0 ;
F_130 ( V_209 , & V_57 -> V_100 -> V_210 ) ;
if ( V_57 -> V_117 == 0 )
F_126 ( V_9 , V_57 ) ;
}
void
F_173 ( void )
{
struct V_7 * V_15 ;
struct V_8 * V_9 ;
F_75 ( V_151 ) ;
struct V_11 * V_13 ;
struct V_1 * V_3 ;
T_1 V_60 ;
F_76 ( & V_223 . V_154 , V_60 ) ;
F_174 ( & V_223 . V_12 , & V_151 ) ;
F_77 ( & V_223 . V_154 , V_60 ) ;
while ( ! F_30 ( & V_151 ) ) {
V_13 = V_151 . V_63 ;
F_10 ( V_13 ) ;
V_15 = F_9 ( V_13 , struct V_7 , V_12 ) ;
V_9 = V_15 -> V_23 -> V_9 ;
V_3 = V_15 -> V_59 ;
F_76 ( & V_9 -> V_154 , V_60 ) ;
if ( V_15 -> V_57 ) {
V_15 -> V_57 -> V_117 -- ;
F_172 ( V_9 , V_15 -> V_57 ) ;
}
F_27 ( V_15 ) ;
F_77 ( & V_9 -> V_154 , V_60 ) ;
F_135 ( V_3 ) ;
F_134 ( V_9 ) ;
}
}
int T_8
F_175 ( void )
{
void * V_133 ;
V_133 = ( void * ) F_176 ( V_254 | V_255 ) ;
if ( ! V_133 )
return - V_237 ;
V_138 = F_177 ( V_133 ) ;
F_167 ( & V_223 . V_12 ) ;
F_178 ( & V_223 . V_154 ) ;
F_179 ( & V_238 ) ;
V_256 . V_236 = L_30 ;
V_256 . V_231 = F_136 ;
V_256 . V_232 = & V_238 ;
V_256 . V_154 = & V_223 . V_154 ;
return F_150 ( & V_256 ) ;
}
void
F_180 ( void )
{
F_147 ( & V_256 ) ;
F_173 () ;
F_181 ( ( unsigned long ) F_120 ( V_138 ) ) ;
V_138 = NULL ;
}
