T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 + V_3 ) ;
if ( V_2 -> V_6 )
return F_3 ( V_4 ) ;
else
return V_4 ;
}
void F_4 ( struct V_1 * V_2 , T_1 V_7 , int V_3 )
{
if ( V_2 -> V_6 )
V_7 = F_3 ( V_7 ) ;
F_5 ( V_7 , V_2 -> V_5 + V_3 ) ;
}
static T_1
F_6 ( T_1 V_8 , T_1 V_9 , T_1 V_10 , int V_11 , int V_3 )
{
if ( V_11 )
return ( V_8 * V_9 + 5000 ) / 10000 - 8 + V_3 ;
else
return ( V_8 * ( V_9 + V_10 ) + 5000 ) / 10000 - 3 + V_3 ;
}
static T_1 F_7 ( T_1 V_8 , T_1 V_12 , T_1 V_10 , int V_3 )
{
return ( ( V_8 * ( V_12 + V_10 ) + 5000 ) / 10000 ) - 1 + V_3 ;
}
int F_8 ( struct V_1 * V_2 )
{
T_1 V_13 ;
T_1 V_14 , V_15 ;
T_1 V_16 ;
V_13 = V_2 -> V_17 ( V_2 ) ;
V_16 = F_1 ( V_2 , V_18 ) ;
if ( V_16 == F_9 ( V_19 ) ) {
V_2 -> V_6 = 1 ;
V_16 = V_19 ;
}
if ( V_16 != V_19 ) {
F_10 ( V_2 -> V_2 , L_1
L_2 , V_16 ) ;
return - V_20 ;
}
F_4 ( V_2 , 0 , V_21 ) ;
V_14 = F_6 ( V_13 ,
40 ,
3 ,
0 ,
0 ) ;
V_15 = F_7 ( V_13 ,
47 ,
3 ,
0 ) ;
F_4 ( V_2 , V_14 , V_22 ) ;
F_4 ( V_2 , V_15 , V_23 ) ;
F_11 ( V_2 -> V_2 , L_3 , V_14 , V_15 ) ;
V_14 = F_6 ( V_13 ,
6 ,
3 ,
0 ,
0 ) ;
V_15 = F_7 ( V_13 ,
13 ,
3 ,
0 ) ;
F_4 ( V_2 , V_14 , V_24 ) ;
F_4 ( V_2 , V_15 , V_25 ) ;
F_11 ( V_2 -> V_2 , L_4 , V_14 , V_15 ) ;
F_4 ( V_2 , V_2 -> V_26 - 1 , V_27 ) ;
F_4 ( V_2 , 0 , V_28 ) ;
F_4 ( V_2 , V_2 -> V_29 , V_30 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_31 = V_32 ;
while ( F_1 ( V_2 , V_33 ) & V_34 ) {
if ( V_31 <= 0 ) {
F_13 ( V_2 -> V_2 , L_5 ) ;
return - V_35 ;
}
V_31 -- ;
F_14 ( 1 ) ;
}
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
T_1 V_38 ;
F_4 ( V_2 , 0 , V_21 ) ;
F_4 ( V_2 , V_37 [ V_2 -> V_39 ] . V_40 , V_41 ) ;
V_38 = F_1 ( V_2 , V_30 ) ;
if ( V_37 [ V_2 -> V_39 ] . V_42 & V_43 )
V_38 |= V_44 ;
else
V_38 &= ~ V_44 ;
F_4 ( V_2 , V_38 , V_30 ) ;
F_4 ( V_2 , 1 , V_21 ) ;
F_4 ( V_2 , V_45 , V_46 ) ;
}
void
F_16 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
T_1 V_47 ;
int V_48 , V_49 ;
T_1 V_40 = V_37 [ V_2 -> V_39 ] . V_40 ;
T_1 V_50 = V_2 -> V_51 ;
T_2 * V_52 = V_2 -> V_53 ;
V_47 = V_45 ;
for (; V_2 -> V_39 < V_2 -> V_54 ; V_2 -> V_39 ++ ) {
if ( V_37 [ V_2 -> V_39 ] . V_40 != V_40 ) {
F_10 ( V_2 -> V_2 ,
L_6 , V_55 ) ;
V_2 -> V_56 = - V_57 ;
break;
}
if ( V_37 [ V_2 -> V_39 ] . V_58 == 0 ) {
F_10 ( V_2 -> V_2 ,
L_7 , V_55 ) ;
V_2 -> V_56 = - V_57 ;
break;
}
if ( ! ( V_2 -> V_59 & V_60 ) ) {
V_52 = V_37 [ V_2 -> V_39 ] . V_52 ;
V_50 = V_37 [ V_2 -> V_39 ] . V_58 ;
}
V_48 = V_2 -> V_26 - F_1 ( V_2 , V_61 ) ;
V_49 = V_2 -> V_62 - F_1 ( V_2 , V_63 ) ;
while ( V_50 > 0 && V_48 > 0 && V_49 > 0 ) {
if ( V_37 [ V_2 -> V_39 ] . V_42 & V_64 ) {
F_4 ( V_2 , 0x100 , V_65 ) ;
V_49 -- ;
} else
F_4 ( V_2 , * V_52 ++ , V_65 ) ;
V_48 -- ; V_50 -- ;
}
V_2 -> V_53 = V_52 ;
V_2 -> V_51 = V_50 ;
if ( V_50 > 0 ) {
V_2 -> V_59 |= V_60 ;
break;
} else
V_2 -> V_59 &= ~ V_60 ;
}
if ( V_2 -> V_39 == V_2 -> V_54 )
V_47 &= ~ V_66 ;
if ( V_2 -> V_56 )
V_47 = 0 ;
F_4 ( V_2 , V_47 , V_46 ) ;
}
static void
F_17 ( struct V_1 * V_2 )
{
struct V_36 * V_37 = V_2 -> V_37 ;
int V_67 ;
for (; V_2 -> V_68 < V_2 -> V_54 ; V_2 -> V_68 ++ ) {
T_1 V_58 ;
T_2 * V_52 ;
if ( ! ( V_37 [ V_2 -> V_68 ] . V_42 & V_64 ) )
continue;
if ( ! ( V_2 -> V_59 & V_69 ) ) {
V_58 = V_37 [ V_2 -> V_68 ] . V_58 ;
V_52 = V_37 [ V_2 -> V_68 ] . V_52 ;
} else {
V_58 = V_2 -> V_70 ;
V_52 = V_2 -> V_71 ;
}
V_67 = F_1 ( V_2 , V_63 ) ;
for (; V_58 > 0 && V_67 > 0 ; V_58 -- , V_67 -- )
* V_52 ++ = F_1 ( V_2 , V_65 ) ;
if ( V_58 > 0 ) {
V_2 -> V_59 |= V_69 ;
V_2 -> V_70 = V_58 ;
V_2 -> V_71 = V_52 ;
return;
} else
V_2 -> V_59 &= ~ V_69 ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned long V_72 = V_2 -> V_72 ;
int V_73 ;
if ( V_72 & V_74 ) {
F_19 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_11 ( V_2 -> V_2 ,
L_8 , V_55 , V_75 [ V_73 ] ) ;
return - V_76 ;
}
F_19 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_10 ( V_2 -> V_2 , L_8 , V_55 , V_75 [ V_73 ] ) ;
if ( V_72 & V_77 )
return - V_78 ;
else if ( V_72 & V_79 )
return - V_57 ;
else
return - V_80 ;
}
int
F_20 ( struct V_81 * V_82 , struct V_36 V_37 [] , int V_83 )
{
struct V_1 * V_2 = F_21 ( V_82 ) ;
int V_84 ;
F_11 ( V_2 -> V_2 , L_9 , V_55 , V_83 ) ;
F_22 ( & V_2 -> V_85 ) ;
F_23 ( V_2 -> V_2 ) ;
F_24 ( V_2 -> V_86 ) ;
V_2 -> V_37 = V_37 ;
V_2 -> V_54 = V_83 ;
V_2 -> V_87 = 0 ;
V_2 -> V_39 = 0 ;
V_2 -> V_68 = 0 ;
V_2 -> V_56 = 0 ;
V_2 -> V_59 = V_88 ;
V_2 -> V_72 = 0 ;
V_84 = F_12 ( V_2 ) ;
if ( V_84 < 0 )
goto V_89;
F_15 ( V_2 ) ;
V_84 = F_25 ( & V_2 -> V_86 , V_90 ) ;
if ( V_84 == 0 ) {
F_10 ( V_2 -> V_2 , L_10 ) ;
F_8 ( V_2 ) ;
V_84 = - V_35 ;
goto V_89;
} else if ( V_84 < 0 )
goto V_89;
if ( V_2 -> V_56 ) {
V_84 = V_2 -> V_56 ;
goto V_89;
}
if ( F_26 ( ! V_2 -> V_87 ) ) {
F_4 ( V_2 , 0 , V_21 ) ;
V_84 = V_83 ;
goto V_89;
}
if ( V_2 -> V_87 == V_91 ) {
V_84 = F_18 ( V_2 ) ;
goto V_89;
}
V_84 = - V_80 ;
V_89:
F_27 ( V_2 -> V_2 ) ;
F_28 ( & V_2 -> V_85 ) ;
return V_84 ;
}
T_1 F_29 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_21 ( V_82 ) ;
return V_2 -> V_92 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
T_1 V_93 ;
V_93 = F_1 ( V_2 , V_94 ) ;
if ( V_93 & V_95 )
F_1 ( V_2 , V_96 ) ;
if ( V_93 & V_97 )
F_1 ( V_2 , V_98 ) ;
if ( V_93 & V_99 )
F_1 ( V_2 , V_100 ) ;
if ( V_93 & V_101 )
F_1 ( V_2 , V_102 ) ;
if ( V_93 & V_103 ) {
V_2 -> V_72 = F_1 ( V_2 , V_104 ) ;
F_1 ( V_2 , V_105 ) ;
}
if ( V_93 & V_106 )
F_1 ( V_2 , V_107 ) ;
if ( V_93 & V_108 )
F_1 ( V_2 , V_109 ) ;
if ( V_93 & V_110 )
F_1 ( V_2 , V_111 ) ;
if ( V_93 & V_112 )
F_1 ( V_2 , V_113 ) ;
if ( V_93 & V_114 )
F_1 ( V_2 , V_115 ) ;
return V_93 ;
}
T_3 F_31 ( int V_116 , void * V_117 )
{
struct V_1 * V_2 = V_117 ;
T_1 V_93 , V_118 ;
V_118 = F_1 ( V_2 , V_21 ) ;
V_93 = F_1 ( V_2 , V_119 ) ;
F_11 ( V_2 -> V_2 , L_11 , V_55 ,
V_2 -> V_120 . V_121 , V_118 , V_93 ) ;
if ( ! V_118 || ! ( V_93 & ~ V_108 ) )
return V_122 ;
V_93 = F_30 ( V_2 ) ;
if ( V_93 & V_103 ) {
V_2 -> V_87 |= V_91 ;
V_2 -> V_59 = V_88 ;
F_4 ( V_2 , 0 , V_46 ) ;
goto V_123;
}
if ( V_93 & V_124 )
F_17 ( V_2 ) ;
if ( V_93 & V_66 )
F_16 ( V_2 ) ;
V_123:
if ( ( V_93 & ( V_103 | V_110 ) ) || V_2 -> V_56 )
F_32 ( & V_2 -> V_86 ) ;
return V_125 ;
}
void F_33 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 1 , V_21 ) ;
}
T_1 F_34 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_21 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 0 , V_21 ) ;
F_4 ( V_2 , 0 , V_46 ) ;
F_1 ( V_2 , V_126 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_126 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 0 , V_46 ) ;
}
T_1 F_38 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_127 ) ;
}
