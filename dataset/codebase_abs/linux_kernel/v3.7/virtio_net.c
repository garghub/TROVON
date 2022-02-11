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
struct V_44 * V_37 = F_24 ( V_6 -> V_37 ) ;
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
V_3 = F_34 ( V_6 -> V_17 , V_79 , V_77 ) ;
if ( F_14 ( ! V_3 ) )
return - V_80 ;
F_16 ( V_3 , V_79 ) ;
V_26 = V_1 ( V_3 ) ;
F_35 ( V_6 -> V_81 , & V_26 -> V_26 , sizeof V_26 -> V_26 ) ;
F_36 ( V_3 , V_6 -> V_81 + 1 , 0 , V_3 -> V_19 ) ;
V_78 = F_37 ( V_6 -> V_40 , V_6 -> V_81 , 0 , 2 , V_3 , V_77 ) ;
if ( V_78 < 0 )
F_19 ( V_3 ) ;
return V_78 ;
}
static int F_38 ( struct V_5 * V_6 , T_1 V_77 )
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
F_35 ( & V_6 -> V_81 [ V_22 ] , F_12 ( V_82 ) , V_21 ) ;
V_82 -> V_9 = ( unsigned long ) V_83 ;
V_83 = V_82 ;
}
V_82 = F_2 ( V_6 , V_77 ) ;
if ( ! V_82 ) {
F_1 ( V_6 , V_83 ) ;
return - V_80 ;
}
V_12 = F_12 ( V_82 ) ;
F_35 ( & V_6 -> V_81 [ 0 ] , V_12 , sizeof( struct V_45 ) ) ;
V_18 = sizeof( struct V_32 ) ;
F_35 ( & V_6 -> V_81 [ 1 ] , V_12 + V_18 , V_21 - V_18 ) ;
V_82 -> V_9 = ( unsigned long ) V_83 ;
V_78 = F_37 ( V_6 -> V_40 , V_6 -> V_81 , 0 , V_33 + 2 ,
V_82 , V_77 ) ;
if ( V_78 < 0 )
F_1 ( V_6 , V_82 ) ;
return V_78 ;
}
static int F_39 ( struct V_5 * V_6 , T_1 V_77 )
{
struct V_7 * V_7 ;
int V_78 ;
V_7 = F_2 ( V_6 , V_77 ) ;
if ( ! V_7 )
return - V_80 ;
F_40 ( V_6 -> V_81 , F_12 ( V_7 ) , V_21 ) ;
V_78 = F_37 ( V_6 -> V_40 , V_6 -> V_81 , 0 , 1 , V_7 , V_77 ) ;
if ( V_78 < 0 )
F_1 ( V_6 , V_7 ) ;
return V_78 ;
}
static bool F_41 ( struct V_5 * V_6 , T_1 V_77 )
{
int V_78 ;
bool V_84 ;
do {
if ( V_6 -> V_30 )
V_78 = F_39 ( V_6 , V_77 ) ;
else if ( V_6 -> V_47 )
V_78 = F_38 ( V_6 , V_77 ) ;
else
V_78 = F_33 ( V_6 , V_77 ) ;
V_84 = V_78 == - V_80 ;
if ( V_78 < 0 )
break;
++ V_6 -> V_41 ;
} while ( V_78 > 0 );
if ( F_14 ( V_6 -> V_41 > V_6 -> V_85 ) )
V_6 -> V_85 = V_6 -> V_41 ;
F_42 ( V_6 -> V_40 ) ;
return ! V_84 ;
}
static void F_43 ( struct V_13 * V_40 )
{
struct V_5 * V_6 = V_40 -> V_15 -> V_16 ;
if ( F_44 ( & V_6 -> V_86 ) ) {
F_5 ( V_40 ) ;
F_45 ( & V_6 -> V_86 ) ;
}
}
static void F_46 ( struct V_5 * V_6 )
{
F_47 ( & V_6 -> V_86 ) ;
if ( F_44 ( & V_6 -> V_86 ) ) {
F_5 ( V_6 -> V_40 ) ;
F_48 () ;
F_45 ( & V_6 -> V_86 ) ;
F_49 () ;
}
}
static void F_50 ( struct V_87 * V_88 )
{
struct V_5 * V_6 ;
bool V_89 ;
V_6 = F_51 ( V_88 , struct V_5 , V_90 . V_88 ) ;
F_52 ( & V_6 -> V_86 ) ;
V_89 = ! F_41 ( V_6 , V_91 ) ;
F_46 ( V_6 ) ;
if ( V_89 )
F_53 ( & V_6 -> V_90 , V_92 / 2 ) ;
}
static int F_54 ( struct V_93 * V_86 , int V_94 )
{
struct V_5 * V_6 = F_51 ( V_86 , struct V_5 , V_86 ) ;
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
if ( ! F_41 ( V_6 , V_97 ) )
F_53 ( & V_6 -> V_90 , 0 ) ;
}
if ( V_95 < V_94 ) {
F_55 ( V_86 ) ;
if ( F_14 ( ! F_56 ( V_6 -> V_40 ) ) &&
F_44 ( V_86 ) ) {
F_5 ( V_6 -> V_40 ) ;
F_45 ( V_86 ) ;
goto V_96;
}
}
return V_95 ;
}
static unsigned int F_57 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
unsigned int V_19 , V_98 = 0 ;
struct V_44 * V_37 = F_24 ( V_6 -> V_37 ) ;
while ( ( V_3 = F_21 ( V_6 -> V_14 , & V_19 ) ) != NULL ) {
F_18 ( L_10 , V_3 ) ;
F_26 ( & V_37 -> V_99 ) ;
V_37 -> V_100 += V_3 -> V_19 ;
V_37 -> V_101 ++ ;
F_27 ( & V_37 -> V_99 ) ;
V_98 += V_1 ( V_3 ) -> V_102 ;
F_58 ( V_3 ) ;
}
return V_98 ;
}
static int F_59 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_26 = V_1 ( V_3 ) ;
const unsigned char * V_103 = ( (struct V_104 * ) V_3 -> V_105 ) -> V_106 ;
F_18 ( L_11 , V_6 -> V_17 -> V_34 , V_3 , V_103 ) ;
if ( V_3 -> V_58 == V_107 ) {
V_26 -> V_26 . V_52 = V_53 ;
V_26 -> V_26 . V_54 = F_60 ( V_3 ) ;
V_26 -> V_26 . V_55 = V_3 -> V_55 ;
} else {
V_26 -> V_26 . V_52 = 0 ;
V_26 -> V_26 . V_55 = V_26 -> V_26 . V_54 = 0 ;
}
if ( F_61 ( V_3 ) ) {
V_26 -> V_26 . V_28 = F_62 ( V_3 ) ;
V_26 -> V_26 . V_73 = F_9 ( V_3 ) -> V_73 ;
if ( F_9 ( V_3 ) -> V_62 & V_66 )
V_26 -> V_26 . V_62 = V_65 ;
else if ( F_9 ( V_3 ) -> V_62 & V_70 )
V_26 -> V_26 . V_62 = V_69 ;
else if ( F_9 ( V_3 ) -> V_62 & V_68 )
V_26 -> V_26 . V_62 = V_67 ;
else
F_63 () ;
if ( F_9 ( V_3 ) -> V_62 & V_72 )
V_26 -> V_26 . V_62 |= V_64 ;
} else {
V_26 -> V_26 . V_62 = V_63 ;
V_26 -> V_26 . V_73 = V_26 -> V_26 . V_28 = 0 ;
}
V_26 -> V_31 . V_36 = 0 ;
if ( V_6 -> V_30 )
F_35 ( V_6 -> V_108 , & V_26 -> V_31 , sizeof V_26 -> V_31 ) ;
else
F_35 ( V_6 -> V_108 , & V_26 -> V_26 , sizeof V_26 -> V_26 ) ;
V_26 -> V_102 = F_36 ( V_3 , V_6 -> V_108 + 1 , 0 , V_3 -> V_19 ) + 1 ;
return F_37 ( V_6 -> V_14 , V_6 -> V_108 , V_26 -> V_102 ,
0 , V_3 , V_97 ) ;
}
static T_2 F_64 ( struct V_2 * V_3 , struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
int V_109 ;
F_57 ( V_6 ) ;
V_109 = F_59 ( V_6 , V_3 ) ;
if ( F_14 ( V_109 < 0 ) ) {
if ( F_65 ( V_109 == - V_80 ) ) {
if ( F_17 () )
F_66 ( & V_17 -> V_17 ,
L_12 ) ;
} else {
V_17 -> V_37 . V_110 ++ ;
if ( F_17 () )
F_66 ( & V_17 -> V_17 ,
L_13 ,
V_109 ) ;
}
V_17 -> V_37 . V_111 ++ ;
F_67 ( V_3 ) ;
return V_112 ;
}
F_42 ( V_6 -> V_14 ) ;
F_68 ( V_3 ) ;
F_69 ( V_3 ) ;
if ( V_109 < 2 + V_33 ) {
F_70 ( V_17 ) ;
if ( F_14 ( ! F_71 ( V_6 -> V_14 ) ) ) {
V_109 += F_57 ( V_6 ) ;
if ( V_109 >= 2 + V_33 ) {
F_72 ( V_17 ) ;
F_5 ( V_6 -> V_14 ) ;
}
}
}
return V_112 ;
}
static int F_73 ( struct V_42 * V_17 , void * V_12 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_113 * V_15 = V_6 -> V_15 ;
int V_114 ;
V_114 = F_74 ( V_17 , V_12 ) ;
if ( V_114 )
return V_114 ;
if ( F_75 ( V_15 , V_115 ) )
V_15 -> V_116 -> V_117 ( V_15 , F_76 ( struct V_118 , V_119 ) ,
V_17 -> V_120 , V_17 -> V_121 ) ;
return 0 ;
}
static struct V_122 * V_44 ( struct V_42 * V_17 ,
struct V_122 * V_123 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
int V_124 ;
unsigned int V_125 ;
F_77 (cpu) {
struct V_44 * V_37 = F_78 ( V_6 -> V_37 , V_124 ) ;
T_3 V_126 , V_127 , V_128 , V_129 ;
do {
V_125 = F_79 ( & V_37 -> V_99 ) ;
V_126 = V_37 -> V_101 ;
V_127 = V_37 -> V_100 ;
} while ( F_80 ( & V_37 -> V_99 , V_125 ) );
do {
V_125 = F_79 ( & V_37 -> V_49 ) ;
V_128 = V_37 -> V_51 ;
V_129 = V_37 -> V_50 ;
} while ( F_80 ( & V_37 -> V_49 , V_125 ) );
V_123 -> V_51 += V_128 ;
V_123 -> V_101 += V_126 ;
V_123 -> V_50 += V_129 ;
V_123 -> V_100 += V_127 ;
}
V_123 -> V_111 = V_17 -> V_37 . V_111 ;
V_123 -> V_110 = V_17 -> V_37 . V_110 ;
V_123 -> V_48 = V_17 -> V_37 . V_48 ;
V_123 -> V_38 = V_17 -> V_37 . V_38 ;
V_123 -> V_76 = V_17 -> V_37 . V_76 ;
return V_123 ;
}
static void F_81 ( struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
F_82 ( & V_6 -> V_86 ) ;
}
static int F_83 ( struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
if ( ! F_41 ( V_6 , V_91 ) )
F_53 ( & V_6 -> V_90 , 0 ) ;
F_46 ( V_6 ) ;
return 0 ;
}
static bool F_84 ( struct V_5 * V_6 , T_4 V_130 , T_4 V_131 ,
struct V_132 * V_105 , int V_133 , int V_134 )
{
struct V_132 * V_135 , V_136 [ V_137 + 2 ] ;
struct V_138 V_139 ;
T_5 V_140 = ~ 0 ;
unsigned int V_141 ;
int V_22 ;
F_85 ( ! F_75 ( V_6 -> V_15 , V_142 ) ||
( V_133 + V_134 > V_137 ) ) ;
V_133 ++ ;
V_134 ++ ;
V_139 . V_130 = V_130 ;
V_139 . V_131 = V_131 ;
F_86 ( V_136 , V_133 + V_134 ) ;
F_35 ( & V_136 [ 0 ] , & V_139 , sizeof( V_139 ) ) ;
F_87 (data, s, out + in - 2 , i)
F_35 ( & V_136 [ V_22 + 1 ] , F_88 ( V_135 ) , V_135 -> V_143 ) ;
F_35 ( & V_136 [ V_133 + V_134 - 1 ] , & V_140 , sizeof( V_140 ) ) ;
F_85 ( F_37 ( V_6 -> V_144 , V_136 , V_133 , V_134 , V_6 , V_97 ) < 0 ) ;
F_42 ( V_6 -> V_144 ) ;
while ( ! F_21 ( V_6 -> V_144 , & V_141 ) )
F_89 () ;
return V_140 == V_145 ;
}
static void F_90 ( struct V_5 * V_6 )
{
F_91 () ;
if ( ! F_84 ( V_6 , V_146 ,
V_147 , NULL ,
0 , 0 ) )
F_66 ( & V_6 -> V_17 -> V_17 , L_14 ) ;
F_92 () ;
}
static int F_93 ( struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
F_94 ( & V_6 -> V_90 ) ;
F_52 ( & V_6 -> V_86 ) ;
return 0 ;
}
static void F_95 ( struct V_42 * V_17 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_132 V_136 [ 2 ] ;
T_4 V_148 , V_149 ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
int V_154 ;
int V_155 ;
void * V_43 ;
int V_22 ;
if ( ! F_75 ( V_6 -> V_15 , V_156 ) )
return;
V_148 = ( ( V_17 -> V_52 & V_157 ) != 0 ) ;
V_149 = ( ( V_17 -> V_52 & V_158 ) != 0 ) ;
F_40 ( V_136 , & V_148 , sizeof( V_148 ) ) ;
if ( ! F_84 ( V_6 , V_159 ,
V_160 ,
V_136 , 1 , 0 ) )
F_66 ( & V_17 -> V_17 , L_15 ,
V_148 ? L_16 : L_17 ) ;
F_40 ( V_136 , & V_149 , sizeof( V_149 ) ) ;
if ( ! F_84 ( V_6 , V_159 ,
V_161 ,
V_136 , 1 , 0 ) )
F_66 ( & V_17 -> V_17 , L_18 ,
V_149 ? L_16 : L_17 ) ;
V_154 = F_96 ( V_17 ) ;
V_155 = F_97 ( V_17 ) ;
V_43 = F_98 ( ( ( V_154 + V_155 ) * V_162 ) +
( 2 * sizeof( V_151 -> V_163 ) ) , V_97 ) ;
V_151 = V_43 ;
if ( ! V_43 ) {
F_66 ( & V_17 -> V_17 , L_19 ) ;
return;
}
F_86 ( V_136 , 2 ) ;
V_151 -> V_163 = V_154 ;
V_22 = 0 ;
F_99 (ha, dev)
memcpy ( & V_151 -> V_164 [ V_22 ++ ] [ 0 ] , V_153 -> V_165 , V_162 ) ;
F_35 ( & V_136 [ 0 ] , V_151 ,
sizeof( V_151 -> V_163 ) + ( V_154 * V_162 ) ) ;
V_151 = ( void * ) & V_151 -> V_164 [ V_154 ] [ 0 ] ;
V_151 -> V_163 = V_155 ;
V_22 = 0 ;
F_100 (ha, dev)
memcpy ( & V_151 -> V_164 [ V_22 ++ ] [ 0 ] , V_153 -> V_165 , V_162 ) ;
F_35 ( & V_136 [ 1 ] , V_151 ,
sizeof( V_151 -> V_163 ) + ( V_155 * V_162 ) ) ;
if ( ! F_84 ( V_6 , V_166 ,
V_167 ,
V_136 , 2 , 0 ) )
F_66 ( & V_17 -> V_17 , L_20 ) ;
F_101 ( V_43 ) ;
}
static int F_102 ( struct V_42 * V_17 , T_6 V_168 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_132 V_136 ;
F_40 ( & V_136 , & V_168 , sizeof( V_168 ) ) ;
if ( ! F_84 ( V_6 , V_169 ,
V_170 , & V_136 , 1 , 0 ) )
F_66 ( & V_17 -> V_17 , L_21 , V_168 ) ;
return 0 ;
}
static int F_103 ( struct V_42 * V_17 , T_6 V_168 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_132 V_136 ;
F_40 ( & V_136 , & V_168 , sizeof( V_168 ) ) ;
if ( ! F_84 ( V_6 , V_169 ,
V_171 , & V_136 , 1 , 0 ) )
F_66 ( & V_17 -> V_17 , L_22 , V_168 ) ;
return 0 ;
}
static void F_104 ( struct V_42 * V_17 ,
struct V_172 * V_173 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
V_173 -> V_174 = F_105 ( V_6 -> V_40 ) ;
V_173 -> V_175 = F_105 ( V_6 -> V_14 ) ;
V_173 -> V_176 = V_173 -> V_174 ;
V_173 -> V_177 = V_173 -> V_175 ;
}
static void F_106 ( struct V_42 * V_17 ,
struct V_178 * V_179 )
{
struct V_5 * V_6 = F_23 ( V_17 ) ;
struct V_113 * V_15 = V_6 -> V_15 ;
F_107 ( V_179 -> V_180 , V_181 , sizeof( V_179 -> V_180 ) ) ;
F_107 ( V_179 -> V_182 , V_183 , sizeof( V_179 -> V_182 ) ) ;
F_107 ( V_179 -> V_184 , F_108 ( V_15 ) , sizeof( V_179 -> V_184 ) ) ;
}
static int F_109 ( struct V_42 * V_17 , int V_185 )
{
if ( V_185 < V_186 || V_185 > V_187 )
return - V_39 ;
V_17 -> V_188 = V_185 ;
return 0 ;
}
static void F_110 ( struct V_87 * V_88 )
{
struct V_5 * V_6 =
F_51 ( V_88 , struct V_5 , V_189 ) ;
T_6 V_190 ;
F_111 ( & V_6 -> V_191 ) ;
if ( ! V_6 -> V_192 )
goto V_193;
if ( F_112 ( V_6 -> V_15 , V_194 ,
F_76 ( struct V_118 , V_140 ) ,
& V_190 ) < 0 )
goto V_193;
if ( V_190 & V_195 ) {
F_113 ( V_6 -> V_17 ) ;
F_90 ( V_6 ) ;
}
V_190 &= V_196 ;
if ( V_6 -> V_140 == V_190 )
goto V_193;
V_6 -> V_140 = V_190 ;
if ( V_6 -> V_140 & V_196 ) {
F_114 ( V_6 -> V_17 ) ;
F_6 ( V_6 -> V_17 ) ;
} else {
F_115 ( V_6 -> V_17 ) ;
F_70 ( V_6 -> V_17 ) ;
}
V_193:
F_116 ( & V_6 -> V_191 ) ;
}
static void F_117 ( struct V_113 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
F_118 ( & V_6 -> V_189 ) ;
}
static int F_119 ( struct V_5 * V_6 )
{
struct V_13 * V_197 [ 3 ] ;
T_7 * V_198 [] = { F_43 , F_4 , NULL } ;
const char * V_199 [] = { L_23 , L_24 , L_25 } ;
int V_200 , V_78 ;
V_200 = F_75 ( V_6 -> V_15 , V_142 ) ? 3 : 2 ;
V_78 = V_6 -> V_15 -> V_116 -> V_201 ( V_6 -> V_15 , V_200 , V_197 , V_198 , V_199 ) ;
if ( V_78 )
return V_78 ;
V_6 -> V_40 = V_197 [ 0 ] ;
V_6 -> V_14 = V_197 [ 1 ] ;
if ( F_75 ( V_6 -> V_15 , V_142 ) ) {
V_6 -> V_144 = V_197 [ 2 ] ;
if ( F_75 ( V_6 -> V_15 , V_202 ) )
V_6 -> V_17 -> V_203 |= V_204 ;
}
return 0 ;
}
static int F_120 ( struct V_113 * V_15 )
{
int V_78 ;
struct V_42 * V_17 ;
struct V_5 * V_6 ;
V_17 = F_121 ( sizeof( struct V_5 ) ) ;
if ( ! V_17 )
return - V_80 ;
V_17 -> V_205 |= V_206 | V_207 ;
V_17 -> V_208 = & V_209 ;
V_17 -> V_203 = V_210 ;
F_122 ( V_17 , & V_211 ) ;
F_123 ( V_17 , & V_15 -> V_17 ) ;
if ( F_75 ( V_15 , V_212 ) ) {
V_17 -> V_213 |= V_214 | V_215 | V_216 ;
if ( V_217 )
V_17 -> V_203 |= V_214 | V_215 | V_216 ;
if ( F_75 ( V_15 , V_218 ) ) {
V_17 -> V_213 |= V_219 | V_220
| V_221 | V_222 ;
}
if ( F_75 ( V_15 , V_223 ) )
V_17 -> V_213 |= V_219 ;
if ( F_75 ( V_15 , V_224 ) )
V_17 -> V_213 |= V_222 ;
if ( F_75 ( V_15 , V_225 ) )
V_17 -> V_213 |= V_221 ;
if ( F_75 ( V_15 , V_226 ) )
V_17 -> V_213 |= V_220 ;
if ( V_227 )
V_17 -> V_203 |= V_17 -> V_213 & ( V_228 | V_220 ) ;
}
if ( F_124 ( V_15 , V_115 ,
F_76 ( struct V_118 , V_119 ) ,
V_17 -> V_120 , V_17 -> V_121 ) < 0 )
F_125 ( V_17 ) ;
V_6 = F_23 ( V_17 ) ;
F_126 ( V_17 , & V_6 -> V_86 , F_54 , V_229 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_15 = V_15 ;
V_15 -> V_16 = V_6 ;
V_6 -> V_10 = NULL ;
V_6 -> V_37 = F_127 ( struct V_44 ) ;
V_78 = - V_80 ;
if ( V_6 -> V_37 == NULL )
goto free;
F_128 ( & V_6 -> V_90 , F_50 ) ;
F_129 ( & V_6 -> V_191 ) ;
V_6 -> V_192 = true ;
F_130 ( & V_6 -> V_189 , F_110 ) ;
F_86 ( V_6 -> V_81 , F_131 ( V_6 -> V_81 ) ) ;
F_86 ( V_6 -> V_108 , F_131 ( V_6 -> V_108 ) ) ;
if ( F_75 ( V_15 , V_230 ) ||
F_75 ( V_15 , V_231 ) ||
F_75 ( V_15 , V_232 ) )
V_6 -> V_47 = true ;
if ( F_75 ( V_15 , V_233 ) )
V_6 -> V_30 = true ;
V_78 = F_119 ( V_6 ) ;
if ( V_78 )
goto V_234;
V_78 = F_132 ( V_17 ) ;
if ( V_78 ) {
F_18 ( L_26 ) ;
goto V_235;
}
F_41 ( V_6 , V_91 ) ;
if ( V_6 -> V_41 == 0 ) {
V_78 = - V_80 ;
goto V_236;
}
if ( F_75 ( V_6 -> V_15 , V_194 ) ) {
F_115 ( V_17 ) ;
F_118 ( & V_6 -> V_189 ) ;
} else {
V_6 -> V_140 = V_196 ;
F_114 ( V_17 ) ;
}
F_18 ( L_27 , V_17 -> V_34 ) ;
return 0 ;
V_236:
F_133 ( V_17 ) ;
V_235:
V_15 -> V_116 -> V_237 ( V_15 ) ;
V_234:
F_134 ( V_6 -> V_37 ) ;
free:
F_135 ( V_17 ) ;
return V_78 ;
}
static void F_136 ( struct V_5 * V_6 )
{
void * V_43 ;
while ( 1 ) {
V_43 = F_137 ( V_6 -> V_14 ) ;
if ( ! V_43 )
break;
F_19 ( V_43 ) ;
}
while ( 1 ) {
V_43 = F_137 ( V_6 -> V_40 ) ;
if ( ! V_43 )
break;
if ( V_6 -> V_30 || V_6 -> V_47 )
F_1 ( V_6 , V_43 ) ;
else
F_19 ( V_43 ) ;
-- V_6 -> V_41 ;
}
F_85 ( V_6 -> V_41 != 0 ) ;
}
static void F_138 ( struct V_5 * V_6 )
{
V_6 -> V_15 -> V_116 -> V_238 ( V_6 -> V_15 ) ;
F_136 ( V_6 ) ;
V_6 -> V_15 -> V_116 -> V_237 ( V_6 -> V_15 ) ;
while ( V_6 -> V_10 )
F_139 ( F_2 ( V_6 , V_91 ) , 0 ) ;
}
static void T_8 F_140 ( struct V_113 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
F_111 ( & V_6 -> V_191 ) ;
V_6 -> V_192 = false ;
F_116 ( & V_6 -> V_191 ) ;
F_133 ( V_6 -> V_17 ) ;
F_138 ( V_6 ) ;
F_141 ( & V_6 -> V_189 ) ;
F_134 ( V_6 -> V_37 ) ;
F_135 ( V_6 -> V_17 ) ;
}
static int F_142 ( struct V_113 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
F_111 ( & V_6 -> V_191 ) ;
V_6 -> V_192 = false ;
F_116 ( & V_6 -> V_191 ) ;
F_143 ( V_6 -> V_17 ) ;
F_94 ( & V_6 -> V_90 ) ;
if ( F_144 ( V_6 -> V_17 ) )
F_52 ( & V_6 -> V_86 ) ;
F_138 ( V_6 ) ;
F_141 ( & V_6 -> V_189 ) ;
return 0 ;
}
static int F_145 ( struct V_113 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
int V_78 ;
V_78 = F_119 ( V_6 ) ;
if ( V_78 )
return V_78 ;
if ( F_144 ( V_6 -> V_17 ) )
F_46 ( V_6 ) ;
F_146 ( V_6 -> V_17 ) ;
if ( ! F_41 ( V_6 , V_91 ) )
F_53 ( & V_6 -> V_90 , 0 ) ;
F_111 ( & V_6 -> V_191 ) ;
V_6 -> V_192 = true ;
F_116 ( & V_6 -> V_191 ) ;
return 0 ;
}
static int T_9 F_147 ( void )
{
return F_148 ( & V_239 ) ;
}
static void T_10 F_149 ( void )
{
F_150 ( & V_239 ) ;
}
