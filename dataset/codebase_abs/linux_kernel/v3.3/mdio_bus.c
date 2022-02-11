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
int F_8 ( struct V_1 * V_3 )
{
int V_14 , V_15 ;
if ( NULL == V_3 || NULL == V_3 -> V_16 ||
NULL == V_3 -> V_17 ||
NULL == V_3 -> V_18 )
return - V_19 ;
F_6 ( V_3 -> V_8 != V_9 &&
V_3 -> V_8 != V_20 ) ;
V_3 -> V_21 . V_22 = V_3 -> V_22 ;
V_3 -> V_21 . V_23 = & V_24 ;
V_3 -> V_21 . V_25 = NULL ;
F_9 ( & V_3 -> V_21 , L_1 , V_3 -> V_26 ) ;
V_15 = F_10 ( & V_3 -> V_21 ) ;
if ( V_15 ) {
F_11 ( V_27 L_2 , V_3 -> V_26 ) ;
return - V_19 ;
}
F_12 ( & V_3 -> V_28 ) ;
if ( V_3 -> V_29 )
V_3 -> V_29 ( V_3 ) ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ ) {
if ( ( V_3 -> V_31 & ( 1 << V_14 ) ) == 0 ) {
struct V_32 * V_33 ;
V_33 = F_13 ( V_3 , V_14 ) ;
if ( F_14 ( V_33 ) ) {
V_15 = F_15 ( V_33 ) ;
goto error;
}
}
}
V_3 -> V_8 = V_34 ;
F_16 ( L_3 , V_3 -> V_16 ) ;
return 0 ;
error:
while ( -- V_14 >= 0 ) {
if ( V_3 -> V_35 [ V_14 ] )
F_17 ( & V_3 -> V_35 [ V_14 ] -> V_21 ) ;
}
F_18 ( & V_3 -> V_21 ) ;
return V_15 ;
}
void F_19 ( struct V_1 * V_3 )
{
int V_14 ;
F_6 ( V_3 -> V_8 != V_34 ) ;
V_3 -> V_8 = V_20 ;
F_18 ( & V_3 -> V_21 ) ;
for ( V_14 = 0 ; V_14 < V_30 ; V_14 ++ ) {
if ( V_3 -> V_35 [ V_14 ] )
F_17 ( & V_3 -> V_35 [ V_14 ] -> V_21 ) ;
V_3 -> V_35 [ V_14 ] = NULL ;
}
}
void F_20 ( struct V_1 * V_3 )
{
if ( V_3 -> V_8 == V_9 ) {
F_7 ( V_3 ) ;
return;
}
F_6 ( V_3 -> V_8 != V_20 ) ;
V_3 -> V_8 = V_13 ;
F_21 ( & V_3 -> V_21 ) ;
}
struct V_32 * F_13 ( struct V_1 * V_3 , int V_36 )
{
struct V_32 * V_33 ;
int V_15 ;
V_33 = F_22 ( V_3 , V_36 ) ;
if ( F_14 ( V_33 ) || V_33 == NULL )
return V_33 ;
V_15 = F_23 ( V_33 ) ;
if ( V_15 ) {
F_24 ( V_33 ) ;
return NULL ;
}
return V_33 ;
}
int F_25 ( struct V_1 * V_3 , int V_36 , T_2 V_37 )
{
int V_38 ;
F_6 ( F_26 () ) ;
F_27 ( & V_3 -> V_28 ) ;
V_38 = V_3 -> V_17 ( V_3 , V_36 , V_37 ) ;
F_28 ( & V_3 -> V_28 ) ;
return V_38 ;
}
int F_29 ( struct V_1 * V_3 , int V_36 , T_2 V_37 , T_3 V_39 )
{
int V_15 ;
F_6 ( F_26 () ) ;
F_27 ( & V_3 -> V_28 ) ;
V_15 = V_3 -> V_18 ( V_3 , V_36 , V_37 , V_39 ) ;
F_28 ( & V_3 -> V_28 ) ;
return V_15 ;
}
static int F_30 ( struct V_11 * V_21 , struct V_40 * V_41 )
{
struct V_32 * V_33 = F_31 ( V_21 ) ;
struct V_42 * V_43 = F_32 ( V_41 ) ;
return ( ( V_43 -> V_44 & V_43 -> V_45 ) ==
( V_33 -> V_44 & V_43 -> V_45 ) ) ;
}
static bool F_33 ( struct V_32 * V_33 )
{
struct V_40 * V_41 = V_33 -> V_21 . V_46 ;
struct V_42 * V_43 = F_32 ( V_41 ) ;
struct V_47 * V_48 = V_33 -> V_49 ;
if ( ! V_41 || ! V_43 -> V_50 )
return false ;
if ( ! V_48 )
return true ;
if ( V_48 -> V_21 . V_22 && F_34 ( V_48 -> V_21 . V_22 ) )
return false ;
if ( F_34 ( & V_48 -> V_21 ) )
return false ;
return true ;
}
static int F_35 ( struct V_11 * V_21 )
{
struct V_42 * V_43 = F_32 ( V_21 -> V_46 ) ;
struct V_32 * V_33 = F_31 ( V_21 ) ;
if ( V_33 -> V_49 && V_33 -> V_51 )
F_36 ( V_33 ) ;
if ( ! F_33 ( V_33 ) )
return 0 ;
return V_43 -> V_50 ( V_33 ) ;
}
static int F_37 ( struct V_11 * V_21 )
{
struct V_42 * V_43 = F_32 ( V_21 -> V_46 ) ;
struct V_32 * V_33 = F_31 ( V_21 ) ;
int V_52 ;
if ( ! F_33 ( V_33 ) )
goto V_53;
V_52 = V_43 -> V_54 ( V_33 ) ;
if ( V_52 < 0 )
return V_52 ;
V_53:
if ( V_33 -> V_49 && V_33 -> V_51 )
F_38 ( V_33 , NULL ) ;
return 0 ;
}
static int F_39 ( struct V_11 * V_21 )
{
struct V_32 * V_33 = F_31 ( V_21 ) ;
struct V_47 * V_48 = V_33 -> V_49 ;
int V_52 ;
if ( ! V_48 )
return 0 ;
V_52 = F_40 ( V_33 ) ;
if ( V_52 < 0 )
return V_52 ;
V_33 -> V_55 = 0 ;
V_33 -> V_8 = V_56 ;
F_38 ( V_33 , NULL ) ;
return 0 ;
}
int T_4 F_41 ( void )
{
int V_52 ;
V_52 = F_42 ( & V_24 ) ;
if ( ! V_52 ) {
V_52 = F_43 ( & V_57 ) ;
if ( V_52 )
F_44 ( & V_24 ) ;
}
return V_52 ;
}
void F_45 ( void )
{
F_44 ( & V_24 ) ;
F_46 ( & V_57 ) ;
}
