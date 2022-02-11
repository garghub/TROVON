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
int V_43 = 0 ;
if ( F_15 ( ! F_27 ( V_12 -> V_30 -> V_31 ) ) )
return;
for ( V_40 = V_12 -> V_41 . V_26 ;
V_40 - V_12 -> V_41 . V_27 < V_9 ;
V_40 ++ ) {
struct V_10 * V_5 ;
unsigned short V_3 ;
T_2 V_16 ;
struct V_34 * V_34 ;
struct V_44 * V_45 ;
V_5 = F_20 ( V_12 ) ;
if ( ! V_5 ) {
V_43 = - V_46 ;
break;
}
V_3 = F_6 ( V_40 ) ;
F_28 ( V_12 -> V_15 [ V_3 ] ) ;
V_12 -> V_15 [ V_3 ] = V_5 ;
V_16 = F_29 ( & V_12 -> V_47 ) ;
F_30 ( F_31 ( ( unsigned long ) ( int ) V_16 ) ) ;
V_12 -> V_17 [ V_3 ] = V_16 ;
V_34 = F_32 ( & F_33 ( V_5 ) -> V_48 [ 0 ] ) ;
V_45 = F_34 ( & V_12 -> V_41 , V_40 ) ;
F_35 ( V_16 ,
V_12 -> V_30 -> V_49 -> V_50 ,
V_34 ,
0 ) ;
V_45 -> V_3 = V_3 ;
V_45 -> V_51 = V_16 ;
}
V_12 -> V_41 . V_26 = V_40 ;
if ( V_40 - V_12 -> V_41 . V_27 < V_52 ||
F_15 ( V_43 ) ) {
F_36 ( & V_12 -> V_53 , V_54 + ( V_55 / 10 ) ) ;
return;
}
F_37 () ;
F_38 ( & V_12 -> V_41 , V_42 ) ;
if ( V_42 )
F_39 ( V_12 -> V_56 ) ;
}
static int F_40 ( struct V_19 * V_20 )
{
struct V_57 * V_58 = F_41 ( V_20 ) ;
unsigned int V_59 = V_20 -> V_60 ;
unsigned int V_14 = 0 ;
struct V_11 * V_12 = NULL ;
for ( V_14 = 0 ; V_14 < V_59 ; ++ V_14 ) {
V_12 = & V_58 -> V_61 [ V_14 ] ;
F_42 ( & V_12 -> V_24 ) ;
F_43 ( & V_12 -> V_62 ) ;
if ( F_27 ( V_20 ) ) {
F_26 ( V_12 ) ;
V_12 -> V_41 . V_63 -> V_64 = V_12 -> V_41 . V_27 + 1 ;
if ( F_44 ( & V_12 -> V_41 ) )
F_11 ( & V_12 -> V_24 ) ;
}
F_45 ( & V_12 -> V_62 ) ;
}
F_46 ( V_20 ) ;
return 0 ;
}
static void F_47 ( struct V_11 * V_12 )
{
T_1 V_65 , V_66 ;
unsigned short V_3 ;
struct V_10 * V_5 ;
bool V_67 ;
F_28 ( ! F_27 ( V_12 -> V_30 -> V_31 ) ) ;
do {
V_66 = V_12 -> V_25 . V_63 -> V_68 ;
F_48 () ;
for ( V_65 = V_12 -> V_25 . V_27 ; V_65 != V_66 ; V_65 ++ ) {
struct V_69 * V_70 ;
V_70 = F_49 ( & V_12 -> V_25 , V_65 ) ;
if ( V_70 -> V_71 == V_72 )
continue;
V_3 = V_70 -> V_3 ;
V_5 = V_12 -> V_73 [ V_3 ] . V_5 ;
if ( F_15 ( F_50 (
V_12 -> V_74 [ V_3 ] ) != 0 ) ) {
F_51 ( L_1 ,
V_75 ) ;
F_52 () ;
}
F_53 (
V_12 -> V_74 [ V_3 ] , V_76 ) ;
F_54 (
& V_12 -> V_77 , V_12 -> V_74 [ V_3 ] ) ;
V_12 -> V_74 [ V_3 ] = V_18 ;
V_12 -> V_78 [ V_3 ] = NULL ;
F_4 ( & V_12 -> V_79 , V_12 -> V_73 , V_3 ) ;
F_55 ( V_5 ) ;
}
V_12 -> V_25 . V_27 = V_66 ;
F_56 ( & V_12 -> V_25 , V_67 ) ;
} while ( V_67 );
F_13 ( V_12 ) ;
}
static void F_57 ( unsigned long V_80 , unsigned int V_81 ,
unsigned int V_82 , void * V_23 )
{
struct V_83 * V_30 = V_23 ;
unsigned int V_3 ;
struct V_84 * V_25 ;
T_2 V_16 ;
struct V_34 * V_34 = V_30 -> V_34 ;
struct V_11 * V_12 = V_30 -> V_12 ;
struct V_10 * V_5 = V_30 -> V_5 ;
V_3 = F_5 ( & V_12 -> V_79 , V_12 -> V_73 ) ;
V_25 = F_34 ( & V_12 -> V_25 , V_12 -> V_25 . V_26 ++ ) ;
V_16 = F_29 ( & V_12 -> V_77 ) ;
F_30 ( F_31 ( ( unsigned long ) ( int ) V_16 ) ) ;
F_58 ( V_16 , V_12 -> V_30 -> V_49 -> V_50 ,
V_80 , V_76 ) ;
V_12 -> V_73 [ V_3 ] . V_5 = V_5 ;
V_12 -> V_78 [ V_3 ] = V_34 ;
V_12 -> V_74 [ V_3 ] = V_16 ;
V_25 -> V_3 = V_3 ;
V_25 -> V_51 = V_16 ;
V_25 -> V_81 = V_81 ;
V_25 -> V_85 = V_82 ;
V_25 -> V_86 = 0 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_85 += V_25 -> V_85 ;
}
static struct V_84 * F_59 (
struct V_11 * V_12 , struct V_10 * V_5 ,
struct V_34 * V_34 , unsigned int V_81 , unsigned int V_82 )
{
struct V_83 V_30 = {
. V_12 = V_12 ,
. V_5 = V_5 ,
. V_34 = V_34 ,
. V_85 = 0 ,
} ;
F_60 ( V_34 , V_81 , V_82 , F_57 , & V_30 ) ;
return V_30 . V_25 ;
}
static void F_61 ( unsigned long V_80 , unsigned int V_81 ,
unsigned int V_82 , void * V_23 )
{
struct V_83 * V_30 = V_23 ;
V_30 -> V_25 -> V_86 |= V_87 ;
F_62 ( V_30 -> V_5 ) ;
F_57 ( V_80 , V_81 , V_82 , V_23 ) ;
}
static struct V_84 * F_63 (
struct V_11 * V_12 , struct V_84 * V_25 ,
struct V_10 * V_5 , struct V_34 * V_34 ,
unsigned int V_81 , unsigned int V_82 )
{
struct V_83 V_30 = {
. V_12 = V_12 ,
. V_5 = V_5 ,
. V_25 = V_25 ,
} ;
V_34 += V_81 >> V_88 ;
V_81 &= ~ V_89 ;
while ( V_82 ) {
V_30 . V_34 = V_34 ;
V_30 . V_85 = 0 ;
F_64 ( V_34 , V_81 , V_82 ,
F_61 ,
& V_30 ) ;
V_34 ++ ;
V_81 = 0 ;
V_82 -= V_30 . V_85 ;
}
return V_30 . V_25 ;
}
static int F_65 ( struct V_10 * V_5 )
{
int V_14 , V_48 = F_33 ( V_5 ) -> V_90 ;
int V_91 ;
V_91 = F_66 ( F_67 ( V_5 -> V_23 ) ,
F_68 ( V_5 ) ) ;
for ( V_14 = 0 ; V_14 < V_48 ; V_14 ++ ) {
T_3 * V_92 = F_33 ( V_5 ) -> V_48 + V_14 ;
unsigned long V_85 = F_69 ( V_92 ) ;
unsigned long V_81 = V_92 -> V_93 ;
V_81 &= ~ V_89 ;
V_91 += F_66 ( V_81 , V_85 ) ;
}
return V_91 ;
}
static T_4 F_70 ( struct V_19 * V_20 , struct V_10 * V_5 ,
void * V_94 , T_5 V_95 )
{
unsigned int V_59 = V_20 -> V_60 ;
T_6 V_96 ;
T_4 V_97 ;
if ( V_59 == 1 ) {
V_97 = 0 ;
} else {
V_96 = F_71 ( V_5 ) ;
V_97 = V_96 % V_59 ;
}
return V_97 ;
}
static int F_72 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
struct V_57 * V_58 = F_41 ( V_20 ) ;
struct V_98 * V_99 = F_73 ( V_58 -> V_99 ) ;
struct V_84 * V_25 , * V_100 ;
unsigned int V_14 ;
int V_42 ;
int V_91 ;
struct V_34 * V_34 ;
unsigned int V_81 ;
unsigned int V_82 ;
unsigned long V_86 ;
struct V_11 * V_12 = NULL ;
unsigned int V_59 = V_20 -> V_60 ;
T_4 V_101 ;
struct V_10 * V_102 ;
if ( V_59 < 1 )
goto V_103;
V_101 = F_74 ( V_5 ) ;
V_12 = & V_58 -> V_61 [ V_101 ] ;
if ( F_15 ( V_5 -> V_82 > V_104 ) ) {
F_75 (
L_2 ,
V_5 -> V_82 ) ;
goto V_103;
}
V_91 = F_65 ( V_5 ) ;
if ( F_15 ( V_91 > V_105 + 1 ) ) {
F_76 ( L_3 ,
V_91 , V_5 -> V_82 ) ;
if ( F_77 ( V_5 ) )
goto V_103;
}
V_34 = F_78 ( V_5 -> V_23 ) ;
V_81 = F_67 ( V_5 -> V_23 ) ;
if ( F_15 ( V_39 - V_81 < V_106 ) ) {
V_102 = F_79 ( V_5 , V_37 ) ;
if ( ! V_102 )
goto V_103;
F_80 ( V_5 ) ;
V_5 = V_102 ;
V_34 = F_78 ( V_5 -> V_23 ) ;
V_81 = F_67 ( V_5 -> V_23 ) ;
}
V_82 = F_68 ( V_5 ) ;
F_81 ( & V_12 -> V_107 , V_86 ) ;
if ( F_15 ( ! F_27 ( V_20 ) ||
( V_91 > 1 && ! F_9 ( V_20 ) ) ||
F_82 ( V_5 , F_83 ( V_5 ) ) ) ) {
F_84 ( & V_12 -> V_107 , V_86 ) ;
goto V_103;
}
V_100 = V_25 = F_59 ( V_12 , V_5 ,
V_34 , V_81 , V_82 ) ;
V_81 += V_25 -> V_85 ;
if ( V_81 == V_39 ) {
V_34 ++ ;
V_81 = 0 ;
}
V_82 -= V_25 -> V_85 ;
if ( V_5 -> V_108 == V_109 )
V_25 -> V_86 |= V_110 | V_111 ;
else if ( V_5 -> V_108 == V_112 )
V_25 -> V_86 |= V_111 ;
if ( F_33 ( V_5 ) -> V_113 ) {
struct V_114 * V_115 ;
V_115 = (struct V_114 * )
F_34 ( & V_12 -> V_25 , V_12 -> V_25 . V_26 ++ ) ;
V_25 -> V_86 |= V_116 ;
V_115 -> V_117 . V_115 . V_85 = F_33 ( V_5 ) -> V_113 ;
V_115 -> V_117 . V_115 . type = ( F_33 ( V_5 ) -> V_118 & V_119 ) ?
V_120 :
V_121 ;
V_115 -> V_117 . V_115 . V_122 = 0 ;
V_115 -> V_117 . V_115 . V_21 = 0 ;
V_115 -> type = V_123 ;
V_115 -> V_86 = 0 ;
}
V_25 = F_63 ( V_12 , V_25 , V_5 , V_34 , V_81 , V_82 ) ;
for ( V_14 = 0 ; V_14 < F_33 ( V_5 ) -> V_90 ; V_14 ++ ) {
T_3 * V_92 = & F_33 ( V_5 ) -> V_48 [ V_14 ] ;
V_25 = F_63 ( V_12 , V_25 , V_5 ,
F_32 ( V_92 ) , V_92 -> V_93 ,
F_69 ( V_92 ) ) ;
}
V_100 -> V_85 = V_5 -> V_82 ;
F_38 ( & V_12 -> V_25 , V_42 ) ;
if ( V_42 )
F_39 ( V_12 -> V_124 ) ;
F_85 ( & V_99 -> V_125 ) ;
V_99 -> V_126 += V_5 -> V_82 ;
V_99 -> V_127 ++ ;
F_86 ( & V_99 -> V_125 ) ;
F_47 ( V_12 ) ;
if ( ! F_12 ( V_12 ) )
F_87 ( F_14 ( V_20 , V_12 -> V_3 ) ) ;
F_84 ( & V_12 -> V_107 , V_86 ) ;
return V_128 ;
V_103:
V_20 -> V_129 . V_130 ++ ;
F_88 ( V_5 ) ;
return V_128 ;
}
static int F_89 ( struct V_19 * V_20 )
{
struct V_57 * V_58 = F_41 ( V_20 ) ;
unsigned int V_59 = V_20 -> V_60 ;
unsigned int V_14 ;
struct V_11 * V_12 ;
F_90 ( V_58 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_59 ; ++ V_14 ) {
V_12 = & V_58 -> V_61 [ V_14 ] ;
F_91 ( & V_12 -> V_24 ) ;
}
return 0 ;
}
static void F_92 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_131 = F_6 ( V_12 -> V_41 . V_26 ) ;
F_28 ( V_12 -> V_15 [ V_131 ] ) ;
V_12 -> V_15 [ V_131 ] = V_5 ;
V_12 -> V_17 [ V_131 ] = V_16 ;
F_34 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_3 = V_131 ;
F_34 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_51 = V_16 ;
V_12 -> V_41 . V_26 ++ ;
}
static int F_93 ( struct V_11 * V_12 ,
struct V_114 * V_132 ,
T_1 V_133 )
{
struct V_114 * V_134 ;
struct V_135 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_65 = V_12 -> V_41 . V_27 ;
int V_43 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_65 + 1 == V_133 ) ) {
if ( F_94 () )
F_95 ( V_20 , L_4 ) ;
V_43 = - V_136 ;
break;
}
V_134 = (struct V_114 * )
F_49 ( & V_12 -> V_41 , ++ V_65 ) ;
if ( F_15 ( ! V_134 -> type ||
V_134 -> type >= V_137 ) ) {
if ( F_94 () )
F_95 ( V_20 , L_5 ,
V_134 -> type ) ;
V_43 = - V_138 ;
} else {
memcpy ( & V_132 [ V_134 -> type - 1 ] , V_134 ,
sizeof( * V_134 ) ) ;
}
V_5 = F_7 ( V_12 , V_65 ) ;
V_16 = F_8 ( V_12 , V_65 ) ;
F_92 ( V_12 , V_5 , V_16 ) ;
} while ( V_134 -> V_86 & V_139 );
V_12 -> V_41 . V_27 = V_65 ;
return V_43 ;
}
static int F_96 ( struct V_11 * V_12 ,
struct V_140 * V_141 , T_1 V_133 ,
struct V_142 * V_2 )
{
struct V_143 * V_41 = & V_141 -> V_41 ;
struct V_114 * V_132 = V_141 -> V_132 ;
struct V_135 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_65 = V_12 -> V_41 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_65 ) ;
T_2 V_16 = F_8 ( V_12 , V_65 ) ;
int V_144 = V_29 + ( V_41 -> V_71 <= V_35 ) ;
int V_91 = 1 ;
int V_43 = 0 ;
unsigned long V_145 ;
if ( V_41 -> V_86 & V_146 ) {
V_43 = F_93 ( V_12 , V_132 , V_133 ) ;
V_65 = V_12 -> V_41 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_41 -> V_71 < 0 ||
V_41 -> V_81 + V_41 -> V_71 > V_147 ) ) {
if ( F_94 () )
F_95 ( V_20 , L_6 ,
V_41 -> V_81 , V_41 -> V_71 ) ;
F_92 ( V_12 , V_5 , V_16 ) ;
V_43 = - V_138 ;
goto V_148;
}
if ( V_16 == V_18 ) {
if ( F_94 () )
F_95 ( V_20 , L_7 ,
V_41 -> V_3 ) ;
V_43 = - V_138 ;
goto V_148;
}
V_145 = F_53 ( V_16 , 0 ) ;
F_28 ( ! V_145 ) ;
F_54 ( & V_12 -> V_47 , V_16 ) ;
F_97 ( V_2 , V_5 ) ;
V_148:
if ( ! ( V_41 -> V_86 & V_149 ) )
break;
if ( V_65 + V_91 == V_133 ) {
if ( F_94 () )
F_95 ( V_20 , L_8 ) ;
V_43 = - V_150 ;
break;
}
V_41 = F_49 ( & V_12 -> V_41 , V_65 + V_91 ) ;
V_5 = F_7 ( V_12 , V_65 + V_91 ) ;
V_16 = F_8 ( V_12 , V_65 + V_91 ) ;
V_91 ++ ;
}
if ( F_15 ( V_91 > V_144 ) ) {
if ( F_94 () )
F_95 ( V_20 , L_9 ) ;
V_43 = - V_151 ;
}
if ( F_15 ( V_43 ) )
V_12 -> V_41 . V_27 = V_65 + V_91 ;
return V_43 ;
}
static int F_98 ( struct V_10 * V_5 ,
struct V_114 * V_115 )
{
if ( ! V_115 -> V_117 . V_115 . V_85 ) {
if ( F_94 () )
F_99 ( L_10 ) ;
return - V_138 ;
}
if ( V_115 -> V_117 . V_115 . type != V_121 &&
V_115 -> V_117 . V_115 . type != V_120 ) {
if ( F_94 () )
F_99 ( L_11 , V_115 -> V_117 . V_115 . type ) ;
return - V_138 ;
}
F_33 ( V_5 ) -> V_113 = V_115 -> V_117 . V_115 . V_85 ;
F_33 ( V_5 ) -> V_118 =
( V_115 -> V_117 . V_115 . type == V_121 ) ?
V_152 :
V_119 ;
F_33 ( V_5 ) -> V_118 |= V_153 ;
F_33 ( V_5 ) -> V_154 = 0 ;
return 0 ;
}
static T_1 F_100 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_142 * V_2 )
{
struct V_155 * V_156 = F_33 ( V_5 ) ;
T_1 V_65 = V_12 -> V_41 . V_27 ;
struct V_10 * V_102 ;
while ( ( V_102 = F_101 ( V_2 ) ) ) {
struct V_143 * V_41 =
F_49 ( & V_12 -> V_41 , ++ V_65 ) ;
T_3 * V_157 = & F_33 ( V_102 ) -> V_48 [ 0 ] ;
if ( V_156 -> V_90 == V_29 ) {
unsigned int V_158 = F_102 ( V_5 ) -> V_158 ;
F_28 ( V_158 <= F_68 ( V_5 ) ) ;
F_103 ( V_5 , V_158 - F_68 ( V_5 ) ) ;
}
F_28 ( V_156 -> V_90 >= V_29 ) ;
F_24 ( V_5 , V_156 -> V_90 , F_32 ( V_157 ) ,
V_41 -> V_81 , V_41 -> V_71 , V_39 ) ;
F_33 ( V_102 ) -> V_90 = 0 ;
F_23 ( V_102 ) ;
}
return V_65 ;
}
static int F_104 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
bool V_159 = false ;
if ( V_5 -> V_108 != V_109 && F_105 ( V_5 ) ) {
struct V_57 * V_58 = F_41 ( V_20 ) ;
F_106 ( & V_58 -> V_160 ) ;
V_5 -> V_108 = V_109 ;
V_159 = true ;
}
if ( V_5 -> V_108 != V_109 )
return 0 ;
return F_107 ( V_5 , V_159 ) ;
}
static int F_108 ( struct V_11 * V_12 ,
struct V_142 * V_161 )
{
struct V_98 * V_162 = F_73 ( V_12 -> V_30 -> V_162 ) ;
int V_163 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_101 ( V_161 ) ) != NULL ) {
int V_158 = F_102 ( V_5 ) -> V_158 ;
if ( V_158 > F_68 ( V_5 ) )
F_103 ( V_5 , V_158 - F_68 ( V_5 ) ) ;
V_5 -> V_164 = F_109 ( V_5 , V_12 -> V_30 -> V_31 ) ;
F_110 ( V_5 ) ;
if ( F_104 ( V_12 -> V_30 -> V_31 , V_5 ) ) {
F_23 ( V_5 ) ;
V_163 ++ ;
V_12 -> V_30 -> V_31 -> V_129 . V_165 ++ ;
continue;
}
F_85 ( & V_162 -> V_125 ) ;
V_162 -> V_127 ++ ;
V_162 -> V_126 += V_5 -> V_82 ;
F_86 ( & V_162 -> V_125 ) ;
F_111 ( & V_12 -> V_24 , V_5 ) ;
}
return V_163 ;
}
static int F_112 ( struct V_166 * V_24 , int V_167 )
{
struct V_11 * V_12 = F_113 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
struct V_10 * V_5 ;
struct V_140 V_141 ;
struct V_143 * V_41 = & V_141 . V_41 ;
struct V_114 * V_132 = V_141 . V_132 ;
T_1 V_14 , V_133 ;
int V_168 ;
struct V_142 V_161 ;
struct V_142 V_169 ;
struct V_142 V_170 ;
int V_43 ;
F_114 ( & V_12 -> V_62 ) ;
F_115 ( & V_161 ) ;
F_115 ( & V_169 ) ;
F_115 ( & V_170 ) ;
V_133 = V_12 -> V_41 . V_63 -> V_68 ;
F_48 () ;
V_14 = V_12 -> V_41 . V_27 ;
V_168 = 0 ;
while ( ( V_14 != V_133 ) && ( V_168 < V_167 ) ) {
memcpy ( V_41 , F_49 ( & V_12 -> V_41 , V_14 ) , sizeof( * V_41 ) ) ;
memset ( V_132 , 0 , sizeof( V_141 . V_132 ) ) ;
V_43 = F_96 ( V_12 , & V_141 , V_133 , & V_170 ) ;
if ( F_15 ( V_43 ) ) {
V_43:
while ( ( V_5 = F_101 ( & V_170 ) ) )
F_97 ( & V_169 , V_5 ) ;
V_20 -> V_129 . V_165 ++ ;
V_14 = V_12 -> V_41 . V_27 ;
continue;
}
V_5 = F_101 ( & V_170 ) ;
if ( V_132 [ V_123 - 1 ] . type ) {
struct V_114 * V_115 ;
V_115 = & V_132 [ V_123 - 1 ] ;
if ( F_15 ( F_98 ( V_5 , V_115 ) ) ) {
F_116 ( & V_170 , V_5 ) ;
V_12 -> V_41 . V_27 += F_117 ( & V_170 ) ;
goto V_43;
}
}
F_102 ( V_5 ) -> V_158 = V_41 -> V_71 ;
if ( F_102 ( V_5 ) -> V_158 > V_35 )
F_102 ( V_5 ) -> V_158 = V_35 ;
F_33 ( V_5 ) -> V_48 [ 0 ] . V_93 = V_41 -> V_81 ;
F_118 ( & F_33 ( V_5 ) -> V_48 [ 0 ] , V_41 -> V_71 ) ;
V_5 -> V_171 = V_41 -> V_71 ;
V_5 -> V_82 += V_41 -> V_71 ;
V_14 = F_100 ( V_12 , V_5 , & V_170 ) ;
if ( V_41 -> V_86 & V_172 )
V_5 -> V_108 = V_109 ;
else if ( V_41 -> V_86 & V_173 )
V_5 -> V_108 = V_112 ;
F_97 ( & V_161 , V_5 ) ;
V_12 -> V_41 . V_27 = ++ V_14 ;
V_168 ++ ;
}
F_119 ( & V_169 ) ;
V_168 -= F_108 ( V_12 , & V_161 ) ;
F_26 ( V_12 ) ;
if ( V_168 < V_167 ) {
int V_67 = 0 ;
F_120 ( V_24 , V_168 ) ;
F_56 ( & V_12 -> V_41 , V_67 ) ;
if ( V_67 )
F_11 ( V_24 ) ;
}
F_121 ( & V_12 -> V_62 ) ;
return V_168 ;
}
static int F_122 ( struct V_19 * V_20 , int V_174 )
{
int V_144 = F_9 ( V_20 ) ? V_104 : V_175 ;
if ( V_174 > V_144 )
return - V_138 ;
V_20 -> V_174 = V_174 ;
return 0 ;
}
static void F_123 ( struct V_19 * V_20 ,
struct V_176 * V_177 )
{
struct V_57 * V_58 = F_41 ( V_20 ) ;
int V_178 ;
F_124 (cpu) {
struct V_98 * V_162 = F_125 ( V_58 -> V_162 , V_178 ) ;
struct V_98 * V_99 = F_125 ( V_58 -> V_99 , V_178 ) ;
T_7 V_179 , V_180 , V_181 , V_182 ;
unsigned int V_183 ;
do {
V_183 = F_126 ( & V_99 -> V_125 ) ;
V_181 = V_99 -> V_127 ;
V_182 = V_99 -> V_126 ;
} while ( F_127 ( & V_99 -> V_125 , V_183 ) );
do {
V_183 = F_126 ( & V_162 -> V_125 ) ;
V_179 = V_162 -> V_127 ;
V_180 = V_162 -> V_126 ;
} while ( F_127 ( & V_162 -> V_125 , V_183 ) );
V_177 -> V_179 += V_179 ;
V_177 -> V_181 += V_181 ;
V_177 -> V_180 += V_180 ;
V_177 -> V_182 += V_182 ;
}
V_177 -> V_165 = V_20 -> V_129 . V_165 ;
V_177 -> V_130 = V_20 -> V_129 . V_130 ;
}
static void F_128 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
if ( F_2 ( & V_12 -> V_73 [ V_14 ] ) )
continue;
V_5 = V_12 -> V_73 [ V_14 ] . V_5 ;
F_129 ( V_12 -> V_78 [ V_14 ] ) ;
F_130 ( V_12 -> V_74 [ V_14 ] ,
V_76 ,
( unsigned long ) F_131 ( V_12 -> V_78 [ V_14 ] ) ) ;
V_12 -> V_78 [ V_14 ] = NULL ;
V_12 -> V_74 [ V_14 ] = V_18 ;
F_4 ( & V_12 -> V_79 , V_12 -> V_73 , V_14 ) ;
F_55 ( V_5 ) ;
}
}
static void F_132 ( struct V_11 * V_12 )
{
int V_3 , V_16 ;
F_43 ( & V_12 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
struct V_10 * V_5 ;
struct V_34 * V_34 ;
V_5 = V_12 -> V_15 [ V_3 ] ;
if ( ! V_5 )
continue;
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 )
continue;
V_34 = F_32 ( & F_33 ( V_5 ) -> V_48 [ 0 ] ) ;
F_129 ( V_34 ) ;
F_130 ( V_16 , 0 ,
( unsigned long ) F_131 ( V_34 ) ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
F_23 ( V_5 ) ;
}
F_45 ( & V_12 -> V_62 ) ;
}
static T_8 F_133 ( struct V_19 * V_20 ,
T_8 V_21 )
{
struct V_57 * V_58 = F_41 ( V_20 ) ;
if ( V_21 & V_22 &&
! F_134 ( V_58 -> V_49 -> V_184 , L_12 , 0 ) )
V_21 &= ~ V_22 ;
if ( V_21 & V_185 &&
! F_134 ( V_58 -> V_49 -> V_184 ,
L_13 , 0 ) )
V_21 &= ~ V_185 ;
if ( V_21 & V_186 &&
! F_134 ( V_58 -> V_49 -> V_184 , L_14 , 0 ) )
V_21 &= ~ V_186 ;
if ( V_21 & V_187 &&
! F_134 ( V_58 -> V_49 -> V_184 , L_15 , 0 ) )
V_21 &= ~ V_187 ;
return V_21 ;
}
static int F_135 ( struct V_19 * V_20 ,
T_8 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_174 > V_175 ) {
F_136 ( V_20 , L_16 ) ;
V_20 -> V_174 = V_175 ;
}
return 0 ;
}
static T_9 F_137 ( int V_188 , void * V_189 )
{
struct V_11 * V_12 = V_189 ;
unsigned long V_86 ;
F_81 ( & V_12 -> V_107 , V_86 ) ;
F_47 ( V_12 ) ;
F_84 ( & V_12 -> V_107 , V_86 ) ;
return V_190 ;
}
static T_9 F_138 ( int V_188 , void * V_189 )
{
struct V_11 * V_12 = V_189 ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
if ( F_17 ( F_27 ( V_20 ) &&
F_44 ( & V_12 -> V_41 ) ) )
F_11 ( & V_12 -> V_24 ) ;
return V_190 ;
}
static T_9 F_139 ( int V_188 , void * V_189 )
{
F_137 ( V_188 , V_189 ) ;
F_138 ( V_188 , V_189 ) ;
return V_190 ;
}
static void F_140 ( struct V_19 * V_20 )
{
struct V_57 * V_30 = F_41 ( V_20 ) ;
unsigned int V_59 = V_20 -> V_60 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_59 ; ++ V_14 )
F_139 ( 0 , & V_30 -> V_61 [ V_14 ] ) ;
}
static void F_141 ( struct V_19 * V_31 )
{
struct V_57 * V_58 = F_41 ( V_31 ) ;
F_142 ( V_58 -> V_162 ) ;
F_142 ( V_58 -> V_99 ) ;
F_143 ( V_31 ) ;
}
static struct V_19 * F_144 ( struct V_191 * V_20 )
{
int V_43 ;
struct V_19 * V_31 ;
struct V_57 * V_58 ;
V_31 = F_145 ( sizeof( struct V_57 ) , V_192 ) ;
if ( ! V_31 )
return F_146 ( - V_46 ) ;
V_58 = F_41 ( V_31 ) ;
V_58 -> V_49 = V_20 ;
V_58 -> V_61 = NULL ;
V_43 = - V_46 ;
V_58 -> V_162 = F_147 ( struct V_98 ) ;
if ( V_58 -> V_162 == NULL )
goto exit;
V_58 -> V_99 = F_147 ( struct V_98 ) ;
if ( V_58 -> V_99 == NULL )
goto exit;
V_31 -> V_193 = & V_194 ;
V_31 -> V_21 = V_195 | V_196 |
V_197 ;
V_31 -> V_198 = V_22 |
V_185 |
V_186 | V_187 ;
V_31 -> V_21 |= V_31 -> V_198 ;
V_31 -> V_199 = & V_200 ;
V_31 -> V_201 = V_202 ;
V_31 -> V_203 = V_104 ;
F_148 ( V_31 , & V_20 -> V_20 ) ;
V_58 -> V_31 = V_31 ;
F_149 ( V_31 ) ;
return V_31 ;
exit:
F_141 ( V_31 ) ;
return F_146 ( V_43 ) ;
}
static int F_150 ( struct V_191 * V_20 ,
const struct V_204 * V_3 )
{
int V_43 ;
struct V_19 * V_31 ;
struct V_57 * V_30 ;
V_31 = F_144 ( V_20 ) ;
if ( F_151 ( V_31 ) ) {
V_43 = F_152 ( V_31 ) ;
F_153 ( V_20 , V_43 , L_17 ) ;
return V_43 ;
}
V_30 = F_41 ( V_31 ) ;
F_154 ( & V_20 -> V_20 , V_30 ) ;
#ifdef F_155
V_30 -> V_31 -> V_205 [ 0 ] = & V_206 ;
#endif
V_43 = F_156 ( V_30 -> V_31 ) ;
if ( V_43 ) {
F_99 ( L_18 , V_75 , V_43 ) ;
goto V_207;
}
return 0 ;
V_207:
F_141 ( V_31 ) ;
F_154 ( & V_20 -> V_20 , NULL ) ;
return V_43 ;
}
static void F_157 ( int V_16 , void * V_34 )
{
if ( V_16 != V_18 )
F_130 ( V_16 , 0 , ( unsigned long ) V_34 ) ;
}
static void F_158 ( struct V_57 * V_30 )
{
unsigned int V_14 = 0 ;
unsigned int V_59 = V_30 -> V_31 -> V_60 ;
F_149 ( V_30 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_59 && V_30 -> V_61 ; ++ V_14 ) {
struct V_11 * V_12 = & V_30 -> V_61 [ V_14 ] ;
F_159 ( & V_12 -> V_53 ) ;
if ( V_12 -> V_124 && ( V_12 -> V_124 == V_12 -> V_56 ) )
F_160 ( V_12 -> V_124 , V_12 ) ;
if ( V_12 -> V_124 && ( V_12 -> V_124 != V_12 -> V_56 ) ) {
F_160 ( V_12 -> V_124 , V_12 ) ;
F_160 ( V_12 -> V_56 , V_12 ) ;
}
V_12 -> V_208 = V_12 -> V_209 = 0 ;
V_12 -> V_124 = V_12 -> V_56 = 0 ;
if ( F_18 ( V_30 -> V_31 ) )
F_161 ( & V_12 -> V_24 ) ;
F_128 ( V_12 ) ;
F_132 ( V_12 ) ;
F_162 ( V_12 -> V_77 ) ;
F_162 ( V_12 -> V_47 ) ;
F_157 ( V_12 -> V_210 , V_12 -> V_25 . V_63 ) ;
F_157 ( V_12 -> V_211 , V_12 -> V_41 . V_63 ) ;
V_12 -> V_210 = V_18 ;
V_12 -> V_211 = V_18 ;
V_12 -> V_25 . V_63 = NULL ;
V_12 -> V_41 . V_63 = NULL ;
}
}
static int F_163 ( struct V_191 * V_20 )
{
struct V_57 * V_30 = F_164 ( & V_20 -> V_20 ) ;
F_165 ( & V_20 -> V_20 , L_19 , V_20 -> V_212 ) ;
F_158 ( V_30 ) ;
return 0 ;
}
static int F_166 ( struct V_191 * V_20 , T_10 V_213 [] )
{
char * V_214 , * V_215 , * V_216 ;
int V_14 ;
V_216 = V_214 = F_167 ( V_217 , V_20 -> V_212 , L_20 , NULL ) ;
if ( F_151 ( V_216 ) )
return F_152 ( V_216 ) ;
for ( V_14 = 0 ; V_14 < V_218 ; V_14 ++ ) {
V_213 [ V_14 ] = F_168 ( V_214 , & V_215 , 16 ) ;
if ( ( V_214 == V_215 ) || ( * V_215 != ( ( V_14 == V_218 - 1 ) ? '\0' : ':' ) ) ) {
F_169 ( V_216 ) ;
return - V_150 ;
}
V_214 = V_215 + 1 ;
}
F_169 ( V_216 ) ;
return 0 ;
}
static int F_170 ( struct V_11 * V_12 )
{
int V_43 ;
V_43 = F_171 ( V_12 -> V_30 -> V_49 , & V_12 -> V_208 ) ;
if ( V_43 < 0 )
goto V_207;
V_43 = F_172 ( V_12 -> V_208 ,
F_139 ,
0 , V_12 -> V_30 -> V_31 -> V_219 , V_12 ) ;
if ( V_43 < 0 )
goto V_220;
V_12 -> V_209 = V_12 -> V_208 ;
V_12 -> V_56 = V_12 -> V_124 = V_43 ;
return 0 ;
V_220:
F_173 ( V_12 -> V_30 -> V_49 , V_12 -> V_208 ) ;
V_12 -> V_208 = 0 ;
V_207:
return V_43 ;
}
static int F_174 ( struct V_11 * V_12 )
{
int V_43 ;
V_43 = F_171 ( V_12 -> V_30 -> V_49 , & V_12 -> V_208 ) ;
if ( V_43 < 0 )
goto V_207;
V_43 = F_171 ( V_12 -> V_30 -> V_49 , & V_12 -> V_209 ) ;
if ( V_43 < 0 )
goto V_221;
snprintf ( V_12 -> V_222 , sizeof( V_12 -> V_222 ) ,
L_21 , V_12 -> V_219 ) ;
V_43 = F_172 ( V_12 -> V_208 ,
F_137 ,
0 , V_12 -> V_222 , V_12 ) ;
if ( V_43 < 0 )
goto V_223;
V_12 -> V_124 = V_43 ;
snprintf ( V_12 -> V_224 , sizeof( V_12 -> V_224 ) ,
L_22 , V_12 -> V_219 ) ;
V_43 = F_172 ( V_12 -> V_209 ,
F_138 ,
0 , V_12 -> V_224 , V_12 ) ;
if ( V_43 < 0 )
goto V_225;
V_12 -> V_56 = V_43 ;
return 0 ;
V_225:
F_160 ( V_12 -> V_124 , V_12 ) ;
V_12 -> V_124 = 0 ;
V_223:
F_173 ( V_12 -> V_30 -> V_49 , V_12 -> V_209 ) ;
V_12 -> V_209 = 0 ;
V_221:
F_173 ( V_12 -> V_30 -> V_49 , V_12 -> V_208 ) ;
V_12 -> V_208 = 0 ;
V_207:
return V_43 ;
}
static int F_175 ( struct V_191 * V_20 ,
struct V_11 * V_12 , unsigned int V_226 )
{
struct V_227 * V_228 ;
struct V_229 * V_230 ;
T_2 V_51 ;
int V_43 ;
V_12 -> V_210 = V_18 ;
V_12 -> V_211 = V_18 ;
V_12 -> V_41 . V_63 = NULL ;
V_12 -> V_25 . V_63 = NULL ;
V_228 = (struct V_227 * ) F_176 ( V_231 | V_232 ) ;
if ( ! V_228 ) {
V_43 = - V_46 ;
F_153 ( V_20 , V_43 , L_23 ) ;
goto V_207;
}
F_177 ( V_228 ) ;
F_178 ( & V_12 -> V_25 , V_228 , V_147 ) ;
V_43 = F_179 ( V_20 , V_228 , 1 , & V_51 ) ;
if ( V_43 < 0 )
goto V_233;
V_12 -> V_210 = V_51 ;
V_230 = (struct V_229 * ) F_176 ( V_231 | V_232 ) ;
if ( ! V_230 ) {
V_43 = - V_46 ;
F_153 ( V_20 , V_43 , L_24 ) ;
goto V_234;
}
F_177 ( V_230 ) ;
F_178 ( & V_12 -> V_41 , V_230 , V_147 ) ;
V_43 = F_179 ( V_20 , V_230 , 1 , & V_51 ) ;
if ( V_43 < 0 )
goto V_235;
V_12 -> V_211 = V_51 ;
if ( V_226 )
V_43 = F_174 ( V_12 ) ;
if ( ! V_226 || ( V_226 && V_43 ) )
V_43 = F_170 ( V_12 ) ;
if ( V_43 )
goto V_236;
return 0 ;
V_236:
F_53 ( V_12 -> V_211 , 0 ) ;
V_235:
F_180 ( ( unsigned long ) V_230 ) ;
V_234:
F_53 ( V_12 -> V_210 , 0 ) ;
V_233:
F_180 ( ( unsigned long ) V_228 ) ;
V_207:
return V_43 ;
}
static int F_181 ( struct V_11 * V_12 )
{
unsigned short V_14 ;
int V_43 = 0 ;
F_182 ( & V_12 -> V_107 ) ;
F_182 ( & V_12 -> V_62 ) ;
F_183 ( & V_12 -> V_53 , F_10 ,
( unsigned long ) V_12 ) ;
snprintf ( V_12 -> V_219 , sizeof( V_12 -> V_219 ) , L_25 ,
V_12 -> V_30 -> V_31 -> V_219 , V_12 -> V_3 ) ;
V_12 -> V_79 = 0 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
F_1 ( & V_12 -> V_73 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_74 [ V_14 ] = V_18 ;
V_12 -> V_78 [ V_14 ] = NULL ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_184 ( V_28 ,
& V_12 -> V_77 ) < 0 ) {
F_51 ( L_26 ) ;
V_43 = - V_46 ;
goto exit;
}
if ( F_184 ( V_9 ,
& V_12 -> V_47 ) < 0 ) {
F_51 ( L_27 ) ;
V_43 = - V_46 ;
goto V_237;
}
return 0 ;
V_237:
F_162 ( V_12 -> V_77 ) ;
exit:
return V_43 ;
}
static int F_185 ( struct V_11 * V_12 ,
struct V_238 * V_239 , int V_240 )
{
struct V_191 * V_20 = V_12 -> V_30 -> V_49 ;
int V_43 ;
const char * V_241 ;
char * V_242 ;
T_11 V_243 ;
if ( V_240 ) {
V_243 = strlen ( V_20 -> V_212 ) + 10 ;
V_242 = F_186 ( V_243 , V_244 ) ;
if ( ! V_242 ) {
V_43 = - V_46 ;
V_241 = L_28 ;
goto error;
}
snprintf ( V_242 , V_243 , L_29 ,
V_20 -> V_212 , V_12 -> V_3 ) ;
} else {
V_242 = ( char * ) V_20 -> V_212 ;
}
V_43 = F_187 ( * V_239 , V_242 , L_30 , L_31 ,
V_12 -> V_210 ) ;
if ( V_43 ) {
V_241 = L_32 ;
goto error;
}
V_43 = F_187 ( * V_239 , V_242 , L_33 , L_31 ,
V_12 -> V_211 ) ;
if ( V_43 ) {
V_241 = L_34 ;
goto error;
}
if ( V_12 -> V_208 == V_12 -> V_209 ) {
V_43 = F_187 ( * V_239 , V_242 ,
L_35 , L_31 , V_12 -> V_208 ) ;
if ( V_43 ) {
V_241 = L_36 ;
goto error;
}
} else {
V_43 = F_187 ( * V_239 , V_242 ,
L_37 , L_31 , V_12 -> V_208 ) ;
if ( V_43 ) {
V_241 = L_38 ;
goto error;
}
V_43 = F_187 ( * V_239 , V_242 ,
L_39 , L_31 , V_12 -> V_209 ) ;
if ( V_43 ) {
V_241 = L_40 ;
goto error;
}
}
if ( V_240 )
F_169 ( V_242 ) ;
return 0 ;
error:
if ( V_240 )
F_169 ( V_242 ) ;
F_153 ( V_20 , V_43 , L_41 , V_241 ) ;
return V_43 ;
}
static void F_188 ( struct V_57 * V_30 )
{
unsigned int V_14 ;
F_189 () ;
for ( V_14 = 0 ; V_14 < V_30 -> V_31 -> V_60 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_61 [ V_14 ] ;
if ( F_18 ( V_30 -> V_31 ) )
F_91 ( & V_12 -> V_24 ) ;
F_190 ( & V_12 -> V_24 ) ;
}
F_191 () ;
F_169 ( V_30 -> V_61 ) ;
V_30 -> V_61 = NULL ;
}
static int F_192 ( struct V_57 * V_30 ,
unsigned int * V_59 )
{
unsigned int V_14 ;
int V_145 ;
V_30 -> V_61 = F_193 ( * V_59 , sizeof( struct V_11 ) ,
V_244 ) ;
if ( ! V_30 -> V_61 )
return - V_46 ;
F_189 () ;
for ( V_14 = 0 ; V_14 < * V_59 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_61 [ V_14 ] ;
V_12 -> V_3 = V_14 ;
V_12 -> V_30 = V_30 ;
V_145 = F_181 ( V_12 ) ;
if ( V_145 < 0 ) {
F_95 ( & V_30 -> V_31 -> V_20 ,
L_42 , V_14 ) ;
* V_59 = V_14 ;
break;
}
F_194 ( V_12 -> V_30 -> V_31 , & V_12 -> V_24 ,
F_112 , 64 ) ;
if ( F_18 ( V_30 -> V_31 ) )
F_42 ( & V_12 -> V_24 ) ;
}
F_195 ( V_30 -> V_31 , * V_59 ) ;
F_191 () ;
if ( * V_59 == 0 ) {
F_196 ( & V_30 -> V_31 -> V_20 , L_43 ) ;
return - V_138 ;
}
return 0 ;
}
static int F_197 ( struct V_191 * V_20 ,
struct V_57 * V_30 )
{
const char * V_241 ;
struct V_238 V_239 ;
int V_43 ;
unsigned int V_226 ;
unsigned int V_14 = 0 ;
unsigned int V_245 = 0 ;
struct V_11 * V_12 = NULL ;
unsigned int V_59 = 1 ;
V_30 -> V_31 -> V_188 = 0 ;
V_245 = F_134 ( V_30 -> V_49 -> V_184 ,
L_44 , 1 ) ;
V_59 = F_198 ( V_245 , V_192 ) ;
V_226 = F_134 ( V_30 -> V_49 -> V_184 ,
L_45 , 0 ) ;
V_43 = F_166 ( V_20 , V_30 -> V_31 -> V_246 ) ;
if ( V_43 ) {
F_153 ( V_20 , V_43 , L_46 , V_20 -> V_212 ) ;
goto V_247;
}
if ( V_30 -> V_61 )
F_188 ( V_30 ) ;
V_43 = F_192 ( V_30 , & V_59 ) ;
if ( V_43 < 0 ) {
F_153 ( V_20 , V_43 , L_47 ) ;
F_169 ( V_30 -> V_61 ) ;
V_30 -> V_61 = NULL ;
goto V_247;
}
for ( V_14 = 0 ; V_14 < V_59 ; ++ V_14 ) {
V_12 = & V_30 -> V_61 [ V_14 ] ;
V_43 = F_175 ( V_20 , V_12 , V_226 ) ;
if ( V_43 )
goto V_248;
}
V_249:
V_43 = F_199 ( & V_239 ) ;
if ( V_43 ) {
F_153 ( V_20 , V_43 , L_48 ) ;
goto V_248;
}
if ( F_200 ( V_217 ,
V_30 -> V_49 -> V_184 , L_44 ) ) {
V_43 = F_187 ( V_239 , V_20 -> V_212 ,
L_49 , L_31 , V_59 ) ;
if ( V_43 ) {
V_241 = L_50 ;
goto V_250;
}
}
if ( V_59 == 1 ) {
V_43 = F_185 ( & V_30 -> V_61 [ 0 ] , & V_239 , 0 ) ;
if ( V_43 )
goto V_250;
} else {
for ( V_14 = 0 ; V_14 < V_59 ; ++ V_14 ) {
V_12 = & V_30 -> V_61 [ V_14 ] ;
V_43 = F_185 ( V_12 , & V_239 , 1 ) ;
if ( V_43 )
goto V_250;
}
}
V_43 = F_187 ( V_239 , V_20 -> V_212 , L_51 , L_31 ,
1 ) ;
if ( V_43 ) {
V_241 = L_52 ;
goto V_251;
}
V_43 = F_187 ( V_239 , V_20 -> V_212 , L_53 , L_54 , 1 ) ;
if ( V_43 ) {
V_241 = L_55 ;
goto V_251;
}
V_43 = F_187 ( V_239 , V_20 -> V_212 , L_12 , L_54 , 1 ) ;
if ( V_43 ) {
V_241 = L_56 ;
goto V_251;
}
V_43 = F_187 ( V_239 , V_20 -> V_212 , L_14 , L_54 , 1 ) ;
if ( V_43 ) {
V_241 = L_57 ;
goto V_251;
}
V_43 = F_201 ( V_239 , V_20 -> V_212 , L_15 , L_58 ) ;
if ( V_43 ) {
V_241 = L_59 ;
goto V_251;
}
V_43 = F_201 ( V_239 , V_20 -> V_212 , L_13 ,
L_58 ) ;
if ( V_43 ) {
V_241 = L_60 ;
goto V_251;
}
V_43 = F_202 ( V_239 , 0 ) ;
if ( V_43 ) {
if ( V_43 == - V_252 )
goto V_249;
F_153 ( V_20 , V_43 , L_61 ) ;
goto V_248;
}
return 0 ;
V_251:
F_153 ( V_20 , V_43 , L_41 , V_241 ) ;
V_250:
F_202 ( V_239 , 1 ) ;
V_248:
F_158 ( V_30 ) ;
F_188 ( V_30 ) ;
V_247:
F_203 ( & V_20 -> V_20 ) ;
return V_43 ;
}
static int F_204 ( struct V_19 * V_20 )
{
struct V_57 * V_58 = F_41 ( V_20 ) ;
unsigned int V_59 = 0 ;
int V_43 ;
unsigned int V_253 = 0 ;
struct V_11 * V_12 = NULL ;
if ( ! F_134 ( V_58 -> V_49 -> V_184 , L_62 , 0 ) ) {
F_205 ( & V_20 -> V_20 ,
L_63 ) ;
return - V_254 ;
}
V_43 = F_197 ( V_58 -> V_49 , V_58 ) ;
if ( V_43 )
return V_43 ;
V_59 = V_20 -> V_60 ;
F_189 () ;
F_206 ( V_20 ) ;
F_191 () ;
F_207 ( V_58 -> V_31 ) ;
for ( V_253 = 0 ; V_253 < V_59 ; ++ V_253 ) {
V_12 = & V_58 -> V_61 [ V_253 ] ;
F_39 ( V_12 -> V_124 ) ;
if ( V_12 -> V_124 != V_12 -> V_56 )
F_39 ( V_12 -> V_56 ) ;
F_208 ( & V_12 -> V_107 ) ;
F_47 ( V_12 ) ;
F_209 ( & V_12 -> V_107 ) ;
F_43 ( & V_12 -> V_62 ) ;
F_26 ( V_12 ) ;
F_45 ( & V_12 -> V_62 ) ;
}
return 0 ;
}
static void F_210 ( struct V_191 * V_20 ,
enum V_255 V_256 )
{
struct V_57 * V_58 = F_164 ( & V_20 -> V_20 ) ;
struct V_19 * V_31 = V_58 -> V_31 ;
F_165 ( & V_20 -> V_20 , L_19 , F_211 ( V_256 ) ) ;
switch ( V_256 ) {
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
break;
case V_262 :
if ( V_20 -> V_263 != V_257 )
break;
if ( F_204 ( V_31 ) != 0 )
break;
F_212 ( V_20 , V_264 ) ;
break;
case V_264 :
F_213 ( V_31 ) ;
break;
case V_265 :
if ( V_20 -> V_263 == V_265 )
break;
case V_266 :
F_214 ( V_20 ) ;
break;
}
}
static int F_215 ( struct V_19 * V_20 , int V_267 )
{
switch ( V_267 ) {
case V_268 :
return F_216 ( V_269 ) ;
default:
return - V_138 ;
}
}
static void F_217 ( struct V_19 * V_20 ,
struct V_270 * V_129 , T_7 * V_23 )
{
void * V_58 = F_41 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_216 ( V_269 ) ; V_14 ++ )
V_23 [ V_14 ] = F_218 ( ( V_271 * ) ( V_58 + V_269 [ V_14 ] . V_81 ) ) ;
}
static void F_219 ( struct V_19 * V_20 , T_6 V_272 , T_10 * V_23 )
{
int V_14 ;
switch ( V_272 ) {
case V_268 :
for ( V_14 = 0 ; V_14 < F_216 ( V_269 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_273 ,
V_269 [ V_14 ] . V_219 , V_273 ) ;
break;
}
}
static T_12 F_220 ( struct V_135 * V_20 ,
struct V_274 * V_275 , char * V_276 )
{
return sprintf ( V_276 , L_64 , V_9 ) ;
}
static T_12 F_221 ( struct V_135 * V_20 ,
struct V_274 * V_275 ,
const char * V_276 , T_11 V_82 )
{
char * V_277 ;
unsigned long V_278 ;
if ( ! F_222 ( V_279 ) )
return - V_280 ;
V_278 = F_168 ( V_276 , & V_277 , 0 ) ;
if ( V_277 == V_276 )
return - V_281 ;
return V_82 ;
}
static int F_223 ( struct V_191 * V_20 )
{
struct V_57 * V_30 = F_164 ( & V_20 -> V_20 ) ;
F_165 ( & V_20 -> V_20 , L_19 , V_20 -> V_212 ) ;
F_158 ( V_30 ) ;
F_224 ( V_30 -> V_31 ) ;
if ( V_30 -> V_61 )
F_188 ( V_30 ) ;
F_141 ( V_30 -> V_31 ) ;
return 0 ;
}
static int T_13 F_225 ( void )
{
if ( ! F_226 () )
return - V_254 ;
if ( ! F_227 () )
return - V_254 ;
F_228 ( L_65 ) ;
if ( V_192 == 0 )
V_192 = F_229 (unsigned int, MAX_QUEUES_DEFAULT,
num_online_cpus()) ;
return F_230 ( & V_282 ) ;
}
static void T_14 F_231 ( void )
{
F_232 ( & V_282 ) ;
}
