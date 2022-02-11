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
T_1 F_34 ( char * V_13 , unsigned int type , int V_59 , int * V_60 )
{
unsigned long long V_61 ;
bool V_62 = false ;
switch ( type ) {
case V_63 :
return sprintf ( V_13 , L_12 , V_60 [ 0 ] ) ;
case V_64 :
V_62 = true ;
case V_65 :
if ( V_60 [ 1 ] < 0 )
return sprintf ( V_13 , L_13 , abs ( V_60 [ 0 ] ) ,
- V_60 [ 1 ] , V_62 ? L_14 : L_15 ) ;
else
return sprintf ( V_13 , L_16 , V_60 [ 0 ] , V_60 [ 1 ] ,
V_62 ? L_14 : L_15 ) ;
case V_66 :
if ( V_60 [ 1 ] < 0 )
return sprintf ( V_13 , L_17 , abs ( V_60 [ 0 ] ) ,
- V_60 [ 1 ] ) ;
else
return sprintf ( V_13 , L_18 , V_60 [ 0 ] , V_60 [ 1 ] ) ;
case V_67 :
V_61 = F_35 ( ( V_68 ) V_60 [ 0 ] * 1000000000LL , V_60 [ 1 ] ) ;
V_60 [ 1 ] = F_36 ( V_61 , 1000000000LL ) ;
V_60 [ 0 ] = V_61 ;
return sprintf ( V_13 , L_18 , V_60 [ 0 ] , V_60 [ 1 ] ) ;
case V_69 :
V_61 = ( V_68 ) V_60 [ 0 ] * 1000000000LL >> V_60 [ 1 ] ;
V_60 [ 1 ] = F_36 ( V_61 , 1000000000LL ) ;
V_60 [ 0 ] = V_61 ;
return sprintf ( V_13 , L_18 , V_60 [ 0 ] , V_60 [ 1 ] ) ;
case V_70 :
{
int V_5 ;
int V_27 = 0 ;
for ( V_5 = 0 ; V_5 < V_59 ; ++ V_5 )
V_27 += snprintf ( & V_13 [ V_27 ] , V_55 - V_27 , L_19 ,
V_60 [ V_5 ] ) ;
V_27 += snprintf ( & V_13 [ V_27 ] , V_55 - V_27 , L_20 ) ;
return V_27 ;
}
default:
return 0 ;
}
}
static T_1 F_37 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_41 * V_42 = F_27 ( V_12 ) ;
int V_60 [ V_71 ] ;
int V_14 ;
int V_72 = 2 ;
if ( V_3 -> V_28 -> V_73 )
V_14 = V_3 -> V_28 -> V_73 ( V_3 , V_42 -> V_45 ,
V_71 ,
V_60 , & V_72 ,
V_42 -> V_46 ) ;
else
V_14 = V_3 -> V_28 -> V_74 ( V_3 , V_42 -> V_45 ,
& V_60 [ 0 ] , & V_60 [ 1 ] , V_42 -> V_46 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_34 ( V_13 , V_14 , V_72 , V_60 ) ;
}
int F_38 ( const char * V_75 , int V_76 ,
int * integer , int * V_77 )
{
int V_5 = 0 , V_78 = 0 ;
bool V_79 = true , V_80 = false ;
if ( V_76 == 0 ) {
* V_77 = 0 ;
return F_39 ( V_75 , 0 , integer ) ;
}
if ( V_75 [ 0 ] == '-' ) {
V_80 = true ;
V_75 ++ ;
} else if ( V_75 [ 0 ] == '+' ) {
V_75 ++ ;
}
while ( * V_75 ) {
if ( '0' <= * V_75 && * V_75 <= '9' ) {
if ( V_79 ) {
V_5 = V_5 * 10 + * V_75 - '0' ;
} else {
V_78 += V_76 * ( * V_75 - '0' ) ;
V_76 /= 10 ;
}
} else if ( * V_75 == '\n' ) {
if ( * ( V_75 + 1 ) == '\0' )
break;
else
return - V_35 ;
} else if ( * V_75 == '.' && V_79 ) {
V_79 = false ;
} else {
return - V_35 ;
}
V_75 ++ ;
}
if ( V_80 ) {
if ( V_5 )
V_5 = - V_5 ;
else
V_78 = - V_78 ;
}
* integer = V_5 ;
* V_77 = V_78 ;
return 0 ;
}
static T_1 F_40 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_41 * V_42 = F_27 ( V_12 ) ;
int V_14 , V_76 = 100000 ;
int integer , V_77 ;
if ( ! V_3 -> V_28 -> V_81 )
return - V_35 ;
if ( V_3 -> V_28 -> V_82 )
switch ( V_3 -> V_28 -> V_82 ( V_3 ,
V_42 -> V_45 , V_42 -> V_46 ) ) {
case V_63 :
V_76 = 0 ;
break;
case V_65 :
V_76 = 100000 ;
break;
case V_66 :
V_76 = 100000000 ;
break;
default:
return - V_35 ;
}
V_14 = F_38 ( V_13 , V_76 , & integer , & V_77 ) ;
if ( V_14 )
return V_14 ;
V_14 = V_3 -> V_28 -> V_81 ( V_3 , V_42 -> V_45 ,
integer , V_77 , V_42 -> V_46 ) ;
if ( V_14 )
return V_14 ;
return V_27 ;
}
static
int F_41 ( struct V_11 * V_83 ,
const char * V_84 ,
struct V_1 const * V_51 ,
T_1 (* F_42)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_43)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 ) ,
enum V_85 V_86 )
{
int V_14 = 0 ;
char * V_87 = NULL ;
char * V_88 ;
F_44 ( & V_83 -> V_12 ) ;
if ( V_51 -> V_89 && ( V_86 == V_90 ) ) {
if ( V_51 -> V_91 )
V_88 = F_45 ( V_92 , L_21 ,
V_93 [ V_51
-> V_94 ] ,
V_51 -> V_91 ,
V_84 ) ;
else
V_88 = F_45 ( V_92 , L_22 ,
V_93 [ V_51
-> V_94 ] ,
V_84 ) ;
} else {
if ( V_51 -> V_91 == NULL || V_86 != V_90 )
V_88 = F_46 ( V_84 , V_92 ) ;
else
V_88 = F_45 ( V_92 ,
L_22 ,
V_51 -> V_91 ,
V_84 ) ;
}
if ( V_88 == NULL )
return - V_40 ;
if ( V_51 -> V_95 ) {
switch ( V_86 ) {
case V_96 :
V_87 = F_45 ( V_92 , L_23 , V_88 ) ;
break;
case V_97 :
V_87 = F_45 ( V_92 , L_22 ,
V_98 [ V_51 -> V_99 ] ,
V_88 ) ;
break;
case V_100 :
V_87 = F_45 ( V_92 , L_24 ,
V_98 [ V_51 -> V_99 ] ,
V_101 [ V_51 -> type ] ,
V_101 [ V_51 -> type ] ,
V_88 ) ;
break;
case V_90 :
if ( ! V_51 -> V_102 ) {
F_47 ( 1 , L_25 ) ;
V_14 = - V_35 ;
goto V_103;
}
V_87 = F_45 ( V_92 ,
L_26 ,
V_98 [ V_51 -> V_99 ] ,
V_101 [ V_51 -> type ] ,
V_51 -> V_104 ,
V_101 [ V_51 -> type ] ,
V_51 -> V_94 ,
V_88 ) ;
break;
}
} else {
switch ( V_86 ) {
case V_96 :
V_87 = F_45 ( V_92 , L_23 , V_88 ) ;
break;
case V_97 :
V_87 = F_45 ( V_92 , L_22 ,
V_98 [ V_51 -> V_99 ] ,
V_88 ) ;
break;
case V_100 :
V_87 = F_45 ( V_92 , L_21 ,
V_98 [ V_51 -> V_99 ] ,
V_101 [ V_51 -> type ] ,
V_88 ) ;
break;
case V_90 :
if ( V_51 -> V_102 )
V_87 = F_45 ( V_92 , L_27 ,
V_98 [ V_51 -> V_99 ] ,
V_101 [ V_51 -> type ] ,
V_51 -> V_104 ,
V_88 ) ;
else
V_87 = F_45 ( V_92 , L_21 ,
V_98 [ V_51 -> V_99 ] ,
V_101 [ V_51 -> type ] ,
V_88 ) ;
break;
}
}
if ( V_87 == NULL ) {
V_14 = - V_40 ;
goto V_103;
}
V_83 -> V_12 . V_87 = V_87 ;
if ( F_42 ) {
V_83 -> V_12 . V_105 |= V_106 ;
V_83 -> V_107 = F_42 ;
}
if ( F_43 ) {
V_83 -> V_12 . V_105 |= V_108 ;
V_83 -> V_109 = F_43 ;
}
V_103:
F_48 ( V_88 ) ;
return V_14 ;
}
static void F_49 ( struct V_11 * V_83 )
{
F_48 ( V_83 -> V_12 . V_87 ) ;
}
int F_50 ( const char * V_84 ,
struct V_1 const * V_51 ,
T_1 (* F_42)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_43)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 ) ,
T_8 V_110 ,
enum V_85 V_86 ,
struct V_9 * V_10 ,
struct V_111 * V_112 )
{
int V_14 ;
struct V_41 * V_113 , * V_114 ;
V_113 = F_51 ( sizeof( * V_113 ) , V_92 ) ;
if ( V_113 == NULL )
return - V_40 ;
V_14 = F_41 ( & V_113 -> V_83 ,
V_84 , V_51 ,
F_42 , F_43 , V_86 ) ;
if ( V_14 )
goto V_115;
V_113 -> V_45 = V_51 ;
V_113 -> V_46 = V_110 ;
F_52 (t, attr_list, l)
if ( strcmp ( V_114 -> V_83 . V_12 . V_87 ,
V_113 -> V_83 . V_12 . V_87 ) == 0 ) {
if ( V_86 == V_90 )
F_14 ( V_10 , L_28 ,
V_114 -> V_83 . V_12 . V_87 ) ;
V_14 = - V_116 ;
goto V_117;
}
F_53 ( & V_113 -> V_118 , V_112 ) ;
return 0 ;
V_117:
F_49 ( & V_113 -> V_83 ) ;
V_115:
F_48 ( V_113 ) ;
return V_14 ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_1 const * V_51 ,
enum V_85 V_86 ,
const long * V_119 )
{
int V_5 , V_14 , V_120 = 0 ;
F_55 (i, infomask, sizeof(infomask)*8 ) {
if ( V_5 >= F_56 ( V_121 ) )
return - V_35 ;
V_14 = F_50 ( V_121 [ V_5 ] ,
V_51 ,
& F_37 ,
& F_40 ,
V_5 ,
V_86 ,
& V_3 -> V_10 ,
& V_3 -> V_122 ) ;
if ( ( V_14 == - V_116 ) && ( V_86 != V_90 ) )
continue;
else if ( V_14 < 0 )
return V_14 ;
V_120 ++ ;
}
return V_120 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_1 const * V_51 )
{
int V_14 , V_120 = 0 ;
const struct V_43 * V_44 ;
if ( V_51 -> V_104 < 0 )
return 0 ;
V_14 = F_54 ( V_3 , V_51 ,
V_90 ,
& V_51 -> V_123 ) ;
if ( V_14 < 0 )
return V_14 ;
V_120 += V_14 ;
V_14 = F_54 ( V_3 , V_51 ,
V_100 ,
& V_51 -> V_124 ) ;
if ( V_14 < 0 )
return V_14 ;
V_120 += V_14 ;
V_14 = F_54 ( V_3 , V_51 ,
V_97 ,
& V_51 -> V_125 ) ;
if ( V_14 < 0 )
return V_14 ;
V_120 += V_14 ;
V_14 = F_54 ( V_3 , V_51 ,
V_96 ,
& V_51 -> V_126 ) ;
if ( V_14 < 0 )
return V_14 ;
V_120 += V_14 ;
if ( V_51 -> V_44 ) {
unsigned int V_5 = 0 ;
for ( V_44 = V_51 -> V_44 ; V_44 -> V_87 ; V_44 ++ ) {
V_14 = F_50 ( V_44 -> V_87 ,
V_51 ,
V_44 -> V_47 ?
& F_25 : NULL ,
V_44 -> V_49 ?
& F_28 : NULL ,
V_5 ,
V_44 -> V_127 ,
& V_3 -> V_10 ,
& V_3 -> V_122 ) ;
V_5 ++ ;
if ( V_14 == - V_116 && V_44 -> V_127 )
continue;
if ( V_14 )
return V_14 ;
V_120 ++ ;
}
}
return V_120 ;
}
void F_58 ( struct V_111 * V_112 )
{
struct V_41 * V_128 , * V_129 ;
F_59 (p, n, attr_list, l) {
F_48 ( V_128 -> V_83 . V_12 . V_87 ) ;
F_60 ( & V_128 -> V_118 ) ;
F_48 ( V_128 ) ;
}
}
static T_1 F_61 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
return snprintf ( V_13 , V_55 , L_1 , V_3 -> V_87 ) ;
}
static int F_62 ( struct V_2 * V_3 )
{
int V_5 , V_14 = 0 , V_120 , V_130 , V_131 = 0 ;
struct V_41 * V_128 ;
struct V_132 * * V_12 ;
if ( V_3 -> V_28 -> V_133 ) {
V_12 = V_3 -> V_28 -> V_133 -> V_133 ;
while ( * V_12 ++ != NULL )
V_131 ++ ;
}
V_120 = V_131 ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_14 = F_57 ( V_3 ,
& V_3
-> V_7 [ V_5 ] ) ;
if ( V_14 < 0 )
goto V_134;
V_120 += V_14 ;
}
if ( V_3 -> V_87 )
V_120 ++ ;
V_3 -> V_135 . V_133 = F_63 ( V_120 + 1 ,
sizeof( V_3 -> V_135 . V_133 [ 0 ] ) ,
V_92 ) ;
if ( V_3 -> V_135 . V_133 == NULL ) {
V_14 = - V_40 ;
goto V_134;
}
if ( V_3 -> V_28 -> V_133 )
memcpy ( V_3 -> V_135 . V_133 ,
V_3 -> V_28 -> V_133 -> V_133 ,
sizeof( V_3 -> V_135 . V_133 [ 0 ] )
* V_131 ) ;
V_130 = V_131 ;
F_52 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_135 . V_133 [ V_130 ++ ] = & V_128 -> V_83 . V_12 ;
if ( V_3 -> V_87 )
V_3 -> V_135 . V_133 [ V_130 ++ ] = & V_136 . V_12 ;
V_3 -> V_137 [ V_3 -> V_138 ++ ] =
& V_3 -> V_135 ;
return 0 ;
V_134:
F_58 ( & V_3 -> V_122 ) ;
return V_14 ;
}
static void F_64 ( struct V_2 * V_3 )
{
F_58 ( & V_3 -> V_122 ) ;
F_48 ( V_3 -> V_135 . V_133 ) ;
V_3 -> V_135 . V_133 = NULL ;
}
static void F_65 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_26 ( V_9 ) ;
if ( V_3 -> V_139 & ( V_140 | V_141 ) )
F_66 ( V_3 ) ;
F_67 ( V_3 ) ;
F_64 ( V_3 ) ;
F_68 ( V_3 -> V_142 ) ;
F_69 ( & V_143 , V_3 -> V_144 ) ;
F_48 ( V_3 ) ;
}
struct V_2 * F_70 ( int V_145 )
{
struct V_2 * V_10 ;
T_5 V_146 ;
V_146 = sizeof( struct V_2 ) ;
if ( V_145 ) {
V_146 = F_71 ( V_146 , V_147 ) ;
V_146 += V_145 ;
}
V_146 += V_147 - 1 ;
V_10 = F_51 ( V_146 , V_92 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_137 = V_10 -> V_137 ;
V_10 -> V_10 . type = & V_148 ;
V_10 -> V_10 . V_149 = & V_15 ;
F_72 ( & V_10 -> V_10 ) ;
F_73 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_74 ( & V_10 -> V_150 ) ;
F_74 ( & V_10 -> V_151 ) ;
F_75 ( & V_10 -> V_122 ) ;
V_10 -> V_144 = F_76 ( & V_143 , 0 , 0 , V_92 ) ;
if ( V_10 -> V_144 < 0 ) {
F_6 ( L_29 ) ;
F_48 ( V_10 ) ;
return NULL ;
}
F_77 ( & V_10 -> V_10 , L_30 , V_10 -> V_144 ) ;
F_75 ( & V_10 -> V_152 ) ;
}
return V_10 ;
}
void F_78 ( struct V_2 * V_10 )
{
if ( V_10 )
F_79 ( & V_10 -> V_10 ) ;
}
static void F_80 ( struct V_9 * V_10 , void * V_153 )
{
F_78 ( * (struct V_2 * * ) V_153 ) ;
}
static int F_81 ( struct V_9 * V_10 , void * V_153 , void * V_154 )
{
struct V_2 * * V_155 = V_153 ;
if ( ! V_155 || ! * V_155 ) {
F_82 ( ! V_155 || ! * V_155 ) ;
return 0 ;
}
return * V_155 == V_154 ;
}
struct V_2 * F_83 ( struct V_9 * V_10 , int V_145 )
{
struct V_2 * * V_156 , * V_2 ;
V_156 = F_84 ( F_80 , sizeof( * V_156 ) ,
V_92 ) ;
if ( ! V_156 )
return NULL ;
V_2 = F_70 ( V_145 ) ;
if ( V_2 ) {
* V_156 = V_2 ;
F_85 ( V_10 , V_156 ) ;
} else {
F_86 ( V_156 ) ;
}
return V_2 ;
}
void F_87 ( struct V_9 * V_10 , struct V_2 * V_2 )
{
int V_157 ;
V_157 = F_88 ( V_10 , F_80 ,
F_81 , V_2 ) ;
F_82 ( V_157 ) ;
}
static int F_89 ( struct V_158 * V_158 , struct V_21 * V_159 )
{
struct V_2 * V_3 = F_90 ( V_158 -> V_160 ,
struct V_2 , V_161 ) ;
if ( F_91 ( V_162 , & V_3 -> V_163 ) )
return - V_116 ;
F_92 ( V_3 ) ;
V_159 -> V_25 = V_3 ;
return 0 ;
}
static int F_93 ( struct V_158 * V_158 , struct V_21 * V_159 )
{
struct V_2 * V_3 = F_90 ( V_158 -> V_160 ,
struct V_2 , V_161 ) ;
F_94 ( V_162 , & V_3 -> V_163 ) ;
F_95 ( V_3 ) ;
return 0 ;
}
static long F_96 ( struct V_21 * V_159 , unsigned int V_164 , unsigned long V_165 )
{
struct V_2 * V_3 = V_159 -> V_25 ;
int T_4 * V_166 = ( int T_4 * ) V_165 ;
int V_167 ;
if ( ! V_3 -> V_28 )
return - V_168 ;
if ( V_164 == V_169 ) {
V_167 = F_97 ( V_3 ) ;
if ( V_167 < 0 )
return V_167 ;
if ( F_98 ( V_166 , & V_167 , sizeof( V_167 ) ) )
return - V_34 ;
return 0 ;
}
return - V_35 ;
}
static int F_99 ( struct V_2 * V_3 )
{
int V_5 , V_170 ;
const struct V_1 * V_7 = V_3 -> V_7 ;
if ( ! ( V_3 -> V_139 & V_171 ) )
return 0 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 - 1 ; V_5 ++ ) {
if ( V_7 [ V_5 ] . V_8 < 0 )
continue;
for ( V_170 = V_5 + 1 ; V_170 < V_3 -> V_6 ; V_170 ++ )
if ( V_7 [ V_5 ] . V_8 == V_7 [ V_170 ] . V_8 ) {
F_14 ( & V_3 -> V_10 ,
L_31 ,
V_7 [ V_5 ] . V_8 ) ;
return - V_35 ;
}
}
return 0 ;
}
int F_100 ( struct V_2 * V_3 )
{
int V_14 ;
if ( ! V_3 -> V_10 . V_172 && V_3 -> V_10 . V_31 )
V_3 -> V_10 . V_172 = V_3 -> V_10 . V_31 -> V_172 ;
V_14 = F_99 ( V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
V_3 -> V_10 . V_173 = F_101 ( F_102 ( V_17 ) , V_3 -> V_144 ) ;
V_14 = F_21 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_32 ) ;
return V_14 ;
}
V_14 = F_103 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_33 ) ;
goto V_174;
}
V_14 = F_62 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_34 ) ;
goto V_175;
}
V_14 = F_104 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_35 ) ;
goto V_176;
}
if ( V_3 -> V_139 & ( V_140 | V_141 ) )
F_105 ( V_3 ) ;
if ( ( V_3 -> V_139 & V_171 ) &&
V_3 -> V_177 == NULL )
V_3 -> V_177 = & V_178 ;
F_106 ( & V_3 -> V_161 , & V_179 ) ;
V_3 -> V_161 . V_180 = V_3 -> V_28 -> V_181 ;
V_3 -> V_161 . V_182 . V_31 = & V_3 -> V_10 . V_182 ;
V_14 = F_107 ( & V_3 -> V_161 , V_3 -> V_10 . V_173 , 1 ) ;
if ( V_14 < 0 )
goto V_183;
V_14 = F_108 ( & V_3 -> V_10 ) ;
if ( V_14 < 0 )
goto V_184;
return 0 ;
V_184:
F_109 ( & V_3 -> V_161 ) ;
V_183:
F_67 ( V_3 ) ;
V_176:
F_64 ( V_3 ) ;
V_175:
F_110 ( V_3 ) ;
V_174:
F_19 ( V_3 ) ;
return V_14 ;
}
void F_111 ( struct V_2 * V_3 )
{
F_112 ( & V_3 -> V_151 ) ;
F_113 ( & V_3 -> V_10 ) ;
if ( V_3 -> V_161 . V_10 )
F_109 ( & V_3 -> V_161 ) ;
F_19 ( V_3 ) ;
F_114 ( V_3 ) ;
V_3 -> V_28 = NULL ;
F_115 ( V_3 ) ;
F_116 ( V_3 ) ;
F_117 ( & V_3 -> V_151 ) ;
F_110 ( V_3 ) ;
}
static void F_118 ( struct V_9 * V_10 , void * V_153 )
{
F_111 ( * (struct V_2 * * ) V_153 ) ;
}
int F_119 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
struct V_2 * * V_156 ;
int V_14 ;
V_156 = F_84 ( F_118 , sizeof( * V_156 ) , V_92 ) ;
if ( ! V_156 )
return - V_40 ;
* V_156 = V_3 ;
V_14 = F_100 ( V_3 ) ;
if ( ! V_14 )
F_85 ( V_10 , V_156 ) ;
else
F_86 ( V_156 ) ;
return V_14 ;
}
void F_120 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_157 ;
V_157 = F_88 ( V_10 , F_118 ,
F_81 , V_3 ) ;
F_82 ( V_157 ) ;
}
