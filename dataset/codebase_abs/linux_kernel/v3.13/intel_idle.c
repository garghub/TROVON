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
if ( ! F_6 () ) {
if ( F_7 ( V_19 ) )
F_8 ( ( void * ) & F_9 () -> V_11 ) ;
F_10 ( ( void * ) & F_9 () -> V_11 , 0 , 0 ) ;
F_11 () ;
if ( ! F_12 () )
F_13 ( V_10 , V_6 ) ;
}
if ( ! ( V_17 & ( 1 << ( V_12 ) ) ) )
F_5 ( V_20 , & V_13 ) ;
return V_5 ;
}
static void F_14 ( void * V_21 )
{
unsigned long V_22 = ( unsigned long ) V_21 ;
int V_13 = F_3 () ;
V_22 = V_22 ?
V_23 : V_24 ;
F_5 ( V_22 , & V_13 ) ;
}
static int F_15 ( struct V_25 * V_26 ,
unsigned long V_27 , void * V_28 )
{
int V_29 = ( unsigned long ) V_28 ;
struct V_1 * V_2 ;
switch ( V_27 & ~ V_30 ) {
case V_31 :
if ( V_17 != V_32 )
F_16 ( V_29 , F_14 ,
( void * ) true , 1 ) ;
V_2 = F_17 ( V_33 , V_29 ) ;
if ( ! V_2 -> V_34 )
F_18 ( V_29 ) ;
break;
}
return V_35 ;
}
static void F_19 ( void * V_36 )
{
unsigned long long V_37 ;
F_20 ( V_38 , V_37 ) ;
V_37 &= ~ ( V_39 -> V_40 ) ;
F_21 ( V_38 , V_37 ) ;
}
static void F_22 ( void * V_36 )
{
unsigned long long V_37 ;
F_20 ( V_41 , V_37 ) ;
V_37 &= ~ 0x2 ;
F_21 ( V_41 , V_37 ) ;
}
static int T_1 F_23 ( void )
{
unsigned int V_10 , V_42 , V_6 ;
const struct V_43 * V_44 ;
if ( V_45 == 0 ) {
F_24 ( V_46 L_1 ) ;
return - V_47 ;
}
V_44 = F_25 ( V_48 ) ;
if ( ! V_44 ) {
if ( V_49 . V_50 == V_51 &&
V_49 . V_52 == 6 )
F_24 ( V_46 L_2 ,
V_49 . V_52 , V_49 . V_53 ) ;
return - V_54 ;
}
if ( V_49 . V_55 < V_56 )
return - V_54 ;
F_26 ( V_56 , & V_10 , & V_42 , & V_6 , & V_57 ) ;
if ( ! ( V_6 & V_58 ) ||
! ( V_6 & V_59 ) ||
! V_57 )
return - V_54 ;
F_24 ( V_46 L_3 , V_57 ) ;
V_39 = ( const struct V_60 * ) V_44 -> V_61 ;
V_62 = V_39 -> V_63 ;
if ( F_27 ( V_64 ) )
V_17 = V_32 ;
else
F_28 ( F_14 , ( void * ) true , 1 ) ;
F_24 ( V_46 L_4 V_65
L_5 , V_49 . V_53 ) ;
F_24 ( V_46 L_6 ,
V_17 ) ;
return 0 ;
}
static void F_29 ( void )
{
int V_66 ;
struct V_1 * V_2 ;
F_30 (i) {
V_2 = F_17 ( V_33 , V_66 ) ;
F_31 ( V_2 ) ;
}
F_32 ( V_33 ) ;
return;
}
static int T_1 F_33 ( void )
{
int V_12 ;
struct V_3 * V_4 = & V_67 ;
V_4 -> V_68 = 1 ;
for ( V_12 = 0 ; V_12 < V_69 ; ++ V_12 ) {
int V_70 , V_71 , V_72 , V_73 ;
if ( V_62 [ V_12 ] . V_74 == NULL )
break;
if ( V_12 + 1 > V_45 ) {
F_34 ( V_46 L_7 ,
V_45 ) ;
break;
}
V_71 = F_2 ( V_62 [ V_12 ] . V_11 ) ;
V_72 = F_35 ( V_71 ) ;
V_73 = F_36 ( V_71 ) ;
V_70 = ( V_57 >> ( ( V_72 + 1 ) * 4 ) )
& V_75 ;
if ( ( V_73 + 1 ) > V_70 )
continue;
if ( ( ( V_72 + 1 ) > 2 ) &&
! F_27 ( V_76 ) )
F_37 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_68 ] =
V_62 [ V_12 ] ;
V_4 -> V_68 += 1 ;
}
if ( V_39 -> V_40 )
F_28 ( F_19 , NULL , 1 ) ;
if ( V_39 -> V_77 )
F_28 ( F_22 , NULL , 1 ) ;
return 0 ;
}
static int F_18 ( int V_13 )
{
int V_12 ;
struct V_1 * V_2 ;
V_2 = F_17 ( V_33 , V_13 ) ;
V_2 -> V_68 = 1 ;
for ( V_12 = 0 ; V_12 < V_69 ; ++ V_12 ) {
int V_70 , V_71 , V_72 , V_73 ;
if ( V_62 [ V_12 ] . V_74 == NULL )
break;
if ( V_12 + 1 > V_45 ) {
F_34 ( V_46 L_7 , V_45 ) ;
break;
}
V_71 = F_2 ( V_62 [ V_12 ] . V_11 ) ;
V_72 = F_35 ( V_71 ) ;
V_73 = F_36 ( V_71 ) ;
V_70 = ( V_57 >> ( ( V_72 + 1 ) * 4 ) )
& V_75 ;
if ( ( V_73 + 1 ) > V_70 )
continue;
V_2 -> V_68 += 1 ;
}
V_2 -> V_13 = V_13 ;
if ( F_38 ( V_2 ) ) {
F_24 ( V_46 L_10 , V_13 ) ;
F_29 () ;
return - V_78 ;
}
if ( V_39 -> V_40 )
F_16 ( V_13 , F_19 , NULL , 1 ) ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_79 , V_66 ;
if ( V_80 != V_81 )
return - V_54 ;
V_79 = F_23 () ;
if ( V_79 )
return V_79 ;
F_33 () ;
V_79 = F_40 ( & V_67 ) ;
if ( V_79 ) {
struct V_3 * V_4 = F_41 () ;
F_34 (KERN_DEBUG PREFIX L_11 ,
drv ? drv->name : L_12 ) ;
return V_79 ;
}
V_33 = F_42 ( struct V_1 ) ;
if ( V_33 == NULL )
return - V_82 ;
F_30 (i) {
V_79 = F_18 ( V_66 ) ;
if ( V_79 ) {
F_43 ( & V_67 ) ;
return V_79 ;
}
}
F_44 ( & V_83 ) ;
return 0 ;
}
static void T_2 F_45 ( void )
{
F_29 () ;
F_43 ( & V_67 ) ;
if ( V_17 != V_32 )
F_28 ( F_14 , ( void * ) false , 1 ) ;
F_46 ( & V_83 ) ;
return;
}
