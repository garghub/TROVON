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
struct V_8 V_9 ;
struct V_10 V_10 ;
char V_11 [ 32 ] ;
if ( F_5 ( & V_9 , NULL ) || ! localtime_r ( & V_9 . V_12 , & V_10 ) )
return - 1 ;
if ( ! strftime ( V_11 , sizeof( V_11 ) , L_1 , & V_10 ) )
return - 1 ;
F_6 ( V_6 , V_7 , L_2 , V_11 , ( unsigned ) V_9 . V_13 / 10000 ) ;
return 0 ;
}
static bool F_7 ( const char * V_14 , char * V_15 )
{
char V_16 [ V_4 ] ;
char V_17 [ V_4 ] ;
const char * V_18 ;
T_2 V_19 = 0 , V_20 = 0 ;
int V_21 ;
F_6 ( V_16 , sizeof( V_16 ) , L_3 , V_14 ) ;
F_6 ( V_17 , sizeof( V_17 ) , L_3 , V_15 ) ;
for ( V_21 = 0 ; ( V_18 = V_22 [ V_21 ] ) != NULL ; V_21 ++ ) {
V_19 = F_8 ( V_16 , V_18 ) ;
if ( V_19 )
break;
}
if ( V_18 )
V_20 = F_8 ( V_17 , V_18 ) ;
return V_19 == V_20 ;
}
static int F_9 ( const char * V_14 , char * V_15 ,
T_1 V_23 )
{
char V_16 [ V_4 ] ;
char V_17 [ V_4 ] ;
char V_24 [ V_4 ] ;
struct V_25 * V_26 ;
int V_27 = - 1 ;
T_3 * V_28 ;
V_28 = F_10 ( V_15 ) ;
if ( ! V_28 )
return - 1 ;
F_6 ( V_16 , sizeof( V_16 ) , L_4 , V_14 ) ;
while ( 1 ) {
V_26 = F_11 ( V_28 ) ;
if ( ! V_26 )
break;
if ( V_26 -> V_29 != V_30 )
continue;
F_6 ( V_17 , sizeof( V_17 ) , L_5 , V_15 ,
V_26 -> V_31 ) ;
F_6 ( V_24 , sizeof( V_24 ) , L_6 ,
V_15 , V_26 -> V_31 ) ;
if ( ! F_12 ( V_16 , V_17 ) &&
F_7 ( V_14 , V_24 ) ) {
F_2 ( V_15 , V_24 , V_23 ) ;
V_27 = 0 ;
break;
}
}
F_13 ( V_28 ) ;
return V_27 ;
}
static int F_14 ( const char * V_32 , bool V_33 )
{
char V_6 [ 32 ] , V_2 [ V_34 ] ;
char V_14 [ V_4 ] , V_15 [ V_4 ] ;
char * V_5 ;
F_2 ( V_14 , V_32 , sizeof( V_14 ) ) ;
V_5 = strrchr ( V_14 , '/' ) ;
if ( ! V_5 || strcmp ( V_5 + 1 , L_7 ) )
return - 1 ;
* V_5 = '\0' ;
if ( F_1 ( V_14 , V_2 ) < 0 )
return - 1 ;
F_6 ( V_15 , sizeof( V_15 ) , L_8 ,
V_35 , V_2 ) ;
if ( ! V_33 &&
! F_9 ( V_14 , V_15 , sizeof( V_15 ) ) ) {
F_15 ( L_9 , V_15 ) ;
return 0 ;
}
if ( F_4 ( V_6 , sizeof( V_6 ) ) )
return - 1 ;
F_6 ( V_15 , sizeof( V_15 ) , L_10 ,
V_35 , V_2 , V_6 ) ;
if ( F_16 ( V_15 , 0755 ) )
return - 1 ;
if ( F_17 ( V_14 , V_15 ) ) {
if ( ! F_18 ( V_15 ) ) {
V_5 = strrchr ( V_15 , '/' ) ;
if ( V_5 )
* V_5 = '\0' ;
if ( ! F_18 ( V_15 ) ) {
V_5 = strrchr ( V_15 , '/' ) ;
if ( V_5 )
* V_5 = '\0' ;
F_18 ( V_15 ) ;
}
}
return - 1 ;
}
F_15 ( L_11 , V_15 ) ;
return 0 ;
}
static int F_19 ( const char * V_32 )
{
char V_36 [ V_34 ] ;
T_4 V_37 [ V_38 ] ;
int V_39 ;
if ( F_20 ( V_32 , & V_37 , sizeof( V_37 ) ) < 0 ) {
F_15 ( L_12 , V_32 ) ;
return - 1 ;
}
F_21 ( V_37 , sizeof( V_37 ) , V_36 ) ;
V_39 = F_22 ( V_36 , V_32 ,
false , false ) ;
F_15 ( L_13 , V_36 , V_32 ,
V_39 ? L_14 : L_15 ) ;
return V_39 ;
}
static int F_23 ( const char * V_32 )
{
T_4 V_37 [ V_38 ] ;
char V_36 [ V_34 ] ;
int V_39 ;
if ( F_20 ( V_32 , & V_37 , sizeof( V_37 ) ) < 0 ) {
F_15 ( L_12 , V_32 ) ;
return - 1 ;
}
F_21 ( V_37 , sizeof( V_37 ) , V_36 ) ;
V_39 = F_24 ( V_36 ) ;
F_15 ( L_16 , V_36 , V_32 ,
V_39 ? L_14 : L_15 ) ;
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
F_15 ( L_16 , V_44 -> V_46 , V_40 ,
V_39 ? L_14 : L_15 ) ;
if ( V_39 )
break;
}
F_28 ( V_42 ) ;
V_45:
F_15 ( L_17 , V_40 , V_39 ? L_14 : L_15 ) ;
return V_39 ;
}
static bool F_29 ( struct V_47 * V_47 , int T_5 V_48 )
{
char V_32 [ V_4 ] ;
T_4 V_37 [ V_38 ] ;
if ( F_30 ( V_47 , V_32 , sizeof( V_32 ) ) &&
F_20 ( V_32 , V_37 ,
sizeof( V_37 ) ) != sizeof( V_37 ) ) {
if ( V_49 == V_50 )
return false ;
F_31 ( L_18 ,
V_32 ) ;
} else if ( memcmp ( V_47 -> V_37 , V_37 , sizeof( V_47 -> V_37 ) ) ) {
F_31 ( L_18 ,
V_32 ) ;
}
return true ;
}
static int F_32 ( struct V_51 * V_52 , T_6 * V_53 )
{
F_33 ( V_52 , V_53 , F_29 , 0 ) ;
return 0 ;
}
static int F_34 ( const char * V_32 )
{
T_4 V_37 [ V_38 ] ;
char V_36 [ V_34 ] ;
int V_39 = 0 ;
if ( F_20 ( V_32 , & V_37 , sizeof( V_37 ) ) < 0 ) {
F_15 ( L_12 , V_32 ) ;
return - 1 ;
}
F_21 ( V_37 , sizeof( V_37 ) , V_36 ) ;
if ( F_35 ( V_36 ) )
V_39 = F_24 ( V_36 ) ;
if ( ! V_39 )
V_39 = F_22 ( V_36 , V_32 , false , false ) ;
F_15 ( L_19 , V_36 , V_32 ,
V_39 ? L_14 : L_15 ) ;
return V_39 ;
}
int F_36 ( int V_54 , const char * * V_55 ,
const char * T_7 V_48 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_27 = 0 ;
bool V_33 = false ;
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
F_37 ( 'a' , L_20 , & V_56 ,
L_21 , L_22 ) ,
F_37 ( 'k' , L_7 , & V_61 ,
L_23 , L_24 ) ,
F_37 ( 'r' , L_25 , & V_57 , L_21 ,
L_26 ) ,
F_37 ( 'p' , L_27 , & V_58 , L_28 ,
L_29 ) ,
F_37 ( 'M' , L_30 , & V_59 , L_23 ,
L_31 ) ,
F_38 ( 'f' , L_32 , & V_33 , L_33 ) ,
F_37 ( 'u' , L_34 , & V_60 , L_21 ,
L_35 ) ,
F_39 ( 'v' , L_36 , & V_70 , L_37 ) ,
F_40 ()
} ;
const char * const V_71 [] = {
L_38 ,
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
V_65 . V_33 = V_33 ;
V_52 = F_43 ( & V_65 , false , NULL ) ;
if ( V_52 == NULL )
return - 1 ;
}
if ( F_44 ( V_52 ? & V_52 -> V_73 . V_74 : NULL ) < 0 )
goto V_45;
F_45 () ;
if ( V_56 ) {
V_42 = F_46 ( V_56 , NULL ) ;
if ( V_42 ) {
F_27 (pos, list)
if ( F_19 ( V_44 -> V_46 ) ) {
if ( V_49 == V_75 ) {
F_15 ( L_39 ,
V_44 -> V_46 ) ;
continue;
}
F_31 ( L_40 ,
V_44 -> V_46 , F_47 ( V_49 , V_62 , sizeof( V_62 ) ) ) ;
}
F_28 ( V_42 ) ;
}
}
if ( V_57 ) {
V_42 = F_46 ( V_57 , NULL ) ;
if ( V_42 ) {
F_27 (pos, list)
if ( F_23 ( V_44 -> V_46 ) ) {
if ( V_49 == V_50 ) {
F_15 ( L_41 ,
V_44 -> V_46 ) ;
continue;
}
F_31 ( L_42 ,
V_44 -> V_46 , F_47 ( V_49 , V_62 , sizeof( V_62 ) ) ) ;
}
F_28 ( V_42 ) ;
}
}
if ( V_58 ) {
V_42 = F_46 ( V_58 , NULL ) ;
if ( V_42 ) {
F_27 (pos, list)
if ( F_25 ( V_44 -> V_46 ) ) {
if ( V_49 == V_50 ) {
F_15 ( L_41 ,
V_44 -> V_46 ) ;
continue;
}
F_31 ( L_42 ,
V_44 -> V_46 , F_47 ( V_49 , V_62 , sizeof( V_62 ) ) ) ;
}
F_28 ( V_42 ) ;
}
}
if ( V_59 )
V_27 = F_32 ( V_52 , stdout ) ;
if ( V_60 ) {
V_42 = F_46 ( V_60 , NULL ) ;
if ( V_42 ) {
F_27 (pos, list)
if ( F_34 ( V_44 -> V_46 ) ) {
if ( V_49 == V_50 ) {
F_15 ( L_41 ,
V_44 -> V_46 ) ;
continue;
}
F_31 ( L_43 ,
V_44 -> V_46 , F_47 ( V_49 , V_62 , sizeof( V_62 ) ) ) ;
}
F_28 ( V_42 ) ;
}
}
if ( V_61 && F_14 ( V_61 , V_33 ) )
F_31 ( L_44 , V_61 ) ;
V_45:
if ( V_52 )
F_48 ( V_52 ) ;
return V_27 ;
}
