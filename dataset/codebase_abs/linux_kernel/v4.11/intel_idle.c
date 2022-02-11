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
static void F_9 ( bool V_18 )
{
if ( V_18 )
F_10 () ;
else
F_11 () ;
}
static void F_12 ( void )
{
unsigned long long V_19 ;
F_13 ( V_20 , V_19 ) ;
V_19 &= ~ ( V_21 -> V_22 ) ;
F_14 ( V_20 , V_19 ) ;
}
static void F_15 ( void )
{
unsigned long long V_19 ;
F_13 ( V_23 , V_19 ) ;
V_19 &= ~ 0x2 ;
F_14 ( V_23 , V_19 ) ;
}
static int T_2 F_16 ( void )
{
unsigned int V_10 , V_24 , V_6 ;
const struct V_25 * V_26 ;
if ( V_27 == 0 ) {
F_17 ( V_28 L_1 ) ;
return - V_29 ;
}
V_26 = F_18 ( V_30 ) ;
if ( ! V_26 ) {
if ( V_31 . V_32 == V_33 &&
V_31 . V_34 == 6 )
F_17 ( V_28 L_2 ,
V_31 . V_34 , V_31 . V_35 ) ;
return - V_36 ;
}
if ( V_31 . V_37 < V_38 )
return - V_36 ;
F_19 ( V_38 , & V_10 , & V_24 , & V_6 , & V_39 ) ;
if ( ! ( V_6 & V_40 ) ||
! ( V_6 & V_41 ) ||
! V_39 )
return - V_36 ;
F_17 ( V_28 L_3 , V_39 ) ;
V_21 = ( const struct V_42 * ) V_26 -> V_43 ;
V_44 = V_21 -> V_45 ;
F_17 ( V_28 L_4 V_46
L_5 , V_31 . V_35 ) ;
return 0 ;
}
static void F_20 ( void )
{
int V_47 ;
struct V_1 * V_2 ;
F_21 (i) {
V_2 = F_22 ( V_48 , V_47 ) ;
F_23 ( V_2 ) ;
}
}
static void F_24 ( void )
{
int V_13 , V_49 , V_50 = 1 ;
F_21 (cpu) {
V_49 = F_25 ( V_13 ) ;
if ( V_49 + 1 > V_50 ) {
V_50 = V_49 + 1 ;
if ( V_50 > 4 ) {
V_44 = V_51 ;
return;
}
}
}
if ( V_50 > 2 )
V_44 = V_52 ;
}
static unsigned long long F_26 ( unsigned long long V_53 )
{
unsigned long long V_54 ;
if ( ! V_53 )
return 0 ;
V_54 = V_55 [ ( V_53 >> 10 ) & 0x7 ] ;
return F_27 ( ( V_53 & 0x3FF ) * V_54 , 1000 ) ;
}
static void F_28 ( void )
{
unsigned long long V_56 ;
unsigned int V_57 ;
F_13 ( V_58 , V_56 ) ;
V_57 = F_26 ( V_56 ) ;
if ( V_57 ) {
V_59 [ 2 ] . V_60 = V_57 ;
V_59 [ 2 ] . V_61 = V_57 ;
}
F_13 ( V_62 , V_56 ) ;
V_57 = F_26 ( V_56 ) ;
if ( V_57 ) {
V_59 [ 3 ] . V_60 = V_57 ;
V_59 [ 3 ] . V_61 = V_57 ;
}
F_13 ( V_63 , V_56 ) ;
V_57 = F_26 ( V_56 ) ;
if ( V_57 ) {
V_59 [ 4 ] . V_60 = V_57 ;
V_59 [ 4 ] . V_61 = V_57 ;
}
F_13 ( V_64 , V_56 ) ;
V_57 = F_26 ( V_56 ) ;
if ( V_57 ) {
V_59 [ 5 ] . V_60 = V_57 ;
V_59 [ 5 ] . V_61 = V_57 ;
}
F_13 ( V_65 , V_56 ) ;
V_57 = F_26 ( V_56 ) ;
if ( V_57 ) {
V_59 [ 6 ] . V_60 = V_57 ;
V_59 [ 6 ] . V_61 = V_57 ;
}
}
static void F_29 ( void )
{
unsigned long long V_56 ;
unsigned int V_10 , V_24 , V_6 , V_66 ;
if ( V_27 <= 7 )
return;
if ( ( V_39 & ( 0xF << 28 ) ) == 0 )
return;
F_13 ( V_20 , V_56 ) ;
if ( ( V_56 & 0xF ) != 8 )
return;
V_6 = 0 ;
F_19 ( 7 , & V_10 , & V_24 , & V_6 , & V_66 ) ;
if ( V_24 & ( 1 << 2 ) ) {
F_13 ( V_67 , V_56 ) ;
if ( V_56 & ( 1 << 18 ) )
return;
}
V_68 [ 5 ] . V_69 = 1 ;
V_68 [ 6 ] . V_69 = 1 ;
}
static void F_30 ( void )
{
switch ( V_31 . V_35 ) {
case V_70 :
F_24 () ;
break;
case V_71 :
F_28 () ;
break;
case V_72 :
F_29 () ;
break;
}
}
static void T_2 F_31 ( void )
{
int V_12 ;
struct V_3 * V_4 = & V_73 ;
F_30 () ;
V_4 -> V_74 = 1 ;
for ( V_12 = 0 ; V_12 < V_75 ; ++ V_12 ) {
int V_76 , V_77 , V_78 ;
if ( ( V_44 [ V_12 ] . V_79 == NULL ) &&
( V_44 [ V_12 ] . V_80 == NULL ) )
break;
if ( V_12 + 1 > V_27 ) {
F_32 ( V_28 L_6 ,
V_27 ) ;
break;
}
V_77 = F_2 ( V_44 [ V_12 ] . V_11 ) ;
V_78 = F_33 ( V_77 ) ;
V_76 = ( V_39 >> ( ( V_78 + 1 ) * 4 ) )
& V_81 ;
if ( V_76 == 0 )
continue;
if ( V_44 [ V_12 ] . V_69 != 0 ) {
F_17 ( V_28 L_7 ,
V_44 [ V_12 ] . V_82 ) ;
continue;
}
if ( ( ( V_78 + 1 ) > 2 ) &&
! F_34 ( V_83 ) )
F_35 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_74 ] =
V_44 [ V_12 ] ;
V_4 -> V_74 += 1 ;
}
if ( V_21 -> V_84 ) {
F_14 ( V_85 , 0 ) ;
F_14 ( V_86 , 0 ) ;
}
}
static int F_36 ( unsigned int V_13 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_48 , V_13 ) ;
V_2 -> V_13 = V_13 ;
if ( F_37 ( V_2 ) ) {
F_17 ( V_28 L_10 , V_13 ) ;
return - V_87 ;
}
if ( V_21 -> V_22 )
F_12 () ;
if ( V_21 -> V_88 )
F_15 () ;
return 0 ;
}
static int F_38 ( unsigned int V_13 )
{
struct V_1 * V_2 ;
if ( V_17 != V_89 )
F_9 ( true ) ;
V_2 = F_22 ( V_48 , V_13 ) ;
if ( ! V_2 -> V_90 )
return F_36 ( V_13 ) ;
return 0 ;
}
static int T_2 F_39 ( void )
{
int V_91 ;
if ( V_92 != V_93 )
return - V_36 ;
V_91 = F_16 () ;
if ( V_91 )
return V_91 ;
V_48 = F_40 ( struct V_1 ) ;
if ( V_48 == NULL )
return - V_94 ;
F_31 () ;
V_91 = F_41 ( & V_73 ) ;
if ( V_91 ) {
struct V_3 * V_4 = F_42 () ;
F_32 (KERN_DEBUG PREFIX L_11 ,
drv ? drv->name : L_12 ) ;
goto V_95;
}
if ( F_34 ( V_96 ) )
V_17 = V_89 ;
V_91 = F_43 ( V_97 , L_13 ,
F_38 , NULL ) ;
if ( V_91 < 0 )
goto V_98;
F_17 ( V_28 L_14 ,
V_17 ) ;
return 0 ;
V_98:
F_20 () ;
F_44 ( & V_73 ) ;
V_95:
F_45 ( V_48 ) ;
return V_91 ;
}
