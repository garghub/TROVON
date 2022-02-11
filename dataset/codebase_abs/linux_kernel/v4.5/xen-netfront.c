static void F_1 ( union V_1 * V_2 , unsigned short V_3 )
{
V_2 -> V_4 = V_3 ;
}
static int F_2 ( const union V_1 * V_2 )
{
F_3 ( sizeof( V_2 -> V_5 ) != sizeof( V_2 -> V_4 ) ) ;
return ( unsigned long ) V_2 -> V_5 < V_6 ;
}
static void F_4 ( unsigned * V_7 , union V_1 * V_2 ,
unsigned short V_3 )
{
F_1 ( & V_2 [ V_3 ] , * V_7 ) ;
* V_7 = V_3 ;
}
static unsigned short F_5 ( unsigned * V_7 ,
union V_1 * V_2 )
{
unsigned int V_3 = * V_7 ;
* V_7 = V_2 [ V_3 ] . V_4 ;
return V_3 ;
}
static int F_6 ( T_1 V_8 )
{
return V_8 & ( V_9 - 1 ) ;
}
static struct V_10 * F_7 ( struct V_11 * V_12 ,
T_1 V_13 )
{
int V_14 = F_6 ( V_13 ) ;
struct V_10 * V_5 = V_12 -> V_15 [ V_14 ] ;
V_12 -> V_15 [ V_14 ] = NULL ;
return V_5 ;
}
static T_2 F_8 ( struct V_11 * V_12 ,
T_1 V_13 )
{
int V_14 = F_6 ( V_13 ) ;
T_2 V_16 = V_12 -> V_17 [ V_14 ] ;
V_12 -> V_17 [ V_14 ] = V_18 ;
return V_16 ;
}
static bool F_9 ( struct V_19 * V_20 )
{
return V_20 -> V_21 & V_22 ;
}
static void F_10 ( unsigned long V_23 )
{
struct V_11 * V_12 = (struct V_11 * ) V_23 ;
F_11 ( & V_12 -> V_24 ) ;
}
static int F_12 ( struct V_11 * V_12 )
{
return ( V_12 -> V_25 . V_26 - V_12 -> V_25 . V_27 ) <
( V_28 - V_29 - 2 ) ;
}
static void F_13 ( struct V_11 * V_12 )
{
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
struct V_32 * V_33 = F_14 ( V_20 , V_12 -> V_3 ) ;
if ( F_15 ( F_16 ( V_33 ) ) &&
F_12 ( V_12 ) &&
F_17 ( F_18 ( V_20 ) ) )
F_19 ( F_14 ( V_20 , V_12 -> V_3 ) ) ;
}
static struct V_10 * F_20 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
struct V_34 * V_34 ;
V_5 = F_21 ( V_12 -> V_30 -> V_31 ,
V_35 + V_36 ,
V_37 | V_38 ) ;
if ( F_15 ( ! V_5 ) )
return NULL ;
V_34 = F_22 ( V_37 | V_38 ) ;
if ( ! V_34 ) {
F_23 ( V_5 ) ;
return NULL ;
}
F_24 ( V_5 , 0 , V_34 , 0 , 0 , V_39 ) ;
F_25 ( V_5 , V_36 ) ;
V_5 -> V_20 = V_12 -> V_30 -> V_31 ;
return V_5 ;
}
static void F_26 ( struct V_11 * V_12 )
{
T_1 V_40 = V_12 -> V_41 . V_26 ;
int V_42 ;
if ( F_15 ( ! F_27 ( V_12 -> V_30 -> V_31 ) ) )
return;
for ( V_40 = V_12 -> V_41 . V_26 ;
V_40 - V_12 -> V_41 . V_27 < V_9 ;
V_40 ++ ) {
struct V_10 * V_5 ;
unsigned short V_3 ;
T_2 V_16 ;
struct V_34 * V_34 ;
struct V_43 * V_44 ;
V_5 = F_20 ( V_12 ) ;
if ( ! V_5 )
break;
V_3 = F_6 ( V_40 ) ;
F_28 ( V_12 -> V_15 [ V_3 ] ) ;
V_12 -> V_15 [ V_3 ] = V_5 ;
V_16 = F_29 ( & V_12 -> V_45 ) ;
F_28 ( ( signed short ) V_16 < 0 ) ;
V_12 -> V_17 [ V_3 ] = V_16 ;
V_34 = F_30 ( & F_31 ( V_5 ) -> V_46 [ 0 ] ) ;
V_44 = F_32 ( & V_12 -> V_41 , V_40 ) ;
F_33 ( V_16 ,
V_12 -> V_30 -> V_47 -> V_48 ,
V_34 ,
0 ) ;
V_44 -> V_3 = V_3 ;
V_44 -> V_49 = V_16 ;
}
V_12 -> V_41 . V_26 = V_40 ;
if ( V_40 - V_12 -> V_41 . V_27 < V_50 ) {
F_34 ( & V_12 -> V_51 , V_52 + ( V_53 / 10 ) ) ;
return;
}
F_35 () ;
F_36 ( & V_12 -> V_41 , V_42 ) ;
if ( V_42 )
F_37 ( V_12 -> V_54 ) ;
}
static int F_38 ( struct V_19 * V_20 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
unsigned int V_57 = V_20 -> V_58 ;
unsigned int V_14 = 0 ;
struct V_11 * V_12 = NULL ;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_56 -> V_59 [ V_14 ] ;
F_40 ( & V_12 -> V_24 ) ;
F_41 ( & V_12 -> V_60 ) ;
if ( F_27 ( V_20 ) ) {
F_26 ( V_12 ) ;
V_12 -> V_41 . V_61 -> V_62 = V_12 -> V_41 . V_27 + 1 ;
if ( F_42 ( & V_12 -> V_41 ) )
F_11 ( & V_12 -> V_24 ) ;
}
F_43 ( & V_12 -> V_60 ) ;
}
F_44 ( V_20 ) ;
return 0 ;
}
static void F_45 ( struct V_11 * V_12 )
{
T_1 V_63 , V_64 ;
unsigned short V_3 ;
struct V_10 * V_5 ;
bool V_65 ;
F_28 ( ! F_27 ( V_12 -> V_30 -> V_31 ) ) ;
do {
V_64 = V_12 -> V_25 . V_61 -> V_66 ;
F_46 () ;
for ( V_63 = V_12 -> V_25 . V_27 ; V_63 != V_64 ; V_63 ++ ) {
struct V_67 * V_68 ;
V_68 = F_47 ( & V_12 -> V_25 , V_63 ) ;
if ( V_68 -> V_69 == V_70 )
continue;
V_3 = V_68 -> V_3 ;
V_5 = V_12 -> V_71 [ V_3 ] . V_5 ;
if ( F_15 ( F_48 (
V_12 -> V_72 [ V_3 ] ) != 0 ) ) {
F_49 ( L_1 ,
V_73 ) ;
F_50 () ;
}
F_51 (
V_12 -> V_72 [ V_3 ] , V_74 ) ;
F_52 (
& V_12 -> V_75 , V_12 -> V_72 [ V_3 ] ) ;
V_12 -> V_72 [ V_3 ] = V_18 ;
V_12 -> V_76 [ V_3 ] = NULL ;
F_4 ( & V_12 -> V_77 , V_12 -> V_71 , V_3 ) ;
F_53 ( V_5 ) ;
}
V_12 -> V_25 . V_27 = V_64 ;
F_54 ( & V_12 -> V_25 , V_65 ) ;
} while ( V_65 );
F_13 ( V_12 ) ;
}
static void F_55 ( unsigned long V_78 , unsigned int V_79 ,
unsigned int V_80 , void * V_23 )
{
struct V_81 * V_30 = V_23 ;
unsigned int V_3 ;
struct V_82 * V_25 ;
T_2 V_16 ;
struct V_34 * V_34 = V_30 -> V_34 ;
struct V_11 * V_12 = V_30 -> V_12 ;
struct V_10 * V_5 = V_30 -> V_5 ;
V_3 = F_5 ( & V_12 -> V_77 , V_12 -> V_71 ) ;
V_25 = F_32 ( & V_12 -> V_25 , V_12 -> V_25 . V_26 ++ ) ;
V_16 = F_29 ( & V_12 -> V_75 ) ;
F_28 ( ( signed short ) V_16 < 0 ) ;
F_56 ( V_16 , V_12 -> V_30 -> V_47 -> V_48 ,
V_78 , V_74 ) ;
V_12 -> V_71 [ V_3 ] . V_5 = V_5 ;
V_12 -> V_76 [ V_3 ] = V_34 ;
V_12 -> V_72 [ V_3 ] = V_16 ;
V_25 -> V_3 = V_3 ;
V_25 -> V_49 = V_16 ;
V_25 -> V_79 = V_79 ;
V_25 -> V_83 = V_80 ;
V_25 -> V_84 = 0 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_83 += V_25 -> V_83 ;
}
static struct V_82 * F_57 (
struct V_11 * V_12 , struct V_10 * V_5 ,
struct V_34 * V_34 , unsigned int V_79 , unsigned int V_80 )
{
struct V_81 V_30 = {
. V_12 = V_12 ,
. V_5 = V_5 ,
. V_34 = V_34 ,
. V_83 = 0 ,
} ;
F_58 ( V_34 , V_79 , V_80 , F_55 , & V_30 ) ;
return V_30 . V_25 ;
}
static void F_59 ( unsigned long V_78 , unsigned int V_79 ,
unsigned int V_80 , void * V_23 )
{
struct V_81 * V_30 = V_23 ;
V_30 -> V_25 -> V_84 |= V_85 ;
F_60 ( V_30 -> V_5 ) ;
F_55 ( V_78 , V_79 , V_80 , V_23 ) ;
}
static struct V_82 * F_61 (
struct V_11 * V_12 , struct V_82 * V_25 ,
struct V_10 * V_5 , struct V_34 * V_34 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_81 V_30 = {
. V_12 = V_12 ,
. V_5 = V_5 ,
. V_25 = V_25 ,
} ;
V_34 += V_79 >> V_86 ;
V_79 &= ~ V_87 ;
while ( V_80 ) {
V_30 . V_34 = V_34 ;
V_30 . V_83 = 0 ;
F_62 ( V_34 , V_79 , V_80 ,
F_59 ,
& V_30 ) ;
V_34 ++ ;
V_79 = 0 ;
V_80 -= V_30 . V_83 ;
}
return V_30 . V_25 ;
}
static int F_63 ( struct V_10 * V_5 )
{
int V_14 , V_46 = F_31 ( V_5 ) -> V_88 ;
int V_89 ;
V_89 = F_64 ( F_65 ( V_5 -> V_23 ) ,
F_66 ( V_5 ) ) ;
for ( V_14 = 0 ; V_14 < V_46 ; V_14 ++ ) {
T_3 * V_90 = F_31 ( V_5 ) -> V_46 + V_14 ;
unsigned long V_83 = F_67 ( V_90 ) ;
unsigned long V_79 = V_90 -> V_91 ;
V_79 &= ~ V_87 ;
V_89 += F_64 ( V_79 , V_83 ) ;
}
return V_89 ;
}
static T_4 F_68 ( struct V_19 * V_20 , struct V_10 * V_5 ,
void * V_92 , T_5 V_93 )
{
unsigned int V_57 = V_20 -> V_58 ;
T_6 V_94 ;
T_4 V_95 ;
if ( V_57 == 1 ) {
V_95 = 0 ;
} else {
V_94 = F_69 ( V_5 ) ;
V_95 = V_94 % V_57 ;
}
return V_95 ;
}
static int F_70 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
struct V_96 * V_97 = F_71 ( V_56 -> V_97 ) ;
struct V_82 * V_25 , * V_98 ;
unsigned int V_14 ;
int V_42 ;
int V_89 ;
struct V_34 * V_34 ;
unsigned int V_79 ;
unsigned int V_80 ;
unsigned long V_84 ;
struct V_11 * V_12 = NULL ;
unsigned int V_57 = V_20 -> V_58 ;
T_4 V_99 ;
if ( V_57 < 1 )
goto V_100;
V_99 = F_72 ( V_5 ) ;
V_12 = & V_56 -> V_59 [ V_99 ] ;
if ( F_15 ( V_5 -> V_80 > V_101 ) ) {
F_73 (
L_2 ,
V_5 -> V_80 ) ;
goto V_100;
}
V_89 = F_63 ( V_5 ) ;
if ( F_15 ( V_89 > V_102 + 1 ) ) {
F_74 ( L_3 ,
V_89 , V_5 -> V_80 ) ;
if ( F_75 ( V_5 ) )
goto V_100;
}
V_34 = F_76 ( V_5 -> V_23 ) ;
V_79 = F_65 ( V_5 -> V_23 ) ;
V_80 = F_66 ( V_5 ) ;
F_77 ( & V_12 -> V_103 , V_84 ) ;
if ( F_15 ( ! F_27 ( V_20 ) ||
( V_89 > 1 && ! F_9 ( V_20 ) ) ||
F_78 ( V_5 , F_79 ( V_5 ) ) ) ) {
F_80 ( & V_12 -> V_103 , V_84 ) ;
goto V_100;
}
V_98 = V_25 = F_57 ( V_12 , V_5 ,
V_34 , V_79 , V_80 ) ;
V_79 += V_25 -> V_83 ;
if ( V_79 == V_39 ) {
V_34 ++ ;
V_79 = 0 ;
}
V_80 -= V_25 -> V_83 ;
if ( V_5 -> V_104 == V_105 )
V_25 -> V_84 |= V_106 | V_107 ;
else if ( V_5 -> V_104 == V_108 )
V_25 -> V_84 |= V_107 ;
if ( F_31 ( V_5 ) -> V_109 ) {
struct V_110 * V_111 ;
V_111 = (struct V_110 * )
F_32 ( & V_12 -> V_25 , V_12 -> V_25 . V_26 ++ ) ;
V_25 -> V_84 |= V_112 ;
V_111 -> V_113 . V_111 . V_83 = F_31 ( V_5 ) -> V_109 ;
V_111 -> V_113 . V_111 . type = ( F_31 ( V_5 ) -> V_114 & V_115 ) ?
V_116 :
V_117 ;
V_111 -> V_113 . V_111 . V_118 = 0 ;
V_111 -> V_113 . V_111 . V_21 = 0 ;
V_111 -> type = V_119 ;
V_111 -> V_84 = 0 ;
}
V_25 = F_61 ( V_12 , V_25 , V_5 , V_34 , V_79 , V_80 ) ;
for ( V_14 = 0 ; V_14 < F_31 ( V_5 ) -> V_88 ; V_14 ++ ) {
T_3 * V_90 = & F_31 ( V_5 ) -> V_46 [ V_14 ] ;
V_25 = F_61 ( V_12 , V_25 , V_5 ,
F_30 ( V_90 ) , V_90 -> V_91 ,
F_67 ( V_90 ) ) ;
}
V_98 -> V_83 = V_5 -> V_80 ;
F_36 ( & V_12 -> V_25 , V_42 ) ;
if ( V_42 )
F_37 ( V_12 -> V_120 ) ;
F_81 ( & V_97 -> V_121 ) ;
V_97 -> V_122 += V_5 -> V_80 ;
V_97 -> V_123 ++ ;
F_82 ( & V_97 -> V_121 ) ;
F_45 ( V_12 ) ;
if ( ! F_12 ( V_12 ) )
F_83 ( F_14 ( V_20 , V_12 -> V_3 ) ) ;
F_80 ( & V_12 -> V_103 , V_84 ) ;
return V_124 ;
V_100:
V_20 -> V_125 . V_126 ++ ;
F_84 ( V_5 ) ;
return V_124 ;
}
static int F_85 ( struct V_19 * V_20 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
unsigned int V_57 = V_20 -> V_58 ;
unsigned int V_14 ;
struct V_11 * V_12 ;
F_86 ( V_56 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_56 -> V_59 [ V_14 ] ;
F_87 ( & V_12 -> V_24 ) ;
}
return 0 ;
}
static void F_88 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_127 = F_6 ( V_12 -> V_41 . V_26 ) ;
F_28 ( V_12 -> V_15 [ V_127 ] ) ;
V_12 -> V_15 [ V_127 ] = V_5 ;
V_12 -> V_17 [ V_127 ] = V_16 ;
F_32 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_3 = V_127 ;
F_32 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_49 = V_16 ;
V_12 -> V_41 . V_26 ++ ;
}
static int F_89 ( struct V_11 * V_12 ,
struct V_110 * V_128 ,
T_1 V_129 )
{
struct V_110 * V_130 ;
struct V_131 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
int V_132 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_63 + 1 == V_129 ) ) {
if ( F_90 () )
F_91 ( V_20 , L_4 ) ;
V_132 = - V_133 ;
break;
}
V_130 = (struct V_110 * )
F_47 ( & V_12 -> V_41 , ++ V_63 ) ;
if ( F_15 ( ! V_130 -> type ||
V_130 -> type >= V_134 ) ) {
if ( F_90 () )
F_91 ( V_20 , L_5 ,
V_130 -> type ) ;
V_132 = - V_135 ;
} else {
memcpy ( & V_128 [ V_130 -> type - 1 ] , V_130 ,
sizeof( * V_130 ) ) ;
}
V_5 = F_7 ( V_12 , V_63 ) ;
V_16 = F_8 ( V_12 , V_63 ) ;
F_88 ( V_12 , V_5 , V_16 ) ;
} while ( V_130 -> V_84 & V_136 );
V_12 -> V_41 . V_27 = V_63 ;
return V_132 ;
}
static int F_92 ( struct V_11 * V_12 ,
struct V_137 * V_138 , T_1 V_129 ,
struct V_139 * V_2 )
{
struct V_140 * V_41 = & V_138 -> V_41 ;
struct V_110 * V_128 = V_138 -> V_128 ;
struct V_131 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_63 ) ;
T_2 V_16 = F_8 ( V_12 , V_63 ) ;
int V_141 = V_29 + ( V_41 -> V_69 <= V_35 ) ;
int V_89 = 1 ;
int V_132 = 0 ;
unsigned long V_142 ;
if ( V_41 -> V_84 & V_143 ) {
V_132 = F_89 ( V_12 , V_128 , V_129 ) ;
V_63 = V_12 -> V_41 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_41 -> V_69 < 0 ||
V_41 -> V_79 + V_41 -> V_69 > V_144 ) ) {
if ( F_90 () )
F_91 ( V_20 , L_6 ,
V_41 -> V_79 , V_41 -> V_69 ) ;
F_88 ( V_12 , V_5 , V_16 ) ;
V_132 = - V_135 ;
goto V_145;
}
if ( V_16 == V_18 ) {
if ( F_90 () )
F_91 ( V_20 , L_7 ,
V_41 -> V_3 ) ;
V_132 = - V_135 ;
goto V_145;
}
V_142 = F_51 ( V_16 , 0 ) ;
F_28 ( ! V_142 ) ;
F_52 ( & V_12 -> V_45 , V_16 ) ;
F_93 ( V_2 , V_5 ) ;
V_145:
if ( ! ( V_41 -> V_84 & V_146 ) )
break;
if ( V_63 + V_89 == V_129 ) {
if ( F_90 () )
F_91 ( V_20 , L_8 ) ;
V_132 = - V_147 ;
break;
}
V_41 = F_47 ( & V_12 -> V_41 , V_63 + V_89 ) ;
V_5 = F_7 ( V_12 , V_63 + V_89 ) ;
V_16 = F_8 ( V_12 , V_63 + V_89 ) ;
V_89 ++ ;
}
if ( F_15 ( V_89 > V_141 ) ) {
if ( F_90 () )
F_91 ( V_20 , L_9 ) ;
V_132 = - V_148 ;
}
if ( F_15 ( V_132 ) )
V_12 -> V_41 . V_27 = V_63 + V_89 ;
return V_132 ;
}
static int F_94 ( struct V_10 * V_5 ,
struct V_110 * V_111 )
{
if ( ! V_111 -> V_113 . V_111 . V_83 ) {
if ( F_90 () )
F_95 ( L_10 ) ;
return - V_135 ;
}
if ( V_111 -> V_113 . V_111 . type != V_117 &&
V_111 -> V_113 . V_111 . type != V_116 ) {
if ( F_90 () )
F_95 ( L_11 , V_111 -> V_113 . V_111 . type ) ;
return - V_135 ;
}
F_31 ( V_5 ) -> V_109 = V_111 -> V_113 . V_111 . V_83 ;
F_31 ( V_5 ) -> V_114 =
( V_111 -> V_113 . V_111 . type == V_117 ) ?
V_149 :
V_115 ;
F_31 ( V_5 ) -> V_114 |= V_150 ;
F_31 ( V_5 ) -> V_151 = 0 ;
return 0 ;
}
static T_1 F_96 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_139 * V_2 )
{
struct V_152 * V_153 = F_31 ( V_5 ) ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
struct V_10 * V_154 ;
while ( ( V_154 = F_97 ( V_2 ) ) ) {
struct V_140 * V_41 =
F_47 ( & V_12 -> V_41 , ++ V_63 ) ;
T_3 * V_155 = & F_31 ( V_154 ) -> V_46 [ 0 ] ;
if ( V_153 -> V_88 == V_29 ) {
unsigned int V_156 = F_98 ( V_5 ) -> V_156 ;
F_28 ( V_156 <= F_66 ( V_5 ) ) ;
F_99 ( V_5 , V_156 - F_66 ( V_5 ) ) ;
}
F_28 ( V_153 -> V_88 >= V_29 ) ;
F_24 ( V_5 , V_153 -> V_88 , F_30 ( V_155 ) ,
V_41 -> V_79 , V_41 -> V_69 , V_39 ) ;
F_31 ( V_154 ) -> V_88 = 0 ;
F_23 ( V_154 ) ;
}
return V_63 ;
}
static int F_100 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
bool V_157 = false ;
if ( V_5 -> V_104 != V_105 && F_101 ( V_5 ) ) {
struct V_55 * V_56 = F_39 ( V_20 ) ;
F_102 ( & V_56 -> V_158 ) ;
V_5 -> V_104 = V_105 ;
V_157 = true ;
}
if ( V_5 -> V_104 != V_105 )
return 0 ;
return F_103 ( V_5 , V_157 ) ;
}
static int F_104 ( struct V_11 * V_12 ,
struct V_139 * V_159 )
{
struct V_96 * V_160 = F_71 ( V_12 -> V_30 -> V_160 ) ;
int V_161 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_97 ( V_159 ) ) != NULL ) {
int V_156 = F_98 ( V_5 ) -> V_156 ;
if ( V_156 > F_66 ( V_5 ) )
F_99 ( V_5 , V_156 - F_66 ( V_5 ) ) ;
V_5 -> V_162 = F_105 ( V_5 , V_12 -> V_30 -> V_31 ) ;
F_106 ( V_5 ) ;
if ( F_100 ( V_12 -> V_30 -> V_31 , V_5 ) ) {
F_23 ( V_5 ) ;
V_161 ++ ;
V_12 -> V_30 -> V_31 -> V_125 . V_163 ++ ;
continue;
}
F_81 ( & V_160 -> V_121 ) ;
V_160 -> V_123 ++ ;
V_160 -> V_122 += V_5 -> V_80 ;
F_82 ( & V_160 -> V_121 ) ;
F_107 ( & V_12 -> V_24 , V_5 ) ;
}
return V_161 ;
}
static int F_108 ( struct V_164 * V_24 , int V_165 )
{
struct V_11 * V_12 = F_109 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
struct V_10 * V_5 ;
struct V_137 V_138 ;
struct V_140 * V_41 = & V_138 . V_41 ;
struct V_110 * V_128 = V_138 . V_128 ;
T_1 V_14 , V_129 ;
int V_166 ;
struct V_139 V_159 ;
struct V_139 V_167 ;
struct V_139 V_168 ;
int V_132 ;
F_110 ( & V_12 -> V_60 ) ;
F_111 ( & V_159 ) ;
F_111 ( & V_167 ) ;
F_111 ( & V_168 ) ;
V_129 = V_12 -> V_41 . V_61 -> V_66 ;
F_46 () ;
V_14 = V_12 -> V_41 . V_27 ;
V_166 = 0 ;
while ( ( V_14 != V_129 ) && ( V_166 < V_165 ) ) {
memcpy ( V_41 , F_47 ( & V_12 -> V_41 , V_14 ) , sizeof( * V_41 ) ) ;
memset ( V_128 , 0 , sizeof( V_138 . V_128 ) ) ;
V_132 = F_92 ( V_12 , & V_138 , V_129 , & V_168 ) ;
if ( F_15 ( V_132 ) ) {
V_132:
while ( ( V_5 = F_97 ( & V_168 ) ) )
F_93 ( & V_167 , V_5 ) ;
V_20 -> V_125 . V_163 ++ ;
V_14 = V_12 -> V_41 . V_27 ;
continue;
}
V_5 = F_97 ( & V_168 ) ;
if ( V_128 [ V_119 - 1 ] . type ) {
struct V_110 * V_111 ;
V_111 = & V_128 [ V_119 - 1 ] ;
if ( F_15 ( F_94 ( V_5 , V_111 ) ) ) {
F_112 ( & V_168 , V_5 ) ;
V_12 -> V_41 . V_27 += F_113 ( & V_168 ) ;
goto V_132;
}
}
F_98 ( V_5 ) -> V_156 = V_41 -> V_69 ;
if ( F_98 ( V_5 ) -> V_156 > V_35 )
F_98 ( V_5 ) -> V_156 = V_35 ;
F_31 ( V_5 ) -> V_46 [ 0 ] . V_91 = V_41 -> V_79 ;
F_114 ( & F_31 ( V_5 ) -> V_46 [ 0 ] , V_41 -> V_69 ) ;
V_5 -> V_169 = V_41 -> V_69 ;
V_5 -> V_80 += V_41 -> V_69 ;
V_14 = F_96 ( V_12 , V_5 , & V_168 ) ;
if ( V_41 -> V_84 & V_170 )
V_5 -> V_104 = V_105 ;
else if ( V_41 -> V_84 & V_171 )
V_5 -> V_104 = V_108 ;
F_93 ( & V_159 , V_5 ) ;
V_12 -> V_41 . V_27 = ++ V_14 ;
V_166 ++ ;
}
F_115 ( & V_167 ) ;
V_166 -= F_104 ( V_12 , & V_159 ) ;
F_26 ( V_12 ) ;
if ( V_166 < V_165 ) {
int V_65 = 0 ;
F_116 ( V_24 ) ;
F_54 ( & V_12 -> V_41 , V_65 ) ;
if ( V_65 )
F_11 ( V_24 ) ;
}
F_117 ( & V_12 -> V_60 ) ;
return V_166 ;
}
static int F_118 ( struct V_19 * V_20 , int V_172 )
{
int V_141 = F_9 ( V_20 ) ? V_101 : V_173 ;
if ( V_172 > V_141 )
return - V_135 ;
V_20 -> V_172 = V_172 ;
return 0 ;
}
static struct V_174 * F_119 ( struct V_19 * V_20 ,
struct V_174 * V_175 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
int V_176 ;
F_120 (cpu) {
struct V_96 * V_160 = F_121 ( V_56 -> V_160 , V_176 ) ;
struct V_96 * V_97 = F_121 ( V_56 -> V_97 , V_176 ) ;
T_7 V_177 , V_178 , V_179 , V_180 ;
unsigned int V_181 ;
do {
V_181 = F_122 ( & V_97 -> V_121 ) ;
V_179 = V_97 -> V_123 ;
V_180 = V_97 -> V_122 ;
} while ( F_123 ( & V_97 -> V_121 , V_181 ) );
do {
V_181 = F_122 ( & V_160 -> V_121 ) ;
V_177 = V_160 -> V_123 ;
V_178 = V_160 -> V_122 ;
} while ( F_123 ( & V_160 -> V_121 , V_181 ) );
V_175 -> V_177 += V_177 ;
V_175 -> V_179 += V_179 ;
V_175 -> V_178 += V_178 ;
V_175 -> V_180 += V_180 ;
}
V_175 -> V_163 = V_20 -> V_125 . V_163 ;
V_175 -> V_126 = V_20 -> V_125 . V_126 ;
return V_175 ;
}
static void F_124 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
if ( F_2 ( & V_12 -> V_71 [ V_14 ] ) )
continue;
V_5 = V_12 -> V_71 [ V_14 ] . V_5 ;
F_125 ( V_12 -> V_76 [ V_14 ] ) ;
F_126 ( V_12 -> V_72 [ V_14 ] ,
V_74 ,
( unsigned long ) F_127 ( V_12 -> V_76 [ V_14 ] ) ) ;
V_12 -> V_76 [ V_14 ] = NULL ;
V_12 -> V_72 [ V_14 ] = V_18 ;
F_4 ( & V_12 -> V_77 , V_12 -> V_71 , V_14 ) ;
F_53 ( V_5 ) ;
}
}
static void F_128 ( struct V_11 * V_12 )
{
int V_3 , V_16 ;
F_41 ( & V_12 -> V_60 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
struct V_10 * V_5 ;
struct V_34 * V_34 ;
V_5 = V_12 -> V_15 [ V_3 ] ;
if ( ! V_5 )
continue;
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 )
continue;
V_34 = F_30 ( & F_31 ( V_5 ) -> V_46 [ 0 ] ) ;
F_125 ( V_34 ) ;
F_126 ( V_16 , 0 ,
( unsigned long ) F_127 ( V_34 ) ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
F_23 ( V_5 ) ;
}
F_43 ( & V_12 -> V_60 ) ;
}
static T_8 F_129 ( struct V_19 * V_20 ,
T_8 V_21 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
int V_182 ;
if ( V_21 & V_22 ) {
if ( F_130 ( V_183 , V_56 -> V_47 -> V_184 , L_12 ,
L_13 , & V_182 ) < 0 )
V_182 = 0 ;
if ( ! V_182 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_185 ) {
if ( F_130 ( V_183 , V_56 -> V_47 -> V_184 ,
L_14 , L_13 , & V_182 ) < 0 )
V_182 = 0 ;
if ( ! V_182 )
V_21 &= ~ V_185 ;
}
if ( V_21 & V_186 ) {
if ( F_130 ( V_183 , V_56 -> V_47 -> V_184 ,
L_15 , L_13 , & V_182 ) < 0 )
V_182 = 0 ;
if ( ! V_182 )
V_21 &= ~ V_186 ;
}
if ( V_21 & V_187 ) {
if ( F_130 ( V_183 , V_56 -> V_47 -> V_184 ,
L_16 , L_13 , & V_182 ) < 0 )
V_182 = 0 ;
if ( ! V_182 )
V_21 &= ~ V_187 ;
}
return V_21 ;
}
static int F_131 ( struct V_19 * V_20 ,
T_8 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_172 > V_173 ) {
F_132 ( V_20 , L_17 ) ;
V_20 -> V_172 = V_173 ;
}
return 0 ;
}
static T_9 F_133 ( int V_188 , void * V_189 )
{
struct V_11 * V_12 = V_189 ;
unsigned long V_84 ;
F_77 ( & V_12 -> V_103 , V_84 ) ;
F_45 ( V_12 ) ;
F_80 ( & V_12 -> V_103 , V_84 ) ;
return V_190 ;
}
static T_9 F_134 ( int V_188 , void * V_189 )
{
struct V_11 * V_12 = V_189 ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
if ( F_17 ( F_27 ( V_20 ) &&
F_42 ( & V_12 -> V_41 ) ) )
F_11 ( & V_12 -> V_24 ) ;
return V_190 ;
}
static T_9 F_135 ( int V_188 , void * V_189 )
{
F_133 ( V_188 , V_189 ) ;
F_134 ( V_188 , V_189 ) ;
return V_190 ;
}
static void F_136 ( struct V_19 * V_20 )
{
struct V_55 * V_30 = F_39 ( V_20 ) ;
unsigned int V_57 = V_20 -> V_58 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 )
F_135 ( 0 , & V_30 -> V_59 [ V_14 ] ) ;
}
static void F_137 ( struct V_19 * V_31 )
{
struct V_55 * V_56 = F_39 ( V_31 ) ;
F_138 ( V_56 -> V_160 ) ;
F_138 ( V_56 -> V_97 ) ;
F_139 ( V_31 ) ;
}
static struct V_19 * F_140 ( struct V_191 * V_20 )
{
int V_132 ;
struct V_19 * V_31 ;
struct V_55 * V_56 ;
V_31 = F_141 ( sizeof( struct V_55 ) , V_192 ) ;
if ( ! V_31 )
return F_142 ( - V_193 ) ;
V_56 = F_39 ( V_31 ) ;
V_56 -> V_47 = V_20 ;
V_56 -> V_59 = NULL ;
V_132 = - V_193 ;
V_56 -> V_160 = F_143 ( struct V_96 ) ;
if ( V_56 -> V_160 == NULL )
goto exit;
V_56 -> V_97 = F_143 ( struct V_96 ) ;
if ( V_56 -> V_97 == NULL )
goto exit;
V_31 -> V_194 = & V_195 ;
V_31 -> V_21 = V_196 | V_197 |
V_198 ;
V_31 -> V_199 = V_22 |
V_185 |
V_186 | V_187 ;
V_31 -> V_21 |= V_31 -> V_199 ;
V_31 -> V_200 = & V_201 ;
F_144 ( V_31 , & V_20 -> V_20 ) ;
V_56 -> V_31 = V_31 ;
F_145 ( V_31 ) ;
return V_31 ;
exit:
F_137 ( V_31 ) ;
return F_142 ( V_132 ) ;
}
static int F_146 ( struct V_191 * V_20 ,
const struct V_202 * V_3 )
{
int V_132 ;
struct V_19 * V_31 ;
struct V_55 * V_30 ;
V_31 = F_140 ( V_20 ) ;
if ( F_147 ( V_31 ) ) {
V_132 = F_148 ( V_31 ) ;
F_149 ( V_20 , V_132 , L_18 ) ;
return V_132 ;
}
V_30 = F_39 ( V_31 ) ;
F_150 ( & V_20 -> V_20 , V_30 ) ;
#ifdef F_151
V_30 -> V_31 -> V_203 [ 0 ] = & V_204 ;
#endif
V_132 = F_152 ( V_30 -> V_31 ) ;
if ( V_132 ) {
F_95 ( L_19 , V_73 , V_132 ) ;
goto V_205;
}
return 0 ;
V_205:
F_137 ( V_31 ) ;
F_150 ( & V_20 -> V_20 , NULL ) ;
return V_132 ;
}
static void F_153 ( int V_16 , void * V_34 )
{
if ( V_16 != V_18 )
F_126 ( V_16 , 0 , ( unsigned long ) V_34 ) ;
}
static void F_154 ( struct V_55 * V_30 )
{
unsigned int V_14 = 0 ;
unsigned int V_57 = V_30 -> V_31 -> V_58 ;
F_145 ( V_30 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_57 && V_30 -> V_59 ; ++ V_14 ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
if ( V_12 -> V_120 && ( V_12 -> V_120 == V_12 -> V_54 ) )
F_155 ( V_12 -> V_120 , V_12 ) ;
if ( V_12 -> V_120 && ( V_12 -> V_120 != V_12 -> V_54 ) ) {
F_155 ( V_12 -> V_120 , V_12 ) ;
F_155 ( V_12 -> V_54 , V_12 ) ;
}
V_12 -> V_206 = V_12 -> V_207 = 0 ;
V_12 -> V_120 = V_12 -> V_54 = 0 ;
if ( F_18 ( V_30 -> V_31 ) )
F_156 ( & V_12 -> V_24 ) ;
F_124 ( V_12 ) ;
F_128 ( V_12 ) ;
F_157 ( V_12 -> V_75 ) ;
F_157 ( V_12 -> V_45 ) ;
F_153 ( V_12 -> V_208 , V_12 -> V_25 . V_61 ) ;
F_153 ( V_12 -> V_209 , V_12 -> V_41 . V_61 ) ;
V_12 -> V_208 = V_18 ;
V_12 -> V_209 = V_18 ;
V_12 -> V_25 . V_61 = NULL ;
V_12 -> V_41 . V_61 = NULL ;
}
}
static int F_158 ( struct V_191 * V_20 )
{
struct V_55 * V_30 = F_159 ( & V_20 -> V_20 ) ;
F_160 ( & V_20 -> V_20 , L_20 , V_20 -> V_210 ) ;
F_154 ( V_30 ) ;
return 0 ;
}
static int F_161 ( struct V_191 * V_20 , T_10 V_211 [] )
{
char * V_212 , * V_213 , * V_214 ;
int V_14 ;
V_214 = V_212 = F_162 ( V_183 , V_20 -> V_210 , L_21 , NULL ) ;
if ( F_147 ( V_214 ) )
return F_148 ( V_214 ) ;
for ( V_14 = 0 ; V_14 < V_215 ; V_14 ++ ) {
V_211 [ V_14 ] = F_163 ( V_212 , & V_213 , 16 ) ;
if ( ( V_212 == V_213 ) || ( * V_213 != ( ( V_14 == V_215 - 1 ) ? '\0' : ':' ) ) ) {
F_164 ( V_214 ) ;
return - V_147 ;
}
V_212 = V_213 + 1 ;
}
F_164 ( V_214 ) ;
return 0 ;
}
static int F_165 ( struct V_11 * V_12 )
{
int V_132 ;
V_132 = F_166 ( V_12 -> V_30 -> V_47 , & V_12 -> V_206 ) ;
if ( V_132 < 0 )
goto V_205;
V_132 = F_167 ( V_12 -> V_206 ,
F_135 ,
0 , V_12 -> V_30 -> V_31 -> V_216 , V_12 ) ;
if ( V_132 < 0 )
goto V_217;
V_12 -> V_207 = V_12 -> V_206 ;
V_12 -> V_54 = V_12 -> V_120 = V_132 ;
return 0 ;
V_217:
F_168 ( V_12 -> V_30 -> V_47 , V_12 -> V_206 ) ;
V_12 -> V_206 = 0 ;
V_205:
return V_132 ;
}
static int F_169 ( struct V_11 * V_12 )
{
int V_132 ;
V_132 = F_166 ( V_12 -> V_30 -> V_47 , & V_12 -> V_206 ) ;
if ( V_132 < 0 )
goto V_205;
V_132 = F_166 ( V_12 -> V_30 -> V_47 , & V_12 -> V_207 ) ;
if ( V_132 < 0 )
goto V_218;
snprintf ( V_12 -> V_219 , sizeof( V_12 -> V_219 ) ,
L_22 , V_12 -> V_216 ) ;
V_132 = F_167 ( V_12 -> V_206 ,
F_133 ,
0 , V_12 -> V_219 , V_12 ) ;
if ( V_132 < 0 )
goto V_220;
V_12 -> V_120 = V_132 ;
snprintf ( V_12 -> V_221 , sizeof( V_12 -> V_221 ) ,
L_23 , V_12 -> V_216 ) ;
V_132 = F_167 ( V_12 -> V_207 ,
F_134 ,
0 , V_12 -> V_221 , V_12 ) ;
if ( V_132 < 0 )
goto V_222;
V_12 -> V_54 = V_132 ;
return 0 ;
V_222:
F_155 ( V_12 -> V_120 , V_12 ) ;
V_12 -> V_120 = 0 ;
V_220:
F_168 ( V_12 -> V_30 -> V_47 , V_12 -> V_207 ) ;
V_12 -> V_207 = 0 ;
V_218:
F_168 ( V_12 -> V_30 -> V_47 , V_12 -> V_206 ) ;
V_12 -> V_206 = 0 ;
V_205:
return V_132 ;
}
static int F_170 ( struct V_191 * V_20 ,
struct V_11 * V_12 , unsigned int V_223 )
{
struct V_224 * V_225 ;
struct V_226 * V_227 ;
T_2 V_49 ;
int V_132 ;
V_12 -> V_208 = V_18 ;
V_12 -> V_209 = V_18 ;
V_12 -> V_41 . V_61 = NULL ;
V_12 -> V_25 . V_61 = NULL ;
V_225 = (struct V_224 * ) F_171 ( V_228 | V_229 ) ;
if ( ! V_225 ) {
V_132 = - V_193 ;
F_149 ( V_20 , V_132 , L_24 ) ;
goto V_205;
}
F_172 ( V_225 ) ;
F_173 ( & V_12 -> V_25 , V_225 , V_144 ) ;
V_132 = F_174 ( V_20 , V_225 , 1 , & V_49 ) ;
if ( V_132 < 0 )
goto V_230;
V_12 -> V_208 = V_49 ;
V_227 = (struct V_226 * ) F_171 ( V_228 | V_229 ) ;
if ( ! V_227 ) {
V_132 = - V_193 ;
F_149 ( V_20 , V_132 , L_25 ) ;
goto V_231;
}
F_172 ( V_227 ) ;
F_173 ( & V_12 -> V_41 , V_227 , V_144 ) ;
V_132 = F_174 ( V_20 , V_227 , 1 , & V_49 ) ;
if ( V_132 < 0 )
goto V_232;
V_12 -> V_209 = V_49 ;
if ( V_223 )
V_132 = F_169 ( V_12 ) ;
if ( ! V_223 || ( V_223 && V_132 ) )
V_132 = F_165 ( V_12 ) ;
if ( V_132 )
goto V_233;
return 0 ;
V_233:
F_51 ( V_12 -> V_209 , 0 ) ;
V_232:
F_175 ( ( unsigned long ) V_227 ) ;
V_231:
F_51 ( V_12 -> V_208 , 0 ) ;
V_230:
F_175 ( ( unsigned long ) V_225 ) ;
V_205:
return V_132 ;
}
static int F_176 ( struct V_11 * V_12 )
{
unsigned short V_14 ;
int V_132 = 0 ;
F_177 ( & V_12 -> V_103 ) ;
F_177 ( & V_12 -> V_60 ) ;
F_178 ( & V_12 -> V_51 , F_10 ,
( unsigned long ) V_12 ) ;
snprintf ( V_12 -> V_216 , sizeof( V_12 -> V_216 ) , L_26 ,
V_12 -> V_30 -> V_31 -> V_216 , V_12 -> V_3 ) ;
V_12 -> V_77 = 0 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
F_1 ( & V_12 -> V_71 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_72 [ V_14 ] = V_18 ;
V_12 -> V_76 [ V_14 ] = NULL ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_179 ( V_28 ,
& V_12 -> V_75 ) < 0 ) {
F_49 ( L_27 ) ;
V_132 = - V_193 ;
goto exit;
}
if ( F_179 ( V_9 ,
& V_12 -> V_45 ) < 0 ) {
F_49 ( L_28 ) ;
V_132 = - V_193 ;
goto V_234;
}
return 0 ;
V_234:
F_157 ( V_12 -> V_75 ) ;
exit:
return V_132 ;
}
static int F_180 ( struct V_11 * V_12 ,
struct V_235 * V_236 , int V_237 )
{
struct V_191 * V_20 = V_12 -> V_30 -> V_47 ;
int V_132 ;
const char * V_238 ;
char * V_239 ;
T_11 V_240 ;
if ( V_237 ) {
V_240 = strlen ( V_20 -> V_210 ) + 10 ;
V_239 = F_181 ( V_240 , V_241 ) ;
if ( ! V_239 ) {
V_132 = - V_193 ;
V_238 = L_29 ;
goto error;
}
snprintf ( V_239 , V_240 , L_30 ,
V_20 -> V_210 , V_12 -> V_3 ) ;
} else {
V_239 = ( char * ) V_20 -> V_210 ;
}
V_132 = F_182 ( * V_236 , V_239 , L_31 , L_32 ,
V_12 -> V_208 ) ;
if ( V_132 ) {
V_238 = L_33 ;
goto error;
}
V_132 = F_182 ( * V_236 , V_239 , L_34 , L_32 ,
V_12 -> V_209 ) ;
if ( V_132 ) {
V_238 = L_35 ;
goto error;
}
if ( V_12 -> V_206 == V_12 -> V_207 ) {
V_132 = F_182 ( * V_236 , V_239 ,
L_36 , L_32 , V_12 -> V_206 ) ;
if ( V_132 ) {
V_238 = L_37 ;
goto error;
}
} else {
V_132 = F_182 ( * V_236 , V_239 ,
L_38 , L_32 , V_12 -> V_206 ) ;
if ( V_132 ) {
V_238 = L_39 ;
goto error;
}
V_132 = F_182 ( * V_236 , V_239 ,
L_40 , L_32 , V_12 -> V_207 ) ;
if ( V_132 ) {
V_238 = L_41 ;
goto error;
}
}
if ( V_237 )
F_164 ( V_239 ) ;
return 0 ;
error:
if ( V_237 )
F_164 ( V_239 ) ;
F_149 ( V_20 , V_132 , L_42 , V_238 ) ;
return V_132 ;
}
static void F_183 ( struct V_55 * V_30 )
{
unsigned int V_14 ;
F_184 () ;
for ( V_14 = 0 ; V_14 < V_30 -> V_31 -> V_58 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
if ( F_18 ( V_30 -> V_31 ) )
F_87 ( & V_12 -> V_24 ) ;
F_185 ( & V_12 -> V_51 ) ;
F_186 ( & V_12 -> V_24 ) ;
}
F_187 () ;
F_164 ( V_30 -> V_59 ) ;
V_30 -> V_59 = NULL ;
}
static int F_188 ( struct V_55 * V_30 ,
unsigned int * V_57 )
{
unsigned int V_14 ;
int V_142 ;
V_30 -> V_59 = F_189 ( * V_57 , sizeof( struct V_11 ) ,
V_241 ) ;
if ( ! V_30 -> V_59 )
return - V_193 ;
F_184 () ;
for ( V_14 = 0 ; V_14 < * V_57 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
V_12 -> V_3 = V_14 ;
V_12 -> V_30 = V_30 ;
V_142 = F_176 ( V_12 ) ;
if ( V_142 < 0 ) {
F_91 ( & V_30 -> V_31 -> V_20 ,
L_43 , V_14 ) ;
* V_57 = V_14 ;
break;
}
F_190 ( V_12 -> V_30 -> V_31 , & V_12 -> V_24 ,
F_108 , 64 ) ;
if ( F_18 ( V_30 -> V_31 ) )
F_40 ( & V_12 -> V_24 ) ;
}
F_191 ( V_30 -> V_31 , * V_57 ) ;
F_187 () ;
if ( * V_57 == 0 ) {
F_192 ( & V_30 -> V_31 -> V_20 , L_44 ) ;
return - V_135 ;
}
return 0 ;
}
static int F_193 ( struct V_191 * V_20 ,
struct V_55 * V_30 )
{
const char * V_238 ;
struct V_235 V_236 ;
int V_132 ;
unsigned int V_223 ;
unsigned int V_14 = 0 ;
unsigned int V_242 = 0 ;
struct V_11 * V_12 = NULL ;
unsigned int V_57 = 1 ;
V_30 -> V_31 -> V_188 = 0 ;
V_132 = F_130 ( V_183 , V_30 -> V_47 -> V_184 ,
L_45 , L_32 , & V_242 ) ;
if ( V_132 < 0 )
V_242 = 1 ;
V_57 = F_194 ( V_242 , V_192 ) ;
V_132 = F_130 ( V_183 , V_30 -> V_47 -> V_184 ,
L_46 , L_32 ,
& V_223 ) ;
if ( V_132 < 0 )
V_223 = 0 ;
V_132 = F_161 ( V_20 , V_30 -> V_31 -> V_243 ) ;
if ( V_132 ) {
F_149 ( V_20 , V_132 , L_47 , V_20 -> V_210 ) ;
goto V_244;
}
if ( V_30 -> V_59 )
F_183 ( V_30 ) ;
V_132 = F_188 ( V_30 , & V_57 ) ;
if ( V_132 < 0 )
goto V_245;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_30 -> V_59 [ V_14 ] ;
V_132 = F_170 ( V_20 , V_12 , V_223 ) ;
if ( V_132 ) {
if ( V_14 > 0 ) {
F_184 () ;
F_191 ( V_30 -> V_31 , V_14 ) ;
F_187 () ;
goto V_245;
} else {
goto V_244;
}
}
}
V_246:
V_132 = F_195 ( & V_236 ) ;
if ( V_132 ) {
F_149 ( V_20 , V_132 , L_48 ) ;
goto V_245;
}
if ( F_196 ( V_183 ,
V_30 -> V_47 -> V_184 , L_45 ) ) {
V_132 = F_182 ( V_236 , V_20 -> V_210 ,
L_49 , L_32 , V_57 ) ;
if ( V_132 ) {
V_238 = L_50 ;
goto V_247;
}
}
if ( V_57 == 1 ) {
V_132 = F_180 ( & V_30 -> V_59 [ 0 ] , & V_236 , 0 ) ;
if ( V_132 )
goto V_247;
} else {
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_30 -> V_59 [ V_14 ] ;
V_132 = F_180 ( V_12 , & V_236 , 1 ) ;
if ( V_132 )
goto V_247;
}
}
V_132 = F_182 ( V_236 , V_20 -> V_210 , L_51 , L_32 ,
1 ) ;
if ( V_132 ) {
V_238 = L_52 ;
goto V_248;
}
V_132 = F_182 ( V_236 , V_20 -> V_210 , L_53 , L_13 , 1 ) ;
if ( V_132 ) {
V_238 = L_54 ;
goto V_248;
}
V_132 = F_182 ( V_236 , V_20 -> V_210 , L_12 , L_13 , 1 ) ;
if ( V_132 ) {
V_238 = L_55 ;
goto V_248;
}
V_132 = F_182 ( V_236 , V_20 -> V_210 , L_15 , L_13 , 1 ) ;
if ( V_132 ) {
V_238 = L_56 ;
goto V_248;
}
V_132 = F_197 ( V_236 , V_20 -> V_210 , L_16 , L_57 ) ;
if ( V_132 ) {
V_238 = L_58 ;
goto V_248;
}
V_132 = F_197 ( V_236 , V_20 -> V_210 , L_14 ,
L_57 ) ;
if ( V_132 ) {
V_238 = L_59 ;
goto V_248;
}
V_132 = F_198 ( V_236 , 0 ) ;
if ( V_132 ) {
if ( V_132 == - V_249 )
goto V_246;
F_149 ( V_20 , V_132 , L_60 ) ;
goto V_245;
}
return 0 ;
V_248:
F_149 ( V_20 , V_132 , L_42 , V_238 ) ;
V_247:
F_198 ( V_236 , 1 ) ;
V_245:
F_154 ( V_30 ) ;
F_164 ( V_30 -> V_59 ) ;
V_30 -> V_59 = NULL ;
V_244:
return V_132 ;
}
static int F_199 ( struct V_19 * V_20 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
unsigned int V_57 = 0 ;
int V_132 ;
unsigned int V_250 ;
unsigned int V_251 = 0 ;
struct V_11 * V_12 = NULL ;
V_132 = F_130 ( V_183 , V_56 -> V_47 -> V_184 ,
L_61 , L_32 , & V_250 ) ;
if ( V_132 != 1 )
V_250 = 0 ;
if ( ! V_250 ) {
F_200 ( & V_20 -> V_20 ,
L_62 ) ;
return - V_252 ;
}
V_132 = F_193 ( V_56 -> V_47 , V_56 ) ;
if ( V_132 )
return V_132 ;
V_57 = V_20 -> V_58 ;
F_184 () ;
F_201 ( V_20 ) ;
F_187 () ;
F_202 ( V_56 -> V_31 ) ;
for ( V_251 = 0 ; V_251 < V_57 ; ++ V_251 ) {
V_12 = & V_56 -> V_59 [ V_251 ] ;
F_37 ( V_12 -> V_120 ) ;
if ( V_12 -> V_120 != V_12 -> V_54 )
F_37 ( V_12 -> V_54 ) ;
F_203 ( & V_12 -> V_103 ) ;
F_45 ( V_12 ) ;
F_204 ( & V_12 -> V_103 ) ;
F_41 ( & V_12 -> V_60 ) ;
F_26 ( V_12 ) ;
F_43 ( & V_12 -> V_60 ) ;
}
return 0 ;
}
static void F_205 ( struct V_191 * V_20 ,
enum V_253 V_254 )
{
struct V_55 * V_56 = F_159 ( & V_20 -> V_20 ) ;
struct V_19 * V_31 = V_56 -> V_31 ;
F_160 ( & V_20 -> V_20 , L_20 , F_206 ( V_254 ) ) ;
switch ( V_254 ) {
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
break;
case V_260 :
if ( V_20 -> V_261 != V_255 )
break;
if ( F_199 ( V_31 ) != 0 )
break;
F_207 ( V_20 , V_262 ) ;
break;
case V_262 :
F_208 ( V_31 ) ;
break;
case V_263 :
if ( V_20 -> V_261 == V_263 )
break;
case V_264 :
F_209 ( V_20 ) ;
break;
}
}
static int F_210 ( struct V_19 * V_20 , int V_265 )
{
switch ( V_265 ) {
case V_266 :
return F_211 ( V_267 ) ;
default:
return - V_135 ;
}
}
static void F_212 ( struct V_19 * V_20 ,
struct V_268 * V_125 , T_7 * V_23 )
{
void * V_56 = F_39 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_211 ( V_267 ) ; V_14 ++ )
V_23 [ V_14 ] = F_213 ( ( V_269 * ) ( V_56 + V_267 [ V_14 ] . V_79 ) ) ;
}
static void F_214 ( struct V_19 * V_20 , T_6 V_270 , T_10 * V_23 )
{
int V_14 ;
switch ( V_270 ) {
case V_266 :
for ( V_14 = 0 ; V_14 < F_211 ( V_267 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_271 ,
V_267 [ V_14 ] . V_216 , V_271 ) ;
break;
}
}
static T_12 F_215 ( struct V_131 * V_20 ,
struct V_272 * V_273 , char * V_274 )
{
return sprintf ( V_274 , L_63 , V_9 ) ;
}
static T_12 F_216 ( struct V_131 * V_20 ,
struct V_272 * V_273 ,
const char * V_274 , T_11 V_80 )
{
char * V_275 ;
unsigned long V_276 ;
if ( ! F_217 ( V_277 ) )
return - V_278 ;
V_276 = F_163 ( V_274 , & V_275 , 0 ) ;
if ( V_275 == V_274 )
return - V_279 ;
return V_80 ;
}
static int F_218 ( struct V_191 * V_20 )
{
struct V_55 * V_30 = F_159 ( & V_20 -> V_20 ) ;
F_160 ( & V_20 -> V_20 , L_20 , V_20 -> V_210 ) ;
F_154 ( V_30 ) ;
F_219 ( V_30 -> V_31 ) ;
if ( V_30 -> V_59 )
F_183 ( V_30 ) ;
F_137 ( V_30 -> V_31 ) ;
return 0 ;
}
static int T_13 F_220 ( void )
{
if ( ! F_221 () )
return - V_252 ;
if ( ! F_222 () )
return - V_252 ;
F_223 ( L_64 ) ;
if ( V_192 == 0 )
V_192 = F_224 () ;
return F_225 ( & V_280 ) ;
}
static void T_14 F_226 ( void )
{
F_227 ( & V_280 ) ;
}
