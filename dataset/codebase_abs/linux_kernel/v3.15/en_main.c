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
V_26 -> V_29 = F_8 ( int , F_9 () ,
V_30 ) ;
if ( V_26 -> V_28 && ! ( V_14 -> V_12 -> V_31 . V_19
& V_32 ) ) {
F_10 ( V_14 , L_3 ) ;
V_26 -> V_28 = 0 ;
}
for ( V_7 = 1 ; V_7 <= V_33 ; V_7 ++ ) {
V_26 -> V_34 [ V_7 ] . V_35 = 1 ;
V_26 -> V_34 [ V_7 ] . V_36 = V_37 ;
V_26 -> V_34 [ V_7 ] . V_38 = 1 ;
V_26 -> V_34 [ V_7 ] . V_39 = V_40 ;
V_26 -> V_34 [ V_7 ] . V_41 = V_42 ;
V_26 -> V_34 [ V_7 ] . V_43 = V_44 ;
V_26 -> V_34 [ V_7 ] . V_45 = V_26 -> V_29 *
V_46 ;
V_26 -> V_34 [ V_7 ] . V_47 = 0 ;
V_26 -> V_34 [ V_7 ] . V_48 = V_48 ;
}
return 0 ;
}
static void * F_11 ( struct V_49 * V_12 , void * V_50 , T_3 V_16 )
{
struct V_24 * V_51 = V_50 ;
return V_51 -> V_52 [ V_16 ] ;
}
static void F_12 ( struct V_49 * V_12 , void * V_53 ,
enum V_54 V_55 , unsigned long V_16 )
{
struct V_24 * V_14 = (struct V_24 * ) V_53 ;
struct V_2 * V_3 ;
switch ( V_55 ) {
case V_56 :
case V_57 :
if ( ! V_14 -> V_52 [ V_16 ] )
return;
V_3 = F_5 ( V_14 -> V_52 [ V_16 ] ) ;
V_3 -> V_58 = V_55 ;
F_13 ( V_14 -> V_59 , & V_3 -> V_60 ) ;
break;
case V_61 :
F_14 ( V_14 , L_4 ) ;
break;
case V_62 :
case V_63 :
break;
default:
if ( V_16 < 1 || V_16 > V_12 -> V_31 . V_64 ||
! V_14 -> V_52 [ V_16 ] )
return;
F_10 ( V_14 , L_5 , V_55 ,
( int ) V_16 ) ;
}
}
static void F_15 ( struct V_49 * V_12 , void * V_53 )
{
struct V_24 * V_14 = V_53 ;
int V_7 ;
F_16 ( & V_14 -> V_65 ) ;
V_14 -> V_66 = false ;
F_17 ( & V_14 -> V_65 ) ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_14 -> V_52 [ V_7 ] )
F_19 ( V_14 -> V_52 [ V_7 ] ) ;
if ( V_14 -> V_12 -> V_31 . V_67 & V_68 )
F_20 ( V_14 ) ;
F_21 ( V_14 -> V_59 ) ;
F_22 ( V_14 -> V_59 ) ;
( void ) F_23 ( V_12 , & V_14 -> V_69 ) ;
F_24 ( V_14 -> V_70 ) ;
F_25 ( V_12 , & V_14 -> V_71 ) ;
F_26 ( V_12 , V_14 -> V_72 ) ;
F_27 ( V_14 ) ;
}
static void * F_28 ( struct V_49 * V_12 )
{
struct V_24 * V_14 ;
int V_7 ;
int V_73 ;
F_29 ( V_74 L_6 , V_75 ) ;
V_14 = F_30 ( sizeof( * V_14 ) , V_76 ) ;
if ( ! V_14 ) {
V_73 = - V_77 ;
goto V_78;
}
if ( F_31 ( V_12 , & V_14 -> V_72 ) )
goto V_79;
if ( F_32 ( V_12 , & V_14 -> V_71 ) )
goto V_80;
V_14 -> V_70 = F_33 ( ( V_81 ) V_14 -> V_71 . V_82 << V_83 ,
V_84 ) ;
if ( ! V_14 -> V_70 )
goto V_85;
F_34 ( & V_14 -> V_86 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_87 = & ( V_12 -> V_15 -> V_12 ) ;
V_14 -> V_15 = V_12 -> V_15 ;
V_14 -> V_66 = false ;
V_14 -> V_88 = ! ! ( V_12 -> V_31 . V_19 & ( 1 << 15 ) ) ;
if ( ! V_14 -> V_88 )
F_10 ( V_14 , L_7
L_8 ) ;
if ( F_35 ( V_14 -> V_12 , V_14 -> V_72 , 0 , ~ 0ull ,
V_89 | V_90 ,
0 , 0 , & V_14 -> V_69 ) ) {
F_14 ( V_14 , L_9 ) ;
goto V_91;
}
if ( F_36 ( V_14 -> V_12 , & V_14 -> V_69 ) ) {
F_14 ( V_14 , L_10 ) ;
goto V_92;
}
V_73 = F_7 ( V_14 ) ;
if ( V_73 ) {
F_14 ( V_14 , L_11 ) ;
goto V_92;
}
V_14 -> V_93 = 0 ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH)
V_14 -> V_93 ++ ;
if ( V_14 -> V_12 -> V_31 . V_67 & V_68 )
F_37 ( V_14 ) ;
F_38 ( V_14 ) ;
V_14 -> V_59 = F_39 ( L_12 ) ;
if ( ! V_14 -> V_59 ) {
V_73 = - V_77 ;
goto V_92;
}
F_40 ( & V_14 -> V_65 ) ;
V_14 -> V_66 = true ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH) {
F_41 ( V_14 , L_13 , V_7 ) ;
if ( F_42 ( V_14 , V_7 , & V_14 -> V_27 . V_34 [ V_7 ] ) )
V_14 -> V_52 [ V_7 ] = NULL ;
}
return V_14 ;
V_92:
( void ) F_23 ( V_12 , & V_14 -> V_69 ) ;
V_91:
if ( V_14 -> V_70 )
F_24 ( V_14 -> V_70 ) ;
V_85:
F_25 ( V_12 , & V_14 -> V_71 ) ;
V_80:
F_26 ( V_12 , V_14 -> V_72 ) ;
V_79:
F_27 ( V_14 ) ;
V_78:
return NULL ;
}
static void F_43 ( void )
{
if ( V_40 > V_94 ) {
F_44 ( L_14 ,
V_40 , V_94 ) ;
V_40 = 0 ;
}
if ( V_37 > V_95 ) {
F_44 ( L_15 ,
V_37 , V_95 ) ;
V_37 = 0 ;
}
if ( V_48 < V_96 || V_48 > V_97 ) {
F_44 ( L_16 ,
V_48 , V_96 , V_97 , V_97 ) ;
V_48 = V_97 ;
}
}
static int T_4 F_45 ( void )
{
F_43 () ;
return F_46 ( & V_98 ) ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_98 ) ;
}
