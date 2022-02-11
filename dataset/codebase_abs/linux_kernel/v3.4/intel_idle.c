static long F_1 ( int V_1 )
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
if ( V_10 -> V_22 & V_23 )
F_5 ( V_19 ) ;
if ( ! ( V_24 & ( 1 << ( V_1 ) ) ) )
F_6 ( V_25 , & V_19 ) ;
V_16 = F_7 () ;
F_8 () ;
if ( ! F_9 () ) {
F_10 ( ( void * ) & F_11 () -> V_22 , 0 , 0 ) ;
F_12 () ;
if ( ! F_9 () )
F_13 ( V_15 , V_8 ) ;
}
F_14 () ;
V_17 = F_7 () ;
V_18 = F_15 ( F_16 ( V_17 , V_16 ) ) ;
F_17 () ;
if ( ! ( V_24 & ( 1 << ( V_1 ) ) ) )
F_6 ( V_26 , & V_19 ) ;
V_4 -> V_27 = ( int ) V_18 ;
return V_7 ;
}
static void F_18 ( void * V_28 )
{
unsigned long V_29 = ( unsigned long ) V_28 ;
int V_19 = F_4 () ;
V_29 = V_29 ?
V_30 : V_31 ;
F_6 ( V_29 , & V_19 ) ;
}
static int F_19 ( struct V_32 * V_33 ,
unsigned long V_34 , void * V_35 )
{
int V_36 = ( unsigned long ) V_35 ;
switch ( V_34 & 0xf ) {
case V_37 :
F_20 ( V_36 , F_18 ,
( void * ) true , 1 ) ;
break;
}
return V_38 ;
}
static void F_21 ( void * V_39 )
{
unsigned long long V_40 ;
F_22 ( V_41 , V_40 ) ;
V_40 &= ~ ( V_42 -> V_43 ) ;
F_23 ( V_41 , V_40 ) ;
}
static int F_24 ( void )
{
unsigned int V_15 , V_44 , V_8 ;
const struct V_45 * V_46 ;
if ( V_47 == 0 ) {
F_25 ( V_48 L_1 ) ;
return - V_49 ;
}
V_46 = F_26 ( V_50 ) ;
if ( ! V_46 ) {
if ( V_51 . V_52 == V_53 &&
V_51 . V_54 == 6 )
F_25 ( V_48 L_2 ,
V_51 . V_54 , V_51 . V_55 ) ;
return - V_56 ;
}
if ( V_51 . V_57 < V_58 )
return - V_56 ;
F_27 ( V_58 , & V_15 , & V_44 , & V_8 , & V_59 ) ;
if ( ! ( V_8 & V_60 ) ||
! ( V_8 & V_61 ) ||
! V_59 )
return - V_56 ;
F_25 ( V_48 L_3 , V_59 ) ;
V_42 = ( const struct V_62 * ) V_46 -> V_2 ;
V_63 = V_42 -> V_64 ;
if ( F_28 ( V_65 ) )
V_24 = V_66 ;
else {
F_29 ( F_18 , ( void * ) true , 1 ) ;
F_30 ( & V_67 ) ;
}
F_25 ( V_48 L_4 V_68
L_5 , V_51 . V_55 ) ;
F_25 ( V_48 L_6 ,
V_24 ) ;
return 0 ;
}
static void F_31 ( void )
{
int V_69 ;
struct V_3 * V_4 ;
F_32 (i) {
V_4 = F_33 ( V_70 , V_69 ) ;
F_34 ( V_4 ) ;
}
F_35 ( V_70 ) ;
return;
}
static int F_36 ( void )
{
int V_1 ;
struct V_5 * V_6 = & V_71 ;
V_6 -> V_72 = 1 ;
for ( V_1 = 1 ; V_1 < V_73 ; ++ V_1 ) {
int V_74 ;
if ( V_1 > V_47 ) {
F_37 ( V_48 L_7 ,
V_47 ) ;
break;
}
V_74 = ( V_59 >> ( ( V_1 ) * 4 ) )
& V_75 ;
if ( V_74 == 0 )
continue;
if ( V_63 [ V_1 ] . V_76 == NULL ) {
if ( * V_63 [ V_1 ] . V_77 == '\0' )
F_25 ( V_48 L_8
L_9
L_10 ,
V_51 . V_55 , V_1 ) ;
continue;
}
if ( ( V_1 > 2 ) &&
! F_28 ( V_78 ) )
F_38 ( L_11
L_12 ) ;
V_6 -> V_11 [ V_6 -> V_72 ] =
V_63 [ V_1 ] ;
V_6 -> V_72 += 1 ;
}
if ( V_42 -> V_43 )
F_29 ( F_21 , NULL , 1 ) ;
return 0 ;
}
int F_39 ( int V_19 )
{
int V_1 ;
struct V_3 * V_4 ;
V_4 = F_33 ( V_70 , V_19 ) ;
V_4 -> V_72 = 1 ;
for ( V_1 = 1 ; V_1 < V_73 ; ++ V_1 ) {
int V_74 ;
if ( V_1 > V_47 ) {
F_37 ( V_48 L_7 , V_47 ) ;
break;
}
V_74 = ( V_59 >> ( ( V_1 ) * 4 ) )
& V_75 ;
if ( V_74 == 0 )
continue;
if ( V_63 [ V_1 ] . V_76 == NULL )
continue;
V_4 -> V_14 [ V_4 -> V_72 ] . V_2 =
( void * ) F_1 ( V_1 ) ;
V_4 -> V_72 += 1 ;
}
V_4 -> V_19 = V_19 ;
if ( F_40 ( V_4 ) ) {
F_25 ( V_48 L_13 , V_19 ) ;
F_31 () ;
return - V_79 ;
}
if ( V_42 -> V_43 )
F_20 ( V_19 , F_21 , NULL , 1 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
int V_80 , V_69 ;
if ( V_81 != V_82 )
return - V_56 ;
V_80 = F_24 () ;
if ( V_80 )
return V_80 ;
F_36 () ;
V_80 = F_42 ( & V_71 ) ;
if ( V_80 ) {
F_37 (KERN_DEBUG PREFIX L_14 ,
cpuidle_get_driver()->name) ;
return V_80 ;
}
V_70 = F_43 ( struct V_3 ) ;
if ( V_70 == NULL )
return - V_83 ;
F_32 (i) {
V_80 = F_39 ( V_69 ) ;
if ( V_80 ) {
F_44 ( & V_71 ) ;
return V_80 ;
}
}
return 0 ;
}
static void T_4 F_45 ( void )
{
F_31 () ;
F_44 ( & V_71 ) ;
if ( V_24 != V_66 ) {
F_29 ( F_18 , ( void * ) false , 1 ) ;
F_46 ( & V_67 ) ;
}
return;
}
