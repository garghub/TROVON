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
return V_2 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 () ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_2 -> V_27 [ 0 ] ) ;
F_16 ( V_2 -> V_27 [ 1 ] ) ;
}
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_28 * V_29 , T_1 V_30 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * * V_36 = V_2 -> V_37 ;
struct V_38 * V_39 ;
unsigned V_40 , V_41 , V_42 ;
unsigned V_43 ;
int V_44 ;
V_44 = F_19 ( V_2 , V_30 , & V_32 , 1 ) ;
if ( F_20 ( V_44 ) )
return V_44 ;
F_21 ( & V_2 -> V_17 ) ;
V_40 = F_22 ( V_36 [ 0 ] -> V_45 ) ;
V_42 = F_22 ( V_36 [ 0 ] -> V_46 ) ;
V_41 = F_22 ( V_36 [ 0 ] -> V_47 ) ;
F_23 ( & V_2 -> V_17 ) ;
V_43 = V_2 -> V_48 ;
V_39 = ( void * ) V_32 -> V_49 + F_24 ( V_43 ) ;
V_44 = F_25 ( V_29 , V_40 , V_39 , & V_2 -> V_50 ) ;
if ( V_44 )
goto V_51;
V_39 = ( void * ) V_32 -> V_49 + F_26 ( V_43 ) ;
V_44 = F_27 ( V_29 , V_42 , V_39 , & V_2 -> V_52 ) ;
if ( V_44 )
goto V_53;
V_39 = ( void * ) V_32 -> V_49 + F_28 ( V_43 ) ;
V_44 = F_29 ( V_29 , V_41 , V_39 ,
& V_2 -> V_54 ) ;
if ( V_44 )
goto V_55;
V_34 = (struct V_33 * ) V_32 -> V_49 ;
V_2 -> V_56 = F_30 ( V_34 -> V_57 ) ;
V_51:
F_16 ( V_32 ) ;
return V_44 ;
V_55:
F_31 ( V_2 -> V_52 ) ;
V_53:
F_31 ( V_2 -> V_50 ) ;
goto V_51;
}
static void F_32 ( struct V_58 * V_59 )
{
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
F_11 ( & V_59 -> V_60 ) ;
}
static void F_33 ( struct V_58 * V_59 )
{
F_34 ( & V_59 -> V_60 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_61 = 0 ;
V_2 -> V_7 = F_30 ( V_36 -> V_62 ) ;
V_2 -> V_9 = F_30 ( V_36 -> V_63 ) ;
V_2 -> V_8 = F_30 ( V_36 -> V_64 ) ;
V_2 -> V_10 = V_2 -> V_8 ;
V_2 -> V_65 = V_2 -> V_8 ;
V_2 -> V_66 =
F_36 ( V_2 , V_2 -> V_7 ) ;
V_2 -> V_67 = V_2 -> V_9 + 1 ;
if ( V_2 -> V_66 >= V_2 -> V_68 ) {
F_37 ( V_69 L_1 ) ;
V_61 = - V_70 ;
}
return V_61 ;
}
int F_38 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_58 V_59 ;
unsigned int V_71 = V_29 -> V_71 ;
int V_72 = F_39 ( V_2 -> V_15 ) ;
int V_73 = F_40 ( V_2 ) ;
int V_44 ;
if ( ! V_73 ) {
F_37 ( V_74 L_2 ) ;
if ( V_71 & V_75 ) {
F_37 ( V_76 L_3
L_4 ) ;
F_37 ( V_76 L_5
L_6 ) ;
}
}
F_32 ( & V_59 ) ;
V_44 = F_41 ( V_2 , & V_59 ) ;
if ( F_20 ( V_44 ) ) {
struct V_35 * * V_36 = V_2 -> V_37 ;
int V_77 ;
if ( V_44 != - V_70 )
goto V_78;
if ( ! F_42 ( V_36 [ 1 ] ) ) {
F_37 ( V_74
L_7
L_8 ) ;
goto V_78;
}
F_37 ( V_76
L_9 ) ;
memcpy ( V_36 [ 0 ] , V_36 [ 1 ] , V_2 -> V_79 ) ;
V_2 -> V_80 = F_43 ( V_36 [ 0 ] -> V_81 ) ;
V_2 -> V_82 = F_30 ( V_36 [ 0 ] -> V_83 ) ;
V_77 = V_84 << F_43 ( V_36 [ 0 ] -> V_85 ) ;
if ( V_77 != V_2 -> V_86 ) {
F_37 ( V_74
L_10
L_11 ,
V_77 , V_2 -> V_86 ) ;
goto V_78;
}
V_44 = F_35 ( V_2 , V_36 [ 0 ] ) ;
if ( V_44 )
goto V_78;
V_2 -> V_87 &= ~ V_88 ;
V_73 = 0 ;
V_44 = F_41 ( V_2 , & V_59 ) ;
if ( V_44 )
goto V_78;
}
V_44 = F_18 ( V_2 , V_29 , V_59 . V_89 ) ;
if ( F_20 ( V_44 ) ) {
F_37 ( V_69 L_12 ) ;
goto V_51;
}
if ( V_73 )
goto V_90;
if ( V_71 & V_75 ) {
T_3 V_91 ;
if ( F_44 ( V_2 , V_92 ) ) {
F_37 ( V_76 L_13
L_14 ) ;
goto V_90;
}
V_91 = F_30 ( V_2 -> V_37 [ 0 ] -> V_93 ) &
~ V_94 ;
if ( V_91 ) {
F_37 ( V_69 L_15
L_16
L_17 ,
( unsigned long long ) V_91 ) ;
V_44 = - V_95 ;
goto V_96;
}
if ( V_72 ) {
F_37 ( V_69 L_18
L_19 ) ;
V_44 = - V_95 ;
goto V_96;
}
V_29 -> V_71 &= ~ V_75 ;
} else if ( F_44 ( V_2 , V_92 ) ) {
F_37 ( V_69 L_20
L_21 ) ;
V_44 = - V_70 ;
goto V_96;
}
V_44 = F_45 ( V_2 , V_29 , & V_59 ) ;
if ( V_44 )
goto V_96;
F_46 ( & V_2 -> V_17 ) ;
V_2 -> V_87 |= V_88 ;
V_44 = F_47 ( V_29 ) ;
F_48 ( & V_2 -> V_17 ) ;
if ( V_44 ) {
F_37 ( V_69 L_22
L_23 ) ;
goto V_96;
}
F_37 ( V_76 L_24 ) ;
V_90:
F_33 ( & V_59 ) ;
V_29 -> V_71 = V_71 ;
return 0 ;
V_78:
F_37 ( V_69 L_25 ) ;
goto V_51;
V_96:
F_31 ( V_2 -> V_52 ) ;
F_31 ( V_2 -> V_54 ) ;
F_31 ( V_2 -> V_50 ) ;
V_51:
F_33 ( & V_59 ) ;
V_29 -> V_71 = V_71 ;
return V_44 ;
}
static unsigned long long F_49 ( unsigned int V_97 )
{
unsigned int V_98 ;
unsigned long long V_99 = V_100 ;
V_98 = V_97 + V_101 ;
if ( V_98 < 64 )
V_99 = F_50 (unsigned long long, res, (1ULL << max_bits) - 1 ) ;
return V_99 ;
}
unsigned long F_51 ( struct V_1 * V_2 , unsigned long V_102 )
{
return F_52 (unsigned long, NILFS_MIN_NRSVSEGS,
DIV_ROUND_UP(nsegs * nilfs->ns_r_segments_percentage,
100)) ;
}
void F_53 ( struct V_1 * V_2 , unsigned long V_102 )
{
V_2 -> V_68 = V_102 ;
V_2 -> V_103 = F_51 ( V_2 , V_102 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
if ( F_43 ( V_36 -> V_104 ) < V_105 ) {
F_37 ( V_69 L_26
L_27
L_28 ,
F_43 ( V_36 -> V_104 ) ,
F_22 ( V_36 -> V_106 ) ,
V_107 , V_108 ) ;
return - V_70 ;
}
V_2 -> V_79 = F_22 ( V_36 -> V_109 ) ;
if ( V_2 -> V_79 > V_84 )
return - V_70 ;
V_2 -> V_48 = F_22 ( V_36 -> V_110 ) ;
V_2 -> V_111 = F_43 ( V_36 -> V_112 ) ;
V_2 -> V_113 = F_43 ( V_36 -> V_114 ) ;
if ( V_2 -> V_113 < V_115 ) {
F_37 ( V_69 L_29 ) ;
return - V_70 ;
}
V_2 -> V_116 = F_30 ( V_36 -> V_117 ) ;
V_2 -> V_118 =
F_43 ( V_36 -> V_119 ) ;
if ( V_2 -> V_118 < 1 ||
V_2 -> V_118 > 99 ) {
F_37 ( V_69 L_30 ) ;
return - V_70 ;
}
F_53 ( V_2 , F_30 ( V_36 -> V_120 ) ) ;
V_2 -> V_80 = F_43 ( V_36 -> V_81 ) ;
return 0 ;
}
static int F_42 ( struct V_35 * V_36 )
{
static unsigned char V_121 [ 4 ] ;
const int V_122 = F_55 ( struct V_35 , V_123 ) ;
T_4 V_124 ;
T_5 V_125 ;
if ( ! V_36 || F_22 ( V_36 -> V_126 ) != V_127 )
return 0 ;
V_124 = F_22 ( V_36 -> V_109 ) ;
if ( V_124 > V_84 )
return 0 ;
V_125 = F_56 ( F_43 ( V_36 -> V_81 ) , ( unsigned char * ) V_36 ,
V_122 ) ;
V_125 = F_56 ( V_125 , V_121 , 4 ) ;
V_125 = F_56 ( V_125 , ( unsigned char * ) V_36 + V_122 + 4 ,
V_124 - V_122 - 4 ) ;
return V_125 == F_43 ( V_36 -> V_123 ) ;
}
static int F_57 ( struct V_35 * V_36 , T_2 V_128 )
{
return V_128 < ( ( F_30 ( V_36 -> V_120 ) *
F_43 ( V_36 -> V_114 ) ) <<
( F_43 ( V_36 -> V_85 ) + 10 ) ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < 2 ; V_129 ++ ) {
if ( V_2 -> V_37 [ V_129 ] ) {
F_16 ( V_2 -> V_27 [ V_129 ] ) ;
V_2 -> V_27 [ V_129 ] = NULL ;
V_2 -> V_37 [ V_129 ] = NULL ;
}
}
}
void F_59 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_27 [ 0 ] ) ;
V_2 -> V_27 [ 0 ] = V_2 -> V_27 [ 1 ] ;
V_2 -> V_37 [ 0 ] = V_2 -> V_37 [ 1 ] ;
V_2 -> V_27 [ 1 ] = NULL ;
V_2 -> V_37 [ 1 ] = NULL ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_31 * V_130 = V_2 -> V_27 [ 0 ] ;
struct V_35 * V_131 = V_2 -> V_37 [ 0 ] ;
V_2 -> V_27 [ 0 ] = V_2 -> V_27 [ 1 ] ;
V_2 -> V_37 [ 0 ] = V_2 -> V_37 [ 1 ] ;
V_2 -> V_27 [ 1 ] = V_130 ;
V_2 -> V_37 [ 1 ] = V_131 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_28 * V_29 , int V_77 ,
struct V_35 * * V_132 )
{
struct V_35 * * V_36 = V_2 -> V_37 ;
struct V_31 * * V_133 = V_2 -> V_27 ;
T_2 V_134 = F_62 ( V_2 -> V_15 -> V_135 -> V_136 ) ;
int V_137 [ 2 ] , V_138 = 0 ;
V_36 [ 0 ] = F_63 ( V_29 , V_139 , V_77 ,
& V_133 [ 0 ] ) ;
V_36 [ 1 ] = F_63 ( V_29 , V_134 , V_77 , & V_133 [ 1 ] ) ;
if ( ! V_36 [ 0 ] ) {
if ( ! V_36 [ 1 ] ) {
F_37 ( V_69 L_31 ) ;
return - V_140 ;
}
F_37 ( V_74
L_32
L_33 , V_77 ) ;
} else if ( ! V_36 [ 1 ] ) {
F_37 ( V_74
L_34
L_33 , V_77 ) ;
}
V_137 [ 0 ] = F_42 ( V_36 [ 0 ] ) ;
V_137 [ 1 ] = F_42 ( V_36 [ 1 ] ) ;
V_138 = V_137 [ 1 ] && ( ! V_137 [ 0 ] ||
F_30 ( V_36 [ 1 ] -> V_63 ) >
F_30 ( V_36 [ 0 ] -> V_63 ) ) ;
if ( V_137 [ V_138 ] && F_57 ( V_36 [ V_138 ] , V_134 ) ) {
F_16 ( V_133 [ 1 ] ) ;
V_133 [ 1 ] = NULL ;
V_36 [ 1 ] = NULL ;
V_137 [ 1 ] = 0 ;
V_138 = 0 ;
}
if ( ! V_137 [ V_138 ] ) {
F_58 ( V_2 ) ;
F_37 ( V_69 L_35 ,
V_29 -> V_141 ) ;
return - V_70 ;
}
if ( ! V_137 [ ! V_138 ] )
F_37 ( V_74 L_36
L_37 , V_77 ) ;
if ( V_138 )
F_60 ( V_2 ) ;
V_2 -> V_142 = 0 ;
V_2 -> V_82 = F_30 ( V_36 [ 0 ] -> V_83 ) ;
V_2 -> V_143 = F_30 ( V_36 [ V_137 [ 1 ] & ! V_138 ] -> V_64 ) ;
* V_132 = V_36 [ 0 ] ;
return 0 ;
}
int F_64 ( struct V_1 * V_2 , struct V_28 * V_29 , char * V_144 )
{
struct V_35 * V_36 ;
int V_77 ;
int V_44 ;
F_46 ( & V_2 -> V_17 ) ;
V_77 = F_65 ( V_29 , V_145 ) ;
if ( ! V_77 ) {
F_37 ( V_69 L_38 ) ;
V_44 = - V_70 ;
goto V_146;
}
V_44 = F_61 ( V_2 , V_29 , V_77 , & V_36 ) ;
if ( V_44 )
goto V_146;
V_44 = F_66 ( V_29 , V_36 , V_144 ) ;
if ( V_44 )
goto V_147;
V_44 = F_67 ( V_29 , V_36 ) ;
if ( V_44 )
goto V_147;
V_77 = V_84 << F_43 ( V_36 -> V_85 ) ;
if ( V_77 < V_145 ||
V_77 > V_148 ) {
F_37 ( V_69 L_39
L_40 , V_77 ) ;
V_44 = - V_70 ;
goto V_147;
}
if ( V_29 -> V_149 != V_77 ) {
int V_150 = F_68 ( V_29 -> V_151 ) ;
if ( V_77 < V_150 ) {
F_37 ( V_69
L_41
L_42 ,
V_77 , V_150 ) ;
V_44 = - V_70 ;
goto V_147;
}
F_58 ( V_2 ) ;
F_69 ( V_29 , V_77 ) ;
V_44 = F_61 ( V_2 , V_29 , V_77 , & V_36 ) ;
if ( V_44 )
goto V_146;
}
V_2 -> V_152 = V_29 -> V_153 ;
V_2 -> V_86 = V_77 ;
F_70 ( & V_2 -> V_154 ,
sizeof( V_2 -> V_154 ) ) ;
V_44 = F_54 ( V_2 , V_36 ) ;
if ( V_44 )
goto V_147;
V_29 -> V_155 = F_49 ( V_29 -> V_153 ) ;
V_2 -> V_87 = F_22 ( V_36 -> V_156 ) ;
V_44 = F_35 ( V_2 , V_36 ) ;
if ( V_44 )
goto V_147;
F_71 ( V_2 ) ;
V_44 = 0 ;
V_146:
F_48 ( & V_2 -> V_17 ) ;
return V_44 ;
V_147:
F_58 ( V_2 ) ;
goto V_146;
}
int F_72 ( struct V_1 * V_2 , T_3 * V_157 ,
T_4 V_102 )
{
T_1 V_158 , V_159 ;
T_1 V_160 = 0 , V_161 = 0 ;
unsigned int V_162 ;
T_3 * V_163 ;
int V_61 = 0 ;
V_162 = ( 1 << V_2 -> V_152 ) /
F_68 ( V_2 -> V_15 ) ;
for ( V_163 = V_157 ; V_163 < V_157 + V_102 ; V_163 ++ ) {
F_73 ( V_2 , * V_163 , & V_158 , & V_159 ) ;
if ( ! V_161 ) {
V_160 = V_158 ;
V_161 = V_159 - V_158 + 1 ;
} else if ( V_160 + V_161 == V_158 ) {
V_161 += V_159 - V_158 + 1 ;
} else {
V_61 = F_74 ( V_2 -> V_15 ,
V_160 * V_162 ,
V_161 * V_162 ,
V_164 , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
V_161 = 0 ;
}
}
if ( V_161 )
V_61 = F_74 ( V_2 -> V_15 ,
V_160 * V_162 ,
V_161 * V_162 ,
V_164 , 0 ) ;
return V_61 ;
}
int F_75 ( struct V_1 * V_2 , T_1 * V_161 )
{
unsigned long V_165 ;
F_21 ( & F_76 ( V_2 -> V_50 ) -> V_166 ) ;
V_165 = F_77 ( V_2 -> V_54 ) ;
F_23 ( & F_76 ( V_2 -> V_50 ) -> V_166 ) ;
* V_161 = ( T_1 ) V_165 * V_2 -> V_113 ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 )
{
unsigned long V_165 , V_167 ;
V_165 = F_77 ( V_2 -> V_54 ) ;
V_167 = F_79 ( & V_2 -> V_16 ) /
V_2 -> V_113 + 1 ;
return V_165 <= V_2 -> V_103 + V_167 ;
}
struct V_168 * F_80 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_169 * V_170 ;
struct V_168 * V_171 ;
F_2 ( & V_2 -> V_25 ) ;
V_170 = V_2 -> V_23 . V_169 ;
while ( V_170 ) {
V_171 = F_81 ( V_170 , struct V_168 , V_169 ) ;
if ( V_5 < V_171 -> V_5 ) {
V_170 = V_170 -> V_172 ;
} else if ( V_5 > V_171 -> V_5 ) {
V_170 = V_170 -> V_173 ;
} else {
F_82 ( & V_171 -> V_174 ) ;
F_5 ( & V_2 -> V_25 ) ;
return V_171 ;
}
}
F_5 ( & V_2 -> V_25 ) ;
return NULL ;
}
struct V_168 *
F_83 ( struct V_1 * V_2 , T_3 V_5 )
{
struct V_169 * * V_175 , * V_176 ;
struct V_168 * V_171 , * V_177 ;
V_171 = F_80 ( V_2 , V_5 ) ;
if ( V_171 )
return V_171 ;
V_177 = F_84 ( sizeof( * V_171 ) , V_14 ) ;
if ( ! V_177 )
return NULL ;
F_2 ( & V_2 -> V_25 ) ;
V_175 = & V_2 -> V_23 . V_169 ;
V_176 = NULL ;
while ( * V_175 ) {
V_176 = * V_175 ;
V_171 = F_81 ( V_176 , struct V_168 , V_169 ) ;
if ( V_5 < V_171 -> V_5 ) {
V_175 = & ( * V_175 ) -> V_172 ;
} else if ( V_5 > V_171 -> V_5 ) {
V_175 = & ( * V_175 ) -> V_173 ;
} else {
F_82 ( & V_171 -> V_174 ) ;
F_5 ( & V_2 -> V_25 ) ;
F_17 ( V_177 ) ;
return V_171 ;
}
}
V_177 -> V_5 = V_5 ;
V_177 -> V_178 = NULL ;
V_177 -> V_2 = V_2 ;
F_8 ( & V_177 -> V_174 , 1 ) ;
F_85 ( & V_177 -> V_179 , 0 ) ;
F_85 ( & V_177 -> V_180 , 0 ) ;
F_86 ( & V_177 -> V_169 , V_176 , V_175 ) ;
F_87 ( & V_177 -> V_169 , & V_2 -> V_23 ) ;
F_5 ( & V_2 -> V_25 ) ;
return V_177 ;
}
void F_88 ( struct V_168 * V_171 )
{
if ( F_89 ( & V_171 -> V_174 ) ) {
struct V_1 * V_2 = V_171 -> V_2 ;
F_2 ( & V_2 -> V_25 ) ;
F_90 ( & V_171 -> V_169 , & V_2 -> V_23 ) ;
F_5 ( & V_2 -> V_25 ) ;
if ( V_171 -> V_178 )
F_31 ( V_171 -> V_178 ) ;
F_17 ( V_171 ) ;
}
}
