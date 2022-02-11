static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
T_1 V_10 ;
T_2 V_11 = 0 ;
V_10 = V_2 -> V_10 ;
if ( V_4 && V_4 -> V_10 )
V_10 = V_4 -> V_10 ;
if ( V_10 != 8 ) {
F_3 ( & V_2 -> V_2 , L_1 ,
V_12 , V_10 ) ;
return - V_13 ;
}
V_11 = V_2 -> V_14 ;
if ( V_4 && V_4 -> V_15 )
V_11 = F_4 ( V_11 , V_4 -> V_15 ) ;
if ( V_11 == 0 ) {
F_3 ( & V_2 -> V_2 , L_2 ) ;
return - V_13 ;
}
F_5 ( V_9 , V_11 ) ;
F_6 ( F_7 ( V_16 ) |
F_8
( V_17 ) |
( ( V_2 -> V_18 & V_19 ) ? V_20 : 0 ) |
( ( V_2 -> V_18 & V_21 ) ? V_22 : 0 ) ,
V_9 -> V_23 + F_9 ( V_9 ) ) ;
F_6 ( 0x0 , V_9 -> V_23 + V_24 ) ;
F_6 ( 0x0 , V_9 -> V_23 + V_25 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
if ( ! V_2 -> V_10 )
V_2 -> V_10 = 8 ;
if ( V_2 -> V_18 & ~ ( V_19 | V_21 ) )
return - V_13 ;
V_26 = F_1 ( V_2 , NULL ) ;
if ( V_26 ) {
F_3 ( & V_2 -> V_2 ,
L_3 , V_26 ) ;
}
return V_26 ;
}
static T_2 F_11 ( unsigned V_27 )
{
T_2 V_28 = 0 ;
if ( V_27 & 1 )
V_28 |= V_29 ;
if ( V_27 & 2 )
V_28 |= V_30 ;
return V_28 ;
}
static void F_12 ( struct V_5 * V_6 , unsigned V_27 )
{
const T_2 V_31 =
V_29 | V_30 ;
T_2 V_28 ;
struct V_8 * V_9 = & V_6 -> V_9 ;
F_6 ( V_31 , V_9 -> V_23 + V_32 + V_33 ) ;
V_28 = F_11 ( V_27 ) ;
F_6 ( V_28 , V_9 -> V_23 + V_32 + V_34 ) ;
}
static inline void F_13 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
F_6 ( V_35 ,
V_9 -> V_23 + V_32 + V_34 ) ;
F_6 ( V_36 ,
V_9 -> V_23 + V_32 + V_33 ) ;
}
static inline void F_14 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
F_6 ( V_35 ,
V_9 -> V_23 + V_32 + V_33 ) ;
F_6 ( V_36 ,
V_9 -> V_23 + V_32 + V_34 ) ;
}
static int F_15 ( struct V_5 * V_6 , int V_37 , int V_31 , bool V_38 )
{
const unsigned long V_39 = V_40 + F_16 ( V_41 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
T_2 V_42 ;
do {
V_42 = F_17 ( V_9 -> V_23 + V_37 ) ;
if ( ! V_38 )
V_42 = ~ V_42 ;
V_42 &= V_31 ;
if ( V_42 == V_31 )
return 0 ;
} while ( F_18 ( V_40 , V_39 ) );
return - V_43 ;
}
static void F_19 ( void * V_44 )
{
struct V_5 * V_6 = V_44 ;
F_20 ( & V_6 -> V_45 ) ;
}
static T_3 F_21 ( int V_46 , void * V_47 )
{
struct V_8 * V_9 = V_47 ;
F_3 ( V_9 -> V_2 , L_4 ,
V_12 , __LINE__ ,
F_22 ( V_9 -> V_23 + F_9 ( V_9 ) ) ,
F_22 ( V_9 -> V_23 + F_23 ( V_9 ) ) ) ;
return V_48 ;
}
static int F_24 ( struct V_5 * V_6 , int V_27 ,
unsigned char * V_49 , int V_50 ,
int * V_51 , int * V_52 , int V_53 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
struct V_54 * V_55 = NULL ;
const bool V_56 = F_25 ( V_49 ) ;
const int V_57 = V_56 ? V_58 : V_59 ;
const int V_60 = F_26 ( V_50 , V_57 ) ;
int V_61 ;
int F_4 , V_62 ;
T_2 V_63 ;
struct V_64 * V_65 ;
void * V_66 ;
struct {
T_2 V_67 [ 4 ] ;
struct V_68 V_69 ;
} * V_70 ;
if ( ! V_50 )
return - V_13 ;
V_70 = F_27 ( sizeof( * V_70 ) * V_60 , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
F_28 ( V_6 -> V_45 ) ;
V_63 = F_22 ( V_9 -> V_23 + V_32 ) ;
V_63 |= V_73 | F_11 ( V_27 ) ;
if ( * V_51 )
V_63 |= V_35 ;
if ( ! V_53 )
V_63 |= V_74 ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
F_4 = F_4 ( V_50 , V_57 ) ;
if ( ( V_61 + 1 == V_60 ) && * V_52 )
V_63 |= V_36 ;
if ( V_9 -> V_75 == V_76 )
V_63 |= F_4 ;
V_70 [ V_61 ] . V_67 [ 0 ] = V_63 ;
V_70 [ V_61 ] . V_67 [ 3 ] = F_4 ;
if ( V_56 ) {
V_65 = F_29 ( V_49 ) ;
if ( ! V_65 ) {
V_62 = - V_72 ;
goto V_77;
}
V_66 = F_30 ( V_65 ) +
( ( V_78 ) V_49 & ~ V_79 ) ;
} else {
V_66 = V_49 ;
}
F_31 ( & V_70 [ V_61 ] . V_69 , V_66 , F_4 ) ;
V_62 = F_32 ( V_9 -> V_2 , & V_70 [ V_61 ] . V_69 , 1 ,
V_53 ? V_80 : V_81 ) ;
V_50 -= F_4 ;
V_49 += F_4 ;
V_55 = F_33 ( V_9 -> V_82 ,
(struct V_68 * ) V_70 [ V_61 ] . V_67 ,
( V_9 -> V_75 == V_76 ) ? 1 : 4 ,
V_83 ,
V_61 ? V_84 : 0 ) ;
if ( ! V_55 ) {
F_3 ( V_9 -> V_2 ,
L_5 ) ;
V_62 = - V_13 ;
goto V_85;
}
V_55 = F_33 ( V_9 -> V_82 ,
& V_70 [ V_61 ] . V_69 , 1 ,
V_53 ? V_86 : V_87 ,
V_84 | V_88 ) ;
if ( ! V_55 ) {
F_3 ( V_9 -> V_2 ,
L_6 ) ;
V_62 = - V_13 ;
goto V_85;
}
}
V_55 -> V_89 = F_19 ;
V_55 -> V_90 = V_6 ;
F_34 ( V_55 ) ;
F_35 ( V_9 -> V_82 ) ;
V_62 = F_36 ( & V_6 -> V_45 ,
F_16 ( V_41 ) ) ;
if ( ! V_62 ) {
F_3 ( V_9 -> V_2 , L_7 ) ;
V_62 = - V_43 ;
F_37 ( V_9 -> V_82 ) ;
goto V_77;
}
V_62 = 0 ;
V_77:
while ( -- V_61 >= 0 ) {
V_85:
F_38 ( V_9 -> V_2 , & V_70 [ V_61 ] . V_69 , 1 ,
V_53 ? V_80 : V_81 ) ;
}
F_39 ( V_70 ) ;
return V_62 ;
}
static int F_40 ( struct V_5 * V_6 , int V_27 ,
unsigned char * V_49 , int V_50 ,
int * V_51 , int * V_52 , int V_53 )
{
struct V_8 * V_9 = & V_6 -> V_9 ;
if ( * V_51 )
F_13 ( V_6 ) ;
F_12 ( V_6 , V_27 ) ;
while ( V_50 -- ) {
if ( * V_52 && V_50 == 0 )
F_14 ( V_6 ) ;
if ( V_9 -> V_75 == V_76 ) {
F_6 ( V_91 ,
V_9 -> V_23 + V_32 + V_33 ) ;
F_6 ( 1 ,
V_9 -> V_23 + V_32 + V_34 ) ;
} else {
F_6 ( 1 , V_9 -> V_23 + V_92 ) ;
}
if ( V_53 )
F_6 ( V_74 ,
V_9 -> V_23 + V_32 + V_33 ) ;
else
F_6 ( V_74 ,
V_9 -> V_23 + V_32 + V_34 ) ;
F_6 ( V_93 ,
V_9 -> V_23 + V_32 + V_34 ) ;
if ( F_15 ( V_6 , V_32 , V_93 , 1 ) )
return - V_43 ;
if ( V_53 )
F_6 ( * V_49 , V_9 -> V_23 + F_41 ( V_9 ) ) ;
F_6 ( V_73 ,
V_9 -> V_23 + V_32 + V_34 ) ;
if ( ! V_53 ) {
if ( F_15 ( V_6 , F_23 ( V_9 ) ,
V_94 , 0 ) )
return - V_43 ;
* V_49 = ( F_22 ( V_9 -> V_23 + F_41 ( V_9 ) ) & 0xff ) ;
}
if ( F_15 ( V_6 , V_32 , V_93 , 0 ) )
return - V_43 ;
V_49 ++ ;
}
if ( V_50 <= 0 )
return 0 ;
return - V_43 ;
}
static int F_42 ( struct V_95 * V_7 ,
struct V_96 * V_97 )
{
struct V_5 * V_6 = F_2 ( V_7 ) ;
struct V_8 * V_9 = & V_6 -> V_9 ;
int V_51 , V_52 ;
struct V_3 * V_4 , * V_98 ;
int V_99 = 0 ;
int V_27 ;
V_51 = V_52 = 0 ;
V_27 = V_97 -> V_6 -> V_100 ;
F_43 (t, tmp_t, &m->transfers, transfer_list) {
V_99 = F_1 ( V_97 -> V_6 , V_4 ) ;
if ( V_99 )
break;
if ( & V_4 -> V_101 == V_97 -> V_102 . V_103 )
V_51 = 1 ;
if ( & V_4 -> V_101 == V_97 -> V_102 . V_104 )
V_52 = 1 ;
if ( ( V_4 -> V_105 && V_4 -> V_106 ) || ( V_4 -> V_107 && V_4 -> V_108 ) ) {
F_3 ( V_9 -> V_2 ,
L_8 ) ;
V_99 = - V_13 ;
break;
}
if ( V_4 -> V_50 < 32 ) {
F_6 ( V_109 ,
V_9 -> V_23 + F_9 ( V_9 ) +
V_33 ) ;
if ( V_4 -> V_106 )
V_99 = F_40 ( V_6 , V_27 ,
( void * ) V_4 -> V_106 ,
V_4 -> V_50 , & V_51 , & V_52 , 1 ) ;
if ( V_4 -> V_105 )
V_99 = F_40 ( V_6 , V_27 ,
V_4 -> V_105 , V_4 -> V_50 ,
& V_51 , & V_52 , 0 ) ;
} else {
F_6 ( V_109 ,
V_9 -> V_23 + F_9 ( V_9 ) +
V_34 ) ;
if ( V_4 -> V_106 )
V_99 = F_24 ( V_6 , V_27 ,
( void * ) V_4 -> V_106 , V_4 -> V_50 ,
& V_51 , & V_52 , 1 ) ;
if ( V_4 -> V_105 )
V_99 = F_24 ( V_6 , V_27 ,
V_4 -> V_105 , V_4 -> V_50 ,
& V_51 , & V_52 , 0 ) ;
}
if ( V_99 ) {
F_44 ( V_9 -> V_23 ) ;
break;
}
V_97 -> V_110 += V_4 -> V_50 ;
V_51 = V_52 = 0 ;
}
V_97 -> V_99 = V_99 ;
F_45 ( V_7 ) ;
return V_99 ;
}
static bool F_46 ( struct V_111 * V_112 , void * V_44 )
{
struct V_8 * V_9 = V_44 ;
if ( ! F_47 ( V_112 ) )
return false ;
if ( V_112 -> V_113 != V_9 -> V_114 )
return false ;
V_112 -> V_115 = & V_9 -> V_116 ;
return true ;
}
static int T_4 F_48 ( struct V_117 * V_118 )
{
const struct V_119 * V_120 =
F_49 ( V_121 , & V_118 -> V_2 ) ;
struct V_122 * V_123 = V_118 -> V_2 . V_124 ;
struct V_95 * V_7 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_125 * V_126 , * V_127 ;
struct V_128 * V_128 ;
struct V_129 * V_129 ;
void T_5 * V_23 ;
int V_75 , V_114 , V_130 ;
int V_62 = 0 , V_131 , V_132 ;
T_6 V_31 ;
const int V_133 = 160000000 ;
V_126 = F_50 ( V_118 , V_134 , 0 ) ;
V_131 = F_51 ( V_118 , 0 ) ;
V_132 = F_51 ( V_118 , 1 ) ;
if ( ! V_126 || V_131 < 0 || V_132 < 0 )
return - V_13 ;
V_23 = F_52 ( & V_118 -> V_2 , V_126 ) ;
if ( ! V_23 )
return - V_135 ;
V_128 = F_53 ( & V_118 -> V_2 ) ;
if ( F_54 ( V_128 ) )
return F_55 ( V_128 ) ;
V_129 = F_56 ( & V_118 -> V_2 , NULL ) ;
if ( F_54 ( V_129 ) )
return F_55 ( V_129 ) ;
if ( V_123 ) {
V_75 = (enum V_136 ) V_120 -> V_137 ;
V_62 = F_57 ( V_123 , L_9 ,
& V_114 ) ;
if ( V_62 ) {
F_3 ( & V_118 -> V_2 ,
L_10 ) ;
return - V_13 ;
}
V_62 = F_57 ( V_123 , L_11 ,
& V_130 ) ;
if ( V_62 )
V_130 = V_133 ;
} else {
V_127 = F_50 ( V_118 , V_138 , 0 ) ;
if ( ! V_127 )
return - V_13 ;
V_75 = V_118 -> V_139 -> V_140 ;
V_114 = V_127 -> V_141 ;
V_130 = V_133 ;
}
V_7 = F_58 ( & V_118 -> V_2 , sizeof( * V_6 ) ) ;
if ( ! V_7 )
return - V_72 ;
V_7 -> V_142 = F_42 ;
V_7 -> V_143 = F_10 ;
V_7 -> V_144 = V_19 | V_21 ;
V_7 -> V_145 = 3 ;
V_7 -> V_2 . V_124 = V_123 ;
V_7 -> V_146 = V_147 ;
V_6 = F_2 ( V_7 ) ;
V_9 = & V_6 -> V_9 ;
V_9 -> V_2 = & V_118 -> V_2 ;
V_9 -> V_129 = V_129 ;
V_9 -> V_23 = V_23 ;
V_9 -> V_75 = V_75 ;
V_9 -> V_114 = V_114 ;
F_59 ( & V_6 -> V_45 ) ;
V_62 = F_60 ( & V_118 -> V_2 , V_131 , F_21 , 0 ,
V_148 , V_9 ) ;
if ( V_62 )
goto V_149;
F_61 ( V_31 ) ;
F_62 ( V_150 , V_31 ) ;
V_9 -> V_116 . V_151 = V_132 ;
V_9 -> V_82 = F_63 ( V_31 , F_46 , V_9 ) ;
if ( ! V_9 -> V_82 ) {
F_3 ( V_9 -> V_2 , L_12 ) ;
goto V_149;
}
F_64 ( V_9 -> V_129 ) ;
F_65 ( V_9 -> V_129 , V_130 ) ;
V_9 -> V_152 = F_66 ( V_9 -> V_129 ) / 1000 ;
F_44 ( V_9 -> V_23 ) ;
F_67 ( V_118 , V_7 ) ;
V_62 = F_68 ( V_7 ) ;
if ( V_62 ) {
F_3 ( & V_118 -> V_2 , L_13 , V_62 ) ;
goto V_153;
}
return 0 ;
V_153:
F_69 ( V_9 -> V_82 ) ;
F_70 ( V_9 -> V_129 ) ;
V_149:
F_71 ( V_7 ) ;
return V_62 ;
}
static int T_7 F_72 ( struct V_117 * V_118 )
{
struct V_95 * V_7 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
V_7 = F_73 ( F_74 ( V_118 ) ) ;
V_6 = F_2 ( V_7 ) ;
V_9 = & V_6 -> V_9 ;
F_75 ( V_7 ) ;
F_69 ( V_9 -> V_82 ) ;
F_70 ( V_9 -> V_129 ) ;
F_71 ( V_7 ) ;
return 0 ;
}
