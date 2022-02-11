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
struct V_22 V_23 ;
int V_8 ;
F_16 ( & V_23 , & V_7 -> V_24 , V_7 -> V_25 ) ;
V_8 = F_14 ( V_7 , V_20 , V_26 , 0 ) ;
if ( V_8 == 0 )
V_8 = F_14 ( V_7 , V_27 , V_28 , & V_23 ) ;
if ( V_8 == 0 )
V_8 = F_13 ( V_7 ) ;
return V_8 ;
}
static inline void F_17 ( struct V_6 * V_7 ,
int V_29 , int V_18 )
{
F_18 ( V_18 , V_7 -> V_30 + V_29 ) ;
}
static inline int F_19 ( struct V_6 * V_7 , int V_29 )
{
return F_20 ( V_7 -> V_30 + V_29 ) ;
}
static inline void F_21 ( struct V_6 * V_7 ,
int V_29 , int V_18 , int V_31 )
{
int V_32 = F_19 ( V_7 , V_29 ) ;
V_32 = ( V_32 & ~ V_31 ) | ( V_18 & V_31 ) ;
F_17 ( V_7 , V_29 , V_32 ) ;
}
static T_2 F_22 ( int V_33 , void * V_34 )
{
struct V_6 * V_7 = V_34 ;
T_2 V_8 = V_35 ;
int V_36 ;
F_23 ( & V_7 -> V_37 -> V_38 ) ;
V_36 = F_19 ( V_7 , V_39 ) ;
if ( V_36 & V_40 ) {
V_36 |= V_40 | V_41 | V_42 ;
F_17 ( V_7 , V_39 , V_36 ) ;
V_8 = V_43 ;
}
F_24 ( & V_7 -> V_37 -> V_38 ) ;
return V_8 ;
}
static struct V_44 * F_25 ( struct V_6 * V_7 )
{
unsigned long V_45 ;
struct V_44 * V_46 = NULL ;
F_26 ( & V_7 -> V_37 -> V_38 , V_45 ) ;
if ( V_7 -> V_47 != V_48 )
goto V_49;
if ( F_27 ( & V_7 -> V_50 ) )
goto V_49;
V_46 = F_28 ( V_7 -> V_50 . V_51 , struct V_44 , V_52 ) ;
if ( ! F_29 ( & V_46 -> V_53 ) ) {
V_46 = NULL ;
goto V_49;
}
F_30 ( & V_46 -> V_52 ) ;
V_46 -> V_54 = V_55 ;
V_49:
F_31 ( & V_7 -> V_37 -> V_38 , V_45 ) ;
return V_46 ;
}
static T_2 F_32 ( int V_33 , void * V_34 )
{
int V_56 ;
struct V_44 * V_57 ;
struct V_6 * V_7 = V_34 ;
struct V_58 * V_59 ;
V_57 = F_25 ( V_7 ) ;
if ( V_57 == NULL )
goto V_53;
V_56 = ( F_19 ( V_7 , V_39 ) & V_60 ) >> 3 ;
V_56 -= 1 ;
if ( V_56 < 0 )
V_56 = V_7 -> V_61 - 1 ;
V_59 = F_33 ( V_57 ) ;
F_34 ( V_7 -> V_62 [ V_56 ] , V_59 -> V_63 , V_59 -> V_64 ) ;
V_57 -> V_54 = V_65 ;
V_57 -> V_66 = V_7 -> V_67 . V_68 ;
F_35 ( & V_57 -> V_53 ) ;
V_53:
return V_69 ;
}
static void F_36 ( struct V_6 * V_7 )
{
F_17 ( V_7 , V_39 ,
V_70 | V_40 | V_41 | V_42 ) ;
F_37 ( V_71 ) ;
}
static void F_38 ( struct V_6 * V_7 )
{
F_39 ( V_71 ) ;
F_17 ( V_7 , V_39 , 0 ) ;
}
static int F_40 ( struct V_6 * V_7 )
{
int V_72 = V_7 -> V_37 -> V_73 / V_7 -> V_24 . V_68 ;
int V_3 ;
unsigned int V_74 ;
if ( V_72 >= 3 ) {
V_7 -> V_61 = 3 ;
F_21 ( V_7 , V_75 , V_76 ,
V_76 ) ;
} else if ( V_72 == 2 ) {
V_7 -> V_61 = 2 ;
F_21 ( V_7 , V_75 , 0 , V_76 ) ;
} else {
F_41 ( V_7 , L_7 ) ;
return - V_77 ;
}
V_74 = V_7 -> V_78 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_61 ; V_3 ++ ) {
V_7 -> V_62 [ V_3 ] = V_74 ;
V_7 -> V_79 [ V_3 ] = V_7 -> V_80 + V_74 ;
F_17 ( V_7 , V_81 + V_3 * 4 , V_74 & V_82 ) ;
V_74 += V_7 -> V_24 . V_68 ;
}
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
unsigned int V_83 ;
int V_84 ;
if ( V_7 -> V_67 . V_85 == V_86 )
V_83 = 0 ;
else {
V_84 = ( V_7 -> V_67 . V_85 * 2048 ) / V_86 ;
V_83 = V_87 | V_84 ;
}
if ( V_7 -> V_67 . V_88 < V_89 ) {
V_84 = ( 1024 * V_7 -> V_67 . V_88 ) / V_89 ;
V_83 |= V_90 | ( V_84 << 16 ) ;
}
F_17 ( V_7 , V_91 , V_83 ) ;
}
static void F_43 ( struct V_6 * V_7 )
{
int V_92 ;
F_17 ( V_7 , V_75 , ~ ( V_93 | V_94 ) ) ;
F_17 ( V_7 , V_95 , 0x06200120 ) ;
F_17 ( V_7 , V_96 , 0x01de0000 ) ;
F_42 ( V_7 ) ;
F_17 ( V_7 , V_97 ,
( V_7 -> V_24 . V_88 << 16 ) |
( V_7 -> V_24 . V_98 >> 3 ) ) ;
F_17 ( V_7 , V_99 , 0 ) ;
F_17 ( V_7 , V_100 ,
V_7 -> V_67 . V_98 & V_101 ) ;
V_92 = V_94 |
0x08000000 |
V_102 |
V_103 |
V_104 |
V_105 ;
if ( V_7 -> V_61 == 3 )
V_92 |= V_76 ;
if ( V_7 -> V_67 . V_2 == V_106 )
V_92 |= V_107 ;
else
V_92 |= V_108 ;
F_17 ( V_7 , V_75 , V_92 ) ;
}
static int F_44 ( struct V_6 * V_7 )
{
int V_8 ;
unsigned long V_45 ;
F_26 ( & V_7 -> V_37 -> V_38 , V_45 ) ;
V_8 = F_40 ( V_7 ) ;
if ( ! V_8 )
F_43 ( V_7 ) ;
F_31 ( & V_7 -> V_37 -> V_38 , V_45 ) ;
F_45 ( V_109 , & V_7 -> V_45 ) ;
return V_8 ;
}
static void F_46 ( struct V_6 * V_7 )
{
F_47 ( & V_7 -> V_37 -> V_38 ) ;
V_7 -> V_110 = 0 ;
F_21 ( V_7 , V_75 , V_93 , V_93 ) ;
F_36 ( V_7 ) ;
( void ) F_19 ( V_7 , V_75 ) ;
V_7 -> V_47 = V_48 ;
F_48 ( & V_7 -> V_37 -> V_38 ) ;
}
static void F_49 ( struct V_6 * V_7 )
{
F_47 ( & V_7 -> V_37 -> V_38 ) ;
F_38 ( V_7 ) ;
F_21 ( V_7 , V_75 , 0 , V_93 ) ;
( void ) F_19 ( V_7 , V_75 ) ;
V_7 -> V_47 = V_111 ;
F_48 ( & V_7 -> V_37 -> V_38 ) ;
}
static int F_50 ( struct V_112 * V_113 ,
unsigned int * V_114 , unsigned int * V_66 )
{
struct V_6 * V_7 = V_113 -> V_115 ;
* V_66 = V_7 -> V_67 . V_68 ;
if ( * V_114 == 0 || * V_114 > 6 )
* V_114 = 6 ;
return 0 ;
}
static int F_51 ( struct V_112 * V_113 ,
struct V_44 * V_57 , enum V_116 V_117 )
{
struct V_6 * V_7 = V_113 -> V_115 ;
V_57 -> V_66 = V_7 -> V_67 . V_68 ;
V_57 -> V_85 = V_7 -> V_67 . V_85 ;
V_57 -> V_88 = V_7 -> V_67 . V_88 ;
V_57 -> V_117 = V_117 ;
if ( V_57 -> V_54 == V_118 ) {
int V_8 = F_52 ( V_113 , V_57 , NULL ) ;
if ( V_8 )
return V_8 ;
}
V_57 -> V_54 = V_119 ;
return 0 ;
}
static void F_53 ( struct V_112 * V_113 ,
struct V_44 * V_57 )
{
struct V_6 * V_7 = V_113 -> V_115 ;
V_57 -> V_54 = V_120 ;
F_54 ( & V_57 -> V_52 , & V_7 -> V_50 ) ;
}
static void F_55 ( struct V_112 * V_113 ,
struct V_44 * V_57 )
{
struct V_6 * V_7 = V_113 -> V_115 ;
F_56 ( & V_7 -> V_11 -> V_12 , F_33 ( V_57 ) ) ;
F_57 ( F_33 ( V_57 ) ) ;
V_57 -> V_54 = V_118 ;
}
static int F_58 ( struct V_121 * V_122 )
{
struct V_6 * V_7 = F_59 ( V_122 ) ;
V_122 -> V_123 = V_7 ;
F_60 ( & V_7 -> V_124 ) ;
if ( V_7 -> V_125 == 0 ) {
int V_8 = F_61 () ;
if ( V_8 ) {
F_62 ( & V_7 -> V_124 ) ;
return V_8 ;
}
F_8 ( V_7 ) ;
F_63 ( V_109 , & V_7 -> V_45 ) ;
F_64 ( & V_7 -> V_126 , & V_127 ,
& V_7 -> V_11 -> V_12 , & V_7 -> V_37 -> V_38 ,
V_128 , V_129 ,
sizeof( struct V_44 ) , V_7 , NULL ) ;
}
( V_7 -> V_125 ) ++ ;
F_62 ( & V_7 -> V_124 ) ;
return 0 ;
}
static int F_65 ( struct V_121 * V_122 )
{
struct V_6 * V_7 = F_59 ( V_122 ) ;
F_60 ( & V_7 -> V_124 ) ;
( V_7 -> V_125 ) -- ;
if ( V_122 == V_7 -> V_130 ) {
F_66 ( & V_7 -> V_126 ) ;
if ( V_7 -> V_47 != V_111 )
F_49 ( V_7 ) ;
V_7 -> V_130 = NULL ;
}
if ( V_7 -> V_125 == 0 ) {
F_67 ( & V_7 -> V_126 ) ;
F_11 ( V_7 ) ;
F_68 () ;
}
F_62 ( & V_7 -> V_124 ) ;
return 0 ;
}
static T_3 F_69 ( struct V_121 * V_122 , char T_4 * V_131 ,
T_5 V_132 , T_6 * V_133 )
{
struct V_6 * V_7 = F_59 ( V_122 ) ;
int V_8 ;
F_60 ( & V_7 -> V_124 ) ;
if ( V_7 -> V_130 && V_7 -> V_130 != V_122 ) {
V_8 = - V_134 ;
goto V_135;
}
V_7 -> V_130 = V_122 ;
if ( F_70 ( V_109 , & V_7 -> V_45 ) ) {
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_44 ( V_7 ) ;
if ( V_8 )
goto V_135;
}
F_71 ( & V_7 -> V_50 ) ;
F_46 ( V_7 ) ;
V_8 = F_72 ( & V_7 -> V_126 , V_131 , V_132 , V_133 , 0 ,
V_122 -> V_136 & V_137 ) ;
F_49 ( V_7 ) ;
V_135:
F_62 ( & V_7 -> V_124 ) ;
return V_8 ;
}
static unsigned int F_73 ( struct V_121 * V_122 , struct V_138 * V_139 )
{
struct V_6 * V_7 = F_59 ( V_122 ) ;
return F_74 ( V_122 , & V_7 -> V_126 , V_139 ) ;
}
static int F_75 ( struct V_121 * V_122 , struct V_140 * V_141 )
{
struct V_6 * V_7 = F_59 ( V_122 ) ;
return F_76 ( & V_7 -> V_126 , V_141 ) ;
}
static int F_77 ( struct V_121 * V_122 , void * V_142 ,
struct V_143 * V_144 )
{
if ( V_144 -> V_145 != 0 )
return - V_13 ;
V_144 -> type = V_146 ;
V_144 -> V_147 = V_148 ;
strcpy ( V_144 -> V_149 , L_8 ) ;
return 0 ;
}
static int F_78 ( struct V_121 * V_122 , void * V_142 , unsigned int * V_3 )
{
* V_3 = 0 ;
return 0 ;
}
static int F_79 ( struct V_121 * V_122 , void * V_142 , unsigned int V_3 )
{
if ( V_3 != 0 )
return - V_13 ;
return 0 ;
}
static int F_80 ( struct V_121 * V_122 , void * V_142 , T_7 V_147 )
{
return 0 ;
}
static int F_81 ( struct V_121 * V_122 , void * V_142 , T_7 * V_147 )
{
* V_147 = V_150 ;
return 0 ;
}
static int F_82 ( struct V_121 * V_122 , void * V_142 ,
struct V_151 * V_152 )
{
if ( V_152 -> V_145 >= V_4 )
return - V_13 ;
F_83 ( V_152 -> V_153 , V_5 [ V_152 -> V_145 ] . V_154 ,
sizeof( V_152 -> V_153 ) ) ;
V_152 -> V_2 = V_5 [ V_152 -> V_145 ] . V_2 ;
return 0 ;
}
static void F_84 ( struct V_155 * V_156 ,
struct V_155 * V_157 )
{
* V_157 = * V_156 ;
if ( V_156 -> V_85 < V_158 || V_156 -> V_88 < V_159 ) {
V_156 -> V_85 = V_158 ;
V_156 -> V_88 = V_159 ;
}
if ( V_156 -> V_85 > V_86 || V_156 -> V_88 > V_89 ) {
V_156 -> V_85 = V_86 ;
V_156 -> V_88 = V_89 ;
}
V_157 -> V_85 = V_86 ;
V_157 -> V_88 = V_89 ;
}
static void F_85 ( struct V_155 * V_156 ,
struct V_155 * V_157 )
{
struct V_1 * V_160 = F_1 ( V_156 -> V_2 ) ;
V_157 -> V_98 = V_157 -> V_85 * V_160 -> V_161 ;
V_157 -> V_68 = V_157 -> V_88 * V_157 -> V_98 ;
V_156 -> V_2 = V_157 -> V_2 ;
V_156 -> V_117 = V_157 -> V_117 ;
V_156 -> V_98 = 2 * V_156 -> V_85 ;
V_156 -> V_68 = V_156 -> V_98 * V_156 -> V_88 ;
}
static int F_86 ( struct V_6 * V_7 ,
struct V_155 * V_162 , struct V_155 * V_163 )
{
int V_8 ;
struct V_22 V_23 ;
struct V_1 * V_160 = F_1 ( V_162 -> V_2 ) ;
V_162 -> V_2 = V_160 -> V_2 ;
F_84 ( V_162 , V_163 ) ;
F_16 ( & V_23 , V_163 , V_160 -> V_25 ) ;
V_8 = F_14 ( V_7 , V_27 , V_164 , & V_23 ) ;
F_87 ( V_163 , & V_23 ) ;
F_85 ( V_162 , V_163 ) ;
return V_8 ;
}
static int F_88 ( struct V_121 * V_122 , void * V_142 ,
struct V_165 * V_152 )
{
struct V_6 * V_7 = V_142 ;
struct V_165 V_166 ;
int V_8 ;
F_60 ( & V_7 -> V_124 ) ;
V_8 = F_86 ( V_7 , & V_152 -> V_152 . V_167 , & V_166 . V_152 . V_167 ) ;
F_62 ( & V_7 -> V_124 ) ;
return V_8 ;
}
static int F_89 ( struct V_121 * V_122 , void * V_142 ,
struct V_165 * V_152 )
{
struct V_6 * V_7 = V_142 ;
F_60 ( & V_7 -> V_124 ) ;
V_152 -> V_152 . V_167 = V_7 -> V_67 ;
F_62 ( & V_7 -> V_124 ) ;
return 0 ;
}
static int F_90 ( struct V_121 * V_122 , void * V_142 ,
struct V_165 * V_152 )
{
struct V_6 * V_7 = V_142 ;
int V_8 ;
struct V_165 V_166 ;
struct V_1 * V_160 = F_1 ( V_152 -> V_152 . V_167 . V_2 ) ;
F_60 ( & V_7 -> V_124 ) ;
if ( V_7 -> V_47 != V_111 ) {
V_8 = - V_134 ;
goto V_49;
}
V_8 = F_86 ( V_7 , & V_152 -> V_152 . V_167 , & V_166 . V_152 . V_167 ) ;
if ( V_8 )
goto V_49;
V_7 -> V_67 = V_152 -> V_152 . V_167 ;
V_7 -> V_24 = V_166 . V_152 . V_167 ;
V_7 -> V_25 = V_160 -> V_25 ;
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_44 ( V_7 ) ;
V_49:
F_62 ( & V_7 -> V_124 ) ;
return V_8 ;
}
static int F_91 ( struct V_121 * V_122 , void * V_142 ,
struct V_168 * V_169 )
{
strcpy ( V_169 -> V_170 , L_9 ) ;
strcpy ( V_169 -> V_171 , L_9 ) ;
V_169 -> V_172 = 1 ;
V_169 -> V_173 = V_174 |
V_175 | V_176 ;
return 0 ;
}
static int F_92 ( struct V_121 * V_122 , void * V_142 ,
struct V_177 * V_178 )
{
struct V_6 * V_7 = V_142 ;
return F_93 ( & V_7 -> V_126 , V_178 ) ;
}
static int F_94 ( struct V_121 * V_122 , void * V_142 ,
struct V_179 * V_46 )
{
struct V_6 * V_7 = V_142 ;
return F_95 ( & V_7 -> V_126 , V_46 ) ;
}
static int F_96 ( struct V_121 * V_122 , void * V_142 , struct V_179 * V_46 )
{
struct V_6 * V_7 = V_142 ;
return F_97 ( & V_7 -> V_126 , V_46 ) ;
}
static int F_98 ( struct V_121 * V_122 , void * V_142 , struct V_179 * V_46 )
{
struct V_6 * V_7 = V_142 ;
return F_99 ( & V_7 -> V_126 , V_46 , V_122 -> V_136 & V_137 ) ;
}
static int F_100 ( struct V_121 * V_122 , void * V_142 , enum V_180 V_181 )
{
struct V_6 * V_7 = V_142 ;
int V_8 = 0 ;
if ( V_181 != V_128 )
return - V_13 ;
F_60 ( & V_7 -> V_124 ) ;
if ( V_7 -> V_47 != V_111 ) {
V_8 = - V_134 ;
goto V_49;
}
if ( V_7 -> V_130 && V_7 -> V_130 != V_122 ) {
V_8 = - V_134 ;
goto V_49;
}
V_7 -> V_130 = V_122 ;
if ( F_70 ( V_109 , & V_7 -> V_45 ) ) {
V_8 = F_15 ( V_7 ) ;
if ( V_8 )
goto V_49;
V_8 = F_44 ( V_7 ) ;
if ( V_8 )
goto V_49;
}
F_101 ( & V_7 -> V_182 , V_183 , 50 ) ;
F_71 ( & V_7 -> V_50 ) ;
V_8 = F_102 ( & V_7 -> V_126 ) ;
if ( ! V_8 )
F_46 ( V_7 ) ;
V_49:
F_62 ( & V_7 -> V_124 ) ;
return V_8 ;
}
static int F_103 ( struct V_121 * V_122 , void * V_142 , enum V_180 V_181 )
{
struct V_6 * V_7 = V_142 ;
int V_8 ;
if ( V_181 != V_128 )
return - V_13 ;
F_60 ( & V_7 -> V_124 ) ;
if ( V_7 -> V_47 != V_48 ) {
V_8 = - V_13 ;
goto V_49;
}
F_104 ( & V_7 -> V_182 ) ;
F_49 ( V_7 ) ;
V_8 = F_105 ( & V_7 -> V_126 ) ;
F_71 ( & V_7 -> V_50 ) ;
V_49:
F_62 ( & V_7 -> V_124 ) ;
return V_8 ;
}
static int F_106 ( struct V_121 * V_122 , void * V_142 ,
struct V_184 * V_185 )
{
struct V_6 * V_7 = V_142 ;
int V_8 ;
F_60 ( & V_7 -> V_124 ) ;
V_8 = F_14 ( V_7 , V_27 , V_186 , V_185 ) ;
F_62 ( & V_7 -> V_124 ) ;
V_185 -> V_185 . V_187 . V_188 = V_7 -> V_61 ;
return V_8 ;
}
static int F_107 ( struct V_121 * V_122 , void * V_142 ,
struct V_184 * V_185 )
{
struct V_6 * V_7 = V_142 ;
int V_8 ;
F_60 ( & V_7 -> V_124 ) ;
V_8 = F_14 ( V_7 , V_27 , V_189 , V_185 ) ;
F_62 ( & V_7 -> V_124 ) ;
V_185 -> V_185 . V_187 . V_188 = V_7 -> V_61 ;
return V_8 ;
}
static int F_108 ( struct V_121 * V_122 , void * V_142 ,
struct V_190 * V_191 )
{
if ( V_191 -> V_145 != 0 )
return - V_13 ;
V_191 -> type = V_192 ;
V_191 -> V_193 . V_194 = V_158 ;
V_191 -> V_193 . V_195 = V_159 ;
V_191 -> V_193 . V_196 = V_86 ;
V_191 -> V_193 . V_197 = V_89 ;
V_191 -> V_193 . V_198 = V_191 -> V_193 . V_199 = 1 ;
return 0 ;
}
static int F_109 ( struct V_121 * V_122 , void * V_142 ,
struct V_200 * V_201 )
{
struct V_6 * V_7 = V_142 ;
int V_8 ;
F_60 ( & V_7 -> V_124 ) ;
V_8 = F_14 ( V_7 , V_27 , V_202 , V_201 ) ;
F_62 ( & V_7 -> V_124 ) ;
return V_8 ;
}
static int F_110 ( void * V_142 )
{
struct V_6 * V_7 = V_142 ;
enum V_203 V_54 = V_7 -> V_47 ;
if ( V_7 -> V_47 != V_111 ) {
F_49 ( V_7 ) ;
V_7 -> V_47 = V_54 ;
}
return 0 ;
}
static int F_111 ( void * V_142 )
{
struct V_6 * V_7 = V_142 ;
int V_8 = 0 ;
F_112 ( V_204 , 0x78 , 0 , 0x80 ) ;
F_112 ( V_204 , 0x1e , 0xc0 , 0xc0 ) ;
F_38 ( V_7 ) ;
F_63 ( V_109 , & V_7 -> V_45 ) ;
if ( V_7 -> V_125 > 0 )
F_8 ( V_7 ) ;
else
F_11 ( V_7 ) ;
if ( V_7 -> V_47 != V_111 ) {
F_60 ( & V_7 -> V_124 ) ;
V_8 = F_15 ( V_7 ) ;
if ( ! V_8 )
V_8 = F_44 ( V_7 ) ;
F_62 ( & V_7 -> V_124 ) ;
if ( ! V_8 )
F_46 ( V_7 ) ;
}
return V_8 ;
}
static bool F_113 ( void )
{
struct V_205 * V_206 = F_114 ( 0 , 0 ) ;
T_8 V_207 ;
if ( ! V_206 )
return false ;
F_115 ( V_206 , V_208 ,
V_209 , & V_207 ) ;
if ( ( V_207 & V_210 ) == 0 )
return false ;
if ( ! V_211 ) {
F_116 ( V_212 L_10 \
L_11 ) ;
F_116 ( V_212 L_12 \
L_13 ) ;
return true ;
}
F_116 ( V_212 L_14 ) ;
F_117 ( V_206 , V_208 ,
V_209 , V_207 & ~ V_210 ) ;
return false ;
}
static int F_118 ( struct V_213 * V_214 )
{
int V_8 ;
struct V_215 * V_216 ;
struct V_217 * V_37 = V_214 -> V_12 . V_218 ;
struct V_219 V_220 = {
. type = L_15 ,
. V_221 = 0x42 >> 1 ,
. V_218 = & V_222 ,
} ;
struct V_6 * V_7 ;
if ( V_37 -> V_73 < ( V_89 * V_86 * 4 ) ) {
F_116 ( V_223 L_16 ) ;
return - V_77 ;
}
if ( V_37 -> V_224 == NULL ) {
F_116 ( V_223 L_17 ) ;
return - V_77 ;
}
if ( F_119 () && F_113 () )
return - V_134 ;
V_7 = F_120 ( sizeof( struct V_6 ) , V_225 ) ;
if ( V_7 == NULL )
return - V_77 ;
V_226 = V_7 ;
V_7 -> V_11 = V_214 ;
V_7 -> V_37 = V_37 ;
V_7 -> V_125 = 0 ;
V_7 -> V_130 = NULL ;
V_7 -> V_47 = V_111 ;
V_7 -> V_67 = V_7 -> V_24 = V_227 ;
F_121 ( & V_7 -> V_124 ) ;
F_71 ( & V_7 -> V_50 ) ;
V_7 -> V_30 = V_37 -> V_224 ;
V_7 -> V_80 = V_37 -> V_80 ;
V_7 -> V_78 = V_37 -> V_228 ;
V_7 -> V_45 = 1 << V_109 ;
V_7 -> V_25 = V_229 ;
V_8 = F_122 ( & V_214 -> V_12 , & V_7 -> V_230 ) ;
if ( V_8 ) {
F_4 ( & V_214 -> V_12 , L_18 ) ;
goto V_231;
}
V_8 = F_123 ( & V_7 -> V_232 , 10 ) ;
if ( V_8 )
goto V_233;
V_7 -> V_230 . V_232 = & V_7 -> V_232 ;
V_214 -> V_12 . V_234 = & V_37 -> V_214 -> V_234 ;
F_124 ( & V_214 -> V_12 , 0xffffffff ) ;
F_112 ( V_204 , 0x78 , 0 , 0x80 ) ;
F_112 ( V_204 , 0x1e , 0xc0 , 0xc0 ) ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 )
goto V_235;
F_8 ( V_7 ) ;
V_216 = F_125 ( V_236 ) ;
V_7 -> V_237 = F_126 ( & V_7 -> V_230 , V_216 ,
& V_220 , NULL ) ;
if ( V_7 -> V_237 == NULL ) {
F_4 ( & V_214 -> V_12 , L_19 ) ;
V_8 = - V_238 ;
goto V_239;
}
F_38 ( V_7 ) ;
V_8 = F_127 ( V_37 -> V_214 -> V_33 , F_22 ,
F_32 , V_240 , L_9 , V_7 ) ;
if ( V_8 )
goto V_239;
V_7 -> V_241 = V_242 ;
V_7 -> V_241 . V_230 = & V_7 -> V_230 ;
V_8 = F_128 ( & V_7 -> V_241 , V_243 , - 1 ) ;
if ( V_8 )
goto V_244;
F_129 ( & V_7 -> V_241 , V_7 ) ;
#ifdef F_130
V_245 . V_246 = V_7 ;
F_131 ( & V_245 ) ;
#endif
F_11 ( V_7 ) ;
return 0 ;
V_244:
F_132 ( V_37 -> V_214 -> V_33 , V_7 ) ;
V_239:
F_12 ( V_7 ) ;
V_235:
F_133 ( & V_7 -> V_232 ) ;
V_233:
F_134 ( & V_7 -> V_230 ) ;
V_231:
F_135 ( V_7 ) ;
return V_8 ;
}
static int F_136 ( struct V_213 * V_214 )
{
struct V_6 * V_7 = V_226 ;
struct V_217 * V_37 = V_214 -> V_12 . V_218 ;
F_137 ( & V_7 -> V_241 ) ;
F_134 ( & V_7 -> V_230 ) ;
F_132 ( V_37 -> V_214 -> V_33 , V_7 ) ;
F_12 ( V_7 ) ;
F_133 ( & V_7 -> V_232 ) ;
F_135 ( V_7 ) ;
V_226 = NULL ;
return 0 ;
}
