static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 |= ( V_8 | V_9 ) ;
F_3 ( V_2 , V_6 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 |= ( V_10 | V_11 ) << 16 ;
F_3 ( V_2 , V_6 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_1 ( V_2 , V_12 ) ;
V_5 &= ~ V_13 ;
V_5 |= F_8 ( 24000 ) ;
F_3 ( V_2 , V_5 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 , int V_16 )
{
if ( V_15 -> V_17 == V_2 -> V_18 && V_16 > 0 )
return 0 ;
if ( V_15 -> V_19 == V_2 -> V_18 && V_16 > 0 )
return 0 ;
return 1 ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
T_1 V_5 ;
T_2 V_20 ;
if ( V_2 -> V_21 )
return F_11 ( V_22 - 1 , 0 ) ;
V_5 = F_1 ( V_2 , V_23 ) ;
V_20 = V_5 & V_24 ;
if ( V_5 & V_25 )
V_20 = F_12 ( V_20 ) >> 4 ;
return V_20 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_26 , int V_27 , T_1 * V_5 )
{
void T_3 * V_28 ;
V_28 = V_2 -> V_4 + V_29 + V_26 ;
if ( ! F_14 ( ( V_30 ) V_28 , V_27 ) ) {
* V_5 = 0 ;
return V_31 ;
}
if ( V_27 == 4 ) {
* V_5 = F_2 ( V_28 ) ;
} else if ( V_27 == 2 ) {
* V_5 = F_15 ( V_28 ) ;
} else if ( V_27 == 1 ) {
* V_5 = F_16 ( V_28 ) ;
} else {
* V_5 = 0 ;
return V_31 ;
}
return V_32 ;
}
static int F_17 ( struct V_1 * V_2 ,
int V_26 , int V_27 , T_1 V_5 )
{
T_1 V_33 , V_34 , V_35 ;
void T_3 * V_28 ;
V_35 = V_26 & ~ 0x3 ;
V_28 = V_2 -> V_4 + V_29 + V_35 ;
if ( V_27 == 4 ) {
F_4 ( V_5 , V_28 ) ;
return V_32 ;
}
V_33 = ~ ( ( ( 1 << ( V_27 * 8 ) ) - 1 ) << ( ( V_26 & 0x3 ) * 8 ) ) ;
V_34 = F_2 ( V_28 ) & V_33 ;
V_34 |= V_5 << ( ( V_26 & 0x3 ) * 8 ) ;
F_4 ( V_34 , V_28 ) ;
return V_32 ;
}
static void F_18 (
struct V_1 * V_2 , T_1 type )
{
T_1 V_36 ;
F_3 ( V_2 , 0x0 , V_37 ) ;
F_3 ( V_2 ,
( V_38 + V_39 ) ,
V_40 ) ;
F_3 ( V_2 , V_41 ,
V_42 ) ;
V_36 = F_1 ( V_2 , V_43 ) ;
V_36 &= ~ ( V_44 ) ;
V_36 |= ( type | ( 0x1 << 23 ) ) ;
F_3 ( V_2 , V_36 , V_43 ) ;
F_3 ( V_2 , 0x0 , V_45 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_14 * V_15 , T_1 V_46 ,
int V_26 , int V_27 , T_1 * V_5 )
{
T_1 V_47 ;
V_47 = F_20 ( V_15 -> V_17 , F_21 ( V_46 ) ,
F_22 ( V_46 ) , V_26 ) ;
if ( ! F_14 ( V_47 , V_27 ) ) {
* V_5 = 0 ;
return V_31 ;
}
if ( V_15 -> V_48 -> V_17 == V_2 -> V_18 )
F_18 ( V_2 ,
V_49 ) ;
else
F_18 ( V_2 ,
V_50 ) ;
if ( V_27 == 4 ) {
* V_5 = F_2 ( V_2 -> V_51 + V_47 ) ;
} else if ( V_27 == 2 ) {
* V_5 = F_15 ( V_2 -> V_51 + V_47 ) ;
} else if ( V_27 == 1 ) {
* V_5 = F_16 ( V_2 -> V_51 + V_47 ) ;
} else {
* V_5 = 0 ;
return V_31 ;
}
return V_32 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_14 * V_15 , T_1 V_46 ,
int V_26 , int V_27 , T_1 V_5 )
{
T_1 V_47 ;
V_47 = F_20 ( V_15 -> V_17 , F_21 ( V_46 ) ,
F_22 ( V_46 ) , V_26 ) ;
if ( ! F_14 ( V_47 , V_27 ) )
return V_31 ;
if ( V_15 -> V_48 -> V_17 == V_2 -> V_18 )
F_18 ( V_2 ,
V_49 ) ;
else
F_18 ( V_2 ,
V_50 ) ;
if ( V_27 == 4 )
F_4 ( V_5 , V_2 -> V_51 + V_47 ) ;
else if ( V_27 == 2 )
F_24 ( V_5 , V_2 -> V_51 + V_47 ) ;
else if ( V_27 == 1 )
F_25 ( V_5 , V_2 -> V_51 + V_47 ) ;
else
return V_31 ;
return V_32 ;
}
static int F_26 ( struct V_14 * V_15 , T_1 V_46 , int V_26 ,
int V_27 , T_1 * V_5 )
{
struct V_1 * V_2 = V_15 -> V_52 ;
if ( ! F_9 ( V_2 , V_15 , F_21 ( V_46 ) ) ) {
* V_5 = 0xffffffff ;
return V_53 ;
}
if ( V_15 -> V_17 == V_2 -> V_18 )
return F_13 ( V_2 , V_26 , V_27 , V_5 ) ;
return F_19 ( V_2 , V_15 , V_46 , V_26 , V_27 , V_5 ) ;
}
static int F_27 ( struct V_14 * V_15 , T_1 V_46 ,
int V_26 , int V_27 , T_1 V_5 )
{
struct V_1 * V_2 = V_15 -> V_52 ;
if ( ! F_9 ( V_2 , V_15 , F_21 ( V_46 ) ) )
return V_53 ;
if ( V_15 -> V_17 == V_2 -> V_18 )
return F_17 ( V_2 , V_26 , V_27 , V_5 ) ;
return F_23 ( V_2 , V_15 , V_46 , V_26 , V_27 , V_5 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_54 ;
T_1 V_6 , V_55 , V_56 ;
if ( F_29 ( V_2 -> V_57 ) )
return;
V_54 = F_30 ( V_2 -> V_57 ) ;
if ( V_54 <= 0 )
return;
V_55 = 3 ;
V_54 = V_54 / 1000 ;
V_56 = ( V_54 * 3300 ) / 1000 ;
while ( V_56 > V_58 ) {
if ( ! V_55 ) {
F_31 ( V_2 -> V_16 , L_1 ) ;
return;
}
V_55 -- ;
V_56 = V_56 / 10 ;
}
V_6 = F_1 ( V_2 , V_59 ) ;
V_6 |= ( V_56 << V_60 ) |
( V_55 << V_61 ) ;
F_3 ( V_2 , V_6 , V_59 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_62 * V_16 = V_2 -> V_16 ;
int V_63 , V_64 ;
T_1 V_6 ;
F_33 ( V_2 -> V_65 , 0 ) ;
V_63 = F_34 ( V_2 -> V_66 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_2 , V_63 ) ;
return V_63 ;
}
V_63 = F_34 ( V_2 -> V_67 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_3 , V_63 ) ;
return V_63 ;
}
V_63 = F_34 ( V_2 -> V_68 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_4 , V_63 ) ;
return V_63 ;
}
for ( V_64 = 0 ; V_64 < V_22 ; V_64 ++ ) {
V_63 = F_36 ( V_2 -> V_69 [ V_64 ] ) ;
if ( V_63 ) {
F_35 ( V_16 , L_5 , V_64 , V_63 ) ;
goto V_70;
}
}
V_63 = F_34 ( V_2 -> V_71 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_6 , V_63 ) ;
goto V_70;
}
V_63 = F_34 ( V_2 -> V_72 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_7 , V_63 ) ;
goto V_70;
}
V_63 = F_34 ( V_2 -> V_73 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_8 , V_63 ) ;
goto V_70;
}
V_63 = F_34 ( V_2 -> V_74 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_9 , V_63 ) ;
goto V_70;
}
F_37 ( 10 ) ;
V_63 = F_38 ( V_2 -> V_68 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_10 , V_63 ) ;
goto V_70;
}
V_63 = F_38 ( V_2 -> V_66 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_11 , V_63 ) ;
goto V_70;
}
V_63 = F_38 ( V_2 -> V_67 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_12 , V_63 ) ;
goto V_70;
}
if ( V_2 -> V_75 == 2 )
F_3 ( V_2 , V_76 ,
V_77 ) ;
else
F_3 ( V_2 , V_78 ,
V_77 ) ;
F_3 ( V_2 ,
V_79 |
V_80 |
V_81 |
F_39 ( V_2 -> V_82 ) |
V_83 ,
V_77 ) ;
for ( V_64 = 0 ; V_64 < V_22 ; V_64 ++ ) {
V_63 = F_40 ( V_2 -> V_69 [ V_64 ] ) ;
if ( V_63 ) {
F_35 ( V_16 , L_13 , V_64 , V_63 ) ;
goto V_84;
}
}
V_63 = F_38 ( V_2 -> V_73 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_14 , V_63 ) ;
goto V_84;
}
V_63 = F_38 ( V_2 -> V_71 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_15 , V_63 ) ;
goto V_84;
}
V_63 = F_38 ( V_2 -> V_72 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_16 , V_63 ) ;
goto V_84;
}
V_63 = F_38 ( V_2 -> V_74 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_17 , V_63 ) ;
goto V_84;
}
V_6 = F_1 ( V_2 , V_85 ) ;
V_6 = ( V_6 & ~ V_86 ) |
( V_87 << V_88 ) ;
F_3 ( V_2 , V_6 , V_85 ) ;
F_28 ( V_2 ) ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 |= V_89 << 16 ;
F_3 ( V_2 , V_6 , V_7 ) ;
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 |= V_90 ;
F_3 ( V_2 , V_6 , V_7 ) ;
F_3 ( V_2 , V_80 ,
V_77 ) ;
F_33 ( V_2 -> V_65 , 1 ) ;
V_63 = F_41 ( V_2 -> V_4 + V_91 ,
V_6 , F_42 ( V_6 ) , 20 ,
500 * V_92 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_18 ) ;
goto V_84;
}
if ( V_2 -> V_75 == 2 ) {
V_6 = F_1 ( V_2 , V_7 ) ;
V_6 |= V_93 ;
F_3 ( V_2 , V_6 , V_7 ) ;
V_63 = F_41 ( V_2 -> V_4 + V_94 ,
V_6 , F_43 ( V_6 ) , 20 ,
500 * V_92 ) ;
if ( V_63 )
F_44 ( V_16 , L_19 ) ;
}
V_6 = F_1 ( V_2 , V_94 ) ;
V_6 = 0x1 << ( ( V_6 & V_95 ) >>
V_96 ) ;
F_44 ( V_16 , L_20 , V_6 ) ;
V_2 -> V_97 = F_10 ( V_2 ) ;
for ( V_64 = 0 ; V_64 < V_22 ; V_64 ++ ) {
if ( ! ( V_2 -> V_97 & F_45 ( V_64 ) ) ) {
F_44 ( V_16 , L_21 , V_64 ) ;
F_46 ( V_2 -> V_69 [ V_64 ] ) ;
}
}
F_3 ( V_2 , V_98 ,
V_99 ) ;
F_3 ( V_2 ,
V_100 << V_101 ,
V_102 ) ;
V_6 = F_1 ( V_2 , V_103 ) ;
V_6 &= ~ V_104 ;
F_3 ( V_2 , V_6 , V_103 ) ;
if ( F_47 ( V_16 -> V_105 , L_22 ) ) {
V_6 = F_1 ( V_2 , V_106 ) ;
V_6 &= ~ V_107 ;
F_3 ( V_2 , V_6 , V_106 ) ;
}
V_6 = F_1 ( V_2 , V_108 ) ;
V_6 &= ~ V_109 ;
V_6 |= V_110 ;
F_3 ( V_2 , V_6 , V_108 ) ;
return 0 ;
V_84:
while ( V_64 -- )
F_46 ( V_2 -> V_69 [ V_64 ] ) ;
V_64 = V_22 ;
V_70:
while ( V_64 -- )
F_48 ( V_2 -> V_69 [ V_64 ] ) ;
return V_63 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_22 ; V_64 ++ ) {
if ( V_2 -> V_97 & F_45 ( V_64 ) )
F_46 ( V_2 -> V_69 [ V_64 ] ) ;
F_48 ( V_2 -> V_69 [ V_64 ] ) ;
}
}
static T_4 F_50 ( int V_111 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
struct V_62 * V_16 = V_2 -> V_16 ;
T_1 V_3 ;
T_1 V_113 ;
V_3 = F_1 ( V_2 , V_114 ) ;
if ( V_3 & V_115 ) {
F_44 ( V_16 , L_23 ) ;
V_113 = F_1 ( V_2 , V_116 ) ;
if ( V_113 & V_117 )
F_44 ( V_16 , L_24 ) ;
if ( V_113 & V_118 )
F_44 ( V_16 , L_25 ) ;
if ( V_113 & V_119 )
F_44 ( V_16 , L_26 ) ;
if ( V_113 & V_120 )
F_44 ( V_16 , L_27 ) ;
if ( V_113 & V_121 )
F_44 ( V_16 , L_28 ) ;
if ( V_113 & V_122 )
F_44 ( V_16 , L_29 ) ;
if ( V_113 & V_123 )
F_44 ( V_16 , L_30 ) ;
if ( V_113 & V_124 )
F_44 ( V_16 , L_31 ) ;
if ( V_113 & V_125 )
F_44 ( V_16 , L_32 ) ;
if ( V_113 & V_126 )
F_44 ( V_16 , L_32 ) ;
if ( V_113 & V_127 )
F_44 ( V_16 , L_33 ) ;
if ( V_113 & V_128 )
F_44 ( V_16 , L_34 ) ;
if ( V_113 & V_129 )
F_44 ( V_16 , L_35 ) ;
if ( V_113 & V_130 )
F_44 ( V_16 , L_36 ) ;
F_3 ( V_2 , V_113 , V_116 ) ;
} else if ( V_3 & V_131 ) {
F_44 ( V_16 , L_37 ) ;
F_7 ( V_2 ) ;
F_6 ( V_2 ) ;
}
F_3 ( V_2 , V_3 & V_115 ,
V_114 ) ;
return V_132 ;
}
static T_4 F_51 ( int V_111 , void * V_112 )
{
struct V_1 * V_2 = V_112 ;
struct V_62 * V_16 = V_2 -> V_16 ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_114 ) ;
if ( V_3 & V_133 )
F_44 ( V_16 , L_38 ) ;
if ( V_3 & V_134 )
F_44 ( V_16 , L_39 ) ;
if ( V_3 & V_135 )
F_44 ( V_16 , L_40 ) ;
if ( V_3 & V_136 )
F_44 ( V_16 , L_41 ) ;
if ( V_3 & V_137 )
F_44 ( V_16 , L_42 ) ;
if ( V_3 & V_138 )
F_44 ( V_16 , L_43 ) ;
if ( V_3 & V_139 )
F_44 ( V_16 , L_44 ) ;
if ( V_3 & V_131 )
F_44 ( V_16 , L_45 ) ;
F_3 ( V_2 , V_3 & ( V_133 |
V_134 | V_135 |
V_136 | V_137 |
V_138 |
V_139 |
V_131 ) ,
V_114 ) ;
return V_132 ;
}
static void F_52 ( struct V_140 * V_141 )
{
struct V_142 * V_143 = F_53 ( V_141 ) ;
struct V_1 * V_2 = F_54 ( V_141 ) ;
struct V_62 * V_16 = V_2 -> V_16 ;
T_1 V_3 ;
T_1 V_144 ;
T_1 V_145 ;
F_55 ( V_143 , V_141 ) ;
V_3 = F_1 ( V_2 , V_114 ) ;
V_3 = ( V_3 & V_146 ) >> V_147 ;
while ( V_3 ) {
V_144 = F_56 ( V_3 ) - 1 ;
V_3 &= ~ F_45 ( V_144 ) ;
V_145 = F_57 ( V_2 -> V_148 , V_144 ) ;
if ( V_145 )
F_58 ( V_145 ) ;
else
F_35 ( V_16 , L_46 , V_144 ) ;
}
F_59 ( V_143 , V_141 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_62 * V_16 = V_2 -> V_16 ;
struct V_149 * V_149 ;
char * V_150 ;
T_1 V_64 ;
V_149 = F_61 ( V_16 , L_47 ) ;
if ( ! F_29 ( V_149 ) ) {
V_2 -> V_21 = true ;
V_2 -> V_69 [ 0 ] = V_149 ;
F_31 ( V_16 , L_48 ) ;
return 0 ;
}
if ( F_62 ( V_149 ) == - V_151 )
return F_62 ( V_149 ) ;
F_44 ( V_16 , L_49 ) ;
for ( V_64 = 0 ; V_64 < V_22 ; V_64 ++ ) {
V_150 = F_63 ( V_152 , L_50 , V_64 ) ;
if ( ! V_150 )
return - V_153 ;
V_149 = F_64 ( V_16 , V_16 -> V_105 , V_150 ) ;
F_65 ( V_150 ) ;
if ( F_29 ( V_149 ) ) {
if ( F_62 ( V_149 ) != - V_151 )
F_35 ( V_16 , L_51 ,
V_64 , F_62 ( V_149 ) ) ;
return F_62 ( V_149 ) ;
}
V_2 -> V_69 [ V_64 ] = V_149 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_111 , V_63 ;
struct V_62 * V_16 = V_2 -> V_16 ;
struct V_154 * V_155 = F_67 ( V_16 ) ;
V_111 = F_68 ( V_155 , L_52 ) ;
if ( V_111 < 0 ) {
F_35 ( V_16 , L_53 ) ;
return V_111 ;
}
V_63 = F_69 ( V_16 , V_111 , F_50 ,
V_156 , L_54 , V_2 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_55 ) ;
return V_63 ;
}
V_111 = F_68 ( V_155 , L_56 ) ;
if ( V_111 < 0 ) {
F_35 ( V_16 , L_57 ) ;
return V_111 ;
}
F_70 ( V_111 ,
F_52 ,
V_2 ) ;
V_111 = F_68 ( V_155 , L_58 ) ;
if ( V_111 < 0 ) {
F_35 ( V_16 , L_59 ) ;
return V_111 ;
}
V_63 = F_69 ( V_16 , V_111 , F_51 ,
V_156 , L_60 , V_2 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_61 ) ;
return V_63 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_62 * V_16 = V_2 -> V_16 ;
struct V_154 * V_155 = F_67 ( V_16 ) ;
struct V_157 * V_158 = V_16 -> V_105 ;
struct V_159 * V_160 ;
int V_63 ;
V_160 = F_72 ( V_155 ,
V_161 ,
L_62 ) ;
V_2 -> V_51 = F_73 ( V_16 , V_160 ) ;
if ( F_29 ( V_2 -> V_51 ) )
return F_62 ( V_2 -> V_51 ) ;
V_160 = F_72 ( V_155 ,
V_161 ,
L_63 ) ;
V_2 -> V_4 = F_74 ( V_16 , V_160 ) ;
if ( F_29 ( V_2 -> V_4 ) )
return F_62 ( V_2 -> V_4 ) ;
V_63 = F_60 ( V_2 ) ;
if ( V_63 )
return V_63 ;
V_2 -> V_82 = 1 ;
V_63 = F_75 ( V_158 , L_64 , & V_2 -> V_82 ) ;
if ( ! V_63 && ( V_2 -> V_82 == 0 ||
V_2 -> V_82 == 3 ||
V_2 -> V_82 > 4 ) ) {
F_31 ( V_16 , L_65 ) ;
V_2 -> V_82 = 1 ;
}
V_2 -> V_75 = F_76 ( V_158 ) ;
if ( V_2 -> V_75 < 0 || V_2 -> V_75 > 2 )
V_2 -> V_75 = 2 ;
V_2 -> V_71 = F_77 ( V_16 , L_66 ) ;
if ( F_29 ( V_2 -> V_71 ) ) {
if ( F_62 ( V_2 -> V_71 ) != - V_151 )
F_35 ( V_16 , L_67 ) ;
return F_62 ( V_2 -> V_71 ) ;
}
V_2 -> V_72 = F_77 ( V_16 , L_68 ) ;
if ( F_29 ( V_2 -> V_72 ) ) {
if ( F_62 ( V_2 -> V_72 ) != - V_151 )
F_35 ( V_16 , L_69 ) ;
return F_62 ( V_2 -> V_72 ) ;
}
V_2 -> V_73 = F_77 ( V_16 ,
L_70 ) ;
if ( F_29 ( V_2 -> V_73 ) ) {
if ( F_62 ( V_2 -> V_73 ) != - V_151 )
F_35 ( V_16 , L_71 ) ;
return F_62 ( V_2 -> V_73 ) ;
}
V_2 -> V_74 = F_77 ( V_16 , L_72 ) ;
if ( F_29 ( V_2 -> V_74 ) ) {
if ( F_62 ( V_2 -> V_74 ) != - V_151 )
F_35 ( V_16 , L_73 ) ;
return F_62 ( V_2 -> V_74 ) ;
}
V_2 -> V_68 = F_77 ( V_16 , L_74 ) ;
if ( F_29 ( V_2 -> V_68 ) ) {
if ( F_62 ( V_2 -> V_68 ) != - V_151 )
F_35 ( V_16 , L_75 ) ;
return F_62 ( V_2 -> V_68 ) ;
}
V_2 -> V_67 = F_77 ( V_16 , L_76 ) ;
if ( F_29 ( V_2 -> V_67 ) ) {
if ( F_62 ( V_2 -> V_67 ) != - V_151 )
F_35 ( V_16 , L_77 ) ;
return F_62 ( V_2 -> V_67 ) ;
}
V_2 -> V_66 = F_77 ( V_16 , L_78 ) ;
if ( F_29 ( V_2 -> V_66 ) ) {
if ( F_62 ( V_2 -> V_66 ) != - V_151 )
F_35 ( V_16 , L_79 ) ;
return F_62 ( V_2 -> V_66 ) ;
}
V_2 -> V_65 = F_78 ( V_16 , L_80 , V_162 ) ;
if ( F_29 ( V_2 -> V_65 ) ) {
F_35 ( V_16 , L_81 ) ;
return F_62 ( V_2 -> V_65 ) ;
}
V_2 -> V_163 = F_79 ( V_16 , L_78 ) ;
if ( F_29 ( V_2 -> V_163 ) ) {
F_35 ( V_16 , L_82 ) ;
return F_62 ( V_2 -> V_163 ) ;
}
V_2 -> V_164 = F_79 ( V_16 , L_83 ) ;
if ( F_29 ( V_2 -> V_164 ) ) {
F_35 ( V_16 , L_84 ) ;
return F_62 ( V_2 -> V_164 ) ;
}
V_2 -> V_165 = F_79 ( V_16 , L_85 ) ;
if ( F_29 ( V_2 -> V_165 ) ) {
F_35 ( V_16 , L_86 ) ;
return F_62 ( V_2 -> V_165 ) ;
}
V_2 -> V_166 = F_79 ( V_16 , L_74 ) ;
if ( F_29 ( V_2 -> V_166 ) ) {
F_35 ( V_16 , L_87 ) ;
return F_62 ( V_2 -> V_166 ) ;
}
V_63 = F_66 ( V_2 ) ;
if ( V_63 )
return V_63 ;
V_2 -> V_167 = F_80 ( V_16 , L_88 ) ;
if ( F_29 ( V_2 -> V_167 ) ) {
if ( F_62 ( V_2 -> V_167 ) == - V_151 )
return - V_151 ;
F_81 ( V_16 , L_89 ) ;
}
V_2 -> V_57 = F_80 ( V_16 , L_90 ) ;
if ( F_29 ( V_2 -> V_57 ) ) {
if ( F_62 ( V_2 -> V_57 ) == - V_151 )
return - V_151 ;
F_81 ( V_16 , L_91 ) ;
}
V_2 -> V_168 = F_80 ( V_16 , L_92 ) ;
if ( F_29 ( V_2 -> V_168 ) ) {
if ( F_62 ( V_2 -> V_168 ) == - V_151 )
return - V_151 ;
F_81 ( V_16 , L_93 ) ;
}
V_2 -> V_169 = F_80 ( V_16 , L_94 ) ;
if ( F_29 ( V_2 -> V_169 ) ) {
if ( F_62 ( V_2 -> V_169 ) == - V_151 )
return - V_151 ;
F_81 ( V_16 , L_95 ) ;
}
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_62 * V_16 = V_2 -> V_16 ;
int V_63 ;
if ( ! F_29 ( V_2 -> V_167 ) ) {
V_63 = F_83 ( V_2 -> V_167 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_96 ) ;
goto V_170;
}
}
if ( ! F_29 ( V_2 -> V_57 ) ) {
V_63 = F_83 ( V_2 -> V_57 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_97 ) ;
goto V_171;
}
}
if ( ! F_29 ( V_2 -> V_168 ) ) {
V_63 = F_83 ( V_2 -> V_168 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_98 ) ;
goto V_172;
}
}
if ( ! F_29 ( V_2 -> V_169 ) ) {
V_63 = F_83 ( V_2 -> V_169 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_99 ) ;
goto V_173;
}
}
return 0 ;
V_173:
if ( ! F_29 ( V_2 -> V_168 ) )
F_84 ( V_2 -> V_168 ) ;
V_172:
if ( ! F_29 ( V_2 -> V_57 ) )
F_84 ( V_2 -> V_57 ) ;
V_171:
if ( ! F_29 ( V_2 -> V_167 ) )
F_84 ( V_2 -> V_167 ) ;
V_170:
return V_63 ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_3 ( V_2 , ( V_174 << 16 ) &
( ~ V_174 ) , V_175 ) ;
F_3 ( V_2 , ( T_1 ) ( ~ V_176 ) ,
V_177 ) ;
F_5 ( V_2 ) ;
}
static int F_86 ( struct V_148 * V_178 , unsigned int V_111 ,
T_5 V_144 )
{
F_87 ( V_111 , & V_179 , V_180 ) ;
F_88 ( V_111 , V_178 -> V_181 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_62 * V_16 = V_2 -> V_16 ;
struct V_157 * V_182 = F_90 ( V_16 -> V_105 , NULL ) ;
if ( ! V_182 ) {
F_35 ( V_16 , L_100 ) ;
return - V_183 ;
}
V_2 -> V_148 = F_91 ( V_182 , V_184 ,
& V_185 , V_2 ) ;
if ( ! V_2 -> V_148 ) {
F_35 ( V_16 , L_101 ) ;
return - V_183 ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
int V_186 , int type , T_2 V_187 ,
T_1 V_188 , T_1 V_189 )
{
T_1 V_190 ;
T_1 V_191 ;
T_1 V_36 ;
T_1 V_192 ;
if ( V_186 >= V_193 )
return - V_183 ;
if ( V_187 + 1 < 8 )
return - V_183 ;
if ( V_187 > 63 )
return - V_183 ;
if ( V_186 == 0 ) {
if ( V_194 < ( 2ULL << V_187 ) )
return - V_183 ;
}
if ( V_186 != 0 ) {
if ( V_195 < ( 2ULL << V_187 ) )
return - V_183 ;
}
V_192 = ( V_186 << V_196 ) ;
V_190 = V_187 & V_197 ;
V_190 |= V_188 & V_198 ;
V_191 = V_189 ;
V_36 = ( 1 << 23 | type ) ;
F_3 ( V_2 , V_190 ,
V_40 + V_192 ) ;
F_3 ( V_2 , V_191 ,
V_42 + V_192 ) ;
F_3 ( V_2 , V_36 ,
V_43 + V_192 ) ;
F_3 ( V_2 , 0 ,
V_45 + V_192 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
int V_186 , T_2 V_187 ,
T_1 V_188 , T_1 V_189 )
{
T_1 V_199 ;
T_1 V_200 ;
T_1 V_192 ;
if ( V_186 > V_201 )
return - V_183 ;
if ( V_187 + 1 < V_202 )
return - V_183 ;
if ( V_187 > 63 )
return - V_183 ;
V_192 = ( V_186 << V_203 ) ;
V_199 = V_187 & V_204 ;
V_199 |= ( V_188 << 8 ) & V_205 ;
V_200 = V_189 ;
F_3 ( V_2 , V_199 , V_206 + V_192 ) ;
F_3 ( V_2 , V_200 , V_207 + V_192 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_62 * V_16 = V_2 -> V_16 ;
int V_35 ;
int V_63 ;
int V_208 ;
F_18 ( V_2 ,
V_49 ) ;
for ( V_208 = 0 ; V_208 < ( V_2 -> V_209 >> 20 ) ; V_208 ++ ) {
V_63 = F_92 ( V_2 , V_208 + 1 ,
V_210 ,
20 - 1 ,
V_2 -> V_211 +
( V_208 << 20 ) ,
0 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_102 ) ;
return V_63 ;
}
}
V_63 = F_93 ( V_2 , 2 , 32 - 1 , 0x0 , 0 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_103 ) ;
return V_63 ;
}
V_35 = V_2 -> V_209 >> 20 ;
for ( V_208 = 0 ; V_208 < ( V_2 -> V_212 >> 20 ) ; V_208 ++ ) {
V_63 = F_92 ( V_2 ,
V_208 + 1 + V_35 ,
V_213 ,
20 - 1 ,
V_2 -> V_214 +
( V_208 << 20 ) ,
0 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_104 ) ;
return V_63 ;
}
}
F_92 ( V_2 , V_208 + 1 + V_35 ,
V_215 ,
20 - 1 , 0 , 0 ) ;
V_2 -> V_216 = V_2 -> V_211 +
( ( V_208 + V_35 ) << 20 ) ;
return V_63 ;
}
static int F_95 ( struct V_1 * V_2 )
{
T_1 V_217 ;
int V_63 ;
F_4 ( 0x0 , V_2 -> V_218 + V_219 ) ;
V_63 = F_41 ( V_2 -> V_4 + V_220 ,
V_217 , F_96 ( V_217 ) , 20 ,
F_97 ( 5 * V_221 ) ) ;
if ( V_63 ) {
F_35 ( V_2 -> V_16 , L_105 ) ;
return V_63 ;
}
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_62 * V_16 = V_2 -> V_16 ;
int V_63 ;
V_63 = F_99 ( V_2 -> V_163 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_106 ) ;
return V_63 ;
}
V_63 = F_99 ( V_2 -> V_164 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_107 ) ;
goto V_222;
}
V_63 = F_99 ( V_2 -> V_165 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_108 ) ;
goto V_223;
}
V_63 = F_99 ( V_2 -> V_166 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_109 ) ;
goto V_224;
}
return 0 ;
V_224:
F_100 ( V_2 -> V_165 ) ;
V_223:
F_100 ( V_2 -> V_164 ) ;
V_222:
F_100 ( V_2 -> V_163 ) ;
return V_63 ;
}
static void F_101 ( void * V_225 )
{
struct V_1 * V_2 = V_225 ;
F_100 ( V_2 -> V_166 ) ;
F_100 ( V_2 -> V_165 ) ;
F_100 ( V_2 -> V_164 ) ;
F_100 ( V_2 -> V_163 ) ;
}
static int T_6 F_102 ( struct V_62 * V_16 )
{
struct V_1 * V_2 = F_103 ( V_16 ) ;
int V_226 ;
F_3 ( V_2 , ( V_174 << 16 ) |
V_174 , V_175 ) ;
F_3 ( V_2 , ( T_1 ) V_176 , V_177 ) ;
V_226 = F_95 ( V_2 ) ;
if ( V_226 ) {
F_85 ( V_2 ) ;
return V_226 ;
}
F_49 ( V_2 ) ;
F_101 ( V_2 ) ;
if ( ! F_29 ( V_2 -> V_169 ) )
F_84 ( V_2 -> V_169 ) ;
return V_226 ;
}
static int T_6 F_104 ( struct V_62 * V_16 )
{
struct V_1 * V_2 = F_103 ( V_16 ) ;
int V_63 ;
if ( ! F_29 ( V_2 -> V_169 ) ) {
V_63 = F_83 ( V_2 -> V_169 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_99 ) ;
return V_63 ;
}
}
V_63 = F_98 ( V_2 ) ;
if ( V_63 )
goto V_227;
V_63 = F_32 ( V_2 ) ;
if ( V_63 )
goto V_228;
V_63 = F_94 ( V_2 ) ;
if ( V_63 )
goto V_229;
F_7 ( V_2 ) ;
F_85 ( V_2 ) ;
return 0 ;
V_229:
F_49 ( V_2 ) ;
V_228:
F_101 ( V_2 ) ;
V_227:
if ( ! F_29 ( V_2 -> V_169 ) )
F_84 ( V_2 -> V_169 ) ;
return V_63 ;
}
static int F_105 ( struct V_154 * V_155 )
{
struct V_1 * V_2 ;
struct V_62 * V_16 = & V_155 -> V_16 ;
struct V_14 * V_15 , * V_230 ;
struct V_231 * V_232 ;
struct V_233 * V_234 ;
T_7 V_235 ;
struct V_159 * V_236 ;
struct V_159 * V_237 ;
int V_63 ;
F_106 ( V_238 ) ;
if ( ! V_16 -> V_105 )
return - V_239 ;
V_232 = F_107 ( V_16 , sizeof( * V_2 ) ) ;
if ( ! V_232 )
return - V_153 ;
V_2 = F_108 ( V_232 ) ;
F_109 ( V_155 , V_2 ) ;
V_2 -> V_16 = V_16 ;
V_63 = F_71 ( V_2 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_98 ( V_2 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_82 ( V_2 ) ;
if ( V_63 ) {
F_35 ( V_16 , L_110 ) ;
goto V_240;
}
V_63 = F_32 ( V_2 ) ;
if ( V_63 )
goto V_241;
F_85 ( V_2 ) ;
V_63 = F_89 ( V_2 ) ;
if ( V_63 < 0 )
goto V_242;
V_63 = F_110 ( V_16 -> V_105 , 0 , 0xff ,
& V_238 , & V_235 ) ;
if ( V_63 )
goto V_243;
V_63 = F_111 ( V_16 , & V_238 ) ;
if ( V_63 )
goto V_244;
F_112 (win, &res) {
switch ( F_113 ( V_234 -> V_238 ) ) {
case V_245 :
V_237 = V_234 -> V_238 ;
V_237 -> V_150 = L_111 ;
V_2 -> V_212 = F_114 ( V_237 ) ;
V_2 -> V_214 = V_237 -> V_246 - V_234 -> V_35 ;
V_63 = F_115 ( V_237 , V_235 ) ;
if ( V_63 ) {
F_31 ( V_16 , L_112 ,
V_63 , V_237 ) ;
continue;
}
V_2 -> V_237 = V_237 ;
break;
case V_161 :
V_236 = V_234 -> V_238 ;
V_236 -> V_150 = L_113 ;
V_2 -> V_209 = F_114 ( V_236 ) ;
V_2 -> V_211 = V_236 -> V_246 - V_234 -> V_35 ;
break;
case V_247 :
V_2 -> V_18 = V_234 -> V_238 -> V_246 ;
break;
default:
continue;
}
}
V_63 = F_94 ( V_2 ) ;
if ( V_63 )
goto V_248;
V_2 -> V_218 = F_116 ( V_16 , V_2 -> V_216 , V_249 ) ;
if ( ! V_2 -> V_218 ) {
V_63 = - V_153 ;
goto V_248;
}
F_117 ( & V_238 , & V_232 -> V_250 ) ;
V_232 -> V_16 . V_48 = V_16 ;
V_232 -> V_52 = V_2 ;
V_232 -> V_251 = 0 ;
V_232 -> V_252 = & V_253 ;
V_232 -> V_254 = V_255 ;
V_232 -> V_256 = V_257 ;
V_63 = F_118 ( V_232 ) ;
if ( V_63 < 0 )
goto V_248;
V_15 = V_232 -> V_15 ;
V_2 -> V_258 = V_15 ;
F_119 ( V_15 ) ;
F_120 ( V_15 ) ;
F_121 (child, &bus->children, node)
F_122 ( V_230 ) ;
F_123 ( V_15 ) ;
return 0 ;
V_248:
F_124 ( V_2 -> V_237 ) ;
V_244:
F_125 ( & V_238 ) ;
V_243:
F_126 ( V_2 -> V_148 ) ;
V_242:
F_49 ( V_2 ) ;
V_241:
if ( ! F_29 ( V_2 -> V_167 ) )
F_84 ( V_2 -> V_167 ) ;
if ( ! F_29 ( V_2 -> V_57 ) )
F_84 ( V_2 -> V_57 ) ;
if ( ! F_29 ( V_2 -> V_168 ) )
F_84 ( V_2 -> V_168 ) ;
if ( ! F_29 ( V_2 -> V_169 ) )
F_84 ( V_2 -> V_169 ) ;
V_240:
F_101 ( V_2 ) ;
return V_63 ;
}
static int F_127 ( struct V_154 * V_155 )
{
struct V_62 * V_16 = & V_155 -> V_16 ;
struct V_1 * V_2 = F_103 ( V_16 ) ;
F_128 ( V_2 -> V_258 ) ;
F_129 ( V_2 -> V_258 ) ;
F_124 ( V_2 -> V_237 ) ;
F_126 ( V_2 -> V_148 ) ;
F_49 ( V_2 ) ;
F_101 ( V_2 ) ;
if ( ! F_29 ( V_2 -> V_167 ) )
F_84 ( V_2 -> V_167 ) ;
if ( ! F_29 ( V_2 -> V_57 ) )
F_84 ( V_2 -> V_57 ) ;
if ( ! F_29 ( V_2 -> V_168 ) )
F_84 ( V_2 -> V_168 ) ;
if ( ! F_29 ( V_2 -> V_169 ) )
F_84 ( V_2 -> V_169 ) ;
return 0 ;
}
