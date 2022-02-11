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
unsigned long V_43 ;
struct V_44 * V_45 ;
V_5 = F_20 ( V_12 ) ;
if ( ! V_5 )
break;
V_3 = F_6 ( V_40 ) ;
F_28 ( V_12 -> V_15 [ V_3 ] ) ;
V_12 -> V_15 [ V_3 ] = V_5 ;
V_16 = F_29 ( & V_12 -> V_46 ) ;
F_28 ( ( signed short ) V_16 < 0 ) ;
V_12 -> V_17 [ V_3 ] = V_16 ;
V_43 = F_30 ( F_31 ( & F_32 ( V_5 ) -> V_47 [ 0 ] ) ) ;
V_45 = F_33 ( & V_12 -> V_41 , V_40 ) ;
F_34 ( V_16 ,
V_12 -> V_30 -> V_48 -> V_49 ,
F_35 ( V_43 ) ,
0 ) ;
V_45 -> V_3 = V_3 ;
V_45 -> V_50 = V_16 ;
}
V_12 -> V_41 . V_26 = V_40 ;
if ( V_40 - V_12 -> V_41 . V_27 < V_51 ) {
F_36 ( & V_12 -> V_52 , V_53 + ( V_54 / 10 ) ) ;
return;
}
F_37 () ;
F_38 ( & V_12 -> V_41 , V_42 ) ;
if ( V_42 )
F_39 ( V_12 -> V_55 ) ;
}
static int F_40 ( struct V_19 * V_20 )
{
struct V_56 * V_57 = F_41 ( V_20 ) ;
unsigned int V_58 = V_20 -> V_59 ;
unsigned int V_14 = 0 ;
struct V_11 * V_12 = NULL ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
V_12 = & V_57 -> V_60 [ V_14 ] ;
F_42 ( & V_12 -> V_24 ) ;
F_43 ( & V_12 -> V_61 ) ;
if ( F_27 ( V_20 ) ) {
F_26 ( V_12 ) ;
V_12 -> V_41 . V_62 -> V_63 = V_12 -> V_41 . V_27 + 1 ;
if ( F_44 ( & V_12 -> V_41 ) )
F_11 ( & V_12 -> V_24 ) ;
}
F_45 ( & V_12 -> V_61 ) ;
}
F_46 ( V_20 ) ;
return 0 ;
}
static void F_47 ( struct V_11 * V_12 )
{
T_1 V_64 , V_65 ;
unsigned short V_3 ;
struct V_10 * V_5 ;
F_28 ( ! F_27 ( V_12 -> V_30 -> V_31 ) ) ;
do {
V_65 = V_12 -> V_25 . V_62 -> V_66 ;
F_48 () ;
for ( V_64 = V_12 -> V_25 . V_27 ; V_64 != V_65 ; V_64 ++ ) {
struct V_67 * V_68 ;
V_68 = F_49 ( & V_12 -> V_25 , V_64 ) ;
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
V_12 -> V_25 . V_27 = V_65 ;
V_12 -> V_25 . V_62 -> V_63 =
V_65 + ( ( V_12 -> V_25 . V_62 -> V_40 - V_65 ) >> 1 ) + 1 ;
F_56 () ;
} while ( ( V_64 == V_65 ) && ( V_65 != V_12 -> V_25 . V_62 -> V_66 ) );
F_13 ( V_12 ) ;
}
static void F_57 ( struct V_10 * V_5 , struct V_11 * V_12 ,
struct V_78 * V_25 )
{
char * V_23 = V_5 -> V_23 ;
unsigned long V_79 ;
T_1 V_65 = V_12 -> V_25 . V_26 ;
int V_47 = F_32 ( V_5 ) -> V_80 ;
unsigned int V_81 = F_58 ( V_23 ) ;
unsigned int V_82 = F_59 ( V_5 ) ;
unsigned int V_3 ;
T_2 V_16 ;
int V_14 ;
while ( V_82 > V_39 - V_81 ) {
V_25 -> V_83 = V_39 - V_81 ;
V_25 -> V_84 |= V_85 ;
V_82 -= V_25 -> V_83 ;
V_23 += V_25 -> V_83 ;
V_81 = 0 ;
V_3 = F_5 ( & V_12 -> V_77 , V_12 -> V_71 ) ;
V_12 -> V_71 [ V_3 ] . V_5 = F_60 ( V_5 ) ;
V_25 = F_33 ( & V_12 -> V_25 , V_65 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_29 ( & V_12 -> V_75 ) ;
F_28 ( ( signed short ) V_16 < 0 ) ;
V_79 = F_61 ( V_23 ) ;
F_34 ( V_16 , V_12 -> V_30 -> V_48 -> V_49 ,
V_79 , V_74 ) ;
V_12 -> V_76 [ V_3 ] = F_62 ( V_23 ) ;
V_25 -> V_50 = V_12 -> V_72 [ V_3 ] = V_16 ;
V_25 -> V_81 = V_81 ;
V_25 -> V_83 = V_82 ;
V_25 -> V_84 = 0 ;
}
for ( V_14 = 0 ; V_14 < V_47 ; V_14 ++ ) {
T_3 * V_86 = F_32 ( V_5 ) -> V_47 + V_14 ;
struct V_34 * V_34 = F_31 ( V_86 ) ;
V_82 = F_63 ( V_86 ) ;
V_81 = V_86 -> V_87 ;
V_34 += V_81 >> V_88 ;
V_81 &= ~ V_89 ;
while ( V_82 > 0 ) {
unsigned long V_90 ;
V_90 = V_39 - V_81 ;
if ( V_90 > V_82 )
V_90 = V_82 ;
V_25 -> V_84 |= V_85 ;
V_3 = F_5 ( & V_12 -> V_77 ,
V_12 -> V_71 ) ;
V_12 -> V_71 [ V_3 ] . V_5 = F_60 ( V_5 ) ;
V_25 = F_33 ( & V_12 -> V_25 , V_65 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_29 ( & V_12 -> V_75 ) ;
F_28 ( ( signed short ) V_16 < 0 ) ;
V_79 = F_35 ( F_30 ( V_34 ) ) ;
F_34 ( V_16 ,
V_12 -> V_30 -> V_48 -> V_49 ,
V_79 , V_74 ) ;
V_12 -> V_76 [ V_3 ] = V_34 ;
V_25 -> V_50 = V_12 -> V_72 [ V_3 ] = V_16 ;
V_25 -> V_81 = V_81 ;
V_25 -> V_83 = V_90 ;
V_25 -> V_84 = 0 ;
V_81 += V_90 ;
V_82 -= V_90 ;
if ( V_81 == V_39 && V_82 ) {
F_28 ( ! F_64 ( V_34 ) ) ;
V_34 ++ ;
V_81 = 0 ;
}
}
}
V_12 -> V_25 . V_26 = V_65 ;
}
static int F_65 ( struct V_10 * V_5 )
{
int V_14 , V_47 = F_32 ( V_5 ) -> V_80 ;
int V_91 = 0 ;
for ( V_14 = 0 ; V_14 < V_47 ; V_14 ++ ) {
T_3 * V_86 = F_32 ( V_5 ) -> V_47 + V_14 ;
unsigned long V_83 = F_63 ( V_86 ) ;
unsigned long V_81 = V_86 -> V_87 ;
V_81 &= ~ V_89 ;
V_91 += F_66 ( V_81 + V_83 ) ;
}
return V_91 ;
}
static T_4 F_67 ( struct V_19 * V_20 , struct V_10 * V_5 ,
void * V_92 , T_5 V_93 )
{
unsigned int V_58 = V_20 -> V_59 ;
T_6 V_94 ;
T_4 V_95 ;
if ( V_58 == 1 ) {
V_95 = 0 ;
} else {
V_94 = F_68 ( V_5 ) ;
V_95 = V_94 % V_58 ;
}
return V_95 ;
}
static int F_69 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
unsigned short V_3 ;
struct V_56 * V_57 = F_41 ( V_20 ) ;
struct V_96 * V_97 = F_70 ( V_57 -> V_97 ) ;
struct V_78 * V_25 ;
char * V_23 = V_5 -> V_23 ;
T_1 V_14 ;
T_2 V_16 ;
unsigned long V_79 ;
int V_42 ;
int V_98 ;
unsigned int V_81 = F_58 ( V_23 ) ;
unsigned int V_82 = F_59 ( V_5 ) ;
unsigned long V_84 ;
struct V_11 * V_12 = NULL ;
unsigned int V_58 = V_20 -> V_59 ;
T_4 V_99 ;
if ( V_58 < 1 )
goto V_100;
V_99 = F_71 ( V_5 ) ;
V_12 = & V_57 -> V_60 [ V_99 ] ;
if ( F_15 ( V_5 -> V_82 > V_101 ) ) {
F_72 (
L_2 ,
V_5 -> V_82 ) ;
goto V_100;
}
V_98 = F_73 ( V_81 + V_82 , V_39 ) +
F_65 ( V_5 ) ;
if ( F_15 ( V_98 > V_29 + 1 ) ) {
F_74 ( L_3 ,
V_98 , V_5 -> V_82 ) ;
if ( F_75 ( V_5 ) )
goto V_100;
V_23 = V_5 -> V_23 ;
V_81 = F_58 ( V_23 ) ;
V_82 = F_59 ( V_5 ) ;
}
F_76 ( & V_12 -> V_102 , V_84 ) ;
if ( F_15 ( ! F_27 ( V_20 ) ||
( V_98 > 1 && ! F_9 ( V_20 ) ) ||
F_77 ( V_20 , V_5 , F_78 ( V_5 ) ) ) ) {
F_79 ( & V_12 -> V_102 , V_84 ) ;
goto V_100;
}
V_14 = V_12 -> V_25 . V_26 ;
V_3 = F_5 ( & V_12 -> V_77 , V_12 -> V_71 ) ;
V_12 -> V_71 [ V_3 ] . V_5 = V_5 ;
V_25 = F_33 ( & V_12 -> V_25 , V_14 ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_29 ( & V_12 -> V_75 ) ;
F_28 ( ( signed short ) V_16 < 0 ) ;
V_79 = F_61 ( V_23 ) ;
F_34 (
V_16 , V_12 -> V_30 -> V_48 -> V_49 , V_79 , V_74 ) ;
V_12 -> V_76 [ V_3 ] = F_62 ( V_23 ) ;
V_25 -> V_50 = V_12 -> V_72 [ V_3 ] = V_16 ;
V_25 -> V_81 = V_81 ;
V_25 -> V_83 = V_82 ;
V_25 -> V_84 = 0 ;
if ( V_5 -> V_103 == V_104 )
V_25 -> V_84 |= V_105 | V_106 ;
else if ( V_5 -> V_103 == V_107 )
V_25 -> V_84 |= V_106 ;
if ( F_32 ( V_5 ) -> V_108 ) {
struct V_109 * V_110 ;
V_110 = (struct V_109 * )
F_33 ( & V_12 -> V_25 , ++ V_14 ) ;
V_25 -> V_84 |= V_111 ;
V_110 -> V_112 . V_110 . V_83 = F_32 ( V_5 ) -> V_108 ;
V_110 -> V_112 . V_110 . type = ( F_32 ( V_5 ) -> V_113 & V_114 ) ?
V_115 :
V_116 ;
V_110 -> V_112 . V_110 . V_117 = 0 ;
V_110 -> V_112 . V_110 . V_21 = 0 ;
V_110 -> type = V_118 ;
V_110 -> V_84 = 0 ;
}
V_12 -> V_25 . V_26 = V_14 + 1 ;
F_57 ( V_5 , V_12 , V_25 ) ;
V_25 -> V_83 = V_5 -> V_82 ;
F_38 ( & V_12 -> V_25 , V_42 ) ;
if ( V_42 )
F_39 ( V_12 -> V_119 ) ;
F_80 ( & V_97 -> V_120 ) ;
V_97 -> V_90 += V_5 -> V_82 ;
V_97 -> V_121 ++ ;
F_81 ( & V_97 -> V_120 ) ;
F_47 ( V_12 ) ;
if ( ! F_12 ( V_12 ) )
F_82 ( F_14 ( V_20 , V_12 -> V_3 ) ) ;
F_79 ( & V_12 -> V_102 , V_84 ) ;
return V_122 ;
V_100:
V_20 -> V_123 . V_124 ++ ;
F_83 ( V_5 ) ;
return V_122 ;
}
static int F_84 ( struct V_19 * V_20 )
{
struct V_56 * V_57 = F_41 ( V_20 ) ;
unsigned int V_58 = V_20 -> V_59 ;
unsigned int V_14 ;
struct V_11 * V_12 ;
F_85 ( V_57 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
V_12 = & V_57 -> V_60 [ V_14 ] ;
F_86 ( & V_12 -> V_24 ) ;
}
return 0 ;
}
static void F_87 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_125 = F_6 ( V_12 -> V_41 . V_26 ) ;
F_28 ( V_12 -> V_15 [ V_125 ] ) ;
V_12 -> V_15 [ V_125 ] = V_5 ;
V_12 -> V_17 [ V_125 ] = V_16 ;
F_33 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_3 = V_125 ;
F_33 ( & V_12 -> V_41 , V_12 -> V_41 . V_26 ) -> V_50 = V_16 ;
V_12 -> V_41 . V_26 ++ ;
}
static int F_88 ( struct V_11 * V_12 ,
struct V_109 * V_126 ,
T_1 V_127 )
{
struct V_109 * V_128 ;
struct V_129 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_64 = V_12 -> V_41 . V_27 ;
int V_130 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_64 + 1 == V_127 ) ) {
if ( F_89 () )
F_90 ( V_20 , L_4 ) ;
V_130 = - V_131 ;
break;
}
V_128 = (struct V_109 * )
F_49 ( & V_12 -> V_41 , ++ V_64 ) ;
if ( F_15 ( ! V_128 -> type ||
V_128 -> type >= V_132 ) ) {
if ( F_89 () )
F_90 ( V_20 , L_5 ,
V_128 -> type ) ;
V_130 = - V_133 ;
} else {
memcpy ( & V_126 [ V_128 -> type - 1 ] , V_128 ,
sizeof( * V_128 ) ) ;
}
V_5 = F_7 ( V_12 , V_64 ) ;
V_16 = F_8 ( V_12 , V_64 ) ;
F_87 ( V_12 , V_5 , V_16 ) ;
} while ( V_128 -> V_84 & V_134 );
V_12 -> V_41 . V_27 = V_64 ;
return V_130 ;
}
static int F_91 ( struct V_11 * V_12 ,
struct V_135 * V_136 , T_1 V_127 ,
struct V_137 * V_2 )
{
struct V_138 * V_41 = & V_136 -> V_41 ;
struct V_109 * V_126 = V_136 -> V_126 ;
struct V_129 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_64 = V_12 -> V_41 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_64 ) ;
T_2 V_16 = F_8 ( V_12 , V_64 ) ;
int V_139 = V_29 + ( V_41 -> V_69 <= V_35 ) ;
int V_98 = 1 ;
int V_130 = 0 ;
unsigned long V_140 ;
if ( V_41 -> V_84 & V_141 ) {
V_130 = F_88 ( V_12 , V_126 , V_127 ) ;
V_64 = V_12 -> V_41 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_41 -> V_69 < 0 ||
V_41 -> V_81 + V_41 -> V_69 > V_39 ) ) {
if ( F_89 () )
F_90 ( V_20 , L_6 ,
V_41 -> V_81 , V_41 -> V_69 ) ;
F_87 ( V_12 , V_5 , V_16 ) ;
V_130 = - V_133 ;
goto V_142;
}
if ( V_16 == V_18 ) {
if ( F_89 () )
F_90 ( V_20 , L_7 ,
V_41 -> V_3 ) ;
V_130 = - V_133 ;
goto V_142;
}
V_140 = F_53 ( V_16 , 0 ) ;
F_28 ( ! V_140 ) ;
F_54 ( & V_12 -> V_46 , V_16 ) ;
F_92 ( V_2 , V_5 ) ;
V_142:
if ( ! ( V_41 -> V_84 & V_143 ) )
break;
if ( V_64 + V_98 == V_127 ) {
if ( F_89 () )
F_90 ( V_20 , L_8 ) ;
V_130 = - V_144 ;
break;
}
V_41 = F_49 ( & V_12 -> V_41 , V_64 + V_98 ) ;
V_5 = F_7 ( V_12 , V_64 + V_98 ) ;
V_16 = F_8 ( V_12 , V_64 + V_98 ) ;
V_98 ++ ;
}
if ( F_15 ( V_98 > V_139 ) ) {
if ( F_89 () )
F_90 ( V_20 , L_9 ) ;
V_130 = - V_145 ;
}
if ( F_15 ( V_130 ) )
V_12 -> V_41 . V_27 = V_64 + V_98 ;
return V_130 ;
}
static int F_93 ( struct V_10 * V_5 ,
struct V_109 * V_110 )
{
if ( ! V_110 -> V_112 . V_110 . V_83 ) {
if ( F_89 () )
F_94 ( L_10 ) ;
return - V_133 ;
}
if ( V_110 -> V_112 . V_110 . type != V_116 &&
V_110 -> V_112 . V_110 . type != V_115 ) {
if ( F_89 () )
F_94 ( L_11 , V_110 -> V_112 . V_110 . type ) ;
return - V_133 ;
}
F_32 ( V_5 ) -> V_108 = V_110 -> V_112 . V_110 . V_83 ;
F_32 ( V_5 ) -> V_113 =
( V_110 -> V_112 . V_110 . type == V_116 ) ?
V_146 :
V_114 ;
F_32 ( V_5 ) -> V_113 |= V_147 ;
F_32 ( V_5 ) -> V_148 = 0 ;
return 0 ;
}
static T_1 F_95 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_137 * V_2 )
{
struct V_149 * V_150 = F_32 ( V_5 ) ;
T_1 V_64 = V_12 -> V_41 . V_27 ;
struct V_10 * V_151 ;
while ( ( V_151 = F_96 ( V_2 ) ) ) {
struct V_138 * V_41 =
F_49 ( & V_12 -> V_41 , ++ V_64 ) ;
T_3 * V_152 = & F_32 ( V_151 ) -> V_47 [ 0 ] ;
if ( V_150 -> V_80 == V_29 ) {
unsigned int V_153 = F_97 ( V_5 ) -> V_153 ;
F_28 ( V_153 <= F_59 ( V_5 ) ) ;
F_98 ( V_5 , V_153 - F_59 ( V_5 ) ) ;
}
F_28 ( V_150 -> V_80 >= V_29 ) ;
F_24 ( V_5 , V_150 -> V_80 , F_31 ( V_152 ) ,
V_41 -> V_81 , V_41 -> V_69 , V_39 ) ;
F_32 ( V_151 ) -> V_80 = 0 ;
F_23 ( V_151 ) ;
}
return V_64 ;
}
static int F_99 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
bool V_154 = false ;
if ( V_5 -> V_103 != V_104 && F_100 ( V_5 ) ) {
struct V_56 * V_57 = F_41 ( V_20 ) ;
F_101 ( & V_57 -> V_155 ) ;
V_5 -> V_103 = V_104 ;
V_154 = true ;
}
if ( V_5 -> V_103 != V_104 )
return 0 ;
return F_102 ( V_5 , V_154 ) ;
}
static int F_103 ( struct V_11 * V_12 ,
struct V_137 * V_156 )
{
struct V_96 * V_157 = F_70 ( V_12 -> V_30 -> V_157 ) ;
int V_158 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_96 ( V_156 ) ) != NULL ) {
int V_153 = F_97 ( V_5 ) -> V_153 ;
if ( V_153 > F_59 ( V_5 ) )
F_98 ( V_5 , V_153 - F_59 ( V_5 ) ) ;
V_5 -> V_159 = F_104 ( V_5 , V_12 -> V_30 -> V_31 ) ;
F_105 ( V_5 ) ;
if ( F_99 ( V_12 -> V_30 -> V_31 , V_5 ) ) {
F_23 ( V_5 ) ;
V_158 ++ ;
V_12 -> V_30 -> V_31 -> V_123 . V_160 ++ ;
continue;
}
F_80 ( & V_157 -> V_120 ) ;
V_157 -> V_121 ++ ;
V_157 -> V_90 += V_5 -> V_82 ;
F_81 ( & V_157 -> V_120 ) ;
F_106 ( & V_12 -> V_24 , V_5 ) ;
}
return V_158 ;
}
static int F_107 ( struct V_161 * V_24 , int V_162 )
{
struct V_11 * V_12 = F_108 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
struct V_10 * V_5 ;
struct V_135 V_136 ;
struct V_138 * V_41 = & V_136 . V_41 ;
struct V_109 * V_126 = V_136 . V_126 ;
T_1 V_14 , V_127 ;
int V_163 ;
struct V_137 V_156 ;
struct V_137 V_164 ;
struct V_137 V_165 ;
int V_130 ;
F_109 ( & V_12 -> V_61 ) ;
F_110 ( & V_156 ) ;
F_110 ( & V_164 ) ;
F_110 ( & V_165 ) ;
V_127 = V_12 -> V_41 . V_62 -> V_66 ;
F_48 () ;
V_14 = V_12 -> V_41 . V_27 ;
V_163 = 0 ;
while ( ( V_14 != V_127 ) && ( V_163 < V_162 ) ) {
memcpy ( V_41 , F_49 ( & V_12 -> V_41 , V_14 ) , sizeof( * V_41 ) ) ;
memset ( V_126 , 0 , sizeof( V_136 . V_126 ) ) ;
V_130 = F_91 ( V_12 , & V_136 , V_127 , & V_165 ) ;
if ( F_15 ( V_130 ) ) {
V_130:
while ( ( V_5 = F_96 ( & V_165 ) ) )
F_92 ( & V_164 , V_5 ) ;
V_20 -> V_123 . V_160 ++ ;
V_14 = V_12 -> V_41 . V_27 ;
continue;
}
V_5 = F_96 ( & V_165 ) ;
if ( V_126 [ V_118 - 1 ] . type ) {
struct V_109 * V_110 ;
V_110 = & V_126 [ V_118 - 1 ] ;
if ( F_15 ( F_93 ( V_5 , V_110 ) ) ) {
F_111 ( & V_165 , V_5 ) ;
V_12 -> V_41 . V_27 += F_112 ( & V_165 ) ;
goto V_130;
}
}
F_97 ( V_5 ) -> V_153 = V_41 -> V_69 ;
if ( F_97 ( V_5 ) -> V_153 > V_35 )
F_97 ( V_5 ) -> V_153 = V_35 ;
F_32 ( V_5 ) -> V_47 [ 0 ] . V_87 = V_41 -> V_81 ;
F_113 ( & F_32 ( V_5 ) -> V_47 [ 0 ] , V_41 -> V_69 ) ;
V_5 -> V_166 = V_41 -> V_69 ;
V_5 -> V_82 += V_41 -> V_69 ;
V_14 = F_95 ( V_12 , V_5 , & V_165 ) ;
if ( V_41 -> V_84 & V_167 )
V_5 -> V_103 = V_104 ;
else if ( V_41 -> V_84 & V_168 )
V_5 -> V_103 = V_107 ;
F_92 ( & V_156 , V_5 ) ;
V_12 -> V_41 . V_27 = ++ V_14 ;
V_163 ++ ;
}
F_114 ( & V_164 ) ;
V_163 -= F_103 ( V_12 , & V_156 ) ;
F_26 ( V_12 ) ;
if ( V_163 < V_162 ) {
int V_169 = 0 ;
F_115 ( V_24 ) ;
F_116 ( & V_12 -> V_41 , V_169 ) ;
if ( V_169 )
F_11 ( V_24 ) ;
}
F_117 ( & V_12 -> V_61 ) ;
return V_163 ;
}
static int F_118 ( struct V_19 * V_20 , int V_170 )
{
int V_139 = F_9 ( V_20 ) ?
V_101 - V_171 : V_172 ;
if ( V_170 > V_139 )
return - V_133 ;
V_20 -> V_170 = V_170 ;
return 0 ;
}
static struct V_173 * F_119 ( struct V_19 * V_20 ,
struct V_173 * V_174 )
{
struct V_56 * V_57 = F_41 ( V_20 ) ;
int V_175 ;
F_120 (cpu) {
struct V_96 * V_157 = F_121 ( V_57 -> V_157 , V_175 ) ;
struct V_96 * V_97 = F_121 ( V_57 -> V_97 , V_175 ) ;
T_7 V_176 , V_177 , V_178 , V_179 ;
unsigned int V_180 ;
do {
V_180 = F_122 ( & V_97 -> V_120 ) ;
V_178 = V_97 -> V_121 ;
V_179 = V_97 -> V_90 ;
} while ( F_123 ( & V_97 -> V_120 , V_180 ) );
do {
V_180 = F_122 ( & V_157 -> V_120 ) ;
V_176 = V_157 -> V_121 ;
V_177 = V_157 -> V_90 ;
} while ( F_123 ( & V_157 -> V_120 , V_180 ) );
V_174 -> V_176 += V_176 ;
V_174 -> V_178 += V_178 ;
V_174 -> V_177 += V_177 ;
V_174 -> V_179 += V_179 ;
}
V_174 -> V_160 = V_20 -> V_123 . V_160 ;
V_174 -> V_124 = V_20 -> V_123 . V_124 ;
return V_174 ;
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
F_55 ( V_5 ) ;
}
}
static void F_128 ( struct V_11 * V_12 )
{
int V_3 , V_16 ;
F_43 ( & V_12 -> V_61 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
struct V_10 * V_5 ;
struct V_34 * V_34 ;
V_5 = V_12 -> V_15 [ V_3 ] ;
if ( ! V_5 )
continue;
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 )
continue;
V_34 = F_31 ( & F_32 ( V_5 ) -> V_47 [ 0 ] ) ;
F_125 ( V_34 ) ;
F_126 ( V_16 , 0 ,
( unsigned long ) F_127 ( V_34 ) ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
F_23 ( V_5 ) ;
}
F_45 ( & V_12 -> V_61 ) ;
}
static T_8 F_129 ( struct V_19 * V_20 ,
T_8 V_21 )
{
struct V_56 * V_57 = F_41 ( V_20 ) ;
int V_181 ;
if ( V_21 & V_22 ) {
if ( F_130 ( V_182 , V_57 -> V_48 -> V_183 , L_12 ,
L_13 , & V_181 ) < 0 )
V_181 = 0 ;
if ( ! V_181 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_184 ) {
if ( F_130 ( V_182 , V_57 -> V_48 -> V_183 ,
L_14 , L_13 , & V_181 ) < 0 )
V_181 = 0 ;
if ( ! V_181 )
V_21 &= ~ V_184 ;
}
if ( V_21 & V_185 ) {
if ( F_130 ( V_182 , V_57 -> V_48 -> V_183 ,
L_15 , L_13 , & V_181 ) < 0 )
V_181 = 0 ;
if ( ! V_181 )
V_21 &= ~ V_185 ;
}
if ( V_21 & V_186 ) {
if ( F_130 ( V_182 , V_57 -> V_48 -> V_183 ,
L_16 , L_13 , & V_181 ) < 0 )
V_181 = 0 ;
if ( ! V_181 )
V_21 &= ~ V_186 ;
}
return V_21 ;
}
static int F_131 ( struct V_19 * V_20 ,
T_8 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_170 > V_172 ) {
F_132 ( V_20 , L_17 ) ;
V_20 -> V_170 = V_172 ;
}
return 0 ;
}
static T_9 F_133 ( int V_187 , void * V_188 )
{
struct V_11 * V_12 = V_188 ;
unsigned long V_84 ;
F_76 ( & V_12 -> V_102 , V_84 ) ;
F_47 ( V_12 ) ;
F_79 ( & V_12 -> V_102 , V_84 ) ;
return V_189 ;
}
static T_9 F_134 ( int V_187 , void * V_188 )
{
struct V_11 * V_12 = V_188 ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
if ( F_17 ( F_27 ( V_20 ) &&
F_44 ( & V_12 -> V_41 ) ) )
F_11 ( & V_12 -> V_24 ) ;
return V_189 ;
}
static T_9 F_135 ( int V_187 , void * V_188 )
{
F_133 ( V_187 , V_188 ) ;
F_134 ( V_187 , V_188 ) ;
return V_189 ;
}
static void F_136 ( struct V_19 * V_20 )
{
struct V_56 * V_30 = F_41 ( V_20 ) ;
unsigned int V_58 = V_20 -> V_59 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 )
F_135 ( 0 , & V_30 -> V_60 [ V_14 ] ) ;
}
static void F_137 ( struct V_19 * V_31 )
{
struct V_56 * V_57 = F_41 ( V_31 ) ;
F_138 ( V_57 -> V_157 ) ;
F_138 ( V_57 -> V_97 ) ;
F_139 ( V_31 ) ;
}
static struct V_19 * F_140 ( struct V_190 * V_20 )
{
int V_130 ;
struct V_19 * V_31 ;
struct V_56 * V_57 ;
V_31 = F_141 ( sizeof( struct V_56 ) , V_191 ) ;
if ( ! V_31 )
return F_142 ( - V_192 ) ;
V_57 = F_41 ( V_31 ) ;
V_57 -> V_48 = V_20 ;
F_143 ( V_31 , 0 ) ;
V_57 -> V_60 = NULL ;
V_130 = - V_192 ;
V_57 -> V_157 = F_144 ( struct V_96 ) ;
if ( V_57 -> V_157 == NULL )
goto exit;
V_57 -> V_97 = F_144 ( struct V_96 ) ;
if ( V_57 -> V_97 == NULL )
goto exit;
V_31 -> V_193 = & V_194 ;
V_31 -> V_21 = V_195 | V_196 |
V_197 ;
V_31 -> V_198 = V_22 |
V_184 |
V_185 | V_186 ;
V_31 -> V_21 |= V_31 -> V_198 ;
V_31 -> V_199 = & V_200 ;
F_145 ( V_31 , & V_20 -> V_20 ) ;
F_146 ( V_31 , V_101 - V_171 ) ;
V_57 -> V_31 = V_31 ;
F_147 ( V_31 ) ;
return V_31 ;
exit:
F_137 ( V_31 ) ;
return F_142 ( V_130 ) ;
}
static int F_148 ( struct V_190 * V_20 ,
const struct V_201 * V_3 )
{
int V_130 ;
struct V_19 * V_31 ;
struct V_56 * V_30 ;
V_31 = F_140 ( V_20 ) ;
if ( F_149 ( V_31 ) ) {
V_130 = F_150 ( V_31 ) ;
F_151 ( V_20 , V_130 , L_18 ) ;
return V_130 ;
}
V_30 = F_41 ( V_31 ) ;
F_152 ( & V_20 -> V_20 , V_30 ) ;
V_130 = F_153 ( V_30 -> V_31 ) ;
if ( V_130 ) {
F_94 ( L_19 , V_73 , V_130 ) ;
goto V_202;
}
V_130 = F_154 ( V_30 -> V_31 ) ;
if ( V_130 ) {
F_155 ( V_30 -> V_31 ) ;
F_94 ( L_20 , V_73 , V_130 ) ;
goto V_202;
}
return 0 ;
V_202:
F_137 ( V_31 ) ;
F_152 ( & V_20 -> V_20 , NULL ) ;
return V_130 ;
}
static void F_156 ( int V_16 , void * V_34 )
{
if ( V_16 != V_18 )
F_126 ( V_16 , 0 , ( unsigned long ) V_34 ) ;
}
static void F_157 ( struct V_56 * V_30 )
{
unsigned int V_14 = 0 ;
unsigned int V_58 = V_30 -> V_31 -> V_59 ;
F_147 ( V_30 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
struct V_11 * V_12 = & V_30 -> V_60 [ V_14 ] ;
if ( V_12 -> V_119 && ( V_12 -> V_119 == V_12 -> V_55 ) )
F_158 ( V_12 -> V_119 , V_12 ) ;
if ( V_12 -> V_119 && ( V_12 -> V_119 != V_12 -> V_55 ) ) {
F_158 ( V_12 -> V_119 , V_12 ) ;
F_158 ( V_12 -> V_55 , V_12 ) ;
}
V_12 -> V_203 = V_12 -> V_204 = 0 ;
V_12 -> V_119 = V_12 -> V_55 = 0 ;
F_159 ( & V_12 -> V_24 ) ;
F_124 ( V_12 ) ;
F_128 ( V_12 ) ;
F_160 ( V_12 -> V_75 ) ;
F_160 ( V_12 -> V_46 ) ;
F_156 ( V_12 -> V_205 , V_12 -> V_25 . V_62 ) ;
F_156 ( V_12 -> V_206 , V_12 -> V_41 . V_62 ) ;
V_12 -> V_205 = V_18 ;
V_12 -> V_206 = V_18 ;
V_12 -> V_25 . V_62 = NULL ;
V_12 -> V_41 . V_62 = NULL ;
}
}
static int F_161 ( struct V_190 * V_20 )
{
struct V_56 * V_30 = F_162 ( & V_20 -> V_20 ) ;
F_163 ( & V_20 -> V_20 , L_21 , V_20 -> V_207 ) ;
F_157 ( V_30 ) ;
return 0 ;
}
static int F_164 ( struct V_190 * V_20 , T_10 V_208 [] )
{
char * V_209 , * V_210 , * V_211 ;
int V_14 ;
V_211 = V_209 = F_165 ( V_182 , V_20 -> V_207 , L_22 , NULL ) ;
if ( F_149 ( V_211 ) )
return F_150 ( V_211 ) ;
for ( V_14 = 0 ; V_14 < V_212 ; V_14 ++ ) {
V_208 [ V_14 ] = F_166 ( V_209 , & V_210 , 16 ) ;
if ( ( V_209 == V_210 ) || ( * V_210 != ( ( V_14 == V_212 - 1 ) ? '\0' : ':' ) ) ) {
F_167 ( V_211 ) ;
return - V_144 ;
}
V_209 = V_210 + 1 ;
}
F_167 ( V_211 ) ;
return 0 ;
}
static int F_168 ( struct V_11 * V_12 )
{
int V_130 ;
V_130 = F_169 ( V_12 -> V_30 -> V_48 , & V_12 -> V_203 ) ;
if ( V_130 < 0 )
goto V_202;
V_130 = F_170 ( V_12 -> V_203 ,
F_135 ,
0 , V_12 -> V_30 -> V_31 -> V_213 , V_12 ) ;
if ( V_130 < 0 )
goto V_214;
V_12 -> V_204 = V_12 -> V_203 ;
V_12 -> V_55 = V_12 -> V_119 = V_130 ;
return 0 ;
V_214:
F_171 ( V_12 -> V_30 -> V_48 , V_12 -> V_203 ) ;
V_12 -> V_203 = 0 ;
V_202:
return V_130 ;
}
static int F_172 ( struct V_11 * V_12 )
{
int V_130 ;
V_130 = F_169 ( V_12 -> V_30 -> V_48 , & V_12 -> V_203 ) ;
if ( V_130 < 0 )
goto V_202;
V_130 = F_169 ( V_12 -> V_30 -> V_48 , & V_12 -> V_204 ) ;
if ( V_130 < 0 )
goto V_215;
snprintf ( V_12 -> V_216 , sizeof( V_12 -> V_216 ) ,
L_23 , V_12 -> V_213 ) ;
V_130 = F_170 ( V_12 -> V_203 ,
F_133 ,
0 , V_12 -> V_216 , V_12 ) ;
if ( V_130 < 0 )
goto V_217;
V_12 -> V_119 = V_130 ;
snprintf ( V_12 -> V_218 , sizeof( V_12 -> V_218 ) ,
L_24 , V_12 -> V_213 ) ;
V_130 = F_170 ( V_12 -> V_204 ,
F_134 ,
0 , V_12 -> V_218 , V_12 ) ;
if ( V_130 < 0 )
goto V_219;
V_12 -> V_55 = V_130 ;
return 0 ;
V_219:
F_158 ( V_12 -> V_119 , V_12 ) ;
V_12 -> V_119 = 0 ;
V_217:
F_171 ( V_12 -> V_30 -> V_48 , V_12 -> V_204 ) ;
V_12 -> V_204 = 0 ;
V_215:
F_171 ( V_12 -> V_30 -> V_48 , V_12 -> V_203 ) ;
V_12 -> V_203 = 0 ;
V_202:
return V_130 ;
}
static int F_173 ( struct V_190 * V_20 ,
struct V_11 * V_12 , unsigned int V_220 )
{
struct V_221 * V_222 ;
struct V_223 * V_224 ;
int V_130 ;
V_12 -> V_205 = V_18 ;
V_12 -> V_206 = V_18 ;
V_12 -> V_41 . V_62 = NULL ;
V_12 -> V_25 . V_62 = NULL ;
V_222 = (struct V_221 * ) F_174 ( V_225 | V_226 ) ;
if ( ! V_222 ) {
V_130 = - V_192 ;
F_151 ( V_20 , V_130 , L_25 ) ;
goto V_202;
}
F_175 ( V_222 ) ;
F_176 ( & V_12 -> V_25 , V_222 , V_39 ) ;
V_130 = F_177 ( V_20 , F_61 ( V_222 ) ) ;
if ( V_130 < 0 )
goto V_227;
V_12 -> V_205 = V_130 ;
V_224 = (struct V_223 * ) F_174 ( V_225 | V_226 ) ;
if ( ! V_224 ) {
V_130 = - V_192 ;
F_151 ( V_20 , V_130 , L_26 ) ;
goto V_228;
}
F_175 ( V_224 ) ;
F_176 ( & V_12 -> V_41 , V_224 , V_39 ) ;
V_130 = F_177 ( V_20 , F_61 ( V_224 ) ) ;
if ( V_130 < 0 )
goto V_229;
V_12 -> V_206 = V_130 ;
if ( V_220 )
V_130 = F_172 ( V_12 ) ;
if ( ! V_220 || ( V_220 && V_130 ) )
V_130 = F_168 ( V_12 ) ;
if ( V_130 )
goto V_230;
return 0 ;
V_230:
F_53 ( V_12 -> V_206 , 0 ) ;
V_229:
F_178 ( ( unsigned long ) V_224 ) ;
V_228:
F_53 ( V_12 -> V_205 , 0 ) ;
V_227:
F_178 ( ( unsigned long ) V_222 ) ;
V_202:
return V_130 ;
}
static int F_179 ( struct V_11 * V_12 )
{
unsigned short V_14 ;
int V_130 = 0 ;
F_180 ( & V_12 -> V_102 ) ;
F_180 ( & V_12 -> V_61 ) ;
F_181 ( & V_12 -> V_52 ) ;
V_12 -> V_52 . V_23 = ( unsigned long ) V_12 ;
V_12 -> V_52 . V_231 = F_10 ;
snprintf ( V_12 -> V_213 , sizeof( V_12 -> V_213 ) , L_27 ,
V_12 -> V_30 -> V_31 -> V_213 , V_12 -> V_3 ) ;
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
F_51 ( L_28 ) ;
V_130 = - V_192 ;
goto exit;
}
if ( F_182 ( V_9 ,
& V_12 -> V_46 ) < 0 ) {
F_51 ( L_29 ) ;
V_130 = - V_192 ;
goto V_232;
}
return 0 ;
V_232:
F_160 ( V_12 -> V_75 ) ;
exit:
return V_130 ;
}
static int F_183 ( struct V_11 * V_12 ,
struct V_233 * V_234 , int V_235 )
{
struct V_190 * V_20 = V_12 -> V_30 -> V_48 ;
int V_130 ;
const char * V_236 ;
char * V_237 ;
T_11 V_238 ;
if ( V_235 ) {
V_238 = strlen ( V_20 -> V_207 ) + 10 ;
V_237 = F_184 ( V_238 , V_239 ) ;
if ( ! V_237 ) {
V_130 = - V_192 ;
V_236 = L_30 ;
goto error;
}
snprintf ( V_237 , V_238 , L_31 ,
V_20 -> V_207 , V_12 -> V_3 ) ;
} else {
V_237 = ( char * ) V_20 -> V_207 ;
}
V_130 = F_185 ( * V_234 , V_237 , L_32 , L_33 ,
V_12 -> V_205 ) ;
if ( V_130 ) {
V_236 = L_34 ;
goto error;
}
V_130 = F_185 ( * V_234 , V_237 , L_35 , L_33 ,
V_12 -> V_206 ) ;
if ( V_130 ) {
V_236 = L_36 ;
goto error;
}
if ( V_12 -> V_203 == V_12 -> V_204 ) {
V_130 = F_185 ( * V_234 , V_237 ,
L_37 , L_33 , V_12 -> V_203 ) ;
if ( V_130 ) {
V_236 = L_38 ;
goto error;
}
} else {
V_130 = F_185 ( * V_234 , V_237 ,
L_39 , L_33 , V_12 -> V_203 ) ;
if ( V_130 ) {
V_236 = L_40 ;
goto error;
}
V_130 = F_185 ( * V_234 , V_237 ,
L_41 , L_33 , V_12 -> V_204 ) ;
if ( V_130 ) {
V_236 = L_42 ;
goto error;
}
}
if ( V_235 )
F_167 ( V_237 ) ;
return 0 ;
error:
if ( V_235 )
F_167 ( V_237 ) ;
F_151 ( V_20 , V_130 , L_43 , V_236 ) ;
return V_130 ;
}
static void F_186 ( struct V_56 * V_30 )
{
unsigned int V_14 ;
F_187 () ;
for ( V_14 = 0 ; V_14 < V_30 -> V_31 -> V_59 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_60 [ V_14 ] ;
if ( F_18 ( V_30 -> V_31 ) )
F_86 ( & V_12 -> V_24 ) ;
F_188 ( & V_12 -> V_24 ) ;
}
F_189 () ;
F_167 ( V_30 -> V_60 ) ;
V_30 -> V_60 = NULL ;
}
static int F_190 ( struct V_56 * V_30 ,
unsigned int V_58 )
{
unsigned int V_14 ;
int V_140 ;
V_30 -> V_60 = F_191 ( V_58 , sizeof( struct V_11 ) ,
V_239 ) ;
if ( ! V_30 -> V_60 )
return - V_192 ;
F_187 () ;
for ( V_14 = 0 ; V_14 < V_58 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_60 [ V_14 ] ;
V_12 -> V_3 = V_14 ;
V_12 -> V_30 = V_30 ;
V_140 = F_179 ( V_12 ) ;
if ( V_140 < 0 ) {
F_90 ( & V_30 -> V_31 -> V_20 ,
L_44 , V_14 ) ;
V_58 = V_14 ;
break;
}
F_192 ( V_12 -> V_30 -> V_31 , & V_12 -> V_24 ,
F_107 , 64 ) ;
if ( F_18 ( V_30 -> V_31 ) )
F_42 ( & V_12 -> V_24 ) ;
}
F_143 ( V_30 -> V_31 , V_58 ) ;
F_189 () ;
if ( V_58 == 0 ) {
F_193 ( & V_30 -> V_31 -> V_20 , L_45 ) ;
return - V_133 ;
}
return 0 ;
}
static int F_194 ( struct V_190 * V_20 ,
struct V_56 * V_30 )
{
const char * V_236 ;
struct V_233 V_234 ;
int V_130 ;
unsigned int V_220 ;
unsigned int V_14 = 0 ;
unsigned int V_240 = 0 ;
struct V_11 * V_12 = NULL ;
unsigned int V_58 = 1 ;
V_30 -> V_31 -> V_187 = 0 ;
V_130 = F_130 ( V_182 , V_30 -> V_48 -> V_183 ,
L_46 , L_33 , & V_240 ) ;
if ( V_130 < 0 )
V_240 = 1 ;
V_58 = F_195 ( V_240 , V_191 ) ;
V_130 = F_130 ( V_182 , V_30 -> V_48 -> V_183 ,
L_47 , L_33 ,
& V_220 ) ;
if ( V_130 < 0 )
V_220 = 0 ;
V_130 = F_164 ( V_20 , V_30 -> V_31 -> V_241 ) ;
if ( V_130 ) {
F_151 ( V_20 , V_130 , L_48 , V_20 -> V_207 ) ;
goto V_242;
}
if ( V_30 -> V_60 )
F_186 ( V_30 ) ;
V_130 = F_190 ( V_30 , V_58 ) ;
if ( V_130 < 0 )
goto V_243;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
V_12 = & V_30 -> V_60 [ V_14 ] ;
V_130 = F_173 ( V_20 , V_12 , V_220 ) ;
if ( V_130 ) {
if ( V_14 > 0 ) {
F_187 () ;
F_143 ( V_30 -> V_31 , V_14 ) ;
F_189 () ;
goto V_243;
} else {
goto V_242;
}
}
}
V_244:
V_130 = F_196 ( & V_234 ) ;
if ( V_130 ) {
F_151 ( V_20 , V_130 , L_49 ) ;
goto V_243;
}
if ( V_58 == 1 ) {
V_130 = F_183 ( & V_30 -> V_60 [ 0 ] , & V_234 , 0 ) ;
if ( V_130 )
goto V_245;
} else {
V_130 = F_185 ( V_234 , V_20 -> V_207 , L_50 ,
L_33 , V_58 ) ;
if ( V_130 ) {
V_236 = L_51 ;
goto V_245;
}
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
V_12 = & V_30 -> V_60 [ V_14 ] ;
V_130 = F_183 ( V_12 , & V_234 , 1 ) ;
if ( V_130 )
goto V_245;
}
}
V_130 = F_185 ( V_234 , V_20 -> V_207 , L_52 , L_33 ,
1 ) ;
if ( V_130 ) {
V_236 = L_53 ;
goto V_246;
}
V_130 = F_185 ( V_234 , V_20 -> V_207 , L_54 , L_13 , 1 ) ;
if ( V_130 ) {
V_236 = L_55 ;
goto V_246;
}
V_130 = F_185 ( V_234 , V_20 -> V_207 , L_12 , L_13 , 1 ) ;
if ( V_130 ) {
V_236 = L_56 ;
goto V_246;
}
V_130 = F_185 ( V_234 , V_20 -> V_207 , L_15 , L_13 , 1 ) ;
if ( V_130 ) {
V_236 = L_57 ;
goto V_246;
}
V_130 = F_197 ( V_234 , V_20 -> V_207 , L_16 , L_58 ) ;
if ( V_130 ) {
V_236 = L_59 ;
goto V_246;
}
V_130 = F_197 ( V_234 , V_20 -> V_207 , L_14 ,
L_58 ) ;
if ( V_130 ) {
V_236 = L_60 ;
goto V_246;
}
V_130 = F_198 ( V_234 , 0 ) ;
if ( V_130 ) {
if ( V_130 == - V_247 )
goto V_244;
F_151 ( V_20 , V_130 , L_61 ) ;
goto V_243;
}
return 0 ;
V_246:
F_151 ( V_20 , V_130 , L_43 , V_236 ) ;
V_245:
F_198 ( V_234 , 1 ) ;
V_243:
F_157 ( V_30 ) ;
F_167 ( V_30 -> V_60 ) ;
V_30 -> V_60 = NULL ;
F_187 () ;
F_143 ( V_30 -> V_31 , 0 ) ;
F_189 () ;
V_242:
return V_130 ;
}
static int F_199 ( struct V_19 * V_20 )
{
struct V_56 * V_57 = F_41 ( V_20 ) ;
unsigned int V_58 = 0 ;
int V_130 ;
unsigned int V_248 ;
unsigned int V_249 = 0 ;
struct V_11 * V_12 = NULL ;
V_130 = F_130 ( V_182 , V_57 -> V_48 -> V_183 ,
L_62 , L_33 , & V_248 ) ;
if ( V_130 != 1 )
V_248 = 0 ;
if ( ! V_248 ) {
F_200 ( & V_20 -> V_20 ,
L_63 ) ;
return - V_250 ;
}
V_130 = F_194 ( V_57 -> V_48 , V_57 ) ;
if ( V_130 )
return V_130 ;
V_58 = V_20 -> V_59 ;
F_187 () ;
F_201 ( V_20 ) ;
F_189 () ;
F_202 ( V_57 -> V_31 ) ;
for ( V_249 = 0 ; V_249 < V_58 ; ++ V_249 ) {
V_12 = & V_57 -> V_60 [ V_249 ] ;
F_39 ( V_12 -> V_119 ) ;
if ( V_12 -> V_119 != V_12 -> V_55 )
F_39 ( V_12 -> V_55 ) ;
F_203 ( & V_12 -> V_102 ) ;
F_47 ( V_12 ) ;
F_204 ( & V_12 -> V_102 ) ;
F_43 ( & V_12 -> V_61 ) ;
F_26 ( V_12 ) ;
F_45 ( & V_12 -> V_61 ) ;
}
return 0 ;
}
static void F_205 ( struct V_190 * V_20 ,
enum V_251 V_252 )
{
struct V_56 * V_57 = F_162 ( & V_20 -> V_20 ) ;
struct V_19 * V_31 = V_57 -> V_31 ;
F_163 ( & V_20 -> V_20 , L_21 , F_206 ( V_252 ) ) ;
switch ( V_252 ) {
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
break;
case V_258 :
if ( V_20 -> V_259 != V_253 )
break;
if ( F_199 ( V_31 ) != 0 )
break;
F_207 ( V_20 , V_260 ) ;
break;
case V_260 :
F_208 ( V_31 ) ;
break;
case V_261 :
if ( V_20 -> V_259 == V_261 )
break;
case V_262 :
F_209 ( V_20 ) ;
break;
}
}
static int F_210 ( struct V_19 * V_20 , int V_263 )
{
switch ( V_263 ) {
case V_264 :
return F_211 ( V_265 ) ;
default:
return - V_133 ;
}
}
static void F_212 ( struct V_19 * V_20 ,
struct V_266 * V_123 , T_7 * V_23 )
{
void * V_57 = F_41 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_211 ( V_265 ) ; V_14 ++ )
V_23 [ V_14 ] = F_213 ( ( V_267 * ) ( V_57 + V_265 [ V_14 ] . V_81 ) ) ;
}
static void F_214 ( struct V_19 * V_20 , T_6 V_268 , T_10 * V_23 )
{
int V_14 ;
switch ( V_268 ) {
case V_264 :
for ( V_14 = 0 ; V_14 < F_211 ( V_265 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_269 ,
V_265 [ V_14 ] . V_213 , V_269 ) ;
break;
}
}
static T_12 F_215 ( struct V_129 * V_20 ,
struct V_270 * V_271 , char * V_272 )
{
return sprintf ( V_272 , L_64 , V_9 ) ;
}
static T_12 F_216 ( struct V_129 * V_20 ,
struct V_270 * V_271 ,
const char * V_272 , T_11 V_82 )
{
char * V_273 ;
unsigned long V_274 ;
if ( ! F_217 ( V_275 ) )
return - V_276 ;
V_274 = F_166 ( V_272 , & V_273 , 0 ) ;
if ( V_273 == V_272 )
return - V_277 ;
return V_82 ;
}
static int F_154 ( struct V_19 * V_31 )
{
int V_14 ;
int V_130 ;
for ( V_14 = 0 ; V_14 < F_211 ( V_278 ) ; V_14 ++ ) {
V_130 = F_218 ( & V_31 -> V_20 ,
& V_278 [ V_14 ] ) ;
if ( V_130 )
goto V_202;
}
return 0 ;
V_202:
while ( -- V_14 >= 0 )
F_219 ( & V_31 -> V_20 , & V_278 [ V_14 ] ) ;
return V_130 ;
}
static void F_220 ( struct V_19 * V_31 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_211 ( V_278 ) ; V_14 ++ )
F_219 ( & V_31 -> V_20 , & V_278 [ V_14 ] ) ;
}
static int F_221 ( struct V_190 * V_20 )
{
struct V_56 * V_30 = F_162 ( & V_20 -> V_20 ) ;
unsigned int V_58 = V_30 -> V_31 -> V_59 ;
struct V_11 * V_12 = NULL ;
unsigned int V_14 = 0 ;
F_163 ( & V_20 -> V_20 , L_21 , V_20 -> V_207 ) ;
F_157 ( V_30 ) ;
F_220 ( V_30 -> V_31 ) ;
F_155 ( V_30 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_58 ; ++ V_14 ) {
V_12 = & V_30 -> V_60 [ V_14 ] ;
F_222 ( & V_12 -> V_52 ) ;
}
if ( V_58 ) {
F_167 ( V_30 -> V_60 ) ;
V_30 -> V_60 = NULL ;
}
F_137 ( V_30 -> V_31 ) ;
return 0 ;
}
static int T_13 F_223 ( void )
{
if ( ! F_224 () )
return - V_250 ;
if ( ! F_225 () )
return - V_250 ;
F_226 ( L_65 ) ;
V_191 = F_227 () ;
return F_228 ( & V_279 ) ;
}
static void T_14 F_229 ( void )
{
F_230 ( & V_279 ) ;
}
