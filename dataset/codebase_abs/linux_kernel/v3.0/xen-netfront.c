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
static int F_9 ( struct V_19 * V_20 )
{
return V_20 -> V_21 & V_22 ;
}
static void F_10 ( unsigned long V_23 )
{
struct V_19 * V_20 = (struct V_19 * ) V_23 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_12 ( & V_12 -> V_24 ) ;
}
static int F_13 ( struct V_11 * V_12 )
{
return ( V_12 -> V_25 . V_26 - V_12 -> V_25 . V_27 ) <
( V_28 - V_29 - 2 ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
if ( F_15 ( F_16 ( V_20 ) ) &&
F_13 ( V_12 ) &&
F_17 ( F_18 ( V_20 ) ) )
F_19 ( V_20 ) ;
}
static void F_20 ( struct V_19 * V_20 )
{
unsigned short V_3 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_10 * V_5 ;
struct V_30 * V_30 ;
int V_14 , V_31 , V_32 ;
T_1 V_33 = V_12 -> V_34 . V_26 ;
T_2 V_16 ;
unsigned long V_35 ;
void * V_36 ;
struct V_37 * V_38 ;
if ( F_15 ( ! F_21 ( V_20 ) ) )
return;
V_31 = V_12 -> V_39 - ( V_33 - V_12 -> V_34 . V_27 ) ;
for ( V_14 = F_22 ( & V_12 -> V_40 ) ; V_14 < V_31 ; V_14 ++ ) {
V_5 = F_23 ( V_20 , V_41 + V_42 ,
V_43 | V_44 ) ;
if ( F_15 ( ! V_5 ) )
goto V_45;
F_24 ( V_5 , V_42 ) ;
V_30 = F_25 ( V_43 | V_44 ) ;
if ( ! V_30 ) {
F_26 ( V_5 ) ;
V_45:
if ( V_14 != 0 )
goto V_46;
F_27 ( & V_12 -> V_47 ,
V_48 + ( V_49 / 10 ) ) ;
break;
}
F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 = V_30 ;
F_28 ( V_5 ) -> V_51 = 1 ;
F_29 ( & V_12 -> V_40 , V_5 ) ;
}
if ( V_14 < ( V_12 -> V_39 / 2 ) ) {
if ( V_33 > V_12 -> V_34 . V_52 -> V_33 )
goto V_53;
return;
}
if ( ( ( V_33 - V_12 -> V_34 . V_52 -> V_54 ) < ( V_12 -> V_39 / 4 ) ) &&
( ( V_12 -> V_39 *= 2 ) > V_12 -> V_55 ) )
V_12 -> V_39 = V_12 -> V_55 ;
V_46:
for ( V_14 = 0 ; ; V_14 ++ ) {
V_5 = F_30 ( & V_12 -> V_40 ) ;
if ( V_5 == NULL )
break;
V_5 -> V_20 = V_20 ;
V_3 = F_6 ( V_33 + V_14 ) ;
F_31 ( V_12 -> V_15 [ V_3 ] ) ;
V_12 -> V_15 [ V_3 ] = V_5 ;
V_16 = F_32 ( & V_12 -> V_56 ) ;
F_31 ( ( signed short ) V_16 < 0 ) ;
V_12 -> V_17 [ V_3 ] = V_16 ;
V_35 = F_33 ( F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 ) ;
V_36 = F_34 ( F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 ) ;
V_38 = F_35 ( & V_12 -> V_34 , V_33 + V_14 ) ;
F_36 ( V_16 ,
V_12 -> V_57 -> V_58 ,
F_37 ( V_35 ) ,
0 ) ;
V_38 -> V_3 = V_3 ;
V_38 -> V_59 = V_16 ;
}
F_38 () ;
V_12 -> V_34 . V_26 = V_33 + V_14 ;
V_53:
F_39 ( & V_12 -> V_34 , V_32 ) ;
if ( V_32 )
F_40 ( V_12 -> V_60 -> V_61 ) ;
}
static int F_41 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_42 ( & V_12 -> V_24 ) ;
F_43 ( & V_12 -> V_62 ) ;
if ( F_21 ( V_20 ) ) {
F_20 ( V_20 ) ;
V_12 -> V_34 . V_52 -> V_63 = V_12 -> V_34 . V_27 + 1 ;
if ( F_44 ( & V_12 -> V_34 ) )
F_12 ( & V_12 -> V_24 ) ;
}
F_45 ( & V_12 -> V_62 ) ;
F_46 ( V_20 ) ;
return 0 ;
}
static void F_47 ( struct V_19 * V_20 )
{
T_1 V_64 , V_65 ;
unsigned short V_3 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_10 * V_5 ;
F_31 ( ! F_21 ( V_20 ) ) ;
do {
V_65 = V_12 -> V_25 . V_52 -> V_54 ;
F_48 () ;
for ( V_64 = V_12 -> V_25 . V_27 ; V_64 != V_65 ; V_64 ++ ) {
struct V_66 * V_67 ;
V_67 = F_49 ( & V_12 -> V_25 , V_64 ) ;
if ( V_67 -> V_68 == V_69 )
continue;
V_3 = V_67 -> V_3 ;
V_5 = V_12 -> V_70 [ V_3 ] . V_5 ;
if ( F_15 ( F_50 (
V_12 -> V_71 [ V_3 ] ) != 0 ) ) {
F_51 ( V_72 L_1
L_2
L_3 ) ;
F_52 () ;
}
F_53 (
V_12 -> V_71 [ V_3 ] , V_73 ) ;
F_54 (
& V_12 -> V_74 , V_12 -> V_71 [ V_3 ] ) ;
V_12 -> V_71 [ V_3 ] = V_18 ;
F_4 ( & V_12 -> V_75 , V_12 -> V_70 , V_3 ) ;
F_55 ( V_5 ) ;
}
V_12 -> V_25 . V_27 = V_65 ;
V_12 -> V_25 . V_52 -> V_63 =
V_65 + ( ( V_12 -> V_25 . V_52 -> V_33 - V_65 ) >> 1 ) + 1 ;
F_56 () ;
} while ( ( V_64 == V_65 ) && ( V_65 != V_12 -> V_25 . V_52 -> V_54 ) );
F_14 ( V_20 ) ;
}
static void F_57 ( struct V_10 * V_5 , struct V_19 * V_20 ,
struct V_76 * V_25 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
char * V_23 = V_5 -> V_23 ;
unsigned long V_77 ;
T_1 V_65 = V_12 -> V_25 . V_26 ;
int V_50 = F_28 ( V_5 ) -> V_51 ;
unsigned int V_78 = F_58 ( V_23 ) ;
unsigned int V_79 = F_59 ( V_5 ) ;
unsigned int V_3 ;
T_2 V_16 ;
int V_14 ;
while ( V_79 > V_80 - V_78 ) {
V_25 -> V_81 = V_80 - V_78 ;
V_25 -> V_82 |= V_83 ;
V_79 -= V_25 -> V_81 ;
V_23 += V_25 -> V_81 ;
V_78 = 0 ;
V_3 = F_5 ( & V_12 -> V_75 , V_12 -> V_70 ) ;
V_12 -> V_70 [ V_3 ] . V_5 = F_60 ( V_5 ) ;
V_25 = F_35 ( & V_12 -> V_25 , V_65 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_32 ( & V_12 -> V_74 ) ;
F_31 ( ( signed short ) V_16 < 0 ) ;
V_77 = F_61 ( V_23 ) ;
F_36 ( V_16 , V_12 -> V_57 -> V_58 ,
V_77 , V_73 ) ;
V_25 -> V_59 = V_12 -> V_71 [ V_3 ] = V_16 ;
V_25 -> V_78 = V_78 ;
V_25 -> V_81 = V_79 ;
V_25 -> V_82 = 0 ;
}
for ( V_14 = 0 ; V_14 < V_50 ; V_14 ++ ) {
T_3 * V_84 = F_28 ( V_5 ) -> V_50 + V_14 ;
V_25 -> V_82 |= V_83 ;
V_3 = F_5 ( & V_12 -> V_75 , V_12 -> V_70 ) ;
V_12 -> V_70 [ V_3 ] . V_5 = F_60 ( V_5 ) ;
V_25 = F_35 ( & V_12 -> V_25 , V_65 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_32 ( & V_12 -> V_74 ) ;
F_31 ( ( signed short ) V_16 < 0 ) ;
V_77 = F_37 ( F_33 ( V_84 -> V_30 ) ) ;
F_36 ( V_16 , V_12 -> V_57 -> V_58 ,
V_77 , V_73 ) ;
V_25 -> V_59 = V_12 -> V_71 [ V_3 ] = V_16 ;
V_25 -> V_78 = V_84 -> V_85 ;
V_25 -> V_81 = V_84 -> V_81 ;
V_25 -> V_82 = 0 ;
}
V_12 -> V_25 . V_26 = V_65 ;
}
static int F_62 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
unsigned short V_3 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_76 * V_25 ;
struct V_86 * V_87 ;
char * V_23 = V_5 -> V_23 ;
T_1 V_14 ;
T_2 V_16 ;
unsigned long V_77 ;
int V_32 ;
int V_50 = F_28 ( V_5 ) -> V_51 ;
unsigned int V_78 = F_58 ( V_23 ) ;
unsigned int V_79 = F_59 ( V_5 ) ;
V_50 += F_63 ( V_78 + V_79 , V_80 ) ;
if ( F_15 ( V_50 > V_29 + 1 ) ) {
F_51 ( V_72 L_4 ,
V_50 ) ;
F_64 () ;
goto V_88;
}
F_65 ( & V_12 -> V_89 ) ;
if ( F_15 ( ! F_21 ( V_20 ) ||
( V_50 > 1 && ! F_9 ( V_20 ) ) ||
F_66 ( V_5 , F_67 ( V_5 ) ) ) ) {
F_68 ( & V_12 -> V_89 ) ;
goto V_88;
}
V_14 = V_12 -> V_25 . V_26 ;
V_3 = F_5 ( & V_12 -> V_75 , V_12 -> V_70 ) ;
V_12 -> V_70 [ V_3 ] . V_5 = V_5 ;
V_25 = F_35 ( & V_12 -> V_25 , V_14 ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_32 ( & V_12 -> V_74 ) ;
F_31 ( ( signed short ) V_16 < 0 ) ;
V_77 = F_61 ( V_23 ) ;
F_36 (
V_16 , V_12 -> V_57 -> V_58 , V_77 , V_73 ) ;
V_25 -> V_59 = V_12 -> V_71 [ V_3 ] = V_16 ;
V_25 -> V_78 = V_78 ;
V_25 -> V_81 = V_79 ;
V_87 = NULL ;
V_25 -> V_82 = 0 ;
if ( V_5 -> V_90 == V_91 )
V_25 -> V_82 |= V_92 | V_93 ;
else if ( V_5 -> V_90 == V_94 )
V_25 -> V_82 |= V_93 ;
if ( F_28 ( V_5 ) -> V_95 ) {
struct V_86 * V_96 ;
V_96 = (struct V_86 * )
F_35 ( & V_12 -> V_25 , ++ V_14 ) ;
if ( V_87 )
V_87 -> V_82 |= V_97 ;
else
V_25 -> V_82 |= V_98 ;
V_96 -> V_99 . V_96 . V_81 = F_28 ( V_5 ) -> V_95 ;
V_96 -> V_99 . V_96 . type = V_100 ;
V_96 -> V_99 . V_96 . V_101 = 0 ;
V_96 -> V_99 . V_96 . V_21 = 0 ;
V_96 -> type = V_102 ;
V_96 -> V_82 = 0 ;
V_87 = V_96 ;
}
V_12 -> V_25 . V_26 = V_14 + 1 ;
F_57 ( V_5 , V_20 , V_25 ) ;
V_25 -> V_81 = V_5 -> V_79 ;
F_39 ( & V_12 -> V_25 , V_32 ) ;
if ( V_32 )
F_40 ( V_12 -> V_60 -> V_61 ) ;
V_20 -> V_103 . V_104 += V_5 -> V_79 ;
V_20 -> V_103 . V_105 ++ ;
F_47 ( V_20 ) ;
if ( ! F_13 ( V_12 ) )
F_69 ( V_20 ) ;
F_68 ( & V_12 -> V_89 ) ;
return V_106 ;
V_88:
V_20 -> V_103 . V_107 ++ ;
F_70 ( V_5 ) ;
return V_106 ;
}
static int F_71 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_69 ( V_12 -> V_60 ) ;
F_72 ( & V_12 -> V_24 ) ;
return 0 ;
}
static void F_73 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_108 = F_6 ( V_12 -> V_34 . V_26 ) ;
F_31 ( V_12 -> V_15 [ V_108 ] ) ;
V_12 -> V_15 [ V_108 ] = V_5 ;
V_12 -> V_17 [ V_108 ] = V_16 ;
F_35 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_3 = V_108 ;
F_35 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_59 = V_16 ;
V_12 -> V_34 . V_26 ++ ;
}
static int F_74 ( struct V_11 * V_12 ,
struct V_86 * V_109 ,
T_1 V_110 )
{
struct V_86 * V_87 ;
struct V_111 * V_20 = & V_12 -> V_60 -> V_20 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
int V_112 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_64 + 1 == V_110 ) ) {
if ( F_75 () )
F_76 ( V_20 , L_5 ) ;
V_112 = - V_113 ;
break;
}
V_87 = (struct V_86 * )
F_49 ( & V_12 -> V_34 , ++ V_64 ) ;
if ( F_15 ( ! V_87 -> type ||
V_87 -> type >= V_114 ) ) {
if ( F_75 () )
F_76 ( V_20 , L_6 ,
V_87 -> type ) ;
V_112 = - V_115 ;
} else {
memcpy ( & V_109 [ V_87 -> type - 1 ] , V_87 ,
sizeof( * V_87 ) ) ;
}
V_5 = F_7 ( V_12 , V_64 ) ;
V_16 = F_8 ( V_12 , V_64 ) ;
F_73 ( V_12 , V_5 , V_16 ) ;
} while ( V_87 -> V_82 & V_97 );
V_12 -> V_34 . V_27 = V_64 ;
return V_112 ;
}
static int F_77 ( struct V_11 * V_12 ,
struct V_116 * V_117 , T_1 V_110 ,
struct V_118 * V_2 )
{
struct V_119 * V_34 = & V_117 -> V_34 ;
struct V_86 * V_109 = V_117 -> V_109 ;
struct V_111 * V_20 = & V_12 -> V_60 -> V_20 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_64 ) ;
T_2 V_16 = F_8 ( V_12 , V_64 ) ;
int V_120 = V_29 + ( V_34 -> V_68 <= V_41 ) ;
int V_50 = 1 ;
int V_112 = 0 ;
unsigned long V_121 ;
if ( V_34 -> V_82 & V_122 ) {
V_112 = F_74 ( V_12 , V_109 , V_110 ) ;
V_64 = V_12 -> V_34 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_34 -> V_68 < 0 ||
V_34 -> V_78 + V_34 -> V_68 > V_80 ) ) {
if ( F_75 () )
F_76 ( V_20 , L_7 ,
V_34 -> V_78 , V_34 -> V_68 ) ;
F_73 ( V_12 , V_5 , V_16 ) ;
V_112 = - V_115 ;
goto V_123;
}
if ( V_16 == V_18 ) {
if ( F_75 () )
F_76 ( V_20 , L_8 ,
V_34 -> V_3 ) ;
V_112 = - V_115 ;
goto V_123;
}
V_121 = F_53 ( V_16 , 0 ) ;
F_31 ( ! V_121 ) ;
F_54 ( & V_12 -> V_56 , V_16 ) ;
F_29 ( V_2 , V_5 ) ;
V_123:
if ( ! ( V_34 -> V_82 & V_124 ) )
break;
if ( V_64 + V_50 == V_110 ) {
if ( F_75 () )
F_76 ( V_20 , L_9 ) ;
V_112 = - V_125 ;
break;
}
V_34 = F_49 ( & V_12 -> V_34 , V_64 + V_50 ) ;
V_5 = F_7 ( V_12 , V_64 + V_50 ) ;
V_16 = F_8 ( V_12 , V_64 + V_50 ) ;
V_50 ++ ;
}
if ( F_15 ( V_50 > V_120 ) ) {
if ( F_75 () )
F_76 ( V_20 , L_10 ) ;
V_112 = - V_126 ;
}
if ( F_15 ( V_112 ) )
V_12 -> V_34 . V_27 = V_64 + V_50 ;
return V_112 ;
}
static int F_78 ( struct V_10 * V_5 ,
struct V_86 * V_96 )
{
if ( ! V_96 -> V_99 . V_96 . V_81 ) {
if ( F_75 () )
F_51 ( V_127 L_11 ) ;
return - V_115 ;
}
if ( V_96 -> V_99 . V_96 . type != V_100 ) {
if ( F_75 () )
F_51 ( V_127 L_12 , V_96 -> V_99 . V_96 . type ) ;
return - V_115 ;
}
F_28 ( V_5 ) -> V_95 = V_96 -> V_99 . V_96 . V_81 ;
F_28 ( V_5 ) -> V_128 = V_129 ;
F_28 ( V_5 ) -> V_128 |= V_130 ;
F_28 ( V_5 ) -> V_131 = 0 ;
return 0 ;
}
static T_1 F_79 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_118 * V_2 )
{
struct V_132 * V_133 = F_28 ( V_5 ) ;
int V_51 = V_133 -> V_51 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
T_3 * V_84 = V_133 -> V_50 + V_51 ;
struct V_10 * V_134 ;
while ( ( V_134 = F_30 ( V_2 ) ) ) {
struct V_119 * V_34 =
F_49 ( & V_12 -> V_34 , ++ V_64 ) ;
V_84 -> V_30 = F_28 ( V_134 ) -> V_50 [ 0 ] . V_30 ;
V_84 -> V_85 = V_34 -> V_78 ;
V_84 -> V_81 = V_34 -> V_68 ;
V_5 -> V_135 += V_34 -> V_68 ;
F_28 ( V_134 ) -> V_51 = 0 ;
F_26 ( V_134 ) ;
V_84 ++ ;
V_51 ++ ;
}
V_133 -> V_51 = V_51 ;
return V_64 ;
}
static int F_80 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
struct V_136 * V_137 ;
unsigned char * V_138 ;
int V_112 = - V_139 ;
int V_140 = 0 ;
if ( V_5 -> V_90 != V_91 && F_81 ( V_5 ) ) {
struct V_11 * V_12 = F_11 ( V_20 ) ;
V_12 -> V_141 ++ ;
V_5 -> V_90 = V_91 ;
V_140 = 1 ;
}
if ( V_5 -> V_90 != V_91 )
return 0 ;
if ( V_5 -> V_142 != F_82 ( V_143 ) )
goto V_144;
V_137 = ( void * ) V_5 -> V_23 ;
V_138 = V_5 -> V_23 + 4 * V_137 -> V_145 ;
if ( V_138 >= F_83 ( V_5 ) )
goto V_144;
V_5 -> V_146 = V_138 - V_5 -> V_7 ;
switch ( V_137 -> V_142 ) {
case V_147 :
V_5 -> V_148 = F_84 ( struct V_149 , V_150 ) ;
if ( V_140 ) {
struct V_149 * V_151 = (struct V_149 * ) V_138 ;
V_151 -> V_150 = ~ F_85 ( V_137 -> V_152 , V_137 -> V_153 ,
V_5 -> V_79 - V_137 -> V_145 * 4 ,
V_147 , 0 ) ;
}
break;
case V_154 :
V_5 -> V_148 = F_84 ( struct V_155 , V_150 ) ;
if ( V_140 ) {
struct V_155 * V_156 = (struct V_155 * ) V_138 ;
V_156 -> V_150 = ~ F_85 ( V_137 -> V_152 , V_137 -> V_153 ,
V_5 -> V_79 - V_137 -> V_145 * 4 ,
V_154 , 0 ) ;
}
break;
default:
if ( F_75 () )
F_51 ( V_157 L_13
L_14
L_15 , V_137 -> V_142 ) ;
goto V_144;
}
if ( ( V_138 + V_5 -> V_148 + 2 ) > F_83 ( V_5 ) )
goto V_144;
V_112 = 0 ;
V_144:
return V_112 ;
}
static int F_86 ( struct V_19 * V_20 ,
struct V_118 * V_158 )
{
int V_159 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_30 ( V_158 ) ) != NULL ) {
struct V_30 * V_30 = F_87 ( V_5 ) -> V_30 ;
void * V_36 = F_34 ( V_30 ) ;
unsigned V_78 = F_87 ( V_5 ) -> V_78 ;
memcpy ( V_5 -> V_23 , V_36 + V_78 ,
F_59 ( V_5 ) ) ;
if ( V_30 != F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 )
F_88 ( V_30 ) ;
V_5 -> V_142 = F_89 ( V_5 , V_20 ) ;
if ( F_80 ( V_20 , V_5 ) ) {
F_26 ( V_5 ) ;
V_159 ++ ;
V_20 -> V_103 . V_160 ++ ;
continue;
}
V_20 -> V_103 . V_161 ++ ;
V_20 -> V_103 . V_162 += V_5 -> V_79 ;
F_90 ( V_5 ) ;
}
return V_159 ;
}
static int F_91 ( struct V_163 * V_24 , int V_164 )
{
struct V_11 * V_12 = F_92 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_60 ;
struct V_10 * V_5 ;
struct V_116 V_117 ;
struct V_119 * V_34 = & V_117 . V_34 ;
struct V_86 * V_109 = V_117 . V_109 ;
T_1 V_14 , V_110 ;
int V_165 ;
struct V_118 V_158 ;
struct V_118 V_166 ;
struct V_118 V_167 ;
unsigned long V_82 ;
unsigned int V_79 ;
int V_112 ;
F_93 ( & V_12 -> V_62 ) ;
F_94 ( & V_158 ) ;
F_94 ( & V_166 ) ;
F_94 ( & V_167 ) ;
V_110 = V_12 -> V_34 . V_52 -> V_54 ;
F_48 () ;
V_14 = V_12 -> V_34 . V_27 ;
V_165 = 0 ;
while ( ( V_14 != V_110 ) && ( V_165 < V_164 ) ) {
memcpy ( V_34 , F_49 ( & V_12 -> V_34 , V_14 ) , sizeof( * V_34 ) ) ;
memset ( V_109 , 0 , sizeof( V_117 . V_109 ) ) ;
V_112 = F_77 ( V_12 , & V_117 , V_110 , & V_167 ) ;
if ( F_15 ( V_112 ) ) {
V_112:
while ( ( V_5 = F_30 ( & V_167 ) ) )
F_29 ( & V_166 , V_5 ) ;
V_20 -> V_103 . V_160 ++ ;
V_14 = V_12 -> V_34 . V_27 ;
continue;
}
V_5 = F_30 ( & V_167 ) ;
if ( V_109 [ V_102 - 1 ] . type ) {
struct V_86 * V_96 ;
V_96 = & V_109 [ V_102 - 1 ] ;
if ( F_15 ( F_78 ( V_5 , V_96 ) ) ) {
F_95 ( & V_167 , V_5 ) ;
V_12 -> V_34 . V_27 += F_22 ( & V_167 ) ;
goto V_112;
}
}
F_87 ( V_5 ) -> V_30 = F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 ;
F_87 ( V_5 ) -> V_78 = V_34 -> V_78 ;
V_79 = V_34 -> V_68 ;
if ( V_79 > V_41 )
V_79 = V_41 ;
F_96 ( V_5 , V_79 ) ;
if ( V_34 -> V_68 > V_79 ) {
F_28 ( V_5 ) -> V_50 [ 0 ] . V_85 =
V_34 -> V_78 + V_79 ;
F_28 ( V_5 ) -> V_50 [ 0 ] . V_81 = V_34 -> V_68 - V_79 ;
V_5 -> V_135 = V_34 -> V_68 - V_79 ;
} else {
F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 = NULL ;
F_28 ( V_5 ) -> V_51 = 0 ;
}
V_14 = F_79 ( V_12 , V_5 , & V_167 ) ;
V_5 -> V_168 += V_5 -> V_135 - ( V_41 - V_79 ) ;
V_5 -> V_79 += V_5 -> V_135 ;
if ( V_34 -> V_82 & V_169 )
V_5 -> V_90 = V_91 ;
else if ( V_34 -> V_82 & V_170 )
V_5 -> V_90 = V_94 ;
F_29 ( & V_158 , V_5 ) ;
V_12 -> V_34 . V_27 = ++ V_14 ;
V_165 ++ ;
}
F_97 ( & V_166 ) ;
V_165 -= F_86 ( V_20 , & V_158 ) ;
if ( ( ( V_12 -> V_34 . V_26 - V_12 -> V_34 . V_52 -> V_54 ) >
( ( 3 * V_12 -> V_39 ) / 4 ) ) &&
( -- V_12 -> V_39 < V_12 -> V_171 ) )
V_12 -> V_39 = V_12 -> V_171 ;
F_20 ( V_20 ) ;
if ( V_165 < V_164 ) {
int V_172 = 0 ;
F_98 ( V_82 ) ;
F_99 ( & V_12 -> V_34 , V_172 ) ;
if ( ! V_172 )
F_100 ( V_24 ) ;
F_101 ( V_82 ) ;
}
F_102 ( & V_12 -> V_62 ) ;
return V_165 ;
}
static int F_103 ( struct V_19 * V_20 , int V_173 )
{
int V_120 = F_9 ( V_20 ) ? 65535 - V_174 : V_175 ;
if ( V_173 > V_120 )
return - V_115 ;
V_20 -> V_173 = V_173 ;
return 0 ;
}
static void F_104 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_176 ; V_14 ++ ) {
if ( F_2 ( & V_12 -> V_70 [ V_14 ] ) )
continue;
V_5 = V_12 -> V_70 [ V_14 ] . V_5 ;
F_53 ( V_12 -> V_71 [ V_14 ] ,
V_73 ) ;
F_54 ( & V_12 -> V_74 ,
V_12 -> V_71 [ V_14 ] ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
F_4 ( & V_12 -> V_75 , V_12 -> V_70 , V_14 ) ;
F_55 ( V_5 ) ;
}
}
static void F_105 ( struct V_11 * V_12 )
{
struct V_177 * V_178 = V_12 -> V_179 ;
struct V_180 * V_181 = V_12 -> V_182 ;
struct V_118 V_183 ;
struct V_10 * V_5 ;
unsigned long V_77 ;
int V_184 = 0 , V_185 = 0 , V_186 = 0 ;
int V_3 , V_16 ;
F_76 ( & V_12 -> V_60 -> V_20 , L_16 ,
V_187 ) ;
return;
F_94 ( & V_183 ) ;
F_43 ( & V_12 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 ) {
V_186 ++ ;
continue;
}
V_5 = V_12 -> V_15 [ V_3 ] ;
V_77 = F_106 ( V_16 ) ;
F_54 ( & V_12 -> V_56 , V_16 ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
if ( 0 == V_77 ) {
F_28 ( V_5 ) -> V_51 = 0 ;
F_70 ( V_5 ) ;
V_185 ++ ;
continue;
}
if ( ! F_107 ( V_188 ) ) {
struct V_30 * V_30 = F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 ;
unsigned long V_35 = F_33 ( V_30 ) ;
void * V_36 = F_34 ( V_30 ) ;
F_108 ( V_181 , ( unsigned long ) V_36 ,
F_109 ( V_77 , V_189 ) ,
0 ) ;
V_181 ++ ;
V_178 -> V_190 = ( ( V_191 ) V_77 << V_192 )
| V_193 ;
V_178 -> V_194 = V_35 ;
V_178 ++ ;
F_110 ( V_35 , V_77 ) ;
}
F_29 ( & V_183 , V_5 ) ;
V_184 ++ ;
}
F_111 ( & V_12 -> V_60 -> V_20 , L_17 ,
V_187 , V_184 , V_185 , V_186 ) ;
if ( V_184 ) {
if ( ! F_107 ( V_188 ) ) {
F_112 ( V_181 , V_12 -> V_179 , V_178 - V_12 -> V_179 ,
NULL , V_195 ) ;
V_181 ++ ;
F_113 ( V_12 -> V_182 , V_181 - V_12 -> V_182 ) ;
}
}
F_97 ( & V_183 ) ;
F_45 ( & V_12 -> V_62 ) ;
}
static void F_114 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_104 ( V_12 ) ;
F_105 ( V_12 ) ;
F_115 ( V_12 -> V_74 ) ;
F_115 ( V_12 -> V_56 ) ;
}
static T_4 F_116 ( struct V_19 * V_20 , T_4 V_21 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_194 ;
if ( V_21 & V_22 ) {
if ( F_117 ( V_196 , V_12 -> V_57 -> V_197 , L_18 ,
L_19 , & V_194 ) < 0 )
V_194 = 0 ;
if ( ! V_194 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_198 ) {
if ( F_117 ( V_196 , V_12 -> V_57 -> V_197 ,
L_20 , L_19 , & V_194 ) < 0 )
V_194 = 0 ;
if ( ! V_194 )
V_21 &= ~ V_198 ;
}
return V_21 ;
}
static int F_118 ( struct V_19 * V_20 , T_4 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_173 > V_175 ) {
F_119 ( V_20 , L_21 ) ;
V_20 -> V_173 = V_175 ;
}
return 0 ;
}
static struct V_19 * T_5 F_120 ( struct V_199 * V_20 )
{
int V_14 , V_112 ;
struct V_19 * V_60 ;
struct V_11 * V_12 ;
V_60 = F_121 ( sizeof( struct V_11 ) ) ;
if ( ! V_60 ) {
F_51 ( V_127 L_22 ,
V_187 ) ;
return F_122 ( - V_200 ) ;
}
V_12 = F_11 ( V_60 ) ;
V_12 -> V_57 = V_20 ;
F_123 ( & V_12 -> V_89 ) ;
F_123 ( & V_12 -> V_62 ) ;
F_94 ( & V_12 -> V_40 ) ;
V_12 -> V_39 = V_201 ;
V_12 -> V_171 = V_201 ;
V_12 -> V_55 = V_202 ;
F_124 ( & V_12 -> V_47 ) ;
V_12 -> V_47 . V_23 = ( unsigned long ) V_60 ;
V_12 -> V_47 . V_203 = F_10 ;
V_12 -> V_75 = 0 ;
for ( V_14 = 0 ; V_14 < V_176 ; V_14 ++ ) {
F_1 ( & V_12 -> V_70 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_125 ( V_28 ,
& V_12 -> V_74 ) < 0 ) {
F_51 ( V_72 L_23 ) ;
V_112 = - V_200 ;
goto exit;
}
if ( F_125 ( V_202 ,
& V_12 -> V_56 ) < 0 ) {
F_51 ( V_72 L_24 ) ;
V_112 = - V_200 ;
goto V_204;
}
V_60 -> V_205 = & V_206 ;
F_126 ( V_60 , & V_12 -> V_24 , F_91 , 64 ) ;
V_60 -> V_21 = V_207 | V_208 |
V_209 ;
V_60 -> V_210 = V_207 | V_22 | V_198 ;
V_60 -> V_21 |= V_60 -> V_210 ;
F_127 ( V_60 , & V_211 ) ;
F_128 ( V_60 , & V_20 -> V_20 ) ;
V_12 -> V_60 = V_60 ;
F_129 ( V_60 ) ;
return V_60 ;
V_204:
F_115 ( V_12 -> V_74 ) ;
exit:
F_130 ( V_60 ) ;
return F_122 ( V_112 ) ;
}
static int T_5 F_131 ( struct V_199 * V_20 ,
const struct V_212 * V_3 )
{
int V_112 ;
struct V_19 * V_60 ;
struct V_11 * V_213 ;
V_60 = F_120 ( V_20 ) ;
if ( F_132 ( V_60 ) ) {
V_112 = F_133 ( V_60 ) ;
F_134 ( V_20 , V_112 , L_25 ) ;
return V_112 ;
}
V_213 = F_11 ( V_60 ) ;
F_135 ( & V_20 -> V_20 , V_213 ) ;
V_112 = F_136 ( V_213 -> V_60 ) ;
if ( V_112 ) {
F_51 ( V_127 L_26 ,
V_187 , V_112 ) ;
goto V_214;
}
V_112 = F_137 ( V_213 -> V_60 ) ;
if ( V_112 ) {
F_138 ( V_213 -> V_60 ) ;
F_51 ( V_127 L_27 ,
V_187 , V_112 ) ;
goto V_214;
}
return 0 ;
V_214:
F_130 ( V_60 ) ;
F_135 ( & V_20 -> V_20 , NULL ) ;
return V_112 ;
}
static void F_139 ( int V_16 , void * V_30 )
{
if ( V_16 != V_18 )
F_140 ( V_16 , 0 , ( unsigned long ) V_30 ) ;
}
static void F_141 ( struct V_11 * V_213 )
{
F_43 ( & V_213 -> V_62 ) ;
F_65 ( & V_213 -> V_89 ) ;
F_129 ( V_213 -> V_60 ) ;
F_68 ( & V_213 -> V_89 ) ;
F_45 ( & V_213 -> V_62 ) ;
if ( V_213 -> V_60 -> V_61 )
F_142 ( V_213 -> V_60 -> V_61 , V_213 -> V_60 ) ;
V_213 -> V_215 = V_213 -> V_60 -> V_61 = 0 ;
F_139 ( V_213 -> V_216 , V_213 -> V_25 . V_52 ) ;
F_139 ( V_213 -> V_217 , V_213 -> V_34 . V_52 ) ;
V_213 -> V_216 = V_18 ;
V_213 -> V_217 = V_18 ;
V_213 -> V_25 . V_52 = NULL ;
V_213 -> V_34 . V_52 = NULL ;
}
static int F_143 ( struct V_199 * V_20 )
{
struct V_11 * V_213 = F_144 ( & V_20 -> V_20 ) ;
F_145 ( & V_20 -> V_20 , L_28 , V_20 -> V_218 ) ;
F_141 ( V_213 ) ;
return 0 ;
}
static int F_146 ( struct V_199 * V_20 , T_6 V_219 [] )
{
char * V_220 , * V_221 , * V_222 ;
int V_14 ;
V_222 = V_220 = F_147 ( V_196 , V_20 -> V_218 , L_29 , NULL ) ;
if ( F_132 ( V_222 ) )
return F_133 ( V_222 ) ;
for ( V_14 = 0 ; V_14 < V_223 ; V_14 ++ ) {
V_219 [ V_14 ] = F_148 ( V_220 , & V_221 , 16 ) ;
if ( ( V_220 == V_221 ) || ( * V_221 != ( ( V_14 == V_223 - 1 ) ? '\0' : ':' ) ) ) {
F_149 ( V_222 ) ;
return - V_125 ;
}
V_220 = V_221 + 1 ;
}
F_149 ( V_222 ) ;
return 0 ;
}
static T_7 F_150 ( int V_61 , void * V_224 )
{
struct V_19 * V_20 = V_224 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
unsigned long V_82 ;
F_151 ( & V_12 -> V_89 , V_82 ) ;
if ( F_17 ( F_21 ( V_20 ) ) ) {
F_47 ( V_20 ) ;
if ( F_44 ( & V_12 -> V_34 ) )
F_12 ( & V_12 -> V_24 ) ;
}
F_152 ( & V_12 -> V_89 , V_82 ) ;
return V_225 ;
}
static int F_153 ( struct V_199 * V_20 , struct V_11 * V_213 )
{
struct V_226 * V_227 ;
struct V_228 * V_229 ;
int V_112 ;
struct V_19 * V_60 = V_213 -> V_60 ;
V_213 -> V_216 = V_18 ;
V_213 -> V_217 = V_18 ;
V_213 -> V_34 . V_52 = NULL ;
V_213 -> V_25 . V_52 = NULL ;
V_60 -> V_61 = 0 ;
V_112 = F_146 ( V_20 , V_60 -> V_230 ) ;
if ( V_112 ) {
F_134 ( V_20 , V_112 , L_30 , V_20 -> V_218 ) ;
goto V_214;
}
V_227 = (struct V_226 * ) F_154 ( V_231 | V_232 ) ;
if ( ! V_227 ) {
V_112 = - V_200 ;
F_134 ( V_20 , V_112 , L_31 ) ;
goto V_214;
}
F_155 ( V_227 ) ;
F_156 ( & V_213 -> V_25 , V_227 , V_80 ) ;
V_112 = F_157 ( V_20 , F_61 ( V_227 ) ) ;
if ( V_112 < 0 ) {
F_158 ( ( unsigned long ) V_227 ) ;
goto V_214;
}
V_213 -> V_216 = V_112 ;
V_229 = (struct V_228 * ) F_154 ( V_231 | V_232 ) ;
if ( ! V_229 ) {
V_112 = - V_200 ;
F_134 ( V_20 , V_112 , L_32 ) ;
goto V_214;
}
F_155 ( V_229 ) ;
F_156 ( & V_213 -> V_34 , V_229 , V_80 ) ;
V_112 = F_157 ( V_20 , F_61 ( V_229 ) ) ;
if ( V_112 < 0 ) {
F_158 ( ( unsigned long ) V_229 ) ;
goto V_214;
}
V_213 -> V_217 = V_112 ;
V_112 = F_159 ( V_20 , & V_213 -> V_215 ) ;
if ( V_112 )
goto V_214;
V_112 = F_160 ( V_213 -> V_215 , F_150 ,
0 , V_60 -> V_233 , V_60 ) ;
if ( V_112 < 0 )
goto V_214;
V_60 -> V_61 = V_112 ;
return 0 ;
V_214:
return V_112 ;
}
static int F_161 ( struct V_199 * V_20 ,
struct V_11 * V_213 )
{
const char * V_234 ;
struct V_235 V_236 ;
int V_112 ;
V_112 = F_153 ( V_20 , V_213 ) ;
if ( V_112 )
goto V_144;
V_237:
V_112 = F_162 ( & V_236 ) ;
if ( V_112 ) {
F_134 ( V_20 , V_112 , L_33 ) ;
goto V_238;
}
V_112 = F_163 ( V_236 , V_20 -> V_218 , L_34 , L_35 ,
V_213 -> V_216 ) ;
if ( V_112 ) {
V_234 = L_36 ;
goto V_239;
}
V_112 = F_163 ( V_236 , V_20 -> V_218 , L_37 , L_35 ,
V_213 -> V_217 ) ;
if ( V_112 ) {
V_234 = L_38 ;
goto V_239;
}
V_112 = F_163 ( V_236 , V_20 -> V_218 ,
L_39 , L_35 , V_213 -> V_215 ) ;
if ( V_112 ) {
V_234 = L_40 ;
goto V_239;
}
V_112 = F_163 ( V_236 , V_20 -> V_218 , L_41 , L_35 ,
1 ) ;
if ( V_112 ) {
V_234 = L_42 ;
goto V_239;
}
V_112 = F_163 ( V_236 , V_20 -> V_218 , L_43 , L_19 , 1 ) ;
if ( V_112 ) {
V_234 = L_44 ;
goto V_239;
}
V_112 = F_163 ( V_236 , V_20 -> V_218 , L_18 , L_19 , 1 ) ;
if ( V_112 ) {
V_234 = L_45 ;
goto V_239;
}
V_112 = F_163 ( V_236 , V_20 -> V_218 , L_20 , L_19 , 1 ) ;
if ( V_112 ) {
V_234 = L_46 ;
goto V_239;
}
V_112 = F_164 ( V_236 , 0 ) ;
if ( V_112 ) {
if ( V_112 == - V_240 )
goto V_237;
F_134 ( V_20 , V_112 , L_47 ) ;
goto V_238;
}
return 0 ;
V_239:
F_164 ( V_236 , 1 ) ;
F_134 ( V_20 , V_112 , L_48 , V_234 ) ;
V_238:
F_141 ( V_213 ) ;
V_144:
return V_112 ;
}
static int F_165 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_14 , V_241 , V_112 ;
struct V_10 * V_5 ;
T_2 V_16 ;
struct V_37 * V_38 ;
unsigned int V_242 ;
V_112 = F_117 ( V_196 , V_12 -> V_57 -> V_197 ,
L_49 , L_35 , & V_242 ) ;
if ( V_112 != 1 )
V_242 = 0 ;
if ( ! V_242 ) {
F_111 ( & V_20 -> V_20 ,
L_50 ) ;
return - V_243 ;
}
V_112 = F_161 ( V_12 -> V_57 , V_12 ) ;
if ( V_112 )
return V_112 ;
F_166 () ;
F_167 ( V_20 ) ;
F_168 () ;
F_43 ( & V_12 -> V_62 ) ;
F_65 ( & V_12 -> V_89 ) ;
F_104 ( V_12 ) ;
for ( V_241 = 0 , V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
if ( ! V_12 -> V_15 [ V_14 ] )
continue;
V_5 = V_12 -> V_15 [ V_241 ] = F_7 ( V_12 , V_14 ) ;
V_16 = V_12 -> V_17 [ V_241 ] = F_8 ( V_12 , V_14 ) ;
V_38 = F_35 ( & V_12 -> V_34 , V_241 ) ;
F_36 (
V_16 , V_12 -> V_57 -> V_58 ,
F_37 ( F_33 ( F_28 ( V_5 ) ->
V_50 -> V_30 ) ) ,
0 ) ;
V_38 -> V_59 = V_16 ;
V_38 -> V_3 = V_241 ;
V_241 ++ ;
}
V_12 -> V_34 . V_26 = V_241 ;
F_169 ( V_12 -> V_60 ) ;
F_40 ( V_12 -> V_60 -> V_61 ) ;
F_47 ( V_20 ) ;
F_20 ( V_20 ) ;
F_68 ( & V_12 -> V_89 ) ;
F_45 ( & V_12 -> V_62 ) ;
return 0 ;
}
static void F_170 ( struct V_199 * V_20 ,
enum V_244 V_245 )
{
struct V_11 * V_12 = F_144 ( & V_20 -> V_20 ) ;
struct V_19 * V_60 = V_12 -> V_60 ;
F_145 ( & V_20 -> V_20 , L_28 , F_171 ( V_245 ) ) ;
switch ( V_245 ) {
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
break;
case V_253 :
if ( V_20 -> V_254 != V_246 )
break;
if ( F_165 ( V_60 ) != 0 )
break;
F_172 ( V_20 , V_250 ) ;
F_173 ( V_60 ) ;
break;
case V_255 :
F_174 ( V_20 ) ;
break;
}
}
static int F_175 ( struct V_19 * V_20 , int V_256 )
{
switch ( V_256 ) {
case V_257 :
return F_176 ( V_258 ) ;
default:
return - V_115 ;
}
}
static void F_177 ( struct V_19 * V_20 ,
struct V_259 * V_103 , V_191 * V_23 )
{
void * V_12 = F_11 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_176 ( V_258 ) ; V_14 ++ )
V_23 [ V_14 ] = * ( unsigned long * ) ( V_12 + V_258 [ V_14 ] . V_78 ) ;
}
static void F_178 ( struct V_19 * V_20 , T_4 V_260 , T_6 * V_23 )
{
int V_14 ;
switch ( V_260 ) {
case V_257 :
for ( V_14 = 0 ; V_14 < F_176 ( V_258 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_261 ,
V_258 [ V_14 ] . V_233 , V_261 ) ;
break;
}
}
static T_8 F_179 ( struct V_111 * V_20 ,
struct V_262 * V_263 , char * V_264 )
{
struct V_19 * V_60 = F_180 ( V_20 ) ;
struct V_11 * V_213 = F_11 ( V_60 ) ;
return sprintf ( V_264 , L_51 , V_213 -> V_171 ) ;
}
static T_8 F_181 ( struct V_111 * V_20 ,
struct V_262 * V_263 ,
const char * V_264 , T_9 V_79 )
{
struct V_19 * V_60 = F_180 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_265 ;
unsigned long V_266 ;
if ( ! F_182 ( V_267 ) )
return - V_268 ;
V_266 = F_148 ( V_264 , & V_265 , 0 ) ;
if ( V_265 == V_264 )
return - V_269 ;
if ( V_266 < V_270 )
V_266 = V_270 ;
if ( V_266 > V_202 )
V_266 = V_202 ;
F_43 ( & V_12 -> V_62 ) ;
if ( V_266 > V_12 -> V_55 )
V_12 -> V_55 = V_266 ;
V_12 -> V_171 = V_266 ;
if ( V_266 > V_12 -> V_39 )
V_12 -> V_39 = V_266 ;
F_20 ( V_60 ) ;
F_45 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_8 F_183 ( struct V_111 * V_20 ,
struct V_262 * V_263 , char * V_264 )
{
struct V_19 * V_60 = F_180 ( V_20 ) ;
struct V_11 * V_213 = F_11 ( V_60 ) ;
return sprintf ( V_264 , L_51 , V_213 -> V_55 ) ;
}
static T_8 F_184 ( struct V_111 * V_20 ,
struct V_262 * V_263 ,
const char * V_264 , T_9 V_79 )
{
struct V_19 * V_60 = F_180 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_265 ;
unsigned long V_266 ;
if ( ! F_182 ( V_267 ) )
return - V_268 ;
V_266 = F_148 ( V_264 , & V_265 , 0 ) ;
if ( V_265 == V_264 )
return - V_269 ;
if ( V_266 < V_270 )
V_266 = V_270 ;
if ( V_266 > V_202 )
V_266 = V_202 ;
F_43 ( & V_12 -> V_62 ) ;
if ( V_266 < V_12 -> V_171 )
V_12 -> V_171 = V_266 ;
V_12 -> V_55 = V_266 ;
if ( V_266 < V_12 -> V_39 )
V_12 -> V_39 = V_266 ;
F_20 ( V_60 ) ;
F_45 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_8 F_185 ( struct V_111 * V_20 ,
struct V_262 * V_263 , char * V_264 )
{
struct V_19 * V_60 = F_180 ( V_20 ) ;
struct V_11 * V_213 = F_11 ( V_60 ) ;
return sprintf ( V_264 , L_51 , V_213 -> V_39 ) ;
}
static int F_137 ( struct V_19 * V_60 )
{
int V_14 ;
int V_112 ;
for ( V_14 = 0 ; V_14 < F_176 ( V_271 ) ; V_14 ++ ) {
V_112 = F_186 ( & V_60 -> V_20 ,
& V_271 [ V_14 ] ) ;
if ( V_112 )
goto V_214;
}
return 0 ;
V_214:
while ( -- V_14 >= 0 )
F_187 ( & V_60 -> V_20 , & V_271 [ V_14 ] ) ;
return V_112 ;
}
static void F_188 ( struct V_19 * V_60 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_176 ( V_271 ) ; V_14 ++ )
F_187 ( & V_60 -> V_20 , & V_271 [ V_14 ] ) ;
}
static int T_10 F_189 ( struct V_199 * V_20 )
{
struct V_11 * V_213 = F_144 ( & V_20 -> V_20 ) ;
F_145 ( & V_20 -> V_20 , L_28 , V_20 -> V_218 ) ;
F_138 ( V_213 -> V_60 ) ;
F_141 ( V_213 ) ;
F_190 ( & V_213 -> V_47 ) ;
F_188 ( V_213 -> V_60 ) ;
F_130 ( V_213 -> V_60 ) ;
return 0 ;
}
static int T_11 F_191 ( void )
{
if ( ! F_192 () )
return - V_243 ;
if ( F_193 () )
return 0 ;
F_51 ( V_272 L_52 ) ;
return F_194 ( & V_273 ) ;
}
static void T_12 F_195 ( void )
{
if ( F_193 () )
return;
F_196 ( & V_273 ) ;
}
