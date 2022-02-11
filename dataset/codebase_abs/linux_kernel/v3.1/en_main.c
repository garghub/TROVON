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
if ( V_19 -> V_22 && ! ( V_14 -> V_12 -> V_23 . V_24
& V_25 ) ) {
F_5 ( V_14 , L_3 ) ;
V_19 -> V_22 = 0 ;
}
for ( V_7 = 1 ; V_7 <= V_26 ; V_7 ++ ) {
V_19 -> V_27 [ V_7 ] . V_28 = 1 ;
V_19 -> V_27 [ V_7 ] . V_29 = V_30 ;
V_19 -> V_27 [ V_7 ] . V_31 = 1 ;
V_19 -> V_27 [ V_7 ] . V_32 = V_33 ;
V_19 -> V_27 [ V_7 ] . V_34 = V_35 ;
V_19 -> V_27 [ V_7 ] . V_36 = V_37 ;
V_19 -> V_27 [ V_7 ] . V_38 = V_39 +
( ! ! V_30 ) * V_40 ;
}
return 0 ;
}
static void * F_6 ( struct V_41 * V_12 , void * V_42 , T_2 V_16 )
{
struct V_17 * V_43 = V_42 ;
return V_43 -> V_44 [ V_16 ] ;
}
static void F_7 ( struct V_41 * V_12 , void * V_45 ,
enum V_46 V_47 , int V_16 )
{
struct V_17 * V_14 = (struct V_17 * ) V_45 ;
struct V_2 * V_3 ;
if ( ! V_14 -> V_44 [ V_16 ] )
return;
V_3 = F_8 ( V_14 -> V_44 [ V_16 ] ) ;
switch ( V_47 ) {
case V_48 :
case V_49 :
V_3 -> V_50 = V_47 ;
F_9 ( V_14 -> V_51 , & V_3 -> V_52 ) ;
break;
case V_53 :
F_10 ( V_14 , L_4 ) ;
break;
default:
F_5 ( V_14 , L_5 , V_47 ) ;
}
}
static void F_11 ( struct V_41 * V_12 , void * V_45 )
{
struct V_17 * V_14 = V_45 ;
int V_7 ;
F_12 ( & V_14 -> V_54 ) ;
V_14 -> V_55 = false ;
F_13 ( & V_14 -> V_54 ) ;
F_14 (i, dev, MLX4_PORT_TYPE_ETH)
if ( V_14 -> V_44 [ V_7 ] )
F_15 ( V_14 -> V_44 [ V_7 ] ) ;
F_16 ( V_14 -> V_51 ) ;
F_17 ( V_14 -> V_51 ) ;
F_18 ( V_12 , & V_14 -> V_56 ) ;
F_19 ( V_12 , & V_14 -> V_57 ) ;
F_20 ( V_12 , V_14 -> V_58 ) ;
F_21 ( V_14 ) ;
}
static void * F_22 ( struct V_41 * V_12 )
{
struct V_17 * V_14 ;
int V_7 ;
int V_59 ;
F_23 ( V_60 L_6 , V_61 ) ;
V_14 = F_24 ( sizeof *V_14 , V_62 ) ;
if ( ! V_14 ) {
F_25 ( & V_12 -> V_15 -> V_12 , L_7
L_8 ) ;
V_59 = - V_63 ;
goto V_64;
}
if ( F_26 ( V_12 , & V_14 -> V_58 ) )
goto V_65;
if ( F_27 ( V_12 , & V_14 -> V_57 ) )
goto V_66;
V_14 -> V_67 = F_28 ( ( V_68 ) V_14 -> V_57 . V_69 << V_70 ,
V_71 ) ;
if ( ! V_14 -> V_67 )
goto V_72;
F_29 ( & V_14 -> V_73 ) ;
V_14 -> V_12 = V_12 ;
V_14 -> V_74 = & ( V_12 -> V_15 -> V_12 ) ;
V_14 -> V_15 = V_12 -> V_15 ;
V_14 -> V_55 = false ;
V_14 -> V_75 = ! ! ( V_12 -> V_23 . V_24 & ( 1 << 15 ) ) ;
if ( ! V_14 -> V_75 )
F_5 ( V_14 , L_9
L_10 ) ;
if ( F_30 ( V_14 -> V_12 , V_14 -> V_58 , 0 , ~ 0ull ,
V_76 | V_77 ,
0 , 0 , & V_14 -> V_56 ) ) {
F_10 ( V_14 , L_11 ) ;
goto V_72;
}
if ( F_31 ( V_14 -> V_12 , & V_14 -> V_56 ) ) {
F_10 ( V_14 , L_12 ) ;
goto V_78;
}
V_59 = F_4 ( V_14 ) ;
if ( V_59 ) {
F_10 ( V_14 , L_13 ) ;
goto V_78;
}
V_14 -> V_79 = 0 ;
F_14 (i, dev, MLX4_PORT_TYPE_ETH)
V_14 -> V_79 ++ ;
F_14 (i, dev, MLX4_PORT_TYPE_ETH) {
if ( ! V_12 -> V_23 . V_80 ) {
V_14 -> V_20 . V_27 [ V_7 ] . V_81 =
F_32 ( F_33 ( int , V_82 ,
F_34 ( int ,
V_12 -> V_23 . V_83 ,
V_84 ) ) ) ;
} else {
V_14 -> V_20 . V_27 [ V_7 ] . V_81 = F_32 (
F_34 ( int , V_12 -> V_23 . V_80 /
V_12 -> V_23 . V_85 - 1 , V_86 - 1 ) ) ;
}
}
V_14 -> V_51 = F_35 ( L_14 ) ;
if ( ! V_14 -> V_51 ) {
V_59 = - V_63 ;
goto V_78;
}
F_36 ( & V_14 -> V_54 ) ;
V_14 -> V_55 = true ;
F_14 (i, dev, MLX4_PORT_TYPE_ETH) {
F_37 ( V_14 , L_15 , V_7 ) ;
if ( F_38 ( V_14 , V_7 , & V_14 -> V_20 . V_27 [ V_7 ] ) )
V_14 -> V_44 [ V_7 ] = NULL ;
}
return V_14 ;
V_78:
F_18 ( V_12 , & V_14 -> V_56 ) ;
V_72:
F_19 ( V_12 , & V_14 -> V_57 ) ;
V_66:
F_20 ( V_12 , V_14 -> V_58 ) ;
V_65:
F_21 ( V_14 ) ;
V_64:
return NULL ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_87 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_87 ) ;
}
