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
static int F_15 ( const char * V_35 , bool V_36 )
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
V_37 , V_2 ) ;
if ( ! V_36 &&
! F_10 ( V_17 , V_18 , sizeof( V_18 ) ) ) {
F_16 ( L_10 , V_18 ) ;
return 0 ;
}
if ( F_6 ( V_9 , sizeof( V_9 ) ) )
return - 1 ;
F_3 ( V_18 , sizeof( V_18 ) , L_11 ,
V_37 , V_2 , V_9 ) ;
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
static int F_20 ( const char * V_35 )
{
char V_38 [ V_7 * 2 + 1 ] ;
T_1 V_6 [ V_7 ] ;
int V_39 ;
if ( F_21 ( V_35 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_16 ( L_13 , V_35 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_38 ) ;
V_39 = F_22 ( V_38 , V_35 ,
false , false ) ;
F_16 ( L_14 , V_38 , V_35 ,
V_39 ? L_15 : L_16 ) ;
return V_39 ;
}
static int F_23 ( const char * V_35 )
{
T_1 V_6 [ V_7 ] ;
char V_38 [ V_7 * 2 + 1 ] ;
int V_39 ;
if ( F_21 ( V_35 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_16 ( L_13 , V_35 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_38 ) ;
V_39 = F_24 ( V_38 ) ;
F_16 ( L_17 , V_38 , V_35 ,
V_39 ? L_15 : L_16 ) ;
return V_39 ;
}
static int F_25 ( const char * V_40 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_39 ;
V_39 = F_26 ( V_40 , & V_42 ) ;
if ( V_39 )
goto V_45;
F_27 (pos, list) {
V_39 = F_24 ( V_44 -> V_46 ) ;
F_16 ( L_17 , V_44 -> V_46 , V_40 ,
V_39 ? L_15 : L_16 ) ;
if ( V_39 )
break;
}
F_28 ( V_42 ) ;
V_45:
F_16 ( L_18 , V_40 , V_39 ? L_15 : L_16 ) ;
return V_39 ;
}
static bool F_29 ( struct V_47 * V_47 , int T_5 V_48 )
{
char V_35 [ V_4 ] ;
T_1 V_6 [ V_7 ] ;
if ( F_30 ( V_47 , V_35 , sizeof( V_35 ) ) &&
F_21 ( V_35 , V_6 ,
sizeof( V_6 ) ) != sizeof( V_6 ) ) {
if ( V_49 == V_50 )
return false ;
F_31 ( L_19 ,
V_35 ) ;
} else if ( memcmp ( V_47 -> V_6 , V_6 , sizeof( V_47 -> V_6 ) ) ) {
F_31 ( L_19 ,
V_35 ) ;
}
return true ;
}
static int F_32 ( struct V_51 * V_52 , T_6 * V_53 )
{
F_33 ( V_52 , V_53 , F_29 , 0 ) ;
return 0 ;
}
static int F_34 ( const char * V_35 )
{
T_1 V_6 [ V_7 ] ;
char V_38 [ V_7 * 2 + 1 ] ;
int V_39 = 0 ;
if ( F_21 ( V_35 , & V_6 , sizeof( V_6 ) ) < 0 ) {
F_16 ( L_13 , V_35 ) ;
return - 1 ;
}
F_5 ( V_6 , sizeof( V_6 ) , V_38 ) ;
if ( F_35 ( V_38 ) )
V_39 = F_24 ( V_38 ) ;
if ( ! V_39 )
V_39 = F_22 ( V_38 , V_35 , false , false ) ;
F_16 ( L_20 , V_38 , V_35 ,
V_39 ? L_15 : L_16 ) ;
return V_39 ;
}
int F_36 ( int V_54 , const char * * V_55 ,
const char * T_7 V_48 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_30 = 0 ;
bool V_36 = false ;
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
struct V_51 * V_52 = NULL ;
const struct V_68 V_69 [] = {
F_37 ( 'a' , L_21 , & V_56 ,
L_22 , L_23 ) ,
F_37 ( 'k' , L_8 , & V_61 ,
L_24 , L_25 ) ,
F_37 ( 'r' , L_26 , & V_57 , L_22 ,
L_27 ) ,
F_37 ( 'p' , L_28 , & V_58 , L_29 ,
L_30 ) ,
F_37 ( 'M' , L_31 , & V_59 , L_24 ,
L_32 ) ,
F_38 ( 'f' , L_33 , & V_36 , L_34 ) ,
F_37 ( 'u' , L_35 , & V_60 , L_22 ,
L_36 ) ,
F_39 ( 'v' , L_37 , & V_70 , L_38 ) ,
F_40 ()
} ;
const char * const V_71 [] = {
L_39 ,
NULL
} ;
V_54 = F_41 ( V_54 , V_55 , V_69 ,
V_71 , 0 ) ;
if ( V_54 || ( ! V_56 && ! V_61 &&
! V_57 && ! V_58 &&
! V_59 && ! V_60 ) )
F_42 ( V_71 , V_69 ) ;
if ( V_59 ) {
V_65 . V_72 = V_59 ;
V_65 . V_36 = V_36 ;
V_52 = F_43 ( & V_65 , false , NULL ) ;
if ( V_52 == NULL )
return - 1 ;
}
if ( F_44 ( V_52 ? & V_52 -> V_73 . V_74 : NULL ) < 0 )
goto V_45;
F_45 () ;
if ( V_56 ) {
V_42 = F_46 ( true , V_56 ) ;
if ( V_42 ) {
F_27 (pos, list)
if ( F_20 ( V_44 -> V_46 ) ) {
if ( V_49 == V_75 ) {
F_16 ( L_40 ,
V_44 -> V_46 ) ;
continue;
}
F_31 ( L_41 ,
V_44 -> V_46 , F_47 ( V_49 , V_62 , sizeof( V_62 ) ) ) ;
}
F_28 ( V_42 ) ;
}
}
if ( V_57 ) {
V_42 = F_46 ( true , V_57 ) ;
if ( V_42 ) {
F_27 (pos, list)
if ( F_23 ( V_44 -> V_46 ) ) {
if ( V_49 == V_50 ) {
F_16 ( L_42 ,
V_44 -> V_46 ) ;
continue;
}
F_31 ( L_43 ,
V_44 -> V_46 , F_47 ( V_49 , V_62 , sizeof( V_62 ) ) ) ;
}
F_28 ( V_42 ) ;
}
}
if ( V_58 ) {
V_42 = F_46 ( true , V_58 ) ;
if ( V_42 ) {
F_27 (pos, list)
if ( F_25 ( V_44 -> V_46 ) ) {
if ( V_49 == V_50 ) {
F_16 ( L_42 ,
V_44 -> V_46 ) ;
continue;
}
F_31 ( L_43 ,
V_44 -> V_46 , F_47 ( V_49 , V_62 , sizeof( V_62 ) ) ) ;
}
F_28 ( V_42 ) ;
}
}
if ( V_59 )
V_30 = F_32 ( V_52 , stdout ) ;
if ( V_60 ) {
V_42 = F_46 ( true , V_60 ) ;
if ( V_42 ) {
F_27 (pos, list)
if ( F_34 ( V_44 -> V_46 ) ) {
if ( V_49 == V_50 ) {
F_16 ( L_42 ,
V_44 -> V_46 ) ;
continue;
}
F_31 ( L_44 ,
V_44 -> V_46 , F_47 ( V_49 , V_62 , sizeof( V_62 ) ) ) ;
}
F_28 ( V_42 ) ;
}
}
if ( V_61 && F_15 ( V_61 , V_36 ) )
F_31 ( L_45 , V_61 ) ;
V_45:
if ( V_52 )
F_48 ( V_52 ) ;
return V_30 ;
}
