static T_1 int F_1 ( struct V_1 * V_2 ,
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
if ( V_2 -> V_29 )
break;
if ( F_15 ( V_24 ) )
return V_30 ;
break;
}
return V_31 ;
}
static void F_16 ( void * V_32 )
{
unsigned long long V_33 ;
F_17 ( V_34 , V_33 ) ;
V_33 &= ~ ( V_35 -> V_36 ) ;
F_18 ( V_34 , V_33 ) ;
}
static void F_19 ( void * V_32 )
{
unsigned long long V_33 ;
F_17 ( V_37 , V_33 ) ;
V_33 &= ~ 0x2 ;
F_18 ( V_37 , V_33 ) ;
}
static int T_2 F_20 ( void )
{
unsigned int V_10 , V_38 , V_6 ;
const struct V_39 * V_40 ;
if ( V_41 == 0 ) {
F_21 ( V_42 L_1 ) ;
return - V_43 ;
}
V_40 = F_22 ( V_44 ) ;
if ( ! V_40 ) {
if ( V_45 . V_46 == V_47 &&
V_45 . V_48 == 6 )
F_21 ( V_42 L_2 ,
V_45 . V_48 , V_45 . V_49 ) ;
return - V_50 ;
}
if ( V_45 . V_51 < V_52 )
return - V_50 ;
F_23 ( V_52 , & V_10 , & V_38 , & V_6 , & V_53 ) ;
if ( ! ( V_6 & V_54 ) ||
! ( V_6 & V_55 ) ||
! V_53 )
return - V_50 ;
F_21 ( V_42 L_3 , V_53 ) ;
V_35 = ( const struct V_56 * ) V_40 -> V_57 ;
V_58 = V_35 -> V_59 ;
F_21 ( V_42 L_4 V_60
L_5 , V_45 . V_49 ) ;
return 0 ;
}
static void F_24 ( void )
{
int V_61 ;
struct V_1 * V_2 ;
F_25 (i) {
V_2 = F_14 ( V_28 , V_61 ) ;
F_26 ( V_2 ) ;
}
}
static void F_27 ( void )
{
int V_13 , V_62 , V_63 = 1 ;
F_25 (cpu) {
V_62 = F_28 ( V_13 ) ;
if ( V_62 + 1 > V_63 ) {
V_63 = V_62 + 1 ;
if ( V_63 > 4 ) {
V_58 = V_64 ;
return;
}
}
}
if ( V_63 > 2 )
V_58 = V_65 ;
}
static unsigned long long F_29 ( unsigned long long V_66 )
{
unsigned long long V_67 ;
if ( ! V_66 )
return 0 ;
V_67 = V_68 [ ( V_66 >> 10 ) & 0x7 ] ;
return F_30 ( ( V_66 & 0x3FF ) * V_67 , 1000 ) ;
}
static void F_31 ( void )
{
unsigned long long V_69 ;
unsigned int V_70 ;
F_17 ( V_71 , V_69 ) ;
V_70 = F_29 ( V_69 ) ;
if ( V_70 ) {
V_72 [ 2 ] . V_73 = V_70 ;
V_72 [ 2 ] . V_74 = V_70 ;
}
F_17 ( V_75 , V_69 ) ;
V_70 = F_29 ( V_69 ) ;
if ( V_70 ) {
V_72 [ 3 ] . V_73 = V_70 ;
V_72 [ 3 ] . V_74 = V_70 ;
}
F_17 ( V_76 , V_69 ) ;
V_70 = F_29 ( V_69 ) ;
if ( V_70 ) {
V_72 [ 4 ] . V_73 = V_70 ;
V_72 [ 4 ] . V_74 = V_70 ;
}
F_17 ( V_77 , V_69 ) ;
V_70 = F_29 ( V_69 ) ;
if ( V_70 ) {
V_72 [ 5 ] . V_73 = V_70 ;
V_72 [ 5 ] . V_74 = V_70 ;
}
F_17 ( V_78 , V_69 ) ;
V_70 = F_29 ( V_69 ) ;
if ( V_70 ) {
V_72 [ 6 ] . V_73 = V_70 ;
V_72 [ 6 ] . V_74 = V_70 ;
}
}
static void F_32 ( void )
{
unsigned long long V_69 ;
unsigned int V_10 , V_38 , V_6 , V_79 ;
if ( V_41 <= 7 )
return;
if ( ( V_53 & ( 0xF << 28 ) ) == 0 )
return;
F_17 ( V_34 , V_69 ) ;
if ( ( V_69 & 0xF ) != 8 )
return;
V_6 = 0 ;
F_23 ( 7 , & V_10 , & V_38 , & V_6 , & V_79 ) ;
if ( V_38 & ( 1 << 2 ) ) {
F_17 ( V_80 , V_69 ) ;
if ( V_69 & ( 1 << 18 ) )
return;
}
V_81 [ 5 ] . V_82 = 1 ;
V_81 [ 6 ] . V_82 = 1 ;
}
static void F_33 ( void )
{
switch ( V_45 . V_49 ) {
case V_83 :
F_27 () ;
break;
case V_84 :
F_31 () ;
break;
case V_85 :
F_32 () ;
break;
}
}
static void T_2 F_34 ( void )
{
int V_12 ;
struct V_3 * V_4 = & V_86 ;
F_33 () ;
V_4 -> V_87 = 1 ;
for ( V_12 = 0 ; V_12 < V_88 ; ++ V_12 ) {
int V_89 , V_90 , V_91 ;
if ( ( V_58 [ V_12 ] . V_92 == NULL ) &&
( V_58 [ V_12 ] . V_93 == NULL ) )
break;
if ( V_12 + 1 > V_41 ) {
F_35 ( V_42 L_6 ,
V_41 ) ;
break;
}
V_90 = F_2 ( V_58 [ V_12 ] . V_11 ) ;
V_91 = F_36 ( V_90 ) ;
V_89 = ( V_53 >> ( ( V_91 + 1 ) * 4 ) )
& V_94 ;
if ( V_89 == 0 )
continue;
if ( V_58 [ V_12 ] . V_82 != 0 ) {
F_21 ( V_42 L_7 ,
V_58 [ V_12 ] . V_95 ) ;
continue;
}
if ( ( ( V_91 + 1 ) > 2 ) &&
! F_37 ( V_96 ) )
F_38 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_87 ] =
V_58 [ V_12 ] ;
V_4 -> V_87 += 1 ;
}
if ( V_35 -> V_97 ) {
F_18 ( V_98 , 0 ) ;
F_18 ( V_99 , 0 ) ;
}
}
static int F_15 ( int V_13 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_28 , V_13 ) ;
V_2 -> V_13 = V_13 ;
if ( F_39 ( V_2 ) ) {
F_21 ( V_42 L_10 , V_13 ) ;
return - V_100 ;
}
if ( V_35 -> V_36 )
F_13 ( V_13 , F_16 , NULL , 1 ) ;
if ( V_35 -> V_101 )
F_13 ( V_13 , F_19 , NULL , 1 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
int V_102 , V_61 ;
if ( V_103 != V_104 )
return - V_50 ;
V_102 = F_20 () ;
if ( V_102 )
return V_102 ;
V_28 = F_41 ( struct V_1 ) ;
if ( V_28 == NULL )
return - V_105 ;
F_34 () ;
V_102 = F_42 ( & V_86 ) ;
if ( V_102 ) {
struct V_3 * V_4 = F_43 () ;
F_35 (KERN_DEBUG PREFIX L_11 ,
drv ? drv->name : L_12 ) ;
F_44 ( V_28 ) ;
return V_102 ;
}
F_45 () ;
F_25 (i) {
V_102 = F_15 ( V_61 ) ;
if ( V_102 ) {
F_24 () ;
F_46 () ;
F_47 ( & V_86 ) ;
F_44 ( V_28 ) ;
return V_102 ;
}
}
F_48 ( & V_106 ) ;
if ( F_37 ( V_107 ) )
V_17 = V_27 ;
else
F_49 ( F_9 , ( void * ) true , 1 ) ;
F_46 () ;
F_21 ( V_42 L_13 ,
V_17 ) ;
return 0 ;
}
