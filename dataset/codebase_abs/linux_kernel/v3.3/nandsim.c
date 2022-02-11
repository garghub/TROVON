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
if ( F_29 ( V_34 , V_75 ) ) {
F_5 ( L_29 ) ;
return - V_14 ;
}
if ( * V_81 == ',' )
V_81 += 1 ;
} while ( * V_81 );
return 0 ;
}
static int F_30 ( void )
{
char * V_81 ;
int V_82 ;
unsigned int V_83 ;
unsigned int V_85 ;
struct V_86 * V_87 ;
if ( ! V_88 )
return 0 ;
V_81 = V_88 ;
do {
V_82 = ( * V_81 == '0' ? 1 : 0 ) ;
V_83 = F_28 ( V_81 , & V_81 , 0 ) ;
if ( ! V_82 && ! V_83 ) {
F_5 ( L_30 ) ;
return - V_14 ;
}
V_85 = 3 ;
if ( * V_81 == ':' ) {
V_81 += 1 ;
V_85 = F_28 ( V_81 , & V_81 , 0 ) ;
}
if ( * V_81 == ',' )
V_81 += 1 ;
V_87 = F_31 ( sizeof( * V_87 ) , V_24 ) ;
if ( ! V_87 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_87 -> V_83 = V_83 ;
V_87 -> V_85 = V_85 ;
F_32 ( & V_87 -> V_89 , & V_90 ) ;
} while ( * V_81 );
return 0 ;
}
static int F_33 ( unsigned int V_83 )
{
struct V_86 * V_87 ;
F_34 (wb, &weak_blocks, list)
if ( V_87 -> V_83 == V_83 ) {
if ( V_87 -> V_91 >= V_87 -> V_85 )
return 1 ;
V_87 -> V_91 += 1 ;
return 0 ;
}
return 0 ;
}
static int F_35 ( void )
{
char * V_81 ;
int V_82 ;
unsigned int V_92 ;
unsigned int V_93 ;
struct V_94 * V_95 ;
if ( ! V_96 )
return 0 ;
V_81 = V_96 ;
do {
V_82 = ( * V_81 == '0' ? 1 : 0 ) ;
V_92 = F_28 ( V_81 , & V_81 , 0 ) ;
if ( ! V_82 && ! V_92 ) {
F_5 ( L_32 ) ;
return - V_14 ;
}
V_93 = 3 ;
if ( * V_81 == ':' ) {
V_81 += 1 ;
V_93 = F_28 ( V_81 , & V_81 , 0 ) ;
}
if ( * V_81 == ',' )
V_81 += 1 ;
V_95 = F_31 ( sizeof( * V_95 ) , V_24 ) ;
if ( ! V_95 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_95 -> V_92 = V_92 ;
V_95 -> V_93 = V_93 ;
F_32 ( & V_95 -> V_89 , & V_97 ) ;
} while ( * V_81 );
return 0 ;
}
static int F_36 ( unsigned int V_92 )
{
struct V_94 * V_95 ;
F_34 (wp, &weak_pages, list)
if ( V_95 -> V_92 == V_92 ) {
if ( V_95 -> V_98 >= V_95 -> V_93 )
return 1 ;
V_95 -> V_98 += 1 ;
return 0 ;
}
return 0 ;
}
static int F_37 ( void )
{
char * V_99 ;
int V_82 ;
unsigned int V_92 ;
unsigned int V_100 ;
struct V_101 * V_102 ;
if ( ! V_103 )
return 0 ;
V_99 = V_103 ;
do {
V_82 = ( * V_99 == '0' ? 1 : 0 ) ;
V_92 = F_28 ( V_99 , & V_99 , 0 ) ;
if ( ! V_82 && ! V_92 ) {
F_5 ( L_33 ) ;
return - V_14 ;
}
V_100 = 3 ;
if ( * V_99 == ':' ) {
V_99 += 1 ;
V_100 = F_28 ( V_99 , & V_99 , 0 ) ;
}
if ( * V_99 == ',' )
V_99 += 1 ;
V_102 = F_31 ( sizeof( * V_102 ) , V_24 ) ;
if ( ! V_102 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_102 -> V_92 = V_92 ;
V_102 -> V_100 = V_100 ;
F_32 ( & V_102 -> V_89 , & V_104 ) ;
} while ( * V_99 );
return 0 ;
}
static int F_38 ( unsigned int V_92 )
{
struct V_101 * V_102 ;
F_34 (gp, &grave_pages, list)
if ( V_102 -> V_92 == V_92 ) {
if ( V_102 -> V_105 >= V_102 -> V_100 )
return 1 ;
V_102 -> V_105 += 1 ;
return 0 ;
}
return 0 ;
}
static void F_39 ( void )
{
struct V_106 * V_107 , * V_31 ;
F_40 (pos, n, &weak_blocks) {
F_41 ( V_107 ) ;
F_13 ( F_42 ( V_107 , struct V_86 , V_89 ) ) ;
}
F_40 (pos, n, &weak_pages) {
F_41 ( V_107 ) ;
F_13 ( F_42 ( V_107 , struct V_94 , V_89 ) ) ;
}
F_40 (pos, n, &grave_pages) {
F_41 ( V_107 ) ;
F_13 ( F_42 ( V_107 , struct V_101 , V_89 ) ) ;
}
F_13 ( V_108 ) ;
}
static int F_43 ( struct V_33 * V_34 )
{
T_4 V_109 ;
if ( ! V_110 )
return 0 ;
V_111 = F_18 ( V_34 -> V_47 , V_34 -> V_53 ) ;
V_109 = V_111 * sizeof( unsigned long ) ;
if ( V_109 / sizeof( unsigned long ) != V_111 ) {
F_5 ( L_34 ) ;
return - V_21 ;
}
V_108 = F_31 ( V_109 , V_24 ) ;
if ( ! V_108 ) {
F_5 ( L_34 ) ;
return - V_21 ;
}
return 0 ;
}
static void F_44 ( unsigned int V_83 )
{
unsigned long V_112 = - 1 , V_113 = 0 , V_114 ;
unsigned long V_115 [ 10 ] , V_116 [ 10 ] , V_117 = 0 ;
unsigned int V_5 ;
if ( ! V_108 )
return;
V_118 += 1 ;
if ( V_118 == 0 )
F_5 ( L_35 ) ;
V_108 [ V_83 ] += 1 ;
if ( V_108 [ V_83 ] == 0 )
F_5 ( L_36 , V_83 ) ;
V_119 += 1 ;
if ( V_119 < V_110 )
return;
V_119 = 0 ;
for ( V_5 = 0 ; V_5 < V_111 ; ++ V_5 ) {
unsigned long V_120 = V_108 [ V_5 ] ;
if ( V_120 < V_112 )
V_112 = V_120 ;
if ( V_120 > V_113 )
V_113 = V_120 ;
V_117 += V_120 ;
}
for ( V_5 = 0 ; V_5 < 9 ; ++ V_5 ) {
V_115 [ V_5 ] = 0 ;
V_116 [ V_5 ] = ( V_113 * ( V_5 + 1 ) + 5 ) / 10 ;
}
V_115 [ 9 ] = 0 ;
V_116 [ 9 ] = V_113 ;
for ( V_5 = 0 ; V_5 < V_111 ; ++ V_5 ) {
int V_32 ;
unsigned long V_120 = V_108 [ V_5 ] ;
for ( V_32 = 0 ; V_32 < 10 ; ++ V_32 )
if ( V_120 <= V_116 [ V_32 ] ) {
V_115 [ V_32 ] += 1 ;
break;
}
}
V_114 = V_117 / V_111 ;
F_45 ( L_37 ) ;
F_45 ( L_38 , V_117 ) ;
F_45 ( L_39 , V_111 ) ;
F_45 ( L_40 , V_114 ) ;
F_45 ( L_41 , V_113 ) ;
F_45 ( L_42 , V_112 ) ;
for ( V_5 = 0 ; V_5 < 10 ; ++ V_5 ) {
unsigned long V_121 = ( V_5 ? V_116 [ V_5 - 1 ] + 1 : 0 ) ;
if ( V_121 > V_116 [ V_5 ] )
continue;
F_45 ( L_43 ,
V_121 ,
V_116 [ V_5 ] ,
V_115 [ V_5 ] ) ;
}
F_45 ( L_44 ) ;
}
static char * F_46 ( T_2 V_122 )
{
switch ( F_47 ( V_122 ) ) {
case V_123 :
return L_45 ;
case V_124 :
return L_46 ;
case V_125 :
return L_47 ;
case V_126 :
return L_48 ;
case V_127 :
return L_49 ;
case V_128 :
return L_50 ;
case V_129 :
return L_51 ;
case V_130 :
return L_52 ;
case V_131 :
return L_53 ;
case V_132 :
return L_54 ;
case V_133 :
return L_55 ;
case V_134 :
return L_56 ;
case V_135 :
return L_57 ;
case V_136 :
return L_58 ;
case V_137 :
return L_59 ;
case V_138 :
return L_60 ;
case V_139 :
return L_61 ;
case V_140 :
return L_62 ;
case V_141 :
return L_63 ;
case V_142 :
return L_64 ;
case V_143 :
return L_65 ;
case V_144 :
return L_66 ;
case V_145 :
return L_67 ;
case V_146 :
return L_68 ;
case V_147 :
return L_69 ;
}
F_5 ( L_70 ) ;
return NULL ;
}
static int F_48 ( int V_148 )
{
switch ( V_148 ) {
case V_149 :
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
return 0 ;
case V_162 :
default:
return 1 ;
}
}
static T_2 F_49 ( unsigned V_163 )
{
switch ( V_163 ) {
case V_149 :
return V_123 ;
case V_150 :
return V_124 ;
case V_152 :
return V_125 ;
case V_151 :
return V_127 ;
case V_153 :
return V_126 ;
case V_154 :
return V_128 ;
case V_155 :
return V_129 ;
case V_162 :
return V_130 ;
case V_156 :
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
}
F_5 ( L_71 ) ;
return 0 ;
}
static inline void F_50 ( struct V_1 * V_2 , T_5 V_164 )
{
T_6 V_28 = ( T_6 ) V_164 ;
if ( V_2 -> V_165 . V_166 < ( V_2 -> V_19 . V_68 - V_2 -> V_19 . V_69 ) )
V_2 -> V_165 . V_167 |= ( V_28 << 8 * V_2 -> V_165 . V_166 ) ;
else {
V_2 -> V_165 . V_168 |= ( V_28 << 8 * ( V_2 -> V_165 . V_166 -
V_2 -> V_19 . V_68 +
V_2 -> V_19 . V_69 ) ) ;
}
return;
}
static inline void F_51 ( struct V_1 * V_2 , T_5 V_169 )
{
F_52 ( L_72 , F_46 ( V_146 ) ) ;
V_2 -> V_122 = V_146 ;
V_2 -> V_170 = V_147 ;
V_2 -> V_171 = NULL ;
V_2 -> V_172 = 0 ;
V_2 -> V_173 = 0 ;
V_2 -> V_165 . V_174 = 0 ;
V_2 -> V_165 . V_166 = 0 ;
V_2 -> V_165 . V_175 = 0 ;
V_2 -> V_165 . V_168 = 0 ;
V_2 -> V_165 . V_167 = 0 ;
V_2 -> V_165 . V_169 = V_169 ;
}
static int F_53 ( struct V_1 * V_2 , T_2 V_176 )
{
int V_177 = 0 ;
int V_5 , V_178 , V_179 = 0 ;
for ( V_5 = 0 ; V_5 < V_180 ; V_5 ++ ) {
int V_181 = 1 ;
if ( ! ( V_2 -> V_44 & V_182 [ V_5 ] . V_183 ) )
continue;
if ( V_176 ) {
if ( ! ( V_182 [ V_5 ] . V_184 [ V_2 -> V_172 ] & V_185 ) )
continue;
} else {
if ( F_47 ( V_2 -> V_122 ) != F_47 ( V_182 [ V_5 ] . V_184 [ V_2 -> V_172 ] ) )
continue;
}
for ( V_178 = 0 ; V_178 < V_2 -> V_172 ; V_178 ++ )
if ( F_47 ( V_182 [ V_5 ] . V_184 [ V_178 ] ) != F_47 ( V_2 -> V_186 [ V_178 ] )
&& ( V_2 -> V_44 & V_182 [ V_179 ] . V_183 ) ) {
V_181 = 0 ;
break;
}
if ( V_181 ) {
V_179 = V_5 ;
V_177 += 1 ;
}
}
if ( V_177 == 1 ) {
V_2 -> V_171 = & V_182 [ V_179 ] . V_184 [ 0 ] ;
if ( V_176 ) {
V_2 -> V_173 = V_2 -> V_172 - 1 ;
} else {
V_2 -> V_173 = V_2 -> V_172 ;
}
V_2 -> V_172 = 0 ;
V_2 -> V_122 = V_2 -> V_171 [ V_2 -> V_173 ] ;
V_2 -> V_170 = V_2 -> V_171 [ V_2 -> V_173 + 1 ] ;
F_52 ( L_73 ,
V_179 , F_46 ( V_2 -> V_122 ) , F_46 ( V_2 -> V_170 ) ) ;
return 0 ;
}
if ( V_177 == 0 ) {
if ( V_2 -> V_172 != 0 ) {
F_52 ( L_74 ,
F_46 ( V_2 -> V_122 ) ) ;
V_2 -> V_172 = 0 ;
return F_53 ( V_2 , 0 ) ;
}
F_52 ( L_75 ) ;
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return - 2 ;
}
if ( V_176 ) {
F_52 ( L_76 ) ;
return - 2 ;
}
F_52 ( L_77 ) ;
V_2 -> V_186 [ V_2 -> V_172 ++ ] = V_2 -> V_122 ;
return - 1 ;
}
static void F_55 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_187 ; V_5 ++ )
F_56 ( V_2 -> V_188 [ V_5 ] ) ;
}
static int F_57 ( struct V_1 * V_2 , struct V_3 * V_3 , T_4 V_166 , T_3 V_107 )
{
T_7 V_189 , V_190 , V_191 ;
struct V_192 * V_192 ;
struct V_193 * V_194 = V_3 -> V_195 ;
V_190 = V_107 >> V_196 ;
V_191 = ( V_107 + V_166 - 1 ) >> V_196 ;
if ( V_191 - V_190 + 1 > V_197 )
return - V_14 ;
V_2 -> V_187 = 0 ;
for ( V_189 = V_190 ; V_189 <= V_191 ; V_189 ++ ) {
V_192 = F_58 ( V_194 , V_189 ) ;
if ( V_192 == NULL ) {
V_192 = F_59 ( V_194 , V_189 , V_198 ) ;
if ( V_192 == NULL ) {
F_60 ( V_194 -> V_199 , 1 ) ;
V_192 = F_59 ( V_194 , V_189 , V_198 ) ;
}
if ( V_192 == NULL ) {
F_55 ( V_2 ) ;
return - V_21 ;
}
F_61 ( V_192 ) ;
}
V_2 -> V_188 [ V_2 -> V_187 ++ ] = V_192 ;
}
return 0 ;
}
static int F_62 ( void )
{
if ( V_200 -> V_201 & V_202 )
return 0 ;
V_200 -> V_201 |= V_202 ;
return 1 ;
}
static void F_63 ( int V_203 )
{
if ( V_203 )
V_200 -> V_201 &= ~ V_202 ;
}
static T_8 F_64 ( struct V_1 * V_2 , struct V_3 * V_3 , void * V_30 , T_4 V_166 , T_3 * V_107 )
{
T_9 V_204 ;
T_8 V_205 ;
int V_6 , V_203 ;
V_6 = F_57 ( V_2 , V_3 , V_166 , * V_107 ) ;
if ( V_6 )
return V_6 ;
V_204 = F_65 () ;
F_66 ( F_67 () ) ;
V_203 = F_62 () ;
V_205 = F_68 ( V_3 , ( char V_206 * ) V_30 , V_166 , V_107 ) ;
F_63 ( V_203 ) ;
F_66 ( V_204 ) ;
F_55 ( V_2 ) ;
return V_205 ;
}
static T_8 F_69 ( struct V_1 * V_2 , struct V_3 * V_3 , void * V_30 , T_4 V_166 , T_3 * V_107 )
{
T_9 V_204 ;
T_8 V_205 ;
int V_6 , V_203 ;
V_6 = F_57 ( V_2 , V_3 , V_166 , * V_107 ) ;
if ( V_6 )
return V_6 ;
V_204 = F_65 () ;
F_66 ( F_67 () ) ;
V_203 = F_62 () ;
V_205 = F_70 ( V_3 , ( char V_206 * ) V_30 , V_166 , V_107 ) ;
F_63 ( V_203 ) ;
F_66 ( V_204 ) ;
F_55 ( V_2 ) ;
return V_205 ;
}
static inline union V_27 * F_71 ( struct V_1 * V_2 )
{
return & ( V_2 -> V_26 [ V_2 -> V_165 . V_168 ] ) ;
}
static inline T_5 * F_72 ( struct V_1 * V_2 )
{
return F_71 ( V_2 ) -> V_28 + V_2 -> V_165 . V_167 + V_2 -> V_165 . V_175 ;
}
int F_73 ( struct V_1 * V_2 , int V_174 )
{
unsigned int V_92 = V_2 -> V_165 . V_168 ;
if ( F_38 ( V_92 ) ) {
int V_5 ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_174 ) ;
for ( V_5 = 0 ; V_5 < V_174 ; ++ V_5 )
V_2 -> V_30 . V_28 [ V_5 ] = F_74 () ;
F_24 ( L_78 , V_92 ) ;
return 1 ;
}
return 0 ;
}
void F_75 ( struct V_1 * V_2 , int V_174 )
{
if ( V_207 && F_74 () < ( 1 << 22 ) ) {
int V_208 = 1 ;
if ( V_207 > 1 )
V_208 = ( F_74 () % ( int ) V_207 ) + 1 ;
while ( V_208 -- ) {
int V_107 = F_74 () % ( V_174 * 8 ) ;
V_2 -> V_30 . V_28 [ V_107 / 8 ] ^= ( 1 << ( V_107 % 8 ) ) ;
F_24 ( L_79
L_80 ,
V_107 , V_2 -> V_165 . V_168 , V_2 -> V_165 . V_167 + V_2 -> V_165 . V_175 ,
V_209 -> V_210 . V_211 , V_209 -> V_210 . V_212 ) ;
}
}
}
static void F_76 ( struct V_1 * V_2 , int V_174 )
{
union V_27 * V_213 ;
if ( V_2 -> V_4 ) {
if ( ! V_2 -> V_18 [ V_2 -> V_165 . V_168 ] ) {
F_52 ( L_81 , V_2 -> V_165 . V_168 ) ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_174 ) ;
} else {
T_3 V_107 ;
T_8 V_205 ;
F_52 ( L_82 ,
V_2 -> V_165 . V_168 , V_2 -> V_165 . V_167 + V_2 -> V_165 . V_175 ) ;
if ( F_73 ( V_2 , V_174 ) )
return;
V_107 = ( T_3 ) V_2 -> V_165 . V_168 * V_2 -> V_19 . V_23 + V_2 -> V_165 . V_167 + V_2 -> V_165 . V_175 ;
V_205 = F_64 ( V_2 , V_2 -> V_4 , V_2 -> V_30 . V_28 , V_174 , & V_107 ) ;
if ( V_205 != V_174 ) {
F_5 ( L_83 , V_2 -> V_165 . V_168 , ( long ) V_205 ) ;
return;
}
F_75 ( V_2 , V_174 ) ;
}
return;
}
V_213 = F_71 ( V_2 ) ;
if ( V_213 -> V_28 == NULL ) {
F_52 ( L_84 , V_2 -> V_165 . V_168 ) ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_174 ) ;
} else {
F_52 ( L_85 ,
V_2 -> V_165 . V_168 , V_2 -> V_165 . V_167 + V_2 -> V_165 . V_175 ) ;
if ( F_73 ( V_2 , V_174 ) )
return;
memcpy ( V_2 -> V_30 . V_28 , F_72 ( V_2 ) , V_174 ) ;
F_75 ( V_2 , V_174 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
union V_27 * V_213 ;
int V_5 ;
if ( V_2 -> V_4 ) {
for ( V_5 = 0 ; V_5 < V_2 -> V_19 . V_59 ; V_5 ++ )
if ( V_2 -> V_18 [ V_2 -> V_165 . V_168 + V_5 ] ) {
F_52 ( L_86 , V_2 -> V_165 . V_168 + V_5 ) ;
V_2 -> V_18 [ V_2 -> V_165 . V_168 + V_5 ] = 0 ;
}
return;
}
V_213 = F_71 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_19 . V_59 ; V_5 ++ ) {
if ( V_213 -> V_28 != NULL ) {
F_52 ( L_86 , V_2 -> V_165 . V_168 + V_5 ) ;
F_14 ( V_2 -> V_29 , V_213 -> V_28 ) ;
V_213 -> V_28 = NULL ;
}
V_213 ++ ;
}
}
static int F_78 ( struct V_1 * V_2 , int V_174 )
{
int V_5 ;
union V_27 * V_213 ;
T_5 * V_214 ;
if ( V_2 -> V_4 ) {
T_3 V_175 , V_107 ;
T_8 V_205 ;
int V_215 ;
F_52 ( L_87 , V_2 -> V_165 . V_168 ) ;
V_214 = V_2 -> V_22 + V_2 -> V_165 . V_167 + V_2 -> V_165 . V_175 ;
V_175 = ( T_3 ) V_2 -> V_165 . V_168 * V_2 -> V_19 . V_23 + V_2 -> V_165 . V_167 + V_2 -> V_165 . V_175 ;
if ( ! V_2 -> V_18 [ V_2 -> V_165 . V_168 ] ) {
V_215 = 1 ;
memset ( V_2 -> V_22 , 0xff , V_2 -> V_19 . V_23 ) ;
} else {
V_215 = 0 ;
V_107 = V_175 ;
V_205 = F_64 ( V_2 , V_2 -> V_4 , V_214 , V_174 , & V_107 ) ;
if ( V_205 != V_174 ) {
F_5 ( L_88 , V_2 -> V_165 . V_168 , ( long ) V_205 ) ;
return - 1 ;
}
}
for ( V_5 = 0 ; V_5 < V_174 ; V_5 ++ )
V_214 [ V_5 ] &= V_2 -> V_30 . V_28 [ V_5 ] ;
if ( V_215 ) {
V_107 = ( T_3 ) V_2 -> V_165 . V_168 * V_2 -> V_19 . V_23 ;
V_205 = F_69 ( V_2 , V_2 -> V_4 , V_2 -> V_22 , V_2 -> V_19 . V_23 , & V_107 ) ;
if ( V_205 != V_2 -> V_19 . V_23 ) {
F_5 ( L_89 , V_2 -> V_165 . V_168 , ( long ) V_205 ) ;
return - 1 ;
}
V_2 -> V_18 [ V_2 -> V_165 . V_168 ] = 1 ;
} else {
V_107 = V_175 ;
V_205 = F_69 ( V_2 , V_2 -> V_4 , V_214 , V_174 , & V_107 ) ;
if ( V_205 != V_174 ) {
F_5 ( L_89 , V_2 -> V_165 . V_168 , ( long ) V_205 ) ;
return - 1 ;
}
}
return 0 ;
}
V_213 = F_71 ( V_2 ) ;
if ( V_213 -> V_28 == NULL ) {
F_52 ( L_90 , V_2 -> V_165 . V_168 ) ;
V_213 -> V_28 = F_79 ( V_2 -> V_29 , V_198 ) ;
if ( V_213 -> V_28 == NULL ) {
F_5 ( L_91 , V_2 -> V_165 . V_168 ) ;
return - 1 ;
}
memset ( V_213 -> V_28 , 0xFF , V_2 -> V_19 . V_23 ) ;
}
V_214 = F_72 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_174 ; V_5 ++ )
V_214 [ V_5 ] &= V_2 -> V_30 . V_28 [ V_5 ] ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , T_2 V_216 )
{
int V_174 ;
int V_217 = V_2 -> V_43 == 8 ? 1 : 2 ;
unsigned int V_83 , V_92 ;
V_216 &= V_218 ;
if ( V_216 != V_219 && V_2 -> V_165 . V_168 >= V_2 -> V_19 . V_20 ) {
F_24 ( L_92 , V_2 -> V_165 . V_168 ) ;
return - 1 ;
}
switch ( V_216 ) {
case V_220 :
if ( V_2 -> V_165 . V_167 >= ( V_2 -> V_19 . V_23 - V_2 -> V_165 . V_175 ) ) {
F_5 ( L_93 ) ;
break;
}
V_174 = V_2 -> V_19 . V_23 - V_2 -> V_165 . V_175 - V_2 -> V_165 . V_167 ;
F_76 ( V_2 , V_174 ) ;
F_52 ( L_94 ,
V_174 , F_81 ( V_2 ) + V_2 -> V_165 . V_175 ) ;
if ( V_2 -> V_165 . V_175 == 0 )
F_82 ( L_95 , V_2 -> V_165 . V_168 ) ;
else if ( V_2 -> V_165 . V_175 < V_2 -> V_19 . V_48 )
F_82 ( L_96 , V_2 -> V_165 . V_168 ) ;
else
F_82 ( L_97 , V_2 -> V_165 . V_168 ) ;
F_83 ( V_221 ) ;
F_83 ( V_222 * V_2 -> V_19 . V_48 / 1000 / V_217 ) ;
break;
case V_219 :
if ( V_2 -> V_223 . V_95 ) {
F_5 ( L_98 ) ;
return - 1 ;
}
if ( V_2 -> V_165 . V_168 >= V_2 -> V_19 . V_20 - V_2 -> V_19 . V_59
|| ( V_2 -> V_165 . V_168 & ~ ( V_2 -> V_19 . V_52 - 1 ) ) ) {
F_5 ( L_99 , V_2 -> V_165 . V_168 ) ;
return - 1 ;
}
V_2 -> V_165 . V_168 = ( V_2 -> V_165 . V_168 <<
8 * ( V_2 -> V_19 . V_68 - V_2 -> V_19 . V_69 ) ) | V_2 -> V_165 . V_167 ;
V_2 -> V_165 . V_167 = 0 ;
V_83 = V_2 -> V_165 . V_168 >> ( V_2 -> V_19 . V_55 - V_2 -> V_19 . V_56 ) ;
F_52 ( L_100 ,
V_2 -> V_165 . V_168 , F_81 ( V_2 ) ) ;
F_82 ( L_101 , V_83 ) ;
F_77 ( V_2 ) ;
F_84 ( V_224 ) ;
if ( V_108 )
F_44 ( V_83 ) ;
if ( F_33 ( V_83 ) ) {
F_24 ( L_102 , V_83 ) ;
return - 1 ;
}
break;
case V_225 :
if ( V_2 -> V_223 . V_95 ) {
F_24 ( L_103 ) ;
return - 1 ;
}
V_174 = V_2 -> V_19 . V_23 - V_2 -> V_165 . V_175 - V_2 -> V_165 . V_167 ;
if ( V_174 != V_2 -> V_165 . V_166 ) {
F_5 ( L_104 ,
V_2 -> V_165 . V_166 , V_174 ) ;
return - 1 ;
}
if ( F_78 ( V_2 , V_174 ) == - 1 )
return - 1 ;
V_92 = V_2 -> V_165 . V_168 ;
F_52 ( L_105 ,
V_174 , V_2 -> V_165 . V_168 , V_2 -> V_165 . V_167 , F_81 ( V_2 ) + V_2 -> V_165 . V_175 ) ;
F_82 ( L_106 , V_2 -> V_165 . V_168 ) ;
F_83 ( V_226 ) ;
F_83 ( V_227 * V_2 -> V_19 . V_48 / 1000 / V_217 ) ;
if ( F_36 ( V_92 ) ) {
F_24 ( L_107 , V_92 ) ;
return - 1 ;
}
break;
case V_228 :
F_52 ( L_108 ) ;
V_2 -> V_165 . V_175 = 0 ;
break;
case V_229 :
if ( ! ( V_2 -> V_44 & V_64 ) ) {
F_5 ( L_109
L_110 ) ;
return - 1 ;
}
F_52 ( L_111 , V_2 -> V_19 . V_48 / 2 ) ;
V_2 -> V_165 . V_175 = V_2 -> V_19 . V_48 / 2 ;
break;
case V_230 :
F_52 ( L_111 , V_2 -> V_19 . V_48 ) ;
V_2 -> V_165 . V_175 = V_2 -> V_19 . V_48 ;
break;
default:
F_52 ( L_112 ) ;
}
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
if ( V_2 -> V_171 ) {
V_2 -> V_173 += 1 ;
V_2 -> V_122 = V_2 -> V_170 ;
V_2 -> V_170 = V_2 -> V_171 [ V_2 -> V_173 + 1 ] ;
F_52 ( L_113
L_114 ,
F_46 ( V_2 -> V_122 ) , F_46 ( V_2 -> V_170 ) ) ;
if ( ( V_2 -> V_122 & V_218 ) && F_80 ( V_2 , V_2 -> V_122 ) < 0 ) {
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
} else {
V_2 -> V_122 = F_49 ( V_2 -> V_165 . V_163 ) ;
F_52 ( L_115 ) ;
if ( F_53 ( V_2 , 0 ) != 0 )
return;
if ( ( V_2 -> V_122 & V_218 ) && F_80 ( V_2 , V_2 -> V_122 ) < 0 ) {
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
}
if ( ( V_2 -> V_170 & V_185 ) && V_2 -> V_43 == 16 ) {
F_52 ( L_116 ) ;
V_2 -> V_165 . V_167 <<= 1 ;
}
if ( F_47 ( V_2 -> V_170 ) == V_146 ) {
T_5 V_169 = F_86 ( V_2 ) ;
if ( ( V_2 -> V_122 & ( V_231 | V_232 ) )
&& V_2 -> V_165 . V_166 != V_2 -> V_165 . V_174 ) {
F_24 ( L_117 ,
V_2 -> V_165 . V_174 - V_2 -> V_165 . V_166 ) ;
V_169 = F_54 ( V_2 ) ;
}
F_52 ( L_118 ) ;
F_51 ( V_2 , V_169 ) ;
return;
} else if ( V_2 -> V_170 & ( V_231 | V_232 ) ) {
V_2 -> V_122 = V_2 -> V_170 ;
V_2 -> V_170 = V_2 -> V_171 [ ++ V_2 -> V_173 + 1 ] ;
V_2 -> V_165 . V_174 = V_2 -> V_165 . V_166 = 0 ;
F_52 ( L_119
L_114 ,
F_46 ( V_2 -> V_122 ) , F_46 ( V_2 -> V_170 ) ) ;
switch ( F_47 ( V_2 -> V_122 ) ) {
case V_141 :
case V_142 :
V_2 -> V_165 . V_174 = V_2 -> V_19 . V_23 - V_2 -> V_165 . V_175 - V_2 -> V_165 . V_167 ;
break;
case V_143 :
V_2 -> V_165 . V_174 = V_2 -> V_19 . V_233 ;
break;
case V_144 :
case V_145 :
V_2 -> V_165 . V_166 = V_2 -> V_165 . V_174 = 0 ;
break;
default:
F_5 ( L_120 ) ;
}
} else if ( V_2 -> V_170 & V_185 ) {
V_2 -> V_165 . V_166 = 0 ;
switch ( F_47 ( V_2 -> V_170 ) ) {
case V_137 :
V_2 -> V_165 . V_174 = V_2 -> V_19 . V_68 ;
break;
case V_138 :
V_2 -> V_165 . V_174 = V_2 -> V_19 . V_69 ;
break;
case V_139 :
V_2 -> V_165 . V_174 = 1 ;
break;
case V_140 :
V_2 -> V_165 . V_174 = V_2 -> V_19 . V_68 - V_2 -> V_19 . V_69 ;
break;
default:
F_5 ( L_121 ) ;
}
} else {
V_2 -> V_165 . V_174 = 0 ;
V_2 -> V_165 . V_166 = 0 ;
}
}
static T_5 F_87 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
T_5 V_234 = 0x00 ;
if ( ! V_2 -> V_223 . V_235 ) {
F_5 ( L_122 , ( T_6 ) V_234 ) ;
return V_234 ;
}
if ( V_2 -> V_223 . V_236 || V_2 -> V_223 . V_237 ) {
F_5 ( L_123 , ( T_6 ) V_234 ) ;
return V_234 ;
}
if ( ! ( V_2 -> V_122 & V_232 ) ) {
F_24 ( L_124
L_125 , F_46 ( V_2 -> V_122 ) , ( T_6 ) V_234 ) ;
return V_234 ;
}
if ( F_47 ( V_2 -> V_122 ) == V_144 ) {
F_52 ( L_126 , V_2 -> V_165 . V_169 ) ;
return V_2 -> V_165 . V_169 ;
}
if ( V_2 -> V_165 . V_166 == V_2 -> V_165 . V_174 ) {
F_24 ( L_127 , ( T_6 ) V_234 ) ;
return V_234 ;
}
switch ( F_47 ( V_2 -> V_122 ) ) {
case V_142 :
if ( V_2 -> V_43 == 8 ) {
V_234 = V_2 -> V_30 . V_28 [ V_2 -> V_165 . V_166 ] ;
V_2 -> V_165 . V_166 += 1 ;
} else {
V_234 = ( T_5 ) F_88 ( V_2 -> V_30 . V_238 [ V_2 -> V_165 . V_166 >> 1 ] ) ;
V_2 -> V_165 . V_166 += 2 ;
}
break;
case V_143 :
F_52 ( L_128 , V_2 -> V_165 . V_166 , V_2 -> V_165 . V_174 ) ;
V_234 = V_2 -> V_239 [ V_2 -> V_165 . V_166 ] ;
V_2 -> V_165 . V_166 += 1 ;
break;
default:
F_89 () ;
}
if ( V_2 -> V_165 . V_166 == V_2 -> V_165 . V_174 ) {
F_52 ( L_129 ) ;
if ( ( V_2 -> V_44 & V_63 ) && F_47 ( V_2 -> V_122 ) == V_142 ) {
V_2 -> V_165 . V_166 = 0 ;
if ( V_2 -> V_165 . V_168 + 1 < V_2 -> V_19 . V_20 )
V_2 -> V_165 . V_168 += 1 ;
F_52 ( L_130 , V_2 -> V_165 . V_168 ) ;
F_80 ( V_2 , V_220 ) ;
}
else if ( F_47 ( V_2 -> V_170 ) == V_146 )
F_85 ( V_2 ) ;
}
return V_234 ;
}
static void F_90 ( struct V_33 * V_34 , T_5 V_28 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
if ( ! V_2 -> V_223 . V_235 ) {
F_5 ( L_131 ) ;
return;
}
if ( V_2 -> V_223 . V_236 && V_2 -> V_223 . V_237 ) {
F_5 ( L_132 ) ;
return;
}
if ( V_2 -> V_223 . V_237 == 1 ) {
if ( V_28 == V_159 ) {
F_82 ( L_133 ) ;
F_51 ( V_2 , F_86 ( V_2 ) ) ;
return;
}
if ( F_48 ( V_28 ) ) {
F_5 ( L_134 , ( T_6 ) V_28 ) ;
return;
}
if ( F_47 ( V_2 -> V_122 ) == V_144
|| F_47 ( V_2 -> V_122 ) == V_145
|| F_47 ( V_2 -> V_122 ) == V_142 ) {
int V_168 = V_2 -> V_165 . V_168 ;
F_85 ( V_2 ) ;
if ( V_28 == V_160 )
V_2 -> V_165 . V_168 = V_168 ;
}
if ( F_47 ( V_2 -> V_170 ) != V_147 && ! ( V_2 -> V_170 & V_240 ) ) {
if ( ! ( V_2 -> V_165 . V_163 == V_157 &&
F_47 ( V_2 -> V_122 ) == V_143 && V_2 -> V_165 . V_166 == 2 ) ) {
F_24 ( L_135
L_136 , ( T_6 ) V_28 , F_46 ( V_2 -> V_170 ) ) ;
}
F_51 ( V_2 , F_54 ( V_2 ) ) ;
}
F_52 ( L_137 ,
F_46 ( F_49 ( V_28 ) ) ) ;
V_2 -> V_165 . V_163 = V_28 ;
F_85 ( V_2 ) ;
} else if ( V_2 -> V_223 . V_236 == 1 ) {
if ( F_47 ( V_2 -> V_170 ) == V_147 ) {
F_52 ( L_138 ) ;
if ( F_53 ( V_2 , 1 ) < 0 )
return;
if ( ( V_2 -> V_122 & V_218 ) && F_80 ( V_2 , V_2 -> V_122 ) < 0 ) {
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
V_2 -> V_165 . V_166 = 0 ;
switch ( F_47 ( V_2 -> V_170 ) ) {
case V_137 :
V_2 -> V_165 . V_174 = V_2 -> V_19 . V_68 ;
break;
case V_138 :
V_2 -> V_165 . V_174 = V_2 -> V_19 . V_69 ;
break;
case V_139 :
V_2 -> V_165 . V_174 = 1 ;
break;
default:
F_89 () ;
}
}
if ( ! ( V_2 -> V_170 & V_185 ) ) {
F_5 ( L_139
L_140 , ( T_6 ) V_28 , F_46 ( V_2 -> V_170 ) ) ;
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_165 . V_166 == V_2 -> V_165 . V_174 ) {
F_5 ( L_141 ) ;
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
F_50 ( V_2 , V_28 ) ;
V_2 -> V_165 . V_166 += 1 ;
F_52 ( L_142 ,
( T_6 ) V_28 , V_2 -> V_165 . V_166 , V_2 -> V_165 . V_174 ) ;
if ( V_2 -> V_165 . V_166 == V_2 -> V_165 . V_174 ) {
F_52 ( L_143 , V_2 -> V_165 . V_168 , V_2 -> V_165 . V_167 ) ;
F_85 ( V_2 ) ;
}
} else {
if ( ! ( V_2 -> V_122 & V_231 ) ) {
F_5 ( L_144
L_145 , ( T_6 ) V_28 ,
F_46 ( V_2 -> V_122 ) , F_46 ( V_146 ) ) ;
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_165 . V_166 == V_2 -> V_165 . V_174 ) {
F_24 ( L_146 ,
V_2 -> V_165 . V_174 ) ;
return;
}
if ( V_2 -> V_43 == 8 ) {
V_2 -> V_30 . V_28 [ V_2 -> V_165 . V_166 ] = V_28 ;
V_2 -> V_165 . V_166 += 1 ;
} else {
V_2 -> V_30 . V_238 [ V_2 -> V_165 . V_166 >> 1 ] = F_88 ( ( V_241 ) V_28 ) ;
V_2 -> V_165 . V_166 += 2 ;
}
}
return;
}
static void F_91 ( struct V_33 * V_34 , int V_148 , unsigned int V_242 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
V_2 -> V_223 . V_237 = V_242 & V_243 ? 1 : 0 ;
V_2 -> V_223 . V_236 = V_242 & V_244 ? 1 : 0 ;
V_2 -> V_223 . V_235 = V_242 & V_245 ? 1 : 0 ;
if ( V_148 != V_246 )
F_90 ( V_34 , V_148 ) ;
}
static int F_92 ( struct V_33 * V_34 )
{
F_52 ( L_147 ) ;
return 1 ;
}
static V_241 F_93 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = (struct V_35 * ) V_34 -> V_37 ;
F_52 ( L_148 ) ;
return V_36 -> V_247 ( V_34 ) | ( V_36 -> V_247 ( V_34 ) << 8 ) ;
}
static void F_94 ( struct V_33 * V_34 , const T_5 * V_30 , int V_248 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
if ( ! ( V_2 -> V_122 & V_231 ) ) {
F_5 ( L_149
L_140 , F_46 ( V_2 -> V_122 ) ) ;
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_165 . V_166 + V_248 > V_2 -> V_165 . V_174 ) {
F_5 ( L_150 ) ;
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
memcpy ( V_2 -> V_30 . V_28 + V_2 -> V_165 . V_166 , V_30 , V_248 ) ;
V_2 -> V_165 . V_166 += V_248 ;
if ( V_2 -> V_165 . V_166 == V_2 -> V_165 . V_174 ) {
F_52 ( L_151 , V_2 -> V_165 . V_166 ) ;
}
}
static void F_95 ( struct V_33 * V_34 , T_5 * V_30 , int V_248 )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_34 -> V_37 ) -> V_37 ;
if ( ! V_2 -> V_223 . V_235 ) {
F_5 ( L_152 ) ;
return;
}
if ( V_2 -> V_223 . V_236 || V_2 -> V_223 . V_237 ) {
F_5 ( L_153 ) ;
return;
}
if ( ! ( V_2 -> V_122 & V_232 ) ) {
F_24 ( L_154 ,
F_46 ( V_2 -> V_122 ) ) ;
return;
}
if ( F_47 ( V_2 -> V_122 ) != V_142 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_248 ; V_5 ++ )
V_30 [ V_5 ] = ( (struct V_35 * ) V_34 -> V_37 ) -> V_247 ( V_34 ) ;
return;
}
if ( V_2 -> V_165 . V_166 + V_248 > V_2 -> V_165 . V_174 ) {
F_5 ( L_155 ) ;
F_51 ( V_2 , F_54 ( V_2 ) ) ;
return;
}
memcpy ( V_30 , V_2 -> V_30 . V_28 + V_2 -> V_165 . V_166 , V_248 ) ;
V_2 -> V_165 . V_166 += V_248 ;
if ( V_2 -> V_165 . V_166 == V_2 -> V_165 . V_174 ) {
if ( ( V_2 -> V_44 & V_63 ) && F_47 ( V_2 -> V_122 ) == V_142 ) {
V_2 -> V_165 . V_166 = 0 ;
if ( V_2 -> V_165 . V_168 + 1 < V_2 -> V_19 . V_20 )
V_2 -> V_165 . V_168 += 1 ;
F_52 ( L_156 , V_2 -> V_165 . V_168 ) ;
F_80 ( V_2 , V_220 ) ;
}
else if ( F_47 ( V_2 -> V_170 ) == V_146 )
F_85 ( V_2 ) ;
}
return;
}
static int F_96 ( struct V_33 * V_34 , const T_5 * V_30 , int V_248 )
{
F_95 ( V_34 , ( T_5 * ) & V_249 [ 0 ] , V_248 ) ;
if ( ! memcmp ( V_30 , & V_249 [ 0 ] , V_248 ) ) {
F_52 ( L_157 ) ;
return 0 ;
} else {
F_52 ( L_158 ) ;
return - V_250 ;
}
}
static int T_10 F_97 ( void )
{
struct V_35 * V_36 ;
struct V_1 * V_251 ;
int V_252 = - V_21 , V_5 ;
if ( V_253 != 8 && V_253 != 16 ) {
F_5 ( L_159 , V_253 ) ;
return - V_14 ;
}
V_209 = F_31 ( sizeof( struct V_33 ) + sizeof( struct V_35 )
+ sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_209 ) {
F_5 ( L_160 ) ;
return - V_21 ;
}
V_36 = (struct V_35 * ) ( V_209 + 1 ) ;
V_209 -> V_37 = ( void * ) V_36 ;
V_251 = (struct V_1 * ) ( V_36 + 1 ) ;
V_36 -> V_37 = ( void * ) V_251 ;
V_36 -> V_254 = F_91 ;
V_36 -> V_247 = F_87 ;
V_36 -> V_255 = F_92 ;
V_36 -> V_256 = F_94 ;
V_36 -> V_257 = F_95 ;
V_36 -> V_258 = F_96 ;
V_36 -> V_259 = F_93 ;
V_36 -> V_260 . V_261 = V_262 ;
V_36 -> V_44 |= V_263 ;
switch ( V_264 ) {
case 2 :
V_36 -> V_265 |= V_266 ;
case 1 :
V_36 -> V_265 |= V_267 ;
case 0 :
break;
default:
F_5 ( L_161 ) ;
V_252 = - V_14 ;
goto error;
}
if ( V_268 != 0xFF || V_269 != 0xFF )
V_251 -> V_19 . V_233 = 4 ;
else
V_251 -> V_19 . V_233 = 2 ;
V_251 -> V_165 . V_169 = F_86 ( V_251 ) ;
V_251 -> V_170 = V_147 ;
V_251 -> V_44 |= V_61 ;
V_251 -> V_239 [ 0 ] = V_270 ;
V_251 -> V_239 [ 1 ] = V_78 ;
V_251 -> V_239 [ 2 ] = V_268 ;
V_251 -> V_239 [ 3 ] = V_269 ;
if ( V_253 == 16 ) {
V_251 -> V_43 = 16 ;
V_36 -> V_44 |= V_45 ;
}
V_209 -> V_271 = V_272 ;
if ( ( V_252 = F_30 () ) != 0 )
goto error;
if ( ( V_252 = F_35 () ) != 0 )
goto error;
if ( ( V_252 = F_37 () ) != 0 )
goto error;
V_252 = F_98 ( V_209 , 1 , NULL ) ;
if ( V_252 ) {
F_5 ( L_162 ) ;
if ( V_252 > 0 )
V_252 = - V_273 ;
goto error;
}
if ( V_274 ) {
unsigned int V_275 , V_276 ;
if ( ! F_99 () ) {
F_5 ( L_163 ) ;
V_252 = - V_14 ;
goto error;
}
V_275 = V_209 -> V_49 / 512 ;
V_276 = ( V_274 * 13 + 7 ) / 8 ;
if ( ( V_209 -> V_51 < 64 ) || ! V_275 ) {
F_5 ( L_164 ) ;
V_252 = - V_14 ;
goto error;
}
if ( ( V_276 * V_275 + 2 ) > V_209 -> V_51 ) {
F_5 ( L_165 , V_274 ) ;
V_252 = - V_14 ;
goto error;
}
V_36 -> V_260 . V_261 = V_277 ;
V_36 -> V_260 . V_47 = 512 ;
V_36 -> V_260 . V_278 = V_276 ;
F_45 ( L_166 , V_274 , V_36 -> V_260 . V_47 ) ;
}
V_252 = F_100 ( V_209 ) ;
if ( V_252 ) {
F_5 ( L_167 ) ;
if ( V_252 > 0 )
V_252 = - V_273 ;
goto error;
}
if ( V_279 ) {
T_1 V_280 = ( T_1 ) V_209 -> V_53 << V_279 ;
if ( V_280 >> V_279 != V_209 -> V_53 ) {
F_5 ( L_168 ) ;
goto V_281;
}
V_209 -> V_47 = V_280 ;
V_36 -> V_282 = V_280 ;
V_36 -> V_283 = F_22 ( V_209 -> V_53 ) + V_279 - 1 ;
V_36 -> V_284 = ( V_36 -> V_282 >> V_36 -> V_57 ) - 1 ;
}
if ( ( V_252 = F_43 ( V_209 ) ) != 0 )
goto V_281;
if ( ( V_252 = F_20 ( V_209 ) ) != 0 )
goto V_281;
if ( ( V_252 = F_101 ( V_209 ) ) != 0 )
goto V_281;
if ( ( V_252 = F_27 ( V_251 , V_209 ) ) != 0 )
goto V_281;
V_252 = F_102 ( V_209 , & V_251 -> V_71 [ 0 ] ,
V_251 -> V_76 ) ;
if ( V_252 != 0 )
goto V_281;
return 0 ;
V_281:
F_26 ( V_251 ) ;
F_103 ( V_209 ) ;
for ( V_5 = 0 ; V_5 < F_23 ( V_251 -> V_71 ) ; ++ V_5 )
F_13 ( V_251 -> V_71 [ V_5 ] . V_74 ) ;
error:
F_13 ( V_209 ) ;
F_39 () ;
return V_252 ;
}
static void T_11 F_104 ( void )
{
struct V_1 * V_2 = ( (struct V_35 * ) V_209 -> V_37 ) -> V_37 ;
int V_5 ;
F_26 ( V_2 ) ;
F_103 ( V_209 ) ;
for ( V_5 = 0 ; V_5 < F_23 ( V_2 -> V_71 ) ; ++ V_5 )
F_13 ( V_2 -> V_71 [ V_5 ] . V_74 ) ;
F_13 ( V_209 ) ;
F_39 () ;
}
