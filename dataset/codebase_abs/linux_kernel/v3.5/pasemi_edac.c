static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_1 V_6 ;
F_3 ( V_4 , V_7 ,
& V_6 ) ;
V_6 &= ( V_8 | V_9
| V_10 ) ;
if ( V_6 ) {
if ( V_6 & V_10 )
F_4 ( V_4 , V_11 ,
V_12 ) ;
F_4 ( V_4 , V_7 , V_6 ) ;
}
return V_6 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
T_1 V_14 ;
T_1 V_15 ;
if ( ! V_13 )
return;
F_3 ( V_4 , V_16 , & V_14 ) ;
V_15 = ( V_14 & V_17 ) >>
V_18 ;
if ( V_13 & ( V_9 |
V_8 ) ) {
F_6 ( V_19 , V_2 ,
V_2 -> V_20 [ V_15 ] . V_21 , 0 , 0 ,
V_15 , 0 , - 1 , V_2 -> V_22 , L_1 , NULL ) ;
}
if ( V_13 & V_10 )
F_6 ( V_23 , V_2 ,
V_2 -> V_20 [ V_15 ] . V_21 , 0 , 0 ,
V_15 , 0 , - 1 , V_2 -> V_22 , L_1 , NULL ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_13 ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
F_5 ( V_2 , V_13 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_24 V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
T_1 V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 ; V_31 ++ ) {
V_27 = & V_2 -> V_20 [ V_31 ] ;
V_29 = V_27 -> V_33 [ 0 ] . V_29 ;
F_3 ( V_4 ,
V_34 + ( V_31 * 12 ) ,
& V_30 ) ;
if ( ! ( V_30 & V_35 ) )
continue;
switch ( ( V_30 & V_36 ) >>
V_37 ) {
case 0 :
V_29 -> V_38 = 128 << ( 20 - V_39 ) ;
break;
case 1 :
V_29 -> V_38 = 256 << ( 20 - V_39 ) ;
break;
case 2 :
case 3 :
V_29 -> V_38 = 512 << ( 20 - V_39 ) ;
break;
case 4 :
V_29 -> V_38 = 1024 << ( 20 - V_39 ) ;
break;
case 5 :
V_29 -> V_38 = 2048 << ( 20 - V_39 ) ;
break;
default:
F_9 ( V_2 , V_40 ,
L_2 ,
V_30 ) ;
return - V_41 ;
}
V_27 -> V_21 = V_42 ;
V_27 -> V_43 = V_27 -> V_21 + V_29 -> V_38 - 1 ;
V_42 += V_29 -> V_38 ;
V_27 -> V_44 = 0 ;
V_29 -> V_45 = V_46 ;
V_29 -> V_47 = V_48 ;
V_29 -> V_49 = V_50 ;
V_29 -> V_25 = V_25 ;
}
return 0 ;
}
static int T_2 F_10 ( struct V_3 * V_4 ,
const struct V_51 * V_52 )
{
struct V_1 * V_2 = NULL ;
struct V_53 V_54 [ 2 ] ;
T_1 V_55 , V_56 , V_57 , V_58 ;
F_3 ( V_4 , V_59 , & V_58 ) ;
if ( ! ( V_58 & V_60 ) )
return - V_61 ;
F_3 ( V_4 , V_62 , & V_55 ) ;
V_55 |= V_63 |
V_64 |
V_65 ;
F_4 ( V_4 , V_62 , V_55 ) ;
V_54 [ 0 ] . type = V_66 ;
V_54 [ 0 ] . V_67 = V_68 ;
V_54 [ 0 ] . V_69 = true ;
V_54 [ 1 ] . type = V_70 ;
V_54 [ 1 ] . V_67 = V_71 ;
V_54 [ 1 ] . V_69 = false ;
V_2 = F_11 ( V_72 ++ , F_12 ( V_54 ) , V_54 ,
0 ) ;
if ( V_2 == NULL )
return - V_73 ;
F_3 ( V_4 , V_74 , & V_56 ) ;
V_56 |= V_75 |
V_76 |
V_77 ;
V_2 -> V_5 = & V_4 -> V_5 ;
V_2 -> V_78 = V_79 | V_80 ;
V_2 -> V_81 = V_82 | V_83 | V_84 ;
V_2 -> V_85 = ( V_56 & V_76 ) ?
( ( V_56 & V_77 ) ?
( V_83 | V_84 ) : V_83 ) :
V_82 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = F_13 ( V_4 ) ;
V_2 -> V_22 = L_3 ;
V_2 -> V_89 = F_7 ;
V_2 -> V_90 = NULL ;
F_3 ( V_4 , V_91 , & V_57 ) ;
V_2 -> V_92 = V_93 | V_94 ;
V_2 -> V_95 =
( ( V_56 & V_77 ) ? V_94 : 0 ) |
( ( V_57 & V_96 ) ? V_93 : 0 ) ;
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
return - V_61 ;
}
static void T_3 F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_17 ( & V_4 -> V_5 ) ;
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
