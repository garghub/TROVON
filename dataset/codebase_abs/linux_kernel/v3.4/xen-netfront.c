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
F_28 ( V_5 , 0 , V_30 , 0 , 0 ) ;
F_29 ( V_5 ) -> V_50 = 1 ;
F_30 ( & V_12 -> V_40 , V_5 ) ;
}
if ( V_14 < ( V_12 -> V_39 / 2 ) ) {
if ( V_33 > V_12 -> V_34 . V_51 -> V_33 )
goto V_52;
return;
}
if ( ( ( V_33 - V_12 -> V_34 . V_51 -> V_53 ) < ( V_12 -> V_39 / 4 ) ) &&
( ( V_12 -> V_39 *= 2 ) > V_12 -> V_54 ) )
V_12 -> V_39 = V_12 -> V_54 ;
V_46:
for ( V_14 = 0 ; ; V_14 ++ ) {
V_5 = F_31 ( & V_12 -> V_40 ) ;
if ( V_5 == NULL )
break;
V_5 -> V_20 = V_20 ;
V_3 = F_6 ( V_33 + V_14 ) ;
F_32 ( V_12 -> V_15 [ V_3 ] ) ;
V_12 -> V_15 [ V_3 ] = V_5 ;
V_16 = F_33 ( & V_12 -> V_55 ) ;
F_32 ( ( signed short ) V_16 < 0 ) ;
V_12 -> V_17 [ V_3 ] = V_16 ;
V_35 = F_34 ( F_35 ( & F_29 ( V_5 ) -> V_56 [ 0 ] ) ) ;
V_36 = F_36 ( F_35 ( & F_29 ( V_5 ) -> V_56 [ 0 ] ) ) ;
V_38 = F_37 ( & V_12 -> V_34 , V_33 + V_14 ) ;
F_38 ( V_16 ,
V_12 -> V_57 -> V_58 ,
F_39 ( V_35 ) ,
0 ) ;
V_38 -> V_3 = V_3 ;
V_38 -> V_59 = V_16 ;
}
F_40 () ;
V_12 -> V_34 . V_26 = V_33 + V_14 ;
V_52:
F_41 ( & V_12 -> V_34 , V_32 ) ;
if ( V_32 )
F_42 ( V_12 -> V_60 -> V_61 ) ;
}
static int F_43 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_44 ( & V_12 -> V_24 ) ;
F_45 ( & V_12 -> V_62 ) ;
if ( F_21 ( V_20 ) ) {
F_20 ( V_20 ) ;
V_12 -> V_34 . V_51 -> V_63 = V_12 -> V_34 . V_27 + 1 ;
if ( F_46 ( & V_12 -> V_34 ) )
F_12 ( & V_12 -> V_24 ) ;
}
F_47 ( & V_12 -> V_62 ) ;
F_48 ( V_20 ) ;
return 0 ;
}
static void F_49 ( struct V_19 * V_20 )
{
T_1 V_64 , V_65 ;
unsigned short V_3 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_10 * V_5 ;
F_32 ( ! F_21 ( V_20 ) ) ;
do {
V_65 = V_12 -> V_25 . V_51 -> V_53 ;
F_50 () ;
for ( V_64 = V_12 -> V_25 . V_27 ; V_64 != V_65 ; V_64 ++ ) {
struct V_66 * V_67 ;
V_67 = F_51 ( & V_12 -> V_25 , V_64 ) ;
if ( V_67 -> V_68 == V_69 )
continue;
V_3 = V_67 -> V_3 ;
V_5 = V_12 -> V_70 [ V_3 ] . V_5 ;
if ( F_15 ( F_52 (
V_12 -> V_71 [ V_3 ] ) != 0 ) ) {
F_53 ( V_72 L_1
L_2
L_3 ) ;
F_54 () ;
}
F_55 (
V_12 -> V_71 [ V_3 ] , V_73 ) ;
F_56 (
& V_12 -> V_74 , V_12 -> V_71 [ V_3 ] ) ;
V_12 -> V_71 [ V_3 ] = V_18 ;
F_4 ( & V_12 -> V_75 , V_12 -> V_70 , V_3 ) ;
F_57 ( V_5 ) ;
}
V_12 -> V_25 . V_27 = V_65 ;
V_12 -> V_25 . V_51 -> V_63 =
V_65 + ( ( V_12 -> V_25 . V_51 -> V_33 - V_65 ) >> 1 ) + 1 ;
F_58 () ;
} while ( ( V_64 == V_65 ) && ( V_65 != V_12 -> V_25 . V_51 -> V_53 ) );
F_14 ( V_20 ) ;
}
static void F_59 ( struct V_10 * V_5 , struct V_19 * V_20 ,
struct V_76 * V_25 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
char * V_23 = V_5 -> V_23 ;
unsigned long V_77 ;
T_1 V_65 = V_12 -> V_25 . V_26 ;
int V_56 = F_29 ( V_5 ) -> V_50 ;
unsigned int V_78 = F_60 ( V_23 ) ;
unsigned int V_79 = F_61 ( V_5 ) ;
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
V_12 -> V_70 [ V_3 ] . V_5 = F_62 ( V_5 ) ;
V_25 = F_37 ( & V_12 -> V_25 , V_65 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_33 ( & V_12 -> V_74 ) ;
F_32 ( ( signed short ) V_16 < 0 ) ;
V_77 = F_63 ( V_23 ) ;
F_38 ( V_16 , V_12 -> V_57 -> V_58 ,
V_77 , V_73 ) ;
V_25 -> V_59 = V_12 -> V_71 [ V_3 ] = V_16 ;
V_25 -> V_78 = V_78 ;
V_25 -> V_81 = V_79 ;
V_25 -> V_82 = 0 ;
}
for ( V_14 = 0 ; V_14 < V_56 ; V_14 ++ ) {
T_3 * V_84 = F_29 ( V_5 ) -> V_56 + V_14 ;
V_25 -> V_82 |= V_83 ;
V_3 = F_5 ( & V_12 -> V_75 , V_12 -> V_70 ) ;
V_12 -> V_70 [ V_3 ] . V_5 = F_62 ( V_5 ) ;
V_25 = F_37 ( & V_12 -> V_25 , V_65 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_33 ( & V_12 -> V_74 ) ;
F_32 ( ( signed short ) V_16 < 0 ) ;
V_77 = F_39 ( F_34 ( F_35 ( V_84 ) ) ) ;
F_38 ( V_16 , V_12 -> V_57 -> V_58 ,
V_77 , V_73 ) ;
V_25 -> V_59 = V_12 -> V_71 [ V_3 ] = V_16 ;
V_25 -> V_78 = V_84 -> V_85 ;
V_25 -> V_81 = F_64 ( V_84 ) ;
V_25 -> V_82 = 0 ;
}
V_12 -> V_25 . V_26 = V_65 ;
}
static int F_65 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
unsigned short V_3 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_86 * V_87 = F_66 ( V_12 -> V_87 ) ;
struct V_76 * V_25 ;
struct V_88 * V_89 ;
char * V_23 = V_5 -> V_23 ;
T_1 V_14 ;
T_2 V_16 ;
unsigned long V_77 ;
int V_32 ;
int V_56 = F_29 ( V_5 ) -> V_50 ;
unsigned int V_78 = F_60 ( V_23 ) ;
unsigned int V_79 = F_61 ( V_5 ) ;
unsigned long V_82 ;
V_56 += F_67 ( V_78 + V_79 , V_80 ) ;
if ( F_15 ( V_56 > V_29 + 1 ) ) {
F_53 ( V_72 L_4 ,
V_56 ) ;
F_68 () ;
goto V_90;
}
F_69 ( & V_12 -> V_91 , V_82 ) ;
if ( F_15 ( ! F_21 ( V_20 ) ||
( V_56 > 1 && ! F_9 ( V_20 ) ) ||
F_70 ( V_5 , F_71 ( V_5 ) ) ) ) {
F_72 ( & V_12 -> V_91 , V_82 ) ;
goto V_90;
}
V_14 = V_12 -> V_25 . V_26 ;
V_3 = F_5 ( & V_12 -> V_75 , V_12 -> V_70 ) ;
V_12 -> V_70 [ V_3 ] . V_5 = V_5 ;
V_25 = F_37 ( & V_12 -> V_25 , V_14 ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_33 ( & V_12 -> V_74 ) ;
F_32 ( ( signed short ) V_16 < 0 ) ;
V_77 = F_63 ( V_23 ) ;
F_38 (
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
if ( F_29 ( V_5 ) -> V_97 ) {
struct V_88 * V_98 ;
V_98 = (struct V_88 * )
F_37 ( & V_12 -> V_25 , ++ V_14 ) ;
if ( V_89 )
V_89 -> V_82 |= V_99 ;
else
V_25 -> V_82 |= V_100 ;
V_98 -> V_101 . V_98 . V_81 = F_29 ( V_5 ) -> V_97 ;
V_98 -> V_101 . V_98 . type = V_102 ;
V_98 -> V_101 . V_98 . V_103 = 0 ;
V_98 -> V_101 . V_98 . V_21 = 0 ;
V_98 -> type = V_104 ;
V_98 -> V_82 = 0 ;
V_89 = V_98 ;
}
V_12 -> V_25 . V_26 = V_14 + 1 ;
F_59 ( V_5 , V_20 , V_25 ) ;
V_25 -> V_81 = V_5 -> V_79 ;
F_41 ( & V_12 -> V_25 , V_32 ) ;
if ( V_32 )
F_42 ( V_12 -> V_60 -> V_61 ) ;
F_73 ( & V_87 -> V_105 ) ;
V_87 -> V_106 += V_5 -> V_79 ;
V_87 -> V_107 ++ ;
F_74 ( & V_87 -> V_105 ) ;
F_49 ( V_20 ) ;
if ( ! F_13 ( V_12 ) )
F_75 ( V_20 ) ;
F_72 ( & V_12 -> V_91 , V_82 ) ;
return V_108 ;
V_90:
V_20 -> V_87 . V_109 ++ ;
F_76 ( V_5 ) ;
return V_108 ;
}
static int F_77 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_75 ( V_12 -> V_60 ) ;
F_78 ( & V_12 -> V_24 ) ;
return 0 ;
}
static void F_79 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_110 = F_6 ( V_12 -> V_34 . V_26 ) ;
F_32 ( V_12 -> V_15 [ V_110 ] ) ;
V_12 -> V_15 [ V_110 ] = V_5 ;
V_12 -> V_17 [ V_110 ] = V_16 ;
F_37 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_3 = V_110 ;
F_37 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_59 = V_16 ;
V_12 -> V_34 . V_26 ++ ;
}
static int F_80 ( struct V_11 * V_12 ,
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
if ( F_81 () )
F_82 ( V_20 , L_5 ) ;
V_114 = - V_115 ;
break;
}
V_89 = (struct V_88 * )
F_51 ( & V_12 -> V_34 , ++ V_64 ) ;
if ( F_15 ( ! V_89 -> type ||
V_89 -> type >= V_116 ) ) {
if ( F_81 () )
F_82 ( V_20 , L_6 ,
V_89 -> type ) ;
V_114 = - V_117 ;
} else {
memcpy ( & V_111 [ V_89 -> type - 1 ] , V_89 ,
sizeof( * V_89 ) ) ;
}
V_5 = F_7 ( V_12 , V_64 ) ;
V_16 = F_8 ( V_12 , V_64 ) ;
F_79 ( V_12 , V_5 , V_16 ) ;
} while ( V_89 -> V_82 & V_99 );
V_12 -> V_34 . V_27 = V_64 ;
return V_114 ;
}
static int F_83 ( struct V_11 * V_12 ,
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
int V_56 = 1 ;
int V_114 = 0 ;
unsigned long V_123 ;
if ( V_34 -> V_82 & V_124 ) {
V_114 = F_80 ( V_12 , V_111 , V_112 ) ;
V_64 = V_12 -> V_34 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_34 -> V_68 < 0 ||
V_34 -> V_78 + V_34 -> V_68 > V_80 ) ) {
if ( F_81 () )
F_82 ( V_20 , L_7 ,
V_34 -> V_78 , V_34 -> V_68 ) ;
F_79 ( V_12 , V_5 , V_16 ) ;
V_114 = - V_117 ;
goto V_125;
}
if ( V_16 == V_18 ) {
if ( F_81 () )
F_82 ( V_20 , L_8 ,
V_34 -> V_3 ) ;
V_114 = - V_117 ;
goto V_125;
}
V_123 = F_55 ( V_16 , 0 ) ;
F_32 ( ! V_123 ) ;
F_56 ( & V_12 -> V_55 , V_16 ) ;
F_30 ( V_2 , V_5 ) ;
V_125:
if ( ! ( V_34 -> V_82 & V_126 ) )
break;
if ( V_64 + V_56 == V_112 ) {
if ( F_81 () )
F_82 ( V_20 , L_9 ) ;
V_114 = - V_127 ;
break;
}
V_34 = F_51 ( & V_12 -> V_34 , V_64 + V_56 ) ;
V_5 = F_7 ( V_12 , V_64 + V_56 ) ;
V_16 = F_8 ( V_12 , V_64 + V_56 ) ;
V_56 ++ ;
}
if ( F_15 ( V_56 > V_122 ) ) {
if ( F_81 () )
F_82 ( V_20 , L_10 ) ;
V_114 = - V_128 ;
}
if ( F_15 ( V_114 ) )
V_12 -> V_34 . V_27 = V_64 + V_56 ;
return V_114 ;
}
static int F_84 ( struct V_10 * V_5 ,
struct V_88 * V_98 )
{
if ( ! V_98 -> V_101 . V_98 . V_81 ) {
if ( F_81 () )
F_53 ( V_129 L_11 ) ;
return - V_117 ;
}
if ( V_98 -> V_101 . V_98 . type != V_102 ) {
if ( F_81 () )
F_53 ( V_129 L_12 , V_98 -> V_101 . V_98 . type ) ;
return - V_117 ;
}
F_29 ( V_5 ) -> V_97 = V_98 -> V_101 . V_98 . V_81 ;
F_29 ( V_5 ) -> V_130 = V_131 ;
F_29 ( V_5 ) -> V_130 |= V_132 ;
F_29 ( V_5 ) -> V_133 = 0 ;
return 0 ;
}
static T_1 F_85 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_120 * V_2 )
{
struct V_134 * V_135 = F_29 ( V_5 ) ;
int V_50 = V_135 -> V_50 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
struct V_10 * V_136 ;
while ( ( V_136 = F_31 ( V_2 ) ) ) {
struct V_121 * V_34 =
F_51 ( & V_12 -> V_34 , ++ V_64 ) ;
T_3 * V_137 = & F_29 ( V_136 ) -> V_56 [ 0 ] ;
F_28 ( V_5 , V_50 ,
F_35 ( V_137 ) ,
V_34 -> V_78 , V_34 -> V_68 ) ;
V_5 -> V_138 += V_34 -> V_68 ;
F_29 ( V_136 ) -> V_50 = 0 ;
F_26 ( V_136 ) ;
V_50 ++ ;
}
V_135 -> V_50 = V_50 ;
return V_64 ;
}
static int F_86 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
struct V_139 * V_140 ;
unsigned char * V_141 ;
int V_114 = - V_142 ;
int V_143 = 0 ;
if ( V_5 -> V_92 != V_93 && F_87 ( V_5 ) ) {
struct V_11 * V_12 = F_11 ( V_20 ) ;
V_12 -> V_144 ++ ;
V_5 -> V_92 = V_93 ;
V_143 = 1 ;
}
if ( V_5 -> V_92 != V_93 )
return 0 ;
if ( V_5 -> V_145 != F_88 ( V_146 ) )
goto V_147;
V_140 = ( void * ) V_5 -> V_23 ;
V_141 = V_5 -> V_23 + 4 * V_140 -> V_148 ;
if ( V_141 >= F_89 ( V_5 ) )
goto V_147;
V_5 -> V_149 = V_141 - V_5 -> V_7 ;
switch ( V_140 -> V_145 ) {
case V_150 :
V_5 -> V_151 = F_90 ( struct V_152 , V_153 ) ;
if ( V_143 ) {
struct V_152 * V_154 = (struct V_152 * ) V_141 ;
V_154 -> V_153 = ~ F_91 ( V_140 -> V_155 , V_140 -> V_156 ,
V_5 -> V_79 - V_140 -> V_148 * 4 ,
V_150 , 0 ) ;
}
break;
case V_157 :
V_5 -> V_151 = F_90 ( struct V_158 , V_153 ) ;
if ( V_143 ) {
struct V_158 * V_159 = (struct V_158 * ) V_141 ;
V_159 -> V_153 = ~ F_91 ( V_140 -> V_155 , V_140 -> V_156 ,
V_5 -> V_79 - V_140 -> V_148 * 4 ,
V_157 , 0 ) ;
}
break;
default:
if ( F_81 () )
F_53 ( V_160 L_13
L_14
L_15 , V_140 -> V_145 ) ;
goto V_147;
}
if ( ( V_141 + V_5 -> V_151 + 2 ) > F_89 ( V_5 ) )
goto V_147;
V_114 = 0 ;
V_147:
return V_114 ;
}
static int F_92 ( struct V_19 * V_20 ,
struct V_120 * V_161 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_86 * V_87 = F_66 ( V_12 -> V_87 ) ;
int V_162 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_31 ( V_161 ) ) != NULL ) {
struct V_30 * V_30 = F_93 ( V_5 ) -> V_30 ;
void * V_36 = F_36 ( V_30 ) ;
unsigned V_78 = F_93 ( V_5 ) -> V_78 ;
memcpy ( V_5 -> V_23 , V_36 + V_78 ,
F_61 ( V_5 ) ) ;
if ( V_30 != F_35 ( & F_29 ( V_5 ) -> V_56 [ 0 ] ) )
F_94 ( V_30 ) ;
V_5 -> V_145 = F_95 ( V_5 , V_20 ) ;
if ( F_86 ( V_20 , V_5 ) ) {
F_26 ( V_5 ) ;
V_162 ++ ;
V_20 -> V_87 . V_163 ++ ;
continue;
}
F_73 ( & V_87 -> V_105 ) ;
V_87 -> V_164 ++ ;
V_87 -> V_165 += V_5 -> V_79 ;
F_74 ( & V_87 -> V_105 ) ;
F_96 ( V_5 ) ;
}
return V_162 ;
}
static int F_97 ( struct V_166 * V_24 , int V_167 )
{
struct V_11 * V_12 = F_98 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_60 ;
struct V_10 * V_5 ;
struct V_118 V_119 ;
struct V_121 * V_34 = & V_119 . V_34 ;
struct V_88 * V_111 = V_119 . V_111 ;
T_1 V_14 , V_112 ;
int V_168 ;
struct V_120 V_161 ;
struct V_120 V_169 ;
struct V_120 V_170 ;
unsigned long V_82 ;
unsigned int V_79 ;
int V_114 ;
F_99 ( & V_12 -> V_62 ) ;
F_100 ( & V_161 ) ;
F_100 ( & V_169 ) ;
F_100 ( & V_170 ) ;
V_112 = V_12 -> V_34 . V_51 -> V_53 ;
F_50 () ;
V_14 = V_12 -> V_34 . V_27 ;
V_168 = 0 ;
while ( ( V_14 != V_112 ) && ( V_168 < V_167 ) ) {
memcpy ( V_34 , F_51 ( & V_12 -> V_34 , V_14 ) , sizeof( * V_34 ) ) ;
memset ( V_111 , 0 , sizeof( V_119 . V_111 ) ) ;
V_114 = F_83 ( V_12 , & V_119 , V_112 , & V_170 ) ;
if ( F_15 ( V_114 ) ) {
V_114:
while ( ( V_5 = F_31 ( & V_170 ) ) )
F_30 ( & V_169 , V_5 ) ;
V_20 -> V_87 . V_163 ++ ;
V_14 = V_12 -> V_34 . V_27 ;
continue;
}
V_5 = F_31 ( & V_170 ) ;
if ( V_111 [ V_104 - 1 ] . type ) {
struct V_88 * V_98 ;
V_98 = & V_111 [ V_104 - 1 ] ;
if ( F_15 ( F_84 ( V_5 , V_98 ) ) ) {
F_101 ( & V_170 , V_5 ) ;
V_12 -> V_34 . V_27 += F_22 ( & V_170 ) ;
goto V_114;
}
}
F_93 ( V_5 ) -> V_30 =
F_35 ( & F_29 ( V_5 ) -> V_56 [ 0 ] ) ;
F_93 ( V_5 ) -> V_78 = V_34 -> V_78 ;
V_79 = V_34 -> V_68 ;
if ( V_79 > V_41 )
V_79 = V_41 ;
F_102 ( V_5 , V_79 ) ;
if ( V_34 -> V_68 > V_79 ) {
F_29 ( V_5 ) -> V_56 [ 0 ] . V_85 =
V_34 -> V_78 + V_79 ;
F_103 ( & F_29 ( V_5 ) -> V_56 [ 0 ] , V_34 -> V_68 - V_79 ) ;
V_5 -> V_138 = V_34 -> V_68 - V_79 ;
} else {
F_28 ( V_5 , 0 , NULL , 0 , 0 ) ;
F_29 ( V_5 ) -> V_50 = 0 ;
}
V_14 = F_85 ( V_12 , V_5 , & V_170 ) ;
V_5 -> V_171 += V_5 -> V_138 - ( V_41 - V_79 ) ;
V_5 -> V_79 += V_5 -> V_138 ;
if ( V_34 -> V_82 & V_172 )
V_5 -> V_92 = V_93 ;
else if ( V_34 -> V_82 & V_173 )
V_5 -> V_92 = V_96 ;
F_30 ( & V_161 , V_5 ) ;
V_12 -> V_34 . V_27 = ++ V_14 ;
V_168 ++ ;
}
F_104 ( & V_169 ) ;
V_168 -= F_92 ( V_20 , & V_161 ) ;
if ( ( ( V_12 -> V_34 . V_26 - V_12 -> V_34 . V_51 -> V_53 ) >
( ( 3 * V_12 -> V_39 ) / 4 ) ) &&
( -- V_12 -> V_39 < V_12 -> V_174 ) )
V_12 -> V_39 = V_12 -> V_174 ;
F_20 ( V_20 ) ;
if ( V_168 < V_167 ) {
int V_175 = 0 ;
F_105 ( V_82 ) ;
F_106 ( & V_12 -> V_34 , V_175 ) ;
if ( ! V_175 )
F_107 ( V_24 ) ;
F_108 ( V_82 ) ;
}
F_109 ( & V_12 -> V_62 ) ;
return V_168 ;
}
static int F_110 ( struct V_19 * V_20 , int V_176 )
{
int V_122 = F_9 ( V_20 ) ? 65535 - V_177 : V_178 ;
if ( V_176 > V_122 )
return - V_117 ;
V_20 -> V_176 = V_176 ;
return 0 ;
}
static struct V_179 * F_111 ( struct V_19 * V_20 ,
struct V_179 * V_180 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_181 ;
F_112 (cpu) {
struct V_86 * V_87 = F_113 ( V_12 -> V_87 , V_181 ) ;
T_4 V_164 , V_165 , V_107 , V_106 ;
unsigned int V_182 ;
do {
V_182 = F_114 ( & V_87 -> V_105 ) ;
V_164 = V_87 -> V_164 ;
V_107 = V_87 -> V_107 ;
V_165 = V_87 -> V_165 ;
V_106 = V_87 -> V_106 ;
} while ( F_115 ( & V_87 -> V_105 , V_182 ) );
V_180 -> V_164 += V_164 ;
V_180 -> V_107 += V_107 ;
V_180 -> V_165 += V_165 ;
V_180 -> V_106 += V_106 ;
}
V_180 -> V_163 = V_20 -> V_87 . V_163 ;
V_180 -> V_109 = V_20 -> V_87 . V_109 ;
return V_180 ;
}
static void F_116 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_183 ; V_14 ++ ) {
if ( F_2 ( & V_12 -> V_70 [ V_14 ] ) )
continue;
V_5 = V_12 -> V_70 [ V_14 ] . V_5 ;
F_55 ( V_12 -> V_71 [ V_14 ] ,
V_73 ) ;
F_56 ( & V_12 -> V_74 ,
V_12 -> V_71 [ V_14 ] ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
F_4 ( & V_12 -> V_75 , V_12 -> V_70 , V_14 ) ;
F_57 ( V_5 ) ;
}
}
static void F_117 ( struct V_11 * V_12 )
{
struct V_184 * V_185 = V_12 -> V_186 ;
struct V_187 * V_188 = V_12 -> V_189 ;
struct V_120 V_190 ;
struct V_10 * V_5 ;
unsigned long V_77 ;
int V_191 = 0 , V_192 = 0 , V_193 = 0 ;
int V_3 , V_16 ;
F_82 ( & V_12 -> V_60 -> V_20 , L_16 ,
V_194 ) ;
return;
F_100 ( & V_190 ) ;
F_45 ( & V_12 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 ) {
V_193 ++ ;
continue;
}
V_5 = V_12 -> V_15 [ V_3 ] ;
V_77 = F_118 ( V_16 ) ;
F_56 ( & V_12 -> V_55 , V_16 ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
if ( 0 == V_77 ) {
F_29 ( V_5 ) -> V_50 = 0 ;
F_76 ( V_5 ) ;
V_192 ++ ;
continue;
}
if ( ! F_119 ( V_195 ) ) {
const struct V_30 * V_30 =
F_35 ( & F_29 ( V_5 ) -> V_56 [ 0 ] ) ;
unsigned long V_35 = F_34 ( V_30 ) ;
void * V_36 = F_36 ( V_30 ) ;
F_120 ( V_188 , ( unsigned long ) V_36 ,
F_121 ( V_77 , V_196 ) ,
0 ) ;
V_188 ++ ;
V_185 -> V_197 = ( ( T_4 ) V_77 << V_198 )
| V_199 ;
V_185 -> V_200 = V_35 ;
V_185 ++ ;
F_122 ( V_35 , V_77 ) ;
}
F_30 ( & V_190 , V_5 ) ;
V_191 ++ ;
}
F_123 ( & V_12 -> V_60 -> V_20 , L_17 ,
V_194 , V_191 , V_192 , V_193 ) ;
if ( V_191 ) {
if ( ! F_119 ( V_195 ) ) {
F_124 ( V_188 , V_12 -> V_186 , V_185 - V_12 -> V_186 ,
NULL , V_201 ) ;
V_188 ++ ;
F_125 ( V_12 -> V_189 , V_188 - V_12 -> V_189 ) ;
}
}
F_104 ( & V_190 ) ;
F_47 ( & V_12 -> V_62 ) ;
}
static void F_126 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_116 ( V_12 ) ;
F_117 ( V_12 ) ;
F_127 ( V_12 -> V_74 ) ;
F_127 ( V_12 -> V_55 ) ;
}
static T_5 F_128 ( struct V_19 * V_20 ,
T_5 V_21 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_200 ;
if ( V_21 & V_22 ) {
if ( F_129 ( V_202 , V_12 -> V_57 -> V_203 , L_18 ,
L_19 , & V_200 ) < 0 )
V_200 = 0 ;
if ( ! V_200 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_204 ) {
if ( F_129 ( V_202 , V_12 -> V_57 -> V_203 ,
L_20 , L_19 , & V_200 ) < 0 )
V_200 = 0 ;
if ( ! V_200 )
V_21 &= ~ V_204 ;
}
return V_21 ;
}
static int F_130 ( struct V_19 * V_20 ,
T_5 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_176 > V_178 ) {
F_131 ( V_20 , L_21 ) ;
V_20 -> V_176 = V_178 ;
}
return 0 ;
}
static T_6 F_132 ( int V_61 , void * V_205 )
{
struct V_19 * V_20 = V_205 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
unsigned long V_82 ;
F_69 ( & V_12 -> V_91 , V_82 ) ;
if ( F_17 ( F_21 ( V_20 ) ) ) {
F_49 ( V_20 ) ;
if ( F_46 ( & V_12 -> V_34 ) )
F_12 ( & V_12 -> V_24 ) ;
}
F_72 ( & V_12 -> V_91 , V_82 ) ;
return V_206 ;
}
static void F_133 ( struct V_19 * V_20 )
{
F_132 ( 0 , V_20 ) ;
}
static struct V_19 * T_7 F_134 ( struct V_207 * V_20 )
{
int V_14 , V_114 ;
struct V_19 * V_60 ;
struct V_11 * V_12 ;
V_60 = F_135 ( sizeof( struct V_11 ) ) ;
if ( ! V_60 )
return F_136 ( - V_208 ) ;
V_12 = F_11 ( V_60 ) ;
V_12 -> V_57 = V_20 ;
F_137 ( & V_12 -> V_91 ) ;
F_137 ( & V_12 -> V_62 ) ;
F_100 ( & V_12 -> V_40 ) ;
V_12 -> V_39 = V_209 ;
V_12 -> V_174 = V_209 ;
V_12 -> V_54 = V_210 ;
F_138 ( & V_12 -> V_47 ) ;
V_12 -> V_47 . V_23 = ( unsigned long ) V_60 ;
V_12 -> V_47 . V_211 = F_10 ;
V_114 = - V_208 ;
V_12 -> V_87 = F_139 ( struct V_86 ) ;
if ( V_12 -> V_87 == NULL )
goto exit;
V_12 -> V_75 = 0 ;
for ( V_14 = 0 ; V_14 < V_183 ; V_14 ++ ) {
F_1 ( & V_12 -> V_70 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_140 ( V_28 ,
& V_12 -> V_74 ) < 0 ) {
F_53 ( V_72 L_22 ) ;
V_114 = - V_208 ;
goto V_212;
}
if ( F_140 ( V_210 ,
& V_12 -> V_55 ) < 0 ) {
F_53 ( V_72 L_23 ) ;
V_114 = - V_208 ;
goto V_213;
}
V_60 -> V_214 = & V_215 ;
F_141 ( V_60 , & V_12 -> V_24 , F_97 , 64 ) ;
V_60 -> V_21 = V_216 | V_217 |
V_218 ;
V_60 -> V_219 = V_216 | V_22 | V_204 ;
V_60 -> V_21 |= V_60 -> V_219 ;
F_142 ( V_60 , & V_220 ) ;
F_143 ( V_60 , & V_20 -> V_20 ) ;
V_12 -> V_60 = V_60 ;
F_144 ( V_60 ) ;
return V_60 ;
V_213:
F_127 ( V_12 -> V_74 ) ;
V_212:
F_145 ( V_12 -> V_87 ) ;
exit:
F_146 ( V_60 ) ;
return F_136 ( V_114 ) ;
}
static int T_7 F_147 ( struct V_207 * V_20 ,
const struct V_221 * V_3 )
{
int V_114 ;
struct V_19 * V_60 ;
struct V_11 * V_222 ;
V_60 = F_134 ( V_20 ) ;
if ( F_148 ( V_60 ) ) {
V_114 = F_149 ( V_60 ) ;
F_150 ( V_20 , V_114 , L_24 ) ;
return V_114 ;
}
V_222 = F_11 ( V_60 ) ;
F_151 ( & V_20 -> V_20 , V_222 ) ;
V_114 = F_152 ( V_222 -> V_60 ) ;
if ( V_114 ) {
F_53 ( V_129 L_25 ,
V_194 , V_114 ) ;
goto V_223;
}
V_114 = F_153 ( V_222 -> V_60 ) ;
if ( V_114 ) {
F_154 ( V_222 -> V_60 ) ;
F_53 ( V_129 L_26 ,
V_194 , V_114 ) ;
goto V_223;
}
return 0 ;
V_223:
F_146 ( V_60 ) ;
F_151 ( & V_20 -> V_20 , NULL ) ;
return V_114 ;
}
static void F_155 ( int V_16 , void * V_30 )
{
if ( V_16 != V_18 )
F_156 ( V_16 , 0 , ( unsigned long ) V_30 ) ;
}
static void F_157 ( struct V_11 * V_222 )
{
F_45 ( & V_222 -> V_62 ) ;
F_158 ( & V_222 -> V_91 ) ;
F_144 ( V_222 -> V_60 ) ;
F_159 ( & V_222 -> V_91 ) ;
F_47 ( & V_222 -> V_62 ) ;
if ( V_222 -> V_60 -> V_61 )
F_160 ( V_222 -> V_60 -> V_61 , V_222 -> V_60 ) ;
V_222 -> V_224 = V_222 -> V_60 -> V_61 = 0 ;
F_155 ( V_222 -> V_225 , V_222 -> V_25 . V_51 ) ;
F_155 ( V_222 -> V_226 , V_222 -> V_34 . V_51 ) ;
V_222 -> V_225 = V_18 ;
V_222 -> V_226 = V_18 ;
V_222 -> V_25 . V_51 = NULL ;
V_222 -> V_34 . V_51 = NULL ;
}
static int F_161 ( struct V_207 * V_20 )
{
struct V_11 * V_222 = F_162 ( & V_20 -> V_20 ) ;
F_163 ( & V_20 -> V_20 , L_27 , V_20 -> V_227 ) ;
F_157 ( V_222 ) ;
return 0 ;
}
static int F_164 ( struct V_207 * V_20 , T_8 V_228 [] )
{
char * V_229 , * V_230 , * V_231 ;
int V_14 ;
V_231 = V_229 = F_165 ( V_202 , V_20 -> V_227 , L_28 , NULL ) ;
if ( F_148 ( V_231 ) )
return F_149 ( V_231 ) ;
for ( V_14 = 0 ; V_14 < V_232 ; V_14 ++ ) {
V_228 [ V_14 ] = F_166 ( V_229 , & V_230 , 16 ) ;
if ( ( V_229 == V_230 ) || ( * V_230 != ( ( V_14 == V_232 - 1 ) ? '\0' : ':' ) ) ) {
F_167 ( V_231 ) ;
return - V_127 ;
}
V_229 = V_230 + 1 ;
}
F_167 ( V_231 ) ;
return 0 ;
}
static int F_168 ( struct V_207 * V_20 , struct V_11 * V_222 )
{
struct V_233 * V_234 ;
struct V_235 * V_236 ;
int V_114 ;
struct V_19 * V_60 = V_222 -> V_60 ;
V_222 -> V_225 = V_18 ;
V_222 -> V_226 = V_18 ;
V_222 -> V_34 . V_51 = NULL ;
V_222 -> V_25 . V_51 = NULL ;
V_60 -> V_61 = 0 ;
V_114 = F_164 ( V_20 , V_60 -> V_237 ) ;
if ( V_114 ) {
F_150 ( V_20 , V_114 , L_29 , V_20 -> V_227 ) ;
goto V_223;
}
V_234 = (struct V_233 * ) F_169 ( V_238 | V_239 ) ;
if ( ! V_234 ) {
V_114 = - V_208 ;
F_150 ( V_20 , V_114 , L_30 ) ;
goto V_223;
}
F_170 ( V_234 ) ;
F_171 ( & V_222 -> V_25 , V_234 , V_80 ) ;
V_114 = F_172 ( V_20 , F_63 ( V_234 ) ) ;
if ( V_114 < 0 ) {
F_173 ( ( unsigned long ) V_234 ) ;
goto V_223;
}
V_222 -> V_225 = V_114 ;
V_236 = (struct V_235 * ) F_169 ( V_238 | V_239 ) ;
if ( ! V_236 ) {
V_114 = - V_208 ;
F_150 ( V_20 , V_114 , L_31 ) ;
goto V_223;
}
F_170 ( V_236 ) ;
F_171 ( & V_222 -> V_34 , V_236 , V_80 ) ;
V_114 = F_172 ( V_20 , F_63 ( V_236 ) ) ;
if ( V_114 < 0 ) {
F_173 ( ( unsigned long ) V_236 ) ;
goto V_223;
}
V_222 -> V_226 = V_114 ;
V_114 = F_174 ( V_20 , & V_222 -> V_224 ) ;
if ( V_114 )
goto V_223;
V_114 = F_175 ( V_222 -> V_224 , F_132 ,
0 , V_60 -> V_240 , V_60 ) ;
if ( V_114 < 0 )
goto V_223;
V_60 -> V_61 = V_114 ;
return 0 ;
V_223:
return V_114 ;
}
static int F_176 ( struct V_207 * V_20 ,
struct V_11 * V_222 )
{
const char * V_241 ;
struct V_242 V_243 ;
int V_114 ;
V_114 = F_168 ( V_20 , V_222 ) ;
if ( V_114 )
goto V_147;
V_244:
V_114 = F_177 ( & V_243 ) ;
if ( V_114 ) {
F_150 ( V_20 , V_114 , L_32 ) ;
goto V_245;
}
V_114 = F_178 ( V_243 , V_20 -> V_227 , L_33 , L_34 ,
V_222 -> V_225 ) ;
if ( V_114 ) {
V_241 = L_35 ;
goto V_246;
}
V_114 = F_178 ( V_243 , V_20 -> V_227 , L_36 , L_34 ,
V_222 -> V_226 ) ;
if ( V_114 ) {
V_241 = L_37 ;
goto V_246;
}
V_114 = F_178 ( V_243 , V_20 -> V_227 ,
L_38 , L_34 , V_222 -> V_224 ) ;
if ( V_114 ) {
V_241 = L_39 ;
goto V_246;
}
V_114 = F_178 ( V_243 , V_20 -> V_227 , L_40 , L_34 ,
1 ) ;
if ( V_114 ) {
V_241 = L_41 ;
goto V_246;
}
V_114 = F_178 ( V_243 , V_20 -> V_227 , L_42 , L_19 , 1 ) ;
if ( V_114 ) {
V_241 = L_43 ;
goto V_246;
}
V_114 = F_178 ( V_243 , V_20 -> V_227 , L_18 , L_19 , 1 ) ;
if ( V_114 ) {
V_241 = L_44 ;
goto V_246;
}
V_114 = F_178 ( V_243 , V_20 -> V_227 , L_20 , L_19 , 1 ) ;
if ( V_114 ) {
V_241 = L_45 ;
goto V_246;
}
V_114 = F_179 ( V_243 , 0 ) ;
if ( V_114 ) {
if ( V_114 == - V_247 )
goto V_244;
F_150 ( V_20 , V_114 , L_46 ) ;
goto V_245;
}
return 0 ;
V_246:
F_179 ( V_243 , 1 ) ;
F_150 ( V_20 , V_114 , L_47 , V_241 ) ;
V_245:
F_157 ( V_222 ) ;
V_147:
return V_114 ;
}
static int F_180 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_14 , V_248 , V_114 ;
struct V_10 * V_5 ;
T_2 V_16 ;
struct V_37 * V_38 ;
unsigned int V_249 ;
V_114 = F_129 ( V_202 , V_12 -> V_57 -> V_203 ,
L_48 , L_34 , & V_249 ) ;
if ( V_114 != 1 )
V_249 = 0 ;
if ( ! V_249 ) {
F_123 ( & V_20 -> V_20 ,
L_49 ) ;
return - V_250 ;
}
V_114 = F_176 ( V_12 -> V_57 , V_12 ) ;
if ( V_114 )
return V_114 ;
F_181 () ;
F_182 ( V_20 ) ;
F_183 () ;
F_45 ( & V_12 -> V_62 ) ;
F_158 ( & V_12 -> V_91 ) ;
F_116 ( V_12 ) ;
for ( V_248 = 0 , V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
T_3 * V_84 ;
const struct V_30 * V_30 ;
if ( ! V_12 -> V_15 [ V_14 ] )
continue;
V_5 = V_12 -> V_15 [ V_248 ] = F_7 ( V_12 , V_14 ) ;
V_16 = V_12 -> V_17 [ V_248 ] = F_8 ( V_12 , V_14 ) ;
V_38 = F_37 ( & V_12 -> V_34 , V_248 ) ;
V_84 = & F_29 ( V_5 ) -> V_56 [ 0 ] ;
V_30 = F_35 ( V_84 ) ;
F_38 (
V_16 , V_12 -> V_57 -> V_58 ,
F_39 ( F_34 ( V_30 ) ) ,
0 ) ;
V_38 -> V_59 = V_16 ;
V_38 -> V_3 = V_248 ;
V_248 ++ ;
}
V_12 -> V_34 . V_26 = V_248 ;
F_184 ( V_12 -> V_60 ) ;
F_42 ( V_12 -> V_60 -> V_61 ) ;
F_49 ( V_20 ) ;
F_20 ( V_20 ) ;
F_159 ( & V_12 -> V_91 ) ;
F_47 ( & V_12 -> V_62 ) ;
return 0 ;
}
static void F_185 ( struct V_207 * V_20 ,
enum V_251 V_252 )
{
struct V_11 * V_12 = F_162 ( & V_20 -> V_20 ) ;
struct V_19 * V_60 = V_12 -> V_60 ;
F_163 ( & V_20 -> V_20 , L_27 , F_186 ( V_252 ) ) ;
switch ( V_252 ) {
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
break;
case V_259 :
if ( V_20 -> V_260 != V_253 )
break;
if ( F_180 ( V_60 ) != 0 )
break;
F_187 ( V_20 , V_261 ) ;
break;
case V_261 :
F_188 ( V_60 ) ;
break;
case V_262 :
F_189 ( V_20 ) ;
break;
}
}
static int F_190 ( struct V_19 * V_20 , int V_263 )
{
switch ( V_263 ) {
case V_264 :
return F_191 ( V_265 ) ;
default:
return - V_117 ;
}
}
static void F_192 ( struct V_19 * V_20 ,
struct V_266 * V_87 , T_4 * V_23 )
{
void * V_12 = F_11 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_191 ( V_265 ) ; V_14 ++ )
V_23 [ V_14 ] = * ( unsigned long * ) ( V_12 + V_265 [ V_14 ] . V_78 ) ;
}
static void F_193 ( struct V_19 * V_20 , T_9 V_267 , T_8 * V_23 )
{
int V_14 ;
switch ( V_267 ) {
case V_264 :
for ( V_14 = 0 ; V_14 < F_191 ( V_265 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_268 ,
V_265 [ V_14 ] . V_240 , V_268 ) ;
break;
}
}
static T_10 F_194 ( struct V_113 * V_20 ,
struct V_269 * V_270 , char * V_271 )
{
struct V_19 * V_60 = F_195 ( V_20 ) ;
struct V_11 * V_222 = F_11 ( V_60 ) ;
return sprintf ( V_271 , L_50 , V_222 -> V_174 ) ;
}
static T_10 F_196 ( struct V_113 * V_20 ,
struct V_269 * V_270 ,
const char * V_271 , T_11 V_79 )
{
struct V_19 * V_60 = F_195 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_272 ;
unsigned long V_273 ;
if ( ! F_197 ( V_274 ) )
return - V_275 ;
V_273 = F_166 ( V_271 , & V_272 , 0 ) ;
if ( V_272 == V_271 )
return - V_276 ;
if ( V_273 < V_277 )
V_273 = V_277 ;
if ( V_273 > V_210 )
V_273 = V_210 ;
F_45 ( & V_12 -> V_62 ) ;
if ( V_273 > V_12 -> V_54 )
V_12 -> V_54 = V_273 ;
V_12 -> V_174 = V_273 ;
if ( V_273 > V_12 -> V_39 )
V_12 -> V_39 = V_273 ;
F_20 ( V_60 ) ;
F_47 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_10 F_198 ( struct V_113 * V_20 ,
struct V_269 * V_270 , char * V_271 )
{
struct V_19 * V_60 = F_195 ( V_20 ) ;
struct V_11 * V_222 = F_11 ( V_60 ) ;
return sprintf ( V_271 , L_50 , V_222 -> V_54 ) ;
}
static T_10 F_199 ( struct V_113 * V_20 ,
struct V_269 * V_270 ,
const char * V_271 , T_11 V_79 )
{
struct V_19 * V_60 = F_195 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_272 ;
unsigned long V_273 ;
if ( ! F_197 ( V_274 ) )
return - V_275 ;
V_273 = F_166 ( V_271 , & V_272 , 0 ) ;
if ( V_272 == V_271 )
return - V_276 ;
if ( V_273 < V_277 )
V_273 = V_277 ;
if ( V_273 > V_210 )
V_273 = V_210 ;
F_45 ( & V_12 -> V_62 ) ;
if ( V_273 < V_12 -> V_174 )
V_12 -> V_174 = V_273 ;
V_12 -> V_54 = V_273 ;
if ( V_273 < V_12 -> V_39 )
V_12 -> V_39 = V_273 ;
F_20 ( V_60 ) ;
F_47 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_10 F_200 ( struct V_113 * V_20 ,
struct V_269 * V_270 , char * V_271 )
{
struct V_19 * V_60 = F_195 ( V_20 ) ;
struct V_11 * V_222 = F_11 ( V_60 ) ;
return sprintf ( V_271 , L_50 , V_222 -> V_39 ) ;
}
static int F_153 ( struct V_19 * V_60 )
{
int V_14 ;
int V_114 ;
for ( V_14 = 0 ; V_14 < F_191 ( V_278 ) ; V_14 ++ ) {
V_114 = F_201 ( & V_60 -> V_20 ,
& V_278 [ V_14 ] ) ;
if ( V_114 )
goto V_223;
}
return 0 ;
V_223:
while ( -- V_14 >= 0 )
F_202 ( & V_60 -> V_20 , & V_278 [ V_14 ] ) ;
return V_114 ;
}
static void F_203 ( struct V_19 * V_60 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_191 ( V_278 ) ; V_14 ++ )
F_202 ( & V_60 -> V_20 , & V_278 [ V_14 ] ) ;
}
static int T_12 F_204 ( struct V_207 * V_20 )
{
struct V_11 * V_222 = F_162 ( & V_20 -> V_20 ) ;
F_163 ( & V_20 -> V_20 , L_27 , V_20 -> V_227 ) ;
F_154 ( V_222 -> V_60 ) ;
F_157 ( V_222 ) ;
F_205 ( & V_222 -> V_47 ) ;
F_203 ( V_222 -> V_60 ) ;
F_145 ( V_222 -> V_87 ) ;
F_146 ( V_222 -> V_60 ) ;
return 0 ;
}
static int T_13 F_206 ( void )
{
if ( ! F_207 () )
return - V_250 ;
if ( F_208 () )
return 0 ;
if ( F_209 () && ! V_279 )
return - V_250 ;
F_53 ( V_280 L_51 ) ;
return F_210 ( & V_281 ) ;
}
static void T_14 F_211 ( void )
{
if ( F_208 () )
return;
F_212 ( & V_281 ) ;
}
