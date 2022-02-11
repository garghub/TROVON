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
static void F_7 ( void * V_20 )
{
unsigned long V_21 = ( unsigned long ) V_20 ;
int V_13 = F_3 () ;
V_21 = V_21 ?
V_22 : V_23 ;
F_5 ( V_21 , & V_13 ) ;
}
static int F_8 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
int V_28 = ( unsigned long ) V_27 ;
struct V_1 * V_2 ;
switch ( V_26 & ~ V_29 ) {
case V_30 :
if ( V_17 != V_31 )
F_9 ( V_28 , F_7 ,
( void * ) true , 1 ) ;
V_2 = F_10 ( V_32 , V_28 ) ;
if ( ! V_2 -> V_33 )
F_11 ( V_28 ) ;
break;
}
return V_34 ;
}
static void F_12 ( void * V_35 )
{
unsigned long long V_36 ;
F_13 ( V_37 , V_36 ) ;
V_36 &= ~ ( V_38 -> V_39 ) ;
F_14 ( V_37 , V_36 ) ;
}
static void F_15 ( void * V_35 )
{
unsigned long long V_36 ;
F_13 ( V_40 , V_36 ) ;
V_36 &= ~ 0x2 ;
F_14 ( V_40 , V_36 ) ;
}
static int T_1 F_16 ( void )
{
unsigned int V_10 , V_41 , V_6 ;
const struct V_42 * V_43 ;
if ( V_44 == 0 ) {
F_17 ( V_45 L_1 ) ;
return - V_46 ;
}
V_43 = F_18 ( V_47 ) ;
if ( ! V_43 ) {
if ( V_48 . V_49 == V_50 &&
V_48 . V_51 == 6 )
F_17 ( V_45 L_2 ,
V_48 . V_51 , V_48 . V_52 ) ;
return - V_53 ;
}
if ( V_48 . V_54 < V_55 )
return - V_53 ;
F_19 ( V_55 , & V_10 , & V_41 , & V_6 , & V_56 ) ;
if ( ! ( V_6 & V_57 ) ||
! ( V_6 & V_58 ) ||
! V_56 )
return - V_53 ;
F_17 ( V_45 L_3 , V_56 ) ;
V_38 = ( const struct V_59 * ) V_43 -> V_60 ;
V_61 = V_38 -> V_62 ;
if ( F_20 ( V_63 ) )
V_17 = V_31 ;
else
F_21 ( F_7 , ( void * ) true , 1 ) ;
F_17 ( V_45 L_4 V_64
L_5 , V_48 . V_52 ) ;
F_17 ( V_45 L_6 ,
V_17 ) ;
return 0 ;
}
static void F_22 ( void )
{
int V_65 ;
struct V_1 * V_2 ;
F_23 (i) {
V_2 = F_10 ( V_32 , V_65 ) ;
F_24 ( V_2 ) ;
}
F_25 ( V_32 ) ;
return;
}
static int T_1 F_26 ( void )
{
int V_12 ;
struct V_3 * V_4 = & V_66 ;
V_4 -> V_67 = 1 ;
for ( V_12 = 0 ; V_12 < V_68 ; ++ V_12 ) {
int V_69 , V_70 , V_71 , V_72 ;
if ( V_61 [ V_12 ] . V_73 == NULL )
break;
if ( V_12 + 1 > V_44 ) {
F_27 ( V_45 L_7 ,
V_44 ) ;
break;
}
V_70 = F_2 ( V_61 [ V_12 ] . V_11 ) ;
V_71 = F_28 ( V_70 ) ;
V_72 = F_29 ( V_70 ) ;
V_69 = ( V_56 >> ( ( V_71 + 1 ) * 4 ) )
& V_74 ;
if ( ( V_72 + 1 ) > V_69 )
continue;
if ( ( ( V_71 + 1 ) > 2 ) &&
! F_20 ( V_75 ) )
F_30 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_67 ] =
V_61 [ V_12 ] ;
V_4 -> V_67 += 1 ;
}
if ( V_38 -> V_39 )
F_21 ( F_12 , NULL , 1 ) ;
if ( V_38 -> V_76 )
F_21 ( F_15 , NULL , 1 ) ;
return 0 ;
}
static int F_11 ( int V_13 )
{
struct V_1 * V_2 ;
V_2 = F_10 ( V_32 , V_13 ) ;
V_2 -> V_13 = V_13 ;
if ( F_31 ( V_2 ) ) {
F_17 ( V_45 L_10 , V_13 ) ;
F_22 () ;
return - V_77 ;
}
if ( V_38 -> V_39 )
F_9 ( V_13 , F_12 , NULL , 1 ) ;
if ( V_38 -> V_76 )
F_9 ( V_13 , F_15 , NULL , 1 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
int V_78 , V_65 ;
if ( V_79 != V_80 )
return - V_53 ;
V_78 = F_16 () ;
if ( V_78 )
return V_78 ;
F_26 () ;
V_78 = F_33 ( & V_66 ) ;
if ( V_78 ) {
struct V_3 * V_4 = F_34 () ;
F_27 (KERN_DEBUG PREFIX L_11 ,
drv ? drv->name : L_12 ) ;
return V_78 ;
}
V_32 = F_35 ( struct V_1 ) ;
if ( V_32 == NULL )
return - V_81 ;
F_23 (i) {
V_78 = F_11 ( V_65 ) ;
if ( V_78 ) {
F_36 ( & V_66 ) ;
return V_78 ;
}
}
F_37 ( & V_82 ) ;
return 0 ;
}
static void T_2 F_38 ( void )
{
F_22 () ;
F_36 ( & V_66 ) ;
if ( V_17 != V_31 )
F_21 ( F_7 , ( void * ) false , 1 ) ;
F_39 ( & V_82 ) ;
return;
}
