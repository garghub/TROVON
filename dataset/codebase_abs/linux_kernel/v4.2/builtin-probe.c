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
#ifdef F_14
else if ( ! strcmp ( V_26 -> V_30 , L_11 ) )
V_4 . V_9 = false ;
#endif
else
return V_7 ;
if ( V_4 . V_9 || strchr ( V_1 , '/' ) ) {
V_29 = F_15 ( V_1 , NULL ) ;
if ( ! V_29 ) {
F_16 ( L_12 , V_1 ) ;
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
static int F_17 ( const struct V_25 * V_26 ,
const char * V_1 , int T_1 V_27 )
{
int V_7 = 0 ;
if ( ! V_1 )
return 0 ;
if ( V_4 . V_31 == 'L' ) {
F_16 ( L_13
L_14 ) ;
return 0 ;
}
V_4 . V_31 = V_26 -> V_32 ;
V_7 = F_18 ( V_1 , & V_4 . V_33 ) ;
return V_7 ;
}
static int F_19 ( const struct V_25 * V_26 ,
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
static int F_20 ( const struct V_25 * V_26 ,
const char * V_1 , int T_1 V_27 )
{
if ( V_1 ) {
V_4 . V_31 = V_26 -> V_32 ;
return F_1 ( V_1 ) ;
}
return 0 ;
}
static int F_21 ( const struct V_25 * V_26 ,
const char * V_1 , int T_1 )
{
if ( ! T_1 )
V_4 . V_31 = V_26 -> V_32 ;
if ( V_1 )
return F_6 ( V_1 ) ;
return 0 ;
}
static int F_22 ( const struct V_25 * V_26 V_27 ,
const char * V_1 , int T_1 V_27 )
{
if ( V_1 )
return F_6 ( V_1 ) ;
return 0 ;
}
static int F_23 ( void )
{
return F_24 ( & V_4 . V_33 ) ;
}
static void F_25 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_4 . V_6 ; V_22 ++ )
F_26 ( V_4 . V_5 + V_22 ) ;
F_27 ( & V_4 . V_33 ) ;
free ( V_4 . V_10 ) ;
if ( V_4 . V_15 )
F_28 ( V_4 . V_15 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
}
static void F_29 ( const char * V_34 , int V_14 )
{
char V_35 [ V_36 ] ;
F_3 ( L_16 , V_34 ) ;
F_2 ( L_17 ,
F_30 ( - V_14 , V_35 , sizeof( V_35 ) ) , V_14 ) ;
F_3 ( L_18 ) ;
}
static int
F_31 ( int V_20 , const char * * V_21 , const char * T_2 V_27 )
{
const char * const V_37 [] = {
L_19 ,
L_20 ,
L_21 ,
L_22 ,
#ifdef F_14
L_23 ,
L_24 ,
#endif
L_25 ,
NULL
} ;
struct V_25 V_38 [] = {
F_32 ( 'v' , L_26 , & V_39 ,
L_27 ) ,
F_33 ( 'q' , L_28 , & V_4 . V_40 ,
L_29 ) ,
F_34 ( 'l' , L_30 , NULL , L_31 ,
L_32 ,
F_21 , V_41 ) ,
F_35 ( 'd' , L_33 , NULL , L_31 , L_34 ,
F_21 ) ,
F_35 ( 'a' , L_35 , NULL ,
#ifdef F_14
L_36
L_37 ,
#else
L_38 ,
#endif
L_39
L_40
L_41
L_42
L_43
L_44
#ifdef F_14
L_45
L_46
L_47
L_48
L_49
L_50 ,
#else
L_51 ,
#endif
F_20 ) ,
F_33 ( 'f' , L_52 , & V_42 . V_43 , L_53
L_54 ) ,
#ifdef F_14
F_35 ( 'L' , L_55 , NULL ,
L_56 ,
L_57 , F_17 ) ,
F_35 ( 'V' , L_58 , NULL ,
L_59 ,
L_60 , F_19 ) ,
F_33 ( '\0' , L_61 , & V_42 . V_44 ,
L_62 ) ,
F_33 ( '\0' , L_63 , & V_42 . V_45 ,
L_64 ) ,
F_36 ( 'k' , L_65 , & V_46 . V_47 ,
L_66 , L_67 ) ,
F_36 ( 's' , L_68 , & V_46 . V_48 ,
L_69 , L_70 ) ,
F_35 ( 'm' , L_11 , NULL , L_71 ,
L_72 ,
F_13 ) ,
F_33 ( '\0' , L_73 , & V_42 . V_49 ,
L_74 ) ,
#endif
F_37 ( & V_50 ) ,
F_38 ( '\0' , L_75 , & V_42 . V_51 ,
L_76 ) ,
F_34 ( 'F' , L_77 , NULL , L_78 ,
L_79 ,
F_21 , V_52 ) ,
F_35 ( '\0' , L_80 , NULL ,
L_81 , L_82
L_83 V_53 L_84
L_85 V_52 L_86 ,
F_22 ) ,
F_35 ( 'x' , L_10 , NULL , L_87 ,
L_88 , F_13 ) ,
F_33 ( 0 , L_89 , & V_46 . V_54 ,
L_90 ) ,
F_33 ( 0 , L_91 , & V_46 . V_55 ,
L_92 ) ,
F_39 ()
} ;
int V_7 ;
F_40 ( V_38 , 'a' , L_35 , V_56 ) ;
F_40 ( V_38 , 'd' , L_33 , V_56 ) ;
F_40 ( V_38 , 'l' , L_30 , V_56 ) ;
#ifdef F_14
F_40 ( V_38 , 'L' , L_55 , V_56 ) ;
F_40 ( V_38 , 'V' , L_58 , V_56 ) ;
#endif
F_40 ( V_38 , 'F' , L_77 , V_56 ) ;
V_20 = F_41 ( V_20 , V_21 , V_38 , V_37 ,
V_57 ) ;
if ( V_20 > 0 ) {
if ( strcmp ( V_21 [ 0 ] , L_93 ) == 0 ) {
F_16 ( L_94 ) ;
F_42 ( V_37 , V_38 ) ;
}
if ( V_4 . V_31 && V_4 . V_31 != 'a' ) {
F_16 ( L_95 ) ;
F_42 ( V_37 , V_38 ) ;
}
V_7 = F_11 ( V_20 , V_21 ) ;
if ( V_7 < 0 ) {
F_29 ( L_96 , V_7 ) ;
return V_7 ;
}
V_4 . V_31 = 'a' ;
}
if ( V_4 . V_40 ) {
if ( V_39 != 0 ) {
F_3 ( L_97 ) ;
return - V_16 ;
}
V_39 = - 1 ;
}
if ( V_42 . V_51 == 0 )
V_42 . V_51 = V_8 ;
V_46 . V_58 = ( V_46 . V_47 == NULL ) ;
switch ( V_4 . V_31 ) {
case 'l' :
if ( V_4 . V_9 ) {
F_16 ( L_98 ) ;
F_42 ( V_37 , V_38 ) ;
}
V_7 = F_43 ( V_4 . V_15 ) ;
if ( V_7 < 0 )
F_29 ( L_99 , V_7 ) ;
return V_7 ;
case 'F' :
V_7 = F_44 ( V_4 . V_10 , V_4 . V_15 ,
V_4 . V_9 ) ;
if ( V_7 < 0 )
F_29 ( L_100 , V_7 ) ;
return V_7 ;
#ifdef F_14
case 'L' :
V_7 = F_45 ( & V_4 . V_33 , V_4 . V_10 ,
V_4 . V_9 ) ;
if ( V_7 < 0 )
F_29 ( L_101 , V_7 ) ;
return V_7 ;
case 'V' :
if ( ! V_4 . V_15 )
V_4 . V_15 = F_8 ( V_53 ,
NULL ) ;
V_7 = F_46 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_15 ) ;
if ( V_7 < 0 )
F_29 ( L_102 , V_7 ) ;
return V_7 ;
#endif
case 'd' :
V_7 = F_47 ( V_4 . V_15 ) ;
if ( V_7 < 0 ) {
F_29 ( L_103 , V_7 ) ;
return V_7 ;
}
break;
case 'a' :
if ( V_4 . V_10 && ! V_4 . V_12 ) {
F_16 ( L_104 ) ;
F_42 ( V_37 , V_38 ) ;
}
V_7 = F_48 ( V_4 . V_5 , V_4 . V_6 ) ;
if ( V_7 < 0 ) {
F_29 ( L_105 , V_7 ) ;
return V_7 ;
}
break;
default:
F_42 ( V_37 , V_38 ) ;
}
return 0 ;
}
int F_49 ( int V_20 , const char * * V_21 , const char * T_2 )
{
int V_7 ;
V_7 = F_23 () ;
if ( ! V_7 ) {
V_7 = F_31 ( V_20 , V_21 , T_2 ) ;
F_25 () ;
}
return V_7 < 0 ? V_7 : 0 ;
}
