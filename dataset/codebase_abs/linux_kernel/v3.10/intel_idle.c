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
F_7 ( ( void * ) & F_8 () -> V_11 , 0 , 0 ) ;
F_9 () ;
if ( ! F_6 () )
F_10 ( V_10 , V_6 ) ;
}
if ( ! ( V_17 & ( 1 << ( V_12 ) ) ) )
F_5 ( V_19 , & V_13 ) ;
return V_5 ;
}
static void F_11 ( void * V_20 )
{
unsigned long V_21 = ( unsigned long ) V_20 ;
int V_13 = F_3 () ;
V_21 = V_21 ?
V_22 : V_23 ;
F_5 ( V_21 , & V_13 ) ;
}
static int F_12 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
int V_28 = ( unsigned long ) V_27 ;
struct V_1 * V_2 ;
switch ( V_26 & 0xf ) {
case V_29 :
if ( V_17 != V_30 )
F_13 ( V_28 , F_11 ,
( void * ) true , 1 ) ;
V_2 = F_14 ( V_31 , V_28 ) ;
if ( ! V_2 -> V_32 )
F_15 ( V_28 ) ;
break;
}
return V_33 ;
}
static void F_16 ( void * V_34 )
{
unsigned long long V_35 ;
F_17 ( V_36 , V_35 ) ;
V_35 &= ~ ( V_37 -> V_38 ) ;
F_18 ( V_36 , V_35 ) ;
}
static void F_19 ( void * V_34 )
{
unsigned long long V_35 ;
F_17 ( V_39 , V_35 ) ;
V_35 &= ~ 0x2 ;
F_18 ( V_39 , V_35 ) ;
}
static int F_20 ( void )
{
unsigned int V_10 , V_40 , V_6 ;
const struct V_41 * V_42 ;
if ( V_43 == 0 ) {
F_21 ( V_44 L_1 ) ;
return - V_45 ;
}
V_42 = F_22 ( V_46 ) ;
if ( ! V_42 ) {
if ( V_47 . V_48 == V_49 &&
V_47 . V_50 == 6 )
F_21 ( V_44 L_2 ,
V_47 . V_50 , V_47 . V_51 ) ;
return - V_52 ;
}
if ( V_47 . V_53 < V_54 )
return - V_52 ;
F_23 ( V_54 , & V_10 , & V_40 , & V_6 , & V_55 ) ;
if ( ! ( V_6 & V_56 ) ||
! ( V_6 & V_57 ) ||
! V_55 )
return - V_52 ;
F_21 ( V_44 L_3 , V_55 ) ;
V_37 = ( const struct V_58 * ) V_42 -> V_59 ;
V_60 = V_37 -> V_61 ;
if ( F_24 ( V_62 ) )
V_17 = V_30 ;
else
F_25 ( F_11 , ( void * ) true , 1 ) ;
F_21 ( V_44 L_4 V_63
L_5 , V_47 . V_51 ) ;
F_21 ( V_44 L_6 ,
V_17 ) ;
return 0 ;
}
static void F_26 ( void )
{
int V_64 ;
struct V_1 * V_2 ;
F_27 (i) {
V_2 = F_14 ( V_31 , V_64 ) ;
F_28 ( V_2 ) ;
}
F_29 ( V_31 ) ;
return;
}
static int F_30 ( void )
{
int V_12 ;
struct V_3 * V_4 = & V_65 ;
V_4 -> V_66 = 1 ;
for ( V_12 = 0 ; V_12 < V_67 ; ++ V_12 ) {
int V_68 , V_69 , V_70 , V_71 ;
if ( V_60 [ V_12 ] . V_72 == NULL )
break;
if ( V_12 + 1 > V_43 ) {
F_31 ( V_44 L_7 ,
V_43 ) ;
break;
}
V_69 = F_2 ( V_60 [ V_12 ] . V_11 ) ;
V_70 = F_32 ( V_69 ) ;
V_71 = F_33 ( V_69 ) ;
V_68 = ( V_55 >> ( ( V_70 + 1 ) * 4 ) )
& V_73 ;
if ( ( V_71 + 1 ) > V_68 )
continue;
if ( ( ( V_70 + 1 ) > 2 ) &&
! F_24 ( V_74 ) )
F_34 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_66 ] =
V_60 [ V_12 ] ;
V_4 -> V_66 += 1 ;
}
if ( V_37 -> V_38 )
F_25 ( F_16 , NULL , 1 ) ;
if ( V_37 -> V_75 )
F_25 ( F_19 , NULL , 1 ) ;
return 0 ;
}
static int F_15 ( int V_13 )
{
int V_12 ;
struct V_1 * V_2 ;
V_2 = F_14 ( V_31 , V_13 ) ;
V_2 -> V_66 = 1 ;
for ( V_12 = 0 ; V_12 < V_67 ; ++ V_12 ) {
int V_68 , V_69 , V_70 , V_71 ;
if ( V_60 [ V_12 ] . V_72 == NULL )
continue;
if ( V_12 + 1 > V_43 ) {
F_31 ( V_44 L_7 , V_43 ) ;
break;
}
V_69 = F_2 ( V_60 [ V_12 ] . V_11 ) ;
V_70 = F_32 ( V_69 ) ;
V_71 = F_33 ( V_69 ) ;
V_68 = ( V_55 >> ( ( V_70 + 1 ) * 4 ) )
& V_73 ;
if ( ( V_71 + 1 ) > V_68 )
continue;
V_2 -> V_66 += 1 ;
}
V_2 -> V_13 = V_13 ;
if ( F_35 ( V_2 ) ) {
F_21 ( V_44 L_10 , V_13 ) ;
F_26 () ;
return - V_76 ;
}
if ( V_37 -> V_38 )
F_13 ( V_13 , F_16 , NULL , 1 ) ;
return 0 ;
}
static int T_1 F_36 ( void )
{
int V_77 , V_64 ;
if ( V_78 != V_79 )
return - V_52 ;
V_77 = F_20 () ;
if ( V_77 )
return V_77 ;
F_30 () ;
V_77 = F_37 ( & V_65 ) ;
if ( V_77 ) {
struct V_3 * V_4 = F_38 () ;
F_31 (KERN_DEBUG PREFIX L_11 ,
drv ? drv->name : L_12 ) ;
return V_77 ;
}
V_31 = F_39 ( struct V_1 ) ;
if ( V_31 == NULL )
return - V_80 ;
F_27 (i) {
V_77 = F_15 ( V_64 ) ;
if ( V_77 ) {
F_40 ( & V_65 ) ;
return V_77 ;
}
}
F_41 ( & V_81 ) ;
return 0 ;
}
static void T_2 F_42 ( void )
{
F_26 () ;
F_40 ( & V_65 ) ;
if ( V_17 != V_30 )
F_25 ( F_11 , ( void * ) false , 1 ) ;
F_43 ( & V_81 ) ;
return;
}
