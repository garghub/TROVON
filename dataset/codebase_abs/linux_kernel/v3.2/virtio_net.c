static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static void F_1 ( struct V_5 * V_6 , struct V_7 * V_7 )
{
struct V_7 * V_8 ;
for ( V_8 = V_7 ; V_8 -> V_9 ; V_8 = (struct V_7 * ) V_8 -> V_9 ) ;
V_8 -> V_9 = ( unsigned long ) V_6 -> V_10 ;
V_6 -> V_10 = V_7 ;
}
static struct V_7 * F_2 ( struct V_5 * V_6 , T_1 V_11 )
{
struct V_7 * V_12 = V_6 -> V_10 ;
if ( V_12 ) {
V_6 -> V_10 = (struct V_7 * ) V_12 -> V_9 ;
V_12 -> V_9 = 0 ;
} else
V_12 = F_3 ( V_11 ) ;
return V_12 ;
}
static void F_4 ( struct V_13 * V_14 )
{
struct V_5 * V_6 = V_14 -> V_15 -> V_16 ;
F_5 ( V_14 ) ;
F_6 ( V_6 -> V_17 ) ;
}
static void F_7 ( struct V_2 * V_3 , struct V_7 * V_7 ,
unsigned int V_18 , unsigned int * V_19 )
{
int V_20 = F_8 ( ( unsigned ) V_21 - V_18 , * V_19 ) ;
int V_22 = F_9 ( V_3 ) -> V_23 ;
F_10 ( V_3 , V_22 , V_7 , V_18 , V_20 ) ;
V_3 -> V_24 += V_20 ;
V_3 -> V_19 += V_20 ;
V_3 -> V_25 += V_21 ;
F_9 ( V_3 ) -> V_23 ++ ;
* V_19 -= V_20 ;
}
static struct V_2 * F_11 ( struct V_5 * V_6 ,
struct V_7 * V_7 , unsigned int V_19 )
{
struct V_2 * V_3 ;
struct V_1 * V_26 ;
unsigned int V_27 , V_28 , V_18 ;
char * V_12 ;
V_12 = F_12 ( V_7 ) ;
V_3 = F_13 ( V_6 -> V_17 , V_29 ) ;
if ( F_14 ( ! V_3 ) )
return NULL ;
V_26 = V_1 ( V_3 ) ;
if ( V_6 -> V_30 ) {
V_28 = sizeof V_26 -> V_31 ;
V_18 = V_28 ;
} else {
V_28 = sizeof V_26 -> V_26 ;
V_18 = sizeof( struct V_32 ) ;
}
memcpy ( V_26 , V_12 , V_28 ) ;
V_19 -= V_28 ;
V_12 += V_18 ;
V_27 = V_19 ;
if ( V_27 > F_15 ( V_3 ) )
V_27 = F_15 ( V_3 ) ;
memcpy ( F_16 ( V_3 , V_27 ) , V_12 , V_27 ) ;
V_19 -= V_27 ;
V_18 += V_27 ;
if ( F_14 ( V_19 > V_33 * V_21 ) ) {
if ( F_17 () )
F_18 ( L_1 , V_3 -> V_17 -> V_34 ) ;
F_19 ( V_3 ) ;
return NULL ;
}
while ( V_19 ) {
F_7 ( V_3 , V_7 , V_18 , & V_19 ) ;
V_7 = (struct V_7 * ) V_7 -> V_9 ;
V_18 = 0 ;
}
if ( V_7 )
F_1 ( V_6 , V_7 ) ;
return V_3 ;
}
static int F_20 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_26 = V_1 ( V_3 ) ;
struct V_7 * V_7 ;
int V_35 , V_22 , V_19 ;
V_35 = V_26 -> V_31 . V_36 ;
while ( -- V_35 ) {
V_22 = F_9 ( V_3 ) -> V_23 ;
if ( V_22 >= V_33 ) {
F_18 ( L_2 , V_3 -> V_17 -> V_34 ) ;
V_3 -> V_17 -> V_37 . V_38 ++ ;
return - V_39 ;
}
V_7 = F_21 ( V_6 -> V_40 , & V_19 ) ;
if ( ! V_7 ) {
F_18 ( L_3 ,
V_3 -> V_17 -> V_34 , V_26 -> V_31 . V_36 ) ;
V_3 -> V_17 -> V_37 . V_38 ++ ;
return - V_39 ;
}
if ( V_19 > V_21 )
V_19 = V_21 ;
F_7 ( V_3 , V_7 , 0 , & V_19 ) ;
-- V_6 -> V_41 ;
}
return 0 ;
}
static void F_22 ( struct V_42 * V_17 , void * V_43 , unsigned int V_19 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_44 T_2 * V_37 = F_24 ( V_6 -> V_37 ) ;
struct V_2 * V_3 ;
struct V_7 * V_7 ;
struct V_1 * V_26 ;
if ( F_14 ( V_19 < sizeof( struct V_45 ) + V_46 ) ) {
F_18 ( L_4 , V_17 -> V_34 , V_19 ) ;
V_17 -> V_37 . V_38 ++ ;
if ( V_6 -> V_30 || V_6 -> V_47 )
F_1 ( V_6 , V_43 ) ;
else
F_19 ( V_43 ) ;
return;
}
if ( ! V_6 -> V_30 && ! V_6 -> V_47 ) {
V_3 = V_43 ;
V_19 -= sizeof( struct V_45 ) ;
F_25 ( V_3 , V_19 ) ;
} else {
V_7 = V_43 ;
V_3 = F_11 ( V_6 , V_7 , V_19 ) ;
if ( F_14 ( ! V_3 ) ) {
V_17 -> V_37 . V_48 ++ ;
F_1 ( V_6 , V_7 ) ;
return;
}
if ( V_6 -> V_30 )
if ( F_20 ( V_6 , V_3 ) ) {
F_19 ( V_3 ) ;
return;
}
}
V_26 = V_1 ( V_3 ) ;
F_26 ( & V_37 -> V_49 ) ;
V_37 -> V_50 += V_3 -> V_19 ;
V_37 -> V_51 ++ ;
F_27 ( & V_37 -> V_49 ) ;
if ( V_26 -> V_26 . V_52 & V_53 ) {
F_18 ( L_5 ) ;
if ( ! F_28 ( V_3 ,
V_26 -> V_26 . V_54 ,
V_26 -> V_26 . V_55 ) )
goto V_56;
} else if ( V_26 -> V_26 . V_52 & V_57 ) {
V_3 -> V_58 = V_59 ;
}
V_3 -> V_60 = F_29 ( V_3 , V_17 ) ;
F_18 ( L_6 ,
F_30 ( V_3 -> V_60 ) , V_3 -> V_19 , V_3 -> V_61 ) ;
if ( V_26 -> V_26 . V_62 != V_63 ) {
F_18 ( L_7 ) ;
switch ( V_26 -> V_26 . V_62 & ~ V_64 ) {
case V_65 :
F_9 ( V_3 ) -> V_62 = V_66 ;
break;
case V_67 :
F_9 ( V_3 ) -> V_62 = V_68 ;
break;
case V_69 :
F_9 ( V_3 ) -> V_62 = V_70 ;
break;
default:
if ( F_17 () )
F_31 ( V_71 L_8 ,
V_17 -> V_34 , V_26 -> V_26 . V_62 ) ;
goto V_56;
}
if ( V_26 -> V_26 . V_62 & V_64 )
F_9 ( V_3 ) -> V_62 |= V_72 ;
F_9 ( V_3 ) -> V_73 = V_26 -> V_26 . V_73 ;
if ( F_9 ( V_3 ) -> V_73 == 0 ) {
if ( F_17 () )
F_31 ( V_71 L_9 ,
V_17 -> V_34 ) ;
goto V_56;
}
F_9 ( V_3 ) -> V_62 |= V_74 ;
F_9 ( V_3 ) -> V_75 = 0 ;
}
F_32 ( V_3 ) ;
return;
V_56:
V_17 -> V_37 . V_76 ++ ;
F_19 ( V_3 ) ;
}
static int F_33 ( struct V_5 * V_6 , T_1 V_77 )
{
struct V_2 * V_3 ;
struct V_1 * V_26 ;
int V_78 ;
V_3 = F_13 ( V_6 -> V_17 , V_79 ) ;
if ( F_14 ( ! V_3 ) )
return - V_80 ;
F_16 ( V_3 , V_79 ) ;
V_26 = V_1 ( V_3 ) ;
F_34 ( V_6 -> V_81 , & V_26 -> V_26 , sizeof V_26 -> V_26 ) ;
F_35 ( V_3 , V_6 -> V_81 + 1 , 0 , V_3 -> V_19 ) ;
V_78 = F_36 ( V_6 -> V_40 , V_6 -> V_81 , 0 , 2 , V_3 , V_77 ) ;
if ( V_78 < 0 )
F_19 ( V_3 ) ;
return V_78 ;
}
static int F_37 ( struct V_5 * V_6 , T_1 V_77 )
{
struct V_7 * V_82 , * V_83 = NULL ;
char * V_12 ;
int V_22 , V_78 , V_18 ;
for ( V_22 = V_33 + 1 ; V_22 > 1 ; -- V_22 ) {
V_82 = F_2 ( V_6 , V_77 ) ;
if ( ! V_82 ) {
if ( V_83 )
F_1 ( V_6 , V_83 ) ;
return - V_80 ;
}
F_34 ( & V_6 -> V_81 [ V_22 ] , F_12 ( V_82 ) , V_21 ) ;
V_82 -> V_9 = ( unsigned long ) V_83 ;
V_83 = V_82 ;
}
V_82 = F_2 ( V_6 , V_77 ) ;
if ( ! V_82 ) {
F_1 ( V_6 , V_83 ) ;
return - V_80 ;
}
V_12 = F_12 ( V_82 ) ;
F_34 ( & V_6 -> V_81 [ 0 ] , V_12 , sizeof( struct V_45 ) ) ;
V_18 = sizeof( struct V_32 ) ;
F_34 ( & V_6 -> V_81 [ 1 ] , V_12 + V_18 , V_21 - V_18 ) ;
V_82 -> V_9 = ( unsigned long ) V_83 ;
V_78 = F_36 ( V_6 -> V_40 , V_6 -> V_81 , 0 , V_33 + 2 ,
V_82 , V_77 ) ;
if ( V_78 < 0 )
F_1 ( V_6 , V_82 ) ;
return V_78 ;
}
static int F_38 ( struct V_5 * V_6 , T_1 V_77 )
{
struct V_7 * V_7 ;
int V_78 ;
V_7 = F_2 ( V_6 , V_77 ) ;
if ( ! V_7 )
return - V_80 ;
F_39 ( V_6 -> V_81 , F_12 ( V_7 ) , V_21 ) ;
V_78 = F_36 ( V_6 -> V_40 , V_6 -> V_81 , 0 , 1 , V_7 , V_77 ) ;
if ( V_78 < 0 )
F_1 ( V_6 , V_7 ) ;
return V_78 ;
}
static bool F_40 ( struct V_5 * V_6 , T_1 V_77 )
{
int V_78 ;
bool V_84 ;
do {
if ( V_6 -> V_30 )
V_78 = F_38 ( V_6 , V_77 ) ;
else if ( V_6 -> V_47 )
V_78 = F_37 ( V_6 , V_77 ) ;
else
V_78 = F_33 ( V_6 , V_77 ) ;
V_84 = V_78 == - V_80 ;
if ( V_78 < 0 )
break;
++ V_6 -> V_41 ;
} while ( V_78 > 0 );
if ( F_14 ( V_6 -> V_41 > V_6 -> V_85 ) )
V_6 -> V_85 = V_6 -> V_41 ;
F_41 ( V_6 -> V_40 ) ;
return ! V_84 ;
}
static void F_42 ( struct V_13 * V_40 )
{
struct V_5 * V_6 = V_40 -> V_15 -> V_16 ;
if ( F_43 ( & V_6 -> V_86 ) ) {
F_5 ( V_40 ) ;
F_44 ( & V_6 -> V_86 ) ;
}
}
static void F_45 ( struct V_5 * V_6 )
{
F_46 ( & V_6 -> V_86 ) ;
if ( F_43 ( & V_6 -> V_86 ) ) {
F_5 ( V_6 -> V_40 ) ;
F_44 ( & V_6 -> V_86 ) ;
}
}
static void F_47 ( struct V_87 * V_88 )
{
struct V_5 * V_6 ;
bool V_89 ;
V_6 = F_48 ( V_88 , struct V_5 , V_90 . V_88 ) ;
F_49 ( & V_6 -> V_86 ) ;
V_89 = ! F_40 ( V_6 , V_91 ) ;
F_45 ( V_6 ) ;
if ( V_89 )
F_50 ( & V_6 -> V_90 , V_92 / 2 ) ;
}
static int F_51 ( struct V_93 * V_86 , int V_94 )
{
struct V_5 * V_6 = F_48 ( V_86 , struct V_5 , V_86 ) ;
void * V_43 ;
unsigned int V_19 , V_95 = 0 ;
V_96:
while ( V_95 < V_94 &&
( V_43 = F_21 ( V_6 -> V_40 , & V_19 ) ) != NULL ) {
F_22 ( V_6 -> V_17 , V_43 , V_19 ) ;
-- V_6 -> V_41 ;
V_95 ++ ;
}
if ( V_6 -> V_41 < V_6 -> V_85 / 2 ) {
if ( ! F_40 ( V_6 , V_97 ) )
F_50 ( & V_6 -> V_90 , 0 ) ;
}
if ( V_95 < V_94 ) {
F_52 ( V_86 ) ;
if ( F_14 ( ! F_53 ( V_6 -> V_40 ) ) &&
F_43 ( V_86 ) ) {
F_5 ( V_6 -> V_40 ) ;
F_44 ( V_86 ) ;
goto V_96;
}
}
return V_95 ;
}
static unsigned int F_54 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
unsigned int V_19 , V_98 = 0 ;
struct V_44 T_2 * V_37 = F_24 ( V_6 -> V_37 ) ;
while ( ( V_3 = F_21 ( V_6 -> V_14 , & V_19 ) ) != NULL ) {
F_18 ( L_10 , V_3 ) ;
F_26 ( & V_37 -> V_49 ) ;
V_37 -> V_99 += V_3 -> V_19 ;
V_37 -> V_100 ++ ;
F_27 ( & V_37 -> V_49 ) ;
V_98 += V_1 ( V_3 ) -> V_101 ;
F_55 ( V_3 ) ;
}
return V_98 ;
}
static int F_56 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_26 = V_1 ( V_3 ) ;
const unsigned char * V_102 = ( (struct V_103 * ) V_3 -> V_104 ) -> V_105 ;
F_18 ( L_11 , V_6 -> V_17 -> V_34 , V_3 , V_102 ) ;
if ( V_3 -> V_58 == V_106 ) {
V_26 -> V_26 . V_52 = V_53 ;
V_26 -> V_26 . V_54 = F_57 ( V_3 ) ;
V_26 -> V_26 . V_55 = V_3 -> V_55 ;
} else {
V_26 -> V_26 . V_52 = 0 ;
V_26 -> V_26 . V_55 = V_26 -> V_26 . V_54 = 0 ;
}
if ( F_58 ( V_3 ) ) {
V_26 -> V_26 . V_28 = F_59 ( V_3 ) ;
V_26 -> V_26 . V_73 = F_9 ( V_3 ) -> V_73 ;
if ( F_9 ( V_3 ) -> V_62 & V_66 )
V_26 -> V_26 . V_62 = V_65 ;
else if ( F_9 ( V_3 ) -> V_62 & V_70 )
V_26 -> V_26 . V_62 = V_69 ;
else if ( F_9 ( V_3 ) -> V_62 & V_68 )
V_26 -> V_26 . V_62 = V_67 ;
else
F_60 () ;
if ( F_9 ( V_3 ) -> V_62 & V_72 )
V_26 -> V_26 . V_62 |= V_64 ;
} else {
V_26 -> V_26 . V_62 = V_63 ;
V_26 -> V_26 . V_73 = V_26 -> V_26 . V_28 = 0 ;
}
V_26 -> V_31 . V_36 = 0 ;
if ( V_6 -> V_30 )
F_34 ( V_6 -> V_107 , & V_26 -> V_31 , sizeof V_26 -> V_31 ) ;
else
F_34 ( V_6 -> V_107 , & V_26 -> V_26 , sizeof V_26 -> V_26 ) ;
V_26 -> V_101 = F_35 ( V_3 , V_6 -> V_107 + 1 , 0 , V_3 -> V_19 ) + 1 ;
return F_61 ( V_6 -> V_14 , V_6 -> V_107 , V_26 -> V_101 ,
0 , V_3 ) ;
}
static T_3 F_62 ( struct V_2 * V_3 , struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
int V_108 ;
F_54 ( V_6 ) ;
V_108 = F_56 ( V_6 , V_3 ) ;
if ( F_14 ( V_108 < 0 ) ) {
if ( F_17 () ) {
if ( F_63 ( V_108 == - V_80 ) ) {
F_64 ( & V_17 -> V_17 ,
L_12 ) ;
} else {
V_17 -> V_37 . V_109 ++ ;
F_64 ( & V_17 -> V_17 ,
L_13 ,
V_108 ) ;
}
}
V_17 -> V_37 . V_110 ++ ;
F_65 ( V_3 ) ;
return V_111 ;
}
F_41 ( V_6 -> V_14 ) ;
F_66 ( V_3 ) ;
F_67 ( V_3 ) ;
if ( V_108 < 2 + V_33 ) {
F_68 ( V_17 ) ;
if ( F_14 ( ! F_69 ( V_6 -> V_14 ) ) ) {
V_108 += F_54 ( V_6 ) ;
if ( V_108 >= 2 + V_33 ) {
F_70 ( V_17 ) ;
F_5 ( V_6 -> V_14 ) ;
}
}
}
return V_111 ;
}
static int F_71 ( struct V_42 * V_17 , void * V_12 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_112 * V_15 = V_6 -> V_15 ;
int V_113 ;
V_113 = F_72 ( V_17 , V_12 ) ;
if ( V_113 )
return V_113 ;
if ( F_73 ( V_15 , V_114 ) )
V_15 -> V_115 -> V_116 ( V_15 , F_74 ( struct V_117 , V_118 ) ,
V_17 -> V_119 , V_17 -> V_120 ) ;
return 0 ;
}
static struct V_121 * V_44 ( struct V_42 * V_17 ,
struct V_121 * V_122 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
int V_123 ;
unsigned int V_124 ;
F_75 (cpu) {
struct V_44 T_2 * V_37
= F_76 ( V_6 -> V_37 , V_123 ) ;
T_4 V_125 , V_126 , V_127 , V_128 ;
do {
V_124 = F_77 ( & V_37 -> V_49 ) ;
V_125 = V_37 -> V_100 ;
V_126 = V_37 -> V_99 ;
V_127 = V_37 -> V_51 ;
V_128 = V_37 -> V_50 ;
} while ( F_78 ( & V_37 -> V_49 , V_124 ) );
V_122 -> V_51 += V_127 ;
V_122 -> V_100 += V_125 ;
V_122 -> V_50 += V_128 ;
V_122 -> V_99 += V_126 ;
}
V_122 -> V_110 = V_17 -> V_37 . V_110 ;
V_122 -> V_48 = V_17 -> V_37 . V_48 ;
V_122 -> V_38 = V_17 -> V_37 . V_38 ;
V_122 -> V_76 = V_17 -> V_37 . V_76 ;
return V_122 ;
}
static void F_79 ( struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
F_80 ( & V_6 -> V_86 ) ;
}
static int F_81 ( struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
F_45 ( V_6 ) ;
return 0 ;
}
static bool F_82 ( struct V_5 * V_6 , T_5 V_129 , T_5 V_130 ,
struct V_131 * V_104 , int V_132 , int V_133 )
{
struct V_131 * V_134 , V_135 [ V_136 + 2 ] ;
struct V_137 V_138 ;
T_6 V_139 = ~ 0 ;
unsigned int V_140 ;
int V_22 ;
F_83 ( ! F_73 ( V_6 -> V_15 , V_141 ) ||
( V_132 + V_133 > V_136 ) ) ;
V_132 ++ ;
V_133 ++ ;
V_138 . V_129 = V_129 ;
V_138 . V_130 = V_130 ;
F_84 ( V_135 , V_132 + V_133 ) ;
F_34 ( & V_135 [ 0 ] , & V_138 , sizeof( V_138 ) ) ;
F_85 (data, s, out + in - 2 , i)
F_34 ( & V_135 [ V_22 + 1 ] , F_86 ( V_134 ) , V_134 -> V_142 ) ;
F_34 ( & V_135 [ V_132 + V_133 - 1 ] , & V_139 , sizeof( V_139 ) ) ;
F_83 ( F_61 ( V_6 -> V_143 , V_135 , V_132 , V_133 , V_6 ) < 0 ) ;
F_41 ( V_6 -> V_143 ) ;
while ( ! F_21 ( V_6 -> V_143 , & V_140 ) )
F_87 () ;
return V_139 == V_144 ;
}
static int F_88 ( struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
F_49 ( & V_6 -> V_86 ) ;
return 0 ;
}
static void F_89 ( struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_131 V_135 [ 2 ] ;
T_5 V_145 , V_146 ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
int V_151 ;
int V_152 ;
void * V_43 ;
int V_22 ;
if ( ! F_73 ( V_6 -> V_15 , V_153 ) )
return;
V_145 = ( ( V_17 -> V_52 & V_154 ) != 0 ) ;
V_146 = ( ( V_17 -> V_52 & V_155 ) != 0 ) ;
F_39 ( V_135 , & V_145 , sizeof( V_145 ) ) ;
if ( ! F_82 ( V_6 , V_156 ,
V_157 ,
V_135 , 1 , 0 ) )
F_64 ( & V_17 -> V_17 , L_14 ,
V_145 ? L_15 : L_16 ) ;
F_39 ( V_135 , & V_146 , sizeof( V_146 ) ) ;
if ( ! F_82 ( V_6 , V_156 ,
V_158 ,
V_135 , 1 , 0 ) )
F_64 ( & V_17 -> V_17 , L_17 ,
V_146 ? L_15 : L_16 ) ;
V_151 = F_90 ( V_17 ) ;
V_152 = F_91 ( V_17 ) ;
V_43 = F_92 ( ( ( V_151 + V_152 ) * V_159 ) +
( 2 * sizeof( V_148 -> V_160 ) ) , V_97 ) ;
V_148 = V_43 ;
if ( ! V_43 ) {
F_64 ( & V_17 -> V_17 , L_18 ) ;
return;
}
F_84 ( V_135 , 2 ) ;
V_148 -> V_160 = V_151 ;
V_22 = 0 ;
F_93 (ha, dev)
memcpy ( & V_148 -> V_161 [ V_22 ++ ] [ 0 ] , V_150 -> V_162 , V_159 ) ;
F_34 ( & V_135 [ 0 ] , V_148 ,
sizeof( V_148 -> V_160 ) + ( V_151 * V_159 ) ) ;
V_148 = ( void * ) & V_148 -> V_161 [ V_151 ] [ 0 ] ;
V_148 -> V_160 = V_152 ;
V_22 = 0 ;
F_94 (ha, dev)
memcpy ( & V_148 -> V_161 [ V_22 ++ ] [ 0 ] , V_150 -> V_162 , V_159 ) ;
F_34 ( & V_135 [ 1 ] , V_148 ,
sizeof( V_148 -> V_160 ) + ( V_152 * V_159 ) ) ;
if ( ! F_82 ( V_6 , V_163 ,
V_164 ,
V_135 , 2 , 0 ) )
F_64 ( & V_17 -> V_17 , L_19 ) ;
F_95 ( V_43 ) ;
}
static void F_96 ( struct V_42 * V_17 , T_7 V_165 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_131 V_135 ;
F_39 ( & V_135 , & V_165 , sizeof( V_165 ) ) ;
if ( ! F_82 ( V_6 , V_166 ,
V_167 , & V_135 , 1 , 0 ) )
F_64 ( & V_17 -> V_17 , L_20 , V_165 ) ;
}
static void F_97 ( struct V_42 * V_17 , T_7 V_165 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_131 V_135 ;
F_39 ( & V_135 , & V_165 , sizeof( V_165 ) ) ;
if ( ! F_82 ( V_6 , V_166 ,
V_168 , & V_135 , 1 , 0 ) )
F_64 ( & V_17 -> V_17 , L_21 , V_165 ) ;
}
static void F_98 ( struct V_42 * V_17 ,
struct V_169 * V_170 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
V_170 -> V_171 = F_99 ( V_6 -> V_40 ) ;
V_170 -> V_172 = F_99 ( V_6 -> V_14 ) ;
V_170 -> V_173 = V_170 -> V_171 ;
V_170 -> V_174 = V_170 -> V_172 ;
}
static int F_100 ( struct V_42 * V_17 , int V_175 )
{
if ( V_175 < V_176 || V_175 > V_177 )
return - V_39 ;
V_17 -> V_178 = V_175 ;
return 0 ;
}
static void F_101 ( struct V_5 * V_6 )
{
T_7 V_179 ;
if ( F_102 ( V_6 -> V_15 , V_180 ,
F_74 ( struct V_117 , V_139 ) ,
& V_179 ) < 0 )
return;
V_179 &= V_181 ;
if ( V_6 -> V_139 == V_179 )
return;
V_6 -> V_139 = V_179 ;
if ( V_6 -> V_139 & V_181 ) {
F_103 ( V_6 -> V_17 ) ;
F_6 ( V_6 -> V_17 ) ;
} else {
F_104 ( V_6 -> V_17 ) ;
F_68 ( V_6 -> V_17 ) ;
}
}
static void F_105 ( struct V_112 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
F_101 ( V_6 ) ;
}
static int F_106 ( struct V_112 * V_15 )
{
int V_78 ;
struct V_42 * V_17 ;
struct V_5 * V_6 ;
struct V_13 * V_182 [ 3 ] ;
T_8 * V_183 [] = { F_42 , F_4 , NULL } ;
const char * V_184 [] = { L_22 , L_23 , L_24 } ;
int V_185 ;
V_17 = F_107 ( sizeof( struct V_5 ) ) ;
if ( ! V_17 )
return - V_80 ;
V_17 -> V_186 |= V_187 ;
V_17 -> V_188 = & V_189 ;
V_17 -> V_190 = V_191 ;
F_108 ( V_17 , & V_192 ) ;
F_109 ( V_17 , & V_15 -> V_17 ) ;
if ( F_73 ( V_15 , V_193 ) ) {
V_17 -> V_194 |= V_195 | V_196 | V_197 ;
if ( V_198 )
V_17 -> V_190 |= V_195 | V_196 | V_197 ;
if ( F_73 ( V_15 , V_199 ) ) {
V_17 -> V_194 |= V_200 | V_201
| V_202 | V_203 ;
}
if ( F_73 ( V_15 , V_204 ) )
V_17 -> V_194 |= V_200 ;
if ( F_73 ( V_15 , V_205 ) )
V_17 -> V_194 |= V_203 ;
if ( F_73 ( V_15 , V_206 ) )
V_17 -> V_194 |= V_202 ;
if ( F_73 ( V_15 , V_207 ) )
V_17 -> V_194 |= V_201 ;
if ( V_208 )
V_17 -> V_190 |= V_17 -> V_194 & ( V_209 | V_201 ) ;
}
if ( F_110 ( V_15 , V_114 ,
F_74 ( struct V_117 , V_118 ) ,
V_17 -> V_119 , V_17 -> V_120 ) < 0 )
F_111 ( V_17 -> V_119 ) ;
V_6 = F_23 ( V_17 ) ;
F_112 ( V_17 , & V_6 -> V_86 , F_51 , V_210 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_15 = V_15 ;
V_15 -> V_16 = V_6 ;
V_6 -> V_10 = NULL ;
V_6 -> V_37 = F_113 ( struct V_44 ) ;
V_78 = - V_80 ;
if ( V_6 -> V_37 == NULL )
goto free;
F_114 ( & V_6 -> V_90 , F_47 ) ;
F_84 ( V_6 -> V_81 , F_115 ( V_6 -> V_81 ) ) ;
F_84 ( V_6 -> V_107 , F_115 ( V_6 -> V_107 ) ) ;
if ( F_73 ( V_15 , V_211 ) ||
F_73 ( V_15 , V_212 ) ||
F_73 ( V_15 , V_213 ) )
V_6 -> V_47 = true ;
if ( F_73 ( V_15 , V_214 ) )
V_6 -> V_30 = true ;
V_185 = F_73 ( V_6 -> V_15 , V_141 ) ? 3 : 2 ;
V_78 = V_15 -> V_115 -> V_215 ( V_15 , V_185 , V_182 , V_183 , V_184 ) ;
if ( V_78 )
goto V_216;
V_6 -> V_40 = V_182 [ 0 ] ;
V_6 -> V_14 = V_182 [ 1 ] ;
if ( F_73 ( V_6 -> V_15 , V_141 ) ) {
V_6 -> V_143 = V_182 [ 2 ] ;
if ( F_73 ( V_6 -> V_15 , V_217 ) )
V_17 -> V_190 |= V_218 ;
}
V_78 = F_116 ( V_17 ) ;
if ( V_78 ) {
F_18 ( L_25 ) ;
goto V_219;
}
F_40 ( V_6 , V_91 ) ;
if ( V_6 -> V_41 == 0 ) {
V_78 = - V_80 ;
goto V_220;
}
if ( F_73 ( V_6 -> V_15 , V_180 ) ) {
F_104 ( V_17 ) ;
F_101 ( V_6 ) ;
} else {
V_6 -> V_139 = V_181 ;
F_103 ( V_17 ) ;
}
F_18 ( L_26 , V_17 -> V_34 ) ;
return 0 ;
V_220:
F_117 ( V_17 ) ;
F_118 ( & V_6 -> V_90 ) ;
V_219:
V_15 -> V_115 -> V_221 ( V_15 ) ;
V_216:
F_119 ( V_6 -> V_37 ) ;
free:
F_120 ( V_17 ) ;
return V_78 ;
}
static void F_121 ( struct V_5 * V_6 )
{
void * V_43 ;
while ( 1 ) {
V_43 = F_122 ( V_6 -> V_14 ) ;
if ( ! V_43 )
break;
F_19 ( V_43 ) ;
}
while ( 1 ) {
V_43 = F_122 ( V_6 -> V_40 ) ;
if ( ! V_43 )
break;
if ( V_6 -> V_30 || V_6 -> V_47 )
F_1 ( V_6 , V_43 ) ;
else
F_19 ( V_43 ) ;
-- V_6 -> V_41 ;
}
F_83 ( V_6 -> V_41 != 0 ) ;
}
static void T_9 F_123 ( struct V_112 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
V_15 -> V_115 -> V_222 ( V_15 ) ;
F_117 ( V_6 -> V_17 ) ;
F_118 ( & V_6 -> V_90 ) ;
F_121 ( V_6 ) ;
V_15 -> V_115 -> V_221 ( V_6 -> V_15 ) ;
while ( V_6 -> V_10 )
F_124 ( F_2 ( V_6 , V_91 ) , 0 ) ;
F_119 ( V_6 -> V_37 ) ;
F_120 ( V_6 -> V_17 ) ;
}
static int T_10 F_125 ( void )
{
return F_126 ( & V_223 ) ;
}
static void T_11 F_127 ( void )
{
F_128 ( & V_223 ) ;
}
