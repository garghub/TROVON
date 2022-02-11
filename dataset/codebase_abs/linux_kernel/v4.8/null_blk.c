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
F_64 ( V_73 , error ) ;
F_65 ( V_34 ) ;
}
static int F_66 ( struct V_75 * V_76 , struct V_72 * V_73 )
{
struct V_32 * V_33 = V_76 -> V_33 ;
struct V_45 * V_34 ;
struct V_37 * V_37 = V_73 -> V_37 ;
V_34 = F_67 ( V_33 , F_68 ( V_37 ) , 0 ) ;
if ( F_69 ( V_34 ) )
return - V_77 ;
V_34 -> V_78 = V_79 ;
V_34 -> V_80 = V_37 -> V_81 . V_82 ;
V_34 -> V_83 = F_70 ( V_37 ) ;
if ( F_71 ( V_37 ) )
V_34 -> V_84 = F_72 ( V_33 , V_37 ) ;
V_34 -> V_85 = V_37 -> V_81 . V_86 ;
V_34 -> V_37 = V_34 -> V_87 = V_37 ;
V_34 -> V_74 = V_73 ;
F_73 ( V_33 , NULL , V_34 , 0 , F_63 ) ;
return 0 ;
}
static int F_74 ( struct V_75 * V_76 , struct V_88 * V_89 )
{
T_3 V_90 = V_91 * 1024 * 1024 * 1024ULL ;
T_3 V_92 ;
struct V_93 * V_94 ;
V_89 -> V_95 = 0x1 ;
V_89 -> V_96 = 0 ;
V_89 -> V_97 = 1 ;
V_89 -> V_98 = 0x2 ;
V_89 -> V_99 = 0x1 ;
V_89 -> V_100 . V_101 = 0 ;
V_89 -> V_100 . V_102 = 16 ;
V_89 -> V_100 . V_103 = 16 ;
V_89 -> V_100 . V_104 = 16 ;
V_89 -> V_100 . V_105 = 32 ;
V_89 -> V_100 . V_106 = 8 ;
V_89 -> V_100 . V_107 = 40 ;
V_89 -> V_100 . V_108 = 8 ;
V_89 -> V_100 . V_109 = 48 ;
V_89 -> V_100 . V_110 = 8 ;
V_89 -> V_100 . V_111 = 56 ;
V_89 -> V_100 . V_112 = 8 ;
F_75 ( V_90 , V_113 ) ;
V_90 >>= 8 ;
V_94 = & V_89 -> V_114 [ 0 ] ;
V_94 -> V_115 = 0 ;
V_94 -> V_116 = 0 ;
V_94 -> V_117 = 1 ;
V_94 -> V_118 = 256 ;
V_92 = V_90 ;
V_90 >>= 16 ;
V_94 -> V_119 = V_90 + 1 ;
F_75 ( V_92 , V_94 -> V_119 ) ;
V_94 -> V_120 = V_92 ;
V_94 -> V_121 = 1 ;
V_94 -> V_122 = V_113 ;
V_94 -> V_123 = V_113 ;
V_94 -> V_124 = 25000 ;
V_94 -> V_125 = 25000 ;
V_94 -> V_126 = 500000 ;
V_94 -> V_127 = 500000 ;
V_94 -> V_128 = 1500000 ;
V_94 -> V_129 = 1500000 ;
V_94 -> V_130 = 0x010101 ;
V_94 -> V_131 = V_132 ;
return 0 ;
}
static void * F_76 ( struct V_75 * V_76 , char * V_133 )
{
T_4 * V_134 ;
V_134 = F_77 ( 64 , V_135 ) ;
if ( ! V_134 ) {
F_78 ( L_1 ) ;
return NULL ;
}
return V_134 ;
}
static void F_79 ( void * V_136 )
{
F_80 ( V_136 ) ;
}
static void * F_81 ( struct V_75 * V_76 , void * V_136 ,
T_5 V_137 , T_6 * V_138 )
{
return F_82 ( V_136 , V_137 ) ;
}
static void F_83 ( void * V_136 , void * V_139 ,
T_6 V_138 )
{
F_84 ( V_139 , V_136 ) ;
}
static int F_85 ( struct V_140 * V_141 , T_7 V_142 )
{
return 0 ;
}
static void F_86 ( struct V_143 * V_70 , T_7 V_142 )
{
}
static int F_87 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_66 , V_144 ;
V_17 -> V_24 = F_88 ( V_17 -> V_21 * sizeof( * V_23 ) , V_145 ) ;
if ( ! V_17 -> V_24 )
return - V_77 ;
V_144 = F_89 ( V_17 -> V_21 , V_146 ) / V_146 ;
V_17 -> V_19 = F_88 ( V_144 * sizeof( unsigned long ) , V_145 ) ;
if ( ! V_17 -> V_19 ) {
F_54 ( V_17 -> V_24 ) ;
return - V_77 ;
}
for ( V_66 = 0 ; V_66 < V_17 -> V_21 ; V_66 ++ ) {
V_23 = & V_17 -> V_24 [ V_66 ] ;
F_22 ( & V_23 -> V_67 ) ;
V_23 -> V_147 . V_148 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static int F_90 ( struct V_49 * V_49 )
{
V_49 -> V_53 = F_88 ( V_149 * sizeof( struct V_16 ) ,
V_145 ) ;
if ( ! V_49 -> V_53 )
return - V_77 ;
V_49 -> V_51 = 0 ;
V_49 -> V_21 = V_132 ;
return 0 ;
}
static int F_91 ( struct V_49 * V_49 )
{
struct V_16 * V_17 ;
int V_66 , V_5 = 0 ;
for ( V_66 = 0 ; V_66 < V_149 ; V_66 ++ ) {
V_17 = & V_49 -> V_53 [ V_66 ] ;
F_49 ( V_49 , V_17 ) ;
V_5 = F_87 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_49 -> V_51 ++ ;
}
return 0 ;
}
static int F_92 ( void )
{
struct V_143 * V_70 ;
struct V_49 * V_49 ;
T_3 V_90 ;
int V_150 ;
V_49 = F_93 ( sizeof( * V_49 ) , V_145 , V_151 ) ;
if ( ! V_49 ) {
V_150 = - V_77 ;
goto V_152;
}
F_94 ( & V_49 -> V_153 ) ;
if ( V_10 == V_12 && V_154 )
V_149 = V_155 ;
V_150 = F_90 ( V_49 ) ;
if ( V_150 )
goto V_156;
if ( V_10 == V_12 ) {
V_49 -> V_71 . V_157 = & V_158 ;
V_49 -> V_71 . V_159 = V_149 ;
V_49 -> V_71 . V_21 = V_132 ;
V_49 -> V_71 . V_160 = V_151 ;
V_49 -> V_71 . V_161 = sizeof( struct V_22 ) ;
V_49 -> V_71 . V_38 = V_162 ;
V_49 -> V_71 . V_63 = V_49 ;
V_150 = F_95 ( & V_49 -> V_71 ) ;
if ( V_150 )
goto V_163;
V_49 -> V_33 = F_96 ( & V_49 -> V_71 ) ;
if ( F_69 ( V_49 -> V_33 ) ) {
V_150 = - V_77 ;
goto V_164;
}
} else if ( V_10 == V_11 ) {
V_49 -> V_33 = F_97 ( V_145 , V_151 ) ;
if ( ! V_49 -> V_33 ) {
V_150 = - V_77 ;
goto V_163;
}
F_98 ( V_49 -> V_33 , F_40 ) ;
V_150 = F_91 ( V_49 ) ;
if ( V_150 )
goto V_165;
} else {
V_49 -> V_33 = F_99 ( F_43 , & V_49 -> V_153 , V_151 ) ;
if ( ! V_49 -> V_33 ) {
V_150 = - V_77 ;
goto V_163;
}
F_100 ( V_49 -> V_33 , F_41 ) ;
F_101 ( V_49 -> V_33 , F_33 ) ;
V_150 = F_91 ( V_49 ) ;
if ( V_150 )
goto V_165;
}
V_49 -> V_33 -> V_54 = V_49 ;
F_102 ( V_166 , V_49 -> V_33 ) ;
F_103 ( V_167 , V_49 -> V_33 ) ;
F_104 ( & V_153 ) ;
V_49 -> V_50 = V_168 ++ ;
F_105 ( & V_153 ) ;
F_106 ( V_49 -> V_33 , V_113 ) ;
F_107 ( V_49 -> V_33 , V_113 ) ;
sprintf ( V_49 -> V_69 , L_2 , V_49 -> V_50 ) ;
if ( V_68 ) {
V_150 = F_108 ( V_49 -> V_33 , V_49 -> V_69 ,
& V_169 ) ;
if ( V_150 )
goto V_165;
goto V_170;
}
V_70 = V_49 -> V_70 = F_109 ( 1 , V_151 ) ;
if ( ! V_70 ) {
V_150 = - V_77 ;
goto V_171;
}
V_90 = V_91 * 1024 * 1024 * 1024ULL ;
F_110 ( V_70 , V_90 >> 9 ) ;
V_70 -> V_38 |= V_172 | V_173 ;
V_70 -> V_174 = V_175 ;
V_70 -> V_176 = V_49 -> V_50 ;
V_70 -> V_177 = & V_178 ;
V_70 -> V_179 = V_49 ;
V_70 -> V_180 = V_49 -> V_33 ;
strncpy ( V_70 -> V_69 , V_49 -> V_69 , V_181 ) ;
F_111 ( V_70 ) ;
V_170:
F_104 ( & V_153 ) ;
F_112 ( & V_49 -> V_67 , & V_182 ) ;
F_105 ( & V_153 ) ;
return 0 ;
V_171:
if ( V_68 )
F_58 ( V_49 -> V_69 ) ;
V_165:
F_60 ( V_49 -> V_33 ) ;
V_164:
if ( V_10 == V_12 )
F_61 ( & V_49 -> V_71 ) ;
V_163:
F_55 ( V_49 ) ;
V_156:
F_54 ( V_49 ) ;
V_152:
return V_150 ;
}
static int T_8 F_113 ( void )
{
int V_5 = 0 ;
unsigned int V_66 ;
struct V_49 * V_49 ;
if ( V_113 > V_183 ) {
F_114 ( L_3 ) ;
F_114 ( L_4 , V_183 ) ;
V_113 = V_183 ;
}
if ( V_68 && V_113 != 4096 ) {
F_114 ( L_5 ) ;
F_114 ( L_6 ) ;
V_113 = 4096 ;
}
if ( V_68 && V_10 != V_12 ) {
F_114 ( L_7 ) ;
F_114 ( L_8 ) ;
V_10 = V_12 ;
}
if ( V_10 == V_12 && V_154 ) {
if ( V_149 < V_155 ) {
F_114 ( L_9 ,
V_155 ) ;
V_149 = V_155 ;
}
} else if ( V_149 > V_52 )
V_149 = V_52 ;
else if ( ! V_149 )
V_149 = 1 ;
F_115 ( & V_153 ) ;
V_175 = F_116 ( 0 , L_10 ) ;
if ( V_175 < 0 )
return V_175 ;
if ( V_68 ) {
V_135 = F_117 ( L_11 , 64 * sizeof( V_184 ) ,
0 , 0 , NULL ) ;
if ( ! V_135 ) {
F_78 ( L_12 ) ;
V_5 = - V_77 ;
goto V_185;
}
}
for ( V_66 = 0 ; V_66 < V_186 ; V_66 ++ ) {
V_5 = F_92 () ;
if ( V_5 )
goto V_187;
}
F_118 ( L_13 ) ;
return 0 ;
V_187:
while ( ! F_119 ( & V_182 ) ) {
V_49 = F_120 ( V_182 . V_148 , struct V_49 , V_67 ) ;
F_56 ( V_49 ) ;
}
F_121 ( V_135 ) ;
V_185:
F_122 ( V_175 , L_10 ) ;
return V_5 ;
}
static void T_9 F_123 ( void )
{
struct V_49 * V_49 ;
F_122 ( V_175 , L_10 ) ;
F_104 ( & V_153 ) ;
while ( ! F_119 ( & V_182 ) ) {
V_49 = F_120 ( V_182 . V_148 , struct V_49 , V_67 ) ;
F_56 ( V_49 ) ;
}
F_105 ( & V_153 ) ;
F_121 ( V_135 ) ;
}
