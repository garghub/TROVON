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
struct V_6 * V_7 ;
if ( ! V_3 || ! V_3 -> V_2 )
return - V_8 ;
if ( F_4 () &&
V_3 -> V_9 == V_10 ) {
F_5 ( L_1 ,
V_3 -> V_2 ) ;
return - V_8 ;
}
if ( F_1 ( V_3 -> V_2 ) )
return - V_11 ;
V_7 = F_6 ( V_3 -> V_7 . V_2 ) ;
if ( ! V_7 ) {
F_5 ( L_2 ,
V_3 -> V_2 , V_3 -> V_7 . V_2 ) ;
return - V_8 ;
}
V_3 -> V_7 . V_12 = V_7 ;
F_7 ( & V_3 -> V_13 ) ;
F_8 ( V_7 , V_3 ) ;
F_9 ( & V_3 -> V_14 , & V_15 ) ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ )
V_3 -> V_17 [ V_5 ] = 0 ;
V_3 -> V_18 = 0 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_19 ; V_5 ++ )
V_3 -> V_20 [ V_5 ] = 0 ;
F_10 ( V_3 ) ;
V_3 -> V_21 = F_11 ( V_3 ) ;
V_3 -> V_17 [ V_3 -> V_21 ] = 1 ;
F_12 ( L_3 , V_3 -> V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_3 )
{
int V_5 ;
T_1 V_22 , V_23 ;
V_22 = F_14 ( V_3 ) ;
if ( ( V_3 -> V_24 == V_25 ) &&
( V_22 == V_26 ) )
V_3 -> V_18 ++ ;
for ( V_5 = 0 ; V_5 < V_3 -> V_19 ; V_5 ++ ) {
V_23 = F_15 ( V_3 , V_5 ) ;
if ( ( V_3 -> V_27 [ V_5 ] == V_25 ) &&
( V_23 == V_26 ) )
V_3 -> V_20 [ V_5 ] ++ ;
}
}
static int F_16 ( struct V_1 * V_3 , int V_28 )
{
int V_29 , V_21 , V_30 = 0 ;
if ( V_3 == NULL )
return - V_8 ;
V_21 = F_11 ( V_3 ) ;
switch ( V_28 ) {
case V_31 :
V_29 = V_3 -> V_21 ;
break;
case V_32 :
V_29 = F_17 ( V_3 ) ;
if ( V_3 -> V_21 != V_29 )
V_3 -> V_17 [ V_29 ] ++ ;
if ( V_29 == V_33 )
F_13 ( V_3 ) ;
if ( V_21 != V_29 ) {
V_30 = ( V_34 |
( ( V_21 & V_35 ) << 8 ) |
( ( V_29 & V_35 ) << 0 ) ) ;
F_18 ( V_3 -> V_2 , V_30 ,
F_19 () ) ;
}
break;
default:
return - V_8 ;
}
if ( V_21 != V_29 )
V_3 -> V_17 [ V_21 ] ++ ;
F_20 ( V_3 , V_29 ) ;
V_3 -> V_21 = V_21 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_3 , void * V_36 )
{
F_22 ( V_3 ) ;
F_16 ( V_3 , V_31 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_3 , void * V_36 )
{
F_16 ( V_3 , V_32 ) ;
return 0 ;
}
int F_24 ( struct V_37 * V_38 )
{
if ( ! V_38 )
return - V_8 ;
if ( V_39 )
return - V_11 ;
V_39 = V_38 ;
return 0 ;
}
int F_25 ( struct V_1 * * V_40 )
{
struct V_1 * * V_41 = NULL ;
if ( ! V_39 )
return - V_11 ;
if ( ! V_40 )
return - V_8 ;
for ( V_41 = V_40 ; * V_41 ; V_41 ++ )
F_3 ( * V_41 ) ;
return 0 ;
}
int F_26 ( void )
{
struct V_1 * V_42 ;
if ( F_27 ( & V_15 ) )
return - V_43 ;
F_2 (temp_p, &pwrdm_list, node)
F_28 ( V_42 , V_44 ) ;
return 0 ;
}
struct V_1 * F_29 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return NULL ;
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
int F_30 ( int (* F_31)( struct V_1 * V_3 , void * V_45 ) ,
void * V_45 )
{
struct V_1 * V_4 ;
int V_46 = 0 ;
if ( ! F_31 )
return - V_8 ;
F_2 (temp_pwrdm, &pwrdm_list, node) {
V_46 = (* F_31)( V_4 , V_45 ) ;
if ( V_46 )
break;
}
return V_46 ;
}
int F_32 ( struct V_1 * V_3 , struct V_47 * V_48 )
{
int V_5 ;
int V_46 = - V_8 ;
if ( ! V_3 || ! V_48 )
return - V_8 ;
F_12 ( L_4
L_5 , V_48 -> V_2 , V_3 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_49 ; V_5 ++ ) {
if ( ! V_3 -> V_50 [ V_5 ] )
break;
#ifdef F_33
if ( V_3 -> V_50 [ V_5 ] == V_48 ) {
V_46 = - V_8 ;
goto V_51;
}
#endif
}
if ( V_5 == V_49 ) {
F_12 ( L_6
L_7 , V_3 -> V_2 , V_48 -> V_2 ) ;
F_34 ( 1 ) ;
V_46 = - V_52 ;
goto V_51;
}
V_3 -> V_50 [ V_5 ] = V_48 ;
V_46 = 0 ;
V_51:
return V_46 ;
}
int F_35 ( struct V_1 * V_3 , struct V_47 * V_48 )
{
int V_46 = - V_8 ;
int V_5 ;
if ( ! V_3 || ! V_48 )
return - V_8 ;
F_12 ( L_8
L_5 , V_48 -> V_2 , V_3 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_49 ; V_5 ++ )
if ( V_3 -> V_50 [ V_5 ] == V_48 )
break;
if ( V_5 == V_49 ) {
F_12 ( L_9
L_10 , V_48 -> V_2 , V_3 -> V_2 ) ;
V_46 = - V_53 ;
goto V_54;
}
V_3 -> V_50 [ V_5 ] = NULL ;
V_46 = 0 ;
V_54:
return V_46 ;
}
int F_36 ( struct V_1 * V_3 ,
int (* F_31)( struct V_1 * V_3 ,
struct V_47 * V_48 ) )
{
int V_46 = 0 ;
int V_5 ;
if ( ! F_31 )
return - V_8 ;
for ( V_5 = 0 ; V_5 < V_49 && ! V_46 ; V_5 ++ )
V_46 = (* F_31)( V_3 , V_3 -> V_50 [ V_5 ] ) ;
return V_46 ;
}
struct V_6 * F_37 ( struct V_1 * V_3 )
{
return V_3 -> V_7 . V_12 ;
}
int F_38 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_8 ;
return V_3 -> V_19 ;
}
int F_28 ( struct V_1 * V_3 , T_1 V_55 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_56 & ( 1 << V_55 ) ) )
return - V_8 ;
F_12 ( L_11 ,
V_3 -> V_2 , V_55 ) ;
if ( V_39 && V_39 -> F_28 ) {
F_18 ( V_3 -> V_2 , V_55 ,
F_19 () ) ;
V_46 = V_39 -> F_28 ( V_3 , V_55 ) ;
}
return V_46 ;
}
int F_39 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_39 && V_39 -> F_39 )
V_46 = V_39 -> F_39 ( V_3 ) ;
return V_46 ;
}
int F_11 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_56 == V_57 )
return V_44 ;
if ( V_39 && V_39 -> F_11 )
V_46 = V_39 -> F_11 ( V_3 ) ;
return V_46 ;
}
int F_17 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_39 && V_39 -> F_17 )
V_46 = V_39 -> F_17 ( V_3 ) ;
return V_46 ;
}
int F_40 ( struct V_1 * V_3 , T_1 V_55 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_24 & ( 1 << V_55 ) ) )
return - V_8 ;
F_12 ( L_12 ,
V_3 -> V_2 , V_55 ) ;
if ( V_39 && V_39 -> F_40 )
V_46 = V_39 -> F_40 ( V_3 , V_55 ) ;
return V_46 ;
}
int F_41 ( struct V_1 * V_3 , T_1 V_58 , T_1 V_55 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_19 < ( V_58 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_59 [ V_58 ] & ( 1 << V_55 ) ) )
return - V_8 ;
F_12 ( L_13
L_14 , V_3 -> V_2 , V_58 , V_55 ) ;
if ( V_39 && V_39 -> F_41 )
V_46 = V_39 -> F_41 ( V_3 , V_58 , V_55 ) ;
return V_46 ;
}
int F_42 ( struct V_1 * V_3 , T_1 V_58 , T_1 V_55 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_19 < ( V_58 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_27 [ V_58 ] & ( 1 << V_55 ) ) )
return - V_8 ;
F_12 ( L_13
L_15 , V_3 -> V_2 , V_58 , V_55 ) ;
if ( V_39 && V_39 -> F_42 )
V_46 = V_39 -> F_42 ( V_3 , V_58 , V_55 ) ;
return V_46 ;
}
int F_43 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_39 && V_39 -> F_43 )
V_46 = V_39 -> F_43 ( V_3 ) ;
return V_46 ;
}
int F_14 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_39 && V_39 -> F_14 )
V_46 = V_39 -> F_14 ( V_3 ) ;
return V_46 ;
}
int F_44 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_39 && V_39 -> F_44 )
V_46 = V_39 -> F_44 ( V_3 ) ;
return V_46 ;
}
int F_45 ( struct V_1 * V_3 , T_1 V_58 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return V_46 ;
if ( V_3 -> V_19 < ( V_58 + 1 ) )
return V_46 ;
if ( V_3 -> V_60 & V_61 )
V_58 = 1 ;
if ( V_39 && V_39 -> F_45 )
V_46 = V_39 -> F_45 ( V_3 , V_58 ) ;
return V_46 ;
}
int F_15 ( struct V_1 * V_3 , T_1 V_58 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return V_46 ;
if ( V_3 -> V_19 < ( V_58 + 1 ) )
return V_46 ;
if ( V_3 -> V_60 & V_61 )
V_58 = 1 ;
if ( V_39 && V_39 -> F_15 )
V_46 = V_39 -> F_15 ( V_3 , V_58 ) ;
return V_46 ;
}
int F_46 ( struct V_1 * V_3 , T_1 V_58 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return V_46 ;
if ( V_3 -> V_19 < ( V_58 + 1 ) )
return V_46 ;
if ( V_39 && V_39 -> F_46 )
V_46 = V_39 -> F_46 ( V_3 , V_58 ) ;
return V_46 ;
}
int F_22 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return V_46 ;
F_12 ( L_16 ,
V_3 -> V_2 ) ;
if ( V_39 && V_39 -> F_22 )
V_46 = V_39 -> F_22 ( V_3 ) ;
return V_46 ;
}
int F_47 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return V_46 ;
if ( ! ( V_3 -> V_60 & V_62 ) )
return V_46 ;
F_12 ( L_17 ,
V_3 -> V_2 ) ;
if ( V_39 && V_39 -> F_47 )
V_46 = V_39 -> F_47 ( V_3 ) ;
return V_46 ;
}
int F_48 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return V_46 ;
if ( ! ( V_3 -> V_60 & V_62 ) )
return V_46 ;
F_12 ( L_18 ,
V_3 -> V_2 ) ;
if ( V_39 && V_39 -> F_48 )
V_46 = V_39 -> F_48 ( V_3 ) ;
return V_46 ;
}
bool F_49 ( struct V_1 * V_3 )
{
return ( V_3 && V_3 -> V_60 & V_62 ) ? 1 : 0 ;
}
int F_50 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_60 & V_63 ) )
return - V_8 ;
F_12 ( L_19 ,
V_3 -> V_2 ) ;
if ( V_39 && V_39 -> F_50 )
V_46 = V_39 -> F_50 ( V_3 ) ;
return V_46 ;
}
int F_10 ( struct V_1 * V_3 )
{
int V_46 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_39 && V_39 -> F_10 )
V_46 = V_39 -> F_10 ( V_3 ) ;
return V_46 ;
}
int F_51 ( struct V_1 * V_3 )
{
int V_46 ;
V_46 = F_10 ( V_3 ) ;
if ( ! V_46 )
V_46 = F_16 ( V_3 , V_31 ) ;
return V_46 ;
}
int F_52 ( struct V_1 * V_3 )
{
if ( V_3 )
F_21 ( V_3 , NULL ) ;
else
F_30 ( F_21 , NULL ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_3 )
{
if ( V_3 )
F_23 ( V_3 , NULL ) ;
else
F_30 ( F_23 , NULL ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_3 )
{
int V_5 , V_64 ;
if ( ! V_3 ) {
F_55 ( 1 , L_20 , V_65 ) ;
return - V_66 ;
}
V_64 = V_3 -> V_17 [ V_26 ] ;
V_64 += V_3 -> V_18 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_19 ; V_5 ++ )
V_64 += V_3 -> V_20 [ V_5 ] ;
V_64 &= V_67 ;
F_12 ( L_21 ,
V_3 -> V_2 , V_64 ) ;
return V_64 ;
}
bool F_56 ( struct V_1 * V_3 )
{
int V_5 ;
if ( F_57 ( V_3 ) ) {
F_12 ( L_22 ,
V_65 ) ;
return 1 ;
}
if ( V_3 -> V_56 & V_68 )
return 1 ;
if ( V_3 -> V_56 & V_69 ) {
if ( V_3 -> V_24 & V_68 )
return 1 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_19 ; V_5 ++ )
if ( V_3 -> V_27 [ V_5 ] & V_68 )
return 1 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_19 ; V_5 ++ )
if ( V_3 -> V_59 [ V_5 ] & V_68 )
return 1 ;
return 0 ;
}
