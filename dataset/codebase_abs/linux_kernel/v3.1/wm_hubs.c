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
T_3 V_6 , V_20 , V_21 , V_22 ;
if ( V_5 -> V_23 && V_5 -> V_24 ) {
F_4 ( V_2 -> V_13 , L_4 ,
V_5 -> V_24 ) ;
F_3 ( V_2 , V_25 , V_5 -> V_24 ) ;
F_1 ( V_2 ,
V_26 |
V_27 ) ;
return;
}
if ( V_5 -> V_28 ) {
F_13 ( V_2 , V_29 ,
V_30 ,
32 << V_31 ) ;
F_1 ( V_2 ,
V_32 |
V_33 ) ;
} else {
F_1 ( V_2 ,
V_34 |
V_35 ) ;
}
switch ( V_5 -> V_36 ) {
case 0 :
V_20 = F_8 ( V_2 , V_37 )
& V_38 ;
V_21 = F_8 ( V_2 , V_39 )
& V_40 ;
break;
case 1 :
V_6 = F_8 ( V_2 , V_25 ) ;
V_21 = ( V_6 & V_41 )
>> V_42 ;
V_20 = V_6 & V_43 ;
break;
default:
F_14 ( 1 , L_5 ) ;
break;
}
F_4 ( V_2 -> V_13 , L_6 , V_20 , V_21 ) ;
if ( V_5 -> V_44 ) {
F_4 ( V_2 -> V_13 , L_7 ,
V_5 -> V_44 ) ;
V_19 = V_21 ;
V_19 += V_5 -> V_44 ;
V_22 = ( V_45 ) V_19 << V_42 ;
V_19 = V_20 ;
V_19 += V_5 -> V_44 ;
V_22 |= ( V_45 ) V_19 ;
F_4 ( V_2 -> V_13 , L_8 , V_22 ) ;
F_3 ( V_2 , V_25 , V_22 ) ;
F_1 ( V_2 ,
V_26 |
V_27 ) ;
} else {
V_22 = V_21 << V_42 ;
V_22 |= V_20 ;
}
if ( V_5 -> V_23 )
V_5 -> V_24 = V_22 ;
}
static int F_15 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_16 ( V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_50 ;
V_50 = F_17 ( V_47 , V_49 ) ;
V_5 -> V_24 = 0 ;
if ( V_5 -> V_44 || V_5 -> V_51 )
return V_50 ;
if ( F_8 ( V_2 , V_52 )
& ( V_53 | V_54 ) )
F_13 ( V_2 ,
V_12 ,
V_55 |
V_56 ,
V_55 |
V_56 ) ;
return V_50 ;
}
static int F_18 ( struct V_57 * V_58 ,
struct V_46 * V_47 , int V_59 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_59 ) {
case V_60 :
switch ( V_5 -> V_61 ) {
case 0 :
break;
case 1 :
F_13 ( V_2 , V_52 ,
V_53 |
V_54 ,
V_53 |
V_54 ) ;
F_13 ( V_2 , V_62 ,
V_63 |
V_64 ,
V_63 |
V_64 ) ;
break;
default:
F_9 ( V_2 -> V_13 , L_9 ,
V_5 -> V_61 ) ;
break;
}
case V_65 :
F_13 ( V_2 , V_66 ,
V_67 , 0 ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_57 * V_58 ,
struct V_46 * V_47 , int V_59 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
unsigned int V_6 = F_8 ( V_2 , V_62 ) ;
switch ( V_59 ) {
case V_68 :
F_13 ( V_2 , V_66 ,
V_67 , V_67 ) ;
F_7 ( 5 ) ;
F_13 ( V_2 , V_52 ,
V_53 | V_54 ,
V_53 | V_54 ) ;
V_6 |= V_63 | V_64 ;
F_3 ( V_2 , V_62 , V_6 ) ;
F_13 ( V_2 , V_29 ,
V_69 , 0 ) ;
F_12 ( V_2 ) ;
V_6 |= V_70 | V_71 |
V_72 | V_73 ;
F_3 ( V_2 , V_62 , V_6 ) ;
break;
case V_65 :
F_13 ( V_2 , V_62 ,
V_72 |
V_70 |
V_73 |
V_71 , 0 ) ;
F_13 ( V_2 , V_62 ,
V_63 |
V_64 , 0 ) ;
F_3 ( V_2 , V_12 , 0 ) ;
F_13 ( V_2 , V_52 ,
V_53 | V_54 ,
0 ) ;
break;
}
return 0 ;
}
static int F_20 ( struct V_57 * V_58 ,
struct V_46 * V_74 , int V_59 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
T_3 V_6 = F_8 ( V_2 , V_75 ) & ~ V_76 ;
switch ( V_59 ) {
case V_60 :
V_6 |= V_76 ;
F_3 ( V_2 , V_75 , V_6 ) ;
F_21 ( 50 ) ;
break;
case V_77 :
F_3 ( V_2 , V_75 , V_6 ) ;
break;
default:
F_22 () ;
break;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = & V_2 -> V_79 ;
F_13 ( V_2 , V_80 ,
V_81 , V_81 ) ;
F_13 ( V_2 , V_82 ,
V_81 , V_81 ) ;
F_13 ( V_2 , V_83 ,
V_84 , V_84 ) ;
F_13 ( V_2 , V_85 ,
V_84 , V_84 ) ;
F_13 ( V_2 , V_86 ,
V_87 , V_87 ) ;
F_13 ( V_2 , V_88 ,
V_87 , V_87 ) ;
F_13 ( V_2 , V_89 ,
V_90 | V_91 ,
V_90 | V_91 ) ;
F_13 ( V_2 , V_92 ,
V_90 | V_93 ,
V_90 | V_93 ) ;
F_13 ( V_2 , V_94 ,
V_95 | V_96 ,
V_95 | V_96 ) ;
F_13 ( V_2 , V_97 ,
V_98 | V_96 ,
V_98 | V_96 ) ;
F_24 ( V_2 , V_99 ,
F_25 ( V_99 ) ) ;
F_26 ( V_79 , V_100 ,
F_25 ( V_100 ) ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
int V_101 , int V_102 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_78 * V_79 = & V_2 -> V_79 ;
F_28 ( & V_5 -> V_15 ) ;
F_29 ( V_79 , V_103 ,
F_25 ( V_103 ) ) ;
if ( V_101 )
F_29 ( V_79 ,
V_104 ,
F_25 ( V_104 ) ) ;
else
F_29 ( V_79 ,
V_105 ,
F_25 ( V_105 ) ) ;
if ( V_102 )
F_29 ( V_79 ,
V_106 ,
F_25 ( V_106 ) ) ;
else
F_29 ( V_79 ,
V_107 ,
F_25 ( V_107 ) ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 ,
int V_101 , int V_102 ,
int V_108 , int V_109 ,
int V_110 , int V_111 , int V_112 ,
int V_113 )
{
if ( ! V_101 )
F_13 ( V_2 , V_114 ,
V_115 ,
V_115 ) ;
if ( ! V_102 )
F_13 ( V_2 , V_116 ,
V_117 ,
V_117 ) ;
if ( V_101 && V_102 )
V_2 -> V_79 . V_118 = 1 ;
if ( V_108 )
F_13 ( V_2 , V_119 ,
V_120 , V_120 ) ;
if ( V_109 )
F_13 ( V_2 , V_119 ,
V_121 , V_121 ) ;
F_13 ( V_2 , V_122 ,
V_123 | V_124 |
V_125 | V_126 ,
V_110 << V_127 |
V_111 << V_128 |
V_112 |
V_113 << V_129 ) ;
return 0 ;
}
