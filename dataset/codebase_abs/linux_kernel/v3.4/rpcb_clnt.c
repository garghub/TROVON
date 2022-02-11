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
int V_23 ;
F_9 ( & V_14 -> V_16 ) ;
if ( -- V_14 -> V_17 == 0 ) {
V_14 -> V_20 = NULL ;
V_14 -> V_22 = NULL ;
}
V_23 = ! V_14 -> V_17 ;
F_10 ( & V_14 -> V_16 ) ;
if ( V_23 ) {
if ( V_21 )
F_12 ( V_21 ) ;
if ( V_19 )
F_12 ( V_19 ) ;
}
}
static void F_13 ( struct V_11 * V_11 , struct V_18 * V_19 ,
struct V_18 * V_21 )
{
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
V_14 -> V_20 = V_19 ;
V_14 -> V_22 = V_21 ;
F_14 () ;
V_14 -> V_17 = 1 ;
F_15 ( L_1
L_2 ,
V_14 -> V_20 , V_14 -> V_22 ,
V_11 , ( V_11 == & V_24 ) ? L_3 : L_4 ) ;
}
static int F_16 ( struct V_11 * V_11 )
{
static const struct V_25 V_26 = {
. V_27 = V_28 ,
. V_29 = V_30 ,
} ;
struct V_31 args = {
. V_11 = V_11 ,
. V_32 = V_33 ,
. V_34 = (struct V_35 * ) & V_26 ,
. V_36 = sizeof( V_26 ) ,
. V_37 = L_5 ,
. V_38 = & V_39 ,
. V_40 = V_41 ,
. V_42 = V_43 ,
} ;
struct V_18 * V_19 , * V_21 ;
int V_44 = 0 ;
V_19 = F_17 ( & args ) ;
if ( F_18 ( V_19 ) ) {
F_15 ( L_6
L_7 , F_19 ( V_19 ) ) ;
V_44 = - F_19 ( V_19 ) ;
goto V_45;
}
V_21 = F_20 ( V_19 , & V_39 , V_46 ) ;
if ( F_18 ( V_21 ) ) {
F_15 ( L_8
L_9 ,
F_19 ( V_21 ) ) ;
V_21 = NULL ;
}
F_13 ( V_11 , V_19 , V_21 ) ;
V_45:
return V_44 ;
}
static int F_21 ( struct V_11 * V_11 )
{
static const struct V_47 V_48 = {
. V_49 = V_50 ,
. V_51 . V_52 = F_22 ( V_53 ) ,
. V_54 = F_23 ( V_55 ) ,
} ;
struct V_31 args = {
. V_11 = V_11 ,
. V_32 = V_56 ,
. V_34 = (struct V_35 * ) & V_48 ,
. V_36 = sizeof( V_48 ) ,
. V_37 = L_5 ,
. V_38 = & V_39 ,
. V_40 = V_41 ,
. V_42 = V_57 ,
. V_58 = V_59 ,
} ;
struct V_18 * V_19 , * V_21 ;
int V_44 = 0 ;
V_19 = F_17 ( & args ) ;
if ( F_18 ( V_19 ) ) {
F_15 ( L_10
L_7 , F_19 ( V_19 ) ) ;
V_44 = - F_19 ( V_19 ) ;
goto V_45;
}
V_21 = F_20 ( V_19 , & V_39 , V_46 ) ;
if ( F_18 ( V_21 ) ) {
F_15 ( L_8
L_9 ,
F_19 ( V_21 ) ) ;
V_21 = NULL ;
}
F_13 ( V_11 , V_19 , V_21 ) ;
V_45:
return V_44 ;
}
int F_24 ( struct V_11 * V_11 )
{
static F_25 ( V_60 ) ;
int V_44 = 0 ;
if ( F_7 ( V_11 ) )
return V_44 ;
F_26 ( & V_60 ) ;
if ( F_7 ( V_11 ) )
goto V_45;
if ( F_16 ( V_11 ) != 0 )
V_44 = F_21 ( V_11 ) ;
V_45:
F_27 ( & V_60 ) ;
return V_44 ;
}
static struct V_18 * F_28 ( struct V_11 * V_11 , const char * V_61 ,
struct V_35 * V_62 , T_1 V_63 ,
int V_64 , T_2 V_40 )
{
struct V_31 args = {
. V_11 = V_11 ,
. V_32 = V_64 ,
. V_34 = V_62 ,
. V_36 = V_63 ,
. V_37 = V_61 ,
. V_38 = & V_39 ,
. V_40 = V_40 ,
. V_42 = V_57 ,
. V_58 = ( V_59 |
V_65 ) ,
} ;
switch ( V_62 -> V_66 ) {
case V_50 :
( (struct V_47 * ) V_62 ) -> V_54 = F_23 ( V_55 ) ;
break;
case V_67 :
( (struct V_68 * ) V_62 ) -> V_69 = F_23 ( V_55 ) ;
break;
default:
return F_29 ( - V_70 ) ;
}
return F_17 ( & args ) ;
}
static int F_30 ( struct V_18 * V_19 , struct V_71 * V_72 )
{
int V_44 , error = 0 ;
V_72 -> V_73 = & V_44 ;
error = F_31 ( V_19 , V_72 , V_74 ) ;
if ( error < 0 ) {
F_15 ( L_11
L_12 , - error ) ;
return error ;
}
if ( ! V_44 )
return - V_75 ;
return 0 ;
}
int F_32 ( struct V_11 * V_11 , T_2 V_76 , T_2 V_77 , int V_78 , unsigned short V_79 )
{
struct V_6 V_7 = {
. V_80 = V_76 ,
. V_81 = V_77 ,
. V_82 = V_78 ,
. V_83 = V_79 ,
} ;
struct V_71 V_72 = {
. V_84 = & V_7 ,
} ;
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
F_15 ( L_13
L_14 , ( V_79 ? L_4 : L_15 ) ,
V_76 , V_77 , V_78 , V_79 ) ;
V_72 . V_85 = & V_86 [ V_87 ] ;
if ( V_79 )
V_72 . V_85 = & V_86 [ V_88 ] ;
return F_30 ( V_14 -> V_20 , & V_72 ) ;
}
static int F_33 ( struct V_13 * V_14 ,
const struct V_35 * V_89 ,
struct V_71 * V_72 )
{
const struct V_47 * sin = ( const struct V_47 * ) V_89 ;
struct V_6 * V_7 = V_72 -> V_84 ;
unsigned short V_79 = F_34 ( sin -> V_54 ) ;
int V_44 ;
V_7 -> V_10 = F_35 ( V_89 , V_90 ) ;
F_15 ( L_16
L_17 , ( V_79 ? L_4 : L_15 ) ,
V_7 -> V_80 , V_7 -> V_81 ,
V_7 -> V_10 , V_7 -> V_91 ) ;
V_72 -> V_85 = & V_92 [ V_87 ] ;
if ( V_79 )
V_72 -> V_85 = & V_92 [ V_88 ] ;
V_44 = F_30 ( V_14 -> V_22 , V_72 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_44 ;
}
static int F_36 ( struct V_13 * V_14 ,
const struct V_35 * V_89 ,
struct V_71 * V_72 )
{
const struct V_68 * V_93 = ( const struct V_68 * ) V_89 ;
struct V_6 * V_7 = V_72 -> V_84 ;
unsigned short V_79 = F_34 ( V_93 -> V_69 ) ;
int V_44 ;
V_7 -> V_10 = F_35 ( V_89 , V_90 ) ;
F_15 ( L_16
L_17 , ( V_79 ? L_4 : L_15 ) ,
V_7 -> V_80 , V_7 -> V_81 ,
V_7 -> V_10 , V_7 -> V_91 ) ;
V_72 -> V_85 = & V_92 [ V_87 ] ;
if ( V_79 )
V_72 -> V_85 = & V_92 [ V_88 ] ;
V_44 = F_30 ( V_14 -> V_22 , V_72 ) ;
F_6 ( V_7 -> V_10 ) ;
return V_44 ;
}
static int F_37 ( struct V_13 * V_14 ,
struct V_71 * V_72 )
{
struct V_6 * V_7 = V_72 -> V_84 ;
F_15 ( L_18
L_17 ,
V_7 -> V_80 , V_7 -> V_81 , V_7 -> V_91 ) ;
V_7 -> V_10 = L_4 ;
V_72 -> V_85 = & V_92 [ V_87 ] ;
return F_30 ( V_14 -> V_22 , V_72 ) ;
}
int F_38 ( struct V_11 * V_11 , const T_2 V_38 , const T_2 V_40 ,
const struct V_35 * V_34 , const char * V_94 )
{
struct V_6 V_7 = {
. V_80 = V_38 ,
. V_81 = V_40 ,
. V_91 = V_94 ,
. V_95 = V_96 ,
} ;
struct V_71 V_72 = {
. V_84 = & V_7 ,
} ;
struct V_13 * V_14 = F_8 ( V_11 , V_15 ) ;
if ( V_14 -> V_22 == NULL )
return - V_97 ;
if ( V_34 == NULL )
return F_37 ( V_14 , & V_72 ) ;
switch ( V_34 -> V_66 ) {
case V_50 :
return F_33 ( V_14 , V_34 , & V_72 ) ;
case V_67 :
return F_36 ( V_14 , V_34 , & V_72 ) ;
}
return - V_70 ;
}
static struct V_98 * F_39 ( struct V_18 * V_99 , struct V_6 * V_7 , struct V_100 * V_101 )
{
struct V_71 V_72 = {
. V_85 = V_101 ,
. V_84 = V_7 ,
. V_73 = V_7 ,
} ;
struct V_102 V_103 = {
. V_104 = V_99 ,
. V_71 = & V_72 ,
. V_105 = & V_106 ,
. V_107 = V_7 ,
. V_58 = V_108 | V_74 ,
} ;
return F_40 ( & V_103 ) ;
}
static struct V_18 * F_41 ( struct V_18 * V_19 )
{
struct V_18 * V_109 = V_19 -> V_110 ;
struct V_1 * V_2 = F_42 ( V_19 -> V_111 ) ;
while ( V_109 != V_19 ) {
if ( F_42 ( V_109 -> V_111 ) != V_2 )
break;
if ( V_19 -> V_112 )
break;
V_19 = V_109 ;
V_109 = V_109 -> V_110 ;
}
return V_19 ;
}
void F_43 ( struct V_98 * V_113 )
{
struct V_18 * V_19 ;
struct V_100 * V_101 ;
T_2 V_114 ;
struct V_1 * V_2 ;
struct V_18 * V_99 ;
struct V_6 * V_7 ;
struct V_98 * V_115 ;
struct V_116 V_117 ;
struct V_35 * V_89 = (struct V_35 * ) & V_117 ;
T_1 V_63 ;
int V_3 ;
F_44 () ;
do {
V_19 = F_41 ( V_113 -> V_118 ) ;
V_2 = F_45 ( F_42 ( V_19 -> V_111 ) ) ;
} while ( V_2 == NULL );
F_46 () ;
F_15 ( L_19 ,
V_113 -> V_119 , V_120 ,
V_2 -> V_37 , V_19 -> V_121 , V_19 -> V_122 , V_2 -> V_78 ) ;
F_47 ( & V_2 -> V_4 , V_113 , NULL ) ;
if ( F_48 ( V_2 ) ) {
F_15 ( L_20 ,
V_113 -> V_119 , V_120 ) ;
F_5 ( V_2 ) ;
return;
}
if ( F_49 ( V_2 ) ) {
V_3 = 0 ;
F_15 ( L_21 ,
V_113 -> V_119 , V_120 ) ;
goto V_123;
}
V_63 = F_50 ( V_19 , V_89 , sizeof( V_117 ) ) ;
switch ( V_89 -> V_66 ) {
case V_50 :
V_101 = V_124 [ V_2 -> V_125 ] . V_85 ;
V_114 = V_124 [ V_2 -> V_125 ] . V_126 ;
break;
case V_67 :
V_101 = V_127 [ V_2 -> V_125 ] . V_85 ;
V_114 = V_127 [ V_2 -> V_125 ] . V_126 ;
break;
default:
V_3 = - V_70 ;
F_15 ( L_22 ,
V_113 -> V_119 , V_120 ) ;
goto V_123;
}
if ( V_101 == NULL ) {
V_2 -> V_125 = 0 ;
V_3 = - V_128 ;
F_15 ( L_23 ,
V_113 -> V_119 , V_120 ) ;
goto V_123;
}
F_15 ( L_24 ,
V_113 -> V_119 , V_120 , V_114 ) ;
V_99 = F_28 ( V_2 -> V_129 , V_2 -> V_37 , V_89 , V_63 ,
V_2 -> V_78 , V_114 ) ;
if ( F_18 ( V_99 ) ) {
V_3 = F_19 ( V_99 ) ;
F_15 ( L_25 ,
V_113 -> V_119 , V_120 , F_19 ( V_99 ) ) ;
goto V_123;
}
V_7 = F_51 ( sizeof( struct V_6 ) , V_130 ) ;
if ( ! V_7 ) {
V_3 = - V_131 ;
F_15 ( L_26 ,
V_113 -> V_119 , V_120 ) ;
goto V_132;
}
V_7 -> V_80 = V_19 -> V_121 ;
V_7 -> V_81 = V_19 -> V_122 ;
V_7 -> V_82 = V_2 -> V_78 ;
V_7 -> V_83 = 0 ;
V_7 -> V_8 = V_2 ;
V_7 -> V_9 = - V_133 ;
switch ( V_114 ) {
case V_46 :
case V_134 :
V_7 -> V_91 = V_2 -> V_135 [ V_136 ] ;
V_7 -> V_10 = F_35 ( V_89 , V_130 ) ;
V_7 -> V_95 = L_4 ;
break;
case V_41 :
V_7 -> V_10 = NULL ;
break;
default:
F_52 () ;
}
V_115 = F_39 ( V_99 , V_7 , V_101 ) ;
F_53 ( V_99 ) ;
if ( F_18 ( V_115 ) ) {
F_15 ( L_27 ,
V_113 -> V_119 , V_120 ) ;
return;
}
V_2 -> V_137 . V_138 ++ ;
F_54 ( V_115 ) ;
return;
V_132:
F_53 ( V_99 ) ;
V_123:
F_1 ( V_2 , V_3 ) ;
V_113 -> V_139 = V_3 ;
F_5 ( V_2 ) ;
}
static void F_55 ( struct V_98 * V_115 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
struct V_1 * V_2 = V_7 -> V_8 ;
int V_3 = V_115 -> V_139 ;
if ( V_3 == - V_133 )
V_3 = - V_97 ;
if ( V_3 == - V_97 )
V_2 -> V_125 ++ ;
if ( V_3 < 0 ) {
V_2 -> V_140 -> V_141 ( V_2 , 0 ) ;
} else if ( V_7 -> V_83 == 0 ) {
V_2 -> V_140 -> V_141 ( V_2 , 0 ) ;
V_3 = - V_75 ;
} else {
V_2 -> V_140 -> V_141 ( V_2 , V_7 -> V_83 ) ;
F_56 ( V_2 ) ;
V_3 = 0 ;
}
F_15 ( L_28 ,
V_115 -> V_119 , V_3 , V_7 -> V_83 ) ;
V_7 -> V_9 = V_3 ;
}
static void F_57 ( struct V_142 * V_143 , struct V_144 * V_145 ,
const struct V_6 * V_146 )
{
T_3 * V_147 ;
F_15 ( L_29 ,
V_143 -> V_148 -> V_119 ,
V_143 -> V_148 -> V_149 . V_85 -> V_150 ,
V_146 -> V_80 , V_146 -> V_81 , V_146 -> V_82 , V_146 -> V_83 ) ;
V_147 = F_58 ( V_145 , V_151 << 2 ) ;
* V_147 ++ = F_59 ( V_146 -> V_80 ) ;
* V_147 ++ = F_59 ( V_146 -> V_81 ) ;
* V_147 ++ = F_59 ( V_146 -> V_82 ) ;
* V_147 = F_59 ( V_146 -> V_83 ) ;
}
static int F_60 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_6 * V_146 )
{
unsigned long V_79 ;
T_3 * V_147 ;
V_146 -> V_83 = 0 ;
V_147 = F_61 ( V_145 , 4 ) ;
if ( F_62 ( V_147 == NULL ) )
return - V_133 ;
V_79 = F_63 ( V_147 ) ;
F_15 ( L_30 , V_143 -> V_148 -> V_119 ,
V_143 -> V_148 -> V_149 . V_85 -> V_150 , V_79 ) ;
if ( F_62 ( V_79 > V_152 ) )
return - V_133 ;
V_146 -> V_83 = V_79 ;
return 0 ;
}
static int F_64 ( struct V_142 * V_143 , struct V_144 * V_145 ,
unsigned int * V_153 )
{
T_3 * V_147 ;
V_147 = F_61 ( V_145 , 4 ) ;
if ( F_62 ( V_147 == NULL ) )
return - V_133 ;
* V_153 = 0 ;
if ( * V_147 != V_154 )
* V_153 = 1 ;
F_15 ( L_31 ,
V_143 -> V_148 -> V_119 ,
V_143 -> V_148 -> V_149 . V_85 -> V_150 ,
( * V_153 ? L_32 : L_33 ) ) ;
return 0 ;
}
static void F_65 ( struct V_144 * V_145 , const char * string ,
const T_2 V_155 )
{
T_3 * V_147 ;
T_2 V_156 ;
V_156 = strlen ( string ) ;
F_66 ( V_156 > V_155 ) ;
V_147 = F_58 ( V_145 , 4 + V_156 ) ;
F_67 ( V_147 , string , V_156 ) ;
}
static void F_68 ( struct V_142 * V_143 , struct V_144 * V_145 ,
const struct V_6 * V_146 )
{
T_3 * V_147 ;
F_15 ( L_34 ,
V_143 -> V_148 -> V_119 ,
V_143 -> V_148 -> V_149 . V_85 -> V_150 ,
V_146 -> V_80 , V_146 -> V_81 ,
V_146 -> V_91 , V_146 -> V_10 ) ;
V_147 = F_58 ( V_145 , ( V_157 + V_158 ) << 2 ) ;
* V_147 ++ = F_59 ( V_146 -> V_80 ) ;
* V_147 = F_59 ( V_146 -> V_81 ) ;
F_65 ( V_145 , V_146 -> V_91 , V_159 ) ;
F_65 ( V_145 , V_146 -> V_10 , V_160 ) ;
F_65 ( V_145 , V_146 -> V_95 , V_161 ) ;
}
static int F_69 ( struct V_142 * V_143 , struct V_144 * V_145 ,
struct V_6 * V_146 )
{
struct V_116 V_34 ;
struct V_35 * V_89 = (struct V_35 * ) & V_34 ;
T_3 * V_147 ;
T_2 V_156 ;
V_146 -> V_83 = 0 ;
V_147 = F_61 ( V_145 , 4 ) ;
if ( F_62 ( V_147 == NULL ) )
goto V_162;
V_156 = F_63 ( V_147 ) ;
if ( V_156 == 0 ) {
F_15 ( L_35 ,
V_143 -> V_148 -> V_119 ) ;
return 0 ;
}
if ( F_62 ( V_156 > V_160 ) )
goto V_162;
V_147 = F_61 ( V_145 , V_156 ) ;
if ( F_62 ( V_147 == NULL ) )
goto V_162;
F_15 ( L_36 , V_143 -> V_148 -> V_119 ,
V_143 -> V_148 -> V_149 . V_85 -> V_150 , ( char * ) V_147 ) ;
if ( F_70 ( V_143 -> V_163 -> V_129 , ( char * ) V_147 , V_156 ,
V_89 , sizeof( V_34 ) ) == 0 )
goto V_162;
V_146 -> V_83 = F_71 ( V_89 ) ;
return 0 ;
V_162:
F_15 ( L_37 ,
V_143 -> V_148 -> V_119 ,
V_143 -> V_148 -> V_149 . V_85 -> V_150 ) ;
return - V_133 ;
}
