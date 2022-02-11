static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
if ( V_2 -> V_5 ) {
V_4 = F_2 ( V_6 , V_2 -> V_5 ) ;
if ( V_4 && V_4 -> V_7 )
return ( (struct V_8 * ) V_4 -> V_7 ) -> type ;
}
return V_9 ;
}
static void F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_4 ( V_11 -> V_14 ) ;
struct V_15 * V_16 = V_11 -> V_17 ;
struct V_18 * V_19 = V_13 -> V_19 ;
T_1 T_2 * V_20 = & V_19 -> V_20 ;
unsigned long V_21 ;
if ( V_16 -> V_22 == F_5 ( V_20 ) )
return;
F_6 ( V_21 ) ;
F_7 ( V_20 , V_16 -> V_22 & ~ V_23 ) ;
if ( V_13 -> V_21 & V_24 ) {
F_8 ( V_13 ) ;
}
F_7 ( V_20 , V_16 -> V_22 ) ;
F_9 ( V_21 ) ;
}
static void F_10 ( struct V_10 * V_11 , int V_25 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
struct V_26 * V_27 ;
bool V_28 = V_11 -> V_20 & V_29 ;
struct V_15 * V_16 = V_11 -> V_17 ;
V_27 = V_11 -> V_2 . V_30 -> V_30 -> V_31 ;
if ( V_25 == V_32 ) {
if ( V_27 -> V_33 )
V_27 -> V_33 ( V_11 , ! V_28 ) ;
}
if ( V_25 == V_34 ) {
V_12 -> V_35 = V_16 -> V_35 ;
V_12 -> V_36 = V_16 -> V_36 ;
V_12 -> V_37 = V_16 -> V_37 ;
V_12 -> V_38 = V_16 -> V_38 ;
F_3 ( V_11 ) ;
if ( V_27 -> V_33 )
V_27 -> V_33 ( V_11 , V_28 ) ;
}
}
static void F_11 ( T_3 * V_35 , T_3 * V_36 ,
int V_39 , int V_40 )
{
* V_35 = 0 ;
* V_36 = 0 ;
if ( V_40 ) {
if ( V_39 <= 8 ) {
* V_35 = 16 ;
* V_36 = 24 ;
} else if ( V_39 <= 16 ) {
* V_35 = 16 ;
* V_36 = 16 ;
}
} else {
if ( V_39 <= 8 )
* V_35 = 8 ;
}
}
static void F_12 ( T_3 * V_35 , T_3 * V_36 ,
int V_39 , int V_40 )
{
* V_35 = 0 ;
* V_36 = 0 ;
if ( V_39 <= 16 ) {
if ( V_40 ) {
* V_35 = 16 ;
* V_36 = 32 - V_39 ;
} else {
* V_35 = 16 - V_39 ;
}
}
}
static int F_13 ( struct V_15 * V_16 ,
struct V_10 * V_11 ,
struct V_12 * V_12 ,
int V_39 )
{
V_16 -> V_35 = 0 ;
V_16 -> V_36 = 0 ;
if ( V_39 <= 8 ) {
V_16 -> V_37 = V_41 ;
V_16 -> V_38 = V_42 ;
} else if ( V_39 <= 16 ) {
V_16 -> V_37 = V_43 ;
V_16 -> V_38 = V_44 ;
} else if ( V_39 <= 32 ) {
V_16 -> V_37 = V_45 ;
V_16 -> V_38 = V_46 ;
} else
return - V_47 ;
if ( V_12 -> V_48 )
V_12 -> V_48 ( & V_16 -> V_35 , & V_16 -> V_36 ,
V_39 ,
! ( V_11 -> V_20 & V_49 ) ) ;
V_12 -> V_35 = V_16 -> V_35 ;
V_12 -> V_36 = V_16 -> V_36 ;
V_12 -> V_37 = V_16 -> V_37 ;
V_12 -> V_38 = V_16 -> V_38 ;
return V_39 ;
}
static int F_14 ( struct V_15 * V_16 ,
struct V_10 * V_11 ,
int V_39 )
{
if ( V_11 -> V_20 & V_49 &&
V_39 > 8 )
return - V_47 ;
if ( V_39 > 8 )
return 8 ;
return V_39 ;
}
static int F_15 ( struct V_10 * V_11 ,
struct V_50 * V_51 )
{
struct V_12 * V_12 ;
int V_39 = 0 ;
T_4 V_52 ;
T_3 V_53 = 0 ;
struct V_15 * V_16 = V_11 -> V_17 ;
V_12 = F_4 ( V_11 -> V_14 ) ;
if ( V_51 ) {
V_39 = V_51 -> V_39 ;
V_53 = V_51 -> V_54 ;
}
if ( ! V_39 )
V_39 = V_11 -> V_39 ;
if ( ! V_53 )
V_53 = V_11 -> V_55 ;
if ( ! ( V_12 -> V_21 & V_24 ) )
V_39 = F_13 ( V_16 , V_11 ,
V_12 ,
V_39 ) ;
else if ( V_12 -> V_21 & V_56 )
V_39 = F_14 ( V_16 , V_11 ,
V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 == 32 )
V_39 = 0 ;
else
V_39 = V_39 - 1 ;
V_16 -> V_22 &= ~ ( F_16 ( 0xF ) | V_57
| F_17 ( 0xF ) ) ;
V_16 -> V_22 |= F_16 ( V_39 ) ;
if ( ( V_12 -> V_58 / V_53 ) > 64 ) {
V_16 -> V_22 |= V_57 ;
V_52 = ( V_12 -> V_58 - 1 ) / ( V_53 * 64 ) + 1 ;
F_18 ( V_52 > 16 ,
L_1 ,
F_19 ( & V_11 -> V_2 ) , V_53 , V_12 -> V_58 / 1024 ) ;
if ( V_52 > 16 )
V_52 = 16 ;
} else {
V_52 = ( V_12 -> V_58 - 1 ) / ( V_53 * 4 ) + 1 ;
}
if ( V_52 )
V_52 -- ;
V_16 -> V_22 |= F_17 ( V_52 ) ;
F_3 ( V_11 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_50 * V_51 , unsigned int V_59 )
{
T_3 V_60 ;
struct V_18 * V_19 = V_13 -> V_19 ;
V_13 -> V_61 = V_59 ;
F_7 ( & V_19 -> V_62 , V_63 ) ;
V_60 = V_13 -> V_38 ( V_13 ) ;
F_7 ( & V_19 -> V_64 , V_60 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 , struct V_50 * V_51 ,
bool V_65 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
struct V_18 * V_19 ;
unsigned int V_59 = V_51 -> V_59 ;
T_4 V_39 ;
int V_66 ;
V_19 = V_12 -> V_19 ;
V_39 = V_11 -> V_39 ;
if ( V_51 -> V_39 )
V_39 = V_51 -> V_39 ;
if ( V_39 > 8 ) {
if ( V_59 & 1 )
return - V_47 ;
V_59 /= 2 ;
}
if ( V_39 > 16 ) {
if ( V_59 & 1 )
return - V_47 ;
V_59 /= 2 ;
}
V_12 -> V_67 = V_51 -> V_68 ;
V_12 -> V_69 = V_51 -> V_70 ;
F_22 ( & V_12 -> V_71 ) ;
if ( V_12 -> V_21 & V_24 )
V_66 = F_23 ( V_12 , V_51 , V_65 ) ;
else
V_66 = F_20 ( V_12 , V_51 , V_59 ) ;
if ( V_66 )
return V_66 ;
F_24 ( & V_12 -> V_71 ) ;
F_7 ( & V_19 -> V_62 , 0 ) ;
if ( V_12 -> V_21 & V_24 )
F_25 ( V_12 ) ;
return V_12 -> V_61 ;
}
static int F_26 ( struct V_72 * V_14 ,
struct V_73 * V_74 )
{
struct V_10 * V_11 = V_74 -> V_11 ;
struct V_50 * V_51 , * V_75 ;
unsigned int V_76 ;
const int V_77 = 50 ;
int V_78 ;
V_75 = F_27 ( & V_74 -> V_79 , struct V_50 ,
V_80 ) ;
F_28 (t, &m->transfers, transfer_list) {
if ( ( V_75 -> V_39 != V_51 -> V_39 ) ||
( V_75 -> V_54 != V_51 -> V_54 ) ) {
F_29 ( & V_11 -> V_2 ,
L_2 ) ;
return - V_47 ;
}
}
V_76 = 1 ;
V_78 = - V_47 ;
F_28 (t, &m->transfers, transfer_list) {
if ( V_51 -> V_39 || V_51 -> V_54 ) {
if ( V_76 )
V_78 = F_15 ( V_11 , V_51 ) ;
if ( V_78 < 0 )
break;
}
if ( V_76 ) {
F_10 ( V_11 , V_34 ) ;
F_30 ( V_77 ) ;
}
V_76 = V_51 -> V_76 ;
if ( V_51 -> V_59 )
V_78 = F_21 ( V_11 , V_51 , V_74 -> V_65 ) ;
if ( V_78 ) {
V_78 = - V_81 ;
break;
}
V_74 -> V_82 += V_51 -> V_59 ;
if ( V_51 -> V_83 )
F_31 ( V_51 -> V_83 ) ;
if ( V_76 ) {
F_30 ( V_77 ) ;
F_10 ( V_11 , V_32 ) ;
F_30 ( V_77 ) ;
}
}
V_74 -> V_78 = V_78 ;
F_32 ( V_14 ) ;
if ( V_78 || ! V_76 ) {
F_30 ( V_77 ) ;
F_10 ( V_11 , V_32 ) ;
}
F_15 ( V_11 , NULL ) ;
return 0 ;
}
static int F_33 ( struct V_10 * V_11 )
{
struct V_12 * V_12 ;
struct V_18 * V_19 ;
int V_84 ;
T_3 V_22 ;
struct V_15 * V_16 = F_34 ( V_11 ) ;
if ( ! V_11 -> V_55 )
return - V_47 ;
if ( ! V_16 ) {
V_16 = F_35 ( sizeof( * V_16 ) , V_85 ) ;
if ( ! V_16 )
return - V_86 ;
F_36 ( V_11 , V_16 ) ;
}
V_12 = F_4 ( V_11 -> V_14 ) ;
V_19 = V_12 -> V_19 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = F_5 ( & V_19 -> V_20 ) ;
V_16 -> V_22 &= ~ ( V_87 | V_88
| V_89 | V_90 ) ;
if ( V_11 -> V_20 & V_91 )
V_16 -> V_22 |= V_87 ;
if ( V_11 -> V_20 & V_92 )
V_16 -> V_22 |= V_88 ;
if ( ! ( V_11 -> V_20 & V_49 ) )
V_16 -> V_22 |= V_89 ;
if ( V_11 -> V_20 & V_93 )
V_16 -> V_22 |= V_90 ;
V_84 = F_15 ( V_11 , NULL ) ;
if ( V_84 < 0 ) {
V_16 -> V_22 = V_22 ;
return V_84 ;
}
if ( V_12 -> type == V_94 ) {
if ( F_37 ( V_11 -> V_95 ) ) {
int V_96 ;
V_84 = F_38 ( V_11 -> V_95 ,
F_19 ( & V_11 -> V_2 ) ) ;
if ( V_84 )
return V_84 ;
V_96 = ! ( V_11 -> V_20 & V_29 ) ;
V_84 = F_39 ( V_11 -> V_95 , V_96 ) ;
if ( V_84 ) {
F_40 ( V_11 -> V_95 ) ;
return V_84 ;
}
} else if ( V_11 -> V_95 != - V_97 ) {
if ( V_11 -> V_95 < 0 )
return V_11 -> V_95 ;
return - V_47 ;
}
}
F_10 ( V_11 , V_32 ) ;
return 0 ;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
struct V_15 * V_16 = F_34 ( V_11 ) ;
if ( V_12 -> type == V_94 && F_37 ( V_11 -> V_95 ) )
F_40 ( V_11 -> V_95 ) ;
F_42 ( V_16 ) ;
F_36 ( V_11 , NULL ) ;
}
static void F_43 ( struct V_12 * V_13 , T_3 V_98 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
if ( V_98 & V_99 ) {
T_3 V_100 = F_5 ( & V_19 -> V_101 ) ;
if ( V_13 -> V_69 )
V_13 -> V_37 ( V_100 , V_13 ) ;
}
if ( ( V_98 & V_102 ) == 0 )
while ( ( ( V_98 =
F_5 ( & V_19 -> V_103 ) ) &
V_102 ) == 0 )
F_44 () ;
F_7 ( & V_19 -> V_103 , V_98 ) ;
V_13 -> V_61 -= 1 ;
if ( V_13 -> V_61 ) {
T_3 V_60 = V_13 -> V_38 ( V_13 ) ;
F_7 ( & V_19 -> V_64 , V_60 ) ;
} else {
F_45 ( & V_13 -> V_71 ) ;
}
}
static T_5 F_46 ( T_6 V_104 , void * V_105 )
{
struct V_12 * V_13 = V_105 ;
T_5 V_66 = V_106 ;
T_3 V_98 ;
struct V_18 * V_19 = V_13 -> V_19 ;
V_98 = F_5 ( & V_19 -> V_103 ) ;
if ( V_98 )
V_66 = V_107 ;
F_47 ( V_13 -> V_2 , L_3 , V_108 , V_98 ) ;
if ( V_13 -> V_21 & V_24 )
F_48 ( V_13 , V_98 ) ;
else
F_43 ( V_13 , V_98 ) ;
return V_66 ;
}
static void F_49 ( struct V_10 * V_11 , bool V_109 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
struct V_18 * V_19 = V_12 -> V_19 ;
T_3 V_110 ;
T_7 V_16 = V_11 -> V_111 ;
if ( F_37 ( V_11 -> V_95 ) ) {
F_50 ( V_11 -> V_95 , V_109 ) ;
} else if ( V_16 < V_12 -> V_112 ) {
V_110 = F_5 ( & V_19 -> V_110 ) ;
V_110 = V_109 ? ( V_110 | ( 1 << V_16 ) ) : ( V_110 & ~ ( 1 << V_16 ) ) ;
F_7 ( & V_19 -> V_110 , V_110 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_52 ( V_2 ) ;
struct V_72 * V_14 = F_53 ( V_2 ) ;
struct V_12 * V_12 = F_4 ( V_14 ) ;
struct V_18 * V_19 = V_12 -> V_19 ;
int V_113 ;
T_3 V_114 ;
V_114 = F_5 ( & V_19 -> V_115 ) ;
V_12 -> V_48 = F_12 ;
V_113 = F_54 ( V_114 ) ;
if ( V_113 )
V_12 -> V_116 = V_113 + 1 ;
V_12 -> V_112 = 0 ;
if ( F_55 ( V_114 ) ) {
V_12 -> V_112 = F_56 ( V_114 ) ;
F_7 ( & V_19 -> V_110 , 0xffffffff ) ;
}
V_14 -> V_117 = V_12 -> V_112 ;
V_27 -> V_33 = F_49 ;
}
static struct V_72 * F_57 ( struct V_1 * V_2 ,
struct V_118 * V_119 , unsigned int V_104 )
{
struct V_26 * V_27 = F_52 ( V_2 ) ;
struct V_72 * V_14 ;
struct V_12 * V_12 ;
struct V_18 * V_19 ;
T_3 V_120 ;
int V_66 = 0 ;
V_14 = F_58 ( V_2 , sizeof( struct V_12 ) ) ;
if ( V_14 == NULL ) {
V_66 = - V_86 ;
goto V_121;
}
F_59 ( V_2 , V_14 ) ;
F_60 ( V_2 , V_119 , V_104 ) ;
V_14 -> V_122 = F_33 ;
V_14 -> V_123 = F_41 ;
V_14 -> V_124 = F_26 ;
V_12 = F_4 ( V_14 ) ;
V_12 -> V_116 = 32 ;
V_12 -> type = F_1 ( V_2 ) ;
V_66 = F_61 ( V_12 ) ;
if ( V_66 )
goto V_125;
V_12 -> V_19 = F_62 ( V_2 , V_119 ) ;
if ( F_63 ( V_12 -> V_19 ) ) {
V_66 = F_64 ( V_12 -> V_19 ) ;
goto V_126;
}
if ( V_12 -> type == V_94 )
F_51 ( V_2 ) ;
V_14 -> V_127 =
( F_65 ( 4 , 16 ) | F_66 ( 32 ) ) &
F_65 ( 1 , V_12 -> V_116 ) ;
if ( V_12 -> V_21 & V_128 )
V_12 -> V_48 = F_11 ;
if ( V_12 -> V_48 )
V_12 -> V_48 ( & V_12 -> V_35 ,
& V_12 -> V_36 , 8 , 1 ) ;
V_66 = F_67 ( V_2 , V_12 -> V_104 , F_46 ,
0 , L_4 , V_12 ) ;
if ( V_66 != 0 )
goto V_126;
V_19 = V_12 -> V_19 ;
F_7 ( & V_19 -> V_20 , 0 ) ;
F_7 ( & V_19 -> V_62 , 0 ) ;
F_7 ( & V_19 -> V_129 , 0 ) ;
F_7 ( & V_19 -> V_103 , 0xffffffff ) ;
V_120 = V_27 -> V_130 | V_131 | V_23 ;
if ( V_12 -> V_116 < 8 ) {
V_120 &= ~ F_16 ( 0xF ) ;
V_120 |= F_16 ( V_12 -> V_116 - 1 ) ;
}
if ( V_12 -> V_21 & V_128 )
V_120 |= V_132 ;
F_7 ( & V_19 -> V_20 , V_120 ) ;
V_66 = F_68 ( V_2 , V_14 ) ;
if ( V_66 < 0 )
goto V_126;
F_69 ( V_2 , L_5 , V_19 ,
V_12 -> V_104 , F_70 ( V_12 -> V_21 ) ) ;
return V_14 ;
V_126:
F_71 ( V_12 ) ;
V_125:
F_72 ( V_14 ) ;
V_121:
return F_73 ( V_66 ) ;
}
static void F_74 ( struct V_10 * V_11 , bool V_109 )
{
struct V_1 * V_2 = V_11 -> V_2 . V_30 -> V_30 ;
struct V_26 * V_27 = F_52 ( V_2 ) ;
struct V_133 * V_134 = F_75 ( V_27 ) ;
T_7 V_16 = V_11 -> V_111 ;
int V_135 = V_134 -> V_136 [ V_16 ] ;
bool V_137 = V_134 -> V_138 [ V_16 ] ;
F_50 ( V_135 , V_109 ^ V_137 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_139 * V_140 = V_2 -> V_5 ;
struct V_26 * V_27 = F_52 ( V_2 ) ;
struct V_133 * V_134 = F_75 ( V_27 ) ;
int V_141 ;
int V_142 = 0 ;
int V_66 ;
V_141 = F_77 ( V_140 ) ;
if ( V_141 <= 0 ) {
V_27 -> V_143 = 1 ;
return 0 ;
}
V_134 -> V_136 = F_78 ( V_141 , sizeof( * V_134 -> V_136 ) ,
V_85 ) ;
if ( ! V_134 -> V_136 )
return - V_86 ;
memset ( V_134 -> V_136 , - 1 , V_141 * sizeof( * V_134 -> V_136 ) ) ;
V_134 -> V_138 = F_79 ( V_141 , sizeof( * V_134 -> V_138 ) ,
V_85 ) ;
if ( ! V_134 -> V_138 ) {
V_66 = - V_86 ;
goto V_144;
}
for (; V_142 < V_141 ; V_142 ++ ) {
int V_135 ;
enum V_145 V_21 ;
V_135 = F_80 ( V_140 , V_142 , & V_21 ) ;
if ( ! F_37 ( V_135 ) ) {
F_29 ( V_2 , L_6 , V_142 , V_135 ) ;
V_66 = V_135 ;
goto V_146;
}
V_66 = F_38 ( V_135 , F_19 ( V_2 ) ) ;
if ( V_66 ) {
F_29 ( V_2 , L_7 , V_142 , V_66 ) ;
goto V_146;
}
V_134 -> V_136 [ V_142 ] = V_135 ;
V_134 -> V_138 [ V_142 ] = V_21 & V_147 ;
V_66 = F_39 ( V_134 -> V_136 [ V_142 ] ,
V_134 -> V_138 [ V_142 ] ) ;
if ( V_66 ) {
F_29 ( V_2 ,
L_8 ,
V_142 , V_66 ) ;
goto V_146;
}
}
V_27 -> V_143 = V_141 ;
V_27 -> V_33 = F_74 ;
return 0 ;
V_146:
while ( V_142 >= 0 ) {
if ( F_37 ( V_134 -> V_136 [ V_142 ] ) )
F_40 ( V_134 -> V_136 [ V_142 ] ) ;
V_142 -- ;
}
F_42 ( V_134 -> V_138 ) ;
V_134 -> V_138 = NULL ;
V_144:
F_42 ( V_134 -> V_136 ) ;
V_134 -> V_136 = NULL ;
return V_66 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_52 ( V_2 ) ;
struct V_133 * V_134 = F_75 ( V_27 ) ;
int V_142 ;
if ( ! V_134 -> V_136 )
return 0 ;
for ( V_142 = 0 ; V_142 < V_27 -> V_143 ; V_142 ++ ) {
if ( F_37 ( V_134 -> V_136 [ V_142 ] ) )
F_40 ( V_134 -> V_136 [ V_142 ] ) ;
}
F_42 ( V_134 -> V_136 ) ;
F_42 ( V_134 -> V_138 ) ;
return 0 ;
}
static int F_82 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = & V_149 -> V_2 ;
struct V_139 * V_140 = V_149 -> V_2 . V_5 ;
struct V_72 * V_14 ;
struct V_118 V_119 ;
int V_104 = 0 , type ;
int V_66 = - V_86 ;
V_66 = F_83 ( V_149 ) ;
if ( V_66 )
return V_66 ;
type = F_1 ( & V_149 -> V_2 ) ;
if ( type == V_9 ) {
V_66 = F_76 ( V_2 ) ;
if ( V_66 )
goto V_121;
}
V_66 = F_84 ( V_140 , 0 , & V_119 ) ;
if ( V_66 )
goto V_121;
V_104 = F_85 ( V_140 , 0 ) ;
if ( ! V_104 ) {
V_66 = - V_47 ;
goto V_121;
}
V_14 = F_57 ( V_2 , & V_119 , V_104 ) ;
if ( F_63 ( V_14 ) ) {
V_66 = F_64 ( V_14 ) ;
goto V_121;
}
return 0 ;
V_121:
F_86 ( V_104 ) ;
if ( type == V_9 )
F_81 ( V_2 ) ;
return V_66 ;
}
static int F_87 ( struct V_148 * V_149 )
{
struct V_72 * V_14 = F_88 ( V_149 ) ;
struct V_12 * V_12 = F_4 ( V_14 ) ;
F_71 ( V_12 ) ;
if ( V_12 -> type == V_9 )
F_81 ( & V_149 -> V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_148 * V_150 )
{
struct V_118 * V_119 ;
int V_104 ;
struct V_72 * V_14 ;
if ( ! F_52 ( & V_150 -> V_2 ) )
return - V_47 ;
V_119 = F_90 ( V_150 , V_151 , 0 ) ;
if ( ! V_119 )
return - V_47 ;
V_104 = F_91 ( V_150 , 0 ) ;
if ( V_104 <= 0 )
return - V_47 ;
V_14 = F_57 ( & V_150 -> V_2 , V_119 , V_104 ) ;
return F_92 ( V_14 ) ;
}
static int F_93 ( struct V_148 * V_150 )
{
struct V_72 * V_14 = F_88 ( V_150 ) ;
struct V_12 * V_12 = F_4 ( V_14 ) ;
F_71 ( V_12 ) ;
return 0 ;
}
static void T_8 F_94 ( void )
{
V_152 = F_95 ( & V_153 ) ;
}
static void T_9 F_96 ( void )
{
if ( V_152 )
return;
F_97 ( & V_153 ) ;
}
static void T_8 F_94 ( void ) {}
static void T_9 F_96 ( void ) {}
static int T_8 F_98 ( void )
{
F_94 () ;
return F_95 ( & V_154 ) ;
}
static void T_9 F_99 ( void )
{
F_97 ( & V_154 ) ;
F_96 () ;
}
