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
int F_10 ( struct V_1 * V_2 )
{
T_1 V_16 ;
T_1 V_17 , V_18 ;
T_1 V_19 ;
V_16 = V_2 -> V_20 ( V_2 ) ;
V_19 = F_1 ( V_2 , V_21 ) ;
if ( V_19 == F_11 ( V_22 ) ) {
V_2 -> V_5 |= V_8 ;
} else if ( V_19 == ( V_22 & 0x0000ffff ) ) {
V_2 -> V_5 |= V_6 ;
} else if ( V_19 != V_22 ) {
F_12 ( V_2 -> V_2 , L_1
L_2 , V_19 ) ;
return - V_23 ;
}
F_5 ( V_2 , 0 , V_24 ) ;
V_17 = F_8 ( V_16 ,
40 ,
3 ,
0 ,
0 ) ;
V_18 = F_9 ( V_16 ,
47 ,
3 ,
0 ) ;
F_5 ( V_2 , V_17 , V_25 ) ;
F_5 ( V_2 , V_18 , V_26 ) ;
F_13 ( V_2 -> V_2 , L_3 , V_17 , V_18 ) ;
V_17 = F_8 ( V_16 ,
6 ,
3 ,
0 ,
0 ) ;
V_18 = F_9 ( V_16 ,
13 ,
3 ,
0 ) ;
F_5 ( V_2 , V_17 , V_27 ) ;
F_5 ( V_2 , V_18 , V_28 ) ;
F_13 ( V_2 -> V_2 , L_4 , V_17 , V_18 ) ;
F_5 ( V_2 , V_2 -> V_29 - 1 , V_30 ) ;
F_5 ( V_2 , 0 , V_31 ) ;
F_5 ( V_2 , V_2 -> V_32 , V_33 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_34 = V_35 ;
while ( F_1 ( V_2 , V_36 ) & V_37 ) {
if ( V_34 <= 0 ) {
F_15 ( V_2 -> V_2 , L_5 ) ;
return - V_38 ;
}
V_34 -- ;
F_16 ( 1 ) ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
T_1 V_41 ;
F_5 ( V_2 , 0 , V_24 ) ;
F_5 ( V_2 , V_40 [ V_2 -> V_42 ] . V_43 , V_44 ) ;
V_41 = F_1 ( V_2 , V_33 ) ;
if ( V_40 [ V_2 -> V_42 ] . V_45 & V_46 )
V_41 |= V_47 ;
else
V_41 &= ~ V_47 ;
F_5 ( V_2 , V_41 , V_33 ) ;
F_5 ( V_2 , 1 , V_24 ) ;
F_5 ( V_2 , V_48 , V_49 ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
T_1 V_50 ;
int V_51 , V_52 ;
T_1 V_43 = V_40 [ V_2 -> V_42 ] . V_43 ;
T_1 V_53 = V_2 -> V_54 ;
T_2 * V_55 = V_2 -> V_56 ;
V_50 = V_48 ;
for (; V_2 -> V_42 < V_2 -> V_57 ; V_2 -> V_42 ++ ) {
if ( V_40 [ V_2 -> V_42 ] . V_43 != V_43 ) {
F_12 ( V_2 -> V_2 ,
L_6 , V_58 ) ;
V_2 -> V_59 = - V_60 ;
break;
}
if ( V_40 [ V_2 -> V_42 ] . V_61 == 0 ) {
F_12 ( V_2 -> V_2 ,
L_7 , V_58 ) ;
V_2 -> V_59 = - V_60 ;
break;
}
if ( ! ( V_2 -> V_62 & V_63 ) ) {
V_55 = V_40 [ V_2 -> V_42 ] . V_55 ;
V_53 = V_40 [ V_2 -> V_42 ] . V_61 ;
}
V_51 = V_2 -> V_29 - F_1 ( V_2 , V_64 ) ;
V_52 = V_2 -> V_65 - F_1 ( V_2 , V_66 ) ;
while ( V_53 > 0 && V_51 > 0 && V_52 > 0 ) {
if ( V_40 [ V_2 -> V_42 ] . V_45 & V_67 ) {
F_5 ( V_2 , 0x100 , V_68 ) ;
V_52 -- ;
} else
F_5 ( V_2 , * V_55 ++ , V_68 ) ;
V_51 -- ; V_53 -- ;
}
V_2 -> V_56 = V_55 ;
V_2 -> V_54 = V_53 ;
if ( V_53 > 0 ) {
V_2 -> V_62 |= V_63 ;
break;
} else
V_2 -> V_62 &= ~ V_63 ;
}
if ( V_2 -> V_42 == V_2 -> V_57 )
V_50 &= ~ V_69 ;
if ( V_2 -> V_59 )
V_50 = 0 ;
F_5 ( V_2 , V_50 , V_49 ) ;
}
static void
F_19 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_40 ;
int V_70 ;
for (; V_2 -> V_71 < V_2 -> V_57 ; V_2 -> V_71 ++ ) {
T_1 V_61 ;
T_2 * V_55 ;
if ( ! ( V_40 [ V_2 -> V_71 ] . V_45 & V_67 ) )
continue;
if ( ! ( V_2 -> V_62 & V_72 ) ) {
V_61 = V_40 [ V_2 -> V_71 ] . V_61 ;
V_55 = V_40 [ V_2 -> V_71 ] . V_55 ;
} else {
V_61 = V_2 -> V_73 ;
V_55 = V_2 -> V_74 ;
}
V_70 = F_1 ( V_2 , V_66 ) ;
for (; V_61 > 0 && V_70 > 0 ; V_61 -- , V_70 -- )
* V_55 ++ = F_1 ( V_2 , V_68 ) ;
if ( V_61 > 0 ) {
V_2 -> V_62 |= V_72 ;
V_2 -> V_73 = V_61 ;
V_2 -> V_74 = V_55 ;
return;
} else
V_2 -> V_62 &= ~ V_72 ;
}
}
static int F_20 ( struct V_1 * V_2 )
{
unsigned long V_75 = V_2 -> V_75 ;
int V_76 ;
if ( V_75 & V_77 ) {
F_21 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_13 ( V_2 -> V_2 ,
L_8 , V_58 , V_78 [ V_76 ] ) ;
return - V_79 ;
}
F_21 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_12 ( V_2 -> V_2 , L_8 , V_58 , V_78 [ V_76 ] ) ;
if ( V_75 & V_80 )
return - V_81 ;
else if ( V_75 & V_82 )
return - V_60 ;
else
return - V_83 ;
}
int
F_22 ( struct V_84 * V_85 , struct V_39 V_40 [] , int V_86 )
{
struct V_1 * V_2 = F_23 ( V_85 ) ;
int V_87 ;
F_13 ( V_2 -> V_2 , L_9 , V_58 , V_86 ) ;
F_24 ( & V_2 -> V_88 ) ;
F_25 ( V_2 -> V_2 ) ;
F_26 ( V_2 -> V_89 ) ;
V_2 -> V_40 = V_40 ;
V_2 -> V_57 = V_86 ;
V_2 -> V_90 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_59 = 0 ;
V_2 -> V_62 = V_91 ;
V_2 -> V_75 = 0 ;
V_87 = F_14 ( V_2 ) ;
if ( V_87 < 0 )
goto V_92;
F_17 ( V_2 ) ;
V_87 = F_27 ( & V_2 -> V_89 , V_93 ) ;
if ( V_87 == 0 ) {
F_12 ( V_2 -> V_2 , L_10 ) ;
F_10 ( V_2 ) ;
V_87 = - V_38 ;
goto V_92;
} else if ( V_87 < 0 )
goto V_92;
if ( V_2 -> V_59 ) {
V_87 = V_2 -> V_59 ;
goto V_92;
}
if ( F_28 ( ! V_2 -> V_90 ) ) {
F_5 ( V_2 , 0 , V_24 ) ;
V_87 = V_86 ;
goto V_92;
}
if ( V_2 -> V_90 == V_94 ) {
V_87 = F_20 ( V_2 ) ;
goto V_92;
}
V_87 = - V_83 ;
V_92:
F_29 ( V_2 -> V_2 ) ;
F_30 ( & V_2 -> V_88 ) ;
return V_87 ;
}
T_1 F_31 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_23 ( V_85 ) ;
return V_2 -> V_95 ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
T_1 V_96 ;
V_96 = F_1 ( V_2 , V_97 ) ;
if ( V_96 & V_98 )
F_1 ( V_2 , V_99 ) ;
if ( V_96 & V_100 )
F_1 ( V_2 , V_101 ) ;
if ( V_96 & V_102 )
F_1 ( V_2 , V_103 ) ;
if ( V_96 & V_104 )
F_1 ( V_2 , V_105 ) ;
if ( V_96 & V_106 ) {
V_2 -> V_75 = F_1 ( V_2 , V_107 ) ;
F_1 ( V_2 , V_108 ) ;
}
if ( V_96 & V_109 )
F_1 ( V_2 , V_110 ) ;
if ( V_96 & V_111 )
F_1 ( V_2 , V_112 ) ;
if ( V_96 & V_113 )
F_1 ( V_2 , V_114 ) ;
if ( V_96 & V_115 )
F_1 ( V_2 , V_116 ) ;
if ( V_96 & V_117 )
F_1 ( V_2 , V_118 ) ;
return V_96 ;
}
T_3 F_33 ( int V_119 , void * V_120 )
{
struct V_1 * V_2 = V_120 ;
T_1 V_96 , V_121 ;
V_121 = F_1 ( V_2 , V_24 ) ;
V_96 = F_1 ( V_2 , V_122 ) ;
F_13 ( V_2 -> V_2 , L_11 , V_58 ,
V_2 -> V_123 . V_124 , V_121 , V_96 ) ;
if ( ! V_121 || ! ( V_96 & ~ V_111 ) )
return V_125 ;
V_96 = F_32 ( V_2 ) ;
if ( V_96 & V_106 ) {
V_2 -> V_90 |= V_94 ;
V_2 -> V_62 = V_91 ;
F_5 ( V_2 , 0 , V_49 ) ;
goto V_126;
}
if ( V_96 & V_127 )
F_19 ( V_2 ) ;
if ( V_96 & V_69 )
F_18 ( V_2 ) ;
V_126:
if ( ( V_96 & ( V_106 | V_113 ) ) || V_2 -> V_59 )
F_34 ( & V_2 -> V_89 ) ;
return V_128 ;
}
void F_35 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 1 , V_24 ) ;
}
T_1 F_36 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_24 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_24 ) ;
F_5 ( V_2 , 0 , V_49 ) ;
F_1 ( V_2 , V_129 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_129 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_49 ) ;
}
T_1 F_40 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_130 ) ;
}
