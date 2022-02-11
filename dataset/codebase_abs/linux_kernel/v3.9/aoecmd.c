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
V_16 -> V_44 = 0 ;
V_16 -> V_59 = NULL ;
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
F_36 ( struct V_1 * V_3 , struct V_82 * V_59 , T_1 V_83 , T_1 V_84 )
{
int V_85 = 0 ;
T_1 V_86 ;
V_87:
V_86 = V_59 -> V_88 - ( V_83 - V_59 -> V_89 ) ;
if ( V_86 > V_84 )
V_86 = V_84 ;
F_37 ( V_3 , V_85 ++ , V_59 -> V_90 , V_83 , V_86 ) ;
V_84 -= V_86 ;
if ( V_84 <= 0 )
return;
V_59 ++ ;
V_83 = V_59 -> V_89 ;
goto V_87;
}
static void
F_38 ( struct V_8 * V_16 )
{
struct V_9 * V_10 = V_16 -> V_24 -> V_10 ;
T_2 V_18 ;
V_18 = V_16 -> V_11 % V_19 ;
F_39 ( & V_16 -> V_13 , & V_10 -> V_20 [ V_18 ] ) ;
}
static void
F_40 ( struct V_8 * V_16 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_42 * V_43 ;
struct V_1 * V_3 ;
char V_91 , V_92 ;
V_3 = V_16 -> V_3 ;
V_26 = (struct V_25 * ) F_41 ( V_3 ) ;
V_43 = (struct V_42 * ) ( V_26 + 1 ) ;
F_42 ( V_3 , sizeof( * V_26 ) + sizeof( * V_43 ) ) ;
memset ( V_26 , 0 , V_3 -> V_2 ) ;
V_91 = 0x10 ;
V_92 = 0x4 ;
V_24 = V_16 -> V_24 ;
V_16 -> V_11 = F_14 ( V_24 -> V_10 , V_24 , V_26 ) ;
F_38 ( V_16 ) ;
V_24 -> V_78 ++ ;
V_16 -> V_93 = 0 ;
V_16 -> V_94 = 0 ;
if ( V_16 -> V_58 )
V_16 -> V_44 = V_16 -> V_58 -> V_95 ;
V_43 -> V_96 = V_16 -> V_97 >> 9 ;
F_18 ( V_43 , V_16 -> V_44 ) ;
if ( V_24 -> V_10 -> V_61 & V_98 ) {
V_43 -> V_99 |= V_100 ;
} else {
V_92 = 0 ;
V_43 -> V_48 &= 0x0f ;
V_43 -> V_48 |= 0xe0 ;
}
if ( V_16 -> V_58 && F_43 ( V_16 -> V_58 -> V_101 ) == V_102 ) {
F_36 ( V_3 , V_16 -> V_59 , V_16 -> V_103 , V_16 -> V_97 ) ;
V_43 -> V_99 |= V_104 ;
V_3 -> V_2 += V_16 -> V_97 ;
V_3 -> V_67 = V_16 -> V_97 ;
V_3 -> V_66 += V_16 -> V_97 ;
V_24 -> V_105 ++ ;
} else {
V_24 -> V_106 ++ ;
V_91 = 0 ;
}
V_43 -> V_107 = V_108 | V_91 | V_92 ;
V_3 -> V_109 = V_24 -> V_29 -> V_30 ;
}
static int
F_44 ( struct V_9 * V_10 )
{
struct V_8 * V_16 ;
struct V_58 * V_58 ;
struct V_23 * V_24 ;
struct V_1 * V_3 ;
struct V_110 V_111 ;
T_1 V_97 , V_112 ;
V_58 = F_45 ( V_10 ) ;
if ( V_58 == NULL )
return 0 ;
V_16 = F_34 ( V_10 ) ;
if ( V_16 == NULL )
return 0 ;
V_24 = * V_10 -> V_75 ;
V_97 = V_10 -> V_113 ;
if ( V_97 == 0 )
V_97 = V_114 ;
if ( V_97 > V_58 -> V_115 )
V_97 = V_58 -> V_115 ;
V_112 = V_97 ;
V_16 -> V_59 = V_58 -> V_59 ;
V_16 -> V_103 = V_16 -> V_59 -> V_89 + ( V_16 -> V_59 -> V_88 - V_58 -> V_116 ) ;
do {
if ( V_112 < V_58 -> V_116 ) {
V_58 -> V_116 -= V_112 ;
V_58 -> V_115 -= V_112 ;
break;
}
V_112 -= V_58 -> V_116 ;
V_58 -> V_115 -= V_58 -> V_116 ;
if ( V_58 -> V_115 == 0 ) {
V_10 -> V_117 . V_58 = NULL ;
break;
}
V_58 -> V_59 ++ ;
V_58 -> V_116 = V_58 -> V_59 -> V_88 ;
F_46 ( V_58 -> V_116 == 0 ) ;
} while ( V_112 );
V_16 -> V_58 = V_58 ;
V_16 -> V_97 = V_97 ;
F_40 ( V_16 ) ;
V_58 -> V_118 += 1 ;
V_58 -> V_95 += V_97 >> 9 ;
V_3 = F_47 ( V_16 -> V_3 , V_5 ) ;
if ( V_3 ) {
F_48 ( & V_16 -> V_119 ) ;
V_16 -> V_120 = ( T_2 ) V_21 ;
F_49 ( & V_111 ) ;
F_21 ( & V_111 , V_3 ) ;
F_50 ( & V_111 ) ;
}
return 1 ;
}
static void
F_51 ( T_4 V_37 , unsigned char V_39 , struct V_110 * V_111 )
{
struct V_25 * V_26 ;
struct V_121 * V_122 ;
struct V_1 * V_3 ;
struct V_123 * V_29 ;
F_52 () ;
F_53 (&init_net, ifp) {
F_54 ( V_29 ) ;
if ( ! F_55 ( V_29 ) )
goto V_124;
V_3 = F_1 ( sizeof *V_26 + sizeof *V_122 ) ;
if ( V_3 == NULL ) {
F_35 ( V_125 L_2 ) ;
goto V_124;
}
F_42 ( V_3 , sizeof *V_26 + sizeof *V_122 ) ;
V_3 -> V_109 = V_29 ;
F_21 ( V_111 , V_3 ) ;
V_26 = (struct V_25 * ) F_41 ( V_3 ) ;
memset ( V_26 , 0 , sizeof *V_26 + sizeof *V_122 ) ;
memset ( V_26 -> V_32 , 0xff , sizeof V_26 -> V_32 ) ;
memcpy ( V_26 -> V_28 , V_29 -> V_31 , sizeof V_26 -> V_28 ) ;
V_26 -> type = F_15 ( V_7 ) ;
V_26 -> V_34 = V_35 ;
V_26 -> V_36 = F_16 ( V_37 ) ;
V_26 -> V_38 = V_39 ;
V_26 -> V_40 = V_126 ;
V_124:
F_56 ( V_29 ) ;
}
F_57 () ;
}
static void
F_58 ( struct V_9 * V_10 , struct V_8 * V_16 )
{
struct V_1 * V_3 ;
struct V_110 V_111 ;
struct V_25 * V_26 ;
struct V_42 * V_43 ;
struct V_23 * V_24 ;
char V_58 [ 128 ] ;
T_2 V_18 ;
V_24 = V_16 -> V_24 ;
V_18 = F_13 ( V_10 ) ;
V_3 = V_16 -> V_3 ;
if ( F_19 ( V_24 ) == NULL ) {
F_59 ( L_3 ) ;
F_60 ( V_16 , NULL ) ;
return;
}
V_26 = (struct V_25 * ) F_41 ( V_3 ) ;
V_43 = (struct V_42 * ) ( V_26 + 1 ) ;
if ( ! ( V_16 -> V_61 & V_127 ) ) {
snprintf ( V_58 , sizeof( V_58 ) ,
L_4 ,
L_5 , V_10 -> V_37 , V_10 -> V_39 ,
V_16 -> V_11 , V_21 , V_18 ,
V_26 -> V_28 , V_26 -> V_32 , V_24 -> V_78 ) ;
F_61 ( V_58 ) ;
}
V_16 -> V_11 = V_18 ;
F_38 ( V_16 ) ;
V_26 -> V_11 = F_17 ( V_18 ) ;
memcpy ( V_26 -> V_32 , V_24 -> V_33 , sizeof V_26 -> V_32 ) ;
memcpy ( V_26 -> V_28 , V_24 -> V_29 -> V_30 -> V_31 , sizeof V_26 -> V_28 ) ;
V_3 -> V_109 = V_24 -> V_29 -> V_30 ;
V_3 = F_47 ( V_3 , V_5 ) ;
if ( V_3 == NULL )
return;
F_48 ( & V_16 -> V_119 ) ;
V_16 -> V_120 = ( T_2 ) V_21 ;
F_49 ( & V_111 ) ;
F_21 ( & V_111 , V_3 ) ;
F_50 ( & V_111 ) ;
}
static int
F_62 ( struct V_8 * V_16 )
{
struct V_128 V_129 ;
int V_18 ;
F_48 ( & V_129 ) ;
V_18 = V_129 . V_130 - V_16 -> V_119 . V_130 ;
V_18 += ( V_129 . V_131 - V_16 -> V_119 . V_131 ) * V_132 ;
if ( V_18 < 0 )
V_18 = - V_18 ;
if ( V_18 > V_132 / 4 ) {
V_18 = ( ( T_2 ) V_21 ) - V_16 -> V_120 ;
V_18 *= V_132 / V_133 ;
}
return V_18 ;
}
static int
F_63 ( T_2 V_11 )
{
int V_18 ;
V_18 = V_21 & 0xffff ;
V_18 -= V_11 & 0xffff ;
if ( V_18 < 0 )
V_18 += 1 << 16 ;
return F_64 ( V_18 + 1 ) ;
}
static struct V_51 *
F_65 ( struct V_23 * V_24 , struct V_123 * V_30 )
{
struct V_51 * V_134 , * V_135 ;
V_134 = V_24 -> V_52 ;
V_135 = V_134 + V_53 ;
for (; V_134 < V_135 ; V_134 ++ )
if ( V_134 -> V_30 == V_30 )
return V_134 ;
return NULL ;
}
static void
F_66 ( struct V_23 * V_24 , struct V_51 * V_29 )
{
struct V_51 * V_135 ;
struct V_123 * V_30 ;
T_1 V_18 ;
V_30 = V_29 -> V_30 ;
V_135 = V_24 -> V_52 + V_53 - 1 ;
V_18 = ( V_135 - V_29 ) * sizeof *V_29 ;
memmove ( V_29 , V_29 + 1 , V_18 ) ;
V_135 -> V_30 = NULL ;
F_56 ( V_30 ) ;
}
static struct V_8 *
F_67 ( struct V_8 * V_16 )
{
struct V_8 * V_136 ;
struct V_1 * V_3 ;
V_136 = F_34 ( V_16 -> V_24 -> V_10 ) ;
if ( ! V_136 )
return NULL ;
if ( V_136 -> V_24 == V_16 -> V_24 ) {
F_28 ( V_136 ) ;
return NULL ;
}
V_3 = V_136 -> V_3 ;
V_136 -> V_3 = V_16 -> V_3 ;
V_136 -> V_58 = V_16 -> V_58 ;
V_136 -> V_97 = V_16 -> V_97 ;
V_136 -> V_44 = V_16 -> V_44 ;
V_136 -> V_59 = V_16 -> V_59 ;
V_136 -> V_103 = V_16 -> V_103 ;
V_136 -> V_93 = 0 ;
V_136 -> V_94 = V_16 -> V_94 ;
V_136 -> V_119 = V_16 -> V_119 ;
V_136 -> V_120 = V_16 -> V_120 ;
V_16 -> V_3 = V_3 ;
return V_136 ;
}
static void
F_68 ( struct V_23 * V_24 )
{
struct V_9 * V_10 ;
struct V_8 * V_16 ;
struct V_1 * V_3 ;
struct V_110 V_111 ;
T_5 V_18 , V_137 ;
int V_85 ;
V_10 = V_24 -> V_10 ;
V_16 = F_30 ( V_10 , V_24 ) ;
if ( ! V_16 ) {
F_69 ( L_6 ,
L_7 ,
V_24 -> V_33 ,
( long ) V_10 -> V_37 , V_10 -> V_39 ,
L_8 ) ;
return;
}
V_16 -> V_61 |= V_127 ;
F_19 ( V_24 ) ;
V_16 -> V_97 = V_24 -> V_10 -> V_113 ? V_24 -> V_10 -> V_113 : V_114 ;
F_40 ( V_16 ) ;
V_3 = V_16 -> V_3 ;
for ( V_85 = 0 , V_18 = V_16 -> V_97 ; V_18 > 0 ; ++ V_85 , V_18 -= V_137 ) {
if ( V_18 < V_138 )
V_137 = V_18 ;
else
V_137 = V_138 ;
F_37 ( V_3 , V_85 , V_139 , 0 , V_137 ) ;
}
V_3 -> V_2 += V_16 -> V_97 ;
V_3 -> V_67 = V_16 -> V_97 ;
V_3 -> V_66 += V_16 -> V_97 ;
V_3 = F_47 ( V_16 -> V_3 , V_5 ) ;
if ( V_3 ) {
F_48 ( & V_16 -> V_119 ) ;
V_16 -> V_120 = ( T_2 ) V_21 ;
F_49 ( & V_111 ) ;
F_21 ( & V_111 , V_3 ) ;
F_50 ( & V_111 ) ;
}
}
static long
F_70 ( struct V_9 * V_10 )
{
long V_24 ;
V_24 = 2 * V_10 -> V_140 >> V_141 ;
V_24 += 8 * V_10 -> V_142 >> V_143 ;
if ( V_24 == 0 )
V_24 = 1 ;
return V_24 ;
}
static void
F_71 ( struct V_9 * V_10 )
{
struct V_23 * V_24 ;
struct V_8 * V_16 ;
struct V_8 * V_136 ;
struct V_12 * V_14 , * V_15 , * V_13 ;
int V_144 ;
int V_145 ;
F_72 ( V_10 , & V_145 ) ;
V_13 = & V_10 -> V_17 ;
F_9 (pos, nx, head) {
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
V_24 = V_16 -> V_24 ;
if ( V_24 -> V_77 ) {
if ( ! ( V_16 -> V_61 & V_127 ) ) {
V_136 = F_67 ( V_16 ) ;
if ( V_136 ) {
if ( V_24 -> V_146 == 0
&& V_145 > 0 ) {
F_68 ( V_24 ) ;
V_24 -> V_146 ++ ;
}
F_73 ( & V_16 -> V_13 , & V_136 -> V_13 ) ;
V_14 = & V_136 -> V_13 ;
F_28 ( V_16 ) ;
V_16 = V_136 ;
V_24 = V_16 -> V_24 ;
}
} else if ( V_145 < 1 ) {
goto V_147;
} else if ( F_62 ( V_16 ) < V_24 -> V_77 * F_70 ( V_10 ) ) {
continue;
}
} else if ( V_16 -> V_61 & V_127 ) {
V_147:
F_11 ( V_14 ) ;
F_28 ( V_16 ) ;
V_16 -> V_24 -> V_10 -> V_61 |= V_81 ;
continue;
}
if ( V_24 -> V_78 >= V_24 -> V_79 )
continue;
F_11 ( V_14 ) ;
V_24 -> V_78 ++ ;
if ( V_16 -> V_61 & V_127 )
V_24 -> V_146 ++ ;
V_144 = F_62 ( V_16 ) ;
V_16 -> V_93 += V_144 ;
V_16 -> V_94 += V_144 ;
F_58 ( V_10 , V_16 ) ;
}
}
static void
F_74 ( struct V_23 * V_24 )
{
int V_18 ;
V_18 = V_24 -> V_77 ++ ;
V_24 -> V_77 += V_24 -> V_77 * 2 ;
if ( V_18 > V_24 -> V_77 )
V_24 -> V_77 = V_18 ;
if ( V_24 -> V_77 > V_148 )
V_24 -> V_77 = V_148 ;
}
static int
F_72 ( struct V_9 * V_10 , int * V_145 )
{
int V_149 , V_150 ;
for ( V_149 = V_150 = 0 ; V_149 < V_10 -> V_76 && V_10 -> V_73 [ V_149 ] ; ++ V_149 )
if ( V_10 -> V_73 [ V_149 ] -> V_77 == 0 )
V_150 ++ ;
if ( V_145 )
* V_145 = V_150 ;
return V_149 ;
}
static void
F_75 ( T_1 V_151 )
{
struct V_9 * V_10 ;
struct V_23 * V_24 ;
struct V_51 * V_29 ;
struct V_8 * V_16 ;
struct V_12 * V_13 , * V_14 , * V_15 ;
F_76 ( V_152 ) ;
register long V_153 ;
T_1 V_61 , V_18 ;
int V_149 ;
int V_154 ;
int V_144 ;
V_10 = (struct V_9 * ) V_151 ;
F_77 ( & V_10 -> V_155 , V_61 ) ;
V_153 = F_70 ( V_10 ) ;
V_154 = F_72 ( V_10 , NULL ) ;
if ( V_10 -> V_61 & V_156 ) {
F_78 ( & V_10 -> V_155 , V_61 ) ;
return;
}
for ( V_149 = 0 ; V_149 < V_19 ; V_149 ++ ) {
V_13 = & V_10 -> V_20 [ V_149 ] ;
F_9 (pos, nx, head) {
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
if ( F_62 ( V_16 ) < V_153 )
break;
F_79 ( V_14 , & V_152 ) ;
}
}
while ( ! F_31 ( & V_152 ) ) {
V_14 = V_152 . V_64 ;
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
V_144 = F_62 ( V_16 ) ;
V_18 = V_16 -> V_94 + V_144 ;
V_18 /= V_132 ;
if ( V_157
&& V_18 > V_157
&& ! ( V_16 -> V_61 & V_127 ) ) {
F_80 ( & V_152 , & V_10 -> V_20 [ 0 ] ) ;
F_81 ( V_10 ) ;
goto V_158;
}
V_24 = V_16 -> V_24 ;
V_18 = V_16 -> V_93 + V_144 ;
V_18 /= V_132 ;
if ( V_157 && V_154 > 0
&& ( V_18 > V_157 / V_154 || V_18 > V_159 ) )
F_74 ( V_24 ) ;
if ( V_24 -> V_79 != 1 ) {
V_24 -> V_160 = V_24 -> V_79 / 2 ;
V_24 -> V_79 = 1 ;
}
if ( V_16 -> V_61 & V_127 ) {
V_24 -> V_146 -- ;
} else {
V_29 = F_65 ( V_24 , V_16 -> V_3 -> V_109 ) ;
if ( V_29 && ++ V_29 -> V_161 > ( V_24 -> V_162 << 1 )
&& ( V_29 != V_24 -> V_52 || V_24 -> V_52 [ 1 ] . V_30 ) ) {
F_66 ( V_24 , V_29 ) ;
V_29 = NULL ;
}
}
F_79 ( V_14 , & V_10 -> V_17 ) ;
V_24 -> V_78 -- ;
}
F_71 ( V_10 ) ;
V_158:
if ( ( V_10 -> V_61 & V_81 ) && V_10 -> V_163 ) {
V_10 -> V_61 &= ~ V_81 ;
V_10 -> V_163 -> V_164 ( V_10 -> V_163 ) ;
}
V_10 -> V_165 . V_166 = V_21 + V_167 ;
F_82 ( & V_10 -> V_165 ) ;
F_78 ( & V_10 -> V_155 , V_61 ) ;
}
static unsigned long
F_83 ( struct V_168 * V_169 )
{
struct V_101 * V_101 ;
unsigned long V_18 = 0 ;
F_84 (bio, r)
V_18 ++ ;
return V_18 ;
}
static void
F_85 ( struct V_101 * V_101 )
{
struct V_82 * V_59 ;
struct V_170 * V_170 ;
int V_149 ;
F_86 (bv, bio, i) {
V_170 = V_59 -> V_90 ;
if ( F_87 ( F_88 ( V_170 ) ) )
if ( F_89 ( V_170 ) != V_170 ) {
F_90 ( L_9 ) ;
F_91 () ;
}
F_92 ( & V_170 -> V_171 ) ;
}
}
static void
F_93 ( struct V_101 * V_101 )
{
struct V_82 * V_59 ;
int V_149 ;
F_86 (bv, bio, i)
F_94 ( & V_59 -> V_90 -> V_171 ) ;
}
static void
F_95 ( struct V_58 * V_58 , struct V_168 * V_172 , struct V_101 * V_101 )
{
struct V_82 * V_59 ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_172 = V_172 ;
V_58 -> V_101 = V_101 ;
V_58 -> V_115 = V_101 -> V_173 ;
V_58 -> V_95 = V_101 -> V_174 ;
F_85 ( V_101 ) ;
V_58 -> V_59 = V_59 = & V_101 -> V_175 [ V_101 -> V_176 ] ;
V_58 -> V_116 = V_59 -> V_88 ;
F_46 ( V_58 -> V_116 == 0 ) ;
}
static struct V_58 *
F_45 ( struct V_9 * V_10 )
{
struct V_168 * V_172 ;
struct V_177 * V_178 ;
struct V_58 * V_58 ;
struct V_101 * V_101 ;
V_178 = V_10 -> V_163 ;
if ( V_178 == NULL )
return NULL ;
if ( V_10 -> V_117 . V_58 )
return V_10 -> V_117 . V_58 ;
V_172 = V_10 -> V_117 . V_172 ;
if ( V_172 == NULL ) {
V_172 = F_96 ( V_178 ) ;
if ( V_172 == NULL )
return NULL ;
F_97 ( V_172 ) ;
V_10 -> V_117 . V_172 = V_172 ;
V_10 -> V_117 . V_179 = V_172 -> V_101 ;
V_172 -> V_180 = ( void * ) F_83 ( V_172 ) ;
}
V_58 = F_98 ( V_10 -> V_181 , V_5 ) ;
if ( V_58 == NULL ) {
F_69 ( L_10 ) ;
return NULL ;
}
V_101 = V_10 -> V_117 . V_179 ;
F_95 ( V_58 , V_172 , V_101 ) ;
V_101 = V_101 -> V_182 ;
V_10 -> V_117 . V_179 = V_101 ;
if ( V_101 == NULL )
V_10 -> V_117 . V_172 = NULL ;
return V_10 -> V_117 . V_58 = V_58 ;
}
void
F_99 ( struct V_9 * V_10 )
{
F_71 ( V_10 ) ;
while ( F_44 ( V_10 ) )
;
}
void
F_100 ( struct V_183 * V_184 )
{
struct V_9 * V_10 = F_101 ( V_184 , struct V_9 , V_184 ) ;
struct V_185 * V_186 ;
T_6 V_187 ;
if ( V_10 -> V_61 & V_188 )
F_102 ( V_10 ) ;
if ( V_10 -> V_61 & V_189 ) {
V_187 = F_103 ( V_10 -> V_190 ) ;
V_186 = F_104 ( V_10 -> V_190 , 0 ) ;
if ( V_186 ) {
F_105 ( & V_186 -> V_191 -> V_192 ) ;
F_106 ( V_186 -> V_191 , ( V_193 ) V_187 << 9 ) ;
F_107 ( & V_186 -> V_191 -> V_192 ) ;
F_108 ( V_186 ) ;
}
F_109 ( & V_10 -> V_155 ) ;
V_10 -> V_61 |= V_194 ;
V_10 -> V_61 &= ~ V_189 ;
F_110 ( & V_10 -> V_155 ) ;
}
}
static void
F_111 ( T_7 * V_195 , int V_196 )
{
T_7 V_197 ;
while ( V_196 -- > 0 ) {
V_197 = * V_195 ;
* V_195 ++ = V_197 >> 8 | V_197 << 8 ;
}
}
static void
F_112 ( struct V_9 * V_10 , struct V_23 * V_24 , unsigned char * V_195 )
{
T_6 V_187 ;
T_7 V_18 ;
V_18 = F_113 ( & V_195 [ 83 << 1 ] ) ;
V_18 |= F_113 ( & V_195 [ 86 << 1 ] ) ;
if ( V_18 & ( 1 << 10 ) ) {
V_10 -> V_61 |= V_98 ;
V_187 = F_114 ( & V_195 [ 100 << 1 ] ) ;
V_10 -> V_198 . V_199 = V_187 ;
V_10 -> V_198 . V_199 /= ( 255 * 63 ) ;
V_10 -> V_198 . V_200 = 255 ;
V_10 -> V_198 . V_201 = 63 ;
} else {
V_10 -> V_61 &= ~ V_98 ;
V_187 = F_115 ( & V_195 [ 60 << 1 ] ) ;
V_10 -> V_198 . V_199 = F_113 ( & V_195 [ 54 << 1 ] ) ;
V_10 -> V_198 . V_200 = F_113 ( & V_195 [ 55 << 1 ] ) ;
V_10 -> V_198 . V_201 = F_113 ( & V_195 [ 56 << 1 ] ) ;
}
F_111 ( ( T_7 * ) & V_195 [ 10 << 1 ] , 10 ) ;
F_111 ( ( T_7 * ) & V_195 [ 23 << 1 ] , 4 ) ;
F_111 ( ( T_7 * ) & V_195 [ 27 << 1 ] , 20 ) ;
memcpy ( V_10 -> V_202 , V_195 , sizeof( V_10 -> V_202 ) ) ;
if ( V_10 -> V_187 != V_187 )
F_35 ( V_125
L_11 ,
V_24 -> V_33 ,
V_10 -> V_37 , V_10 -> V_39 ,
V_10 -> V_203 , ( long long ) V_187 ) ;
V_10 -> V_187 = V_187 ;
V_10 -> V_198 . V_204 = 0 ;
if ( V_10 -> V_61 & ( V_188 | V_189 ) )
return;
if ( V_10 -> V_190 != NULL ) {
F_116 ( V_10 -> V_190 , V_187 ) ;
V_10 -> V_61 |= V_189 ;
} else
V_10 -> V_61 |= V_188 ;
F_117 ( & V_10 -> V_184 ) ;
}
static void
F_118 ( struct V_9 * V_10 , struct V_23 * V_24 , int V_205 )
{
register long V_18 ;
V_18 = V_205 ;
V_18 -= V_10 -> V_140 >> V_141 ;
V_10 -> V_140 += V_18 ;
if ( V_18 < 0 )
V_18 = - V_18 ;
V_18 -= V_10 -> V_142 >> V_143 ;
V_10 -> V_142 += V_18 ;
if ( ! V_24 || V_24 -> V_79 >= V_24 -> V_162 )
return;
if ( V_24 -> V_79 < V_24 -> V_160 )
V_24 -> V_79 += 1 ;
else if ( V_24 -> V_78 == V_24 -> V_79 && V_24 -> V_206 -- == 0 ) {
V_24 -> V_79 += 1 ;
V_24 -> V_206 = V_24 -> V_79 ;
}
}
static struct V_23 *
F_119 ( struct V_9 * V_10 , char * V_33 )
{
struct V_23 * * V_24 , * * V_135 ;
V_24 = V_10 -> V_73 ;
V_135 = V_24 + V_10 -> V_76 ;
for (; V_24 < V_135 && * V_24 ; V_24 ++ )
if ( memcmp ( ( * V_24 ) -> V_33 , V_33 , sizeof( ( * V_24 ) -> V_33 ) ) == 0 )
return * V_24 ;
return NULL ;
}
static void
F_120 ( struct V_82 * V_59 , T_1 V_83 , struct V_1 * V_3 , long V_84 )
{
T_1 V_86 ;
char * V_134 ;
int V_207 = 0 ;
V_87:
V_86 = V_59 -> V_88 - ( V_83 - V_59 -> V_89 ) ;
if ( V_86 > V_84 )
V_86 = V_84 ;
V_134 = F_121 ( V_59 -> V_90 ) + V_83 ;
F_122 ( V_3 , V_207 , V_134 , V_86 ) ;
V_207 += V_86 ;
V_84 -= V_86 ;
if ( V_84 <= 0 )
return;
V_59 ++ ;
V_83 = V_59 -> V_89 ;
goto V_87;
}
void
F_123 ( struct V_9 * V_10 , struct V_168 * V_172 , int V_208 )
{
struct V_101 * V_101 ;
int V_209 ;
struct V_177 * V_178 ;
V_178 = V_10 -> V_163 ;
if ( V_172 == V_10 -> V_117 . V_172 )
V_10 -> V_117 . V_172 = NULL ;
do {
V_101 = V_172 -> V_101 ;
V_209 = ! V_208 && F_124 ( V_210 , & V_101 -> V_211 ) ;
} while ( F_125 ( V_172 , V_209 ? 0 : - V_212 , V_101 -> V_173 ) );
if ( ! V_208 )
F_126 ( V_178 ) ;
}
static void
F_127 ( struct V_9 * V_10 , struct V_58 * V_58 )
{
struct V_168 * V_172 ;
unsigned long V_18 ;
if ( V_58 == V_10 -> V_117 . V_58 )
V_10 -> V_117 . V_58 = NULL ;
V_172 = V_58 -> V_172 ;
F_93 ( V_58 -> V_101 ) ;
F_128 ( V_58 , V_10 -> V_181 ) ;
V_18 = ( unsigned long ) V_172 -> V_180 ;
V_172 -> V_180 = ( void * ) -- V_18 ;
if ( V_18 == 0 )
F_123 ( V_10 , V_172 , 0 ) ;
}
static void
F_129 ( struct V_8 * V_16 )
{
struct V_25 * V_213 , * V_214 ;
struct V_42 * V_215 , * V_216 ;
struct V_58 * V_58 ;
struct V_1 * V_3 ;
struct V_23 * V_24 ;
struct V_51 * V_29 ;
struct V_9 * V_10 ;
long V_18 ;
int V_145 ;
if ( V_16 == NULL )
return;
V_24 = V_16 -> V_24 ;
V_10 = V_24 -> V_10 ;
V_3 = V_16 -> V_60 ;
V_58 = V_16 -> V_58 ;
if ( V_16 -> V_61 & V_127 )
goto V_158;
if ( ! V_3 )
goto V_217;
V_214 = (struct V_25 * ) F_41 ( V_16 -> V_3 ) ;
V_216 = (struct V_42 * ) ( V_214 + 1 ) ;
V_213 = (struct V_25 * ) V_3 -> V_218 ;
F_130 ( V_3 , sizeof( * V_213 ) ) ;
V_215 = (struct V_42 * ) V_3 -> V_218 ;
F_130 ( V_3 , sizeof( * V_215 ) ) ;
if ( V_215 -> V_107 & 0xa9 ) {
F_69 ( L_12 ,
V_216 -> V_107 , V_215 -> V_107 ,
V_10 -> V_37 , V_10 -> V_39 ) ;
V_217: if ( V_58 )
F_131 ( V_210 , & V_58 -> V_101 -> V_211 ) ;
goto V_158;
}
V_18 = V_216 -> V_96 << 9 ;
switch ( V_216 -> V_107 ) {
case V_108 :
case V_219 :
if ( V_3 -> V_2 < V_18 ) {
F_69 ( L_13 ,
L_14 ,
( long ) V_10 -> V_37 , V_10 -> V_39 ,
V_3 -> V_2 , V_18 ) ;
F_131 ( V_210 , & V_58 -> V_101 -> V_211 ) ;
break;
}
F_120 ( V_16 -> V_59 , V_16 -> V_103 , V_3 , V_18 ) ;
case V_220 :
case V_221 :
F_109 ( & V_10 -> V_155 ) ;
V_29 = F_65 ( V_24 , V_3 -> V_109 ) ;
if ( V_29 )
V_29 -> V_161 = 0 ;
F_110 ( & V_10 -> V_155 ) ;
break;
case V_222 :
if ( V_3 -> V_2 < 512 ) {
F_59 ( L_15 ,
L_16 ,
( long ) V_10 -> V_37 , V_10 -> V_39 ,
V_3 -> V_2 ) ;
break;
}
if ( F_132 ( V_3 ) )
break;
F_109 ( & V_10 -> V_155 ) ;
F_112 ( V_10 , V_24 , V_3 -> V_218 ) ;
F_110 ( & V_10 -> V_155 ) ;
break;
default:
F_59 ( L_17 ,
V_216 -> V_107 ,
F_133 ( F_134 ( & V_213 -> V_36 ) ) ,
V_213 -> V_38 ) ;
}
V_158:
F_109 ( & V_10 -> V_155 ) ;
if ( V_24 -> V_77 > 0
&& -- V_24 -> V_77 > 0
&& V_24 -> V_146 == 0 ) {
F_72 ( V_10 , & V_145 ) ;
if ( V_145 > 0 ) {
F_68 ( V_24 ) ;
V_24 -> V_146 ++ ;
}
}
F_28 ( V_16 ) ;
if ( V_58 && -- V_58 -> V_118 == 0 && V_58 -> V_115 == 0 )
F_127 ( V_10 , V_58 ) ;
F_110 ( & V_10 -> V_155 ) ;
F_135 ( V_10 ) ;
F_136 ( V_3 ) ;
}
static int
F_137 ( void )
{
struct V_8 * V_16 ;
struct V_12 * V_14 ;
int V_149 ;
for ( V_149 = 0 ; ; ++ V_149 ) {
if ( V_149 == V_223 )
return 1 ;
if ( F_31 ( & V_224 . V_13 ) )
return 0 ;
V_14 = V_224 . V_13 . V_64 ;
F_11 ( V_14 ) ;
F_110 ( & V_224 . V_155 ) ;
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
F_129 ( V_16 ) ;
F_109 ( & V_224 . V_155 ) ;
}
}
static int
F_138 ( void * V_151 )
{
struct V_225 * V_226 ;
F_139 ( V_227 , V_228 ) ;
int V_229 ;
V_226 = V_151 ;
V_228 -> V_61 |= V_230 ;
F_140 ( V_228 , - 10 ) ;
F_141 ( & V_226 -> V_231 ) ;
do {
F_109 ( V_226 -> V_155 ) ;
V_229 = V_226 -> V_232 () ;
if ( ! V_229 ) {
F_142 ( V_226 -> V_233 , & V_227 ) ;
F_143 ( V_234 ) ;
}
F_110 ( V_226 -> V_155 ) ;
if ( ! V_229 ) {
F_144 () ;
F_145 ( V_226 -> V_233 , & V_227 ) ;
} else
F_146 () ;
} while ( ! F_147 () );
F_141 ( & V_226 -> V_231 ) ;
return 0 ;
}
void
F_148 ( struct V_225 * V_226 )
{
F_149 ( V_226 -> V_235 ) ;
F_150 ( & V_226 -> V_231 ) ;
}
int
F_151 ( struct V_225 * V_226 )
{
struct V_236 * V_235 ;
F_152 ( & V_226 -> V_231 ) ;
V_235 = F_153 ( F_138 , V_226 , V_226 -> V_237 ) ;
if ( V_235 == NULL || F_154 ( V_235 ) )
return - V_238 ;
V_226 -> V_235 = V_235 ;
F_150 ( & V_226 -> V_231 ) ;
F_152 ( & V_226 -> V_231 ) ;
return 0 ;
}
static void
F_60 ( struct V_8 * V_16 , struct V_1 * V_3 )
{
T_1 V_61 ;
V_16 -> V_60 = V_3 ;
F_77 ( & V_224 . V_155 , V_61 ) ;
F_39 ( & V_16 -> V_13 , & V_224 . V_13 ) ;
F_78 ( & V_224 . V_155 , V_61 ) ;
F_155 ( & V_239 ) ;
}
struct V_1 *
F_156 ( struct V_1 * V_3 )
{
struct V_9 * V_10 ;
struct V_25 * V_26 ;
struct V_8 * V_16 ;
T_2 V_18 ;
T_1 V_61 ;
char V_240 [ 128 ] ;
T_7 V_37 ;
V_26 = (struct V_25 * ) V_3 -> V_218 ;
V_37 = F_133 ( F_134 ( & V_26 -> V_36 ) ) ;
V_10 = F_157 ( V_37 , V_26 -> V_38 , 0 ) ;
if ( V_10 == NULL ) {
snprintf ( V_240 , sizeof V_240 , L_18
L_19 ,
V_37 , V_26 -> V_38 ) ;
F_61 ( V_240 ) ;
return V_3 ;
}
F_77 ( & V_10 -> V_155 , V_61 ) ;
V_18 = F_158 ( F_134 ( & V_26 -> V_11 ) ) ;
V_16 = F_12 ( V_10 , V_18 ) ;
if ( V_16 ) {
F_118 ( V_10 , V_16 -> V_24 , F_62 ( V_16 ) ) ;
V_16 -> V_24 -> V_78 -- ;
if ( V_16 -> V_61 & V_127 )
V_16 -> V_24 -> V_146 -- ;
} else {
V_16 = F_8 ( V_10 , V_18 ) ;
if ( V_16 ) {
F_118 ( V_10 , NULL , F_62 ( V_16 ) ) ;
} else {
F_118 ( V_10 , NULL , F_63 ( V_18 ) ) ;
F_78 ( & V_10 -> V_155 , V_61 ) ;
F_135 ( V_10 ) ;
snprintf ( V_240 , sizeof( V_240 ) ,
L_20 ,
L_21 ,
F_159 ( & V_26 -> V_36 ) ,
V_26 -> V_38 ,
F_160 ( & V_26 -> V_11 ) ,
V_21 ,
V_26 -> V_28 ,
V_26 -> V_32 ) ;
F_61 ( V_240 ) ;
return V_3 ;
}
}
F_99 ( V_10 ) ;
F_78 ( & V_10 -> V_155 , V_61 ) ;
F_60 ( V_16 , V_3 ) ;
return NULL ;
}
void
F_161 ( T_4 V_37 , unsigned char V_39 )
{
struct V_110 V_111 ;
F_49 ( & V_111 ) ;
F_51 ( V_37 , V_39 , & V_111 ) ;
F_50 ( & V_111 ) ;
}
struct V_1 *
F_162 ( struct V_9 * V_10 )
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
V_26 = (struct V_25 * ) F_41 ( V_3 ) ;
V_43 = (struct V_42 * ) ( V_26 + 1 ) ;
F_42 ( V_3 , sizeof *V_26 + sizeof *V_43 ) ;
memset ( V_26 , 0 , V_3 -> V_2 ) ;
V_16 -> V_11 = F_14 ( V_10 , V_24 , V_26 ) ;
F_38 ( V_16 ) ;
V_24 -> V_78 ++ ;
V_16 -> V_93 = 0 ;
V_16 -> V_94 = 0 ;
V_43 -> V_96 = 1 ;
V_43 -> V_107 = V_222 ;
V_43 -> V_48 = 0xa0 ;
V_3 -> V_109 = V_24 -> V_29 -> V_30 ;
V_10 -> V_140 = V_241 ;
V_10 -> V_142 = V_242 ;
V_10 -> V_165 . V_243 = F_75 ;
V_3 = F_47 ( V_3 , V_5 ) ;
if ( V_3 ) {
F_48 ( & V_16 -> V_119 ) ;
V_16 -> V_120 = ( T_2 ) V_21 ;
}
return V_3 ;
}
static struct V_23 * *
F_163 ( struct V_9 * V_10 )
{
T_1 V_244 , V_245 ;
struct V_23 * * V_69 ;
V_244 = V_10 -> V_76 ;
V_245 = V_244 * 2 ;
V_69 = F_32 ( V_245 , sizeof( * V_10 -> V_73 ) , V_5 ) ;
if ( ! V_69 )
return NULL ;
memmove ( V_69 , V_10 -> V_73 , sizeof( * V_10 -> V_73 ) * V_244 ) ;
V_10 -> V_75 = V_69 + ( V_10 -> V_75 - V_10 -> V_73 ) ;
F_164 ( V_10 -> V_73 ) ;
V_10 -> V_73 = V_69 ;
V_10 -> V_76 = V_245 ;
return & V_10 -> V_73 [ V_244 ] ;
}
static struct V_23 *
F_165 ( struct V_9 * V_10 , char * V_33 , T_1 V_162 )
{
struct V_23 * V_24 , * * V_69 , * * V_246 ;
V_69 = V_10 -> V_73 ;
V_246 = V_69 + V_10 -> V_76 ;
for (; V_69 < V_246 && * V_69 ; V_69 ++ )
;
if ( V_69 == V_246 ) {
V_69 = F_163 ( V_10 ) ;
if ( ! V_69 )
goto V_247;
}
V_24 = F_166 ( sizeof( * V_24 ) , V_5 ) ;
if ( ! V_24 )
goto V_247;
V_24 -> V_162 = V_162 ;
V_24 -> V_10 = V_10 ;
memcpy ( V_24 -> V_33 , V_33 , sizeof V_24 -> V_33 ) ;
V_24 -> V_29 = V_24 -> V_52 ;
F_167 ( V_24 ) ;
V_24 -> V_79 = V_24 -> V_162 / 2 ;
F_168 ( & V_24 -> V_62 ) ;
return * V_69 = V_24 ;
V_247:
F_59 ( L_22 ) ;
return NULL ;
}
static void
F_169 ( struct V_9 * V_10 )
{
struct V_23 * * V_24 , * * V_135 ;
int V_97 = 0 ;
V_24 = V_10 -> V_73 ;
V_135 = V_24 + V_10 -> V_76 ;
for (; V_24 < V_135 && * V_24 ; V_24 ++ )
if ( V_97 == 0 || V_97 > ( * V_24 ) -> V_248 )
V_97 = ( * V_24 ) -> V_248 ;
if ( V_97 != V_10 -> V_113 ) {
V_10 -> V_113 = V_97 ;
F_59 ( L_23 ,
V_10 -> V_37 , V_10 -> V_39 , V_97 ) ;
}
}
static void
F_170 ( struct V_23 * V_24 , struct V_123 * V_30 , int V_97 )
{
struct V_9 * V_10 ;
struct V_51 * V_134 , * V_135 ;
int V_248 ;
V_10 = V_24 -> V_10 ;
V_248 = V_97 ;
V_134 = V_24 -> V_52 ;
V_135 = V_134 + V_53 ;
for (; V_134 < V_135 ; V_134 ++ ) {
if ( V_134 -> V_30 == NULL )
break;
if ( V_134 -> V_30 == V_30 ) {
V_134 -> V_97 = V_97 ;
V_30 = NULL ;
} else if ( V_248 > V_134 -> V_97 )
V_248 = V_134 -> V_97 ;
}
if ( V_30 ) {
if ( V_134 == V_135 ) {
F_69 ( L_24 ) ;
return;
}
F_54 ( V_30 ) ;
V_134 -> V_30 = V_30 ;
V_134 -> V_97 = V_97 ;
}
V_24 -> V_248 = V_248 ;
F_169 ( V_10 ) ;
}
void
F_171 ( struct V_1 * V_3 )
{
struct V_9 * V_10 ;
struct V_25 * V_26 ;
struct V_121 * V_122 ;
struct V_23 * V_24 ;
T_1 V_61 , V_37 ;
struct V_1 * V_249 ;
struct V_110 V_111 ;
T_7 V_18 ;
V_249 = NULL ;
V_26 = (struct V_25 * ) F_41 ( V_3 ) ;
V_122 = (struct V_121 * ) ( V_26 + 1 ) ;
V_37 = F_159 ( & V_26 -> V_36 ) ;
if ( V_37 == 0xfff ) {
F_35 ( V_74 L_25
L_26 ) ;
return;
}
if ( V_37 == 0xffff ) {
F_59 ( L_27 ,
V_37 , ( int ) V_26 -> V_38 ) ;
return;
}
if ( V_26 -> V_38 == 0xff ) {
F_59 ( L_28 ,
V_37 , ( int ) V_26 -> V_38 ) ;
return;
}
V_18 = F_133 ( V_122 -> V_250 ) ;
if ( V_18 > V_251 )
V_18 = V_251 ;
V_10 = F_157 ( V_37 , V_26 -> V_38 , 1 ) ;
if ( V_10 == NULL ) {
F_59 ( L_29 ) ;
return;
}
F_77 ( & V_10 -> V_155 , V_61 ) ;
V_24 = F_119 ( V_10 , V_26 -> V_28 ) ;
if ( V_24 ) {
V_24 -> V_162 = V_18 ;
if ( V_18 < V_24 -> V_79 )
F_167 ( V_24 ) ;
} else {
V_24 = F_165 ( V_10 , V_26 -> V_28 , V_18 ) ;
if ( ! V_24 )
goto V_65;
}
V_18 = V_3 -> V_109 -> V_252 ;
V_18 -= sizeof( struct V_25 ) + sizeof( struct V_42 ) ;
V_18 /= 512 ;
if ( V_18 > V_122 -> V_96 )
V_18 = V_122 -> V_96 ;
V_18 = V_18 ? V_18 * 512 : V_114 ;
F_170 ( V_24 , V_3 -> V_109 , V_18 ) ;
if ( V_10 -> V_253 == 0 ) {
V_10 -> V_203 = F_133 ( V_122 -> V_254 ) ;
V_249 = F_162 ( V_10 ) ;
}
V_65:
F_78 ( & V_10 -> V_155 , V_61 ) ;
F_135 ( V_10 ) ;
if ( V_249 ) {
F_49 ( & V_111 ) ;
F_21 ( & V_111 , V_249 ) ;
F_50 ( & V_111 ) ;
}
}
void
F_167 ( struct V_23 * V_24 )
{
V_24 -> V_79 = 1 ;
V_24 -> V_160 = V_24 -> V_162 / 2 ;
V_24 -> V_206 = V_24 -> V_162 ;
}
void
F_172 ( struct V_9 * V_10 )
{
struct V_23 * * V_24 , * * V_246 ;
V_10 -> V_140 = V_241 ;
V_10 -> V_142 = V_242 ;
V_10 -> V_113 = 0 ;
V_24 = V_10 -> V_73 ;
V_246 = V_24 + V_10 -> V_76 ;
for (; V_24 < V_246 && * V_24 ; V_24 ++ )
F_167 ( * V_24 ) ;
}
void
F_173 ( struct V_9 * V_10 , struct V_58 * V_58 )
{
if ( V_58 == NULL )
return;
V_58 -> V_115 = 0 ;
F_131 ( V_210 , & V_58 -> V_101 -> V_211 ) ;
if ( V_58 -> V_118 == 0 )
F_127 ( V_10 , V_58 ) ;
}
void
F_174 ( void )
{
struct V_8 * V_16 ;
struct V_9 * V_10 ;
F_76 ( V_152 ) ;
struct V_12 * V_14 ;
struct V_1 * V_3 ;
T_1 V_61 ;
F_77 ( & V_224 . V_155 , V_61 ) ;
F_175 ( & V_224 . V_13 , & V_152 ) ;
F_78 ( & V_224 . V_155 , V_61 ) ;
while ( ! F_31 ( & V_152 ) ) {
V_14 = V_152 . V_64 ;
F_11 ( V_14 ) ;
V_16 = F_10 ( V_14 , struct V_8 , V_13 ) ;
V_10 = V_16 -> V_24 -> V_10 ;
V_3 = V_16 -> V_60 ;
F_77 ( & V_10 -> V_155 , V_61 ) ;
if ( V_16 -> V_58 ) {
V_16 -> V_58 -> V_118 -- ;
F_173 ( V_10 , V_16 -> V_58 ) ;
}
F_28 ( V_16 ) ;
F_78 ( & V_10 -> V_155 , V_61 ) ;
F_136 ( V_3 ) ;
F_135 ( V_10 ) ;
}
}
int T_8
F_176 ( void )
{
void * V_134 ;
V_134 = ( void * ) F_177 ( V_255 | V_256 ) ;
if ( ! V_134 )
return - V_238 ;
V_139 = F_178 ( V_134 ) ;
F_168 ( & V_224 . V_13 ) ;
F_179 ( & V_224 . V_155 ) ;
F_180 ( & V_239 ) ;
V_257 . V_237 = L_30 ;
V_257 . V_232 = F_137 ;
V_257 . V_233 = & V_239 ;
V_257 . V_155 = & V_224 . V_155 ;
return F_151 ( & V_257 ) ;
}
void
F_181 ( void )
{
F_148 ( & V_257 ) ;
F_174 () ;
F_182 ( ( unsigned long ) F_121 ( V_139 ) ) ;
V_139 = NULL ;
}
