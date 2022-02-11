static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 , 0 ) ;
F_1 ( V_2 , V_7 , 0 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
F_1 ( V_2 , V_10 , 0 ) ;
F_1 ( V_2 , V_11 , 0 ) ;
F_1 ( V_2 , V_12 , 0 ) ;
F_1 ( V_2 , V_13 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( ! ( F_3 ( V_2 , V_11 ) & V_16 ) )
return 0 ;
F_7 ( 1 ) ;
}
return - V_17 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_18 ,
struct V_19 * V_20 )
{
T_1 V_21 , V_22 ;
T_1 V_23 , V_24 ;
T_1 V_25 ;
T_1 V_26 ;
unsigned long V_27 ;
switch ( V_2 -> V_28 ) {
case V_29 :
V_26 = 2 ;
break;
case V_30 :
V_26 = 3 ;
break;
default:
F_9 ( V_20 , L_1 ) ;
return - V_31 ;
}
V_27 = F_10 ( V_2 -> V_32 ) ;
V_22 = V_27 / 20000000 ;
if ( V_22 >= 1 << V_26 ) {
F_9 ( V_20 , L_2 , V_27 ) ;
return - V_31 ;
}
V_24 = V_27 / ( V_22 + 1 ) ;
V_23 = ( V_24 + 500000 ) / 1000000 * 285 ;
V_23 = ( V_23 + 500 ) / 1000 ;
for ( V_21 = 0 ; V_21 < 0x40 ; V_21 ++ ) {
V_25 = V_24 / ( 20 + ( V_21 * 8 ) + V_23 ) ;
if ( V_25 <= V_18 )
goto V_33;
}
F_9 ( V_20 , L_3 ) ;
return - V_31 ;
V_33:
F_11 ( V_20 , L_4 ,
V_25 , V_18 , F_10 ( V_2 -> V_32 ) , V_23 , V_22 , V_21 ) ;
V_2 -> V_34 = V_21 << V_26 | V_22 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_35 = ! ! F_13 ( V_2 ) ;
F_1 ( V_2 , V_13 , ( V_2 -> V_36 -> V_37 << 1 ) | V_35 ) ;
F_1 ( V_2 , V_12 , 0 ) ;
F_1 ( V_2 , V_11 , V_38 ) ;
F_1 ( V_2 , V_10 , V_35 ? V_39 : V_40 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_42 * V_36 = V_2 -> V_36 ;
if ( ! ( V_41 & V_43 ) )
return 0 ;
if ( V_41 & V_44 )
F_1 ( V_2 , V_11 , V_45 ) ;
if ( V_2 -> V_46 < V_36 -> V_47 ) {
F_1 ( V_2 , V_48 , V_36 -> V_49 [ V_2 -> V_46 ] ) ;
V_2 -> V_46 ++ ;
} else {
if ( V_2 -> V_50 & V_51 )
F_1 ( V_2 , V_11 , V_52 ) ;
else
return V_53 ;
}
F_1 ( V_2 , V_12 , V_54 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_42 * V_36 = V_2 -> V_36 ;
if ( ! ( V_41 & V_55 ) )
return 0 ;
if ( V_41 & V_44 ) {
} else if ( V_2 -> V_46 < V_36 -> V_47 ) {
V_36 -> V_49 [ V_2 -> V_46 ] = F_3 ( V_2 , V_48 ) ;
V_2 -> V_46 ++ ;
}
if ( V_2 -> V_46 + 1 >= V_36 -> V_47 )
F_1 ( V_2 , V_11 , V_52 ) ;
else
F_1 ( V_2 , V_11 , V_45 ) ;
F_1 ( V_2 , V_12 , V_56 ) ;
return 0 ;
}
static T_2 F_16 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
T_1 V_41 ;
F_17 ( & V_2 -> V_59 ) ;
V_41 = F_3 ( V_2 , V_12 ) ;
V_41 &= F_3 ( V_2 , V_10 ) ;
if ( V_41 & V_60 ) {
F_18 ( V_2 , ( V_53 | V_61 ) ) ;
goto V_62;
}
if ( V_41 & V_63 ) {
F_1 ( V_2 , V_11 , V_52 ) ;
F_1 ( V_2 , V_10 , V_64 ) ;
F_18 ( V_2 , V_65 ) ;
goto V_62;
}
if ( V_41 & V_66 ) {
F_18 ( V_2 , V_53 ) ;
goto V_62;
}
if ( F_13 ( V_2 ) )
F_18 ( V_2 , F_15 ( V_2 , V_41 ) ) ;
else
F_18 ( V_2 , F_14 ( V_2 , V_41 ) ) ;
V_62:
if ( F_19 ( V_2 , V_53 ) ) {
F_1 ( V_2 , V_10 , 0 ) ;
F_1 ( V_2 , V_12 , 0 ) ;
F_20 ( & V_2 -> V_67 ) ;
}
F_21 ( & V_2 -> V_59 ) ;
return V_68 ;
}
static int F_22 ( struct V_69 * V_70 ,
struct V_42 * V_71 ,
int V_72 )
{
struct V_1 * V_2 = F_23 ( V_70 ) ;
struct V_19 * V_20 = F_24 ( V_2 ) ;
unsigned long V_50 ;
int V_14 , V_73 , V_74 ;
F_25 ( V_20 ) ;
F_26 ( & V_2 -> V_59 , V_50 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 , V_75 , V_2 -> V_34 ) ;
F_27 ( & V_2 -> V_59 , V_50 ) ;
V_73 = F_6 ( V_2 ) ;
if ( V_73 < 0 )
goto V_62;
for ( V_14 = 0 ; V_14 < V_72 ; V_14 ++ ) {
if ( V_71 [ V_14 ] . V_47 == 0 ) {
V_73 = - V_76 ;
break;
}
F_26 ( & V_2 -> V_59 , V_50 ) ;
V_2 -> V_36 = & V_71 [ V_14 ] ;
V_2 -> V_46 = 0 ;
V_2 -> V_50 = 0 ;
if ( V_2 -> V_36 == & V_71 [ V_72 - 1 ] )
F_18 ( V_2 , V_51 ) ;
V_73 = F_12 ( V_2 ) ;
F_27 ( & V_2 -> V_59 , V_50 ) ;
if ( V_73 < 0 )
break;
V_74 = F_28 ( V_2 -> V_67 ,
F_19 ( V_2 , V_53 ) ,
5 * V_77 ) ;
if ( ! V_74 ) {
V_73 = - V_78 ;
break;
}
if ( F_19 ( V_2 , V_65 ) ) {
V_73 = - V_79 ;
break;
}
if ( F_19 ( V_2 , V_61 ) ) {
V_73 = - V_80 ;
break;
}
if ( F_19 ( V_2 , V_81 ) ) {
V_73 = - V_31 ;
break;
}
V_73 = V_14 + 1 ;
}
V_62:
F_29 ( V_20 ) ;
if ( V_73 < 0 && V_73 != - V_79 )
F_9 ( V_20 , L_5 , V_73 , V_2 -> V_50 ) ;
return V_73 ;
}
static T_1 F_30 ( struct V_69 * V_70 )
{
return V_82 | ( V_83 & ~ V_84 ) ;
}
static int F_31 ( struct V_85 * V_86 )
{
struct V_87 * V_88 = F_32 ( & V_86 -> V_20 ) ;
struct V_1 * V_2 ;
struct V_69 * V_70 ;
struct V_89 * V_90 ;
struct V_19 * V_20 = & V_86 -> V_20 ;
T_1 V_18 ;
int V_57 , V_73 ;
V_2 = F_33 ( V_20 , sizeof( struct V_1 ) , V_91 ) ;
if ( ! V_2 )
return - V_92 ;
V_2 -> V_32 = F_34 ( V_20 , NULL ) ;
if ( F_35 ( V_2 -> V_32 ) ) {
F_9 ( V_20 , L_6 ) ;
return F_36 ( V_2 -> V_32 ) ;
}
V_18 = 100000 ;
V_73 = F_37 ( V_20 -> V_93 , L_7 , & V_18 ) ;
if ( V_73 < 0 && V_88 && V_88 -> V_18 )
V_18 = V_88 -> V_18 ;
if ( V_86 -> V_20 . V_93 )
V_2 -> V_28 = ( long ) F_38 ( V_94 ,
V_20 ) -> V_95 ;
else
V_2 -> V_28 = F_39 ( V_86 ) -> V_96 ;
V_73 = F_8 ( V_2 , V_18 , V_20 ) ;
if ( V_73 < 0 )
return V_73 ;
V_90 = F_40 ( V_86 , V_97 , 0 ) ;
V_2 -> V_5 = F_41 ( V_20 , V_90 ) ;
if ( F_35 ( V_2 -> V_5 ) )
return F_36 ( V_2 -> V_5 ) ;
V_57 = F_42 ( V_86 , 0 ) ;
F_43 ( & V_2 -> V_67 ) ;
F_44 ( & V_2 -> V_59 ) ;
V_70 = & V_2 -> V_70 ;
V_70 -> V_98 = V_86 -> V_99 ;
V_70 -> V_100 = & V_101 ;
V_70 -> V_102 = V_103 ;
V_70 -> V_104 = 3 ;
V_70 -> V_20 . V_105 = V_20 ;
V_70 -> V_20 . V_93 = V_20 -> V_93 ;
F_45 ( V_70 , V_2 ) ;
F_46 ( V_70 -> V_106 , V_86 -> V_106 , sizeof( V_70 -> V_106 ) ) ;
V_73 = F_47 ( V_20 , V_57 , F_16 , 0 ,
F_48 ( V_20 ) , V_2 ) ;
if ( V_73 < 0 ) {
F_9 ( V_20 , L_8 , V_57 ) ;
return V_73 ;
}
V_73 = F_49 ( V_70 ) ;
if ( V_73 < 0 ) {
F_9 ( V_20 , L_9 , V_73 ) ;
return V_73 ;
}
F_50 ( V_20 ) ;
F_51 ( V_86 , V_2 ) ;
F_52 ( V_20 , L_10 ) ;
return 0 ;
}
static int F_53 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_54 ( V_86 ) ;
struct V_19 * V_20 = & V_86 -> V_20 ;
F_55 ( & V_2 -> V_70 ) ;
F_56 ( V_20 ) ;
return 0 ;
}
