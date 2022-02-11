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
V_44 -> V_52 = V_48 ;
V_44 -> V_53 = V_44 -> V_47 ;
V_44 -> V_14 = V_41 ;
V_47 = V_44 -> V_47 ;
F_29 (sgl, sg, sg_len, i) {
unsigned int V_54 = F_31 ( V_45 ) ;
unsigned int V_55 = 0 ;
do {
V_47 -> V_56 = F_33 ( V_45 ) + V_55 ;
if ( V_54 > V_49 ) {
V_47 -> V_57 = V_49 ;
V_54 -= V_49 ;
V_55 += V_49 ;
} else {
V_47 -> V_57 = V_54 ;
V_54 = 0 ;
}
V_44 -> V_58 += V_47 -> V_57 ;
V_47 ++ ;
} while ( V_54 > 0 );
}
return F_34 ( & V_6 -> V_4 , & V_44 -> V_59 , V_31 ) ;
V_51:
F_35 ( V_44 ) ;
return NULL ;
}
static void F_36 ( struct V_1 * V_6 )
{
unsigned long V_60 ;
F_37 ( V_25 ) ;
F_23 ( & V_6 -> V_4 . V_9 , V_60 ) ;
if ( V_6 -> V_32 ) {
F_38 ( & V_6 -> V_32 -> V_59 . V_61 , & V_6 -> V_4 . V_62 ) ;
V_6 -> V_32 = NULL ;
}
F_39 ( & V_6 -> V_4 , & V_25 ) ;
F_24 ( & V_6 -> V_4 . V_9 , V_60 ) ;
F_40 ( & V_6 -> V_4 , & V_25 ) ;
}
static int F_41 ( struct V_2 * V_5 , enum V_63 V_64 ,
unsigned long V_65 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_66 = 0 ;
unsigned long V_60 ;
switch ( V_64 ) {
case V_67 :
F_23 ( & V_6 -> V_4 . V_9 , V_60 ) ;
F_5 ( 1 , V_8 -> V_10 + F_42 ( V_6 -> V_11 ) ) ;
V_6 -> V_68 = 1 ;
F_24 ( & V_6 -> V_4 . V_9 , V_60 ) ;
break;
case V_69 :
F_23 ( & V_6 -> V_4 . V_9 , V_60 ) ;
F_5 ( 0 , V_8 -> V_10 + F_42 ( V_6 -> V_11 ) ) ;
V_6 -> V_68 = 0 ;
F_24 ( & V_6 -> V_4 . V_9 , V_60 ) ;
break;
case V_70 :
F_36 ( V_6 ) ;
break;
case V_71 :
F_23 ( & V_6 -> V_4 . V_9 , V_60 ) ;
F_26 ( V_6 , (struct V_33 * ) V_65 ) ;
F_24 ( & V_6 -> V_4 . V_9 , V_60 ) ;
break;
default:
V_66 = - V_72 ;
break;
}
return V_66 ;
}
static T_1 F_43 ( struct V_7 * V_8 )
{
T_1 V_46 , V_73 , V_74 ;
unsigned long V_31 ;
struct V_43 * V_44 ;
V_73 = F_13 ( V_8 -> V_10 + F_44 ( V_8 -> V_20 ) ) ;
if ( ! ( V_73 & V_75 ) )
return V_73 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_76 ; V_46 ++ ) {
struct V_1 * V_6 = & V_8 -> V_77 [ V_46 ] ;
if ( ! ( V_73 & F_15 ( V_46 ) ) )
continue;
V_74 = F_13 ( V_8 -> V_10 +
F_45 ( V_46 ) ) ;
F_5 ( V_74 , V_8 -> V_10 +
F_46 ( V_46 ) ) ;
F_23 ( & V_6 -> V_4 . V_9 , V_31 ) ;
V_44 = V_6 -> V_32 ;
if ( V_44 ) {
V_44 -> V_52 -= V_44 -> V_78 ;
V_44 -> V_53 += V_44 -> V_78 ;
V_6 -> V_32 = NULL ;
V_6 -> V_25 += V_44 -> V_78 ;
V_6 -> V_25 %= V_79 ;
if ( ! V_44 -> V_52 )
F_47 ( & V_44 -> V_59 ) ;
else
F_38 ( & V_44 -> V_59 . V_61 ,
& V_6 -> V_4 . V_62 ) ;
}
F_24 ( & V_6 -> V_4 . V_9 , V_31 ) ;
}
return V_73 ;
}
static T_2 F_48 ( int V_80 , void * V_81 )
{
struct V_7 * V_8 = V_81 ;
T_1 V_82 = 0 , V_73 = 0 ;
V_73 |= F_43 ( V_8 ) ;
if ( V_73 & V_75 )
F_49 ( & V_8 -> V_83 ) ;
if ( V_73 & V_84 )
V_82 = F_13 ( V_8 -> V_10 + V_85 ) ;
F_50 () ;
F_5 ( V_82 , V_8 -> V_10 + V_86 ) ;
return V_87 ;
}
static enum V_88 F_51 ( struct V_2 * V_5 , T_3 V_89 ,
struct V_90 * V_91 )
{
struct V_1 * V_6 = F_1 ( V_5 ) ;
struct V_92 * V_59 ;
int V_66 ;
T_4 V_93 = 0 ;
unsigned int V_46 ;
unsigned long V_31 ;
V_66 = F_52 ( V_5 , V_89 , V_91 ) ;
if ( V_66 == V_94 )
return V_66 ;
if ( ! V_91 )
return V_6 -> V_68 ? V_95 : V_66 ;
F_23 ( & V_6 -> V_4 . V_9 , V_31 ) ;
V_59 = F_53 ( & V_6 -> V_4 , V_89 ) ;
if ( V_59 )
V_93 = F_2 ( V_59 , struct V_43 , V_59 ) -> V_58 ;
else if ( V_6 -> V_32 && V_6 -> V_32 -> V_59 . V_96 . V_89 == V_89 )
for ( V_46 = 0 ; V_46 < V_6 -> V_32 -> V_52 ; V_46 ++ )
V_93 += V_6 -> V_32 -> V_53 [ V_46 ] . V_57 ;
F_24 ( & V_6 -> V_4 . V_9 , V_31 ) ;
F_54 ( V_91 , V_93 ) ;
if ( V_66 == V_97 && V_6 -> V_68 )
V_66 = V_95 ;
return V_66 ;
}
static void F_55 ( struct V_1 * V_6 ,
enum V_13 V_14 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_98 ;
if ( V_14 == V_23 )
V_98 = V_6 -> V_35 . V_99 ;
else
V_98 = V_6 -> V_35 . V_100 ;
F_5 ( V_98 , V_8 -> V_10 + V_101 ) ;
V_6 -> V_36 = 0 ;
}
static void F_56 ( struct V_1 * V_6 )
{
struct V_92 * V_59 = F_57 ( & V_6 -> V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_43 * V_44 ;
struct V_17 * V_47 ;
struct V_17 * V_102 = F_58 ( V_6 -> V_27 ,
sizeof( struct V_17 ) ) ;
F_4 ( & V_6 -> V_4 . V_9 ) ;
if ( ! V_59 )
return;
F_59 ( & V_59 -> V_61 ) ;
V_44 = F_2 ( V_59 , struct V_43 , V_59 ) ;
V_6 -> V_32 = V_44 ;
if ( ! V_6 -> V_12 )
F_8 ( V_6 , V_44 -> V_14 ) ;
if ( V_6 -> V_36 )
F_55 ( V_6 , V_44 -> V_14 ) ;
V_47 = V_6 -> V_32 -> V_53 ;
if ( V_44 -> V_52 > V_79 )
V_44 -> V_78 = V_79 ;
else
V_44 -> V_78 = V_44 -> V_52 ;
V_47 [ V_44 -> V_78 - 1 ] . V_31 |= V_103 ;
if ( V_6 -> V_26 + V_44 -> V_78 > V_79 ) {
T_1 V_104 = V_79 - V_6 -> V_26 ;
memcpy ( & V_102 [ V_6 -> V_26 ] , V_47 ,
V_104 * sizeof( struct V_17 ) ) ;
memcpy ( V_102 , & V_47 [ V_104 ] , ( V_44 -> V_78 - V_104 ) *
sizeof( struct V_17 ) ) ;
} else {
memcpy ( & V_102 [ V_6 -> V_26 ] , V_47 ,
V_44 -> V_78 * sizeof( struct V_17 ) ) ;
}
V_6 -> V_26 += V_44 -> V_78 ;
V_6 -> V_26 %= V_79 ;
F_7 () ;
F_5 ( V_6 -> V_26 * sizeof( struct V_17 ) ,
V_8 -> V_10 + F_60 ( V_6 -> V_11 ) ) ;
}
static void F_61 ( unsigned long V_81 )
{
struct V_7 * V_8 = (struct V_7 * ) V_81 ;
struct V_1 * V_6 ;
unsigned long V_31 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_8 -> V_76 ; V_46 ++ ) {
V_6 = & V_8 -> V_77 [ V_46 ] ;
F_23 ( & V_6 -> V_4 . V_9 , V_31 ) ;
if ( ! F_62 ( & V_6 -> V_4 . V_62 ) && ! V_6 -> V_32 )
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
static void F_65 ( struct V_92 * V_59 )
{
struct V_43 * V_44 = F_2 ( V_59 ,
struct V_43 , V_59 ) ;
F_35 ( V_44 ) ;
}
static struct V_2 * F_66 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
struct V_7 * V_8 = F_2 ( V_108 -> V_109 ,
struct V_7 , V_3 ) ;
unsigned int V_110 ;
if ( V_106 -> V_111 != 1 )
return NULL ;
V_110 = V_106 -> args [ 0 ] ;
if ( V_110 >= V_8 -> V_76 )
return NULL ;
return F_67 ( & ( V_8 -> V_77 [ V_110 ] . V_4 . V_5 ) ) ;
}
static int F_68 ( struct V_7 * V_8 )
{
T_1 V_15 ;
V_15 = F_13 ( V_8 -> V_10 + V_112 ) >> V_113 ;
V_15 &= V_114 ;
if ( V_8 -> V_20 >= V_15 )
return - V_115 ;
V_15 = F_13 ( V_8 -> V_10 + V_116 ) ;
V_8 -> V_76 = V_15 & V_117 ;
V_15 = F_13 ( V_8 -> V_10 + V_118 ) ;
V_15 |= V_119 ;
F_5 ( V_15 , V_8 -> V_10 + V_118 ) ;
V_15 &= ~ V_119 ;
F_5 ( V_15 , V_8 -> V_10 + V_118 ) ;
F_7 () ;
V_15 |= V_120 ;
F_5 ( V_15 , V_8 -> V_10 + V_118 ) ;
F_5 ( V_121 , V_8 -> V_10 + V_101 ) ;
F_5 ( V_122 , V_8 -> V_10 + V_123 ) ;
F_5 ( V_124 | V_125 ,
V_8 -> V_10 + V_126 ) ;
F_5 ( V_127 , V_8 -> V_10 + F_14 ( V_8 -> V_20 ) ) ;
return 0 ;
}
static void F_69 ( struct V_7 * V_8 , struct V_1 * V_6 ,
T_1 V_128 )
{
V_6 -> V_11 = V_128 ;
V_6 -> V_8 = V_8 ;
F_70 ( & V_6 -> V_4 , & V_8 -> V_3 ) ;
V_6 -> V_4 . V_129 = F_65 ;
}
static int F_71 ( struct V_130 * V_131 )
{
struct V_7 * V_8 ;
struct V_132 * V_133 ;
int V_66 , V_46 ;
V_8 = F_72 ( & V_131 -> V_28 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 )
return - V_30 ;
V_8 -> V_28 = & V_131 -> V_28 ;
V_133 = F_73 ( V_131 , V_134 , 0 ) ;
V_8 -> V_10 = F_74 ( & V_131 -> V_28 , V_133 ) ;
if ( F_75 ( V_8 -> V_10 ) )
return F_76 ( V_8 -> V_10 ) ;
V_8 -> V_80 = F_77 ( V_131 , 0 ) ;
if ( V_8 -> V_80 < 0 )
return V_8 -> V_80 ;
V_66 = F_78 ( V_131 -> V_28 . V_135 , L_4 , & V_8 -> V_20 ) ;
if ( V_66 ) {
F_19 ( V_8 -> V_28 , L_5 ) ;
return V_66 ;
}
V_8 -> V_136 = F_79 ( V_8 -> V_28 , L_6 ) ;
if ( F_75 ( V_8 -> V_136 ) )
return F_76 ( V_8 -> V_136 ) ;
V_66 = F_80 ( V_8 -> V_136 ) ;
if ( V_66 ) {
F_19 ( V_8 -> V_28 , L_7 ) ;
return V_66 ;
}
V_66 = F_68 ( V_8 ) ;
if ( V_66 )
goto V_137;
F_81 ( & V_8 -> V_83 , F_61 , ( unsigned long ) V_8 ) ;
V_8 -> V_77 = F_82 ( V_8 -> V_28 , V_8 -> V_76 ,
sizeof( * V_8 -> V_77 ) , V_29 ) ;
if ( ! V_8 -> V_77 ) {
V_66 = - V_30 ;
goto V_137;
}
F_83 ( & V_8 -> V_3 . V_77 ) ;
for ( V_46 = 0 ; V_46 < V_8 -> V_76 ; V_46 ++ )
F_69 ( V_8 , & V_8 -> V_77 [ V_46 ] , V_46 ) ;
V_66 = F_84 ( V_8 -> V_28 , V_8 -> V_80 , F_48 ,
V_138 , L_8 , V_8 ) ;
if ( V_66 )
goto V_137;
V_8 -> V_3 . V_28 = V_8 -> V_28 ;
V_8 -> V_3 . V_28 -> V_139 = & V_8 -> V_139 ;
V_66 = F_85 ( V_8 -> V_3 . V_28 , V_49 ) ;
if ( V_66 ) {
F_19 ( V_8 -> V_28 , L_9 ) ;
goto V_137;
}
F_86 ( V_131 , V_8 ) ;
F_87 ( V_8 -> V_3 . V_140 ) ;
F_88 ( V_141 , V_8 -> V_3 . V_140 ) ;
V_8 -> V_3 . V_142 = F_17 ;
V_8 -> V_3 . V_143 = F_20 ;
V_8 -> V_3 . V_144 = F_27 ;
V_8 -> V_3 . V_145 = F_41 ;
V_8 -> V_3 . V_146 = F_63 ;
V_8 -> V_3 . V_147 = F_51 ;
V_8 -> V_3 . V_28 = V_8 -> V_28 ;
V_66 = F_89 ( & V_8 -> V_3 ) ;
if ( V_66 ) {
F_19 ( V_8 -> V_28 , L_10 ) ;
goto V_137;
}
V_66 = F_90 ( V_131 -> V_28 . V_135 , F_66 ,
& V_8 -> V_3 ) ;
if ( V_66 )
goto V_148;
return 0 ;
V_148:
F_91 ( & V_8 -> V_3 ) ;
V_137:
F_92 ( V_8 -> V_136 ) ;
return V_66 ;
}
static int F_93 ( struct V_130 * V_131 )
{
struct V_7 * V_8 = F_94 ( V_131 ) ;
T_1 V_46 ;
F_95 ( V_131 -> V_28 . V_135 ) ;
F_91 ( & V_8 -> V_3 ) ;
F_5 ( 0 , V_8 -> V_10 + F_14 ( V_8 -> V_20 ) ) ;
F_96 ( V_8 -> V_28 , V_8 -> V_80 , V_8 ) ;
for ( V_46 = 0 ; V_46 < V_8 -> V_76 ; V_46 ++ ) {
F_36 ( & V_8 -> V_77 [ V_46 ] ) ;
F_97 ( & V_8 -> V_77 [ V_46 ] . V_4 . V_83 ) ;
F_25 ( V_8 -> V_28 , V_18 ,
V_8 -> V_77 [ V_46 ] . V_27 ,
V_8 -> V_77 [ V_46 ] . V_16 ) ;
}
F_97 ( & V_8 -> V_83 ) ;
F_92 ( V_8 -> V_136 ) ;
return 0 ;
}
