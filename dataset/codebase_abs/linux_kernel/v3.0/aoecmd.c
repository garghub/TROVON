static struct V_1 *
F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 ) {
F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
V_3 -> V_5 = F_5 ( V_6 ) ;
}
return V_3 ;
}
static struct V_7 *
F_6 ( struct V_8 * V_9 , int V_10 )
{
struct V_7 * V_11 , * V_12 ;
V_11 = V_9 -> V_13 ;
V_12 = V_11 + V_9 -> V_14 ;
for (; V_11 < V_12 ; V_11 ++ )
if ( V_11 -> V_10 == V_10 )
return V_11 ;
return NULL ;
}
static int
F_7 ( struct V_8 * V_9 )
{
register T_1 V_15 ;
V_15 = V_16 & 0xffff ;
return V_15 |= ( ++ V_9 -> V_17 & 0x7fff ) << 16 ;
}
static int
F_8 ( struct V_18 * V_19 , struct V_8 * V_9 , struct V_20 * V_21 )
{
T_2 V_22 = F_7 ( V_9 ) ;
memcpy ( V_21 -> V_23 , V_9 -> V_24 -> V_25 -> V_26 , sizeof V_21 -> V_23 ) ;
memcpy ( V_21 -> V_27 , V_9 -> V_28 , sizeof V_21 -> V_27 ) ;
V_21 -> type = F_9 ( V_6 ) ;
V_21 -> V_29 = V_30 ;
V_21 -> V_31 = F_10 ( V_19 -> V_32 ) ;
V_21 -> V_33 = V_19 -> V_34 ;
V_21 -> V_35 = V_36 ;
V_21 -> V_10 = F_11 ( V_22 ) ;
return V_22 ;
}
static inline void
F_12 ( struct V_37 * V_38 , T_3 V_39 )
{
V_38 -> V_40 = V_39 ;
V_38 -> V_41 = V_39 >>= 8 ;
V_38 -> V_42 = V_39 >>= 8 ;
V_38 -> V_43 = V_39 >>= 8 ;
V_38 -> V_44 = V_39 >>= 8 ;
V_38 -> V_45 = V_39 >>= 8 ;
}
static void
F_13 ( struct V_8 * V_9 )
{
V_9 -> V_24 ++ ;
if ( V_9 -> V_24 >= & V_9 -> V_46 [ V_47 ] || V_9 -> V_24 -> V_25 == NULL )
V_9 -> V_24 = V_9 -> V_46 ;
if ( V_9 -> V_24 -> V_25 == NULL ) {
F_14 ( V_48 L_1 ) ;
F_15 () ;
}
}
static void
F_16 ( struct V_18 * V_19 , struct V_1 * V_3 )
{
F_17 ( & V_19 -> V_49 , V_3 ) ;
}
static struct V_1 *
F_18 ( struct V_18 * V_19 )
{
struct V_1 * V_3 = F_19 ( & V_19 -> V_49 ) ;
if ( V_3 && F_20 ( & F_21 ( V_3 ) -> V_50 ) == 1 ) {
F_22 ( V_3 , & V_19 -> V_49 ) ;
return V_3 ;
}
if ( F_23 ( & V_19 -> V_49 ) < V_51 &&
( V_3 = F_1 ( V_52 ) ) )
return V_3 ;
return NULL ;
}
static struct V_7 *
F_24 ( struct V_18 * V_19 )
{
struct V_7 * V_11 , * V_12 , * V_53 ;
struct V_8 * * V_9 ;
struct V_1 * V_3 ;
if ( V_19 -> V_54 [ 0 ] == NULL ) {
F_14 ( V_55 L_2 ) ;
return NULL ;
}
V_9 = V_19 -> V_56 ;
V_9 ++ ;
if ( V_9 >= & V_19 -> V_54 [ V_57 ] || ! * V_9 )
V_9 = V_19 -> V_54 ;
for (; ; ) {
if ( ( * V_9 ) -> V_58 < ( * V_9 ) -> V_59
&& V_9 != V_19 -> V_60
&& ( * V_9 ) -> V_24 -> V_25 ) {
V_53 = NULL ;
V_11 = ( * V_9 ) -> V_13 ;
V_12 = V_11 + ( * V_9 ) -> V_14 ;
for (; V_11 < V_12 ; V_11 ++ ) {
if ( V_11 -> V_10 != V_61 )
continue;
V_3 = V_11 -> V_3 ;
if ( ! V_3
&& ! ( V_11 -> V_3 = V_3 = F_1 ( V_52 ) ) )
continue;
if ( F_20 ( & F_21 ( V_3 ) -> V_50 )
!= 1 ) {
if ( ! V_53 )
V_53 = V_11 ;
continue;
}
V_62: F_21 ( V_3 ) -> V_63 = V_3 -> V_64 = 0 ;
F_25 ( V_3 , 0 ) ;
V_19 -> V_56 = V_9 ;
F_13 ( * V_9 ) ;
return V_11 ;
}
V_11 = V_53 ;
if ( V_11 == NULL ) {
F_14 ( V_55
L_3 ,
L_4 ) ;
V_19 -> V_65 |= V_66 ;
return NULL ;
}
V_3 = F_18 ( V_19 ) ;
if ( V_3 ) {
F_16 ( V_19 , V_11 -> V_3 ) ;
V_11 -> V_3 = V_3 ;
goto V_62;
}
( * V_9 ) -> V_50 ++ ;
if ( ( * V_9 ) -> V_58 == 0 )
V_19 -> V_65 |= V_66 ;
}
if ( V_9 == V_19 -> V_56 )
break;
V_9 ++ ;
if ( V_9 >= & V_19 -> V_54 [ V_57 ] || ! * V_9 )
V_9 = V_19 -> V_54 ;
}
return NULL ;
}
static int
F_26 ( struct V_18 * V_19 )
{
struct V_7 * V_11 ;
struct V_20 * V_21 ;
struct V_37 * V_38 ;
struct V_67 * V_67 ;
struct V_68 * V_69 ;
struct V_8 * V_9 ;
struct V_1 * V_3 ;
T_1 V_70 ;
char V_71 , V_72 ;
V_71 = 0x10 ;
V_72 = 0x4 ;
V_11 = F_24 ( V_19 ) ;
if ( V_11 == NULL )
return 0 ;
V_9 = * V_19 -> V_56 ;
V_67 = V_19 -> V_73 ;
V_69 = V_67 -> V_69 ;
V_70 = V_9 -> V_24 -> V_74 ;
if ( V_70 == 0 )
V_70 = V_75 ;
if ( V_70 > V_67 -> V_76 )
V_70 = V_67 -> V_76 ;
V_3 = V_11 -> V_3 ;
V_21 = (struct V_20 * ) F_27 ( V_3 ) ;
V_38 = (struct V_37 * ) ( V_21 + 1 ) ;
F_28 ( V_3 , sizeof *V_21 + sizeof *V_38 ) ;
memset ( V_21 , 0 , V_3 -> V_2 ) ;
V_11 -> V_10 = F_8 ( V_19 , V_9 , V_21 ) ;
V_9 -> V_58 ++ ;
V_11 -> V_77 = 0 ;
V_11 -> V_67 = V_67 ;
V_11 -> V_78 = F_29 ( V_69 -> V_79 ) + V_67 -> V_80 ;
V_11 -> V_70 = V_70 ;
V_11 -> V_39 = V_67 -> V_81 ;
V_38 -> V_82 = V_70 >> 9 ;
F_12 ( V_38 , V_67 -> V_81 ) ;
if ( V_19 -> V_65 & V_83 ) {
V_38 -> V_84 |= V_85 ;
} else {
V_72 = 0 ;
V_38 -> V_43 &= 0x0f ;
V_38 -> V_43 |= 0xe0 ;
}
if ( F_30 ( V_67 -> V_86 ) == V_87 ) {
F_31 ( V_3 , 0 , V_69 -> V_79 , V_67 -> V_80 , V_70 ) ;
V_38 -> V_84 |= V_88 ;
V_3 -> V_2 += V_70 ;
V_3 -> V_64 = V_70 ;
V_9 -> V_89 ++ ;
} else {
V_9 -> V_90 ++ ;
V_71 = 0 ;
}
V_38 -> V_91 = V_92 | V_71 | V_72 ;
V_67 -> V_93 += 1 ;
V_67 -> V_80 += V_70 ;
V_67 -> V_76 -= V_70 ;
V_67 -> V_94 -= V_70 ;
V_67 -> V_81 += V_70 >> 9 ;
if ( V_67 -> V_94 == 0 ) {
V_19 -> V_73 = NULL ;
} else if ( V_67 -> V_76 == 0 ) {
V_67 -> V_69 = ++ V_69 ;
V_67 -> V_76 = V_69 -> V_95 ;
F_32 ( V_67 -> V_76 == 0 ) ;
V_67 -> V_80 = V_69 -> V_96 ;
}
V_3 -> V_97 = V_9 -> V_24 -> V_25 ;
V_3 = F_33 ( V_3 , V_4 ) ;
if ( V_3 )
F_17 ( & V_19 -> V_98 , V_3 ) ;
return 1 ;
}
static void
F_34 ( T_4 V_32 , unsigned char V_34 , struct V_99 * V_100 )
{
struct V_20 * V_21 ;
struct V_101 * V_102 ;
struct V_1 * V_3 ;
struct V_103 * V_24 ;
F_35 () ;
F_36 (&init_net, ifp) {
F_37 ( V_24 ) ;
if ( ! F_38 ( V_24 ) )
goto V_104;
V_3 = F_1 ( sizeof *V_21 + sizeof *V_102 ) ;
if ( V_3 == NULL ) {
F_14 ( V_48 L_5 ) ;
goto V_104;
}
F_28 ( V_3 , sizeof *V_21 + sizeof *V_102 ) ;
V_3 -> V_97 = V_24 ;
F_17 ( V_100 , V_3 ) ;
V_21 = (struct V_20 * ) F_27 ( V_3 ) ;
memset ( V_21 , 0 , sizeof *V_21 + sizeof *V_102 ) ;
memset ( V_21 -> V_27 , 0xff , sizeof V_21 -> V_27 ) ;
memcpy ( V_21 -> V_23 , V_24 -> V_26 , sizeof V_21 -> V_23 ) ;
V_21 -> type = F_9 ( V_6 ) ;
V_21 -> V_29 = V_30 ;
V_21 -> V_31 = F_10 ( V_32 ) ;
V_21 -> V_33 = V_34 ;
V_21 -> V_35 = V_105 ;
V_104:
F_39 ( V_24 ) ;
}
F_40 () ;
}
static void
F_41 ( struct V_18 * V_19 , struct V_8 * V_9 , struct V_7 * V_11 )
{
struct V_1 * V_3 ;
struct V_20 * V_21 ;
struct V_37 * V_38 ;
char V_67 [ 128 ] ;
T_2 V_15 ;
F_13 ( V_9 ) ;
V_15 = F_7 ( V_9 ) ;
V_3 = V_11 -> V_3 ;
V_21 = (struct V_20 * ) F_27 ( V_3 ) ;
V_38 = (struct V_37 * ) ( V_21 + 1 ) ;
snprintf ( V_67 , sizeof V_67 ,
L_6 ,
L_7 , V_19 -> V_32 , V_19 -> V_34 , V_11 -> V_10 , V_16 , V_15 ,
V_21 -> V_23 , V_21 -> V_27 , V_9 -> V_58 ) ;
F_42 ( V_67 ) ;
V_11 -> V_10 = V_15 ;
V_21 -> V_10 = F_11 ( V_15 ) ;
memcpy ( V_21 -> V_27 , V_9 -> V_28 , sizeof V_21 -> V_27 ) ;
memcpy ( V_21 -> V_23 , V_9 -> V_24 -> V_25 -> V_26 , sizeof V_21 -> V_23 ) ;
switch ( V_38 -> V_91 ) {
default:
break;
case V_92 :
case V_106 :
case V_107 :
case V_108 :
F_12 ( V_38 , V_11 -> V_39 ) ;
V_15 = V_11 -> V_70 ;
if ( V_15 > V_75 )
V_15 = V_75 ;
V_38 -> V_82 = V_15 >> 9 ;
if ( V_38 -> V_84 & V_88 ) {
F_31 ( V_3 , 0 , F_43 ( V_11 -> V_78 ) ,
F_44 ( V_11 -> V_78 ) , V_15 ) ;
V_3 -> V_2 = sizeof *V_21 + sizeof *V_38 + V_15 ;
V_3 -> V_64 = V_15 ;
}
}
V_3 -> V_97 = V_9 -> V_24 -> V_25 ;
V_3 = F_33 ( V_3 , V_4 ) ;
if ( V_3 == NULL )
return;
F_17 ( & V_19 -> V_98 , V_3 ) ;
}
static int
F_45 ( int V_10 )
{
int V_15 ;
V_15 = V_16 & 0xffff ;
V_15 -= V_10 & 0xffff ;
if ( V_15 < 0 )
V_15 += 1 << 16 ;
return V_15 ;
}
static struct V_109 *
F_46 ( struct V_8 * V_9 , struct V_103 * V_25 )
{
struct V_109 * V_110 , * V_12 ;
V_110 = V_9 -> V_46 ;
V_12 = V_110 + V_47 ;
for (; V_110 < V_12 ; V_110 ++ )
if ( V_110 -> V_25 == V_25 )
return V_110 ;
return NULL ;
}
static struct V_109 *
F_47 ( struct V_8 * V_9 , struct V_103 * V_25 )
{
struct V_109 * V_110 ;
V_110 = F_46 ( V_9 , NULL ) ;
if ( ! V_110 )
return NULL ;
V_110 -> V_25 = V_25 ;
V_110 -> V_74 = V_75 ;
V_110 -> V_111 = 0 ;
V_110 -> V_112 = 0 ;
return V_110 ;
}
static void
F_48 ( struct V_8 * V_9 , struct V_109 * V_24 )
{
struct V_109 * V_12 ;
T_1 V_15 ;
V_12 = V_9 -> V_46 + V_47 - 1 ;
V_15 = ( V_12 - V_24 ) * sizeof *V_24 ;
memmove ( V_24 , V_24 + 1 , V_15 ) ;
V_12 -> V_25 = NULL ;
}
static int
F_49 ( struct V_18 * V_19 )
{
struct V_7 * V_11 , * V_12 , * V_113 ;
struct V_1 * V_3 ;
struct V_8 * V_114 = * V_19 -> V_60 ;
V_11 = V_114 -> V_13 ;
V_12 = V_11 + V_114 -> V_14 ;
for (; V_11 < V_12 ; V_11 ++ ) {
if ( V_11 -> V_10 == V_61 )
continue;
V_113 = F_24 ( V_19 ) ;
if ( ! V_113 )
return 0 ;
V_3 = V_113 -> V_3 ;
* V_113 = * V_11 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_10 = V_61 ;
V_113 -> V_77 = 0 ;
V_114 -> V_58 -- ;
( * V_19 -> V_56 ) -> V_58 ++ ;
F_41 ( V_19 , * V_19 -> V_56 , V_113 ) ;
}
memset ( V_114 -> V_46 , 0 , sizeof V_114 -> V_46 ) ;
V_19 -> V_60 = NULL ;
return 1 ;
}
static inline unsigned char
F_50 ( unsigned char * V_115 ) {
struct V_20 * V_21 ;
struct V_37 * V_38 ;
V_21 = (struct V_20 * ) V_115 ;
V_38 = (struct V_37 * ) ( V_21 + 1 ) ;
return V_38 -> V_82 ;
}
static void
F_51 ( T_1 V_116 )
{
struct V_99 V_100 ;
struct V_18 * V_19 ;
struct V_8 * V_9 , * * V_117 , * * V_118 ;
struct V_109 * V_24 ;
struct V_7 * V_11 , * V_12 ;
register long V_119 ;
T_1 V_65 , V_15 ;
V_19 = (struct V_18 * ) V_116 ;
V_119 = V_19 -> V_120 ;
V_119 += V_119 >> 1 ;
F_52 ( & V_19 -> V_121 , V_65 ) ;
if ( V_19 -> V_65 & V_122 ) {
F_53 ( & V_19 -> V_121 , V_65 ) ;
return;
}
V_117 = V_19 -> V_54 ;
V_118 = V_117 + V_57 ;
for (; V_117 < V_118 && * V_117 ; V_117 ++ ) {
V_9 = * V_117 ;
V_11 = V_9 -> V_13 ;
V_12 = V_11 + V_9 -> V_14 ;
for (; V_11 < V_12 ; V_11 ++ ) {
if ( V_11 -> V_10 == V_61
|| F_45 ( V_11 -> V_10 ) < V_119 )
continue;
V_15 = V_11 -> V_77 += V_119 ;
V_15 /= V_123 ;
if ( V_15 > V_124 ) {
F_54 ( V_19 ) ;
break;
}
if ( V_15 > V_125
&& ( V_117 != V_19 -> V_54 || V_19 -> V_54 [ 1 ] ) )
V_19 -> V_60 = V_117 ;
if ( V_9 -> V_58 == V_9 -> V_59 ) {
if ( V_9 -> V_59 > 1 )
V_9 -> V_59 -- ;
V_9 -> V_126 = V_16 ;
}
V_24 = F_46 ( V_9 , V_11 -> V_3 -> V_97 ) ;
if ( V_24 && ++ V_24 -> V_111 > ( V_9 -> V_14 << 1 )
&& ( V_24 != V_9 -> V_46 || V_9 -> V_46 [ 1 ] . V_25 ) ) {
F_48 ( V_9 , V_24 ) ;
V_24 = NULL ;
}
if ( F_50 ( F_27 ( V_11 -> V_3 ) ) > V_75 / 512
&& V_24 && ++ V_24 -> V_112 > ( V_9 -> V_14 << 1 )
&& V_24 -> V_74 != V_75 ) {
F_14 ( V_48
L_8
L_9
L_10
L_11 ,
V_19 -> V_32 , V_19 -> V_34 ,
V_24 -> V_25 -> V_127 , V_9 -> V_28 ,
V_75 ) ;
V_24 -> V_74 = 0 ;
}
F_41 ( V_19 , V_9 , V_11 ) ;
}
if ( V_9 -> V_58 == V_9 -> V_59
&& V_9 -> V_59 < V_9 -> V_14
&& ( V_16 - V_9 -> V_126 ) / V_123 > 10 ) {
V_9 -> V_59 ++ ;
V_9 -> V_126 = V_16 ;
}
}
if ( ! F_55 ( & V_19 -> V_98 ) ) {
V_15 = V_19 -> V_120 <<= 1 ;
if ( V_15 > V_128 )
V_19 -> V_120 = V_128 ;
}
if ( V_19 -> V_65 & V_66 || V_19 -> V_60 ) {
V_19 -> V_65 &= ~ V_66 ;
F_56 ( V_19 ) ;
}
F_57 ( & V_100 ) ;
F_58 ( & V_19 -> V_98 , & V_100 ) ;
V_19 -> V_129 . V_130 = V_16 + V_131 ;
F_59 ( & V_19 -> V_129 ) ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
F_60 ( & V_100 ) ;
}
void
F_56 ( struct V_18 * V_19 )
{
struct V_67 * V_67 ;
V_132:
if ( V_19 -> V_60 && ! F_49 ( V_19 ) )
return;
if ( V_19 -> V_73 == NULL ) {
if ( F_61 ( & V_19 -> V_133 ) )
return;
V_67 = F_62 ( V_19 -> V_133 . V_134 , struct V_67 , V_135 ) ;
F_63 ( V_19 -> V_133 . V_134 ) ;
V_19 -> V_73 = V_67 ;
}
if ( F_26 ( V_19 ) )
goto V_132;
}
void
F_64 ( struct V_136 * V_137 )
{
struct V_18 * V_19 = F_62 ( V_137 , struct V_18 , V_137 ) ;
if ( V_19 -> V_65 & V_138 )
F_65 ( V_19 ) ;
if ( V_19 -> V_65 & V_139 ) {
struct V_140 * V_141 ;
unsigned long V_65 ;
T_5 V_142 ;
V_142 = F_66 ( V_19 -> V_143 ) ;
V_141 = F_67 ( V_19 -> V_143 , 0 ) ;
if ( V_141 ) {
F_68 ( & V_141 -> V_144 -> V_145 ) ;
F_69 ( V_141 -> V_144 , ( V_146 ) V_142 << 9 ) ;
F_70 ( & V_141 -> V_144 -> V_145 ) ;
F_71 ( V_141 ) ;
}
F_52 ( & V_19 -> V_121 , V_65 ) ;
V_19 -> V_65 |= V_147 ;
V_19 -> V_65 &= ~ V_139 ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
}
}
static void
F_72 ( struct V_18 * V_19 , struct V_8 * V_9 , unsigned char * V_148 )
{
T_5 V_142 ;
T_6 V_15 ;
V_15 = F_73 ( & V_148 [ 83 << 1 ] ) ;
V_15 |= F_73 ( & V_148 [ 86 << 1 ] ) ;
if ( V_15 & ( 1 << 10 ) ) {
V_19 -> V_65 |= V_83 ;
V_142 = F_74 ( & V_148 [ 100 << 1 ] ) ;
V_19 -> V_149 . V_150 = V_142 ;
V_19 -> V_149 . V_150 /= ( 255 * 63 ) ;
V_19 -> V_149 . V_151 = 255 ;
V_19 -> V_149 . V_152 = 63 ;
} else {
V_19 -> V_65 &= ~ V_83 ;
V_142 = F_75 ( & V_148 [ 60 << 1 ] ) ;
V_19 -> V_149 . V_150 = F_73 ( & V_148 [ 54 << 1 ] ) ;
V_19 -> V_149 . V_151 = F_73 ( & V_148 [ 55 << 1 ] ) ;
V_19 -> V_149 . V_152 = F_73 ( & V_148 [ 56 << 1 ] ) ;
}
if ( V_19 -> V_142 != V_142 )
F_14 ( V_48
L_12 ,
V_9 -> V_28 ,
V_19 -> V_32 , V_19 -> V_34 ,
V_19 -> V_153 , ( long long ) V_142 ) ;
V_19 -> V_142 = V_142 ;
V_19 -> V_149 . V_154 = 0 ;
if ( V_19 -> V_65 & ( V_138 | V_139 ) )
return;
if ( V_19 -> V_143 != NULL ) {
F_76 ( V_19 -> V_143 , V_142 ) ;
V_19 -> V_65 |= V_139 ;
} else
V_19 -> V_65 |= V_138 ;
F_77 ( & V_19 -> V_137 ) ;
}
static void
F_78 ( struct V_18 * V_19 , int V_155 )
{
register long V_15 ;
V_15 = V_155 ;
if ( V_15 < 0 ) {
V_15 = - V_155 ;
if ( V_15 < V_156 )
V_15 = V_156 ;
else if ( V_15 > V_128 )
V_15 = V_128 ;
V_19 -> V_157 += ( V_15 - V_19 -> V_157 ) >> 1 ;
} else if ( V_15 < V_19 -> V_157 )
V_15 = V_19 -> V_157 ;
else if ( V_15 > V_128 )
V_15 = V_128 ;
V_15 -= V_19 -> V_120 ;
V_19 -> V_120 += V_15 >> 2 ;
}
static struct V_8 *
F_79 ( struct V_18 * V_19 , char * V_28 )
{
struct V_8 * * V_9 , * * V_12 ;
V_9 = V_19 -> V_54 ;
V_12 = V_9 + V_57 ;
for (; V_9 < V_12 && * V_9 ; V_9 ++ )
if ( memcmp ( ( * V_9 ) -> V_28 , V_28 , sizeof( ( * V_9 ) -> V_28 ) ) == 0 )
return * V_9 ;
return NULL ;
}
static inline void
F_80 ( struct V_158 * V_159 , struct V_86 * V_86 , T_1 V_160 , T_3 V_81 )
{
unsigned long V_161 = V_86 -> V_162 >> 9 ;
const int V_163 = F_30 ( V_86 ) ;
struct V_164 * V_165 ;
int V_166 ;
V_166 = F_81 () ;
V_165 = F_82 ( V_159 , V_81 ) ;
F_83 ( V_166 , V_165 , V_167 [ V_163 ] ) ;
F_84 ( V_166 , V_165 , V_168 [ V_163 ] , V_160 ) ;
F_84 ( V_166 , V_165 , V_152 [ V_163 ] , V_161 ) ;
F_84 ( V_166 , V_165 , V_169 , V_160 ) ;
F_85 () ;
}
void
F_86 ( struct V_1 * V_3 )
{
struct V_99 V_100 ;
struct V_18 * V_19 ;
struct V_20 * V_170 , * V_171 ;
struct V_37 * V_172 , * V_173 ;
struct V_7 * V_11 ;
struct V_67 * V_67 ;
struct V_8 * V_9 ;
struct V_109 * V_24 ;
register long V_15 ;
T_1 V_65 ;
char V_174 [ 128 ] ;
T_6 V_32 ;
V_170 = (struct V_20 * ) F_27 ( V_3 ) ;
V_32 = F_87 ( & V_170 -> V_31 ) ;
V_19 = F_88 ( V_32 , V_170 -> V_33 ) ;
if ( V_19 == NULL ) {
snprintf ( V_174 , sizeof V_174 , L_13
L_14 ,
V_32 , V_170 -> V_33 ) ;
F_42 ( V_174 ) ;
return;
}
F_52 ( & V_19 -> V_121 , V_65 ) ;
V_15 = F_89 ( & V_170 -> V_10 ) ;
V_9 = F_79 ( V_19 , V_170 -> V_23 ) ;
if ( V_9 == NULL ) {
F_14 ( V_48 L_15 ,
V_19 -> V_32 , V_19 -> V_34 , V_170 -> V_23 ) ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
return;
}
V_11 = F_6 ( V_9 , V_15 ) ;
if ( V_11 == NULL ) {
F_78 ( V_19 , - F_45 ( V_15 ) ) ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
snprintf ( V_174 , sizeof V_174 ,
L_16 ,
L_17 ,
F_87 ( & V_170 -> V_31 ) ,
V_170 -> V_33 ,
F_89 ( & V_170 -> V_10 ) ,
V_16 ) ;
F_42 ( V_174 ) ;
return;
}
F_78 ( V_19 , F_45 ( V_11 -> V_10 ) ) ;
V_172 = (struct V_37 * ) ( V_170 + 1 ) ;
V_171 = (struct V_20 * ) F_27 ( V_11 -> V_3 ) ;
V_173 = (struct V_37 * ) ( V_171 + 1 ) ;
V_67 = V_11 -> V_67 ;
if ( V_172 -> V_91 & 0xa9 ) {
F_14 ( V_55
L_18 ,
V_173 -> V_91 , V_172 -> V_91 ,
V_19 -> V_32 , V_19 -> V_34 ) ;
if ( V_67 )
V_67 -> V_65 |= V_175 ;
} else {
if ( V_19 -> V_60 && V_9 == * V_19 -> V_60 )
V_19 -> V_60 = NULL ;
V_15 = V_173 -> V_82 << 9 ;
switch ( V_173 -> V_91 ) {
case V_92 :
case V_106 :
if ( V_3 -> V_2 - sizeof *V_170 - sizeof *V_172 < V_15 ) {
F_14 ( V_55
L_19 ,
L_20 , V_3 -> V_2 , V_15 ) ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
return;
}
memcpy ( V_11 -> V_78 , V_172 + 1 , V_15 ) ;
case V_107 :
case V_108 :
V_24 = F_46 ( V_9 , V_3 -> V_97 ) ;
if ( V_24 ) {
V_24 -> V_111 = 0 ;
if ( V_15 > V_75 )
V_24 -> V_112 = 0 ;
}
if ( V_11 -> V_70 -= V_15 ) {
V_11 -> V_39 += V_15 >> 9 ;
V_11 -> V_78 += V_15 ;
F_41 ( V_19 , V_9 , V_11 ) ;
goto V_176;
}
break;
case V_177 :
if ( V_3 -> V_2 - sizeof *V_170 - sizeof *V_172 < 512 ) {
F_14 ( V_48
L_21 ,
V_3 -> V_2 ) ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
return;
}
F_72 ( V_19 , V_9 , ( char * ) ( V_172 + 1 ) ) ;
break;
default:
F_14 ( V_48
L_22 ,
V_173 -> V_91 ,
F_87 ( & V_170 -> V_31 ) ,
V_170 -> V_33 ) ;
}
}
if ( V_67 && -- V_67 -> V_93 == 0 && V_67 -> V_94 == 0 ) {
F_80 ( V_19 -> V_143 , V_67 -> V_86 , V_16 - V_67 -> V_178 , V_67 -> V_81 ) ;
if ( V_67 -> V_65 & V_175 )
F_90 ( V_67 -> V_86 , - V_179 ) ;
else {
F_91 ( V_67 -> V_86 ) ;
F_90 ( V_67 -> V_86 , 0 ) ;
}
F_92 ( V_67 , V_19 -> V_180 ) ;
}
V_11 -> V_67 = NULL ;
V_11 -> V_10 = V_61 ;
V_9 -> V_58 -- ;
F_56 ( V_19 ) ;
V_176:
F_57 ( & V_100 ) ;
F_58 ( & V_19 -> V_98 , & V_100 ) ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
F_60 ( & V_100 ) ;
}
void
F_93 ( T_4 V_32 , unsigned char V_34 )
{
struct V_99 V_100 ;
F_57 ( & V_100 ) ;
F_34 ( V_32 , V_34 , & V_100 ) ;
F_60 ( & V_100 ) ;
}
struct V_1 *
F_94 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_37 * V_38 ;
struct V_7 * V_11 ;
struct V_1 * V_3 ;
struct V_8 * V_9 ;
V_11 = F_24 ( V_19 ) ;
if ( V_11 == NULL )
return NULL ;
V_9 = * V_19 -> V_56 ;
V_3 = V_11 -> V_3 ;
V_21 = (struct V_20 * ) F_27 ( V_3 ) ;
V_38 = (struct V_37 * ) ( V_21 + 1 ) ;
F_28 ( V_3 , sizeof *V_21 + sizeof *V_38 ) ;
memset ( V_21 , 0 , V_3 -> V_2 ) ;
V_11 -> V_10 = F_8 ( V_19 , V_9 , V_21 ) ;
V_9 -> V_58 ++ ;
V_11 -> V_77 = 0 ;
V_38 -> V_82 = 1 ;
V_38 -> V_91 = V_177 ;
V_38 -> V_43 = 0xa0 ;
V_3 -> V_97 = V_9 -> V_24 -> V_25 ;
V_19 -> V_120 = V_128 ;
V_19 -> V_129 . V_181 = F_51 ;
return F_33 ( V_3 , V_4 ) ;
}
static struct V_8 *
F_95 ( struct V_18 * V_19 , char * V_28 , T_1 V_14 )
{
struct V_8 * V_9 , * * V_117 , * * V_118 ;
struct V_7 * V_11 , * V_12 ;
V_117 = V_19 -> V_54 ;
V_118 = V_117 + V_57 ;
for (; V_117 < V_118 && * V_117 ; V_117 ++ )
;
if ( V_117 == V_118 ) {
F_14 ( V_48
L_23 ) ;
return NULL ;
}
V_9 = F_96 ( 1 , sizeof *V_9 , V_4 ) ;
V_11 = F_96 ( V_14 , sizeof *V_11 , V_4 ) ;
if ( ! V_9 || ! V_11 ) {
F_97 ( V_11 ) ;
F_97 ( V_9 ) ;
F_14 ( V_48 L_24 ) ;
return NULL ;
}
V_9 -> V_14 = V_14 ;
V_9 -> V_13 = V_11 ;
V_12 = V_11 + V_14 ;
for (; V_11 < V_12 ; V_11 ++ )
V_11 -> V_10 = V_61 ;
memcpy ( V_9 -> V_28 , V_28 , sizeof V_9 -> V_28 ) ;
V_9 -> V_24 = V_9 -> V_46 ;
V_9 -> V_59 = V_9 -> V_14 ;
return * V_117 = V_9 ;
}
void
F_98 ( struct V_1 * V_3 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_101 * V_102 ;
struct V_8 * V_9 ;
struct V_109 * V_24 ;
T_1 V_65 , V_182 , V_32 ;
struct V_1 * V_183 ;
T_6 V_15 ;
V_21 = (struct V_20 * ) F_27 ( V_3 ) ;
V_102 = (struct V_101 * ) ( V_21 + 1 ) ;
V_32 = F_87 ( & V_21 -> V_31 ) ;
if ( V_32 == 0xfff ) {
F_14 ( V_55 L_25
L_26 ) ;
return;
}
V_182 = F_99 ( V_32 , V_21 -> V_33 ) ;
if ( V_182 * V_184 + V_184 > V_185 ) {
F_14 ( V_48 L_27 ,
V_32 , ( int ) V_21 -> V_33 ) ;
return;
}
V_15 = F_100 ( V_102 -> V_186 ) ;
if ( V_15 > V_187 )
V_15 = V_187 ;
V_19 = F_101 ( V_182 ) ;
if ( V_19 == NULL ) {
F_14 ( V_48 L_28 ) ;
return;
}
F_52 ( & V_19 -> V_121 , V_65 ) ;
V_9 = F_79 ( V_19 , V_21 -> V_23 ) ;
if ( ! V_9 ) {
V_9 = F_95 ( V_19 , V_21 -> V_23 , V_15 ) ;
if ( ! V_9 ) {
F_53 ( & V_19 -> V_121 , V_65 ) ;
return;
}
}
V_24 = F_46 ( V_9 , V_3 -> V_97 ) ;
if ( ! V_24 ) {
V_24 = F_47 ( V_9 , V_3 -> V_97 ) ;
if ( ! V_24 ) {
F_14 ( V_48
L_29
L_30 ) ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
return;
}
}
if ( V_24 -> V_74 ) {
V_15 = V_24 -> V_25 -> V_188 ;
V_15 -= sizeof ( struct V_20 ) + sizeof ( struct V_37 ) ;
V_15 /= 512 ;
if ( V_15 > V_102 -> V_82 )
V_15 = V_102 -> V_82 ;
V_15 = V_15 ? V_15 * 512 : V_75 ;
if ( V_15 != V_24 -> V_74 ) {
F_14 ( V_48
L_31 ,
V_19 -> V_32 , V_19 -> V_34 , V_15 ,
L_32 , V_24 -> V_25 -> V_127 ,
V_9 -> V_28 ) ;
V_24 -> V_74 = V_15 ;
}
}
if ( V_19 -> V_189 ) {
F_53 ( & V_19 -> V_121 , V_65 ) ;
return;
}
V_19 -> V_153 = F_100 ( V_102 -> V_190 ) ;
V_183 = F_94 ( V_19 ) ;
F_53 ( & V_19 -> V_121 , V_65 ) ;
if ( V_183 ) {
struct V_99 V_100 ;
F_57 ( & V_100 ) ;
F_17 ( & V_100 , V_183 ) ;
F_60 ( & V_100 ) ;
}
}
void
F_102 ( struct V_18 * V_19 )
{
struct V_8 * * V_9 , * * V_118 ;
struct V_109 * V_110 , * V_12 ;
V_19 -> V_157 = V_156 ;
V_9 = V_19 -> V_54 ;
V_118 = V_9 + V_57 ;
for (; V_9 < V_118 && * V_9 ; V_9 ++ ) {
( * V_9 ) -> V_59 = ( * V_9 ) -> V_14 ;
V_110 = ( * V_9 ) -> V_46 ;
V_12 = V_110 + V_47 ;
for (; V_110 < V_12 ; V_110 ++ ) {
V_110 -> V_112 = 0 ;
V_110 -> V_111 = 0 ;
V_110 -> V_74 = V_75 ;
}
}
}
