static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ) ;
}
static void F_4 ( T_1 * V_3 )
{
if ( ! F_5 ( & V_3 -> V_4 ) ) {
F_6 ( & V_5 ) ;
F_7 ( & V_3 -> V_4 ) ;
F_8 ( & V_5 ) ;
F_2 ( V_3 ) ;
}
}
static void F_9 ( struct V_6 * V_7 )
{
T_2 * T_2 ;
T_1 * V_8 ;
if ( ( T_2 = F_10 ( V_7 ) ) == NULL )
return;
F_6 ( & V_5 ) ;
V_9:
F_11 (s, &ax25_list) {
if ( V_8 -> T_2 == T_2 ) {
V_8 -> T_2 = NULL ;
F_8 ( & V_5 ) ;
F_12 ( V_8 , V_10 ) ;
F_6 ( & V_5 ) ;
goto V_9;
}
}
F_8 ( & V_5 ) ;
}
static int F_13 ( struct V_11 * V_12 , unsigned long V_13 ,
void * V_14 )
{
struct V_6 * V_7 = F_14 ( V_14 ) ;
if ( ! F_15 ( F_16 ( V_7 ) , & V_15 ) )
return V_16 ;
if ( V_7 -> type != V_17 )
return V_16 ;
switch ( V_13 ) {
case V_18 :
F_17 ( V_7 ) ;
break;
case V_19 :
F_9 ( V_7 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
break;
default:
break;
}
return V_16 ;
}
void F_20 ( T_1 * V_3 )
{
F_6 ( & V_5 ) ;
F_21 ( V_3 ) ;
F_22 ( & V_3 -> V_4 , & V_20 ) ;
F_8 ( & V_5 ) ;
}
struct V_1 * F_23 ( T_3 * V_21 , int V_22 ,
struct V_6 * V_7 , int type )
{
T_1 * V_8 ;
F_24 ( & V_5 ) ;
F_11 (s, &ax25_list) {
if ( ( V_8 -> V_23 && ! V_22 ) || ( ! V_8 -> V_23 && V_22 ) )
continue;
if ( V_8 -> V_2 && ! F_25 ( & V_8 -> V_24 , V_21 ) &&
V_8 -> V_2 -> V_25 == type && V_8 -> V_2 -> V_26 == V_27 ) {
if ( V_8 -> T_2 == NULL || V_8 -> T_2 -> V_7 == V_7 ) {
F_26 ( V_8 -> V_2 ) ;
F_27 ( & V_5 ) ;
return V_8 -> V_2 ;
}
}
}
F_27 ( & V_5 ) ;
return NULL ;
}
struct V_1 * F_28 ( T_3 * V_28 , T_3 * V_29 ,
int type )
{
struct V_1 * V_2 = NULL ;
T_1 * V_8 ;
F_24 ( & V_5 ) ;
F_11 (s, &ax25_list) {
if ( V_8 -> V_2 && ! F_25 ( & V_8 -> V_24 , V_28 ) &&
! F_25 ( & V_8 -> V_29 , V_29 ) &&
V_8 -> V_2 -> V_25 == type ) {
V_2 = V_8 -> V_2 ;
F_26 ( V_2 ) ;
break;
}
}
F_27 ( & V_5 ) ;
return V_2 ;
}
T_1 * F_29 ( T_3 * V_30 , T_3 * V_29 ,
T_4 * V_22 , struct V_6 * V_7 )
{
T_1 * V_8 ;
F_6 ( & V_5 ) ;
F_11 (s, &ax25_list) {
if ( V_8 -> V_2 && V_8 -> V_2 -> V_25 != V_31 )
continue;
if ( V_8 -> T_2 == NULL )
continue;
if ( F_25 ( & V_8 -> V_24 , V_30 ) == 0 && F_25 ( & V_8 -> V_29 , V_29 ) == 0 && V_8 -> T_2 -> V_7 == V_7 ) {
if ( V_22 != NULL && V_22 -> V_32 != 0 ) {
if ( V_8 -> V_33 == NULL )
continue;
if ( F_30 ( V_8 -> V_33 , V_22 ) != 0 )
continue;
} else {
if ( V_8 -> V_33 != NULL && V_8 -> V_33 -> V_32 != 0 )
continue;
}
F_21 ( V_8 ) ;
F_8 ( & V_5 ) ;
return V_8 ;
}
}
F_8 ( & V_5 ) ;
return NULL ;
}
void F_31 ( T_3 * V_21 , struct V_34 * V_35 , int V_36 )
{
T_1 * V_8 ;
struct V_34 * V_37 ;
F_24 ( & V_5 ) ;
F_11 (s, &ax25_list) {
if ( V_8 -> V_2 != NULL && F_25 ( & V_8 -> V_24 , V_21 ) == 0 &&
V_8 -> V_2 -> V_25 == V_38 &&
V_8 -> V_2 -> V_39 == V_36 &&
V_8 -> T_2 -> V_7 == V_35 -> V_7 &&
F_32 ( & V_8 -> V_2 -> V_40 ) <= V_8 -> V_2 -> V_41 ) {
if ( ( V_37 = F_33 ( V_35 , V_42 ) ) == NULL )
continue;
if ( F_34 ( V_8 -> V_2 , V_37 ) != 0 )
F_35 ( V_37 ) ;
}
}
F_27 ( & V_5 ) ;
}
static void F_36 ( unsigned long V_43 )
{
T_1 * V_3 = ( T_1 * ) V_43 ;
struct V_1 * V_2 ;
V_2 = V_3 -> V_2 ;
F_37 ( V_2 ) ;
F_26 ( V_2 ) ;
F_38 ( V_3 ) ;
F_39 ( V_2 ) ;
F_40 ( V_2 ) ;
}
void F_38 ( T_1 * V_3 )
{
struct V_34 * V_35 ;
F_4 ( V_3 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 ) ;
if ( V_3 -> V_2 != NULL ) {
while ( ( V_35 = F_47 ( & V_3 -> V_2 -> V_44 ) ) != NULL ) {
if ( V_35 -> V_2 != V_3 -> V_2 ) {
T_1 * V_45 = F_3 ( V_35 -> V_2 ) ;
F_48 ( V_35 -> V_2 ) ;
V_35 -> V_2 -> V_26 = V_27 ;
F_49 ( V_45 ) ;
V_45 -> V_46 = V_47 ;
}
F_35 ( V_35 ) ;
}
F_50 ( & V_3 -> V_2 -> V_48 ) ;
}
if ( V_3 -> V_2 != NULL ) {
if ( F_51 ( V_3 -> V_2 ) ) {
F_52 ( & V_3 -> V_49 , F_36 ,
( unsigned long ) V_3 ) ;
V_3 -> V_49 . V_50 = V_51 + 2 * V_52 ;
F_53 ( & V_3 -> V_49 ) ;
} else {
struct V_1 * V_2 = V_3 -> V_2 ;
V_3 -> V_2 = NULL ;
F_40 ( V_2 ) ;
}
} else {
F_2 ( V_3 ) ;
}
}
static int F_54 ( const unsigned int V_53 , void T_5 * V_54 )
{
struct V_55 V_56 ;
T_4 V_22 ;
T_2 * T_2 ;
T_1 * V_3 ;
unsigned int V_57 ;
int V_58 = 0 ;
if ( F_55 ( & V_56 , V_54 , sizeof( V_56 ) ) )
return - V_59 ;
if ( ( T_2 = F_56 ( & V_56 . V_60 ) ) == NULL )
return - V_61 ;
if ( V_56 . V_62 > V_63 )
return - V_64 ;
if ( V_56 . V_54 > V_65 / V_52 && V_56 . V_53 != V_66 )
return - V_64 ;
V_22 . V_32 = V_56 . V_62 ;
for ( V_57 = 0 ; V_57 < V_22 . V_32 ; V_57 ++ )
V_22 . V_67 [ V_57 ] = V_56 . V_68 [ V_57 ] ;
if ( ( V_3 = F_29 ( & V_56 . V_24 , & V_56 . V_29 , & V_22 , T_2 -> V_7 ) ) == NULL )
return - V_69 ;
switch ( V_56 . V_53 ) {
case V_66 :
F_57 ( V_3 , V_70 , V_71 , V_72 ) ;
#ifdef F_58
if ( T_2 -> V_73 . V_74 && V_3 -> T_2 -> V_75 [ V_76 ] == V_77 )
F_59 ( V_3 ) ;
#endif
F_12 ( V_3 , V_78 ) ;
break;
case V_79 :
if ( V_3 -> V_80 == V_81 ) {
if ( V_56 . V_54 < 1 || V_56 . V_54 > 7 )
goto V_82;
} else {
if ( V_56 . V_54 < 1 || V_56 . V_54 > 63 )
goto V_82;
}
V_3 -> V_83 = V_56 . V_54 ;
break;
case V_84 :
if ( V_56 . V_54 < 1 || V_56 . V_54 > V_65 / V_52 )
goto V_82;
V_3 -> V_85 = ( V_56 . V_54 * V_52 ) / 2 ;
V_3 -> V_86 = V_56 . V_54 * V_52 ;
break;
case V_87 :
if ( V_56 . V_54 < 1 || V_56 . V_54 > V_65 / V_52 )
goto V_82;
V_3 -> V_88 = V_56 . V_54 * V_52 ;
break;
case V_89 :
if ( V_56 . V_54 < 1 || V_56 . V_54 > 31 )
goto V_82;
V_3 -> V_90 = 0 ;
V_3 -> V_91 = V_56 . V_54 ;
break;
case V_92 :
if ( V_56 . V_54 > V_65 / V_52 )
goto V_82;
V_3 -> V_93 = V_56 . V_54 * V_52 ;
break;
case V_94 :
if ( V_56 . V_54 > V_65 / ( 60 * V_52 ) )
goto V_82;
V_3 -> V_95 = V_56 . V_54 * 60 * V_52 ;
break;
case V_96 :
if ( V_56 . V_54 < 16 || V_56 . V_54 > 65535 )
goto V_82;
V_3 -> V_97 = V_56 . V_54 ;
break;
default:
goto V_82;
}
V_98:
F_2 ( V_3 ) ;
return V_58 ;
V_82:
V_58 = - V_64 ;
goto V_98;
}
static void F_60 ( T_1 * V_3 , T_2 * T_2 )
{
V_3 -> V_85 = F_61 ( T_2 -> V_75 [ V_99 ] ) / 2 ;
V_3 -> V_86 = F_61 ( T_2 -> V_75 [ V_99 ] ) ;
V_3 -> V_88 = F_61 ( T_2 -> V_75 [ V_100 ] ) ;
V_3 -> V_93 = F_61 ( T_2 -> V_75 [ V_101 ] ) ;
V_3 -> V_91 = T_2 -> V_75 [ V_102 ] ;
V_3 -> V_97 = T_2 -> V_75 [ V_103 ] ;
V_3 -> V_95 = F_61 ( T_2 -> V_75 [ V_104 ] ) ;
V_3 -> V_105 = T_2 -> V_75 [ V_106 ] ;
if ( T_2 -> V_75 [ V_107 ] ) {
V_3 -> V_80 = V_108 ;
V_3 -> V_83 = T_2 -> V_75 [ V_109 ] ;
} else {
V_3 -> V_80 = V_81 ;
V_3 -> V_83 = T_2 -> V_75 [ V_110 ] ;
}
}
void F_62 ( T_1 * V_3 , T_2 * T_2 )
{
V_3 -> T_2 = T_2 ;
if ( V_3 -> T_2 != NULL ) {
F_60 ( V_3 , T_2 ) ;
return;
}
V_3 -> V_85 = F_61 ( V_111 ) / 2 ;
V_3 -> V_86 = F_61 ( V_111 ) ;
V_3 -> V_88 = F_61 ( V_112 ) ;
V_3 -> V_93 = F_61 ( V_113 ) ;
V_3 -> V_91 = V_114 ;
V_3 -> V_97 = V_115 ;
V_3 -> V_95 = F_61 ( V_116 ) ;
V_3 -> V_105 = V_117 ;
if ( V_118 ) {
V_3 -> V_80 = V_108 ;
V_3 -> V_83 = V_119 ;
} else {
V_3 -> V_80 = V_81 ;
V_3 -> V_83 = V_120 ;
}
}
T_1 * F_63 ( void )
{
T_1 * V_3 ;
if ( ( V_3 = F_64 ( sizeof( * V_3 ) , V_42 ) ) == NULL )
return NULL ;
F_65 ( & V_3 -> V_121 , 1 ) ;
F_66 ( & V_3 -> V_122 ) ;
F_66 ( & V_3 -> V_123 ) ;
F_66 ( & V_3 -> V_124 ) ;
F_66 ( & V_3 -> V_125 ) ;
F_67 ( V_3 ) ;
F_62 ( V_3 , NULL ) ;
V_3 -> V_46 = V_47 ;
return V_3 ;
}
static int F_68 ( struct V_126 * V_1 , int V_127 , int V_128 ,
char T_5 * V_129 , unsigned int V_130 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
T_1 * V_3 ;
struct V_6 * V_7 ;
char V_131 [ V_132 ] ;
unsigned long V_133 ;
int V_134 = 0 ;
if ( V_127 != V_135 )
return - V_136 ;
if ( V_130 < sizeof( unsigned int ) )
return - V_64 ;
if ( F_69 ( V_133 , ( unsigned int T_5 * ) V_129 ) )
return - V_59 ;
F_70 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
switch ( V_128 ) {
case V_79 :
if ( V_3 -> V_80 == V_81 ) {
if ( V_133 < 1 || V_133 > 7 ) {
V_134 = - V_64 ;
break;
}
} else {
if ( V_133 < 1 || V_133 > 63 ) {
V_134 = - V_64 ;
break;
}
}
V_3 -> V_83 = V_133 ;
break;
case V_84 :
if ( V_133 < 1 || V_133 > V_65 / V_52 ) {
V_134 = - V_64 ;
break;
}
V_3 -> V_85 = ( V_133 * V_52 ) >> 1 ;
V_3 -> V_86 = V_133 * V_52 ;
break;
case V_87 :
if ( V_133 < 1 || V_133 > V_65 / V_52 ) {
V_134 = - V_64 ;
break;
}
V_3 -> V_88 = V_133 * V_52 ;
break;
case V_89 :
if ( V_133 < 1 || V_133 > 31 ) {
V_134 = - V_64 ;
break;
}
V_3 -> V_91 = V_133 ;
break;
case V_92 :
if ( V_133 < 1 || V_133 > V_65 / V_52 ) {
V_134 = - V_64 ;
break;
}
V_3 -> V_93 = V_133 * V_52 ;
break;
case V_94 :
if ( V_133 > V_65 / ( 60 * V_52 ) ) {
V_134 = - V_64 ;
break;
}
V_3 -> V_95 = V_133 * 60 * V_52 ;
break;
case V_137 :
if ( V_133 > 2 ) {
V_134 = - V_64 ;
break;
}
V_3 -> V_105 = V_133 ;
break;
case V_138 :
V_3 -> V_80 = V_133 ? V_108 : V_81 ;
break;
case V_139 :
V_3 -> V_140 = V_133 ? 1 : 0 ;
break;
case V_141 :
V_3 -> V_23 = V_133 ? 1 : 0 ;
break;
case V_96 :
if ( V_133 < 16 || V_133 > 65535 ) {
V_134 = - V_64 ;
break;
}
V_3 -> V_97 = V_133 ;
break;
case V_142 :
if ( V_130 > V_132 )
V_130 = V_132 ;
if ( F_55 ( V_131 , V_129 , V_130 ) ) {
V_134 = - V_59 ;
break;
}
if ( V_2 -> V_25 == V_31 &&
( V_1 -> V_46 != V_143 ||
V_2 -> V_26 == V_27 ) ) {
V_134 = - V_144 ;
break;
}
V_7 = F_71 ( & V_15 , V_131 ) ;
if ( ! V_7 ) {
V_134 = - V_61 ;
break;
}
V_3 -> T_2 = F_10 ( V_7 ) ;
F_62 ( V_3 , V_3 -> T_2 ) ;
F_72 ( V_7 ) ;
break;
default:
V_134 = - V_136 ;
}
F_73 ( V_2 ) ;
return V_134 ;
}
static int F_74 ( struct V_126 * V_1 , int V_127 , int V_128 ,
char T_5 * V_129 , int T_5 * V_130 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
T_1 * V_3 ;
struct T_2 * T_2 ;
char V_131 [ V_132 ] ;
void * V_145 ;
int V_146 = 0 ;
int V_147 , V_148 ;
if ( V_127 != V_135 )
return - V_136 ;
if ( F_69 ( V_147 , V_130 ) )
return - V_59 ;
if ( V_147 < 1 )
return - V_59 ;
V_145 = ( void * ) & V_146 ;
V_148 = F_75 (unsigned int, maxlen, sizeof(int)) ;
F_70 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
switch ( V_128 ) {
case V_79 :
V_146 = V_3 -> V_83 ;
break;
case V_84 :
V_146 = V_3 -> V_86 / V_52 ;
break;
case V_87 :
V_146 = V_3 -> V_88 / V_52 ;
break;
case V_89 :
V_146 = V_3 -> V_91 ;
break;
case V_92 :
V_146 = V_3 -> V_93 / V_52 ;
break;
case V_94 :
V_146 = V_3 -> V_95 / ( 60 * V_52 ) ;
break;
case V_137 :
V_146 = V_3 -> V_105 ;
break;
case V_138 :
V_146 = ( V_3 -> V_80 == V_108 ) ;
break;
case V_139 :
V_146 = V_3 -> V_140 ;
break;
case V_141 :
V_146 = V_3 -> V_23 ;
break;
case V_96 :
V_146 = V_3 -> V_97 ;
break;
case V_142 :
T_2 = V_3 -> T_2 ;
if ( T_2 != NULL && T_2 -> V_7 != NULL ) {
F_76 ( V_131 , T_2 -> V_7 -> V_149 , sizeof( V_131 ) ) ;
V_148 = strlen ( V_131 ) + 1 ;
} else {
* V_131 = '\0' ;
V_148 = 1 ;
}
V_145 = ( void * ) V_131 ;
break;
default:
F_73 ( V_2 ) ;
return - V_136 ;
}
F_73 ( V_2 ) ;
if ( F_77 ( V_148 , V_130 ) )
return - V_59 ;
return F_78 ( V_129 , V_145 , V_148 ) ? - V_59 : 0 ;
}
static int F_79 ( struct V_126 * V_1 , int V_150 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_134 = 0 ;
F_70 ( V_2 ) ;
if ( V_2 -> V_25 == V_31 && V_2 -> V_26 != V_27 ) {
V_2 -> V_151 = V_150 ;
V_2 -> V_26 = V_27 ;
goto V_152;
}
V_134 = - V_153 ;
V_152:
F_73 ( V_2 ) ;
return V_134 ;
}
static int F_80 ( struct V_154 * V_154 , struct V_126 * V_1 , int V_155 ,
int V_156 )
{
struct V_1 * V_2 ;
T_1 * V_3 ;
if ( ! F_15 ( V_154 , & V_15 ) )
return - V_157 ;
switch ( V_1 -> type ) {
case V_158 :
if ( V_155 == 0 || V_155 == V_159 )
V_155 = V_160 ;
break;
case V_31 :
switch ( V_155 ) {
case 0 :
case V_159 :
V_155 = V_160 ;
break;
case V_161 :
#ifdef F_81
case V_162 :
case V_163 :
#endif
#ifdef F_82
case V_164 :
#endif
#ifdef F_83
case V_165 :
#endif
return - V_166 ;
#ifdef F_84
case V_164 :
if ( F_85 ( V_164 ) )
return - V_166 ;
break;
#endif
#ifdef F_86
case V_165 :
if ( F_85 ( V_165 ) )
return - V_166 ;
#endif
default:
break;
}
break;
case V_38 :
break;
default:
return - V_166 ;
}
V_2 = F_87 ( V_154 , V_159 , V_42 , & V_167 ) ;
if ( V_2 == NULL )
return - V_168 ;
V_3 = V_2 -> V_169 = F_63 () ;
if ( ! V_3 ) {
F_88 ( V_2 ) ;
return - V_168 ;
}
F_89 ( V_1 , V_2 ) ;
V_2 -> V_170 = F_1 ;
V_1 -> V_171 = & V_172 ;
V_2 -> V_39 = V_155 ;
V_3 -> V_2 = V_2 ;
return 0 ;
}
struct V_1 * F_90 ( struct V_1 * V_173 , struct T_2 * T_2 )
{
struct V_1 * V_2 ;
T_1 * V_3 , * V_174 ;
V_2 = F_87 ( F_91 ( V_173 ) , V_159 , V_42 , V_173 -> V_175 ) ;
if ( V_2 == NULL )
return NULL ;
if ( ( V_3 = F_63 () ) == NULL ) {
F_88 ( V_2 ) ;
return NULL ;
}
switch ( V_173 -> V_25 ) {
case V_158 :
break;
case V_31 :
break;
default:
F_88 ( V_2 ) ;
F_2 ( V_3 ) ;
return NULL ;
}
F_89 ( NULL , V_2 ) ;
V_2 -> V_25 = V_173 -> V_25 ;
V_2 -> V_176 = V_173 -> V_176 ;
V_2 -> V_39 = V_173 -> V_39 ;
V_2 -> V_41 = V_173 -> V_41 ;
V_2 -> V_177 = V_173 -> V_177 ;
V_2 -> V_26 = V_178 ;
F_92 ( V_2 , V_173 ) ;
V_174 = F_3 ( V_173 ) ;
V_3 -> V_80 = V_174 -> V_80 ;
V_3 -> V_105 = V_174 -> V_105 ;
V_3 -> V_140 = V_174 -> V_140 ;
V_3 -> V_23 = V_174 -> V_23 ;
V_3 -> V_85 = V_174 -> V_85 ;
V_3 -> V_86 = V_174 -> V_86 ;
V_3 -> V_88 = V_174 -> V_88 ;
V_3 -> V_93 = V_174 -> V_93 ;
V_3 -> V_91 = V_174 -> V_91 ;
V_3 -> V_95 = V_174 -> V_95 ;
V_3 -> V_97 = V_174 -> V_97 ;
V_3 -> V_83 = V_174 -> V_83 ;
V_3 -> T_2 = T_2 ;
V_3 -> V_24 = V_174 -> V_24 ;
if ( V_174 -> V_33 != NULL ) {
V_3 -> V_33 = F_93 ( V_174 -> V_33 , sizeof( T_4 ) ,
V_42 ) ;
if ( V_3 -> V_33 == NULL ) {
F_88 ( V_2 ) ;
F_2 ( V_3 ) ;
return NULL ;
}
}
V_2 -> V_169 = V_3 ;
V_2 -> V_170 = F_1 ;
V_3 -> V_2 = V_2 ;
return V_2 ;
}
static int F_94 ( struct V_126 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
T_1 * V_3 ;
if ( V_2 == NULL )
return 0 ;
F_26 ( V_2 ) ;
F_48 ( V_2 ) ;
F_70 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_2 -> V_25 == V_31 ) {
switch ( V_3 -> V_46 ) {
case V_47 :
F_73 ( V_2 ) ;
F_12 ( V_3 , 0 ) ;
F_70 ( V_2 ) ;
F_38 ( V_3 ) ;
break;
case V_179 :
case V_180 :
F_57 ( V_3 , V_70 , V_71 , V_72 ) ;
F_73 ( V_2 ) ;
F_12 ( V_3 , 0 ) ;
F_70 ( V_2 ) ;
F_38 ( V_3 ) ;
break;
case V_181 :
case V_182 :
F_46 ( V_3 ) ;
V_3 -> V_90 = 0 ;
switch ( V_3 -> T_2 -> V_75 [ V_76 ] ) {
case V_183 :
case V_184 :
F_57 ( V_3 ,
V_70 ,
V_71 ,
V_72 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
break;
#ifdef F_58
case V_77 :
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
break;
#endif
}
F_95 ( V_3 ) ;
F_96 ( V_3 ) ;
V_3 -> V_46 = V_180 ;
V_2 -> V_26 = V_185 ;
V_2 -> V_186 |= V_187 ;
V_2 -> V_188 ( V_2 ) ;
F_97 ( V_2 , V_189 ) ;
break;
default:
break;
}
} else {
V_2 -> V_26 = V_185 ;
V_2 -> V_186 |= V_187 ;
V_2 -> V_188 ( V_2 ) ;
F_38 ( V_3 ) ;
}
V_1 -> V_2 = NULL ;
F_73 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_98 ( struct V_126 * V_1 , struct V_190 * V_191 , int V_192 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_193 * V_21 = (struct V_193 * ) V_191 ;
T_2 * T_2 = NULL ;
T_6 * V_194 ;
T_3 V_195 ;
T_1 * V_3 ;
int V_196 = 0 ;
if ( V_192 != sizeof( struct V_197 ) &&
V_192 != sizeof( struct V_193 ) )
if ( ( V_192 < sizeof( struct V_197 ) + sizeof( T_3 ) * 6 ) ||
( V_192 > sizeof( struct V_193 ) ) )
return - V_64 ;
if ( V_21 -> V_198 . V_199 != V_200 )
return - V_64 ;
V_194 = F_99 ( F_100 () ) ;
if ( V_194 ) {
V_195 = V_194 -> V_195 ;
F_101 ( V_194 ) ;
} else {
if ( V_201 && ! F_102 ( V_202 ) )
return - V_203 ;
V_195 = V_21 -> V_198 . V_204 ;
}
F_70 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
if ( ! F_103 ( V_2 , V_205 ) ) {
V_196 = - V_64 ;
goto V_152;
}
V_3 -> V_24 = V_195 ;
if ( V_3 -> T_2 != NULL )
goto V_206;
if ( V_192 > sizeof( struct V_197 ) && V_21 -> V_198 . V_207 == 1 ) {
if ( F_25 ( & V_21 -> V_208 [ 0 ] , & V_209 ) != 0 &&
( T_2 = F_56 ( & V_21 -> V_208 [ 0 ] ) ) == NULL ) {
V_196 = - V_144 ;
goto V_152;
}
} else {
if ( ( T_2 = F_56 ( & V_21 -> V_198 . V_204 ) ) == NULL ) {
V_196 = - V_144 ;
goto V_152;
}
}
if ( T_2 != NULL )
F_62 ( V_3 , T_2 ) ;
V_206:
F_20 ( V_3 ) ;
F_104 ( V_2 , V_205 ) ;
V_152:
F_73 ( V_2 ) ;
return V_196 ;
}
static int T_7 F_105 ( struct V_126 * V_1 ,
struct V_190 * V_191 , int V_192 , int V_210 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
T_1 * V_3 = F_3 ( V_2 ) , * V_211 ;
struct V_193 * V_212 = (struct V_193 * ) V_191 ;
T_4 * V_22 = NULL ;
int V_213 = 0 , V_196 = 0 ;
if ( V_192 == sizeof( struct V_197 ) )
;
else if ( V_192 != sizeof( struct V_193 ) )
if ( ( V_192 < sizeof( struct V_197 ) + sizeof( T_3 ) * 6 ) ||
( V_192 > sizeof( struct V_193 ) ) )
return - V_64 ;
if ( V_212 -> V_198 . V_199 != V_200 )
return - V_64 ;
F_70 ( V_2 ) ;
if ( V_1 -> V_46 == V_214 ) {
switch ( V_2 -> V_26 ) {
case V_215 :
V_196 = - V_216 ;
goto V_217;
case V_178 :
V_1 -> V_46 = V_218 ;
goto V_217;
case V_185 :
V_1 -> V_46 = V_143 ;
V_196 = - V_219 ;
goto V_217;
}
}
if ( V_2 -> V_26 == V_178 && V_2 -> V_25 == V_31 ) {
V_196 = - V_220 ;
goto V_217;
}
V_2 -> V_26 = V_185 ;
V_1 -> V_46 = V_143 ;
F_106 ( V_3 -> V_33 ) ;
V_3 -> V_33 = NULL ;
if ( V_192 > sizeof( struct V_197 ) &&
V_212 -> V_198 . V_207 != 0 ) {
if ( V_212 -> V_198 . V_207 < 1 || V_212 -> V_198 . V_207 > V_63 ) {
V_196 = - V_64 ;
goto V_217;
}
if ( ( V_22 = F_107 ( sizeof( T_4 ) , V_221 ) ) == NULL ) {
V_196 = - V_222 ;
goto V_217;
}
V_22 -> V_32 = V_212 -> V_198 . V_207 ;
V_22 -> V_223 = - 1 ;
while ( V_213 < V_212 -> V_198 . V_207 ) {
if ( ( V_212 -> V_208 [ V_213 ] . V_224 [ 6 ] &
V_225 ) && V_3 -> V_23 ) {
V_22 -> V_226 [ V_213 ] = 1 ;
V_22 -> V_223 = V_213 ;
} else {
V_22 -> V_226 [ V_213 ] = 0 ;
}
V_22 -> V_67 [ V_213 ] = V_212 -> V_208 [ V_213 ] ;
V_213 ++ ;
}
}
if ( F_103 ( V_2 , V_205 ) ) {
F_108 ( V_227 L_1 ,
V_228 -> V_229 ) ;
if ( ( V_196 = F_109 ( V_3 , & V_212 -> V_198 . V_204 ) ) < 0 ) {
F_106 ( V_22 ) ;
goto V_217;
}
F_62 ( V_3 , V_3 -> T_2 ) ;
F_20 ( V_3 ) ;
} else {
if ( V_3 -> T_2 == NULL ) {
F_106 ( V_22 ) ;
V_196 = - V_230 ;
goto V_217;
}
}
if ( V_2 -> V_25 == V_31 &&
( V_211 = F_29 ( & V_3 -> V_24 , & V_212 -> V_198 . V_204 , V_22 ,
V_3 -> T_2 -> V_7 ) ) ) {
F_106 ( V_22 ) ;
V_196 = - V_231 ;
F_2 ( V_211 ) ;
goto V_217;
}
V_3 -> V_29 = V_212 -> V_198 . V_204 ;
V_3 -> V_33 = V_22 ;
if ( V_2 -> V_25 != V_31 ) {
V_1 -> V_46 = V_218 ;
V_2 -> V_26 = V_178 ;
goto V_217;
}
V_1 -> V_46 = V_214 ;
V_2 -> V_26 = V_215 ;
switch ( V_3 -> T_2 -> V_75 [ V_76 ] ) {
case V_183 :
case V_184 :
F_110 ( V_3 ) ;
break;
#ifdef F_58
case V_77 :
V_3 -> V_80 = V_81 ;
V_3 -> V_83 = V_3 -> T_2 -> V_75 [ V_110 ] ;
if ( V_3 -> T_2 -> V_73 . V_74 )
F_111 ( V_3 ) ;
else
F_110 ( V_3 ) ;
break;
#endif
}
V_3 -> V_46 = V_179 ;
F_49 ( V_3 ) ;
if ( V_2 -> V_26 != V_178 && ( V_210 & V_232 ) ) {
V_196 = - V_216 ;
goto V_217;
}
if ( V_2 -> V_26 == V_215 ) {
F_112 ( V_233 ) ;
for (; ; ) {
F_113 ( F_114 ( V_2 ) , & V_233 ,
V_234 ) ;
if ( V_2 -> V_26 != V_215 )
break;
if ( ! F_115 ( V_228 ) ) {
F_73 ( V_2 ) ;
F_116 () ;
F_70 ( V_2 ) ;
continue;
}
V_196 = - V_235 ;
break;
}
F_117 ( F_114 ( V_2 ) , & V_233 ) ;
if ( V_196 )
goto V_217;
}
if ( V_2 -> V_26 != V_178 ) {
V_1 -> V_46 = V_143 ;
V_196 = F_118 ( V_2 ) ;
goto V_217;
}
V_1 -> V_46 = V_218 ;
V_196 = 0 ;
V_217:
F_73 ( V_2 ) ;
return V_196 ;
}
static int F_119 ( struct V_126 * V_1 , struct V_126 * V_236 , int V_210 )
{
struct V_34 * V_35 ;
struct V_1 * V_237 ;
F_112 ( V_233 ) ;
struct V_1 * V_2 ;
int V_196 = 0 ;
if ( V_1 -> V_46 != V_143 )
return - V_64 ;
if ( ( V_2 = V_1 -> V_2 ) == NULL )
return - V_64 ;
F_70 ( V_2 ) ;
if ( V_2 -> V_25 != V_31 ) {
V_196 = - V_153 ;
goto V_152;
}
if ( V_2 -> V_26 != V_27 ) {
V_196 = - V_64 ;
goto V_152;
}
for (; ; ) {
F_113 ( F_114 ( V_2 ) , & V_233 , V_234 ) ;
V_35 = F_47 ( & V_2 -> V_44 ) ;
if ( V_35 )
break;
if ( V_210 & V_232 ) {
V_196 = - V_238 ;
break;
}
if ( ! F_115 ( V_228 ) ) {
F_73 ( V_2 ) ;
F_116 () ;
F_70 ( V_2 ) ;
continue;
}
V_196 = - V_235 ;
break;
}
F_117 ( F_114 ( V_2 ) , & V_233 ) ;
if ( V_196 )
goto V_152;
V_237 = V_35 -> V_2 ;
F_120 ( V_237 , V_236 ) ;
F_35 ( V_35 ) ;
V_2 -> V_239 -- ;
V_236 -> V_46 = V_218 ;
V_152:
F_73 ( V_2 ) ;
return V_196 ;
}
static int F_121 ( struct V_126 * V_1 , struct V_190 * V_191 ,
int * V_240 , int V_241 )
{
struct V_193 * V_212 = (struct V_193 * ) V_191 ;
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned char V_32 , V_242 ;
T_1 * V_3 ;
int V_196 = 0 ;
memset ( V_212 , 0 , sizeof( * V_212 ) ) ;
F_70 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_241 != 0 ) {
if ( V_2 -> V_26 != V_178 ) {
V_196 = - V_69 ;
goto V_152;
}
V_212 -> V_198 . V_199 = V_200 ;
V_212 -> V_198 . V_204 = V_3 -> V_29 ;
if ( V_3 -> V_33 != NULL ) {
V_32 = V_3 -> V_33 -> V_32 ;
V_212 -> V_198 . V_207 = V_32 ;
for ( V_242 = 0 ; V_242 < V_32 ; V_242 ++ )
V_212 -> V_208 [ V_242 ] =
V_3 -> V_33 -> V_67 [ V_242 ] ;
}
} else {
V_212 -> V_198 . V_199 = V_200 ;
V_212 -> V_198 . V_204 = V_3 -> V_24 ;
V_212 -> V_198 . V_207 = 1 ;
if ( V_3 -> T_2 != NULL ) {
memcpy ( & V_212 -> V_208 [ 0 ] ,
V_3 -> T_2 -> V_7 -> V_243 , V_244 ) ;
} else {
V_212 -> V_208 [ 0 ] = V_209 ;
}
}
* V_240 = sizeof ( struct V_193 ) ;
V_152:
F_73 ( V_2 ) ;
return V_196 ;
}
static int F_122 ( struct V_245 * V_246 , struct V_126 * V_1 ,
struct V_247 * V_248 , T_8 V_249 )
{
F_123 ( struct V_197 * , V_250 , V_248 -> V_251 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_197 V_252 ;
struct V_34 * V_35 ;
T_4 V_253 , * V_254 ;
T_1 * V_3 ;
T_8 V_255 ;
int V_256 , V_196 , V_192 = V_248 -> V_257 ;
if ( V_248 -> V_258 & ~ ( V_259 | V_260 | V_261 ) )
return - V_64 ;
F_70 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
if ( F_103 ( V_2 , V_205 ) ) {
V_196 = - V_144 ;
goto V_152;
}
if ( V_2 -> V_186 & V_187 ) {
F_124 ( V_262 , V_228 , 0 ) ;
V_196 = - V_263 ;
goto V_152;
}
if ( V_3 -> T_2 == NULL ) {
V_196 = - V_10 ;
goto V_152;
}
if ( V_249 > V_3 -> T_2 -> V_7 -> V_264 ) {
V_196 = - V_265 ;
goto V_152;
}
if ( V_250 != NULL ) {
if ( V_250 -> V_199 != V_200 ) {
V_196 = - V_64 ;
goto V_152;
}
if ( V_192 == sizeof( struct V_197 ) )
;
else if ( V_192 != sizeof( struct V_193 ) )
if ( ( V_192 < sizeof( struct V_197 ) + sizeof( T_3 ) * 6 ) ||
( V_192 > sizeof( struct V_193 ) ) ) {
V_196 = - V_64 ;
goto V_152;
}
if ( V_192 > sizeof( struct V_197 ) && V_250 -> V_207 != 0 ) {
int V_213 = 0 ;
struct V_193 * V_212 = (struct V_193 * ) V_250 ;
if ( V_250 -> V_207 < 1 || V_250 -> V_207 > V_63 ) {
V_196 = - V_64 ;
goto V_152;
}
V_253 . V_32 = V_250 -> V_207 ;
while ( V_213 < V_250 -> V_207 ) {
V_253 . V_226 [ V_213 ] = 0 ;
V_253 . V_67 [ V_213 ] = V_212 -> V_208 [ V_213 ] ;
V_213 ++ ;
}
V_253 . V_223 = 0 ;
}
V_252 = * V_250 ;
if ( V_2 -> V_25 == V_31 &&
F_25 ( & V_3 -> V_29 , & V_252 . V_204 ) ) {
V_196 = - V_220 ;
goto V_152;
}
if ( V_250 -> V_207 == 0 )
V_254 = NULL ;
else
V_254 = & V_253 ;
} else {
if ( V_2 -> V_26 != V_178 ) {
V_196 = - V_69 ;
goto V_152;
}
V_252 . V_199 = V_200 ;
V_252 . V_204 = V_3 -> V_29 ;
V_254 = V_3 -> V_33 ;
}
V_255 = V_249 + V_3 -> T_2 -> V_7 -> V_266 ;
V_35 = F_125 ( V_2 , V_255 , V_248 -> V_258 & V_259 , & V_196 ) ;
if ( V_35 == NULL )
goto V_152;
F_126 ( V_35 , V_255 - V_249 ) ;
if ( F_127 ( F_128 ( V_35 , V_249 ) , V_248 , V_249 ) ) {
V_196 = - V_59 ;
F_35 ( V_35 ) ;
goto V_152;
}
F_129 ( V_35 ) ;
if ( ! V_3 -> V_140 )
* F_130 ( V_35 , 1 ) = V_2 -> V_39 ;
if ( V_2 -> V_25 == V_31 ) {
if ( V_2 -> V_26 != V_178 ) {
F_35 ( V_35 ) ;
V_196 = - V_69 ;
goto V_152;
}
F_131 ( V_3 , V_3 -> V_97 , V_35 ) ;
V_196 = V_249 ;
goto V_152;
}
F_130 ( V_35 , 1 + F_132 ( V_254 ) ) ;
V_256 = F_133 ( V_35 -> V_43 , & V_3 -> V_24 , & V_252 . V_204 ,
V_254 , V_72 , V_81 ) ;
F_134 ( V_35 , V_256 ) ;
* F_135 ( V_35 ) = V_267 ;
F_136 ( V_35 , V_3 -> T_2 -> V_7 ) ;
V_196 = V_249 ;
V_152:
F_73 ( V_2 ) ;
return V_196 ;
}
static int F_137 ( struct V_245 * V_246 , struct V_126 * V_1 ,
struct V_247 * V_248 , T_8 V_255 , int V_210 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_34 * V_35 ;
int V_268 ;
int V_196 = 0 ;
F_70 ( V_2 ) ;
if ( V_2 -> V_25 == V_31 && V_2 -> V_26 != V_178 ) {
V_196 = - V_69 ;
goto V_152;
}
V_35 = F_138 ( V_2 , V_210 & ~ V_259 ,
V_210 & V_259 , & V_196 ) ;
if ( V_35 == NULL )
goto V_152;
if ( ! F_3 ( V_2 ) -> V_140 )
F_139 ( V_35 , 1 ) ;
F_140 ( V_35 ) ;
V_268 = V_35 -> V_249 ;
if ( V_268 > V_255 ) {
V_268 = V_255 ;
V_248 -> V_258 |= V_269 ;
}
F_141 ( V_35 , 0 , V_248 , V_268 ) ;
if ( V_248 -> V_251 ) {
T_4 V_22 ;
T_3 V_270 ;
const unsigned char * V_271 = F_142 ( V_35 ) ;
F_123 ( struct V_197 * , V_252 , V_248 -> V_251 ) ;
memset ( V_252 , 0 , sizeof( struct V_193 ) ) ;
F_143 ( V_271 + 1 , V_35 -> V_43 - V_271 - 1 , & V_270 , NULL ,
& V_22 , NULL , NULL ) ;
V_252 -> V_199 = V_200 ;
V_252 -> V_207 = V_22 . V_32 ;
V_252 -> V_204 = V_270 ;
if ( V_252 -> V_207 != 0 ) {
int V_213 ;
struct V_193 * V_212 = (struct V_193 * ) V_252 ;
for ( V_213 = 0 ; V_213 < V_22 . V_32 ; V_213 ++ )
V_212 -> V_208 [ V_213 ] = V_22 . V_67 [ V_213 ] ;
}
V_248 -> V_257 = sizeof( struct V_193 ) ;
}
F_144 ( V_2 , V_35 ) ;
V_196 = V_268 ;
V_152:
F_73 ( V_2 ) ;
return V_196 ;
}
static int F_145 ( struct V_126 * V_2 , int V_272 )
{
return - V_153 ;
}
static int F_146 ( struct V_126 * V_1 , unsigned int V_53 , unsigned long V_54 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
void T_5 * V_273 = ( void T_5 * ) V_54 ;
int V_134 = 0 ;
F_70 ( V_2 ) ;
switch ( V_53 ) {
case V_274 : {
long V_275 ;
V_275 = V_2 -> V_177 - F_147 ( V_2 ) ;
if ( V_275 < 0 )
V_275 = 0 ;
V_134 = F_77 ( V_275 , ( int T_5 * ) V_273 ) ;
break;
}
case V_276 : {
struct V_34 * V_35 ;
long V_275 = 0L ;
if ( ( V_35 = F_148 ( & V_2 -> V_44 ) ) != NULL )
V_275 = V_35 -> V_249 ;
V_134 = F_77 ( V_275 , ( int T_5 * ) V_273 ) ;
break;
}
case V_277 :
V_134 = F_149 ( V_2 , V_273 ) ;
break;
case V_278 :
V_134 = F_150 ( V_2 , V_273 ) ;
break;
case V_279 :
case V_280 :
case V_281 : {
struct V_197 V_45 ;
if ( F_55 ( & V_45 , V_273 , sizeof( V_45 ) ) ) {
V_134 = - V_59 ;
break;
}
V_134 = F_151 ( V_53 , & V_45 ) ;
break;
}
case V_282 : {
long V_275 ;
if ( ! F_102 ( V_202 ) ) {
V_134 = - V_283 ;
break;
}
if ( F_69 ( V_275 , ( long T_5 * ) V_273 ) ) {
V_134 = - V_59 ;
break;
}
if ( V_275 < 0 || V_275 > V_284 ) {
V_134 = - V_64 ;
break;
}
V_201 = V_275 ;
V_134 = 0 ;
break;
}
case V_285 :
case V_286 :
case V_287 :
if ( ! F_102 ( V_202 ) ) {
V_134 = - V_283 ;
break;
}
V_134 = F_152 ( V_53 , V_273 ) ;
break;
case V_288 :
if ( ! F_102 ( V_202 ) ) {
V_134 = - V_283 ;
break;
}
V_134 = F_54 ( V_53 , V_273 ) ;
break;
case V_289 :
case V_290 : {
T_1 * V_3 = F_3 ( V_2 ) ;
struct V_291 V_292 ;
V_292 . V_86 = V_3 -> V_86 / V_52 ;
V_292 . V_88 = V_3 -> V_88 / V_52 ;
V_292 . V_93 = V_3 -> V_93 / V_52 ;
V_292 . V_95 = V_3 -> V_95 / ( 60 * V_52 ) ;
V_292 . V_91 = V_3 -> V_91 ;
V_292 . V_293 = F_153 ( & V_3 -> V_293 ) / V_52 ;
V_292 . V_294 = F_153 ( & V_3 -> V_294 ) / V_52 ;
V_292 . V_295 = F_153 ( & V_3 -> V_295 ) / V_52 ;
V_292 . V_296 = F_153 ( & V_3 -> V_296 ) / ( 60 * V_52 ) ;
V_292 . V_90 = V_3 -> V_90 ;
V_292 . V_46 = V_3 -> V_46 ;
V_292 . V_297 = F_154 ( V_2 ) ;
V_292 . V_298 = F_147 ( V_2 ) ;
V_292 . V_299 = V_3 -> V_299 ;
V_292 . V_300 = V_3 -> V_300 ;
V_292 . V_301 = V_3 -> V_301 ;
V_292 . V_302 = V_3 -> V_299 ;
V_292 . V_97 = V_3 -> V_97 ;
V_292 . V_83 = V_3 -> V_83 ;
if ( V_53 == V_290 ) {
static int V_303 = 0 ;
if ( ! V_303 ) {
F_108 ( V_304 L_2 ,
V_228 -> V_229 ) ;
V_303 = 1 ;
}
if ( F_78 ( V_273 , & V_292 , sizeof( struct V_305 ) ) ) {
V_134 = - V_59 ;
break;
}
} else {
if ( F_78 ( V_273 , & V_292 , sizeof( struct V_291 ) ) ) {
V_134 = - V_64 ;
break;
}
}
V_134 = 0 ;
break;
}
case V_306 :
case V_307 : {
struct V_308 V_309 ;
if ( ! F_102 ( V_202 ) ) {
V_134 = - V_283 ;
break;
}
if ( F_55 ( & V_309 , V_273 , sizeof( V_309 ) ) ) {
V_134 = - V_59 ;
break;
}
V_134 = F_155 ( V_53 , & V_309 ) ;
break;
}
case V_310 :
case V_311 :
case V_312 :
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
V_134 = - V_64 ;
break;
default:
V_134 = - V_320 ;
break;
}
F_73 ( V_2 ) ;
return V_134 ;
}
static void * F_156 ( struct V_321 * V_322 , T_9 * V_323 )
__acquires( V_5 )
{
F_6 ( & V_5 ) ;
return F_157 ( & V_20 , * V_323 ) ;
}
static void * F_158 ( struct V_321 * V_322 , void * V_324 , T_9 * V_323 )
{
return F_159 ( V_324 , & V_20 , V_323 ) ;
}
static void F_160 ( struct V_321 * V_322 , void * V_324 )
__releases( V_5 )
{
F_8 ( & V_5 ) ;
}
static int F_161 ( struct V_321 * V_322 , void * V_324 )
{
T_1 * V_3 = F_162 ( V_324 , struct T_1 , V_4 ) ;
char V_325 [ 11 ] ;
int V_57 ;
F_163 ( V_322 , L_3 ,
( long ) V_3 ,
V_3 -> T_2 == NULL ? L_4 : V_3 -> T_2 -> V_7 -> V_149 ,
F_164 ( V_325 , & V_3 -> V_24 ) ,
V_3 -> V_23 ? L_5 : L_6 ) ;
F_163 ( V_322 , L_7 , F_164 ( V_325 , & V_3 -> V_29 ) ) ;
for ( V_57 = 0 ; ( V_3 -> V_33 != NULL ) && ( V_57 < V_3 -> V_33 -> V_32 ) ; V_57 ++ ) {
F_163 ( V_322 , L_8 ,
F_164 ( V_325 , & V_3 -> V_33 -> V_67 [ V_57 ] ) ,
V_3 -> V_33 -> V_226 [ V_57 ] ? L_5 : L_6 ) ;
}
F_163 ( V_322 , L_9 ,
V_3 -> V_46 ,
V_3 -> V_299 , V_3 -> V_300 , V_3 -> V_301 ,
F_153 ( & V_3 -> V_293 ) / V_52 , V_3 -> V_86 / V_52 ,
F_153 ( & V_3 -> V_294 ) / V_52 , V_3 -> V_88 / V_52 ,
F_153 ( & V_3 -> V_295 ) / V_52 , V_3 -> V_93 / V_52 ,
F_153 ( & V_3 -> V_296 ) / ( 60 * V_52 ) ,
V_3 -> V_95 / ( 60 * V_52 ) ,
V_3 -> V_90 , V_3 -> V_91 ,
V_3 -> V_85 / V_52 ,
V_3 -> V_83 ,
V_3 -> V_97 ) ;
if ( V_3 -> V_2 != NULL ) {
F_163 ( V_322 , L_10 ,
F_147 ( V_3 -> V_2 ) ,
F_154 ( V_3 -> V_2 ) ,
F_165 ( V_3 -> V_2 ) ) ;
} else {
F_166 ( V_322 , L_11 ) ;
}
return 0 ;
}
static int F_167 ( struct V_326 * V_326 , struct V_327 * V_327 )
{
return F_168 ( V_327 , & V_328 ) ;
}
static int T_10 F_169 ( void )
{
int V_329 = F_170 ( & V_167 , 0 ) ;
if ( V_329 != 0 )
goto V_152;
F_171 ( & V_330 ) ;
F_172 ( & V_331 ) ;
F_173 ( & V_332 ) ;
F_174 ( L_12 , V_333 , V_15 . V_334 ,
& V_335 ) ;
F_174 ( L_13 , V_333 , V_15 . V_334 , & V_336 ) ;
F_174 ( L_14 , V_333 , V_15 . V_334 , & V_337 ) ;
V_152:
return V_329 ;
}
static void T_11 F_175 ( void )
{
F_176 ( L_12 , V_15 . V_334 ) ;
F_176 ( L_13 , V_15 . V_334 ) ;
F_176 ( L_14 , V_15 . V_334 ) ;
F_177 ( & V_332 ) ;
F_178 ( & V_331 ) ;
F_179 ( V_159 ) ;
F_180 ( & V_167 ) ;
F_181 () ;
F_182 () ;
F_183 () ;
}
