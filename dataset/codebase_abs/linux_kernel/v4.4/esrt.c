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
char V_19 [ 20 ] ;
V_9 = F_12 ( sizeof( * V_9 ) , V_20 ) ;
if ( ! V_9 )
return - V_21 ;
sprintf ( V_19 , L_2 , V_18 ) ;
V_9 -> V_3 . V_22 = V_23 ;
if ( V_24 -> V_25 == 1 ) {
int V_26 = 0 ;
V_9 -> V_14 . V_15 = V_14 ;
V_26 = F_13 ( & V_9 -> V_3 , & V_27 , NULL ,
L_3 , V_19 ) ;
if ( V_26 ) {
F_10 ( V_9 ) ;
return V_26 ;
}
}
F_14 ( & V_9 -> V_17 , & V_28 ) ;
return 0 ;
}
static inline int F_15 ( void )
{
if ( ! F_16 ( V_29 ) )
return 0 ;
if ( V_30 . V_24 == V_31 )
return 0 ;
return 1 ;
}
static T_2 F_17 ( struct V_2 * V_3 ,
struct V_5 * V_6 , int V_32 )
{
if ( ! F_15 () )
return 0 ;
return V_6 -> V_33 ;
}
void T_3 F_18 ( void )
{
void * V_34 ;
struct V_35 V_36 ;
struct V_37 * V_38 ;
T_4 V_39 , V_40 , V_41 , V_42 ;
T_5 V_43 ;
int V_26 ;
T_6 V_44 ;
F_19 ( L_4 ) ;
if ( ! F_15 () )
return;
V_26 = F_20 ( V_30 . V_24 , & V_43 ) ;
if ( V_26 < 0 ) {
F_21 ( L_5 ) ;
return;
}
V_40 = F_22 ( & V_43 ) ;
if ( V_40 < V_30 . V_24 ) {
F_21 ( L_6 ,
( void * ) V_30 . V_24 , ( void * ) V_40 ) ;
return;
}
V_39 = sizeof( * V_24 ) ;
V_40 -= V_30 . V_24 ;
if ( V_40 < V_39 ) {
F_21 ( L_7 ,
V_39 , V_40 ) ;
return;
}
V_34 = F_23 ( V_30 . V_24 , V_39 ) ;
if ( ! V_34 ) {
F_21 ( L_8 , ( void * ) V_30 . V_24 ,
V_39 ) ;
return;
}
memcpy ( & V_36 , V_34 , sizeof( V_36 ) ) ;
if ( V_36 . V_25 == 1 ) {
V_41 = sizeof ( * V_38 ) ;
} else {
F_21 ( L_9 ,
V_36 . V_25 ) ;
return;
}
if ( V_36 . V_45 > 0 && V_40 - V_39 < V_41 ) {
F_21 ( L_10 ,
V_40 - V_39 , V_41 ) ;
goto V_46;
}
if ( V_36 . V_45 > 128 ) {
F_21 ( L_11 ,
V_36 . V_45 ) ;
goto V_46;
}
V_42 = V_36 . V_45 * V_41 ;
if ( V_40 < V_39 + V_42 ) {
F_21 ( L_12 ,
V_39 , V_40 ) ;
goto V_46;
}
F_24 ( V_34 , V_39 ) ;
V_39 += V_42 ;
V_34 = F_23 ( V_30 . V_24 , V_39 ) ;
if ( ! V_34 ) {
F_21 ( L_8 , ( void * ) V_30 . V_24 ,
V_39 ) ;
return;
}
V_47 = ( T_6 ) V_30 . V_24 ;
V_48 = V_39 ;
V_44 = V_47 + V_39 ;
F_25 ( L_13 , & V_47 , & V_44 ) ;
F_26 ( V_47 , V_48 ) ;
F_19 ( L_14 ) ;
V_46:
F_24 ( V_34 , V_39 ) ;
}
static int T_3 F_27 ( void )
{
struct V_37 * V_38 = ( void * ) V_24 -> V_49 ;
int V_50 , V_26 ;
if ( ! F_15 () )
return 0 ;
for ( V_50 = 0 ; V_50 < F_28 ( V_24 -> V_45 ) ; V_50 ++ ) {
void * V_14 = NULL ;
if ( V_24 -> V_25 == 1 ) {
V_14 = & V_38 [ V_50 ] ;
} else {
F_21 ( L_9 ,
V_24 -> V_25 ) ;
return - V_51 ;
}
V_26 = F_11 ( V_14 , V_50 ) ;
if ( V_26 < 0 ) {
F_21 ( L_15 ,
V_26 ) ;
return V_26 ;
}
}
return 0 ;
}
static void F_29 ( void )
{
struct V_1 * V_9 , * V_52 ;
F_30 (entry, next, &entry_list, list) {
F_31 ( & V_9 -> V_3 ) ;
}
}
static int T_3 F_32 ( void )
{
int error ;
struct V_35 T_7 * V_53 ;
F_19 ( L_16 ) ;
if ( ! V_47 || ! V_48 )
return - V_54 ;
V_53 = F_33 ( V_47 , V_48 ) ;
if ( ! V_53 ) {
F_21 ( L_17 , & V_47 ,
V_48 ) ;
return - V_21 ;
}
V_24 = F_34 ( V_48 , V_20 ) ;
if ( ! V_24 ) {
F_21 ( L_18 , V_48 ) ;
F_35 ( V_53 ) ;
return - V_21 ;
}
F_36 ( V_24 , V_53 , V_48 ) ;
V_55 = F_37 ( L_19 , V_56 ) ;
if ( ! V_55 ) {
F_21 ( L_20 ) ;
error = - V_21 ;
goto V_57;
}
error = F_38 ( V_55 , & V_58 ) ;
if ( error ) {
F_21 ( L_21 ,
error ) ;
goto V_59;
}
V_23 = F_39 ( L_22 , NULL , V_55 ) ;
if ( ! V_23 ) {
F_21 ( L_23 ) ;
error = - V_21 ;
goto V_60;
}
error = F_27 () ;
if ( error )
goto V_61;
F_40 ( V_47 , V_48 ) ;
F_19 ( L_24 ) ;
return 0 ;
V_61:
F_29 () ;
F_41 ( V_23 ) ;
V_60:
F_42 ( V_55 , & V_58 ) ;
V_59:
F_31 ( V_55 ) ;
V_57:
F_10 ( V_24 ) ;
V_24 = NULL ;
return error ;
}
