static void F_1 ( int T_1 V_1 )
{
V_2 = true ;
}
static void F_2 ( int T_2 V_1 ,
T_3 * T_4 V_1 ,
void * T_5 V_1 )
{
V_2 = true ;
}
static int F_3 ( const char * V_3 , const char * V_4 , bool V_5 )
{
char * V_6 ;
int V_7 , V_8 = - 1 ;
T_6 V_9 = strlen ( V_4 ) ;
int V_10 = V_11 ;
char V_12 [ 512 ] ;
V_6 = F_4 ( V_3 ) ;
if ( ! V_6 ) {
F_5 ( L_1 , V_3 ) ;
return - 1 ;
}
if ( V_5 )
V_10 |= V_13 ;
else
V_10 |= V_14 ;
V_7 = F_6 ( V_6 , V_10 ) ;
if ( V_7 < 0 ) {
F_5 ( L_2 ,
V_3 , F_7 ( V_15 , V_12 , sizeof( V_12 ) ) ) ;
goto V_16;
}
if ( F_8 ( V_7 , V_4 , V_9 ) == V_9 )
V_8 = 0 ;
else
F_5 ( L_3 ,
V_4 , V_3 , F_7 ( V_15 , V_12 , sizeof( V_12 ) ) ) ;
F_9 ( V_7 ) ;
V_16:
F_10 ( V_6 ) ;
return V_8 ;
}
static int F_11 ( const char * V_3 , const char * V_4 )
{
return F_3 ( V_3 , V_4 , false ) ;
}
static int F_12 ( const char * V_3 , const char * V_4 )
{
return F_3 ( V_3 , V_4 , true ) ;
}
static int F_13 ( struct V_17 * T_7 V_1 )
{
if ( F_11 ( L_4 , L_5 ) < 0 )
return - 1 ;
if ( F_11 ( L_6 , L_7 ) < 0 )
return - 1 ;
if ( F_11 ( L_8 , L_9 ) < 0 )
return - 1 ;
if ( F_14 () < 0 )
return - 1 ;
if ( F_11 ( L_10 , L_5 ) < 0 )
return - 1 ;
F_15 () ;
return 0 ;
}
static int F_16 ( struct V_17 * T_7 )
{
int V_18 ;
char V_19 [ 16 ] ;
if ( F_17 ( & T_7 -> V_20 ) )
return 0 ;
for ( V_18 = 0 ; V_18 < F_18 ( T_7 -> V_21 -> V_22 ) ; V_18 ++ ) {
F_19 ( V_19 , sizeof( V_19 ) , L_11 ,
T_7 -> V_21 -> V_22 -> V_23 [ V_18 ] ) ;
if ( F_12 ( L_8 , V_19 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_20 ( struct V_24 * V_25 )
{
char * V_26 ;
T_8 V_27 ;
int V_8 ;
int V_28 ;
V_28 = F_21 ( V_25 , V_25 -> V_29 - 1 ) ;
V_27 = ( V_28 + 3 ) / 4 + 1 ;
V_27 += V_28 / 32 ;
V_26 = malloc ( V_27 ) ;
if ( V_26 == NULL ) {
F_5 ( L_12 ) ;
return - 1 ;
}
F_22 ( V_25 , V_26 , V_27 ) ;
V_8 = F_11 ( L_13 , V_26 ) ;
free ( V_26 ) ;
return V_8 ;
}
static int F_23 ( struct V_17 * T_7 )
{
struct V_24 * V_25 = T_7 -> V_21 -> V_30 ;
if ( ! F_17 ( & T_7 -> V_20 ) )
return 0 ;
return F_20 ( V_25 ) ;
}
static int F_14 ( void )
{
struct V_24 * V_25 = F_24 ( NULL ) ;
int V_8 ;
V_8 = F_20 ( V_25 ) ;
F_25 ( V_25 ) ;
return V_8 ;
}
static int F_26 ( const char * V_31 , struct V_32 * V_33 )
{
struct V_34 * V_35 ;
F_27 (pos, funcs, list) {
if ( F_12 ( V_31 , V_35 -> V_3 ) < 0 )
return - 1 ;
}
return 0 ;
}
static int F_28 ( struct V_17 * T_7 )
{
int V_8 ;
V_8 = F_26 ( L_14 , & T_7 -> V_36 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_26 ( L_15 , & T_7 -> V_37 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_26 ( L_16 , & T_7 -> V_38 ) ;
if ( V_8 < 0 )
return V_8 ;
F_26 ( L_17 , & T_7 -> V_39 ) ;
return V_8 ;
}
static void F_15 ( void )
{
F_11 ( L_14 , L_9 ) ;
F_11 ( L_15 , L_9 ) ;
F_11 ( L_16 , L_9 ) ;
F_11 ( L_17 , L_9 ) ;
}
static int F_29 ( struct V_17 * T_7 )
{
char V_19 [ 16 ] ;
if ( T_7 -> V_40 == 0 )
return 0 ;
if ( T_7 -> V_40 < 0 ) {
F_30 ( L_18 , T_7 -> V_40 ) ;
return - 1 ;
}
snprintf ( V_19 , sizeof( V_19 ) , L_11 , T_7 -> V_40 ) ;
if ( F_11 ( L_10 , V_19 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_31 ( struct V_17 * T_7 , int V_41 , const char * * V_42 )
{
char * V_43 ;
int V_44 ;
char V_19 [ 4096 ] ;
struct V_45 V_45 = {
. V_46 = V_47 ,
} ;
if ( F_32 () != 0 ) {
F_30 ( L_19 ) ;
return - 1 ;
}
signal ( V_48 , F_1 ) ;
signal ( V_49 , F_1 ) ;
signal ( V_50 , F_1 ) ;
signal ( V_51 , F_1 ) ;
if ( F_13 ( T_7 ) < 0 )
goto V_16;
if ( F_11 ( L_20 , L_5 ) < 0 )
goto V_16;
if ( V_41 && F_33 ( T_7 -> V_21 ,
& T_7 -> V_20 , V_42 , false ,
F_2 ) < 0 ) {
goto V_16;
}
if ( F_16 ( T_7 ) < 0 ) {
F_30 ( L_21 ) ;
goto V_52;
}
if ( F_23 ( T_7 ) < 0 ) {
F_30 ( L_22 ) ;
goto V_52;
}
if ( F_28 ( T_7 ) < 0 ) {
F_30 ( L_23 ) ;
goto V_52;
}
if ( F_29 ( T_7 ) < 0 ) {
F_30 ( L_24 ) ;
goto V_52;
}
if ( F_11 ( L_6 , T_7 -> V_53 ) < 0 ) {
F_30 ( L_25 , T_7 -> V_53 ) ;
goto V_52;
}
F_34 () ;
V_43 = F_4 ( L_26 ) ;
if ( ! V_43 ) {
F_30 ( L_27 ) ;
goto V_52;
}
V_44 = F_6 ( V_43 , V_54 ) ;
F_10 ( V_43 ) ;
if ( V_44 < 0 ) {
F_30 ( L_27 ) ;
goto V_52;
}
F_35 ( V_44 , V_55 , V_56 ) ;
V_45 . V_7 = V_44 ;
if ( F_11 ( L_4 , L_28 ) < 0 ) {
F_30 ( L_29 ) ;
goto V_57;
}
F_36 ( T_7 -> V_21 ) ;
while ( ! V_2 ) {
if ( F_37 ( & V_45 , 1 , - 1 ) < 0 )
break;
if ( V_45 . V_58 & V_47 ) {
int V_59 = F_38 ( V_44 , V_19 , sizeof( V_19 ) ) ;
if ( V_59 < 0 )
break;
if ( fwrite ( V_19 , V_59 , 1 , stdout ) != 1 )
break;
}
}
F_11 ( L_4 , L_5 ) ;
while ( true ) {
int V_59 = F_38 ( V_44 , V_19 , sizeof( V_19 ) ) ;
if ( V_59 <= 0 )
break;
if ( fwrite ( V_19 , V_59 , 1 , stdout ) != 1 )
break;
}
V_57:
F_9 ( V_44 ) ;
V_52:
F_13 ( T_7 ) ;
V_16:
return V_2 ? 0 : - 1 ;
}
static int F_39 ( const char * V_60 , const char * V_61 , void * V_62 )
{
struct V_17 * T_7 = V_62 ;
if ( ! F_40 ( V_60 , L_30 ) )
return 0 ;
if ( strcmp ( V_60 , L_31 ) )
return - 1 ;
if ( ! strcmp ( V_61 , L_32 ) ||
! strcmp ( V_61 , L_33 ) ) {
T_7 -> V_53 = V_61 ;
return 0 ;
}
F_30 ( L_34 ) ;
return - 1 ;
}
static int F_41 ( const struct V_63 * V_64 , const char * V_65 ,
int T_9 V_1 )
{
struct V_32 * V_66 = V_64 -> V_61 ;
struct V_34 * V_67 ;
V_67 = malloc ( sizeof( * V_67 ) + strlen ( V_65 ) + 1 ) ;
if ( V_67 == NULL )
return - V_68 ;
strcpy ( V_67 -> V_3 , V_65 ) ;
F_42 ( & V_67 -> V_69 , V_66 ) ;
return 0 ;
}
static void F_43 ( struct V_32 * V_66 )
{
struct V_34 * V_35 , * V_70 ;
F_44 (pos, tmp, head, list) {
F_45 ( & V_35 -> V_69 ) ;
free ( V_35 ) ;
}
}
int F_46 ( int V_41 , const char * * V_42 )
{
int V_8 ;
struct V_17 T_7 = {
. V_53 = V_71 ,
. V_20 = { . V_72 = V_73 , } ,
} ;
const char * const V_74 [] = {
L_35 ,
L_36 ,
NULL
} ;
const struct V_63 V_75 [] = {
F_47 ( 't' , L_37 , & T_7 . V_53 , L_37 ,
L_38 ) ,
F_47 ( 'p' , L_39 , & T_7 . V_20 . V_76 , L_39 ,
L_40 ) ,
F_48 ( 'v' , L_41 , & V_77 ,
L_42 ) ,
F_49 ( 'a' , L_43 , & T_7 . V_20 . V_78 ,
L_44 ) ,
F_47 ( 'C' , L_45 , & T_7 . V_20 . V_79 , L_45 ,
L_46 ) ,
F_50 ( 'T' , L_47 , & T_7 . V_36 , L_48 ,
L_49 , F_41 ) ,
F_50 ( 'N' , L_50 , & T_7 . V_37 , L_48 ,
L_51 , F_41 ) ,
F_50 ( 'G' , L_52 , & T_7 . V_38 , L_48 ,
L_53 , F_41 ) ,
F_50 ( 'g' , L_54 , & T_7 . V_39 , L_48 ,
L_55 , F_41 ) ,
F_51 ( 'D' , L_56 , & T_7 . V_40 ,
L_57 ) ,
F_52 ()
} ;
F_53 ( & T_7 . V_36 ) ;
F_53 ( & T_7 . V_37 ) ;
F_53 ( & T_7 . V_38 ) ;
F_53 ( & T_7 . V_39 ) ;
V_8 = F_54 ( F_39 , & T_7 ) ;
if ( V_8 < 0 )
return - 1 ;
V_41 = F_55 ( V_41 , V_42 , V_75 , V_74 ,
V_80 ) ;
if ( ! V_41 && F_56 ( & T_7 . V_20 ) )
F_57 ( V_74 , V_75 ) ;
V_8 = F_58 ( & T_7 . V_20 ) ;
if ( V_8 ) {
char V_12 [ 512 ] ;
F_59 ( & T_7 . V_20 , V_8 , V_12 , 512 ) ;
F_30 ( L_58 , V_12 ) ;
goto V_81;
}
T_7 . V_21 = F_60 () ;
if ( T_7 . V_21 == NULL ) {
V_8 = - V_68 ;
goto V_81;
}
V_8 = F_61 ( T_7 . V_21 , & T_7 . V_20 ) ;
if ( V_8 < 0 )
goto V_82;
V_8 = F_31 ( & T_7 , V_41 , V_42 ) ;
V_82:
F_62 ( T_7 . V_21 ) ;
V_81:
F_43 ( & T_7 . V_36 ) ;
F_43 ( & T_7 . V_37 ) ;
F_43 ( & T_7 . V_38 ) ;
F_43 ( & T_7 . V_39 ) ;
return V_8 ;
}
