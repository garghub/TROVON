static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
if ( V_7 -> V_10 & V_11 ) {
F_7 ( V_9 -> V_12 , L_1 ) ;
return;
}
F_8 ( V_9 -> V_13 , V_14 << V_9 -> V_15 ) ;
if ( ! F_9 ( V_7 ) ) {
struct V_16 * V_17 ;
F_10 (ha, ndev) {
F_11 ( V_9 -> V_13 , ( V_18 * ) V_17 -> V_19 ,
V_14 << V_9 -> V_15 , 0 , 0 ) ;
}
}
}
static void F_12 ( struct V_8 * V_9 )
{
F_4 ( 0xFF , & V_9 -> V_20 -> V_21 ) ;
F_4 ( 0xFF , & V_9 -> V_20 -> V_22 ) ;
F_13 ( V_9 -> V_23 , true ) ;
return;
}
static void F_14 ( struct V_8 * V_9 )
{
F_4 ( 0 , & V_9 -> V_20 -> V_21 ) ;
F_4 ( 0 , & V_9 -> V_20 -> V_22 ) ;
F_13 ( V_9 -> V_23 , false ) ;
return;
}
void F_15 ( void * V_24 , int V_25 , int V_26 )
{
struct V_27 * V_28 = V_24 ;
struct V_6 * V_7 = V_28 -> V_12 ;
struct V_8 * V_9 = F_6 ( V_7 ) ;
if ( F_16 ( F_17 ( V_7 ) ) )
F_18 ( V_7 ) ;
F_19 ( & V_9 -> V_29 , V_28 ) ;
V_9 -> V_30 . V_31 ++ ;
V_9 -> V_30 . V_32 += V_25 ;
F_20 ( V_28 ) ;
}
void F_21 ( void * V_24 , int V_25 , int V_26 )
{
struct V_27 * V_28 = V_24 ;
struct V_6 * V_7 = V_28 -> V_12 ;
struct V_8 * V_9 = F_6 ( V_7 ) ;
int V_33 = 0 ;
if ( F_16 ( ! F_22 ( V_7 ) ) ||
F_16 ( ! F_23 ( V_7 ) ) ) {
F_20 ( V_28 ) ;
return;
}
if ( F_24 ( V_26 >= 0 ) ) {
F_25 ( V_28 , V_25 ) ;
F_26 ( & V_9 -> V_29 , V_28 ) ;
V_28 -> V_34 = F_27 ( V_28 , V_7 ) ;
F_28 ( V_28 ) ;
V_9 -> V_30 . V_35 += V_25 ;
V_9 -> V_30 . V_36 ++ ;
V_28 = NULL ;
}
if ( F_16 ( ! F_22 ( V_7 ) ) ) {
if ( V_28 )
F_20 ( V_28 ) ;
return;
}
if ( F_24 ( ! V_28 ) ) {
V_28 = F_29 ( V_7 , V_9 -> V_37 ) ;
if ( F_30 ( ! V_28 ) )
return;
V_33 = F_31 ( V_9 -> V_38 , V_28 , V_28 -> V_39 ,
F_32 ( V_28 ) , V_40 ) ;
}
F_30 ( V_33 < 0 ) ;
}
static T_2 F_33 ( int V_41 , void * V_42 )
{
struct V_8 * V_9 = V_42 ;
if ( F_24 ( F_22 ( V_9 -> V_7 ) ) ) {
F_14 ( V_9 ) ;
F_34 ( V_9 ) ;
F_35 ( & V_9 -> V_43 ) ;
}
return V_44 ;
}
static inline int F_36 ( struct V_8 * V_9 , T_1 V_45 )
{
if ( V_9 -> V_15 == 0 )
return V_45 + 1 ;
else
return V_45 ;
}
static int F_37 ( struct V_46 * V_43 , int V_47 )
{
struct V_8 * V_9 = F_38 ( V_43 ) ;
int V_48 , V_49 ;
V_48 = F_39 ( V_9 -> V_50 , 128 ) ;
V_49 = F_39 ( V_9 -> V_38 , V_47 ) ;
if ( V_49 || V_48 )
F_40 ( V_9 , V_51 , L_2 ,
V_49 , V_48 ) ;
if ( V_49 < V_47 ) {
F_41 ( V_43 ) ;
F_12 ( V_9 ) ;
F_42 ( V_9 -> V_23 ) ;
F_43 ( V_9 ) ;
}
return V_49 ;
}
static inline void F_44 ( const char * V_52 , void T_3 * V_53 )
{
unsigned long V_54 = V_55 + V_56 ;
F_4 ( 1 , V_53 ) ;
do {
F_45 () ;
} while ( ( F_2 ( V_53 ) & 1 ) && F_46 ( V_54 , V_55 ) );
F_47 ( F_2 ( V_53 ) & 1 , L_3 , V_52 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_3 ( V_2 , F_49 ( V_9 -> V_57 ) , V_58 ) ;
F_3 ( V_2 , F_50 ( V_9 -> V_57 ) , V_59 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_8 * V_9 , bool * V_60 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
T_1 V_63 = 0 ;
T_1 V_64 ;
if ( ! V_62 )
return;
V_64 = F_36 ( V_9 , V_2 -> V_45 ) ;
if ( V_62 -> V_60 ) {
V_63 = V_9 -> V_39 . V_63 ;
F_52 ( V_9 -> V_13 , V_64 ,
V_65 , V_66 ) ;
if ( V_62 -> V_67 == 1000 )
V_63 |= F_53 ( 7 ) ;
if ( V_62 -> V_68 )
V_63 |= F_53 ( 0 ) ;
if ( V_62 -> V_67 == 100 )
V_63 |= F_53 ( 15 ) ;
* V_60 = true ;
} else {
V_63 = 0 ;
F_52 ( V_9 -> V_13 , V_64 ,
V_65 , V_69 ) ;
}
if ( V_63 != V_2 -> V_63 ) {
F_54 ( V_62 ) ;
F_4 ( V_63 , & V_2 -> V_70 -> V_63 ) ;
}
V_2 -> V_63 = V_63 ;
}
static void F_55 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
bool V_60 = false ;
F_56 ( V_9 , F_51 , V_9 , & V_60 ) ;
if ( V_60 ) {
F_57 ( V_7 ) ;
if ( F_22 ( V_7 ) )
F_58 ( V_7 ) ;
} else {
F_59 ( V_7 ) ;
F_60 ( V_7 ) ;
}
}
static inline int F_61 ( char * V_71 , int V_72 , const char * V_73 , T_1 V_5 )
{
static char * V_74 = L_4 ;
if ( ! V_5 )
return 0 ;
else
return snprintf ( V_71 , V_72 , L_5 , V_73 ,
V_74 + strlen ( V_73 ) , V_5 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
char V_73 [ 32 ] ;
T_1 V_64 ;
sprintf ( V_73 , L_6 , V_2 -> V_45 ) ;
F_44 ( V_73 , & V_2 -> V_70 -> F_44 ) ;
F_4 ( V_75 , & V_2 -> V_70 -> V_76 ) ;
switch ( V_9 -> V_77 ) {
case V_78 :
F_3 ( V_2 , V_79 , V_80 ) ;
break;
case V_81 :
F_3 ( V_2 , V_79 , V_82 ) ;
break;
}
F_4 ( V_9 -> V_37 , & V_2 -> V_70 -> V_83 ) ;
F_48 ( V_2 , V_9 ) ;
V_2 -> V_63 = 0 ;
V_64 = F_36 ( V_9 , V_2 -> V_45 ) ;
F_11 ( V_9 -> V_13 , V_9 -> V_7 -> V_84 ,
1 << V_64 , 0 , V_85 ) ;
V_2 -> V_62 = F_63 ( V_9 -> V_7 , V_2 -> V_39 -> V_86 ,
& F_55 , 0 , V_2 -> V_39 -> V_87 ) ;
if ( F_64 ( V_2 -> V_62 ) ) {
F_7 ( V_9 -> V_12 , L_7 ,
V_2 -> V_39 -> V_86 , V_2 -> V_45 ) ;
V_2 -> V_62 = NULL ;
} else {
F_65 ( V_9 -> V_12 , L_8 ,
V_2 -> V_62 -> V_86 ) ;
F_66 ( V_2 -> V_62 ) ;
}
}
static void F_67 ( struct V_8 * V_9 )
{
F_44 ( L_9 , & V_9 -> V_4 -> F_44 ) ;
F_68 ( V_9 -> V_13 ) ;
F_52 ( V_9 -> V_13 , 0 , V_88 , 0 ) ;
F_4 ( V_89 ,
& V_9 -> V_90 -> V_91 ) ;
F_4 ( 0 , & V_9 -> V_90 -> V_92 ) ;
F_52 ( V_9 -> V_13 , V_9 -> V_15 ,
V_65 , V_66 ) ;
F_69 ( V_9 -> V_13 , V_9 -> V_57 , V_9 -> V_15 , 0 ) ;
F_11 ( V_9 -> V_13 , V_9 -> V_7 -> V_84 ,
1 << V_9 -> V_15 , 0 , V_85 ) ;
}
static int F_70 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
int V_93 , V_33 ;
T_1 V_53 ;
F_14 ( V_9 ) ;
F_59 ( V_7 ) ;
F_71 ( & V_9 -> V_94 -> V_12 ) ;
V_53 = V_9 -> V_77 ;
F_65 ( V_9 -> V_12 , L_10 ,
F_72 ( V_53 ) , F_73 ( V_53 ) ,
F_74 ( V_53 ) ) ;
F_67 ( V_9 ) ;
F_56 ( V_9 , F_62 , V_9 ) ;
F_75 ( V_9 -> V_23 , V_95 , 1 ) ;
F_75 ( V_9 -> V_23 , V_96 , 0 ) ;
F_4 ( 0 , & V_9 -> V_4 -> V_97 ) ;
F_4 ( 0x7 , & V_9 -> V_4 -> V_98 ) ;
if ( F_30 ( ! V_9 -> V_39 . V_99 ) )
V_9 -> V_39 . V_99 = 128 ;
for ( V_93 = 0 ; V_93 < V_9 -> V_39 . V_99 ; V_93 ++ ) {
struct V_27 * V_28 ;
V_33 = - V_100 ;
V_28 = F_29 ( V_9 -> V_7 ,
V_9 -> V_37 ) ;
if ( ! V_28 )
break;
V_33 = F_31 ( V_9 -> V_38 , V_28 , V_28 -> V_39 ,
F_32 ( V_28 ) , V_40 ) ;
if ( F_30 ( V_33 < 0 ) )
break;
}
F_76 ( V_9 , V_101 , L_11 , V_93 ) ;
F_77 ( V_9 -> V_23 ) ;
F_12 ( V_9 ) ;
F_78 ( & V_9 -> V_43 ) ;
F_42 ( V_9 -> V_23 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( ! V_2 -> V_62 )
return;
F_80 ( V_2 -> V_62 ) ;
F_81 ( V_2 -> V_62 ) ;
V_2 -> V_62 = NULL ;
}
static int F_82 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
F_76 ( V_9 , V_102 , L_12 ) ;
F_60 ( V_9 -> V_7 ) ;
F_83 ( & V_9 -> V_43 ) ;
F_59 ( V_9 -> V_7 ) ;
F_14 ( V_9 ) ;
F_13 ( V_9 -> V_23 , false ) ;
F_84 ( V_9 -> V_23 ) ;
F_85 ( V_9 -> V_13 ) ;
F_56 ( V_9 , F_79 , V_9 ) ;
F_86 ( & V_9 -> V_94 -> V_12 ) ;
return 0 ;
}
static T_4 F_87 ( struct V_27 * V_28 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
int V_33 ;
V_7 -> V_103 = V_55 ;
if ( F_88 ( V_28 , V_104 ) ) {
F_89 ( V_9 , V_105 , L_13 ) ;
V_9 -> V_30 . V_106 ++ ;
return V_107 ;
}
if ( F_90 ( V_28 ) -> V_108 & V_109 && V_9 -> V_29 . V_110 )
F_90 ( V_28 ) -> V_108 |= V_111 ;
F_91 ( V_28 ) ;
V_33 = F_31 ( V_9 -> V_50 , V_28 , V_28 -> V_39 ,
V_28 -> V_25 , V_40 ) ;
if ( F_16 ( V_33 != 0 ) ) {
F_89 ( V_9 , V_105 , L_14 ) ;
goto V_112;
}
return V_107 ;
V_112:
V_9 -> V_30 . V_106 ++ ;
F_60 ( V_7 ) ;
return V_113 ;
}
static void F_92 ( struct V_6 * V_7 , int V_10 )
{
if ( ( V_10 & V_11 ) && ( V_7 -> V_10 & V_11 ) )
F_7 ( & V_7 -> V_12 , L_15 ) ;
if ( ( V_10 & V_114 ) && ! ( V_7 -> V_10 & V_114 ) )
F_7 ( & V_7 -> V_12 , L_16 ) ;
}
static void F_93 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_115 [ V_9 -> V_39 . V_116 ] ;
T_1 V_117 , V_118 ;
if ( ! V_9 -> V_29 . V_110 && ! V_9 -> V_29 . V_119 ) {
F_3 ( V_2 , 0 , V_120 ) ;
return;
}
V_118 = ( 30 << V_121 ) | V_122 ;
V_117 = V_123 << V_124 ;
if ( V_9 -> V_29 . V_110 )
V_117 |= V_125 ;
if ( V_9 -> V_29 . V_119 )
V_117 |= V_126 ;
F_3 ( V_2 , V_117 , V_120 ) ;
F_3 ( V_2 , V_118 , V_127 ) ;
}
static void F_94 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_9 -> V_115 [ V_9 -> V_39 . V_116 ] ;
T_1 V_128 , V_129 ;
V_128 = F_1 ( V_2 , V_130 ) ;
V_128 &= ~ V_131 ;
if ( V_9 -> V_29 . V_110 )
V_128 |= V_132 ;
if ( V_9 -> V_29 . V_119 )
V_128 |= V_133 ;
V_129 = ( 30 << V_134 ) | V_123 ;
F_3 ( V_2 , V_129 , V_135 ) ;
F_3 ( V_2 , V_128 , V_130 ) ;
F_4 ( V_122 , & V_9 -> V_4 -> V_136 ) ;
}
static int F_95 ( struct V_6 * V_12 , struct V_137 * V_138 )
{
struct V_8 * V_9 = F_6 ( V_12 ) ;
struct V_29 * V_29 = & V_9 -> V_29 ;
struct V_139 V_140 ;
if ( F_96 ( & V_140 , V_138 -> V_141 , sizeof( V_140 ) ) )
return - V_142 ;
if ( V_140 . V_10 )
return - V_143 ;
switch ( V_140 . V_144 ) {
case V_145 :
V_29 -> V_110 = 0 ;
break;
case V_146 :
V_29 -> V_110 = 1 ;
break;
default:
return - V_147 ;
}
switch ( V_140 . V_148 ) {
case V_149 :
V_29 -> V_119 = 0 ;
break;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
return - V_147 ;
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
V_29 -> V_119 = 1 ;
V_140 . V_148 = V_160 ;
break;
default:
return - V_147 ;
}
switch ( V_9 -> V_77 ) {
case V_78 :
F_93 ( V_9 ) ;
break;
case V_81 :
F_94 ( V_9 ) ;
break;
default:
return - V_163 ;
}
return F_97 ( V_138 -> V_141 , & V_140 , sizeof( V_140 ) ) ? - V_142 : 0 ;
}
static int F_98 ( struct V_6 * V_12 , struct V_137 * V_164 , int V_165 )
{
if ( ! F_22 ( V_12 ) )
return - V_143 ;
#ifdef F_99
if ( V_165 == V_166 )
return F_95 ( V_12 , V_164 ) ;
#endif
return - V_163 ;
}
static void F_100 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
F_89 ( V_9 , V_105 , L_17 ) ;
V_9 -> V_30 . V_167 ++ ;
F_14 ( V_9 ) ;
F_13 ( V_9 -> V_23 , false ) ;
F_101 ( V_9 -> V_50 ) ;
F_102 ( V_9 -> V_50 ) ;
F_13 ( V_9 -> V_23 , true ) ;
F_12 ( V_9 ) ;
F_42 ( V_9 -> V_23 ) ;
}
static struct V_168 * F_103 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
return & V_9 -> V_30 ;
}
static void F_104 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
F_14 ( V_9 ) ;
F_13 ( V_9 -> V_23 , false ) ;
F_33 ( V_7 -> V_41 , V_9 ) ;
F_13 ( V_9 -> V_23 , true ) ;
F_12 ( V_9 ) ;
F_42 ( V_9 -> V_23 ) ;
}
static void F_105 ( struct V_6 * V_7 ,
struct V_169 * V_170 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
strcpy ( V_170 -> V_171 , L_18 ) ;
strcpy ( V_170 -> V_77 , L_19 ) ;
strcpy ( V_170 -> V_172 , V_9 -> V_94 -> V_73 ) ;
}
static T_1 F_106 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
return V_9 -> V_173 ;
}
static void F_107 ( struct V_6 * V_7 , T_1 V_174 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
V_9 -> V_173 = V_174 ;
}
static int F_108 ( struct V_6 * V_7 ,
struct V_175 * V_170 )
{
#ifdef F_99
struct V_8 * V_9 = F_6 ( V_7 ) ;
V_170 -> V_176 =
V_177 |
V_178 |
V_179 |
V_180 |
V_181 |
V_182 ;
V_170 -> V_183 = V_9 -> V_29 . V_183 ;
V_170 -> V_184 =
( 1 << V_145 ) |
( 1 << V_146 ) ;
V_170 -> V_185 =
( 1 << V_149 ) |
( 1 << V_160 ) ;
#else
V_170 -> V_176 =
V_178 |
V_180 |
V_181 ;
V_170 -> V_183 = - 1 ;
V_170 -> V_184 = 0 ;
V_170 -> V_185 = 0 ;
#endif
return 0 ;
}
static void F_109 ( struct V_1 * V_2 , struct V_8 * V_9 ,
T_1 V_186 , T_1 V_187 )
{
void T_3 * V_4 = V_9 -> V_4 ;
int V_45 = V_2 -> V_45 ;
struct V_188 * V_39 = V_9 -> V_39 . V_189 + V_45 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_4 = V_4 + V_186 ;
V_2 -> V_70 = V_4 + V_187 ;
}
static int F_110 ( struct V_190 * V_39 ,
struct V_191 * V_94 )
{
struct V_192 * V_193 = V_94 -> V_12 . V_194 ;
struct V_192 * V_195 ;
int V_93 = 0 , V_33 ;
T_1 V_196 ;
if ( ! V_193 )
return - V_143 ;
if ( F_111 ( V_193 , L_20 , & V_196 ) ) {
F_112 ( L_21 ) ;
return - V_143 ;
}
V_39 -> V_115 = V_196 ;
if ( F_111 ( V_193 , L_22 , & V_196 ) ) {
F_112 ( L_23 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_39 -> V_116 = V_196 ;
if ( F_111 ( V_193 , L_24 , & V_196 ) ) {
F_112 ( L_25 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_39 -> V_198 = V_196 ;
if ( F_111 ( V_193 , L_26 , & V_196 ) ) {
F_112 ( L_27 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_39 -> V_199 = V_196 ;
V_39 -> V_189 = F_113 ( sizeof( struct V_188 ) *
V_39 -> V_115 , V_40 ) ;
if ( ! V_39 -> V_189 ) {
F_112 ( L_28 ) ;
return - V_143 ;
}
if ( F_111 ( V_193 , L_29 , & V_196 ) ) {
F_112 ( L_30 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_39 -> V_200 = V_196 ;
if ( F_111 ( V_193 , L_31 , & V_196 ) ) {
F_112 ( L_32 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_39 -> V_201 = V_196 ;
if ( F_111 ( V_193 , L_33 , & V_196 ) ) {
F_112 ( L_34 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_39 -> V_202 = V_196 ;
if ( F_111 ( V_193 , L_35 , & V_196 ) ) {
F_112 ( L_36 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_39 -> V_99 = V_196 ;
if ( F_111 ( V_193 , L_37 , & V_196 ) ) {
F_112 ( L_38 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_39 -> V_63 = V_196 ;
V_33 = F_114 ( V_193 , NULL , NULL , & V_94 -> V_12 ) ;
if ( V_33 )
F_115 ( L_39 ) ;
F_116 (slave_node, L_40 ) {
struct V_188 * V_189 = V_39 -> V_189 + V_93 ;
const void * V_57 = NULL ;
T_1 V_203 ;
int V_204 ;
const T_5 * V_205 ;
struct V_192 * V_206 ;
struct V_191 * V_207 ;
V_205 = F_117 ( V_195 , L_41 , & V_204 ) ;
if ( ( V_205 == NULL ) && ( V_204 != ( sizeof( void * ) * 2 ) ) ) {
F_112 ( L_42 , V_93 ) ;
V_33 = - V_143 ;
goto V_197;
}
V_206 = F_118 ( F_119 ( V_205 ) ) ;
V_203 = F_119 ( V_205 + 1 ) ;
V_207 = F_120 ( V_206 ) ;
snprintf ( V_189 -> V_86 , sizeof( V_189 -> V_86 ) ,
V_208 , V_207 -> V_73 , V_203 ) ;
V_57 = F_121 ( V_195 ) ;
if ( V_57 )
memcpy ( V_189 -> V_57 , V_57 , V_209 ) ;
V_93 ++ ;
}
return 0 ;
V_197:
F_122 ( V_39 -> V_189 ) ;
return V_33 ;
}
static int F_123 ( struct V_191 * V_94 )
{
struct V_190 * V_39 = V_94 -> V_12 . V_210 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_211 V_212 ;
struct V_213 V_214 ;
void T_3 * V_215 , * V_20 ;
struct V_216 * V_217 ;
T_1 V_218 , V_219 , V_220 ;
int V_33 = 0 , V_93 , V_221 = 0 ;
V_7 = F_124 ( sizeof( struct V_8 ) ) ;
if ( ! V_7 ) {
F_112 ( L_43 ) ;
return - V_100 ;
}
F_125 ( V_94 , V_7 ) ;
V_9 = F_6 ( V_7 ) ;
F_126 ( & V_9 -> V_222 ) ;
V_9 -> V_94 = V_94 ;
V_9 -> V_7 = V_7 ;
V_9 -> V_12 = & V_7 -> V_12 ;
V_9 -> V_173 = F_127 ( V_223 , V_224 ) ;
V_9 -> V_37 = F_128 ( V_37 , 128 ) ;
F_129 ( & V_94 -> V_12 ) ;
if ( F_110 ( & V_9 -> V_39 , V_94 ) ) {
F_112 ( L_44 ) ;
V_33 = - V_225 ;
goto V_226;
}
V_39 = & V_9 -> V_39 ;
if ( F_130 ( V_39 -> V_189 [ 0 ] . V_57 ) ) {
memcpy ( V_9 -> V_57 , V_39 -> V_189 [ 0 ] . V_57 , V_209 ) ;
F_131 ( L_45 , V_9 -> V_57 ) ;
} else {
F_132 ( V_9 -> V_57 ) ;
F_131 ( L_46 , V_9 -> V_57 ) ;
}
memcpy ( V_7 -> V_227 , V_9 -> V_57 , V_209 ) ;
V_9 -> V_115 = F_113 ( sizeof( struct V_1 ) * V_39 -> V_115 ,
V_40 ) ;
if ( ! V_9 -> V_115 ) {
V_33 = - V_228 ;
goto V_226;
}
for ( V_93 = 0 ; V_93 < V_39 -> V_115 ; V_93 ++ )
V_9 -> V_115 [ V_93 ] . V_45 = V_93 ;
V_9 -> V_229 = F_133 ( & V_94 -> V_12 , L_47 ) ;
if ( F_64 ( V_9 -> V_229 ) ) {
F_7 ( & V_94 -> V_12 , L_48 ) ;
V_33 = - V_225 ;
goto V_230;
}
V_9 -> V_231 = F_134 ( V_94 , V_232 , 0 ) ;
if ( ! V_9 -> V_231 ) {
F_7 ( V_9 -> V_12 , L_49 ) ;
V_33 = - V_233 ;
goto V_234;
}
if ( ! F_135 ( V_9 -> V_231 -> V_235 ,
F_136 ( V_9 -> V_231 ) , V_7 -> V_73 ) ) {
F_7 ( V_9 -> V_12 , L_50 ) ;
V_33 = - V_236 ;
goto V_234;
}
V_215 = F_137 ( V_9 -> V_231 -> V_235 , F_136 ( V_9 -> V_231 ) ) ;
if ( ! V_215 ) {
F_7 ( V_9 -> V_12 , L_51 ) ;
goto V_237;
}
V_9 -> V_4 = V_215 ;
V_9 -> V_77 = F_2 ( & V_9 -> V_4 -> V_238 ) ;
V_9 -> V_15 = V_239 ;
V_9 -> V_240 = F_134 ( V_94 , V_232 , 1 ) ;
if ( ! V_9 -> V_240 ) {
F_7 ( V_9 -> V_12 , L_49 ) ;
V_33 = - V_233 ;
goto V_241;
}
if ( ! F_135 ( V_9 -> V_240 -> V_235 ,
F_136 ( V_9 -> V_240 ) , V_7 -> V_73 ) ) {
F_7 ( V_9 -> V_12 , L_50 ) ;
V_33 = - V_236 ;
goto V_241;
}
V_20 = F_137 ( V_9 -> V_240 -> V_235 ,
F_136 ( V_9 -> V_240 ) ) ;
if ( ! V_20 ) {
F_7 ( V_9 -> V_12 , L_51 ) ;
goto V_242;
}
V_9 -> V_20 = V_20 ;
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
memset ( & V_214 , 0 , sizeof( V_214 ) ) ;
switch ( V_9 -> V_77 ) {
case V_78 :
V_9 -> V_90 = V_215 + V_243 ;
V_9 -> V_29 . V_53 = V_215 + V_244 ;
V_212 . V_245 = V_215 + V_246 ;
V_212 . V_247 = V_215 + V_248 ;
V_214 . V_249 = V_215 + V_250 ;
V_218 = V_251 ;
V_220 = V_252 ;
V_219 = V_253 ;
V_212 . V_254 = 0 ;
break;
case V_81 :
V_9 -> V_90 = V_215 + V_255 ;
V_9 -> V_29 . V_53 = V_215 + V_256 ;
V_212 . V_245 = V_215 + V_257 ;
V_212 . V_247 = V_215 + V_258 ;
V_214 . V_249 = V_215 + V_259 ;
V_218 = V_260 ;
V_220 = V_261 ;
V_219 = V_262 ;
V_212 . V_254 =
( T_1 V_263 ) V_9 -> V_231 -> V_235 + V_264 ;
break;
default:
F_7 ( V_9 -> V_12 , L_52 , V_9 -> V_77 ) ;
V_33 = - V_225 ;
goto V_242;
}
for ( V_93 = 0 ; V_93 < V_9 -> V_39 . V_115 ; V_93 ++ ) {
struct V_1 * V_2 = & V_9 -> V_115 [ V_93 ] ;
F_109 ( V_2 , V_9 , V_218 , V_219 ) ;
V_218 += V_220 ;
V_219 += V_265 ;
}
V_212 . V_12 = & V_94 -> V_12 ;
V_212 . V_266 = V_212 . V_245 + V_267 ;
V_212 . V_268 = V_212 . V_245 + V_269 ;
V_212 . V_270 = V_212 . V_247 + V_271 ;
V_212 . V_272 = V_212 . V_247 + V_273 ;
V_212 . V_274 = V_212 . V_247 + V_275 ;
V_212 . V_276 = V_39 -> V_200 ;
V_212 . V_277 = true ;
V_212 . V_278 = V_104 ;
V_212 . V_279 = V_39 -> V_202 ;
V_212 . V_280 = 16 ;
V_212 . V_281 = true ;
V_212 . V_282 = V_212 . V_254 ;
V_9 -> V_23 = F_138 ( & V_212 ) ;
if ( ! V_9 -> V_23 ) {
F_7 ( V_9 -> V_12 , L_53 ) ;
V_33 = - V_100 ;
goto V_283;
}
V_9 -> V_50 = F_139 ( V_9 -> V_23 , F_140 ( 0 ) ,
F_15 ) ;
V_9 -> V_38 = F_139 ( V_9 -> V_23 , F_141 ( 0 ) ,
F_21 ) ;
if ( F_30 ( ! V_9 -> V_50 || ! V_9 -> V_38 ) ) {
F_7 ( V_9 -> V_12 , L_54 ) ;
V_33 = - V_100 ;
goto V_284;
}
V_214 . V_12 = & V_7 -> V_12 ;
V_214 . V_285 = V_285 ;
V_214 . V_201 = V_39 -> V_201 ;
V_214 . V_286 = V_39 -> V_115 ;
V_9 -> V_13 = F_142 ( & V_214 ) ;
if ( ! V_9 -> V_13 ) {
F_7 ( V_9 -> V_12 , L_55 ) ;
V_33 = - V_225 ;
goto V_284;
}
V_7 -> V_41 = F_143 ( V_94 , 0 ) ;
if ( V_7 -> V_41 < 0 ) {
F_7 ( V_9 -> V_12 , L_56 ) ;
V_33 = - V_233 ;
goto V_287;
}
while ( ( V_217 = F_134 ( V_9 -> V_94 , V_288 , V_221 ) ) ) {
for ( V_93 = V_217 -> V_235 ; V_93 <= V_217 -> V_289 ; V_93 ++ ) {
if ( F_144 ( V_93 , F_33 , V_290 ,
F_145 ( & V_94 -> V_12 ) , V_9 ) ) {
F_7 ( V_9 -> V_12 , L_57 ) ;
goto V_287;
}
V_9 -> V_291 [ V_221 ] = V_93 ;
V_9 -> V_292 = V_221 ;
}
V_221 ++ ;
}
V_7 -> V_10 |= V_114 ;
V_7 -> V_293 = & V_294 ;
F_146 ( V_7 , & V_295 ) ;
F_147 ( V_7 , & V_9 -> V_43 , F_37 , V_296 ) ;
F_148 ( V_7 , & V_94 -> V_12 ) ;
V_33 = F_149 ( V_7 ) ;
if ( V_33 ) {
F_7 ( V_9 -> V_12 , L_58 ) ;
V_33 = - V_225 ;
goto V_297;
}
if ( F_150 ( & V_94 -> V_12 , & V_9 -> V_29 ,
V_39 -> V_198 , V_39 -> V_199 ) )
F_7 ( V_9 -> V_12 , L_59 ) ;
F_151 ( V_9 , V_298 , L_60 ,
V_9 -> V_231 -> V_235 , V_7 -> V_41 ) ;
return 0 ;
V_297:
F_152 ( V_7 -> V_41 , V_9 ) ;
V_287:
F_153 ( V_9 -> V_13 ) ;
V_284:
F_154 ( V_9 -> V_50 ) ;
F_154 ( V_9 -> V_38 ) ;
F_155 ( V_9 -> V_23 ) ;
V_283:
F_156 ( V_9 -> V_20 ) ;
V_242:
F_157 ( V_9 -> V_240 -> V_235 ,
F_136 ( V_9 -> V_240 ) ) ;
V_241:
F_156 ( V_9 -> V_4 ) ;
V_237:
F_157 ( V_9 -> V_231 -> V_235 ,
F_136 ( V_9 -> V_231 ) ) ;
V_234:
F_158 ( V_9 -> V_229 ) ;
V_230:
F_159 ( & V_94 -> V_12 ) ;
F_122 ( V_9 -> V_115 ) ;
V_226:
F_160 ( V_7 ) ;
return V_33 ;
}
static int F_161 ( struct V_191 * V_94 )
{
struct V_6 * V_7 = F_162 ( V_94 ) ;
struct V_8 * V_9 = F_6 ( V_7 ) ;
F_131 ( L_61 ) ;
F_125 ( V_94 , NULL ) ;
F_163 ( & V_9 -> V_29 ) ;
F_152 ( V_7 -> V_41 , V_9 ) ;
F_153 ( V_9 -> V_13 ) ;
F_154 ( V_9 -> V_50 ) ;
F_154 ( V_9 -> V_38 ) ;
F_155 ( V_9 -> V_23 ) ;
F_156 ( V_9 -> V_4 ) ;
F_157 ( V_9 -> V_231 -> V_235 ,
F_136 ( V_9 -> V_231 ) ) ;
F_156 ( V_9 -> V_20 ) ;
F_157 ( V_9 -> V_240 -> V_235 ,
F_136 ( V_9 -> V_240 ) ) ;
F_159 ( & V_94 -> V_12 ) ;
F_158 ( V_9 -> V_229 ) ;
F_122 ( V_9 -> V_115 ) ;
F_160 ( V_7 ) ;
return 0 ;
}
static int F_164 ( struct V_299 * V_12 )
{
struct V_191 * V_94 = F_165 ( V_12 ) ;
struct V_6 * V_7 = F_162 ( V_94 ) ;
if ( F_22 ( V_7 ) )
F_82 ( V_7 ) ;
F_86 ( & V_94 -> V_12 ) ;
return 0 ;
}
static int F_166 ( struct V_299 * V_12 )
{
struct V_191 * V_94 = F_165 ( V_12 ) ;
struct V_6 * V_7 = F_162 ( V_94 ) ;
F_71 ( & V_94 -> V_12 ) ;
if ( F_22 ( V_7 ) )
F_70 ( V_7 ) ;
return 0 ;
}
static int T_6 F_167 ( void )
{
return F_168 ( & V_300 ) ;
}
static void T_7 F_169 ( void )
{
F_170 ( & V_300 ) ;
}
