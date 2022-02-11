T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
if ( V_2 -> V_5 & V_6 )
V_4 = F_2 ( V_2 -> V_7 + V_3 ) |
( F_2 ( V_2 -> V_7 + V_3 + 2 ) << 16 ) ;
else
V_4 = F_3 ( V_2 -> V_7 + V_3 ) ;
if ( V_2 -> V_5 & V_8 )
return F_4 ( V_4 ) ;
else
return V_4 ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_9 , int V_3 )
{
if ( V_2 -> V_5 & V_8 )
V_9 = F_4 ( V_9 ) ;
if ( V_2 -> V_5 & V_6 ) {
F_6 ( ( V_10 ) V_9 , V_2 -> V_7 + V_3 ) ;
F_6 ( ( V_10 ) ( V_9 >> 16 ) , V_2 -> V_7 + V_3 + 2 ) ;
} else {
F_7 ( V_9 , V_2 -> V_7 + V_3 ) ;
}
}
static T_1
F_8 ( T_1 V_11 , T_1 V_12 , T_1 V_13 , int V_14 , int V_3 )
{
if ( V_14 )
return ( V_11 * V_12 + 5000 ) / 10000 - 8 + V_3 ;
else
return ( V_11 * ( V_12 + V_13 ) + 5000 ) / 10000 - 3 + V_3 ;
}
static T_1 F_9 ( T_1 V_11 , T_1 V_15 , T_1 V_13 , int V_3 )
{
return ( ( V_11 * ( V_15 + V_13 ) + 5000 ) / 10000 ) - 1 + V_3 ;
}
static void F_10 ( struct V_1 * V_2 , bool V_16 )
{
int V_17 = 100 ;
do {
F_5 ( V_2 , V_16 , V_18 ) ;
if ( ( F_1 ( V_2 , V_19 ) & 1 ) == V_16 )
return;
F_11 ( 25 , 250 ) ;
} while ( V_17 -- );
F_12 ( V_2 -> V_2 , L_1 ,
V_16 ? L_2 : L_3 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
T_1 V_20 ;
T_1 V_21 , V_22 ;
T_1 V_23 ;
V_20 = V_2 -> V_24 ( V_2 ) ;
V_23 = F_1 ( V_2 , V_25 ) ;
if ( V_23 == F_14 ( V_26 ) ) {
V_2 -> V_5 |= V_8 ;
} else if ( V_23 == ( V_26 & 0x0000ffff ) ) {
V_2 -> V_5 |= V_6 ;
} else if ( V_23 != V_26 ) {
F_15 ( V_2 -> V_2 , L_4
L_5 , V_23 ) ;
return - V_27 ;
}
F_10 ( V_2 , false ) ;
V_21 = F_8 ( V_20 ,
40 ,
3 ,
0 ,
0 ) ;
V_22 = F_9 ( V_20 ,
47 ,
3 ,
0 ) ;
F_5 ( V_2 , V_21 , V_28 ) ;
F_5 ( V_2 , V_22 , V_29 ) ;
F_16 ( V_2 -> V_2 , L_6 , V_21 , V_22 ) ;
V_21 = F_8 ( V_20 ,
6 ,
3 ,
0 ,
0 ) ;
V_22 = F_9 ( V_20 ,
13 ,
3 ,
0 ) ;
F_5 ( V_2 , V_21 , V_30 ) ;
F_5 ( V_2 , V_22 , V_31 ) ;
F_16 ( V_2 -> V_2 , L_7 , V_21 , V_22 ) ;
if ( V_2 -> V_32 ) {
V_23 = F_1 ( V_2 , V_33 ) ;
if ( V_23 >= V_34 )
F_5 ( V_2 , V_2 -> V_32 , V_35 ) ;
else
F_12 ( V_2 -> V_2 ,
L_8 ) ;
}
F_5 ( V_2 , V_2 -> V_36 - 1 , V_37 ) ;
F_5 ( V_2 , 0 , V_38 ) ;
F_5 ( V_2 , V_2 -> V_39 , V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_17 = V_41 ;
while ( F_1 ( V_2 , V_42 ) & V_43 ) {
if ( V_17 <= 0 ) {
F_12 ( V_2 -> V_2 , L_9 ) ;
return - V_44 ;
}
V_17 -- ;
F_11 ( 1000 , 1100 ) ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
T_1 V_47 ;
F_10 ( V_2 , false ) ;
F_5 ( V_2 , V_46 [ V_2 -> V_48 ] . V_49 , V_50 ) ;
V_47 = F_1 ( V_2 , V_40 ) ;
if ( V_46 [ V_2 -> V_48 ] . V_51 & V_52 )
V_47 |= V_53 ;
else
V_47 &= ~ V_53 ;
F_5 ( V_2 , V_47 , V_40 ) ;
F_10 ( V_2 , true ) ;
F_19 ( V_2 ) ;
F_5 ( V_2 , V_54 , V_55 ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
T_1 V_56 ;
int V_57 , V_58 ;
T_1 V_49 = V_46 [ V_2 -> V_48 ] . V_49 ;
T_1 V_59 = V_2 -> V_60 ;
T_2 * V_61 = V_2 -> V_62 ;
V_56 = V_54 ;
for (; V_2 -> V_48 < V_2 -> V_63 ; V_2 -> V_48 ++ ) {
if ( V_46 [ V_2 -> V_48 ] . V_49 != V_49 ) {
F_15 ( V_2 -> V_2 ,
L_10 , V_64 ) ;
V_2 -> V_65 = - V_66 ;
break;
}
if ( V_46 [ V_2 -> V_48 ] . V_67 == 0 ) {
F_15 ( V_2 -> V_2 ,
L_11 , V_64 ) ;
V_2 -> V_65 = - V_66 ;
break;
}
if ( ! ( V_2 -> V_68 & V_69 ) ) {
V_61 = V_46 [ V_2 -> V_48 ] . V_61 ;
V_59 = V_46 [ V_2 -> V_48 ] . V_67 ;
}
V_57 = V_2 -> V_36 - F_1 ( V_2 , V_70 ) ;
V_58 = V_2 -> V_71 - F_1 ( V_2 , V_72 ) ;
while ( V_59 > 0 && V_57 > 0 && V_58 > 0 ) {
T_1 V_73 = 0 ;
if ( V_2 -> V_48 == V_2 -> V_63 - 1 &&
V_59 == 1 )
V_73 |= F_21 ( 9 ) ;
if ( V_46 [ V_2 -> V_48 ] . V_51 & V_74 ) {
if ( V_58 - V_2 -> V_75 <= 0 )
break;
F_5 ( V_2 , V_73 | 0x100 , V_76 ) ;
V_58 -- ;
V_2 -> V_75 ++ ;
} else
F_5 ( V_2 , V_73 | * V_61 ++ , V_76 ) ;
V_57 -- ; V_59 -- ;
}
V_2 -> V_62 = V_61 ;
V_2 -> V_60 = V_59 ;
if ( V_59 > 0 ) {
V_2 -> V_68 |= V_69 ;
break;
} else
V_2 -> V_68 &= ~ V_69 ;
}
if ( V_2 -> V_48 == V_2 -> V_63 )
V_56 &= ~ V_77 ;
if ( V_2 -> V_65 )
V_56 = 0 ;
F_5 ( V_2 , V_56 , V_55 ) ;
}
static void
F_22 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_46 ;
int V_78 ;
for (; V_2 -> V_79 < V_2 -> V_63 ; V_2 -> V_79 ++ ) {
T_1 V_67 ;
T_2 * V_61 ;
if ( ! ( V_46 [ V_2 -> V_79 ] . V_51 & V_74 ) )
continue;
if ( ! ( V_2 -> V_68 & V_80 ) ) {
V_67 = V_46 [ V_2 -> V_79 ] . V_67 ;
V_61 = V_46 [ V_2 -> V_79 ] . V_61 ;
} else {
V_67 = V_2 -> V_81 ;
V_61 = V_2 -> V_82 ;
}
V_78 = F_1 ( V_2 , V_72 ) ;
for (; V_67 > 0 && V_78 > 0 ; V_67 -- , V_78 -- ) {
* V_61 ++ = F_1 ( V_2 , V_76 ) ;
V_2 -> V_75 -- ;
}
if ( V_67 > 0 ) {
V_2 -> V_68 |= V_80 ;
V_2 -> V_81 = V_67 ;
V_2 -> V_82 = V_61 ;
return;
} else
V_2 -> V_68 &= ~ V_80 ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned long V_83 = V_2 -> V_83 ;
int V_84 ;
if ( V_83 & V_85 ) {
F_24 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_16 ( V_2 -> V_2 ,
L_12 , V_64 , V_86 [ V_84 ] ) ;
return - V_87 ;
}
F_24 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_15 ( V_2 -> V_2 , L_12 , V_64 , V_86 [ V_84 ] ) ;
if ( V_83 & V_88 )
return - V_89 ;
else if ( V_83 & V_90 )
return - V_66 ;
else
return - V_91 ;
}
int
F_25 ( struct V_92 * V_93 , struct V_45 V_46 [] , int V_94 )
{
struct V_1 * V_2 = F_26 ( V_93 ) ;
int V_95 ;
F_16 ( V_2 -> V_2 , L_13 , V_64 , V_94 ) ;
F_27 ( & V_2 -> V_96 ) ;
F_28 ( V_2 -> V_2 ) ;
F_29 ( V_2 -> V_97 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_63 = V_94 ;
V_2 -> V_98 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_65 = 0 ;
V_2 -> V_68 = V_99 ;
V_2 -> V_83 = 0 ;
V_2 -> V_75 = 0 ;
V_95 = F_17 ( V_2 ) ;
if ( V_95 < 0 )
goto V_100;
F_18 ( V_2 ) ;
V_95 = F_30 ( & V_2 -> V_97 , V_101 ) ;
if ( V_95 == 0 ) {
F_15 ( V_2 -> V_2 , L_14 ) ;
F_13 ( V_2 ) ;
V_95 = - V_44 ;
goto V_100;
}
F_10 ( V_2 , false ) ;
if ( V_2 -> V_65 ) {
V_95 = V_2 -> V_65 ;
goto V_100;
}
if ( F_31 ( ! V_2 -> V_98 ) ) {
V_95 = V_94 ;
goto V_100;
}
if ( V_2 -> V_98 == V_102 ) {
V_95 = F_23 ( V_2 ) ;
goto V_100;
}
V_95 = - V_91 ;
V_100:
F_32 ( V_2 -> V_2 ) ;
F_33 ( V_2 -> V_2 ) ;
F_34 ( & V_2 -> V_96 ) ;
return V_95 ;
}
T_1 F_35 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_26 ( V_93 ) ;
return V_2 -> V_103 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
T_1 V_104 ;
V_104 = F_1 ( V_2 , V_105 ) ;
if ( V_104 & V_106 )
F_1 ( V_2 , V_107 ) ;
if ( V_104 & V_108 )
F_1 ( V_2 , V_109 ) ;
if ( V_104 & V_110 )
F_1 ( V_2 , V_111 ) ;
if ( V_104 & V_112 )
F_1 ( V_2 , V_113 ) ;
if ( V_104 & V_114 ) {
V_2 -> V_83 = F_1 ( V_2 , V_115 ) ;
F_1 ( V_2 , V_116 ) ;
}
if ( V_104 & V_117 )
F_1 ( V_2 , V_118 ) ;
if ( V_104 & V_119 )
F_1 ( V_2 , V_120 ) ;
if ( V_104 & V_121 )
F_1 ( V_2 , V_122 ) ;
if ( V_104 & V_123 )
F_1 ( V_2 , V_124 ) ;
if ( V_104 & V_125 )
F_1 ( V_2 , V_126 ) ;
return V_104 ;
}
T_3 F_37 ( int V_127 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
T_1 V_104 , V_129 ;
V_129 = F_1 ( V_2 , V_18 ) ;
V_104 = F_1 ( V_2 , V_130 ) ;
F_16 ( V_2 -> V_2 , L_15 , V_64 ,
V_2 -> V_131 . V_132 , V_129 , V_104 ) ;
if ( ! V_129 || ! ( V_104 & ~ V_119 ) )
return V_133 ;
V_104 = F_36 ( V_2 ) ;
if ( V_104 & V_114 ) {
V_2 -> V_98 |= V_102 ;
V_2 -> V_68 = V_99 ;
F_5 ( V_2 , 0 , V_55 ) ;
goto V_134;
}
if ( V_104 & V_135 )
F_22 ( V_2 ) ;
if ( V_104 & V_77 )
F_20 ( V_2 ) ;
V_134:
if ( ( V_104 & ( V_114 | V_121 ) ) || V_2 -> V_65 )
F_38 ( & V_2 -> V_97 ) ;
return V_136 ;
}
void F_39 ( struct V_1 * V_2 )
{
F_10 ( V_2 , true ) ;
}
T_1 F_40 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_18 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_10 ( V_2 , false ) ;
F_5 ( V_2 , 0 , V_55 ) ;
F_1 ( V_2 , V_137 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_137 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_55 ) ;
}
T_1 F_43 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_138 ) ;
}
