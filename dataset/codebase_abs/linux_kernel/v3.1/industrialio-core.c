int F_1 ( struct V_1 * V_2 ,
int V_3 ,
int V_4 ,
T_1 V_5 )
{
struct V_6 * V_7
= & V_2 -> V_8 [ V_3 ] ;
struct V_9 * V_10 ;
int V_11 = 0 ;
F_2 ( & V_7 -> V_12 ) ;
if ( F_3 ( V_13 , & V_7 -> V_14 . V_15 ) ) {
if ( V_7 -> V_16 == V_7 -> V_17 ) {
F_4 ( & V_7 -> V_12 ) ;
return 0 ;
}
V_10 = F_5 ( sizeof( * V_10 ) , V_18 ) ;
if ( V_10 == NULL ) {
V_11 = - V_19 ;
F_4 ( & V_7 -> V_12 ) ;
goto V_20;
}
V_10 -> V_10 . V_21 = V_4 ;
V_10 -> V_10 . V_5 = V_5 ;
F_6 ( & V_10 -> V_22 , & V_7 -> V_23 ) ;
V_7 -> V_16 ++ ;
F_4 ( & V_7 -> V_12 ) ;
F_7 ( & V_7 -> V_24 ) ;
} else
F_4 ( & V_7 -> V_12 ) ;
V_20:
return V_11 ;
}
T_2 F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
return sprintf ( V_29 , L_1 , F_9 ( V_28 ) -> string ) ;
}
static T_2 F_10 ( struct V_30 * V_31 ,
char T_3 * V_29 ,
T_4 V_32 ,
T_5 * V_33 )
{
struct V_6 * V_7 = V_31 -> V_34 ;
struct V_9 * V_35 ;
int V_11 ;
T_4 V_36 ;
F_2 ( & V_7 -> V_12 ) ;
if ( F_11 ( & V_7 -> V_23 ) ) {
if ( V_31 -> V_37 & V_38 ) {
V_11 = - V_39 ;
goto V_40;
}
F_4 ( & V_7 -> V_12 ) ;
V_11 = F_12 ( V_7 -> V_24 ,
! F_11 ( & V_7
-> V_23 ) ) ;
if ( V_11 )
goto V_20;
F_2 ( & V_7 -> V_12 ) ;
}
V_35 = F_13 ( & V_7 -> V_23 ,
struct V_9 ,
V_22 ) ;
V_36 = sizeof V_35 -> V_10 ;
if ( F_14 ( V_29 , & ( V_35 -> V_10 ) , V_36 ) ) {
V_11 = - V_41 ;
goto V_40;
}
F_15 ( & V_35 -> V_22 ) ;
V_7 -> V_16 -- ;
F_4 ( & V_7 -> V_12 ) ;
F_16 ( V_35 ) ;
return V_36 ;
V_40:
F_4 ( & V_7 -> V_12 ) ;
V_20:
return V_11 ;
}
static int F_17 ( struct V_42 * V_42 , struct V_30 * V_31 )
{
struct V_43 * V_44 = F_18 ( V_42 -> V_45 ) ;
struct V_6 * V_7 = V_44 -> V_46 ;
struct V_9 * V_35 , * V_47 ;
F_2 ( & V_7 -> V_12 ) ;
F_19 ( V_13 , & V_7 -> V_14 . V_15 ) ;
F_20 (el, t, &ev_int->det_events, list) {
F_15 ( & V_35 -> V_22 ) ;
F_16 ( V_35 ) ;
}
F_4 ( & V_7 -> V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_42 * V_42 , struct V_30 * V_31 )
{
struct V_43 * V_44 = F_18 ( V_42 -> V_45 ) ;
struct V_6 * V_7 = V_44 -> V_46 ;
F_2 ( & V_7 -> V_12 ) ;
if ( F_22 ( V_13 , & V_44 -> V_15 ) ) {
F_23 ( V_31 -> V_48 ) ;
F_4 ( & V_7 -> V_12 ) ;
return - V_49 ;
}
V_31 -> V_34 = V_44 -> V_46 ;
F_4 ( & V_7 -> V_12 ) ;
return 0 ;
}
static void F_24 ( struct V_25 * V_26 )
{
struct V_6 * V_7
= F_25 ( V_26 , struct V_6 , V_26 ) ;
F_26 ( & V_7 -> V_14 . V_50 ) ;
F_27 ( F_28 ( V_26 -> V_51 ) ) ;
}
int F_29 ( void )
{
int V_11 , V_52 ;
V_53:
if ( F_30 ( F_31 ( & V_54 , V_18 ) == 0 ) )
return - V_19 ;
F_32 ( & V_55 ) ;
V_11 = F_33 ( & V_54 , & V_52 ) ;
F_34 ( & V_55 ) ;
if ( F_30 ( V_11 == - V_39 ) )
goto V_53;
else if ( F_30 ( V_11 ) )
return V_11 ;
if ( V_52 > V_56 )
return - V_19 ;
return V_52 ;
}
void F_27 ( int V_52 )
{
F_32 ( & V_55 ) ;
F_35 ( & V_54 , V_52 ) ;
F_34 ( & V_55 ) ;
}
static int F_36 ( struct V_6 * V_7 ,
const char * V_57 ,
int V_58 ,
struct V_59 * V_60 ,
struct V_25 * V_26 )
{
int V_11 , V_61 ;
V_7 -> V_26 . V_62 = & V_63 ;
V_7 -> V_26 . V_64 = V_26 ;
V_7 -> V_26 . type = & V_65 ;
F_37 ( & V_7 -> V_26 ) ;
V_61 = F_29 () ;
if ( V_61 < 0 ) {
V_11 = V_61 ;
goto V_66;
}
V_7 -> V_26 . V_51 = F_38 ( F_39 ( V_67 ) , V_61 ) ;
F_40 ( & V_7 -> V_26 , L_2 , V_57 , V_58 ) ;
V_11 = F_41 ( & V_7 -> V_26 ) ;
if ( V_11 )
goto V_68;
F_42 ( & V_7 -> V_14 . V_50 , & V_69 ) ;
V_7 -> V_14 . V_50 . V_60 = V_60 ;
F_43 ( & V_7 -> V_12 ) ;
V_7 -> V_17 = 10 ;
V_7 -> V_16 = 0 ;
F_44 ( & V_7 -> V_23 ) ;
F_45 ( & V_7 -> V_24 ) ;
V_7 -> V_14 . V_46 = V_7 ;
V_7 -> V_14 . V_15 = 0 ;
V_11 = F_46 ( & V_7 -> V_14 . V_50 , V_7 -> V_26 . V_51 , 1 ) ;
if ( V_11 )
goto V_70;
return 0 ;
V_70:
F_47 ( & V_7 -> V_26 ) ;
V_68:
F_27 ( V_61 ) ;
V_66:
F_48 ( & V_7 -> V_26 ) ;
return V_11 ;
}
static void F_49 ( struct V_6 * V_7 )
{
F_47 ( & V_7 -> V_26 ) ;
F_48 ( & V_7 -> V_26 ) ;
}
static int T_6 F_50 ( void )
{
int V_71 ;
V_71 = F_51 ( & V_67 , 0 , V_56 , L_3 ) ;
if ( V_71 < 0 )
F_52 ( V_72 L_4 ,
__FILE__ ) ;
return V_71 ;
}
static void T_7 F_53 ( void )
{
if ( V_67 )
F_54 ( V_67 , V_56 ) ;
}
static int T_6 F_55 ( void )
{
int V_11 ;
V_11 = F_56 ( & V_63 ) ;
if ( V_11 < 0 ) {
F_52 ( V_72
L_5 ,
__FILE__ ) ;
goto V_73;
}
V_11 = F_50 () ;
if ( V_11 < 0 )
goto V_74;
return 0 ;
V_74:
F_57 ( & V_63 ) ;
V_73:
return V_11 ;
}
static void T_7 F_58 ( void )
{
F_53 () ;
F_57 ( & V_63 ) ;
}
static T_2 F_59 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_75 = F_60 ( V_26 ) ;
struct V_76 * V_77 = F_61 ( V_28 ) ;
int V_52 , V_78 ;
int V_11 = V_75 -> V_79 -> V_80 ( V_75 , V_77 -> V_81 ,
& V_52 , & V_78 , V_77 -> V_82 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_11 == V_83 )
return sprintf ( V_29 , L_6 , V_52 ) ;
else if ( V_11 == V_84 ) {
if ( V_78 < 0 )
return sprintf ( V_29 , L_7 , V_52 , - V_78 ) ;
else
return sprintf ( V_29 , L_8 , V_52 , V_78 ) ;
} else if ( V_11 == V_85 ) {
if ( V_78 < 0 )
return sprintf ( V_29 , L_9 , V_52 , - V_78 ) ;
else
return sprintf ( V_29 , L_10 , V_52 , V_78 ) ;
} else
return 0 ;
}
static T_2 F_62 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_4 V_36 )
{
struct V_1 * V_75 = F_60 ( V_26 ) ;
struct V_76 * V_77 = F_61 ( V_28 ) ;
int V_11 , integer = 0 , V_86 = 0 , V_87 = 100000 ;
bool V_88 = true , V_89 = false ;
if ( ! V_75 -> V_79 -> V_90 )
return - V_91 ;
if ( V_75 -> V_79 -> V_92 )
switch ( V_75 -> V_79 -> V_92 ( V_75 ,
V_77 -> V_81 , V_77 -> V_82 ) ) {
case V_84 :
V_87 = 100000 ;
break;
case V_85 :
V_87 = 100000000 ;
break;
default:
return - V_91 ;
}
if ( V_29 [ 0 ] == '-' ) {
V_89 = true ;
V_29 ++ ;
}
while ( * V_29 ) {
if ( '0' <= * V_29 && * V_29 <= '9' ) {
if ( V_88 )
integer = integer * 10 + * V_29 - '0' ;
else {
V_86 += V_87 * ( * V_29 - '0' ) ;
if ( V_87 == 1 )
break;
V_87 /= 10 ;
}
} else if ( * V_29 == '\n' ) {
if ( * ( V_29 + 1 ) == '\0' )
break;
else
return - V_91 ;
} else if ( * V_29 == '.' ) {
V_88 = false ;
} else {
return - V_91 ;
}
V_29 ++ ;
}
if ( V_89 ) {
if ( integer )
integer = - integer ;
else
V_86 = - V_86 ;
}
V_11 = V_75 -> V_79 -> V_90 ( V_75 , V_77 -> V_81 ,
integer , V_86 , V_77 -> V_82 ) ;
if ( V_11 )
return V_11 ;
return V_36 ;
}
static int F_63 ( struct V_93 const * V_94 ,
bool V_95 ,
const char * V_96 ,
char * * V_97 )
{
char * V_98 ;
if ( V_95 || ( ! V_94 -> V_99 && ! V_94 -> V_100 ) ) {
V_98 = F_64 ( V_18 , L_11 , V_96 ) ;
} else if ( V_94 -> V_99 ) {
const char * V_101 ;
switch ( V_94 -> type ) {
case V_102 :
V_101
= V_103 [ V_94 -> V_104 ] ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_101
= V_111 [ V_94 -> V_104 ] ;
break;
default:
return - V_91 ;
}
if ( V_94 -> V_100 )
V_98 = F_64 ( V_18 , L_12 ,
V_101 ,
V_94 -> V_100 ,
V_96 ) ;
else
V_98 = F_64 ( V_18 , L_13 ,
V_101 ,
V_96 ) ;
} else
V_98 = F_64 ( V_18 , L_13 , V_94 -> V_100 ,
V_96 ) ;
if ( V_98 == NULL )
return - V_19 ;
* V_97 = V_98 ;
return 0 ;
}
int F_65 ( struct V_27 * V_112 ,
const char * V_96 ,
struct V_93 const * V_94 ,
T_2 (* F_66)( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 ) ,
T_2 (* F_67)( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_4 V_36 ) ,
bool V_95 )
{
int V_11 ;
char * V_113 , * V_114 ;
F_68 ( & V_112 -> V_28 ) ;
V_11 = F_63 ( V_94 , V_95 , V_96 , & V_114 ) ;
if ( V_11 )
goto V_20;
if ( V_94 -> type == V_115 && ! V_95 )
V_113
= F_64 ( V_18 , L_13 ,
V_116 [ V_94 -> type ] ,
V_114 ) ;
else if ( V_95 || ! V_94 -> V_117 )
V_113
= F_64 ( V_18 , L_13 ,
V_118 [ V_94 -> type ] ,
V_114 ) ;
else
V_113
= F_64 ( V_18 , L_14 ,
V_118 [ V_94 -> type ] ,
V_94 -> V_119 ,
V_114 ) ;
if ( V_113 == NULL ) {
V_11 = - V_19 ;
goto V_120;
}
V_112 -> V_28 . V_121 = F_64 ( V_18 ,
V_113 ,
V_94 -> V_119 ,
V_94 -> V_104 ) ;
if ( V_112 -> V_28 . V_121 == NULL ) {
V_11 = - V_19 ;
goto V_122;
}
if ( F_66 ) {
V_112 -> V_28 . V_123 |= V_124 ;
V_112 -> V_125 = F_66 ;
}
if ( F_67 ) {
V_112 -> V_28 . V_123 |= V_126 ;
V_112 -> V_127 = F_67 ;
}
F_16 ( V_113 ) ;
F_16 ( V_114 ) ;
return 0 ;
V_122:
F_16 ( V_113 ) ;
V_120:
F_16 ( V_114 ) ;
V_20:
return V_11 ;
}
void F_69 ( struct V_27 * V_112 )
{
F_16 ( V_112 -> V_28 . V_121 ) ;
}
int F_70 ( const char * V_96 ,
const char * V_128 ,
struct V_93 const * V_94 ,
T_2 (* F_66)( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 ) ,
T_2 (* F_67)( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_4 V_36 ) ,
int V_129 ,
bool V_95 ,
struct V_25 * V_26 ,
struct V_130 * V_131 )
{
int V_11 ;
struct V_76 * V_132 , * V_47 ;
V_132 = F_71 ( sizeof *V_132 , V_18 ) ;
if ( V_132 == NULL ) {
V_11 = - V_19 ;
goto V_20;
}
V_11 = F_65 ( & V_132 -> V_112 ,
V_96 , V_94 ,
F_66 , F_67 , V_95 ) ;
if ( V_11 )
goto V_133;
V_132 -> V_81 = V_94 ;
V_132 -> V_82 = V_129 ;
F_72 (t, attr_list, l)
if ( strcmp ( V_47 -> V_112 . V_28 . V_121 ,
V_132 -> V_112 . V_28 . V_121 ) == 0 ) {
if ( ! V_95 )
F_73 ( V_26 , L_15 ,
V_47 -> V_112 . V_28 . V_121 ) ;
V_11 = - V_49 ;
goto V_134;
}
V_11 = F_74 ( & V_26 -> V_135 ,
& V_132 -> V_112 . V_28 , V_128 ) ;
if ( V_11 < 0 )
goto V_134;
F_75 ( & V_132 -> V_136 , V_131 ) ;
return 0 ;
V_134:
F_69 ( & V_132 -> V_112 ) ;
V_133:
F_16 ( V_132 ) ;
V_20:
return V_11 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_93 const * V_94 )
{
int V_11 , V_137 ;
if ( V_94 -> V_119 < 0 )
return 0 ;
if ( V_94 -> V_138 )
V_11 = F_70 ( L_16 , NULL , V_94 ,
& F_59 ,
NULL ,
0 ,
0 ,
& V_2 -> V_26 ,
& V_2 -> V_139 ) ;
else
V_11 = F_70 ( L_17 , NULL , V_94 ,
& F_59 ,
( V_94 -> type == V_140 ?
& F_62 : NULL ) ,
0 ,
0 ,
& V_2 -> V_26 ,
& V_2 -> V_139 ) ;
if ( V_11 )
goto V_20;
F_77 (i, &chan->info_mask, sizeof(long)*8 ) {
V_11 = F_70 ( V_141 [ V_137 / 2 ] ,
NULL , V_94 ,
& F_59 ,
& F_62 ,
( 1 << V_137 ) ,
! ( V_137 % 2 ) ,
& V_2 -> V_26 ,
& V_2 -> V_139 ) ;
if ( V_11 == - V_49 && ( V_137 % 2 == 0 ) ) {
V_11 = 0 ;
continue;
}
if ( V_11 < 0 )
goto V_20;
}
V_20:
return V_11 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_76 * V_142 )
{
F_79 ( & V_2 -> V_26 . V_135 ,
& V_142 -> V_112 . V_28 , NULL ) ;
F_16 ( V_142 -> V_112 . V_28 . V_121 ) ;
F_16 ( V_142 ) ;
}
static T_2 F_80 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_75 = F_60 ( V_26 ) ;
return sprintf ( V_29 , L_1 , V_75 -> V_121 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
int V_137 , V_11 = 0 ;
struct V_76 * V_142 , * V_143 ;
if ( V_2 -> V_79 -> V_144 ) {
V_11 = F_82 ( & V_2 -> V_26 . V_135 ,
V_2 -> V_79 -> V_144 ) ;
if ( V_11 ) {
F_73 ( V_2 -> V_26 . V_64 ,
L_18 ) ;
goto V_20;
}
}
F_44 ( & V_2 -> V_139 ) ;
if ( V_2 -> V_145 )
for ( V_137 = 0 ; V_137 < V_2 -> V_146 ; V_137 ++ ) {
V_11 = F_76 ( V_2 ,
& V_2
-> V_145 [ V_137 ] ) ;
if ( V_11 < 0 )
goto V_147;
}
if ( V_2 -> V_121 ) {
V_11 = F_74 ( & V_2 -> V_26 . V_135 ,
& V_148 . V_28 ,
NULL ) ;
if ( V_11 )
goto V_147;
}
return 0 ;
V_147:
F_20 (p, n,
&dev_info->channel_attr_list, l) {
F_15 ( & V_142 -> V_136 ) ;
F_78 ( V_2 , V_142 ) ;
}
if ( V_2 -> V_79 -> V_144 )
F_83 ( & V_2 -> V_26 . V_135 , V_2 -> V_79 -> V_144 ) ;
V_20:
return V_11 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_76 * V_142 , * V_143 ;
if ( V_2 -> V_121 )
F_79 ( & V_2 -> V_26 . V_135 ,
& V_148 . V_28 ,
NULL ) ;
F_20 (p, n, &dev_info->channel_attr_list, l) {
F_15 ( & V_142 -> V_136 ) ;
F_78 ( V_2 , V_142 ) ;
}
if ( V_2 -> V_79 -> V_144 )
F_83 ( & V_2 -> V_26 . V_135 , V_2 -> V_79 -> V_144 ) ;
}
int F_85 ( struct V_149 * V_150 )
{
int V_11 ;
int V_52 ;
V_53:
if ( F_30 ( F_31 ( V_150 , V_18 ) == 0 ) )
return - V_19 ;
F_32 ( & V_55 ) ;
V_11 = F_33 ( V_150 , & V_52 ) ;
F_34 ( & V_55 ) ;
if ( F_30 ( V_11 == - V_39 ) )
goto V_53;
else if ( F_30 ( V_11 ) )
return V_11 ;
return V_52 ;
}
void F_86 ( struct V_149 * V_150 , int V_21 )
{
F_32 ( & V_55 ) ;
F_35 ( V_150 , V_21 ) ;
F_34 ( & V_55 ) ;
}
static T_2 F_87 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_4 V_36 )
{
struct V_1 * V_75 = F_60 ( V_26 ) ;
struct V_76 * V_77 = F_61 ( V_28 ) ;
int V_11 ;
bool V_52 ;
V_11 = F_88 ( V_29 , & V_52 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = V_75 -> V_79 -> V_151 ( V_75 ,
V_77 -> V_82 ,
V_52 ) ;
return ( V_11 < 0 ) ? V_11 : V_36 ;
}
static T_2 F_89 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_75 = F_60 ( V_26 ) ;
struct V_76 * V_77 = F_61 ( V_28 ) ;
int V_52 = V_75 -> V_79 -> V_152 ( V_75 ,
V_77 -> V_82 ) ;
if ( V_52 < 0 )
return V_52 ;
else
return sprintf ( V_29 , L_6 , V_52 ) ;
}
static T_2 F_90 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_29 )
{
struct V_1 * V_75 = F_60 ( V_26 ) ;
struct V_76 * V_77 = F_61 ( V_28 ) ;
int V_52 , V_11 ;
V_11 = V_75 -> V_79 -> V_153 ( V_75 ,
V_77 -> V_82 , & V_52 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_29 , L_6 , V_52 ) ;
}
static T_2 F_91 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_29 ,
T_4 V_36 )
{
struct V_1 * V_75 = F_60 ( V_26 ) ;
struct V_76 * V_77 = F_61 ( V_28 ) ;
unsigned long V_52 ;
int V_11 ;
V_11 = F_92 ( V_29 , 10 , & V_52 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_75 -> V_79 -> V_154 ( V_75 , V_77 -> V_82 ,
V_52 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_36 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_93 const * V_94 )
{
int V_11 = 0 , V_137 , V_129 ;
char * V_96 ;
if ( ! V_94 -> V_155 )
return 0 ;
F_77 (i, &chan->event_mask, sizeof(chan->event_mask)*8 ) {
V_96 = F_64 ( V_18 , L_19 ,
V_156 [ V_137 / V_157 ] ,
V_158 [ V_137 % V_157 ] ) ;
if ( V_96 == NULL ) {
V_11 = - V_19 ;
goto V_20;
}
switch ( V_94 -> type ) {
case V_159 :
V_129 = F_94 ( V_94 -> type , V_94 -> V_119 ,
V_137 / V_157 ,
V_137 % V_157 ) ;
break;
case V_105 :
V_129 = F_95 ( V_94 -> type , 0 , V_94 -> V_119 ,
V_137 / V_157 ,
V_137 % V_157 ) ;
break;
case V_115 :
V_129 = F_95 ( V_94 -> type , V_94 -> V_119 ,
V_94 -> V_104 ,
V_137 / V_157 ,
V_137 % V_157 ) ;
break;
default:
F_52 ( V_160 L_20 ) ;
}
V_11 = F_70 ( V_96 ,
NULL ,
V_94 ,
& F_89 ,
F_87 ,
V_129 ,
0 ,
& V_2 -> V_8 [ 0 ] . V_26 ,
& V_2 -> V_8 [ 0 ] .
V_161 ) ;
F_16 ( V_96 ) ;
if ( V_11 )
goto V_20;
V_96 = F_64 ( V_18 , L_21 ,
V_156 [ V_137 / V_157 ] ,
V_158 [ V_137 % V_157 ] ) ;
if ( V_96 == NULL ) {
V_11 = - V_19 ;
goto V_20;
}
V_11 = F_70 ( V_96 , NULL , V_94 ,
F_90 ,
F_91 ,
V_129 ,
0 ,
& V_2 -> V_8 [ 0 ]
. V_26 ,
& V_2 -> V_8 [ 0 ]
. V_161 ) ;
F_16 ( V_96 ) ;
if ( V_11 )
goto V_20;
}
V_20:
return V_11 ;
}
static inline void F_96 ( struct V_1 * V_2 ,
const char * V_162 ,
int V_163 )
{
struct V_76 * V_142 , * V_143 ;
F_20 (p, n,
&dev_info->event_interfaces[num].
dev_attr_list, l) {
F_79 ( & V_2
-> V_8 [ V_163 ] . V_26 . V_135 ,
& V_142 -> V_112 . V_28 ,
V_162 ) ;
F_16 ( V_142 -> V_112 . V_28 . V_121 ) ;
F_16 ( V_142 ) ;
}
}
static inline int F_97 ( struct V_1 * V_2 , int V_137 )
{
int V_164 ;
int V_11 ;
F_44 ( & V_2 -> V_8 [ 0 ] . V_161 ) ;
if ( V_2 -> V_145 ) {
for ( V_164 = 0 ; V_164 < V_2 -> V_146 ; V_164 ++ ) {
V_11 = F_93 ( V_2 ,
& V_2
-> V_145 [ V_164 ] ) ;
if ( V_11 )
goto V_147;
}
}
return 0 ;
V_147:
F_96 ( V_2 , NULL , V_137 ) ;
return V_11 ;
}
static inline int F_98 ( struct V_1 * V_2 ,
int V_137 )
{
F_96 ( V_2 , NULL , V_137 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_11 = 0 , V_137 , V_164 ;
if ( V_2 -> V_79 -> V_165 == 0 )
return 0 ;
V_2 -> V_8 =
F_71 ( sizeof( struct V_6 )
* V_2 -> V_79 -> V_165 ,
V_18 ) ;
if ( V_2 -> V_8 == NULL ) {
V_11 = - V_19 ;
goto V_20;
}
for ( V_137 = 0 ; V_137 < V_2 -> V_79 -> V_165 ; V_137 ++ ) {
V_11 = F_36 ( & V_2 -> V_8 [ V_137 ] ,
V_57 ( & V_2 -> V_26 ) ,
V_137 ,
V_2 -> V_79 -> V_166 ,
& V_2 -> V_26 ) ;
if ( V_11 ) {
F_73 ( & V_2 -> V_26 ,
L_22 ) ;
goto V_167;
}
F_100 ( & V_2 -> V_8 [ V_137 ] . V_26 ,
( void * ) V_2 ) ;
if ( V_2 -> V_79 -> V_168 != NULL )
V_11 = F_82 ( & V_2
-> V_8 [ V_137 ]
. V_26 . V_135 ,
& V_2 -> V_79
-> V_168 [ V_137 ] ) ;
if ( V_11 ) {
F_73 ( & V_2 -> V_26 ,
L_23 ) ;
goto V_169;
}
}
for ( V_137 = 0 ; V_137 < V_2 -> V_79 -> V_165 ; V_137 ++ ) {
V_11 = F_97 ( V_2 , V_137 ) ;
if ( V_11 )
goto V_170;
}
return 0 ;
V_170:
for ( V_164 = 0 ; V_164 < V_137 ; V_164 ++ )
F_98 ( V_2 , V_137 ) ;
V_137 = V_2 -> V_79 -> V_165 - 1 ;
V_169:
for ( V_164 = 0 ; V_164 < V_137 ; V_164 ++ )
if ( V_2 -> V_79 -> V_168 != NULL )
F_83 ( & V_2
-> V_8 [ V_164 ] . V_26 . V_135 ,
& V_2 -> V_79 -> V_168 [ V_164 ] ) ;
V_167:
for ( V_164 = 0 ; V_164 < V_137 ; V_164 ++ )
F_49 ( & V_2 -> V_8 [ V_164 ] ) ;
F_16 ( V_2 -> V_8 ) ;
V_20:
return V_11 ;
}
static void F_101 ( struct V_1 * V_2 )
{
int V_137 ;
if ( V_2 -> V_79 -> V_165 == 0 )
return;
for ( V_137 = 0 ; V_137 < V_2 -> V_79 -> V_165 ; V_137 ++ ) {
F_98 ( V_2 , V_137 ) ;
if ( V_2 -> V_79 -> V_168 != NULL )
F_83 ( & V_2
-> V_8 [ V_137 ] . V_26 . V_135 ,
& V_2 -> V_79 -> V_168 [ V_137 ] ) ;
}
for ( V_137 = 0 ; V_137 < V_2 -> V_79 -> V_165 ; V_137 ++ )
F_49 ( & V_2 -> V_8 [ V_137 ] ) ;
F_16 ( V_2 -> V_8 ) ;
}
static void F_102 ( struct V_25 * V_25 )
{
F_103 () ;
F_16 ( F_104 ( V_25 ) ) ;
}
struct V_1 * F_105 ( int V_171 )
{
struct V_1 * V_26 ;
T_4 V_172 ;
V_172 = sizeof( struct V_1 ) ;
if ( V_171 ) {
V_172 = F_106 ( V_172 , V_173 ) ;
V_172 += V_171 ;
}
V_172 += V_173 - 1 ;
V_26 = F_71 ( V_172 , V_18 ) ;
if ( V_26 ) {
V_26 -> V_26 . type = & V_174 ;
V_26 -> V_26 . V_62 = & V_63 ;
F_37 ( & V_26 -> V_26 ) ;
F_100 ( & V_26 -> V_26 , ( void * ) V_26 ) ;
F_43 ( & V_26 -> V_175 ) ;
F_107 () ;
}
return V_26 ;
}
void F_108 ( struct V_1 * V_26 )
{
if ( V_26 )
F_109 ( V_26 ) ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_11 ;
V_2 -> V_21 = F_85 ( & V_176 ) ;
if ( V_2 -> V_21 < 0 ) {
V_11 = V_2 -> V_21 ;
F_73 ( & V_2 -> V_26 , L_24 ) ;
goto V_20;
}
F_40 ( & V_2 -> V_26 , L_25 , V_2 -> V_21 ) ;
V_11 = F_41 ( & V_2 -> V_26 ) ;
if ( V_11 )
goto V_177;
V_11 = F_81 ( V_2 ) ;
if ( V_11 ) {
F_73 ( V_2 -> V_26 . V_64 ,
L_26 ) ;
goto V_178;
}
V_11 = F_99 ( V_2 ) ;
if ( V_11 ) {
F_73 ( V_2 -> V_26 . V_64 ,
L_27 ) ;
goto V_179;
}
if ( V_2 -> V_180 & V_181 )
F_111 ( V_2 ) ;
return 0 ;
V_179:
F_84 ( V_2 ) ;
V_178:
F_112 ( & V_2 -> V_26 ) ;
V_177:
F_86 ( & V_176 , V_2 -> V_21 ) ;
V_20:
return V_11 ;
}
void F_113 ( struct V_1 * V_2 )
{
if ( V_2 -> V_180 & V_181 )
F_114 ( V_2 ) ;
F_101 ( V_2 ) ;
F_84 ( V_2 ) ;
F_86 ( & V_176 , V_2 -> V_21 ) ;
F_47 ( & V_2 -> V_26 ) ;
}
void F_103 ( void )
{
F_115 ( V_182 ) ;
}
void F_107 ( void )
{
F_116 ( V_182 ) ;
}
