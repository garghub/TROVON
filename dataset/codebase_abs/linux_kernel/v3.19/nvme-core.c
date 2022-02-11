static inline void F_1 ( void )
{
F_2 ( sizeof( struct V_1 ) != 64 ) ;
F_2 ( sizeof( struct V_2 ) != 64 ) ;
F_2 ( sizeof( struct V_3 ) != 64 ) ;
F_2 ( sizeof( struct V_4 ) != 64 ) ;
F_2 ( sizeof( struct V_5 ) != 64 ) ;
F_2 ( sizeof( struct V_6 ) != 64 ) ;
F_2 ( sizeof( struct V_7 ) != 64 ) ;
F_2 ( sizeof( struct V_8 ) != 64 ) ;
F_2 ( sizeof( struct V_9 ) != 4096 ) ;
F_2 ( sizeof( struct V_10 ) != 4096 ) ;
F_2 ( sizeof( struct V_11 ) != 64 ) ;
F_2 ( sizeof( struct V_12 ) != 512 ) ;
}
static int F_3 ( struct V_13 * V_14 , void * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = V_15 ;
struct V_19 * V_20 = V_18 -> V_21 [ 0 ] ;
F_4 ( V_20 -> V_14 ) ;
V_20 -> V_14 = V_14 ;
V_14 -> V_22 = V_20 ;
return 0 ;
}
static int F_5 ( void * V_15 , struct V_23 * V_24 ,
unsigned int V_16 , unsigned int V_25 ,
unsigned int V_26 )
{
struct V_17 * V_18 = V_15 ;
struct V_27 * V_28 = F_6 ( V_24 ) ;
struct V_19 * V_20 = V_18 -> V_21 [ 0 ] ;
F_7 ( ! V_20 ) ;
V_28 -> V_20 = V_20 ;
return 0 ;
}
static void F_8 ( struct V_13 * V_14 , unsigned int V_16 )
{
struct V_19 * V_20 = V_14 -> V_22 ;
V_20 -> V_14 = NULL ;
}
static int F_9 ( struct V_13 * V_14 , void * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = V_15 ;
struct V_19 * V_20 = V_18 -> V_21 [
( V_16 % V_18 -> V_29 ) + 1 ] ;
if ( ! V_20 -> V_14 )
V_20 -> V_14 = V_14 ;
F_4 ( V_20 -> V_14 -> V_30 != V_14 -> V_30 ) ;
V_14 -> V_22 = V_20 ;
return 0 ;
}
static int F_10 ( void * V_15 , struct V_23 * V_24 ,
unsigned int V_16 , unsigned int V_25 ,
unsigned int V_26 )
{
struct V_17 * V_18 = V_15 ;
struct V_27 * V_28 = F_6 ( V_24 ) ;
struct V_19 * V_20 = V_18 -> V_21 [ V_16 + 1 ] ;
F_7 ( ! V_20 ) ;
V_28 -> V_20 = V_20 ;
return 0 ;
}
static void F_11 ( struct V_27 * V_28 , void * V_31 ,
T_1 V_32 )
{
V_28 -> V_33 = V_32 ;
V_28 -> V_31 = V_31 ;
V_28 -> V_34 = 0 ;
F_12 ( F_13 ( V_28 ) ) ;
}
static void F_14 ( struct V_19 * V_20 , void * V_31 ,
struct V_35 * V_36 )
{
if ( V_31 == V_37 )
return;
if ( V_31 == V_38 ) {
F_15 ( V_20 -> V_39 ,
L_1 ,
V_36 -> V_40 , F_16 ( & V_36 -> V_41 ) ) ;
return;
}
if ( V_31 == V_42 ) {
F_15 ( V_20 -> V_39 ,
L_2 ,
V_36 -> V_40 , F_16 ( & V_36 -> V_41 ) ) ;
return;
}
F_15 ( V_20 -> V_39 , L_3 , V_31 ) ;
}
static void * F_17 ( struct V_27 * V_28 , T_1 * V_33 )
{
void * V_31 ;
if ( V_33 )
* V_33 = V_28 -> V_33 ;
V_31 = V_28 -> V_31 ;
V_28 -> V_33 = F_14 ;
V_28 -> V_31 = V_37 ;
return V_31 ;
}
static void F_18 ( struct V_19 * V_20 , void * V_31 ,
struct V_35 * V_36 )
{
struct V_23 * V_24 = V_31 ;
T_2 V_43 = F_19 ( & V_36 -> V_43 ) ;
T_3 V_44 = F_16 ( & V_36 -> V_44 ) >> 1 ;
if ( V_44 == V_45 || V_44 == V_46 )
++ V_20 -> V_18 -> V_47 ;
if ( V_44 == V_45 )
F_15 ( V_20 -> V_39 ,
L_4 , V_43 ) ;
F_20 ( V_20 -> V_14 , V_24 ) ;
}
static void F_21 ( struct V_19 * V_20 , void * V_31 ,
struct V_35 * V_36 )
{
struct V_23 * V_24 = V_31 ;
T_3 V_44 = F_16 ( & V_36 -> V_44 ) >> 1 ;
T_2 V_43 = F_19 ( & V_36 -> V_43 ) ;
F_20 ( V_20 -> V_14 , V_24 ) ;
F_15 ( V_20 -> V_39 , L_5 , V_44 , V_43 ) ;
++ V_20 -> V_18 -> V_48 ;
}
static void F_22 ( struct V_19 * V_20 , void * V_31 ,
struct V_35 * V_36 )
{
struct V_49 * V_50 = V_31 ;
V_50 -> V_43 = F_19 ( & V_36 -> V_43 ) ;
V_50 -> V_44 = F_16 ( & V_36 -> V_44 ) >> 1 ;
F_23 ( V_50 -> V_51 , & V_50 -> V_52 ) ;
F_20 ( V_20 -> V_14 , V_50 -> V_24 ) ;
}
static inline struct V_27 * F_24 ( struct V_19 * V_20 ,
unsigned int V_53 )
{
struct V_13 * V_14 = V_20 -> V_14 ;
struct V_23 * V_24 = F_25 ( V_14 -> V_30 , V_53 ) ;
return F_6 ( V_24 ) ;
}
static void * F_26 ( struct V_19 * V_20 , int V_53 ,
T_1 * V_33 )
{
struct V_27 * V_28 = F_24 ( V_20 , V_53 ) ;
void * V_31 ;
if ( V_53 >= V_20 -> V_54 ) {
* V_33 = F_14 ;
return V_42 ;
}
if ( V_33 )
* V_33 = V_28 -> V_33 ;
V_31 = V_28 -> V_31 ;
V_28 -> V_33 = F_14 ;
V_28 -> V_31 = V_38 ;
return V_31 ;
}
static int F_27 ( struct V_19 * V_20 , struct V_8 * V_28 )
{
T_3 V_55 = V_20 -> V_56 ;
memcpy ( & V_20 -> V_57 [ V_55 ] , V_28 , sizeof( * V_28 ) ) ;
if ( ++ V_55 == V_20 -> V_54 )
V_55 = 0 ;
F_28 ( V_55 , V_20 -> V_58 ) ;
V_20 -> V_56 = V_55 ;
return 0 ;
}
static int F_29 ( struct V_19 * V_20 , struct V_8 * V_28 )
{
unsigned long V_59 ;
int V_60 ;
F_30 ( & V_20 -> V_61 , V_59 ) ;
V_60 = F_27 ( V_20 , V_28 ) ;
F_31 ( & V_20 -> V_61 , V_59 ) ;
return V_60 ;
}
static T_4 * * F_32 ( struct V_62 * V_63 )
{
return ( ( void * ) V_63 ) + V_63 -> V_64 ;
}
static int F_33 ( unsigned V_65 , struct V_17 * V_18 )
{
unsigned V_66 = F_34 ( V_65 + V_18 -> V_67 , V_18 -> V_67 ) ;
return F_34 ( 8 * V_66 , V_18 -> V_67 - 8 ) ;
}
static struct V_62 *
F_35 ( unsigned V_68 , unsigned V_69 , struct V_17 * V_18 , T_5 V_70 )
{
struct V_62 * V_63 = F_36 ( sizeof( struct V_62 ) +
sizeof( T_4 * ) * F_33 ( V_69 , V_18 ) +
sizeof( struct V_71 ) * V_68 , V_70 ) ;
if ( V_63 ) {
V_63 -> V_64 = F_37 ( struct V_62 , V_72 [ V_68 ] ) ;
V_63 -> V_73 = - 1 ;
V_63 -> V_74 = V_69 ;
V_63 -> V_75 = 0 ;
V_63 -> V_76 = 0ULL ;
}
return V_63 ;
}
void F_38 ( struct V_17 * V_18 , struct V_62 * V_63 )
{
const int V_77 = V_18 -> V_67 / 8 - 1 ;
int V_78 ;
T_4 * * V_79 = F_32 ( V_63 ) ;
T_6 V_80 = V_63 -> V_76 ;
if ( V_63 -> V_73 == 0 )
F_39 ( V_18 -> V_81 , V_79 [ 0 ] , V_80 ) ;
for ( V_78 = 0 ; V_78 < V_63 -> V_73 ; V_78 ++ ) {
T_4 * V_82 = V_79 [ V_78 ] ;
T_6 V_83 = F_40 ( V_82 [ V_77 ] ) ;
F_39 ( V_18 -> V_84 , V_82 , V_80 ) ;
V_80 = V_83 ;
}
F_41 ( V_63 ) ;
}
static int F_42 ( T_3 V_44 )
{
switch ( V_44 & 0x7ff ) {
case V_45 :
return 0 ;
case V_85 :
return - V_86 ;
default:
return - V_87 ;
}
}
static void F_43 ( struct V_19 * V_20 , void * V_31 ,
struct V_35 * V_36 )
{
struct V_62 * V_63 = V_31 ;
struct V_23 * V_24 = V_63 -> V_88 ;
struct V_27 * V_89 = F_6 ( V_24 ) ;
T_3 V_44 = F_16 ( & V_36 -> V_44 ) >> 1 ;
if ( F_44 ( V_44 ) ) {
if ( ! ( V_44 & V_90 || F_45 ( V_24 ) )
&& ( V_91 - V_24 -> V_92 ) < V_24 -> V_93 ) {
unsigned long V_59 ;
F_46 ( V_24 ) ;
F_30 ( V_24 -> V_94 -> V_95 , V_59 ) ;
if ( ! F_47 ( V_24 -> V_94 ) )
F_48 ( V_24 -> V_94 ) ;
F_31 ( V_24 -> V_94 -> V_95 , V_59 ) ;
return;
}
V_24 -> V_96 = F_42 ( V_44 ) ;
} else
V_24 -> V_96 = 0 ;
if ( V_89 -> V_34 )
F_15 ( & V_20 -> V_18 -> V_97 -> V_18 ,
L_6 ,
V_44 ) ;
if ( V_63 -> V_75 )
F_49 ( & V_20 -> V_18 -> V_97 -> V_18 , V_63 -> V_72 , V_63 -> V_75 ,
F_50 ( V_24 ) ? V_98 : V_99 ) ;
F_38 ( V_20 -> V_18 , V_63 ) ;
F_51 ( V_24 ) ;
}
int F_52 ( struct V_17 * V_18 , struct V_62 * V_63 , int V_100 ,
T_5 V_70 )
{
struct V_101 * V_102 ;
int V_74 = V_100 ;
struct V_71 * V_72 = V_63 -> V_72 ;
int V_103 = F_53 ( V_72 ) ;
T_7 V_104 = F_54 ( V_72 ) ;
int V_64 = F_55 ( V_104 ) ;
T_4 * V_82 ;
T_4 * * V_79 = F_32 ( V_63 ) ;
T_6 V_80 ;
int V_66 , V_78 ;
T_2 V_67 = V_18 -> V_67 ;
V_74 -= ( V_67 - V_64 ) ;
if ( V_74 <= 0 )
return V_100 ;
V_103 -= ( V_67 - V_64 ) ;
if ( V_103 ) {
V_104 += ( V_67 - V_64 ) ;
} else {
V_72 = F_56 ( V_72 ) ;
V_104 = F_54 ( V_72 ) ;
V_103 = F_53 ( V_72 ) ;
}
if ( V_74 <= V_67 ) {
V_63 -> V_76 = V_104 ;
return V_100 ;
}
V_66 = F_34 ( V_74 , V_67 ) ;
if ( V_66 <= ( 256 / 8 ) ) {
V_102 = V_18 -> V_81 ;
V_63 -> V_73 = 0 ;
} else {
V_102 = V_18 -> V_84 ;
V_63 -> V_73 = 1 ;
}
V_82 = F_57 ( V_102 , V_70 , & V_80 ) ;
if ( ! V_82 ) {
V_63 -> V_76 = V_104 ;
V_63 -> V_73 = - 1 ;
return ( V_100 - V_74 ) + V_67 ;
}
V_79 [ 0 ] = V_82 ;
V_63 -> V_76 = V_80 ;
V_78 = 0 ;
for (; ; ) {
if ( V_78 == V_67 >> 3 ) {
T_4 * V_105 = V_82 ;
V_82 = F_57 ( V_102 , V_70 , & V_80 ) ;
if ( ! V_82 )
return V_100 - V_74 ;
V_79 [ V_63 -> V_73 ++ ] = V_82 ;
V_82 [ 0 ] = V_105 [ V_78 - 1 ] ;
V_105 [ V_78 - 1 ] = F_58 ( V_80 ) ;
V_78 = 1 ;
}
V_82 [ V_78 ++ ] = F_58 ( V_104 ) ;
V_103 -= V_67 ;
V_104 += V_67 ;
V_74 -= V_67 ;
if ( V_74 <= 0 )
break;
if ( V_103 > 0 )
continue;
F_7 ( V_103 < 0 ) ;
V_72 = F_56 ( V_72 ) ;
V_104 = F_54 ( V_72 ) ;
V_103 = F_53 ( V_72 ) ;
}
return V_100 ;
}
static void F_59 ( struct V_19 * V_20 , struct V_106 * V_107 ,
struct V_23 * V_24 , struct V_62 * V_63 )
{
struct V_108 * V_109 =
(struct V_108 * ) F_32 ( V_63 ) [ 0 ] ;
struct V_8 * V_110 = & V_20 -> V_57 [ V_20 -> V_56 ] ;
V_109 -> V_111 = F_60 ( 0 ) ;
V_109 -> V_112 = F_60 ( F_61 ( V_24 ) >> V_107 -> V_113 ) ;
V_109 -> V_114 = F_58 ( F_62 ( V_107 , F_63 ( V_24 ) ) ) ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_115 . V_116 = V_117 ;
V_110 -> V_115 . V_40 = V_24 -> V_53 ;
V_110 -> V_115 . V_118 = F_60 ( V_107 -> V_119 ) ;
V_110 -> V_115 . V_120 = F_58 ( V_63 -> V_76 ) ;
V_110 -> V_115 . V_121 = 0 ;
V_110 -> V_115 . V_122 = F_60 ( V_123 ) ;
if ( ++ V_20 -> V_56 == V_20 -> V_54 )
V_20 -> V_56 = 0 ;
F_28 ( V_20 -> V_56 , V_20 -> V_58 ) ;
}
static void F_64 ( struct V_19 * V_20 , struct V_106 * V_107 ,
int V_124 )
{
struct V_8 * V_110 = & V_20 -> V_57 [ V_20 -> V_56 ] ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_125 . V_116 = V_126 ;
V_110 -> V_125 . V_40 = V_124 ;
V_110 -> V_125 . V_118 = F_60 ( V_107 -> V_119 ) ;
if ( ++ V_20 -> V_56 == V_20 -> V_54 )
V_20 -> V_56 = 0 ;
F_28 ( V_20 -> V_56 , V_20 -> V_58 ) ;
}
static int F_65 ( struct V_19 * V_20 , struct V_62 * V_63 ,
struct V_106 * V_107 )
{
struct V_23 * V_24 = V_63 -> V_88 ;
struct V_8 * V_110 ;
T_3 V_127 = 0 ;
T_2 V_128 = 0 ;
if ( V_24 -> V_129 & V_130 )
V_127 |= V_131 ;
if ( V_24 -> V_129 & ( V_132 | V_133 ) )
V_127 |= V_134 ;
if ( V_24 -> V_129 & V_133 )
V_128 |= V_135 ;
V_110 = & V_20 -> V_57 [ V_20 -> V_56 ] ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_136 . V_116 = ( F_50 ( V_24 ) ? V_137 : V_138 ) ;
V_110 -> V_136 . V_40 = V_24 -> V_53 ;
V_110 -> V_136 . V_118 = F_60 ( V_107 -> V_119 ) ;
V_110 -> V_136 . V_120 = F_58 ( F_54 ( V_63 -> V_72 ) ) ;
V_110 -> V_136 . V_139 = F_58 ( V_63 -> V_76 ) ;
V_110 -> V_136 . V_114 = F_58 ( F_62 ( V_107 , F_63 ( V_24 ) ) ) ;
V_110 -> V_136 . V_74 = F_66 ( ( F_61 ( V_24 ) >> V_107 -> V_113 ) - 1 ) ;
V_110 -> V_136 . V_127 = F_66 ( V_127 ) ;
V_110 -> V_136 . V_128 = F_60 ( V_128 ) ;
if ( ++ V_20 -> V_56 == V_20 -> V_54 )
V_20 -> V_56 = 0 ;
F_28 ( V_20 -> V_56 , V_20 -> V_58 ) ;
return 0 ;
}
static int F_67 ( struct V_13 * V_14 ,
const struct V_140 * V_141 )
{
struct V_106 * V_107 = V_14 -> V_142 -> V_143 ;
struct V_19 * V_20 = V_14 -> V_22 ;
struct V_23 * V_24 = V_141 -> V_144 ;
struct V_27 * V_28 = F_6 ( V_24 ) ;
struct V_62 * V_63 ;
int V_145 = V_24 -> V_146 ;
enum V_147 V_148 ;
unsigned V_65 = ! ( V_24 -> V_129 & V_149 ) ? F_61 ( V_24 ) :
sizeof( struct V_108 ) ;
V_63 = F_35 ( V_145 , V_65 , V_107 -> V_18 , V_150 ) ;
if ( ! V_63 )
return V_151 ;
V_63 -> V_88 = V_24 ;
if ( V_24 -> V_129 & V_149 ) {
void * V_109 ;
V_109 = F_57 ( V_20 -> V_18 -> V_81 ,
V_150 ,
& V_63 -> V_76 ) ;
if ( ! V_109 )
goto V_152;
F_32 ( V_63 ) [ 0 ] = ( T_4 * ) V_109 ;
V_63 -> V_73 = 0 ;
} else if ( V_145 ) {
V_148 = F_50 ( V_24 ) ? V_98 : V_99 ;
F_68 ( V_63 -> V_72 , V_145 ) ;
V_63 -> V_75 = F_69 ( V_24 -> V_94 , V_24 , V_63 -> V_72 ) ;
if ( ! V_63 -> V_75 )
goto V_153;
if ( ! F_70 ( V_20 -> V_39 , V_63 -> V_72 , V_63 -> V_75 , V_148 ) )
goto V_152;
if ( F_61 ( V_24 ) !=
F_52 ( V_20 -> V_18 , V_63 , F_61 ( V_24 ) , V_150 ) ) {
F_49 ( & V_20 -> V_18 -> V_97 -> V_18 , V_63 -> V_72 ,
V_63 -> V_75 , V_148 ) ;
goto V_152;
}
}
F_11 ( V_28 , V_63 , F_43 ) ;
F_71 ( & V_20 -> V_61 ) ;
if ( V_24 -> V_129 & V_149 )
F_59 ( V_20 , V_107 , V_24 , V_63 ) ;
else if ( V_24 -> V_129 & V_154 )
F_64 ( V_20 , V_107 , V_24 -> V_53 ) ;
else
F_65 ( V_20 , V_63 , V_107 ) ;
F_72 ( V_20 ) ;
F_73 ( & V_20 -> V_61 ) ;
return V_155 ;
V_153:
F_38 ( V_20 -> V_18 , V_63 ) ;
return V_156 ;
V_152:
F_38 ( V_20 -> V_18 , V_63 ) ;
return V_151 ;
}
static int F_72 ( struct V_19 * V_20 )
{
T_3 V_157 , V_158 ;
V_157 = V_20 -> V_159 ;
V_158 = V_20 -> V_160 ;
for (; ; ) {
void * V_31 ;
T_1 V_33 ;
struct V_35 V_36 = V_20 -> V_161 [ V_157 ] ;
if ( ( F_74 ( V_36 . V_44 ) & 1 ) != V_158 )
break;
V_20 -> V_162 = F_74 ( V_36 . V_162 ) ;
if ( ++ V_157 == V_20 -> V_54 ) {
V_157 = 0 ;
V_158 = ! V_158 ;
}
V_31 = F_26 ( V_20 , V_36 . V_40 , & V_33 ) ;
V_33 ( V_20 , V_31 , & V_36 ) ;
}
if ( V_157 == V_20 -> V_159 && V_158 == V_20 -> V_160 )
return 0 ;
F_28 ( V_157 , V_20 -> V_58 + V_20 -> V_18 -> V_163 ) ;
V_20 -> V_159 = V_157 ;
V_20 -> V_160 = V_158 ;
V_20 -> V_164 = 1 ;
return 1 ;
}
static int F_75 ( struct V_13 * V_14 ,
const struct V_140 * V_141 )
{
F_76 ( 1 ) ;
return V_156 ;
}
static T_8 F_77 ( int V_165 , void * V_15 )
{
T_8 V_43 ;
struct V_19 * V_20 = V_15 ;
F_78 ( & V_20 -> V_61 ) ;
F_72 ( V_20 ) ;
V_43 = V_20 -> V_164 ? V_166 : V_167 ;
V_20 -> V_164 = 0 ;
F_79 ( & V_20 -> V_61 ) ;
return V_43 ;
}
static T_8 F_80 ( int V_165 , void * V_15 )
{
struct V_19 * V_20 = V_15 ;
struct V_35 V_36 = V_20 -> V_161 [ V_20 -> V_159 ] ;
if ( ( F_74 ( V_36 . V_44 ) & 1 ) != V_20 -> V_160 )
return V_167 ;
return V_168 ;
}
static void F_81 ( struct V_19 * V_20 , struct V_27 *
V_169 )
{
F_71 ( & V_20 -> V_61 ) ;
F_17 ( V_169 , NULL ) ;
F_73 ( & V_20 -> V_61 ) ;
}
static void F_82 ( struct V_19 * V_20 , void * V_31 ,
struct V_35 * V_36 )
{
struct V_170 * V_50 = V_31 ;
V_50 -> V_43 = F_19 ( & V_36 -> V_43 ) ;
V_50 -> V_44 = F_16 ( & V_36 -> V_44 ) >> 1 ;
F_83 ( V_50 -> V_171 ) ;
}
static int F_84 ( struct V_23 * V_24 , struct V_8 * V_28 ,
T_2 * V_43 , unsigned V_93 )
{
int V_60 ;
struct V_170 V_50 ;
struct V_27 * V_89 = F_6 ( V_24 ) ;
struct V_19 * V_20 = V_89 -> V_20 ;
V_50 . V_171 = V_172 ;
V_50 . V_44 = - V_173 ;
V_28 -> V_125 . V_40 = V_24 -> V_53 ;
F_11 ( V_89 , & V_50 , F_82 ) ;
F_85 ( V_174 ) ;
V_60 = F_29 ( V_20 , V_28 ) ;
if ( V_60 ) {
F_26 ( V_20 , V_24 -> V_53 , NULL ) ;
F_85 ( V_175 ) ;
}
V_60 = F_86 ( V_93 ) ;
F_81 ( V_20 , F_6 ( V_24 ) ) ;
if ( V_50 . V_44 == - V_173 )
return - V_173 ;
if ( V_43 )
* V_43 = V_50 . V_43 ;
return V_50 . V_44 ;
}
static int F_87 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 [ 0 ] ;
struct V_8 V_176 ;
struct V_27 * V_169 ;
struct V_23 * V_24 ;
V_24 = F_88 ( V_18 -> V_177 , V_178 , V_150 , false ) ;
if ( F_89 ( V_24 ) )
return F_90 ( V_24 ) ;
V_24 -> V_129 |= V_179 ;
V_169 = F_6 ( V_24 ) ;
F_11 ( V_169 , V_24 , F_18 ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_125 . V_116 = V_180 ;
V_176 . V_125 . V_40 = V_24 -> V_53 ;
return F_27 ( V_20 , & V_176 ) ;
}
static int F_91 ( struct V_17 * V_18 ,
struct V_8 * V_28 ,
struct V_49 * V_50 , unsigned V_93 )
{
struct V_19 * V_20 = V_18 -> V_21 [ 0 ] ;
struct V_23 * V_24 ;
struct V_27 * V_89 ;
V_24 = F_88 ( V_18 -> V_177 , V_178 , V_181 , false ) ;
if ( F_89 ( V_24 ) )
return F_90 ( V_24 ) ;
V_24 -> V_93 = V_93 ;
V_89 = F_6 ( V_24 ) ;
V_50 -> V_24 = V_24 ;
F_11 ( V_89 , V_50 , F_22 ) ;
V_50 -> V_44 = - V_173 ;
V_28 -> V_125 . V_40 = V_24 -> V_53 ;
return F_29 ( V_20 , V_28 ) ;
}
static int F_92 ( struct V_17 * V_18 , struct V_8 * V_28 ,
T_2 * V_43 , unsigned V_93 )
{
int V_182 ;
struct V_23 * V_24 ;
V_24 = F_88 ( V_18 -> V_177 , V_178 , V_181 , false ) ;
if ( F_89 ( V_24 ) )
return F_90 ( V_24 ) ;
V_182 = F_84 ( V_24 , V_28 , V_43 , V_93 ) ;
F_93 ( V_24 ) ;
return V_182 ;
}
int F_94 ( struct V_17 * V_18 , struct V_8 * V_28 ,
T_2 * V_43 )
{
return F_92 ( V_18 , V_28 , V_43 , V_183 ) ;
}
int F_95 ( struct V_17 * V_18 , struct V_106 * V_107 ,
struct V_8 * V_28 , T_2 * V_43 )
{
int V_182 ;
struct V_23 * V_24 ;
V_24 = F_88 ( V_107 -> V_142 , V_178 , ( V_181 | V_184 ) ,
false ) ;
if ( F_89 ( V_24 ) )
return F_90 ( V_24 ) ;
V_182 = F_84 ( V_24 , V_28 , V_43 , V_185 ) ;
F_93 ( V_24 ) ;
return V_182 ;
}
static int F_96 ( struct V_17 * V_18 , T_9 V_116 , T_3 V_186 )
{
struct V_8 V_176 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_187 . V_116 = V_116 ;
V_176 . V_187 . V_188 = F_66 ( V_186 ) ;
return F_94 ( V_18 , & V_176 , NULL ) ;
}
static int F_97 ( struct V_17 * V_18 , T_3 V_188 ,
struct V_19 * V_20 )
{
struct V_8 V_176 ;
int V_59 = V_189 | V_190 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_191 . V_116 = V_192 ;
V_176 . V_191 . V_120 = F_58 ( V_20 -> V_193 ) ;
V_176 . V_191 . V_194 = F_66 ( V_188 ) ;
V_176 . V_191 . V_195 = F_66 ( V_20 -> V_54 - 1 ) ;
V_176 . V_191 . V_196 = F_66 ( V_59 ) ;
V_176 . V_191 . V_197 = F_66 ( V_20 -> V_198 ) ;
return F_94 ( V_18 , & V_176 , NULL ) ;
}
static int F_98 ( struct V_17 * V_18 , T_3 V_188 ,
struct V_19 * V_20 )
{
struct V_8 V_176 ;
int V_59 = V_189 | V_199 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_200 . V_116 = V_201 ;
V_176 . V_200 . V_120 = F_58 ( V_20 -> V_202 ) ;
V_176 . V_200 . V_203 = F_66 ( V_188 ) ;
V_176 . V_200 . V_195 = F_66 ( V_20 -> V_54 - 1 ) ;
V_176 . V_200 . V_204 = F_66 ( V_59 ) ;
V_176 . V_200 . V_194 = F_66 ( V_188 ) ;
return F_94 ( V_18 , & V_176 , NULL ) ;
}
static int F_99 ( struct V_17 * V_18 , T_3 V_194 )
{
return F_96 ( V_18 , V_205 , V_194 ) ;
}
static int F_100 ( struct V_17 * V_18 , T_3 V_203 )
{
return F_96 ( V_18 , V_206 , V_203 ) ;
}
int F_101 ( struct V_17 * V_18 , unsigned V_118 , unsigned V_207 ,
T_6 V_104 )
{
struct V_8 V_176 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_208 . V_116 = V_209 ;
V_176 . V_208 . V_118 = F_60 ( V_118 ) ;
V_176 . V_208 . V_120 = F_58 ( V_104 ) ;
V_176 . V_208 . V_207 = F_60 ( V_207 ) ;
return F_94 ( V_18 , & V_176 , NULL ) ;
}
int F_102 ( struct V_17 * V_18 , unsigned V_210 , unsigned V_118 ,
T_6 V_104 , T_2 * V_43 )
{
struct V_8 V_176 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_211 . V_116 = V_212 ;
V_176 . V_211 . V_118 = F_60 ( V_118 ) ;
V_176 . V_211 . V_120 = F_58 ( V_104 ) ;
V_176 . V_211 . V_210 = F_60 ( V_210 ) ;
return F_94 ( V_18 , & V_176 , V_43 ) ;
}
int F_103 ( struct V_17 * V_18 , unsigned V_210 , unsigned V_213 ,
T_6 V_104 , T_2 * V_43 )
{
struct V_8 V_176 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_211 . V_116 = V_214 ;
V_176 . V_211 . V_120 = F_58 ( V_104 ) ;
V_176 . V_211 . V_210 = F_60 ( V_210 ) ;
V_176 . V_211 . V_213 = F_60 ( V_213 ) ;
return F_94 ( V_18 , & V_176 , V_43 ) ;
}
static void F_104 ( struct V_23 * V_24 )
{
struct V_27 * V_89 = F_6 ( V_24 ) ;
struct V_19 * V_20 = V_89 -> V_20 ;
struct V_17 * V_18 = V_20 -> V_18 ;
struct V_23 * V_215 ;
struct V_27 * V_216 ;
struct V_8 V_28 ;
if ( ! V_20 -> V_188 || V_89 -> V_34 ) {
unsigned long V_59 ;
F_30 ( & V_217 , V_59 ) ;
if ( F_105 ( & V_18 -> V_218 ) )
goto V_219;
F_106 ( & V_18 -> V_220 ) ;
F_15 ( & V_18 -> V_97 -> V_18 ,
L_7 ,
V_24 -> V_53 , V_20 -> V_188 ) ;
V_18 -> V_221 = V_222 ;
F_107 ( V_223 , & V_18 -> V_218 ) ;
V_219:
F_31 ( & V_217 , V_59 ) ;
return;
}
if ( ! V_18 -> V_48 )
return;
V_215 = F_88 ( V_18 -> V_177 , V_178 , V_150 ,
false ) ;
if ( F_89 ( V_215 ) )
return;
V_216 = F_6 ( V_215 ) ;
F_11 ( V_216 , V_215 , F_21 ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . abort . V_116 = V_224 ;
V_28 . abort . V_225 = V_24 -> V_53 ;
V_28 . abort . V_203 = F_66 ( V_20 -> V_188 ) ;
V_28 . abort . V_40 = V_215 -> V_53 ;
-- V_18 -> V_48 ;
V_89 -> V_34 = 1 ;
F_15 ( V_20 -> V_39 , L_8 , V_24 -> V_53 ,
V_20 -> V_188 ) ;
if ( F_29 ( V_18 -> V_21 [ 0 ] , & V_28 ) < 0 ) {
F_15 ( V_20 -> V_39 ,
L_9 ,
V_24 -> V_53 , V_20 -> V_188 ) ;
F_93 ( V_215 ) ;
}
}
static void F_108 ( struct V_13 * V_14 ,
struct V_23 * V_24 , void * V_15 , bool V_226 )
{
struct V_19 * V_20 = V_15 ;
void * V_31 ;
T_1 V_33 ;
struct V_27 * V_28 ;
struct V_35 V_36 ;
if ( ! F_109 ( V_24 ) )
return;
V_28 = F_6 ( V_24 ) ;
if ( V_28 -> V_31 == V_37 )
return;
if ( F_110 ( V_24 -> V_94 ) )
V_36 . V_44 = F_66 ( ( V_46 | V_90 ) << 1 ) ;
else
V_36 . V_44 = F_66 ( V_46 << 1 ) ;
F_15 ( V_20 -> V_39 , L_10 ,
V_24 -> V_53 , V_20 -> V_188 ) ;
V_31 = F_17 ( V_28 , & V_33 ) ;
V_33 ( V_20 , V_31 , & V_36 ) ;
}
static enum V_227 F_111 ( struct V_23 * V_24 , bool V_226 )
{
struct V_27 * V_28 = F_6 ( V_24 ) ;
struct V_19 * V_20 = V_28 -> V_20 ;
int V_60 = V_228 ;
F_15 ( V_20 -> V_39 , L_11 , V_24 -> V_53 ,
V_20 -> V_188 ) ;
F_71 ( & V_20 -> V_61 ) ;
if ( ! V_20 -> V_18 -> V_229 ) {
F_108 ( V_20 -> V_14 , V_24 , V_20 , V_226 ) ;
V_60 = V_230 ;
} else
F_104 ( V_24 ) ;
F_73 ( & V_20 -> V_61 ) ;
return V_60 ;
}
static void F_112 ( struct V_19 * V_20 )
{
F_113 ( V_20 -> V_39 , F_114 ( V_20 -> V_54 ) ,
( void * ) V_20 -> V_161 , V_20 -> V_193 ) ;
F_113 ( V_20 -> V_39 , F_115 ( V_20 -> V_54 ) ,
V_20 -> V_57 , V_20 -> V_202 ) ;
F_41 ( V_20 ) ;
}
static void F_116 ( struct V_17 * V_18 , int V_231 )
{
F_117 ( V_232 ) ;
struct V_19 * V_20 , * V_233 ;
struct V_234 * V_235 ;
int V_78 ;
for ( V_78 = V_18 -> V_29 - 1 ; V_78 >= V_231 ; V_78 -- ) {
struct V_19 * V_20 = V_18 -> V_21 [ V_78 ] ;
F_118 ( & V_20 -> V_220 , & V_232 ) ;
V_18 -> V_29 -- ;
V_18 -> V_21 [ V_78 ] = NULL ;
}
F_119 () ;
V_235 = F_120 ( & V_232 ) ;
F_121 (nvmeq, next, entry, node)
F_112 ( V_20 ) ;
}
static int F_122 ( struct V_19 * V_20 )
{
int V_236 ;
F_71 ( & V_20 -> V_61 ) ;
if ( V_20 -> V_198 == - 1 ) {
F_73 ( & V_20 -> V_61 ) ;
return 1 ;
}
V_236 = V_20 -> V_18 -> V_235 [ V_20 -> V_198 ] . V_236 ;
V_20 -> V_18 -> V_237 -- ;
V_20 -> V_198 = - 1 ;
F_73 ( & V_20 -> V_61 ) ;
F_123 ( V_236 , NULL ) ;
F_124 ( V_236 , V_20 ) ;
return 0 ;
}
static void F_125 ( struct V_19 * V_20 )
{
struct V_13 * V_14 = V_20 -> V_14 ;
F_71 ( & V_20 -> V_61 ) ;
F_72 ( V_20 ) ;
if ( V_14 && V_14 -> V_30 )
F_126 ( V_14 , F_108 , V_20 ) ;
F_73 ( & V_20 -> V_61 ) ;
}
static void F_127 ( struct V_17 * V_18 , int V_188 )
{
struct V_19 * V_20 = V_18 -> V_21 [ V_188 ] ;
if ( ! V_20 )
return;
if ( F_122 ( V_20 ) )
return;
if ( V_188 && F_128 ( & V_18 -> V_238 -> V_239 ) != - 1 ) {
F_100 ( V_18 , V_188 ) ;
F_99 ( V_18 , V_188 ) ;
}
if ( ! V_188 && V_18 -> V_177 )
F_129 ( V_18 -> V_177 ) ;
F_125 ( V_20 ) ;
}
static struct V_19 * F_130 ( struct V_17 * V_18 , int V_188 ,
int V_240 )
{
struct V_241 * V_242 = & V_18 -> V_97 -> V_18 ;
struct V_19 * V_20 = F_131 ( sizeof( * V_20 ) , V_181 ) ;
if ( ! V_20 )
return NULL ;
V_20 -> V_161 = F_132 ( V_242 , F_114 ( V_240 ) ,
& V_20 -> V_193 , V_181 ) ;
if ( ! V_20 -> V_161 )
goto V_243;
V_20 -> V_57 = F_133 ( V_242 , F_115 ( V_240 ) ,
& V_20 -> V_202 , V_181 ) ;
if ( ! V_20 -> V_57 )
goto V_244;
V_20 -> V_39 = V_242 ;
V_20 -> V_18 = V_18 ;
snprintf ( V_20 -> V_245 , sizeof( V_20 -> V_245 ) , L_12 ,
V_18 -> V_246 , V_188 ) ;
F_134 ( & V_20 -> V_61 ) ;
V_20 -> V_159 = 0 ;
V_20 -> V_160 = 1 ;
V_20 -> V_58 = & V_18 -> V_247 [ V_188 * 2 * V_18 -> V_163 ] ;
V_20 -> V_54 = V_240 ;
V_20 -> V_188 = V_188 ;
V_18 -> V_29 ++ ;
V_18 -> V_21 [ V_188 ] = V_20 ;
return V_20 ;
V_244:
F_113 ( V_242 , F_114 ( V_240 ) , ( void * ) V_20 -> V_161 ,
V_20 -> V_193 ) ;
V_243:
F_41 ( V_20 ) ;
return NULL ;
}
static int F_135 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_248 )
{
if ( V_249 )
return F_136 ( V_18 -> V_235 [ V_20 -> V_198 ] . V_236 ,
F_80 , F_77 , V_250 ,
V_248 , V_20 ) ;
return F_137 ( V_18 -> V_235 [ V_20 -> V_198 ] . V_236 , F_77 ,
V_250 , V_248 , V_20 ) ;
}
static void F_138 ( struct V_19 * V_20 , T_3 V_188 )
{
struct V_17 * V_18 = V_20 -> V_18 ;
F_71 ( & V_20 -> V_61 ) ;
V_20 -> V_56 = 0 ;
V_20 -> V_159 = 0 ;
V_20 -> V_160 = 1 ;
V_20 -> V_58 = & V_18 -> V_247 [ V_188 * 2 * V_18 -> V_163 ] ;
memset ( ( void * ) V_20 -> V_161 , 0 , F_114 ( V_20 -> V_54 ) ) ;
V_18 -> V_237 ++ ;
F_73 ( & V_20 -> V_61 ) ;
}
static int F_139 ( struct V_19 * V_20 , int V_188 )
{
struct V_17 * V_18 = V_20 -> V_18 ;
int V_43 ;
V_20 -> V_198 = V_188 - 1 ;
V_43 = F_97 ( V_18 , V_188 , V_20 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_98 ( V_18 , V_188 , V_20 ) ;
if ( V_43 < 0 )
goto V_251;
V_43 = F_135 ( V_18 , V_20 , V_20 -> V_245 ) ;
if ( V_43 < 0 )
goto V_252;
F_138 ( V_20 , V_188 ) ;
return V_43 ;
V_252:
F_100 ( V_18 , V_188 ) ;
V_251:
F_99 ( V_18 , V_188 ) ;
return V_43 ;
}
static int F_140 ( struct V_17 * V_18 , T_7 V_253 , bool V_254 )
{
unsigned long V_93 ;
T_2 V_255 = V_254 ? V_256 : 0 ;
V_93 = ( ( F_141 ( V_253 ) + 1 ) * V_257 / 2 ) + V_91 ;
while ( ( F_128 ( & V_18 -> V_238 -> V_239 ) & V_256 ) != V_255 ) {
F_142 ( 100 ) ;
if ( F_143 ( V_172 ) )
return - V_173 ;
if ( F_144 ( V_91 , V_93 ) ) {
F_145 ( & V_18 -> V_97 -> V_18 ,
L_13 , V_254 ?
L_14 : L_15 ) ;
return - V_258 ;
}
}
return 0 ;
}
static int F_146 ( struct V_17 * V_18 , T_7 V_253 )
{
V_18 -> V_259 &= ~ V_260 ;
V_18 -> V_259 &= ~ V_261 ;
F_28 ( V_18 -> V_259 , & V_18 -> V_238 -> V_262 ) ;
return F_140 ( V_18 , V_253 , false ) ;
}
static int F_147 ( struct V_17 * V_18 , T_7 V_253 )
{
V_18 -> V_259 &= ~ V_260 ;
V_18 -> V_259 |= V_261 ;
F_28 ( V_18 -> V_259 , & V_18 -> V_238 -> V_262 ) ;
return F_140 ( V_18 , V_253 , true ) ;
}
static int F_148 ( struct V_17 * V_18 )
{
unsigned long V_93 ;
V_18 -> V_259 &= ~ V_260 ;
V_18 -> V_259 |= V_263 ;
F_28 ( V_18 -> V_259 , & V_18 -> V_238 -> V_262 ) ;
V_93 = V_264 + V_91 ;
while ( ( F_128 ( & V_18 -> V_238 -> V_239 ) & V_265 ) !=
V_266 ) {
F_142 ( 100 ) ;
if ( F_143 ( V_172 ) )
return - V_173 ;
if ( F_144 ( V_91 , V_93 ) ) {
F_145 ( & V_18 -> V_97 -> V_18 ,
L_16 ) ;
return - V_258 ;
}
}
return 0 ;
}
static void F_149 ( struct V_17 * V_18 )
{
if ( V_18 -> V_177 && ! F_110 ( V_18 -> V_177 ) ) {
F_150 ( V_18 -> V_177 ) ;
F_151 ( & V_18 -> V_267 ) ;
}
}
static int F_152 ( struct V_17 * V_18 )
{
if ( ! V_18 -> V_177 ) {
V_18 -> V_267 . V_268 = & V_269 ;
V_18 -> V_267 . V_270 = 1 ;
V_18 -> V_267 . V_271 = V_272 - 1 ;
V_18 -> V_267 . V_93 = V_183 ;
V_18 -> V_267 . V_26 = F_153 ( & V_18 -> V_97 -> V_18 ) ;
V_18 -> V_267 . V_273 = sizeof( struct V_27 ) ;
V_18 -> V_267 . V_22 = V_18 ;
if ( F_154 ( & V_18 -> V_267 ) )
return - V_274 ;
V_18 -> V_177 = F_155 ( & V_18 -> V_267 ) ;
if ( F_89 ( V_18 -> V_177 ) ) {
F_151 ( & V_18 -> V_267 ) ;
return - V_274 ;
}
if ( ! F_156 ( V_18 -> V_177 ) ) {
F_149 ( V_18 ) ;
return - V_258 ;
}
} else
F_157 ( V_18 -> V_177 ) ;
return 0 ;
}
static int F_158 ( struct V_17 * V_18 )
{
int V_43 ;
T_2 V_275 ;
T_7 V_253 = F_159 ( & V_18 -> V_238 -> V_253 ) ;
struct V_19 * V_20 ;
unsigned V_276 = V_277 ;
unsigned V_278 = F_160 ( V_253 ) + 12 ;
unsigned V_279 = F_161 ( V_253 ) + 12 ;
if ( V_276 < V_278 ) {
F_145 ( & V_18 -> V_97 -> V_18 ,
L_17
L_18 , 1 << V_278 ,
1 << V_276 ) ;
return - V_258 ;
}
if ( V_276 > V_279 ) {
F_162 ( & V_18 -> V_97 -> V_18 ,
L_19
L_20 ,
1 << V_279 , 1 << V_276 ) ;
V_276 = V_279 ;
}
V_43 = F_146 ( V_18 , V_253 ) ;
if ( V_43 < 0 )
return V_43 ;
V_20 = V_18 -> V_21 [ 0 ] ;
if ( ! V_20 ) {
V_20 = F_130 ( V_18 , 0 , V_272 ) ;
if ( ! V_20 )
return - V_274 ;
}
V_275 = V_20 -> V_54 - 1 ;
V_275 |= V_275 << 16 ;
V_18 -> V_67 = 1 << V_276 ;
V_18 -> V_259 = V_280 ;
V_18 -> V_259 |= ( V_276 - 12 ) << V_281 ;
V_18 -> V_259 |= V_282 | V_283 ;
V_18 -> V_259 |= V_284 | V_285 ;
F_28 ( V_275 , & V_18 -> V_238 -> V_275 ) ;
F_163 ( V_20 -> V_202 , & V_18 -> V_238 -> V_286 ) ;
F_163 ( V_20 -> V_193 , & V_18 -> V_238 -> V_287 ) ;
V_43 = F_147 ( V_18 , V_253 ) ;
if ( V_43 )
goto V_243;
V_20 -> V_198 = 0 ;
V_43 = F_135 ( V_18 , V_20 , V_20 -> V_245 ) ;
if ( V_43 )
goto V_243;
return V_43 ;
V_243:
F_116 ( V_18 , 0 ) ;
return V_43 ;
}
struct V_62 * F_164 ( struct V_17 * V_18 , int V_288 ,
unsigned long V_289 , unsigned V_74 )
{
int V_78 , V_290 , V_291 , V_75 , V_64 ;
struct V_71 * V_72 ;
struct V_292 * * V_293 ;
struct V_62 * V_63 ;
if ( V_289 & 3 )
return F_165 ( - V_294 ) ;
if ( ! V_74 || V_74 > V_295 - V_296 )
return F_165 ( - V_294 ) ;
V_64 = F_55 ( V_289 ) ;
V_291 = F_34 ( V_64 + V_74 , V_296 ) ;
V_293 = F_166 ( V_291 , sizeof( * V_293 ) , V_181 ) ;
if ( ! V_293 )
return F_165 ( - V_274 ) ;
V_290 = F_167 ( V_289 , V_291 , 1 , V_293 ) ;
if ( V_290 < V_291 ) {
V_291 = V_290 ;
V_290 = - V_297 ;
goto V_298;
}
V_290 = - V_274 ;
V_63 = F_35 ( V_291 , V_74 , V_18 , V_181 ) ;
if ( ! V_63 )
goto V_298;
V_72 = V_63 -> V_72 ;
F_68 ( V_72 , V_291 ) ;
for ( V_78 = 0 ; V_78 < V_291 ; V_78 ++ ) {
F_168 ( & V_72 [ V_78 ] , V_293 [ V_78 ] ,
F_169 ( unsigned , V_74 , V_296 - V_64 ) ,
V_64 ) ;
V_74 -= ( V_296 - V_64 ) ;
V_64 = 0 ;
}
F_170 ( & V_72 [ V_78 - 1 ] ) ;
V_63 -> V_75 = V_291 ;
V_75 = F_70 ( & V_18 -> V_97 -> V_18 , V_72 , V_291 ,
V_288 ? V_98 : V_99 ) ;
if ( ! V_75 )
goto V_299;
F_41 ( V_293 ) ;
return V_63 ;
V_299:
F_41 ( V_63 ) ;
V_298:
for ( V_78 = 0 ; V_78 < V_291 ; V_78 ++ )
F_171 ( V_293 [ V_78 ] ) ;
F_41 ( V_293 ) ;
return F_165 ( V_290 ) ;
}
void F_172 ( struct V_17 * V_18 , int V_288 ,
struct V_62 * V_63 )
{
int V_78 ;
F_49 ( & V_18 -> V_97 -> V_18 , V_63 -> V_72 , V_63 -> V_75 ,
V_288 ? V_98 : V_99 ) ;
for ( V_78 = 0 ; V_78 < V_63 -> V_75 ; V_78 ++ )
F_171 ( F_173 ( & V_63 -> V_72 [ V_78 ] ) ) ;
}
static int F_174 ( struct V_106 * V_107 , struct V_300 T_10 * V_301 )
{
struct V_17 * V_18 = V_107 -> V_18 ;
struct V_300 V_302 ;
struct V_8 V_176 ;
unsigned V_74 , V_303 ;
int V_44 , V_78 ;
struct V_62 * V_63 , * V_304 = NULL ;
T_6 V_305 ;
void * V_306 , * V_307 ( V_308 ) ;
if ( F_175 ( & V_302 , V_301 , sizeof( V_302 ) ) )
return - V_297 ;
V_74 = ( V_302 . V_309 + 1 ) << V_107 -> V_113 ;
V_303 = ( V_302 . V_309 + 1 ) * V_107 -> V_310 ;
if ( V_303 && ( ( V_302 . V_311 & 3 ) || ! V_302 . V_311 ) )
return - V_294 ;
switch ( V_302 . V_116 ) {
case V_137 :
case V_138 :
case V_312 :
V_63 = F_164 ( V_18 , V_302 . V_116 & 1 , V_302 . V_289 , V_74 ) ;
break;
default:
return - V_294 ;
}
if ( F_89 ( V_63 ) )
return F_90 ( V_63 ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_136 . V_116 = V_302 . V_116 ;
V_176 . V_136 . V_59 = V_302 . V_59 ;
V_176 . V_136 . V_118 = F_60 ( V_107 -> V_119 ) ;
V_176 . V_136 . V_114 = F_58 ( V_302 . V_114 ) ;
V_176 . V_136 . V_74 = F_66 ( V_302 . V_309 ) ;
V_176 . V_136 . V_127 = F_66 ( V_302 . V_127 ) ;
V_176 . V_136 . V_128 = F_60 ( V_302 . V_128 ) ;
V_176 . V_136 . V_313 = F_60 ( V_302 . V_313 ) ;
V_176 . V_136 . V_314 = F_66 ( V_302 . V_314 ) ;
V_176 . V_136 . V_315 = F_66 ( V_302 . V_315 ) ;
if ( V_303 ) {
V_304 = F_164 ( V_18 , V_302 . V_116 & 1 , V_302 . V_311 ,
V_303 ) ;
if ( F_89 ( V_304 ) ) {
V_44 = F_90 ( V_304 ) ;
V_304 = NULL ;
goto V_316;
}
V_308 = F_133 ( & V_18 -> V_97 -> V_18 , V_303 ,
& V_305 , V_181 ) ;
if ( ! V_308 ) {
V_44 = - V_274 ;
goto V_316;
}
if ( V_302 . V_116 & 1 ) {
int V_317 = 0 ;
for ( V_78 = 0 ; V_78 < V_304 -> V_75 ; V_78 ++ ) {
V_306 = F_176 ( F_173 ( & V_304 -> V_72 [ V_78 ] ) ) +
V_304 -> V_72 [ V_78 ] . V_64 ;
memcpy ( V_308 + V_317 , V_306 ,
V_304 -> V_72 [ V_78 ] . V_74 ) ;
F_177 ( V_306 ) ;
V_317 += V_304 -> V_72 [ V_78 ] . V_74 ;
}
}
V_176 . V_136 . V_311 = F_58 ( V_305 ) ;
}
V_74 = F_52 ( V_18 , V_63 , V_74 , V_181 ) ;
V_176 . V_136 . V_120 = F_58 ( F_54 ( V_63 -> V_72 ) ) ;
V_176 . V_136 . V_139 = F_58 ( V_63 -> V_76 ) ;
if ( V_74 != ( V_302 . V_309 + 1 ) << V_107 -> V_113 )
V_44 = - V_274 ;
else
V_44 = F_95 ( V_18 , V_107 , & V_176 , NULL ) ;
if ( V_303 ) {
if ( V_44 == V_45 && ! ( V_302 . V_116 & 1 ) ) {
int V_317 = 0 ;
for ( V_78 = 0 ; V_78 < V_304 -> V_75 ; V_78 ++ ) {
V_306 = F_176 ( F_173 ( & V_304 -> V_72 [ V_78 ] ) ) +
V_304 -> V_72 [ V_78 ] . V_64 ;
memcpy ( V_306 , V_308 + V_317 ,
V_304 -> V_72 [ V_78 ] . V_74 ) ;
F_177 ( V_306 ) ;
V_317 += V_304 -> V_72 [ V_78 ] . V_74 ;
}
}
F_113 ( & V_18 -> V_97 -> V_18 , V_303 , V_308 ,
V_305 ) ;
}
V_316:
F_172 ( V_18 , V_302 . V_116 & 1 , V_63 ) ;
F_38 ( V_18 , V_63 ) ;
if ( V_304 ) {
F_172 ( V_18 , V_302 . V_116 & 1 , V_304 ) ;
F_38 ( V_18 , V_304 ) ;
}
return V_44 ;
}
static int F_178 ( struct V_17 * V_18 , struct V_106 * V_107 ,
struct V_318 T_10 * V_319 )
{
struct V_318 V_28 ;
struct V_8 V_176 ;
int V_44 , V_74 ;
struct V_62 * V_307 ( V_63 ) ;
unsigned V_93 ;
if ( ! F_179 ( V_320 ) )
return - V_321 ;
if ( F_175 ( & V_28 , V_319 , sizeof( V_28 ) ) )
return - V_297 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_125 . V_116 = V_28 . V_116 ;
V_176 . V_125 . V_59 = V_28 . V_59 ;
V_176 . V_125 . V_118 = F_60 ( V_28 . V_118 ) ;
V_176 . V_125 . V_322 [ 0 ] = F_60 ( V_28 . V_322 ) ;
V_176 . V_125 . V_322 [ 1 ] = F_60 ( V_28 . V_323 ) ;
V_176 . V_125 . V_324 [ 0 ] = F_60 ( V_28 . V_324 ) ;
V_176 . V_125 . V_324 [ 1 ] = F_60 ( V_28 . V_325 ) ;
V_176 . V_125 . V_324 [ 2 ] = F_60 ( V_28 . V_326 ) ;
V_176 . V_125 . V_324 [ 3 ] = F_60 ( V_28 . V_327 ) ;
V_176 . V_125 . V_324 [ 4 ] = F_60 ( V_28 . V_328 ) ;
V_176 . V_125 . V_324 [ 5 ] = F_60 ( V_28 . V_329 ) ;
V_74 = V_28 . V_330 ;
if ( V_28 . V_330 ) {
V_63 = F_164 ( V_18 , V_28 . V_116 & 1 , V_28 . V_289 ,
V_74 ) ;
if ( F_89 ( V_63 ) )
return F_90 ( V_63 ) ;
V_74 = F_52 ( V_18 , V_63 , V_74 , V_181 ) ;
V_176 . V_125 . V_120 = F_58 ( F_54 ( V_63 -> V_72 ) ) ;
V_176 . V_125 . V_139 = F_58 ( V_63 -> V_76 ) ;
}
V_93 = V_28 . V_331 ? F_180 ( V_28 . V_331 ) :
V_183 ;
if ( V_74 != V_28 . V_330 )
V_44 = - V_274 ;
else if ( V_107 ) {
struct V_23 * V_24 ;
V_24 = F_88 ( V_107 -> V_142 , V_178 ,
( V_181 | V_184 ) , false ) ;
if ( F_89 ( V_24 ) )
V_44 = F_90 ( V_24 ) ;
else {
V_44 = F_84 ( V_24 , & V_176 , & V_28 . V_43 ,
V_93 ) ;
F_93 ( V_24 ) ;
}
} else
V_44 = F_92 ( V_18 , & V_176 , & V_28 . V_43 , V_93 ) ;
if ( V_28 . V_330 ) {
F_172 ( V_18 , V_28 . V_116 & 1 , V_63 ) ;
F_38 ( V_18 , V_63 ) ;
}
if ( ( V_44 >= 0 ) && F_181 ( & V_319 -> V_43 , & V_28 . V_43 ,
sizeof( V_28 . V_43 ) ) )
V_44 = - V_297 ;
return V_44 ;
}
static int F_182 ( struct V_332 * V_333 , T_11 V_334 , unsigned int V_28 ,
unsigned long V_335 )
{
struct V_106 * V_107 = V_333 -> V_336 -> V_337 ;
switch ( V_28 ) {
case V_338 :
F_183 () ;
return V_107 -> V_119 ;
case V_339 :
return F_178 ( V_107 -> V_18 , NULL , ( void T_10 * ) V_335 ) ;
case V_340 :
return F_178 ( V_107 -> V_18 , V_107 , ( void T_10 * ) V_335 ) ;
case V_341 :
return F_174 ( V_107 , ( void T_10 * ) V_335 ) ;
case V_342 :
return F_184 ( ( void T_10 * ) V_335 ) ;
case V_343 :
return F_185 ( V_107 , ( void T_10 * ) V_335 ) ;
default:
return - V_344 ;
}
}
static int F_186 ( struct V_332 * V_333 , T_11 V_334 ,
unsigned int V_28 , unsigned long V_335 )
{
switch ( V_28 ) {
case V_343 :
return - V_345 ;
}
return F_182 ( V_333 , V_334 , V_28 , V_335 ) ;
}
static int F_187 ( struct V_332 * V_333 , T_11 V_334 )
{
int V_60 = 0 ;
struct V_106 * V_107 ;
F_78 ( & V_217 ) ;
V_107 = V_333 -> V_336 -> V_337 ;
if ( ! V_107 )
V_60 = - V_346 ;
else if ( ! F_188 ( & V_107 -> V_18 -> V_347 ) )
V_60 = - V_346 ;
F_79 ( & V_217 ) ;
return V_60 ;
}
static void F_189 ( struct V_348 * V_349 , T_11 V_334 )
{
struct V_106 * V_107 = V_349 -> V_337 ;
struct V_17 * V_18 = V_107 -> V_18 ;
F_190 ( & V_18 -> V_347 , V_350 ) ;
}
static int F_191 ( struct V_332 * V_141 , struct V_351 * V_352 )
{
V_352 -> V_353 = 1 << 6 ;
V_352 -> V_354 = 1 << 5 ;
V_352 -> V_355 = F_192 ( V_141 -> V_336 ) >> 11 ;
return 0 ;
}
static int F_193 ( struct V_348 * V_349 )
{
struct V_106 * V_107 = V_349 -> V_337 ;
struct V_17 * V_18 = V_107 -> V_18 ;
struct V_10 * V_186 ;
T_6 V_104 ;
int V_356 ;
V_186 = F_133 ( & V_18 -> V_97 -> V_18 , 4096 , & V_104 ,
V_181 ) ;
if ( ! V_186 ) {
F_15 ( & V_18 -> V_97 -> V_18 , L_21 ,
V_357 ) ;
return 0 ;
}
if ( F_101 ( V_18 , V_107 -> V_119 , 0 , V_104 ) )
goto free;
V_356 = V_186 -> V_358 & 0xf ;
V_107 -> V_113 = V_186 -> V_356 [ V_356 ] . V_359 ;
F_194 ( V_107 -> V_142 , 1 << V_107 -> V_113 ) ;
F_195 ( V_349 , F_196 ( & V_186 -> V_360 ) << ( V_107 -> V_113 - 9 ) ) ;
free:
F_113 ( & V_18 -> V_97 -> V_18 , 4096 , V_186 , V_104 ) ;
return 0 ;
}
static int F_197 ( void * V_15 )
{
struct V_17 * V_18 , * V_233 ;
while ( ! F_198 () ) {
F_85 ( V_361 ) ;
F_78 ( & V_217 ) ;
F_199 (dev, next, &dev_list, node) {
int V_78 ;
if ( F_128 ( & V_18 -> V_238 -> V_239 ) & V_362 &&
V_18 -> V_229 ) {
if ( F_105 ( & V_18 -> V_218 ) )
continue;
F_106 ( & V_18 -> V_220 ) ;
F_15 ( & V_18 -> V_97 -> V_18 ,
L_22 ,
F_128 ( & V_18 -> V_238 -> V_239 ) ) ;
V_18 -> V_221 = V_222 ;
F_107 ( V_223 , & V_18 -> V_218 ) ;
continue;
}
for ( V_78 = 0 ; V_78 < V_18 -> V_29 ; V_78 ++ ) {
struct V_19 * V_20 = V_18 -> V_21 [ V_78 ] ;
if ( ! V_20 )
continue;
F_71 ( & V_20 -> V_61 ) ;
F_72 ( V_20 ) ;
while ( ( V_78 == 0 ) && ( V_18 -> V_47 > 0 ) ) {
if ( F_87 ( V_18 ) )
break;
V_18 -> V_47 -- ;
}
F_73 ( & V_20 -> V_61 ) ;
}
}
F_79 ( & V_217 ) ;
F_86 ( F_200 ( V_257 ) ) ;
}
return 0 ;
}
static void F_201 ( struct V_106 * V_107 )
{
T_2 V_363 = F_202 ( V_107 -> V_142 ) ;
V_107 -> V_142 -> V_364 . V_365 = 0 ;
V_107 -> V_142 -> V_364 . V_366 = V_363 ;
V_107 -> V_142 -> V_364 . V_367 = V_363 ;
V_107 -> V_142 -> V_364 . V_368 = 0xffffffff ;
F_203 ( V_369 , V_107 -> V_142 ) ;
}
static struct V_106 * F_204 ( struct V_17 * V_18 , unsigned V_118 ,
struct V_10 * V_186 , struct V_11 * V_370 )
{
struct V_106 * V_107 ;
struct V_348 * V_349 ;
int V_220 = F_153 ( & V_18 -> V_97 -> V_18 ) ;
int V_356 ;
if ( V_370 -> V_122 & V_371 )
return NULL ;
V_107 = F_205 ( sizeof( * V_107 ) , V_181 , V_220 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_142 = F_155 ( & V_18 -> V_372 ) ;
if ( F_89 ( V_107 -> V_142 ) )
goto V_373;
F_203 ( V_374 , V_107 -> V_142 ) ;
F_203 ( V_375 , V_107 -> V_142 ) ;
F_203 ( V_376 , V_107 -> V_142 ) ;
V_107 -> V_18 = V_18 ;
V_107 -> V_142 -> V_143 = V_107 ;
V_349 = F_206 ( 0 , V_220 ) ;
if ( ! V_349 )
goto V_377;
V_107 -> V_119 = V_118 ;
V_107 -> V_349 = V_349 ;
V_356 = V_186 -> V_358 & 0xf ;
V_107 -> V_113 = V_186 -> V_356 [ V_356 ] . V_359 ;
V_107 -> V_310 = F_74 ( V_186 -> V_356 [ V_356 ] . V_310 ) ;
F_194 ( V_107 -> V_142 , 1 << V_107 -> V_113 ) ;
if ( V_18 -> V_378 )
F_207 ( V_107 -> V_142 , V_18 -> V_378 ) ;
if ( V_18 -> V_379 )
F_208 ( V_107 -> V_142 , V_18 -> V_379 >> 9 ) ;
if ( V_18 -> V_380 & V_381 )
F_209 ( V_107 -> V_142 , V_154 | V_130 ) ;
V_349 -> V_382 = V_383 ;
V_349 -> V_384 = 0 ;
V_349 -> V_385 = & V_386 ;
V_349 -> V_337 = V_107 ;
V_349 -> V_142 = V_107 -> V_142 ;
V_349 -> V_387 = & V_18 -> V_97 -> V_18 ;
V_349 -> V_59 = V_388 ;
sprintf ( V_349 -> V_389 , L_23 , V_18 -> V_246 , V_118 ) ;
F_195 ( V_349 , F_196 ( & V_186 -> V_360 ) << ( V_107 -> V_113 - 9 ) ) ;
if ( V_18 -> V_390 & V_391 )
F_201 ( V_107 ) ;
return V_107 ;
V_377:
F_150 ( V_107 -> V_142 ) ;
V_373:
F_41 ( V_107 ) ;
return NULL ;
}
static void F_210 ( struct V_17 * V_18 )
{
unsigned V_78 ;
for ( V_78 = V_18 -> V_29 ; V_78 <= V_18 -> V_392 ; V_78 ++ )
if ( ! F_130 ( V_18 , V_78 , V_18 -> V_54 ) )
break;
for ( V_78 = V_18 -> V_237 ; V_78 <= V_18 -> V_29 - 1 ; V_78 ++ )
if ( F_139 ( V_18 -> V_21 [ V_78 ] , V_78 ) )
break;
}
static int F_211 ( struct V_17 * V_18 , int V_291 )
{
int V_44 ;
T_2 V_43 ;
T_2 V_393 = ( V_291 - 1 ) | ( ( V_291 - 1 ) << 16 ) ;
V_44 = F_103 ( V_18 , V_394 , V_393 , 0 ,
& V_43 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_44 > 0 ) {
F_145 ( & V_18 -> V_97 -> V_18 , L_24 ,
V_44 ) ;
return 0 ;
}
return F_212 ( V_43 & 0xffff , V_43 >> 16 ) + 1 ;
}
static T_12 F_213 ( struct V_17 * V_18 , unsigned V_395 )
{
return 4096 + ( ( V_395 + 1 ) * 8 * V_18 -> V_163 ) ;
}
static int F_214 ( struct V_17 * V_18 )
{
struct V_19 * V_396 = V_18 -> V_21 [ 0 ] ;
struct V_97 * V_397 = V_18 -> V_97 ;
int V_43 , V_78 , V_398 , V_395 , V_65 ;
V_395 = F_215 () ;
V_43 = F_211 ( V_18 , V_395 ) ;
if ( V_43 <= 0 )
return V_43 ;
if ( V_43 < V_395 )
V_395 = V_43 ;
V_65 = F_213 ( V_18 , V_395 ) ;
if ( V_65 > 8192 ) {
F_216 ( V_18 -> V_238 ) ;
do {
V_18 -> V_238 = F_217 ( F_218 ( V_397 , 0 ) , V_65 ) ;
if ( V_18 -> V_238 )
break;
if ( ! -- V_395 )
return - V_274 ;
V_65 = F_213 ( V_18 , V_395 ) ;
} while ( 1 );
V_18 -> V_247 = ( ( void V_399 * ) V_18 -> V_238 ) + 4096 ;
V_396 -> V_58 = V_18 -> V_247 ;
}
F_124 ( V_18 -> V_235 [ 0 ] . V_236 , V_396 ) ;
if ( ! V_397 -> V_165 )
F_219 ( V_397 ) ;
for ( V_78 = 0 ; V_78 < V_395 ; V_78 ++ )
V_18 -> V_235 [ V_78 ] . V_235 = V_78 ;
V_398 = F_220 ( V_397 , V_18 -> V_235 , 1 , V_395 ) ;
if ( V_398 < 0 ) {
V_398 = F_221 ( V_397 , 1 , F_212 ( V_395 , 32 ) ) ;
if ( V_398 < 0 ) {
V_398 = 1 ;
} else {
for ( V_78 = 0 ; V_78 < V_398 ; V_78 ++ )
V_18 -> V_235 [ V_78 ] . V_236 = V_78 + V_397 -> V_165 ;
}
}
V_395 = V_398 ;
V_18 -> V_392 = V_395 ;
V_43 = F_135 ( V_18 , V_396 , V_396 -> V_245 ) ;
if ( V_43 )
goto V_400;
F_116 ( V_18 , V_395 + 1 ) ;
F_210 ( V_18 ) ;
return 0 ;
V_400:
F_116 ( V_18 , 1 ) ;
return V_43 ;
}
static int F_222 ( struct V_17 * V_18 )
{
struct V_97 * V_397 = V_18 -> V_97 ;
int V_182 ;
unsigned V_401 , V_78 ;
struct V_106 * V_107 ;
struct V_9 * V_402 ;
struct V_10 * V_403 ;
void * V_404 ;
T_6 V_104 ;
int V_405 = F_160 ( F_159 ( & V_18 -> V_238 -> V_253 ) ) + 12 ;
V_404 = F_133 ( & V_397 -> V_18 , 8192 , & V_104 , V_181 ) ;
if ( ! V_404 )
return - V_274 ;
V_182 = F_101 ( V_18 , 0 , 1 , V_104 ) ;
if ( V_182 ) {
F_145 ( & V_397 -> V_18 , L_25 , V_182 ) ;
V_182 = - V_87 ;
goto V_219;
}
V_402 = V_404 ;
V_401 = F_19 ( & V_402 -> V_401 ) ;
V_18 -> V_390 = F_16 ( & V_402 -> V_390 ) ;
V_18 -> V_48 = V_402 -> V_406 + 1 ;
V_18 -> V_380 = V_402 -> V_380 ;
V_18 -> V_47 = F_212 ( V_402 -> V_407 + 1 , 8 ) ;
memcpy ( V_18 -> V_408 , V_402 -> V_409 , sizeof( V_402 -> V_409 ) ) ;
memcpy ( V_18 -> V_410 , V_402 -> V_411 , sizeof( V_402 -> V_411 ) ) ;
memcpy ( V_18 -> V_412 , V_402 -> V_413 , sizeof( V_402 -> V_413 ) ) ;
if ( V_402 -> V_414 )
V_18 -> V_378 = 1 << ( V_402 -> V_414 + V_405 - 9 ) ;
if ( ( V_397 -> V_415 == V_416 ) &&
( V_397 -> V_241 == 0x0953 ) && V_402 -> V_417 [ 3 ] ) {
unsigned int V_378 ;
V_18 -> V_379 = 1 << ( V_402 -> V_417 [ 3 ] + V_405 ) ;
V_378 = V_18 -> V_379 >> ( V_405 - 9 ) ;
if ( V_18 -> V_378 ) {
V_18 -> V_378 = F_212 ( V_378 ,
V_18 -> V_378 ) ;
} else
V_18 -> V_378 = V_378 ;
}
V_18 -> V_372 . V_268 = & V_418 ;
V_18 -> V_372 . V_270 = V_18 -> V_237 - 1 ;
V_18 -> V_372 . V_93 = V_185 ;
V_18 -> V_372 . V_26 = F_153 ( & V_18 -> V_97 -> V_18 ) ;
V_18 -> V_372 . V_271 =
F_169 ( int , V_18 -> V_54 , V_419 ) - 1 ;
V_18 -> V_372 . V_273 = sizeof( struct V_27 ) ;
V_18 -> V_372 . V_59 = V_420 ;
V_18 -> V_372 . V_22 = V_18 ;
if ( F_154 ( & V_18 -> V_372 ) )
goto V_219;
V_403 = V_404 ;
for ( V_78 = 1 ; V_78 <= V_401 ; V_78 ++ ) {
V_182 = F_101 ( V_18 , V_78 , 0 , V_104 ) ;
if ( V_182 )
continue;
if ( V_403 -> V_421 == 0 )
continue;
V_182 = F_102 ( V_18 , V_422 , V_78 ,
V_104 + 4096 , NULL ) ;
if ( V_182 )
memset ( V_404 + 4096 , 0 , 4096 ) ;
V_107 = F_204 ( V_18 , V_78 , V_404 , V_404 + 4096 ) ;
if ( V_107 )
F_223 ( & V_107 -> V_79 , & V_18 -> V_423 ) ;
}
F_224 (ns, &dev->namespaces, list)
F_225 ( V_107 -> V_349 ) ;
V_182 = 0 ;
V_219:
F_113 ( & V_18 -> V_97 -> V_18 , 8192 , V_404 , V_104 ) ;
return V_182 ;
}
static int F_226 ( struct V_17 * V_18 )
{
T_7 V_253 ;
int V_424 , V_43 = - V_274 ;
struct V_97 * V_397 = V_18 -> V_97 ;
if ( F_227 ( V_397 ) )
return V_43 ;
V_18 -> V_235 [ 0 ] . V_236 = V_397 -> V_165 ;
F_228 ( V_397 ) ;
V_424 = F_229 ( V_397 , V_425 ) ;
if ( ! V_424 )
goto V_426;
if ( F_230 ( V_397 , V_424 , L_26 ) )
goto V_426;
if ( F_231 ( & V_397 -> V_18 , F_232 ( 64 ) ) &&
F_231 ( & V_397 -> V_18 , F_232 ( 32 ) ) )
goto V_427;
V_18 -> V_238 = F_217 ( F_218 ( V_397 , 0 ) , 8192 ) ;
if ( ! V_18 -> V_238 )
goto V_427;
if ( F_128 ( & V_18 -> V_238 -> V_239 ) == - 1 ) {
V_43 = - V_258 ;
goto V_316;
}
if ( ! V_397 -> V_165 ) {
V_43 = F_233 ( V_397 , V_18 -> V_235 , 1 ) ;
if ( V_43 < 0 )
goto V_316;
}
V_253 = F_159 ( & V_18 -> V_238 -> V_253 ) ;
V_18 -> V_54 = F_169 ( int , F_234 ( V_253 ) + 1 , V_428 ) ;
V_18 -> V_163 = 1 << F_235 ( V_253 ) ;
V_18 -> V_247 = ( ( void V_399 * ) V_18 -> V_238 ) + 4096 ;
return 0 ;
V_316:
F_216 ( V_18 -> V_238 ) ;
V_18 -> V_238 = NULL ;
V_427:
F_236 ( V_397 ) ;
V_426:
F_237 ( V_397 ) ;
return V_43 ;
}
static void F_238 ( struct V_17 * V_18 )
{
if ( V_18 -> V_97 -> V_429 )
F_239 ( V_18 -> V_97 ) ;
else if ( V_18 -> V_97 -> V_430 )
F_219 ( V_18 -> V_97 ) ;
if ( V_18 -> V_238 ) {
F_216 ( V_18 -> V_238 ) ;
V_18 -> V_238 = NULL ;
F_236 ( V_18 -> V_97 ) ;
}
if ( F_240 ( V_18 -> V_97 ) )
F_237 ( V_18 -> V_97 ) ;
}
static void F_241 ( struct V_431 * V_432 , struct V_17 * V_18 )
{
V_432 -> V_433 = V_172 ;
F_242 () ;
for (; ; ) {
F_85 ( V_174 ) ;
if ( ! F_243 ( & V_432 -> V_434 ) )
break;
if ( ! F_86 ( V_183 ) ||
F_143 ( V_172 ) ) {
F_85 ( V_175 ) ;
F_146 ( V_18 , F_159 ( & V_18 -> V_238 -> V_253 ) ) ;
F_125 ( V_18 -> V_21 [ 0 ] ) ;
F_244 ( V_432 -> V_51 ) ;
F_127 ( V_18 , 0 ) ;
return;
}
}
F_85 ( V_175 ) ;
}
static void F_245 ( struct V_431 * V_432 )
{
F_246 ( & V_432 -> V_434 ) ;
if ( V_432 -> V_433 )
F_83 ( V_432 -> V_433 ) ;
}
static struct V_431 * F_247 ( struct V_431 * V_432 )
{
F_248 ( & V_432 -> V_434 ) ;
return V_432 ;
}
static void F_249 ( struct V_19 * V_20 )
{
struct V_431 * V_432 = V_20 -> V_50 . V_31 ;
F_125 ( V_20 ) ;
F_245 ( V_432 ) ;
}
static int F_250 ( struct V_19 * V_20 , T_9 V_116 ,
T_13 V_33 )
{
struct V_8 V_176 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_187 . V_116 = V_116 ;
V_176 . V_187 . V_188 = F_66 ( V_20 -> V_188 ) ;
F_251 ( & V_20 -> V_50 . V_52 , V_33 ) ;
return F_91 ( V_20 -> V_18 , & V_176 , & V_20 -> V_50 ,
V_183 ) ;
}
static void F_252 ( struct V_435 * V_52 )
{
struct V_19 * V_20 = F_253 ( V_52 , struct V_19 ,
V_50 . V_52 ) ;
F_249 ( V_20 ) ;
}
static int F_254 ( struct V_19 * V_20 )
{
return F_250 ( V_20 , V_205 ,
F_252 ) ;
}
static void F_255 ( struct V_435 * V_52 )
{
struct V_19 * V_20 = F_253 ( V_52 , struct V_19 ,
V_50 . V_52 ) ;
int V_44 = V_20 -> V_50 . V_44 ;
if ( ! V_44 )
V_44 = F_254 ( V_20 ) ;
if ( V_44 )
F_249 ( V_20 ) ;
}
static int F_256 ( struct V_19 * V_20 )
{
return F_250 ( V_20 , V_206 ,
F_255 ) ;
}
static void F_257 ( struct V_435 * V_52 )
{
struct V_19 * V_20 = F_253 ( V_52 , struct V_19 ,
V_50 . V_52 ) ;
if ( F_256 ( V_20 ) )
F_249 ( V_20 ) ;
}
static void F_258 ( struct V_17 * V_18 )
{
int V_78 ;
F_259 ( V_51 ) ;
struct V_431 V_432 ;
struct V_436 * V_437 = F_260 ( V_438 ,
& V_51 , L_27 , V_18 -> V_246 ) ;
if ( F_89 ( V_437 ) ) {
F_145 ( & V_18 -> V_97 -> V_18 ,
L_28 ) ;
for ( V_78 = V_18 -> V_29 - 1 ; V_78 > 0 ; V_78 -- )
F_127 ( V_18 , V_78 ) ;
return;
}
V_432 . V_433 = NULL ;
F_261 ( & V_432 . V_434 , 0 ) ;
V_432 . V_51 = & V_51 ;
for ( V_78 = V_18 -> V_29 - 1 ; V_78 > 0 ; V_78 -- ) {
struct V_19 * V_20 = V_18 -> V_21 [ V_78 ] ;
if ( F_122 ( V_20 ) )
continue;
V_20 -> V_50 . V_31 = F_247 ( & V_432 ) ;
V_20 -> V_50 . V_51 = V_432 . V_51 ;
F_251 ( & V_20 -> V_50 . V_52 , F_257 ) ;
F_23 ( V_432 . V_51 , & V_20 -> V_50 . V_52 ) ;
}
F_241 ( & V_432 , V_18 ) ;
F_262 ( V_437 ) ;
}
static void F_263 ( struct V_17 * V_18 )
{
struct V_436 * V_439 = NULL ;
F_78 ( & V_217 ) ;
F_106 ( & V_18 -> V_220 ) ;
if ( F_264 ( & V_440 ) && ! F_265 ( V_441 ) ) {
V_439 = V_441 ;
V_441 = NULL ;
}
F_79 ( & V_217 ) ;
if ( V_439 )
F_262 ( V_439 ) ;
}
static void F_266 ( struct V_17 * V_18 )
{
struct V_106 * V_107 ;
F_224 (ns, &dev->namespaces, list) {
F_129 ( V_107 -> V_142 ) ;
F_78 ( V_107 -> V_142 -> V_95 ) ;
F_267 ( V_442 , V_107 -> V_142 ) ;
F_79 ( V_107 -> V_142 -> V_95 ) ;
F_268 ( V_107 -> V_142 ) ;
F_269 ( V_107 -> V_142 ) ;
}
}
static void F_270 ( struct V_17 * V_18 )
{
struct V_106 * V_107 ;
F_224 (ns, &dev->namespaces, list) {
F_271 ( V_442 , V_107 -> V_142 ) ;
F_157 ( V_107 -> V_142 ) ;
F_272 ( V_107 -> V_142 , true ) ;
F_48 ( V_107 -> V_142 ) ;
}
}
static void F_273 ( struct V_17 * V_18 )
{
int V_78 ;
T_2 V_239 = - 1 ;
V_18 -> V_229 = 0 ;
F_263 ( V_18 ) ;
if ( V_18 -> V_238 ) {
F_266 ( V_18 ) ;
V_239 = F_128 ( & V_18 -> V_238 -> V_239 ) ;
}
if ( V_239 & V_362 || ! ( V_239 & V_256 ) ) {
for ( V_78 = V_18 -> V_29 - 1 ; V_78 >= 0 ; V_78 -- ) {
struct V_19 * V_20 = V_18 -> V_21 [ V_78 ] ;
F_122 ( V_20 ) ;
F_125 ( V_20 ) ;
}
} else {
F_258 ( V_18 ) ;
F_148 ( V_18 ) ;
F_127 ( V_18 , 0 ) ;
}
F_238 ( V_18 ) ;
}
static void F_274 ( struct V_17 * V_18 )
{
struct V_106 * V_107 ;
F_224 (ns, &dev->namespaces, list) {
if ( V_107 -> V_349 -> V_59 & V_443 )
F_275 ( V_107 -> V_349 ) ;
if ( ! F_110 ( V_107 -> V_142 ) ) {
F_276 ( V_107 -> V_142 ) ;
F_150 ( V_107 -> V_142 ) ;
}
}
}
static int F_277 ( struct V_17 * V_18 )
{
struct V_241 * V_242 = & V_18 -> V_97 -> V_18 ;
V_18 -> V_84 = F_278 ( L_29 , V_242 ,
V_296 , V_296 , 0 ) ;
if ( ! V_18 -> V_84 )
return - V_274 ;
V_18 -> V_81 = F_278 ( L_30 , V_242 ,
256 , 256 , 0 ) ;
if ( ! V_18 -> V_81 ) {
F_279 ( V_18 -> V_84 ) ;
return - V_274 ;
}
return 0 ;
}
static void F_280 ( struct V_17 * V_18 )
{
F_279 ( V_18 -> V_84 ) ;
F_279 ( V_18 -> V_81 ) ;
}
static int F_281 ( struct V_17 * V_18 )
{
int V_246 , error ;
do {
if ( ! F_282 ( & V_444 , V_181 ) )
return - V_258 ;
F_78 ( & V_217 ) ;
error = F_283 ( & V_444 , & V_246 ) ;
F_79 ( & V_217 ) ;
} while ( error == - V_445 );
if ( error )
return - V_258 ;
V_18 -> V_246 = V_246 ;
return 0 ;
}
static void F_284 ( struct V_17 * V_18 )
{
F_78 ( & V_217 ) ;
F_285 ( & V_444 , V_18 -> V_246 ) ;
F_79 ( & V_217 ) ;
}
static void F_286 ( struct V_17 * V_18 )
{
struct V_106 * V_107 , * V_233 ;
F_199 (ns, next, &dev->namespaces, list) {
F_287 ( & V_107 -> V_79 ) ;
F_78 ( & V_217 ) ;
V_107 -> V_349 -> V_337 = NULL ;
F_79 ( & V_217 ) ;
F_288 ( V_107 -> V_349 ) ;
F_41 ( V_107 ) ;
}
}
static void V_350 ( struct V_347 * V_347 )
{
struct V_17 * V_18 = F_253 ( V_347 , struct V_17 , V_347 ) ;
F_289 ( V_18 -> V_97 ) ;
F_286 ( V_18 ) ;
F_284 ( V_18 ) ;
F_151 ( & V_18 -> V_372 ) ;
F_290 ( V_18 -> V_177 ) ;
F_41 ( V_18 -> V_21 ) ;
F_41 ( V_18 -> V_235 ) ;
F_41 ( V_18 ) ;
}
static int F_291 ( struct V_446 * V_446 , struct V_447 * V_448 )
{
struct V_17 * V_18 = F_253 ( V_448 -> V_337 , struct V_17 ,
V_449 ) ;
F_292 ( & V_18 -> V_347 ) ;
V_448 -> V_337 = V_18 ;
return 0 ;
}
static int F_293 ( struct V_446 * V_446 , struct V_447 * V_448 )
{
struct V_17 * V_18 = V_448 -> V_337 ;
F_190 ( & V_18 -> V_347 , V_350 ) ;
return 0 ;
}
static long F_294 ( struct V_447 * V_448 , unsigned int V_28 , unsigned long V_335 )
{
struct V_17 * V_18 = V_448 -> V_337 ;
struct V_106 * V_107 ;
switch ( V_28 ) {
case V_339 :
return F_178 ( V_18 , NULL , ( void T_10 * ) V_335 ) ;
case V_340 :
if ( F_264 ( & V_18 -> V_423 ) )
return - V_344 ;
V_107 = F_295 ( & V_18 -> V_423 , struct V_106 , V_79 ) ;
return F_178 ( V_18 , V_107 , ( void T_10 * ) V_335 ) ;
default:
return - V_344 ;
}
}
static void F_296 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_18 -> V_237 ; V_78 ++ ) {
V_20 = V_18 -> V_21 [ V_78 ] ;
if ( ! V_20 -> V_14 )
continue;
F_123 ( V_18 -> V_235 [ V_20 -> V_198 ] . V_236 ,
V_20 -> V_14 -> V_450 ) ;
}
}
static int F_297 ( struct V_17 * V_18 )
{
int V_43 ;
bool V_451 = false ;
V_43 = F_226 ( V_18 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_158 ( V_18 ) ;
if ( V_43 )
goto V_316;
F_78 ( & V_217 ) ;
if ( F_264 ( & V_440 ) && F_265 ( V_441 ) ) {
V_451 = true ;
V_441 = NULL ;
}
F_298 ( & V_18 -> V_220 , & V_440 ) ;
F_79 ( & V_217 ) ;
if ( V_451 ) {
V_441 = F_260 ( F_197 , NULL , L_26 ) ;
F_299 ( & V_452 ) ;
} else
F_300 ( V_452 , V_441 ) ;
if ( F_265 ( V_441 ) ) {
V_43 = V_441 ? F_90 ( V_441 ) : - V_173 ;
goto V_427;
}
F_138 ( V_18 -> V_21 [ 0 ] , 0 ) ;
V_43 = F_152 ( V_18 ) ;
if ( V_43 )
goto V_427;
V_43 = F_214 ( V_18 ) ;
if ( V_43 )
goto V_453;
F_296 ( V_18 ) ;
return V_43 ;
V_453:
F_149 ( V_18 ) ;
V_427:
F_127 ( V_18 , 0 ) ;
F_263 ( V_18 ) ;
V_316:
F_238 ( V_18 ) ;
return V_43 ;
}
static int F_301 ( void * V_335 )
{
struct V_17 * V_18 = (struct V_17 * ) V_335 ;
struct V_97 * V_397 = V_18 -> V_97 ;
if ( F_302 ( V_397 ) )
F_303 ( V_397 ) ;
F_190 ( & V_18 -> V_347 , V_350 ) ;
return 0 ;
}
static void F_304 ( struct V_454 * V_455 )
{
struct V_17 * V_18 = F_253 ( V_455 , struct V_17 , V_218 ) ;
F_116 ( V_18 , 1 ) ;
F_274 ( V_18 ) ;
}
static int F_305 ( struct V_17 * V_18 )
{
int V_60 ;
V_60 = F_297 ( V_18 ) ;
if ( V_60 )
return V_60 ;
if ( V_18 -> V_237 < 2 ) {
F_78 ( & V_217 ) ;
V_18 -> V_221 = F_304 ;
F_107 ( V_223 , & V_18 -> V_218 ) ;
F_79 ( & V_217 ) ;
} else {
F_270 ( V_18 ) ;
F_296 ( V_18 ) ;
}
V_18 -> V_229 = 1 ;
return 0 ;
}
static void F_306 ( struct V_17 * V_18 )
{
F_273 ( V_18 ) ;
if ( F_305 ( V_18 ) ) {
F_15 ( & V_18 -> V_97 -> V_18 , L_31 ) ;
F_292 ( & V_18 -> V_347 ) ;
if ( F_89 ( F_260 ( F_301 , V_18 , L_27 ,
V_18 -> V_246 ) ) ) {
F_145 ( & V_18 -> V_97 -> V_18 ,
L_32 ) ;
F_190 ( & V_18 -> V_347 , V_350 ) ;
}
}
}
static void V_222 ( struct V_454 * V_455 )
{
struct V_17 * V_18 = F_253 ( V_455 , struct V_17 , V_218 ) ;
F_306 ( V_18 ) ;
}
static void F_307 ( struct V_454 * V_52 )
{
struct V_17 * V_18 = F_253 ( V_52 , struct V_17 , V_218 ) ;
V_18 -> V_221 ( V_52 ) ;
}
static int F_308 ( struct V_97 * V_397 , const struct V_456 * V_186 )
{
int V_220 , V_43 = - V_274 ;
struct V_17 * V_18 ;
V_220 = F_153 ( & V_397 -> V_18 ) ;
if ( V_220 == V_457 )
F_309 ( & V_397 -> V_18 , 0 ) ;
V_18 = F_205 ( sizeof( * V_18 ) , V_181 , V_220 ) ;
if ( ! V_18 )
return - V_274 ;
V_18 -> V_235 = F_205 ( F_215 () * sizeof( * V_18 -> V_235 ) ,
V_181 , V_220 ) ;
if ( ! V_18 -> V_235 )
goto free;
V_18 -> V_21 = F_205 ( ( F_215 () + 1 ) * sizeof( void * ) ,
V_181 , V_220 ) ;
if ( ! V_18 -> V_21 )
goto free;
F_310 ( & V_18 -> V_423 ) ;
V_18 -> V_221 = V_222 ;
F_311 ( & V_18 -> V_218 , F_307 ) ;
V_18 -> V_97 = F_312 ( V_397 ) ;
F_313 ( V_397 , V_18 ) ;
V_43 = F_281 ( V_18 ) ;
if ( V_43 )
goto V_458;
V_43 = F_277 ( V_18 ) ;
if ( V_43 )
goto V_459;
F_314 ( & V_18 -> V_347 ) ;
V_43 = F_297 ( V_18 ) ;
if ( V_43 )
goto V_460;
if ( V_18 -> V_237 > 1 )
V_43 = F_222 ( V_18 ) ;
if ( V_43 )
goto V_461;
F_315 ( V_18 -> V_248 , sizeof( V_18 -> V_248 ) , L_27 , V_18 -> V_246 ) ;
V_18 -> V_449 . V_462 = V_463 ;
V_18 -> V_449 . V_464 = & V_397 -> V_18 ;
V_18 -> V_449 . V_248 = V_18 -> V_248 ;
V_18 -> V_449 . V_385 = & V_465 ;
V_43 = F_316 ( & V_18 -> V_449 ) ;
if ( V_43 )
goto remove;
F_296 ( V_18 ) ;
V_18 -> V_229 = 1 ;
return 0 ;
remove:
F_274 ( V_18 ) ;
F_149 ( V_18 ) ;
F_286 ( V_18 ) ;
V_461:
F_273 ( V_18 ) ;
V_460:
F_116 ( V_18 , 0 ) ;
F_280 ( V_18 ) ;
V_459:
F_284 ( V_18 ) ;
V_458:
F_289 ( V_18 -> V_97 ) ;
free:
F_41 ( V_18 -> V_21 ) ;
F_41 ( V_18 -> V_235 ) ;
F_41 ( V_18 ) ;
return V_43 ;
}
static void F_317 ( struct V_97 * V_397 , bool V_466 )
{
struct V_17 * V_18 = F_302 ( V_397 ) ;
if ( V_466 )
F_273 ( V_18 ) ;
else
F_305 ( V_18 ) ;
}
static void F_318 ( struct V_97 * V_397 )
{
struct V_17 * V_18 = F_302 ( V_397 ) ;
F_273 ( V_18 ) ;
}
static void F_319 ( struct V_97 * V_397 )
{
struct V_17 * V_18 = F_302 ( V_397 ) ;
F_78 ( & V_217 ) ;
F_106 ( & V_18 -> V_220 ) ;
F_79 ( & V_217 ) ;
F_313 ( V_397 , NULL ) ;
F_320 ( & V_18 -> V_218 ) ;
F_321 ( & V_18 -> V_449 ) ;
F_273 ( V_18 ) ;
F_274 ( V_18 ) ;
F_149 ( V_18 ) ;
F_116 ( V_18 , 0 ) ;
F_280 ( V_18 ) ;
F_190 ( & V_18 -> V_347 , V_350 ) ;
}
static int F_322 ( struct V_241 * V_18 )
{
struct V_97 * V_397 = F_323 ( V_18 ) ;
struct V_17 * V_467 = F_302 ( V_397 ) ;
F_273 ( V_467 ) ;
return 0 ;
}
static int F_324 ( struct V_241 * V_18 )
{
struct V_97 * V_397 = F_323 ( V_18 ) ;
struct V_17 * V_467 = F_302 ( V_397 ) ;
if ( F_305 ( V_467 ) && ! F_105 ( & V_467 -> V_218 ) ) {
V_467 -> V_221 = V_222 ;
F_107 ( V_223 , & V_467 -> V_218 ) ;
}
return 0 ;
}
static int T_14 F_325 ( void )
{
int V_43 ;
F_326 ( & V_452 ) ;
V_223 = F_327 ( L_26 ) ;
if ( ! V_223 )
return - V_274 ;
V_43 = F_328 ( V_383 , L_26 ) ;
if ( V_43 < 0 )
goto V_468;
else if ( V_43 > 0 )
V_383 = V_43 ;
V_43 = F_329 ( & V_469 ) ;
if ( V_43 )
goto V_470;
return 0 ;
V_470:
V_470 ( V_383 , L_26 ) ;
V_468:
F_330 ( V_223 ) ;
return V_43 ;
}
static void T_15 F_331 ( void )
{
F_332 ( & V_469 ) ;
F_333 ( & V_471 ) ;
V_470 ( V_383 , L_26 ) ;
F_330 ( V_223 ) ;
F_7 ( V_441 && ! F_89 ( V_441 ) ) ;
F_1 () ;
}
