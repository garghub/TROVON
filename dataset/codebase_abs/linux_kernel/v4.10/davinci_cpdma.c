static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_2 ( F_3 ( V_2 -> V_3 ) != F_4 ( V_2 -> V_3 ) ,
L_1 ,
F_3 ( V_2 -> V_3 ) ,
F_4 ( V_2 -> V_3 ) ) ;
if ( V_2 -> V_4 )
F_5 ( V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_4 ,
V_2 -> V_7 ) ;
else
F_6 ( V_2 -> V_8 ) ;
}
static struct V_1 *
F_7 ( struct V_9 * V_5 , T_1 V_7 , T_2 V_10 ,
int V_11 , int V_12 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_8 ( V_5 , sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
goto V_15;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_11 ;
V_2 -> V_16 = F_9 ( sizeof( struct V_17 ) , V_12 ) ;
V_2 -> V_18 = V_11 / V_2 -> V_16 ;
V_2 -> V_3 = F_10 ( V_5 , F_11 ( V_2 -> V_16 ) , - 1 ,
L_2 ) ;
if ( F_12 ( V_2 -> V_3 ) ) {
F_13 ( V_5 , L_3 ,
F_14 ( V_2 -> V_3 ) ) ;
goto V_15;
}
if ( V_7 ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = F_15 ( V_7 , V_11 ) ;
V_2 -> V_10 = V_10 ;
} else {
V_2 -> V_4 = F_16 ( V_5 , V_11 , & V_2 -> V_10 ,
V_14 ) ;
V_2 -> V_8 = ( void V_19 V_20 * ) V_2 -> V_4 ;
V_2 -> V_7 = V_2 -> V_10 ;
}
if ( ! V_2 -> V_8 )
goto V_15;
V_13 = F_17 ( V_2 -> V_3 , ( unsigned long ) V_2 -> V_8 ,
V_2 -> V_7 , V_2 -> V_6 , - 1 ) ;
if ( V_13 < 0 ) {
F_13 ( V_5 , L_4 , V_13 ) ;
goto V_21;
}
return V_2 ;
V_21:
F_1 ( V_2 ) ;
V_15:
return NULL ;
}
static inline T_2 F_18 ( struct V_1 * V_2 ,
struct V_17 V_19 * V_22 )
{
if ( ! V_22 )
return 0 ;
return V_2 -> V_10 + ( V_20 long ) V_22 - ( V_20 long ) V_2 -> V_8 ;
}
static inline struct V_17 V_19 *
F_19 ( struct V_1 * V_2 , T_2 V_23 )
{
return V_23 ? V_2 -> V_8 + V_23 - V_2 -> V_10 : NULL ;
}
static struct V_17 V_19 *
F_20 ( struct V_1 * V_2 )
{
return (struct V_17 V_19 * )
F_21 ( V_2 -> V_3 , V_2 -> V_16 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_17 V_19 * V_22 , int V_18 )
{
F_23 ( V_2 -> V_3 , ( unsigned long ) V_22 , V_2 -> V_16 ) ;
}
static int F_24 ( struct V_24 * V_25 , int V_26 , int V_27 )
{
struct V_28 * V_29 = & V_30 [ V_26 ] ;
T_1 V_31 ;
if ( ! V_25 -> V_32 . V_33 )
return - V_34 ;
if ( V_25 -> V_35 != V_36 )
return - V_37 ;
if ( V_26 < 0 || V_26 >= F_25 ( V_30 ) )
return - V_38 ;
if ( ( V_29 -> V_39 & V_40 ) != V_40 )
return - V_41 ;
V_31 = F_26 ( V_25 , V_29 -> V_42 ) ;
V_31 &= ~ ( V_29 -> V_43 << V_29 -> V_44 ) ;
V_31 |= ( V_27 & V_29 -> V_43 ) << V_29 -> V_44 ;
F_27 ( V_25 , V_29 -> V_42 , V_31 ) ;
return 0 ;
}
static int F_28 ( struct V_24 * V_25 , int V_26 )
{
struct V_28 * V_29 = & V_30 [ V_26 ] ;
int V_13 ;
if ( ! V_25 -> V_32 . V_33 )
return - V_34 ;
if ( V_25 -> V_35 != V_36 )
return - V_37 ;
if ( V_26 < 0 || V_26 >= F_25 ( V_30 ) )
return - V_38 ;
if ( ( V_29 -> V_39 & V_45 ) != V_45 )
return - V_41 ;
V_13 = ( F_26 ( V_25 , V_29 -> V_42 ) >> V_29 -> V_44 ) & V_29 -> V_43 ;
return V_13 ;
}
static int F_29 ( struct V_46 * V_47 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
T_1 V_48 ;
T_1 V_49 ;
int V_13 ;
if ( ! V_47 -> V_50 )
return 0 ;
V_48 = V_51 + 4 * V_47 -> V_52 ;
F_27 ( V_25 , V_48 , V_47 -> V_53 ) ;
V_49 = F_28 ( V_25 , V_54 ) ;
V_49 |= V_47 -> V_43 ;
V_13 = F_24 ( V_25 , V_54 , V_49 ) ;
return V_13 ;
}
static int F_30 ( struct V_46 * V_47 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
struct V_1 * V_2 = V_25 -> V_2 ;
unsigned long V_55 ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
if ( V_47 -> V_35 != V_57 ) {
F_32 ( & V_47 -> V_56 , V_55 ) ;
return - V_58 ;
}
if ( V_25 -> V_35 != V_36 ) {
F_32 ( & V_47 -> V_56 , V_55 ) ;
return - V_37 ;
}
F_27 ( V_25 , V_47 -> V_59 , V_47 -> V_43 ) ;
V_47 -> V_35 = V_36 ;
if ( V_47 -> V_60 ) {
F_33 ( V_47 , V_61 , F_18 ( V_2 , V_47 -> V_60 ) ) ;
if ( V_47 -> V_62 )
F_33 ( V_47 , V_62 , V_47 -> V_63 ) ;
}
F_32 ( & V_47 -> V_56 , V_55 ) ;
return 0 ;
}
static int F_34 ( struct V_46 * V_64 , T_1 V_50 ,
T_1 * V_49 , int * V_65 )
{
struct V_24 * V_25 = V_64 -> V_25 ;
struct V_46 * V_47 ;
T_1 V_66 = V_64 -> V_50 ;
T_1 V_67 = 0 ;
int V_68 = 1 ;
int V_69 ;
* V_65 = 0 ;
for ( V_69 = F_35 ( 0 ) ; V_69 < F_35 ( V_70 ) ; V_69 ++ ) {
V_47 = V_25 -> V_71 [ V_69 ] ;
if ( ! V_47 ) {
V_68 = 0 ;
continue;
}
if ( V_47 == V_64 )
V_47 -> V_50 = V_50 ;
if ( V_47 -> V_50 ) {
if ( V_68 ) {
V_67 |= V_47 -> V_43 ;
} else {
V_64 -> V_50 = V_66 ;
F_13 ( V_25 -> V_5 , L_5 ,
V_47 -> V_52 ) ;
return - V_37 ;
}
} else {
* V_65 = 1 ;
V_68 = 0 ;
}
}
* V_49 = V_67 ;
return 0 ;
}
static T_1 F_36 ( struct V_24 * V_25 ,
struct V_46 * V_64 )
{
T_1 V_72 = V_73 , V_74 = V_73 , V_75 = V_73 ;
T_1 V_76 = 0 , V_77 = 0 ;
T_1 V_78 , V_79 = 0 , V_48 ;
T_3 V_80 , V_81 ;
T_1 V_82 , V_83 ;
T_3 V_84 , V_85 ;
if ( ! V_64 -> V_50 ) {
V_64 -> V_53 = 0 ;
goto V_86;
}
V_83 = V_25 -> V_32 . V_87 * 1000 * 32 ;
if ( ! V_83 ) {
F_13 ( V_25 -> V_5 , L_6 ) ;
return - V_37 ;
}
V_82 = V_83 - V_64 -> V_50 ;
V_80 = F_37 ( V_82 , V_64 -> V_50 ) ;
while ( V_80 <= V_88 ) {
V_84 = V_64 -> V_50 * V_80 ;
V_85 = V_82 ;
V_81 = F_38 ( V_84 , V_85 ) ;
V_84 = V_83 * V_81 ;
V_85 = V_81 + V_80 ;
V_78 = F_38 ( V_84 , V_85 ) ;
V_72 = V_78 >= V_64 -> V_50 ? V_78 - V_64 -> V_50 : V_72 ;
if ( V_72 < V_75 ) {
V_75 = V_72 ;
V_76 = V_80 ;
V_77 = V_81 ;
V_79 = V_78 ;
if ( ! V_72 )
break;
}
if ( V_74 >= V_72 ) {
V_74 = V_72 ;
V_80 ++ ;
continue;
}
V_81 ++ ;
V_84 = V_83 * V_81 ;
V_80 = F_38 ( V_84 , V_64 -> V_50 ) ;
V_80 -= V_81 ;
V_74 = V_73 ;
}
V_64 -> V_50 = V_79 ;
V_64 -> V_53 = V_76 | ( V_77 << 16 ) ;
V_86:
V_48 = V_51 + 4 * V_64 -> V_52 ;
F_27 ( V_25 , V_48 , V_64 -> V_53 ) ;
return 0 ;
}
struct V_24 * F_39 ( struct V_89 * V_32 )
{
struct V_24 * V_25 ;
V_25 = F_8 ( V_32 -> V_5 , sizeof( * V_25 ) , V_14 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_35 = V_57 ;
V_25 -> V_32 = * V_32 ;
V_25 -> V_5 = V_32 -> V_5 ;
V_25 -> V_52 = 0 ;
F_40 ( & V_25 -> V_56 ) ;
V_25 -> V_2 = F_7 ( V_25 -> V_5 ,
V_25 -> V_32 . V_90 ,
V_25 -> V_32 . V_91 ,
V_25 -> V_32 . V_92 ,
V_25 -> V_32 . V_93 ) ;
if ( ! V_25 -> V_2 )
return NULL ;
if ( F_41 ( V_25 -> V_94 > V_70 ) )
V_25 -> V_94 = V_70 ;
return V_25 ;
}
int F_42 ( struct V_24 * V_25 )
{
struct V_46 * V_47 ;
unsigned long V_55 ;
int V_69 , V_65 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
if ( V_25 -> V_35 != V_57 ) {
F_32 ( & V_25 -> V_56 , V_55 ) ;
return - V_58 ;
}
if ( V_25 -> V_32 . V_95 ) {
unsigned V_96 = 10 * 100 ;
F_27 ( V_25 , V_97 , 1 ) ;
while ( V_96 ) {
if ( F_26 ( V_25 , V_97 ) == 0 )
break;
F_43 ( 10 ) ;
V_96 -- ;
}
F_41 ( ! V_96 ) ;
}
for ( V_69 = 0 ; V_69 < V_25 -> V_94 ; V_69 ++ ) {
F_44 ( 0 , V_25 -> V_32 . V_98 + 4 * V_69 ) ;
F_44 ( 0 , V_25 -> V_32 . V_99 + 4 * V_69 ) ;
F_44 ( 0 , V_25 -> V_32 . V_100 + 4 * V_69 ) ;
F_44 ( 0 , V_25 -> V_32 . V_101 + 4 * V_69 ) ;
}
F_27 ( V_25 , V_102 , 0xffffffff ) ;
F_27 ( V_25 , V_103 , 0xffffffff ) ;
F_27 ( V_25 , V_104 , 1 ) ;
F_27 ( V_25 , V_105 , 1 ) ;
V_25 -> V_35 = V_36 ;
V_65 = 0 ;
for ( V_69 = 0 ; V_69 < F_25 ( V_25 -> V_71 ) ; V_69 ++ ) {
V_47 = V_25 -> V_71 [ V_69 ] ;
if ( V_47 ) {
F_29 ( V_47 ) ;
F_30 ( V_47 ) ;
if ( F_45 ( V_47 ) && ! V_47 -> V_50 )
V_65 = 1 ;
}
}
F_24 ( V_25 , V_106 , V_65 ) ;
F_24 ( V_25 , V_107 , 0 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return 0 ;
}
int F_46 ( struct V_24 * V_25 )
{
unsigned long V_55 ;
int V_69 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
if ( V_25 -> V_35 != V_36 ) {
F_32 ( & V_25 -> V_56 , V_55 ) ;
return - V_37 ;
}
V_25 -> V_35 = V_108 ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
for ( V_69 = 0 ; V_69 < F_25 ( V_25 -> V_71 ) ; V_69 ++ ) {
if ( V_25 -> V_71 [ V_69 ] )
F_47 ( V_25 -> V_71 [ V_69 ] ) ;
}
F_31 ( & V_25 -> V_56 , V_55 ) ;
F_27 ( V_25 , V_102 , 0xffffffff ) ;
F_27 ( V_25 , V_103 , 0xffffffff ) ;
F_27 ( V_25 , V_104 , 0 ) ;
F_27 ( V_25 , V_105 , 0 ) ;
V_25 -> V_35 = V_57 ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return 0 ;
}
int F_48 ( struct V_24 * V_25 )
{
int V_13 = 0 , V_69 ;
if ( ! V_25 )
return - V_37 ;
if ( V_25 -> V_35 != V_57 )
F_46 ( V_25 ) ;
for ( V_69 = 0 ; V_69 < F_25 ( V_25 -> V_71 ) ; V_69 ++ )
F_49 ( V_25 -> V_71 [ V_69 ] ) ;
F_1 ( V_25 -> V_2 ) ;
return V_13 ;
}
int F_50 ( struct V_24 * V_25 , bool V_109 )
{
unsigned long V_55 ;
int V_69 , V_42 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
if ( V_25 -> V_35 != V_36 ) {
F_32 ( & V_25 -> V_56 , V_55 ) ;
return - V_37 ;
}
V_42 = V_109 ? V_110 : V_111 ;
F_27 ( V_25 , V_42 , V_112 ) ;
for ( V_69 = 0 ; V_69 < F_25 ( V_25 -> V_71 ) ; V_69 ++ ) {
if ( V_25 -> V_71 [ V_69 ] )
F_51 ( V_25 -> V_71 [ V_69 ] , V_109 ) ;
}
F_32 ( & V_25 -> V_56 , V_55 ) ;
return 0 ;
}
void F_52 ( struct V_24 * V_25 , T_1 V_27 )
{
F_27 ( V_25 , V_113 , V_27 ) ;
}
T_1 F_53 ( struct V_24 * V_25 )
{
return F_26 ( V_25 , V_114 ) ;
}
T_1 F_54 ( struct V_24 * V_25 )
{
return F_26 ( V_25 , V_115 ) ;
}
static void F_55 ( struct V_24 * V_25 ,
int V_116 , int V_117 ,
int V_118 )
{
struct V_46 * V_47 , * V_119 = NULL ;
int V_120 = V_117 ;
int V_121 = 0 ;
int V_122 , V_123 , V_69 ;
if ( ! V_117 )
return;
if ( V_116 ) {
V_122 = F_56 ( 0 ) ;
V_123 = F_56 ( V_70 ) ;
} else {
V_122 = F_35 ( 0 ) ;
V_123 = F_35 ( V_70 ) ;
}
for ( V_69 = V_122 ; V_69 < V_123 ; V_69 ++ ) {
V_47 = V_25 -> V_71 [ V_69 ] ;
if ( ! V_47 )
continue;
if ( V_47 -> V_124 )
V_47 -> V_117 = ( V_47 -> V_124 * V_117 ) / 100 ;
else
V_47 -> V_117 = V_118 ;
V_120 -= V_47 -> V_117 ;
if ( V_121 < V_47 -> V_117 ) {
V_121 = V_47 -> V_117 ;
V_119 = V_47 ;
}
}
V_119 -> V_117 += V_120 ;
}
static int F_57 ( struct V_24 * V_25 )
{
int V_125 = 0 , V_126 = 0 ;
struct V_1 * V_2 = V_25 -> V_2 ;
int V_127 = 0 , V_128 = 0 ;
int V_129 = 0 , V_130 = 0 ;
int V_131 , V_132 ;
struct V_46 * V_47 ;
int V_69 , V_133 = 0 ;
if ( ! V_25 -> V_52 )
return 0 ;
for ( V_69 = 0 ; V_69 < F_25 ( V_25 -> V_71 ) ; V_69 ++ ) {
V_47 = V_25 -> V_71 [ V_69 ] ;
if ( ! V_47 )
continue;
if ( F_58 ( V_47 ) ) {
if ( ! V_47 -> V_124 )
V_127 ++ ;
V_129 += V_47 -> V_124 ;
} else {
if ( ! V_47 -> V_124 )
V_128 ++ ;
V_130 += V_47 -> V_124 ;
V_133 ++ ;
}
}
if ( V_129 > 100 || V_130 > 100 )
return - V_37 ;
V_131 = ( V_133 * V_2 -> V_18 ) / V_25 -> V_52 ;
V_132 = V_2 -> V_18 - V_131 ;
if ( V_128 ) {
V_125 = V_131 - ( V_130 * V_131 ) / 100 ;
V_125 /= V_128 ;
}
if ( V_127 ) {
V_126 = V_132 - ( V_129 * V_132 ) / 100 ;
V_126 /= V_127 ;
}
F_55 ( V_25 , 0 , V_131 , V_125 ) ;
F_55 ( V_25 , 1 , V_132 , V_126 ) ;
return 0 ;
}
int F_59 ( struct V_46 * V_64 , int V_124 )
{
struct V_24 * V_25 = V_64 -> V_25 ;
unsigned long V_55 , V_134 ;
int V_13 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
F_31 ( & V_64 -> V_56 , V_134 ) ;
if ( V_64 -> V_124 == V_124 ) {
F_32 ( & V_64 -> V_56 , V_134 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return 0 ;
}
V_64 -> V_124 = V_124 ;
F_32 ( & V_64 -> V_56 , V_134 ) ;
V_13 = F_57 ( V_25 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return V_13 ;
}
T_1 F_60 ( struct V_24 * V_25 )
{
unsigned int V_84 , V_85 ;
V_84 = V_25 -> V_32 . V_87 * 32 * 1000 ;
V_85 = 1 + V_88 ;
return F_37 ( V_84 , V_85 ) ;
}
int F_61 ( struct V_46 * V_64 , T_1 V_50 )
{
struct V_24 * V_25 = V_64 -> V_25 ;
unsigned long V_55 , V_134 ;
int V_13 , V_65 ;
T_1 V_49 ;
if ( ! V_64 || ! F_45 ( V_64 ) )
return - V_37 ;
if ( V_64 -> V_50 == V_50 )
return V_50 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
F_31 ( & V_64 -> V_56 , V_134 ) ;
V_13 = F_34 ( V_64 , V_50 , & V_49 , & V_65 ) ;
if ( V_13 )
goto V_135;
V_13 = F_36 ( V_25 , V_64 ) ;
if ( V_13 )
goto V_135;
F_32 ( & V_64 -> V_56 , V_134 ) ;
F_24 ( V_25 , V_54 , V_49 ) ;
F_24 ( V_25 , V_106 , V_65 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return V_13 ;
V_135:
F_32 ( & V_64 -> V_56 , V_134 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return V_13 ;
}
T_1 F_62 ( struct V_46 * V_64 )
{
unsigned long V_55 ;
T_1 V_50 ;
F_31 ( & V_64 -> V_56 , V_55 ) ;
V_50 = V_64 -> V_50 ;
F_32 ( & V_64 -> V_56 , V_55 ) ;
return V_50 ;
}
struct V_46 * F_63 ( struct V_24 * V_25 , int V_52 ,
T_4 V_136 , int V_137 )
{
int V_138 = V_52 * 4 ;
struct V_46 * V_47 ;
unsigned long V_55 ;
V_52 = V_137 ? F_56 ( V_52 ) : F_35 ( V_52 ) ;
if ( F_64 ( V_52 ) >= V_25 -> V_94 )
return NULL ;
V_47 = F_8 ( V_25 -> V_5 , sizeof( * V_47 ) , V_14 ) ;
if ( ! V_47 )
return F_65 ( - V_139 ) ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
if ( V_25 -> V_71 [ V_52 ] ) {
F_32 ( & V_25 -> V_56 , V_55 ) ;
F_66 ( V_25 -> V_5 , V_47 ) ;
return F_65 ( - V_58 ) ;
}
V_47 -> V_25 = V_25 ;
V_47 -> V_35 = V_57 ;
V_47 -> V_52 = V_52 ;
V_47 -> V_136 = V_136 ;
V_47 -> V_50 = 0 ;
V_47 -> V_117 = V_25 -> V_2 -> V_18 / 2 ;
V_47 -> V_124 = 0 ;
if ( F_58 ( V_47 ) ) {
V_47 -> V_61 = V_25 -> V_32 . V_99 + V_138 ;
V_47 -> V_140 = V_25 -> V_32 . V_101 + V_138 ;
V_47 -> V_62 = V_25 -> V_32 . V_62 + V_138 ;
V_47 -> V_59 = V_141 ;
V_47 -> V_142 = V_102 ;
V_47 -> V_143 = V_144 ;
V_47 -> V_145 = V_146 ;
} else {
V_47 -> V_61 = V_25 -> V_32 . V_98 + V_138 ;
V_47 -> V_140 = V_25 -> V_32 . V_100 + V_138 ;
V_47 -> V_59 = V_147 ;
V_47 -> V_142 = V_103 ;
V_47 -> V_143 = V_148 ;
V_47 -> V_145 = V_149 ;
}
V_47 -> V_43 = F_67 ( F_68 ( V_47 ) ) ;
F_40 ( & V_47 -> V_56 ) ;
V_25 -> V_71 [ V_52 ] = V_47 ;
V_25 -> V_52 ++ ;
F_57 ( V_25 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return V_47 ;
}
int F_69 ( struct V_46 * V_47 )
{
unsigned long V_55 ;
int V_117 ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
V_117 = V_47 -> V_117 ;
F_32 ( & V_47 -> V_56 , V_55 ) ;
return V_117 ;
}
int F_49 ( struct V_46 * V_47 )
{
struct V_24 * V_25 ;
unsigned long V_55 ;
if ( ! V_47 )
return - V_37 ;
V_25 = V_47 -> V_25 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
if ( V_47 -> V_35 != V_57 )
F_47 ( V_47 ) ;
V_25 -> V_71 [ V_47 -> V_52 ] = NULL ;
V_25 -> V_52 -- ;
F_66 ( V_25 -> V_5 , V_47 ) ;
F_57 ( V_25 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return 0 ;
}
int F_70 ( struct V_46 * V_47 ,
struct V_150 * V_151 )
{
unsigned long V_55 ;
if ( ! V_47 )
return - V_37 ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
memcpy ( V_151 , & V_47 -> V_151 , sizeof( * V_151 ) ) ;
F_32 ( & V_47 -> V_56 , V_55 ) ;
return 0 ;
}
static void F_71 ( struct V_46 * V_47 ,
struct V_17 V_19 * V_22 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
struct V_17 V_19 * V_152 = V_47 -> V_153 ;
struct V_1 * V_2 = V_25 -> V_2 ;
T_2 V_154 ;
T_1 V_155 ;
V_154 = F_18 ( V_2 , V_22 ) ;
if ( ! V_47 -> V_60 ) {
V_47 -> V_151 . V_156 ++ ;
V_47 -> V_60 = V_22 ;
V_47 -> V_153 = V_22 ;
if ( V_47 -> V_35 == V_36 )
F_33 ( V_47 , V_61 , V_154 ) ;
return;
}
F_72 ( V_152 , V_157 , V_154 ) ;
V_47 -> V_153 = V_22 ;
V_47 -> V_151 . V_158 ++ ;
V_155 = F_73 ( V_152 , V_159 ) ;
if ( ( ( V_155 & ( V_160 | V_161 ) ) == V_160 ) &&
( V_47 -> V_35 == V_36 ) ) {
F_72 ( V_152 , V_159 , V_155 & ~ V_160 ) ;
F_33 ( V_47 , V_61 , V_154 ) ;
V_47 -> V_151 . V_162 ++ ;
}
}
int F_74 ( struct V_46 * V_47 , void * V_163 , void * V_164 ,
int V_165 , int V_166 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
struct V_17 V_19 * V_22 ;
T_2 V_167 ;
unsigned long V_55 ;
T_1 V_155 ;
int V_13 = 0 ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
if ( V_47 -> V_35 == V_108 ) {
V_13 = - V_37 ;
goto V_168;
}
if ( V_47 -> V_63 >= V_47 -> V_117 ) {
V_47 -> V_151 . V_169 ++ ;
V_13 = - V_139 ;
goto V_168;
}
V_22 = F_20 ( V_25 -> V_2 ) ;
if ( ! V_22 ) {
V_47 -> V_151 . V_169 ++ ;
V_13 = - V_139 ;
goto V_168;
}
if ( V_165 < V_25 -> V_32 . V_170 ) {
V_165 = V_25 -> V_32 . V_170 ;
V_47 -> V_151 . V_171 ++ ;
}
V_167 = F_75 ( V_25 -> V_5 , V_164 , V_165 , V_47 -> V_145 ) ;
V_13 = F_76 ( V_25 -> V_5 , V_167 ) ;
if ( V_13 ) {
F_22 ( V_25 -> V_2 , V_22 , 1 ) ;
V_13 = - V_37 ;
goto V_168;
}
V_155 = V_161 | V_172 | V_173 ;
F_77 ( V_47 , V_155 , V_166 ) ;
F_72 ( V_22 , V_157 , 0 ) ;
F_72 ( V_22 , V_174 , V_167 ) ;
F_72 ( V_22 , V_175 , V_165 ) ;
F_72 ( V_22 , V_159 , V_155 | V_165 ) ;
F_72 ( V_22 , V_176 , V_163 ) ;
F_72 ( V_22 , V_177 , V_167 ) ;
F_72 ( V_22 , V_178 , V_165 ) ;
F_71 ( V_47 , V_22 ) ;
if ( V_47 -> V_35 == V_36 && V_47 -> V_62 )
F_33 ( V_47 , V_62 , 1 ) ;
V_47 -> V_63 ++ ;
V_168:
F_32 ( & V_47 -> V_56 , V_55 ) ;
return V_13 ;
}
bool F_78 ( struct V_46 * V_47 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
struct V_1 * V_2 = V_25 -> V_2 ;
bool V_179 ;
unsigned long V_55 ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
V_179 = ( V_47 -> V_63 < V_47 -> V_117 ) &&
F_4 ( V_2 -> V_3 ) ;
F_32 ( & V_47 -> V_56 , V_55 ) ;
return V_179 ;
}
static void F_79 ( struct V_46 * V_47 ,
struct V_17 V_19 * V_22 ,
int V_180 , int V_181 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
struct V_1 * V_2 = V_25 -> V_2 ;
T_2 V_182 ;
int V_183 ;
void * V_163 ;
V_163 = ( void * ) F_73 ( V_22 , V_176 ) ;
V_182 = F_73 ( V_22 , V_177 ) ;
V_183 = F_73 ( V_22 , V_178 ) ;
F_80 ( V_25 -> V_5 , V_182 , V_183 , V_47 -> V_145 ) ;
F_22 ( V_2 , V_22 , 1 ) ;
(* V_47 -> V_136 )( V_163 , V_180 , V_181 ) ;
}
static int F_81 ( struct V_46 * V_47 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
struct V_17 V_19 * V_22 ;
int V_181 , V_180 ;
int V_184 = 0 ;
struct V_1 * V_2 = V_25 -> V_2 ;
T_2 V_154 ;
unsigned long V_55 ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
V_22 = V_47 -> V_60 ;
if ( ! V_22 ) {
V_47 -> V_151 . V_185 ++ ;
V_181 = - V_38 ;
goto V_168;
}
V_154 = F_18 ( V_2 , V_22 ) ;
V_181 = F_82 ( & V_22 -> V_159 ) ;
V_180 = V_181 & 0x7ff ;
if ( V_181 & V_161 ) {
V_47 -> V_151 . V_186 ++ ;
V_181 = - V_58 ;
goto V_168;
}
if ( V_181 & V_187 )
V_180 -= V_188 ;
V_181 = V_181 & ( V_160 | V_189 |
V_190 ) ;
V_47 -> V_60 = F_19 ( V_2 , F_73 ( V_22 , V_157 ) ) ;
F_33 ( V_47 , V_140 , V_154 ) ;
V_47 -> V_63 -- ;
V_47 -> V_151 . V_191 ++ ;
if ( V_181 & V_160 ) {
V_47 -> V_151 . V_192 ++ ;
F_33 ( V_47 , V_61 , F_18 ( V_2 , V_47 -> V_60 ) ) ;
}
F_32 ( & V_47 -> V_56 , V_55 ) ;
if ( F_83 ( V_181 & V_189 ) )
V_184 = - V_193 ;
else
V_184 = V_181 ;
F_79 ( V_47 , V_22 , V_180 , V_184 ) ;
return V_181 ;
V_168:
F_32 ( & V_47 -> V_56 , V_55 ) ;
return V_181 ;
}
int F_84 ( struct V_46 * V_47 , int V_194 )
{
int V_195 = 0 , V_13 = 0 ;
if ( V_47 -> V_35 != V_36 )
return - V_37 ;
while ( V_195 < V_194 ) {
V_13 = F_81 ( V_47 ) ;
if ( V_13 < 0 )
break;
V_195 ++ ;
}
return V_195 ;
}
int F_85 ( struct V_46 * V_47 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
unsigned long V_55 ;
int V_13 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
V_13 = F_29 ( V_47 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_30 ( V_47 ) ;
if ( V_13 )
return V_13 ;
return 0 ;
}
int F_47 ( struct V_46 * V_47 )
{
struct V_24 * V_25 = V_47 -> V_25 ;
struct V_1 * V_2 = V_25 -> V_2 ;
unsigned long V_55 ;
int V_13 ;
unsigned V_96 ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
if ( V_47 -> V_35 == V_108 ) {
F_32 ( & V_47 -> V_56 , V_55 ) ;
return - V_37 ;
}
V_47 -> V_35 = V_108 ;
F_27 ( V_25 , V_47 -> V_142 , V_47 -> V_43 ) ;
F_27 ( V_25 , V_47 -> V_143 , F_68 ( V_47 ) ) ;
V_96 = 100 * 100 ;
while ( V_96 ) {
T_1 V_140 = F_86 ( V_47 , V_140 ) ;
if ( ( V_140 & V_196 ) == V_196 )
break;
F_43 ( 10 ) ;
V_96 -- ;
}
F_41 ( ! V_96 ) ;
F_33 ( V_47 , V_140 , V_196 ) ;
F_32 ( & V_47 -> V_56 , V_55 ) ;
do {
V_13 = F_81 ( V_47 ) ;
if ( V_13 < 0 )
break;
} while ( ( V_13 & V_189 ) == 0 );
F_31 ( & V_47 -> V_56 , V_55 ) ;
while ( V_47 -> V_60 ) {
struct V_17 V_19 * V_22 = V_47 -> V_60 ;
T_2 V_197 ;
V_197 = F_73 ( V_22 , V_157 ) ;
V_47 -> V_60 = F_19 ( V_2 , V_197 ) ;
V_47 -> V_63 -- ;
V_47 -> V_151 . V_198 ++ ;
F_32 ( & V_47 -> V_56 , V_55 ) ;
F_79 ( V_47 , V_22 , 0 , - V_193 ) ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
}
V_47 -> V_35 = V_57 ;
F_32 ( & V_47 -> V_56 , V_55 ) ;
return 0 ;
}
int F_51 ( struct V_46 * V_47 , bool V_109 )
{
unsigned long V_55 ;
F_31 ( & V_47 -> V_56 , V_55 ) ;
if ( V_47 -> V_35 != V_36 ) {
F_32 ( & V_47 -> V_56 , V_55 ) ;
return - V_37 ;
}
F_27 ( V_47 -> V_25 , V_109 ? V_47 -> V_59 : V_47 -> V_142 ,
V_47 -> V_43 ) ;
F_32 ( & V_47 -> V_56 , V_55 ) ;
return 0 ;
}
int F_87 ( struct V_24 * V_25 , int V_26 )
{
unsigned long V_55 ;
int V_13 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
V_13 = F_28 ( V_25 , V_26 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return V_13 ;
}
int F_88 ( struct V_24 * V_25 , int V_26 , int V_27 )
{
unsigned long V_55 ;
int V_13 ;
F_31 ( & V_25 -> V_56 , V_55 ) ;
V_13 = F_24 ( V_25 , V_26 , V_27 ) ;
F_32 ( & V_25 -> V_56 , V_55 ) ;
return V_13 ;
}
