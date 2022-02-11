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
F_18 ( V_52 > 16 , L_1
L_2 , F_19 ( & V_11 -> V_2 ) ,
V_53 , V_12 -> V_58 / 1024 ) ;
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
static void F_26 ( struct V_72 * V_73 )
{
struct V_10 * V_11 = V_73 -> V_11 ;
struct V_50 * V_51 , * V_74 ;
unsigned int V_75 ;
const int V_76 = 50 ;
int V_77 ;
V_74 = F_27 ( & V_73 -> V_78 , struct V_50 ,
V_79 ) ;
F_28 (t, &m->transfers, transfer_list) {
if ( ( V_74 -> V_39 != V_51 -> V_39 ) ||
( V_74 -> V_54 != V_51 -> V_54 ) ) {
V_77 = - V_47 ;
F_29 ( & V_11 -> V_2 ,
L_3 ) ;
return;
}
}
V_75 = 1 ;
V_77 = - V_47 ;
F_28 (t, &m->transfers, transfer_list) {
if ( V_51 -> V_39 || V_51 -> V_54 ) {
if ( V_75 )
V_77 = F_15 ( V_11 , V_51 ) ;
if ( V_77 < 0 )
break;
}
if ( V_75 ) {
F_10 ( V_11 , V_34 ) ;
F_30 ( V_76 ) ;
}
V_75 = V_51 -> V_75 ;
if ( V_51 -> V_59 )
V_77 = F_21 ( V_11 , V_51 , V_73 -> V_65 ) ;
if ( V_77 ) {
V_77 = - V_80 ;
break;
}
V_73 -> V_81 += V_51 -> V_59 ;
if ( V_51 -> V_82 )
F_31 ( V_51 -> V_82 ) ;
if ( V_75 ) {
F_30 ( V_76 ) ;
F_10 ( V_11 , V_32 ) ;
F_30 ( V_76 ) ;
}
}
V_73 -> V_77 = V_77 ;
if ( V_73 -> V_83 )
V_73 -> V_83 ( V_73 -> V_84 ) ;
if ( V_77 || ! V_75 ) {
F_30 ( V_76 ) ;
F_10 ( V_11 , V_32 ) ;
}
F_15 ( V_11 , NULL ) ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_12 * V_12 ;
struct V_18 * V_19 ;
int V_85 ;
T_3 V_22 ;
struct V_15 * V_16 = V_11 -> V_17 ;
if ( ! V_11 -> V_55 )
return - V_47 ;
if ( ! V_16 ) {
V_16 = F_33 ( sizeof *V_16 , V_86 ) ;
if ( ! V_16 )
return - V_87 ;
V_11 -> V_17 = V_16 ;
}
V_12 = F_4 ( V_11 -> V_14 ) ;
V_19 = V_12 -> V_19 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = F_5 ( & V_19 -> V_20 ) ;
V_16 -> V_22 &= ~ ( V_88 | V_89
| V_90 | V_91 ) ;
if ( V_11 -> V_20 & V_92 )
V_16 -> V_22 |= V_88 ;
if ( V_11 -> V_20 & V_93 )
V_16 -> V_22 |= V_89 ;
if ( ! ( V_11 -> V_20 & V_49 ) )
V_16 -> V_22 |= V_90 ;
if ( V_11 -> V_20 & V_94 )
V_16 -> V_22 |= V_91 ;
V_85 = F_15 ( V_11 , NULL ) ;
if ( V_85 < 0 ) {
V_16 -> V_22 = V_22 ;
return V_85 ;
}
if ( V_12 -> type == V_95 ) {
if ( F_34 ( V_11 -> V_96 ) ) {
int V_97 ;
V_85 = F_35 ( V_11 -> V_96 ,
F_19 ( & V_11 -> V_2 ) ) ;
if ( V_85 )
return V_85 ;
V_97 = ! ( V_11 -> V_20 & V_29 ) ;
V_85 = F_36 ( V_11 -> V_96 , V_97 ) ;
if ( V_85 ) {
F_37 ( V_11 -> V_96 ) ;
return V_85 ;
}
} else if ( V_11 -> V_96 != - V_98 ) {
if ( V_11 -> V_96 < 0 )
return V_11 -> V_96 ;
return - V_47 ;
}
}
F_10 ( V_11 , V_32 ) ;
return 0 ;
}
static void F_38 ( struct V_10 * V_11 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
if ( V_12 -> type == V_95 && F_34 ( V_11 -> V_96 ) )
F_37 ( V_11 -> V_96 ) ;
}
static void F_39 ( struct V_12 * V_13 , T_3 V_99 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
if ( V_99 & V_100 ) {
T_3 V_101 = F_5 ( & V_19 -> V_102 ) ;
if ( V_13 -> V_69 )
V_13 -> V_37 ( V_101 , V_13 ) ;
}
if ( ( V_99 & V_103 ) == 0 )
while ( ( ( V_99 =
F_5 ( & V_19 -> V_104 ) ) &
V_103 ) == 0 )
F_40 () ;
F_7 ( & V_19 -> V_104 , V_99 ) ;
V_13 -> V_61 -= 1 ;
if ( V_13 -> V_61 ) {
T_3 V_60 = V_13 -> V_38 ( V_13 ) ;
F_7 ( & V_19 -> V_64 , V_60 ) ;
} else {
V_83 ( & V_13 -> V_71 ) ;
}
}
static T_5 F_41 ( T_6 V_105 , void * V_106 )
{
struct V_12 * V_13 = V_106 ;
T_5 V_66 = V_107 ;
T_3 V_99 ;
struct V_18 * V_19 = V_13 -> V_19 ;
V_99 = F_5 ( & V_19 -> V_104 ) ;
if ( V_99 )
V_66 = V_108 ;
F_42 ( V_13 -> V_2 , L_4 , V_109 , V_99 ) ;
if ( V_13 -> V_21 & V_24 )
F_43 ( V_13 , V_99 ) ;
else
F_39 ( V_13 , V_99 ) ;
return V_66 ;
}
static void F_44 ( struct V_12 * V_13 )
{
F_45 ( V_13 -> V_19 ) ;
F_46 ( V_13 ) ;
}
static void F_47 ( struct V_10 * V_11 , bool V_110 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
struct V_18 * V_19 = V_12 -> V_19 ;
T_3 V_111 ;
T_7 V_16 = V_11 -> V_112 ;
if ( F_34 ( V_11 -> V_96 ) ) {
F_48 ( V_11 -> V_96 , V_110 ) ;
} else if ( V_16 < V_12 -> V_113 ) {
V_111 = F_5 ( & V_19 -> V_111 ) ;
V_111 = V_110 ? ( V_111 | ( 1 << V_16 ) ) : ( V_111 & ~ ( 1 << V_16 ) ) ;
F_7 ( & V_19 -> V_111 , V_111 ) ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_50 ( V_2 ) ;
struct V_114 * V_14 = F_51 ( V_2 ) ;
struct V_12 * V_12 = F_4 ( V_14 ) ;
struct V_18 * V_19 = V_12 -> V_19 ;
int V_115 ;
T_3 V_116 ;
V_116 = F_5 ( & V_19 -> V_117 ) ;
V_12 -> V_48 = F_12 ;
V_115 = F_52 ( V_116 ) ;
if ( V_115 )
V_12 -> V_118 = V_115 + 1 ;
V_12 -> V_113 = 0 ;
if ( F_53 ( V_116 ) ) {
V_12 -> V_113 = F_54 ( V_116 ) ;
F_7 ( & V_19 -> V_111 , 0xffffffff ) ;
}
V_14 -> V_119 = V_12 -> V_113 ;
V_27 -> V_33 = F_47 ;
}
static struct V_114 * F_55 ( struct V_1 * V_2 ,
struct V_120 * V_121 , unsigned int V_105 )
{
struct V_26 * V_27 = F_50 ( V_2 ) ;
struct V_114 * V_14 ;
struct V_12 * V_12 ;
struct V_18 * V_19 ;
T_3 V_122 ;
int V_66 = 0 ;
V_14 = F_56 ( V_2 , sizeof( struct V_12 ) ) ;
if ( V_14 == NULL ) {
V_66 = - V_87 ;
goto V_123;
}
F_57 ( V_2 , V_14 ) ;
V_66 = F_58 ( V_2 , V_121 , V_105 ) ;
if ( V_66 )
goto V_124;
V_14 -> V_125 = F_32 ;
V_14 -> V_126 = F_38 ;
V_12 = F_4 ( V_14 ) ;
V_12 -> V_127 = F_26 ;
V_12 -> V_128 = F_44 ;
V_12 -> V_118 = 32 ;
V_12 -> type = F_1 ( V_2 ) ;
V_66 = F_59 ( V_12 ) ;
if ( V_66 )
goto V_129;
V_12 -> V_19 = F_60 ( V_121 -> V_130 , F_61 ( V_121 ) ) ;
if ( V_12 -> V_19 == NULL ) {
V_66 = - V_87 ;
goto V_131;
}
if ( V_12 -> type == V_95 )
F_49 ( V_2 ) ;
V_14 -> V_132 =
( F_62 ( 4 , 16 ) | F_63 ( 32 ) ) &
F_62 ( 1 , V_12 -> V_118 ) ;
if ( V_12 -> V_21 & V_133 )
V_12 -> V_48 = F_11 ;
if ( V_12 -> V_48 )
V_12 -> V_48 ( & V_12 -> V_35 ,
& V_12 -> V_36 , 8 , 1 ) ;
V_66 = F_64 ( V_12 -> V_105 , F_41 ,
0 , L_5 , V_12 ) ;
if ( V_66 != 0 )
goto V_134;
V_19 = V_12 -> V_19 ;
F_7 ( & V_19 -> V_20 , 0 ) ;
F_7 ( & V_19 -> V_62 , 0 ) ;
F_7 ( & V_19 -> V_135 , 0 ) ;
F_7 ( & V_19 -> V_104 , 0xffffffff ) ;
V_122 = V_27 -> V_136 | V_137 | V_23 ;
if ( V_12 -> V_118 < 8 ) {
V_122 &= ~ F_16 ( 0xF ) ;
V_122 |= F_16 ( V_12 -> V_118 - 1 ) ;
}
if ( V_12 -> V_21 & V_133 )
V_122 |= V_138 ;
F_7 ( & V_19 -> V_20 , V_122 ) ;
V_66 = F_65 ( V_14 ) ;
if ( V_66 < 0 )
goto V_139;
F_66 ( V_2 , L_6 , V_19 ,
V_12 -> V_105 , F_67 ( V_12 -> V_21 ) ) ;
return V_14 ;
V_139:
V_134 ( V_12 -> V_105 , V_12 ) ;
V_134:
F_45 ( V_12 -> V_19 ) ;
V_131:
F_46 ( V_12 ) ;
V_129:
V_124:
F_68 ( V_14 ) ;
V_123:
return F_69 ( V_66 ) ;
}
static void F_70 ( struct V_10 * V_11 , bool V_110 )
{
struct V_1 * V_2 = V_11 -> V_2 . V_30 -> V_30 ;
struct V_26 * V_27 = F_50 ( V_2 ) ;
struct V_140 * V_141 = F_71 ( V_27 ) ;
T_7 V_16 = V_11 -> V_112 ;
int V_142 = V_141 -> V_143 [ V_16 ] ;
bool V_144 = V_141 -> V_145 [ V_16 ] ;
F_48 ( V_142 , V_110 ^ V_144 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_146 * V_147 = V_2 -> V_5 ;
struct V_26 * V_27 = F_50 ( V_2 ) ;
struct V_140 * V_141 = F_71 ( V_27 ) ;
int V_148 ;
int V_149 = 0 ;
int V_66 ;
V_148 = F_73 ( V_147 ) ;
if ( V_148 <= 0 ) {
V_27 -> V_150 = 1 ;
return 0 ;
}
V_141 -> V_143 = F_74 ( V_148 * sizeof( * V_141 -> V_143 ) , V_86 ) ;
if ( ! V_141 -> V_143 )
return - V_87 ;
memset ( V_141 -> V_143 , - 1 , V_148 * sizeof( * V_141 -> V_143 ) ) ;
V_141 -> V_145 = F_33 ( V_148 * sizeof( * V_141 -> V_145 ) ,
V_86 ) ;
if ( ! V_141 -> V_145 ) {
V_66 = - V_87 ;
goto V_151;
}
for (; V_149 < V_148 ; V_149 ++ ) {
int V_142 ;
enum V_152 V_21 ;
V_142 = F_75 ( V_147 , V_149 , & V_21 ) ;
if ( ! F_34 ( V_142 ) ) {
F_29 ( V_2 , L_7 , V_149 , V_142 ) ;
V_66 = V_142 ;
goto V_153;
}
V_66 = F_35 ( V_142 , F_19 ( V_2 ) ) ;
if ( V_66 ) {
F_29 ( V_2 , L_8 , V_149 , V_66 ) ;
goto V_153;
}
V_141 -> V_143 [ V_149 ] = V_142 ;
V_141 -> V_145 [ V_149 ] = V_21 & V_154 ;
V_66 = F_36 ( V_141 -> V_143 [ V_149 ] ,
V_141 -> V_145 [ V_149 ] ) ;
if ( V_66 ) {
F_29 ( V_2 , L_9
L_10 , V_149 , V_66 ) ;
goto V_153;
}
}
V_27 -> V_150 = V_148 ;
V_27 -> V_33 = F_70 ;
return 0 ;
V_153:
while ( V_149 >= 0 ) {
if ( F_34 ( V_141 -> V_143 [ V_149 ] ) )
F_37 ( V_141 -> V_143 [ V_149 ] ) ;
V_149 -- ;
}
F_76 ( V_141 -> V_145 ) ;
V_141 -> V_145 = NULL ;
V_151:
F_76 ( V_141 -> V_143 ) ;
V_141 -> V_143 = NULL ;
return V_66 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_50 ( V_2 ) ;
struct V_140 * V_141 = F_71 ( V_27 ) ;
int V_149 ;
if ( ! V_141 -> V_143 )
return 0 ;
for ( V_149 = 0 ; V_149 < V_27 -> V_150 ; V_149 ++ ) {
if ( F_34 ( V_141 -> V_143 [ V_149 ] ) )
F_37 ( V_141 -> V_143 [ V_149 ] ) ;
}
F_76 ( V_141 -> V_143 ) ;
F_76 ( V_141 -> V_145 ) ;
return 0 ;
}
static int F_78 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = & V_156 -> V_2 ;
struct V_146 * V_147 = V_156 -> V_2 . V_5 ;
struct V_114 * V_14 ;
struct V_120 V_121 ;
int V_105 , type ;
int V_66 = - V_87 ;
V_66 = F_79 ( V_156 ) ;
if ( V_66 )
return V_66 ;
type = F_1 ( & V_156 -> V_2 ) ;
if ( type == V_9 ) {
V_66 = F_72 ( V_2 ) ;
if ( V_66 )
goto V_123;
}
V_66 = F_80 ( V_147 , 0 , & V_121 ) ;
if ( V_66 )
goto V_123;
V_105 = F_81 ( V_147 , 0 ) ;
if ( ! V_105 ) {
V_66 = - V_47 ;
goto V_123;
}
V_14 = F_55 ( V_2 , & V_121 , V_105 ) ;
if ( F_82 ( V_14 ) ) {
V_66 = F_83 ( V_14 ) ;
goto V_123;
}
return 0 ;
V_123:
if ( type == V_9 )
F_77 ( V_2 ) ;
return V_66 ;
}
static int F_84 ( struct V_155 * V_156 )
{
struct V_114 * V_14 = F_85 ( V_156 ) ;
struct V_12 * V_12 = F_4 ( V_14 ) ;
int V_66 ;
V_66 = F_86 ( & V_156 -> V_2 ) ;
if ( V_66 )
return V_66 ;
if ( V_12 -> type == V_9 )
F_77 ( & V_156 -> V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_155 * V_157 )
{
struct V_120 * V_121 ;
int V_105 ;
struct V_114 * V_14 ;
if ( ! F_50 ( & V_157 -> V_2 ) )
return - V_47 ;
V_121 = F_88 ( V_157 , V_158 , 0 ) ;
if ( ! V_121 )
return - V_47 ;
V_105 = F_89 ( V_157 , 0 ) ;
if ( V_105 <= 0 )
return - V_47 ;
V_14 = F_55 ( & V_157 -> V_2 , V_121 , V_105 ) ;
return F_90 ( V_14 ) ;
}
static int F_91 ( struct V_155 * V_157 )
{
return F_86 ( & V_157 -> V_2 ) ;
}
static void T_8 F_92 ( void )
{
V_159 = F_93 ( & V_160 ) ;
}
static void T_9 F_94 ( void )
{
if ( V_159 )
return;
F_95 ( & V_160 ) ;
}
static void T_8 F_92 ( void ) {}
static void T_9 F_94 ( void ) {}
static int T_8 F_96 ( void )
{
F_92 () ;
return F_93 ( & V_161 ) ;
}
static void T_9 F_97 ( void )
{
F_95 ( & V_161 ) ;
F_94 () ;
}
