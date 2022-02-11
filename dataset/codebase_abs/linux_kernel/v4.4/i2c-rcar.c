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
}
static int F_6 ( struct V_1 * V_2 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( ! ( F_3 ( V_2 , V_7 ) & V_12 ) )
return 0 ;
F_7 ( 1 ) ;
}
return - V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_14 ,
struct V_15 * V_16 )
{
T_1 V_17 , V_18 ;
T_1 V_19 , V_20 ;
T_1 V_21 ;
T_1 V_22 ;
unsigned long V_23 ;
switch ( V_2 -> V_24 ) {
case V_25 :
V_22 = 2 ;
break;
case V_26 :
case V_27 :
V_22 = 3 ;
break;
default:
F_9 ( V_16 , L_1 ) ;
return - V_28 ;
}
V_23 = F_10 ( V_2 -> V_29 ) ;
V_18 = V_23 / 20000000 ;
if ( V_18 >= 1U << V_22 ) {
F_9 ( V_16 , L_2 , V_23 ) ;
return - V_28 ;
}
V_20 = V_23 / ( V_18 + 1 ) ;
V_19 = ( V_20 + 500000 ) / 1000000 * 285 ;
V_19 = ( V_19 + 500 ) / 1000 ;
for ( V_17 = 0 ; V_17 < 0x40 ; V_17 ++ ) {
V_21 = V_20 / ( 20 + ( V_17 * 8 ) + V_19 ) ;
if ( V_21 <= V_14 )
goto V_30;
}
F_9 ( V_16 , L_3 ) ;
return - V_28 ;
V_30:
F_11 ( V_16 , L_4 ,
V_21 , V_14 , F_10 ( V_2 -> V_29 ) , V_19 , V_18 , V_17 ) ;
V_2 -> V_31 = V_17 << V_22 | V_18 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_32 = ! ! F_13 ( V_2 ) ;
F_1 ( V_2 , V_9 , ( V_2 -> V_33 -> V_34 << 1 ) | V_32 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
F_1 ( V_2 , V_7 , V_35 ) ;
F_1 ( V_2 , V_6 , V_32 ? V_36 : V_37 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_38 )
{
struct V_39 * V_33 = V_2 -> V_33 ;
if ( ! ( V_38 & V_40 ) )
return 0 ;
if ( V_38 & V_41 )
F_1 ( V_2 , V_7 , V_42 ) ;
if ( V_2 -> V_43 < V_33 -> V_44 ) {
F_1 ( V_2 , V_45 , V_33 -> V_46 [ V_2 -> V_43 ] ) ;
V_2 -> V_43 ++ ;
} else {
if ( V_2 -> V_47 & V_48 )
F_1 ( V_2 , V_7 , V_49 ) ;
else
return V_50 ;
}
F_1 ( V_2 , V_8 , V_51 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_38 )
{
struct V_39 * V_33 = V_2 -> V_33 ;
if ( ! ( V_38 & V_52 ) )
return 0 ;
if ( V_38 & V_41 ) {
} else if ( V_2 -> V_43 < V_33 -> V_44 ) {
V_33 -> V_46 [ V_2 -> V_43 ] = F_3 ( V_2 , V_45 ) ;
V_2 -> V_43 ++ ;
}
if ( V_2 -> V_43 + 1 >= V_33 -> V_44 )
F_1 ( V_2 , V_7 , V_49 ) ;
else
F_1 ( V_2 , V_7 , V_42 ) ;
F_1 ( V_2 , V_8 , V_53 ) ;
return 0 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
T_1 V_54 , V_55 ;
T_2 V_56 ;
V_54 = F_3 ( V_2 , V_57 ) & 0xff ;
V_55 = V_54 & F_3 ( V_2 , V_58 ) ;
if ( ! V_55 )
return false ;
if ( V_55 & V_59 ) {
if ( V_54 & V_60 ) {
F_17 ( V_2 -> V_61 , V_62 , & V_56 ) ;
F_1 ( V_2 , V_45 , V_56 ) ;
F_1 ( V_2 , V_58 , V_63 | V_64 | V_59 ) ;
} else {
F_17 ( V_2 -> V_61 , V_65 , & V_56 ) ;
F_3 ( V_2 , V_45 ) ;
F_1 ( V_2 , V_58 , V_66 | V_64 | V_59 ) ;
}
F_1 ( V_2 , V_57 , ~ V_59 & 0xff ) ;
}
if ( V_55 & V_64 ) {
F_17 ( V_2 -> V_61 , V_67 , & V_56 ) ;
F_1 ( V_2 , V_58 , V_59 | V_64 ) ;
F_1 ( V_2 , V_57 , ~ V_64 & 0xff ) ;
}
if ( V_55 & V_66 ) {
int V_68 ;
V_56 = F_3 ( V_2 , V_45 ) ;
V_68 = F_17 ( V_2 -> V_61 , V_69 , & V_56 ) ;
F_1 ( V_2 , V_70 , V_71 | V_72 | ( V_68 < 0 ? V_73 : 0 ) ) ;
F_1 ( V_2 , V_57 , ~ V_66 & 0xff ) ;
}
if ( V_55 & V_63 ) {
F_17 ( V_2 -> V_61 , V_74 , & V_56 ) ;
F_1 ( V_2 , V_45 , V_56 ) ;
F_1 ( V_2 , V_57 , ~ V_63 & 0xff ) ;
}
return true ;
}
static T_3 F_18 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
T_3 V_77 = V_78 ;
T_1 V_38 ;
F_19 ( & V_2 -> V_79 ) ;
if ( F_16 ( V_2 ) )
goto exit;
V_38 = F_3 ( V_2 , V_8 ) ;
V_38 &= F_3 ( V_2 , V_6 ) ;
if ( ! V_38 ) {
V_77 = V_80 ;
goto exit;
}
if ( V_38 & V_81 ) {
F_20 ( V_2 , ( V_50 | V_82 ) ) ;
goto V_83;
}
if ( V_38 & V_84 ) {
F_1 ( V_2 , V_7 , V_49 ) ;
F_1 ( V_2 , V_6 , V_85 ) ;
F_20 ( V_2 , V_86 ) ;
goto V_83;
}
if ( V_38 & V_87 ) {
F_20 ( V_2 , V_50 ) ;
goto V_83;
}
if ( F_13 ( V_2 ) )
F_20 ( V_2 , F_15 ( V_2 , V_38 ) ) ;
else
F_20 ( V_2 , F_14 ( V_2 , V_38 ) ) ;
V_83:
if ( F_21 ( V_2 , V_50 ) ) {
F_1 ( V_2 , V_6 , 0 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
F_22 ( & V_2 -> V_88 ) ;
}
exit:
F_23 ( & V_2 -> V_79 ) ;
return V_77 ;
}
static int F_24 ( struct V_89 * V_90 ,
struct V_39 * V_91 ,
int V_92 )
{
struct V_1 * V_2 = F_25 ( V_90 ) ;
struct V_15 * V_16 = F_26 ( V_2 ) ;
unsigned long V_47 ;
int V_10 , V_68 ;
long V_93 ;
F_27 ( V_16 ) ;
F_28 ( & V_2 -> V_79 , V_47 ) ;
F_5 ( V_2 ) ;
F_1 ( V_2 , V_94 , V_2 -> V_31 ) ;
F_29 ( & V_2 -> V_79 , V_47 ) ;
V_68 = F_6 ( V_2 ) ;
if ( V_68 < 0 )
goto V_83;
for ( V_10 = 0 ; V_10 < V_92 ; V_10 ++ ) {
if ( V_91 [ V_10 ] . V_44 == 0 ) {
V_68 = - V_95 ;
break;
}
F_28 ( & V_2 -> V_79 , V_47 ) ;
V_2 -> V_33 = & V_91 [ V_10 ] ;
V_2 -> V_43 = 0 ;
V_2 -> V_47 = 0 ;
if ( V_10 == V_92 - 1 )
F_20 ( V_2 , V_48 ) ;
F_12 ( V_2 ) ;
F_29 ( & V_2 -> V_79 , V_47 ) ;
V_93 = F_30 ( V_2 -> V_88 ,
F_21 ( V_2 , V_50 ) ,
V_90 -> V_93 ) ;
if ( ! V_93 ) {
V_68 = - V_96 ;
break;
}
if ( F_21 ( V_2 , V_86 ) ) {
V_68 = - V_97 ;
break;
}
if ( F_21 ( V_2 , V_82 ) ) {
V_68 = - V_98 ;
break;
}
if ( F_21 ( V_2 , V_99 ) ) {
V_68 = - V_28 ;
break;
}
V_68 = V_10 + 1 ;
}
V_83:
F_31 ( V_16 ) ;
if ( V_68 < 0 && V_68 != - V_97 )
F_9 ( V_16 , L_5 , V_68 , V_2 -> V_47 ) ;
return V_68 ;
}
static int F_32 ( struct V_100 * V_61 )
{
struct V_1 * V_2 = F_25 ( V_61 -> V_101 ) ;
if ( V_2 -> V_61 )
return - V_13 ;
if ( V_61 -> V_47 & V_102 )
return - V_103 ;
F_27 ( F_26 ( V_2 ) ) ;
V_2 -> V_61 = V_61 ;
F_1 ( V_2 , V_104 , V_61 -> V_34 ) ;
F_1 ( V_2 , V_57 , 0 ) ;
F_1 ( V_2 , V_58 , V_59 | V_64 ) ;
F_1 ( V_2 , V_70 , V_71 | V_72 ) ;
return 0 ;
}
static int F_33 ( struct V_100 * V_61 )
{
struct V_1 * V_2 = F_25 ( V_61 -> V_101 ) ;
F_34 ( ! V_2 -> V_61 ) ;
F_1 ( V_2 , V_58 , 0 ) ;
F_1 ( V_2 , V_70 , 0 ) ;
V_2 -> V_61 = NULL ;
F_31 ( F_26 ( V_2 ) ) ;
return 0 ;
}
static T_1 F_35 ( struct V_89 * V_90 )
{
return V_105 | V_106 |
( V_107 & ~ V_108 ) ;
}
static int F_36 ( struct V_109 * V_110 )
{
struct V_1 * V_2 ;
struct V_89 * V_90 ;
struct V_111 * V_112 ;
struct V_15 * V_16 = & V_110 -> V_16 ;
T_1 V_14 ;
int V_75 , V_68 ;
V_2 = F_37 ( V_16 , sizeof( struct V_1 ) , V_113 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_29 = F_38 ( V_16 , NULL ) ;
if ( F_39 ( V_2 -> V_29 ) ) {
F_9 ( V_16 , L_6 ) ;
return F_40 ( V_2 -> V_29 ) ;
}
V_14 = 100000 ;
F_41 ( V_16 -> V_115 , L_7 , & V_14 ) ;
V_2 -> V_24 = (enum V_116 ) F_42 ( V_117 , V_16 ) -> V_118 ;
V_68 = F_8 ( V_2 , V_14 , V_16 ) ;
if ( V_68 < 0 )
return V_68 ;
V_112 = F_43 ( V_110 , V_119 , 0 ) ;
V_2 -> V_5 = F_44 ( V_16 , V_112 ) ;
if ( F_39 ( V_2 -> V_5 ) )
return F_40 ( V_2 -> V_5 ) ;
V_75 = F_45 ( V_110 , 0 ) ;
F_46 ( & V_2 -> V_88 ) ;
F_47 ( & V_2 -> V_79 ) ;
V_90 = & V_2 -> V_90 ;
V_90 -> V_120 = V_110 -> V_121 ;
V_90 -> V_122 = & V_123 ;
V_90 -> V_124 = V_125 ;
V_90 -> V_126 = 3 ;
V_90 -> V_16 . V_127 = V_16 ;
V_90 -> V_16 . V_115 = V_16 -> V_115 ;
F_48 ( V_90 , V_2 ) ;
F_49 ( V_90 -> V_128 , V_110 -> V_128 , sizeof( V_90 -> V_128 ) ) ;
V_68 = F_50 ( V_16 , V_75 , F_18 , 0 ,
F_51 ( V_16 ) , V_2 ) ;
if ( V_68 < 0 ) {
F_9 ( V_16 , L_8 , V_75 ) ;
return V_68 ;
}
F_52 ( V_16 ) ;
F_53 ( V_110 , V_2 ) ;
V_68 = F_54 ( V_90 ) ;
if ( V_68 < 0 ) {
F_9 ( V_16 , L_9 , V_68 ) ;
F_55 ( V_16 ) ;
return V_68 ;
}
F_56 ( V_16 , L_10 ) ;
return 0 ;
}
static int F_57 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = F_58 ( V_110 ) ;
struct V_15 * V_16 = & V_110 -> V_16 ;
F_59 ( & V_2 -> V_90 ) ;
F_55 ( V_16 ) ;
return 0 ;
}
