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
const char * V_65 ,
struct V_37 * V_66 , T_1 V_67 ,
int V_68 , T_2 V_42 )
{
struct V_33 args = {
. V_11 = V_11 ,
. V_34 = V_68 ,
. V_36 = V_66 ,
. V_38 = V_67 ,
. V_39 = V_65 ,
. V_64 = V_64 ,
. V_40 = & V_41 ,
. V_42 = V_42 ,
. V_44 = V_61 ,
. V_46 = ( V_62 |
V_69 ) ,
} ;
switch ( V_66 -> V_70 ) {
case V_54 :
( (struct V_51 * ) V_66 ) -> V_58 = F_23 ( V_59 ) ;
break;
case V_71 :
( (struct V_72 * ) V_66 ) -> V_73 = F_23 ( V_59 ) ;
break;
default:
return F_29 ( - V_74 ) ;
}
return F_17 ( & args ) ;
}
static int F_30 ( struct V_13 * V_14 , struct V_18 * V_19 , struct V_75 * V_76 , bool V_77 )
{
int V_46 = V_78 ;
int error , V_48 = 0 ;
if ( V_77 || ! V_14 -> V_25 )
V_46 = V_79 ;
V_76 -> V_80 = & V_48 ;
error = F_31 ( V_19 , V_76 , V_46 ) ;
if ( error < 0 ) {
F_15 ( L_11
L_12 , - error ) ;
return error ;
}
if ( ! V_48 )
return - V_81 ;
return 0 ;
}
int F_32 ( struct V_11 * V_11 , T_2 V_82 , T_2 V_83 , int V_84 , unsigned short V_85 )
{
struct V_6 V_7 = {
. V_86 = V_82 ,
. V_87 = V_83 ,
. V_88 = V_84 ,
. V_89 = V_85 ,
} ;
struct V_75 V_76 = {
. V_90 = & V_7 ,
} ;
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
bool V_77 = false ;
F_15 ( L_13
L_14 , ( V_85 ? L_4 : L_15 ) ,
V_82 , V_83 , V_84 , V_85 ) ;
V_76 . V_91 = & V_92 [ V_93 ] ;
if ( V_85 != 0 ) {
V_76 . V_91 = & V_92 [ V_94 ] ;
V_77 = true ;
}
return F_30 ( V_14 , V_14 -> V_20 , & V_76 , V_77 ) ;
}
static int F_33 ( struct V_13 * V_14 ,
const struct V_37 * V_95 ,
struct V_75 * V_76 )
{
const struct V_51 * sin = ( const struct V_51 * ) V_95 ;
struct V_6 * V_7 = V_76 -> V_90 ;
unsigned short V_85 = F_34 ( sin -> V_58 ) ;
bool V_77 = false ;
int V_48 ;
V_7 -> V_10 = F_35 ( V_95 , V_96 ) ;
F_15 ( L_16
L_17 , ( V_85 ? L_4 : L_15 ) ,
V_7 -> V_86 , V_7 -> V_87 ,
V_7 -> V_10 , V_7 -> V_97 ) ;
V_76 -> V_91 = & V_98 [ V_93 ] ;
if ( V_85 != 0 ) {
V_76 -> V_91 = & V_98 [ V_94 ] ;
V_77 = true ;
}
V_48 = F_30 ( V_14 , V_14 -> V_22 , V_76 , V_77 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_48 ;
}
static int F_36 ( struct V_13 * V_14 ,
const struct V_37 * V_95 ,
struct V_75 * V_76 )
{
const struct V_72 * V_99 = ( const struct V_72 * ) V_95 ;
struct V_6 * V_7 = V_76 -> V_90 ;
unsigned short V_85 = F_34 ( V_99 -> V_73 ) ;
bool V_77 = false ;
int V_48 ;
V_7 -> V_10 = F_35 ( V_95 , V_96 ) ;
F_15 ( L_16
L_17 , ( V_85 ? L_4 : L_15 ) ,
V_7 -> V_86 , V_7 -> V_87 ,
V_7 -> V_10 , V_7 -> V_97 ) ;
V_76 -> V_91 = & V_98 [ V_93 ] ;
if ( V_85 != 0 ) {
V_76 -> V_91 = & V_98 [ V_94 ] ;
V_77 = true ;
}
V_48 = F_30 ( V_14 , V_14 -> V_22 , V_76 , V_77 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_48 ;
}
static int F_37 ( struct V_13 * V_14 ,
struct V_75 * V_76 )
{
struct V_6 * V_7 = V_76 -> V_90 ;
F_15 ( L_18
L_17 ,
V_7 -> V_86 , V_7 -> V_87 , V_7 -> V_97 ) ;
V_7 -> V_10 = L_4 ;
V_76 -> V_91 = & V_98 [ V_93 ] ;
return F_30 ( V_14 , V_14 -> V_22 , V_76 , false ) ;
}
int F_38 ( struct V_11 * V_11 , const T_2 V_40 , const T_2 V_42 ,
const struct V_37 * V_36 , const char * V_100 )
{
struct V_6 V_7 = {
. V_86 = V_40 ,
. V_87 = V_42 ,
. V_97 = V_100 ,
. V_101 = V_102 ,
} ;
struct V_75 V_76 = {
. V_90 = & V_7 ,
} ;
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
if ( V_14 -> V_22 == NULL )
return - V_103 ;
if ( V_36 == NULL )
return F_37 ( V_14 , & V_76 ) ;
switch ( V_36 -> V_70 ) {
case V_54 :
return F_33 ( V_14 , V_36 , & V_76 ) ;
case V_71 :
return F_36 ( V_14 , V_36 , & V_76 ) ;
}
return - V_74 ;
}
static struct V_104 * F_39 ( struct V_18 * V_105 , struct V_6 * V_7 , struct V_106 * V_107 )
{
struct V_75 V_76 = {
. V_91 = V_107 ,
. V_90 = V_7 ,
. V_80 = V_7 ,
} ;
struct V_108 V_109 = {
. V_110 = V_105 ,
. V_75 = & V_76 ,
. V_111 = & V_112 ,
. V_113 = V_7 ,
. V_46 = V_114 | V_79 ,
} ;
return F_40 ( & V_109 ) ;
}
static struct V_18 * F_41 ( struct V_18 * V_19 )
{
struct V_18 * V_115 = V_19 -> V_116 ;
struct V_1 * V_2 = F_42 ( V_19 -> V_117 ) ;
while ( V_115 != V_19 ) {
if ( F_42 ( V_115 -> V_117 ) != V_2 )
break;
if ( V_19 -> V_118 )
break;
V_19 = V_115 ;
V_115 = V_115 -> V_116 ;
}
return V_19 ;
}
void F_43 ( struct V_104 * V_119 )
{
struct V_18 * V_19 ;
struct V_106 * V_107 ;
T_2 V_120 ;
struct V_1 * V_2 ;
struct V_18 * V_105 ;
struct V_6 * V_7 ;
struct V_104 * V_121 ;
struct V_122 V_123 ;
struct V_37 * V_95 = (struct V_37 * ) & V_123 ;
T_1 V_67 ;
int V_3 ;
F_44 () ;
do {
V_19 = F_41 ( V_119 -> V_124 ) ;
V_2 = F_45 ( F_42 ( V_19 -> V_117 ) ) ;
} while ( V_2 == NULL );
F_46 () ;
F_15 ( L_19 ,
V_119 -> V_125 , V_126 ,
V_2 -> V_39 , V_19 -> V_127 , V_19 -> V_128 , V_2 -> V_84 ) ;
F_47 ( & V_2 -> V_4 , V_119 , NULL ) ;
if ( F_48 ( V_2 ) ) {
F_15 ( L_20 ,
V_119 -> V_125 , V_126 ) ;
F_5 ( V_2 ) ;
return;
}
if ( F_49 ( V_2 ) ) {
V_3 = 0 ;
F_15 ( L_21 ,
V_119 -> V_125 , V_126 ) ;
goto V_129;
}
V_67 = F_50 ( V_19 , V_95 , sizeof( V_123 ) ) ;
switch ( V_95 -> V_70 ) {
case V_54 :
V_107 = V_130 [ V_2 -> V_131 ] . V_91 ;
V_120 = V_130 [ V_2 -> V_131 ] . V_132 ;
break;
case V_71 :
V_107 = V_133 [ V_2 -> V_131 ] . V_91 ;
V_120 = V_133 [ V_2 -> V_131 ] . V_132 ;
break;
default:
V_3 = - V_74 ;
F_15 ( L_22 ,
V_119 -> V_125 , V_126 ) ;
goto V_129;
}
if ( V_107 == NULL ) {
V_2 -> V_131 = 0 ;
V_3 = - V_134 ;
F_15 ( L_23 ,
V_119 -> V_125 , V_126 ) ;
goto V_129;
}
F_15 ( L_24 ,
V_119 -> V_125 , V_126 , V_120 ) ;
V_105 = F_28 ( V_2 -> V_135 ,
V_19 -> V_136 ,
V_2 -> V_39 , V_95 , V_67 ,
V_2 -> V_84 , V_120 ) ;
if ( F_18 ( V_105 ) ) {
V_3 = F_19 ( V_105 ) ;
F_15 ( L_25 ,
V_119 -> V_125 , V_126 , F_19 ( V_105 ) ) ;
goto V_129;
}
V_7 = F_51 ( sizeof( struct V_6 ) , V_137 ) ;
if ( ! V_7 ) {
V_3 = - V_138 ;
F_15 ( L_26 ,
V_119 -> V_125 , V_126 ) ;
goto V_139;
}
V_7 -> V_86 = V_19 -> V_127 ;
V_7 -> V_87 = V_19 -> V_128 ;
V_7 -> V_88 = V_2 -> V_84 ;
V_7 -> V_89 = 0 ;
V_7 -> V_8 = V_2 ;
V_7 -> V_9 = - V_140 ;
switch ( V_120 ) {
case V_50 :
case V_141 :
V_7 -> V_97 = V_2 -> V_142 [ V_143 ] ;
V_7 -> V_10 = F_35 ( V_95 , V_137 ) ;
V_7 -> V_101 = L_4 ;
break;
case V_43 :
V_7 -> V_10 = NULL ;
break;
default:
F_52 () ;
}
V_121 = F_39 ( V_105 , V_7 , V_107 ) ;
F_53 ( V_105 ) ;
if ( F_18 ( V_121 ) ) {
F_15 ( L_27 ,
V_119 -> V_125 , V_126 ) ;
return;
}
V_2 -> V_144 . V_145 ++ ;
F_54 ( V_121 ) ;
return;
V_139:
F_53 ( V_105 ) ;
V_129:
F_1 ( V_2 , V_3 ) ;
V_119 -> V_146 = V_3 ;
F_5 ( V_2 ) ;
}
static void F_55 ( struct V_104 * V_121 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
struct V_1 * V_2 = V_7 -> V_8 ;
int V_3 = V_121 -> V_146 ;
if ( V_3 == - V_140 )
V_3 = - V_103 ;
if ( V_3 == - V_103 )
V_2 -> V_131 ++ ;
if ( V_3 < 0 ) {
V_2 -> V_147 -> V_148 ( V_2 , 0 ) ;
} else if ( V_7 -> V_89 == 0 ) {
V_2 -> V_147 -> V_148 ( V_2 , 0 ) ;
V_3 = - V_81 ;
} else {
V_2 -> V_147 -> V_148 ( V_2 , V_7 -> V_89 ) ;
F_56 ( V_2 ) ;
V_3 = 0 ;
}
F_15 ( L_28 ,
V_121 -> V_125 , V_3 , V_7 -> V_89 ) ;
V_7 -> V_9 = V_3 ;
}
static void F_57 ( struct V_149 * V_150 , struct V_151 * V_152 ,
const struct V_6 * V_153 )
{
T_3 * V_154 ;
F_15 ( L_29 ,
V_150 -> V_155 -> V_125 ,
V_150 -> V_155 -> V_156 . V_91 -> V_157 ,
V_153 -> V_86 , V_153 -> V_87 , V_153 -> V_88 , V_153 -> V_89 ) ;
V_154 = F_58 ( V_152 , V_158 << 2 ) ;
* V_154 ++ = F_59 ( V_153 -> V_86 ) ;
* V_154 ++ = F_59 ( V_153 -> V_87 ) ;
* V_154 ++ = F_59 ( V_153 -> V_88 ) ;
* V_154 = F_59 ( V_153 -> V_89 ) ;
}
static int F_60 ( struct V_149 * V_150 , struct V_151 * V_152 ,
struct V_6 * V_153 )
{
unsigned long V_85 ;
T_3 * V_154 ;
V_153 -> V_89 = 0 ;
V_154 = F_61 ( V_152 , 4 ) ;
if ( F_62 ( V_154 == NULL ) )
return - V_140 ;
V_85 = F_63 ( V_154 ) ;
F_15 ( L_30 , V_150 -> V_155 -> V_125 ,
V_150 -> V_155 -> V_156 . V_91 -> V_157 , V_85 ) ;
if ( F_62 ( V_85 > V_159 ) )
return - V_140 ;
V_153 -> V_89 = V_85 ;
return 0 ;
}
static int F_64 ( struct V_149 * V_150 , struct V_151 * V_152 ,
unsigned int * V_160 )
{
T_3 * V_154 ;
V_154 = F_61 ( V_152 , 4 ) ;
if ( F_62 ( V_154 == NULL ) )
return - V_140 ;
* V_160 = 0 ;
if ( * V_154 != V_161 )
* V_160 = 1 ;
F_15 ( L_31 ,
V_150 -> V_155 -> V_125 ,
V_150 -> V_155 -> V_156 . V_91 -> V_157 ,
( * V_160 ? L_32 : L_33 ) ) ;
return 0 ;
}
static void F_65 ( struct V_151 * V_152 , const char * string ,
const T_2 V_162 )
{
T_3 * V_154 ;
T_2 V_163 ;
V_163 = strlen ( string ) ;
F_66 ( V_163 > V_162 ) ;
if ( V_163 > V_162 )
V_163 = V_162 ;
V_154 = F_58 ( V_152 , 4 + V_163 ) ;
F_67 ( V_154 , string , V_163 ) ;
}
static void F_68 ( struct V_149 * V_150 , struct V_151 * V_152 ,
const struct V_6 * V_153 )
{
T_3 * V_154 ;
F_15 ( L_34 ,
V_150 -> V_155 -> V_125 ,
V_150 -> V_155 -> V_156 . V_91 -> V_157 ,
V_153 -> V_86 , V_153 -> V_87 ,
V_153 -> V_97 , V_153 -> V_10 ) ;
V_154 = F_58 ( V_152 , ( V_164 + V_165 ) << 2 ) ;
* V_154 ++ = F_59 ( V_153 -> V_86 ) ;
* V_154 = F_59 ( V_153 -> V_87 ) ;
F_65 ( V_152 , V_153 -> V_97 , V_166 ) ;
F_65 ( V_152 , V_153 -> V_10 , V_167 ) ;
F_65 ( V_152 , V_153 -> V_101 , V_168 ) ;
}
static int F_69 ( struct V_149 * V_150 , struct V_151 * V_152 ,
struct V_6 * V_153 )
{
struct V_122 V_36 ;
struct V_37 * V_95 = (struct V_37 * ) & V_36 ;
T_3 * V_154 ;
T_2 V_163 ;
V_153 -> V_89 = 0 ;
V_154 = F_61 ( V_152 , 4 ) ;
if ( F_62 ( V_154 == NULL ) )
goto V_169;
V_163 = F_63 ( V_154 ) ;
if ( V_163 == 0 ) {
F_15 ( L_35 ,
V_150 -> V_155 -> V_125 ) ;
return 0 ;
}
if ( F_62 ( V_163 > V_167 ) )
goto V_169;
V_154 = F_61 ( V_152 , V_163 ) ;
if ( F_62 ( V_154 == NULL ) )
goto V_169;
F_15 ( L_36 , V_150 -> V_155 -> V_125 ,
V_150 -> V_155 -> V_156 . V_91 -> V_157 , ( char * ) V_154 ) ;
if ( F_70 ( V_150 -> V_170 -> V_135 , ( char * ) V_154 , V_163 ,
V_95 , sizeof( V_36 ) ) == 0 )
goto V_169;
V_153 -> V_89 = F_71 ( V_95 ) ;
return 0 ;
V_169:
F_15 ( L_37 ,
V_150 -> V_155 -> V_125 ,
V_150 -> V_155 -> V_156 . V_91 -> V_157 ) ;
return - V_140 ;
}
