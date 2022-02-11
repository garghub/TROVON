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
if ( ( V_39 < 4 )
|| ( ( V_39 > 16 ) && ( V_39 != 32 ) )
|| ( V_39 > V_12 -> V_55 ) )
return - V_47 ;
if ( ! V_53 )
V_53 = V_11 -> V_56 ;
if ( ! ( V_12 -> V_21 & V_24 ) )
V_39 = F_13 ( V_16 , V_11 ,
V_12 ,
V_39 ) ;
else if ( V_12 -> V_21 & V_57 )
V_39 = F_14 ( V_16 , V_11 ,
V_39 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_39 == 32 )
V_39 = 0 ;
else
V_39 = V_39 - 1 ;
V_16 -> V_22 &= ~ ( F_16 ( 0xF ) | V_58
| F_17 ( 0xF ) ) ;
V_16 -> V_22 |= F_16 ( V_39 ) ;
if ( ( V_12 -> V_59 / V_53 ) > 64 ) {
V_16 -> V_22 |= V_58 ;
V_52 = ( V_12 -> V_59 - 1 ) / ( V_53 * 64 ) + 1 ;
F_18 ( V_52 > 16 , L_1
L_2 , F_19 ( & V_11 -> V_2 ) ,
V_53 , V_12 -> V_59 / 1024 ) ;
if ( V_52 > 16 )
V_52 = 16 ;
} else {
V_52 = ( V_12 -> V_59 - 1 ) / ( V_53 * 4 ) + 1 ;
}
if ( V_52 )
V_52 -- ;
V_16 -> V_22 |= F_17 ( V_52 ) ;
F_3 ( V_11 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_50 * V_51 , unsigned int V_60 )
{
T_3 V_61 ;
struct V_18 * V_19 = V_13 -> V_19 ;
V_13 -> V_62 = V_60 ;
F_7 ( & V_19 -> V_63 , V_64 ) ;
V_61 = V_13 -> V_38 ( V_13 ) ;
F_7 ( & V_19 -> V_65 , V_61 ) ;
return 0 ;
}
static int F_21 ( struct V_10 * V_11 , struct V_50 * V_51 ,
bool V_66 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
struct V_18 * V_19 ;
unsigned int V_60 = V_51 -> V_60 ;
T_4 V_39 ;
int V_67 ;
V_19 = V_12 -> V_19 ;
V_39 = V_11 -> V_39 ;
if ( V_51 -> V_39 )
V_39 = V_51 -> V_39 ;
if ( V_39 > 8 ) {
if ( V_60 & 1 )
return - V_47 ;
V_60 /= 2 ;
}
if ( V_39 > 16 ) {
if ( V_60 & 1 )
return - V_47 ;
V_60 /= 2 ;
}
V_12 -> V_68 = V_51 -> V_69 ;
V_12 -> V_70 = V_51 -> V_71 ;
F_22 ( V_12 -> V_72 ) ;
if ( V_12 -> V_21 & V_24 )
V_67 = F_23 ( V_12 , V_51 , V_66 ) ;
else
V_67 = F_20 ( V_12 , V_51 , V_60 ) ;
if ( V_67 )
return V_67 ;
F_24 ( & V_12 -> V_72 ) ;
F_7 ( & V_19 -> V_63 , 0 ) ;
if ( V_12 -> V_21 & V_24 )
F_25 ( V_12 ) ;
return V_12 -> V_62 ;
}
static void F_26 ( struct V_73 * V_74 )
{
struct V_10 * V_11 = V_74 -> V_11 ;
struct V_50 * V_51 ;
unsigned int V_75 ;
const int V_76 = 50 ;
int V_77 ;
V_75 = 1 ;
V_77 = 0 ;
F_27 (t, &m->transfers, transfer_list) {
if ( V_51 -> V_39 || V_51 -> V_54 ) {
V_77 = - V_47 ;
if ( V_75 )
V_77 = F_15 ( V_11 , V_51 ) ;
if ( V_77 < 0 )
break;
}
if ( V_75 ) {
F_10 ( V_11 , V_34 ) ;
F_28 ( V_76 ) ;
}
V_75 = V_51 -> V_75 ;
if ( V_51 -> V_60 )
V_77 = F_21 ( V_11 , V_51 , V_74 -> V_66 ) ;
if ( V_77 ) {
V_77 = - V_78 ;
break;
}
V_74 -> V_79 += V_51 -> V_60 ;
if ( V_51 -> V_80 )
F_29 ( V_51 -> V_80 ) ;
if ( V_75 ) {
F_28 ( V_76 ) ;
F_10 ( V_11 , V_32 ) ;
F_28 ( V_76 ) ;
}
}
V_74 -> V_77 = V_77 ;
V_74 -> V_81 ( V_74 -> V_82 ) ;
if ( V_77 || ! V_75 ) {
F_28 ( V_76 ) ;
F_10 ( V_11 , V_32 ) ;
}
F_15 ( V_11 , NULL ) ;
}
static int F_30 ( struct V_10 * V_11 )
{
struct V_12 * V_12 ;
struct V_18 * V_19 ;
int V_83 ;
T_3 V_22 ;
struct V_15 * V_16 = V_11 -> V_17 ;
if ( ! V_11 -> V_56 )
return - V_47 ;
if ( ! V_16 ) {
V_16 = F_31 ( sizeof *V_16 , V_84 ) ;
if ( ! V_16 )
return - V_85 ;
V_11 -> V_17 = V_16 ;
}
V_12 = F_4 ( V_11 -> V_14 ) ;
V_19 = V_12 -> V_19 ;
V_22 = V_16 -> V_22 ;
V_16 -> V_22 = F_5 ( & V_19 -> V_20 ) ;
V_16 -> V_22 &= ~ ( V_86 | V_87
| V_88 | V_89 ) ;
if ( V_11 -> V_20 & V_90 )
V_16 -> V_22 |= V_86 ;
if ( V_11 -> V_20 & V_91 )
V_16 -> V_22 |= V_87 ;
if ( ! ( V_11 -> V_20 & V_49 ) )
V_16 -> V_22 |= V_88 ;
if ( V_11 -> V_20 & V_92 )
V_16 -> V_22 |= V_89 ;
V_83 = F_15 ( V_11 , NULL ) ;
if ( V_83 < 0 ) {
V_16 -> V_22 = V_22 ;
return V_83 ;
}
if ( V_12 -> type == V_93 ) {
if ( F_32 ( V_11 -> V_94 ) ) {
int V_95 ;
V_83 = F_33 ( V_11 -> V_94 ,
F_19 ( & V_11 -> V_2 ) ) ;
if ( V_83 )
return V_83 ;
V_95 = ! ( V_11 -> V_20 & V_29 ) ;
V_83 = F_34 ( V_11 -> V_94 , V_95 ) ;
if ( V_83 ) {
F_35 ( V_11 -> V_94 ) ;
return V_83 ;
}
} else if ( V_11 -> V_94 != - V_96 ) {
if ( V_11 -> V_94 < 0 )
return V_11 -> V_94 ;
return - V_47 ;
}
}
F_10 ( V_11 , V_32 ) ;
return 0 ;
}
static void F_36 ( struct V_10 * V_11 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
if ( V_12 -> type == V_93 && F_32 ( V_11 -> V_94 ) )
F_35 ( V_11 -> V_94 ) ;
}
static void F_37 ( struct V_12 * V_13 , T_3 V_97 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
if ( V_97 & V_98 ) {
T_3 V_99 = F_5 ( & V_19 -> V_100 ) ;
if ( V_13 -> V_70 )
V_13 -> V_37 ( V_99 , V_13 ) ;
}
if ( ( V_97 & V_101 ) == 0 )
while ( ( ( V_97 =
F_5 ( & V_19 -> V_102 ) ) &
V_101 ) == 0 )
F_38 () ;
F_7 ( & V_19 -> V_102 , V_97 ) ;
V_13 -> V_62 -= 1 ;
if ( V_13 -> V_62 ) {
T_3 V_61 = V_13 -> V_38 ( V_13 ) ;
F_7 ( & V_19 -> V_65 , V_61 ) ;
} else {
V_81 ( & V_13 -> V_72 ) ;
}
}
static T_5 F_39 ( T_6 V_103 , void * V_104 )
{
struct V_12 * V_13 = V_104 ;
T_5 V_67 = V_105 ;
T_3 V_97 ;
struct V_18 * V_19 = V_13 -> V_19 ;
V_97 = F_5 ( & V_19 -> V_102 ) ;
if ( V_97 )
V_67 = V_106 ;
F_40 ( V_13 -> V_2 , L_3 , V_107 , V_97 ) ;
if ( V_13 -> V_21 & V_24 )
F_41 ( V_13 , V_97 ) ;
else
F_37 ( V_13 , V_97 ) ;
return V_67 ;
}
static void F_42 ( struct V_12 * V_13 )
{
F_43 ( V_13 -> V_19 ) ;
F_44 ( V_13 ) ;
}
static void F_45 ( struct V_10 * V_11 , bool V_108 )
{
struct V_12 * V_12 = F_4 ( V_11 -> V_14 ) ;
struct V_18 * V_19 = V_12 -> V_19 ;
T_3 V_109 ;
T_7 V_16 = V_11 -> V_110 ;
if ( F_32 ( V_11 -> V_94 ) ) {
F_46 ( V_11 -> V_94 , V_108 ) ;
} else if ( V_16 < V_12 -> V_111 ) {
V_109 = F_5 ( & V_19 -> V_109 ) ;
V_109 = V_108 ? ( V_109 | ( 1 << V_16 ) ) : ( V_109 & ~ ( 1 << V_16 ) ) ;
F_7 ( & V_19 -> V_109 , V_109 ) ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_48 ( V_2 ) ;
struct V_112 * V_14 = F_49 ( V_2 ) ;
struct V_12 * V_12 = F_4 ( V_14 ) ;
struct V_18 * V_19 = V_12 -> V_19 ;
int V_113 ;
T_3 V_114 ;
V_114 = F_5 ( & V_19 -> V_115 ) ;
V_12 -> V_48 = F_12 ;
V_113 = F_50 ( V_114 ) ;
if ( V_113 )
V_12 -> V_55 = V_113 + 1 ;
V_12 -> V_111 = 0 ;
if ( F_51 ( V_114 ) ) {
V_12 -> V_111 = F_52 ( V_114 ) ;
F_7 ( & V_19 -> V_109 , 0xffffffff ) ;
}
V_14 -> V_116 = V_12 -> V_111 ;
V_27 -> V_33 = F_45 ;
}
static struct V_112 * F_53 ( struct V_1 * V_2 ,
struct V_117 * V_118 , unsigned int V_103 )
{
struct V_26 * V_27 = F_48 ( V_2 ) ;
struct V_112 * V_14 ;
struct V_12 * V_12 ;
struct V_18 * V_19 ;
T_3 V_119 ;
int V_67 = 0 ;
V_14 = F_54 ( V_2 , sizeof( struct V_12 ) ) ;
if ( V_14 == NULL ) {
V_67 = - V_85 ;
goto V_120;
}
F_55 ( V_2 , V_14 ) ;
V_67 = F_56 ( V_2 , V_118 , V_103 ) ;
if ( V_67 )
goto V_121;
V_14 -> V_122 = F_30 ;
V_14 -> V_123 = F_36 ;
V_12 = F_4 ( V_14 ) ;
V_12 -> V_124 = F_26 ;
V_12 -> V_125 = F_42 ;
V_12 -> V_55 = 32 ;
V_12 -> type = F_1 ( V_2 ) ;
V_67 = F_57 ( V_12 ) ;
if ( V_67 )
goto V_126;
V_12 -> V_19 = F_58 ( V_118 -> V_127 , F_59 ( V_118 ) ) ;
if ( V_12 -> V_19 == NULL ) {
V_67 = - V_85 ;
goto V_128;
}
if ( V_12 -> type == V_93 )
F_47 ( V_2 ) ;
if ( V_12 -> V_21 & V_129 )
V_12 -> V_48 = F_11 ;
if ( V_12 -> V_48 )
V_12 -> V_48 ( & V_12 -> V_35 ,
& V_12 -> V_36 , 8 , 1 ) ;
V_67 = F_60 ( V_12 -> V_103 , F_39 ,
0 , L_4 , V_12 ) ;
if ( V_67 != 0 )
goto V_130;
V_19 = V_12 -> V_19 ;
F_7 ( & V_19 -> V_20 , 0 ) ;
F_7 ( & V_19 -> V_63 , 0 ) ;
F_7 ( & V_19 -> V_131 , 0 ) ;
F_7 ( & V_19 -> V_102 , 0xffffffff ) ;
V_119 = V_27 -> V_132 | V_133 | V_23 ;
if ( V_12 -> V_55 < 8 ) {
V_119 &= ~ F_16 ( 0xF ) ;
V_119 |= F_16 ( V_12 -> V_55 - 1 ) ;
}
if ( V_12 -> V_21 & V_129 )
V_119 |= V_134 ;
F_7 ( & V_19 -> V_20 , V_119 ) ;
V_67 = F_61 ( V_14 ) ;
if ( V_67 < 0 )
goto V_135;
F_62 ( V_2 , L_5 , V_19 ,
V_12 -> V_103 , F_63 ( V_12 -> V_21 ) ) ;
return V_14 ;
V_135:
V_130 ( V_12 -> V_103 , V_12 ) ;
V_130:
F_43 ( V_12 -> V_19 ) ;
V_128:
F_44 ( V_12 ) ;
V_126:
V_121:
F_64 ( V_14 ) ;
V_120:
return F_65 ( V_67 ) ;
}
static void F_66 ( struct V_10 * V_11 , bool V_108 )
{
struct V_1 * V_2 = V_11 -> V_2 . V_30 -> V_30 ;
struct V_26 * V_27 = F_48 ( V_2 ) ;
struct V_136 * V_137 = F_67 ( V_27 ) ;
T_7 V_16 = V_11 -> V_110 ;
int V_138 = V_137 -> V_139 [ V_16 ] ;
bool V_140 = V_137 -> V_141 [ V_16 ] ;
F_46 ( V_138 , V_108 ^ V_140 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_142 * V_143 = V_2 -> V_5 ;
struct V_26 * V_27 = F_48 ( V_2 ) ;
struct V_136 * V_137 = F_67 ( V_27 ) ;
int V_144 ;
int V_145 = 0 ;
int V_67 ;
V_144 = F_69 ( V_143 ) ;
if ( V_144 <= 0 ) {
V_27 -> V_146 = 1 ;
return 0 ;
}
V_137 -> V_139 = F_70 ( V_144 * sizeof( * V_137 -> V_139 ) , V_84 ) ;
if ( ! V_137 -> V_139 )
return - V_85 ;
memset ( V_137 -> V_139 , - 1 , V_144 * sizeof( * V_137 -> V_139 ) ) ;
V_137 -> V_141 = F_31 ( V_144 * sizeof( * V_137 -> V_141 ) ,
V_84 ) ;
if ( ! V_137 -> V_141 ) {
V_67 = - V_85 ;
goto V_147;
}
for (; V_145 < V_144 ; V_145 ++ ) {
int V_138 ;
enum V_148 V_21 ;
V_138 = F_71 ( V_143 , V_145 , & V_21 ) ;
if ( ! F_32 ( V_138 ) ) {
F_72 ( V_2 , L_6 , V_145 , V_138 ) ;
V_67 = V_138 ;
goto V_149;
}
V_67 = F_33 ( V_138 , F_19 ( V_2 ) ) ;
if ( V_67 ) {
F_72 ( V_2 , L_7 , V_145 , V_67 ) ;
goto V_149;
}
V_137 -> V_139 [ V_145 ] = V_138 ;
V_137 -> V_141 [ V_145 ] = V_21 & V_150 ;
V_67 = F_34 ( V_137 -> V_139 [ V_145 ] ,
V_137 -> V_141 [ V_145 ] ) ;
if ( V_67 ) {
F_72 ( V_2 , L_8
L_9 , V_145 , V_67 ) ;
goto V_149;
}
}
V_27 -> V_146 = V_144 ;
V_27 -> V_33 = F_66 ;
return 0 ;
V_149:
while ( V_145 >= 0 ) {
if ( F_32 ( V_137 -> V_139 [ V_145 ] ) )
F_35 ( V_137 -> V_139 [ V_145 ] ) ;
V_145 -- ;
}
F_73 ( V_137 -> V_141 ) ;
V_137 -> V_141 = NULL ;
V_147:
F_73 ( V_137 -> V_139 ) ;
V_137 -> V_139 = NULL ;
return V_67 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_48 ( V_2 ) ;
struct V_136 * V_137 = F_67 ( V_27 ) ;
int V_145 ;
if ( ! V_137 -> V_139 )
return 0 ;
for ( V_145 = 0 ; V_145 < V_27 -> V_146 ; V_145 ++ ) {
if ( F_32 ( V_137 -> V_139 [ V_145 ] ) )
F_35 ( V_137 -> V_139 [ V_145 ] ) ;
}
F_73 ( V_137 -> V_139 ) ;
F_73 ( V_137 -> V_141 ) ;
return 0 ;
}
static int F_75 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = & V_152 -> V_2 ;
struct V_142 * V_143 = V_152 -> V_2 . V_5 ;
struct V_112 * V_14 ;
struct V_117 V_118 ;
int V_103 , type ;
int V_67 = - V_85 ;
V_67 = F_76 ( V_152 ) ;
if ( V_67 )
return V_67 ;
type = F_1 ( & V_152 -> V_2 ) ;
if ( type == V_9 ) {
V_67 = F_68 ( V_2 ) ;
if ( V_67 )
goto V_120;
}
V_67 = F_77 ( V_143 , 0 , & V_118 ) ;
if ( V_67 )
goto V_120;
V_103 = F_78 ( V_143 , 0 ) ;
if ( ! V_103 ) {
V_67 = - V_47 ;
goto V_120;
}
V_14 = F_53 ( V_2 , & V_118 , V_103 ) ;
if ( F_79 ( V_14 ) ) {
V_67 = F_80 ( V_14 ) ;
goto V_120;
}
return 0 ;
V_120:
if ( type == V_9 )
F_74 ( V_2 ) ;
return V_67 ;
}
static int F_81 ( struct V_151 * V_152 )
{
struct V_112 * V_14 = F_82 ( V_152 ) ;
struct V_12 * V_12 = F_4 ( V_14 ) ;
int V_67 ;
V_67 = F_83 ( & V_152 -> V_2 ) ;
if ( V_67 )
return V_67 ;
if ( V_12 -> type == V_9 )
F_74 ( & V_152 -> V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_151 * V_153 )
{
struct V_117 * V_118 ;
int V_103 ;
struct V_112 * V_14 ;
if ( ! F_48 ( & V_153 -> V_2 ) )
return - V_47 ;
V_118 = F_85 ( V_153 , V_154 , 0 ) ;
if ( ! V_118 )
return - V_47 ;
V_103 = F_86 ( V_153 , 0 ) ;
if ( V_103 <= 0 )
return - V_47 ;
V_14 = F_53 ( & V_153 -> V_2 , V_118 , V_103 ) ;
return F_87 ( V_14 ) ;
}
static int F_88 ( struct V_151 * V_153 )
{
return F_83 ( & V_153 -> V_2 ) ;
}
static void T_8 F_89 ( void )
{
V_155 = F_90 ( & V_156 ) ;
}
static void T_9 F_91 ( void )
{
if ( V_155 )
return;
F_92 ( & V_156 ) ;
}
static void T_8 F_89 ( void ) {}
static void T_9 F_91 ( void ) {}
static int T_8 F_93 ( void )
{
F_89 () ;
return F_90 ( & V_157 ) ;
}
static void T_9 F_94 ( void )
{
F_92 ( & V_157 ) ;
F_91 () ;
}
