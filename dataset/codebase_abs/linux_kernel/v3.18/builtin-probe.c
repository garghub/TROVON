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
V_7 = F_4 ( V_1 , V_3 ) ;
F_2 ( L_3 , V_3 -> V_10 ) ;
return V_7 ;
}
static int F_5 ( const char * V_11 )
{
int V_12 = 0 ;
const char * V_13 ;
if ( ! V_4 . V_14 && V_11 && * V_11 == '/' ) {
V_4 . V_14 = F_6 ( V_11 ) ;
if ( ! V_4 . V_14 )
return - V_15 ;
V_12 = 1 ;
V_13 = V_11 + ( strlen ( V_11 ) - 3 ) ;
if ( strcmp ( V_13 , L_4 ) )
V_4 . V_9 = true ;
}
return V_12 ;
}
static int F_7 ( int V_16 , const char * * V_17 )
{
int V_18 , V_19 , V_7 , V_20 ;
char * V_13 ;
V_20 = F_5 ( V_17 [ 0 ] ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_20 && V_16 == 1 )
return 0 ;
V_19 = 0 ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 ++ ) {
if ( V_18 == 0 && V_20 )
continue;
V_19 += strlen ( V_17 [ V_18 ] ) + 1 ;
}
V_13 = F_8 ( V_19 + 1 ) ;
if ( V_13 == NULL )
return - V_15 ;
V_19 = 0 ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 ++ ) {
if ( V_18 == 0 && V_20 )
continue;
V_19 += sprintf ( & V_13 [ V_19 ] , L_5 , V_17 [ V_18 ] ) ;
}
V_4 . V_21 = true ;
V_7 = F_1 ( V_13 ) ;
free ( V_13 ) ;
return V_7 ;
}
static int F_9 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
if ( V_1 ) {
V_4 . V_21 = true ;
return F_1 ( V_1 ) ;
} else
return 0 ;
}
static int F_10 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
if ( V_1 ) {
V_4 . V_21 = true ;
if ( ! V_4 . V_24 )
V_4 . V_24 = F_11 ( true , NULL ) ;
F_12 ( V_4 . V_24 , V_1 ) ;
}
return 0 ;
}
static int F_13 ( const struct V_22 * T_1 , const char * V_1 ,
int T_2 V_23 )
{
int V_7 = - V_25 ;
char * V_26 ;
if ( V_1 && ! V_4 . V_14 ) {
if ( ! strcmp ( T_1 -> V_27 , L_6 ) )
V_4 . V_9 = true ;
#ifdef F_14
else if ( ! strcmp ( T_1 -> V_27 , L_7 ) )
V_4 . V_9 = false ;
#endif
else
return V_7 ;
if ( V_4 . V_9 || strchr ( V_1 , '/' ) ) {
V_26 = F_15 ( V_1 , NULL ) ;
if ( ! V_26 ) {
F_16 ( L_8 , V_1 ) ;
return V_7 ;
}
} else {
V_26 = F_6 ( V_1 ) ;
if ( ! V_26 )
return - V_15 ;
}
V_4 . V_14 = V_26 ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_17 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
int V_7 = 0 ;
if ( ! V_1 )
return 0 ;
if ( V_4 . V_28 ) {
F_16 ( L_9
L_10 ) ;
return 0 ;
}
V_4 . V_28 = true ;
V_7 = F_18 ( V_1 , & V_4 . V_29 ) ;
return V_7 ;
}
static int F_19 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
if ( ! V_1 )
return 0 ;
V_7 = F_1 ( V_1 ) ;
if ( ! V_7 && V_3 -> V_10 != 0 ) {
F_3 ( L_11 ) ;
return - V_30 ;
}
V_4 . V_31 = true ;
return V_7 ;
}
static int F_20 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
const char * V_32 ;
if ( V_1 ) {
F_21 ( L_12 , V_1 ) ;
if ( V_4 . V_33 )
F_22 ( V_4 . V_33 ) ;
V_4 . V_33 = F_23 ( V_1 , & V_32 ) ;
if ( ! V_4 . V_33 ) {
F_3 ( L_13 , V_32 - V_1 + 1 ) ;
F_3 ( L_14 , V_1 ) ;
F_3 ( L_15 , ( int ) ( V_32 - V_1 + 1 ) , '^' ) ;
return - V_30 ;
}
}
return 0 ;
}
static int F_24 ( void )
{
return F_25 ( & V_4 . V_29 ) ;
}
static void F_26 ( void )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 . V_6 ; V_18 ++ )
F_27 ( V_4 . V_5 + V_18 ) ;
if ( V_4 . V_24 )
F_28 ( V_4 . V_24 ) ;
F_29 ( & V_4 . V_29 ) ;
free ( V_4 . V_14 ) ;
if ( V_4 . V_33 )
F_22 ( V_4 . V_33 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
}
static void F_30 ( const char * V_34 , int V_32 )
{
char V_35 [ V_36 ] ;
F_3 ( L_16 , V_34 ) ;
F_2 ( L_17 ,
F_31 ( - V_32 , V_35 , sizeof( V_35 ) ) , V_32 ) ;
F_3 ( L_18 ) ;
}
static int
F_32 ( int V_16 , const char * * V_17 , const char * T_3 V_23 )
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
NULL
} ;
const struct V_22 V_38 [] = {
F_33 ( 'v' , L_25 , & V_39 ,
L_26 ) ,
F_34 ( 'l' , L_27 , & V_4 . V_40 ,
L_28 ) ,
F_35 ( 'd' , L_29 , NULL , L_30 , L_31 ,
F_10 ) ,
F_35 ( 'a' , L_32 , NULL ,
#ifdef F_14
L_33
L_34 ,
#else
L_35 ,
#endif
L_36
L_37
L_38
L_39
L_40
L_41
#ifdef F_14
L_42
L_43
L_44
L_45
L_46
L_47 ,
#else
L_48 ,
#endif
F_9 ) ,
F_34 ( 'f' , L_49 , & V_4 . V_41 , L_50
L_51 ) ,
#ifdef F_14
F_35 ( 'L' , L_52 , NULL ,
L_53 ,
L_54 , F_17 ) ,
F_35 ( 'V' , L_55 , NULL ,
L_56 ,
L_57 , F_19 ) ,
F_34 ( '\0' , L_58 , & V_4 . V_42 ,
L_59 ) ,
F_36 ( 'k' , L_60 , & V_43 . V_44 ,
L_61 , L_62 ) ,
F_36 ( 's' , L_63 , & V_43 . V_45 ,
L_64 , L_65 ) ,
F_35 ( 'm' , L_7 , NULL , L_66 ,
L_67 ,
F_13 ) ,
#endif
F_37 ( & V_46 ) ,
F_38 ( '\0' , L_68 , & V_4 . V_47 ,
L_69 ) ,
F_34 ( 'F' , L_70 , & V_4 . V_48 ,
L_71 ) ,
F_35 ( '\0' , L_72 , NULL ,
L_73 , L_74
L_75 V_49 L_76
L_77 V_50 L_78 ,
F_20 ) ,
F_35 ( 'x' , L_6 , NULL , L_79 ,
L_80 , F_13 ) ,
F_34 ( 0 , L_81 , & V_43 . V_51 ,
L_82 ) ,
F_34 ( 0 , L_83 , & V_43 . V_52 ,
L_84 ) ,
F_39 ()
} ;
int V_7 ;
V_16 = F_40 ( V_16 , V_17 , V_38 , V_37 ,
V_53 ) ;
if ( V_16 > 0 ) {
if ( strcmp ( V_17 [ 0 ] , L_85 ) == 0 ) {
F_16 ( L_86 ) ;
F_41 ( V_37 , V_38 ) ;
}
V_7 = F_7 ( V_16 , V_17 ) ;
if ( V_7 < 0 ) {
F_30 ( L_87 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_47 == 0 )
V_4 . V_47 = V_8 ;
if ( ( ! V_4 . V_6 && ! V_4 . V_24 && ! V_4 . V_40 &&
! V_4 . V_28 && ! V_4 . V_48 ) )
F_41 ( V_37 , V_38 ) ;
V_43 . V_54 = ( V_43 . V_44 == NULL ) ;
if ( V_4 . V_40 ) {
if ( V_4 . V_21 ) {
F_3 ( L_88 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( V_4 . V_28 ) {
F_3 ( L_89 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_90 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( V_4 . V_48 ) {
F_3 ( L_91 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( V_4 . V_9 ) {
F_16 ( L_92 ) ;
F_41 ( V_37 , V_38 ) ;
}
V_7 = F_42 () ;
if ( V_7 < 0 )
F_30 ( L_93 , V_7 ) ;
return V_7 ;
}
if ( V_4 . V_48 ) {
if ( V_4 . V_6 != 0 || V_4 . V_24 ) {
F_3 ( L_94
L_95 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( V_4 . V_28 ) {
F_3 ( L_96 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_97 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( ! V_4 . V_33 )
V_4 . V_33 = F_23 ( V_50 ,
NULL ) ;
V_7 = F_43 ( V_4 . V_14 , V_4 . V_33 ,
V_4 . V_9 ) ;
F_22 ( V_4 . V_33 ) ;
V_4 . V_33 = NULL ;
if ( V_7 < 0 )
F_30 ( L_98 , V_7 ) ;
return V_7 ;
}
#ifdef F_14
if ( V_4 . V_28 ) {
if ( V_4 . V_21 ) {
F_3 ( L_99
L_95 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_100 ) ;
F_41 ( V_37 , V_38 ) ;
}
V_7 = F_44 ( & V_4 . V_29 , V_4 . V_14 ,
V_4 . V_9 ) ;
if ( V_7 < 0 )
F_30 ( L_101 , V_7 ) ;
return V_7 ;
}
if ( V_4 . V_31 ) {
if ( V_4 . V_21 ) {
F_3 ( L_102
L_95 ) ;
F_41 ( V_37 , V_38 ) ;
}
if ( ! V_4 . V_33 )
V_4 . V_33 = F_23 ( V_49 ,
NULL ) ;
V_7 = F_45 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_47 ,
V_4 . V_14 ,
V_4 . V_33 ,
V_4 . V_42 ) ;
F_22 ( V_4 . V_33 ) ;
V_4 . V_33 = NULL ;
if ( V_7 < 0 )
F_30 ( L_103 , V_7 ) ;
return V_7 ;
}
#endif
if ( V_4 . V_24 ) {
V_7 = F_46 ( V_4 . V_24 ) ;
if ( V_7 < 0 ) {
F_30 ( L_104 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_6 ) {
V_7 = F_47 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_47 ,
V_4 . V_14 ,
V_4 . V_41 ) ;
if ( V_7 < 0 ) {
F_30 ( L_105 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
int F_48 ( int V_16 , const char * * V_17 , const char * T_3 )
{
int V_7 ;
V_7 = F_24 () ;
if ( ! V_7 ) {
V_7 = F_32 ( V_16 , V_17 , T_3 ) ;
F_26 () ;
}
return V_7 ;
}
