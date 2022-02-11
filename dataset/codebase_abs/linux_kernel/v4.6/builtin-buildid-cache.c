static int F_1 ( const char * V_1 , char * V_2 )
{
char V_3 [ V_4 ] ;
char * V_5 ;
F_2 ( V_3 , V_1 , sizeof( V_3 ) ) ;
V_5 = strrchr ( V_3 , '/' ) ;
if ( ! V_5 )
return - 1 ;
* V_5 = '\0' ;
return F_3 ( V_3 , V_2 ) ;
}
static int F_4 ( char * V_6 , T_1 V_7 )
{
return F_5 ( V_6 , V_7 ) ;
}
static bool F_6 ( const char * V_8 , char * V_9 )
{
char V_10 [ V_4 ] ;
char V_11 [ V_4 ] ;
const char * V_12 ;
T_2 V_13 = 0 , V_14 = 0 ;
int V_15 ;
F_7 ( V_10 , sizeof( V_10 ) , L_1 , V_8 ) ;
F_7 ( V_11 , sizeof( V_11 ) , L_1 , V_9 ) ;
for ( V_15 = 0 ; ( V_12 = V_16 [ V_15 ] ) != NULL ; V_15 ++ ) {
V_13 = F_8 ( V_10 , V_12 ) ;
if ( V_13 )
break;
}
if ( V_12 )
V_14 = F_8 ( V_11 , V_12 ) ;
return V_13 == V_14 ;
}
static int F_9 ( const char * V_8 , char * V_9 ,
T_1 V_17 )
{
char V_10 [ V_4 ] ;
char V_11 [ V_4 ] ;
char V_18 [ V_4 ] ;
struct V_19 * V_20 ;
int V_21 = - 1 ;
T_3 * V_22 ;
V_22 = F_10 ( V_9 ) ;
if ( ! V_22 )
return - 1 ;
F_7 ( V_10 , sizeof( V_10 ) , L_2 , V_8 ) ;
while ( 1 ) {
V_20 = F_11 ( V_22 ) ;
if ( ! V_20 )
break;
if ( V_20 -> V_23 != V_24 )
continue;
F_7 ( V_11 , sizeof( V_11 ) , L_3 , V_9 ,
V_20 -> V_25 ) ;
F_7 ( V_18 , sizeof( V_18 ) , L_4 ,
V_9 , V_20 -> V_25 ) ;
if ( ! F_12 ( V_10 , V_11 ) &&
F_6 ( V_8 , V_18 ) ) {
F_2 ( V_9 , V_18 , V_17 ) ;
V_21 = 0 ;
break;
}
}
F_13 ( V_22 ) ;
return V_21 ;
}
static int F_14 ( const char * V_26 , bool V_27 )
{
char V_6 [ 32 ] , V_2 [ V_28 ] ;
char V_8 [ V_4 ] , V_9 [ V_4 ] ;
char * V_5 ;
F_2 ( V_8 , V_26 , sizeof( V_8 ) ) ;
V_5 = strrchr ( V_8 , '/' ) ;
if ( ! V_5 || strcmp ( V_5 + 1 , L_5 ) )
return - 1 ;
* V_5 = '\0' ;
if ( F_1 ( V_8 , V_2 ) < 0 )
return - 1 ;
F_7 ( V_9 , sizeof( V_9 ) , L_6 ,
V_29 , V_2 ) ;
if ( ! V_27 &&
! F_9 ( V_8 , V_9 , sizeof( V_9 ) ) ) {
F_15 ( L_7 , V_9 ) ;
return 0 ;
}
if ( F_4 ( V_6 , sizeof( V_6 ) ) )
return - 1 ;
F_7 ( V_9 , sizeof( V_9 ) , L_8 ,
V_29 , V_2 , V_6 ) ;
if ( F_16 ( V_9 , 0755 ) )
return - 1 ;
if ( F_17 ( V_8 , V_9 ) ) {
if ( ! F_18 ( V_9 ) ) {
V_5 = strrchr ( V_9 , '/' ) ;
if ( V_5 )
* V_5 = '\0' ;
if ( ! F_18 ( V_9 ) ) {
V_5 = strrchr ( V_9 , '/' ) ;
if ( V_5 )
* V_5 = '\0' ;
F_18 ( V_9 ) ;
}
}
return - 1 ;
}
F_15 ( L_9 , V_9 ) ;
return 0 ;
}
static int F_19 ( const char * V_26 )
{
char V_30 [ V_28 ] ;
T_4 V_31 [ V_32 ] ;
int V_33 ;
if ( F_20 ( V_26 , & V_31 , sizeof( V_31 ) ) < 0 ) {
F_15 ( L_10 , V_26 ) ;
return - 1 ;
}
F_21 ( V_31 , sizeof( V_31 ) , V_30 ) ;
V_33 = F_22 ( V_30 , V_26 ,
false , false ) ;
F_15 ( L_11 , V_30 , V_26 ,
V_33 ? L_12 : L_13 ) ;
return V_33 ;
}
static int F_23 ( const char * V_26 )
{
T_4 V_31 [ V_32 ] ;
char V_30 [ V_28 ] ;
int V_33 ;
if ( F_20 ( V_26 , & V_31 , sizeof( V_31 ) ) < 0 ) {
F_15 ( L_10 , V_26 ) ;
return - 1 ;
}
F_21 ( V_31 , sizeof( V_31 ) , V_30 ) ;
V_33 = F_24 ( V_30 ) ;
F_15 ( L_14 , V_30 , V_26 ,
V_33 ? L_12 : L_13 ) ;
return V_33 ;
}
static int F_25 ( const char * V_34 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
int V_33 ;
V_33 = F_26 ( V_34 , & V_36 ) ;
if ( V_33 )
goto V_39;
F_27 (pos, list) {
V_33 = F_24 ( V_38 -> V_40 ) ;
F_15 ( L_14 , V_38 -> V_40 , V_34 ,
V_33 ? L_12 : L_13 ) ;
if ( V_33 )
break;
}
F_28 ( V_36 ) ;
V_39:
F_15 ( L_15 , V_34 , V_33 ? L_12 : L_13 ) ;
return V_33 ;
}
static bool F_29 ( struct V_41 * V_41 , int T_5 V_42 )
{
char V_26 [ V_4 ] ;
T_4 V_31 [ V_32 ] ;
if ( F_30 ( V_41 , V_26 , sizeof( V_26 ) ) &&
F_20 ( V_26 , V_31 ,
sizeof( V_31 ) ) != sizeof( V_31 ) ) {
if ( V_43 == V_44 )
return false ;
F_31 ( L_16 ,
V_26 ) ;
} else if ( memcmp ( V_41 -> V_31 , V_31 , sizeof( V_41 -> V_31 ) ) ) {
F_31 ( L_16 ,
V_26 ) ;
}
return true ;
}
static int F_32 ( struct V_45 * V_46 , T_6 * V_47 )
{
F_33 ( V_46 , V_47 , F_29 , 0 ) ;
return 0 ;
}
static int F_34 ( const char * V_26 )
{
T_4 V_31 [ V_32 ] ;
char V_30 [ V_28 ] ;
int V_33 = 0 ;
if ( F_20 ( V_26 , & V_31 , sizeof( V_31 ) ) < 0 ) {
F_15 ( L_10 , V_26 ) ;
return - 1 ;
}
F_21 ( V_31 , sizeof( V_31 ) , V_30 ) ;
if ( F_35 ( V_30 ) )
V_33 = F_24 ( V_30 ) ;
if ( ! V_33 )
V_33 = F_22 ( V_30 , V_26 , false , false ) ;
F_15 ( L_17 , V_30 , V_26 ,
V_33 ? L_12 : L_13 ) ;
return V_33 ;
}
int F_36 ( int V_48 , const char * * V_49 ,
const char * T_7 V_42 )
{
struct V_35 * V_36 ;
struct V_37 * V_38 ;
int V_21 = 0 ;
bool V_27 = false ;
char const * V_50 = NULL ,
* V_51 = NULL ,
* V_52 = NULL ,
* V_53 = NULL ,
* V_54 = NULL ,
* V_55 = NULL ;
char V_56 [ V_57 ] ;
struct V_58 V_59 = {
. V_60 = V_61 ,
} ;
struct V_45 * V_46 = NULL ;
const struct V_62 V_63 [] = {
F_37 ( 'a' , L_18 , & V_50 ,
L_19 , L_20 ) ,
F_37 ( 'k' , L_5 , & V_55 ,
L_21 , L_22 ) ,
F_37 ( 'r' , L_23 , & V_51 , L_19 ,
L_24 ) ,
F_37 ( 'p' , L_25 , & V_52 , L_26 ,
L_27 ) ,
F_37 ( 'M' , L_28 , & V_53 , L_21 ,
L_29 ) ,
F_38 ( 'f' , L_30 , & V_27 , L_31 ) ,
F_37 ( 'u' , L_32 , & V_54 , L_19 ,
L_33 ) ,
F_39 ( 'v' , L_34 , & V_64 , L_35 ) ,
F_40 ()
} ;
const char * const V_65 [] = {
L_36 ,
NULL
} ;
V_48 = F_41 ( V_48 , V_49 , V_63 ,
V_65 , 0 ) ;
if ( V_48 || ( ! V_50 && ! V_55 &&
! V_51 && ! V_52 &&
! V_53 && ! V_54 ) )
F_42 ( V_65 , V_63 ) ;
if ( V_53 ) {
V_59 . V_66 = V_53 ;
V_59 . V_27 = V_27 ;
V_46 = F_43 ( & V_59 , false , NULL ) ;
if ( V_46 == NULL )
return - 1 ;
}
if ( F_44 ( V_46 ? & V_46 -> V_67 . V_68 : NULL ) < 0 )
goto V_39;
F_45 () ;
if ( V_50 ) {
V_36 = F_46 ( V_50 , NULL ) ;
if ( V_36 ) {
F_27 (pos, list)
if ( F_19 ( V_38 -> V_40 ) ) {
if ( V_43 == V_69 ) {
F_15 ( L_37 ,
V_38 -> V_40 ) ;
continue;
}
F_31 ( L_38 ,
V_38 -> V_40 , F_47 ( V_43 , V_56 , sizeof( V_56 ) ) ) ;
}
F_28 ( V_36 ) ;
}
}
if ( V_51 ) {
V_36 = F_46 ( V_51 , NULL ) ;
if ( V_36 ) {
F_27 (pos, list)
if ( F_23 ( V_38 -> V_40 ) ) {
if ( V_43 == V_44 ) {
F_15 ( L_39 ,
V_38 -> V_40 ) ;
continue;
}
F_31 ( L_40 ,
V_38 -> V_40 , F_47 ( V_43 , V_56 , sizeof( V_56 ) ) ) ;
}
F_28 ( V_36 ) ;
}
}
if ( V_52 ) {
V_36 = F_46 ( V_52 , NULL ) ;
if ( V_36 ) {
F_27 (pos, list)
if ( F_25 ( V_38 -> V_40 ) ) {
if ( V_43 == V_44 ) {
F_15 ( L_39 ,
V_38 -> V_40 ) ;
continue;
}
F_31 ( L_40 ,
V_38 -> V_40 , F_47 ( V_43 , V_56 , sizeof( V_56 ) ) ) ;
}
F_28 ( V_36 ) ;
}
}
if ( V_53 )
V_21 = F_32 ( V_46 , stdout ) ;
if ( V_54 ) {
V_36 = F_46 ( V_54 , NULL ) ;
if ( V_36 ) {
F_27 (pos, list)
if ( F_34 ( V_38 -> V_40 ) ) {
if ( V_43 == V_44 ) {
F_15 ( L_39 ,
V_38 -> V_40 ) ;
continue;
}
F_31 ( L_41 ,
V_38 -> V_40 , F_47 ( V_43 , V_56 , sizeof( V_56 ) ) ) ;
}
F_28 ( V_36 ) ;
}
}
if ( V_55 && F_14 ( V_55 , V_27 ) )
F_31 ( L_42 , V_55 ) ;
V_39:
if ( V_46 )
F_48 ( V_46 ) ;
return V_21 ;
}
