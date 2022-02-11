static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 - 1 ) / 2 ;
}
static int F_2 ( int V_4 )
{
return V_4 * 2 + 1 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 / 2 ;
}
static int F_4 ( int V_5 )
{
return V_5 * 2 ;
}
static inline struct V_6 * V_6 ( struct V_7 * V_8 )
{
return (struct V_6 * ) V_8 -> V_9 ;
}
static void F_5 ( struct V_10 * V_11 , struct V_12 * V_12 )
{
struct V_12 * V_13 ;
for ( V_13 = V_12 ; V_13 -> V_14 ; V_13 = (struct V_12 * ) V_13 -> V_14 ) ;
V_13 -> V_14 = ( unsigned long ) V_11 -> V_15 ;
V_11 -> V_15 = V_12 ;
}
static struct V_12 * F_6 ( struct V_10 * V_11 , T_1 V_16 )
{
struct V_12 * V_17 = V_11 -> V_15 ;
if ( V_17 ) {
V_11 -> V_15 = (struct V_12 * ) V_17 -> V_14 ;
V_17 -> V_14 = 0 ;
} else
V_17 = F_7 ( V_16 ) ;
return V_17 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 -> V_21 ;
F_9 ( V_2 ) ;
F_10 ( V_19 -> V_22 , F_1 ( V_2 ) ) ;
}
static void F_11 ( struct V_7 * V_8 , struct V_12 * V_12 ,
unsigned int V_23 , unsigned int * V_24 )
{
int V_25 = F_12 ( ( unsigned ) V_26 - V_23 , * V_24 ) ;
int V_27 = F_13 ( V_8 ) -> V_28 ;
F_14 ( V_8 , V_27 , V_12 , V_23 , V_25 ) ;
V_8 -> V_29 += V_25 ;
V_8 -> V_24 += V_25 ;
V_8 -> V_30 += V_26 ;
F_13 ( V_8 ) -> V_28 ++ ;
F_13 ( V_8 ) -> V_31 |= V_32 ;
* V_24 -= V_25 ;
}
static struct V_7 * F_15 ( struct V_10 * V_11 ,
struct V_12 * V_12 , unsigned int V_24 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
struct V_7 * V_8 ;
struct V_6 * V_33 ;
unsigned int V_34 , V_35 , V_23 ;
char * V_17 ;
V_17 = F_16 ( V_12 ) ;
V_8 = F_17 ( V_19 -> V_22 , V_36 ) ;
if ( F_18 ( ! V_8 ) )
return NULL ;
V_33 = V_6 ( V_8 ) ;
if ( V_19 -> V_37 ) {
V_35 = sizeof V_33 -> V_38 ;
V_23 = V_35 ;
} else {
V_35 = sizeof V_33 -> V_33 ;
V_23 = sizeof( struct V_39 ) ;
}
memcpy ( V_33 , V_17 , V_35 ) ;
V_24 -= V_35 ;
V_17 += V_23 ;
V_34 = V_24 ;
if ( V_34 > F_19 ( V_8 ) )
V_34 = F_19 ( V_8 ) ;
memcpy ( F_20 ( V_8 , V_34 ) , V_17 , V_34 ) ;
V_24 -= V_34 ;
V_23 += V_34 ;
if ( F_18 ( V_24 > V_40 * V_26 ) ) {
F_21 ( L_1 , V_8 -> V_22 -> V_41 ) ;
F_22 ( V_8 ) ;
return NULL ;
}
while ( V_24 ) {
F_11 ( V_8 , V_12 , V_23 , & V_24 ) ;
V_12 = (struct V_12 * ) V_12 -> V_14 ;
V_23 = 0 ;
}
if ( V_12 )
F_5 ( V_11 , V_12 ) ;
return V_8 ;
}
static int F_23 ( struct V_10 * V_11 , struct V_7 * V_8 )
{
struct V_6 * V_33 = V_6 ( V_8 ) ;
struct V_12 * V_12 ;
int V_42 , V_27 , V_24 ;
V_42 = V_33 -> V_38 . V_43 ;
while ( -- V_42 ) {
V_27 = F_13 ( V_8 ) -> V_28 ;
if ( V_27 >= V_40 ) {
F_24 ( L_2 , V_8 -> V_22 -> V_41 ) ;
V_8 -> V_22 -> V_44 . V_45 ++ ;
return - V_46 ;
}
V_12 = F_25 ( V_11 -> V_2 , & V_24 ) ;
if ( ! V_12 ) {
F_24 ( L_3 ,
V_8 -> V_22 -> V_41 , V_33 -> V_38 . V_43 ) ;
V_8 -> V_22 -> V_44 . V_45 ++ ;
return - V_46 ;
}
if ( V_24 > V_26 )
V_24 = V_26 ;
F_11 ( V_8 , V_12 , 0 , & V_24 ) ;
-- V_11 -> V_47 ;
}
return 0 ;
}
static void F_26 ( struct V_10 * V_11 , void * V_48 , unsigned int V_24 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
struct V_49 * V_22 = V_19 -> V_22 ;
struct V_50 * V_44 = F_27 ( V_19 -> V_44 ) ;
struct V_7 * V_8 ;
struct V_12 * V_12 ;
struct V_6 * V_33 ;
if ( F_18 ( V_24 < sizeof( struct V_51 ) + V_52 ) ) {
F_24 ( L_4 , V_22 -> V_41 , V_24 ) ;
V_22 -> V_44 . V_45 ++ ;
if ( V_19 -> V_37 || V_19 -> V_53 )
F_5 ( V_11 , V_48 ) ;
else
F_22 ( V_48 ) ;
return;
}
if ( ! V_19 -> V_37 && ! V_19 -> V_53 ) {
V_8 = V_48 ;
V_24 -= sizeof( struct V_51 ) ;
F_28 ( V_8 , V_24 ) ;
} else {
V_12 = V_48 ;
V_8 = F_15 ( V_11 , V_12 , V_24 ) ;
if ( F_18 ( ! V_8 ) ) {
V_22 -> V_44 . V_54 ++ ;
F_5 ( V_11 , V_12 ) ;
return;
}
if ( V_19 -> V_37 )
if ( F_23 ( V_11 , V_8 ) ) {
F_22 ( V_8 ) ;
return;
}
}
V_33 = V_6 ( V_8 ) ;
F_29 ( & V_44 -> V_55 ) ;
V_44 -> V_56 += V_8 -> V_24 ;
V_44 -> V_57 ++ ;
F_30 ( & V_44 -> V_55 ) ;
if ( V_33 -> V_33 . V_58 & V_59 ) {
F_24 ( L_5 ) ;
if ( ! F_31 ( V_8 ,
V_33 -> V_33 . V_60 ,
V_33 -> V_33 . V_61 ) )
goto V_62;
} else if ( V_33 -> V_33 . V_58 & V_63 ) {
V_8 -> V_64 = V_65 ;
}
V_8 -> V_66 = F_32 ( V_8 , V_22 ) ;
F_24 ( L_6 ,
F_33 ( V_8 -> V_66 ) , V_8 -> V_24 , V_8 -> V_67 ) ;
if ( V_33 -> V_33 . V_68 != V_69 ) {
F_24 ( L_7 ) ;
switch ( V_33 -> V_33 . V_68 & ~ V_70 ) {
case V_71 :
F_13 ( V_8 ) -> V_68 = V_72 ;
break;
case V_73 :
F_13 ( V_8 ) -> V_68 = V_74 ;
break;
case V_75 :
F_13 ( V_8 ) -> V_68 = V_76 ;
break;
default:
F_34 ( L_8 ,
V_22 -> V_41 , V_33 -> V_33 . V_68 ) ;
goto V_62;
}
if ( V_33 -> V_33 . V_68 & V_70 )
F_13 ( V_8 ) -> V_68 |= V_77 ;
F_13 ( V_8 ) -> V_78 = V_33 -> V_33 . V_78 ;
if ( F_13 ( V_8 ) -> V_78 == 0 ) {
F_34 ( L_9 , V_22 -> V_41 ) ;
goto V_62;
}
F_13 ( V_8 ) -> V_68 |= V_79 ;
F_13 ( V_8 ) -> V_80 = 0 ;
}
F_35 ( V_8 ) ;
return;
V_62:
V_22 -> V_44 . V_81 ++ ;
F_22 ( V_8 ) ;
}
static int F_36 ( struct V_10 * V_11 , T_1 V_82 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
struct V_7 * V_8 ;
struct V_6 * V_33 ;
int V_83 ;
V_8 = F_37 ( V_19 -> V_22 , V_84 , V_82 ) ;
if ( F_18 ( ! V_8 ) )
return - V_85 ;
F_20 ( V_8 , V_84 ) ;
V_33 = V_6 ( V_8 ) ;
F_38 ( V_11 -> V_86 , & V_33 -> V_33 , sizeof V_33 -> V_33 ) ;
F_39 ( V_8 , V_11 -> V_86 + 1 , 0 , V_8 -> V_24 ) ;
V_83 = F_40 ( V_11 -> V_2 , V_11 -> V_86 , 2 , V_8 , V_82 ) ;
if ( V_83 < 0 )
F_22 ( V_8 ) ;
return V_83 ;
}
static int F_41 ( struct V_10 * V_11 , T_1 V_82 )
{
struct V_12 * V_87 , * V_88 = NULL ;
char * V_17 ;
int V_27 , V_83 , V_23 ;
for ( V_27 = V_40 + 1 ; V_27 > 1 ; -- V_27 ) {
V_87 = F_6 ( V_11 , V_82 ) ;
if ( ! V_87 ) {
if ( V_88 )
F_5 ( V_11 , V_88 ) ;
return - V_85 ;
}
F_38 ( & V_11 -> V_86 [ V_27 ] , F_16 ( V_87 ) , V_26 ) ;
V_87 -> V_14 = ( unsigned long ) V_88 ;
V_88 = V_87 ;
}
V_87 = F_6 ( V_11 , V_82 ) ;
if ( ! V_87 ) {
F_5 ( V_11 , V_88 ) ;
return - V_85 ;
}
V_17 = F_16 ( V_87 ) ;
F_38 ( & V_11 -> V_86 [ 0 ] , V_17 , sizeof( struct V_51 ) ) ;
V_23 = sizeof( struct V_39 ) ;
F_38 ( & V_11 -> V_86 [ 1 ] , V_17 + V_23 , V_26 - V_23 ) ;
V_87 -> V_14 = ( unsigned long ) V_88 ;
V_83 = F_40 ( V_11 -> V_2 , V_11 -> V_86 , V_40 + 2 ,
V_87 , V_82 ) ;
if ( V_83 < 0 )
F_5 ( V_11 , V_87 ) ;
return V_83 ;
}
static int F_42 ( struct V_10 * V_11 , T_1 V_82 )
{
struct V_12 * V_12 ;
int V_83 ;
V_12 = F_6 ( V_11 , V_82 ) ;
if ( ! V_12 )
return - V_85 ;
F_43 ( V_11 -> V_86 , F_16 ( V_12 ) , V_26 ) ;
V_83 = F_40 ( V_11 -> V_2 , V_11 -> V_86 , 1 , V_12 , V_82 ) ;
if ( V_83 < 0 )
F_5 ( V_11 , V_12 ) ;
return V_83 ;
}
static bool F_44 ( struct V_10 * V_11 , T_1 V_82 )
{
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
int V_83 ;
bool V_89 ;
do {
if ( V_19 -> V_37 )
V_83 = F_42 ( V_11 , V_82 ) ;
else if ( V_19 -> V_53 )
V_83 = F_41 ( V_11 , V_82 ) ;
else
V_83 = F_36 ( V_11 , V_82 ) ;
V_89 = V_83 == - V_85 ;
if ( V_83 )
break;
++ V_11 -> V_47 ;
} while ( V_11 -> V_2 -> V_90 );
if ( F_18 ( V_11 -> V_47 > V_11 -> V_91 ) )
V_11 -> V_91 = V_11 -> V_47 ;
F_45 ( V_11 -> V_2 ) ;
return ! V_89 ;
}
static void F_46 ( struct V_1 * V_92 )
{
struct V_18 * V_19 = V_92 -> V_20 -> V_21 ;
struct V_10 * V_11 = & V_19 -> V_11 [ F_3 ( V_92 ) ] ;
if ( F_47 ( & V_11 -> V_93 ) ) {
F_9 ( V_92 ) ;
F_48 ( & V_11 -> V_93 ) ;
}
}
static void F_49 ( struct V_10 * V_11 )
{
F_50 ( & V_11 -> V_93 ) ;
if ( F_47 ( & V_11 -> V_93 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_51 () ;
F_48 ( & V_11 -> V_93 ) ;
F_52 () ;
}
}
static void F_53 ( struct V_94 * V_95 )
{
struct V_18 * V_19 =
F_54 ( V_95 , struct V_18 , V_96 . V_95 ) ;
bool V_97 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_98 ; V_27 ++ ) {
struct V_10 * V_11 = & V_19 -> V_11 [ V_27 ] ;
F_55 ( & V_11 -> V_93 ) ;
V_97 = ! F_44 ( V_11 , V_99 ) ;
F_49 ( V_11 ) ;
if ( V_97 )
F_56 ( & V_19 -> V_96 , V_100 / 2 ) ;
}
}
static int F_57 ( struct V_101 * V_93 , int V_102 )
{
struct V_10 * V_11 =
F_54 ( V_93 , struct V_10 , V_93 ) ;
struct V_18 * V_19 = V_11 -> V_2 -> V_20 -> V_21 ;
void * V_48 ;
unsigned int V_24 , V_103 = 0 ;
V_104:
while ( V_103 < V_102 &&
( V_48 = F_25 ( V_11 -> V_2 , & V_24 ) ) != NULL ) {
F_26 ( V_11 , V_48 , V_24 ) ;
-- V_11 -> V_47 ;
V_103 ++ ;
}
if ( V_11 -> V_47 < V_11 -> V_91 / 2 ) {
if ( ! F_44 ( V_11 , V_105 ) )
F_56 ( & V_19 -> V_96 , 0 ) ;
}
if ( V_103 < V_102 ) {
F_58 ( V_93 ) ;
if ( F_18 ( ! F_59 ( V_11 -> V_2 ) ) &&
F_47 ( V_93 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_48 ( V_93 ) ;
goto V_104;
}
}
return V_103 ;
}
static int F_60 ( struct V_49 * V_22 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
if ( V_27 < V_19 -> V_98 )
if ( ! F_44 ( & V_19 -> V_11 [ V_27 ] , V_99 ) )
F_56 ( & V_19 -> V_96 , 0 ) ;
F_49 ( & V_19 -> V_11 [ V_27 ] ) ;
}
return 0 ;
}
static void F_62 ( struct V_107 * V_108 )
{
struct V_7 * V_8 ;
unsigned int V_24 ;
struct V_18 * V_19 = V_108 -> V_2 -> V_20 -> V_21 ;
struct V_50 * V_44 = F_27 ( V_19 -> V_44 ) ;
while ( ( V_8 = F_25 ( V_108 -> V_2 , & V_24 ) ) != NULL ) {
F_24 ( L_10 , V_8 ) ;
F_29 ( & V_44 -> V_109 ) ;
V_44 -> V_110 += V_8 -> V_24 ;
V_44 -> V_111 ++ ;
F_30 ( & V_44 -> V_109 ) ;
F_63 ( V_8 ) ;
}
}
static int F_64 ( struct V_107 * V_108 , struct V_7 * V_8 )
{
struct V_6 * V_33 = V_6 ( V_8 ) ;
const unsigned char * V_112 = ( (struct V_113 * ) V_8 -> V_114 ) -> V_115 ;
struct V_18 * V_19 = V_108 -> V_2 -> V_20 -> V_21 ;
unsigned V_116 ;
F_24 ( L_11 , V_19 -> V_22 -> V_41 , V_8 , V_112 ) ;
if ( V_8 -> V_64 == V_117 ) {
V_33 -> V_33 . V_58 = V_59 ;
V_33 -> V_33 . V_60 = F_65 ( V_8 ) ;
V_33 -> V_33 . V_61 = V_8 -> V_61 ;
} else {
V_33 -> V_33 . V_58 = 0 ;
V_33 -> V_33 . V_61 = V_33 -> V_33 . V_60 = 0 ;
}
if ( F_66 ( V_8 ) ) {
V_33 -> V_33 . V_35 = F_67 ( V_8 ) ;
V_33 -> V_33 . V_78 = F_13 ( V_8 ) -> V_78 ;
if ( F_13 ( V_8 ) -> V_68 & V_72 )
V_33 -> V_33 . V_68 = V_71 ;
else if ( F_13 ( V_8 ) -> V_68 & V_76 )
V_33 -> V_33 . V_68 = V_75 ;
else if ( F_13 ( V_8 ) -> V_68 & V_74 )
V_33 -> V_33 . V_68 = V_73 ;
else
F_68 () ;
if ( F_13 ( V_8 ) -> V_68 & V_77 )
V_33 -> V_33 . V_68 |= V_70 ;
} else {
V_33 -> V_33 . V_68 = V_69 ;
V_33 -> V_33 . V_78 = V_33 -> V_33 . V_35 = 0 ;
}
V_33 -> V_38 . V_43 = 0 ;
if ( V_19 -> V_37 )
F_38 ( V_108 -> V_86 , & V_33 -> V_38 , sizeof V_33 -> V_38 ) ;
else
F_38 ( V_108 -> V_86 , & V_33 -> V_33 , sizeof V_33 -> V_33 ) ;
V_116 = F_39 ( V_8 , V_108 -> V_86 + 1 , 0 , V_8 -> V_24 ) + 1 ;
return F_69 ( V_108 -> V_2 , V_108 -> V_86 , V_116 , V_8 , V_105 ) ;
}
static T_2 F_70 ( struct V_7 * V_8 , struct V_49 * V_22 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
int V_118 = F_71 ( V_8 ) ;
struct V_107 * V_108 = & V_19 -> V_108 [ V_118 ] ;
int V_83 ;
F_62 ( V_108 ) ;
V_83 = F_64 ( V_108 , V_8 ) ;
if ( F_18 ( V_83 ) ) {
V_22 -> V_44 . V_119 ++ ;
if ( F_72 () )
F_73 ( & V_22 -> V_22 ,
L_12 , V_118 , V_83 ) ;
V_22 -> V_44 . V_120 ++ ;
F_74 ( V_8 ) ;
return V_121 ;
}
F_45 ( V_108 -> V_2 ) ;
F_75 ( V_8 ) ;
F_76 ( V_8 ) ;
if ( V_108 -> V_2 -> V_90 < 2 + V_40 ) {
F_77 ( V_22 , V_118 ) ;
if ( F_18 ( ! F_78 ( V_108 -> V_2 ) ) ) {
F_62 ( V_108 ) ;
if ( V_108 -> V_2 -> V_90 >= 2 + V_40 ) {
F_79 ( V_22 , V_118 ) ;
F_9 ( V_108 -> V_2 ) ;
}
}
}
return V_121 ;
}
static bool F_80 ( struct V_18 * V_19 , T_3 V_122 , T_3 V_123 ,
struct V_124 * V_125 ,
struct V_124 * V_126 )
{
struct V_124 * V_127 [ 4 ] , V_33 , V_128 ;
struct V_129 V_130 ;
T_4 V_131 = ~ 0 ;
unsigned V_132 = 0 , V_133 = 0 , V_134 ;
F_81 ( ! F_82 ( V_19 -> V_20 , V_135 ) ) ;
V_130 . V_122 = V_122 ;
V_130 . V_123 = V_123 ;
F_43 ( & V_33 , & V_130 , sizeof( V_130 ) ) ;
V_127 [ V_132 ++ ] = & V_33 ;
if ( V_125 )
V_127 [ V_132 ++ ] = V_125 ;
if ( V_126 )
V_127 [ V_132 + V_133 ++ ] = V_126 ;
F_43 ( & V_128 , & V_131 , sizeof( V_131 ) ) ;
V_127 [ V_132 + V_133 ++ ] = & V_128 ;
F_81 ( V_132 + V_133 > F_83 ( V_127 ) ) ;
F_81 ( F_84 ( V_19 -> V_136 , V_127 , V_132 , V_133 , V_19 , V_105 )
< 0 ) ;
F_45 ( V_19 -> V_136 ) ;
while ( ! F_25 ( V_19 -> V_136 , & V_134 ) )
F_85 () ;
return V_131 == V_137 ;
}
static int F_86 ( struct V_49 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
struct V_138 * V_20 = V_19 -> V_20 ;
int V_139 ;
struct V_140 * V_141 = V_17 ;
struct V_124 V_86 ;
V_139 = F_87 ( V_22 , V_17 ) ;
if ( V_139 )
return V_139 ;
if ( F_82 ( V_20 , V_142 ) ) {
F_43 ( & V_86 , V_141 -> V_143 , V_22 -> V_144 ) ;
if ( ! F_80 ( V_19 , V_145 ,
V_146 ,
& V_86 , NULL ) ) {
F_73 ( & V_20 -> V_22 ,
L_13 ) ;
return - V_46 ;
}
} else if ( F_82 ( V_20 , V_147 ) ) {
V_20 -> V_148 -> V_149 ( V_20 , F_88 ( struct V_150 , V_151 ) ,
V_141 -> V_143 , V_22 -> V_144 ) ;
}
F_89 ( V_22 , V_17 ) ;
return 0 ;
}
static struct V_152 * V_50 ( struct V_49 * V_22 ,
struct V_152 * V_153 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
int V_154 ;
unsigned int V_155 ;
F_90 (cpu) {
struct V_50 * V_44 = F_91 ( V_19 -> V_44 , V_154 ) ;
T_5 V_156 , V_157 , V_158 , V_159 ;
do {
V_155 = F_92 ( & V_44 -> V_109 ) ;
V_156 = V_44 -> V_111 ;
V_157 = V_44 -> V_110 ;
} while ( F_93 ( & V_44 -> V_109 , V_155 ) );
do {
V_155 = F_92 ( & V_44 -> V_55 ) ;
V_158 = V_44 -> V_57 ;
V_159 = V_44 -> V_56 ;
} while ( F_93 ( & V_44 -> V_55 , V_155 ) );
V_153 -> V_57 += V_158 ;
V_153 -> V_111 += V_156 ;
V_153 -> V_56 += V_159 ;
V_153 -> V_110 += V_157 ;
}
V_153 -> V_120 = V_22 -> V_44 . V_120 ;
V_153 -> V_119 = V_22 -> V_44 . V_119 ;
V_153 -> V_54 = V_22 -> V_44 . V_54 ;
V_153 -> V_45 = V_22 -> V_44 . V_45 ;
V_153 -> V_81 = V_22 -> V_44 . V_81 ;
return V_153 ;
}
static void F_94 ( struct V_49 * V_22 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_98 ; V_27 ++ )
F_95 ( & V_19 -> V_11 [ V_27 ] . V_93 ) ;
}
static void F_96 ( struct V_18 * V_19 )
{
F_97 () ;
if ( ! F_80 ( V_19 , V_160 ,
V_161 , NULL , NULL ) )
F_73 ( & V_19 -> V_22 -> V_22 , L_14 ) ;
F_98 () ;
}
static int F_99 ( struct V_18 * V_19 , T_6 V_162 )
{
struct V_124 V_86 ;
struct V_163 V_164 ;
struct V_49 * V_22 = V_19 -> V_22 ;
int V_27 ;
if ( ! V_19 -> V_165 || ! F_82 ( V_19 -> V_20 , V_166 ) )
return 0 ;
V_164 . V_167 = V_162 ;
F_43 ( & V_86 , & V_164 , sizeof( V_164 ) ) ;
if ( ! F_80 ( V_19 , V_168 ,
V_169 , & V_86 , NULL ) ) {
F_73 ( & V_22 -> V_22 , L_15 ,
V_162 ) ;
return - V_46 ;
} else {
for ( V_27 = V_19 -> V_98 ; V_27 < V_162 ; V_27 ++ )
if ( ! F_44 ( & V_19 -> V_11 [ V_27 ] , V_99 ) )
F_56 ( & V_19 -> V_96 , 0 ) ;
V_19 -> V_98 = V_162 ;
}
return 0 ;
}
static int F_100 ( struct V_49 * V_22 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
int V_27 ;
F_101 ( & V_19 -> V_96 ) ;
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ )
F_55 ( & V_19 -> V_11 [ V_27 ] . V_93 ) ;
return 0 ;
}
static void F_102 ( struct V_49 * V_22 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
struct V_124 V_86 [ 2 ] ;
T_3 V_170 , V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
int V_176 ;
int V_177 ;
void * V_48 ;
int V_27 ;
if ( ! F_82 ( V_19 -> V_20 , V_178 ) )
return;
V_170 = ( ( V_22 -> V_58 & V_179 ) != 0 ) ;
V_171 = ( ( V_22 -> V_58 & V_180 ) != 0 ) ;
F_43 ( V_86 , & V_170 , sizeof( V_170 ) ) ;
if ( ! F_80 ( V_19 , V_181 ,
V_182 ,
V_86 , NULL ) )
F_73 ( & V_22 -> V_22 , L_16 ,
V_170 ? L_17 : L_18 ) ;
F_43 ( V_86 , & V_171 , sizeof( V_171 ) ) ;
if ( ! F_80 ( V_19 , V_181 ,
V_183 ,
V_86 , NULL ) )
F_73 ( & V_22 -> V_22 , L_19 ,
V_171 ? L_17 : L_18 ) ;
V_176 = F_103 ( V_22 ) ;
V_177 = F_104 ( V_22 ) ;
V_48 = F_105 ( ( ( V_176 + V_177 ) * V_184 ) +
( 2 * sizeof( V_173 -> V_185 ) ) , V_105 ) ;
V_173 = V_48 ;
if ( ! V_48 )
return;
F_106 ( V_86 , 2 ) ;
V_173 -> V_185 = V_176 ;
V_27 = 0 ;
F_107 (ha, dev)
memcpy ( & V_173 -> V_186 [ V_27 ++ ] [ 0 ] , V_175 -> V_141 , V_184 ) ;
F_38 ( & V_86 [ 0 ] , V_173 ,
sizeof( V_173 -> V_185 ) + ( V_176 * V_184 ) ) ;
V_173 = ( void * ) & V_173 -> V_186 [ V_176 ] [ 0 ] ;
V_173 -> V_185 = V_177 ;
V_27 = 0 ;
F_108 (ha, dev)
memcpy ( & V_173 -> V_186 [ V_27 ++ ] [ 0 ] , V_175 -> V_141 , V_184 ) ;
F_38 ( & V_86 [ 1 ] , V_173 ,
sizeof( V_173 -> V_185 ) + ( V_177 * V_184 ) ) ;
if ( ! F_80 ( V_19 , V_145 ,
V_187 ,
V_86 , NULL ) )
F_73 ( & V_22 -> V_22 , L_20 ) ;
F_109 ( V_48 ) ;
}
static int F_110 ( struct V_49 * V_22 ,
T_7 V_188 , T_6 V_189 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
struct V_124 V_86 ;
F_43 ( & V_86 , & V_189 , sizeof( V_189 ) ) ;
if ( ! F_80 ( V_19 , V_190 ,
V_191 , & V_86 , NULL ) )
F_73 ( & V_22 -> V_22 , L_21 , V_189 ) ;
return 0 ;
}
static int F_111 ( struct V_49 * V_22 ,
T_7 V_188 , T_6 V_189 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
struct V_124 V_86 ;
F_43 ( & V_86 , & V_189 , sizeof( V_189 ) ) ;
if ( ! F_80 ( V_19 , V_190 ,
V_192 , & V_86 , NULL ) )
F_73 ( & V_22 -> V_22 , L_22 , V_189 ) ;
return 0 ;
}
static void F_112 ( struct V_18 * V_19 , long V_193 )
{
int V_27 ;
int V_154 ;
if ( V_19 -> V_194 ) {
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
F_113 ( V_19 -> V_11 [ V_27 ] . V_2 , - 1 ) ;
F_113 ( V_19 -> V_108 [ V_27 ] . V_2 , - 1 ) ;
}
V_19 -> V_194 = false ;
}
V_27 = 0 ;
F_114 (cpu) {
if ( V_154 == V_193 ) {
* F_91 ( V_19 -> V_195 , V_154 ) = - 1 ;
} else {
* F_91 ( V_19 -> V_195 , V_154 ) =
++ V_27 % V_19 -> V_98 ;
}
}
}
static void F_115 ( struct V_18 * V_19 )
{
int V_27 ;
int V_154 ;
if ( V_19 -> V_98 == 1 ||
V_19 -> V_106 != F_116 () ) {
F_112 ( V_19 , - 1 ) ;
return;
}
V_27 = 0 ;
F_114 (cpu) {
F_113 ( V_19 -> V_11 [ V_27 ] . V_2 , V_154 ) ;
F_113 ( V_19 -> V_108 [ V_27 ] . V_2 , V_154 ) ;
* F_91 ( V_19 -> V_195 , V_154 ) = V_27 ;
V_27 ++ ;
}
V_19 -> V_194 = true ;
}
static int F_117 ( struct V_196 * V_197 ,
unsigned long V_198 , void * V_193 )
{
struct V_18 * V_19 = F_54 ( V_197 , struct V_18 , V_199 ) ;
switch( V_198 & ~ V_200 ) {
case V_201 :
case V_202 :
case V_203 :
F_115 ( V_19 ) ;
break;
case V_204 :
F_112 ( V_19 , ( long ) V_193 ) ;
break;
default:
break;
}
return V_205 ;
}
static void F_118 ( struct V_49 * V_22 ,
struct V_206 * V_207 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
V_207 -> V_208 = F_119 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_207 -> V_209 = F_119 ( V_19 -> V_108 [ 0 ] . V_2 ) ;
V_207 -> V_210 = V_207 -> V_208 ;
V_207 -> V_211 = V_207 -> V_209 ;
}
static void F_120 ( struct V_49 * V_22 ,
struct V_212 * V_213 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
struct V_138 * V_20 = V_19 -> V_20 ;
F_121 ( V_213 -> V_214 , V_215 , sizeof( V_213 -> V_214 ) ) ;
F_121 ( V_213 -> V_216 , V_217 , sizeof( V_213 -> V_216 ) ) ;
F_121 ( V_213 -> V_218 , F_122 ( V_20 ) , sizeof( V_213 -> V_218 ) ) ;
}
static int F_123 ( struct V_49 * V_22 ,
struct V_219 * V_220 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
T_6 V_162 = V_220 -> V_221 ;
int V_83 ;
if ( V_220 -> V_222 || V_220 -> V_223 || V_220 -> V_224 )
return - V_46 ;
if ( V_162 > V_19 -> V_106 )
return - V_46 ;
F_124 () ;
V_83 = F_99 ( V_19 , V_162 ) ;
if ( ! V_83 ) {
F_125 ( V_22 , V_162 ) ;
F_126 ( V_22 , V_162 ) ;
F_115 ( V_19 ) ;
}
F_127 () ;
return V_83 ;
}
static void F_128 ( struct V_49 * V_22 ,
struct V_219 * V_220 )
{
struct V_18 * V_19 = F_61 ( V_22 ) ;
V_220 -> V_221 = V_19 -> V_98 ;
V_220 -> V_225 = V_19 -> V_106 ;
V_220 -> V_226 = 0 ;
V_220 -> V_222 = 0 ;
V_220 -> V_223 = 0 ;
V_220 -> V_224 = 0 ;
}
static int F_129 ( struct V_49 * V_22 , int V_227 )
{
if ( V_227 < V_228 || V_227 > V_229 )
return - V_46 ;
V_22 -> V_230 = V_227 ;
return 0 ;
}
static T_6 F_130 ( struct V_49 * V_22 , struct V_7 * V_8 )
{
int V_4 ;
struct V_18 * V_19 = F_61 ( V_22 ) ;
if ( F_131 ( V_8 ) ) {
V_4 = F_132 ( V_8 ) ;
} else {
V_4 = * F_133 ( V_19 -> V_195 ) ;
if ( V_4 == - 1 )
V_4 = 0 ;
}
while ( F_18 ( V_4 >= V_22 -> V_231 ) )
V_4 -= V_22 -> V_231 ;
return V_4 ;
}
static void F_134 ( struct V_94 * V_95 )
{
struct V_18 * V_19 =
F_54 ( V_95 , struct V_18 , V_232 ) ;
T_6 V_233 ;
F_135 ( & V_19 -> V_234 ) ;
if ( ! V_19 -> V_235 )
goto V_236;
if ( F_136 ( V_19 -> V_20 , V_237 ,
F_88 ( struct V_150 , V_131 ) ,
& V_233 ) < 0 )
goto V_236;
if ( V_233 & V_238 ) {
F_137 ( V_19 -> V_22 ) ;
F_96 ( V_19 ) ;
}
V_233 &= V_239 ;
if ( V_19 -> V_131 == V_233 )
goto V_236;
V_19 -> V_131 = V_233 ;
if ( V_19 -> V_131 & V_239 ) {
F_138 ( V_19 -> V_22 ) ;
F_139 ( V_19 -> V_22 ) ;
} else {
F_140 ( V_19 -> V_22 ) ;
F_141 ( V_19 -> V_22 ) ;
}
V_236:
F_142 ( & V_19 -> V_234 ) ;
}
static void F_143 ( struct V_138 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_144 ( & V_19 -> V_232 ) ;
}
static void F_145 ( struct V_18 * V_19 )
{
F_109 ( V_19 -> V_11 ) ;
F_109 ( V_19 -> V_108 ) ;
}
static void F_146 ( struct V_18 * V_19 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
while ( V_19 -> V_11 [ V_27 ] . V_15 )
F_147 ( F_6 ( & V_19 -> V_11 [ V_27 ] , V_99 ) , 0 ) ;
}
}
static void F_148 ( struct V_18 * V_19 )
{
void * V_48 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
struct V_1 * V_2 = V_19 -> V_108 [ V_27 ] . V_2 ;
while ( ( V_48 = F_149 ( V_2 ) ) != NULL )
F_22 ( V_48 ) ;
}
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_27 ] . V_2 ;
while ( ( V_48 = F_149 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_37 || V_19 -> V_53 )
F_5 ( & V_19 -> V_11 [ V_27 ] , V_48 ) ;
else
F_22 ( V_48 ) ;
-- V_19 -> V_11 [ V_27 ] . V_47 ;
}
F_81 ( V_19 -> V_11 [ V_27 ] . V_47 != 0 ) ;
}
}
static void F_150 ( struct V_18 * V_19 )
{
struct V_138 * V_20 = V_19 -> V_20 ;
F_112 ( V_19 , - 1 ) ;
V_20 -> V_148 -> V_240 ( V_20 ) ;
F_145 ( V_19 ) ;
}
static int F_151 ( struct V_18 * V_19 )
{
T_8 * * V_241 ;
struct V_1 * * V_242 ;
int V_139 = - V_85 ;
int V_27 , V_243 ;
const char * * V_244 ;
V_243 = V_19 -> V_106 * 2 +
F_82 ( V_19 -> V_20 , V_135 ) ;
V_242 = F_105 ( V_243 * sizeof( * V_242 ) , V_99 ) ;
if ( ! V_242 )
goto V_245;
V_241 = F_152 ( V_243 * sizeof( * V_241 ) , V_99 ) ;
if ( ! V_241 )
goto V_246;
V_244 = F_152 ( V_243 * sizeof( * V_244 ) , V_99 ) ;
if ( ! V_244 )
goto V_247;
if ( V_19 -> V_165 ) {
V_241 [ V_243 - 1 ] = NULL ;
V_244 [ V_243 - 1 ] = L_23 ;
}
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
V_241 [ F_4 ( V_27 ) ] = F_46 ;
V_241 [ F_2 ( V_27 ) ] = F_8 ;
sprintf ( V_19 -> V_11 [ V_27 ] . V_41 , L_24 , V_27 ) ;
sprintf ( V_19 -> V_108 [ V_27 ] . V_41 , L_25 , V_27 ) ;
V_244 [ F_4 ( V_27 ) ] = V_19 -> V_11 [ V_27 ] . V_41 ;
V_244 [ F_2 ( V_27 ) ] = V_19 -> V_108 [ V_27 ] . V_41 ;
}
V_139 = V_19 -> V_20 -> V_148 -> V_248 ( V_19 -> V_20 , V_243 , V_242 , V_241 ,
V_244 ) ;
if ( V_139 )
goto V_249;
if ( V_19 -> V_165 ) {
V_19 -> V_136 = V_242 [ V_243 - 1 ] ;
if ( F_82 ( V_19 -> V_20 , V_250 ) )
V_19 -> V_22 -> V_251 |= V_252 ;
}
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
V_19 -> V_11 [ V_27 ] . V_2 = V_242 [ F_4 ( V_27 ) ] ;
V_19 -> V_108 [ V_27 ] . V_2 = V_242 [ F_2 ( V_27 ) ] ;
}
F_109 ( V_244 ) ;
F_109 ( V_241 ) ;
F_109 ( V_242 ) ;
return 0 ;
V_249:
F_109 ( V_244 ) ;
V_247:
F_109 ( V_241 ) ;
V_246:
F_109 ( V_242 ) ;
V_245:
return V_139 ;
}
static int F_153 ( struct V_18 * V_19 )
{
int V_27 ;
V_19 -> V_108 = F_105 ( sizeof( * V_19 -> V_108 ) * V_19 -> V_106 , V_99 ) ;
if ( ! V_19 -> V_108 )
goto V_253;
V_19 -> V_11 = F_105 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_106 , V_99 ) ;
if ( ! V_19 -> V_11 )
goto V_254;
F_154 ( & V_19 -> V_96 , F_53 ) ;
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
V_19 -> V_11 [ V_27 ] . V_15 = NULL ;
F_155 ( V_19 -> V_22 , & V_19 -> V_11 [ V_27 ] . V_93 , F_57 ,
V_255 ) ;
F_106 ( V_19 -> V_11 [ V_27 ] . V_86 , F_83 ( V_19 -> V_11 [ V_27 ] . V_86 ) ) ;
F_106 ( V_19 -> V_108 [ V_27 ] . V_86 , F_83 ( V_19 -> V_108 [ V_27 ] . V_86 ) ) ;
}
return 0 ;
V_254:
F_109 ( V_19 -> V_108 ) ;
V_253:
return - V_85 ;
}
static int F_156 ( struct V_18 * V_19 )
{
int V_139 ;
V_139 = F_153 ( V_19 ) ;
if ( V_139 )
goto V_83;
V_139 = F_151 ( V_19 ) ;
if ( V_139 )
goto V_256;
F_124 () ;
F_115 ( V_19 ) ;
F_127 () ;
return 0 ;
V_256:
F_145 ( V_19 ) ;
V_83:
return V_139 ;
}
static int F_157 ( struct V_138 * V_20 )
{
int V_27 , V_83 ;
struct V_49 * V_22 ;
struct V_18 * V_19 ;
T_6 V_106 ;
V_83 = F_136 ( V_20 , V_166 ,
F_88 ( struct V_150 ,
V_257 ) , & V_106 ) ;
if ( V_83 || V_106 < V_258 ||
V_106 > V_259 ||
! F_82 ( V_20 , V_135 ) )
V_106 = 1 ;
V_22 = F_158 ( sizeof( struct V_18 ) , V_106 ) ;
if ( ! V_22 )
return - V_85 ;
V_22 -> V_260 |= V_261 | V_262 ;
V_22 -> V_263 = & V_264 ;
V_22 -> V_251 = V_265 ;
F_159 ( V_22 , & V_266 ) ;
F_160 ( V_22 , & V_20 -> V_22 ) ;
if ( F_82 ( V_20 , V_267 ) ) {
V_22 -> V_268 |= V_269 | V_270 | V_271 ;
if ( V_272 )
V_22 -> V_251 |= V_269 | V_270 | V_271 ;
if ( F_82 ( V_20 , V_273 ) ) {
V_22 -> V_268 |= V_274 | V_275
| V_276 | V_277 ;
}
if ( F_82 ( V_20 , V_278 ) )
V_22 -> V_268 |= V_274 ;
if ( F_82 ( V_20 , V_279 ) )
V_22 -> V_268 |= V_277 ;
if ( F_82 ( V_20 , V_280 ) )
V_22 -> V_268 |= V_276 ;
if ( F_82 ( V_20 , V_281 ) )
V_22 -> V_268 |= V_275 ;
if ( V_282 )
V_22 -> V_251 |= V_22 -> V_268 & ( V_283 | V_275 ) ;
}
V_22 -> V_284 = V_22 -> V_251 ;
if ( F_161 ( V_20 , V_147 ,
F_88 ( struct V_150 , V_151 ) ,
V_22 -> V_285 , V_22 -> V_144 ) < 0 )
F_162 ( V_22 ) ;
V_19 = F_61 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_44 = F_163 ( struct V_50 ) ;
V_83 = - V_85 ;
if ( V_19 -> V_44 == NULL )
goto free;
V_19 -> V_195 = F_163 ( int ) ;
if ( V_19 -> V_195 == NULL )
goto V_286;
F_164 ( & V_19 -> V_234 ) ;
V_19 -> V_235 = true ;
F_165 ( & V_19 -> V_232 , F_134 ) ;
if ( F_82 ( V_20 , V_287 ) ||
F_82 ( V_20 , V_288 ) ||
F_82 ( V_20 , V_289 ) )
V_19 -> V_53 = true ;
if ( F_82 ( V_20 , V_290 ) )
V_19 -> V_37 = true ;
if ( F_82 ( V_20 , V_135 ) )
V_19 -> V_165 = true ;
V_19 -> V_98 = 1 ;
V_19 -> V_106 = V_106 ;
V_83 = F_156 ( V_19 ) ;
if ( V_83 )
goto V_291;
F_125 ( V_22 , 1 ) ;
F_126 ( V_22 , 1 ) ;
V_83 = F_166 ( V_22 ) ;
if ( V_83 ) {
F_24 ( L_26 ) ;
goto V_292;
}
for ( V_27 = 0 ; V_27 < V_19 -> V_98 ; V_27 ++ ) {
F_44 ( & V_19 -> V_11 [ V_27 ] , V_99 ) ;
if ( V_19 -> V_11 [ V_27 ] . V_47 == 0 ) {
F_148 ( V_19 ) ;
V_83 = - V_85 ;
goto V_293;
}
}
V_19 -> V_199 . V_294 = & F_117 ;
V_83 = F_167 ( & V_19 -> V_199 ) ;
if ( V_83 ) {
F_24 ( L_27 ) ;
goto V_293;
}
if ( F_82 ( V_19 -> V_20 , V_237 ) ) {
F_140 ( V_22 ) ;
F_144 ( & V_19 -> V_232 ) ;
} else {
V_19 -> V_131 = V_239 ;
F_138 ( V_22 ) ;
}
F_24 ( L_28 ,
V_22 -> V_41 , V_106 ) ;
return 0 ;
V_293:
F_146 ( V_19 ) ;
F_168 ( V_22 ) ;
V_292:
F_101 ( & V_19 -> V_96 ) ;
F_150 ( V_19 ) ;
V_291:
F_169 ( V_19 -> V_195 ) ;
V_286:
F_169 ( V_19 -> V_44 ) ;
free:
F_170 ( V_22 ) ;
return V_83 ;
}
static void F_171 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_148 -> V_295 ( V_19 -> V_20 ) ;
F_148 ( V_19 ) ;
F_146 ( V_19 ) ;
F_150 ( V_19 ) ;
}
static void F_172 ( struct V_138 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_173 ( & V_19 -> V_199 ) ;
F_135 ( & V_19 -> V_234 ) ;
V_19 -> V_235 = false ;
F_142 ( & V_19 -> V_234 ) ;
F_168 ( V_19 -> V_22 ) ;
F_171 ( V_19 ) ;
F_174 ( & V_19 -> V_232 ) ;
F_169 ( V_19 -> V_195 ) ;
F_169 ( V_19 -> V_44 ) ;
F_170 ( V_19 -> V_22 ) ;
}
static int F_175 ( struct V_138 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_27 ;
F_135 ( & V_19 -> V_234 ) ;
V_19 -> V_235 = false ;
F_142 ( & V_19 -> V_234 ) ;
F_176 ( V_19 -> V_22 ) ;
F_101 ( & V_19 -> V_96 ) ;
if ( F_177 ( V_19 -> V_22 ) )
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ ) {
F_55 ( & V_19 -> V_11 [ V_27 ] . V_93 ) ;
F_178 ( & V_19 -> V_11 [ V_27 ] . V_93 ) ;
}
F_171 ( V_19 ) ;
F_174 ( & V_19 -> V_232 ) ;
return 0 ;
}
static int F_179 ( struct V_138 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_83 , V_27 ;
V_83 = F_156 ( V_19 ) ;
if ( V_83 )
return V_83 ;
if ( F_177 ( V_19 -> V_22 ) )
for ( V_27 = 0 ; V_27 < V_19 -> V_106 ; V_27 ++ )
F_49 ( & V_19 -> V_11 [ V_27 ] ) ;
F_180 ( V_19 -> V_22 ) ;
for ( V_27 = 0 ; V_27 < V_19 -> V_98 ; V_27 ++ )
if ( ! F_44 ( & V_19 -> V_11 [ V_27 ] , V_99 ) )
F_56 ( & V_19 -> V_96 , 0 ) ;
F_135 ( & V_19 -> V_234 ) ;
V_19 -> V_235 = true ;
F_142 ( & V_19 -> V_234 ) ;
F_99 ( V_19 , V_19 -> V_98 ) ;
return 0 ;
}
