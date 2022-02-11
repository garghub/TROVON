static int F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 ) - 1 ) / 2 ;
}
static int F_3 ( int V_3 )
{
return V_3 * 2 + 1 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) / 2 ;
}
static int F_5 ( int V_4 )
{
return V_4 * 2 ;
}
static inline struct V_5 * V_5 ( struct V_6 * V_7 )
{
return (struct V_5 * ) V_7 -> V_8 ;
}
static void F_6 ( struct V_9 * V_10 , struct V_11 * V_11 )
{
struct V_11 * V_12 ;
for ( V_12 = V_11 ; V_12 -> V_13 ; V_12 = (struct V_11 * ) V_12 -> V_13 ) ;
V_12 -> V_13 = ( unsigned long ) V_10 -> V_14 ;
V_10 -> V_14 = V_11 ;
}
static struct V_11 * F_7 ( struct V_9 * V_10 , T_1 V_15 )
{
struct V_11 * V_16 = V_10 -> V_14 ;
if ( V_16 ) {
V_10 -> V_14 = (struct V_11 * ) V_16 -> V_13 ;
V_16 -> V_13 = 0 ;
} else
V_16 = F_8 ( V_15 ) ;
return V_16 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 -> V_20 ;
F_10 ( V_2 ) ;
F_11 ( V_18 -> V_21 , F_1 ( V_2 ) ) ;
}
static void F_12 ( struct V_6 * V_7 , struct V_11 * V_11 ,
unsigned int V_22 , unsigned int * V_23 )
{
int V_24 = F_13 ( ( unsigned ) V_25 - V_22 , * V_23 ) ;
int V_26 = F_14 ( V_7 ) -> V_27 ;
F_15 ( V_7 , V_26 , V_11 , V_22 , V_24 ) ;
V_7 -> V_28 += V_24 ;
V_7 -> V_23 += V_24 ;
V_7 -> V_29 += V_25 ;
F_14 ( V_7 ) -> V_27 ++ ;
F_14 ( V_7 ) -> V_30 |= V_31 ;
* V_23 -= V_24 ;
}
static struct V_6 * F_16 ( struct V_9 * V_10 ,
struct V_11 * V_11 , unsigned int V_23 )
{
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
struct V_6 * V_7 ;
struct V_5 * V_32 ;
unsigned int V_33 , V_34 , V_22 ;
char * V_16 ;
V_16 = F_17 ( V_11 ) ;
V_7 = F_18 ( V_18 -> V_21 , V_35 ) ;
if ( F_19 ( ! V_7 ) )
return NULL ;
V_32 = V_5 ( V_7 ) ;
if ( V_18 -> V_36 ) {
V_34 = sizeof V_32 -> V_37 ;
V_22 = V_34 ;
} else {
V_34 = sizeof V_32 -> V_32 ;
V_22 = sizeof( struct V_38 ) ;
}
memcpy ( V_32 , V_16 , V_34 ) ;
V_23 -= V_34 ;
V_16 += V_22 ;
V_33 = V_23 ;
if ( V_33 > F_20 ( V_7 ) )
V_33 = F_20 ( V_7 ) ;
memcpy ( F_21 ( V_7 , V_33 ) , V_16 , V_33 ) ;
V_23 -= V_33 ;
V_22 += V_33 ;
if ( F_19 ( V_23 > V_39 * V_25 ) ) {
F_22 ( L_1 , V_7 -> V_21 -> V_40 ) ;
F_23 ( V_7 ) ;
return NULL ;
}
while ( V_23 ) {
F_12 ( V_7 , V_11 , V_22 , & V_23 ) ;
V_11 = (struct V_11 * ) V_11 -> V_13 ;
V_22 = 0 ;
}
if ( V_11 )
F_6 ( V_10 , V_11 ) ;
return V_7 ;
}
static int F_24 ( struct V_9 * V_10 , struct V_6 * V_7 )
{
struct V_5 * V_32 = V_5 ( V_7 ) ;
struct V_11 * V_11 ;
int V_41 , V_26 , V_23 ;
V_41 = V_32 -> V_37 . V_42 ;
while ( -- V_41 ) {
V_26 = F_14 ( V_7 ) -> V_27 ;
if ( V_26 >= V_39 ) {
F_25 ( L_2 , V_7 -> V_21 -> V_40 ) ;
V_7 -> V_21 -> V_43 . V_44 ++ ;
return - V_45 ;
}
V_11 = F_26 ( V_10 -> V_2 , & V_23 ) ;
if ( ! V_11 ) {
F_25 ( L_3 ,
V_7 -> V_21 -> V_40 , V_32 -> V_37 . V_42 ) ;
V_7 -> V_21 -> V_43 . V_44 ++ ;
return - V_45 ;
}
if ( V_23 > V_25 )
V_23 = V_25 ;
F_12 ( V_7 , V_11 , 0 , & V_23 ) ;
-- V_10 -> V_46 ;
}
return 0 ;
}
static void F_27 ( struct V_9 * V_10 , void * V_47 , unsigned int V_23 )
{
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
struct V_48 * V_21 = V_18 -> V_21 ;
struct V_49 * V_43 = F_28 ( V_18 -> V_43 ) ;
struct V_6 * V_7 ;
struct V_11 * V_11 ;
struct V_5 * V_32 ;
if ( F_19 ( V_23 < sizeof( struct V_50 ) + V_51 ) ) {
F_25 ( L_4 , V_21 -> V_40 , V_23 ) ;
V_21 -> V_43 . V_44 ++ ;
if ( V_18 -> V_36 || V_18 -> V_52 )
F_6 ( V_10 , V_47 ) ;
else
F_23 ( V_47 ) ;
return;
}
if ( ! V_18 -> V_36 && ! V_18 -> V_52 ) {
V_7 = V_47 ;
V_23 -= sizeof( struct V_50 ) ;
F_29 ( V_7 , V_23 ) ;
} else {
V_11 = V_47 ;
V_7 = F_16 ( V_10 , V_11 , V_23 ) ;
if ( F_19 ( ! V_7 ) ) {
V_21 -> V_43 . V_53 ++ ;
F_6 ( V_10 , V_11 ) ;
return;
}
if ( V_18 -> V_36 )
if ( F_24 ( V_10 , V_7 ) ) {
F_23 ( V_7 ) ;
return;
}
}
V_32 = V_5 ( V_7 ) ;
F_30 ( & V_43 -> V_54 ) ;
V_43 -> V_55 += V_7 -> V_23 ;
V_43 -> V_56 ++ ;
F_31 ( & V_43 -> V_54 ) ;
if ( V_32 -> V_32 . V_57 & V_58 ) {
F_25 ( L_5 ) ;
if ( ! F_32 ( V_7 ,
V_32 -> V_32 . V_59 ,
V_32 -> V_32 . V_60 ) )
goto V_61;
} else if ( V_32 -> V_32 . V_57 & V_62 ) {
V_7 -> V_63 = V_64 ;
}
V_7 -> V_65 = F_33 ( V_7 , V_21 ) ;
F_25 ( L_6 ,
F_34 ( V_7 -> V_65 ) , V_7 -> V_23 , V_7 -> V_66 ) ;
if ( V_32 -> V_32 . V_67 != V_68 ) {
F_25 ( L_7 ) ;
switch ( V_32 -> V_32 . V_67 & ~ V_69 ) {
case V_70 :
F_14 ( V_7 ) -> V_67 = V_71 ;
break;
case V_72 :
F_14 ( V_7 ) -> V_67 = V_73 ;
break;
case V_74 :
F_14 ( V_7 ) -> V_67 = V_75 ;
break;
default:
F_35 ( L_8 ,
V_21 -> V_40 , V_32 -> V_32 . V_67 ) ;
goto V_61;
}
if ( V_32 -> V_32 . V_67 & V_69 )
F_14 ( V_7 ) -> V_67 |= V_76 ;
F_14 ( V_7 ) -> V_77 = V_32 -> V_32 . V_77 ;
if ( F_14 ( V_7 ) -> V_77 == 0 ) {
F_35 ( L_9 , V_21 -> V_40 ) ;
goto V_61;
}
F_14 ( V_7 ) -> V_67 |= V_78 ;
F_14 ( V_7 ) -> V_79 = 0 ;
}
F_36 ( V_7 ) ;
return;
V_61:
V_21 -> V_43 . V_80 ++ ;
F_23 ( V_7 ) ;
}
static int F_37 ( struct V_9 * V_10 , T_1 V_81 )
{
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
struct V_6 * V_7 ;
struct V_5 * V_32 ;
int V_82 ;
V_7 = F_38 ( V_18 -> V_21 , V_83 , V_81 ) ;
if ( F_19 ( ! V_7 ) )
return - V_84 ;
F_21 ( V_7 , V_83 ) ;
V_32 = V_5 ( V_7 ) ;
F_39 ( V_10 -> V_85 , & V_32 -> V_32 , sizeof V_32 -> V_32 ) ;
F_40 ( V_7 , V_10 -> V_85 + 1 , 0 , V_7 -> V_23 ) ;
V_82 = F_41 ( V_10 -> V_2 , V_10 -> V_85 , 0 , 2 , V_7 , V_81 ) ;
if ( V_82 < 0 )
F_23 ( V_7 ) ;
return V_82 ;
}
static int F_42 ( struct V_9 * V_10 , T_1 V_81 )
{
struct V_11 * V_86 , * V_87 = NULL ;
char * V_16 ;
int V_26 , V_82 , V_22 ;
for ( V_26 = V_39 + 1 ; V_26 > 1 ; -- V_26 ) {
V_86 = F_7 ( V_10 , V_81 ) ;
if ( ! V_86 ) {
if ( V_87 )
F_6 ( V_10 , V_87 ) ;
return - V_84 ;
}
F_39 ( & V_10 -> V_85 [ V_26 ] , F_17 ( V_86 ) , V_25 ) ;
V_86 -> V_13 = ( unsigned long ) V_87 ;
V_87 = V_86 ;
}
V_86 = F_7 ( V_10 , V_81 ) ;
if ( ! V_86 ) {
F_6 ( V_10 , V_87 ) ;
return - V_84 ;
}
V_16 = F_17 ( V_86 ) ;
F_39 ( & V_10 -> V_85 [ 0 ] , V_16 , sizeof( struct V_50 ) ) ;
V_22 = sizeof( struct V_38 ) ;
F_39 ( & V_10 -> V_85 [ 1 ] , V_16 + V_22 , V_25 - V_22 ) ;
V_86 -> V_13 = ( unsigned long ) V_87 ;
V_82 = F_41 ( V_10 -> V_2 , V_10 -> V_85 , 0 , V_39 + 2 ,
V_86 , V_81 ) ;
if ( V_82 < 0 )
F_6 ( V_10 , V_86 ) ;
return V_82 ;
}
static int F_43 ( struct V_9 * V_10 , T_1 V_81 )
{
struct V_11 * V_11 ;
int V_82 ;
V_11 = F_7 ( V_10 , V_81 ) ;
if ( ! V_11 )
return - V_84 ;
F_44 ( V_10 -> V_85 , F_17 ( V_11 ) , V_25 ) ;
V_82 = F_41 ( V_10 -> V_2 , V_10 -> V_85 , 0 , 1 , V_11 , V_81 ) ;
if ( V_82 < 0 )
F_6 ( V_10 , V_11 ) ;
return V_82 ;
}
static bool F_45 ( struct V_9 * V_10 , T_1 V_81 )
{
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
int V_82 ;
bool V_88 ;
do {
if ( V_18 -> V_36 )
V_82 = F_43 ( V_10 , V_81 ) ;
else if ( V_18 -> V_52 )
V_82 = F_42 ( V_10 , V_81 ) ;
else
V_82 = F_37 ( V_10 , V_81 ) ;
V_88 = V_82 == - V_84 ;
if ( V_82 )
break;
++ V_10 -> V_46 ;
} while ( V_10 -> V_2 -> V_89 );
if ( F_19 ( V_10 -> V_46 > V_10 -> V_90 ) )
V_10 -> V_90 = V_10 -> V_46 ;
F_46 ( V_10 -> V_2 ) ;
return ! V_88 ;
}
static void F_47 ( struct V_1 * V_91 )
{
struct V_17 * V_18 = V_91 -> V_19 -> V_20 ;
struct V_9 * V_10 = & V_18 -> V_10 [ F_4 ( V_91 ) ] ;
if ( F_48 ( & V_10 -> V_92 ) ) {
F_10 ( V_91 ) ;
F_49 ( & V_10 -> V_92 ) ;
}
}
static void F_50 ( struct V_9 * V_10 )
{
F_51 ( & V_10 -> V_92 ) ;
if ( F_48 ( & V_10 -> V_92 ) ) {
F_10 ( V_10 -> V_2 ) ;
F_52 () ;
F_49 ( & V_10 -> V_92 ) ;
F_53 () ;
}
}
static void F_54 ( struct V_93 * V_94 )
{
struct V_17 * V_18 =
F_55 ( V_94 , struct V_17 , V_95 . V_94 ) ;
bool V_96 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
struct V_9 * V_10 = & V_18 -> V_10 [ V_26 ] ;
F_56 ( & V_10 -> V_92 ) ;
V_96 = ! F_45 ( V_10 , V_98 ) ;
F_50 ( V_10 ) ;
if ( V_96 )
F_57 ( & V_18 -> V_95 , V_99 / 2 ) ;
}
}
static int F_58 ( struct V_100 * V_92 , int V_101 )
{
struct V_9 * V_10 =
F_55 ( V_92 , struct V_9 , V_92 ) ;
struct V_17 * V_18 = V_10 -> V_2 -> V_19 -> V_20 ;
void * V_47 ;
unsigned int V_23 , V_102 = 0 ;
V_103:
while ( V_102 < V_101 &&
( V_47 = F_26 ( V_10 -> V_2 , & V_23 ) ) != NULL ) {
F_27 ( V_10 , V_47 , V_23 ) ;
-- V_10 -> V_46 ;
V_102 ++ ;
}
if ( V_10 -> V_46 < V_10 -> V_90 / 2 ) {
if ( ! F_45 ( V_10 , V_104 ) )
F_57 ( & V_18 -> V_95 , 0 ) ;
}
if ( V_102 < V_101 ) {
F_59 ( V_92 ) ;
if ( F_19 ( ! F_60 ( V_10 -> V_2 ) ) &&
F_48 ( V_92 ) ) {
F_10 ( V_10 -> V_2 ) ;
F_49 ( V_92 ) ;
goto V_103;
}
}
return V_102 ;
}
static int F_61 ( struct V_48 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
if ( ! F_45 ( & V_18 -> V_10 [ V_26 ] , V_98 ) )
F_57 ( & V_18 -> V_95 , 0 ) ;
F_50 ( & V_18 -> V_10 [ V_26 ] ) ;
}
return 0 ;
}
static void F_63 ( struct V_105 * V_106 )
{
struct V_6 * V_7 ;
unsigned int V_23 ;
struct V_17 * V_18 = V_106 -> V_2 -> V_19 -> V_20 ;
struct V_49 * V_43 = F_28 ( V_18 -> V_43 ) ;
while ( ( V_7 = F_26 ( V_106 -> V_2 , & V_23 ) ) != NULL ) {
F_25 ( L_10 , V_7 ) ;
F_30 ( & V_43 -> V_107 ) ;
V_43 -> V_108 += V_7 -> V_23 ;
V_43 -> V_109 ++ ;
F_31 ( & V_43 -> V_107 ) ;
F_64 ( V_7 ) ;
}
}
static int F_65 ( struct V_105 * V_106 , struct V_6 * V_7 )
{
struct V_5 * V_32 = V_5 ( V_7 ) ;
const unsigned char * V_110 = ( (struct V_111 * ) V_7 -> V_112 ) -> V_113 ;
struct V_17 * V_18 = V_106 -> V_2 -> V_19 -> V_20 ;
unsigned V_114 ;
F_25 ( L_11 , V_18 -> V_21 -> V_40 , V_7 , V_110 ) ;
if ( V_7 -> V_63 == V_115 ) {
V_32 -> V_32 . V_57 = V_58 ;
V_32 -> V_32 . V_59 = F_66 ( V_7 ) ;
V_32 -> V_32 . V_60 = V_7 -> V_60 ;
} else {
V_32 -> V_32 . V_57 = 0 ;
V_32 -> V_32 . V_60 = V_32 -> V_32 . V_59 = 0 ;
}
if ( F_67 ( V_7 ) ) {
V_32 -> V_32 . V_34 = F_68 ( V_7 ) ;
V_32 -> V_32 . V_77 = F_14 ( V_7 ) -> V_77 ;
if ( F_14 ( V_7 ) -> V_67 & V_71 )
V_32 -> V_32 . V_67 = V_70 ;
else if ( F_14 ( V_7 ) -> V_67 & V_75 )
V_32 -> V_32 . V_67 = V_74 ;
else if ( F_14 ( V_7 ) -> V_67 & V_73 )
V_32 -> V_32 . V_67 = V_72 ;
else
F_69 () ;
if ( F_14 ( V_7 ) -> V_67 & V_76 )
V_32 -> V_32 . V_67 |= V_69 ;
} else {
V_32 -> V_32 . V_67 = V_68 ;
V_32 -> V_32 . V_77 = V_32 -> V_32 . V_34 = 0 ;
}
V_32 -> V_37 . V_42 = 0 ;
if ( V_18 -> V_36 )
F_39 ( V_106 -> V_85 , & V_32 -> V_37 , sizeof V_32 -> V_37 ) ;
else
F_39 ( V_106 -> V_85 , & V_32 -> V_32 , sizeof V_32 -> V_32 ) ;
V_114 = F_40 ( V_7 , V_106 -> V_85 + 1 , 0 , V_7 -> V_23 ) + 1 ;
return F_41 ( V_106 -> V_2 , V_106 -> V_85 , V_114 ,
0 , V_7 , V_104 ) ;
}
static T_2 F_70 ( struct V_6 * V_7 , struct V_48 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_116 = F_71 ( V_7 ) ;
struct V_105 * V_106 = & V_18 -> V_106 [ V_116 ] ;
int V_82 ;
F_63 ( V_106 ) ;
V_82 = F_65 ( V_106 , V_7 ) ;
if ( F_19 ( V_82 ) ) {
V_21 -> V_43 . V_117 ++ ;
if ( F_72 () )
F_73 ( & V_21 -> V_21 ,
L_12 , V_116 , V_82 ) ;
V_21 -> V_43 . V_118 ++ ;
F_74 ( V_7 ) ;
return V_119 ;
}
F_46 ( V_106 -> V_2 ) ;
F_75 ( V_7 ) ;
F_76 ( V_7 ) ;
if ( V_106 -> V_2 -> V_89 < 2 + V_39 ) {
F_77 ( V_21 , V_116 ) ;
if ( F_19 ( ! F_78 ( V_106 -> V_2 ) ) ) {
F_63 ( V_106 ) ;
if ( V_106 -> V_2 -> V_89 >= 2 + V_39 ) {
F_79 ( V_21 , V_116 ) ;
F_10 ( V_106 -> V_2 ) ;
}
}
}
return V_119 ;
}
static bool F_80 ( struct V_17 * V_18 , T_3 V_120 , T_3 V_121 ,
struct V_122 * V_112 , int V_123 , int V_124 )
{
struct V_122 * V_125 , V_85 [ V_126 + 2 ] ;
struct V_127 V_128 ;
T_4 V_129 = ~ 0 ;
unsigned int V_130 ;
int V_26 ;
F_81 ( ! F_82 ( V_18 -> V_19 , V_131 ) ||
( V_123 + V_124 > V_126 ) ) ;
V_123 ++ ;
V_124 ++ ;
V_128 . V_120 = V_120 ;
V_128 . V_121 = V_121 ;
F_83 ( V_85 , V_123 + V_124 ) ;
F_39 ( & V_85 [ 0 ] , & V_128 , sizeof( V_128 ) ) ;
F_84 (data, s, out + in - 2 , i)
F_39 ( & V_85 [ V_26 + 1 ] , F_85 ( V_125 ) , V_125 -> V_132 ) ;
F_39 ( & V_85 [ V_123 + V_124 - 1 ] , & V_129 , sizeof( V_129 ) ) ;
F_81 ( F_41 ( V_18 -> V_133 , V_85 , V_123 , V_124 , V_18 , V_104 ) < 0 ) ;
F_46 ( V_18 -> V_133 ) ;
while ( ! F_26 ( V_18 -> V_133 , & V_130 ) )
F_86 () ;
return V_129 == V_134 ;
}
static int F_87 ( struct V_48 * V_21 , void * V_16 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_135 * V_19 = V_18 -> V_19 ;
int V_136 ;
struct V_137 * V_138 = V_16 ;
struct V_122 V_85 ;
V_136 = F_88 ( V_21 , V_16 ) ;
if ( V_136 )
return V_136 ;
if ( F_82 ( V_19 , V_139 ) ) {
F_44 ( & V_85 , V_138 -> V_140 , V_21 -> V_141 ) ;
if ( ! F_80 ( V_18 , V_142 ,
V_143 ,
& V_85 , 1 , 0 ) ) {
F_73 ( & V_19 -> V_21 ,
L_13 ) ;
return - V_45 ;
}
} else if ( F_82 ( V_19 , V_144 ) ) {
V_19 -> V_145 -> V_146 ( V_19 , F_89 ( struct V_147 , V_148 ) ,
V_138 -> V_140 , V_21 -> V_141 ) ;
}
F_90 ( V_21 , V_16 ) ;
return 0 ;
}
static struct V_149 * V_49 ( struct V_48 * V_21 ,
struct V_149 * V_150 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_151 ;
unsigned int V_152 ;
F_91 (cpu) {
struct V_49 * V_43 = F_92 ( V_18 -> V_43 , V_151 ) ;
T_5 V_153 , V_154 , V_155 , V_156 ;
do {
V_152 = F_93 ( & V_43 -> V_107 ) ;
V_153 = V_43 -> V_109 ;
V_154 = V_43 -> V_108 ;
} while ( F_94 ( & V_43 -> V_107 , V_152 ) );
do {
V_152 = F_93 ( & V_43 -> V_54 ) ;
V_155 = V_43 -> V_56 ;
V_156 = V_43 -> V_55 ;
} while ( F_94 ( & V_43 -> V_54 , V_152 ) );
V_150 -> V_56 += V_155 ;
V_150 -> V_109 += V_153 ;
V_150 -> V_55 += V_156 ;
V_150 -> V_108 += V_154 ;
}
V_150 -> V_118 = V_21 -> V_43 . V_118 ;
V_150 -> V_117 = V_21 -> V_43 . V_117 ;
V_150 -> V_53 = V_21 -> V_43 . V_53 ;
V_150 -> V_44 = V_21 -> V_43 . V_44 ;
V_150 -> V_80 = V_21 -> V_43 . V_80 ;
return V_150 ;
}
static void F_95 ( struct V_48 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_157 ; V_26 ++ )
F_96 ( & V_18 -> V_10 [ V_26 ] . V_92 ) ;
}
static void F_97 ( struct V_17 * V_18 )
{
F_98 () ;
if ( ! F_80 ( V_18 , V_158 ,
V_159 , NULL ,
0 , 0 ) )
F_73 ( & V_18 -> V_21 -> V_21 , L_14 ) ;
F_99 () ;
}
static int F_100 ( struct V_17 * V_18 , T_6 V_160 )
{
struct V_122 V_85 ;
struct V_161 V_125 ;
struct V_48 * V_21 = V_18 -> V_21 ;
if ( ! V_18 -> V_162 || ! F_82 ( V_18 -> V_19 , V_163 ) )
return 0 ;
V_125 . V_164 = V_160 ;
F_44 ( & V_85 , & V_125 , sizeof( V_125 ) ) ;
if ( ! F_80 ( V_18 , V_165 ,
V_166 , & V_85 , 1 , 0 ) ) {
F_73 ( & V_21 -> V_21 , L_15 ,
V_160 ) ;
return - V_45 ;
} else
V_18 -> V_157 = V_160 ;
return 0 ;
}
static int F_101 ( struct V_48 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
int V_26 ;
F_102 ( & V_18 -> V_95 ) ;
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ )
F_56 ( & V_18 -> V_10 [ V_26 ] . V_92 ) ;
return 0 ;
}
static void F_103 ( struct V_48 * V_21 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_122 V_85 [ 2 ] ;
T_3 V_167 , V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
int V_173 ;
int V_174 ;
void * V_47 ;
int V_26 ;
if ( ! F_82 ( V_18 -> V_19 , V_175 ) )
return;
V_167 = ( ( V_21 -> V_57 & V_176 ) != 0 ) ;
V_168 = ( ( V_21 -> V_57 & V_177 ) != 0 ) ;
F_44 ( V_85 , & V_167 , sizeof( V_167 ) ) ;
if ( ! F_80 ( V_18 , V_178 ,
V_179 ,
V_85 , 1 , 0 ) )
F_73 ( & V_21 -> V_21 , L_16 ,
V_167 ? L_17 : L_18 ) ;
F_44 ( V_85 , & V_168 , sizeof( V_168 ) ) ;
if ( ! F_80 ( V_18 , V_178 ,
V_180 ,
V_85 , 1 , 0 ) )
F_73 ( & V_21 -> V_21 , L_19 ,
V_168 ? L_17 : L_18 ) ;
V_173 = F_104 ( V_21 ) ;
V_174 = F_105 ( V_21 ) ;
V_47 = F_106 ( ( ( V_173 + V_174 ) * V_181 ) +
( 2 * sizeof( V_170 -> V_182 ) ) , V_104 ) ;
V_170 = V_47 ;
if ( ! V_47 )
return;
F_83 ( V_85 , 2 ) ;
V_170 -> V_182 = V_173 ;
V_26 = 0 ;
F_107 (ha, dev)
memcpy ( & V_170 -> V_183 [ V_26 ++ ] [ 0 ] , V_172 -> V_138 , V_181 ) ;
F_39 ( & V_85 [ 0 ] , V_170 ,
sizeof( V_170 -> V_182 ) + ( V_173 * V_181 ) ) ;
V_170 = ( void * ) & V_170 -> V_183 [ V_173 ] [ 0 ] ;
V_170 -> V_182 = V_174 ;
V_26 = 0 ;
F_108 (ha, dev)
memcpy ( & V_170 -> V_183 [ V_26 ++ ] [ 0 ] , V_172 -> V_138 , V_181 ) ;
F_39 ( & V_85 [ 1 ] , V_170 ,
sizeof( V_170 -> V_182 ) + ( V_174 * V_181 ) ) ;
if ( ! F_80 ( V_18 , V_142 ,
V_184 ,
V_85 , 2 , 0 ) )
F_73 ( & V_21 -> V_21 , L_20 ) ;
F_109 ( V_47 ) ;
}
static int F_110 ( struct V_48 * V_21 , T_6 V_185 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_122 V_85 ;
F_44 ( & V_85 , & V_185 , sizeof( V_185 ) ) ;
if ( ! F_80 ( V_18 , V_186 ,
V_187 , & V_85 , 1 , 0 ) )
F_73 ( & V_21 -> V_21 , L_21 , V_185 ) ;
return 0 ;
}
static int F_111 ( struct V_48 * V_21 , T_6 V_185 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_122 V_85 ;
F_44 ( & V_85 , & V_185 , sizeof( V_185 ) ) ;
if ( ! F_80 ( V_18 , V_186 ,
V_188 , & V_85 , 1 , 0 ) )
F_73 ( & V_21 -> V_21 , L_22 , V_185 ) ;
return 0 ;
}
static void F_112 ( struct V_17 * V_18 , long V_189 )
{
int V_26 ;
int V_151 ;
if ( V_18 -> V_190 ) {
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
F_113 ( V_18 -> V_10 [ V_26 ] . V_2 , - 1 ) ;
F_113 ( V_18 -> V_106 [ V_26 ] . V_2 , - 1 ) ;
}
V_18 -> V_190 = false ;
}
V_26 = 0 ;
F_114 (cpu) {
if ( V_151 == V_189 ) {
* F_92 ( V_18 -> V_191 , V_151 ) = - 1 ;
} else {
* F_92 ( V_18 -> V_191 , V_151 ) =
++ V_26 % V_18 -> V_157 ;
}
}
}
static void F_115 ( struct V_17 * V_18 )
{
int V_26 ;
int V_151 ;
if ( V_18 -> V_157 == 1 ||
V_18 -> V_97 != F_116 () ) {
F_112 ( V_18 , - 1 ) ;
return;
}
V_26 = 0 ;
F_114 (cpu) {
F_113 ( V_18 -> V_10 [ V_26 ] . V_2 , V_151 ) ;
F_113 ( V_18 -> V_106 [ V_26 ] . V_2 , V_151 ) ;
* F_92 ( V_18 -> V_191 , V_151 ) = V_26 ;
V_26 ++ ;
}
V_18 -> V_190 = true ;
}
static int F_117 ( struct V_192 * V_193 ,
unsigned long V_194 , void * V_189 )
{
struct V_17 * V_18 = F_55 ( V_193 , struct V_17 , V_195 ) ;
switch( V_194 & ~ V_196 ) {
case V_197 :
case V_198 :
case V_199 :
F_115 ( V_18 ) ;
break;
case V_200 :
F_112 ( V_18 , ( long ) V_189 ) ;
break;
default:
break;
}
return V_201 ;
}
static void F_118 ( struct V_48 * V_21 ,
struct V_202 * V_203 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
V_203 -> V_204 = F_119 ( V_18 -> V_10 [ 0 ] . V_2 ) ;
V_203 -> V_205 = F_119 ( V_18 -> V_106 [ 0 ] . V_2 ) ;
V_203 -> V_206 = V_203 -> V_204 ;
V_203 -> V_207 = V_203 -> V_205 ;
}
static void F_120 ( struct V_48 * V_21 ,
struct V_208 * V_209 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
struct V_135 * V_19 = V_18 -> V_19 ;
F_121 ( V_209 -> V_210 , V_211 , sizeof( V_209 -> V_210 ) ) ;
F_121 ( V_209 -> V_212 , V_213 , sizeof( V_209 -> V_212 ) ) ;
F_121 ( V_209 -> V_214 , F_122 ( V_19 ) , sizeof( V_209 -> V_214 ) ) ;
}
static int F_123 ( struct V_48 * V_21 ,
struct V_215 * V_216 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
T_6 V_160 = V_216 -> V_217 ;
int V_82 ;
if ( V_216 -> V_218 || V_216 -> V_219 || V_216 -> V_220 )
return - V_45 ;
if ( V_160 > V_18 -> V_97 )
return - V_45 ;
F_124 () ;
V_82 = F_100 ( V_18 , V_160 ) ;
if ( ! V_82 ) {
F_125 ( V_21 , V_160 ) ;
F_126 ( V_21 , V_160 ) ;
F_115 ( V_18 ) ;
}
F_127 () ;
return V_82 ;
}
static void F_128 ( struct V_48 * V_21 ,
struct V_215 * V_216 )
{
struct V_17 * V_18 = F_62 ( V_21 ) ;
V_216 -> V_217 = V_18 -> V_157 ;
V_216 -> V_221 = V_18 -> V_97 ;
V_216 -> V_222 = 0 ;
V_216 -> V_218 = 0 ;
V_216 -> V_219 = 0 ;
V_216 -> V_220 = 0 ;
}
static int F_129 ( struct V_48 * V_21 , int V_223 )
{
if ( V_223 < V_224 || V_223 > V_225 )
return - V_45 ;
V_21 -> V_226 = V_223 ;
return 0 ;
}
static T_6 F_130 ( struct V_48 * V_21 , struct V_6 * V_7 )
{
int V_3 ;
struct V_17 * V_18 = F_62 ( V_21 ) ;
if ( F_131 ( V_7 ) ) {
V_3 = F_132 ( V_7 ) ;
} else {
V_3 = * F_133 ( V_18 -> V_191 ) ;
if ( V_3 == - 1 )
V_3 = 0 ;
}
while ( F_19 ( V_3 >= V_21 -> V_227 ) )
V_3 -= V_21 -> V_227 ;
return V_3 ;
}
static void F_134 ( struct V_93 * V_94 )
{
struct V_17 * V_18 =
F_55 ( V_94 , struct V_17 , V_228 ) ;
T_6 V_229 ;
F_135 ( & V_18 -> V_230 ) ;
if ( ! V_18 -> V_231 )
goto V_232;
if ( F_136 ( V_18 -> V_19 , V_233 ,
F_89 ( struct V_147 , V_129 ) ,
& V_229 ) < 0 )
goto V_232;
if ( V_229 & V_234 ) {
F_137 ( V_18 -> V_21 ) ;
F_97 ( V_18 ) ;
}
V_229 &= V_235 ;
if ( V_18 -> V_129 == V_229 )
goto V_232;
V_18 -> V_129 = V_229 ;
if ( V_18 -> V_129 & V_235 ) {
F_138 ( V_18 -> V_21 ) ;
F_139 ( V_18 -> V_21 ) ;
} else {
F_140 ( V_18 -> V_21 ) ;
F_141 ( V_18 -> V_21 ) ;
}
V_232:
F_142 ( & V_18 -> V_230 ) ;
}
static void F_143 ( struct V_135 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
F_144 ( & V_18 -> V_228 ) ;
}
static void F_145 ( struct V_17 * V_18 )
{
F_109 ( V_18 -> V_10 ) ;
F_109 ( V_18 -> V_106 ) ;
}
static void F_146 ( struct V_17 * V_18 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
while ( V_18 -> V_10 [ V_26 ] . V_14 )
F_147 ( F_7 ( & V_18 -> V_10 [ V_26 ] , V_98 ) , 0 ) ;
}
}
static void F_148 ( struct V_17 * V_18 )
{
void * V_47 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
struct V_1 * V_2 = V_18 -> V_106 [ V_26 ] . V_2 ;
while ( ( V_47 = F_149 ( V_2 ) ) != NULL )
F_23 ( V_47 ) ;
}
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
struct V_1 * V_2 = V_18 -> V_10 [ V_26 ] . V_2 ;
while ( ( V_47 = F_149 ( V_2 ) ) != NULL ) {
if ( V_18 -> V_36 || V_18 -> V_52 )
F_6 ( & V_18 -> V_10 [ V_26 ] , V_47 ) ;
else
F_23 ( V_47 ) ;
-- V_18 -> V_10 [ V_26 ] . V_46 ;
}
F_81 ( V_18 -> V_10 [ V_26 ] . V_46 != 0 ) ;
}
}
static void F_150 ( struct V_17 * V_18 )
{
struct V_135 * V_19 = V_18 -> V_19 ;
F_112 ( V_18 , - 1 ) ;
V_19 -> V_145 -> V_236 ( V_19 ) ;
F_145 ( V_18 ) ;
}
static int F_151 ( struct V_17 * V_18 )
{
T_7 * * V_237 ;
struct V_1 * * V_238 ;
int V_136 = - V_84 ;
int V_26 , V_239 ;
const char * * V_240 ;
V_239 = V_18 -> V_97 * 2 +
F_82 ( V_18 -> V_19 , V_131 ) ;
V_238 = F_106 ( V_239 * sizeof( * V_238 ) , V_98 ) ;
if ( ! V_238 )
goto V_241;
V_237 = F_152 ( V_239 * sizeof( * V_237 ) , V_98 ) ;
if ( ! V_237 )
goto V_242;
V_240 = F_152 ( V_239 * sizeof( * V_240 ) , V_98 ) ;
if ( ! V_240 )
goto V_243;
if ( V_18 -> V_162 ) {
V_237 [ V_239 - 1 ] = NULL ;
V_240 [ V_239 - 1 ] = L_23 ;
}
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
V_237 [ F_5 ( V_26 ) ] = F_47 ;
V_237 [ F_3 ( V_26 ) ] = F_9 ;
sprintf ( V_18 -> V_10 [ V_26 ] . V_40 , L_24 , V_26 ) ;
sprintf ( V_18 -> V_106 [ V_26 ] . V_40 , L_25 , V_26 ) ;
V_240 [ F_5 ( V_26 ) ] = V_18 -> V_10 [ V_26 ] . V_40 ;
V_240 [ F_3 ( V_26 ) ] = V_18 -> V_106 [ V_26 ] . V_40 ;
}
V_136 = V_18 -> V_19 -> V_145 -> V_244 ( V_18 -> V_19 , V_239 , V_238 , V_237 ,
V_240 ) ;
if ( V_136 )
goto V_245;
if ( V_18 -> V_162 ) {
V_18 -> V_133 = V_238 [ V_239 - 1 ] ;
if ( F_82 ( V_18 -> V_19 , V_246 ) )
V_18 -> V_21 -> V_247 |= V_248 ;
}
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
V_18 -> V_10 [ V_26 ] . V_2 = V_238 [ F_5 ( V_26 ) ] ;
V_18 -> V_106 [ V_26 ] . V_2 = V_238 [ F_3 ( V_26 ) ] ;
}
F_109 ( V_240 ) ;
F_109 ( V_237 ) ;
F_109 ( V_238 ) ;
return 0 ;
V_245:
F_109 ( V_240 ) ;
V_243:
F_109 ( V_237 ) ;
V_242:
F_109 ( V_238 ) ;
V_241:
return V_136 ;
}
static int F_153 ( struct V_17 * V_18 )
{
int V_26 ;
V_18 -> V_106 = F_106 ( sizeof( * V_18 -> V_106 ) * V_18 -> V_97 , V_98 ) ;
if ( ! V_18 -> V_106 )
goto V_249;
V_18 -> V_10 = F_106 ( sizeof( * V_18 -> V_10 ) * V_18 -> V_97 , V_98 ) ;
if ( ! V_18 -> V_10 )
goto V_250;
F_154 ( & V_18 -> V_95 , F_54 ) ;
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
V_18 -> V_10 [ V_26 ] . V_14 = NULL ;
F_155 ( V_18 -> V_21 , & V_18 -> V_10 [ V_26 ] . V_92 , F_58 ,
V_251 ) ;
F_83 ( V_18 -> V_10 [ V_26 ] . V_85 , F_156 ( V_18 -> V_10 [ V_26 ] . V_85 ) ) ;
F_83 ( V_18 -> V_106 [ V_26 ] . V_85 , F_156 ( V_18 -> V_106 [ V_26 ] . V_85 ) ) ;
}
return 0 ;
V_250:
F_109 ( V_18 -> V_106 ) ;
V_249:
return - V_84 ;
}
static int F_157 ( struct V_17 * V_18 )
{
int V_136 ;
V_136 = F_153 ( V_18 ) ;
if ( V_136 )
goto V_82;
V_136 = F_151 ( V_18 ) ;
if ( V_136 )
goto V_252;
F_124 () ;
F_115 ( V_18 ) ;
F_127 () ;
return 0 ;
V_252:
F_145 ( V_18 ) ;
V_82:
return V_136 ;
}
static int F_158 ( struct V_135 * V_19 )
{
int V_26 , V_82 ;
struct V_48 * V_21 ;
struct V_17 * V_18 ;
T_6 V_97 ;
V_82 = F_136 ( V_19 , V_163 ,
F_89 ( struct V_147 ,
V_253 ) , & V_97 ) ;
if ( V_82 || V_97 < V_254 ||
V_97 > V_255 ||
! F_82 ( V_19 , V_131 ) )
V_97 = 1 ;
V_21 = F_159 ( sizeof( struct V_17 ) , V_97 ) ;
if ( ! V_21 )
return - V_84 ;
V_21 -> V_256 |= V_257 | V_258 ;
V_21 -> V_259 = & V_260 ;
V_21 -> V_247 = V_261 ;
F_160 ( V_21 , & V_262 ) ;
F_161 ( V_21 , & V_19 -> V_21 ) ;
if ( F_82 ( V_19 , V_263 ) ) {
V_21 -> V_264 |= V_265 | V_266 | V_267 ;
if ( V_268 )
V_21 -> V_247 |= V_265 | V_266 | V_267 ;
if ( F_82 ( V_19 , V_269 ) ) {
V_21 -> V_264 |= V_270 | V_271
| V_272 | V_273 ;
}
if ( F_82 ( V_19 , V_274 ) )
V_21 -> V_264 |= V_270 ;
if ( F_82 ( V_19 , V_275 ) )
V_21 -> V_264 |= V_273 ;
if ( F_82 ( V_19 , V_276 ) )
V_21 -> V_264 |= V_272 ;
if ( F_82 ( V_19 , V_277 ) )
V_21 -> V_264 |= V_271 ;
if ( V_278 )
V_21 -> V_247 |= V_21 -> V_264 & ( V_279 | V_271 ) ;
}
if ( F_162 ( V_19 , V_144 ,
F_89 ( struct V_147 , V_148 ) ,
V_21 -> V_280 , V_21 -> V_141 ) < 0 )
F_163 ( V_21 ) ;
V_18 = F_62 ( V_21 ) ;
V_18 -> V_21 = V_21 ;
V_18 -> V_19 = V_19 ;
V_19 -> V_20 = V_18 ;
V_18 -> V_43 = F_164 ( struct V_49 ) ;
V_82 = - V_84 ;
if ( V_18 -> V_43 == NULL )
goto free;
V_18 -> V_191 = F_164 ( int ) ;
if ( V_18 -> V_191 == NULL )
goto V_281;
F_165 ( & V_18 -> V_230 ) ;
V_18 -> V_231 = true ;
F_166 ( & V_18 -> V_228 , F_134 ) ;
if ( F_82 ( V_19 , V_282 ) ||
F_82 ( V_19 , V_283 ) ||
F_82 ( V_19 , V_284 ) )
V_18 -> V_52 = true ;
if ( F_82 ( V_19 , V_285 ) )
V_18 -> V_36 = true ;
if ( F_82 ( V_19 , V_131 ) )
V_18 -> V_162 = true ;
V_18 -> V_157 = 1 ;
V_18 -> V_97 = V_97 ;
V_82 = F_157 ( V_18 ) ;
if ( V_82 )
goto V_286;
F_125 ( V_21 , 1 ) ;
F_126 ( V_21 , 1 ) ;
V_82 = F_167 ( V_21 ) ;
if ( V_82 ) {
F_25 ( L_26 ) ;
goto V_287;
}
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
F_45 ( & V_18 -> V_10 [ V_26 ] , V_98 ) ;
if ( V_18 -> V_10 [ V_26 ] . V_46 == 0 ) {
F_148 ( V_18 ) ;
V_82 = - V_84 ;
goto V_288;
}
}
V_18 -> V_195 . V_289 = & F_117 ;
V_82 = F_168 ( & V_18 -> V_195 ) ;
if ( V_82 ) {
F_25 ( L_27 ) ;
goto V_288;
}
if ( F_82 ( V_18 -> V_19 , V_233 ) ) {
F_140 ( V_21 ) ;
F_144 ( & V_18 -> V_228 ) ;
} else {
V_18 -> V_129 = V_235 ;
F_138 ( V_21 ) ;
}
F_25 ( L_28 ,
V_21 -> V_40 , V_97 ) ;
return 0 ;
V_288:
F_146 ( V_18 ) ;
F_169 ( V_21 ) ;
V_287:
F_102 ( & V_18 -> V_95 ) ;
F_150 ( V_18 ) ;
V_286:
F_170 ( V_18 -> V_191 ) ;
V_281:
F_170 ( V_18 -> V_43 ) ;
free:
F_171 ( V_21 ) ;
return V_82 ;
}
static void F_172 ( struct V_17 * V_18 )
{
V_18 -> V_19 -> V_145 -> V_290 ( V_18 -> V_19 ) ;
F_148 ( V_18 ) ;
F_146 ( V_18 ) ;
F_150 ( V_18 ) ;
}
static void F_173 ( struct V_135 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
F_174 ( & V_18 -> V_195 ) ;
F_135 ( & V_18 -> V_230 ) ;
V_18 -> V_231 = false ;
F_142 ( & V_18 -> V_230 ) ;
F_169 ( V_18 -> V_21 ) ;
F_172 ( V_18 ) ;
F_175 ( & V_18 -> V_228 ) ;
F_170 ( V_18 -> V_191 ) ;
F_170 ( V_18 -> V_43 ) ;
F_171 ( V_18 -> V_21 ) ;
}
static int F_176 ( struct V_135 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
int V_26 ;
F_135 ( & V_18 -> V_230 ) ;
V_18 -> V_231 = false ;
F_142 ( & V_18 -> V_230 ) ;
F_177 ( V_18 -> V_21 ) ;
F_102 ( & V_18 -> V_95 ) ;
if ( F_178 ( V_18 -> V_21 ) )
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ ) {
F_56 ( & V_18 -> V_10 [ V_26 ] . V_92 ) ;
F_179 ( & V_18 -> V_10 [ V_26 ] . V_92 ) ;
}
F_172 ( V_18 ) ;
F_175 ( & V_18 -> V_228 ) ;
return 0 ;
}
static int F_180 ( struct V_135 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
int V_82 , V_26 ;
V_82 = F_157 ( V_18 ) ;
if ( V_82 )
return V_82 ;
if ( F_178 ( V_18 -> V_21 ) )
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ )
F_50 ( & V_18 -> V_10 [ V_26 ] ) ;
F_181 ( V_18 -> V_21 ) ;
for ( V_26 = 0 ; V_26 < V_18 -> V_97 ; V_26 ++ )
if ( ! F_45 ( & V_18 -> V_10 [ V_26 ] , V_98 ) )
F_57 ( & V_18 -> V_95 , 0 ) ;
F_135 ( & V_18 -> V_230 ) ;
V_18 -> V_231 = true ;
F_142 ( & V_18 -> V_230 ) ;
F_100 ( V_18 , V_18 -> V_157 ) ;
return 0 ;
}
