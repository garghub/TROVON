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
F_21 ( V_23 -> V_34 , V_35 ) ;
return;
case V_36 :
F_22 ( & V_23 -> V_34 -> V_37 ) ;
F_23 ( V_23 -> V_34 , V_35 ) ;
break;
case V_11 :
F_24 ( V_23 -> V_38 ) ;
break;
}
F_12 ( V_23 ) ;
if ( V_10 == V_36 && F_25 ( V_33 ) ) {
unsigned long V_39 ;
F_26 ( V_33 -> V_40 , V_39 ) ;
F_27 ( V_33 ) ;
F_28 ( V_33 -> V_40 , V_39 ) ;
}
}
static enum V_41 V_29 ( struct V_42 * V_25 )
{
F_20 ( F_29 ( V_25 , struct V_22 , V_25 ) ) ;
return V_43 ;
}
static void F_30 ( struct V_22 * V_23 )
{
T_1 V_44 = V_45 ;
F_31 ( & V_23 -> V_25 , V_44 , V_27 ) ;
}
static void F_32 ( struct V_46 * V_34 )
{
if ( V_10 == V_12 )
F_20 ( F_33 ( V_34 ) ) ;
else
F_20 ( V_34 -> V_47 ) ;
}
static inline void F_34 ( struct V_22 * V_23 )
{
switch ( V_13 ) {
case V_48 :
switch ( V_10 ) {
case V_12 :
F_35 ( V_23 -> V_34 ) ;
break;
case V_36 :
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
static T_2 F_39 ( struct V_32 * V_33 , struct V_38 * V_38 )
{
struct V_49 * V_49 = V_33 -> V_54 ;
struct V_16 * V_17 = F_37 ( V_49 ) ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_17 , 1 ) ;
V_23 -> V_38 = V_38 ;
F_34 ( V_23 ) ;
return V_55 ;
}
static int F_40 ( struct V_32 * V_33 , struct V_46 * V_56 )
{
struct V_49 * V_49 = V_33 -> V_54 ;
struct V_16 * V_17 = F_37 ( V_49 ) ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_17 , 0 ) ;
if ( V_23 ) {
V_23 -> V_34 = V_56 ;
V_56 -> V_47 = V_23 ;
return V_57 ;
}
F_41 ( V_33 ) ;
return V_58 ;
}
static void F_42 ( struct V_32 * V_33 )
{
struct V_46 * V_34 ;
while ( ( V_34 = F_43 ( V_33 ) ) != NULL ) {
struct V_22 * V_23 = V_34 -> V_47 ;
F_44 ( V_33 -> V_40 ) ;
F_34 ( V_23 ) ;
F_45 ( V_33 -> V_40 ) ;
}
}
static T_3 F_46 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_22 * V_23 = F_33 ( V_62 -> V_34 ) ;
F_47 ( V_60 -> V_39 & V_63 ) ;
if ( V_13 == V_15 ) {
F_14 ( & V_23 -> V_25 , V_26 , V_27 ) ;
V_23 -> V_25 . V_28 = V_29 ;
}
V_23 -> V_34 = V_62 -> V_34 ;
V_23 -> V_17 = V_60 -> V_64 ;
F_48 ( V_62 -> V_34 ) ;
F_34 ( V_23 ) ;
return V_35 ;
}
static void F_49 ( struct V_16 * V_17 )
{
F_50 ( V_17 -> V_19 ) ;
F_50 ( V_17 -> V_24 ) ;
}
static void F_51 ( struct V_49 * V_49 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_49 -> V_51 ; V_65 ++ )
F_49 ( & V_49 -> V_53 [ V_65 ] ) ;
F_50 ( V_49 -> V_53 ) ;
}
static void F_52 ( struct V_46 * V_34 , T_3 V_66 )
{
struct V_67 * V_68 = V_34 -> V_69 ;
V_68 -> error = V_66 ? - V_70 : 0 ;
F_53 ( V_68 ) ;
F_54 ( V_34 ) ;
}
static int F_55 ( struct V_71 * V_72 , struct V_67 * V_68 )
{
struct V_32 * V_33 = V_72 -> V_33 ;
struct V_46 * V_34 ;
struct V_38 * V_38 = V_68 -> V_38 ;
V_34 = F_56 ( V_33 ,
F_57 ( F_58 ( V_38 ) ) ? V_73 : V_74 , 0 ) ;
if ( F_59 ( V_34 ) )
return - V_75 ;
F_60 ( V_34 , V_38 ) ;
V_34 -> V_69 = V_68 ;
F_61 ( V_33 , NULL , V_34 , 0 , F_52 ) ;
return 0 ;
}
static int F_62 ( struct V_71 * V_72 , struct V_76 * V_77 )
{
T_4 V_78 = V_79 * 1024 * 1024 * 1024ULL ;
T_4 V_80 ;
struct V_81 * V_82 ;
V_77 -> V_83 = 0x1 ;
V_77 -> V_84 = 0 ;
V_77 -> V_85 = 0x2 ;
V_77 -> V_86 = 0x1 ;
V_77 -> V_87 . V_88 = 0 ;
V_77 -> V_87 . V_89 = 16 ;
V_77 -> V_87 . V_90 = 16 ;
V_77 -> V_87 . V_91 = 16 ;
V_77 -> V_87 . V_92 = 32 ;
V_77 -> V_87 . V_93 = 8 ;
V_77 -> V_87 . V_94 = 40 ;
V_77 -> V_87 . V_95 = 8 ;
V_77 -> V_87 . V_96 = 48 ;
V_77 -> V_87 . V_97 = 8 ;
V_77 -> V_87 . V_98 = 56 ;
V_77 -> V_87 . V_99 = 8 ;
F_63 ( V_78 , V_100 ) ;
V_78 >>= 8 ;
V_82 = & V_77 -> V_82 ;
V_82 -> V_101 = 0 ;
V_82 -> V_102 = 0 ;
V_82 -> V_103 = 1 ;
V_82 -> V_104 = 256 ;
V_80 = V_78 ;
V_78 >>= 16 ;
V_82 -> V_105 = V_78 + 1 ;
F_63 ( V_80 , V_82 -> V_105 ) ;
V_82 -> V_106 = V_80 ;
V_82 -> V_107 = 1 ;
V_82 -> V_108 = V_100 ;
V_82 -> V_109 = V_100 ;
V_82 -> V_110 = 25000 ;
V_82 -> V_111 = 25000 ;
V_82 -> V_112 = 500000 ;
V_82 -> V_113 = 500000 ;
V_82 -> V_114 = 1500000 ;
V_82 -> V_115 = 1500000 ;
V_82 -> V_116 = 0x010101 ;
V_82 -> V_117 = V_118 ;
return 0 ;
}
static void * F_64 ( struct V_71 * V_72 , char * V_119 )
{
T_5 * V_120 ;
V_120 = F_65 ( 64 , V_121 ) ;
if ( ! V_120 ) {
F_66 ( L_1 ) ;
return NULL ;
}
return V_120 ;
}
static void F_67 ( void * V_122 )
{
F_68 ( V_122 ) ;
}
static void * F_69 ( struct V_71 * V_72 , void * V_122 ,
T_6 V_123 , T_7 * V_124 )
{
return F_70 ( V_122 , V_123 ) ;
}
static void F_71 ( void * V_122 , void * V_125 ,
T_7 V_124 )
{
F_72 ( V_125 , V_122 ) ;
}
static int F_73 ( struct V_49 * V_49 )
{
struct V_71 * V_72 ;
int V_126 ;
V_72 = F_74 ( 0 ) ;
if ( ! V_72 )
return - V_75 ;
V_72 -> V_33 = V_49 -> V_33 ;
memcpy ( V_72 -> V_119 , V_49 -> V_127 , V_128 ) ;
V_72 -> V_129 = & V_130 ;
V_126 = F_75 ( V_72 ) ;
if ( V_126 ) {
F_50 ( V_72 ) ;
return V_126 ;
}
V_49 -> V_131 = V_72 ;
return 0 ;
}
static void F_76 ( struct V_49 * V_49 )
{
F_77 ( V_49 -> V_131 ) ;
}
static int F_73 ( struct V_49 * V_49 )
{
F_66 ( L_2 ) ;
return - V_7 ;
}
static void F_76 ( struct V_49 * V_49 ) {}
static void F_78 ( struct V_49 * V_49 )
{
F_79 ( & V_49 -> V_132 ) ;
if ( V_133 )
F_76 ( V_49 ) ;
else
F_80 ( V_49 -> V_134 ) ;
F_81 ( V_49 -> V_33 ) ;
if ( V_10 == V_12 && V_49 -> V_135 == & V_49 -> V_136 )
F_82 ( V_49 -> V_135 ) ;
if ( ! V_133 )
F_83 ( V_49 -> V_134 ) ;
F_51 ( V_49 ) ;
F_50 ( V_49 ) ;
}
static int F_84 ( struct V_137 * V_138 , T_8 V_139 )
{
return 0 ;
}
static void F_85 ( struct V_140 * V_134 , T_8 V_139 )
{
}
static void F_86 ( struct V_49 * V_49 , struct V_16 * V_17 )
{
F_87 ( ! V_49 ) ;
F_87 ( ! V_17 ) ;
F_88 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_49 -> V_21 ;
}
static void F_89 ( struct V_49 * V_49 )
{
struct V_32 * V_33 = V_49 -> V_33 ;
struct V_59 * V_60 ;
struct V_16 * V_17 ;
int V_65 ;
F_90 (q, hctx, i) {
if ( ! V_60 -> V_141 || ! V_60 -> V_142 )
continue;
V_17 = & V_49 -> V_53 [ V_65 ] ;
V_60 -> V_64 = V_17 ;
F_86 ( V_49 , V_17 ) ;
V_49 -> V_51 ++ ;
}
}
static int F_91 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_65 , V_143 ;
V_17 -> V_24 = F_92 ( V_17 -> V_21 * sizeof( * V_23 ) , V_144 ) ;
if ( ! V_17 -> V_24 )
return - V_75 ;
V_143 = F_93 ( V_17 -> V_21 , V_145 ) / V_145 ;
V_17 -> V_19 = F_92 ( V_143 * sizeof( unsigned long ) , V_144 ) ;
if ( ! V_17 -> V_19 ) {
F_50 ( V_17 -> V_24 ) ;
return - V_75 ;
}
for ( V_65 = 0 ; V_65 < V_17 -> V_21 ; V_65 ++ ) {
V_23 = & V_17 -> V_24 [ V_65 ] ;
F_22 ( & V_23 -> V_132 ) ;
V_23 -> V_146 . V_147 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static int F_94 ( struct V_49 * V_49 )
{
V_49 -> V_53 = F_92 ( V_148 * sizeof( struct V_16 ) ,
V_144 ) ;
if ( ! V_49 -> V_53 )
return - V_75 ;
V_49 -> V_51 = 0 ;
V_49 -> V_21 = V_118 ;
return 0 ;
}
static int F_95 ( struct V_49 * V_49 )
{
struct V_16 * V_17 ;
int V_65 , V_5 = 0 ;
for ( V_65 = 0 ; V_65 < V_148 ; V_65 ++ ) {
V_17 = & V_49 -> V_53 [ V_65 ] ;
F_86 ( V_49 , V_17 ) ;
V_5 = F_91 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_49 -> V_51 ++ ;
}
return 0 ;
}
static int F_96 ( struct V_49 * V_49 )
{
struct V_140 * V_134 ;
T_4 V_78 ;
V_134 = V_49 -> V_134 = F_97 ( 1 , V_149 ) ;
if ( ! V_134 )
return - V_75 ;
V_78 = V_79 * 1024 * 1024 * 1024ULL ;
F_98 ( V_134 , V_78 >> 9 ) ;
V_134 -> V_39 |= V_150 | V_151 ;
V_134 -> V_152 = V_153 ;
V_134 -> V_154 = V_49 -> V_50 ;
V_134 -> V_155 = & V_156 ;
V_134 -> V_157 = V_49 ;
V_134 -> V_158 = V_49 -> V_33 ;
strncpy ( V_134 -> V_127 , V_49 -> V_127 , V_128 ) ;
F_99 ( V_134 ) ;
return 0 ;
}
static int F_100 ( struct V_159 * V_160 )
{
V_160 -> V_129 = & V_161 ;
V_160 -> V_162 = V_148 ;
V_160 -> V_21 = V_118 ;
V_160 -> V_163 = V_149 ;
V_160 -> V_164 = sizeof( struct V_22 ) ;
V_160 -> V_39 = V_165 ;
V_160 -> V_64 = NULL ;
if ( V_166 )
V_160 -> V_39 |= V_63 ;
return F_101 ( V_160 ) ;
}
static int F_102 ( void )
{
struct V_49 * V_49 ;
int V_126 ;
V_49 = F_103 ( sizeof( * V_49 ) , V_144 , V_149 ) ;
if ( ! V_49 ) {
V_126 = - V_75 ;
goto V_167;
}
F_104 ( & V_49 -> V_168 ) ;
if ( V_10 == V_12 && V_169 )
V_148 = V_170 ;
V_126 = F_94 ( V_49 ) ;
if ( V_126 )
goto V_171;
if ( V_10 == V_12 ) {
if ( V_172 ) {
V_49 -> V_135 = & V_135 ;
V_126 = 0 ;
} else {
V_49 -> V_135 = & V_49 -> V_136 ;
V_126 = F_100 ( V_49 -> V_135 ) ;
}
if ( V_126 )
goto V_173;
V_49 -> V_33 = F_105 ( V_49 -> V_135 ) ;
if ( F_59 ( V_49 -> V_33 ) ) {
V_126 = - V_75 ;
goto V_174;
}
F_89 ( V_49 ) ;
} else if ( V_10 == V_11 ) {
V_49 -> V_33 = F_106 ( V_144 , V_149 ) ;
if ( ! V_49 -> V_33 ) {
V_126 = - V_75 ;
goto V_173;
}
F_107 ( V_49 -> V_33 , F_39 ) ;
V_126 = F_95 ( V_49 ) ;
if ( V_126 )
goto V_175;
} else {
V_49 -> V_33 = F_108 ( F_42 , & V_49 -> V_168 , V_149 ) ;
if ( ! V_49 -> V_33 ) {
V_126 = - V_75 ;
goto V_173;
}
F_109 ( V_49 -> V_33 , F_40 ) ;
F_110 ( V_49 -> V_33 , F_32 ) ;
V_126 = F_95 ( V_49 ) ;
if ( V_126 )
goto V_175;
}
V_49 -> V_33 -> V_54 = V_49 ;
F_111 ( V_176 , V_49 -> V_33 ) ;
F_112 ( V_177 , V_49 -> V_33 ) ;
F_113 ( & V_168 ) ;
V_49 -> V_50 = V_178 ++ ;
F_114 ( & V_168 ) ;
F_115 ( V_49 -> V_33 , V_100 ) ;
F_116 ( V_49 -> V_33 , V_100 ) ;
sprintf ( V_49 -> V_127 , L_3 , V_49 -> V_50 ) ;
if ( V_133 )
V_126 = F_73 ( V_49 ) ;
else
V_126 = F_96 ( V_49 ) ;
if ( V_126 )
goto V_175;
F_113 ( & V_168 ) ;
F_117 ( & V_49 -> V_132 , & V_179 ) ;
F_114 ( & V_168 ) ;
return 0 ;
V_175:
F_81 ( V_49 -> V_33 ) ;
V_174:
if ( V_10 == V_12 && V_49 -> V_135 == & V_49 -> V_136 )
F_82 ( V_49 -> V_135 ) ;
V_173:
F_51 ( V_49 ) ;
V_171:
F_50 ( V_49 ) ;
V_167:
return V_126 ;
}
static int T_9 F_118 ( void )
{
int V_5 = 0 ;
unsigned int V_65 ;
struct V_49 * V_49 ;
if ( V_100 > V_180 ) {
F_119 ( L_4 ) ;
F_119 ( L_5 , V_180 ) ;
V_100 = V_180 ;
}
if ( V_133 && V_100 != 4096 ) {
F_119 ( L_6 ) ;
F_119 ( L_7 ) ;
V_100 = 4096 ;
}
if ( V_133 && V_10 != V_12 ) {
F_119 ( L_8 ) ;
F_119 ( L_9 ) ;
V_10 = V_12 ;
}
if ( V_10 == V_12 && V_169 ) {
if ( V_148 < V_170 ) {
F_119 ( L_10 ,
V_170 ) ;
V_148 = V_170 ;
}
} else if ( V_148 > V_52 )
V_148 = V_52 ;
else if ( ! V_148 )
V_148 = 1 ;
if ( V_10 == V_12 && V_172 ) {
V_5 = F_100 ( & V_135 ) ;
if ( V_5 )
return V_5 ;
}
F_120 ( & V_168 ) ;
V_153 = F_121 ( 0 , L_11 ) ;
if ( V_153 < 0 ) {
V_5 = V_153 ;
goto V_181;
}
if ( V_133 ) {
V_121 = F_122 ( L_12 , 64 * sizeof( V_182 ) ,
0 , 0 , NULL ) ;
if ( ! V_121 ) {
F_66 ( L_13 ) ;
V_5 = - V_75 ;
goto V_183;
}
}
for ( V_65 = 0 ; V_65 < V_184 ; V_65 ++ ) {
V_5 = F_102 () ;
if ( V_5 )
goto V_185;
}
F_123 ( L_14 ) ;
return 0 ;
V_185:
while ( ! F_124 ( & V_179 ) ) {
V_49 = F_125 ( V_179 . V_147 , struct V_49 , V_132 ) ;
F_78 ( V_49 ) ;
}
F_126 ( V_121 ) ;
V_183:
F_127 ( V_153 , L_11 ) ;
V_181:
if ( V_10 == V_12 && V_172 )
F_82 ( & V_135 ) ;
return V_5 ;
}
static void T_10 F_128 ( void )
{
struct V_49 * V_49 ;
F_127 ( V_153 , L_11 ) ;
F_113 ( & V_168 ) ;
while ( ! F_124 ( & V_179 ) ) {
V_49 = F_125 ( V_179 . V_147 , struct V_49 , V_132 ) ;
F_78 ( V_49 ) ;
}
F_114 ( & V_168 ) ;
if ( V_10 == V_12 && V_172 )
F_82 ( & V_135 ) ;
F_126 ( V_121 ) ;
}
