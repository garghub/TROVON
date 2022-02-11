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
static void F_20 ( struct V_11 * V_12 )
{
unsigned short V_3 ;
struct V_10 * V_5 ;
struct V_34 * V_34 ;
int V_14 , V_35 , V_36 ;
T_1 V_37 = V_12 -> V_38 . V_26 ;
T_2 V_16 ;
unsigned long V_39 ;
void * V_40 ;
struct V_41 * V_42 ;
if ( F_15 ( ! F_21 ( V_12 -> V_30 -> V_31 ) ) )
return;
V_35 = V_12 -> V_43 - ( V_37 - V_12 -> V_38 . V_27 ) ;
for ( V_14 = F_22 ( & V_12 -> V_44 ) ; V_14 < V_35 ; V_14 ++ ) {
V_5 = F_23 ( V_12 -> V_30 -> V_31 ,
V_45 + V_46 ,
V_47 | V_48 ) ;
if ( F_15 ( ! V_5 ) )
goto V_49;
F_24 ( V_5 , V_46 ) ;
V_34 = F_25 ( V_47 | V_48 ) ;
if ( ! V_34 ) {
F_26 ( V_5 ) ;
V_49:
F_27 ( & V_12 -> V_50 ,
V_51 + ( V_52 / 10 ) ) ;
if ( V_14 != 0 )
goto V_53;
break;
}
F_28 ( V_5 , 0 , V_34 , 0 , 0 , V_54 ) ;
F_29 ( & V_12 -> V_44 , V_5 ) ;
}
if ( V_14 < ( V_12 -> V_43 / 2 ) ) {
if ( V_37 > V_12 -> V_38 . V_55 -> V_37 )
goto V_56;
return;
}
if ( ( ( V_37 - V_12 -> V_38 . V_55 -> V_57 ) < ( V_12 -> V_43 / 4 ) ) &&
( ( V_12 -> V_43 *= 2 ) > V_12 -> V_58 ) )
V_12 -> V_43 = V_12 -> V_58 ;
V_53:
for ( V_14 = 0 ; ; V_14 ++ ) {
V_5 = F_30 ( & V_12 -> V_44 ) ;
if ( V_5 == NULL )
break;
V_5 -> V_20 = V_12 -> V_30 -> V_31 ;
V_3 = F_6 ( V_37 + V_14 ) ;
F_31 ( V_12 -> V_15 [ V_3 ] ) ;
V_12 -> V_15 [ V_3 ] = V_5 ;
V_16 = F_32 ( & V_12 -> V_59 ) ;
F_31 ( ( signed short ) V_16 < 0 ) ;
V_12 -> V_17 [ V_3 ] = V_16 ;
V_39 = F_33 ( F_34 ( & F_35 ( V_5 ) -> V_60 [ 0 ] ) ) ;
V_40 = F_36 ( F_34 ( & F_35 ( V_5 ) -> V_60 [ 0 ] ) ) ;
V_42 = F_37 ( & V_12 -> V_38 , V_37 + V_14 ) ;
F_38 ( V_16 ,
V_12 -> V_30 -> V_61 -> V_62 ,
F_39 ( V_39 ) ,
0 ) ;
V_42 -> V_3 = V_3 ;
V_42 -> V_63 = V_16 ;
}
F_40 () ;
V_12 -> V_38 . V_26 = V_37 + V_14 ;
V_56:
F_41 ( & V_12 -> V_38 , V_36 ) ;
if ( V_36 )
F_42 ( V_12 -> V_64 ) ;
}
static int F_43 ( struct V_19 * V_20 )
{
struct V_65 * V_66 = F_44 ( V_20 ) ;
unsigned int V_67 = V_20 -> V_68 ;
unsigned int V_14 = 0 ;
struct V_11 * V_12 = NULL ;
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 ) {
V_12 = & V_66 -> V_69 [ V_14 ] ;
F_45 ( & V_12 -> V_24 ) ;
F_46 ( & V_12 -> V_70 ) ;
if ( F_21 ( V_20 ) ) {
F_20 ( V_12 ) ;
V_12 -> V_38 . V_55 -> V_71 = V_12 -> V_38 . V_27 + 1 ;
if ( F_47 ( & V_12 -> V_38 ) )
F_11 ( & V_12 -> V_24 ) ;
}
F_48 ( & V_12 -> V_70 ) ;
}
F_49 ( V_20 ) ;
return 0 ;
}
static void F_50 ( struct V_11 * V_12 )
{
T_1 V_72 , V_73 ;
unsigned short V_3 ;
struct V_10 * V_5 ;
F_31 ( ! F_21 ( V_12 -> V_30 -> V_31 ) ) ;
do {
V_73 = V_12 -> V_25 . V_55 -> V_57 ;
F_51 () ;
for ( V_72 = V_12 -> V_25 . V_27 ; V_72 != V_73 ; V_72 ++ ) {
struct V_74 * V_75 ;
V_75 = F_52 ( & V_12 -> V_25 , V_72 ) ;
if ( V_75 -> V_76 == V_77 )
continue;
V_3 = V_75 -> V_3 ;
V_5 = V_12 -> V_78 [ V_3 ] . V_5 ;
if ( F_15 ( F_53 (
V_12 -> V_79 [ V_3 ] ) != 0 ) ) {
F_54 ( L_1 ,
V_80 ) ;
F_55 () ;
}
F_56 (
V_12 -> V_79 [ V_3 ] , V_81 ) ;
F_57 (
& V_12 -> V_82 , V_12 -> V_79 [ V_3 ] ) ;
V_12 -> V_79 [ V_3 ] = V_18 ;
V_12 -> V_83 [ V_3 ] = NULL ;
F_4 ( & V_12 -> V_84 , V_12 -> V_78 , V_3 ) ;
F_58 ( V_5 ) ;
}
V_12 -> V_25 . V_27 = V_73 ;
V_12 -> V_25 . V_55 -> V_71 =
V_73 + ( ( V_12 -> V_25 . V_55 -> V_37 - V_73 ) >> 1 ) + 1 ;
F_59 () ;
} while ( ( V_72 == V_73 ) && ( V_73 != V_12 -> V_25 . V_55 -> V_57 ) );
F_13 ( V_12 ) ;
}
static void F_60 ( struct V_10 * V_5 , struct V_11 * V_12 ,
struct V_85 * V_25 )
{
char * V_23 = V_5 -> V_23 ;
unsigned long V_86 ;
T_1 V_73 = V_12 -> V_25 . V_26 ;
int V_60 = F_35 ( V_5 ) -> V_87 ;
unsigned int V_88 = F_61 ( V_23 ) ;
unsigned int V_89 = F_62 ( V_5 ) ;
unsigned int V_3 ;
T_2 V_16 ;
int V_14 ;
while ( V_89 > V_54 - V_88 ) {
V_25 -> V_90 = V_54 - V_88 ;
V_25 -> V_91 |= V_92 ;
V_89 -= V_25 -> V_90 ;
V_23 += V_25 -> V_90 ;
V_88 = 0 ;
V_3 = F_5 ( & V_12 -> V_84 , V_12 -> V_78 ) ;
V_12 -> V_78 [ V_3 ] . V_5 = F_63 ( V_5 ) ;
V_25 = F_37 ( & V_12 -> V_25 , V_73 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_32 ( & V_12 -> V_82 ) ;
F_31 ( ( signed short ) V_16 < 0 ) ;
V_86 = F_64 ( V_23 ) ;
F_38 ( V_16 , V_12 -> V_30 -> V_61 -> V_62 ,
V_86 , V_81 ) ;
V_12 -> V_83 [ V_3 ] = F_65 ( V_23 ) ;
V_25 -> V_63 = V_12 -> V_79 [ V_3 ] = V_16 ;
V_25 -> V_88 = V_88 ;
V_25 -> V_90 = V_89 ;
V_25 -> V_91 = 0 ;
}
for ( V_14 = 0 ; V_14 < V_60 ; V_14 ++ ) {
T_3 * V_93 = F_35 ( V_5 ) -> V_60 + V_14 ;
struct V_34 * V_34 = F_34 ( V_93 ) ;
V_89 = F_66 ( V_93 ) ;
V_88 = V_93 -> V_94 ;
V_34 += V_88 >> V_95 ;
V_88 &= ~ V_96 ;
while ( V_89 > 0 ) {
unsigned long V_97 ;
V_97 = V_54 - V_88 ;
if ( V_97 > V_89 )
V_97 = V_89 ;
V_25 -> V_91 |= V_92 ;
V_3 = F_5 ( & V_12 -> V_84 ,
V_12 -> V_78 ) ;
V_12 -> V_78 [ V_3 ] . V_5 = F_63 ( V_5 ) ;
V_25 = F_37 ( & V_12 -> V_25 , V_73 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_32 ( & V_12 -> V_82 ) ;
F_31 ( ( signed short ) V_16 < 0 ) ;
V_86 = F_39 ( F_33 ( V_34 ) ) ;
F_38 ( V_16 ,
V_12 -> V_30 -> V_61 -> V_62 ,
V_86 , V_81 ) ;
V_12 -> V_83 [ V_3 ] = V_34 ;
V_25 -> V_63 = V_12 -> V_79 [ V_3 ] = V_16 ;
V_25 -> V_88 = V_88 ;
V_25 -> V_90 = V_97 ;
V_25 -> V_91 = 0 ;
V_88 += V_97 ;
V_89 -= V_97 ;
if ( V_88 == V_54 && V_89 ) {
F_31 ( ! F_67 ( V_34 ) ) ;
V_34 ++ ;
V_88 = 0 ;
}
}
}
V_12 -> V_25 . V_26 = V_73 ;
}
static int F_68 ( struct V_10 * V_5 )
{
int V_14 , V_60 = F_35 ( V_5 ) -> V_87 ;
int V_98 = 0 ;
for ( V_14 = 0 ; V_14 < V_60 ; V_14 ++ ) {
T_3 * V_93 = F_35 ( V_5 ) -> V_60 + V_14 ;
unsigned long V_90 = F_66 ( V_93 ) ;
unsigned long V_88 = V_93 -> V_94 ;
V_88 &= ~ V_96 ;
V_98 += F_69 ( V_88 + V_90 ) ;
}
return V_98 ;
}
static T_4 F_70 ( struct V_19 * V_20 , struct V_10 * V_5 ,
void * V_99 , T_5 V_100 )
{
unsigned int V_67 = V_20 -> V_68 ;
T_6 V_101 ;
T_4 V_102 ;
if ( V_67 == 1 ) {
V_102 = 0 ;
} else {
V_101 = F_71 ( V_5 ) ;
V_102 = V_101 % V_67 ;
}
return V_102 ;
}
static int F_72 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
unsigned short V_3 ;
struct V_65 * V_66 = F_44 ( V_20 ) ;
struct V_103 * V_104 = F_73 ( V_66 -> V_104 ) ;
struct V_85 * V_25 ;
char * V_23 = V_5 -> V_23 ;
T_1 V_14 ;
T_2 V_16 ;
unsigned long V_86 ;
int V_36 ;
int V_105 ;
unsigned int V_88 = F_61 ( V_23 ) ;
unsigned int V_89 = F_62 ( V_5 ) ;
unsigned long V_91 ;
struct V_11 * V_12 = NULL ;
unsigned int V_67 = V_20 -> V_68 ;
T_4 V_106 ;
if ( V_67 < 1 )
goto V_107;
V_106 = F_74 ( V_5 ) ;
V_12 = & V_66 -> V_69 [ V_106 ] ;
if ( F_15 ( V_5 -> V_89 > V_108 ) ) {
F_75 (
L_2 ,
V_5 -> V_89 ) ;
goto V_107;
}
V_105 = F_76 ( V_88 + V_89 , V_54 ) +
F_68 ( V_5 ) ;
if ( F_15 ( V_105 > V_29 + 1 ) ) {
F_77 ( L_3 ,
V_105 , V_5 -> V_89 ) ;
if ( F_78 ( V_5 ) )
goto V_107;
}
F_79 ( & V_12 -> V_109 , V_91 ) ;
if ( F_15 ( ! F_21 ( V_20 ) ||
( V_105 > 1 && ! F_9 ( V_20 ) ) ||
F_80 ( V_20 , V_5 , F_81 ( V_5 ) ) ) ) {
F_82 ( & V_12 -> V_109 , V_91 ) ;
goto V_107;
}
V_14 = V_12 -> V_25 . V_26 ;
V_3 = F_5 ( & V_12 -> V_84 , V_12 -> V_78 ) ;
V_12 -> V_78 [ V_3 ] . V_5 = V_5 ;
V_25 = F_37 ( & V_12 -> V_25 , V_14 ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_32 ( & V_12 -> V_82 ) ;
F_31 ( ( signed short ) V_16 < 0 ) ;
V_86 = F_64 ( V_23 ) ;
F_38 (
V_16 , V_12 -> V_30 -> V_61 -> V_62 , V_86 , V_81 ) ;
V_12 -> V_83 [ V_3 ] = F_65 ( V_23 ) ;
V_25 -> V_63 = V_12 -> V_79 [ V_3 ] = V_16 ;
V_25 -> V_88 = V_88 ;
V_25 -> V_90 = V_89 ;
V_25 -> V_91 = 0 ;
if ( V_5 -> V_110 == V_111 )
V_25 -> V_91 |= V_112 | V_113 ;
else if ( V_5 -> V_110 == V_114 )
V_25 -> V_91 |= V_113 ;
if ( F_35 ( V_5 ) -> V_115 ) {
struct V_116 * V_117 ;
V_117 = (struct V_116 * )
F_37 ( & V_12 -> V_25 , ++ V_14 ) ;
V_25 -> V_91 |= V_118 ;
V_117 -> V_119 . V_117 . V_90 = F_35 ( V_5 ) -> V_115 ;
V_117 -> V_119 . V_117 . type = ( F_35 ( V_5 ) -> V_120 & V_121 ) ?
V_122 :
V_123 ;
V_117 -> V_119 . V_117 . V_124 = 0 ;
V_117 -> V_119 . V_117 . V_21 = 0 ;
V_117 -> type = V_125 ;
V_117 -> V_91 = 0 ;
}
V_12 -> V_25 . V_26 = V_14 + 1 ;
F_60 ( V_5 , V_12 , V_25 ) ;
V_25 -> V_90 = V_5 -> V_89 ;
F_41 ( & V_12 -> V_25 , V_36 ) ;
if ( V_36 )
F_42 ( V_12 -> V_126 ) ;
F_83 ( & V_104 -> V_127 ) ;
V_104 -> V_128 += V_5 -> V_89 ;
V_104 -> V_129 ++ ;
F_84 ( & V_104 -> V_127 ) ;
F_50 ( V_12 ) ;
if ( ! F_12 ( V_12 ) )
F_85 ( F_14 ( V_20 , V_12 -> V_3 ) ) ;
F_82 ( & V_12 -> V_109 , V_91 ) ;
return V_130 ;
V_107:
V_20 -> V_104 . V_131 ++ ;
F_86 ( V_5 ) ;
return V_130 ;
}
static int F_87 ( struct V_19 * V_20 )
{
struct V_65 * V_66 = F_44 ( V_20 ) ;
unsigned int V_67 = V_20 -> V_68 ;
unsigned int V_14 ;
struct V_11 * V_12 ;
F_88 ( V_66 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 ) {
V_12 = & V_66 -> V_69 [ V_14 ] ;
F_89 ( & V_12 -> V_24 ) ;
}
return 0 ;
}
static void F_90 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_132 = F_6 ( V_12 -> V_38 . V_26 ) ;
F_31 ( V_12 -> V_15 [ V_132 ] ) ;
V_12 -> V_15 [ V_132 ] = V_5 ;
V_12 -> V_17 [ V_132 ] = V_16 ;
F_37 ( & V_12 -> V_38 , V_12 -> V_38 . V_26 ) -> V_3 = V_132 ;
F_37 ( & V_12 -> V_38 , V_12 -> V_38 . V_26 ) -> V_63 = V_16 ;
V_12 -> V_38 . V_26 ++ ;
}
static int F_91 ( struct V_11 * V_12 ,
struct V_116 * V_133 ,
T_1 V_134 )
{
struct V_116 * V_135 ;
struct V_136 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_72 = V_12 -> V_38 . V_27 ;
int V_137 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_72 + 1 == V_134 ) ) {
if ( F_92 () )
F_93 ( V_20 , L_4 ) ;
V_137 = - V_138 ;
break;
}
V_135 = (struct V_116 * )
F_52 ( & V_12 -> V_38 , ++ V_72 ) ;
if ( F_15 ( ! V_135 -> type ||
V_135 -> type >= V_139 ) ) {
if ( F_92 () )
F_93 ( V_20 , L_5 ,
V_135 -> type ) ;
V_137 = - V_140 ;
} else {
memcpy ( & V_133 [ V_135 -> type - 1 ] , V_135 ,
sizeof( * V_135 ) ) ;
}
V_5 = F_7 ( V_12 , V_72 ) ;
V_16 = F_8 ( V_12 , V_72 ) ;
F_90 ( V_12 , V_5 , V_16 ) ;
} while ( V_135 -> V_91 & V_141 );
V_12 -> V_38 . V_27 = V_72 ;
return V_137 ;
}
static int F_94 ( struct V_11 * V_12 ,
struct V_142 * V_143 , T_1 V_134 ,
struct V_144 * V_2 )
{
struct V_145 * V_38 = & V_143 -> V_38 ;
struct V_116 * V_133 = V_143 -> V_133 ;
struct V_136 * V_20 = & V_12 -> V_30 -> V_31 -> V_20 ;
T_1 V_72 = V_12 -> V_38 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_72 ) ;
T_2 V_16 = F_8 ( V_12 , V_72 ) ;
int V_146 = V_29 + ( V_38 -> V_76 <= V_45 ) ;
int V_105 = 1 ;
int V_137 = 0 ;
unsigned long V_147 ;
if ( V_38 -> V_91 & V_148 ) {
V_137 = F_91 ( V_12 , V_133 , V_134 ) ;
V_72 = V_12 -> V_38 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_38 -> V_76 < 0 ||
V_38 -> V_88 + V_38 -> V_76 > V_54 ) ) {
if ( F_92 () )
F_93 ( V_20 , L_6 ,
V_38 -> V_88 , V_38 -> V_76 ) ;
F_90 ( V_12 , V_5 , V_16 ) ;
V_137 = - V_140 ;
goto V_149;
}
if ( V_16 == V_18 ) {
if ( F_92 () )
F_93 ( V_20 , L_7 ,
V_38 -> V_3 ) ;
V_137 = - V_140 ;
goto V_149;
}
V_147 = F_56 ( V_16 , 0 ) ;
F_31 ( ! V_147 ) ;
F_57 ( & V_12 -> V_59 , V_16 ) ;
F_29 ( V_2 , V_5 ) ;
V_149:
if ( ! ( V_38 -> V_91 & V_150 ) )
break;
if ( V_72 + V_105 == V_134 ) {
if ( F_92 () )
F_93 ( V_20 , L_8 ) ;
V_137 = - V_151 ;
break;
}
V_38 = F_52 ( & V_12 -> V_38 , V_72 + V_105 ) ;
V_5 = F_7 ( V_12 , V_72 + V_105 ) ;
V_16 = F_8 ( V_12 , V_72 + V_105 ) ;
V_105 ++ ;
}
if ( F_15 ( V_105 > V_146 ) ) {
if ( F_92 () )
F_93 ( V_20 , L_9 ) ;
V_137 = - V_152 ;
}
if ( F_15 ( V_137 ) )
V_12 -> V_38 . V_27 = V_72 + V_105 ;
return V_137 ;
}
static int F_95 ( struct V_10 * V_5 ,
struct V_116 * V_117 )
{
if ( ! V_117 -> V_119 . V_117 . V_90 ) {
if ( F_92 () )
F_96 ( L_10 ) ;
return - V_140 ;
}
if ( V_117 -> V_119 . V_117 . type != V_123 &&
V_117 -> V_119 . V_117 . type != V_122 ) {
if ( F_92 () )
F_96 ( L_11 , V_117 -> V_119 . V_117 . type ) ;
return - V_140 ;
}
F_35 ( V_5 ) -> V_115 = V_117 -> V_119 . V_117 . V_90 ;
F_35 ( V_5 ) -> V_120 =
( V_117 -> V_119 . V_117 . type == V_123 ) ?
V_153 :
V_121 ;
F_35 ( V_5 ) -> V_120 |= V_154 ;
F_35 ( V_5 ) -> V_155 = 0 ;
return 0 ;
}
static T_1 F_97 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_144 * V_2 )
{
struct V_156 * V_157 = F_35 ( V_5 ) ;
T_1 V_72 = V_12 -> V_38 . V_27 ;
struct V_10 * V_158 ;
while ( ( V_158 = F_30 ( V_2 ) ) ) {
struct V_145 * V_38 =
F_52 ( & V_12 -> V_38 , ++ V_72 ) ;
T_3 * V_159 = & F_35 ( V_158 ) -> V_60 [ 0 ] ;
if ( V_157 -> V_87 == V_29 ) {
unsigned int V_160 = F_98 ( V_5 ) -> V_160 ;
F_31 ( V_160 <= F_62 ( V_5 ) ) ;
F_99 ( V_5 , V_160 - F_62 ( V_5 ) ) ;
}
F_31 ( V_157 -> V_87 >= V_29 ) ;
F_28 ( V_5 , V_157 -> V_87 , F_34 ( V_159 ) ,
V_38 -> V_88 , V_38 -> V_76 , V_54 ) ;
F_35 ( V_158 ) -> V_87 = 0 ;
F_26 ( V_158 ) ;
}
return V_72 ;
}
static int F_100 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
bool V_161 = false ;
if ( V_5 -> V_110 != V_111 && F_101 ( V_5 ) ) {
struct V_65 * V_66 = F_44 ( V_20 ) ;
F_102 ( & V_66 -> V_162 ) ;
V_5 -> V_110 = V_111 ;
V_161 = true ;
}
if ( V_5 -> V_110 != V_111 )
return 0 ;
return F_103 ( V_5 , V_161 ) ;
}
static int F_104 ( struct V_11 * V_12 ,
struct V_144 * V_163 )
{
struct V_103 * V_104 = F_73 ( V_12 -> V_30 -> V_104 ) ;
int V_164 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_30 ( V_163 ) ) != NULL ) {
int V_160 = F_98 ( V_5 ) -> V_160 ;
if ( V_160 > F_62 ( V_5 ) )
F_99 ( V_5 , V_160 - F_62 ( V_5 ) ) ;
V_5 -> V_165 = F_105 ( V_5 , V_12 -> V_30 -> V_31 ) ;
F_106 ( V_5 ) ;
if ( F_100 ( V_12 -> V_30 -> V_31 , V_5 ) ) {
F_26 ( V_5 ) ;
V_164 ++ ;
V_12 -> V_30 -> V_31 -> V_104 . V_166 ++ ;
continue;
}
F_83 ( & V_104 -> V_127 ) ;
V_104 -> V_167 ++ ;
V_104 -> V_168 += V_5 -> V_89 ;
F_84 ( & V_104 -> V_127 ) ;
F_107 ( & V_12 -> V_24 , V_5 ) ;
}
return V_164 ;
}
static int F_108 ( struct V_169 * V_24 , int V_170 )
{
struct V_11 * V_12 = F_109 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
struct V_10 * V_5 ;
struct V_142 V_143 ;
struct V_145 * V_38 = & V_143 . V_38 ;
struct V_116 * V_133 = V_143 . V_133 ;
T_1 V_14 , V_134 ;
int V_171 ;
struct V_144 V_163 ;
struct V_144 V_172 ;
struct V_144 V_173 ;
unsigned long V_91 ;
int V_137 ;
F_110 ( & V_12 -> V_70 ) ;
F_111 ( & V_163 ) ;
F_111 ( & V_172 ) ;
F_111 ( & V_173 ) ;
V_134 = V_12 -> V_38 . V_55 -> V_57 ;
F_51 () ;
V_14 = V_12 -> V_38 . V_27 ;
V_171 = 0 ;
while ( ( V_14 != V_134 ) && ( V_171 < V_170 ) ) {
memcpy ( V_38 , F_52 ( & V_12 -> V_38 , V_14 ) , sizeof( * V_38 ) ) ;
memset ( V_133 , 0 , sizeof( V_143 . V_133 ) ) ;
V_137 = F_94 ( V_12 , & V_143 , V_134 , & V_173 ) ;
if ( F_15 ( V_137 ) ) {
V_137:
while ( ( V_5 = F_30 ( & V_173 ) ) )
F_29 ( & V_172 , V_5 ) ;
V_20 -> V_104 . V_166 ++ ;
V_14 = V_12 -> V_38 . V_27 ;
continue;
}
V_5 = F_30 ( & V_173 ) ;
if ( V_133 [ V_125 - 1 ] . type ) {
struct V_116 * V_117 ;
V_117 = & V_133 [ V_125 - 1 ] ;
if ( F_15 ( F_95 ( V_5 , V_117 ) ) ) {
F_112 ( & V_173 , V_5 ) ;
V_12 -> V_38 . V_27 += F_22 ( & V_173 ) ;
goto V_137;
}
}
F_98 ( V_5 ) -> V_160 = V_38 -> V_76 ;
if ( F_98 ( V_5 ) -> V_160 > V_45 )
F_98 ( V_5 ) -> V_160 = V_45 ;
F_35 ( V_5 ) -> V_60 [ 0 ] . V_94 = V_38 -> V_88 ;
F_113 ( & F_35 ( V_5 ) -> V_60 [ 0 ] , V_38 -> V_76 ) ;
V_5 -> V_174 = V_38 -> V_76 ;
V_5 -> V_89 += V_38 -> V_76 ;
V_14 = F_97 ( V_12 , V_5 , & V_173 ) ;
if ( V_38 -> V_91 & V_175 )
V_5 -> V_110 = V_111 ;
else if ( V_38 -> V_91 & V_176 )
V_5 -> V_110 = V_114 ;
F_29 ( & V_163 , V_5 ) ;
V_12 -> V_38 . V_27 = ++ V_14 ;
V_171 ++ ;
}
F_114 ( & V_172 ) ;
V_171 -= F_104 ( V_12 , & V_163 ) ;
if ( ( ( V_12 -> V_38 . V_26 - V_12 -> V_38 . V_55 -> V_57 ) >
( ( 3 * V_12 -> V_43 ) / 4 ) ) &&
( -- V_12 -> V_43 < V_12 -> V_177 ) )
V_12 -> V_43 = V_12 -> V_177 ;
F_20 ( V_12 ) ;
if ( V_171 < V_170 ) {
int V_178 = 0 ;
F_115 ( V_24 , false ) ;
F_116 ( V_91 ) ;
F_117 ( & V_12 -> V_38 , V_178 ) ;
if ( ! V_178 )
F_118 ( V_24 ) ;
F_119 ( V_91 ) ;
}
F_120 ( & V_12 -> V_70 ) ;
return V_171 ;
}
static int F_121 ( struct V_19 * V_20 , int V_179 )
{
int V_146 = F_9 ( V_20 ) ?
V_108 - V_180 : V_181 ;
if ( V_179 > V_146 )
return - V_140 ;
V_20 -> V_179 = V_179 ;
return 0 ;
}
static struct V_182 * F_122 ( struct V_19 * V_20 ,
struct V_182 * V_183 )
{
struct V_65 * V_66 = F_44 ( V_20 ) ;
int V_184 ;
F_123 (cpu) {
struct V_103 * V_104 = F_124 ( V_66 -> V_104 , V_184 ) ;
T_7 V_167 , V_168 , V_129 , V_128 ;
unsigned int V_185 ;
do {
V_185 = F_125 ( & V_104 -> V_127 ) ;
V_167 = V_104 -> V_167 ;
V_129 = V_104 -> V_129 ;
V_168 = V_104 -> V_168 ;
V_128 = V_104 -> V_128 ;
} while ( F_126 ( & V_104 -> V_127 , V_185 ) );
V_183 -> V_167 += V_167 ;
V_183 -> V_129 += V_129 ;
V_183 -> V_168 += V_168 ;
V_183 -> V_128 += V_128 ;
}
V_183 -> V_166 = V_20 -> V_104 . V_166 ;
V_183 -> V_131 = V_20 -> V_104 . V_131 ;
return V_183 ;
}
static void F_127 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_186 ; V_14 ++ ) {
if ( F_2 ( & V_12 -> V_78 [ V_14 ] ) )
continue;
V_5 = V_12 -> V_78 [ V_14 ] . V_5 ;
F_128 ( V_12 -> V_83 [ V_14 ] ) ;
F_129 ( V_12 -> V_79 [ V_14 ] ,
V_81 ,
( unsigned long ) F_36 ( V_12 -> V_83 [ V_14 ] ) ) ;
V_12 -> V_83 [ V_14 ] = NULL ;
V_12 -> V_79 [ V_14 ] = V_18 ;
F_4 ( & V_12 -> V_84 , V_12 -> V_78 , V_14 ) ;
F_58 ( V_5 ) ;
}
}
static void F_130 ( struct V_11 * V_12 )
{
int V_3 , V_16 ;
F_46 ( & V_12 -> V_70 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
struct V_10 * V_5 ;
struct V_34 * V_34 ;
V_5 = V_12 -> V_15 [ V_3 ] ;
if ( ! V_5 )
continue;
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 )
continue;
V_34 = F_34 ( & F_35 ( V_5 ) -> V_60 [ 0 ] ) ;
F_128 ( V_34 ) ;
F_129 ( V_16 , 0 ,
( unsigned long ) F_36 ( V_34 ) ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
F_26 ( V_5 ) ;
}
F_48 ( & V_12 -> V_70 ) ;
}
static T_8 F_131 ( struct V_19 * V_20 ,
T_8 V_21 )
{
struct V_65 * V_66 = F_44 ( V_20 ) ;
int V_187 ;
if ( V_21 & V_22 ) {
if ( F_132 ( V_188 , V_66 -> V_61 -> V_189 , L_12 ,
L_13 , & V_187 ) < 0 )
V_187 = 0 ;
if ( ! V_187 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_190 ) {
if ( F_132 ( V_188 , V_66 -> V_61 -> V_189 ,
L_14 , L_13 , & V_187 ) < 0 )
V_187 = 0 ;
if ( ! V_187 )
V_21 &= ~ V_190 ;
}
if ( V_21 & V_191 ) {
if ( F_132 ( V_188 , V_66 -> V_61 -> V_189 ,
L_15 , L_13 , & V_187 ) < 0 )
V_187 = 0 ;
if ( ! V_187 )
V_21 &= ~ V_191 ;
}
if ( V_21 & V_192 ) {
if ( F_132 ( V_188 , V_66 -> V_61 -> V_189 ,
L_16 , L_13 , & V_187 ) < 0 )
V_187 = 0 ;
if ( ! V_187 )
V_21 &= ~ V_192 ;
}
return V_21 ;
}
static int F_133 ( struct V_19 * V_20 ,
T_8 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_179 > V_181 ) {
F_134 ( V_20 , L_17 ) ;
V_20 -> V_179 = V_181 ;
}
return 0 ;
}
static T_9 F_135 ( int V_193 , void * V_194 )
{
struct V_11 * V_12 = V_194 ;
unsigned long V_91 ;
F_79 ( & V_12 -> V_109 , V_91 ) ;
F_50 ( V_12 ) ;
F_82 ( & V_12 -> V_109 , V_91 ) ;
return V_195 ;
}
static T_9 F_136 ( int V_193 , void * V_194 )
{
struct V_11 * V_12 = V_194 ;
struct V_19 * V_20 = V_12 -> V_30 -> V_31 ;
if ( F_17 ( F_21 ( V_20 ) &&
F_47 ( & V_12 -> V_38 ) ) )
F_11 ( & V_12 -> V_24 ) ;
return V_195 ;
}
static T_9 F_137 ( int V_193 , void * V_194 )
{
F_135 ( V_193 , V_194 ) ;
F_136 ( V_193 , V_194 ) ;
return V_195 ;
}
static void F_138 ( struct V_19 * V_20 )
{
struct V_65 * V_30 = F_44 ( V_20 ) ;
unsigned int V_67 = V_20 -> V_68 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 )
F_137 ( 0 , & V_30 -> V_69 [ V_14 ] ) ;
}
static struct V_19 * F_139 ( struct V_196 * V_20 )
{
int V_137 ;
struct V_19 * V_31 ;
struct V_65 * V_66 ;
V_31 = F_140 ( sizeof( struct V_65 ) , V_197 ) ;
if ( ! V_31 )
return F_141 ( - V_198 ) ;
V_66 = F_44 ( V_31 ) ;
V_66 -> V_61 = V_20 ;
F_142 ( V_31 , 0 ) ;
V_66 -> V_69 = NULL ;
V_137 = - V_198 ;
V_66 -> V_104 = F_143 ( struct V_103 ) ;
if ( V_66 -> V_104 == NULL )
goto exit;
V_31 -> V_199 = & V_200 ;
V_31 -> V_21 = V_201 | V_202 |
V_203 ;
V_31 -> V_204 = V_22 |
V_190 |
V_191 | V_192 ;
V_31 -> V_21 |= V_31 -> V_204 ;
V_31 -> V_205 = & V_206 ;
F_144 ( V_31 , & V_20 -> V_20 ) ;
F_145 ( V_31 , V_108 - V_180 ) ;
V_66 -> V_31 = V_31 ;
F_146 ( V_31 ) ;
return V_31 ;
exit:
F_147 ( V_31 ) ;
return F_141 ( V_137 ) ;
}
static int F_148 ( struct V_196 * V_20 ,
const struct V_207 * V_3 )
{
int V_137 ;
struct V_19 * V_31 ;
struct V_65 * V_30 ;
V_31 = F_139 ( V_20 ) ;
if ( F_149 ( V_31 ) ) {
V_137 = F_150 ( V_31 ) ;
F_151 ( V_20 , V_137 , L_18 ) ;
return V_137 ;
}
V_30 = F_44 ( V_31 ) ;
F_152 ( & V_20 -> V_20 , V_30 ) ;
V_137 = F_153 ( V_30 -> V_31 ) ;
if ( V_137 ) {
F_96 ( L_19 , V_80 , V_137 ) ;
goto V_208;
}
V_137 = F_154 ( V_30 -> V_31 ) ;
if ( V_137 ) {
F_155 ( V_30 -> V_31 ) ;
F_96 ( L_20 , V_80 , V_137 ) ;
goto V_208;
}
return 0 ;
V_208:
F_147 ( V_31 ) ;
F_152 ( & V_20 -> V_20 , NULL ) ;
return V_137 ;
}
static void F_156 ( int V_16 , void * V_34 )
{
if ( V_16 != V_18 )
F_129 ( V_16 , 0 , ( unsigned long ) V_34 ) ;
}
static void F_157 ( struct V_65 * V_30 )
{
unsigned int V_14 = 0 ;
unsigned int V_67 = V_30 -> V_31 -> V_68 ;
F_146 ( V_30 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 ) {
struct V_11 * V_12 = & V_30 -> V_69 [ V_14 ] ;
if ( V_12 -> V_126 && ( V_12 -> V_126 == V_12 -> V_64 ) )
F_158 ( V_12 -> V_126 , V_12 ) ;
if ( V_12 -> V_126 && ( V_12 -> V_126 != V_12 -> V_64 ) ) {
F_158 ( V_12 -> V_126 , V_12 ) ;
F_158 ( V_12 -> V_64 , V_12 ) ;
}
V_12 -> V_209 = V_12 -> V_210 = 0 ;
V_12 -> V_126 = V_12 -> V_64 = 0 ;
F_159 ( & V_12 -> V_24 ) ;
F_127 ( V_12 ) ;
F_130 ( V_12 ) ;
F_160 ( V_12 -> V_82 ) ;
F_160 ( V_12 -> V_59 ) ;
F_156 ( V_12 -> V_211 , V_12 -> V_25 . V_55 ) ;
F_156 ( V_12 -> V_212 , V_12 -> V_38 . V_55 ) ;
V_12 -> V_211 = V_18 ;
V_12 -> V_212 = V_18 ;
V_12 -> V_25 . V_55 = NULL ;
V_12 -> V_38 . V_55 = NULL ;
}
}
static int F_161 ( struct V_196 * V_20 )
{
struct V_65 * V_30 = F_162 ( & V_20 -> V_20 ) ;
F_163 ( & V_20 -> V_20 , L_21 , V_20 -> V_213 ) ;
F_157 ( V_30 ) ;
return 0 ;
}
static int F_164 ( struct V_196 * V_20 , T_10 V_214 [] )
{
char * V_215 , * V_216 , * V_217 ;
int V_14 ;
V_217 = V_215 = F_165 ( V_188 , V_20 -> V_213 , L_22 , NULL ) ;
if ( F_149 ( V_217 ) )
return F_150 ( V_217 ) ;
for ( V_14 = 0 ; V_14 < V_218 ; V_14 ++ ) {
V_214 [ V_14 ] = F_166 ( V_215 , & V_216 , 16 ) ;
if ( ( V_215 == V_216 ) || ( * V_216 != ( ( V_14 == V_218 - 1 ) ? '\0' : ':' ) ) ) {
F_167 ( V_217 ) ;
return - V_151 ;
}
V_215 = V_216 + 1 ;
}
F_167 ( V_217 ) ;
return 0 ;
}
static int F_168 ( struct V_11 * V_12 )
{
int V_137 ;
V_137 = F_169 ( V_12 -> V_30 -> V_61 , & V_12 -> V_209 ) ;
if ( V_137 < 0 )
goto V_208;
V_137 = F_170 ( V_12 -> V_209 ,
F_137 ,
0 , V_12 -> V_30 -> V_31 -> V_219 , V_12 ) ;
if ( V_137 < 0 )
goto V_220;
V_12 -> V_210 = V_12 -> V_209 ;
V_12 -> V_64 = V_12 -> V_126 = V_137 ;
return 0 ;
V_220:
F_171 ( V_12 -> V_30 -> V_61 , V_12 -> V_209 ) ;
V_12 -> V_209 = 0 ;
V_208:
return V_137 ;
}
static int F_172 ( struct V_11 * V_12 )
{
int V_137 ;
V_137 = F_169 ( V_12 -> V_30 -> V_61 , & V_12 -> V_209 ) ;
if ( V_137 < 0 )
goto V_208;
V_137 = F_169 ( V_12 -> V_30 -> V_61 , & V_12 -> V_210 ) ;
if ( V_137 < 0 )
goto V_221;
snprintf ( V_12 -> V_222 , sizeof( V_12 -> V_222 ) ,
L_23 , V_12 -> V_219 ) ;
V_137 = F_170 ( V_12 -> V_209 ,
F_135 ,
0 , V_12 -> V_222 , V_12 ) ;
if ( V_137 < 0 )
goto V_223;
V_12 -> V_126 = V_137 ;
snprintf ( V_12 -> V_224 , sizeof( V_12 -> V_224 ) ,
L_24 , V_12 -> V_219 ) ;
V_137 = F_170 ( V_12 -> V_210 ,
F_136 ,
0 , V_12 -> V_224 , V_12 ) ;
if ( V_137 < 0 )
goto V_225;
V_12 -> V_64 = V_137 ;
return 0 ;
V_225:
F_158 ( V_12 -> V_126 , V_12 ) ;
V_12 -> V_126 = 0 ;
V_223:
F_171 ( V_12 -> V_30 -> V_61 , V_12 -> V_210 ) ;
V_12 -> V_210 = 0 ;
V_221:
F_171 ( V_12 -> V_30 -> V_61 , V_12 -> V_209 ) ;
V_12 -> V_209 = 0 ;
V_208:
return V_137 ;
}
static int F_173 ( struct V_196 * V_20 ,
struct V_11 * V_12 , unsigned int V_226 )
{
struct V_227 * V_228 ;
struct V_229 * V_230 ;
int V_137 ;
V_12 -> V_211 = V_18 ;
V_12 -> V_212 = V_18 ;
V_12 -> V_38 . V_55 = NULL ;
V_12 -> V_25 . V_55 = NULL ;
V_228 = (struct V_227 * ) F_174 ( V_231 | V_232 ) ;
if ( ! V_228 ) {
V_137 = - V_198 ;
F_151 ( V_20 , V_137 , L_25 ) ;
goto V_208;
}
F_175 ( V_228 ) ;
F_176 ( & V_12 -> V_25 , V_228 , V_54 ) ;
V_137 = F_177 ( V_20 , F_64 ( V_228 ) ) ;
if ( V_137 < 0 )
goto V_233;
V_12 -> V_211 = V_137 ;
V_230 = (struct V_229 * ) F_174 ( V_231 | V_232 ) ;
if ( ! V_230 ) {
V_137 = - V_198 ;
F_151 ( V_20 , V_137 , L_26 ) ;
goto V_234;
}
F_175 ( V_230 ) ;
F_176 ( & V_12 -> V_38 , V_230 , V_54 ) ;
V_137 = F_177 ( V_20 , F_64 ( V_230 ) ) ;
if ( V_137 < 0 )
goto V_235;
V_12 -> V_212 = V_137 ;
if ( V_226 )
V_137 = F_172 ( V_12 ) ;
if ( ! V_226 || ( V_226 && V_137 ) )
V_137 = F_168 ( V_12 ) ;
if ( V_137 )
goto V_236;
return 0 ;
V_236:
F_56 ( V_12 -> V_212 , 0 ) ;
V_235:
F_178 ( ( unsigned long ) V_230 ) ;
V_234:
F_56 ( V_12 -> V_211 , 0 ) ;
V_233:
F_178 ( ( unsigned long ) V_228 ) ;
V_208:
return V_137 ;
}
static int F_179 ( struct V_11 * V_12 )
{
unsigned short V_14 ;
int V_137 = 0 ;
F_180 ( & V_12 -> V_109 ) ;
F_180 ( & V_12 -> V_70 ) ;
F_111 ( & V_12 -> V_44 ) ;
V_12 -> V_43 = V_237 ;
V_12 -> V_177 = V_237 ;
V_12 -> V_58 = V_238 ;
F_181 ( & V_12 -> V_50 ) ;
V_12 -> V_50 . V_23 = ( unsigned long ) V_12 ;
V_12 -> V_50 . V_239 = F_10 ;
snprintf ( V_12 -> V_219 , sizeof( V_12 -> V_219 ) , L_27 ,
V_12 -> V_30 -> V_31 -> V_219 , V_12 -> V_3 ) ;
V_12 -> V_84 = 0 ;
for ( V_14 = 0 ; V_14 < V_186 ; V_14 ++ ) {
F_1 ( & V_12 -> V_78 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_79 [ V_14 ] = V_18 ;
V_12 -> V_83 [ V_14 ] = NULL ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_182 ( V_28 ,
& V_12 -> V_82 ) < 0 ) {
F_54 ( L_28 ) ;
V_137 = - V_198 ;
goto exit;
}
if ( F_182 ( V_238 ,
& V_12 -> V_59 ) < 0 ) {
F_54 ( L_29 ) ;
V_137 = - V_198 ;
goto V_240;
}
return 0 ;
V_240:
F_160 ( V_12 -> V_82 ) ;
exit:
return V_137 ;
}
static int F_183 ( struct V_11 * V_12 ,
struct V_241 * V_242 , int V_243 )
{
struct V_196 * V_20 = V_12 -> V_30 -> V_61 ;
int V_137 ;
const char * V_244 ;
char * V_245 ;
T_11 V_246 ;
if ( V_243 ) {
V_246 = strlen ( V_20 -> V_213 ) + 10 ;
V_245 = F_184 ( V_246 , V_247 ) ;
if ( ! V_245 ) {
V_137 = - V_198 ;
V_244 = L_30 ;
goto error;
}
snprintf ( V_245 , V_246 , L_31 ,
V_20 -> V_213 , V_12 -> V_3 ) ;
} else {
V_245 = ( char * ) V_20 -> V_213 ;
}
V_137 = F_185 ( * V_242 , V_245 , L_32 , L_33 ,
V_12 -> V_211 ) ;
if ( V_137 ) {
V_244 = L_34 ;
goto error;
}
V_137 = F_185 ( * V_242 , V_245 , L_35 , L_33 ,
V_12 -> V_212 ) ;
if ( V_137 ) {
V_244 = L_36 ;
goto error;
}
if ( V_12 -> V_209 == V_12 -> V_210 ) {
V_137 = F_185 ( * V_242 , V_245 ,
L_37 , L_33 , V_12 -> V_209 ) ;
if ( V_137 ) {
V_244 = L_38 ;
goto error;
}
} else {
V_137 = F_185 ( * V_242 , V_245 ,
L_39 , L_33 , V_12 -> V_209 ) ;
if ( V_137 ) {
V_244 = L_40 ;
goto error;
}
V_137 = F_185 ( * V_242 , V_245 ,
L_41 , L_33 , V_12 -> V_210 ) ;
if ( V_137 ) {
V_244 = L_42 ;
goto error;
}
}
if ( V_243 )
F_167 ( V_245 ) ;
return 0 ;
error:
if ( V_243 )
F_167 ( V_245 ) ;
F_151 ( V_20 , V_137 , L_43 , V_244 ) ;
return V_137 ;
}
static void F_186 ( struct V_65 * V_30 )
{
unsigned int V_14 ;
F_187 () ;
for ( V_14 = 0 ; V_14 < V_30 -> V_31 -> V_68 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_69 [ V_14 ] ;
if ( F_18 ( V_30 -> V_31 ) )
F_89 ( & V_12 -> V_24 ) ;
F_188 ( & V_12 -> V_24 ) ;
}
F_189 () ;
F_167 ( V_30 -> V_69 ) ;
V_30 -> V_69 = NULL ;
}
static int F_190 ( struct V_65 * V_30 ,
unsigned int V_67 )
{
unsigned int V_14 ;
int V_147 ;
V_30 -> V_69 = F_191 ( V_67 , sizeof( struct V_11 ) ,
V_247 ) ;
if ( ! V_30 -> V_69 )
return - V_198 ;
F_187 () ;
for ( V_14 = 0 ; V_14 < V_67 ; V_14 ++ ) {
struct V_11 * V_12 = & V_30 -> V_69 [ V_14 ] ;
V_12 -> V_3 = V_14 ;
V_12 -> V_30 = V_30 ;
V_147 = F_179 ( V_12 ) ;
if ( V_147 < 0 ) {
F_93 ( & V_30 -> V_31 -> V_20 ,
L_44 , V_14 ) ;
V_67 = V_14 ;
break;
}
F_192 ( V_12 -> V_30 -> V_31 , & V_12 -> V_24 ,
F_108 , 64 ) ;
if ( F_18 ( V_30 -> V_31 ) )
F_45 ( & V_12 -> V_24 ) ;
}
F_142 ( V_30 -> V_31 , V_67 ) ;
F_189 () ;
if ( V_67 == 0 ) {
F_193 ( & V_30 -> V_31 -> V_20 , L_45 ) ;
return - V_140 ;
}
return 0 ;
}
static int F_194 ( struct V_196 * V_20 ,
struct V_65 * V_30 )
{
const char * V_244 ;
struct V_241 V_242 ;
int V_137 ;
unsigned int V_226 ;
unsigned int V_14 = 0 ;
unsigned int V_248 = 0 ;
struct V_11 * V_12 = NULL ;
unsigned int V_67 = 1 ;
V_30 -> V_31 -> V_193 = 0 ;
V_137 = F_132 ( V_188 , V_30 -> V_61 -> V_189 ,
L_46 , L_33 , & V_248 ) ;
if ( V_137 < 0 )
V_248 = 1 ;
V_67 = F_195 ( V_248 , V_197 ) ;
V_137 = F_132 ( V_188 , V_30 -> V_61 -> V_189 ,
L_47 , L_33 ,
& V_226 ) ;
if ( V_137 < 0 )
V_226 = 0 ;
V_137 = F_164 ( V_20 , V_30 -> V_31 -> V_249 ) ;
if ( V_137 ) {
F_151 ( V_20 , V_137 , L_48 , V_20 -> V_213 ) ;
goto V_250;
}
if ( V_30 -> V_69 )
F_186 ( V_30 ) ;
V_137 = F_190 ( V_30 , V_67 ) ;
if ( V_137 < 0 )
goto V_251;
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 ) {
V_12 = & V_30 -> V_69 [ V_14 ] ;
V_137 = F_173 ( V_20 , V_12 , V_226 ) ;
if ( V_137 ) {
if ( V_14 > 0 ) {
F_187 () ;
F_142 ( V_30 -> V_31 , V_14 ) ;
F_189 () ;
goto V_251;
} else {
goto V_250;
}
}
}
V_252:
V_137 = F_196 ( & V_242 ) ;
if ( V_137 ) {
F_151 ( V_20 , V_137 , L_49 ) ;
goto V_251;
}
if ( V_67 == 1 ) {
V_137 = F_183 ( & V_30 -> V_69 [ 0 ] , & V_242 , 0 ) ;
if ( V_137 )
goto V_253;
} else {
V_137 = F_185 ( V_242 , V_20 -> V_213 , L_50 ,
L_33 , V_67 ) ;
if ( V_137 ) {
V_244 = L_51 ;
goto V_253;
}
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 ) {
V_12 = & V_30 -> V_69 [ V_14 ] ;
V_137 = F_183 ( V_12 , & V_242 , 1 ) ;
if ( V_137 )
goto V_253;
}
}
V_137 = F_185 ( V_242 , V_20 -> V_213 , L_52 , L_33 ,
1 ) ;
if ( V_137 ) {
V_244 = L_53 ;
goto V_254;
}
V_137 = F_185 ( V_242 , V_20 -> V_213 , L_54 , L_13 , 1 ) ;
if ( V_137 ) {
V_244 = L_55 ;
goto V_254;
}
V_137 = F_185 ( V_242 , V_20 -> V_213 , L_12 , L_13 , 1 ) ;
if ( V_137 ) {
V_244 = L_56 ;
goto V_254;
}
V_137 = F_185 ( V_242 , V_20 -> V_213 , L_15 , L_13 , 1 ) ;
if ( V_137 ) {
V_244 = L_57 ;
goto V_254;
}
V_137 = F_197 ( V_242 , V_20 -> V_213 , L_16 , L_58 ) ;
if ( V_137 ) {
V_244 = L_59 ;
goto V_254;
}
V_137 = F_197 ( V_242 , V_20 -> V_213 , L_14 ,
L_58 ) ;
if ( V_137 ) {
V_244 = L_60 ;
goto V_254;
}
V_137 = F_198 ( V_242 , 0 ) ;
if ( V_137 ) {
if ( V_137 == - V_255 )
goto V_252;
F_151 ( V_20 , V_137 , L_61 ) ;
goto V_251;
}
return 0 ;
V_254:
F_151 ( V_20 , V_137 , L_43 , V_244 ) ;
V_253:
F_198 ( V_242 , 1 ) ;
V_251:
F_157 ( V_30 ) ;
F_167 ( V_30 -> V_69 ) ;
V_30 -> V_69 = NULL ;
F_187 () ;
F_142 ( V_30 -> V_31 , 0 ) ;
F_189 () ;
V_250:
return V_137 ;
}
static int F_199 ( struct V_19 * V_20 )
{
struct V_65 * V_66 = F_44 ( V_20 ) ;
unsigned int V_67 = 0 ;
int V_137 ;
unsigned int V_256 ;
unsigned int V_257 = 0 ;
struct V_11 * V_12 = NULL ;
V_137 = F_132 ( V_188 , V_66 -> V_61 -> V_189 ,
L_62 , L_33 , & V_256 ) ;
if ( V_137 != 1 )
V_256 = 0 ;
if ( ! V_256 ) {
F_200 ( & V_20 -> V_20 ,
L_63 ) ;
return - V_258 ;
}
V_137 = F_194 ( V_66 -> V_61 , V_66 ) ;
if ( V_137 )
return V_137 ;
V_67 = V_20 -> V_68 ;
F_187 () ;
F_201 ( V_20 ) ;
F_189 () ;
F_202 ( V_66 -> V_31 ) ;
for ( V_257 = 0 ; V_257 < V_67 ; ++ V_257 ) {
V_12 = & V_66 -> V_69 [ V_257 ] ;
F_42 ( V_12 -> V_126 ) ;
if ( V_12 -> V_126 != V_12 -> V_64 )
F_42 ( V_12 -> V_64 ) ;
F_203 ( & V_12 -> V_109 ) ;
F_50 ( V_12 ) ;
F_204 ( & V_12 -> V_109 ) ;
F_46 ( & V_12 -> V_70 ) ;
F_20 ( V_12 ) ;
F_48 ( & V_12 -> V_70 ) ;
}
return 0 ;
}
static void F_205 ( struct V_196 * V_20 ,
enum V_259 V_260 )
{
struct V_65 * V_66 = F_162 ( & V_20 -> V_20 ) ;
struct V_19 * V_31 = V_66 -> V_31 ;
F_163 ( & V_20 -> V_20 , L_21 , F_206 ( V_260 ) ) ;
switch ( V_260 ) {
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
break;
case V_266 :
if ( V_20 -> V_267 != V_261 )
break;
if ( F_199 ( V_31 ) != 0 )
break;
F_207 ( V_20 , V_268 ) ;
break;
case V_268 :
F_208 ( V_31 ) ;
break;
case V_269 :
if ( V_20 -> V_267 == V_269 )
break;
case V_270 :
F_209 ( V_20 ) ;
break;
}
}
static int F_210 ( struct V_19 * V_20 , int V_271 )
{
switch ( V_271 ) {
case V_272 :
return F_211 ( V_273 ) ;
default:
return - V_140 ;
}
}
static void F_212 ( struct V_19 * V_20 ,
struct V_274 * V_104 , T_7 * V_23 )
{
void * V_66 = F_44 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_211 ( V_273 ) ; V_14 ++ )
V_23 [ V_14 ] = F_213 ( ( V_275 * ) ( V_66 + V_273 [ V_14 ] . V_88 ) ) ;
}
static void F_214 ( struct V_19 * V_20 , T_6 V_276 , T_10 * V_23 )
{
int V_14 ;
switch ( V_276 ) {
case V_272 :
for ( V_14 = 0 ; V_14 < F_211 ( V_273 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_277 ,
V_273 [ V_14 ] . V_219 , V_277 ) ;
break;
}
}
static T_12 F_215 ( struct V_136 * V_20 ,
struct V_278 * V_279 , char * V_280 )
{
struct V_19 * V_31 = F_216 ( V_20 ) ;
struct V_65 * V_30 = F_44 ( V_31 ) ;
unsigned int V_67 = V_31 -> V_68 ;
if ( V_67 )
return sprintf ( V_280 , L_64 , V_30 -> V_69 [ 0 ] . V_177 ) ;
else
return sprintf ( V_280 , L_64 , V_281 ) ;
}
static T_12 F_217 ( struct V_136 * V_20 ,
struct V_278 * V_279 ,
const char * V_280 , T_11 V_89 )
{
struct V_19 * V_31 = F_216 ( V_20 ) ;
struct V_65 * V_66 = F_44 ( V_31 ) ;
unsigned int V_67 = V_31 -> V_68 ;
char * V_282 ;
unsigned long V_283 ;
unsigned int V_14 ;
struct V_11 * V_12 ;
if ( ! F_218 ( V_284 ) )
return - V_285 ;
V_283 = F_166 ( V_280 , & V_282 , 0 ) ;
if ( V_282 == V_280 )
return - V_286 ;
if ( V_283 < V_281 )
V_283 = V_281 ;
if ( V_283 > V_238 )
V_283 = V_238 ;
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 ) {
V_12 = & V_66 -> V_69 [ V_14 ] ;
F_46 ( & V_12 -> V_70 ) ;
if ( V_283 > V_12 -> V_58 )
V_12 -> V_58 = V_283 ;
V_12 -> V_177 = V_283 ;
if ( V_283 > V_12 -> V_43 )
V_12 -> V_43 = V_283 ;
F_20 ( V_12 ) ;
F_48 ( & V_12 -> V_70 ) ;
}
return V_89 ;
}
static T_12 F_219 ( struct V_136 * V_20 ,
struct V_278 * V_279 , char * V_280 )
{
struct V_19 * V_31 = F_216 ( V_20 ) ;
struct V_65 * V_30 = F_44 ( V_31 ) ;
unsigned int V_67 = V_31 -> V_68 ;
if ( V_67 )
return sprintf ( V_280 , L_64 , V_30 -> V_69 [ 0 ] . V_58 ) ;
else
return sprintf ( V_280 , L_64 , V_238 ) ;
}
static T_12 F_220 ( struct V_136 * V_20 ,
struct V_278 * V_279 ,
const char * V_280 , T_11 V_89 )
{
struct V_19 * V_31 = F_216 ( V_20 ) ;
struct V_65 * V_66 = F_44 ( V_31 ) ;
unsigned int V_67 = V_31 -> V_68 ;
char * V_282 ;
unsigned long V_283 ;
unsigned int V_14 = 0 ;
struct V_11 * V_12 = NULL ;
if ( ! F_218 ( V_284 ) )
return - V_285 ;
V_283 = F_166 ( V_280 , & V_282 , 0 ) ;
if ( V_282 == V_280 )
return - V_286 ;
if ( V_283 < V_281 )
V_283 = V_281 ;
if ( V_283 > V_238 )
V_283 = V_238 ;
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 ) {
V_12 = & V_66 -> V_69 [ V_14 ] ;
F_46 ( & V_12 -> V_70 ) ;
if ( V_283 < V_12 -> V_177 )
V_12 -> V_177 = V_283 ;
V_12 -> V_58 = V_283 ;
if ( V_283 < V_12 -> V_43 )
V_12 -> V_43 = V_283 ;
F_20 ( V_12 ) ;
F_48 ( & V_12 -> V_70 ) ;
}
return V_89 ;
}
static T_12 F_221 ( struct V_136 * V_20 ,
struct V_278 * V_279 , char * V_280 )
{
struct V_19 * V_31 = F_216 ( V_20 ) ;
struct V_65 * V_30 = F_44 ( V_31 ) ;
unsigned int V_67 = V_31 -> V_68 ;
if ( V_67 )
return sprintf ( V_280 , L_64 , V_30 -> V_69 [ 0 ] . V_43 ) ;
else
return sprintf ( V_280 , L_65 ) ;
}
static int F_154 ( struct V_19 * V_31 )
{
int V_14 ;
int V_137 ;
for ( V_14 = 0 ; V_14 < F_211 ( V_287 ) ; V_14 ++ ) {
V_137 = F_222 ( & V_31 -> V_20 ,
& V_287 [ V_14 ] ) ;
if ( V_137 )
goto V_208;
}
return 0 ;
V_208:
while ( -- V_14 >= 0 )
F_223 ( & V_31 -> V_20 , & V_287 [ V_14 ] ) ;
return V_137 ;
}
static void F_224 ( struct V_19 * V_31 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_211 ( V_287 ) ; V_14 ++ )
F_223 ( & V_31 -> V_20 , & V_287 [ V_14 ] ) ;
}
static int F_225 ( struct V_196 * V_20 )
{
struct V_65 * V_30 = F_162 ( & V_20 -> V_20 ) ;
unsigned int V_67 = V_30 -> V_31 -> V_68 ;
struct V_11 * V_12 = NULL ;
unsigned int V_14 = 0 ;
F_163 ( & V_20 -> V_20 , L_21 , V_20 -> V_213 ) ;
F_157 ( V_30 ) ;
F_224 ( V_30 -> V_31 ) ;
F_155 ( V_30 -> V_31 ) ;
for ( V_14 = 0 ; V_14 < V_67 ; ++ V_14 ) {
V_12 = & V_30 -> V_69 [ V_14 ] ;
F_226 ( & V_12 -> V_50 ) ;
}
if ( V_67 ) {
F_167 ( V_30 -> V_69 ) ;
V_30 -> V_69 = NULL ;
}
F_227 ( V_30 -> V_104 ) ;
F_147 ( V_30 -> V_31 ) ;
return 0 ;
}
static int T_13 F_228 ( void )
{
if ( ! F_229 () )
return - V_258 ;
if ( ! F_230 () )
return - V_258 ;
F_231 ( L_66 ) ;
V_197 = F_232 () ;
return F_233 ( & V_288 ) ;
}
static void T_14 F_234 ( void )
{
F_235 ( & V_288 ) ;
}
