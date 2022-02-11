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
int V_26 ;
T_6 V_27 = V_28 ;
bool V_29 = false ;
int V_30 ;
V_25 = V_17 -> V_31 ;
if ( V_25 == NULL )
return - 1 ;
F_14 ( V_13 , & V_27 , sizeof( V_27 ) ) ;
F_14 ( V_13 , V_25 -> V_32 , V_33 ) ;
V_26 = strlen ( V_25 -> V_34 -> V_35 ) ;
F_14 ( V_13 , & V_26 , sizeof( V_26 ) ) ;
F_14 ( V_13 , V_25 -> V_34 -> V_35 , V_26 ) ;
if ( strcmp ( V_25 -> V_34 -> V_35 , V_36 ) == 0 )
V_29 = true ;
if ( ! V_29 )
F_14 ( V_13 , & V_25 -> V_37 ,
sizeof( V_25 -> V_37 ) ) ;
for ( V_30 = 0 ; V_30 < V_25 -> V_34 -> V_38 ; V_30 ++ ) {
enum V_39 V_40 = V_41 ;
struct V_42 * V_43 = V_25 -> V_34 -> V_44 [ V_30 ] ;
if ( V_29 && strcmp ( V_43 -> V_45 , L_2 ) == 0 )
V_40 = V_46 ;
if ( V_29 && strcmp ( V_43 -> V_45 , L_3 ) == 0 )
V_40 = V_47 ;
V_43 -> V_48 ( V_13 , V_40 , & V_25 -> V_49 [ V_30 ] ) ;
}
return 0 ;
}
static int F_17 ( struct V_50 * V_50 , struct V_8 * V_8 )
{
return F_18 ( V_8 , & V_51 ) ;
}
void F_19 ( struct V_12 * V_13 , T_7 * V_32 , int V_52 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_52 ; V_30 ++ )
F_20 ( V_13 , L_4 , * ( V_32 + V_30 ) ) ;
}
static int F_21 ( struct V_12 * V_13 , void * V_18 )
{
struct V_16 * V_17 = V_18 ;
struct V_24 * V_25 ;
int V_30 ;
V_25 = V_17 -> V_31 ;
if ( V_25 == NULL )
return - 1 ;
F_20 ( V_13 , L_5 , V_28 ) ;
F_19 ( V_13 , V_25 -> V_32 , V_33 ) ;
F_20 ( V_13 , L_6 , V_25 -> V_34 -> V_35 ) ;
for ( V_30 = 0 ; V_30 < V_25 -> V_34 -> V_38 ; V_30 ++ ) {
F_22 ( V_13 , L_7 ) ;
if ( V_25 -> V_49 [ V_30 ] . V_7 == 0 )
continue;
V_25 -> V_34 -> V_44 [ V_30 ] -> V_48 ( V_13 , V_53 ,
& V_25 -> V_49 [ V_30 ] ) ;
}
F_22 ( V_13 , L_8 ) ;
return 0 ;
}
static int F_23 ( struct V_50 * V_50 , struct V_8 * V_8 )
{
return F_18 ( V_8 , & V_54 ) ;
}
static T_1 F_24 ( struct V_8 * V_8 , const char T_2 * V_1 ,
T_3 V_23 , T_4 * V_3 )
{
char * V_22 = NULL ;
T_1 V_55 ;
if ( V_23 >= V_56 )
V_23 = V_56 - 1 ;
V_55 = - V_57 ;
if ( * V_3 != 0 )
goto V_58;
V_55 = - V_59 ;
V_22 = F_25 ( V_23 + 1 , V_60 ) ;
if ( ! V_22 )
goto V_58;
* ( V_22 + V_23 ) = '\0' ;
V_55 = - V_61 ;
if ( F_26 ( V_22 , V_1 , V_23 ) )
goto V_58;
V_55 = F_27 ( V_22 ) ;
V_58:
if ( V_55 < 0 )
V_62 = 0 ;
F_28 ( V_22 ) ;
return V_55 ;
}
static int F_29 ( struct V_50 * V_50 , struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_63 & V_64 ) )
return - V_65 ;
if ( F_30 ( & V_66 ) )
return 0 ;
return - V_67 ;
}
static int F_31 ( struct V_50 * V_50 , struct V_8 * V_8 )
{
if ( ! V_62 ) {
F_32 () ;
V_62 = 1 ;
F_33 ( & V_66 , 1 ) ;
return 0 ;
}
F_34 () ;
F_35 ( V_68 ) ;
V_68 = NULL ;
return 0 ;
}
int T_8 F_36 ( void )
{
V_69 = F_37 ( L_9 , NULL ) ;
if ( F_38 ( V_69 ) )
return - 1 ;
V_70 =
F_39 ( L_10 ,
V_71 | V_72 , V_69 , NULL ,
& V_73 ) ;
if ( F_38 ( V_70 ) )
goto V_58;
V_74 =
F_39 ( L_11 ,
V_71 | V_72 , V_69 , NULL ,
& V_75 ) ;
if ( F_38 ( V_74 ) )
goto V_58;
V_76 =
F_39 ( L_12 ,
V_71 | V_72 , V_69 , NULL ,
& V_77 ) ;
if ( F_38 ( V_76 ) )
goto V_58;
V_11 =
F_39 ( L_13 , V_71 | V_72 ,
V_69 , NULL , & V_78 ) ;
if ( F_38 ( V_11 ) )
goto V_58;
V_68 = F_39 ( L_14 ,
V_79 ,
V_69 , NULL ,
& V_80 ) ;
if ( F_38 ( V_68 ) )
goto V_58;
return 0 ;
V_58:
F_35 ( V_11 ) ;
F_35 ( V_76 ) ;
F_35 ( V_74 ) ;
F_35 ( V_70 ) ;
F_35 ( V_69 ) ;
F_35 ( V_68 ) ;
return - 1 ;
}
