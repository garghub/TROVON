static int F_1 ( int V_1 )
{
int V_2 ;
switch ( V_1 ) {
case 1 :
V_2 = 0x00 ;
break;
case 2 :
V_2 = 0x10 ;
break;
case 3 :
V_2 = 0x20 ;
break;
case 4 :
V_2 = 0x30 ;
break;
case 5 :
V_2 = 0x40 ;
break;
case 6 :
V_2 = 0x52 ;
break;
default:
V_2 = 0x00 ;
}
return V_2 ;
}
static int F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 )
{
unsigned long V_8 = 1 ;
struct V_9 * V_10 = & V_6 -> V_11 [ V_7 ] ;
struct V_12 * V_13 = & V_4 -> V_14 [ V_7 ] ;
unsigned long V_15 = ( unsigned long ) F_3 ( V_13 ) ;
unsigned int V_1 ;
T_1 V_16 , V_17 ;
T_2 V_18 ;
int V_19 = F_4 () ;
V_1 = ( ( ( V_15 ) >> V_20 ) & V_21 ) + 1 ;
F_5 () ;
if ( V_10 -> V_22 & V_23 )
F_6 ( V_19 ) ;
if ( ! ( V_24 & ( 1 << ( V_1 ) ) ) )
F_7 ( V_25 , & V_19 ) ;
V_16 = F_8 () ;
F_9 () ;
if ( ! F_10 () ) {
F_11 ( ( void * ) & F_12 () -> V_22 , 0 , 0 ) ;
F_13 () ;
if ( ! F_10 () )
F_14 ( V_15 , V_8 ) ;
}
F_15 () ;
V_17 = F_8 () ;
V_18 = F_16 ( F_17 ( V_17 , V_16 ) ) ;
F_18 () ;
if ( ! ( V_24 & ( 1 << ( V_1 ) ) ) )
F_7 ( V_26 , & V_19 ) ;
V_4 -> V_27 = ( int ) V_18 ;
return V_7 ;
}
static void F_19 ( void * V_28 )
{
unsigned long V_29 = ( unsigned long ) V_28 ;
int V_19 = F_4 () ;
V_29 = V_29 ?
V_30 : V_31 ;
F_7 ( V_29 , & V_19 ) ;
}
static int F_20 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
int V_36 = ( unsigned long ) V_35 ;
switch ( V_34 & 0xf ) {
case V_37 :
F_21 ( V_36 , F_19 ,
( void * ) true , 1 ) ;
break;
}
return V_38 ;
}
static void F_22 ( void * V_39 )
{
unsigned long long V_40 ;
F_23 ( V_41 , V_40 ) ;
V_40 &= ~ V_42 ;
F_24 ( V_41 , V_40 ) ;
}
static int F_25 ( void )
{
unsigned int V_15 , V_43 , V_8 ;
if ( V_44 == 0 ) {
F_26 ( V_45 L_1 ) ;
return - V_46 ;
}
if ( V_47 . V_48 != V_49 )
return - V_50 ;
if ( ! F_27 ( V_51 ) )
return - V_50 ;
if ( V_47 . V_52 < V_53 )
return - V_50 ;
F_28 ( V_53 , & V_15 , & V_43 , & V_8 , & V_54 ) ;
if ( ! ( V_8 & V_55 ) ||
! ( V_8 & V_56 ) )
return - V_50 ;
F_26 ( V_45 L_2 , V_54 ) ;
if ( V_47 . V_57 != 6 )
return - V_50 ;
switch ( V_47 . V_58 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x2E :
case 0x2F :
case 0x25 :
case 0x2C :
V_59 = V_60 ;
V_42 =
( V_61 | V_62 ) ;
break;
case 0x1C :
V_59 = V_63 ;
break;
case 0x26 :
V_59 = V_63 ;
V_42 = V_64 ;
break;
case 0x2A :
case 0x2D :
V_59 = V_65 ;
break;
default:
F_26 ( V_45 L_3 ,
V_47 . V_57 , V_47 . V_58 ) ;
return - V_50 ;
}
if ( F_27 ( V_66 ) )
V_24 = V_67 ;
else {
F_29 ( F_19 , ( void * ) true , 1 ) ;
F_30 ( & V_68 ) ;
}
F_26 ( V_45 L_4 V_69
L_5 , V_47 . V_58 ) ;
F_26 ( V_45 L_6 ,
V_24 ) ;
return 0 ;
}
static void F_31 ( void )
{
int V_70 ;
struct V_3 * V_4 ;
F_32 (i) {
V_4 = F_33 ( V_71 , V_70 ) ;
F_34 ( V_4 ) ;
}
F_35 ( V_71 ) ;
return;
}
static int F_36 ( void )
{
int V_1 ;
struct V_5 * V_6 = & V_72 ;
V_6 -> V_73 = 1 ;
for ( V_1 = 1 ; V_1 < V_74 ; ++ V_1 ) {
int V_75 ;
if ( V_1 > V_44 ) {
F_37 ( V_45 L_7 ,
V_44 ) ;
break;
}
V_75 = ( V_54 >> ( ( V_1 ) * 4 ) )
& V_76 ;
if ( V_75 == 0 )
continue;
if ( V_59 [ V_1 ] . V_77 == NULL ) {
if ( * V_59 [ V_1 ] . V_78 == '\0' )
F_26 ( V_45 L_8
L_9
L_10 ,
V_47 . V_58 , V_1 ) ;
continue;
}
if ( ( V_1 > 2 ) &&
! F_27 ( V_79 ) )
F_38 ( L_11
L_12 ) ;
V_6 -> V_11 [ V_6 -> V_73 ] =
V_59 [ V_1 ] ;
V_6 -> V_73 += 1 ;
}
if ( V_42 )
F_29 ( F_22 , NULL , 1 ) ;
return 0 ;
}
static int F_39 ( void )
{
int V_70 , V_1 ;
struct V_3 * V_4 ;
V_71 = F_40 ( struct V_3 ) ;
if ( V_71 == NULL )
return - V_80 ;
F_32 (i) {
V_4 = F_33 ( V_71 , V_70 ) ;
V_4 -> V_73 = 1 ;
for ( V_1 = 1 ; V_1 < V_74 ; ++ V_1 ) {
int V_75 ;
if ( V_1 > V_44 ) {
F_37 ( V_45 L_7 ,
V_44 ) ;
break;
}
V_75 = ( V_54 >> ( ( V_1 ) * 4 ) )
& V_76 ;
if ( V_75 == 0 )
continue;
if ( V_59 [ V_1 ] . V_77 == NULL ) {
continue;
}
V_4 -> V_14 [ V_4 -> V_73 ] . V_2 =
( void * ) F_1 ( V_1 ) ;
V_4 -> V_73 += 1 ;
}
V_4 -> V_19 = V_70 ;
if ( F_41 ( V_4 ) ) {
F_26 ( V_45 L_13 ,
V_70 ) ;
F_31 () ;
return - V_81 ;
}
}
return 0 ;
}
static int T_3 F_42 ( void )
{
int V_82 ;
if ( V_83 != V_84 )
return - V_50 ;
V_82 = F_25 () ;
if ( V_82 )
return V_82 ;
F_36 () ;
V_82 = F_43 ( & V_72 ) ;
if ( V_82 ) {
F_37 (KERN_DEBUG PREFIX L_14 ,
cpuidle_get_driver()->name) ;
return V_82 ;
}
V_82 = F_39 () ;
if ( V_82 ) {
F_44 ( & V_72 ) ;
return V_82 ;
}
return 0 ;
}
static void T_4 F_45 ( void )
{
F_31 () ;
F_44 ( & V_72 ) ;
if ( V_24 != V_67 ) {
F_29 ( F_19 , ( void * ) false , 1 ) ;
F_46 ( & V_68 ) ;
}
return;
}
