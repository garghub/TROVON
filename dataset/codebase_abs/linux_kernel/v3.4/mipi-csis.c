static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static const struct V_5 * F_3 (
struct V_6 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_4 ( V_9 ) ; V_8 ++ )
if ( V_7 -> V_10 == V_9 [ V_8 ] . V_10 )
return & V_9 [ V_8 ] ;
return NULL ;
}
static void F_5 ( struct V_1 * V_11 , bool V_12 )
{
T_1 V_13 = F_6 ( V_11 , V_14 ) ;
V_13 = V_12 ? V_13 | V_15 :
V_13 & ~ V_15 ;
F_7 ( V_11 , V_14 , V_13 ) ;
}
static void F_8 ( struct V_1 * V_11 )
{
T_1 V_13 = F_6 ( V_11 , V_16 ) ;
F_7 ( V_11 , V_16 , V_13 | V_17 ) ;
F_9 ( 10 ) ;
}
static void F_10 ( struct V_1 * V_11 , int V_12 )
{
T_1 V_13 ;
V_13 = F_6 ( V_11 , V_16 ) ;
if ( V_12 )
V_13 |= V_18 ;
else
V_13 &= ~ V_18 ;
F_7 ( V_11 , V_16 , V_13 ) ;
V_13 = F_6 ( V_11 , V_19 ) ;
if ( V_12 )
V_13 |= V_20 ;
else
V_13 &= ~ V_20 ;
F_7 ( V_11 , V_19 , V_13 ) ;
}
static void F_11 ( struct V_1 * V_11 )
{
struct V_6 * V_7 = & V_11 -> V_21 ;
T_1 V_13 ;
F_12 ( 1 , V_22 , & V_11 -> V_4 , L_1 ,
V_7 -> V_10 , V_7 -> V_23 , V_7 -> V_24 ) ;
V_13 = F_6 ( V_11 , V_25 ) ;
V_13 = ( V_13 & ~ V_26 ) | V_11 -> V_27 -> V_28 ;
F_7 ( V_11 , V_25 , V_13 ) ;
V_13 = ( V_7 -> V_23 << 16 ) | V_7 -> V_24 ;
F_7 ( V_11 , V_29 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_11 , int V_30 )
{
T_1 V_13 = F_6 ( V_11 , V_19 ) ;
V_13 = ( V_13 & ~ V_31 ) | ( V_30 << 27 ) ;
F_7 ( V_11 , V_19 , V_13 ) ;
}
static void F_14 ( struct V_1 * V_11 )
{
struct V_32 * V_33 = V_11 -> V_34 -> V_35 . V_36 ;
T_1 V_13 ;
V_13 = F_6 ( V_11 , V_25 ) ;
V_13 = ( V_13 & ~ V_37 ) | ( V_33 -> V_38 - 1 ) ;
F_7 ( V_11 , V_25 , V_13 ) ;
F_11 ( V_11 ) ;
F_13 ( V_11 , V_33 -> V_39 ) ;
V_13 = F_6 ( V_11 , V_16 ) ;
if ( V_33 -> V_40 == 32 )
V_13 |= V_41 ;
else
V_13 &= ~ V_41 ;
V_13 &= ~ V_42 ;
F_7 ( V_11 , V_16 , V_13 ) ;
V_13 = F_6 ( V_11 , V_16 ) ;
F_7 ( V_11 , V_16 , V_13 | V_43 ) ;
}
static void F_15 ( struct V_1 * V_11 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_44 ; V_8 ++ ) {
if ( F_16 ( V_11 -> clock [ V_8 ] ) )
continue;
F_17 ( V_11 -> clock [ V_8 ] ) ;
F_18 ( V_11 -> clock [ V_8 ] ) ;
V_11 -> clock [ V_8 ] = NULL ;
}
}
static int F_19 ( struct V_1 * V_11 )
{
struct V_45 * V_35 = & V_11 -> V_34 -> V_35 ;
int V_8 , V_46 ;
for ( V_8 = 0 ; V_8 < V_44 ; V_8 ++ ) {
V_11 -> clock [ V_8 ] = F_20 ( V_35 , V_47 [ V_8 ] ) ;
if ( F_21 ( V_11 -> clock [ V_8 ] ) )
goto V_48;
V_46 = F_22 ( V_11 -> clock [ V_8 ] ) ;
if ( V_46 < 0 ) {
F_18 ( V_11 -> clock [ V_8 ] ) ;
V_11 -> clock [ V_8 ] = NULL ;
goto V_48;
}
}
return 0 ;
V_48:
F_15 ( V_11 ) ;
F_23 ( V_35 , L_2 , V_47 [ V_8 ] ) ;
return - V_49 ;
}
static int F_24 ( struct V_2 * V_4 , int V_12 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_45 * V_35 = & V_11 -> V_34 -> V_35 ;
if ( V_12 )
return F_25 ( V_35 ) ;
return F_26 ( V_35 ) ;
}
static void F_27 ( struct V_1 * V_11 )
{
F_8 ( V_11 ) ;
F_14 ( V_11 ) ;
F_10 ( V_11 , true ) ;
F_5 ( V_11 , true ) ;
}
static void F_28 ( struct V_1 * V_11 )
{
F_5 ( V_11 , false ) ;
F_10 ( V_11 , false ) ;
}
static int F_29 ( struct V_2 * V_4 , int V_50 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_46 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_3 ,
V_51 , V_50 , V_11 -> V_52 ) ;
if ( V_50 ) {
V_46 = F_25 ( & V_11 -> V_34 -> V_35 ) ;
if ( V_46 && V_46 != 1 )
return V_46 ;
}
F_30 ( & V_11 -> V_53 ) ;
if ( V_50 ) {
if ( V_11 -> V_52 & V_54 ) {
V_46 = - V_55 ;
goto V_56;
}
F_27 ( V_11 ) ;
V_11 -> V_52 |= V_57 ;
} else {
F_28 ( V_11 ) ;
V_11 -> V_52 &= ~ V_57 ;
}
V_56:
F_31 ( & V_11 -> V_53 ) ;
if ( ! V_50 )
F_32 ( & V_11 -> V_34 -> V_35 ) ;
return V_46 == 1 ? 0 : V_46 ;
}
static int F_33 ( struct V_2 * V_4 ,
struct V_58 * V_59 ,
struct V_60 * V_10 )
{
if ( V_10 -> V_61 >= F_4 ( V_9 ) )
return - V_62 ;
V_10 -> V_10 = V_9 [ V_10 -> V_61 ] . V_10 ;
return 0 ;
}
static struct V_5 const * F_34 (
struct V_6 * V_7 )
{
struct V_5 const * V_27 ;
V_27 = F_3 ( V_7 ) ;
if ( V_27 == NULL )
V_27 = & V_9 [ 0 ] ;
V_7 -> V_10 = V_27 -> V_10 ;
F_35 ( & V_7 -> V_23 , 1 , V_63 ,
V_27 -> V_64 ,
& V_7 -> V_24 , 1 , V_65 , 1 ,
0 ) ;
return V_27 ;
}
static struct V_6 * F_36 (
struct V_1 * V_11 , struct V_58 * V_59 ,
T_1 V_66 , enum V_67 V_68 )
{
if ( V_68 == V_69 )
return V_59 ? F_37 ( V_59 , V_66 ) : NULL ;
return & V_11 -> V_21 ;
}
static int F_38 ( struct V_2 * V_4 , struct V_58 * V_59 ,
struct V_70 * V_71 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_5 const * V_27 ;
struct V_6 * V_7 ;
if ( V_71 -> V_66 != V_72 && V_71 -> V_66 != V_73 )
return - V_62 ;
V_7 = F_36 ( V_11 , V_59 , V_71 -> V_66 , V_71 -> V_68 ) ;
if ( V_71 -> V_66 == V_72 ) {
if ( V_7 ) {
F_30 ( & V_11 -> V_53 ) ;
V_71 -> V_21 = * V_7 ;
F_31 ( & V_11 -> V_53 ) ;
}
return 0 ;
}
V_27 = F_34 ( & V_71 -> V_21 ) ;
if ( V_7 ) {
F_30 ( & V_11 -> V_53 ) ;
* V_7 = V_71 -> V_21 ;
if ( V_71 -> V_68 == V_74 )
V_11 -> V_27 = V_27 ;
F_31 ( & V_11 -> V_53 ) ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_4 , struct V_58 * V_59 ,
struct V_70 * V_71 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_6 * V_7 ;
if ( V_71 -> V_66 != V_72 && V_71 -> V_66 != V_73 )
return - V_62 ;
V_7 = F_36 ( V_11 , V_59 , V_71 -> V_66 , V_71 -> V_68 ) ;
if ( ! V_7 )
return - V_62 ;
F_30 ( & V_11 -> V_53 ) ;
V_71 -> V_21 = * V_7 ;
F_31 ( & V_11 -> V_53 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_4 , struct V_58 * V_59 )
{
struct V_6 * V_21 = F_37 ( V_59 , 0 ) ;
V_21 -> V_75 = V_76 ;
V_21 -> V_10 = V_9 [ 0 ] . V_10 ;
V_21 -> V_23 = V_77 ;
V_21 -> V_24 = V_78 ;
V_21 -> V_79 = V_80 ;
return 0 ;
}
static T_2 F_41 ( int V_81 , void * V_82 )
{
struct V_1 * V_11 = V_82 ;
T_1 V_13 ;
V_13 = F_6 ( V_11 , V_83 ) ;
F_7 ( V_11 , V_83 , V_13 ) ;
return V_84 ;
}
static int T_3 F_42 ( struct V_85 * V_34 )
{
struct V_32 * V_33 ;
struct V_86 * V_87 ;
struct V_1 * V_11 ;
int V_46 = - V_88 ;
int V_8 ;
V_11 = F_43 ( & V_34 -> V_35 , sizeof( * V_11 ) , V_89 ) ;
if ( ! V_11 )
return - V_88 ;
F_44 ( & V_11 -> V_53 ) ;
V_11 -> V_34 = V_34 ;
V_33 = V_34 -> V_35 . V_36 ;
if ( V_33 == NULL || V_33 -> V_90 == NULL ) {
F_23 ( & V_34 -> V_35 , L_4 ) ;
return - V_62 ;
}
if ( ( V_34 -> V_91 == 1 && V_33 -> V_38 > V_92 ) ||
V_33 -> V_38 > V_93 ) {
F_23 ( & V_34 -> V_35 , L_5 ,
V_33 -> V_38 ) ;
return - V_62 ;
}
V_87 = F_45 ( V_34 , V_94 , 0 ) ;
V_11 -> V_95 = F_46 ( & V_34 -> V_35 , V_87 ) ;
if ( V_11 -> V_95 == NULL ) {
F_23 ( & V_34 -> V_35 , L_6 ) ;
return - V_49 ;
}
V_11 -> V_81 = F_47 ( V_34 , 0 ) ;
if ( V_11 -> V_81 < 0 ) {
F_23 ( & V_34 -> V_35 , L_7 ) ;
return V_11 -> V_81 ;
}
for ( V_8 = 0 ; V_8 < V_96 ; V_8 ++ )
V_11 -> V_97 [ V_8 ] . V_98 = V_99 [ V_8 ] ;
V_46 = F_48 ( & V_34 -> V_35 , V_96 ,
V_11 -> V_97 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_19 ( V_11 ) ;
if ( V_46 )
goto V_100;
F_49 ( V_11 -> clock [ V_101 ] ) ;
if ( V_33 -> V_102 )
F_50 ( V_11 -> clock [ V_101 ] , V_33 -> V_102 ) ;
else
F_51 ( & V_34 -> V_35 , L_8 ) ;
V_46 = F_52 ( & V_34 -> V_35 , V_11 -> V_81 , F_41 ,
0 , F_53 ( & V_34 -> V_35 ) , V_11 ) ;
if ( V_46 ) {
F_23 ( & V_34 -> V_35 , L_9 ) ;
goto V_103;
}
F_54 ( & V_11 -> V_4 , & V_104 ) ;
V_11 -> V_4 . V_105 = V_106 ;
F_55 ( V_11 -> V_4 . V_107 , F_53 ( & V_34 -> V_35 ) , sizeof( V_11 -> V_4 . V_107 ) ) ;
V_11 -> V_4 . V_52 |= V_108 ;
V_11 -> V_27 = & V_9 [ 0 ] ;
V_11 -> V_21 . V_10 = V_9 [ 0 ] . V_10 ;
V_11 -> V_21 . V_23 = V_77 ;
V_11 -> V_21 . V_24 = V_78 ;
V_11 -> V_109 [ V_73 ] . V_52 = V_110 ;
V_11 -> V_109 [ V_72 ] . V_52 = V_111 ;
V_46 = F_56 ( & V_11 -> V_4 . V_112 ,
V_113 , V_11 -> V_109 , 0 ) ;
if ( V_46 < 0 )
goto V_100;
F_57 ( & V_11 -> V_4 , V_34 ) ;
F_58 ( V_34 , & V_11 -> V_4 ) ;
F_59 ( & V_34 -> V_35 ) ;
return 0 ;
V_103:
F_60 ( V_96 , V_11 -> V_97 ) ;
V_100:
F_61 ( V_11 -> clock [ V_101 ] ) ;
F_15 ( V_11 ) ;
return V_46 ;
}
static int F_62 ( struct V_45 * V_35 , bool V_114 )
{
struct V_32 * V_33 = V_35 -> V_36 ;
struct V_85 * V_34 = F_63 ( V_35 ) ;
struct V_2 * V_4 = F_64 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_46 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_10 ,
V_51 , V_11 -> V_52 ) ;
F_30 ( & V_11 -> V_53 ) ;
if ( V_11 -> V_52 & V_115 ) {
F_28 ( V_11 ) ;
V_46 = V_33 -> V_90 ( V_11 -> V_34 , false ) ;
if ( V_46 )
goto V_56;
V_46 = F_65 ( V_96 ,
V_11 -> V_97 ) ;
if ( V_46 )
goto V_56;
F_61 ( V_11 -> clock [ V_116 ] ) ;
V_11 -> V_52 &= ~ V_115 ;
if ( ! V_114 )
V_11 -> V_52 |= V_54 ;
}
V_56:
F_31 ( & V_11 -> V_53 ) ;
return V_46 ? - V_117 : 0 ;
}
static int F_66 ( struct V_45 * V_35 , bool V_114 )
{
struct V_32 * V_33 = V_35 -> V_36 ;
struct V_85 * V_34 = F_63 ( V_35 ) ;
struct V_2 * V_4 = F_64 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_46 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_10 ,
V_51 , V_11 -> V_52 ) ;
F_30 ( & V_11 -> V_53 ) ;
if ( ! V_114 && ! ( V_11 -> V_52 & V_54 ) )
goto V_56;
if ( ! ( V_11 -> V_52 & V_115 ) ) {
V_46 = F_67 ( V_96 ,
V_11 -> V_97 ) ;
if ( V_46 )
goto V_56;
V_46 = V_33 -> V_90 ( V_11 -> V_34 , true ) ;
if ( ! V_46 ) {
V_11 -> V_52 |= V_115 ;
} else {
F_65 ( V_96 ,
V_11 -> V_97 ) ;
goto V_56;
}
F_49 ( V_11 -> clock [ V_116 ] ) ;
}
if ( V_11 -> V_52 & V_57 )
F_27 ( V_11 ) ;
V_11 -> V_52 &= ~ V_54 ;
V_56:
F_31 ( & V_11 -> V_53 ) ;
return V_46 ? - V_117 : 0 ;
}
static int F_68 ( struct V_45 * V_35 )
{
return F_62 ( V_35 , false ) ;
}
static int F_69 ( struct V_45 * V_35 )
{
return F_66 ( V_35 , false ) ;
}
static int F_70 ( struct V_45 * V_35 )
{
return F_62 ( V_35 , true ) ;
}
static int F_71 ( struct V_45 * V_35 )
{
return F_66 ( V_35 , true ) ;
}
static int T_4 F_72 ( struct V_85 * V_34 )
{
struct V_2 * V_4 = F_64 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_73 ( & V_34 -> V_35 ) ;
F_62 ( & V_34 -> V_35 , false ) ;
F_61 ( V_11 -> clock [ V_101 ] ) ;
F_74 ( & V_34 -> V_35 ) ;
F_15 ( V_11 ) ;
F_60 ( V_96 , V_11 -> V_97 ) ;
F_75 ( & V_11 -> V_4 . V_112 ) ;
return 0 ;
}
static int T_5 F_76 ( void )
{
return F_77 ( & V_118 , F_42 ) ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_118 ) ;
}
