static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
int V_7 = 0 ;
int V_8 ;
unsigned int V_9 ;
V_9 = V_3 | V_10 | V_11 ;
F_3 ( V_2 , V_12 , V_9 ) ;
F_4 ( V_2 -> V_13 , L_1 ) ;
if ( V_5 -> V_14 )
V_8 = 4 ;
else
V_8 = 400 ;
do {
V_7 ++ ;
if ( V_5 -> V_14 )
F_5 ( & V_5 -> V_15 ,
F_6 ( 250 ) ) ;
else
F_7 ( 1 ) ;
V_6 = F_8 ( V_2 , V_12 ) ;
F_4 ( V_2 -> V_13 , L_2 , V_6 ) ;
} while ( V_6 & V_3 && V_7 < V_8 );
if ( V_6 & V_3 )
F_9 ( V_2 -> V_13 , L_3 ,
V_3 ) ;
}
T_1 F_10 ( int V_16 , void * V_17 )
{
struct V_4 * V_5 = V_17 ;
F_11 ( & V_5 -> V_15 ) ;
return V_18 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_2 V_19 ;
T_3 V_6 , V_20 , V_21 , V_22 , V_23 ;
switch ( V_5 -> V_24 ) {
case 2 :
V_23 = V_25 ;
break;
default:
V_23 = V_26 ;
break;
}
if ( V_5 -> V_27 && V_5 -> V_28 ) {
F_4 ( V_2 -> V_13 , L_4 ,
V_5 -> V_28 ) ;
F_3 ( V_2 , V_23 , V_5 -> V_28 ) ;
F_1 ( V_2 ,
V_29 |
V_30 ) ;
return;
}
if ( V_5 -> V_31 ) {
F_13 ( V_2 , V_32 ,
V_33 ,
32 << V_34 ) ;
F_1 ( V_2 ,
V_35 |
V_36 ) ;
} else {
F_1 ( V_2 ,
V_37 |
V_38 ) ;
}
switch ( V_5 -> V_24 ) {
case 0 :
V_20 = F_8 ( V_2 , V_39 )
& V_40 ;
V_21 = F_8 ( V_2 , V_41 )
& V_42 ;
break;
case 2 :
case 1 :
V_6 = F_8 ( V_2 , V_23 ) ;
V_21 = ( V_6 & V_43 )
>> V_44 ;
V_20 = V_6 & V_45 ;
break;
default:
F_14 ( 1 , L_5 ) ;
break;
}
F_4 ( V_2 -> V_13 , L_6 , V_20 , V_21 ) ;
if ( V_5 -> V_46 || V_5 -> V_47 ) {
F_4 ( V_2 -> V_13 ,
L_7 ,
V_5 -> V_46 , V_5 -> V_47 ) ;
V_19 = V_21 ;
V_19 += V_5 -> V_47 ;
V_22 = ( V_48 ) V_19 << V_44 ;
V_19 = V_20 ;
V_19 += V_5 -> V_46 ;
V_22 |= ( V_48 ) V_19 ;
F_4 ( V_2 -> V_13 , L_8 , V_22 ) ;
F_3 ( V_2 , V_23 , V_22 ) ;
F_1 ( V_2 ,
V_29 |
V_30 ) ;
} else {
V_22 = V_21 << V_44 ;
V_22 |= V_20 ;
}
if ( V_5 -> V_27 )
V_5 -> V_28 = V_22 ;
}
static int F_15 ( struct V_49 * V_50 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_16 ( V_50 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_53 ;
V_53 = F_17 ( V_50 , V_52 ) ;
V_5 -> V_28 = 0 ;
if ( V_5 -> V_46 || V_5 -> V_47 || V_5 -> V_54 )
return V_53 ;
if ( F_8 ( V_2 , V_55 )
& ( V_56 | V_57 ) )
F_13 ( V_2 ,
V_12 ,
V_58 |
V_59 ,
V_58 |
V_59 ) ;
return V_53 ;
}
static int F_18 ( struct V_60 * V_61 ,
struct V_49 * V_50 , int V_62 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_62 ) {
case V_63 :
switch ( V_5 -> V_64 ) {
case 0 :
break;
case 1 :
F_13 ( V_2 , V_55 ,
V_56 |
V_57 ,
V_56 |
V_57 ) ;
F_13 ( V_2 , V_65 ,
V_66 |
V_67 ,
V_66 |
V_67 ) ;
break;
default:
F_9 ( V_2 -> V_13 , L_9 ,
V_5 -> V_64 ) ;
break;
}
case V_68 :
F_13 ( V_2 , V_69 ,
V_70 , 0 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_60 * V_61 ,
struct V_49 * V_50 , int V_62 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
unsigned int V_6 = F_8 ( V_2 , V_65 ) ;
switch ( V_62 ) {
case V_71 :
F_13 ( V_2 , V_69 ,
V_70 , V_70 ) ;
F_7 ( 5 ) ;
F_13 ( V_2 , V_55 ,
V_56 | V_57 ,
V_56 | V_57 ) ;
V_6 |= V_66 | V_67 ;
F_3 ( V_2 , V_65 , V_6 ) ;
F_13 ( V_2 , V_32 ,
V_72 , 0 ) ;
F_12 ( V_2 ) ;
V_6 |= V_73 | V_74 |
V_75 | V_76 ;
F_3 ( V_2 , V_65 , V_6 ) ;
break;
case V_68 :
F_13 ( V_2 , V_65 ,
V_75 |
V_73 |
V_76 |
V_74 , 0 ) ;
F_13 ( V_2 , V_65 ,
V_66 |
V_67 , 0 ) ;
F_3 ( V_2 , V_12 , 0 ) ;
F_13 ( V_2 , V_55 ,
V_56 | V_57 ,
0 ) ;
break;
}
return 0 ;
}
static int F_20 ( struct V_60 * V_61 ,
struct V_49 * V_77 , int V_62 )
{
struct V_1 * V_2 = V_61 -> V_2 ;
T_3 V_6 = F_8 ( V_2 , V_78 ) & ~ V_79 ;
switch ( V_62 ) {
case V_63 :
V_6 |= V_79 ;
F_3 ( V_2 , V_78 , V_6 ) ;
F_21 ( 50 ) ;
break;
case V_80 :
F_3 ( V_2 , V_78 , V_6 ) ;
break;
default:
F_22 () ;
break;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 ;
F_13 ( V_2 , V_83 ,
V_84 , V_84 ) ;
F_13 ( V_2 , V_85 ,
V_84 , V_84 ) ;
F_13 ( V_2 , V_86 ,
V_87 , V_87 ) ;
F_13 ( V_2 , V_88 ,
V_87 , V_87 ) ;
F_13 ( V_2 , V_89 ,
V_90 , V_90 ) ;
F_13 ( V_2 , V_91 ,
V_90 , V_90 ) ;
F_13 ( V_2 , V_92 ,
V_93 | V_94 ,
V_93 | V_94 ) ;
F_13 ( V_2 , V_95 ,
V_93 | V_96 ,
V_93 | V_96 ) ;
F_13 ( V_2 , V_97 ,
V_98 | V_99 ,
V_98 | V_99 ) ;
F_13 ( V_2 , V_100 ,
V_101 | V_99 ,
V_101 | V_99 ) ;
F_24 ( V_2 , V_102 ,
F_25 ( V_102 ) ) ;
F_26 ( V_82 , V_103 ,
F_25 ( V_103 ) ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
int V_104 , int V_105 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_81 * V_82 = & V_2 -> V_82 ;
F_28 ( & V_5 -> V_15 ) ;
F_29 ( V_82 , V_106 ,
F_25 ( V_106 ) ) ;
if ( V_104 )
F_29 ( V_82 ,
V_107 ,
F_25 ( V_107 ) ) ;
else
F_29 ( V_82 ,
V_108 ,
F_25 ( V_108 ) ) ;
if ( V_105 )
F_29 ( V_82 ,
V_109 ,
F_25 ( V_109 ) ) ;
else
F_29 ( V_82 ,
V_110 ,
F_25 ( V_110 ) ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 ,
int V_104 , int V_105 ,
int V_111 , int V_112 ,
int V_113 , int V_114 , int V_115 ,
int V_116 )
{
if ( ! V_104 )
F_13 ( V_2 , V_117 ,
V_118 ,
V_118 ) ;
if ( ! V_105 )
F_13 ( V_2 , V_119 ,
V_120 ,
V_120 ) ;
if ( V_104 && V_105 )
V_2 -> V_82 . V_121 = 1 ;
if ( V_111 )
F_13 ( V_2 , V_122 ,
V_123 , V_123 ) ;
if ( V_112 )
F_13 ( V_2 , V_122 ,
V_124 , V_124 ) ;
F_13 ( V_2 , V_125 ,
V_126 | V_127 |
V_128 | V_129 ,
V_113 << V_130 |
V_114 << V_131 |
V_115 |
V_116 << V_132 ) ;
return 0 ;
}
