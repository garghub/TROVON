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
V_7 = F_5 ( V_1 , V_3 ) ;
F_2 ( L_3 , V_3 -> V_13 ) ;
return V_7 ;
}
static int F_6 ( const char * V_1 )
{
const char * V_14 = NULL ;
int V_7 = 0 ;
F_7 ( L_4 , V_1 ) ;
if ( ! V_4 . V_15 ) {
V_4 . V_15 = F_8 ( V_1 , & V_14 ) ;
if ( ! V_4 . V_15 )
V_7 = V_14 ? - V_16 : - V_11 ;
} else
V_7 = F_9 ( V_4 . V_15 , V_1 , & V_14 ) ;
if ( V_7 == - V_16 ) {
F_3 ( L_5 , V_14 - V_1 + 1 ) ;
F_3 ( L_6 , V_1 ) ;
F_3 ( L_7 , ( int ) ( V_14 - V_1 + 1 ) , '^' ) ;
}
return V_7 ;
}
static int F_10 ( const char * V_17 )
{
int V_18 = 0 ;
const char * V_19 ;
if ( ! V_4 . V_10 && V_17 && * V_17 == '/' ) {
V_4 . V_10 = F_4 ( V_17 ) ;
if ( ! V_4 . V_10 )
return - V_11 ;
V_4 . V_12 = false ;
V_18 = 1 ;
V_19 = V_17 + ( strlen ( V_17 ) - 3 ) ;
if ( strcmp ( V_19 , L_8 ) )
V_4 . V_9 = true ;
}
return V_18 ;
}
static int F_11 ( int V_20 , const char * * V_21 )
{
int V_22 , V_23 , V_7 , V_24 ;
char * V_19 ;
V_24 = F_10 ( V_21 [ 0 ] ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 && V_20 == 1 )
return 0 ;
V_23 = 0 ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
if ( V_22 == 0 && V_24 )
continue;
V_23 += strlen ( V_21 [ V_22 ] ) + 1 ;
}
V_19 = F_12 ( V_23 + 1 ) ;
if ( V_19 == NULL )
return - V_11 ;
V_23 = 0 ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ ) {
if ( V_22 == 0 && V_24 )
continue;
V_23 += sprintf ( & V_19 [ V_23 ] , L_9 , V_21 [ V_22 ] ) ;
}
V_7 = F_1 ( V_19 ) ;
free ( V_19 ) ;
return V_7 ;
}
static int F_13 ( const struct V_25 * V_26 , const char * V_1 ,
int T_1 V_27 )
{
int V_7 = - V_28 ;
char * V_29 ;
if ( V_1 ) {
if ( ! strcmp ( V_26 -> V_30 , L_10 ) )
V_4 . V_9 = true ;
else if ( ! strcmp ( V_26 -> V_30 , L_11 ) )
V_4 . V_9 = false ;
else
return V_7 ;
if ( V_4 . V_9 || strchr ( V_1 , '/' ) ) {
V_29 = F_14 ( V_1 , NULL ) ;
if ( ! V_29 ) {
F_15 ( L_12 , V_1 ) ;
return V_7 ;
}
} else {
V_29 = F_4 ( V_1 ) ;
if ( ! V_29 )
return - V_11 ;
}
free ( V_4 . V_10 ) ;
V_4 . V_10 = V_29 ;
V_4 . V_12 = false ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_16 ( const struct V_25 * V_26 ,
const char * V_1 , int T_1 V_27 )
{
int V_7 = 0 ;
if ( ! V_1 )
return 0 ;
if ( V_4 . V_31 == 'L' ) {
F_15 ( L_13
L_14 ) ;
return 0 ;
}
V_4 . V_31 = V_26 -> V_32 ;
V_7 = F_17 ( V_1 , & V_4 . V_33 ) ;
return V_7 ;
}
static int F_18 ( const struct V_25 * V_26 ,
const char * V_1 , int T_1 V_27 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
if ( ! V_1 )
return 0 ;
V_7 = F_1 ( V_1 ) ;
if ( ! V_7 && V_3 -> V_13 != 0 ) {
F_3 ( L_15 ) ;
return - V_16 ;
}
V_4 . V_31 = V_26 -> V_32 ;
return V_7 ;
}
static int F_19 ( const struct V_25 * V_26 ,
const char * V_1 , int T_1 V_27 )
{
if ( V_1 ) {
V_4 . V_31 = V_26 -> V_32 ;
return F_1 ( V_1 ) ;
}
return 0 ;
}
static int F_20 ( const struct V_25 * V_26 ,
const char * V_1 , int T_1 )
{
if ( ! T_1 )
V_4 . V_31 = V_26 -> V_32 ;
if ( V_1 )
return F_6 ( V_1 ) ;
return 0 ;
}
static int F_21 ( const struct V_25 * V_26 V_27 ,
const char * V_1 , int T_1 V_27 )
{
if ( V_1 )
return F_6 ( V_1 ) ;
return 0 ;
}
static int F_22 ( void )
{
return F_23 ( & V_4 . V_33 ) ;
}
static void F_24 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_4 . V_6 ; V_22 ++ )
F_25 ( V_4 . V_5 + V_22 ) ;
F_26 ( & V_4 . V_33 ) ;
free ( V_4 . V_10 ) ;
F_27 ( V_4 . V_15 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
}
static void F_28 ( const char * V_34 , int V_14 )
{
char V_35 [ V_36 ] ;
F_3 ( L_16 , V_34 ) ;
F_2 ( L_17 ,
F_29 ( - V_14 , V_35 , sizeof( V_35 ) ) , V_14 ) ;
F_3 ( L_18 ) ;
}
static int F_30 ( struct V_2 * V_37 , int V_38 )
{
int V_7 ;
int V_22 , V_39 ;
const char * V_40 = NULL , * V_41 = NULL ;
V_7 = F_31 ( V_37 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_32 ( V_37 , V_38 ) ;
if ( V_7 < 0 )
goto V_42;
V_7 = F_33 ( V_37 , V_38 ) ;
if ( V_7 < 0 )
goto V_42;
for ( V_22 = V_39 = 0 ; V_22 < V_38 ; V_22 ++ )
V_39 += V_37 [ V_22 ] . V_43 ;
F_34 ( L_19 , ( V_39 > 1 ) ? L_20 : L_21 ) ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 ++ ) {
struct V_2 * V_3 = & V_37 [ V_22 ] ;
for ( V_39 = 0 ; V_39 < V_3 -> V_43 ; V_39 ++ ) {
struct V_44 * V_45 = & V_3 -> V_46 [ V_39 ] ;
F_35 ( V_45 -> V_41 , V_45 -> V_40 , V_3 ,
V_45 -> V_47 . V_48 , false ) ;
V_40 = V_45 -> V_40 ;
V_41 = V_45 -> V_41 ;
}
}
if ( V_40 ) {
F_34 ( L_22 ) ;
F_34 ( L_23 , V_41 , V_40 ) ;
}
V_42:
F_36 ( V_37 , V_38 ) ;
F_37 () ;
return V_7 ;
}
static int F_38 ( struct V_49 * V_15 )
{
int V_7 , V_50 , V_51 = - 1 , V_52 = - 1 ;
char * V_1 = F_39 ( V_15 ) ;
struct V_53 * V_54 = NULL , * V_55 = NULL ;
struct V_56 * V_57 ;
if ( ! V_1 )
return - V_16 ;
F_2 ( L_24 , V_1 ) ;
V_7 = F_40 ( & V_52 , & V_51 , V_58 ) ;
if ( V_7 < 0 )
goto V_59;
V_54 = F_41 ( NULL , NULL ) ;
V_55 = F_41 ( NULL , NULL ) ;
if ( ! V_54 || ! V_55 ) {
V_7 = - V_11 ;
goto V_59;
}
V_7 = F_42 ( V_52 , V_15 , V_54 ) ;
if ( V_7 == 0 ) {
F_43 (ent, klist)
F_34 ( L_25 , V_57 -> V_60 ) ;
V_7 = F_44 ( V_52 , V_54 ) ;
if ( V_7 < 0 )
goto error;
}
V_50 = F_42 ( V_51 , V_15 , V_55 ) ;
if ( V_50 == 0 ) {
F_43 (ent, ulist)
F_34 ( L_25 , V_57 -> V_60 ) ;
V_50 = F_44 ( V_51 , V_55 ) ;
if ( V_50 < 0 )
goto error;
}
if ( V_7 == - V_28 && V_50 == - V_28 )
F_2 ( L_26 , V_1 ) ;
V_7 = 0 ;
error:
if ( V_52 >= 0 )
F_45 ( V_52 ) ;
if ( V_51 >= 0 )
F_45 ( V_51 ) ;
V_59:
F_46 ( V_54 ) ;
F_46 ( V_55 ) ;
free ( V_1 ) ;
return V_7 ;
}
static int
F_47 ( int V_20 , const char * * V_21 , const char * T_2 V_27 )
{
const char * const V_61 [] = {
L_27 ,
L_28 ,
L_29 ,
L_30 ,
#ifdef F_48
L_31 ,
L_32 ,
#endif
L_33 ,
NULL
} ;
struct V_25 V_62 [] = {
F_49 ( 'v' , L_34 , & V_63 ,
L_35 ) ,
F_50 ( 'q' , L_36 , & V_4 . V_64 ,
L_37 ) ,
F_51 ( 'l' , L_38 , NULL , L_39 ,
L_40 ,
F_20 , V_65 ) ,
F_52 ( 'd' , L_41 , NULL , L_39 , L_42 ,
F_20 ) ,
F_52 ( 'a' , L_43 , NULL ,
#ifdef F_48
L_44
L_45 ,
#else
L_46 ,
#endif
L_47
L_48
L_49
L_50
L_51
L_52
#ifdef F_48
L_53
L_54
L_55
L_56
L_57
L_58 ,
#else
L_59 ,
#endif
F_19 ) ,
F_50 ( 'f' , L_60 , & V_66 . V_67 , L_61
L_62 ) ,
F_52 ( 'L' , L_63 , NULL ,
L_64 ,
L_65 , F_16 ) ,
F_52 ( 'V' , L_66 , NULL ,
L_67 ,
L_68 , F_18 ) ,
F_50 ( '\0' , L_69 , & V_66 . V_68 ,
L_70 ) ,
F_50 ( '\0' , L_71 , & V_66 . V_69 ,
L_72 ) ,
F_53 ( 'k' , L_73 , & V_70 . V_71 ,
L_74 , L_75 ) ,
F_53 ( 's' , L_76 , & V_70 . V_72 ,
L_77 , L_78 ) ,
F_50 ( '\0' , L_79 , & V_66 . V_73 ,
L_80 ) ,
F_54 ( & V_74 ) ,
F_55 ( '\0' , L_81 , & V_66 . V_75 ,
L_82 ) ,
F_51 ( 'F' , L_83 , NULL , L_84 ,
L_85 ,
F_20 , V_76 ) ,
F_52 ( '\0' , L_86 , NULL ,
L_87 , L_88
L_89 V_77 L_90
L_91 V_76 L_92 ,
F_21 ) ,
F_52 ( 'x' , L_10 , NULL , L_93 ,
L_94 , F_13 ) ,
F_52 ( 'm' , L_11 , NULL , L_95 ,
L_96 ,
F_13 ) ,
F_50 ( 0 , L_97 , & V_70 . V_78 ,
L_98 ) ,
F_50 ( 0 , L_99 , & V_70 . V_79 ,
L_100 ) ,
F_56 ()
} ;
int V_7 ;
F_57 ( V_62 , 'a' , L_43 , V_80 ) ;
F_57 ( V_62 , 'd' , L_41 , V_80 ) ;
F_57 ( V_62 , 'l' , L_38 , V_80 ) ;
#ifdef F_48
F_57 ( V_62 , 'L' , L_63 , V_80 ) ;
F_57 ( V_62 , 'V' , L_66 , V_80 ) ;
#else
# define F_58 ( V_60 , T_3 , T_4 ) set_option_nobuild(options, s, l, "NO_DWARF=1", c)
F_58 ( 'L' , L_63 , false ) ;
F_58 ( 'V' , L_66 , false ) ;
F_58 ( '\0' , L_69 , false ) ;
F_58 ( '\0' , L_71 , false ) ;
F_58 ( 'k' , L_73 , true ) ;
F_58 ( 's' , L_76 , true ) ;
F_58 ( '\0' , L_79 , true ) ;
# undef F_58
#endif
F_57 ( V_62 , 'F' , L_83 , V_80 ) ;
V_20 = F_59 ( V_20 , V_21 , V_62 , V_61 ,
V_81 ) ;
if ( V_20 > 0 ) {
if ( strcmp ( V_21 [ 0 ] , L_101 ) == 0 ) {
F_60 ( V_61 , V_62 ,
L_102 ) ;
}
if ( V_4 . V_31 && V_4 . V_31 != 'a' ) {
F_60 ( V_61 , V_62 ,
L_103 ) ;
}
V_7 = F_11 ( V_20 , V_21 ) ;
if ( V_7 < 0 ) {
F_28 ( L_104 , V_7 ) ;
return V_7 ;
}
V_4 . V_31 = 'a' ;
}
if ( V_4 . V_64 ) {
if ( V_63 != 0 ) {
F_3 ( L_105 ) ;
return - V_16 ;
}
V_63 = - 1 ;
}
if ( V_66 . V_75 == 0 )
V_66 . V_75 = V_8 ;
V_70 . V_82 = ( V_70 . V_71 == NULL ) ;
switch ( V_4 . V_31 ) {
case 'l' :
if ( V_4 . V_9 ) {
F_3 ( L_106 ) ;
F_61 ( V_61 , V_62 , L_107 , true ) ;
F_61 ( NULL , V_62 , L_108 , true ) ;
return - V_16 ;
}
V_7 = F_62 ( V_4 . V_15 ) ;
if ( V_7 < 0 )
F_28 ( L_109 , V_7 ) ;
return V_7 ;
case 'F' :
V_7 = F_63 ( V_4 . V_10 , V_4 . V_15 ,
V_4 . V_9 ) ;
if ( V_7 < 0 )
F_28 ( L_110 , V_7 ) ;
return V_7 ;
#ifdef F_48
case 'L' :
V_7 = F_64 ( & V_4 . V_33 , V_4 . V_10 ,
V_4 . V_9 ) ;
if ( V_7 < 0 )
F_28 ( L_111 , V_7 ) ;
return V_7 ;
case 'V' :
if ( ! V_4 . V_15 )
V_4 . V_15 = F_8 ( V_77 ,
NULL ) ;
V_7 = F_65 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_15 ) ;
if ( V_7 < 0 )
F_28 ( L_112 , V_7 ) ;
return V_7 ;
#endif
case 'd' :
V_7 = F_38 ( V_4 . V_15 ) ;
if ( V_7 < 0 ) {
F_28 ( L_113 , V_7 ) ;
return V_7 ;
}
break;
case 'a' :
if ( V_4 . V_10 && ! V_4 . V_12 ) {
F_3 ( L_114 ) ;
F_61 ( V_61 , V_62 , L_115 , true ) ;
F_61 ( NULL , V_62 , L_108 , true ) ;
return - V_16 ;
}
V_7 = F_30 ( V_4 . V_5 , V_4 . V_6 ) ;
if ( V_7 < 0 ) {
F_28 ( L_116 , V_7 ) ;
return V_7 ;
}
break;
default:
F_66 ( V_61 , V_62 ) ;
}
return 0 ;
}
int F_67 ( int V_20 , const char * * V_21 , const char * T_2 )
{
int V_7 ;
V_7 = F_22 () ;
if ( ! V_7 ) {
V_7 = F_47 ( V_20 , V_21 , T_2 ) ;
F_24 () ;
}
return V_7 < 0 ? V_7 : 0 ;
}
