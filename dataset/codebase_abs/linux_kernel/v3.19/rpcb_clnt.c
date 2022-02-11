static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_4 , V_3 ) ;
}
static void F_4 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
F_1 ( V_7 -> V_8 , V_7 -> V_9 ) ;
F_5 ( V_7 -> V_8 ) ;
F_6 ( V_7 -> V_10 ) ;
F_6 ( V_7 ) ;
}
static int F_7 ( struct V_11 * V_11 )
{
int V_12 ;
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
F_9 ( & V_14 -> V_16 ) ;
if ( V_14 -> V_17 )
V_14 -> V_17 ++ ;
V_12 = V_14 -> V_17 ;
F_10 ( & V_14 -> V_16 ) ;
return V_12 ;
}
void F_11 ( struct V_11 * V_11 )
{
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
struct V_18 * V_19 = V_14 -> V_20 ;
struct V_18 * V_21 = V_14 -> V_22 ;
int V_23 = 0 ;
F_9 ( & V_14 -> V_16 ) ;
if ( V_14 -> V_17 ) {
if ( -- V_14 -> V_17 == 0 ) {
V_14 -> V_20 = NULL ;
V_14 -> V_22 = NULL ;
}
V_23 = ! V_14 -> V_17 ;
}
F_10 ( & V_14 -> V_16 ) ;
if ( V_23 ) {
if ( V_21 )
F_12 ( V_21 ) ;
if ( V_19 )
F_12 ( V_19 ) ;
}
}
static void F_13 ( struct V_11 * V_11 , struct V_18 * V_19 ,
struct V_18 * V_21 ,
bool V_24 )
{
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
V_14 -> V_20 = V_19 ;
V_14 -> V_22 = V_21 ;
V_14 -> V_25 = V_24 ? 1 : 0 ;
F_14 () ;
V_14 -> V_17 = 1 ;
F_15 ( L_1
L_2 ,
V_14 -> V_20 , V_14 -> V_22 ,
V_11 , ( V_11 == & V_26 ) ? L_3 : L_4 ) ;
}
static int F_16 ( struct V_11 * V_11 )
{
static const struct V_27 V_28 = {
. V_29 = V_30 ,
. V_31 = V_32 ,
} ;
struct V_33 args = {
. V_11 = V_11 ,
. V_34 = V_35 ,
. V_36 = (struct V_37 * ) & V_28 ,
. V_38 = sizeof( V_28 ) ,
. V_39 = L_5 ,
. V_40 = & V_41 ,
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = V_47 ,
} ;
struct V_18 * V_19 , * V_21 ;
int V_48 = 0 ;
V_19 = F_17 ( & args ) ;
if ( F_18 ( V_19 ) ) {
F_15 ( L_6
L_7 , F_19 ( V_19 ) ) ;
V_48 = F_19 ( V_19 ) ;
goto V_49;
}
V_21 = F_20 ( V_19 , & V_41 , V_50 ) ;
if ( F_18 ( V_21 ) ) {
F_15 ( L_8
L_9 ,
F_19 ( V_21 ) ) ;
V_21 = NULL ;
}
F_13 ( V_11 , V_19 , V_21 , true ) ;
V_49:
return V_48 ;
}
static int F_21 ( struct V_11 * V_11 )
{
static const struct V_51 V_52 = {
. V_53 = V_54 ,
. V_55 . V_56 = F_22 ( V_57 ) ,
. V_58 = F_23 ( V_59 ) ,
} ;
struct V_33 args = {
. V_11 = V_11 ,
. V_34 = V_60 ,
. V_36 = (struct V_37 * ) & V_52 ,
. V_38 = sizeof( V_52 ) ,
. V_39 = L_5 ,
. V_40 = & V_41 ,
. V_42 = V_43 ,
. V_44 = V_61 ,
. V_46 = V_62 ,
} ;
struct V_18 * V_19 , * V_21 ;
int V_48 = 0 ;
V_19 = F_17 ( & args ) ;
if ( F_18 ( V_19 ) ) {
F_15 ( L_10
L_7 , F_19 ( V_19 ) ) ;
V_48 = F_19 ( V_19 ) ;
goto V_49;
}
V_21 = F_20 ( V_19 , & V_41 , V_50 ) ;
if ( F_18 ( V_21 ) ) {
F_15 ( L_8
L_9 ,
F_19 ( V_21 ) ) ;
V_21 = NULL ;
}
F_13 ( V_11 , V_19 , V_21 , false ) ;
V_49:
return V_48 ;
}
int F_24 ( struct V_11 * V_11 )
{
static F_25 ( V_63 ) ;
int V_48 = 0 ;
if ( F_7 ( V_11 ) )
return V_48 ;
F_26 ( & V_63 ) ;
if ( F_7 ( V_11 ) )
goto V_49;
if ( F_16 ( V_11 ) != 0 )
V_48 = F_21 ( V_11 ) ;
V_49:
F_27 ( & V_63 ) ;
return V_48 ;
}
static struct V_18 * F_28 ( struct V_11 * V_11 , const char * V_64 ,
struct V_37 * V_65 , T_1 V_66 ,
int V_67 , T_2 V_42 )
{
struct V_33 args = {
. V_11 = V_11 ,
. V_34 = V_67 ,
. V_36 = V_65 ,
. V_38 = V_66 ,
. V_39 = V_64 ,
. V_40 = & V_41 ,
. V_42 = V_42 ,
. V_44 = V_61 ,
. V_46 = ( V_62 |
V_68 ) ,
} ;
switch ( V_65 -> V_69 ) {
case V_54 :
( (struct V_51 * ) V_65 ) -> V_58 = F_23 ( V_59 ) ;
break;
case V_70 :
( (struct V_71 * ) V_65 ) -> V_72 = F_23 ( V_59 ) ;
break;
default:
return F_29 ( - V_73 ) ;
}
return F_17 ( & args ) ;
}
static int F_30 ( struct V_13 * V_14 , struct V_18 * V_19 , struct V_74 * V_75 , bool V_76 )
{
int V_46 = V_77 ;
int error , V_48 = 0 ;
if ( V_76 || ! V_14 -> V_25 )
V_46 = V_78 ;
V_75 -> V_79 = & V_48 ;
error = F_31 ( V_19 , V_75 , V_46 ) ;
if ( error < 0 ) {
F_15 ( L_11
L_12 , - error ) ;
return error ;
}
if ( ! V_48 )
return - V_80 ;
return 0 ;
}
int F_32 ( struct V_11 * V_11 , T_2 V_81 , T_2 V_82 , int V_83 , unsigned short V_84 )
{
struct V_6 V_7 = {
. V_85 = V_81 ,
. V_86 = V_82 ,
. V_87 = V_83 ,
. V_88 = V_84 ,
} ;
struct V_74 V_75 = {
. V_89 = & V_7 ,
} ;
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
bool V_76 = false ;
F_15 ( L_13
L_14 , ( V_84 ? L_4 : L_15 ) ,
V_81 , V_82 , V_83 , V_84 ) ;
V_75 . V_90 = & V_91 [ V_92 ] ;
if ( V_84 != 0 ) {
V_75 . V_90 = & V_91 [ V_93 ] ;
V_76 = true ;
}
return F_30 ( V_14 , V_14 -> V_20 , & V_75 , V_76 ) ;
}
static int F_33 ( struct V_13 * V_14 ,
const struct V_37 * V_94 ,
struct V_74 * V_75 )
{
const struct V_51 * sin = ( const struct V_51 * ) V_94 ;
struct V_6 * V_7 = V_75 -> V_89 ;
unsigned short V_84 = F_34 ( sin -> V_58 ) ;
bool V_76 = false ;
int V_48 ;
V_7 -> V_10 = F_35 ( V_94 , V_95 ) ;
F_15 ( L_16
L_17 , ( V_84 ? L_4 : L_15 ) ,
V_7 -> V_85 , V_7 -> V_86 ,
V_7 -> V_10 , V_7 -> V_96 ) ;
V_75 -> V_90 = & V_97 [ V_92 ] ;
if ( V_84 != 0 ) {
V_75 -> V_90 = & V_97 [ V_93 ] ;
V_76 = true ;
}
V_48 = F_30 ( V_14 , V_14 -> V_22 , V_75 , V_76 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_48 ;
}
static int F_36 ( struct V_13 * V_14 ,
const struct V_37 * V_94 ,
struct V_74 * V_75 )
{
const struct V_71 * V_98 = ( const struct V_71 * ) V_94 ;
struct V_6 * V_7 = V_75 -> V_89 ;
unsigned short V_84 = F_34 ( V_98 -> V_72 ) ;
bool V_76 = false ;
int V_48 ;
V_7 -> V_10 = F_35 ( V_94 , V_95 ) ;
F_15 ( L_16
L_17 , ( V_84 ? L_4 : L_15 ) ,
V_7 -> V_85 , V_7 -> V_86 ,
V_7 -> V_10 , V_7 -> V_96 ) ;
V_75 -> V_90 = & V_97 [ V_92 ] ;
if ( V_84 != 0 ) {
V_75 -> V_90 = & V_97 [ V_93 ] ;
V_76 = true ;
}
V_48 = F_30 ( V_14 , V_14 -> V_22 , V_75 , V_76 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_48 ;
}
static int F_37 ( struct V_13 * V_14 ,
struct V_74 * V_75 )
{
struct V_6 * V_7 = V_75 -> V_89 ;
F_15 ( L_18
L_17 ,
V_7 -> V_85 , V_7 -> V_86 , V_7 -> V_96 ) ;
V_7 -> V_10 = L_4 ;
V_75 -> V_90 = & V_97 [ V_92 ] ;
return F_30 ( V_14 , V_14 -> V_22 , V_75 , false ) ;
}
int F_38 ( struct V_11 * V_11 , const T_2 V_40 , const T_2 V_42 ,
const struct V_37 * V_36 , const char * V_99 )
{
struct V_6 V_7 = {
. V_85 = V_40 ,
. V_86 = V_42 ,
. V_96 = V_99 ,
. V_100 = V_101 ,
} ;
struct V_74 V_75 = {
. V_89 = & V_7 ,
} ;
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
if ( V_14 -> V_22 == NULL )
return - V_102 ;
if ( V_36 == NULL )
return F_37 ( V_14 , & V_75 ) ;
switch ( V_36 -> V_69 ) {
case V_54 :
return F_33 ( V_14 , V_36 , & V_75 ) ;
case V_70 :
return F_36 ( V_14 , V_36 , & V_75 ) ;
}
return - V_73 ;
}
static struct V_103 * F_39 ( struct V_18 * V_104 , struct V_6 * V_7 , struct V_105 * V_106 )
{
struct V_74 V_75 = {
. V_90 = V_106 ,
. V_89 = V_7 ,
. V_79 = V_7 ,
} ;
struct V_107 V_108 = {
. V_109 = V_104 ,
. V_74 = & V_75 ,
. V_110 = & V_111 ,
. V_112 = V_7 ,
. V_46 = V_113 | V_78 ,
} ;
return F_40 ( & V_108 ) ;
}
static struct V_18 * F_41 ( struct V_18 * V_19 )
{
struct V_18 * V_114 = V_19 -> V_115 ;
struct V_1 * V_2 = F_42 ( V_19 -> V_116 ) ;
while ( V_114 != V_19 ) {
if ( F_42 ( V_114 -> V_116 ) != V_2 )
break;
if ( V_19 -> V_117 )
break;
V_19 = V_114 ;
V_114 = V_114 -> V_115 ;
}
return V_19 ;
}
void F_43 ( struct V_103 * V_118 )
{
struct V_18 * V_19 ;
struct V_105 * V_106 ;
T_2 V_119 ;
struct V_1 * V_2 ;
struct V_18 * V_104 ;
struct V_6 * V_7 ;
struct V_103 * V_120 ;
struct V_121 V_122 ;
struct V_37 * V_94 = (struct V_37 * ) & V_122 ;
T_1 V_66 ;
int V_3 ;
F_44 () ;
do {
V_19 = F_41 ( V_118 -> V_123 ) ;
V_2 = F_45 ( F_42 ( V_19 -> V_116 ) ) ;
} while ( V_2 == NULL );
F_46 () ;
F_15 ( L_19 ,
V_118 -> V_124 , V_125 ,
V_2 -> V_39 , V_19 -> V_126 , V_19 -> V_127 , V_2 -> V_83 ) ;
F_47 ( & V_2 -> V_4 , V_118 , NULL ) ;
if ( F_48 ( V_2 ) ) {
F_15 ( L_20 ,
V_118 -> V_124 , V_125 ) ;
F_5 ( V_2 ) ;
return;
}
if ( F_49 ( V_2 ) ) {
V_3 = 0 ;
F_15 ( L_21 ,
V_118 -> V_124 , V_125 ) ;
goto V_128;
}
V_66 = F_50 ( V_19 , V_94 , sizeof( V_122 ) ) ;
switch ( V_94 -> V_69 ) {
case V_54 :
V_106 = V_129 [ V_2 -> V_130 ] . V_90 ;
V_119 = V_129 [ V_2 -> V_130 ] . V_131 ;
break;
case V_70 :
V_106 = V_132 [ V_2 -> V_130 ] . V_90 ;
V_119 = V_132 [ V_2 -> V_130 ] . V_131 ;
break;
default:
V_3 = - V_73 ;
F_15 ( L_22 ,
V_118 -> V_124 , V_125 ) ;
goto V_128;
}
if ( V_106 == NULL ) {
V_2 -> V_130 = 0 ;
V_3 = - V_133 ;
F_15 ( L_23 ,
V_118 -> V_124 , V_125 ) ;
goto V_128;
}
F_15 ( L_24 ,
V_118 -> V_124 , V_125 , V_119 ) ;
V_104 = F_28 ( V_2 -> V_134 , V_2 -> V_39 , V_94 , V_66 ,
V_2 -> V_83 , V_119 ) ;
if ( F_18 ( V_104 ) ) {
V_3 = F_19 ( V_104 ) ;
F_15 ( L_25 ,
V_118 -> V_124 , V_125 , F_19 ( V_104 ) ) ;
goto V_128;
}
V_7 = F_51 ( sizeof( struct V_6 ) , V_135 ) ;
if ( ! V_7 ) {
V_3 = - V_136 ;
F_15 ( L_26 ,
V_118 -> V_124 , V_125 ) ;
goto V_137;
}
V_7 -> V_85 = V_19 -> V_126 ;
V_7 -> V_86 = V_19 -> V_127 ;
V_7 -> V_87 = V_2 -> V_83 ;
V_7 -> V_88 = 0 ;
V_7 -> V_8 = V_2 ;
V_7 -> V_9 = - V_138 ;
switch ( V_119 ) {
case V_50 :
case V_139 :
V_7 -> V_96 = V_2 -> V_140 [ V_141 ] ;
V_7 -> V_10 = F_35 ( V_94 , V_135 ) ;
V_7 -> V_100 = L_4 ;
break;
case V_43 :
V_7 -> V_10 = NULL ;
break;
default:
F_52 () ;
}
V_120 = F_39 ( V_104 , V_7 , V_106 ) ;
F_53 ( V_104 ) ;
if ( F_18 ( V_120 ) ) {
F_15 ( L_27 ,
V_118 -> V_124 , V_125 ) ;
return;
}
V_2 -> V_142 . V_143 ++ ;
F_54 ( V_120 ) ;
return;
V_137:
F_53 ( V_104 ) ;
V_128:
F_1 ( V_2 , V_3 ) ;
V_118 -> V_144 = V_3 ;
F_5 ( V_2 ) ;
}
static void F_55 ( struct V_103 * V_120 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
struct V_1 * V_2 = V_7 -> V_8 ;
int V_3 = V_120 -> V_144 ;
if ( V_3 == - V_138 )
V_3 = - V_102 ;
if ( V_3 == - V_102 )
V_2 -> V_130 ++ ;
if ( V_3 < 0 ) {
V_2 -> V_145 -> V_146 ( V_2 , 0 ) ;
} else if ( V_7 -> V_88 == 0 ) {
V_2 -> V_145 -> V_146 ( V_2 , 0 ) ;
V_3 = - V_80 ;
} else {
V_2 -> V_145 -> V_146 ( V_2 , V_7 -> V_88 ) ;
F_56 ( V_2 ) ;
V_3 = 0 ;
}
F_15 ( L_28 ,
V_120 -> V_124 , V_3 , V_7 -> V_88 ) ;
V_7 -> V_9 = V_3 ;
}
static void F_57 ( struct V_147 * V_148 , struct V_149 * V_150 ,
const struct V_6 * V_151 )
{
T_3 * V_152 ;
F_15 ( L_29 ,
V_148 -> V_153 -> V_124 ,
V_148 -> V_153 -> V_154 . V_90 -> V_155 ,
V_151 -> V_85 , V_151 -> V_86 , V_151 -> V_87 , V_151 -> V_88 ) ;
V_152 = F_58 ( V_150 , V_156 << 2 ) ;
* V_152 ++ = F_59 ( V_151 -> V_85 ) ;
* V_152 ++ = F_59 ( V_151 -> V_86 ) ;
* V_152 ++ = F_59 ( V_151 -> V_87 ) ;
* V_152 = F_59 ( V_151 -> V_88 ) ;
}
static int F_60 ( struct V_147 * V_148 , struct V_149 * V_150 ,
struct V_6 * V_151 )
{
unsigned long V_84 ;
T_3 * V_152 ;
V_151 -> V_88 = 0 ;
V_152 = F_61 ( V_150 , 4 ) ;
if ( F_62 ( V_152 == NULL ) )
return - V_138 ;
V_84 = F_63 ( V_152 ) ;
F_15 ( L_30 , V_148 -> V_153 -> V_124 ,
V_148 -> V_153 -> V_154 . V_90 -> V_155 , V_84 ) ;
if ( F_62 ( V_84 > V_157 ) )
return - V_138 ;
V_151 -> V_88 = V_84 ;
return 0 ;
}
static int F_64 ( struct V_147 * V_148 , struct V_149 * V_150 ,
unsigned int * V_158 )
{
T_3 * V_152 ;
V_152 = F_61 ( V_150 , 4 ) ;
if ( F_62 ( V_152 == NULL ) )
return - V_138 ;
* V_158 = 0 ;
if ( * V_152 != V_159 )
* V_158 = 1 ;
F_15 ( L_31 ,
V_148 -> V_153 -> V_124 ,
V_148 -> V_153 -> V_154 . V_90 -> V_155 ,
( * V_158 ? L_32 : L_33 ) ) ;
return 0 ;
}
static void F_65 ( struct V_149 * V_150 , const char * string ,
const T_2 V_160 )
{
T_3 * V_152 ;
T_2 V_161 ;
V_161 = strlen ( string ) ;
F_66 ( V_161 > V_160 ) ;
if ( V_161 > V_160 )
V_161 = V_160 ;
V_152 = F_58 ( V_150 , 4 + V_161 ) ;
F_67 ( V_152 , string , V_161 ) ;
}
static void F_68 ( struct V_147 * V_148 , struct V_149 * V_150 ,
const struct V_6 * V_151 )
{
T_3 * V_152 ;
F_15 ( L_34 ,
V_148 -> V_153 -> V_124 ,
V_148 -> V_153 -> V_154 . V_90 -> V_155 ,
V_151 -> V_85 , V_151 -> V_86 ,
V_151 -> V_96 , V_151 -> V_10 ) ;
V_152 = F_58 ( V_150 , ( V_162 + V_163 ) << 2 ) ;
* V_152 ++ = F_59 ( V_151 -> V_85 ) ;
* V_152 = F_59 ( V_151 -> V_86 ) ;
F_65 ( V_150 , V_151 -> V_96 , V_164 ) ;
F_65 ( V_150 , V_151 -> V_10 , V_165 ) ;
F_65 ( V_150 , V_151 -> V_100 , V_166 ) ;
}
static int F_69 ( struct V_147 * V_148 , struct V_149 * V_150 ,
struct V_6 * V_151 )
{
struct V_121 V_36 ;
struct V_37 * V_94 = (struct V_37 * ) & V_36 ;
T_3 * V_152 ;
T_2 V_161 ;
V_151 -> V_88 = 0 ;
V_152 = F_61 ( V_150 , 4 ) ;
if ( F_62 ( V_152 == NULL ) )
goto V_167;
V_161 = F_63 ( V_152 ) ;
if ( V_161 == 0 ) {
F_15 ( L_35 ,
V_148 -> V_153 -> V_124 ) ;
return 0 ;
}
if ( F_62 ( V_161 > V_165 ) )
goto V_167;
V_152 = F_61 ( V_150 , V_161 ) ;
if ( F_62 ( V_152 == NULL ) )
goto V_167;
F_15 ( L_36 , V_148 -> V_153 -> V_124 ,
V_148 -> V_153 -> V_154 . V_90 -> V_155 , ( char * ) V_152 ) ;
if ( F_70 ( V_148 -> V_168 -> V_134 , ( char * ) V_152 , V_161 ,
V_94 , sizeof( V_36 ) ) == 0 )
goto V_167;
V_151 -> V_88 = F_71 ( V_94 ) ;
return 0 ;
V_167:
F_15 ( L_37 ,
V_148 -> V_153 -> V_124 ,
V_148 -> V_153 -> V_154 . V_90 -> V_155 ) ;
return - V_138 ;
}
