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
F_6 ( V_2 , V_2 -> V_19 [ V_15 ] . V_20 , 0 ,
V_15 , V_2 -> V_21 ) ;
}
if ( V_13 & V_10 ) {
F_7 ( V_2 , V_2 -> V_19 [ V_15 ] . V_20 , 0 ,
0 , V_15 , 0 , V_2 -> V_21 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_13 ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
F_5 ( V_2 , V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_22 V_23 )
{
struct V_24 * V_25 ;
T_1 V_26 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_28 ; V_27 ++ ) {
V_25 = & V_2 -> V_19 [ V_27 ] ;
F_3 ( V_4 ,
V_29 + ( V_27 * 12 ) ,
& V_26 ) ;
if ( ! ( V_26 & V_30 ) )
continue;
switch ( ( V_26 & V_31 ) >>
V_32 ) {
case 0 :
V_25 -> V_33 = 128 << ( 20 - V_34 ) ;
break;
case 1 :
V_25 -> V_33 = 256 << ( 20 - V_34 ) ;
break;
case 2 :
case 3 :
V_25 -> V_33 = 512 << ( 20 - V_34 ) ;
break;
case 4 :
V_25 -> V_33 = 1024 << ( 20 - V_34 ) ;
break;
case 5 :
V_25 -> V_33 = 2048 << ( 20 - V_34 ) ;
break;
default:
F_10 ( V_2 , V_35 ,
L_1 ,
V_26 ) ;
return - V_36 ;
}
V_25 -> V_20 = V_37 ;
V_25 -> V_38 = V_25 -> V_20 + V_25 -> V_33 - 1 ;
V_37 += V_25 -> V_33 ;
V_25 -> V_39 = 0 ;
V_25 -> V_40 = V_41 ;
V_25 -> V_42 = V_43 ;
V_25 -> V_44 = V_45 ;
V_25 -> V_23 = V_23 ;
}
return 0 ;
}
static int T_2 F_11 ( struct V_3 * V_4 ,
const struct V_46 * V_47 )
{
struct V_1 * V_2 = NULL ;
T_1 V_48 , V_49 , V_50 , V_51 ;
F_3 ( V_4 , V_52 , & V_51 ) ;
if ( ! ( V_51 & V_53 ) )
return - V_54 ;
F_3 ( V_4 , V_55 , & V_48 ) ;
V_48 |= V_56 |
V_57 |
V_58 ;
F_4 ( V_4 , V_55 , V_48 ) ;
V_2 = F_12 ( 0 , V_59 , V_60 ,
V_61 ++ ) ;
if ( V_2 == NULL )
return - V_62 ;
F_3 ( V_4 , V_63 , & V_49 ) ;
V_49 |= V_64 |
V_65 |
V_66 ;
V_2 -> V_5 = & V_4 -> V_5 ;
V_2 -> V_67 = V_68 | V_69 ;
V_2 -> V_70 = V_71 | V_72 | V_73 ;
V_2 -> V_74 = ( V_49 & V_65 ) ?
( ( V_49 & V_66 ) ?
( V_72 | V_73 ) : V_72 ) :
V_71 ;
V_2 -> V_75 = V_76 ;
V_2 -> V_77 = F_13 ( V_4 ) ;
V_2 -> V_21 = L_2 ;
V_2 -> V_78 = F_8 ;
V_2 -> V_79 = NULL ;
F_3 ( V_4 , V_80 , & V_50 ) ;
V_2 -> V_81 = V_82 | V_83 ;
V_2 -> V_84 =
( ( V_49 & V_66 ) ? V_83 : 0 ) |
( ( V_50 & V_85 ) ? V_82 : 0 ) ;
if ( F_9 ( V_2 , V_4 ,
( V_2 -> V_74 & V_73 ) ?
V_86 :
( ( V_2 -> V_74 & V_72 ) ?
V_87 : V_88 ) ) )
goto V_89;
F_1 ( V_2 ) ;
if ( F_14 ( V_2 ) )
goto V_89;
return 0 ;
V_89:
F_15 ( V_2 ) ;
return - V_54 ;
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
return F_20 ( & V_90 ) ;
}
static void T_5 F_21 ( void )
{
F_22 ( & V_90 ) ;
}
