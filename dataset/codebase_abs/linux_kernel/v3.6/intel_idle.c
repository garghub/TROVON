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
struct V_3 * V_4 ;
switch ( V_34 & 0xf ) {
case V_37 :
if ( V_24 != V_38 )
F_20 ( V_36 , F_18 ,
( void * ) true , 1 ) ;
V_4 = F_21 ( V_39 , V_36 ) ;
if ( ! V_4 -> V_40 )
F_22 ( V_36 ) ;
break;
}
return V_41 ;
}
static void F_23 ( void * V_42 )
{
unsigned long long V_43 ;
F_24 ( V_44 , V_43 ) ;
V_43 &= ~ ( V_45 -> V_46 ) ;
F_25 ( V_44 , V_43 ) ;
}
static int F_26 ( void )
{
unsigned int V_15 , V_47 , V_8 ;
const struct V_48 * V_49 ;
if ( V_50 == 0 ) {
F_27 ( V_51 L_1 ) ;
return - V_52 ;
}
V_49 = F_28 ( V_53 ) ;
if ( ! V_49 ) {
if ( V_54 . V_55 == V_56 &&
V_54 . V_57 == 6 )
F_27 ( V_51 L_2 ,
V_54 . V_57 , V_54 . V_58 ) ;
return - V_59 ;
}
if ( V_54 . V_60 < V_61 )
return - V_59 ;
F_29 ( V_61 , & V_15 , & V_47 , & V_8 , & V_62 ) ;
if ( ! ( V_8 & V_63 ) ||
! ( V_8 & V_64 ) ||
! V_62 )
return - V_59 ;
F_27 ( V_51 L_3 , V_62 ) ;
V_45 = ( const struct V_65 * ) V_49 -> V_2 ;
V_66 = V_45 -> V_67 ;
if ( F_30 ( V_68 ) )
V_24 = V_38 ;
else
F_31 ( F_18 , ( void * ) true , 1 ) ;
F_32 ( & V_69 ) ;
F_27 ( V_51 L_4 V_70
L_5 , V_54 . V_58 ) ;
F_27 ( V_51 L_6 ,
V_24 ) ;
return 0 ;
}
static void F_33 ( void )
{
int V_71 ;
struct V_3 * V_4 ;
F_34 (i) {
V_4 = F_21 ( V_39 , V_71 ) ;
F_35 ( V_4 ) ;
}
F_36 ( V_39 ) ;
return;
}
static int F_37 ( void )
{
int V_1 ;
struct V_5 * V_6 = & V_72 ;
V_6 -> V_73 = 1 ;
for ( V_1 = 1 ; V_1 < V_74 ; ++ V_1 ) {
int V_75 ;
if ( V_1 > V_50 ) {
F_38 ( V_51 L_7 ,
V_50 ) ;
break;
}
V_75 = ( V_62 >> ( ( V_1 ) * 4 ) )
& V_76 ;
if ( V_75 == 0 )
continue;
if ( V_66 [ V_1 ] . V_77 == NULL ) {
if ( * V_66 [ V_1 ] . V_78 == '\0' )
F_27 ( V_51 L_8
L_9
L_10 ,
V_54 . V_58 , V_1 ) ;
continue;
}
if ( ( V_1 > 2 ) &&
! F_30 ( V_79 ) )
F_39 ( L_11
L_12 ) ;
V_6 -> V_11 [ V_6 -> V_73 ] =
V_66 [ V_1 ] ;
V_6 -> V_73 += 1 ;
}
if ( V_45 -> V_46 )
F_31 ( F_23 , NULL , 1 ) ;
return 0 ;
}
static int F_22 ( int V_19 )
{
int V_1 ;
struct V_3 * V_4 ;
V_4 = F_21 ( V_39 , V_19 ) ;
V_4 -> V_73 = 1 ;
for ( V_1 = 1 ; V_1 < V_74 ; ++ V_1 ) {
int V_75 ;
if ( V_1 > V_50 ) {
F_38 ( V_51 L_7 , V_50 ) ;
break;
}
V_75 = ( V_62 >> ( ( V_1 ) * 4 ) )
& V_76 ;
if ( V_75 == 0 )
continue;
if ( V_66 [ V_1 ] . V_77 == NULL )
continue;
V_4 -> V_14 [ V_4 -> V_73 ] . V_2 =
( void * ) F_1 ( V_1 ) ;
V_4 -> V_73 += 1 ;
}
V_4 -> V_19 = V_19 ;
if ( F_40 ( V_4 ) ) {
F_27 ( V_51 L_13 , V_19 ) ;
F_33 () ;
return - V_80 ;
}
if ( V_45 -> V_46 )
F_20 ( V_19 , F_23 , NULL , 1 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
int V_81 , V_71 ;
if ( V_82 != V_83 )
return - V_59 ;
V_81 = F_26 () ;
if ( V_81 )
return V_81 ;
F_37 () ;
V_81 = F_42 ( & V_72 ) ;
if ( V_81 ) {
struct V_5 * V_6 = F_43 () ;
F_38 (KERN_DEBUG PREFIX L_14 ,
drv ? drv->name : L_15 ) ;
return V_81 ;
}
V_39 = F_44 ( struct V_3 ) ;
if ( V_39 == NULL )
return - V_84 ;
F_34 (i) {
V_81 = F_22 ( V_71 ) ;
if ( V_81 ) {
F_45 ( & V_72 ) ;
return V_81 ;
}
}
return 0 ;
}
static void T_4 F_46 ( void )
{
F_33 () ;
F_45 ( & V_72 ) ;
if ( V_24 != V_38 )
F_31 ( F_18 , ( void * ) false , 1 ) ;
F_47 ( & V_69 ) ;
return;
}
