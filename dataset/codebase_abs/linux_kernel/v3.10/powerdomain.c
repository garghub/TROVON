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
F_9 ( & V_3 -> V_14 ) ;
F_10 ( & V_3 -> V_15 , & V_16 ) ;
for ( V_5 = 0 ; V_5 < V_17 ; V_5 ++ )
V_3 -> V_18 [ V_5 ] = 0 ;
V_3 -> V_19 = 0 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_20 ; V_5 ++ )
V_3 -> V_21 [ V_5 ] = 0 ;
V_22 -> V_23 ( V_3 ) ;
V_3 -> V_24 = F_11 ( V_3 ) ;
V_3 -> V_18 [ V_3 -> V_24 ] = 1 ;
F_12 ( L_3 , V_3 -> V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_3 )
{
int V_5 ;
T_1 V_25 , V_26 ;
V_25 = F_14 ( V_3 ) ;
if ( ( V_3 -> V_27 == V_28 ) &&
( V_25 == V_29 ) )
V_3 -> V_19 ++ ;
for ( V_5 = 0 ; V_5 < V_3 -> V_20 ; V_5 ++ ) {
V_26 = F_15 ( V_3 , V_5 ) ;
if ( ( V_3 -> V_30 [ V_5 ] == V_28 ) &&
( V_26 == V_29 ) )
V_3 -> V_21 [ V_5 ] ++ ;
}
}
static int F_16 ( struct V_1 * V_3 , int V_31 )
{
int V_32 , V_33 , V_24 , V_34 = 0 ;
if ( V_3 == NULL )
return - V_8 ;
V_24 = F_11 ( V_3 ) ;
switch ( V_31 ) {
case V_35 :
V_32 = V_3 -> V_24 ;
break;
case V_36 :
V_32 = F_17 ( V_3 ) ;
if ( V_3 -> V_24 != V_32 )
V_3 -> V_18 [ V_32 ] ++ ;
if ( V_32 == V_37 )
F_13 ( V_3 ) ;
V_33 = F_18 ( V_3 ) ;
if ( V_33 != V_32 ) {
V_34 = ( V_38 |
( ( V_33 & V_39 ) << 8 ) |
( ( V_32 & V_39 ) << 0 ) ) ;
F_19 ( V_3 -> V_2 , V_34 ,
F_20 () ) ;
}
break;
default:
return - V_8 ;
}
if ( V_24 != V_32 )
V_3 -> V_18 [ V_24 ] ++ ;
F_21 ( V_3 , V_32 ) ;
V_3 -> V_24 = V_24 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_3 , void * V_40 )
{
F_23 ( V_3 ) ;
F_16 ( V_3 , V_35 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_3 , void * V_40 )
{
F_16 ( V_3 , V_36 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_3 ,
T_1 V_41 , T_1 V_42 ,
bool * V_43 )
{
T_1 V_44 ;
if ( V_41 < V_45 ) {
if ( V_41 > V_42 &&
V_3 -> V_46 & V_47 &&
V_22 -> V_48 ) {
V_44 = V_49 ;
} else {
* V_43 = F_26 ( V_3 -> V_50 [ 0 ] ) ;
F_27 ( V_3 -> V_50 [ 0 ] ) ;
V_44 = V_51 ;
}
} else {
V_44 = V_52 ;
}
return V_44 ;
}
static void F_28 ( struct V_1 * V_3 ,
T_1 V_44 , bool V_43 )
{
switch ( V_44 ) {
case V_51 :
if ( V_43 )
F_29 ( V_3 -> V_50 [ 0 ] ) ;
else
F_30 ( V_3 -> V_50 [ 0 ] ) ;
break;
case V_49 :
if ( V_3 -> V_46 & V_47 &&
V_22 -> V_48 )
V_22 -> V_48 ( V_3 ) ;
F_31 ( V_3 ) ;
break;
}
}
int F_32 ( struct V_53 * V_54 )
{
if ( ! V_54 )
return - V_8 ;
if ( V_22 )
return - V_11 ;
V_22 = V_54 ;
return 0 ;
}
int F_33 ( struct V_1 * * V_55 )
{
struct V_1 * * V_56 = NULL ;
if ( ! V_22 )
return - V_11 ;
if ( ! V_55 )
return - V_8 ;
for ( V_56 = V_55 ; * V_56 ; V_56 ++ )
F_3 ( * V_56 ) ;
return 0 ;
}
int F_34 ( void )
{
struct V_1 * V_57 ;
if ( F_35 ( & V_16 ) )
return - V_58 ;
F_2 (temp_p, &pwrdm_list, node)
F_36 ( V_57 , V_45 ) ;
return 0 ;
}
void F_37 ( struct V_1 * V_3 )
__acquires( &pwrdm->_lock
void F_38 ( struct V_1 * V_3 )
__releases( &pwrdm->_lock
struct V_1 * F_39 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return NULL ;
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
int F_40 ( int (* F_41)( struct V_1 * V_3 , void * V_59 ) ,
void * V_59 )
{
struct V_1 * V_4 ;
int V_60 = 0 ;
if ( ! F_41 )
return - V_8 ;
F_2 (temp_pwrdm, &pwrdm_list, node) {
V_60 = (* F_41)( V_4 , V_59 ) ;
if ( V_60 )
break;
}
return V_60 ;
}
int F_42 ( struct V_1 * V_3 , struct V_61 * V_62 )
{
int V_5 ;
int V_60 = - V_8 ;
if ( ! V_3 || ! V_62 )
return - V_8 ;
F_12 ( L_4 ,
V_3 -> V_2 , V_62 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_63 ; V_5 ++ ) {
if ( ! V_3 -> V_50 [ V_5 ] )
break;
#ifdef F_43
if ( V_3 -> V_50 [ V_5 ] == V_62 ) {
V_60 = - V_8 ;
goto V_64;
}
#endif
}
if ( V_5 == V_63 ) {
F_12 ( L_5 ,
V_3 -> V_2 , V_62 -> V_2 ) ;
F_44 ( 1 ) ;
V_60 = - V_65 ;
goto V_64;
}
V_3 -> V_50 [ V_5 ] = V_62 ;
V_60 = 0 ;
V_64:
return V_60 ;
}
int F_45 ( struct V_1 * V_3 , struct V_61 * V_62 )
{
int V_60 = - V_8 ;
int V_5 ;
if ( ! V_3 || ! V_62 )
return - V_8 ;
F_12 ( L_6 ,
V_3 -> V_2 , V_62 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_63 ; V_5 ++ )
if ( V_3 -> V_50 [ V_5 ] == V_62 )
break;
if ( V_5 == V_63 ) {
F_12 ( L_7 ,
V_3 -> V_2 , V_62 -> V_2 ) ;
V_60 = - V_66 ;
goto V_67;
}
V_3 -> V_50 [ V_5 ] = NULL ;
V_60 = 0 ;
V_67:
return V_60 ;
}
int F_46 ( struct V_1 * V_3 ,
int (* F_41)( struct V_1 * V_3 ,
struct V_61 * V_62 ) )
{
int V_60 = 0 ;
int V_5 ;
if ( ! F_41 )
return - V_8 ;
for ( V_5 = 0 ; V_5 < V_63 && ! V_60 ; V_5 ++ )
V_60 = (* F_41)( V_3 , V_3 -> V_50 [ V_5 ] ) ;
return V_60 ;
}
struct V_6 * F_47 ( struct V_1 * V_3 )
{
return V_3 -> V_7 . V_12 ;
}
int F_48 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_8 ;
return V_3 -> V_20 ;
}
int F_36 ( struct V_1 * V_3 , T_1 V_42 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_68 & ( 1 << V_42 ) ) )
return - V_8 ;
F_12 ( L_8 ,
V_3 -> V_2 , V_42 ) ;
if ( V_22 && V_22 -> F_36 ) {
F_19 ( V_3 -> V_2 , V_42 ,
F_20 () ) ;
V_60 = V_22 -> F_36 ( V_3 , V_42 ) ;
}
return V_60 ;
}
int F_18 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_18 )
V_60 = V_22 -> F_18 ( V_3 ) ;
return V_60 ;
}
int F_11 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_68 == V_69 )
return V_45 ;
if ( V_22 && V_22 -> F_11 )
V_60 = V_22 -> F_11 ( V_3 ) ;
return V_60 ;
}
int F_17 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_17 )
V_60 = V_22 -> F_17 ( V_3 ) ;
return V_60 ;
}
int F_49 ( struct V_1 * V_3 , T_1 V_42 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_27 & ( 1 << V_42 ) ) )
return - V_8 ;
F_12 ( L_9 ,
V_3 -> V_2 , V_42 ) ;
if ( V_22 && V_22 -> F_49 )
V_60 = V_22 -> F_49 ( V_3 , V_42 ) ;
return V_60 ;
}
int F_50 ( struct V_1 * V_3 , T_1 V_70 , T_1 V_42 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_20 < ( V_70 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_71 [ V_70 ] & ( 1 << V_42 ) ) )
return - V_8 ;
F_12 ( L_10 ,
V_3 -> V_2 , V_70 , V_42 ) ;
if ( V_22 && V_22 -> F_50 )
V_60 = V_22 -> F_50 ( V_3 , V_70 , V_42 ) ;
return V_60 ;
}
int F_51 ( struct V_1 * V_3 , T_1 V_70 , T_1 V_42 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_20 < ( V_70 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_30 [ V_70 ] & ( 1 << V_42 ) ) )
return - V_8 ;
F_12 ( L_11 ,
V_3 -> V_2 , V_70 , V_42 ) ;
if ( V_22 && V_22 -> F_51 )
V_60 = V_22 -> F_51 ( V_3 , V_70 , V_42 ) ;
return V_60 ;
}
int F_52 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_52 )
V_60 = V_22 -> F_52 ( V_3 ) ;
return V_60 ;
}
int F_14 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_14 )
V_60 = V_22 -> F_14 ( V_3 ) ;
return V_60 ;
}
int F_53 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_53 )
V_60 = V_22 -> F_53 ( V_3 ) ;
return V_60 ;
}
int F_54 ( struct V_1 * V_3 , T_1 V_70 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return V_60 ;
if ( V_3 -> V_20 < ( V_70 + 1 ) )
return V_60 ;
if ( V_3 -> V_46 & V_72 )
V_70 = 1 ;
if ( V_22 && V_22 -> F_54 )
V_60 = V_22 -> F_54 ( V_3 , V_70 ) ;
return V_60 ;
}
int F_15 ( struct V_1 * V_3 , T_1 V_70 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return V_60 ;
if ( V_3 -> V_20 < ( V_70 + 1 ) )
return V_60 ;
if ( V_3 -> V_46 & V_72 )
V_70 = 1 ;
if ( V_22 && V_22 -> F_15 )
V_60 = V_22 -> F_15 ( V_3 , V_70 ) ;
return V_60 ;
}
int F_55 ( struct V_1 * V_3 , T_1 V_70 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return V_60 ;
if ( V_3 -> V_20 < ( V_70 + 1 ) )
return V_60 ;
if ( V_22 && V_22 -> F_55 )
V_60 = V_22 -> F_55 ( V_3 , V_70 ) ;
return V_60 ;
}
int F_23 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return V_60 ;
F_12 ( L_12 ,
V_3 -> V_2 ) ;
if ( V_22 && V_22 -> F_23 )
V_60 = V_22 -> F_23 ( V_3 ) ;
return V_60 ;
}
int F_56 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return V_60 ;
if ( ! ( V_3 -> V_46 & V_73 ) )
return V_60 ;
F_12 ( L_13 , V_3 -> V_2 ) ;
if ( V_22 && V_22 -> F_56 )
V_60 = V_22 -> F_56 ( V_3 ) ;
return V_60 ;
}
int F_57 ( struct V_1 * V_3 )
{
int V_60 = - V_8 ;
if ( ! V_3 )
return V_60 ;
if ( ! ( V_3 -> V_46 & V_73 ) )
return V_60 ;
F_12 ( L_14 , V_3 -> V_2 ) ;
if ( V_22 && V_22 -> F_57 )
V_60 = V_22 -> F_57 ( V_3 ) ;
return V_60 ;
}
bool F_58 ( struct V_1 * V_3 )
{
return ( V_3 && V_3 -> V_46 & V_73 ) ? 1 : 0 ;
}
int F_31 ( struct V_1 * V_3 )
{
int V_60 ;
if ( ! V_3 || ! V_22 )
return - V_8 ;
V_60 = V_22 -> V_23 ( V_3 ) ;
if ( ! V_60 )
V_60 = F_16 ( V_3 , V_35 ) ;
return V_60 ;
}
int T_2 F_59 ( struct V_1 * V_3 )
{
int V_60 ;
F_37 ( V_3 ) ;
V_60 = F_31 ( V_3 ) ;
F_38 ( V_3 ) ;
return V_60 ;
}
int F_60 ( struct V_1 * V_3 )
{
if ( V_3 )
F_22 ( V_3 , NULL ) ;
else
F_40 ( F_22 , NULL ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_3 )
{
if ( V_3 )
F_24 ( V_3 , NULL ) ;
else
F_40 ( F_24 , NULL ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_3 , T_1 V_42 )
{
T_1 V_74 , V_44 ;
int V_41 ;
int V_60 = 0 ;
bool V_43 = false ;
if ( ! V_3 || F_63 ( V_3 ) )
return - V_8 ;
while ( ! ( V_3 -> V_68 & ( 1 << V_42 ) ) ) {
if ( V_42 == V_29 )
return V_60 ;
V_42 -- ;
}
F_37 ( V_3 ) ;
V_41 = F_11 ( V_3 ) ;
if ( V_41 < 0 ) {
V_60 = - V_8 ;
goto V_75;
}
V_74 = F_18 ( V_3 ) ;
if ( V_41 == V_42 && V_74 == V_42 )
goto V_75;
V_44 = F_25 ( V_3 , V_41 ,
V_42 , & V_43 ) ;
V_60 = F_36 ( V_3 , V_42 ) ;
if ( V_60 )
F_5 ( L_15 ,
V_76 , V_3 -> V_2 ) ;
F_28 ( V_3 , V_44 , V_43 ) ;
V_75:
F_38 ( V_3 ) ;
return V_60 ;
}
int F_64 ( struct V_1 * V_3 )
{
int V_5 , V_77 ;
if ( ! V_3 ) {
F_65 ( 1 , L_16 , V_76 ) ;
return - V_78 ;
}
V_77 = V_3 -> V_18 [ V_29 ] ;
V_77 += V_3 -> V_19 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_20 ; V_5 ++ )
V_77 += V_3 -> V_21 [ V_5 ] ;
V_77 &= V_79 ;
F_12 ( L_17 ,
V_3 -> V_2 , V_77 ) ;
return V_77 ;
}
bool F_66 ( struct V_1 * V_3 )
{
int V_5 ;
if ( ! V_3 ) {
F_12 ( L_18 ,
V_76 ) ;
return 1 ;
}
if ( V_3 -> V_68 & V_80 )
return 1 ;
if ( V_3 -> V_68 & V_81 ) {
if ( V_3 -> V_27 & V_80 )
return 1 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_20 ; V_5 ++ )
if ( V_3 -> V_30 [ V_5 ] & V_80 )
return 1 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_20 ; V_5 ++ )
if ( V_3 -> V_71 [ V_5 ] & V_80 )
return 1 ;
return 0 ;
}
