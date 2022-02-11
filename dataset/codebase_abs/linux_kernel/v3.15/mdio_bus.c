struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
T_1 V_4 = F_2 ( sizeof( * V_3 ) , V_5 ) ;
T_1 V_6 ;
if ( V_2 )
V_6 = V_4 + V_2 ;
else
V_6 = sizeof( * V_3 ) ;
V_3 = F_3 ( V_6 , V_7 ) ;
if ( V_3 ) {
V_3 -> V_8 = V_9 ;
if ( V_2 )
V_3 -> V_10 = ( void * ) V_3 + V_4 ;
}
return V_3 ;
}
static void F_4 ( struct V_11 * V_12 )
{
struct V_1 * V_3 = F_5 ( V_12 ) ;
F_6 ( V_3 -> V_8 != V_13 &&
V_3 -> V_8 != V_9 ) ;
F_7 ( V_3 ) ;
}
static int F_8 ( struct V_11 * V_14 , const void * V_15 )
{
return V_14 -> V_16 == V_15 ;
}
struct V_1 * F_9 ( struct V_17 * V_15 )
{
struct V_11 * V_12 ;
if ( ! V_15 )
return NULL ;
V_12 = F_10 ( & V_18 , NULL , V_15 ,
F_8 ) ;
return V_12 ? F_5 ( V_12 ) : NULL ;
}
int F_11 ( struct V_1 * V_3 )
{
int V_19 , V_20 ;
if ( NULL == V_3 || NULL == V_3 -> V_21 ||
NULL == V_3 -> V_22 || NULL == V_3 -> V_23 )
return - V_24 ;
F_6 ( V_3 -> V_8 != V_9 &&
V_3 -> V_8 != V_25 ) ;
V_3 -> V_14 . V_26 = V_3 -> V_26 ;
V_3 -> V_14 . V_27 = & V_18 ;
V_3 -> V_14 . V_28 = NULL ;
F_12 ( & V_3 -> V_14 , L_1 , V_3 -> V_29 ) ;
V_20 = F_13 ( & V_3 -> V_14 ) ;
if ( V_20 ) {
F_14 ( L_2 , V_3 -> V_29 ) ;
F_15 ( & V_3 -> V_14 ) ;
return - V_24 ;
}
F_16 ( & V_3 -> V_30 ) ;
if ( V_3 -> V_31 )
V_3 -> V_31 ( V_3 ) ;
for ( V_19 = 0 ; V_19 < V_32 ; V_19 ++ ) {
if ( ( V_3 -> V_33 & ( 1 << V_19 ) ) == 0 ) {
struct V_34 * V_35 ;
V_35 = F_17 ( V_3 , V_19 ) ;
if ( F_18 ( V_35 ) ) {
V_20 = F_19 ( V_35 ) ;
goto error;
}
}
}
V_3 -> V_8 = V_36 ;
F_20 ( L_3 , V_3 -> V_21 ) ;
return 0 ;
error:
while ( -- V_19 >= 0 ) {
if ( V_3 -> V_37 [ V_19 ] )
F_21 ( & V_3 -> V_37 [ V_19 ] -> V_14 ) ;
}
F_22 ( & V_3 -> V_14 ) ;
return V_20 ;
}
void F_23 ( struct V_1 * V_3 )
{
int V_19 ;
F_6 ( V_3 -> V_8 != V_36 ) ;
V_3 -> V_8 = V_25 ;
F_22 ( & V_3 -> V_14 ) ;
for ( V_19 = 0 ; V_19 < V_32 ; V_19 ++ ) {
if ( V_3 -> V_37 [ V_19 ] )
F_21 ( & V_3 -> V_37 [ V_19 ] -> V_14 ) ;
V_3 -> V_37 [ V_19 ] = NULL ;
}
}
void F_24 ( struct V_1 * V_3 )
{
if ( V_3 -> V_8 == V_9 ) {
F_7 ( V_3 ) ;
return;
}
F_6 ( V_3 -> V_8 != V_25 ) ;
V_3 -> V_8 = V_13 ;
F_15 ( & V_3 -> V_14 ) ;
}
struct V_34 * F_17 ( struct V_1 * V_3 , int V_38 )
{
struct V_34 * V_35 ;
int V_20 ;
V_35 = F_25 ( V_3 , V_38 , false ) ;
if ( F_18 ( V_35 ) || V_35 == NULL )
return V_35 ;
V_20 = F_26 ( V_35 ) ;
if ( V_20 ) {
F_27 ( V_35 ) ;
return NULL ;
}
return V_35 ;
}
int F_28 ( struct V_1 * V_3 , int V_38 , T_2 V_39 )
{
int V_40 ;
F_6 ( F_29 () ) ;
F_30 ( & V_3 -> V_30 ) ;
V_40 = V_3 -> V_22 ( V_3 , V_38 , V_39 ) ;
F_31 ( & V_3 -> V_30 ) ;
return V_40 ;
}
int F_32 ( struct V_1 * V_3 , int V_38 , T_2 V_39 , T_3 V_41 )
{
int V_20 ;
F_6 ( F_29 () ) ;
F_30 ( & V_3 -> V_30 ) ;
V_20 = V_3 -> V_23 ( V_3 , V_38 , V_39 , V_41 ) ;
F_31 ( & V_3 -> V_30 ) ;
return V_20 ;
}
static int F_33 ( struct V_11 * V_14 , struct V_42 * V_43 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_44 * V_45 = F_35 ( V_43 ) ;
if ( F_36 ( V_14 , V_43 ) )
return 1 ;
if ( V_45 -> V_46 )
return V_45 -> V_46 ( V_35 ) ;
return ( V_45 -> V_47 & V_45 -> V_48 ) ==
( V_35 -> V_47 & V_45 -> V_48 ) ;
}
static bool F_37 ( struct V_34 * V_35 )
{
struct V_42 * V_43 = V_35 -> V_14 . V_49 ;
struct V_44 * V_45 = F_35 ( V_43 ) ;
struct V_50 * V_51 = V_35 -> V_52 ;
if ( ! V_43 || ! V_45 -> V_53 )
return false ;
if ( ! V_51 )
return true ;
if ( V_51 -> V_14 . V_26 && F_38 ( V_51 -> V_14 . V_26 ) )
return false ;
if ( F_38 ( & V_51 -> V_14 ) )
return false ;
return true ;
}
static int F_39 ( struct V_11 * V_14 )
{
struct V_44 * V_45 = F_35 ( V_14 -> V_49 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
if ( V_35 -> V_52 && V_35 -> V_54 )
F_40 ( V_35 ) ;
if ( ! F_37 ( V_35 ) )
return 0 ;
return V_45 -> V_53 ( V_35 ) ;
}
static int F_41 ( struct V_11 * V_14 )
{
struct V_44 * V_45 = F_35 ( V_14 -> V_49 ) ;
struct V_34 * V_35 = F_34 ( V_14 ) ;
int V_55 ;
if ( ! F_37 ( V_35 ) )
goto V_56;
V_55 = V_45 -> V_57 ( V_35 ) ;
if ( V_55 < 0 )
return V_55 ;
V_56:
if ( V_35 -> V_52 && V_35 -> V_54 )
F_42 ( V_35 ) ;
return 0 ;
}
static int F_43 ( struct V_11 * V_14 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
struct V_50 * V_51 = V_35 -> V_52 ;
int V_55 ;
if ( ! V_51 )
return 0 ;
V_55 = F_44 ( V_35 ) ;
if ( V_55 < 0 )
return V_55 ;
V_35 -> V_58 = 0 ;
V_35 -> V_8 = V_59 ;
F_42 ( V_35 ) ;
return 0 ;
}
static T_4
F_45 ( struct V_11 * V_14 , struct V_60 * V_61 , char * V_62 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
return sprintf ( V_62 , L_4 , ( unsigned long ) V_35 -> V_47 ) ;
}
static T_4
F_46 ( struct V_11 * V_14 , struct V_60 * V_61 , char * V_62 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
return sprintf ( V_62 , L_5 , F_47 ( V_35 -> V_63 ) ) ;
}
static T_4
F_48 ( struct V_11 * V_14 , struct V_60 * V_61 , char * V_62 )
{
struct V_34 * V_35 = F_34 ( V_14 ) ;
return sprintf ( V_62 , L_6 , V_35 -> V_64 ) ;
}
int T_5 F_49 ( void )
{
int V_55 ;
V_55 = F_50 ( & V_18 ) ;
if ( ! V_55 ) {
V_55 = F_51 ( & V_65 ) ;
if ( V_55 )
F_52 ( & V_18 ) ;
}
return V_55 ;
}
void F_53 ( void )
{
F_52 ( & V_18 ) ;
F_54 ( & V_65 ) ;
}
