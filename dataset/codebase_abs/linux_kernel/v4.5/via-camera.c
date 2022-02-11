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
return F_14 ( V_7 , V_20 , V_21 , & V_15 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_22 V_23 = {
. V_24 = V_25 ,
} ;
int V_8 ;
F_16 ( & V_23 . V_23 , & V_7 -> V_26 , V_7 -> V_27 ) ;
V_8 = F_14 ( V_7 , V_20 , V_28 , 0 ) ;
if ( V_8 == 0 )
V_8 = F_14 ( V_7 , V_29 , V_30 , NULL , & V_23 ) ;
if ( V_8 == 0 )
V_8 = F_13 ( V_7 ) ;
return V_8 ;
}
static inline void F_17 ( struct V_6 * V_7 ,
int V_31 , int V_18 )
{
F_18 ( V_18 , V_7 -> V_32 + V_31 ) ;
}
static inline int F_19 ( struct V_6 * V_7 , int V_31 )
{
return F_20 ( V_7 -> V_32 + V_31 ) ;
}
static inline void F_21 ( struct V_6 * V_7 ,
int V_31 , int V_18 , int V_33 )
{
int V_34 = F_19 ( V_7 , V_31 ) ;
V_34 = ( V_34 & ~ V_33 ) | ( V_18 & V_33 ) ;
F_17 ( V_7 , V_31 , V_34 ) ;
}
static T_2 F_22 ( int V_35 , void * V_36 )
{
struct V_6 * V_7 = V_36 ;
T_2 V_8 = V_37 ;
int V_38 ;
F_23 ( & V_7 -> V_39 -> V_40 ) ;
V_38 = F_19 ( V_7 , V_41 ) ;
if ( V_38 & V_42 ) {
V_38 |= V_42 | V_43 | V_44 ;
F_17 ( V_7 , V_41 , V_38 ) ;
V_8 = V_45 ;
}
F_24 ( & V_7 -> V_39 -> V_40 ) ;
return V_8 ;
}
static struct V_46 * F_25 ( struct V_6 * V_7 )
{
unsigned long V_47 ;
struct V_46 * V_48 = NULL ;
F_26 ( & V_7 -> V_39 -> V_40 , V_47 ) ;
if ( V_7 -> V_49 != V_50 )
goto V_51;
if ( F_27 ( & V_7 -> V_52 ) )
goto V_51;
V_48 = F_28 ( V_7 -> V_52 . V_53 , struct V_46 , V_54 ) ;
if ( ! F_29 ( & V_48 -> V_55 ) ) {
V_48 = NULL ;
goto V_51;
}
F_30 ( & V_48 -> V_54 ) ;
V_48 -> V_56 = V_57 ;
V_51:
F_31 ( & V_7 -> V_39 -> V_40 , V_47 ) ;
return V_48 ;
}
static T_2 F_32 ( int V_35 , void * V_36 )
{
int V_58 ;
struct V_46 * V_59 ;
struct V_6 * V_7 = V_36 ;
struct V_60 * V_61 ;
V_59 = F_25 ( V_7 ) ;
if ( V_59 == NULL )
goto V_55;
V_58 = ( F_19 ( V_7 , V_41 ) & V_62 ) >> 3 ;
V_58 -= 1 ;
if ( V_58 < 0 )
V_58 = V_7 -> V_63 - 1 ;
V_61 = F_33 ( V_59 ) ;
F_34 ( V_7 -> V_64 [ V_58 ] , V_61 -> V_65 , V_61 -> V_66 ) ;
V_59 -> V_56 = V_67 ;
V_59 -> V_68 = V_7 -> V_69 . V_70 ;
F_35 ( & V_59 -> V_55 ) ;
V_55:
return V_71 ;
}
static void F_36 ( struct V_6 * V_7 )
{
F_17 ( V_7 , V_41 ,
V_72 | V_42 | V_43 | V_44 ) ;
F_37 ( V_73 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
F_39 ( V_73 ) ;
F_17 ( V_7 , V_41 , 0 ) ;
}
static int F_40 ( struct V_6 * V_7 )
{
int V_74 = V_7 -> V_39 -> V_75 / V_7 -> V_26 . V_70 ;
int V_3 ;
unsigned int V_76 ;
if ( V_74 >= 3 ) {
V_7 -> V_63 = 3 ;
F_21 ( V_7 , V_77 , V_78 ,
V_78 ) ;
} else if ( V_74 == 2 ) {
V_7 -> V_63 = 2 ;
F_21 ( V_7 , V_77 , 0 , V_78 ) ;
} else {
F_41 ( V_7 , L_7 ) ;
return - V_79 ;
}
V_76 = V_7 -> V_80 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_63 ; V_3 ++ ) {
V_7 -> V_64 [ V_3 ] = V_76 ;
V_7 -> V_81 [ V_3 ] = V_7 -> V_82 + V_76 ;
F_17 ( V_7 , V_83 + V_3 * 4 , V_76 & V_84 ) ;
V_76 += V_7 -> V_26 . V_70 ;
}
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
unsigned int V_85 ;
int V_86 ;
if ( V_7 -> V_69 . V_87 == V_88 )
V_85 = 0 ;
else {
V_86 = ( V_7 -> V_69 . V_87 * 2048 ) / V_88 ;
V_85 = V_89 | V_86 ;
}
if ( V_7 -> V_69 . V_90 < V_91 ) {
V_86 = ( 1024 * V_7 -> V_69 . V_90 ) / V_91 ;
V_85 |= V_92 | ( V_86 << 16 ) ;
}
F_17 ( V_7 , V_93 , V_85 ) ;
}
static void F_43 ( struct V_6 * V_7 )
{
int V_94 ;
F_17 ( V_7 , V_77 , ~ ( V_95 | V_96 ) ) ;
F_17 ( V_7 , V_97 , 0x06200120 ) ;
F_17 ( V_7 , V_98 , 0x01de0000 ) ;
F_42 ( V_7 ) ;
F_17 ( V_7 , V_99 ,
( V_7 -> V_26 . V_90 << 16 ) |
( V_7 -> V_26 . V_100 >> 3 ) ) ;
F_17 ( V_7 , V_101 , 0 ) ;
F_17 ( V_7 , V_102 ,
V_7 -> V_69 . V_100 & V_103 ) ;
V_94 = V_96 |
0x08000000 |
V_104 |
V_105 |
V_106 |
V_107 ;
if ( V_7 -> V_63 == 3 )
V_94 |= V_78 ;
if ( V_7 -> V_69 . V_2 == V_108 )
V_94 |= V_109 ;
else
V_94 |= V_110 ;
F_17 ( V_7 , V_77 , V_94 ) ;
}
static int F_44 ( struct V_6 * V_7 )
{
int V_8 ;
unsigned long V_47 ;
F_26 ( & V_7 -> V_39 -> V_40 , V_47 ) ;
V_8 = F_40 ( V_7 ) ;
if ( ! V_8 )
F_43 ( V_7 ) ;
F_31 ( & V_7 -> V_39 -> V_40 , V_47 ) ;
F_45 ( V_111 , & V_7 -> V_47 ) ;
return V_8 ;
}
static void F_46 ( struct V_6 * V_7 )
{
F_47 ( & V_7 -> V_39 -> V_40 ) ;
V_7 -> V_112 = 0 ;
F_21 ( V_7 , V_77 , V_95 , V_95 ) ;
F_36 ( V_7 ) ;
( void ) F_19 ( V_7 , V_77 ) ;
V_7 -> V_49 = V_50 ;
F_48 ( & V_7 -> V_39 -> V_40 ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
F_47 ( & V_7 -> V_39 -> V_40 ) ;
F_38 ( V_7 ) ;
F_21 ( V_7 , V_77 , 0 , V_95 ) ;
( void ) F_19 ( V_7 , V_77 ) ;
V_7 -> V_49 = V_113 ;
F_48 ( & V_7 -> V_39 -> V_40 ) ;
}
static int F_50 ( struct V_114 * V_115 ,
unsigned int * V_116 , unsigned int * V_68 )
{
struct V_6 * V_7 = V_115 -> V_117 ;
* V_68 = V_7 -> V_69 . V_70 ;
if ( * V_116 == 0 || * V_116 > 6 )
* V_116 = 6 ;
return 0 ;
}
static int F_51 ( struct V_114 * V_115 ,
struct V_46 * V_59 , enum V_118 V_119 )
{
struct V_6 * V_7 = V_115 -> V_117 ;
V_59 -> V_68 = V_7 -> V_69 . V_70 ;
V_59 -> V_87 = V_7 -> V_69 . V_87 ;
V_59 -> V_90 = V_7 -> V_69 . V_90 ;
V_59 -> V_119 = V_119 ;
if ( V_59 -> V_56 == V_120 ) {
int V_8 = F_52 ( V_115 , V_59 , NULL ) ;
if ( V_8 )
return V_8 ;
}
V_59 -> V_56 = V_121 ;
return 0 ;
}
static void F_53 ( struct V_114 * V_115 ,
struct V_46 * V_59 )
{
struct V_6 * V_7 = V_115 -> V_117 ;
V_59 -> V_56 = V_122 ;
F_54 ( & V_59 -> V_54 , & V_7 -> V_52 ) ;
}
static void F_55 ( struct V_114 * V_115 ,
struct V_46 * V_59 )
{
struct V_6 * V_7 = V_115 -> V_117 ;
F_56 ( & V_7 -> V_11 -> V_12 , F_33 ( V_59 ) ) ;
F_57 ( F_33 ( V_59 ) ) ;
V_59 -> V_56 = V_120 ;
}
static int F_58 ( struct V_123 * V_124 )
{
struct V_6 * V_7 = F_59 ( V_124 ) ;
V_124 -> V_125 = V_7 ;
F_60 ( & V_7 -> V_126 ) ;
if ( V_7 -> V_127 == 0 ) {
int V_8 = F_61 () ;
if ( V_8 ) {
F_62 ( & V_7 -> V_126 ) ;
return V_8 ;
}
F_8 ( V_7 ) ;
F_63 ( V_111 , & V_7 -> V_47 ) ;
F_64 ( & V_7 -> V_128 , & V_129 ,
& V_7 -> V_11 -> V_12 , & V_7 -> V_39 -> V_40 ,
V_130 , V_131 ,
sizeof( struct V_46 ) , V_7 , NULL ) ;
}
( V_7 -> V_127 ) ++ ;
F_62 ( & V_7 -> V_126 ) ;
return 0 ;
}
static int F_65 ( struct V_123 * V_124 )
{
struct V_6 * V_7 = F_59 ( V_124 ) ;
F_60 ( & V_7 -> V_126 ) ;
( V_7 -> V_127 ) -- ;
if ( V_124 == V_7 -> V_132 ) {
F_66 ( & V_7 -> V_128 ) ;
if ( V_7 -> V_49 != V_113 )
F_49 ( V_7 ) ;
V_7 -> V_132 = NULL ;
}
if ( V_7 -> V_127 == 0 ) {
F_67 ( & V_7 -> V_128 ) ;
F_11 ( V_7 ) ;
F_68 () ;
}
F_62 ( & V_7 -> V_126 ) ;
return 0 ;
}
static T_3 F_69 ( struct V_123 * V_124 , char T_4 * V_133 ,
T_5 V_134 , T_6 * V_135 )
{
struct V_6 * V_7 = F_59 ( V_124 ) ;
int V_8 ;
F_60 ( & V_7 -> V_126 ) ;
if ( V_7 -> V_132 && V_7 -> V_132 != V_124 ) {
V_8 = - V_136 ;
goto V_137;
}
V_7 -> V_132 = V_124 ;
if ( F_70 ( V_111 , & V_7 -> V_47 ) ) {
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_44 ( V_7 ) ;
if ( V_8 )
goto V_137;
}
F_71 ( & V_7 -> V_52 ) ;
F_46 ( V_7 ) ;
V_8 = F_72 ( & V_7 -> V_128 , V_133 , V_134 , V_135 , 0 ,
V_124 -> V_138 & V_139 ) ;
F_49 ( V_7 ) ;
V_137:
F_62 ( & V_7 -> V_126 ) ;
return V_8 ;
}
static unsigned int F_73 ( struct V_123 * V_124 , struct V_140 * V_141 )
{
struct V_6 * V_7 = F_59 ( V_124 ) ;
return F_74 ( V_124 , & V_7 -> V_128 , V_141 ) ;
}
static int F_75 ( struct V_123 * V_124 , struct V_142 * V_143 )
{
struct V_6 * V_7 = F_59 ( V_124 ) ;
return F_76 ( & V_7 -> V_128 , V_143 ) ;
}
static int F_77 ( struct V_123 * V_124 , void * V_144 ,
struct V_145 * V_146 )
{
if ( V_146 -> V_147 != 0 )
return - V_13 ;
V_146 -> type = V_148 ;
V_146 -> V_149 = V_150 ;
strcpy ( V_146 -> V_151 , L_8 ) ;
return 0 ;
}
static int F_78 ( struct V_123 * V_124 , void * V_144 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_79 ( struct V_123 * V_124 , void * V_144 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_13 ;
return 0 ;
}
static int F_80 ( struct V_123 * V_124 , void * V_144 , T_7 V_149 )
{
return 0 ;
}
static int F_81 ( struct V_123 * V_124 , void * V_144 , T_7 * V_149 )
{
* V_149 = V_152 ;
return 0 ;
}
static int F_82 ( struct V_123 * V_124 , void * V_144 ,
struct V_153 * V_154 )
{
if ( V_154 -> V_147 >= V_4 )
return - V_13 ;
F_83 ( V_154 -> V_155 , V_5 [ V_154 -> V_147 ] . V_156 ,
sizeof( V_154 -> V_155 ) ) ;
V_154 -> V_2 = V_5 [ V_154 -> V_147 ] . V_2 ;
return 0 ;
}
static void F_84 ( struct V_157 * V_158 ,
struct V_157 * V_159 )
{
* V_159 = * V_158 ;
if ( V_158 -> V_87 < V_160 || V_158 -> V_90 < V_161 ) {
V_158 -> V_87 = V_160 ;
V_158 -> V_90 = V_161 ;
}
if ( V_158 -> V_87 > V_88 || V_158 -> V_90 > V_91 ) {
V_158 -> V_87 = V_88 ;
V_158 -> V_90 = V_91 ;
}
V_159 -> V_87 = V_88 ;
V_159 -> V_90 = V_91 ;
}
static void F_85 ( struct V_157 * V_158 ,
struct V_157 * V_159 )
{
struct V_1 * V_162 = F_1 ( V_158 -> V_2 ) ;
V_159 -> V_100 = V_159 -> V_87 * V_162 -> V_163 ;
V_159 -> V_70 = V_159 -> V_90 * V_159 -> V_100 ;
V_158 -> V_2 = V_159 -> V_2 ;
V_158 -> V_119 = V_159 -> V_119 ;
V_158 -> V_100 = 2 * V_158 -> V_87 ;
V_158 -> V_70 = V_158 -> V_100 * V_158 -> V_90 ;
}
static int F_86 ( struct V_6 * V_7 ,
struct V_157 * V_164 , struct V_157 * V_165 )
{
int V_8 ;
struct V_166 V_167 ;
struct V_22 V_23 = {
. V_24 = V_168 ,
} ;
struct V_1 * V_162 = F_1 ( V_164 -> V_2 ) ;
V_164 -> V_2 = V_162 -> V_2 ;
F_84 ( V_164 , V_165 ) ;
F_16 ( & V_23 . V_23 , V_165 , V_162 -> V_27 ) ;
V_8 = F_14 ( V_7 , V_29 , V_30 , & V_167 , & V_23 ) ;
F_87 ( V_165 , & V_23 . V_23 ) ;
F_85 ( V_164 , V_165 ) ;
return V_8 ;
}
static int F_88 ( struct V_123 * V_124 , void * V_144 ,
struct V_169 * V_154 )
{
struct V_6 * V_7 = V_144 ;
struct V_169 V_170 ;
int V_8 ;
F_60 ( & V_7 -> V_126 ) ;
V_8 = F_86 ( V_7 , & V_154 -> V_154 . V_171 , & V_170 . V_154 . V_171 ) ;
F_62 ( & V_7 -> V_126 ) ;
return V_8 ;
}
static int F_89 ( struct V_123 * V_124 , void * V_144 ,
struct V_169 * V_154 )
{
struct V_6 * V_7 = V_144 ;
F_60 ( & V_7 -> V_126 ) ;
V_154 -> V_154 . V_171 = V_7 -> V_69 ;
F_62 ( & V_7 -> V_126 ) ;
return 0 ;
}
static int F_90 ( struct V_123 * V_124 , void * V_144 ,
struct V_169 * V_154 )
{
struct V_6 * V_7 = V_144 ;
int V_8 ;
struct V_169 V_170 ;
struct V_1 * V_162 = F_1 ( V_154 -> V_154 . V_171 . V_2 ) ;
F_60 ( & V_7 -> V_126 ) ;
if ( V_7 -> V_49 != V_113 ) {
V_8 = - V_136 ;
goto V_51;
}
V_8 = F_86 ( V_7 , & V_154 -> V_154 . V_171 , & V_170 . V_154 . V_171 ) ;
if ( V_8 )
goto V_51;
V_7 -> V_69 = V_154 -> V_154 . V_171 ;
V_7 -> V_26 = V_170 . V_154 . V_171 ;
V_7 -> V_27 = V_162 -> V_27 ;
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_44 ( V_7 ) ;
V_51:
F_62 ( & V_7 -> V_126 ) ;
return V_8 ;
}
static int F_91 ( struct V_123 * V_124 , void * V_144 ,
struct V_172 * V_173 )
{
strcpy ( V_173 -> V_174 , L_9 ) ;
strcpy ( V_173 -> V_175 , L_9 ) ;
V_173 -> V_176 = V_177 |
V_178 | V_179 ;
V_173 -> V_180 = V_173 -> V_176 | V_181 ;
return 0 ;
}
static int F_92 ( struct V_123 * V_124 , void * V_144 ,
struct V_182 * V_183 )
{
struct V_6 * V_7 = V_144 ;
return F_93 ( & V_7 -> V_128 , V_183 ) ;
}
static int F_94 ( struct V_123 * V_124 , void * V_144 ,
struct V_184 * V_48 )
{
struct V_6 * V_7 = V_144 ;
return F_95 ( & V_7 -> V_128 , V_48 ) ;
}
static int F_96 ( struct V_123 * V_124 , void * V_144 , struct V_184 * V_48 )
{
struct V_6 * V_7 = V_144 ;
return F_97 ( & V_7 -> V_128 , V_48 ) ;
}
static int F_98 ( struct V_123 * V_124 , void * V_144 , struct V_184 * V_48 )
{
struct V_6 * V_7 = V_144 ;
return F_99 ( & V_7 -> V_128 , V_48 , V_124 -> V_138 & V_139 ) ;
}
static int F_100 ( struct V_123 * V_124 , void * V_144 , enum V_185 V_186 )
{
struct V_6 * V_7 = V_144 ;
int V_8 = 0 ;
if ( V_186 != V_130 )
return - V_13 ;
F_60 ( & V_7 -> V_126 ) ;
if ( V_7 -> V_49 != V_113 ) {
V_8 = - V_136 ;
goto V_51;
}
if ( V_7 -> V_132 && V_7 -> V_132 != V_124 ) {
V_8 = - V_136 ;
goto V_51;
}
V_7 -> V_132 = V_124 ;
if ( F_70 ( V_111 , & V_7 -> V_47 ) ) {
V_8 = F_15 ( V_7 ) ;
if ( V_8 )
goto V_51;
V_8 = F_44 ( V_7 ) ;
if ( V_8 )
goto V_51;
}
F_101 ( & V_7 -> V_187 , V_188 , 50 ) ;
F_71 ( & V_7 -> V_52 ) ;
V_8 = F_102 ( & V_7 -> V_128 ) ;
if ( ! V_8 )
F_46 ( V_7 ) ;
V_51:
F_62 ( & V_7 -> V_126 ) ;
return V_8 ;
}
static int F_103 ( struct V_123 * V_124 , void * V_144 , enum V_185 V_186 )
{
struct V_6 * V_7 = V_144 ;
int V_8 ;
if ( V_186 != V_130 )
return - V_13 ;
F_60 ( & V_7 -> V_126 ) ;
if ( V_7 -> V_49 != V_50 ) {
V_8 = - V_13 ;
goto V_51;
}
F_104 ( & V_7 -> V_187 ) ;
F_49 ( V_7 ) ;
V_8 = F_105 ( & V_7 -> V_128 ) ;
F_71 ( & V_7 -> V_52 ) ;
V_51:
F_62 ( & V_7 -> V_126 ) ;
return V_8 ;
}
static int F_106 ( struct V_123 * V_124 , void * V_144 ,
struct V_189 * V_190 )
{
struct V_6 * V_7 = V_144 ;
int V_8 ;
F_60 ( & V_7 -> V_126 ) ;
V_8 = F_14 ( V_7 , V_191 , V_192 , V_190 ) ;
F_62 ( & V_7 -> V_126 ) ;
V_190 -> V_190 . V_193 . V_194 = V_7 -> V_63 ;
return V_8 ;
}
static int F_107 ( struct V_123 * V_124 , void * V_144 ,
struct V_189 * V_190 )
{
struct V_6 * V_7 = V_144 ;
int V_8 ;
F_60 ( & V_7 -> V_126 ) ;
V_8 = F_14 ( V_7 , V_191 , V_195 , V_190 ) ;
F_62 ( & V_7 -> V_126 ) ;
V_190 -> V_190 . V_193 . V_194 = V_7 -> V_63 ;
return V_8 ;
}
static int F_108 ( struct V_123 * V_124 , void * V_144 ,
struct V_196 * V_197 )
{
if ( V_197 -> V_147 != 0 )
return - V_13 ;
V_197 -> type = V_198 ;
V_197 -> V_199 . V_200 = V_160 ;
V_197 -> V_199 . V_201 = V_161 ;
V_197 -> V_199 . V_202 = V_88 ;
V_197 -> V_199 . V_203 = V_91 ;
V_197 -> V_199 . V_204 = V_197 -> V_199 . V_205 = 1 ;
return 0 ;
}
static int F_109 ( struct V_123 * V_124 , void * V_144 ,
struct V_206 * V_207 )
{
struct V_6 * V_7 = V_144 ;
struct V_208 V_209 = {
. V_147 = V_207 -> V_147 ,
. V_210 = V_7 -> V_27 ,
. V_87 = V_7 -> V_26 . V_87 ,
. V_90 = V_7 -> V_26 . V_90 ,
. V_24 = V_25 ,
} ;
int V_8 ;
F_60 ( & V_7 -> V_126 ) ;
V_8 = F_14 ( V_7 , V_29 , V_211 , NULL , & V_209 ) ;
F_62 ( & V_7 -> V_126 ) ;
if ( V_8 )
return V_8 ;
V_207 -> type = V_212 ;
V_207 -> V_213 = V_209 . V_207 ;
return 0 ;
}
static int F_110 ( void * V_144 )
{
struct V_6 * V_7 = V_144 ;
enum V_214 V_56 = V_7 -> V_49 ;
if ( V_7 -> V_49 != V_113 ) {
F_49 ( V_7 ) ;
V_7 -> V_49 = V_56 ;
}
return 0 ;
}
static int F_111 ( void * V_144 )
{
struct V_6 * V_7 = V_144 ;
int V_8 = 0 ;
F_112 ( V_215 , 0x78 , 0 , 0x80 ) ;
F_112 ( V_215 , 0x1e , 0xc0 , 0xc0 ) ;
F_38 ( V_7 ) ;
F_63 ( V_111 , & V_7 -> V_47 ) ;
if ( V_7 -> V_127 > 0 )
F_8 ( V_7 ) ;
else
F_11 ( V_7 ) ;
if ( V_7 -> V_49 != V_113 ) {
F_60 ( & V_7 -> V_126 ) ;
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_44 ( V_7 ) ;
F_62 ( & V_7 -> V_126 ) ;
if ( ! V_8 )
F_46 ( V_7 ) ;
}
return V_8 ;
}
static bool F_113 ( void )
{
struct V_216 * V_217 = F_114 ( 0 , 0 ) ;
T_8 V_218 ;
if ( ! V_217 )
return false ;
F_115 ( V_217 , V_219 ,
V_220 , & V_218 ) ;
if ( ( V_218 & V_221 ) == 0 )
return false ;
if ( ! V_222 ) {
F_116 ( V_223 L_10 \
L_11 ) ;
F_116 ( V_223 L_12 \
L_13 ) ;
return true ;
}
F_116 ( V_223 L_14 ) ;
F_117 ( V_217 , V_219 ,
V_220 , V_218 & ~ V_221 ) ;
return false ;
}
static int F_118 ( struct V_224 * V_225 )
{
int V_8 ;
struct V_226 * V_227 ;
struct V_228 * V_39 = V_225 -> V_12 . V_229 ;
struct V_230 V_231 = {
. type = L_15 ,
. V_232 = 0x42 >> 1 ,
. V_229 = & V_233 ,
} ;
struct V_6 * V_7 ;
if ( V_39 -> V_75 < ( V_91 * V_88 * 4 ) ) {
F_116 ( V_234 L_16 ) ;
return - V_79 ;
}
if ( V_39 -> V_235 == NULL ) {
F_116 ( V_234 L_17 ) ;
return - V_79 ;
}
if ( F_119 () && F_113 () )
return - V_136 ;
V_7 = F_120 ( sizeof( struct V_6 ) , V_236 ) ;
if ( V_7 == NULL )
return - V_79 ;
V_237 = V_7 ;
V_7 -> V_11 = V_225 ;
V_7 -> V_39 = V_39 ;
V_7 -> V_127 = 0 ;
V_7 -> V_132 = NULL ;
V_7 -> V_49 = V_113 ;
V_7 -> V_69 = V_7 -> V_26 = V_238 ;
F_121 ( & V_7 -> V_126 ) ;
F_71 ( & V_7 -> V_52 ) ;
V_7 -> V_32 = V_39 -> V_235 ;
V_7 -> V_82 = V_39 -> V_82 ;
V_7 -> V_80 = V_39 -> V_239 ;
V_7 -> V_47 = 1 << V_111 ;
V_7 -> V_27 = V_240 ;
V_8 = F_122 ( & V_225 -> V_12 , & V_7 -> V_241 ) ;
if ( V_8 ) {
F_4 ( & V_225 -> V_12 , L_18 ) ;
goto V_242;
}
V_8 = F_123 ( & V_7 -> V_243 , 10 ) ;
if ( V_8 )
goto V_244;
V_7 -> V_241 . V_243 = & V_7 -> V_243 ;
V_225 -> V_12 . V_245 = & V_39 -> V_225 -> V_245 ;
F_124 ( & V_225 -> V_12 , 0xffffffff ) ;
F_112 ( V_215 , 0x78 , 0 , 0x80 ) ;
F_112 ( V_215 , 0x1e , 0xc0 , 0xc0 ) ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 )
goto V_246;
F_8 ( V_7 ) ;
V_227 = F_125 ( V_247 ) ;
V_7 -> V_248 = F_126 ( & V_7 -> V_241 , V_227 ,
& V_231 , NULL ) ;
if ( V_7 -> V_248 == NULL ) {
F_4 ( & V_225 -> V_12 , L_19 ) ;
V_8 = - V_249 ;
goto V_250;
}
F_38 ( V_7 ) ;
V_8 = F_127 ( V_39 -> V_225 -> V_35 , F_22 ,
F_32 , V_251 , L_9 , V_7 ) ;
if ( V_8 )
goto V_250;
V_7 -> V_252 = V_253 ;
V_7 -> V_252 . V_241 = & V_7 -> V_241 ;
V_8 = F_128 ( & V_7 -> V_252 , V_254 , - 1 ) ;
if ( V_8 )
goto V_255;
F_129 ( & V_7 -> V_252 , V_7 ) ;
#ifdef F_130
V_256 . V_257 = V_7 ;
F_131 ( & V_256 ) ;
#endif
F_11 ( V_7 ) ;
return 0 ;
V_255:
F_132 ( V_39 -> V_225 -> V_35 , V_7 ) ;
V_250:
F_12 ( V_7 ) ;
V_246:
F_133 ( & V_7 -> V_243 ) ;
V_244:
F_134 ( & V_7 -> V_241 ) ;
V_242:
F_135 ( V_7 ) ;
return V_8 ;
}
static int F_136 ( struct V_224 * V_225 )
{
struct V_6 * V_7 = V_237 ;
struct V_228 * V_39 = V_225 -> V_12 . V_229 ;
F_137 ( & V_7 -> V_252 ) ;
F_134 ( & V_7 -> V_241 ) ;
F_132 ( V_39 -> V_225 -> V_35 , V_7 ) ;
F_12 ( V_7 ) ;
F_133 ( & V_7 -> V_243 ) ;
F_135 ( V_7 ) ;
V_237 = NULL ;
return 0 ;
}
