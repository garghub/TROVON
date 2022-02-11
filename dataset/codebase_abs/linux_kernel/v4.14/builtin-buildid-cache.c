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
int V_15 , V_16 = - 1 ;
F_7 ( V_10 , sizeof( V_10 ) , L_1 , V_8 ) ;
F_7 ( V_11 , sizeof( V_11 ) , L_1 , V_9 ) ;
for ( V_15 = 0 ; ( V_12 = V_17 [ V_15 ] ) != NULL ; V_15 ++ ) {
V_16 = F_8 ( V_10 , V_12 , & V_13 ) ;
if ( ! V_16 )
break;
}
if ( V_16 )
return false ;
if ( F_8 ( V_11 , V_12 , & V_14 ) )
return false ;
return V_13 == V_14 ;
}
static int F_9 ( const char * V_8 , char * V_9 ,
T_1 V_18 )
{
char V_10 [ V_4 ] ;
char V_11 [ V_4 ] ;
char V_19 [ V_4 ] ;
struct V_20 * V_21 ;
int V_22 = - 1 ;
T_3 * V_23 ;
V_23 = F_10 ( V_9 ) ;
if ( ! V_23 )
return - 1 ;
F_7 ( V_10 , sizeof( V_10 ) , L_2 , V_8 ) ;
while ( 1 ) {
V_21 = F_11 ( V_23 ) ;
if ( ! V_21 )
break;
if ( V_21 -> V_24 != V_25 )
continue;
F_7 ( V_11 , sizeof( V_11 ) , L_3 , V_9 ,
V_21 -> V_26 ) ;
F_7 ( V_19 , sizeof( V_19 ) , L_4 ,
V_9 , V_21 -> V_26 ) ;
if ( ! F_12 ( V_10 , V_11 ) &&
F_6 ( V_8 , V_19 ) ) {
F_2 ( V_9 , V_19 , V_18 ) ;
V_22 = 0 ;
break;
}
}
F_13 ( V_23 ) ;
return V_22 ;
}
static int F_14 ( const char * V_27 , bool V_28 )
{
char V_6 [ 32 ] , V_2 [ V_29 ] ;
char V_8 [ V_4 ] , V_9 [ V_4 ] ;
char * V_5 ;
F_2 ( V_8 , V_27 , sizeof( V_8 ) ) ;
V_5 = strrchr ( V_8 , '/' ) ;
if ( ! V_5 || strcmp ( V_5 + 1 , L_5 ) )
return - 1 ;
* V_5 = '\0' ;
if ( F_1 ( V_8 , V_2 ) < 0 )
return - 1 ;
F_7 ( V_9 , sizeof( V_9 ) , L_6 ,
V_30 , V_31 , V_2 ) ;
if ( ! V_28 &&
! F_9 ( V_8 , V_9 , sizeof( V_9 ) ) ) {
F_15 ( L_7 , V_9 ) ;
return 0 ;
}
if ( F_4 ( V_6 , sizeof( V_6 ) ) )
return - 1 ;
F_7 ( V_9 , sizeof( V_9 ) , L_8 ,
V_30 , V_31 , V_2 , V_6 ) ;
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
static int F_19 ( const char * V_27 , struct V_32 * V_33 )
{
char V_34 [ V_29 ] ;
T_4 V_35 [ V_36 ] ;
int V_16 ;
struct V_37 V_38 ;
F_20 ( V_33 , & V_38 ) ;
V_16 = F_21 ( V_27 , & V_35 , sizeof( V_35 ) ) ;
F_22 ( & V_38 ) ;
if ( V_16 < 0 ) {
F_15 ( L_10 , V_27 ) ;
return - 1 ;
}
F_23 ( V_35 , sizeof( V_35 ) , V_34 ) ;
V_16 = F_24 ( V_34 , V_27 , V_33 ,
false , false ) ;
F_15 ( L_11 , V_34 , V_27 ,
V_16 ? L_12 : L_13 ) ;
return V_16 ;
}
static int F_25 ( const char * V_27 , struct V_32 * V_33 )
{
T_4 V_35 [ V_36 ] ;
char V_34 [ V_29 ] ;
struct V_37 V_38 ;
int V_16 ;
F_20 ( V_33 , & V_38 ) ;
V_16 = F_21 ( V_27 , & V_35 , sizeof( V_35 ) ) ;
F_22 ( & V_38 ) ;
if ( V_16 < 0 ) {
F_15 ( L_10 , V_27 ) ;
return - 1 ;
}
F_23 ( V_35 , sizeof( V_35 ) , V_34 ) ;
V_16 = F_26 ( V_34 ) ;
F_15 ( L_14 , V_34 , V_27 ,
V_16 ? L_12 : L_13 ) ;
return V_16 ;
}
static int F_27 ( const char * V_39 , struct V_32 * V_33 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_16 ;
V_16 = F_28 ( V_39 , V_33 , & V_41 ) ;
if ( V_16 )
goto V_44;
F_29 (pos, list) {
V_16 = F_26 ( V_43 -> V_45 ) ;
F_15 ( L_14 , V_43 -> V_45 , V_39 ,
V_16 ? L_12 : L_13 ) ;
if ( V_16 )
break;
}
F_30 ( V_41 ) ;
V_44:
F_15 ( L_15 , V_39 , V_16 ? L_12 : L_13 ) ;
return V_16 ;
}
static bool F_31 ( struct V_46 * V_46 , int T_5 V_47 )
{
char V_27 [ V_4 ] ;
T_4 V_35 [ V_36 ] ;
if ( F_32 ( V_46 , V_27 , sizeof( V_27 ) , false ) &&
F_21 ( V_27 , V_35 ,
sizeof( V_35 ) ) != sizeof( V_35 ) ) {
if ( V_48 == V_49 )
return false ;
F_33 ( L_16 ,
V_27 ) ;
} else if ( memcmp ( V_46 -> V_35 , V_35 , sizeof( V_46 -> V_35 ) ) ) {
F_33 ( L_16 ,
V_27 ) ;
}
return true ;
}
static int F_34 ( struct V_50 * V_51 , T_6 * V_52 )
{
F_35 ( V_51 , V_52 , F_31 , 0 ) ;
return 0 ;
}
static int F_36 ( const char * V_27 , struct V_32 * V_33 )
{
T_4 V_35 [ V_36 ] ;
char V_34 [ V_29 ] ;
struct V_37 V_38 ;
int V_16 ;
F_20 ( V_33 , & V_38 ) ;
V_16 = F_21 ( V_27 , & V_35 , sizeof( V_35 ) ) ;
F_22 ( & V_38 ) ;
if ( V_16 < 0 ) {
F_15 ( L_10 , V_27 ) ;
return - 1 ;
}
V_16 = 0 ;
F_23 ( V_35 , sizeof( V_35 ) , V_34 ) ;
if ( F_37 ( V_34 ) )
V_16 = F_26 ( V_34 ) ;
if ( ! V_16 )
V_16 = F_24 ( V_34 , V_27 , V_33 , false ,
false ) ;
F_15 ( L_17 , V_34 , V_27 ,
V_16 ? L_12 : L_13 ) ;
return V_16 ;
}
int F_38 ( int V_53 , const char * * V_54 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_22 = 0 ;
int V_55 = - 1 ;
bool V_28 = false ;
char const * V_56 = NULL ,
* V_57 = NULL ,
* V_58 = NULL ,
* V_59 = NULL ,
* V_60 = NULL ,
* V_61 = NULL ;
char V_62 [ V_63 ] ;
struct V_64 V_65 = {
. V_66 = V_67 ,
} ;
struct V_50 * V_51 = NULL ;
struct V_32 * V_33 = NULL ;
const struct V_68 V_69 [] = {
F_39 ( 'a' , L_18 , & V_56 ,
L_19 , L_20 ) ,
F_39 ( 'k' , L_5 , & V_61 ,
L_21 , L_22 ) ,
F_39 ( 'r' , L_23 , & V_57 , L_19 ,
L_24 ) ,
F_39 ( 'p' , L_25 , & V_58 , L_26 ,
L_27 ) ,
F_39 ( 'M' , L_28 , & V_59 , L_21 ,
L_29 ) ,
F_40 ( 'f' , L_30 , & V_28 , L_31 ) ,
F_39 ( 'u' , L_32 , & V_60 , L_19 ,
L_33 ) ,
F_41 ( 'v' , L_34 , & V_70 , L_35 ) ,
F_42 ( 0 , L_36 , & V_55 , L_37 ) ,
F_43 ()
} ;
const char * const V_71 [] = {
L_38 ,
NULL
} ;
V_53 = F_44 ( V_53 , V_54 , V_69 ,
V_71 , 0 ) ;
if ( V_53 || ( ! V_56 && ! V_61 &&
! V_57 && ! V_58 &&
! V_59 && ! V_60 ) )
F_45 ( V_71 , V_69 ) ;
if ( V_55 > 0 )
V_33 = F_46 ( V_55 ) ;
if ( V_59 ) {
V_65 . V_72 = V_59 ;
V_65 . V_28 = V_28 ;
V_51 = F_47 ( & V_65 , false , NULL ) ;
if ( V_51 == NULL )
return - 1 ;
}
if ( F_48 ( V_51 ? & V_51 -> V_73 . V_74 : NULL ) < 0 )
goto V_44;
F_49 () ;
if ( V_56 ) {
V_41 = F_50 ( V_56 , NULL ) ;
if ( V_41 ) {
F_29 (pos, list)
if ( F_19 ( V_43 -> V_45 , V_33 ) ) {
if ( V_48 == V_75 ) {
F_15 ( L_39 ,
V_43 -> V_45 ) ;
continue;
}
F_33 ( L_40 ,
V_43 -> V_45 , F_51 ( V_48 , V_62 , sizeof( V_62 ) ) ) ;
}
F_30 ( V_41 ) ;
}
}
if ( V_57 ) {
V_41 = F_50 ( V_57 , NULL ) ;
if ( V_41 ) {
F_29 (pos, list)
if ( F_25 ( V_43 -> V_45 , V_33 ) ) {
if ( V_48 == V_49 ) {
F_15 ( L_41 ,
V_43 -> V_45 ) ;
continue;
}
F_33 ( L_42 ,
V_43 -> V_45 , F_51 ( V_48 , V_62 , sizeof( V_62 ) ) ) ;
}
F_30 ( V_41 ) ;
}
}
if ( V_58 ) {
V_41 = F_50 ( V_58 , NULL ) ;
if ( V_41 ) {
F_29 (pos, list)
if ( F_27 ( V_43 -> V_45 , V_33 ) ) {
if ( V_48 == V_49 ) {
F_15 ( L_41 ,
V_43 -> V_45 ) ;
continue;
}
F_33 ( L_42 ,
V_43 -> V_45 , F_51 ( V_48 , V_62 , sizeof( V_62 ) ) ) ;
}
F_30 ( V_41 ) ;
}
}
if ( V_59 )
V_22 = F_34 ( V_51 , stdout ) ;
if ( V_60 ) {
V_41 = F_50 ( V_60 , NULL ) ;
if ( V_41 ) {
F_29 (pos, list)
if ( F_36 ( V_43 -> V_45 , V_33 ) ) {
if ( V_48 == V_49 ) {
F_15 ( L_41 ,
V_43 -> V_45 ) ;
continue;
}
F_33 ( L_43 ,
V_43 -> V_45 , F_51 ( V_48 , V_62 , sizeof( V_62 ) ) ) ;
}
F_30 ( V_41 ) ;
}
}
if ( V_61 && F_14 ( V_61 , V_28 ) )
F_33 ( L_44 , V_61 ) ;
V_44:
F_52 ( V_51 ) ;
F_53 ( V_33 ) ;
return V_22 ;
}
