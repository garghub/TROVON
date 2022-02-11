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
F_6 () ;
if ( ! F_7 () ) {
F_8 ( ( void * ) & F_9 () -> V_11 , 0 , 0 ) ;
F_10 () ;
if ( ! F_7 () )
F_11 ( V_10 , V_6 ) ;
}
F_12 () ;
if ( ! ( V_17 & ( 1 << ( V_12 ) ) ) )
F_5 ( V_19 , & V_13 ) ;
return V_5 ;
}
static void F_13 ( void * V_20 )
{
unsigned long V_21 = ( unsigned long ) V_20 ;
int V_13 = F_3 () ;
V_21 = V_21 ?
V_22 : V_23 ;
F_5 ( V_21 , & V_13 ) ;
}
static int F_14 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
int V_28 = ( unsigned long ) V_27 ;
struct V_1 * V_2 ;
switch ( V_26 & 0xf ) {
case V_29 :
if ( V_17 != V_30 )
F_15 ( V_28 , F_13 ,
( void * ) true , 1 ) ;
V_2 = F_16 ( V_31 , V_28 ) ;
if ( ! V_2 -> V_32 )
F_17 ( V_28 ) ;
break;
}
return V_33 ;
}
static void F_18 ( void * V_34 )
{
unsigned long long V_35 ;
F_19 ( V_36 , V_35 ) ;
V_35 &= ~ ( V_37 -> V_38 ) ;
F_20 ( V_36 , V_35 ) ;
}
static void F_21 ( void * V_34 )
{
unsigned long long V_35 ;
F_19 ( V_39 , V_35 ) ;
V_35 &= ~ 0x2 ;
F_20 ( V_39 , V_35 ) ;
}
static int F_22 ( void )
{
unsigned int V_10 , V_40 , V_6 ;
const struct V_41 * V_42 ;
if ( V_43 == 0 ) {
F_23 ( V_44 L_1 ) ;
return - V_45 ;
}
V_42 = F_24 ( V_46 ) ;
if ( ! V_42 ) {
if ( V_47 . V_48 == V_49 &&
V_47 . V_50 == 6 )
F_23 ( V_44 L_2 ,
V_47 . V_50 , V_47 . V_51 ) ;
return - V_52 ;
}
if ( V_47 . V_53 < V_54 )
return - V_52 ;
F_25 ( V_54 , & V_10 , & V_40 , & V_6 , & V_55 ) ;
if ( ! ( V_6 & V_56 ) ||
! ( V_6 & V_57 ) ||
! V_55 )
return - V_52 ;
F_23 ( V_44 L_3 , V_55 ) ;
V_37 = ( const struct V_58 * ) V_42 -> V_59 ;
V_60 = V_37 -> V_61 ;
if ( F_26 ( V_62 ) )
V_17 = V_30 ;
else
F_27 ( F_13 , ( void * ) true , 1 ) ;
F_23 ( V_44 L_4 V_63
L_5 , V_47 . V_51 ) ;
F_23 ( V_44 L_6 ,
V_17 ) ;
return 0 ;
}
static void F_28 ( void )
{
int V_64 ;
struct V_1 * V_2 ;
F_29 (i) {
V_2 = F_16 ( V_31 , V_64 ) ;
F_30 ( V_2 ) ;
}
F_31 ( V_31 ) ;
return;
}
static int F_32 ( void )
{
int V_12 ;
struct V_3 * V_4 = & V_65 ;
V_4 -> V_66 = 1 ;
for ( V_12 = 0 ; V_12 < V_67 ; ++ V_12 ) {
int V_68 , V_69 , V_70 , V_71 ;
if ( V_60 [ V_12 ] . V_72 == NULL )
break;
if ( V_12 + 1 > V_43 ) {
F_33 ( V_44 L_7 ,
V_43 ) ;
break;
}
V_69 = F_2 ( V_60 [ V_12 ] . V_11 ) ;
V_70 = F_34 ( V_69 ) ;
V_71 = F_35 ( V_69 ) ;
V_68 = ( V_55 >> ( ( V_70 + 1 ) * 4 ) )
& V_73 ;
if ( ( V_71 + 1 ) > V_68 )
continue;
if ( ( ( V_70 + 1 ) > 2 ) &&
! F_26 ( V_74 ) )
F_36 ( L_8
L_9 ) ;
V_4 -> V_9 [ V_4 -> V_66 ] =
V_60 [ V_12 ] ;
V_4 -> V_66 += 1 ;
}
if ( V_37 -> V_38 )
F_27 ( F_18 , NULL , 1 ) ;
if ( V_37 -> V_75 )
F_27 ( F_21 , NULL , 1 ) ;
return 0 ;
}
static int F_17 ( int V_13 )
{
int V_12 ;
struct V_1 * V_2 ;
V_2 = F_16 ( V_31 , V_13 ) ;
V_2 -> V_66 = 1 ;
for ( V_12 = 0 ; V_12 < V_67 ; ++ V_12 ) {
int V_68 , V_69 , V_70 , V_71 ;
if ( V_60 [ V_12 ] . V_72 == NULL )
continue;
if ( V_12 + 1 > V_43 ) {
F_33 ( V_44 L_7 , V_43 ) ;
break;
}
V_69 = F_2 ( V_60 [ V_12 ] . V_11 ) ;
V_70 = F_34 ( V_69 ) ;
V_71 = F_35 ( V_69 ) ;
V_68 = ( V_55 >> ( ( V_70 + 1 ) * 4 ) )
& V_73 ;
if ( ( V_71 + 1 ) > V_68 )
continue;
V_2 -> V_66 += 1 ;
}
V_2 -> V_13 = V_13 ;
if ( F_37 ( V_2 ) ) {
F_23 ( V_44 L_10 , V_13 ) ;
F_28 () ;
return - V_76 ;
}
if ( V_37 -> V_38 )
F_15 ( V_13 , F_18 , NULL , 1 ) ;
return 0 ;
}
static int T_1 F_38 ( void )
{
int V_77 , V_64 ;
if ( V_78 != V_79 )
return - V_52 ;
V_77 = F_22 () ;
if ( V_77 )
return V_77 ;
F_32 () ;
V_77 = F_39 ( & V_65 ) ;
if ( V_77 ) {
struct V_3 * V_4 = F_40 () ;
F_33 (KERN_DEBUG PREFIX L_11 ,
drv ? drv->name : L_12 ) ;
return V_77 ;
}
V_31 = F_41 ( struct V_1 ) ;
if ( V_31 == NULL )
return - V_80 ;
F_29 (i) {
V_77 = F_17 ( V_64 ) ;
if ( V_77 ) {
F_42 ( & V_65 ) ;
return V_77 ;
}
}
F_43 ( & V_81 ) ;
return 0 ;
}
static void T_2 F_44 ( void )
{
F_28 () ;
F_42 ( & V_65 ) ;
if ( V_17 != V_30 )
F_27 ( F_13 , ( void * ) false , 1 ) ;
F_45 ( & V_81 ) ;
return;
}
