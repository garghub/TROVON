static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static void F_3 ( struct V_1 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_4 ( & V_6 -> V_4 . V_9 ) ;
F_5 ( 1 , V_8 -> V_10 + F_6 ( V_6 -> V_11 ) ) ;
F_5 ( 0 , V_8 -> V_10 + F_6 ( V_6 -> V_11 ) ) ;
F_7 () ;
V_6 -> V_12 = 0 ;
}
static void F_8 ( struct V_1 * V_6 ,
enum V_13 V_14 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_15 ;
F_3 ( V_6 ) ;
F_5 ( F_9 ( V_6 -> V_16 , sizeof( struct V_17 ) ) ,
V_8 -> V_10 + F_10 ( V_6 -> V_11 ) ) ;
F_5 ( V_18 , V_8 -> V_10 +
F_11 ( V_6 -> V_11 ) ) ;
F_5 ( V_19 , V_8 -> V_10 + F_12 ( V_6 -> V_11 ) ) ;
V_15 = F_13 ( V_8 -> V_10 + F_14 ( V_8 -> V_20 ) ) ;
V_15 |= F_15 ( V_6 -> V_11 ) ;
F_5 ( V_15 , V_8 -> V_10 + F_14 ( V_8 -> V_20 ) ) ;
F_7 () ;
V_15 = V_21 | V_22 ;
if ( V_14 == V_23 )
V_15 |= V_24 ;
F_5 ( V_15 , V_8 -> V_10 + F_16 ( V_6 -> V_11 ) ) ;
V_6 -> V_12 = 1 ;
V_6 -> V_25 = 0 ;
V_6 -> V_26 = 0 ;
}
static int F_17 ( struct V_2 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_6 -> V_27 )
return 0 ;
V_6 -> V_27 = F_18 ( V_8 -> V_28 , V_18 ,
& V_6 -> V_16 , V_29 ) ;
if ( ! V_6 -> V_27 ) {
F_19 ( V_8 -> V_28 , L_1 ) ;
return - V_30 ;
}
return 0 ;
}
static void F_20 ( struct V_2 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_15 ;
unsigned long V_31 ;
F_21 ( F_22 ( V_5 ) ) ;
if ( V_6 -> V_32 ) {
F_19 ( V_6 -> V_8 -> V_28 , L_2 ) ;
return;
}
F_23 ( & V_6 -> V_4 . V_9 , V_31 ) ;
F_3 ( V_6 ) ;
F_24 ( & V_6 -> V_4 . V_9 , V_31 ) ;
F_25 ( V_8 -> V_28 , V_18 , V_6 -> V_27 ,
V_6 -> V_16 ) ;
V_6 -> V_27 = NULL ;
V_15 = F_13 ( V_8 -> V_10 + F_14 ( V_8 -> V_20 ) ) ;
V_15 &= ~ F_15 ( V_6 -> V_11 ) ;
F_5 ( V_15 , V_8 -> V_10 + F_14 ( V_8 -> V_20 ) ) ;
F_5 ( 0 , V_8 -> V_10 + F_12 ( V_6 -> V_11 ) ) ;
}
static void F_26 ( struct V_1 * V_6 ,
struct V_33 * V_34 )
{
memcpy ( & V_6 -> V_35 , V_34 , sizeof( * V_34 ) ) ;
V_6 -> V_36 = 1 ;
}
static struct V_37 * F_27 ( struct V_2 * V_5 ,
struct V_38 * V_39 , unsigned int V_40 ,
enum V_13 V_41 , unsigned long V_31 ,
void * V_42 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_43 * V_44 ;
struct V_38 * V_45 ;
T_1 V_46 ;
struct V_17 * V_47 ;
unsigned int V_48 = 0 ;
if ( ! F_28 ( V_41 ) ) {
F_19 ( V_8 -> V_28 , L_3 ) ;
return NULL ;
}
F_29 (sgl, sg, sg_len, i)
V_48 += F_30 ( F_31 ( V_45 ) , V_49 ) ;
V_44 = F_32 ( sizeof( * V_44 ) +
( V_48 * sizeof( struct V_17 ) ) , V_50 ) ;
if ( ! V_44 )
goto V_51;
if ( V_31 & V_52 )
V_44 -> V_31 |= V_53 ;
if ( V_31 & V_54 )
V_44 -> V_31 |= V_55 ;
else
V_44 -> V_31 |= V_56 ;
V_44 -> V_57 = V_48 ;
V_44 -> V_58 = V_44 -> V_47 ;
V_44 -> V_14 = V_41 ;
V_47 = V_44 -> V_47 ;
F_29 (sgl, sg, sg_len, i) {
unsigned int V_59 = F_31 ( V_45 ) ;
unsigned int V_60 = 0 ;
do {
V_47 -> V_61 = F_33 ( V_45 ) + V_60 ;
if ( V_59 > V_49 ) {
V_47 -> V_62 = V_49 ;
V_59 -= V_49 ;
V_60 += V_49 ;
} else {
V_47 -> V_62 = V_59 ;
V_59 = 0 ;
}
V_44 -> V_63 += V_47 -> V_62 ;
V_47 ++ ;
} while ( V_59 > 0 );
}
return F_34 ( & V_6 -> V_4 , & V_44 -> V_64 , V_31 ) ;
V_51:
F_35 ( V_44 ) ;
return NULL ;
}
static void F_36 ( struct V_1 * V_6 )
{
unsigned long V_65 ;
F_37 ( V_25 ) ;
F_23 ( & V_6 -> V_4 . V_9 , V_65 ) ;
if ( V_6 -> V_32 ) {
F_38 ( & V_6 -> V_32 -> V_64 . V_66 , & V_6 -> V_4 . V_67 ) ;
V_6 -> V_32 = NULL ;
}
F_39 ( & V_6 -> V_4 , & V_25 ) ;
F_24 ( & V_6 -> V_4 . V_9 , V_65 ) ;
F_40 ( & V_6 -> V_4 , & V_25 ) ;
}
static int F_41 ( struct V_2 * V_5 , enum V_68 V_69 ,
unsigned long V_70 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_71 = 0 ;
unsigned long V_65 ;
switch ( V_69 ) {
case V_72 :
F_23 ( & V_6 -> V_4 . V_9 , V_65 ) ;
F_5 ( 1 , V_8 -> V_10 + F_42 ( V_6 -> V_11 ) ) ;
V_6 -> V_73 = 1 ;
F_24 ( & V_6 -> V_4 . V_9 , V_65 ) ;
break;
case V_74 :
F_23 ( & V_6 -> V_4 . V_9 , V_65 ) ;
F_5 ( 0 , V_8 -> V_10 + F_42 ( V_6 -> V_11 ) ) ;
V_6 -> V_73 = 0 ;
F_24 ( & V_6 -> V_4 . V_9 , V_65 ) ;
break;
case V_75 :
F_36 ( V_6 ) ;
break;
case V_76 :
F_23 ( & V_6 -> V_4 . V_9 , V_65 ) ;
F_26 ( V_6 , (struct V_33 * ) V_70 ) ;
F_24 ( & V_6 -> V_4 . V_9 , V_65 ) ;
break;
default:
V_71 = - V_77 ;
break;
}
return V_71 ;
}
static T_1 F_43 ( struct V_7 * V_8 )
{
T_1 V_46 , V_78 , V_79 ;
unsigned long V_31 ;
struct V_43 * V_44 ;
V_78 = F_13 ( V_8 -> V_10 + F_44 ( V_8 -> V_20 ) ) ;
if ( ! ( V_78 & V_80 ) )
return V_78 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_81 ; V_46 ++ ) {
struct V_1 * V_6 = & V_8 -> V_82 [ V_46 ] ;
if ( ! ( V_78 & F_15 ( V_46 ) ) )
continue;
V_79 = F_13 ( V_8 -> V_10 +
F_45 ( V_46 ) ) ;
F_5 ( V_79 , V_8 -> V_10 +
F_46 ( V_46 ) ) ;
F_23 ( & V_6 -> V_4 . V_9 , V_31 ) ;
V_44 = V_6 -> V_32 ;
if ( V_44 ) {
V_44 -> V_57 -= V_44 -> V_83 ;
V_44 -> V_58 += V_44 -> V_83 ;
V_6 -> V_32 = NULL ;
V_6 -> V_25 += V_44 -> V_83 ;
V_6 -> V_25 %= V_84 ;
if ( ! V_44 -> V_57 )
F_47 ( & V_44 -> V_64 ) ;
else
F_38 ( & V_44 -> V_64 . V_66 ,
& V_6 -> V_4 . V_67 ) ;
}
F_24 ( & V_6 -> V_4 . V_9 , V_31 ) ;
}
return V_78 ;
}
static T_2 F_48 ( int V_85 , void * V_86 )
{
struct V_7 * V_8 = V_86 ;
T_1 V_87 = 0 , V_78 = 0 ;
V_78 |= F_43 ( V_8 ) ;
if ( V_78 & V_80 )
F_49 ( & V_8 -> V_88 ) ;
if ( V_78 & V_89 )
V_87 = F_13 ( V_8 -> V_10 + V_90 ) ;
F_50 () ;
F_5 ( V_87 , V_8 -> V_10 + V_91 ) ;
return V_92 ;
}
static enum V_93 F_51 ( struct V_2 * V_5 , T_3 V_94 ,
struct V_95 * V_96 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
struct V_97 * V_64 ;
int V_71 ;
T_4 V_98 = 0 ;
unsigned int V_46 ;
unsigned long V_31 ;
V_71 = F_52 ( V_5 , V_94 , V_96 ) ;
if ( V_71 == V_99 )
return V_71 ;
if ( ! V_96 )
return V_6 -> V_73 ? V_100 : V_71 ;
F_23 ( & V_6 -> V_4 . V_9 , V_31 ) ;
V_64 = F_53 ( & V_6 -> V_4 , V_94 ) ;
if ( V_64 )
V_98 = F_2 ( V_64 , struct V_43 , V_64 ) -> V_63 ;
else if ( V_6 -> V_32 && V_6 -> V_32 -> V_64 . V_101 . V_94 == V_94 )
for ( V_46 = 0 ; V_46 < V_6 -> V_32 -> V_57 ; V_46 ++ )
V_98 += V_6 -> V_32 -> V_58 [ V_46 ] . V_62 ;
F_24 ( & V_6 -> V_4 . V_9 , V_31 ) ;
F_54 ( V_96 , V_98 ) ;
if ( V_71 == V_102 && V_6 -> V_73 )
V_71 = V_100 ;
return V_71 ;
}
static void F_55 ( struct V_1 * V_6 ,
enum V_13 V_14 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_103 ;
if ( V_14 == V_23 )
V_103 = V_6 -> V_35 . V_104 ;
else
V_103 = V_6 -> V_35 . V_105 ;
F_5 ( V_103 , V_8 -> V_10 + V_106 ) ;
V_6 -> V_36 = 0 ;
}
static void F_56 ( struct V_1 * V_6 )
{
struct V_97 * V_64 = F_57 ( & V_6 -> V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_43 * V_44 ;
struct V_17 * V_47 ;
struct V_17 * V_107 = F_58 ( V_6 -> V_27 ,
sizeof( struct V_17 ) ) ;
F_4 ( & V_6 -> V_4 . V_9 ) ;
if ( ! V_64 )
return;
F_59 ( & V_64 -> V_66 ) ;
V_44 = F_2 ( V_64 , struct V_43 , V_64 ) ;
V_6 -> V_32 = V_44 ;
if ( ! V_6 -> V_12 )
F_8 ( V_6 , V_44 -> V_14 ) ;
if ( V_6 -> V_36 )
F_55 ( V_6 , V_44 -> V_14 ) ;
V_47 = V_6 -> V_32 -> V_58 ;
if ( V_44 -> V_57 > V_84 )
V_44 -> V_83 = V_84 ;
else
V_44 -> V_83 = V_44 -> V_57 ;
if ( V_44 -> V_57 == V_44 -> V_83 )
V_47 [ V_44 -> V_83 - 1 ] . V_31 = V_44 -> V_31 ;
else
V_47 [ V_44 -> V_83 - 1 ] . V_31 |= V_56 ;
if ( V_6 -> V_26 + V_44 -> V_83 > V_84 ) {
T_1 V_108 = V_84 - V_6 -> V_26 ;
memcpy ( & V_107 [ V_6 -> V_26 ] , V_47 ,
V_108 * sizeof( struct V_17 ) ) ;
memcpy ( V_107 , & V_47 [ V_108 ] , ( V_44 -> V_83 - V_108 ) *
sizeof( struct V_17 ) ) ;
} else {
memcpy ( & V_107 [ V_6 -> V_26 ] , V_47 ,
V_44 -> V_83 * sizeof( struct V_17 ) ) ;
}
V_6 -> V_26 += V_44 -> V_83 ;
V_6 -> V_26 %= V_84 ;
F_7 () ;
F_5 ( V_6 -> V_26 * sizeof( struct V_17 ) ,
V_8 -> V_10 + F_60 ( V_6 -> V_11 ) ) ;
}
static void F_61 ( unsigned long V_86 )
{
struct V_7 * V_8 = (struct V_7 * ) V_86 ;
struct V_1 * V_6 ;
unsigned long V_31 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_81 ; V_46 ++ ) {
V_6 = & V_8 -> V_82 [ V_46 ] ;
F_23 ( & V_6 -> V_4 . V_9 , V_31 ) ;
if ( ! F_62 ( & V_6 -> V_4 . V_67 ) && ! V_6 -> V_32 )
F_56 ( V_6 ) ;
F_24 ( & V_6 -> V_4 . V_9 , V_31 ) ;
}
}
static void F_63 ( struct V_2 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
unsigned long V_31 ;
F_23 ( & V_6 -> V_4 . V_9 , V_31 ) ;
if ( F_64 ( & V_6 -> V_4 ) && ! V_6 -> V_32 )
F_56 ( V_6 ) ;
F_24 ( & V_6 -> V_4 . V_9 , V_31 ) ;
}
static void F_65 ( struct V_97 * V_64 )
{
struct V_43 * V_44 = F_2 ( V_64 ,
struct V_43 , V_64 ) ;
F_35 ( V_44 ) ;
}
static struct V_2 * F_66 ( struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_7 * V_8 = F_2 ( V_112 -> V_113 ,
struct V_7 , V_3 ) ;
unsigned int V_114 ;
if ( V_110 -> V_115 != 1 )
return NULL ;
V_114 = V_110 -> args [ 0 ] ;
if ( V_114 >= V_8 -> V_81 )
return NULL ;
return F_67 ( & ( V_8 -> V_82 [ V_114 ] . V_4 . V_5 ) ) ;
}
static int F_68 ( struct V_7 * V_8 )
{
T_1 V_15 ;
V_15 = F_13 ( V_8 -> V_10 + V_116 ) >> V_117 ;
V_15 &= V_118 ;
if ( V_8 -> V_20 >= V_15 )
return - V_119 ;
V_15 = F_13 ( V_8 -> V_10 + V_120 ) ;
V_8 -> V_81 = V_15 & V_121 ;
V_15 = F_13 ( V_8 -> V_10 + V_122 ) ;
V_15 |= V_123 ;
F_5 ( V_15 , V_8 -> V_10 + V_122 ) ;
V_15 &= ~ V_123 ;
F_5 ( V_15 , V_8 -> V_10 + V_122 ) ;
F_7 () ;
V_15 |= V_124 ;
F_5 ( V_15 , V_8 -> V_10 + V_122 ) ;
F_5 ( V_125 , V_8 -> V_10 + V_106 ) ;
F_5 ( V_126 , V_8 -> V_10 + V_127 ) ;
F_5 ( V_128 | V_129 ,
V_8 -> V_10 + V_130 ) ;
F_5 ( V_131 , V_8 -> V_10 + F_14 ( V_8 -> V_20 ) ) ;
return 0 ;
}
static void F_69 ( struct V_7 * V_8 , struct V_1 * V_6 ,
T_1 V_132 )
{
V_6 -> V_11 = V_132 ;
V_6 -> V_8 = V_8 ;
F_70 ( & V_6 -> V_4 , & V_8 -> V_3 ) ;
V_6 -> V_4 . V_133 = F_65 ;
}
static int F_71 ( struct V_134 * V_135 )
{
struct V_7 * V_8 ;
struct V_136 * V_137 ;
int V_71 , V_46 ;
V_8 = F_72 ( & V_135 -> V_28 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
V_8 -> V_28 = & V_135 -> V_28 ;
V_137 = F_73 ( V_135 , V_138 , 0 ) ;
V_8 -> V_10 = F_74 ( & V_135 -> V_28 , V_137 ) ;
if ( F_75 ( V_8 -> V_10 ) )
return F_76 ( V_8 -> V_10 ) ;
V_8 -> V_85 = F_77 ( V_135 , 0 ) ;
if ( V_8 -> V_85 < 0 )
return V_8 -> V_85 ;
V_71 = F_78 ( V_135 -> V_28 . V_139 , L_4 , & V_8 -> V_20 ) ;
if ( V_71 ) {
F_19 ( V_8 -> V_28 , L_5 ) ;
return V_71 ;
}
V_8 -> V_140 = F_79 ( V_8 -> V_28 , L_6 ) ;
if ( F_75 ( V_8 -> V_140 ) )
return F_76 ( V_8 -> V_140 ) ;
V_71 = F_80 ( V_8 -> V_140 ) ;
if ( V_71 ) {
F_19 ( V_8 -> V_28 , L_7 ) ;
return V_71 ;
}
V_71 = F_68 ( V_8 ) ;
if ( V_71 )
goto V_141;
F_81 ( & V_8 -> V_88 , F_61 , ( unsigned long ) V_8 ) ;
V_8 -> V_82 = F_82 ( V_8 -> V_28 , V_8 -> V_81 ,
sizeof( * V_8 -> V_82 ) , V_29 ) ;
if ( ! V_8 -> V_82 ) {
V_71 = - V_30 ;
goto V_141;
}
F_83 ( & V_8 -> V_3 . V_82 ) ;
for ( V_46 = 0 ; V_46 < V_8 -> V_81 ; V_46 ++ )
F_69 ( V_8 , & V_8 -> V_82 [ V_46 ] , V_46 ) ;
V_71 = F_84 ( V_8 -> V_28 , V_8 -> V_85 , F_48 ,
V_142 , L_8 , V_8 ) ;
if ( V_71 )
goto V_141;
V_8 -> V_3 . V_28 = V_8 -> V_28 ;
V_8 -> V_3 . V_28 -> V_143 = & V_8 -> V_143 ;
V_71 = F_85 ( V_8 -> V_3 . V_28 , V_49 ) ;
if ( V_71 ) {
F_19 ( V_8 -> V_28 , L_9 ) ;
goto V_141;
}
F_86 ( V_135 , V_8 ) ;
F_87 ( V_8 -> V_3 . V_144 ) ;
F_88 ( V_145 , V_8 -> V_3 . V_144 ) ;
V_8 -> V_3 . V_146 = F_17 ;
V_8 -> V_3 . V_147 = F_20 ;
V_8 -> V_3 . V_148 = F_27 ;
V_8 -> V_3 . V_149 = F_41 ;
V_8 -> V_3 . V_150 = F_63 ;
V_8 -> V_3 . V_151 = F_51 ;
V_8 -> V_3 . V_28 = V_8 -> V_28 ;
V_71 = F_89 ( & V_8 -> V_3 ) ;
if ( V_71 ) {
F_19 ( V_8 -> V_28 , L_10 ) ;
goto V_141;
}
V_71 = F_90 ( V_135 -> V_28 . V_139 , F_66 ,
& V_8 -> V_3 ) ;
if ( V_71 )
goto V_152;
return 0 ;
V_152:
F_91 ( & V_8 -> V_3 ) ;
V_141:
F_92 ( V_8 -> V_140 ) ;
return V_71 ;
}
static int F_93 ( struct V_134 * V_135 )
{
struct V_7 * V_8 = F_94 ( V_135 ) ;
T_1 V_46 ;
F_95 ( V_135 -> V_28 . V_139 ) ;
F_91 ( & V_8 -> V_3 ) ;
F_5 ( 0 , V_8 -> V_10 + F_14 ( V_8 -> V_20 ) ) ;
F_96 ( V_8 -> V_28 , V_8 -> V_85 , V_8 ) ;
for ( V_46 = 0 ; V_46 < V_8 -> V_81 ; V_46 ++ ) {
F_36 ( & V_8 -> V_82 [ V_46 ] ) ;
F_97 ( & V_8 -> V_82 [ V_46 ] . V_4 . V_88 ) ;
F_25 ( V_8 -> V_28 , V_18 ,
V_8 -> V_82 [ V_46 ] . V_27 ,
V_8 -> V_82 [ V_46 ] . V_16 ) ;
}
F_97 ( & V_8 -> V_88 ) ;
F_92 ( V_8 -> V_140 ) ;
return 0 ;
}
