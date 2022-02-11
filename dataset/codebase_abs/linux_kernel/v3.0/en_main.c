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
V_19 -> V_22 = V_22 ;
if ( V_19 -> V_22 && ! V_14 -> V_12 -> V_23 . V_22 ) {
F_5 ( V_14 , L_3 ) ;
V_19 -> V_22 = 0 ;
}
for ( V_7 = 1 ; V_7 <= V_24 ; V_7 ++ ) {
V_19 -> V_25 [ V_7 ] . V_26 = 1 ;
V_19 -> V_25 [ V_7 ] . V_27 = V_28 ;
V_19 -> V_25 [ V_7 ] . V_29 = 1 ;
V_19 -> V_25 [ V_7 ] . V_30 = V_31 ;
V_19 -> V_25 [ V_7 ] . V_32 = V_33 ;
V_19 -> V_25 [ V_7 ] . V_34 = V_35 ;
V_19 -> V_25 [ V_7 ] . V_36 = V_37 +
( ! ! V_28 ) * V_38 ;
}
return 0 ;
}
static void * F_6 ( struct V_39 * V_12 , void * V_40 , T_2 V_16 )
{
struct V_17 * V_41 = V_40 ;
return V_41 -> V_42 [ V_16 ] ;
}
static void F_7 ( struct V_39 * V_12 , void * V_43 ,
enum V_44 V_45 , int V_16 )
{
struct V_17 * V_14 = (struct V_17 * ) V_43 ;
struct V_2 * V_3 ;
if ( ! V_14 -> V_42 [ V_16 ] )
return;
V_3 = F_8 ( V_14 -> V_42 [ V_16 ] ) ;
switch ( V_45 ) {
case V_46 :
case V_47 :
V_3 -> V_48 = V_45 ;
F_9 ( V_14 -> V_49 , & V_3 -> V_50 ) ;
break;
case V_51 :
F_10 ( V_14 , L_4 ) ;
break;
default:
F_5 ( V_14 , L_5 , V_45 ) ;
}
}
static void F_11 ( struct V_39 * V_12 , void * V_43 )
{
struct V_17 * V_14 = V_43 ;
int V_7 ;
F_12 ( & V_14 -> V_52 ) ;
V_14 -> V_53 = false ;
F_13 ( & V_14 -> V_52 ) ;
F_14 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_14 -> V_42 [ V_7 ] )
F_15 ( V_14 -> V_42 [ V_7 ] ) ;
F_16 ( V_14 -> V_49 ) ;
F_17 ( V_14 -> V_49 ) ;
F_18 ( V_12 , & V_14 -> V_54 ) ;
F_19 ( V_12 , & V_14 -> V_55 ) ;
F_20 ( V_12 , V_14 -> V_56 ) ;
F_21 ( V_14 ) ;
}
static void * F_22 ( struct V_39 * V_12 )
{
struct V_17 * V_14 ;
int V_7 ;
int V_57 ;
F_23 ( V_58 L_6 , V_59 ) ;
V_14 = F_24 ( sizeof *V_14 , V_60 ) ;
if ( ! V_14 ) {
F_25 ( & V_12 -> V_15 -> V_12 , L_7
L_8 ) ;
V_57 = - V_61 ;
goto V_62;
}
if ( F_26 ( V_12 , & V_14 -> V_56 ) )
goto V_63;
if ( F_27 ( V_12 , & V_14 -> V_55 ) )
goto V_64;
V_14 -> V_65 = F_28 ( ( V_66 ) V_14 -> V_55 . V_67 << V_68 ,
V_69 ) ;
if ( ! V_14 -> V_65 )
goto V_70;
F_29 ( & V_14 -> V_71 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_72 = & ( V_12 -> V_15 -> V_12 ) ;
V_14 -> V_15 = V_12 -> V_15 ;
V_14 -> V_53 = false ;
V_14 -> V_73 = ! ! ( V_12 -> V_23 . V_74 & ( 1 << 15 ) ) ;
if ( ! V_14 -> V_73 )
F_5 ( V_14 , L_9
L_10 ) ;
if ( F_30 ( V_14 -> V_12 , V_14 -> V_56 , 0 , ~ 0ull ,
V_75 | V_76 ,
0 , 0 , & V_14 -> V_54 ) ) {
F_10 ( V_14 , L_11 ) ;
goto V_70;
}
if ( F_31 ( V_14 -> V_12 , & V_14 -> V_54 ) ) {
F_10 ( V_14 , L_12 ) ;
goto V_77;
}
V_57 = F_4 ( V_14 ) ;
if ( V_57 ) {
F_10 ( V_14 , L_13 ) ;
goto V_77;
}
V_14 -> V_78 = 0 ;
F_14 (i, dev, MLX4_PORT_TYPE_ETH)
V_14 -> V_78 ++ ;
F_14 (i, dev, MLX4_PORT_TYPE_ETH) {
if ( ! V_12 -> V_23 . V_79 ) {
V_14 -> V_20 . V_25 [ V_7 ] . V_80 =
F_32 ( F_33 ( int , V_81 ,
F_34 ( int ,
V_12 -> V_23 . V_82 ,
V_83 ) ) ) ;
} else {
V_14 -> V_20 . V_25 [ V_7 ] . V_80 = F_32 (
F_34 ( int , V_12 -> V_23 . V_79 /
V_12 -> V_23 . V_84 - 1 , V_85 - 1 ) ) ;
}
}
V_14 -> V_49 = F_35 ( L_14 ) ;
if ( ! V_14 -> V_49 ) {
V_57 = - V_61 ;
goto V_77;
}
F_36 ( & V_14 -> V_52 ) ;
V_14 -> V_53 = true ;
F_14 (i, dev, MLX4_PORT_TYPE_ETH) {
F_37 ( V_14 , L_15 , V_7 ) ;
if ( F_38 ( V_14 , V_7 , & V_14 -> V_20 . V_25 [ V_7 ] ) )
V_14 -> V_42 [ V_7 ] = NULL ;
}
return V_14 ;
V_77:
F_18 ( V_12 , & V_14 -> V_54 ) ;
V_70:
F_19 ( V_12 , & V_14 -> V_55 ) ;
V_64:
F_20 ( V_12 , V_14 -> V_56 ) ;
V_63:
F_21 ( V_14 ) ;
V_62:
return NULL ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_86 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_86 ) ;
}
