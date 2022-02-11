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
case V_61 :
case V_62 :
break;
default:
if ( V_16 < 1 || V_16 > V_12 -> V_31 . V_63 ||
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
F_16 ( & V_14 -> V_64 ) ;
V_14 -> V_65 = false ;
F_17 ( & V_14 -> V_64 ) ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_14 -> V_51 [ V_7 ] )
F_19 ( V_14 -> V_51 [ V_7 ] ) ;
if ( V_14 -> V_12 -> V_31 . V_66 & V_67 )
F_20 ( V_14 ) ;
F_21 ( V_14 -> V_58 ) ;
F_22 ( V_14 -> V_58 ) ;
( void ) F_23 ( V_12 , & V_14 -> V_68 ) ;
F_24 ( V_14 -> V_69 ) ;
F_25 ( V_12 , & V_14 -> V_70 ) ;
F_26 ( V_12 , V_14 -> V_71 ) ;
F_27 ( V_14 ) ;
}
static void * F_28 ( struct V_48 * V_12 )
{
struct V_24 * V_14 ;
int V_7 ;
int V_72 ;
F_29 ( V_73 L_6 , V_74 ) ;
V_14 = F_30 ( sizeof( * V_14 ) , V_75 ) ;
if ( ! V_14 ) {
V_72 = - V_76 ;
goto V_77;
}
if ( F_31 ( V_12 , & V_14 -> V_71 ) )
goto V_78;
if ( F_32 ( V_12 , & V_14 -> V_70 ) )
goto V_79;
V_14 -> V_69 = F_33 ( ( V_80 ) V_14 -> V_70 . V_81 << V_82 ,
V_83 ) ;
if ( ! V_14 -> V_69 )
goto V_84;
F_34 ( & V_14 -> V_85 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_86 = & ( V_12 -> V_15 -> V_12 ) ;
V_14 -> V_15 = V_12 -> V_15 ;
V_14 -> V_65 = false ;
V_14 -> V_87 = ! ! ( V_12 -> V_31 . V_19 & ( 1 << 15 ) ) ;
if ( ! V_14 -> V_87 )
F_10 ( V_14 , L_7
L_8 ) ;
if ( F_35 ( V_14 -> V_12 , V_14 -> V_71 , 0 , ~ 0ull ,
V_88 | V_89 ,
0 , 0 , & V_14 -> V_68 ) ) {
F_14 ( V_14 , L_9 ) ;
goto V_90;
}
if ( F_36 ( V_14 -> V_12 , & V_14 -> V_68 ) ) {
F_14 ( V_14 , L_10 ) ;
goto V_91;
}
V_72 = F_7 ( V_14 ) ;
if ( V_72 ) {
F_14 ( V_14 , L_11 ) ;
goto V_91;
}
V_14 -> V_92 = 0 ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH)
V_14 -> V_92 ++ ;
if ( V_14 -> V_12 -> V_31 . V_66 & V_67 )
F_37 ( V_14 ) ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH) {
if ( ! V_12 -> V_31 . V_93 ) {
V_14 -> V_27 . V_34 [ V_7 ] . V_94 =
F_38 ( F_39 ( int , V_95 ,
F_8 ( int ,
V_12 -> V_31 . V_96 ,
V_97 ) ) ) ;
} else {
V_14 -> V_27 . V_34 [ V_7 ] . V_94 = F_38 (
F_8 ( int , V_12 -> V_31 . V_93 /
V_12 -> V_31 . V_63 - 1 , V_98 - 1 ) ) ;
}
}
V_14 -> V_58 = F_40 ( L_12 ) ;
if ( ! V_14 -> V_58 ) {
V_72 = - V_76 ;
goto V_91;
}
F_41 ( & V_14 -> V_64 ) ;
V_14 -> V_65 = true ;
F_18 (i, dev, MLX4_PORT_TYPE_ETH) {
F_42 ( V_14 , L_13 , V_7 ) ;
if ( F_43 ( V_14 , V_7 , & V_14 -> V_27 . V_34 [ V_7 ] ) )
V_14 -> V_51 [ V_7 ] = NULL ;
}
return V_14 ;
V_91:
( void ) F_23 ( V_12 , & V_14 -> V_68 ) ;
V_90:
if ( V_14 -> V_69 )
F_24 ( V_14 -> V_69 ) ;
V_84:
F_25 ( V_12 , & V_14 -> V_70 ) ;
V_79:
F_26 ( V_12 , V_14 -> V_71 ) ;
V_78:
F_27 ( V_14 ) ;
V_77:
return NULL ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_99 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_99 ) ;
}
