static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_4 ) ;
T_1 V_5 ;
F_3 ( V_4 , V_6 ,
& V_5 ) ;
V_5 &= ( V_7 | V_8
| V_9 ) ;
if ( V_5 ) {
if ( V_5 & V_9 )
F_4 ( V_4 , V_10 ,
V_11 ) ;
F_4 ( V_4 , V_6 , V_5 ) ;
}
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_4 ) ;
T_1 V_13 ;
T_1 V_14 ;
if ( ! V_12 )
return;
F_3 ( V_4 , V_15 , & V_13 ) ;
V_14 = ( V_13 & V_16 ) >>
V_17 ;
if ( V_12 & ( V_8 |
V_7 ) ) {
F_6 ( V_18 , V_2 , 1 ,
V_2 -> V_19 [ V_14 ] -> V_20 , 0 , 0 ,
V_14 , 0 , - 1 , V_2 -> V_21 , L_1 ) ;
}
if ( V_12 & V_9 )
F_6 ( V_22 , V_2 , 1 ,
V_2 -> V_19 [ V_14 ] -> V_20 , 0 , 0 ,
V_14 , 0 , - 1 , V_2 -> V_21 , L_1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
F_5 ( V_2 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_23 V_24 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
T_1 V_29 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ ) {
V_26 = V_2 -> V_19 [ V_30 ] ;
V_28 = V_26 -> V_32 [ 0 ] -> V_28 ;
F_3 ( V_4 ,
V_33 + ( V_30 * 12 ) ,
& V_29 ) ;
if ( ! ( V_29 & V_34 ) )
continue;
switch ( ( V_29 & V_35 ) >>
V_36 ) {
case 0 :
V_28 -> V_37 = 128 << ( 20 - V_38 ) ;
break;
case 1 :
V_28 -> V_37 = 256 << ( 20 - V_38 ) ;
break;
case 2 :
case 3 :
V_28 -> V_37 = 512 << ( 20 - V_38 ) ;
break;
case 4 :
V_28 -> V_37 = 1024 << ( 20 - V_38 ) ;
break;
case 5 :
V_28 -> V_37 = 2048 << ( 20 - V_38 ) ;
break;
default:
F_9 ( V_2 , V_39 ,
L_2 ,
V_29 ) ;
return - V_40 ;
}
V_26 -> V_20 = V_41 ;
V_26 -> V_42 = V_26 -> V_20 + V_28 -> V_37 - 1 ;
V_41 += V_28 -> V_37 ;
V_26 -> V_43 = 0 ;
V_28 -> V_44 = V_45 ;
V_28 -> V_46 = V_47 ;
V_28 -> V_48 = V_49 ;
V_28 -> V_24 = V_24 ;
}
return 0 ;
}
static int T_2 F_10 ( struct V_3 * V_4 ,
const struct V_50 * V_51 )
{
struct V_1 * V_2 = NULL ;
struct V_52 V_53 [ 2 ] ;
T_1 V_54 , V_55 , V_56 , V_57 ;
F_3 ( V_4 , V_58 , & V_57 ) ;
if ( ! ( V_57 & V_59 ) )
return - V_60 ;
F_3 ( V_4 , V_61 , & V_54 ) ;
V_54 |= V_62 |
V_63 |
V_64 ;
F_4 ( V_4 , V_61 , V_54 ) ;
V_53 [ 0 ] . type = V_65 ;
V_53 [ 0 ] . V_66 = V_67 ;
V_53 [ 0 ] . V_68 = true ;
V_53 [ 1 ] . type = V_69 ;
V_53 [ 1 ] . V_66 = V_70 ;
V_53 [ 1 ] . V_68 = false ;
V_2 = F_11 ( V_71 ++ , F_12 ( V_53 ) , V_53 ,
0 ) ;
if ( V_2 == NULL )
return - V_72 ;
F_3 ( V_4 , V_73 , & V_55 ) ;
V_55 |= V_74 |
V_75 |
V_76 ;
V_2 -> V_4 = & V_4 -> V_77 ;
V_2 -> V_78 = V_79 | V_80 ;
V_2 -> V_81 = V_82 | V_83 | V_84 ;
V_2 -> V_85 = ( V_55 & V_75 ) ?
( ( V_55 & V_76 ) ?
( V_83 | V_84 ) : V_83 ) :
V_82 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = F_13 ( V_4 ) ;
V_2 -> V_21 = L_3 ;
V_2 -> V_89 = F_7 ;
V_2 -> V_90 = NULL ;
F_3 ( V_4 , V_91 , & V_56 ) ;
V_2 -> V_92 = V_93 | V_94 ;
V_2 -> V_95 =
( ( V_55 & V_76 ) ? V_94 : 0 ) |
( ( V_56 & V_96 ) ? V_93 : 0 ) ;
if ( F_8 ( V_2 , V_4 ,
( V_2 -> V_85 & V_84 ) ?
V_97 :
( ( V_2 -> V_85 & V_83 ) ?
V_98 : V_99 ) ) )
goto V_100;
F_1 ( V_2 ) ;
if ( F_14 ( V_2 ) )
goto V_100;
return 0 ;
V_100:
F_15 ( V_2 ) ;
return - V_60 ;
}
static void T_3 F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( & V_4 -> V_77 ) ;
if ( ! V_2 )
return;
F_15 ( V_2 ) ;
}
static int T_4 F_18 ( void )
{
F_19 () ;
return F_20 ( & V_101 ) ;
}
static void T_5 F_21 ( void )
{
F_22 ( & V_101 ) ;
}
