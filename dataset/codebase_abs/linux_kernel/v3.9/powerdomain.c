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
if ( V_41 < 0 ) {
F_26 ( 1 ) ;
V_44 = V_45 ;
} else if ( V_41 < V_46 ) {
if ( V_41 > V_42 &&
V_3 -> V_47 & V_48 &&
V_22 -> V_49 ) {
V_44 = V_50 ;
} else {
* V_43 = F_27 ( V_3 -> V_51 [ 0 ] ) ;
F_28 ( V_3 -> V_51 [ 0 ] ) ;
V_44 = V_52 ;
}
} else {
V_44 = V_53 ;
}
return V_44 ;
}
static void F_29 ( struct V_1 * V_3 ,
T_1 V_44 , bool V_43 )
{
switch ( V_44 ) {
case V_52 :
if ( V_43 )
F_30 ( V_3 -> V_51 [ 0 ] ) ;
else
F_31 ( V_3 -> V_51 [ 0 ] ) ;
break;
case V_50 :
if ( V_3 -> V_47 & V_48 &&
V_22 -> V_49 )
V_22 -> V_49 ( V_3 ) ;
F_32 ( V_3 ) ;
break;
}
}
int F_33 ( struct V_54 * V_55 )
{
if ( ! V_55 )
return - V_8 ;
if ( V_22 )
return - V_11 ;
V_22 = V_55 ;
return 0 ;
}
int F_34 ( struct V_1 * * V_56 )
{
struct V_1 * * V_57 = NULL ;
if ( ! V_22 )
return - V_11 ;
if ( ! V_56 )
return - V_8 ;
for ( V_57 = V_56 ; * V_57 ; V_57 ++ )
F_3 ( * V_57 ) ;
return 0 ;
}
int F_35 ( void )
{
struct V_1 * V_58 ;
if ( F_36 ( & V_16 ) )
return - V_59 ;
F_2 (temp_p, &pwrdm_list, node)
F_37 ( V_58 , V_46 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_3 )
__acquires( &pwrdm->_lock
void F_39 ( struct V_1 * V_3 )
__releases( &pwrdm->_lock
struct V_1 * F_40 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return NULL ;
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
int F_41 ( int (* F_42)( struct V_1 * V_3 , void * V_60 ) ,
void * V_60 )
{
struct V_1 * V_4 ;
int V_61 = 0 ;
if ( ! F_42 )
return - V_8 ;
F_2 (temp_pwrdm, &pwrdm_list, node) {
V_61 = (* F_42)( V_4 , V_60 ) ;
if ( V_61 )
break;
}
return V_61 ;
}
int F_43 ( struct V_1 * V_3 , struct V_62 * V_63 )
{
int V_5 ;
int V_61 = - V_8 ;
if ( ! V_3 || ! V_63 )
return - V_8 ;
F_12 ( L_4 ,
V_3 -> V_2 , V_63 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_64 ; V_5 ++ ) {
if ( ! V_3 -> V_51 [ V_5 ] )
break;
#ifdef F_44
if ( V_3 -> V_51 [ V_5 ] == V_63 ) {
V_61 = - V_8 ;
goto V_65;
}
#endif
}
if ( V_5 == V_64 ) {
F_12 ( L_5 ,
V_3 -> V_2 , V_63 -> V_2 ) ;
F_26 ( 1 ) ;
V_61 = - V_66 ;
goto V_65;
}
V_3 -> V_51 [ V_5 ] = V_63 ;
V_61 = 0 ;
V_65:
return V_61 ;
}
int F_45 ( struct V_1 * V_3 , struct V_62 * V_63 )
{
int V_61 = - V_8 ;
int V_5 ;
if ( ! V_3 || ! V_63 )
return - V_8 ;
F_12 ( L_6 ,
V_3 -> V_2 , V_63 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_64 ; V_5 ++ )
if ( V_3 -> V_51 [ V_5 ] == V_63 )
break;
if ( V_5 == V_64 ) {
F_12 ( L_7 ,
V_3 -> V_2 , V_63 -> V_2 ) ;
V_61 = - V_67 ;
goto V_68;
}
V_3 -> V_51 [ V_5 ] = NULL ;
V_61 = 0 ;
V_68:
return V_61 ;
}
int F_46 ( struct V_1 * V_3 ,
int (* F_42)( struct V_1 * V_3 ,
struct V_62 * V_63 ) )
{
int V_61 = 0 ;
int V_5 ;
if ( ! F_42 )
return - V_8 ;
for ( V_5 = 0 ; V_5 < V_64 && ! V_61 ; V_5 ++ )
V_61 = (* F_42)( V_3 , V_3 -> V_51 [ V_5 ] ) ;
return V_61 ;
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
int F_37 ( struct V_1 * V_3 , T_1 V_42 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_69 & ( 1 << V_42 ) ) )
return - V_8 ;
F_12 ( L_8 ,
V_3 -> V_2 , V_42 ) ;
if ( V_22 && V_22 -> F_37 ) {
F_19 ( V_3 -> V_2 , V_42 ,
F_20 () ) ;
V_61 = V_22 -> F_37 ( V_3 , V_42 ) ;
}
return V_61 ;
}
int F_18 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_18 )
V_61 = V_22 -> F_18 ( V_3 ) ;
return V_61 ;
}
int F_11 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_69 == V_70 )
return V_46 ;
if ( V_22 && V_22 -> F_11 )
V_61 = V_22 -> F_11 ( V_3 ) ;
return V_61 ;
}
int F_17 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_17 )
V_61 = V_22 -> F_17 ( V_3 ) ;
return V_61 ;
}
int F_49 ( struct V_1 * V_3 , T_1 V_42 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_27 & ( 1 << V_42 ) ) )
return - V_8 ;
F_12 ( L_9 ,
V_3 -> V_2 , V_42 ) ;
if ( V_22 && V_22 -> F_49 )
V_61 = V_22 -> F_49 ( V_3 , V_42 ) ;
return V_61 ;
}
int F_50 ( struct V_1 * V_3 , T_1 V_71 , T_1 V_42 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_20 < ( V_71 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_72 [ V_71 ] & ( 1 << V_42 ) ) )
return - V_8 ;
F_12 ( L_10 ,
V_3 -> V_2 , V_71 , V_42 ) ;
if ( V_22 && V_22 -> F_50 )
V_61 = V_22 -> F_50 ( V_3 , V_71 , V_42 ) ;
return V_61 ;
}
int F_51 ( struct V_1 * V_3 , T_1 V_71 , T_1 V_42 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_20 < ( V_71 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_30 [ V_71 ] & ( 1 << V_42 ) ) )
return - V_8 ;
F_12 ( L_11 ,
V_3 -> V_2 , V_71 , V_42 ) ;
if ( V_22 && V_22 -> F_51 )
V_61 = V_22 -> F_51 ( V_3 , V_71 , V_42 ) ;
return V_61 ;
}
int F_52 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_52 )
V_61 = V_22 -> F_52 ( V_3 ) ;
return V_61 ;
}
int F_14 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_14 )
V_61 = V_22 -> F_14 ( V_3 ) ;
return V_61 ;
}
int F_53 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_22 && V_22 -> F_53 )
V_61 = V_22 -> F_53 ( V_3 ) ;
return V_61 ;
}
int F_54 ( struct V_1 * V_3 , T_1 V_71 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( V_3 -> V_20 < ( V_71 + 1 ) )
return V_61 ;
if ( V_3 -> V_47 & V_73 )
V_71 = 1 ;
if ( V_22 && V_22 -> F_54 )
V_61 = V_22 -> F_54 ( V_3 , V_71 ) ;
return V_61 ;
}
int F_15 ( struct V_1 * V_3 , T_1 V_71 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( V_3 -> V_20 < ( V_71 + 1 ) )
return V_61 ;
if ( V_3 -> V_47 & V_73 )
V_71 = 1 ;
if ( V_22 && V_22 -> F_15 )
V_61 = V_22 -> F_15 ( V_3 , V_71 ) ;
return V_61 ;
}
int F_55 ( struct V_1 * V_3 , T_1 V_71 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( V_3 -> V_20 < ( V_71 + 1 ) )
return V_61 ;
if ( V_22 && V_22 -> F_55 )
V_61 = V_22 -> F_55 ( V_3 , V_71 ) ;
return V_61 ;
}
int F_23 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
F_12 ( L_12 ,
V_3 -> V_2 ) ;
if ( V_22 && V_22 -> F_23 )
V_61 = V_22 -> F_23 ( V_3 ) ;
return V_61 ;
}
int F_56 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( ! ( V_3 -> V_47 & V_74 ) )
return V_61 ;
F_12 ( L_13 , V_3 -> V_2 ) ;
if ( V_22 && V_22 -> F_56 )
V_61 = V_22 -> F_56 ( V_3 ) ;
return V_61 ;
}
int F_57 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( ! ( V_3 -> V_47 & V_74 ) )
return V_61 ;
F_12 ( L_14 , V_3 -> V_2 ) ;
if ( V_22 && V_22 -> F_57 )
V_61 = V_22 -> F_57 ( V_3 ) ;
return V_61 ;
}
bool F_58 ( struct V_1 * V_3 )
{
return ( V_3 && V_3 -> V_47 & V_74 ) ? 1 : 0 ;
}
int F_32 ( struct V_1 * V_3 )
{
int V_61 ;
if ( ! V_3 || ! V_22 )
return - V_8 ;
V_61 = V_22 -> V_23 ( V_3 ) ;
if ( ! V_61 )
V_61 = F_16 ( V_3 , V_35 ) ;
return V_61 ;
}
int T_2 F_59 ( struct V_1 * V_3 )
{
int V_61 ;
F_38 ( V_3 ) ;
V_61 = F_32 ( V_3 ) ;
F_39 ( V_3 ) ;
return V_61 ;
}
int F_60 ( struct V_1 * V_3 )
{
if ( V_3 )
F_22 ( V_3 , NULL ) ;
else
F_41 ( F_22 , NULL ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_3 )
{
if ( V_3 )
F_24 ( V_3 , NULL ) ;
else
F_41 ( F_24 , NULL ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_3 , T_1 V_42 )
{
T_1 V_41 , V_75 , V_44 ;
int V_61 = 0 ;
bool V_43 = false ;
if ( ! V_3 || F_63 ( V_3 ) )
return - V_8 ;
while ( ! ( V_3 -> V_69 & ( 1 << V_42 ) ) ) {
if ( V_42 == V_29 )
return V_61 ;
V_42 -- ;
}
F_38 ( V_3 ) ;
V_41 = F_11 ( V_3 ) ;
V_75 = F_18 ( V_3 ) ;
if ( V_41 == V_42 && V_75 == V_42 )
goto V_76;
V_44 = F_25 ( V_3 , V_41 ,
V_42 , & V_43 ) ;
if ( V_44 == V_45 ) {
V_61 = - V_8 ;
goto V_76;
}
V_61 = F_37 ( V_3 , V_42 ) ;
if ( V_61 )
F_5 ( L_15 ,
V_77 , V_3 -> V_2 ) ;
F_29 ( V_3 , V_44 , V_43 ) ;
V_76:
F_39 ( V_3 ) ;
return V_61 ;
}
int F_64 ( struct V_1 * V_3 )
{
int V_5 , V_78 ;
if ( ! V_3 ) {
F_65 ( 1 , L_16 , V_77 ) ;
return - V_79 ;
}
V_78 = V_3 -> V_18 [ V_29 ] ;
V_78 += V_3 -> V_19 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_20 ; V_5 ++ )
V_78 += V_3 -> V_21 [ V_5 ] ;
V_78 &= V_80 ;
F_12 ( L_17 ,
V_3 -> V_2 , V_78 ) ;
return V_78 ;
}
bool F_66 ( struct V_1 * V_3 )
{
int V_5 ;
if ( F_67 ( V_3 ) ) {
F_12 ( L_18 ,
V_77 ) ;
return 1 ;
}
if ( V_3 -> V_69 & V_81 )
return 1 ;
if ( V_3 -> V_69 & V_82 ) {
if ( V_3 -> V_27 & V_81 )
return 1 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_20 ; V_5 ++ )
if ( V_3 -> V_30 [ V_5 ] & V_81 )
return 1 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_20 ; V_5 ++ )
if ( V_3 -> V_72 [ V_5 ] & V_81 )
return 1 ;
return 0 ;
}
