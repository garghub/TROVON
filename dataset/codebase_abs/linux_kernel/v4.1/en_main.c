void F_1 ( const char * V_1 , const struct V_2 * V_3 ,
const char * V_4 , ... )
{
T_1 args ;
struct V_5 V_6 ;
va_start ( args , V_4 ) ;
V_6 . V_7 = V_4 ;
V_6 . V_8 = & args ;
if ( V_3 -> V_9 )
F_2 ( L_1 ,
V_1 , V_10 , V_3 -> V_11 -> V_12 , & V_6 ) ;
else
F_2 ( L_2 ,
V_1 , V_10 , F_3 ( & V_3 -> V_13 -> V_14 -> V_11 ) ,
V_3 -> V_15 , & V_6 ) ;
va_end ( args ) ;
}
void F_4 ( struct V_16 * V_11 ,
T_2 V_17 )
{
struct V_2 * V_3 = F_5 ( V_11 ) ;
if ( V_17 & V_18 )
V_3 -> V_19 |= F_6 ( V_20 ) ;
else
V_3 -> V_19 &= F_6 ( ~ V_20 ) ;
V_3 -> V_21 &= ~ ( V_22 |
V_23 ) ;
if ( F_7 ( V_3 -> V_13 -> V_11 ) &&
! ( V_17 & V_18 ) && ! V_3 -> V_24 )
V_3 -> V_21 |= V_22 ;
if ( F_7 ( V_3 -> V_13 -> V_11 ) || V_3 -> V_24 )
V_3 -> V_21 |= V_23 ;
}
static int F_8 ( struct V_25 * V_13 )
{
struct V_26 * V_27 = & V_13 -> V_28 ;
int V_29 ;
V_27 -> V_30 = V_30 ;
V_27 -> V_31 = F_9 () ?
V_32 :
F_10 ( int , F_11 () , V_33 ) ;
if ( V_27 -> V_30 && ! ( V_13 -> V_11 -> V_34 . V_21
& V_35 ) ) {
F_12 ( V_13 , L_3 ) ;
V_27 -> V_30 = 0 ;
}
for ( V_29 = 1 ; V_29 <= V_36 ; V_29 ++ ) {
V_27 -> V_37 [ V_29 ] . V_38 = 1 ;
V_27 -> V_37 [ V_29 ] . V_39 = V_40 ;
V_27 -> V_37 [ V_29 ] . V_41 = 1 ;
V_27 -> V_37 [ V_29 ] . V_42 = V_43 ;
V_27 -> V_37 [ V_29 ] . V_44 = V_45 ;
V_27 -> V_37 [ V_29 ] . V_46 = V_47 ;
V_27 -> V_37 [ V_29 ] . V_48 = V_27 -> V_31 *
V_49 ;
V_27 -> V_37 [ V_29 ] . V_50 = 0 ;
V_27 -> V_37 [ V_29 ] . V_51 = V_51 ;
}
return 0 ;
}
static void * F_13 ( struct V_52 * V_11 , void * V_53 , T_3 V_15 )
{
struct V_25 * V_54 = V_53 ;
return V_54 -> V_55 [ V_15 ] ;
}
static void F_14 ( struct V_52 * V_11 , void * V_56 ,
enum V_57 V_58 , unsigned long V_15 )
{
struct V_25 * V_13 = (struct V_25 * ) V_56 ;
struct V_2 * V_3 ;
switch ( V_58 ) {
case V_59 :
case V_60 :
if ( ! V_13 -> V_55 [ V_15 ] )
return;
V_3 = F_5 ( V_13 -> V_55 [ V_15 ] ) ;
V_3 -> V_61 = V_58 ;
F_15 ( V_13 -> V_62 , & V_3 -> V_63 ) ;
break;
case V_64 :
F_16 ( V_13 , L_4 ) ;
break;
case V_65 :
case V_66 :
break;
default:
if ( V_15 < 1 || V_15 > V_11 -> V_34 . V_67 ||
! V_13 -> V_55 [ V_15 ] )
return;
F_12 ( V_13 , L_5 , V_58 ,
( int ) V_15 ) ;
}
}
static void F_17 ( struct V_52 * V_11 , void * V_56 )
{
struct V_25 * V_13 = V_56 ;
int V_29 ;
F_18 ( & V_13 -> V_68 ) ;
V_13 -> V_69 = false ;
F_19 ( & V_13 -> V_68 ) ;
F_20 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_13 -> V_55 [ V_29 ] )
F_21 ( V_13 -> V_55 [ V_29 ] ) ;
if ( V_13 -> V_11 -> V_34 . V_70 & V_71 )
F_22 ( V_13 ) ;
F_23 ( V_13 -> V_62 ) ;
F_24 ( V_13 -> V_62 ) ;
( void ) F_25 ( V_11 , & V_13 -> V_72 ) ;
F_26 ( V_13 -> V_73 ) ;
F_27 ( V_11 , & V_13 -> V_74 ) ;
F_28 ( V_11 , V_13 -> V_75 ) ;
if ( V_13 -> V_76 . V_77 )
F_29 ( & V_13 -> V_76 ) ;
F_30 ( V_13 ) ;
}
static void * F_31 ( struct V_52 * V_11 )
{
struct V_25 * V_13 ;
int V_29 ;
F_32 ( V_78 L_6 , V_79 ) ;
V_13 = F_33 ( sizeof( * V_13 ) , V_80 ) ;
if ( ! V_13 )
goto V_81;
if ( F_34 ( V_11 , & V_13 -> V_75 ) )
goto V_82;
if ( F_35 ( V_11 , & V_13 -> V_74 ) )
goto V_83;
V_13 -> V_73 = F_36 ( ( V_84 ) V_13 -> V_74 . V_85 << V_86 ,
V_87 ) ;
if ( ! V_13 -> V_73 )
goto V_88;
F_37 ( & V_13 -> V_89 ) ;
V_13 -> V_11 = V_11 ;
V_13 -> V_90 = & V_11 -> V_91 -> V_14 -> V_11 ;
V_13 -> V_14 = V_11 -> V_91 -> V_14 ;
V_13 -> V_69 = false ;
V_13 -> V_92 = ! ! ( V_11 -> V_34 . V_21 & ( 1 << 15 ) ) ;
if ( ! V_13 -> V_92 )
F_12 ( V_13 , L_7 ) ;
if ( F_38 ( V_13 -> V_11 , V_13 -> V_75 , 0 , ~ 0ull ,
V_93 | V_94 ,
0 , 0 , & V_13 -> V_72 ) ) {
F_16 ( V_13 , L_8 ) ;
goto V_95;
}
if ( F_39 ( V_13 -> V_11 , & V_13 -> V_72 ) ) {
F_16 ( V_13 , L_9 ) ;
goto V_96;
}
if ( F_8 ( V_13 ) ) {
F_16 ( V_13 , L_10 ) ;
goto V_96;
}
V_13 -> V_97 = 0 ;
F_20 (i, dev, MLX4_PORT_TYPE_ETH)
V_13 -> V_97 ++ ;
if ( V_13 -> V_11 -> V_34 . V_70 & V_71 )
F_40 ( V_13 ) ;
F_41 ( V_13 ) ;
V_13 -> V_62 = F_42 ( L_11 ) ;
if ( ! V_13 -> V_62 )
goto V_96;
F_43 ( & V_13 -> V_68 ) ;
V_13 -> V_69 = true ;
F_20 (i, dev, MLX4_PORT_TYPE_ETH) {
F_44 ( V_13 , L_12 , V_29 ) ;
if ( F_45 ( V_13 , V_29 , & V_13 -> V_28 . V_37 [ V_29 ] ) )
V_13 -> V_55 [ V_29 ] = NULL ;
}
V_13 -> V_76 . V_77 = V_98 ;
if ( F_46 ( & V_13 -> V_76 ) ) {
V_13 -> V_76 . V_77 = NULL ;
F_16 ( V_13 , L_13 ) ;
}
return V_13 ;
V_96:
( void ) F_25 ( V_11 , & V_13 -> V_72 ) ;
V_95:
if ( V_13 -> V_73 )
F_26 ( V_13 -> V_73 ) ;
V_88:
F_27 ( V_11 , & V_13 -> V_74 ) ;
V_83:
F_28 ( V_11 , V_13 -> V_75 ) ;
V_82:
F_30 ( V_13 ) ;
V_81:
return NULL ;
}
static void F_47 ( void )
{
if ( V_43 > V_99 ) {
F_48 ( L_14 ,
V_43 , V_99 ) ;
V_43 = 0 ;
}
if ( V_40 > V_100 ) {
F_48 ( L_15 ,
V_40 , V_100 ) ;
V_40 = 0 ;
}
if ( V_51 < V_101 || V_51 > V_102 ) {
F_48 ( L_16 ,
V_51 , V_101 , V_102 , V_102 ) ;
V_51 = V_102 ;
}
}
static int T_4 F_49 ( void )
{
F_47 () ;
return F_50 ( & V_103 ) ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_103 ) ;
}
