static T_1 F_1 ( char T_2 * V_1 , T_3 V_2 ,
T_4 * V_3 , T_5 * V_4 )
{
char V_5 [ V_6 ] ;
T_1 V_7 ;
V_7 = F_2 ( V_5 , V_6 , L_1 , F_3 ( V_4 ) ) ;
return F_4 ( V_1 , V_2 , V_3 , V_5 , V_7 ) ;
}
static T_1 F_5 ( struct V_8 * V_9 ,
char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , & V_10 . V_11 ) ;
}
static T_1 F_6 ( struct V_8 * V_9 ,
char T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
return F_1 ( V_1 , V_2 , V_3 , & V_10 . V_7 ) ;
}
static void * F_7 ( struct V_12 * V_13 , T_4 * V_14 )
{
T_4 V_15 = * V_14 ;
struct V_16 * V_17 ;
F_8 () ;
F_9 (qe, &ima_measurements, later) {
if ( ! V_15 -- ) {
F_10 () ;
return V_17 ;
}
}
F_10 () ;
return NULL ;
}
static void * F_11 ( struct V_12 * V_13 , void * V_18 , T_4 * V_14 )
{
struct V_16 * V_17 = V_18 ;
F_8 () ;
V_17 = F_12 ( V_17 -> V_19 . V_20 , struct V_16 , V_19 ) ;
F_10 () ;
( * V_14 ) ++ ;
return ( & V_17 -> V_19 == & V_21 ) ? NULL : V_17 ;
}
static void F_13 ( struct V_12 * V_13 , void * V_18 )
{
}
void F_14 ( struct V_12 * V_13 , void * V_22 , int V_23 )
{
while ( V_23 -- )
F_15 ( V_13 , * ( char * ) V_22 ++ ) ;
}
static int F_16 ( struct V_12 * V_13 , void * V_18 )
{
struct V_16 * V_17 = V_18 ;
struct V_24 * V_25 ;
char * V_26 ;
int V_27 ;
T_6 V_28 = V_29 ;
bool V_30 = false ;
int V_31 ;
V_25 = V_17 -> V_32 ;
if ( V_25 == NULL )
return - 1 ;
V_26 = ( V_25 -> V_33 -> V_34 [ 0 ] != '\0' ) ?
V_25 -> V_33 -> V_34 : V_25 -> V_33 -> V_35 ;
F_14 ( V_13 , & V_28 , sizeof( V_28 ) ) ;
F_14 ( V_13 , V_25 -> V_36 , V_37 ) ;
V_27 = strlen ( V_26 ) ;
F_14 ( V_13 , & V_27 , sizeof( V_27 ) ) ;
F_14 ( V_13 , V_26 , V_27 ) ;
if ( strcmp ( V_26 , V_38 ) == 0 )
V_30 = true ;
if ( ! V_30 )
F_14 ( V_13 , & V_25 -> V_39 ,
sizeof( V_25 -> V_39 ) ) ;
for ( V_31 = 0 ; V_31 < V_25 -> V_33 -> V_40 ; V_31 ++ ) {
enum V_41 V_42 = V_43 ;
struct V_44 * V_45 = V_25 -> V_33 -> V_46 [ V_31 ] ;
if ( V_30 && strcmp ( V_45 -> V_47 , L_2 ) == 0 )
V_42 = V_48 ;
if ( V_30 && strcmp ( V_45 -> V_47 , L_3 ) == 0 )
V_42 = V_49 ;
V_45 -> V_50 ( V_13 , V_42 , & V_25 -> V_51 [ V_31 ] ) ;
}
return 0 ;
}
static int F_17 ( struct V_52 * V_52 , struct V_8 * V_8 )
{
return F_18 ( V_8 , & V_53 ) ;
}
void F_19 ( struct V_12 * V_13 , T_7 * V_36 , T_6 V_54 )
{
T_6 V_31 ;
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ )
F_20 ( V_13 , L_4 , * ( V_36 + V_31 ) ) ;
}
static int F_21 ( struct V_12 * V_13 , void * V_18 )
{
struct V_16 * V_17 = V_18 ;
struct V_24 * V_25 ;
char * V_26 ;
int V_31 ;
V_25 = V_17 -> V_32 ;
if ( V_25 == NULL )
return - 1 ;
V_26 = ( V_25 -> V_33 -> V_34 [ 0 ] != '\0' ) ?
V_25 -> V_33 -> V_34 : V_25 -> V_33 -> V_35 ;
F_20 ( V_13 , L_5 , V_29 ) ;
F_19 ( V_13 , V_25 -> V_36 , V_37 ) ;
F_20 ( V_13 , L_6 , V_26 ) ;
for ( V_31 = 0 ; V_31 < V_25 -> V_33 -> V_40 ; V_31 ++ ) {
F_22 ( V_13 , L_7 ) ;
if ( V_25 -> V_51 [ V_31 ] . V_7 == 0 )
continue;
V_25 -> V_33 -> V_46 [ V_31 ] -> V_50 ( V_13 , V_55 ,
& V_25 -> V_51 [ V_31 ] ) ;
}
F_22 ( V_13 , L_8 ) ;
return 0 ;
}
static int F_23 ( struct V_52 * V_52 , struct V_8 * V_8 )
{
return F_18 ( V_8 , & V_56 ) ;
}
static T_1 F_24 ( struct V_8 * V_8 , const char T_2 * V_1 ,
T_3 V_23 , T_4 * V_3 )
{
char * V_22 = NULL ;
T_1 V_57 ;
if ( V_23 >= V_58 )
V_23 = V_58 - 1 ;
V_57 = - V_59 ;
if ( * V_3 != 0 )
goto V_60;
V_57 = - V_61 ;
V_22 = F_25 ( V_23 + 1 , V_62 ) ;
if ( ! V_22 )
goto V_60;
* ( V_22 + V_23 ) = '\0' ;
V_57 = - V_63 ;
if ( F_26 ( V_22 , V_1 , V_23 ) )
goto V_60;
V_57 = F_27 ( V_22 ) ;
V_60:
if ( V_57 < 0 )
V_64 = 0 ;
F_28 ( V_22 ) ;
return V_57 ;
}
static int F_29 ( struct V_52 * V_52 , struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_65 & V_66 ) )
return - V_67 ;
if ( F_30 ( V_68 , & V_69 ) )
return - V_70 ;
return 0 ;
}
static int F_31 ( struct V_52 * V_52 , struct V_8 * V_8 )
{
const char * V_71 = V_64 ? L_9 : L_10 ;
F_32 ( L_11 , V_71 ) ;
F_33 ( V_72 , NULL , NULL ,
L_12 , V_71 , ! V_64 , 0 ) ;
if ( ! V_64 ) {
F_34 () ;
V_64 = 1 ;
F_35 ( V_68 , & V_69 ) ;
return 0 ;
}
F_36 () ;
F_37 ( V_73 ) ;
V_73 = NULL ;
return 0 ;
}
int T_8 F_38 ( void )
{
V_74 = F_39 ( L_13 , NULL ) ;
if ( F_40 ( V_74 ) )
return - 1 ;
V_75 =
F_41 ( L_14 ,
V_76 | V_77 , V_74 , NULL ,
& V_78 ) ;
if ( F_40 ( V_75 ) )
goto V_60;
V_79 =
F_41 ( L_15 ,
V_76 | V_77 , V_74 , NULL ,
& V_80 ) ;
if ( F_40 ( V_79 ) )
goto V_60;
V_81 =
F_41 ( L_16 ,
V_76 | V_77 , V_74 , NULL ,
& V_82 ) ;
if ( F_40 ( V_81 ) )
goto V_60;
V_11 =
F_41 ( L_17 , V_76 | V_77 ,
V_74 , NULL , & V_83 ) ;
if ( F_40 ( V_11 ) )
goto V_60;
V_73 = F_41 ( L_18 ,
V_84 ,
V_74 , NULL ,
& V_85 ) ;
if ( F_40 ( V_73 ) )
goto V_60;
return 0 ;
V_60:
F_37 ( V_11 ) ;
F_37 ( V_81 ) ;
F_37 ( V_79 ) ;
F_37 ( V_75 ) ;
F_37 ( V_74 ) ;
F_37 ( V_73 ) ;
return - 1 ;
}
