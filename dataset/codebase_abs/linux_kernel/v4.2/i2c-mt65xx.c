static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 )
goto V_6;
if ( V_2 -> V_7 ) {
V_3 = F_2 ( V_2 -> V_8 ) ;
if ( V_3 )
goto V_9;
}
return 0 ;
V_9:
F_3 ( V_2 -> V_5 ) ;
V_6:
F_3 ( V_2 -> V_4 ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_3 ( V_2 -> V_8 ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_10 ;
F_6 ( V_11 , V_2 -> V_12 + V_13 ) ;
if ( V_2 -> V_14 )
F_6 ( V_15 , V_2 -> V_12 + V_16 ) ;
else
F_6 ( V_17 , V_2 -> V_12 + V_16 ) ;
if ( V_2 -> V_18 -> V_19 )
F_6 ( V_20 , V_2 -> V_12 + V_21 ) ;
F_6 ( V_2 -> V_22 , V_2 -> V_12 + V_23 ) ;
F_6 ( V_2 -> V_24 , V_2 -> V_12 + V_25 ) ;
if ( V_2 -> V_7 )
F_6 ( V_26 , V_2 -> V_12 + V_27 ) ;
V_10 = V_28 |
V_29 | V_30 ;
F_6 ( V_10 , V_2 -> V_12 + V_31 ) ;
F_6 ( V_32 , V_2 -> V_12 + V_33 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_34 ,
unsigned int V_35 )
{
unsigned int V_36 ;
unsigned int V_37 ;
unsigned int V_38 ;
unsigned int V_39 ;
unsigned int V_40 ;
unsigned int V_41 = V_42 ;
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_46 ;
V_36 = V_34 / V_35 ;
V_40 = V_2 -> V_47 ;
if ( V_40 > V_48 )
V_40 = V_48 ;
if ( V_40 > V_49 )
V_39 = V_50 ;
else
V_39 = V_51 ;
V_43 = V_39 ;
V_44 = F_8 ( V_36 >> 1 , V_40 ) ;
V_45 = V_42 * V_39 ;
for ( V_38 = 1 ; V_38 <= V_42 ; V_38 ++ ) {
V_37 = F_8 ( V_44 , V_38 ) ;
V_46 = V_37 * V_38 ;
if ( V_37 > V_39 )
continue;
if ( V_46 < V_45 ) {
V_45 = V_46 ;
V_41 = V_38 ;
V_43 = V_37 ;
if ( V_45 == V_44 )
break;
}
}
V_38 = V_41 ;
V_37 = V_43 ;
if ( ( V_36 / ( 2 * V_38 * V_37 ) ) > V_40 ) {
F_9 ( V_2 -> V_52 , L_1 , V_40 ) ;
return - V_53 ;
}
V_37 -- ;
V_38 -- ;
if ( V_40 > V_49 ) {
V_2 -> V_22 = V_54 ;
V_2 -> V_24 = V_55 |
( V_38 << 12 ) | ( V_37 << 8 ) ;
} else {
V_2 -> V_22 = ( V_38 << 8 ) | ( V_37 << 0 ) ;
V_2 -> V_24 = V_56 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_57 * V_58 ,
int V_59 , int V_60 )
{
T_1 V_61 ;
T_1 V_62 ;
T_1 V_10 ;
T_1 V_63 = 0 ;
T_2 V_64 = 0 ;
T_2 V_65 = 0 ;
int V_3 ;
V_2 -> V_66 = 0 ;
if ( V_2 -> V_18 -> V_67 )
V_63 = V_68 ;
F_11 ( & V_2 -> V_69 ) ;
V_10 = F_12 ( V_2 -> V_12 + V_31 ) &
~ ( V_70 | V_71 ) ;
if ( ( V_2 -> V_47 > 400000 ) || ( V_60 >= 1 ) )
V_10 |= V_71 ;
if ( V_2 -> V_72 == V_73 )
V_10 |= V_70 | V_71 ;
F_6 ( V_10 , V_2 -> V_12 + V_31 ) ;
if ( V_2 -> V_47 <= 100000 )
F_6 ( V_74 , V_2 -> V_12 + V_75 ) ;
else
F_6 ( V_76 , V_2 -> V_12 + V_75 ) ;
V_61 = V_58 -> V_77 << 1 ;
if ( V_2 -> V_72 == V_78 )
V_61 |= 0x1 ;
F_6 ( V_61 , V_2 -> V_12 + V_79 ) ;
F_6 ( V_63 | V_80 | V_81 |
V_82 , V_2 -> V_12 + V_83 ) ;
F_6 ( V_84 , V_2 -> V_12 + V_85 ) ;
F_6 ( V_63 | V_80 | V_81 |
V_82 , V_2 -> V_12 + V_86 ) ;
if ( V_2 -> V_72 == V_73 ) {
F_6 ( V_58 -> V_87 | ( ( V_58 + 1 ) -> V_87 ) << 8 ,
V_2 -> V_12 + V_88 ) ;
F_6 ( V_89 , V_2 -> V_12 + V_90 ) ;
} else {
F_6 ( V_58 -> V_87 , V_2 -> V_12 + V_88 ) ;
F_6 ( V_59 , V_2 -> V_12 + V_90 ) ;
}
if ( V_2 -> V_72 == V_78 ) {
F_13 ( V_91 , V_2 -> V_92 + V_93 ) ;
F_13 ( V_94 , V_2 -> V_92 + V_95 ) ;
V_64 = F_14 ( V_2 -> V_52 , V_58 -> V_96 ,
V_58 -> V_87 , V_97 ) ;
if ( F_15 ( V_2 -> V_52 , V_64 ) )
return - V_98 ;
F_13 ( ( V_99 ) V_64 , V_2 -> V_92 + V_100 ) ;
F_13 ( V_58 -> V_87 , V_2 -> V_92 + V_101 ) ;
} else if ( V_2 -> V_72 == V_102 ) {
F_13 ( V_91 , V_2 -> V_92 + V_93 ) ;
F_13 ( V_103 , V_2 -> V_92 + V_95 ) ;
V_65 = F_14 ( V_2 -> V_52 , V_58 -> V_96 ,
V_58 -> V_87 , V_104 ) ;
if ( F_15 ( V_2 -> V_52 , V_65 ) )
return - V_98 ;
F_13 ( ( V_99 ) V_65 , V_2 -> V_92 + V_105 ) ;
F_13 ( V_58 -> V_87 , V_2 -> V_92 + V_106 ) ;
} else {
F_13 ( V_107 , V_2 -> V_92 + V_93 ) ;
F_13 ( V_107 , V_2 -> V_92 + V_95 ) ;
V_65 = F_14 ( V_2 -> V_52 , V_58 -> V_96 ,
V_58 -> V_87 , V_104 ) ;
if ( F_15 ( V_2 -> V_52 , V_65 ) )
return - V_98 ;
V_64 = F_14 ( V_2 -> V_52 , ( V_58 + 1 ) -> V_96 ,
( V_58 + 1 ) -> V_87 ,
V_97 ) ;
if ( F_15 ( V_2 -> V_52 , V_64 ) ) {
F_16 ( V_2 -> V_52 , V_65 ,
V_58 -> V_87 , V_104 ) ;
return - V_98 ;
}
F_13 ( ( V_99 ) V_65 , V_2 -> V_92 + V_105 ) ;
F_13 ( ( V_99 ) V_64 , V_2 -> V_92 + V_100 ) ;
F_13 ( V_58 -> V_87 , V_2 -> V_92 + V_106 ) ;
F_13 ( ( V_58 + 1 ) -> V_87 , V_2 -> V_92 + V_101 ) ;
}
F_13 ( V_108 , V_2 -> V_92 + V_109 ) ;
if ( ! V_2 -> V_18 -> V_67 ) {
V_62 = V_110 ;
} else {
V_62 = V_110 | V_111 ;
if ( V_60 >= 1 )
V_62 |= V_112 ;
}
F_6 ( V_62 , V_2 -> V_12 + V_113 ) ;
V_3 = F_17 ( & V_2 -> V_69 ,
V_2 -> V_114 . V_115 ) ;
F_6 ( ~ ( V_63 | V_80 | V_81 |
V_82 ) , V_2 -> V_12 + V_86 ) ;
if ( V_2 -> V_72 == V_102 ) {
F_16 ( V_2 -> V_52 , V_65 ,
V_58 -> V_87 , V_104 ) ;
} else if ( V_2 -> V_72 == V_78 ) {
F_16 ( V_2 -> V_52 , V_64 ,
V_58 -> V_87 , V_97 ) ;
} else {
F_16 ( V_2 -> V_52 , V_65 , V_58 -> V_87 ,
V_104 ) ;
F_16 ( V_2 -> V_52 , V_64 , ( V_58 + 1 ) -> V_87 ,
V_97 ) ;
}
if ( V_3 == 0 ) {
F_9 ( V_2 -> V_52 , L_2 , V_58 -> V_77 ) ;
F_5 ( V_2 ) ;
return - V_116 ;
}
F_18 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_66 & ( V_80 | V_81 ) ) {
F_9 ( V_2 -> V_52 , L_3 , V_58 -> V_77 ) ;
F_5 ( V_2 ) ;
return - V_117 ;
}
return 0 ;
}
static int F_19 ( struct V_118 * V_114 ,
struct V_57 V_58 [] , int V_59 )
{
int V_3 ;
int V_60 = V_59 ;
struct V_1 * V_2 = F_20 ( V_114 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
while ( V_60 -- ) {
if ( ! V_58 -> V_96 ) {
F_9 ( V_2 -> V_52 , L_4 ) ;
V_3 = - V_53 ;
goto V_119;
}
if ( V_58 -> V_120 & V_121 )
V_2 -> V_72 = V_78 ;
else
V_2 -> V_72 = V_102 ;
if ( ! V_2 -> V_18 -> V_67 ) {
if ( V_59 > 1 ) {
V_2 -> V_72 = V_73 ;
V_60 -- ;
}
}
V_3 = F_10 ( V_2 , V_58 , V_59 , V_60 ) ;
if ( V_3 < 0 )
goto V_119;
V_58 ++ ;
}
V_3 = V_59 ;
V_119:
F_4 ( V_2 ) ;
return V_3 ;
}
static T_3 F_21 ( int V_122 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
T_1 V_63 = 0 ;
if ( V_2 -> V_18 -> V_67 )
V_63 = V_68 ;
V_2 -> V_66 = F_12 ( V_2 -> V_12 + V_83 ) ;
F_6 ( V_63 | V_80 | V_81
| V_82 , V_2 -> V_12 + V_83 ) ;
F_22 ( & V_2 -> V_69 ) ;
return V_124 ;
}
static V_99 F_23 ( struct V_118 * V_114 )
{
return V_125 | V_126 ;
}
static int F_24 ( struct V_127 * V_128 , struct V_1 * V_2 ,
unsigned int * V_129 )
{
int V_3 ;
V_3 = F_25 ( V_128 , L_5 , & V_2 -> V_47 ) ;
if ( V_3 < 0 )
V_2 -> V_47 = V_130 ;
V_3 = F_25 ( V_128 , L_6 , V_129 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( * V_129 == 0 )
return - V_53 ;
V_2 -> V_7 = F_26 ( V_128 , L_7 ) ;
V_2 -> V_14 =
F_26 ( V_128 , L_8 ) ;
return 0 ;
}
static int F_27 ( struct V_131 * V_132 )
{
const struct V_133 * V_134 ;
int V_3 = 0 ;
struct V_1 * V_2 ;
struct V_135 * V_135 ;
unsigned int V_129 ;
struct V_136 * V_137 ;
int V_138 ;
V_2 = F_28 ( & V_132 -> V_52 , sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 )
return - V_98 ;
V_3 = F_24 ( V_132 -> V_52 . V_140 , V_2 , & V_129 ) ;
if ( V_3 )
return - V_53 ;
V_137 = F_29 ( V_132 , V_141 , 0 ) ;
V_2 -> V_12 = F_30 ( & V_132 -> V_52 , V_137 ) ;
if ( F_31 ( V_2 -> V_12 ) )
return F_32 ( V_2 -> V_12 ) ;
V_137 = F_29 ( V_132 , V_141 , 1 ) ;
V_2 -> V_92 = F_30 ( & V_132 -> V_52 , V_137 ) ;
if ( F_31 ( V_2 -> V_92 ) )
return F_32 ( V_2 -> V_92 ) ;
V_138 = F_33 ( V_132 , 0 ) ;
if ( V_138 <= 0 )
return V_138 ;
F_34 ( & V_2 -> V_69 ) ;
V_134 = F_35 ( V_142 , V_132 -> V_52 . V_140 ) ;
if ( ! V_134 )
return - V_53 ;
V_2 -> V_18 = V_134 -> V_143 ;
V_2 -> V_114 . V_52 . V_140 = V_132 -> V_52 . V_140 ;
V_2 -> V_52 = & V_132 -> V_52 ;
V_2 -> V_114 . V_52 . V_144 = & V_132 -> V_52 ;
V_2 -> V_114 . V_145 = V_146 ;
V_2 -> V_114 . V_147 = & V_148 ;
V_2 -> V_114 . V_149 = V_2 -> V_18 -> V_149 ;
V_2 -> V_114 . V_115 = 2 * V_150 ;
V_2 -> V_114 . V_151 = 1 ;
if ( V_2 -> V_7 && ! V_2 -> V_18 -> V_152 )
return - V_53 ;
V_2 -> V_5 = F_36 ( & V_132 -> V_52 , L_9 ) ;
if ( F_31 ( V_2 -> V_5 ) ) {
F_37 ( & V_132 -> V_52 , L_10 ) ;
return F_32 ( V_2 -> V_5 ) ;
}
V_2 -> V_4 = F_36 ( & V_132 -> V_52 , L_11 ) ;
if ( F_31 ( V_2 -> V_4 ) ) {
F_37 ( & V_132 -> V_52 , L_12 ) ;
return F_32 ( V_2 -> V_4 ) ;
}
V_135 = V_2 -> V_5 ;
if ( V_2 -> V_7 ) {
V_2 -> V_8 = F_36 ( & V_132 -> V_52 , L_13 ) ;
if ( F_31 ( V_2 -> V_8 ) ) {
F_37 ( & V_132 -> V_52 , L_14 ) ;
return F_32 ( V_2 -> V_8 ) ;
}
V_135 = V_2 -> V_8 ;
}
F_38 ( V_2 -> V_114 . V_153 , V_154 , sizeof( V_2 -> V_114 . V_153 ) ) ;
V_3 = F_7 ( V_2 , F_39 ( V_135 ) , V_129 ) ;
if ( V_3 ) {
F_37 ( & V_132 -> V_52 , L_15 ) ;
return - V_53 ;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_37 ( & V_132 -> V_52 , L_16 ) ;
return V_3 ;
}
F_5 ( V_2 ) ;
F_4 ( V_2 ) ;
V_3 = F_40 ( & V_132 -> V_52 , V_138 , F_21 ,
V_155 , V_154 , V_2 ) ;
if ( V_3 < 0 ) {
F_37 ( & V_132 -> V_52 ,
L_17 , V_138 ) ;
return V_3 ;
}
F_41 ( & V_2 -> V_114 , V_2 ) ;
V_3 = F_42 ( & V_2 -> V_114 ) ;
if ( V_3 ) {
F_37 ( & V_132 -> V_52 , L_18 ) ;
return V_3 ;
}
F_43 ( V_132 , V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_45 ( V_132 ) ;
F_46 ( & V_2 -> V_114 ) ;
return 0 ;
}
