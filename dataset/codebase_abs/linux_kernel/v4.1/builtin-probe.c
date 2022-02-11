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
static int F_6 ( const char * V_14 )
{
int V_15 = 0 ;
const char * V_16 ;
if ( ! V_4 . V_10 && V_14 && * V_14 == '/' ) {
V_4 . V_10 = F_4 ( V_14 ) ;
if ( ! V_4 . V_10 )
return - V_11 ;
V_4 . V_12 = false ;
V_15 = 1 ;
V_16 = V_14 + ( strlen ( V_14 ) - 3 ) ;
if ( strcmp ( V_16 , L_4 ) )
V_4 . V_9 = true ;
}
return V_15 ;
}
static int F_7 ( int V_17 , const char * * V_18 )
{
int V_19 , V_20 , V_7 , V_21 ;
char * V_16 ;
V_21 = F_6 ( V_18 [ 0 ] ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_21 && V_17 == 1 )
return 0 ;
V_20 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
if ( V_19 == 0 && V_21 )
continue;
V_20 += strlen ( V_18 [ V_19 ] ) + 1 ;
}
V_16 = F_8 ( V_20 + 1 ) ;
if ( V_16 == NULL )
return - V_11 ;
V_20 = 0 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 ++ ) {
if ( V_19 == 0 && V_21 )
continue;
V_20 += sprintf ( & V_16 [ V_20 ] , L_5 , V_18 [ V_19 ] ) ;
}
V_4 . V_22 = true ;
V_7 = F_1 ( V_16 ) ;
free ( V_16 ) ;
return V_7 ;
}
static int F_9 ( const struct V_23 * T_1 V_24 ,
const char * V_1 , int T_2 V_24 )
{
if ( V_1 ) {
V_4 . V_22 = true ;
return F_1 ( V_1 ) ;
} else
return 0 ;
}
static int F_10 ( const struct V_23 * T_1 V_24 ,
const char * V_1 , int T_2 V_24 )
{
if ( V_1 ) {
V_4 . V_22 = true ;
if ( ! V_4 . V_25 )
V_4 . V_25 = F_11 ( true , NULL ) ;
F_12 ( V_4 . V_25 , V_1 ) ;
}
return 0 ;
}
static int F_13 ( const struct V_23 * T_1 , const char * V_1 ,
int T_2 V_24 )
{
int V_7 = - V_26 ;
char * V_27 ;
if ( V_1 ) {
if ( ! strcmp ( T_1 -> V_28 , L_6 ) )
V_4 . V_9 = true ;
#ifdef F_14
else if ( ! strcmp ( T_1 -> V_28 , L_7 ) )
V_4 . V_9 = false ;
#endif
else
return V_7 ;
if ( V_4 . V_9 || strchr ( V_1 , '/' ) ) {
V_27 = F_15 ( V_1 , NULL ) ;
if ( ! V_27 ) {
F_16 ( L_8 , V_1 ) ;
return V_7 ;
}
} else {
V_27 = F_4 ( V_1 ) ;
if ( ! V_27 )
return - V_11 ;
}
free ( V_4 . V_10 ) ;
V_4 . V_10 = V_27 ;
V_4 . V_12 = false ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_17 ( const struct V_23 * T_1 V_24 ,
const char * V_1 , int T_2 V_24 )
{
int V_7 = 0 ;
if ( ! V_1 )
return 0 ;
if ( V_4 . V_29 ) {
F_16 ( L_9
L_10 ) ;
return 0 ;
}
V_4 . V_29 = true ;
V_7 = F_18 ( V_1 , & V_4 . V_30 ) ;
return V_7 ;
}
static int F_19 ( const struct V_23 * T_1 V_24 ,
const char * V_1 , int T_2 V_24 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
if ( ! V_1 )
return 0 ;
V_7 = F_1 ( V_1 ) ;
if ( ! V_7 && V_3 -> V_13 != 0 ) {
F_3 ( L_11 ) ;
return - V_31 ;
}
V_4 . V_32 = true ;
return V_7 ;
}
static int F_20 ( const struct V_23 * T_1 V_24 ,
const char * V_1 , int T_2 V_24 )
{
const char * V_33 ;
if ( V_1 ) {
F_21 ( L_12 , V_1 ) ;
if ( V_4 . V_34 )
F_22 ( V_4 . V_34 ) ;
V_4 . V_34 = F_23 ( V_1 , & V_33 ) ;
if ( ! V_4 . V_34 ) {
F_3 ( L_13 , V_33 - V_1 + 1 ) ;
F_3 ( L_14 , V_1 ) ;
F_3 ( L_15 , ( int ) ( V_33 - V_1 + 1 ) , '^' ) ;
return - V_31 ;
}
}
return 0 ;
}
static int F_24 ( void )
{
return F_25 ( & V_4 . V_30 ) ;
}
static void F_26 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_4 . V_6 ; V_19 ++ )
F_27 ( V_4 . V_5 + V_19 ) ;
if ( V_4 . V_25 )
F_28 ( V_4 . V_25 ) ;
F_29 ( & V_4 . V_30 ) ;
free ( V_4 . V_10 ) ;
if ( V_4 . V_34 )
F_22 ( V_4 . V_34 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
}
static void F_30 ( const char * V_35 , int V_33 )
{
char V_36 [ V_37 ] ;
F_3 ( L_16 , V_35 ) ;
F_2 ( L_17 ,
F_31 ( - V_33 , V_36 , sizeof( V_36 ) ) , V_33 ) ;
F_3 ( L_18 ) ;
}
static int
F_32 ( int V_17 , const char * * V_18 , const char * T_3 V_24 )
{
const char * const V_38 [] = {
L_19 ,
L_20 ,
L_21 ,
L_22 ,
#ifdef F_14
L_23 ,
L_24 ,
#endif
NULL
} ;
struct V_23 V_39 [] = {
F_33 ( 'v' , L_25 , & V_40 ,
L_26 ) ,
F_34 ( 'q' , L_27 , & V_4 . V_41 ,
L_28 ) ,
F_34 ( 'l' , L_29 , & V_4 . V_42 ,
L_30 ) ,
F_35 ( 'd' , L_31 , NULL , L_32 , L_33 ,
F_10 ) ,
F_35 ( 'a' , L_34 , NULL ,
#ifdef F_14
L_35
L_36 ,
#else
L_37 ,
#endif
L_38
L_39
L_40
L_41
L_42
L_43
#ifdef F_14
L_44
L_45
L_46
L_47
L_48
L_49 ,
#else
L_50 ,
#endif
F_9 ) ,
F_34 ( 'f' , L_51 , & V_4 . V_43 , L_52
L_53 ) ,
#ifdef F_14
F_35 ( 'L' , L_54 , NULL ,
L_55 ,
L_56 , F_17 ) ,
F_35 ( 'V' , L_57 , NULL ,
L_58 ,
L_59 , F_19 ) ,
F_34 ( '\0' , L_60 , & V_4 . V_44 ,
L_61 ) ,
F_36 ( 'k' , L_62 , & V_45 . V_46 ,
L_63 , L_64 ) ,
F_36 ( 's' , L_65 , & V_45 . V_47 ,
L_66 , L_67 ) ,
F_35 ( 'm' , L_7 , NULL , L_68 ,
L_69 ,
F_13 ) ,
#endif
F_37 ( & V_48 ) ,
F_38 ( '\0' , L_70 , & V_4 . V_49 ,
L_71 ) ,
F_34 ( 'F' , L_72 , & V_4 . V_50 ,
L_73 ) ,
F_35 ( '\0' , L_74 , NULL ,
L_75 , L_76
L_77 V_51 L_78
L_79 V_52 L_80 ,
F_20 ) ,
F_35 ( 'x' , L_6 , NULL , L_81 ,
L_82 , F_13 ) ,
F_34 ( 0 , L_83 , & V_45 . V_53 ,
L_84 ) ,
F_34 ( 0 , L_85 , & V_45 . V_54 ,
L_86 ) ,
F_39 ()
} ;
int V_7 ;
F_40 ( V_39 , 'a' , L_34 , V_55 ) ;
F_40 ( V_39 , 'd' , L_31 , V_55 ) ;
F_40 ( V_39 , 'l' , L_29 , V_55 ) ;
#ifdef F_14
F_40 ( V_39 , 'L' , L_54 , V_55 ) ;
F_40 ( V_39 , 'V' , L_57 , V_55 ) ;
#endif
V_17 = F_41 ( V_17 , V_18 , V_39 , V_38 ,
V_56 ) ;
if ( V_17 > 0 ) {
if ( strcmp ( V_18 [ 0 ] , L_87 ) == 0 ) {
F_16 ( L_88 ) ;
F_42 ( V_38 , V_39 ) ;
}
V_7 = F_7 ( V_17 , V_18 ) ;
if ( V_7 < 0 ) {
F_30 ( L_89 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_41 ) {
if ( V_40 != 0 ) {
F_3 ( L_90 ) ;
return - V_31 ;
}
V_40 = - 1 ;
}
if ( V_4 . V_49 == 0 )
V_4 . V_49 = V_8 ;
if ( ( ! V_4 . V_6 && ! V_4 . V_25 && ! V_4 . V_42 &&
! V_4 . V_29 && ! V_4 . V_50 ) )
F_42 ( V_38 , V_39 ) ;
V_45 . V_57 = ( V_45 . V_46 == NULL ) ;
if ( V_4 . V_42 ) {
if ( V_4 . V_9 ) {
F_16 ( L_91 ) ;
F_42 ( V_38 , V_39 ) ;
}
V_7 = F_43 () ;
if ( V_7 < 0 )
F_30 ( L_92 , V_7 ) ;
return V_7 ;
}
if ( V_4 . V_50 ) {
if ( ! V_4 . V_34 )
V_4 . V_34 = F_23 ( V_52 ,
NULL ) ;
V_7 = F_44 ( V_4 . V_10 , V_4 . V_34 ,
V_4 . V_9 ) ;
F_22 ( V_4 . V_34 ) ;
V_4 . V_34 = NULL ;
if ( V_7 < 0 )
F_30 ( L_93 , V_7 ) ;
return V_7 ;
}
#ifdef F_14
if ( V_4 . V_29 ) {
V_7 = F_45 ( & V_4 . V_30 , V_4 . V_10 ,
V_4 . V_9 ) ;
if ( V_7 < 0 )
F_30 ( L_94 , V_7 ) ;
return V_7 ;
}
if ( V_4 . V_32 ) {
if ( ! V_4 . V_34 )
V_4 . V_34 = F_23 ( V_51 ,
NULL ) ;
V_7 = F_46 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_49 ,
V_4 . V_10 ,
V_4 . V_34 ,
V_4 . V_44 ) ;
F_22 ( V_4 . V_34 ) ;
V_4 . V_34 = NULL ;
if ( V_7 < 0 )
F_30 ( L_95 , V_7 ) ;
return V_7 ;
}
#endif
if ( V_4 . V_25 ) {
V_7 = F_47 ( V_4 . V_25 ) ;
if ( V_7 < 0 ) {
F_30 ( L_96 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_6 ) {
if ( V_4 . V_10 && ! V_4 . V_12 ) {
F_16 ( L_97 ) ;
F_42 ( V_38 , V_39 ) ;
}
V_7 = F_48 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_49 ,
V_4 . V_43 ) ;
if ( V_7 < 0 ) {
F_30 ( L_98 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
int F_49 ( int V_17 , const char * * V_18 , const char * T_3 )
{
int V_7 ;
V_7 = F_24 () ;
if ( ! V_7 ) {
V_7 = F_32 ( V_17 , V_18 , T_3 ) ;
F_26 () ;
}
return V_7 ;
}
