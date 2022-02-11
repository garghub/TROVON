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
struct V_9 * V_10 ;
if ( ( T_2 = F_10 ( V_7 ) ) == NULL )
return;
F_6 ( & V_5 ) ;
V_11:
F_11 (s, node, &ax25_list) {
if ( V_8 -> T_2 == T_2 ) {
V_8 -> T_2 = NULL ;
F_8 ( & V_5 ) ;
F_12 ( V_8 , V_12 ) ;
F_6 ( & V_5 ) ;
goto V_11;
}
}
F_8 ( & V_5 ) ;
}
static int F_13 ( struct V_13 * V_14 , unsigned long V_15 ,
void * V_16 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 ;
if ( ! F_14 ( F_15 ( V_7 ) , & V_17 ) )
return V_18 ;
if ( V_7 -> type != V_19 )
return V_18 ;
switch ( V_15 ) {
case V_20 :
F_16 ( V_7 ) ;
break;
case V_21 :
F_9 ( V_7 ) ;
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
break;
default:
break;
}
return V_18 ;
}
void F_19 ( T_1 * V_3 )
{
F_6 ( & V_5 ) ;
F_20 ( V_3 ) ;
F_21 ( & V_3 -> V_4 , & V_22 ) ;
F_8 ( & V_5 ) ;
}
struct V_1 * F_22 ( T_3 * V_23 , int V_24 ,
struct V_6 * V_7 , int type )
{
T_1 * V_8 ;
struct V_9 * V_10 ;
F_23 ( & V_5 ) ;
F_11 (s, node, &ax25_list) {
if ( ( V_8 -> V_25 && ! V_24 ) || ( ! V_8 -> V_25 && V_24 ) )
continue;
if ( V_8 -> V_2 && ! F_24 ( & V_8 -> V_26 , V_23 ) &&
V_8 -> V_2 -> V_27 == type && V_8 -> V_2 -> V_28 == V_29 ) {
if ( V_8 -> T_2 == NULL || V_8 -> T_2 -> V_7 == V_7 ) {
F_25 ( V_8 -> V_2 ) ;
F_26 ( & V_5 ) ;
return V_8 -> V_2 ;
}
}
}
F_26 ( & V_5 ) ;
return NULL ;
}
struct V_1 * F_27 ( T_3 * V_30 , T_3 * V_31 ,
int type )
{
struct V_1 * V_2 = NULL ;
T_1 * V_8 ;
struct V_9 * V_10 ;
F_23 ( & V_5 ) ;
F_11 (s, node, &ax25_list) {
if ( V_8 -> V_2 && ! F_24 ( & V_8 -> V_26 , V_30 ) &&
! F_24 ( & V_8 -> V_31 , V_31 ) &&
V_8 -> V_2 -> V_27 == type ) {
V_2 = V_8 -> V_2 ;
F_25 ( V_2 ) ;
break;
}
}
F_26 ( & V_5 ) ;
return V_2 ;
}
T_1 * F_28 ( T_3 * V_32 , T_3 * V_31 ,
T_4 * V_24 , struct V_6 * V_7 )
{
T_1 * V_8 ;
struct V_9 * V_10 ;
F_6 ( & V_5 ) ;
F_11 (s, node, &ax25_list) {
if ( V_8 -> V_2 && V_8 -> V_2 -> V_27 != V_33 )
continue;
if ( V_8 -> T_2 == NULL )
continue;
if ( F_24 ( & V_8 -> V_26 , V_32 ) == 0 && F_24 ( & V_8 -> V_31 , V_31 ) == 0 && V_8 -> T_2 -> V_7 == V_7 ) {
if ( V_24 != NULL && V_24 -> V_34 != 0 ) {
if ( V_8 -> V_35 == NULL )
continue;
if ( F_29 ( V_8 -> V_35 , V_24 ) != 0 )
continue;
} else {
if ( V_8 -> V_35 != NULL && V_8 -> V_35 -> V_34 != 0 )
continue;
}
F_20 ( V_8 ) ;
F_8 ( & V_5 ) ;
return V_8 ;
}
}
F_8 ( & V_5 ) ;
return NULL ;
}
void F_30 ( T_3 * V_23 , struct V_36 * V_37 , int V_38 )
{
T_1 * V_8 ;
struct V_36 * V_39 ;
struct V_9 * V_10 ;
F_23 ( & V_5 ) ;
F_11 (s, node, &ax25_list) {
if ( V_8 -> V_2 != NULL && F_24 ( & V_8 -> V_26 , V_23 ) == 0 &&
V_8 -> V_2 -> V_27 == V_40 &&
V_8 -> V_2 -> V_41 == V_38 &&
V_8 -> T_2 -> V_7 == V_37 -> V_7 &&
F_31 ( & V_8 -> V_2 -> V_42 ) <= V_8 -> V_2 -> V_43 ) {
if ( ( V_39 = F_32 ( V_37 , V_44 ) ) == NULL )
continue;
if ( F_33 ( V_8 -> V_2 , V_39 ) != 0 )
F_34 ( V_39 ) ;
}
}
F_26 ( & V_5 ) ;
}
static void F_35 ( unsigned long V_45 )
{
T_1 * V_3 = ( T_1 * ) V_45 ;
struct V_1 * V_2 ;
V_2 = V_3 -> V_2 ;
F_36 ( V_2 ) ;
F_25 ( V_2 ) ;
F_37 ( V_3 ) ;
F_38 ( V_2 ) ;
F_39 ( V_2 ) ;
}
void F_37 ( T_1 * V_3 )
{
struct V_36 * V_37 ;
F_4 ( V_3 ) ;
F_40 ( V_3 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
F_45 ( V_3 ) ;
if ( V_3 -> V_2 != NULL ) {
while ( ( V_37 = F_46 ( & V_3 -> V_2 -> V_46 ) ) != NULL ) {
if ( V_37 -> V_2 != V_3 -> V_2 ) {
T_1 * V_47 = F_3 ( V_37 -> V_2 ) ;
F_47 ( V_37 -> V_2 ) ;
V_37 -> V_2 -> V_28 = V_29 ;
F_48 ( V_47 ) ;
V_47 -> V_48 = V_49 ;
}
F_34 ( V_37 ) ;
}
F_49 ( & V_3 -> V_2 -> V_50 ) ;
}
if ( V_3 -> V_2 != NULL ) {
if ( F_50 ( V_3 -> V_2 ) ) {
F_51 ( & V_3 -> V_51 , F_35 ,
( unsigned long ) V_3 ) ;
V_3 -> V_51 . V_52 = V_53 + 2 * V_54 ;
F_52 ( & V_3 -> V_51 ) ;
} else {
struct V_1 * V_2 = V_3 -> V_2 ;
V_3 -> V_2 = NULL ;
F_39 ( V_2 ) ;
}
} else {
F_2 ( V_3 ) ;
}
}
static int F_53 ( const unsigned int V_55 , void T_5 * V_56 )
{
struct V_57 V_58 ;
T_4 V_24 ;
T_2 * T_2 ;
T_1 * V_3 ;
unsigned int V_59 ;
int V_60 = 0 ;
if ( F_54 ( & V_58 , V_56 , sizeof( V_58 ) ) )
return - V_61 ;
if ( ( T_2 = F_55 ( & V_58 . V_62 ) ) == NULL )
return - V_63 ;
if ( V_58 . V_64 > V_65 )
return - V_66 ;
if ( V_58 . V_56 > V_67 / V_54 && V_58 . V_55 != V_68 )
return - V_66 ;
V_24 . V_34 = V_58 . V_64 ;
for ( V_59 = 0 ; V_59 < V_24 . V_34 ; V_59 ++ )
V_24 . V_69 [ V_59 ] = V_58 . V_70 [ V_59 ] ;
if ( ( V_3 = F_28 ( & V_58 . V_26 , & V_58 . V_31 , & V_24 , T_2 -> V_7 ) ) == NULL )
return - V_71 ;
switch ( V_58 . V_55 ) {
case V_68 :
F_56 ( V_3 , V_72 , V_73 , V_74 ) ;
#ifdef F_57
if ( T_2 -> V_75 . V_76 && V_3 -> T_2 -> V_77 [ V_78 ] == V_79 )
F_58 ( V_3 ) ;
#endif
F_12 ( V_3 , V_80 ) ;
break;
case V_81 :
if ( V_3 -> V_82 == V_83 ) {
if ( V_58 . V_56 < 1 || V_58 . V_56 > 7 )
goto V_84;
} else {
if ( V_58 . V_56 < 1 || V_58 . V_56 > 63 )
goto V_84;
}
V_3 -> V_85 = V_58 . V_56 ;
break;
case V_86 :
if ( V_58 . V_56 < 1 || V_58 . V_56 > V_67 / V_54 )
goto V_84;
V_3 -> V_87 = ( V_58 . V_56 * V_54 ) / 2 ;
V_3 -> V_88 = V_58 . V_56 * V_54 ;
break;
case V_89 :
if ( V_58 . V_56 < 1 || V_58 . V_56 > V_67 / V_54 )
goto V_84;
V_3 -> V_90 = V_58 . V_56 * V_54 ;
break;
case V_91 :
if ( V_58 . V_56 < 1 || V_58 . V_56 > 31 )
goto V_84;
V_3 -> V_92 = 0 ;
V_3 -> V_93 = V_58 . V_56 ;
break;
case V_94 :
if ( V_58 . V_56 > V_67 / V_54 )
goto V_84;
V_3 -> V_95 = V_58 . V_56 * V_54 ;
break;
case V_96 :
if ( V_58 . V_56 > V_67 / ( 60 * V_54 ) )
goto V_84;
V_3 -> V_97 = V_58 . V_56 * 60 * V_54 ;
break;
case V_98 :
if ( V_58 . V_56 < 16 || V_58 . V_56 > 65535 )
goto V_84;
V_3 -> V_99 = V_58 . V_56 ;
break;
default:
goto V_84;
}
V_100:
F_2 ( V_3 ) ;
return V_60 ;
V_84:
V_60 = - V_66 ;
goto V_100;
}
static void F_59 ( T_1 * V_3 , T_2 * T_2 )
{
V_3 -> V_87 = F_60 ( T_2 -> V_77 [ V_101 ] ) / 2 ;
V_3 -> V_88 = F_60 ( T_2 -> V_77 [ V_101 ] ) ;
V_3 -> V_90 = F_60 ( T_2 -> V_77 [ V_102 ] ) ;
V_3 -> V_95 = F_60 ( T_2 -> V_77 [ V_103 ] ) ;
V_3 -> V_93 = T_2 -> V_77 [ V_104 ] ;
V_3 -> V_99 = T_2 -> V_77 [ V_105 ] ;
V_3 -> V_97 = F_60 ( T_2 -> V_77 [ V_106 ] ) ;
V_3 -> V_107 = T_2 -> V_77 [ V_108 ] ;
if ( T_2 -> V_77 [ V_109 ] ) {
V_3 -> V_82 = V_110 ;
V_3 -> V_85 = T_2 -> V_77 [ V_111 ] ;
} else {
V_3 -> V_82 = V_83 ;
V_3 -> V_85 = T_2 -> V_77 [ V_112 ] ;
}
}
void F_61 ( T_1 * V_3 , T_2 * T_2 )
{
V_3 -> T_2 = T_2 ;
if ( V_3 -> T_2 != NULL ) {
F_59 ( V_3 , T_2 ) ;
return;
}
V_3 -> V_87 = F_60 ( V_113 ) / 2 ;
V_3 -> V_88 = F_60 ( V_113 ) ;
V_3 -> V_90 = F_60 ( V_114 ) ;
V_3 -> V_95 = F_60 ( V_115 ) ;
V_3 -> V_93 = V_116 ;
V_3 -> V_99 = V_117 ;
V_3 -> V_97 = F_60 ( V_118 ) ;
V_3 -> V_107 = V_119 ;
if ( V_120 ) {
V_3 -> V_82 = V_110 ;
V_3 -> V_85 = V_121 ;
} else {
V_3 -> V_82 = V_83 ;
V_3 -> V_85 = V_122 ;
}
}
T_1 * F_62 ( void )
{
T_1 * V_3 ;
if ( ( V_3 = F_63 ( sizeof( * V_3 ) , V_44 ) ) == NULL )
return NULL ;
F_64 ( & V_3 -> V_123 , 1 ) ;
F_65 ( & V_3 -> V_124 ) ;
F_65 ( & V_3 -> V_125 ) ;
F_65 ( & V_3 -> V_126 ) ;
F_65 ( & V_3 -> V_127 ) ;
F_66 ( V_3 ) ;
F_61 ( V_3 , NULL ) ;
V_3 -> V_48 = V_49 ;
return V_3 ;
}
static int F_67 ( struct V_128 * V_1 , int V_129 , int V_130 ,
char T_5 * V_131 , unsigned int V_132 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
T_1 * V_3 ;
struct V_6 * V_7 ;
char V_133 [ V_134 ] ;
unsigned long V_135 ;
int V_136 = 0 ;
if ( V_129 != V_137 )
return - V_138 ;
if ( V_132 < sizeof( unsigned int ) )
return - V_66 ;
if ( F_68 ( V_135 , ( unsigned int T_5 * ) V_131 ) )
return - V_61 ;
F_69 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
switch ( V_130 ) {
case V_81 :
if ( V_3 -> V_82 == V_83 ) {
if ( V_135 < 1 || V_135 > 7 ) {
V_136 = - V_66 ;
break;
}
} else {
if ( V_135 < 1 || V_135 > 63 ) {
V_136 = - V_66 ;
break;
}
}
V_3 -> V_85 = V_135 ;
break;
case V_86 :
if ( V_135 < 1 || V_135 > V_67 / V_54 ) {
V_136 = - V_66 ;
break;
}
V_3 -> V_87 = ( V_135 * V_54 ) >> 1 ;
V_3 -> V_88 = V_135 * V_54 ;
break;
case V_89 :
if ( V_135 < 1 || V_135 > V_67 / V_54 ) {
V_136 = - V_66 ;
break;
}
V_3 -> V_90 = V_135 * V_54 ;
break;
case V_91 :
if ( V_135 < 1 || V_135 > 31 ) {
V_136 = - V_66 ;
break;
}
V_3 -> V_93 = V_135 ;
break;
case V_94 :
if ( V_135 < 1 || V_135 > V_67 / V_54 ) {
V_136 = - V_66 ;
break;
}
V_3 -> V_95 = V_135 * V_54 ;
break;
case V_96 :
if ( V_135 > V_67 / ( 60 * V_54 ) ) {
V_136 = - V_66 ;
break;
}
V_3 -> V_97 = V_135 * 60 * V_54 ;
break;
case V_139 :
if ( V_135 > 2 ) {
V_136 = - V_66 ;
break;
}
V_3 -> V_107 = V_135 ;
break;
case V_140 :
V_3 -> V_82 = V_135 ? V_110 : V_83 ;
break;
case V_141 :
V_3 -> V_142 = V_135 ? 1 : 0 ;
break;
case V_143 :
V_3 -> V_25 = V_135 ? 1 : 0 ;
break;
case V_98 :
if ( V_135 < 16 || V_135 > 65535 ) {
V_136 = - V_66 ;
break;
}
V_3 -> V_99 = V_135 ;
break;
case V_144 :
if ( V_132 > V_134 )
V_132 = V_134 ;
if ( F_54 ( V_133 , V_131 , V_132 ) ) {
V_136 = - V_61 ;
break;
}
if ( V_2 -> V_27 == V_33 &&
( V_1 -> V_48 != V_145 ||
V_2 -> V_28 == V_29 ) ) {
V_136 = - V_146 ;
break;
}
V_7 = F_70 ( & V_17 , V_133 ) ;
if ( ! V_7 ) {
V_136 = - V_63 ;
break;
}
V_3 -> T_2 = F_10 ( V_7 ) ;
F_61 ( V_3 , V_3 -> T_2 ) ;
F_71 ( V_7 ) ;
break;
default:
V_136 = - V_138 ;
}
F_72 ( V_2 ) ;
return V_136 ;
}
static int F_73 ( struct V_128 * V_1 , int V_129 , int V_130 ,
char T_5 * V_131 , int T_5 * V_132 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
T_1 * V_3 ;
struct T_2 * T_2 ;
char V_133 [ V_134 ] ;
void * V_147 ;
int V_148 = 0 ;
int V_149 , V_150 ;
if ( V_129 != V_137 )
return - V_138 ;
if ( F_68 ( V_149 , V_132 ) )
return - V_61 ;
if ( V_149 < 1 )
return - V_61 ;
V_147 = ( void * ) & V_148 ;
V_150 = F_74 (unsigned int, maxlen, sizeof(int)) ;
F_69 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
switch ( V_130 ) {
case V_81 :
V_148 = V_3 -> V_85 ;
break;
case V_86 :
V_148 = V_3 -> V_88 / V_54 ;
break;
case V_89 :
V_148 = V_3 -> V_90 / V_54 ;
break;
case V_91 :
V_148 = V_3 -> V_93 ;
break;
case V_94 :
V_148 = V_3 -> V_95 / V_54 ;
break;
case V_96 :
V_148 = V_3 -> V_97 / ( 60 * V_54 ) ;
break;
case V_139 :
V_148 = V_3 -> V_107 ;
break;
case V_140 :
V_148 = ( V_3 -> V_82 == V_110 ) ;
break;
case V_141 :
V_148 = V_3 -> V_142 ;
break;
case V_143 :
V_148 = V_3 -> V_25 ;
break;
case V_98 :
V_148 = V_3 -> V_99 ;
break;
case V_144 :
T_2 = V_3 -> T_2 ;
if ( T_2 != NULL && T_2 -> V_7 != NULL ) {
F_75 ( V_133 , T_2 -> V_7 -> V_151 , sizeof( V_133 ) ) ;
V_150 = strlen ( V_133 ) + 1 ;
} else {
* V_133 = '\0' ;
V_150 = 1 ;
}
V_147 = ( void * ) V_133 ;
break;
default:
F_72 ( V_2 ) ;
return - V_138 ;
}
F_72 ( V_2 ) ;
if ( F_76 ( V_150 , V_132 ) )
return - V_61 ;
return F_77 ( V_131 , V_147 , V_150 ) ? - V_61 : 0 ;
}
static int F_78 ( struct V_128 * V_1 , int V_152 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
int V_136 = 0 ;
F_69 ( V_2 ) ;
if ( V_2 -> V_27 == V_33 && V_2 -> V_28 != V_29 ) {
V_2 -> V_153 = V_152 ;
V_2 -> V_28 = V_29 ;
goto V_154;
}
V_136 = - V_155 ;
V_154:
F_72 ( V_2 ) ;
return V_136 ;
}
static int F_79 ( struct V_156 * V_156 , struct V_128 * V_1 , int V_157 ,
int V_158 )
{
struct V_1 * V_2 ;
T_1 * V_3 ;
if ( ! F_14 ( V_156 , & V_17 ) )
return - V_159 ;
switch ( V_1 -> type ) {
case V_160 :
if ( V_157 == 0 || V_157 == V_161 )
V_157 = V_162 ;
break;
case V_33 :
switch ( V_157 ) {
case 0 :
case V_161 :
V_157 = V_162 ;
break;
case V_163 :
#ifdef F_80
case V_164 :
case V_165 :
#endif
#ifdef F_81
case V_166 :
#endif
#ifdef F_82
case V_167 :
#endif
return - V_168 ;
#ifdef F_83
case V_166 :
if ( F_84 ( V_166 ) )
return - V_168 ;
#endif
#ifdef F_85
case V_167 :
if ( F_84 ( V_167 ) )
return - V_168 ;
#endif
default:
break;
}
break;
case V_40 :
break;
default:
return - V_168 ;
}
V_2 = F_86 ( V_156 , V_161 , V_44 , & V_169 ) ;
if ( V_2 == NULL )
return - V_170 ;
V_3 = V_2 -> V_171 = F_62 () ;
if ( ! V_3 ) {
F_87 ( V_2 ) ;
return - V_170 ;
}
F_88 ( V_1 , V_2 ) ;
V_2 -> V_172 = F_1 ;
V_1 -> V_173 = & V_174 ;
V_2 -> V_41 = V_157 ;
V_3 -> V_2 = V_2 ;
return 0 ;
}
struct V_1 * F_89 ( struct V_1 * V_175 , struct T_2 * T_2 )
{
struct V_1 * V_2 ;
T_1 * V_3 , * V_176 ;
V_2 = F_86 ( F_90 ( V_175 ) , V_161 , V_44 , V_175 -> V_177 ) ;
if ( V_2 == NULL )
return NULL ;
if ( ( V_3 = F_62 () ) == NULL ) {
F_87 ( V_2 ) ;
return NULL ;
}
switch ( V_175 -> V_27 ) {
case V_160 :
break;
case V_33 :
break;
default:
F_87 ( V_2 ) ;
F_2 ( V_3 ) ;
return NULL ;
}
F_88 ( NULL , V_2 ) ;
V_2 -> V_27 = V_175 -> V_27 ;
V_2 -> V_178 = V_175 -> V_178 ;
V_2 -> V_41 = V_175 -> V_41 ;
V_2 -> V_43 = V_175 -> V_43 ;
V_2 -> V_179 = V_175 -> V_179 ;
V_2 -> V_28 = V_180 ;
F_91 ( V_2 , V_175 ) ;
V_176 = F_3 ( V_175 ) ;
V_3 -> V_82 = V_176 -> V_82 ;
V_3 -> V_107 = V_176 -> V_107 ;
V_3 -> V_142 = V_176 -> V_142 ;
V_3 -> V_25 = V_176 -> V_25 ;
V_3 -> V_87 = V_176 -> V_87 ;
V_3 -> V_88 = V_176 -> V_88 ;
V_3 -> V_90 = V_176 -> V_90 ;
V_3 -> V_95 = V_176 -> V_95 ;
V_3 -> V_93 = V_176 -> V_93 ;
V_3 -> V_97 = V_176 -> V_97 ;
V_3 -> V_99 = V_176 -> V_99 ;
V_3 -> V_85 = V_176 -> V_85 ;
V_3 -> T_2 = T_2 ;
V_3 -> V_26 = V_176 -> V_26 ;
if ( V_176 -> V_35 != NULL ) {
V_3 -> V_35 = F_92 ( V_176 -> V_35 , sizeof( T_4 ) ,
V_44 ) ;
if ( V_3 -> V_35 == NULL ) {
F_87 ( V_2 ) ;
F_2 ( V_3 ) ;
return NULL ;
}
}
V_2 -> V_171 = V_3 ;
V_2 -> V_172 = F_1 ;
V_3 -> V_2 = V_2 ;
return V_2 ;
}
static int F_93 ( struct V_128 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
T_1 * V_3 ;
if ( V_2 == NULL )
return 0 ;
F_25 ( V_2 ) ;
F_47 ( V_2 ) ;
F_69 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_2 -> V_27 == V_33 ) {
switch ( V_3 -> V_48 ) {
case V_49 :
F_72 ( V_2 ) ;
F_12 ( V_3 , 0 ) ;
F_69 ( V_2 ) ;
F_37 ( V_3 ) ;
break;
case V_181 :
case V_182 :
F_56 ( V_3 , V_72 , V_73 , V_74 ) ;
F_72 ( V_2 ) ;
F_12 ( V_3 , 0 ) ;
F_69 ( V_2 ) ;
F_37 ( V_3 ) ;
break;
case V_183 :
case V_184 :
F_45 ( V_3 ) ;
V_3 -> V_92 = 0 ;
switch ( V_3 -> T_2 -> V_77 [ V_78 ] ) {
case V_185 :
case V_186 :
F_56 ( V_3 ,
V_72 ,
V_73 ,
V_74 ) ;
F_42 ( V_3 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
break;
#ifdef F_57
case V_79 :
F_43 ( V_3 ) ;
F_44 ( V_3 ) ;
break;
#endif
}
F_94 ( V_3 ) ;
F_95 ( V_3 ) ;
V_3 -> V_48 = V_182 ;
V_2 -> V_28 = V_187 ;
V_2 -> V_188 |= V_189 ;
V_2 -> V_190 ( V_2 ) ;
F_96 ( V_2 , V_191 ) ;
break;
default:
break;
}
} else {
V_2 -> V_28 = V_187 ;
V_2 -> V_188 |= V_189 ;
V_2 -> V_190 ( V_2 ) ;
F_37 ( V_3 ) ;
}
V_1 -> V_2 = NULL ;
F_72 ( V_2 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_128 * V_1 , struct V_192 * V_193 , int V_194 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_195 * V_23 = (struct V_195 * ) V_193 ;
T_2 * T_2 = NULL ;
T_6 * V_196 ;
T_3 V_197 ;
T_1 * V_3 ;
int V_198 = 0 ;
if ( V_194 != sizeof( struct V_199 ) &&
V_194 != sizeof( struct V_195 ) )
if ( ( V_194 < sizeof( struct V_199 ) + sizeof( T_3 ) * 6 ) ||
( V_194 > sizeof( struct V_195 ) ) )
return - V_66 ;
if ( V_23 -> V_200 . V_201 != V_202 )
return - V_66 ;
V_196 = F_98 ( F_99 () ) ;
if ( V_196 ) {
V_197 = V_196 -> V_197 ;
F_100 ( V_196 ) ;
} else {
if ( V_203 && ! F_101 ( V_204 ) )
return - V_205 ;
V_197 = V_23 -> V_200 . V_206 ;
}
F_69 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
if ( ! F_102 ( V_2 , V_207 ) ) {
V_198 = - V_66 ;
goto V_154;
}
V_3 -> V_26 = V_197 ;
if ( V_3 -> T_2 != NULL )
goto V_208;
if ( V_194 > sizeof( struct V_199 ) && V_23 -> V_200 . V_209 == 1 ) {
if ( F_24 ( & V_23 -> V_210 [ 0 ] , & V_211 ) != 0 &&
( T_2 = F_55 ( & V_23 -> V_210 [ 0 ] ) ) == NULL ) {
V_198 = - V_146 ;
goto V_154;
}
} else {
if ( ( T_2 = F_55 ( & V_23 -> V_200 . V_206 ) ) == NULL ) {
V_198 = - V_146 ;
goto V_154;
}
}
if ( T_2 != NULL )
F_61 ( V_3 , T_2 ) ;
V_208:
F_19 ( V_3 ) ;
F_103 ( V_2 , V_207 ) ;
V_154:
F_72 ( V_2 ) ;
return V_198 ;
}
static int T_7 F_104 ( struct V_128 * V_1 ,
struct V_192 * V_193 , int V_194 , int V_212 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
T_1 * V_3 = F_3 ( V_2 ) , * V_213 ;
struct V_195 * V_214 = (struct V_195 * ) V_193 ;
T_4 * V_24 = NULL ;
int V_215 = 0 , V_198 = 0 ;
if ( V_194 == sizeof( struct V_199 ) )
;
else if ( V_194 != sizeof( struct V_195 ) )
if ( ( V_194 < sizeof( struct V_199 ) + sizeof( T_3 ) * 6 ) ||
( V_194 > sizeof( struct V_195 ) ) )
return - V_66 ;
if ( V_214 -> V_200 . V_201 != V_202 )
return - V_66 ;
F_69 ( V_2 ) ;
if ( V_1 -> V_48 == V_216 ) {
switch ( V_2 -> V_28 ) {
case V_217 :
V_198 = - V_218 ;
goto V_219;
case V_180 :
V_1 -> V_48 = V_220 ;
goto V_219;
case V_187 :
V_1 -> V_48 = V_145 ;
V_198 = - V_221 ;
goto V_219;
}
}
if ( V_2 -> V_28 == V_180 && V_2 -> V_27 == V_33 ) {
V_198 = - V_222 ;
goto V_219;
}
V_2 -> V_28 = V_187 ;
V_1 -> V_48 = V_145 ;
F_105 ( V_3 -> V_35 ) ;
V_3 -> V_35 = NULL ;
if ( V_194 > sizeof( struct V_199 ) &&
V_214 -> V_200 . V_209 != 0 ) {
if ( V_214 -> V_200 . V_209 < 1 || V_214 -> V_200 . V_209 > V_65 ) {
V_198 = - V_66 ;
goto V_219;
}
if ( ( V_24 = F_106 ( sizeof( T_4 ) , V_223 ) ) == NULL ) {
V_198 = - V_224 ;
goto V_219;
}
V_24 -> V_34 = V_214 -> V_200 . V_209 ;
V_24 -> V_225 = - 1 ;
while ( V_215 < V_214 -> V_200 . V_209 ) {
if ( ( V_214 -> V_210 [ V_215 ] . V_226 [ 6 ] &
V_227 ) && V_3 -> V_25 ) {
V_24 -> V_228 [ V_215 ] = 1 ;
V_24 -> V_225 = V_215 ;
} else {
V_24 -> V_228 [ V_215 ] = 0 ;
}
V_24 -> V_69 [ V_215 ] = V_214 -> V_210 [ V_215 ] ;
V_215 ++ ;
}
}
if ( F_102 ( V_2 , V_207 ) ) {
F_107 ( V_229 L_1 ,
V_230 -> V_231 ) ;
if ( ( V_198 = F_108 ( V_3 , & V_214 -> V_200 . V_206 ) ) < 0 ) {
F_105 ( V_24 ) ;
goto V_219;
}
F_61 ( V_3 , V_3 -> T_2 ) ;
F_19 ( V_3 ) ;
} else {
if ( V_3 -> T_2 == NULL ) {
F_105 ( V_24 ) ;
V_198 = - V_232 ;
goto V_219;
}
}
if ( V_2 -> V_27 == V_33 &&
( V_213 = F_28 ( & V_3 -> V_26 , & V_214 -> V_200 . V_206 , V_24 ,
V_3 -> T_2 -> V_7 ) ) ) {
F_105 ( V_24 ) ;
V_198 = - V_233 ;
F_2 ( V_213 ) ;
goto V_219;
}
V_3 -> V_31 = V_214 -> V_200 . V_206 ;
V_3 -> V_35 = V_24 ;
if ( V_2 -> V_27 != V_33 ) {
V_1 -> V_48 = V_220 ;
V_2 -> V_28 = V_180 ;
goto V_219;
}
V_1 -> V_48 = V_216 ;
V_2 -> V_28 = V_217 ;
switch ( V_3 -> T_2 -> V_77 [ V_78 ] ) {
case V_185 :
case V_186 :
F_109 ( V_3 ) ;
break;
#ifdef F_57
case V_79 :
V_3 -> V_82 = V_83 ;
V_3 -> V_85 = V_3 -> T_2 -> V_77 [ V_112 ] ;
if ( V_3 -> T_2 -> V_75 . V_76 )
F_110 ( V_3 ) ;
else
F_109 ( V_3 ) ;
break;
#endif
}
V_3 -> V_48 = V_181 ;
F_48 ( V_3 ) ;
if ( V_2 -> V_28 != V_180 && ( V_212 & V_234 ) ) {
V_198 = - V_218 ;
goto V_219;
}
if ( V_2 -> V_28 == V_217 ) {
F_111 ( V_235 ) ;
for (; ; ) {
F_112 ( F_113 ( V_2 ) , & V_235 ,
V_236 ) ;
if ( V_2 -> V_28 != V_217 )
break;
if ( ! F_114 ( V_230 ) ) {
F_72 ( V_2 ) ;
F_115 () ;
F_69 ( V_2 ) ;
continue;
}
V_198 = - V_237 ;
break;
}
F_116 ( F_113 ( V_2 ) , & V_235 ) ;
if ( V_198 )
goto V_219;
}
if ( V_2 -> V_28 != V_180 ) {
V_1 -> V_48 = V_145 ;
V_198 = F_117 ( V_2 ) ;
goto V_219;
}
V_1 -> V_48 = V_220 ;
V_198 = 0 ;
V_219:
F_72 ( V_2 ) ;
return V_198 ;
}
static int F_118 ( struct V_128 * V_1 , struct V_128 * V_238 , int V_212 )
{
struct V_36 * V_37 ;
struct V_1 * V_239 ;
F_111 ( V_235 ) ;
struct V_1 * V_2 ;
int V_198 = 0 ;
if ( V_1 -> V_48 != V_145 )
return - V_66 ;
if ( ( V_2 = V_1 -> V_2 ) == NULL )
return - V_66 ;
F_69 ( V_2 ) ;
if ( V_2 -> V_27 != V_33 ) {
V_198 = - V_155 ;
goto V_154;
}
if ( V_2 -> V_28 != V_29 ) {
V_198 = - V_66 ;
goto V_154;
}
for (; ; ) {
F_112 ( F_113 ( V_2 ) , & V_235 , V_236 ) ;
V_37 = F_46 ( & V_2 -> V_46 ) ;
if ( V_37 )
break;
if ( V_212 & V_234 ) {
V_198 = - V_240 ;
break;
}
if ( ! F_114 ( V_230 ) ) {
F_72 ( V_2 ) ;
F_115 () ;
F_69 ( V_2 ) ;
continue;
}
V_198 = - V_237 ;
break;
}
F_116 ( F_113 ( V_2 ) , & V_235 ) ;
if ( V_198 )
goto V_154;
V_239 = V_37 -> V_2 ;
F_119 ( V_239 , V_238 ) ;
F_34 ( V_37 ) ;
V_2 -> V_241 -- ;
V_238 -> V_48 = V_220 ;
V_154:
F_72 ( V_2 ) ;
return V_198 ;
}
static int F_120 ( struct V_128 * V_1 , struct V_192 * V_193 ,
int * V_242 , int V_243 )
{
struct V_195 * V_214 = (struct V_195 * ) V_193 ;
struct V_1 * V_2 = V_1 -> V_2 ;
unsigned char V_34 , V_244 ;
T_1 * V_3 ;
int V_198 = 0 ;
memset ( V_214 , 0 , sizeof( * V_214 ) ) ;
F_69 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_243 != 0 ) {
if ( V_2 -> V_28 != V_180 ) {
V_198 = - V_71 ;
goto V_154;
}
V_214 -> V_200 . V_201 = V_202 ;
V_214 -> V_200 . V_206 = V_3 -> V_31 ;
if ( V_3 -> V_35 != NULL ) {
V_34 = V_3 -> V_35 -> V_34 ;
V_214 -> V_200 . V_209 = V_34 ;
for ( V_244 = 0 ; V_244 < V_34 ; V_244 ++ )
V_214 -> V_210 [ V_244 ] =
V_3 -> V_35 -> V_69 [ V_244 ] ;
}
} else {
V_214 -> V_200 . V_201 = V_202 ;
V_214 -> V_200 . V_206 = V_3 -> V_26 ;
V_214 -> V_200 . V_209 = 1 ;
if ( V_3 -> T_2 != NULL ) {
memcpy ( & V_214 -> V_210 [ 0 ] ,
V_3 -> T_2 -> V_7 -> V_245 , V_246 ) ;
} else {
V_214 -> V_210 [ 0 ] = V_211 ;
}
}
* V_242 = sizeof ( struct V_195 ) ;
V_154:
F_72 ( V_2 ) ;
return V_198 ;
}
static int F_121 ( struct V_247 * V_248 , struct V_128 * V_1 ,
struct V_249 * V_250 , T_8 V_251 )
{
struct V_199 * V_252 = (struct V_199 * ) V_250 -> V_253 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_199 V_254 ;
struct V_36 * V_37 ;
T_4 V_255 , * V_256 ;
T_1 * V_3 ;
T_8 V_257 ;
int V_258 , V_198 , V_194 = V_250 -> V_259 ;
if ( V_250 -> V_260 & ~ ( V_261 | V_262 | V_263 ) )
return - V_66 ;
F_69 ( V_2 ) ;
V_3 = F_3 ( V_2 ) ;
if ( F_102 ( V_2 , V_207 ) ) {
V_198 = - V_146 ;
goto V_154;
}
if ( V_2 -> V_188 & V_189 ) {
F_122 ( V_264 , V_230 , 0 ) ;
V_198 = - V_265 ;
goto V_154;
}
if ( V_3 -> T_2 == NULL ) {
V_198 = - V_12 ;
goto V_154;
}
if ( V_251 > V_3 -> T_2 -> V_7 -> V_266 ) {
V_198 = - V_267 ;
goto V_154;
}
if ( V_252 != NULL ) {
if ( V_252 -> V_201 != V_202 ) {
V_198 = - V_66 ;
goto V_154;
}
if ( V_194 == sizeof( struct V_199 ) )
;
else if ( V_194 != sizeof( struct V_195 ) )
if ( ( V_194 < sizeof( struct V_199 ) + sizeof( T_3 ) * 6 ) ||
( V_194 > sizeof( struct V_195 ) ) ) {
V_198 = - V_66 ;
goto V_154;
}
if ( V_194 > sizeof( struct V_199 ) && V_252 -> V_209 != 0 ) {
int V_215 = 0 ;
struct V_195 * V_214 = (struct V_195 * ) V_252 ;
if ( V_252 -> V_209 < 1 || V_252 -> V_209 > V_65 ) {
V_198 = - V_66 ;
goto V_154;
}
V_255 . V_34 = V_252 -> V_209 ;
while ( V_215 < V_252 -> V_209 ) {
V_255 . V_228 [ V_215 ] = 0 ;
V_255 . V_69 [ V_215 ] = V_214 -> V_210 [ V_215 ] ;
V_215 ++ ;
}
V_255 . V_225 = 0 ;
}
V_254 = * V_252 ;
if ( V_2 -> V_27 == V_33 &&
F_24 ( & V_3 -> V_31 , & V_254 . V_206 ) ) {
V_198 = - V_222 ;
goto V_154;
}
if ( V_252 -> V_209 == 0 )
V_256 = NULL ;
else
V_256 = & V_255 ;
} else {
if ( V_2 -> V_28 != V_180 ) {
V_198 = - V_71 ;
goto V_154;
}
V_254 . V_201 = V_202 ;
V_254 . V_206 = V_3 -> V_31 ;
V_256 = V_3 -> V_35 ;
}
V_257 = V_251 + V_3 -> T_2 -> V_7 -> V_268 ;
V_37 = F_123 ( V_2 , V_257 , V_250 -> V_260 & V_261 , & V_198 ) ;
if ( V_37 == NULL )
goto V_154;
F_124 ( V_37 , V_257 - V_251 ) ;
if ( F_125 ( F_126 ( V_37 , V_251 ) , V_250 -> V_269 , V_251 ) ) {
V_198 = - V_61 ;
F_34 ( V_37 ) ;
goto V_154;
}
F_127 ( V_37 ) ;
if ( ! V_3 -> V_142 )
* F_128 ( V_37 , 1 ) = V_2 -> V_41 ;
if ( V_2 -> V_27 == V_33 ) {
if ( V_2 -> V_28 != V_180 ) {
F_34 ( V_37 ) ;
V_198 = - V_71 ;
goto V_154;
}
F_129 ( V_3 , V_3 -> V_99 , V_37 ) ;
V_198 = V_251 ;
goto V_154;
}
F_128 ( V_37 , 1 + F_130 ( V_256 ) ) ;
V_258 = F_131 ( V_37 -> V_45 , & V_3 -> V_26 , & V_254 . V_206 ,
V_256 , V_74 , V_83 ) ;
F_132 ( V_37 , V_258 ) ;
* F_133 ( V_37 ) = V_270 ;
F_134 ( V_37 , V_3 -> T_2 -> V_7 ) ;
V_198 = V_251 ;
V_154:
F_72 ( V_2 ) ;
return V_198 ;
}
static int F_135 ( struct V_247 * V_248 , struct V_128 * V_1 ,
struct V_249 * V_250 , T_8 V_257 , int V_212 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_36 * V_37 ;
int V_271 ;
int V_198 = 0 ;
F_69 ( V_2 ) ;
if ( V_2 -> V_27 == V_33 && V_2 -> V_28 != V_180 ) {
V_198 = - V_71 ;
goto V_154;
}
V_37 = F_136 ( V_2 , V_212 & ~ V_261 ,
V_212 & V_261 , & V_198 ) ;
if ( V_37 == NULL )
goto V_154;
if ( ! F_3 ( V_2 ) -> V_142 )
F_137 ( V_37 , 1 ) ;
F_138 ( V_37 ) ;
V_271 = V_37 -> V_251 ;
if ( V_271 > V_257 ) {
V_271 = V_257 ;
V_250 -> V_260 |= V_272 ;
}
F_139 ( V_37 , 0 , V_250 -> V_269 , V_271 ) ;
if ( V_250 -> V_259 != 0 ) {
struct V_199 * V_254 = (struct V_199 * ) V_250 -> V_253 ;
T_4 V_24 ;
T_3 V_273 ;
const unsigned char * V_274 = F_140 ( V_37 ) ;
F_141 ( V_274 + 1 , V_37 -> V_45 - V_274 - 1 , & V_273 , NULL ,
& V_24 , NULL , NULL ) ;
V_254 -> V_201 = V_202 ;
V_254 -> V_209 = V_24 . V_34 ;
V_254 -> V_206 = V_273 ;
if ( V_254 -> V_209 != 0 ) {
int V_215 ;
struct V_195 * V_214 = (struct V_195 * ) V_254 ;
for ( V_215 = 0 ; V_215 < V_24 . V_34 ; V_215 ++ )
V_214 -> V_210 [ V_215 ] = V_24 . V_69 [ V_215 ] ;
}
V_250 -> V_259 = sizeof( struct V_195 ) ;
}
F_142 ( V_2 , V_37 ) ;
V_198 = V_271 ;
V_154:
F_72 ( V_2 ) ;
return V_198 ;
}
static int F_143 ( struct V_128 * V_2 , int V_275 )
{
return - V_155 ;
}
static int F_144 ( struct V_128 * V_1 , unsigned int V_55 , unsigned long V_56 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
void T_5 * V_276 = ( void T_5 * ) V_56 ;
int V_136 = 0 ;
F_69 ( V_2 ) ;
switch ( V_55 ) {
case V_277 : {
long V_278 ;
V_278 = V_2 -> V_179 - F_145 ( V_2 ) ;
if ( V_278 < 0 )
V_278 = 0 ;
V_136 = F_76 ( V_278 , ( int T_5 * ) V_276 ) ;
break;
}
case V_279 : {
struct V_36 * V_37 ;
long V_278 = 0L ;
if ( ( V_37 = F_146 ( & V_2 -> V_46 ) ) != NULL )
V_278 = V_37 -> V_251 ;
V_136 = F_76 ( V_278 , ( int T_5 * ) V_276 ) ;
break;
}
case V_280 :
V_136 = F_147 ( V_2 , V_276 ) ;
break;
case V_281 :
V_136 = F_148 ( V_2 , V_276 ) ;
break;
case V_282 :
case V_283 :
case V_284 : {
struct V_199 V_47 ;
if ( F_54 ( & V_47 , V_276 , sizeof( V_47 ) ) ) {
V_136 = - V_61 ;
break;
}
V_136 = F_149 ( V_55 , & V_47 ) ;
break;
}
case V_285 : {
long V_278 ;
if ( ! F_101 ( V_204 ) ) {
V_136 = - V_286 ;
break;
}
if ( F_68 ( V_278 , ( long T_5 * ) V_276 ) ) {
V_136 = - V_61 ;
break;
}
if ( V_278 > V_287 ) {
V_136 = - V_66 ;
break;
}
V_203 = V_278 ;
V_136 = 0 ;
break;
}
case V_288 :
case V_289 :
case V_290 :
if ( ! F_101 ( V_204 ) ) {
V_136 = - V_286 ;
break;
}
V_136 = F_150 ( V_55 , V_276 ) ;
break;
case V_291 :
if ( ! F_101 ( V_204 ) ) {
V_136 = - V_286 ;
break;
}
V_136 = F_53 ( V_55 , V_276 ) ;
break;
case V_292 :
case V_293 : {
T_1 * V_3 = F_3 ( V_2 ) ;
struct V_294 V_295 ;
V_295 . V_88 = V_3 -> V_88 / V_54 ;
V_295 . V_90 = V_3 -> V_90 / V_54 ;
V_295 . V_95 = V_3 -> V_95 / V_54 ;
V_295 . V_97 = V_3 -> V_97 / ( 60 * V_54 ) ;
V_295 . V_93 = V_3 -> V_93 ;
V_295 . V_296 = F_151 ( & V_3 -> V_296 ) / V_54 ;
V_295 . V_297 = F_151 ( & V_3 -> V_297 ) / V_54 ;
V_295 . V_298 = F_151 ( & V_3 -> V_298 ) / V_54 ;
V_295 . V_299 = F_151 ( & V_3 -> V_299 ) / ( 60 * V_54 ) ;
V_295 . V_92 = V_3 -> V_92 ;
V_295 . V_48 = V_3 -> V_48 ;
V_295 . V_300 = F_152 ( V_2 ) ;
V_295 . V_301 = F_145 ( V_2 ) ;
V_295 . V_302 = V_3 -> V_302 ;
V_295 . V_303 = V_3 -> V_303 ;
V_295 . V_304 = V_3 -> V_304 ;
V_295 . V_305 = V_3 -> V_302 ;
V_295 . V_99 = V_3 -> V_99 ;
V_295 . V_85 = V_3 -> V_85 ;
if ( V_55 == V_293 ) {
static int V_306 = 0 ;
if ( ! V_306 ) {
F_107 ( V_307 L_2 ,
V_230 -> V_231 ) ;
V_306 = 1 ;
}
if ( F_77 ( V_276 , & V_295 , sizeof( struct V_308 ) ) ) {
V_136 = - V_61 ;
break;
}
} else {
if ( F_77 ( V_276 , & V_295 , sizeof( struct V_294 ) ) ) {
V_136 = - V_66 ;
break;
}
}
V_136 = 0 ;
break;
}
case V_309 :
case V_310 : {
struct V_311 V_312 ;
if ( ! F_101 ( V_204 ) ) {
V_136 = - V_286 ;
break;
}
if ( F_54 ( & V_312 , V_276 , sizeof( V_312 ) ) ) {
V_136 = - V_61 ;
break;
}
V_136 = F_153 ( V_55 , & V_312 ) ;
break;
}
case V_313 :
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_320 :
case V_321 :
case V_322 :
V_136 = - V_66 ;
break;
default:
V_136 = - V_323 ;
break;
}
F_72 ( V_2 ) ;
return V_136 ;
}
static void * F_154 ( struct V_324 * V_325 , T_9 * V_326 )
__acquires( V_5 )
{
F_6 ( & V_5 ) ;
return F_155 ( & V_22 , * V_326 ) ;
}
static void * F_156 ( struct V_324 * V_325 , void * V_327 , T_9 * V_326 )
{
return F_157 ( V_327 , & V_22 , V_326 ) ;
}
static void F_158 ( struct V_324 * V_325 , void * V_327 )
__releases( V_5 )
{
F_8 ( & V_5 ) ;
}
static int F_159 ( struct V_324 * V_325 , void * V_327 )
{
T_1 * V_3 = F_160 ( V_327 , struct T_1 , V_4 ) ;
char V_328 [ 11 ] ;
int V_59 ;
F_161 ( V_325 , L_3 ,
( long ) V_3 ,
V_3 -> T_2 == NULL ? L_4 : V_3 -> T_2 -> V_7 -> V_151 ,
F_162 ( V_328 , & V_3 -> V_26 ) ,
V_3 -> V_25 ? L_5 : L_6 ) ;
F_161 ( V_325 , L_7 , F_162 ( V_328 , & V_3 -> V_31 ) ) ;
for ( V_59 = 0 ; ( V_3 -> V_35 != NULL ) && ( V_59 < V_3 -> V_35 -> V_34 ) ; V_59 ++ ) {
F_161 ( V_325 , L_8 ,
F_162 ( V_328 , & V_3 -> V_35 -> V_69 [ V_59 ] ) ,
V_3 -> V_35 -> V_228 [ V_59 ] ? L_5 : L_6 ) ;
}
F_161 ( V_325 , L_9 ,
V_3 -> V_48 ,
V_3 -> V_302 , V_3 -> V_303 , V_3 -> V_304 ,
F_151 ( & V_3 -> V_296 ) / V_54 , V_3 -> V_88 / V_54 ,
F_151 ( & V_3 -> V_297 ) / V_54 , V_3 -> V_90 / V_54 ,
F_151 ( & V_3 -> V_298 ) / V_54 , V_3 -> V_95 / V_54 ,
F_151 ( & V_3 -> V_299 ) / ( 60 * V_54 ) ,
V_3 -> V_97 / ( 60 * V_54 ) ,
V_3 -> V_92 , V_3 -> V_93 ,
V_3 -> V_87 / V_54 ,
V_3 -> V_85 ,
V_3 -> V_99 ) ;
if ( V_3 -> V_2 != NULL ) {
F_161 ( V_325 , L_10 ,
F_145 ( V_3 -> V_2 ) ,
F_152 ( V_3 -> V_2 ) ,
F_163 ( V_3 -> V_2 ) ) ;
} else {
F_164 ( V_325 , L_11 ) ;
}
return 0 ;
}
static int F_165 ( struct V_329 * V_329 , struct V_330 * V_330 )
{
return F_166 ( V_330 , & V_331 ) ;
}
static int T_10 F_167 ( void )
{
int V_332 = F_168 ( & V_169 , 0 ) ;
if ( V_332 != 0 )
goto V_154;
F_169 ( & V_333 ) ;
F_170 ( & V_334 ) ;
F_171 ( & V_335 ) ;
F_172 () ;
F_173 ( & V_17 , L_12 , V_336 , & V_337 ) ;
F_173 ( & V_17 , L_13 , V_336 , & V_338 ) ;
F_173 ( & V_17 , L_14 , V_336 , & V_339 ) ;
V_154:
return V_332 ;
}
static void T_11 F_174 ( void )
{
F_175 ( & V_17 , L_12 ) ;
F_175 ( & V_17 , L_13 ) ;
F_175 ( & V_17 , L_14 ) ;
F_176 () ;
F_177 () ;
F_178 () ;
F_179 () ;
F_180 ( & V_335 ) ;
F_181 ( & V_334 ) ;
F_182 ( V_161 ) ;
F_183 ( & V_169 ) ;
}
