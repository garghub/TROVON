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
F_18 ( V_3 -> V_2 ,
V_36 ,
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
T_1 V_43 , T_1 V_44 )
{
T_1 V_45 ;
if ( V_43 < V_46 ) {
if ( V_43 > V_44 &&
V_3 -> V_47 & V_48 &&
V_12 -> V_49 ) {
V_45 = V_50 ;
} else {
F_25 ( V_3 -> V_51 [ 0 ] ) ;
V_45 = V_52 ;
}
} else {
V_45 = V_53 ;
}
return V_45 ;
}
static void F_26 ( struct V_1 * V_3 ,
T_1 V_45 )
{
switch ( V_45 ) {
case V_52 :
F_27 ( V_3 -> V_51 [ 0 ] ) ;
break;
case V_50 :
if ( V_3 -> V_47 & V_48 &&
V_12 -> V_49 )
V_12 -> V_49 ( V_3 ) ;
F_28 ( V_3 ) ;
break;
}
}
int F_29 ( struct V_54 * V_55 )
{
if ( ! V_55 )
return - V_8 ;
if ( V_12 )
return - V_11 ;
V_12 = V_55 ;
return 0 ;
}
int F_30 ( struct V_1 * * V_56 )
{
struct V_1 * * V_57 = NULL ;
if ( ! V_12 )
return - V_11 ;
if ( ! V_56 )
return - V_8 ;
for ( V_57 = V_56 ; * V_57 ; V_57 ++ )
F_3 ( * V_57 ) ;
return 0 ;
}
int F_31 ( void )
{
struct V_1 * V_58 ;
if ( F_32 ( & V_19 ) )
return - V_59 ;
F_2 (temp_p, &pwrdm_list, node)
F_33 ( V_58 , V_46 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_3 )
__acquires( &pwrdm->_lock
void F_35 ( struct V_1 * V_3 )
__releases( &pwrdm->_lock
struct V_1 * F_36 ( const char * V_2 )
{
struct V_1 * V_3 ;
if ( ! V_2 )
return NULL ;
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
int F_37 ( int (* F_38)( struct V_1 * V_3 , void * V_60 ) ,
void * V_60 )
{
struct V_1 * V_4 ;
int V_61 = 0 ;
if ( ! F_38 )
return - V_8 ;
F_2 (temp_pwrdm, &pwrdm_list, node) {
V_61 = (* F_38)( V_4 , V_60 ) ;
if ( V_61 )
break;
}
return V_61 ;
}
int F_39 ( struct V_1 * V_3 , struct V_62 * V_63 )
{
int V_5 ;
int V_61 = - V_8 ;
if ( ! V_3 || ! V_63 )
return - V_8 ;
F_11 ( L_4 ,
V_3 -> V_2 , V_63 -> V_2 ) ;
for ( V_5 = 0 ; V_5 < V_64 ; V_5 ++ ) {
if ( ! V_3 -> V_51 [ V_5 ] )
break;
#ifdef F_40
if ( V_3 -> V_51 [ V_5 ] == V_63 ) {
V_61 = - V_8 ;
goto V_65;
}
#endif
}
if ( V_5 == V_64 ) {
F_11 ( L_5 ,
V_3 -> V_2 , V_63 -> V_2 ) ;
F_41 ( 1 ) ;
V_61 = - V_66 ;
goto V_65;
}
V_3 -> V_51 [ V_5 ] = V_63 ;
V_61 = 0 ;
V_65:
return V_61 ;
}
int F_42 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return - V_8 ;
return V_3 -> V_23 ;
}
int F_33 ( struct V_1 * V_3 , T_1 V_44 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_67 & ( 1 << V_44 ) ) )
return - V_8 ;
F_11 ( L_6 ,
V_3 -> V_2 , V_44 ) ;
if ( V_12 && V_12 -> F_33 ) {
F_18 ( V_3 -> V_2 , V_44 ,
F_19 () ) ;
V_61 = V_12 -> F_33 ( V_3 , V_44 ) ;
}
return V_61 ;
}
int F_17 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_17 )
V_61 = V_12 -> F_17 ( V_3 ) ;
return V_61 ;
}
int F_10 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_67 == V_68 )
return V_46 ;
if ( V_12 && V_12 -> F_10 )
V_61 = V_12 -> F_10 ( V_3 ) ;
return V_61 ;
}
int F_16 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_16 )
V_61 = V_12 -> F_16 ( V_3 ) ;
return V_61 ;
}
int F_43 ( struct V_1 * V_3 , T_1 V_44 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( ! ( V_3 -> V_29 & ( 1 << V_44 ) ) )
return - V_8 ;
F_11 ( L_7 ,
V_3 -> V_2 , V_44 ) ;
if ( V_12 && V_12 -> F_43 )
V_61 = V_12 -> F_43 ( V_3 , V_44 ) ;
return V_61 ;
}
int F_44 ( struct V_1 * V_3 , T_1 V_69 , T_1 V_44 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_23 < ( V_69 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_70 [ V_69 ] & ( 1 << V_44 ) ) )
return - V_8 ;
F_11 ( L_8 ,
V_3 -> V_2 , V_69 , V_44 ) ;
if ( V_12 && V_12 -> F_44 )
V_61 = V_12 -> F_44 ( V_3 , V_69 , V_44 ) ;
return V_61 ;
}
int F_45 ( struct V_1 * V_3 , T_1 V_69 , T_1 V_44 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_3 -> V_23 < ( V_69 + 1 ) )
return - V_11 ;
if ( ! ( V_3 -> V_32 [ V_69 ] & ( 1 << V_44 ) ) )
return - V_8 ;
F_11 ( L_9 ,
V_3 -> V_2 , V_69 , V_44 ) ;
if ( V_12 && V_12 -> F_45 )
V_61 = V_12 -> F_45 ( V_3 , V_69 , V_44 ) ;
return V_61 ;
}
int F_46 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_46 )
V_61 = V_12 -> F_46 ( V_3 ) ;
return V_61 ;
}
int F_13 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_13 )
V_61 = V_12 -> F_13 ( V_3 ) ;
return V_61 ;
}
int F_47 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return - V_8 ;
if ( V_12 && V_12 -> F_47 )
V_61 = V_12 -> F_47 ( V_3 ) ;
return V_61 ;
}
int F_48 ( struct V_1 * V_3 , T_1 V_69 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( V_3 -> V_23 < ( V_69 + 1 ) )
return V_61 ;
if ( V_3 -> V_47 & V_71 )
V_69 = 1 ;
if ( V_12 && V_12 -> F_48 )
V_61 = V_12 -> F_48 ( V_3 , V_69 ) ;
return V_61 ;
}
int F_14 ( struct V_1 * V_3 , T_1 V_69 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( V_3 -> V_23 < ( V_69 + 1 ) )
return V_61 ;
if ( V_3 -> V_47 & V_71 )
V_69 = 1 ;
if ( V_12 && V_12 -> F_14 )
V_61 = V_12 -> F_14 ( V_3 , V_69 ) ;
return V_61 ;
}
int F_49 ( struct V_1 * V_3 , T_1 V_69 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( V_3 -> V_23 < ( V_69 + 1 ) )
return V_61 ;
if ( V_12 && V_12 -> F_49 )
V_61 = V_12 -> F_49 ( V_3 , V_69 ) ;
return V_61 ;
}
int F_22 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
F_11 ( L_10 ,
V_3 -> V_2 ) ;
if ( V_12 && V_12 -> F_22 )
V_61 = V_12 -> F_22 ( V_3 ) ;
return V_61 ;
}
int F_50 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( ! ( V_3 -> V_47 & V_72 ) )
return V_61 ;
F_11 ( L_11 , V_3 -> V_2 ) ;
if ( V_12 && V_12 -> F_50 )
V_61 = V_12 -> F_50 ( V_3 ) ;
return V_61 ;
}
int F_51 ( struct V_1 * V_3 )
{
int V_61 = - V_8 ;
if ( ! V_3 )
return V_61 ;
if ( ! ( V_3 -> V_47 & V_72 ) )
return V_61 ;
F_11 ( L_12 , V_3 -> V_2 ) ;
if ( V_12 && V_12 -> F_51 )
V_61 = V_12 -> F_51 ( V_3 ) ;
return V_61 ;
}
bool F_52 ( struct V_1 * V_3 )
{
return ( V_3 && V_3 -> V_47 & V_72 ) ? 1 : 0 ;
}
int F_28 ( struct V_1 * V_3 )
{
int V_61 ;
if ( ! V_3 || ! V_12 )
return - V_8 ;
V_61 = V_12 -> V_25 ( V_3 ) ;
if ( ! V_61 )
V_61 = F_15 ( V_3 , V_37 ) ;
return V_61 ;
}
int T_2 F_53 ( struct V_1 * V_3 )
{
int V_61 ;
F_34 ( V_3 ) ;
V_61 = F_28 ( V_3 ) ;
F_35 ( V_3 ) ;
return V_61 ;
}
int F_54 ( struct V_1 * V_3 )
{
if ( V_3 )
F_21 ( V_3 , NULL ) ;
else
F_37 ( F_21 , NULL ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_3 )
{
if ( V_3 )
F_23 ( V_3 , NULL ) ;
else
F_37 ( F_23 , NULL ) ;
return 0 ;
}
T_1 F_56 ( struct V_1 * V_3 ,
bool V_73 , T_1 V_74 )
{
T_1 V_75 = V_73 ? V_3 -> V_29 :
V_3 -> V_67 ;
T_1 V_76 = V_73 ? V_39 : V_46 ;
T_1 V_77 ;
bool V_78 ;
if ( V_75 & F_57 ( V_74 ) )
return V_74 ;
if ( ! V_74 )
goto V_79;
V_77 = V_74 - 1 ;
V_78 = true ;
while ( ! ( V_75 & F_57 ( V_77 ) ) ) {
if ( V_77 == V_31 ) {
V_78 = false ;
break;
}
V_77 -- ;
}
if ( V_78 )
goto V_80;
V_79:
V_77 = V_74 + 1 ;
while ( ! ( V_75 & F_57 ( V_77 ) ) ) {
if ( V_77 > V_46 ) {
F_58 ( 1 , L_13 ,
V_3 -> V_2 ) ;
return V_46 ;
}
if ( V_77 == V_76 )
break;
V_77 ++ ;
}
V_80:
return V_77 ;
}
int F_59 ( struct V_1 * V_3 , T_1 V_44 )
{
T_1 V_81 , V_45 ;
int V_43 ;
int V_61 = 0 ;
if ( ! V_3 || F_60 ( V_3 ) )
return - V_8 ;
while ( ! ( V_3 -> V_67 & ( 1 << V_44 ) ) ) {
if ( V_44 == V_31 )
return V_61 ;
V_44 -- ;
}
F_34 ( V_3 ) ;
V_43 = F_10 ( V_3 ) ;
if ( V_43 < 0 ) {
V_61 = - V_8 ;
goto V_82;
}
V_81 = F_17 ( V_3 ) ;
if ( V_43 == V_44 && V_81 == V_44 )
goto V_82;
V_45 = F_24 ( V_3 , V_43 ,
V_44 ) ;
V_61 = F_33 ( V_3 , V_44 ) ;
if ( V_61 )
F_5 ( L_14 ,
V_83 , V_3 -> V_2 ) ;
F_26 ( V_3 , V_45 ) ;
V_82:
F_35 ( V_3 ) ;
return V_61 ;
}
int F_61 ( struct V_1 * V_3 )
{
int V_5 , V_84 ;
if ( ! V_3 ) {
F_58 ( 1 , L_15 , V_83 ) ;
return - V_85 ;
}
V_84 = V_3 -> V_21 [ V_31 ] ;
V_84 += V_3 -> V_22 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_23 ; V_5 ++ )
V_84 += V_3 -> V_24 [ V_5 ] ;
V_84 &= V_86 ;
F_11 ( L_16 ,
V_3 -> V_2 , V_84 ) ;
return V_84 ;
}
bool F_62 ( struct V_1 * V_3 )
{
int V_5 ;
if ( ! V_3 ) {
F_11 ( L_17 ,
V_83 ) ;
return 1 ;
}
if ( V_3 -> V_67 & V_87 )
return 1 ;
if ( V_3 -> V_67 & V_88 ) {
if ( V_3 -> V_29 & V_87 )
return 1 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_23 ; V_5 ++ )
if ( V_3 -> V_32 [ V_5 ] & V_87 )
return 1 ;
}
for ( V_5 = 0 ; V_5 < V_3 -> V_23 ; V_5 ++ )
if ( V_3 -> V_70 [ V_5 ] & V_87 )
return 1 ;
return 0 ;
}
