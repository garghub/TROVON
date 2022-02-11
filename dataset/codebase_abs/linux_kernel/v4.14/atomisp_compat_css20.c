void F_1 ( void )
{
F_2 () ;
}
void F_3 ( const char * V_1 )
{
F_4 ( V_1 ) ;
}
void F_5 ( const unsigned int V_2 )
{
F_6 ( V_2 ) ;
}
unsigned int F_7 ( void )
{
return V_3 ;
}
void F_8 ( T_1 V_4 , T_2 V_5 )
{
unsigned long V_6 ;
F_9 ( & V_7 , V_6 ) ;
F_10 ( V_4 , V_5 ) ;
F_11 ( & V_7 , V_6 ) ;
}
static void F_12 ( T_1 V_4 , T_3 V_5 )
{
unsigned long V_6 ;
F_9 ( & V_7 , V_6 ) ;
F_13 ( V_4 , V_5 ) ;
F_11 ( & V_7 , V_6 ) ;
}
static void F_14 ( T_1 V_4 , T_4 V_5 )
{
unsigned long V_6 ;
F_9 ( & V_7 , V_6 ) ;
F_15 ( V_4 , V_5 ) ;
F_11 ( & V_7 , V_6 ) ;
}
static T_2 F_16 ( T_1 V_4 )
{
unsigned long V_6 ;
T_2 V_8 ;
F_9 ( & V_7 , V_6 ) ;
V_8 = F_17 ( V_4 ) ;
F_11 ( & V_7 , V_6 ) ;
return V_8 ;
}
T_3 F_18 ( T_1 V_4 )
{
unsigned long V_6 ;
T_3 V_8 ;
F_9 ( & V_7 , V_6 ) ;
V_8 = F_19 ( V_4 ) ;
F_11 ( & V_7 , V_6 ) ;
return V_8 ;
}
T_4 F_20 ( T_1 V_4 )
{
unsigned long V_6 ;
T_4 V_8 ;
F_9 ( & V_7 , V_6 ) ;
V_8 = F_21 ( V_4 ) ;
F_11 ( & V_7 , V_6 ) ;
return V_8 ;
}
static void F_22 ( T_1 V_4 ,
const void * V_9 , T_4 V_10 )
{
unsigned long V_6 ;
unsigned V_11 ;
unsigned int V_12 = ( unsigned int ) V_4 ;
const char * V_13 = ( const char * ) V_9 ;
F_9 ( & V_7 , V_6 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ , V_12 ++ , V_13 ++ )
F_10 ( V_12 , * V_13 ) ;
F_11 ( & V_7 , V_6 ) ;
}
static void F_23 ( T_1 V_4 , void * V_14 , T_4 V_10 )
{
unsigned long V_6 ;
unsigned V_11 ;
char * V_12 = ( char * ) V_14 ;
unsigned int V_13 = ( unsigned int ) V_4 ;
F_9 ( & V_7 , V_6 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ , V_12 ++ , V_13 ++ )
* V_12 = F_17 ( V_13 ) ;
F_11 ( & V_7 , V_6 ) ;
}
static int F_24 ( const char * V_15 , T_5 args )
{
F_25 ( V_15 , args ) ;
return 0 ;
}
static int F_26 ( const char * V_15 , T_5 args )
{
F_27 ( V_15 , args ) ;
return 0 ;
}
static int F_28 ( const char * V_15 , T_5 args )
{
F_25 ( V_15 , args ) ;
return 0 ;
}
void F_29 ( T_1 V_4 , T_4 V_5 )
{
F_14 ( V_4 , V_5 ) ;
}
void F_30 ( T_1 V_4 , T_4 * V_5 )
{
* V_5 = F_20 ( V_4 ) ;
}
static int F_31 ( unsigned int * V_16 )
{
if ( V_17 . V_18 == NULL ) {
F_32 ( V_19 , L_1 ) ;
return - V_20 ;
}
* V_16 = V_17 . V_18 ( & V_21 . V_22 ,
V_21 . V_22 . V_23 ) ;
return 0 ;
}
static void F_33 (
struct V_24 * V_25 )
{
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
}
static void F_34 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
unsigned int V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
if ( V_29 -> V_33 [ V_30 ] ) {
struct V_34 * V_35 ;
struct V_36 * V_37 ;
V_35 = & V_29 -> V_38 [ V_30 ] ;
V_37 = & V_29 -> V_39 [ V_30 ] ;
F_35 ( V_32 -> V_40 , L_2 , V_30 ) ;
F_35 ( V_32 -> V_40 ,
L_3 , V_35 -> V_41 ) ;
F_35 ( V_32 -> V_40 ,
L_4 ,
V_35 -> V_42 [ 0 ] . V_43 . V_44 ,
V_35 -> V_42 [ 0 ] . V_43 . V_45 ) ;
F_35 ( V_32 -> V_40 ,
L_5 ,
V_35 -> V_46 . V_44 ,
V_35 -> V_46 . V_45 ) ;
F_35 ( V_32 -> V_40 ,
L_6 ,
V_35 -> V_47 . V_44 ,
V_35 -> V_47 . V_45 ) ;
F_35 ( V_32 -> V_40 ,
L_7 ,
V_35 -> V_42 [ 0 ] . V_48 ) ;
F_35 ( V_32 -> V_40 ,
L_8 ,
V_35 -> V_49 [ 0 ] . V_43 . V_44 ,
V_35 -> V_49 [ 0 ] . V_43 . V_45 ) ;
F_35 ( V_32 -> V_40 ,
L_9 ,
V_35 -> V_50 . V_44 ,
V_35 -> V_50 . V_45 ) ;
F_35 ( V_32 -> V_40 ,
L_10 ,
V_35 -> V_51 . V_44 ,
V_35 -> V_51 . V_45 ) ;
F_35 ( V_32 -> V_40 ,
L_11 ,
V_35 -> V_52 ) ;
F_35 ( V_32 -> V_40 ,
L_12 ,
V_35 -> V_53 ) ;
F_35 ( V_32 -> V_40 ,
L_13 ,
V_35 -> V_54 ) ;
F_35 ( V_32 -> V_40 ,
L_14 ,
V_35 -> V_55 ) ;
F_35 ( V_32 -> V_40 ,
L_15 ,
V_35 -> V_56 ) ;
F_35 ( V_32 -> V_40 ,
L_16 ,
V_35 -> V_57 ) ;
F_35 ( V_32 -> V_40 ,
L_17 ,
V_35 -> V_58 . V_41 ) ;
F_35 ( V_32 -> V_40 ,
L_18 ,
V_35 -> V_59 ) ;
F_35 ( V_32 -> V_40 ,
L_19 ,
V_35 -> V_58 . V_60 ) ;
F_35 ( V_32 -> V_40 ,
L_20 , V_30 ) ;
F_35 ( V_32 -> V_40 ,
L_21 ,
V_37 -> V_61 ) ;
F_35 ( V_32 -> V_40 ,
L_22 ,
V_37 -> V_62 ) ;
F_35 ( V_32 -> V_40 ,
L_23 ,
V_37 -> V_63 ) ;
F_35 ( V_32 -> V_40 ,
L_24 ,
V_37 -> V_64 ) ;
F_35 ( V_32 -> V_40 ,
L_25 ,
V_37 -> V_65 ) ;
F_35 ( V_32 -> V_40 ,
L_26 ,
V_35 -> V_59 ) ;
F_35 ( V_32 -> V_40 ,
L_27 ,
V_37 -> V_66 ) ;
}
}
static void F_36 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_67 * V_68 ;
int V_69 ;
bool V_70 = false ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
if ( V_29 -> V_33 [ V_69 ] ) {
F_34 ( V_27 , V_29 , V_69 ) ;
V_70 = true ;
}
}
if ( ! V_70 )
return;
V_68 = & V_29 -> V_72 ;
F_35 ( V_32 -> V_40 , L_28 , V_68 -> V_41 ) ;
if ( V_68 -> V_41 == V_73 ||
V_68 -> V_41 == V_74 ) {
F_35 ( V_32 -> V_40 , L_29 ,
V_68 -> V_75 . V_76 . V_76 ) ;
F_35 ( V_32 -> V_40 , L_30 ,
V_68 -> V_75 . V_76 . V_77 ) ;
F_35 ( V_32 -> V_40 , L_31 ,
V_68 -> V_75 . V_76 . V_78 ) ;
F_35 ( V_32 -> V_40 , L_32 ,
V_68 -> V_75 . V_76 . V_79 ) ;
F_35 ( V_32 -> V_40 , L_33 ,
V_68 -> V_75 . V_76 . V_80 . type ) ;
F_35 ( V_32 -> V_40 , L_34 ,
V_68 -> V_75 . V_76 . V_80 .
V_81 ) ;
F_35 ( V_32 -> V_40 , L_35 ,
V_68 -> V_75 . V_76 . V_80 .
V_82 ) ;
} else if ( V_68 -> V_41 == V_83 ) {
F_35 ( V_32 -> V_40 , L_36 ,
V_68 -> V_75 . V_84 . V_85 ) ;
F_35 ( V_32 -> V_40 , L_37 ,
V_68 -> V_75 . V_84 . V_41 ) ;
F_35 ( V_32 -> V_40 , L_38 ,
V_68 -> V_75 . V_84 . V_86 ) ;
F_35 ( V_32 -> V_40 , L_39 ,
V_68 -> V_75 . V_84 . V_87 ) ;
F_35 ( V_32 -> V_40 , L_40 ,
V_68 -> V_75 . V_84 . V_88 ) ;
F_35 ( V_32 -> V_40 , L_41 ,
V_68 -> V_75 . V_84 . V_89 ) ;
F_35 ( V_32 -> V_40 , L_42 ,
V_68 -> V_75 . V_84 . V_90 ) ;
} else if ( V_68 -> V_41 == V_91 ) {
F_35 ( V_32 -> V_40 , L_43 ,
V_68 -> V_75 . V_92 . V_85 ) ;
F_35 ( V_32 -> V_40 , L_44 ,
V_68 -> V_75 . V_92 . V_93 ) ;
F_35 ( V_32 -> V_40 , L_45 ,
V_68 -> V_75 . V_92 . V_94 ) ;
F_35 ( V_32 -> V_40 , L_46 ,
V_68 -> V_75 . V_92 . V_95 ) ;
F_35 ( V_32 -> V_40 , L_47 ,
V_68 -> V_75 . V_92 . V_96 ) ;
}
for ( V_69 = 0 ; V_69 < V_97 ; V_69 ++ ) {
F_35 ( V_32 -> V_40 , L_48 ,
V_69 ,
V_68 -> V_98 [ V_69 ] . V_99 . V_44 ,
V_68 -> V_98 [ V_69 ] . V_99 . V_45 ) ;
F_35 ( V_32 -> V_40 , L_49 ,
V_69 ,
V_68 -> V_98 [ V_69 ] . V_100 ) ;
F_35 ( V_32 -> V_40 , L_50 ,
V_69 ,
V_68 -> V_98 [ V_69 ] . V_101 ) ;
F_35 ( V_32 -> V_40 , L_51 ,
V_69 ,
V_68 -> V_98 [ V_69 ] . V_102 ) ;
}
F_35 ( V_32 -> V_40 , L_52 ,
V_68 -> V_103 . V_99 . V_44 ,
V_68 -> V_103 . V_99 . V_45 ) ;
F_35 ( V_32 -> V_40 , L_53 ,
V_68 -> V_103 . V_104 . V_44 ,
V_68 -> V_103 . V_104 . V_45 ) ;
F_35 ( V_32 -> V_40 , L_54 ,
V_68 -> V_103 . V_101 ) ;
F_35 ( V_32 -> V_40 , L_55 ,
V_68 -> V_103 . V_105 ) ;
F_35 ( V_32 -> V_40 , L_56 ,
V_68 -> V_106 ) ;
F_35 ( V_32 -> V_40 , L_57 , V_68 -> V_107 ) ;
F_35 ( V_32 -> V_40 , L_58 ,
V_68 -> V_108 ) ;
F_35 ( V_32 -> V_40 , L_59 ,
V_68 -> V_109 ) ;
F_35 ( V_32 -> V_40 , L_60 ,
V_68 -> V_110 ) ;
F_35 ( V_32 -> V_40 , L_61 ,
V_68 -> V_111 ) ;
F_35 ( V_32 -> V_40 , L_62 ,
V_68 -> V_112 ) ;
F_35 ( V_32 -> V_40 , L_63 ,
V_68 -> V_113 ) ;
F_35 ( V_32 -> V_40 , L_64 ,
V_68 -> V_114 ) ;
F_35 ( V_32 -> V_40 , L_56 ,
V_68 -> V_106 ) ;
F_35 ( V_32 -> V_40 , L_65 ,
V_68 -> V_115 ) ;
F_35 ( V_32 -> V_40 , L_66 ,
V_68 -> V_116 ) ;
F_35 ( V_32 -> V_40 , L_67 ,
V_68 -> V_117 . V_118 ) ;
F_35 ( V_32 -> V_40 , L_68 ,
V_68 -> V_117 . V_119 ) ;
F_35 ( V_32 -> V_40 , L_69 ,
V_68 -> V_120 . V_121 ) ;
F_35 ( V_32 -> V_40 , L_70 ,
V_68 -> V_120 . V_122 . V_44 ,
V_68 -> V_120 . V_122 . V_45 ) ;
}
static int F_37 ( struct V_26 * V_27 ,
struct V_28 * V_29 , bool V_123 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
int V_11 ;
unsigned long V_78 ;
if ( ! V_29 -> V_124 )
return 0 ;
if ( ! V_123 ) {
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
if ( V_29 -> V_125 [ V_11 ] )
break;
if ( V_11 == V_71 )
return 0 ;
}
if ( V_29 -> V_126 == V_127
&& F_38 ( V_29 -> V_124 ) != V_128 ) {
F_32 ( V_32 -> V_40 , L_71 ) ;
return - V_20 ;
}
if ( V_29 -> V_126 == V_127 ) {
V_78 = V_129 + F_39 ( 40 ) ;
while ( 1 ) {
if ( F_40 ( V_29 -> V_124 ) )
break;
if ( F_41 ( V_129 , V_78 ) ) {
F_42 ( V_32 -> V_40 , L_72 ) ;
break;
}
F_43 ( 100 , 200 ) ;
}
}
V_29 -> V_126 = V_130 ;
if ( F_44 ( V_29 -> V_124 ) != V_128 ) {
F_32 ( V_32 -> V_40 , L_73 ) ;
return - V_20 ;
}
V_29 -> V_126 = V_131 ;
V_29 -> V_124 = NULL ;
return 0 ;
}
static int F_45 ( struct V_26 * V_27 , bool V_123 )
{
int V_8 , V_11 ;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
V_8 = F_37 ( V_27 , & V_27 -> V_29 [ V_11 ] , V_123 ) ;
if ( V_8 )
return V_8 ;
}
V_27 -> V_133 = false ;
return 0 ;
}
static int F_46 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
int V_134 = 0 , V_11 ;
struct V_135 * V_136 [ V_71 ] ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ ) {
if ( V_29 -> V_33 [ V_11 ] )
V_136 [ V_134 ++ ] = V_29 -> V_33 [ V_11 ] ;
}
if ( V_134 == 0 )
return 0 ;
V_29 -> V_72 . V_112 =
V_27 -> V_137 -> V_138 ;
V_29 -> V_72 . V_110 = V_29 -> V_139 ;
V_29 -> V_72 . V_140 =
V_27 -> V_141 -> V_138 ;
F_36 ( V_27 , V_29 ) ;
if ( F_47 ( & V_29 -> V_72 ,
V_134 , V_136 , & V_29 -> V_124 ) != V_128 )
return - V_20 ;
if ( F_48 ( V_29 -> V_124 ,
& V_29 -> V_142 ) != V_128 ) {
F_44 ( V_29 -> V_124 ) ;
V_29 -> V_124 = NULL ;
return - V_20 ;
}
V_29 -> V_126 = V_143 ;
return 0 ;
}
static int F_49 ( struct V_26 * V_27 )
{
int V_8 , V_11 ;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
V_8 = F_46 ( V_27 , & V_27 -> V_29 [ V_11 ] ) ;
if ( V_8 )
goto V_144;
}
V_27 -> V_133 = true ;
return 0 ;
V_144:
for ( V_11 -- ; V_11 >= 0 ; V_11 -- )
F_37 ( V_27 , & V_27 -> V_29 [ V_11 ] , true ) ;
return V_8 ;
}
static int F_50 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
bool V_123 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
int V_8 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ ) {
if ( ! V_29 -> V_33 [ V_11 ] ||
! ( V_123 || V_29 -> V_125 [ V_11 ] ) )
continue;
if ( F_51 ( V_29 -> V_33 [ V_11 ] )
!= V_128 ) {
F_32 ( V_32 -> V_40 ,
L_74 , V_11 ) ;
V_8 = - V_20 ;
}
V_29 -> V_33 [ V_11 ] = NULL ;
V_29 -> V_125 [ V_11 ] = false ;
}
return V_8 ;
}
static int F_52 ( struct V_26 * V_27 , bool V_123 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
int V_11 ;
int V_8 = 0 ;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
if ( V_27 -> V_29 [ V_11 ] . V_124 ) {
F_32 ( V_32 -> V_40 ,
L_75 ,
V_11 ) ;
continue;
}
V_8 = F_50 ( V_27 , & V_27 -> V_29 [ V_11 ] , V_123 ) ;
if ( V_8 )
return V_8 ;
}
return 0 ;
}
void F_53 ( struct V_26 * V_27 )
{
F_45 ( V_27 , true ) ;
F_52 ( V_27 , true ) ;
}
static void F_54 (
struct V_26 * V_27 ,
struct V_28 * V_29 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
if ( V_30 < 0 || V_30 >= V_71 ) {
F_32 ( V_32 -> V_40 ,
L_76 ) ;
return;
}
V_29 -> V_38 [ V_30 ] . V_53 = 2 ;
V_29 -> V_38 [ V_30 ] . V_59 =
V_27 -> V_146 -> V_138 ? false : true ;
switch ( V_30 ) {
case V_147 :
if ( V_29 -> V_38 [ V_30 ] .
V_58 . V_41 == V_148 )
V_29 -> V_38 [ V_30 ] . V_59 = false ;
#ifdef F_55
if ( V_27 -> V_149 -> V_138 ==
V_150 )
V_29 -> V_38 [ V_30 ] . V_53 =
V_151 ;
else
V_29 -> V_38 [ V_30 ] . V_53 =
V_152 ;
#endif
break;
case V_153 :
V_29 -> V_39 [ V_30 ]
. V_65 = true ;
V_29 -> V_38 [ V_30 ]
. V_59 = false ;
if ( F_56 ( V_27 ) )
V_29 -> V_38 [ V_30 ] . V_59 = true ;
if ( V_27 -> V_154 . V_155 ) {
V_29 -> V_39 [ V_30 ]
. V_64 = true ;
V_29 -> V_38 [ V_30 ]
. V_52 =
V_156 ;
}
break;
case V_157 :
break;
case V_158 :
case V_159 :
if ( F_56 ( V_27 ) )
V_29 -> V_38 [ V_30 ] . V_59 = true ;
else
V_29 -> V_38 [ V_30 ] . V_59 = false ;
break;
case V_160 :
V_29 -> V_38 [ V_30 ] . V_41 = V_161 ;
V_29 -> V_38 [ V_30 ] . V_59 = false ;
break;
default:
break;
}
}
static bool F_57 ( struct V_26 * V_27 ,
enum V_145 V_30 )
{
if ( ! V_27 )
return false ;
if ( V_30 == V_162 || V_30 == V_163 )
return true ;
if ( V_27 -> V_164 ) {
if ( V_27 -> V_164 -> V_138 == V_165 ) {
if ( V_30 == V_153 )
return true ;
else
return false ;
} else if ( V_27 -> V_164 -> V_138 == V_166 ) {
if ( V_30 == V_147 )
return true ;
else
return false ;
}
}
if ( ! V_27 -> V_167 )
return false ;
if ( V_27 -> V_168 && V_30 == V_159 )
return true ;
switch ( V_27 -> V_167 -> V_138 ) {
case V_169 :
if ( V_30 == V_147 )
return true ;
else
return false ;
case V_170 :
if ( ! V_27 -> V_171 -> V_138 ) {
if ( V_30 == V_157 )
return true ;
else
return false ;
}
case V_172 :
if ( V_30 == V_147 ||
V_30 == V_157 )
return true ;
else
return false ;
case V_173 :
if ( ! V_27 -> V_171 -> V_138 ) {
if ( V_30 == V_153 ||
V_30 == V_158 )
return true ;
else
return false ;
}
case V_174 :
if ( V_30 == V_147 ||
V_30 == V_153 )
return true ;
else
return false ;
}
return false ;
}
static int F_58 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_36 V_175 ;
enum V_176 V_8 ;
if ( V_30 >= V_71 )
return - V_20 ;
if ( V_30 != V_162 &&
! V_29 -> V_38 [ V_30 ] . V_42 [ 0 ] . V_43 . V_44 )
return 0 ;
if ( V_30 == V_162 &&
! V_29 -> V_38 [ V_30 ] . V_54 )
return 0 ;
if ( ! F_57 ( V_27 , V_30 ) )
return 0 ;
F_59 ( & V_175 ) ;
F_54 ( V_27 , V_29 , V_30 ) ;
if ( ! memcmp ( & V_175 ,
& V_29 -> V_39 [ V_30 ] ,
sizeof( V_175 ) ) )
V_8 = F_60 (
& V_29 -> V_38 [ V_30 ] ,
& V_29 -> V_33 [ V_30 ] ) ;
else
V_8 = F_61 (
& V_29 -> V_38 [ V_30 ] ,
& V_29 -> V_39 [ V_30 ] ,
& V_29 -> V_33 [ V_30 ] ) ;
if ( V_8 != V_128 )
F_32 ( V_32 -> V_40 , L_77 , V_30 ) ;
return V_8 ;
}
static int F_62 ( struct V_26 * V_27 )
{
enum V_176 V_8 ;
int V_11 , V_69 ;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
V_8 = F_58 ( V_27 , & V_27 -> V_29 [ V_11 ] , V_69 ) ;
if ( V_8 != V_128 )
break;
}
if ( V_69 < V_71 )
goto V_177;
}
return 0 ;
V_177:
for (; V_11 >= 0 ; V_11 -- ) {
for ( V_69 -- ; V_69 >= 0 ; V_69 -- ) {
if ( V_27 -> V_29 [ V_11 ] . V_33 [ V_69 ] ) {
F_51 ( V_27 -> V_29 [ V_11 ] . V_33 [ V_69 ] ) ;
V_27 -> V_29 [ V_11 ] . V_33 [ V_69 ] = NULL ;
}
}
V_69 = V_71 ;
}
return - V_20 ;
}
void F_63 ( struct V_26 * V_27 )
{
F_62 ( V_27 ) ;
F_49 ( V_27 ) ;
}
int F_64 ( struct V_26 * V_27 )
{
int V_8 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( F_45 ( V_27 , true ) != V_128 )
F_42 ( V_32 -> V_40 , L_73 ) ;
if ( F_52 ( V_27 , true ) != V_128 )
F_42 ( V_32 -> V_40 , L_78 ) ;
V_8 = F_62 ( V_27 ) ;
if ( V_8 != V_128 ) {
F_32 ( V_32 -> V_40 , L_79 , V_8 ) ;
return - V_178 ;
}
V_8 = F_49 ( V_27 ) ;
if ( V_8 != V_128 ) {
F_42 ( V_32 -> V_40 , L_80 , V_8 ) ;
F_52 ( V_27 , true ) ;
return - V_178 ;
}
return 0 ;
}
int F_65 ( struct V_31 * V_32 )
{
unsigned int V_16 ;
int V_8 ;
enum V_176 V_179 ;
V_8 = F_31 ( & V_16 ) ;
if ( V_8 )
return V_8 ;
V_179 = F_66 ( & V_32 -> V_180 . V_181 , NULL ,
( T_4 ) V_16 , V_182 ) ;
if ( V_179 != V_128 ) {
F_32 ( V_32 -> V_40 , L_81 ) ;
return - V_20 ;
}
F_67 ( true ) ;
V_32 -> V_183 = true ;
F_35 ( V_32 -> V_40 , L_82 ) ;
return 0 ;
}
static inline int F_68 ( struct V_31 * V_32 , int V_184 )
{
int V_8 = 0 ;
if ( 0 == V_184 )
V_32 -> V_180 . V_181 . V_185 . V_186 = NULL ;
else if ( 1 == V_184 )
V_32 -> V_180 . V_181 . V_185 . V_186 =
F_26 ;
else if ( 2 == V_184 )
V_32 -> V_180 . V_181 . V_185 . V_186 =
F_24 ;
else
V_8 = - V_20 ;
return V_8 ;
}
int F_69 ( struct V_31 * V_32 )
{
if ( ! F_70 ( ( void * ) V_32 -> V_187 -> V_5 ) ) {
F_32 ( V_32 -> V_40 , L_83 ) ;
return - V_20 ;
}
return 0 ;
}
int F_71 ( struct V_31 * V_32 )
{
enum V_176 V_179 ;
V_32 -> V_180 . V_188 . V_5 = ( void * ) V_32 -> V_187 -> V_5 ;
V_32 -> V_180 . V_188 . V_189 = V_32 -> V_187 -> V_190 ;
V_32 -> V_180 . V_181 . V_191 . V_192 =
F_8 ;
V_32 -> V_180 . V_181 . V_191 . V_193 =
F_12 ;
V_32 -> V_180 . V_181 . V_191 . V_194 =
F_14 ;
V_32 -> V_180 . V_181 . V_191 . V_195 = F_16 ;
V_32 -> V_180 . V_181 . V_191 . V_196 =
F_18 ;
V_32 -> V_180 . V_181 . V_191 . V_197 =
F_20 ;
V_32 -> V_180 . V_181 . V_191 . V_198 = F_23 ;
V_32 -> V_180 . V_181 . V_191 . V_199 = F_22 ;
F_68 ( V_32 , V_200 ) ;
V_32 -> V_180 . V_181 . V_185 . V_201 = F_28 ;
V_179 = F_72 ( & V_32 -> V_180 . V_181 ,
& V_32 -> V_180 . V_188 ) ;
if ( V_179 != V_128 ) {
F_32 ( V_32 -> V_40 , L_84 ) ;
return - V_20 ;
}
return 0 ;
}
void F_73 ( struct V_31 * V_32 )
{
F_74 () ;
}
void F_75 ( struct V_31 * V_32 )
{
struct V_26 * V_27 ;
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_32 -> V_202 ; V_11 ++ ) {
V_27 = & V_32 -> V_27 [ V_11 ] ;
F_33 ( & V_27 -> V_154 . V_25 ) ;
V_27 -> V_154 . V_203 = false ;
}
V_32 -> V_183 = false ;
F_76 () ;
}
void F_77 ( struct V_31 * V_32 )
{
V_32 -> V_183 = false ;
F_76 () ;
}
int F_78 ( struct V_31 * V_32 )
{
unsigned int V_16 ;
int V_8 ;
V_8 = F_31 ( & V_16 ) ;
if ( V_8 ) {
F_32 ( V_32 -> V_40 , L_85 ) ;
return - V_20 ;
}
V_8 = F_66 ( & V_32 -> V_180 . V_181 , NULL ,
V_16 , V_182 ) ;
if ( V_8 ) {
F_32 ( V_32 -> V_40 , L_86 ) ;
return - V_20 ;
}
F_67 ( true ) ;
V_32 -> V_183 = true ;
return 0 ;
}
int F_79 ( struct V_31 * V_32 ,
unsigned int * V_204 )
{
int V_179 ;
V_179 = F_80 ( V_204 ) ;
if ( V_179 != V_128 ) {
F_42 ( V_32 -> V_40 ,
L_87 ,
V_205 , V_179 , * V_204 ) ;
return - V_20 ;
}
return 0 ;
}
void F_81 ( enum V_206 V_76 ,
unsigned int * V_204 )
{
#ifndef F_82
F_83 ( V_76 , V_204 ) ;
#else
* V_204 = 0 ;
#endif
}
void F_84 ( enum V_206 V_76 ,
unsigned int V_204 )
{
#ifndef F_82
F_85 ( V_76 , V_204 ) ;
#endif
}
int F_86 ( struct V_31 * V_32 ,
enum V_207 V_208 , bool V_209 )
{
if ( F_87 ( V_208 , V_209 ) != V_128 ) {
F_42 ( V_32 -> V_40 , L_88 , V_205 ) ;
return - V_20 ;
}
return 0 ;
}
void F_88 ( struct V_26 * V_27 )
{
int V_11 , V_69 ;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
V_27 -> V_29 [ V_11 ] . V_124 = NULL ;
for ( V_69 = 0 ; V_69 < V_210 ; V_69 ++ ) {
V_27 -> V_29 [ V_11 ] . V_33 [ V_69 ] = NULL ;
V_27 -> V_29 [ V_11 ] . V_125 [ V_69 ] = false ;
F_89 (
& V_27 -> V_29 [ V_11 ] . V_38 [ V_69 ] ) ;
F_59 (
& V_27 -> V_29 [ V_11 ] . V_39 [ V_69 ] ) ;
}
F_90 ( & V_27 -> V_29 [ V_11 ] . V_72 ) ;
}
}
int F_91 ( struct V_26 * V_27 ,
struct V_211 * V_212 ,
enum V_213 V_214 ,
enum V_215 V_216 ,
enum V_217 V_218 )
{
struct V_28 * V_29 = & V_27 -> V_29 [ V_214 ] ;
struct V_219 V_220 = { 0 } ;
enum V_176 V_179 ;
V_220 . type = V_216 ;
V_220 . V_5 . V_221 = V_212 -> V_222 ;
V_179 = F_92 (
V_29 -> V_33 [ V_218 ] , & V_220 ) ;
if ( V_179 != V_128 )
return - V_20 ;
return 0 ;
}
int F_93 ( struct V_26 * V_27 ,
struct V_223 * V_224 ,
enum V_213 V_214 ,
enum V_217 V_218 )
{
struct V_28 * V_29 = & V_27 -> V_29 [ V_214 ] ;
struct V_219 V_225 = { 0 } ;
struct V_31 * V_32 = V_27 -> V_32 ;
V_225 . type = V_226 ;
V_225 . V_5 . V_227 = V_224 -> V_227 ;
if ( F_92 ( V_29 -> V_33 [ V_218 ] ,
& V_225 ) ) {
F_32 ( V_32 -> V_40 , L_89 ) ;
return - V_20 ;
}
return 0 ;
}
int F_94 ( struct V_26 * V_27 ,
struct V_228 * V_229 ,
enum V_213 V_214 ,
enum V_217 V_218 )
{
struct V_28 * V_29 = & V_27 -> V_29 [ V_214 ] ;
struct V_219 V_225 = { 0 } ;
struct V_31 * V_32 = V_27 -> V_32 ;
V_225 . type = V_230 ;
V_225 . V_5 . V_231 = V_229 -> V_232 ;
if ( F_92 (
V_29 -> V_33 [ V_218 ] ,
& V_225 ) ) {
F_35 ( V_32 -> V_40 , L_90 ) ;
return - V_20 ;
}
return 0 ;
}
int F_95 ( struct V_26 * V_27 ,
struct V_233 * V_234 ,
enum V_213 V_214 ,
enum V_217 V_218 )
{
struct V_28 * V_29 = & V_27 -> V_29 [ V_214 ] ;
struct V_219 V_225 = { 0 } ;
struct V_31 * V_32 = V_27 -> V_32 ;
V_225 . type = V_235 ;
V_225 . V_5 . V_236 = V_234 -> V_237 ;
if ( F_92 (
V_29 -> V_33 [ V_218 ] ,
& V_225 ) ) {
F_35 ( V_32 -> V_40 , L_91 ) ;
return - V_20 ;
}
return 0 ;
}
void F_96 ( void )
{
F_97 () ;
}
void F_98 ( void )
{
F_97 () ;
}
void F_99 ( unsigned long V_238 )
{
}
bool F_100 ( struct V_31 * V_32 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_32 -> V_202 ; V_11 ++ ) {
struct V_26 * V_27 = & V_32 -> V_27 [ V_11 ] ;
if ( V_27 -> V_239 !=
V_240 )
continue;
if ( V_27 -> V_241 < V_32 -> V_241 )
return true ;
}
return false ;
}
int F_101 ( struct V_26 * V_27 ,
enum V_217 V_30 , bool V_242 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
bool V_243 = false ;
int V_8 = 0 , V_11 = 0 ;
if ( V_242 ) {
if ( F_45 ( V_27 , true ) )
F_42 ( V_32 -> V_40 , L_73 ) ;
if ( F_52 ( V_27 , true ) )
F_42 ( V_32 -> V_40 , L_78 ) ;
if ( F_62 ( V_27 ) ) {
F_32 ( V_32 -> V_40 , L_92 ) ;
return - V_20 ;
}
if ( F_49 ( V_27 ) ) {
F_32 ( V_32 -> V_40 , L_93 ) ;
V_8 = - V_20 ;
goto V_244;
}
F_102 ( V_27 ) ;
}
if ( V_27 -> V_133 == false ) {
if ( F_62 ( V_27 ) ) {
F_32 ( V_32 -> V_40 , L_92 ) ;
return - V_20 ;
}
if ( F_49 ( V_27 ) ) {
F_32 ( V_32 -> V_40 , L_93 ) ;
V_8 = - V_20 ;
goto V_244;
}
}
if ( F_103 ( V_32 ) ) {
F_35 ( V_32 -> V_40 , L_94 ) ;
} else {
if ( ! F_104 () )
F_32 ( V_32 -> V_40 , L_95 ) ;
if ( F_105 () != V_128 ) {
F_32 ( V_32 -> V_40 , L_96 ) ;
V_8 = - V_20 ;
goto V_245;
} else {
V_243 = true ;
}
}
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
if ( V_27 -> V_29 [ V_11 ] . V_124 ) {
if ( F_106 ( V_27 -> V_29 [ V_11 ]
. V_124 ) != V_128 ) {
F_32 ( V_32 -> V_40 , L_97 , V_11 ) ;
V_8 = - V_20 ;
goto V_245;
} else {
V_27 -> V_29 [ V_11 ] . V_126 = V_127 ;
F_35 ( V_32 -> V_40 , L_98 , V_11 ) ;
}
}
}
return 0 ;
V_245:
F_45 ( V_27 , true ) ;
V_244:
F_52 ( V_27 , true ) ;
if ( ( F_103 ( V_32 ) == 0 ) && V_243 )
F_107 () ;
return V_8 ;
}
void F_108 ( struct V_26 * V_27 )
{
if ( V_27 -> V_168 ) {
F_42 ( V_27 -> V_32 -> V_40 ,
L_99 ,
V_205 ) ;
return;
}
F_109 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_27 -> V_154 . V_25 ) ;
F_33 ( & V_27 -> V_154 . V_25 ) ;
}
void F_110 ( struct V_26 * V_27 ,
struct V_135 * V_247 )
{
enum V_176 V_8 ;
if ( ! V_247 ) {
F_108 ( V_27 ) ;
return;
}
F_35 ( V_27 -> V_32 -> V_40 , L_100 ,
V_205 , V_27 -> V_154 . V_25 . V_248 ,
V_27 -> V_154 . V_25 . V_249 , V_247 ) ;
V_8 = F_111 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_27 -> V_154 . V_25 , V_247 ) ;
if ( V_8 != V_128 )
F_42 ( V_27 -> V_32 -> V_40 , L_101 ,
V_205 , V_8 ) ;
F_33 ( & V_27 -> V_154 . V_25 ) ;
}
int F_112 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
enum V_217 V_30 ,
enum V_215 V_250 ,
struct V_251 * V_252 )
{
if ( F_92 (
V_27 -> V_29 [ V_214 ] . V_33 [ V_30 ] ,
& V_252 -> V_253 )
!= V_128 )
return - V_20 ;
return 0 ;
}
int F_113 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
enum V_217 V_30 ,
enum V_215 V_250 ,
struct V_251 * V_252 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
enum V_176 V_179 ;
V_179 = F_114 (
V_27 -> V_29 [ V_214 ] . V_33 [ V_30 ] ,
& V_252 -> V_253 ) ;
if ( V_179 != V_128 ) {
F_32 ( V_32 -> V_40 ,
L_102 , V_179 ) ;
return - V_20 ;
}
return 0 ;
}
int F_115 ( struct V_26 * V_27 ,
T_3 V_214 ,
struct V_228 * V_229 ,
struct V_233 * V_234 ,
struct V_223 * V_254 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_255 * V_256 =
F_116 ( & V_27 -> V_154 . V_257 ) ;
if ( V_229 && V_27 -> V_154 . V_257 . V_258 . V_209 ) {
void * V_259 ;
V_229 -> V_232 = F_117 (
& V_27 -> V_154 . V_257 . V_258 ) ;
if ( ! V_229 -> V_232 ) {
F_32 ( V_32 -> V_40 , L_103 ) ;
return - V_20 ;
}
V_259 = F_118 ( V_229 -> V_232 -> V_260 , true ) ;
V_229 -> V_261 = F_119 (
V_229 -> V_232 , V_259 ) ;
}
if ( V_234 && V_256 && V_256 -> V_209 ) {
void * V_262 ;
V_234 -> V_237 = F_120 (
V_256 ) ;
if ( ! V_234 -> V_237 ) {
F_32 ( V_32 -> V_40 , L_104 ) ;
if ( V_229 )
F_121 ( V_229 -> V_232 ) ;
return - V_20 ;
}
V_262 = F_118 ( V_234 -> V_237 -> V_260 , true ) ;
V_234 -> V_263 = F_122 (
V_234 -> V_237 , V_262 ) ;
}
if ( V_27 -> V_29 [ V_214 ] . V_142 .
V_264 . V_190 && V_254 ) {
V_254 -> V_227 = F_123 (
& V_27 -> V_29 [ V_214 ] . V_142 . V_264 ) ;
if ( ! V_254 -> V_227 ) {
if ( V_229 )
F_121 ( V_229 -> V_232 ) ;
if ( V_234 )
F_124 ( V_234 -> V_237 ) ;
F_32 ( V_32 -> V_40 , L_105 ) ;
return - V_20 ;
}
V_254 -> V_265 = F_118 ( V_254 -> V_227 -> V_266 , false ) ;
}
return 0 ;
}
void F_125 ( struct V_228 * V_229 )
{
if ( V_229 -> V_232 )
F_126 ( V_229 -> V_232 -> V_260 ) ;
F_127 ( V_229 -> V_261 ) ;
V_229 -> V_261 = NULL ;
F_121 ( V_229 -> V_232 ) ;
}
void F_128 ( struct V_233 * V_234 )
{
if ( V_234 -> V_237 )
F_126 ( V_234 -> V_237 -> V_260 ) ;
F_129 ( V_234 -> V_263 ) ;
V_234 -> V_263 = NULL ;
F_124 ( V_234 -> V_237 ) ;
}
void F_130 ( struct V_223 * V_224 )
{
if ( V_224 -> V_265 ) {
F_126 ( V_224 -> V_227 -> V_266 ) ;
V_224 -> V_265 = NULL ;
}
F_131 ( V_224 -> V_227 ) ;
}
void F_132 ( struct V_26 * V_27 )
{
struct V_228 * V_229 , * V_267 ;
struct V_233 * V_234 , * V_268 ;
struct V_223 * V_254 , * V_269 ;
struct V_255 * V_256 =
F_116 ( & V_27 -> V_154 . V_257 ) ;
unsigned int V_11 ;
if ( V_256 && V_256 -> V_209 ) {
F_133 ( V_27 -> V_154 . V_270 . V_271 ) ;
F_134 ( V_27 -> V_154 . V_272 ) ;
V_27 -> V_154 . V_270 . V_271 = NULL ;
V_27 -> V_154 . V_272 = NULL ;
V_27 -> V_154 . V_273 = 0 ;
V_27 -> V_154 . V_274 = 0 ;
V_27 -> V_154 . V_275 = 0 ;
V_27 -> V_154 . V_276 = 0 ;
V_27 -> V_154 . V_277 = false ;
F_135 (dis_buf, _dis_buf,
&asd->dis_stats, list) {
F_128 ( V_234 ) ;
F_136 ( & V_234 -> V_278 ) ;
F_137 ( V_234 ) ;
}
F_135 (dis_buf, _dis_buf,
&asd->dis_stats_in_css, list) {
F_128 ( V_234 ) ;
F_136 ( & V_234 -> V_278 ) ;
F_137 ( V_234 ) ;
}
}
if ( V_27 -> V_154 . V_257 . V_258 . V_209 ) {
F_138 ( V_27 -> V_154 . V_279 ) ;
V_27 -> V_154 . V_279 = NULL ;
V_27 -> V_154 . V_280 = 0 ;
F_135 (s3a_buf, _s3a_buf,
&asd->s3a_stats, list) {
F_125 ( V_229 ) ;
F_136 ( & V_229 -> V_278 ) ;
F_137 ( V_229 ) ;
}
F_135 (s3a_buf, _s3a_buf,
&asd->s3a_stats_in_css, list) {
F_125 ( V_229 ) ;
F_136 ( & V_229 -> V_278 ) ;
F_137 ( V_229 ) ;
}
F_135 (s3a_buf, _s3a_buf,
&asd->s3a_stats_ready, list) {
F_125 ( V_229 ) ;
F_136 ( & V_229 -> V_278 ) ;
F_137 ( V_229 ) ;
}
}
if ( V_27 -> V_154 . V_270 . V_281 ) {
F_139 ( V_27 -> V_154 . V_270 . V_281 ) ;
V_27 -> V_154 . V_270 . V_281 = NULL ;
}
for ( V_11 = 0 ; V_11 < V_282 ; V_11 ++ ) {
F_135 (md_buf, _md_buf,
&asd->metadata[i], list) {
F_130 ( V_254 ) ;
F_136 ( & V_254 -> V_278 ) ;
F_137 ( V_254 ) ;
}
F_135 (md_buf, _md_buf,
&asd->metadata_in_css[i], list) {
F_130 ( V_254 ) ;
F_136 ( & V_254 -> V_278 ) ;
F_137 ( V_254 ) ;
}
F_135 (md_buf, _md_buf,
&asd->metadata_ready[i], list) {
F_130 ( V_254 ) ;
F_136 ( & V_254 -> V_278 ) ;
F_137 ( V_254 ) ;
}
}
V_27 -> V_154 . V_283 = 0 ;
F_140 ( V_27 ) ;
}
int F_141 ( struct V_26 * V_27 ,
enum V_217 V_30 ,
int V_284 )
{
struct V_285 V_286 ;
struct V_287 V_288 ;
struct V_31 * V_32 = V_27 -> V_32 ;
int V_289 = F_142 ( V_27 , V_284 ) ;
int V_290 = V_27 -> V_29 [ V_246 ] .
V_72 . V_120 . V_122 . V_44 ;
memset ( & V_286 , 0 , sizeof( struct V_285 ) ) ;
memset ( & V_288 , 0 , sizeof( struct V_287 ) ) ;
if ( F_143 (
V_27 -> V_29 [ V_289 ] . V_33 [ V_30 ] ,
& V_286 ) != V_128 ) {
F_32 ( V_32 -> V_40 , L_106 ) ;
return - V_20 ;
}
memcpy ( & V_288 , & V_27 -> V_154 . V_257 ,
sizeof( struct V_287 ) ) ;
memcpy ( & V_27 -> V_154 . V_257 , & V_286 . V_291 ,
sizeof( struct V_287 ) ) ;
if ( V_27 -> V_154 . V_257 . V_258 . V_209 ) {
if ( V_27 -> V_154 . V_292 != V_293 )
F_35 ( V_32 -> V_40 , L_107 ,
V_27 -> V_154 . V_292 , V_30 ) ;
V_27 -> V_154 . V_292 = V_30 ;
}
if ( ( ( ! memcmp ( & V_288 , & V_27 -> V_154 . V_257 , sizeof( V_288 ) )
&& V_27 -> V_154 . V_279 && V_27 -> V_154 . V_272 )
|| V_27 -> V_154 . V_257 . V_258 . V_44 == 0
|| V_27 -> V_154 . V_257 . V_258 . V_45 == 0 )
&& V_27 -> V_154 . V_283 == V_290 ) {
F_35 ( V_32 -> V_40 ,
L_108
L_109 ,
! memcmp ( & V_288 , & V_27 -> V_154 . V_257 ,
sizeof( V_288 ) ) ,
! ! V_27 -> V_154 . V_279 , ! ! V_27 -> V_154 . V_272 ,
V_27 -> V_154 . V_257 . V_258 . V_44 ,
V_27 -> V_154 . V_257 . V_258 . V_45 ,
V_27 -> V_154 . V_283 ) ;
return - V_20 ;
}
V_27 -> V_154 . V_283 = V_290 ;
return 0 ;
}
int F_144 ( struct V_26 * V_27 )
{
if ( ! V_27 -> V_154 . V_257 . V_258 . V_44 ||
! V_27 -> V_154 . V_257 . V_258 . V_45 )
return 0 ;
V_27 -> V_154 . V_279 = F_145 (
& V_27 -> V_154 . V_257 . V_258 ) ;
if ( ! V_27 -> V_154 . V_279 )
return - V_294 ;
V_27 -> V_154 . V_280 =
V_27 -> V_154 . V_257 . V_258 . V_44 *
V_27 -> V_154 . V_257 . V_258 . V_45 *
sizeof( * V_27 -> V_154 . V_279 -> V_5 ) ;
return 0 ;
}
int F_146 ( struct V_26 * V_27 )
{
struct V_255 * V_295 =
F_116 ( & V_27 -> V_154 . V_257 ) ;
if ( ! V_295 )
return 0 ;
if ( ! V_295 -> V_209 ) {
F_35 ( V_27 -> V_32 -> V_40 , L_110 , V_205 ) ;
return 0 ;
}
V_27 -> V_154 . V_270 . V_271 = F_147 (
V_295 ) ;
if ( ! V_27 -> V_154 . V_270 . V_271 )
return - V_294 ;
V_27 -> V_154 . V_275 = V_295 -> V_296 *
sizeof( * V_27 -> V_154 . V_270 . V_271 -> V_297 . V_298 ) ;
V_27 -> V_154 . V_276 = V_295 -> V_299 *
sizeof( * V_27 -> V_154 . V_270 . V_271 -> V_300 . V_298 ) ;
V_27 -> V_154 . V_277 = false ;
V_27 -> V_154 . V_272 = F_148 ( V_295 ) ;
if ( ! V_27 -> V_154 . V_272 )
return - V_294 ;
V_27 -> V_154 . V_273 =
V_295 -> V_301 * V_295 -> V_302 *
sizeof( * V_27 -> V_154 . V_272 -> V_303 . V_298 ) ;
V_27 -> V_154 . V_274 =
V_295 -> V_301 * V_295 -> V_302 *
sizeof( * V_27 -> V_154 . V_272 -> V_304 . V_298 ) ;
return 0 ;
}
int F_149 ( struct V_26 * V_27 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_282 ; V_11 ++ ) {
V_27 -> V_154 . V_305 [ V_11 ] = F_150 (
V_27 -> V_29 [ V_246 ] .
V_142 . V_264 . V_190 , V_306 ) ;
if ( ! V_27 -> V_154 . V_305 [ V_11 ] ) {
while ( -- V_11 >= 0 ) {
F_151 ( V_27 -> V_154 . V_305 [ V_11 ] ) ;
V_27 -> V_154 . V_305 [ V_11 ] = NULL ;
}
return - V_294 ;
}
}
return 0 ;
}
void F_140 ( struct V_26 * V_27 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_282 ; V_11 ++ ) {
if ( V_27 -> V_154 . V_305 [ V_11 ] ) {
F_151 ( V_27 -> V_154 . V_305 [ V_11 ] ) ;
V_27 -> V_154 . V_305 [ V_11 ] = NULL ;
}
}
}
void F_152 ( struct V_26 * V_27 ,
struct V_251 * V_252 ,
struct V_307 * V_263 )
{
if ( V_27 -> V_154 . V_272 ) {
if ( V_263 )
F_153 (
V_27 -> V_154 . V_272 , V_263 ) ;
else
F_154 ( V_27 -> V_154 . V_272 ,
V_252 -> V_253 . V_5 . V_236 ) ;
}
}
int F_155 ( struct V_308 * V_309 )
{
if ( F_156 ( & V_309 -> V_310 ) != V_128 )
return - V_20 ;
return 0 ;
}
void F_157 ( struct V_26 * V_27 ,
struct V_308 * V_309 )
{
F_158 ( V_309 -> V_310 . V_247 ,
& V_309 -> V_247 ) ;
if ( V_27 && V_27 -> V_168 &&
V_309 -> V_247 == V_147 )
V_309 -> V_247 = V_159 ;
}
int F_159 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
struct V_311 * V_312 ,
int V_313 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
if ( V_313 >= V_97 )
return - V_20 ;
V_68 -> V_98 [ V_313 ] . V_99 . V_44 = V_312 -> V_44 ;
V_68 -> V_98 [ V_313 ] . V_99 . V_45 = V_312 -> V_45 ;
return 0 ;
}
int F_160 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
struct V_311 * V_312 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_103 . V_99 . V_44 = V_312 -> V_44 ;
V_68 -> V_103 . V_99 . V_45 = V_312 -> V_45 ;
return 0 ;
}
void F_161 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
unsigned int V_314 )
{
V_27 -> V_29 [ V_214 ]
. V_72 . V_114 = V_314 ;
}
void F_162 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
enum V_315 V_105 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_103 . V_105 = V_105 ;
}
void F_163 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
int V_316 ,
int V_313 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_98 [ V_313 ] . V_100 = V_316 ;
}
void F_164 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
bool V_102 ,
int V_313 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_98 [ V_313 ] . V_102 = V_102 ;
}
void F_165 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
enum V_317 V_101 ,
int V_313 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_98 [ V_313 ] . V_101 = V_101 ;
}
void F_166 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
enum V_317 V_101 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_103 . V_101 = V_101 ;
}
int F_167 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
struct V_311 * V_312 )
{
int V_11 ;
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
for ( V_11 = V_318 ;
V_11 < V_97 ; V_11 ++ )
V_68 -> V_98 [ V_11 ] . V_102 = false ;
F_159 ( V_27 , V_214 , V_312 ,
V_319 ) ;
F_165 ( V_27 , V_214 ,
V_68 -> V_103 . V_101 ,
V_319 ) ;
F_163 ( V_27 , V_214 , V_320 ,
V_319 ) ;
F_164 ( V_27 , V_214 , true ,
V_319 ) ;
return 0 ;
}
int F_168 ( struct V_26 * V_27 ,
enum V_213 V_214 ,
enum V_317 V_321 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_98 [ V_322 ] . V_99 . V_44 =
V_68 -> V_98 [ V_318 ] . V_99 . V_44 ;
V_68 -> V_98 [ V_322 ] . V_99 . V_45 =
V_68 -> V_98 [ V_318 ] . V_99 . V_45 / 2 ;
V_68 -> V_98 [ V_322 ] . V_100
= V_318 ;
V_68 -> V_98 [ V_318 ] . V_101 =
V_323 ;
V_68 -> V_98 [ V_322 ] . V_101 =
V_324 ;
V_68 -> V_98 [ V_322 ] . V_102 = true ;
return 0 ;
}
void F_169 (
struct V_26 * V_27 ,
enum V_213 V_214 ,
enum V_317 V_321 ,
unsigned int V_44 , unsigned int V_45 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_98 [ V_318 ] . V_99 . V_44 =
V_44 ;
V_68 -> V_98 [ V_318 ] . V_99 . V_45 =
V_45 ;
V_68 -> V_98 [ V_318 ] . V_101 =
V_321 ;
V_68 -> V_98 [ V_318 ] . V_102 = true ;
}
void F_170 (
struct V_26 * V_27 ,
enum V_213 V_214 ,
enum V_317 V_321 ,
unsigned int V_44 , unsigned int V_45 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_98 [ V_322 ] . V_99 . V_44 =
V_44 ;
V_68 -> V_98 [ V_322 ] . V_99 . V_45 =
V_45 ;
V_68 -> V_98 [ V_322 ] . V_100
= V_318 ;
V_68 -> V_98 [ V_322 ] . V_101 =
V_321 ;
V_68 -> V_98 [ V_322 ] . V_102 = true ;
}
int F_171 (
struct V_26 * V_27 ,
enum V_213 V_214 ,
unsigned int V_44 , unsigned int V_45 )
{
struct V_67 * V_68 =
& V_27 -> V_29 [ V_214 ] . V_72 ;
V_68 -> V_103 . V_104 . V_44 = V_44 ;
V_68 -> V_103 . V_104 . V_45 = V_45 ;
return 0 ;
}
void F_172 ( struct V_26 * V_27 ,
unsigned int V_325 , unsigned int V_326 )
{
V_27 -> V_29 [ V_246 ]
. V_38 [ V_153 ] . V_51 . V_44 = V_325 ;
V_27 -> V_29 [ V_246 ]
. V_38 [ V_153 ] . V_51 . V_45 = V_326 ;
}
void F_173 (
struct V_26 * V_27 ,
bool V_327 )
{
int V_11 ;
if ( V_27 -> V_29 [ V_246 ]
. V_72 . V_106 == ( V_327 ? 2 : 1 ) )
return;
V_27 -> V_29 [ V_246 ]
. V_72 . V_106 = ( V_327 ? 2 : 1 ) ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
V_27 -> V_29 [ V_246 ]
. V_125 [ V_11 ] = true ;
}
void F_174 ( struct V_26 * V_27 ,
bool V_209 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
unsigned int V_247 ;
if ( V_27 -> V_167 -> V_138 == V_173 )
V_247 = V_153 ;
else
V_247 = V_157 ;
V_29 -> V_39 [ V_247 ] . V_61 = V_209 ;
V_29 -> V_125 [ V_247 ] = true ;
if ( V_209 )
V_29 -> V_38 [ V_247 ] . V_42 [ 0 ] . V_48 =
V_29 -> V_72 . V_103 . V_104 . V_44 ;
}
void F_175 ( struct V_26 * V_27 , bool V_209 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
V_27 -> V_29 [ V_246 ]
. V_38 [ V_11 ] . V_59 = V_209 ;
}
void F_176 ( struct V_26 * V_27 ,
enum V_328 V_41 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
if ( V_29 -> V_38 [ V_147 ]
. V_58 . V_41 == V_41 )
return;
V_29 -> V_38 [ V_147 ] .
V_58 . V_41 = V_41 ;
V_29 -> V_125 [ V_147 ] = true ;
}
void F_177 ( struct V_26 * V_27 ,
enum V_329 V_41 )
{
int V_11 ;
struct V_31 * V_32 = V_27 -> V_32 ;
unsigned int V_118 ;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ )
V_27 -> V_29 [ V_11 ] . V_72 . V_41 = V_41 ;
if ( V_32 -> V_330 [ V_27 -> V_331 ] . type == V_332 ) {
struct V_67 * V_68 =
& V_27 -> V_29 [ V_246 ] . V_72 ;
V_68 -> V_41 = V_83 ;
V_68 -> V_75 . V_84 . V_41 = V_333 ;
V_68 -> V_75 . V_84 . V_86 = ( 1 << 4 ) - 1 ;
V_68 -> V_75 . V_84 . V_87 = - 2 ;
V_68 -> V_75 . V_84 . V_88 = ( 1 << 4 ) - 1 ;
V_68 -> V_75 . V_84 . V_89 = 3 ;
V_68 -> V_75 . V_84 . V_90 = ( 1 << 8 ) - 1 ;
return;
}
if ( V_41 != V_74 )
return;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
struct V_67 * V_68 =
& V_27 -> V_29 [ V_11 ] . V_72 ;
if ( V_68 -> V_103 . V_99 . V_44 == 0 )
continue;
if ( F_178 (
V_68 -> V_103 . V_99 . V_44 ,
V_68 -> V_103 . V_99 . V_45 ,
V_68 -> V_103 . V_101 ,
true ,
0x13000 ,
& V_118 ) != V_128 ) {
if ( F_179 () ==
V_334 )
V_118 = V_335 ;
else
V_118 = V_336 ;
F_42 ( V_27 -> V_32 -> V_40 ,
L_111
L_112 ,
V_118 ) ;
}
V_68 -> V_117 . V_118 = V_118 ;
V_68 -> V_117 . V_337 = 2 ;
}
}
void F_180 ( struct V_26 * V_27 ,
unsigned short V_289 , bool V_209 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_289 ] ;
if ( V_29 -> V_72 . V_107 == ! ! V_209 )
return;
V_29 -> V_72 . V_107 = ! ! V_209 ;
V_29 -> V_125 [ V_147 ] = true ;
}
void F_181 ( struct V_26 * V_27 ,
unsigned short V_289 , bool V_209 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_289 ] ;
int V_11 ;
if ( V_29 -> V_72 . V_107 != ! ! V_209 ) {
V_29 -> V_72 . V_107 = ! ! V_209 ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
V_29 -> V_125 [ V_11 ] = true ;
}
}
void F_182 ( struct V_26 * V_27 ,
bool V_209 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_338 ] ;
int V_11 ;
if ( V_29 -> V_72 . V_107 != V_209 ) {
V_29 -> V_72 . V_107 = V_209 ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
V_29 -> V_125 [ V_11 ] = true ;
}
}
void F_183 ( struct V_26 * V_27 ,
bool V_209 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
int V_11 ;
if ( F_184 ( V_27 ) ) {
V_29 -> V_72 . V_108 = 0 ;
V_29 -> V_72 . V_107 = 1 ;
return;
}
if ( V_29 -> V_72 . V_108 != ! ! V_209 ) {
V_29 -> V_72 . V_108 = ! ! V_209 ;
V_29 -> V_72 . V_115 = true ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
V_29 -> V_125 [ V_11 ] = true ;
}
}
void F_185 ( struct V_26 * V_27 ,
bool V_209 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
int V_11 ;
if ( V_29 -> V_72 . V_109 != ! V_209 ) {
V_29 -> V_72 . V_109 = ! V_209 ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
V_29 -> V_125 [ V_11 ] = true ;
}
}
int F_186 (
struct V_26 * V_27 ,
T_6 V_76 ,
unsigned int V_77 ,
unsigned int V_78 ,
unsigned int V_339 ,
enum V_317 V_340 ,
unsigned int V_341 ,
unsigned int V_342 )
{
int V_11 ;
struct V_28 * V_29 ;
const unsigned int V_79 =
F_187 ( ( ( V_339 / 46000 ) - 1280 ) >> 10 , 0xffU ) * 0x01010101U ;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
V_29 = & V_27 -> V_29 [ V_11 ] ;
V_29 -> V_72 . V_75 . V_76 . V_76 = V_76 ;
V_29 -> V_72 . V_75 . V_76 . V_77 = V_77 ;
V_29 -> V_72 . V_75 . V_76 . V_78 = V_78 ;
if ( V_339 )
V_29 -> V_72 . V_75 . V_76 . V_79 = V_79 ;
V_29 -> V_72 .
V_120 . V_121 = V_340 ;
V_29 -> V_72 .
V_120 . V_122 . V_44 = V_341 ;
V_29 -> V_72 .
V_120 . V_122 . V_45 = V_342 ;
}
return 0 ;
}
int F_188 ( struct V_343 * * V_221 ,
unsigned int V_44 , unsigned int V_45 ,
enum V_344 V_101 ,
unsigned int V_48 ,
unsigned int V_345 )
{
if ( F_189 ( V_221 , V_44 , V_45 , V_101 ,
V_48 , V_345 ) != V_128 )
return - V_294 ;
return 0 ;
}
int F_190 ( struct V_343 * * V_221 ,
const struct V_346 * V_208 )
{
if ( F_191 ( V_221 , V_208 ) != V_128 )
return - V_294 ;
return 0 ;
}
void F_192 ( struct V_343 * V_221 )
{
F_193 ( V_221 ) ;
}
int F_194 ( struct V_343 * * V_221 ,
const struct V_346 * V_208 ,
const void * V_5 , T_3 V_347 ,
void * V_1 )
{
if ( F_195 ( V_221 , V_208 , V_5 , V_347 , V_1 )
!= V_128 )
return - V_294 ;
return 0 ;
}
int F_196 ( struct V_26 * V_27 ,
const struct V_343 * V_348 )
{
if ( F_197 (
V_27 -> V_29 [ V_246 ] . V_124 ,
V_348 ) != V_128 )
return - V_294 ;
return 0 ;
}
int F_198 ( bool V_349 ,
struct V_26 * V_27 )
{
if ( F_199 (
V_27 -> V_29 [ V_246 ] . V_124 )
!= V_128 )
return - V_20 ;
return 0 ;
}
void F_200 ( struct V_26 * V_27 )
{
F_201 (
V_27 -> V_29 [ V_246 ] . V_124 ) ;
}
int F_202 ( struct V_26 * V_27 ,
enum V_217 V_30 , bool V_242 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_228 * V_229 ;
struct V_233 * V_234 ;
struct V_223 * V_254 ;
unsigned long V_350 ;
unsigned int V_11 ;
if ( F_45 ( V_27 , true ) )
F_32 ( V_32 -> V_40 , L_73 ) ;
if ( F_52 ( V_27 , true ) )
F_32 ( V_32 -> V_40 , L_113 ) ;
F_203 ( V_27 ) ;
if ( F_103 ( V_32 ) == 0 )
F_107 () ;
if ( ! V_242 ) {
struct V_28 * V_29 ;
int V_11 , V_69 ;
for ( V_11 = 0 ; V_11 < V_132 ; V_11 ++ ) {
V_29 = & V_27 -> V_29 [ V_11 ] ;
for ( V_69 = 0 ; V_69 < V_71 ; V_69 ++ ) {
F_89 (
& V_29 -> V_38 [ V_69 ] ) ;
F_59 (
& V_29 -> V_39 [ V_69 ] ) ;
}
F_90 (
& V_29 -> V_72 ) ;
}
F_33 ( & V_27 -> V_154 . V_25 ) ;
V_27 -> V_154 . V_203 = false ;
}
while ( ! F_204 ( & V_27 -> V_351 ) ) {
V_229 = F_205 ( V_27 -> V_351 . V_352 ,
struct V_228 , V_278 ) ;
F_136 ( & V_229 -> V_278 ) ;
F_206 ( & V_229 -> V_278 , & V_27 -> V_353 ) ;
}
while ( ! F_204 ( & V_27 -> V_354 ) ) {
V_229 = F_205 ( V_27 -> V_354 . V_352 ,
struct V_228 , V_278 ) ;
F_136 ( & V_229 -> V_278 ) ;
F_206 ( & V_229 -> V_278 , & V_27 -> V_353 ) ;
}
F_9 ( & V_27 -> V_355 , V_350 ) ;
while ( ! F_204 ( & V_27 -> V_356 ) ) {
V_234 = F_205 ( V_27 -> V_356 . V_352 ,
struct V_233 , V_278 ) ;
F_136 ( & V_234 -> V_278 ) ;
F_206 ( & V_234 -> V_278 , & V_27 -> V_357 ) ;
}
V_27 -> V_154 . V_277 = false ;
F_11 ( & V_27 -> V_355 , V_350 ) ;
for ( V_11 = 0 ; V_11 < V_282 ; V_11 ++ ) {
while ( ! F_204 ( & V_27 -> V_358 [ V_11 ] ) ) {
V_254 = F_205 ( V_27 -> V_358 [ V_11 ] . V_352 ,
struct V_223 , V_278 ) ;
F_136 ( & V_254 -> V_278 ) ;
F_206 ( & V_254 -> V_278 , & V_27 -> V_227 [ V_11 ] ) ;
}
while ( ! F_204 ( & V_27 -> V_359 [ V_11 ] ) ) {
V_254 = F_205 ( V_27 -> V_359 [ V_11 ] . V_352 ,
struct V_223 , V_278 ) ;
F_136 ( & V_254 -> V_278 ) ;
F_206 ( & V_254 -> V_278 , & V_27 -> V_227 [ V_11 ] ) ;
}
}
F_207 ( & V_27 -> V_360 ) ;
F_207 ( & V_27 -> V_361 ) ;
F_207 ( & V_27 -> V_362 ) ;
F_207 ( & V_27 -> V_363 ) ;
F_208 ( & V_27 -> V_154 . V_270 ) ;
memset ( & V_27 -> V_154 . V_270 , 0 , sizeof( V_27 -> V_154 . V_270 ) ) ;
return 0 ;
}
int F_209 (
struct V_26 * V_27 ,
int V_364 )
{
if ( V_27 -> V_141 -> V_138 ) {
V_27 -> V_29 [ V_246 ]
. V_72 . V_111 =
V_365 ;
if ( V_27 -> V_167 -> V_138 == V_173 &&
V_27 -> V_154 . V_155 )
V_27 -> V_29 [ V_246 ]
. V_72 . V_111 +=
V_156 ;
} else {
V_27 -> V_29 [ V_246 ]
. V_72 . V_111 =
V_366 ;
}
if ( V_27 -> V_154 . V_155 )
V_27 -> V_29 [ V_246 ]
. V_72 . V_111 +=
V_156 ;
V_27 -> V_29 [ V_246 ]
. V_72 . V_112 = V_364 ;
return 0 ;
}
void F_210 ( struct V_26 * V_27 ,
bool V_367 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 ++ )
V_27 -> V_29 [ V_246 ]
. V_39 [ V_11 ] . V_66 = ! ! V_367 ;
}
static enum V_368 F_211 (
struct V_26 * V_27 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_369 * V_370 = F_212 (
V_32 -> V_330 [ V_27 -> V_331 ] . V_371 ) ;
switch ( V_30 ) {
case V_159 :
if ( V_370 && V_370 -> V_321 ==
V_372 )
return V_373 ;
return V_374 ;
case V_157 :
return V_375 ;
case V_147 :
return V_376 ;
case V_153 :
return V_377 ;
case V_160 :
return V_161 ;
case V_158 :
return V_373 ;
default:
F_213 ( 1 ) ;
return V_375 ;
}
}
static void F_214 ( struct V_26 * V_27 ,
unsigned int V_289 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_379 V_101 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_289 ] ;
struct V_67 * V_68 = & V_29 -> V_72 ;
V_29 -> V_38 [ V_30 ] . V_41 =
F_211 ( V_27 , V_30 ) ;
V_29 -> V_125 [ V_30 ] = true ;
V_29 -> V_38 [ V_30 ] . V_42 [ 0 ] . V_43 . V_44 = V_44 ;
V_29 -> V_38 [ V_30 ] . V_42 [ 0 ] . V_43 . V_45 = V_45 ;
V_29 -> V_38 [ V_30 ] . V_42 [ 0 ] . V_101 = V_101 ;
V_29 -> V_38 [ V_30 ] . V_42 [ 0 ] . V_48 = V_378 ;
if ( V_44 > V_68 -> V_103 . V_104 . V_44 ||
V_45 > V_68 -> V_103 . V_104 . V_45 ) {
V_68 -> V_103 . V_104 . V_44 = V_44 ;
V_68 -> V_103 . V_104 . V_45 = V_45 ;
}
F_35 ( V_32 -> V_40 , L_114 ,
V_30 , V_44 , V_45 , V_101 ) ;
}
static void F_215 ( struct V_26 * V_27 ,
unsigned int V_289 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_379 V_101 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_289 ] ;
struct V_380 * V_381 ;
struct V_67 * V_72 = & V_29 -> V_72 ;
V_29 -> V_38 [ V_30 ] . V_41 =
F_211 ( V_27 , V_30 ) ;
V_29 -> V_125 [ V_30 ] = true ;
if ( V_27 -> V_171 -> V_138 )
V_381 = & V_29 -> V_38 [ V_30 ] .
V_42 [ V_382 ] ;
else
V_381 = & V_29 -> V_38 [ V_30 ] .
V_42 [ V_383 ] ;
V_381 -> V_43 . V_44 = V_44 ;
V_381 -> V_43 . V_45 = V_45 ;
V_381 -> V_101 = V_101 ;
V_381 -> V_48 = V_378 ;
if ( V_44 > V_72 -> V_103 . V_104 . V_44 ||
V_45 > V_72 -> V_103 . V_104 . V_45 ) {
V_72 -> V_103 . V_104 . V_44 = V_44 ;
V_72 -> V_103 . V_104 . V_45 = V_45 ;
}
F_35 ( V_32 -> V_40 , L_114 ,
V_30 , V_44 , V_45 , V_101 ) ;
}
static void F_216 ( struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
struct V_67 * V_72 = & V_29 -> V_72 ;
struct V_34 * V_38 =
& V_29 -> V_38 [ V_30 ] ;
struct V_36 * V_39 =
& V_29 -> V_39 [ V_30 ] ;
unsigned int V_384 = 0 , V_385 = 0 ;
if ( V_44 == 0 && V_45 == 0 )
return;
if ( V_44 * 9 / 10 < V_38 -> V_42 [ 0 ] . V_43 . V_44 ||
V_45 * 9 / 10 < V_38 -> V_42 [ 0 ] . V_43 . V_45 )
return;
V_384 = F_217 ( V_44 >> 1 ,
V_38 -> V_42 [ 0 ] . V_43 . V_44 ) ;
V_385 = F_217 ( V_45 >> 1 ,
V_38 -> V_42 [ 0 ] . V_43 . V_45 ) ;
if ( ( V_27 -> V_32 -> V_386 . V_387 <
( V_388 << V_389 ) ||
V_390 ) && V_384 != V_385 ) {
F_42 ( V_27 -> V_32 -> V_40 ,
L_115 ) ;
return;
}
V_38 -> V_41 = F_211 ( V_27 , V_30 ) ;
V_29 -> V_125 [ V_30 ] = true ;
V_39 -> V_62 = true ;
V_38 -> V_47 . V_44 =
V_72 -> V_103 . V_104 . V_44 ;
V_38 -> V_47 . V_45 =
V_72 -> V_103 . V_104 . V_45 ;
F_35 ( V_32 -> V_40 , L_116 ,
V_30 , V_44 , V_45 ) ;
}
static void F_218 ( struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
int V_391 , V_392 , V_393 , V_394 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
struct V_67 * V_72 = & V_29 -> V_72 ;
struct V_34 * V_38 =
& V_29 -> V_38 [ V_30 ] ;
struct V_36 * V_39 =
& V_29 -> V_39 [ V_30 ] ;
struct V_395 * V_50 =
& V_38 -> V_50 ;
struct V_395 * V_46 =
& V_38 -> V_46 ;
struct V_395 * V_104 =
& V_72 -> V_103 . V_104 ;
const struct V_396 V_397 [] = { { 2 , 1 } , { 3 , 2 } , { 5 , 4 } } ;
const unsigned int V_398 [] = { 2 } ;
unsigned int V_11 ;
if ( V_44 == 0 && V_45 == 0 )
return;
V_38 -> V_41 = F_211 ( V_27 , V_30 ) ;
V_29 -> V_125 [ V_30 ] = true ;
V_391 = V_38 -> V_42 [ 0 ] . V_43 . V_44 ;
V_392 = V_38 -> V_42 [ 0 ] . V_43 . V_45 ;
if ( V_72 -> V_107 || ! V_72 -> V_108 ||
! V_39 -> V_61 ) {
V_50 -> V_44 = 0 ;
V_50 -> V_45 = 0 ;
} else {
V_50 -> V_44 = V_104 -> V_44 ;
V_50 -> V_45 = V_104 -> V_45 ;
for ( V_11 = 0 ; V_11 < F_219 ( V_397 ) ; V_11 ++ ) {
if ( V_104 -> V_44 >= V_391 *
V_397 [ V_11 ] . V_399 / V_397 [ V_11 ] . V_400 &&
V_104 -> V_45 >= V_392 *
V_397 [ V_11 ] . V_399 / V_397 [ V_11 ] . V_400 ) {
V_50 -> V_44 =
V_104 -> V_44 *
V_397 [ V_11 ] . V_400 /
V_397 [ V_11 ] . V_399 ;
V_50 -> V_45 =
V_104 -> V_45 *
V_397 [ V_11 ] . V_400 /
V_397 [ V_11 ] . V_399 ;
break;
}
}
}
if ( V_50 -> V_44 == 0 ) {
V_393 = V_104 -> V_44 ;
V_394 = V_104 -> V_45 ;
} else {
V_393 = V_50 -> V_44 ;
V_394 = V_50 -> V_45 ;
}
V_46 -> V_44 = V_393 ;
V_46 -> V_45 = V_394 ;
for ( V_11 = 0 ; V_11 < F_219 ( V_398 ) ; V_11 ++ ) {
if ( V_393 >= V_391 * V_398 [ V_11 ] &&
V_394 >= V_392 * V_398 [ V_11 ] ) {
V_46 -> V_44 = V_393 / V_398 [ V_11 ] ;
V_46 -> V_45 = V_394 / V_398 [ V_11 ] ;
break;
}
}
if ( V_46 -> V_44 == V_391 &&
V_46 -> V_45 == V_392 ) {
V_39 -> V_62 = false ;
V_46 -> V_44 = 0 ;
V_46 -> V_45 = 0 ;
} else {
V_39 -> V_62 = true ;
}
F_35 ( V_32 -> V_40 , L_117 ,
V_30 , V_44 , V_45 ) ;
}
static void F_220 ( struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
int V_391 , V_392 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
struct V_67 * V_72 = & V_29 -> V_72 ;
struct V_34 * V_38 =
& V_29 -> V_38 [ V_30 ] ;
struct V_36 * V_39 =
& V_29 -> V_39 [ V_30 ] ;
struct V_395 * V_50 =
& V_38 -> V_50 ;
struct V_395 * V_104 =
& V_72 -> V_103 . V_104 ;
const struct V_396 V_401 [] = {
{ 8 , 1 } , { 6 , 1 } , { 4 , 1 } , { 3 , 1 } , { 2 , 1 } , { 3 , 2 } } ;
unsigned int V_11 ;
if ( V_44 == 0 && V_45 == 0 )
return;
V_38 -> V_41 = F_211 ( V_27 , V_30 ) ;
V_29 -> V_125 [ V_30 ] = true ;
V_39 -> V_62 = false ;
if ( V_27 -> V_154 . V_155 ) {
V_391 = V_38 -> V_42 [ 0 ] . V_43 . V_44 * 110 / 100 ;
V_392 = V_38 -> V_42 [ 0 ] . V_43 . V_45 * 110 / 100 ;
} else {
V_391 = V_38 -> V_42 [ 0 ] . V_43 . V_44 ;
V_392 = V_38 -> V_42 [ 0 ] . V_43 . V_45 ;
}
if ( V_72 -> V_107 || ! V_72 -> V_108 ) {
V_50 -> V_44 = 0 ;
V_50 -> V_45 = 0 ;
goto V_402;
}
V_39 -> V_61 = true ;
V_50 -> V_44 = V_104 -> V_44 ;
V_50 -> V_45 = V_104 -> V_45 ;
for ( V_11 = 0 ; V_11 < sizeof( V_401 ) / sizeof( struct V_396 ) ;
V_11 ++ ) {
if ( V_104 -> V_44 >= V_391 *
V_401 [ V_11 ] . V_399 / V_401 [ V_11 ] . V_400 &&
V_104 -> V_45 >= V_392 *
V_401 [ V_11 ] . V_399 / V_401 [ V_11 ] . V_400 ) {
V_50 -> V_44 = V_104 -> V_44 *
V_401 [ V_11 ] . V_400 /
V_401 [ V_11 ] . V_399 ;
V_50 -> V_45 = V_104 -> V_45 *
V_401 [ V_11 ] . V_400 /
V_401 [ V_11 ] . V_399 ;
break;
}
}
V_38 -> V_51 . V_44 = 12 ;
V_38 -> V_51 . V_45 = 12 ;
V_402:
if ( V_30 == V_158 )
V_72 -> V_113 = - 1 ;
else
V_72 -> V_113 = 12 ;
F_35 ( V_32 -> V_40 , L_118 ,
V_30 , V_44 , V_45 ) ;
}
static void F_221 ( struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_344 V_101 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
V_29 -> V_38 [ V_30 ] . V_41 =
F_211 ( V_27 , V_30 ) ;
V_29 -> V_125 [ V_30 ] = true ;
V_29 -> V_38 [ V_30 ] . V_49 [ 0 ] . V_43 . V_44 = V_44 ;
V_29 -> V_38 [ V_30 ] . V_49 [ 0 ] . V_43 . V_45 = V_45 ;
V_29 -> V_38 [ V_30 ] . V_49 [ 0 ] . V_101 = V_101 ;
V_29 -> V_38 [ V_30 ] . V_49 [ 0 ] . V_48 =
V_378 ;
F_35 ( V_32 -> V_40 ,
L_119 ,
V_30 , V_44 , V_45 , V_101 ) ;
}
static void F_222 ( struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_344 V_101 ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
struct V_380 * V_381 ;
V_29 -> V_38 [ V_30 ] . V_41 =
F_211 ( V_27 , V_30 ) ;
V_29 -> V_125 [ V_30 ] = true ;
if ( V_27 -> V_171 -> V_138 )
V_381 = & V_29 -> V_38 [ V_30 ] .
V_49 [ V_382 ] ;
else
V_381 = & V_29 -> V_38 [ V_30 ] .
V_49 [ V_383 ] ;
V_381 -> V_43 . V_44 = V_44 ;
V_381 -> V_43 . V_45 = V_45 ;
V_381 -> V_101 = V_101 ;
V_381 -> V_48 = V_378 ;
F_35 ( V_32 -> V_40 ,
L_119 ,
V_30 , V_44 , V_45 , V_101 ) ;
}
static int F_223 ( struct V_26 * V_27 ,
unsigned int V_289 ,
struct V_346 * V_208 ,
enum V_403 type ,
enum V_145 V_30 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
enum V_176 V_8 ;
struct V_285 V_286 ;
if ( F_45 ( V_27 , true ) )
F_42 ( V_32 -> V_40 , L_73 ) ;
if ( F_52 ( V_27 , true ) )
F_42 ( V_32 -> V_40 , L_78 ) ;
if ( F_62 ( V_27 ) )
return - V_20 ;
if ( F_49 ( V_27 ) )
goto V_244;
V_8 = F_143 (
V_27 -> V_29 [ V_289 ]
. V_33 [ V_30 ] , & V_286 ) ;
if ( V_8 == V_128 ) {
switch ( type ) {
case V_404 :
* V_208 = V_286 . V_49 [ 0 ] ;
F_35 ( V_32 -> V_40 , L_120 ) ;
break;
case V_405 :
* V_208 = V_286 . V_49 [ 1 ] ;
F_35 ( V_32 -> V_40 , L_121 ) ;
break;
case V_406 :
* V_208 = V_286 . V_42 [ 0 ] ;
F_35 ( V_32 -> V_40 , L_122 ) ;
break;
case V_407 :
* V_208 = V_286 . V_42 [ 1 ] ;
F_35 ( V_32 -> V_40 , L_123 ) ;
break;
case V_408 :
* V_208 = V_286 . V_409 ;
F_35 ( V_32 -> V_40 , L_124 ) ;
}
F_35 ( V_32 -> V_40 , L_125 ,
V_208 -> V_43 . V_44 , V_208 -> V_43 . V_45 , V_286 . V_410 ) ;
return 0 ;
}
V_244:
F_52 ( V_27 , true ) ;
return - V_20 ;
}
unsigned int F_224 ( struct V_26 * V_27 ,
T_3 V_284 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
if ( F_184 ( V_27 ) )
return V_158 ;
switch ( V_284 ) {
case V_411 :
if ( V_27 -> V_412 )
return V_158 ;
if ( V_27 -> V_168 )
return V_159 ;
if ( V_27 -> V_167 -> V_138 == V_173
|| V_27 -> V_164 -> V_138 == V_165 )
return V_153 ;
else
return V_147 ;
case V_413 :
if ( V_27 -> V_168 )
return V_159 ;
return V_147 ;
case V_414 :
if ( ! F_225 (
V_27 -> V_15 [ V_27 -> V_415 ] . V_15 . V_416 ) )
return V_147 ;
case V_417 :
if ( V_27 -> V_412 )
return V_158 ;
if ( V_27 -> V_168 )
return V_159 ;
if ( V_27 -> V_167 -> V_138 == V_173 )
return V_153 ;
else
return V_157 ;
}
F_42 ( V_32 -> V_40 ,
L_126 ,
V_284 ) ;
return V_157 ;
}
int F_226 ( struct V_26 * V_27 ,
T_3 V_284 ,
struct V_346 * V_418 )
{
struct V_285 V_208 ;
int V_134 = F_224 ( V_27 , V_284 ) ;
int V_289 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( F_56 ( V_27 ) )
V_289 = F_142 ( V_27 , V_284 ) ;
else {
V_289 = ( V_134 == V_158 ) ?
V_338 :
F_142 ( V_27 , V_284 ) ;
}
if ( V_128 != F_143 ( V_27 -> V_29 [ V_289 ]
. V_33 [ V_134 ] , & V_208 ) ) {
F_32 ( V_32 -> V_40 , L_127 ) ;
return - V_20 ;
}
switch ( V_284 ) {
case V_413 :
* V_418 = V_208 . V_42 [ 0 ] ;
break;
case V_411 :
if ( F_184 ( V_27 ) && V_27 -> V_171 -> V_138 )
* V_418 = V_208 .
V_42 [ V_382 ] ;
else
* V_418 = V_208 .
V_42 [ V_383 ] ;
break;
case V_414 :
if ( V_289 == V_419 )
* V_418 = V_208 . V_42 [ 0 ] ;
else
* V_418 = V_208 . V_49 [ 0 ] ;
break;
case V_417 :
if ( V_27 -> V_167 -> V_138 == V_173 &&
( V_134 == V_153 ||
V_134 == V_158 ) )
if ( F_184 ( V_27 ) && V_27 -> V_171 -> V_138 )
* V_418 = V_208 .
V_49 [ V_382 ] ;
else
* V_418 = V_208 .
V_49 [ V_383 ] ;
else if ( F_184 ( V_27 ) && V_27 -> V_171 -> V_138 )
* V_418 =
V_208 . V_42 [ V_382 ] ;
else
* V_418 =
V_208 . V_42 [ V_383 ] ;
break;
default:
V_418 = NULL ;
break;
}
return V_418 ? 0 : - V_20 ;
}
int F_227 ( struct V_26 * V_27 ,
unsigned int V_289 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_48 ,
enum V_344 V_101 )
{
V_27 -> V_29 [ V_289 ] . V_38 [ V_159 ] .
V_58 . V_41 =
V_148 ;
F_214 ( V_27 , V_289 , V_44 , V_45 , V_48 ,
V_101 , V_159 ) ;
return 0 ;
}
int F_228 ( struct V_26 * V_27 ,
unsigned int V_289 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_48 ,
enum V_344 V_101 )
{
V_27 -> V_29 [ V_289 ] . V_38 [ V_158 ] .
V_58 . V_41 =
V_148 ;
F_214 ( V_27 , V_289 , V_44 , V_45 , V_48 ,
V_101 , V_158 ) ;
return 0 ;
}
int F_229 (
struct V_26 * V_27 ,
unsigned int V_289 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_344 V_101 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_289 ] ;
enum V_145 V_30 = V_158 ;
V_29 -> V_38 [ V_30 ] . V_41 =
F_211 ( V_27 , V_30 ) ;
V_29 -> V_125 [ V_30 ] = true ;
V_29 -> V_38 [ V_30 ] . V_49 [ 0 ] . V_43 . V_44 = V_44 ;
V_29 -> V_38 [ V_30 ] . V_49 [ 0 ] . V_43 . V_45 = V_45 ;
V_29 -> V_38 [ V_30 ] . V_49 [ 0 ] . V_101 = V_101 ;
V_29 -> V_38 [ V_30 ] . V_49 [ 0 ] . V_48 =
V_378 ;
return 0 ;
}
int F_230 (
struct V_26 * V_27 ,
unsigned int V_289 ,
struct V_346 * V_208 )
{
return F_223 ( V_27 , V_289 , V_208 ,
V_406 , V_158 ) ;
}
int F_231 (
struct V_26 * V_27 ,
unsigned int V_289 ,
struct V_346 * V_208 )
{
return F_223 ( V_27 , V_289 , V_208 ,
V_404 , V_158 ) ;
}
int F_232 ( struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_344 V_101 )
{
if ( F_184 ( V_27 ) )
F_215 ( V_27 , V_246 , V_44 , V_45 ,
V_378 , V_101 , V_158 ) ;
else
F_214 ( V_27 , V_246 , V_44 , V_45 ,
V_378 , V_101 , V_157 ) ;
return 0 ;
}
int F_233 ( struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_344 V_101 )
{
enum V_145 V_30 ;
if ( F_184 ( V_27 ) )
V_30 = V_158 ;
else
V_30 = V_147 ;
F_214 ( V_27 , V_246 , V_44 , V_45 ,
V_378 , V_101 , V_30 ) ;
return 0 ;
}
int F_234 ( struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_344 V_101 )
{
if ( F_184 ( V_27 ) )
F_215 ( V_27 , V_246 , V_44 , V_45 ,
V_378 , V_101 , V_158 ) ;
else
F_214 ( V_27 , V_246 , V_44 , V_45 ,
V_378 , V_101 , V_153 ) ;
return 0 ;
}
int F_235 (
struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_344 V_101 )
{
if ( F_184 ( V_27 ) )
F_222 ( V_27 , V_44 , V_45 , V_378 , V_101 ,
V_158 ) ;
else
F_221 ( V_27 , V_44 , V_45 , V_378 , V_101 ,
V_153 ) ;
return 0 ;
}
int F_236 (
struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 ,
unsigned int V_378 ,
enum V_344 V_101 )
{
enum V_145 V_30 ;
if ( F_184 ( V_27 ) )
V_30 = V_158 ;
else
V_30 = V_147 ;
F_221 ( V_27 , V_44 , V_45 , V_378 , V_101 ,
V_30 ) ;
return 0 ;
}
int F_237 (
struct V_26 * V_27 ,
struct V_346 * V_208 )
{
enum V_145 V_30 ;
enum V_403 V_420 = V_404 ;
if ( F_184 ( V_27 ) ) {
V_30 = V_158 ;
if ( V_27 -> V_171 -> V_138 )
V_420 = V_405 ;
} else {
V_30 = V_153 ;
}
return F_223 ( V_27 , V_246 , V_208 ,
V_420 , V_30 ) ;
}
int F_238 (
struct V_26 * V_27 ,
struct V_346 * V_208 )
{
enum V_145 V_30 ;
if ( F_184 ( V_27 ) )
V_30 = V_158 ;
else
V_30 = V_147 ;
return F_223 ( V_27 , V_246 , V_208 ,
V_404 , V_30 ) ;
}
int F_239 (
struct V_26 * V_27 ,
struct V_346 * V_208 )
{
if ( F_184 ( V_27 ) )
return 0 ;
return F_223 ( V_27 , V_246 , V_208 ,
V_408 , V_147 ) ;
}
int F_240 (
struct V_26 * V_27 ,
unsigned int V_289 ,
struct V_346 * V_208 )
{
return F_223 ( V_27 , V_289 , V_208 ,
V_406 , V_159 ) ;
}
int F_241 (
struct V_26 * V_27 ,
struct V_346 * V_208 )
{
enum V_145 V_30 ;
enum V_403 V_420 = V_406 ;
if ( F_184 ( V_27 ) ) {
V_30 = V_158 ;
if ( V_27 -> V_171 -> V_138 )
V_420 = V_407 ;
} else {
V_30 = V_157 ;
}
return F_223 ( V_27 , V_246 , V_208 ,
V_420 , V_30 ) ;
}
int F_242 (
struct V_26 * V_27 ,
struct V_346 * V_208 )
{
enum V_145 V_30 ;
if ( F_184 ( V_27 ) )
V_30 = V_158 ;
else
V_30 = V_147 ;
return F_223 ( V_27 , V_246 , V_208 ,
V_406 , V_30 ) ;
}
int F_243 (
struct V_26 * V_27 ,
struct V_346 * V_208 )
{
enum V_145 V_30 ;
enum V_403 V_420 = V_406 ;
if ( F_184 ( V_27 ) ) {
V_30 = V_158 ;
if ( V_27 -> V_171 -> V_138 )
V_420 = V_407 ;
} else {
V_30 = V_153 ;
}
return F_223 ( V_27 , V_246 , V_208 ,
V_420 , V_30 ) ;
}
int F_244 (
struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
F_218 ( V_27 , V_44 , V_45 ,
F_184 ( V_27 ) ?
V_158 : V_157 ) ;
if ( V_44 > V_29 -> V_38 [ V_147 ] .
V_47 . V_44 )
F_216 ( V_27 , V_44 , V_45 ,
F_184 ( V_27 ) ?
V_158 : V_147 ) ;
return 0 ;
}
int F_245 (
struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 )
{
F_216 ( V_27 , V_44 , V_45 ,
F_184 ( V_27 ) ?
V_158 : V_147 ) ;
return 0 ;
}
int F_246 (
struct V_26 * V_27 ,
unsigned int V_44 , unsigned int V_45 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
F_220 ( V_27 , V_44 , V_45 ,
F_184 ( V_27 ) ?
V_158 : V_153 ) ;
if ( V_44 > V_29 -> V_38 [ V_147 ] .
V_47 . V_44 )
F_216 ( V_27 , V_44 , V_45 ,
F_184 ( V_27 ) ?
V_158 : V_147 ) ;
return 0 ;
}
int F_247 ( struct V_26 * V_27 ,
int V_421 , unsigned int V_422 , int V_423 )
{
enum V_176 V_8 ;
#ifdef F_55
F_35 ( V_27 -> V_32 -> V_40 , L_128 ,
V_205 , V_421 , V_422 , V_423 ) ;
#endif
V_8 = F_248 (
V_27 -> V_29 [ V_246 ] . V_124 ,
V_421 , V_422 , V_423 ) ;
if ( V_8 != V_128 )
return - V_20 ;
return 0 ;
}
int F_249 ( struct V_26 * V_27 , int V_424 )
{
enum V_176 V_8 ;
V_8 = F_250 (
V_27 -> V_29 [ V_246 ] . V_124 ,
V_424 ) ;
if ( V_8 == V_425 ) {
return - V_426 ;
} else if ( V_8 != V_128 ) {
return - V_178 ;
}
return 0 ;
}
int F_251 ( struct V_26 * V_27 , int V_424 )
{
enum V_176 V_8 ;
V_8 = F_252 (
V_27 -> V_29 [ V_246 ] . V_124 ,
V_424 ) ;
if ( V_8 == V_425 )
return - V_427 ;
else if ( V_8 != V_128 )
return - V_178 ;
return 0 ;
}
int F_253 ( struct V_26 * V_27 ,
bool V_209 )
{
V_27 -> V_29 [ V_246 ]
. V_38 [ V_147 ]
. V_58 . V_60 = V_209 ;
V_27 -> V_154 . V_428 . V_60 = V_209 ;
V_27 -> V_29 [ V_246 ]
. V_125 [ V_147 ] = true ;
return 0 ;
}
void F_254 ( struct V_26 * V_27 ,
unsigned short * V_5 , unsigned int V_44 ,
unsigned int V_45 )
{
F_255 (
V_27 -> V_29 [ V_246 ] . V_124 ,
V_5 , V_44 , V_45 ) ;
}
bool F_256 ( void )
{
return F_257 () ;
}
void F_258 ( struct V_26 * V_27 )
{
F_259 (
V_27 -> V_29 [ V_246 ] . V_124 ) ;
}
void F_260 ( struct V_26 * V_27 ,
struct V_429 * V_430 )
{
V_27 -> V_154 . V_25 . V_430 = V_430 ;
}
void F_261 ( struct V_26 * V_27 ,
struct V_431 * V_432 )
{
V_27 -> V_154 . V_25 . V_432 = V_432 ;
}
void F_262 ( struct V_26 * V_27 ,
struct V_433 * V_434 )
{
V_27 -> V_154 . V_25 . V_434 = V_434 ;
}
void F_263 ( struct V_26 * V_27 ,
struct V_435 * V_436 )
{
V_27 -> V_154 . V_25 . V_436 = V_436 ;
}
void F_264 ( struct V_26 * V_27 ,
struct V_437 * V_438 )
{
V_27 -> V_154 . V_25 . V_438 = V_438 ;
}
void F_265 ( struct V_26 * V_27 )
{
V_27 -> V_154 . V_25 . V_436 = NULL ;
}
void F_266 ( struct V_26 * V_27 ,
struct V_439 * V_440 )
{
V_27 -> V_154 . V_25 . V_440 = V_440 ;
}
void F_267 ( struct V_26 * V_27 ,
struct V_441 * V_442 )
{
V_27 -> V_154 . V_25 . V_442 = V_442 ;
}
void F_268 ( struct V_26 * V_27 ,
struct V_443 * V_444 )
{
V_27 -> V_154 . V_25 . V_444 = V_444 ;
}
void F_269 ( struct V_26 * V_27 ,
struct V_445 * V_446 )
{
V_27 -> V_154 . V_25 . V_446 = V_446 ;
}
void F_270 ( struct V_26 * V_27 ,
struct V_447 * V_448 )
{
V_27 -> V_154 . V_25 . V_448 = V_448 ;
}
void F_271 ( struct V_26 * V_27 ,
struct V_449 * V_450 )
{
V_27 -> V_154 . V_25 . V_450 = V_450 ;
}
void F_272 ( struct V_26 * V_27 ,
struct V_451 * V_452 )
{
V_27 -> V_154 . V_25 . V_452 = V_452 ;
}
void F_273 ( struct V_26 * V_27 ,
struct V_453 * V_454 )
{
V_27 -> V_154 . V_25 . V_454 = V_454 ;
}
void F_274 ( struct V_26 * V_27 ,
struct V_455 * V_456 )
{
V_27 -> V_154 . V_25 . V_456 = V_456 ;
}
void F_275 ( struct V_26 * V_27 ,
struct V_457 * V_458 )
{
V_27 -> V_154 . V_25 . V_458 = V_458 ;
}
void F_276 ( struct V_26 * V_27 ,
struct V_459 * V_460 )
{
V_27 -> V_154 . V_25 . V_460 = V_460 ;
}
void F_277 ( struct V_26 * V_27 ,
struct V_461 * V_462 )
{
V_27 -> V_154 . V_25 . V_462 = V_462 ;
}
void F_278 ( struct V_26 * V_27 ,
struct V_463 * V_464 )
{
V_27 -> V_154 . V_25 . V_464 = V_464 ;
}
void F_279 ( struct V_26 * V_27 ,
struct V_465 * V_466 )
{
V_27 -> V_154 . V_25 . V_466 = V_466 ;
}
void F_280 ( struct V_26 * V_27 ,
struct V_467 * V_468 )
{
V_27 -> V_154 . V_25 . V_468 = V_468 ;
}
void F_281 ( struct V_26 * V_27 ,
struct V_469 * V_470 )
{
V_27 -> V_154 . V_25 . V_470 = V_470 ;
}
void F_282 ( struct V_26 * V_27 ,
struct V_447 * V_471 )
{
V_27 -> V_154 . V_25 . V_471 = V_471 ;
}
void F_283 ( struct V_26 * V_27 ,
struct V_447 * V_472 )
{
V_27 -> V_154 . V_25 . V_472 = V_472 ;
}
void F_284 ( struct V_26 * V_27 ,
struct V_473 * V_474 )
{
V_27 -> V_154 . V_25 . V_474 = V_474 ;
}
void F_285 ( struct V_26 * V_27 ,
struct V_475 * V_476 )
{
V_27 -> V_154 . V_25 . V_476 = V_476 ;
}
void F_286 ( struct V_26 * V_27 ,
struct V_475 * V_477 )
{
V_27 -> V_154 . V_25 . V_477 = V_477 ;
}
void F_287 ( struct V_26 * V_27 ,
struct V_475 * V_478 )
{
V_27 -> V_154 . V_25 . V_478 = V_478 ;
}
void F_288 ( struct V_26 * V_27 ,
struct V_479 * V_480 )
{
V_27 -> V_154 . V_25 . V_480 = V_480 ;
}
void F_289 ( struct V_26 * V_27 ,
struct V_481 * V_482 )
{
int V_11 ;
T_3 * V_483 = V_482 -> V_5 . V_484 ;
int V_485 = V_486 ;
bool V_102 = false ;
if ( V_482 -> V_487 == V_488 ) {
V_483 = V_482 -> V_5 . V_489 ;
V_485 = V_490 ;
}
for ( V_11 = 0 ; V_11 < V_485 ; V_11 ++ ) {
if ( * ( V_483 + V_11 ) ) {
V_102 = true ;
break;
}
}
if ( V_102 )
V_27 -> V_154 . V_25 . V_482 = V_482 ;
else
F_42 ( V_27 -> V_32 -> V_40 , L_129 ) ;
}
void F_290 ( struct V_26 * V_27 ,
struct V_491 * V_492 )
{
V_27 -> V_154 . V_25 . V_492 = V_492 ;
}
void F_291 ( struct V_26 * V_27 ,
struct V_493 * V_281 )
{
V_27 -> V_154 . V_25 . V_494 = V_281 ;
}
void F_292 ( struct V_26 * V_27 ,
struct V_495 * V_496 )
{
V_27 -> V_154 . V_25 . V_496 = V_496 ;
}
void F_293 ( struct V_26 * V_27 ,
struct V_497 * V_498 )
{
V_27 -> V_154 . V_25 . V_498 = V_498 ;
}
void F_294 ( struct V_26 * V_27 ,
struct V_499 * V_500 )
{
if ( ! V_27 -> V_154 . V_25 . V_501 )
V_27 -> V_154 . V_25 . V_501 = & V_27 -> V_154 . V_270 . V_501 ;
memset ( V_27 -> V_154 . V_25 . V_501 ,
0 , sizeof( struct V_502 ) ) ;
V_27 -> V_154 . V_270 . V_501 . V_503 = V_500 -> V_503 ;
V_27 -> V_154 . V_270 . V_501 . V_504 = V_500 -> V_504 ;
}
static int F_295 ( struct V_26 * V_27 ,
struct V_505 * V_506 )
{
struct V_255 * V_507 =
F_116 ( & V_27 -> V_154 . V_257 ) ;
if ( ! V_507 ) {
F_32 ( V_27 -> V_32 -> V_40 , L_130 ) ;
return - V_20 ;
}
if ( sizeof( * V_507 ) != sizeof( * V_506 ) ) {
F_32 ( V_27 -> V_32 -> V_40 , L_131 ) ;
return - V_20 ;
}
if ( ! V_507 -> V_209 ) {
F_32 ( V_27 -> V_32 -> V_40 , L_132 ) ;
return - V_20 ;
}
return memcmp ( V_506 , V_507 , sizeof( * V_507 ) ) ;
}
void F_296 ( struct V_26 * V_27 ,
struct V_508 * V_509 )
{
V_27 -> V_154 . V_25 . V_510 = V_509 ;
}
int F_297 ( struct V_26 * V_27 ,
struct V_511 * V_509 )
{
if ( F_295 ( V_27 , & V_509 -> V_291 ) != 0 )
return - V_427 ;
if ( V_509 -> V_297 . V_298 == NULL ||
V_509 -> V_297 . V_512 == NULL ||
V_509 -> V_297 . V_513 == NULL ||
V_509 -> V_297 . V_514 == NULL ||
V_509 -> V_300 . V_298 == NULL ||
V_509 -> V_300 . V_512 == NULL ||
V_509 -> V_300 . V_513 == NULL ||
V_509 -> V_300 . V_514 == NULL ||
V_27 -> V_154 . V_270 . V_271 -> V_297 . V_298 == NULL ||
V_27 -> V_154 . V_270 . V_271 -> V_297 . V_512 == NULL ||
V_27 -> V_154 . V_270 . V_271 -> V_297 . V_513 == NULL ||
V_27 -> V_154 . V_270 . V_271 -> V_297 . V_514 == NULL ||
V_27 -> V_154 . V_270 . V_271 -> V_300 . V_298 == NULL ||
V_27 -> V_154 . V_270 . V_271 -> V_300 . V_512 == NULL ||
V_27 -> V_154 . V_270 . V_271 -> V_300 . V_513 == NULL ||
V_27 -> V_154 . V_270 . V_271 -> V_300 . V_514 == NULL )
return - V_20 ;
if ( F_298 ( V_27 -> V_154 . V_270 . V_271 -> V_297 . V_298 ,
V_509 -> V_297 . V_298 , V_27 -> V_154 . V_275 ) )
return - V_515 ;
if ( F_298 ( V_27 -> V_154 . V_270 . V_271 -> V_297 . V_512 ,
V_509 -> V_297 . V_512 , V_27 -> V_154 . V_275 ) )
return - V_515 ;
if ( F_298 ( V_27 -> V_154 . V_270 . V_271 -> V_297 . V_513 ,
V_509 -> V_297 . V_513 , V_27 -> V_154 . V_275 ) )
return - V_515 ;
if ( F_298 ( V_27 -> V_154 . V_270 . V_271 -> V_297 . V_514 ,
V_509 -> V_297 . V_514 , V_27 -> V_154 . V_275 ) )
return - V_515 ;
if ( F_298 ( V_27 -> V_154 . V_270 . V_271 -> V_300 . V_298 ,
V_509 -> V_300 . V_298 , V_27 -> V_154 . V_276 ) )
return - V_515 ;
if ( F_298 ( V_27 -> V_154 . V_270 . V_271 -> V_300 . V_512 ,
V_509 -> V_300 . V_512 , V_27 -> V_154 . V_276 ) )
return - V_515 ;
if ( F_298 ( V_27 -> V_154 . V_270 . V_271 -> V_300 . V_513 ,
V_509 -> V_300 . V_513 , V_27 -> V_154 . V_276 ) )
return - V_515 ;
if ( F_298 ( V_27 -> V_154 . V_270 . V_271 -> V_300 . V_514 ,
V_509 -> V_300 . V_514 , V_27 -> V_154 . V_276 ) )
return - V_515 ;
V_27 -> V_154 . V_270 . V_516 . V_510 =
(struct V_517 * )
V_27 -> V_154 . V_270 . V_271 ;
V_27 -> V_154 . V_203 = true ;
return 0 ;
}
void F_299 ( struct V_26 * V_27 ,
unsigned int V_518 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
if ( V_518 == V_27 -> V_154 . V_270 . V_438 . V_519 &&
V_518 == V_27 -> V_154 . V_270 . V_438 . V_520 ) {
F_35 ( V_32 -> V_40 , L_133 ) ;
return;
}
memset ( & V_27 -> V_154 . V_270 . V_438 , 0 ,
sizeof( struct V_521 ) ) ;
V_27 -> V_154 . V_270 . V_438 . V_519 = V_518 ;
V_27 -> V_154 . V_270 . V_438 . V_520 = V_518 ;
V_27 -> V_154 . V_270 . V_516 . V_438 =
(struct V_522 * ) & V_27 -> V_154 . V_270 . V_438 ;
V_27 -> V_154 . V_203 = true ;
}
void F_300 ( struct V_26 * V_27 ,
struct V_523 * V_524 )
{
V_27 -> V_154 . V_25 . V_524 = V_524 ;
}
int F_301 ( struct V_26 * V_27 ,
struct V_525 * V_25 )
{
struct V_429 V_430 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_430 , 0 , sizeof( struct V_429 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_430 = & V_430 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_430 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_303 ( struct V_26 * V_27 ,
struct V_528 * V_25 )
{
struct V_431 V_432 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_432 , 0 , sizeof( struct V_431 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_432 = & V_432 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_432 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_304 ( struct V_26 * V_27 ,
struct V_529 * V_25 )
{
struct V_433 V_434 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_434 , 0 , sizeof( struct V_433 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_434 = & V_434 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_434 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_305 ( struct V_26 * V_27 ,
struct V_530 * V_25 )
{
struct V_435 V_436 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_436 , 0 , sizeof( struct V_435 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_436 = & V_436 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_436 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_306 ( struct V_26 * V_27 ,
struct V_531 * V_25 )
{
struct V_441 V_442 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_442 , 0 , sizeof( struct V_441 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_442 = & V_442 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_442 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_307 ( struct V_26 * V_27 ,
struct V_532 * V_25 )
{
struct V_443 V_444 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_444 , 0 , sizeof( struct V_443 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_444 = & V_444 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_444 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_308 ( struct V_26 * V_27 ,
struct V_533 * V_25 )
{
struct V_445 V_446 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_446 , 0 , sizeof( struct V_445 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_446 = & V_446 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_446 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_309 ( struct V_26 * V_27 ,
struct V_534 * V_25 )
{
struct V_481 * V_535 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
V_535 = F_310 ( sizeof( struct V_481 ) ) ;
if ( ! V_535 )
return - V_294 ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_482 = V_535 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , V_535 , sizeof( * V_535 ) ) ;
F_311 ( V_535 ) ;
return 0 ;
}
int F_312 ( struct V_26 * V_27 ,
struct V_536 * V_25 )
{
struct V_479 * V_535 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
V_535 = F_310 ( sizeof( struct V_479 ) ) ;
if ( ! V_535 )
return - V_294 ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_480 = V_535 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , V_535 , sizeof( * V_535 ) ) ;
F_311 ( V_535 ) ;
return 0 ;
}
int F_313 ( struct V_26 * V_27 ,
struct V_537 * V_25 )
{
struct V_495 V_496 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_496 , 0 , sizeof( struct V_495 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_496 = & V_496 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_496 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_314 ( struct V_26 * V_27 ,
struct V_538 * V_25 )
{
struct V_497 V_498 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_498 , 0 , sizeof( struct V_497 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_498 = & V_498 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_498 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_315 ( struct V_26 * V_27 ,
struct V_539 * V_25 )
{
struct V_523 V_524 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_524 , 0 , sizeof( V_524 ) ) ;
memset ( & V_527 , 0 , sizeof( V_527 ) ) ;
V_527 . V_524 = & V_524 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
memcpy ( V_25 , & V_524 , sizeof( * V_25 ) ) ;
return 0 ;
}
int F_316 ( struct V_26 * V_27 ,
unsigned int * V_518 )
{
struct V_521 V_438 ;
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 , L_134 ,
V_205 ) ;
return - V_20 ;
}
memset ( & V_438 , 0 , sizeof( struct V_521 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_438 = & V_438 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
* V_518 = V_438 . V_519 ;
return 0 ;
}
int F_317 ( struct V_26 * V_27 ,
struct V_540 * V_541 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_233 * V_234 ;
unsigned long V_6 ;
if ( V_27 -> V_154 . V_272 -> V_303 . V_298 == NULL ||
V_27 -> V_154 . V_272 -> V_303 . V_512 == NULL ||
V_27 -> V_154 . V_272 -> V_303 . V_513 == NULL ||
V_27 -> V_154 . V_272 -> V_303 . V_514 == NULL ||
V_27 -> V_154 . V_272 -> V_304 . V_298 == NULL ||
V_27 -> V_154 . V_272 -> V_304 . V_512 == NULL ||
V_27 -> V_154 . V_272 -> V_304 . V_513 == NULL ||
V_27 -> V_154 . V_272 -> V_304 . V_514 == NULL )
return - V_20 ;
F_9 ( & V_32 -> V_542 , V_6 ) ;
if ( V_27 -> V_239 != V_240 ) {
F_11 ( & V_32 -> V_542 , V_6 ) ;
return - V_20 ;
}
F_11 ( & V_32 -> V_542 , V_6 ) ;
if ( F_295 ( V_27 , & V_541 -> V_543 . V_291 ) != 0 )
return - V_427 ;
F_9 ( & V_27 -> V_355 , V_6 ) ;
if ( ! V_27 -> V_154 . V_277 || F_204 ( & V_27 -> V_357 ) ) {
F_11 ( & V_27 -> V_355 , V_6 ) ;
F_32 ( V_32 -> V_40 , L_135 ) ;
return - V_427 ;
}
V_234 = F_205 ( V_27 -> V_357 . V_352 ,
struct V_233 , V_278 ) ;
F_318 ( & V_234 -> V_278 ) ;
F_11 ( & V_27 -> V_355 , V_6 ) ;
if ( V_234 -> V_263 )
F_153 (
V_27 -> V_154 . V_272 , V_234 -> V_263 ) ;
else
F_154 ( V_27 -> V_154 . V_272 ,
V_234 -> V_237 ) ;
V_541 -> V_424 = V_234 -> V_237 -> V_424 ;
F_9 ( & V_27 -> V_355 , V_6 ) ;
F_206 ( & V_234 -> V_278 , & V_27 -> V_357 ) ;
F_11 ( & V_27 -> V_355 , V_6 ) ;
if ( F_319 ( V_541 -> V_543 . V_304 . V_298 ,
V_27 -> V_154 . V_272 -> V_304 . V_298 ,
V_27 -> V_154 . V_274 ) )
return - V_515 ;
if ( F_319 ( V_541 -> V_543 . V_304 . V_512 ,
V_27 -> V_154 . V_272 -> V_304 . V_512 ,
V_27 -> V_154 . V_274 ) )
return - V_515 ;
if ( F_319 ( V_541 -> V_543 . V_304 . V_513 ,
V_27 -> V_154 . V_272 -> V_304 . V_513 ,
V_27 -> V_154 . V_274 ) )
return - V_515 ;
if ( F_319 ( V_541 -> V_543 . V_304 . V_514 ,
V_27 -> V_154 . V_272 -> V_304 . V_514 ,
V_27 -> V_154 . V_274 ) )
return - V_515 ;
if ( F_319 ( V_541 -> V_543 . V_303 . V_298 ,
V_27 -> V_154 . V_272 -> V_303 . V_298 ,
V_27 -> V_154 . V_273 ) )
return - V_515 ;
if ( F_319 ( V_541 -> V_543 . V_303 . V_512 ,
V_27 -> V_154 . V_272 -> V_303 . V_512 ,
V_27 -> V_154 . V_273 ) )
return - V_515 ;
if ( F_319 ( V_541 -> V_543 . V_303 . V_513 ,
V_27 -> V_154 . V_272 -> V_303 . V_513 ,
V_27 -> V_154 . V_273 ) )
return - V_515 ;
if ( F_319 ( V_541 -> V_543 . V_303 . V_514 ,
V_27 -> V_154 . V_272 -> V_303 . V_514 ,
V_27 -> V_154 . V_273 ) )
return - V_515 ;
return 0 ;
}
struct V_544 * F_320 (
unsigned int V_44 , unsigned int V_45 )
{
return F_321 ( V_44 , V_45 ) ;
}
void F_322 ( struct V_26 * V_27 ,
struct V_544 * V_545 )
{
V_27 -> V_154 . V_25 . V_546 = V_545 ;
}
void F_323 ( struct V_544 * V_545 )
{
F_324 ( V_545 ) ;
}
struct V_547 * F_325 (
unsigned int V_44 , unsigned int V_45 )
{
return F_326 ( V_44 , V_45 ) ;
}
void F_327 ( struct V_26 * V_27 ,
struct V_547 * V_545 )
{
V_27 -> V_154 . V_25 . V_548 = V_545 ;
}
void F_328 ( struct V_26 * V_27 ,
struct V_547 * V_545 )
{
struct V_526 V_527 ;
struct V_31 * V_32 = V_27 -> V_32 ;
if ( ! V_27 -> V_29 [ V_246 ] . V_124 ) {
F_32 ( V_32 -> V_40 ,
L_134 , V_205 ) ;
return;
}
memset ( V_545 , 0 , sizeof( struct V_547 ) ) ;
memset ( & V_527 , 0 , sizeof( struct V_526 ) ) ;
V_527 . V_548 = V_545 ;
F_302 (
V_27 -> V_29 [ V_246 ] . V_124 ,
& V_527 ) ;
}
void F_329 ( struct V_547 * V_545 )
{
F_330 ( V_545 ) ;
}
void F_331 ( struct V_31 * V_32 ,
unsigned int V_549 )
{
F_35 ( V_32 -> V_40 , L_136 ) ;
return;
}
void F_332 ( struct V_26 * V_27 )
{
F_333 ( & V_27 -> V_550 . V_551 ) ;
}
int F_334 ( struct V_26 * V_27 )
{
int V_8 = 0 ;
struct V_31 * V_32 = V_27 -> V_32 ;
F_335 ( & V_32 -> V_552 ) ;
if ( F_336 ( & V_27 -> V_550 . V_551 ,
V_553 ) == 0 ) {
F_32 ( V_32 -> V_40 , L_137 , V_205 ) ;
F_1 () ;
F_3 ( V_205 ) ;
V_8 = - V_178 ;
}
F_337 ( & V_32 -> V_552 ) ;
return V_8 ;
}
int F_338 ( struct V_554 * V_555 )
{
unsigned int V_556 ;
for ( V_556 = 0 ; V_556 < V_557 ; V_556 ++ ) {
if ( V_555 -> args [ V_556 ] . V_558 == 0 )
continue;
F_339 ( & V_555 -> V_559 -> V_560 ,
V_561 , V_556 ,
V_555 -> args [ V_556 ] . V_562 ,
V_555 -> args [ V_556 ] . V_558 ) ;
}
return 0 ;
}
int F_340 ( struct V_26 * V_27 ,
struct V_563 * V_559 ,
enum V_217 V_30 ,
unsigned int type )
{
struct V_563 * * V_564 ;
V_559 -> V_352 = NULL ;
V_564 = & ( V_27 -> V_29 [ V_246 ]
. V_38 [ V_30 ] . V_54 ) ;
while ( * V_564 )
V_564 = & ( * V_564 ) -> V_352 ;
* V_564 = V_559 ;
V_27 -> V_29 [ V_246 ]
. V_125 [ V_30 ] = true ;
return 0 ;
}
void F_341 ( struct V_26 * V_27 ,
struct V_563 * V_559 ,
enum V_217 V_30 )
{
struct V_563 * * V_564 ;
V_564 = & ( V_27 -> V_29 [ V_246 ]
. V_38 [ V_30 ] . V_54 ) ;
while ( * V_564 && * V_564 != V_559 )
V_564 = & ( * V_564 ) -> V_352 ;
if ( ! * V_564 ) {
F_32 ( V_27 -> V_32 -> V_40 , L_138 ) ;
return;
}
* V_564 = V_559 -> V_352 ;
V_559 -> V_352 = NULL ;
V_27 -> V_29 [ V_246 ]
. V_125 [ V_30 ] = true ;
}
int F_342 ( struct V_26 * V_27 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_34 * V_565 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
if ( V_29 -> V_566 ) {
if ( V_29 -> V_567 == V_127 ) {
if ( F_38 ( V_29 -> V_566 )
!= V_128 ) {
F_32 ( V_32 -> V_40 , L_139 ) ;
return - V_426 ;
}
}
if ( F_44 ( V_29 -> V_566 )
!= V_128 ) {
F_32 ( V_32 -> V_40 , L_140 ) ;
return - V_426 ;
}
V_29 -> V_566 = NULL ;
}
V_565 = & V_29 -> V_38 [ V_162 ] ;
F_89 ( V_565 ) ;
V_27 -> V_550 . V_55 = F_343 ( V_568 *
sizeof( void * ) , V_306 ) ;
if ( ! V_27 -> V_550 . V_55 )
return - V_294 ;
V_565 -> V_55 = V_27 -> V_550 . V_55 ;
V_565 -> V_41 = V_161 ;
V_565 -> V_56 = 0 ;
return 0 ;
}
int F_344 ( struct V_26 * V_27 )
{
struct V_31 * V_32 = V_27 -> V_32 ;
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
struct V_34 * V_565 =
& V_29 -> V_38 [ V_160 ] ;
if ( F_60 ( V_565 ,
& V_29 -> V_33 [ V_160 ] ) != V_128 ) {
F_32 ( V_32 -> V_40 , L_141 ,
V_205 ) ;
return - V_569 ;
}
memset ( & V_29 -> V_570 , 0 ,
sizeof( struct V_67 ) ) ;
if ( F_47 ( & V_29 -> V_570 , 1 ,
& V_29 -> V_33 [ V_160 ] ,
& V_29 -> V_566 ) != V_128 ) {
F_32 ( V_32 -> V_40 , L_142 , V_205 ) ;
return - V_20 ;
}
V_29 -> V_567 = V_143 ;
F_345 ( & V_27 -> V_550 . V_551 ) ;
V_27 -> V_550 . V_571 = V_29 -> V_33 [ V_160 ] ;
F_346 ( V_32 , V_572 , false ) ;
if ( F_105 () != V_128 ) {
F_32 ( V_32 -> V_40 , L_96 ) ;
return - V_178 ;
}
if ( F_106 ( V_29 -> V_566 )
!= V_128 ) {
F_32 ( V_32 -> V_40 , L_143 ) ;
return - V_178 ;
}
V_29 -> V_567 = V_127 ;
return 0 ;
}
int F_347 ( struct V_26 * V_27 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
if ( V_29 -> V_567 == V_127 ) {
F_38 ( V_29 -> V_566 ) ;
V_29 -> V_567 = V_130 ;
}
return 0 ;
}
void F_348 ( struct V_26 * V_27 )
{
struct V_28 * V_29 =
& V_27 -> V_29 [ V_246 ] ;
if ( V_29 -> V_566 ) {
if ( F_44 ( V_29 -> V_566 )
!= V_128 )
F_42 ( V_27 -> V_32 -> V_40 ,
L_140 ) ;
V_29 -> V_566 = NULL ;
}
if ( V_29 -> V_33 [ V_160 ] ) {
if ( F_51 ( V_29 -> V_33 [ V_160 ] )
!= V_128 )
F_42 ( V_27 -> V_32 -> V_40 ,
L_144 ) ;
V_29 -> V_33 [ V_160 ] = NULL ;
V_29 -> V_125 [ V_160 ] = false ;
F_89 (
& V_29 -> V_38 [ V_160 ] ) ;
F_59 (
& V_29 -> V_39 [ V_160 ] ) ;
}
V_27 -> V_550 . V_571 = NULL ;
F_107 () ;
F_137 ( V_27 -> V_550 . V_55 ) ;
V_27 -> V_550 . V_55 = NULL ;
F_346 ( V_27 -> V_32 , V_573 , false ) ;
}
int F_349 ( struct V_26 * V_27 ,
struct V_563 * V_559 ,
unsigned int V_574 )
{
struct V_34 * V_565 =
& V_27 -> V_29 [ V_246 ]
. V_38 [ V_160 ] ;
if ( V_574 >= V_568 ) {
F_35 ( V_27 -> V_32 -> V_40 , L_145 ,
V_205 , V_574 ) ;
return - V_294 ;
}
V_565 -> V_55 [ V_574 ] = V_559 ;
V_565 -> V_56 = V_574 + 1 ;
V_565 -> V_57 = 1 ;
return 0 ;
}
static struct V_26 * F_350 (
struct V_135 * V_575 ,
struct V_31 * V_32 ,
enum V_213 * V_214 ) {
int V_11 , V_69 , V_576 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
for ( V_11 = 0 ; V_11 < V_32 -> V_202 ; V_11 ++ ) {
V_27 = & V_32 -> V_27 [ V_11 ] ;
if ( V_27 -> V_239 == V_577 &&
! V_27 -> V_550 . V_571 )
continue;
for ( V_69 = 0 ; V_69 < V_132 ; V_69 ++ ) {
V_29 = & V_27 -> V_29 [ V_69 ] ;
for ( V_576 = 0 ; V_576 < V_71 ; V_576 ++ ) {
if ( V_29 -> V_33 [ V_576 ] &&
V_29 -> V_33 [ V_576 ] == V_575 ) {
* V_214 = V_69 ;
return V_27 ;
}
}
}
}
return NULL ;
}
int F_351 ( struct V_31 * V_32 ,
bool * V_578 ,
bool * V_579 )
{
enum V_213 V_214 = 0 ;
struct V_308 V_309 ;
struct V_26 * V_27 = & V_32 -> V_27 [ 0 ] ;
#ifndef F_55
bool V_580 [ V_581 ] = { false } ;
#endif
int V_11 ;
while ( ! F_155 ( & V_309 ) ) {
if ( V_309 . V_310 . type ==
V_582 ) {
F_32 ( V_32 -> V_40 , L_146 ,
V_205 ,
V_309 . V_310 . V_583 ,
V_309 . V_310 . V_584 ) ;
for ( V_11 = 0 ; V_11 < V_32 -> V_202 ; V_11 ++ )
F_352 ( & V_32 -> V_27 [ V_11 ] , 0 ) ;
#ifndef F_55
F_353 ( ( unsigned long ) V_32 ) ;
#else
F_354 ( V_32 -> V_585 , & V_32 -> V_586 ) ;
#endif
return - V_20 ;
} else if ( V_309 . V_310 . type == V_587 ) {
F_42 ( V_32 -> V_40 , L_147 ,
V_205 , V_309 . V_310 . V_588 ,
V_309 . V_310 . V_424 ) ;
continue;
}
V_27 = F_350 ( V_309 . V_310 . V_247 ,
V_32 , & V_214 ) ;
if ( ! V_27 ) {
if ( V_309 . V_310 . type == V_589 )
F_35 ( V_32 -> V_40 ,
L_148 ) ;
else
F_42 ( V_32 -> V_40 , L_149 ,
V_205 ,
V_309 . V_310 . type ) ;
continue;
}
F_157 ( V_27 , & V_309 ) ;
switch ( V_309 . V_310 . type ) {
case V_590 :
V_578 [ V_27 -> V_574 ] = true ;
F_355 ( V_27 , 0 , V_591 ,
V_309 . V_247 , true , V_214 ) ;
#ifndef F_55
V_580 [ V_27 -> V_574 ] = true ;
#endif
break;
case V_592 :
V_578 [ V_27 -> V_574 ] = true ;
F_355 ( V_27 , 0 , V_593 ,
V_309 . V_247 , true , V_214 ) ;
#ifndef F_55
V_580 [ V_27 -> V_574 ] = true ;
#endif
break;
case V_594 :
F_355 ( V_27 , 0 ,
V_595 ,
V_309 . V_247 ,
false , V_214 ) ;
break;
case V_596 :
F_355 ( V_27 , 0 ,
V_597 ,
V_309 . V_247 ,
false , V_214 ) ;
break;
case V_598 :
F_355 ( V_27 , 0 ,
V_599 ,
V_309 . V_247 , true , V_214 ) ;
#ifndef F_55
V_580 [ V_27 -> V_574 ] = true ;
#endif
break;
case V_600 :
F_355 ( V_27 , 0 ,
V_601 ,
V_309 . V_247 , true , V_214 ) ;
#ifndef F_55
V_580 [ V_27 -> V_574 ] = true ;
#endif
break;
case V_602 :
F_355 ( V_27 , 0 ,
V_603 ,
V_309 . V_247 ,
false , V_214 ) ;
break;
case V_604 :
V_579 [ V_27 -> V_574 ] = true ;
break;
case V_605 :
F_356 ( V_27 , V_309 . V_310 . V_606 ) ;
break;
default:
F_35 ( V_32 -> V_40 , L_150 ,
V_309 . V_310 . type ) ;
break;
}
}
#ifndef F_55
for ( V_11 = 0 ; V_11 < V_32 -> V_202 ; V_11 ++ ) {
V_27 = & V_32 -> V_27 [ V_11 ] ;
if ( ! V_27 )
continue;
if ( V_27 -> V_239 != V_240 )
continue;
if ( ! F_357 ( V_27 ) )
F_352 ( V_27 , false ) ;
else if ( V_580 [ V_11 ] )
F_358 ( V_27 ,
V_607 ) ;
}
#endif
return 0 ;
}
bool F_359 ( struct V_31 * V_32 )
{
unsigned int V_11 , V_69 ;
for ( V_11 = 0 ; V_11 < V_32 -> V_202 ; V_11 ++ ) {
struct V_26 * V_27 = & V_32 -> V_27 [ V_11 ] ;
for ( V_69 = 0 ; V_69 < V_132 ; V_69 ++ ) {
if ( V_27 -> V_29 [ V_69 ] . V_124 &&
V_27 -> V_29 [ V_69 ] . V_72 . V_41 ==
V_74 )
return false ;
}
}
return true ;
}
int F_360 ( void )
{
F_361 () ;
return 0 ;
}
int F_362 ( bool V_608 )
{
F_363 ( V_608 ) ;
return 0 ;
}
int F_364 ( void )
{
struct V_609 * V_610 = V_611 ;
unsigned V_11 , V_612 = V_613 ;
if ( V_612 == 0 )
return - V_614 ;
if ( V_610 == NULL )
return - V_614 ;
for ( V_11 = 1 ; V_11 < V_613 ; V_11 ++ )
F_35 ( V_19 , L_151 , V_11 ,
V_610 [ V_11 - 1 ] . V_615 . V_208 . V_32 . V_616 . V_85 , V_610 [ V_11 - 1 ] . V_617 ) ;
return 0 ;
}
void F_365 ( struct V_26 * V_27 ,
T_4 V_249 )
{
V_27 -> V_154 . V_25 . V_249 = V_249 ;
}
void F_366 ( struct V_26 * V_27 ,
struct V_343 * V_248 )
{
V_27 -> V_154 . V_25 . V_248 = V_248 ;
}
int F_367 ( void )
{
return V_200 ;
}
int F_368 ( struct V_31 * V_32 , int V_184 )
{
int V_8 ;
V_8 = F_68 ( V_32 , V_184 ) ;
if ( 0 == V_8 )
V_200 = V_184 ;
return V_8 ;
}
void F_369 ( struct V_26 * V_27 , bool V_209 )
{
F_370 (
V_27 -> V_29 [ V_246 ] . V_124 ,
V_209 ) ;
}
struct V_255 * F_116 (
struct V_618 * V_291 )
{
if ( ! V_291 )
return NULL ;
#ifdef F_371
return & V_291 -> V_295 . V_256 ;
#else
return & V_291 -> V_295 ;
#endif
}
