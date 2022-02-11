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
static int T_2 F_4 ( void )
{
int V_14 ;
V_14 = F_5 ( & V_15 ) ;
if ( V_14 < 0 ) {
F_6 ( L_2 ) ;
goto V_16;
}
V_14 = F_7 ( & V_17 , 0 , V_18 , L_3 ) ;
if ( V_14 < 0 ) {
F_6 ( L_4 ) ;
goto V_19;
}
V_20 = F_8 ( L_3 , NULL ) ;
return 0 ;
V_19:
F_9 ( & V_15 ) ;
V_16:
return V_14 ;
}
static void T_3 F_10 ( void )
{
if ( V_17 )
F_11 ( V_17 , V_18 ) ;
F_9 ( & V_15 ) ;
F_12 ( V_20 ) ;
}
static T_1 F_13 ( struct V_21 * V_21 , char T_4 * V_22 ,
T_5 V_23 , T_6 * V_24 )
{
struct V_2 * V_3 = V_21 -> V_25 ;
char V_13 [ 20 ] ;
unsigned V_26 = 0 ;
T_1 V_27 ;
int V_14 ;
V_14 = V_3 -> V_28 -> V_29 ( V_3 ,
V_3 -> V_30 ,
0 , & V_26 ) ;
if ( V_14 )
F_14 ( V_3 -> V_10 . V_31 , L_5 , V_32 ) ;
V_27 = snprintf ( V_13 , sizeof( V_13 ) , L_6 , V_26 ) ;
return F_15 ( V_22 , V_23 , V_24 , V_13 , V_27 ) ;
}
static T_1 F_16 ( struct V_21 * V_21 ,
const char T_4 * V_22 , T_5 V_23 , T_6 * V_24 )
{
struct V_2 * V_3 = V_21 -> V_25 ;
unsigned V_33 , V_26 ;
char V_13 [ 80 ] ;
int V_14 ;
V_23 = F_17 ( T_5 , V_23 , ( sizeof( V_13 ) - 1 ) ) ;
if ( F_18 ( V_13 , V_22 , V_23 ) )
return - V_34 ;
V_13 [ V_23 ] = 0 ;
V_14 = sscanf ( V_13 , L_7 , & V_33 , & V_26 ) ;
switch ( V_14 ) {
case 1 :
V_3 -> V_30 = V_33 ;
break;
case 2 :
V_3 -> V_30 = V_33 ;
V_14 = V_3 -> V_28 -> V_29 ( V_3 , V_33 ,
V_26 , NULL ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 , L_8 ,
V_32 ) ;
return V_14 ;
}
break;
default:
return - V_35 ;
}
return V_23 ;
}
static void F_19 ( struct V_2 * V_3 )
{
F_20 ( V_3 -> V_36 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_37 * V_38 ;
if ( V_3 -> V_28 -> V_29 == NULL )
return 0 ;
if ( ! V_20 )
return 0 ;
V_3 -> V_36 =
F_8 ( F_22 ( & V_3 -> V_10 ) ,
V_20 ) ;
if ( V_3 -> V_36 == NULL ) {
F_23 ( V_3 -> V_10 . V_31 ,
L_9 ) ;
return - V_34 ;
}
V_38 = F_24 ( L_10 , 0644 ,
V_3 -> V_36 ,
V_3 , & V_39 ) ;
if ( ! V_38 ) {
F_19 ( V_3 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_19 ( struct V_2 * V_3 )
{
}
static T_1 F_25 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_41 * V_42 = F_27 ( V_12 ) ;
const struct V_43 * V_44 ;
V_44 = & V_42 -> V_45 -> V_44 [ V_42 -> V_46 ] ;
return V_44 -> V_47 ( V_3 , V_44 -> V_48 , V_42 -> V_45 , V_13 ) ;
}
static T_1 F_28 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_41 * V_42 = F_27 ( V_12 ) ;
const struct V_43 * V_44 ;
V_44 = & V_42 -> V_45 -> V_44 [ V_42 -> V_46 ] ;
return V_44 -> V_49 ( V_3 , V_44 -> V_48 ,
V_42 -> V_45 , V_13 , V_27 ) ;
}
T_1 F_29 ( struct V_2 * V_3 ,
T_7 V_50 , const struct V_1 * V_51 , char * V_13 )
{
const struct V_52 * V_53 = ( const struct V_52 * ) V_50 ;
unsigned int V_5 ;
T_5 V_27 = 0 ;
if ( ! V_53 -> V_54 )
return 0 ;
for ( V_5 = 0 ; V_5 < V_53 -> V_54 ; ++ V_5 )
V_27 += F_30 ( V_13 + V_27 , V_55 - V_27 , L_11 , V_53 -> V_56 [ V_5 ] ) ;
V_13 [ V_27 - 1 ] = '\n' ;
return V_27 ;
}
T_1 F_31 ( struct V_2 * V_3 ,
T_7 V_50 , const struct V_1 * V_51 , char * V_13 )
{
const struct V_52 * V_53 = ( const struct V_52 * ) V_50 ;
int V_5 ;
if ( ! V_53 -> V_57 )
return - V_35 ;
V_5 = V_53 -> V_57 ( V_3 , V_51 ) ;
if ( V_5 < 0 )
return V_5 ;
else if ( V_5 >= V_53 -> V_54 )
return - V_35 ;
return snprintf ( V_13 , V_55 , L_1 , V_53 -> V_56 [ V_5 ] ) ;
}
T_1 F_32 ( struct V_2 * V_3 ,
T_7 V_50 , const struct V_1 * V_51 , const char * V_13 ,
T_5 V_27 )
{
const struct V_52 * V_53 = ( const struct V_52 * ) V_50 ;
unsigned int V_5 ;
int V_14 ;
if ( ! V_53 -> V_58 )
return - V_35 ;
for ( V_5 = 0 ; V_5 < V_53 -> V_54 ; V_5 ++ ) {
if ( F_33 ( V_13 , V_53 -> V_56 [ V_5 ] ) )
break;
}
if ( V_5 == V_53 -> V_54 )
return - V_35 ;
V_14 = V_53 -> V_58 ( V_3 , V_51 , V_5 ) ;
return V_14 ? V_14 : V_27 ;
}
static int F_34 ( const struct V_9 * V_10 ,
struct V_59 * V_60 )
{
* V_60 = V_61 ;
F_35 ( V_10 , L_12 ) ;
return 0 ;
}
T_1 F_36 ( struct V_2 * V_3 , T_7 V_50 ,
const struct V_1 * V_51 , char * V_13 )
{
const struct V_59 * V_62 = ( ( V_63 * )
V_50 ) ( V_3, V_51 ) ;
if ( F_37 ( V_62 ) )
return F_38 ( V_62 ) ;
if ( ! V_62 )
V_62 = & V_61 ;
return snprintf ( V_13 , V_55 , L_13 ,
V_62 -> V_64 [ 0 ] , V_62 -> V_64 [ 1 ] , V_62 -> V_64 [ 2 ] ,
V_62 -> V_64 [ 3 ] , V_62 -> V_64 [ 4 ] , V_62 -> V_64 [ 5 ] ,
V_62 -> V_64 [ 6 ] , V_62 -> V_64 [ 7 ] , V_62 -> V_64 [ 8 ] ) ;
}
int F_39 ( const struct V_9 * V_10 ,
const char * V_65 ,
struct V_59 * V_60 )
{
if ( V_10 -> V_66 ) {
int V_67 = F_40 ( V_10 -> V_66 ,
V_65 , V_60 -> V_64 ,
F_41 ( V_61 . V_64 ) ) ;
if ( V_67 == F_41 ( V_61 . V_64 ) )
return 0 ;
if ( V_67 >= 0 )
return - V_35 ;
if ( V_67 != - V_35 )
return V_67 ;
}
return F_34 ( V_10 , V_60 ) ;
}
int F_39 ( const struct V_9 * V_10 ,
const char * V_65 ,
struct V_59 * V_60 )
{
return F_34 ( V_10 , V_60 ) ;
}
T_1 F_42 ( char * V_13 , unsigned int type , int V_68 , int * V_69 )
{
unsigned long long V_70 ;
bool V_71 = false ;
switch ( type ) {
case V_72 :
return sprintf ( V_13 , L_14 , V_69 [ 0 ] ) ;
case V_73 :
V_71 = true ;
case V_74 :
if ( V_69 [ 1 ] < 0 )
return sprintf ( V_13 , L_15 , abs ( V_69 [ 0 ] ) ,
- V_69 [ 1 ] , V_71 ? L_16 : L_17 ) ;
else
return sprintf ( V_13 , L_18 , V_69 [ 0 ] , V_69 [ 1 ] ,
V_71 ? L_16 : L_17 ) ;
case V_75 :
if ( V_69 [ 1 ] < 0 )
return sprintf ( V_13 , L_19 , abs ( V_69 [ 0 ] ) ,
- V_69 [ 1 ] ) ;
else
return sprintf ( V_13 , L_20 , V_69 [ 0 ] , V_69 [ 1 ] ) ;
case V_76 :
V_70 = F_43 ( ( V_77 ) V_69 [ 0 ] * 1000000000LL , V_69 [ 1 ] ) ;
V_69 [ 1 ] = F_44 ( V_70 , 1000000000LL ) ;
V_69 [ 0 ] = V_70 ;
return sprintf ( V_13 , L_20 , V_69 [ 0 ] , V_69 [ 1 ] ) ;
case V_78 :
V_70 = ( V_77 ) V_69 [ 0 ] * 1000000000LL >> V_69 [ 1 ] ;
V_69 [ 1 ] = F_44 ( V_70 , 1000000000LL ) ;
V_69 [ 0 ] = V_70 ;
return sprintf ( V_13 , L_20 , V_69 [ 0 ] , V_69 [ 1 ] ) ;
case V_79 :
{
int V_5 ;
int V_27 = 0 ;
for ( V_5 = 0 ; V_5 < V_68 ; ++ V_5 )
V_27 += snprintf ( & V_13 [ V_27 ] , V_55 - V_27 , L_21 ,
V_69 [ V_5 ] ) ;
V_27 += snprintf ( & V_13 [ V_27 ] , V_55 - V_27 , L_22 ) ;
return V_27 ;
}
default:
return 0 ;
}
}
static T_1 F_45 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_41 * V_42 = F_27 ( V_12 ) ;
int V_69 [ V_80 ] ;
int V_14 ;
int V_81 = 2 ;
if ( V_3 -> V_28 -> V_82 )
V_14 = V_3 -> V_28 -> V_82 ( V_3 , V_42 -> V_45 ,
V_80 ,
V_69 , & V_81 ,
V_42 -> V_46 ) ;
else
V_14 = V_3 -> V_28 -> V_83 ( V_3 , V_42 -> V_45 ,
& V_69 [ 0 ] , & V_69 [ 1 ] , V_42 -> V_46 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_42 ( V_13 , V_14 , V_81 , V_69 ) ;
}
int F_46 ( const char * V_84 , int V_85 ,
int * integer , int * V_86 )
{
int V_5 = 0 , V_87 = 0 ;
bool V_88 = true , V_89 = false ;
if ( V_85 == 0 ) {
* V_86 = 0 ;
return F_47 ( V_84 , 0 , integer ) ;
}
if ( V_84 [ 0 ] == '-' ) {
V_89 = true ;
V_84 ++ ;
} else if ( V_84 [ 0 ] == '+' ) {
V_84 ++ ;
}
while ( * V_84 ) {
if ( '0' <= * V_84 && * V_84 <= '9' ) {
if ( V_88 ) {
V_5 = V_5 * 10 + * V_84 - '0' ;
} else {
V_87 += V_85 * ( * V_84 - '0' ) ;
V_85 /= 10 ;
}
} else if ( * V_84 == '\n' ) {
if ( * ( V_84 + 1 ) == '\0' )
break;
else
return - V_35 ;
} else if ( * V_84 == '.' && V_88 ) {
V_88 = false ;
} else {
return - V_35 ;
}
V_84 ++ ;
}
if ( V_89 ) {
if ( V_5 )
V_5 = - V_5 ;
else
V_87 = - V_87 ;
}
* integer = V_5 ;
* V_86 = V_87 ;
return 0 ;
}
static T_1 F_48 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_41 * V_42 = F_27 ( V_12 ) ;
int V_14 , V_85 = 100000 ;
int integer , V_86 ;
if ( ! V_3 -> V_28 -> V_90 )
return - V_35 ;
if ( V_3 -> V_28 -> V_91 )
switch ( V_3 -> V_28 -> V_91 ( V_3 ,
V_42 -> V_45 , V_42 -> V_46 ) ) {
case V_72 :
V_85 = 0 ;
break;
case V_74 :
V_85 = 100000 ;
break;
case V_75 :
V_85 = 100000000 ;
break;
default:
return - V_35 ;
}
V_14 = F_46 ( V_13 , V_85 , & integer , & V_86 ) ;
if ( V_14 )
return V_14 ;
V_14 = V_3 -> V_28 -> V_90 ( V_3 , V_42 -> V_45 ,
integer , V_86 , V_42 -> V_46 ) ;
if ( V_14 )
return V_14 ;
return V_27 ;
}
static
int F_49 ( struct V_11 * V_92 ,
const char * V_93 ,
struct V_1 const * V_51 ,
T_1 (* F_50)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_51)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 ) ,
enum V_94 V_95 )
{
int V_14 = 0 ;
char * V_96 = NULL ;
char * V_97 ;
F_52 ( & V_92 -> V_12 ) ;
if ( V_51 -> V_98 && ( V_95 == V_99 ) ) {
if ( V_51 -> V_100 )
V_97 = F_53 ( V_101 , L_23 ,
V_102 [ V_51
-> V_103 ] ,
V_51 -> V_100 ,
V_93 ) ;
else
V_97 = F_53 ( V_101 , L_24 ,
V_102 [ V_51
-> V_103 ] ,
V_93 ) ;
} else {
if ( V_51 -> V_100 == NULL || V_95 != V_99 )
V_97 = F_54 ( V_93 , V_101 ) ;
else
V_97 = F_53 ( V_101 ,
L_24 ,
V_51 -> V_100 ,
V_93 ) ;
}
if ( V_97 == NULL )
return - V_40 ;
if ( V_51 -> V_104 ) {
switch ( V_95 ) {
case V_105 :
V_96 = F_53 ( V_101 , L_25 , V_97 ) ;
break;
case V_106 :
V_96 = F_53 ( V_101 , L_24 ,
V_107 [ V_51 -> V_108 ] ,
V_97 ) ;
break;
case V_109 :
V_96 = F_53 ( V_101 , L_26 ,
V_107 [ V_51 -> V_108 ] ,
V_110 [ V_51 -> type ] ,
V_110 [ V_51 -> type ] ,
V_97 ) ;
break;
case V_99 :
if ( ! V_51 -> V_111 ) {
F_55 ( 1 , L_27 ) ;
V_14 = - V_35 ;
goto V_112;
}
V_96 = F_53 ( V_101 ,
L_28 ,
V_107 [ V_51 -> V_108 ] ,
V_110 [ V_51 -> type ] ,
V_51 -> V_113 ,
V_110 [ V_51 -> type ] ,
V_51 -> V_103 ,
V_97 ) ;
break;
}
} else {
switch ( V_95 ) {
case V_105 :
V_96 = F_53 ( V_101 , L_25 , V_97 ) ;
break;
case V_106 :
V_96 = F_53 ( V_101 , L_24 ,
V_107 [ V_51 -> V_108 ] ,
V_97 ) ;
break;
case V_109 :
V_96 = F_53 ( V_101 , L_23 ,
V_107 [ V_51 -> V_108 ] ,
V_110 [ V_51 -> type ] ,
V_97 ) ;
break;
case V_99 :
if ( V_51 -> V_111 )
V_96 = F_53 ( V_101 , L_29 ,
V_107 [ V_51 -> V_108 ] ,
V_110 [ V_51 -> type ] ,
V_51 -> V_113 ,
V_97 ) ;
else
V_96 = F_53 ( V_101 , L_23 ,
V_107 [ V_51 -> V_108 ] ,
V_110 [ V_51 -> type ] ,
V_97 ) ;
break;
}
}
if ( V_96 == NULL ) {
V_14 = - V_40 ;
goto V_112;
}
V_92 -> V_12 . V_96 = V_96 ;
if ( F_50 ) {
V_92 -> V_12 . V_114 |= V_115 ;
V_92 -> V_116 = F_50 ;
}
if ( F_51 ) {
V_92 -> V_12 . V_114 |= V_117 ;
V_92 -> V_118 = F_51 ;
}
V_112:
F_56 ( V_97 ) ;
return V_14 ;
}
static void F_57 ( struct V_11 * V_92 )
{
F_56 ( V_92 -> V_12 . V_96 ) ;
}
int F_58 ( const char * V_93 ,
struct V_1 const * V_51 ,
T_1 (* F_50)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_51)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 ) ,
T_8 V_119 ,
enum V_94 V_95 ,
struct V_9 * V_10 ,
struct V_120 * V_121 )
{
int V_14 ;
struct V_41 * V_122 , * V_123 ;
V_122 = F_59 ( sizeof( * V_122 ) , V_101 ) ;
if ( V_122 == NULL )
return - V_40 ;
V_14 = F_49 ( & V_122 -> V_92 ,
V_93 , V_51 ,
F_50 , F_51 , V_95 ) ;
if ( V_14 )
goto V_124;
V_122 -> V_45 = V_51 ;
V_122 -> V_46 = V_119 ;
F_60 (t, attr_list, l)
if ( strcmp ( V_123 -> V_92 . V_12 . V_96 ,
V_122 -> V_92 . V_12 . V_96 ) == 0 ) {
if ( V_95 == V_99 )
F_14 ( V_10 , L_30 ,
V_123 -> V_92 . V_12 . V_96 ) ;
V_14 = - V_125 ;
goto V_126;
}
F_61 ( & V_122 -> V_127 , V_121 ) ;
return 0 ;
V_126:
F_57 ( & V_122 -> V_92 ) ;
V_124:
F_56 ( V_122 ) ;
return V_14 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_1 const * V_51 ,
enum V_94 V_95 ,
const long * V_128 )
{
int V_5 , V_14 , V_129 = 0 ;
F_63 (i, infomask, sizeof(infomask)*8 ) {
if ( V_5 >= F_41 ( V_130 ) )
return - V_35 ;
V_14 = F_58 ( V_130 [ V_5 ] ,
V_51 ,
& F_45 ,
& F_48 ,
V_5 ,
V_95 ,
& V_3 -> V_10 ,
& V_3 -> V_131 ) ;
if ( ( V_14 == - V_125 ) && ( V_95 != V_99 ) )
continue;
else if ( V_14 < 0 )
return V_14 ;
V_129 ++ ;
}
return V_129 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_1 const * V_51 )
{
int V_14 , V_129 = 0 ;
const struct V_43 * V_44 ;
if ( V_51 -> V_113 < 0 )
return 0 ;
V_14 = F_62 ( V_3 , V_51 ,
V_99 ,
& V_51 -> V_132 ) ;
if ( V_14 < 0 )
return V_14 ;
V_129 += V_14 ;
V_14 = F_62 ( V_3 , V_51 ,
V_109 ,
& V_51 -> V_133 ) ;
if ( V_14 < 0 )
return V_14 ;
V_129 += V_14 ;
V_14 = F_62 ( V_3 , V_51 ,
V_106 ,
& V_51 -> V_134 ) ;
if ( V_14 < 0 )
return V_14 ;
V_129 += V_14 ;
V_14 = F_62 ( V_3 , V_51 ,
V_105 ,
& V_51 -> V_135 ) ;
if ( V_14 < 0 )
return V_14 ;
V_129 += V_14 ;
if ( V_51 -> V_44 ) {
unsigned int V_5 = 0 ;
for ( V_44 = V_51 -> V_44 ; V_44 -> V_96 ; V_44 ++ ) {
V_14 = F_58 ( V_44 -> V_96 ,
V_51 ,
V_44 -> V_47 ?
& F_25 : NULL ,
V_44 -> V_49 ?
& F_28 : NULL ,
V_5 ,
V_44 -> V_136 ,
& V_3 -> V_10 ,
& V_3 -> V_131 ) ;
V_5 ++ ;
if ( V_14 == - V_125 && V_44 -> V_136 )
continue;
if ( V_14 )
return V_14 ;
V_129 ++ ;
}
}
return V_129 ;
}
void F_65 ( struct V_120 * V_121 )
{
struct V_41 * V_137 , * V_138 ;
F_66 (p, n, attr_list, l) {
F_56 ( V_137 -> V_92 . V_12 . V_96 ) ;
F_67 ( & V_137 -> V_127 ) ;
F_56 ( V_137 ) ;
}
}
static T_1 F_68 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
return snprintf ( V_13 , V_55 , L_1 , V_3 -> V_96 ) ;
}
static int F_69 ( struct V_2 * V_3 )
{
int V_5 , V_14 = 0 , V_129 , V_139 , V_140 = 0 ;
struct V_41 * V_137 ;
struct V_141 * * V_12 ;
if ( V_3 -> V_28 -> V_142 ) {
V_12 = V_3 -> V_28 -> V_142 -> V_142 ;
while ( * V_12 ++ != NULL )
V_140 ++ ;
}
V_129 = V_140 ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_14 = F_64 ( V_3 ,
& V_3
-> V_7 [ V_5 ] ) ;
if ( V_14 < 0 )
goto V_143;
V_129 += V_14 ;
}
if ( V_3 -> V_96 )
V_129 ++ ;
V_3 -> V_144 . V_142 = F_70 ( V_129 + 1 ,
sizeof( V_3 -> V_144 . V_142 [ 0 ] ) ,
V_101 ) ;
if ( V_3 -> V_144 . V_142 == NULL ) {
V_14 = - V_40 ;
goto V_143;
}
if ( V_3 -> V_28 -> V_142 )
memcpy ( V_3 -> V_144 . V_142 ,
V_3 -> V_28 -> V_142 -> V_142 ,
sizeof( V_3 -> V_144 . V_142 [ 0 ] )
* V_140 ) ;
V_139 = V_140 ;
F_60 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_144 . V_142 [ V_139 ++ ] = & V_137 -> V_92 . V_12 ;
if ( V_3 -> V_96 )
V_3 -> V_144 . V_142 [ V_139 ++ ] = & V_145 . V_12 ;
V_3 -> V_146 [ V_3 -> V_147 ++ ] =
& V_3 -> V_144 ;
return 0 ;
V_143:
F_65 ( & V_3 -> V_131 ) ;
return V_14 ;
}
static void F_71 ( struct V_2 * V_3 )
{
F_65 ( & V_3 -> V_131 ) ;
F_56 ( V_3 -> V_144 . V_142 ) ;
V_3 -> V_144 . V_142 = NULL ;
}
static void F_72 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_26 ( V_9 ) ;
if ( V_3 -> V_148 & ( V_149 | V_150 ) )
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
F_71 ( V_3 ) ;
F_75 ( V_3 -> V_151 ) ;
F_76 ( & V_152 , V_3 -> V_153 ) ;
F_56 ( V_3 ) ;
}
struct V_2 * F_77 ( int V_154 )
{
struct V_2 * V_10 ;
T_5 V_155 ;
V_155 = sizeof( struct V_2 ) ;
if ( V_154 ) {
V_155 = F_78 ( V_155 , V_156 ) ;
V_155 += V_154 ;
}
V_155 += V_156 - 1 ;
V_10 = F_59 ( V_155 , V_101 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_146 = V_10 -> V_146 ;
V_10 -> V_10 . type = & V_157 ;
V_10 -> V_10 . V_158 = & V_15 ;
F_79 ( & V_10 -> V_10 ) ;
F_80 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_81 ( & V_10 -> V_159 ) ;
F_81 ( & V_10 -> V_160 ) ;
F_82 ( & V_10 -> V_131 ) ;
V_10 -> V_153 = F_83 ( & V_152 , 0 , 0 , V_101 ) ;
if ( V_10 -> V_153 < 0 ) {
F_6 ( L_31 ) ;
F_56 ( V_10 ) ;
return NULL ;
}
F_84 ( & V_10 -> V_10 , L_32 , V_10 -> V_153 ) ;
F_82 ( & V_10 -> V_161 ) ;
}
return V_10 ;
}
void F_85 ( struct V_2 * V_10 )
{
if ( V_10 )
F_86 ( & V_10 -> V_10 ) ;
}
static void F_87 ( struct V_9 * V_10 , void * V_162 )
{
F_85 ( * (struct V_2 * * ) V_162 ) ;
}
static int F_88 ( struct V_9 * V_10 , void * V_162 , void * V_163 )
{
struct V_2 * * V_164 = V_162 ;
if ( ! V_164 || ! * V_164 ) {
F_89 ( ! V_164 || ! * V_164 ) ;
return 0 ;
}
return * V_164 == V_163 ;
}
struct V_2 * F_90 ( struct V_9 * V_10 , int V_154 )
{
struct V_2 * * V_165 , * V_2 ;
V_165 = F_91 ( F_87 , sizeof( * V_165 ) ,
V_101 ) ;
if ( ! V_165 )
return NULL ;
V_2 = F_77 ( V_154 ) ;
if ( V_2 ) {
* V_165 = V_2 ;
F_92 ( V_10 , V_165 ) ;
} else {
F_93 ( V_165 ) ;
}
return V_2 ;
}
void F_94 ( struct V_9 * V_10 , struct V_2 * V_2 )
{
int V_166 ;
V_166 = F_95 ( V_10 , F_87 ,
F_88 , V_2 ) ;
F_89 ( V_166 ) ;
}
static int F_96 ( struct V_167 * V_167 , struct V_21 * V_168 )
{
struct V_2 * V_3 = F_97 ( V_167 -> V_169 ,
struct V_2 , V_170 ) ;
if ( F_98 ( V_171 , & V_3 -> V_172 ) )
return - V_125 ;
F_99 ( V_3 ) ;
V_168 -> V_25 = V_3 ;
return 0 ;
}
static int F_100 ( struct V_167 * V_167 , struct V_21 * V_168 )
{
struct V_2 * V_3 = F_97 ( V_167 -> V_169 ,
struct V_2 , V_170 ) ;
F_101 ( V_171 , & V_3 -> V_172 ) ;
F_102 ( V_3 ) ;
return 0 ;
}
static long F_103 ( struct V_21 * V_168 , unsigned int V_173 , unsigned long V_174 )
{
struct V_2 * V_3 = V_168 -> V_25 ;
int T_4 * V_175 = ( int T_4 * ) V_174 ;
int V_176 ;
if ( ! V_3 -> V_28 )
return - V_177 ;
if ( V_173 == V_178 ) {
V_176 = F_104 ( V_3 ) ;
if ( V_176 < 0 )
return V_176 ;
if ( F_105 ( V_175 , & V_176 , sizeof( V_176 ) ) )
return - V_34 ;
return 0 ;
}
return - V_35 ;
}
static int F_106 ( struct V_2 * V_3 )
{
int V_5 , V_179 ;
const struct V_1 * V_7 = V_3 -> V_7 ;
if ( ! ( V_3 -> V_148 & V_180 ) )
return 0 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 - 1 ; V_5 ++ ) {
if ( V_7 [ V_5 ] . V_8 < 0 )
continue;
for ( V_179 = V_5 + 1 ; V_179 < V_3 -> V_6 ; V_179 ++ )
if ( V_7 [ V_5 ] . V_8 == V_7 [ V_179 ] . V_8 ) {
F_14 ( & V_3 -> V_10 ,
L_33 ,
V_7 [ V_5 ] . V_8 ) ;
return - V_35 ;
}
}
return 0 ;
}
int F_107 ( struct V_2 * V_3 )
{
int V_14 ;
if ( ! V_3 -> V_10 . V_66 && V_3 -> V_10 . V_31 )
V_3 -> V_10 . V_66 = V_3 -> V_10 . V_31 -> V_66 ;
V_14 = F_106 ( V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
V_3 -> V_10 . V_181 = F_108 ( F_109 ( V_17 ) , V_3 -> V_153 ) ;
V_14 = F_21 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_34 ) ;
return V_14 ;
}
V_14 = F_110 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_35 ) ;
goto V_182;
}
V_14 = F_69 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_36 ) ;
goto V_183;
}
V_14 = F_111 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_37 ) ;
goto V_184;
}
if ( V_3 -> V_148 & ( V_149 | V_150 ) )
F_112 ( V_3 ) ;
if ( ( V_3 -> V_148 & V_180 ) &&
V_3 -> V_185 == NULL )
V_3 -> V_185 = & V_186 ;
F_113 ( & V_3 -> V_170 , & V_187 ) ;
V_3 -> V_170 . V_188 = V_3 -> V_28 -> V_189 ;
V_3 -> V_170 . V_190 . V_31 = & V_3 -> V_10 . V_190 ;
V_14 = F_114 ( & V_3 -> V_170 , V_3 -> V_10 . V_181 , 1 ) ;
if ( V_14 < 0 )
goto V_191;
V_14 = F_115 ( & V_3 -> V_10 ) ;
if ( V_14 < 0 )
goto V_192;
return 0 ;
V_192:
F_116 ( & V_3 -> V_170 ) ;
V_191:
F_74 ( V_3 ) ;
V_184:
F_71 ( V_3 ) ;
V_183:
F_117 ( V_3 ) ;
V_182:
F_19 ( V_3 ) ;
return V_14 ;
}
void F_118 ( struct V_2 * V_3 )
{
F_119 ( & V_3 -> V_160 ) ;
F_120 ( & V_3 -> V_10 ) ;
if ( V_3 -> V_170 . V_10 )
F_116 ( & V_3 -> V_170 ) ;
F_19 ( V_3 ) ;
F_121 ( V_3 ) ;
V_3 -> V_28 = NULL ;
F_122 ( V_3 ) ;
F_123 ( V_3 ) ;
F_124 ( & V_3 -> V_160 ) ;
F_117 ( V_3 ) ;
}
static void F_125 ( struct V_9 * V_10 , void * V_162 )
{
F_118 ( * (struct V_2 * * ) V_162 ) ;
}
int F_126 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
struct V_2 * * V_165 ;
int V_14 ;
V_165 = F_91 ( F_125 , sizeof( * V_165 ) , V_101 ) ;
if ( ! V_165 )
return - V_40 ;
* V_165 = V_3 ;
V_14 = F_107 ( V_3 ) ;
if ( ! V_14 )
F_92 ( V_10 , V_165 ) ;
else
F_93 ( V_165 ) ;
return V_14 ;
}
void F_127 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_166 ;
V_166 = F_95 ( V_10 , F_125 ,
F_88 , V_3 ) ;
F_89 ( V_166 ) ;
}
int F_128 ( struct V_2 * V_3 )
{
F_119 ( & V_3 -> V_159 ) ;
if ( F_129 ( V_3 ) ) {
F_124 ( & V_3 -> V_159 ) ;
return - V_125 ;
}
return 0 ;
}
void F_130 ( struct V_2 * V_3 )
{
F_124 ( & V_3 -> V_159 ) ;
}
