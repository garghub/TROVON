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
static int F_3 ( unsigned V_13 , struct V_14 * V_15 )
{
unsigned V_16 = F_4 ( V_13 + V_15 -> V_17 , V_15 -> V_17 ) ;
return F_4 ( 8 * V_16 , V_18 - 8 ) ;
}
static unsigned int F_5 ( struct V_14 * V_15 )
{
unsigned int V_19 = sizeof( struct V_20 ) ;
V_19 += sizeof( struct V_21 ) ;
V_19 += sizeof( V_22 * ) * F_3 ( F_6 ( V_15 ) , V_15 ) ;
V_19 += sizeof( struct V_23 ) * V_24 ;
return V_19 ;
}
static int F_7 ( struct V_25 * V_26 , void * V_27 ,
unsigned int V_28 )
{
struct V_14 * V_15 = V_27 ;
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
F_8 ( V_28 != 0 ) ;
F_8 ( V_15 -> V_32 . V_33 [ 0 ] != V_26 -> V_33 ) ;
F_8 ( V_30 -> V_33 ) ;
V_26 -> V_34 = V_30 ;
V_30 -> V_33 = & V_15 -> V_32 . V_33 [ 0 ] ;
return 0 ;
}
static void F_9 ( struct V_25 * V_26 , unsigned int V_28 )
{
struct V_29 * V_30 = V_26 -> V_34 ;
V_30 -> V_33 = NULL ;
}
static int F_10 ( void * V_27 , struct V_35 * V_36 ,
unsigned int V_28 , unsigned int V_37 ,
unsigned int V_38 )
{
struct V_14 * V_15 = V_27 ;
struct V_20 * V_39 = F_11 ( V_36 ) ;
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
F_12 ( ! V_30 ) ;
V_39 -> V_30 = V_30 ;
return 0 ;
}
static int F_13 ( struct V_25 * V_26 , void * V_27 ,
unsigned int V_28 )
{
struct V_14 * V_15 = V_27 ;
struct V_29 * V_30 = V_15 -> V_31 [ V_28 + 1 ] ;
if ( ! V_30 -> V_33 )
V_30 -> V_33 = & V_15 -> V_40 . V_33 [ V_28 ] ;
F_8 ( V_15 -> V_40 . V_33 [ V_28 ] != V_26 -> V_33 ) ;
V_26 -> V_34 = V_30 ;
return 0 ;
}
static int F_14 ( void * V_27 , struct V_35 * V_36 ,
unsigned int V_28 , unsigned int V_37 ,
unsigned int V_38 )
{
struct V_14 * V_15 = V_27 ;
struct V_20 * V_39 = F_11 ( V_36 ) ;
struct V_29 * V_30 = V_15 -> V_31 [ V_28 + 1 ] ;
F_12 ( ! V_30 ) ;
V_39 -> V_30 = V_30 ;
return 0 ;
}
static void F_15 ( struct V_20 * V_39 , void * V_41 ,
T_1 V_42 )
{
V_39 -> V_43 = V_42 ;
V_39 -> V_41 = V_41 ;
V_39 -> V_44 = 0 ;
F_16 ( F_17 ( V_39 ) ) ;
}
static void * F_18 ( struct V_21 * V_45 )
{
return ( void * ) ( V_45 -> V_46 & ~ 0x1UL ) ;
}
static bool F_19 ( struct V_21 * V_45 )
{
return ( V_45 -> V_46 & V_47 ) == 0 ;
}
static void F_20 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
if ( V_41 == V_50 )
return;
if ( V_41 == V_51 ) {
F_21 ( V_30 -> V_52 ,
L_1 ,
V_49 -> V_53 , F_22 ( & V_49 -> V_54 ) ) ;
return;
}
if ( V_41 == V_55 ) {
F_21 ( V_30 -> V_52 ,
L_2 ,
V_49 -> V_53 , F_22 ( & V_49 -> V_54 ) ) ;
return;
}
F_21 ( V_30 -> V_52 , L_3 , V_41 ) ;
}
static void * F_23 ( struct V_20 * V_39 , T_1 * V_43 )
{
void * V_41 ;
if ( V_43 )
* V_43 = V_39 -> V_43 ;
V_41 = V_39 -> V_41 ;
V_39 -> V_43 = F_20 ;
V_39 -> V_41 = V_50 ;
return V_41 ;
}
static void F_24 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
T_2 V_56 = F_25 ( & V_49 -> V_56 ) ;
T_3 V_57 = F_22 ( & V_49 -> V_57 ) >> 1 ;
if ( V_57 == V_58 || V_57 == V_59 )
++ V_30 -> V_15 -> V_60 ;
if ( V_57 != V_58 )
return;
switch ( V_56 & 0xff07 ) {
case V_61 :
F_26 ( V_30 -> V_52 , L_4 ) ;
F_27 ( & V_30 -> V_15 -> V_62 ) ;
default:
F_21 ( V_30 -> V_52 , L_5 , V_56 ) ;
}
}
static void F_28 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
struct V_35 * V_36 = V_41 ;
T_3 V_57 = F_22 ( & V_49 -> V_57 ) >> 1 ;
T_2 V_56 = F_25 ( & V_49 -> V_56 ) ;
F_29 ( V_36 ) ;
F_21 ( V_30 -> V_52 , L_6 , V_57 , V_56 ) ;
++ V_30 -> V_15 -> V_63 ;
}
static void F_30 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
struct V_64 * V_65 = V_41 ;
V_65 -> V_56 = F_25 ( & V_49 -> V_56 ) ;
V_65 -> V_57 = F_22 ( & V_49 -> V_57 ) >> 1 ;
F_31 ( V_65 -> V_66 , & V_65 -> V_67 ) ;
F_29 ( V_65 -> V_36 ) ;
}
static inline struct V_20 * F_32 ( struct V_29 * V_30 ,
unsigned int V_68 )
{
struct V_35 * V_36 = F_33 ( * V_30 -> V_33 , V_68 ) ;
return F_11 ( V_36 ) ;
}
static void * F_34 ( struct V_29 * V_30 , int V_68 ,
T_1 * V_43 )
{
struct V_20 * V_39 = F_32 ( V_30 , V_68 ) ;
void * V_41 ;
if ( V_68 >= V_30 -> V_69 ) {
* V_43 = F_20 ;
return V_55 ;
}
if ( V_43 )
* V_43 = V_39 -> V_43 ;
V_41 = V_39 -> V_41 ;
V_39 -> V_43 = F_20 ;
V_39 -> V_41 = V_51 ;
return V_41 ;
}
static void F_35 ( struct V_29 * V_30 ,
struct V_8 * V_39 )
{
T_3 V_70 = V_30 -> V_71 ;
if ( V_30 -> V_72 )
F_36 ( & V_30 -> V_72 [ V_70 ] , V_39 , sizeof( * V_39 ) ) ;
else
memcpy ( & V_30 -> V_73 [ V_70 ] , V_39 , sizeof( * V_39 ) ) ;
if ( ++ V_70 == V_30 -> V_69 )
V_70 = 0 ;
F_37 ( V_70 , V_30 -> V_74 ) ;
V_30 -> V_71 = V_70 ;
}
static void F_38 ( struct V_29 * V_30 , struct V_8 * V_39 )
{
unsigned long V_75 ;
F_39 ( & V_30 -> V_76 , V_75 ) ;
F_35 ( V_30 , V_39 ) ;
F_40 ( & V_30 -> V_76 , V_75 ) ;
}
static V_22 * * F_41 ( struct V_21 * V_45 )
{
return ( ( void * ) V_45 ) + V_45 -> V_77 ;
}
static inline void F_42 ( struct V_21 * V_45 , unsigned V_78 ,
unsigned V_79 , unsigned long V_46 )
{
V_45 -> V_46 = V_46 ;
V_45 -> V_77 = F_43 ( struct V_21 , V_80 [ V_79 ] ) ;
V_45 -> V_81 = - 1 ;
V_45 -> V_82 = V_78 ;
V_45 -> V_83 = 0 ;
}
static struct V_21 *
F_44 ( unsigned V_79 , unsigned V_84 , struct V_14 * V_15 ,
unsigned long V_85 , T_4 V_86 )
{
struct V_21 * V_45 = F_45 ( sizeof( struct V_21 ) +
sizeof( V_22 * ) * F_3 ( V_84 , V_15 ) +
sizeof( struct V_23 ) * V_79 , V_86 ) ;
if ( V_45 )
F_42 ( V_45 , V_84 , V_79 , V_85 ) ;
return V_45 ;
}
static struct V_21 * F_46 ( struct V_35 * V_87 , struct V_14 * V_15 ,
T_4 V_86 )
{
unsigned V_13 = ! ( V_87 -> V_88 & V_89 ) ? F_47 ( V_87 ) :
sizeof( struct V_90 ) ;
struct V_21 * V_45 ;
if ( V_87 -> V_91 <= V_24 &&
V_13 <= F_6 ( V_15 ) ) {
struct V_20 * V_39 = F_11 ( V_87 ) ;
V_45 = V_39 -> V_45 ;
F_42 ( V_45 , V_13 , V_87 -> V_91 ,
( unsigned long ) V_87 | V_47 ) ;
return V_45 ;
}
return F_44 ( V_87 -> V_91 , V_13 , V_15 ,
( unsigned long ) V_87 , V_86 ) ;
}
static void F_48 ( struct V_14 * V_15 , struct V_21 * V_45 )
{
const int V_92 = V_15 -> V_17 / 8 - 1 ;
int V_93 ;
V_22 * * V_94 = F_41 ( V_45 ) ;
T_5 V_95 = V_45 -> V_96 ;
if ( V_45 -> V_81 == 0 )
F_49 ( V_15 -> V_97 , V_94 [ 0 ] , V_95 ) ;
for ( V_93 = 0 ; V_93 < V_45 -> V_81 ; V_93 ++ ) {
V_22 * V_98 = V_94 [ V_93 ] ;
T_5 V_99 = F_50 ( V_98 [ V_92 ] ) ;
F_49 ( V_15 -> V_100 , V_98 , V_95 ) ;
V_95 = V_99 ;
}
if ( F_19 ( V_45 ) )
F_51 ( V_45 ) ;
}
static int F_52 ( T_3 V_57 )
{
switch ( V_57 & 0x7ff ) {
case V_58 :
return 0 ;
case V_101 :
return - V_102 ;
default:
return - V_103 ;
}
}
static void F_53 ( T_2 V_104 , T_2 V_105 , struct V_106 * V_107 )
{
if ( F_54 ( V_107 -> V_108 ) == V_105 )
V_107 -> V_108 = F_55 ( V_104 ) ;
}
static void F_56 ( T_2 V_104 , T_2 V_105 , struct V_106 * V_107 )
{
if ( F_54 ( V_107 -> V_108 ) == V_104 )
V_107 -> V_108 = F_55 ( V_105 ) ;
}
static void F_57 ( struct V_35 * V_36 ,
void (* F_58)( T_2 V_104 , T_2 V_105 , struct V_106 * V_107 ) )
{
struct V_109 * V_110 = V_36 -> V_111 -> V_112 ;
struct V_113 * V_114 ;
struct V_106 * V_107 ;
void * V_104 , * V_115 ;
T_2 V_93 , V_116 , V_117 , V_118 , V_119 ;
if ( ! V_110 -> V_120 || V_110 -> V_120 == V_121 )
return;
V_114 = F_59 ( V_36 -> V_122 ) ;
if ( ! V_114 )
return;
V_115 = F_60 ( V_114 -> V_123 -> V_124 ) + V_114 -> V_123 -> V_125 ;
V_104 = V_115 ;
V_119 = F_61 ( V_114 ) ;
V_118 = F_62 ( V_110 , F_63 ( V_36 ) ) ;
V_116 = ( F_47 ( V_36 ) >> V_110 -> V_126 ) ;
V_117 = V_110 -> V_127 -> V_128 -> V_129 ;
for ( V_93 = 0 ; V_93 < V_116 ; V_93 ++ , V_119 ++ , V_118 ++ ) {
V_107 = (struct V_106 * ) V_104 ;
F_58 ( V_118 , V_119 , V_107 ) ;
V_104 += V_117 ;
}
F_64 ( V_115 ) ;
}
static int F_65 ( struct V_130 * V_131 )
{
return 0 ;
}
static int F_66 ( struct V_130 * V_131 )
{
return 0 ;
}
static void F_67 ( struct V_109 * V_110 )
{
struct V_132 V_128 ;
switch ( V_110 -> V_120 ) {
case V_121 :
V_128 = V_133 ;
break;
case V_134 :
case V_135 :
V_128 = V_136 ;
break;
default:
V_128 = V_137 ;
break;
}
V_128 . V_129 = V_110 -> V_138 ;
F_68 ( V_110 -> V_127 , & V_128 ) ;
F_69 ( V_110 -> V_139 , 1 ) ;
}
static void F_57 ( struct V_35 * V_36 ,
void (* F_58)( T_2 V_104 , T_2 V_105 , struct V_106 * V_107 ) )
{
}
static void F_53 ( T_2 V_104 , T_2 V_105 , struct V_106 * V_107 )
{
}
static void F_56 ( T_2 V_104 , T_2 V_105 , struct V_106 * V_107 )
{
}
static void F_67 ( struct V_109 * V_110 )
{
}
static void F_70 ( struct V_29 * V_30 , void * V_41 ,
struct V_48 * V_49 )
{
struct V_21 * V_45 = V_41 ;
struct V_35 * V_36 = F_18 ( V_45 ) ;
struct V_20 * V_140 = F_11 ( V_36 ) ;
T_3 V_57 = F_22 ( & V_49 -> V_57 ) >> 1 ;
bool V_141 = false ;
int error = 0 ;
if ( F_71 ( V_57 ) ) {
if ( ! ( V_57 & V_142 || F_72 ( V_36 ) )
&& ( V_143 - V_36 -> V_144 ) < V_36 -> V_145 ) {
unsigned long V_75 ;
V_141 = true ;
F_73 ( V_36 ) ;
F_39 ( V_36 -> V_146 -> V_147 , V_75 ) ;
if ( ! F_74 ( V_36 -> V_146 ) )
F_75 ( V_36 -> V_146 ) ;
F_40 ( V_36 -> V_146 -> V_147 , V_75 ) ;
goto V_148;
}
if ( V_36 -> V_149 == V_150 ) {
if ( V_140 -> V_41 == V_50 )
error = - V_151 ;
else
error = V_57 ;
} else {
error = F_52 ( V_57 ) ;
}
}
if ( V_36 -> V_149 == V_150 ) {
T_2 V_56 = F_25 ( & V_49 -> V_56 ) ;
V_36 -> V_152 = ( void * ) ( V_153 ) V_56 ;
}
if ( V_140 -> V_44 )
F_21 ( V_30 -> V_15 -> V_15 ,
L_7 ,
error ) ;
V_148:
if ( V_45 -> V_83 ) {
F_76 ( V_30 -> V_15 -> V_15 , V_45 -> V_80 , V_45 -> V_83 ,
F_77 ( V_36 ) ? V_154 : V_155 ) ;
if ( F_78 ( V_36 ) ) {
if ( ! F_77 ( V_36 ) )
F_57 ( V_36 , F_56 ) ;
F_76 ( V_30 -> V_15 -> V_15 , V_45 -> V_156 , 1 ,
F_77 ( V_36 ) ? V_154 : V_155 ) ;
}
}
F_48 ( V_30 -> V_15 , V_45 ) ;
if ( F_79 ( ! V_141 ) )
F_80 ( V_36 , error ) ;
}
static int F_81 ( struct V_14 * V_15 , struct V_21 * V_45 ,
int V_157 , T_4 V_86 )
{
struct V_158 * V_159 ;
int V_82 = V_157 ;
struct V_23 * V_80 = V_45 -> V_80 ;
int V_160 = F_82 ( V_80 ) ;
T_6 V_161 = F_83 ( V_80 ) ;
T_2 V_17 = V_15 -> V_17 ;
int V_77 = V_161 & ( V_17 - 1 ) ;
V_22 * V_98 ;
V_22 * * V_94 = F_41 ( V_45 ) ;
T_5 V_95 ;
int V_16 , V_93 ;
V_82 -= ( V_17 - V_77 ) ;
if ( V_82 <= 0 )
return V_157 ;
V_160 -= ( V_17 - V_77 ) ;
if ( V_160 ) {
V_161 += ( V_17 - V_77 ) ;
} else {
V_80 = F_84 ( V_80 ) ;
V_161 = F_83 ( V_80 ) ;
V_160 = F_82 ( V_80 ) ;
}
if ( V_82 <= V_17 ) {
V_45 -> V_96 = V_161 ;
return V_157 ;
}
V_16 = F_4 ( V_82 , V_17 ) ;
if ( V_16 <= ( 256 / 8 ) ) {
V_159 = V_15 -> V_97 ;
V_45 -> V_81 = 0 ;
} else {
V_159 = V_15 -> V_100 ;
V_45 -> V_81 = 1 ;
}
V_98 = F_85 ( V_159 , V_86 , & V_95 ) ;
if ( ! V_98 ) {
V_45 -> V_96 = V_161 ;
V_45 -> V_81 = - 1 ;
return ( V_157 - V_82 ) + V_17 ;
}
V_94 [ 0 ] = V_98 ;
V_45 -> V_96 = V_95 ;
V_93 = 0 ;
for (; ; ) {
if ( V_93 == V_17 >> 3 ) {
V_22 * V_162 = V_98 ;
V_98 = F_85 ( V_159 , V_86 , & V_95 ) ;
if ( ! V_98 )
return V_157 - V_82 ;
V_94 [ V_45 -> V_81 ++ ] = V_98 ;
V_98 [ 0 ] = V_162 [ V_93 - 1 ] ;
V_162 [ V_93 - 1 ] = F_86 ( V_95 ) ;
V_93 = 1 ;
}
V_98 [ V_93 ++ ] = F_86 ( V_161 ) ;
V_160 -= V_17 ;
V_161 += V_17 ;
V_82 -= V_17 ;
if ( V_82 <= 0 )
break;
if ( V_160 > 0 )
continue;
F_12 ( V_160 < 0 ) ;
V_80 = F_84 ( V_80 ) ;
V_161 = F_83 ( V_80 ) ;
V_160 = F_82 ( V_80 ) ;
}
return V_157 ;
}
static void F_87 ( struct V_29 * V_30 , struct V_35 * V_36 ,
struct V_21 * V_45 )
{
struct V_8 V_163 ;
memcpy ( & V_163 , V_36 -> V_39 , sizeof( V_163 ) ) ;
V_163 . V_164 . V_53 = V_36 -> V_68 ;
if ( V_36 -> V_91 ) {
V_163 . V_164 . V_165 = F_86 ( F_83 ( V_45 -> V_80 ) ) ;
V_163 . V_164 . V_166 = F_86 ( V_45 -> V_96 ) ;
}
F_35 ( V_30 , & V_163 ) ;
}
static void F_88 ( struct V_29 * V_30 , struct V_109 * V_110 ,
struct V_35 * V_36 , struct V_21 * V_45 )
{
struct V_90 * V_167 =
(struct V_90 * ) F_41 ( V_45 ) [ 0 ] ;
struct V_8 V_163 ;
V_167 -> V_168 = F_89 ( 0 ) ;
V_167 -> V_116 = F_89 ( F_47 ( V_36 ) >> V_110 -> V_126 ) ;
V_167 -> V_169 = F_86 ( F_62 ( V_110 , F_63 ( V_36 ) ) ) ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_170 . V_171 = V_172 ;
V_163 . V_170 . V_53 = V_36 -> V_68 ;
V_163 . V_170 . V_173 = F_89 ( V_110 -> V_174 ) ;
V_163 . V_170 . V_165 = F_86 ( V_45 -> V_96 ) ;
V_163 . V_170 . V_175 = 0 ;
V_163 . V_170 . V_176 = F_89 ( V_177 ) ;
F_35 ( V_30 , & V_163 ) ;
}
static void F_90 ( struct V_29 * V_30 , struct V_109 * V_110 ,
int V_178 )
{
struct V_8 V_163 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_179 . V_171 = V_180 ;
V_163 . V_179 . V_53 = V_178 ;
V_163 . V_179 . V_173 = F_89 ( V_110 -> V_174 ) ;
F_35 ( V_30 , & V_163 ) ;
}
static int F_91 ( struct V_29 * V_30 , struct V_21 * V_45 ,
struct V_109 * V_110 )
{
struct V_35 * V_36 = F_18 ( V_45 ) ;
struct V_8 V_163 ;
T_3 V_181 = 0 ;
T_2 V_182 = 0 ;
if ( V_36 -> V_88 & V_183 )
V_181 |= V_184 ;
if ( V_36 -> V_88 & ( V_185 | V_186 ) )
V_181 |= V_187 ;
if ( V_36 -> V_88 & V_186 )
V_182 |= V_188 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_164 . V_171 = ( F_77 ( V_36 ) ? V_189 : V_190 ) ;
V_163 . V_164 . V_53 = V_36 -> V_68 ;
V_163 . V_164 . V_173 = F_89 ( V_110 -> V_174 ) ;
V_163 . V_164 . V_165 = F_86 ( F_83 ( V_45 -> V_80 ) ) ;
V_163 . V_164 . V_166 = F_86 ( V_45 -> V_96 ) ;
V_163 . V_164 . V_169 = F_86 ( F_62 ( V_110 , F_63 ( V_36 ) ) ) ;
V_163 . V_164 . V_82 = F_92 ( ( F_47 ( V_36 ) >> V_110 -> V_126 ) - 1 ) ;
if ( V_110 -> V_138 ) {
switch ( V_110 -> V_120 ) {
case V_121 :
V_181 |= V_191 ;
break;
case V_134 :
case V_135 :
V_181 |= V_191 |
V_192 ;
V_163 . V_164 . V_193 = F_89 (
F_62 ( V_110 , F_63 ( V_36 ) ) ) ;
break;
}
if ( F_78 ( V_36 ) )
V_163 . V_164 . V_194 =
F_86 ( F_83 ( V_45 -> V_156 ) ) ;
else
V_181 |= V_195 ;
}
V_163 . V_164 . V_181 = F_92 ( V_181 ) ;
V_163 . V_164 . V_182 = F_89 ( V_182 ) ;
F_35 ( V_30 , & V_163 ) ;
return 0 ;
}
static int F_93 ( struct V_25 * V_26 ,
const struct V_196 * V_197 )
{
struct V_109 * V_110 = V_26 -> V_139 -> V_198 ;
struct V_29 * V_30 = V_26 -> V_34 ;
struct V_14 * V_15 = V_30 -> V_15 ;
struct V_35 * V_36 = V_197 -> V_87 ;
struct V_20 * V_39 = F_11 ( V_36 ) ;
struct V_21 * V_45 ;
enum V_199 V_200 ;
if ( V_110 && V_110 -> V_138 && ! F_78 ( V_36 ) ) {
if ( ! ( V_110 -> V_120 && V_110 -> V_138 == 8 ) &&
V_36 -> V_149 != V_150 ) {
F_80 ( V_36 , - V_201 ) ;
return V_202 ;
}
}
V_45 = F_46 ( V_36 , V_15 , V_203 ) ;
if ( ! V_45 )
return V_204 ;
if ( V_36 -> V_88 & V_89 ) {
void * V_167 ;
V_167 = F_85 ( V_15 -> V_97 , V_203 ,
& V_45 -> V_96 ) ;
if ( ! V_167 )
goto V_205;
F_41 ( V_45 ) [ 0 ] = ( V_22 * ) V_167 ;
V_45 -> V_81 = 0 ;
} else if ( V_36 -> V_91 ) {
V_200 = F_77 ( V_36 ) ? V_154 : V_155 ;
F_94 ( V_45 -> V_80 , V_36 -> V_91 ) ;
V_45 -> V_83 = F_95 ( V_36 -> V_146 , V_36 , V_45 -> V_80 ) ;
if ( ! V_45 -> V_83 )
goto V_206;
if ( ! F_96 ( V_30 -> V_52 , V_45 -> V_80 , V_45 -> V_83 , V_200 ) )
goto V_205;
if ( F_47 ( V_36 ) !=
F_81 ( V_15 , V_45 , F_47 ( V_36 ) , V_203 ) ) {
F_76 ( V_15 -> V_15 , V_45 -> V_80 , V_45 -> V_83 , V_200 ) ;
goto V_205;
}
if ( F_78 ( V_36 ) ) {
if ( F_97 ( V_36 -> V_146 , V_36 -> V_122 ) != 1 )
goto V_206;
F_94 ( V_45 -> V_156 , 1 ) ;
if ( F_98 (
V_36 -> V_146 , V_36 -> V_122 , V_45 -> V_156 ) != 1 )
goto V_206;
if ( F_77 ( V_36 ) )
F_57 ( V_36 , F_53 ) ;
if ( ! F_96 ( V_30 -> V_52 , V_45 -> V_156 , 1 , V_200 ) )
goto V_206;
}
}
F_15 ( V_39 , V_45 , F_70 ) ;
F_99 ( & V_30 -> V_76 ) ;
if ( V_36 -> V_149 == V_150 )
F_87 ( V_30 , V_36 , V_45 ) ;
else if ( V_36 -> V_88 & V_89 )
F_88 ( V_30 , V_110 , V_36 , V_45 ) ;
else if ( V_36 -> V_88 & V_207 )
F_90 ( V_30 , V_110 , V_36 -> V_68 ) ;
else
F_91 ( V_30 , V_45 , V_110 ) ;
F_100 ( V_30 ) ;
F_101 ( & V_30 -> V_76 ) ;
return V_202 ;
V_206:
F_48 ( V_15 , V_45 ) ;
return V_208 ;
V_205:
F_48 ( V_15 , V_45 ) ;
return V_204 ;
}
static int F_100 ( struct V_29 * V_30 )
{
T_3 V_209 , V_210 ;
V_209 = V_30 -> V_211 ;
V_210 = V_30 -> V_212 ;
for (; ; ) {
void * V_41 ;
T_1 V_43 ;
struct V_48 V_49 = V_30 -> V_213 [ V_209 ] ;
if ( ( F_102 ( V_49 . V_57 ) & 1 ) != V_210 )
break;
V_30 -> V_214 = F_102 ( V_49 . V_214 ) ;
if ( ++ V_209 == V_30 -> V_69 ) {
V_209 = 0 ;
V_210 = ! V_210 ;
}
V_41 = F_34 ( V_30 , V_49 . V_53 , & V_43 ) ;
V_43 ( V_30 , V_41 , & V_49 ) ;
}
if ( V_209 == V_30 -> V_211 && V_210 == V_30 -> V_212 )
return 0 ;
F_37 ( V_209 , V_30 -> V_74 + V_30 -> V_15 -> V_215 ) ;
V_30 -> V_211 = V_209 ;
V_30 -> V_212 = V_210 ;
V_30 -> V_216 = 1 ;
return 1 ;
}
static T_7 F_103 ( int V_217 , void * V_27 )
{
T_7 V_56 ;
struct V_29 * V_30 = V_27 ;
F_104 ( & V_30 -> V_76 ) ;
F_100 ( V_30 ) ;
V_56 = V_30 -> V_216 ? V_218 : V_219 ;
V_30 -> V_216 = 0 ;
F_105 ( & V_30 -> V_76 ) ;
return V_56 ;
}
static T_7 F_106 ( int V_217 , void * V_27 )
{
struct V_29 * V_30 = V_27 ;
struct V_48 V_49 = V_30 -> V_213 [ V_30 -> V_211 ] ;
if ( ( F_102 ( V_49 . V_57 ) & 1 ) != V_30 -> V_212 )
return V_219 ;
return V_220 ;
}
int F_107 ( struct V_221 * V_146 , struct V_8 * V_39 ,
void * V_222 , void T_8 * V_223 , unsigned V_224 ,
T_2 * V_56 , unsigned V_145 )
{
bool V_225 = V_39 -> V_179 . V_171 & 1 ;
struct V_122 * V_122 = NULL ;
struct V_35 * V_36 ;
int V_19 ;
V_36 = F_108 ( V_146 , V_225 , V_226 , false ) ;
if ( F_109 ( V_36 ) )
return F_110 ( V_36 ) ;
V_36 -> V_149 = V_150 ;
V_36 -> V_88 |= V_227 ;
V_36 -> V_228 = 0 ;
V_36 -> V_229 = ( V_230 ) - 1 ;
V_36 -> V_122 = V_36 -> V_231 = NULL ;
V_36 -> V_145 = V_145 ? V_145 : V_232 ;
V_36 -> V_39 = ( unsigned char * ) V_39 ;
V_36 -> V_233 = sizeof( struct V_8 ) ;
V_36 -> V_152 = ( void * ) 0 ;
if ( V_222 && V_224 ) {
V_19 = F_111 ( V_146 , V_36 , V_222 , V_224 , V_234 ) ;
if ( V_19 )
goto V_235;
} else if ( V_223 && V_224 ) {
V_19 = F_112 ( V_146 , V_36 , NULL , V_223 , V_224 , V_234 ) ;
if ( V_19 )
goto V_235;
V_122 = V_36 -> V_122 ;
}
F_113 ( V_36 -> V_146 , NULL , V_36 , 0 ) ;
if ( V_122 )
F_114 ( V_122 ) ;
if ( V_56 )
* V_56 = ( T_2 ) ( V_153 ) V_36 -> V_152 ;
V_19 = V_36 -> V_236 ;
V_235:
F_29 ( V_36 ) ;
return V_19 ;
}
int F_115 ( struct V_221 * V_146 , struct V_8 * V_39 ,
void * V_222 , unsigned V_224 )
{
return F_107 ( V_146 , V_39 , V_222 , NULL , V_224 , NULL , 0 ) ;
}
static int F_116 ( struct V_14 * V_15 )
{
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
struct V_8 V_237 ;
struct V_20 * V_238 ;
struct V_35 * V_36 ;
V_36 = F_108 ( V_15 -> V_239 , V_240 , V_203 , true ) ;
if ( F_109 ( V_36 ) )
return F_110 ( V_36 ) ;
V_36 -> V_88 |= V_241 ;
V_238 = F_11 ( V_36 ) ;
F_15 ( V_238 , NULL , F_24 ) ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_179 . V_171 = V_242 ;
V_237 . V_179 . V_53 = V_36 -> V_68 ;
F_29 ( V_36 ) ;
F_35 ( V_30 , & V_237 ) ;
return 0 ;
}
static int F_117 ( struct V_14 * V_15 ,
struct V_8 * V_39 ,
struct V_64 * V_65 , unsigned V_145 )
{
struct V_29 * V_30 = V_15 -> V_31 [ 0 ] ;
struct V_35 * V_36 ;
struct V_20 * V_140 ;
V_36 = F_108 ( V_15 -> V_239 , V_240 , V_226 , false ) ;
if ( F_109 ( V_36 ) )
return F_110 ( V_36 ) ;
V_36 -> V_145 = V_145 ;
V_140 = F_11 ( V_36 ) ;
V_65 -> V_36 = V_36 ;
F_15 ( V_140 , V_65 , F_30 ) ;
V_65 -> V_57 = - V_151 ;
V_39 -> V_179 . V_53 = V_36 -> V_68 ;
F_38 ( V_30 , V_39 ) ;
return 0 ;
}
static int F_118 ( struct V_14 * V_15 , T_9 V_171 , T_3 V_243 )
{
struct V_8 V_237 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_244 . V_171 = V_171 ;
V_237 . V_244 . V_245 = F_92 ( V_243 ) ;
return F_115 ( V_15 -> V_239 , & V_237 , NULL , 0 ) ;
}
static int F_119 ( struct V_14 * V_15 , T_3 V_245 ,
struct V_29 * V_30 )
{
struct V_8 V_237 ;
int V_75 = V_246 | V_247 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_248 . V_171 = V_249 ;
V_237 . V_248 . V_165 = F_86 ( V_30 -> V_250 ) ;
V_237 . V_248 . V_251 = F_92 ( V_245 ) ;
V_237 . V_248 . V_252 = F_92 ( V_30 -> V_69 - 1 ) ;
V_237 . V_248 . V_253 = F_92 ( V_75 ) ;
V_237 . V_248 . V_254 = F_92 ( V_30 -> V_255 ) ;
return F_115 ( V_15 -> V_239 , & V_237 , NULL , 0 ) ;
}
static int F_120 ( struct V_14 * V_15 , T_3 V_245 ,
struct V_29 * V_30 )
{
struct V_8 V_237 ;
int V_75 = V_246 | V_256 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_257 . V_171 = V_258 ;
V_237 . V_257 . V_165 = F_86 ( V_30 -> V_259 ) ;
V_237 . V_257 . V_260 = F_92 ( V_245 ) ;
V_237 . V_257 . V_252 = F_92 ( V_30 -> V_69 - 1 ) ;
V_237 . V_257 . V_261 = F_92 ( V_75 ) ;
V_237 . V_257 . V_251 = F_92 ( V_245 ) ;
return F_115 ( V_15 -> V_239 , & V_237 , NULL , 0 ) ;
}
static int F_121 ( struct V_14 * V_15 , T_3 V_251 )
{
return F_118 ( V_15 , V_262 , V_251 ) ;
}
static int F_122 ( struct V_14 * V_15 , T_3 V_260 )
{
return F_118 ( V_15 , V_263 , V_260 ) ;
}
int F_123 ( struct V_14 * V_15 , struct V_9 * * V_243 )
{
struct V_8 V_237 = { } ;
int error ;
V_237 . V_264 . V_171 = V_265 ;
V_237 . V_264 . V_266 = F_89 ( 1 ) ;
* V_243 = F_45 ( sizeof( struct V_9 ) , V_226 ) ;
if ( ! * V_243 )
return - V_267 ;
error = F_115 ( V_15 -> V_239 , & V_237 , * V_243 ,
sizeof( struct V_9 ) ) ;
if ( error )
F_51 ( * V_243 ) ;
return error ;
}
int F_124 ( struct V_14 * V_15 , unsigned V_173 ,
struct V_10 * * V_243 )
{
struct V_8 V_237 = { } ;
int error ;
V_237 . V_264 . V_171 = V_265 ,
V_237 . V_264 . V_173 = F_89 ( V_173 ) ,
* V_243 = F_45 ( sizeof( struct V_10 ) , V_226 ) ;
if ( ! * V_243 )
return - V_267 ;
error = F_115 ( V_15 -> V_239 , & V_237 , * V_243 ,
sizeof( struct V_10 ) ) ;
if ( error )
F_51 ( * V_243 ) ;
return error ;
}
int F_125 ( struct V_14 * V_15 , unsigned V_268 , unsigned V_173 ,
T_5 V_161 , T_2 * V_56 )
{
struct V_8 V_237 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_269 . V_171 = V_270 ;
V_237 . V_269 . V_173 = F_89 ( V_173 ) ;
V_237 . V_269 . V_165 = F_86 ( V_161 ) ;
V_237 . V_269 . V_268 = F_89 ( V_268 ) ;
return F_107 ( V_15 -> V_239 , & V_237 , NULL , NULL , 0 ,
V_56 , 0 ) ;
}
int F_126 ( struct V_14 * V_15 , unsigned V_268 , unsigned V_271 ,
T_5 V_161 , T_2 * V_56 )
{
struct V_8 V_237 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_269 . V_171 = V_272 ;
V_237 . V_269 . V_165 = F_86 ( V_161 ) ;
V_237 . V_269 . V_268 = F_89 ( V_268 ) ;
V_237 . V_269 . V_271 = F_89 ( V_271 ) ;
return F_107 ( V_15 -> V_239 , & V_237 , NULL , NULL , 0 ,
V_56 , 0 ) ;
}
int F_127 ( struct V_14 * V_15 , struct V_12 * * log )
{
struct V_8 V_237 = { } ;
int error ;
V_237 . V_179 . V_171 = V_273 ,
V_237 . V_179 . V_173 = F_89 ( 0xFFFFFFFF ) ,
V_237 . V_179 . V_274 [ 0 ] = F_89 (
( ( ( sizeof( struct V_12 ) / 4 ) - 1 ) << 16 ) |
V_275 ) ,
* log = F_45 ( sizeof( struct V_12 ) , V_226 ) ;
if ( ! * log )
return - V_267 ;
error = F_115 ( V_15 -> V_239 , & V_237 , * log ,
sizeof( struct V_12 ) ) ;
if ( error )
F_51 ( * log ) ;
return error ;
}
static void F_128 ( struct V_35 * V_36 )
{
struct V_20 * V_140 = F_11 ( V_36 ) ;
struct V_29 * V_30 = V_140 -> V_30 ;
struct V_14 * V_15 = V_30 -> V_15 ;
struct V_35 * V_276 ;
struct V_20 * V_277 ;
struct V_8 V_39 ;
if ( ! V_30 -> V_245 || V_140 -> V_44 ) {
unsigned long V_75 ;
F_39 ( & V_278 , V_75 ) ;
if ( F_129 ( & V_15 -> V_279 ) )
goto V_235;
F_130 ( & V_15 -> V_280 ) ;
F_21 ( V_15 -> V_15 , L_8 ,
V_36 -> V_68 , V_30 -> V_245 ) ;
V_15 -> V_281 = V_282 ;
F_131 ( V_283 , & V_15 -> V_279 ) ;
V_235:
F_40 ( & V_278 , V_75 ) ;
return;
}
if ( ! V_15 -> V_63 )
return;
V_276 = F_108 ( V_15 -> V_239 , V_240 , V_203 ,
false ) ;
if ( F_109 ( V_276 ) )
return;
V_277 = F_11 ( V_276 ) ;
F_15 ( V_277 , V_276 , F_28 ) ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . abort . V_171 = V_284 ;
V_39 . abort . V_285 = V_36 -> V_68 ;
V_39 . abort . V_260 = F_92 ( V_30 -> V_245 ) ;
V_39 . abort . V_53 = V_276 -> V_68 ;
-- V_15 -> V_63 ;
V_140 -> V_44 = 1 ;
F_21 ( V_30 -> V_52 , L_9 , V_36 -> V_68 ,
V_30 -> V_245 ) ;
F_38 ( V_15 -> V_31 [ 0 ] , & V_39 ) ;
}
static void F_132 ( struct V_35 * V_36 , void * V_27 , bool V_286 )
{
struct V_29 * V_30 = V_27 ;
void * V_41 ;
T_1 V_43 ;
struct V_20 * V_39 ;
struct V_48 V_49 ;
if ( ! F_133 ( V_36 ) )
return;
V_39 = F_11 ( V_36 ) ;
if ( V_39 -> V_41 == V_50 )
return;
if ( F_134 ( V_36 -> V_146 ) )
V_49 . V_57 = F_92 ( ( V_59 | V_142 ) << 1 ) ;
else
V_49 . V_57 = F_92 ( V_59 << 1 ) ;
F_21 ( V_30 -> V_52 , L_10 ,
V_36 -> V_68 , V_30 -> V_245 ) ;
V_41 = F_23 ( V_39 , & V_43 ) ;
V_43 ( V_30 , V_41 , & V_49 ) ;
}
static enum V_287 F_135 ( struct V_35 * V_36 , bool V_286 )
{
struct V_20 * V_39 = F_11 ( V_36 ) ;
struct V_29 * V_30 = V_39 -> V_30 ;
F_21 ( V_30 -> V_52 , L_11 , V_36 -> V_68 ,
V_30 -> V_245 ) ;
F_99 ( & V_30 -> V_76 ) ;
F_128 ( V_36 ) ;
F_101 ( & V_30 -> V_76 ) ;
return V_288 ;
}
static void F_136 ( struct V_29 * V_30 )
{
F_137 ( V_30 -> V_52 , F_138 ( V_30 -> V_69 ) ,
( void * ) V_30 -> V_213 , V_30 -> V_250 ) ;
if ( V_30 -> V_73 )
F_137 ( V_30 -> V_52 , F_139 ( V_30 -> V_69 ) ,
V_30 -> V_73 , V_30 -> V_259 ) ;
F_51 ( V_30 ) ;
}
static void F_140 ( struct V_14 * V_15 , int V_289 )
{
int V_93 ;
for ( V_93 = V_15 -> V_290 - 1 ; V_93 >= V_289 ; V_93 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_93 ] ;
V_15 -> V_290 -- ;
V_15 -> V_31 [ V_93 ] = NULL ;
F_136 ( V_30 ) ;
}
}
static int F_141 ( struct V_29 * V_30 )
{
int V_291 ;
F_99 ( & V_30 -> V_76 ) ;
if ( V_30 -> V_255 == - 1 ) {
F_101 ( & V_30 -> V_76 ) ;
return 1 ;
}
V_291 = V_30 -> V_15 -> V_292 [ V_30 -> V_255 ] . V_291 ;
V_30 -> V_15 -> V_293 -- ;
V_30 -> V_255 = - 1 ;
F_101 ( & V_30 -> V_76 ) ;
if ( ! V_30 -> V_245 && V_30 -> V_15 -> V_239 )
F_142 ( V_30 -> V_15 -> V_239 ) ;
F_143 ( V_291 , NULL ) ;
F_144 ( V_291 , V_30 ) ;
return 0 ;
}
static void F_145 ( struct V_29 * V_30 )
{
F_99 ( & V_30 -> V_76 ) ;
if ( V_30 -> V_33 && * V_30 -> V_33 )
F_146 ( * V_30 -> V_33 , F_132 , V_30 ) ;
F_101 ( & V_30 -> V_76 ) ;
}
static void F_147 ( struct V_14 * V_15 , int V_245 )
{
struct V_29 * V_30 = V_15 -> V_31 [ V_245 ] ;
if ( ! V_30 )
return;
if ( F_141 ( V_30 ) )
return;
if ( V_245 && F_148 ( & V_15 -> V_294 -> V_295 ) != - 1 ) {
F_122 ( V_15 , V_245 ) ;
F_121 ( V_15 , V_245 ) ;
}
F_99 ( & V_30 -> V_76 ) ;
F_100 ( V_30 ) ;
F_101 ( & V_30 -> V_76 ) ;
}
static int F_149 ( struct V_14 * V_15 , int V_296 ,
int V_297 )
{
int V_69 = V_15 -> V_69 ;
unsigned V_298 = F_150 ( V_69 * V_297 , V_15 -> V_17 ) ;
if ( V_298 * V_296 > V_15 -> V_299 ) {
T_6 V_300 = F_151 ( V_15 -> V_299 , V_296 ) ;
V_300 = F_152 ( V_300 , V_15 -> V_17 ) ;
V_69 = F_151 ( V_300 , V_297 ) ;
if ( V_69 < 64 )
return - V_267 ;
}
return V_69 ;
}
static int F_153 ( struct V_14 * V_15 , struct V_29 * V_30 ,
int V_245 , int V_301 )
{
if ( V_245 && V_15 -> V_302 && V_303 && F_154 ( V_15 -> V_304 ) ) {
unsigned V_77 = ( V_245 - 1 ) *
F_150 ( F_139 ( V_301 ) , V_15 -> V_17 ) ;
V_30 -> V_259 = V_15 -> V_305 + V_77 ;
V_30 -> V_72 = V_15 -> V_302 + V_77 ;
} else {
V_30 -> V_73 = F_155 ( V_15 -> V_15 , F_139 ( V_301 ) ,
& V_30 -> V_259 , V_226 ) ;
if ( ! V_30 -> V_73 )
return - V_267 ;
}
return 0 ;
}
static struct V_29 * F_156 ( struct V_14 * V_15 , int V_245 ,
int V_301 )
{
struct V_29 * V_30 = F_157 ( sizeof( * V_30 ) , V_226 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_213 = F_158 ( V_15 -> V_15 , F_138 ( V_301 ) ,
& V_30 -> V_250 , V_226 ) ;
if ( ! V_30 -> V_213 )
goto V_306;
if ( F_153 ( V_15 , V_30 , V_245 , V_301 ) )
goto V_307;
V_30 -> V_52 = V_15 -> V_15 ;
V_30 -> V_15 = V_15 ;
snprintf ( V_30 -> V_308 , sizeof( V_30 -> V_308 ) , L_12 ,
V_15 -> V_309 , V_245 ) ;
F_159 ( & V_30 -> V_76 ) ;
V_30 -> V_211 = 0 ;
V_30 -> V_212 = 1 ;
V_30 -> V_74 = & V_15 -> V_310 [ V_245 * 2 * V_15 -> V_215 ] ;
V_30 -> V_69 = V_301 ;
V_30 -> V_245 = V_245 ;
V_30 -> V_255 = - 1 ;
V_15 -> V_31 [ V_245 ] = V_30 ;
F_160 () ;
V_15 -> V_290 ++ ;
return V_30 ;
V_307:
F_137 ( V_15 -> V_15 , F_138 ( V_301 ) , ( void * ) V_30 -> V_213 ,
V_30 -> V_250 ) ;
V_306:
F_51 ( V_30 ) ;
return NULL ;
}
static int F_161 ( struct V_14 * V_15 , struct V_29 * V_30 ,
const char * V_311 )
{
if ( V_312 )
return F_162 ( V_15 -> V_292 [ V_30 -> V_255 ] . V_291 ,
F_106 , F_103 , V_313 ,
V_311 , V_30 ) ;
return F_163 ( V_15 -> V_292 [ V_30 -> V_255 ] . V_291 , F_103 ,
V_313 , V_311 , V_30 ) ;
}
static void F_164 ( struct V_29 * V_30 , T_3 V_245 )
{
struct V_14 * V_15 = V_30 -> V_15 ;
F_99 ( & V_30 -> V_76 ) ;
V_30 -> V_71 = 0 ;
V_30 -> V_211 = 0 ;
V_30 -> V_212 = 1 ;
V_30 -> V_74 = & V_15 -> V_310 [ V_245 * 2 * V_15 -> V_215 ] ;
memset ( ( void * ) V_30 -> V_213 , 0 , F_138 ( V_30 -> V_69 ) ) ;
V_15 -> V_293 ++ ;
F_101 ( & V_30 -> V_76 ) ;
}
static int F_165 ( struct V_29 * V_30 , int V_245 )
{
struct V_14 * V_15 = V_30 -> V_15 ;
int V_56 ;
V_30 -> V_255 = V_245 - 1 ;
V_56 = F_119 ( V_15 , V_245 , V_30 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_120 ( V_15 , V_245 , V_30 ) ;
if ( V_56 < 0 )
goto V_314;
V_56 = F_161 ( V_15 , V_30 , V_30 -> V_308 ) ;
if ( V_56 < 0 )
goto V_315;
F_164 ( V_30 , V_245 ) ;
return V_56 ;
V_315:
F_122 ( V_15 , V_245 ) ;
V_314:
F_121 ( V_15 , V_245 ) ;
return V_56 ;
}
static int F_166 ( struct V_14 * V_15 , T_6 V_316 , bool V_317 )
{
unsigned long V_145 ;
T_2 V_318 = V_317 ? V_319 : 0 ;
V_145 = ( ( F_167 ( V_316 ) + 1 ) * V_320 / 2 ) + V_143 ;
while ( ( F_148 ( & V_15 -> V_294 -> V_295 ) & V_319 ) != V_318 ) {
F_168 ( 100 ) ;
if ( F_169 ( V_321 ) )
return - V_151 ;
if ( F_170 ( V_143 , V_145 ) ) {
F_171 ( V_15 -> V_15 ,
L_13 , V_317 ?
L_14 : L_15 ) ;
return - V_322 ;
}
}
return 0 ;
}
static int F_172 ( struct V_14 * V_15 , T_6 V_316 )
{
V_15 -> V_323 &= ~ V_324 ;
V_15 -> V_323 &= ~ V_325 ;
F_37 ( V_15 -> V_323 , & V_15 -> V_294 -> V_326 ) ;
return F_166 ( V_15 , V_316 , false ) ;
}
static int F_173 ( struct V_14 * V_15 , T_6 V_316 )
{
V_15 -> V_323 &= ~ V_324 ;
V_15 -> V_323 |= V_325 ;
F_37 ( V_15 -> V_323 , & V_15 -> V_294 -> V_326 ) ;
return F_166 ( V_15 , V_316 , true ) ;
}
static int F_174 ( struct V_14 * V_15 )
{
unsigned long V_145 ;
V_15 -> V_323 &= ~ V_324 ;
V_15 -> V_323 |= V_327 ;
F_37 ( V_15 -> V_323 , & V_15 -> V_294 -> V_326 ) ;
V_145 = V_328 + V_143 ;
while ( ( F_148 ( & V_15 -> V_294 -> V_295 ) & V_329 ) !=
V_330 ) {
F_168 ( 100 ) ;
if ( F_169 ( V_321 ) )
return - V_151 ;
if ( F_170 ( V_143 , V_145 ) ) {
F_171 ( V_15 -> V_15 ,
L_16 ) ;
return - V_322 ;
}
}
return 0 ;
}
static void F_175 ( struct V_14 * V_15 )
{
if ( V_15 -> V_239 && ! F_134 ( V_15 -> V_239 ) ) {
F_176 ( V_15 -> V_239 ) ;
F_177 ( & V_15 -> V_32 ) ;
}
}
static int F_178 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_239 ) {
V_15 -> V_32 . V_331 = & V_332 ;
V_15 -> V_32 . V_333 = 1 ;
V_15 -> V_32 . V_334 = V_335 - 1 ;
V_15 -> V_32 . V_336 = 1 ;
V_15 -> V_32 . V_145 = V_232 ;
V_15 -> V_32 . V_38 = F_179 ( V_15 -> V_15 ) ;
V_15 -> V_32 . V_337 = F_5 ( V_15 ) ;
V_15 -> V_32 . V_34 = V_15 ;
if ( F_180 ( & V_15 -> V_32 ) )
return - V_267 ;
V_15 -> V_239 = F_181 ( & V_15 -> V_32 ) ;
if ( F_109 ( V_15 -> V_239 ) ) {
F_177 ( & V_15 -> V_32 ) ;
return - V_267 ;
}
if ( ! F_182 ( V_15 -> V_239 ) ) {
F_175 ( V_15 ) ;
V_15 -> V_239 = NULL ;
return - V_322 ;
}
} else
F_183 ( V_15 -> V_239 ) ;
return 0 ;
}
static int F_184 ( struct V_14 * V_15 )
{
int V_56 ;
T_2 V_338 ;
T_6 V_316 = F_185 ( & V_15 -> V_294 -> V_316 ) ;
struct V_29 * V_30 ;
unsigned V_339 = V_340 ;
unsigned V_341 = F_186 ( V_316 ) + 12 ;
unsigned V_342 = F_187 ( V_316 ) + 12 ;
if ( V_339 < V_341 ) {
F_171 ( V_15 -> V_15 ,
L_17
L_18 , 1 << V_341 ,
1 << V_339 ) ;
return - V_322 ;
}
if ( V_339 > V_342 ) {
F_26 ( V_15 -> V_15 ,
L_19
L_20 ,
1 << V_342 , 1 << V_339 ) ;
V_339 = V_342 ;
}
V_15 -> V_343 = F_148 ( & V_15 -> V_294 -> V_344 ) >= F_188 ( 1 , 1 ) ?
F_189 ( V_316 ) : 0 ;
if ( V_15 -> V_343 && ( F_148 ( & V_15 -> V_294 -> V_295 ) & V_345 ) )
F_37 ( V_345 , & V_15 -> V_294 -> V_295 ) ;
V_56 = F_172 ( V_15 , V_316 ) ;
if ( V_56 < 0 )
return V_56 ;
V_30 = V_15 -> V_31 [ 0 ] ;
if ( ! V_30 ) {
V_30 = F_156 ( V_15 , 0 , V_335 ) ;
if ( ! V_30 )
return - V_267 ;
}
V_338 = V_30 -> V_69 - 1 ;
V_338 |= V_338 << 16 ;
V_15 -> V_17 = 1 << V_339 ;
V_15 -> V_323 = V_346 ;
V_15 -> V_323 |= ( V_339 - 12 ) << V_347 ;
V_15 -> V_323 |= V_348 | V_349 ;
V_15 -> V_323 |= V_350 | V_351 ;
F_37 ( V_338 , & V_15 -> V_294 -> V_338 ) ;
F_190 ( V_30 -> V_259 , & V_15 -> V_294 -> V_352 ) ;
F_190 ( V_30 -> V_250 , & V_15 -> V_294 -> V_353 ) ;
V_56 = F_173 ( V_15 , V_316 ) ;
if ( V_56 )
goto V_306;
V_30 -> V_255 = 0 ;
V_56 = F_161 ( V_15 , V_30 , V_30 -> V_308 ) ;
if ( V_56 ) {
V_30 -> V_255 = - 1 ;
goto V_306;
}
return V_56 ;
V_306:
F_140 ( V_15 , 0 ) ;
return V_56 ;
}
static int F_191 ( struct V_109 * V_110 , struct V_354 T_8 * V_355 )
{
struct V_14 * V_15 = V_110 -> V_15 ;
struct V_354 V_356 ;
struct V_8 V_237 ;
unsigned V_82 , V_357 ;
int V_57 , V_225 ;
T_5 V_358 = 0 ;
void * V_359 = NULL ;
void T_8 * V_194 ;
if ( F_192 ( & V_356 , V_355 , sizeof( V_356 ) ) )
return - V_201 ;
switch ( V_356 . V_171 ) {
case V_189 :
case V_190 :
case V_360 :
break;
default:
return - V_361 ;
}
V_82 = ( V_356 . V_362 + 1 ) << V_110 -> V_126 ;
V_357 = ( V_356 . V_362 + 1 ) * V_110 -> V_138 ;
V_194 = ( void T_8 * ) ( V_153 ) V_356 . V_194 ;
V_225 = V_356 . V_171 & 1 ;
if ( V_110 -> V_363 ) {
V_82 += V_357 ;
V_357 = 0 ;
}
if ( V_357 ) {
if ( ( ( V_356 . V_194 & 3 ) || ! V_356 . V_194 ) && ! V_110 -> V_363 )
return - V_361 ;
V_359 = F_155 ( V_15 -> V_15 , V_357 ,
& V_358 , V_226 ) ;
if ( ! V_359 ) {
V_57 = - V_267 ;
goto V_364;
}
if ( V_225 ) {
if ( F_192 ( V_359 , V_194 , V_357 ) ) {
V_57 = - V_201 ;
goto V_364;
}
}
}
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_164 . V_171 = V_356 . V_171 ;
V_237 . V_164 . V_75 = V_356 . V_75 ;
V_237 . V_164 . V_173 = F_89 ( V_110 -> V_174 ) ;
V_237 . V_164 . V_169 = F_86 ( V_356 . V_169 ) ;
V_237 . V_164 . V_82 = F_92 ( V_356 . V_362 ) ;
V_237 . V_164 . V_181 = F_92 ( V_356 . V_181 ) ;
V_237 . V_164 . V_182 = F_89 ( V_356 . V_182 ) ;
V_237 . V_164 . V_193 = F_89 ( V_356 . V_193 ) ;
V_237 . V_164 . V_365 = F_92 ( V_356 . V_365 ) ;
V_237 . V_164 . V_366 = F_92 ( V_356 . V_366 ) ;
V_237 . V_164 . V_194 = F_86 ( V_358 ) ;
V_57 = F_107 ( V_110 -> V_139 , & V_237 , NULL ,
( void T_8 * ) ( V_153 ) V_356 . V_367 , V_82 , NULL , 0 ) ;
V_364:
if ( V_359 ) {
if ( V_57 == V_58 && ! V_225 ) {
if ( F_193 ( V_194 , V_359 , V_357 ) )
V_57 = - V_201 ;
}
F_137 ( V_15 -> V_15 , V_357 , V_359 , V_358 ) ;
}
return V_57 ;
}
static int F_194 ( struct V_14 * V_15 , struct V_109 * V_110 ,
struct V_368 T_8 * V_369 )
{
struct V_368 V_39 ;
struct V_8 V_237 ;
unsigned V_145 = 0 ;
int V_57 ;
if ( ! F_195 ( V_370 ) )
return - V_371 ;
if ( F_192 ( & V_39 , V_369 , sizeof( V_39 ) ) )
return - V_201 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_179 . V_171 = V_39 . V_171 ;
V_237 . V_179 . V_75 = V_39 . V_75 ;
V_237 . V_179 . V_173 = F_89 ( V_39 . V_173 ) ;
V_237 . V_179 . V_372 [ 0 ] = F_89 ( V_39 . V_372 ) ;
V_237 . V_179 . V_372 [ 1 ] = F_89 ( V_39 . V_373 ) ;
V_237 . V_179 . V_274 [ 0 ] = F_89 ( V_39 . V_274 ) ;
V_237 . V_179 . V_274 [ 1 ] = F_89 ( V_39 . V_374 ) ;
V_237 . V_179 . V_274 [ 2 ] = F_89 ( V_39 . V_375 ) ;
V_237 . V_179 . V_274 [ 3 ] = F_89 ( V_39 . V_376 ) ;
V_237 . V_179 . V_274 [ 4 ] = F_89 ( V_39 . V_377 ) ;
V_237 . V_179 . V_274 [ 5 ] = F_89 ( V_39 . V_378 ) ;
if ( V_39 . V_379 )
V_145 = F_196 ( V_39 . V_379 ) ;
V_57 = F_107 ( V_110 ? V_110 -> V_139 : V_15 -> V_239 , & V_237 ,
NULL , ( void T_8 * ) ( V_153 ) V_39 . V_367 , V_39 . V_380 ,
& V_39 . V_56 , V_145 ) ;
if ( V_57 >= 0 ) {
if ( F_197 ( V_39 . V_56 , & V_369 -> V_56 ) )
return - V_201 ;
}
return V_57 ;
}
static int F_198 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_343 )
return - V_381 ;
F_37 ( 0x4E564D65 , & V_15 -> V_294 -> V_382 ) ;
return 0 ;
}
static int F_199 ( struct V_383 * V_384 , T_10 V_385 , unsigned int V_39 ,
unsigned long V_386 )
{
struct V_109 * V_110 = V_384 -> V_387 -> V_112 ;
switch ( V_39 ) {
case V_388 :
F_200 () ;
return V_110 -> V_174 ;
case V_389 :
return F_194 ( V_110 -> V_15 , NULL , ( void T_8 * ) V_386 ) ;
case V_390 :
return F_194 ( V_110 -> V_15 , V_110 , ( void T_8 * ) V_386 ) ;
case V_391 :
return F_191 ( V_110 , ( void T_8 * ) V_386 ) ;
case V_392 :
return F_201 ( ( void T_8 * ) V_386 ) ;
case V_393 :
return F_202 ( V_110 , ( void T_8 * ) V_386 ) ;
default:
return - V_381 ;
}
}
static int F_203 ( struct V_383 * V_384 , T_10 V_385 ,
unsigned int V_39 , unsigned long V_386 )
{
switch ( V_39 ) {
case V_393 :
return - V_394 ;
}
return F_199 ( V_384 , V_385 , V_39 , V_386 ) ;
}
static int F_204 ( struct V_383 * V_384 , T_10 V_385 )
{
int V_19 = 0 ;
struct V_109 * V_110 ;
F_104 ( & V_278 ) ;
V_110 = V_384 -> V_387 -> V_112 ;
if ( ! V_110 )
V_19 = - V_395 ;
else if ( ! F_205 ( & V_110 -> V_15 -> V_396 ) )
V_19 = - V_395 ;
F_105 ( & V_278 ) ;
return V_19 ;
}
static void F_206 ( struct V_397 * V_127 , T_10 V_385 )
{
struct V_109 * V_110 = V_127 -> V_112 ;
struct V_14 * V_15 = V_110 -> V_15 ;
F_207 ( & V_15 -> V_396 , V_398 ) ;
}
static int F_208 ( struct V_383 * V_197 , struct V_399 * V_400 )
{
V_400 -> V_401 = 1 << 6 ;
V_400 -> V_402 = 1 << 5 ;
V_400 -> V_403 = F_209 ( V_197 -> V_387 ) >> 11 ;
return 0 ;
}
static void F_210 ( struct V_109 * V_110 )
{
T_2 V_404 = F_211 ( V_110 -> V_139 ) ;
V_110 -> V_139 -> V_405 . V_406 = 0 ;
V_110 -> V_139 -> V_405 . V_407 = V_404 ;
V_110 -> V_139 -> V_405 . V_408 = V_404 ;
F_212 ( V_110 -> V_139 , 0xffffffff ) ;
F_213 ( V_409 , V_110 -> V_139 ) ;
}
static int F_214 ( struct V_397 * V_127 )
{
struct V_109 * V_110 = V_127 -> V_112 ;
struct V_14 * V_15 = V_110 -> V_15 ;
struct V_10 * V_243 ;
T_9 V_410 , V_120 ;
T_3 V_411 ;
unsigned short V_412 ;
if ( F_124 ( V_15 , V_110 -> V_174 , & V_243 ) ) {
F_21 ( V_15 -> V_15 , L_21 , V_413 ,
V_15 -> V_309 , V_110 -> V_174 ) ;
return - V_322 ;
}
if ( V_243 -> V_414 == 0 ) {
F_51 ( V_243 ) ;
return - V_322 ;
}
V_411 = V_110 -> V_138 ;
V_410 = V_243 -> V_415 & V_416 ;
V_110 -> V_126 = V_243 -> V_410 [ V_410 ] . V_417 ;
V_110 -> V_138 = F_102 ( V_243 -> V_410 [ V_410 ] . V_138 ) ;
V_110 -> V_363 = V_110 -> V_138 && ( V_243 -> V_415 & V_418 ) ;
if ( V_110 -> V_126 == 0 )
V_110 -> V_126 = 9 ;
V_412 = 1 << V_110 -> V_126 ;
V_120 = V_110 -> V_138 == sizeof( struct V_106 ) ?
V_243 -> V_419 & V_420 : 0 ;
if ( F_215 ( V_127 ) && ( V_110 -> V_120 != V_120 ||
V_110 -> V_138 != V_411 ||
V_412 != F_211 ( V_127 -> V_139 ) ||
( V_110 -> V_138 && V_110 -> V_363 ) ) )
F_216 ( V_127 ) ;
V_110 -> V_120 = V_120 ;
F_217 ( V_110 -> V_139 , V_412 ) ;
if ( V_110 -> V_138 && ! F_215 ( V_127 ) && ( V_127 -> V_75 & V_421 ) &&
! V_110 -> V_363 )
F_67 ( V_110 ) ;
if ( V_110 -> V_138 && ! ( V_110 -> V_138 == 8 && V_110 -> V_120 ) && ! F_215 ( V_127 ) )
F_218 ( V_127 , 0 ) ;
else
F_218 ( V_127 , F_219 ( & V_243 -> V_422 ) << ( V_110 -> V_126 - 9 ) ) ;
if ( V_15 -> V_423 & V_424 )
F_210 ( V_110 ) ;
F_51 ( V_243 ) ;
return 0 ;
}
static int F_220 ( void * V_27 )
{
struct V_14 * V_15 , * V_425 ;
while ( ! F_221 () ) {
F_222 ( V_426 ) ;
F_104 ( & V_278 ) ;
F_223 (dev, next, &dev_list, node) {
int V_93 ;
T_2 V_295 = F_148 ( & V_15 -> V_294 -> V_295 ) ;
if ( ( V_15 -> V_343 && ( V_295 & V_345 ) ) ||
V_295 & V_427 ) {
if ( F_129 ( & V_15 -> V_279 ) )
continue;
F_130 ( & V_15 -> V_280 ) ;
F_21 ( V_15 -> V_15 ,
L_22 ,
F_148 ( & V_15 -> V_294 -> V_295 ) ) ;
V_15 -> V_281 = V_282 ;
F_131 ( V_283 , & V_15 -> V_279 ) ;
continue;
}
for ( V_93 = 0 ; V_93 < V_15 -> V_290 ; V_93 ++ ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_93 ] ;
if ( ! V_30 )
continue;
F_99 ( & V_30 -> V_76 ) ;
F_100 ( V_30 ) ;
while ( ( V_93 == 0 ) && ( V_15 -> V_60 > 0 ) ) {
if ( F_116 ( V_15 ) )
break;
V_15 -> V_60 -- ;
}
F_101 ( & V_30 -> V_76 ) ;
}
}
F_105 ( & V_278 ) ;
F_224 ( F_225 ( V_320 ) ) ;
}
return 0 ;
}
static void F_226 ( struct V_14 * V_15 , unsigned V_173 )
{
struct V_109 * V_110 ;
struct V_397 * V_127 ;
int V_280 = F_179 ( V_15 -> V_15 ) ;
V_110 = F_227 ( sizeof( * V_110 ) , V_226 , V_280 ) ;
if ( ! V_110 )
return;
V_110 -> V_139 = F_181 ( & V_15 -> V_40 ) ;
if ( F_109 ( V_110 -> V_139 ) )
goto V_428;
F_213 ( V_429 , V_110 -> V_139 ) ;
F_213 ( V_430 , V_110 -> V_139 ) ;
V_110 -> V_15 = V_15 ;
V_110 -> V_139 -> V_198 = V_110 ;
V_127 = F_228 ( 0 , V_280 ) ;
if ( ! V_127 )
goto V_431;
V_110 -> V_174 = V_173 ;
V_110 -> V_127 = V_127 ;
V_110 -> V_126 = 9 ;
F_229 ( & V_110 -> V_94 , & V_15 -> V_432 ) ;
F_217 ( V_110 -> V_139 , 1 << V_110 -> V_126 ) ;
if ( V_15 -> V_433 ) {
F_230 ( V_110 -> V_139 , V_15 -> V_433 ) ;
F_231 ( V_110 -> V_139 ,
( ( V_15 -> V_433 << 9 ) / V_15 -> V_17 ) + 1 ) ;
}
if ( V_15 -> V_434 )
F_232 ( V_110 -> V_139 , V_15 -> V_434 >> 9 ) ;
if ( V_15 -> V_435 & V_436 )
F_233 ( V_110 -> V_139 , V_207 | V_183 ) ;
F_234 ( V_110 -> V_139 , V_15 -> V_17 - 1 ) ;
V_127 -> V_437 = V_438 ;
V_127 -> V_439 = 0 ;
V_127 -> V_440 = & V_441 ;
V_127 -> V_112 = V_110 ;
V_127 -> V_139 = V_110 -> V_139 ;
V_127 -> V_442 = V_15 -> V_443 ;
V_127 -> V_75 = V_444 ;
sprintf ( V_127 -> V_445 , L_23 , V_15 -> V_309 , V_173 ) ;
F_218 ( V_127 , 0 ) ;
if ( F_214 ( V_110 -> V_127 ) )
goto V_446;
F_235 ( V_110 -> V_127 ) ;
if ( V_110 -> V_138 ) {
struct V_383 * V_197 = F_236 ( V_110 -> V_127 , 0 ) ;
if ( ! V_197 )
return;
if ( F_237 ( V_197 , V_447 , NULL ) ) {
F_238 ( V_197 ) ;
return;
}
F_239 ( V_197 ) ;
F_240 ( V_197 , V_447 ) ;
}
return;
V_446:
F_51 ( V_127 ) ;
F_241 ( & V_110 -> V_94 ) ;
V_431:
F_176 ( V_110 -> V_139 ) ;
V_428:
F_51 ( V_110 ) ;
}
static void F_242 ( struct V_14 * V_15 )
{
unsigned V_93 ;
for ( V_93 = V_15 -> V_290 ; V_93 <= V_15 -> V_448 ; V_93 ++ )
if ( ! F_156 ( V_15 , V_93 , V_15 -> V_69 ) )
break;
for ( V_93 = V_15 -> V_293 ; V_93 <= V_15 -> V_290 - 1 ; V_93 ++ )
if ( F_165 ( V_15 -> V_31 [ V_93 ] , V_93 ) )
break;
}
static int F_243 ( struct V_14 * V_15 , int V_449 )
{
int V_57 ;
T_2 V_56 ;
T_2 V_450 = ( V_449 - 1 ) | ( ( V_449 - 1 ) << 16 ) ;
V_57 = F_126 ( V_15 , V_451 , V_450 , 0 ,
& V_56 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_57 > 0 ) {
F_171 ( V_15 -> V_15 , L_24 , V_57 ) ;
return 0 ;
}
return F_244 ( V_56 & 0xffff , V_56 >> 16 ) + 1 ;
}
static void T_11 * F_245 ( struct V_14 * V_15 )
{
T_6 V_452 , V_13 , V_77 ;
T_2 V_453 ;
T_12 V_454 ;
struct V_455 * V_456 = F_246 ( V_15 -> V_15 ) ;
void T_11 * V_302 ;
T_5 V_161 ;
if ( ! V_303 )
return NULL ;
V_15 -> V_304 = F_148 ( & V_15 -> V_294 -> V_304 ) ;
if ( ! ( F_247 ( V_15 -> V_304 ) ) )
return NULL ;
V_453 = F_148 ( & V_15 -> V_294 -> V_453 ) ;
V_452 = ( T_6 ) 1 << ( 12 + 4 * F_248 ( V_15 -> V_304 ) ) ;
V_13 = V_452 * F_247 ( V_15 -> V_304 ) ;
V_77 = V_452 * F_249 ( V_453 ) ;
V_454 = F_250 ( V_456 , F_251 ( V_453 ) ) ;
if ( V_77 > V_454 )
return NULL ;
if ( V_13 > V_454 - V_77 )
V_13 = V_454 - V_77 ;
V_161 = F_252 ( V_456 , F_251 ( V_453 ) ) + V_77 ;
V_302 = F_253 ( V_161 , V_13 ) ;
if ( ! V_302 )
return NULL ;
V_15 -> V_305 = V_161 ;
V_15 -> V_299 = V_13 ;
return V_302 ;
}
static inline void F_254 ( struct V_14 * V_15 )
{
if ( V_15 -> V_302 ) {
F_255 ( V_15 -> V_302 ) ;
V_15 -> V_302 = NULL ;
}
}
static T_13 F_256 ( struct V_14 * V_15 , unsigned V_296 )
{
return 4096 + ( ( V_296 + 1 ) * 8 * V_15 -> V_215 ) ;
}
static int F_257 ( struct V_14 * V_15 )
{
struct V_29 * V_457 = V_15 -> V_31 [ 0 ] ;
struct V_455 * V_456 = F_246 ( V_15 -> V_15 ) ;
int V_56 , V_93 , V_458 , V_296 , V_13 ;
V_296 = F_258 () ;
V_56 = F_243 ( V_15 , V_296 ) ;
if ( V_56 <= 0 )
return V_56 ;
if ( V_56 < V_296 )
V_296 = V_56 ;
if ( V_15 -> V_302 && F_154 ( V_15 -> V_304 ) ) {
V_56 = F_149 ( V_15 , V_296 ,
sizeof( struct V_8 ) ) ;
if ( V_56 > 0 )
V_15 -> V_69 = V_56 ;
else
F_254 ( V_15 ) ;
}
V_13 = F_256 ( V_15 , V_296 ) ;
if ( V_13 > 8192 ) {
F_255 ( V_15 -> V_294 ) ;
do {
V_15 -> V_294 = F_259 ( F_252 ( V_456 , 0 ) , V_13 ) ;
if ( V_15 -> V_294 )
break;
if ( ! -- V_296 )
return - V_267 ;
V_13 = F_256 ( V_15 , V_296 ) ;
} while ( 1 );
V_15 -> V_310 = ( ( void T_11 * ) V_15 -> V_294 ) + 4096 ;
V_457 -> V_74 = V_15 -> V_310 ;
}
F_144 ( V_15 -> V_292 [ 0 ] . V_291 , V_457 ) ;
if ( ! V_456 -> V_217 )
F_260 ( V_456 ) ;
for ( V_93 = 0 ; V_93 < V_296 ; V_93 ++ )
V_15 -> V_292 [ V_93 ] . V_292 = V_93 ;
V_458 = F_261 ( V_456 , V_15 -> V_292 , 1 , V_296 ) ;
if ( V_458 < 0 ) {
V_458 = F_262 ( V_456 , 1 , F_244 ( V_296 , 32 ) ) ;
if ( V_458 < 0 ) {
V_458 = 1 ;
} else {
for ( V_93 = 0 ; V_93 < V_458 ; V_93 ++ )
V_15 -> V_292 [ V_93 ] . V_291 = V_93 + V_456 -> V_217 ;
}
}
V_296 = V_458 ;
V_15 -> V_448 = V_296 ;
V_56 = F_161 ( V_15 , V_457 , V_457 -> V_308 ) ;
if ( V_56 ) {
V_457 -> V_255 = - 1 ;
goto V_459;
}
F_140 ( V_15 , V_296 + 1 ) ;
F_242 ( V_15 ) ;
return 0 ;
V_459:
F_140 ( V_15 , 1 ) ;
return V_56 ;
}
static void F_263 ( struct V_109 * V_110 )
{
F_241 ( & V_110 -> V_94 ) ;
F_104 ( & V_278 ) ;
V_110 -> V_127 -> V_112 = NULL ;
F_105 ( & V_278 ) ;
F_264 ( V_110 -> V_127 ) ;
F_51 ( V_110 ) ;
}
static int F_265 ( void * V_85 , struct V_460 * V_461 , struct V_460 * V_462 )
{
struct V_109 * V_463 = F_266 ( V_461 , struct V_109 , V_94 ) ;
struct V_109 * V_464 = F_266 ( V_462 , struct V_109 , V_94 ) ;
return V_463 -> V_174 - V_464 -> V_174 ;
}
static struct V_109 * F_267 ( struct V_14 * V_15 , unsigned V_173 )
{
struct V_109 * V_110 ;
F_268 (ns, &dev->namespaces, list) {
if ( V_110 -> V_174 == V_173 )
return V_110 ;
if ( V_110 -> V_174 > V_173 )
break;
}
return NULL ;
}
static inline bool F_269 ( struct V_14 * V_15 )
{
return ( ! V_15 -> V_294 || F_148 ( & V_15 -> V_294 -> V_295 ) & V_427 ||
V_15 -> V_293 < 2 ) ;
}
static void F_270 ( struct V_109 * V_110 )
{
bool V_465 = F_269 ( V_110 -> V_15 ) && ! F_134 ( V_110 -> V_139 ) ;
if ( V_465 )
F_271 ( V_110 -> V_139 ) ;
if ( V_110 -> V_127 -> V_75 & V_421 ) {
if ( F_215 ( V_110 -> V_127 ) )
F_216 ( V_110 -> V_127 ) ;
F_272 ( V_110 -> V_127 ) ;
}
if ( V_465 || ! F_134 ( V_110 -> V_139 ) ) {
F_273 ( V_110 -> V_139 ) ;
F_176 ( V_110 -> V_139 ) ;
}
}
static void F_274 ( struct V_14 * V_15 , unsigned V_466 )
{
struct V_109 * V_110 , * V_425 ;
unsigned V_93 ;
for ( V_93 = 1 ; V_93 <= V_466 ; V_93 ++ ) {
V_110 = F_267 ( V_15 , V_93 ) ;
if ( V_110 ) {
if ( F_275 ( V_110 -> V_127 ) ) {
F_270 ( V_110 ) ;
F_263 ( V_110 ) ;
}
} else
F_226 ( V_15 , V_93 ) ;
}
F_223 (ns, next, &dev->namespaces, list) {
if ( V_110 -> V_174 > V_466 ) {
F_270 ( V_110 ) ;
F_263 ( V_110 ) ;
}
}
F_276 ( NULL , & V_15 -> V_432 , F_265 ) ;
}
static void F_277 ( struct V_14 * V_15 )
{
struct V_29 * V_30 ;
int V_93 ;
for ( V_93 = 0 ; V_93 < V_15 -> V_293 ; V_93 ++ ) {
V_30 = V_15 -> V_31 [ V_93 ] ;
if ( ! V_30 -> V_33 || ! ( * V_30 -> V_33 ) )
continue;
F_143 ( V_15 -> V_292 [ V_30 -> V_255 ] . V_291 ,
F_278 ( * V_30 -> V_33 ) ) ;
}
}
static void F_279 ( struct V_467 * V_67 )
{
struct V_14 * V_15 = F_266 ( V_67 , struct V_14 , V_62 ) ;
struct V_9 * V_468 ;
if ( ! V_15 -> V_40 . V_33 )
return;
if ( F_123 ( V_15 , & V_468 ) )
return;
F_274 ( V_15 , F_25 ( & V_468 -> V_466 ) ) ;
F_51 ( V_468 ) ;
F_277 ( V_15 ) ;
}
static int F_280 ( struct V_14 * V_15 )
{
struct V_455 * V_456 = F_246 ( V_15 -> V_15 ) ;
int V_469 ;
struct V_9 * V_468 ;
int V_470 = F_186 ( F_185 ( & V_15 -> V_294 -> V_316 ) ) + 12 ;
V_469 = F_123 ( V_15 , & V_468 ) ;
if ( V_469 ) {
F_171 ( V_15 -> V_15 , L_25 , V_469 ) ;
return - V_103 ;
}
V_15 -> V_423 = F_22 ( & V_468 -> V_423 ) ;
V_15 -> V_63 = V_468 -> V_471 + 1 ;
V_15 -> V_435 = V_468 -> V_435 ;
memcpy ( V_15 -> V_472 , V_468 -> V_473 , sizeof( V_468 -> V_473 ) ) ;
memcpy ( V_15 -> V_474 , V_468 -> V_475 , sizeof( V_468 -> V_475 ) ) ;
memcpy ( V_15 -> V_476 , V_468 -> V_477 , sizeof( V_468 -> V_477 ) ) ;
if ( V_468 -> V_478 )
V_15 -> V_433 = 1 << ( V_468 -> V_478 + V_470 - 9 ) ;
if ( ( V_456 -> V_479 == V_480 ) &&
( V_456 -> V_443 == 0x0953 ) && V_468 -> V_344 [ 3 ] ) {
unsigned int V_433 ;
V_15 -> V_434 = 1 << ( V_468 -> V_344 [ 3 ] + V_470 ) ;
V_433 = V_15 -> V_434 >> ( V_470 - 9 ) ;
if ( V_15 -> V_433 ) {
V_15 -> V_433 = F_244 ( V_433 ,
V_15 -> V_433 ) ;
} else
V_15 -> V_433 = V_433 ;
}
F_51 ( V_468 ) ;
if ( ! V_15 -> V_40 . V_33 ) {
V_15 -> V_40 . V_331 = & V_481 ;
V_15 -> V_40 . V_333 = V_15 -> V_293 - 1 ;
V_15 -> V_40 . V_145 = V_482 ;
V_15 -> V_40 . V_38 = F_179 ( V_15 -> V_15 ) ;
V_15 -> V_40 . V_334 =
F_281 ( int , V_15 -> V_69 , V_483 ) - 1 ;
V_15 -> V_40 . V_337 = F_5 ( V_15 ) ;
V_15 -> V_40 . V_75 = V_484 ;
V_15 -> V_40 . V_34 = V_15 ;
if ( F_180 ( & V_15 -> V_40 ) )
return 0 ;
}
F_27 ( & V_15 -> V_62 ) ;
return 0 ;
}
static int F_282 ( struct V_14 * V_15 )
{
T_6 V_316 ;
int V_485 , V_56 = - V_267 ;
struct V_455 * V_456 = F_246 ( V_15 -> V_15 ) ;
if ( F_283 ( V_456 ) )
return V_56 ;
V_15 -> V_292 [ 0 ] . V_291 = V_456 -> V_217 ;
F_284 ( V_456 ) ;
V_485 = F_285 ( V_456 , V_486 ) ;
if ( ! V_485 )
goto V_487;
if ( F_286 ( V_456 , V_485 , L_26 ) )
goto V_487;
if ( F_287 ( V_15 -> V_15 , F_288 ( 64 ) ) &&
F_287 ( V_15 -> V_15 , F_288 ( 32 ) ) )
goto V_488;
V_15 -> V_294 = F_259 ( F_252 ( V_456 , 0 ) , 8192 ) ;
if ( ! V_15 -> V_294 )
goto V_488;
if ( F_148 ( & V_15 -> V_294 -> V_295 ) == - 1 ) {
V_56 = - V_322 ;
goto V_364;
}
if ( ! V_456 -> V_217 ) {
V_56 = F_289 ( V_456 , V_15 -> V_292 , 1 ) ;
if ( V_56 < 0 )
goto V_364;
}
V_316 = F_185 ( & V_15 -> V_294 -> V_316 ) ;
V_15 -> V_69 = F_281 ( int , F_290 ( V_316 ) + 1 , V_489 ) ;
V_15 -> V_215 = 1 << F_291 ( V_316 ) ;
V_15 -> V_310 = ( ( void T_11 * ) V_15 -> V_294 ) + 4096 ;
if ( F_148 ( & V_15 -> V_294 -> V_344 ) >= F_188 ( 1 , 2 ) )
V_15 -> V_302 = F_245 ( V_15 ) ;
return 0 ;
V_364:
F_255 ( V_15 -> V_294 ) ;
V_15 -> V_294 = NULL ;
V_488:
F_292 ( V_456 ) ;
V_487:
F_293 ( V_456 ) ;
return V_56 ;
}
static void F_294 ( struct V_14 * V_15 )
{
struct V_455 * V_456 = F_246 ( V_15 -> V_15 ) ;
if ( V_456 -> V_490 )
F_295 ( V_456 ) ;
else if ( V_456 -> V_491 )
F_260 ( V_456 ) ;
if ( V_15 -> V_294 ) {
F_255 ( V_15 -> V_294 ) ;
V_15 -> V_294 = NULL ;
F_292 ( V_456 ) ;
}
if ( F_296 ( V_456 ) )
F_293 ( V_456 ) ;
}
static void F_297 ( struct V_492 * V_493 , struct V_14 * V_15 )
{
V_493 -> V_494 = V_321 ;
F_160 () ;
for (; ; ) {
F_222 ( V_495 ) ;
if ( ! F_298 ( & V_493 -> V_496 ) )
break;
if ( ! F_224 ( V_232 ) ||
F_169 ( V_321 ) ) {
F_222 ( V_497 ) ;
F_172 ( V_15 , F_185 ( & V_15 -> V_294 -> V_316 ) ) ;
F_145 ( V_15 -> V_31 [ 0 ] ) ;
F_299 ( V_493 -> V_66 ) ;
F_147 ( V_15 , 0 ) ;
return;
}
}
F_222 ( V_497 ) ;
}
static void F_300 ( struct V_492 * V_493 )
{
F_301 ( & V_493 -> V_496 ) ;
if ( V_493 -> V_494 )
F_302 ( V_493 -> V_494 ) ;
}
static struct V_492 * F_303 ( struct V_492 * V_493 )
{
F_304 ( & V_493 -> V_496 ) ;
return V_493 ;
}
static void F_305 ( struct V_29 * V_30 )
{
struct V_492 * V_493 = V_30 -> V_65 . V_41 ;
F_300 ( V_493 ) ;
}
static int F_306 ( struct V_29 * V_30 , T_9 V_171 ,
T_14 V_43 )
{
struct V_8 V_237 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_244 . V_171 = V_171 ;
V_237 . V_244 . V_245 = F_92 ( V_30 -> V_245 ) ;
F_307 ( & V_30 -> V_65 . V_67 , V_43 ) ;
return F_117 ( V_30 -> V_15 , & V_237 , & V_30 -> V_65 ,
V_232 ) ;
}
static void F_308 ( struct V_498 * V_67 )
{
struct V_29 * V_30 = F_266 ( V_67 , struct V_29 ,
V_65 . V_67 ) ;
F_305 ( V_30 ) ;
}
static int F_309 ( struct V_29 * V_30 )
{
return F_306 ( V_30 , V_262 ,
F_308 ) ;
}
static void F_310 ( struct V_498 * V_67 )
{
struct V_29 * V_30 = F_266 ( V_67 , struct V_29 ,
V_65 . V_67 ) ;
int V_57 = V_30 -> V_65 . V_57 ;
if ( ! V_57 )
V_57 = F_309 ( V_30 ) ;
if ( V_57 )
F_305 ( V_30 ) ;
}
static int F_311 ( struct V_29 * V_30 )
{
return F_306 ( V_30 , V_263 ,
F_310 ) ;
}
static void F_312 ( struct V_498 * V_67 )
{
struct V_29 * V_30 = F_266 ( V_67 , struct V_29 ,
V_65 . V_67 ) ;
if ( F_311 ( V_30 ) )
F_305 ( V_30 ) ;
}
static void F_313 ( struct V_14 * V_15 )
{
int V_93 ;
F_314 ( V_66 ) ;
struct V_492 V_493 ;
struct V_499 * V_500 = F_315 ( V_501 ,
& V_66 , L_27 , V_15 -> V_309 ) ;
if ( F_109 ( V_500 ) ) {
F_171 ( V_15 -> V_15 ,
L_28 ) ;
for ( V_93 = V_15 -> V_290 - 1 ; V_93 > 0 ; V_93 -- )
F_147 ( V_15 , V_93 ) ;
return;
}
V_493 . V_494 = NULL ;
F_316 ( & V_493 . V_496 , 0 ) ;
V_493 . V_66 = & V_66 ;
for ( V_93 = V_15 -> V_290 - 1 ; V_93 > 0 ; V_93 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_93 ] ;
if ( F_141 ( V_30 ) )
continue;
V_30 -> V_65 . V_41 = F_303 ( & V_493 ) ;
V_30 -> V_65 . V_66 = V_493 . V_66 ;
F_307 ( & V_30 -> V_65 . V_67 , F_312 ) ;
F_31 ( V_493 . V_66 , & V_30 -> V_65 . V_67 ) ;
}
F_297 ( & V_493 , V_15 ) ;
F_317 ( V_500 ) ;
}
static void F_318 ( struct V_14 * V_15 )
{
struct V_499 * V_502 = NULL ;
F_104 ( & V_278 ) ;
F_130 ( & V_15 -> V_280 ) ;
if ( F_319 ( & V_503 ) && ! F_320 ( V_504 ) ) {
V_502 = V_504 ;
V_504 = NULL ;
}
F_105 ( & V_278 ) ;
if ( V_502 )
F_317 ( V_502 ) ;
}
static void F_321 ( struct V_14 * V_15 )
{
struct V_109 * V_110 ;
F_268 (ns, &dev->namespaces, list) {
F_142 ( V_110 -> V_139 ) ;
F_99 ( V_110 -> V_139 -> V_147 ) ;
F_322 ( V_505 , V_110 -> V_139 ) ;
F_101 ( V_110 -> V_139 -> V_147 ) ;
F_323 ( V_110 -> V_139 ) ;
F_324 ( V_110 -> V_139 ) ;
}
}
static void F_325 ( struct V_14 * V_15 )
{
struct V_109 * V_110 ;
F_268 (ns, &dev->namespaces, list) {
F_326 ( V_505 , V_110 -> V_139 ) ;
F_183 ( V_110 -> V_139 ) ;
F_327 ( V_110 -> V_139 , true ) ;
F_75 ( V_110 -> V_139 ) ;
}
}
static void F_328 ( struct V_14 * V_15 )
{
int V_93 ;
T_2 V_295 = - 1 ;
F_318 ( V_15 ) ;
if ( V_15 -> V_294 ) {
F_321 ( V_15 ) ;
V_295 = F_148 ( & V_15 -> V_294 -> V_295 ) ;
}
if ( V_295 & V_427 || ! ( V_295 & V_319 ) ) {
for ( V_93 = V_15 -> V_290 - 1 ; V_93 >= 0 ; V_93 -- ) {
struct V_29 * V_30 = V_15 -> V_31 [ V_93 ] ;
F_141 ( V_30 ) ;
}
} else {
F_313 ( V_15 ) ;
F_174 ( V_15 ) ;
F_147 ( V_15 , 0 ) ;
}
F_294 ( V_15 ) ;
for ( V_93 = V_15 -> V_290 - 1 ; V_93 >= 0 ; V_93 -- )
F_145 ( V_15 -> V_31 [ V_93 ] ) ;
}
static void F_329 ( struct V_14 * V_15 )
{
struct V_109 * V_110 ;
F_268 (ns, &dev->namespaces, list)
F_270 ( V_110 ) ;
}
static int F_330 ( struct V_14 * V_15 )
{
V_15 -> V_100 = F_331 ( L_29 , V_15 -> V_15 ,
V_18 , V_18 , 0 ) ;
if ( ! V_15 -> V_100 )
return - V_267 ;
V_15 -> V_97 = F_331 ( L_30 , V_15 -> V_15 ,
256 , 256 , 0 ) ;
if ( ! V_15 -> V_97 ) {
F_332 ( V_15 -> V_100 ) ;
return - V_267 ;
}
return 0 ;
}
static void F_333 ( struct V_14 * V_15 )
{
F_332 ( V_15 -> V_100 ) ;
F_332 ( V_15 -> V_97 ) ;
}
static int F_334 ( struct V_14 * V_15 )
{
int V_309 , error ;
do {
if ( ! F_335 ( & V_506 , V_226 ) )
return - V_322 ;
F_104 ( & V_278 ) ;
error = F_336 ( & V_506 , & V_309 ) ;
F_105 ( & V_278 ) ;
} while ( error == - V_507 );
if ( error )
return - V_322 ;
V_15 -> V_309 = V_309 ;
return 0 ;
}
static void F_337 ( struct V_14 * V_15 )
{
F_104 ( & V_278 ) ;
F_338 ( & V_506 , V_15 -> V_309 ) ;
F_105 ( & V_278 ) ;
}
static void F_339 ( struct V_14 * V_15 )
{
struct V_109 * V_110 , * V_425 ;
F_223 (ns, next, &dev->namespaces, list)
F_263 ( V_110 ) ;
}
static void V_398 ( struct V_396 * V_396 )
{
struct V_14 * V_15 = F_266 ( V_396 , struct V_14 , V_396 ) ;
F_340 ( V_15 -> V_15 ) ;
F_340 ( V_15 -> V_443 ) ;
F_339 ( V_15 ) ;
F_337 ( V_15 ) ;
if ( V_15 -> V_40 . V_33 )
F_177 ( & V_15 -> V_40 ) ;
if ( V_15 -> V_239 )
F_341 ( V_15 -> V_239 ) ;
F_51 ( V_15 -> V_31 ) ;
F_51 ( V_15 -> V_292 ) ;
F_51 ( V_15 ) ;
}
static int F_342 ( struct V_508 * V_508 , struct V_509 * V_510 )
{
struct V_14 * V_15 ;
int V_309 = F_343 ( V_508 ) ;
int V_19 = - V_322 ;
F_104 ( & V_278 ) ;
F_268 (dev, &dev_list, node) {
if ( V_15 -> V_309 == V_309 ) {
if ( ! V_15 -> V_239 ) {
V_19 = - V_511 ;
break;
}
if ( ! F_205 ( & V_15 -> V_396 ) )
break;
V_510 -> V_112 = V_15 ;
V_19 = 0 ;
break;
}
}
F_105 ( & V_278 ) ;
return V_19 ;
}
static int F_344 ( struct V_508 * V_508 , struct V_509 * V_510 )
{
struct V_14 * V_15 = V_510 -> V_112 ;
F_207 ( & V_15 -> V_396 , V_398 ) ;
return 0 ;
}
static long F_345 ( struct V_509 * V_510 , unsigned int V_39 , unsigned long V_386 )
{
struct V_14 * V_15 = V_510 -> V_112 ;
struct V_109 * V_110 ;
switch ( V_39 ) {
case V_389 :
return F_194 ( V_15 , NULL , ( void T_8 * ) V_386 ) ;
case V_390 :
if ( F_319 ( & V_15 -> V_432 ) )
return - V_381 ;
V_110 = F_346 ( & V_15 -> V_432 , struct V_109 , V_94 ) ;
return F_194 ( V_15 , V_110 , ( void T_8 * ) V_386 ) ;
case V_512 :
F_21 ( V_15 -> V_15 , L_31 ) ;
return F_347 ( V_15 ) ;
case V_513 :
return F_198 ( V_15 ) ;
default:
return - V_381 ;
}
}
static int F_348 ( struct V_14 * V_15 )
{
int V_56 ;
bool V_514 = false ;
V_56 = F_282 ( V_15 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_184 ( V_15 ) ;
if ( V_56 )
goto V_364;
F_104 ( & V_278 ) ;
if ( F_319 ( & V_503 ) && F_320 ( V_504 ) ) {
V_514 = true ;
V_504 = NULL ;
}
F_349 ( & V_15 -> V_280 , & V_503 ) ;
F_105 ( & V_278 ) ;
if ( V_514 ) {
V_504 = F_315 ( F_220 , NULL , L_26 ) ;
F_350 ( & V_515 ) ;
} else
F_351 ( V_515 , V_504 ) ;
if ( F_320 ( V_504 ) ) {
V_56 = V_504 ? F_110 ( V_504 ) : - V_151 ;
goto V_488;
}
F_164 ( V_15 -> V_31 [ 0 ] , 0 ) ;
V_56 = F_178 ( V_15 ) ;
if ( V_56 )
goto V_488;
V_56 = F_257 ( V_15 ) ;
if ( V_56 )
goto V_516;
V_15 -> V_60 = 1 ;
return V_56 ;
V_516:
F_175 ( V_15 ) ;
F_341 ( V_15 -> V_239 ) ;
V_15 -> V_239 = NULL ;
V_15 -> V_31 [ 0 ] -> V_33 = NULL ;
V_488:
F_147 ( V_15 , 0 ) ;
F_318 ( V_15 ) ;
V_364:
F_294 ( V_15 ) ;
return V_56 ;
}
static int F_352 ( void * V_386 )
{
struct V_14 * V_15 = (struct V_14 * ) V_386 ;
struct V_455 * V_456 = F_246 ( V_15 -> V_15 ) ;
if ( F_353 ( V_456 ) )
F_354 ( V_456 ) ;
F_207 ( & V_15 -> V_396 , V_398 ) ;
return 0 ;
}
static void F_355 ( struct V_467 * V_517 )
{
struct V_14 * V_15 = F_266 ( V_517 , struct V_14 , V_279 ) ;
F_140 ( V_15 , 1 ) ;
F_329 ( V_15 ) ;
}
static int F_356 ( struct V_14 * V_15 )
{
int V_19 ;
V_19 = F_348 ( V_15 ) ;
if ( V_19 )
return V_19 ;
if ( V_15 -> V_293 < 2 ) {
F_104 ( & V_278 ) ;
V_15 -> V_281 = F_355 ;
F_131 ( V_283 , & V_15 -> V_279 ) ;
F_105 ( & V_278 ) ;
} else {
F_325 ( V_15 ) ;
F_280 ( V_15 ) ;
}
return 0 ;
}
static void F_357 ( struct V_14 * V_15 )
{
F_21 ( V_15 -> V_15 , L_32 ) ;
F_358 ( & V_15 -> V_396 ) ;
if ( F_109 ( F_315 ( F_352 , V_15 , L_27 ,
V_15 -> V_309 ) ) ) {
F_171 ( V_15 -> V_15 ,
L_33 ) ;
F_207 ( & V_15 -> V_396 , V_398 ) ;
}
}
static void F_359 ( struct V_14 * V_15 )
{
bool V_518 = F_129 ( & V_15 -> V_519 ) ;
F_328 ( V_15 ) ;
F_360 ( & V_15 -> V_519 ) ;
if ( V_518 ) {
F_357 ( V_15 ) ;
return;
}
F_27 ( & V_15 -> V_519 ) ;
}
static void V_282 ( struct V_467 * V_517 )
{
struct V_14 * V_15 = F_266 ( V_517 , struct V_14 , V_279 ) ;
F_359 ( V_15 ) ;
}
static void F_361 ( struct V_467 * V_67 )
{
struct V_14 * V_15 = F_266 ( V_67 , struct V_14 , V_279 ) ;
V_15 -> V_281 ( V_67 ) ;
}
static int F_347 ( struct V_14 * V_15 )
{
int V_19 = - V_520 ;
if ( ! V_15 -> V_239 || F_134 ( V_15 -> V_239 ) )
return - V_322 ;
F_104 ( & V_278 ) ;
if ( ! F_362 ( & V_15 -> V_279 ) ) {
V_15 -> V_281 = V_282 ;
F_131 ( V_283 , & V_15 -> V_279 ) ;
V_19 = 0 ;
}
F_105 ( & V_278 ) ;
if ( ! V_19 ) {
F_360 ( & V_15 -> V_279 ) ;
F_360 ( & V_15 -> V_519 ) ;
return 0 ;
}
return V_19 ;
}
static T_15 F_363 ( struct V_443 * V_15 ,
struct V_521 * V_522 , const char * V_523 ,
T_13 V_449 )
{
struct V_14 * V_524 = F_364 ( V_15 ) ;
int V_19 ;
V_19 = F_347 ( V_524 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_449 ;
}
static int F_365 ( struct V_455 * V_456 , const struct V_525 * V_243 )
{
int V_280 , V_56 = - V_267 ;
struct V_14 * V_15 ;
V_280 = F_179 ( & V_456 -> V_15 ) ;
if ( V_280 == V_526 )
F_366 ( & V_456 -> V_15 , 0 ) ;
V_15 = F_227 ( sizeof( * V_15 ) , V_226 , V_280 ) ;
if ( ! V_15 )
return - V_267 ;
V_15 -> V_292 = F_227 ( F_258 () * sizeof( * V_15 -> V_292 ) ,
V_226 , V_280 ) ;
if ( ! V_15 -> V_292 )
goto free;
V_15 -> V_31 = F_227 ( ( F_258 () + 1 ) * sizeof( void * ) ,
V_226 , V_280 ) ;
if ( ! V_15 -> V_31 )
goto free;
F_367 ( & V_15 -> V_432 ) ;
V_15 -> V_281 = V_282 ;
F_368 ( & V_15 -> V_279 , F_361 ) ;
V_15 -> V_15 = F_369 ( & V_456 -> V_15 ) ;
F_370 ( V_456 , V_15 ) ;
V_56 = F_334 ( V_15 ) ;
if ( V_56 )
goto V_527;
V_56 = F_330 ( V_15 ) ;
if ( V_56 )
goto V_528;
F_371 ( & V_15 -> V_396 ) ;
V_15 -> V_443 = F_372 ( V_529 , & V_456 -> V_15 ,
F_373 ( V_530 , V_15 -> V_309 ) ,
V_15 , L_27 , V_15 -> V_309 ) ;
if ( F_109 ( V_15 -> V_443 ) ) {
V_56 = F_110 ( V_15 -> V_443 ) ;
goto V_531;
}
F_369 ( V_15 -> V_443 ) ;
F_374 ( V_15 -> V_443 , V_15 ) ;
V_56 = F_375 ( V_15 -> V_443 , & V_532 ) ;
if ( V_56 )
goto V_533;
F_367 ( & V_15 -> V_280 ) ;
F_368 ( & V_15 -> V_62 , F_279 ) ;
F_368 ( & V_15 -> V_519 , V_534 ) ;
F_27 ( & V_15 -> V_519 ) ;
return 0 ;
V_533:
F_376 ( V_529 , F_373 ( V_530 , V_15 -> V_309 ) ) ;
F_340 ( V_15 -> V_443 ) ;
V_531:
F_333 ( V_15 ) ;
V_528:
F_337 ( V_15 ) ;
V_527:
F_340 ( V_15 -> V_15 ) ;
free:
F_51 ( V_15 -> V_31 ) ;
F_51 ( V_15 -> V_292 ) ;
F_51 ( V_15 ) ;
return V_56 ;
}
static void V_534 ( struct V_467 * V_67 )
{
struct V_14 * V_15 = F_266 ( V_67 , struct V_14 , V_519 ) ;
if ( F_356 ( V_15 ) && ! F_129 ( & V_15 -> V_279 ) )
F_357 ( V_15 ) ;
}
static void F_377 ( struct V_455 * V_456 , bool V_535 )
{
struct V_14 * V_15 = F_353 ( V_456 ) ;
if ( V_535 )
F_328 ( V_15 ) ;
else
F_356 ( V_15 ) ;
}
static void F_378 ( struct V_455 * V_456 )
{
struct V_14 * V_15 = F_353 ( V_456 ) ;
F_328 ( V_15 ) ;
}
static void F_379 ( struct V_455 * V_456 )
{
struct V_14 * V_15 = F_353 ( V_456 ) ;
F_104 ( & V_278 ) ;
F_130 ( & V_15 -> V_280 ) ;
F_105 ( & V_278 ) ;
F_370 ( V_456 , NULL ) ;
F_360 ( & V_15 -> V_519 ) ;
F_360 ( & V_15 -> V_279 ) ;
F_360 ( & V_15 -> V_62 ) ;
F_380 ( V_15 -> V_443 , & V_532 ) ;
F_329 ( V_15 ) ;
F_328 ( V_15 ) ;
F_175 ( V_15 ) ;
F_376 ( V_529 , F_373 ( V_530 , V_15 -> V_309 ) ) ;
F_140 ( V_15 , 0 ) ;
F_254 ( V_15 ) ;
F_333 ( V_15 ) ;
F_207 ( & V_15 -> V_396 , V_398 ) ;
}
static int F_381 ( struct V_443 * V_15 )
{
struct V_455 * V_456 = F_246 ( V_15 ) ;
struct V_14 * V_524 = F_353 ( V_456 ) ;
F_328 ( V_524 ) ;
return 0 ;
}
static int F_382 ( struct V_443 * V_15 )
{
struct V_455 * V_456 = F_246 ( V_15 ) ;
struct V_14 * V_524 = F_353 ( V_456 ) ;
if ( F_356 ( V_524 ) && ! F_129 ( & V_524 -> V_279 ) ) {
V_524 -> V_281 = V_282 ;
F_131 ( V_283 , & V_524 -> V_279 ) ;
}
return 0 ;
}
static int T_16 F_383 ( void )
{
int V_56 ;
F_384 ( & V_515 ) ;
V_283 = F_385 ( L_26 ) ;
if ( ! V_283 )
return - V_267 ;
V_56 = F_386 ( V_438 , L_26 ) ;
if ( V_56 < 0 )
goto V_536;
else if ( V_56 > 0 )
V_438 = V_56 ;
V_56 = F_387 ( V_530 , 0 , V_537 , L_26 ,
& V_538 ) ;
if ( V_56 < 0 )
goto V_539;
else if ( V_56 > 0 )
V_530 = V_56 ;
V_529 = F_388 ( V_540 , L_26 ) ;
if ( F_109 ( V_529 ) ) {
V_56 = F_110 ( V_529 ) ;
goto V_541;
}
V_56 = F_389 ( & V_542 ) ;
if ( V_56 )
goto V_543;
return 0 ;
V_543:
F_390 ( V_529 ) ;
V_541:
F_391 ( V_530 , 0 , V_537 , L_26 ) ;
V_539:
V_539 ( V_438 , L_26 ) ;
V_536:
F_392 ( V_283 ) ;
return V_56 ;
}
static void T_17 F_393 ( void )
{
F_394 ( & V_542 ) ;
V_539 ( V_438 , L_26 ) ;
F_392 ( V_283 ) ;
F_390 ( V_529 ) ;
F_391 ( V_530 , 0 , V_537 , L_26 ) ;
F_12 ( V_504 && ! F_109 ( V_504 ) ) ;
F_1 () ;
}
