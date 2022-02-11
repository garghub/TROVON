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
char * V_22 ;
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
goto V_64;
V_57 = F_27 ( & V_65 ) ;
if ( V_57 < 0 )
goto V_64;
V_57 = F_28 ( V_22 ) ;
F_29 ( & V_65 ) ;
V_64:
F_30 ( V_22 ) ;
V_60:
if ( V_57 < 0 )
V_66 = 0 ;
return V_57 ;
}
static int F_31 ( struct V_52 * V_52 , struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_67 & V_68 ) ) {
#ifndef F_32
return - V_69 ;
#else
if ( ( V_9 -> V_67 & V_70 ) != V_71 )
return - V_69 ;
if ( ! F_33 ( V_72 ) )
return - V_73 ;
return F_18 ( V_9 , & V_74 ) ;
#endif
}
if ( F_34 ( V_75 , & V_76 ) )
return - V_77 ;
return 0 ;
}
static int F_35 ( struct V_52 * V_52 , struct V_8 * V_8 )
{
const char * V_78 = V_66 ? L_9 : L_10 ;
if ( ( V_8 -> V_67 & V_70 ) == V_71 )
return 0 ;
if ( V_66 && F_36 () < 0 ) {
V_78 = L_10 ;
V_66 = 0 ;
}
F_37 ( L_11 , V_78 ) ;
F_38 ( V_79 , NULL , NULL ,
L_12 , V_78 , ! V_66 , 0 ) ;
if ( ! V_66 ) {
F_39 () ;
V_66 = 1 ;
F_40 ( V_75 , & V_76 ) ;
return 0 ;
}
F_41 () ;
#ifndef F_42
F_43 ( V_80 ) ;
V_80 = NULL ;
#else
F_40 ( V_75 , & V_76 ) ;
#endif
return 0 ;
}
int T_8 F_44 ( void )
{
V_81 = F_45 ( L_13 , NULL ) ;
if ( F_46 ( V_81 ) )
return - 1 ;
V_82 =
F_47 ( L_14 ,
V_83 | V_84 , V_81 , NULL ,
& V_85 ) ;
if ( F_46 ( V_82 ) )
goto V_60;
V_86 =
F_47 ( L_15 ,
V_83 | V_84 , V_81 , NULL ,
& V_87 ) ;
if ( F_46 ( V_86 ) )
goto V_60;
V_88 =
F_47 ( L_16 ,
V_83 | V_84 , V_81 , NULL ,
& V_89 ) ;
if ( F_46 ( V_88 ) )
goto V_60;
V_11 =
F_47 ( L_17 , V_83 | V_84 ,
V_81 , NULL , & V_90 ) ;
if ( F_46 ( V_11 ) )
goto V_60;
V_80 = F_47 ( L_18 , V_91 ,
V_81 , NULL ,
& V_92 ) ;
if ( F_46 ( V_80 ) )
goto V_60;
return 0 ;
V_60:
F_43 ( V_11 ) ;
F_43 ( V_88 ) ;
F_43 ( V_86 ) ;
F_43 ( V_82 ) ;
F_43 ( V_81 ) ;
F_43 ( V_80 ) ;
return - 1 ;
}
