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
struct V_86 * V_87 = F_63 ( V_12 -> V_87 ) ;
struct V_76 * V_25 ;
struct V_88 * V_89 ;
char * V_23 = V_5 -> V_23 ;
T_1 V_14 ;
T_2 V_16 ;
unsigned long V_77 ;
int V_32 ;
int V_50 = F_28 ( V_5 ) -> V_51 ;
unsigned int V_78 = F_58 ( V_23 ) ;
unsigned int V_79 = F_59 ( V_5 ) ;
V_50 += F_64 ( V_78 + V_79 , V_80 ) ;
if ( F_15 ( V_50 > V_29 + 1 ) ) {
F_51 ( V_72 L_4 ,
V_50 ) ;
F_65 () ;
goto V_90;
}
F_66 ( & V_12 -> V_91 ) ;
if ( F_15 ( ! F_21 ( V_20 ) ||
( V_50 > 1 && ! F_9 ( V_20 ) ) ||
F_67 ( V_5 , F_68 ( V_5 ) ) ) ) {
F_69 ( & V_12 -> V_91 ) ;
goto V_90;
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
V_89 = NULL ;
V_25 -> V_82 = 0 ;
if ( V_5 -> V_92 == V_93 )
V_25 -> V_82 |= V_94 | V_95 ;
else if ( V_5 -> V_92 == V_96 )
V_25 -> V_82 |= V_95 ;
if ( F_28 ( V_5 ) -> V_97 ) {
struct V_88 * V_98 ;
V_98 = (struct V_88 * )
F_35 ( & V_12 -> V_25 , ++ V_14 ) ;
if ( V_89 )
V_89 -> V_82 |= V_99 ;
else
V_25 -> V_82 |= V_100 ;
V_98 -> V_101 . V_98 . V_81 = F_28 ( V_5 ) -> V_97 ;
V_98 -> V_101 . V_98 . type = V_102 ;
V_98 -> V_101 . V_98 . V_103 = 0 ;
V_98 -> V_101 . V_98 . V_21 = 0 ;
V_98 -> type = V_104 ;
V_98 -> V_82 = 0 ;
V_89 = V_98 ;
}
V_12 -> V_25 . V_26 = V_14 + 1 ;
F_57 ( V_5 , V_20 , V_25 ) ;
V_25 -> V_81 = V_5 -> V_79 ;
F_39 ( & V_12 -> V_25 , V_32 ) ;
if ( V_32 )
F_40 ( V_12 -> V_60 -> V_61 ) ;
F_70 ( & V_87 -> V_105 ) ;
V_87 -> V_106 += V_5 -> V_79 ;
V_87 -> V_107 ++ ;
F_71 ( & V_87 -> V_105 ) ;
F_47 ( V_20 ) ;
if ( ! F_13 ( V_12 ) )
F_72 ( V_20 ) ;
F_69 ( & V_12 -> V_91 ) ;
return V_108 ;
V_90:
V_20 -> V_87 . V_109 ++ ;
F_73 ( V_5 ) ;
return V_108 ;
}
static int F_74 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_72 ( V_12 -> V_60 ) ;
F_75 ( & V_12 -> V_24 ) ;
return 0 ;
}
static void F_76 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_110 = F_6 ( V_12 -> V_34 . V_26 ) ;
F_31 ( V_12 -> V_15 [ V_110 ] ) ;
V_12 -> V_15 [ V_110 ] = V_5 ;
V_12 -> V_17 [ V_110 ] = V_16 ;
F_35 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_3 = V_110 ;
F_35 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_59 = V_16 ;
V_12 -> V_34 . V_26 ++ ;
}
static int F_77 ( struct V_11 * V_12 ,
struct V_88 * V_111 ,
T_1 V_112 )
{
struct V_88 * V_89 ;
struct V_113 * V_20 = & V_12 -> V_60 -> V_20 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
int V_114 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_64 + 1 == V_112 ) ) {
if ( F_78 () )
F_79 ( V_20 , L_5 ) ;
V_114 = - V_115 ;
break;
}
V_89 = (struct V_88 * )
F_49 ( & V_12 -> V_34 , ++ V_64 ) ;
if ( F_15 ( ! V_89 -> type ||
V_89 -> type >= V_116 ) ) {
if ( F_78 () )
F_79 ( V_20 , L_6 ,
V_89 -> type ) ;
V_114 = - V_117 ;
} else {
memcpy ( & V_111 [ V_89 -> type - 1 ] , V_89 ,
sizeof( * V_89 ) ) ;
}
V_5 = F_7 ( V_12 , V_64 ) ;
V_16 = F_8 ( V_12 , V_64 ) ;
F_76 ( V_12 , V_5 , V_16 ) ;
} while ( V_89 -> V_82 & V_99 );
V_12 -> V_34 . V_27 = V_64 ;
return V_114 ;
}
static int F_80 ( struct V_11 * V_12 ,
struct V_118 * V_119 , T_1 V_112 ,
struct V_120 * V_2 )
{
struct V_121 * V_34 = & V_119 -> V_34 ;
struct V_88 * V_111 = V_119 -> V_111 ;
struct V_113 * V_20 = & V_12 -> V_60 -> V_20 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_64 ) ;
T_2 V_16 = F_8 ( V_12 , V_64 ) ;
int V_122 = V_29 + ( V_34 -> V_68 <= V_41 ) ;
int V_50 = 1 ;
int V_114 = 0 ;
unsigned long V_123 ;
if ( V_34 -> V_82 & V_124 ) {
V_114 = F_77 ( V_12 , V_111 , V_112 ) ;
V_64 = V_12 -> V_34 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_34 -> V_68 < 0 ||
V_34 -> V_78 + V_34 -> V_68 > V_80 ) ) {
if ( F_78 () )
F_79 ( V_20 , L_7 ,
V_34 -> V_78 , V_34 -> V_68 ) ;
F_76 ( V_12 , V_5 , V_16 ) ;
V_114 = - V_117 ;
goto V_125;
}
if ( V_16 == V_18 ) {
if ( F_78 () )
F_79 ( V_20 , L_8 ,
V_34 -> V_3 ) ;
V_114 = - V_117 ;
goto V_125;
}
V_123 = F_53 ( V_16 , 0 ) ;
F_31 ( ! V_123 ) ;
F_54 ( & V_12 -> V_56 , V_16 ) ;
F_29 ( V_2 , V_5 ) ;
V_125:
if ( ! ( V_34 -> V_82 & V_126 ) )
break;
if ( V_64 + V_50 == V_112 ) {
if ( F_78 () )
F_79 ( V_20 , L_9 ) ;
V_114 = - V_127 ;
break;
}
V_34 = F_49 ( & V_12 -> V_34 , V_64 + V_50 ) ;
V_5 = F_7 ( V_12 , V_64 + V_50 ) ;
V_16 = F_8 ( V_12 , V_64 + V_50 ) ;
V_50 ++ ;
}
if ( F_15 ( V_50 > V_122 ) ) {
if ( F_78 () )
F_79 ( V_20 , L_10 ) ;
V_114 = - V_128 ;
}
if ( F_15 ( V_114 ) )
V_12 -> V_34 . V_27 = V_64 + V_50 ;
return V_114 ;
}
static int F_81 ( struct V_10 * V_5 ,
struct V_88 * V_98 )
{
if ( ! V_98 -> V_101 . V_98 . V_81 ) {
if ( F_78 () )
F_51 ( V_129 L_11 ) ;
return - V_117 ;
}
if ( V_98 -> V_101 . V_98 . type != V_102 ) {
if ( F_78 () )
F_51 ( V_129 L_12 , V_98 -> V_101 . V_98 . type ) ;
return - V_117 ;
}
F_28 ( V_5 ) -> V_97 = V_98 -> V_101 . V_98 . V_81 ;
F_28 ( V_5 ) -> V_130 = V_131 ;
F_28 ( V_5 ) -> V_130 |= V_132 ;
F_28 ( V_5 ) -> V_133 = 0 ;
return 0 ;
}
static T_1 F_82 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_120 * V_2 )
{
struct V_134 * V_135 = F_28 ( V_5 ) ;
int V_51 = V_135 -> V_51 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
T_3 * V_84 = V_135 -> V_50 + V_51 ;
struct V_10 * V_136 ;
while ( ( V_136 = F_30 ( V_2 ) ) ) {
struct V_121 * V_34 =
F_49 ( & V_12 -> V_34 , ++ V_64 ) ;
V_84 -> V_30 = F_28 ( V_136 ) -> V_50 [ 0 ] . V_30 ;
V_84 -> V_85 = V_34 -> V_78 ;
V_84 -> V_81 = V_34 -> V_68 ;
V_5 -> V_137 += V_34 -> V_68 ;
F_28 ( V_136 ) -> V_51 = 0 ;
F_26 ( V_136 ) ;
V_84 ++ ;
V_51 ++ ;
}
V_135 -> V_51 = V_51 ;
return V_64 ;
}
static int F_83 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
struct V_138 * V_139 ;
unsigned char * V_140 ;
int V_114 = - V_141 ;
int V_142 = 0 ;
if ( V_5 -> V_92 != V_93 && F_84 ( V_5 ) ) {
struct V_11 * V_12 = F_11 ( V_20 ) ;
V_12 -> V_143 ++ ;
V_5 -> V_92 = V_93 ;
V_142 = 1 ;
}
if ( V_5 -> V_92 != V_93 )
return 0 ;
if ( V_5 -> V_144 != F_85 ( V_145 ) )
goto V_146;
V_139 = ( void * ) V_5 -> V_23 ;
V_140 = V_5 -> V_23 + 4 * V_139 -> V_147 ;
if ( V_140 >= F_86 ( V_5 ) )
goto V_146;
V_5 -> V_148 = V_140 - V_5 -> V_7 ;
switch ( V_139 -> V_144 ) {
case V_149 :
V_5 -> V_150 = F_87 ( struct V_151 , V_152 ) ;
if ( V_142 ) {
struct V_151 * V_153 = (struct V_151 * ) V_140 ;
V_153 -> V_152 = ~ F_88 ( V_139 -> V_154 , V_139 -> V_155 ,
V_5 -> V_79 - V_139 -> V_147 * 4 ,
V_149 , 0 ) ;
}
break;
case V_156 :
V_5 -> V_150 = F_87 ( struct V_157 , V_152 ) ;
if ( V_142 ) {
struct V_157 * V_158 = (struct V_157 * ) V_140 ;
V_158 -> V_152 = ~ F_88 ( V_139 -> V_154 , V_139 -> V_155 ,
V_5 -> V_79 - V_139 -> V_147 * 4 ,
V_156 , 0 ) ;
}
break;
default:
if ( F_78 () )
F_51 ( V_159 L_13
L_14
L_15 , V_139 -> V_144 ) ;
goto V_146;
}
if ( ( V_140 + V_5 -> V_150 + 2 ) > F_86 ( V_5 ) )
goto V_146;
V_114 = 0 ;
V_146:
return V_114 ;
}
static int F_89 ( struct V_19 * V_20 ,
struct V_120 * V_160 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_86 * V_87 = F_63 ( V_12 -> V_87 ) ;
int V_161 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_30 ( V_160 ) ) != NULL ) {
struct V_30 * V_30 = F_90 ( V_5 ) -> V_30 ;
void * V_36 = F_34 ( V_30 ) ;
unsigned V_78 = F_90 ( V_5 ) -> V_78 ;
memcpy ( V_5 -> V_23 , V_36 + V_78 ,
F_59 ( V_5 ) ) ;
if ( V_30 != F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 )
F_91 ( V_30 ) ;
V_5 -> V_144 = F_92 ( V_5 , V_20 ) ;
if ( F_83 ( V_20 , V_5 ) ) {
F_26 ( V_5 ) ;
V_161 ++ ;
V_20 -> V_87 . V_162 ++ ;
continue;
}
F_70 ( & V_87 -> V_105 ) ;
V_87 -> V_163 ++ ;
V_87 -> V_164 += V_5 -> V_79 ;
F_71 ( & V_87 -> V_105 ) ;
F_93 ( V_5 ) ;
}
return V_161 ;
}
static int F_94 ( struct V_165 * V_24 , int V_166 )
{
struct V_11 * V_12 = F_95 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_60 ;
struct V_10 * V_5 ;
struct V_118 V_119 ;
struct V_121 * V_34 = & V_119 . V_34 ;
struct V_88 * V_111 = V_119 . V_111 ;
T_1 V_14 , V_112 ;
int V_167 ;
struct V_120 V_160 ;
struct V_120 V_168 ;
struct V_120 V_169 ;
unsigned long V_82 ;
unsigned int V_79 ;
int V_114 ;
F_96 ( & V_12 -> V_62 ) ;
F_97 ( & V_160 ) ;
F_97 ( & V_168 ) ;
F_97 ( & V_169 ) ;
V_112 = V_12 -> V_34 . V_52 -> V_54 ;
F_48 () ;
V_14 = V_12 -> V_34 . V_27 ;
V_167 = 0 ;
while ( ( V_14 != V_112 ) && ( V_167 < V_166 ) ) {
memcpy ( V_34 , F_49 ( & V_12 -> V_34 , V_14 ) , sizeof( * V_34 ) ) ;
memset ( V_111 , 0 , sizeof( V_119 . V_111 ) ) ;
V_114 = F_80 ( V_12 , & V_119 , V_112 , & V_169 ) ;
if ( F_15 ( V_114 ) ) {
V_114:
while ( ( V_5 = F_30 ( & V_169 ) ) )
F_29 ( & V_168 , V_5 ) ;
V_20 -> V_87 . V_162 ++ ;
V_14 = V_12 -> V_34 . V_27 ;
continue;
}
V_5 = F_30 ( & V_169 ) ;
if ( V_111 [ V_104 - 1 ] . type ) {
struct V_88 * V_98 ;
V_98 = & V_111 [ V_104 - 1 ] ;
if ( F_15 ( F_81 ( V_5 , V_98 ) ) ) {
F_98 ( & V_169 , V_5 ) ;
V_12 -> V_34 . V_27 += F_22 ( & V_169 ) ;
goto V_114;
}
}
F_90 ( V_5 ) -> V_30 = F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 ;
F_90 ( V_5 ) -> V_78 = V_34 -> V_78 ;
V_79 = V_34 -> V_68 ;
if ( V_79 > V_41 )
V_79 = V_41 ;
F_99 ( V_5 , V_79 ) ;
if ( V_34 -> V_68 > V_79 ) {
F_28 ( V_5 ) -> V_50 [ 0 ] . V_85 =
V_34 -> V_78 + V_79 ;
F_28 ( V_5 ) -> V_50 [ 0 ] . V_81 = V_34 -> V_68 - V_79 ;
V_5 -> V_137 = V_34 -> V_68 - V_79 ;
} else {
F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 = NULL ;
F_28 ( V_5 ) -> V_51 = 0 ;
}
V_14 = F_82 ( V_12 , V_5 , & V_169 ) ;
V_5 -> V_170 += V_5 -> V_137 - ( V_41 - V_79 ) ;
V_5 -> V_79 += V_5 -> V_137 ;
if ( V_34 -> V_82 & V_171 )
V_5 -> V_92 = V_93 ;
else if ( V_34 -> V_82 & V_172 )
V_5 -> V_92 = V_96 ;
F_29 ( & V_160 , V_5 ) ;
V_12 -> V_34 . V_27 = ++ V_14 ;
V_167 ++ ;
}
F_100 ( & V_168 ) ;
V_167 -= F_89 ( V_20 , & V_160 ) ;
if ( ( ( V_12 -> V_34 . V_26 - V_12 -> V_34 . V_52 -> V_54 ) >
( ( 3 * V_12 -> V_39 ) / 4 ) ) &&
( -- V_12 -> V_39 < V_12 -> V_173 ) )
V_12 -> V_39 = V_12 -> V_173 ;
F_20 ( V_20 ) ;
if ( V_167 < V_166 ) {
int V_174 = 0 ;
F_101 ( V_82 ) ;
F_102 ( & V_12 -> V_34 , V_174 ) ;
if ( ! V_174 )
F_103 ( V_24 ) ;
F_104 ( V_82 ) ;
}
F_105 ( & V_12 -> V_62 ) ;
return V_167 ;
}
static int F_106 ( struct V_19 * V_20 , int V_175 )
{
int V_122 = F_9 ( V_20 ) ? 65535 - V_176 : V_177 ;
if ( V_175 > V_122 )
return - V_117 ;
V_20 -> V_175 = V_175 ;
return 0 ;
}
static struct V_178 * F_107 ( struct V_19 * V_20 ,
struct V_178 * V_179 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_180 ;
F_108 (cpu) {
struct V_86 * V_87 = F_109 ( V_12 -> V_87 , V_180 ) ;
T_4 V_163 , V_164 , V_107 , V_106 ;
unsigned int V_181 ;
do {
V_181 = F_110 ( & V_87 -> V_105 ) ;
V_163 = V_87 -> V_163 ;
V_107 = V_87 -> V_107 ;
V_164 = V_87 -> V_164 ;
V_106 = V_87 -> V_106 ;
} while ( F_111 ( & V_87 -> V_105 , V_181 ) );
V_179 -> V_163 += V_163 ;
V_179 -> V_107 += V_107 ;
V_179 -> V_164 += V_164 ;
V_179 -> V_106 += V_106 ;
}
V_179 -> V_162 = V_20 -> V_87 . V_162 ;
V_179 -> V_109 = V_20 -> V_87 . V_109 ;
return V_179 ;
}
static void F_112 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_182 ; V_14 ++ ) {
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
static void F_113 ( struct V_11 * V_12 )
{
struct V_183 * V_184 = V_12 -> V_185 ;
struct V_186 * V_187 = V_12 -> V_188 ;
struct V_120 V_189 ;
struct V_10 * V_5 ;
unsigned long V_77 ;
int V_190 = 0 , V_191 = 0 , V_192 = 0 ;
int V_3 , V_16 ;
F_79 ( & V_12 -> V_60 -> V_20 , L_16 ,
V_193 ) ;
return;
F_97 ( & V_189 ) ;
F_43 ( & V_12 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 ) {
V_192 ++ ;
continue;
}
V_5 = V_12 -> V_15 [ V_3 ] ;
V_77 = F_114 ( V_16 ) ;
F_54 ( & V_12 -> V_56 , V_16 ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
if ( 0 == V_77 ) {
F_28 ( V_5 ) -> V_51 = 0 ;
F_73 ( V_5 ) ;
V_191 ++ ;
continue;
}
if ( ! F_115 ( V_194 ) ) {
struct V_30 * V_30 = F_28 ( V_5 ) -> V_50 [ 0 ] . V_30 ;
unsigned long V_35 = F_33 ( V_30 ) ;
void * V_36 = F_34 ( V_30 ) ;
F_116 ( V_187 , ( unsigned long ) V_36 ,
F_117 ( V_77 , V_195 ) ,
0 ) ;
V_187 ++ ;
V_184 -> V_196 = ( ( T_4 ) V_77 << V_197 )
| V_198 ;
V_184 -> V_199 = V_35 ;
V_184 ++ ;
F_118 ( V_35 , V_77 ) ;
}
F_29 ( & V_189 , V_5 ) ;
V_190 ++ ;
}
F_119 ( & V_12 -> V_60 -> V_20 , L_17 ,
V_193 , V_190 , V_191 , V_192 ) ;
if ( V_190 ) {
if ( ! F_115 ( V_194 ) ) {
F_120 ( V_187 , V_12 -> V_185 , V_184 - V_12 -> V_185 ,
NULL , V_200 ) ;
V_187 ++ ;
F_121 ( V_12 -> V_188 , V_187 - V_12 -> V_188 ) ;
}
}
F_100 ( & V_189 ) ;
F_45 ( & V_12 -> V_62 ) ;
}
static void F_122 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_112 ( V_12 ) ;
F_113 ( V_12 ) ;
F_123 ( V_12 -> V_74 ) ;
F_123 ( V_12 -> V_56 ) ;
}
static T_5 F_124 ( struct V_19 * V_20 , T_5 V_21 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_199 ;
if ( V_21 & V_22 ) {
if ( F_125 ( V_201 , V_12 -> V_57 -> V_202 , L_18 ,
L_19 , & V_199 ) < 0 )
V_199 = 0 ;
if ( ! V_199 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_203 ) {
if ( F_125 ( V_201 , V_12 -> V_57 -> V_202 ,
L_20 , L_19 , & V_199 ) < 0 )
V_199 = 0 ;
if ( ! V_199 )
V_21 &= ~ V_203 ;
}
return V_21 ;
}
static int F_126 ( struct V_19 * V_20 , T_5 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_175 > V_177 ) {
F_127 ( V_20 , L_21 ) ;
V_20 -> V_175 = V_177 ;
}
return 0 ;
}
static struct V_19 * T_6 F_128 ( struct V_204 * V_20 )
{
int V_14 , V_114 ;
struct V_19 * V_60 ;
struct V_11 * V_12 ;
V_60 = F_129 ( sizeof( struct V_11 ) ) ;
if ( ! V_60 ) {
F_51 ( V_129 L_22 ,
V_193 ) ;
return F_130 ( - V_205 ) ;
}
V_12 = F_11 ( V_60 ) ;
V_12 -> V_57 = V_20 ;
F_131 ( & V_12 -> V_91 ) ;
F_131 ( & V_12 -> V_62 ) ;
F_97 ( & V_12 -> V_40 ) ;
V_12 -> V_39 = V_206 ;
V_12 -> V_173 = V_206 ;
V_12 -> V_55 = V_207 ;
F_132 ( & V_12 -> V_47 ) ;
V_12 -> V_47 . V_23 = ( unsigned long ) V_60 ;
V_12 -> V_47 . V_208 = F_10 ;
V_114 = - V_205 ;
V_12 -> V_87 = F_133 ( struct V_86 ) ;
if ( V_12 -> V_87 == NULL )
goto exit;
V_12 -> V_75 = 0 ;
for ( V_14 = 0 ; V_14 < V_182 ; V_14 ++ ) {
F_1 ( & V_12 -> V_70 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_134 ( V_28 ,
& V_12 -> V_74 ) < 0 ) {
F_51 ( V_72 L_23 ) ;
V_114 = - V_205 ;
goto V_209;
}
if ( F_134 ( V_207 ,
& V_12 -> V_56 ) < 0 ) {
F_51 ( V_72 L_24 ) ;
V_114 = - V_205 ;
goto V_210;
}
V_60 -> V_211 = & V_212 ;
F_135 ( V_60 , & V_12 -> V_24 , F_94 , 64 ) ;
V_60 -> V_21 = V_213 | V_214 |
V_215 ;
V_60 -> V_216 = V_213 | V_22 | V_203 ;
V_60 -> V_21 |= V_60 -> V_216 ;
F_136 ( V_60 , & V_217 ) ;
F_137 ( V_60 , & V_20 -> V_20 ) ;
V_12 -> V_60 = V_60 ;
F_138 ( V_60 ) ;
return V_60 ;
V_210:
F_123 ( V_12 -> V_74 ) ;
V_209:
F_139 ( V_12 -> V_87 ) ;
exit:
F_140 ( V_60 ) ;
return F_130 ( V_114 ) ;
}
static int T_6 F_141 ( struct V_204 * V_20 ,
const struct V_218 * V_3 )
{
int V_114 ;
struct V_19 * V_60 ;
struct V_11 * V_219 ;
V_60 = F_128 ( V_20 ) ;
if ( F_142 ( V_60 ) ) {
V_114 = F_143 ( V_60 ) ;
F_144 ( V_20 , V_114 , L_25 ) ;
return V_114 ;
}
V_219 = F_11 ( V_60 ) ;
F_145 ( & V_20 -> V_20 , V_219 ) ;
V_114 = F_146 ( V_219 -> V_60 ) ;
if ( V_114 ) {
F_51 ( V_129 L_26 ,
V_193 , V_114 ) ;
goto V_220;
}
V_114 = F_147 ( V_219 -> V_60 ) ;
if ( V_114 ) {
F_148 ( V_219 -> V_60 ) ;
F_51 ( V_129 L_27 ,
V_193 , V_114 ) ;
goto V_220;
}
return 0 ;
V_220:
F_140 ( V_60 ) ;
F_145 ( & V_20 -> V_20 , NULL ) ;
return V_114 ;
}
static void F_149 ( int V_16 , void * V_30 )
{
if ( V_16 != V_18 )
F_150 ( V_16 , 0 , ( unsigned long ) V_30 ) ;
}
static void F_151 ( struct V_11 * V_219 )
{
F_43 ( & V_219 -> V_62 ) ;
F_66 ( & V_219 -> V_91 ) ;
F_138 ( V_219 -> V_60 ) ;
F_69 ( & V_219 -> V_91 ) ;
F_45 ( & V_219 -> V_62 ) ;
if ( V_219 -> V_60 -> V_61 )
F_152 ( V_219 -> V_60 -> V_61 , V_219 -> V_60 ) ;
V_219 -> V_221 = V_219 -> V_60 -> V_61 = 0 ;
F_149 ( V_219 -> V_222 , V_219 -> V_25 . V_52 ) ;
F_149 ( V_219 -> V_223 , V_219 -> V_34 . V_52 ) ;
V_219 -> V_222 = V_18 ;
V_219 -> V_223 = V_18 ;
V_219 -> V_25 . V_52 = NULL ;
V_219 -> V_34 . V_52 = NULL ;
}
static int F_153 ( struct V_204 * V_20 )
{
struct V_11 * V_219 = F_154 ( & V_20 -> V_20 ) ;
F_155 ( & V_20 -> V_20 , L_28 , V_20 -> V_224 ) ;
F_151 ( V_219 ) ;
return 0 ;
}
static int F_156 ( struct V_204 * V_20 , T_7 V_225 [] )
{
char * V_226 , * V_227 , * V_228 ;
int V_14 ;
V_228 = V_226 = F_157 ( V_201 , V_20 -> V_224 , L_29 , NULL ) ;
if ( F_142 ( V_228 ) )
return F_143 ( V_228 ) ;
for ( V_14 = 0 ; V_14 < V_229 ; V_14 ++ ) {
V_225 [ V_14 ] = F_158 ( V_226 , & V_227 , 16 ) ;
if ( ( V_226 == V_227 ) || ( * V_227 != ( ( V_14 == V_229 - 1 ) ? '\0' : ':' ) ) ) {
F_159 ( V_228 ) ;
return - V_127 ;
}
V_226 = V_227 + 1 ;
}
F_159 ( V_228 ) ;
return 0 ;
}
static T_8 F_160 ( int V_61 , void * V_230 )
{
struct V_19 * V_20 = V_230 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
unsigned long V_82 ;
F_161 ( & V_12 -> V_91 , V_82 ) ;
if ( F_17 ( F_21 ( V_20 ) ) ) {
F_47 ( V_20 ) ;
if ( F_44 ( & V_12 -> V_34 ) )
F_12 ( & V_12 -> V_24 ) ;
}
F_162 ( & V_12 -> V_91 , V_82 ) ;
return V_231 ;
}
static int F_163 ( struct V_204 * V_20 , struct V_11 * V_219 )
{
struct V_232 * V_233 ;
struct V_234 * V_235 ;
int V_114 ;
struct V_19 * V_60 = V_219 -> V_60 ;
V_219 -> V_222 = V_18 ;
V_219 -> V_223 = V_18 ;
V_219 -> V_34 . V_52 = NULL ;
V_219 -> V_25 . V_52 = NULL ;
V_60 -> V_61 = 0 ;
V_114 = F_156 ( V_20 , V_60 -> V_236 ) ;
if ( V_114 ) {
F_144 ( V_20 , V_114 , L_30 , V_20 -> V_224 ) ;
goto V_220;
}
V_233 = (struct V_232 * ) F_164 ( V_237 | V_238 ) ;
if ( ! V_233 ) {
V_114 = - V_205 ;
F_144 ( V_20 , V_114 , L_31 ) ;
goto V_220;
}
F_165 ( V_233 ) ;
F_166 ( & V_219 -> V_25 , V_233 , V_80 ) ;
V_114 = F_167 ( V_20 , F_61 ( V_233 ) ) ;
if ( V_114 < 0 ) {
F_168 ( ( unsigned long ) V_233 ) ;
goto V_220;
}
V_219 -> V_222 = V_114 ;
V_235 = (struct V_234 * ) F_164 ( V_237 | V_238 ) ;
if ( ! V_235 ) {
V_114 = - V_205 ;
F_144 ( V_20 , V_114 , L_32 ) ;
goto V_220;
}
F_165 ( V_235 ) ;
F_166 ( & V_219 -> V_34 , V_235 , V_80 ) ;
V_114 = F_167 ( V_20 , F_61 ( V_235 ) ) ;
if ( V_114 < 0 ) {
F_168 ( ( unsigned long ) V_235 ) ;
goto V_220;
}
V_219 -> V_223 = V_114 ;
V_114 = F_169 ( V_20 , & V_219 -> V_221 ) ;
if ( V_114 )
goto V_220;
V_114 = F_170 ( V_219 -> V_221 , F_160 ,
0 , V_60 -> V_239 , V_60 ) ;
if ( V_114 < 0 )
goto V_220;
V_60 -> V_61 = V_114 ;
return 0 ;
V_220:
return V_114 ;
}
static int F_171 ( struct V_204 * V_20 ,
struct V_11 * V_219 )
{
const char * V_240 ;
struct V_241 V_242 ;
int V_114 ;
V_114 = F_163 ( V_20 , V_219 ) ;
if ( V_114 )
goto V_146;
V_243:
V_114 = F_172 ( & V_242 ) ;
if ( V_114 ) {
F_144 ( V_20 , V_114 , L_33 ) ;
goto V_244;
}
V_114 = F_173 ( V_242 , V_20 -> V_224 , L_34 , L_35 ,
V_219 -> V_222 ) ;
if ( V_114 ) {
V_240 = L_36 ;
goto V_245;
}
V_114 = F_173 ( V_242 , V_20 -> V_224 , L_37 , L_35 ,
V_219 -> V_223 ) ;
if ( V_114 ) {
V_240 = L_38 ;
goto V_245;
}
V_114 = F_173 ( V_242 , V_20 -> V_224 ,
L_39 , L_35 , V_219 -> V_221 ) ;
if ( V_114 ) {
V_240 = L_40 ;
goto V_245;
}
V_114 = F_173 ( V_242 , V_20 -> V_224 , L_41 , L_35 ,
1 ) ;
if ( V_114 ) {
V_240 = L_42 ;
goto V_245;
}
V_114 = F_173 ( V_242 , V_20 -> V_224 , L_43 , L_19 , 1 ) ;
if ( V_114 ) {
V_240 = L_44 ;
goto V_245;
}
V_114 = F_173 ( V_242 , V_20 -> V_224 , L_18 , L_19 , 1 ) ;
if ( V_114 ) {
V_240 = L_45 ;
goto V_245;
}
V_114 = F_173 ( V_242 , V_20 -> V_224 , L_20 , L_19 , 1 ) ;
if ( V_114 ) {
V_240 = L_46 ;
goto V_245;
}
V_114 = F_174 ( V_242 , 0 ) ;
if ( V_114 ) {
if ( V_114 == - V_246 )
goto V_243;
F_144 ( V_20 , V_114 , L_47 ) ;
goto V_244;
}
return 0 ;
V_245:
F_174 ( V_242 , 1 ) ;
F_144 ( V_20 , V_114 , L_48 , V_240 ) ;
V_244:
F_151 ( V_219 ) ;
V_146:
return V_114 ;
}
static int F_175 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_14 , V_247 , V_114 ;
struct V_10 * V_5 ;
T_2 V_16 ;
struct V_37 * V_38 ;
unsigned int V_248 ;
V_114 = F_125 ( V_201 , V_12 -> V_57 -> V_202 ,
L_49 , L_35 , & V_248 ) ;
if ( V_114 != 1 )
V_248 = 0 ;
if ( ! V_248 ) {
F_119 ( & V_20 -> V_20 ,
L_50 ) ;
return - V_249 ;
}
V_114 = F_171 ( V_12 -> V_57 , V_12 ) ;
if ( V_114 )
return V_114 ;
F_176 () ;
F_177 ( V_20 ) ;
F_178 () ;
F_43 ( & V_12 -> V_62 ) ;
F_66 ( & V_12 -> V_91 ) ;
F_112 ( V_12 ) ;
for ( V_247 = 0 , V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
if ( ! V_12 -> V_15 [ V_14 ] )
continue;
V_5 = V_12 -> V_15 [ V_247 ] = F_7 ( V_12 , V_14 ) ;
V_16 = V_12 -> V_17 [ V_247 ] = F_8 ( V_12 , V_14 ) ;
V_38 = F_35 ( & V_12 -> V_34 , V_247 ) ;
F_36 (
V_16 , V_12 -> V_57 -> V_58 ,
F_37 ( F_33 ( F_28 ( V_5 ) ->
V_50 -> V_30 ) ) ,
0 ) ;
V_38 -> V_59 = V_16 ;
V_38 -> V_3 = V_247 ;
V_247 ++ ;
}
V_12 -> V_34 . V_26 = V_247 ;
F_179 ( V_12 -> V_60 ) ;
F_40 ( V_12 -> V_60 -> V_61 ) ;
F_47 ( V_20 ) ;
F_20 ( V_20 ) ;
F_69 ( & V_12 -> V_91 ) ;
F_45 ( & V_12 -> V_62 ) ;
return 0 ;
}
static void F_180 ( struct V_204 * V_20 ,
enum V_250 V_251 )
{
struct V_11 * V_12 = F_154 ( & V_20 -> V_20 ) ;
struct V_19 * V_60 = V_12 -> V_60 ;
F_155 ( & V_20 -> V_20 , L_28 , F_181 ( V_251 ) ) ;
switch ( V_251 ) {
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
break;
case V_259 :
if ( V_20 -> V_260 != V_252 )
break;
if ( F_175 ( V_60 ) != 0 )
break;
F_182 ( V_20 , V_256 ) ;
F_183 ( V_60 ) ;
break;
case V_261 :
F_184 ( V_20 ) ;
break;
}
}
static int F_185 ( struct V_19 * V_20 , int V_262 )
{
switch ( V_262 ) {
case V_263 :
return F_186 ( V_264 ) ;
default:
return - V_117 ;
}
}
static void F_187 ( struct V_19 * V_20 ,
struct V_265 * V_87 , T_4 * V_23 )
{
void * V_12 = F_11 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_186 ( V_264 ) ; V_14 ++ )
V_23 [ V_14 ] = * ( unsigned long * ) ( V_12 + V_264 [ V_14 ] . V_78 ) ;
}
static void F_188 ( struct V_19 * V_20 , T_5 V_266 , T_7 * V_23 )
{
int V_14 ;
switch ( V_266 ) {
case V_263 :
for ( V_14 = 0 ; V_14 < F_186 ( V_264 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_267 ,
V_264 [ V_14 ] . V_239 , V_267 ) ;
break;
}
}
static T_9 F_189 ( struct V_113 * V_20 ,
struct V_268 * V_269 , char * V_270 )
{
struct V_19 * V_60 = F_190 ( V_20 ) ;
struct V_11 * V_219 = F_11 ( V_60 ) ;
return sprintf ( V_270 , L_51 , V_219 -> V_173 ) ;
}
static T_9 F_191 ( struct V_113 * V_20 ,
struct V_268 * V_269 ,
const char * V_270 , T_10 V_79 )
{
struct V_19 * V_60 = F_190 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_271 ;
unsigned long V_272 ;
if ( ! F_192 ( V_273 ) )
return - V_274 ;
V_272 = F_158 ( V_270 , & V_271 , 0 ) ;
if ( V_271 == V_270 )
return - V_275 ;
if ( V_272 < V_276 )
V_272 = V_276 ;
if ( V_272 > V_207 )
V_272 = V_207 ;
F_43 ( & V_12 -> V_62 ) ;
if ( V_272 > V_12 -> V_55 )
V_12 -> V_55 = V_272 ;
V_12 -> V_173 = V_272 ;
if ( V_272 > V_12 -> V_39 )
V_12 -> V_39 = V_272 ;
F_20 ( V_60 ) ;
F_45 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_9 F_193 ( struct V_113 * V_20 ,
struct V_268 * V_269 , char * V_270 )
{
struct V_19 * V_60 = F_190 ( V_20 ) ;
struct V_11 * V_219 = F_11 ( V_60 ) ;
return sprintf ( V_270 , L_51 , V_219 -> V_55 ) ;
}
static T_9 F_194 ( struct V_113 * V_20 ,
struct V_268 * V_269 ,
const char * V_270 , T_10 V_79 )
{
struct V_19 * V_60 = F_190 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_271 ;
unsigned long V_272 ;
if ( ! F_192 ( V_273 ) )
return - V_274 ;
V_272 = F_158 ( V_270 , & V_271 , 0 ) ;
if ( V_271 == V_270 )
return - V_275 ;
if ( V_272 < V_276 )
V_272 = V_276 ;
if ( V_272 > V_207 )
V_272 = V_207 ;
F_43 ( & V_12 -> V_62 ) ;
if ( V_272 < V_12 -> V_173 )
V_12 -> V_173 = V_272 ;
V_12 -> V_55 = V_272 ;
if ( V_272 < V_12 -> V_39 )
V_12 -> V_39 = V_272 ;
F_20 ( V_60 ) ;
F_45 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_9 F_195 ( struct V_113 * V_20 ,
struct V_268 * V_269 , char * V_270 )
{
struct V_19 * V_60 = F_190 ( V_20 ) ;
struct V_11 * V_219 = F_11 ( V_60 ) ;
return sprintf ( V_270 , L_51 , V_219 -> V_39 ) ;
}
static int F_147 ( struct V_19 * V_60 )
{
int V_14 ;
int V_114 ;
for ( V_14 = 0 ; V_14 < F_186 ( V_277 ) ; V_14 ++ ) {
V_114 = F_196 ( & V_60 -> V_20 ,
& V_277 [ V_14 ] ) ;
if ( V_114 )
goto V_220;
}
return 0 ;
V_220:
while ( -- V_14 >= 0 )
F_197 ( & V_60 -> V_20 , & V_277 [ V_14 ] ) ;
return V_114 ;
}
static void F_198 ( struct V_19 * V_60 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_186 ( V_277 ) ; V_14 ++ )
F_197 ( & V_60 -> V_20 , & V_277 [ V_14 ] ) ;
}
static int T_11 F_199 ( struct V_204 * V_20 )
{
struct V_11 * V_219 = F_154 ( & V_20 -> V_20 ) ;
F_155 ( & V_20 -> V_20 , L_28 , V_20 -> V_224 ) ;
F_148 ( V_219 -> V_60 ) ;
F_151 ( V_219 ) ;
F_200 ( & V_219 -> V_47 ) ;
F_198 ( V_219 -> V_60 ) ;
F_139 ( V_219 -> V_87 ) ;
F_140 ( V_219 -> V_60 ) ;
return 0 ;
}
static int T_12 F_201 ( void )
{
if ( ! F_202 () )
return - V_249 ;
if ( F_203 () )
return 0 ;
F_51 ( V_278 L_52 ) ;
return F_204 ( & V_279 ) ;
}
static void T_13 F_205 ( void )
{
if ( F_203 () )
return;
F_206 ( & V_279 ) ;
}
