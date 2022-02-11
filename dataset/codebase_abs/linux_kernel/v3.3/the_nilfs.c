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
F_10 ( & V_2 -> V_19 ) ;
F_11 ( & V_2 -> V_20 ) ;
F_11 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_6 ) ;
V_2 -> V_22 = V_23 ;
F_11 ( & V_2 -> V_24 ) ;
F_9 ( & V_2 -> V_25 ) ;
return V_2 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 () ;
if ( F_14 ( V_2 ) ) {
F_15 ( V_2 -> V_26 [ 0 ] ) ;
F_15 ( V_2 -> V_26 [ 1 ] ) ;
}
F_16 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_27 * V_28 , T_1 V_29 )
{
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * * V_35 = V_2 -> V_36 ;
struct V_37 * V_38 ;
unsigned V_39 , V_40 , V_41 ;
unsigned V_42 ;
int V_43 ;
V_43 = F_18 ( V_2 , V_29 , & V_31 , 1 ) ;
if ( F_19 ( V_43 ) )
return V_43 ;
F_20 ( & V_2 -> V_17 ) ;
V_39 = F_21 ( V_35 [ 0 ] -> V_44 ) ;
V_41 = F_21 ( V_35 [ 0 ] -> V_45 ) ;
V_40 = F_21 ( V_35 [ 0 ] -> V_46 ) ;
F_22 ( & V_2 -> V_17 ) ;
V_42 = V_2 -> V_47 ;
V_38 = ( void * ) V_31 -> V_48 + F_23 ( V_42 ) ;
V_43 = F_24 ( V_28 , V_39 , V_38 , & V_2 -> V_49 ) ;
if ( V_43 )
goto V_50;
V_38 = ( void * ) V_31 -> V_48 + F_25 ( V_42 ) ;
V_43 = F_26 ( V_28 , V_41 , V_38 , & V_2 -> V_51 ) ;
if ( V_43 )
goto V_52;
V_38 = ( void * ) V_31 -> V_48 + F_27 ( V_42 ) ;
V_43 = F_28 ( V_28 , V_40 , V_38 ,
& V_2 -> V_53 ) ;
if ( V_43 )
goto V_54;
V_33 = (struct V_32 * ) V_31 -> V_48 ;
V_2 -> V_55 = F_29 ( V_33 -> V_56 ) ;
V_50:
F_15 ( V_31 ) ;
return V_43 ;
V_54:
F_30 ( V_2 -> V_51 ) ;
V_52:
F_30 ( V_2 -> V_49 ) ;
goto V_50;
}
static void F_31 ( struct V_57 * V_58 )
{
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
F_10 ( & V_58 -> V_59 ) ;
}
static void F_32 ( struct V_57 * V_58 )
{
F_33 ( & V_58 -> V_59 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
int V_60 = 0 ;
V_2 -> V_7 = F_29 ( V_35 -> V_61 ) ;
V_2 -> V_9 = F_29 ( V_35 -> V_62 ) ;
V_2 -> V_8 = F_29 ( V_35 -> V_63 ) ;
V_2 -> V_10 = V_2 -> V_8 ;
V_2 -> V_64 = V_2 -> V_8 ;
V_2 -> V_65 =
F_35 ( V_2 , V_2 -> V_7 ) ;
V_2 -> V_66 = V_2 -> V_9 + 1 ;
if ( V_2 -> V_65 >= V_2 -> V_67 ) {
F_36 ( V_68 L_1 ) ;
V_60 = - V_69 ;
}
return V_60 ;
}
int F_37 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_57 V_58 ;
unsigned int V_70 = V_28 -> V_70 ;
int V_71 = F_38 ( V_2 -> V_15 ) ;
int V_72 = F_39 ( V_2 ) ;
int V_43 ;
if ( ! V_72 ) {
F_36 ( V_73 L_2 ) ;
if ( V_70 & V_74 ) {
F_36 ( V_75 L_3
L_4 ) ;
F_36 ( V_75 L_5
L_6 ) ;
}
}
F_31 ( & V_58 ) ;
V_43 = F_40 ( V_2 , & V_58 ) ;
if ( F_19 ( V_43 ) ) {
struct V_34 * * V_35 = V_2 -> V_36 ;
int V_76 ;
if ( V_43 != - V_69 )
goto V_77;
if ( ! F_41 ( V_35 [ 1 ] ) ) {
F_36 ( V_73
L_7
L_8 ) ;
goto V_77;
}
F_36 ( V_75
L_9 ) ;
memcpy ( V_35 [ 0 ] , V_35 [ 1 ] , V_2 -> V_78 ) ;
V_2 -> V_79 = F_42 ( V_35 [ 0 ] -> V_80 ) ;
V_2 -> V_81 = F_29 ( V_35 [ 0 ] -> V_82 ) ;
V_76 = V_83 << F_42 ( V_35 [ 0 ] -> V_84 ) ;
if ( V_76 != V_2 -> V_85 ) {
F_36 ( V_73
L_10
L_11 ,
V_76 , V_2 -> V_85 ) ;
goto V_77;
}
V_43 = F_34 ( V_2 , V_35 [ 0 ] ) ;
if ( V_43 )
goto V_77;
V_2 -> V_86 &= ~ V_87 ;
V_72 = 0 ;
V_43 = F_40 ( V_2 , & V_58 ) ;
if ( V_43 )
goto V_77;
}
V_43 = F_17 ( V_2 , V_28 , V_58 . V_88 ) ;
if ( F_19 ( V_43 ) ) {
F_36 ( V_68 L_12 ) ;
goto V_50;
}
if ( V_72 )
goto V_89;
if ( V_70 & V_74 ) {
T_3 V_90 ;
if ( F_43 ( V_2 , V_91 ) ) {
F_36 ( V_75 L_13
L_14 ) ;
goto V_89;
}
V_90 = F_29 ( V_2 -> V_36 [ 0 ] -> V_92 ) &
~ V_93 ;
if ( V_90 ) {
F_36 ( V_68 L_15
L_16
L_17 ,
( unsigned long long ) V_90 ) ;
V_43 = - V_94 ;
goto V_95;
}
if ( V_71 ) {
F_36 ( V_68 L_18
L_19 ) ;
V_43 = - V_94 ;
goto V_95;
}
V_28 -> V_70 &= ~ V_74 ;
} else if ( F_43 ( V_2 , V_91 ) ) {
F_36 ( V_68 L_20
L_21 ) ;
V_43 = - V_69 ;
goto V_95;
}
V_43 = F_44 ( V_2 , V_28 , & V_58 ) ;
if ( V_43 )
goto V_95;
F_45 ( & V_2 -> V_17 ) ;
V_2 -> V_86 |= V_87 ;
V_43 = F_46 ( V_28 ) ;
F_47 ( & V_2 -> V_17 ) ;
if ( V_43 ) {
F_36 ( V_68 L_22
L_23 ) ;
goto V_95;
}
F_36 ( V_75 L_24 ) ;
V_89:
F_32 ( & V_58 ) ;
V_28 -> V_70 = V_70 ;
return 0 ;
V_77:
F_36 ( V_68 L_25 ) ;
goto V_50;
V_95:
F_30 ( V_2 -> V_51 ) ;
F_30 ( V_2 -> V_53 ) ;
F_30 ( V_2 -> V_49 ) ;
V_50:
F_32 ( & V_58 ) ;
V_28 -> V_70 = V_70 ;
return V_43 ;
}
static unsigned long long F_48 ( unsigned int V_96 )
{
unsigned int V_97 ;
unsigned long long V_98 = V_99 ;
V_97 = V_96 + V_100 ;
if ( V_97 < 64 )
V_98 = F_49 (unsigned long long, res, (1ULL << max_bits) - 1 ) ;
return V_98 ;
}
unsigned long F_50 ( struct V_1 * V_2 , unsigned long V_101 )
{
return F_51 (unsigned long, NILFS_MIN_NRSVSEGS,
DIV_ROUND_UP(nsegs * nilfs->ns_r_segments_percentage,
100)) ;
}
void F_52 ( struct V_1 * V_2 , unsigned long V_101 )
{
V_2 -> V_67 = V_101 ;
V_2 -> V_102 = F_50 ( V_2 , V_101 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
if ( F_42 ( V_35 -> V_103 ) < V_104 ) {
F_36 ( V_68 L_26
L_27
L_28 ,
F_42 ( V_35 -> V_103 ) ,
F_21 ( V_35 -> V_105 ) ,
V_106 , V_107 ) ;
return - V_69 ;
}
V_2 -> V_78 = F_21 ( V_35 -> V_108 ) ;
if ( V_2 -> V_78 > V_83 )
return - V_69 ;
V_2 -> V_47 = F_21 ( V_35 -> V_109 ) ;
V_2 -> V_110 = F_42 ( V_35 -> V_111 ) ;
V_2 -> V_112 = F_42 ( V_35 -> V_113 ) ;
if ( V_2 -> V_112 < V_114 ) {
F_36 ( V_68 L_29 ) ;
return - V_69 ;
}
V_2 -> V_115 = F_29 ( V_35 -> V_116 ) ;
V_2 -> V_117 =
F_42 ( V_35 -> V_118 ) ;
if ( V_2 -> V_117 < 1 ||
V_2 -> V_117 > 99 ) {
F_36 ( V_68 L_30 ) ;
return - V_69 ;
}
F_52 ( V_2 , F_29 ( V_35 -> V_119 ) ) ;
V_2 -> V_79 = F_42 ( V_35 -> V_80 ) ;
return 0 ;
}
static int F_41 ( struct V_34 * V_35 )
{
static unsigned char V_120 [ 4 ] ;
const int V_121 = F_54 ( struct V_34 , V_122 ) ;
T_4 V_123 ;
T_5 V_124 ;
if ( ! V_35 || F_21 ( V_35 -> V_125 ) != V_126 )
return 0 ;
V_123 = F_21 ( V_35 -> V_108 ) ;
if ( V_123 > V_83 )
return 0 ;
V_124 = F_55 ( F_42 ( V_35 -> V_80 ) , ( unsigned char * ) V_35 ,
V_121 ) ;
V_124 = F_55 ( V_124 , V_120 , 4 ) ;
V_124 = F_55 ( V_124 , ( unsigned char * ) V_35 + V_121 + 4 ,
V_123 - V_121 - 4 ) ;
return V_124 == F_42 ( V_35 -> V_122 ) ;
}
static int F_56 ( struct V_34 * V_35 , T_2 V_127 )
{
return V_127 < ( ( F_29 ( V_35 -> V_119 ) *
F_42 ( V_35 -> V_113 ) ) <<
( F_42 ( V_35 -> V_84 ) + 10 ) ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
int V_128 ;
for ( V_128 = 0 ; V_128 < 2 ; V_128 ++ ) {
if ( V_2 -> V_36 [ V_128 ] ) {
F_15 ( V_2 -> V_26 [ V_128 ] ) ;
V_2 -> V_26 [ V_128 ] = NULL ;
V_2 -> V_36 [ V_128 ] = NULL ;
}
}
}
void F_58 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_26 [ 0 ] ) ;
V_2 -> V_26 [ 0 ] = V_2 -> V_26 [ 1 ] ;
V_2 -> V_36 [ 0 ] = V_2 -> V_36 [ 1 ] ;
V_2 -> V_26 [ 1 ] = NULL ;
V_2 -> V_36 [ 1 ] = NULL ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_30 * V_129 = V_2 -> V_26 [ 0 ] ;
struct V_34 * V_130 = V_2 -> V_36 [ 0 ] ;
V_2 -> V_26 [ 0 ] = V_2 -> V_26 [ 1 ] ;
V_2 -> V_36 [ 0 ] = V_2 -> V_36 [ 1 ] ;
V_2 -> V_26 [ 1 ] = V_129 ;
V_2 -> V_36 [ 1 ] = V_130 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_27 * V_28 , int V_76 ,
struct V_34 * * V_131 )
{
struct V_34 * * V_35 = V_2 -> V_36 ;
struct V_30 * * V_132 = V_2 -> V_26 ;
T_2 V_133 = F_61 ( V_2 -> V_15 -> V_134 -> V_135 ) ;
int V_136 [ 2 ] , V_137 = 0 ;
V_35 [ 0 ] = F_62 ( V_28 , V_138 , V_76 ,
& V_132 [ 0 ] ) ;
V_35 [ 1 ] = F_62 ( V_28 , V_133 , V_76 , & V_132 [ 1 ] ) ;
if ( ! V_35 [ 0 ] ) {
if ( ! V_35 [ 1 ] ) {
F_36 ( V_68 L_31 ) ;
return - V_139 ;
}
F_36 ( V_73
L_32
L_33 , V_76 ) ;
} else if ( ! V_35 [ 1 ] ) {
F_36 ( V_73
L_34
L_33 , V_76 ) ;
}
V_136 [ 0 ] = F_41 ( V_35 [ 0 ] ) ;
V_136 [ 1 ] = F_41 ( V_35 [ 1 ] ) ;
V_137 = V_136 [ 1 ] && ( ! V_136 [ 0 ] ||
F_29 ( V_35 [ 1 ] -> V_62 ) >
F_29 ( V_35 [ 0 ] -> V_62 ) ) ;
if ( V_136 [ V_137 ] && F_56 ( V_35 [ V_137 ] , V_133 ) ) {
F_15 ( V_132 [ 1 ] ) ;
V_132 [ 1 ] = NULL ;
V_35 [ 1 ] = NULL ;
V_136 [ 1 ] = 0 ;
V_137 = 0 ;
}
if ( ! V_136 [ V_137 ] ) {
F_57 ( V_2 ) ;
F_36 ( V_68 L_35 ,
V_28 -> V_140 ) ;
return - V_69 ;
}
if ( ! V_136 [ ! V_137 ] )
F_36 ( V_73 L_36
L_37 , V_76 ) ;
if ( V_137 )
F_59 ( V_2 ) ;
V_2 -> V_141 = 0 ;
V_2 -> V_81 = F_29 ( V_35 [ 0 ] -> V_82 ) ;
V_2 -> V_142 = F_29 ( V_35 [ V_136 [ 1 ] & ! V_137 ] -> V_63 ) ;
* V_131 = V_35 [ 0 ] ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 , struct V_27 * V_28 , char * V_143 )
{
struct V_34 * V_35 ;
int V_76 ;
int V_43 ;
F_45 ( & V_2 -> V_17 ) ;
V_76 = F_64 ( V_28 , V_144 ) ;
if ( ! V_76 ) {
F_36 ( V_68 L_38 ) ;
V_43 = - V_69 ;
goto V_145;
}
V_43 = F_60 ( V_2 , V_28 , V_76 , & V_35 ) ;
if ( V_43 )
goto V_145;
V_43 = F_65 ( V_28 , V_35 , V_143 ) ;
if ( V_43 )
goto V_146;
V_43 = F_66 ( V_28 , V_35 ) ;
if ( V_43 )
goto V_146;
V_76 = V_83 << F_42 ( V_35 -> V_84 ) ;
if ( V_76 < V_144 ||
V_76 > V_147 ) {
F_36 ( V_68 L_39
L_40 , V_76 ) ;
V_43 = - V_69 ;
goto V_146;
}
if ( V_28 -> V_148 != V_76 ) {
int V_149 = F_67 ( V_28 -> V_150 ) ;
if ( V_76 < V_149 ) {
F_36 ( V_68
L_41
L_42 ,
V_76 , V_149 ) ;
V_43 = - V_69 ;
goto V_146;
}
F_57 ( V_2 ) ;
F_68 ( V_28 , V_76 ) ;
V_43 = F_60 ( V_2 , V_28 , V_76 , & V_35 ) ;
if ( V_43 )
goto V_145;
}
V_2 -> V_151 = V_28 -> V_152 ;
V_2 -> V_85 = V_76 ;
F_69 ( & V_2 -> V_153 ,
sizeof( V_2 -> V_153 ) ) ;
V_43 = F_53 ( V_2 , V_35 ) ;
if ( V_43 )
goto V_146;
V_28 -> V_154 = F_48 ( V_28 -> V_152 ) ;
V_2 -> V_86 = F_21 ( V_35 -> V_155 ) ;
V_43 = F_34 ( V_2 , V_35 ) ;
if ( V_43 )
goto V_146;
F_70 ( V_2 ) ;
V_43 = 0 ;
V_145:
F_47 ( & V_2 -> V_17 ) ;
return V_43 ;
V_146:
F_57 ( V_2 ) ;
goto V_145;
}
int F_71 ( struct V_1 * V_2 , T_3 * V_156 ,
T_4 V_101 )
{
T_1 V_157 , V_158 ;
T_1 V_159 = 0 , V_160 = 0 ;
unsigned int V_161 ;
T_3 * V_162 ;
int V_60 = 0 ;
V_161 = ( 1 << V_2 -> V_151 ) /
F_67 ( V_2 -> V_15 ) ;
for ( V_162 = V_156 ; V_162 < V_156 + V_101 ; V_162 ++ ) {
F_72 ( V_2 , * V_162 , & V_157 , & V_158 ) ;
if ( ! V_160 ) {
V_159 = V_157 ;
V_160 = V_158 - V_157 + 1 ;
} else if ( V_159 + V_160 == V_157 ) {
V_160 += V_158 - V_157 + 1 ;
} else {
V_60 = F_73 ( V_2 -> V_15 ,
V_159 * V_161 ,
V_160 * V_161 ,
V_163 , 0 ) ;
if ( V_60 < 0 )
return V_60 ;
V_160 = 0 ;
}
}
if ( V_160 )
V_60 = F_73 ( V_2 -> V_15 ,
V_159 * V_161 ,
V_160 * V_161 ,
V_163 , 0 ) ;
return V_60 ;
}
int F_74 ( struct V_1 * V_2 , T_1 * V_160 )
{
unsigned long V_164 ;
F_20 ( & F_75 ( V_2 -> V_49 ) -> V_165 ) ;
V_164 = F_76 ( V_2 -> V_53 ) ;
F_22 ( & F_75 ( V_2 -> V_49 ) -> V_165 ) ;
* V_160 = ( T_1 ) V_164 * V_2 -> V_112 ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 )
{
unsigned long V_164 , V_166 ;
V_164 = F_76 ( V_2 -> V_53 ) ;
V_166 = F_78 ( & V_2 -> V_16 ) /
V_2 -> V_112 + 1 ;
return V_164 <= V_2 -> V_102 + V_166 ;
}
struct V_167 * F_79 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_168 * V_169 ;
struct V_167 * V_170 ;
F_2 ( & V_2 -> V_24 ) ;
V_169 = V_2 -> V_22 . V_168 ;
while ( V_169 ) {
V_170 = F_80 ( V_169 , struct V_167 , V_168 ) ;
if ( V_5 < V_170 -> V_5 ) {
V_169 = V_169 -> V_171 ;
} else if ( V_5 > V_170 -> V_5 ) {
V_169 = V_169 -> V_172 ;
} else {
F_81 ( & V_170 -> V_173 ) ;
F_5 ( & V_2 -> V_24 ) ;
return V_170 ;
}
}
F_5 ( & V_2 -> V_24 ) ;
return NULL ;
}
struct V_167 *
F_82 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_168 * * V_174 , * V_175 ;
struct V_167 * V_170 , * V_176 ;
V_170 = F_79 ( V_2 , V_5 ) ;
if ( V_170 )
return V_170 ;
V_176 = F_83 ( sizeof( * V_170 ) , V_14 ) ;
if ( ! V_176 )
return NULL ;
F_2 ( & V_2 -> V_24 ) ;
V_174 = & V_2 -> V_22 . V_168 ;
V_175 = NULL ;
while ( * V_174 ) {
V_175 = * V_174 ;
V_170 = F_80 ( V_175 , struct V_167 , V_168 ) ;
if ( V_5 < V_170 -> V_5 ) {
V_174 = & ( * V_174 ) -> V_171 ;
} else if ( V_5 > V_170 -> V_5 ) {
V_174 = & ( * V_174 ) -> V_172 ;
} else {
F_81 ( & V_170 -> V_173 ) ;
F_5 ( & V_2 -> V_24 ) ;
F_16 ( V_176 ) ;
return V_170 ;
}
}
V_176 -> V_5 = V_5 ;
V_176 -> V_177 = NULL ;
V_176 -> V_2 = V_2 ;
F_8 ( & V_176 -> V_173 , 1 ) ;
F_8 ( & V_176 -> V_178 , 0 ) ;
F_8 ( & V_176 -> V_179 , 0 ) ;
F_84 ( & V_176 -> V_168 , V_175 , V_174 ) ;
F_85 ( & V_176 -> V_168 , & V_2 -> V_22 ) ;
F_5 ( & V_2 -> V_24 ) ;
return V_176 ;
}
void F_86 ( struct V_167 * V_170 )
{
if ( F_87 ( & V_170 -> V_173 ) ) {
struct V_1 * V_2 = V_170 -> V_2 ;
F_2 ( & V_2 -> V_24 ) ;
F_88 ( & V_170 -> V_168 , & V_2 -> V_22 ) ;
F_5 ( & V_2 -> V_24 ) ;
if ( V_170 -> V_177 )
F_30 ( V_170 -> V_177 ) ;
F_16 ( V_170 ) ;
}
}
