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
}
return 0 ;
}
static void * F_11 ( struct V_48 * V_12 , void * V_49 , T_3 V_16 )
{
struct V_24 * V_50 = V_49 ;
return V_50 -> V_51 [ V_16 ] ;
}
static void F_12 ( struct V_48 * V_12 , void * V_52 ,
enum V_53 V_54 , unsigned long V_16 )
{
struct V_24 * V_14 = (struct V_24 * ) V_52 ;
struct V_2 * V_3 ;
switch ( V_54 ) {
case V_55 :
case V_56 :
if ( ! V_14 -> V_51 [ V_16 ] )
return;
V_3 = F_5 ( V_14 -> V_51 [ V_16 ] ) ;
V_3 -> V_57 = V_54 ;
F_13 ( V_14 -> V_58 , & V_3 -> V_59 ) ;
break;
case V_60 :
F_14 ( V_14 , L_4 ) ;
break;
default:
if ( V_16 < 1 || V_16 > V_12 -> V_31 . V_61 ||
! V_14 -> V_51 [ V_16 ] )
return;
F_10 ( V_14 , L_5 , V_54 ,
( int ) V_16 ) ;
}
}
static void F_15 ( struct V_48 * V_12 , void * V_52 )
{
struct V_24 * V_14 = V_52 ;
int V_7 ;
F_16 ( & V_14 -> V_62 ) ;
V_14 -> V_63 = false ;
F_17 ( & V_14 -> V_62 ) ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_14 -> V_51 [ V_7 ] )
F_19 ( V_14 -> V_51 [ V_7 ] ) ;
F_20 ( V_14 -> V_58 ) ;
F_21 ( V_14 -> V_58 ) ;
( void ) F_22 ( V_12 , & V_14 -> V_64 ) ;
F_23 ( V_14 -> V_65 ) ;
F_24 ( V_12 , & V_14 -> V_66 ) ;
F_25 ( V_12 , V_14 -> V_67 ) ;
F_26 ( V_14 ) ;
}
static void * F_27 ( struct V_48 * V_12 )
{
struct V_24 * V_14 ;
int V_7 ;
int V_68 ;
F_28 ( V_69 L_6 , V_70 ) ;
V_14 = F_29 ( sizeof( * V_14 ) , V_71 ) ;
if ( ! V_14 ) {
V_68 = - V_72 ;
goto V_73;
}
if ( F_30 ( V_12 , & V_14 -> V_67 ) )
goto V_74;
if ( F_31 ( V_12 , & V_14 -> V_66 ) )
goto V_75;
V_14 -> V_65 = F_32 ( ( V_76 ) V_14 -> V_66 . V_77 << V_78 ,
V_79 ) ;
if ( ! V_14 -> V_65 )
goto V_80;
F_33 ( & V_14 -> V_81 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_82 = & ( V_12 -> V_15 -> V_12 ) ;
V_14 -> V_15 = V_12 -> V_15 ;
V_14 -> V_63 = false ;
V_14 -> V_83 = ! ! ( V_12 -> V_31 . V_19 & ( 1 << 15 ) ) ;
if ( ! V_14 -> V_83 )
F_10 ( V_14 , L_7
L_8 ) ;
if ( F_34 ( V_14 -> V_12 , V_14 -> V_67 , 0 , ~ 0ull ,
V_84 | V_85 ,
0 , 0 , & V_14 -> V_64 ) ) {
F_14 ( V_14 , L_9 ) ;
goto V_86;
}
if ( F_35 ( V_14 -> V_12 , & V_14 -> V_64 ) ) {
F_14 ( V_14 , L_10 ) ;
goto V_87;
}
V_68 = F_7 ( V_14 ) ;
if ( V_68 ) {
F_14 ( V_14 , L_11 ) ;
goto V_87;
}
V_14 -> V_88 = 0 ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH)
V_14 -> V_88 ++ ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH) {
if ( ! V_12 -> V_31 . V_89 ) {
V_14 -> V_27 . V_34 [ V_7 ] . V_90 =
F_36 ( F_37 ( int , V_91 ,
F_8 ( int ,
V_12 -> V_31 . V_92 ,
V_93 ) ) ) ;
} else {
V_14 -> V_27 . V_34 [ V_7 ] . V_90 = F_36 (
F_8 ( int , V_12 -> V_31 . V_89 /
V_12 -> V_31 . V_61 - 1 , V_94 - 1 ) ) ;
}
}
V_14 -> V_58 = F_38 ( L_12 ) ;
if ( ! V_14 -> V_58 ) {
V_68 = - V_72 ;
goto V_87;
}
F_39 ( & V_14 -> V_62 ) ;
V_14 -> V_63 = true ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH) {
F_40 ( V_14 , L_13 , V_7 ) ;
if ( F_41 ( V_14 , V_7 , & V_14 -> V_27 . V_34 [ V_7 ] ) )
V_14 -> V_51 [ V_7 ] = NULL ;
}
if ( V_14 -> V_12 -> V_31 . V_95 & V_96 )
F_42 ( V_14 ) ;
return V_14 ;
V_87:
( void ) F_22 ( V_12 , & V_14 -> V_64 ) ;
V_86:
if ( ! V_14 -> V_65 )
F_23 ( V_14 -> V_65 ) ;
V_80:
F_24 ( V_12 , & V_14 -> V_66 ) ;
V_75:
F_25 ( V_12 , V_14 -> V_67 ) ;
V_74:
F_26 ( V_14 ) ;
V_73:
return NULL ;
}
static int T_4 F_43 ( void )
{
return F_44 ( & V_97 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_97 ) ;
}
