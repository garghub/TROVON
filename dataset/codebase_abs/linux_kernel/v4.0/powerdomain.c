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
if ( V_12 && V_12 -> V_13 )
if ( ! V_12 -> V_13 () )
goto V_14;
V_7 = F_6 ( V_3 -> V_7 . V_2 ) ;
if ( ! V_7 ) {
F_5 ( L_2 ,
V_3 -> V_2 , V_3 -> V_7 . V_2 ) ;
return - V_8 ;
}
V_3 -> V_7 . V_15 = V_7 ;
F_7 ( & V_3 -> V_16 ) ;
V_14:
F_8 ( & V_3 -> V_17 ) ;
F_9 ( & V_3 -> V_18 , & V_19 ) ;
for ( V_5 = 0 ; V_5 < V_20 ; V_5 ++ )
V_3 -> V_21 [ V_5 ] = 0 ;
V_3 -> V_22 = 0 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_23 ; V_5 ++ )
V_3 -> V_24 [ V_5 ] = 0 ;
if ( V_12 && V_12 -> V_25 )
V_12 -> V_25 ( V_3 ) ;
V_3 -> V_26 = F_10 ( V_3 ) ;
V_3 -> V_21 [ V_3 -> V_26 ] = 1 ;
F_11 ( L_3 , V_3 -> V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_3 )
{
int V_5 ;
T_1 V_27 , V_28 ;
V_27 = F_13 ( V_3 ) ;
if ( ( V_3 -> V_29 == V_30 ) &&
( V_27 == V_31 ) )
V_3 -> V_22 ++ ;
for ( V_5 = 0 ; V_5 < V_3 -> V_23 ; V_5 ++ ) {
V_28 = F_14 ( V_3 , V_5 ) ;
if ( ( V_3 -> V_32 [ V_5 ] == V_30 ) &&
( V_28 == V_31 ) )
V_3 -> V_24 [ V_5 ] ++ ;
}
}
static int F_15 ( struct V_1 * V_3 , int V_33 )
{
int V_34 , V_35 , V_26 , V_36 = 0 ;
if ( V_3 == NULL )
return - V_8 ;
V_26 = F_10 ( V_3 ) ;
switch ( V_33 ) {
case V_37 :
V_34 = V_3 -> V_26 ;
break;
case V_38 :
V_34 = F_16 ( V_3 ) ;
if ( V_3 -> V_26 != V_34 )
V_3 -> V_21 [ V_34 ] ++ ;
if ( V_34 == V_39 )
F_12 ( V_3 ) ;
V_35 = F_17 ( V_3 ) ;
if ( V_35 != V_34 ) {
V_36 = ( V_40 |
( ( V_35 & V_41 ) << 8 ) |
( ( V_34 & V_41 ) << 0 ) ) ;
F_18 ( V_3 -> V_2 , V_36 ,
F_19 () ) ;
}
break;
default:
return - V_8 ;
}
if ( V_26 != V_34 )
V_3 -> V_21 [ V_26 ] ++ ;
F_20 ( V_3 , V_34 ) ;
V_3 -> V_26 = V_26 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_3 , void * V_42 )
{
F_22 ( V_3 ) ;
F_15 ( V_3 , V_37 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_3 , void * V_42 )
{
F_15 ( V_3 , V_38 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_3 ,
T_1 V_43 , T_1 V_44 ,
bool * V_45 )
{
T_1 V_46 ;
if ( V_43 < V_47 ) {
if ( V_43 > V_44 &&
V_3 -> V_48 & V_49 &&
V_12 -> V_50 ) {
V_46 = V_51 ;
} else {
* V_45 = F_25 ( V_3 -> V_52 [ 0 ] ) ;
F_26 ( V_3 -> V_52 [ 0 ] ) ;
V_46 = V_53 ;
}
} else {
V_46 = V_54 ;
}
return V_46 ;
}
static void F_27 ( struct V_1 * V_3 ,
T_1 V_46 , bool V_45 )
{
switch ( V_46 ) {
case V_53 :
if ( V_45 )
F_28 ( V_3 -> V_52 [ 0 ] ) ;
else
F_29 ( V_3 -> V_52 [ 0 ] ) ;
break;
case V_51 :
if ( V_3 -> V_48 & V_49 &&
V_12 -> V_50 )
V_12 -> V_50 ( V_3 ) ;
F_30 ( V_3 ) ;
break;
}
}
int F_31 ( struct V_55 * V_56 )
{
if ( ! V_56 )
return - V_8 ;
if ( V_12 )
return - V_11 ;
V_12 = V_56 ;
return 0 ;
}
int F_32 ( struct V_1 * * V_57 )
{
struct V_1 * * V_58 = NULL ;
if ( ! V_12 )
return - V_11 ;
if ( ! V_57 )
return - V_8 ;
for ( V_58 = V_57 ; * V_58 ; V_58 ++ )
F_3 ( * V_58 ) ;
return 0 ;
}
int F_33 ( void )
{
struct V_1 * V_59 ;
if ( F_34 ( & V_19 ) )
return - V_60 ;
F_2 (temp_p, &pwrdm_list, node)
F_35 ( V_59 , V_47 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_3 )
__acquires( &pwrdm->_lock
void F_37 ( struct V_1 * V_3 )
__releases( &pwrdm->_lock
struct V_1 * F_38 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return NULL ;
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
int F_39 ( int (* F_40)( struct V_1 * V_3 , void * V_61 ) ,
void * V_61 )
{
struct V_1 * V_4 ;
int V_62 = 0 ;
if ( ! F_40 )
return - V_8 ;
F_2 (temp_pwrdm, &pwrdm_list, node) {
V_62 = (* F_40)( V_4 , V_61 ) ;
if ( V_62 )
break;
}
return V_62 ;
}
int F_41 ( struct V_1 * V_3 , struct V_63 * V_64 )
{
int V_5 ;
int V_62 = - V_8 ;
if ( ! V_3 || ! V_64 )
return - V_8 ;
F_11 ( L_4 ,
V_3 -> V_2 , V_64 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_65 ; V_5 ++ ) {
if ( ! V_3 -> V_52 [ V_5 ] )
break;
#ifdef F_42
if ( V_3 -> V_52 [ V_5 ] == V_64 ) {
V_62 = - V_8 ;
goto V_66;
}
#endif
}
if ( V_5 == V_65 ) {
F_11 ( L_5 ,
V_3 -> V_2 , V_64 -> V_2 ) ;
F_43 ( 1 ) ;
V_62 = - V_67 ;
goto V_66;
}
V_3 -> V_52 [ V_5 ] = V_64 ;
V_62 = 0 ;
V_66:
return V_62 ;
}
int F_44 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_8 ;
return V_3 -> V_23 ;
}
int F_35 ( struct V_1 * V_3 , T_1 V_44 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_68 & ( 1 << V_44 ) ) )
return - V_8 ;
F_11 ( L_6 ,
V_3 -> V_2 , V_44 ) ;
if ( V_12 && V_12 -> F_35 ) {
F_18 ( V_3 -> V_2 , V_44 ,
F_19 () ) ;
V_62 = V_12 -> F_35 ( V_3 , V_44 ) ;
}
return V_62 ;
}
int F_17 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_17 )
V_62 = V_12 -> F_17 ( V_3 ) ;
return V_62 ;
}
int F_10 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_68 == V_69 )
return V_47 ;
if ( V_12 && V_12 -> F_10 )
V_62 = V_12 -> F_10 ( V_3 ) ;
return V_62 ;
}
int F_16 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_16 )
V_62 = V_12 -> F_16 ( V_3 ) ;
return V_62 ;
}
int F_45 ( struct V_1 * V_3 , T_1 V_44 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_29 & ( 1 << V_44 ) ) )
return - V_8 ;
F_11 ( L_7 ,
V_3 -> V_2 , V_44 ) ;
if ( V_12 && V_12 -> F_45 )
V_62 = V_12 -> F_45 ( V_3 , V_44 ) ;
return V_62 ;
}
int F_46 ( struct V_1 * V_3 , T_1 V_70 , T_1 V_44 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_23 < ( V_70 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_71 [ V_70 ] & ( 1 << V_44 ) ) )
return - V_8 ;
F_11 ( L_8 ,
V_3 -> V_2 , V_70 , V_44 ) ;
if ( V_12 && V_12 -> F_46 )
V_62 = V_12 -> F_46 ( V_3 , V_70 , V_44 ) ;
return V_62 ;
}
int F_47 ( struct V_1 * V_3 , T_1 V_70 , T_1 V_44 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_23 < ( V_70 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_32 [ V_70 ] & ( 1 << V_44 ) ) )
return - V_8 ;
F_11 ( L_9 ,
V_3 -> V_2 , V_70 , V_44 ) ;
if ( V_12 && V_12 -> F_47 )
V_62 = V_12 -> F_47 ( V_3 , V_70 , V_44 ) ;
return V_62 ;
}
int F_48 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_48 )
V_62 = V_12 -> F_48 ( V_3 ) ;
return V_62 ;
}
int F_13 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_13 )
V_62 = V_12 -> F_13 ( V_3 ) ;
return V_62 ;
}
int F_49 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_49 )
V_62 = V_12 -> F_49 ( V_3 ) ;
return V_62 ;
}
int F_50 ( struct V_1 * V_3 , T_1 V_70 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return V_62 ;
if ( V_3 -> V_23 < ( V_70 + 1 ) )
return V_62 ;
if ( V_3 -> V_48 & V_72 )
V_70 = 1 ;
if ( V_12 && V_12 -> F_50 )
V_62 = V_12 -> F_50 ( V_3 , V_70 ) ;
return V_62 ;
}
int F_14 ( struct V_1 * V_3 , T_1 V_70 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return V_62 ;
if ( V_3 -> V_23 < ( V_70 + 1 ) )
return V_62 ;
if ( V_3 -> V_48 & V_72 )
V_70 = 1 ;
if ( V_12 && V_12 -> F_14 )
V_62 = V_12 -> F_14 ( V_3 , V_70 ) ;
return V_62 ;
}
int F_51 ( struct V_1 * V_3 , T_1 V_70 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return V_62 ;
if ( V_3 -> V_23 < ( V_70 + 1 ) )
return V_62 ;
if ( V_12 && V_12 -> F_51 )
V_62 = V_12 -> F_51 ( V_3 , V_70 ) ;
return V_62 ;
}
int F_22 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return V_62 ;
F_11 ( L_10 ,
V_3 -> V_2 ) ;
if ( V_12 && V_12 -> F_22 )
V_62 = V_12 -> F_22 ( V_3 ) ;
return V_62 ;
}
int F_52 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return V_62 ;
if ( ! ( V_3 -> V_48 & V_73 ) )
return V_62 ;
F_11 ( L_11 , V_3 -> V_2 ) ;
if ( V_12 && V_12 -> F_52 )
V_62 = V_12 -> F_52 ( V_3 ) ;
return V_62 ;
}
int F_53 ( struct V_1 * V_3 )
{
int V_62 = - V_8 ;
if ( ! V_3 )
return V_62 ;
if ( ! ( V_3 -> V_48 & V_73 ) )
return V_62 ;
F_11 ( L_12 , V_3 -> V_2 ) ;
if ( V_12 && V_12 -> F_53 )
V_62 = V_12 -> F_53 ( V_3 ) ;
return V_62 ;
}
bool F_54 ( struct V_1 * V_3 )
{
return ( V_3 && V_3 -> V_48 & V_73 ) ? 1 : 0 ;
}
int F_30 ( struct V_1 * V_3 )
{
int V_62 ;
if ( ! V_3 || ! V_12 )
return - V_8 ;
V_62 = V_12 -> V_25 ( V_3 ) ;
if ( ! V_62 )
V_62 = F_15 ( V_3 , V_37 ) ;
return V_62 ;
}
int T_2 F_55 ( struct V_1 * V_3 )
{
int V_62 ;
F_36 ( V_3 ) ;
V_62 = F_30 ( V_3 ) ;
F_37 ( V_3 ) ;
return V_62 ;
}
int F_56 ( struct V_1 * V_3 )
{
if ( V_3 )
F_21 ( V_3 , NULL ) ;
else
F_39 ( F_21 , NULL ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_3 )
{
if ( V_3 )
F_23 ( V_3 , NULL ) ;
else
F_39 ( F_23 , NULL ) ;
return 0 ;
}
T_1 F_58 ( struct V_1 * V_3 ,
bool V_74 , T_1 V_75 )
{
T_1 V_76 = V_74 ? V_3 -> V_29 :
V_3 -> V_68 ;
T_1 V_77 = V_74 ? V_39 : V_47 ;
T_1 V_78 ;
bool V_79 ;
if ( V_76 & F_59 ( V_75 ) )
return V_75 ;
if ( ! V_75 )
goto V_80;
V_78 = V_75 - 1 ;
V_79 = true ;
while ( ! ( V_76 & F_59 ( V_78 ) ) ) {
if ( V_78 == V_31 ) {
V_79 = false ;
break;
}
V_78 -- ;
}
if ( V_79 )
goto V_81;
V_80:
V_78 = V_75 + 1 ;
while ( ! ( V_76 & F_59 ( V_78 ) ) ) {
if ( V_78 > V_47 ) {
F_60 ( 1 , L_13 ,
V_3 -> V_2 ) ;
return V_47 ;
}
if ( V_78 == V_77 )
break;
V_78 ++ ;
}
V_81:
return V_78 ;
}
int F_61 ( struct V_1 * V_3 , T_1 V_44 )
{
T_1 V_82 , V_46 ;
int V_43 ;
int V_62 = 0 ;
bool V_45 = false ;
if ( ! V_3 || F_62 ( V_3 ) )
return - V_8 ;
while ( ! ( V_3 -> V_68 & ( 1 << V_44 ) ) ) {
if ( V_44 == V_31 )
return V_62 ;
V_44 -- ;
}
F_36 ( V_3 ) ;
V_43 = F_10 ( V_3 ) ;
if ( V_43 < 0 ) {
V_62 = - V_8 ;
goto V_83;
}
V_82 = F_17 ( V_3 ) ;
if ( V_43 == V_44 && V_82 == V_44 )
goto V_83;
V_46 = F_24 ( V_3 , V_43 ,
V_44 , & V_45 ) ;
V_62 = F_35 ( V_3 , V_44 ) ;
if ( V_62 )
F_5 ( L_14 ,
V_84 , V_3 -> V_2 ) ;
F_27 ( V_3 , V_46 , V_45 ) ;
V_83:
F_37 ( V_3 ) ;
return V_62 ;
}
int F_63 ( struct V_1 * V_3 )
{
int V_5 , V_85 ;
if ( ! V_3 ) {
F_60 ( 1 , L_15 , V_84 ) ;
return - V_86 ;
}
V_85 = V_3 -> V_21 [ V_31 ] ;
V_85 += V_3 -> V_22 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_23 ; V_5 ++ )
V_85 += V_3 -> V_24 [ V_5 ] ;
V_85 &= V_87 ;
F_11 ( L_16 ,
V_3 -> V_2 , V_85 ) ;
return V_85 ;
}
bool F_64 ( struct V_1 * V_3 )
{
int V_5 ;
if ( ! V_3 ) {
F_11 ( L_17 ,
V_84 ) ;
return 1 ;
}
if ( V_3 -> V_68 & V_88 )
return 1 ;
if ( V_3 -> V_68 & V_89 ) {
if ( V_3 -> V_29 & V_88 )
return 1 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_23 ; V_5 ++ )
if ( V_3 -> V_32 [ V_5 ] & V_88 )
return 1 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_23 ; V_5 ++ )
if ( V_3 -> V_71 [ V_5 ] & V_88 )
return 1 ;
return 0 ;
}
