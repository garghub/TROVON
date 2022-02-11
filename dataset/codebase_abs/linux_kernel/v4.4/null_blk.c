static int F_1 ( const char * V_1 , int * V_2 , int V_3 , int V_4 )
{
int V_5 , V_6 ;
V_5 = F_2 ( V_1 , 10 , & V_6 ) ;
if ( V_5 )
return - V_7 ;
if ( V_6 < V_3 || V_6 > V_4 )
return - V_7 ;
* V_2 = V_6 ;
return 0 ;
}
static int F_3 ( const char * V_1 , const struct V_8 * V_9 )
{
return F_1 ( V_1 , & V_10 , V_11 , V_12 ) ;
}
static int F_4 ( const char * V_1 , const struct V_8 * V_9 )
{
return F_1 ( V_1 , & V_13 , V_14 ,
V_15 ) ;
}
static void F_5 ( struct V_16 * V_17 , unsigned int V_18 )
{
F_6 ( V_18 , V_17 -> V_19 ) ;
if ( F_7 ( & V_17 -> V_20 ) )
F_8 ( & V_17 -> V_20 ) ;
}
static unsigned int F_9 ( struct V_16 * V_17 )
{
unsigned int V_18 ;
do {
V_18 = F_10 ( V_17 -> V_19 , V_17 -> V_21 ) ;
if ( V_18 >= V_17 -> V_21 )
return - 1U ;
} while ( F_11 ( V_18 , V_17 -> V_19 ) );
return V_18 ;
}
static void F_12 ( struct V_22 * V_23 )
{
F_5 ( V_23 -> V_17 , V_23 -> V_18 ) ;
}
static struct V_22 * F_13 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
unsigned int V_18 ;
V_18 = F_9 ( V_17 ) ;
if ( V_18 != - 1U ) {
V_23 = & V_17 -> V_24 [ V_18 ] ;
V_23 -> V_18 = V_18 ;
V_23 -> V_17 = V_17 ;
if ( V_13 == V_15 ) {
F_14 ( & V_23 -> V_25 , V_26 ,
V_27 ) ;
V_23 -> V_25 . V_28 = V_29 ;
}
return V_23 ;
}
return NULL ;
}
static struct V_22 * F_15 ( struct V_16 * V_17 , int V_30 )
{
struct V_22 * V_23 ;
F_16 ( V_20 ) ;
V_23 = F_13 ( V_17 ) ;
if ( V_23 || ! V_30 )
return V_23 ;
do {
F_17 ( & V_17 -> V_20 , & V_20 , V_31 ) ;
V_23 = F_13 ( V_17 ) ;
if ( V_23 )
break;
F_18 () ;
} while ( 1 );
F_19 ( & V_17 -> V_20 , & V_20 ) ;
return V_23 ;
}
static void F_20 ( struct V_22 * V_23 )
{
struct V_32 * V_33 = NULL ;
if ( V_23 -> V_34 )
V_33 = V_23 -> V_34 -> V_33 ;
switch ( V_10 ) {
case V_12 :
F_21 ( V_23 -> V_34 , 0 ) ;
return;
case V_35 :
F_22 ( & V_23 -> V_34 -> V_36 ) ;
F_23 ( V_23 -> V_34 , 0 ) ;
break;
case V_11 :
F_24 ( V_23 -> V_37 ) ;
break;
}
F_12 ( V_23 ) ;
if ( V_10 == V_35 && F_25 ( V_33 ) ) {
unsigned long V_38 ;
F_26 ( V_33 -> V_39 , V_38 ) ;
F_27 ( V_33 ) ;
F_28 ( V_33 -> V_39 , V_38 ) ;
}
}
static enum V_40 V_29 ( struct V_41 * V_25 )
{
F_20 ( F_29 ( V_25 , struct V_22 , V_25 ) ) ;
return V_42 ;
}
static void F_30 ( struct V_22 * V_23 )
{
T_1 V_43 = F_31 ( 0 , V_44 ) ;
F_32 ( & V_23 -> V_25 , V_43 , V_27 ) ;
}
static void F_33 ( struct V_45 * V_34 )
{
if ( V_10 == V_12 )
F_20 ( F_34 ( V_34 ) ) ;
else
F_20 ( V_34 -> V_46 ) ;
}
static inline void F_35 ( struct V_22 * V_23 )
{
switch ( V_13 ) {
case V_47 :
switch ( V_10 ) {
case V_12 :
F_36 ( V_23 -> V_34 , V_23 -> V_34 -> V_48 ) ;
break;
case V_35 :
F_37 ( V_23 -> V_34 ) ;
break;
case V_11 :
F_20 ( V_23 ) ;
break;
}
break;
case V_14 :
F_20 ( V_23 ) ;
break;
case V_15 :
F_30 ( V_23 ) ;
break;
}
}
static struct V_16 * F_38 ( struct V_49 * V_49 )
{
int V_50 = 0 ;
if ( V_49 -> V_51 != 1 )
V_50 = F_39 () / ( ( V_52 + V_49 -> V_51 - 1 ) / V_49 -> V_51 ) ;
return & V_49 -> V_53 [ V_50 ] ;
}
static T_2 F_40 ( struct V_32 * V_33 , struct V_37 * V_37 )
{
struct V_49 * V_49 = V_33 -> V_54 ;
struct V_16 * V_17 = F_38 ( V_49 ) ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_17 , 1 ) ;
V_23 -> V_37 = V_37 ;
F_35 ( V_23 ) ;
return V_55 ;
}
static int F_41 ( struct V_32 * V_33 , struct V_45 * V_56 )
{
struct V_49 * V_49 = V_33 -> V_54 ;
struct V_16 * V_17 = F_38 ( V_49 ) ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_17 , 0 ) ;
if ( V_23 ) {
V_23 -> V_34 = V_56 ;
V_56 -> V_46 = V_23 ;
return V_57 ;
}
F_42 ( V_33 ) ;
return V_58 ;
}
static void F_43 ( struct V_32 * V_33 )
{
struct V_45 * V_34 ;
while ( ( V_34 = F_44 ( V_33 ) ) != NULL ) {
struct V_22 * V_23 = V_34 -> V_46 ;
F_45 ( V_33 -> V_39 ) ;
F_35 ( V_23 ) ;
F_46 ( V_33 -> V_39 ) ;
}
}
static int F_47 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_22 * V_23 = F_34 ( V_62 -> V_34 ) ;
if ( V_13 == V_15 ) {
F_14 ( & V_23 -> V_25 , V_26 , V_27 ) ;
V_23 -> V_25 . V_28 = V_29 ;
}
V_23 -> V_34 = V_62 -> V_34 ;
V_23 -> V_17 = V_60 -> V_63 ;
F_48 ( V_62 -> V_34 ) ;
F_35 ( V_23 ) ;
return V_64 ;
}
static void F_49 ( struct V_49 * V_49 , struct V_16 * V_17 )
{
F_50 ( ! V_49 ) ;
F_50 ( ! V_17 ) ;
F_51 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_49 -> V_21 ;
}
static int F_52 ( struct V_59 * V_60 , void * V_65 ,
unsigned int V_50 )
{
struct V_49 * V_49 = V_65 ;
struct V_16 * V_17 = & V_49 -> V_53 [ V_50 ] ;
V_60 -> V_63 = V_17 ;
F_49 ( V_49 , V_17 ) ;
V_49 -> V_51 ++ ;
return 0 ;
}
static void F_53 ( struct V_16 * V_17 )
{
F_54 ( V_17 -> V_19 ) ;
F_54 ( V_17 -> V_24 ) ;
}
static void F_55 ( struct V_49 * V_49 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_49 -> V_51 ; V_66 ++ )
F_53 ( & V_49 -> V_53 [ V_66 ] ) ;
F_54 ( V_49 -> V_53 ) ;
}
static void F_56 ( struct V_49 * V_49 )
{
F_57 ( & V_49 -> V_67 ) ;
if ( V_68 )
F_58 ( V_49 -> V_69 ) ;
else
F_59 ( V_49 -> V_70 ) ;
F_60 ( V_49 -> V_33 ) ;
if ( V_10 == V_12 )
F_61 ( & V_49 -> V_71 ) ;
if ( ! V_68 )
F_62 ( V_49 -> V_70 ) ;
F_55 ( V_49 ) ;
F_54 ( V_49 ) ;
}
static void F_63 ( struct V_45 * V_34 , int error )
{
struct V_72 * V_73 = V_34 -> V_74 ;
struct V_75 * V_76 = V_73 -> V_76 ;
V_76 -> V_77 -> V_78 ( V_73 , error ) ;
F_64 ( V_34 ) ;
}
static int F_65 ( struct V_75 * V_76 , struct V_72 * V_73 )
{
struct V_32 * V_33 = V_76 -> V_33 ;
struct V_45 * V_34 ;
struct V_37 * V_37 = V_73 -> V_37 ;
V_34 = F_66 ( V_33 , F_67 ( V_37 ) , V_79 , 0 ) ;
if ( F_68 ( V_34 ) )
return - V_80 ;
V_34 -> V_81 = V_82 ;
V_34 -> V_83 = V_37 -> V_84 . V_85 ;
V_34 -> V_86 = F_69 ( V_37 ) ;
if ( F_70 ( V_37 ) )
V_34 -> V_87 = F_71 ( V_33 , V_37 ) ;
V_34 -> V_88 = V_37 -> V_84 . V_89 ;
V_34 -> V_37 = V_34 -> V_90 = V_37 ;
V_34 -> V_74 = V_73 ;
F_72 ( V_33 , NULL , V_34 , 0 , F_63 ) ;
return 0 ;
}
static int F_73 ( struct V_75 * V_76 , struct V_91 * V_92 )
{
T_3 V_93 = V_94 * 1024 * 1024 * 1024ULL ;
T_3 V_95 ;
struct V_96 * V_97 ;
V_92 -> V_98 = 0x1 ;
V_92 -> V_99 = 0 ;
V_92 -> V_100 = 1 ;
V_92 -> V_101 = 0x3 ;
V_92 -> V_102 = 0x1 ;
V_92 -> V_103 . V_104 = 0 ;
V_92 -> V_103 . V_105 = 16 ;
V_92 -> V_103 . V_106 = 16 ;
V_92 -> V_103 . V_107 = 16 ;
V_92 -> V_103 . V_108 = 32 ;
V_92 -> V_103 . V_109 = 8 ;
V_92 -> V_103 . V_110 = 40 ;
V_92 -> V_103 . V_111 = 8 ;
V_92 -> V_103 . V_112 = 48 ;
V_92 -> V_103 . V_113 = 8 ;
V_92 -> V_103 . V_114 = 56 ;
V_92 -> V_103 . V_115 = 8 ;
F_74 ( V_93 , V_116 ) ;
F_74 ( V_93 , 256 ) ;
V_97 = & V_92 -> V_117 [ 0 ] ;
V_97 -> V_118 = 0 ;
V_97 -> V_119 = 0 ;
V_97 -> V_120 = 1 ;
V_97 -> V_121 = 256 ;
V_95 = V_93 ;
F_74 ( V_93 , ( 1 << 16 ) ) ;
V_97 -> V_122 = V_93 + 1 ;
F_74 ( V_95 , V_97 -> V_122 ) ;
V_97 -> V_123 = V_95 ;
V_97 -> V_124 = 1 ;
V_97 -> V_125 = V_116 ;
V_97 -> V_126 = V_116 ;
V_97 -> V_127 = 25000 ;
V_97 -> V_128 = 25000 ;
V_97 -> V_129 = 500000 ;
V_97 -> V_130 = 500000 ;
V_97 -> V_131 = 1500000 ;
V_97 -> V_132 = 1500000 ;
V_97 -> V_133 = 0x010101 ;
V_97 -> V_134 = V_135 ;
return 0 ;
}
static void * F_75 ( struct V_75 * V_76 , char * V_136 )
{
T_4 * V_137 ;
V_137 = F_76 ( 64 , V_138 ) ;
if ( ! V_137 ) {
F_77 ( L_1 ) ;
return NULL ;
}
return V_137 ;
}
static void F_78 ( void * V_139 )
{
F_79 ( V_139 ) ;
}
static void * F_80 ( struct V_75 * V_76 , void * V_139 ,
T_5 V_140 , T_6 * V_141 )
{
return F_81 ( V_139 , V_140 ) ;
}
static void F_82 ( void * V_139 , void * V_142 ,
T_6 V_141 )
{
F_83 ( V_142 , V_139 ) ;
}
static int F_84 ( struct V_143 * V_144 , T_7 V_145 )
{
return 0 ;
}
static void F_85 ( struct V_146 * V_70 , T_7 V_145 )
{
}
static int F_86 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_66 , V_147 ;
V_17 -> V_24 = F_87 ( V_17 -> V_21 * sizeof( * V_23 ) , V_79 ) ;
if ( ! V_17 -> V_24 )
return - V_80 ;
V_147 = F_88 ( V_17 -> V_21 , V_148 ) / V_148 ;
V_17 -> V_19 = F_87 ( V_147 * sizeof( unsigned long ) , V_79 ) ;
if ( ! V_17 -> V_19 ) {
F_54 ( V_17 -> V_24 ) ;
return - V_80 ;
}
for ( V_66 = 0 ; V_66 < V_17 -> V_21 ; V_66 ++ ) {
V_23 = & V_17 -> V_24 [ V_66 ] ;
F_22 ( & V_23 -> V_67 ) ;
V_23 -> V_149 . V_150 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static int F_89 ( struct V_49 * V_49 )
{
V_49 -> V_53 = F_87 ( V_151 * sizeof( struct V_16 ) ,
V_79 ) ;
if ( ! V_49 -> V_53 )
return - V_80 ;
V_49 -> V_51 = 0 ;
V_49 -> V_21 = V_135 ;
return 0 ;
}
static int F_90 ( struct V_49 * V_49 )
{
struct V_16 * V_17 ;
int V_66 , V_5 = 0 ;
for ( V_66 = 0 ; V_66 < V_151 ; V_66 ++ ) {
V_17 = & V_49 -> V_53 [ V_66 ] ;
F_49 ( V_49 , V_17 ) ;
V_5 = F_86 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_49 -> V_51 ++ ;
}
return 0 ;
}
static int F_91 ( void )
{
struct V_146 * V_70 ;
struct V_49 * V_49 ;
T_3 V_93 ;
int V_152 ;
V_49 = F_92 ( sizeof( * V_49 ) , V_79 , V_153 ) ;
if ( ! V_49 ) {
V_152 = - V_80 ;
goto V_154;
}
F_93 ( & V_49 -> V_155 ) ;
if ( V_10 == V_12 && V_156 )
V_151 = V_157 ;
V_152 = F_89 ( V_49 ) ;
if ( V_152 )
goto V_158;
if ( V_10 == V_12 ) {
V_49 -> V_71 . V_159 = & V_160 ;
V_49 -> V_71 . V_161 = V_151 ;
V_49 -> V_71 . V_21 = V_135 ;
V_49 -> V_71 . V_162 = V_153 ;
V_49 -> V_71 . V_163 = sizeof( struct V_22 ) ;
V_49 -> V_71 . V_38 = V_164 ;
V_49 -> V_71 . V_63 = V_49 ;
V_152 = F_94 ( & V_49 -> V_71 ) ;
if ( V_152 )
goto V_165;
V_49 -> V_33 = F_95 ( & V_49 -> V_71 ) ;
if ( F_68 ( V_49 -> V_33 ) ) {
V_152 = - V_80 ;
goto V_166;
}
} else if ( V_10 == V_11 ) {
V_49 -> V_33 = F_96 ( V_79 , V_153 ) ;
if ( ! V_49 -> V_33 ) {
V_152 = - V_80 ;
goto V_165;
}
F_97 ( V_49 -> V_33 , F_40 ) ;
V_152 = F_90 ( V_49 ) ;
if ( V_152 )
goto V_167;
} else {
V_49 -> V_33 = F_98 ( F_43 , & V_49 -> V_155 , V_153 ) ;
if ( ! V_49 -> V_33 ) {
V_152 = - V_80 ;
goto V_165;
}
F_99 ( V_49 -> V_33 , F_41 ) ;
F_100 ( V_49 -> V_33 , F_33 ) ;
V_152 = F_90 ( V_49 ) ;
if ( V_152 )
goto V_167;
}
V_49 -> V_33 -> V_54 = V_49 ;
F_101 ( V_168 , V_49 -> V_33 ) ;
F_102 ( V_169 , V_49 -> V_33 ) ;
F_103 ( & V_155 ) ;
F_104 ( & V_49 -> V_67 , & V_170 ) ;
V_49 -> V_50 = V_171 ++ ;
F_105 ( & V_155 ) ;
F_106 ( V_49 -> V_33 , V_116 ) ;
F_107 ( V_49 -> V_33 , V_116 ) ;
sprintf ( V_49 -> V_69 , L_2 , V_49 -> V_50 ) ;
if ( V_68 ) {
V_152 = F_108 ( V_49 -> V_33 , V_49 -> V_69 ,
& V_172 ) ;
if ( V_152 )
goto V_167;
goto V_173;
}
V_70 = V_49 -> V_70 = F_109 ( 1 , V_153 ) ;
if ( ! V_70 ) {
V_152 = - V_80 ;
goto V_174;
}
V_93 = V_94 * 1024 * 1024 * 1024ULL ;
F_110 ( V_70 , V_93 >> 9 ) ;
V_70 -> V_38 |= V_175 | V_176 ;
V_70 -> V_177 = V_178 ;
V_70 -> V_179 = V_49 -> V_50 ;
V_70 -> V_180 = & V_181 ;
V_70 -> V_182 = V_49 ;
V_70 -> V_183 = V_49 -> V_33 ;
strncpy ( V_70 -> V_69 , V_49 -> V_69 , V_184 ) ;
F_111 ( V_70 ) ;
V_173:
return 0 ;
V_174:
if ( V_68 )
F_58 ( V_49 -> V_69 ) ;
V_167:
F_60 ( V_49 -> V_33 ) ;
V_166:
if ( V_10 == V_12 )
F_61 ( & V_49 -> V_71 ) ;
V_165:
F_55 ( V_49 ) ;
V_158:
F_54 ( V_49 ) ;
V_154:
return V_152 ;
}
static int T_8 F_112 ( void )
{
int V_5 = 0 ;
unsigned int V_66 ;
struct V_49 * V_49 ;
if ( V_116 > V_185 ) {
F_113 ( L_3 ) ;
F_113 ( L_4 , V_185 ) ;
V_116 = V_185 ;
}
if ( V_68 && V_116 != 4096 ) {
F_113 ( L_5 ) ;
F_113 ( L_6 ) ;
V_116 = 4096 ;
}
if ( V_68 && V_10 != V_12 ) {
F_113 ( L_7 ) ;
F_113 ( L_8 ) ;
V_10 = V_12 ;
}
if ( V_10 == V_12 && V_156 ) {
if ( V_151 < V_157 ) {
F_113 ( L_9 ,
V_157 ) ;
V_151 = V_157 ;
}
} else if ( V_151 > V_52 )
V_151 = V_52 ;
else if ( ! V_151 )
V_151 = 1 ;
F_114 ( & V_155 ) ;
V_178 = F_115 ( 0 , L_10 ) ;
if ( V_178 < 0 )
return V_178 ;
if ( V_68 ) {
V_138 = F_116 ( L_11 , 64 * sizeof( V_186 ) ,
0 , 0 , NULL ) ;
if ( ! V_138 ) {
F_77 ( L_12 ) ;
V_5 = - V_80 ;
goto V_187;
}
}
for ( V_66 = 0 ; V_66 < V_188 ; V_66 ++ ) {
V_5 = F_91 () ;
if ( V_5 )
goto V_189;
}
F_117 ( L_13 ) ;
return 0 ;
V_189:
while ( ! F_118 ( & V_170 ) ) {
V_49 = F_119 ( V_170 . V_150 , struct V_49 , V_67 ) ;
F_56 ( V_49 ) ;
}
F_120 ( V_138 ) ;
V_187:
F_121 ( V_178 , L_10 ) ;
return V_5 ;
}
static void T_9 F_122 ( void )
{
struct V_49 * V_49 ;
F_121 ( V_178 , L_10 ) ;
F_103 ( & V_155 ) ;
while ( ! F_118 ( & V_170 ) ) {
V_49 = F_119 ( V_170 . V_150 , struct V_49 , V_67 ) ;
F_56 ( V_49 ) ;
}
F_105 ( & V_155 ) ;
F_120 ( V_138 ) ;
}
