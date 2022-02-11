static void F_1 ( void )
{
F_2 () ;
F_3 ( F_4 ( V_1 ) ,
V_2 + 0x2a0 ) ;
F_5 () ;
F_6 () ;
F_7 () ;
F_8 () ;
}
static void F_9 ( void )
{
F_10 () ;
F_11 () ;
F_12 () ;
F_13 () ;
}
static void F_14 ( void )
{
T_1 V_3 ;
int V_4 = F_15 ( V_5 ) ;
if ( F_16 () != V_6 ) {
F_17 ( V_5 , V_7 ) ;
V_3 = F_18 ( ( T_1 * ) ( unsigned long )
F_19 ( V_8 ) ) ;
F_17 ( V_5 , V_4 ) ;
if ( V_3 ) {
F_20 ( L_1 , V_3 ) ;
while ( 1 )
;
}
}
}
static T_2 F_21 ( int V_9 , void * V_10 )
{
int V_11 ;
V_11 = F_22 ( V_12 , 1 ,
~ ( V_13 |
V_14 ) ) ;
return V_11 ? V_15 : V_16 ;
}
static T_2 F_23 ( int V_9 , void * V_10 )
{
int V_11 ;
V_11 = F_22 ( V_12 , 1 ,
V_13 |
V_14 ) ;
V_11 += F_22 ( V_17 , 1 , 0 ) ;
V_11 += F_22 ( V_18 , 1 , 0 ) ;
if ( F_24 () > V_19 ) {
V_11 += F_22 ( V_17 , 3 , 0 ) ;
V_11 += F_22 ( V_20 , 1 , 0 ) ;
}
return V_11 ? V_15 : V_16 ;
}
static void F_25 ( T_1 * V_21 )
{
T_1 V_22 ;
asm("mrc p15, 0, %0, c1, c0, 1" : "=r" (val));
* V_21 ++ = 1 ;
* V_21 ++ = V_22 ;
asm("mrc p15, 1, %0, c9, c0, 2" : "=r" (val));
* V_21 ++ = 1 ;
* V_21 ++ = V_22 ;
}
static int F_26 ( unsigned long V_23 )
{
F_27 ( V_23 ) ;
return 0 ;
}
void F_28 ( void )
{
int V_23 = 0 ;
int V_4 = V_7 ;
int V_24 = V_7 ;
int V_25 = V_7 ;
int V_26 ;
int V_27 ;
T_1 V_28 = 0 ;
V_4 = F_15 ( V_5 ) ;
switch ( V_4 ) {
case V_7 :
case V_29 :
V_23 = 0 ;
break;
case V_30 :
V_23 = 3 ;
break;
default:
F_20 ( L_2 ) ;
return;
}
if ( F_29 ( V_31 ) == V_7 )
F_17 ( V_31 , V_4 ) ;
V_24 = F_15 ( V_32 ) ;
V_25 = F_15 ( V_33 ) ;
F_30 ( NULL ) ;
if ( V_24 < V_7 ) {
V_26 = ( V_24 == V_30 ) ? 1 : 0 ;
F_31 ( V_26 ) ;
}
if ( V_25 < V_7 ) {
if ( V_25 == V_30 ) {
F_1 () ;
F_32 () ;
}
}
F_33 ( V_25 ) ;
F_34 () ;
if ( F_35 () && F_24 () >= V_34 &&
( F_16 () == V_35 ||
F_16 () == V_36 ) &&
V_25 == V_30 )
V_28 = F_36 ( V_37 ) ;
if ( V_23 )
F_25 ( V_38 ) ;
if ( V_23 == 1 || V_23 == 3 )
F_37 ( V_23 , F_26 ) ;
else
F_26 ( V_23 ) ;
if ( F_35 () && F_24 () >= V_34 &&
( F_16 () == V_35 ||
F_16 () == V_36 ) &&
V_25 == V_30 )
F_38 ( V_28 , V_37 ) ;
if ( V_25 < V_7 ) {
V_27 = F_39 ( V_33 ) ;
if ( V_27 == V_30 ) {
F_9 () ;
F_40 () ;
F_41 () ;
F_42 () ;
}
}
F_43 () ;
F_44 ( NULL ) ;
if ( V_24 < V_7 )
F_45 () ;
}
static void F_46 ( void )
{
if ( F_47 () )
return;
F_48 ( 1 , F_49 () ) ;
F_28 () ;
F_48 ( V_39 , F_49 () ) ;
}
static int F_50 ( void )
{
struct V_40 * V_41 ;
int V_42 , V_3 = 0 ;
F_51 (pwrst, &pwrst_list, node)
V_41 -> V_43 = F_15 ( V_41 -> V_44 ) ;
F_51 (pwrst, &pwrst_list, node) {
if ( F_52 ( V_41 -> V_44 , V_41 -> V_45 ) )
goto V_46;
if ( F_53 ( V_41 -> V_44 ) )
goto V_46;
}
F_54 () ;
F_28 () ;
V_46:
F_51 (pwrst, &pwrst_list, node) {
V_42 = F_39 ( V_41 -> V_44 ) ;
if ( V_42 > V_41 -> V_45 ) {
F_55 ( L_3 ,
V_41 -> V_44 -> V_47 , V_41 -> V_45 ) ;
V_3 = - 1 ;
}
F_52 ( V_41 -> V_44 , V_41 -> V_43 ) ;
}
if ( V_3 )
F_20 ( L_4 ) ;
else
F_55 ( L_5 ) ;
return V_3 ;
}
static void T_3 F_56 ( void )
{
F_57 () ;
F_58 ( F_59 () , F_60 () ) ;
}
void F_61 ( int V_48 )
{
struct V_40 * V_41 ;
T_1 V_42 ;
if ( V_48 )
V_42 = V_30 ;
else
V_42 = V_29 ;
F_51 (pwrst, &pwrst_list, node) {
if ( F_62 ( V_49 ) &&
V_41 -> V_44 == V_33 &&
V_42 == V_30 ) {
V_41 -> V_45 = V_29 ;
F_63 ( L_6 ,
V_50 ) ;
} else {
V_41 -> V_45 = V_42 ;
}
F_52 ( V_41 -> V_44 , V_41 -> V_45 ) ;
}
}
int F_64 ( struct V_51 * V_44 )
{
struct V_40 * V_41 ;
F_51 (pwrst, &pwrst_list, node) {
if ( V_41 -> V_44 == V_44 )
return V_41 -> V_45 ;
}
return - V_52 ;
}
int F_65 ( struct V_51 * V_44 , int V_42 )
{
struct V_40 * V_41 ;
F_51 (pwrst, &pwrst_list, node) {
if ( V_41 -> V_44 == V_44 ) {
V_41 -> V_45 = V_42 ;
return 0 ;
}
}
return - V_52 ;
}
static int T_3 F_66 ( struct V_51 * V_44 , void * V_10 )
{
struct V_40 * V_41 ;
if ( ! V_44 -> V_53 )
return 0 ;
V_41 = F_67 ( sizeof( struct V_40 ) , V_54 ) ;
if ( ! V_41 )
return - V_55 ;
V_41 -> V_44 = V_44 ;
V_41 -> V_45 = V_29 ;
F_68 ( & V_41 -> V_56 , & V_57 ) ;
if ( F_69 ( V_44 ) )
F_70 ( V_44 ) ;
return F_52 ( V_41 -> V_44 , V_41 -> V_45 ) ;
}
void F_71 ( void )
{
V_58 = F_72 ( V_59 , V_60 ) ;
if ( F_16 () != V_6 )
F_18 = F_72 ( V_61 ,
V_62 ) ;
}
static void T_3 F_73 ( void )
{
if ( F_59 () ) {
V_63 |= V_64 ;
F_74 () ;
if ( F_24 () < V_65 )
V_63 |= ( V_49 |
V_66 ) ;
} else if ( F_75 () ) {
V_63 |= V_66 ;
}
}
int T_3 F_76 ( void )
{
struct V_40 * V_41 , * V_67 ;
struct V_68 * V_69 , * V_70 , * V_71 , * V_72 ;
int V_3 ;
if ( ! F_77 () )
F_63 ( L_7 ) ;
F_73 () ;
F_56 () ;
V_3 = F_78 ( F_79 ( L_8 ) ,
F_23 , V_73 , L_9 , NULL ) ;
if ( V_3 ) {
F_20 ( L_10 ) ;
goto V_74;
}
V_3 = F_78 ( F_79 ( L_11 ) ,
F_21 , V_75 | V_73 , L_12 ,
F_76 ) ;
F_80 ( F_79 ( L_11 ) ) ;
if ( V_3 ) {
F_20 ( L_13 ) ;
goto V_76;
}
V_3 = F_81 ( F_66 , NULL ) ;
if ( V_3 ) {
F_20 ( L_14 ) ;
goto V_77;
}
( void ) F_82 ( V_78 , NULL ) ;
V_5 = F_83 ( L_15 ) ;
if ( V_5 == NULL ) {
F_20 ( L_16 ) ;
V_3 = - V_52 ;
goto V_77;
}
V_31 = F_83 ( L_17 ) ;
V_32 = F_83 ( L_18 ) ;
V_33 = F_83 ( L_19 ) ;
V_69 = F_84 ( L_20 ) ;
V_70 = F_84 ( L_21 ) ;
V_71 = F_84 ( L_22 ) ;
V_72 = F_84 ( L_23 ) ;
F_85 ( F_50 ) ;
V_79 = F_46 ;
F_86 () ;
if ( F_62 ( V_64 ) )
F_87 () ;
if ( F_62 ( V_66 ) )
F_88 ( V_71 , V_72 ) ;
F_88 ( V_69 , V_70 ) ;
if ( F_16 () != V_6 ) {
V_8 =
F_67 ( 0x803F , V_80 ) ;
if ( ! V_8 )
F_20 ( L_24 ) ;
F_89 () ;
F_8 () ;
F_14 () ;
F_13 () ;
F_90 () ;
}
F_91 () ;
return V_3 ;
V_77:
F_92 (pwrst, tmp, &pwrst_list, node) {
F_93 ( & V_41 -> V_56 ) ;
F_94 ( V_41 ) ;
}
F_95 ( F_79 ( L_11 ) , F_76 ) ;
V_76:
F_95 ( F_79 ( L_8 ) , NULL ) ;
V_74:
return V_3 ;
}
