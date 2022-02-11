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
V_3 -> V_18 &= ~ ( V_19 |
V_20 ) ;
if ( F_6 ( V_3 -> V_13 -> V_11 ) &&
! ( V_17 & V_21 ) && ! V_3 -> V_22 )
V_3 -> V_18 |= V_19 ;
if ( F_6 ( V_3 -> V_13 -> V_11 ) || V_3 -> V_22 )
V_3 -> V_18 |= V_20 ;
}
static int F_7 ( struct V_23 * V_13 )
{
struct V_24 * V_25 = & V_13 -> V_26 ;
int V_27 ;
V_25 -> V_28 = V_28 ;
V_25 -> V_29 = F_8 () ?
V_30 :
F_9 ( int , F_10 () , V_31 ) ;
if ( V_25 -> V_28 && ! ( V_13 -> V_11 -> V_32 . V_18
& V_33 ) ) {
F_11 ( V_13 , L_3 ) ;
V_25 -> V_28 = 0 ;
}
for ( V_27 = 1 ; V_27 <= V_34 ; V_27 ++ ) {
V_25 -> V_35 [ V_27 ] . V_36 = 1 ;
V_25 -> V_35 [ V_27 ] . V_37 = V_38 ;
V_25 -> V_35 [ V_27 ] . V_39 = 1 ;
V_25 -> V_35 [ V_27 ] . V_40 = V_41 ;
V_25 -> V_35 [ V_27 ] . V_42 = V_43 ;
V_25 -> V_35 [ V_27 ] . V_44 = V_45 ;
V_25 -> V_35 [ V_27 ] . V_46 = V_25 -> V_29 *
V_47 ;
V_25 -> V_35 [ V_27 ] . V_48 = 0 ;
V_25 -> V_35 [ V_27 ] . V_49 = V_49 ;
}
return 0 ;
}
static void * F_12 ( struct V_50 * V_11 , void * V_51 , T_3 V_15 )
{
struct V_23 * V_52 = V_51 ;
return V_52 -> V_53 [ V_15 ] ;
}
static void F_13 ( struct V_50 * V_11 , void * V_54 ,
enum V_55 V_56 , unsigned long V_15 )
{
struct V_23 * V_13 = (struct V_23 * ) V_54 ;
struct V_2 * V_3 ;
switch ( V_56 ) {
case V_57 :
case V_58 :
if ( ! V_13 -> V_53 [ V_15 ] )
return;
V_3 = F_5 ( V_13 -> V_53 [ V_15 ] ) ;
V_3 -> V_59 = V_56 ;
F_14 ( V_13 -> V_60 , & V_3 -> V_61 ) ;
break;
case V_62 :
F_15 ( V_13 , L_4 ) ;
break;
case V_63 :
case V_64 :
break;
default:
if ( V_15 < 1 || V_15 > V_11 -> V_32 . V_65 ||
! V_13 -> V_53 [ V_15 ] )
return;
F_11 ( V_13 , L_5 , V_56 ,
( int ) V_15 ) ;
}
}
static void F_16 ( struct V_50 * V_11 , void * V_54 )
{
struct V_23 * V_13 = V_54 ;
int V_27 ;
F_17 ( & V_13 -> V_66 ) ;
V_13 -> V_67 = false ;
F_18 ( & V_13 -> V_66 ) ;
F_19 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_13 -> V_53 [ V_27 ] )
F_20 ( V_13 -> V_53 [ V_27 ] ) ;
if ( V_13 -> V_11 -> V_32 . V_68 & V_69 )
F_21 ( V_13 ) ;
F_22 ( V_13 -> V_60 ) ;
F_23 ( V_13 -> V_60 ) ;
( void ) F_24 ( V_11 , & V_13 -> V_70 ) ;
F_25 ( V_13 -> V_71 ) ;
F_26 ( V_11 , & V_13 -> V_72 ) ;
F_27 ( V_11 , V_13 -> V_73 ) ;
if ( V_13 -> V_74 . V_75 )
F_28 ( & V_13 -> V_74 ) ;
F_29 ( V_13 ) ;
}
static void * F_30 ( struct V_50 * V_11 )
{
struct V_23 * V_13 ;
int V_27 ;
F_31 ( V_76 L_6 , V_77 ) ;
V_13 = F_32 ( sizeof( * V_13 ) , V_78 ) ;
if ( ! V_13 )
goto V_79;
if ( F_33 ( V_11 , & V_13 -> V_73 ) )
goto V_80;
if ( F_34 ( V_11 , & V_13 -> V_72 ) )
goto V_81;
V_13 -> V_71 = F_35 ( ( V_82 ) V_13 -> V_72 . V_83 << V_84 ,
V_85 ) ;
if ( ! V_13 -> V_71 )
goto V_86;
F_36 ( & V_13 -> V_87 ) ;
V_13 -> V_11 = V_11 ;
V_13 -> V_88 = & V_11 -> V_89 -> V_14 -> V_11 ;
V_13 -> V_14 = V_11 -> V_89 -> V_14 ;
V_13 -> V_67 = false ;
V_13 -> V_90 = ! ! ( V_11 -> V_32 . V_18 & ( 1 << 15 ) ) ;
if ( ! V_13 -> V_90 )
F_11 ( V_13 , L_7 ) ;
if ( F_37 ( V_13 -> V_11 , V_13 -> V_73 , 0 , ~ 0ull ,
V_91 | V_92 ,
0 , 0 , & V_13 -> V_70 ) ) {
F_15 ( V_13 , L_8 ) ;
goto V_93;
}
if ( F_38 ( V_13 -> V_11 , & V_13 -> V_70 ) ) {
F_15 ( V_13 , L_9 ) ;
goto V_94;
}
if ( F_7 ( V_13 ) ) {
F_15 ( V_13 , L_10 ) ;
goto V_94;
}
V_13 -> V_95 = 0 ;
F_19 (i, dev, MLX4_PORT_TYPE_ETH)
V_13 -> V_95 ++ ;
if ( V_13 -> V_11 -> V_32 . V_68 & V_69 )
F_39 ( V_13 ) ;
F_40 ( V_13 ) ;
V_13 -> V_60 = F_41 ( L_11 ) ;
if ( ! V_13 -> V_60 )
goto V_94;
F_42 ( & V_13 -> V_66 ) ;
V_13 -> V_67 = true ;
F_19 (i, dev, MLX4_PORT_TYPE_ETH) {
F_43 ( V_13 , L_12 , V_27 ) ;
if ( F_44 ( V_13 , V_27 , & V_13 -> V_26 . V_35 [ V_27 ] ) )
V_13 -> V_53 [ V_27 ] = NULL ;
}
V_13 -> V_74 . V_75 = V_96 ;
if ( F_45 ( & V_13 -> V_74 ) ) {
V_13 -> V_74 . V_75 = NULL ;
F_15 ( V_13 , L_13 ) ;
}
return V_13 ;
V_94:
( void ) F_24 ( V_11 , & V_13 -> V_70 ) ;
V_93:
if ( V_13 -> V_71 )
F_25 ( V_13 -> V_71 ) ;
V_86:
F_26 ( V_11 , & V_13 -> V_72 ) ;
V_81:
F_27 ( V_11 , V_13 -> V_73 ) ;
V_80:
F_29 ( V_13 ) ;
V_79:
return NULL ;
}
static void F_46 ( void )
{
if ( V_41 > V_97 ) {
F_47 ( L_14 ,
V_41 , V_97 ) ;
V_41 = 0 ;
}
if ( V_38 > V_98 ) {
F_47 ( L_15 ,
V_38 , V_98 ) ;
V_38 = 0 ;
}
if ( V_49 < V_99 || V_49 > V_100 ) {
F_47 ( L_16 ,
V_49 , V_99 , V_100 , V_100 ) ;
V_49 = V_100 ;
}
}
static int T_4 F_48 ( void )
{
F_46 () ;
return F_49 ( & V_101 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_101 ) ;
}
