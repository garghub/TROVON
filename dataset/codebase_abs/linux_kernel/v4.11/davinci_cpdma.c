static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 )
return;
F_2 ( F_3 ( V_4 -> V_5 ) != F_4 ( V_4 -> V_5 ) ,
L_1 ,
F_3 ( V_4 -> V_5 ) ,
F_4 ( V_4 -> V_5 ) ) ;
if ( V_4 -> V_6 )
F_5 ( V_2 -> V_7 , V_4 -> V_8 , V_4 -> V_6 ,
V_4 -> V_9 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_10 * V_10 = & V_2 -> V_11 ;
struct V_3 * V_4 ;
int V_12 = - V_13 ;
V_4 = F_7 ( V_2 -> V_7 , sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
goto V_15;
V_2 -> V_4 = V_4 ;
V_4 -> V_8 = V_10 -> V_16 ;
V_4 -> V_17 = F_8 ( sizeof( struct V_18 ) ,
V_10 -> V_19 ) ;
V_4 -> V_20 = V_4 -> V_8 / V_4 -> V_17 ;
if ( V_10 -> V_21 ) {
V_4 -> V_20 = V_10 -> V_21 ;
V_4 -> V_8 = V_4 -> V_17 * V_4 -> V_20 ;
if ( V_4 -> V_8 > V_10 -> V_16 )
V_10 -> V_22 = 0 ;
}
V_4 -> V_5 = F_9 ( V_2 -> V_7 , F_10 ( V_4 -> V_17 ) ,
- 1 , L_2 ) ;
if ( F_11 ( V_4 -> V_5 ) ) {
V_12 = F_12 ( V_4 -> V_5 ) ;
F_13 ( V_2 -> V_7 , L_3 , V_12 ) ;
goto V_15;
}
if ( V_10 -> V_22 ) {
V_4 -> V_9 = V_10 -> V_22 ;
V_4 -> V_23 = F_14 ( V_2 -> V_7 , V_4 -> V_9 ,
V_4 -> V_8 ) ;
V_4 -> V_24 = V_10 -> V_25 ;
} else {
V_4 -> V_6 = F_15 ( V_2 -> V_7 , V_4 -> V_8 ,
& V_4 -> V_24 , V_14 ) ;
V_4 -> V_23 = ( void V_26 V_27 * ) V_4 -> V_6 ;
V_4 -> V_9 = V_4 -> V_24 ;
}
if ( ! V_4 -> V_23 )
goto V_15;
V_12 = F_16 ( V_4 -> V_5 , ( unsigned long ) V_4 -> V_23 ,
V_4 -> V_9 , V_4 -> V_8 , - 1 ) ;
if ( V_12 < 0 ) {
F_13 ( V_2 -> V_7 , L_4 , V_12 ) ;
goto V_28;
}
return 0 ;
V_28:
F_1 ( V_2 ) ;
V_15:
V_2 -> V_4 = NULL ;
return V_12 ;
}
static inline T_1 F_17 ( struct V_3 * V_4 ,
struct V_18 V_26 * V_29 )
{
if ( ! V_29 )
return 0 ;
return V_4 -> V_24 + ( V_27 long ) V_29 - ( V_27 long ) V_4 -> V_23 ;
}
static inline struct V_18 V_26 *
F_18 ( struct V_3 * V_4 , T_1 V_30 )
{
return V_30 ? V_4 -> V_23 + V_30 - V_4 -> V_24 : NULL ;
}
static struct V_18 V_26 *
F_19 ( struct V_3 * V_4 )
{
return (struct V_18 V_26 * )
F_20 ( V_4 -> V_5 , V_4 -> V_17 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_18 V_26 * V_29 , int V_20 )
{
F_22 ( V_4 -> V_5 , ( unsigned long ) V_29 , V_4 -> V_17 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_31 , int V_32 )
{
struct V_33 * V_34 = & V_35 [ V_31 ] ;
T_2 V_36 ;
if ( ! V_2 -> V_11 . V_37 )
return - V_38 ;
if ( V_2 -> V_39 != V_40 )
return - V_41 ;
if ( V_31 < 0 || V_31 >= F_24 ( V_35 ) )
return - V_42 ;
if ( ( V_34 -> V_43 & V_44 ) != V_44 )
return - V_45 ;
V_36 = F_25 ( V_2 , V_34 -> V_46 ) ;
V_36 &= ~ ( V_34 -> V_47 << V_34 -> V_48 ) ;
V_36 |= ( V_32 & V_34 -> V_47 ) << V_34 -> V_48 ;
F_26 ( V_2 , V_34 -> V_46 , V_36 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_31 )
{
struct V_33 * V_34 = & V_35 [ V_31 ] ;
int V_12 ;
if ( ! V_2 -> V_11 . V_37 )
return - V_38 ;
if ( V_2 -> V_39 != V_40 )
return - V_41 ;
if ( V_31 < 0 || V_31 >= F_24 ( V_35 ) )
return - V_42 ;
if ( ( V_34 -> V_43 & V_49 ) != V_49 )
return - V_45 ;
V_12 = ( F_25 ( V_2 , V_34 -> V_46 ) >> V_34 -> V_48 ) & V_34 -> V_47 ;
return V_12 ;
}
static int F_28 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
T_2 V_52 ;
T_2 V_53 ;
int V_12 ;
if ( ! V_51 -> V_54 )
return 0 ;
V_52 = V_55 + 4 * V_51 -> V_56 ;
F_26 ( V_2 , V_52 , V_51 -> V_57 ) ;
V_53 = F_27 ( V_2 , V_58 ) ;
V_53 |= V_51 -> V_47 ;
V_12 = F_23 ( V_2 , V_58 , V_53 ) ;
return V_12 ;
}
static int F_29 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_59 ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
if ( V_51 -> V_39 != V_61 ) {
F_31 ( & V_51 -> V_60 , V_59 ) ;
return - V_62 ;
}
if ( V_2 -> V_39 != V_40 ) {
F_31 ( & V_51 -> V_60 , V_59 ) ;
return - V_41 ;
}
F_26 ( V_2 , V_51 -> V_63 , V_51 -> V_47 ) ;
V_51 -> V_39 = V_40 ;
if ( V_51 -> V_64 ) {
F_32 ( V_51 , V_65 , F_17 ( V_4 , V_51 -> V_64 ) ) ;
if ( V_51 -> V_66 )
F_32 ( V_51 , V_66 , V_51 -> V_67 ) ;
}
F_31 ( & V_51 -> V_60 , V_59 ) ;
return 0 ;
}
static int F_33 ( struct V_50 * V_68 , T_2 V_54 ,
T_2 * V_53 , int * V_69 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_50 * V_51 ;
T_2 V_70 = V_68 -> V_54 ;
T_2 V_71 = 0 ;
int V_72 = 1 ;
int V_73 ;
* V_69 = 0 ;
for ( V_73 = F_34 ( 0 ) ; V_73 < F_34 ( V_74 ) ; V_73 ++ ) {
V_51 = V_2 -> V_75 [ V_73 ] ;
if ( ! V_51 ) {
V_72 = 0 ;
continue;
}
if ( V_51 == V_68 )
V_51 -> V_54 = V_54 ;
if ( V_51 -> V_54 ) {
if ( V_72 ) {
V_71 |= V_51 -> V_47 ;
} else {
V_68 -> V_54 = V_70 ;
F_13 ( V_2 -> V_7 , L_5 ,
V_51 -> V_56 ) ;
return - V_41 ;
}
} else {
* V_69 = 1 ;
V_72 = 0 ;
}
}
* V_53 = V_71 ;
return 0 ;
}
static T_2 F_35 ( struct V_1 * V_2 ,
struct V_50 * V_68 )
{
T_2 V_76 = V_77 , V_78 = V_77 , V_79 = V_77 ;
T_2 V_80 = 0 , V_81 = 0 ;
T_2 V_82 , V_83 = 0 , V_52 ;
T_3 V_84 , V_85 ;
T_2 V_86 , V_87 ;
T_3 V_88 , V_89 ;
if ( ! V_68 -> V_54 ) {
V_68 -> V_57 = 0 ;
goto V_90;
}
V_87 = V_2 -> V_11 . V_91 * 1000 * 32 ;
if ( ! V_87 ) {
F_13 ( V_2 -> V_7 , L_6 ) ;
return - V_41 ;
}
V_86 = V_87 - V_68 -> V_54 ;
V_84 = F_36 ( V_86 , V_68 -> V_54 ) ;
while ( V_84 <= V_92 ) {
V_88 = V_68 -> V_54 * V_84 ;
V_89 = V_86 ;
V_85 = F_37 ( V_88 , V_89 ) ;
V_88 = V_87 * V_85 ;
V_89 = V_85 + V_84 ;
V_82 = F_37 ( V_88 , V_89 ) ;
V_76 = V_82 >= V_68 -> V_54 ? V_82 - V_68 -> V_54 : V_76 ;
if ( V_76 < V_79 ) {
V_79 = V_76 ;
V_80 = V_84 ;
V_81 = V_85 ;
V_83 = V_82 ;
if ( ! V_76 )
break;
}
if ( V_78 >= V_76 ) {
V_78 = V_76 ;
V_84 ++ ;
continue;
}
V_85 ++ ;
V_88 = V_87 * V_85 ;
V_84 = F_37 ( V_88 , V_68 -> V_54 ) ;
V_84 -= V_85 ;
V_78 = V_77 ;
}
V_68 -> V_54 = V_83 ;
V_68 -> V_57 = V_80 | ( V_81 << 16 ) ;
V_90:
V_52 = V_55 + 4 * V_68 -> V_56 ;
F_26 ( V_2 , V_52 , V_68 -> V_57 ) ;
return 0 ;
}
struct V_1 * F_38 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( V_11 -> V_7 , sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_39 = V_61 ;
V_2 -> V_11 = * V_11 ;
V_2 -> V_7 = V_11 -> V_7 ;
V_2 -> V_56 = 0 ;
F_39 ( & V_2 -> V_60 ) ;
if ( F_6 ( V_2 ) )
return NULL ;
V_2 -> V_93 = V_2 -> V_4 -> V_20 / 2 ;
V_2 -> V_94 = V_2 -> V_4 -> V_20 - V_2 -> V_93 ;
if ( F_40 ( V_2 -> V_95 > V_74 ) )
V_2 -> V_95 = V_74 ;
return V_2 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
unsigned long V_59 ;
int V_73 , V_69 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
if ( V_2 -> V_39 != V_61 ) {
F_31 ( & V_2 -> V_60 , V_59 ) ;
return - V_62 ;
}
if ( V_2 -> V_11 . V_96 ) {
unsigned V_97 = 10 * 100 ;
F_26 ( V_2 , V_98 , 1 ) ;
while ( V_97 ) {
if ( F_25 ( V_2 , V_98 ) == 0 )
break;
F_42 ( 10 ) ;
V_97 -- ;
}
F_40 ( ! V_97 ) ;
}
for ( V_73 = 0 ; V_73 < V_2 -> V_95 ; V_73 ++ ) {
F_43 ( 0 , V_2 -> V_11 . V_99 + 4 * V_73 ) ;
F_43 ( 0 , V_2 -> V_11 . V_100 + 4 * V_73 ) ;
F_43 ( 0 , V_2 -> V_11 . V_101 + 4 * V_73 ) ;
F_43 ( 0 , V_2 -> V_11 . V_102 + 4 * V_73 ) ;
}
F_26 ( V_2 , V_103 , 0xffffffff ) ;
F_26 ( V_2 , V_104 , 0xffffffff ) ;
F_26 ( V_2 , V_105 , 1 ) ;
F_26 ( V_2 , V_106 , 1 ) ;
V_2 -> V_39 = V_40 ;
V_69 = 0 ;
for ( V_73 = 0 ; V_73 < F_24 ( V_2 -> V_75 ) ; V_73 ++ ) {
V_51 = V_2 -> V_75 [ V_73 ] ;
if ( V_51 ) {
F_28 ( V_51 ) ;
F_29 ( V_51 ) ;
if ( F_44 ( V_51 ) && ! V_51 -> V_54 )
V_69 = 1 ;
}
}
F_23 ( V_2 , V_107 , V_69 ) ;
F_23 ( V_2 , V_108 , 0 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
unsigned long V_59 ;
int V_73 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
if ( V_2 -> V_39 != V_40 ) {
F_31 ( & V_2 -> V_60 , V_59 ) ;
return - V_41 ;
}
V_2 -> V_39 = V_109 ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
for ( V_73 = 0 ; V_73 < F_24 ( V_2 -> V_75 ) ; V_73 ++ ) {
if ( V_2 -> V_75 [ V_73 ] )
F_46 ( V_2 -> V_75 [ V_73 ] ) ;
}
F_30 ( & V_2 -> V_60 , V_59 ) ;
F_26 ( V_2 , V_103 , 0xffffffff ) ;
F_26 ( V_2 , V_104 , 0xffffffff ) ;
F_26 ( V_2 , V_105 , 0 ) ;
F_26 ( V_2 , V_106 , 0 ) ;
V_2 -> V_39 = V_61 ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_12 = 0 , V_73 ;
if ( ! V_2 )
return - V_41 ;
if ( V_2 -> V_39 != V_61 )
F_45 ( V_2 ) ;
for ( V_73 = 0 ; V_73 < F_24 ( V_2 -> V_75 ) ; V_73 ++ )
F_48 ( V_2 -> V_75 [ V_73 ] ) ;
F_1 ( V_2 ) ;
return V_12 ;
}
int F_49 ( struct V_1 * V_2 , bool V_110 )
{
unsigned long V_59 ;
int V_73 , V_46 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
if ( V_2 -> V_39 != V_40 ) {
F_31 ( & V_2 -> V_60 , V_59 ) ;
return - V_41 ;
}
V_46 = V_110 ? V_111 : V_112 ;
F_26 ( V_2 , V_46 , V_113 ) ;
for ( V_73 = 0 ; V_73 < F_24 ( V_2 -> V_75 ) ; V_73 ++ ) {
if ( V_2 -> V_75 [ V_73 ] )
F_50 ( V_2 -> V_75 [ V_73 ] , V_110 ) ;
}
F_31 ( & V_2 -> V_60 , V_59 ) ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 , T_2 V_32 )
{
F_26 ( V_2 , V_114 , V_32 ) ;
}
T_2 F_52 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , V_115 ) ;
}
T_2 F_53 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , V_116 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
int V_117 , int V_118 ,
int V_119 )
{
struct V_50 * V_51 , * V_120 = NULL ;
int V_121 = V_118 ;
int V_122 = 0 ;
int V_123 , V_124 , V_73 ;
if ( ! V_118 )
return;
if ( V_117 ) {
V_123 = F_55 ( 0 ) ;
V_124 = F_55 ( V_74 ) ;
} else {
V_123 = F_34 ( 0 ) ;
V_124 = F_34 ( V_74 ) ;
}
for ( V_73 = V_123 ; V_73 < V_124 ; V_73 ++ ) {
V_51 = V_2 -> V_75 [ V_73 ] ;
if ( ! V_51 )
continue;
if ( V_51 -> V_125 )
V_51 -> V_118 = ( V_51 -> V_125 * V_118 ) / 100 ;
else
V_51 -> V_118 = V_119 ;
V_121 -= V_51 -> V_118 ;
if ( V_122 < V_51 -> V_118 ) {
V_122 = V_51 -> V_118 ;
V_120 = V_51 ;
}
}
if ( V_120 )
V_120 -> V_118 += V_121 ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_126 = 0 , V_127 = 0 ;
int V_128 = 0 , V_129 = 0 ;
int V_130 = 0 , V_131 = 0 ;
int V_132 , V_133 ;
struct V_50 * V_51 ;
int V_73 ;
if ( ! V_2 -> V_56 )
return 0 ;
for ( V_73 = 0 ; V_73 < F_24 ( V_2 -> V_75 ) ; V_73 ++ ) {
V_51 = V_2 -> V_75 [ V_73 ] ;
if ( ! V_51 )
continue;
if ( F_57 ( V_51 ) ) {
if ( ! V_51 -> V_125 )
V_128 ++ ;
V_130 += V_51 -> V_125 ;
} else {
if ( ! V_51 -> V_125 )
V_129 ++ ;
V_131 += V_51 -> V_125 ;
}
}
if ( V_130 > 100 || V_131 > 100 )
return - V_41 ;
V_132 = V_2 -> V_93 ;
V_133 = V_2 -> V_94 ;
if ( V_129 ) {
V_126 = V_132 - ( V_131 * V_132 ) / 100 ;
V_126 /= V_129 ;
}
if ( V_128 ) {
V_127 = V_133 - ( V_130 * V_133 ) / 100 ;
V_127 /= V_128 ;
}
F_54 ( V_2 , 0 , V_132 , V_126 ) ;
F_54 ( V_2 , 1 , V_133 , V_127 ) ;
return 0 ;
}
int F_58 ( struct V_50 * V_68 , int V_125 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
unsigned long V_59 , V_134 ;
int V_12 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
F_30 ( & V_68 -> V_60 , V_134 ) ;
if ( V_68 -> V_125 == V_125 ) {
F_31 ( & V_68 -> V_60 , V_134 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return 0 ;
}
V_68 -> V_125 = V_125 ;
F_31 ( & V_68 -> V_60 , V_134 ) ;
V_12 = F_56 ( V_2 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return V_12 ;
}
T_2 F_59 ( struct V_1 * V_2 )
{
unsigned int V_88 , V_89 ;
V_88 = V_2 -> V_11 . V_91 * 32 * 1000 ;
V_89 = 1 + V_92 ;
return F_36 ( V_88 , V_89 ) ;
}
int F_60 ( struct V_50 * V_68 , T_2 V_54 )
{
unsigned long V_59 , V_134 ;
struct V_1 * V_2 ;
int V_12 , V_69 ;
T_2 V_53 ;
if ( ! V_68 || ! F_44 ( V_68 ) )
return - V_41 ;
if ( V_68 -> V_54 == V_54 )
return V_54 ;
V_2 = V_68 -> V_2 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
F_30 ( & V_68 -> V_60 , V_134 ) ;
V_12 = F_33 ( V_68 , V_54 , & V_53 , & V_69 ) ;
if ( V_12 )
goto V_135;
V_12 = F_35 ( V_2 , V_68 ) ;
if ( V_12 )
goto V_135;
F_31 ( & V_68 -> V_60 , V_134 ) ;
F_23 ( V_2 , V_58 , V_53 ) ;
F_23 ( V_2 , V_107 , V_69 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return V_12 ;
V_135:
F_31 ( & V_68 -> V_60 , V_134 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return V_12 ;
}
T_2 F_61 ( struct V_50 * V_68 )
{
unsigned long V_59 ;
T_2 V_54 ;
F_30 ( & V_68 -> V_60 , V_59 ) ;
V_54 = V_68 -> V_54 ;
F_31 ( & V_68 -> V_60 , V_59 ) ;
return V_54 ;
}
struct V_50 * F_62 ( struct V_1 * V_2 , int V_56 ,
T_4 V_136 , int V_137 )
{
int V_138 = V_56 * 4 ;
struct V_50 * V_51 ;
unsigned long V_59 ;
V_56 = V_137 ? F_55 ( V_56 ) : F_34 ( V_56 ) ;
if ( F_63 ( V_56 ) >= V_2 -> V_95 )
return NULL ;
V_51 = F_7 ( V_2 -> V_7 , sizeof( * V_51 ) , V_14 ) ;
if ( ! V_51 )
return F_64 ( - V_13 ) ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
if ( V_2 -> V_75 [ V_56 ] ) {
F_31 ( & V_2 -> V_60 , V_59 ) ;
F_65 ( V_2 -> V_7 , V_51 ) ;
return F_64 ( - V_62 ) ;
}
V_51 -> V_2 = V_2 ;
V_51 -> V_39 = V_61 ;
V_51 -> V_56 = V_56 ;
V_51 -> V_136 = V_136 ;
V_51 -> V_54 = 0 ;
V_51 -> V_125 = 0 ;
if ( F_57 ( V_51 ) ) {
V_51 -> V_65 = V_2 -> V_11 . V_100 + V_138 ;
V_51 -> V_139 = V_2 -> V_11 . V_102 + V_138 ;
V_51 -> V_66 = V_2 -> V_11 . V_66 + V_138 ;
V_51 -> V_63 = V_140 ;
V_51 -> V_141 = V_103 ;
V_51 -> V_142 = V_143 ;
V_51 -> V_144 = V_145 ;
} else {
V_51 -> V_65 = V_2 -> V_11 . V_99 + V_138 ;
V_51 -> V_139 = V_2 -> V_11 . V_101 + V_138 ;
V_51 -> V_63 = V_146 ;
V_51 -> V_141 = V_104 ;
V_51 -> V_142 = V_147 ;
V_51 -> V_144 = V_148 ;
}
V_51 -> V_47 = F_66 ( F_67 ( V_51 ) ) ;
F_39 ( & V_51 -> V_60 ) ;
V_2 -> V_75 [ V_56 ] = V_51 ;
V_2 -> V_56 ++ ;
F_56 ( V_2 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return V_51 ;
}
int F_68 ( struct V_50 * V_51 )
{
unsigned long V_59 ;
int V_118 ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
V_118 = V_51 -> V_118 ;
F_31 ( & V_51 -> V_60 , V_59 ) ;
return V_118 ;
}
int F_48 ( struct V_50 * V_51 )
{
struct V_1 * V_2 ;
unsigned long V_59 ;
if ( ! V_51 )
return - V_41 ;
V_2 = V_51 -> V_2 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
if ( V_51 -> V_39 != V_61 )
F_46 ( V_51 ) ;
V_2 -> V_75 [ V_51 -> V_56 ] = NULL ;
V_2 -> V_56 -- ;
F_65 ( V_2 -> V_7 , V_51 ) ;
F_56 ( V_2 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return 0 ;
}
int F_69 ( struct V_50 * V_51 ,
struct V_149 * V_150 )
{
unsigned long V_59 ;
if ( ! V_51 )
return - V_41 ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
memcpy ( V_150 , & V_51 -> V_150 , sizeof( * V_150 ) ) ;
F_31 ( & V_51 -> V_60 , V_59 ) ;
return 0 ;
}
static void F_70 ( struct V_50 * V_51 ,
struct V_18 V_26 * V_29 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_18 V_26 * V_151 = V_51 -> V_152 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_153 ;
T_2 V_154 ;
V_153 = F_17 ( V_4 , V_29 ) ;
if ( ! V_51 -> V_64 ) {
V_51 -> V_150 . V_155 ++ ;
V_51 -> V_64 = V_29 ;
V_51 -> V_152 = V_29 ;
if ( V_51 -> V_39 == V_40 )
F_32 ( V_51 , V_65 , V_153 ) ;
return;
}
F_71 ( V_151 , V_156 , V_153 ) ;
V_51 -> V_152 = V_29 ;
V_51 -> V_150 . V_157 ++ ;
V_154 = F_72 ( V_151 , V_158 ) ;
if ( ( ( V_154 & ( V_159 | V_160 ) ) == V_159 ) &&
( V_51 -> V_39 == V_40 ) ) {
F_71 ( V_151 , V_158 , V_154 & ~ V_159 ) ;
F_32 ( V_51 , V_65 , V_153 ) ;
V_51 -> V_150 . V_161 ++ ;
}
}
int F_73 ( struct V_50 * V_51 , void * V_162 , void * V_163 ,
int V_164 , int V_165 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_18 V_26 * V_29 ;
T_1 V_166 ;
unsigned long V_59 ;
T_2 V_154 ;
int V_12 = 0 ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
if ( V_51 -> V_39 == V_109 ) {
V_12 = - V_41 ;
goto V_167;
}
if ( V_51 -> V_67 >= V_51 -> V_118 ) {
V_51 -> V_150 . V_168 ++ ;
V_12 = - V_13 ;
goto V_167;
}
V_29 = F_19 ( V_2 -> V_4 ) ;
if ( ! V_29 ) {
V_51 -> V_150 . V_168 ++ ;
V_12 = - V_13 ;
goto V_167;
}
if ( V_164 < V_2 -> V_11 . V_169 ) {
V_164 = V_2 -> V_11 . V_169 ;
V_51 -> V_150 . V_170 ++ ;
}
V_166 = F_74 ( V_2 -> V_7 , V_163 , V_164 , V_51 -> V_144 ) ;
V_12 = F_75 ( V_2 -> V_7 , V_166 ) ;
if ( V_12 ) {
F_21 ( V_2 -> V_4 , V_29 , 1 ) ;
V_12 = - V_41 ;
goto V_167;
}
V_154 = V_160 | V_171 | V_172 ;
F_76 ( V_51 , V_154 , V_165 ) ;
F_77 ( 0 , & V_29 -> V_156 ) ;
F_77 ( V_166 , & V_29 -> V_173 ) ;
F_77 ( V_164 , & V_29 -> V_174 ) ;
F_77 ( V_154 | V_164 , & V_29 -> V_158 ) ;
F_77 ( V_162 , & V_29 -> V_175 ) ;
F_77 ( V_166 , & V_29 -> V_176 ) ;
F_77 ( V_164 , & V_29 -> V_177 ) ;
F_72 ( V_29 , V_177 ) ;
F_70 ( V_51 , V_29 ) ;
if ( V_51 -> V_39 == V_40 && V_51 -> V_66 )
F_32 ( V_51 , V_66 , 1 ) ;
V_51 -> V_67 ++ ;
V_167:
F_31 ( & V_51 -> V_60 , V_59 ) ;
return V_12 ;
}
bool F_78 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_178 ;
unsigned long V_59 ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
V_178 = ( V_51 -> V_67 < V_51 -> V_118 ) &&
F_4 ( V_4 -> V_5 ) ;
F_31 ( & V_51 -> V_60 , V_59 ) ;
return V_178 ;
}
static void F_79 ( struct V_50 * V_51 ,
struct V_18 V_26 * V_29 ,
int V_179 , int V_180 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_181 ;
int V_182 ;
void * V_162 ;
V_162 = ( void * ) F_72 ( V_29 , V_175 ) ;
V_181 = F_72 ( V_29 , V_176 ) ;
V_182 = F_72 ( V_29 , V_177 ) ;
F_80 ( V_2 -> V_7 , V_181 , V_182 , V_51 -> V_144 ) ;
F_21 ( V_4 , V_29 , 1 ) ;
(* V_51 -> V_136 )( V_162 , V_179 , V_180 ) ;
}
static int F_81 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_18 V_26 * V_29 ;
int V_180 , V_179 ;
int V_183 = 0 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_153 ;
unsigned long V_59 ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
V_29 = V_51 -> V_64 ;
if ( ! V_29 ) {
V_51 -> V_150 . V_184 ++ ;
V_180 = - V_42 ;
goto V_167;
}
V_153 = F_17 ( V_4 , V_29 ) ;
V_180 = F_72 ( V_29 , V_158 ) ;
V_179 = V_180 & 0x7ff ;
if ( V_180 & V_160 ) {
V_51 -> V_150 . V_185 ++ ;
V_180 = - V_62 ;
goto V_167;
}
if ( V_180 & V_186 )
V_179 -= V_187 ;
V_180 = V_180 & ( V_159 | V_188 |
V_189 ) ;
V_51 -> V_64 = F_18 ( V_4 , F_72 ( V_29 , V_156 ) ) ;
F_32 ( V_51 , V_139 , V_153 ) ;
V_51 -> V_67 -- ;
V_51 -> V_150 . V_190 ++ ;
if ( ( V_180 & V_159 ) && V_51 -> V_64 ) {
V_51 -> V_150 . V_191 ++ ;
F_32 ( V_51 , V_65 , F_17 ( V_4 , V_51 -> V_64 ) ) ;
}
F_31 ( & V_51 -> V_60 , V_59 ) ;
if ( F_82 ( V_180 & V_188 ) )
V_183 = - V_192 ;
else
V_183 = V_180 ;
F_79 ( V_51 , V_29 , V_179 , V_183 ) ;
return V_180 ;
V_167:
F_31 ( & V_51 -> V_60 , V_59 ) ;
return V_180 ;
}
int F_83 ( struct V_50 * V_51 , int V_193 )
{
int V_194 = 0 , V_12 = 0 ;
if ( V_51 -> V_39 != V_40 )
return - V_41 ;
while ( V_194 < V_193 ) {
V_12 = F_81 ( V_51 ) ;
if ( V_12 < 0 )
break;
V_194 ++ ;
}
return V_194 ;
}
int F_84 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
unsigned long V_59 ;
int V_12 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
V_12 = F_28 ( V_51 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_29 ( V_51 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
int F_46 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_59 ;
int V_12 ;
unsigned V_97 ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
if ( V_51 -> V_39 == V_109 ) {
F_31 ( & V_51 -> V_60 , V_59 ) ;
return - V_41 ;
}
V_51 -> V_39 = V_109 ;
F_26 ( V_2 , V_51 -> V_141 , V_51 -> V_47 ) ;
F_26 ( V_2 , V_51 -> V_142 , F_67 ( V_51 ) ) ;
V_97 = 100 * 100 ;
while ( V_97 ) {
T_2 V_139 = F_85 ( V_51 , V_139 ) ;
if ( ( V_139 & V_195 ) == V_195 )
break;
F_42 ( 10 ) ;
V_97 -- ;
}
F_40 ( ! V_97 ) ;
F_32 ( V_51 , V_139 , V_195 ) ;
F_31 ( & V_51 -> V_60 , V_59 ) ;
do {
V_12 = F_81 ( V_51 ) ;
if ( V_12 < 0 )
break;
} while ( ( V_12 & V_188 ) == 0 );
F_30 ( & V_51 -> V_60 , V_59 ) ;
while ( V_51 -> V_64 ) {
struct V_18 V_26 * V_29 = V_51 -> V_64 ;
T_1 V_196 ;
V_196 = F_72 ( V_29 , V_156 ) ;
V_51 -> V_64 = F_18 ( V_4 , V_196 ) ;
V_51 -> V_67 -- ;
V_51 -> V_150 . V_197 ++ ;
F_31 ( & V_51 -> V_60 , V_59 ) ;
F_79 ( V_51 , V_29 , 0 , - V_192 ) ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
}
V_51 -> V_39 = V_61 ;
F_31 ( & V_51 -> V_60 , V_59 ) ;
return 0 ;
}
int F_50 ( struct V_50 * V_51 , bool V_110 )
{
unsigned long V_59 ;
F_30 ( & V_51 -> V_60 , V_59 ) ;
if ( V_51 -> V_39 != V_40 ) {
F_31 ( & V_51 -> V_60 , V_59 ) ;
return - V_41 ;
}
F_26 ( V_51 -> V_2 , V_110 ? V_51 -> V_63 : V_51 -> V_141 ,
V_51 -> V_47 ) ;
F_31 ( & V_51 -> V_60 , V_59 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 , int V_31 )
{
unsigned long V_59 ;
int V_12 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
V_12 = F_27 ( V_2 , V_31 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return V_12 ;
}
int F_87 ( struct V_1 * V_2 , int V_31 , int V_32 )
{
unsigned long V_59 ;
int V_12 ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
V_12 = F_23 ( V_2 , V_31 , V_32 ) ;
F_31 ( & V_2 -> V_60 , V_59 ) ;
return V_12 ;
}
int F_88 ( struct V_1 * V_2 )
{
return V_2 -> V_94 ;
}
int F_89 ( struct V_1 * V_2 )
{
return V_2 -> V_93 ;
}
void F_90 ( struct V_1 * V_2 , int V_94 )
{
V_2 -> V_94 = V_94 ;
V_2 -> V_93 = V_2 -> V_4 -> V_20 - V_2 -> V_94 ;
}
