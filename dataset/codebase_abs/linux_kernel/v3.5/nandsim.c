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
static int F_18 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_35 ;
struct V_1 * V_2 = V_34 -> V_35 ;
int V_5 , V_36 = 0 ;
T_1 V_37 ;
T_1 V_38 ;
if ( F_19 ( V_2 ) ) {
F_5 ( L_9 ) ;
return - V_39 ;
}
V_34 -> V_40 = 0 ;
V_2 -> V_41 = V_34 -> V_42 & V_43 ? 16 : 8 ;
V_2 -> V_19 . V_44 = V_32 -> V_45 ;
V_2 -> V_19 . V_46 = V_32 -> V_47 ;
V_2 -> V_19 . V_48 = V_32 -> V_49 ;
V_2 -> V_19 . V_50 = V_32 -> V_51 ;
V_2 -> V_19 . V_23 = V_2 -> V_19 . V_46 + V_2 -> V_19 . V_48 ;
V_2 -> V_19 . V_20 = F_20 ( V_2 -> V_19 . V_44 , V_2 -> V_19 . V_46 ) ;
V_2 -> V_19 . V_52 = V_2 -> V_19 . V_44 + ( T_1 ) V_2 -> V_19 . V_20 * V_2 -> V_19 . V_48 ;
V_2 -> V_19 . V_53 = F_21 ( V_2 -> V_19 . V_50 ) - 1 ;
V_2 -> V_19 . V_54 = V_34 -> V_55 ;
V_2 -> V_19 . V_56 = F_21 ( V_2 -> V_19 . V_48 ) - 1 ;
V_2 -> V_19 . V_57 = V_2 -> V_19 . V_50 / V_2 -> V_19 . V_46 ;
V_2 -> V_19 . V_58 = V_2 -> V_19 . V_50 + V_2 -> V_19 . V_48 * V_2 -> V_19 . V_57 ;
V_2 -> V_42 = 0 ;
if ( V_2 -> V_19 . V_46 == 256 ) {
V_2 -> V_42 |= V_59 ;
}
else if ( V_2 -> V_19 . V_46 == 512 ) {
V_2 -> V_42 |= V_60 ;
if ( V_2 -> V_41 == 8 )
V_2 -> V_42 |= V_61 ;
} else if ( V_2 -> V_19 . V_46 == 2048 ) {
V_2 -> V_42 |= V_62 ;
} else if ( V_2 -> V_19 . V_46 == 4096 ) {
V_2 -> V_42 |= V_63 ;
} else {
F_5 ( L_10 , V_2 -> V_19 . V_46 ) ;
return - V_39 ;
}
if ( V_2 -> V_42 & V_64 ) {
if ( V_2 -> V_19 . V_44 <= ( 32 << 20 ) ) {
V_2 -> V_19 . V_65 = 3 ;
V_2 -> V_19 . V_66 = 2 ;
} else {
V_2 -> V_19 . V_65 = 4 ;
V_2 -> V_19 . V_66 = 3 ;
}
} else {
if ( V_2 -> V_19 . V_44 <= ( 128 << 20 ) ) {
V_2 -> V_19 . V_65 = 4 ;
V_2 -> V_19 . V_66 = 2 ;
} else {
V_2 -> V_19 . V_65 = 5 ;
V_2 -> V_19 . V_66 = 3 ;
}
}
if ( V_67 > F_22 ( V_2 -> V_68 ) ) {
F_5 ( L_11 ) ;
V_36 = - V_14 ;
goto error;
}
V_37 = V_2 -> V_19 . V_44 ;
V_38 = 0 ;
for ( V_5 = 0 ; V_5 < V_67 ; ++ V_5 ) {
T_1 V_69 = ( T_1 ) V_70 [ V_5 ] * V_2 -> V_19 . V_50 ;
if ( ! V_69 || V_69 > V_37 ) {
F_5 ( L_12 ) ;
V_36 = - V_14 ;
goto error;
}
V_2 -> V_68 [ V_5 ] . V_71 = F_16 ( V_5 ) ;
V_2 -> V_68 [ V_5 ] . V_72 = V_38 ;
V_2 -> V_68 [ V_5 ] . V_45 = V_69 ;
V_38 += V_2 -> V_68 [ V_5 ] . V_45 ;
V_37 -= V_2 -> V_68 [ V_5 ] . V_45 ;
}
V_2 -> V_73 = V_67 ;
if ( V_37 ) {
if ( V_67 + 1 > F_22 ( V_2 -> V_68 ) ) {
F_5 ( L_11 ) ;
V_36 = - V_14 ;
goto error;
}
V_2 -> V_68 [ V_5 ] . V_71 = F_16 ( V_5 ) ;
V_2 -> V_68 [ V_5 ] . V_72 = V_38 ;
V_2 -> V_68 [ V_5 ] . V_45 = V_37 ;
V_2 -> V_73 += 1 ;
}
for ( V_5 = 0 ; V_74 [ V_5 ] . V_71 != NULL ; V_5 ++ ) {
if ( V_75 != V_74 [ V_5 ] . V_76 )
continue;
}
if ( V_2 -> V_41 == 16 )
F_23 ( L_13 ) ;
F_24 ( L_14 ,
( unsigned long long ) V_2 -> V_19 . V_44 >> 20 ) ;
F_24 ( L_15 , V_2 -> V_19 . V_46 ) ;
F_24 ( L_16 , V_2 -> V_19 . V_48 ) ;
F_24 ( L_17 , V_2 -> V_19 . V_50 >> 10 ) ;
F_24 ( L_18 , V_2 -> V_19 . V_20 ) ;
F_24 ( L_19 , V_2 -> V_19 . V_57 ) ;
F_24 ( L_20 , V_2 -> V_41 ) ;
F_24 ( L_21 , V_2 -> V_19 . V_53 ) ;
F_24 ( L_22 , V_2 -> V_19 . V_54 ) ;
F_24 ( L_23 , V_2 -> V_19 . V_56 ) ;
F_24 ( L_24 ,
( unsigned long long ) V_2 -> V_19 . V_52 >> 10 ) ;
F_24 ( L_25 , V_2 -> V_19 . V_65 ) ;
F_24 ( L_26 , V_2 -> V_19 . V_66 ) ;
F_24 ( L_27 , V_2 -> V_42 ) ;
if ( ( V_36 = F_1 ( V_2 ) ) != 0 )
goto error;
V_2 -> V_30 . V_28 = F_7 ( V_2 -> V_19 . V_23 , V_24 ) ;
if ( ! V_2 -> V_30 . V_28 ) {
F_5 ( L_28 ,
V_2 -> V_19 . V_23 ) ;
V_36 = - V_21 ;
goto error;
}
memset ( V_2 -> V_30 . V_28 , 0xFF , V_2 -> V_19 . V_23 ) ;
return 0 ;
error:
F_12 ( V_2 ) ;
return V_36 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_30 . V_28 ) ;
F_12 ( V_2 ) ;
return;
}
static int F_26 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
char * V_77 ;
int V_78 ;
unsigned int V_79 ;
T_2 V_72 ;
if ( ! V_80 )
return 0 ;
V_77 = V_80 ;
do {
V_78 = ( * V_77 == '0' ? 1 : 0 ) ;
V_79 = F_27 ( V_77 , & V_77 , 0 ) ;
if ( ! V_78 && ! V_79 ) {
F_5 ( L_29 ) ;
return - V_14 ;
}
V_72 = V_79 * V_2 -> V_19 . V_50 ;
if ( F_28 ( V_32 , V_72 ) ) {
F_5 ( L_29 ) ;
return - V_14 ;
}
if ( * V_77 == ',' )
V_77 += 1 ;
} while ( * V_77 );
return 0 ;
}
static int F_29 ( void )
{
char * V_77 ;
int V_78 ;
unsigned int V_79 ;
unsigned int V_81 ;
struct V_82 * V_83 ;
if ( ! V_84 )
return 0 ;
V_77 = V_84 ;
do {
V_78 = ( * V_77 == '0' ? 1 : 0 ) ;
V_79 = F_27 ( V_77 , & V_77 , 0 ) ;
if ( ! V_78 && ! V_79 ) {
F_5 ( L_30 ) ;
return - V_14 ;
}
V_81 = 3 ;
if ( * V_77 == ':' ) {
V_77 += 1 ;
V_81 = F_27 ( V_77 , & V_77 , 0 ) ;
}
if ( * V_77 == ',' )
V_77 += 1 ;
V_83 = F_30 ( sizeof( * V_83 ) , V_24 ) ;
if ( ! V_83 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_83 -> V_79 = V_79 ;
V_83 -> V_81 = V_81 ;
F_31 ( & V_83 -> V_85 , & V_86 ) ;
} while ( * V_77 );
return 0 ;
}
static int F_32 ( unsigned int V_79 )
{
struct V_82 * V_83 ;
F_33 (wb, &weak_blocks, list)
if ( V_83 -> V_79 == V_79 ) {
if ( V_83 -> V_87 >= V_83 -> V_81 )
return 1 ;
V_83 -> V_87 += 1 ;
return 0 ;
}
return 0 ;
}
static int F_34 ( void )
{
char * V_77 ;
int V_78 ;
unsigned int V_88 ;
unsigned int V_89 ;
struct V_90 * V_91 ;
if ( ! V_92 )
return 0 ;
V_77 = V_92 ;
do {
V_78 = ( * V_77 == '0' ? 1 : 0 ) ;
V_88 = F_27 ( V_77 , & V_77 , 0 ) ;
if ( ! V_78 && ! V_88 ) {
F_5 ( L_32 ) ;
return - V_14 ;
}
V_89 = 3 ;
if ( * V_77 == ':' ) {
V_77 += 1 ;
V_89 = F_27 ( V_77 , & V_77 , 0 ) ;
}
if ( * V_77 == ',' )
V_77 += 1 ;
V_91 = F_30 ( sizeof( * V_91 ) , V_24 ) ;
if ( ! V_91 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_91 -> V_88 = V_88 ;
V_91 -> V_89 = V_89 ;
F_31 ( & V_91 -> V_85 , & V_93 ) ;
} while ( * V_77 );
return 0 ;
}
static int F_35 ( unsigned int V_88 )
{
struct V_90 * V_91 ;
F_33 (wp, &weak_pages, list)
if ( V_91 -> V_88 == V_88 ) {
if ( V_91 -> V_94 >= V_91 -> V_89 )
return 1 ;
V_91 -> V_94 += 1 ;
return 0 ;
}
return 0 ;
}
static int F_36 ( void )
{
char * V_95 ;
int V_78 ;
unsigned int V_88 ;
unsigned int V_96 ;
struct V_97 * V_98 ;
if ( ! V_99 )
return 0 ;
V_95 = V_99 ;
do {
V_78 = ( * V_95 == '0' ? 1 : 0 ) ;
V_88 = F_27 ( V_95 , & V_95 , 0 ) ;
if ( ! V_78 && ! V_88 ) {
F_5 ( L_33 ) ;
return - V_14 ;
}
V_96 = 3 ;
if ( * V_95 == ':' ) {
V_95 += 1 ;
V_96 = F_27 ( V_95 , & V_95 , 0 ) ;
}
if ( * V_95 == ',' )
V_95 += 1 ;
V_98 = F_30 ( sizeof( * V_98 ) , V_24 ) ;
if ( ! V_98 ) {
F_5 ( L_31 ) ;
return - V_21 ;
}
V_98 -> V_88 = V_88 ;
V_98 -> V_96 = V_96 ;
F_31 ( & V_98 -> V_85 , & V_100 ) ;
} while ( * V_95 );
return 0 ;
}
static int F_37 ( unsigned int V_88 )
{
struct V_97 * V_98 ;
F_33 (gp, &grave_pages, list)
if ( V_98 -> V_88 == V_88 ) {
if ( V_98 -> V_101 >= V_98 -> V_96 )
return 1 ;
V_98 -> V_101 += 1 ;
return 0 ;
}
return 0 ;
}
static void F_38 ( void )
{
struct V_102 * V_103 , * V_104 ;
F_39 (pos, n, &weak_blocks) {
F_40 ( V_103 ) ;
F_13 ( F_41 ( V_103 , struct V_82 , V_85 ) ) ;
}
F_39 (pos, n, &weak_pages) {
F_40 ( V_103 ) ;
F_13 ( F_41 ( V_103 , struct V_90 , V_85 ) ) ;
}
F_39 (pos, n, &grave_pages) {
F_40 ( V_103 ) ;
F_13 ( F_41 ( V_103 , struct V_97 , V_85 ) ) ;
}
F_13 ( V_105 ) ;
}
static int F_42 ( struct V_31 * V_32 )
{
T_3 V_106 ;
if ( ! V_107 )
return 0 ;
V_108 = F_20 ( V_32 -> V_45 , V_32 -> V_51 ) ;
V_106 = V_108 * sizeof( unsigned long ) ;
if ( V_106 / sizeof( unsigned long ) != V_108 ) {
F_5 ( L_34 ) ;
return - V_21 ;
}
V_105 = F_30 ( V_106 , V_24 ) ;
if ( ! V_105 ) {
F_5 ( L_34 ) ;
return - V_21 ;
}
return 0 ;
}
static void F_43 ( unsigned int V_79 )
{
unsigned long V_109 = - 1 , V_110 = 0 , V_111 ;
unsigned long V_112 [ 10 ] , V_113 [ 10 ] , V_114 = 0 ;
unsigned int V_5 ;
if ( ! V_105 )
return;
V_115 += 1 ;
if ( V_115 == 0 )
F_5 ( L_35 ) ;
V_105 [ V_79 ] += 1 ;
if ( V_105 [ V_79 ] == 0 )
F_5 ( L_36 , V_79 ) ;
V_116 += 1 ;
if ( V_116 < V_107 )
return;
V_116 = 0 ;
for ( V_5 = 0 ; V_5 < V_108 ; ++ V_5 ) {
unsigned long V_117 = V_105 [ V_5 ] ;
if ( V_117 < V_109 )
V_109 = V_117 ;
if ( V_117 > V_110 )
V_110 = V_117 ;
V_114 += V_117 ;
}
for ( V_5 = 0 ; V_5 < 9 ; ++ V_5 ) {
V_112 [ V_5 ] = 0 ;
V_113 [ V_5 ] = ( V_110 * ( V_5 + 1 ) + 5 ) / 10 ;
}
V_112 [ 9 ] = 0 ;
V_113 [ 9 ] = V_110 ;
for ( V_5 = 0 ; V_5 < V_108 ; ++ V_5 ) {
int V_118 ;
unsigned long V_117 = V_105 [ V_5 ] ;
for ( V_118 = 0 ; V_118 < 10 ; ++ V_118 )
if ( V_117 <= V_113 [ V_118 ] ) {
V_112 [ V_118 ] += 1 ;
break;
}
}
V_111 = V_114 / V_108 ;
F_44 ( L_37 ) ;
F_44 ( L_38 , V_114 ) ;
F_44 ( L_39 , V_108 ) ;
F_44 ( L_40 , V_111 ) ;
F_44 ( L_41 , V_110 ) ;
F_44 ( L_42 , V_109 ) ;
for ( V_5 = 0 ; V_5 < 10 ; ++ V_5 ) {
unsigned long V_119 = ( V_5 ? V_113 [ V_5 - 1 ] + 1 : 0 ) ;
if ( V_119 > V_113 [ V_5 ] )
continue;
F_44 ( L_43 ,
V_119 ,
V_113 [ V_5 ] ,
V_112 [ V_5 ] ) ;
}
F_44 ( L_44 ) ;
}
static char * F_45 ( T_4 V_120 )
{
switch ( F_46 ( V_120 ) ) {
case V_121 :
return L_45 ;
case V_122 :
return L_46 ;
case V_123 :
return L_47 ;
case V_124 :
return L_48 ;
case V_125 :
return L_49 ;
case V_126 :
return L_50 ;
case V_127 :
return L_51 ;
case V_128 :
return L_52 ;
case V_129 :
return L_53 ;
case V_130 :
return L_54 ;
case V_131 :
return L_55 ;
case V_132 :
return L_56 ;
case V_133 :
return L_57 ;
case V_134 :
return L_58 ;
case V_135 :
return L_59 ;
case V_136 :
return L_60 ;
case V_137 :
return L_61 ;
case V_138 :
return L_62 ;
case V_139 :
return L_63 ;
case V_140 :
return L_64 ;
case V_141 :
return L_65 ;
case V_142 :
return L_66 ;
case V_143 :
return L_67 ;
case V_144 :
return L_68 ;
case V_145 :
return L_69 ;
}
F_5 ( L_70 ) ;
return NULL ;
}
static int F_47 ( int V_146 )
{
switch ( V_146 ) {
case V_147 :
case V_148 :
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
return 0 ;
case V_160 :
default:
return 1 ;
}
}
static T_4 F_48 ( unsigned V_161 )
{
switch ( V_161 ) {
case V_147 :
return V_121 ;
case V_148 :
return V_122 ;
case V_150 :
return V_123 ;
case V_149 :
return V_125 ;
case V_151 :
return V_124 ;
case V_152 :
return V_126 ;
case V_153 :
return V_127 ;
case V_160 :
return V_128 ;
case V_154 :
return V_129 ;
case V_155 :
return V_130 ;
case V_156 :
return V_131 ;
case V_157 :
return V_132 ;
case V_158 :
return V_133 ;
case V_159 :
return V_134 ;
}
F_5 ( L_71 ) ;
return 0 ;
}
static inline void F_49 ( struct V_1 * V_2 , T_5 V_162 )
{
T_6 V_28 = ( T_6 ) V_162 ;
if ( V_2 -> V_163 . V_164 < ( V_2 -> V_19 . V_65 - V_2 -> V_19 . V_66 ) )
V_2 -> V_163 . V_165 |= ( V_28 << 8 * V_2 -> V_163 . V_164 ) ;
else {
V_2 -> V_163 . V_166 |= ( V_28 << 8 * ( V_2 -> V_163 . V_164 -
V_2 -> V_19 . V_65 +
V_2 -> V_19 . V_66 ) ) ;
}
return;
}
static inline void F_50 ( struct V_1 * V_2 , T_5 V_167 )
{
F_51 ( L_72 , F_45 ( V_144 ) ) ;
V_2 -> V_120 = V_144 ;
V_2 -> V_168 = V_145 ;
V_2 -> V_169 = NULL ;
V_2 -> V_170 = 0 ;
V_2 -> V_171 = 0 ;
V_2 -> V_163 . V_172 = 0 ;
V_2 -> V_163 . V_164 = 0 ;
V_2 -> V_163 . V_173 = 0 ;
V_2 -> V_163 . V_166 = 0 ;
V_2 -> V_163 . V_165 = 0 ;
V_2 -> V_163 . V_167 = V_167 ;
}
static int F_52 ( struct V_1 * V_2 , T_4 V_174 )
{
int V_175 = 0 ;
int V_5 , V_176 , V_177 = 0 ;
for ( V_5 = 0 ; V_5 < V_178 ; V_5 ++ ) {
int V_179 = 1 ;
if ( ! ( V_2 -> V_42 & V_180 [ V_5 ] . V_181 ) )
continue;
if ( V_174 ) {
if ( ! ( V_180 [ V_5 ] . V_182 [ V_2 -> V_170 ] & V_183 ) )
continue;
} else {
if ( F_46 ( V_2 -> V_120 ) != F_46 ( V_180 [ V_5 ] . V_182 [ V_2 -> V_170 ] ) )
continue;
}
for ( V_176 = 0 ; V_176 < V_2 -> V_170 ; V_176 ++ )
if ( F_46 ( V_180 [ V_5 ] . V_182 [ V_176 ] ) != F_46 ( V_2 -> V_184 [ V_176 ] )
&& ( V_2 -> V_42 & V_180 [ V_177 ] . V_181 ) ) {
V_179 = 0 ;
break;
}
if ( V_179 ) {
V_177 = V_5 ;
V_175 += 1 ;
}
}
if ( V_175 == 1 ) {
V_2 -> V_169 = & V_180 [ V_177 ] . V_182 [ 0 ] ;
if ( V_174 ) {
V_2 -> V_171 = V_2 -> V_170 - 1 ;
} else {
V_2 -> V_171 = V_2 -> V_170 ;
}
V_2 -> V_170 = 0 ;
V_2 -> V_120 = V_2 -> V_169 [ V_2 -> V_171 ] ;
V_2 -> V_168 = V_2 -> V_169 [ V_2 -> V_171 + 1 ] ;
F_51 ( L_73 ,
V_177 , F_45 ( V_2 -> V_120 ) , F_45 ( V_2 -> V_168 ) ) ;
return 0 ;
}
if ( V_175 == 0 ) {
if ( V_2 -> V_170 != 0 ) {
F_51 ( L_74 ,
F_45 ( V_2 -> V_120 ) ) ;
V_2 -> V_170 = 0 ;
return F_52 ( V_2 , 0 ) ;
}
F_51 ( L_75 ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return - 2 ;
}
if ( V_174 ) {
F_51 ( L_76 ) ;
return - 2 ;
}
F_51 ( L_77 ) ;
V_2 -> V_184 [ V_2 -> V_170 ++ ] = V_2 -> V_120 ;
return - 1 ;
}
static void F_54 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_185 ; V_5 ++ )
F_55 ( V_2 -> V_186 [ V_5 ] ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_3 * V_3 , T_3 V_164 , T_2 V_103 )
{
T_7 V_187 , V_188 , V_189 ;
struct V_190 * V_190 ;
struct V_191 * V_192 = V_3 -> V_193 ;
V_188 = V_103 >> V_194 ;
V_189 = ( V_103 + V_164 - 1 ) >> V_194 ;
if ( V_189 - V_188 + 1 > V_195 )
return - V_14 ;
V_2 -> V_185 = 0 ;
for ( V_187 = V_188 ; V_187 <= V_189 ; V_187 ++ ) {
V_190 = F_57 ( V_192 , V_187 ) ;
if ( V_190 == NULL ) {
V_190 = F_58 ( V_192 , V_187 , V_196 ) ;
if ( V_190 == NULL ) {
F_59 ( V_192 -> V_197 , 1 ) ;
V_190 = F_58 ( V_192 , V_187 , V_196 ) ;
}
if ( V_190 == NULL ) {
F_54 ( V_2 ) ;
return - V_21 ;
}
F_60 ( V_190 ) ;
}
V_2 -> V_186 [ V_2 -> V_185 ++ ] = V_190 ;
}
return 0 ;
}
static int F_61 ( void )
{
if ( V_198 -> V_199 & V_200 )
return 0 ;
V_198 -> V_199 |= V_200 ;
return 1 ;
}
static void F_62 ( int V_201 )
{
if ( V_201 )
V_198 -> V_199 &= ~ V_200 ;
}
static T_8 F_63 ( struct V_1 * V_2 , struct V_3 * V_3 , void * V_30 , T_3 V_164 , T_2 * V_103 )
{
T_9 V_202 ;
T_8 V_203 ;
int V_6 , V_201 ;
V_6 = F_56 ( V_2 , V_3 , V_164 , * V_103 ) ;
if ( V_6 )
return V_6 ;
V_202 = F_64 () ;
F_65 ( F_66 () ) ;
V_201 = F_61 () ;
V_203 = F_67 ( V_3 , ( char V_204 * ) V_30 , V_164 , V_103 ) ;
F_62 ( V_201 ) ;
F_65 ( V_202 ) ;
F_54 ( V_2 ) ;
return V_203 ;
}
static T_8 F_68 ( struct V_1 * V_2 , struct V_3 * V_3 , void * V_30 , T_3 V_164 , T_2 * V_103 )
{
T_9 V_202 ;
T_8 V_203 ;
int V_6 , V_201 ;
V_6 = F_56 ( V_2 , V_3 , V_164 , * V_103 ) ;
if ( V_6 )
return V_6 ;
V_202 = F_64 () ;
F_65 ( F_66 () ) ;
V_201 = F_61 () ;
V_203 = F_69 ( V_3 , ( char V_204 * ) V_30 , V_164 , V_103 ) ;
F_62 ( V_201 ) ;
F_65 ( V_202 ) ;
F_54 ( V_2 ) ;
return V_203 ;
}
static inline union V_27 * F_70 ( struct V_1 * V_2 )
{
return & ( V_2 -> V_26 [ V_2 -> V_163 . V_166 ] ) ;
}
static inline T_5 * F_71 ( struct V_1 * V_2 )
{
return F_70 ( V_2 ) -> V_28 + V_2 -> V_163 . V_165 + V_2 -> V_163 . V_173 ;
}
int F_72 ( struct V_1 * V_2 , int V_172 )
{
unsigned int V_88 = V_2 -> V_163 . V_166 ;
if ( F_37 ( V_88 ) ) {
int V_5 ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_172 ) ;
for ( V_5 = 0 ; V_5 < V_172 ; ++ V_5 )
V_2 -> V_30 . V_28 [ V_5 ] = F_73 () ;
F_23 ( L_78 , V_88 ) ;
return 1 ;
}
return 0 ;
}
void F_74 ( struct V_1 * V_2 , int V_172 )
{
if ( V_205 && F_73 () < ( 1 << 22 ) ) {
int V_206 = 1 ;
if ( V_205 > 1 )
V_206 = ( F_73 () % ( int ) V_205 ) + 1 ;
while ( V_206 -- ) {
int V_103 = F_73 () % ( V_172 * 8 ) ;
V_2 -> V_30 . V_28 [ V_103 / 8 ] ^= ( 1 << ( V_103 % 8 ) ) ;
F_23 ( L_79
L_80 ,
V_103 , V_2 -> V_163 . V_166 , V_2 -> V_163 . V_165 + V_2 -> V_163 . V_173 ,
V_207 -> V_208 . V_209 , V_207 -> V_208 . V_210 ) ;
}
}
}
static void F_75 ( struct V_1 * V_2 , int V_172 )
{
union V_27 * V_211 ;
if ( V_2 -> V_4 ) {
if ( ! V_2 -> V_18 [ V_2 -> V_163 . V_166 ] ) {
F_51 ( L_81 , V_2 -> V_163 . V_166 ) ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_172 ) ;
} else {
T_2 V_103 ;
T_8 V_203 ;
F_51 ( L_82 ,
V_2 -> V_163 . V_166 , V_2 -> V_163 . V_165 + V_2 -> V_163 . V_173 ) ;
if ( F_72 ( V_2 , V_172 ) )
return;
V_103 = ( T_2 ) V_2 -> V_163 . V_166 * V_2 -> V_19 . V_23 + V_2 -> V_163 . V_165 + V_2 -> V_163 . V_173 ;
V_203 = F_63 ( V_2 , V_2 -> V_4 , V_2 -> V_30 . V_28 , V_172 , & V_103 ) ;
if ( V_203 != V_172 ) {
F_5 ( L_83 , V_2 -> V_163 . V_166 , ( long ) V_203 ) ;
return;
}
F_74 ( V_2 , V_172 ) ;
}
return;
}
V_211 = F_70 ( V_2 ) ;
if ( V_211 -> V_28 == NULL ) {
F_51 ( L_84 , V_2 -> V_163 . V_166 ) ;
memset ( V_2 -> V_30 . V_28 , 0xFF , V_172 ) ;
} else {
F_51 ( L_85 ,
V_2 -> V_163 . V_166 , V_2 -> V_163 . V_165 + V_2 -> V_163 . V_173 ) ;
if ( F_72 ( V_2 , V_172 ) )
return;
memcpy ( V_2 -> V_30 . V_28 , F_71 ( V_2 ) , V_172 ) ;
F_74 ( V_2 , V_172 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
union V_27 * V_211 ;
int V_5 ;
if ( V_2 -> V_4 ) {
for ( V_5 = 0 ; V_5 < V_2 -> V_19 . V_57 ; V_5 ++ )
if ( V_2 -> V_18 [ V_2 -> V_163 . V_166 + V_5 ] ) {
F_51 ( L_86 , V_2 -> V_163 . V_166 + V_5 ) ;
V_2 -> V_18 [ V_2 -> V_163 . V_166 + V_5 ] = 0 ;
}
return;
}
V_211 = F_70 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_19 . V_57 ; V_5 ++ ) {
if ( V_211 -> V_28 != NULL ) {
F_51 ( L_86 , V_2 -> V_163 . V_166 + V_5 ) ;
F_14 ( V_2 -> V_29 , V_211 -> V_28 ) ;
V_211 -> V_28 = NULL ;
}
V_211 ++ ;
}
}
static int F_77 ( struct V_1 * V_2 , int V_172 )
{
int V_5 ;
union V_27 * V_211 ;
T_5 * V_212 ;
if ( V_2 -> V_4 ) {
T_2 V_173 , V_103 ;
T_8 V_203 ;
int V_213 ;
F_51 ( L_87 , V_2 -> V_163 . V_166 ) ;
V_212 = V_2 -> V_22 + V_2 -> V_163 . V_165 + V_2 -> V_163 . V_173 ;
V_173 = ( T_2 ) V_2 -> V_163 . V_166 * V_2 -> V_19 . V_23 + V_2 -> V_163 . V_165 + V_2 -> V_163 . V_173 ;
if ( ! V_2 -> V_18 [ V_2 -> V_163 . V_166 ] ) {
V_213 = 1 ;
memset ( V_2 -> V_22 , 0xff , V_2 -> V_19 . V_23 ) ;
} else {
V_213 = 0 ;
V_103 = V_173 ;
V_203 = F_63 ( V_2 , V_2 -> V_4 , V_212 , V_172 , & V_103 ) ;
if ( V_203 != V_172 ) {
F_5 ( L_88 , V_2 -> V_163 . V_166 , ( long ) V_203 ) ;
return - 1 ;
}
}
for ( V_5 = 0 ; V_5 < V_172 ; V_5 ++ )
V_212 [ V_5 ] &= V_2 -> V_30 . V_28 [ V_5 ] ;
if ( V_213 ) {
V_103 = ( T_2 ) V_2 -> V_163 . V_166 * V_2 -> V_19 . V_23 ;
V_203 = F_68 ( V_2 , V_2 -> V_4 , V_2 -> V_22 , V_2 -> V_19 . V_23 , & V_103 ) ;
if ( V_203 != V_2 -> V_19 . V_23 ) {
F_5 ( L_89 , V_2 -> V_163 . V_166 , ( long ) V_203 ) ;
return - 1 ;
}
V_2 -> V_18 [ V_2 -> V_163 . V_166 ] = 1 ;
} else {
V_103 = V_173 ;
V_203 = F_68 ( V_2 , V_2 -> V_4 , V_212 , V_172 , & V_103 ) ;
if ( V_203 != V_172 ) {
F_5 ( L_89 , V_2 -> V_163 . V_166 , ( long ) V_203 ) ;
return - 1 ;
}
}
return 0 ;
}
V_211 = F_70 ( V_2 ) ;
if ( V_211 -> V_28 == NULL ) {
F_51 ( L_90 , V_2 -> V_163 . V_166 ) ;
V_211 -> V_28 = F_78 ( V_2 -> V_29 , V_196 ) ;
if ( V_211 -> V_28 == NULL ) {
F_5 ( L_91 , V_2 -> V_163 . V_166 ) ;
return - 1 ;
}
memset ( V_211 -> V_28 , 0xFF , V_2 -> V_19 . V_23 ) ;
}
V_212 = F_71 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_172 ; V_5 ++ )
V_212 [ V_5 ] &= V_2 -> V_30 . V_28 [ V_5 ] ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , T_4 V_214 )
{
int V_172 ;
int V_215 = V_2 -> V_41 == 8 ? 1 : 2 ;
unsigned int V_79 , V_88 ;
V_214 &= V_216 ;
if ( V_214 != V_217 && V_2 -> V_163 . V_166 >= V_2 -> V_19 . V_20 ) {
F_23 ( L_92 , V_2 -> V_163 . V_166 ) ;
return - 1 ;
}
switch ( V_214 ) {
case V_218 :
if ( V_2 -> V_163 . V_165 >= ( V_2 -> V_19 . V_23 - V_2 -> V_163 . V_173 ) ) {
F_5 ( L_93 ) ;
break;
}
V_172 = V_2 -> V_19 . V_23 - V_2 -> V_163 . V_173 - V_2 -> V_163 . V_165 ;
F_75 ( V_2 , V_172 ) ;
F_51 ( L_94 ,
V_172 , F_80 ( V_2 ) + V_2 -> V_163 . V_173 ) ;
if ( V_2 -> V_163 . V_173 == 0 )
F_81 ( L_95 , V_2 -> V_163 . V_166 ) ;
else if ( V_2 -> V_163 . V_173 < V_2 -> V_19 . V_46 )
F_81 ( L_96 , V_2 -> V_163 . V_166 ) ;
else
F_81 ( L_97 , V_2 -> V_163 . V_166 ) ;
F_82 ( V_219 ) ;
F_82 ( V_220 * V_2 -> V_19 . V_46 / 1000 / V_215 ) ;
break;
case V_217 :
if ( V_2 -> V_221 . V_91 ) {
F_5 ( L_98 ) ;
return - 1 ;
}
if ( V_2 -> V_163 . V_166 >= V_2 -> V_19 . V_20 - V_2 -> V_19 . V_57
|| ( V_2 -> V_163 . V_166 & ~ ( V_2 -> V_19 . V_50 - 1 ) ) ) {
F_5 ( L_99 , V_2 -> V_163 . V_166 ) ;
return - 1 ;
}
V_2 -> V_163 . V_166 = ( V_2 -> V_163 . V_166 <<
8 * ( V_2 -> V_19 . V_65 - V_2 -> V_19 . V_66 ) ) | V_2 -> V_163 . V_165 ;
V_2 -> V_163 . V_165 = 0 ;
V_79 = V_2 -> V_163 . V_166 >> ( V_2 -> V_19 . V_53 - V_2 -> V_19 . V_54 ) ;
F_51 ( L_100 ,
V_2 -> V_163 . V_166 , F_80 ( V_2 ) ) ;
F_81 ( L_101 , V_79 ) ;
F_76 ( V_2 ) ;
F_83 ( V_222 ) ;
if ( V_105 )
F_43 ( V_79 ) ;
if ( F_32 ( V_79 ) ) {
F_23 ( L_102 , V_79 ) ;
return - 1 ;
}
break;
case V_223 :
if ( V_2 -> V_221 . V_91 ) {
F_23 ( L_103 ) ;
return - 1 ;
}
V_172 = V_2 -> V_19 . V_23 - V_2 -> V_163 . V_173 - V_2 -> V_163 . V_165 ;
if ( V_172 != V_2 -> V_163 . V_164 ) {
F_5 ( L_104 ,
V_2 -> V_163 . V_164 , V_172 ) ;
return - 1 ;
}
if ( F_77 ( V_2 , V_172 ) == - 1 )
return - 1 ;
V_88 = V_2 -> V_163 . V_166 ;
F_51 ( L_105 ,
V_172 , V_2 -> V_163 . V_166 , V_2 -> V_163 . V_165 , F_80 ( V_2 ) + V_2 -> V_163 . V_173 ) ;
F_81 ( L_106 , V_2 -> V_163 . V_166 ) ;
F_82 ( V_224 ) ;
F_82 ( V_225 * V_2 -> V_19 . V_46 / 1000 / V_215 ) ;
if ( F_35 ( V_88 ) ) {
F_23 ( L_107 , V_88 ) ;
return - 1 ;
}
break;
case V_226 :
F_51 ( L_108 ) ;
V_2 -> V_163 . V_173 = 0 ;
break;
case V_227 :
if ( ! ( V_2 -> V_42 & V_61 ) ) {
F_5 ( L_109
L_110 ) ;
return - 1 ;
}
F_51 ( L_111 , V_2 -> V_19 . V_46 / 2 ) ;
V_2 -> V_163 . V_173 = V_2 -> V_19 . V_46 / 2 ;
break;
case V_228 :
F_51 ( L_111 , V_2 -> V_19 . V_46 ) ;
V_2 -> V_163 . V_173 = V_2 -> V_19 . V_46 ;
break;
default:
F_51 ( L_112 ) ;
}
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_169 ) {
V_2 -> V_171 += 1 ;
V_2 -> V_120 = V_2 -> V_168 ;
V_2 -> V_168 = V_2 -> V_169 [ V_2 -> V_171 + 1 ] ;
F_51 ( L_113
L_114 ,
F_45 ( V_2 -> V_120 ) , F_45 ( V_2 -> V_168 ) ) ;
if ( ( V_2 -> V_120 & V_216 ) && F_79 ( V_2 , V_2 -> V_120 ) < 0 ) {
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
} else {
V_2 -> V_120 = F_48 ( V_2 -> V_163 . V_161 ) ;
F_51 ( L_115 ) ;
if ( F_52 ( V_2 , 0 ) != 0 )
return;
if ( ( V_2 -> V_120 & V_216 ) && F_79 ( V_2 , V_2 -> V_120 ) < 0 ) {
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
}
if ( ( V_2 -> V_168 & V_183 ) && V_2 -> V_41 == 16 ) {
F_51 ( L_116 ) ;
V_2 -> V_163 . V_165 <<= 1 ;
}
if ( F_46 ( V_2 -> V_168 ) == V_144 ) {
T_5 V_167 = F_85 ( V_2 ) ;
if ( ( V_2 -> V_120 & ( V_229 | V_230 ) )
&& V_2 -> V_163 . V_164 != V_2 -> V_163 . V_172 ) {
F_23 ( L_117 ,
V_2 -> V_163 . V_172 - V_2 -> V_163 . V_164 ) ;
V_167 = F_53 ( V_2 ) ;
}
F_51 ( L_118 ) ;
F_50 ( V_2 , V_167 ) ;
return;
} else if ( V_2 -> V_168 & ( V_229 | V_230 ) ) {
V_2 -> V_120 = V_2 -> V_168 ;
V_2 -> V_168 = V_2 -> V_169 [ ++ V_2 -> V_171 + 1 ] ;
V_2 -> V_163 . V_172 = V_2 -> V_163 . V_164 = 0 ;
F_51 ( L_119
L_114 ,
F_45 ( V_2 -> V_120 ) , F_45 ( V_2 -> V_168 ) ) ;
switch ( F_46 ( V_2 -> V_120 ) ) {
case V_139 :
case V_140 :
V_2 -> V_163 . V_172 = V_2 -> V_19 . V_23 - V_2 -> V_163 . V_173 - V_2 -> V_163 . V_165 ;
break;
case V_141 :
V_2 -> V_163 . V_172 = V_2 -> V_19 . V_231 ;
break;
case V_142 :
case V_143 :
V_2 -> V_163 . V_164 = V_2 -> V_163 . V_172 = 0 ;
break;
default:
F_5 ( L_120 ) ;
}
} else if ( V_2 -> V_168 & V_183 ) {
V_2 -> V_163 . V_164 = 0 ;
switch ( F_46 ( V_2 -> V_168 ) ) {
case V_135 :
V_2 -> V_163 . V_172 = V_2 -> V_19 . V_65 ;
break;
case V_136 :
V_2 -> V_163 . V_172 = V_2 -> V_19 . V_66 ;
break;
case V_137 :
V_2 -> V_163 . V_172 = 1 ;
break;
case V_138 :
V_2 -> V_163 . V_172 = V_2 -> V_19 . V_65 - V_2 -> V_19 . V_66 ;
break;
default:
F_5 ( L_121 ) ;
}
} else {
V_2 -> V_163 . V_172 = 0 ;
V_2 -> V_163 . V_164 = 0 ;
}
}
static T_5 F_86 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = ( (struct V_33 * ) V_32 -> V_35 ) -> V_35 ;
T_5 V_232 = 0x00 ;
if ( ! V_2 -> V_221 . V_233 ) {
F_5 ( L_122 , ( T_6 ) V_232 ) ;
return V_232 ;
}
if ( V_2 -> V_221 . V_234 || V_2 -> V_221 . V_235 ) {
F_5 ( L_123 , ( T_6 ) V_232 ) ;
return V_232 ;
}
if ( ! ( V_2 -> V_120 & V_230 ) ) {
F_23 ( L_124
L_125 , F_45 ( V_2 -> V_120 ) , ( T_6 ) V_232 ) ;
return V_232 ;
}
if ( F_46 ( V_2 -> V_120 ) == V_142 ) {
F_51 ( L_126 , V_2 -> V_163 . V_167 ) ;
return V_2 -> V_163 . V_167 ;
}
if ( V_2 -> V_163 . V_164 == V_2 -> V_163 . V_172 ) {
F_23 ( L_127 , ( T_6 ) V_232 ) ;
return V_232 ;
}
switch ( F_46 ( V_2 -> V_120 ) ) {
case V_140 :
if ( V_2 -> V_41 == 8 ) {
V_232 = V_2 -> V_30 . V_28 [ V_2 -> V_163 . V_164 ] ;
V_2 -> V_163 . V_164 += 1 ;
} else {
V_232 = ( T_5 ) F_87 ( V_2 -> V_30 . V_236 [ V_2 -> V_163 . V_164 >> 1 ] ) ;
V_2 -> V_163 . V_164 += 2 ;
}
break;
case V_141 :
F_51 ( L_128 , V_2 -> V_163 . V_164 , V_2 -> V_163 . V_172 ) ;
V_232 = V_2 -> V_237 [ V_2 -> V_163 . V_164 ] ;
V_2 -> V_163 . V_164 += 1 ;
break;
default:
F_88 () ;
}
if ( V_2 -> V_163 . V_164 == V_2 -> V_163 . V_172 ) {
F_51 ( L_129 ) ;
if ( F_46 ( V_2 -> V_168 ) == V_144 )
F_84 ( V_2 ) ;
}
return V_232 ;
}
static void F_89 ( struct V_31 * V_32 , T_5 V_28 )
{
struct V_1 * V_2 = ( (struct V_33 * ) V_32 -> V_35 ) -> V_35 ;
if ( ! V_2 -> V_221 . V_233 ) {
F_5 ( L_130 ) ;
return;
}
if ( V_2 -> V_221 . V_234 && V_2 -> V_221 . V_235 ) {
F_5 ( L_131 ) ;
return;
}
if ( V_2 -> V_221 . V_235 == 1 ) {
if ( V_28 == V_157 ) {
F_81 ( L_132 ) ;
F_50 ( V_2 , F_85 ( V_2 ) ) ;
return;
}
if ( F_47 ( V_28 ) ) {
F_5 ( L_133 , ( T_6 ) V_28 ) ;
return;
}
if ( F_46 ( V_2 -> V_120 ) == V_142
|| F_46 ( V_2 -> V_120 ) == V_143
|| F_46 ( V_2 -> V_120 ) == V_140 ) {
int V_166 = V_2 -> V_163 . V_166 ;
F_84 ( V_2 ) ;
if ( V_28 == V_158 )
V_2 -> V_163 . V_166 = V_166 ;
}
if ( F_46 ( V_2 -> V_168 ) != V_145 && ! ( V_2 -> V_168 & V_238 ) ) {
if ( ! ( V_2 -> V_163 . V_161 == V_155 &&
F_46 ( V_2 -> V_120 ) == V_141 && V_2 -> V_163 . V_164 == 2 ) ) {
F_23 ( L_134
L_135 , ( T_6 ) V_28 , F_45 ( V_2 -> V_168 ) ) ;
}
F_50 ( V_2 , F_53 ( V_2 ) ) ;
}
F_51 ( L_136 ,
F_45 ( F_48 ( V_28 ) ) ) ;
V_2 -> V_163 . V_161 = V_28 ;
F_84 ( V_2 ) ;
} else if ( V_2 -> V_221 . V_234 == 1 ) {
if ( F_46 ( V_2 -> V_168 ) == V_145 ) {
F_51 ( L_137 ) ;
if ( F_52 ( V_2 , 1 ) < 0 )
return;
if ( ( V_2 -> V_120 & V_216 ) && F_79 ( V_2 , V_2 -> V_120 ) < 0 ) {
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
V_2 -> V_163 . V_164 = 0 ;
switch ( F_46 ( V_2 -> V_168 ) ) {
case V_135 :
V_2 -> V_163 . V_172 = V_2 -> V_19 . V_65 ;
break;
case V_136 :
V_2 -> V_163 . V_172 = V_2 -> V_19 . V_66 ;
break;
case V_137 :
V_2 -> V_163 . V_172 = 1 ;
break;
default:
F_88 () ;
}
}
if ( ! ( V_2 -> V_168 & V_183 ) ) {
F_5 ( L_138
L_139 , ( T_6 ) V_28 , F_45 ( V_2 -> V_168 ) ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_163 . V_164 == V_2 -> V_163 . V_172 ) {
F_5 ( L_140 ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
F_49 ( V_2 , V_28 ) ;
V_2 -> V_163 . V_164 += 1 ;
F_51 ( L_141 ,
( T_6 ) V_28 , V_2 -> V_163 . V_164 , V_2 -> V_163 . V_172 ) ;
if ( V_2 -> V_163 . V_164 == V_2 -> V_163 . V_172 ) {
F_51 ( L_142 , V_2 -> V_163 . V_166 , V_2 -> V_163 . V_165 ) ;
F_84 ( V_2 ) ;
}
} else {
if ( ! ( V_2 -> V_120 & V_229 ) ) {
F_5 ( L_143
L_144 , ( T_6 ) V_28 ,
F_45 ( V_2 -> V_120 ) , F_45 ( V_144 ) ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_163 . V_164 == V_2 -> V_163 . V_172 ) {
F_23 ( L_145 ,
V_2 -> V_163 . V_172 ) ;
return;
}
if ( V_2 -> V_41 == 8 ) {
V_2 -> V_30 . V_28 [ V_2 -> V_163 . V_164 ] = V_28 ;
V_2 -> V_163 . V_164 += 1 ;
} else {
V_2 -> V_30 . V_236 [ V_2 -> V_163 . V_164 >> 1 ] = F_87 ( ( V_239 ) V_28 ) ;
V_2 -> V_163 . V_164 += 2 ;
}
}
return;
}
static void F_90 ( struct V_31 * V_32 , int V_146 , unsigned int V_240 )
{
struct V_1 * V_2 = ( (struct V_33 * ) V_32 -> V_35 ) -> V_35 ;
V_2 -> V_221 . V_235 = V_240 & V_241 ? 1 : 0 ;
V_2 -> V_221 . V_234 = V_240 & V_242 ? 1 : 0 ;
V_2 -> V_221 . V_233 = V_240 & V_243 ? 1 : 0 ;
if ( V_146 != V_244 )
F_89 ( V_32 , V_146 ) ;
}
static int F_91 ( struct V_31 * V_32 )
{
F_51 ( L_146 ) ;
return 1 ;
}
static V_239 F_92 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = (struct V_33 * ) V_32 -> V_35 ;
F_51 ( L_147 ) ;
return V_34 -> V_245 ( V_32 ) | ( V_34 -> V_245 ( V_32 ) << 8 ) ;
}
static void F_93 ( struct V_31 * V_32 , const T_5 * V_30 , int V_246 )
{
struct V_1 * V_2 = ( (struct V_33 * ) V_32 -> V_35 ) -> V_35 ;
if ( ! ( V_2 -> V_120 & V_229 ) ) {
F_5 ( L_148
L_139 , F_45 ( V_2 -> V_120 ) ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
if ( V_2 -> V_163 . V_164 + V_246 > V_2 -> V_163 . V_172 ) {
F_5 ( L_149 ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
memcpy ( V_2 -> V_30 . V_28 + V_2 -> V_163 . V_164 , V_30 , V_246 ) ;
V_2 -> V_163 . V_164 += V_246 ;
if ( V_2 -> V_163 . V_164 == V_2 -> V_163 . V_172 ) {
F_51 ( L_150 , V_2 -> V_163 . V_164 ) ;
}
}
static void F_94 ( struct V_31 * V_32 , T_5 * V_30 , int V_246 )
{
struct V_1 * V_2 = ( (struct V_33 * ) V_32 -> V_35 ) -> V_35 ;
if ( ! V_2 -> V_221 . V_233 ) {
F_5 ( L_151 ) ;
return;
}
if ( V_2 -> V_221 . V_234 || V_2 -> V_221 . V_235 ) {
F_5 ( L_152 ) ;
return;
}
if ( ! ( V_2 -> V_120 & V_230 ) ) {
F_23 ( L_153 ,
F_45 ( V_2 -> V_120 ) ) ;
return;
}
if ( F_46 ( V_2 -> V_120 ) != V_140 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_246 ; V_5 ++ )
V_30 [ V_5 ] = ( (struct V_33 * ) V_32 -> V_35 ) -> V_245 ( V_32 ) ;
return;
}
if ( V_2 -> V_163 . V_164 + V_246 > V_2 -> V_163 . V_172 ) {
F_5 ( L_154 ) ;
F_50 ( V_2 , F_53 ( V_2 ) ) ;
return;
}
memcpy ( V_30 , V_2 -> V_30 . V_28 + V_2 -> V_163 . V_164 , V_246 ) ;
V_2 -> V_163 . V_164 += V_246 ;
if ( V_2 -> V_163 . V_164 == V_2 -> V_163 . V_172 ) {
if ( F_46 ( V_2 -> V_168 ) == V_144 )
F_84 ( V_2 ) ;
}
return;
}
static int F_95 ( struct V_31 * V_32 , const T_5 * V_30 , int V_246 )
{
F_94 ( V_32 , ( T_5 * ) & V_247 [ 0 ] , V_246 ) ;
if ( ! memcmp ( V_30 , & V_247 [ 0 ] , V_246 ) ) {
F_51 ( L_155 ) ;
return 0 ;
} else {
F_51 ( L_156 ) ;
return - V_248 ;
}
}
static int T_10 F_96 ( void )
{
struct V_33 * V_34 ;
struct V_1 * V_249 ;
int V_250 = - V_21 , V_5 ;
if ( V_251 != 8 && V_251 != 16 ) {
F_5 ( L_157 , V_251 ) ;
return - V_14 ;
}
V_207 = F_30 ( sizeof( struct V_31 ) + sizeof( struct V_33 )
+ sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_207 ) {
F_5 ( L_158 ) ;
return - V_21 ;
}
V_34 = (struct V_33 * ) ( V_207 + 1 ) ;
V_207 -> V_35 = ( void * ) V_34 ;
V_249 = (struct V_1 * ) ( V_34 + 1 ) ;
V_34 -> V_35 = ( void * ) V_249 ;
V_34 -> V_252 = F_90 ;
V_34 -> V_245 = F_86 ;
V_34 -> V_253 = F_91 ;
V_34 -> V_254 = F_93 ;
V_34 -> V_255 = F_94 ;
V_34 -> V_256 = F_95 ;
V_34 -> V_257 = F_92 ;
V_34 -> V_258 . V_259 = V_260 ;
V_34 -> V_42 |= V_261 ;
switch ( V_262 ) {
case 2 :
V_34 -> V_263 |= V_264 ;
case 1 :
V_34 -> V_263 |= V_265 ;
case 0 :
break;
default:
F_5 ( L_159 ) ;
V_250 = - V_14 ;
goto error;
}
if ( V_266 != 0xFF || V_267 != 0xFF )
V_249 -> V_19 . V_231 = 4 ;
else
V_249 -> V_19 . V_231 = 2 ;
V_249 -> V_163 . V_167 = F_85 ( V_249 ) ;
V_249 -> V_168 = V_145 ;
V_249 -> V_42 |= V_59 ;
V_249 -> V_237 [ 0 ] = V_268 ;
V_249 -> V_237 [ 1 ] = V_75 ;
V_249 -> V_237 [ 2 ] = V_266 ;
V_249 -> V_237 [ 3 ] = V_267 ;
if ( V_251 == 16 ) {
V_249 -> V_41 = 16 ;
V_34 -> V_42 |= V_43 ;
}
V_207 -> V_269 = V_270 ;
if ( ( V_250 = F_29 () ) != 0 )
goto error;
if ( ( V_250 = F_34 () ) != 0 )
goto error;
if ( ( V_250 = F_36 () ) != 0 )
goto error;
V_250 = F_97 ( V_207 , 1 , NULL ) ;
if ( V_250 ) {
F_5 ( L_160 ) ;
if ( V_250 > 0 )
V_250 = - V_271 ;
goto error;
}
if ( V_272 ) {
unsigned int V_273 , V_274 ;
if ( ! F_98 () ) {
F_5 ( L_161 ) ;
V_250 = - V_14 ;
goto error;
}
V_273 = V_207 -> V_47 / 512 ;
V_274 = ( V_272 * 13 + 7 ) / 8 ;
if ( ( V_207 -> V_49 < 64 ) || ! V_273 ) {
F_5 ( L_162 ) ;
V_250 = - V_14 ;
goto error;
}
if ( ( V_274 * V_273 + 2 ) > V_207 -> V_49 ) {
F_5 ( L_163 , V_272 ) ;
V_250 = - V_14 ;
goto error;
}
V_34 -> V_258 . V_259 = V_275 ;
V_34 -> V_258 . V_45 = 512 ;
V_34 -> V_258 . V_276 = V_274 ;
F_44 ( L_164 , V_272 , V_34 -> V_258 . V_45 ) ;
}
V_250 = F_99 ( V_207 ) ;
if ( V_250 ) {
F_5 ( L_165 ) ;
if ( V_250 > 0 )
V_250 = - V_271 ;
goto error;
}
if ( V_277 ) {
T_1 V_278 = ( T_1 ) V_207 -> V_51 << V_277 ;
if ( V_278 >> V_277 != V_207 -> V_51 ) {
F_5 ( L_166 ) ;
goto V_279;
}
V_207 -> V_45 = V_278 ;
V_34 -> V_280 = V_278 ;
V_34 -> V_281 = F_21 ( V_207 -> V_51 ) + V_277 - 1 ;
V_34 -> V_282 = ( V_34 -> V_280 >> V_34 -> V_55 ) - 1 ;
}
if ( ( V_250 = F_42 ( V_207 ) ) != 0 )
goto V_279;
if ( ( V_250 = F_18 ( V_207 ) ) != 0 )
goto V_279;
if ( ( V_250 = F_100 ( V_207 ) ) != 0 )
goto V_279;
if ( ( V_250 = F_26 ( V_249 , V_207 ) ) != 0 )
goto V_279;
V_250 = F_101 ( V_207 , & V_249 -> V_68 [ 0 ] ,
V_249 -> V_73 ) ;
if ( V_250 != 0 )
goto V_279;
return 0 ;
V_279:
F_25 ( V_249 ) ;
F_102 ( V_207 ) ;
for ( V_5 = 0 ; V_5 < F_22 ( V_249 -> V_68 ) ; ++ V_5 )
F_13 ( V_249 -> V_68 [ V_5 ] . V_71 ) ;
error:
F_13 ( V_207 ) ;
F_38 () ;
return V_250 ;
}
static void T_11 F_103 ( void )
{
struct V_1 * V_2 = ( (struct V_33 * ) V_207 -> V_35 ) -> V_35 ;
int V_5 ;
F_25 ( V_2 ) ;
F_102 ( V_207 ) ;
for ( V_5 = 0 ; V_5 < F_22 ( V_2 -> V_68 ) ; ++ V_5 )
F_13 ( V_2 -> V_68 [ V_5 ] . V_71 ) ;
F_13 ( V_207 ) ;
F_38 () ;
}
