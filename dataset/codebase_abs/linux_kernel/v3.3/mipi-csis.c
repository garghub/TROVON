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
for ( V_8 = 0 ; V_8 < V_44 ; V_8 ++ )
if ( ! F_16 ( V_11 -> clock [ V_8 ] ) )
F_17 ( V_11 -> clock [ V_8 ] ) ;
}
static int F_18 ( struct V_1 * V_11 )
{
struct V_45 * V_35 = & V_11 -> V_34 -> V_35 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_44 ; V_8 ++ ) {
V_11 -> clock [ V_8 ] = F_19 ( V_35 , V_46 [ V_8 ] ) ;
if ( F_20 ( V_11 -> clock [ V_8 ] ) ) {
F_15 ( V_11 ) ;
F_21 ( V_35 , L_2 ,
V_46 [ V_8 ] ) ;
return - V_47 ;
}
}
return 0 ;
}
static int F_22 ( struct V_2 * V_4 , int V_12 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_45 * V_35 = & V_11 -> V_34 -> V_35 ;
if ( V_12 )
return F_23 ( V_35 ) ;
return F_24 ( V_35 ) ;
}
static void F_25 ( struct V_1 * V_11 )
{
F_8 ( V_11 ) ;
F_14 ( V_11 ) ;
F_10 ( V_11 , true ) ;
F_5 ( V_11 , true ) ;
}
static void F_26 ( struct V_1 * V_11 )
{
F_5 ( V_11 , false ) ;
F_10 ( V_11 , false ) ;
}
static int F_27 ( struct V_2 * V_4 , int V_48 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_49 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_3 ,
V_50 , V_48 , V_11 -> V_51 ) ;
if ( V_48 ) {
V_49 = F_23 ( & V_11 -> V_34 -> V_35 ) ;
if ( V_49 && V_49 != 1 )
return V_49 ;
}
F_28 ( & V_11 -> V_52 ) ;
if ( V_48 ) {
if ( V_11 -> V_51 & V_53 ) {
V_49 = - V_54 ;
goto V_55;
}
F_25 ( V_11 ) ;
V_11 -> V_51 |= V_56 ;
} else {
F_26 ( V_11 ) ;
V_11 -> V_51 &= ~ V_56 ;
}
V_55:
F_29 ( & V_11 -> V_52 ) ;
if ( ! V_48 )
F_30 ( & V_11 -> V_34 -> V_35 ) ;
return V_49 == 1 ? 0 : V_49 ;
}
static int F_31 ( struct V_2 * V_4 ,
struct V_57 * V_58 ,
struct V_59 * V_10 )
{
if ( V_10 -> V_60 >= F_4 ( V_9 ) )
return - V_61 ;
V_10 -> V_10 = V_9 [ V_10 -> V_60 ] . V_10 ;
return 0 ;
}
static struct V_5 const * F_32 (
struct V_6 * V_7 )
{
struct V_5 const * V_27 ;
V_27 = F_3 ( V_7 ) ;
if ( V_27 == NULL )
V_27 = & V_9 [ 0 ] ;
V_7 -> V_10 = V_27 -> V_10 ;
F_33 ( & V_7 -> V_23 , 1 , V_62 ,
V_27 -> V_63 ,
& V_7 -> V_24 , 1 , V_64 , 1 ,
0 ) ;
return V_27 ;
}
static struct V_6 * F_34 (
struct V_1 * V_11 , struct V_57 * V_58 ,
T_1 V_65 , enum V_66 V_67 )
{
if ( V_67 == V_68 )
return V_58 ? F_35 ( V_58 , V_65 ) : NULL ;
return & V_11 -> V_21 ;
}
static int F_36 ( struct V_2 * V_4 , struct V_57 * V_58 ,
struct V_69 * V_70 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_5 const * V_27 ;
struct V_6 * V_7 ;
if ( V_70 -> V_65 != V_71 && V_70 -> V_65 != V_72 )
return - V_61 ;
V_7 = F_34 ( V_11 , V_58 , V_70 -> V_65 , V_70 -> V_67 ) ;
if ( V_70 -> V_65 == V_71 ) {
if ( V_7 ) {
F_28 ( & V_11 -> V_52 ) ;
V_70 -> V_21 = * V_7 ;
F_29 ( & V_11 -> V_52 ) ;
}
return 0 ;
}
V_27 = F_32 ( & V_70 -> V_21 ) ;
if ( V_7 ) {
F_28 ( & V_11 -> V_52 ) ;
* V_7 = V_70 -> V_21 ;
if ( V_70 -> V_67 == V_73 )
V_11 -> V_27 = V_27 ;
F_29 ( & V_11 -> V_52 ) ;
}
return 0 ;
}
static int F_37 ( struct V_2 * V_4 , struct V_57 * V_58 ,
struct V_69 * V_70 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_6 * V_7 ;
if ( V_70 -> V_65 != V_71 && V_70 -> V_65 != V_72 )
return - V_61 ;
V_7 = F_34 ( V_11 , V_58 , V_70 -> V_65 , V_70 -> V_67 ) ;
if ( ! V_7 )
return - V_61 ;
F_28 ( & V_11 -> V_52 ) ;
V_70 -> V_21 = * V_7 ;
F_29 ( & V_11 -> V_52 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_4 , struct V_57 * V_58 )
{
struct V_6 * V_21 = F_35 ( V_58 , 0 ) ;
V_21 -> V_74 = V_75 ;
V_21 -> V_10 = V_9 [ 0 ] . V_10 ;
V_21 -> V_23 = V_76 ;
V_21 -> V_24 = V_77 ;
V_21 -> V_78 = V_79 ;
return 0 ;
}
static T_2 F_39 ( int V_80 , void * V_81 )
{
struct V_1 * V_11 = V_81 ;
T_1 V_13 ;
V_13 = F_6 ( V_11 , V_82 ) ;
F_7 ( V_11 , V_82 , V_13 ) ;
return V_83 ;
}
static int T_3 F_40 ( struct V_84 * V_34 )
{
struct V_32 * V_33 ;
struct V_85 * V_86 ;
struct V_85 * V_87 ;
struct V_1 * V_11 ;
int V_49 = - V_88 ;
int V_8 ;
V_11 = F_41 ( sizeof( * V_11 ) , V_89 ) ;
if ( ! V_11 )
return - V_88 ;
F_42 ( & V_11 -> V_52 ) ;
V_11 -> V_34 = V_34 ;
V_33 = V_34 -> V_35 . V_36 ;
if ( V_33 == NULL || V_33 -> V_90 == NULL ) {
F_21 ( & V_34 -> V_35 , L_4 ) ;
goto V_91;
}
if ( ( V_34 -> V_92 == 1 && V_33 -> V_38 > V_93 ) ||
V_33 -> V_38 > V_94 ) {
V_49 = - V_61 ;
F_21 ( & V_34 -> V_35 , L_5 ,
V_33 -> V_38 ) ;
goto V_91;
}
V_86 = F_43 ( V_34 , V_95 , 0 ) ;
if ( ! V_86 ) {
F_21 ( & V_34 -> V_35 , L_6 ) ;
goto V_91;
}
V_87 = F_44 ( V_86 -> V_96 , F_45 ( V_86 ) ,
V_34 -> V_97 ) ;
if ( ! V_87 ) {
F_21 ( & V_34 -> V_35 , L_7 ) ;
goto V_91;
}
V_11 -> V_87 = V_87 ;
V_11 -> V_98 = F_46 ( V_86 -> V_96 , F_45 ( V_86 ) ) ;
if ( ! V_11 -> V_98 ) {
F_21 ( & V_34 -> V_35 , L_8 ) ;
goto V_99;
}
V_49 = F_18 ( V_11 ) ;
if ( V_49 )
goto V_100;
F_47 ( V_11 -> clock [ V_101 ] ) ;
if ( V_33 -> V_102 )
F_48 ( V_11 -> clock [ V_101 ] , V_33 -> V_102 ) ;
else
F_49 ( & V_34 -> V_35 , L_9 ) ;
V_11 -> V_80 = F_50 ( V_34 , 0 ) ;
if ( V_11 -> V_80 < 0 ) {
V_49 = V_11 -> V_80 ;
F_21 ( & V_34 -> V_35 , L_10 ) ;
goto V_103;
}
for ( V_8 = 0 ; V_8 < V_104 ; V_8 ++ )
V_11 -> V_105 [ V_8 ] . V_106 = V_107 [ V_8 ] ;
V_49 = F_51 ( & V_34 -> V_35 , V_104 ,
V_11 -> V_105 ) ;
if ( V_49 )
goto V_103;
V_49 = F_52 ( V_11 -> V_80 , F_39 , 0 ,
F_53 ( & V_34 -> V_35 ) , V_11 ) ;
if ( V_49 ) {
F_21 ( & V_34 -> V_35 , L_11 ) ;
goto V_108;
}
F_54 ( & V_11 -> V_4 , & V_109 ) ;
V_11 -> V_4 . V_110 = V_111 ;
F_55 ( V_11 -> V_4 . V_97 , F_53 ( & V_34 -> V_35 ) , sizeof( V_11 -> V_4 . V_97 ) ) ;
V_11 -> V_4 . V_51 |= V_112 ;
V_11 -> V_27 = & V_9 [ 0 ] ;
V_11 -> V_21 . V_10 = V_9 [ 0 ] . V_10 ;
V_11 -> V_21 . V_23 = V_76 ;
V_11 -> V_21 . V_24 = V_77 ;
V_11 -> V_113 [ V_72 ] . V_51 = V_114 ;
V_11 -> V_113 [ V_71 ] . V_51 = V_115 ;
V_49 = F_56 ( & V_11 -> V_4 . V_116 ,
V_117 , V_11 -> V_113 , 0 ) ;
if ( V_49 < 0 )
goto V_118;
F_57 ( & V_11 -> V_4 , V_34 ) ;
F_58 ( V_34 , & V_11 -> V_4 ) ;
F_59 ( & V_34 -> V_35 ) ;
return 0 ;
V_118:
F_60 ( V_11 -> V_80 , V_11 ) ;
V_108:
F_61 ( V_104 , V_11 -> V_105 ) ;
V_103:
F_62 ( V_11 -> clock [ V_101 ] ) ;
F_15 ( V_11 ) ;
V_100:
F_63 ( V_11 -> V_98 ) ;
V_99:
F_64 ( V_87 -> V_96 , F_45 ( V_87 ) ) ;
V_91:
F_65 ( V_11 ) ;
return V_49 ;
}
static int F_66 ( struct V_45 * V_35 , bool V_119 )
{
struct V_32 * V_33 = V_35 -> V_36 ;
struct V_84 * V_34 = F_67 ( V_35 ) ;
struct V_2 * V_4 = F_68 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_49 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_12 ,
V_50 , V_11 -> V_51 ) ;
F_28 ( & V_11 -> V_52 ) ;
if ( V_11 -> V_51 & V_120 ) {
F_26 ( V_11 ) ;
V_49 = V_33 -> V_90 ( V_11 -> V_34 , false ) ;
if ( V_49 )
goto V_55;
V_49 = F_69 ( V_104 ,
V_11 -> V_105 ) ;
if ( V_49 )
goto V_55;
F_62 ( V_11 -> clock [ V_121 ] ) ;
V_11 -> V_51 &= ~ V_120 ;
if ( ! V_119 )
V_11 -> V_51 |= V_53 ;
}
V_55:
F_29 ( & V_11 -> V_52 ) ;
return V_49 ? - V_122 : 0 ;
}
static int F_70 ( struct V_45 * V_35 , bool V_119 )
{
struct V_32 * V_33 = V_35 -> V_36 ;
struct V_84 * V_34 = F_67 ( V_35 ) ;
struct V_2 * V_4 = F_68 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_49 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_12 ,
V_50 , V_11 -> V_51 ) ;
F_28 ( & V_11 -> V_52 ) ;
if ( ! V_119 && ! ( V_11 -> V_51 & V_53 ) )
goto V_55;
if ( ! ( V_11 -> V_51 & V_120 ) ) {
V_49 = F_71 ( V_104 ,
V_11 -> V_105 ) ;
if ( V_49 )
goto V_55;
V_49 = V_33 -> V_90 ( V_11 -> V_34 , true ) ;
if ( ! V_49 ) {
V_11 -> V_51 |= V_120 ;
} else {
F_69 ( V_104 ,
V_11 -> V_105 ) ;
goto V_55;
}
F_47 ( V_11 -> clock [ V_121 ] ) ;
}
if ( V_11 -> V_51 & V_56 )
F_25 ( V_11 ) ;
V_11 -> V_51 &= ~ V_53 ;
V_55:
F_29 ( & V_11 -> V_52 ) ;
return V_49 ? - V_122 : 0 ;
}
static int F_72 ( struct V_45 * V_35 )
{
return F_66 ( V_35 , false ) ;
}
static int F_73 ( struct V_45 * V_35 )
{
return F_70 ( V_35 , false ) ;
}
static int F_74 ( struct V_45 * V_35 )
{
return F_66 ( V_35 , true ) ;
}
static int F_75 ( struct V_45 * V_35 )
{
return F_70 ( V_35 , true ) ;
}
static int T_4 F_76 ( struct V_84 * V_34 )
{
struct V_2 * V_4 = F_68 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_85 * V_123 = V_11 -> V_87 ;
F_77 ( & V_34 -> V_35 ) ;
F_72 ( & V_34 -> V_35 ) ;
F_62 ( V_11 -> clock [ V_101 ] ) ;
F_78 ( & V_34 -> V_35 ) ;
F_15 ( V_11 ) ;
F_61 ( V_104 , V_11 -> V_105 ) ;
F_79 ( & V_11 -> V_4 . V_116 ) ;
F_60 ( V_11 -> V_80 , V_11 ) ;
F_63 ( V_11 -> V_98 ) ;
F_64 ( V_123 -> V_96 , F_45 ( V_123 ) ) ;
F_65 ( V_11 ) ;
return 0 ;
}
static int T_5 F_80 ( void )
{
return F_81 ( & V_124 , F_40 ) ;
}
static void T_6 F_82 ( void )
{
F_83 ( & V_124 ) ;
}
