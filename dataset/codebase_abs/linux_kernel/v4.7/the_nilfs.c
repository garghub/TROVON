void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_3 V_5 )
{
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 = V_4 ;
V_2 -> V_9 = V_5 ;
if ( ! F_3 ( V_2 ) ) {
if ( V_2 -> V_10 == V_2 -> V_8 )
goto V_11;
F_4 ( V_2 ) ;
}
V_2 -> V_10 = V_2 -> V_8 ;
V_11:
F_5 ( & V_2 -> V_6 ) ;
}
struct V_1 * F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_15 = V_13 ;
F_8 ( & V_2 -> V_16 , 0 ) ;
F_9 ( & V_2 -> V_17 ) ;
F_10 ( & V_2 -> V_18 ) ;
F_11 ( & V_2 -> V_19 ) ;
F_11 ( & V_2 -> V_20 ) ;
F_12 ( & V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_22 ) ;
F_12 ( & V_2 -> V_6 ) ;
V_2 -> V_23 = V_24 ;
F_12 ( & V_2 -> V_25 ) ;
F_9 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = V_28 ;
return V_2 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 () ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_2 ) ;
F_17 ( V_2 -> V_29 [ 0 ] ) ;
F_17 ( V_2 -> V_29 [ 1 ] ) ;
}
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_30 * V_31 , T_1 V_32 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
struct V_37 * * V_38 = V_2 -> V_39 ;
struct V_40 * V_41 ;
unsigned int V_42 , V_43 , V_44 ;
unsigned int V_45 ;
int V_46 ;
V_46 = F_20 ( V_2 , V_32 , & V_34 , 1 ) ;
if ( F_21 ( V_46 ) )
return V_46 ;
F_22 ( & V_2 -> V_17 ) ;
V_42 = F_23 ( V_38 [ 0 ] -> V_47 ) ;
V_44 = F_23 ( V_38 [ 0 ] -> V_48 ) ;
V_43 = F_23 ( V_38 [ 0 ] -> V_49 ) ;
F_24 ( & V_2 -> V_17 ) ;
V_45 = V_2 -> V_50 ;
V_41 = ( void * ) V_34 -> V_51 + F_25 ( V_45 ) ;
V_46 = F_26 ( V_31 , V_42 , V_41 , & V_2 -> V_52 ) ;
if ( V_46 )
goto V_53;
V_41 = ( void * ) V_34 -> V_51 + F_27 ( V_45 ) ;
V_46 = F_28 ( V_31 , V_44 , V_41 , & V_2 -> V_54 ) ;
if ( V_46 )
goto V_55;
V_41 = ( void * ) V_34 -> V_51 + F_29 ( V_45 ) ;
V_46 = F_30 ( V_31 , V_43 , V_41 ,
& V_2 -> V_56 ) ;
if ( V_46 )
goto V_57;
V_36 = (struct V_35 * ) V_34 -> V_51 ;
V_2 -> V_58 = F_31 ( V_36 -> V_59 ) ;
V_53:
F_17 ( V_34 ) ;
return V_46 ;
V_57:
F_32 ( V_2 -> V_54 ) ;
V_55:
F_32 ( V_2 -> V_52 ) ;
goto V_53;
}
static void F_33 ( struct V_60 * V_61 )
{
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_11 ( & V_61 -> V_62 ) ;
}
static void F_34 ( struct V_60 * V_61 )
{
F_35 ( & V_61 -> V_62 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
int V_63 = 0 ;
V_2 -> V_7 = F_31 ( V_38 -> V_64 ) ;
V_2 -> V_9 = F_31 ( V_38 -> V_65 ) ;
V_2 -> V_8 = F_31 ( V_38 -> V_66 ) ;
V_2 -> V_10 = V_2 -> V_8 ;
V_2 -> V_67 = V_2 -> V_8 ;
V_2 -> V_68 =
F_37 ( V_2 , V_2 -> V_7 ) ;
V_2 -> V_69 = V_2 -> V_9 + 1 ;
if ( V_2 -> V_68 >= V_2 -> V_70 ) {
F_38 ( V_71 L_1 ) ;
V_63 = - V_72 ;
}
return V_63 ;
}
int F_39 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
struct V_60 V_61 ;
unsigned int V_73 = V_31 -> V_73 ;
int V_74 = F_40 ( V_2 -> V_15 ) ;
int V_75 = F_41 ( V_2 ) ;
int V_46 ;
if ( ! V_75 ) {
F_38 ( V_76 L_2 ) ;
if ( V_73 & V_77 ) {
F_38 ( V_78 L_3
L_4 ) ;
F_38 ( V_78 L_5
L_6 ) ;
}
}
F_33 ( & V_61 ) ;
V_46 = F_42 ( V_2 , & V_61 ) ;
if ( F_21 ( V_46 ) ) {
struct V_37 * * V_38 = V_2 -> V_39 ;
int V_79 ;
if ( V_46 != - V_72 )
goto V_80;
if ( ! F_43 ( V_38 [ 1 ] ) ) {
F_38 ( V_76
L_7
L_8 ) ;
goto V_80;
}
F_38 ( V_78
L_9 ) ;
memcpy ( V_38 [ 0 ] , V_38 [ 1 ] , V_2 -> V_81 ) ;
V_2 -> V_82 = F_44 ( V_38 [ 0 ] -> V_83 ) ;
V_2 -> V_84 = F_31 ( V_38 [ 0 ] -> V_85 ) ;
V_79 = V_86 << F_44 ( V_38 [ 0 ] -> V_87 ) ;
if ( V_79 != V_2 -> V_88 ) {
F_38 ( V_76
L_10
L_11 ,
V_79 , V_2 -> V_88 ) ;
goto V_80;
}
V_46 = F_36 ( V_2 , V_38 [ 0 ] ) ;
if ( V_46 )
goto V_80;
V_2 -> V_89 &= ~ V_90 ;
V_75 = 0 ;
V_46 = F_42 ( V_2 , & V_61 ) ;
if ( V_46 )
goto V_80;
}
V_46 = F_19 ( V_2 , V_31 , V_61 . V_91 ) ;
if ( F_21 ( V_46 ) ) {
F_38 ( V_71 L_12 ) ;
goto V_53;
}
if ( V_75 )
goto V_92;
if ( V_73 & V_77 ) {
T_3 V_93 ;
if ( F_45 ( V_2 , V_94 ) ) {
F_38 ( V_78 L_13
L_14 ) ;
goto V_92;
}
V_93 = F_31 ( V_2 -> V_39 [ 0 ] -> V_95 ) &
~ V_96 ;
if ( V_93 ) {
F_38 ( V_71 L_15
L_16
L_17 ,
( unsigned long long ) V_93 ) ;
V_46 = - V_97 ;
goto V_98;
}
if ( V_74 ) {
F_38 ( V_71 L_18
L_19 ) ;
V_46 = - V_97 ;
goto V_98;
}
V_31 -> V_73 &= ~ V_77 ;
} else if ( F_45 ( V_2 , V_94 ) ) {
F_38 ( V_71 L_20
L_21 ) ;
V_46 = - V_72 ;
goto V_98;
}
V_46 = F_46 ( V_2 , V_31 , & V_61 ) ;
if ( V_46 )
goto V_98;
F_47 ( & V_2 -> V_17 ) ;
V_2 -> V_89 |= V_90 ;
V_46 = F_48 ( V_31 ) ;
F_49 ( & V_2 -> V_17 ) ;
if ( V_46 ) {
F_38 ( V_71 L_22
L_23 ) ;
goto V_98;
}
F_38 ( V_78 L_24 ) ;
V_92:
F_34 ( & V_61 ) ;
V_31 -> V_73 = V_73 ;
return 0 ;
V_80:
F_38 ( V_71 L_25 ) ;
goto V_53;
V_98:
F_32 ( V_2 -> V_54 ) ;
F_32 ( V_2 -> V_56 ) ;
F_32 ( V_2 -> V_52 ) ;
V_53:
F_34 ( & V_61 ) ;
V_31 -> V_73 = V_73 ;
return V_46 ;
}
static unsigned long long F_50 ( unsigned int V_99 )
{
unsigned int V_100 ;
unsigned long long V_101 = V_102 ;
V_100 = V_99 + V_103 ;
if ( V_100 < 64 )
V_101 = F_51 (unsigned long long, res, (1ULL << max_bits) - 1 ) ;
return V_101 ;
}
unsigned long F_52 ( struct V_1 * V_2 , unsigned long V_104 )
{
return F_53 (unsigned long, NILFS_MIN_NRSVSEGS,
DIV_ROUND_UP(nsegs * nilfs->ns_r_segments_percentage,
100)) ;
}
void F_54 ( struct V_1 * V_2 , unsigned long V_104 )
{
V_2 -> V_70 = V_104 ;
V_2 -> V_105 = F_52 ( V_2 , V_104 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
if ( F_44 ( V_38 -> V_106 ) < V_107 ) {
F_38 ( V_71 L_26
L_27
L_28 ,
F_44 ( V_38 -> V_106 ) ,
F_23 ( V_38 -> V_108 ) ,
V_109 , V_110 ) ;
return - V_72 ;
}
V_2 -> V_81 = F_23 ( V_38 -> V_111 ) ;
if ( V_2 -> V_81 > V_86 )
return - V_72 ;
V_2 -> V_50 = F_23 ( V_38 -> V_112 ) ;
if ( V_2 -> V_50 > V_2 -> V_88 ) {
F_38 ( V_71 L_29 ,
V_2 -> V_50 ) ;
return - V_72 ;
} else if ( V_2 -> V_50 < V_113 ) {
F_38 ( V_71 L_30 ,
V_2 -> V_50 ) ;
return - V_72 ;
}
V_2 -> V_114 = F_44 ( V_38 -> V_115 ) ;
V_2 -> V_116 = F_44 ( V_38 -> V_117 ) ;
if ( V_2 -> V_116 < V_118 ) {
F_38 ( V_71 L_31 ) ;
return - V_72 ;
}
V_2 -> V_119 = F_31 ( V_38 -> V_120 ) ;
V_2 -> V_121 =
F_44 ( V_38 -> V_122 ) ;
if ( V_2 -> V_121 < 1 ||
V_2 -> V_121 > 99 ) {
F_38 ( V_71 L_32 ) ;
return - V_72 ;
}
F_54 ( V_2 , F_31 ( V_38 -> V_123 ) ) ;
V_2 -> V_82 = F_44 ( V_38 -> V_83 ) ;
return 0 ;
}
static int F_43 ( struct V_37 * V_38 )
{
static unsigned char V_124 [ 4 ] ;
const int V_125 = F_56 ( struct V_37 , V_126 ) ;
T_4 V_127 ;
T_5 V_128 ;
if ( ! V_38 || F_23 ( V_38 -> V_129 ) != V_130 )
return 0 ;
V_127 = F_23 ( V_38 -> V_111 ) ;
if ( V_127 < V_125 + 4 || V_127 > V_86 )
return 0 ;
V_128 = F_57 ( F_44 ( V_38 -> V_83 ) , ( unsigned char * ) V_38 ,
V_125 ) ;
V_128 = F_57 ( V_128 , V_124 , 4 ) ;
V_128 = F_57 ( V_128 , ( unsigned char * ) V_38 + V_125 + 4 ,
V_127 - V_125 - 4 ) ;
return V_128 == F_44 ( V_38 -> V_126 ) ;
}
static int F_58 ( struct V_37 * V_38 , T_2 V_131 )
{
return V_131 < ( ( F_31 ( V_38 -> V_123 ) *
F_44 ( V_38 -> V_117 ) ) <<
( F_44 ( V_38 -> V_87 ) + 10 ) ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < 2 ; V_132 ++ ) {
if ( V_2 -> V_39 [ V_132 ] ) {
F_17 ( V_2 -> V_29 [ V_132 ] ) ;
V_2 -> V_29 [ V_132 ] = NULL ;
V_2 -> V_39 [ V_132 ] = NULL ;
}
}
}
void F_60 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_29 [ 0 ] ) ;
V_2 -> V_29 [ 0 ] = V_2 -> V_29 [ 1 ] ;
V_2 -> V_39 [ 0 ] = V_2 -> V_39 [ 1 ] ;
V_2 -> V_29 [ 1 ] = NULL ;
V_2 -> V_39 [ 1 ] = NULL ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_33 * V_133 = V_2 -> V_29 [ 0 ] ;
struct V_37 * V_134 = V_2 -> V_39 [ 0 ] ;
V_2 -> V_29 [ 0 ] = V_2 -> V_29 [ 1 ] ;
V_2 -> V_39 [ 0 ] = V_2 -> V_39 [ 1 ] ;
V_2 -> V_29 [ 1 ] = V_133 ;
V_2 -> V_39 [ 1 ] = V_134 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_30 * V_31 , int V_79 ,
struct V_37 * * V_135 )
{
struct V_37 * * V_38 = V_2 -> V_39 ;
struct V_33 * * V_136 = V_2 -> V_29 ;
T_2 V_137 = F_63 ( V_2 -> V_15 -> V_138 -> V_139 ) ;
int V_140 [ 2 ] , V_141 = 0 ;
V_38 [ 0 ] = F_64 ( V_31 , V_142 , V_79 ,
& V_136 [ 0 ] ) ;
V_38 [ 1 ] = F_64 ( V_31 , V_137 , V_79 , & V_136 [ 1 ] ) ;
if ( ! V_38 [ 0 ] ) {
if ( ! V_38 [ 1 ] ) {
F_38 ( V_71 L_33 ) ;
return - V_143 ;
}
F_38 ( V_76
L_34
L_35 , V_79 ) ;
} else if ( ! V_38 [ 1 ] ) {
F_38 ( V_76
L_36
L_35 , V_79 ) ;
}
V_140 [ 0 ] = F_43 ( V_38 [ 0 ] ) ;
V_140 [ 1 ] = F_43 ( V_38 [ 1 ] ) ;
V_141 = V_140 [ 1 ] && ( ! V_140 [ 0 ] ||
F_31 ( V_38 [ 1 ] -> V_65 ) >
F_31 ( V_38 [ 0 ] -> V_65 ) ) ;
if ( V_140 [ V_141 ] && F_58 ( V_38 [ V_141 ] , V_137 ) ) {
F_17 ( V_136 [ 1 ] ) ;
V_136 [ 1 ] = NULL ;
V_38 [ 1 ] = NULL ;
V_140 [ 1 ] = 0 ;
V_141 = 0 ;
}
if ( ! V_140 [ V_141 ] ) {
F_59 ( V_2 ) ;
F_38 ( V_71 L_37 ,
V_31 -> V_144 ) ;
return - V_72 ;
}
if ( ! V_140 [ ! V_141 ] )
F_38 ( V_76 L_38
L_39 , V_79 ) ;
if ( V_141 )
F_61 ( V_2 ) ;
V_2 -> V_145 = 0 ;
V_2 -> V_84 = F_31 ( V_38 [ 0 ] -> V_85 ) ;
V_2 -> V_146 = F_31 ( V_38 [ V_140 [ 1 ] & ! V_141 ] -> V_66 ) ;
* V_135 = V_38 [ 0 ] ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 , struct V_30 * V_31 , char * V_147 )
{
struct V_37 * V_38 ;
int V_79 ;
int V_46 ;
F_47 ( & V_2 -> V_17 ) ;
V_79 = F_66 ( V_31 , V_148 ) ;
if ( ! V_79 ) {
F_38 ( V_71 L_40 ) ;
V_46 = - V_72 ;
goto V_149;
}
V_46 = F_62 ( V_2 , V_31 , V_79 , & V_38 ) ;
if ( V_46 )
goto V_149;
V_46 = F_67 ( V_31 , V_38 , V_147 ) ;
if ( V_46 )
goto V_150;
V_46 = F_68 ( V_31 , V_38 ) ;
if ( V_46 )
goto V_150;
V_79 = V_86 << F_44 ( V_38 -> V_87 ) ;
if ( V_79 < V_148 ||
V_79 > V_151 ) {
F_38 ( V_71 L_41
L_42 , V_79 ) ;
V_46 = - V_72 ;
goto V_150;
}
if ( V_31 -> V_152 != V_79 ) {
int V_153 = F_69 ( V_31 -> V_154 ) ;
if ( V_79 < V_153 ) {
F_38 ( V_71
L_43
L_44 ,
V_79 , V_153 ) ;
V_46 = - V_72 ;
goto V_150;
}
F_59 ( V_2 ) ;
F_70 ( V_31 , V_79 ) ;
V_46 = F_62 ( V_2 , V_31 , V_79 , & V_38 ) ;
if ( V_46 )
goto V_149;
}
V_2 -> V_155 = V_31 -> V_156 ;
V_2 -> V_88 = V_79 ;
F_71 ( & V_2 -> V_157 ,
sizeof( V_2 -> V_157 ) ) ;
V_46 = F_55 ( V_2 , V_38 ) ;
if ( V_46 )
goto V_150;
V_31 -> V_158 = F_50 ( V_31 -> V_156 ) ;
V_2 -> V_89 = F_23 ( V_38 -> V_159 ) ;
V_46 = F_36 ( V_2 , V_38 ) ;
if ( V_46 )
goto V_150;
V_46 = F_72 ( V_31 ) ;
if ( V_46 )
goto V_150;
F_73 ( V_2 ) ;
V_46 = 0 ;
V_149:
F_49 ( & V_2 -> V_17 ) ;
return V_46 ;
V_150:
F_59 ( V_2 ) ;
goto V_149;
}
int F_74 ( struct V_1 * V_2 , T_3 * V_160 ,
T_4 V_104 )
{
T_1 V_161 , V_162 ;
T_1 V_163 = 0 , V_164 = 0 ;
unsigned int V_165 ;
T_3 * V_166 ;
int V_63 = 0 ;
V_165 = ( 1 << V_2 -> V_155 ) /
F_69 ( V_2 -> V_15 ) ;
for ( V_166 = V_160 ; V_166 < V_160 + V_104 ; V_166 ++ ) {
F_75 ( V_2 , * V_166 , & V_161 , & V_162 ) ;
if ( ! V_164 ) {
V_163 = V_161 ;
V_164 = V_162 - V_161 + 1 ;
} else if ( V_163 + V_164 == V_161 ) {
V_164 += V_162 - V_161 + 1 ;
} else {
V_63 = F_76 ( V_2 -> V_15 ,
V_163 * V_165 ,
V_164 * V_165 ,
V_167 , 0 ) ;
if ( V_63 < 0 )
return V_63 ;
V_164 = 0 ;
}
}
if ( V_164 )
V_63 = F_76 ( V_2 -> V_15 ,
V_163 * V_165 ,
V_164 * V_165 ,
V_167 , 0 ) ;
return V_63 ;
}
int F_77 ( struct V_1 * V_2 , T_1 * V_164 )
{
unsigned long V_168 ;
F_22 ( & F_78 ( V_2 -> V_52 ) -> V_169 ) ;
V_168 = F_79 ( V_2 -> V_56 ) ;
F_24 ( & F_78 ( V_2 -> V_52 ) -> V_169 ) ;
* V_164 = ( T_1 ) V_168 * V_2 -> V_116 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
unsigned long V_168 , V_170 ;
V_168 = F_79 ( V_2 -> V_56 ) ;
V_170 = F_81 ( & V_2 -> V_16 ) /
V_2 -> V_116 + 1 ;
return V_168 <= V_2 -> V_105 + V_170 ;
}
struct V_171 * F_82 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_172 * V_173 ;
struct V_171 * V_174 ;
F_2 ( & V_2 -> V_25 ) ;
V_173 = V_2 -> V_23 . V_172 ;
while ( V_173 ) {
V_174 = F_83 ( V_173 , struct V_171 , V_172 ) ;
if ( V_5 < V_174 -> V_5 ) {
V_173 = V_173 -> V_175 ;
} else if ( V_5 > V_174 -> V_5 ) {
V_173 = V_173 -> V_176 ;
} else {
F_84 ( & V_174 -> V_177 ) ;
F_5 ( & V_2 -> V_25 ) ;
return V_174 ;
}
}
F_5 ( & V_2 -> V_25 ) ;
return NULL ;
}
struct V_171 *
F_85 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_172 * * V_178 , * V_179 ;
struct V_171 * V_174 , * V_180 ;
int V_46 ;
V_174 = F_82 ( V_2 , V_5 ) ;
if ( V_174 )
return V_174 ;
V_180 = F_7 ( sizeof( * V_174 ) , V_14 ) ;
if ( ! V_180 )
return NULL ;
F_2 ( & V_2 -> V_25 ) ;
V_178 = & V_2 -> V_23 . V_172 ;
V_179 = NULL ;
while ( * V_178 ) {
V_179 = * V_178 ;
V_174 = F_83 ( V_179 , struct V_171 , V_172 ) ;
if ( V_5 < V_174 -> V_5 ) {
V_178 = & ( * V_178 ) -> V_175 ;
} else if ( V_5 > V_174 -> V_5 ) {
V_178 = & ( * V_178 ) -> V_176 ;
} else {
F_84 ( & V_174 -> V_177 ) ;
F_5 ( & V_2 -> V_25 ) ;
F_18 ( V_180 ) ;
return V_174 ;
}
}
V_180 -> V_5 = V_5 ;
V_180 -> V_181 = NULL ;
V_180 -> V_2 = V_2 ;
F_8 ( & V_180 -> V_177 , 1 ) ;
F_86 ( & V_180 -> V_182 , 0 ) ;
F_86 ( & V_180 -> V_183 , 0 ) ;
F_87 ( & V_180 -> V_172 , V_179 , V_178 ) ;
F_88 ( & V_180 -> V_172 , & V_2 -> V_23 ) ;
F_5 ( & V_2 -> V_25 ) ;
V_46 = F_89 ( V_180 ) ;
if ( V_46 ) {
F_18 ( V_180 ) ;
V_180 = NULL ;
}
return V_180 ;
}
void F_90 ( struct V_171 * V_174 )
{
if ( F_91 ( & V_174 -> V_177 ) ) {
struct V_1 * V_2 = V_174 -> V_2 ;
F_92 ( V_174 ) ;
F_2 ( & V_2 -> V_25 ) ;
F_93 ( & V_174 -> V_172 , & V_2 -> V_23 ) ;
F_5 ( & V_2 -> V_25 ) ;
F_32 ( V_174 -> V_181 ) ;
F_18 ( V_174 ) ;
}
}
