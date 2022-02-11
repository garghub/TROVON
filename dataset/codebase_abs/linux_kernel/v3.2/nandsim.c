static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , V_6 ;
if ( V_7 ) {
V_4 = F_2 ( V_7 , V_8 | V_9 | V_10 , 0600 ) ;
if ( F_3 ( V_4 ) )
return F_4 ( V_4 ) ;
if ( ! V_4 -> V_11 || ( ! V_4 -> V_11 -> V_12 && ! V_4 -> V_11 -> V_13 ) ) {
F_5 ( L_1 ) ;
V_6 = - V_14 ;
goto V_15;
}
if ( ! V_4 -> V_11 -> V_16 && ! V_4 -> V_11 -> V_17 ) {
F_5 ( L_2 ) ;
V_6 = - V_14 ;
goto V_15;
}
V_2 -> V_18 = F_6 ( V_2 -> V_19 . V_20 ) ;
if ( ! V_2 -> V_18 ) {
F_5 ( L_3 ) ;
V_6 = - V_21 ;
goto V_15;
}
V_2 -> V_22 = F_7 ( V_2 -> V_19 . V_23 , V_24 ) ;
if ( ! V_2 -> V_22 ) {
F_5 ( L_4 ) ;
V_6 = - V_21 ;
goto V_25;
}
V_2 -> V_4 = V_4 ;
return 0 ;
}
V_2 -> V_26 = F_8 ( V_2 -> V_19 . V_20 * sizeof( union V_27 ) ) ;
if ( ! V_2 -> V_26 ) {
F_5 ( L_5 ) ;
return - V_21 ;
}
for ( V_5 = 0 ; V_5 < V_2 -> V_19 . V_20 ; V_5 ++ ) {
V_2 -> V_26 [ V_5 ] . V_28 = NULL ;
}
V_2 -> V_29 = F_9 ( L_6 ,
V_2 -> V_19 . V_23 , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_29 ) {
F_5 ( L_7 ) ;
return - V_21 ;
}
return 0 ;
V_25:
F_10 ( V_2 -> V_18 ) ;
V_15:
F_11 ( V_4 , NULL ) ;
return V_6 ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_5 ;
if ( V_2 -> V_4 ) {
F_13 ( V_2 -> V_22 ) ;
F_10 ( V_2 -> V_18 ) ;
F_11 ( V_2 -> V_4 , NULL ) ;
return;
}
if ( V_2 -> V_26 ) {
for ( V_5 = 0 ; V_5 < V_2 -> V_19 . V_20 ; V_5 ++ ) {
if ( V_2 -> V_26 [ V_5 ] . V_28 )
F_14 ( V_2 -> V_29 ,
V_2 -> V_26 [ V_5 ] . V_28 ) ;
}
F_15 ( V_2 -> V_29 ) ;
F_10 ( V_2 -> V_26 ) ;
}
}
static char * F_16 ( int V_5 )
{
char V_30 [ 64 ] ;
sprintf ( V_30 , L_8 , V_5 ) ;
return F_17 ( V_30 , V_24 ) ;
}
static T_1 F_18 ( T_1 V_31 , T_2 V_32 )
{
F_19 ( V_31 , V_32 ) ;
return V_31 ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_1 * V_2 = V_36 -> V_37 ;
int V_5 , V_38 = 0 ;
T_1 V_39 ;
T_1 V_40 ;
if ( F_21 ( V_2 ) ) {
F_5 ( L_9 ) ;
return - V_41 ;
}
V_36 -> V_42 = 0 ;
V_2 -> V_43 = V_36 -> V_44 & V_45 ? 16 : 8 ;
V_2 -> V_19 . V_46 = V_34 -> V_47 ;
V_2 -> V_19 . V_48 = V_34 -> V_49 ;
V_2 -> V_19 . V_50 = V_34 -> V_51 ;
V_2 -> V_19 . V_52 = V_34 -> V_53 ;
V_2 -> V_19 . V_23 = V_2 -> V_19 . V_48 + V_2 -> V_19 . V_50 ;
V_2 -> V_19 . V_20 = F_18 ( V_2 -> V_19 . V_46 , V_2 -> V_19 . V_48 ) ;
V_2 -> V_19 . V_54 = V_2 -> V_19 . V_46 + ( T_1 ) V_2 -> V_19 . V_20 * V_2 -> V_19 . V_50 ;
V_2 -> V_19 . V_55 = F_22 ( V_2 -> V_19 . V_52 ) - 1 ;
V_2 -> V_19 . V_56 = V_36 -> V_57 ;
V_2 -> V_19 . V_58 = F_22 ( V_2 -> V_19 . V_50 ) - 1 ;
V_2 -> V_19 . V_59 = V_2 -> V_19 . V_52 / V_2 -> V_19 . V_48 ;
V_2 -> V_19 . V_60 = V_2 -> V_19 . V_52 + V_2 -> V_19 . V_50 * V_2 -> V_19 . V_59 ;
V_2 -> V_44 = 0 ;
if ( V_2 -> V_19 . V_48 == 256 ) {
V_2 -> V_44 |= V_61 ;
}
else if ( V_2 -> V_19 . V_48 == 512 ) {
V_2 -> V_44 |= ( V_62 | V_63 ) ;
if ( V_2 -> V_43 == 8 )
V_2 -> V_44 |= V_64 ;
} else if ( V_2 -> V_19 . V_48 == 2048 ) {
V_2 -> V_44 |= V_65 ;
} else if ( V_2 -> V_19 . V_48 == 4096 ) {
V_2 -> V_44 |= V_66 ;
} else {
F_5 ( L_10 , V_2 -> V_19 . V_48 ) ;
return - V_41 ;
}
if ( V_2 -> V_44 & V_67 ) {
if ( V_2 -> V_19 . V_46 <= ( 32 << 20 ) ) {
V_2 -> V_19 . V_68 = 3 ;
V_2 -> V_19 . V_69 = 2 ;
} else {
V_2 -> V_19 . V_68 = 4 ;
V_2 -> V_19 . V_69 = 3 ;
}
} else {
if ( V_2 -> V_19 . V_46 <= ( 128 << 20 ) ) {
V_2 -> V_19 . V_68 = 4 ;
V_2 -> V_19 . V_69 = 2 ;
} else {
V_2 -> V_19 . V_68 = 5 ;
V_2 -> V_19 . V_69 = 3 ;
}
}
if ( V_70 > F_23 ( V_2 -> V_71 ) ) {
F_5 ( L_11 ) ;
V_38 = - V_14 ;
goto error;
}
V_39 = V_2 -> V_19 . V_46 ;
V_40 = 0 ;
for ( V_5 = 0 ; V_5 < V_70 ; ++ V_5 ) {
T_1 V_72 = ( T_1 ) V_73 [ V_5 ] * V_2 -> V_19 . V_52 ;
if ( ! V_72 || V_72 > V_39 ) {
F_5 ( L_12 ) ;
V_38 = - V_14 ;
goto error;
}
V_2 -> V_71 [ V_5 ] . V_74 = F_16 ( V_5 ) ;
V_2 -> V_71 [ V_5 ] . V_75 = V_40 ;
V_2 -> V_71 [ V_5 ] . V_47 = V_72 ;
V_40 += V_2 -> V_71 [ V_5 ] . V_47 ;
V_39 -= V_2 -> V_71 [ V_5 ] . V_47 ;
}
V_2 -> V_76 = V_70 ;
if ( V_39 ) {
if ( V_70 + 1 > F_23 ( V_2 -> V_71 ) ) {
F_5 ( L_11 ) ;
V_38 = - V_14 ;
goto error;
}
V_2 -> V_71 [ V_5 ] . V_74 = F_16 ( V_5 ) ;
V_2 -> V_71 [ V_5 ] . V_75 = V_40 ;
V_2 -> V_71 [ V_5 ] . V_47 = V_39 ;
V_2 -> V_76 += 1 ;
}
for ( V_5 = 0 ; V_77 [ V_5 ] . V_74 != NULL ; V_5 ++ ) {
if ( V_78 != V_77 [ V_5 ] . V_79 )
continue;
if ( ! ( V_77 [ V_5 ] . V_44 & V_80 ) )
V_2 -> V_44 |= V_63 ;
}
if ( V_2 -> V_43 == 16 )
F_24 ( L_13 ) ;
F_25 ( L_14 ,
( unsigned long long ) V_2 -> V_19 . V_46 >> 20 ) ;
F_25 ( L_15 , V_2 -> V_19 . V_48 ) ;
F_25 ( L_16 , V_2 -> V_19 . V_50 ) ;
F_25 ( L_17 , V_2 -> V_19 . V_52 >> 10 ) ;
F_25 ( L_18 , V_2 -> V_19 . V_20 ) ;
F_25 ( L_19 , V_2 -> V_19 . V_59 ) ;
F_25 ( L_20 , V_2 -> V_43 ) ;
F_25 ( L_21 , V_2 -> V_19 . V_55 ) ;
F_25 ( L_22 , V_2 -> V_19 . V_56 ) ;
F_25 ( L_23 , V_2 -> V_19 . V_58 ) ;
F_25 ( L_24 ,
( unsigned long long ) V_2 -> V_19 . V_54 >> 10 ) ;
F_25 ( L_25 , V_2 -> V_19 . V_68 ) ;
F_25 ( L_26 , V_2 -> V_19 . V_69 ) ;
F_25 ( L_27 , V_2 -> V_44 ) ;
if ( ( V_38 = F_1 ( V_2 ) ) != 0 )
goto error;
V_2 -> V_30 . V_28 = F_7 ( V_2 -> V_19 . V_23 , V_24 ) ;
if ( ! V_2 -> V_30 . V_28 ) {
F_5 ( L_28 ,
V_2 -> V_19 . V_23 ) ;
V_38 = - V_21 ;
goto error;
}
memset ( V_2 -> V_30 . V_28 , 0xFF , V_2 -> V_19 . V_23 ) ;
return 0 ;
error:
F_12 ( V_2 ) ;
return V_38 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_30 . V_28 ) ;
F_12 ( V_2 ) ;
return;
}
static int F_27 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
char * V_81 ;
int V_82 ;
unsigned int V_83 ;
T_3 V_75 ;
if ( ! V_84 )
return 0 ;
V_81 = V_84 ;
do {
V_82 = ( * V_81 == '0' ? 1 : 0 ) ;
V_83 = F_28 ( V_81 , & V_81 , 0 ) ;
if ( ! V_82 && ! V_83 ) {
F_5 ( L_29 ) ;
return - V_14 ;
}
V_75 = V_83 * V_2 -> V_19 . V_52 ;
if ( V_34 -> V_85 ( V_34 , V_75 ) ) {
F_5 ( L_29 ) ;
return - V_14 ;
}
if ( * V_81 == ',' )
V_81 += 1 ;
} while ( * V_81 );
return 0 ;
}
static int F_29 ( void )
{
char * V_81 ;
int V_82 ;
unsigned int V_83 ;
unsigned int V_86 ;
struct V_87 * V_88 ;
if ( ! V_89 )
return 0 ;
V_81 = V_89 ;
do {
V_82 = ( * V_81 == '0' ? 1 : 0 ) ;
V_83 = F_28 ( V_81 , & V_81 , 0 ) ;
if ( ! V_82 && ! V_83 ) {
F_5 ( L_30 ) ;
return - V_14 ;
}
V_86 = 3 ;
if ( * V_81 == ':' ) {
V_81 += 1 ;
V_86 = F_28 ( V_81 , & V_81 , 0 ) ;
}
if ( * V_81 == ',' )
V_81 += 1 ;
V_88 = F_30 ( sizeof( * V_88 ) , V_24 ) ;
if ( ! V_88 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_88 -> V_83 = V_83 ;
V_88 -> V_86 = V_86 ;
F_31 ( & V_88 -> V_90 , & V_91 ) ;
} while ( * V_81 );
return 0 ;
}
static int F_32 ( unsigned int V_83 )
{
struct V_87 * V_88 ;
F_33 (wb, &weak_blocks, list)
if ( V_88 -> V_83 == V_83 ) {
if ( V_88 -> V_92 >= V_88 -> V_86 )
return 1 ;
V_88 -> V_92 += 1 ;
return 0 ;
}
return 0 ;
}
static int F_34 ( void )
{
char * V_81 ;
int V_82 ;
unsigned int V_93 ;
unsigned int V_94 ;
struct V_95 * V_96 ;
if ( ! V_97 )
return 0 ;
V_81 = V_97 ;
do {
V_82 = ( * V_81 == '0' ? 1 : 0 ) ;
V_93 = F_28 ( V_81 , & V_81 , 0 ) ;
if ( ! V_82 && ! V_93 ) {
F_5 ( L_32 ) ;
return - V_14 ;
}
V_94 = 3 ;
if ( * V_81 == ':' ) {
V_81 += 1 ;
V_94 = F_28 ( V_81 , & V_81 , 0 ) ;
}
if ( * V_81 == ',' )
V_81 += 1 ;
V_96 = F_30 ( sizeof( * V_96 ) , V_24 ) ;
if ( ! V_96 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_96 -> V_93 = V_93 ;
V_96 -> V_94 = V_94 ;
F_31 ( & V_96 -> V_90 , & V_98 ) ;
} while ( * V_81 );
return 0 ;
}
static int F_35 ( unsigned int V_93 )
{
struct V_95 * V_96 ;
F_33 (wp, &weak_pages, list)
if ( V_96 -> V_93 == V_93 ) {
if ( V_96 -> V_99 >= V_96 -> V_94 )
return 1 ;
V_96 -> V_99 += 1 ;
return 0 ;
}
return 0 ;
}
static int F_36 ( void )
{
char * V_100 ;
int V_82 ;
unsigned int V_93 ;
unsigned int V_101 ;
struct V_102 * V_103 ;
if ( ! V_104 )
return 0 ;
V_100 = V_104 ;
do {
V_82 = ( * V_100 == '0' ? 1 : 0 ) ;
V_93 = F_28 ( V_100 , & V_100 , 0 ) ;
if ( ! V_82 && ! V_93 ) {
F_5 ( L_33 ) ;
return - V_14 ;
}
V_101 = 3 ;
if ( * V_100 == ':' ) {
V_100 += 1 ;
V_101 = F_28 ( V_100 , & V_100 , 0 ) ;
}
if ( * V_100 == ',' )
V_100 += 1 ;
V_103 = F_30 ( sizeof( * V_103 ) , V_24 ) ;
if ( ! V_103 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_103 -> V_93 = V_93 ;
V_103 -> V_101 = V_101 ;
F_31 ( & V_103 -> V_90 , & V_105 ) ;
} while ( * V_100 );
return 0 ;
}
static int F_37 ( unsigned int V_93 )
{
struct V_102 * V_103 ;
F_33 (gp, &grave_pages, list)
if ( V_103 -> V_93 == V_93 ) {
if ( V_103 -> V_106 >= V_103 -> V_101 )
return 1 ;
V_103 -> V_106 += 1 ;
return 0 ;
}
return 0 ;
}
static void F_38 ( void )
{
struct V_107 * V_108 , * V_31 ;
F_39 (pos, n, &weak_blocks) {
F_40 ( V_108 ) ;
F_13 ( F_41 ( V_108 , struct V_87 , V_90 ) ) ;
}
F_39 (pos, n, &weak_pages) {
F_40 ( V_108 ) ;
F_13 ( F_41 ( V_108 , struct V_95 , V_90 ) ) ;
}
F_39 (pos, n, &grave_pages) {
F_40 ( V_108 ) ;
F_13 ( F_41 ( V_108 , struct V_102 , V_90 ) ) ;
}
F_13 ( V_109 ) ;
}
static int F_42 ( struct V_33 * V_34 )
{
T_4 V_110 ;
if ( ! V_111 )
return 0 ;
V_112 = F_18 ( V_34 -> V_47 , V_34 -> V_53 ) ;
V_110 = V_112 * sizeof( unsigned long ) ;
if ( V_110 / sizeof( unsigned long ) != V_112 ) {
F_5 ( L_34 ) ;
return - V_21 ;
}
V_109 = F_30 ( V_110 , V_24 ) ;
if ( ! V_109 ) {
F_5 ( L_34 ) ;
return - V_21 ;
}
return 0 ;
}
static void F_43 ( unsigned int V_83 )
{
unsigned long V_113 = - 1 , V_114 = 0 , V_115 ;
unsigned long V_116 [ 10 ] , V_117 [ 10 ] , V_118 = 0 ;
unsigned int V_5 ;
if ( ! V_109 )
return;
V_119 += 1 ;
if ( V_119 == 0 )
F_5 ( L_35 ) ;
V_109 [ V_83 ] += 1 ;
if ( V_109 [ V_83 ] == 0 )
F_5 ( L_36 , V_83 ) ;
V_120 += 1 ;
if ( V_120 < V_111 )
return;
V_120 = 0 ;
for ( V_5 = 0 ; V_5 < V_112 ; ++ V_5 ) {
unsigned long V_121 = V_109 [ V_5 ] ;
if ( V_121 < V_113 )
V_113 = V_121 ;
if ( V_121 > V_114 )
V_114 = V_121 ;
V_118 += V_121 ;
}
for ( V_5 = 0 ; V_5 < 9 ; ++ V_5 ) {
V_116 [ V_5 ] = 0 ;
V_117 [ V_5 ] = ( V_114 * ( V_5 + 1 ) + 5 ) / 10 ;
}
V_116 [ 9 ] = 0 ;
V_117 [ 9 ] = V_114 ;
for ( V_5 = 0 ; V_5 < V_112 ; ++ V_5 ) {
int V_32 ;
unsigned long V_121 = V_109 [ V_5 ] ;
for ( V_32 = 0 ; V_32 < 10 ; ++ V_32 )
if ( V_121 <= V_117 [ V_32 ] ) {
V_116 [ V_32 ] += 1 ;
break;
}
}
V_115 = V_118 / V_112 ;
F_44 ( L_37 ) ;
F_44 ( L_38 , V_118 ) ;
F_44 ( L_39 , V_112 ) ;
F_44 ( L_40 , V_115 ) ;
F_44 ( L_41 , V_114 ) ;
F_44 ( L_42 , V_113 ) ;
for ( V_5 = 0 ; V_5 < 10 ; ++ V_5 ) {
unsigned long V_122 = ( V_5 ? V_117 [ V_5 - 1 ] + 1 : 0 ) ;
if ( V_122 > V_117 [ V_5 ] )
continue;
F_44 ( L_43 ,
V_122 ,
V_117 [ V_5 ] ,
V_116 [ V_5 ] ) ;
}
F_44 ( L_44 ) ;
}
static char * F_45 ( T_2 V_123 )
{
switch ( F_46 ( V_123 ) ) {
case V_124 :
return L_45 ;
case V_125 :
return L_46 ;
case V_126 :
return L_47 ;
case V_127 :
return L_48 ;
case V_128 :
return L_49 ;
case V_129 :
return L_50 ;
case V_130 :
return L_51 ;
case V_131 :
return L_52 ;
case V_132 :
return L_53 ;
case V_133 :
return L_54 ;
case V_134 :
return L_55 ;
case V_135 :
return L_56 ;
case V_136 :
return L_57 ;
case V_137 :
return L_58 ;
case V_138 :
return L_59 ;
case V_139 :
return L_60 ;
case V_140 :
return L_61 ;
case V_141 :
return L_62 ;
case V_142 :
return L_63 ;
case V_143 :
return L_64 ;
case V_144 :
return L_65 ;
case V_145 :
return L_66 ;
case V_146 :
return L_67 ;
case V_147 :
return L_68 ;
case V_148 :
return L_69 ;
}
F_5 ( L_70 ) ;
return NULL ;
}
static int F_47 ( int V_149 )
{
switch ( V_149 ) {
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
return 0 ;
case V_163 :
default:
return 1 ;
}
}
static T_2 F_48 ( unsigned V_164 )
{
switch ( V_164 ) {
case V_150 :
return V_124 ;
case V_151 :
return V_125 ;
case V_153 :
return V_126 ;
case V_152 :
return V_128 ;
case V_154 :
return V_127 ;
case V_155 :
return V_129 ;
case V_156 :
return V_130 ;
case V_163 :
return V_131 ;
case V_157 :
return V_132 ;
case V_158 :
return V_133 ;
case V_159 :
return V_134 ;
case V_160 :
return V_135 ;
case V_161 :
return V_136 ;
case V_162 :
return V_137 ;
}
F_5 ( L_71 ) ;
return 0 ;
}
static inline void F_49 ( struct V_1 * V_2 , T_5 V_165 )
{
T_6 V_28 = ( T_6 ) V_165 ;
if ( V_2 -> V_166 . V_167 < ( V_2 -> V_19 . V_68 - V_2 -> V_19 . V_69 ) )
V_2 -> V_166 . V_168 |= ( V_28 << 8 * V_2 -> V_166 . V_167 ) ;
else {
V_2 -> V_166 . V_169 |= ( V_28 << 8 * ( V_2 -> V_166 . V_167 -
V_2 -> V_19 . V_68 +
V_2 -> V_19 . V_69 ) ) ;
}
return;
}
static inline void F_50 ( struct V_1 * V_2 , T_5 V_170 )
{
F_51 ( L_72 , F_45 ( V_147 ) ) ;
V_2 -> V_123 = V_147 ;
V_2 -> V_171 = V_148 ;
V_2 -> V_172 = NULL ;
V_2 -> V_173 = 0 ;
V_2 -> V_174 = 0 ;
V_2 -> V_166 . V_175 = 0 ;
V_2 -> V_166 . V_167 = 0 ;
V_2 -> V_166 . V_176 = 0 ;
V_2 -> V_166 . V_169 = 0 ;
V_2 -> V_166 . V_168 = 0 ;
V_2 -> V_166 . V_170 = V_170 ;
}
static int F_52 ( struct V_1 * V_2 , T_2 V_177 )
{
int V_178 = 0 ;
int V_5 , V_179 , V_180 = 0 ;
for ( V_5 = 0 ; V_5 < V_181 ; V_5 ++ ) {
int V_182 = 1 ;
if ( ! ( V_2 -> V_44 & V_183 [ V_5 ] . V_184 ) )
continue;
if ( V_177 ) {
if ( ! ( V_183 [ V_5 ] . V_185 [ V_2 -> V_173 ] & V_186 ) )
continue;
} else {
if ( F_46 ( V_2 -> V_123 ) != F_46 ( V_183 [ V_5 ] . V_185 [ V_2 -> V_173 ] ) )
continue;
}
for ( V_179 = 0 ; V_179 < V_2 -> V_173 ; V_179 ++ )
if ( F_46 ( V_183 [ V_5 ] . V_185 [ V_179 ] ) != F_46 ( V_2 -> V_187 [ V_179 ] )
&& ( V_2 -> V_44 & V_183 [ V_180 ] . V_184 ) ) {
V_182 = 0 ;
break;
}
if ( V_182 ) {
V_180 = V_5 ;
V_178 += 1 ;
}
}
if ( V_178 == 1 ) {
V_2 -> V_172 = & V_183 [ V_180 ] . V_185 [ 0 ] ;
if ( V_177 ) {
V_2 -> V_174 = V_2 -> V_173 - 1 ;
} else {
V_2 -> V_174 = V_2 -> V_173 ;
}
V_2 -> V_173 = 0 ;
V_2 -> V_123 = V_2 -> V_172 [ V_2 -> V_174 ] ;
V_2 -> V_171 = V_2 -> V_172 [ V_2 -> V_174 + 1 ] ;
F_51 ( L_73 ,
V_180 , F_45 ( V_2 -> V_123 ) , F_45 ( V_2 -> V_171 ) ) ;
return 0 ;
}
if ( V_178 == 0 ) {
if ( V_2 -> V_173 != 0 ) {
F_51 ( L_74 ,
F_45 ( V_2 -> V_123 ) ) ;
V_2 -> V_173 = 0 ;
return F_52 ( V_2 , 0 ) ;
}
F_51 ( L_75 ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return - 2 ;
}
if ( V_177 ) {
F_51 ( L_76 ) ;
return - 2 ;
}
F_51 ( L_77 ) ;
V_2 -> V_187 [ V_2 -> V_173 ++ ] = V_2 -> V_123 ;
return - 1 ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_188 ; V_5 ++ )
F_55 ( V_2 -> V_189 [ V_5 ] ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_3 * V_3 , T_4 V_167 , T_3 V_108 )
{
T_7 V_190 , V_191 , V_192 ;
struct V_193 * V_193 ;
struct V_194 * V_195 = V_3 -> V_196 ;
V_191 = V_108 >> V_197 ;
V_192 = ( V_108 + V_167 - 1 ) >> V_197 ;
if ( V_192 - V_191 + 1 > V_198 )
return - V_14 ;
V_2 -> V_188 = 0 ;
for ( V_190 = V_191 ; V_190 <= V_192 ; V_190 ++ ) {
V_193 = F_57 ( V_195 , V_190 ) ;
if ( V_193 == NULL ) {
V_193 = F_58 ( V_195 , V_190 , V_199 ) ;
if ( V_193 == NULL ) {
F_59 ( V_195 -> V_200 , 1 ) ;
V_193 = F_58 ( V_195 , V_190 , V_199 ) ;
}
if ( V_193 == NULL ) {
F_54 ( V_2 ) ;
return - V_21 ;
}
F_60 ( V_193 ) ;
}
V_2 -> V_189 [ V_2 -> V_188 ++ ] = V_193 ;
}
return 0 ;
}
static int F_61 ( void )
{
if ( V_201 -> V_202 & V_203 )
return 0 ;
V_201 -> V_202 |= V_203 ;
return 1 ;
}
static void F_62 ( int V_204 )
{
if ( V_204 )
V_201 -> V_202 &= ~ V_203 ;
}
static T_8 F_63 ( struct V_1 * V_2 , struct V_3 * V_3 , void * V_30 , T_4 V_167 , T_3 * V_108 )
{
T_9 V_205 ;
T_8 V_206 ;
int V_6 , V_204 ;
V_6 = F_56 ( V_2 , V_3 , V_167 , * V_108 ) ;
if ( V_6 )
return V_6 ;
V_205 = F_64 () ;
F_65 ( F_66 () ) ;
V_204 = F_61 () ;
V_206 = F_67 ( V_3 , ( char V_207 * ) V_30 , V_167 , V_108 ) ;
F_62 ( V_204 ) ;
F_65 ( V_205 ) ;
F_54 ( V_2 ) ;
return V_206 ;
}
static T_8 F_68 ( struct V_1 * V_2 , struct V_3 * V_3 , void * V_30 , T_4 V_167 , T_3 * V_108 )
{
T_9 V_205 ;
T_8 V_206 ;
int V_6 , V_204 ;
V_6 = F_56 ( V_2 , V_3 , V_167 , * V_108 ) ;
if ( V_6 )
return V_6 ;
V_205 = F_64 () ;
F_65 ( F_66 () ) ;
V_204 = F_61 () ;
V_206 = F_69 ( V_3 , ( char V_207 * ) V_30 , V_167 , V_108 ) ;
F_62 ( V_204 ) ;
F_65 ( V_205 ) ;
F_54 ( V_2 ) ;
return V_206 ;
}
static inline union V_27 * F_70 ( struct V_1 * V_2 )
{
return & ( V_2 -> V_26 [ V_2 -> V_166 . V_169 ] ) ;
}
static inline T_5 * F_71 ( struct V_1 * V_2 )
{
return F_70 ( V_2 ) -> V_28 + V_2 -> V_166 . V_168 + V_2 -> V_166 . V_176 ;
}
int F_72 ( struct V_1 * V_2 , int V_175 )
{
unsigned int V_93 = V_2 -> V_166 . V_169 ;
if ( F_37 ( V_93 ) ) {
int V_5 ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_175 ) ;
for ( V_5 = 0 ; V_5 < V_175 ; ++ V_5 )
V_2 -> V_30 . V_28 [ V_5 ] = F_73 () ;
F_24 ( L_78 , V_93 ) ;
return 1 ;
}
return 0 ;
}
void F_74 ( struct V_1 * V_2 , int V_175 )
{
if ( V_208 && F_73 () < ( 1 << 22 ) ) {
int V_209 = 1 ;
if ( V_208 > 1 )
V_209 = ( F_73 () % ( int ) V_208 ) + 1 ;
while ( V_209 -- ) {
int V_108 = F_73 () % ( V_175 * 8 ) ;
V_2 -> V_30 . V_28 [ V_108 / 8 ] ^= ( 1 << ( V_108 % 8 ) ) ;
F_24 ( L_79
L_80 ,
V_108 , V_2 -> V_166 . V_169 , V_2 -> V_166 . V_168 + V_2 -> V_166 . V_176 ,
V_210 -> V_211 . V_212 , V_210 -> V_211 . V_213 ) ;
}
}
}
static void F_75 ( struct V_1 * V_2 , int V_175 )
{
union V_27 * V_214 ;
if ( V_2 -> V_4 ) {
if ( ! V_2 -> V_18 [ V_2 -> V_166 . V_169 ] ) {
F_51 ( L_81 , V_2 -> V_166 . V_169 ) ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_175 ) ;
} else {
T_3 V_108 ;
T_8 V_206 ;
F_51 ( L_82 ,
V_2 -> V_166 . V_169 , V_2 -> V_166 . V_168 + V_2 -> V_166 . V_176 ) ;
if ( F_72 ( V_2 , V_175 ) )
return;
V_108 = ( T_3 ) V_2 -> V_166 . V_169 * V_2 -> V_19 . V_23 + V_2 -> V_166 . V_168 + V_2 -> V_166 . V_176 ;
V_206 = F_63 ( V_2 , V_2 -> V_4 , V_2 -> V_30 . V_28 , V_175 , & V_108 ) ;
if ( V_206 != V_175 ) {
F_5 ( L_83 , V_2 -> V_166 . V_169 , ( long ) V_206 ) ;
return;
}
F_74 ( V_2 , V_175 ) ;
}
return;
}
V_214 = F_70 ( V_2 ) ;
if ( V_214 -> V_28 == NULL ) {
F_51 ( L_84 , V_2 -> V_166 . V_169 ) ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_175 ) ;
} else {
F_51 ( L_85 ,
V_2 -> V_166 . V_169 , V_2 -> V_166 . V_168 + V_2 -> V_166 . V_176 ) ;
if ( F_72 ( V_2 , V_175 ) )
return;
memcpy ( V_2 -> V_30 . V_28 , F_71 ( V_2 ) , V_175 ) ;
F_74 ( V_2 , V_175 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
union V_27 * V_214 ;
int V_5 ;
if ( V_2 -> V_4 ) {
for ( V_5 = 0 ; V_5 < V_2 -> V_19 . V_59 ; V_5 ++ )
if ( V_2 -> V_18 [ V_2 -> V_166 . V_169 + V_5 ] ) {
F_51 ( L_86 , V_2 -> V_166 . V_169 + V_5 ) ;
V_2 -> V_18 [ V_2 -> V_166 . V_169 + V_5 ] = 0 ;
}
return;
}
V_214 = F_70 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_19 . V_59 ; V_5 ++ ) {
if ( V_214 -> V_28 != NULL ) {
F_51 ( L_86 , V_2 -> V_166 . V_169 + V_5 ) ;
F_14 ( V_2 -> V_29 , V_214 -> V_28 ) ;
V_214 -> V_28 = NULL ;
}
V_214 ++ ;
}
}
static int F_77 ( struct V_1 * V_2 , int V_175 )
{
int V_5 ;
union V_27 * V_214 ;
T_5 * V_215 ;
if ( V_2 -> V_4 ) {
T_3 V_176 , V_108 ;
T_8 V_206 ;
int V_216 ;
F_51 ( L_87 , V_2 -> V_166 . V_169 ) ;
V_215 = V_2 -> V_22 + V_2 -> V_166 . V_168 + V_2 -> V_166 . V_176 ;
V_176 = ( T_3 ) V_2 -> V_166 . V_169 * V_2 -> V_19 . V_23 + V_2 -> V_166 . V_168 + V_2 -> V_166 . V_176 ;
if ( ! V_2 -> V_18 [ V_2 -> V_166 . V_169 ] ) {
V_216 = 1 ;
memset ( V_2 -> V_22 , 0xff , V_2 -> V_19 . V_23 ) ;
} else {
V_216 = 0 ;
V_108 = V_176 ;
V_206 = F_63 ( V_2 , V_2 -> V_4 , V_215 , V_175 , & V_108 ) ;
if ( V_206 != V_175 ) {
F_5 ( L_88 , V_2 -> V_166 . V_169 , ( long ) V_206 ) ;
return - 1 ;
}
}
for ( V_5 = 0 ; V_5 < V_175 ; V_5 ++ )
V_215 [ V_5 ] &= V_2 -> V_30 . V_28 [ V_5 ] ;
if ( V_216 ) {
V_108 = ( T_3 ) V_2 -> V_166 . V_169 * V_2 -> V_19 . V_23 ;
V_206 = F_68 ( V_2 , V_2 -> V_4 , V_2 -> V_22 , V_2 -> V_19 . V_23 , & V_108 ) ;
if ( V_206 != V_2 -> V_19 . V_23 ) {
F_5 ( L_89 , V_2 -> V_166 . V_169 , ( long ) V_206 ) ;
return - 1 ;
}
V_2 -> V_18 [ V_2 -> V_166 . V_169 ] = 1 ;
} else {
V_108 = V_176 ;
V_206 = F_68 ( V_2 , V_2 -> V_4 , V_215 , V_175 , & V_108 ) ;
if ( V_206 != V_175 ) {
F_5 ( L_89 , V_2 -> V_166 . V_169 , ( long ) V_206 ) ;
return - 1 ;
}
}
return 0 ;
}
V_214 = F_70 ( V_2 ) ;
if ( V_214 -> V_28 == NULL ) {
F_51 ( L_90 , V_2 -> V_166 . V_169 ) ;
V_214 -> V_28 = F_78 ( V_2 -> V_29 , V_199 ) ;
if ( V_214 -> V_28 == NULL ) {
F_5 ( L_91 , V_2 -> V_166 . V_169 ) ;
return - 1 ;
}
memset ( V_214 -> V_28 , 0xFF , V_2 -> V_19 . V_23 ) ;
}
V_215 = F_71 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_175 ; V_5 ++ )
V_215 [ V_5 ] &= V_2 -> V_30 . V_28 [ V_5 ] ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , T_2 V_217 )
{
int V_175 ;
int V_218 = V_2 -> V_43 == 8 ? 1 : 2 ;
unsigned int V_83 , V_93 ;
V_217 &= V_219 ;
if ( V_217 != V_220 && V_2 -> V_166 . V_169 >= V_2 -> V_19 . V_20 ) {
F_24 ( L_92 , V_2 -> V_166 . V_169 ) ;
return - 1 ;
}
switch ( V_217 ) {
case V_221 :
if ( V_2 -> V_166 . V_168 >= ( V_2 -> V_19 . V_23 - V_2 -> V_166 . V_176 ) ) {
F_5 ( L_93 ) ;
break;
}
V_175 = V_2 -> V_19 . V_23 - V_2 -> V_166 . V_176 - V_2 -> V_166 . V_168 ;
F_75 ( V_2 , V_175 ) ;
F_51 ( L_94 ,
V_175 , F_80 ( V_2 ) + V_2 -> V_166 . V_176 ) ;
if ( V_2 -> V_166 . V_176 == 0 )
F_81 ( L_95 , V_2 -> V_166 . V_169 ) ;
else if ( V_2 -> V_166 . V_176 < V_2 -> V_19 . V_48 )
F_81 ( L_96 , V_2 -> V_166 . V_169 ) ;
else
F_81 ( L_97 , V_2 -> V_166 . V_169 ) ;
F_82 ( V_222 ) ;
F_82 ( V_223 * V_2 -> V_19 . V_48 / 1000 / V_218 ) ;
break;
case V_220 :
if ( V_2 -> V_224 . V_96 ) {
F_5 ( L_98 ) ;
return - 1 ;
}
if ( V_2 -> V_166 . V_169 >= V_2 -> V_19 . V_20 - V_2 -> V_19 . V_59
|| ( V_2 -> V_166 . V_169 & ~ ( V_2 -> V_19 . V_52 - 1 ) ) ) {
F_5 ( L_99 , V_2 -> V_166 . V_169 ) ;
return - 1 ;
}
V_2 -> V_166 . V_169 = ( V_2 -> V_166 . V_169 <<
8 * ( V_2 -> V_19 . V_68 - V_2 -> V_19 . V_69 ) ) | V_2 -> V_166 . V_168 ;
V_2 -> V_166 . V_168 = 0 ;
V_83 = V_2 -> V_166 . V_169 >> ( V_2 -> V_19 . V_55 - V_2 -> V_19 . V_56 ) ;
F_51 ( L_100 ,
V_2 -> V_166 . V_169 , F_80 ( V_2 ) ) ;
F_81 ( L_101 , V_83 ) ;
F_76 ( V_2 ) ;
F_83 ( V_225 ) ;
if ( V_109 )
F_43 ( V_83 ) ;
if ( F_32 ( V_83 ) ) {
F_24 ( L_102 , V_83 ) ;
return - 1 ;
}
break;
case V_226 :
if ( V_2 -> V_224 . V_96 ) {
F_24 ( L_103 ) ;
return - 1 ;
}
V_175 = V_2 -> V_19 . V_23 - V_2 -> V_166 . V_176 - V_2 -> V_166 . V_168 ;
if ( V_175 != V_2 -> V_166 . V_167 ) {
F_5 ( L_104 ,
V_2 -> V_166 . V_167 , V_175 ) ;
return - 1 ;
}
if ( F_77 ( V_2 , V_175 ) == - 1 )
return - 1 ;
V_93 = V_2 -> V_166 . V_169 ;
F_51 ( L_105 ,
V_175 , V_2 -> V_166 . V_169 , V_2 -> V_166 . V_168 , F_80 ( V_2 ) + V_2 -> V_166 . V_176 ) ;
F_81 ( L_106 , V_2 -> V_166 . V_169 ) ;
F_82 ( V_227 ) ;
F_82 ( V_228 * V_2 -> V_19 . V_48 / 1000 / V_218 ) ;
if ( F_35 ( V_93 ) ) {
F_24 ( L_107 , V_93 ) ;
return - 1 ;
}
break;
case V_229 :
F_51 ( L_108 ) ;
V_2 -> V_166 . V_176 = 0 ;
break;
case V_230 :
if ( ! ( V_2 -> V_44 & V_64 ) ) {
F_5 ( L_109
L_110 ) ;
return - 1 ;
}
F_51 ( L_111 , V_2 -> V_19 . V_48 / 2 ) ;
V_2 -> V_166 . V_176 = V_2 -> V_19 . V_48 / 2 ;
break;
case V_231 :
F_51 ( L_111 , V_2 -> V_19 . V_48 ) ;
V_2 -> V_166 . V_176 = V_2 -> V_19 . V_48 ;
break;
default:
F_51 ( L_112 ) ;
}
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_172 ) {
V_2 -> V_174 += 1 ;
V_2 -> V_123 = V_2 -> V_171 ;
V_2 -> V_171 = V_2 -> V_172 [ V_2 -> V_174 + 1 ] ;
F_51 ( L_113
L_114 ,
F_45 ( V_2 -> V_123 ) , F_45 ( V_2 -> V_171 ) ) ;
if ( ( V_2 -> V_123 & V_219 ) && F_79 ( V_2 , V_2 -> V_123 ) < 0 ) {
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
} else {
V_2 -> V_123 = F_48 ( V_2 -> V_166 . V_164 ) ;
F_51 ( L_115 ) ;
if ( F_52 ( V_2 , 0 ) != 0 )
return;
if ( ( V_2 -> V_123 & V_219 ) && F_79 ( V_2 , V_2 -> V_123 ) < 0 ) {
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
}
if ( ( V_2 -> V_171 & V_186 ) && V_2 -> V_43 == 16 ) {
F_51 ( L_116 ) ;
V_2 -> V_166 . V_168 <<= 1 ;
}
if ( F_46 ( V_2 -> V_171 ) == V_147 ) {
T_5 V_170 = F_85 ( V_2 ) ;
if ( ( V_2 -> V_123 & ( V_232 | V_233 ) )
&& V_2 -> V_166 . V_167 != V_2 -> V_166 . V_175 ) {
F_24 ( L_117 ,
V_2 -> V_166 . V_175 - V_2 -> V_166 . V_167 ) ;
V_170 = F_53 ( V_2 ) ;
}
F_51 ( L_118 ) ;
F_50 ( V_2 , V_170 ) ;
return;
} else if ( V_2 -> V_171 & ( V_232 | V_233 ) ) {
V_2 -> V_123 = V_2 -> V_171 ;
V_2 -> V_171 = V_2 -> V_172 [ ++ V_2 -> V_174 + 1 ] ;
V_2 -> V_166 . V_175 = V_2 -> V_166 . V_167 = 0 ;
F_51 ( L_119
L_114 ,
F_45 ( V_2 -> V_123 ) , F_45 ( V_2 -> V_171 ) ) ;
switch ( F_46 ( V_2 -> V_123 ) ) {
case V_142 :
case V_143 :
V_2 -> V_166 . V_175 = V_2 -> V_19 . V_23 - V_2 -> V_166 . V_176 - V_2 -> V_166 . V_168 ;
break;
case V_144 :
V_2 -> V_166 . V_175 = V_2 -> V_19 . V_234 ;
break;
case V_145 :
case V_146 :
V_2 -> V_166 . V_167 = V_2 -> V_166 . V_175 = 0 ;
break;
default:
F_5 ( L_120 ) ;
}
} else if ( V_2 -> V_171 & V_186 ) {
V_2 -> V_166 . V_167 = 0 ;
switch ( F_46 ( V_2 -> V_171 ) ) {
case V_138 :
V_2 -> V_166 . V_175 = V_2 -> V_19 . V_68 ;
break;
case V_139 :
V_2 -> V_166 . V_175 = V_2 -> V_19 . V_69 ;
break;
case V_140 :
V_2 -> V_166 . V_175 = 1 ;
break;
case V_141 :
V_2 -> V_166 . V_175 = V_2 -> V_19 . V_68 - V_2 -> V_19 . V_69 ;
break;
default:
F_5 ( L_121 ) ;
}
} else {
V_2 -> V_166 . V_175 = 0 ;
V_2 -> V_166 . V_167 = 0 ;
}
}
static T_5 F_86 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
T_5 V_235 = 0x00 ;
if ( ! V_2 -> V_224 . V_236 ) {
F_5 ( L_122 , ( T_6 ) V_235 ) ;
return V_235 ;
}
if ( V_2 -> V_224 . V_237 || V_2 -> V_224 . V_238 ) {
F_5 ( L_123 , ( T_6 ) V_235 ) ;
return V_235 ;
}
if ( ! ( V_2 -> V_123 & V_233 ) ) {
F_24 ( L_124
L_125 , F_45 ( V_2 -> V_123 ) , ( T_6 ) V_235 ) ;
return V_235 ;
}
if ( F_46 ( V_2 -> V_123 ) == V_145 ) {
F_51 ( L_126 , V_2 -> V_166 . V_170 ) ;
return V_2 -> V_166 . V_170 ;
}
if ( V_2 -> V_166 . V_167 == V_2 -> V_166 . V_175 ) {
F_24 ( L_127 , ( T_6 ) V_235 ) ;
return V_235 ;
}
switch ( F_46 ( V_2 -> V_123 ) ) {
case V_143 :
if ( V_2 -> V_43 == 8 ) {
V_235 = V_2 -> V_30 . V_28 [ V_2 -> V_166 . V_167 ] ;
V_2 -> V_166 . V_167 += 1 ;
} else {
V_235 = ( T_5 ) F_87 ( V_2 -> V_30 . V_239 [ V_2 -> V_166 . V_167 >> 1 ] ) ;
V_2 -> V_166 . V_167 += 2 ;
}
break;
case V_144 :
F_51 ( L_128 , V_2 -> V_166 . V_167 , V_2 -> V_166 . V_175 ) ;
V_235 = V_2 -> V_240 [ V_2 -> V_166 . V_167 ] ;
V_2 -> V_166 . V_167 += 1 ;
break;
default:
F_88 () ;
}
if ( V_2 -> V_166 . V_167 == V_2 -> V_166 . V_175 ) {
F_51 ( L_129 ) ;
if ( ( V_2 -> V_44 & V_63 ) && F_46 ( V_2 -> V_123 ) == V_143 ) {
V_2 -> V_166 . V_167 = 0 ;
if ( V_2 -> V_166 . V_169 + 1 < V_2 -> V_19 . V_20 )
V_2 -> V_166 . V_169 += 1 ;
F_51 ( L_130 , V_2 -> V_166 . V_169 ) ;
F_79 ( V_2 , V_221 ) ;
}
else if ( F_46 ( V_2 -> V_171 ) == V_147 )
F_84 ( V_2 ) ;
}
return V_235 ;
}
static void F_89 ( struct V_33 * V_34 , T_5 V_28 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
if ( ! V_2 -> V_224 . V_236 ) {
F_5 ( L_131 ) ;
return;
}
if ( V_2 -> V_224 . V_237 && V_2 -> V_224 . V_238 ) {
F_5 ( L_132 ) ;
return;
}
if ( V_2 -> V_224 . V_238 == 1 ) {
if ( V_28 == V_160 ) {
F_81 ( L_133 ) ;
F_50 ( V_2 , F_85 ( V_2 ) ) ;
return;
}
if ( F_47 ( V_28 ) ) {
F_5 ( L_134 , ( T_6 ) V_28 ) ;
return;
}
if ( F_46 ( V_2 -> V_123 ) == V_145
|| F_46 ( V_2 -> V_123 ) == V_146
|| F_46 ( V_2 -> V_123 ) == V_143 ) {
int V_169 = V_2 -> V_166 . V_169 ;
F_84 ( V_2 ) ;
if ( V_28 == V_161 )
V_2 -> V_166 . V_169 = V_169 ;
}
if ( F_46 ( V_2 -> V_171 ) != V_148 && ! ( V_2 -> V_171 & V_241 ) ) {
if ( ! ( V_2 -> V_166 . V_164 == V_158 &&
F_46 ( V_2 -> V_123 ) == V_144 && V_2 -> V_166 . V_167 == 2 ) ) {
F_24 ( L_135
L_136 , ( T_6 ) V_28 , F_45 ( V_2 -> V_171 ) ) ;
}
F_50 ( V_2 , F_53 ( V_2 ) ) ;
}
F_51 ( L_137 ,
F_45 ( F_48 ( V_28 ) ) ) ;
V_2 -> V_166 . V_164 = V_28 ;
F_84 ( V_2 ) ;
} else if ( V_2 -> V_224 . V_237 == 1 ) {
if ( F_46 ( V_2 -> V_171 ) == V_148 ) {
F_51 ( L_138 ) ;
if ( F_52 ( V_2 , 1 ) < 0 )
return;
if ( ( V_2 -> V_123 & V_219 ) && F_79 ( V_2 , V_2 -> V_123 ) < 0 ) {
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
V_2 -> V_166 . V_167 = 0 ;
switch ( F_46 ( V_2 -> V_171 ) ) {
case V_138 :
V_2 -> V_166 . V_175 = V_2 -> V_19 . V_68 ;
break;
case V_139 :
V_2 -> V_166 . V_175 = V_2 -> V_19 . V_69 ;
break;
case V_140 :
V_2 -> V_166 . V_175 = 1 ;
break;
default:
F_88 () ;
}
}
if ( ! ( V_2 -> V_171 & V_186 ) ) {
F_5 ( L_139
L_140 , ( T_6 ) V_28 , F_45 ( V_2 -> V_171 ) ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_166 . V_167 == V_2 -> V_166 . V_175 ) {
F_5 ( L_141 ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
F_49 ( V_2 , V_28 ) ;
V_2 -> V_166 . V_167 += 1 ;
F_51 ( L_142 ,
( T_6 ) V_28 , V_2 -> V_166 . V_167 , V_2 -> V_166 . V_175 ) ;
if ( V_2 -> V_166 . V_167 == V_2 -> V_166 . V_175 ) {
F_51 ( L_143 , V_2 -> V_166 . V_169 , V_2 -> V_166 . V_168 ) ;
F_84 ( V_2 ) ;
}
} else {
if ( ! ( V_2 -> V_123 & V_232 ) ) {
F_5 ( L_144
L_145 , ( T_6 ) V_28 ,
F_45 ( V_2 -> V_123 ) , F_45 ( V_147 ) ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_166 . V_167 == V_2 -> V_166 . V_175 ) {
F_24 ( L_146 ,
V_2 -> V_166 . V_175 ) ;
return;
}
if ( V_2 -> V_43 == 8 ) {
V_2 -> V_30 . V_28 [ V_2 -> V_166 . V_167 ] = V_28 ;
V_2 -> V_166 . V_167 += 1 ;
} else {
V_2 -> V_30 . V_239 [ V_2 -> V_166 . V_167 >> 1 ] = F_87 ( ( V_242 ) V_28 ) ;
V_2 -> V_166 . V_167 += 2 ;
}
}
return;
}
static void F_90 ( struct V_33 * V_34 , int V_149 , unsigned int V_243 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
V_2 -> V_224 . V_238 = V_243 & V_244 ? 1 : 0 ;
V_2 -> V_224 . V_237 = V_243 & V_245 ? 1 : 0 ;
V_2 -> V_224 . V_236 = V_243 & V_246 ? 1 : 0 ;
if ( V_149 != V_247 )
F_89 ( V_34 , V_149 ) ;
}
static int F_91 ( struct V_33 * V_34 )
{
F_51 ( L_147 ) ;
return 1 ;
}
static V_242 F_92 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_34 -> V_37 ;
F_51 ( L_148 ) ;
return V_36 -> V_248 ( V_34 ) | ( V_36 -> V_248 ( V_34 ) << 8 ) ;
}
static void F_93 ( struct V_33 * V_34 , const T_5 * V_30 , int V_249 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
if ( ! ( V_2 -> V_123 & V_232 ) ) {
F_5 ( L_149
L_140 , F_45 ( V_2 -> V_123 ) ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_166 . V_167 + V_249 > V_2 -> V_166 . V_175 ) {
F_5 ( L_150 ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
memcpy ( V_2 -> V_30 . V_28 + V_2 -> V_166 . V_167 , V_30 , V_249 ) ;
V_2 -> V_166 . V_167 += V_249 ;
if ( V_2 -> V_166 . V_167 == V_2 -> V_166 . V_175 ) {
F_51 ( L_151 , V_2 -> V_166 . V_167 ) ;
}
}
static void F_94 ( struct V_33 * V_34 , T_5 * V_30 , int V_249 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
if ( ! V_2 -> V_224 . V_236 ) {
F_5 ( L_152 ) ;
return;
}
if ( V_2 -> V_224 . V_237 || V_2 -> V_224 . V_238 ) {
F_5 ( L_153 ) ;
return;
}
if ( ! ( V_2 -> V_123 & V_233 ) ) {
F_24 ( L_154 ,
F_45 ( V_2 -> V_123 ) ) ;
return;
}
if ( F_46 ( V_2 -> V_123 ) != V_143 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_249 ; V_5 ++ )
V_30 [ V_5 ] = ( (struct V_35 * ) V_34 -> V_37 ) -> V_248 ( V_34 ) ;
return;
}
if ( V_2 -> V_166 . V_167 + V_249 > V_2 -> V_166 . V_175 ) {
F_5 ( L_155 ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
memcpy ( V_30 , V_2 -> V_30 . V_28 + V_2 -> V_166 . V_167 , V_249 ) ;
V_2 -> V_166 . V_167 += V_249 ;
if ( V_2 -> V_166 . V_167 == V_2 -> V_166 . V_175 ) {
if ( ( V_2 -> V_44 & V_63 ) && F_46 ( V_2 -> V_123 ) == V_143 ) {
V_2 -> V_166 . V_167 = 0 ;
if ( V_2 -> V_166 . V_169 + 1 < V_2 -> V_19 . V_20 )
V_2 -> V_166 . V_169 += 1 ;
F_51 ( L_156 , V_2 -> V_166 . V_169 ) ;
F_79 ( V_2 , V_221 ) ;
}
else if ( F_46 ( V_2 -> V_171 ) == V_147 )
F_84 ( V_2 ) ;
}
return;
}
static int F_95 ( struct V_33 * V_34 , const T_5 * V_30 , int V_249 )
{
F_94 ( V_34 , ( T_5 * ) & V_250 [ 0 ] , V_249 ) ;
if ( ! memcmp ( V_30 , & V_250 [ 0 ] , V_249 ) ) {
F_51 ( L_157 ) ;
return 0 ;
} else {
F_51 ( L_158 ) ;
return - V_251 ;
}
}
static int T_10 F_96 ( void )
{
struct V_35 * V_36 ;
struct V_1 * V_252 ;
int V_253 = - V_21 , V_5 ;
if ( V_254 != 8 && V_254 != 16 ) {
F_5 ( L_159 , V_254 ) ;
return - V_14 ;
}
V_210 = F_30 ( sizeof( struct V_33 ) + sizeof( struct V_35 )
+ sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_210 ) {
F_5 ( L_160 ) ;
return - V_21 ;
}
V_36 = (struct V_35 * ) ( V_210 + 1 ) ;
V_210 -> V_37 = ( void * ) V_36 ;
V_252 = (struct V_1 * ) ( V_36 + 1 ) ;
V_36 -> V_37 = ( void * ) V_252 ;
V_36 -> V_255 = F_90 ;
V_36 -> V_248 = F_86 ;
V_36 -> V_256 = F_91 ;
V_36 -> V_257 = F_93 ;
V_36 -> V_258 = F_94 ;
V_36 -> V_259 = F_95 ;
V_36 -> V_260 = F_92 ;
V_36 -> V_261 . V_262 = V_263 ;
V_36 -> V_44 |= V_264 ;
switch ( V_265 ) {
case 2 :
V_36 -> V_266 |= V_267 ;
case 1 :
V_36 -> V_266 |= V_268 ;
case 0 :
break;
default:
F_5 ( L_161 ) ;
V_253 = - V_14 ;
goto error;
}
if ( V_269 != 0xFF || V_270 != 0xFF )
V_252 -> V_19 . V_234 = 4 ;
else
V_252 -> V_19 . V_234 = 2 ;
V_252 -> V_166 . V_170 = F_85 ( V_252 ) ;
V_252 -> V_171 = V_148 ;
V_252 -> V_44 |= V_61 ;
V_252 -> V_240 [ 0 ] = V_271 ;
V_252 -> V_240 [ 1 ] = V_78 ;
V_252 -> V_240 [ 2 ] = V_269 ;
V_252 -> V_240 [ 3 ] = V_270 ;
if ( V_254 == 16 ) {
V_252 -> V_43 = 16 ;
V_36 -> V_44 |= V_45 ;
}
V_210 -> V_272 = V_273 ;
if ( ( V_253 = F_29 () ) != 0 )
goto error;
if ( ( V_253 = F_34 () ) != 0 )
goto error;
if ( ( V_253 = F_36 () ) != 0 )
goto error;
V_253 = F_97 ( V_210 , 1 , NULL ) ;
if ( V_253 ) {
F_5 ( L_162 ) ;
if ( V_253 > 0 )
V_253 = - V_274 ;
goto error;
}
if ( V_275 ) {
unsigned int V_276 , V_277 ;
if ( ! F_98 () ) {
F_5 ( L_163 ) ;
V_253 = - V_14 ;
goto error;
}
V_276 = V_210 -> V_49 / 512 ;
V_277 = ( V_275 * 13 + 7 ) / 8 ;
if ( ( V_210 -> V_51 < 64 ) || ! V_276 ) {
F_5 ( L_164 ) ;
V_253 = - V_14 ;
goto error;
}
if ( ( V_277 * V_276 + 2 ) > V_210 -> V_51 ) {
F_5 ( L_165 , V_275 ) ;
V_253 = - V_14 ;
goto error;
}
V_36 -> V_261 . V_262 = V_278 ;
V_36 -> V_261 . V_47 = 512 ;
V_36 -> V_261 . V_279 = V_277 ;
F_44 ( L_166 , V_275 , V_36 -> V_261 . V_47 ) ;
}
V_253 = F_99 ( V_210 ) ;
if ( V_253 ) {
F_5 ( L_167 ) ;
if ( V_253 > 0 )
V_253 = - V_274 ;
goto error;
}
if ( V_280 ) {
T_1 V_281 = ( T_1 ) V_210 -> V_53 << V_280 ;
if ( V_281 >> V_280 != V_210 -> V_53 ) {
F_5 ( L_168 ) ;
goto V_282;
}
V_210 -> V_47 = V_281 ;
V_36 -> V_283 = V_281 ;
V_36 -> V_284 = F_22 ( V_210 -> V_53 ) + V_280 - 1 ;
V_36 -> V_285 = ( V_36 -> V_283 >> V_36 -> V_57 ) - 1 ;
}
if ( ( V_253 = F_42 ( V_210 ) ) != 0 )
goto V_282;
if ( ( V_253 = F_20 ( V_210 ) ) != 0 )
goto V_282;
if ( ( V_253 = F_100 ( V_210 ) ) != 0 )
goto V_282;
if ( ( V_253 = F_27 ( V_252 , V_210 ) ) != 0 )
goto V_282;
V_253 = F_101 ( V_210 , & V_252 -> V_71 [ 0 ] ,
V_252 -> V_76 ) ;
if ( V_253 != 0 )
goto V_282;
return 0 ;
V_282:
F_26 ( V_252 ) ;
F_102 ( V_210 ) ;
for ( V_5 = 0 ; V_5 < F_23 ( V_252 -> V_71 ) ; ++ V_5 )
F_13 ( V_252 -> V_71 [ V_5 ] . V_74 ) ;
error:
F_13 ( V_210 ) ;
F_38 () ;
return V_253 ;
}
static void T_11 F_103 ( void )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_210 -> V_37 ) -> V_37 ;
int V_5 ;
F_26 ( V_2 ) ;
F_102 ( V_210 ) ;
for ( V_5 = 0 ; V_5 < F_23 ( V_2 -> V_71 ) ; ++ V_5 )
F_13 ( V_2 -> V_71 [ V_5 ] . V_74 ) ;
F_13 ( V_210 ) ;
F_38 () ;
}
