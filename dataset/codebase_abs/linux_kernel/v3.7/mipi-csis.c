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
if ( V_11 -> V_27 -> V_40 == 32 )
V_13 |= V_41 ;
else
V_13 &= ~ V_41 ;
V_13 &= ~ V_42 ;
if ( V_33 -> V_43 )
V_13 |= V_42 ;
F_7 ( V_11 , V_16 , V_13 ) ;
V_13 = F_6 ( V_11 , V_16 ) ;
F_7 ( V_11 , V_16 , V_13 | V_44 ) ;
}
static void F_15 ( struct V_1 * V_11 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_45 ; V_8 ++ ) {
if ( F_16 ( V_11 -> clock [ V_8 ] ) )
continue;
F_17 ( V_11 -> clock [ V_8 ] ) ;
F_18 ( V_11 -> clock [ V_8 ] ) ;
V_11 -> clock [ V_8 ] = NULL ;
}
}
static int F_19 ( struct V_1 * V_11 )
{
struct V_46 * V_35 = & V_11 -> V_34 -> V_35 ;
int V_8 , V_47 ;
for ( V_8 = 0 ; V_8 < V_45 ; V_8 ++ ) {
V_11 -> clock [ V_8 ] = F_20 ( V_35 , V_48 [ V_8 ] ) ;
if ( F_21 ( V_11 -> clock [ V_8 ] ) )
goto V_49;
V_47 = F_22 ( V_11 -> clock [ V_8 ] ) ;
if ( V_47 < 0 ) {
F_18 ( V_11 -> clock [ V_8 ] ) ;
V_11 -> clock [ V_8 ] = NULL ;
goto V_49;
}
}
return 0 ;
V_49:
F_15 ( V_11 ) ;
F_23 ( V_35 , L_2 , V_48 [ V_8 ] ) ;
return - V_50 ;
}
static void F_24 ( struct V_1 * V_11 )
{
F_8 ( V_11 ) ;
F_14 ( V_11 ) ;
F_10 ( V_11 , true ) ;
F_5 ( V_11 , true ) ;
}
static void F_25 ( struct V_1 * V_11 )
{
F_5 ( V_11 , false ) ;
F_10 ( V_11 , false ) ;
}
static void F_26 ( struct V_1 * V_11 )
{
unsigned long V_51 ;
int V_8 ;
F_27 ( & V_11 -> V_52 , V_51 ) ;
for ( V_8 = 0 ; V_8 < V_53 ; V_8 ++ )
V_11 -> V_54 [ V_8 ] . V_55 = 0 ;
F_28 ( & V_11 -> V_52 , V_51 ) ;
}
static void F_29 ( struct V_1 * V_11 , bool V_56 )
{
int V_8 = V_56 ? V_53 : V_53 - 4 ;
unsigned long V_51 ;
F_27 ( & V_11 -> V_52 , V_51 ) ;
for ( V_8 -- ; V_8 >= 0 ; V_8 -- )
if ( V_11 -> V_54 [ V_8 ] . V_55 >= 0 )
F_30 ( & V_11 -> V_4 , L_3 ,
V_11 -> V_54 [ V_8 ] . V_57 ,
V_11 -> V_54 [ V_8 ] . V_55 ) ;
F_28 ( & V_11 -> V_52 , V_51 ) ;
}
static int F_31 ( struct V_2 * V_4 , int V_12 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_46 * V_35 = & V_11 -> V_34 -> V_35 ;
if ( V_12 )
return F_32 ( V_35 ) ;
return F_33 ( V_35 ) ;
}
static int F_34 ( struct V_2 * V_4 , int V_58 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_47 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_4 ,
V_59 , V_58 , V_11 -> V_51 ) ;
if ( V_58 ) {
F_26 ( V_11 ) ;
V_47 = F_32 ( & V_11 -> V_34 -> V_35 ) ;
if ( V_47 && V_47 != 1 )
return V_47 ;
}
F_35 ( & V_11 -> V_60 ) ;
if ( V_58 ) {
if ( V_11 -> V_51 & V_61 ) {
V_47 = - V_62 ;
goto V_63;
}
F_24 ( V_11 ) ;
V_11 -> V_51 |= V_64 ;
} else {
F_25 ( V_11 ) ;
V_11 -> V_51 &= ~ V_64 ;
if ( V_22 > 0 )
F_29 ( V_11 , true ) ;
}
V_63:
F_36 ( & V_11 -> V_60 ) ;
if ( ! V_58 )
F_37 ( & V_11 -> V_34 -> V_35 ) ;
return V_47 == 1 ? 0 : V_47 ;
}
static int F_38 ( struct V_2 * V_4 ,
struct V_65 * V_66 ,
struct V_67 * V_10 )
{
if ( V_10 -> V_68 >= F_4 ( V_9 ) )
return - V_69 ;
V_10 -> V_10 = V_9 [ V_10 -> V_68 ] . V_10 ;
return 0 ;
}
static struct V_5 const * F_39 (
struct V_6 * V_7 )
{
struct V_5 const * V_27 ;
V_27 = F_3 ( V_7 ) ;
if ( V_27 == NULL )
V_27 = & V_9 [ 0 ] ;
V_7 -> V_10 = V_27 -> V_10 ;
F_40 ( & V_7 -> V_23 , 1 , V_70 ,
V_27 -> V_71 ,
& V_7 -> V_24 , 1 , V_72 , 1 ,
0 ) ;
return V_27 ;
}
static struct V_6 * F_41 (
struct V_1 * V_11 , struct V_65 * V_66 ,
T_1 V_73 , enum V_74 V_75 )
{
if ( V_75 == V_76 )
return V_66 ? F_42 ( V_66 , V_73 ) : NULL ;
return & V_11 -> V_21 ;
}
static int F_43 ( struct V_2 * V_4 , struct V_65 * V_66 ,
struct V_77 * V_78 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_5 const * V_27 ;
struct V_6 * V_7 ;
if ( V_78 -> V_73 != V_79 && V_78 -> V_73 != V_80 )
return - V_69 ;
V_7 = F_41 ( V_11 , V_66 , V_78 -> V_73 , V_78 -> V_75 ) ;
if ( V_78 -> V_73 == V_79 ) {
if ( V_7 ) {
F_35 ( & V_11 -> V_60 ) ;
V_78 -> V_21 = * V_7 ;
F_36 ( & V_11 -> V_60 ) ;
}
return 0 ;
}
V_27 = F_39 ( & V_78 -> V_21 ) ;
if ( V_7 ) {
F_35 ( & V_11 -> V_60 ) ;
* V_7 = V_78 -> V_21 ;
if ( V_78 -> V_75 == V_81 )
V_11 -> V_27 = V_27 ;
F_36 ( & V_11 -> V_60 ) ;
}
return 0 ;
}
static int F_44 ( struct V_2 * V_4 , struct V_65 * V_66 ,
struct V_77 * V_78 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
struct V_6 * V_7 ;
if ( V_78 -> V_73 != V_79 && V_78 -> V_73 != V_80 )
return - V_69 ;
V_7 = F_41 ( V_11 , V_66 , V_78 -> V_73 , V_78 -> V_75 ) ;
if ( ! V_7 )
return - V_69 ;
F_35 ( & V_11 -> V_60 ) ;
V_78 -> V_21 = * V_7 ;
F_36 ( & V_11 -> V_60 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_4 , void * V_82 ,
unsigned int * V_83 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
unsigned long V_51 ;
* V_83 = F_46 (unsigned int, *size, S5PCSIS_PKTDATA_SIZE) ;
F_27 ( & V_11 -> V_52 , V_51 ) ;
V_11 -> V_84 . V_85 = V_82 ;
V_11 -> V_84 . V_86 = * V_83 ;
F_28 ( & V_11 -> V_52 , V_51 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_4 )
{
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_29 ( V_11 , true ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_4 , struct V_65 * V_66 )
{
struct V_6 * V_21 = F_42 ( V_66 , 0 ) ;
V_21 -> V_87 = V_88 ;
V_21 -> V_10 = V_9 [ 0 ] . V_10 ;
V_21 -> V_23 = V_89 ;
V_21 -> V_24 = V_90 ;
V_21 -> V_91 = V_92 ;
return 0 ;
}
static T_2 F_49 ( int V_93 , void * V_94 )
{
struct V_1 * V_11 = V_94 ;
struct V_95 * V_96 = & V_11 -> V_84 ;
unsigned long V_51 ;
T_1 V_97 ;
V_97 = F_6 ( V_11 , V_98 ) ;
F_27 ( & V_11 -> V_52 , V_51 ) ;
if ( ( V_97 & V_99 ) && V_96 -> V_85 ) {
T_1 V_100 ;
if ( V_97 & V_101 )
V_100 = V_102 ;
else
V_100 = V_103 ;
memcpy ( V_96 -> V_85 , V_11 -> V_104 + V_100 , V_96 -> V_86 ) ;
V_96 -> V_85 = NULL ;
F_50 () ;
}
if ( ( V_97 & V_105 ) || V_22 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_53 ; V_8 ++ ) {
if ( ! ( V_97 & V_11 -> V_54 [ V_8 ] . V_106 ) )
continue;
V_11 -> V_54 [ V_8 ] . V_55 ++ ;
F_12 ( 2 , V_22 , & V_11 -> V_4 , L_5 ,
V_11 -> V_54 [ V_8 ] . V_57 ,
V_11 -> V_54 [ V_8 ] . V_55 ) ;
}
F_12 ( 2 , V_22 , & V_11 -> V_4 , L_6 , V_97 ) ;
}
F_28 ( & V_11 -> V_52 , V_51 ) ;
F_7 ( V_11 , V_98 , V_97 ) ;
return V_107 ;
}
static int T_3 F_51 ( struct V_108 * V_34 )
{
struct V_32 * V_33 ;
struct V_109 * V_110 ;
struct V_1 * V_11 ;
int V_47 = - V_111 ;
int V_8 ;
V_11 = F_52 ( & V_34 -> V_35 , sizeof( * V_11 ) , V_112 ) ;
if ( ! V_11 )
return - V_111 ;
F_53 ( & V_11 -> V_60 ) ;
F_54 ( & V_11 -> V_52 ) ;
V_11 -> V_34 = V_34 ;
V_11 -> V_68 = F_55 ( 0 , V_34 -> V_113 ) ;
V_33 = V_34 -> V_35 . V_36 ;
if ( V_33 == NULL ) {
F_23 ( & V_34 -> V_35 , L_7 ) ;
return - V_69 ;
}
if ( ( V_11 -> V_68 == 1 && V_33 -> V_38 > V_114 ) ||
V_33 -> V_38 > V_115 ) {
F_23 ( & V_34 -> V_35 , L_8 ,
V_33 -> V_38 ) ;
return - V_69 ;
}
V_110 = F_56 ( V_34 , V_116 , 0 ) ;
V_11 -> V_104 = F_57 ( & V_34 -> V_35 , V_110 ) ;
if ( V_11 -> V_104 == NULL ) {
F_23 ( & V_34 -> V_35 , L_9 ) ;
return - V_50 ;
}
V_11 -> V_93 = F_58 ( V_34 , 0 ) ;
if ( V_11 -> V_93 < 0 ) {
F_23 ( & V_34 -> V_35 , L_10 ) ;
return V_11 -> V_93 ;
}
for ( V_8 = 0 ; V_8 < V_117 ; V_8 ++ )
V_11 -> V_118 [ V_8 ] . V_119 = V_120 [ V_8 ] ;
V_47 = F_59 ( & V_34 -> V_35 , V_117 ,
V_11 -> V_118 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_19 ( V_11 ) ;
if ( V_47 )
goto V_121;
F_60 ( V_11 -> clock [ V_122 ] ) ;
if ( V_33 -> V_123 )
F_61 ( V_11 -> clock [ V_122 ] , V_33 -> V_123 ) ;
else
F_62 ( & V_34 -> V_35 , L_11 ) ;
V_47 = F_63 ( & V_34 -> V_35 , V_11 -> V_93 , F_49 ,
0 , F_64 ( & V_34 -> V_35 ) , V_11 ) ;
if ( V_47 ) {
F_23 ( & V_34 -> V_35 , L_12 ) ;
goto V_124;
}
F_65 ( & V_11 -> V_4 , & V_125 ) ;
V_11 -> V_4 . V_126 = V_127 ;
F_66 ( V_11 -> V_4 . V_57 , F_64 ( & V_34 -> V_35 ) , sizeof( V_11 -> V_4 . V_57 ) ) ;
V_11 -> V_4 . V_51 |= V_128 ;
V_11 -> V_27 = & V_9 [ 0 ] ;
V_11 -> V_21 . V_10 = V_9 [ 0 ] . V_10 ;
V_11 -> V_21 . V_23 = V_89 ;
V_11 -> V_21 . V_24 = V_90 ;
V_11 -> V_129 [ V_80 ] . V_51 = V_130 ;
V_11 -> V_129 [ V_79 ] . V_51 = V_131 ;
V_47 = F_67 ( & V_11 -> V_4 . V_132 ,
V_133 , V_11 -> V_129 , 0 ) ;
if ( V_47 < 0 )
goto V_121;
F_68 ( & V_11 -> V_4 , V_34 ) ;
F_69 ( V_34 , & V_11 -> V_4 ) ;
memcpy ( V_11 -> V_54 , V_134 , sizeof( V_11 -> V_54 ) ) ;
F_70 ( & V_34 -> V_35 ) ;
return 0 ;
V_124:
F_71 ( V_117 , V_11 -> V_118 ) ;
V_121:
F_72 ( V_11 -> clock [ V_122 ] ) ;
F_15 ( V_11 ) ;
return V_47 ;
}
static int F_73 ( struct V_46 * V_35 , bool V_135 )
{
struct V_108 * V_34 = F_74 ( V_35 ) ;
struct V_2 * V_4 = F_75 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_47 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_13 ,
V_59 , V_11 -> V_51 ) ;
F_35 ( & V_11 -> V_60 ) ;
if ( V_11 -> V_51 & V_136 ) {
F_25 ( V_11 ) ;
V_47 = F_76 ( V_11 -> V_68 , false ) ;
if ( V_47 )
goto V_63;
V_47 = F_77 ( V_117 ,
V_11 -> V_118 ) ;
if ( V_47 )
goto V_63;
F_72 ( V_11 -> clock [ V_137 ] ) ;
V_11 -> V_51 &= ~ V_136 ;
if ( ! V_135 )
V_11 -> V_51 |= V_61 ;
}
V_63:
F_36 ( & V_11 -> V_60 ) ;
return V_47 ? - V_138 : 0 ;
}
static int F_78 ( struct V_46 * V_35 , bool V_135 )
{
struct V_108 * V_34 = F_74 ( V_35 ) ;
struct V_2 * V_4 = F_75 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
int V_47 = 0 ;
F_12 ( 1 , V_22 , V_4 , L_13 ,
V_59 , V_11 -> V_51 ) ;
F_35 ( & V_11 -> V_60 ) ;
if ( ! V_135 && ! ( V_11 -> V_51 & V_61 ) )
goto V_63;
if ( ! ( V_11 -> V_51 & V_136 ) ) {
V_47 = F_79 ( V_117 ,
V_11 -> V_118 ) ;
if ( V_47 )
goto V_63;
V_47 = F_76 ( V_11 -> V_68 , true ) ;
if ( ! V_47 ) {
V_11 -> V_51 |= V_136 ;
} else {
F_77 ( V_117 ,
V_11 -> V_118 ) ;
goto V_63;
}
F_60 ( V_11 -> clock [ V_137 ] ) ;
}
if ( V_11 -> V_51 & V_64 )
F_24 ( V_11 ) ;
V_11 -> V_51 &= ~ V_61 ;
V_63:
F_36 ( & V_11 -> V_60 ) ;
return V_47 ? - V_138 : 0 ;
}
static int F_80 ( struct V_46 * V_35 )
{
return F_73 ( V_35 , false ) ;
}
static int F_81 ( struct V_46 * V_35 )
{
return F_78 ( V_35 , false ) ;
}
static int F_82 ( struct V_46 * V_35 )
{
return F_73 ( V_35 , true ) ;
}
static int F_83 ( struct V_46 * V_35 )
{
return F_78 ( V_35 , true ) ;
}
static int T_4 F_84 ( struct V_108 * V_34 )
{
struct V_2 * V_4 = F_75 ( V_34 ) ;
struct V_1 * V_11 = F_1 ( V_4 ) ;
F_85 ( & V_34 -> V_35 ) ;
F_73 ( & V_34 -> V_35 , false ) ;
F_72 ( V_11 -> clock [ V_122 ] ) ;
F_86 ( & V_34 -> V_35 ) ;
F_15 ( V_11 ) ;
F_71 ( V_117 , V_11 -> V_118 ) ;
F_87 ( & V_11 -> V_4 . V_132 ) ;
return 0 ;
}
