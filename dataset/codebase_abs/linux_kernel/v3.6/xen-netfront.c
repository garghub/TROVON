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
int V_163 = F_93 ( V_5 ) -> V_163 ;
F_94 ( V_5 , V_163 - F_61 ( V_5 ) ) ;
V_5 -> V_145 = F_95 ( V_5 , V_20 ) ;
if ( F_86 ( V_20 , V_5 ) ) {
F_26 ( V_5 ) ;
V_162 ++ ;
V_20 -> V_87 . V_164 ++ ;
continue;
}
F_73 ( & V_87 -> V_105 ) ;
V_87 -> V_165 ++ ;
V_87 -> V_166 += V_5 -> V_79 ;
F_74 ( & V_87 -> V_105 ) ;
F_96 ( V_5 ) ;
}
return V_162 ;
}
static int F_97 ( struct V_167 * V_24 , int V_168 )
{
struct V_11 * V_12 = F_98 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_60 ;
struct V_10 * V_5 ;
struct V_118 V_119 ;
struct V_121 * V_34 = & V_119 . V_34 ;
struct V_88 * V_111 = V_119 . V_111 ;
T_1 V_14 , V_112 ;
int V_169 ;
struct V_120 V_161 ;
struct V_120 V_170 ;
struct V_120 V_171 ;
unsigned long V_82 ;
int V_114 ;
F_99 ( & V_12 -> V_62 ) ;
F_100 ( & V_161 ) ;
F_100 ( & V_170 ) ;
F_100 ( & V_171 ) ;
V_112 = V_12 -> V_34 . V_51 -> V_53 ;
F_50 () ;
V_14 = V_12 -> V_34 . V_27 ;
V_169 = 0 ;
while ( ( V_14 != V_112 ) && ( V_169 < V_168 ) ) {
memcpy ( V_34 , F_51 ( & V_12 -> V_34 , V_14 ) , sizeof( * V_34 ) ) ;
memset ( V_111 , 0 , sizeof( V_119 . V_111 ) ) ;
V_114 = F_83 ( V_12 , & V_119 , V_112 , & V_171 ) ;
if ( F_15 ( V_114 ) ) {
V_114:
while ( ( V_5 = F_31 ( & V_171 ) ) )
F_30 ( & V_170 , V_5 ) ;
V_20 -> V_87 . V_164 ++ ;
V_14 = V_12 -> V_34 . V_27 ;
continue;
}
V_5 = F_31 ( & V_171 ) ;
if ( V_111 [ V_104 - 1 ] . type ) {
struct V_88 * V_98 ;
V_98 = & V_111 [ V_104 - 1 ] ;
if ( F_15 ( F_84 ( V_5 , V_98 ) ) ) {
F_101 ( & V_171 , V_5 ) ;
V_12 -> V_34 . V_27 += F_22 ( & V_171 ) ;
goto V_114;
}
}
F_93 ( V_5 ) -> V_163 = V_34 -> V_68 ;
if ( F_93 ( V_5 ) -> V_163 > V_41 )
F_93 ( V_5 ) -> V_163 = V_41 ;
F_29 ( V_5 ) -> V_56 [ 0 ] . V_85 = V_34 -> V_78 ;
F_102 ( & F_29 ( V_5 ) -> V_56 [ 0 ] , V_34 -> V_68 ) ;
V_5 -> V_138 = V_34 -> V_68 ;
V_14 = F_85 ( V_12 , V_5 , & V_171 ) ;
V_5 -> V_172 += V_5 -> V_138 - V_41 ;
V_5 -> V_79 += V_5 -> V_138 ;
if ( V_34 -> V_82 & V_173 )
V_5 -> V_92 = V_93 ;
else if ( V_34 -> V_82 & V_174 )
V_5 -> V_92 = V_96 ;
F_30 ( & V_161 , V_5 ) ;
V_12 -> V_34 . V_27 = ++ V_14 ;
V_169 ++ ;
}
F_103 ( & V_170 ) ;
V_169 -= F_92 ( V_20 , & V_161 ) ;
if ( ( ( V_12 -> V_34 . V_26 - V_12 -> V_34 . V_51 -> V_53 ) >
( ( 3 * V_12 -> V_39 ) / 4 ) ) &&
( -- V_12 -> V_39 < V_12 -> V_175 ) )
V_12 -> V_39 = V_12 -> V_175 ;
F_20 ( V_20 ) ;
if ( V_169 < V_168 ) {
int V_176 = 0 ;
F_104 ( V_82 ) ;
F_105 ( & V_12 -> V_34 , V_176 ) ;
if ( ! V_176 )
F_106 ( V_24 ) ;
F_107 ( V_82 ) ;
}
F_108 ( & V_12 -> V_62 ) ;
return V_169 ;
}
static int F_109 ( struct V_19 * V_20 , int V_177 )
{
int V_122 = F_9 ( V_20 ) ? 65535 - V_178 : V_179 ;
if ( V_177 > V_122 )
return - V_117 ;
V_20 -> V_177 = V_177 ;
return 0 ;
}
static struct V_180 * F_110 ( struct V_19 * V_20 ,
struct V_180 * V_181 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_182 ;
F_111 (cpu) {
struct V_86 * V_87 = F_112 ( V_12 -> V_87 , V_182 ) ;
T_4 V_165 , V_166 , V_107 , V_106 ;
unsigned int V_183 ;
do {
V_183 = F_113 ( & V_87 -> V_105 ) ;
V_165 = V_87 -> V_165 ;
V_107 = V_87 -> V_107 ;
V_166 = V_87 -> V_166 ;
V_106 = V_87 -> V_106 ;
} while ( F_114 ( & V_87 -> V_105 , V_183 ) );
V_181 -> V_165 += V_165 ;
V_181 -> V_107 += V_107 ;
V_181 -> V_166 += V_166 ;
V_181 -> V_106 += V_106 ;
}
V_181 -> V_164 = V_20 -> V_87 . V_164 ;
V_181 -> V_109 = V_20 -> V_87 . V_109 ;
return V_181 ;
}
static void F_115 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_184 ; V_14 ++ ) {
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
static void F_116 ( struct V_11 * V_12 )
{
struct V_185 * V_186 = V_12 -> V_187 ;
struct V_188 * V_189 = V_12 -> V_190 ;
struct V_120 V_191 ;
struct V_10 * V_5 ;
unsigned long V_77 ;
int V_192 = 0 , V_193 = 0 , V_194 = 0 ;
int V_3 , V_16 ;
F_82 ( & V_12 -> V_60 -> V_20 , L_16 ,
V_195 ) ;
return;
F_100 ( & V_191 ) ;
F_45 ( & V_12 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 ) {
V_194 ++ ;
continue;
}
V_5 = V_12 -> V_15 [ V_3 ] ;
V_77 = F_117 ( V_16 ) ;
F_56 ( & V_12 -> V_55 , V_16 ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
if ( 0 == V_77 ) {
F_29 ( V_5 ) -> V_50 = 0 ;
F_76 ( V_5 ) ;
V_193 ++ ;
continue;
}
if ( ! F_118 ( V_196 ) ) {
const struct V_30 * V_30 =
F_35 ( & F_29 ( V_5 ) -> V_56 [ 0 ] ) ;
unsigned long V_35 = F_34 ( V_30 ) ;
void * V_36 = F_36 ( V_30 ) ;
F_119 ( V_189 , ( unsigned long ) V_36 ,
F_120 ( V_77 , V_197 ) ,
0 ) ;
V_189 ++ ;
V_186 -> V_198 = ( ( T_4 ) V_77 << V_199 )
| V_200 ;
V_186 -> V_201 = V_35 ;
V_186 ++ ;
F_121 ( V_35 , V_77 ) ;
}
F_30 ( & V_191 , V_5 ) ;
V_192 ++ ;
}
F_122 ( & V_12 -> V_60 -> V_20 , L_17 ,
V_195 , V_192 , V_193 , V_194 ) ;
if ( V_192 ) {
if ( ! F_118 ( V_196 ) ) {
F_123 ( V_189 , V_12 -> V_187 , V_186 - V_12 -> V_187 ,
NULL , V_202 ) ;
V_189 ++ ;
F_124 ( V_12 -> V_190 , V_189 - V_12 -> V_190 ) ;
}
}
F_103 ( & V_191 ) ;
F_47 ( & V_12 -> V_62 ) ;
}
static void F_125 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_115 ( V_12 ) ;
F_116 ( V_12 ) ;
F_126 ( V_12 -> V_74 ) ;
F_126 ( V_12 -> V_55 ) ;
}
static T_5 F_127 ( struct V_19 * V_20 ,
T_5 V_21 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_201 ;
if ( V_21 & V_22 ) {
if ( F_128 ( V_203 , V_12 -> V_57 -> V_204 , L_18 ,
L_19 , & V_201 ) < 0 )
V_201 = 0 ;
if ( ! V_201 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_205 ) {
if ( F_128 ( V_203 , V_12 -> V_57 -> V_204 ,
L_20 , L_19 , & V_201 ) < 0 )
V_201 = 0 ;
if ( ! V_201 )
V_21 &= ~ V_205 ;
}
return V_21 ;
}
static int F_129 ( struct V_19 * V_20 ,
T_5 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_177 > V_179 ) {
F_130 ( V_20 , L_21 ) ;
V_20 -> V_177 = V_179 ;
}
return 0 ;
}
static T_6 F_131 ( int V_61 , void * V_206 )
{
struct V_19 * V_20 = V_206 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
unsigned long V_82 ;
F_69 ( & V_12 -> V_91 , V_82 ) ;
if ( F_17 ( F_21 ( V_20 ) ) ) {
F_49 ( V_20 ) ;
if ( F_46 ( & V_12 -> V_34 ) )
F_12 ( & V_12 -> V_24 ) ;
}
F_72 ( & V_12 -> V_91 , V_82 ) ;
return V_207 ;
}
static void F_132 ( struct V_19 * V_20 )
{
F_131 ( 0 , V_20 ) ;
}
static struct V_19 * T_7 F_133 ( struct V_208 * V_20 )
{
int V_14 , V_114 ;
struct V_19 * V_60 ;
struct V_11 * V_12 ;
V_60 = F_134 ( sizeof( struct V_11 ) ) ;
if ( ! V_60 )
return F_135 ( - V_209 ) ;
V_12 = F_11 ( V_60 ) ;
V_12 -> V_57 = V_20 ;
F_136 ( & V_12 -> V_91 ) ;
F_136 ( & V_12 -> V_62 ) ;
F_100 ( & V_12 -> V_40 ) ;
V_12 -> V_39 = V_210 ;
V_12 -> V_175 = V_210 ;
V_12 -> V_54 = V_211 ;
F_137 ( & V_12 -> V_47 ) ;
V_12 -> V_47 . V_23 = ( unsigned long ) V_60 ;
V_12 -> V_47 . V_212 = F_10 ;
V_114 = - V_209 ;
V_12 -> V_87 = F_138 ( struct V_86 ) ;
if ( V_12 -> V_87 == NULL )
goto exit;
V_12 -> V_75 = 0 ;
for ( V_14 = 0 ; V_14 < V_184 ; V_14 ++ ) {
F_1 ( & V_12 -> V_70 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_139 ( V_28 ,
& V_12 -> V_74 ) < 0 ) {
F_53 ( V_72 L_22 ) ;
V_114 = - V_209 ;
goto V_213;
}
if ( F_139 ( V_211 ,
& V_12 -> V_55 ) < 0 ) {
F_53 ( V_72 L_23 ) ;
V_114 = - V_209 ;
goto V_214;
}
V_60 -> V_215 = & V_216 ;
F_140 ( V_60 , & V_12 -> V_24 , F_97 , 64 ) ;
V_60 -> V_21 = V_217 | V_218 |
V_219 ;
V_60 -> V_220 = V_217 | V_22 | V_205 ;
V_60 -> V_21 |= V_60 -> V_220 ;
F_141 ( V_60 , & V_221 ) ;
F_142 ( V_60 , & V_20 -> V_20 ) ;
V_12 -> V_60 = V_60 ;
F_143 ( V_60 ) ;
return V_60 ;
V_214:
F_126 ( V_12 -> V_74 ) ;
V_213:
F_144 ( V_12 -> V_87 ) ;
exit:
F_145 ( V_60 ) ;
return F_135 ( V_114 ) ;
}
static int T_7 F_146 ( struct V_208 * V_20 ,
const struct V_222 * V_3 )
{
int V_114 ;
struct V_19 * V_60 ;
struct V_11 * V_223 ;
V_60 = F_133 ( V_20 ) ;
if ( F_147 ( V_60 ) ) {
V_114 = F_148 ( V_60 ) ;
F_149 ( V_20 , V_114 , L_24 ) ;
return V_114 ;
}
V_223 = F_11 ( V_60 ) ;
F_150 ( & V_20 -> V_20 , V_223 ) ;
V_114 = F_151 ( V_223 -> V_60 ) ;
if ( V_114 ) {
F_53 ( V_129 L_25 ,
V_195 , V_114 ) ;
goto V_224;
}
V_114 = F_152 ( V_223 -> V_60 ) ;
if ( V_114 ) {
F_153 ( V_223 -> V_60 ) ;
F_53 ( V_129 L_26 ,
V_195 , V_114 ) ;
goto V_224;
}
return 0 ;
V_224:
F_145 ( V_60 ) ;
F_150 ( & V_20 -> V_20 , NULL ) ;
return V_114 ;
}
static void F_154 ( int V_16 , void * V_30 )
{
if ( V_16 != V_18 )
F_155 ( V_16 , 0 , ( unsigned long ) V_30 ) ;
}
static void F_156 ( struct V_11 * V_223 )
{
F_45 ( & V_223 -> V_62 ) ;
F_157 ( & V_223 -> V_91 ) ;
F_143 ( V_223 -> V_60 ) ;
F_158 ( & V_223 -> V_91 ) ;
F_47 ( & V_223 -> V_62 ) ;
if ( V_223 -> V_60 -> V_61 )
F_159 ( V_223 -> V_60 -> V_61 , V_223 -> V_60 ) ;
V_223 -> V_225 = V_223 -> V_60 -> V_61 = 0 ;
F_154 ( V_223 -> V_226 , V_223 -> V_25 . V_51 ) ;
F_154 ( V_223 -> V_227 , V_223 -> V_34 . V_51 ) ;
V_223 -> V_226 = V_18 ;
V_223 -> V_227 = V_18 ;
V_223 -> V_25 . V_51 = NULL ;
V_223 -> V_34 . V_51 = NULL ;
}
static int F_160 ( struct V_208 * V_20 )
{
struct V_11 * V_223 = F_161 ( & V_20 -> V_20 ) ;
F_162 ( & V_20 -> V_20 , L_27 , V_20 -> V_228 ) ;
F_156 ( V_223 ) ;
return 0 ;
}
static int F_163 ( struct V_208 * V_20 , T_8 V_229 [] )
{
char * V_230 , * V_231 , * V_232 ;
int V_14 ;
V_232 = V_230 = F_164 ( V_203 , V_20 -> V_228 , L_28 , NULL ) ;
if ( F_147 ( V_232 ) )
return F_148 ( V_232 ) ;
for ( V_14 = 0 ; V_14 < V_233 ; V_14 ++ ) {
V_229 [ V_14 ] = F_165 ( V_230 , & V_231 , 16 ) ;
if ( ( V_230 == V_231 ) || ( * V_231 != ( ( V_14 == V_233 - 1 ) ? '\0' : ':' ) ) ) {
F_166 ( V_232 ) ;
return - V_127 ;
}
V_230 = V_231 + 1 ;
}
F_166 ( V_232 ) ;
return 0 ;
}
static int F_167 ( struct V_208 * V_20 , struct V_11 * V_223 )
{
struct V_234 * V_235 ;
struct V_236 * V_237 ;
int V_114 ;
struct V_19 * V_60 = V_223 -> V_60 ;
V_223 -> V_226 = V_18 ;
V_223 -> V_227 = V_18 ;
V_223 -> V_34 . V_51 = NULL ;
V_223 -> V_25 . V_51 = NULL ;
V_60 -> V_61 = 0 ;
V_114 = F_163 ( V_20 , V_60 -> V_238 ) ;
if ( V_114 ) {
F_149 ( V_20 , V_114 , L_29 , V_20 -> V_228 ) ;
goto V_224;
}
V_235 = (struct V_234 * ) F_168 ( V_239 | V_240 ) ;
if ( ! V_235 ) {
V_114 = - V_209 ;
F_149 ( V_20 , V_114 , L_30 ) ;
goto V_224;
}
F_169 ( V_235 ) ;
F_170 ( & V_223 -> V_25 , V_235 , V_80 ) ;
V_114 = F_171 ( V_20 , F_63 ( V_235 ) ) ;
if ( V_114 < 0 ) {
F_172 ( ( unsigned long ) V_235 ) ;
goto V_224;
}
V_223 -> V_226 = V_114 ;
V_237 = (struct V_236 * ) F_168 ( V_239 | V_240 ) ;
if ( ! V_237 ) {
V_114 = - V_209 ;
F_149 ( V_20 , V_114 , L_31 ) ;
goto V_224;
}
F_169 ( V_237 ) ;
F_170 ( & V_223 -> V_34 , V_237 , V_80 ) ;
V_114 = F_171 ( V_20 , F_63 ( V_237 ) ) ;
if ( V_114 < 0 ) {
F_172 ( ( unsigned long ) V_237 ) ;
goto V_224;
}
V_223 -> V_227 = V_114 ;
V_114 = F_173 ( V_20 , & V_223 -> V_225 ) ;
if ( V_114 )
goto V_224;
V_114 = F_174 ( V_223 -> V_225 , F_131 ,
0 , V_60 -> V_241 , V_60 ) ;
if ( V_114 < 0 )
goto V_224;
V_60 -> V_61 = V_114 ;
return 0 ;
V_224:
return V_114 ;
}
static int F_175 ( struct V_208 * V_20 ,
struct V_11 * V_223 )
{
const char * V_242 ;
struct V_243 V_244 ;
int V_114 ;
V_114 = F_167 ( V_20 , V_223 ) ;
if ( V_114 )
goto V_147;
V_245:
V_114 = F_176 ( & V_244 ) ;
if ( V_114 ) {
F_149 ( V_20 , V_114 , L_32 ) ;
goto V_246;
}
V_114 = F_177 ( V_244 , V_20 -> V_228 , L_33 , L_34 ,
V_223 -> V_226 ) ;
if ( V_114 ) {
V_242 = L_35 ;
goto V_247;
}
V_114 = F_177 ( V_244 , V_20 -> V_228 , L_36 , L_34 ,
V_223 -> V_227 ) ;
if ( V_114 ) {
V_242 = L_37 ;
goto V_247;
}
V_114 = F_177 ( V_244 , V_20 -> V_228 ,
L_38 , L_34 , V_223 -> V_225 ) ;
if ( V_114 ) {
V_242 = L_39 ;
goto V_247;
}
V_114 = F_177 ( V_244 , V_20 -> V_228 , L_40 , L_34 ,
1 ) ;
if ( V_114 ) {
V_242 = L_41 ;
goto V_247;
}
V_114 = F_177 ( V_244 , V_20 -> V_228 , L_42 , L_19 , 1 ) ;
if ( V_114 ) {
V_242 = L_43 ;
goto V_247;
}
V_114 = F_177 ( V_244 , V_20 -> V_228 , L_18 , L_19 , 1 ) ;
if ( V_114 ) {
V_242 = L_44 ;
goto V_247;
}
V_114 = F_177 ( V_244 , V_20 -> V_228 , L_20 , L_19 , 1 ) ;
if ( V_114 ) {
V_242 = L_45 ;
goto V_247;
}
V_114 = F_178 ( V_244 , 0 ) ;
if ( V_114 ) {
if ( V_114 == - V_248 )
goto V_245;
F_149 ( V_20 , V_114 , L_46 ) ;
goto V_246;
}
return 0 ;
V_247:
F_178 ( V_244 , 1 ) ;
F_149 ( V_20 , V_114 , L_47 , V_242 ) ;
V_246:
F_156 ( V_223 ) ;
V_147:
return V_114 ;
}
static int F_179 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_14 , V_249 , V_114 ;
struct V_10 * V_5 ;
T_2 V_16 ;
struct V_37 * V_38 ;
unsigned int V_250 ;
V_114 = F_128 ( V_203 , V_12 -> V_57 -> V_204 ,
L_48 , L_34 , & V_250 ) ;
if ( V_114 != 1 )
V_250 = 0 ;
if ( ! V_250 ) {
F_122 ( & V_20 -> V_20 ,
L_49 ) ;
return - V_251 ;
}
V_114 = F_175 ( V_12 -> V_57 , V_12 ) ;
if ( V_114 )
return V_114 ;
F_180 () ;
F_181 ( V_20 ) ;
F_182 () ;
F_45 ( & V_12 -> V_62 ) ;
F_157 ( & V_12 -> V_91 ) ;
F_115 ( V_12 ) ;
for ( V_249 = 0 , V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
T_3 * V_84 ;
const struct V_30 * V_30 ;
if ( ! V_12 -> V_15 [ V_14 ] )
continue;
V_5 = V_12 -> V_15 [ V_249 ] = F_7 ( V_12 , V_14 ) ;
V_16 = V_12 -> V_17 [ V_249 ] = F_8 ( V_12 , V_14 ) ;
V_38 = F_37 ( & V_12 -> V_34 , V_249 ) ;
V_84 = & F_29 ( V_5 ) -> V_56 [ 0 ] ;
V_30 = F_35 ( V_84 ) ;
F_38 (
V_16 , V_12 -> V_57 -> V_58 ,
F_39 ( F_34 ( V_30 ) ) ,
0 ) ;
V_38 -> V_59 = V_16 ;
V_38 -> V_3 = V_249 ;
V_249 ++ ;
}
V_12 -> V_34 . V_26 = V_249 ;
F_183 ( V_12 -> V_60 ) ;
F_42 ( V_12 -> V_60 -> V_61 ) ;
F_49 ( V_20 ) ;
F_20 ( V_20 ) ;
F_158 ( & V_12 -> V_91 ) ;
F_47 ( & V_12 -> V_62 ) ;
return 0 ;
}
static void F_184 ( struct V_208 * V_20 ,
enum V_252 V_253 )
{
struct V_11 * V_12 = F_161 ( & V_20 -> V_20 ) ;
struct V_19 * V_60 = V_12 -> V_60 ;
F_162 ( & V_20 -> V_20 , L_27 , F_185 ( V_253 ) ) ;
switch ( V_253 ) {
case V_254 :
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
break;
case V_260 :
if ( V_20 -> V_261 != V_254 )
break;
if ( F_179 ( V_60 ) != 0 )
break;
F_186 ( V_20 , V_262 ) ;
break;
case V_262 :
F_187 ( V_60 ) ;
break;
case V_263 :
F_188 ( V_20 ) ;
break;
}
}
static int F_189 ( struct V_19 * V_20 , int V_264 )
{
switch ( V_264 ) {
case V_265 :
return F_190 ( V_266 ) ;
default:
return - V_117 ;
}
}
static void F_191 ( struct V_19 * V_20 ,
struct V_267 * V_87 , T_4 * V_23 )
{
void * V_12 = F_11 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_190 ( V_266 ) ; V_14 ++ )
V_23 [ V_14 ] = * ( unsigned long * ) ( V_12 + V_266 [ V_14 ] . V_78 ) ;
}
static void F_192 ( struct V_19 * V_20 , T_9 V_268 , T_8 * V_23 )
{
int V_14 ;
switch ( V_268 ) {
case V_265 :
for ( V_14 = 0 ; V_14 < F_190 ( V_266 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_269 ,
V_266 [ V_14 ] . V_241 , V_269 ) ;
break;
}
}
static T_10 F_193 ( struct V_113 * V_20 ,
struct V_270 * V_271 , char * V_272 )
{
struct V_19 * V_60 = F_194 ( V_20 ) ;
struct V_11 * V_223 = F_11 ( V_60 ) ;
return sprintf ( V_272 , L_50 , V_223 -> V_175 ) ;
}
static T_10 F_195 ( struct V_113 * V_20 ,
struct V_270 * V_271 ,
const char * V_272 , T_11 V_79 )
{
struct V_19 * V_60 = F_194 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_273 ;
unsigned long V_274 ;
if ( ! F_196 ( V_275 ) )
return - V_276 ;
V_274 = F_165 ( V_272 , & V_273 , 0 ) ;
if ( V_273 == V_272 )
return - V_277 ;
if ( V_274 < V_278 )
V_274 = V_278 ;
if ( V_274 > V_211 )
V_274 = V_211 ;
F_45 ( & V_12 -> V_62 ) ;
if ( V_274 > V_12 -> V_54 )
V_12 -> V_54 = V_274 ;
V_12 -> V_175 = V_274 ;
if ( V_274 > V_12 -> V_39 )
V_12 -> V_39 = V_274 ;
F_20 ( V_60 ) ;
F_47 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_10 F_197 ( struct V_113 * V_20 ,
struct V_270 * V_271 , char * V_272 )
{
struct V_19 * V_60 = F_194 ( V_20 ) ;
struct V_11 * V_223 = F_11 ( V_60 ) ;
return sprintf ( V_272 , L_50 , V_223 -> V_54 ) ;
}
static T_10 F_198 ( struct V_113 * V_20 ,
struct V_270 * V_271 ,
const char * V_272 , T_11 V_79 )
{
struct V_19 * V_60 = F_194 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_273 ;
unsigned long V_274 ;
if ( ! F_196 ( V_275 ) )
return - V_276 ;
V_274 = F_165 ( V_272 , & V_273 , 0 ) ;
if ( V_273 == V_272 )
return - V_277 ;
if ( V_274 < V_278 )
V_274 = V_278 ;
if ( V_274 > V_211 )
V_274 = V_211 ;
F_45 ( & V_12 -> V_62 ) ;
if ( V_274 < V_12 -> V_175 )
V_12 -> V_175 = V_274 ;
V_12 -> V_54 = V_274 ;
if ( V_274 < V_12 -> V_39 )
V_12 -> V_39 = V_274 ;
F_20 ( V_60 ) ;
F_47 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_10 F_199 ( struct V_113 * V_20 ,
struct V_270 * V_271 , char * V_272 )
{
struct V_19 * V_60 = F_194 ( V_20 ) ;
struct V_11 * V_223 = F_11 ( V_60 ) ;
return sprintf ( V_272 , L_50 , V_223 -> V_39 ) ;
}
static int F_152 ( struct V_19 * V_60 )
{
int V_14 ;
int V_114 ;
for ( V_14 = 0 ; V_14 < F_190 ( V_279 ) ; V_14 ++ ) {
V_114 = F_200 ( & V_60 -> V_20 ,
& V_279 [ V_14 ] ) ;
if ( V_114 )
goto V_224;
}
return 0 ;
V_224:
while ( -- V_14 >= 0 )
F_201 ( & V_60 -> V_20 , & V_279 [ V_14 ] ) ;
return V_114 ;
}
static void F_202 ( struct V_19 * V_60 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_190 ( V_279 ) ; V_14 ++ )
F_201 ( & V_60 -> V_20 , & V_279 [ V_14 ] ) ;
}
static int T_12 F_203 ( struct V_208 * V_20 )
{
struct V_11 * V_223 = F_161 ( & V_20 -> V_20 ) ;
F_162 ( & V_20 -> V_20 , L_27 , V_20 -> V_228 ) ;
F_156 ( V_223 ) ;
F_202 ( V_223 -> V_60 ) ;
F_153 ( V_223 -> V_60 ) ;
F_204 ( & V_223 -> V_47 ) ;
F_144 ( V_223 -> V_87 ) ;
F_145 ( V_223 -> V_60 ) ;
return 0 ;
}
static int T_13 F_205 ( void )
{
if ( ! F_206 () )
return - V_251 ;
if ( F_207 () && ! V_280 )
return - V_251 ;
F_53 ( V_281 L_51 ) ;
return F_208 ( & V_282 ) ;
}
static void T_14 F_209 ( void )
{
F_210 ( & V_282 ) ;
}
