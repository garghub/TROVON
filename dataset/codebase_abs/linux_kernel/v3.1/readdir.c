static void F_1 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 ;
if ( V_1 ) {
V_4 = V_1 -> V_5 ;
if ( V_4 == NULL ) {
F_2 ( 1 , L_1 ) ;
return;
}
if ( V_4 -> V_6 )
F_2 ( 1 , L_2 ) ;
if ( V_4 -> V_7 . V_8 )
F_2 ( 1 , L_3 ) ;
if ( V_4 -> V_7 . V_9 )
F_2 ( 1 , L_4 ) ;
}
}
static inline void F_1 ( struct V_1 * V_1 , char * V_2 )
{
}
static struct V_10 *
F_3 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_10 * V_10 , * V_16 ;
struct V_17 * V_17 ;
struct V_18 * V_19 = V_11 -> V_20 -> V_21 ;
F_2 ( 1 , L_5 , V_13 -> V_13 ) ;
if ( V_11 -> V_22 && V_11 -> V_22 -> V_23 )
V_11 -> V_22 -> V_23 ( V_11 , V_11 -> V_20 , V_13 ) ;
else
V_13 -> V_24 = F_4 ( V_13 -> V_13 , V_13 -> V_25 ) ;
V_10 = F_5 ( V_11 , V_13 ) ;
if ( V_10 ) {
if ( V_10 -> V_20 != NULL )
return V_10 ;
F_6 ( V_10 ) ;
F_7 ( V_10 ) ;
}
V_10 = F_8 ( V_11 , V_13 ) ;
if ( V_10 == NULL )
return NULL ;
V_17 = F_9 ( V_19 , V_15 ) ;
if ( ! V_17 ) {
F_7 ( V_10 ) ;
return NULL ;
}
V_16 = F_10 ( V_10 , V_17 ) ;
if ( V_16 != NULL ) {
F_7 ( V_10 ) ;
if ( F_11 ( V_16 ) )
return NULL ;
V_10 = V_16 ;
}
return V_10 ;
}
static void
F_12 ( struct V_14 * V_15 , struct V_26 * V_27 )
{
V_15 -> V_28 = V_27 -> V_29 ;
V_15 -> V_30 = V_27 -> V_31 ;
if ( V_15 -> V_32 & V_33 ) {
V_15 -> V_34 = V_35 | V_27 -> V_36 ;
V_15 -> V_37 = V_38 ;
} else {
V_15 -> V_34 = V_39 | V_27 -> V_40 ;
V_15 -> V_37 = V_41 ;
}
if ( V_15 -> V_32 & V_42 )
V_15 -> V_34 &= ~ V_43 ;
if ( V_27 -> V_44 & V_45 &&
V_15 -> V_32 & V_46 ) {
if ( V_15 -> V_47 == 0 ) {
V_15 -> V_34 &= ~ V_48 ;
V_15 -> V_34 |= V_49 ;
V_15 -> V_37 = V_50 ;
} else {
V_15 -> V_51 |= V_52 ;
}
}
}
static void
F_13 ( struct V_14 * V_15 , T_1 * V_53 ,
struct V_26 * V_27 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_32 = F_14 ( V_53 -> V_54 ) ;
V_15 -> V_47 = F_15 ( V_53 -> V_55 ) ;
V_15 -> V_56 = F_15 ( V_53 -> V_57 ) ;
V_15 -> V_58 = F_15 ( V_53 -> V_59 ) ;
V_15 -> V_60 = F_16 ( V_53 -> V_61 ) ;
V_15 -> V_62 = F_16 ( V_53 -> V_63 ) ;
V_15 -> V_64 = F_16 ( V_53 -> V_65 ) ;
F_12 ( V_15 , V_27 ) ;
}
static void
F_17 ( struct V_14 * V_15 , T_2 * V_53 ,
struct V_26 * V_27 )
{
int V_66 = F_18 ( V_27 ) -> V_67 -> V_68 -> V_69 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_60 = F_19 ( V_53 -> V_70 ,
V_53 -> V_61 , V_66 ) ;
V_15 -> V_62 = F_19 ( V_53 -> V_71 ,
V_53 -> V_65 , V_66 ) ;
V_15 -> V_64 = F_19 ( V_53 -> V_71 ,
V_53 -> V_65 , V_66 ) ;
V_15 -> V_32 = F_20 ( V_53 -> V_72 ) ;
V_15 -> V_56 = F_14 ( V_53 -> V_57 ) ;
V_15 -> V_47 = F_14 ( V_53 -> V_73 ) ;
F_12 ( V_15 , V_27 ) ;
}
static int F_21 ( const int V_74 , struct V_1 * V_1 )
{
int V_75 = 0 ;
char * V_76 = NULL ;
struct V_3 * V_77 ;
struct V_26 * V_27 = F_22 ( V_1 -> V_78 . V_10 -> V_79 ) ;
struct V_80 * V_81 = NULL ;
struct V_82 * V_83 ;
if ( V_1 -> V_5 == NULL ) {
V_81 = F_23 ( V_27 ) ;
if ( F_11 ( V_81 ) )
return F_24 ( V_81 ) ;
V_77 = F_25 ( sizeof( struct V_3 ) , V_84 ) ;
if ( V_77 == NULL ) {
V_75 = - V_85 ;
goto V_86;
}
V_1 -> V_5 = V_77 ;
V_77 -> V_81 = F_26 ( V_81 ) ;
V_83 = F_27 ( V_81 ) ;
} else {
V_77 = V_1 -> V_5 ;
V_83 = F_27 ( V_77 -> V_81 ) ;
}
V_77 -> V_6 = true ;
V_77 -> V_7 . V_8 = false ;
V_76 = F_28 ( V_1 -> V_78 . V_10 ) ;
if ( V_76 == NULL ) {
V_75 = - V_85 ;
goto V_86;
}
F_2 ( 1 , L_6 , V_76 , V_1 -> V_87 ) ;
V_88:
if ( V_83 -> V_89 )
V_77 -> V_7 . V_90 = V_91 ;
else if ( ( V_83 -> V_67 -> V_92 &
( V_93 | V_94 ) ) == 0 ) {
V_77 -> V_7 . V_90 = V_95 ;
} else if ( V_27 -> V_44 & V_96 ) {
V_77 -> V_7 . V_90 = V_97 ;
} else {
V_77 -> V_7 . V_90 = V_98 ;
}
V_75 = F_29 ( V_74 , V_83 , V_76 , V_27 -> V_99 ,
& V_77 -> V_100 , & V_77 -> V_7 ,
V_27 -> V_44 &
V_101 , F_30 ( V_27 ) ) ;
if ( V_75 == 0 )
V_77 -> V_6 = false ;
else if ( ( V_75 == - V_102 ) &&
( V_27 -> V_44 & V_96 ) ) {
V_27 -> V_44 &= ~ V_96 ;
goto V_88;
}
V_86:
F_31 ( V_76 ) ;
F_32 ( V_81 ) ;
return V_75 ;
}
static int F_33 ( const char * V_103 )
{
int V_25 ;
const T_3 * V_104 = ( const T_3 * ) V_103 ;
for ( V_25 = 0 ; V_25 <= V_105 ; V_25 ++ ) {
if ( V_104 [ V_25 ] == 0 )
return V_25 << 1 ;
}
F_2 ( 1 , L_7 ) ;
return V_25 << 1 ;
}
static char * F_34 ( char * V_106 , char * V_107 , int V_108 )
{
char * V_109 ;
T_1 * V_110 = ( T_1 * ) V_106 ;
if ( V_108 == V_95 ) {
T_2 * V_111 ;
V_111 = ( T_2 * ) V_110 ;
V_109 = V_106 + sizeof( T_2 ) +
V_111 -> V_112 ;
} else
V_109 = V_106 + F_14 ( V_110 -> V_113 ) ;
F_2 ( 1 , L_8 , V_109 , V_106 ) ;
if ( V_109 >= V_107 ) {
F_35 ( 1 , L_9 ,
V_109 , V_107 , V_106 ) ;
return NULL ;
} else if ( ( ( V_108 == V_95 ) &&
( V_109 + sizeof( T_2 ) > V_107 ) )
|| ( ( V_108 != V_95 ) &&
( V_109 + sizeof( T_1 ) > V_107 ) ) ) {
F_35 ( 1 , L_10 ,
V_109 , V_107 ) ;
return NULL ;
} else
return V_109 ;
}
static void F_36 ( struct V_114 * V_115 ,
const T_4 * V_53 , bool V_116 )
{
V_115 -> V_13 = & V_53 -> V_117 [ 0 ] ;
if ( V_116 )
V_115 -> V_118 = F_33 ( V_115 -> V_13 ) ;
else
V_115 -> V_118 = F_37 ( V_115 -> V_13 , V_105 ) ;
V_115 -> V_119 = V_53 -> V_120 ;
V_115 -> V_121 = F_15 ( V_53 -> V_122 . V_123 ) ;
}
static void F_38 ( struct V_114 * V_115 ,
const T_1 * V_53 )
{
V_115 -> V_13 = & V_53 -> V_117 [ 0 ] ;
V_115 -> V_118 = F_14 ( V_53 -> V_112 ) ;
V_115 -> V_119 = V_53 -> V_124 ;
}
static void F_39 ( struct V_114 * V_115 ,
const T_5 * V_53 )
{
V_115 -> V_13 = & V_53 -> V_117 [ 0 ] ;
V_115 -> V_118 = F_14 ( V_53 -> V_112 ) ;
V_115 -> V_119 = V_53 -> V_124 ;
}
static void F_40 ( struct V_114 * V_115 ,
const T_6 * V_53 )
{
V_115 -> V_13 = & V_53 -> V_117 [ 0 ] ;
V_115 -> V_118 = F_14 ( V_53 -> V_112 ) ;
V_115 -> V_119 = V_53 -> V_124 ;
V_115 -> V_121 = F_15 ( V_53 -> V_123 ) ;
}
static void F_41 ( struct V_114 * V_115 ,
const T_7 * V_53 )
{
V_115 -> V_13 = & V_53 -> V_117 [ 0 ] ;
V_115 -> V_118 = F_14 ( V_53 -> V_112 ) ;
V_115 -> V_119 = V_53 -> V_124 ;
}
static void F_42 ( struct V_114 * V_115 ,
const T_2 * V_53 )
{
V_115 -> V_13 = & V_53 -> V_117 [ 0 ] ;
V_115 -> V_118 = V_53 -> V_112 ;
V_115 -> V_119 = V_53 -> V_120 ;
}
static int F_43 ( struct V_114 * V_115 , const void * V_53 ,
T_8 V_108 , bool V_116 )
{
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
switch ( V_108 ) {
case V_91 :
F_36 ( V_115 , V_53 , V_116 ) ;
break;
case V_98 :
F_38 ( V_115 , V_53 ) ;
break;
case V_125 :
F_39 ( V_115 , V_53 ) ;
break;
case V_97 :
F_40 ( V_115 , V_53 ) ;
break;
case V_126 :
F_41 ( V_115 , V_53 ) ;
break;
case V_95 :
F_42 ( V_115 , V_53 ) ;
break;
default:
F_2 ( 1 , L_11 , V_108 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_44 ( struct V_114 * V_115 , bool V_116 )
{
int V_75 = 0 ;
if ( ! V_115 -> V_13 )
return 0 ;
if ( V_116 ) {
T_3 * V_128 = ( T_3 * ) V_115 -> V_13 ;
if ( V_115 -> V_118 == 2 ) {
if ( V_128 [ 0 ] == V_129 )
V_75 = 1 ;
} else if ( V_115 -> V_118 == 4 ) {
if ( V_128 [ 0 ] == V_129 &&
V_128 [ 1 ] == V_129 )
V_75 = 2 ;
}
} else {
if ( V_115 -> V_118 == 1 ) {
if ( V_115 -> V_13 [ 0 ] == '.' )
V_75 = 1 ;
} else if ( V_115 -> V_118 == 2 ) {
if ( V_115 -> V_13 [ 0 ] == '.' && V_115 -> V_13 [ 1 ] == '.' )
V_75 = 2 ;
}
}
return V_75 ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = V_1 -> V_78 . V_10 -> V_20 ;
struct V_130 * V_131 = F_46 ( V_17 ) ;
if ( V_131 -> time == 0 )
return 1 ;
else
return 0 ;
}
static int F_47 ( const char * V_132 ,
struct V_3 * V_133 )
{
struct V_114 V_115 ;
int V_75 ;
V_75 = F_43 ( & V_115 , V_132 , V_133 -> V_7 . V_90 ,
V_133 -> V_7 . V_134 ) ;
if ( ! V_75 ) {
V_133 -> V_7 . V_135 = V_115 . V_13 ;
V_133 -> V_7 . V_136 = V_115 . V_118 ;
V_133 -> V_7 . V_119 = V_115 . V_119 ;
}
return V_75 ;
}
static int F_48 ( const int V_74 , struct V_82 * V_83 ,
struct V_1 * V_1 , char * * V_137 , int * V_138 )
{
int V_75 = 0 ;
int V_139 = 0 ;
T_9 V_140 ;
T_9 V_141 = V_1 -> V_87 ;
struct V_3 * V_77 = V_1 -> V_5 ;
if ( ( V_77 == NULL ) || ( V_137 == NULL ) ||
( V_138 == NULL ) )
return - V_142 ;
* V_137 = NULL ;
V_140 =
V_77 -> V_7 . V_143 -
V_77 -> V_7 . V_144 ;
F_1 ( V_1 , L_12 ) ;
if ( ( ( V_141 < V_77 -> V_7 . V_143 ) &&
F_45 ( V_1 ) ) ||
( V_141 < V_140 ) ) {
F_2 ( 1 , L_13 ) ;
F_49 ( & V_145 ) ;
if ( ! V_77 -> V_7 . V_8 &&
! V_77 -> V_6 ) {
V_77 -> V_6 = true ;
F_50 ( & V_145 ) ;
F_51 ( V_74 , V_83 , V_77 -> V_100 ) ;
} else
F_50 ( & V_145 ) ;
if ( V_77 -> V_7 . V_146 ) {
F_2 ( 1 , L_14 ) ;
if ( V_77 -> V_7 . V_147 )
F_52 ( V_77 -> V_7 .
V_146 ) ;
else
F_53 ( V_77 -> V_7 .
V_146 ) ;
V_77 -> V_7 . V_146 = NULL ;
}
V_75 = F_21 ( V_74 , V_1 ) ;
if ( V_75 ) {
F_2 ( 1 , L_15 ,
V_75 ) ;
return V_75 ;
}
F_47 ( V_77 -> V_7 . V_148 , V_77 ) ;
}
while ( ( V_141 >= V_77 -> V_7 . V_143 ) &&
( V_75 == 0 ) && ! V_77 -> V_7 . V_8 ) {
F_2 ( 1 , L_16 ) ;
V_75 = F_54 ( V_74 , V_83 , V_77 -> V_100 ,
& V_77 -> V_7 ) ;
F_47 ( V_77 -> V_7 . V_148 , V_77 ) ;
if ( V_75 )
return - V_142 ;
}
if ( V_141 < V_77 -> V_7 . V_143 ) {
int V_149 ;
char * V_132 ;
char * V_107 = V_77 -> V_7 . V_146 +
F_55 ( (struct V_150 * )
V_77 -> V_7 . V_146 ) ;
V_132 = V_77 -> V_7 . V_151 ;
V_140 = V_77 -> V_7 . V_143
- V_77 -> V_7 . V_144 ;
V_139 = V_141 - V_140 ;
F_2 ( 1 , L_17 , V_139 ) ;
for ( V_149 = 0 ; ( V_149 < ( V_139 ) ) && ( V_132 != NULL ) ; V_149 ++ ) {
V_132 = F_34 ( V_132 , V_107 ,
V_77 -> V_7 . V_90 ) ;
}
if ( ( V_132 == NULL ) && ( V_149 < V_139 ) ) {
F_35 ( 1 , L_18
L_19 ,
V_139 , V_141 , V_75 ) ;
}
V_75 = 0 ;
* V_137 = V_132 ;
} else {
F_2 ( 1 , L_20 ) ;
return 0 ;
}
if ( V_139 >= V_77 -> V_7 . V_144 ) {
F_2 ( 1 , L_21 ) ;
* V_138 = 0 ;
} else
* V_138 = V_77 -> V_7 . V_144 - V_139 ;
return V_75 ;
}
static int F_56 ( char * V_152 , struct V_1 * V_1 , T_10 V_153 ,
void * V_154 , char * V_155 , unsigned int V_156 )
{
struct V_3 * V_133 = V_1 -> V_5 ;
struct V_18 * V_19 = V_1 -> V_78 . V_10 -> V_79 ;
struct V_26 * V_27 = F_22 ( V_19 ) ;
struct V_114 V_115 = { NULL , } ;
struct V_14 V_15 ;
struct V_10 * V_10 ;
struct V_12 V_13 ;
int V_75 = 0 ;
T_11 V_121 ;
V_75 = F_43 ( & V_115 , V_152 , V_133 -> V_7 . V_90 ,
V_133 -> V_7 . V_134 ) ;
if ( V_75 )
return V_75 ;
if ( V_115 . V_118 > V_156 ) {
F_35 ( 1 , L_22 ,
V_115 . V_118 ) ;
return - V_127 ;
}
if ( F_44 ( & V_115 , V_133 -> V_7 . V_134 ) )
return 0 ;
if ( V_133 -> V_7 . V_134 ) {
struct V_157 * V_158 = V_27 -> V_99 ;
V_13 . V_13 = V_155 ;
V_13 . V_25 =
F_57 ( ( char * ) V_13 . V_13 , ( T_3 * ) V_115 . V_13 ,
V_159 ,
F_58 ( V_115 . V_118 , ( V_160 ) V_156 ) , V_158 ,
V_27 -> V_44 &
V_101 ) ;
V_13 . V_25 -= F_59 ( V_158 ) ;
} else {
V_13 . V_13 = V_115 . V_13 ;
V_13 . V_25 = V_115 . V_118 ;
}
switch ( V_133 -> V_7 . V_90 ) {
case V_91 :
F_60 ( & V_15 ,
& ( ( T_4 * ) V_152 ) -> V_122 ,
V_27 ) ;
break;
case V_95 :
F_17 ( & V_15 ,
( T_2 * ) V_152 ,
V_27 ) ;
break;
default:
F_13 ( & V_15 ,
( T_1 * ) V_152 ,
V_27 ) ;
break;
}
if ( V_115 . V_121 && ( V_27 -> V_44 & V_96 ) ) {
V_15 . V_161 = V_115 . V_121 ;
} else {
V_15 . V_161 = F_61 ( V_19 , V_162 ) ;
F_62 ( V_27 ) ;
}
if ( ( V_27 -> V_44 & V_163 ) &&
F_63 ( & V_15 ) )
V_15 . V_51 |= V_52 ;
V_121 = F_64 ( V_15 . V_161 ) ;
V_10 = F_3 ( V_1 -> V_164 , & V_13 , & V_15 ) ;
V_75 = V_153 ( V_154 , V_13 . V_13 , V_13 . V_25 , V_1 -> V_87 , V_121 ,
V_15 . V_37 ) ;
F_7 ( V_10 ) ;
return V_75 ;
}
int F_65 ( struct V_1 * V_1 , void * V_165 , T_10 V_153 )
{
int V_75 = 0 ;
int V_74 , V_149 ;
struct V_82 * V_83 ;
struct V_3 * V_77 = NULL ;
char * V_132 ;
int V_166 = 0 ;
char * V_167 = NULL ;
char * V_107 ;
unsigned int V_156 ;
V_74 = F_66 () ;
if ( V_1 -> V_5 == NULL ) {
V_75 = F_21 ( V_74 , V_1 ) ;
F_2 ( 1 , L_23 , V_75 ) ;
if ( V_75 )
goto V_168;
}
switch ( ( int ) V_1 -> V_87 ) {
case 0 :
if ( V_153 ( V_165 , L_24 , 1 , V_1 -> V_87 ,
V_1 -> V_78 . V_10 -> V_20 -> V_169 , V_38 ) < 0 ) {
F_35 ( 1 , L_25 ) ;
V_75 = - V_85 ;
break;
}
V_1 -> V_87 ++ ;
case 1 :
if ( V_153 ( V_165 , L_26 , 2 , V_1 -> V_87 ,
F_67 ( V_1 -> V_78 . V_10 ) , V_38 ) < 0 ) {
F_35 ( 1 , L_27 ) ;
V_75 = - V_85 ;
break;
}
V_1 -> V_87 ++ ;
default:
if ( V_1 -> V_5 == NULL ) {
V_75 = - V_127 ;
F_68 ( V_74 ) ;
return V_75 ;
}
V_77 = V_1 -> V_5 ;
if ( V_77 -> V_7 . V_8 ) {
if ( V_77 -> V_7 . V_9 ) {
F_2 ( 1 , L_28 ) ;
V_75 = 0 ;
break;
}
}
V_83 = F_27 ( V_77 -> V_81 ) ;
V_75 = F_48 ( V_74 , V_83 , V_1 ,
& V_132 , & V_166 ) ;
if ( V_75 ) {
F_2 ( 1 , L_29 , V_75 ) ;
goto V_168;
} else if ( V_132 != NULL ) {
F_2 ( 1 , L_30 , V_1 -> V_87 ) ;
} else {
F_2 ( 1 , L_31 ) ;
goto V_168;
}
F_2 ( 1 , L_32 ,
V_166 , V_77 -> V_7 . V_146 ) ;
V_156 = F_55 ( (struct V_150 * )
V_77 -> V_7 . V_146 ) ;
V_107 = V_77 -> V_7 . V_146 + V_156 ;
V_167 = F_69 ( V_159 , V_84 ) ;
if ( V_167 == NULL ) {
V_75 = - V_85 ;
break;
}
for ( V_149 = 0 ; ( V_149 < V_166 ) && ( V_75 == 0 ) ; V_149 ++ ) {
if ( V_132 == NULL ) {
F_35 ( 1 , L_33 ,
V_166 , V_149 ) ;
break;
}
V_75 = F_56 ( V_132 , V_1 ,
V_153 , V_165 , V_167 , V_156 ) ;
if ( V_75 == - V_170 ) {
V_75 = 0 ;
break;
}
V_1 -> V_87 ++ ;
if ( V_1 -> V_87 ==
V_77 -> V_7 . V_143 ) {
F_2 ( 1 , L_34 ,
V_1 -> V_87 , V_167 ) ;
F_47 ( V_132 , V_77 ) ;
break;
} else
V_132 =
F_34 ( V_132 , V_107 ,
V_77 -> V_7 . V_90 ) ;
}
F_31 ( V_167 ) ;
break;
}
V_168:
F_68 ( V_74 ) ;
return V_75 ;
}
