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
return sprintf ( V_13 , L_1 , V_53 -> V_56 [ V_5 ] ) ;
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
T_1 F_34 ( char * V_13 , unsigned int type , int V_26 , int V_59 )
{
unsigned long long V_60 ;
bool V_61 = false ;
switch ( type ) {
case V_62 :
return sprintf ( V_13 , L_12 , V_26 ) ;
case V_63 :
V_61 = true ;
case V_64 :
if ( V_59 < 0 )
return sprintf ( V_13 , L_13 , abs ( V_26 ) , - V_59 ,
V_61 ? L_14 : L_15 ) ;
else
return sprintf ( V_13 , L_16 , V_26 , V_59 ,
V_61 ? L_14 : L_15 ) ;
case V_65 :
if ( V_59 < 0 )
return sprintf ( V_13 , L_17 , abs ( V_26 ) , - V_59 ) ;
else
return sprintf ( V_13 , L_18 , V_26 , V_59 ) ;
case V_66 :
V_60 = F_35 ( ( V_67 ) V_26 * 1000000000LL , V_59 ) ;
V_59 = F_36 ( V_60 , 1000000000LL ) ;
V_26 = V_60 ;
return sprintf ( V_13 , L_18 , V_26 , V_59 ) ;
case V_68 :
V_60 = ( V_67 ) V_26 * 1000000000LL >> V_59 ;
V_59 = F_36 ( V_60 , 1000000000LL ) ;
V_26 = V_60 ;
return sprintf ( V_13 , L_18 , V_26 , V_59 ) ;
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
int V_26 , V_59 ;
int V_14 = V_3 -> V_28 -> V_69 ( V_3 , V_42 -> V_45 ,
& V_26 , & V_59 , V_42 -> V_46 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_34 ( V_13 , V_14 , V_26 , V_59 ) ;
}
int F_38 ( const char * V_70 , int V_71 ,
int * integer , int * V_72 )
{
int V_5 = 0 , V_73 = 0 ;
bool V_74 = true , V_75 = false ;
if ( V_70 [ 0 ] == '-' ) {
V_75 = true ;
V_70 ++ ;
} else if ( V_70 [ 0 ] == '+' ) {
V_70 ++ ;
}
while ( * V_70 ) {
if ( '0' <= * V_70 && * V_70 <= '9' ) {
if ( V_74 ) {
V_5 = V_5 * 10 + * V_70 - '0' ;
} else {
V_73 += V_71 * ( * V_70 - '0' ) ;
V_71 /= 10 ;
}
} else if ( * V_70 == '\n' ) {
if ( * ( V_70 + 1 ) == '\0' )
break;
else
return - V_35 ;
} else if ( * V_70 == '.' && V_74 ) {
V_74 = false ;
} else {
return - V_35 ;
}
V_70 ++ ;
}
if ( V_75 ) {
if ( V_5 )
V_5 = - V_5 ;
else
V_73 = - V_73 ;
}
* integer = V_5 ;
* V_72 = V_73 ;
return 0 ;
}
static T_1 F_39 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
struct V_41 * V_42 = F_27 ( V_12 ) ;
int V_14 , V_71 = 100000 ;
int integer , V_72 ;
if ( ! V_3 -> V_28 -> V_76 )
return - V_35 ;
if ( V_3 -> V_28 -> V_77 )
switch ( V_3 -> V_28 -> V_77 ( V_3 ,
V_42 -> V_45 , V_42 -> V_46 ) ) {
case V_64 :
V_71 = 100000 ;
break;
case V_65 :
V_71 = 100000000 ;
break;
default:
return - V_35 ;
}
V_14 = F_38 ( V_13 , V_71 , & integer , & V_72 ) ;
if ( V_14 )
return V_14 ;
V_14 = V_3 -> V_28 -> V_76 ( V_3 , V_42 -> V_45 ,
integer , V_72 , V_42 -> V_46 ) ;
if ( V_14 )
return V_14 ;
return V_27 ;
}
static
int F_40 ( struct V_11 * V_78 ,
const char * V_79 ,
struct V_1 const * V_51 ,
T_1 (* F_41)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_42)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 ) ,
enum V_80 V_81 )
{
int V_14 = 0 ;
char * V_82 = NULL ;
char * V_83 ;
F_43 ( & V_78 -> V_12 ) ;
if ( V_51 -> V_84 && ( V_81 == V_85 ) ) {
if ( V_51 -> V_86 )
V_83 = F_44 ( V_87 , L_19 ,
V_88 [ V_51
-> V_89 ] ,
V_51 -> V_86 ,
V_79 ) ;
else
V_83 = F_44 ( V_87 , L_20 ,
V_88 [ V_51
-> V_89 ] ,
V_79 ) ;
} else {
if ( V_51 -> V_86 == NULL || V_81 != V_85 )
V_83 = F_45 ( V_79 , V_87 ) ;
else
V_83 = F_44 ( V_87 ,
L_20 ,
V_51 -> V_86 ,
V_79 ) ;
}
if ( V_83 == NULL )
return - V_40 ;
if ( V_51 -> V_90 ) {
switch ( V_81 ) {
case V_91 :
V_82 = F_44 ( V_87 , L_21 , V_83 ) ;
break;
case V_92 :
V_82 = F_44 ( V_87 , L_20 ,
V_93 [ V_51 -> V_94 ] ,
V_83 ) ;
break;
case V_95 :
V_82 = F_44 ( V_87 , L_22 ,
V_93 [ V_51 -> V_94 ] ,
V_96 [ V_51 -> type ] ,
V_96 [ V_51 -> type ] ,
V_83 ) ;
break;
case V_85 :
if ( ! V_51 -> V_97 ) {
F_46 ( L_23 ) ;
V_14 = - V_35 ;
goto V_98;
}
V_82 = F_44 ( V_87 ,
L_24 ,
V_93 [ V_51 -> V_94 ] ,
V_96 [ V_51 -> type ] ,
V_51 -> V_99 ,
V_96 [ V_51 -> type ] ,
V_51 -> V_89 ,
V_83 ) ;
break;
}
} else {
switch ( V_81 ) {
case V_91 :
V_82 = F_44 ( V_87 , L_21 , V_83 ) ;
break;
case V_92 :
V_82 = F_44 ( V_87 , L_20 ,
V_93 [ V_51 -> V_94 ] ,
V_83 ) ;
break;
case V_95 :
V_82 = F_44 ( V_87 , L_19 ,
V_93 [ V_51 -> V_94 ] ,
V_96 [ V_51 -> type ] ,
V_83 ) ;
break;
case V_85 :
if ( V_51 -> V_97 )
V_82 = F_44 ( V_87 , L_25 ,
V_93 [ V_51 -> V_94 ] ,
V_96 [ V_51 -> type ] ,
V_51 -> V_99 ,
V_83 ) ;
else
V_82 = F_44 ( V_87 , L_19 ,
V_93 [ V_51 -> V_94 ] ,
V_96 [ V_51 -> type ] ,
V_83 ) ;
break;
}
}
if ( V_82 == NULL ) {
V_14 = - V_40 ;
goto V_98;
}
V_78 -> V_12 . V_82 = V_82 ;
if ( F_41 ) {
V_78 -> V_12 . V_100 |= V_101 ;
V_78 -> V_102 = F_41 ;
}
if ( F_42 ) {
V_78 -> V_12 . V_100 |= V_103 ;
V_78 -> V_104 = F_42 ;
}
V_98:
F_47 ( V_83 ) ;
return V_14 ;
}
static void F_48 ( struct V_11 * V_78 )
{
F_47 ( V_78 -> V_12 . V_82 ) ;
}
int F_49 ( const char * V_79 ,
struct V_1 const * V_51 ,
T_1 (* F_41)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 ) ,
T_1 (* F_42)( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_5 V_27 ) ,
T_8 V_105 ,
enum V_80 V_81 ,
struct V_9 * V_10 ,
struct V_106 * V_107 )
{
int V_14 ;
struct V_41 * V_108 , * V_109 ;
V_108 = F_50 ( sizeof( * V_108 ) , V_87 ) ;
if ( V_108 == NULL )
return - V_40 ;
V_14 = F_40 ( & V_108 -> V_78 ,
V_79 , V_51 ,
F_41 , F_42 , V_81 ) ;
if ( V_14 )
goto V_110;
V_108 -> V_45 = V_51 ;
V_108 -> V_46 = V_105 ;
F_51 (t, attr_list, l)
if ( strcmp ( V_109 -> V_78 . V_12 . V_82 ,
V_108 -> V_78 . V_12 . V_82 ) == 0 ) {
if ( V_81 == V_85 )
F_14 ( V_10 , L_26 ,
V_109 -> V_78 . V_12 . V_82 ) ;
V_14 = - V_111 ;
goto V_112;
}
F_52 ( & V_108 -> V_113 , V_107 ) ;
return 0 ;
V_112:
F_48 ( & V_108 -> V_78 ) ;
V_110:
F_47 ( V_108 ) ;
return V_14 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_1 const * V_51 ,
enum V_80 V_81 ,
const long * V_114 )
{
int V_5 , V_14 , V_115 = 0 ;
F_54 (i, infomask, sizeof(infomask)*8 ) {
V_14 = F_49 ( V_116 [ V_5 ] ,
V_51 ,
& F_37 ,
& F_39 ,
V_5 ,
V_81 ,
& V_3 -> V_10 ,
& V_3 -> V_117 ) ;
if ( ( V_14 == - V_111 ) && ( V_81 != V_85 ) )
continue;
else if ( V_14 < 0 )
return V_14 ;
V_115 ++ ;
}
return V_115 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_1 const * V_51 )
{
int V_14 , V_115 = 0 ;
const struct V_43 * V_44 ;
if ( V_51 -> V_99 < 0 )
return 0 ;
V_14 = F_53 ( V_3 , V_51 ,
V_85 ,
& V_51 -> V_118 ) ;
if ( V_14 < 0 )
return V_14 ;
V_115 += V_14 ;
V_14 = F_53 ( V_3 , V_51 ,
V_95 ,
& V_51 -> V_119 ) ;
if ( V_14 < 0 )
return V_14 ;
V_115 += V_14 ;
V_14 = F_53 ( V_3 , V_51 ,
V_92 ,
& V_51 -> V_120 ) ;
if ( V_14 < 0 )
return V_14 ;
V_115 += V_14 ;
V_14 = F_53 ( V_3 , V_51 ,
V_91 ,
& V_51 -> V_121 ) ;
if ( V_14 < 0 )
return V_14 ;
V_115 += V_14 ;
if ( V_51 -> V_44 ) {
unsigned int V_5 = 0 ;
for ( V_44 = V_51 -> V_44 ; V_44 -> V_82 ; V_44 ++ ) {
V_14 = F_49 ( V_44 -> V_82 ,
V_51 ,
V_44 -> V_47 ?
& F_25 : NULL ,
V_44 -> V_49 ?
& F_28 : NULL ,
V_5 ,
V_44 -> V_122 ,
& V_3 -> V_10 ,
& V_3 -> V_117 ) ;
V_5 ++ ;
if ( V_14 == - V_111 && V_44 -> V_122 )
continue;
if ( V_14 )
return V_14 ;
V_115 ++ ;
}
}
return V_115 ;
}
void F_56 ( struct V_106 * V_107 )
{
struct V_41 * V_123 , * V_124 ;
F_57 (p, n, attr_list, l) {
F_47 ( V_123 -> V_78 . V_12 . V_82 ) ;
F_47 ( V_123 ) ;
}
}
static T_1 F_58 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_2 * V_3 = F_26 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_3 -> V_82 ) ;
}
static int F_59 ( struct V_2 * V_3 )
{
int V_5 , V_14 = 0 , V_115 , V_125 , V_126 = 0 ;
struct V_41 * V_123 ;
struct V_127 * * V_12 ;
if ( V_3 -> V_28 -> V_128 ) {
V_12 = V_3 -> V_28 -> V_128 -> V_128 ;
while ( * V_12 ++ != NULL )
V_126 ++ ;
}
V_115 = V_126 ;
if ( V_3 -> V_7 )
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
V_14 = F_55 ( V_3 ,
& V_3
-> V_7 [ V_5 ] ) ;
if ( V_14 < 0 )
goto V_129;
V_115 += V_14 ;
}
if ( V_3 -> V_82 )
V_115 ++ ;
V_3 -> V_130 . V_128 = F_60 ( V_115 + 1 ,
sizeof( V_3 -> V_130 . V_128 [ 0 ] ) ,
V_87 ) ;
if ( V_3 -> V_130 . V_128 == NULL ) {
V_14 = - V_40 ;
goto V_129;
}
if ( V_3 -> V_28 -> V_128 )
memcpy ( V_3 -> V_130 . V_128 ,
V_3 -> V_28 -> V_128 -> V_128 ,
sizeof( V_3 -> V_130 . V_128 [ 0 ] )
* V_126 ) ;
V_125 = V_126 ;
F_51 (p, &indio_dev->channel_attr_list, l)
V_3 -> V_130 . V_128 [ V_125 ++ ] = & V_123 -> V_78 . V_12 ;
if ( V_3 -> V_82 )
V_3 -> V_130 . V_128 [ V_125 ++ ] = & V_131 . V_12 ;
V_3 -> V_132 [ V_3 -> V_133 ++ ] =
& V_3 -> V_130 ;
return 0 ;
V_129:
F_56 ( & V_3 -> V_117 ) ;
return V_14 ;
}
static void F_61 ( struct V_2 * V_3 )
{
F_56 ( & V_3 -> V_117 ) ;
F_47 ( V_3 -> V_130 . V_128 ) ;
}
static void F_62 ( struct V_9 * V_9 )
{
struct V_2 * V_3 = F_26 ( V_9 ) ;
if ( V_3 -> V_134 & V_135 )
F_63 ( V_3 ) ;
F_64 ( V_3 ) ;
F_61 ( V_3 ) ;
F_65 ( V_3 -> V_136 ) ;
F_66 ( & V_137 , V_3 -> V_138 ) ;
F_47 ( V_3 ) ;
}
struct V_2 * F_67 ( int V_139 )
{
struct V_2 * V_10 ;
T_5 V_140 ;
V_140 = sizeof( struct V_2 ) ;
if ( V_139 ) {
V_140 = F_68 ( V_140 , V_141 ) ;
V_140 += V_139 ;
}
V_140 += V_141 - 1 ;
V_10 = F_50 ( V_140 , V_87 ) ;
if ( V_10 ) {
V_10 -> V_10 . V_132 = V_10 -> V_132 ;
V_10 -> V_10 . type = & V_142 ;
V_10 -> V_10 . V_143 = & V_15 ;
F_69 ( & V_10 -> V_10 ) ;
F_70 ( & V_10 -> V_10 , ( void * ) V_10 ) ;
F_71 ( & V_10 -> V_144 ) ;
F_71 ( & V_10 -> V_145 ) ;
F_72 ( & V_10 -> V_117 ) ;
V_10 -> V_138 = F_73 ( & V_137 , 0 , 0 , V_87 ) ;
if ( V_10 -> V_138 < 0 ) {
F_6 ( L_27 ) ;
F_47 ( V_10 ) ;
return NULL ;
}
F_74 ( & V_10 -> V_10 , L_28 , V_10 -> V_138 ) ;
F_72 ( & V_10 -> V_146 ) ;
}
return V_10 ;
}
void F_75 ( struct V_2 * V_10 )
{
if ( V_10 )
F_76 ( & V_10 -> V_10 ) ;
}
static void F_77 ( struct V_9 * V_10 , void * V_147 )
{
F_75 ( * (struct V_2 * * ) V_147 ) ;
}
static int F_78 ( struct V_9 * V_10 , void * V_147 , void * V_148 )
{
struct V_2 * * V_149 = V_147 ;
if ( ! V_149 || ! * V_149 ) {
F_46 ( ! V_149 || ! * V_149 ) ;
return 0 ;
}
return * V_149 == V_148 ;
}
struct V_2 * F_79 ( struct V_9 * V_10 , int V_139 )
{
struct V_2 * * V_150 , * V_2 ;
V_150 = F_80 ( F_77 , sizeof( * V_150 ) ,
V_87 ) ;
if ( ! V_150 )
return NULL ;
V_2 = F_67 ( V_139 ) ;
if ( V_2 ) {
* V_150 = V_2 ;
F_81 ( V_10 , V_150 ) ;
} else {
F_82 ( V_150 ) ;
}
return V_2 ;
}
void F_83 ( struct V_9 * V_10 , struct V_2 * V_2 )
{
int V_151 ;
V_151 = F_84 ( V_10 , F_77 ,
F_78 , V_2 ) ;
F_46 ( V_151 ) ;
}
static int F_85 ( struct V_152 * V_152 , struct V_21 * V_153 )
{
struct V_2 * V_3 = F_86 ( V_152 -> V_154 ,
struct V_2 , V_155 ) ;
if ( F_87 ( V_156 , & V_3 -> V_157 ) )
return - V_111 ;
F_88 ( V_3 ) ;
V_153 -> V_25 = V_3 ;
return 0 ;
}
static int F_89 ( struct V_152 * V_152 , struct V_21 * V_153 )
{
struct V_2 * V_3 = F_86 ( V_152 -> V_154 ,
struct V_2 , V_155 ) ;
F_90 ( V_156 , & V_3 -> V_157 ) ;
F_91 ( V_3 ) ;
return 0 ;
}
static long F_92 ( struct V_21 * V_153 , unsigned int V_158 , unsigned long V_159 )
{
struct V_2 * V_3 = V_153 -> V_25 ;
int T_4 * V_160 = ( int T_4 * ) V_159 ;
int V_161 ;
if ( ! V_3 -> V_28 )
return - V_162 ;
if ( V_158 == V_163 ) {
V_161 = F_93 ( V_3 ) ;
if ( F_94 ( V_160 , & V_161 , sizeof( V_161 ) ) )
return - V_34 ;
return 0 ;
}
return - V_35 ;
}
int F_95 ( struct V_2 * V_3 )
{
int V_14 ;
if ( ! V_3 -> V_10 . V_164 && V_3 -> V_10 . V_31 )
V_3 -> V_10 . V_164 = V_3 -> V_10 . V_31 -> V_164 ;
V_3 -> V_10 . V_165 = F_96 ( F_97 ( V_17 ) , V_3 -> V_138 ) ;
V_14 = F_21 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_29 ) ;
return V_14 ;
}
V_14 = F_59 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_30 ) ;
goto V_166;
}
V_14 = F_98 ( V_3 ) ;
if ( V_14 ) {
F_14 ( V_3 -> V_10 . V_31 ,
L_31 ) ;
goto V_167;
}
if ( V_3 -> V_134 & V_135 )
F_99 ( V_3 ) ;
if ( ( V_3 -> V_134 & V_168 ) &&
V_3 -> V_169 == NULL )
V_3 -> V_169 = & V_170 ;
F_100 ( & V_3 -> V_155 , & V_171 ) ;
V_3 -> V_155 . V_172 = V_3 -> V_28 -> V_173 ;
V_3 -> V_155 . V_174 . V_31 = & V_3 -> V_10 . V_174 ;
V_14 = F_101 ( & V_3 -> V_155 , V_3 -> V_10 . V_165 , 1 ) ;
if ( V_14 < 0 )
goto V_175;
V_14 = F_102 ( & V_3 -> V_10 ) ;
if ( V_14 < 0 )
goto V_176;
return 0 ;
V_176:
F_103 ( & V_3 -> V_155 ) ;
V_175:
F_64 ( V_3 ) ;
V_167:
F_61 ( V_3 ) ;
V_166:
F_19 ( V_3 ) ;
return V_14 ;
}
void F_104 ( struct V_2 * V_3 )
{
F_105 ( & V_3 -> V_145 ) ;
F_106 ( & V_3 -> V_10 ) ;
if ( V_3 -> V_155 . V_10 )
F_103 ( & V_3 -> V_155 ) ;
F_19 ( V_3 ) ;
F_107 ( V_3 ) ;
V_3 -> V_28 = NULL ;
F_108 ( V_3 ) ;
F_109 ( V_3 ) ;
F_110 ( & V_3 -> V_145 ) ;
}
static void F_111 ( struct V_9 * V_10 , void * V_147 )
{
F_104 ( * (struct V_2 * * ) V_147 ) ;
}
int F_112 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
struct V_2 * * V_150 ;
int V_14 ;
V_150 = F_80 ( F_111 , sizeof( * V_150 ) , V_87 ) ;
if ( ! V_150 )
return - V_40 ;
* V_150 = V_3 ;
V_14 = F_95 ( V_3 ) ;
if ( ! V_14 )
F_81 ( V_10 , V_150 ) ;
else
F_82 ( V_150 ) ;
return V_14 ;
}
void F_113 ( struct V_9 * V_10 , struct V_2 * V_3 )
{
int V_151 ;
V_151 = F_84 ( V_10 , F_111 ,
F_78 , V_3 ) ;
F_46 ( V_151 ) ;
}
