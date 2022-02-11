static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
F_2 ( V_4 ) ;
unsigned V_5 , V_6 , V_7 ;
F_3 ( V_2 -> V_8 , L_1 , V_3 , V_2 -> V_9 , V_3 ) ;
V_7 = V_2 -> V_9 [ 2 ] ;
V_5 = V_6 = V_7 + V_10 ;
if ( V_6 >= V_3 ) {
F_4 ( V_2 -> V_8 , L_2 , V_7 ) ;
} else {
if ( V_7 > 0 )
F_5 ( V_2 -> V_8 , L_3 ,
V_7 ) ;
do {
V_4 . V_11 = V_2 -> V_9 [ V_5 ] * 85333 ;
V_4 . V_12 = V_5 & 1 ;
F_6 ( V_2 -> V_13 , & V_4 ) ;
if ( ++ V_5 == V_3 )
V_5 = V_10 ;
} while ( V_5 != V_6 );
V_4 . V_11 = V_2 -> V_13 -> V_14 ;
V_4 . V_12 = false ;
F_6 ( V_2 -> V_13 , & V_4 ) ;
F_7 ( V_2 -> V_13 ) ;
}
F_8 ( V_2 , V_15 ) ;
}
static void F_9 ( struct V_16 * V_16 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 = V_16 -> V_19 ;
V_18 = (struct V_17 * ) V_16 -> V_20 ;
switch ( V_16 -> V_21 ) {
case 0 :
if ( V_18 -> V_22 == V_23 &&
V_16 -> V_24 > V_10 )
F_1 ( V_2 , V_16 -> V_24 ) ;
else
F_10 ( & V_2 -> V_25 , V_26 + F_11 ( 50 ) ) ;
break;
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
F_12 ( V_16 ) ;
return;
default:
F_5 ( V_2 -> V_8 , L_4 , V_16 -> V_21 ) ;
F_8 ( V_2 , V_15 ) ;
break;
}
}
static void F_8 ( struct V_1 * V_2 , int V_31 )
{
int V_32 ;
V_2 -> V_33 . V_22 = V_31 ;
V_2 -> V_16 -> V_34 = 0 ;
V_32 = F_13 ( V_2 -> V_16 , V_35 ) ;
if ( V_32 )
F_4 ( V_2 -> V_8 , L_5 , V_32 ) ;
}
static void F_14 ( unsigned long V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
F_8 ( V_2 , V_23 ) ;
}
static int F_15 ( struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_1 * V_2 ;
struct V_47 * V_13 ;
int V_32 = - V_48 ;
V_42 = F_16 ( V_38 ) ;
V_44 = V_38 -> V_49 ;
if ( V_44 -> V_50 . V_51 != 1 ) {
F_4 ( & V_38 -> V_8 , L_6 ) ;
return - V_52 ;
}
V_46 = & V_44 -> V_53 [ 0 ] . V_50 ;
if ( ! F_17 ( V_46 ) || ! F_18 ( V_46 ) ) {
F_4 ( & V_38 -> V_8 , L_7 ) ;
return - V_52 ;
}
V_2 = F_19 ( & V_38 -> V_8 , sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_8 = & V_38 -> V_8 ;
F_20 ( & V_2 -> V_25 , F_14 , ( unsigned long ) V_2 ) ;
V_2 -> V_33 . V_22 = V_23 ;
V_2 -> V_33 . V_55 = V_56 | V_57 ;
V_2 -> V_33 . V_58 = F_21 ( sizeof( V_2 -> V_9 ) ) ;
V_2 -> V_16 = F_22 ( 0 , V_54 ) ;
if ( ! V_2 -> V_16 )
goto V_59;
F_23 ( V_2 -> V_16 , V_42 ,
F_24 ( V_42 , 0 ) , ( V_60 * ) & V_2 -> V_33 ,
V_2 -> V_9 , sizeof( V_2 -> V_9 ) , F_9 , V_2 ) ;
F_25 ( V_42 , V_2 -> V_61 , sizeof( V_2 -> V_61 ) ) ;
V_13 = F_26 ( V_62 ) ;
if ( ! V_13 )
goto V_59;
V_13 -> V_63 = V_64 ;
V_13 -> V_65 = V_2 -> V_61 ;
F_27 ( V_42 , & V_13 -> V_66 ) ;
V_13 -> V_8 . V_67 = & V_38 -> V_8 ;
V_13 -> V_68 = V_69 & ~ ( V_70 |
V_71 | V_72 | V_73 |
V_74 | V_75 | V_76 |
V_77 | V_78 | V_79 ) ;
V_13 -> V_80 = V_2 ;
V_13 -> V_81 = V_82 ;
V_13 -> V_83 = V_84 ;
V_13 -> V_14 = F_28 ( 100 ) ;
V_13 -> V_85 = 85333 ;
V_2 -> V_13 = V_13 ;
V_32 = F_29 ( V_13 ) ;
if ( V_32 ) {
F_4 ( & V_38 -> V_8 , L_8 , V_32 ) ;
goto V_59;
}
F_30 ( V_38 , V_2 ) ;
F_8 ( V_2 , V_15 ) ;
return 0 ;
V_59:
F_31 ( V_2 -> V_13 ) ;
F_32 ( V_2 -> V_16 ) ;
F_33 ( & V_2 -> V_25 ) ;
return V_32 ;
}
static void F_34 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_35 ( V_38 ) ;
F_36 ( V_2 -> V_13 ) ;
F_37 ( & V_2 -> V_25 ) ;
F_30 ( V_38 , NULL ) ;
F_38 ( V_2 -> V_16 ) ;
F_32 ( V_2 -> V_16 ) ;
}
