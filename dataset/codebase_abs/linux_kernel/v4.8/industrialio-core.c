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
unsigned int V_5 ;
int V_15 ;
if ( ! V_70 -> V_75 )
return - V_52 ;
for ( V_5 = 0 ; V_5 < V_70 -> V_71 ; V_5 ++ ) {
if ( F_50 ( V_13 , V_70 -> V_73 [ V_5 ] ) )
break;
}
if ( V_5 == V_70 -> V_71 )
return - V_52 ;
V_15 = V_70 -> V_75 ( V_3 , V_68 , V_5 ) ;
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
T_1 F_59 ( char * V_13 , unsigned int type , int V_85 , int * V_86 )
{
unsigned long long V_87 ;
bool V_88 = false ;
switch ( type ) {
case V_89 :
return sprintf ( V_13 , L_14 , V_86 [ 0 ] ) ;
case V_90 :
V_88 = true ;
case V_91 :
if ( V_86 [ 1 ] < 0 )
return sprintf ( V_13 , L_15 , abs ( V_86 [ 0 ] ) ,
- V_86 [ 1 ] , V_88 ? L_16 : L_17 ) ;
else
return sprintf ( V_13 , L_18 , V_86 [ 0 ] , V_86 [ 1 ] ,
V_88 ? L_16 : L_17 ) ;
case V_92 :
if ( V_86 [ 1 ] < 0 )
return sprintf ( V_13 , L_19 , abs ( V_86 [ 0 ] ) ,
- V_86 [ 1 ] ) ;
else
return sprintf ( V_13 , L_20 , V_86 [ 0 ] , V_86 [ 1 ] ) ;
case V_93 :
V_87 = F_60 ( ( T_3 ) V_86 [ 0 ] * 1000000000LL , V_86 [ 1 ] ) ;
V_86 [ 0 ] = ( int ) F_61 ( V_87 , 1000000000 , & V_86 [ 1 ] ) ;
return sprintf ( V_13 , L_20 , V_86 [ 0 ] , abs ( V_86 [ 1 ] ) ) ;
case V_94 :
V_87 = ( T_3 ) V_86 [ 0 ] * 1000000000LL >> V_86 [ 1 ] ;
V_86 [ 1 ] = F_62 ( V_87 , 1000000000LL ) ;
V_86 [ 0 ] = V_87 ;
return sprintf ( V_13 , L_20 , V_86 [ 0 ] , V_86 [ 1 ] ) ;
case V_95 :
{
int V_5 ;
int V_44 = 0 ;
for ( V_5 = 0 ; V_5 < V_85 ; ++ V_5 )
V_44 += snprintf ( & V_13 [ V_44 ] , V_72 - V_44 , L_21 ,
V_86 [ V_5 ] ) ;
V_44 += snprintf ( & V_13 [ V_44 ] , V_72 - V_44 , L_22 ) ;
return V_44 ;
}
default:
return 0 ;
}
}
static T_1 F_63 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
struct V_58 * V_59 = F_44 ( V_12 ) ;
int V_86 [ V_96 ] ;
int V_15 ;
int V_97 = 2 ;
if ( V_3 -> V_45 -> V_98 )
V_15 = V_3 -> V_45 -> V_98 ( V_3 , V_59 -> V_62 ,
V_96 ,
V_86 , & V_97 ,
V_59 -> V_63 ) ;
else
V_15 = V_3 -> V_45 -> V_99 ( V_3 , V_59 -> V_62 ,
& V_86 [ 0 ] , & V_86 [ 1 ] , V_59 -> V_63 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_59 ( V_13 , V_15 , V_97 , V_86 ) ;
}
int F_64 ( const char * V_100 , int V_101 ,
int * integer , int * V_102 )
{
int V_5 = 0 , V_103 = 0 ;
bool V_104 = true , V_105 = false ;
if ( V_101 == 0 ) {
* V_102 = 0 ;
return F_65 ( V_100 , 0 , integer ) ;
}
if ( V_100 [ 0 ] == '-' ) {
V_105 = true ;
V_100 ++ ;
} else if ( V_100 [ 0 ] == '+' ) {
V_100 ++ ;
}
while ( * V_100 ) {
if ( '0' <= * V_100 && * V_100 <= '9' ) {
if ( V_104 ) {
V_5 = V_5 * 10 + * V_100 - '0' ;
} else {
V_103 += V_101 * ( * V_100 - '0' ) ;
V_101 /= 10 ;
}
} else if ( * V_100 == '\n' ) {
if ( * ( V_100 + 1 ) == '\0' )
break;
else
return - V_52 ;
} else if ( * V_100 == '.' && V_104 ) {
V_104 = false ;
} else {
return - V_52 ;
}
V_100 ++ ;
}
if ( V_105 ) {
if ( V_5 )
V_5 = - V_5 ;
else
V_103 = - V_103 ;
}
* integer = V_5 ;
* V_102 = V_103 ;
return 0 ;
}
static T_1 F_66 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_7 V_44 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
struct V_58 * V_59 = F_44 ( V_12 ) ;
int V_15 , V_101 = 100000 ;
int integer , V_102 ;
if ( ! V_3 -> V_45 -> V_106 )
return - V_52 ;
if ( V_3 -> V_45 -> V_107 )
switch ( V_3 -> V_45 -> V_107 ( V_3 ,
V_59 -> V_62 , V_59 -> V_63 ) ) {
case V_89 :
V_101 = 0 ;
break;
case V_91 :
V_101 = 100000 ;
break;
case V_92 :
V_101 = 100000000 ;
break;
default:
return - V_52 ;
}
V_15 = F_64 ( V_13 , V_101 , & integer , & V_102 ) ;
if ( V_15 )
return V_15 ;
V_15 = V_3 -> V_45 -> V_106 ( V_3 , V_59 -> V_62 ,
integer , V_102 , V_59 -> V_63 ) ;
if ( V_15 )
return V_15 ;
return V_44 ;
}
static
int F_67 ( struct V_11 * V_108 ,
const char * V_109 ,
struct V_1 const * V_68 ,
T_1 (* F_68)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_69)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_7 V_44 ) ,
enum V_110 V_111 )
{
int V_15 = 0 ;
char * V_112 = NULL ;
char * V_113 ;
F_70 ( & V_108 -> V_12 ) ;
if ( V_68 -> V_114 && ( V_111 == V_115 ) ) {
if ( V_68 -> V_116 )
V_113 = F_71 ( V_117 , L_23 ,
V_118 [ V_68
-> V_119 ] ,
V_68 -> V_116 ,
V_109 ) ;
else
V_113 = F_71 ( V_117 , L_24 ,
V_118 [ V_68
-> V_119 ] ,
V_109 ) ;
} else {
if ( V_68 -> V_116 == NULL || V_111 != V_115 )
V_113 = F_72 ( V_109 , V_117 ) ;
else
V_113 = F_71 ( V_117 ,
L_24 ,
V_68 -> V_116 ,
V_109 ) ;
}
if ( V_113 == NULL )
return - V_57 ;
if ( V_68 -> V_120 ) {
switch ( V_111 ) {
case V_121 :
V_112 = F_71 ( V_117 , L_25 , V_113 ) ;
break;
case V_122 :
V_112 = F_71 ( V_117 , L_24 ,
V_123 [ V_68 -> V_124 ] ,
V_113 ) ;
break;
case V_125 :
V_112 = F_71 ( V_117 , L_26 ,
V_123 [ V_68 -> V_124 ] ,
V_126 [ V_68 -> type ] ,
V_126 [ V_68 -> type ] ,
V_113 ) ;
break;
case V_115 :
if ( ! V_68 -> V_127 ) {
F_73 ( 1 , L_27 ) ;
V_15 = - V_52 ;
goto V_128;
}
V_112 = F_71 ( V_117 ,
L_28 ,
V_123 [ V_68 -> V_124 ] ,
V_126 [ V_68 -> type ] ,
V_68 -> V_129 ,
V_126 [ V_68 -> type ] ,
V_68 -> V_119 ,
V_113 ) ;
break;
}
} else {
switch ( V_111 ) {
case V_121 :
V_112 = F_71 ( V_117 , L_25 , V_113 ) ;
break;
case V_122 :
V_112 = F_71 ( V_117 , L_24 ,
V_123 [ V_68 -> V_124 ] ,
V_113 ) ;
break;
case V_125 :
V_112 = F_71 ( V_117 , L_23 ,
V_123 [ V_68 -> V_124 ] ,
V_126 [ V_68 -> type ] ,
V_113 ) ;
break;
case V_115 :
if ( V_68 -> V_127 )
V_112 = F_71 ( V_117 , L_29 ,
V_123 [ V_68 -> V_124 ] ,
V_126 [ V_68 -> type ] ,
V_68 -> V_129 ,
V_113 ) ;
else
V_112 = F_71 ( V_117 , L_23 ,
V_123 [ V_68 -> V_124 ] ,
V_126 [ V_68 -> type ] ,
V_113 ) ;
break;
}
}
if ( V_112 == NULL ) {
V_15 = - V_57 ;
goto V_128;
}
V_108 -> V_12 . V_112 = V_112 ;
if ( F_68 ) {
V_108 -> V_12 . V_130 |= V_131 ;
V_108 -> V_132 = F_68 ;
}
if ( F_69 ) {
V_108 -> V_12 . V_130 |= V_133 ;
V_108 -> V_134 = F_69 ;
}
V_128:
F_74 ( V_113 ) ;
return V_15 ;
}
static void F_75 ( struct V_11 * V_108 )
{
F_74 ( V_108 -> V_12 . V_112 ) ;
}
int F_76 ( const char * V_109 ,
struct V_1 const * V_68 ,
T_1 (* F_68)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_69)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_7 V_44 ) ,
T_10 V_135 ,
enum V_110 V_111 ,
struct V_9 * V_10 ,
struct V_136 * V_137 )
{
int V_15 ;
struct V_58 * V_138 , * V_139 ;
V_138 = F_77 ( sizeof( * V_138 ) , V_117 ) ;
if ( V_138 == NULL )
return - V_57 ;
V_15 = F_67 ( & V_138 -> V_108 ,
V_109 , V_68 ,
F_68 , F_69 , V_111 ) ;
if ( V_15 )
goto V_140;
V_138 -> V_62 = V_68 ;
V_138 -> V_63 = V_135 ;
F_78 (t, attr_list, l)
if ( strcmp ( V_139 -> V_108 . V_12 . V_112 ,
V_138 -> V_108 . V_12 . V_112 ) == 0 ) {
if ( V_111 == V_115 )
F_31 ( V_10 , L_30 ,
V_139 -> V_108 . V_12 . V_112 ) ;
V_15 = - V_20 ;
goto V_141;
}
F_79 ( & V_138 -> V_142 , V_137 ) ;
return 0 ;
V_141:
F_75 ( & V_138 -> V_108 ) ;
V_140:
F_74 ( V_138 ) ;
return V_15 ;
}
static int F_80 ( struct V_2 * V_3 ,
struct V_1 const * V_68 ,
enum V_110 V_111 ,
const long * V_143 )
{
int V_5 , V_15 , V_144 = 0 ;
F_81 (i, infomask, sizeof(infomask)*8 ) {
if ( V_5 >= F_58 ( V_145 ) )
return - V_52 ;
V_15 = F_76 ( V_145 [ V_5 ] ,
V_68 ,
& F_63 ,
& F_66 ,
V_5 ,
V_111 ,
& V_3 -> V_10 ,
& V_3 -> V_146 ) ;
if ( ( V_15 == - V_20 ) && ( V_111 != V_115 ) )
continue;
else if ( V_15 < 0 )
return V_15 ;
V_144 ++ ;
}
return V_144 ;
}
static int F_82 ( struct V_2 * V_3 ,
struct V_1 const * V_68 )
{
int V_15 , V_144 = 0 ;
const struct V_60 * V_61 ;
if ( V_68 -> V_129 < 0 )
return 0 ;
V_15 = F_80 ( V_3 , V_68 ,
V_115 ,
& V_68 -> V_147 ) ;
if ( V_15 < 0 )
return V_15 ;
V_144 += V_15 ;
V_15 = F_80 ( V_3 , V_68 ,
V_125 ,
& V_68 -> V_148 ) ;
if ( V_15 < 0 )
return V_15 ;
V_144 += V_15 ;
V_15 = F_80 ( V_3 , V_68 ,
V_122 ,
& V_68 -> V_149 ) ;
if ( V_15 < 0 )
return V_15 ;
V_144 += V_15 ;
V_15 = F_80 ( V_3 , V_68 ,
V_121 ,
& V_68 -> V_150 ) ;
if ( V_15 < 0 )
return V_15 ;
V_144 += V_15 ;
if ( V_68 -> V_61 ) {
unsigned int V_5 = 0 ;
for ( V_61 = V_68 -> V_61 ; V_61 -> V_112 ; V_61 ++ ) {
V_15 = F_76 ( V_61 -> V_112 ,
V_68 ,
V_61 -> V_64 ?
& F_42 : NULL ,
V_61 -> V_66 ?
& F_45 : NULL ,
V_5 ,
V_61 -> V_151 ,
& V_3 -> V_10 ,
& V_3 -> V_146 ) ;
V_5 ++ ;
if ( V_15 == - V_20 && V_61 -> V_151 )
continue;
if ( V_15 )
return V_15 ;
V_144 ++ ;
}
}
return V_144 ;
}
void F_83 ( struct V_136 * V_137 )
{
struct V_58 * V_152 , * V_153 ;
F_84 (p, n, attr_list, l) {
F_74 ( V_152 -> V_108 . V_12 . V_112 ) ;
F_85 ( & V_152 -> V_142 ) ;
F_74 ( V_152 ) ;
}
}
static T_1 F_86 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_43 ( V_10 ) ;
return snprintf ( V_13 , V_72 , L_1 , V_3 -> V_112 ) ;
}
static T_1 F_87 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
const struct V_2 * V_3 = F_43 ( V_10 ) ;
const T_2 V_154 = F_10 ( V_3 ) ;
const char * V_112 ;
T_1 V_155 ;
switch ( V_154 ) {
case V_23 :
V_112 = L_31 ;
V_155 = sizeof( L_31 ) ;
break;
case V_24 :
V_112 = L_32 ;
V_155 = sizeof( L_32 ) ;
break;
case V_25 :
V_112 = L_33 ;
V_155 = sizeof( L_33 ) ;
break;
case V_26 :
V_112 = L_34 ;
V_155 = sizeof( L_34 ) ;
break;
case V_27 :
V_112 = L_35 ;
V_155 = sizeof( L_35 ) ;
break;
case V_28 :
V_112 = L_36 ;
V_155 = sizeof( L_36 ) ;
break;
case V_29 :
V_112 = L_37 ;
V_155 = sizeof( L_37 ) ;
break;
default:
F_18 () ;
}
memcpy ( V_13 , V_112 , V_155 ) ;
return V_155 ;
}
static T_1 F_88 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_7 V_44 )
{
T_2 V_154 ;
int V_15 ;
if ( F_50 ( V_13 , L_38 ) )
V_154 = V_23 ;
else if ( F_50 ( V_13 , L_39 ) )
V_154 = V_24 ;
else if ( F_50 ( V_13 , L_40 ) )
V_154 = V_25 ;
else if ( F_50 ( V_13 , L_41 ) )
V_154 = V_26 ;
else if ( F_50 ( V_13 , L_42 ) )
V_154 = V_27 ;
else if ( F_50 ( V_13 , L_43 ) )
V_154 = V_28 ;
else if ( F_50 ( V_13 , L_44 ) )
V_154 = V_29 ;
else
return - V_52 ;
V_15 = F_4 ( F_43 ( V_10 ) , V_154 ) ;
if ( V_15 )
return V_15 ;
return V_44 ;
}
static int F_89 ( struct V_2 * V_3 )
{
int V_5 , V_15 = 0 , V_144 , V_156 , V_157 = 0 ;
struct V_58 * V_152 ;
struct V_158 * * V_12 , * V_154 = NULL ;
if ( V_3 -> V_45 -> V_159 ) {
V_12 = V_3 -> V_45 -> V_159 -> V_159 ;
while ( * V_12 ++ != NULL )
V_157 ++ ;
}
V_144 = V_157 ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
const struct V_1 * V_68 =
& V_3 -> V_7 [ V_5 ] ;
if ( V_68 -> type == V_160 )
V_154 = & V_161 . V_12 ;
V_15 = F_82 ( V_3 , V_68 ) ;
if ( V_15 < 0 )
goto V_162;
V_144 += V_15 ;
}
if ( V_3 -> V_18 )
V_154 = & V_161 . V_12 ;
if ( V_3 -> V_112 )
V_144 ++ ;
if ( V_154 )
V_144 ++ ;
V_3 -> V_163 . V_159 = F_90 ( V_144 + 1 ,
sizeof( V_3 -> V_163 . V_159 [ 0 ] ) ,
V_117 ) ;
if ( V_3 -> V_163 . V_159 == NULL ) {
V_15 = - V_57 ;
goto V_162;
}
if ( V_3 -> V_45 -> V_159 )
memcpy ( V_3 -> V_163 . V_159 ,
V_3 -> V_45 -> V_159 -> V_159 ,
sizeof( V_3 -> V_163 . V_159 [ 0 ] )
* V_157 ) ;
V_156 = V_157 ;
F_78 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_163 . V_159 [ V_156 ++ ] = & V_152 -> V_108 . V_12 ;
if ( V_3 -> V_112 )
V_3 -> V_163 . V_159 [ V_156 ++ ] = & V_164 . V_12 ;
if ( V_154 )
V_3 -> V_163 . V_159 [ V_156 ++ ] = V_154 ;
V_3 -> V_165 [ V_3 -> V_166 ++ ] =
& V_3 -> V_163 ;
return 0 ;
V_162:
F_83 ( & V_3 -> V_146 ) ;
return V_15 ;
}
static void F_91 ( struct V_2 * V_3 )
{
F_83 ( & V_3 -> V_146 ) ;
F_74 ( V_3 -> V_163 . V_159 ) ;
V_3 -> V_163 . V_159 = NULL ;
}
static void F_92 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_43 ( V_9 ) ;
if ( V_3 -> V_167 & ( V_168 | V_169 ) )
F_93 ( V_3 ) ;
F_94 ( V_3 ) ;
F_91 ( V_3 ) ;
F_95 ( V_3 -> V_170 ) ;
F_96 ( & V_171 , V_3 -> V_172 ) ;
F_74 ( V_3 ) ;
}
struct V_2 * F_97 ( int V_173 )
{
struct V_2 * V_10 ;
T_7 V_174 ;
V_174 = sizeof( struct V_2 ) ;
if ( V_173 ) {
V_174 = F_98 ( V_174 , V_175 ) ;
V_174 += V_173 ;
}
V_174 += V_175 - 1 ;
V_10 = F_77 ( V_174 , V_117 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_165 = V_10 -> V_165 ;
V_10 -> V_10 . type = & V_176 ;
V_10 -> V_10 . V_177 = & V_32 ;
F_99 ( & V_10 -> V_10 ) ;
F_100 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_101 ( & V_10 -> V_19 ) ;
F_101 ( & V_10 -> V_178 ) ;
F_102 ( & V_10 -> V_146 ) ;
V_10 -> V_172 = F_103 ( & V_171 , 0 , 0 , V_117 ) ;
if ( V_10 -> V_172 < 0 ) {
F_23 ( L_45 ) ;
F_74 ( V_10 ) ;
return NULL ;
}
F_104 ( & V_10 -> V_10 , L_46 , V_10 -> V_172 ) ;
F_102 ( & V_10 -> V_179 ) ;
}
return V_10 ;
}
void F_105 ( struct V_2 * V_10 )
{
if ( V_10 )
F_106 ( & V_10 -> V_10 ) ;
}
static void F_107 ( struct V_9 * V_10 , void * V_180 )
{
F_105 ( * (struct V_2 * * ) V_180 ) ;
}
static int F_108 ( struct V_9 * V_10 , void * V_180 , void * V_181 )
{
struct V_2 * * V_182 = V_180 ;
if ( ! V_182 || ! * V_182 ) {
F_109 ( ! V_182 || ! * V_182 ) ;
return 0 ;
}
return * V_182 == V_181 ;
}
struct V_2 * F_110 ( struct V_9 * V_10 , int V_173 )
{
struct V_2 * * V_183 , * V_2 ;
V_183 = F_111 ( F_107 , sizeof( * V_183 ) ,
V_117 ) ;
if ( ! V_183 )
return NULL ;
V_2 = F_97 ( V_173 ) ;
if ( V_2 ) {
* V_183 = V_2 ;
F_112 ( V_10 , V_183 ) ;
} else {
F_113 ( V_183 ) ;
}
return V_2 ;
}
void F_114 ( struct V_9 * V_10 , struct V_2 * V_2 )
{
int V_184 ;
V_184 = F_115 ( V_10 , F_107 ,
F_108 , V_2 ) ;
F_109 ( V_184 ) ;
}
static int F_116 ( struct V_185 * V_185 , struct V_38 * V_186 )
{
struct V_2 * V_3 = F_117 ( V_185 -> V_187 ,
struct V_2 , V_188 ) ;
if ( F_118 ( V_189 , & V_3 -> V_190 ) )
return - V_20 ;
F_119 ( V_3 ) ;
V_186 -> V_42 = V_3 ;
return 0 ;
}
static int F_120 ( struct V_185 * V_185 , struct V_38 * V_186 )
{
struct V_2 * V_3 = F_117 ( V_185 -> V_187 ,
struct V_2 , V_188 ) ;
F_121 ( V_189 , & V_3 -> V_190 ) ;
F_122 ( V_3 ) ;
return 0 ;
}
static long F_123 ( struct V_38 * V_186 , unsigned int V_191 , unsigned long V_192 )
{
struct V_2 * V_3 = V_186 -> V_42 ;
int T_6 * V_193 = ( int T_6 * ) V_192 ;
int V_194 ;
if ( ! V_3 -> V_45 )
return - V_195 ;
if ( V_191 == V_196 ) {
V_194 = F_124 ( V_3 ) ;
if ( V_194 < 0 )
return V_194 ;
if ( F_125 ( V_193 , & V_194 , sizeof( V_194 ) ) )
return - V_51 ;
return 0 ;
}
return - V_52 ;
}
static int F_126 ( struct V_2 * V_3 )
{
int V_5 , V_197 ;
const struct V_1 * V_7 = V_3 -> V_7 ;
if ( ! ( V_3 -> V_167 & V_198 ) )
return 0 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 - 1 ; V_5 ++ ) {
if ( V_7 [ V_5 ] . V_8 < 0 )
continue;
for ( V_197 = V_5 + 1 ; V_197 < V_3 -> V_6 ; V_197 ++ )
if ( V_7 [ V_5 ] . V_8 == V_7 [ V_197 ] . V_8 ) {
F_31 ( & V_3 -> V_10 ,
L_47 ,
V_7 [ V_5 ] . V_8 ) ;
return - V_52 ;
}
}
return 0 ;
}
int F_127 ( struct V_2 * V_3 )
{
int V_15 ;
if ( ! V_3 -> V_10 . V_83 && V_3 -> V_10 . V_48 )
V_3 -> V_10 . V_83 = V_3 -> V_10 . V_48 -> V_83 ;
V_15 = F_126 ( V_3 ) ;
if ( V_15 < 0 )
return V_15 ;
V_3 -> V_10 . V_199 = F_128 ( F_129 ( V_34 ) , V_3 -> V_172 ) ;
V_15 = F_38 ( V_3 ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 ,
L_48 ) ;
return V_15 ;
}
V_15 = F_130 ( V_3 ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 ,
L_49 ) ;
goto V_200;
}
V_15 = F_89 ( V_3 ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 ,
L_50 ) ;
goto V_201;
}
V_15 = F_131 ( V_3 ) ;
if ( V_15 ) {
F_31 ( V_3 -> V_10 . V_48 ,
L_51 ) ;
goto V_202;
}
if ( V_3 -> V_167 & ( V_168 | V_169 ) )
F_132 ( V_3 ) ;
if ( ( V_3 -> V_167 & V_198 ) &&
V_3 -> V_203 == NULL )
V_3 -> V_203 = & V_204 ;
F_133 ( & V_3 -> V_188 , & V_205 ) ;
V_3 -> V_188 . V_206 = V_3 -> V_45 -> V_207 ;
V_3 -> V_188 . V_208 . V_48 = & V_3 -> V_10 . V_208 ;
V_15 = F_134 ( & V_3 -> V_188 , V_3 -> V_10 . V_199 , 1 ) ;
if ( V_15 < 0 )
goto V_209;
V_15 = F_135 ( & V_3 -> V_10 ) ;
if ( V_15 < 0 )
goto V_210;
return 0 ;
V_210:
F_136 ( & V_3 -> V_188 ) ;
V_209:
F_94 ( V_3 ) ;
V_202:
F_91 ( V_3 ) ;
V_201:
F_137 ( V_3 ) ;
V_200:
F_36 ( V_3 ) ;
return V_15 ;
}
void F_138 ( struct V_2 * V_3 )
{
F_139 ( & V_3 -> V_178 ) ;
F_140 ( & V_3 -> V_10 ) ;
if ( V_3 -> V_188 . V_10 )
F_136 ( & V_3 -> V_188 ) ;
F_36 ( V_3 ) ;
F_141 ( V_3 ) ;
V_3 -> V_45 = NULL ;
F_142 ( V_3 ) ;
F_143 ( V_3 ) ;
F_8 ( & V_3 -> V_178 ) ;
F_137 ( V_3 ) ;
}
static void F_144 ( struct V_9 * V_10 , void * V_180 )
{
F_138 ( * (struct V_2 * * ) V_180 ) ;
}
int F_145 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
struct V_2 * * V_183 ;
int V_15 ;
V_183 = F_111 ( F_144 , sizeof( * V_183 ) , V_117 ) ;
if ( ! V_183 )
return - V_57 ;
* V_183 = V_3 ;
V_15 = F_127 ( V_3 ) ;
if ( ! V_15 )
F_112 ( V_10 , V_183 ) ;
else
F_113 ( V_183 ) ;
return V_15 ;
}
void F_146 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_184 ;
V_184 = F_115 ( V_10 , F_144 ,
F_108 , V_3 ) ;
F_109 ( V_184 ) ;
}
int F_147 ( struct V_2 * V_3 )
{
F_139 ( & V_3 -> V_19 ) ;
if ( F_7 ( V_3 ) ) {
F_8 ( & V_3 -> V_19 ) ;
return - V_20 ;
}
return 0 ;
}
void F_148 ( struct V_2 * V_3 )
{
F_8 ( & V_3 -> V_19 ) ;
}
