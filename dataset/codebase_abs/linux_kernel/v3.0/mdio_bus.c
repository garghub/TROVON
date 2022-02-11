struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( V_2 != NULL )
V_2 -> V_4 = V_5 ;
return V_2 ;
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
F_5 ( V_2 -> V_4 != V_8 &&
V_2 -> V_4 != V_5 ) ;
F_6 ( V_2 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_9 , V_10 ;
if ( NULL == V_2 || NULL == V_2 -> V_11 ||
NULL == V_2 -> V_12 ||
NULL == V_2 -> V_13 )
return - V_14 ;
F_5 ( V_2 -> V_4 != V_5 &&
V_2 -> V_4 != V_15 ) ;
V_2 -> V_16 . V_17 = V_2 -> V_17 ;
V_2 -> V_16 . V_18 = & V_19 ;
V_2 -> V_16 . V_20 = NULL ;
F_8 ( & V_2 -> V_16 , L_1 , V_2 -> V_21 ) ;
V_10 = F_9 ( & V_2 -> V_16 ) ;
if ( V_10 ) {
F_10 ( V_22 L_2 , V_2 -> V_21 ) ;
return - V_14 ;
}
F_11 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 )
V_2 -> V_24 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_25 ; V_9 ++ ) {
if ( ( V_2 -> V_26 & ( 1 << V_9 ) ) == 0 ) {
struct V_27 * V_28 ;
V_28 = F_12 ( V_2 , V_9 ) ;
if ( F_13 ( V_28 ) ) {
V_10 = F_14 ( V_28 ) ;
goto error;
}
}
}
V_2 -> V_4 = V_29 ;
F_15 ( L_3 , V_2 -> V_11 ) ;
return 0 ;
error:
while ( -- V_9 >= 0 ) {
if ( V_2 -> V_30 [ V_9 ] )
F_16 ( & V_2 -> V_30 [ V_9 ] -> V_16 ) ;
}
F_17 ( & V_2 -> V_16 ) ;
return V_10 ;
}
void F_18 ( struct V_1 * V_2 )
{
int V_9 ;
F_5 ( V_2 -> V_4 != V_29 ) ;
V_2 -> V_4 = V_15 ;
F_17 ( & V_2 -> V_16 ) ;
for ( V_9 = 0 ; V_9 < V_25 ; V_9 ++ ) {
if ( V_2 -> V_30 [ V_9 ] )
F_16 ( & V_2 -> V_30 [ V_9 ] -> V_16 ) ;
V_2 -> V_30 [ V_9 ] = NULL ;
}
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 == V_5 ) {
F_6 ( V_2 ) ;
return;
}
F_5 ( V_2 -> V_4 != V_15 ) ;
V_2 -> V_4 = V_8 ;
F_20 ( & V_2 -> V_16 ) ;
}
struct V_27 * F_12 ( struct V_1 * V_2 , int V_31 )
{
struct V_27 * V_28 ;
int V_10 ;
V_28 = F_21 ( V_2 , V_31 ) ;
if ( F_13 ( V_28 ) || V_28 == NULL )
return V_28 ;
V_10 = F_22 ( V_28 ) ;
if ( V_10 ) {
F_23 ( V_28 ) ;
return NULL ;
}
return V_28 ;
}
int F_24 ( struct V_1 * V_2 , int V_31 , T_1 V_32 )
{
int V_33 ;
F_5 ( F_25 () ) ;
F_26 ( & V_2 -> V_23 ) ;
V_33 = V_2 -> V_12 ( V_2 , V_31 , V_32 ) ;
F_27 ( & V_2 -> V_23 ) ;
return V_33 ;
}
int F_28 ( struct V_1 * V_2 , int V_31 , T_1 V_32 , T_2 V_34 )
{
int V_10 ;
F_5 ( F_25 () ) ;
F_26 ( & V_2 -> V_23 ) ;
V_10 = V_2 -> V_13 ( V_2 , V_31 , V_32 , V_34 ) ;
F_27 ( & V_2 -> V_23 ) ;
return V_10 ;
}
static int F_29 ( struct V_6 * V_16 , struct V_35 * V_36 )
{
struct V_27 * V_28 = F_30 ( V_16 ) ;
struct V_37 * V_38 = F_31 ( V_36 ) ;
return ( ( V_38 -> V_39 & V_38 -> V_40 ) ==
( V_28 -> V_39 & V_38 -> V_40 ) ) ;
}
static bool F_32 ( struct V_27 * V_28 )
{
struct V_35 * V_36 = V_28 -> V_16 . V_41 ;
struct V_37 * V_38 = F_31 ( V_36 ) ;
struct V_42 * V_43 = V_28 -> V_44 ;
if ( ! V_36 || ! V_38 -> V_45 )
return false ;
if ( ! V_43 )
return true ;
if ( V_43 -> V_16 . V_17 && F_33 ( V_43 -> V_16 . V_17 ) )
return false ;
if ( F_33 ( & V_43 -> V_16 ) )
return false ;
return true ;
}
static int F_34 ( struct V_6 * V_16 )
{
struct V_37 * V_38 = F_31 ( V_16 -> V_41 ) ;
struct V_27 * V_28 = F_30 ( V_16 ) ;
if ( V_28 -> V_44 && V_28 -> V_46 )
F_35 ( V_28 ) ;
if ( ! F_32 ( V_28 ) )
return 0 ;
return V_38 -> V_45 ( V_28 ) ;
}
static int F_36 ( struct V_6 * V_16 )
{
struct V_37 * V_38 = F_31 ( V_16 -> V_41 ) ;
struct V_27 * V_28 = F_30 ( V_16 ) ;
int V_47 ;
if ( ! F_32 ( V_28 ) )
goto V_48;
V_47 = V_38 -> V_49 ( V_28 ) ;
if ( V_47 < 0 )
return V_47 ;
V_48:
if ( V_28 -> V_44 && V_28 -> V_46 )
F_37 ( V_28 , NULL ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_16 )
{
struct V_27 * V_28 = F_30 ( V_16 ) ;
struct V_42 * V_43 = V_28 -> V_44 ;
int V_47 ;
if ( ! V_43 )
return 0 ;
V_47 = F_39 ( V_28 ) ;
if ( V_47 < 0 )
return V_47 ;
V_28 -> V_50 = 0 ;
V_28 -> V_4 = V_51 ;
F_37 ( V_28 , NULL ) ;
return 0 ;
}
int T_3 F_40 ( void )
{
int V_47 ;
V_47 = F_41 ( & V_19 ) ;
if ( ! V_47 ) {
V_47 = F_42 ( & V_52 ) ;
if ( V_47 )
F_43 ( & V_19 ) ;
}
return V_47 ;
}
void F_44 ( void )
{
F_43 ( & V_19 ) ;
F_45 ( & V_52 ) ;
}
