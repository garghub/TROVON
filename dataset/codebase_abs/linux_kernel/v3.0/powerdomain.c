static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 , * V_4 ;
V_3 = NULL ;
F_2 (temp_pwrdm, &pwrdm_list, node) {
if ( ! strcmp ( V_2 , V_4 -> V_2 ) ) {
V_3 = V_4 ;
break;
}
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_3 )
{
int V_5 ;
if ( ! V_3 || ! V_3 -> V_2 )
return - V_6 ;
if ( ! F_4 ( V_3 -> V_7 ) )
return - V_6 ;
if ( F_5 () &&
V_3 -> V_8 == V_9 ) {
F_6 ( L_1 ,
V_3 -> V_2 ) ;
return - V_6 ;
}
if ( F_1 ( V_3 -> V_2 ) )
return - V_10 ;
F_7 ( & V_3 -> V_11 , & V_12 ) ;
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ )
V_3 -> V_14 [ V_5 ] = 0 ;
V_3 -> V_15 = 0 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_16 ; V_5 ++ )
V_3 -> V_17 [ V_5 ] = 0 ;
F_8 ( V_3 ) ;
V_3 -> V_18 = F_9 ( V_3 ) ;
V_3 -> V_14 [ V_3 -> V_18 ] = 1 ;
F_10 ( L_2 , V_3 -> V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_3 )
{
int V_5 ;
T_1 V_19 , V_20 ;
V_19 = F_12 ( V_3 ) ;
if ( ( V_3 -> V_21 == V_22 ) &&
( V_19 == V_23 ) )
V_3 -> V_15 ++ ;
for ( V_5 = 0 ; V_5 < V_3 -> V_16 ; V_5 ++ ) {
V_20 = F_13 ( V_3 , V_5 ) ;
if ( ( V_3 -> V_24 [ V_5 ] == V_22 ) &&
( V_20 == V_23 ) )
V_3 -> V_17 [ V_5 ] ++ ;
}
}
static int F_14 ( struct V_1 * V_3 , int V_25 )
{
int V_26 , V_18 , V_27 = 0 ;
if ( V_3 == NULL )
return - V_6 ;
V_18 = F_9 ( V_3 ) ;
switch ( V_25 ) {
case V_28 :
V_26 = V_3 -> V_18 ;
break;
case V_29 :
V_26 = F_15 ( V_3 ) ;
if ( V_3 -> V_18 != V_26 )
V_3 -> V_14 [ V_26 ] ++ ;
if ( V_26 == V_30 )
F_11 ( V_3 ) ;
if ( V_18 != V_26 ) {
V_27 = ( V_31 |
( ( V_18 & V_32 ) << 8 ) |
( ( V_26 & V_32 ) << 0 ) ) ;
F_16 ( V_3 -> V_2 , V_27 ,
F_17 () ) ;
}
break;
default:
return - V_6 ;
}
if ( V_18 != V_26 )
V_3 -> V_14 [ V_18 ] ++ ;
F_18 ( V_3 , V_26 ) ;
V_3 -> V_18 = V_18 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_3 , void * V_33 )
{
F_20 ( V_3 ) ;
F_14 ( V_3 , V_28 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_3 , void * V_33 )
{
F_14 ( V_3 , V_29 ) ;
return 0 ;
}
void F_22 ( struct V_1 * * V_12 , struct V_34 * V_35 )
{
struct V_1 * * V_36 = NULL ;
if ( ! V_35 )
F_23 ( 1 , L_3 ) ;
else
V_37 = V_35 ;
if ( V_12 ) {
for ( V_36 = V_12 ; * V_36 ; V_36 ++ )
F_3 ( * V_36 ) ;
}
}
struct V_1 * F_24 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return NULL ;
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
int F_25 ( int (* F_26)( struct V_1 * V_3 , void * V_38 ) ,
void * V_38 )
{
struct V_1 * V_4 ;
int V_39 = 0 ;
if ( ! F_26 )
return - V_6 ;
F_2 (temp_pwrdm, &pwrdm_list, node) {
V_39 = (* F_26)( V_4 , V_38 ) ;
if ( V_39 )
break;
}
return V_39 ;
}
int F_27 ( struct V_1 * V_3 , struct V_40 * V_41 )
{
int V_5 ;
int V_39 = - V_6 ;
if ( ! V_3 || ! V_41 )
return - V_6 ;
F_10 ( L_4
L_5 , V_41 -> V_2 , V_3 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_42 ; V_5 ++ ) {
if ( ! V_3 -> V_43 [ V_5 ] )
break;
#ifdef F_28
if ( V_3 -> V_43 [ V_5 ] == V_41 ) {
V_39 = - V_6 ;
goto V_44;
}
#endif
}
if ( V_5 == V_42 ) {
F_10 ( L_6
L_7 , V_3 -> V_2 , V_41 -> V_2 ) ;
F_29 ( 1 ) ;
V_39 = - V_45 ;
goto V_44;
}
V_3 -> V_43 [ V_5 ] = V_41 ;
V_39 = 0 ;
V_44:
return V_39 ;
}
int F_30 ( struct V_1 * V_3 , struct V_40 * V_41 )
{
int V_39 = - V_6 ;
int V_5 ;
if ( ! V_3 || ! V_41 )
return - V_6 ;
F_10 ( L_8
L_5 , V_41 -> V_2 , V_3 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_42 ; V_5 ++ )
if ( V_3 -> V_43 [ V_5 ] == V_41 )
break;
if ( V_5 == V_42 ) {
F_10 ( L_9
L_10 , V_41 -> V_2 , V_3 -> V_2 ) ;
V_39 = - V_46 ;
goto V_47;
}
V_3 -> V_43 [ V_5 ] = NULL ;
V_39 = 0 ;
V_47:
return V_39 ;
}
int F_31 ( struct V_1 * V_3 ,
int (* F_26)( struct V_1 * V_3 ,
struct V_40 * V_41 ) )
{
int V_39 = 0 ;
int V_5 ;
if ( ! F_26 )
return - V_6 ;
for ( V_5 = 0 ; V_5 < V_42 && ! V_39 ; V_5 ++ )
V_39 = (* F_26)( V_3 , V_3 -> V_43 [ V_5 ] ) ;
return V_39 ;
}
int F_32 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_6 ;
return V_3 -> V_16 ;
}
int F_33 ( struct V_1 * V_3 , T_1 V_48 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( ! ( V_3 -> V_49 & ( 1 << V_48 ) ) )
return - V_6 ;
F_10 ( L_11 ,
V_3 -> V_2 , V_48 ) ;
if ( V_37 && V_37 -> F_33 ) {
F_16 ( V_3 -> V_2 , V_48 ,
F_17 () ) ;
V_39 = V_37 -> F_33 ( V_3 , V_48 ) ;
}
return V_39 ;
}
int F_34 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_37 && V_37 -> F_34 )
V_39 = V_37 -> F_34 ( V_3 ) ;
return V_39 ;
}
int F_9 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_37 && V_37 -> F_9 )
V_39 = V_37 -> F_9 ( V_3 ) ;
return V_39 ;
}
int F_15 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_37 && V_37 -> F_15 )
V_39 = V_37 -> F_15 ( V_3 ) ;
return V_39 ;
}
int F_35 ( struct V_1 * V_3 , T_1 V_48 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( ! ( V_3 -> V_21 & ( 1 << V_48 ) ) )
return - V_6 ;
F_10 ( L_12 ,
V_3 -> V_2 , V_48 ) ;
if ( V_37 && V_37 -> F_35 )
V_39 = V_37 -> F_35 ( V_3 , V_48 ) ;
return V_39 ;
}
int F_36 ( struct V_1 * V_3 , T_1 V_50 , T_1 V_48 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_3 -> V_16 < ( V_50 + 1 ) )
return - V_10 ;
if ( ! ( V_3 -> V_51 [ V_50 ] & ( 1 << V_48 ) ) )
return - V_6 ;
F_10 ( L_13
L_14 , V_3 -> V_2 , V_50 , V_48 ) ;
if ( V_37 && V_37 -> F_36 )
V_39 = V_37 -> F_36 ( V_3 , V_50 , V_48 ) ;
return V_39 ;
}
int F_37 ( struct V_1 * V_3 , T_1 V_50 , T_1 V_48 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_3 -> V_16 < ( V_50 + 1 ) )
return - V_10 ;
if ( ! ( V_3 -> V_24 [ V_50 ] & ( 1 << V_48 ) ) )
return - V_6 ;
F_10 ( L_13
L_15 , V_3 -> V_2 , V_50 , V_48 ) ;
if ( V_37 && V_37 -> F_37 )
V_39 = V_37 -> F_37 ( V_3 , V_50 , V_48 ) ;
return V_39 ;
}
int F_38 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_37 && V_37 -> F_38 )
V_39 = V_37 -> F_38 ( V_3 ) ;
return V_39 ;
}
int F_12 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_37 && V_37 -> F_12 )
V_39 = V_37 -> F_12 ( V_3 ) ;
return V_39 ;
}
int F_39 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_37 && V_37 -> F_39 )
V_39 = V_37 -> F_39 ( V_3 ) ;
return V_39 ;
}
int F_40 ( struct V_1 * V_3 , T_1 V_50 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return V_39 ;
if ( V_3 -> V_16 < ( V_50 + 1 ) )
return V_39 ;
if ( V_3 -> V_52 & V_53 )
V_50 = 1 ;
if ( V_37 && V_37 -> F_40 )
V_39 = V_37 -> F_40 ( V_3 , V_50 ) ;
return V_39 ;
}
int F_13 ( struct V_1 * V_3 , T_1 V_50 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return V_39 ;
if ( V_3 -> V_16 < ( V_50 + 1 ) )
return V_39 ;
if ( V_3 -> V_52 & V_53 )
V_50 = 1 ;
if ( V_37 && V_37 -> F_13 )
V_39 = V_37 -> F_13 ( V_3 , V_50 ) ;
return V_39 ;
}
int F_41 ( struct V_1 * V_3 , T_1 V_50 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return V_39 ;
if ( V_3 -> V_16 < ( V_50 + 1 ) )
return V_39 ;
if ( V_37 && V_37 -> F_41 )
V_39 = V_37 -> F_41 ( V_3 , V_50 ) ;
return V_39 ;
}
int F_20 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return V_39 ;
F_10 ( L_16 ,
V_3 -> V_2 ) ;
if ( V_37 && V_37 -> F_20 )
V_39 = V_37 -> F_20 ( V_3 ) ;
return V_39 ;
}
int F_42 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return V_39 ;
if ( ! ( V_3 -> V_52 & V_54 ) )
return V_39 ;
F_10 ( L_17 ,
V_3 -> V_2 ) ;
if ( V_37 && V_37 -> F_42 )
V_39 = V_37 -> F_42 ( V_3 ) ;
return V_39 ;
}
int F_43 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return V_39 ;
if ( ! ( V_3 -> V_52 & V_54 ) )
return V_39 ;
F_10 ( L_18 ,
V_3 -> V_2 ) ;
if ( V_37 && V_37 -> F_43 )
V_39 = V_37 -> F_43 ( V_3 ) ;
return V_39 ;
}
bool F_44 ( struct V_1 * V_3 )
{
return ( V_3 && V_3 -> V_52 & V_54 ) ? 1 : 0 ;
}
int F_45 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( ! ( V_3 -> V_52 & V_55 ) )
return - V_6 ;
F_10 ( L_19 ,
V_3 -> V_2 ) ;
if ( V_37 && V_37 -> F_45 )
V_39 = V_37 -> F_45 ( V_3 ) ;
return V_39 ;
}
int F_8 ( struct V_1 * V_3 )
{
int V_39 = - V_6 ;
if ( ! V_3 )
return - V_6 ;
if ( V_37 && V_37 -> F_8 )
V_39 = V_37 -> F_8 ( V_3 ) ;
return V_39 ;
}
int F_46 ( struct V_1 * V_3 )
{
return F_14 ( V_3 , V_28 ) ;
}
int F_47 ( struct V_40 * V_41 )
{
if ( V_41 != NULL && V_41 -> V_3 . V_56 != NULL ) {
F_8 ( V_41 -> V_3 . V_56 ) ;
return F_46 ( V_41 -> V_3 . V_56 ) ;
}
return - V_6 ;
}
int F_48 ( void )
{
F_25 ( F_19 , NULL ) ;
return 0 ;
}
int F_49 ( void )
{
F_25 ( F_21 , NULL ) ;
return 0 ;
}
T_2 F_50 ( struct V_1 * V_3 )
{
int V_5 , V_57 ;
if ( ! V_3 ) {
F_23 ( 1 , L_20 , V_58 ) ;
return 0 ;
}
V_57 = V_3 -> V_14 [ V_23 ] ;
V_57 += V_3 -> V_15 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_16 ; V_5 ++ )
V_57 += V_3 -> V_17 [ V_5 ] ;
F_10 ( L_21 ,
V_3 -> V_2 , V_57 ) ;
return V_57 ;
}
bool F_51 ( struct V_1 * V_3 )
{
int V_5 ;
if ( F_52 ( V_3 ) ) {
F_10 ( L_22 ,
V_58 ) ;
return 1 ;
}
if ( V_3 -> V_49 & V_59 )
return 1 ;
if ( V_3 -> V_49 & V_60 ) {
if ( V_3 -> V_21 & V_59 )
return 1 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_16 ; V_5 ++ )
if ( V_3 -> V_24 [ V_5 ] & V_59 )
return 1 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_16 ; V_5 ++ )
if ( V_3 -> V_51 [ V_5 ] & V_59 )
return 1 ;
return 0 ;
}
