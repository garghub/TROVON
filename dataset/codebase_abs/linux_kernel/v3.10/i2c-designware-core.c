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
F_5 ( V_2 , V_2 -> V_32 - 1 , V_33 ) ;
F_5 ( V_2 , 0 , V_34 ) ;
F_5 ( V_2 , V_2 -> V_35 , V_36 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_17 = V_37 ;
while ( F_1 ( V_2 , V_38 ) & V_39 ) {
if ( V_17 <= 0 ) {
F_12 ( V_2 -> V_2 , L_8 ) ;
return - V_40 ;
}
V_17 -- ;
F_11 ( 1000 , 1100 ) ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_1 V_43 ;
F_10 ( V_2 , false ) ;
F_5 ( V_2 , V_42 [ V_2 -> V_44 ] . V_45 , V_46 ) ;
V_43 = F_1 ( V_2 , V_36 ) ;
if ( V_42 [ V_2 -> V_44 ] . V_47 & V_48 )
V_43 |= V_49 ;
else
V_43 &= ~ V_49 ;
F_5 ( V_2 , V_43 , V_36 ) ;
F_10 ( V_2 , true ) ;
F_19 ( V_2 ) ;
F_5 ( V_2 , V_50 , V_51 ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
T_1 V_52 ;
int V_53 , V_54 ;
T_1 V_45 = V_42 [ V_2 -> V_44 ] . V_45 ;
T_1 V_55 = V_2 -> V_56 ;
T_2 * V_57 = V_2 -> V_58 ;
V_52 = V_50 ;
for (; V_2 -> V_44 < V_2 -> V_59 ; V_2 -> V_44 ++ ) {
if ( V_42 [ V_2 -> V_44 ] . V_45 != V_45 ) {
F_15 ( V_2 -> V_2 ,
L_9 , V_60 ) ;
V_2 -> V_61 = - V_62 ;
break;
}
if ( V_42 [ V_2 -> V_44 ] . V_63 == 0 ) {
F_15 ( V_2 -> V_2 ,
L_10 , V_60 ) ;
V_2 -> V_61 = - V_62 ;
break;
}
if ( ! ( V_2 -> V_64 & V_65 ) ) {
V_57 = V_42 [ V_2 -> V_44 ] . V_57 ;
V_55 = V_42 [ V_2 -> V_44 ] . V_63 ;
}
V_53 = V_2 -> V_32 - F_1 ( V_2 , V_66 ) ;
V_54 = V_2 -> V_67 - F_1 ( V_2 , V_68 ) ;
while ( V_55 > 0 && V_53 > 0 && V_54 > 0 ) {
T_1 V_69 = 0 ;
if ( V_2 -> V_44 == V_2 -> V_59 - 1 &&
V_55 == 1 )
V_69 |= F_21 ( 9 ) ;
if ( V_42 [ V_2 -> V_44 ] . V_47 & V_70 ) {
if ( V_54 - V_2 -> V_71 <= 0 )
break;
F_5 ( V_2 , V_69 | 0x100 , V_72 ) ;
V_54 -- ;
V_2 -> V_71 ++ ;
} else
F_5 ( V_2 , V_69 | * V_57 ++ , V_72 ) ;
V_53 -- ; V_55 -- ;
}
V_2 -> V_58 = V_57 ;
V_2 -> V_56 = V_55 ;
if ( V_55 > 0 ) {
V_2 -> V_64 |= V_65 ;
break;
} else
V_2 -> V_64 &= ~ V_65 ;
}
if ( V_2 -> V_44 == V_2 -> V_59 )
V_52 &= ~ V_73 ;
if ( V_2 -> V_61 )
V_52 = 0 ;
F_5 ( V_2 , V_52 , V_51 ) ;
}
static void
F_22 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_42 ;
int V_74 ;
for (; V_2 -> V_75 < V_2 -> V_59 ; V_2 -> V_75 ++ ) {
T_1 V_63 ;
T_2 * V_57 ;
if ( ! ( V_42 [ V_2 -> V_75 ] . V_47 & V_70 ) )
continue;
if ( ! ( V_2 -> V_64 & V_76 ) ) {
V_63 = V_42 [ V_2 -> V_75 ] . V_63 ;
V_57 = V_42 [ V_2 -> V_75 ] . V_57 ;
} else {
V_63 = V_2 -> V_77 ;
V_57 = V_2 -> V_78 ;
}
V_74 = F_1 ( V_2 , V_68 ) ;
for (; V_63 > 0 && V_74 > 0 ; V_63 -- , V_74 -- ) {
* V_57 ++ = F_1 ( V_2 , V_72 ) ;
V_2 -> V_71 -- ;
}
if ( V_63 > 0 ) {
V_2 -> V_64 |= V_76 ;
V_2 -> V_77 = V_63 ;
V_2 -> V_78 = V_57 ;
return;
} else
V_2 -> V_64 &= ~ V_76 ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
unsigned long V_79 = V_2 -> V_79 ;
int V_80 ;
if ( V_79 & V_81 ) {
F_24 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_16 ( V_2 -> V_2 ,
L_11 , V_60 , V_82 [ V_80 ] ) ;
return - V_83 ;
}
F_24 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_15 ( V_2 -> V_2 , L_11 , V_60 , V_82 [ V_80 ] ) ;
if ( V_79 & V_84 )
return - V_85 ;
else if ( V_79 & V_86 )
return - V_62 ;
else
return - V_87 ;
}
int
F_25 ( struct V_88 * V_89 , struct V_41 V_42 [] , int V_90 )
{
struct V_1 * V_2 = F_26 ( V_89 ) ;
int V_91 ;
F_16 ( V_2 -> V_2 , L_12 , V_60 , V_90 ) ;
F_27 ( & V_2 -> V_92 ) ;
F_28 ( V_2 -> V_2 ) ;
F_29 ( V_2 -> V_93 ) ;
V_2 -> V_42 = V_42 ;
V_2 -> V_59 = V_90 ;
V_2 -> V_94 = 0 ;
V_2 -> V_44 = 0 ;
V_2 -> V_75 = 0 ;
V_2 -> V_61 = 0 ;
V_2 -> V_64 = V_95 ;
V_2 -> V_79 = 0 ;
V_2 -> V_71 = 0 ;
V_91 = F_17 ( V_2 ) ;
if ( V_91 < 0 )
goto V_96;
F_18 ( V_2 ) ;
V_91 = F_30 ( & V_2 -> V_93 , V_97 ) ;
if ( V_91 == 0 ) {
F_15 ( V_2 -> V_2 , L_13 ) ;
F_13 ( V_2 ) ;
V_91 = - V_40 ;
goto V_96;
} else if ( V_91 < 0 )
goto V_96;
if ( V_2 -> V_61 ) {
V_91 = V_2 -> V_61 ;
goto V_96;
}
if ( F_31 ( ! V_2 -> V_94 ) ) {
F_10 ( V_2 , false ) ;
V_91 = V_90 ;
goto V_96;
}
if ( V_2 -> V_94 == V_98 ) {
V_91 = F_23 ( V_2 ) ;
goto V_96;
}
V_91 = - V_87 ;
V_96:
F_32 ( V_2 -> V_2 ) ;
F_33 ( V_2 -> V_2 ) ;
F_34 ( & V_2 -> V_92 ) ;
return V_91 ;
}
T_1 F_35 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_26 ( V_89 ) ;
return V_2 -> V_99 ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
T_1 V_100 ;
V_100 = F_1 ( V_2 , V_101 ) ;
if ( V_100 & V_102 )
F_1 ( V_2 , V_103 ) ;
if ( V_100 & V_104 )
F_1 ( V_2 , V_105 ) ;
if ( V_100 & V_106 )
F_1 ( V_2 , V_107 ) ;
if ( V_100 & V_108 )
F_1 ( V_2 , V_109 ) ;
if ( V_100 & V_110 ) {
V_2 -> V_79 = F_1 ( V_2 , V_111 ) ;
F_1 ( V_2 , V_112 ) ;
}
if ( V_100 & V_113 )
F_1 ( V_2 , V_114 ) ;
if ( V_100 & V_115 )
F_1 ( V_2 , V_116 ) ;
if ( V_100 & V_117 )
F_1 ( V_2 , V_118 ) ;
if ( V_100 & V_119 )
F_1 ( V_2 , V_120 ) ;
if ( V_100 & V_121 )
F_1 ( V_2 , V_122 ) ;
return V_100 ;
}
T_3 F_37 ( int V_123 , void * V_124 )
{
struct V_1 * V_2 = V_124 ;
T_1 V_100 , V_125 ;
V_125 = F_1 ( V_2 , V_18 ) ;
V_100 = F_1 ( V_2 , V_126 ) ;
F_16 ( V_2 -> V_2 , L_14 , V_60 ,
V_2 -> V_127 . V_128 , V_125 , V_100 ) ;
if ( ! V_125 || ! ( V_100 & ~ V_115 ) )
return V_129 ;
V_100 = F_36 ( V_2 ) ;
if ( V_100 & V_110 ) {
V_2 -> V_94 |= V_98 ;
V_2 -> V_64 = V_95 ;
F_5 ( V_2 , 0 , V_51 ) ;
goto V_130;
}
if ( V_100 & V_131 )
F_22 ( V_2 ) ;
if ( V_100 & V_73 )
F_20 ( V_2 ) ;
V_130:
if ( ( V_100 & ( V_110 | V_117 ) ) || V_2 -> V_61 )
F_38 ( & V_2 -> V_93 ) ;
return V_132 ;
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
F_5 ( V_2 , 0 , V_51 ) ;
F_1 ( V_2 , V_133 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_133 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_51 ) ;
}
T_1 F_43 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_134 ) ;
}
