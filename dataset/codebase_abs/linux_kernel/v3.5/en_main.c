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
static int F_4 ( struct V_17 * V_14 )
{
struct V_18 * V_19 = & V_14 -> V_20 ;
int V_7 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_22 = F_5 ( int , F_6 () ,
V_23 ) ;
if ( V_19 -> V_21 && ! ( V_14 -> V_12 -> V_24 . V_25
& V_26 ) ) {
F_7 ( V_14 , L_3 ) ;
V_19 -> V_21 = 0 ;
}
for ( V_7 = 1 ; V_7 <= V_27 ; V_7 ++ ) {
V_19 -> V_28 [ V_7 ] . V_29 = 1 ;
V_19 -> V_28 [ V_7 ] . V_30 = V_31 ;
V_19 -> V_28 [ V_7 ] . V_32 = 1 ;
V_19 -> V_28 [ V_7 ] . V_33 = V_34 ;
V_19 -> V_28 [ V_7 ] . V_35 = V_36 ;
V_19 -> V_28 [ V_7 ] . V_37 = V_38 ;
V_19 -> V_28 [ V_7 ] . V_39 = V_19 -> V_22 *
V_40 ;
V_19 -> V_28 [ V_7 ] . V_41 = 0 ;
}
return 0 ;
}
static void * F_8 ( struct V_42 * V_12 , void * V_43 , T_2 V_16 )
{
struct V_17 * V_44 = V_43 ;
return V_44 -> V_45 [ V_16 ] ;
}
static void F_9 ( struct V_42 * V_12 , void * V_46 ,
enum V_47 V_48 , int V_16 )
{
struct V_17 * V_14 = (struct V_17 * ) V_46 ;
struct V_2 * V_3 ;
switch ( V_48 ) {
case V_49 :
case V_50 :
if ( ! V_14 -> V_45 [ V_16 ] )
return;
V_3 = F_10 ( V_14 -> V_45 [ V_16 ] ) ;
V_3 -> V_51 = V_48 ;
F_11 ( V_14 -> V_52 , & V_3 -> V_53 ) ;
break;
case V_54 :
F_12 ( V_14 , L_4 ) ;
break;
default:
if ( V_16 < 1 || V_16 > V_12 -> V_24 . V_55 ||
! V_14 -> V_45 [ V_16 ] )
return;
F_7 ( V_14 , L_5 , V_48 , V_16 ) ;
}
}
static void F_13 ( struct V_42 * V_12 , void * V_46 )
{
struct V_17 * V_14 = V_46 ;
int V_7 ;
F_14 ( & V_14 -> V_56 ) ;
V_14 -> V_57 = false ;
F_15 ( & V_14 -> V_56 ) ;
F_16 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_14 -> V_45 [ V_7 ] )
F_17 ( V_14 -> V_45 [ V_7 ] ) ;
F_18 ( V_14 -> V_52 ) ;
F_19 ( V_14 -> V_52 ) ;
F_20 ( V_12 , & V_14 -> V_58 ) ;
F_21 ( V_14 -> V_59 ) ;
F_22 ( V_12 , & V_14 -> V_60 ) ;
F_23 ( V_12 , V_14 -> V_61 ) ;
F_24 ( V_14 ) ;
}
static void * F_25 ( struct V_42 * V_12 )
{
struct V_17 * V_14 ;
int V_7 ;
int V_62 ;
F_26 ( V_63 L_6 , V_64 ) ;
V_14 = F_27 ( sizeof *V_14 , V_65 ) ;
if ( ! V_14 ) {
F_28 ( & V_12 -> V_15 -> V_12 , L_7
L_8 ) ;
V_62 = - V_66 ;
goto V_67;
}
if ( F_29 ( V_12 , & V_14 -> V_61 ) )
goto V_68;
if ( F_30 ( V_12 , & V_14 -> V_60 ) )
goto V_69;
V_14 -> V_59 = F_31 ( ( V_70 ) V_14 -> V_60 . V_71 << V_72 ,
V_73 ) ;
if ( ! V_14 -> V_59 )
goto V_74;
F_32 ( & V_14 -> V_75 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_76 = & ( V_12 -> V_15 -> V_12 ) ;
V_14 -> V_15 = V_12 -> V_15 ;
V_14 -> V_57 = false ;
V_14 -> V_77 = ! ! ( V_12 -> V_24 . V_25 & ( 1 << 15 ) ) ;
if ( ! V_14 -> V_77 )
F_7 ( V_14 , L_9
L_10 ) ;
if ( F_33 ( V_14 -> V_12 , V_14 -> V_61 , 0 , ~ 0ull ,
V_78 | V_79 ,
0 , 0 , & V_14 -> V_58 ) ) {
F_12 ( V_14 , L_11 ) ;
goto V_80;
}
if ( F_34 ( V_14 -> V_12 , & V_14 -> V_58 ) ) {
F_12 ( V_14 , L_12 ) ;
goto V_81;
}
V_62 = F_4 ( V_14 ) ;
if ( V_62 ) {
F_12 ( V_14 , L_13 ) ;
goto V_81;
}
V_14 -> V_82 = 0 ;
F_16 (i, dev, MLX4_PORT_TYPE_ETH)
V_14 -> V_82 ++ ;
F_16 (i, dev, MLX4_PORT_TYPE_ETH) {
if ( ! V_12 -> V_24 . V_83 ) {
V_14 -> V_20 . V_28 [ V_7 ] . V_84 =
F_35 ( F_36 ( int , V_85 ,
F_5 ( int ,
V_12 -> V_24 . V_86 ,
V_87 ) ) ) ;
} else {
V_14 -> V_20 . V_28 [ V_7 ] . V_84 = F_35 (
F_5 ( int , V_12 -> V_24 . V_83 /
V_12 -> V_24 . V_55 - 1 , V_88 - 1 ) ) ;
}
}
V_14 -> V_52 = F_37 ( L_14 ) ;
if ( ! V_14 -> V_52 ) {
V_62 = - V_66 ;
goto V_81;
}
F_38 ( & V_14 -> V_56 ) ;
V_14 -> V_57 = true ;
F_16 (i, dev, MLX4_PORT_TYPE_ETH) {
F_39 ( V_14 , L_15 , V_7 ) ;
if ( F_40 ( V_14 , V_7 , & V_14 -> V_20 . V_28 [ V_7 ] ) )
V_14 -> V_45 [ V_7 ] = NULL ;
}
return V_14 ;
V_81:
F_20 ( V_12 , & V_14 -> V_58 ) ;
V_80:
if ( ! V_14 -> V_59 )
F_21 ( V_14 -> V_59 ) ;
V_74:
F_22 ( V_12 , & V_14 -> V_60 ) ;
V_69:
F_23 ( V_12 , V_14 -> V_61 ) ;
V_68:
F_24 ( V_14 ) ;
V_67:
return NULL ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_89 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_89 ) ;
}
