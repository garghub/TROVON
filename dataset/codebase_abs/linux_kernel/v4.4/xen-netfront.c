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
F_28 ( ! F_27 ( V_12 -> V_30 -> V_31 ) ) ;
do {
V_64 = V_12 -> V_25 . V_61 -> V_65 ;
F_46 () ;
for ( V_63 = V_12 -> V_25 . V_27 ; V_63 != V_64 ; V_63 ++ ) {
struct V_66 * V_67 ;
V_67 = F_47 ( & V_12 -> V_25 , V_63 ) ;
if ( V_67 -> V_68 == V_69 )
continue;
V_3 = V_67 -> V_3 ;
V_5 = V_12 -> V_70 [ V_3 ] . V_5 ;
if ( F_15 ( F_48 (
V_12 -> V_71 [ V_3 ] ) != 0 ) ) {
F_49 ( L_1 ,
V_72 ) ;
F_50 () ;
}
F_51 (
V_12 -> V_71 [ V_3 ] , V_73 ) ;
F_52 (
& V_12 -> V_74 , V_12 -> V_71 [ V_3 ] ) ;
V_12 -> V_71 [ V_3 ] = V_18 ;
V_12 -> V_75 [ V_3 ] = NULL ;
F_4 ( & V_12 -> V_76 , V_12 -> V_70 , V_3 ) ;
F_53 ( V_5 ) ;
}
V_12 -> V_25 . V_27 = V_64 ;
V_12 -> V_25 . V_61 -> V_62 =
V_64 + ( ( V_12 -> V_25 . V_61 -> V_40 - V_64 ) >> 1 ) + 1 ;
F_54 () ;
} while ( ( V_63 == V_64 ) && ( V_64 != V_12 -> V_25 . V_61 -> V_65 ) );
F_13 ( V_12 ) ;
}
static void F_55 ( unsigned long V_77 , unsigned int V_78 ,
unsigned int V_79 , void * V_23 )
{
struct V_80 * V_30 = V_23 ;
unsigned int V_3 ;
struct V_81 * V_25 ;
T_2 V_16 ;
struct V_34 * V_34 = V_30 -> V_34 ;
struct V_11 * V_12 = V_30 -> V_12 ;
struct V_10 * V_5 = V_30 -> V_5 ;
V_3 = F_5 ( & V_12 -> V_76 , V_12 -> V_70 ) ;
V_25 = F_32 ( & V_12 -> V_25 , V_12 -> V_25 . V_26 ++ ) ;
V_16 = F_29 ( & V_12 -> V_74 ) ;
F_28 ( ( signed short ) V_16 < 0 ) ;
F_56 ( V_16 , V_12 -> V_30 -> V_47 -> V_48 ,
V_77 , V_73 ) ;
V_12 -> V_70 [ V_3 ] . V_5 = V_5 ;
V_12 -> V_75 [ V_3 ] = V_34 ;
V_12 -> V_71 [ V_3 ] = V_16 ;
V_25 -> V_3 = V_3 ;
V_25 -> V_49 = V_16 ;
V_25 -> V_78 = V_78 ;
V_25 -> V_82 = V_79 ;
V_25 -> V_83 = 0 ;
V_30 -> V_25 = V_25 ;
V_30 -> V_82 += V_25 -> V_82 ;
}
static struct V_81 * F_57 (
struct V_11 * V_12 , struct V_10 * V_5 ,
struct V_34 * V_34 , unsigned int V_78 , unsigned int V_79 )
{
struct V_80 V_30 = {
. V_12 = V_12 ,
. V_5 = V_5 ,
. V_34 = V_34 ,
. V_82 = 0 ,
} ;
F_58 ( V_34 , V_78 , V_79 , F_55 , & V_30 ) ;
return V_30 . V_25 ;
}
static void F_59 ( unsigned long V_77 , unsigned int V_78 ,
unsigned int V_79 , void * V_23 )
{
struct V_80 * V_30 = V_23 ;
V_30 -> V_25 -> V_83 |= V_84 ;
F_60 ( V_30 -> V_5 ) ;
F_55 ( V_77 , V_78 , V_79 , V_23 ) ;
}
static struct V_81 * F_61 (
struct V_11 * V_12 , struct V_81 * V_25 ,
struct V_10 * V_5 , struct V_34 * V_34 ,
unsigned int V_78 , unsigned int V_79 )
{
struct V_80 V_30 = {
. V_12 = V_12 ,
. V_5 = V_5 ,
. V_25 = V_25 ,
} ;
V_34 += V_78 >> V_85 ;
V_78 &= ~ V_86 ;
while ( V_79 ) {
V_30 . V_34 = V_34 ;
V_30 . V_82 = 0 ;
F_62 ( V_34 , V_78 , V_79 ,
F_59 ,
& V_30 ) ;
V_34 ++ ;
V_78 = 0 ;
V_79 -= V_30 . V_82 ;
}
return V_30 . V_25 ;
}
static int F_63 ( struct V_10 * V_5 )
{
int V_14 , V_46 = F_31 ( V_5 ) -> V_87 ;
int V_88 ;
V_88 = F_64 ( F_65 ( V_5 -> V_23 ) ,
F_66 ( V_5 ) ) ;
for ( V_14 = 0 ; V_14 < V_46 ; V_14 ++ ) {
T_3 * V_89 = F_31 ( V_5 ) -> V_46 + V_14 ;
unsigned long V_82 = F_67 ( V_89 ) ;
unsigned long V_78 = V_89 -> V_90 ;
V_78 &= ~ V_86 ;
V_88 += F_64 ( V_78 , V_82 ) ;
}
return V_88 ;
}
static T_4 F_68 ( struct V_19 * V_20 , struct V_10 * V_5 ,
void * V_91 , T_5 V_92 )
{
unsigned int V_57 = V_20 -> V_58 ;
T_6 V_93 ;
T_4 V_94 ;
if ( V_57 == 1 ) {
V_94 = 0 ;
} else {
V_93 = F_69 ( V_5 ) ;
V_94 = V_93 % V_57 ;
}
return V_94 ;
}
static int F_70 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
struct V_95 * V_96 = F_71 ( V_56 -> V_96 ) ;
struct V_81 * V_25 , * V_97 ;
unsigned int V_14 ;
int V_42 ;
int V_88 ;
struct V_34 * V_34 ;
unsigned int V_78 ;
unsigned int V_79 ;
unsigned long V_83 ;
struct V_11 * V_12 = NULL ;
unsigned int V_57 = V_20 -> V_58 ;
T_4 V_98 ;
if ( V_57 < 1 )
goto V_99;
V_98 = F_72 ( V_5 ) ;
V_12 = & V_56 -> V_59 [ V_98 ] ;
if ( F_15 ( V_5 -> V_79 > V_100 ) ) {
F_73 (
L_2 ,
V_5 -> V_79 ) ;
goto V_99;
}
V_88 = F_63 ( V_5 ) ;
if ( F_15 ( V_88 > V_101 + 1 ) ) {
F_74 ( L_3 ,
V_88 , V_5 -> V_79 ) ;
if ( F_75 ( V_5 ) )
goto V_99;
}
V_34 = F_76 ( V_5 -> V_23 ) ;
V_78 = F_65 ( V_5 -> V_23 ) ;
V_79 = F_66 ( V_5 ) ;
F_77 ( & V_12 -> V_102 , V_83 ) ;
if ( F_15 ( ! F_27 ( V_20 ) ||
( V_88 > 1 && ! F_9 ( V_20 ) ) ||
F_78 ( V_5 , F_79 ( V_5 ) ) ) ) {
F_80 ( & V_12 -> V_102 , V_83 ) ;
goto V_99;
}
V_97 = V_25 = F_57 ( V_12 , V_5 ,
V_34 , V_78 , V_79 ) ;
V_78 += V_25 -> V_82 ;
if ( V_78 == V_39 ) {
V_34 ++ ;
V_78 = 0 ;
}
V_79 -= V_25 -> V_82 ;
if ( V_5 -> V_103 == V_104 )
V_25 -> V_83 |= V_105 | V_106 ;
else if ( V_5 -> V_103 == V_107 )
V_25 -> V_83 |= V_106 ;
if ( F_31 ( V_5 ) -> V_108 ) {
struct V_109 * V_110 ;
V_110 = (struct V_109 * )
F_32 ( & V_12 -> V_25 , V_12 -> V_25 . V_26 ++ ) ;
V_25 -> V_83 |= V_111 ;
V_110 -> V_112 . V_110 . V_82 = F_31 ( V_5 ) -> V_108 ;
V_110 -> V_112 . V_110 . type = ( F_31 ( V_5 ) -> V_113 & V_114 ) ?
V_115 :
V_116 ;
V_110 -> V_112 . V_110 . V_117 = 0 ;
V_110 -> V_112 . V_110 . V_21 = 0 ;
V_110 -> type = V_118 ;
V_110 -> V_83 = 0 ;
}
V_25 = F_61 ( V_12 , V_25 , V_5 , V_34 , V_78 , V_79 ) ;
for ( V_14 = 0 ; V_14 < F_31 ( V_5 ) -> V_87 ; V_14 ++ ) {
T_3 * V_89 = & F_31 ( V_5 ) -> V_46 [ V_14 ] ;
V_25 = F_61 ( V_12 , V_25 , V_5 ,
F_30 ( V_89 ) , V_89 -> V_90 ,
F_67 ( V_89 ) ) ;
}
V_97 -> V_82 = V_5 -> V_79 ;
F_36 ( & V_12 -> V_25 , V_42 ) ;
if ( V_42 )
F_37 ( V_12 -> V_119 ) ;
F_81 ( & V_96 -> V_120 ) ;
V_96 -> V_121 += V_5 -> V_79 ;
V_96 -> V_122 ++ ;
F_82 ( & V_96 -> V_120 ) ;
F_45 ( V_12 ) ;
if ( ! F_12 ( V_12 ) )
F_83 ( F_14 ( V_20 , V_12 -> V_3 ) ) ;
F_80 ( & V_12 -> V_102 , V_83 ) ;
return V_123 ;
V_99:
V_20 -> V_124 . V_125 ++ ;
F_84 ( V_5 ) ;
return V_123 ;
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
int V_126 = F_6 ( V_12 -> V_41 . V_26 ) ;
F_28 ( V_12 -> V_15 [ V_126 ] ) ;
V_12 -> V_15 [ V_126 ] = V_5 ;
V_12 -> V_17 [ V_126 ] = V_16 ;
F_32 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_3 = V_126 ;
F_32 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_49 = V_16 ;
V_12 -> V_41 . V_26 ++ ;
}
static int F_89 ( struct V_11 * V_12 ,
struct V_109 * V_127 ,
T_1 V_128 )
{
struct V_109 * V_129 ;
struct V_130 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
int V_131 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_63 + 1 == V_128 ) ) {
if ( F_90 () )
F_91 ( V_20 , L_4 ) ;
V_131 = - V_132 ;
break;
}
V_129 = (struct V_109 * )
F_47 ( & V_12 -> V_41 , ++ V_63 ) ;
if ( F_15 ( ! V_129 -> type ||
V_129 -> type >= V_133 ) ) {
if ( F_90 () )
F_91 ( V_20 , L_5 ,
V_129 -> type ) ;
V_131 = - V_134 ;
} else {
memcpy ( & V_127 [ V_129 -> type - 1 ] , V_129 ,
sizeof( * V_129 ) ) ;
}
V_5 = F_7 ( V_12 , V_63 ) ;
V_16 = F_8 ( V_12 , V_63 ) ;
F_88 ( V_12 , V_5 , V_16 ) ;
} while ( V_129 -> V_83 & V_135 );
V_12 -> V_41 . V_27 = V_63 ;
return V_131 ;
}
static int F_92 ( struct V_11 * V_12 ,
struct V_136 * V_137 , T_1 V_128 ,
struct V_138 * V_2 )
{
struct V_139 * V_41 = & V_137 -> V_41 ;
struct V_109 * V_127 = V_137 -> V_127 ;
struct V_130 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_63 ) ;
T_2 V_16 = F_8 ( V_12 , V_63 ) ;
int V_140 = V_29 + ( V_41 -> V_68 <= V_35 ) ;
int V_88 = 1 ;
int V_131 = 0 ;
unsigned long V_141 ;
if ( V_41 -> V_83 & V_142 ) {
V_131 = F_89 ( V_12 , V_127 , V_128 ) ;
V_63 = V_12 -> V_41 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_41 -> V_68 < 0 ||
V_41 -> V_78 + V_41 -> V_68 > V_143 ) ) {
if ( F_90 () )
F_91 ( V_20 , L_6 ,
V_41 -> V_78 , V_41 -> V_68 ) ;
F_88 ( V_12 , V_5 , V_16 ) ;
V_131 = - V_134 ;
goto V_144;
}
if ( V_16 == V_18 ) {
if ( F_90 () )
F_91 ( V_20 , L_7 ,
V_41 -> V_3 ) ;
V_131 = - V_134 ;
goto V_144;
}
V_141 = F_51 ( V_16 , 0 ) ;
F_28 ( ! V_141 ) ;
F_52 ( & V_12 -> V_45 , V_16 ) ;
F_93 ( V_2 , V_5 ) ;
V_144:
if ( ! ( V_41 -> V_83 & V_145 ) )
break;
if ( V_63 + V_88 == V_128 ) {
if ( F_90 () )
F_91 ( V_20 , L_8 ) ;
V_131 = - V_146 ;
break;
}
V_41 = F_47 ( & V_12 -> V_41 , V_63 + V_88 ) ;
V_5 = F_7 ( V_12 , V_63 + V_88 ) ;
V_16 = F_8 ( V_12 , V_63 + V_88 ) ;
V_88 ++ ;
}
if ( F_15 ( V_88 > V_140 ) ) {
if ( F_90 () )
F_91 ( V_20 , L_9 ) ;
V_131 = - V_147 ;
}
if ( F_15 ( V_131 ) )
V_12 -> V_41 . V_27 = V_63 + V_88 ;
return V_131 ;
}
static int F_94 ( struct V_10 * V_5 ,
struct V_109 * V_110 )
{
if ( ! V_110 -> V_112 . V_110 . V_82 ) {
if ( F_90 () )
F_95 ( L_10 ) ;
return - V_134 ;
}
if ( V_110 -> V_112 . V_110 . type != V_116 &&
V_110 -> V_112 . V_110 . type != V_115 ) {
if ( F_90 () )
F_95 ( L_11 , V_110 -> V_112 . V_110 . type ) ;
return - V_134 ;
}
F_31 ( V_5 ) -> V_108 = V_110 -> V_112 . V_110 . V_82 ;
F_31 ( V_5 ) -> V_113 =
( V_110 -> V_112 . V_110 . type == V_116 ) ?
V_148 :
V_114 ;
F_31 ( V_5 ) -> V_113 |= V_149 ;
F_31 ( V_5 ) -> V_150 = 0 ;
return 0 ;
}
static T_1 F_96 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_138 * V_2 )
{
struct V_151 * V_152 = F_31 ( V_5 ) ;
T_1 V_63 = V_12 -> V_41 . V_27 ;
struct V_10 * V_153 ;
while ( ( V_153 = F_97 ( V_2 ) ) ) {
struct V_139 * V_41 =
F_47 ( & V_12 -> V_41 , ++ V_63 ) ;
T_3 * V_154 = & F_31 ( V_153 ) -> V_46 [ 0 ] ;
if ( V_152 -> V_87 == V_29 ) {
unsigned int V_155 = F_98 ( V_5 ) -> V_155 ;
F_28 ( V_155 <= F_66 ( V_5 ) ) ;
F_99 ( V_5 , V_155 - F_66 ( V_5 ) ) ;
}
F_28 ( V_152 -> V_87 >= V_29 ) ;
F_24 ( V_5 , V_152 -> V_87 , F_30 ( V_154 ) ,
V_41 -> V_78 , V_41 -> V_68 , V_39 ) ;
F_31 ( V_153 ) -> V_87 = 0 ;
F_23 ( V_153 ) ;
}
return V_63 ;
}
static int F_100 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
bool V_156 = false ;
if ( V_5 -> V_103 != V_104 && F_101 ( V_5 ) ) {
struct V_55 * V_56 = F_39 ( V_20 ) ;
F_102 ( & V_56 -> V_157 ) ;
V_5 -> V_103 = V_104 ;
V_156 = true ;
}
if ( V_5 -> V_103 != V_104 )
return 0 ;
return F_103 ( V_5 , V_156 ) ;
}
static int F_104 ( struct V_11 * V_12 ,
struct V_138 * V_158 )
{
struct V_95 * V_159 = F_71 ( V_12 -> V_30 -> V_159 ) ;
int V_160 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_97 ( V_158 ) ) != NULL ) {
int V_155 = F_98 ( V_5 ) -> V_155 ;
if ( V_155 > F_66 ( V_5 ) )
F_99 ( V_5 , V_155 - F_66 ( V_5 ) ) ;
V_5 -> V_161 = F_105 ( V_5 , V_12 -> V_30 -> V_31 ) ;
F_106 ( V_5 ) ;
if ( F_100 ( V_12 -> V_30 -> V_31 , V_5 ) ) {
F_23 ( V_5 ) ;
V_160 ++ ;
V_12 -> V_30 -> V_31 -> V_124 . V_162 ++ ;
continue;
}
F_81 ( & V_159 -> V_120 ) ;
V_159 -> V_122 ++ ;
V_159 -> V_121 += V_5 -> V_79 ;
F_82 ( & V_159 -> V_120 ) ;
F_107 ( & V_12 -> V_24 , V_5 ) ;
}
return V_160 ;
}
static int F_108 ( struct V_163 * V_24 , int V_164 )
{
struct V_11 * V_12 = F_109 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
struct V_10 * V_5 ;
struct V_136 V_137 ;
struct V_139 * V_41 = & V_137 . V_41 ;
struct V_109 * V_127 = V_137 . V_127 ;
T_1 V_14 , V_128 ;
int V_165 ;
struct V_138 V_158 ;
struct V_138 V_166 ;
struct V_138 V_167 ;
int V_131 ;
F_110 ( & V_12 -> V_60 ) ;
F_111 ( & V_158 ) ;
F_111 ( & V_166 ) ;
F_111 ( & V_167 ) ;
V_128 = V_12 -> V_41 . V_61 -> V_65 ;
F_46 () ;
V_14 = V_12 -> V_41 . V_27 ;
V_165 = 0 ;
while ( ( V_14 != V_128 ) && ( V_165 < V_164 ) ) {
memcpy ( V_41 , F_47 ( & V_12 -> V_41 , V_14 ) , sizeof( * V_41 ) ) ;
memset ( V_127 , 0 , sizeof( V_137 . V_127 ) ) ;
V_131 = F_92 ( V_12 , & V_137 , V_128 , & V_167 ) ;
if ( F_15 ( V_131 ) ) {
V_131:
while ( ( V_5 = F_97 ( & V_167 ) ) )
F_93 ( & V_166 , V_5 ) ;
V_20 -> V_124 . V_162 ++ ;
V_14 = V_12 -> V_41 . V_27 ;
continue;
}
V_5 = F_97 ( & V_167 ) ;
if ( V_127 [ V_118 - 1 ] . type ) {
struct V_109 * V_110 ;
V_110 = & V_127 [ V_118 - 1 ] ;
if ( F_15 ( F_94 ( V_5 , V_110 ) ) ) {
F_112 ( & V_167 , V_5 ) ;
V_12 -> V_41 . V_27 += F_113 ( & V_167 ) ;
goto V_131;
}
}
F_98 ( V_5 ) -> V_155 = V_41 -> V_68 ;
if ( F_98 ( V_5 ) -> V_155 > V_35 )
F_98 ( V_5 ) -> V_155 = V_35 ;
F_31 ( V_5 ) -> V_46 [ 0 ] . V_90 = V_41 -> V_78 ;
F_114 ( & F_31 ( V_5 ) -> V_46 [ 0 ] , V_41 -> V_68 ) ;
V_5 -> V_168 = V_41 -> V_68 ;
V_5 -> V_79 += V_41 -> V_68 ;
V_14 = F_96 ( V_12 , V_5 , & V_167 ) ;
if ( V_41 -> V_83 & V_169 )
V_5 -> V_103 = V_104 ;
else if ( V_41 -> V_83 & V_170 )
V_5 -> V_103 = V_107 ;
F_93 ( & V_158 , V_5 ) ;
V_12 -> V_41 . V_27 = ++ V_14 ;
V_165 ++ ;
}
F_115 ( & V_166 ) ;
V_165 -= F_104 ( V_12 , & V_158 ) ;
F_26 ( V_12 ) ;
if ( V_165 < V_164 ) {
int V_171 = 0 ;
F_116 ( V_24 ) ;
F_117 ( & V_12 -> V_41 , V_171 ) ;
if ( V_171 )
F_11 ( V_24 ) ;
}
F_118 ( & V_12 -> V_60 ) ;
return V_165 ;
}
static int F_119 ( struct V_19 * V_20 , int V_172 )
{
int V_140 = F_9 ( V_20 ) ? V_100 : V_173 ;
if ( V_172 > V_140 )
return - V_134 ;
V_20 -> V_172 = V_172 ;
return 0 ;
}
static struct V_174 * F_120 ( struct V_19 * V_20 ,
struct V_174 * V_175 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
int V_176 ;
F_121 (cpu) {
struct V_95 * V_159 = F_122 ( V_56 -> V_159 , V_176 ) ;
struct V_95 * V_96 = F_122 ( V_56 -> V_96 , V_176 ) ;
T_7 V_177 , V_178 , V_179 , V_180 ;
unsigned int V_181 ;
do {
V_181 = F_123 ( & V_96 -> V_120 ) ;
V_179 = V_96 -> V_122 ;
V_180 = V_96 -> V_121 ;
} while ( F_124 ( & V_96 -> V_120 , V_181 ) );
do {
V_181 = F_123 ( & V_159 -> V_120 ) ;
V_177 = V_159 -> V_122 ;
V_178 = V_159 -> V_121 ;
} while ( F_124 ( & V_159 -> V_120 , V_181 ) );
V_175 -> V_177 += V_177 ;
V_175 -> V_179 += V_179 ;
V_175 -> V_178 += V_178 ;
V_175 -> V_180 += V_180 ;
}
V_175 -> V_162 = V_20 -> V_124 . V_162 ;
V_175 -> V_125 = V_20 -> V_124 . V_125 ;
return V_175 ;
}
static void F_125 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
if ( F_2 ( & V_12 -> V_70 [ V_14 ] ) )
continue;
V_5 = V_12 -> V_70 [ V_14 ] . V_5 ;
F_126 ( V_12 -> V_75 [ V_14 ] ) ;
F_127 ( V_12 -> V_71 [ V_14 ] ,
V_73 ,
( unsigned long ) F_128 ( V_12 -> V_75 [ V_14 ] ) ) ;
V_12 -> V_75 [ V_14 ] = NULL ;
V_12 -> V_71 [ V_14 ] = V_18 ;
F_4 ( & V_12 -> V_76 , V_12 -> V_70 , V_14 ) ;
F_53 ( V_5 ) ;
}
}
static void F_129 ( struct V_11 * V_12 )
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
F_126 ( V_34 ) ;
F_127 ( V_16 , 0 ,
( unsigned long ) F_128 ( V_34 ) ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
F_23 ( V_5 ) ;
}
F_43 ( & V_12 -> V_60 ) ;
}
static T_8 F_130 ( struct V_19 * V_20 ,
T_8 V_21 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
int V_182 ;
if ( V_21 & V_22 ) {
if ( F_131 ( V_183 , V_56 -> V_47 -> V_184 , L_12 ,
L_13 , & V_182 ) < 0 )
V_182 = 0 ;
if ( ! V_182 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_185 ) {
if ( F_131 ( V_183 , V_56 -> V_47 -> V_184 ,
L_14 , L_13 , & V_182 ) < 0 )
V_182 = 0 ;
if ( ! V_182 )
V_21 &= ~ V_185 ;
}
if ( V_21 & V_186 ) {
if ( F_131 ( V_183 , V_56 -> V_47 -> V_184 ,
L_15 , L_13 , & V_182 ) < 0 )
V_182 = 0 ;
if ( ! V_182 )
V_21 &= ~ V_186 ;
}
if ( V_21 & V_187 ) {
if ( F_131 ( V_183 , V_56 -> V_47 -> V_184 ,
L_16 , L_13 , & V_182 ) < 0 )
V_182 = 0 ;
if ( ! V_182 )
V_21 &= ~ V_187 ;
}
return V_21 ;
}
static int F_132 ( struct V_19 * V_20 ,
T_8 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_172 > V_173 ) {
F_133 ( V_20 , L_17 ) ;
V_20 -> V_172 = V_173 ;
}
return 0 ;
}
static T_9 F_134 ( int V_188 , void * V_189 )
{
struct V_11 * V_12 = V_189 ;
unsigned long V_83 ;
F_77 ( & V_12 -> V_102 , V_83 ) ;
F_45 ( V_12 ) ;
F_80 ( & V_12 -> V_102 , V_83 ) ;
return V_190 ;
}
static T_9 F_135 ( int V_188 , void * V_189 )
{
struct V_11 * V_12 = V_189 ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
if ( F_17 ( F_27 ( V_20 ) &&
F_42 ( & V_12 -> V_41 ) ) )
F_11 ( & V_12 -> V_24 ) ;
return V_190 ;
}
static T_9 F_136 ( int V_188 , void * V_189 )
{
F_134 ( V_188 , V_189 ) ;
F_135 ( V_188 , V_189 ) ;
return V_190 ;
}
static void F_137 ( struct V_19 * V_20 )
{
struct V_55 * V_30 = F_39 ( V_20 ) ;
unsigned int V_57 = V_20 -> V_58 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 )
F_136 ( 0 , & V_30 -> V_59 [ V_14 ] ) ;
}
static void F_138 ( struct V_19 * V_31 )
{
struct V_55 * V_56 = F_39 ( V_31 ) ;
F_139 ( V_56 -> V_159 ) ;
F_139 ( V_56 -> V_96 ) ;
F_140 ( V_31 ) ;
}
static struct V_19 * F_141 ( struct V_191 * V_20 )
{
int V_131 ;
struct V_19 * V_31 ;
struct V_55 * V_56 ;
V_31 = F_142 ( sizeof( struct V_55 ) , V_192 ) ;
if ( ! V_31 )
return F_143 ( - V_193 ) ;
V_56 = F_39 ( V_31 ) ;
V_56 -> V_47 = V_20 ;
V_56 -> V_59 = NULL ;
V_131 = - V_193 ;
V_56 -> V_159 = F_144 ( struct V_95 ) ;
if ( V_56 -> V_159 == NULL )
goto exit;
V_56 -> V_96 = F_144 ( struct V_95 ) ;
if ( V_56 -> V_96 == NULL )
goto exit;
V_31 -> V_194 = & V_195 ;
V_31 -> V_21 = V_196 | V_197 |
V_198 ;
V_31 -> V_199 = V_22 |
V_185 |
V_186 | V_187 ;
V_31 -> V_21 |= V_31 -> V_199 ;
V_31 -> V_200 = & V_201 ;
F_145 ( V_31 , & V_20 -> V_20 ) ;
V_56 -> V_31 = V_31 ;
F_146 ( V_31 ) ;
return V_31 ;
exit:
F_138 ( V_31 ) ;
return F_143 ( V_131 ) ;
}
static int F_147 ( struct V_191 * V_20 ,
const struct V_202 * V_3 )
{
int V_131 ;
struct V_19 * V_31 ;
struct V_55 * V_30 ;
V_31 = F_141 ( V_20 ) ;
if ( F_148 ( V_31 ) ) {
V_131 = F_149 ( V_31 ) ;
F_150 ( V_20 , V_131 , L_18 ) ;
return V_131 ;
}
V_30 = F_39 ( V_31 ) ;
F_151 ( & V_20 -> V_20 , V_30 ) ;
#ifdef F_152
V_30 -> V_31 -> V_203 [ 0 ] = & V_204 ;
#endif
V_131 = F_153 ( V_30 -> V_31 ) ;
if ( V_131 ) {
F_95 ( L_19 , V_72 , V_131 ) ;
goto V_205;
}
return 0 ;
V_205:
F_138 ( V_31 ) ;
F_151 ( & V_20 -> V_20 , NULL ) ;
return V_131 ;
}
static void F_154 ( int V_16 , void * V_34 )
{
if ( V_16 != V_18 )
F_127 ( V_16 , 0 , ( unsigned long ) V_34 ) ;
}
static void F_155 ( struct V_55 * V_30 )
{
unsigned int V_14 = 0 ;
unsigned int V_57 = V_30 -> V_31 -> V_58 ;
F_146 ( V_30 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_57 && V_30 -> V_59 ; ++ V_14 ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
if ( V_12 -> V_119 && ( V_12 -> V_119 == V_12 -> V_54 ) )
F_156 ( V_12 -> V_119 , V_12 ) ;
if ( V_12 -> V_119 && ( V_12 -> V_119 != V_12 -> V_54 ) ) {
F_156 ( V_12 -> V_119 , V_12 ) ;
F_156 ( V_12 -> V_54 , V_12 ) ;
}
V_12 -> V_206 = V_12 -> V_207 = 0 ;
V_12 -> V_119 = V_12 -> V_54 = 0 ;
if ( F_18 ( V_30 -> V_31 ) )
F_157 ( & V_12 -> V_24 ) ;
F_125 ( V_12 ) ;
F_129 ( V_12 ) ;
F_158 ( V_12 -> V_74 ) ;
F_158 ( V_12 -> V_45 ) ;
F_154 ( V_12 -> V_208 , V_12 -> V_25 . V_61 ) ;
F_154 ( V_12 -> V_209 , V_12 -> V_41 . V_61 ) ;
V_12 -> V_208 = V_18 ;
V_12 -> V_209 = V_18 ;
V_12 -> V_25 . V_61 = NULL ;
V_12 -> V_41 . V_61 = NULL ;
}
}
static int F_159 ( struct V_191 * V_20 )
{
struct V_55 * V_30 = F_160 ( & V_20 -> V_20 ) ;
F_161 ( & V_20 -> V_20 , L_20 , V_20 -> V_210 ) ;
F_155 ( V_30 ) ;
return 0 ;
}
static int F_162 ( struct V_191 * V_20 , T_10 V_211 [] )
{
char * V_212 , * V_213 , * V_214 ;
int V_14 ;
V_214 = V_212 = F_163 ( V_183 , V_20 -> V_210 , L_21 , NULL ) ;
if ( F_148 ( V_214 ) )
return F_149 ( V_214 ) ;
for ( V_14 = 0 ; V_14 < V_215 ; V_14 ++ ) {
V_211 [ V_14 ] = F_164 ( V_212 , & V_213 , 16 ) ;
if ( ( V_212 == V_213 ) || ( * V_213 != ( ( V_14 == V_215 - 1 ) ? '\0' : ':' ) ) ) {
F_165 ( V_214 ) ;
return - V_146 ;
}
V_212 = V_213 + 1 ;
}
F_165 ( V_214 ) ;
return 0 ;
}
static int F_166 ( struct V_11 * V_12 )
{
int V_131 ;
V_131 = F_167 ( V_12 -> V_30 -> V_47 , & V_12 -> V_206 ) ;
if ( V_131 < 0 )
goto V_205;
V_131 = F_168 ( V_12 -> V_206 ,
F_136 ,
0 , V_12 -> V_30 -> V_31 -> V_216 , V_12 ) ;
if ( V_131 < 0 )
goto V_217;
V_12 -> V_207 = V_12 -> V_206 ;
V_12 -> V_54 = V_12 -> V_119 = V_131 ;
return 0 ;
V_217:
F_169 ( V_12 -> V_30 -> V_47 , V_12 -> V_206 ) ;
V_12 -> V_206 = 0 ;
V_205:
return V_131 ;
}
static int F_170 ( struct V_11 * V_12 )
{
int V_131 ;
V_131 = F_167 ( V_12 -> V_30 -> V_47 , & V_12 -> V_206 ) ;
if ( V_131 < 0 )
goto V_205;
V_131 = F_167 ( V_12 -> V_30 -> V_47 , & V_12 -> V_207 ) ;
if ( V_131 < 0 )
goto V_218;
snprintf ( V_12 -> V_219 , sizeof( V_12 -> V_219 ) ,
L_22 , V_12 -> V_216 ) ;
V_131 = F_168 ( V_12 -> V_206 ,
F_134 ,
0 , V_12 -> V_219 , V_12 ) ;
if ( V_131 < 0 )
goto V_220;
V_12 -> V_119 = V_131 ;
snprintf ( V_12 -> V_221 , sizeof( V_12 -> V_221 ) ,
L_23 , V_12 -> V_216 ) ;
V_131 = F_168 ( V_12 -> V_207 ,
F_135 ,
0 , V_12 -> V_221 , V_12 ) ;
if ( V_131 < 0 )
goto V_222;
V_12 -> V_54 = V_131 ;
return 0 ;
V_222:
F_156 ( V_12 -> V_119 , V_12 ) ;
V_12 -> V_119 = 0 ;
V_220:
F_169 ( V_12 -> V_30 -> V_47 , V_12 -> V_207 ) ;
V_12 -> V_207 = 0 ;
V_218:
F_169 ( V_12 -> V_30 -> V_47 , V_12 -> V_206 ) ;
V_12 -> V_206 = 0 ;
V_205:
return V_131 ;
}
static int F_171 ( struct V_191 * V_20 ,
struct V_11 * V_12 , unsigned int V_223 )
{
struct V_224 * V_225 ;
struct V_226 * V_227 ;
T_2 V_49 ;
int V_131 ;
V_12 -> V_208 = V_18 ;
V_12 -> V_209 = V_18 ;
V_12 -> V_41 . V_61 = NULL ;
V_12 -> V_25 . V_61 = NULL ;
V_225 = (struct V_224 * ) F_172 ( V_228 | V_229 ) ;
if ( ! V_225 ) {
V_131 = - V_193 ;
F_150 ( V_20 , V_131 , L_24 ) ;
goto V_205;
}
F_173 ( V_225 ) ;
F_174 ( & V_12 -> V_25 , V_225 , V_143 ) ;
V_131 = F_175 ( V_20 , V_225 , 1 , & V_49 ) ;
if ( V_131 < 0 )
goto V_230;
V_12 -> V_208 = V_49 ;
V_227 = (struct V_226 * ) F_172 ( V_228 | V_229 ) ;
if ( ! V_227 ) {
V_131 = - V_193 ;
F_150 ( V_20 , V_131 , L_25 ) ;
goto V_231;
}
F_173 ( V_227 ) ;
F_174 ( & V_12 -> V_41 , V_227 , V_143 ) ;
V_131 = F_175 ( V_20 , V_227 , 1 , & V_49 ) ;
if ( V_131 < 0 )
goto V_232;
V_12 -> V_209 = V_49 ;
if ( V_223 )
V_131 = F_170 ( V_12 ) ;
if ( ! V_223 || ( V_223 && V_131 ) )
V_131 = F_166 ( V_12 ) ;
if ( V_131 )
goto V_233;
return 0 ;
V_233:
F_51 ( V_12 -> V_209 , 0 ) ;
V_232:
F_176 ( ( unsigned long ) V_227 ) ;
V_231:
F_51 ( V_12 -> V_208 , 0 ) ;
V_230:
F_176 ( ( unsigned long ) V_225 ) ;
V_205:
return V_131 ;
}
static int F_177 ( struct V_11 * V_12 )
{
unsigned short V_14 ;
int V_131 = 0 ;
F_178 ( & V_12 -> V_102 ) ;
F_178 ( & V_12 -> V_60 ) ;
F_179 ( & V_12 -> V_51 , F_10 ,
( unsigned long ) V_12 ) ;
snprintf ( V_12 -> V_216 , sizeof( V_12 -> V_216 ) , L_26 ,
V_12 -> V_30 -> V_31 -> V_216 , V_12 -> V_3 ) ;
V_12 -> V_76 = 0 ;
for ( V_14 = 0 ; V_14 < V_28 ; V_14 ++ ) {
F_1 ( & V_12 -> V_70 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
V_12 -> V_75 [ V_14 ] = NULL ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_180 ( V_28 ,
& V_12 -> V_74 ) < 0 ) {
F_49 ( L_27 ) ;
V_131 = - V_193 ;
goto exit;
}
if ( F_180 ( V_9 ,
& V_12 -> V_45 ) < 0 ) {
F_49 ( L_28 ) ;
V_131 = - V_193 ;
goto V_234;
}
return 0 ;
V_234:
F_158 ( V_12 -> V_74 ) ;
exit:
return V_131 ;
}
static int F_181 ( struct V_11 * V_12 ,
struct V_235 * V_236 , int V_237 )
{
struct V_191 * V_20 = V_12 -> V_30 -> V_47 ;
int V_131 ;
const char * V_238 ;
char * V_239 ;
T_11 V_240 ;
if ( V_237 ) {
V_240 = strlen ( V_20 -> V_210 ) + 10 ;
V_239 = F_182 ( V_240 , V_241 ) ;
if ( ! V_239 ) {
V_131 = - V_193 ;
V_238 = L_29 ;
goto error;
}
snprintf ( V_239 , V_240 , L_30 ,
V_20 -> V_210 , V_12 -> V_3 ) ;
} else {
V_239 = ( char * ) V_20 -> V_210 ;
}
V_131 = F_183 ( * V_236 , V_239 , L_31 , L_32 ,
V_12 -> V_208 ) ;
if ( V_131 ) {
V_238 = L_33 ;
goto error;
}
V_131 = F_183 ( * V_236 , V_239 , L_34 , L_32 ,
V_12 -> V_209 ) ;
if ( V_131 ) {
V_238 = L_35 ;
goto error;
}
if ( V_12 -> V_206 == V_12 -> V_207 ) {
V_131 = F_183 ( * V_236 , V_239 ,
L_36 , L_32 , V_12 -> V_206 ) ;
if ( V_131 ) {
V_238 = L_37 ;
goto error;
}
} else {
V_131 = F_183 ( * V_236 , V_239 ,
L_38 , L_32 , V_12 -> V_206 ) ;
if ( V_131 ) {
V_238 = L_39 ;
goto error;
}
V_131 = F_183 ( * V_236 , V_239 ,
L_40 , L_32 , V_12 -> V_207 ) ;
if ( V_131 ) {
V_238 = L_41 ;
goto error;
}
}
if ( V_237 )
F_165 ( V_239 ) ;
return 0 ;
error:
if ( V_237 )
F_165 ( V_239 ) ;
F_150 ( V_20 , V_131 , L_42 , V_238 ) ;
return V_131 ;
}
static void F_184 ( struct V_55 * V_30 )
{
unsigned int V_14 ;
F_185 () ;
for ( V_14 = 0 ; V_14 < V_30 -> V_31 -> V_58 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
if ( F_18 ( V_30 -> V_31 ) )
F_87 ( & V_12 -> V_24 ) ;
F_186 ( & V_12 -> V_51 ) ;
F_187 ( & V_12 -> V_24 ) ;
}
F_188 () ;
F_165 ( V_30 -> V_59 ) ;
V_30 -> V_59 = NULL ;
}
static int F_189 ( struct V_55 * V_30 ,
unsigned int * V_57 )
{
unsigned int V_14 ;
int V_141 ;
V_30 -> V_59 = F_190 ( * V_57 , sizeof( struct V_11 ) ,
V_241 ) ;
if ( ! V_30 -> V_59 )
return - V_193 ;
F_185 () ;
for ( V_14 = 0 ; V_14 < * V_57 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_59 [ V_14 ] ;
V_12 -> V_3 = V_14 ;
V_12 -> V_30 = V_30 ;
V_141 = F_177 ( V_12 ) ;
if ( V_141 < 0 ) {
F_91 ( & V_30 -> V_31 -> V_20 ,
L_43 , V_14 ) ;
* V_57 = V_14 ;
break;
}
F_191 ( V_12 -> V_30 -> V_31 , & V_12 -> V_24 ,
F_108 , 64 ) ;
if ( F_18 ( V_30 -> V_31 ) )
F_40 ( & V_12 -> V_24 ) ;
}
F_192 ( V_30 -> V_31 , * V_57 ) ;
F_188 () ;
if ( * V_57 == 0 ) {
F_193 ( & V_30 -> V_31 -> V_20 , L_44 ) ;
return - V_134 ;
}
return 0 ;
}
static int F_194 ( struct V_191 * V_20 ,
struct V_55 * V_30 )
{
const char * V_238 ;
struct V_235 V_236 ;
int V_131 ;
unsigned int V_223 ;
unsigned int V_14 = 0 ;
unsigned int V_242 = 0 ;
struct V_11 * V_12 = NULL ;
unsigned int V_57 = 1 ;
V_30 -> V_31 -> V_188 = 0 ;
V_131 = F_131 ( V_183 , V_30 -> V_47 -> V_184 ,
L_45 , L_32 , & V_242 ) ;
if ( V_131 < 0 )
V_242 = 1 ;
V_57 = F_195 ( V_242 , V_192 ) ;
V_131 = F_131 ( V_183 , V_30 -> V_47 -> V_184 ,
L_46 , L_32 ,
& V_223 ) ;
if ( V_131 < 0 )
V_223 = 0 ;
V_131 = F_162 ( V_20 , V_30 -> V_31 -> V_243 ) ;
if ( V_131 ) {
F_150 ( V_20 , V_131 , L_47 , V_20 -> V_210 ) ;
goto V_244;
}
if ( V_30 -> V_59 )
F_184 ( V_30 ) ;
V_131 = F_189 ( V_30 , & V_57 ) ;
if ( V_131 < 0 )
goto V_245;
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_30 -> V_59 [ V_14 ] ;
V_131 = F_171 ( V_20 , V_12 , V_223 ) ;
if ( V_131 ) {
if ( V_14 > 0 ) {
F_185 () ;
F_192 ( V_30 -> V_31 , V_14 ) ;
F_188 () ;
goto V_245;
} else {
goto V_244;
}
}
}
V_246:
V_131 = F_196 ( & V_236 ) ;
if ( V_131 ) {
F_150 ( V_20 , V_131 , L_48 ) ;
goto V_245;
}
if ( F_197 ( V_183 ,
V_30 -> V_47 -> V_184 , L_45 ) ) {
V_131 = F_183 ( V_236 , V_20 -> V_210 ,
L_49 , L_32 , V_57 ) ;
if ( V_131 ) {
V_238 = L_50 ;
goto V_247;
}
}
if ( V_57 == 1 ) {
V_131 = F_181 ( & V_30 -> V_59 [ 0 ] , & V_236 , 0 ) ;
if ( V_131 )
goto V_247;
} else {
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_12 = & V_30 -> V_59 [ V_14 ] ;
V_131 = F_181 ( V_12 , & V_236 , 1 ) ;
if ( V_131 )
goto V_247;
}
}
V_131 = F_183 ( V_236 , V_20 -> V_210 , L_51 , L_32 ,
1 ) ;
if ( V_131 ) {
V_238 = L_52 ;
goto V_248;
}
V_131 = F_183 ( V_236 , V_20 -> V_210 , L_53 , L_13 , 1 ) ;
if ( V_131 ) {
V_238 = L_54 ;
goto V_248;
}
V_131 = F_183 ( V_236 , V_20 -> V_210 , L_12 , L_13 , 1 ) ;
if ( V_131 ) {
V_238 = L_55 ;
goto V_248;
}
V_131 = F_183 ( V_236 , V_20 -> V_210 , L_15 , L_13 , 1 ) ;
if ( V_131 ) {
V_238 = L_56 ;
goto V_248;
}
V_131 = F_198 ( V_236 , V_20 -> V_210 , L_16 , L_57 ) ;
if ( V_131 ) {
V_238 = L_58 ;
goto V_248;
}
V_131 = F_198 ( V_236 , V_20 -> V_210 , L_14 ,
L_57 ) ;
if ( V_131 ) {
V_238 = L_59 ;
goto V_248;
}
V_131 = F_199 ( V_236 , 0 ) ;
if ( V_131 ) {
if ( V_131 == - V_249 )
goto V_246;
F_150 ( V_20 , V_131 , L_60 ) ;
goto V_245;
}
return 0 ;
V_248:
F_150 ( V_20 , V_131 , L_42 , V_238 ) ;
V_247:
F_199 ( V_236 , 1 ) ;
V_245:
F_155 ( V_30 ) ;
F_165 ( V_30 -> V_59 ) ;
V_30 -> V_59 = NULL ;
V_244:
return V_131 ;
}
static int F_200 ( struct V_19 * V_20 )
{
struct V_55 * V_56 = F_39 ( V_20 ) ;
unsigned int V_57 = 0 ;
int V_131 ;
unsigned int V_250 ;
unsigned int V_251 = 0 ;
struct V_11 * V_12 = NULL ;
V_131 = F_131 ( V_183 , V_56 -> V_47 -> V_184 ,
L_61 , L_32 , & V_250 ) ;
if ( V_131 != 1 )
V_250 = 0 ;
if ( ! V_250 ) {
F_201 ( & V_20 -> V_20 ,
L_62 ) ;
return - V_252 ;
}
V_131 = F_194 ( V_56 -> V_47 , V_56 ) ;
if ( V_131 )
return V_131 ;
V_57 = V_20 -> V_58 ;
F_185 () ;
F_202 ( V_20 ) ;
F_188 () ;
F_203 ( V_56 -> V_31 ) ;
for ( V_251 = 0 ; V_251 < V_57 ; ++ V_251 ) {
V_12 = & V_56 -> V_59 [ V_251 ] ;
F_37 ( V_12 -> V_119 ) ;
if ( V_12 -> V_119 != V_12 -> V_54 )
F_37 ( V_12 -> V_54 ) ;
F_204 ( & V_12 -> V_102 ) ;
F_45 ( V_12 ) ;
F_205 ( & V_12 -> V_102 ) ;
F_41 ( & V_12 -> V_60 ) ;
F_26 ( V_12 ) ;
F_43 ( & V_12 -> V_60 ) ;
}
return 0 ;
}
static void F_206 ( struct V_191 * V_20 ,
enum V_253 V_254 )
{
struct V_55 * V_56 = F_160 ( & V_20 -> V_20 ) ;
struct V_19 * V_31 = V_56 -> V_31 ;
F_161 ( & V_20 -> V_20 , L_20 , F_207 ( V_254 ) ) ;
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
if ( F_200 ( V_31 ) != 0 )
break;
F_208 ( V_20 , V_262 ) ;
break;
case V_262 :
F_209 ( V_31 ) ;
break;
case V_263 :
if ( V_20 -> V_261 == V_263 )
break;
case V_264 :
F_210 ( V_20 ) ;
break;
}
}
static int F_211 ( struct V_19 * V_20 , int V_265 )
{
switch ( V_265 ) {
case V_266 :
return F_212 ( V_267 ) ;
default:
return - V_134 ;
}
}
static void F_213 ( struct V_19 * V_20 ,
struct V_268 * V_124 , T_7 * V_23 )
{
void * V_56 = F_39 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_212 ( V_267 ) ; V_14 ++ )
V_23 [ V_14 ] = F_214 ( ( V_269 * ) ( V_56 + V_267 [ V_14 ] . V_78 ) ) ;
}
static void F_215 ( struct V_19 * V_20 , T_6 V_270 , T_10 * V_23 )
{
int V_14 ;
switch ( V_270 ) {
case V_266 :
for ( V_14 = 0 ; V_14 < F_212 ( V_267 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_271 ,
V_267 [ V_14 ] . V_216 , V_271 ) ;
break;
}
}
static T_12 F_216 ( struct V_130 * V_20 ,
struct V_272 * V_273 , char * V_274 )
{
return sprintf ( V_274 , L_63 , V_9 ) ;
}
static T_12 F_217 ( struct V_130 * V_20 ,
struct V_272 * V_273 ,
const char * V_274 , T_11 V_79 )
{
char * V_275 ;
unsigned long V_276 ;
if ( ! F_218 ( V_277 ) )
return - V_278 ;
V_276 = F_164 ( V_274 , & V_275 , 0 ) ;
if ( V_275 == V_274 )
return - V_279 ;
return V_79 ;
}
static int F_219 ( struct V_191 * V_20 )
{
struct V_55 * V_30 = F_160 ( & V_20 -> V_20 ) ;
F_161 ( & V_20 -> V_20 , L_20 , V_20 -> V_210 ) ;
F_155 ( V_30 ) ;
F_220 ( V_30 -> V_31 ) ;
if ( V_30 -> V_59 )
F_184 ( V_30 ) ;
F_138 ( V_30 -> V_31 ) ;
return 0 ;
}
static int T_13 F_221 ( void )
{
if ( ! F_222 () )
return - V_252 ;
if ( ! F_223 () )
return - V_252 ;
F_224 ( L_64 ) ;
if ( V_192 == 0 )
V_192 = F_225 () ;
return F_226 ( & V_280 ) ;
}
static void T_14 F_227 ( void )
{
F_228 ( & V_280 ) ;
}
