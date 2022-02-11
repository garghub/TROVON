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
V_4 . V_14 = V_11 ;
V_12 = 1 ;
V_13 = V_11 + ( strlen ( V_11 ) - 3 ) ;
if ( strcmp ( V_13 , L_4 ) )
V_4 . V_9 = true ;
}
return V_12 ;
}
static int F_6 ( int V_15 , const char * * V_16 )
{
int V_17 , V_18 , V_7 , V_19 ;
char * V_13 ;
V_19 = F_5 ( V_16 [ 0 ] ) ;
if ( V_19 && V_15 == 1 )
return 0 ;
V_18 = 0 ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ ) {
if ( V_17 == 0 && V_19 )
continue;
V_18 += strlen ( V_16 [ V_17 ] ) + 1 ;
}
V_13 = F_7 ( V_18 + 1 ) ;
if ( V_13 == NULL )
return - V_20 ;
V_18 = 0 ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ ) {
if ( V_17 == 0 && V_19 )
continue;
V_18 += sprintf ( & V_13 [ V_18 ] , L_5 , V_16 [ V_17 ] ) ;
}
V_4 . V_21 = true ;
V_7 = F_1 ( V_13 ) ;
free ( V_13 ) ;
return V_7 ;
}
static int F_8 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
if ( V_1 ) {
V_4 . V_21 = true ;
return F_1 ( V_1 ) ;
} else
return 0 ;
}
static int F_9 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
if ( V_1 ) {
V_4 . V_21 = true ;
if ( ! V_4 . V_24 )
V_4 . V_24 = F_10 ( true , NULL ) ;
F_11 ( V_4 . V_24 , V_1 ) ;
}
return 0 ;
}
static int F_12 ( const struct V_22 * T_1 , const char * V_1 ,
int T_2 V_23 )
{
int V_7 = - V_25 ;
if ( V_1 && ! V_4 . V_14 ) {
if ( ! strcmp ( T_1 -> V_26 , L_6 ) )
V_4 . V_9 = true ;
#ifdef F_13
else if ( ! strcmp ( T_1 -> V_26 , L_7 ) )
V_4 . V_9 = false ;
#endif
else
return V_7 ;
V_4 . V_14 = V_1 ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_14 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
int V_7 = 0 ;
if ( ! V_1 )
return 0 ;
if ( V_4 . V_27 ) {
F_15 ( L_8
L_9 ) ;
return 0 ;
}
V_4 . V_27 = true ;
V_7 = F_16 ( V_1 , & V_4 . V_28 ) ;
F_17 ( & V_4 . V_28 . V_29 ) ;
return V_7 ;
}
static int F_18 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
struct V_2 * V_3 = & V_4 . V_5 [ V_4 . V_6 ] ;
int V_7 ;
if ( ! V_1 )
return 0 ;
V_7 = F_1 ( V_1 ) ;
if ( ! V_7 && V_3 -> V_10 != 0 ) {
F_3 ( L_10 ) ;
return - V_30 ;
}
V_4 . V_31 = true ;
return V_7 ;
}
static int F_19 ( const struct V_22 * T_1 V_23 ,
const char * V_1 , int T_2 V_23 )
{
const char * V_32 ;
if ( V_1 ) {
F_20 ( L_11 , V_1 ) ;
if ( V_4 . V_33 )
F_21 ( V_4 . V_33 ) ;
V_4 . V_33 = F_22 ( V_1 , & V_32 ) ;
if ( ! V_4 . V_33 ) {
F_3 ( L_12 , V_32 - V_1 + 1 ) ;
F_3 ( L_13 , V_1 ) ;
F_3 ( L_14 , ( int ) ( V_32 - V_1 + 1 ) , '^' ) ;
return - V_30 ;
}
}
return 0 ;
}
int F_23 ( int V_15 , const char * * V_16 , const char * T_3 V_23 )
{
const char * const V_34 [] = {
L_15 ,
L_16 ,
L_17 ,
L_18 ,
#ifdef F_13
L_19 ,
L_20 ,
#endif
NULL
} ;
const struct V_22 V_35 [] = {
F_24 ( 'v' , L_21 , & V_36 ,
L_22 ) ,
F_25 ( 'l' , L_23 , & V_4 . V_37 ,
L_24 ) ,
F_26 ( 'd' , L_25 , NULL , L_26 , L_27 ,
F_9 ) ,
F_26 ( 'a' , L_28 , NULL ,
#ifdef F_13
L_29
L_30 ,
#else
L_31 ,
#endif
L_32
L_33
L_34
L_35
L_36
L_37
#ifdef F_13
L_38
L_39
L_40
L_41
L_42
L_43 ,
#else
L_44 ,
#endif
F_8 ) ,
F_25 ( 'f' , L_45 , & V_4 . V_38 , L_46
L_47 ) ,
#ifdef F_13
F_26 ( 'L' , L_48 , NULL ,
L_49 ,
L_50 , F_14 ) ,
F_26 ( 'V' , L_51 , NULL ,
L_52 ,
L_53 , F_18 ) ,
F_25 ( '\0' , L_54 , & V_4 . V_39 ,
L_55 ) ,
F_27 ( 'k' , L_56 , & V_40 . V_41 ,
L_57 , L_58 ) ,
F_27 ( 's' , L_59 , & V_40 . V_42 ,
L_60 , L_61 ) ,
F_26 ( 'm' , L_7 , NULL , L_62 ,
L_63 ,
F_12 ) ,
#endif
F_28 ( & V_43 ) ,
F_29 ( '\0' , L_64 , & V_4 . V_44 ,
L_65 ) ,
F_25 ( 'F' , L_66 , & V_4 . V_45 ,
L_67 ) ,
F_26 ( '\0' , L_68 , NULL ,
L_69 , L_70
L_71 V_46 L_72
L_73 V_47 L_74 ,
F_19 ) ,
F_26 ( 'x' , L_6 , NULL , L_75 ,
L_76 , F_12 ) ,
F_30 ()
} ;
int V_7 ;
V_15 = F_31 ( V_15 , V_16 , V_35 , V_34 ,
V_48 ) ;
if ( V_15 > 0 ) {
if ( strcmp ( V_16 [ 0 ] , L_77 ) == 0 ) {
F_15 ( L_78 ) ;
F_32 ( V_34 , V_35 ) ;
}
V_7 = F_6 ( V_15 , V_16 ) ;
if ( V_7 < 0 ) {
F_3 ( L_79 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_44 == 0 )
V_4 . V_44 = V_8 ;
if ( ( ! V_4 . V_6 && ! V_4 . V_24 && ! V_4 . V_37 &&
! V_4 . V_27 && ! V_4 . V_45 ) )
F_32 ( V_34 , V_35 ) ;
V_40 . V_49 = ( V_40 . V_41 == NULL ) ;
if ( V_4 . V_37 ) {
if ( V_4 . V_21 ) {
F_3 ( L_80 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( V_4 . V_27 ) {
F_3 ( L_81 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_82 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( V_4 . V_45 ) {
F_3 ( L_83 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( V_4 . V_9 ) {
F_15 ( L_84 ) ;
F_32 ( V_34 , V_35 ) ;
}
V_7 = F_33 () ;
if ( V_7 < 0 )
F_3 ( L_85 ,
V_7 ) ;
return V_7 ;
}
if ( V_4 . V_45 ) {
if ( V_4 . V_6 != 0 || V_4 . V_24 ) {
F_3 ( L_86
L_87 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( V_4 . V_27 ) {
F_3 ( L_88 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_89 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( ! V_4 . V_33 )
V_4 . V_33 = F_22 ( V_47 ,
NULL ) ;
V_7 = F_34 ( V_4 . V_14 , V_4 . V_33 ,
V_4 . V_9 ) ;
F_21 ( V_4 . V_33 ) ;
if ( V_7 < 0 )
F_3 ( L_90
L_91 , V_7 ) ;
return V_7 ;
}
#ifdef F_13
if ( V_4 . V_27 && ! V_4 . V_9 ) {
if ( V_4 . V_21 ) {
F_3 ( L_92
L_87 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( V_4 . V_31 ) {
F_3 ( L_93 ) ;
F_32 ( V_34 , V_35 ) ;
}
V_7 = F_35 ( & V_4 . V_28 , V_4 . V_14 ) ;
if ( V_7 < 0 )
F_3 ( L_94 , V_7 ) ;
return V_7 ;
}
if ( V_4 . V_31 ) {
if ( V_4 . V_21 ) {
F_3 ( L_95
L_87 ) ;
F_32 ( V_34 , V_35 ) ;
}
if ( ! V_4 . V_33 )
V_4 . V_33 = F_22 ( V_46 ,
NULL ) ;
V_7 = F_36 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_44 ,
V_4 . V_14 ,
V_4 . V_33 ,
V_4 . V_39 ) ;
F_21 ( V_4 . V_33 ) ;
if ( V_7 < 0 )
F_3 ( L_96 , V_7 ) ;
return V_7 ;
}
#endif
if ( V_4 . V_24 ) {
V_7 = F_37 ( V_4 . V_24 ) ;
F_38 ( V_4 . V_24 ) ;
if ( V_7 < 0 ) {
F_3 ( L_97 , V_7 ) ;
return V_7 ;
}
}
if ( V_4 . V_6 ) {
V_7 = F_39 ( V_4 . V_5 , V_4 . V_6 ,
V_4 . V_44 ,
V_4 . V_14 ,
V_4 . V_38 ) ;
if ( V_7 < 0 ) {
F_3 ( L_98 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
