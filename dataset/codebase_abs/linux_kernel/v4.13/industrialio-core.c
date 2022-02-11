const struct V_1
* F_1 ( struct V_2 * V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ )
if ( V_3 -> V_7 [ V_5 ] . V_8 == V_4 )
return & V_3 -> V_7 [ V_5 ] ;
return NULL ;
}
T_1 F_2 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
return sprintf ( V_13 , L_1 , F_3 ( V_12 ) -> string ) ;
}
static int F_4 ( struct V_2 * V_3 , T_2 V_14 )
{
int V_15 ;
const struct V_16 * V_17 = V_3 -> V_18 ;
V_15 = F_5 ( & V_3 -> V_19 ) ;
if ( V_15 )
return V_15 ;
if ( ( V_17 && F_6 ( V_17 ) ) ||
F_7 ( V_3 ) ) {
F_8 ( & V_3 -> V_19 ) ;
return - V_20 ;
}
V_3 -> V_14 = V_14 ;
F_8 ( & V_3 -> V_19 ) ;
return 0 ;
}
T_3 F_9 ( const struct V_2 * V_3 )
{
struct V_21 V_22 ;
switch ( F_10 ( V_3 ) ) {
case V_23 :
F_11 ( & V_22 ) ;
break;
case V_24 :
F_12 ( & V_22 ) ;
break;
case V_25 :
F_13 ( & V_22 ) ;
break;
case V_26 :
V_22 = F_14 () ;
break;
case V_27 :
V_22 = F_15 () ;
break;
case V_28 :
F_16 ( & V_22 ) ;
break;
case V_29 :
F_17 ( & V_22 ) ;
break;
default:
F_18 () ;
}
return F_19 ( & V_22 ) ;
}
unsigned int F_20 ( const struct V_2 * V_3 )
{
switch ( F_10 ( V_3 ) ) {
case V_23 :
case V_24 :
case V_25 :
case V_28 :
case V_29 :
return V_30 ;
case V_26 :
case V_27 :
return V_31 ;
default:
F_18 () ;
}
}
static int T_4 F_21 ( void )
{
int V_15 ;
V_15 = F_22 ( & V_32 ) ;
if ( V_15 < 0 ) {
F_23 ( L_2 ) ;
goto V_33;
}
V_15 = F_24 ( & V_34 , 0 , V_35 , L_3 ) ;
if ( V_15 < 0 ) {
F_23 ( L_4 ) ;
goto V_36;
}
V_37 = F_25 ( L_3 , NULL ) ;
return 0 ;
V_36:
F_26 ( & V_32 ) ;
V_33:
return V_15 ;
}
static void T_5 F_27 ( void )
{
if ( V_34 )
F_28 ( V_34 , V_35 ) ;
F_26 ( & V_32 ) ;
F_29 ( V_37 ) ;
}
static T_1 F_30 ( struct V_38 * V_38 , char T_6 * V_39 ,
T_7 V_40 , T_8 * V_41 )
{
struct V_2 * V_3 = V_38 -> V_42 ;
char V_13 [ 20 ] ;
unsigned V_43 = 0 ;
T_1 V_44 ;
int V_15 ;
V_15 = V_3 -> V_45 -> V_46 ( V_3 ,
V_3 -> V_47 ,
0 , & V_43 ) ;
if ( V_15 )
F_31 ( V_3 -> V_10 . V_48 , L_5 , V_49 ) ;
V_44 = snprintf ( V_13 , sizeof( V_13 ) , L_6 , V_43 ) ;
return F_32 ( V_39 , V_40 , V_41 , V_13 , V_44 ) ;
}
static T_1 F_33 ( struct V_38 * V_38 ,
const char T_6 * V_39 , T_7 V_40 , T_8 * V_41 )
{
struct V_2 * V_3 = V_38 -> V_42 ;
unsigned V_50 , V_43 ;
char V_13 [ 80 ] ;
int V_15 ;
V_40 = F_34 ( T_7 , V_40 , ( sizeof( V_13 ) - 1 ) ) ;
if ( F_35 ( V_13 , V_39 , V_40 ) )
return - V_51 ;
V_13 [ V_40 ] = 0 ;
V_15 = sscanf ( V_13 , L_7 , & V_50 , & V_43 ) ;
switch ( V_15 ) {
case 1 :
V_3 -> V_47 = V_50 ;
break;
case 2 :
V_3 -> V_47 = V_50 ;
V_15 = V_3 -> V_45 -> V_46 ( V_3 , V_50 ,
V_43 , NULL ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 , L_8 ,
V_49 ) ;
return V_15 ;
}
break;
default:
return - V_52 ;
}
return V_40 ;
}
static void F_36 ( struct V_2 * V_3 )
{
F_37 ( V_3 -> V_53 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_54 * V_55 ;
if ( V_3 -> V_45 -> V_46 == NULL )
return 0 ;
if ( ! V_37 )
return 0 ;
V_3 -> V_53 =
F_25 ( F_39 ( & V_3 -> V_10 ) ,
V_37 ) ;
if ( V_3 -> V_53 == NULL ) {
F_40 ( V_3 -> V_10 . V_48 ,
L_9 ) ;
return - V_51 ;
}
V_55 = F_41 ( L_10 , 0644 ,
V_3 -> V_53 ,
V_3 , & V_56 ) ;
if ( ! V_55 ) {
F_36 ( V_3 ) ;
return - V_57 ;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_36 ( struct V_2 * V_3 )
{
}
static T_1 F_42 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
struct V_58 * V_59 = F_44 ( V_12 ) ;
const struct V_60 * V_61 ;
V_61 = & V_59 -> V_62 -> V_61 [ V_59 -> V_63 ] ;
return V_61 -> V_64 ( V_3 , V_61 -> V_65 , V_59 -> V_62 , V_13 ) ;
}
static T_1 F_45 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_7 V_44 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
struct V_58 * V_59 = F_44 ( V_12 ) ;
const struct V_60 * V_61 ;
V_61 = & V_59 -> V_62 -> V_61 [ V_59 -> V_63 ] ;
return V_61 -> V_66 ( V_3 , V_61 -> V_65 ,
V_59 -> V_62 , V_13 , V_44 ) ;
}
T_1 F_46 ( struct V_2 * V_3 ,
T_9 V_67 , const struct V_1 * V_68 , char * V_13 )
{
const struct V_69 * V_70 = ( const struct V_69 * ) V_67 ;
unsigned int V_5 ;
T_7 V_44 = 0 ;
if ( ! V_70 -> V_71 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_70 -> V_71 ; ++ V_5 )
V_44 += F_47 ( V_13 + V_44 , V_72 - V_44 , L_11 , V_70 -> V_73 [ V_5 ] ) ;
V_13 [ V_44 - 1 ] = '\n' ;
return V_44 ;
}
T_1 F_48 ( struct V_2 * V_3 ,
T_9 V_67 , const struct V_1 * V_68 , char * V_13 )
{
const struct V_69 * V_70 = ( const struct V_69 * ) V_67 ;
int V_5 ;
if ( ! V_70 -> V_74 )
return - V_52 ;
V_5 = V_70 -> V_74 ( V_3 , V_68 ) ;
if ( V_5 < 0 )
return V_5 ;
else if ( V_5 >= V_70 -> V_71 )
return - V_52 ;
return snprintf ( V_13 , V_72 , L_1 , V_70 -> V_73 [ V_5 ] ) ;
}
T_1 F_49 ( struct V_2 * V_3 ,
T_9 V_67 , const struct V_1 * V_68 , const char * V_13 ,
T_7 V_44 )
{
const struct V_69 * V_70 = ( const struct V_69 * ) V_67 ;
int V_15 ;
if ( ! V_70 -> V_75 )
return - V_52 ;
V_15 = F_50 ( V_70 -> V_73 , V_70 -> V_71 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = V_70 -> V_75 ( V_3 , V_68 , V_15 ) ;
return V_15 ? V_15 : V_44 ;
}
static int F_51 ( const struct V_9 * V_10 ,
struct V_76 * V_77 )
{
* V_77 = V_78 ;
F_52 ( V_10 , L_12 ) ;
return 0 ;
}
T_1 F_53 ( struct V_2 * V_3 , T_9 V_67 ,
const struct V_1 * V_68 , char * V_13 )
{
const struct V_76 * V_79 = ( ( V_80 * )
V_67 ) ( V_3, V_68 ) ;
if ( F_54 ( V_79 ) )
return F_55 ( V_79 ) ;
if ( ! V_79 )
V_79 = & V_78 ;
return snprintf ( V_13 , V_72 , L_13 ,
V_79 -> V_81 [ 0 ] , V_79 -> V_81 [ 1 ] , V_79 -> V_81 [ 2 ] ,
V_79 -> V_81 [ 3 ] , V_79 -> V_81 [ 4 ] , V_79 -> V_81 [ 5 ] ,
V_79 -> V_81 [ 6 ] , V_79 -> V_81 [ 7 ] , V_79 -> V_81 [ 8 ] ) ;
}
int F_56 ( const struct V_9 * V_10 ,
const char * V_82 ,
struct V_76 * V_77 )
{
if ( V_10 -> V_83 ) {
int V_84 = F_57 ( V_10 -> V_83 ,
V_82 , V_77 -> V_81 ,
F_58 ( V_78 . V_81 ) ) ;
if ( V_84 == F_58 ( V_78 . V_81 ) )
return 0 ;
if ( V_84 >= 0 )
return - V_52 ;
if ( V_84 != - V_52 )
return V_84 ;
}
return F_51 ( V_10 , V_77 ) ;
}
int F_56 ( const struct V_9 * V_10 ,
const char * V_82 ,
struct V_76 * V_77 )
{
return F_51 ( V_10 , V_77 ) ;
}
static T_1 F_59 ( char * V_13 , T_7 V_44 , unsigned int type ,
int V_85 , const int * V_86 )
{
unsigned long long V_87 ;
int V_88 , V_89 ;
bool V_90 = false ;
switch ( type ) {
case V_91 :
return snprintf ( V_13 , V_44 , L_14 , V_86 [ 0 ] ) ;
case V_92 :
V_90 = true ;
case V_93 :
if ( V_86 [ 1 ] < 0 )
return snprintf ( V_13 , V_44 , L_15 , abs ( V_86 [ 0 ] ) ,
- V_86 [ 1 ] , V_90 ? L_16 : L_17 ) ;
else
return snprintf ( V_13 , V_44 , L_18 , V_86 [ 0 ] , V_86 [ 1 ] ,
V_90 ? L_16 : L_17 ) ;
case V_94 :
if ( V_86 [ 1 ] < 0 )
return snprintf ( V_13 , V_44 , L_19 , abs ( V_86 [ 0 ] ) ,
- V_86 [ 1 ] ) ;
else
return snprintf ( V_13 , V_44 , L_20 , V_86 [ 0 ] , V_86 [ 1 ] ) ;
case V_95 :
V_87 = F_60 ( ( T_3 ) V_86 [ 0 ] * 1000000000LL , V_86 [ 1 ] ) ;
V_89 = V_86 [ 1 ] ;
V_88 = ( int ) F_61 ( V_87 , 1000000000 , & V_89 ) ;
return snprintf ( V_13 , V_44 , L_20 , V_88 , abs ( V_89 ) ) ;
case V_96 :
V_87 = F_62 ( ( T_3 ) V_86 [ 0 ] * 1000000000LL , V_86 [ 1 ] ) ;
V_88 = ( int ) F_61 ( V_87 , 1000000000LL , & V_89 ) ;
return snprintf ( V_13 , V_44 , L_20 , V_88 , abs ( V_89 ) ) ;
case V_97 :
{
int V_5 ;
int V_98 = 0 ;
for ( V_5 = 0 ; V_5 < V_85 ; ++ V_5 ) {
V_98 += snprintf ( & V_13 [ V_98 ] , V_44 - V_98 , L_21 , V_86 [ V_5 ] ) ;
if ( V_98 >= V_44 )
break;
}
return V_98 ;
}
default:
return 0 ;
}
}
T_1 F_63 ( char * V_13 , unsigned int type , int V_85 , int * V_86 )
{
T_1 V_44 ;
V_44 = F_59 ( V_13 , V_72 , type , V_85 , V_86 ) ;
if ( V_44 >= V_72 - 1 )
return - V_99 ;
return V_44 + sprintf ( V_13 + V_44 , L_22 ) ;
}
static T_1 F_64 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
struct V_58 * V_59 = F_44 ( V_12 ) ;
int V_86 [ V_100 ] ;
int V_15 ;
int V_101 = 2 ;
if ( V_3 -> V_45 -> V_102 )
V_15 = V_3 -> V_45 -> V_102 ( V_3 , V_59 -> V_62 ,
V_100 ,
V_86 , & V_101 ,
V_59 -> V_63 ) ;
else
V_15 = V_3 -> V_45 -> V_103 ( V_3 , V_59 -> V_62 ,
& V_86 [ 0 ] , & V_86 [ 1 ] , V_59 -> V_63 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_63 ( V_13 , V_15 , V_101 , V_86 ) ;
}
static T_1 F_65 ( char * V_13 , const int * V_86 ,
int type , int V_104 )
{
int V_5 ;
T_1 V_44 = 0 ;
switch ( type ) {
case V_91 :
for ( V_5 = 0 ; V_5 < V_104 ; V_5 ++ ) {
V_44 += F_59 ( V_13 + V_44 , V_72 - V_44 ,
type , 1 , & V_86 [ V_5 ] ) ;
if ( V_44 >= V_72 )
return - V_99 ;
if ( V_5 < V_104 - 1 )
V_44 += snprintf ( V_13 + V_44 , V_72 - V_44 ,
L_23 ) ;
else
V_44 += snprintf ( V_13 + V_44 , V_72 - V_44 ,
L_22 ) ;
if ( V_44 >= V_72 )
return - V_99 ;
}
break;
default:
for ( V_5 = 0 ; V_5 < V_104 / 2 ; V_5 ++ ) {
V_44 += F_59 ( V_13 + V_44 , V_72 - V_44 ,
type , 2 , & V_86 [ V_5 * 2 ] ) ;
if ( V_44 >= V_72 )
return - V_99 ;
if ( V_5 < V_104 / 2 - 1 )
V_44 += snprintf ( V_13 + V_44 , V_72 - V_44 ,
L_23 ) ;
else
V_44 += snprintf ( V_13 + V_44 , V_72 - V_44 ,
L_22 ) ;
if ( V_44 >= V_72 )
return - V_99 ;
}
}
return V_44 ;
}
static T_1 F_66 ( char * V_13 , const int * V_86 , int type )
{
int V_5 ;
T_1 V_44 ;
V_44 = snprintf ( V_13 , V_72 , L_24 ) ;
switch ( type ) {
case V_91 :
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_44 += F_59 ( V_13 + V_44 , V_72 - V_44 ,
type , 1 , & V_86 [ V_5 ] ) ;
if ( V_44 >= V_72 )
return - V_99 ;
if ( V_5 < 2 )
V_44 += snprintf ( V_13 + V_44 , V_72 - V_44 ,
L_23 ) ;
else
V_44 += snprintf ( V_13 + V_44 , V_72 - V_44 ,
L_25 ) ;
if ( V_44 >= V_72 )
return - V_99 ;
}
break;
default:
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_44 += F_59 ( V_13 + V_44 , V_72 - V_44 ,
type , 2 , & V_86 [ V_5 * 2 ] ) ;
if ( V_44 >= V_72 )
return - V_99 ;
if ( V_5 < 2 )
V_44 += snprintf ( V_13 + V_44 , V_72 - V_44 ,
L_23 ) ;
else
V_44 += snprintf ( V_13 + V_44 , V_72 - V_44 ,
L_25 ) ;
if ( V_44 >= V_72 )
return - V_99 ;
}
}
return V_44 ;
}
static T_1 F_67 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
struct V_58 * V_59 = F_44 ( V_12 ) ;
const int * V_86 ;
int V_15 ;
int V_104 ;
int type ;
V_15 = V_3 -> V_45 -> V_105 ( V_3 , V_59 -> V_62 ,
& V_86 , & type , & V_104 ,
V_59 -> V_63 ) ;
if ( V_15 < 0 )
return V_15 ;
switch ( V_15 ) {
case V_106 :
return F_65 ( V_13 , V_86 , type , V_104 ) ;
case V_107 :
return F_66 ( V_13 , V_86 , type ) ;
default:
return - V_52 ;
}
}
int F_68 ( const char * V_108 , int V_109 ,
int * integer , int * V_110 )
{
int V_5 = 0 , V_111 = 0 ;
bool V_112 = true , V_113 = false ;
if ( V_109 == 0 ) {
* V_110 = 0 ;
return F_69 ( V_108 , 0 , integer ) ;
}
if ( V_108 [ 0 ] == '-' ) {
V_113 = true ;
V_108 ++ ;
} else if ( V_108 [ 0 ] == '+' ) {
V_108 ++ ;
}
while ( * V_108 ) {
if ( '0' <= * V_108 && * V_108 <= '9' ) {
if ( V_112 ) {
V_5 = V_5 * 10 + * V_108 - '0' ;
} else {
V_111 += V_109 * ( * V_108 - '0' ) ;
V_109 /= 10 ;
}
} else if ( * V_108 == '\n' ) {
if ( * ( V_108 + 1 ) == '\0' )
break;
else
return - V_52 ;
} else if ( * V_108 == '.' && V_112 ) {
V_112 = false ;
} else {
return - V_52 ;
}
V_108 ++ ;
}
if ( V_113 ) {
if ( V_5 )
V_5 = - V_5 ;
else
V_111 = - V_111 ;
}
* integer = V_5 ;
* V_110 = V_111 ;
return 0 ;
}
static T_1 F_70 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_7 V_44 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
struct V_58 * V_59 = F_44 ( V_12 ) ;
int V_15 , V_109 = 100000 ;
int integer , V_110 ;
if ( ! V_3 -> V_45 -> V_114 )
return - V_52 ;
if ( V_3 -> V_45 -> V_115 )
switch ( V_3 -> V_45 -> V_115 ( V_3 ,
V_59 -> V_62 , V_59 -> V_63 ) ) {
case V_91 :
V_109 = 0 ;
break;
case V_93 :
V_109 = 100000 ;
break;
case V_94 :
V_109 = 100000000 ;
break;
default:
return - V_52 ;
}
V_15 = F_68 ( V_13 , V_109 , & integer , & V_110 ) ;
if ( V_15 )
return V_15 ;
V_15 = V_3 -> V_45 -> V_114 ( V_3 , V_59 -> V_62 ,
integer , V_110 , V_59 -> V_63 ) ;
if ( V_15 )
return V_15 ;
return V_44 ;
}
static
int F_71 ( struct V_11 * V_116 ,
const char * V_117 ,
struct V_1 const * V_68 ,
T_1 (* F_72)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_73)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_7 V_44 ) ,
enum V_118 V_119 )
{
int V_15 = 0 ;
char * V_120 = NULL ;
char * V_121 ;
F_74 ( & V_116 -> V_12 ) ;
if ( V_68 -> V_122 && ( V_119 == V_123 ) ) {
if ( V_68 -> V_124 )
V_121 = F_75 ( V_125 , L_26 ,
V_126 [ V_68
-> V_127 ] ,
V_68 -> V_124 ,
V_117 ) ;
else
V_121 = F_75 ( V_125 , L_27 ,
V_126 [ V_68
-> V_127 ] ,
V_117 ) ;
} else {
if ( V_68 -> V_124 == NULL || V_119 != V_123 )
V_121 = F_76 ( V_117 , V_125 ) ;
else
V_121 = F_75 ( V_125 ,
L_27 ,
V_68 -> V_124 ,
V_117 ) ;
}
if ( V_121 == NULL )
return - V_57 ;
if ( V_68 -> V_128 ) {
switch ( V_119 ) {
case V_129 :
V_120 = F_75 ( V_125 , L_28 , V_121 ) ;
break;
case V_130 :
V_120 = F_75 ( V_125 , L_27 ,
V_131 [ V_68 -> V_132 ] ,
V_121 ) ;
break;
case V_133 :
V_120 = F_75 ( V_125 , L_29 ,
V_131 [ V_68 -> V_132 ] ,
V_134 [ V_68 -> type ] ,
V_134 [ V_68 -> type ] ,
V_121 ) ;
break;
case V_123 :
if ( ! V_68 -> V_135 ) {
F_77 ( 1 , L_30 ) ;
V_15 = - V_52 ;
goto V_136;
}
V_120 = F_75 ( V_125 ,
L_31 ,
V_131 [ V_68 -> V_132 ] ,
V_134 [ V_68 -> type ] ,
V_68 -> V_137 ,
V_134 [ V_68 -> type ] ,
V_68 -> V_127 ,
V_121 ) ;
break;
}
} else {
switch ( V_119 ) {
case V_129 :
V_120 = F_75 ( V_125 , L_28 , V_121 ) ;
break;
case V_130 :
V_120 = F_75 ( V_125 , L_27 ,
V_131 [ V_68 -> V_132 ] ,
V_121 ) ;
break;
case V_133 :
V_120 = F_75 ( V_125 , L_26 ,
V_131 [ V_68 -> V_132 ] ,
V_134 [ V_68 -> type ] ,
V_121 ) ;
break;
case V_123 :
if ( V_68 -> V_135 )
V_120 = F_75 ( V_125 , L_32 ,
V_131 [ V_68 -> V_132 ] ,
V_134 [ V_68 -> type ] ,
V_68 -> V_137 ,
V_121 ) ;
else
V_120 = F_75 ( V_125 , L_26 ,
V_131 [ V_68 -> V_132 ] ,
V_134 [ V_68 -> type ] ,
V_121 ) ;
break;
}
}
if ( V_120 == NULL ) {
V_15 = - V_57 ;
goto V_136;
}
V_116 -> V_12 . V_120 = V_120 ;
if ( F_72 ) {
V_116 -> V_12 . V_138 |= V_139 ;
V_116 -> V_140 = F_72 ;
}
if ( F_73 ) {
V_116 -> V_12 . V_138 |= V_141 ;
V_116 -> V_142 = F_73 ;
}
V_136:
F_78 ( V_121 ) ;
return V_15 ;
}
static void F_79 ( struct V_11 * V_116 )
{
F_78 ( V_116 -> V_12 . V_120 ) ;
}
int F_80 ( const char * V_117 ,
struct V_1 const * V_68 ,
T_1 (* F_72)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_73)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_7 V_44 ) ,
T_10 V_143 ,
enum V_118 V_119 ,
struct V_9 * V_10 ,
struct V_144 * V_145 )
{
int V_15 ;
struct V_58 * V_146 , * V_147 ;
V_146 = F_81 ( sizeof( * V_146 ) , V_125 ) ;
if ( V_146 == NULL )
return - V_57 ;
V_15 = F_71 ( & V_146 -> V_116 ,
V_117 , V_68 ,
F_72 , F_73 , V_119 ) ;
if ( V_15 )
goto V_148;
V_146 -> V_62 = V_68 ;
V_146 -> V_63 = V_143 ;
F_82 (t, attr_list, l)
if ( strcmp ( V_147 -> V_116 . V_12 . V_120 ,
V_146 -> V_116 . V_12 . V_120 ) == 0 ) {
if ( V_119 == V_123 )
F_31 ( V_10 , L_33 ,
V_147 -> V_116 . V_12 . V_120 ) ;
V_15 = - V_20 ;
goto V_149;
}
F_83 ( & V_146 -> V_98 , V_145 ) ;
return 0 ;
V_149:
F_79 ( & V_146 -> V_116 ) ;
V_148:
F_78 ( V_146 ) ;
return V_15 ;
}
static int F_84 ( struct V_2 * V_3 ,
struct V_1 const * V_68 ,
enum V_118 V_119 ,
const long * V_150 )
{
int V_5 , V_15 , V_151 = 0 ;
F_85 (i, infomask, sizeof(*infomask)*8 ) {
if ( V_5 >= F_58 ( V_152 ) )
return - V_52 ;
V_15 = F_80 ( V_152 [ V_5 ] ,
V_68 ,
& F_64 ,
& F_70 ,
V_5 ,
V_119 ,
& V_3 -> V_10 ,
& V_3 -> V_153 ) ;
if ( ( V_15 == - V_20 ) && ( V_119 != V_123 ) )
continue;
else if ( V_15 < 0 )
return V_15 ;
V_151 ++ ;
}
return V_151 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_1 const * V_68 ,
enum V_118 V_119 ,
const long * V_150 )
{
int V_5 , V_15 , V_151 = 0 ;
char * V_154 ;
F_85 (i, infomask, sizeof(*infomask) * 8 ) {
V_154 = F_75 ( V_125 ,
L_34 ,
V_152 [ V_5 ] ) ;
if ( ! V_154 )
return - V_57 ;
V_15 = F_80 ( V_154 ,
V_68 ,
& F_67 ,
NULL ,
V_5 ,
V_119 ,
& V_3 -> V_10 ,
& V_3 -> V_153 ) ;
F_78 ( V_154 ) ;
if ( ( V_15 == - V_20 ) && ( V_119 != V_123 ) )
continue;
else if ( V_15 < 0 )
return V_15 ;
V_151 ++ ;
}
return V_151 ;
}
static int F_87 ( struct V_2 * V_3 ,
struct V_1 const * V_68 )
{
int V_15 , V_151 = 0 ;
const struct V_60 * V_61 ;
if ( V_68 -> V_137 < 0 )
return 0 ;
V_15 = F_84 ( V_3 , V_68 ,
V_123 ,
& V_68 -> V_155 ) ;
if ( V_15 < 0 )
return V_15 ;
V_151 += V_15 ;
V_15 = F_86 ( V_3 , V_68 ,
V_123 ,
& V_68 ->
V_156 ) ;
if ( V_15 < 0 )
return V_15 ;
V_151 += V_15 ;
V_15 = F_84 ( V_3 , V_68 ,
V_133 ,
& V_68 -> V_157 ) ;
if ( V_15 < 0 )
return V_15 ;
V_151 += V_15 ;
V_15 = F_86 ( V_3 , V_68 ,
V_133 ,
& V_68 ->
V_158 ) ;
if ( V_15 < 0 )
return V_15 ;
V_151 += V_15 ;
V_15 = F_84 ( V_3 , V_68 ,
V_130 ,
& V_68 -> V_159 ) ;
if ( V_15 < 0 )
return V_15 ;
V_151 += V_15 ;
V_15 = F_86 ( V_3 , V_68 ,
V_130 ,
& V_68 -> V_160 ) ;
if ( V_15 < 0 )
return V_15 ;
V_151 += V_15 ;
V_15 = F_84 ( V_3 , V_68 ,
V_129 ,
& V_68 -> V_161 ) ;
if ( V_15 < 0 )
return V_15 ;
V_151 += V_15 ;
V_15 = F_86 ( V_3 , V_68 ,
V_129 ,
& V_68 -> V_162 ) ;
if ( V_15 < 0 )
return V_15 ;
V_151 += V_15 ;
if ( V_68 -> V_61 ) {
unsigned int V_5 = 0 ;
for ( V_61 = V_68 -> V_61 ; V_61 -> V_120 ; V_61 ++ ) {
V_15 = F_80 ( V_61 -> V_120 ,
V_68 ,
V_61 -> V_64 ?
& F_42 : NULL ,
V_61 -> V_66 ?
& F_45 : NULL ,
V_5 ,
V_61 -> V_163 ,
& V_3 -> V_10 ,
& V_3 -> V_153 ) ;
V_5 ++ ;
if ( V_15 == - V_20 && V_61 -> V_163 )
continue;
if ( V_15 )
return V_15 ;
V_151 ++ ;
}
}
return V_151 ;
}
void F_88 ( struct V_144 * V_145 )
{
struct V_58 * V_164 , * V_165 ;
F_89 (p, n, attr_list, l) {
F_78 ( V_164 -> V_116 . V_12 . V_120 ) ;
F_90 ( & V_164 -> V_98 ) ;
F_78 ( V_164 ) ;
}
}
static T_1 F_91 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
return snprintf ( V_13 , V_72 , L_1 , V_3 -> V_120 ) ;
}
static T_1 F_92 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
const struct V_2 * V_3 = F_43 ( V_10 ) ;
const T_2 V_166 = F_10 ( V_3 ) ;
const char * V_120 ;
T_1 V_167 ;
switch ( V_166 ) {
case V_23 :
V_120 = L_35 ;
V_167 = sizeof( L_35 ) ;
break;
case V_24 :
V_120 = L_36 ;
V_167 = sizeof( L_36 ) ;
break;
case V_25 :
V_120 = L_37 ;
V_167 = sizeof( L_37 ) ;
break;
case V_26 :
V_120 = L_38 ;
V_167 = sizeof( L_38 ) ;
break;
case V_27 :
V_120 = L_39 ;
V_167 = sizeof( L_39 ) ;
break;
case V_28 :
V_120 = L_40 ;
V_167 = sizeof( L_40 ) ;
break;
case V_29 :
V_120 = L_41 ;
V_167 = sizeof( L_41 ) ;
break;
default:
F_18 () ;
}
memcpy ( V_13 , V_120 , V_167 ) ;
return V_167 ;
}
static T_1 F_93 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_7 V_44 )
{
T_2 V_166 ;
int V_15 ;
if ( F_94 ( V_13 , L_42 ) )
V_166 = V_23 ;
else if ( F_94 ( V_13 , L_43 ) )
V_166 = V_24 ;
else if ( F_94 ( V_13 , L_44 ) )
V_166 = V_25 ;
else if ( F_94 ( V_13 , L_45 ) )
V_166 = V_26 ;
else if ( F_94 ( V_13 , L_46 ) )
V_166 = V_27 ;
else if ( F_94 ( V_13 , L_47 ) )
V_166 = V_28 ;
else if ( F_94 ( V_13 , L_48 ) )
V_166 = V_29 ;
else
return - V_52 ;
V_15 = F_4 ( F_43 ( V_10 ) , V_166 ) ;
if ( V_15 )
return V_15 ;
return V_44 ;
}
static int F_95 ( struct V_2 * V_3 )
{
int V_5 , V_15 = 0 , V_151 , V_168 , V_169 = 0 ;
struct V_58 * V_164 ;
struct V_170 * * V_12 , * V_166 = NULL ;
if ( V_3 -> V_45 -> V_171 ) {
V_12 = V_3 -> V_45 -> V_171 -> V_171 ;
while ( * V_12 ++ != NULL )
V_169 ++ ;
}
V_151 = V_169 ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
const struct V_1 * V_68 =
& V_3 -> V_7 [ V_5 ] ;
if ( V_68 -> type == V_172 )
V_166 = & V_173 . V_12 ;
V_15 = F_87 ( V_3 , V_68 ) ;
if ( V_15 < 0 )
goto V_174;
V_151 += V_15 ;
}
if ( V_3 -> V_18 )
V_166 = & V_173 . V_12 ;
if ( V_3 -> V_120 )
V_151 ++ ;
if ( V_166 )
V_151 ++ ;
V_3 -> V_175 . V_171 = F_96 ( V_151 + 1 ,
sizeof( V_3 -> V_175 . V_171 [ 0 ] ) ,
V_125 ) ;
if ( V_3 -> V_175 . V_171 == NULL ) {
V_15 = - V_57 ;
goto V_174;
}
if ( V_3 -> V_45 -> V_171 )
memcpy ( V_3 -> V_175 . V_171 ,
V_3 -> V_45 -> V_171 -> V_171 ,
sizeof( V_3 -> V_175 . V_171 [ 0 ] )
* V_169 ) ;
V_168 = V_169 ;
F_82 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_175 . V_171 [ V_168 ++ ] = & V_164 -> V_116 . V_12 ;
if ( V_3 -> V_120 )
V_3 -> V_175 . V_171 [ V_168 ++ ] = & V_176 . V_12 ;
if ( V_166 )
V_3 -> V_175 . V_171 [ V_168 ++ ] = V_166 ;
V_3 -> V_177 [ V_3 -> V_178 ++ ] =
& V_3 -> V_175 ;
return 0 ;
V_174:
F_88 ( & V_3 -> V_153 ) ;
return V_15 ;
}
static void F_97 ( struct V_2 * V_3 )
{
F_88 ( & V_3 -> V_153 ) ;
F_78 ( V_3 -> V_175 . V_171 ) ;
V_3 -> V_175 . V_171 = NULL ;
}
static void F_98 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_43 ( V_9 ) ;
if ( V_3 -> V_179 & V_180 )
F_99 ( V_3 ) ;
F_100 ( V_3 ) ;
F_97 ( V_3 ) ;
F_101 ( V_3 -> V_181 ) ;
F_102 ( & V_182 , V_3 -> V_183 ) ;
F_78 ( V_3 ) ;
}
struct V_2 * F_103 ( int V_184 )
{
struct V_2 * V_10 ;
T_7 V_185 ;
V_185 = sizeof( struct V_2 ) ;
if ( V_184 ) {
V_185 = F_104 ( V_185 , V_186 ) ;
V_185 += V_184 ;
}
V_185 += V_186 - 1 ;
V_10 = F_81 ( V_185 , V_125 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_177 = V_10 -> V_177 ;
V_10 -> V_10 . type = & V_187 ;
V_10 -> V_10 . V_188 = & V_32 ;
F_105 ( & V_10 -> V_10 ) ;
F_106 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_107 ( & V_10 -> V_19 ) ;
F_107 ( & V_10 -> V_189 ) ;
F_108 ( & V_10 -> V_153 ) ;
V_10 -> V_183 = F_109 ( & V_182 , 0 , 0 , V_125 ) ;
if ( V_10 -> V_183 < 0 ) {
F_23 ( L_49 ) ;
F_78 ( V_10 ) ;
return NULL ;
}
F_110 ( & V_10 -> V_10 , L_50 , V_10 -> V_183 ) ;
F_108 ( & V_10 -> V_190 ) ;
}
return V_10 ;
}
void F_111 ( struct V_2 * V_10 )
{
if ( V_10 )
F_112 ( & V_10 -> V_10 ) ;
}
static void F_113 ( struct V_9 * V_10 , void * V_191 )
{
F_111 ( * (struct V_2 * * ) V_191 ) ;
}
int F_114 ( struct V_9 * V_10 , void * V_191 , void * V_192 )
{
struct V_2 * * V_193 = V_191 ;
if ( ! V_193 || ! * V_193 ) {
F_115 ( ! V_193 || ! * V_193 ) ;
return 0 ;
}
return * V_193 == V_192 ;
}
struct V_2 * F_116 ( struct V_9 * V_10 , int V_184 )
{
struct V_2 * * V_194 , * V_2 ;
V_194 = F_117 ( F_113 , sizeof( * V_194 ) ,
V_125 ) ;
if ( ! V_194 )
return NULL ;
V_2 = F_103 ( V_184 ) ;
if ( V_2 ) {
* V_194 = V_2 ;
F_118 ( V_10 , V_194 ) ;
} else {
F_119 ( V_194 ) ;
}
return V_2 ;
}
void F_120 ( struct V_9 * V_10 , struct V_2 * V_2 )
{
int V_195 ;
V_195 = F_121 ( V_10 , F_113 ,
F_114 , V_2 ) ;
F_115 ( V_195 ) ;
}
static int F_122 ( struct V_196 * V_196 , struct V_38 * V_197 )
{
struct V_2 * V_3 = F_123 ( V_196 -> V_198 ,
struct V_2 , V_199 ) ;
if ( F_124 ( V_200 , & V_3 -> V_201 ) )
return - V_20 ;
F_125 ( V_3 ) ;
V_197 -> V_42 = V_3 ;
return 0 ;
}
static int F_126 ( struct V_196 * V_196 , struct V_38 * V_197 )
{
struct V_2 * V_3 = F_123 ( V_196 -> V_198 ,
struct V_2 , V_199 ) ;
F_127 ( V_200 , & V_3 -> V_201 ) ;
F_128 ( V_3 ) ;
return 0 ;
}
static long F_129 ( struct V_38 * V_197 , unsigned int V_202 , unsigned long V_203 )
{
struct V_2 * V_3 = V_197 -> V_42 ;
int T_6 * V_204 = ( int T_6 * ) V_203 ;
int V_205 ;
if ( ! V_3 -> V_45 )
return - V_206 ;
if ( V_202 == V_207 ) {
V_205 = F_130 ( V_3 ) ;
if ( V_205 < 0 )
return V_205 ;
if ( F_131 ( V_204 , & V_205 , sizeof( V_205 ) ) )
return - V_51 ;
return 0 ;
}
return - V_52 ;
}
static int F_132 ( struct V_2 * V_3 )
{
int V_5 , V_208 ;
const struct V_1 * V_7 = V_3 -> V_7 ;
if ( ! ( V_3 -> V_179 & V_209 ) )
return 0 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 - 1 ; V_5 ++ ) {
if ( V_7 [ V_5 ] . V_8 < 0 )
continue;
for ( V_208 = V_5 + 1 ; V_208 < V_3 -> V_6 ; V_208 ++ )
if ( V_7 [ V_5 ] . V_8 == V_7 [ V_208 ] . V_8 ) {
F_31 ( & V_3 -> V_10 ,
L_51 ,
V_7 [ V_5 ] . V_8 ) ;
return - V_52 ;
}
}
return 0 ;
}
int F_133 ( struct V_2 * V_3 )
{
int V_15 ;
if ( ! V_3 -> V_10 . V_83 && V_3 -> V_10 . V_48 )
V_3 -> V_10 . V_83 = V_3 -> V_10 . V_48 -> V_83 ;
V_15 = F_132 ( V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 -> V_10 . V_210 = F_134 ( F_135 ( V_34 ) , V_3 -> V_183 ) ;
V_15 = F_38 ( V_3 ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 ,
L_52 ) ;
return V_15 ;
}
V_15 = F_136 ( V_3 ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 ,
L_53 ) ;
goto V_211;
}
V_15 = F_95 ( V_3 ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 ,
L_54 ) ;
goto V_212;
}
V_15 = F_137 ( V_3 ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 ,
L_55 ) ;
goto V_213;
}
if ( V_3 -> V_179 & V_180 )
F_138 ( V_3 ) ;
if ( ( V_3 -> V_179 & V_209 ) &&
V_3 -> V_214 == NULL )
V_3 -> V_214 = & V_215 ;
F_139 ( & V_3 -> V_199 , & V_216 ) ;
V_3 -> V_199 . V_217 = V_3 -> V_45 -> V_218 ;
V_15 = F_140 ( & V_3 -> V_199 , & V_3 -> V_10 ) ;
if ( V_15 < 0 )
goto V_219;
return 0 ;
V_219:
F_100 ( V_3 ) ;
V_213:
F_97 ( V_3 ) ;
V_212:
F_141 ( V_3 ) ;
V_211:
F_36 ( V_3 ) ;
return V_15 ;
}
void F_142 ( struct V_2 * V_3 )
{
F_143 ( & V_3 -> V_189 ) ;
F_144 ( & V_3 -> V_199 , & V_3 -> V_10 ) ;
F_36 ( V_3 ) ;
F_145 ( V_3 ) ;
V_3 -> V_45 = NULL ;
F_146 ( V_3 ) ;
F_147 ( V_3 ) ;
F_8 ( & V_3 -> V_189 ) ;
F_141 ( V_3 ) ;
}
static void F_148 ( struct V_9 * V_10 , void * V_191 )
{
F_142 ( * (struct V_2 * * ) V_191 ) ;
}
int F_149 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
struct V_2 * * V_194 ;
int V_15 ;
V_194 = F_117 ( F_148 , sizeof( * V_194 ) , V_125 ) ;
if ( ! V_194 )
return - V_57 ;
* V_194 = V_3 ;
V_15 = F_133 ( V_3 ) ;
if ( ! V_15 )
F_118 ( V_10 , V_194 ) ;
else
F_119 ( V_194 ) ;
return V_15 ;
}
void F_150 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_195 ;
V_195 = F_121 ( V_10 , F_148 ,
F_114 , V_3 ) ;
F_115 ( V_195 ) ;
}
int F_151 ( struct V_2 * V_3 )
{
F_143 ( & V_3 -> V_19 ) ;
if ( F_7 ( V_3 ) ) {
F_8 ( & V_3 -> V_19 ) ;
return - V_20 ;
}
return 0 ;
}
void F_152 ( struct V_2 * V_3 )
{
F_8 ( & V_3 -> V_19 ) ;
}
