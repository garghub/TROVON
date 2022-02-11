static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
struct V_1 * V_7 ;
if ( ! V_5 ) {
F_2 ( V_3 , L_1 ) ;
return F_3 ( - V_8 ) ;
}
V_7 = F_4 ( V_3 , sizeof( * V_7 ) , V_9 ) ;
if ( ! V_7 )
return F_3 ( - V_10 ) ;
if ( F_5 ( V_5 , L_2 , & V_7 -> V_11 ) )
V_7 -> V_11 = L_3 ;
if ( F_6 ( V_5 , L_4 ,
& V_7 -> V_12 ) ) {
F_2 ( V_3 , L_5 ) ;
return F_3 ( - V_8 ) ;
}
if ( F_6 ( V_5 , L_6 ,
& V_7 -> V_13 ) ) {
F_2 ( V_3 , L_7 ) ;
return F_3 ( - V_8 ) ;
}
if ( V_7 -> V_13 < V_7 -> V_12 ) {
F_2 ( V_3 ,
L_8 ) ;
return F_3 ( - V_8 ) ;
}
if ( F_7 ( V_5 , L_9 , & V_7 -> V_14 ) )
V_7 -> V_14 = 0 ;
if ( V_7 -> V_14 > V_15 ) {
F_8 ( V_3 ,
L_10 ,
V_7 -> V_14 , V_15 ) ;
V_7 -> V_14 = V_15 ;
} else if ( V_7 -> V_14 < V_16 ) {
F_8 ( V_3 ,
L_11 ,
V_7 -> V_14 , V_16 ) ;
V_7 -> V_14 = V_16 ;
}
return V_7 ;
}
static int F_9 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_24 * V_25 = F_10 ( V_22 -> V_26 ) ;
int V_27 ;
V_27 = F_11 ( V_25 -> V_28 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_11 ( V_25 -> V_29 ) ;
if ( V_27 ) {
F_12 ( V_25 -> V_28 ) ;
return V_27 ;
}
F_13 ( V_25 -> V_30 , V_31 , 0 ) ;
V_25 -> V_18 = V_18 ;
F_13 ( V_25 -> V_30 , V_32 , V_33 ) ;
return 0 ;
}
static void F_14 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_24 * V_25 = F_10 ( V_22 -> V_26 ) ;
F_13 ( V_25 -> V_30 , V_34 , V_35 ) ;
F_12 ( V_25 -> V_28 ) ;
F_12 ( V_25 -> V_29 ) ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_24 * V_25 = F_10 ( V_22 -> V_26 ) ;
T_1 V_36 ;
return F_16 ( V_25 -> V_30 , V_37 , & V_36 ) ;
}
static int
F_17 ( struct V_17 * V_18 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_24 * V_25 = F_10 ( V_22 -> V_26 ) ;
int V_27 ;
V_27 = F_18 ( V_18 , V_39 ,
V_41 ) ;
if ( V_27 ) {
F_2 ( V_22 -> V_42 -> V_3 ,
L_12 ) ;
return V_27 ;
}
V_41 -> V_43 = V_25 -> V_44 + V_37 ;
V_41 -> V_45 = 1 ;
V_41 -> V_46 = 1 ;
return 0 ;
}
static int F_19 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = F_20 ( V_48 ) ;
unsigned int V_53 , V_54 ;
int V_55 ;
V_53 = ( F_21 ( V_52 , V_56 ) & V_57 )
>> V_58 ;
V_54 = ( F_21 ( V_52 , V_59 ) & V_60 )
>> V_61 ;
for ( V_55 = 0 ; V_55 < F_22 ( V_62 ) ; V_55 ++ ) {
if ( ( V_62 [ V_55 ] . V_63 == V_53 ) &&
( V_62 [ V_55 ] . V_64 == V_54 ) )
V_50 -> V_65 . integer . V_65 [ 0 ] = V_55 ;
}
return 0 ;
}
static int F_23 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_66 * V_67 =
(struct V_66 * ) V_48 -> V_68 ;
struct V_51 * V_52 = F_20 ( V_48 ) ;
int V_69 = V_67 -> V_69 ;
unsigned int V_36 ;
int V_27 ;
V_36 = V_50 -> V_65 . integer . V_65 [ 0 ] ;
if ( V_36 > V_69 )
return - V_8 ;
V_27 = F_24 ( V_52 , V_56 , V_57 ,
V_62 [ V_36 ] . V_63 << V_58 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_24 ( V_52 , V_59 , V_60 ,
V_62 [ V_36 ] . V_64 << V_61 ) ;
if ( V_27 < 0 )
return V_27 ;
return 0 ;
}
static int F_25 ( struct V_51 * V_52 )
{
struct V_70 * V_26 = F_26 ( V_52 ) ;
struct V_24 * V_25 = F_10 ( V_26 ) ;
F_24 ( V_52 , V_56 , V_71 ,
( T_1 ) ( V_25 -> V_7 -> V_14 << V_72 ) ) ;
return 0 ;
}
static int
F_27 ( struct V_17 * V_18 ,
struct V_38 * V_39 ,
struct V_19 * V_73 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_24 * V_25 = F_10 ( V_22 -> V_26 ) ;
struct V_51 * V_52 = V_73 -> V_52 ;
unsigned int V_74 = V_18 -> V_75 -> V_76 . V_74 ;
unsigned int V_77 = V_18 -> V_75 -> V_76 . V_77 ;
int V_78 = F_28 ( V_39 ) ;
int V_79 = F_29 ( V_39 ) ;
unsigned long V_80 , V_81 ;
unsigned int V_82 ;
T_1 V_83 , V_84 , V_85 , V_86 ;
if ( F_30 ( V_39 ) != 1 ) {
F_2 ( V_52 -> V_3 ,
L_13 ) ;
return - V_8 ;
}
if ( ( V_78 < V_74 ) || ( V_78 > V_77 ) ) {
F_2 ( V_52 -> V_3 ,
L_14 ,
V_78 , V_74 , V_77 ) ;
return - V_8 ;
}
switch ( V_79 ) {
case 16 :
V_84 = ( V_87
<< V_88 ) ;
break;
case 32 :
V_84 = ( V_89
<< V_88 ) ;
break;
default:
return - V_8 ;
}
if ( ( V_78 << 7 ) > ( V_77 << 6 ) ) {
V_82 = V_78 << 6 ;
V_84 |= V_90 << V_91 ;
} else {
V_82 = V_78 << 7 ;
V_84 |= V_92 << V_91 ;
}
V_80 = F_31 ( V_25 -> V_29 ) ;
V_81 = F_31 ( V_25 -> V_28 ) ;
V_85 = ( T_1 ) ( V_80 / ( V_82 << 1 ) ) - 1 ;
V_86 = ( T_1 ) ( V_81 / ( V_82 << 1 ) ) - 1 ;
if ( ( V_85 > V_93 ) ||
( V_81 / ( ( V_86 + 1 ) << 1 ) <
V_80 / ( ( V_85 + 1 ) << 1 ) ) ) {
V_83 = V_86 << V_94 ;
V_83 |= V_95 << V_96 ;
} else {
V_83 = V_85 << V_94 ;
V_83 |= V_97 << V_96 ;
}
F_24 ( V_52 , V_98 ,
V_99 | V_100 , V_83 ) ;
F_24 ( V_52 , V_59 ,
V_101 | V_102 , V_84 ) ;
return 0 ;
}
static int F_32 ( struct V_17 * V_18 ,
struct V_19 * V_73 )
{
struct V_51 * V_52 = V_73 -> V_52 ;
F_24 ( V_52 , V_31 , V_103 ,
V_104 << V_105 ) ;
return 0 ;
}
static int F_33 ( struct V_17 * V_18 ,
int V_106 , struct V_19 * V_73 )
{
struct V_51 * V_52 = V_73 -> V_52 ;
T_1 V_36 ;
switch ( V_106 ) {
case V_107 :
case V_108 :
case V_109 :
V_36 = V_110 << V_105 ;
break;
case V_111 :
case V_112 :
case V_113 :
V_36 = V_104 << V_105 ;
break;
default:
return - V_8 ;
}
F_24 ( V_52 , V_31 , V_103 , V_36 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_70 * V_26 )
{
struct V_114 * V_115 ;
struct V_24 * V_25 = F_10 ( V_26 ) ;
V_115 = F_4 ( V_3 , sizeof( * V_115 ) , V_9 ) ;
if ( ! V_115 )
return - V_10 ;
V_115 -> V_116 = L_3 ;
V_115 -> V_117 = L_15 ;
V_115 -> V_118 = V_119 ;
V_115 -> V_120 = F_35 ( V_3 ) ;
V_115 -> V_121 = F_35 ( V_3 ) ;
V_115 -> V_122 = F_35 ( V_3 ) ;
V_26 -> V_115 = V_115 ;
V_26 -> V_123 = 1 ;
V_26 -> V_116 = V_25 -> V_7 -> V_11 ;
V_26 -> V_3 = V_3 ;
return 0 ;
}
static void F_36 ( struct V_24 * V_25 ,
unsigned int * V_74 , unsigned int * V_77 )
{
T_1 V_12 = V_25 -> V_7 -> V_12 ;
T_1 V_13 = V_25 -> V_7 -> V_13 ;
T_1 V_124 = ( T_1 ) ( F_31 ( V_25 -> V_29 ) >> 1 ) ;
T_1 V_125 = ( T_1 ) ( F_31 ( V_25 -> V_28 ) >> 8 ) ;
if ( V_13 > V_124 )
V_13 = V_124 ;
if ( V_12 < V_125 )
V_12 = V_125 ;
* V_74 = F_37 ( V_12 , 128 ) ;
* V_77 = V_13 >> 6 ;
}
static T_2 F_38 ( int V_126 , void * V_127 )
{
struct V_24 * V_25 = (struct V_24 * ) V_127 ;
T_1 V_128 ;
T_2 V_27 = V_129 ;
F_16 ( V_25 -> V_30 , V_130 , & V_128 ) ;
if ( V_128 & V_131 ) {
F_39 ( V_25 -> V_30 , V_31 , V_103 ,
V_104 << V_105 ) ;
F_40 ( V_25 -> V_18 ) ;
V_27 = V_132 ;
}
return V_27 ;
}
static int F_41 ( struct V_133 * V_134 )
{
struct V_2 * V_3 = & V_134 -> V_3 ;
struct V_24 * V_25 ;
struct V_135 * V_136 ;
void T_3 * V_137 ;
const struct V_1 * V_7 ;
struct V_70 * V_26 ;
unsigned int V_74 , V_77 ;
int V_27 ;
V_7 = F_1 ( V_3 ) ;
if ( F_42 ( V_7 ) )
return F_43 ( V_7 ) ;
V_25 = F_4 ( V_3 , sizeof( * V_25 ) , V_9 ) ;
if ( ! V_25 )
return - V_10 ;
V_25 -> V_7 = V_7 ;
V_25 -> V_126 = F_44 ( V_134 , 0 ) ;
if ( V_25 -> V_126 < 0 ) {
V_27 = V_25 -> V_126 ;
F_2 ( V_3 , L_16 , V_27 ) ;
return V_27 ;
}
V_25 -> V_29 = F_45 ( V_3 , L_17 ) ;
if ( F_42 ( V_25 -> V_29 ) ) {
V_27 = F_43 ( V_25 -> V_29 ) ;
F_2 ( V_3 , L_18 , V_27 ) ;
return V_27 ;
}
V_25 -> V_28 = F_45 ( V_3 , L_19 ) ;
if ( F_42 ( V_25 -> V_28 ) ) {
V_27 = F_43 ( V_25 -> V_28 ) ;
F_2 ( V_3 , L_20 , V_27 ) ;
return V_27 ;
}
V_27 = F_46 ( V_25 -> V_28 , F_31 ( V_25 -> V_29 ) / 3 ) ;
if ( V_27 ) {
F_2 ( V_3 , L_21 , V_27 ) ;
return V_27 ;
}
V_136 = F_47 ( V_134 , V_138 , 0 ) ;
V_137 = F_48 ( V_3 , V_136 ) ;
if ( F_42 ( V_137 ) ) {
V_27 = F_43 ( V_137 ) ;
F_2 ( V_3 , L_22 , V_27 ) ;
return V_27 ;
}
V_25 -> V_44 = V_136 -> V_139 ;
V_25 -> V_30 = F_49 ( V_3 , V_137 ,
& V_140 ) ;
if ( F_42 ( V_25 -> V_30 ) ) {
V_27 = F_43 ( V_25 -> V_30 ) ;
F_2 ( V_3 , L_23 , V_27 ) ;
return V_27 ;
}
V_27 = F_50 ( V_3 , V_25 -> V_126 , F_38 , 0 ,
L_3 , ( void * ) V_25 ) ;
if ( V_27 < 0 ) {
F_2 ( V_3 , L_24 ,
V_25 -> V_126 , V_27 ) ;
return V_27 ;
}
F_36 ( V_25 , & V_74 , & V_77 ) ;
V_141 . V_142 . V_74 = V_74 ;
V_141 . V_142 . V_77 = V_77 ;
V_27 = F_51 ( V_3 ,
& V_143 ,
& V_141 , 1 ) ;
if ( V_27 ) {
F_2 ( V_3 , L_25 , V_27 ) ;
return V_27 ;
}
V_27 = F_52 ( V_3 ,
& V_144 ,
0 ) ;
if ( V_27 ) {
F_2 ( V_3 , L_26 , V_27 ) ;
return V_27 ;
}
V_145 . V_142 . V_74 = V_74 ;
V_145 . V_142 . V_77 = V_77 ;
V_27 = F_53 ( V_3 , & V_146 ,
& V_145 , 1 ) ;
if ( V_27 ) {
F_2 ( V_3 , L_27 , V_27 ) ;
return V_27 ;
}
V_26 = F_4 ( V_3 , sizeof( * V_26 ) , V_9 ) ;
if ( ! V_26 ) {
V_27 = - V_10 ;
goto V_147;
}
F_54 ( V_26 , V_25 ) ;
V_27 = F_34 ( V_3 , V_26 ) ;
if ( V_27 ) {
F_2 ( V_3 , L_28 , V_27 ) ;
goto V_147;
}
V_27 = F_55 ( V_3 , V_26 ) ;
if ( V_27 ) {
F_2 ( V_3 , L_29 , V_27 ) ;
goto V_147;
}
return 0 ;
V_147:
F_56 ( V_3 ) ;
return V_27 ;
}
static int F_57 ( struct V_133 * V_134 )
{
F_56 ( & V_134 -> V_3 ) ;
return 0 ;
}
