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
F_5 () ;
F_6 ( V_10 , V_6 ) ;
if ( ! ( V_17 & ( 1 << ( V_12 ) ) ) )
F_7 () ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
unsigned long V_6 = 1 ;
unsigned long V_10 = F_2 ( V_4 -> V_9 [ V_5 ] . V_11 ) ;
F_6 ( V_10 , V_6 ) ;
}
static void F_9 ( void * V_18 )
{
unsigned long V_19 = ( unsigned long ) V_18 ;
if ( V_19 )
F_10 () ;
else
F_11 () ;
}
static int F_12 ( struct V_20 * V_21 ,
unsigned long V_22 , void * V_23 )
{
int V_24 = ( unsigned long ) V_23 ;
struct V_1 * V_2 ;
switch ( V_22 & ~ V_25 ) {
case V_26 :
if ( V_17 != V_27 )
F_13 ( V_24 , F_9 ,
( void * ) true , 1 ) ;
V_2 = F_14 ( V_28 , V_24 ) ;
if ( ! V_2 -> V_29 )
F_15 ( V_24 ) ;
break;
}
return V_30 ;
}
static void F_16 ( void * V_31 )
{
unsigned long long V_32 ;
F_17 ( V_33 , V_32 ) ;
V_32 &= ~ ( V_34 -> V_35 ) ;
F_18 ( V_33 , V_32 ) ;
}
static void F_19 ( void * V_31 )
{
unsigned long long V_32 ;
F_17 ( V_36 , V_32 ) ;
V_32 &= ~ 0x2 ;
F_18 ( V_36 , V_32 ) ;
}
static int T_1 F_20 ( void )
{
unsigned int V_10 , V_37 , V_6 ;
const struct V_38 * V_39 ;
if ( V_40 == 0 ) {
F_21 ( V_41 L_1 ) ;
return - V_42 ;
}
V_39 = F_22 ( V_43 ) ;
if ( ! V_39 ) {
if ( V_44 . V_45 == V_46 &&
V_44 . V_47 == 6 )
F_21 ( V_41 L_2 ,
V_44 . V_47 , V_44 . V_48 ) ;
return - V_49 ;
}
if ( V_44 . V_50 < V_51 )
return - V_49 ;
F_23 ( V_51 , & V_10 , & V_37 , & V_6 , & V_52 ) ;
if ( ! ( V_6 & V_53 ) ||
! ( V_6 & V_54 ) ||
! V_52 )
return - V_49 ;
F_21 ( V_41 L_3 , V_52 ) ;
V_34 = ( const struct V_55 * ) V_39 -> V_56 ;
V_57 = V_34 -> V_58 ;
if ( F_24 ( V_59 ) )
V_17 = V_27 ;
else
F_25 ( F_9 , ( void * ) true , 1 ) ;
F_21 ( V_41 L_4 V_60
L_5 , V_44 . V_48 ) ;
F_21 ( V_41 L_6 ,
V_17 ) ;
return 0 ;
}
static void F_26 ( void )
{
int V_61 ;
struct V_1 * V_2 ;
F_27 (i) {
V_2 = F_14 ( V_28 , V_61 ) ;
F_28 ( V_2 ) ;
}
F_29 ( V_28 ) ;
return;
}
void F_30 ( void )
{
if ( V_44 . V_48 == 0x3e ) {
int V_13 , V_62 , V_63 = 1 ;
F_27 (cpu) {
V_62 = F_31 ( V_13 ) ;
if ( V_62 + 1 > V_63 ) {
V_63 = V_62 + 1 ;
if ( V_63 > 4 ) {
V_57 = V_64 ;
return;
}
}
}
if ( V_63 > 2 )
V_57 = V_65 ;
}
return;
}
static int T_1 F_32 ( void )
{
int V_12 ;
struct V_3 * V_4 = & V_66 ;
F_30 () ;
V_4 -> V_67 = 1 ;
for ( V_12 = 0 ; V_12 < V_68 ; ++ V_12 ) {
int V_69 , V_70 , V_71 ;
if ( V_57 [ V_12 ] . V_72 == NULL )
break;
if ( V_12 + 1 > V_40 ) {
F_33 ( V_41 L_7 ,
V_40 ) ;
break;
}
V_70 = F_2 ( V_57 [ V_12 ] . V_11 ) ;
V_71 = F_34 ( V_70 ) ;
V_69 = ( V_52 >> ( ( V_71 + 1 ) * 4 ) )
& V_73 ;
if ( V_69 == 0 )
continue;
if ( ( ( V_71 + 1 ) > 2 ) &&
! F_24 ( V_74 ) )
F_35 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_67 ] =
V_57 [ V_12 ] ;
V_4 -> V_67 += 1 ;
}
if ( V_34 -> V_35 )
F_25 ( F_16 , NULL , 1 ) ;
if ( V_34 -> V_75 ) {
F_18 ( V_76 , 0 ) ;
F_18 ( V_77 , 0 ) ;
}
if ( V_34 -> V_78 )
F_25 ( F_19 , NULL , 1 ) ;
return 0 ;
}
static int F_15 ( int V_13 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_28 , V_13 ) ;
V_2 -> V_13 = V_13 ;
if ( F_36 ( V_2 ) ) {
F_21 ( V_41 L_10 , V_13 ) ;
F_26 () ;
return - V_79 ;
}
if ( V_34 -> V_35 )
F_13 ( V_13 , F_16 , NULL , 1 ) ;
if ( V_34 -> V_78 )
F_13 ( V_13 , F_19 , NULL , 1 ) ;
return 0 ;
}
static int T_1 F_37 ( void )
{
int V_80 , V_61 ;
if ( V_81 != V_82 )
return - V_49 ;
V_80 = F_20 () ;
if ( V_80 )
return V_80 ;
F_32 () ;
V_80 = F_38 ( & V_66 ) ;
if ( V_80 ) {
struct V_3 * V_4 = F_39 () ;
F_33 (KERN_DEBUG PREFIX L_11 ,
drv ? drv->name : L_12 ) ;
return V_80 ;
}
V_28 = F_40 ( struct V_1 ) ;
if ( V_28 == NULL )
return - V_83 ;
F_41 () ;
F_27 (i) {
V_80 = F_15 ( V_61 ) ;
if ( V_80 ) {
F_42 () ;
F_43 ( & V_66 ) ;
return V_80 ;
}
}
F_44 ( & V_84 ) ;
F_42 () ;
return 0 ;
}
static void T_2 F_45 ( void )
{
F_26 () ;
F_43 ( & V_66 ) ;
F_41 () ;
if ( V_17 != V_27 )
F_25 ( F_9 , ( void * ) false , 1 ) ;
F_46 ( & V_84 ) ;
F_42 () ;
return;
}
