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
char * V_23 = V_5 -> V_23 ;
T_1 V_14 ;
T_2 V_16 ;
unsigned long V_77 ;
int V_32 ;
int V_92 ;
unsigned int V_78 = F_60 ( V_23 ) ;
unsigned int V_79 = F_61 ( V_5 ) ;
unsigned long V_82 ;
if ( F_15 ( V_5 -> V_79 > V_93 ) ) {
F_71 (
L_4 ,
V_5 -> V_79 ) ;
goto V_94;
}
V_92 = F_72 ( V_78 + V_79 , V_80 ) +
F_67 ( V_5 ) ;
if ( F_15 ( V_92 > V_29 + 1 ) ) {
F_71 (
L_5 , V_92 ) ;
goto V_94;
}
F_73 ( & V_12 -> V_95 , V_82 ) ;
if ( F_15 ( ! F_21 ( V_20 ) ||
( V_92 > 1 && ! F_9 ( V_20 ) ) ||
F_74 ( V_5 , F_75 ( V_5 ) ) ) ) {
F_76 ( & V_12 -> V_95 , V_82 ) ;
goto V_94;
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
V_25 -> V_82 = 0 ;
if ( V_5 -> V_96 == V_97 )
V_25 -> V_82 |= V_98 | V_99 ;
else if ( V_5 -> V_96 == V_100 )
V_25 -> V_82 |= V_99 ;
if ( F_29 ( V_5 ) -> V_101 ) {
struct V_102 * V_103 ;
V_103 = (struct V_102 * )
F_37 ( & V_12 -> V_25 , ++ V_14 ) ;
V_25 -> V_82 |= V_104 ;
V_103 -> V_105 . V_103 . V_81 = F_29 ( V_5 ) -> V_101 ;
V_103 -> V_105 . V_103 . type = V_106 ;
V_103 -> V_105 . V_103 . V_107 = 0 ;
V_103 -> V_105 . V_103 . V_21 = 0 ;
V_103 -> type = V_108 ;
V_103 -> V_82 = 0 ;
}
V_12 -> V_25 . V_26 = V_14 + 1 ;
F_59 ( V_5 , V_20 , V_25 ) ;
V_25 -> V_81 = V_5 -> V_79 ;
F_41 ( & V_12 -> V_25 , V_32 ) ;
if ( V_32 )
F_42 ( V_12 -> V_60 -> V_61 ) ;
F_77 ( & V_91 -> V_109 ) ;
V_91 -> V_110 += V_5 -> V_79 ;
V_91 -> V_111 ++ ;
F_78 ( & V_91 -> V_109 ) ;
F_49 ( V_20 ) ;
if ( ! F_13 ( V_12 ) )
F_79 ( V_20 ) ;
F_76 ( & V_12 -> V_95 , V_82 ) ;
return V_112 ;
V_94:
V_20 -> V_91 . V_113 ++ ;
F_80 ( V_5 ) ;
return V_112 ;
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
int V_114 = F_6 ( V_12 -> V_34 . V_26 ) ;
F_32 ( V_12 -> V_15 [ V_114 ] ) ;
V_12 -> V_15 [ V_114 ] = V_5 ;
V_12 -> V_17 [ V_114 ] = V_16 ;
F_37 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_3 = V_114 ;
F_37 ( & V_12 -> V_34 , V_12 -> V_34 . V_26 ) -> V_59 = V_16 ;
V_12 -> V_34 . V_26 ++ ;
}
static int F_84 ( struct V_11 * V_12 ,
struct V_102 * V_115 ,
T_1 V_116 )
{
struct V_102 * V_117 ;
struct V_118 * V_20 = & V_12 -> V_60 -> V_20 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
int V_119 = 0 ;
do {
struct V_10 * V_5 ;
T_2 V_16 ;
if ( F_15 ( V_64 + 1 == V_116 ) ) {
if ( F_85 () )
F_86 ( V_20 , L_6 ) ;
V_119 = - V_120 ;
break;
}
V_117 = (struct V_102 * )
F_51 ( & V_12 -> V_34 , ++ V_64 ) ;
if ( F_15 ( ! V_117 -> type ||
V_117 -> type >= V_121 ) ) {
if ( F_85 () )
F_86 ( V_20 , L_7 ,
V_117 -> type ) ;
V_119 = - V_122 ;
} else {
memcpy ( & V_115 [ V_117 -> type - 1 ] , V_117 ,
sizeof( * V_117 ) ) ;
}
V_5 = F_7 ( V_12 , V_64 ) ;
V_16 = F_8 ( V_12 , V_64 ) ;
F_83 ( V_12 , V_5 , V_16 ) ;
} while ( V_117 -> V_82 & V_123 );
V_12 -> V_34 . V_27 = V_64 ;
return V_119 ;
}
static int F_87 ( struct V_11 * V_12 ,
struct V_124 * V_125 , T_1 V_116 ,
struct V_126 * V_2 )
{
struct V_127 * V_34 = & V_125 -> V_34 ;
struct V_102 * V_115 = V_125 -> V_115 ;
struct V_118 * V_20 = & V_12 -> V_60 -> V_20 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
struct V_10 * V_5 = F_7 ( V_12 , V_64 ) ;
T_2 V_16 = F_8 ( V_12 , V_64 ) ;
int V_128 = V_29 + ( V_34 -> V_68 <= V_41 ) ;
int V_92 = 1 ;
int V_119 = 0 ;
unsigned long V_129 ;
if ( V_34 -> V_82 & V_130 ) {
V_119 = F_84 ( V_12 , V_115 , V_116 ) ;
V_64 = V_12 -> V_34 . V_27 ;
}
for (; ; ) {
if ( F_15 ( V_34 -> V_68 < 0 ||
V_34 -> V_78 + V_34 -> V_68 > V_80 ) ) {
if ( F_85 () )
F_86 ( V_20 , L_8 ,
V_34 -> V_78 , V_34 -> V_68 ) ;
F_83 ( V_12 , V_5 , V_16 ) ;
V_119 = - V_122 ;
goto V_131;
}
if ( V_16 == V_18 ) {
if ( F_85 () )
F_86 ( V_20 , L_9 ,
V_34 -> V_3 ) ;
V_119 = - V_122 ;
goto V_131;
}
V_129 = F_55 ( V_16 , 0 ) ;
F_32 ( ! V_129 ) ;
F_56 ( & V_12 -> V_55 , V_16 ) ;
F_30 ( V_2 , V_5 ) ;
V_131:
if ( ! ( V_34 -> V_82 & V_132 ) )
break;
if ( V_64 + V_92 == V_116 ) {
if ( F_85 () )
F_86 ( V_20 , L_10 ) ;
V_119 = - V_133 ;
break;
}
V_34 = F_51 ( & V_12 -> V_34 , V_64 + V_92 ) ;
V_5 = F_7 ( V_12 , V_64 + V_92 ) ;
V_16 = F_8 ( V_12 , V_64 + V_92 ) ;
V_92 ++ ;
}
if ( F_15 ( V_92 > V_128 ) ) {
if ( F_85 () )
F_86 ( V_20 , L_11 ) ;
V_119 = - V_134 ;
}
if ( F_15 ( V_119 ) )
V_12 -> V_34 . V_27 = V_64 + V_92 ;
return V_119 ;
}
static int F_88 ( struct V_10 * V_5 ,
struct V_102 * V_103 )
{
if ( ! V_103 -> V_105 . V_103 . V_81 ) {
if ( F_85 () )
F_53 ( V_135 L_12 ) ;
return - V_122 ;
}
if ( V_103 -> V_105 . V_103 . type != V_106 ) {
if ( F_85 () )
F_53 ( V_135 L_13 , V_103 -> V_105 . V_103 . type ) ;
return - V_122 ;
}
F_29 ( V_5 ) -> V_101 = V_103 -> V_105 . V_103 . V_81 ;
F_29 ( V_5 ) -> V_136 = V_137 ;
F_29 ( V_5 ) -> V_136 |= V_138 ;
F_29 ( V_5 ) -> V_139 = 0 ;
return 0 ;
}
static T_1 F_89 ( struct V_11 * V_12 ,
struct V_10 * V_5 ,
struct V_126 * V_2 )
{
struct V_140 * V_141 = F_29 ( V_5 ) ;
int V_50 = V_141 -> V_50 ;
T_1 V_64 = V_12 -> V_34 . V_27 ;
struct V_10 * V_142 ;
while ( ( V_142 = F_31 ( V_2 ) ) ) {
struct V_127 * V_34 =
F_51 ( & V_12 -> V_34 , ++ V_64 ) ;
T_3 * V_143 = & F_29 ( V_142 ) -> V_56 [ 0 ] ;
F_28 ( V_5 , V_50 ,
F_35 ( V_143 ) ,
V_34 -> V_78 , V_34 -> V_68 ) ;
V_5 -> V_144 += V_34 -> V_68 ;
F_29 ( V_142 ) -> V_50 = 0 ;
F_26 ( V_142 ) ;
V_50 ++ ;
}
V_141 -> V_50 = V_50 ;
return V_64 ;
}
static int F_90 ( struct V_19 * V_20 , struct V_10 * V_5 )
{
struct V_145 * V_146 ;
unsigned char * V_147 ;
int V_119 = - V_148 ;
int V_149 = 0 ;
if ( V_5 -> V_96 != V_97 && F_91 ( V_5 ) ) {
struct V_11 * V_12 = F_11 ( V_20 ) ;
V_12 -> V_150 ++ ;
V_5 -> V_96 = V_97 ;
V_149 = 1 ;
}
if ( V_5 -> V_96 != V_97 )
return 0 ;
if ( V_5 -> V_151 != F_92 ( V_152 ) )
goto V_153;
V_146 = ( void * ) V_5 -> V_23 ;
V_147 = V_5 -> V_23 + 4 * V_146 -> V_154 ;
if ( V_147 >= F_93 ( V_5 ) )
goto V_153;
V_5 -> V_155 = V_147 - V_5 -> V_7 ;
switch ( V_146 -> V_151 ) {
case V_156 :
V_5 -> V_157 = F_94 ( struct V_158 , V_159 ) ;
if ( V_149 ) {
struct V_158 * V_160 = (struct V_158 * ) V_147 ;
V_160 -> V_159 = ~ F_95 ( V_146 -> V_161 , V_146 -> V_162 ,
V_5 -> V_79 - V_146 -> V_154 * 4 ,
V_156 , 0 ) ;
}
break;
case V_163 :
V_5 -> V_157 = F_94 ( struct V_164 , V_159 ) ;
if ( V_149 ) {
struct V_164 * V_165 = (struct V_164 * ) V_147 ;
V_165 -> V_159 = ~ F_95 ( V_146 -> V_161 , V_146 -> V_162 ,
V_5 -> V_79 - V_146 -> V_154 * 4 ,
V_163 , 0 ) ;
}
break;
default:
if ( F_85 () )
F_53 ( V_166 L_14
L_15
L_16 , V_146 -> V_151 ) ;
goto V_153;
}
if ( ( V_147 + V_5 -> V_157 + 2 ) > F_93 ( V_5 ) )
goto V_153;
V_119 = 0 ;
V_153:
return V_119 ;
}
static int F_96 ( struct V_19 * V_20 ,
struct V_126 * V_167 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
struct V_90 * V_91 = F_70 ( V_12 -> V_91 ) ;
int V_168 = 0 ;
struct V_10 * V_5 ;
while ( ( V_5 = F_31 ( V_167 ) ) != NULL ) {
int V_169 = F_97 ( V_5 ) -> V_169 ;
F_98 ( V_5 , V_169 - F_61 ( V_5 ) ) ;
V_5 -> V_151 = F_99 ( V_5 , V_20 ) ;
if ( F_90 ( V_20 , V_5 ) ) {
F_26 ( V_5 ) ;
V_168 ++ ;
V_20 -> V_91 . V_170 ++ ;
continue;
}
F_77 ( & V_91 -> V_109 ) ;
V_91 -> V_171 ++ ;
V_91 -> V_172 += V_5 -> V_79 ;
F_78 ( & V_91 -> V_109 ) ;
F_100 ( V_5 ) ;
}
return V_168 ;
}
static int F_101 ( struct V_173 * V_24 , int V_174 )
{
struct V_11 * V_12 = F_102 ( V_24 , struct V_11 , V_24 ) ;
struct V_19 * V_20 = V_12 -> V_60 ;
struct V_10 * V_5 ;
struct V_124 V_125 ;
struct V_127 * V_34 = & V_125 . V_34 ;
struct V_102 * V_115 = V_125 . V_115 ;
T_1 V_14 , V_116 ;
int V_175 ;
struct V_126 V_167 ;
struct V_126 V_176 ;
struct V_126 V_177 ;
unsigned long V_82 ;
int V_119 ;
F_103 ( & V_12 -> V_62 ) ;
F_104 ( & V_167 ) ;
F_104 ( & V_176 ) ;
F_104 ( & V_177 ) ;
V_116 = V_12 -> V_34 . V_51 -> V_53 ;
F_50 () ;
V_14 = V_12 -> V_34 . V_27 ;
V_175 = 0 ;
while ( ( V_14 != V_116 ) && ( V_175 < V_174 ) ) {
memcpy ( V_34 , F_51 ( & V_12 -> V_34 , V_14 ) , sizeof( * V_34 ) ) ;
memset ( V_115 , 0 , sizeof( V_125 . V_115 ) ) ;
V_119 = F_87 ( V_12 , & V_125 , V_116 , & V_177 ) ;
if ( F_15 ( V_119 ) ) {
V_119:
while ( ( V_5 = F_31 ( & V_177 ) ) )
F_30 ( & V_176 , V_5 ) ;
V_20 -> V_91 . V_170 ++ ;
V_14 = V_12 -> V_34 . V_27 ;
continue;
}
V_5 = F_31 ( & V_177 ) ;
if ( V_115 [ V_108 - 1 ] . type ) {
struct V_102 * V_103 ;
V_103 = & V_115 [ V_108 - 1 ] ;
if ( F_15 ( F_88 ( V_5 , V_103 ) ) ) {
F_105 ( & V_177 , V_5 ) ;
V_12 -> V_34 . V_27 += F_22 ( & V_177 ) ;
goto V_119;
}
}
F_97 ( V_5 ) -> V_169 = V_34 -> V_68 ;
if ( F_97 ( V_5 ) -> V_169 > V_41 )
F_97 ( V_5 ) -> V_169 = V_41 ;
F_29 ( V_5 ) -> V_56 [ 0 ] . V_85 = V_34 -> V_78 ;
F_106 ( & F_29 ( V_5 ) -> V_56 [ 0 ] , V_34 -> V_68 ) ;
V_5 -> V_144 = V_34 -> V_68 ;
V_14 = F_89 ( V_12 , V_5 , & V_177 ) ;
V_5 -> V_178 += V_80 * F_29 ( V_5 ) -> V_50 ;
V_5 -> V_79 += V_5 -> V_144 ;
if ( V_34 -> V_82 & V_179 )
V_5 -> V_96 = V_97 ;
else if ( V_34 -> V_82 & V_180 )
V_5 -> V_96 = V_100 ;
F_30 ( & V_167 , V_5 ) ;
V_12 -> V_34 . V_27 = ++ V_14 ;
V_175 ++ ;
}
F_107 ( & V_176 ) ;
V_175 -= F_96 ( V_20 , & V_167 ) ;
if ( ( ( V_12 -> V_34 . V_26 - V_12 -> V_34 . V_51 -> V_53 ) >
( ( 3 * V_12 -> V_39 ) / 4 ) ) &&
( -- V_12 -> V_39 < V_12 -> V_181 ) )
V_12 -> V_39 = V_12 -> V_181 ;
F_20 ( V_20 ) ;
if ( V_175 < V_174 ) {
int V_182 = 0 ;
F_108 ( V_82 ) ;
F_109 ( & V_12 -> V_34 , V_182 ) ;
if ( ! V_182 )
F_110 ( V_24 ) ;
F_111 ( V_82 ) ;
}
F_112 ( & V_12 -> V_62 ) ;
return V_175 ;
}
static int F_113 ( struct V_19 * V_20 , int V_183 )
{
int V_128 = F_9 ( V_20 ) ?
V_93 - V_184 : V_185 ;
if ( V_183 > V_128 )
return - V_122 ;
V_20 -> V_183 = V_183 ;
return 0 ;
}
static struct V_186 * F_114 ( struct V_19 * V_20 ,
struct V_186 * V_187 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_188 ;
F_115 (cpu) {
struct V_90 * V_91 = F_116 ( V_12 -> V_91 , V_188 ) ;
T_4 V_171 , V_172 , V_111 , V_110 ;
unsigned int V_189 ;
do {
V_189 = F_117 ( & V_91 -> V_109 ) ;
V_171 = V_91 -> V_171 ;
V_111 = V_91 -> V_111 ;
V_172 = V_91 -> V_172 ;
V_110 = V_91 -> V_110 ;
} while ( F_118 ( & V_91 -> V_109 , V_189 ) );
V_187 -> V_171 += V_171 ;
V_187 -> V_111 += V_111 ;
V_187 -> V_172 += V_172 ;
V_187 -> V_110 += V_110 ;
}
V_187 -> V_170 = V_20 -> V_91 . V_170 ;
V_187 -> V_113 = V_20 -> V_91 . V_113 ;
return V_187 ;
}
static void F_119 ( struct V_11 * V_12 )
{
struct V_10 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_190 ; V_14 ++ ) {
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
struct V_191 * V_192 = V_12 -> V_193 ;
struct V_194 * V_195 = V_12 -> V_196 ;
struct V_126 V_197 ;
struct V_10 * V_5 ;
unsigned long V_77 ;
int V_198 = 0 , V_199 = 0 , V_200 = 0 ;
int V_3 , V_16 ;
F_86 ( & V_12 -> V_60 -> V_20 , L_17 ,
V_201 ) ;
return;
F_104 ( & V_197 ) ;
F_45 ( & V_12 -> V_62 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ ) {
V_16 = V_12 -> V_17 [ V_3 ] ;
if ( V_16 == V_18 ) {
V_200 ++ ;
continue;
}
V_5 = V_12 -> V_15 [ V_3 ] ;
V_77 = F_121 ( V_16 ) ;
F_56 ( & V_12 -> V_55 , V_16 ) ;
V_12 -> V_17 [ V_3 ] = V_18 ;
if ( 0 == V_77 ) {
F_29 ( V_5 ) -> V_50 = 0 ;
F_80 ( V_5 ) ;
V_199 ++ ;
continue;
}
if ( ! F_122 ( V_202 ) ) {
const struct V_30 * V_30 =
F_35 ( & F_29 ( V_5 ) -> V_56 [ 0 ] ) ;
unsigned long V_35 = F_34 ( V_30 ) ;
void * V_36 = F_36 ( V_30 ) ;
F_123 ( V_195 , ( unsigned long ) V_36 ,
F_124 ( V_77 , V_203 ) ,
0 ) ;
V_195 ++ ;
V_192 -> V_204 = ( ( T_4 ) V_77 << V_86 )
| V_205 ;
V_192 -> V_206 = V_35 ;
V_192 ++ ;
F_125 ( V_35 , V_77 ) ;
}
F_30 ( & V_197 , V_5 ) ;
V_198 ++ ;
}
F_126 ( & V_12 -> V_60 -> V_20 , L_18 ,
V_201 , V_198 , V_199 , V_200 ) ;
if ( V_198 ) {
if ( ! F_122 ( V_202 ) ) {
F_127 ( V_195 , V_12 -> V_193 , V_192 - V_12 -> V_193 ,
NULL , V_207 ) ;
V_195 ++ ;
F_128 ( V_12 -> V_196 , V_195 - V_12 -> V_196 ) ;
}
}
F_107 ( & V_197 ) ;
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
int V_206 ;
if ( V_21 & V_22 ) {
if ( F_132 ( V_208 , V_12 -> V_57 -> V_209 , L_19 ,
L_20 , & V_206 ) < 0 )
V_206 = 0 ;
if ( ! V_206 )
V_21 &= ~ V_22 ;
}
if ( V_21 & V_210 ) {
if ( F_132 ( V_208 , V_12 -> V_57 -> V_209 ,
L_21 , L_20 , & V_206 ) < 0 )
V_206 = 0 ;
if ( ! V_206 )
V_21 &= ~ V_210 ;
}
return V_21 ;
}
static int F_133 ( struct V_19 * V_20 ,
T_5 V_21 )
{
if ( ! ( V_21 & V_22 ) && V_20 -> V_183 > V_185 ) {
F_134 ( V_20 , L_22 ) ;
V_20 -> V_183 = V_185 ;
}
return 0 ;
}
static T_6 F_135 ( int V_61 , void * V_211 )
{
struct V_19 * V_20 = V_211 ;
struct V_11 * V_12 = F_11 ( V_20 ) ;
unsigned long V_82 ;
F_73 ( & V_12 -> V_95 , V_82 ) ;
if ( F_17 ( F_21 ( V_20 ) ) ) {
F_49 ( V_20 ) ;
if ( F_46 ( & V_12 -> V_34 ) )
F_12 ( & V_12 -> V_24 ) ;
}
F_76 ( & V_12 -> V_95 , V_82 ) ;
return V_212 ;
}
static void F_136 ( struct V_19 * V_20 )
{
F_135 ( 0 , V_20 ) ;
}
static struct V_19 * F_137 ( struct V_213 * V_20 )
{
int V_14 , V_119 ;
struct V_19 * V_60 ;
struct V_11 * V_12 ;
V_60 = F_138 ( sizeof( struct V_11 ) ) ;
if ( ! V_60 )
return F_139 ( - V_214 ) ;
V_12 = F_11 ( V_60 ) ;
V_12 -> V_57 = V_20 ;
F_140 ( & V_12 -> V_95 ) ;
F_140 ( & V_12 -> V_62 ) ;
F_104 ( & V_12 -> V_40 ) ;
V_12 -> V_39 = V_215 ;
V_12 -> V_181 = V_215 ;
V_12 -> V_54 = V_216 ;
F_141 ( & V_12 -> V_47 ) ;
V_12 -> V_47 . V_23 = ( unsigned long ) V_60 ;
V_12 -> V_47 . V_217 = F_10 ;
V_119 = - V_214 ;
V_12 -> V_91 = F_142 ( struct V_90 ) ;
if ( V_12 -> V_91 == NULL )
goto exit;
V_12 -> V_75 = 0 ;
for ( V_14 = 0 ; V_14 < V_190 ; V_14 ++ ) {
F_1 ( & V_12 -> V_70 [ V_14 ] , V_14 + 1 ) ;
V_12 -> V_71 [ V_14 ] = V_18 ;
}
for ( V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
V_12 -> V_15 [ V_14 ] = NULL ;
V_12 -> V_17 [ V_14 ] = V_18 ;
}
if ( F_143 ( V_28 ,
& V_12 -> V_74 ) < 0 ) {
F_53 ( V_72 L_23 ) ;
V_119 = - V_214 ;
goto V_218;
}
if ( F_143 ( V_216 ,
& V_12 -> V_55 ) < 0 ) {
F_53 ( V_72 L_24 ) ;
V_119 = - V_214 ;
goto V_219;
}
V_60 -> V_220 = & V_221 ;
F_144 ( V_60 , & V_12 -> V_24 , F_101 , 64 ) ;
V_60 -> V_21 = V_222 | V_223 |
V_224 ;
V_60 -> V_225 = V_222 | V_22 | V_210 ;
V_60 -> V_21 |= V_60 -> V_225 ;
F_145 ( V_60 , & V_226 ) ;
F_146 ( V_60 , & V_20 -> V_20 ) ;
F_147 ( V_60 , V_93 - V_184 ) ;
V_12 -> V_60 = V_60 ;
F_148 ( V_60 ) ;
return V_60 ;
V_219:
F_130 ( V_12 -> V_74 ) ;
V_218:
F_149 ( V_12 -> V_91 ) ;
exit:
F_150 ( V_60 ) ;
return F_139 ( V_119 ) ;
}
static int F_151 ( struct V_213 * V_20 ,
const struct V_227 * V_3 )
{
int V_119 ;
struct V_19 * V_60 ;
struct V_11 * V_228 ;
V_60 = F_137 ( V_20 ) ;
if ( F_152 ( V_60 ) ) {
V_119 = F_153 ( V_60 ) ;
F_154 ( V_20 , V_119 , L_25 ) ;
return V_119 ;
}
V_228 = F_11 ( V_60 ) ;
F_155 ( & V_20 -> V_20 , V_228 ) ;
V_119 = F_156 ( V_228 -> V_60 ) ;
if ( V_119 ) {
F_53 ( V_135 L_26 ,
V_201 , V_119 ) ;
goto V_229;
}
V_119 = F_157 ( V_228 -> V_60 ) ;
if ( V_119 ) {
F_158 ( V_228 -> V_60 ) ;
F_53 ( V_135 L_27 ,
V_201 , V_119 ) ;
goto V_229;
}
return 0 ;
V_229:
F_150 ( V_60 ) ;
F_155 ( & V_20 -> V_20 , NULL ) ;
return V_119 ;
}
static void F_159 ( int V_16 , void * V_30 )
{
if ( V_16 != V_18 )
F_160 ( V_16 , 0 , ( unsigned long ) V_30 ) ;
}
static void F_161 ( struct V_11 * V_228 )
{
F_45 ( & V_228 -> V_62 ) ;
F_162 ( & V_228 -> V_95 ) ;
F_148 ( V_228 -> V_60 ) ;
F_163 ( & V_228 -> V_95 ) ;
F_47 ( & V_228 -> V_62 ) ;
if ( V_228 -> V_60 -> V_61 )
F_164 ( V_228 -> V_60 -> V_61 , V_228 -> V_60 ) ;
V_228 -> V_230 = V_228 -> V_60 -> V_61 = 0 ;
F_159 ( V_228 -> V_231 , V_228 -> V_25 . V_51 ) ;
F_159 ( V_228 -> V_232 , V_228 -> V_34 . V_51 ) ;
V_228 -> V_231 = V_18 ;
V_228 -> V_232 = V_18 ;
V_228 -> V_25 . V_51 = NULL ;
V_228 -> V_34 . V_51 = NULL ;
}
static int F_165 ( struct V_213 * V_20 )
{
struct V_11 * V_228 = F_166 ( & V_20 -> V_20 ) ;
F_167 ( & V_20 -> V_20 , L_28 , V_20 -> V_233 ) ;
F_161 ( V_228 ) ;
return 0 ;
}
static int F_168 ( struct V_213 * V_20 , T_7 V_234 [] )
{
char * V_235 , * V_236 , * V_237 ;
int V_14 ;
V_237 = V_235 = F_169 ( V_208 , V_20 -> V_233 , L_29 , NULL ) ;
if ( F_152 ( V_237 ) )
return F_153 ( V_237 ) ;
for ( V_14 = 0 ; V_14 < V_238 ; V_14 ++ ) {
V_234 [ V_14 ] = F_170 ( V_235 , & V_236 , 16 ) ;
if ( ( V_235 == V_236 ) || ( * V_236 != ( ( V_14 == V_238 - 1 ) ? '\0' : ':' ) ) ) {
F_171 ( V_237 ) ;
return - V_133 ;
}
V_235 = V_236 + 1 ;
}
F_171 ( V_237 ) ;
return 0 ;
}
static int F_172 ( struct V_213 * V_20 , struct V_11 * V_228 )
{
struct V_239 * V_240 ;
struct V_241 * V_242 ;
int V_119 ;
struct V_19 * V_60 = V_228 -> V_60 ;
V_228 -> V_231 = V_18 ;
V_228 -> V_232 = V_18 ;
V_228 -> V_34 . V_51 = NULL ;
V_228 -> V_25 . V_51 = NULL ;
V_60 -> V_61 = 0 ;
V_119 = F_168 ( V_20 , V_60 -> V_243 ) ;
if ( V_119 ) {
F_154 ( V_20 , V_119 , L_30 , V_20 -> V_233 ) ;
goto V_229;
}
V_240 = (struct V_239 * ) F_173 ( V_244 | V_245 ) ;
if ( ! V_240 ) {
V_119 = - V_214 ;
F_154 ( V_20 , V_119 , L_31 ) ;
goto V_229;
}
F_174 ( V_240 ) ;
F_175 ( & V_228 -> V_25 , V_240 , V_80 ) ;
V_119 = F_176 ( V_20 , F_63 ( V_240 ) ) ;
if ( V_119 < 0 ) {
F_177 ( ( unsigned long ) V_240 ) ;
goto V_229;
}
V_228 -> V_231 = V_119 ;
V_242 = (struct V_241 * ) F_173 ( V_244 | V_245 ) ;
if ( ! V_242 ) {
V_119 = - V_214 ;
F_154 ( V_20 , V_119 , L_32 ) ;
goto V_229;
}
F_174 ( V_242 ) ;
F_175 ( & V_228 -> V_34 , V_242 , V_80 ) ;
V_119 = F_176 ( V_20 , F_63 ( V_242 ) ) ;
if ( V_119 < 0 ) {
F_177 ( ( unsigned long ) V_242 ) ;
goto V_229;
}
V_228 -> V_232 = V_119 ;
V_119 = F_178 ( V_20 , & V_228 -> V_230 ) ;
if ( V_119 )
goto V_229;
V_119 = F_179 ( V_228 -> V_230 , F_135 ,
0 , V_60 -> V_246 , V_60 ) ;
if ( V_119 < 0 )
goto V_229;
V_60 -> V_61 = V_119 ;
return 0 ;
V_229:
return V_119 ;
}
static int F_180 ( struct V_213 * V_20 ,
struct V_11 * V_228 )
{
const char * V_247 ;
struct V_248 V_249 ;
int V_119 ;
V_119 = F_172 ( V_20 , V_228 ) ;
if ( V_119 )
goto V_153;
V_250:
V_119 = F_181 ( & V_249 ) ;
if ( V_119 ) {
F_154 ( V_20 , V_119 , L_33 ) ;
goto V_251;
}
V_119 = F_182 ( V_249 , V_20 -> V_233 , L_34 , L_35 ,
V_228 -> V_231 ) ;
if ( V_119 ) {
V_247 = L_36 ;
goto V_252;
}
V_119 = F_182 ( V_249 , V_20 -> V_233 , L_37 , L_35 ,
V_228 -> V_232 ) ;
if ( V_119 ) {
V_247 = L_38 ;
goto V_252;
}
V_119 = F_182 ( V_249 , V_20 -> V_233 ,
L_39 , L_35 , V_228 -> V_230 ) ;
if ( V_119 ) {
V_247 = L_40 ;
goto V_252;
}
V_119 = F_182 ( V_249 , V_20 -> V_233 , L_41 , L_35 ,
1 ) ;
if ( V_119 ) {
V_247 = L_42 ;
goto V_252;
}
V_119 = F_182 ( V_249 , V_20 -> V_233 , L_43 , L_20 , 1 ) ;
if ( V_119 ) {
V_247 = L_44 ;
goto V_252;
}
V_119 = F_182 ( V_249 , V_20 -> V_233 , L_19 , L_20 , 1 ) ;
if ( V_119 ) {
V_247 = L_45 ;
goto V_252;
}
V_119 = F_182 ( V_249 , V_20 -> V_233 , L_21 , L_20 , 1 ) ;
if ( V_119 ) {
V_247 = L_46 ;
goto V_252;
}
V_119 = F_183 ( V_249 , 0 ) ;
if ( V_119 ) {
if ( V_119 == - V_253 )
goto V_250;
F_154 ( V_20 , V_119 , L_47 ) ;
goto V_251;
}
return 0 ;
V_252:
F_183 ( V_249 , 1 ) ;
F_154 ( V_20 , V_119 , L_48 , V_247 ) ;
V_251:
F_161 ( V_228 ) ;
V_153:
return V_119 ;
}
static int F_184 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_11 ( V_20 ) ;
int V_14 , V_254 , V_119 ;
struct V_10 * V_5 ;
T_2 V_16 ;
struct V_37 * V_38 ;
unsigned int V_255 ;
V_119 = F_132 ( V_208 , V_12 -> V_57 -> V_209 ,
L_49 , L_35 , & V_255 ) ;
if ( V_119 != 1 )
V_255 = 0 ;
if ( ! V_255 ) {
F_126 ( & V_20 -> V_20 ,
L_50 ) ;
return - V_256 ;
}
V_119 = F_180 ( V_12 -> V_57 , V_12 ) ;
if ( V_119 )
return V_119 ;
F_185 () ;
F_186 ( V_20 ) ;
F_187 () ;
F_45 ( & V_12 -> V_62 ) ;
F_162 ( & V_12 -> V_95 ) ;
F_119 ( V_12 ) ;
for ( V_254 = 0 , V_14 = 0 ; V_14 < V_9 ; V_14 ++ ) {
T_3 * V_84 ;
const struct V_30 * V_30 ;
if ( ! V_12 -> V_15 [ V_14 ] )
continue;
V_5 = V_12 -> V_15 [ V_254 ] = F_7 ( V_12 , V_14 ) ;
V_16 = V_12 -> V_17 [ V_254 ] = F_8 ( V_12 , V_14 ) ;
V_38 = F_37 ( & V_12 -> V_34 , V_254 ) ;
V_84 = & F_29 ( V_5 ) -> V_56 [ 0 ] ;
V_30 = F_35 ( V_84 ) ;
F_38 (
V_16 , V_12 -> V_57 -> V_58 ,
F_39 ( F_34 ( V_30 ) ) ,
0 ) ;
V_38 -> V_59 = V_16 ;
V_38 -> V_3 = V_254 ;
V_254 ++ ;
}
V_12 -> V_34 . V_26 = V_254 ;
F_188 ( V_12 -> V_60 ) ;
F_42 ( V_12 -> V_60 -> V_61 ) ;
F_49 ( V_20 ) ;
F_20 ( V_20 ) ;
F_163 ( & V_12 -> V_95 ) ;
F_47 ( & V_12 -> V_62 ) ;
return 0 ;
}
static void F_189 ( struct V_213 * V_20 ,
enum V_257 V_258 )
{
struct V_11 * V_12 = F_166 ( & V_20 -> V_20 ) ;
struct V_19 * V_60 = V_12 -> V_60 ;
F_167 ( & V_20 -> V_20 , L_28 , F_190 ( V_258 ) ) ;
switch ( V_258 ) {
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
case V_264 :
break;
case V_265 :
if ( V_20 -> V_266 != V_259 )
break;
if ( F_184 ( V_60 ) != 0 )
break;
F_191 ( V_20 , V_267 ) ;
break;
case V_267 :
F_192 ( V_60 ) ;
break;
case V_268 :
F_193 ( V_20 ) ;
break;
}
}
static int F_194 ( struct V_19 * V_20 , int V_269 )
{
switch ( V_269 ) {
case V_270 :
return F_195 ( V_271 ) ;
default:
return - V_122 ;
}
}
static void F_196 ( struct V_19 * V_20 ,
struct V_272 * V_91 , T_4 * V_23 )
{
void * V_12 = F_11 ( V_20 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < F_195 ( V_271 ) ; V_14 ++ )
V_23 [ V_14 ] = * ( unsigned long * ) ( V_12 + V_271 [ V_14 ] . V_78 ) ;
}
static void F_197 ( struct V_19 * V_20 , T_8 V_273 , T_7 * V_23 )
{
int V_14 ;
switch ( V_273 ) {
case V_270 :
for ( V_14 = 0 ; V_14 < F_195 ( V_271 ) ; V_14 ++ )
memcpy ( V_23 + V_14 * V_274 ,
V_271 [ V_14 ] . V_246 , V_274 ) ;
break;
}
}
static T_9 F_198 ( struct V_118 * V_20 ,
struct V_275 * V_276 , char * V_277 )
{
struct V_19 * V_60 = F_199 ( V_20 ) ;
struct V_11 * V_228 = F_11 ( V_60 ) ;
return sprintf ( V_277 , L_51 , V_228 -> V_181 ) ;
}
static T_9 F_200 ( struct V_118 * V_20 ,
struct V_275 * V_276 ,
const char * V_277 , T_10 V_79 )
{
struct V_19 * V_60 = F_199 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_278 ;
unsigned long V_279 ;
if ( ! F_201 ( V_280 ) )
return - V_281 ;
V_279 = F_170 ( V_277 , & V_278 , 0 ) ;
if ( V_278 == V_277 )
return - V_282 ;
if ( V_279 < V_283 )
V_279 = V_283 ;
if ( V_279 > V_216 )
V_279 = V_216 ;
F_45 ( & V_12 -> V_62 ) ;
if ( V_279 > V_12 -> V_54 )
V_12 -> V_54 = V_279 ;
V_12 -> V_181 = V_279 ;
if ( V_279 > V_12 -> V_39 )
V_12 -> V_39 = V_279 ;
F_20 ( V_60 ) ;
F_47 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_9 F_202 ( struct V_118 * V_20 ,
struct V_275 * V_276 , char * V_277 )
{
struct V_19 * V_60 = F_199 ( V_20 ) ;
struct V_11 * V_228 = F_11 ( V_60 ) ;
return sprintf ( V_277 , L_51 , V_228 -> V_54 ) ;
}
static T_9 F_203 ( struct V_118 * V_20 ,
struct V_275 * V_276 ,
const char * V_277 , T_10 V_79 )
{
struct V_19 * V_60 = F_199 ( V_20 ) ;
struct V_11 * V_12 = F_11 ( V_60 ) ;
char * V_278 ;
unsigned long V_279 ;
if ( ! F_201 ( V_280 ) )
return - V_281 ;
V_279 = F_170 ( V_277 , & V_278 , 0 ) ;
if ( V_278 == V_277 )
return - V_282 ;
if ( V_279 < V_283 )
V_279 = V_283 ;
if ( V_279 > V_216 )
V_279 = V_216 ;
F_45 ( & V_12 -> V_62 ) ;
if ( V_279 < V_12 -> V_181 )
V_12 -> V_181 = V_279 ;
V_12 -> V_54 = V_279 ;
if ( V_279 < V_12 -> V_39 )
V_12 -> V_39 = V_279 ;
F_20 ( V_60 ) ;
F_47 ( & V_12 -> V_62 ) ;
return V_79 ;
}
static T_9 F_204 ( struct V_118 * V_20 ,
struct V_275 * V_276 , char * V_277 )
{
struct V_19 * V_60 = F_199 ( V_20 ) ;
struct V_11 * V_228 = F_11 ( V_60 ) ;
return sprintf ( V_277 , L_51 , V_228 -> V_39 ) ;
}
static int F_157 ( struct V_19 * V_60 )
{
int V_14 ;
int V_119 ;
for ( V_14 = 0 ; V_14 < F_195 ( V_284 ) ; V_14 ++ ) {
V_119 = F_205 ( & V_60 -> V_20 ,
& V_284 [ V_14 ] ) ;
if ( V_119 )
goto V_229;
}
return 0 ;
V_229:
while ( -- V_14 >= 0 )
F_206 ( & V_60 -> V_20 , & V_284 [ V_14 ] ) ;
return V_119 ;
}
static void F_207 ( struct V_19 * V_60 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < F_195 ( V_284 ) ; V_14 ++ )
F_206 ( & V_60 -> V_20 , & V_284 [ V_14 ] ) ;
}
static int F_208 ( struct V_213 * V_20 )
{
struct V_11 * V_228 = F_166 ( & V_20 -> V_20 ) ;
F_167 ( & V_20 -> V_20 , L_28 , V_20 -> V_233 ) ;
F_161 ( V_228 ) ;
F_207 ( V_228 -> V_60 ) ;
F_158 ( V_228 -> V_60 ) ;
F_209 ( & V_228 -> V_47 ) ;
F_149 ( V_228 -> V_91 ) ;
F_150 ( V_228 -> V_60 ) ;
return 0 ;
}
static int T_11 F_210 ( void )
{
if ( ! F_211 () )
return - V_256 ;
if ( F_212 () && ! V_285 )
return - V_256 ;
F_53 ( V_286 L_52 ) ;
return F_213 ( & V_287 ) ;
}
static void T_12 F_214 ( void )
{
F_215 ( & V_287 ) ;
}
