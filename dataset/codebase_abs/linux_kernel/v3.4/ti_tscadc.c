static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_5 , unsigned int V_3 ,
unsigned int V_6 )
{
F_4 ( V_6 , V_5 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_7 )
{
unsigned int V_8 ;
int V_9 ;
V_8 = V_10 |
V_11 | V_12 ;
switch ( V_7 -> V_13 ) {
case 4 :
V_8 |= V_14 | V_15 ;
break;
case 5 :
V_8 |= V_16 |
V_17 | V_15 |
V_18 ;
break;
case 8 :
V_8 |= V_14 | V_15 ;
break;
}
for ( V_9 = 1 ; V_9 < 7 ; V_9 ++ ) {
F_3 ( V_7 , F_6 ( V_9 ) , V_8 ) ;
F_3 ( V_7 , F_7 ( V_9 ) , V_19 ) ;
}
V_8 = 0 ;
V_8 = V_10 |
V_11 | V_16 |
V_20 | V_21 ;
switch ( V_7 -> V_13 ) {
case 4 :
V_8 |= V_18 ;
break;
case 5 :
V_8 |= V_12 | V_17 |
V_22 | V_23 ;
break;
case 8 :
V_8 |= V_18 ;
break;
}
for ( V_9 = 7 ; V_9 < 13 ; V_9 ++ ) {
F_3 ( V_7 , F_6 ( V_9 ) , V_8 ) ;
F_3 ( V_7 , F_7 ( V_9 ) , V_19 ) ;
}
V_8 = 0 ;
V_8 = V_12 | V_16 |
V_24 | V_25 |
V_26 | V_27 ;
F_3 ( V_7 , V_28 , V_8 ) ;
F_3 ( V_7 , V_29 , V_30 ) ;
V_8 = 0 ;
V_8 = V_10 |
V_11 | V_18 |
V_15 | V_20 ;
F_3 ( V_7 , V_31 , V_8 ) ;
F_3 ( V_7 , V_32 , V_19 ) ;
V_8 |= V_33 | V_21 ;
F_3 ( V_7 , V_34 , V_8 ) ;
F_3 ( V_7 , V_35 , V_19 ) ;
F_3 ( V_7 , V_36 , V_37 ) ;
}
static void F_8 ( struct V_1 * V_38 )
{
unsigned int V_39 ;
V_39 = V_16 |
V_20 |
V_23 | V_40 ;
F_3 ( V_38 , V_41 , V_39 ) ;
}
static void F_9 ( struct V_1 * V_7 ,
unsigned int * V_42 , unsigned int * V_43 )
{
unsigned int V_44 = F_1 ( V_7 , V_45 ) ;
unsigned int V_46 = ~ 0 , V_47 = ~ 0 ;
unsigned int V_48 = ~ 0 , V_49 = ~ 0 ;
unsigned int V_50 , V_51 ;
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_44 - 1 ; V_9 ++ ) {
V_50 = F_1 ( V_7 , V_52 ) & 0xfff ;
V_51 = abs ( V_50 - V_46 ) ;
if ( V_51 < V_48 ) {
V_48 = V_51 ;
* V_42 = V_50 ;
}
V_46 = V_50 ;
V_50 = F_1 ( V_7 , V_53 ) & 0xfff ;
V_51 = abs ( V_50 - V_47 ) ;
if ( V_51 < V_49 ) {
V_49 = V_51 ;
* V_43 = V_50 ;
}
V_47 = V_50 ;
}
}
static T_1 F_10 ( int V_54 , void * V_55 )
{
struct V_1 * V_7 = V_55 ;
struct V_56 * V_56 = V_7 -> V_57 ;
unsigned int V_58 , V_59 = 0 ;
unsigned int V_42 = 0 , V_43 = 0 ;
unsigned int V_60 , V_61 , V_62 ;
unsigned int V_63 ;
V_58 = F_1 ( V_7 , V_64 ) ;
if ( V_58 & V_65 ) {
F_9 ( V_7 , & V_42 , & V_43 ) ;
V_60 = F_1 ( V_7 , V_52 ) & 0xfff ;
V_61 = F_1 ( V_7 , V_53 ) & 0xfff ;
if ( V_7 -> V_66 && V_60 != 0 && V_61 != 0 ) {
V_62 = V_61 - V_60 ;
V_62 *= V_42 ;
V_62 *= V_7 -> V_67 ;
V_62 /= V_60 ;
V_62 = ( V_62 + 2047 ) >> 12 ;
if ( V_62 <= V_68 ) {
F_11 ( V_56 , V_69 , V_42 ) ;
F_11 ( V_56 , V_70 , V_43 ) ;
F_11 ( V_56 , V_71 , V_62 ) ;
F_12 ( V_56 , V_72 , 1 ) ;
F_13 ( V_56 ) ;
}
}
V_59 |= V_65 ;
}
F_14 ( V_73 ) ;
V_58 = F_1 ( V_7 , V_74 ) ;
if ( V_58 & V_75 ) {
V_63 = F_1 ( V_7 , V_76 ) ;
if ( V_63 == V_77 ) {
V_7 -> V_66 = false ;
F_12 ( V_56 , V_72 , 0 ) ;
F_11 ( V_56 , V_71 , 0 ) ;
F_13 ( V_56 ) ;
} else {
V_7 -> V_66 = true ;
}
V_59 |= V_75 ;
}
F_3 ( V_7 , V_64 , V_59 ) ;
F_3 ( V_7 , V_78 , 0x0 ) ;
F_3 ( V_7 , V_36 , V_37 ) ;
return V_79 ;
}
static int T_2 F_15 ( struct V_80 * V_81 )
{
const struct V_82 * V_83 = V_81 -> V_55 . V_84 ;
struct V_85 * V_86 ;
struct V_1 * V_7 ;
struct V_56 * V_56 ;
struct V_87 * V_87 ;
int V_88 ;
int V_89 , V_90 , V_54 ;
if ( ! V_83 ) {
F_16 ( & V_81 -> V_55 , L_1 ) ;
return - V_91 ;
}
V_86 = F_17 ( V_81 , V_92 , 0 ) ;
if ( ! V_86 ) {
F_16 ( & V_81 -> V_55 , L_2 ) ;
return - V_91 ;
}
V_54 = F_18 ( V_81 , 0 ) ;
if ( V_54 < 0 ) {
F_16 ( & V_81 -> V_55 , L_3 ) ;
return - V_91 ;
}
V_7 = F_19 ( sizeof( struct V_1 ) , V_93 ) ;
V_56 = F_20 () ;
if ( ! V_7 || ! V_56 ) {
F_16 ( & V_81 -> V_55 , L_4 ) ;
V_88 = - V_94 ;
goto V_95;
}
V_7 -> V_57 = V_56 ;
V_7 -> V_54 = V_54 ;
V_7 -> V_13 = V_83 -> V_13 ;
V_7 -> V_67 = V_83 -> V_67 ;
V_86 = F_21 ( V_86 -> V_96 , F_22 ( V_86 ) , V_81 -> V_97 ) ;
if ( ! V_86 ) {
F_16 ( & V_81 -> V_55 , L_5 ) ;
V_88 = - V_98 ;
goto V_95;
}
V_7 -> V_4 = F_23 ( V_86 -> V_96 , F_22 ( V_86 ) ) ;
if ( ! V_7 -> V_4 ) {
F_16 ( & V_81 -> V_55 , L_6 ) ;
V_88 = - V_94 ;
goto V_99;
}
V_88 = F_24 ( V_7 -> V_54 , F_10 ,
0 , V_81 -> V_55 . V_100 -> V_97 , V_7 ) ;
if ( V_88 ) {
F_16 ( & V_81 -> V_55 , L_7 ) ;
goto V_101;
}
V_7 -> V_102 = F_25 ( & V_81 -> V_55 , L_8 ) ;
if ( F_26 ( V_7 -> V_102 ) ) {
F_16 ( & V_81 -> V_55 , L_9 ) ;
goto V_103;
}
F_27 ( V_7 -> V_102 ) ;
V_87 = F_25 ( & V_81 -> V_55 , L_10 ) ;
if ( F_26 ( V_87 ) ) {
F_16 ( & V_81 -> V_55 , L_11 ) ;
V_88 = F_28 ( V_87 ) ;
goto V_104;
}
V_89 = F_29 ( V_87 ) / V_105 ;
F_30 ( V_87 ) ;
if ( V_89 < 7 ) {
F_16 ( & V_81 -> V_55 , L_12 ) ;
goto V_104;
}
F_3 ( V_7 , V_106 , V_89 - 1 ) ;
F_3 ( V_7 , V_107 , V_108 ) ;
V_90 = V_109 |
V_110 |
V_111 ;
switch ( V_7 -> V_13 ) {
case 4 :
V_90 |= V_112 ;
break;
case 5 :
V_90 |= V_113 ;
break;
case 8 :
V_90 |= V_114 ;
break;
}
F_3 ( V_7 , V_115 , V_90 ) ;
F_8 ( V_7 ) ;
F_3 ( V_7 , V_116 , V_65 ) ;
F_5 ( V_7 ) ;
F_3 ( V_7 , V_117 , 6 ) ;
V_90 |= V_118 ;
F_3 ( V_7 , V_115 , V_90 ) ;
V_56 -> V_97 = L_13 ;
V_56 -> V_55 . V_119 = & V_81 -> V_55 ;
V_56 -> V_120 [ 0 ] = F_31 ( V_121 ) | F_31 ( V_122 ) ;
V_56 -> V_123 [ F_32 ( V_72 ) ] = F_31 ( V_72 ) ;
F_33 ( V_56 , V_69 , 0 , V_68 , 0 , 0 ) ;
F_33 ( V_56 , V_70 , 0 , V_68 , 0 , 0 ) ;
F_33 ( V_56 , V_71 , 0 , V_68 , 0 , 0 ) ;
V_88 = F_34 ( V_56 ) ;
if ( V_88 )
goto V_104;
F_35 ( V_81 , V_7 ) ;
return 0 ;
V_104:
F_36 ( V_7 -> V_102 ) ;
F_30 ( V_7 -> V_102 ) ;
V_103:
F_37 ( V_7 -> V_54 , V_7 ) ;
V_101:
F_38 ( V_7 -> V_4 ) ;
V_99:
F_39 ( V_86 -> V_96 , F_22 ( V_86 ) ) ;
V_95:
F_40 ( V_56 ) ;
F_41 ( V_7 ) ;
return V_88 ;
}
static int T_3 F_42 ( struct V_80 * V_81 )
{
struct V_1 * V_7 = F_43 ( V_81 ) ;
struct V_85 * V_86 ;
F_37 ( V_7 -> V_54 , V_7 ) ;
F_44 ( V_7 -> V_57 ) ;
V_86 = F_17 ( V_81 , V_92 , 0 ) ;
F_38 ( V_7 -> V_4 ) ;
F_39 ( V_86 -> V_96 , F_22 ( V_86 ) ) ;
F_36 ( V_7 -> V_102 ) ;
F_30 ( V_7 -> V_102 ) ;
F_41 ( V_7 ) ;
F_35 ( V_81 , NULL ) ;
return 0 ;
}
