static int F_1 ( const char * V_1 , char * V_2 )
{
char V_3 [ V_4 ] ;
char V_5 [ V_4 ] ;
T_1 V_6 [ V_7 ] ;
char * V_8 ;
F_2 ( V_3 , V_1 , sizeof( V_3 ) ) ;
V_8 = strrchr ( V_3 , '/' ) ;
if ( ! V_8 )
return - 1 ;
* V_8 = '\0' ;
F_3 ( V_5 , sizeof( V_5 ) , L_1 , V_3 ) ;
if ( F_4 ( V_5 , V_6 , sizeof( V_6 ) ) )
return - 1 ;
F_5 ( V_6 , sizeof( V_6 ) , V_2 ) ;
return 0 ;
}
static int F_6 ( char * V_9 , T_2 V_10 )
{
struct V_11 V_12 ;
struct V_13 V_13 ;
char V_14 [ 32 ] ;
if ( F_7 ( & V_12 , NULL ) || ! localtime_r ( & V_12 . V_15 , & V_13 ) )
return - 1 ;
if ( ! strftime ( V_14 , sizeof( V_14 ) , L_2 , & V_13 ) )
return - 1 ;
F_3 ( V_9 , V_10 , L_3 , V_14 , ( unsigned ) V_12 . V_16 / 10000 ) ;
return 0 ;
}
static bool F_8 ( const char * V_17 , char * V_18 )
{
char V_19 [ V_4 ] ;
char V_20 [ V_4 ] ;
const char * V_21 ;
T_3 V_22 = 0 , V_23 = 0 ;
int V_24 ;
F_3 ( V_19 , sizeof( V_19 ) , L_4 , V_17 ) ;
F_3 ( V_20 , sizeof( V_20 ) , L_4 , V_18 ) ;
for ( V_24 = 0 ; ( V_21 = V_25 [ V_24 ] ) != NULL ; V_24 ++ ) {
V_22 = F_9 ( V_19 , V_21 ) ;
if ( V_22 )
break;
}
if ( V_21 )
V_23 = F_9 ( V_20 , V_21 ) ;
return V_22 == V_23 ;
}
static int F_10 ( const char * V_17 , char * V_18 ,
T_2 V_26 )
{
char V_19 [ V_4 ] ;
char V_20 [ V_4 ] ;
char V_27 [ V_4 ] ;
struct V_28 * V_29 ;
int V_30 = - 1 ;
T_4 * V_31 ;
V_31 = F_11 ( V_18 ) ;
if ( ! V_31 )
return - 1 ;
F_3 ( V_19 , sizeof( V_19 ) , L_5 , V_17 ) ;
while ( 1 ) {
V_29 = F_12 ( V_31 ) ;
if ( ! V_29 )
break;
if ( V_29 -> V_32 != V_33 )
continue;
F_3 ( V_20 , sizeof( V_20 ) , L_6 , V_18 ,
V_29 -> V_34 ) ;
F_3 ( V_27 , sizeof( V_27 ) , L_7 ,
V_18 , V_29 -> V_34 ) ;
if ( ! F_13 ( V_19 , V_20 ) &&
F_8 ( V_17 , V_27 ) ) {
F_2 ( V_18 , V_27 , V_26 ) ;
V_30 = 0 ;
break;
}
}
F_14 ( V_31 ) ;
return V_30 ;
}
static int F_15 ( const char * V_35 , const char * V_36 ,
bool V_37 )
{
char V_9 [ 32 ] , V_2 [ V_7 * 2 + 1 ] ;
char V_17 [ V_4 ] , V_18 [ V_4 ] ;
char * V_8 ;
F_2 ( V_17 , V_35 , sizeof( V_17 ) ) ;
V_8 = strrchr ( V_17 , '/' ) ;
if ( ! V_8 || strcmp ( V_8 + 1 , L_8 ) )
return - 1 ;
* V_8 = '\0' ;
if ( F_1 ( V_17 , V_2 ) )
return - 1 ;
F_3 ( V_18 , sizeof( V_18 ) , L_9 ,
V_36 , V_2 ) ;
if ( ! V_37 &&
! F_10 ( V_17 , V_18 , sizeof( V_18 ) ) ) {
F_16 ( L_10 , V_18 ) ;
return 0 ;
}
if ( F_6 ( V_9 , sizeof( V_9 ) ) )
return - 1 ;
F_3 ( V_18 , sizeof( V_18 ) , L_11 ,
V_36 , V_2 , V_9 ) ;
if ( F_17 ( V_18 , 0755 ) )
return - 1 ;
if ( F_18 ( V_17 , V_18 ) ) {
if ( ! F_19 ( V_18 ) ) {
V_8 = strrchr ( V_18 , '/' ) ;
if ( V_8 )
* V_8 = '\0' ;
if ( ! F_19 ( V_18 ) ) {
V_8 = strrchr ( V_18 , '/' ) ;
if ( V_8 )
* V_8 = '\0' ;
F_19 ( V_18 ) ;
}
}
return - 1 ;
}
F_16 ( L_12 , V_18 ) ;
return 0 ;
}
static int F_20 ( const char * V_35 , const char * V_36 )
{
char V_38 [ V_7 * 2 + 1 ] ;
T_1 V_6 [ V_7 ] ;
int V_39 ;
if ( F_21 ( V_35 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_16 ( L_13 , V_35 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_38 ) ;
V_39 = F_22 ( V_38 , V_36 , V_35 ,
false , false ) ;
if ( V_40 )
F_23 ( L_14 , V_38 , V_35 ,
V_39 ? L_15 : L_16 ) ;
return V_39 ;
}
static int F_24 ( const char * V_35 ,
const char * V_36 )
{
T_1 V_6 [ V_7 ] ;
char V_38 [ V_7 * 2 + 1 ] ;
int V_39 ;
if ( F_21 ( V_35 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_16 ( L_13 , V_35 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_38 ) ;
V_39 = F_25 ( V_38 , V_36 ) ;
if ( V_40 )
F_23 ( L_17 , V_38 , V_35 ,
V_39 ? L_15 : L_16 ) ;
return V_39 ;
}
static bool F_26 ( struct V_41 * V_41 , int T_5 V_42 )
{
char V_35 [ V_4 ] ;
T_1 V_6 [ V_7 ] ;
if ( F_27 ( V_41 , V_35 , sizeof( V_35 ) ) &&
F_21 ( V_35 , V_6 ,
sizeof( V_6 ) ) != sizeof( V_6 ) ) {
if ( V_43 == V_44 )
return false ;
F_28 ( L_18 ,
V_35 ) ;
} else if ( memcmp ( V_41 -> V_6 , V_6 , sizeof( V_41 -> V_6 ) ) ) {
F_28 ( L_18 ,
V_35 ) ;
}
return true ;
}
static int F_29 ( struct V_45 * V_46 , T_6 * V_47 )
{
F_30 ( V_46 , V_47 , F_26 , 0 ) ;
return 0 ;
}
static int F_31 ( const char * V_35 ,
const char * V_36 )
{
T_1 V_6 [ V_7 ] ;
char V_38 [ V_7 * 2 + 1 ] ;
int V_39 ;
if ( F_21 ( V_35 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_16 ( L_13 , V_35 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_38 ) ;
V_39 = F_25 ( V_38 , V_36 ) ;
if ( ! V_39 ) {
V_39 = F_22 ( V_38 , V_36 , V_35 ,
false , false ) ;
}
if ( V_40 )
F_23 ( L_19 , V_38 , V_35 ,
V_39 ? L_15 : L_16 ) ;
return V_39 ;
}
int F_32 ( int V_48 , const char * * V_49 ,
const char * T_7 V_42 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_30 = 0 ;
bool V_37 = false ;
char const * V_54 = NULL ,
* V_55 = NULL ,
* V_56 = NULL ,
* V_57 = NULL ,
* V_58 = NULL ;
char V_59 [ V_60 ] ;
struct V_61 V_62 = {
. V_63 = V_64 ,
} ;
struct V_45 * V_46 = NULL ;
const struct V_65 V_66 [] = {
F_33 ( 'a' , L_20 , & V_54 ,
L_21 , L_22 ) ,
F_33 ( 'k' , L_8 , & V_58 ,
L_23 , L_24 ) ,
F_33 ( 'r' , L_25 , & V_55 , L_21 ,
L_26 ) ,
F_33 ( 'M' , L_27 , & V_56 , L_23 ,
L_28 ) ,
F_34 ( 'f' , L_29 , & V_37 , L_30 ) ,
F_33 ( 'u' , L_31 , & V_57 , L_21 ,
L_32 ) ,
F_35 ( 'v' , L_33 , & V_40 , L_34 ) ,
F_36 ()
} ;
const char * const V_67 [] = {
L_35 ,
NULL
} ;
V_48 = F_37 ( V_48 , V_49 , V_66 ,
V_67 , 0 ) ;
if ( V_56 ) {
V_62 . V_68 = V_56 ;
V_62 . V_37 = V_37 ;
V_46 = F_38 ( & V_62 , false , NULL ) ;
if ( V_46 == NULL )
return - 1 ;
}
if ( F_39 ( V_46 ? & V_46 -> V_69 . V_70 : NULL ) < 0 )
goto V_71;
F_40 () ;
if ( V_54 ) {
V_51 = F_41 ( true , V_54 ) ;
if ( V_51 ) {
F_42 (pos, list)
if ( F_20 ( V_53 -> V_72 , V_73 ) ) {
if ( V_43 == V_74 ) {
F_16 ( L_36 ,
V_53 -> V_72 ) ;
continue;
}
F_28 ( L_37 ,
V_53 -> V_72 , F_43 ( V_43 , V_59 , sizeof( V_59 ) ) ) ;
}
F_44 ( V_51 ) ;
}
}
if ( V_55 ) {
V_51 = F_41 ( true , V_55 ) ;
if ( V_51 ) {
F_42 (pos, list)
if ( F_24 ( V_53 -> V_72 , V_73 ) ) {
if ( V_43 == V_44 ) {
F_16 ( L_38 ,
V_53 -> V_72 ) ;
continue;
}
F_28 ( L_39 ,
V_53 -> V_72 , F_43 ( V_43 , V_59 , sizeof( V_59 ) ) ) ;
}
F_44 ( V_51 ) ;
}
}
if ( V_56 )
V_30 = F_29 ( V_46 , stdout ) ;
if ( V_57 ) {
V_51 = F_41 ( true , V_57 ) ;
if ( V_51 ) {
F_42 (pos, list)
if ( F_31 ( V_53 -> V_72 , V_73 ) ) {
if ( V_43 == V_44 ) {
F_16 ( L_38 ,
V_53 -> V_72 ) ;
continue;
}
F_28 ( L_40 ,
V_53 -> V_72 , F_43 ( V_43 , V_59 , sizeof( V_59 ) ) ) ;
}
F_44 ( V_51 ) ;
}
}
if ( V_58 &&
F_15 ( V_58 , V_73 , V_37 ) )
F_28 ( L_41 , V_58 ) ;
V_71:
if ( V_46 )
F_45 ( V_46 ) ;
return V_30 ;
}
