static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
unsigned long V_6 = 1 ;
struct V_7 * V_8 = & V_4 -> V_9 [ V_5 ] ;
unsigned long V_10 = F_2 ( V_8 -> V_11 ) ;
unsigned int V_12 ;
int V_13 = F_3 () ;
V_12 = ( ( ( V_10 ) >> V_14 ) & V_15 ) + 1 ;
if ( V_8 -> V_11 & V_16 )
F_4 ( V_13 ) ;
if ( ! ( V_17 & ( 1 << ( V_12 ) ) ) )
F_5 ( V_18 , & V_13 ) ;
F_6 ( V_10 , V_6 ) ;
if ( ! ( V_17 & ( 1 << ( V_12 ) ) ) )
F_5 ( V_19 , & V_13 ) ;
return V_5 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
unsigned long V_6 = 1 ;
unsigned long V_10 = F_2 ( V_4 -> V_9 [ V_5 ] . V_11 ) ;
F_6 ( V_10 , V_6 ) ;
}
static void F_8 ( void * V_20 )
{
unsigned long V_21 = ( unsigned long ) V_20 ;
int V_13 = F_3 () ;
V_21 = V_21 ?
V_22 : V_23 ;
F_5 ( V_21 , & V_13 ) ;
}
static int F_9 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
int V_28 = ( unsigned long ) V_27 ;
struct V_1 * V_2 ;
switch ( V_26 & ~ V_29 ) {
case V_30 :
if ( V_17 != V_31 )
F_10 ( V_28 , F_8 ,
( void * ) true , 1 ) ;
V_2 = F_11 ( V_32 , V_28 ) ;
if ( ! V_2 -> V_33 )
F_12 ( V_28 ) ;
break;
}
return V_34 ;
}
static void F_13 ( void * V_35 )
{
unsigned long long V_36 ;
F_14 ( V_37 , V_36 ) ;
V_36 &= ~ ( V_38 -> V_39 ) ;
F_15 ( V_37 , V_36 ) ;
}
static void F_16 ( void * V_35 )
{
unsigned long long V_36 ;
F_14 ( V_40 , V_36 ) ;
V_36 &= ~ 0x2 ;
F_15 ( V_40 , V_36 ) ;
}
static int T_1 F_17 ( void )
{
unsigned int V_10 , V_41 , V_6 ;
const struct V_42 * V_43 ;
if ( V_44 == 0 ) {
F_18 ( V_45 L_1 ) ;
return - V_46 ;
}
V_43 = F_19 ( V_47 ) ;
if ( ! V_43 ) {
if ( V_48 . V_49 == V_50 &&
V_48 . V_51 == 6 )
F_18 ( V_45 L_2 ,
V_48 . V_51 , V_48 . V_52 ) ;
return - V_53 ;
}
if ( V_48 . V_54 < V_55 )
return - V_53 ;
F_20 ( V_55 , & V_10 , & V_41 , & V_6 , & V_56 ) ;
if ( ! ( V_6 & V_57 ) ||
! ( V_6 & V_58 ) ||
! V_56 )
return - V_53 ;
F_18 ( V_45 L_3 , V_56 ) ;
V_38 = ( const struct V_59 * ) V_43 -> V_60 ;
V_61 = V_38 -> V_62 ;
if ( F_21 ( V_63 ) )
V_17 = V_31 ;
else
F_22 ( F_8 , ( void * ) true , 1 ) ;
F_18 ( V_45 L_4 V_64
L_5 , V_48 . V_52 ) ;
F_18 ( V_45 L_6 ,
V_17 ) ;
return 0 ;
}
static void F_23 ( void )
{
int V_65 ;
struct V_1 * V_2 ;
F_24 (i) {
V_2 = F_11 ( V_32 , V_65 ) ;
F_25 ( V_2 ) ;
}
F_26 ( V_32 ) ;
return;
}
void F_27 ( void )
{
if ( V_48 . V_52 == 0x3e ) {
int V_13 , V_66 , V_67 = 1 ;
F_24 (cpu) {
V_66 = F_28 ( V_13 ) ;
if ( V_66 + 1 > V_67 ) {
V_67 = V_66 + 1 ;
if ( V_67 > 4 ) {
V_61 = V_68 ;
return;
}
}
}
if ( V_67 > 2 )
V_61 = V_69 ;
}
return;
}
static int T_1 F_29 ( void )
{
int V_12 ;
struct V_3 * V_4 = & V_70 ;
F_27 () ;
V_4 -> V_71 = 1 ;
for ( V_12 = 0 ; V_12 < V_72 ; ++ V_12 ) {
int V_73 , V_74 , V_75 ;
if ( V_61 [ V_12 ] . V_76 == NULL )
break;
if ( V_12 + 1 > V_44 ) {
F_30 ( V_45 L_7 ,
V_44 ) ;
break;
}
V_74 = F_2 ( V_61 [ V_12 ] . V_11 ) ;
V_75 = F_31 ( V_74 ) ;
V_73 = ( V_56 >> ( ( V_75 + 1 ) * 4 ) )
& V_77 ;
if ( V_73 == 0 )
continue;
if ( ( ( V_75 + 1 ) > 2 ) &&
! F_21 ( V_78 ) )
F_32 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_71 ] =
V_61 [ V_12 ] ;
V_4 -> V_71 += 1 ;
}
if ( V_38 -> V_39 )
F_22 ( F_13 , NULL , 1 ) ;
if ( V_38 -> V_79 ) {
F_15 ( V_80 , 0 ) ;
F_15 ( V_81 , 0 ) ;
}
if ( V_38 -> V_82 )
F_22 ( F_16 , NULL , 1 ) ;
return 0 ;
}
static int F_12 ( int V_13 )
{
struct V_1 * V_2 ;
V_2 = F_11 ( V_32 , V_13 ) ;
V_2 -> V_13 = V_13 ;
if ( F_33 ( V_2 ) ) {
F_18 ( V_45 L_10 , V_13 ) ;
F_23 () ;
return - V_83 ;
}
if ( V_38 -> V_39 )
F_10 ( V_13 , F_13 , NULL , 1 ) ;
if ( V_38 -> V_82 )
F_10 ( V_13 , F_16 , NULL , 1 ) ;
return 0 ;
}
static int T_1 F_34 ( void )
{
int V_84 , V_65 ;
if ( V_85 != V_86 )
return - V_53 ;
V_84 = F_17 () ;
if ( V_84 )
return V_84 ;
F_29 () ;
V_84 = F_35 ( & V_70 ) ;
if ( V_84 ) {
struct V_3 * V_4 = F_36 () ;
F_30 (KERN_DEBUG PREFIX L_11 ,
drv ? drv->name : L_12 ) ;
return V_84 ;
}
V_32 = F_37 ( struct V_1 ) ;
if ( V_32 == NULL )
return - V_87 ;
F_38 () ;
F_24 (i) {
V_84 = F_12 ( V_65 ) ;
if ( V_84 ) {
F_39 () ;
F_40 ( & V_70 ) ;
return V_84 ;
}
}
F_41 ( & V_88 ) ;
F_39 () ;
return 0 ;
}
static void T_2 F_42 ( void )
{
F_23 () ;
F_40 ( & V_70 ) ;
F_38 () ;
if ( V_17 != V_31 )
F_22 ( F_8 , ( void * ) false , 1 ) ;
F_43 ( & V_88 ) ;
F_39 () ;
return;
}
