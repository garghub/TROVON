static struct V_1 * F_1 ( T_1 V_2 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( V_5 [ V_3 ] . V_2 == V_2 )
return V_5 + V_3 ;
return V_5 ;
}
static int F_2 ( struct V_6 * V_7 )
{
int V_8 ;
V_7 -> V_9 = F_3 ( L_1 ) ;
V_7 -> V_10 = F_3 ( L_2 ) ;
if ( V_7 -> V_9 < 0 || V_7 -> V_10 < 0 ) {
F_4 ( & V_7 -> V_11 -> V_12 , L_3 ) ;
return - V_13 ;
}
V_8 = F_5 ( V_7 -> V_9 , L_4 ) ;
if ( V_8 ) {
F_4 ( & V_7 -> V_11 -> V_12 , L_5 ) ;
return V_8 ;
}
V_8 = F_5 ( V_7 -> V_10 , L_4 ) ;
if ( V_8 ) {
F_4 ( & V_7 -> V_11 -> V_12 , L_6 ) ;
F_6 ( V_7 -> V_9 ) ;
return V_8 ;
}
F_7 ( V_7 -> V_9 , 0 ) ;
F_7 ( V_7 -> V_10 , 0 ) ;
return 0 ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_9 ( V_7 -> V_9 , 1 ) ;
F_9 ( V_7 -> V_10 , 0 ) ;
F_10 ( 20 ) ;
F_9 ( V_7 -> V_10 , 1 ) ;
F_10 ( 20 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
F_9 ( V_7 -> V_9 , 0 ) ;
F_9 ( V_7 -> V_10 , 0 ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
F_11 ( V_7 ) ;
F_6 ( V_7 -> V_9 ) ;
F_6 ( V_7 -> V_10 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_14 V_15 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_15 . V_16 = V_17 ;
V_15 . V_18 = V_19 ;
return F_14 ( NULL , V_7 -> V_20 -> V_21 , & V_15 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_22 V_23 = {
. V_24 = V_25 ,
} ;
int V_8 ;
F_16 ( & V_23 . V_23 , & V_7 -> V_26 , V_7 -> V_27 ) ;
V_8 = F_17 ( V_7 , V_28 , V_29 , 0 ) ;
if ( V_8 == 0 )
V_8 = F_17 ( V_7 , V_30 , V_31 , NULL , & V_23 ) ;
if ( V_8 == 0 )
V_8 = F_13 ( V_7 ) ;
return V_8 ;
}
static inline void F_18 ( struct V_6 * V_7 ,
int V_32 , int V_18 )
{
F_19 ( V_18 , V_7 -> V_33 + V_32 ) ;
}
static inline int F_20 ( struct V_6 * V_7 , int V_32 )
{
return F_21 ( V_7 -> V_33 + V_32 ) ;
}
static inline void F_22 ( struct V_6 * V_7 ,
int V_32 , int V_18 , int V_34 )
{
int V_35 = F_20 ( V_7 , V_32 ) ;
V_35 = ( V_35 & ~ V_34 ) | ( V_18 & V_34 ) ;
F_18 ( V_7 , V_32 , V_35 ) ;
}
static T_2 F_23 ( int V_36 , void * V_37 )
{
struct V_6 * V_7 = V_37 ;
T_2 V_8 = V_38 ;
int V_39 ;
F_24 ( & V_7 -> V_40 -> V_41 ) ;
V_39 = F_20 ( V_7 , V_42 ) ;
if ( V_39 & V_43 ) {
V_39 |= V_43 | V_44 | V_45 ;
F_18 ( V_7 , V_42 , V_39 ) ;
V_8 = V_46 ;
}
F_25 ( & V_7 -> V_40 -> V_41 ) ;
return V_8 ;
}
static struct V_47 * F_26 ( struct V_6 * V_7 )
{
unsigned long V_48 ;
struct V_47 * V_49 = NULL ;
F_27 ( & V_7 -> V_40 -> V_41 , V_48 ) ;
if ( V_7 -> V_50 != V_51 )
goto V_52;
if ( F_28 ( & V_7 -> V_53 ) )
goto V_52;
V_49 = F_29 ( V_7 -> V_53 . V_54 , struct V_47 , V_55 ) ;
if ( ! F_30 ( & V_49 -> V_56 ) ) {
V_49 = NULL ;
goto V_52;
}
F_31 ( & V_49 -> V_55 ) ;
V_49 -> V_57 = V_58 ;
V_52:
F_32 ( & V_7 -> V_40 -> V_41 , V_48 ) ;
return V_49 ;
}
static T_2 F_33 ( int V_36 , void * V_37 )
{
int V_59 ;
struct V_47 * V_60 ;
struct V_6 * V_7 = V_37 ;
struct V_61 * V_62 ;
V_60 = F_26 ( V_7 ) ;
if ( V_60 == NULL )
goto V_56;
V_59 = ( F_20 ( V_7 , V_42 ) & V_63 ) >> 3 ;
V_59 -= 1 ;
if ( V_59 < 0 )
V_59 = V_7 -> V_64 - 1 ;
V_62 = F_34 ( V_60 ) ;
F_35 ( V_7 -> V_65 [ V_59 ] , V_62 -> V_66 , V_62 -> V_67 ) ;
V_60 -> V_57 = V_68 ;
V_60 -> V_69 = V_7 -> V_70 . V_71 ;
F_36 ( & V_60 -> V_56 ) ;
V_56:
return V_72 ;
}
static void F_37 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_42 ,
V_73 | V_43 | V_44 | V_45 ) ;
F_38 ( V_74 ) ;
}
static void F_39 ( struct V_6 * V_7 )
{
F_40 ( V_74 ) ;
F_18 ( V_7 , V_42 , 0 ) ;
}
static int F_41 ( struct V_6 * V_7 )
{
int V_75 = V_7 -> V_40 -> V_76 / V_7 -> V_26 . V_71 ;
int V_3 ;
unsigned int V_77 ;
if ( V_75 >= 3 ) {
V_7 -> V_64 = 3 ;
F_22 ( V_7 , V_78 , V_79 ,
V_79 ) ;
} else if ( V_75 == 2 ) {
V_7 -> V_64 = 2 ;
F_22 ( V_7 , V_78 , 0 , V_79 ) ;
} else {
F_42 ( V_7 , L_7 ) ;
return - V_80 ;
}
V_77 = V_7 -> V_81 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_64 ; V_3 ++ ) {
V_7 -> V_65 [ V_3 ] = V_77 ;
V_7 -> V_82 [ V_3 ] = V_7 -> V_83 + V_77 ;
F_18 ( V_7 , V_84 + V_3 * 4 , V_77 & V_85 ) ;
V_77 += V_7 -> V_26 . V_71 ;
}
return 0 ;
}
static void F_43 ( struct V_6 * V_7 )
{
unsigned int V_86 ;
int V_87 ;
if ( V_7 -> V_70 . V_88 == V_89 )
V_86 = 0 ;
else {
V_87 = ( V_7 -> V_70 . V_88 * 2048 ) / V_89 ;
V_86 = V_90 | V_87 ;
}
if ( V_7 -> V_70 . V_91 < V_92 ) {
V_87 = ( 1024 * V_7 -> V_70 . V_91 ) / V_92 ;
V_86 |= V_93 | ( V_87 << 16 ) ;
}
F_18 ( V_7 , V_94 , V_86 ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
int V_95 ;
F_18 ( V_7 , V_78 , ~ ( V_96 | V_97 ) ) ;
F_18 ( V_7 , V_98 , 0x06200120 ) ;
F_18 ( V_7 , V_99 , 0x01de0000 ) ;
F_43 ( V_7 ) ;
F_18 ( V_7 , V_100 ,
( V_7 -> V_26 . V_91 << 16 ) |
( V_7 -> V_26 . V_101 >> 3 ) ) ;
F_18 ( V_7 , V_102 , 0 ) ;
F_18 ( V_7 , V_103 ,
V_7 -> V_70 . V_101 & V_104 ) ;
V_95 = V_97 |
0x08000000 |
V_105 |
V_106 |
V_107 |
V_108 ;
if ( V_7 -> V_64 == 3 )
V_95 |= V_79 ;
if ( V_7 -> V_70 . V_2 == V_109 )
V_95 |= V_110 ;
else
V_95 |= V_111 ;
F_18 ( V_7 , V_78 , V_95 ) ;
}
static int F_45 ( struct V_6 * V_7 )
{
int V_8 ;
unsigned long V_48 ;
F_27 ( & V_7 -> V_40 -> V_41 , V_48 ) ;
V_8 = F_41 ( V_7 ) ;
if ( ! V_8 )
F_44 ( V_7 ) ;
F_32 ( & V_7 -> V_40 -> V_41 , V_48 ) ;
F_46 ( V_112 , & V_7 -> V_48 ) ;
return V_8 ;
}
static void F_47 ( struct V_6 * V_7 )
{
F_48 ( & V_7 -> V_40 -> V_41 ) ;
V_7 -> V_113 = 0 ;
F_22 ( V_7 , V_78 , V_96 , V_96 ) ;
F_37 ( V_7 ) ;
( void ) F_20 ( V_7 , V_78 ) ;
V_7 -> V_50 = V_51 ;
F_49 ( & V_7 -> V_40 -> V_41 ) ;
}
static void F_50 ( struct V_6 * V_7 )
{
F_48 ( & V_7 -> V_40 -> V_41 ) ;
F_39 ( V_7 ) ;
F_22 ( V_7 , V_78 , 0 , V_96 ) ;
( void ) F_20 ( V_7 , V_78 ) ;
V_7 -> V_50 = V_114 ;
F_49 ( & V_7 -> V_40 -> V_41 ) ;
}
static int F_51 ( struct V_115 * V_116 ,
unsigned int * V_117 , unsigned int * V_69 )
{
struct V_6 * V_7 = V_116 -> V_118 ;
* V_69 = V_7 -> V_70 . V_71 ;
if ( * V_117 == 0 || * V_117 > 6 )
* V_117 = 6 ;
return 0 ;
}
static int F_52 ( struct V_115 * V_116 ,
struct V_47 * V_60 , enum V_119 V_120 )
{
struct V_6 * V_7 = V_116 -> V_118 ;
V_60 -> V_69 = V_7 -> V_70 . V_71 ;
V_60 -> V_88 = V_7 -> V_70 . V_88 ;
V_60 -> V_91 = V_7 -> V_70 . V_91 ;
V_60 -> V_120 = V_120 ;
if ( V_60 -> V_57 == V_121 ) {
int V_8 = F_53 ( V_116 , V_60 , NULL ) ;
if ( V_8 )
return V_8 ;
}
V_60 -> V_57 = V_122 ;
return 0 ;
}
static void F_54 ( struct V_115 * V_116 ,
struct V_47 * V_60 )
{
struct V_6 * V_7 = V_116 -> V_118 ;
V_60 -> V_57 = V_123 ;
F_55 ( & V_60 -> V_55 , & V_7 -> V_53 ) ;
}
static void F_56 ( struct V_115 * V_116 ,
struct V_47 * V_60 )
{
struct V_6 * V_7 = V_116 -> V_118 ;
F_57 ( & V_7 -> V_11 -> V_12 , F_34 ( V_60 ) ) ;
F_58 ( F_34 ( V_60 ) ) ;
V_60 -> V_57 = V_121 ;
}
static int F_59 ( struct V_124 * V_125 )
{
struct V_6 * V_7 = F_60 ( V_125 ) ;
V_125 -> V_126 = V_7 ;
F_61 ( & V_7 -> V_127 ) ;
if ( V_7 -> V_128 == 0 ) {
int V_8 = F_62 () ;
if ( V_8 ) {
F_63 ( & V_7 -> V_127 ) ;
return V_8 ;
}
F_8 ( V_7 ) ;
F_64 ( V_112 , & V_7 -> V_48 ) ;
F_65 ( & V_7 -> V_129 , & V_130 ,
& V_7 -> V_11 -> V_12 , & V_7 -> V_40 -> V_41 ,
V_131 , V_132 ,
sizeof( struct V_47 ) , V_7 , NULL ) ;
}
( V_7 -> V_128 ) ++ ;
F_63 ( & V_7 -> V_127 ) ;
return 0 ;
}
static int F_66 ( struct V_124 * V_125 )
{
struct V_6 * V_7 = F_60 ( V_125 ) ;
F_61 ( & V_7 -> V_127 ) ;
( V_7 -> V_128 ) -- ;
if ( V_125 == V_7 -> V_133 ) {
F_67 ( & V_7 -> V_129 ) ;
if ( V_7 -> V_50 != V_114 )
F_50 ( V_7 ) ;
V_7 -> V_133 = NULL ;
}
if ( V_7 -> V_128 == 0 ) {
F_68 ( & V_7 -> V_129 ) ;
F_11 ( V_7 ) ;
F_69 () ;
}
F_63 ( & V_7 -> V_127 ) ;
return 0 ;
}
static T_3 F_70 ( struct V_124 * V_125 , char T_4 * V_134 ,
T_5 V_135 , T_6 * V_136 )
{
struct V_6 * V_7 = F_60 ( V_125 ) ;
int V_8 ;
F_61 ( & V_7 -> V_127 ) ;
if ( V_7 -> V_133 && V_7 -> V_133 != V_125 ) {
V_8 = - V_137 ;
goto V_138;
}
V_7 -> V_133 = V_125 ;
if ( F_71 ( V_112 , & V_7 -> V_48 ) ) {
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_45 ( V_7 ) ;
if ( V_8 )
goto V_138;
}
F_72 ( & V_7 -> V_53 ) ;
F_47 ( V_7 ) ;
V_8 = F_73 ( & V_7 -> V_129 , V_134 , V_135 , V_136 , 0 ,
V_125 -> V_139 & V_140 ) ;
F_50 ( V_7 ) ;
V_138:
F_63 ( & V_7 -> V_127 ) ;
return V_8 ;
}
static unsigned int F_74 ( struct V_124 * V_125 , struct V_141 * V_142 )
{
struct V_6 * V_7 = F_60 ( V_125 ) ;
return F_75 ( V_125 , & V_7 -> V_129 , V_142 ) ;
}
static int F_76 ( struct V_124 * V_125 , struct V_143 * V_144 )
{
struct V_6 * V_7 = F_60 ( V_125 ) ;
return F_77 ( & V_7 -> V_129 , V_144 ) ;
}
static int F_78 ( struct V_124 * V_125 , void * V_145 ,
struct V_146 * V_147 )
{
if ( V_147 -> V_148 != 0 )
return - V_13 ;
V_147 -> type = V_149 ;
V_147 -> V_150 = V_151 ;
strcpy ( V_147 -> V_152 , L_8 ) ;
return 0 ;
}
static int F_79 ( struct V_124 * V_125 , void * V_145 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_80 ( struct V_124 * V_125 , void * V_145 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_13 ;
return 0 ;
}
static int F_81 ( struct V_124 * V_125 , void * V_145 , T_7 V_150 )
{
return 0 ;
}
static int F_82 ( struct V_124 * V_125 , void * V_145 , T_7 * V_150 )
{
* V_150 = V_153 ;
return 0 ;
}
static int F_83 ( struct V_124 * V_125 , void * V_145 ,
struct V_154 * V_155 )
{
if ( V_155 -> V_148 >= V_4 )
return - V_13 ;
F_84 ( V_155 -> V_156 , V_5 [ V_155 -> V_148 ] . V_157 ,
sizeof( V_155 -> V_156 ) ) ;
V_155 -> V_2 = V_5 [ V_155 -> V_148 ] . V_2 ;
return 0 ;
}
static void F_85 ( struct V_158 * V_159 ,
struct V_158 * V_160 )
{
* V_160 = * V_159 ;
if ( V_159 -> V_88 < V_161 || V_159 -> V_91 < V_162 ) {
V_159 -> V_88 = V_161 ;
V_159 -> V_91 = V_162 ;
}
if ( V_159 -> V_88 > V_89 || V_159 -> V_91 > V_92 ) {
V_159 -> V_88 = V_89 ;
V_159 -> V_91 = V_92 ;
}
V_160 -> V_88 = V_89 ;
V_160 -> V_91 = V_92 ;
}
static void F_86 ( struct V_158 * V_159 ,
struct V_158 * V_160 )
{
struct V_1 * V_163 = F_1 ( V_159 -> V_2 ) ;
V_160 -> V_101 = V_160 -> V_88 * V_163 -> V_164 ;
V_160 -> V_71 = V_160 -> V_91 * V_160 -> V_101 ;
V_159 -> V_2 = V_160 -> V_2 ;
V_159 -> V_120 = V_160 -> V_120 ;
V_159 -> V_101 = 2 * V_159 -> V_88 ;
V_159 -> V_71 = V_159 -> V_101 * V_159 -> V_91 ;
}
static int F_87 ( struct V_6 * V_7 ,
struct V_158 * V_165 , struct V_158 * V_166 )
{
int V_8 ;
struct V_167 V_168 ;
struct V_22 V_23 = {
. V_24 = V_169 ,
} ;
struct V_1 * V_163 = F_1 ( V_165 -> V_2 ) ;
V_165 -> V_2 = V_163 -> V_2 ;
F_85 ( V_165 , V_166 ) ;
F_16 ( & V_23 . V_23 , V_166 , V_163 -> V_27 ) ;
V_8 = F_17 ( V_7 , V_30 , V_31 , & V_168 , & V_23 ) ;
F_88 ( V_166 , & V_23 . V_23 ) ;
F_86 ( V_165 , V_166 ) ;
return V_8 ;
}
static int F_89 ( struct V_124 * V_125 , void * V_145 ,
struct V_170 * V_155 )
{
struct V_6 * V_7 = V_145 ;
struct V_170 V_171 ;
int V_8 ;
F_61 ( & V_7 -> V_127 ) ;
V_8 = F_87 ( V_7 , & V_155 -> V_155 . V_172 , & V_171 . V_155 . V_172 ) ;
F_63 ( & V_7 -> V_127 ) ;
return V_8 ;
}
static int F_90 ( struct V_124 * V_125 , void * V_145 ,
struct V_170 * V_155 )
{
struct V_6 * V_7 = V_145 ;
F_61 ( & V_7 -> V_127 ) ;
V_155 -> V_155 . V_172 = V_7 -> V_70 ;
F_63 ( & V_7 -> V_127 ) ;
return 0 ;
}
static int F_91 ( struct V_124 * V_125 , void * V_145 ,
struct V_170 * V_155 )
{
struct V_6 * V_7 = V_145 ;
int V_8 ;
struct V_170 V_171 ;
struct V_1 * V_163 = F_1 ( V_155 -> V_155 . V_172 . V_2 ) ;
F_61 ( & V_7 -> V_127 ) ;
if ( V_7 -> V_50 != V_114 ) {
V_8 = - V_137 ;
goto V_52;
}
V_8 = F_87 ( V_7 , & V_155 -> V_155 . V_172 , & V_171 . V_155 . V_172 ) ;
if ( V_8 )
goto V_52;
V_7 -> V_70 = V_155 -> V_155 . V_172 ;
V_7 -> V_26 = V_171 . V_155 . V_172 ;
V_7 -> V_27 = V_163 -> V_27 ;
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_45 ( V_7 ) ;
V_52:
F_63 ( & V_7 -> V_127 ) ;
return V_8 ;
}
static int F_92 ( struct V_124 * V_125 , void * V_145 ,
struct V_173 * V_174 )
{
strcpy ( V_174 -> V_175 , L_9 ) ;
strcpy ( V_174 -> V_176 , L_9 ) ;
V_174 -> V_177 = V_178 |
V_179 | V_180 ;
V_174 -> V_181 = V_174 -> V_177 | V_182 ;
return 0 ;
}
static int F_93 ( struct V_124 * V_125 , void * V_145 ,
struct V_183 * V_184 )
{
struct V_6 * V_7 = V_145 ;
return F_94 ( & V_7 -> V_129 , V_184 ) ;
}
static int F_95 ( struct V_124 * V_125 , void * V_145 ,
struct V_185 * V_49 )
{
struct V_6 * V_7 = V_145 ;
return F_96 ( & V_7 -> V_129 , V_49 ) ;
}
static int F_97 ( struct V_124 * V_125 , void * V_145 , struct V_185 * V_49 )
{
struct V_6 * V_7 = V_145 ;
return F_98 ( & V_7 -> V_129 , V_49 ) ;
}
static int F_99 ( struct V_124 * V_125 , void * V_145 , struct V_185 * V_49 )
{
struct V_6 * V_7 = V_145 ;
return F_100 ( & V_7 -> V_129 , V_49 , V_125 -> V_139 & V_140 ) ;
}
static int F_101 ( struct V_124 * V_125 , void * V_145 , enum V_186 V_187 )
{
struct V_6 * V_7 = V_145 ;
int V_8 = 0 ;
if ( V_187 != V_131 )
return - V_13 ;
F_61 ( & V_7 -> V_127 ) ;
if ( V_7 -> V_50 != V_114 ) {
V_8 = - V_137 ;
goto V_52;
}
if ( V_7 -> V_133 && V_7 -> V_133 != V_125 ) {
V_8 = - V_137 ;
goto V_52;
}
V_7 -> V_133 = V_125 ;
if ( F_71 ( V_112 , & V_7 -> V_48 ) ) {
V_8 = F_15 ( V_7 ) ;
if ( V_8 )
goto V_52;
V_8 = F_45 ( V_7 ) ;
if ( V_8 )
goto V_52;
}
F_102 ( & V_7 -> V_188 , V_189 , 50 ) ;
F_72 ( & V_7 -> V_53 ) ;
V_8 = F_103 ( & V_7 -> V_129 ) ;
if ( ! V_8 )
F_47 ( V_7 ) ;
V_52:
F_63 ( & V_7 -> V_127 ) ;
return V_8 ;
}
static int F_104 ( struct V_124 * V_125 , void * V_145 , enum V_186 V_187 )
{
struct V_6 * V_7 = V_145 ;
int V_8 ;
if ( V_187 != V_131 )
return - V_13 ;
F_61 ( & V_7 -> V_127 ) ;
if ( V_7 -> V_50 != V_51 ) {
V_8 = - V_13 ;
goto V_52;
}
F_105 ( & V_7 -> V_188 ) ;
F_50 ( V_7 ) ;
V_8 = F_106 ( & V_7 -> V_129 ) ;
F_72 ( & V_7 -> V_53 ) ;
V_52:
F_63 ( & V_7 -> V_127 ) ;
return V_8 ;
}
static int F_107 ( struct V_124 * V_125 , void * V_145 ,
struct V_190 * V_191 )
{
struct V_6 * V_7 = V_145 ;
int V_8 ;
F_61 ( & V_7 -> V_127 ) ;
V_8 = F_17 ( V_7 , V_192 , V_193 , V_191 ) ;
F_63 ( & V_7 -> V_127 ) ;
V_191 -> V_191 . V_194 . V_195 = V_7 -> V_64 ;
return V_8 ;
}
static int F_108 ( struct V_124 * V_125 , void * V_145 ,
struct V_190 * V_191 )
{
struct V_6 * V_7 = V_145 ;
int V_8 ;
F_61 ( & V_7 -> V_127 ) ;
V_8 = F_17 ( V_7 , V_192 , V_196 , V_191 ) ;
F_63 ( & V_7 -> V_127 ) ;
V_191 -> V_191 . V_194 . V_195 = V_7 -> V_64 ;
return V_8 ;
}
static int F_109 ( struct V_124 * V_125 , void * V_145 ,
struct V_197 * V_198 )
{
if ( V_198 -> V_148 != 0 )
return - V_13 ;
V_198 -> type = V_199 ;
V_198 -> V_200 . V_201 = V_161 ;
V_198 -> V_200 . V_202 = V_162 ;
V_198 -> V_200 . V_203 = V_89 ;
V_198 -> V_200 . V_204 = V_92 ;
V_198 -> V_200 . V_205 = V_198 -> V_200 . V_206 = 1 ;
return 0 ;
}
static int F_110 ( struct V_124 * V_125 , void * V_145 ,
struct V_207 * V_208 )
{
struct V_6 * V_7 = V_145 ;
struct V_209 V_210 = {
. V_148 = V_208 -> V_148 ,
. V_211 = V_7 -> V_27 ,
. V_88 = V_7 -> V_26 . V_88 ,
. V_91 = V_7 -> V_26 . V_91 ,
. V_24 = V_25 ,
} ;
int V_8 ;
F_61 ( & V_7 -> V_127 ) ;
V_8 = F_17 ( V_7 , V_30 , V_212 , NULL , & V_210 ) ;
F_63 ( & V_7 -> V_127 ) ;
if ( V_8 )
return V_8 ;
V_208 -> type = V_213 ;
V_208 -> V_214 = V_210 . V_208 ;
return 0 ;
}
static int F_111 ( void * V_145 )
{
struct V_6 * V_7 = V_145 ;
enum V_215 V_57 = V_7 -> V_50 ;
if ( V_7 -> V_50 != V_114 ) {
F_50 ( V_7 ) ;
V_7 -> V_50 = V_57 ;
}
return 0 ;
}
static int F_112 ( void * V_145 )
{
struct V_6 * V_7 = V_145 ;
int V_8 = 0 ;
F_113 ( V_216 , 0x78 , 0 , 0x80 ) ;
F_113 ( V_216 , 0x1e , 0xc0 , 0xc0 ) ;
F_39 ( V_7 ) ;
F_64 ( V_112 , & V_7 -> V_48 ) ;
if ( V_7 -> V_128 > 0 )
F_8 ( V_7 ) ;
else
F_11 ( V_7 ) ;
if ( V_7 -> V_50 != V_114 ) {
F_61 ( & V_7 -> V_127 ) ;
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_45 ( V_7 ) ;
F_63 ( & V_7 -> V_127 ) ;
if ( ! V_8 )
F_47 ( V_7 ) ;
}
return V_8 ;
}
static bool F_114 ( void )
{
struct V_217 * V_218 = F_115 ( 0 , 0 ) ;
T_8 V_219 ;
if ( ! V_218 )
return false ;
F_116 ( V_218 , V_220 ,
V_221 , & V_219 ) ;
if ( ( V_219 & V_222 ) == 0 )
return false ;
if ( ! V_223 ) {
F_117 ( V_224 L_10 \
L_11 ) ;
F_117 ( V_224 L_12 \
L_13 ) ;
return true ;
}
F_117 ( V_224 L_14 ) ;
F_118 ( V_218 , V_220 ,
V_221 , V_219 & ~ V_222 ) ;
return false ;
}
static int F_119 ( struct V_225 * V_226 )
{
int V_8 ;
struct V_227 * V_228 ;
struct V_229 * V_40 = V_226 -> V_12 . V_230 ;
struct V_231 V_232 = {
. type = L_15 ,
. V_233 = 0x42 >> 1 ,
. V_230 = & V_234 ,
} ;
struct V_6 * V_7 ;
if ( V_40 -> V_76 < ( V_92 * V_89 * 4 ) ) {
F_117 ( V_235 L_16 ) ;
return - V_80 ;
}
if ( V_40 -> V_236 == NULL ) {
F_117 ( V_235 L_17 ) ;
return - V_80 ;
}
if ( F_120 () && F_114 () )
return - V_137 ;
V_7 = F_121 ( sizeof( struct V_6 ) , V_237 ) ;
if ( V_7 == NULL )
return - V_80 ;
V_238 = V_7 ;
V_7 -> V_11 = V_226 ;
V_7 -> V_40 = V_40 ;
V_7 -> V_128 = 0 ;
V_7 -> V_133 = NULL ;
V_7 -> V_50 = V_114 ;
V_7 -> V_70 = V_7 -> V_26 = V_239 ;
F_122 ( & V_7 -> V_127 ) ;
F_72 ( & V_7 -> V_53 ) ;
V_7 -> V_33 = V_40 -> V_236 ;
V_7 -> V_83 = V_40 -> V_83 ;
V_7 -> V_81 = V_40 -> V_240 ;
V_7 -> V_48 = 1 << V_112 ;
V_7 -> V_27 = V_241 ;
V_8 = F_123 ( & V_226 -> V_12 , & V_7 -> V_242 ) ;
if ( V_8 ) {
F_4 ( & V_226 -> V_12 , L_18 ) ;
goto V_243;
}
V_8 = F_124 ( & V_7 -> V_21 , 10 ) ;
if ( V_8 )
goto V_244;
V_7 -> V_242 . V_21 = & V_7 -> V_21 ;
V_226 -> V_12 . V_245 = & V_40 -> V_226 -> V_245 ;
F_125 ( & V_226 -> V_12 , 0xffffffff ) ;
F_113 ( V_216 , 0x78 , 0 , 0x80 ) ;
F_113 ( V_216 , 0x1e , 0xc0 , 0xc0 ) ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 )
goto V_246;
F_8 ( V_7 ) ;
V_228 = F_126 ( V_247 ) ;
V_7 -> V_20 = F_127 ( & V_7 -> V_242 , V_228 ,
& V_232 , NULL ) ;
if ( V_7 -> V_20 == NULL ) {
F_4 ( & V_226 -> V_12 , L_19 ) ;
V_8 = - V_248 ;
goto V_249;
}
F_39 ( V_7 ) ;
V_8 = F_128 ( V_40 -> V_226 -> V_36 , F_23 ,
F_33 , V_250 , L_9 , V_7 ) ;
if ( V_8 )
goto V_249;
V_7 -> V_251 = V_252 ;
V_7 -> V_251 . V_242 = & V_7 -> V_242 ;
V_8 = F_129 ( & V_7 -> V_251 , V_253 , - 1 ) ;
if ( V_8 )
goto V_254;
F_130 ( & V_7 -> V_251 , V_7 ) ;
#ifdef F_131
V_255 . V_256 = V_7 ;
F_132 ( & V_255 ) ;
#endif
F_11 ( V_7 ) ;
return 0 ;
V_254:
F_133 ( V_40 -> V_226 -> V_36 , V_7 ) ;
V_249:
F_12 ( V_7 ) ;
V_246:
F_134 ( & V_7 -> V_21 ) ;
V_244:
F_135 ( & V_7 -> V_242 ) ;
V_243:
F_136 ( V_7 ) ;
return V_8 ;
}
static int F_137 ( struct V_225 * V_226 )
{
struct V_6 * V_7 = V_238 ;
struct V_229 * V_40 = V_226 -> V_12 . V_230 ;
F_138 ( & V_7 -> V_251 ) ;
F_135 ( & V_7 -> V_242 ) ;
F_133 ( V_40 -> V_226 -> V_36 , V_7 ) ;
F_12 ( V_7 ) ;
F_134 ( & V_7 -> V_21 ) ;
F_136 ( V_7 ) ;
V_238 = NULL ;
return 0 ;
}
