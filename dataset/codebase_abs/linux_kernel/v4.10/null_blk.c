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
T_1 V_43 = V_44 ;
F_31 ( & V_23 -> V_25 , V_43 , V_27 ) ;
}
static void F_32 ( struct V_45 * V_34 )
{
if ( V_10 == V_12 )
F_20 ( F_33 ( V_34 ) ) ;
else
F_20 ( V_34 -> V_46 ) ;
}
static inline void F_34 ( struct V_22 * V_23 )
{
switch ( V_13 ) {
case V_47 :
switch ( V_10 ) {
case V_12 :
F_35 ( V_23 -> V_34 , V_23 -> V_34 -> V_48 ) ;
break;
case V_35 :
F_36 ( V_23 -> V_34 ) ;
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
static struct V_16 * F_37 ( struct V_49 * V_49 )
{
int V_50 = 0 ;
if ( V_49 -> V_51 != 1 )
V_50 = F_38 () / ( ( V_52 + V_49 -> V_51 - 1 ) / V_49 -> V_51 ) ;
return & V_49 -> V_53 [ V_50 ] ;
}
static T_2 F_39 ( struct V_32 * V_33 , struct V_37 * V_37 )
{
struct V_49 * V_49 = V_33 -> V_54 ;
struct V_16 * V_17 = F_37 ( V_49 ) ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_17 , 1 ) ;
V_23 -> V_37 = V_37 ;
F_34 ( V_23 ) ;
return V_55 ;
}
static int F_40 ( struct V_32 * V_33 , struct V_45 * V_56 )
{
struct V_49 * V_49 = V_33 -> V_54 ;
struct V_16 * V_17 = F_37 ( V_49 ) ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_17 , 0 ) ;
if ( V_23 ) {
V_23 -> V_34 = V_56 ;
V_56 -> V_46 = V_23 ;
return V_57 ;
}
F_41 ( V_33 ) ;
return V_58 ;
}
static void F_42 ( struct V_32 * V_33 )
{
struct V_45 * V_34 ;
while ( ( V_34 = F_43 ( V_33 ) ) != NULL ) {
struct V_22 * V_23 = V_34 -> V_46 ;
F_44 ( V_33 -> V_39 ) ;
F_34 ( V_23 ) ;
F_45 ( V_33 -> V_39 ) ;
}
}
static int F_46 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_22 * V_23 = F_33 ( V_62 -> V_34 ) ;
if ( V_13 == V_15 ) {
F_14 ( & V_23 -> V_25 , V_26 , V_27 ) ;
V_23 -> V_25 . V_28 = V_29 ;
}
V_23 -> V_34 = V_62 -> V_34 ;
V_23 -> V_17 = V_60 -> V_63 ;
F_47 ( V_62 -> V_34 ) ;
F_34 ( V_23 ) ;
return V_64 ;
}
static void F_48 ( struct V_49 * V_49 , struct V_16 * V_17 )
{
F_49 ( ! V_49 ) ;
F_49 ( ! V_17 ) ;
F_50 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_49 -> V_21 ;
}
static int F_51 ( struct V_59 * V_60 , void * V_65 ,
unsigned int V_50 )
{
struct V_49 * V_49 = V_65 ;
struct V_16 * V_17 = & V_49 -> V_53 [ V_50 ] ;
V_60 -> V_63 = V_17 ;
F_48 ( V_49 , V_17 ) ;
V_49 -> V_51 ++ ;
return 0 ;
}
static void F_52 ( struct V_16 * V_17 )
{
F_53 ( V_17 -> V_19 ) ;
F_53 ( V_17 -> V_24 ) ;
}
static void F_54 ( struct V_49 * V_49 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_49 -> V_51 ; V_66 ++ )
F_52 ( & V_49 -> V_53 [ V_66 ] ) ;
F_53 ( V_49 -> V_53 ) ;
}
static void F_55 ( struct V_45 * V_34 , int error )
{
struct V_67 * V_68 = V_34 -> V_69 ;
F_56 ( V_68 , error ) ;
F_57 ( V_34 ) ;
}
static int F_58 ( struct V_70 * V_71 , struct V_67 * V_68 )
{
struct V_32 * V_33 = V_71 -> V_33 ;
struct V_45 * V_34 ;
struct V_37 * V_37 = V_68 -> V_37 ;
V_34 = F_59 ( V_33 , F_60 ( V_37 ) , 0 ) ;
if ( F_61 ( V_34 ) )
return - V_72 ;
V_34 -> V_73 = V_74 ;
V_34 -> V_75 = V_37 -> V_76 . V_77 ;
V_34 -> V_78 = F_62 ( V_37 ) ;
if ( F_63 ( V_37 ) )
V_34 -> V_79 = F_64 ( V_33 , V_37 ) ;
V_34 -> V_80 = V_37 -> V_76 . V_81 ;
V_34 -> V_37 = V_34 -> V_82 = V_37 ;
V_34 -> V_69 = V_68 ;
F_65 ( V_33 , NULL , V_34 , 0 , F_55 ) ;
return 0 ;
}
static int F_66 ( struct V_70 * V_71 , struct V_83 * V_84 )
{
T_3 V_85 = V_86 * 1024 * 1024 * 1024ULL ;
T_3 V_87 ;
struct V_88 * V_89 ;
V_84 -> V_90 = 0x1 ;
V_84 -> V_91 = 0 ;
V_84 -> V_92 = 1 ;
V_84 -> V_93 = 0x2 ;
V_84 -> V_94 = 0x1 ;
V_84 -> V_95 . V_96 = 0 ;
V_84 -> V_95 . V_97 = 16 ;
V_84 -> V_95 . V_98 = 16 ;
V_84 -> V_95 . V_99 = 16 ;
V_84 -> V_95 . V_100 = 32 ;
V_84 -> V_95 . V_101 = 8 ;
V_84 -> V_95 . V_102 = 40 ;
V_84 -> V_95 . V_103 = 8 ;
V_84 -> V_95 . V_104 = 48 ;
V_84 -> V_95 . V_105 = 8 ;
V_84 -> V_95 . V_106 = 56 ;
V_84 -> V_95 . V_107 = 8 ;
F_67 ( V_85 , V_108 ) ;
V_85 >>= 8 ;
V_89 = & V_84 -> V_109 [ 0 ] ;
V_89 -> V_110 = 0 ;
V_89 -> V_111 = 0 ;
V_89 -> V_112 = 1 ;
V_89 -> V_113 = 256 ;
V_87 = V_85 ;
V_85 >>= 16 ;
V_89 -> V_114 = V_85 + 1 ;
F_67 ( V_87 , V_89 -> V_114 ) ;
V_89 -> V_115 = V_87 ;
V_89 -> V_116 = 1 ;
V_89 -> V_117 = V_108 ;
V_89 -> V_118 = V_108 ;
V_89 -> V_119 = 25000 ;
V_89 -> V_120 = 25000 ;
V_89 -> V_121 = 500000 ;
V_89 -> V_122 = 500000 ;
V_89 -> V_123 = 1500000 ;
V_89 -> V_124 = 1500000 ;
V_89 -> V_125 = 0x010101 ;
V_89 -> V_126 = V_127 ;
return 0 ;
}
static void * F_68 ( struct V_70 * V_71 , char * V_128 )
{
T_4 * V_129 ;
V_129 = F_69 ( 64 , V_130 ) ;
if ( ! V_129 ) {
F_70 ( L_1 ) ;
return NULL ;
}
return V_129 ;
}
static void F_71 ( void * V_131 )
{
F_72 ( V_131 ) ;
}
static void * F_73 ( struct V_70 * V_71 , void * V_131 ,
T_5 V_132 , T_6 * V_133 )
{
return F_74 ( V_131 , V_132 ) ;
}
static void F_75 ( void * V_131 , void * V_134 ,
T_6 V_133 )
{
F_76 ( V_134 , V_131 ) ;
}
static int F_77 ( struct V_49 * V_49 )
{
struct V_70 * V_71 ;
int V_135 ;
V_71 = F_78 ( 0 ) ;
if ( ! V_71 )
return - V_72 ;
V_71 -> V_33 = V_49 -> V_33 ;
memcpy ( V_71 -> V_128 , V_49 -> V_136 , V_137 ) ;
V_71 -> V_138 = & V_139 ;
V_135 = F_79 ( V_71 ) ;
if ( V_135 ) {
F_53 ( V_71 ) ;
return V_135 ;
}
V_49 -> V_140 = V_71 ;
return 0 ;
}
static void F_80 ( struct V_49 * V_49 )
{
F_81 ( V_49 -> V_140 ) ;
}
static int F_77 ( struct V_49 * V_49 )
{
F_70 ( L_2 ) ;
return - V_7 ;
}
static void F_80 ( struct V_49 * V_49 ) {}
static void F_82 ( struct V_49 * V_49 )
{
F_83 ( & V_49 -> V_141 ) ;
if ( V_142 )
F_80 ( V_49 ) ;
else
F_84 ( V_49 -> V_143 ) ;
F_85 ( V_49 -> V_33 ) ;
if ( V_10 == V_12 )
F_86 ( & V_49 -> V_144 ) ;
if ( ! V_142 )
F_87 ( V_49 -> V_143 ) ;
F_54 ( V_49 ) ;
F_53 ( V_49 ) ;
}
static int F_88 ( struct V_145 * V_146 , T_7 V_147 )
{
return 0 ;
}
static void F_89 ( struct V_148 * V_143 , T_7 V_147 )
{
}
static int F_90 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_66 , V_149 ;
V_17 -> V_24 = F_91 ( V_17 -> V_21 * sizeof( * V_23 ) , V_150 ) ;
if ( ! V_17 -> V_24 )
return - V_72 ;
V_149 = F_92 ( V_17 -> V_21 , V_151 ) / V_151 ;
V_17 -> V_19 = F_91 ( V_149 * sizeof( unsigned long ) , V_150 ) ;
if ( ! V_17 -> V_19 ) {
F_53 ( V_17 -> V_24 ) ;
return - V_72 ;
}
for ( V_66 = 0 ; V_66 < V_17 -> V_21 ; V_66 ++ ) {
V_23 = & V_17 -> V_24 [ V_66 ] ;
F_22 ( & V_23 -> V_141 ) ;
V_23 -> V_152 . V_153 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static int F_93 ( struct V_49 * V_49 )
{
V_49 -> V_53 = F_91 ( V_154 * sizeof( struct V_16 ) ,
V_150 ) ;
if ( ! V_49 -> V_53 )
return - V_72 ;
V_49 -> V_51 = 0 ;
V_49 -> V_21 = V_127 ;
return 0 ;
}
static int F_94 ( struct V_49 * V_49 )
{
struct V_16 * V_17 ;
int V_66 , V_5 = 0 ;
for ( V_66 = 0 ; V_66 < V_154 ; V_66 ++ ) {
V_17 = & V_49 -> V_53 [ V_66 ] ;
F_48 ( V_49 , V_17 ) ;
V_5 = F_90 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_49 -> V_51 ++ ;
}
return 0 ;
}
static int F_95 ( struct V_49 * V_49 )
{
struct V_148 * V_143 ;
T_3 V_85 ;
V_143 = V_49 -> V_143 = F_96 ( 1 , V_155 ) ;
if ( ! V_143 )
return - V_72 ;
V_85 = V_86 * 1024 * 1024 * 1024ULL ;
F_97 ( V_143 , V_85 >> 9 ) ;
V_143 -> V_38 |= V_156 | V_157 ;
V_143 -> V_158 = V_159 ;
V_143 -> V_160 = V_49 -> V_50 ;
V_143 -> V_161 = & V_162 ;
V_143 -> V_163 = V_49 ;
V_143 -> V_164 = V_49 -> V_33 ;
strncpy ( V_143 -> V_136 , V_49 -> V_136 , V_137 ) ;
F_98 ( V_143 ) ;
return 0 ;
}
static int F_99 ( void )
{
struct V_49 * V_49 ;
int V_135 ;
V_49 = F_100 ( sizeof( * V_49 ) , V_150 , V_155 ) ;
if ( ! V_49 ) {
V_135 = - V_72 ;
goto V_165;
}
F_101 ( & V_49 -> V_166 ) ;
if ( V_10 == V_12 && V_167 )
V_154 = V_168 ;
V_135 = F_93 ( V_49 ) ;
if ( V_135 )
goto V_169;
if ( V_10 == V_12 ) {
V_49 -> V_144 . V_138 = & V_170 ;
V_49 -> V_144 . V_171 = V_154 ;
V_49 -> V_144 . V_21 = V_127 ;
V_49 -> V_144 . V_172 = V_155 ;
V_49 -> V_144 . V_173 = sizeof( struct V_22 ) ;
V_49 -> V_144 . V_38 = V_174 ;
V_49 -> V_144 . V_63 = V_49 ;
V_135 = F_102 ( & V_49 -> V_144 ) ;
if ( V_135 )
goto V_175;
V_49 -> V_33 = F_103 ( & V_49 -> V_144 ) ;
if ( F_61 ( V_49 -> V_33 ) ) {
V_135 = - V_72 ;
goto V_176;
}
} else if ( V_10 == V_11 ) {
V_49 -> V_33 = F_104 ( V_150 , V_155 ) ;
if ( ! V_49 -> V_33 ) {
V_135 = - V_72 ;
goto V_175;
}
F_105 ( V_49 -> V_33 , F_39 ) ;
V_135 = F_94 ( V_49 ) ;
if ( V_135 )
goto V_177;
} else {
V_49 -> V_33 = F_106 ( F_42 , & V_49 -> V_166 , V_155 ) ;
if ( ! V_49 -> V_33 ) {
V_135 = - V_72 ;
goto V_175;
}
F_107 ( V_49 -> V_33 , F_40 ) ;
F_108 ( V_49 -> V_33 , F_32 ) ;
V_135 = F_94 ( V_49 ) ;
if ( V_135 )
goto V_177;
}
V_49 -> V_33 -> V_54 = V_49 ;
F_109 ( V_178 , V_49 -> V_33 ) ;
F_110 ( V_179 , V_49 -> V_33 ) ;
F_111 ( & V_166 ) ;
V_49 -> V_50 = V_180 ++ ;
F_112 ( & V_166 ) ;
F_113 ( V_49 -> V_33 , V_108 ) ;
F_114 ( V_49 -> V_33 , V_108 ) ;
sprintf ( V_49 -> V_136 , L_3 , V_49 -> V_50 ) ;
if ( V_142 )
V_135 = F_77 ( V_49 ) ;
else
V_135 = F_95 ( V_49 ) ;
if ( V_135 )
goto V_177;
F_111 ( & V_166 ) ;
F_115 ( & V_49 -> V_141 , & V_181 ) ;
F_112 ( & V_166 ) ;
return 0 ;
V_177:
F_85 ( V_49 -> V_33 ) ;
V_176:
if ( V_10 == V_12 )
F_86 ( & V_49 -> V_144 ) ;
V_175:
F_54 ( V_49 ) ;
V_169:
F_53 ( V_49 ) ;
V_165:
return V_135 ;
}
static int T_8 F_116 ( void )
{
int V_5 = 0 ;
unsigned int V_66 ;
struct V_49 * V_49 ;
if ( V_108 > V_182 ) {
F_117 ( L_4 ) ;
F_117 ( L_5 , V_182 ) ;
V_108 = V_182 ;
}
if ( V_142 && V_108 != 4096 ) {
F_117 ( L_6 ) ;
F_117 ( L_7 ) ;
V_108 = 4096 ;
}
if ( V_142 && V_10 != V_12 ) {
F_117 ( L_8 ) ;
F_117 ( L_9 ) ;
V_10 = V_12 ;
}
if ( V_10 == V_12 && V_167 ) {
if ( V_154 < V_168 ) {
F_117 ( L_10 ,
V_168 ) ;
V_154 = V_168 ;
}
} else if ( V_154 > V_52 )
V_154 = V_52 ;
else if ( ! V_154 )
V_154 = 1 ;
F_118 ( & V_166 ) ;
V_159 = F_119 ( 0 , L_11 ) ;
if ( V_159 < 0 )
return V_159 ;
if ( V_142 ) {
V_130 = F_120 ( L_12 , 64 * sizeof( V_183 ) ,
0 , 0 , NULL ) ;
if ( ! V_130 ) {
F_70 ( L_13 ) ;
V_5 = - V_72 ;
goto V_184;
}
}
for ( V_66 = 0 ; V_66 < V_185 ; V_66 ++ ) {
V_5 = F_99 () ;
if ( V_5 )
goto V_186;
}
F_121 ( L_14 ) ;
return 0 ;
V_186:
while ( ! F_122 ( & V_181 ) ) {
V_49 = F_123 ( V_181 . V_153 , struct V_49 , V_141 ) ;
F_82 ( V_49 ) ;
}
F_124 ( V_130 ) ;
V_184:
F_125 ( V_159 , L_11 ) ;
return V_5 ;
}
static void T_9 F_126 ( void )
{
struct V_49 * V_49 ;
F_125 ( V_159 , L_11 ) ;
F_111 ( & V_166 ) ;
while ( ! F_122 ( & V_181 ) ) {
V_49 = F_123 ( V_181 . V_153 , struct V_49 , V_141 ) ;
F_82 ( V_49 ) ;
}
F_112 ( & V_166 ) ;
F_124 ( V_130 ) ;
}
