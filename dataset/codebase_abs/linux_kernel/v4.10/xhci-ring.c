T_1 F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
unsigned long V_5 ;
if ( ! V_2 || ! V_4 || V_4 < V_2 -> V_6 )
return 0 ;
V_5 = V_4 - V_2 -> V_6 ;
if ( V_5 >= V_7 )
return 0 ;
return V_2 -> V_8 + ( V_5 * sizeof( * V_4 ) ) ;
}
static bool F_2 ( union V_3 * V_4 )
{
return F_3 ( V_4 -> V_9 . V_10 [ 3 ] ) ;
}
static bool F_4 ( union V_3 * V_4 )
{
return F_5 ( V_4 -> V_11 . V_12 ) ;
}
static bool F_6 ( struct V_1 * V_2 , union V_3 * V_4 )
{
return V_4 == & V_2 -> V_6 [ V_7 - 1 ] ;
}
static bool F_7 ( struct V_13 * V_14 ,
struct V_1 * V_2 , union V_3 * V_4 )
{
return F_6 ( V_2 , V_4 ) && ( V_2 -> V_15 == V_14 -> V_16 ) ;
}
static bool F_8 ( union V_3 * V_4 )
{
return F_9 ( V_4 -> V_11 . V_12 ) & V_17 ;
}
static bool F_10 ( struct V_18 * V_19 )
{
struct V_20 * V_20 = V_19 -> V_21 -> V_22 ;
return V_20 -> V_23 == V_20 -> V_24 ;
}
static void F_11 ( struct V_21 * V_21 )
{
struct V_20 * V_20 = V_21 -> V_22 ;
V_20 -> V_23 ++ ;
}
static void F_12 ( struct V_25 * V_26 ,
struct V_13 * V_14 ,
struct V_1 * * V_2 ,
union V_3 * * V_4 )
{
if ( F_4 ( * V_4 ) ) {
* V_2 = ( * V_2 ) -> V_15 ;
* V_4 = ( ( * V_2 ) -> V_6 ) ;
} else {
( * V_4 ) ++ ;
}
}
static void F_13 ( struct V_25 * V_26 , struct V_13 * V_14 )
{
V_14 -> V_27 ++ ;
if ( V_14 -> type == V_28 ) {
if ( ! F_6 ( V_14 -> V_29 , V_14 -> V_30 ) ) {
V_14 -> V_30 ++ ;
return;
}
if ( F_7 ( V_14 , V_14 -> V_29 , V_14 -> V_30 ) )
V_14 -> V_31 ^= 1 ;
V_14 -> V_29 = V_14 -> V_29 -> V_15 ;
V_14 -> V_30 = V_14 -> V_29 -> V_6 ;
return;
}
if ( ! F_4 ( V_14 -> V_30 ) ) {
V_14 -> V_30 ++ ;
V_14 -> V_32 ++ ;
}
while ( F_4 ( V_14 -> V_30 ) ) {
V_14 -> V_29 = V_14 -> V_29 -> V_15 ;
V_14 -> V_30 = V_14 -> V_29 -> V_6 ;
}
return;
}
static void F_14 ( struct V_25 * V_26 , struct V_13 * V_14 ,
bool V_33 )
{
T_2 V_34 ;
union V_3 * V_15 ;
V_34 = F_9 ( V_14 -> V_35 -> V_9 . V_10 [ 3 ] ) & V_36 ;
if ( ! F_4 ( V_14 -> V_35 ) )
V_14 -> V_32 -- ;
V_15 = ++ ( V_14 -> V_35 ) ;
V_14 -> V_37 ++ ;
while ( F_4 ( V_15 ) ) {
if ( ! V_34 && ! V_33 )
break;
if ( ! ( V_14 -> type == V_38 &&
( V_26 -> V_39 & V_40 ) ) &&
! F_15 ( V_26 ) ) {
V_15 -> V_11 . V_12 &= F_16 ( ~ V_36 ) ;
V_15 -> V_11 . V_12 |= F_16 ( V_34 ) ;
}
F_17 () ;
V_15 -> V_11 . V_12 ^= F_16 ( V_41 ) ;
if ( F_8 ( V_15 ) )
V_14 -> V_31 ^= 1 ;
V_14 -> V_42 = V_14 -> V_42 -> V_15 ;
V_14 -> V_35 = V_14 -> V_42 -> V_6 ;
V_15 = V_14 -> V_35 ;
}
}
static inline int F_18 ( struct V_25 * V_26 , struct V_13 * V_14 ,
unsigned int V_43 )
{
int V_44 ;
if ( V_14 -> V_32 < V_43 )
return 0 ;
if ( V_14 -> type != V_45 && V_14 -> type != V_28 ) {
V_44 = V_14 -> V_30 - V_14 -> V_29 -> V_6 ;
if ( V_14 -> V_32 < V_43 + V_44 )
return 0 ;
}
return 1 ;
}
void F_19 ( struct V_25 * V_26 )
{
if ( ! ( V_26 -> V_46 & V_47 ) )
return;
F_20 ( V_26 , L_1 ) ;
F_21 ( V_48 , & V_26 -> V_49 -> V_50 [ 0 ] ) ;
F_22 ( & V_26 -> V_49 -> V_50 [ 0 ] ) ;
}
static bool F_23 ( struct V_25 * V_26 , unsigned long V_51 )
{
return F_24 ( V_52 , & V_26 -> V_53 , V_51 ) ;
}
static struct V_54 * F_25 ( struct V_25 * V_26 )
{
return F_26 ( & V_26 -> V_55 , struct V_54 ,
V_55 ) ;
}
static void F_27 ( struct V_25 * V_26 ,
struct V_54 * V_56 )
{
struct V_54 * V_57 ;
T_2 V_31 ;
F_28 (i_cmd, &xhci->cmd_list, cmd_list) {
if ( V_57 -> V_58 != V_59 )
continue;
V_57 -> V_58 = V_60 ;
F_20 ( V_26 , L_2 ,
V_57 -> V_61 ) ;
V_31 = F_9 (
V_57 -> V_61 -> V_9 . V_10 [ 3 ] ) & V_41 ;
V_57 -> V_61 -> V_9 . V_10 [ 0 ] = 0 ;
V_57 -> V_61 -> V_9 . V_10 [ 1 ] = 0 ;
V_57 -> V_61 -> V_9 . V_10 [ 2 ] = 0 ;
V_57 -> V_61 -> V_9 . V_10 [ 3 ] = F_16 (
F_29 ( V_62 ) | V_31 ) ;
}
V_26 -> V_46 = V_47 ;
if ( ( V_26 -> V_63 -> V_30 != V_26 -> V_63 -> V_35 ) &&
! ( V_26 -> V_64 & V_65 ) ) {
V_26 -> V_66 = V_56 ;
F_23 ( V_26 , V_67 ) ;
F_19 ( V_26 ) ;
}
}
static int F_30 ( struct V_25 * V_26 , unsigned long V_68 )
{
T_3 V_69 ;
int V_70 ;
F_20 ( V_26 , L_3 ) ;
F_31 ( & V_26 -> V_71 ) ;
V_69 = F_32 ( V_26 , & V_26 -> V_72 -> V_63 ) ;
F_33 ( V_26 , V_69 | V_73 ,
& V_26 -> V_72 -> V_63 ) ;
V_70 = F_34 ( & V_26 -> V_72 -> V_63 ,
V_74 , 0 , 5 * 1000 * 1000 ) ;
if ( V_70 < 0 ) {
F_33 ( V_26 , V_69 | V_73 ,
& V_26 -> V_72 -> V_63 ) ;
F_35 ( 1000 ) ;
V_70 = F_34 ( & V_26 -> V_72 -> V_63 ,
V_74 , 0 , 3 * 1000 * 1000 ) ;
if ( V_70 < 0 ) {
F_36 ( V_26 , L_4
L_5 ) ;
V_26 -> V_64 |= V_65 ;
F_37 ( V_26 ) ;
return - V_75 ;
}
}
F_38 ( & V_26 -> V_76 , V_68 ) ;
V_70 = F_39 ( & V_26 -> V_71 ,
F_40 ( 2000 ) ) ;
F_41 ( & V_26 -> V_76 , V_68 ) ;
if ( ! V_70 ) {
F_20 ( V_26 , L_6 ) ;
F_42 ( V_26 ) ;
} else {
F_27 ( V_26 , F_25 ( V_26 ) ) ;
}
return 0 ;
}
void F_43 ( struct V_25 * V_26 ,
unsigned int V_77 ,
unsigned int V_78 ,
unsigned int V_79 )
{
T_4 T_5 * V_80 = & V_26 -> V_49 -> V_50 [ V_77 ] ;
struct V_81 * V_82 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
unsigned int V_85 = V_82 -> V_85 ;
if ( ( V_85 & V_86 ) || ( V_85 & V_87 ) ||
( V_85 & V_88 ) )
return;
F_21 ( F_44 ( V_78 , V_79 ) , V_80 ) ;
}
static void F_45 ( struct V_25 * V_26 ,
unsigned int V_77 ,
unsigned int V_78 )
{
unsigned int V_79 ;
struct V_81 * V_82 ;
V_82 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
if ( ! ( V_82 -> V_85 & V_89 ) ) {
if ( V_82 -> V_14 && ! ( F_46 ( & V_82 -> V_14 -> V_90 ) ) )
F_43 ( V_26 , V_77 , V_78 , 0 ) ;
return;
}
for ( V_79 = 1 ; V_79 < V_82 -> V_91 -> V_92 ;
V_79 ++ ) {
struct V_93 * V_91 = V_82 -> V_91 ;
if ( ! F_46 ( & V_91 -> V_94 [ V_79 ] -> V_90 ) )
F_43 ( V_26 , V_77 , V_78 ,
V_79 ) ;
}
}
struct V_13 * F_47 ( struct V_25 * V_26 ,
unsigned int V_77 , unsigned int V_78 ,
unsigned int V_79 )
{
struct V_81 * V_82 ;
V_82 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
if ( ! ( V_82 -> V_85 & V_89 ) )
return V_82 -> V_14 ;
if ( V_79 == 0 ) {
F_48 ( V_26 ,
L_7
L_8 ,
V_77 , V_78 ) ;
return NULL ;
}
if ( V_79 < V_82 -> V_91 -> V_92 )
return V_82 -> V_91 -> V_94 [ V_79 ] ;
F_48 ( V_26 ,
L_9
L_10
L_11 ,
V_77 , V_78 ,
V_82 -> V_91 -> V_92 - 1 ,
V_79 ) ;
return NULL ;
}
void F_49 ( struct V_25 * V_26 ,
unsigned int V_77 , unsigned int V_78 ,
unsigned int V_79 , struct V_18 * V_95 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = V_26 -> V_83 [ V_77 ] ;
struct V_81 * V_82 = & V_99 -> V_84 [ V_78 ] ;
struct V_13 * V_100 ;
struct V_1 * V_101 ;
union V_3 * V_102 ;
T_1 V_103 ;
T_3 V_104 ;
bool V_105 = false ;
bool V_106 = false ;
V_100 = F_47 ( V_26 , V_77 ,
V_78 , V_79 ) ;
if ( ! V_100 ) {
F_48 ( V_26 , L_12
L_13 ,
V_79 ) ;
return;
}
F_50 ( V_26 , V_107 ,
L_14 ) ;
if ( V_82 -> V_85 & V_89 ) {
struct V_108 * V_109 =
& V_82 -> V_91 -> V_110 [ V_79 ] ;
V_104 = F_51 ( V_109 -> V_111 ) ;
} else {
struct V_112 * V_113
= F_52 ( V_26 , V_99 -> V_114 , V_78 ) ;
V_104 = F_51 ( V_113 -> V_115 ) ;
}
V_101 = V_100 -> V_29 ;
V_102 = V_100 -> V_30 ;
V_97 -> V_116 = V_104 & 0x1 ;
do {
if ( ! V_105 && F_1 ( V_101 , V_102 )
== ( T_1 ) ( V_104 & ~ 0xf ) ) {
V_105 = true ;
if ( V_106 )
break;
}
if ( V_102 == V_95 -> V_117 )
V_106 = true ;
if ( V_105 && F_4 ( V_102 ) &&
F_8 ( V_102 ) )
V_97 -> V_116 ^= 0x1 ;
F_12 ( V_26 , V_100 , & V_101 , & V_102 ) ;
if ( V_102 == V_82 -> V_14 -> V_30 ) {
F_36 ( V_26 , L_15 ) ;
V_97 -> V_118 = NULL ;
V_97 -> V_119 = NULL ;
return;
}
} while ( ! V_105 || ! V_106 );
V_97 -> V_118 = V_101 ;
V_97 -> V_119 = V_102 ;
F_50 ( V_26 , V_107 ,
L_16 , V_97 -> V_116 ) ;
F_50 ( V_26 , V_107 ,
L_17 ,
V_97 -> V_118 ) ;
V_103 = F_1 ( V_97 -> V_118 , V_97 -> V_119 ) ;
F_50 ( V_26 , V_107 ,
L_18 ,
( unsigned long long ) V_103 ) ;
}
static void F_53 ( struct V_25 * V_26 , struct V_13 * V_100 ,
struct V_18 * V_19 , bool V_120 )
{
struct V_1 * V_2 = V_19 -> V_121 ;
union V_3 * V_4 = V_19 -> V_122 ;
while ( 1 ) {
if ( F_4 ( V_4 ) ) {
V_4 -> V_11 . V_12 &= F_16 ( ~ V_36 ) ;
} else {
V_4 -> V_9 . V_10 [ 0 ] = 0 ;
V_4 -> V_9 . V_10 [ 1 ] = 0 ;
V_4 -> V_9 . V_10 [ 2 ] = 0 ;
V_4 -> V_9 . V_10 [ 3 ] &= F_16 ( V_41 ) ;
V_4 -> V_9 . V_10 [ 3 ] |= F_16 (
F_29 ( V_123 ) ) ;
}
if ( V_120 && V_4 != V_19 -> V_122 && V_4 != V_19 -> V_117 )
V_4 -> V_9 . V_10 [ 3 ] ^= F_16 ( V_41 ) ;
if ( V_4 == V_19 -> V_117 )
break;
F_12 ( V_26 , V_100 , & V_2 , & V_4 ) ;
}
}
static void F_54 ( struct V_25 * V_26 ,
struct V_81 * V_82 )
{
V_82 -> V_85 &= ~ V_86 ;
if ( F_55 ( & V_82 -> V_124 ) )
V_82 -> V_125 -- ;
}
static void F_56 ( struct V_25 * V_26 ,
struct V_18 * V_95 , int V_58 )
{
struct V_21 * V_21 = V_95 -> V_21 ;
struct V_20 * V_20 = V_21 -> V_22 ;
struct V_126 * V_127 = F_57 ( V_21 -> V_99 -> V_128 ) ;
if ( F_58 ( V_21 -> V_129 ) == V_130 ) {
F_59 ( V_26 ) -> V_131 . V_132 -- ;
if ( F_59 ( V_26 ) -> V_131 . V_132 == 0 ) {
if ( V_26 -> V_39 & V_133 )
F_60 () ;
}
}
F_61 ( V_20 ) ;
F_62 ( V_127 , V_21 ) ;
F_63 ( & V_26 -> V_76 ) ;
F_64 ( V_127 , V_21 , V_58 ) ;
F_65 ( & V_26 -> V_76 ) ;
}
static void F_66 ( struct V_25 * V_26 ,
struct V_13 * V_14 , struct V_18 * V_19 )
{
struct V_134 * V_99 = F_59 ( V_26 ) -> V_131 . V_135 ;
struct V_1 * V_2 = V_19 -> V_136 ;
struct V_21 * V_21 = V_19 -> V_21 ;
if ( ! V_2 || ! V_21 )
return;
if ( F_67 ( V_21 ) ) {
F_68 ( V_99 , V_2 -> V_137 , V_14 -> V_138 ,
V_139 ) ;
return;
}
F_69 ( V_21 -> V_140 , V_21 -> V_141 , V_2 -> V_142 ,
V_2 -> V_143 , V_2 -> V_144 ) ;
F_68 ( V_99 , V_2 -> V_137 , V_14 -> V_138 ,
V_145 ) ;
V_2 -> V_143 = 0 ;
V_2 -> V_144 = 0 ;
}
static void F_70 ( struct V_25 * V_26 , int V_77 ,
union V_3 * V_4 , struct V_146 * V_147 )
{
unsigned int V_78 ;
struct V_13 * V_100 ;
struct V_81 * V_82 ;
struct V_148 * V_149 ;
struct V_18 * V_95 = NULL ;
struct V_18 * V_150 ;
struct V_96 V_151 ;
if ( F_71 ( F_72 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ) ) {
if ( ! V_26 -> V_83 [ V_77 ] )
F_48 ( V_26 , L_19
L_20 ,
V_77 ) ;
return;
}
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_78 = F_73 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_82 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
if ( F_46 ( & V_82 -> V_152 ) ) {
F_54 ( V_26 , V_82 ) ;
V_82 -> V_153 = NULL ;
F_45 ( V_26 , V_77 , V_78 ) ;
return;
}
F_74 (entry, &ep->cancelled_td_list) {
V_95 = F_75 ( V_149 , struct V_18 , V_152 ) ;
F_50 ( V_26 , V_107 ,
L_21 ,
( unsigned long long ) F_1 (
V_95 -> V_121 , V_95 -> V_122 ) ) ;
V_100 = F_76 ( V_26 , V_95 -> V_21 ) ;
if ( ! V_100 ) {
F_48 ( V_26 , L_22
L_23 ,
V_95 -> V_21 ,
V_95 -> V_21 -> V_79 ) ;
goto V_154;
}
if ( V_95 == V_82 -> V_153 )
F_49 ( V_26 , V_77 , V_78 ,
V_95 -> V_21 -> V_79 ,
V_95 , & V_151 ) ;
else
F_53 ( V_26 , V_100 , V_95 , false ) ;
V_154:
F_77 ( & V_95 -> V_90 ) ;
}
V_150 = V_95 ;
F_54 ( V_26 , V_82 ) ;
if ( V_151 . V_119 && V_151 . V_118 ) {
F_78 ( V_26 , V_77 , V_78 ,
V_82 -> V_153 -> V_21 -> V_79 , & V_151 ) ;
F_19 ( V_26 ) ;
} else {
F_45 ( V_26 , V_77 , V_78 ) ;
}
V_82 -> V_153 = NULL ;
do {
V_95 = F_75 ( V_82 -> V_152 . V_15 ,
struct V_18 , V_152 ) ;
F_77 ( & V_95 -> V_152 ) ;
V_100 = F_76 ( V_26 , V_95 -> V_21 ) ;
if ( V_100 && V_95 -> V_136 )
F_66 ( V_26 , V_100 , V_95 ) ;
F_11 ( V_95 -> V_21 ) ;
if ( F_10 ( V_95 ) )
F_56 ( V_26 , V_95 , 0 ) ;
if ( V_26 -> V_64 & V_65 )
return;
} while ( V_95 != V_150 );
}
static void F_79 ( struct V_25 * V_26 , struct V_13 * V_14 )
{
struct V_18 * V_95 ;
while ( ! F_46 ( & V_14 -> V_90 ) ) {
V_95 = F_80 ( & V_14 -> V_90 ,
struct V_18 , V_90 ) ;
F_77 ( & V_95 -> V_90 ) ;
if ( ! F_46 ( & V_95 -> V_152 ) )
F_77 ( & V_95 -> V_152 ) ;
if ( V_95 -> V_136 )
F_66 ( V_26 , V_14 , V_95 ) ;
F_11 ( V_95 -> V_21 ) ;
if ( F_10 ( V_95 ) )
F_56 ( V_26 , V_95 , - V_75 ) ;
}
}
static void F_81 ( struct V_25 * V_26 ,
int V_77 , int V_78 )
{
struct V_18 * V_95 ;
struct V_81 * V_82 ;
struct V_13 * V_14 ;
V_82 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
if ( ( V_82 -> V_85 & V_89 ) ||
( V_82 -> V_85 & V_155 ) ) {
int V_79 ;
for ( V_79 = 0 ; V_79 < V_82 -> V_91 -> V_92 ;
V_79 ++ ) {
F_50 ( V_26 , V_107 ,
L_24 ,
V_77 , V_78 , V_79 + 1 ) ;
F_79 ( V_26 ,
V_82 -> V_91 -> V_94 [ V_79 ] ) ;
}
} else {
V_14 = V_82 -> V_14 ;
if ( ! V_14 )
return;
F_50 ( V_26 , V_107 ,
L_25 ,
V_77 , V_78 ) ;
F_79 ( V_26 , V_14 ) ;
}
while ( ! F_46 ( & V_82 -> V_152 ) ) {
V_95 = F_80 ( & V_82 -> V_152 ,
struct V_18 , V_152 ) ;
F_77 ( & V_95 -> V_152 ) ;
F_11 ( V_95 -> V_21 ) ;
if ( F_10 ( V_95 ) )
F_56 ( V_26 , V_95 , - V_75 ) ;
}
}
void F_82 ( unsigned long V_156 )
{
struct V_25 * V_26 ;
struct V_81 * V_82 ;
int V_70 , V_157 , V_158 ;
unsigned long V_68 ;
V_82 = (struct V_81 * ) V_156 ;
V_26 = V_82 -> V_26 ;
F_41 ( & V_26 -> V_76 , V_68 ) ;
V_82 -> V_125 -- ;
if ( ! ( V_82 -> V_125 == 0 && ( V_82 -> V_85 & V_86 ) ) ) {
F_50 ( V_26 , V_107 ,
L_26
L_27 ) ;
F_38 ( & V_26 -> V_76 , V_68 ) ;
return;
}
F_48 ( V_26 , L_28 ) ;
F_48 ( V_26 , L_29 ) ;
V_26 -> V_64 |= V_65 ;
F_83 ( V_26 ) ;
F_38 ( & V_26 -> V_76 , V_68 ) ;
V_70 = F_37 ( V_26 ) ;
F_41 ( & V_26 -> V_76 , V_68 ) ;
if ( V_70 < 0 ) {
F_48 ( V_26 , L_30 ) ;
F_48 ( V_26 , L_31 ) ;
}
for ( V_157 = 0 ; V_157 < V_159 ; V_157 ++ ) {
if ( ! V_26 -> V_83 [ V_157 ] )
continue;
for ( V_158 = 0 ; V_158 < 31 ; V_158 ++ )
F_81 ( V_26 , V_157 , V_158 ) ;
}
F_38 ( & V_26 -> V_76 , V_68 ) ;
F_50 ( V_26 , V_107 ,
L_32 ) ;
F_84 ( F_59 ( V_26 ) ) ;
F_50 ( V_26 , V_107 ,
L_33 ) ;
}
static void F_85 ( struct V_25 * V_26 ,
struct V_98 * V_99 ,
struct V_13 * V_100 ,
unsigned int V_78 )
{
union V_3 * V_160 ;
int V_161 ;
bool V_162 = false ;
V_161 = V_100 -> V_32 ;
V_160 = V_100 -> V_30 ;
if ( F_4 ( V_100 -> V_30 ) ) {
V_100 -> V_29 = V_100 -> V_29 -> V_15 ;
V_100 -> V_30 = V_100 -> V_29 -> V_6 ;
}
while ( V_100 -> V_30 != V_99 -> V_84 [ V_78 ] . V_163 ) {
V_100 -> V_32 ++ ;
V_100 -> V_30 ++ ;
if ( F_4 ( V_100 -> V_30 ) ) {
if ( V_100 -> V_30 ==
V_99 -> V_84 [ V_78 ] . V_163 )
break;
V_100 -> V_29 = V_100 -> V_29 -> V_15 ;
V_100 -> V_30 = V_100 -> V_29 -> V_6 ;
}
if ( V_100 -> V_30 == V_160 ) {
V_162 = true ;
break;
}
}
if ( V_162 ) {
F_20 ( V_26 , L_34 ) ;
V_100 -> V_32 = V_161 ;
}
}
static void F_86 ( struct V_25 * V_26 , int V_77 ,
union V_3 * V_4 , T_2 V_164 )
{
unsigned int V_78 ;
unsigned int V_79 ;
struct V_13 * V_100 ;
struct V_98 * V_99 ;
struct V_81 * V_82 ;
struct V_112 * V_113 ;
struct V_165 * V_166 ;
V_78 = F_73 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_79 = F_87 ( F_9 ( V_4 -> V_9 . V_10 [ 2 ] ) ) ;
V_99 = V_26 -> V_83 [ V_77 ] ;
V_82 = & V_99 -> V_84 [ V_78 ] ;
V_100 = F_88 ( V_99 , V_78 , V_79 ) ;
if ( ! V_100 ) {
F_48 ( V_26 , L_35 ,
V_79 ) ;
goto V_167;
}
V_113 = F_52 ( V_26 , V_99 -> V_114 , V_78 ) ;
V_166 = F_89 ( V_26 , V_99 -> V_114 ) ;
if ( V_164 != V_168 ) {
unsigned int V_85 ;
unsigned int V_169 ;
switch ( V_164 ) {
case V_170 :
F_48 ( V_26 , L_36 ) ;
break;
case V_171 :
F_48 ( V_26 , L_37 ) ;
V_85 = F_90 ( V_113 ) ;
V_169 = F_9 ( V_166 -> V_172 ) ;
V_169 = F_91 ( V_169 ) ;
F_50 ( V_26 , V_107 ,
L_38 ,
V_169 , V_85 ) ;
break;
case V_173 :
F_48 ( V_26 , L_39 ,
V_77 ) ;
break;
default:
F_48 ( V_26 , L_40 ,
V_164 ) ;
break;
}
} else {
T_3 V_115 ;
if ( V_82 -> V_85 & V_89 ) {
struct V_108 * V_109 =
& V_82 -> V_91 -> V_110 [ V_79 ] ;
V_115 = F_51 ( V_109 -> V_111 ) & V_174 ;
} else {
V_115 = F_51 ( V_113 -> V_115 ) & ~ V_175 ;
}
F_50 ( V_26 , V_107 ,
L_41 , V_115 ) ;
if ( F_1 ( V_82 -> V_176 ,
V_82 -> V_163 ) == V_115 ) {
F_85 ( V_26 , V_99 ,
V_100 , V_78 ) ;
} else {
F_48 ( V_26 , L_42 ) ;
F_48 ( V_26 , L_43 ,
V_82 -> V_176 , V_82 -> V_163 ) ;
}
}
V_167:
V_99 -> V_84 [ V_78 ] . V_85 &= ~ V_87 ;
V_99 -> V_84 [ V_78 ] . V_176 = NULL ;
V_99 -> V_84 [ V_78 ] . V_163 = NULL ;
F_45 ( V_26 , V_77 , V_78 ) ;
}
static void F_92 ( struct V_25 * V_26 , int V_77 ,
union V_3 * V_4 , T_2 V_164 )
{
unsigned int V_78 ;
V_78 = F_73 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
F_50 ( V_26 , V_177 ,
L_44 , V_164 ) ;
if ( V_26 -> V_39 & V_178 ) {
struct V_54 * V_179 ;
V_179 = F_93 ( V_26 , false , false , V_180 ) ;
if ( ! V_179 ) {
F_48 ( V_26 , L_45 ) ;
return;
}
F_50 ( V_26 , V_181 ,
L_46 ) ;
F_94 ( V_26 , V_179 ,
V_26 -> V_83 [ V_77 ] -> V_182 -> V_8 , V_77 ,
false ) ;
F_19 ( V_26 ) ;
} else {
V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] . V_85 &= ~ V_88 ;
}
}
static void F_95 ( struct V_25 * V_26 , int V_77 ,
struct V_54 * V_179 , T_2 V_164 )
{
if ( V_164 == V_168 )
V_179 -> V_77 = V_77 ;
else
V_179 -> V_77 = 0 ;
}
static void F_96 ( struct V_25 * V_26 , int V_77 )
{
struct V_98 * V_183 ;
V_183 = V_26 -> V_83 [ V_77 ] ;
if ( ! V_183 )
return;
if ( V_26 -> V_39 & V_184 )
F_97 ( V_26 , V_183 , true ) ;
F_98 ( V_26 , V_77 ) ;
}
static void F_99 ( struct V_25 * V_26 , int V_77 ,
struct V_146 * V_147 , T_2 V_164 )
{
struct V_98 * V_183 ;
struct V_185 * V_186 ;
unsigned int V_78 ;
unsigned int V_85 ;
T_2 V_187 , V_188 ;
V_183 = V_26 -> V_83 [ V_77 ] ;
V_186 = F_100 ( V_183 -> V_182 ) ;
if ( ! V_186 ) {
F_48 ( V_26 , L_47 ) ;
return;
}
V_187 = F_9 ( V_186 -> V_187 ) ;
V_188 = F_9 ( V_186 -> V_188 ) ;
V_78 = F_101 ( V_187 ) - 1 ;
if ( V_26 -> V_39 & V_178 &&
V_78 != ( unsigned int ) - 1 &&
V_187 - V_189 == V_188 ) {
V_85 = V_183 -> V_84 [ V_78 ] . V_85 ;
if ( ! ( V_85 & V_88 ) )
return;
F_50 ( V_26 , V_181 ,
L_48
L_49 ,
V_78 , V_85 ) ;
V_183 -> V_84 [ V_78 ] . V_85 &= ~ V_88 ;
F_45 ( V_26 , V_77 , V_78 ) ;
return;
}
return;
}
static void F_102 ( struct V_25 * V_26 , int V_77 ,
struct V_146 * V_147 )
{
F_20 ( V_26 , L_50 ) ;
if ( ! V_26 -> V_83 [ V_77 ] )
F_48 ( V_26 , L_51
L_52 , V_77 ) ;
}
static void F_103 ( struct V_25 * V_26 ,
struct V_146 * V_147 )
{
if ( ! ( V_26 -> V_39 & V_190 ) ) {
F_48 ( V_26 , L_53 ) ;
return;
}
F_50 ( V_26 , V_181 ,
L_54 ,
F_104 ( F_9 ( V_147 -> V_58 ) ) ,
F_105 ( F_9 ( V_147 -> V_58 ) ) ) ;
}
static void F_106 ( struct V_54 * V_191 , T_2 V_58 )
{
F_107 ( & V_191 -> V_55 ) ;
if ( V_191 -> V_192 ) {
V_191 -> V_58 = V_58 ;
F_108 ( V_191 -> V_192 ) ;
} else {
F_109 ( V_191 ) ;
}
}
void F_42 ( struct V_25 * V_26 )
{
struct V_54 * V_56 , * V_193 ;
F_110 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_106 ( V_56 , V_59 ) ;
}
void F_111 ( struct V_194 * V_195 )
{
struct V_25 * V_26 ;
int V_70 ;
unsigned long V_68 ;
T_3 V_196 ;
V_26 = F_112 ( F_113 ( V_195 ) , struct V_25 , V_53 ) ;
F_41 ( & V_26 -> V_76 , V_68 ) ;
if ( ! V_26 -> V_66 || F_114 ( & V_26 -> V_53 ) ) {
F_38 ( & V_26 -> V_76 , V_68 ) ;
return;
}
V_26 -> V_66 -> V_58 = V_59 ;
V_196 = F_32 ( V_26 , & V_26 -> V_72 -> V_63 ) ;
if ( ( V_26 -> V_46 & V_47 ) &&
( V_196 & V_74 ) ) {
V_26 -> V_46 = V_197 ;
F_20 ( V_26 , L_55 ) ;
V_70 = F_30 ( V_26 , V_68 ) ;
if ( F_71 ( V_70 == - V_75 ) ) {
F_36 ( V_26 , L_56 ) ;
F_42 ( V_26 ) ;
F_38 ( & V_26 -> V_76 , V_68 ) ;
F_84 ( F_59 ( V_26 ) -> V_198 ) ;
F_20 ( V_26 , L_57 ) ;
return;
}
goto V_199;
}
if ( V_26 -> V_64 & V_200 ) {
F_20 ( V_26 , L_58 ) ;
F_42 ( V_26 ) ;
goto V_199;
}
F_20 ( V_26 , L_59 ) ;
F_27 ( V_26 , V_26 -> V_66 ) ;
V_199:
F_38 ( & V_26 -> V_76 , V_68 ) ;
return;
}
static void F_115 ( struct V_25 * V_26 ,
struct V_146 * V_147 )
{
int V_77 = F_116 ( F_9 ( V_147 -> V_68 ) ) ;
T_3 V_201 ;
T_1 V_202 ;
T_2 V_164 ;
union V_3 * V_203 ;
struct V_54 * V_191 ;
T_2 V_204 ;
V_201 = F_51 ( V_147 -> V_203 ) ;
V_203 = V_26 -> V_63 -> V_30 ;
V_202 = F_1 ( V_26 -> V_63 -> V_29 ,
V_203 ) ;
if ( ! V_202 || V_201 != ( T_3 ) V_202 ) {
F_48 ( V_26 ,
L_60 ) ;
return;
}
V_191 = F_75 ( V_26 -> V_55 . V_15 , struct V_54 , V_55 ) ;
F_117 ( & V_26 -> V_53 ) ;
F_118 ( V_203 , (struct V_205 * ) V_147 ) ;
V_164 = F_119 ( F_9 ( V_147 -> V_58 ) ) ;
if ( V_164 == V_60 ) {
F_120 ( & V_26 -> V_71 ) ;
return;
}
if ( V_191 -> V_61 != V_26 -> V_63 -> V_30 ) {
F_36 ( V_26 ,
L_61 ) ;
return;
}
if ( V_164 == V_59 ) {
V_26 -> V_46 = V_206 ;
if ( V_191 -> V_58 == V_59 ) {
if ( V_26 -> V_66 == V_191 )
V_26 -> V_66 = NULL ;
goto V_207;
}
}
V_204 = F_121 ( F_9 ( V_203 -> V_9 . V_10 [ 3 ] ) ) ;
switch ( V_204 ) {
case V_208 :
F_95 ( V_26 , V_77 , V_191 , V_164 ) ;
break;
case V_209 :
F_96 ( V_26 , V_77 ) ;
break;
case V_210 :
if ( ! V_191 -> V_192 )
F_99 ( V_26 , V_77 , V_147 ,
V_164 ) ;
break;
case V_211 :
break;
case V_212 :
break;
case V_213 :
F_122 ( V_77 != F_116 (
F_9 ( V_203 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_70 ( V_26 , V_77 , V_203 , V_147 ) ;
break;
case V_214 :
F_122 ( V_77 != F_116 (
F_9 ( V_203 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_86 ( V_26 , V_77 , V_203 , V_164 ) ;
break;
case V_62 :
if ( V_191 -> V_58 == V_60 )
V_164 = V_60 ;
break;
case V_215 :
F_122 ( V_77 != F_116 (
F_9 ( V_203 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_92 ( V_26 , V_77 , V_203 , V_164 ) ;
break;
case V_216 :
V_77 = F_116 (
F_9 ( V_203 -> V_9 . V_10 [ 3 ] ) ) ;
F_102 ( V_26 , V_77 , V_147 ) ;
break;
case V_217 :
F_103 ( V_26 , V_147 ) ;
break;
default:
F_123 ( V_26 , L_62 , V_204 ) ;
break;
}
if ( V_191 -> V_55 . V_15 != & V_26 -> V_55 ) {
V_26 -> V_66 = F_75 ( V_191 -> V_55 . V_15 ,
struct V_54 , V_55 ) ;
F_23 ( V_26 , V_67 ) ;
} else if ( V_26 -> V_66 == V_191 ) {
V_26 -> V_66 = NULL ;
}
V_207:
F_106 ( V_191 , V_164 ) ;
F_13 ( V_26 , V_26 -> V_63 ) ;
}
static void F_124 ( struct V_25 * V_26 ,
union V_3 * V_147 )
{
T_2 V_218 ;
V_218 = F_121 ( F_9 ( V_147 -> V_9 . V_10 [ 3 ] ) ) ;
F_20 ( V_26 , L_63 , V_218 ) ;
if ( V_218 == V_219 && ( V_26 -> V_39 & V_190 ) )
F_115 ( V_26 , & V_147 -> V_220 ) ;
}
static unsigned int F_125 ( struct V_126 * V_127 ,
struct V_25 * V_26 , T_2 V_221 )
{
unsigned int V_157 ;
unsigned int V_222 = 0 ;
for ( V_157 = 0 ; V_157 < ( V_221 - 1 ) ; V_157 ++ ) {
T_6 V_223 = V_26 -> V_224 [ V_157 ] ;
if ( V_223 == 0 || V_223 == V_225 )
continue;
if ( ( V_223 == 0x03 ) == ( V_127 -> V_226 >= V_227 ) )
V_222 ++ ;
}
return V_222 ;
}
static void F_126 ( struct V_25 * V_26 ,
union V_3 * V_147 )
{
T_2 V_77 ;
struct V_228 * V_229 ;
V_77 = F_116 ( F_9 ( V_147 -> V_9 . V_10 [ 3 ] ) ) ;
if ( ! V_26 -> V_83 [ V_77 ] ) {
F_48 ( V_26 , L_64
L_65 , V_77 ) ;
return;
}
F_20 ( V_26 , L_66 ,
V_77 ) ;
V_229 = V_26 -> V_83 [ V_77 ] -> V_229 ;
if ( V_229 && V_229 -> V_230 )
F_127 ( V_229 -> V_230 , V_229 -> V_231 ) ;
}
static void F_128 ( struct V_25 * V_26 ,
union V_3 * V_147 )
{
struct V_126 * V_127 ;
T_2 V_221 ;
T_2 V_232 , V_233 ;
int V_234 ;
int V_77 ;
unsigned int V_235 ;
T_6 V_236 ;
struct V_237 * V_238 ;
T_4 T_5 * * V_224 ;
bool V_239 = false ;
if ( F_119 ( F_9 ( V_147 -> V_9 . V_10 [ 2 ] ) ) != V_168 )
F_48 ( V_26 ,
L_67 ) ;
V_221 = F_129 ( F_9 ( V_147 -> V_9 . V_10 [ 0 ] ) ) ;
F_20 ( V_26 , L_68 , V_221 ) ;
V_234 = F_130 ( V_26 -> V_240 ) ;
if ( ( V_221 <= 0 ) || ( V_221 > V_234 ) ) {
F_48 ( V_26 , L_69 , V_221 ) ;
F_13 ( V_26 , V_26 -> V_241 ) ;
return;
}
V_236 = V_26 -> V_224 [ V_221 - 1 ] ;
V_127 = F_59 ( V_26 ) ;
if ( ( V_236 == 0x03 ) != ( V_127 -> V_226 >= V_227 ) )
V_127 = V_26 -> V_242 ;
if ( V_236 == 0 ) {
F_48 ( V_26 , L_70
L_71 ,
V_221 ) ;
V_239 = true ;
goto V_167;
}
if ( V_236 == V_225 ) {
F_48 ( V_26 , L_72
L_71 ,
V_221 ) ;
V_239 = true ;
goto V_167;
}
V_238 = & V_26 -> V_238 [ F_131 ( V_127 ) ] ;
if ( V_127 -> V_226 >= V_227 )
V_224 = V_26 -> V_243 ;
else
V_224 = V_26 -> V_244 ;
V_235 = F_125 ( V_127 , V_26 ,
V_221 ) ;
V_232 = F_22 ( V_224 [ V_235 ] ) ;
if ( V_127 -> V_97 == V_245 ) {
F_20 ( V_26 , L_73 ) ;
F_132 ( V_127 ) ;
}
if ( V_127 -> V_226 >= V_227 && ( V_232 & V_246 ) == V_247 )
V_238 -> V_248 &= ~ ( 1 << V_235 ) ;
if ( ( V_232 & V_249 ) && ( V_232 & V_246 ) == V_250 ) {
F_20 ( V_26 , L_74 , V_221 ) ;
V_233 = F_22 ( & V_26 -> V_72 -> V_179 ) ;
if ( ! ( V_233 & V_251 ) ) {
F_48 ( V_26 , L_75 ) ;
goto V_167;
}
if ( F_133 ( V_232 ) ) {
F_20 ( V_26 , L_76 , V_221 ) ;
V_238 -> V_248 |= 1 << V_235 ;
F_134 ( V_26 , V_224 ,
V_235 , V_249 ) ;
F_135 ( V_26 , V_224 , V_235 ,
V_252 ) ;
V_239 = true ;
goto V_167;
} else if ( ! F_136 ( V_235 ,
& V_238 -> V_253 ) ) {
F_20 ( V_26 , L_77 , V_221 ) ;
V_238 -> V_254 [ V_235 ] = V_255 +
F_40 ( V_256 ) ;
F_137 ( V_235 , & V_238 -> V_253 ) ;
F_138 ( & V_127 -> V_257 ,
V_238 -> V_254 [ V_235 ] ) ;
}
}
if ( ( V_232 & V_249 ) && ( V_232 & V_246 ) == V_252 &&
F_133 ( V_232 ) ) {
F_20 ( V_26 , L_78 , V_221 ) ;
V_77 = F_139 ( V_127 , V_26 ,
V_235 + 1 ) ;
if ( V_77 && V_26 -> V_83 [ V_77 ] )
F_140 ( V_26 , V_77 ) ;
if ( V_238 -> V_248 & ( 1 << V_235 ) ) {
V_238 -> V_248 &=
~ ( 1 << V_235 ) ;
F_134 ( V_26 , V_224 ,
V_235 , V_249 ) ;
F_127 ( V_127 -> V_131 . V_258 ,
V_235 + 1 ) ;
V_239 = true ;
goto V_167;
}
}
if ( ! F_133 ( V_232 ) &&
F_141 ( V_235 ,
& V_238 -> V_259 ) ) {
F_108 ( & V_238 -> V_260 [ V_235 ] ) ;
V_239 = true ;
goto V_167;
}
if ( V_127 -> V_226 < V_227 )
F_134 ( V_26 , V_224 , V_235 ,
V_249 ) ;
V_167:
F_13 ( V_26 , V_26 -> V_241 ) ;
if ( V_239 )
return;
F_20 ( V_26 , L_79 , V_261 ) ;
F_137 ( V_262 , & V_127 -> V_68 ) ;
F_63 ( & V_26 -> V_76 ) ;
F_142 ( V_127 ) ;
F_65 ( & V_26 -> V_76 ) ;
}
struct V_1 * F_143 ( struct V_25 * V_26 ,
struct V_1 * V_121 ,
union V_3 * V_263 ,
union V_3 * V_264 ,
T_1 V_265 ,
bool V_266 )
{
T_1 V_267 ;
T_1 V_268 ;
T_1 V_269 ;
struct V_1 * V_270 ;
V_267 = F_1 ( V_121 , V_263 ) ;
V_270 = V_121 ;
do {
if ( V_267 == 0 )
return NULL ;
V_268 = F_1 ( V_270 ,
& V_270 -> V_6 [ V_7 - 1 ] ) ;
V_269 = F_1 ( V_270 , V_264 ) ;
if ( V_266 )
F_48 ( V_26 ,
L_80 ,
( unsigned long long ) V_265 ,
( unsigned long long ) V_267 ,
( unsigned long long ) V_269 ,
( unsigned long long ) V_270 -> V_8 ,
( unsigned long long ) V_268 ) ;
if ( V_269 > 0 ) {
if ( V_267 <= V_269 ) {
if ( V_265 >= V_267 && V_265 <= V_269 )
return V_270 ;
} else {
if ( ( V_265 >= V_267 &&
V_265 <= V_268 ) ||
( V_265 >= V_270 -> V_8 &&
V_265 <= V_269 ) )
return V_270 ;
}
return NULL ;
} else {
if ( V_265 >= V_267 && V_265 <= V_268 )
return V_270 ;
}
V_270 = V_270 -> V_15 ;
V_267 = F_1 ( V_270 , & V_270 -> V_6 [ 0 ] ) ;
} while ( V_270 != V_121 );
return NULL ;
}
static void F_144 ( struct V_25 * V_26 ,
unsigned int V_77 , unsigned int V_78 ,
unsigned int V_79 ,
struct V_18 * V_19 , union V_3 * V_271 )
{
struct V_81 * V_82 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
struct V_54 * V_179 ;
V_179 = F_93 ( V_26 , false , false , V_180 ) ;
if ( ! V_179 )
return;
V_82 -> V_85 |= V_88 ;
V_82 -> V_272 = V_79 ;
F_145 ( V_26 , V_179 , V_77 , V_78 ) ;
F_146 ( V_26 , V_78 , V_19 ) ;
V_82 -> V_272 = 0 ;
F_19 ( V_26 ) ;
}
static int F_147 ( struct V_25 * V_26 ,
struct V_112 * V_113 ,
unsigned int V_273 )
{
if ( V_273 == V_274 ||
V_273 == V_275 ||
V_273 == V_276 )
if ( F_90 ( V_113 ) == V_277 )
return 1 ;
return 0 ;
}
int F_148 ( struct V_25 * V_26 , unsigned int V_273 )
{
if ( V_273 >= 224 && V_273 <= 255 ) {
F_20 ( V_26 , L_81 ,
V_273 ) ;
F_20 ( V_26 , L_82 ) ;
return 1 ;
}
return 0 ;
}
static int F_149 ( struct V_25 * V_26 , struct V_18 * V_19 ,
union V_3 * V_271 , struct V_278 * V_147 ,
struct V_81 * V_82 , int * V_58 , bool V_279 )
{
struct V_98 * V_280 ;
struct V_13 * V_100 ;
unsigned int V_77 ;
int V_78 ;
struct V_21 * V_21 = NULL ;
struct V_112 * V_113 ;
struct V_20 * V_20 ;
T_2 V_273 ;
V_77 = F_116 ( F_9 ( V_147 -> V_68 ) ) ;
V_280 = V_26 -> V_83 [ V_77 ] ;
V_78 = F_150 ( F_9 ( V_147 -> V_68 ) ) - 1 ;
V_100 = F_151 ( V_82 , F_51 ( V_147 -> V_281 ) ) ;
V_113 = F_52 ( V_26 , V_280 -> V_114 , V_78 ) ;
V_273 = F_119 ( F_9 ( V_147 -> V_282 ) ) ;
if ( V_279 )
goto V_283;
if ( V_273 == V_284 ||
V_273 == V_285 ||
V_273 == V_286 ) {
V_82 -> V_153 = V_19 ;
return 0 ;
}
if ( V_273 == V_287 ||
F_147 ( V_26 , V_113 ,
V_273 ) ) {
F_144 ( V_26 , V_77 , V_78 ,
V_100 -> V_79 , V_19 , V_271 ) ;
} else {
while ( V_100 -> V_30 != V_19 -> V_117 )
F_13 ( V_26 , V_100 ) ;
F_13 ( V_26 , V_100 ) ;
}
V_283:
V_21 = V_19 -> V_21 ;
V_20 = V_21 -> V_22 ;
if ( V_19 -> V_136 )
F_66 ( V_26 , V_100 , V_19 ) ;
if ( V_21 -> V_288 > V_21 -> V_289 ) {
F_48 ( V_26 , L_83 ,
V_21 -> V_289 , V_21 -> V_288 ) ;
V_21 -> V_288 = 0 ;
* V_58 = 0 ;
}
F_77 ( & V_19 -> V_90 ) ;
if ( ! F_46 ( & V_19 -> V_152 ) )
F_77 ( & V_19 -> V_152 ) ;
F_11 ( V_21 ) ;
if ( F_10 ( V_19 ) ) {
if ( ( V_21 -> V_288 != V_21 -> V_289 &&
( V_21 -> V_290 & V_291 ) ) ||
( * V_58 != 0 && ! F_152 ( & V_21 -> V_82 -> V_292 ) ) )
F_20 ( V_26 , L_84 ,
V_21 , V_21 -> V_288 ,
V_21 -> V_289 , * V_58 ) ;
if ( F_58 ( V_21 -> V_129 ) == V_130 )
* V_58 = 0 ;
F_56 ( V_26 , V_19 , * V_58 ) ;
}
return 0 ;
}
static int F_153 ( struct V_25 * V_26 , struct V_13 * V_14 ,
union V_3 * V_293 )
{
T_2 V_294 ;
union V_3 * V_4 = V_14 -> V_30 ;
struct V_1 * V_2 = V_14 -> V_29 ;
for ( V_294 = 0 ; V_4 != V_293 ; F_12 ( V_26 , V_14 , & V_2 , & V_4 ) ) {
if ( ! F_2 ( V_4 ) && ! F_4 ( V_4 ) )
V_294 += F_154 ( F_9 ( V_4 -> V_9 . V_10 [ 2 ] ) ) ;
}
return V_294 ;
}
static int F_155 ( struct V_25 * V_26 , struct V_18 * V_19 ,
union V_3 * V_271 , struct V_278 * V_147 ,
struct V_81 * V_82 , int * V_58 )
{
struct V_98 * V_280 ;
struct V_13 * V_100 ;
unsigned int V_77 ;
int V_78 ;
struct V_112 * V_113 ;
T_2 V_273 ;
T_2 V_295 , V_296 ;
T_2 V_218 ;
V_218 = F_121 ( F_9 ( V_271 -> V_9 . V_10 [ 3 ] ) ) ;
V_77 = F_116 ( F_9 ( V_147 -> V_68 ) ) ;
V_280 = V_26 -> V_83 [ V_77 ] ;
V_78 = F_150 ( F_9 ( V_147 -> V_68 ) ) - 1 ;
V_100 = F_151 ( V_82 , F_51 ( V_147 -> V_281 ) ) ;
V_113 = F_52 ( V_26 , V_280 -> V_114 , V_78 ) ;
V_273 = F_119 ( F_9 ( V_147 -> V_282 ) ) ;
V_296 = V_19 -> V_21 -> V_289 ;
V_295 = F_156 ( F_9 ( V_147 -> V_282 ) ) ;
switch ( V_273 ) {
case V_168 :
if ( V_218 != V_297 ) {
F_48 ( V_26 , L_85 ,
( V_218 == V_298 ) ? L_86 : L_87 ) ;
* V_58 = - V_75 ;
break;
}
* V_58 = 0 ;
break;
case V_299 :
* V_58 = 0 ;
break;
case V_286 :
if ( V_218 == V_298 || V_218 == V_300 )
V_19 -> V_21 -> V_288 = V_295 ;
else
F_48 ( V_26 , L_88 ) ;
goto F_149;
case V_285 :
switch ( V_218 ) {
case V_301 :
V_19 -> V_21 -> V_288 = 0 ;
goto F_149;
case V_298 :
case V_300 :
V_19 -> V_21 -> V_288 = V_296 - V_295 ;
goto F_149;
default:
F_48 ( V_26 , L_89 ,
V_218 ) ;
goto F_149;
}
case V_284 :
goto F_149;
default:
if ( ! F_147 ( V_26 ,
V_113 , V_273 ) )
break;
F_20 ( V_26 , L_90 ,
V_273 , V_78 ) ;
case V_287 :
if ( V_218 == V_298 || V_218 == V_300 )
V_19 -> V_21 -> V_288 = V_296 - V_295 ;
else if ( ! V_19 -> V_302 )
V_19 -> V_21 -> V_288 = 0 ;
goto F_149;
}
if ( V_218 == V_301 )
goto F_149;
if ( V_218 == V_298 ||
V_218 == V_300 ) {
V_19 -> V_302 = true ;
V_19 -> V_21 -> V_288 = V_296 - V_295 ;
F_20 ( V_26 , L_91 ) ;
return 0 ;
}
if ( ! V_19 -> V_302 )
V_19 -> V_21 -> V_288 = V_296 ;
F_149:
return F_149 ( V_26 , V_19 , V_271 , V_147 , V_82 , V_58 , false ) ;
}
static int F_157 ( struct V_25 * V_26 , struct V_18 * V_19 ,
union V_3 * V_271 , struct V_278 * V_147 ,
struct V_81 * V_82 , int * V_58 )
{
struct V_13 * V_100 ;
struct V_20 * V_20 ;
int V_303 ;
struct V_304 * V_305 ;
T_2 V_273 ;
bool V_306 = false ;
T_2 V_295 , V_296 , V_307 ;
int V_308 ;
V_100 = F_151 ( V_82 , F_51 ( V_147 -> V_281 ) ) ;
V_273 = F_119 ( F_9 ( V_147 -> V_282 ) ) ;
V_20 = V_19 -> V_21 -> V_22 ;
V_303 = V_20 -> V_23 ;
V_305 = & V_19 -> V_21 -> V_309 [ V_303 ] ;
V_296 = V_305 -> V_24 ;
V_295 = F_156 ( F_9 ( V_147 -> V_282 ) ) ;
V_307 = F_154 ( F_9 ( V_271 -> V_9 . V_10 [ 2 ] ) ) ;
V_308 = V_19 -> V_21 -> V_290 & V_291 ?
- V_310 : 0 ;
switch ( V_273 ) {
case V_168 :
if ( V_295 ) {
V_305 -> V_58 = V_308 ;
if ( V_26 -> V_39 & V_311 )
V_306 = true ;
break;
}
V_305 -> V_58 = 0 ;
break;
case V_299 :
V_305 -> V_58 = V_308 ;
V_306 = true ;
break;
case V_312 :
V_305 -> V_58 = - V_313 ;
break;
case V_314 :
case V_275 :
V_305 -> V_58 = - V_315 ;
break;
case V_316 :
case V_287 :
V_305 -> V_58 = - V_317 ;
break;
case V_274 :
V_305 -> V_58 = - V_317 ;
if ( V_271 != V_19 -> V_117 )
return 0 ;
break;
case V_285 :
V_306 = true ;
break;
case V_286 :
V_305 -> V_58 = V_308 ;
V_296 = V_295 ;
break;
case V_284 :
V_296 = 0 ;
V_295 = 0 ;
break;
default:
V_306 = true ;
V_305 -> V_58 = - 1 ;
break;
}
if ( V_306 )
V_305 -> V_288 = F_153 ( V_26 , V_100 , V_271 ) +
V_307 - V_295 ;
else
V_305 -> V_288 = V_296 ;
V_19 -> V_21 -> V_288 += V_305 -> V_288 ;
return F_149 ( V_26 , V_19 , V_271 , V_147 , V_82 , V_58 , false ) ;
}
static int F_158 ( struct V_25 * V_26 , struct V_18 * V_19 ,
struct V_278 * V_147 ,
struct V_81 * V_82 , int * V_58 )
{
struct V_13 * V_100 ;
struct V_20 * V_20 ;
struct V_304 * V_305 ;
int V_303 ;
V_100 = F_151 ( V_82 , F_51 ( V_147 -> V_281 ) ) ;
V_20 = V_19 -> V_21 -> V_22 ;
V_303 = V_20 -> V_23 ;
V_305 = & V_19 -> V_21 -> V_309 [ V_303 ] ;
V_305 -> V_58 = - V_318 ;
V_305 -> V_288 = 0 ;
while ( V_100 -> V_30 != V_19 -> V_117 )
F_13 ( V_26 , V_100 ) ;
F_13 ( V_26 , V_100 ) ;
return F_149 ( V_26 , V_19 , NULL , V_147 , V_82 , V_58 , true ) ;
}
static int F_159 ( struct V_25 * V_26 , struct V_18 * V_19 ,
union V_3 * V_271 , struct V_278 * V_147 ,
struct V_81 * V_82 , int * V_58 )
{
struct V_13 * V_100 ;
T_2 V_273 ;
T_2 V_295 , V_296 , V_307 ;
V_100 = F_151 ( V_82 , F_51 ( V_147 -> V_281 ) ) ;
V_273 = F_119 ( F_9 ( V_147 -> V_282 ) ) ;
V_295 = F_156 ( F_9 ( V_147 -> V_282 ) ) ;
V_307 = F_154 ( F_9 ( V_271 -> V_9 . V_10 [ 2 ] ) ) ;
V_296 = V_19 -> V_21 -> V_289 ;
switch ( V_273 ) {
case V_168 :
if ( V_271 != V_19 -> V_117 || V_295 ) {
F_48 ( V_26 , L_92 ) ;
F_20 ( V_26 , L_93 ,
V_19 -> V_21 -> V_82 -> V_292 . V_319 ,
V_296 , V_295 ) ;
}
* V_58 = 0 ;
break;
case V_299 :
F_20 ( V_26 , L_93 ,
V_19 -> V_21 -> V_82 -> V_292 . V_319 ,
V_296 , V_295 ) ;
* V_58 = 0 ;
break;
case V_286 :
V_19 -> V_21 -> V_288 = V_295 ;
goto F_149;
case V_284 :
V_307 = 0 ;
V_295 = 0 ;
break;
default:
break;
}
if ( V_271 == V_19 -> V_117 )
V_19 -> V_21 -> V_288 = V_296 - V_295 ;
else
V_19 -> V_21 -> V_288 =
F_153 ( V_26 , V_100 , V_271 ) +
V_307 - V_295 ;
F_149:
if ( V_295 > V_296 ) {
F_48 ( V_26 , L_94 ,
V_295 ) ;
V_19 -> V_21 -> V_288 = 0 ;
}
return F_149 ( V_26 , V_19 , V_271 , V_147 , V_82 , V_58 , false ) ;
}
static int F_160 ( struct V_25 * V_26 ,
struct V_278 * V_147 )
__releases( &xhci->lock
static int F_161 ( struct V_25 * V_26 )
{
union V_3 * V_147 ;
int V_320 = 1 ;
int V_70 ;
if ( ! V_26 -> V_241 || ! V_26 -> V_241 -> V_30 ) {
F_36 ( V_26 , L_95 ) ;
return - V_321 ;
}
V_147 = V_26 -> V_241 -> V_30 ;
if ( ( F_9 ( V_147 -> V_220 . V_68 ) & V_41 ) !=
V_26 -> V_241 -> V_31 )
return 0 ;
F_162 () ;
switch ( F_9 ( V_147 -> V_220 . V_68 ) & V_322 ) {
case F_29 ( V_323 ) :
F_115 ( V_26 , & V_147 -> V_220 ) ;
break;
case F_29 ( V_324 ) :
F_128 ( V_26 , V_147 ) ;
V_320 = 0 ;
break;
case F_29 ( V_325 ) :
V_70 = F_160 ( V_26 , & V_147 -> V_326 ) ;
if ( V_70 >= 0 )
V_320 = 0 ;
break;
case F_29 ( V_327 ) :
F_126 ( V_26 , V_147 ) ;
break;
default:
if ( ( F_9 ( V_147 -> V_220 . V_68 ) & V_322 ) >=
F_29 ( 48 ) )
F_124 ( V_26 , V_147 ) ;
else
F_48 ( V_26 , L_96 ,
F_121 (
F_9 ( V_147 -> V_220 . V_68 ) ) ) ;
}
if ( V_26 -> V_64 & V_65 ) {
F_20 ( V_26 , L_97
L_98 ) ;
return 0 ;
}
if ( V_320 )
F_13 ( V_26 , V_26 -> V_241 ) ;
return 1 ;
}
T_7 F_163 ( struct V_126 * V_127 )
{
struct V_25 * V_26 = F_164 ( V_127 ) ;
T_2 V_58 ;
T_3 V_69 ;
union V_3 * V_328 ;
T_1 V_115 ;
F_65 ( & V_26 -> V_76 ) ;
V_58 = F_22 ( & V_26 -> V_72 -> V_58 ) ;
if ( V_58 == 0xffffffff )
goto V_329;
if ( ! ( V_58 & V_330 ) ) {
F_63 ( & V_26 -> V_76 ) ;
return V_331 ;
}
if ( V_58 & V_332 ) {
F_48 ( V_26 , L_99 ) ;
F_37 ( V_26 ) ;
V_329:
F_63 ( & V_26 -> V_76 ) ;
return V_333 ;
}
V_58 |= V_330 ;
F_21 ( V_58 , & V_26 -> V_72 -> V_58 ) ;
if ( V_127 -> V_334 ) {
T_2 V_335 ;
V_335 = F_22 ( & V_26 -> V_336 -> V_335 ) ;
V_335 |= V_337 ;
F_21 ( V_335 , & V_26 -> V_336 -> V_335 ) ;
}
if ( V_26 -> V_64 & V_65 ||
V_26 -> V_64 & V_338 ) {
F_20 ( V_26 , L_100
L_101 ) ;
V_69 = F_32 ( V_26 , & V_26 -> V_336 -> V_339 ) ;
F_33 ( V_26 , V_69 | V_340 ,
& V_26 -> V_336 -> V_339 ) ;
F_63 ( & V_26 -> V_76 ) ;
return V_333 ;
}
V_328 = V_26 -> V_241 -> V_30 ;
while ( F_161 ( V_26 ) > 0 ) {}
V_69 = F_32 ( V_26 , & V_26 -> V_336 -> V_339 ) ;
if ( V_328 != V_26 -> V_241 -> V_30 ) {
V_115 = F_1 ( V_26 -> V_241 -> V_29 ,
V_26 -> V_241 -> V_30 ) ;
if ( V_115 == 0 )
F_48 ( V_26 , L_102
L_103 ) ;
V_69 &= V_341 ;
V_69 |= ( ( T_3 ) V_115 & ( T_3 ) ~ V_341 ) ;
}
V_69 |= V_340 ;
F_33 ( V_26 , V_69 , & V_26 -> V_336 -> V_339 ) ;
F_63 ( & V_26 -> V_76 ) ;
return V_333 ;
}
T_7 F_165 ( int V_334 , void * V_127 )
{
return F_163 ( V_127 ) ;
}
static void F_166 ( struct V_25 * V_26 , struct V_13 * V_14 ,
bool V_33 ,
T_2 V_342 , T_2 V_343 , T_2 V_344 , T_2 V_345 )
{
struct V_205 * V_4 ;
V_4 = & V_14 -> V_35 -> V_9 ;
V_4 -> V_10 [ 0 ] = F_16 ( V_342 ) ;
V_4 -> V_10 [ 1 ] = F_16 ( V_343 ) ;
V_4 -> V_10 [ 2 ] = F_16 ( V_344 ) ;
V_4 -> V_10 [ 3 ] = F_16 ( V_345 ) ;
F_14 ( V_26 , V_14 , V_33 ) ;
}
static int F_167 ( struct V_25 * V_26 , struct V_13 * V_100 ,
T_2 V_85 , unsigned int V_43 , T_8 V_346 )
{
unsigned int V_347 ;
switch ( V_85 ) {
case V_348 :
F_48 ( V_26 , L_104 ) ;
return - V_349 ;
case V_350 :
F_48 ( V_26 , L_105 ) ;
return - V_351 ;
case V_277 :
F_20 ( V_26 , L_106 ) ;
case V_352 :
case V_353 :
break;
default:
F_36 ( V_26 , L_107 ) ;
return - V_351 ;
}
while ( 1 ) {
if ( F_18 ( V_26 , V_100 , V_43 ) )
break;
if ( V_100 == V_26 -> V_63 ) {
F_36 ( V_26 , L_108 ) ;
return - V_321 ;
}
F_50 ( V_26 , V_354 ,
L_109 ) ;
V_347 = V_43 - V_100 -> V_32 ;
if ( F_168 ( V_26 , V_100 , V_347 ,
V_346 ) ) {
F_36 ( V_26 , L_110 ) ;
return - V_321 ;
}
}
while ( F_4 ( V_100 -> V_35 ) ) {
if ( ! F_15 ( V_26 ) &&
! ( V_100 -> type == V_38 &&
( V_26 -> V_39 & V_40 ) ) )
V_100 -> V_35 -> V_11 . V_12 &=
F_16 ( ~ V_36 ) ;
else
V_100 -> V_35 -> V_11 . V_12 |=
F_16 ( V_36 ) ;
F_17 () ;
V_100 -> V_35 -> V_11 . V_12 ^= F_16 ( V_41 ) ;
if ( F_8 ( V_100 -> V_35 ) )
V_100 -> V_31 ^= 1 ;
V_100 -> V_42 = V_100 -> V_42 -> V_15 ;
V_100 -> V_35 = V_100 -> V_42 -> V_6 ;
}
return 0 ;
}
static int F_169 ( struct V_25 * V_26 ,
struct V_98 * V_280 ,
unsigned int V_78 ,
unsigned int V_79 ,
unsigned int V_43 ,
struct V_21 * V_21 ,
unsigned int V_355 ,
T_8 V_346 )
{
int V_70 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
struct V_13 * V_100 ;
struct V_112 * V_113 = F_52 ( V_26 , V_280 -> V_114 , V_78 ) ;
V_100 = F_88 ( V_280 , V_78 , V_79 ) ;
if ( ! V_100 ) {
F_20 ( V_26 , L_111 ,
V_79 ) ;
return - V_351 ;
}
V_70 = F_167 ( V_26 , V_100 , F_90 ( V_113 ) ,
V_43 , V_346 ) ;
if ( V_70 )
return V_70 ;
V_20 = V_21 -> V_22 ;
V_19 = V_20 -> V_19 [ V_355 ] ;
F_170 ( & V_19 -> V_90 ) ;
F_170 ( & V_19 -> V_152 ) ;
if ( V_355 == 0 ) {
V_70 = F_171 ( F_57 ( V_21 -> V_99 -> V_128 ) , V_21 ) ;
if ( F_71 ( V_70 ) )
return V_70 ;
}
V_19 -> V_21 = V_21 ;
F_172 ( & V_19 -> V_90 , & V_100 -> V_90 ) ;
V_19 -> V_121 = V_100 -> V_42 ;
V_19 -> V_122 = V_100 -> V_35 ;
V_20 -> V_19 [ V_355 ] = V_19 ;
return 0 ;
}
static unsigned int F_173 ( T_3 V_103 , T_3 V_356 )
{
unsigned int V_43 ;
V_43 = F_174 ( V_356 + ( V_103 & ( V_357 - 1 ) ) ,
V_357 ) ;
if ( V_43 == 0 )
V_43 ++ ;
return V_43 ;
}
static inline unsigned int F_175 ( struct V_21 * V_21 )
{
return F_173 ( V_21 -> V_358 , V_21 -> V_289 ) ;
}
static unsigned int F_176 ( struct V_21 * V_21 )
{
struct V_359 * V_140 ;
unsigned int V_157 , V_356 , V_360 , V_43 = 0 ;
V_360 = V_21 -> V_289 ;
F_177 (urb->sg, sg, urb->num_mapped_sgs, i) {
V_356 = F_178 ( V_140 ) ;
V_43 += F_173 ( F_179 ( V_140 ) , V_356 ) ;
V_356 = F_180 (unsigned int, len, full_len) ;
V_360 -= V_356 ;
if ( V_360 == 0 )
break;
}
return V_43 ;
}
static unsigned int F_181 ( struct V_21 * V_21 , int V_157 )
{
T_3 V_103 , V_356 ;
V_103 = ( T_3 ) ( V_21 -> V_358 + V_21 -> V_309 [ V_157 ] . V_361 ) ;
V_356 = V_21 -> V_309 [ V_157 ] . V_24 ;
return F_173 ( V_103 , V_356 ) ;
}
static void F_182 ( struct V_21 * V_21 , int V_362 )
{
if ( F_71 ( V_362 != V_21 -> V_289 ) )
F_183 ( & V_21 -> V_99 -> V_99 , L_112
L_113 ,
V_261 ,
V_21 -> V_82 -> V_292 . V_319 ,
V_362 , V_362 ,
V_21 -> V_289 ,
V_21 -> V_289 ) ;
}
static void F_184 ( struct V_25 * V_26 , int V_77 ,
unsigned int V_78 , unsigned int V_79 , int V_363 ,
struct V_205 * V_263 )
{
F_17 () ;
if ( V_363 )
V_263 -> V_10 [ 3 ] |= F_16 ( V_363 ) ;
else
V_263 -> V_10 [ 3 ] &= F_16 ( ~ V_41 ) ;
F_43 ( V_26 , V_77 , V_78 , V_79 ) ;
}
static void F_185 ( struct V_25 * V_26 , struct V_21 * V_21 ,
struct V_112 * V_113 )
{
int V_364 ;
int V_365 ;
V_364 = F_186 ( F_9 ( V_113 -> V_366 ) ) ;
V_365 = V_21 -> V_367 ;
if ( V_21 -> V_99 -> V_226 == V_368 ||
V_21 -> V_99 -> V_226 == V_369 )
V_365 *= 8 ;
if ( V_364 != V_365 ) {
F_187 ( & V_21 -> V_99 -> V_99 ,
L_114 ,
V_365 , V_365 == 1 ? L_115 : L_116 ,
V_364 , V_364 == 1 ? L_115 : L_116 ) ;
V_21 -> V_367 = V_364 ;
if ( V_21 -> V_99 -> V_226 == V_368 ||
V_21 -> V_99 -> V_226 == V_369 )
V_21 -> V_367 /= 8 ;
}
}
int F_188 ( struct V_25 * V_26 , T_8 V_346 ,
struct V_21 * V_21 , int V_77 , unsigned int V_78 )
{
struct V_112 * V_113 ;
V_113 = F_52 ( V_26 , V_26 -> V_83 [ V_77 ] -> V_114 , V_78 ) ;
F_185 ( V_26 , V_21 , V_113 ) ;
return F_189 ( V_26 , V_346 , V_21 , V_77 , V_78 ) ;
}
static T_2 F_190 ( struct V_25 * V_26 , int V_370 ,
int V_371 , unsigned int V_372 ,
struct V_21 * V_21 , bool V_33 )
{
T_2 V_373 , V_374 ;
if ( V_26 -> V_375 < 0x100 && ! ( V_26 -> V_39 & V_376 ) )
return ( ( V_372 - V_370 ) >> 10 ) ;
if ( ! V_33 || ( V_370 == 0 && V_371 == 0 ) ||
V_371 == V_372 )
return 0 ;
if ( V_26 -> V_39 & V_376 )
V_371 = 0 ;
V_373 = F_191 ( & V_21 -> V_82 -> V_292 ) ;
V_374 = F_174 ( V_372 , V_373 ) ;
return ( V_374 - ( ( V_370 + V_371 ) / V_373 ) ) ;
}
static int F_192 ( struct V_25 * V_26 , struct V_21 * V_21 , T_2 V_377 ,
T_2 * V_371 , struct V_1 * V_2 )
{
struct V_134 * V_99 = F_59 ( V_26 ) -> V_131 . V_135 ;
unsigned int V_378 ;
unsigned int V_379 ;
T_2 V_380 ;
V_379 = F_191 ( & V_21 -> V_82 -> V_292 ) ;
V_378 = ( V_377 + * V_371 ) % V_379 ;
if ( V_378 == 0 )
return 0 ;
F_20 ( V_26 , L_117 ,
V_378 , * V_371 ) ;
if ( * V_371 > V_378 ) {
* V_371 -= V_378 ;
F_20 ( V_26 , L_118 , * V_371 ) ;
return 0 ;
}
V_380 = V_379 - ( V_377 % V_379 ) ;
if ( V_380 > ( V_21 -> V_289 - V_377 ) )
V_380 = ( V_21 -> V_289 - V_377 ) ;
if ( F_67 ( V_21 ) ) {
F_193 ( V_21 -> V_140 , V_21 -> V_141 ,
V_2 -> V_142 , V_380 , V_377 ) ;
V_2 -> V_137 = F_194 ( V_99 , V_2 -> V_142 ,
V_379 , V_139 ) ;
} else {
V_2 -> V_137 = F_194 ( V_99 , V_2 -> V_142 ,
V_379 , V_145 ) ;
}
if ( F_195 ( V_99 , V_2 -> V_137 ) ) {
F_48 ( V_26 , L_119 ) ;
return 0 ;
}
* V_371 = V_380 ;
V_2 -> V_143 = V_380 ;
V_2 -> V_144 = V_377 ;
F_20 ( V_26 , L_120 , * V_371 ) ;
return 1 ;
}
int F_189 ( struct V_25 * V_26 , T_8 V_346 ,
struct V_21 * V_21 , int V_77 , unsigned int V_78 )
{
struct V_13 * V_14 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
struct V_205 * V_263 ;
struct V_359 * V_140 = NULL ;
bool V_33 = true ;
bool V_381 = false ;
bool V_122 = true ;
unsigned int V_43 ;
unsigned int V_363 , V_382 = 0 ;
unsigned int V_377 , V_383 , V_371 , V_360 ;
int V_384 , V_70 ;
T_2 V_10 , V_385 , V_386 ;
T_3 V_103 , V_387 ;
V_14 = F_76 ( V_26 , V_21 ) ;
if ( ! V_14 )
return - V_351 ;
V_360 = V_21 -> V_289 ;
if ( V_21 -> V_382 ) {
V_382 = V_21 -> V_141 ;
V_140 = V_21 -> V_140 ;
V_103 = ( T_3 ) F_179 ( V_140 ) ;
V_383 = F_178 ( V_140 ) ;
V_43 = F_176 ( V_21 ) ;
} else {
V_43 = F_175 ( V_21 ) ;
V_103 = ( T_3 ) V_21 -> V_358 ;
V_383 = V_360 ;
}
V_70 = F_169 ( V_26 , V_26 -> V_83 [ V_77 ] ,
V_78 , V_21 -> V_79 ,
V_43 , V_21 , 0 , V_346 ) ;
if ( F_71 ( V_70 < 0 ) )
return V_70 ;
V_20 = V_21 -> V_22 ;
if ( V_21 -> V_290 & V_388 && V_20 -> V_24 > 1 )
V_381 = true ;
V_19 = V_20 -> V_19 [ 0 ] ;
V_263 = & V_14 -> V_35 -> V_9 ;
V_363 = V_14 -> V_31 ;
V_387 = V_103 ;
for ( V_377 = 0 ; V_122 || V_377 < V_360 ;
V_377 += V_371 ) {
V_10 = F_29 ( V_300 ) ;
V_371 = F_196 ( V_103 ) ;
V_371 = F_180 (unsigned int, trb_buff_len, block_len) ;
if ( V_377 + V_371 > V_360 )
V_371 = V_360 - V_377 ;
if ( V_122 ) {
V_122 = false ;
if ( V_363 == 0 )
V_10 |= V_41 ;
} else
V_10 |= V_14 -> V_31 ;
if ( V_377 + V_371 < V_360 ) {
V_10 |= V_36 ;
if ( F_4 ( V_14 -> V_35 + 1 ) ) {
if ( F_192 ( V_26 , V_21 , V_377 ,
& V_371 ,
V_14 -> V_42 ) ) {
V_387 = V_14 -> V_42 -> V_137 ;
V_19 -> V_136 = V_14 -> V_42 ;
}
}
}
if ( V_377 + V_371 >= V_360 ) {
V_10 &= ~ V_36 ;
V_10 |= V_389 ;
V_33 = false ;
V_19 -> V_117 = V_14 -> V_35 ;
}
if ( F_197 ( V_21 ) )
V_10 |= V_390 ;
V_386 = F_190 ( V_26 , V_377 , V_371 ,
V_360 , V_21 , V_33 ) ;
V_385 = F_154 ( V_371 ) |
F_198 ( V_386 ) |
F_199 ( 0 ) ;
F_166 ( V_26 , V_14 , V_33 | V_381 ,
F_200 ( V_387 ) ,
F_201 ( V_387 ) ,
V_385 ,
V_10 ) ;
V_103 += V_371 ;
V_384 = V_371 ;
while ( V_140 && V_384 >= V_383 ) {
-- V_382 ;
V_384 -= V_383 ;
if ( V_382 != 0 ) {
V_140 = F_202 ( V_140 ) ;
V_383 = F_178 ( V_140 ) ;
V_103 = ( T_3 ) F_179 ( V_140 ) ;
V_103 += V_384 ;
}
}
V_383 -= V_384 ;
V_387 = V_103 ;
}
if ( V_381 ) {
V_70 = F_169 ( V_26 , V_26 -> V_83 [ V_77 ] ,
V_78 , V_21 -> V_79 ,
1 , V_21 , 1 , V_346 ) ;
V_20 -> V_19 [ 1 ] -> V_117 = V_14 -> V_35 ;
V_10 = F_29 ( V_300 ) | V_14 -> V_31 | V_389 ;
F_166 ( V_26 , V_14 , 0 , 0 , 0 , F_199 ( 0 ) , V_10 ) ;
}
F_182 ( V_21 , V_377 ) ;
F_184 ( V_26 , V_77 , V_78 , V_21 -> V_79 ,
V_363 , V_263 ) ;
return 0 ;
}
int F_203 ( struct V_25 * V_26 , T_8 V_346 ,
struct V_21 * V_21 , int V_77 , unsigned int V_78 )
{
struct V_13 * V_100 ;
int V_43 ;
int V_70 ;
struct V_391 * V_392 ;
struct V_205 * V_263 ;
int V_363 ;
T_2 V_10 , V_385 , V_386 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
V_100 = F_76 ( V_26 , V_21 ) ;
if ( ! V_100 )
return - V_351 ;
if ( ! V_21 -> V_393 )
return - V_351 ;
V_43 = 2 ;
if ( V_21 -> V_289 > 0 )
V_43 ++ ;
V_70 = F_169 ( V_26 , V_26 -> V_83 [ V_77 ] ,
V_78 , V_21 -> V_79 ,
V_43 , V_21 , 0 , V_346 ) ;
if ( V_70 < 0 )
return V_70 ;
V_20 = V_21 -> V_22 ;
V_19 = V_20 -> V_19 [ 0 ] ;
V_263 = & V_100 -> V_35 -> V_9 ;
V_363 = V_100 -> V_31 ;
V_392 = (struct V_391 * ) V_21 -> V_393 ;
V_10 = 0 ;
V_10 |= V_394 | F_29 ( V_301 ) ;
if ( V_363 == 0 )
V_10 |= 0x1 ;
if ( ( V_26 -> V_375 >= 0x100 ) || ( V_26 -> V_39 & V_376 ) ) {
if ( V_21 -> V_289 > 0 ) {
if ( V_392 -> V_395 & V_396 )
V_10 |= F_204 ( V_397 ) ;
else
V_10 |= F_204 ( V_398 ) ;
}
}
F_166 ( V_26 , V_100 , true ,
V_392 -> V_395 | V_392 -> V_399 << 8 | F_205 ( V_392 -> V_400 ) << 16 ,
F_205 ( V_392 -> V_401 ) | F_205 ( V_392 -> V_402 ) << 16 ,
F_154 ( 8 ) | F_199 ( 0 ) ,
V_10 ) ;
if ( F_197 ( V_21 ) )
V_10 = V_390 | F_29 ( V_298 ) ;
else
V_10 = F_29 ( V_298 ) ;
V_386 = F_190 ( V_26 , 0 ,
V_21 -> V_289 ,
V_21 -> V_289 ,
V_21 , 1 ) ;
V_385 = F_154 ( V_21 -> V_289 ) |
F_198 ( V_386 ) |
F_199 ( 0 ) ;
if ( V_21 -> V_289 > 0 ) {
if ( V_392 -> V_395 & V_396 )
V_10 |= V_403 ;
F_166 ( V_26 , V_100 , true ,
F_200 ( V_21 -> V_358 ) ,
F_201 ( V_21 -> V_358 ) ,
V_385 ,
V_10 | V_100 -> V_31 ) ;
}
V_19 -> V_117 = V_100 -> V_35 ;
if ( V_21 -> V_289 > 0 && V_392 -> V_395 & V_396 )
V_10 = 0 ;
else
V_10 = V_403 ;
F_166 ( V_26 , V_100 , false ,
0 ,
0 ,
F_199 ( 0 ) ,
V_10 | V_389 | F_29 ( V_297 ) | V_100 -> V_31 ) ;
F_184 ( V_26 , V_77 , V_78 , 0 ,
V_363 , V_263 ) ;
return 0 ;
}
static unsigned int F_206 ( struct V_25 * V_26 ,
struct V_21 * V_21 , unsigned int V_374 )
{
unsigned int V_404 ;
if ( V_26 -> V_375 < 0x100 || V_21 -> V_99 -> V_226 < V_405 )
return 0 ;
V_404 = V_21 -> V_82 -> V_406 . V_407 ;
return F_174 ( V_374 , V_404 + 1 ) - 1 ;
}
static unsigned int F_207 ( struct V_25 * V_26 ,
struct V_21 * V_21 , unsigned int V_374 )
{
unsigned int V_404 ;
unsigned int V_408 ;
if ( V_26 -> V_375 < 0x100 )
return 0 ;
if ( V_21 -> V_99 -> V_226 >= V_405 ) {
V_404 = V_21 -> V_82 -> V_406 . V_407 ;
V_408 = V_374 % ( V_404 + 1 ) ;
if ( V_408 == 0 )
return V_404 ;
return V_408 - 1 ;
}
if ( V_374 == 0 )
return 0 ;
return V_374 - 1 ;
}
static int F_208 ( struct V_25 * V_26 ,
struct V_21 * V_21 , int V_409 )
{
int V_410 , V_411 , V_70 = 0 ;
int V_412 , V_413 , V_414 ;
if ( V_21 -> V_99 -> V_226 == V_368 ||
V_21 -> V_99 -> V_226 == V_369 )
V_410 = V_21 -> V_410 + V_409 * V_21 -> V_367 ;
else
V_410 = ( V_21 -> V_410 + V_409 * V_21 -> V_367 ) >> 3 ;
V_411 = F_209 ( V_26 -> V_415 ) & 0x7 ;
if ( F_209 ( V_26 -> V_415 ) & ( 1 << 3 ) )
V_411 <<= 3 ;
V_414 = F_22 ( & V_26 -> V_416 -> V_417 ) ;
V_412 = F_210 ( V_414 + V_411 + 1 , 8 ) ;
V_413 = F_211 ( V_414 + 895 * 8 , 8 ) ;
V_410 &= 0x7ff ;
V_412 = ( V_412 >> 3 ) & 0x7ff ;
V_413 = ( V_413 >> 3 ) & 0x7ff ;
F_20 ( V_26 , L_121 ,
V_261 , V_409 , F_22 ( & V_26 -> V_416 -> V_417 ) ,
V_412 , V_413 , V_410 ) ;
if ( V_412 < V_413 ) {
if ( V_410 > V_413 ||
V_410 < V_412 )
V_70 = - V_351 ;
} else if ( V_412 > V_413 ) {
if ( ( V_410 > V_413 &&
V_410 < V_412 ) )
V_70 = - V_351 ;
} else {
V_70 = - V_351 ;
}
if ( V_409 == 0 ) {
if ( V_70 == - V_351 || V_410 == V_412 ) {
V_410 = V_412 + 1 ;
if ( V_21 -> V_99 -> V_226 == V_368 ||
V_21 -> V_99 -> V_226 == V_369 )
V_21 -> V_410 = V_410 ;
else
V_21 -> V_410 = V_410 << 3 ;
V_70 = 0 ;
}
}
if ( V_70 ) {
F_48 ( V_26 , L_122 ,
V_410 , V_414 , V_409 ,
V_412 , V_413 ) ;
F_48 ( V_26 , L_123 ) ;
return V_70 ;
}
return V_410 ;
}
static int F_212 ( struct V_25 * V_26 , T_8 V_346 ,
struct V_21 * V_21 , int V_77 , unsigned int V_78 )
{
struct V_13 * V_100 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
int V_418 , V_419 ;
struct V_205 * V_263 ;
bool V_122 ;
int V_363 ;
T_2 V_10 , V_385 ;
int V_362 , V_371 , V_420 , V_421 , V_70 ;
T_3 V_422 , V_103 ;
int V_157 , V_158 ;
bool V_33 ;
struct V_81 * V_423 ;
int V_424 ;
V_423 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
V_100 = V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] . V_14 ;
V_418 = V_21 -> V_425 ;
if ( V_418 < 1 ) {
F_20 ( V_26 , L_124 ) ;
return - V_351 ;
}
V_422 = ( T_3 ) V_21 -> V_358 ;
V_263 = & V_100 -> V_35 -> V_9 ;
V_363 = V_100 -> V_31 ;
V_20 = V_21 -> V_22 ;
for ( V_157 = 0 ; V_157 < V_418 ; V_157 ++ ) {
unsigned int V_426 , V_379 ;
unsigned int V_427 , V_428 ;
T_2 V_429 ;
V_122 = true ;
V_362 = 0 ;
V_103 = V_422 + V_21 -> V_309 [ V_157 ] . V_361 ;
V_420 = V_21 -> V_309 [ V_157 ] . V_24 ;
V_421 = V_420 ;
V_379 = F_191 ( & V_21 -> V_82 -> V_292 ) ;
V_426 = F_174 ( V_420 , V_379 ) ;
if ( V_426 == 0 )
V_426 ++ ;
V_427 = F_206 ( V_26 , V_21 , V_426 ) ;
V_428 = F_207 ( V_26 ,
V_21 , V_426 ) ;
V_419 = F_181 ( V_21 , V_157 ) ;
V_70 = F_169 ( V_26 , V_26 -> V_83 [ V_77 ] , V_78 ,
V_21 -> V_79 , V_419 , V_21 , V_157 , V_346 ) ;
if ( V_70 < 0 ) {
if ( V_157 == 0 )
return V_70 ;
goto V_167;
}
V_19 = V_20 -> V_19 [ V_157 ] ;
V_429 = V_430 ;
if ( ! ( V_21 -> V_290 & V_431 ) &&
F_213 ( V_26 -> V_432 ) ) {
V_424 = F_208 ( V_26 , V_21 , V_157 ) ;
if ( V_424 >= 0 )
V_429 = F_214 ( V_424 ) ;
}
V_10 = F_29 ( V_433 ) |
F_215 ( V_428 ) |
V_429 |
( V_157 ? V_100 -> V_31 : ! V_363 ) ;
if ( ! V_423 -> V_434 )
V_10 |= F_216 ( V_427 ) ;
for ( V_158 = 0 ; V_158 < V_419 ; V_158 ++ ) {
T_2 V_386 = 0 ;
if ( ! V_122 )
V_10 = F_29 ( V_300 ) |
V_100 -> V_31 ;
if ( F_197 ( V_21 ) )
V_10 |= V_390 ;
if ( V_158 < V_419 - 1 ) {
V_33 = true ;
V_10 |= V_36 ;
} else {
V_33 = false ;
V_19 -> V_117 = V_100 -> V_35 ;
V_10 |= V_389 ;
if ( V_26 -> V_375 >= 0x100 &&
! ( V_26 -> V_39 & V_435 ) &&
V_157 < V_418 - 1 )
V_10 |= V_436 ;
}
V_371 = F_196 ( V_103 ) ;
if ( V_371 > V_421 )
V_371 = V_421 ;
V_386 = F_190 ( V_26 , V_362 ,
V_371 , V_420 ,
V_21 , V_33 ) ;
V_385 = F_154 ( V_371 ) |
F_199 ( 0 ) ;
if ( V_122 && V_423 -> V_434 )
V_385 |= F_217 ( V_427 ) ;
else
V_385 |= F_198 ( V_386 ) ;
V_122 = false ;
F_166 ( V_26 , V_100 , V_33 ,
F_200 ( V_103 ) ,
F_201 ( V_103 ) ,
V_385 ,
V_10 ) ;
V_362 += V_371 ;
V_103 += V_371 ;
V_421 -= V_371 ;
}
if ( V_362 != V_420 ) {
F_36 ( V_26 , L_125 ) ;
V_70 = - V_351 ;
goto V_167;
}
}
if ( F_213 ( V_26 -> V_432 ) )
V_423 -> V_437 = V_21 -> V_410 + V_418 * V_21 -> V_367 ;
if ( F_59 ( V_26 ) -> V_131 . V_132 == 0 ) {
if ( V_26 -> V_39 & V_133 )
F_218 () ;
}
F_59 ( V_26 ) -> V_131 . V_132 ++ ;
F_184 ( V_26 , V_77 , V_78 , V_21 -> V_79 ,
V_363 , V_263 ) ;
return 0 ;
V_167:
for ( V_157 -- ; V_157 >= 0 ; V_157 -- )
F_77 ( & V_20 -> V_19 [ V_157 ] -> V_90 ) ;
V_20 -> V_19 [ 0 ] -> V_117 = V_100 -> V_35 ;
F_53 ( V_26 , V_100 , V_20 -> V_19 [ 0 ] , true ) ;
V_100 -> V_35 = V_20 -> V_19 [ 0 ] -> V_122 ;
V_100 -> V_42 = V_20 -> V_19 [ 0 ] -> V_121 ;
V_100 -> V_31 = V_363 ;
V_100 -> V_32 = V_100 -> V_161 ;
F_62 ( F_57 ( V_21 -> V_99 -> V_128 ) , V_21 ) ;
return V_70 ;
}
int F_219 ( struct V_25 * V_26 , T_8 V_346 ,
struct V_21 * V_21 , int V_77 , unsigned int V_78 )
{
struct V_98 * V_280 ;
struct V_13 * V_100 ;
struct V_112 * V_113 ;
int V_410 ;
int V_418 , V_43 , V_157 ;
int V_70 ;
struct V_81 * V_423 ;
int V_411 ;
V_280 = V_26 -> V_83 [ V_77 ] ;
V_423 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
V_100 = V_280 -> V_84 [ V_78 ] . V_14 ;
V_113 = F_52 ( V_26 , V_280 -> V_114 , V_78 ) ;
V_43 = 0 ;
V_418 = V_21 -> V_425 ;
for ( V_157 = 0 ; V_157 < V_418 ; V_157 ++ )
V_43 += F_181 ( V_21 , V_157 ) ;
V_70 = F_167 ( V_26 , V_100 , F_90 ( V_113 ) ,
V_43 , V_346 ) ;
if ( V_70 )
return V_70 ;
F_185 ( V_26 , V_21 , V_113 ) ;
if ( F_213 ( V_26 -> V_432 ) && ! F_46 ( & V_100 -> V_90 ) ) {
if ( F_90 ( V_113 ) == V_353 ) {
V_21 -> V_410 = V_423 -> V_437 ;
goto V_438;
}
}
V_410 = F_22 ( & V_26 -> V_416 -> V_417 ) ;
V_410 &= 0x3fff ;
V_411 = F_209 ( V_26 -> V_415 ) & 0x7 ;
if ( F_209 ( V_26 -> V_415 ) & ( 1 << 3 ) )
V_411 <<= 3 ;
V_410 += V_411 + V_439 ;
V_410 = F_210 ( V_410 , 8 ) ;
if ( V_21 -> V_99 -> V_226 == V_368 ||
V_21 -> V_99 -> V_226 == V_369 ) {
V_410 = F_210 ( V_410 , V_21 -> V_367 << 3 ) ;
V_21 -> V_410 = V_410 >> 3 ;
} else {
V_410 = F_210 ( V_410 , V_21 -> V_367 ) ;
V_21 -> V_410 = V_410 ;
}
V_438:
V_100 -> V_161 = V_100 -> V_32 ;
return F_212 ( V_26 , V_346 , V_21 , V_77 , V_78 ) ;
}
static int F_220 ( struct V_25 * V_26 , struct V_54 * V_191 ,
T_2 V_342 , T_2 V_343 ,
T_2 V_344 , T_2 V_345 , bool V_440 )
{
int V_441 = V_26 -> V_442 ;
int V_70 ;
if ( ( V_26 -> V_64 & V_65 ) ||
( V_26 -> V_64 & V_338 ) ) {
F_20 ( V_26 , L_126 ) ;
return - V_75 ;
}
if ( ! V_440 )
V_441 ++ ;
V_70 = F_167 ( V_26 , V_26 -> V_63 , V_353 ,
V_441 , V_180 ) ;
if ( V_70 < 0 ) {
F_36 ( V_26 , L_127 ) ;
if ( V_440 )
F_36 ( V_26 , L_128
L_129 ) ;
return V_70 ;
}
V_191 -> V_61 = V_26 -> V_63 -> V_35 ;
F_172 ( & V_191 -> V_55 , & V_26 -> V_55 ) ;
if ( V_26 -> V_55 . V_15 == & V_191 -> V_55 &&
! F_114 ( & V_26 -> V_53 ) ) {
V_26 -> V_66 = V_191 ;
F_23 ( V_26 , V_67 ) ;
}
F_166 ( V_26 , V_26 -> V_63 , false , V_342 , V_343 , V_344 ,
V_345 | V_26 -> V_63 -> V_31 ) ;
return 0 ;
}
int F_221 ( struct V_25 * V_26 , struct V_54 * V_191 ,
T_2 V_218 , T_2 V_77 )
{
return F_220 ( V_26 , V_191 , 0 , 0 , 0 ,
F_29 ( V_218 ) | F_222 ( V_77 ) , false ) ;
}
int F_223 ( struct V_25 * V_26 , struct V_54 * V_191 ,
T_1 V_443 , T_2 V_77 , enum V_444 V_392 )
{
return F_220 ( V_26 , V_191 , F_200 ( V_443 ) ,
F_201 ( V_443 ) , 0 ,
F_29 ( V_212 ) | F_222 ( V_77 )
| ( V_392 == V_445 ? V_446 : 0 ) , false ) ;
}
int F_224 ( struct V_25 * V_26 , struct V_54 * V_191 ,
T_2 V_342 , T_2 V_343 , T_2 V_344 , T_2 V_345 )
{
return F_220 ( V_26 , V_191 , V_342 , V_343 , V_344 , V_345 , false ) ;
}
int F_225 ( struct V_25 * V_26 , struct V_54 * V_191 ,
T_2 V_77 )
{
return F_220 ( V_26 , V_191 , 0 , 0 , 0 ,
F_29 ( V_216 ) | F_222 ( V_77 ) ,
false ) ;
}
int F_94 ( struct V_25 * V_26 ,
struct V_54 * V_191 , T_1 V_443 ,
T_2 V_77 , bool V_440 )
{
return F_220 ( V_26 , V_191 , F_200 ( V_443 ) ,
F_201 ( V_443 ) , 0 ,
F_29 ( V_210 ) | F_222 ( V_77 ) ,
V_440 ) ;
}
int F_226 ( struct V_25 * V_26 , struct V_54 * V_191 ,
T_1 V_443 , T_2 V_77 , bool V_440 )
{
return F_220 ( V_26 , V_191 , F_200 ( V_443 ) ,
F_201 ( V_443 ) , 0 ,
F_29 ( V_211 ) | F_222 ( V_77 ) ,
V_440 ) ;
}
int F_227 ( struct V_25 * V_26 , struct V_54 * V_191 ,
int V_77 , unsigned int V_78 , int V_447 )
{
T_2 V_448 = F_222 ( V_77 ) ;
T_2 V_449 = F_228 ( V_78 ) ;
T_2 type = F_29 ( V_213 ) ;
T_2 V_450 = F_229 ( V_447 ) ;
return F_220 ( V_26 , V_191 , 0 , 0 , 0 ,
V_448 | V_449 | type | V_450 , false ) ;
}
void F_78 ( struct V_25 * V_26 ,
unsigned int V_77 , unsigned int V_78 ,
unsigned int V_79 ,
struct V_96 * V_151 )
{
T_1 V_103 ;
T_2 V_448 = F_222 ( V_77 ) ;
T_2 V_449 = F_228 ( V_78 ) ;
T_2 V_451 = F_230 ( V_79 ) ;
T_2 V_452 = 0 ;
T_2 type = F_29 ( V_214 ) ;
struct V_81 * V_82 ;
struct V_54 * V_191 ;
int V_70 ;
F_50 ( V_26 , V_107 ,
L_130 ,
V_151 -> V_118 ,
( unsigned long long ) V_151 -> V_118 -> V_8 ,
V_151 -> V_119 ,
( unsigned long long ) F_1 (
V_151 -> V_118 , V_151 -> V_119 ) ,
V_151 -> V_116 ) ;
V_103 = F_1 ( V_151 -> V_118 ,
V_151 -> V_119 ) ;
if ( V_103 == 0 ) {
F_48 ( V_26 , L_131 ) ;
F_48 ( V_26 , L_132 ,
V_151 -> V_118 , V_151 -> V_119 ) ;
return;
}
V_82 = & V_26 -> V_83 [ V_77 ] -> V_84 [ V_78 ] ;
if ( ( V_82 -> V_85 & V_87 ) ) {
F_48 ( V_26 , L_131 ) ;
F_48 ( V_26 , L_133 ) ;
return;
}
V_191 = F_93 ( V_26 , false , false , V_180 ) ;
if ( ! V_191 ) {
F_48 ( V_26 , L_134 ) ;
return;
}
V_82 -> V_176 = V_151 -> V_118 ;
V_82 -> V_163 = V_151 -> V_119 ;
if ( V_79 )
V_452 = F_231 ( V_453 ) ;
V_70 = F_220 ( V_26 , V_191 ,
F_200 ( V_103 ) | V_452 | V_151 -> V_116 ,
F_201 ( V_103 ) , V_451 ,
V_448 | V_449 | type , false ) ;
if ( V_70 < 0 ) {
F_232 ( V_26 , V_191 ) ;
return;
}
V_82 -> V_85 |= V_87 ;
}
int F_145 ( struct V_25 * V_26 , struct V_54 * V_191 ,
int V_77 , unsigned int V_78 )
{
T_2 V_448 = F_222 ( V_77 ) ;
T_2 V_449 = F_228 ( V_78 ) ;
T_2 type = F_29 ( V_215 ) ;
return F_220 ( V_26 , V_191 , 0 , 0 , 0 ,
V_448 | V_449 | type , false ) ;
}
