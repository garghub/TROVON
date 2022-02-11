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
int V_20 = F_8 ( V_3 ) -> V_21 ;
T_2 * V_22 ;
V_22 = & F_8 ( V_3 ) -> V_23 [ V_20 ] ;
V_22 -> V_24 = F_9 ( ( unsigned ) V_25 - V_18 , * V_19 ) ;
V_22 -> V_26 = V_18 ;
V_22 -> V_7 = V_7 ;
V_3 -> V_27 += V_22 -> V_24 ;
V_3 -> V_19 += V_22 -> V_24 ;
F_8 ( V_3 ) -> V_21 ++ ;
* V_19 -= V_22 -> V_24 ;
}
static struct V_2 * F_10 ( struct V_5 * V_6 ,
struct V_7 * V_7 , unsigned int V_19 )
{
struct V_2 * V_3 ;
struct V_1 * V_28 ;
unsigned int V_29 , V_30 , V_18 ;
char * V_12 ;
V_12 = F_11 ( V_7 ) ;
V_3 = F_12 ( V_6 -> V_17 , V_31 ) ;
if ( F_13 ( ! V_3 ) )
return NULL ;
V_28 = V_1 ( V_3 ) ;
if ( V_6 -> V_32 ) {
V_30 = sizeof V_28 -> V_33 ;
V_18 = V_30 ;
} else {
V_30 = sizeof V_28 -> V_28 ;
V_18 = sizeof( struct V_34 ) ;
}
memcpy ( V_28 , V_12 , V_30 ) ;
V_19 -= V_30 ;
V_12 += V_18 ;
V_29 = V_19 ;
if ( V_29 > F_14 ( V_3 ) )
V_29 = F_14 ( V_3 ) ;
memcpy ( F_15 ( V_3 , V_29 ) , V_12 , V_29 ) ;
V_19 -= V_29 ;
V_18 += V_29 ;
while ( V_19 ) {
F_7 ( V_3 , V_7 , V_18 , & V_19 ) ;
V_7 = (struct V_7 * ) V_7 -> V_9 ;
V_18 = 0 ;
}
if ( V_7 )
F_1 ( V_6 , V_7 ) ;
return V_3 ;
}
static int F_16 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_28 = V_1 ( V_3 ) ;
struct V_7 * V_7 ;
int V_35 , V_20 , V_19 ;
V_35 = V_28 -> V_33 . V_36 ;
while ( -- V_35 ) {
V_20 = F_8 ( V_3 ) -> V_21 ;
if ( V_20 >= V_37 ) {
F_17 ( L_1 , V_3 -> V_17 -> V_38 ) ;
V_3 -> V_17 -> V_39 . V_40 ++ ;
return - V_41 ;
}
V_7 = F_18 ( V_6 -> V_42 , & V_19 ) ;
if ( ! V_7 ) {
F_17 ( L_2 ,
V_3 -> V_17 -> V_38 , V_28 -> V_33 . V_36 ) ;
V_3 -> V_17 -> V_39 . V_40 ++ ;
return - V_41 ;
}
if ( V_19 > V_25 )
V_19 = V_25 ;
F_7 ( V_3 , V_7 , 0 , & V_19 ) ;
-- V_6 -> V_43 ;
}
return 0 ;
}
static void F_19 ( struct V_44 * V_17 , void * V_45 , unsigned int V_19 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_46 T_3 * V_39 = F_21 ( V_6 -> V_39 ) ;
struct V_2 * V_3 ;
struct V_7 * V_7 ;
struct V_1 * V_28 ;
if ( F_13 ( V_19 < sizeof( struct V_47 ) + V_48 ) ) {
F_17 ( L_3 , V_17 -> V_38 , V_19 ) ;
V_17 -> V_39 . V_40 ++ ;
if ( V_6 -> V_32 || V_6 -> V_49 )
F_1 ( V_6 , V_45 ) ;
else
F_22 ( V_45 ) ;
return;
}
if ( ! V_6 -> V_32 && ! V_6 -> V_49 ) {
V_3 = V_45 ;
V_19 -= sizeof( struct V_47 ) ;
F_23 ( V_3 , V_19 ) ;
} else {
V_7 = V_45 ;
V_3 = F_10 ( V_6 , V_7 , V_19 ) ;
if ( F_13 ( ! V_3 ) ) {
V_17 -> V_39 . V_50 ++ ;
F_1 ( V_6 , V_7 ) ;
return;
}
if ( V_6 -> V_32 )
if ( F_16 ( V_6 , V_3 ) ) {
F_22 ( V_3 ) ;
return;
}
}
V_28 = V_1 ( V_3 ) ;
V_3 -> V_51 += V_3 -> V_27 ;
F_24 ( & V_39 -> V_52 ) ;
V_39 -> V_53 += V_3 -> V_19 ;
V_39 -> V_54 ++ ;
F_25 ( & V_39 -> V_52 ) ;
if ( V_28 -> V_28 . V_55 & V_56 ) {
F_17 ( L_4 ) ;
if ( ! F_26 ( V_3 ,
V_28 -> V_28 . V_57 ,
V_28 -> V_28 . V_58 ) )
goto V_59;
} else if ( V_28 -> V_28 . V_55 & V_60 ) {
V_3 -> V_61 = V_62 ;
}
V_3 -> V_63 = F_27 ( V_3 , V_17 ) ;
F_17 ( L_5 ,
F_28 ( V_3 -> V_63 ) , V_3 -> V_19 , V_3 -> V_64 ) ;
if ( V_28 -> V_28 . V_65 != V_66 ) {
F_17 ( L_6 ) ;
switch ( V_28 -> V_28 . V_65 & ~ V_67 ) {
case V_68 :
F_8 ( V_3 ) -> V_65 = V_69 ;
break;
case V_70 :
F_8 ( V_3 ) -> V_65 = V_71 ;
break;
case V_72 :
F_8 ( V_3 ) -> V_65 = V_73 ;
break;
default:
if ( F_29 () )
F_30 ( V_74 L_7 ,
V_17 -> V_38 , V_28 -> V_28 . V_65 ) ;
goto V_59;
}
if ( V_28 -> V_28 . V_65 & V_67 )
F_8 ( V_3 ) -> V_65 |= V_75 ;
F_8 ( V_3 ) -> V_76 = V_28 -> V_28 . V_76 ;
if ( F_8 ( V_3 ) -> V_76 == 0 ) {
if ( F_29 () )
F_30 ( V_74 L_8 ,
V_17 -> V_38 ) ;
goto V_59;
}
F_8 ( V_3 ) -> V_65 |= V_77 ;
F_8 ( V_3 ) -> V_78 = 0 ;
}
F_31 ( V_3 ) ;
return;
V_59:
V_17 -> V_39 . V_79 ++ ;
F_22 ( V_3 ) ;
}
static int F_32 ( struct V_5 * V_6 , T_1 V_80 )
{
struct V_2 * V_3 ;
struct V_1 * V_28 ;
int V_81 ;
V_3 = F_12 ( V_6 -> V_17 , V_82 ) ;
if ( F_13 ( ! V_3 ) )
return - V_83 ;
F_15 ( V_3 , V_82 ) ;
V_28 = V_1 ( V_3 ) ;
F_33 ( V_6 -> V_84 , & V_28 -> V_28 , sizeof V_28 -> V_28 ) ;
F_34 ( V_3 , V_6 -> V_84 + 1 , 0 , V_3 -> V_19 ) ;
V_81 = F_35 ( V_6 -> V_42 , V_6 -> V_84 , 0 , 2 , V_3 , V_80 ) ;
if ( V_81 < 0 )
F_22 ( V_3 ) ;
return V_81 ;
}
static int F_36 ( struct V_5 * V_6 , T_1 V_80 )
{
struct V_7 * V_85 , * V_86 = NULL ;
char * V_12 ;
int V_20 , V_81 , V_18 ;
for ( V_20 = V_37 + 1 ; V_20 > 1 ; -- V_20 ) {
V_85 = F_2 ( V_6 , V_80 ) ;
if ( ! V_85 ) {
if ( V_86 )
F_1 ( V_6 , V_86 ) ;
return - V_83 ;
}
F_33 ( & V_6 -> V_84 [ V_20 ] , F_11 ( V_85 ) , V_25 ) ;
V_85 -> V_9 = ( unsigned long ) V_86 ;
V_86 = V_85 ;
}
V_85 = F_2 ( V_6 , V_80 ) ;
if ( ! V_85 ) {
F_1 ( V_6 , V_86 ) ;
return - V_83 ;
}
V_12 = F_11 ( V_85 ) ;
F_33 ( & V_6 -> V_84 [ 0 ] , V_12 , sizeof( struct V_47 ) ) ;
V_18 = sizeof( struct V_34 ) ;
F_33 ( & V_6 -> V_84 [ 1 ] , V_12 + V_18 , V_25 - V_18 ) ;
V_85 -> V_9 = ( unsigned long ) V_86 ;
V_81 = F_35 ( V_6 -> V_42 , V_6 -> V_84 , 0 , V_37 + 2 ,
V_85 , V_80 ) ;
if ( V_81 < 0 )
F_1 ( V_6 , V_85 ) ;
return V_81 ;
}
static int F_37 ( struct V_5 * V_6 , T_1 V_80 )
{
struct V_7 * V_7 ;
int V_81 ;
V_7 = F_2 ( V_6 , V_80 ) ;
if ( ! V_7 )
return - V_83 ;
F_38 ( V_6 -> V_84 , F_11 ( V_7 ) , V_25 ) ;
V_81 = F_35 ( V_6 -> V_42 , V_6 -> V_84 , 0 , 1 , V_7 , V_80 ) ;
if ( V_81 < 0 )
F_1 ( V_6 , V_7 ) ;
return V_81 ;
}
static bool F_39 ( struct V_5 * V_6 , T_1 V_80 )
{
int V_81 ;
bool V_87 ;
do {
if ( V_6 -> V_32 )
V_81 = F_37 ( V_6 , V_80 ) ;
else if ( V_6 -> V_49 )
V_81 = F_36 ( V_6 , V_80 ) ;
else
V_81 = F_32 ( V_6 , V_80 ) ;
V_87 = V_81 == - V_83 ;
if ( V_81 < 0 )
break;
++ V_6 -> V_43 ;
} while ( V_81 > 0 );
if ( F_13 ( V_6 -> V_43 > V_6 -> V_88 ) )
V_6 -> V_88 = V_6 -> V_43 ;
F_40 ( V_6 -> V_42 ) ;
return ! V_87 ;
}
static void F_41 ( struct V_13 * V_42 )
{
struct V_5 * V_6 = V_42 -> V_15 -> V_16 ;
if ( F_42 ( & V_6 -> V_89 ) ) {
F_5 ( V_42 ) ;
F_43 ( & V_6 -> V_89 ) ;
}
}
static void F_44 ( struct V_5 * V_6 )
{
F_45 ( & V_6 -> V_89 ) ;
if ( F_42 ( & V_6 -> V_89 ) ) {
F_5 ( V_6 -> V_42 ) ;
F_43 ( & V_6 -> V_89 ) ;
}
}
static void F_46 ( struct V_90 * V_91 )
{
struct V_5 * V_6 ;
bool V_92 ;
V_6 = F_47 ( V_91 , struct V_5 , V_93 . V_91 ) ;
F_48 ( & V_6 -> V_89 ) ;
V_92 = ! F_39 ( V_6 , V_94 ) ;
F_44 ( V_6 ) ;
if ( V_92 )
F_49 ( & V_6 -> V_93 , V_95 / 2 ) ;
}
static int F_50 ( struct V_96 * V_89 , int V_97 )
{
struct V_5 * V_6 = F_47 ( V_89 , struct V_5 , V_89 ) ;
void * V_45 ;
unsigned int V_19 , V_98 = 0 ;
V_99:
while ( V_98 < V_97 &&
( V_45 = F_18 ( V_6 -> V_42 , & V_19 ) ) != NULL ) {
F_19 ( V_6 -> V_17 , V_45 , V_19 ) ;
-- V_6 -> V_43 ;
V_98 ++ ;
}
if ( V_6 -> V_43 < V_6 -> V_88 / 2 ) {
if ( ! F_39 ( V_6 , V_100 ) )
F_49 ( & V_6 -> V_93 , 0 ) ;
}
if ( V_98 < V_97 ) {
F_51 ( V_89 ) ;
if ( F_13 ( ! F_52 ( V_6 -> V_42 ) ) &&
F_42 ( V_89 ) ) {
F_5 ( V_6 -> V_42 ) ;
F_43 ( V_89 ) ;
goto V_99;
}
}
return V_98 ;
}
static unsigned int F_53 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
unsigned int V_19 , V_101 = 0 ;
struct V_46 T_3 * V_39 = F_21 ( V_6 -> V_39 ) ;
while ( ( V_3 = F_18 ( V_6 -> V_14 , & V_19 ) ) != NULL ) {
F_17 ( L_9 , V_3 ) ;
F_24 ( & V_39 -> V_52 ) ;
V_39 -> V_102 += V_3 -> V_19 ;
V_39 -> V_103 ++ ;
F_25 ( & V_39 -> V_52 ) ;
V_101 += V_1 ( V_3 ) -> V_104 ;
F_54 ( V_3 ) ;
}
return V_101 ;
}
static int F_55 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_28 = V_1 ( V_3 ) ;
const unsigned char * V_105 = ( (struct V_106 * ) V_3 -> V_107 ) -> V_108 ;
F_17 ( L_10 , V_6 -> V_17 -> V_38 , V_3 , V_105 ) ;
if ( V_3 -> V_61 == V_109 ) {
V_28 -> V_28 . V_55 = V_56 ;
V_28 -> V_28 . V_57 = F_56 ( V_3 ) ;
V_28 -> V_28 . V_58 = V_3 -> V_58 ;
} else {
V_28 -> V_28 . V_55 = 0 ;
V_28 -> V_28 . V_58 = V_28 -> V_28 . V_57 = 0 ;
}
if ( F_57 ( V_3 ) ) {
V_28 -> V_28 . V_30 = F_58 ( V_3 ) ;
V_28 -> V_28 . V_76 = F_8 ( V_3 ) -> V_76 ;
if ( F_8 ( V_3 ) -> V_65 & V_69 )
V_28 -> V_28 . V_65 = V_68 ;
else if ( F_8 ( V_3 ) -> V_65 & V_73 )
V_28 -> V_28 . V_65 = V_72 ;
else if ( F_8 ( V_3 ) -> V_65 & V_71 )
V_28 -> V_28 . V_65 = V_70 ;
else
F_59 () ;
if ( F_8 ( V_3 ) -> V_65 & V_75 )
V_28 -> V_28 . V_65 |= V_67 ;
} else {
V_28 -> V_28 . V_65 = V_66 ;
V_28 -> V_28 . V_76 = V_28 -> V_28 . V_30 = 0 ;
}
V_28 -> V_33 . V_36 = 0 ;
if ( V_6 -> V_32 )
F_33 ( V_6 -> V_110 , & V_28 -> V_33 , sizeof V_28 -> V_33 ) ;
else
F_33 ( V_6 -> V_110 , & V_28 -> V_28 , sizeof V_28 -> V_28 ) ;
V_28 -> V_104 = F_34 ( V_3 , V_6 -> V_110 + 1 , 0 , V_3 -> V_19 ) + 1 ;
return F_60 ( V_6 -> V_14 , V_6 -> V_110 , V_28 -> V_104 ,
0 , V_3 ) ;
}
static T_4 F_61 ( struct V_2 * V_3 , struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
int V_111 ;
F_53 ( V_6 ) ;
V_111 = F_55 ( V_6 , V_3 ) ;
if ( F_13 ( V_111 < 0 ) ) {
if ( F_29 () ) {
if ( F_62 ( V_111 == - V_83 ) ) {
F_63 ( & V_17 -> V_17 ,
L_11 ) ;
} else {
V_17 -> V_39 . V_112 ++ ;
F_63 ( & V_17 -> V_17 ,
L_12 ,
V_111 ) ;
}
}
V_17 -> V_39 . V_113 ++ ;
F_64 ( V_3 ) ;
return V_114 ;
}
F_40 ( V_6 -> V_14 ) ;
F_65 ( V_3 ) ;
F_66 ( V_3 ) ;
if ( V_111 < 2 + V_37 ) {
F_67 ( V_17 ) ;
if ( F_13 ( ! F_68 ( V_6 -> V_14 ) ) ) {
V_111 += F_53 ( V_6 ) ;
if ( V_111 >= 2 + V_37 ) {
F_69 ( V_17 ) ;
F_5 ( V_6 -> V_14 ) ;
}
}
}
return V_114 ;
}
static int F_70 ( struct V_44 * V_17 , void * V_12 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_115 * V_15 = V_6 -> V_15 ;
int V_116 ;
V_116 = F_71 ( V_17 , V_12 ) ;
if ( V_116 )
return V_116 ;
if ( F_72 ( V_15 , V_117 ) )
V_15 -> V_118 -> V_119 ( V_15 , F_73 ( struct V_120 , V_121 ) ,
V_17 -> V_122 , V_17 -> V_123 ) ;
return 0 ;
}
static struct V_124 * V_46 ( struct V_44 * V_17 ,
struct V_124 * V_125 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
int V_126 ;
unsigned int V_127 ;
F_74 (cpu) {
struct V_46 T_3 * V_39
= F_75 ( V_6 -> V_39 , V_126 ) ;
T_5 V_128 , V_129 , V_130 , V_131 ;
do {
V_127 = F_76 ( & V_39 -> V_52 ) ;
V_128 = V_39 -> V_103 ;
V_129 = V_39 -> V_102 ;
V_130 = V_39 -> V_54 ;
V_131 = V_39 -> V_53 ;
} while ( F_77 ( & V_39 -> V_52 , V_127 ) );
V_125 -> V_54 += V_130 ;
V_125 -> V_103 += V_128 ;
V_125 -> V_53 += V_131 ;
V_125 -> V_102 += V_129 ;
}
V_125 -> V_113 = V_17 -> V_39 . V_113 ;
V_125 -> V_50 = V_17 -> V_39 . V_50 ;
V_125 -> V_40 = V_17 -> V_39 . V_40 ;
V_125 -> V_79 = V_17 -> V_39 . V_79 ;
return V_125 ;
}
static void F_78 ( struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
F_79 ( & V_6 -> V_89 ) ;
}
static int F_80 ( struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
static bool F_81 ( struct V_5 * V_6 , T_6 V_132 , T_6 V_133 ,
struct V_134 * V_107 , int V_135 , int V_136 )
{
struct V_134 * V_137 , V_138 [ V_139 + 2 ] ;
struct V_140 V_141 ;
T_7 V_142 = ~ 0 ;
unsigned int V_143 ;
int V_20 ;
F_82 ( ! F_72 ( V_6 -> V_15 , V_144 ) ||
( V_135 + V_136 > V_139 ) ) ;
V_135 ++ ;
V_136 ++ ;
V_141 . V_132 = V_132 ;
V_141 . V_133 = V_133 ;
F_83 ( V_138 , V_135 + V_136 ) ;
F_33 ( & V_138 [ 0 ] , & V_141 , sizeof( V_141 ) ) ;
F_84 (data, s, out + in - 2 , i)
F_33 ( & V_138 [ V_20 + 1 ] , F_85 ( V_137 ) , V_137 -> V_145 ) ;
F_33 ( & V_138 [ V_135 + V_136 - 1 ] , & V_142 , sizeof( V_142 ) ) ;
F_82 ( F_60 ( V_6 -> V_146 , V_138 , V_135 , V_136 , V_6 ) < 0 ) ;
F_40 ( V_6 -> V_146 ) ;
while ( ! F_18 ( V_6 -> V_146 , & V_143 ) )
F_86 () ;
return V_142 == V_147 ;
}
static int F_87 ( struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
F_48 ( & V_6 -> V_89 ) ;
return 0 ;
}
static void F_88 ( struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_134 V_138 [ 2 ] ;
T_6 V_148 , V_149 ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
int V_154 ;
int V_155 ;
void * V_45 ;
int V_20 ;
if ( ! F_72 ( V_6 -> V_15 , V_156 ) )
return;
V_148 = ( ( V_17 -> V_55 & V_157 ) != 0 ) ;
V_149 = ( ( V_17 -> V_55 & V_158 ) != 0 ) ;
F_38 ( V_138 , & V_148 , sizeof( V_148 ) ) ;
if ( ! F_81 ( V_6 , V_159 ,
V_160 ,
V_138 , 1 , 0 ) )
F_63 ( & V_17 -> V_17 , L_13 ,
V_148 ? L_14 : L_15 ) ;
F_38 ( V_138 , & V_149 , sizeof( V_149 ) ) ;
if ( ! F_81 ( V_6 , V_159 ,
V_161 ,
V_138 , 1 , 0 ) )
F_63 ( & V_17 -> V_17 , L_16 ,
V_149 ? L_14 : L_15 ) ;
V_154 = F_89 ( V_17 ) ;
V_155 = F_90 ( V_17 ) ;
V_45 = F_91 ( ( ( V_154 + V_155 ) * V_162 ) +
( 2 * sizeof( V_151 -> V_163 ) ) , V_100 ) ;
V_151 = V_45 ;
if ( ! V_45 ) {
F_63 ( & V_17 -> V_17 , L_17 ) ;
return;
}
F_83 ( V_138 , 2 ) ;
V_151 -> V_163 = V_154 ;
V_20 = 0 ;
F_92 (ha, dev)
memcpy ( & V_151 -> V_164 [ V_20 ++ ] [ 0 ] , V_153 -> V_165 , V_162 ) ;
F_33 ( & V_138 [ 0 ] , V_151 ,
sizeof( V_151 -> V_163 ) + ( V_154 * V_162 ) ) ;
V_151 = ( void * ) & V_151 -> V_164 [ V_154 ] [ 0 ] ;
V_151 -> V_163 = V_155 ;
V_20 = 0 ;
F_93 (ha, dev)
memcpy ( & V_151 -> V_164 [ V_20 ++ ] [ 0 ] , V_153 -> V_165 , V_162 ) ;
F_33 ( & V_138 [ 1 ] , V_151 ,
sizeof( V_151 -> V_163 ) + ( V_155 * V_162 ) ) ;
if ( ! F_81 ( V_6 , V_166 ,
V_167 ,
V_138 , 2 , 0 ) )
F_63 ( & V_17 -> V_17 , L_18 ) ;
F_94 ( V_45 ) ;
}
static void F_95 ( struct V_44 * V_17 , T_8 V_168 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_134 V_138 ;
F_38 ( & V_138 , & V_168 , sizeof( V_168 ) ) ;
if ( ! F_81 ( V_6 , V_169 ,
V_170 , & V_138 , 1 , 0 ) )
F_63 ( & V_17 -> V_17 , L_19 , V_168 ) ;
}
static void F_96 ( struct V_44 * V_17 , T_8 V_168 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_134 V_138 ;
F_38 ( & V_138 , & V_168 , sizeof( V_168 ) ) ;
if ( ! F_81 ( V_6 , V_169 ,
V_171 , & V_138 , 1 , 0 ) )
F_63 ( & V_17 -> V_17 , L_20 , V_168 ) ;
}
static int F_97 ( struct V_44 * V_17 , int V_172 )
{
if ( V_172 < V_173 || V_172 > V_174 )
return - V_41 ;
V_17 -> V_175 = V_172 ;
return 0 ;
}
static void F_98 ( struct V_5 * V_6 )
{
T_8 V_176 ;
if ( ! F_72 ( V_6 -> V_15 , V_177 ) )
return;
V_6 -> V_15 -> V_118 -> V_178 ( V_6 -> V_15 ,
F_73 ( struct V_120 , V_142 ) ,
& V_176 , sizeof( V_176 ) ) ;
V_176 &= V_179 ;
if ( V_6 -> V_142 == V_176 )
return;
V_6 -> V_142 = V_176 ;
if ( V_6 -> V_142 & V_179 ) {
F_99 ( V_6 -> V_17 ) ;
F_6 ( V_6 -> V_17 ) ;
} else {
F_100 ( V_6 -> V_17 ) ;
F_67 ( V_6 -> V_17 ) ;
}
}
static void F_101 ( struct V_115 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
F_98 ( V_6 ) ;
}
static int F_102 ( struct V_115 * V_15 )
{
int V_81 ;
struct V_44 * V_17 ;
struct V_5 * V_6 ;
struct V_13 * V_180 [ 3 ] ;
T_9 * V_181 [] = { F_41 , F_4 , NULL } ;
const char * V_182 [] = { L_21 , L_22 , L_23 } ;
int V_183 ;
V_17 = F_103 ( sizeof( struct V_5 ) ) ;
if ( ! V_17 )
return - V_83 ;
V_17 -> V_184 = & V_185 ;
V_17 -> V_186 = V_187 ;
F_104 ( V_17 , & V_188 ) ;
F_105 ( V_17 , & V_15 -> V_17 ) ;
if ( F_72 ( V_15 , V_189 ) ) {
V_17 -> V_190 |= V_191 | V_192 | V_193 ;
if ( V_194 )
V_17 -> V_186 |= V_191 | V_192 | V_193 ;
if ( F_72 ( V_15 , V_195 ) ) {
V_17 -> V_190 |= V_196 | V_197
| V_198 | V_199 ;
}
if ( F_72 ( V_15 , V_200 ) )
V_17 -> V_190 |= V_196 ;
if ( F_72 ( V_15 , V_201 ) )
V_17 -> V_190 |= V_199 ;
if ( F_72 ( V_15 , V_202 ) )
V_17 -> V_190 |= V_198 ;
if ( F_72 ( V_15 , V_203 ) )
V_17 -> V_190 |= V_197 ;
if ( V_204 )
V_17 -> V_186 |= V_17 -> V_190 & ( V_205 | V_197 ) ;
}
if ( F_72 ( V_15 , V_117 ) ) {
V_15 -> V_118 -> V_178 ( V_15 ,
F_73 ( struct V_120 , V_121 ) ,
V_17 -> V_122 , V_17 -> V_123 ) ;
} else
F_106 ( V_17 -> V_122 ) ;
V_6 = F_20 ( V_17 ) ;
F_107 ( V_17 , & V_6 -> V_89 , F_50 , V_206 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_15 = V_15 ;
V_15 -> V_16 = V_6 ;
V_6 -> V_10 = NULL ;
V_6 -> V_39 = F_108 ( struct V_46 ) ;
V_81 = - V_83 ;
if ( V_6 -> V_39 == NULL )
goto free;
F_109 ( & V_6 -> V_93 , F_46 ) ;
F_83 ( V_6 -> V_84 , F_110 ( V_6 -> V_84 ) ) ;
F_83 ( V_6 -> V_110 , F_110 ( V_6 -> V_110 ) ) ;
if ( F_72 ( V_15 , V_207 ) ||
F_72 ( V_15 , V_208 ) ||
F_72 ( V_15 , V_209 ) )
V_6 -> V_49 = true ;
if ( F_72 ( V_15 , V_210 ) )
V_6 -> V_32 = true ;
V_183 = F_72 ( V_6 -> V_15 , V_144 ) ? 3 : 2 ;
V_81 = V_15 -> V_118 -> V_211 ( V_15 , V_183 , V_180 , V_181 , V_182 ) ;
if ( V_81 )
goto V_212;
V_6 -> V_42 = V_180 [ 0 ] ;
V_6 -> V_14 = V_180 [ 1 ] ;
if ( F_72 ( V_6 -> V_15 , V_144 ) ) {
V_6 -> V_146 = V_180 [ 2 ] ;
if ( F_72 ( V_6 -> V_15 , V_213 ) )
V_17 -> V_186 |= V_214 ;
}
V_81 = F_111 ( V_17 ) ;
if ( V_81 ) {
F_17 ( L_24 ) ;
goto V_215;
}
F_39 ( V_6 , V_94 ) ;
if ( V_6 -> V_43 == 0 ) {
V_81 = - V_83 ;
goto V_216;
}
if ( F_72 ( V_6 -> V_15 , V_177 ) ) {
F_100 ( V_17 ) ;
F_98 ( V_6 ) ;
} else {
V_6 -> V_142 = V_179 ;
F_99 ( V_17 ) ;
}
F_17 ( L_25 , V_17 -> V_38 ) ;
return 0 ;
V_216:
F_112 ( V_17 ) ;
F_113 ( & V_6 -> V_93 ) ;
V_215:
V_15 -> V_118 -> V_217 ( V_15 ) ;
V_212:
F_114 ( V_6 -> V_39 ) ;
free:
F_115 ( V_17 ) ;
return V_81 ;
}
static void F_116 ( struct V_5 * V_6 )
{
void * V_45 ;
while ( 1 ) {
V_45 = F_117 ( V_6 -> V_14 ) ;
if ( ! V_45 )
break;
F_22 ( V_45 ) ;
}
while ( 1 ) {
V_45 = F_117 ( V_6 -> V_42 ) ;
if ( ! V_45 )
break;
if ( V_6 -> V_32 || V_6 -> V_49 )
F_1 ( V_6 , V_45 ) ;
else
F_22 ( V_45 ) ;
-- V_6 -> V_43 ;
}
F_82 ( V_6 -> V_43 != 0 ) ;
}
static void T_10 F_118 ( struct V_115 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
V_15 -> V_118 -> V_218 ( V_15 ) ;
F_112 ( V_6 -> V_17 ) ;
F_113 ( & V_6 -> V_93 ) ;
F_116 ( V_6 ) ;
V_15 -> V_118 -> V_217 ( V_6 -> V_15 ) ;
while ( V_6 -> V_10 )
F_119 ( F_2 ( V_6 , V_94 ) , 0 ) ;
F_114 ( V_6 -> V_39 ) ;
F_115 ( V_6 -> V_17 ) ;
}
static int T_11 F_120 ( void )
{
return F_121 ( & V_219 ) ;
}
static void T_12 F_122 ( void )
{
F_123 ( & V_219 ) ;
}
