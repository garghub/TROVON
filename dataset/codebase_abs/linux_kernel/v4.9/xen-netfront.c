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
F_30 ( F_31 ( ( unsigned long ) ( int ) V_16 ) ) ;
V_12 -> V_17 [ V_3 ] = V_16 ;
V_34 = F_32 ( & F_33 ( V_5 ) -> V_46 [ 0 ] ) ;
V_44 = F_34 ( & V_12 -> V_41 , V_40 ) ;
F_35 ( V_16 ,
V_12 -> V_30 -> V_47 -> V_48 ,
V_34 ,
0 ) ;
V_44 -> V_3 = V_3 ;
V_44 -> V_49 = V_16 ;
}
V_12 -> V_41 . V_26 = V_40 ;
if ( V_40 - V_12 -> V_41 . V_27 < V_50 ) {
F_36 ( & V_12 -> V_51 , V_52 + ( V_53 / 10 ) ) ;
return;
}
F_37 () ;
F_38 ( & V_12 -> V_41 , V_42 ) ;
if ( V_42 )
F_39 ( V_12 -> V_54 ) ;
}
static int F_40 ( struct V_19 * V_20 )
{
struct V_55 * V_56 = F_41 ( V_20 ) ;
unsigned int V_57 = V_20 -> V_58 ;
unsigned int V_14 = 0 ;
struct V_11 * V_12 = NULL ;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_56 -> V_59 [ V_14 ] ;
F_42 ( & V_12 -> V_24 ) ;
F_43 ( & V_12 -> V_60 ) ;
if ( F_27 ( V_20 ) ) {
F_26 ( V_12 ) ;
V_12 -> V_41 . V_61 -> V_62 = V_12 -> V_41 . V_27 + 1 ;
if ( F_44 ( & V_12 -> V_41 ) )
F_11 ( & V_12 -> V_24 ) ;
}
F_45 ( & V_12 -> V_60 ) ;
}
F_46 ( V_20 ) ;
return 0 ;
}
static void F_47 ( struct V_11 * V_12 )
{
T_1 V_63 , V_64 ;
unsigned short V_3 ;
struct V_10 * V_5 ;
bool V_65 ;
F_28 ( ! F_27 ( V_12 -> V_30 -> V_31 ) ) ;
do {
V_64 = V_12 -> V_25 . V_61 -> V_66 ;
F_48 () ;
for ( V_63 = V_12 -> V_25 . V_27 ; V_63 != V_64 ; V_63 ++ ) {
struct V_67 * V_68 ;
V_68 = F_49 ( & V_12 -> V_25 , V_63 ) ;
if ( V_68 -> V_69 == V_70 )
continue;
V_3 = V_68 -> V_3 ;
V_5 = V_12 -> V_71 [ V_3 ] . V_5 ;
if ( F_15 ( F_50 (
V_12 -> V_72 [ V_3 ] ) != 0 ) ) {
F_51 ( L_1 ,
V_73 ) ;
F_52 () ;
}
F_53 (
V_12 -> V_72 [ V_3 ] , V_74 ) ;
F_54 (
& V_12 -> V_75 , V_12 -> V_72 [ V_3 ] ) ;
V_12 -> V_72 [ V_3 ] = V_18 ;
V_12 -> V_76 [ V_3 ] = NULL ;
F_4 ( & V_12 -> V_77 , V_12 -> V_71 , V_3 ) ;
F_55 ( V_5 ) ;
}
V_12 -> V_25 . V_27 = V_64 ;
F_56 ( & V_12 -> V_25 , V_65 ) ;
} while ( V_65 );
F_13 ( V_12 ) ;
}
static void F_57 ( unsigned long V_78 , unsigned int V_79 ,
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
V_25 = F_34 ( & V_12 -> V_25 , V_12 -> V_25 . V_26 ++ ) ;
V_16 = F_29 ( & V_12 -> V_75 ) ;
F_30 ( F_31 ( ( unsigned long ) ( int ) V_16 ) ) ;
F_58 ( V_16 , V_12 -> V_30 -> V_47 -> V_48 ,
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
static struct V_82 * F_59 (
struct V_11 * V_12 , struct V_10 * V_5 ,
struct V_34 * V_34 , unsigned int V_79 , unsigned int V_80 )
{
struct V_81 V_30 = {
. V_12 = V_12 ,
. V_5 = V_5 ,
. V_34 = V_34 ,
. V_83 = 0 ,
} ;
F_60 ( V_34 , V_79 , V_80 , F_57 , & V_30 ) ;
return V_30 . V_25 ;
}
static void F_61 ( unsigned long V_78 , unsigned int V_79 ,
unsigned int V_80 , void * V_23 )
{
struct V_81 * V_30 = V_23 ;
V_30 -> V_25 -> V_84 |= V_85 ;
F_62 ( V_30 -> V_5 ) ;
F_57 ( V_78 , V_79 , V_80 , V_23 ) ;
}
static struct V_82 * F_63 (
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
F_64 ( V_34 , V_79 , V_80 ,
F_61 ,
& V_30 ) ;
V_34 ++ ;
V_79 = 0 ;
V_80 -= V_30 . V_83 ;
}
return V_30 . V_25 ;
}
static int F_65 ( struct V_10 * V_5 )
{
int V_14 , V_46 = F_33 ( V_5 ) -> V_88 ;
int V_89 ;
V_89 = F_66 ( F_67 ( V_5 -> V_23 ) ,
F_68 ( V_5 ) ) ;
for ( V_14 = 0 ; V_14 < V_46 ; V_14 ++ ) {
T_3 * V_90 = F_33 ( V_5 ) -> V_46 + V_14 ;
unsigned long V_83 = F_69 ( V_90 ) ;
unsigned long V_79 = V_90 -> V_91 ;
V_79 &= ~ V_87 ;
V_89 += F_66 ( V_79 , V_83 ) ;
}
return V_89 ;
}
static T_4 F_70 ( struct V_19 * V_20 , struct V_10 * V_5 ,
void * V_92 , T_5 V_93 )
{
unsigned int V_57 = V_20 -> V_58 ;
T_6 V_94 ;
T_4 V_95 ;
if ( V_57 == 1 ) {
V_95 = 0 ;
} else {
V_94 = F_71 ( V_5 ) ;
V_95 = V_94 % V_57 ;
}
return V_95 ;
}
static int F_72 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
struct V_55 * V_56 = F_41 ( V_20 ) ;
struct V_96 * V_97 = F_73 ( V_56 -> V_97 ) ;
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
struct V_10 * V_100 ;
if ( V_57 < 1 )
goto V_101;
V_99 = F_74 ( V_5 ) ;
V_12 = & V_56 -> V_59 [ V_99 ] ;
if ( F_15 ( V_5 -> V_80 > V_102 ) ) {
F_75 (
L_2 ,
V_5 -> V_80 ) ;
goto V_101;
}
V_89 = F_65 ( V_5 ) ;
if ( F_15 ( V_89 > V_103 + 1 ) ) {
F_76 ( L_3 ,
V_89 , V_5 -> V_80 ) ;
if ( F_77 ( V_5 ) )
goto V_101;
}
V_34 = F_78 ( V_5 -> V_23 ) ;
V_79 = F_67 ( V_5 -> V_23 ) ;
if ( F_15 ( V_39 - V_79 < V_104 ) ) {
V_100 = F_79 ( V_5 , V_37 ) ;
if ( ! V_100 )
goto V_101;
F_80 ( V_5 ) ;
V_5 = V_100 ;
V_34 = F_78 ( V_5 -> V_23 ) ;
V_79 = F_67 ( V_5 -> V_23 ) ;
}
V_80 = F_68 ( V_5 ) ;
F_81 ( & V_12 -> V_105 , V_84 ) ;
if ( F_15 ( ! F_27 ( V_20 ) ||
( V_89 > 1 && ! F_9 ( V_20 ) ) ||
F_82 ( V_5 , F_83 ( V_5 ) ) ) ) {
F_84 ( & V_12 -> V_105 , V_84 ) ;
goto V_101;
}
V_98 = V_25 = F_59 ( V_12 , V_5 ,
V_34 , V_79 , V_80 ) ;
V_79 += V_25 -> V_83 ;
if ( V_79 == V_39 ) {
V_34 ++ ;
V_79 = 0 ;
}
V_80 -= V_25 -> V_83 ;
if ( V_5 -> V_106 == V_107 )
V_25 -> V_84 |= V_108 | V_109 ;
else if ( V_5 -> V_106 == V_110 )
V_25 -> V_84 |= V_109 ;
if ( F_33 ( V_5 ) -> V_111 ) {
struct V_112 * V_113 ;
V_113 = (struct V_112 * )
F_34 ( & V_12 -> V_25 , V_12 -> V_25 . V_26 ++ ) ;
V_25 -> V_84 |= V_114 ;
V_113 -> V_115 . V_113 . V_83 = F_33 ( V_5 ) -> V_111 ;
V_113 -> V_115 . V_113 . type = ( F_33 ( V_5 ) -> V_116 & V_117 ) ?
V_118 :
V_119 ;
V_113 -> V_115 . V_113 . V_120 = 0 ;
V_113 -> V_115 . V_113 . V_21 = 0 ;
V_113 -> type = V_121 ;
V_113 -> V_84 = 0 ;
}
V_25 = F_63 ( V_12 , V_25 , V_5 , V_34 , V_79 , V_80 ) ;
for ( V_14 = 0 ; V_14 < F_33 ( V_5 ) -> V_88 ; V_14 ++ ) {
T_3 * V_90 = & F_33 ( V_5 ) -> V_46 [ V_14 ] ;
V_25 = F_63 ( V_12 , V_25 , V_5 ,
F_32 ( V_90 ) , V_90 -> V_91 ,
F_69 ( V_90 ) ) ;
}
V_98 -> V_83 = V_5 -> V_80 ;
F_38 ( & V_12 -> V_25 , V_42 ) ;
if ( V_42 )
F_39 ( V_12 -> V_122 ) ;
F_85 ( & V_97 -> V_123 ) ;
V_97 -> V_124 += V_5 -> V_80 ;
V_97 -> V_125 ++ ;
F_86 ( & V_97 -> V_123 ) ;
F_47 ( V_12 ) ;
if ( ! F_12 ( V_12 ) )
F_87 ( F_14 ( V_20 , V_12 -> V_3 ) ) ;
F_84 ( & V_12 -> V_105 , V_84 ) ;
return V_126 ;
V_101:
V_20 -> V_127 . V_128 ++ ;
F_80 ( V_5 ) ;
return V_126 ;
}
static int F_88 ( struct V_19 * V_20 )
{
struct V_55 * V_56 = F_41 ( V_20 ) ;
unsigned int V_57 = V_20 -> V_58 ;
unsigned int V_14 ;
struct V_11 * V_12 ;
F_89 ( V_56 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_56 -> V_59 [ V_14 ] ;
F_90 ( & V_12 -> V_24 ) ;
}
return 0 ;
}
static void F_91 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_129 = F_6 ( V_12 -> V_41 . V_26 ) ;
F_28 ( V_12 -> V_15 [ V_129 ] ) ;
V_12 -> V_15 [ V_129 ] = V_5 ;
V_12 -> V_17 [ V_129 ] = V_16 ;
F_34 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_3 = V_129 ;
F_34 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_49 = V_16 ;
V_12 -> V_41 . V_26 ++ ;
}
static int F_92 ( struct V_11 * V_12 ,
struct V_112 * V_130 ,
T_1 V_131 )
{
struct V_112 * V_132 ;
struct V_133 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
int V_134 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_63 + 1 == V_131 ) ) {
if ( F_93 () )
F_94 ( V_20 , L_4 ) ;
V_134 = - V_135 ;
break;
}
V_132 = (struct V_112 * )
F_49 ( & V_12 -> V_41 , ++ V_63 ) ;
if ( F_15 ( ! V_132 -> type ||
V_132 -> type >= V_136 ) ) {
if ( F_93 () )
F_94 ( V_20 , L_5 ,
V_132 -> type ) ;
V_134 = - V_137 ;
} else {
memcpy ( & V_130 [ V_132 -> type - 1 ] , V_132 ,
sizeof( * V_132 ) ) ;
}
V_5 = F_7 ( V_12 , V_63 ) ;
V_16 = F_8 ( V_12 , V_63 ) ;
F_91 ( V_12 , V_5 , V_16 ) ;
} while ( V_132 -> V_84 & V_138 );
V_12 -> V_41 . V_27 = V_63 ;
return V_134 ;
}
static int F_95 ( struct V_11 * V_12 ,
struct V_139 * V_140 , T_1 V_131 ,
struct V_141 * V_2 )
{
struct V_142 * V_41 = & V_140 -> V_41 ;
struct V_112 * V_130 = V_140 -> V_130 ;
struct V_133 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_63 ) ;
T_2 V_16 = F_8 ( V_12 , V_63 ) ;
int V_143 = V_29 + ( V_41 -> V_69 <= V_35 ) ;
int V_89 = 1 ;
int V_134 = 0 ;
unsigned long V_144 ;
if ( V_41 -> V_84 & V_145 ) {
V_134 = F_92 ( V_12 , V_130 , V_131 ) ;
V_63 = V_12 -> V_41 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_41 -> V_69 < 0 ||
V_41 -> V_79 + V_41 -> V_69 > V_146 ) ) {
if ( F_93 () )
F_94 ( V_20 , L_6 ,
V_41 -> V_79 , V_41 -> V_69 ) ;
F_91 ( V_12 , V_5 , V_16 ) ;
V_134 = - V_137 ;
goto V_147;
}
if ( V_16 == V_18 ) {
if ( F_93 () )
F_94 ( V_20 , L_7 ,
V_41 -> V_3 ) ;
V_134 = - V_137 ;
goto V_147;
}
V_144 = F_53 ( V_16 , 0 ) ;
F_28 ( ! V_144 ) ;
F_54 ( & V_12 -> V_45 , V_16 ) ;
F_96 ( V_2 , V_5 ) ;
V_147:
if ( ! ( V_41 -> V_84 & V_148 ) )
break;
if ( V_63 + V_89 == V_131 ) {
if ( F_93 () )
F_94 ( V_20 , L_8 ) ;
V_134 = - V_149 ;
break;
}
V_41 = F_49 ( & V_12 -> V_41 , V_63 + V_89 ) ;
V_5 = F_7 ( V_12 , V_63 + V_89 ) ;
V_16 = F_8 ( V_12 , V_63 + V_89 ) ;
V_89 ++ ;
}
if ( F_15 ( V_89 > V_143 ) ) {
if ( F_93 () )
F_94 ( V_20 , L_9 ) ;
V_134 = - V_150 ;
}
if ( F_15 ( V_134 ) )
V_12 -> V_41 . V_27 = V_63 + V_89 ;
return V_134 ;
}
static int F_97 ( struct V_10 * V_5 ,
struct V_112 * V_113 )
{
if ( ! V_113 -> V_115 . V_113 . V_83 ) {
if ( F_93 () )
F_98 ( L_10 ) ;
return - V_137 ;
}
if ( V_113 -> V_115 . V_113 . type != V_119 &&
V_113 -> V_115 . V_113 . type != V_118 ) {
if ( F_93 () )
F_98 ( L_11 , V_113 -> V_115 . V_113 . type ) ;
return - V_137 ;
}
F_33 ( V_5 ) -> V_111 = V_113 -> V_115 . V_113 . V_83 ;
F_33 ( V_5 ) -> V_116 =
( V_113 -> V_115 . V_113 . type == V_119 ) ?
V_151 :
V_117 ;
F_33 ( V_5 ) -> V_116 |= V_152 ;
F_33 ( V_5 ) -> V_153 = 0 ;
return 0 ;
}
static T_1 F_99 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_141 * V_2 )
{
struct V_154 * V_155 = F_33 ( V_5 ) ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
struct V_10 * V_100 ;
while ( ( V_100 = F_100 ( V_2 ) ) ) {
struct V_142 * V_41 =
F_49 ( & V_12 -> V_41 , ++ V_63 ) ;
T_3 * V_156 = & F_33 ( V_100 ) -> V_46 [ 0 ] ;
if ( V_155 -> V_88 == V_29 ) {
unsigned int V_157 = F_101 ( V_5 ) -> V_157 ;
F_28 ( V_157 <= F_68 ( V_5 ) ) ;
F_102 ( V_5 , V_157 - F_68 ( V_5 ) ) ;
}
F_28 ( V_155 -> V_88 >= V_29 ) ;
F_24 ( V_5 , V_155 -> V_88 , F_32 ( V_156 ) ,
V_41 -> V_79 , V_41 -> V_69 , V_39 ) ;
F_33 ( V_100 ) -> V_88 = 0 ;
F_23 ( V_100 ) ;
}
return V_63 ;
}
static int F_103 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
bool V_158 = false ;
if ( V_5 -> V_106 != V_107 && F_104 ( V_5 ) ) {
struct V_55 * V_56 = F_41 ( V_20 ) ;
F_105 ( & V_56 -> V_159 ) ;
V_5 -> V_106 = V_107 ;
V_158 = true ;
}
if ( V_5 -> V_106 != V_107 )
return 0 ;
return F_106 ( V_5 , V_158 ) ;
}
static int F_107 ( struct V_11 * V_12 ,
struct V_141 * V_160 )
{
struct V_96 * V_161 = F_73 ( V_12 -> V_30 -> V_161 ) ;
int V_162 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_100 ( V_160 ) ) != NULL ) {
int V_157 = F_101 ( V_5 ) -> V_157 ;
if ( V_157 > F_68 ( V_5 ) )
F_102 ( V_5 , V_157 - F_68 ( V_5 ) ) ;
V_5 -> V_163 = F_108 ( V_5 , V_12 -> V_30 -> V_31 ) ;
F_109 ( V_5 ) ;
if ( F_103 ( V_12 -> V_30 -> V_31 , V_5 ) ) {
F_23 ( V_5 ) ;
V_162 ++ ;
V_12 -> V_30 -> V_31 -> V_127 . V_164 ++ ;
continue;
}
F_85 ( & V_161 -> V_123 ) ;
V_161 -> V_125 ++ ;
V_161 -> V_124 += V_5 -> V_80 ;
F_86 ( & V_161 -> V_123 ) ;
F_110 ( & V_12 -> V_24 , V_5 ) ;
}
return V_162 ;
}
static int F_111 ( struct V_165 * V_24 , int V_166 )
{
struct V_11 * V_12 = F_112 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
struct V_10 * V_5 ;
struct V_139 V_140 ;
struct V_142 * V_41 = & V_140 . V_41 ;
struct V_112 * V_130 = V_140 . V_130 ;
T_1 V_14 , V_131 ;
int V_167 ;
struct V_141 V_160 ;
struct V_141 V_168 ;
struct V_141 V_169 ;
int V_134 ;
F_113 ( & V_12 -> V_60 ) ;
F_114 ( & V_160 ) ;
F_114 ( & V_168 ) ;
F_114 ( & V_169 ) ;
V_131 = V_12 -> V_41 . V_61 -> V_66 ;
F_48 () ;
V_14 = V_12 -> V_41 . V_27 ;
V_167 = 0 ;
while ( ( V_14 != V_131 ) && ( V_167 < V_166 ) ) {
memcpy ( V_41 , F_49 ( & V_12 -> V_41 , V_14 ) , sizeof( * V_41 ) ) ;
memset ( V_130 , 0 , sizeof( V_140 . V_130 ) ) ;
V_134 = F_95 ( V_12 , & V_140 , V_131 , & V_169 ) ;
if ( F_15 ( V_134 ) ) {
V_134:
while ( ( V_5 = F_100 ( & V_169 ) ) )
F_96 ( & V_168 , V_5 ) ;
V_20 -> V_127 . V_164 ++ ;
V_14 = V_12 -> V_41 . V_27 ;
continue;
}
V_5 = F_100 ( & V_169 ) ;
if ( V_130 [ V_121 - 1 ] . type ) {
struct V_112 * V_113 ;
V_113 = & V_130 [ V_121 - 1 ] ;
if ( F_15 ( F_97 ( V_5 , V_113 ) ) ) {
F_115 ( & V_169 , V_5 ) ;
V_12 -> V_41 . V_27 += F_116 ( & V_169 ) ;
goto V_134;
}
}
F_101 ( V_5 ) -> V_157 = V_41 -> V_69 ;
if ( F_101 ( V_5 ) -> V_157 > V_35 )
F_101 ( V_5 ) -> V_157 = V_35 ;
F_33 ( V_5 ) -> V_46 [ 0 ] . V_91 = V_41 -> V_79 ;
F_117 ( & F_33 ( V_5 ) -> V_46 [ 0 ] , V_41 -> V_69 ) ;
V_5 -> V_170 = V_41 -> V_69 ;
V_5 -> V_80 += V_41 -> V_69 ;
V_14 = F_99 ( V_12 , V_5 , & V_169 ) ;
if ( V_41 -> V_84 & V_171 )
V_5 -> V_106 = V_107 ;
else if ( V_41 -> V_84 & V_172 )
V_5 -> V_106 = V_110 ;
F_96 ( & V_160 , V_5 ) ;
V_12 -> V_41 . V_27 = ++ V_14 ;
V_167 ++ ;
}
F_118 ( & V_168 ) ;
V_167 -= F_107 ( V_12 , & V_160 ) ;
F_26 ( V_12 ) ;
if ( V_167 < V_166 ) {
int V_65 = 0 ;
F_119 ( V_24 ) ;
F_56 ( & V_12 -> V_41 , V_65 ) ;
if ( V_65 )
F_11 ( V_24 ) ;
}
F_120 ( & V_12 -> V_60 ) ;
return V_167 ;
}
static int F_121 ( struct V_19 * V_20 , int V_173 )
{
int V_143 = F_9 ( V_20 ) ? V_102 : V_174 ;
if ( V_173 > V_143 )
return - V_137 ;
V_20 -> V_173 = V_173 ;
return 0 ;
}
static struct V_175 * F_122 ( struct V_19 * V_20 ,
struct V_175 * V_176 )
{
struct V_55 * V_56 = F_41 ( V_20 ) ;
int V_177 ;
F_123 (cpu) {
struct V_96 * V_161 = F_124 ( V_56 -> V_161 , V_177 ) ;
struct V_96 * V_97 = F_124 ( V_56 -> V_97 , V_177 ) ;
T_7 V_178 , V_179 , V_180 , V_181 ;
unsigned int V_182 ;
do {
V_182 = F_125 ( & V_97 -> V_123 ) ;
V_180 = V_97 -> V_125 ;
V_181 = V_97 -> V_124 ;
} while ( F_126 ( & V_97 -> V_123 , V_182 ) );
do {
V_182 = F_125 ( & V_161 -> V_123 ) ;
V_178 = V_161 -> V_125 ;
V_179 = V_161 -> V_124 ;
} while ( F_126 ( & V_161 -> V_123 , V_182 ) );
V_176 -> V_178 += V_178 ;
V_176 -> V_180 += V_180 ;
V_176 -> V_179 += V_179 ;
V_176 -> V_181 += V_181 ;
}
V_176 -> V_164 = V_20 -> V_127 . V_164 ;
V_176 -> V_128 = V_20 -> V_127 . V_128 ;
return V_176 ;
}
static void F_127 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
if ( F_2 ( & V_12 -> V_71 [ V_14 ] ) )
continue;
V_5 = V_12 -> V_71 [ V_14 ] . V_5 ;
F_128 ( V_12 -> V_76 [ V_14 ] ) ;
F_129 ( V_12 -> V_72 [ V_14 ] ,
V_74 ,
( unsigned long ) F_130 ( V_12 -> V_76 [ V_14 ] ) ) ;
V_12 -> V_76 [ V_14 ] = NULL ;
V_12 -> V_72 [ V_14 ] = V_18 ;
F_4 ( & V_12 -> V_77 , V_12 -> V_71 , V_14 ) ;
F_55 ( V_5 ) ;
}
}
static void F_131 ( struct V_11 * V_12 )
{
int V_3 , V_16 ;
F_43 ( & V_12 -> V_60 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
struct V_10 * V_5 ;
struct V_34 * V_34 ;
V_5 = V_12 -> V_15 [ V_3 ] ;
if ( ! V_5 )
continue;
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 )
continue;
V_34 = F_32 ( & F_33 ( V_5 ) -> V_46 [ 0 ] ) ;
F_128 ( V_34 ) ;
F_129 ( V_16 , 0 ,
( unsigned long ) F_130 ( V_34 ) ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
F_23 ( V_5 ) ;
}
F_45 ( & V_12 -> V_60 ) ;
}
static T_8 F_132 ( struct V_19 * V_20 ,
T_8 V_21 )
{
struct V_55 * V_56 = F_41 ( V_20 ) ;
int V_183 ;
if ( V_21 & V_22 ) {
if ( F_133 ( V_184 , V_56 -> V_47 -> V_185 , L_12 ,
L_13 , & V_183 ) < 0 )
V_183 = 0 ;
if ( ! V_183 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_186 ) {
if ( F_133 ( V_184 , V_56 -> V_47 -> V_185 ,
L_14 , L_13 , & V_183 ) < 0 )
V_183 = 0 ;
if ( ! V_183 )
V_21 &= ~ V_186 ;
}
if ( V_21 & V_187 ) {
if ( F_133 ( V_184 , V_56 -> V_47 -> V_185 ,
L_15 , L_13 , & V_183 ) < 0 )
V_183 = 0 ;
if ( ! V_183 )
V_21 &= ~ V_187 ;
}
if ( V_21 & V_188 ) {
if ( F_133 ( V_184 , V_56 -> V_47 -> V_185 ,
L_16 , L_13 , & V_183 ) < 0 )
V_183 = 0 ;
if ( ! V_183 )
V_21 &= ~ V_188 ;
}
return V_21 ;
}
static int F_134 ( struct V_19 * V_20 ,
T_8 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_173 > V_174 ) {
F_135 ( V_20 , L_17 ) ;
V_20 -> V_173 = V_174 ;
}
return 0 ;
}
static T_9 F_136 ( int V_189 , void * V_190 )
{
struct V_11 * V_12 = V_190 ;
unsigned long V_84 ;
F_81 ( & V_12 -> V_105 , V_84 ) ;
F_47 ( V_12 ) ;
F_84 ( & V_12 -> V_105 , V_84 ) ;
return V_191 ;
}
static T_9 F_137 ( int V_189 , void * V_190 )
{
struct V_11 * V_12 = V_190 ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
if ( F_17 ( F_27 ( V_20 ) &&
F_44 ( & V_12 -> V_41 ) ) )
F_11 ( & V_12 -> V_24 ) ;
return V_191 ;
}
static T_9 F_138 ( int V_189 , void * V_190 )
{
F_136 ( V_189 , V_190 ) ;
F_137 ( V_189 , V_190 ) ;
return V_191 ;
}
static void F_139 ( struct V_19 * V_20 )
{
struct V_55 * V_30 = F_41 ( V_20 ) ;
unsigned int V_57 = V_20 -> V_58 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 )
F_138 ( 0 , & V_30 -> V_59 [ V_14 ] ) ;
}
static void F_140 ( struct V_19 * V_31 )
{
struct V_55 * V_56 = F_41 ( V_31 ) ;
F_141 ( V_56 -> V_161 ) ;
F_141 ( V_56 -> V_97 ) ;
F_142 ( V_31 ) ;
}
static struct V_19 * F_143 ( struct V_192 * V_20 )
{
int V_134 ;
struct V_19 * V_31 ;
struct V_55 * V_56 ;
V_31 = F_144 ( sizeof( struct V_55 ) , V_193 ) ;
if ( ! V_31 )
return F_145 ( - V_194 ) ;
V_56 = F_41 ( V_31 ) ;
V_56 -> V_47 = V_20 ;
V_56 -> V_59 = NULL ;
V_134 = - V_194 ;
V_56 -> V_161 = F_146 ( struct V_96 ) ;
if ( V_56 -> V_161 == NULL )
goto exit;
V_56 -> V_97 = F_146 ( struct V_96 ) ;
if ( V_56 -> V_97 == NULL )
goto exit;
V_31 -> V_195 = & V_196 ;
V_31 -> V_21 = V_197 | V_198 |
V_199 ;
V_31 -> V_200 = V_22 |
V_186 |
V_187 | V_188 ;
V_31 -> V_21 |= V_31 -> V_200 ;
V_31 -> V_201 = & V_202 ;
F_147 ( V_31 , & V_20 -> V_20 ) ;
V_56 -> V_31 = V_31 ;
F_148 ( V_31 ) ;
return V_31 ;
exit:
F_140 ( V_31 ) ;
return F_145 ( V_134 ) ;
}
static int F_149 ( struct V_192 * V_20 ,
const struct V_203 * V_3 )
{
int V_134 ;
struct V_19 * V_31 ;
struct V_55 * V_30 ;
V_31 = F_143 ( V_20 ) ;
if ( F_150 ( V_31 ) ) {
V_134 = F_151 ( V_31 ) ;
F_152 ( V_20 , V_134 , L_18 ) ;
return V_134 ;
}
V_30 = F_41 ( V_31 ) ;
F_153 ( & V_20 -> V_20 , V_30 ) ;
#ifdef F_154
V_30 -> V_31 -> V_204 [ 0 ] = & V_205 ;
#endif
V_134 = F_155 ( V_30 -> V_31 ) ;
if ( V_134 ) {
F_98 ( L_19 , V_73 , V_134 ) ;
goto V_206;
}
return 0 ;
V_206:
F_140 ( V_31 ) ;
F_153 ( & V_20 -> V_20 , NULL ) ;
return V_134 ;
}
static void F_156 ( int V_16 , void * V_34 )
{
if ( V_16 != V_18 )
F_129 ( V_16 , 0 , ( unsigned long ) V_34 ) ;
}
static void F_157 ( struct V_55 * V_30 )
{
unsigned int V_14 = 0 ;
unsigned int V_57 = V_30 -> V_31 -> V_58 ;
F_148 ( V_30 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_57 && V_30 -> V_59 ; ++ V_14 ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
if ( V_12 -> V_122 && ( V_12 -> V_122 == V_12 -> V_54 ) )
F_158 ( V_12 -> V_122 , V_12 ) ;
if ( V_12 -> V_122 && ( V_12 -> V_122 != V_12 -> V_54 ) ) {
F_158 ( V_12 -> V_122 , V_12 ) ;
F_158 ( V_12 -> V_54 , V_12 ) ;
}
V_12 -> V_207 = V_12 -> V_208 = 0 ;
V_12 -> V_122 = V_12 -> V_54 = 0 ;
if ( F_18 ( V_30 -> V_31 ) )
F_159 ( & V_12 -> V_24 ) ;
F_127 ( V_12 ) ;
F_131 ( V_12 ) ;
F_160 ( V_12 -> V_75 ) ;
F_160 ( V_12 -> V_45 ) ;
F_156 ( V_12 -> V_209 , V_12 -> V_25 . V_61 ) ;
F_156 ( V_12 -> V_210 , V_12 -> V_41 . V_61 ) ;
V_12 -> V_209 = V_18 ;
V_12 -> V_210 = V_18 ;
V_12 -> V_25 . V_61 = NULL ;
V_12 -> V_41 . V_61 = NULL ;
}
}
static int F_161 ( struct V_192 * V_20 )
{
struct V_55 * V_30 = F_162 ( & V_20 -> V_20 ) ;
F_163 ( & V_20 -> V_20 , L_20 , V_20 -> V_211 ) ;
F_157 ( V_30 ) ;
return 0 ;
}
static int F_164 ( struct V_192 * V_20 , T_10 V_212 [] )
{
char * V_213 , * V_214 , * V_215 ;
int V_14 ;
V_215 = V_213 = F_165 ( V_184 , V_20 -> V_211 , L_21 , NULL ) ;
if ( F_150 ( V_215 ) )
return F_151 ( V_215 ) ;
for ( V_14 = 0 ; V_14 < V_216 ; V_14 ++ ) {
V_212 [ V_14 ] = F_166 ( V_213 , & V_214 , 16 ) ;
if ( ( V_213 == V_214 ) || ( * V_214 != ( ( V_14 == V_216 - 1 ) ? '\0' : ':' ) ) ) {
F_167 ( V_215 ) ;
return - V_149 ;
}
V_213 = V_214 + 1 ;
}
F_167 ( V_215 ) ;
return 0 ;
}
static int F_168 ( struct V_11 * V_12 )
{
int V_134 ;
V_134 = F_169 ( V_12 -> V_30 -> V_47 , & V_12 -> V_207 ) ;
if ( V_134 < 0 )
goto V_206;
V_134 = F_170 ( V_12 -> V_207 ,
F_138 ,
0 , V_12 -> V_30 -> V_31 -> V_217 , V_12 ) ;
if ( V_134 < 0 )
goto V_218;
V_12 -> V_208 = V_12 -> V_207 ;
V_12 -> V_54 = V_12 -> V_122 = V_134 ;
return 0 ;
V_218:
F_171 ( V_12 -> V_30 -> V_47 , V_12 -> V_207 ) ;
V_12 -> V_207 = 0 ;
V_206:
return V_134 ;
}
static int F_172 ( struct V_11 * V_12 )
{
int V_134 ;
V_134 = F_169 ( V_12 -> V_30 -> V_47 , & V_12 -> V_207 ) ;
if ( V_134 < 0 )
goto V_206;
V_134 = F_169 ( V_12 -> V_30 -> V_47 , & V_12 -> V_208 ) ;
if ( V_134 < 0 )
goto V_219;
snprintf ( V_12 -> V_220 , sizeof( V_12 -> V_220 ) ,
L_22 , V_12 -> V_217 ) ;
V_134 = F_170 ( V_12 -> V_207 ,
F_136 ,
0 , V_12 -> V_220 , V_12 ) ;
if ( V_134 < 0 )
goto V_221;
V_12 -> V_122 = V_134 ;
snprintf ( V_12 -> V_222 , sizeof( V_12 -> V_222 ) ,
L_23 , V_12 -> V_217 ) ;
V_134 = F_170 ( V_12 -> V_208 ,
F_137 ,
0 , V_12 -> V_222 , V_12 ) ;
if ( V_134 < 0 )
goto V_223;
V_12 -> V_54 = V_134 ;
return 0 ;
V_223:
F_158 ( V_12 -> V_122 , V_12 ) ;
V_12 -> V_122 = 0 ;
V_221:
F_171 ( V_12 -> V_30 -> V_47 , V_12 -> V_208 ) ;
V_12 -> V_208 = 0 ;
V_219:
F_171 ( V_12 -> V_30 -> V_47 , V_12 -> V_207 ) ;
V_12 -> V_207 = 0 ;
V_206:
return V_134 ;
}
static int F_173 ( struct V_192 * V_20 ,
struct V_11 * V_12 , unsigned int V_224 )
{
struct V_225 * V_226 ;
struct V_227 * V_228 ;
T_2 V_49 ;
int V_134 ;
V_12 -> V_209 = V_18 ;
V_12 -> V_210 = V_18 ;
V_12 -> V_41 . V_61 = NULL ;
V_12 -> V_25 . V_61 = NULL ;
V_226 = (struct V_225 * ) F_174 ( V_229 | V_230 ) ;
if ( ! V_226 ) {
V_134 = - V_194 ;
F_152 ( V_20 , V_134 , L_24 ) ;
goto V_206;
}
F_175 ( V_226 ) ;
F_176 ( & V_12 -> V_25 , V_226 , V_146 ) ;
V_134 = F_177 ( V_20 , V_226 , 1 , & V_49 ) ;
if ( V_134 < 0 )
goto V_231;
V_12 -> V_209 = V_49 ;
V_228 = (struct V_227 * ) F_174 ( V_229 | V_230 ) ;
if ( ! V_228 ) {
V_134 = - V_194 ;
F_152 ( V_20 , V_134 , L_25 ) ;
goto V_232;
}
F_175 ( V_228 ) ;
F_176 ( & V_12 -> V_41 , V_228 , V_146 ) ;
V_134 = F_177 ( V_20 , V_228 , 1 , & V_49 ) ;
if ( V_134 < 0 )
goto V_233;
V_12 -> V_210 = V_49 ;
if ( V_224 )
V_134 = F_172 ( V_12 ) ;
if ( ! V_224 || ( V_224 && V_134 ) )
V_134 = F_168 ( V_12 ) ;
if ( V_134 )
goto V_234;
return 0 ;
V_234:
F_53 ( V_12 -> V_210 , 0 ) ;
V_233:
F_178 ( ( unsigned long ) V_228 ) ;
V_232:
F_53 ( V_12 -> V_209 , 0 ) ;
V_231:
F_178 ( ( unsigned long ) V_226 ) ;
V_206:
return V_134 ;
}
static int F_179 ( struct V_11 * V_12 )
{
unsigned short V_14 ;
int V_134 = 0 ;
F_180 ( & V_12 -> V_105 ) ;
F_180 ( & V_12 -> V_60 ) ;
F_181 ( & V_12 -> V_51 , F_10 ,
( unsigned long ) V_12 ) ;
snprintf ( V_12 -> V_217 , sizeof( V_12 -> V_217 ) , L_26 ,
V_12 -> V_30 -> V_31 -> V_217 , V_12 -> V_3 ) ;
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
if ( F_182 ( V_28 ,
& V_12 -> V_75 ) < 0 ) {
F_51 ( L_27 ) ;
V_134 = - V_194 ;
goto exit;
}
if ( F_182 ( V_9 ,
& V_12 -> V_45 ) < 0 ) {
F_51 ( L_28 ) ;
V_134 = - V_194 ;
goto V_235;
}
return 0 ;
V_235:
F_160 ( V_12 -> V_75 ) ;
exit:
return V_134 ;
}
static int F_183 ( struct V_11 * V_12 ,
struct V_236 * V_237 , int V_238 )
{
struct V_192 * V_20 = V_12 -> V_30 -> V_47 ;
int V_134 ;
const char * V_239 ;
char * V_240 ;
T_11 V_241 ;
if ( V_238 ) {
V_241 = strlen ( V_20 -> V_211 ) + 10 ;
V_240 = F_184 ( V_241 , V_242 ) ;
if ( ! V_240 ) {
V_134 = - V_194 ;
V_239 = L_29 ;
goto error;
}
snprintf ( V_240 , V_241 , L_30 ,
V_20 -> V_211 , V_12 -> V_3 ) ;
} else {
V_240 = ( char * ) V_20 -> V_211 ;
}
V_134 = F_185 ( * V_237 , V_240 , L_31 , L_32 ,
V_12 -> V_209 ) ;
if ( V_134 ) {
V_239 = L_33 ;
goto error;
}
V_134 = F_185 ( * V_237 , V_240 , L_34 , L_32 ,
V_12 -> V_210 ) ;
if ( V_134 ) {
V_239 = L_35 ;
goto error;
}
if ( V_12 -> V_207 == V_12 -> V_208 ) {
V_134 = F_185 ( * V_237 , V_240 ,
L_36 , L_32 , V_12 -> V_207 ) ;
if ( V_134 ) {
V_239 = L_37 ;
goto error;
}
} else {
V_134 = F_185 ( * V_237 , V_240 ,
L_38 , L_32 , V_12 -> V_207 ) ;
if ( V_134 ) {
V_239 = L_39 ;
goto error;
}
V_134 = F_185 ( * V_237 , V_240 ,
L_40 , L_32 , V_12 -> V_208 ) ;
if ( V_134 ) {
V_239 = L_41 ;
goto error;
}
}
if ( V_238 )
F_167 ( V_240 ) ;
return 0 ;
error:
if ( V_238 )
F_167 ( V_240 ) ;
F_152 ( V_20 , V_134 , L_42 , V_239 ) ;
return V_134 ;
}
static void F_186 ( struct V_55 * V_30 )
{
unsigned int V_14 ;
F_187 () ;
for ( V_14 = 0 ; V_14 < V_30 -> V_31 -> V_58 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
if ( F_18 ( V_30 -> V_31 ) )
F_90 ( & V_12 -> V_24 ) ;
F_188 ( & V_12 -> V_51 ) ;
F_189 ( & V_12 -> V_24 ) ;
}
F_190 () ;
F_167 ( V_30 -> V_59 ) ;
V_30 -> V_59 = NULL ;
}
static int F_191 ( struct V_55 * V_30 ,
unsigned int * V_57 )
{
unsigned int V_14 ;
int V_144 ;
V_30 -> V_59 = F_192 ( * V_57 , sizeof( struct V_11 ) ,
V_242 ) ;
if ( ! V_30 -> V_59 )
return - V_194 ;
F_187 () ;
for ( V_14 = 0 ; V_14 < * V_57 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
V_12 -> V_3 = V_14 ;
V_12 -> V_30 = V_30 ;
V_144 = F_179 ( V_12 ) ;
if ( V_144 < 0 ) {
F_94 ( & V_30 -> V_31 -> V_20 ,
L_43 , V_14 ) ;
* V_57 = V_14 ;
break;
}
F_193 ( V_12 -> V_30 -> V_31 , & V_12 -> V_24 ,
F_111 , 64 ) ;
if ( F_18 ( V_30 -> V_31 ) )
F_42 ( & V_12 -> V_24 ) ;
}
F_194 ( V_30 -> V_31 , * V_57 ) ;
F_190 () ;
if ( * V_57 == 0 ) {
F_195 ( & V_30 -> V_31 -> V_20 , L_44 ) ;
return - V_137 ;
}
return 0 ;
}
static int F_196 ( struct V_192 * V_20 ,
struct V_55 * V_30 )
{
const char * V_239 ;
struct V_236 V_237 ;
int V_134 ;
unsigned int V_224 ;
unsigned int V_14 = 0 ;
unsigned int V_243 = 0 ;
struct V_11 * V_12 = NULL ;
unsigned int V_57 = 1 ;
V_30 -> V_31 -> V_189 = 0 ;
V_134 = F_133 ( V_184 , V_30 -> V_47 -> V_185 ,
L_45 , L_32 , & V_243 ) ;
if ( V_134 < 0 )
V_243 = 1 ;
V_57 = F_197 ( V_243 , V_193 ) ;
V_134 = F_133 ( V_184 , V_30 -> V_47 -> V_185 ,
L_46 , L_32 ,
& V_224 ) ;
if ( V_134 < 0 )
V_224 = 0 ;
V_134 = F_164 ( V_20 , V_30 -> V_31 -> V_244 ) ;
if ( V_134 ) {
F_152 ( V_20 , V_134 , L_47 , V_20 -> V_211 ) ;
goto V_245;
}
if ( V_30 -> V_59 )
F_186 ( V_30 ) ;
V_134 = F_191 ( V_30 , & V_57 ) ;
if ( V_134 < 0 )
goto V_246;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_30 -> V_59 [ V_14 ] ;
V_134 = F_173 ( V_20 , V_12 , V_224 ) ;
if ( V_134 ) {
if ( V_14 > 0 ) {
F_187 () ;
F_194 ( V_30 -> V_31 , V_14 ) ;
F_190 () ;
goto V_246;
} else {
goto V_245;
}
}
}
V_247:
V_134 = F_198 ( & V_237 ) ;
if ( V_134 ) {
F_152 ( V_20 , V_134 , L_48 ) ;
goto V_246;
}
if ( F_199 ( V_184 ,
V_30 -> V_47 -> V_185 , L_45 ) ) {
V_134 = F_185 ( V_237 , V_20 -> V_211 ,
L_49 , L_32 , V_57 ) ;
if ( V_134 ) {
V_239 = L_50 ;
goto V_248;
}
}
if ( V_57 == 1 ) {
V_134 = F_183 ( & V_30 -> V_59 [ 0 ] , & V_237 , 0 ) ;
if ( V_134 )
goto V_248;
} else {
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_30 -> V_59 [ V_14 ] ;
V_134 = F_183 ( V_12 , & V_237 , 1 ) ;
if ( V_134 )
goto V_248;
}
}
V_134 = F_185 ( V_237 , V_20 -> V_211 , L_51 , L_32 ,
1 ) ;
if ( V_134 ) {
V_239 = L_52 ;
goto V_249;
}
V_134 = F_185 ( V_237 , V_20 -> V_211 , L_53 , L_13 , 1 ) ;
if ( V_134 ) {
V_239 = L_54 ;
goto V_249;
}
V_134 = F_185 ( V_237 , V_20 -> V_211 , L_12 , L_13 , 1 ) ;
if ( V_134 ) {
V_239 = L_55 ;
goto V_249;
}
V_134 = F_185 ( V_237 , V_20 -> V_211 , L_15 , L_13 , 1 ) ;
if ( V_134 ) {
V_239 = L_56 ;
goto V_249;
}
V_134 = F_200 ( V_237 , V_20 -> V_211 , L_16 , L_57 ) ;
if ( V_134 ) {
V_239 = L_58 ;
goto V_249;
}
V_134 = F_200 ( V_237 , V_20 -> V_211 , L_14 ,
L_57 ) ;
if ( V_134 ) {
V_239 = L_59 ;
goto V_249;
}
V_134 = F_201 ( V_237 , 0 ) ;
if ( V_134 ) {
if ( V_134 == - V_250 )
goto V_247;
F_152 ( V_20 , V_134 , L_60 ) ;
goto V_246;
}
return 0 ;
V_249:
F_152 ( V_20 , V_134 , L_42 , V_239 ) ;
V_248:
F_201 ( V_237 , 1 ) ;
V_246:
F_157 ( V_30 ) ;
F_167 ( V_30 -> V_59 ) ;
V_30 -> V_59 = NULL ;
V_245:
return V_134 ;
}
static int F_202 ( struct V_19 * V_20 )
{
struct V_55 * V_56 = F_41 ( V_20 ) ;
unsigned int V_57 = 0 ;
int V_134 ;
unsigned int V_251 ;
unsigned int V_252 = 0 ;
struct V_11 * V_12 = NULL ;
V_134 = F_133 ( V_184 , V_56 -> V_47 -> V_185 ,
L_61 , L_32 , & V_251 ) ;
if ( V_134 != 1 )
V_251 = 0 ;
if ( ! V_251 ) {
F_203 ( & V_20 -> V_20 ,
L_62 ) ;
return - V_253 ;
}
V_134 = F_196 ( V_56 -> V_47 , V_56 ) ;
if ( V_134 )
return V_134 ;
V_57 = V_20 -> V_58 ;
F_187 () ;
F_204 ( V_20 ) ;
F_190 () ;
F_205 ( V_56 -> V_31 ) ;
for ( V_252 = 0 ; V_252 < V_57 ; ++ V_252 ) {
V_12 = & V_56 -> V_59 [ V_252 ] ;
F_39 ( V_12 -> V_122 ) ;
if ( V_12 -> V_122 != V_12 -> V_54 )
F_39 ( V_12 -> V_54 ) ;
F_206 ( & V_12 -> V_105 ) ;
F_47 ( V_12 ) ;
F_207 ( & V_12 -> V_105 ) ;
F_43 ( & V_12 -> V_60 ) ;
F_26 ( V_12 ) ;
F_45 ( & V_12 -> V_60 ) ;
}
return 0 ;
}
static void F_208 ( struct V_192 * V_20 ,
enum V_254 V_255 )
{
struct V_55 * V_56 = F_162 ( & V_20 -> V_20 ) ;
struct V_19 * V_31 = V_56 -> V_31 ;
F_163 ( & V_20 -> V_20 , L_20 , F_209 ( V_255 ) ) ;
switch ( V_255 ) {
case V_256 :
case V_257 :
case V_258 :
case V_259 :
case V_260 :
break;
case V_261 :
if ( V_20 -> V_262 != V_256 )
break;
if ( F_202 ( V_31 ) != 0 )
break;
F_210 ( V_20 , V_263 ) ;
break;
case V_263 :
F_211 ( V_31 ) ;
break;
case V_264 :
if ( V_20 -> V_262 == V_264 )
break;
case V_265 :
F_212 ( V_20 ) ;
break;
}
}
static int F_213 ( struct V_19 * V_20 , int V_266 )
{
switch ( V_266 ) {
case V_267 :
return F_214 ( V_268 ) ;
default:
return - V_137 ;
}
}
static void F_215 ( struct V_19 * V_20 ,
struct V_269 * V_127 , T_7 * V_23 )
{
void * V_56 = F_41 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_214 ( V_268 ) ; V_14 ++ )
V_23 [ V_14 ] = F_216 ( ( V_270 * ) ( V_56 + V_268 [ V_14 ] . V_79 ) ) ;
}
static void F_217 ( struct V_19 * V_20 , T_6 V_271 , T_10 * V_23 )
{
int V_14 ;
switch ( V_271 ) {
case V_267 :
for ( V_14 = 0 ; V_14 < F_214 ( V_268 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_272 ,
V_268 [ V_14 ] . V_217 , V_272 ) ;
break;
}
}
static T_12 F_218 ( struct V_133 * V_20 ,
struct V_273 * V_274 , char * V_275 )
{
return sprintf ( V_275 , L_63 , V_9 ) ;
}
static T_12 F_219 ( struct V_133 * V_20 ,
struct V_273 * V_274 ,
const char * V_275 , T_11 V_80 )
{
char * V_276 ;
unsigned long V_277 ;
if ( ! F_220 ( V_278 ) )
return - V_279 ;
V_277 = F_166 ( V_275 , & V_276 , 0 ) ;
if ( V_276 == V_275 )
return - V_280 ;
return V_80 ;
}
static int F_221 ( struct V_192 * V_20 )
{
struct V_55 * V_30 = F_162 ( & V_20 -> V_20 ) ;
F_163 ( & V_20 -> V_20 , L_20 , V_20 -> V_211 ) ;
F_157 ( V_30 ) ;
F_222 ( V_30 -> V_31 ) ;
if ( V_30 -> V_59 )
F_186 ( V_30 ) ;
F_140 ( V_30 -> V_31 ) ;
return 0 ;
}
static int T_13 F_223 ( void )
{
if ( ! F_224 () )
return - V_253 ;
if ( ! F_225 () )
return - V_253 ;
F_226 ( L_64 ) ;
if ( V_193 == 0 )
V_193 = F_227 () ;
return F_228 ( & V_281 ) ;
}
static void T_14 F_229 ( void )
{
F_230 ( & V_281 ) ;
}
