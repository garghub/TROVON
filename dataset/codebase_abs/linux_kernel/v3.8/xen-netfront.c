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
struct V_30 * V_30 = F_35 ( V_84 ) ;
V_79 = F_64 ( V_84 ) ;
V_78 = V_84 -> V_85 ;
F_32 ( V_79 + V_78 > V_80 << F_65 ( V_30 ) ) ;
V_30 += V_78 >> V_86 ;
V_78 &= ~ V_87 ;
while ( V_79 > 0 ) {
unsigned long V_88 ;
F_32 ( V_78 >= V_80 ) ;
V_88 = V_80 - V_78 ;
if ( V_88 > V_79 )
V_88 = V_79 ;
V_25 -> V_82 |= V_83 ;
V_3 = F_5 ( & V_12 -> V_75 ,
V_12 -> V_70 ) ;
V_12 -> V_70 [ V_3 ] . V_5 = F_62 ( V_5 ) ;
V_25 = F_37 ( & V_12 -> V_25 , V_65 ++ ) ;
V_25 -> V_3 = V_3 ;
V_16 = F_33 ( & V_12 -> V_74 ) ;
F_32 ( ( signed short ) V_16 < 0 ) ;
V_77 = F_39 ( F_34 ( V_30 ) ) ;
F_38 ( V_16 ,
V_12 -> V_57 -> V_58 ,
V_77 , V_73 ) ;
V_25 -> V_59 = V_12 -> V_71 [ V_3 ] = V_16 ;
V_25 -> V_78 = V_78 ;
V_25 -> V_81 = V_88 ;
V_25 -> V_82 = 0 ;
V_78 += V_88 ;
V_79 -= V_88 ;
if ( V_78 == V_80 && V_79 ) {
F_32 ( ! F_66 ( V_30 ) ) ;
V_30 ++ ;
V_78 = 0 ;
}
}
}
V_12 -> V_25 . V_26 = V_65 ;
}
static int F_67 ( struct V_10 * V_5 )
{
int V_14 , V_56 = F_29 ( V_5 ) -> V_50 ;
int V_89 = 0 ;
for ( V_14 = 0 ; V_14 < V_56 ; V_14 ++ ) {
T_3 * V_84 = F_29 ( V_5 ) -> V_56 + V_14 ;
unsigned long V_81 = F_64 ( V_84 ) ;
unsigned long V_78 = V_84 -> V_85 ;
V_78 &= ~ V_87 ;
V_89 += F_68 ( V_78 + V_81 ) ;
}
return V_89 ;
}
static int F_69 ( struct V_10 * V_5 , struct V_19 * V_20 )
{
unsigned short V_3 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_90 * V_91 = F_70 ( V_12 -> V_91 ) ;
struct V_76 * V_25 ;
struct V_92 * V_93 ;
char * V_23 = V_5 -> V_23 ;
T_1 V_14 ;
T_2 V_16 ;
unsigned long V_77 ;
int V_32 ;
int V_94 ;
unsigned int V_78 = F_60 ( V_23 ) ;
unsigned int V_79 = F_61 ( V_5 ) ;
unsigned long V_82 ;
V_94 = F_71 ( V_78 + V_79 , V_80 ) +
F_67 ( V_5 ) ;
if ( F_15 ( V_94 > V_29 + 1 ) ) {
F_72 (
L_4 , V_94 ) ;
goto V_95;
}
F_73 ( & V_12 -> V_96 , V_82 ) ;
if ( F_15 ( ! F_21 ( V_20 ) ||
( V_94 > 1 && ! F_9 ( V_20 ) ) ||
F_74 ( V_5 , F_75 ( V_5 ) ) ) ) {
F_76 ( & V_12 -> V_96 , V_82 ) ;
goto V_95;
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
V_93 = NULL ;
V_25 -> V_82 = 0 ;
if ( V_5 -> V_97 == V_98 )
V_25 -> V_82 |= V_99 | V_100 ;
else if ( V_5 -> V_97 == V_101 )
V_25 -> V_82 |= V_100 ;
if ( F_29 ( V_5 ) -> V_102 ) {
struct V_92 * V_103 ;
V_103 = (struct V_92 * )
F_37 ( & V_12 -> V_25 , ++ V_14 ) ;
if ( V_93 )
V_93 -> V_82 |= V_104 ;
else
V_25 -> V_82 |= V_105 ;
V_103 -> V_106 . V_103 . V_81 = F_29 ( V_5 ) -> V_102 ;
V_103 -> V_106 . V_103 . type = V_107 ;
V_103 -> V_106 . V_103 . V_108 = 0 ;
V_103 -> V_106 . V_103 . V_21 = 0 ;
V_103 -> type = V_109 ;
V_103 -> V_82 = 0 ;
V_93 = V_103 ;
}
V_12 -> V_25 . V_26 = V_14 + 1 ;
F_59 ( V_5 , V_20 , V_25 ) ;
V_25 -> V_81 = V_5 -> V_79 ;
F_41 ( & V_12 -> V_25 , V_32 ) ;
if ( V_32 )
F_42 ( V_12 -> V_60 -> V_61 ) ;
F_77 ( & V_91 -> V_110 ) ;
V_91 -> V_111 += V_5 -> V_79 ;
V_91 -> V_112 ++ ;
F_78 ( & V_91 -> V_110 ) ;
F_49 ( V_20 ) ;
if ( ! F_13 ( V_12 ) )
F_79 ( V_20 ) ;
F_76 ( & V_12 -> V_96 , V_82 ) ;
return V_113 ;
V_95:
V_20 -> V_91 . V_114 ++ ;
F_80 ( V_5 ) ;
return V_113 ;
}
static int F_81 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_79 ( V_12 -> V_60 ) ;
F_82 ( & V_12 -> V_24 ) ;
return 0 ;
}
static void F_83 ( struct V_11 * V_12 , struct V_10 * V_5 ,
T_2 V_16 )
{
int V_115 = F_6 ( V_12 -> V_34 . V_26 ) ;
F_32 ( V_12 -> V_15 [ V_115 ] ) ;
V_12 -> V_15 [ V_115 ] = V_5 ;
V_12 -> V_17 [ V_115 ] = V_16 ;
F_37 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_3 = V_115 ;
F_37 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_59 = V_16 ;
V_12 -> V_34 . V_26 ++ ;
}
static int F_84 ( struct V_11 * V_12 ,
struct V_92 * V_116 ,
T_1 V_117 )
{
struct V_92 * V_93 ;
struct V_118 * V_20 = & V_12 -> V_60 -> V_20 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
int V_119 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_64 + 1 == V_117 ) ) {
if ( F_85 () )
F_86 ( V_20 , L_5 ) ;
V_119 = - V_120 ;
break;
}
V_93 = (struct V_92 * )
F_51 ( & V_12 -> V_34 , ++ V_64 ) ;
if ( F_15 ( ! V_93 -> type ||
V_93 -> type >= V_121 ) ) {
if ( F_85 () )
F_86 ( V_20 , L_6 ,
V_93 -> type ) ;
V_119 = - V_122 ;
} else {
memcpy ( & V_116 [ V_93 -> type - 1 ] , V_93 ,
sizeof( * V_93 ) ) ;
}
V_5 = F_7 ( V_12 , V_64 ) ;
V_16 = F_8 ( V_12 , V_64 ) ;
F_83 ( V_12 , V_5 , V_16 ) ;
} while ( V_93 -> V_82 & V_104 );
V_12 -> V_34 . V_27 = V_64 ;
return V_119 ;
}
static int F_87 ( struct V_11 * V_12 ,
struct V_123 * V_124 , T_1 V_117 ,
struct V_125 * V_2 )
{
struct V_126 * V_34 = & V_124 -> V_34 ;
struct V_92 * V_116 = V_124 -> V_116 ;
struct V_118 * V_20 = & V_12 -> V_60 -> V_20 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_64 ) ;
T_2 V_16 = F_8 ( V_12 , V_64 ) ;
int V_127 = V_29 + ( V_34 -> V_68 <= V_41 ) ;
int V_56 = 1 ;
int V_119 = 0 ;
unsigned long V_128 ;
if ( V_34 -> V_82 & V_129 ) {
V_119 = F_84 ( V_12 , V_116 , V_117 ) ;
V_64 = V_12 -> V_34 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_34 -> V_68 < 0 ||
V_34 -> V_78 + V_34 -> V_68 > V_80 ) ) {
if ( F_85 () )
F_86 ( V_20 , L_7 ,
V_34 -> V_78 , V_34 -> V_68 ) ;
F_83 ( V_12 , V_5 , V_16 ) ;
V_119 = - V_122 ;
goto V_130;
}
if ( V_16 == V_18 ) {
if ( F_85 () )
F_86 ( V_20 , L_8 ,
V_34 -> V_3 ) ;
V_119 = - V_122 ;
goto V_130;
}
V_128 = F_55 ( V_16 , 0 ) ;
F_32 ( ! V_128 ) ;
F_56 ( & V_12 -> V_55 , V_16 ) ;
F_30 ( V_2 , V_5 ) ;
V_130:
if ( ! ( V_34 -> V_82 & V_131 ) )
break;
if ( V_64 + V_56 == V_117 ) {
if ( F_85 () )
F_86 ( V_20 , L_9 ) ;
V_119 = - V_132 ;
break;
}
V_34 = F_51 ( & V_12 -> V_34 , V_64 + V_56 ) ;
V_5 = F_7 ( V_12 , V_64 + V_56 ) ;
V_16 = F_8 ( V_12 , V_64 + V_56 ) ;
V_56 ++ ;
}
if ( F_15 ( V_56 > V_127 ) ) {
if ( F_85 () )
F_86 ( V_20 , L_10 ) ;
V_119 = - V_133 ;
}
if ( F_15 ( V_119 ) )
V_12 -> V_34 . V_27 = V_64 + V_56 ;
return V_119 ;
}
static int F_88 ( struct V_10 * V_5 ,
struct V_92 * V_103 )
{
if ( ! V_103 -> V_106 . V_103 . V_81 ) {
if ( F_85 () )
F_53 ( V_134 L_11 ) ;
return - V_122 ;
}
if ( V_103 -> V_106 . V_103 . type != V_107 ) {
if ( F_85 () )
F_53 ( V_134 L_12 , V_103 -> V_106 . V_103 . type ) ;
return - V_122 ;
}
F_29 ( V_5 ) -> V_102 = V_103 -> V_106 . V_103 . V_81 ;
F_29 ( V_5 ) -> V_135 = V_136 ;
F_29 ( V_5 ) -> V_135 |= V_137 ;
F_29 ( V_5 ) -> V_138 = 0 ;
return 0 ;
}
static T_1 F_89 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_125 * V_2 )
{
struct V_139 * V_140 = F_29 ( V_5 ) ;
int V_50 = V_140 -> V_50 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
struct V_10 * V_141 ;
while ( ( V_141 = F_31 ( V_2 ) ) ) {
struct V_126 * V_34 =
F_51 ( & V_12 -> V_34 , ++ V_64 ) ;
T_3 * V_142 = & F_29 ( V_141 ) -> V_56 [ 0 ] ;
F_28 ( V_5 , V_50 ,
F_35 ( V_142 ) ,
V_34 -> V_78 , V_34 -> V_68 ) ;
V_5 -> V_143 += V_34 -> V_68 ;
F_29 ( V_141 ) -> V_50 = 0 ;
F_26 ( V_141 ) ;
V_50 ++ ;
}
V_140 -> V_50 = V_50 ;
return V_64 ;
}
static int F_90 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
struct V_144 * V_145 ;
unsigned char * V_146 ;
int V_119 = - V_147 ;
int V_148 = 0 ;
if ( V_5 -> V_97 != V_98 && F_91 ( V_5 ) ) {
struct V_11 * V_12 = F_11 ( V_20 ) ;
V_12 -> V_149 ++ ;
V_5 -> V_97 = V_98 ;
V_148 = 1 ;
}
if ( V_5 -> V_97 != V_98 )
return 0 ;
if ( V_5 -> V_150 != F_92 ( V_151 ) )
goto V_152;
V_145 = ( void * ) V_5 -> V_23 ;
V_146 = V_5 -> V_23 + 4 * V_145 -> V_153 ;
if ( V_146 >= F_93 ( V_5 ) )
goto V_152;
V_5 -> V_154 = V_146 - V_5 -> V_7 ;
switch ( V_145 -> V_150 ) {
case V_155 :
V_5 -> V_156 = F_94 ( struct V_157 , V_158 ) ;
if ( V_148 ) {
struct V_157 * V_159 = (struct V_157 * ) V_146 ;
V_159 -> V_158 = ~ F_95 ( V_145 -> V_160 , V_145 -> V_161 ,
V_5 -> V_79 - V_145 -> V_153 * 4 ,
V_155 , 0 ) ;
}
break;
case V_162 :
V_5 -> V_156 = F_94 ( struct V_163 , V_158 ) ;
if ( V_148 ) {
struct V_163 * V_164 = (struct V_163 * ) V_146 ;
V_164 -> V_158 = ~ F_95 ( V_145 -> V_160 , V_145 -> V_161 ,
V_5 -> V_79 - V_145 -> V_153 * 4 ,
V_162 , 0 ) ;
}
break;
default:
if ( F_85 () )
F_53 ( V_165 L_13
L_14
L_15 , V_145 -> V_150 ) ;
goto V_152;
}
if ( ( V_146 + V_5 -> V_156 + 2 ) > F_93 ( V_5 ) )
goto V_152;
V_119 = 0 ;
V_152:
return V_119 ;
}
static int F_96 ( struct V_19 * V_20 ,
struct V_125 * V_166 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_90 * V_91 = F_70 ( V_12 -> V_91 ) ;
int V_167 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_31 ( V_166 ) ) != NULL ) {
int V_168 = F_97 ( V_5 ) -> V_168 ;
F_98 ( V_5 , V_168 - F_61 ( V_5 ) ) ;
V_5 -> V_150 = F_99 ( V_5 , V_20 ) ;
if ( F_90 ( V_20 , V_5 ) ) {
F_26 ( V_5 ) ;
V_167 ++ ;
V_20 -> V_91 . V_169 ++ ;
continue;
}
F_77 ( & V_91 -> V_110 ) ;
V_91 -> V_170 ++ ;
V_91 -> V_171 += V_5 -> V_79 ;
F_78 ( & V_91 -> V_110 ) ;
F_100 ( V_5 ) ;
}
return V_167 ;
}
static int F_101 ( struct V_172 * V_24 , int V_173 )
{
struct V_11 * V_12 = F_102 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_60 ;
struct V_10 * V_5 ;
struct V_123 V_124 ;
struct V_126 * V_34 = & V_124 . V_34 ;
struct V_92 * V_116 = V_124 . V_116 ;
T_1 V_14 , V_117 ;
int V_174 ;
struct V_125 V_166 ;
struct V_125 V_175 ;
struct V_125 V_176 ;
unsigned long V_82 ;
int V_119 ;
F_103 ( & V_12 -> V_62 ) ;
F_104 ( & V_166 ) ;
F_104 ( & V_175 ) ;
F_104 ( & V_176 ) ;
V_117 = V_12 -> V_34 . V_51 -> V_53 ;
F_50 () ;
V_14 = V_12 -> V_34 . V_27 ;
V_174 = 0 ;
while ( ( V_14 != V_117 ) && ( V_174 < V_173 ) ) {
memcpy ( V_34 , F_51 ( & V_12 -> V_34 , V_14 ) , sizeof( * V_34 ) ) ;
memset ( V_116 , 0 , sizeof( V_124 . V_116 ) ) ;
V_119 = F_87 ( V_12 , & V_124 , V_117 , & V_176 ) ;
if ( F_15 ( V_119 ) ) {
V_119:
while ( ( V_5 = F_31 ( & V_176 ) ) )
F_30 ( & V_175 , V_5 ) ;
V_20 -> V_91 . V_169 ++ ;
V_14 = V_12 -> V_34 . V_27 ;
continue;
}
V_5 = F_31 ( & V_176 ) ;
if ( V_116 [ V_109 - 1 ] . type ) {
struct V_92 * V_103 ;
V_103 = & V_116 [ V_109 - 1 ] ;
if ( F_15 ( F_88 ( V_5 , V_103 ) ) ) {
F_105 ( & V_176 , V_5 ) ;
V_12 -> V_34 . V_27 += F_22 ( & V_176 ) ;
goto V_119;
}
}
F_97 ( V_5 ) -> V_168 = V_34 -> V_68 ;
if ( F_97 ( V_5 ) -> V_168 > V_41 )
F_97 ( V_5 ) -> V_168 = V_41 ;
F_29 ( V_5 ) -> V_56 [ 0 ] . V_85 = V_34 -> V_78 ;
F_106 ( & F_29 ( V_5 ) -> V_56 [ 0 ] , V_34 -> V_68 ) ;
V_5 -> V_143 = V_34 -> V_68 ;
V_14 = F_89 ( V_12 , V_5 , & V_176 ) ;
V_5 -> V_177 += V_80 * F_29 ( V_5 ) -> V_50 ;
V_5 -> V_79 += V_5 -> V_143 ;
if ( V_34 -> V_82 & V_178 )
V_5 -> V_97 = V_98 ;
else if ( V_34 -> V_82 & V_179 )
V_5 -> V_97 = V_101 ;
F_30 ( & V_166 , V_5 ) ;
V_12 -> V_34 . V_27 = ++ V_14 ;
V_174 ++ ;
}
F_107 ( & V_175 ) ;
V_174 -= F_96 ( V_20 , & V_166 ) ;
if ( ( ( V_12 -> V_34 . V_26 - V_12 -> V_34 . V_51 -> V_53 ) >
( ( 3 * V_12 -> V_39 ) / 4 ) ) &&
( -- V_12 -> V_39 < V_12 -> V_180 ) )
V_12 -> V_39 = V_12 -> V_180 ;
F_20 ( V_20 ) ;
if ( V_174 < V_173 ) {
int V_181 = 0 ;
F_108 ( V_82 ) ;
F_109 ( & V_12 -> V_34 , V_181 ) ;
if ( ! V_181 )
F_110 ( V_24 ) ;
F_111 ( V_82 ) ;
}
F_112 ( & V_12 -> V_62 ) ;
return V_174 ;
}
static int F_113 ( struct V_19 * V_20 , int V_182 )
{
int V_127 = F_9 ( V_20 ) ? 65535 - V_183 : V_184 ;
if ( V_182 > V_127 )
return - V_122 ;
V_20 -> V_182 = V_182 ;
return 0 ;
}
static struct V_185 * F_114 ( struct V_19 * V_20 ,
struct V_185 * V_186 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_187 ;
F_115 (cpu) {
struct V_90 * V_91 = F_116 ( V_12 -> V_91 , V_187 ) ;
T_4 V_170 , V_171 , V_112 , V_111 ;
unsigned int V_188 ;
do {
V_188 = F_117 ( & V_91 -> V_110 ) ;
V_170 = V_91 -> V_170 ;
V_112 = V_91 -> V_112 ;
V_171 = V_91 -> V_171 ;
V_111 = V_91 -> V_111 ;
} while ( F_118 ( & V_91 -> V_110 , V_188 ) );
V_186 -> V_170 += V_170 ;
V_186 -> V_112 += V_112 ;
V_186 -> V_171 += V_171 ;
V_186 -> V_111 += V_111 ;
}
V_186 -> V_169 = V_20 -> V_91 . V_169 ;
V_186 -> V_114 = V_20 -> V_91 . V_114 ;
return V_186 ;
}
static void F_119 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_189 ; V_14 ++ ) {
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
static void F_120 ( struct V_11 * V_12 )
{
struct V_190 * V_191 = V_12 -> V_192 ;
struct V_193 * V_194 = V_12 -> V_195 ;
struct V_125 V_196 ;
struct V_10 * V_5 ;
unsigned long V_77 ;
int V_197 = 0 , V_198 = 0 , V_199 = 0 ;
int V_3 , V_16 ;
F_86 ( & V_12 -> V_60 -> V_20 , L_16 ,
V_200 ) ;
return;
F_104 ( & V_196 ) ;
F_45 ( & V_12 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 ) {
V_199 ++ ;
continue;
}
V_5 = V_12 -> V_15 [ V_3 ] ;
V_77 = F_121 ( V_16 ) ;
F_56 ( & V_12 -> V_55 , V_16 ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
if ( 0 == V_77 ) {
F_29 ( V_5 ) -> V_50 = 0 ;
F_80 ( V_5 ) ;
V_198 ++ ;
continue;
}
if ( ! F_122 ( V_201 ) ) {
const struct V_30 * V_30 =
F_35 ( & F_29 ( V_5 ) -> V_56 [ 0 ] ) ;
unsigned long V_35 = F_34 ( V_30 ) ;
void * V_36 = F_36 ( V_30 ) ;
F_123 ( V_194 , ( unsigned long ) V_36 ,
F_124 ( V_77 , V_202 ) ,
0 ) ;
V_194 ++ ;
V_191 -> V_203 = ( ( T_4 ) V_77 << V_86 )
| V_204 ;
V_191 -> V_205 = V_35 ;
V_191 ++ ;
F_125 ( V_35 , V_77 ) ;
}
F_30 ( & V_196 , V_5 ) ;
V_197 ++ ;
}
F_126 ( & V_12 -> V_60 -> V_20 , L_17 ,
V_200 , V_197 , V_198 , V_199 ) ;
if ( V_197 ) {
if ( ! F_122 ( V_201 ) ) {
F_127 ( V_194 , V_12 -> V_192 , V_191 - V_12 -> V_192 ,
NULL , V_206 ) ;
V_194 ++ ;
F_128 ( V_12 -> V_195 , V_194 - V_12 -> V_195 ) ;
}
}
F_107 ( & V_196 ) ;
F_47 ( & V_12 -> V_62 ) ;
}
static void F_129 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
F_119 ( V_12 ) ;
F_120 ( V_12 ) ;
F_130 ( V_12 -> V_74 ) ;
F_130 ( V_12 -> V_55 ) ;
}
static T_5 F_131 ( struct V_19 * V_20 ,
T_5 V_21 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_205 ;
if ( V_21 & V_22 ) {
if ( F_132 ( V_207 , V_12 -> V_57 -> V_208 , L_18 ,
L_19 , & V_205 ) < 0 )
V_205 = 0 ;
if ( ! V_205 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_209 ) {
if ( F_132 ( V_207 , V_12 -> V_57 -> V_208 ,
L_20 , L_19 , & V_205 ) < 0 )
V_205 = 0 ;
if ( ! V_205 )
V_21 &= ~ V_209 ;
}
return V_21 ;
}
static int F_133 ( struct V_19 * V_20 ,
T_5 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_182 > V_184 ) {
F_134 ( V_20 , L_21 ) ;
V_20 -> V_182 = V_184 ;
}
return 0 ;
}
static T_6 F_135 ( int V_61 , void * V_210 )
{
struct V_19 * V_20 = V_210 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
unsigned long V_82 ;
F_73 ( & V_12 -> V_96 , V_82 ) ;
if ( F_17 ( F_21 ( V_20 ) ) ) {
F_49 ( V_20 ) ;
if ( F_46 ( & V_12 -> V_34 ) )
F_12 ( & V_12 -> V_24 ) ;
}
F_76 ( & V_12 -> V_96 , V_82 ) ;
return V_211 ;
}
static void F_136 ( struct V_19 * V_20 )
{
F_135 ( 0 , V_20 ) ;
}
static struct V_19 * F_137 ( struct V_212 * V_20 )
{
int V_14 , V_119 ;
struct V_19 * V_60 ;
struct V_11 * V_12 ;
V_60 = F_138 ( sizeof( struct V_11 ) ) ;
if ( ! V_60 )
return F_139 ( - V_213 ) ;
V_12 = F_11 ( V_60 ) ;
V_12 -> V_57 = V_20 ;
F_140 ( & V_12 -> V_96 ) ;
F_140 ( & V_12 -> V_62 ) ;
F_104 ( & V_12 -> V_40 ) ;
V_12 -> V_39 = V_214 ;
V_12 -> V_180 = V_214 ;
V_12 -> V_54 = V_215 ;
F_141 ( & V_12 -> V_47 ) ;
V_12 -> V_47 . V_23 = ( unsigned long ) V_60 ;
V_12 -> V_47 . V_216 = F_10 ;
V_119 = - V_213 ;
V_12 -> V_91 = F_142 ( struct V_90 ) ;
if ( V_12 -> V_91 == NULL )
goto exit;
V_12 -> V_75 = 0 ;
for ( V_14 = 0 ; V_14 < V_189 ; V_14 ++ ) {
F_1 ( & V_12 -> V_70 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_143 ( V_28 ,
& V_12 -> V_74 ) < 0 ) {
F_53 ( V_72 L_22 ) ;
V_119 = - V_213 ;
goto V_217;
}
if ( F_143 ( V_215 ,
& V_12 -> V_55 ) < 0 ) {
F_53 ( V_72 L_23 ) ;
V_119 = - V_213 ;
goto V_218;
}
V_60 -> V_219 = & V_220 ;
F_144 ( V_60 , & V_12 -> V_24 , F_101 , 64 ) ;
V_60 -> V_21 = V_221 | V_222 |
V_223 ;
V_60 -> V_224 = V_221 | V_22 | V_209 ;
V_60 -> V_21 |= V_60 -> V_224 ;
F_145 ( V_60 , & V_225 ) ;
F_146 ( V_60 , & V_20 -> V_20 ) ;
V_12 -> V_60 = V_60 ;
F_147 ( V_60 ) ;
return V_60 ;
V_218:
F_130 ( V_12 -> V_74 ) ;
V_217:
F_148 ( V_12 -> V_91 ) ;
exit:
F_149 ( V_60 ) ;
return F_139 ( V_119 ) ;
}
static int F_150 ( struct V_212 * V_20 ,
const struct V_226 * V_3 )
{
int V_119 ;
struct V_19 * V_60 ;
struct V_11 * V_227 ;
V_60 = F_137 ( V_20 ) ;
if ( F_151 ( V_60 ) ) {
V_119 = F_152 ( V_60 ) ;
F_153 ( V_20 , V_119 , L_24 ) ;
return V_119 ;
}
V_227 = F_11 ( V_60 ) ;
F_154 ( & V_20 -> V_20 , V_227 ) ;
V_119 = F_155 ( V_227 -> V_60 ) ;
if ( V_119 ) {
F_53 ( V_134 L_25 ,
V_200 , V_119 ) ;
goto V_228;
}
V_119 = F_156 ( V_227 -> V_60 ) ;
if ( V_119 ) {
F_157 ( V_227 -> V_60 ) ;
F_53 ( V_134 L_26 ,
V_200 , V_119 ) ;
goto V_228;
}
return 0 ;
V_228:
F_149 ( V_60 ) ;
F_154 ( & V_20 -> V_20 , NULL ) ;
return V_119 ;
}
static void F_158 ( int V_16 , void * V_30 )
{
if ( V_16 != V_18 )
F_159 ( V_16 , 0 , ( unsigned long ) V_30 ) ;
}
static void F_160 ( struct V_11 * V_227 )
{
F_45 ( & V_227 -> V_62 ) ;
F_161 ( & V_227 -> V_96 ) ;
F_147 ( V_227 -> V_60 ) ;
F_162 ( & V_227 -> V_96 ) ;
F_47 ( & V_227 -> V_62 ) ;
if ( V_227 -> V_60 -> V_61 )
F_163 ( V_227 -> V_60 -> V_61 , V_227 -> V_60 ) ;
V_227 -> V_229 = V_227 -> V_60 -> V_61 = 0 ;
F_158 ( V_227 -> V_230 , V_227 -> V_25 . V_51 ) ;
F_158 ( V_227 -> V_231 , V_227 -> V_34 . V_51 ) ;
V_227 -> V_230 = V_18 ;
V_227 -> V_231 = V_18 ;
V_227 -> V_25 . V_51 = NULL ;
V_227 -> V_34 . V_51 = NULL ;
}
static int F_164 ( struct V_212 * V_20 )
{
struct V_11 * V_227 = F_165 ( & V_20 -> V_20 ) ;
F_166 ( & V_20 -> V_20 , L_27 , V_20 -> V_232 ) ;
F_160 ( V_227 ) ;
return 0 ;
}
static int F_167 ( struct V_212 * V_20 , T_7 V_233 [] )
{
char * V_234 , * V_235 , * V_236 ;
int V_14 ;
V_236 = V_234 = F_168 ( V_207 , V_20 -> V_232 , L_28 , NULL ) ;
if ( F_151 ( V_236 ) )
return F_152 ( V_236 ) ;
for ( V_14 = 0 ; V_14 < V_237 ; V_14 ++ ) {
V_233 [ V_14 ] = F_169 ( V_234 , & V_235 , 16 ) ;
if ( ( V_234 == V_235 ) || ( * V_235 != ( ( V_14 == V_237 - 1 ) ? '\0' : ':' ) ) ) {
F_170 ( V_236 ) ;
return - V_132 ;
}
V_234 = V_235 + 1 ;
}
F_170 ( V_236 ) ;
return 0 ;
}
static int F_171 ( struct V_212 * V_20 , struct V_11 * V_227 )
{
struct V_238 * V_239 ;
struct V_240 * V_241 ;
int V_119 ;
struct V_19 * V_60 = V_227 -> V_60 ;
V_227 -> V_230 = V_18 ;
V_227 -> V_231 = V_18 ;
V_227 -> V_34 . V_51 = NULL ;
V_227 -> V_25 . V_51 = NULL ;
V_60 -> V_61 = 0 ;
V_119 = F_167 ( V_20 , V_60 -> V_242 ) ;
if ( V_119 ) {
F_153 ( V_20 , V_119 , L_29 , V_20 -> V_232 ) ;
goto V_228;
}
V_239 = (struct V_238 * ) F_172 ( V_243 | V_244 ) ;
if ( ! V_239 ) {
V_119 = - V_213 ;
F_153 ( V_20 , V_119 , L_30 ) ;
goto V_228;
}
F_173 ( V_239 ) ;
F_174 ( & V_227 -> V_25 , V_239 , V_80 ) ;
V_119 = F_175 ( V_20 , F_63 ( V_239 ) ) ;
if ( V_119 < 0 ) {
F_176 ( ( unsigned long ) V_239 ) ;
goto V_228;
}
V_227 -> V_230 = V_119 ;
V_241 = (struct V_240 * ) F_172 ( V_243 | V_244 ) ;
if ( ! V_241 ) {
V_119 = - V_213 ;
F_153 ( V_20 , V_119 , L_31 ) ;
goto V_228;
}
F_173 ( V_241 ) ;
F_174 ( & V_227 -> V_34 , V_241 , V_80 ) ;
V_119 = F_175 ( V_20 , F_63 ( V_241 ) ) ;
if ( V_119 < 0 ) {
F_176 ( ( unsigned long ) V_241 ) ;
goto V_228;
}
V_227 -> V_231 = V_119 ;
V_119 = F_177 ( V_20 , & V_227 -> V_229 ) ;
if ( V_119 )
goto V_228;
V_119 = F_178 ( V_227 -> V_229 , F_135 ,
0 , V_60 -> V_245 , V_60 ) ;
if ( V_119 < 0 )
goto V_228;
V_60 -> V_61 = V_119 ;
return 0 ;
V_228:
return V_119 ;
}
static int F_179 ( struct V_212 * V_20 ,
struct V_11 * V_227 )
{
const char * V_246 ;
struct V_247 V_248 ;
int V_119 ;
V_119 = F_171 ( V_20 , V_227 ) ;
if ( V_119 )
goto V_152;
V_249:
V_119 = F_180 ( & V_248 ) ;
if ( V_119 ) {
F_153 ( V_20 , V_119 , L_32 ) ;
goto V_250;
}
V_119 = F_181 ( V_248 , V_20 -> V_232 , L_33 , L_34 ,
V_227 -> V_230 ) ;
if ( V_119 ) {
V_246 = L_35 ;
goto V_251;
}
V_119 = F_181 ( V_248 , V_20 -> V_232 , L_36 , L_34 ,
V_227 -> V_231 ) ;
if ( V_119 ) {
V_246 = L_37 ;
goto V_251;
}
V_119 = F_181 ( V_248 , V_20 -> V_232 ,
L_38 , L_34 , V_227 -> V_229 ) ;
if ( V_119 ) {
V_246 = L_39 ;
goto V_251;
}
V_119 = F_181 ( V_248 , V_20 -> V_232 , L_40 , L_34 ,
1 ) ;
if ( V_119 ) {
V_246 = L_41 ;
goto V_251;
}
V_119 = F_181 ( V_248 , V_20 -> V_232 , L_42 , L_19 , 1 ) ;
if ( V_119 ) {
V_246 = L_43 ;
goto V_251;
}
V_119 = F_181 ( V_248 , V_20 -> V_232 , L_18 , L_19 , 1 ) ;
if ( V_119 ) {
V_246 = L_44 ;
goto V_251;
}
V_119 = F_181 ( V_248 , V_20 -> V_232 , L_20 , L_19 , 1 ) ;
if ( V_119 ) {
V_246 = L_45 ;
goto V_251;
}
V_119 = F_182 ( V_248 , 0 ) ;
if ( V_119 ) {
if ( V_119 == - V_252 )
goto V_249;
F_153 ( V_20 , V_119 , L_46 ) ;
goto V_250;
}
return 0 ;
V_251:
F_182 ( V_248 , 1 ) ;
F_153 ( V_20 , V_119 , L_47 , V_246 ) ;
V_250:
F_160 ( V_227 ) ;
V_152:
return V_119 ;
}
static int F_183 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_14 , V_253 , V_119 ;
struct V_10 * V_5 ;
T_2 V_16 ;
struct V_37 * V_38 ;
unsigned int V_254 ;
V_119 = F_132 ( V_207 , V_12 -> V_57 -> V_208 ,
L_48 , L_34 , & V_254 ) ;
if ( V_119 != 1 )
V_254 = 0 ;
if ( ! V_254 ) {
F_126 ( & V_20 -> V_20 ,
L_49 ) ;
return - V_255 ;
}
V_119 = F_179 ( V_12 -> V_57 , V_12 ) ;
if ( V_119 )
return V_119 ;
F_184 () ;
F_185 ( V_20 ) ;
F_186 () ;
F_45 ( & V_12 -> V_62 ) ;
F_161 ( & V_12 -> V_96 ) ;
F_119 ( V_12 ) ;
for ( V_253 = 0 , V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
T_3 * V_84 ;
const struct V_30 * V_30 ;
if ( ! V_12 -> V_15 [ V_14 ] )
continue;
V_5 = V_12 -> V_15 [ V_253 ] = F_7 ( V_12 , V_14 ) ;
V_16 = V_12 -> V_17 [ V_253 ] = F_8 ( V_12 , V_14 ) ;
V_38 = F_37 ( & V_12 -> V_34 , V_253 ) ;
V_84 = & F_29 ( V_5 ) -> V_56 [ 0 ] ;
V_30 = F_35 ( V_84 ) ;
F_38 (
V_16 , V_12 -> V_57 -> V_58 ,
F_39 ( F_34 ( V_30 ) ) ,
0 ) ;
V_38 -> V_59 = V_16 ;
V_38 -> V_3 = V_253 ;
V_253 ++ ;
}
V_12 -> V_34 . V_26 = V_253 ;
F_187 ( V_12 -> V_60 ) ;
F_42 ( V_12 -> V_60 -> V_61 ) ;
F_49 ( V_20 ) ;
F_20 ( V_20 ) ;
F_162 ( & V_12 -> V_96 ) ;
F_47 ( & V_12 -> V_62 ) ;
return 0 ;
}
static void F_188 ( struct V_212 * V_20 ,
enum V_256 V_257 )
{
struct V_11 * V_12 = F_165 ( & V_20 -> V_20 ) ;
struct V_19 * V_60 = V_12 -> V_60 ;
F_166 ( & V_20 -> V_20 , L_27 , F_189 ( V_257 ) ) ;
switch ( V_257 ) {
case V_258 :
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
break;
case V_264 :
if ( V_20 -> V_265 != V_258 )
break;
if ( F_183 ( V_60 ) != 0 )
break;
F_190 ( V_20 , V_266 ) ;
break;
case V_266 :
F_191 ( V_60 ) ;
break;
case V_267 :
F_192 ( V_20 ) ;
break;
}
}
static int F_193 ( struct V_19 * V_20 , int V_268 )
{
switch ( V_268 ) {
case V_269 :
return F_194 ( V_270 ) ;
default:
return - V_122 ;
}
}
static void F_195 ( struct V_19 * V_20 ,
struct V_271 * V_91 , T_4 * V_23 )
{
void * V_12 = F_11 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_194 ( V_270 ) ; V_14 ++ )
V_23 [ V_14 ] = * ( unsigned long * ) ( V_12 + V_270 [ V_14 ] . V_78 ) ;
}
static void F_196 ( struct V_19 * V_20 , T_8 V_272 , T_7 * V_23 )
{
int V_14 ;
switch ( V_272 ) {
case V_269 :
for ( V_14 = 0 ; V_14 < F_194 ( V_270 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_273 ,
V_270 [ V_14 ] . V_245 , V_273 ) ;
break;
}
}
static T_9 F_197 ( struct V_118 * V_20 ,
struct V_274 * V_275 , char * V_276 )
{
struct V_19 * V_60 = F_198 ( V_20 ) ;
struct V_11 * V_227 = F_11 ( V_60 ) ;
return sprintf ( V_276 , L_50 , V_227 -> V_180 ) ;
}
static T_9 F_199 ( struct V_118 * V_20 ,
struct V_274 * V_275 ,
const char * V_276 , T_10 V_79 )
{
struct V_19 * V_60 = F_198 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_277 ;
unsigned long V_278 ;
if ( ! F_200 ( V_279 ) )
return - V_280 ;
V_278 = F_169 ( V_276 , & V_277 , 0 ) ;
if ( V_277 == V_276 )
return - V_281 ;
if ( V_278 < V_282 )
V_278 = V_282 ;
if ( V_278 > V_215 )
V_278 = V_215 ;
F_45 ( & V_12 -> V_62 ) ;
if ( V_278 > V_12 -> V_54 )
V_12 -> V_54 = V_278 ;
V_12 -> V_180 = V_278 ;
if ( V_278 > V_12 -> V_39 )
V_12 -> V_39 = V_278 ;
F_20 ( V_60 ) ;
F_47 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_9 F_201 ( struct V_118 * V_20 ,
struct V_274 * V_275 , char * V_276 )
{
struct V_19 * V_60 = F_198 ( V_20 ) ;
struct V_11 * V_227 = F_11 ( V_60 ) ;
return sprintf ( V_276 , L_50 , V_227 -> V_54 ) ;
}
static T_9 F_202 ( struct V_118 * V_20 ,
struct V_274 * V_275 ,
const char * V_276 , T_10 V_79 )
{
struct V_19 * V_60 = F_198 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_277 ;
unsigned long V_278 ;
if ( ! F_200 ( V_279 ) )
return - V_280 ;
V_278 = F_169 ( V_276 , & V_277 , 0 ) ;
if ( V_277 == V_276 )
return - V_281 ;
if ( V_278 < V_282 )
V_278 = V_282 ;
if ( V_278 > V_215 )
V_278 = V_215 ;
F_45 ( & V_12 -> V_62 ) ;
if ( V_278 < V_12 -> V_180 )
V_12 -> V_180 = V_278 ;
V_12 -> V_54 = V_278 ;
if ( V_278 < V_12 -> V_39 )
V_12 -> V_39 = V_278 ;
F_20 ( V_60 ) ;
F_47 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_9 F_203 ( struct V_118 * V_20 ,
struct V_274 * V_275 , char * V_276 )
{
struct V_19 * V_60 = F_198 ( V_20 ) ;
struct V_11 * V_227 = F_11 ( V_60 ) ;
return sprintf ( V_276 , L_50 , V_227 -> V_39 ) ;
}
static int F_156 ( struct V_19 * V_60 )
{
int V_14 ;
int V_119 ;
for ( V_14 = 0 ; V_14 < F_194 ( V_283 ) ; V_14 ++ ) {
V_119 = F_204 ( & V_60 -> V_20 ,
& V_283 [ V_14 ] ) ;
if ( V_119 )
goto V_228;
}
return 0 ;
V_228:
while ( -- V_14 >= 0 )
F_205 ( & V_60 -> V_20 , & V_283 [ V_14 ] ) ;
return V_119 ;
}
static void F_206 ( struct V_19 * V_60 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_194 ( V_283 ) ; V_14 ++ )
F_205 ( & V_60 -> V_20 , & V_283 [ V_14 ] ) ;
}
static int F_207 ( struct V_212 * V_20 )
{
struct V_11 * V_227 = F_165 ( & V_20 -> V_20 ) ;
F_166 ( & V_20 -> V_20 , L_27 , V_20 -> V_232 ) ;
F_160 ( V_227 ) ;
F_206 ( V_227 -> V_60 ) ;
F_157 ( V_227 -> V_60 ) ;
F_208 ( & V_227 -> V_47 ) ;
F_148 ( V_227 -> V_91 ) ;
F_149 ( V_227 -> V_60 ) ;
return 0 ;
}
static int T_11 F_209 ( void )
{
if ( ! F_210 () )
return - V_255 ;
if ( F_211 () && ! V_284 )
return - V_255 ;
F_53 ( V_285 L_51 ) ;
return F_212 ( & V_286 ) ;
}
static void T_12 F_213 ( void )
{
F_214 ( & V_286 ) ;
}
