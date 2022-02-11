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
V_68 -> error = error ;
F_56 ( V_68 ) ;
F_57 ( V_34 ) ;
}
static int F_58 ( struct V_70 * V_71 , struct V_67 * V_68 )
{
struct V_32 * V_33 = V_71 -> V_33 ;
struct V_45 * V_34 ;
struct V_37 * V_37 = V_68 -> V_37 ;
V_34 = F_59 ( V_33 ,
F_60 ( F_61 ( V_37 ) ) ? V_72 : V_73 , 0 ) ;
if ( F_62 ( V_34 ) )
return - V_74 ;
V_34 -> V_75 = V_37 -> V_76 . V_77 ;
V_34 -> V_78 = F_63 ( V_37 ) ;
if ( F_64 ( V_37 ) )
V_34 -> V_79 = F_65 ( V_33 , V_37 ) ;
V_34 -> V_80 = V_37 -> V_76 . V_81 ;
V_34 -> V_37 = V_34 -> V_82 = V_37 ;
V_34 -> V_69 = V_68 ;
F_66 ( V_33 , NULL , V_34 , 0 , F_55 ) ;
return 0 ;
}
static int F_67 ( struct V_70 * V_71 , struct V_83 * V_84 )
{
T_3 V_85 = V_86 * 1024 * 1024 * 1024ULL ;
T_3 V_87 ;
struct V_88 * V_89 ;
V_84 -> V_90 = 0x1 ;
V_84 -> V_91 = 0 ;
V_84 -> V_92 = 0x2 ;
V_84 -> V_93 = 0x1 ;
V_84 -> V_94 . V_95 = 0 ;
V_84 -> V_94 . V_96 = 16 ;
V_84 -> V_94 . V_97 = 16 ;
V_84 -> V_94 . V_98 = 16 ;
V_84 -> V_94 . V_99 = 32 ;
V_84 -> V_94 . V_100 = 8 ;
V_84 -> V_94 . V_101 = 40 ;
V_84 -> V_94 . V_102 = 8 ;
V_84 -> V_94 . V_103 = 48 ;
V_84 -> V_94 . V_104 = 8 ;
V_84 -> V_94 . V_105 = 56 ;
V_84 -> V_94 . V_106 = 8 ;
F_68 ( V_85 , V_107 ) ;
V_85 >>= 8 ;
V_89 = & V_84 -> V_89 ;
V_89 -> V_108 = 0 ;
V_89 -> V_109 = 0 ;
V_89 -> V_110 = 1 ;
V_89 -> V_111 = 256 ;
V_87 = V_85 ;
V_85 >>= 16 ;
V_89 -> V_112 = V_85 + 1 ;
F_68 ( V_87 , V_89 -> V_112 ) ;
V_89 -> V_113 = V_87 ;
V_89 -> V_114 = 1 ;
V_89 -> V_115 = V_107 ;
V_89 -> V_116 = V_107 ;
V_89 -> V_117 = 25000 ;
V_89 -> V_118 = 25000 ;
V_89 -> V_119 = 500000 ;
V_89 -> V_120 = 500000 ;
V_89 -> V_121 = 1500000 ;
V_89 -> V_122 = 1500000 ;
V_89 -> V_123 = 0x010101 ;
V_89 -> V_124 = V_125 ;
return 0 ;
}
static void * F_69 ( struct V_70 * V_71 , char * V_126 )
{
T_4 * V_127 ;
V_127 = F_70 ( 64 , V_128 ) ;
if ( ! V_127 ) {
F_71 ( L_1 ) ;
return NULL ;
}
return V_127 ;
}
static void F_72 ( void * V_129 )
{
F_73 ( V_129 ) ;
}
static void * F_74 ( struct V_70 * V_71 , void * V_129 ,
T_5 V_130 , T_6 * V_131 )
{
return F_75 ( V_129 , V_130 ) ;
}
static void F_76 ( void * V_129 , void * V_132 ,
T_6 V_131 )
{
F_77 ( V_132 , V_129 ) ;
}
static int F_78 ( struct V_49 * V_49 )
{
struct V_70 * V_71 ;
int V_133 ;
V_71 = F_79 ( 0 ) ;
if ( ! V_71 )
return - V_74 ;
V_71 -> V_33 = V_49 -> V_33 ;
memcpy ( V_71 -> V_126 , V_49 -> V_134 , V_135 ) ;
V_71 -> V_136 = & V_137 ;
V_133 = F_80 ( V_71 ) ;
if ( V_133 ) {
F_53 ( V_71 ) ;
return V_133 ;
}
V_49 -> V_138 = V_71 ;
return 0 ;
}
static void F_81 ( struct V_49 * V_49 )
{
F_82 ( V_49 -> V_138 ) ;
}
static int F_78 ( struct V_49 * V_49 )
{
F_71 ( L_2 ) ;
return - V_7 ;
}
static void F_81 ( struct V_49 * V_49 ) {}
static void F_83 ( struct V_49 * V_49 )
{
F_84 ( & V_49 -> V_139 ) ;
if ( V_140 )
F_81 ( V_49 ) ;
else
F_85 ( V_49 -> V_141 ) ;
F_86 ( V_49 -> V_33 ) ;
if ( V_10 == V_12 )
F_87 ( & V_49 -> V_142 ) ;
if ( ! V_140 )
F_88 ( V_49 -> V_141 ) ;
F_54 ( V_49 ) ;
F_53 ( V_49 ) ;
}
static int F_89 ( struct V_143 * V_144 , T_7 V_145 )
{
return 0 ;
}
static void F_90 ( struct V_146 * V_141 , T_7 V_145 )
{
}
static int F_91 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_66 , V_147 ;
V_17 -> V_24 = F_92 ( V_17 -> V_21 * sizeof( * V_23 ) , V_148 ) ;
if ( ! V_17 -> V_24 )
return - V_74 ;
V_147 = F_93 ( V_17 -> V_21 , V_149 ) / V_149 ;
V_17 -> V_19 = F_92 ( V_147 * sizeof( unsigned long ) , V_148 ) ;
if ( ! V_17 -> V_19 ) {
F_53 ( V_17 -> V_24 ) ;
return - V_74 ;
}
for ( V_66 = 0 ; V_66 < V_17 -> V_21 ; V_66 ++ ) {
V_23 = & V_17 -> V_24 [ V_66 ] ;
F_22 ( & V_23 -> V_139 ) ;
V_23 -> V_150 . V_151 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static int F_94 ( struct V_49 * V_49 )
{
V_49 -> V_53 = F_92 ( V_152 * sizeof( struct V_16 ) ,
V_148 ) ;
if ( ! V_49 -> V_53 )
return - V_74 ;
V_49 -> V_51 = 0 ;
V_49 -> V_21 = V_125 ;
return 0 ;
}
static int F_95 ( struct V_49 * V_49 )
{
struct V_16 * V_17 ;
int V_66 , V_5 = 0 ;
for ( V_66 = 0 ; V_66 < V_152 ; V_66 ++ ) {
V_17 = & V_49 -> V_53 [ V_66 ] ;
F_48 ( V_49 , V_17 ) ;
V_5 = F_91 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_49 -> V_51 ++ ;
}
return 0 ;
}
static int F_96 ( struct V_49 * V_49 )
{
struct V_146 * V_141 ;
T_3 V_85 ;
V_141 = V_49 -> V_141 = F_97 ( 1 , V_153 ) ;
if ( ! V_141 )
return - V_74 ;
V_85 = V_86 * 1024 * 1024 * 1024ULL ;
F_98 ( V_141 , V_85 >> 9 ) ;
V_141 -> V_38 |= V_154 | V_155 ;
V_141 -> V_156 = V_157 ;
V_141 -> V_158 = V_49 -> V_50 ;
V_141 -> V_159 = & V_160 ;
V_141 -> V_161 = V_49 ;
V_141 -> V_162 = V_49 -> V_33 ;
strncpy ( V_141 -> V_134 , V_49 -> V_134 , V_135 ) ;
F_99 ( V_141 ) ;
return 0 ;
}
static int F_100 ( void )
{
struct V_49 * V_49 ;
int V_133 ;
V_49 = F_101 ( sizeof( * V_49 ) , V_148 , V_153 ) ;
if ( ! V_49 ) {
V_133 = - V_74 ;
goto V_163;
}
F_102 ( & V_49 -> V_164 ) ;
if ( V_10 == V_12 && V_165 )
V_152 = V_166 ;
V_133 = F_94 ( V_49 ) ;
if ( V_133 )
goto V_167;
if ( V_10 == V_12 ) {
V_49 -> V_142 . V_136 = & V_168 ;
V_49 -> V_142 . V_169 = V_152 ;
V_49 -> V_142 . V_21 = V_125 ;
V_49 -> V_142 . V_170 = V_153 ;
V_49 -> V_142 . V_171 = sizeof( struct V_22 ) ;
V_49 -> V_142 . V_38 = V_172 ;
V_49 -> V_142 . V_63 = V_49 ;
V_133 = F_103 ( & V_49 -> V_142 ) ;
if ( V_133 )
goto V_173;
V_49 -> V_33 = F_104 ( & V_49 -> V_142 ) ;
if ( F_62 ( V_49 -> V_33 ) ) {
V_133 = - V_74 ;
goto V_174;
}
} else if ( V_10 == V_11 ) {
V_49 -> V_33 = F_105 ( V_148 , V_153 ) ;
if ( ! V_49 -> V_33 ) {
V_133 = - V_74 ;
goto V_173;
}
F_106 ( V_49 -> V_33 , F_39 ) ;
V_133 = F_95 ( V_49 ) ;
if ( V_133 )
goto V_175;
} else {
V_49 -> V_33 = F_107 ( F_42 , & V_49 -> V_164 , V_153 ) ;
if ( ! V_49 -> V_33 ) {
V_133 = - V_74 ;
goto V_173;
}
F_108 ( V_49 -> V_33 , F_40 ) ;
F_109 ( V_49 -> V_33 , F_32 ) ;
V_133 = F_95 ( V_49 ) ;
if ( V_133 )
goto V_175;
}
V_49 -> V_33 -> V_54 = V_49 ;
F_110 ( V_176 , V_49 -> V_33 ) ;
F_111 ( V_177 , V_49 -> V_33 ) ;
F_112 ( & V_164 ) ;
V_49 -> V_50 = V_178 ++ ;
F_113 ( & V_164 ) ;
F_114 ( V_49 -> V_33 , V_107 ) ;
F_115 ( V_49 -> V_33 , V_107 ) ;
sprintf ( V_49 -> V_134 , L_3 , V_49 -> V_50 ) ;
if ( V_140 )
V_133 = F_78 ( V_49 ) ;
else
V_133 = F_96 ( V_49 ) ;
if ( V_133 )
goto V_175;
F_112 ( & V_164 ) ;
F_116 ( & V_49 -> V_139 , & V_179 ) ;
F_113 ( & V_164 ) ;
return 0 ;
V_175:
F_86 ( V_49 -> V_33 ) ;
V_174:
if ( V_10 == V_12 )
F_87 ( & V_49 -> V_142 ) ;
V_173:
F_54 ( V_49 ) ;
V_167:
F_53 ( V_49 ) ;
V_163:
return V_133 ;
}
static int T_8 F_117 ( void )
{
int V_5 = 0 ;
unsigned int V_66 ;
struct V_49 * V_49 ;
if ( V_107 > V_180 ) {
F_118 ( L_4 ) ;
F_118 ( L_5 , V_180 ) ;
V_107 = V_180 ;
}
if ( V_140 && V_107 != 4096 ) {
F_118 ( L_6 ) ;
F_118 ( L_7 ) ;
V_107 = 4096 ;
}
if ( V_140 && V_10 != V_12 ) {
F_118 ( L_8 ) ;
F_118 ( L_9 ) ;
V_10 = V_12 ;
}
if ( V_10 == V_12 && V_165 ) {
if ( V_152 < V_166 ) {
F_118 ( L_10 ,
V_166 ) ;
V_152 = V_166 ;
}
} else if ( V_152 > V_52 )
V_152 = V_52 ;
else if ( ! V_152 )
V_152 = 1 ;
F_119 ( & V_164 ) ;
V_157 = F_120 ( 0 , L_11 ) ;
if ( V_157 < 0 )
return V_157 ;
if ( V_140 ) {
V_128 = F_121 ( L_12 , 64 * sizeof( V_181 ) ,
0 , 0 , NULL ) ;
if ( ! V_128 ) {
F_71 ( L_13 ) ;
V_5 = - V_74 ;
goto V_182;
}
}
for ( V_66 = 0 ; V_66 < V_183 ; V_66 ++ ) {
V_5 = F_100 () ;
if ( V_5 )
goto V_184;
}
F_122 ( L_14 ) ;
return 0 ;
V_184:
while ( ! F_123 ( & V_179 ) ) {
V_49 = F_124 ( V_179 . V_151 , struct V_49 , V_139 ) ;
F_83 ( V_49 ) ;
}
F_125 ( V_128 ) ;
V_182:
F_126 ( V_157 , L_11 ) ;
return V_5 ;
}
static void T_9 F_127 ( void )
{
struct V_49 * V_49 ;
F_126 ( V_157 , L_11 ) ;
F_112 ( & V_164 ) ;
while ( ! F_123 ( & V_179 ) ) {
V_49 = F_124 ( V_179 . V_151 , struct V_49 , V_139 ) ;
F_83 ( V_49 ) ;
}
F_113 ( & V_164 ) ;
F_125 ( V_128 ) ;
}
