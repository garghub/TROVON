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
F_17 ( L_1 ) ;
return - V_28 ;
}
V_26 = F_18 ( V_29 ) ;
if ( ! V_26 ) {
if ( V_30 . V_31 == V_32 &&
V_30 . V_33 == 6 )
F_17 ( L_2 ,
V_30 . V_33 , V_30 . V_34 ) ;
return - V_35 ;
}
if ( V_30 . V_36 < V_37 )
return - V_35 ;
F_19 ( V_37 , & V_10 , & V_24 , & V_6 , & V_38 ) ;
if ( ! ( V_6 & V_39 ) ||
! ( V_6 & V_40 ) ||
! V_38 )
return - V_35 ;
F_17 ( L_3 , V_38 ) ;
V_21 = ( const struct V_41 * ) V_26 -> V_42 ;
V_43 = V_21 -> V_44 ;
F_17 ( L_4 V_45 L_5 ,
V_30 . V_34 ) ;
return 0 ;
}
static void F_20 ( void )
{
int V_46 ;
struct V_1 * V_2 ;
F_21 (i) {
V_2 = F_22 ( V_47 , V_46 ) ;
F_23 ( V_2 ) ;
}
}
static void F_24 ( void )
{
int V_13 , V_48 , V_49 = 1 ;
F_21 (cpu) {
V_48 = F_25 ( V_13 ) ;
if ( V_48 + 1 > V_49 ) {
V_49 = V_48 + 1 ;
if ( V_49 > 4 ) {
V_43 = V_50 ;
return;
}
}
}
if ( V_49 > 2 )
V_43 = V_51 ;
}
static unsigned long long F_26 ( unsigned long long V_52 )
{
unsigned long long V_53 ;
if ( ! V_52 )
return 0 ;
V_53 = V_54 [ ( V_52 >> 10 ) & 0x7 ] ;
return F_27 ( ( V_52 & 0x3FF ) * V_53 , 1000 ) ;
}
static void F_28 ( void )
{
unsigned long long V_55 ;
unsigned int V_56 ;
F_13 ( V_57 , V_55 ) ;
V_56 = F_26 ( V_55 ) ;
if ( V_56 ) {
V_58 [ 2 ] . V_59 = V_56 ;
V_58 [ 2 ] . V_60 = V_56 ;
}
F_13 ( V_61 , V_55 ) ;
V_56 = F_26 ( V_55 ) ;
if ( V_56 ) {
V_58 [ 3 ] . V_59 = V_56 ;
V_58 [ 3 ] . V_60 = V_56 ;
}
F_13 ( V_62 , V_55 ) ;
V_56 = F_26 ( V_55 ) ;
if ( V_56 ) {
V_58 [ 4 ] . V_59 = V_56 ;
V_58 [ 4 ] . V_60 = V_56 ;
}
F_13 ( V_63 , V_55 ) ;
V_56 = F_26 ( V_55 ) ;
if ( V_56 ) {
V_58 [ 5 ] . V_59 = V_56 ;
V_58 [ 5 ] . V_60 = V_56 ;
}
F_13 ( V_64 , V_55 ) ;
V_56 = F_26 ( V_55 ) ;
if ( V_56 ) {
V_58 [ 6 ] . V_59 = V_56 ;
V_58 [ 6 ] . V_60 = V_56 ;
}
}
static void F_29 ( void )
{
unsigned long long V_55 ;
unsigned int V_10 , V_24 , V_6 , V_65 ;
if ( V_27 <= 7 )
return;
if ( ( V_38 & ( 0xF << 28 ) ) == 0 )
return;
F_13 ( V_20 , V_55 ) ;
if ( ( V_55 & 0xF ) != 8 )
return;
V_6 = 0 ;
F_19 ( 7 , & V_10 , & V_24 , & V_6 , & V_65 ) ;
if ( V_24 & ( 1 << 2 ) ) {
F_13 ( V_66 , V_55 ) ;
if ( V_55 & ( 1 << 18 ) )
return;
}
V_67 [ 5 ] . V_68 = 1 ;
V_67 [ 6 ] . V_68 = 1 ;
}
static void F_30 ( void )
{
switch ( V_30 . V_34 ) {
case V_69 :
F_24 () ;
break;
case V_70 :
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
F_32 ( V_4 ) ;
V_4 -> V_74 = 1 ;
for ( V_12 = 0 ; V_12 < V_75 ; ++ V_12 ) {
int V_76 , V_77 , V_78 ;
if ( ( V_43 [ V_12 ] . V_79 == NULL ) &&
( V_43 [ V_12 ] . V_80 == NULL ) )
break;
if ( V_12 + 1 > V_27 ) {
F_33 ( L_6 , V_27 ) ;
break;
}
V_77 = F_2 ( V_43 [ V_12 ] . V_11 ) ;
V_78 = F_34 ( V_77 ) ;
V_76 = ( V_38 >> ( ( V_78 + 1 ) * 4 ) )
& V_81 ;
if ( V_76 == 0 )
continue;
if ( V_43 [ V_12 ] . V_68 != 0 ) {
F_17 ( L_7 ,
V_43 [ V_12 ] . V_82 ) ;
continue;
}
if ( ( ( V_78 + 1 ) > 2 ) &&
! F_35 ( V_83 ) )
F_36 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_74 ] =
V_43 [ V_12 ] ;
V_4 -> V_74 += 1 ;
}
if ( V_21 -> V_84 ) {
F_14 ( V_85 , 0 ) ;
F_14 ( V_86 , 0 ) ;
}
}
static int F_37 ( unsigned int V_13 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_47 , V_13 ) ;
V_2 -> V_13 = V_13 ;
if ( F_38 ( V_2 ) ) {
F_17 ( L_10 , V_13 ) ;
return - V_87 ;
}
if ( V_21 -> V_22 )
F_12 () ;
if ( V_21 -> V_88 )
F_15 () ;
return 0 ;
}
static int F_39 ( unsigned int V_13 )
{
struct V_1 * V_2 ;
if ( V_17 != V_89 )
F_9 ( true ) ;
V_2 = F_22 ( V_47 , V_13 ) ;
if ( ! V_2 -> V_90 )
return F_37 ( V_13 ) ;
return 0 ;
}
static int T_2 F_40 ( void )
{
int V_91 ;
if ( V_92 != V_93 )
return - V_35 ;
V_91 = F_16 () ;
if ( V_91 )
return V_91 ;
V_47 = F_41 ( struct V_1 ) ;
if ( V_47 == NULL )
return - V_94 ;
F_31 () ;
V_91 = F_42 ( & V_73 ) ;
if ( V_91 ) {
struct V_3 * V_4 = F_43 () ;
F_44 (KERN_DEBUG pr_fmt(L_11),
drv ? drv->name : L_12 ) ;
goto V_95;
}
if ( F_35 ( V_96 ) )
V_17 = V_89 ;
V_91 = F_45 ( V_97 , L_13 ,
F_39 , NULL ) ;
if ( V_91 < 0 )
goto V_98;
F_17 ( L_14 ,
V_17 ) ;
return 0 ;
V_98:
F_20 () ;
F_46 ( & V_73 ) ;
V_95:
F_47 ( V_47 ) ;
return V_91 ;
}
