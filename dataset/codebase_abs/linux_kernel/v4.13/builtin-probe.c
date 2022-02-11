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
if ( V_4 . V_31 == 'D' ) {
V_7 = F_33 ( V_37 , V_38 ) ;
goto V_42;
}
V_7 = F_34 ( V_37 , V_38 ) ;
if ( V_7 < 0 )
goto V_42;
for ( V_22 = V_39 = 0 ; V_22 < V_38 ; V_22 ++ )
V_39 += V_37 [ V_22 ] . V_43 ;
F_35 ( L_19 , ( V_39 > 1 ) ? L_20 : L_21 ) ;
for ( V_22 = 0 ; V_22 < V_38 ; V_22 ++ ) {
struct V_2 * V_3 = & V_37 [ V_22 ] ;
for ( V_39 = 0 ; V_39 < V_3 -> V_43 ; V_39 ++ ) {
struct V_44 * V_45 = & V_3 -> V_46 [ V_39 ] ;
F_36 ( V_45 -> V_41 , V_45 -> V_40 , V_3 ,
V_45 -> V_47 . V_48 , false ) ;
V_40 = V_45 -> V_40 ;
V_41 = V_45 -> V_41 ;
}
}
if ( V_40 ) {
F_35 ( L_22 ) ;
F_35 ( L_23 , V_41 , V_40 ) ;
}
V_42:
F_37 ( V_37 , V_38 ) ;
F_38 () ;
return V_7 ;
}
static int F_39 ( struct V_49 * V_15 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
int V_7 ;
V_53 = F_40 ( false ) ;
if ( ! V_53 ) {
V_7 = - V_56 ;
F_2 ( L_24 , V_7 ) ;
return V_7 ? : - V_11 ;
}
F_41 (nd, bidlist) {
V_51 = F_42 ( V_55 -> V_57 ) ;
if ( ! V_51 )
continue;
if ( F_43 ( V_51 , V_15 ) < 0 ||
F_44 ( V_51 ) < 0 )
F_15 ( L_25 , V_55 -> V_57 ) ;
F_45 ( V_51 ) ;
}
return 0 ;
}
static int F_46 ( struct V_49 * V_15 )
{
int V_7 , V_58 , V_59 = - 1 , V_60 = - 1 ;
char * V_1 = F_47 ( V_15 ) ;
struct V_52 * V_61 = NULL , * V_62 = NULL ;
struct V_54 * V_63 ;
if ( ! V_1 )
return - V_16 ;
F_2 ( L_26 , V_1 ) ;
if ( V_64 . V_51 )
return F_39 ( V_15 ) ;
V_7 = F_48 ( & V_60 , & V_59 , V_65 ) ;
if ( V_7 < 0 )
goto V_66;
V_61 = F_49 ( NULL , NULL ) ;
V_62 = F_49 ( NULL , NULL ) ;
if ( ! V_61 || ! V_62 ) {
V_7 = - V_11 ;
goto V_66;
}
V_7 = F_50 ( V_60 , V_15 , V_61 ) ;
if ( V_7 == 0 ) {
F_41 (ent, klist)
F_35 ( L_27 , V_63 -> V_57 ) ;
V_7 = F_51 ( V_60 , V_61 ) ;
if ( V_7 < 0 )
goto error;
}
V_58 = F_50 ( V_59 , V_15 , V_62 ) ;
if ( V_58 == 0 ) {
F_41 (ent, ulist)
F_35 ( L_27 , V_63 -> V_57 ) ;
V_58 = F_51 ( V_59 , V_62 ) ;
if ( V_58 < 0 )
goto error;
}
if ( V_7 == - V_28 && V_58 == - V_28 )
F_15 ( L_28 , V_1 ) ;
else
V_7 = 0 ;
error:
if ( V_60 >= 0 )
F_52 ( V_60 ) ;
if ( V_59 >= 0 )
F_52 ( V_59 ) ;
V_66:
F_53 ( V_61 ) ;
F_53 ( V_62 ) ;
free ( V_1 ) ;
return V_7 ;
}
static int
F_54 ( int V_20 , const char * * V_21 )
{
const char * const V_67 [] = {
L_29 ,
L_30 ,
L_31 ,
L_32 ,
#ifdef F_55
L_33 ,
L_34 ,
#endif
L_35 ,
NULL
} ;
struct V_25 V_68 [] = {
F_56 ( 'v' , L_36 , & V_69 ,
L_37 ) ,
F_57 ( 'q' , L_38 , & V_4 . V_70 ,
L_39 ) ,
F_58 ( 'l' , L_40 , NULL , L_41 ,
L_42 ,
F_20 , V_71 ) ,
F_59 ( 'd' , L_43 , NULL , L_41 , L_44 ,
F_20 ) ,
F_59 ( 'a' , L_45 , NULL , V_72 ,
L_46
L_47
L_48
L_49
L_50
L_51
#ifdef F_55
L_52
L_53
L_54
L_55
L_56
L_57 ,
#else
L_58 ,
#endif
F_19 ) ,
F_59 ( 'D' , L_59 , NULL , V_72 ,
L_60 ,
F_19 ) ,
F_57 ( 'f' , L_61 , & V_64 . V_73 , L_62
L_63 ) ,
F_59 ( 'L' , L_64 , NULL ,
L_65 ,
L_66 , F_16 ) ,
F_59 ( 'V' , L_67 , NULL ,
L_68 ,
L_69 , F_18 ) ,
F_57 ( '\0' , L_70 , & V_64 . V_74 ,
L_71 ) ,
F_57 ( '\0' , L_72 , & V_64 . V_75 ,
L_73 ) ,
F_60 ( 'k' , L_74 , & V_76 . V_77 ,
L_75 , L_76 ) ,
F_60 ( 's' , L_77 , & V_76 . V_78 ,
L_78 , L_79 ) ,
F_57 ( '\0' , L_80 , & V_64 . V_79 ,
L_81 ) ,
F_61 ( & V_80 ) ,
F_62 ( '\0' , L_82 , & V_64 . V_81 ,
L_83 ) ,
F_58 ( 'F' , L_84 , NULL , L_85 ,
L_86 ,
F_20 , V_82 ) ,
F_59 ( '\0' , L_87 , NULL ,
L_88 , L_89
L_90 V_83 L_91
L_92 V_82 L_93 ,
F_21 ) ,
F_59 ( 'x' , L_10 , NULL , L_94 ,
L_95 , F_13 ) ,
F_59 ( 'm' , L_11 , NULL , L_96 ,
L_97 ,
F_13 ) ,
F_57 ( 0 , L_98 , & V_76 . V_84 ,
L_99 ) ,
F_57 ( 0 , L_100 , & V_76 . V_85 ,
L_101 ) ,
F_57 ( 0 , L_102 , & V_64 . V_51 , L_103 ) ,
F_60 ( 0 , L_104 , & V_76 . V_86 , L_78 ,
L_105 ) ,
F_63 ()
} ;
int V_7 ;
F_64 ( V_68 , 'a' , L_45 , V_87 ) ;
F_64 ( V_68 , 'd' , L_43 , V_87 ) ;
F_64 ( V_68 , 'D' , L_59 , V_87 ) ;
F_64 ( V_68 , 'l' , L_40 , V_87 ) ;
#ifdef F_55
F_64 ( V_68 , 'L' , L_64 , V_87 ) ;
F_64 ( V_68 , 'V' , L_67 , V_87 ) ;
#else
# define F_65 ( V_57 , T_2 , T_3 ) set_option_nobuild(options, s, l, "NO_DWARF=1", c)
F_65 ( 'L' , L_64 , false ) ;
F_65 ( 'V' , L_67 , false ) ;
F_65 ( '\0' , L_70 , false ) ;
F_65 ( '\0' , L_72 , false ) ;
F_65 ( 'k' , L_74 , true ) ;
F_65 ( 's' , L_77 , true ) ;
F_65 ( '\0' , L_80 , true ) ;
# undef F_65
#endif
F_64 ( V_68 , 'F' , L_84 , V_87 ) ;
V_20 = F_66 ( V_20 , V_21 , V_68 , V_67 ,
V_88 ) ;
if ( V_20 > 0 ) {
if ( strcmp ( V_21 [ 0 ] , L_106 ) == 0 ) {
F_67 ( V_67 , V_68 ,
L_107 ) ;
}
if ( V_4 . V_31 && V_4 . V_31 != 'a' ) {
F_67 ( V_67 , V_68 ,
L_108 ) ;
}
V_7 = F_11 ( V_20 , V_21 ) ;
if ( V_7 < 0 ) {
F_28 ( L_109 , V_7 ) ;
return V_7 ;
}
V_4 . V_31 = 'a' ;
}
if ( V_4 . V_70 ) {
if ( V_69 != 0 ) {
F_3 ( L_110 ) ;
return - V_16 ;
}
V_69 = - 1 ;
}
if ( V_64 . V_81 == 0 )
V_64 . V_81 = V_8 ;
V_76 . V_89 = ( V_76 . V_77 == NULL ) ;
if ( ! strchr ( L_111 , V_4 . V_31 ) && V_76 . V_77 )
V_76 . V_90 = true ;
switch ( V_4 . V_31 ) {
case 'l' :
if ( V_4 . V_9 ) {
F_3 ( L_112 ) ;
F_68 ( V_67 , V_68 , L_113 , true ) ;
F_68 ( NULL , V_68 , L_114 , true ) ;
return - V_16 ;
}
V_7 = F_69 ( V_4 . V_15 ) ;
if ( V_7 < 0 )
F_28 ( L_115 , V_7 ) ;
return V_7 ;
case 'F' :
V_7 = F_70 ( V_4 . V_10 , V_4 . V_15 ,
V_4 . V_9 ) ;
if ( V_7 < 0 )
F_28 ( L_116 , V_7 ) ;
return V_7 ;
#ifdef F_55
case 'L' :
V_7 = F_71 ( & V_4 . V_33 , V_4 . V_10 ,
V_4 . V_9 ) ;
if ( V_7 < 0 )
F_28 ( L_117 , V_7 ) ;
return V_7 ;
case 'V' :
if ( ! V_4 . V_15 )
V_4 . V_15 = F_8 ( V_83 ,
NULL ) ;
V_7 = F_72 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_15 ) ;
if ( V_7 < 0 )
F_28 ( L_118 , V_7 ) ;
return V_7 ;
#endif
case 'd' :
V_7 = F_46 ( V_4 . V_15 ) ;
if ( V_7 < 0 ) {
F_28 ( L_119 , V_7 ) ;
return V_7 ;
}
break;
case 'D' :
case 'a' :
if ( V_4 . V_10 && ! V_4 . V_12 ) {
F_3 ( L_120 ) ;
F_68 ( V_67 , V_68 , L_121 , true ) ;
F_68 ( NULL , V_68 , L_114 , true ) ;
return - V_16 ;
}
V_7 = F_30 ( V_4 . V_5 , V_4 . V_6 ) ;
if ( V_7 < 0 ) {
F_28 ( L_122 , V_7 ) ;
return V_7 ;
}
break;
default:
F_73 ( V_67 , V_68 ) ;
}
return 0 ;
}
int F_74 ( int V_20 , const char * * V_21 )
{
int V_7 ;
V_7 = F_22 () ;
if ( ! V_7 ) {
V_7 = F_54 ( V_20 , V_21 ) ;
F_24 () ;
}
return V_7 < 0 ? V_7 : 0 ;
}
