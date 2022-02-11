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
int V_16 = F_4 () ;
V_1 = ( ( ( V_15 ) >> V_17 ) & V_18 ) + 1 ;
if ( V_10 -> V_19 & V_20 )
F_5 ( V_16 ) ;
if ( ! ( V_21 & ( 1 << ( V_1 ) ) ) )
F_6 ( V_22 , & V_16 ) ;
F_7 () ;
if ( ! F_8 () ) {
F_9 ( ( void * ) & F_10 () -> V_19 , 0 , 0 ) ;
F_11 () ;
if ( ! F_8 () )
F_12 ( V_15 , V_8 ) ;
}
F_13 () ;
if ( ! ( V_21 & ( 1 << ( V_1 ) ) ) )
F_6 ( V_23 , & V_16 ) ;
return V_7 ;
}
static void F_14 ( void * V_24 )
{
unsigned long V_25 = ( unsigned long ) V_24 ;
int V_16 = F_4 () ;
V_25 = V_25 ?
V_26 : V_27 ;
F_6 ( V_25 , & V_16 ) ;
}
static int F_15 ( struct V_28 * V_29 ,
unsigned long V_30 , void * V_31 )
{
int V_32 = ( unsigned long ) V_31 ;
struct V_3 * V_4 ;
switch ( V_30 & 0xf ) {
case V_33 :
if ( V_21 != V_34 )
F_16 ( V_32 , F_14 ,
( void * ) true , 1 ) ;
V_4 = F_17 ( V_35 , V_32 ) ;
if ( ! V_4 -> V_36 )
F_18 ( V_32 ) ;
break;
}
return V_37 ;
}
static void F_19 ( void * V_38 )
{
unsigned long long V_39 ;
F_20 ( V_40 , V_39 ) ;
V_39 &= ~ ( V_41 -> V_42 ) ;
F_21 ( V_40 , V_39 ) ;
}
static int F_22 ( void )
{
unsigned int V_15 , V_43 , V_8 ;
const struct V_44 * V_45 ;
if ( V_46 == 0 ) {
F_23 ( V_47 L_1 ) ;
return - V_48 ;
}
V_45 = F_24 ( V_49 ) ;
if ( ! V_45 ) {
if ( V_50 . V_51 == V_52 &&
V_50 . V_53 == 6 )
F_23 ( V_47 L_2 ,
V_50 . V_53 , V_50 . V_54 ) ;
return - V_55 ;
}
if ( V_50 . V_56 < V_57 )
return - V_55 ;
F_25 ( V_57 , & V_15 , & V_43 , & V_8 , & V_58 ) ;
if ( ! ( V_8 & V_59 ) ||
! ( V_8 & V_60 ) ||
! V_58 )
return - V_55 ;
F_23 ( V_47 L_3 , V_58 ) ;
V_41 = ( const struct V_61 * ) V_45 -> V_2 ;
V_62 = V_41 -> V_63 ;
if ( F_26 ( V_64 ) )
V_21 = V_34 ;
else
F_27 ( F_14 , ( void * ) true , 1 ) ;
F_23 ( V_47 L_4 V_65
L_5 , V_50 . V_54 ) ;
F_23 ( V_47 L_6 ,
V_21 ) ;
return 0 ;
}
static void F_28 ( void )
{
int V_66 ;
struct V_3 * V_4 ;
F_29 (i) {
V_4 = F_17 ( V_35 , V_66 ) ;
F_30 ( V_4 ) ;
}
F_31 ( V_35 ) ;
return;
}
static int F_32 ( void )
{
int V_1 ;
struct V_5 * V_6 = & V_67 ;
V_6 -> V_68 = 1 ;
for ( V_1 = 1 ; V_1 < V_69 ; ++ V_1 ) {
int V_70 ;
if ( V_1 > V_46 ) {
F_33 ( V_47 L_7 ,
V_46 ) ;
break;
}
V_70 = ( V_58 >> ( ( V_1 ) * 4 ) )
& V_71 ;
if ( V_70 == 0 )
continue;
if ( V_62 [ V_1 ] . V_72 == NULL ) {
if ( * V_62 [ V_1 ] . V_73 == '\0' )
F_23 ( V_47 L_8
L_9
L_10 ,
V_50 . V_54 , V_1 ) ;
continue;
}
if ( ( V_1 > 2 ) &&
! F_26 ( V_74 ) )
F_34 ( L_11
L_12 ) ;
V_6 -> V_11 [ V_6 -> V_68 ] =
V_62 [ V_1 ] ;
V_6 -> V_68 += 1 ;
}
if ( V_41 -> V_42 )
F_27 ( F_19 , NULL , 1 ) ;
return 0 ;
}
static int F_18 ( int V_16 )
{
int V_1 ;
struct V_3 * V_4 ;
V_4 = F_17 ( V_35 , V_16 ) ;
V_4 -> V_68 = 1 ;
for ( V_1 = 1 ; V_1 < V_69 ; ++ V_1 ) {
int V_70 ;
if ( V_1 > V_46 ) {
F_33 ( V_47 L_7 , V_46 ) ;
break;
}
V_70 = ( V_58 >> ( ( V_1 ) * 4 ) )
& V_71 ;
if ( V_70 == 0 )
continue;
if ( V_62 [ V_1 ] . V_72 == NULL )
continue;
V_4 -> V_14 [ V_4 -> V_68 ] . V_2 =
( void * ) F_1 ( V_1 ) ;
V_4 -> V_68 += 1 ;
}
V_4 -> V_16 = V_16 ;
if ( F_35 ( V_4 ) ) {
F_23 ( V_47 L_13 , V_16 ) ;
F_28 () ;
return - V_75 ;
}
if ( V_41 -> V_42 )
F_16 ( V_16 , F_19 , NULL , 1 ) ;
return 0 ;
}
static int T_1 F_36 ( void )
{
int V_76 , V_66 ;
if ( V_77 != V_78 )
return - V_55 ;
V_76 = F_22 () ;
if ( V_76 )
return V_76 ;
F_32 () ;
V_76 = F_37 ( & V_67 ) ;
if ( V_76 ) {
struct V_5 * V_6 = F_38 () ;
F_33 (KERN_DEBUG PREFIX L_14 ,
drv ? drv->name : L_15 ) ;
return V_76 ;
}
V_35 = F_39 ( struct V_3 ) ;
if ( V_35 == NULL )
return - V_79 ;
F_29 (i) {
V_76 = F_18 ( V_66 ) ;
if ( V_76 ) {
F_40 ( & V_67 ) ;
return V_76 ;
}
}
F_41 ( & V_80 ) ;
return 0 ;
}
static void T_2 F_42 ( void )
{
F_28 () ;
F_40 ( & V_67 ) ;
if ( V_21 != V_34 )
F_27 ( F_14 , ( void * ) false , 1 ) ;
F_43 ( & V_80 ) ;
return;
}
