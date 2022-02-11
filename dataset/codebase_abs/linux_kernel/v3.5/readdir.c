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
V_17 = V_10 -> V_20 ;
if ( V_17 && F_6 ( V_17 ) -> V_26 == V_15 -> V_27 ) {
F_7 ( V_17 , V_15 ) ;
return V_10 ;
}
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
}
V_10 = F_10 ( V_11 , V_13 ) ;
if ( V_10 == NULL )
return NULL ;
V_17 = F_11 ( V_19 , V_15 ) ;
if ( ! V_17 ) {
F_9 ( V_10 ) ;
return NULL ;
}
V_16 = F_12 ( V_10 , V_17 ) ;
if ( V_16 != NULL ) {
F_9 ( V_10 ) ;
if ( F_13 ( V_16 ) )
return NULL ;
V_10 = V_16 ;
}
return V_10 ;
}
static void
F_14 ( struct V_14 * V_15 , struct V_28 * V_29 )
{
V_15 -> V_30 = V_29 -> V_31 ;
V_15 -> V_32 = V_29 -> V_33 ;
if ( V_15 -> V_34 & V_35 ) {
V_15 -> V_36 = V_37 | V_29 -> V_38 ;
V_15 -> V_39 = V_40 ;
} else {
V_15 -> V_36 = V_41 | V_29 -> V_42 ;
V_15 -> V_39 = V_43 ;
}
if ( V_15 -> V_34 & V_44 )
V_15 -> V_36 &= ~ V_45 ;
if ( V_29 -> V_46 & V_47 &&
V_15 -> V_34 & V_48 ) {
if ( V_15 -> V_49 == 0 ) {
V_15 -> V_36 &= ~ V_50 ;
V_15 -> V_36 |= V_51 ;
V_15 -> V_39 = V_52 ;
} else {
V_15 -> V_53 |= V_54 ;
}
}
}
static void
F_15 ( struct V_14 * V_15 , T_1 * V_55 ,
struct V_28 * V_29 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_34 = F_16 ( V_55 -> V_56 ) ;
V_15 -> V_49 = F_17 ( V_55 -> V_57 ) ;
V_15 -> V_58 = F_17 ( V_55 -> V_59 ) ;
V_15 -> V_60 = F_17 ( V_55 -> V_61 ) ;
V_15 -> V_62 = F_18 ( V_55 -> V_63 ) ;
V_15 -> V_64 = F_18 ( V_55 -> V_65 ) ;
V_15 -> V_66 = F_18 ( V_55 -> V_67 ) ;
F_14 ( V_15 , V_29 ) ;
}
static void
F_19 ( struct V_14 * V_15 , T_2 * V_55 ,
struct V_28 * V_29 )
{
int V_68 = F_20 ( V_29 ) -> V_69 -> V_70 -> V_71 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_62 = F_21 ( V_55 -> V_72 ,
V_55 -> V_63 , V_68 ) ;
V_15 -> V_64 = F_21 ( V_55 -> V_73 ,
V_55 -> V_67 , V_68 ) ;
V_15 -> V_66 = F_21 ( V_55 -> V_73 ,
V_55 -> V_67 , V_68 ) ;
V_15 -> V_34 = F_22 ( V_55 -> V_74 ) ;
V_15 -> V_58 = F_16 ( V_55 -> V_59 ) ;
V_15 -> V_49 = F_16 ( V_55 -> V_75 ) ;
F_14 ( V_15 , V_29 ) ;
}
static int F_23 ( const int V_76 , struct V_1 * V_1 )
{
T_3 V_77 ;
int V_78 = 0 ;
char * V_79 = NULL ;
struct V_3 * V_80 ;
struct V_28 * V_29 = F_24 ( V_1 -> V_81 . V_10 -> V_82 ) ;
struct V_83 * V_84 = NULL ;
struct V_85 * V_86 ;
if ( V_1 -> V_5 == NULL ) {
V_84 = F_25 ( V_29 ) ;
if ( F_13 ( V_84 ) )
return F_26 ( V_84 ) ;
V_80 = F_27 ( sizeof( struct V_3 ) , V_87 ) ;
if ( V_80 == NULL ) {
V_78 = - V_88 ;
goto V_89;
}
V_1 -> V_5 = V_80 ;
V_80 -> V_84 = F_28 ( V_84 ) ;
V_86 = F_29 ( V_84 ) ;
} else {
V_80 = V_1 -> V_5 ;
V_86 = F_29 ( V_80 -> V_84 ) ;
}
V_80 -> V_6 = true ;
V_80 -> V_7 . V_8 = false ;
V_79 = F_30 ( V_1 -> V_81 . V_10 ) ;
if ( V_79 == NULL ) {
V_78 = - V_88 ;
goto V_89;
}
F_2 ( 1 , L_6 , V_79 , V_1 -> V_90 ) ;
V_91:
if ( V_86 -> V_92 )
V_80 -> V_7 . V_93 = V_94 ;
else if ( ( V_86 -> V_69 -> V_95 &
( V_96 | V_97 ) ) == 0 ) {
V_80 -> V_7 . V_93 = V_98 ;
} else if ( V_29 -> V_46 & V_99 ) {
V_80 -> V_7 . V_93 = V_100 ;
} else {
V_80 -> V_7 . V_93 = V_101 ;
}
V_77 = V_102 | V_103 ;
if ( F_31 ( V_29 ) )
V_77 |= V_104 ;
V_78 = F_32 ( V_76 , V_86 , V_79 , V_29 -> V_105 ,
& V_80 -> V_106 , V_77 , & V_80 -> V_7 ,
V_29 -> V_46 &
V_107 , F_33 ( V_29 ) ) ;
if ( V_78 == 0 )
V_80 -> V_6 = false ;
else if ( ( V_78 == - V_108 ) &&
( V_29 -> V_46 & V_99 ) ) {
V_29 -> V_46 &= ~ V_99 ;
goto V_91;
}
V_89:
F_34 ( V_79 ) ;
F_35 ( V_84 ) ;
return V_78 ;
}
static int F_36 ( const char * V_109 )
{
int V_25 ;
const T_4 * V_110 = ( const T_4 * ) V_109 ;
for ( V_25 = 0 ; V_25 <= V_111 ; V_25 ++ ) {
if ( V_110 [ V_25 ] == 0 )
return V_25 << 1 ;
}
F_2 ( 1 , L_7 ) ;
return V_25 << 1 ;
}
static char * F_37 ( char * V_112 , char * V_113 , int V_114 )
{
char * V_115 ;
T_1 * V_116 = ( T_1 * ) V_112 ;
if ( V_114 == V_98 ) {
T_2 * V_117 ;
V_117 = ( T_2 * ) V_116 ;
V_115 = V_112 + sizeof( T_2 ) +
V_117 -> V_118 ;
} else
V_115 = V_112 + F_16 ( V_116 -> V_119 ) ;
F_2 ( 1 , L_8 , V_115 , V_112 ) ;
if ( V_115 >= V_113 ) {
F_38 ( 1 , L_9 ,
V_115 , V_113 , V_112 ) ;
return NULL ;
} else if ( ( ( V_114 == V_98 ) &&
( V_115 + sizeof( T_2 ) > V_113 ) )
|| ( ( V_114 != V_98 ) &&
( V_115 + sizeof( T_1 ) > V_113 ) ) ) {
F_38 ( 1 , L_10 ,
V_115 , V_113 ) ;
return NULL ;
} else
return V_115 ;
}
static void F_39 ( struct V_120 * V_121 ,
const T_5 * V_55 , bool V_122 )
{
V_121 -> V_13 = & V_55 -> V_123 [ 0 ] ;
if ( V_122 )
V_121 -> V_124 = F_36 ( V_121 -> V_13 ) ;
else
V_121 -> V_124 = F_40 ( V_121 -> V_13 , V_111 ) ;
V_121 -> V_125 = V_55 -> V_126 ;
V_121 -> V_127 = F_17 ( V_55 -> V_128 . V_129 ) ;
}
static void F_41 ( struct V_120 * V_121 ,
const T_1 * V_55 )
{
V_121 -> V_13 = & V_55 -> V_123 [ 0 ] ;
V_121 -> V_124 = F_16 ( V_55 -> V_118 ) ;
V_121 -> V_125 = V_55 -> V_130 ;
}
static void F_42 ( struct V_120 * V_121 ,
const T_6 * V_55 )
{
V_121 -> V_13 = & V_55 -> V_123 [ 0 ] ;
V_121 -> V_124 = F_16 ( V_55 -> V_118 ) ;
V_121 -> V_125 = V_55 -> V_130 ;
}
static void F_43 ( struct V_120 * V_121 ,
const T_7 * V_55 )
{
V_121 -> V_13 = & V_55 -> V_123 [ 0 ] ;
V_121 -> V_124 = F_16 ( V_55 -> V_118 ) ;
V_121 -> V_125 = V_55 -> V_130 ;
V_121 -> V_127 = F_17 ( V_55 -> V_129 ) ;
}
static void F_44 ( struct V_120 * V_121 ,
const T_8 * V_55 )
{
V_121 -> V_13 = & V_55 -> V_123 [ 0 ] ;
V_121 -> V_124 = F_16 ( V_55 -> V_118 ) ;
V_121 -> V_125 = V_55 -> V_130 ;
}
static void F_45 ( struct V_120 * V_121 ,
const T_2 * V_55 )
{
V_121 -> V_13 = & V_55 -> V_123 [ 0 ] ;
V_121 -> V_124 = V_55 -> V_118 ;
V_121 -> V_125 = V_55 -> V_126 ;
}
static int F_46 ( struct V_120 * V_121 , const void * V_55 ,
T_9 V_114 , bool V_122 )
{
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
switch ( V_114 ) {
case V_94 :
F_39 ( V_121 , V_55 , V_122 ) ;
break;
case V_101 :
F_41 ( V_121 , V_55 ) ;
break;
case V_131 :
F_42 ( V_121 , V_55 ) ;
break;
case V_100 :
F_43 ( V_121 , V_55 ) ;
break;
case V_132 :
F_44 ( V_121 , V_55 ) ;
break;
case V_98 :
F_45 ( V_121 , V_55 ) ;
break;
default:
F_2 ( 1 , L_11 , V_114 ) ;
return - V_133 ;
}
return 0 ;
}
static int F_47 ( struct V_120 * V_121 , bool V_122 )
{
int V_78 = 0 ;
if ( ! V_121 -> V_13 )
return 0 ;
if ( V_122 ) {
T_4 * V_134 = ( T_4 * ) V_121 -> V_13 ;
if ( V_121 -> V_124 == 2 ) {
if ( V_134 [ 0 ] == V_135 )
V_78 = 1 ;
} else if ( V_121 -> V_124 == 4 ) {
if ( V_134 [ 0 ] == V_135 &&
V_134 [ 1 ] == V_135 )
V_78 = 2 ;
}
} else {
if ( V_121 -> V_124 == 1 ) {
if ( V_121 -> V_13 [ 0 ] == '.' )
V_78 = 1 ;
} else if ( V_121 -> V_124 == 2 ) {
if ( V_121 -> V_13 [ 0 ] == '.' && V_121 -> V_13 [ 1 ] == '.' )
V_78 = 2 ;
}
}
return V_78 ;
}
static int F_48 ( struct V_1 * V_1 )
{
struct V_17 * V_17 = V_1 -> V_81 . V_10 -> V_20 ;
struct V_136 * V_137 = F_6 ( V_17 ) ;
if ( V_137 -> time == 0 )
return 1 ;
else
return 0 ;
}
static int F_49 ( const char * V_138 ,
struct V_3 * V_139 )
{
struct V_120 V_121 ;
int V_78 ;
V_78 = F_46 ( & V_121 , V_138 , V_139 -> V_7 . V_93 ,
V_139 -> V_7 . V_140 ) ;
if ( ! V_78 ) {
V_139 -> V_7 . V_141 = V_121 . V_13 ;
V_139 -> V_7 . V_142 = V_121 . V_124 ;
V_139 -> V_7 . V_125 = V_121 . V_125 ;
}
return V_78 ;
}
static int F_50 ( const int V_76 , struct V_85 * V_86 ,
struct V_1 * V_1 , char * * V_143 , int * V_144 )
{
T_3 V_77 ;
int V_78 = 0 ;
int V_145 = 0 ;
T_10 V_146 ;
T_10 V_147 = V_1 -> V_90 ;
struct V_3 * V_80 = V_1 -> V_5 ;
struct V_28 * V_29 = F_24 ( V_1 -> V_81 . V_10 -> V_82 ) ;
if ( ( V_80 == NULL ) || ( V_143 == NULL ) ||
( V_144 == NULL ) )
return - V_148 ;
* V_143 = NULL ;
V_146 =
V_80 -> V_7 . V_149 -
V_80 -> V_7 . V_150 ;
F_1 ( V_1 , L_12 ) ;
if ( ( ( V_147 < V_80 -> V_7 . V_149 ) &&
F_48 ( V_1 ) ) ||
( V_147 < V_146 ) ) {
F_2 ( 1 , L_13 ) ;
F_51 ( & V_151 ) ;
if ( ! V_80 -> V_7 . V_8 &&
! V_80 -> V_6 ) {
V_80 -> V_6 = true ;
F_52 ( & V_151 ) ;
F_53 ( V_76 , V_86 , V_80 -> V_106 ) ;
} else
F_52 ( & V_151 ) ;
if ( V_80 -> V_7 . V_152 ) {
F_2 ( 1 , L_14 ) ;
if ( V_80 -> V_7 . V_153 )
F_54 ( V_80 -> V_7 .
V_152 ) ;
else
F_55 ( V_80 -> V_7 .
V_152 ) ;
V_80 -> V_7 . V_152 = NULL ;
}
V_78 = F_23 ( V_76 , V_1 ) ;
if ( V_78 ) {
F_2 ( 1 , L_15 ,
V_78 ) ;
return V_78 ;
}
if ( V_80 -> V_7 . V_154 )
F_49 ( V_80 -> V_7 . V_154 ,
V_80 ) ;
}
V_77 = V_102 | V_103 ;
if ( F_31 ( V_29 ) )
V_77 |= V_104 ;
while ( ( V_147 >= V_80 -> V_7 . V_149 ) &&
( V_78 == 0 ) && ! V_80 -> V_7 . V_8 ) {
F_2 ( 1 , L_16 ) ;
V_78 = F_56 ( V_76 , V_86 , V_80 -> V_106 , V_77 ,
& V_80 -> V_7 ) ;
if ( V_80 -> V_7 . V_154 )
F_49 ( V_80 -> V_7 . V_154 ,
V_80 ) ;
if ( V_78 )
return - V_148 ;
}
if ( V_147 < V_80 -> V_7 . V_149 ) {
int V_155 ;
char * V_138 ;
char * V_113 = V_80 -> V_7 . V_152 +
F_57 ( (struct V_156 * )
V_80 -> V_7 . V_152 ) ;
V_138 = V_80 -> V_7 . V_157 ;
V_146 = V_80 -> V_7 . V_149
- V_80 -> V_7 . V_150 ;
V_145 = V_147 - V_146 ;
F_2 ( 1 , L_17 , V_145 ) ;
for ( V_155 = 0 ; ( V_155 < ( V_145 ) ) && ( V_138 != NULL ) ; V_155 ++ ) {
V_138 = F_37 ( V_138 , V_113 ,
V_80 -> V_7 . V_93 ) ;
}
if ( ( V_138 == NULL ) && ( V_155 < V_145 ) ) {
F_38 ( 1 , L_18
L_19 ,
V_145 , V_147 , V_78 ) ;
}
V_78 = 0 ;
* V_143 = V_138 ;
} else {
F_2 ( 1 , L_20 ) ;
return 0 ;
}
if ( V_145 >= V_80 -> V_7 . V_150 ) {
F_2 ( 1 , L_21 ) ;
* V_144 = 0 ;
} else
* V_144 = V_80 -> V_7 . V_150 - V_145 ;
return V_78 ;
}
static int F_58 ( char * V_158 , struct V_1 * V_1 , T_11 V_159 ,
void * V_160 , char * V_161 , unsigned int V_162 )
{
struct V_3 * V_139 = V_1 -> V_5 ;
struct V_18 * V_19 = V_1 -> V_81 . V_10 -> V_82 ;
struct V_28 * V_29 = F_24 ( V_19 ) ;
struct V_120 V_121 = { NULL , } ;
struct V_14 V_15 ;
struct V_10 * V_10 ;
struct V_12 V_13 ;
int V_78 = 0 ;
T_12 V_127 ;
V_78 = F_46 ( & V_121 , V_158 , V_139 -> V_7 . V_93 ,
V_139 -> V_7 . V_140 ) ;
if ( V_78 )
return V_78 ;
if ( V_121 . V_124 > V_162 ) {
F_38 ( 1 , L_22 ,
V_121 . V_124 ) ;
return - V_133 ;
}
if ( F_47 ( & V_121 , V_139 -> V_7 . V_140 ) )
return 0 ;
if ( V_139 -> V_7 . V_140 ) {
struct V_163 * V_164 = V_29 -> V_105 ;
V_13 . V_13 = V_161 ;
V_13 . V_25 =
F_59 ( ( char * ) V_13 . V_13 , ( T_4 * ) V_121 . V_13 ,
V_165 ,
F_60 ( V_166 , V_121 . V_124 ,
( V_166 ) V_162 ) , V_164 ,
V_29 -> V_46 &
V_107 ) ;
V_13 . V_25 -= F_61 ( V_164 ) ;
} else {
V_13 . V_13 = V_121 . V_13 ;
V_13 . V_25 = V_121 . V_124 ;
}
switch ( V_139 -> V_7 . V_93 ) {
case V_94 :
F_62 ( & V_15 ,
& ( ( T_5 * ) V_158 ) -> V_128 ,
V_29 ) ;
break;
case V_98 :
F_19 ( & V_15 ,
( T_2 * ) V_158 ,
V_29 ) ;
break;
default:
F_15 ( & V_15 ,
( T_1 * ) V_158 ,
V_29 ) ;
break;
}
if ( V_121 . V_127 && ( V_29 -> V_46 & V_99 ) ) {
V_15 . V_27 = V_121 . V_127 ;
} else {
V_15 . V_27 = F_63 ( V_19 , V_167 ) ;
F_64 ( V_29 ) ;
}
if ( ( V_29 -> V_46 & V_168 ) &&
F_65 ( & V_15 ) )
V_15 . V_53 |= V_54 ;
V_127 = F_66 ( V_15 . V_27 ) ;
V_10 = F_3 ( V_1 -> V_169 , & V_13 , & V_15 ) ;
V_78 = V_159 ( V_160 , V_13 . V_13 , V_13 . V_25 , V_1 -> V_90 , V_127 ,
V_15 . V_39 ) ;
F_9 ( V_10 ) ;
return V_78 ;
}
int F_67 ( struct V_1 * V_1 , void * V_170 , T_11 V_159 )
{
int V_78 = 0 ;
int V_76 , V_155 ;
struct V_85 * V_86 ;
struct V_3 * V_80 = NULL ;
char * V_138 ;
int V_171 = 0 ;
char * V_172 = NULL ;
char * V_113 ;
unsigned int V_162 ;
V_76 = F_68 () ;
if ( V_1 -> V_5 == NULL ) {
V_78 = F_23 ( V_76 , V_1 ) ;
F_2 ( 1 , L_23 , V_78 ) ;
if ( V_78 )
goto V_173;
}
switch ( ( int ) V_1 -> V_90 ) {
case 0 :
if ( V_159 ( V_170 , L_24 , 1 , V_1 -> V_90 ,
V_1 -> V_81 . V_10 -> V_20 -> V_174 , V_40 ) < 0 ) {
F_38 ( 1 , L_25 ) ;
V_78 = - V_88 ;
break;
}
V_1 -> V_90 ++ ;
case 1 :
if ( V_159 ( V_170 , L_26 , 2 , V_1 -> V_90 ,
F_69 ( V_1 -> V_81 . V_10 ) , V_40 ) < 0 ) {
F_38 ( 1 , L_27 ) ;
V_78 = - V_88 ;
break;
}
V_1 -> V_90 ++ ;
default:
if ( V_1 -> V_5 == NULL ) {
V_78 = - V_133 ;
F_70 ( V_76 ) ;
return V_78 ;
}
V_80 = V_1 -> V_5 ;
if ( V_80 -> V_7 . V_8 ) {
if ( V_80 -> V_7 . V_9 ) {
F_2 ( 1 , L_28 ) ;
V_78 = 0 ;
break;
}
}
V_86 = F_29 ( V_80 -> V_84 ) ;
V_78 = F_50 ( V_76 , V_86 , V_1 ,
& V_138 , & V_171 ) ;
if ( V_78 ) {
F_2 ( 1 , L_29 , V_78 ) ;
goto V_173;
} else if ( V_138 != NULL ) {
F_2 ( 1 , L_30 , V_1 -> V_90 ) ;
} else {
F_2 ( 1 , L_31 ) ;
goto V_173;
}
F_2 ( 1 , L_32 ,
V_171 , V_80 -> V_7 . V_152 ) ;
V_162 = F_57 ( (struct V_156 * )
V_80 -> V_7 . V_152 ) ;
V_113 = V_80 -> V_7 . V_152 + V_162 ;
V_172 = F_71 ( V_165 , V_87 ) ;
if ( V_172 == NULL ) {
V_78 = - V_88 ;
break;
}
for ( V_155 = 0 ; ( V_155 < V_171 ) && ( V_78 == 0 ) ; V_155 ++ ) {
if ( V_138 == NULL ) {
F_38 ( 1 , L_33 ,
V_171 , V_155 ) ;
break;
}
V_78 = F_58 ( V_138 , V_1 ,
V_159 , V_170 , V_172 , V_162 ) ;
if ( V_78 == - V_175 ) {
V_78 = 0 ;
break;
}
V_1 -> V_90 ++ ;
if ( V_1 -> V_90 ==
V_80 -> V_7 . V_149 ) {
F_2 ( 1 , L_34 ,
V_1 -> V_90 , V_172 ) ;
F_49 ( V_138 , V_80 ) ;
break;
} else
V_138 =
F_37 ( V_138 , V_113 ,
V_80 -> V_7 . V_93 ) ;
}
F_34 ( V_172 ) ;
break;
}
V_173:
F_70 ( V_76 ) ;
return V_78 ;
}
