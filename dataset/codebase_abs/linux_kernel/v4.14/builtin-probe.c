static int F_1 ( const char * V_1 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
F_2 ( L_1 , V_4 . V_6 , V_1 ) ;
if ( ++ V_4 . V_6 == V_8 ) {
F_3 ( L_2 , V_8 ) ;
return - 1 ;
}
V_3 -> V_9 = V_4 . V_9 ;
if ( V_4 . V_10 ) {
V_3 -> V_10 = F_4 ( V_4 . V_10 ) ;
if ( ! V_3 -> V_10 )
return - V_11 ;
V_4 . V_12 = true ;
}
if ( V_4 . V_13 )
V_3 -> V_13 = F_5 ( V_4 . V_13 ) ;
V_7 = F_6 ( V_1 , V_3 ) ;
F_2 ( L_3 , V_3 -> V_14 ) ;
return V_7 ;
}
static int F_7 ( const char * V_1 )
{
const char * V_15 = NULL ;
int V_7 = 0 ;
F_8 ( L_4 , V_1 ) ;
if ( ! V_4 . V_16 ) {
V_4 . V_16 = F_9 ( V_1 , & V_15 ) ;
if ( ! V_4 . V_16 )
V_7 = V_15 ? - V_17 : - V_11 ;
} else
V_7 = F_10 ( V_4 . V_16 , V_1 , & V_15 ) ;
if ( V_7 == - V_17 ) {
F_3 ( L_5 , V_15 - V_1 + 1 ) ;
F_3 ( L_6 , V_1 ) ;
F_3 ( L_7 , ( int ) ( V_15 - V_1 + 1 ) , '^' ) ;
}
return V_7 ;
}
static int F_11 ( const char * V_18 )
{
int V_19 = 0 ;
const char * V_20 ;
if ( ! V_4 . V_10 && V_18 && * V_18 == '/' ) {
V_4 . V_10 = F_4 ( V_18 ) ;
if ( ! V_4 . V_10 )
return - V_11 ;
V_4 . V_12 = false ;
V_19 = 1 ;
V_20 = V_18 + ( strlen ( V_18 ) - 3 ) ;
if ( strcmp ( V_20 , L_8 ) )
V_4 . V_9 = true ;
}
return V_19 ;
}
static int F_12 ( int V_21 , const char * * V_22 )
{
int V_23 , V_24 , V_7 , V_25 ;
char * V_20 ;
V_25 = F_11 ( V_22 [ 0 ] ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_25 && V_21 == 1 )
return 0 ;
V_24 = 0 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) {
if ( V_23 == 0 && V_25 )
continue;
V_24 += strlen ( V_22 [ V_23 ] ) + 1 ;
}
V_20 = F_13 ( V_24 + 1 ) ;
if ( V_20 == NULL )
return - V_11 ;
V_24 = 0 ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) {
if ( V_23 == 0 && V_25 )
continue;
V_24 += sprintf ( & V_20 [ V_24 ] , L_9 , V_22 [ V_23 ] ) ;
}
V_7 = F_1 ( V_20 ) ;
free ( V_20 ) ;
return V_7 ;
}
static int F_14 ( const struct V_26 * V_27 , const char * V_1 ,
int T_1 V_28 )
{
int V_7 = - V_29 ;
char * V_30 ;
if ( V_1 ) {
if ( ! strcmp ( V_27 -> V_31 , L_10 ) )
V_4 . V_9 = true ;
else if ( ! strcmp ( V_27 -> V_31 , L_11 ) )
V_4 . V_9 = false ;
else
return V_7 ;
if ( V_4 . V_9 || strchr ( V_1 , '/' ) ) {
V_30 = F_15 ( V_1 , V_4 . V_13 ) ;
if ( ! V_30 ) {
F_16 ( L_12 , V_1 ) ;
return V_7 ;
}
} else {
V_30 = F_4 ( V_1 ) ;
if ( ! V_30 )
return - V_11 ;
}
free ( V_4 . V_10 ) ;
V_4 . V_10 = V_30 ;
V_4 . V_12 = false ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_17 ( const struct V_26 * V_27 V_28 ,
const char * V_1 , int T_1 V_28 )
{
int V_7 = - V_29 ;
T_2 V_32 ;
struct V_33 * V_34 ;
if ( V_1 ) {
V_35 = 0 ;
V_32 = ( T_2 ) strtol ( V_1 , NULL , 10 ) ;
if ( V_35 != 0 ) {
V_7 = - V_35 ;
F_16 ( L_13 , V_1 ,
strerror ( V_35 ) ) ;
return V_7 ;
}
V_34 = F_18 ( V_32 ) ;
if ( V_34 && V_34 -> V_36 )
V_4 . V_13 = F_5 ( V_34 ) ;
F_19 ( V_34 ) ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_20 ( const struct V_26 * V_27 ,
const char * V_1 , int T_1 V_28 )
{
int V_7 = 0 ;
if ( ! V_1 )
return 0 ;
if ( V_4 . V_37 == 'L' ) {
F_16 ( L_14
L_15 ) ;
return 0 ;
}
V_4 . V_37 = V_27 -> V_38 ;
V_7 = F_21 ( V_1 , & V_4 . V_39 ) ;
return V_7 ;
}
static int F_22 ( const struct V_26 * V_27 ,
const char * V_1 , int T_1 V_28 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
if ( ! V_1 )
return 0 ;
V_7 = F_1 ( V_1 ) ;
if ( ! V_7 && V_3 -> V_14 != 0 ) {
F_3 ( L_16 ) ;
return - V_17 ;
}
V_4 . V_37 = V_27 -> V_38 ;
return V_7 ;
}
static int F_23 ( const struct V_26 * V_27 ,
const char * V_1 , int T_1 V_28 )
{
if ( V_1 ) {
V_4 . V_37 = V_27 -> V_38 ;
return F_1 ( V_1 ) ;
}
return 0 ;
}
static int F_24 ( const struct V_26 * V_27 ,
const char * V_1 , int T_1 )
{
if ( ! T_1 )
V_4 . V_37 = V_27 -> V_38 ;
if ( V_1 )
return F_7 ( V_1 ) ;
return 0 ;
}
static int F_25 ( const struct V_26 * V_27 V_28 ,
const char * V_1 , int T_1 V_28 )
{
if ( V_1 )
return F_7 ( V_1 ) ;
return 0 ;
}
static int F_26 ( void )
{
return F_27 ( & V_4 . V_39 ) ;
}
static void F_28 ( void )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_4 . V_6 ; V_23 ++ )
F_29 ( V_4 . V_5 + V_23 ) ;
F_30 ( & V_4 . V_39 ) ;
free ( V_4 . V_10 ) ;
F_31 ( V_4 . V_16 ) ;
F_19 ( V_4 . V_13 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
}
static void F_32 ( const char * V_40 , int V_15 )
{
char V_41 [ V_42 ] ;
F_3 ( L_17 , V_40 ) ;
F_2 ( L_18 ,
F_33 ( - V_15 , V_41 , sizeof( V_41 ) ) , V_15 ) ;
F_3 ( L_19 ) ;
}
static int F_34 ( struct V_2 * V_43 , int V_44 )
{
int V_7 ;
int V_23 , V_45 ;
const char * V_46 = NULL , * V_47 = NULL ;
V_7 = F_35 ( V_43 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_36 ( V_43 , V_44 ) ;
if ( V_7 < 0 )
goto V_48;
if ( V_4 . V_37 == 'D' ) {
V_7 = F_37 ( V_43 , V_44 ) ;
goto V_48;
}
V_7 = F_38 ( V_43 , V_44 ) ;
if ( V_7 < 0 )
goto V_48;
for ( V_23 = V_45 = 0 ; V_23 < V_44 ; V_23 ++ )
V_45 += V_43 [ V_23 ] . V_49 ;
F_39 ( L_20 , ( V_45 > 1 ) ? L_21 : L_22 ) ;
for ( V_23 = 0 ; V_23 < V_44 ; V_23 ++ ) {
struct V_2 * V_3 = & V_43 [ V_23 ] ;
for ( V_45 = 0 ; V_45 < V_3 -> V_49 ; V_45 ++ ) {
struct V_50 * V_51 = & V_3 -> V_52 [ V_45 ] ;
F_40 ( V_51 -> V_47 , V_51 -> V_46 , V_3 ,
V_51 -> V_53 . V_54 , false ) ;
V_46 = V_51 -> V_46 ;
V_47 = V_51 -> V_47 ;
}
}
if ( V_46 ) {
F_39 ( L_23 ) ;
F_39 ( L_24 , V_47 , V_46 ) ;
}
V_48:
F_41 ( V_43 , V_44 ) ;
F_42 () ;
return V_7 ;
}
static int F_43 ( struct V_55 * V_16 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_7 ;
V_59 = F_44 ( false ) ;
if ( ! V_59 ) {
V_7 = - V_35 ;
F_2 ( L_25 , V_7 ) ;
return V_7 ? : - V_11 ;
}
F_45 (nd, bidlist) {
V_57 = F_46 ( V_61 -> V_62 , NULL ) ;
if ( ! V_57 )
continue;
if ( F_47 ( V_57 , V_16 ) < 0 ||
F_48 ( V_57 ) < 0 )
F_16 ( L_26 , V_61 -> V_62 ) ;
F_49 ( V_57 ) ;
}
return 0 ;
}
static int F_50 ( struct V_55 * V_16 )
{
int V_7 , V_63 , V_64 = - 1 , V_65 = - 1 ;
char * V_1 = F_51 ( V_16 ) ;
struct V_58 * V_66 = NULL , * V_67 = NULL ;
struct V_60 * V_68 ;
if ( ! V_1 )
return - V_17 ;
F_2 ( L_27 , V_1 ) ;
if ( V_69 . V_57 )
return F_43 ( V_16 ) ;
V_7 = F_52 ( & V_65 , & V_64 , V_70 ) ;
if ( V_7 < 0 )
goto V_71;
V_66 = F_53 ( NULL , NULL ) ;
V_67 = F_53 ( NULL , NULL ) ;
if ( ! V_66 || ! V_67 ) {
V_7 = - V_11 ;
goto V_71;
}
V_7 = F_54 ( V_65 , V_16 , V_66 ) ;
if ( V_7 == 0 ) {
F_45 (ent, klist)
F_39 ( L_28 , V_68 -> V_62 ) ;
V_7 = F_55 ( V_65 , V_66 ) ;
if ( V_7 < 0 )
goto error;
}
V_63 = F_54 ( V_64 , V_16 , V_67 ) ;
if ( V_63 == 0 ) {
F_45 (ent, ulist)
F_39 ( L_28 , V_68 -> V_62 ) ;
V_63 = F_55 ( V_64 , V_67 ) ;
if ( V_63 < 0 )
goto error;
}
if ( V_7 == - V_29 && V_63 == - V_29 )
F_16 ( L_29 , V_1 ) ;
else
V_7 = 0 ;
error:
if ( V_65 >= 0 )
F_56 ( V_65 ) ;
if ( V_64 >= 0 )
F_56 ( V_64 ) ;
V_71:
F_57 ( V_66 ) ;
F_57 ( V_67 ) ;
free ( V_1 ) ;
return V_7 ;
}
static int
F_58 ( int V_21 , const char * * V_22 )
{
const char * const V_72 [] = {
L_30 ,
L_31 ,
L_32 ,
L_33 ,
#ifdef F_59
L_34 ,
L_35 ,
#endif
L_36 ,
NULL
} ;
struct V_26 V_73 [] = {
F_60 ( 'v' , L_37 , & V_74 ,
L_38 ) ,
F_61 ( 'q' , L_39 , & V_4 . V_75 ,
L_40 ) ,
F_62 ( 'l' , L_41 , NULL , L_42 ,
L_43 ,
F_24 , V_76 ) ,
F_63 ( 'd' , L_44 , NULL , L_42 , L_45 ,
F_24 ) ,
F_63 ( 'a' , L_46 , NULL , V_77 ,
L_47
L_48
L_49
L_50
L_51
L_52
#ifdef F_59
L_53
L_54
L_55
L_56
L_57
L_58 ,
#else
L_59 ,
#endif
F_23 ) ,
F_63 ( 'D' , L_60 , NULL , V_77 ,
L_61 ,
F_23 ) ,
F_61 ( 'f' , L_62 , & V_69 . V_78 , L_63
L_64 ) ,
F_63 ( 'L' , L_65 , NULL ,
L_66 ,
L_67 , F_20 ) ,
F_63 ( 'V' , L_68 , NULL ,
L_69 ,
L_70 , F_22 ) ,
F_61 ( '\0' , L_71 , & V_69 . V_79 ,
L_72 ) ,
F_61 ( '\0' , L_73 , & V_69 . V_80 ,
L_74 ) ,
F_64 ( 'k' , L_75 , & V_81 . V_82 ,
L_76 , L_77 ) ,
F_64 ( 's' , L_78 , & V_81 . V_83 ,
L_79 , L_80 ) ,
F_61 ( '\0' , L_81 , & V_69 . V_84 ,
L_82 ) ,
F_65 ( & V_85 ) ,
F_66 ( '\0' , L_83 , & V_69 . V_86 ,
L_84 ) ,
F_62 ( 'F' , L_85 , NULL , L_86 ,
L_87 ,
F_24 , V_87 ) ,
F_63 ( '\0' , L_88 , NULL ,
L_89 , L_90
L_91 V_88 L_92
L_93 V_87 L_94 ,
F_25 ) ,
F_63 ( 'x' , L_10 , NULL , L_95 ,
L_96 , F_14 ) ,
F_63 ( 'm' , L_11 , NULL , L_97 ,
L_98 ,
F_14 ) ,
F_61 ( 0 , L_99 , & V_81 . V_89 ,
L_100 ) ,
F_61 ( 0 , L_101 , & V_81 . V_90 ,
L_102 ) ,
F_61 ( 0 , L_103 , & V_69 . V_57 , L_104 ) ,
F_64 ( 0 , L_105 , & V_81 . V_91 , L_79 ,
L_106 ) ,
F_63 ( 0 , L_107 , NULL , L_108 ,
L_109 , F_17 ) ,
F_67 ()
} ;
int V_7 ;
F_68 ( V_73 , 'a' , L_46 , V_92 ) ;
F_68 ( V_73 , 'd' , L_44 , V_92 ) ;
F_68 ( V_73 , 'D' , L_60 , V_92 ) ;
F_68 ( V_73 , 'l' , L_41 , V_92 ) ;
#ifdef F_59
F_68 ( V_73 , 'L' , L_65 , V_92 ) ;
F_68 ( V_73 , 'V' , L_68 , V_92 ) ;
#else
# define F_69 ( V_62 , T_3 , T_4 ) set_option_nobuild(options, s, l, "NO_DWARF=1", c)
F_69 ( 'L' , L_65 , false ) ;
F_69 ( 'V' , L_68 , false ) ;
F_69 ( '\0' , L_71 , false ) ;
F_69 ( '\0' , L_73 , false ) ;
F_69 ( 'k' , L_75 , true ) ;
F_69 ( 's' , L_78 , true ) ;
F_69 ( '\0' , L_81 , true ) ;
# undef F_69
#endif
F_68 ( V_73 , 'F' , L_85 , V_92 ) ;
V_21 = F_70 ( V_21 , V_22 , V_73 , V_72 ,
V_93 ) ;
if ( V_21 > 0 ) {
if ( strcmp ( V_22 [ 0 ] , L_110 ) == 0 ) {
F_71 ( V_72 , V_73 ,
L_111 ) ;
}
if ( V_4 . V_37 && V_4 . V_37 != 'a' ) {
F_71 ( V_72 , V_73 ,
L_112 ) ;
}
V_7 = F_12 ( V_21 , V_22 ) ;
if ( V_7 < 0 ) {
F_32 ( L_113 , V_7 ) ;
return V_7 ;
}
V_4 . V_37 = 'a' ;
}
if ( V_4 . V_75 ) {
if ( V_74 != 0 ) {
F_3 ( L_114 ) ;
return - V_17 ;
}
V_74 = - 1 ;
}
if ( V_69 . V_86 == 0 )
V_69 . V_86 = V_8 ;
V_81 . V_94 = ( V_81 . V_82 == NULL ) ;
if ( ! strchr ( L_115 , V_4 . V_37 ) && V_81 . V_82 )
V_81 . V_95 = true ;
switch ( V_4 . V_37 ) {
case 'l' :
if ( V_4 . V_9 ) {
F_3 ( L_116 ) ;
F_72 ( V_72 , V_73 , L_117 , true ) ;
F_72 ( NULL , V_73 , L_118 , true ) ;
return - V_17 ;
}
V_7 = F_73 ( V_4 . V_16 ) ;
if ( V_7 < 0 )
F_32 ( L_119 , V_7 ) ;
return V_7 ;
case 'F' :
V_7 = F_74 ( V_4 . V_10 , V_4 . V_13 ,
V_4 . V_16 , V_4 . V_9 ) ;
if ( V_7 < 0 )
F_32 ( L_120 , V_7 ) ;
return V_7 ;
#ifdef F_59
case 'L' :
V_7 = F_75 ( & V_4 . V_39 , V_4 . V_10 ,
V_4 . V_13 , V_4 . V_9 ) ;
if ( V_7 < 0 )
F_32 ( L_121 , V_7 ) ;
return V_7 ;
case 'V' :
if ( ! V_4 . V_16 )
V_4 . V_16 = F_9 ( V_88 ,
NULL ) ;
V_7 = F_76 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_16 ) ;
if ( V_7 < 0 )
F_32 ( L_122 , V_7 ) ;
return V_7 ;
#endif
case 'd' :
V_7 = F_50 ( V_4 . V_16 ) ;
if ( V_7 < 0 ) {
F_32 ( L_123 , V_7 ) ;
return V_7 ;
}
break;
case 'D' :
case 'a' :
if ( V_4 . V_10 && ! V_4 . V_12 ) {
F_3 ( L_124 ) ;
F_72 ( V_72 , V_73 , L_125 , true ) ;
F_72 ( NULL , V_73 , L_118 , true ) ;
return - V_17 ;
}
V_7 = F_34 ( V_4 . V_5 , V_4 . V_6 ) ;
if ( V_7 < 0 ) {
F_32 ( L_126 , V_7 ) ;
return V_7 ;
}
break;
default:
F_77 ( V_72 , V_73 ) ;
}
return 0 ;
}
int F_78 ( int V_21 , const char * * V_22 )
{
int V_7 ;
V_7 = F_26 () ;
if ( ! V_7 ) {
V_7 = F_58 ( V_21 , V_22 ) ;
F_28 () ;
}
return V_7 < 0 ? V_7 : 0 ;
}
