static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 = 1 ;
unsigned long V_6 = ( unsigned long ) F_2 ( V_4 ) ;
unsigned int V_7 ;
T_1 V_8 , V_9 ;
T_2 V_10 ;
int V_11 = F_3 () ;
V_7 = ( ( ( V_6 ) >> V_12 ) & V_13 ) + 1 ;
F_4 () ;
if ( V_4 -> V_14 & V_15 )
F_5 ( V_11 ) ;
if ( ! ( V_16 & ( 1 << ( V_7 ) ) ) )
F_6 ( V_17 , & V_11 ) ;
V_8 = F_7 () ;
F_8 () ;
if ( ! F_9 () ) {
F_10 ( ( void * ) & F_11 () -> V_14 , 0 , 0 ) ;
F_12 () ;
if ( ! F_9 () )
F_13 ( V_6 , V_5 ) ;
}
F_14 () ;
V_9 = F_7 () ;
V_10 = F_15 ( F_16 ( V_9 , V_8 ) ) ;
F_17 () ;
if ( ! ( V_16 & ( 1 << ( V_7 ) ) ) )
F_6 ( V_18 , & V_11 ) ;
return V_10 ;
}
static void F_18 ( void * V_19 )
{
unsigned long V_20 = ( unsigned long ) V_19 ;
int V_11 = F_3 () ;
V_20 = V_20 ?
V_21 : V_22 ;
F_6 ( V_20 , & V_11 ) ;
}
static int F_19 ( struct V_23 * V_24 ,
unsigned long V_25 , void * V_26 )
{
int V_27 = ( unsigned long ) V_26 ;
switch ( V_25 & 0xf ) {
case V_28 :
F_20 ( V_27 , F_18 ,
( void * ) true , 1 ) ;
break;
}
return V_29 ;
}
static void F_21 ( void * V_30 )
{
unsigned long long V_31 ;
F_22 ( V_32 , V_31 ) ;
V_31 &= ~ V_33 ;
F_23 ( V_32 , V_31 ) ;
}
static int F_24 ( void )
{
unsigned int V_6 , V_34 , V_5 ;
if ( V_35 == 0 ) {
F_25 ( V_36 L_1 ) ;
return - V_37 ;
}
if ( V_38 . V_39 != V_40 )
return - V_41 ;
if ( ! F_26 ( V_42 ) )
return - V_41 ;
if ( V_38 . V_43 < V_44 )
return - V_41 ;
F_27 ( V_44 , & V_6 , & V_34 , & V_5 , & V_45 ) ;
if ( ! ( V_5 & V_46 ) ||
! ( V_5 & V_47 ) )
return - V_41 ;
F_25 ( V_36 L_2 , V_45 ) ;
if ( V_38 . V_48 != 6 )
return - V_41 ;
switch ( V_38 . V_49 ) {
case 0x1A :
case 0x1E :
case 0x1F :
case 0x2E :
case 0x2F :
case 0x25 :
case 0x2C :
V_50 = V_51 ;
V_33 =
( V_52 | V_53 ) ;
break;
case 0x1C :
V_50 = V_54 ;
break;
case 0x26 :
V_50 = V_54 ;
V_33 = V_55 ;
break;
case 0x2A :
case 0x2D :
V_50 = V_56 ;
break;
default:
F_25 ( V_36 L_3 ,
V_38 . V_48 , V_38 . V_49 ) ;
return - V_41 ;
}
if ( F_26 ( V_57 ) )
V_16 = V_58 ;
else {
F_28 ( F_18 , ( void * ) true , 1 ) ;
F_29 ( & V_59 ) ;
}
F_25 ( V_36 L_4 V_60
L_5 , V_38 . V_49 ) ;
F_25 ( V_36 L_6 ,
V_16 ) ;
return 0 ;
}
static void F_30 ( void )
{
int V_61 ;
struct V_1 * V_2 ;
F_31 (i) {
V_2 = F_32 ( V_62 , V_61 ) ;
F_33 ( V_2 ) ;
}
F_34 ( V_62 ) ;
return;
}
static int F_35 ( void )
{
int V_61 , V_7 ;
struct V_1 * V_2 ;
V_62 = F_36 ( struct V_1 ) ;
if ( V_62 == NULL )
return - V_63 ;
F_31 (i) {
V_2 = F_32 ( V_62 , V_61 ) ;
V_2 -> V_64 = 1 ;
for ( V_7 = 1 ; V_7 < V_65 ; ++ V_7 ) {
int V_66 ;
if ( V_7 > V_35 ) {
F_37 ( V_36 L_7 ,
V_35 ) ;
break;
}
V_66 = ( V_45 >> ( ( V_7 ) * 4 ) )
& V_67 ;
if ( V_66 == 0 )
continue;
if ( V_50 [ V_7 ] . V_68 == NULL ) {
if ( * V_50 [ V_7 ] . V_69 == '\0' )
F_25 ( V_36 L_8
L_9
L_10 ,
V_38 . V_49 , V_7 ) ;
continue;
}
if ( ( V_7 > 2 ) &&
! F_26 ( V_70 ) )
F_38 ( L_11
L_12 ) ;
V_2 -> V_71 [ V_2 -> V_64 ] =
V_50 [ V_7 ] ;
V_2 -> V_64 += 1 ;
}
V_2 -> V_11 = V_61 ;
if ( F_39 ( V_2 ) ) {
F_25 ( V_36 L_13 ,
V_61 ) ;
F_30 () ;
return - V_72 ;
}
}
if ( V_33 )
F_28 ( F_21 , NULL , 1 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
int V_73 ;
if ( V_74 != V_75 )
return - V_41 ;
V_73 = F_24 () ;
if ( V_73 )
return V_73 ;
V_73 = F_41 ( & V_76 ) ;
if ( V_73 ) {
F_37 (KERN_DEBUG PREFIX L_14 ,
cpuidle_get_driver()->name) ;
return V_73 ;
}
V_73 = F_35 () ;
if ( V_73 ) {
F_42 ( & V_76 ) ;
return V_73 ;
}
return 0 ;
}
static void T_4 F_43 ( void )
{
F_30 () ;
F_42 ( & V_76 ) ;
if ( V_16 != V_58 ) {
F_28 ( F_18 , ( void * ) false , 1 ) ;
F_44 ( & V_59 ) ;
}
return;
}
