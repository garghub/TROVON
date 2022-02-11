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
F_35 ( V_23 -> V_34 ) ;
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
static struct V_16 * F_37 ( struct V_48 * V_48 )
{
int V_49 = 0 ;
if ( V_48 -> V_50 != 1 )
V_49 = F_38 () / ( ( V_51 + V_48 -> V_50 - 1 ) / V_48 -> V_50 ) ;
return & V_48 -> V_52 [ V_49 ] ;
}
static T_2 F_39 ( struct V_32 * V_33 , struct V_37 * V_37 )
{
struct V_48 * V_48 = V_33 -> V_53 ;
struct V_16 * V_17 = F_37 ( V_48 ) ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_17 , 1 ) ;
V_23 -> V_37 = V_37 ;
F_34 ( V_23 ) ;
return V_54 ;
}
static int F_40 ( struct V_32 * V_33 , struct V_45 * V_55 )
{
struct V_48 * V_48 = V_33 -> V_53 ;
struct V_16 * V_17 = F_37 ( V_48 ) ;
struct V_22 * V_23 ;
V_23 = F_15 ( V_17 , 0 ) ;
if ( V_23 ) {
V_23 -> V_34 = V_55 ;
V_55 -> V_46 = V_23 ;
return V_56 ;
}
F_41 ( V_33 ) ;
return V_57 ;
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
static int F_46 ( struct V_58 * V_59 ,
const struct V_60 * V_61 )
{
struct V_22 * V_23 = F_33 ( V_61 -> V_34 ) ;
F_47 ( V_59 -> V_38 & V_62 ) ;
if ( V_13 == V_15 ) {
F_14 ( & V_23 -> V_25 , V_26 , V_27 ) ;
V_23 -> V_25 . V_28 = V_29 ;
}
V_23 -> V_34 = V_61 -> V_34 ;
V_23 -> V_17 = V_59 -> V_63 ;
F_48 ( V_61 -> V_34 ) ;
F_34 ( V_23 ) ;
return V_64 ;
}
static void F_49 ( struct V_48 * V_48 , struct V_16 * V_17 )
{
F_50 ( ! V_48 ) ;
F_50 ( ! V_17 ) ;
F_51 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_48 -> V_21 ;
}
static int F_52 ( struct V_58 * V_59 , void * V_65 ,
unsigned int V_49 )
{
struct V_48 * V_48 = V_65 ;
struct V_16 * V_17 = & V_48 -> V_52 [ V_49 ] ;
V_59 -> V_63 = V_17 ;
F_49 ( V_48 , V_17 ) ;
V_48 -> V_50 ++ ;
return 0 ;
}
static void F_53 ( struct V_16 * V_17 )
{
F_54 ( V_17 -> V_19 ) ;
F_54 ( V_17 -> V_24 ) ;
}
static void F_55 ( struct V_48 * V_48 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_48 -> V_50 ; V_66 ++ )
F_53 ( & V_48 -> V_52 [ V_66 ] ) ;
F_54 ( V_48 -> V_52 ) ;
}
static void F_56 ( struct V_45 * V_34 , int error )
{
struct V_67 * V_68 = V_34 -> V_69 ;
V_68 -> error = error ;
F_57 ( V_68 ) ;
F_58 ( V_34 ) ;
}
static int F_59 ( struct V_70 * V_71 , struct V_67 * V_68 )
{
struct V_32 * V_33 = V_71 -> V_33 ;
struct V_45 * V_34 ;
struct V_37 * V_37 = V_68 -> V_37 ;
V_34 = F_60 ( V_33 ,
F_61 ( F_62 ( V_37 ) ) ? V_72 : V_73 , 0 ) ;
if ( F_63 ( V_34 ) )
return - V_74 ;
F_64 ( V_34 , V_37 ) ;
V_34 -> V_69 = V_68 ;
F_65 ( V_33 , NULL , V_34 , 0 , F_56 ) ;
return 0 ;
}
static int F_66 ( struct V_70 * V_71 , struct V_75 * V_76 )
{
T_3 V_77 = V_78 * 1024 * 1024 * 1024ULL ;
T_3 V_79 ;
struct V_80 * V_81 ;
V_76 -> V_82 = 0x1 ;
V_76 -> V_83 = 0 ;
V_76 -> V_84 = 0x2 ;
V_76 -> V_85 = 0x1 ;
V_76 -> V_86 . V_87 = 0 ;
V_76 -> V_86 . V_88 = 16 ;
V_76 -> V_86 . V_89 = 16 ;
V_76 -> V_86 . V_90 = 16 ;
V_76 -> V_86 . V_91 = 32 ;
V_76 -> V_86 . V_92 = 8 ;
V_76 -> V_86 . V_93 = 40 ;
V_76 -> V_86 . V_94 = 8 ;
V_76 -> V_86 . V_95 = 48 ;
V_76 -> V_86 . V_96 = 8 ;
V_76 -> V_86 . V_97 = 56 ;
V_76 -> V_86 . V_98 = 8 ;
F_67 ( V_77 , V_99 ) ;
V_77 >>= 8 ;
V_81 = & V_76 -> V_81 ;
V_81 -> V_100 = 0 ;
V_81 -> V_101 = 0 ;
V_81 -> V_102 = 1 ;
V_81 -> V_103 = 256 ;
V_79 = V_77 ;
V_77 >>= 16 ;
V_81 -> V_104 = V_77 + 1 ;
F_67 ( V_79 , V_81 -> V_104 ) ;
V_81 -> V_105 = V_79 ;
V_81 -> V_106 = 1 ;
V_81 -> V_107 = V_99 ;
V_81 -> V_108 = V_99 ;
V_81 -> V_109 = 25000 ;
V_81 -> V_110 = 25000 ;
V_81 -> V_111 = 500000 ;
V_81 -> V_112 = 500000 ;
V_81 -> V_113 = 1500000 ;
V_81 -> V_114 = 1500000 ;
V_81 -> V_115 = 0x010101 ;
V_81 -> V_116 = V_117 ;
return 0 ;
}
static void * F_68 ( struct V_70 * V_71 , char * V_118 )
{
T_4 * V_119 ;
V_119 = F_69 ( 64 , V_120 ) ;
if ( ! V_119 ) {
F_70 ( L_1 ) ;
return NULL ;
}
return V_119 ;
}
static void F_71 ( void * V_121 )
{
F_72 ( V_121 ) ;
}
static void * F_73 ( struct V_70 * V_71 , void * V_121 ,
T_5 V_122 , T_6 * V_123 )
{
return F_74 ( V_121 , V_122 ) ;
}
static void F_75 ( void * V_121 , void * V_124 ,
T_6 V_123 )
{
F_76 ( V_124 , V_121 ) ;
}
static int F_77 ( struct V_48 * V_48 )
{
struct V_70 * V_71 ;
int V_125 ;
V_71 = F_78 ( 0 ) ;
if ( ! V_71 )
return - V_74 ;
V_71 -> V_33 = V_48 -> V_33 ;
memcpy ( V_71 -> V_118 , V_48 -> V_126 , V_127 ) ;
V_71 -> V_128 = & V_129 ;
V_125 = F_79 ( V_71 ) ;
if ( V_125 ) {
F_54 ( V_71 ) ;
return V_125 ;
}
V_48 -> V_130 = V_71 ;
return 0 ;
}
static void F_80 ( struct V_48 * V_48 )
{
F_81 ( V_48 -> V_130 ) ;
}
static int F_77 ( struct V_48 * V_48 )
{
F_70 ( L_2 ) ;
return - V_7 ;
}
static void F_80 ( struct V_48 * V_48 ) {}
static void F_82 ( struct V_48 * V_48 )
{
F_83 ( & V_48 -> V_131 ) ;
if ( V_132 )
F_80 ( V_48 ) ;
else
F_84 ( V_48 -> V_133 ) ;
F_85 ( V_48 -> V_33 ) ;
if ( V_10 == V_12 )
F_86 ( & V_48 -> V_134 ) ;
if ( ! V_132 )
F_87 ( V_48 -> V_133 ) ;
F_55 ( V_48 ) ;
F_54 ( V_48 ) ;
}
static int F_88 ( struct V_135 * V_136 , T_7 V_137 )
{
return 0 ;
}
static void F_89 ( struct V_138 * V_133 , T_7 V_137 )
{
}
static int F_90 ( struct V_16 * V_17 )
{
struct V_22 * V_23 ;
int V_66 , V_139 ;
V_17 -> V_24 = F_91 ( V_17 -> V_21 * sizeof( * V_23 ) , V_140 ) ;
if ( ! V_17 -> V_24 )
return - V_74 ;
V_139 = F_92 ( V_17 -> V_21 , V_141 ) / V_141 ;
V_17 -> V_19 = F_91 ( V_139 * sizeof( unsigned long ) , V_140 ) ;
if ( ! V_17 -> V_19 ) {
F_54 ( V_17 -> V_24 ) ;
return - V_74 ;
}
for ( V_66 = 0 ; V_66 < V_17 -> V_21 ; V_66 ++ ) {
V_23 = & V_17 -> V_24 [ V_66 ] ;
F_22 ( & V_23 -> V_131 ) ;
V_23 -> V_142 . V_143 = NULL ;
V_23 -> V_18 = - 1U ;
}
return 0 ;
}
static int F_93 ( struct V_48 * V_48 )
{
V_48 -> V_52 = F_91 ( V_144 * sizeof( struct V_16 ) ,
V_140 ) ;
if ( ! V_48 -> V_52 )
return - V_74 ;
V_48 -> V_50 = 0 ;
V_48 -> V_21 = V_117 ;
return 0 ;
}
static int F_94 ( struct V_48 * V_48 )
{
struct V_16 * V_17 ;
int V_66 , V_5 = 0 ;
for ( V_66 = 0 ; V_66 < V_144 ; V_66 ++ ) {
V_17 = & V_48 -> V_52 [ V_66 ] ;
F_49 ( V_48 , V_17 ) ;
V_5 = F_90 ( V_17 ) ;
if ( V_5 )
return V_5 ;
V_48 -> V_50 ++ ;
}
return 0 ;
}
static int F_95 ( struct V_48 * V_48 )
{
struct V_138 * V_133 ;
T_3 V_77 ;
V_133 = V_48 -> V_133 = F_96 ( 1 , V_145 ) ;
if ( ! V_133 )
return - V_74 ;
V_77 = V_78 * 1024 * 1024 * 1024ULL ;
F_97 ( V_133 , V_77 >> 9 ) ;
V_133 -> V_38 |= V_146 | V_147 ;
V_133 -> V_148 = V_149 ;
V_133 -> V_150 = V_48 -> V_49 ;
V_133 -> V_151 = & V_152 ;
V_133 -> V_153 = V_48 ;
V_133 -> V_154 = V_48 -> V_33 ;
strncpy ( V_133 -> V_126 , V_48 -> V_126 , V_127 ) ;
F_98 ( V_133 ) ;
return 0 ;
}
static int F_99 ( void )
{
struct V_48 * V_48 ;
int V_125 ;
V_48 = F_100 ( sizeof( * V_48 ) , V_140 , V_145 ) ;
if ( ! V_48 ) {
V_125 = - V_74 ;
goto V_155;
}
F_101 ( & V_48 -> V_156 ) ;
if ( V_10 == V_12 && V_157 )
V_144 = V_158 ;
V_125 = F_93 ( V_48 ) ;
if ( V_125 )
goto V_159;
if ( V_10 == V_12 ) {
V_48 -> V_134 . V_128 = & V_160 ;
V_48 -> V_134 . V_161 = V_144 ;
V_48 -> V_134 . V_21 = V_117 ;
V_48 -> V_134 . V_162 = V_145 ;
V_48 -> V_134 . V_163 = sizeof( struct V_22 ) ;
V_48 -> V_134 . V_38 = V_164 ;
V_48 -> V_134 . V_63 = V_48 ;
if ( V_165 )
V_48 -> V_134 . V_38 |= V_62 ;
V_125 = F_102 ( & V_48 -> V_134 ) ;
if ( V_125 )
goto V_166;
V_48 -> V_33 = F_103 ( & V_48 -> V_134 ) ;
if ( F_63 ( V_48 -> V_33 ) ) {
V_125 = - V_74 ;
goto V_167;
}
} else if ( V_10 == V_11 ) {
V_48 -> V_33 = F_104 ( V_140 , V_145 ) ;
if ( ! V_48 -> V_33 ) {
V_125 = - V_74 ;
goto V_166;
}
F_105 ( V_48 -> V_33 , F_39 ) ;
V_125 = F_94 ( V_48 ) ;
if ( V_125 )
goto V_168;
} else {
V_48 -> V_33 = F_106 ( F_42 , & V_48 -> V_156 , V_145 ) ;
if ( ! V_48 -> V_33 ) {
V_125 = - V_74 ;
goto V_166;
}
F_107 ( V_48 -> V_33 , F_40 ) ;
F_108 ( V_48 -> V_33 , F_32 ) ;
V_125 = F_94 ( V_48 ) ;
if ( V_125 )
goto V_168;
}
V_48 -> V_33 -> V_53 = V_48 ;
F_109 ( V_169 , V_48 -> V_33 ) ;
F_110 ( V_170 , V_48 -> V_33 ) ;
F_111 ( & V_156 ) ;
V_48 -> V_49 = V_171 ++ ;
F_112 ( & V_156 ) ;
F_113 ( V_48 -> V_33 , V_99 ) ;
F_114 ( V_48 -> V_33 , V_99 ) ;
sprintf ( V_48 -> V_126 , L_3 , V_48 -> V_49 ) ;
if ( V_132 )
V_125 = F_77 ( V_48 ) ;
else
V_125 = F_95 ( V_48 ) ;
if ( V_125 )
goto V_168;
F_111 ( & V_156 ) ;
F_115 ( & V_48 -> V_131 , & V_172 ) ;
F_112 ( & V_156 ) ;
return 0 ;
V_168:
F_85 ( V_48 -> V_33 ) ;
V_167:
if ( V_10 == V_12 )
F_86 ( & V_48 -> V_134 ) ;
V_166:
F_55 ( V_48 ) ;
V_159:
F_54 ( V_48 ) ;
V_155:
return V_125 ;
}
static int T_8 F_116 ( void )
{
int V_5 = 0 ;
unsigned int V_66 ;
struct V_48 * V_48 ;
if ( V_99 > V_173 ) {
F_117 ( L_4 ) ;
F_117 ( L_5 , V_173 ) ;
V_99 = V_173 ;
}
if ( V_132 && V_99 != 4096 ) {
F_117 ( L_6 ) ;
F_117 ( L_7 ) ;
V_99 = 4096 ;
}
if ( V_132 && V_10 != V_12 ) {
F_117 ( L_8 ) ;
F_117 ( L_9 ) ;
V_10 = V_12 ;
}
if ( V_10 == V_12 && V_157 ) {
if ( V_144 < V_158 ) {
F_117 ( L_10 ,
V_158 ) ;
V_144 = V_158 ;
}
} else if ( V_144 > V_51 )
V_144 = V_51 ;
else if ( ! V_144 )
V_144 = 1 ;
F_118 ( & V_156 ) ;
V_149 = F_119 ( 0 , L_11 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_132 ) {
V_120 = F_120 ( L_12 , 64 * sizeof( V_174 ) ,
0 , 0 , NULL ) ;
if ( ! V_120 ) {
F_70 ( L_13 ) ;
V_5 = - V_74 ;
goto V_175;
}
}
for ( V_66 = 0 ; V_66 < V_176 ; V_66 ++ ) {
V_5 = F_99 () ;
if ( V_5 )
goto V_177;
}
F_121 ( L_14 ) ;
return 0 ;
V_177:
while ( ! F_122 ( & V_172 ) ) {
V_48 = F_123 ( V_172 . V_143 , struct V_48 , V_131 ) ;
F_82 ( V_48 ) ;
}
F_124 ( V_120 ) ;
V_175:
F_125 ( V_149 , L_11 ) ;
return V_5 ;
}
static void T_9 F_126 ( void )
{
struct V_48 * V_48 ;
F_125 ( V_149 , L_11 ) ;
F_111 ( & V_156 ) ;
while ( ! F_122 ( & V_172 ) ) {
V_48 = F_123 ( V_172 . V_143 , struct V_48 , V_131 ) ;
F_82 ( V_48 ) ;
}
F_112 ( & V_156 ) ;
F_124 ( V_120 ) ;
}
