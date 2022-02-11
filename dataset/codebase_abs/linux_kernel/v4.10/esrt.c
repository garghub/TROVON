static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_6 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_5 * V_7 , char * V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_4 * V_6 = F_3 ( V_7 ) ;
if ( ! F_5 ( V_10 ) )
return - V_11 ;
return V_6 -> V_12 ( V_9 , V_8 ) ;
}
static T_1 F_6 ( struct V_1 * V_9 , char * V_8 )
{
char * V_13 = V_8 ;
F_7 ( & V_9 -> V_14 . V_15 -> V_16 , V_13 ) ;
V_13 += strlen ( V_13 ) ;
V_13 += sprintf ( V_13 , L_1 ) ;
return V_13 - V_8 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_9 ( & V_9 -> V_17 ) ;
F_10 ( V_9 ) ;
}
static int F_11 ( void * V_14 , int V_18 )
{
struct V_1 * V_9 ;
V_9 = F_12 ( sizeof( * V_9 ) , V_19 ) ;
if ( ! V_9 )
return - V_20 ;
V_9 -> V_3 . V_21 = V_22 ;
if ( V_23 -> V_24 == 1 ) {
int V_25 = 0 ;
V_9 -> V_14 . V_15 = V_14 ;
V_25 = F_13 ( & V_9 -> V_3 , & V_26 , NULL ,
L_2 , V_18 ) ;
if ( V_25 ) {
F_10 ( V_9 ) ;
return V_25 ;
}
}
F_14 ( & V_9 -> V_17 , & V_27 ) ;
return 0 ;
}
static inline int F_15 ( void )
{
if ( ! F_16 ( V_28 ) )
return 0 ;
if ( V_29 . V_23 == V_30 )
return 0 ;
return 1 ;
}
static T_2 F_17 ( struct V_2 * V_3 ,
struct V_5 * V_6 , int V_31 )
{
if ( ! F_15 () )
return 0 ;
return V_6 -> V_32 ;
}
void T_3 F_18 ( void )
{
void * V_33 ;
struct V_34 V_35 ;
struct V_36 * V_37 ;
T_4 V_38 , V_39 , V_40 , V_41 ;
T_5 V_42 ;
int V_25 ;
T_6 V_43 ;
F_19 ( L_3 ) ;
if ( ! F_15 () )
return;
V_25 = F_20 ( V_29 . V_23 , & V_42 ) ;
if ( V_25 < 0 ) {
F_21 ( L_4 ) ;
return;
}
V_39 = F_22 ( & V_42 ) ;
if ( V_39 < V_29 . V_23 ) {
F_21 ( L_5 ,
( void * ) V_29 . V_23 , ( void * ) V_39 ) ;
return;
}
V_38 = sizeof( * V_23 ) ;
V_39 -= V_29 . V_23 ;
if ( V_39 < V_38 ) {
F_21 ( L_6 ,
V_38 , V_39 ) ;
return;
}
V_33 = F_23 ( V_29 . V_23 , V_38 ) ;
if ( ! V_33 ) {
F_21 ( L_7 , ( void * ) V_29 . V_23 ,
V_38 ) ;
return;
}
memcpy ( & V_35 , V_33 , sizeof( V_35 ) ) ;
if ( V_35 . V_24 == 1 ) {
V_40 = sizeof ( * V_37 ) ;
} else {
F_21 ( L_8 ,
V_35 . V_24 ) ;
return;
}
if ( V_35 . V_44 > 0 && V_39 - V_38 < V_40 ) {
F_21 ( L_9 ,
V_39 - V_38 , V_40 ) ;
goto V_45;
}
if ( V_35 . V_44 > 128 ) {
F_21 ( L_10 ,
V_35 . V_44 ) ;
goto V_45;
}
V_41 = V_35 . V_44 * V_40 ;
if ( V_39 < V_38 + V_41 ) {
F_21 ( L_11 ,
V_38 , V_39 ) ;
goto V_45;
}
F_24 ( V_33 , V_38 ) ;
V_38 += V_41 ;
V_33 = F_23 ( V_29 . V_23 , V_38 ) ;
if ( ! V_33 ) {
F_21 ( L_7 , ( void * ) V_29 . V_23 ,
V_38 ) ;
return;
}
V_46 = ( T_6 ) V_29 . V_23 ;
V_47 = V_38 ;
V_43 = V_46 + V_38 ;
F_25 ( L_12 , & V_46 , & V_43 ) ;
F_26 ( V_46 , V_47 ) ;
F_19 ( L_13 ) ;
V_45:
F_24 ( V_33 , V_38 ) ;
}
static int T_3 F_27 ( void )
{
struct V_36 * V_37 = ( void * ) V_23 -> V_48 ;
int V_49 , V_25 ;
if ( ! F_15 () )
return 0 ;
for ( V_49 = 0 ; V_49 < F_28 ( V_23 -> V_44 ) ; V_49 ++ ) {
void * V_14 = NULL ;
if ( V_23 -> V_24 == 1 ) {
V_14 = & V_37 [ V_49 ] ;
} else {
F_21 ( L_8 ,
V_23 -> V_24 ) ;
return - V_50 ;
}
V_25 = F_11 ( V_14 , V_49 ) ;
if ( V_25 < 0 ) {
F_21 ( L_14 ,
V_25 ) ;
return V_25 ;
}
}
return 0 ;
}
static void F_29 ( void )
{
struct V_1 * V_9 , * V_51 ;
F_30 (entry, next, &entry_list, list) {
F_31 ( & V_9 -> V_3 ) ;
}
}
static int T_3 F_32 ( void )
{
int error ;
F_19 ( L_15 ) ;
if ( ! V_46 || ! V_47 )
return - V_52 ;
V_23 = F_33 ( V_46 , V_47 , V_53 ) ;
if ( ! V_23 ) {
F_21 ( L_16 , & V_46 ,
V_47 ) ;
return - V_20 ;
}
V_54 = F_34 ( L_17 , V_55 ) ;
if ( ! V_54 ) {
F_21 ( L_18 ) ;
error = - V_20 ;
goto V_56;
}
error = F_35 ( V_54 , & V_57 ) ;
if ( error ) {
F_21 ( L_19 ,
error ) ;
goto V_58;
}
V_22 = F_36 ( L_20 , NULL , V_54 ) ;
if ( ! V_22 ) {
F_21 ( L_21 ) ;
error = - V_20 ;
goto V_59;
}
error = F_27 () ;
if ( error )
goto V_60;
F_19 ( L_22 ) ;
return 0 ;
V_60:
F_29 () ;
F_37 ( V_22 ) ;
V_59:
F_38 ( V_54 , & V_57 ) ;
V_58:
F_31 ( V_54 ) ;
V_56:
F_10 ( V_23 ) ;
V_23 = NULL ;
return error ;
}
