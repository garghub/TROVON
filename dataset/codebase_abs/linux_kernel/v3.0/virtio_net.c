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
struct V_2 * V_3 ;
struct V_7 * V_7 ;
struct V_1 * V_28 ;
if ( F_13 ( V_19 < sizeof( struct V_46 ) + V_47 ) ) {
F_17 ( L_3 , V_17 -> V_38 , V_19 ) ;
V_17 -> V_39 . V_40 ++ ;
if ( V_6 -> V_32 || V_6 -> V_48 )
F_1 ( V_6 , V_45 ) ;
else
F_21 ( V_45 ) ;
return;
}
if ( ! V_6 -> V_32 && ! V_6 -> V_48 ) {
V_3 = V_45 ;
V_19 -= sizeof( struct V_46 ) ;
F_22 ( V_3 , V_19 ) ;
} else {
V_7 = V_45 ;
V_3 = F_10 ( V_6 , V_7 , V_19 ) ;
if ( F_13 ( ! V_3 ) ) {
V_17 -> V_39 . V_49 ++ ;
F_1 ( V_6 , V_7 ) ;
return;
}
if ( V_6 -> V_32 )
if ( F_16 ( V_6 , V_3 ) ) {
F_21 ( V_3 ) ;
return;
}
}
V_28 = V_1 ( V_3 ) ;
V_3 -> V_50 += V_3 -> V_27 ;
V_17 -> V_39 . V_51 += V_3 -> V_19 ;
V_17 -> V_39 . V_52 ++ ;
if ( V_28 -> V_28 . V_53 & V_54 ) {
F_17 ( L_4 ) ;
if ( ! F_23 ( V_3 ,
V_28 -> V_28 . V_55 ,
V_28 -> V_28 . V_56 ) )
goto V_57;
}
V_3 -> V_58 = F_24 ( V_3 , V_17 ) ;
F_17 ( L_5 ,
F_25 ( V_3 -> V_58 ) , V_3 -> V_19 , V_3 -> V_59 ) ;
if ( V_28 -> V_28 . V_60 != V_61 ) {
F_17 ( L_6 ) ;
switch ( V_28 -> V_28 . V_60 & ~ V_62 ) {
case V_63 :
F_8 ( V_3 ) -> V_60 = V_64 ;
break;
case V_65 :
F_8 ( V_3 ) -> V_60 = V_66 ;
break;
case V_67 :
F_8 ( V_3 ) -> V_60 = V_68 ;
break;
default:
if ( F_26 () )
F_27 ( V_69 L_7 ,
V_17 -> V_38 , V_28 -> V_28 . V_60 ) ;
goto V_57;
}
if ( V_28 -> V_28 . V_60 & V_62 )
F_8 ( V_3 ) -> V_60 |= V_70 ;
F_8 ( V_3 ) -> V_71 = V_28 -> V_28 . V_71 ;
if ( F_8 ( V_3 ) -> V_71 == 0 ) {
if ( F_26 () )
F_27 ( V_69 L_8 ,
V_17 -> V_38 ) ;
goto V_57;
}
F_8 ( V_3 ) -> V_60 |= V_72 ;
F_8 ( V_3 ) -> V_73 = 0 ;
}
F_28 ( V_3 ) ;
return;
V_57:
V_17 -> V_39 . V_74 ++ ;
F_21 ( V_3 ) ;
}
static int F_29 ( struct V_5 * V_6 , T_1 V_75 )
{
struct V_2 * V_3 ;
struct V_1 * V_28 ;
int V_76 ;
V_3 = F_12 ( V_6 -> V_17 , V_77 ) ;
if ( F_13 ( ! V_3 ) )
return - V_78 ;
F_15 ( V_3 , V_77 ) ;
V_28 = V_1 ( V_3 ) ;
F_30 ( V_6 -> V_79 , & V_28 -> V_28 , sizeof V_28 -> V_28 ) ;
F_31 ( V_3 , V_6 -> V_79 + 1 , 0 , V_3 -> V_19 ) ;
V_76 = F_32 ( V_6 -> V_42 , V_6 -> V_79 , 0 , 2 , V_3 , V_75 ) ;
if ( V_76 < 0 )
F_21 ( V_3 ) ;
return V_76 ;
}
static int F_33 ( struct V_5 * V_6 , T_1 V_75 )
{
struct V_7 * V_80 , * V_81 = NULL ;
char * V_12 ;
int V_20 , V_76 , V_18 ;
for ( V_20 = V_37 + 1 ; V_20 > 1 ; -- V_20 ) {
V_80 = F_2 ( V_6 , V_75 ) ;
if ( ! V_80 ) {
if ( V_81 )
F_1 ( V_6 , V_81 ) ;
return - V_78 ;
}
F_30 ( & V_6 -> V_79 [ V_20 ] , F_11 ( V_80 ) , V_25 ) ;
V_80 -> V_9 = ( unsigned long ) V_81 ;
V_81 = V_80 ;
}
V_80 = F_2 ( V_6 , V_75 ) ;
if ( ! V_80 ) {
F_1 ( V_6 , V_81 ) ;
return - V_78 ;
}
V_12 = F_11 ( V_80 ) ;
F_30 ( & V_6 -> V_79 [ 0 ] , V_12 , sizeof( struct V_46 ) ) ;
V_18 = sizeof( struct V_34 ) ;
F_30 ( & V_6 -> V_79 [ 1 ] , V_12 + V_18 , V_25 - V_18 ) ;
V_80 -> V_9 = ( unsigned long ) V_81 ;
V_76 = F_32 ( V_6 -> V_42 , V_6 -> V_79 , 0 , V_37 + 2 ,
V_80 , V_75 ) ;
if ( V_76 < 0 )
F_1 ( V_6 , V_80 ) ;
return V_76 ;
}
static int F_34 ( struct V_5 * V_6 , T_1 V_75 )
{
struct V_7 * V_7 ;
int V_76 ;
V_7 = F_2 ( V_6 , V_75 ) ;
if ( ! V_7 )
return - V_78 ;
F_35 ( V_6 -> V_79 , F_11 ( V_7 ) , V_25 ) ;
V_76 = F_32 ( V_6 -> V_42 , V_6 -> V_79 , 0 , 1 , V_7 , V_75 ) ;
if ( V_76 < 0 )
F_1 ( V_6 , V_7 ) ;
return V_76 ;
}
static bool F_36 ( struct V_5 * V_6 , T_1 V_75 )
{
int V_76 ;
bool V_82 ;
do {
if ( V_6 -> V_32 )
V_76 = F_34 ( V_6 , V_75 ) ;
else if ( V_6 -> V_48 )
V_76 = F_33 ( V_6 , V_75 ) ;
else
V_76 = F_29 ( V_6 , V_75 ) ;
V_82 = V_76 == - V_78 ;
if ( V_76 < 0 )
break;
++ V_6 -> V_43 ;
} while ( V_76 > 0 );
if ( F_13 ( V_6 -> V_43 > V_6 -> V_83 ) )
V_6 -> V_83 = V_6 -> V_43 ;
F_37 ( V_6 -> V_42 ) ;
return ! V_82 ;
}
static void F_38 ( struct V_13 * V_42 )
{
struct V_5 * V_6 = V_42 -> V_15 -> V_16 ;
if ( F_39 ( & V_6 -> V_84 ) ) {
F_5 ( V_42 ) ;
F_40 ( & V_6 -> V_84 ) ;
}
}
static void F_41 ( struct V_5 * V_6 )
{
F_42 ( & V_6 -> V_84 ) ;
if ( F_39 ( & V_6 -> V_84 ) ) {
F_5 ( V_6 -> V_42 ) ;
F_40 ( & V_6 -> V_84 ) ;
}
}
static void F_43 ( struct V_85 * V_86 )
{
struct V_5 * V_6 ;
bool V_87 ;
V_6 = F_44 ( V_86 , struct V_5 , V_88 . V_86 ) ;
F_45 ( & V_6 -> V_84 ) ;
V_87 = ! F_36 ( V_6 , V_89 ) ;
F_41 ( V_6 ) ;
if ( V_87 )
F_46 ( & V_6 -> V_88 , V_90 / 2 ) ;
}
static int F_47 ( struct V_91 * V_84 , int V_92 )
{
struct V_5 * V_6 = F_44 ( V_84 , struct V_5 , V_84 ) ;
void * V_45 ;
unsigned int V_19 , V_93 = 0 ;
V_94:
while ( V_93 < V_92 &&
( V_45 = F_18 ( V_6 -> V_42 , & V_19 ) ) != NULL ) {
F_19 ( V_6 -> V_17 , V_45 , V_19 ) ;
-- V_6 -> V_43 ;
V_93 ++ ;
}
if ( V_6 -> V_43 < V_6 -> V_83 / 2 ) {
if ( ! F_36 ( V_6 , V_95 ) )
F_46 ( & V_6 -> V_88 , 0 ) ;
}
if ( V_93 < V_92 ) {
F_48 ( V_84 ) ;
if ( F_13 ( ! F_49 ( V_6 -> V_42 ) ) &&
F_39 ( V_84 ) ) {
F_5 ( V_6 -> V_42 ) ;
F_40 ( V_84 ) ;
goto V_94;
}
}
return V_93 ;
}
static unsigned int F_50 ( struct V_5 * V_6 )
{
struct V_2 * V_3 ;
unsigned int V_19 , V_96 = 0 ;
while ( ( V_3 = F_18 ( V_6 -> V_14 , & V_19 ) ) != NULL ) {
F_17 ( L_9 , V_3 ) ;
V_6 -> V_17 -> V_39 . V_97 += V_3 -> V_19 ;
V_6 -> V_17 -> V_39 . V_98 ++ ;
V_96 += V_1 ( V_3 ) -> V_99 ;
F_51 ( V_3 ) ;
}
return V_96 ;
}
static int F_52 ( struct V_5 * V_6 , struct V_2 * V_3 )
{
struct V_1 * V_28 = V_1 ( V_3 ) ;
const unsigned char * V_100 = ( (struct V_101 * ) V_3 -> V_102 ) -> V_103 ;
F_17 ( L_10 , V_6 -> V_17 -> V_38 , V_3 , V_100 ) ;
if ( V_3 -> V_104 == V_105 ) {
V_28 -> V_28 . V_53 = V_54 ;
V_28 -> V_28 . V_55 = F_53 ( V_3 ) ;
V_28 -> V_28 . V_56 = V_3 -> V_56 ;
} else {
V_28 -> V_28 . V_53 = 0 ;
V_28 -> V_28 . V_56 = V_28 -> V_28 . V_55 = 0 ;
}
if ( F_54 ( V_3 ) ) {
V_28 -> V_28 . V_30 = F_55 ( V_3 ) ;
V_28 -> V_28 . V_71 = F_8 ( V_3 ) -> V_71 ;
if ( F_8 ( V_3 ) -> V_60 & V_64 )
V_28 -> V_28 . V_60 = V_63 ;
else if ( F_8 ( V_3 ) -> V_60 & V_68 )
V_28 -> V_28 . V_60 = V_67 ;
else if ( F_8 ( V_3 ) -> V_60 & V_66 )
V_28 -> V_28 . V_60 = V_65 ;
else
F_56 () ;
if ( F_8 ( V_3 ) -> V_60 & V_70 )
V_28 -> V_28 . V_60 |= V_62 ;
} else {
V_28 -> V_28 . V_60 = V_61 ;
V_28 -> V_28 . V_71 = V_28 -> V_28 . V_30 = 0 ;
}
V_28 -> V_33 . V_36 = 0 ;
if ( V_6 -> V_32 )
F_30 ( V_6 -> V_106 , & V_28 -> V_33 , sizeof V_28 -> V_33 ) ;
else
F_30 ( V_6 -> V_106 , & V_28 -> V_28 , sizeof V_28 -> V_28 ) ;
V_28 -> V_99 = F_31 ( V_3 , V_6 -> V_106 + 1 , 0 , V_3 -> V_19 ) + 1 ;
return F_57 ( V_6 -> V_14 , V_6 -> V_106 , V_28 -> V_99 ,
0 , V_3 ) ;
}
static T_3 F_58 ( struct V_2 * V_3 , struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
int V_107 ;
F_50 ( V_6 ) ;
V_107 = F_52 ( V_6 , V_3 ) ;
if ( F_13 ( V_107 < 0 ) ) {
if ( F_26 () ) {
if ( F_59 ( V_107 == - V_78 ) ) {
F_60 ( & V_17 -> V_17 ,
L_11 ) ;
} else {
V_17 -> V_39 . V_108 ++ ;
F_60 ( & V_17 -> V_17 ,
L_12 ,
V_107 ) ;
}
}
V_17 -> V_39 . V_109 ++ ;
F_61 ( V_3 ) ;
return V_110 ;
}
F_37 ( V_6 -> V_14 ) ;
F_62 ( V_3 ) ;
F_63 ( V_3 ) ;
if ( V_107 < 2 + V_37 ) {
F_64 ( V_17 ) ;
if ( F_13 ( ! F_65 ( V_6 -> V_14 ) ) ) {
V_107 += F_50 ( V_6 ) ;
if ( V_107 >= 2 + V_37 ) {
F_66 ( V_17 ) ;
F_5 ( V_6 -> V_14 ) ;
}
}
}
return V_110 ;
}
static int F_67 ( struct V_44 * V_17 , void * V_12 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_111 * V_15 = V_6 -> V_15 ;
int V_112 ;
V_112 = F_68 ( V_17 , V_12 ) ;
if ( V_112 )
return V_112 ;
if ( F_69 ( V_15 , V_113 ) )
V_15 -> V_114 -> V_115 ( V_15 , F_70 ( struct V_116 , V_117 ) ,
V_17 -> V_118 , V_17 -> V_119 ) ;
return 0 ;
}
static void F_71 ( struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
F_72 ( & V_6 -> V_84 ) ;
}
static int F_73 ( struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
F_41 ( V_6 ) ;
return 0 ;
}
static bool F_74 ( struct V_5 * V_6 , T_4 V_120 , T_4 V_121 ,
struct V_122 * V_102 , int V_123 , int V_124 )
{
struct V_122 * V_125 , V_126 [ V_127 + 2 ] ;
struct V_128 V_129 ;
T_5 V_130 = ~ 0 ;
unsigned int V_131 ;
int V_20 ;
F_75 ( ! F_69 ( V_6 -> V_15 , V_132 ) ||
( V_123 + V_124 > V_127 ) ) ;
V_123 ++ ;
V_124 ++ ;
V_129 . V_120 = V_120 ;
V_129 . V_121 = V_121 ;
F_76 ( V_126 , V_123 + V_124 ) ;
F_30 ( & V_126 [ 0 ] , & V_129 , sizeof( V_129 ) ) ;
F_77 (data, s, out + in - 2 , i)
F_30 ( & V_126 [ V_20 + 1 ] , F_78 ( V_125 ) , V_125 -> V_133 ) ;
F_30 ( & V_126 [ V_123 + V_124 - 1 ] , & V_130 , sizeof( V_130 ) ) ;
F_75 ( F_57 ( V_6 -> V_134 , V_126 , V_123 , V_124 , V_6 ) < 0 ) ;
F_37 ( V_6 -> V_134 ) ;
while ( ! F_18 ( V_6 -> V_134 , & V_131 ) )
F_79 () ;
return V_130 == V_135 ;
}
static int F_80 ( struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
F_45 ( & V_6 -> V_84 ) ;
return 0 ;
}
static void F_81 ( struct V_44 * V_17 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_122 V_126 [ 2 ] ;
T_4 V_136 , V_137 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
int V_142 ;
int V_143 ;
void * V_45 ;
int V_20 ;
if ( ! F_69 ( V_6 -> V_15 , V_144 ) )
return;
V_136 = ( ( V_17 -> V_53 & V_145 ) != 0 ) ;
V_137 = ( ( V_17 -> V_53 & V_146 ) != 0 ) ;
F_35 ( V_126 , & V_136 , sizeof( V_136 ) ) ;
if ( ! F_74 ( V_6 , V_147 ,
V_148 ,
V_126 , 1 , 0 ) )
F_60 ( & V_17 -> V_17 , L_13 ,
V_136 ? L_14 : L_15 ) ;
F_35 ( V_126 , & V_137 , sizeof( V_137 ) ) ;
if ( ! F_74 ( V_6 , V_147 ,
V_149 ,
V_126 , 1 , 0 ) )
F_60 ( & V_17 -> V_17 , L_16 ,
V_137 ? L_14 : L_15 ) ;
V_142 = F_82 ( V_17 ) ;
V_143 = F_83 ( V_17 ) ;
V_45 = F_84 ( ( ( V_142 + V_143 ) * V_150 ) +
( 2 * sizeof( V_139 -> V_151 ) ) , V_95 ) ;
V_139 = V_45 ;
if ( ! V_45 ) {
F_60 ( & V_17 -> V_17 , L_17 ) ;
return;
}
F_76 ( V_126 , 2 ) ;
V_139 -> V_151 = V_142 ;
V_20 = 0 ;
F_85 (ha, dev)
memcpy ( & V_139 -> V_152 [ V_20 ++ ] [ 0 ] , V_141 -> V_153 , V_150 ) ;
F_30 ( & V_126 [ 0 ] , V_139 ,
sizeof( V_139 -> V_151 ) + ( V_142 * V_150 ) ) ;
V_139 = ( void * ) & V_139 -> V_152 [ V_142 ] [ 0 ] ;
V_139 -> V_151 = V_143 ;
V_20 = 0 ;
F_86 (ha, dev)
memcpy ( & V_139 -> V_152 [ V_20 ++ ] [ 0 ] , V_141 -> V_153 , V_150 ) ;
F_30 ( & V_126 [ 1 ] , V_139 ,
sizeof( V_139 -> V_151 ) + ( V_143 * V_150 ) ) ;
if ( ! F_74 ( V_6 , V_154 ,
V_155 ,
V_126 , 2 , 0 ) )
F_60 ( & V_17 -> V_17 , L_18 ) ;
F_87 ( V_45 ) ;
}
static void F_88 ( struct V_44 * V_17 , T_6 V_156 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_122 V_126 ;
F_35 ( & V_126 , & V_156 , sizeof( V_156 ) ) ;
if ( ! F_74 ( V_6 , V_157 ,
V_158 , & V_126 , 1 , 0 ) )
F_60 ( & V_17 -> V_17 , L_19 , V_156 ) ;
}
static void F_89 ( struct V_44 * V_17 , T_6 V_156 )
{
struct V_5 * V_6 = F_20 ( V_17 ) ;
struct V_122 V_126 ;
F_35 ( & V_126 , & V_156 , sizeof( V_156 ) ) ;
if ( ! F_74 ( V_6 , V_157 ,
V_159 , & V_126 , 1 , 0 ) )
F_60 ( & V_17 -> V_17 , L_20 , V_156 ) ;
}
static int F_90 ( struct V_44 * V_17 , int V_160 )
{
if ( V_160 < V_161 || V_160 > V_162 )
return - V_41 ;
V_17 -> V_163 = V_160 ;
return 0 ;
}
static void F_91 ( struct V_5 * V_6 )
{
T_6 V_164 ;
if ( ! F_69 ( V_6 -> V_15 , V_165 ) )
return;
V_6 -> V_15 -> V_114 -> V_166 ( V_6 -> V_15 ,
F_70 ( struct V_116 , V_130 ) ,
& V_164 , sizeof( V_164 ) ) ;
V_164 &= V_167 ;
if ( V_6 -> V_130 == V_164 )
return;
V_6 -> V_130 = V_164 ;
if ( V_6 -> V_130 & V_167 ) {
F_92 ( V_6 -> V_17 ) ;
F_6 ( V_6 -> V_17 ) ;
} else {
F_93 ( V_6 -> V_17 ) ;
F_64 ( V_6 -> V_17 ) ;
}
}
static void F_94 ( struct V_111 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
F_91 ( V_6 ) ;
}
static int F_95 ( struct V_111 * V_15 )
{
int V_76 ;
struct V_44 * V_17 ;
struct V_5 * V_6 ;
struct V_13 * V_168 [ 3 ] ;
T_7 * V_169 [] = { F_38 , F_4 , NULL } ;
const char * V_170 [] = { L_21 , L_22 , L_23 } ;
int V_171 ;
V_17 = F_96 ( sizeof( struct V_5 ) ) ;
if ( ! V_17 )
return - V_78 ;
V_17 -> V_172 = & V_173 ;
V_17 -> V_174 = V_175 ;
F_97 ( V_17 , & V_176 ) ;
F_98 ( V_17 , & V_15 -> V_17 ) ;
if ( F_69 ( V_15 , V_177 ) ) {
V_17 -> V_178 |= V_179 | V_180 | V_181 ;
if ( V_182 )
V_17 -> V_174 |= V_179 | V_180 | V_181 ;
if ( F_69 ( V_15 , V_183 ) ) {
V_17 -> V_178 |= V_184 | V_185
| V_186 | V_187 ;
}
if ( F_69 ( V_15 , V_188 ) )
V_17 -> V_178 |= V_184 ;
if ( F_69 ( V_15 , V_189 ) )
V_17 -> V_178 |= V_187 ;
if ( F_69 ( V_15 , V_190 ) )
V_17 -> V_178 |= V_186 ;
if ( F_69 ( V_15 , V_191 ) )
V_17 -> V_178 |= V_185 ;
if ( V_192 )
V_17 -> V_174 |= V_17 -> V_178 & ( V_193 | V_185 ) ;
}
if ( F_69 ( V_15 , V_113 ) ) {
V_15 -> V_114 -> V_166 ( V_15 ,
F_70 ( struct V_116 , V_117 ) ,
V_17 -> V_118 , V_17 -> V_119 ) ;
} else
F_99 ( V_17 -> V_118 ) ;
V_6 = F_20 ( V_17 ) ;
F_100 ( V_17 , & V_6 -> V_84 , F_47 , V_194 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_15 = V_15 ;
V_15 -> V_16 = V_6 ;
V_6 -> V_10 = NULL ;
F_101 ( & V_6 -> V_88 , F_43 ) ;
F_76 ( V_6 -> V_79 , F_102 ( V_6 -> V_79 ) ) ;
F_76 ( V_6 -> V_106 , F_102 ( V_6 -> V_106 ) ) ;
if ( F_69 ( V_15 , V_195 ) ||
F_69 ( V_15 , V_196 ) ||
F_69 ( V_15 , V_197 ) )
V_6 -> V_48 = true ;
if ( F_69 ( V_15 , V_198 ) )
V_6 -> V_32 = true ;
V_171 = F_69 ( V_6 -> V_15 , V_132 ) ? 3 : 2 ;
V_76 = V_15 -> V_114 -> V_199 ( V_15 , V_171 , V_168 , V_169 , V_170 ) ;
if ( V_76 )
goto free;
V_6 -> V_42 = V_168 [ 0 ] ;
V_6 -> V_14 = V_168 [ 1 ] ;
if ( F_69 ( V_6 -> V_15 , V_132 ) ) {
V_6 -> V_134 = V_168 [ 2 ] ;
if ( F_69 ( V_6 -> V_15 , V_200 ) )
V_17 -> V_174 |= V_201 ;
}
V_76 = F_103 ( V_17 ) ;
if ( V_76 ) {
F_17 ( L_24 ) ;
goto V_202;
}
F_36 ( V_6 , V_89 ) ;
if ( V_6 -> V_43 == 0 ) {
V_76 = - V_78 ;
goto V_203;
}
if ( F_69 ( V_6 -> V_15 , V_165 ) ) {
F_93 ( V_17 ) ;
F_91 ( V_6 ) ;
} else {
V_6 -> V_130 = V_167 ;
F_92 ( V_17 ) ;
}
F_17 ( L_25 , V_17 -> V_38 ) ;
return 0 ;
V_203:
F_104 ( V_17 ) ;
F_105 ( & V_6 -> V_88 ) ;
V_202:
V_15 -> V_114 -> V_204 ( V_15 ) ;
free:
F_106 ( V_17 ) ;
return V_76 ;
}
static void F_107 ( struct V_5 * V_6 )
{
void * V_45 ;
while ( 1 ) {
V_45 = F_108 ( V_6 -> V_14 ) ;
if ( ! V_45 )
break;
F_21 ( V_45 ) ;
}
while ( 1 ) {
V_45 = F_108 ( V_6 -> V_42 ) ;
if ( ! V_45 )
break;
if ( V_6 -> V_32 || V_6 -> V_48 )
F_1 ( V_6 , V_45 ) ;
else
F_21 ( V_45 ) ;
-- V_6 -> V_43 ;
}
F_75 ( V_6 -> V_43 != 0 ) ;
}
static void T_8 F_109 ( struct V_111 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_16 ;
V_15 -> V_114 -> V_205 ( V_15 ) ;
F_104 ( V_6 -> V_17 ) ;
F_105 ( & V_6 -> V_88 ) ;
F_107 ( V_6 ) ;
V_15 -> V_114 -> V_204 ( V_6 -> V_15 ) ;
while ( V_6 -> V_10 )
F_110 ( F_2 ( V_6 , V_89 ) , 0 ) ;
F_106 ( V_6 -> V_17 ) ;
}
static int T_9 F_111 ( void )
{
return F_112 ( & V_206 ) ;
}
static void T_10 F_113 ( void )
{
F_114 ( & V_206 ) ;
}
