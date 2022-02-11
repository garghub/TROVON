int F_1 ( const char * V_1 , const struct V_2 * V_3 ,
const char * V_4 , ... )
{
T_1 args ;
struct V_5 V_6 ;
int V_7 ;
va_start ( args , V_4 ) ;
V_6 . V_8 = V_4 ;
V_6 . V_9 = & args ;
if ( V_3 -> V_10 )
V_7 = F_2 ( L_1 ,
V_1 , V_11 , V_3 -> V_12 -> V_13 , & V_6 ) ;
else
V_7 = F_2 ( L_2 ,
V_1 , V_11 , F_3 ( & V_3 -> V_14 -> V_15 -> V_12 ) ,
V_3 -> V_16 , & V_6 ) ;
va_end ( args ) ;
return V_7 ;
}
void F_4 ( struct V_17 * V_12 ,
T_2 V_18 )
{
struct V_2 * V_3 = F_5 ( V_12 ) ;
V_3 -> V_19 &= ~ ( V_20 |
V_21 ) ;
if ( F_6 ( V_3 -> V_14 -> V_12 ) &&
! ( V_18 & V_22 ) && ! V_3 -> V_23 )
V_3 -> V_19 |= V_20 ;
if ( F_6 ( V_3 -> V_14 -> V_12 ) || V_3 -> V_23 )
V_3 -> V_19 |= V_21 ;
}
static int F_7 ( struct V_24 * V_14 )
{
struct V_25 * V_26 = & V_14 -> V_27 ;
int V_7 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_29 = F_8 () ?
V_30 :
F_9 ( int , F_10 () , V_31 ) ;
if ( V_26 -> V_28 && ! ( V_14 -> V_12 -> V_32 . V_19
& V_33 ) ) {
F_11 ( V_14 , L_3 ) ;
V_26 -> V_28 = 0 ;
}
for ( V_7 = 1 ; V_7 <= V_34 ; V_7 ++ ) {
V_26 -> V_35 [ V_7 ] . V_36 = 1 ;
V_26 -> V_35 [ V_7 ] . V_37 = V_38 ;
V_26 -> V_35 [ V_7 ] . V_39 = 1 ;
V_26 -> V_35 [ V_7 ] . V_40 = V_41 ;
V_26 -> V_35 [ V_7 ] . V_42 = V_43 ;
V_26 -> V_35 [ V_7 ] . V_44 = V_45 ;
V_26 -> V_35 [ V_7 ] . V_46 = V_26 -> V_29 *
V_47 ;
V_26 -> V_35 [ V_7 ] . V_48 = 0 ;
V_26 -> V_35 [ V_7 ] . V_49 = V_49 ;
}
return 0 ;
}
static void * F_12 ( struct V_50 * V_12 , void * V_51 , T_3 V_16 )
{
struct V_24 * V_52 = V_51 ;
return V_52 -> V_53 [ V_16 ] ;
}
static void F_13 ( struct V_50 * V_12 , void * V_54 ,
enum V_55 V_56 , unsigned long V_16 )
{
struct V_24 * V_14 = (struct V_24 * ) V_54 ;
struct V_2 * V_3 ;
switch ( V_56 ) {
case V_57 :
case V_58 :
if ( ! V_14 -> V_53 [ V_16 ] )
return;
V_3 = F_5 ( V_14 -> V_53 [ V_16 ] ) ;
V_3 -> V_59 = V_56 ;
F_14 ( V_14 -> V_60 , & V_3 -> V_61 ) ;
break;
case V_62 :
F_15 ( V_14 , L_4 ) ;
break;
case V_63 :
case V_64 :
break;
default:
if ( V_16 < 1 || V_16 > V_12 -> V_32 . V_65 ||
! V_14 -> V_53 [ V_16 ] )
return;
F_11 ( V_14 , L_5 , V_56 ,
( int ) V_16 ) ;
}
}
static void F_16 ( struct V_50 * V_12 , void * V_54 )
{
struct V_24 * V_14 = V_54 ;
int V_7 ;
F_17 ( & V_14 -> V_66 ) ;
V_14 -> V_67 = false ;
F_18 ( & V_14 -> V_66 ) ;
F_19 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_14 -> V_53 [ V_7 ] )
F_20 ( V_14 -> V_53 [ V_7 ] ) ;
if ( V_14 -> V_12 -> V_32 . V_68 & V_69 )
F_21 ( V_14 ) ;
F_22 ( V_14 -> V_60 ) ;
F_23 ( V_14 -> V_60 ) ;
( void ) F_24 ( V_12 , & V_14 -> V_70 ) ;
F_25 ( V_14 -> V_71 ) ;
F_26 ( V_12 , & V_14 -> V_72 ) ;
F_27 ( V_12 , V_14 -> V_73 ) ;
F_28 ( V_14 ) ;
}
static void * F_29 ( struct V_50 * V_12 )
{
struct V_24 * V_14 ;
int V_7 ;
int V_74 ;
F_30 ( V_75 L_6 , V_76 ) ;
V_14 = F_31 ( sizeof( * V_14 ) , V_77 ) ;
if ( ! V_14 ) {
V_74 = - V_78 ;
goto V_79;
}
if ( F_32 ( V_12 , & V_14 -> V_73 ) )
goto V_80;
if ( F_33 ( V_12 , & V_14 -> V_72 ) )
goto V_81;
V_14 -> V_71 = F_34 ( ( V_82 ) V_14 -> V_72 . V_83 << V_84 ,
V_85 ) ;
if ( ! V_14 -> V_71 )
goto V_86;
F_35 ( & V_14 -> V_87 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_88 = & ( V_12 -> V_15 -> V_12 ) ;
V_14 -> V_15 = V_12 -> V_15 ;
V_14 -> V_67 = false ;
V_14 -> V_89 = ! ! ( V_12 -> V_32 . V_19 & ( 1 << 15 ) ) ;
if ( ! V_14 -> V_89 )
F_11 ( V_14 , L_7 ) ;
if ( F_36 ( V_14 -> V_12 , V_14 -> V_73 , 0 , ~ 0ull ,
V_90 | V_91 ,
0 , 0 , & V_14 -> V_70 ) ) {
F_15 ( V_14 , L_8 ) ;
goto V_92;
}
if ( F_37 ( V_14 -> V_12 , & V_14 -> V_70 ) ) {
F_15 ( V_14 , L_9 ) ;
goto V_93;
}
V_74 = F_7 ( V_14 ) ;
if ( V_74 ) {
F_15 ( V_14 , L_10 ) ;
goto V_93;
}
V_14 -> V_94 = 0 ;
F_19 (i, dev, MLX4_PORT_TYPE_ETH)
V_14 -> V_94 ++ ;
if ( V_14 -> V_12 -> V_32 . V_68 & V_69 )
F_38 ( V_14 ) ;
F_39 ( V_14 ) ;
V_14 -> V_60 = F_40 ( L_11 ) ;
if ( ! V_14 -> V_60 ) {
V_74 = - V_78 ;
goto V_93;
}
F_41 ( & V_14 -> V_66 ) ;
V_14 -> V_67 = true ;
F_19 (i, dev, MLX4_PORT_TYPE_ETH) {
F_42 ( V_14 , L_12 , V_7 ) ;
if ( F_43 ( V_14 , V_7 , & V_14 -> V_27 . V_35 [ V_7 ] ) )
V_14 -> V_53 [ V_7 ] = NULL ;
}
return V_14 ;
V_93:
( void ) F_24 ( V_12 , & V_14 -> V_70 ) ;
V_92:
if ( V_14 -> V_71 )
F_25 ( V_14 -> V_71 ) ;
V_86:
F_26 ( V_12 , & V_14 -> V_72 ) ;
V_81:
F_27 ( V_12 , V_14 -> V_73 ) ;
V_80:
F_28 ( V_14 ) ;
V_79:
return NULL ;
}
static void F_44 ( void )
{
if ( V_41 > V_95 ) {
F_45 ( L_13 ,
V_41 , V_95 ) ;
V_41 = 0 ;
}
if ( V_38 > V_96 ) {
F_45 ( L_14 ,
V_38 , V_96 ) ;
V_38 = 0 ;
}
if ( V_49 < V_97 || V_49 > V_98 ) {
F_45 ( L_15 ,
V_49 , V_97 , V_98 , V_98 ) ;
V_49 = V_98 ;
}
}
static int T_4 F_46 ( void )
{
F_44 () ;
return F_47 ( & V_99 ) ;
}
static void T_5 F_48 ( void )
{
F_49 ( & V_99 ) ;
}
