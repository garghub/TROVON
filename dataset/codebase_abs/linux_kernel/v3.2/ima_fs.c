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
V_17 = F_12 ( V_17 -> V_19 . V_20 ,
struct V_16 , V_19 ) ;
F_10 () ;
( * V_14 ) ++ ;
return ( & V_17 -> V_19 == & V_21 ) ? NULL : V_17 ;
}
static void F_13 ( struct V_12 * V_13 , void * V_18 )
{
}
static void F_14 ( struct V_12 * V_13 , void * V_22 , int V_23 )
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
V_25 = V_17 -> V_29 ;
if ( V_25 == NULL )
return - 1 ;
F_14 ( V_13 , & V_27 , sizeof V_27 ) ;
F_14 ( V_13 , V_25 -> V_30 , V_31 ) ;
V_26 = strlen ( V_25 -> V_32 ) ;
F_14 ( V_13 , & V_26 , sizeof V_26 ) ;
F_14 ( V_13 , ( void * ) V_25 -> V_32 , V_26 ) ;
F_17 ( V_13 , (struct V_33 * ) & V_25 -> V_34 ,
V_35 ) ;
return 0 ;
}
static int F_18 ( struct V_36 * V_36 , struct V_8 * V_8 )
{
return F_19 ( V_8 , & V_37 ) ;
}
static void F_20 ( struct V_12 * V_13 , T_7 * V_30 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_31 ; V_38 ++ )
F_21 ( V_13 , L_2 , * ( V_30 + V_38 ) ) ;
}
void F_17 ( struct V_12 * V_13 , void * V_25 , enum V_39 V_40 )
{
struct V_33 * V_29 = V_25 ;
int V_26 ;
switch ( V_40 ) {
case V_41 :
F_20 ( V_13 , V_29 -> V_30 ) ;
F_21 ( V_13 , L_3 , V_29 -> V_42 ) ;
break;
case V_35 :
F_14 ( V_13 , V_29 -> V_30 , V_31 ) ;
V_26 = strlen ( V_29 -> V_42 ) ;
F_14 ( V_13 , & V_26 , sizeof V_26 ) ;
F_14 ( V_13 , V_29 -> V_42 , V_26 ) ;
default:
break;
}
}
static int F_22 ( struct V_12 * V_13 , void * V_18 )
{
struct V_16 * V_17 = V_18 ;
struct V_24 * V_25 ;
V_25 = V_17 -> V_29 ;
if ( V_25 == NULL )
return - 1 ;
F_21 ( V_13 , L_4 , V_28 ) ;
F_20 ( V_13 , V_25 -> V_30 ) ;
F_21 ( V_13 , L_5 , V_25 -> V_32 ) ;
F_17 ( V_13 , (struct V_33 * ) & V_25 -> V_34 ,
V_41 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_36 , struct V_8 * V_8 )
{
return F_19 ( V_8 , & V_43 ) ;
}
static T_1 F_24 ( struct V_8 * V_8 , const char T_2 * V_1 ,
T_3 V_23 , T_4 * V_3 )
{
char * V_22 = NULL ;
T_1 V_44 ;
if ( V_23 >= V_45 )
V_23 = V_45 - 1 ;
V_44 = - V_46 ;
if ( * V_3 != 0 )
goto V_47;
V_44 = - V_48 ;
V_22 = F_25 ( V_23 + 1 , V_49 ) ;
if ( ! V_22 )
goto V_47;
* ( V_22 + V_23 ) = '\0' ;
V_44 = - V_50 ;
if ( F_26 ( V_22 , V_1 , V_23 ) )
goto V_47;
V_44 = F_27 ( V_22 ) ;
V_47:
if ( V_44 < 0 )
V_51 = 0 ;
F_28 ( V_22 ) ;
return V_44 ;
}
static int F_29 ( struct V_36 * V_36 , struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_52 & V_53 ) )
return - V_54 ;
if ( F_30 ( & V_55 ) )
return 0 ;
return - V_56 ;
}
static int F_31 ( struct V_36 * V_36 , struct V_8 * V_8 )
{
if ( ! V_51 ) {
F_32 () ;
V_51 = 1 ;
F_33 ( & V_55 , 1 ) ;
return 0 ;
}
F_34 () ;
F_35 ( V_57 ) ;
V_57 = NULL ;
return 0 ;
}
int T_8 F_36 ( void )
{
V_58 = F_37 ( L_6 , NULL ) ;
if ( F_38 ( V_58 ) )
return - 1 ;
V_59 =
F_39 ( L_7 ,
V_60 | V_61 , V_58 , NULL ,
& V_62 ) ;
if ( F_38 ( V_59 ) )
goto V_47;
V_63 =
F_39 ( L_8 ,
V_60 | V_61 , V_58 , NULL ,
& V_64 ) ;
if ( F_38 ( V_63 ) )
goto V_47;
V_65 =
F_39 ( L_9 ,
V_60 | V_61 , V_58 , NULL ,
& V_66 ) ;
if ( F_38 ( V_65 ) )
goto V_47;
V_11 =
F_39 ( L_10 , V_60 | V_61 ,
V_58 , NULL , & V_67 ) ;
if ( F_38 ( V_11 ) )
goto V_47;
V_57 = F_39 ( L_11 ,
V_68 ,
V_58 , NULL ,
& V_69 ) ;
if ( F_38 ( V_57 ) )
goto V_47;
return 0 ;
V_47:
F_35 ( V_65 ) ;
F_35 ( V_63 ) ;
F_35 ( V_59 ) ;
F_35 ( V_58 ) ;
F_35 ( V_57 ) ;
return - 1 ;
}
void T_9 F_40 ( void )
{
F_35 ( V_11 ) ;
F_35 ( V_65 ) ;
F_35 ( V_63 ) ;
F_35 ( V_59 ) ;
F_35 ( V_58 ) ;
F_35 ( V_57 ) ;
}
