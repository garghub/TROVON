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
unsigned int V_103 , V_24 , V_104 = 0 ;
V_105:
while ( V_104 < V_102 &&
( V_48 = F_25 ( V_11 -> V_2 , & V_24 ) ) != NULL ) {
F_26 ( V_11 , V_48 , V_24 ) ;
-- V_11 -> V_47 ;
V_104 ++ ;
}
if ( V_11 -> V_47 < V_11 -> V_91 / 2 ) {
if ( ! F_44 ( V_11 , V_106 ) )
F_56 ( & V_19 -> V_96 , 0 ) ;
}
if ( V_104 < V_102 ) {
V_103 = F_58 ( V_11 -> V_2 ) ;
F_59 ( V_93 ) ;
if ( F_18 ( F_60 ( V_11 -> V_2 , V_103 ) ) &&
F_47 ( V_93 ) ) {
F_9 ( V_11 -> V_2 ) ;
F_48 ( V_93 ) ;
goto V_105;
}
}
return V_104 ;
}
static int F_61 ( struct V_49 * V_22 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
if ( V_27 < V_19 -> V_98 )
if ( ! F_44 ( & V_19 -> V_11 [ V_27 ] , V_99 ) )
F_56 ( & V_19 -> V_96 , 0 ) ;
F_49 ( & V_19 -> V_11 [ V_27 ] ) ;
}
return 0 ;
}
static void F_63 ( struct V_108 * V_109 )
{
struct V_7 * V_8 ;
unsigned int V_24 ;
struct V_18 * V_19 = V_109 -> V_2 -> V_20 -> V_21 ;
struct V_50 * V_44 = F_27 ( V_19 -> V_44 ) ;
while ( ( V_8 = F_25 ( V_109 -> V_2 , & V_24 ) ) != NULL ) {
F_24 ( L_10 , V_8 ) ;
F_29 ( & V_44 -> V_110 ) ;
V_44 -> V_111 += V_8 -> V_24 ;
V_44 -> V_112 ++ ;
F_30 ( & V_44 -> V_110 ) ;
F_64 ( V_8 ) ;
}
}
static int F_65 ( struct V_108 * V_109 , struct V_7 * V_8 )
{
struct V_6 * V_33 = V_6 ( V_8 ) ;
const unsigned char * V_113 = ( (struct V_114 * ) V_8 -> V_115 ) -> V_116 ;
struct V_18 * V_19 = V_109 -> V_2 -> V_20 -> V_21 ;
unsigned V_117 ;
F_24 ( L_11 , V_19 -> V_22 -> V_41 , V_8 , V_113 ) ;
if ( V_8 -> V_64 == V_118 ) {
V_33 -> V_33 . V_58 = V_59 ;
V_33 -> V_33 . V_60 = F_66 ( V_8 ) ;
V_33 -> V_33 . V_61 = V_8 -> V_61 ;
} else {
V_33 -> V_33 . V_58 = 0 ;
V_33 -> V_33 . V_61 = V_33 -> V_33 . V_60 = 0 ;
}
if ( F_67 ( V_8 ) ) {
V_33 -> V_33 . V_35 = F_68 ( V_8 ) ;
V_33 -> V_33 . V_78 = F_13 ( V_8 ) -> V_78 ;
if ( F_13 ( V_8 ) -> V_68 & V_72 )
V_33 -> V_33 . V_68 = V_71 ;
else if ( F_13 ( V_8 ) -> V_68 & V_76 )
V_33 -> V_33 . V_68 = V_75 ;
else if ( F_13 ( V_8 ) -> V_68 & V_74 )
V_33 -> V_33 . V_68 = V_73 ;
else
F_69 () ;
if ( F_13 ( V_8 ) -> V_68 & V_77 )
V_33 -> V_33 . V_68 |= V_70 ;
} else {
V_33 -> V_33 . V_68 = V_69 ;
V_33 -> V_33 . V_78 = V_33 -> V_33 . V_35 = 0 ;
}
V_33 -> V_38 . V_43 = 0 ;
if ( V_19 -> V_37 )
F_38 ( V_109 -> V_86 , & V_33 -> V_38 , sizeof V_33 -> V_38 ) ;
else
F_38 ( V_109 -> V_86 , & V_33 -> V_33 , sizeof V_33 -> V_33 ) ;
V_117 = F_39 ( V_8 , V_109 -> V_86 + 1 , 0 , V_8 -> V_24 ) + 1 ;
return F_70 ( V_109 -> V_2 , V_109 -> V_86 , V_117 , V_8 , V_106 ) ;
}
static T_2 F_71 ( struct V_7 * V_8 , struct V_49 * V_22 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
int V_119 = F_72 ( V_8 ) ;
struct V_108 * V_109 = & V_19 -> V_109 [ V_119 ] ;
int V_83 ;
F_63 ( V_109 ) ;
V_83 = F_65 ( V_109 , V_8 ) ;
if ( F_18 ( V_83 ) ) {
V_22 -> V_44 . V_120 ++ ;
if ( F_73 () )
F_74 ( & V_22 -> V_22 ,
L_12 , V_119 , V_83 ) ;
V_22 -> V_44 . V_121 ++ ;
F_75 ( V_8 ) ;
return V_122 ;
}
F_45 ( V_109 -> V_2 ) ;
F_76 ( V_8 ) ;
F_77 ( V_8 ) ;
if ( V_109 -> V_2 -> V_90 < 2 + V_40 ) {
F_78 ( V_22 , V_119 ) ;
if ( F_18 ( ! F_79 ( V_109 -> V_2 ) ) ) {
F_63 ( V_109 ) ;
if ( V_109 -> V_2 -> V_90 >= 2 + V_40 ) {
F_80 ( V_22 , V_119 ) ;
F_9 ( V_109 -> V_2 ) ;
}
}
}
return V_122 ;
}
static bool F_81 ( struct V_18 * V_19 , T_3 V_123 , T_3 V_124 ,
struct V_125 * V_126 ,
struct V_125 * V_127 )
{
struct V_125 * V_128 [ 4 ] , V_33 , V_129 ;
struct V_130 V_131 ;
T_4 V_132 = ~ 0 ;
unsigned V_133 = 0 , V_134 = 0 , V_135 ;
F_82 ( ! F_83 ( V_19 -> V_20 , V_136 ) ) ;
V_131 . V_123 = V_123 ;
V_131 . V_124 = V_124 ;
F_43 ( & V_33 , & V_131 , sizeof( V_131 ) ) ;
V_128 [ V_133 ++ ] = & V_33 ;
if ( V_126 )
V_128 [ V_133 ++ ] = V_126 ;
if ( V_127 )
V_128 [ V_133 + V_134 ++ ] = V_127 ;
F_43 ( & V_129 , & V_132 , sizeof( V_132 ) ) ;
V_128 [ V_133 + V_134 ++ ] = & V_129 ;
F_82 ( V_133 + V_134 > F_84 ( V_128 ) ) ;
F_82 ( F_85 ( V_19 -> V_137 , V_128 , V_133 , V_134 , V_19 , V_106 )
< 0 ) ;
F_45 ( V_19 -> V_137 ) ;
while ( ! F_25 ( V_19 -> V_137 , & V_135 ) )
F_86 () ;
return V_132 == V_138 ;
}
static int F_87 ( struct V_49 * V_22 , void * V_17 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
struct V_139 * V_20 = V_19 -> V_20 ;
int V_140 ;
struct V_141 * V_142 = V_17 ;
struct V_125 V_86 ;
V_140 = F_88 ( V_22 , V_17 ) ;
if ( V_140 )
return V_140 ;
if ( F_83 ( V_20 , V_143 ) ) {
F_43 ( & V_86 , V_142 -> V_144 , V_22 -> V_145 ) ;
if ( ! F_81 ( V_19 , V_146 ,
V_147 ,
& V_86 , NULL ) ) {
F_74 ( & V_20 -> V_22 ,
L_13 ) ;
return - V_46 ;
}
} else if ( F_83 ( V_20 , V_148 ) ) {
V_20 -> V_149 -> V_150 ( V_20 , F_89 ( struct V_151 , V_152 ) ,
V_142 -> V_144 , V_22 -> V_145 ) ;
}
F_90 ( V_22 , V_17 ) ;
return 0 ;
}
static struct V_153 * V_50 ( struct V_49 * V_22 ,
struct V_153 * V_154 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
int V_155 ;
unsigned int V_156 ;
F_91 (cpu) {
struct V_50 * V_44 = F_92 ( V_19 -> V_44 , V_155 ) ;
T_5 V_157 , V_158 , V_159 , V_160 ;
do {
V_156 = F_93 ( & V_44 -> V_110 ) ;
V_157 = V_44 -> V_112 ;
V_158 = V_44 -> V_111 ;
} while ( F_94 ( & V_44 -> V_110 , V_156 ) );
do {
V_156 = F_93 ( & V_44 -> V_55 ) ;
V_159 = V_44 -> V_57 ;
V_160 = V_44 -> V_56 ;
} while ( F_94 ( & V_44 -> V_55 , V_156 ) );
V_154 -> V_57 += V_159 ;
V_154 -> V_112 += V_157 ;
V_154 -> V_56 += V_160 ;
V_154 -> V_111 += V_158 ;
}
V_154 -> V_121 = V_22 -> V_44 . V_121 ;
V_154 -> V_120 = V_22 -> V_44 . V_120 ;
V_154 -> V_54 = V_22 -> V_44 . V_54 ;
V_154 -> V_45 = V_22 -> V_44 . V_45 ;
V_154 -> V_81 = V_22 -> V_44 . V_81 ;
return V_154 ;
}
static void F_95 ( struct V_49 * V_22 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_98 ; V_27 ++ )
F_96 ( & V_19 -> V_11 [ V_27 ] . V_93 ) ;
}
static void F_97 ( struct V_18 * V_19 )
{
F_98 () ;
if ( ! F_81 ( V_19 , V_161 ,
V_162 , NULL , NULL ) )
F_74 ( & V_19 -> V_22 -> V_22 , L_14 ) ;
F_99 () ;
}
static int F_100 ( struct V_18 * V_19 , T_6 V_163 )
{
struct V_125 V_86 ;
struct V_164 V_165 ;
struct V_49 * V_22 = V_19 -> V_22 ;
if ( ! V_19 -> V_166 || ! F_83 ( V_19 -> V_20 , V_167 ) )
return 0 ;
V_165 . V_168 = V_163 ;
F_43 ( & V_86 , & V_165 , sizeof( V_165 ) ) ;
if ( ! F_81 ( V_19 , V_169 ,
V_170 , & V_86 , NULL ) ) {
F_74 ( & V_22 -> V_22 , L_15 ,
V_163 ) ;
return - V_46 ;
} else {
V_19 -> V_98 = V_163 ;
F_56 ( & V_19 -> V_96 , 0 ) ;
}
return 0 ;
}
static int F_101 ( struct V_49 * V_22 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
int V_27 ;
F_102 ( & V_19 -> V_96 ) ;
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ )
F_55 ( & V_19 -> V_11 [ V_27 ] . V_93 ) ;
return 0 ;
}
static void F_103 ( struct V_49 * V_22 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
struct V_125 V_86 [ 2 ] ;
T_3 V_171 , V_172 ;
struct V_173 * V_174 ;
struct V_175 * V_176 ;
int V_177 ;
int V_178 ;
void * V_48 ;
int V_27 ;
if ( ! F_83 ( V_19 -> V_20 , V_179 ) )
return;
V_171 = ( ( V_22 -> V_58 & V_180 ) != 0 ) ;
V_172 = ( ( V_22 -> V_58 & V_181 ) != 0 ) ;
F_43 ( V_86 , & V_171 , sizeof( V_171 ) ) ;
if ( ! F_81 ( V_19 , V_182 ,
V_183 ,
V_86 , NULL ) )
F_74 ( & V_22 -> V_22 , L_16 ,
V_171 ? L_17 : L_18 ) ;
F_43 ( V_86 , & V_172 , sizeof( V_172 ) ) ;
if ( ! F_81 ( V_19 , V_182 ,
V_184 ,
V_86 , NULL ) )
F_74 ( & V_22 -> V_22 , L_19 ,
V_172 ? L_17 : L_18 ) ;
V_177 = F_104 ( V_22 ) ;
V_178 = F_105 ( V_22 ) ;
V_48 = F_106 ( ( ( V_177 + V_178 ) * V_185 ) +
( 2 * sizeof( V_174 -> V_186 ) ) , V_106 ) ;
V_174 = V_48 ;
if ( ! V_48 )
return;
F_107 ( V_86 , 2 ) ;
V_174 -> V_186 = V_177 ;
V_27 = 0 ;
F_108 (ha, dev)
memcpy ( & V_174 -> V_187 [ V_27 ++ ] [ 0 ] , V_176 -> V_142 , V_185 ) ;
F_38 ( & V_86 [ 0 ] , V_174 ,
sizeof( V_174 -> V_186 ) + ( V_177 * V_185 ) ) ;
V_174 = ( void * ) & V_174 -> V_187 [ V_177 ] [ 0 ] ;
V_174 -> V_186 = V_178 ;
V_27 = 0 ;
F_109 (ha, dev)
memcpy ( & V_174 -> V_187 [ V_27 ++ ] [ 0 ] , V_176 -> V_142 , V_185 ) ;
F_38 ( & V_86 [ 1 ] , V_174 ,
sizeof( V_174 -> V_186 ) + ( V_178 * V_185 ) ) ;
if ( ! F_81 ( V_19 , V_146 ,
V_188 ,
V_86 , NULL ) )
F_74 ( & V_22 -> V_22 , L_20 ) ;
F_110 ( V_48 ) ;
}
static int F_111 ( struct V_49 * V_22 ,
T_7 V_189 , T_6 V_190 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
struct V_125 V_86 ;
F_43 ( & V_86 , & V_190 , sizeof( V_190 ) ) ;
if ( ! F_81 ( V_19 , V_191 ,
V_192 , & V_86 , NULL ) )
F_74 ( & V_22 -> V_22 , L_21 , V_190 ) ;
return 0 ;
}
static int F_112 ( struct V_49 * V_22 ,
T_7 V_189 , T_6 V_190 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
struct V_125 V_86 ;
F_43 ( & V_86 , & V_190 , sizeof( V_190 ) ) ;
if ( ! F_81 ( V_19 , V_191 ,
V_193 , & V_86 , NULL ) )
F_74 ( & V_22 -> V_22 , L_22 , V_190 ) ;
return 0 ;
}
static void F_113 ( struct V_18 * V_19 , long V_194 )
{
int V_27 ;
int V_155 ;
if ( V_19 -> V_195 ) {
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
F_114 ( V_19 -> V_11 [ V_27 ] . V_2 , - 1 ) ;
F_114 ( V_19 -> V_109 [ V_27 ] . V_2 , - 1 ) ;
}
V_19 -> V_195 = false ;
}
V_27 = 0 ;
F_115 (cpu) {
if ( V_155 == V_194 ) {
* F_92 ( V_19 -> V_196 , V_155 ) = - 1 ;
} else {
* F_92 ( V_19 -> V_196 , V_155 ) =
++ V_27 % V_19 -> V_98 ;
}
}
}
static void F_116 ( struct V_18 * V_19 )
{
int V_27 ;
int V_155 ;
if ( V_19 -> V_98 == 1 ||
V_19 -> V_107 != F_117 () ) {
F_113 ( V_19 , - 1 ) ;
return;
}
V_27 = 0 ;
F_115 (cpu) {
F_114 ( V_19 -> V_11 [ V_27 ] . V_2 , V_155 ) ;
F_114 ( V_19 -> V_109 [ V_27 ] . V_2 , V_155 ) ;
* F_92 ( V_19 -> V_196 , V_155 ) = V_27 ;
V_27 ++ ;
}
V_19 -> V_195 = true ;
}
static int F_118 ( struct V_197 * V_198 ,
unsigned long V_199 , void * V_194 )
{
struct V_18 * V_19 = F_54 ( V_198 , struct V_18 , V_200 ) ;
switch( V_199 & ~ V_201 ) {
case V_202 :
case V_203 :
case V_204 :
F_116 ( V_19 ) ;
break;
case V_205 :
F_113 ( V_19 , ( long ) V_194 ) ;
break;
default:
break;
}
return V_206 ;
}
static void F_119 ( struct V_49 * V_22 ,
struct V_207 * V_208 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
V_208 -> V_209 = F_120 ( V_19 -> V_11 [ 0 ] . V_2 ) ;
V_208 -> V_210 = F_120 ( V_19 -> V_109 [ 0 ] . V_2 ) ;
V_208 -> V_211 = V_208 -> V_209 ;
V_208 -> V_212 = V_208 -> V_210 ;
}
static void F_121 ( struct V_49 * V_22 ,
struct V_213 * V_214 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
struct V_139 * V_20 = V_19 -> V_20 ;
F_122 ( V_214 -> V_215 , V_216 , sizeof( V_214 -> V_215 ) ) ;
F_122 ( V_214 -> V_217 , V_218 , sizeof( V_214 -> V_217 ) ) ;
F_122 ( V_214 -> V_219 , F_123 ( V_20 ) , sizeof( V_214 -> V_219 ) ) ;
}
static int F_124 ( struct V_49 * V_22 ,
struct V_220 * V_221 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
T_6 V_163 = V_221 -> V_222 ;
int V_83 ;
if ( V_221 -> V_223 || V_221 -> V_224 || V_221 -> V_225 )
return - V_46 ;
if ( V_163 > V_19 -> V_107 )
return - V_46 ;
F_125 () ;
V_83 = F_100 ( V_19 , V_163 ) ;
if ( ! V_83 ) {
F_126 ( V_22 , V_163 ) ;
F_127 ( V_22 , V_163 ) ;
F_116 ( V_19 ) ;
}
F_128 () ;
return V_83 ;
}
static void F_129 ( struct V_49 * V_22 ,
struct V_220 * V_221 )
{
struct V_18 * V_19 = F_62 ( V_22 ) ;
V_221 -> V_222 = V_19 -> V_98 ;
V_221 -> V_226 = V_19 -> V_107 ;
V_221 -> V_227 = 0 ;
V_221 -> V_223 = 0 ;
V_221 -> V_224 = 0 ;
V_221 -> V_225 = 0 ;
}
static int F_130 ( struct V_49 * V_22 , int V_228 )
{
if ( V_228 < V_229 || V_228 > V_230 )
return - V_46 ;
V_22 -> V_231 = V_228 ;
return 0 ;
}
static T_6 F_131 ( struct V_49 * V_22 , struct V_7 * V_8 )
{
int V_4 ;
struct V_18 * V_19 = F_62 ( V_22 ) ;
if ( F_132 ( V_8 ) ) {
V_4 = F_133 ( V_8 ) ;
} else {
V_4 = * F_134 ( V_19 -> V_196 ) ;
if ( V_4 == - 1 )
V_4 = 0 ;
}
while ( F_18 ( V_4 >= V_22 -> V_232 ) )
V_4 -= V_22 -> V_232 ;
return V_4 ;
}
static void F_135 ( struct V_94 * V_95 )
{
struct V_18 * V_19 =
F_54 ( V_95 , struct V_18 , V_233 ) ;
T_6 V_234 ;
F_136 ( & V_19 -> V_235 ) ;
if ( ! V_19 -> V_236 )
goto V_237;
if ( F_137 ( V_19 -> V_20 , V_238 ,
F_89 ( struct V_151 , V_132 ) ,
& V_234 ) < 0 )
goto V_237;
if ( V_234 & V_239 ) {
F_138 ( V_19 -> V_22 ) ;
F_97 ( V_19 ) ;
}
V_234 &= V_240 ;
if ( V_19 -> V_132 == V_234 )
goto V_237;
V_19 -> V_132 = V_234 ;
if ( V_19 -> V_132 & V_240 ) {
F_139 ( V_19 -> V_22 ) ;
F_140 ( V_19 -> V_22 ) ;
} else {
F_141 ( V_19 -> V_22 ) ;
F_142 ( V_19 -> V_22 ) ;
}
V_237:
F_143 ( & V_19 -> V_235 ) ;
}
static void F_144 ( struct V_139 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_145 ( & V_19 -> V_233 ) ;
}
static void F_146 ( struct V_18 * V_19 )
{
F_110 ( V_19 -> V_11 ) ;
F_110 ( V_19 -> V_109 ) ;
}
static void F_147 ( struct V_18 * V_19 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
while ( V_19 -> V_11 [ V_27 ] . V_15 )
F_148 ( F_6 ( & V_19 -> V_11 [ V_27 ] , V_99 ) , 0 ) ;
}
}
static void F_149 ( struct V_18 * V_19 )
{
void * V_48 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
struct V_1 * V_2 = V_19 -> V_109 [ V_27 ] . V_2 ;
while ( ( V_48 = F_150 ( V_2 ) ) != NULL )
F_22 ( V_48 ) ;
}
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
struct V_1 * V_2 = V_19 -> V_11 [ V_27 ] . V_2 ;
while ( ( V_48 = F_150 ( V_2 ) ) != NULL ) {
if ( V_19 -> V_37 || V_19 -> V_53 )
F_5 ( & V_19 -> V_11 [ V_27 ] , V_48 ) ;
else
F_22 ( V_48 ) ;
-- V_19 -> V_11 [ V_27 ] . V_47 ;
}
F_82 ( V_19 -> V_11 [ V_27 ] . V_47 != 0 ) ;
}
}
static void F_151 ( struct V_18 * V_19 )
{
struct V_139 * V_20 = V_19 -> V_20 ;
F_113 ( V_19 , - 1 ) ;
V_20 -> V_149 -> V_241 ( V_20 ) ;
F_146 ( V_19 ) ;
}
static int F_152 ( struct V_18 * V_19 )
{
T_8 * * V_242 ;
struct V_1 * * V_243 ;
int V_140 = - V_85 ;
int V_27 , V_244 ;
const char * * V_245 ;
V_244 = V_19 -> V_107 * 2 +
F_83 ( V_19 -> V_20 , V_136 ) ;
V_243 = F_106 ( V_244 * sizeof( * V_243 ) , V_99 ) ;
if ( ! V_243 )
goto V_246;
V_242 = F_153 ( V_244 * sizeof( * V_242 ) , V_99 ) ;
if ( ! V_242 )
goto V_247;
V_245 = F_153 ( V_244 * sizeof( * V_245 ) , V_99 ) ;
if ( ! V_245 )
goto V_248;
if ( V_19 -> V_166 ) {
V_242 [ V_244 - 1 ] = NULL ;
V_245 [ V_244 - 1 ] = L_23 ;
}
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
V_242 [ F_4 ( V_27 ) ] = F_46 ;
V_242 [ F_2 ( V_27 ) ] = F_8 ;
sprintf ( V_19 -> V_11 [ V_27 ] . V_41 , L_24 , V_27 ) ;
sprintf ( V_19 -> V_109 [ V_27 ] . V_41 , L_25 , V_27 ) ;
V_245 [ F_4 ( V_27 ) ] = V_19 -> V_11 [ V_27 ] . V_41 ;
V_245 [ F_2 ( V_27 ) ] = V_19 -> V_109 [ V_27 ] . V_41 ;
}
V_140 = V_19 -> V_20 -> V_149 -> V_249 ( V_19 -> V_20 , V_244 , V_243 , V_242 ,
V_245 ) ;
if ( V_140 )
goto V_250;
if ( V_19 -> V_166 ) {
V_19 -> V_137 = V_243 [ V_244 - 1 ] ;
if ( F_83 ( V_19 -> V_20 , V_251 ) )
V_19 -> V_22 -> V_252 |= V_253 ;
}
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
V_19 -> V_11 [ V_27 ] . V_2 = V_243 [ F_4 ( V_27 ) ] ;
V_19 -> V_109 [ V_27 ] . V_2 = V_243 [ F_2 ( V_27 ) ] ;
}
F_110 ( V_245 ) ;
F_110 ( V_242 ) ;
F_110 ( V_243 ) ;
return 0 ;
V_250:
F_110 ( V_245 ) ;
V_248:
F_110 ( V_242 ) ;
V_247:
F_110 ( V_243 ) ;
V_246:
return V_140 ;
}
static int F_154 ( struct V_18 * V_19 )
{
int V_27 ;
V_19 -> V_109 = F_106 ( sizeof( * V_19 -> V_109 ) * V_19 -> V_107 , V_99 ) ;
if ( ! V_19 -> V_109 )
goto V_254;
V_19 -> V_11 = F_106 ( sizeof( * V_19 -> V_11 ) * V_19 -> V_107 , V_99 ) ;
if ( ! V_19 -> V_11 )
goto V_255;
F_155 ( & V_19 -> V_96 , F_53 ) ;
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
V_19 -> V_11 [ V_27 ] . V_15 = NULL ;
F_156 ( V_19 -> V_22 , & V_19 -> V_11 [ V_27 ] . V_93 , F_57 ,
V_256 ) ;
F_107 ( V_19 -> V_11 [ V_27 ] . V_86 , F_84 ( V_19 -> V_11 [ V_27 ] . V_86 ) ) ;
F_107 ( V_19 -> V_109 [ V_27 ] . V_86 , F_84 ( V_19 -> V_109 [ V_27 ] . V_86 ) ) ;
}
return 0 ;
V_255:
F_110 ( V_19 -> V_109 ) ;
V_254:
return - V_85 ;
}
static int F_157 ( struct V_18 * V_19 )
{
int V_140 ;
V_140 = F_154 ( V_19 ) ;
if ( V_140 )
goto V_83;
V_140 = F_152 ( V_19 ) ;
if ( V_140 )
goto V_257;
F_125 () ;
F_116 ( V_19 ) ;
F_128 () ;
return 0 ;
V_257:
F_146 ( V_19 ) ;
V_83:
return V_140 ;
}
static int F_158 ( struct V_139 * V_20 )
{
int V_27 , V_83 ;
struct V_49 * V_22 ;
struct V_18 * V_19 ;
T_6 V_107 ;
V_83 = F_137 ( V_20 , V_167 ,
F_89 ( struct V_151 ,
V_258 ) , & V_107 ) ;
if ( V_83 || V_107 < V_259 ||
V_107 > V_260 ||
! F_83 ( V_20 , V_136 ) )
V_107 = 1 ;
V_22 = F_159 ( sizeof( struct V_18 ) , V_107 ) ;
if ( ! V_22 )
return - V_85 ;
V_22 -> V_261 |= V_262 | V_263 ;
V_22 -> V_264 = & V_265 ;
V_22 -> V_252 = V_266 ;
F_160 ( V_22 , & V_267 ) ;
F_161 ( V_22 , & V_20 -> V_22 ) ;
if ( F_83 ( V_20 , V_268 ) ) {
V_22 -> V_269 |= V_270 | V_271 | V_272 ;
if ( V_273 )
V_22 -> V_252 |= V_270 | V_271 | V_272 ;
if ( F_83 ( V_20 , V_274 ) ) {
V_22 -> V_269 |= V_275 | V_276
| V_277 | V_278 ;
}
if ( F_83 ( V_20 , V_279 ) )
V_22 -> V_269 |= V_275 ;
if ( F_83 ( V_20 , V_280 ) )
V_22 -> V_269 |= V_278 ;
if ( F_83 ( V_20 , V_281 ) )
V_22 -> V_269 |= V_277 ;
if ( F_83 ( V_20 , V_282 ) )
V_22 -> V_269 |= V_276 ;
if ( V_283 )
V_22 -> V_252 |= V_22 -> V_269 & ( V_284 | V_276 ) ;
}
V_22 -> V_285 = V_22 -> V_252 ;
if ( F_162 ( V_20 , V_148 ,
F_89 ( struct V_151 , V_152 ) ,
V_22 -> V_286 , V_22 -> V_145 ) < 0 )
F_163 ( V_22 ) ;
V_19 = F_62 ( V_22 ) ;
V_19 -> V_22 = V_22 ;
V_19 -> V_20 = V_20 ;
V_20 -> V_21 = V_19 ;
V_19 -> V_44 = F_164 ( struct V_50 ) ;
V_83 = - V_85 ;
if ( V_19 -> V_44 == NULL )
goto free;
V_19 -> V_196 = F_164 ( int ) ;
if ( V_19 -> V_196 == NULL )
goto V_287;
F_165 ( & V_19 -> V_235 ) ;
V_19 -> V_236 = true ;
F_166 ( & V_19 -> V_233 , F_135 ) ;
if ( F_83 ( V_20 , V_288 ) ||
F_83 ( V_20 , V_289 ) ||
F_83 ( V_20 , V_290 ) )
V_19 -> V_53 = true ;
if ( F_83 ( V_20 , V_291 ) )
V_19 -> V_37 = true ;
if ( F_83 ( V_20 , V_136 ) )
V_19 -> V_166 = true ;
V_19 -> V_98 = 1 ;
V_19 -> V_107 = V_107 ;
V_83 = F_157 ( V_19 ) ;
if ( V_83 )
goto V_292;
F_126 ( V_22 , 1 ) ;
F_127 ( V_22 , 1 ) ;
V_83 = F_167 ( V_22 ) ;
if ( V_83 ) {
F_24 ( L_26 ) ;
goto V_293;
}
for ( V_27 = 0 ; V_27 < V_19 -> V_98 ; V_27 ++ ) {
F_44 ( & V_19 -> V_11 [ V_27 ] , V_99 ) ;
if ( V_19 -> V_11 [ V_27 ] . V_47 == 0 ) {
F_149 ( V_19 ) ;
V_83 = - V_85 ;
goto V_294;
}
}
V_19 -> V_200 . V_295 = & F_118 ;
V_83 = F_168 ( & V_19 -> V_200 ) ;
if ( V_83 ) {
F_24 ( L_27 ) ;
goto V_294;
}
if ( F_83 ( V_19 -> V_20 , V_238 ) ) {
F_141 ( V_22 ) ;
F_145 ( & V_19 -> V_233 ) ;
} else {
V_19 -> V_132 = V_240 ;
F_139 ( V_22 ) ;
}
F_24 ( L_28 ,
V_22 -> V_41 , V_107 ) ;
return 0 ;
V_294:
F_147 ( V_19 ) ;
F_169 ( V_22 ) ;
V_293:
F_102 ( & V_19 -> V_96 ) ;
F_151 ( V_19 ) ;
V_292:
F_170 ( V_19 -> V_196 ) ;
V_287:
F_170 ( V_19 -> V_44 ) ;
free:
F_171 ( V_22 ) ;
return V_83 ;
}
static void F_172 ( struct V_18 * V_19 )
{
V_19 -> V_20 -> V_149 -> V_296 ( V_19 -> V_20 ) ;
F_149 ( V_19 ) ;
F_147 ( V_19 ) ;
F_151 ( V_19 ) ;
}
static void F_173 ( struct V_139 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
F_174 ( & V_19 -> V_200 ) ;
F_136 ( & V_19 -> V_235 ) ;
V_19 -> V_236 = false ;
F_143 ( & V_19 -> V_235 ) ;
F_169 ( V_19 -> V_22 ) ;
F_172 ( V_19 ) ;
F_175 ( & V_19 -> V_233 ) ;
F_170 ( V_19 -> V_196 ) ;
F_170 ( V_19 -> V_44 ) ;
F_171 ( V_19 -> V_22 ) ;
}
static int F_176 ( struct V_139 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_27 ;
F_136 ( & V_19 -> V_235 ) ;
V_19 -> V_236 = false ;
F_143 ( & V_19 -> V_235 ) ;
F_177 ( V_19 -> V_22 ) ;
F_102 ( & V_19 -> V_96 ) ;
if ( F_178 ( V_19 -> V_22 ) )
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ ) {
F_55 ( & V_19 -> V_11 [ V_27 ] . V_93 ) ;
F_179 ( & V_19 -> V_11 [ V_27 ] . V_93 ) ;
}
F_172 ( V_19 ) ;
F_175 ( & V_19 -> V_233 ) ;
return 0 ;
}
static int F_180 ( struct V_139 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
int V_83 , V_27 ;
V_83 = F_157 ( V_19 ) ;
if ( V_83 )
return V_83 ;
if ( F_178 ( V_19 -> V_22 ) )
for ( V_27 = 0 ; V_27 < V_19 -> V_107 ; V_27 ++ )
F_49 ( & V_19 -> V_11 [ V_27 ] ) ;
F_181 ( V_19 -> V_22 ) ;
for ( V_27 = 0 ; V_27 < V_19 -> V_98 ; V_27 ++ )
if ( ! F_44 ( & V_19 -> V_11 [ V_27 ] , V_99 ) )
F_56 ( & V_19 -> V_96 , 0 ) ;
F_136 ( & V_19 -> V_235 ) ;
V_19 -> V_236 = true ;
F_143 ( & V_19 -> V_235 ) ;
F_100 ( V_19 , V_19 -> V_98 ) ;
return 0 ;
}
