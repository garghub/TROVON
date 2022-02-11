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
static void F_12 ( union V_3 * V_4 , T_2 V_25 )
{
if ( F_4 ( V_4 ) ) {
V_4 -> V_11 . V_12 &= F_13 ( ~ V_26 ) ;
} else {
V_4 -> V_9 . V_10 [ 0 ] = 0 ;
V_4 -> V_9 . V_10 [ 1 ] = 0 ;
V_4 -> V_9 . V_10 [ 2 ] = 0 ;
V_4 -> V_9 . V_10 [ 3 ] &= F_13 ( V_27 ) ;
V_4 -> V_9 . V_10 [ 3 ] |= F_13 ( F_14 ( V_25 ) ) ;
}
}
static void F_15 ( struct V_28 * V_29 ,
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
static void F_16 ( struct V_28 * V_29 , struct V_13 * V_14 )
{
V_14 -> V_30 ++ ;
if ( V_14 -> type == V_31 ) {
if ( ! F_6 ( V_14 -> V_32 , V_14 -> V_33 ) ) {
V_14 -> V_33 ++ ;
return;
}
if ( F_7 ( V_14 , V_14 -> V_32 , V_14 -> V_33 ) )
V_14 -> V_34 ^= 1 ;
V_14 -> V_32 = V_14 -> V_32 -> V_15 ;
V_14 -> V_33 = V_14 -> V_32 -> V_6 ;
return;
}
if ( ! F_4 ( V_14 -> V_33 ) ) {
V_14 -> V_33 ++ ;
V_14 -> V_35 ++ ;
}
while ( F_4 ( V_14 -> V_33 ) ) {
V_14 -> V_32 = V_14 -> V_32 -> V_15 ;
V_14 -> V_33 = V_14 -> V_32 -> V_6 ;
}
return;
}
static void F_17 ( struct V_28 * V_29 , struct V_13 * V_14 ,
bool V_36 )
{
T_2 V_37 ;
union V_3 * V_15 ;
V_37 = F_9 ( V_14 -> V_38 -> V_9 . V_10 [ 3 ] ) & V_26 ;
if ( ! F_4 ( V_14 -> V_38 ) )
V_14 -> V_35 -- ;
V_15 = ++ ( V_14 -> V_38 ) ;
V_14 -> V_39 ++ ;
while ( F_4 ( V_15 ) ) {
if ( ! V_37 && ! V_36 )
break;
if ( ! ( V_14 -> type == V_40 &&
( V_29 -> V_41 & V_42 ) ) &&
! F_18 ( V_29 ) ) {
V_15 -> V_11 . V_12 &= F_13 ( ~ V_26 ) ;
V_15 -> V_11 . V_12 |= F_13 ( V_37 ) ;
}
F_19 () ;
V_15 -> V_11 . V_12 ^= F_13 ( V_27 ) ;
if ( F_8 ( V_15 ) )
V_14 -> V_34 ^= 1 ;
V_14 -> V_43 = V_14 -> V_43 -> V_15 ;
V_14 -> V_38 = V_14 -> V_43 -> V_6 ;
V_15 = V_14 -> V_38 ;
}
}
static inline int F_20 ( struct V_28 * V_29 , struct V_13 * V_14 ,
unsigned int V_44 )
{
int V_45 ;
if ( V_14 -> V_35 < V_44 )
return 0 ;
if ( V_14 -> type != V_46 && V_14 -> type != V_31 ) {
V_45 = V_14 -> V_33 - V_14 -> V_32 -> V_6 ;
if ( V_14 -> V_35 < V_44 + V_45 )
return 0 ;
}
return 1 ;
}
void F_21 ( struct V_28 * V_29 )
{
if ( ! ( V_29 -> V_47 & V_48 ) )
return;
F_22 ( V_29 , L_1 ) ;
F_23 ( V_49 , & V_29 -> V_50 -> V_51 [ 0 ] ) ;
F_24 ( & V_29 -> V_50 -> V_51 [ 0 ] ) ;
}
static bool F_25 ( struct V_28 * V_29 , unsigned long V_52 )
{
return F_26 ( V_53 , & V_29 -> V_54 , V_52 ) ;
}
static struct V_55 * F_27 ( struct V_28 * V_29 )
{
return F_28 ( & V_29 -> V_56 , struct V_55 ,
V_56 ) ;
}
static void F_29 ( struct V_28 * V_29 ,
struct V_55 * V_57 )
{
struct V_55 * V_58 ;
F_30 (i_cmd, &xhci->cmd_list, cmd_list) {
if ( V_58 -> V_59 != V_60 )
continue;
V_58 -> V_59 = V_61 ;
F_22 ( V_29 , L_2 ,
V_58 -> V_62 ) ;
F_12 ( V_58 -> V_62 , V_63 ) ;
}
V_29 -> V_47 = V_48 ;
if ( ( V_29 -> V_64 -> V_33 != V_29 -> V_64 -> V_38 ) &&
! ( V_29 -> V_65 & V_66 ) ) {
V_29 -> V_67 = V_57 ;
F_25 ( V_29 , V_68 ) ;
F_21 ( V_29 ) ;
}
}
static int F_31 ( struct V_28 * V_29 , unsigned long V_69 )
{
T_3 V_70 ;
int V_71 ;
F_22 ( V_29 , L_3 ) ;
F_32 ( & V_29 -> V_72 ) ;
V_70 = F_33 ( V_29 , & V_29 -> V_73 -> V_64 ) ;
F_34 ( V_29 , V_70 | V_74 ,
& V_29 -> V_73 -> V_64 ) ;
V_71 = F_35 ( & V_29 -> V_73 -> V_64 ,
V_75 , 0 , 5 * 1000 * 1000 ) ;
if ( V_71 < 0 ) {
F_36 ( V_29 ,
L_4 ) ;
V_29 -> V_65 |= V_66 ;
F_37 ( V_29 ) ;
return - V_76 ;
}
F_38 ( & V_29 -> V_77 , V_69 ) ;
V_71 = F_39 ( & V_29 -> V_72 ,
F_40 ( 2000 ) ) ;
F_41 ( & V_29 -> V_77 , V_69 ) ;
if ( ! V_71 ) {
F_22 ( V_29 , L_5 ) ;
F_42 ( V_29 ) ;
} else {
F_29 ( V_29 , F_27 ( V_29 ) ) ;
}
return 0 ;
}
void F_43 ( struct V_28 * V_29 ,
unsigned int V_78 ,
unsigned int V_79 ,
unsigned int V_80 )
{
T_4 T_5 * V_81 = & V_29 -> V_50 -> V_51 [ V_78 ] ;
struct V_82 * V_83 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
unsigned int V_86 = V_83 -> V_86 ;
if ( ( V_86 & V_87 ) || ( V_86 & V_88 ) ||
( V_86 & V_89 ) )
return;
F_23 ( F_44 ( V_79 , V_80 ) , V_81 ) ;
}
static void F_45 ( struct V_28 * V_29 ,
unsigned int V_78 ,
unsigned int V_79 )
{
unsigned int V_80 ;
struct V_82 * V_83 ;
V_83 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
if ( ! ( V_83 -> V_86 & V_90 ) ) {
if ( V_83 -> V_14 && ! ( F_46 ( & V_83 -> V_14 -> V_91 ) ) )
F_43 ( V_29 , V_78 , V_79 , 0 ) ;
return;
}
for ( V_80 = 1 ; V_80 < V_83 -> V_92 -> V_93 ;
V_80 ++ ) {
struct V_94 * V_92 = V_83 -> V_92 ;
if ( ! F_46 ( & V_92 -> V_95 [ V_80 ] -> V_91 ) )
F_43 ( V_29 , V_78 , V_79 ,
V_80 ) ;
}
}
struct V_13 * F_47 ( struct V_28 * V_29 ,
unsigned int V_78 , unsigned int V_79 ,
unsigned int V_80 )
{
struct V_82 * V_83 ;
V_83 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
if ( ! ( V_83 -> V_86 & V_90 ) )
return V_83 -> V_14 ;
if ( V_80 == 0 ) {
F_48 ( V_29 ,
L_6
L_7 ,
V_78 , V_79 ) ;
return NULL ;
}
if ( V_80 < V_83 -> V_92 -> V_93 )
return V_83 -> V_92 -> V_95 [ V_80 ] ;
F_48 ( V_29 ,
L_8
L_9
L_10 ,
V_78 , V_79 ,
V_83 -> V_92 -> V_93 - 1 ,
V_80 ) ;
return NULL ;
}
void F_49 ( struct V_28 * V_29 ,
unsigned int V_78 , unsigned int V_79 ,
unsigned int V_80 , struct V_18 * V_96 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 = V_29 -> V_84 [ V_78 ] ;
struct V_82 * V_83 = & V_100 -> V_85 [ V_79 ] ;
struct V_13 * V_101 ;
struct V_1 * V_102 ;
union V_3 * V_103 ;
T_1 V_104 ;
T_3 V_105 ;
bool V_106 = false ;
bool V_107 = false ;
V_101 = F_47 ( V_29 , V_78 ,
V_79 , V_80 ) ;
if ( ! V_101 ) {
F_48 ( V_29 , L_11
L_12 ,
V_80 ) ;
return;
}
F_50 ( V_29 , V_108 ,
L_13 ) ;
if ( V_83 -> V_86 & V_90 ) {
struct V_109 * V_110 =
& V_83 -> V_92 -> V_111 [ V_80 ] ;
V_105 = F_51 ( V_110 -> V_112 ) ;
} else {
struct V_113 * V_114
= F_52 ( V_29 , V_100 -> V_115 , V_79 ) ;
V_105 = F_51 ( V_114 -> V_116 ) ;
}
V_102 = V_101 -> V_32 ;
V_103 = V_101 -> V_33 ;
V_98 -> V_117 = V_105 & 0x1 ;
do {
if ( ! V_106 && F_1 ( V_102 , V_103 )
== ( T_1 ) ( V_105 & ~ 0xf ) ) {
V_106 = true ;
if ( V_107 )
break;
}
if ( V_103 == V_96 -> V_118 )
V_107 = true ;
if ( V_106 && F_4 ( V_103 ) &&
F_8 ( V_103 ) )
V_98 -> V_117 ^= 0x1 ;
F_15 ( V_29 , V_101 , & V_102 , & V_103 ) ;
if ( V_103 == V_83 -> V_14 -> V_33 ) {
F_36 ( V_29 , L_14 ) ;
V_98 -> V_119 = NULL ;
V_98 -> V_120 = NULL ;
return;
}
} while ( ! V_106 || ! V_107 );
V_98 -> V_119 = V_102 ;
V_98 -> V_120 = V_103 ;
F_50 ( V_29 , V_108 ,
L_15 , V_98 -> V_117 ) ;
F_50 ( V_29 , V_108 ,
L_16 ,
V_98 -> V_119 ) ;
V_104 = F_1 ( V_98 -> V_119 , V_98 -> V_120 ) ;
F_50 ( V_29 , V_108 ,
L_17 ,
( unsigned long long ) V_104 ) ;
}
static void F_53 ( struct V_28 * V_29 , struct V_13 * V_101 ,
struct V_18 * V_19 , bool V_121 )
{
struct V_1 * V_2 = V_19 -> V_122 ;
union V_3 * V_4 = V_19 -> V_123 ;
while ( 1 ) {
F_12 ( V_4 , V_124 ) ;
if ( V_121 && V_4 != V_19 -> V_123 && V_4 != V_19 -> V_118 )
V_4 -> V_9 . V_10 [ 3 ] ^= F_13 ( V_27 ) ;
if ( V_4 == V_19 -> V_118 )
break;
F_15 ( V_29 , V_101 , & V_2 , & V_4 ) ;
}
}
static void F_54 ( struct V_28 * V_29 ,
struct V_82 * V_83 )
{
V_83 -> V_86 &= ~ V_87 ;
F_55 ( & V_83 -> V_125 ) ;
}
static void F_56 ( struct V_28 * V_29 ,
struct V_18 * V_96 , int V_59 )
{
struct V_21 * V_21 = V_96 -> V_21 ;
struct V_20 * V_20 = V_21 -> V_22 ;
struct V_126 * V_127 = F_57 ( V_21 -> V_100 -> V_128 ) ;
if ( F_58 ( V_21 -> V_129 ) == V_130 ) {
F_59 ( V_29 ) -> V_131 . V_132 -- ;
if ( F_59 ( V_29 ) -> V_131 . V_132 == 0 ) {
if ( V_29 -> V_41 & V_133 )
F_60 () ;
}
}
F_61 ( V_20 ) ;
F_62 ( V_127 , V_21 ) ;
F_63 ( & V_29 -> V_77 ) ;
F_64 ( V_127 , V_21 , V_59 ) ;
F_65 ( V_21 ) ;
F_66 ( & V_29 -> V_77 ) ;
}
static void F_67 ( struct V_28 * V_29 ,
struct V_13 * V_14 , struct V_18 * V_19 )
{
struct V_134 * V_100 = F_59 ( V_29 ) -> V_131 . V_135 ;
struct V_1 * V_2 = V_19 -> V_136 ;
struct V_21 * V_21 = V_19 -> V_21 ;
if ( ! V_14 || ! V_2 || ! V_21 )
return;
if ( F_68 ( V_21 ) ) {
F_69 ( V_100 , V_2 -> V_137 , V_14 -> V_138 ,
V_139 ) ;
return;
}
F_70 ( V_21 -> V_140 , V_21 -> V_141 , V_2 -> V_142 ,
V_2 -> V_143 , V_2 -> V_144 ) ;
F_69 ( V_100 , V_2 -> V_137 , V_14 -> V_138 ,
V_145 ) ;
V_2 -> V_143 = 0 ;
V_2 -> V_144 = 0 ;
}
static void F_71 ( struct V_28 * V_29 , int V_78 ,
union V_3 * V_4 , struct V_146 * V_147 )
{
unsigned int V_79 ;
struct V_13 * V_101 ;
struct V_82 * V_83 ;
struct V_18 * V_96 = NULL ;
struct V_18 * V_148 ;
struct V_97 V_149 ;
if ( F_72 ( F_73 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ) ) {
if ( ! V_29 -> V_84 [ V_78 ] )
F_48 ( V_29 , L_18
L_19 ,
V_78 ) ;
return;
}
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_79 = F_74 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_83 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
V_148 = F_75 ( & V_83 -> V_150 ,
struct V_18 , V_150 ) ;
if ( F_46 ( & V_83 -> V_150 ) ) {
F_54 ( V_29 , V_83 ) ;
V_83 -> V_151 = NULL ;
F_45 ( V_29 , V_78 , V_79 ) ;
return;
}
F_30 (cur_td, &ep->cancelled_td_list, cancelled_td_list) {
F_50 ( V_29 , V_108 ,
L_20 ,
( unsigned long long ) F_1 (
V_96 -> V_122 , V_96 -> V_123 ) ) ;
V_101 = F_76 ( V_29 , V_96 -> V_21 ) ;
if ( ! V_101 ) {
F_48 ( V_29 , L_21
L_22 ,
V_96 -> V_21 ,
V_96 -> V_21 -> V_80 ) ;
goto V_152;
}
if ( V_96 == V_83 -> V_151 )
F_49 ( V_29 , V_78 , V_79 ,
V_96 -> V_21 -> V_80 ,
V_96 , & V_149 ) ;
else
F_53 ( V_29 , V_101 , V_96 , false ) ;
V_152:
F_77 ( & V_96 -> V_91 ) ;
}
F_54 ( V_29 , V_83 ) ;
if ( V_149 . V_120 && V_149 . V_119 ) {
F_78 ( V_29 , V_78 , V_79 ,
V_83 -> V_151 -> V_21 -> V_80 , & V_149 ) ;
F_21 ( V_29 ) ;
} else {
F_45 ( V_29 , V_78 , V_79 ) ;
}
V_83 -> V_151 = NULL ;
do {
V_96 = F_79 ( & V_83 -> V_150 ,
struct V_18 , V_150 ) ;
F_77 ( & V_96 -> V_150 ) ;
V_101 = F_76 ( V_29 , V_96 -> V_21 ) ;
F_67 ( V_29 , V_101 , V_96 ) ;
F_11 ( V_96 -> V_21 ) ;
if ( F_10 ( V_96 ) )
F_56 ( V_29 , V_96 , 0 ) ;
if ( V_29 -> V_65 & V_66 )
return;
} while ( V_96 != V_148 );
}
static void F_80 ( struct V_28 * V_29 , struct V_13 * V_14 )
{
struct V_18 * V_96 ;
struct V_18 * V_153 ;
F_81 (cur_td, tmp, &ring->td_list, td_list) {
F_77 ( & V_96 -> V_91 ) ;
if ( ! F_46 ( & V_96 -> V_150 ) )
F_77 ( & V_96 -> V_150 ) ;
F_67 ( V_29 , V_14 , V_96 ) ;
F_11 ( V_96 -> V_21 ) ;
if ( F_10 ( V_96 ) )
F_56 ( V_29 , V_96 , - V_76 ) ;
}
}
static void F_82 ( struct V_28 * V_29 ,
int V_78 , int V_79 )
{
struct V_18 * V_96 ;
struct V_18 * V_153 ;
struct V_82 * V_83 ;
struct V_13 * V_14 ;
V_83 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
if ( ( V_83 -> V_86 & V_90 ) ||
( V_83 -> V_86 & V_154 ) ) {
int V_80 ;
for ( V_80 = 0 ; V_80 < V_83 -> V_92 -> V_93 ;
V_80 ++ ) {
F_50 ( V_29 , V_108 ,
L_23 ,
V_78 , V_79 , V_80 + 1 ) ;
F_80 ( V_29 ,
V_83 -> V_92 -> V_95 [ V_80 ] ) ;
}
} else {
V_14 = V_83 -> V_14 ;
if ( ! V_14 )
return;
F_50 ( V_29 , V_108 ,
L_24 ,
V_78 , V_79 ) ;
F_80 ( V_29 , V_14 ) ;
}
F_81 (cur_td, tmp, &ep->cancelled_td_list,
cancelled_td_list) {
F_77 ( & V_96 -> V_150 ) ;
F_11 ( V_96 -> V_21 ) ;
if ( F_10 ( V_96 ) )
F_56 ( V_29 , V_96 , - V_76 ) ;
}
}
void F_83 ( unsigned long V_155 )
{
struct V_28 * V_29 ;
struct V_82 * V_83 ;
int V_71 , V_156 , V_157 ;
unsigned long V_69 ;
V_83 = (struct V_82 * ) V_155 ;
V_29 = V_83 -> V_29 ;
F_41 ( & V_29 -> V_77 , V_69 ) ;
if ( ! ( V_83 -> V_86 & V_87 ) ||
F_84 ( & V_83 -> V_125 ) ) {
F_38 ( & V_29 -> V_77 , V_69 ) ;
F_22 ( V_29 , L_25 ) ;
return;
}
F_48 ( V_29 , L_26 ) ;
F_48 ( V_29 , L_27 ) ;
V_29 -> V_65 |= V_66 ;
V_83 -> V_86 &= ~ V_87 ;
F_85 ( V_29 ) ;
F_38 ( & V_29 -> V_77 , V_69 ) ;
V_71 = F_37 ( V_29 ) ;
F_41 ( & V_29 -> V_77 , V_69 ) ;
if ( V_71 < 0 ) {
F_48 ( V_29 , L_28 ) ;
F_48 ( V_29 , L_29 ) ;
}
for ( V_156 = 0 ; V_156 < V_158 ; V_156 ++ ) {
if ( ! V_29 -> V_84 [ V_156 ] )
continue;
for ( V_157 = 0 ; V_157 < 31 ; V_157 ++ )
F_82 ( V_29 , V_156 , V_157 ) ;
}
F_38 ( & V_29 -> V_77 , V_69 ) ;
F_50 ( V_29 , V_108 ,
L_30 ) ;
F_86 ( F_59 ( V_29 ) ) ;
F_50 ( V_29 , V_108 ,
L_31 ) ;
}
static void F_87 ( struct V_28 * V_29 ,
struct V_99 * V_100 ,
struct V_13 * V_101 ,
unsigned int V_79 )
{
union V_3 * V_159 ;
int V_160 ;
bool V_161 = false ;
V_160 = V_101 -> V_35 ;
V_159 = V_101 -> V_33 ;
if ( F_4 ( V_101 -> V_33 ) ) {
V_101 -> V_32 = V_101 -> V_32 -> V_15 ;
V_101 -> V_33 = V_101 -> V_32 -> V_6 ;
}
while ( V_101 -> V_33 != V_100 -> V_85 [ V_79 ] . V_162 ) {
V_101 -> V_35 ++ ;
V_101 -> V_33 ++ ;
if ( F_4 ( V_101 -> V_33 ) ) {
if ( V_101 -> V_33 ==
V_100 -> V_85 [ V_79 ] . V_162 )
break;
V_101 -> V_32 = V_101 -> V_32 -> V_15 ;
V_101 -> V_33 = V_101 -> V_32 -> V_6 ;
}
if ( V_101 -> V_33 == V_159 ) {
V_161 = true ;
break;
}
}
if ( V_161 ) {
F_22 ( V_29 , L_32 ) ;
V_101 -> V_35 = V_160 ;
}
}
static void F_88 ( struct V_28 * V_29 , int V_78 ,
union V_3 * V_4 , T_2 V_163 )
{
unsigned int V_79 ;
unsigned int V_80 ;
struct V_13 * V_101 ;
struct V_99 * V_100 ;
struct V_82 * V_83 ;
struct V_113 * V_114 ;
struct V_164 * V_165 ;
V_79 = F_74 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_80 = F_89 ( F_9 ( V_4 -> V_9 . V_10 [ 2 ] ) ) ;
V_100 = V_29 -> V_84 [ V_78 ] ;
V_83 = & V_100 -> V_85 [ V_79 ] ;
V_101 = F_90 ( V_100 , V_79 , V_80 ) ;
if ( ! V_101 ) {
F_48 ( V_29 , L_33 ,
V_80 ) ;
goto V_166;
}
V_114 = F_52 ( V_29 , V_100 -> V_115 , V_79 ) ;
V_165 = F_91 ( V_29 , V_100 -> V_115 ) ;
if ( V_163 != V_167 ) {
unsigned int V_86 ;
unsigned int V_168 ;
switch ( V_163 ) {
case V_169 :
F_48 ( V_29 , L_34 ) ;
break;
case V_170 :
F_48 ( V_29 , L_35 ) ;
V_86 = F_92 ( V_114 ) ;
V_168 = F_9 ( V_165 -> V_171 ) ;
V_168 = F_93 ( V_168 ) ;
F_50 ( V_29 , V_108 ,
L_36 ,
V_168 , V_86 ) ;
break;
case V_172 :
F_48 ( V_29 , L_37 ,
V_78 ) ;
break;
default:
F_48 ( V_29 , L_38 ,
V_163 ) ;
break;
}
} else {
T_3 V_116 ;
if ( V_83 -> V_86 & V_90 ) {
struct V_109 * V_110 =
& V_83 -> V_92 -> V_111 [ V_80 ] ;
V_116 = F_51 ( V_110 -> V_112 ) & V_173 ;
} else {
V_116 = F_51 ( V_114 -> V_116 ) & ~ V_174 ;
}
F_50 ( V_29 , V_108 ,
L_39 , V_116 ) ;
if ( F_1 ( V_83 -> V_175 ,
V_83 -> V_162 ) == V_116 ) {
F_87 ( V_29 , V_100 ,
V_101 , V_79 ) ;
} else {
F_48 ( V_29 , L_40 ) ;
F_48 ( V_29 , L_41 ,
V_83 -> V_175 , V_83 -> V_162 ) ;
}
}
V_166:
V_100 -> V_85 [ V_79 ] . V_86 &= ~ V_88 ;
V_100 -> V_85 [ V_79 ] . V_175 = NULL ;
V_100 -> V_85 [ V_79 ] . V_162 = NULL ;
F_45 ( V_29 , V_78 , V_79 ) ;
}
static void F_94 ( struct V_28 * V_29 , int V_78 ,
union V_3 * V_4 , T_2 V_163 )
{
unsigned int V_79 ;
V_79 = F_74 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
F_50 ( V_29 , V_176 ,
L_42 , V_163 ) ;
if ( V_29 -> V_41 & V_177 ) {
struct V_55 * V_178 ;
V_178 = F_95 ( V_29 , false , false , V_179 ) ;
if ( ! V_178 ) {
F_48 ( V_29 , L_43 ) ;
return;
}
F_50 ( V_29 , V_180 ,
L_44 ) ;
F_96 ( V_29 , V_178 ,
V_29 -> V_84 [ V_78 ] -> V_181 -> V_8 , V_78 ,
false ) ;
F_21 ( V_29 ) ;
} else {
V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] . V_86 &= ~ V_89 ;
}
}
static void F_97 ( struct V_28 * V_29 , int V_78 ,
struct V_55 * V_178 , T_2 V_163 )
{
if ( V_163 == V_167 )
V_178 -> V_78 = V_78 ;
else
V_178 -> V_78 = 0 ;
}
static void F_98 ( struct V_28 * V_29 , int V_78 )
{
struct V_99 * V_182 ;
V_182 = V_29 -> V_84 [ V_78 ] ;
if ( ! V_182 )
return;
if ( V_29 -> V_41 & V_183 )
F_99 ( V_29 , V_182 , true ) ;
F_100 ( V_29 , V_78 ) ;
}
static void F_101 ( struct V_28 * V_29 , int V_78 ,
struct V_146 * V_147 , T_2 V_163 )
{
struct V_99 * V_182 ;
struct V_184 * V_185 ;
unsigned int V_79 ;
unsigned int V_86 ;
T_2 V_186 , V_187 ;
V_182 = V_29 -> V_84 [ V_78 ] ;
V_185 = F_102 ( V_182 -> V_181 ) ;
if ( ! V_185 ) {
F_48 ( V_29 , L_45 ) ;
return;
}
V_186 = F_9 ( V_185 -> V_186 ) ;
V_187 = F_9 ( V_185 -> V_187 ) ;
V_79 = F_103 ( V_186 ) - 1 ;
if ( V_29 -> V_41 & V_177 &&
V_79 != ( unsigned int ) - 1 &&
V_186 - V_188 == V_187 ) {
V_86 = V_182 -> V_85 [ V_79 ] . V_86 ;
if ( ! ( V_86 & V_89 ) )
return;
F_50 ( V_29 , V_180 ,
L_46
L_47 ,
V_79 , V_86 ) ;
V_182 -> V_85 [ V_79 ] . V_86 &= ~ V_89 ;
F_45 ( V_29 , V_78 , V_79 ) ;
return;
}
return;
}
static void F_104 ( struct V_28 * V_29 , int V_78 ,
struct V_146 * V_147 )
{
F_22 ( V_29 , L_48 ) ;
if ( ! V_29 -> V_84 [ V_78 ] )
F_48 ( V_29 , L_49
L_50 , V_78 ) ;
}
static void F_105 ( struct V_28 * V_29 ,
struct V_146 * V_147 )
{
if ( ! ( V_29 -> V_41 & V_189 ) ) {
F_48 ( V_29 , L_51 ) ;
return;
}
F_50 ( V_29 , V_180 ,
L_52 ,
F_106 ( F_9 ( V_147 -> V_59 ) ) ,
F_107 ( F_9 ( V_147 -> V_59 ) ) ) ;
}
static void F_108 ( struct V_55 * V_190 , T_2 V_59 )
{
F_109 ( & V_190 -> V_56 ) ;
if ( V_190 -> V_191 ) {
V_190 -> V_59 = V_59 ;
F_110 ( V_190 -> V_191 ) ;
} else {
F_111 ( V_190 ) ;
}
}
void F_42 ( struct V_28 * V_29 )
{
struct V_55 * V_57 , * V_192 ;
F_81 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_108 ( V_57 , V_60 ) ;
}
void F_112 ( struct V_193 * V_194 )
{
struct V_28 * V_29 ;
int V_71 ;
unsigned long V_69 ;
T_3 V_195 ;
V_29 = F_113 ( F_114 ( V_194 ) , struct V_28 , V_54 ) ;
F_41 ( & V_29 -> V_77 , V_69 ) ;
if ( ! V_29 -> V_67 || F_115 ( & V_29 -> V_54 ) ) {
F_38 ( & V_29 -> V_77 , V_69 ) ;
return;
}
V_29 -> V_67 -> V_59 = V_60 ;
V_195 = F_33 ( V_29 , & V_29 -> V_73 -> V_64 ) ;
if ( ( V_29 -> V_47 & V_48 ) &&
( V_195 & V_75 ) ) {
V_29 -> V_47 = V_196 ;
F_22 ( V_29 , L_53 ) ;
V_71 = F_31 ( V_29 , V_69 ) ;
if ( F_72 ( V_71 == - V_76 ) ) {
F_36 ( V_29 , L_54 ) ;
F_42 ( V_29 ) ;
F_38 ( & V_29 -> V_77 , V_69 ) ;
F_86 ( F_59 ( V_29 ) -> V_197 ) ;
F_22 ( V_29 , L_55 ) ;
return;
}
goto V_198;
}
if ( V_29 -> V_65 & V_199 ) {
F_22 ( V_29 , L_56 ) ;
F_42 ( V_29 ) ;
goto V_198;
}
F_22 ( V_29 , L_57 ) ;
F_29 ( V_29 , V_29 -> V_67 ) ;
V_198:
F_38 ( & V_29 -> V_77 , V_69 ) ;
return;
}
static void F_116 ( struct V_28 * V_29 ,
struct V_146 * V_147 )
{
int V_78 = F_117 ( F_9 ( V_147 -> V_69 ) ) ;
T_3 V_200 ;
T_1 V_201 ;
T_2 V_163 ;
union V_3 * V_202 ;
struct V_55 * V_190 ;
T_2 V_203 ;
V_200 = F_51 ( V_147 -> V_202 ) ;
V_202 = V_29 -> V_64 -> V_33 ;
F_118 ( V_29 -> V_64 , & V_202 -> V_9 ) ;
V_201 = F_1 ( V_29 -> V_64 -> V_32 ,
V_202 ) ;
if ( ! V_201 || V_200 != ( T_3 ) V_201 ) {
F_48 ( V_29 ,
L_58 ) ;
return;
}
V_190 = F_79 ( & V_29 -> V_56 , struct V_55 , V_56 ) ;
F_119 ( & V_29 -> V_54 ) ;
V_163 = F_120 ( F_9 ( V_147 -> V_59 ) ) ;
if ( V_163 == V_61 ) {
F_121 ( & V_29 -> V_72 ) ;
return;
}
if ( V_190 -> V_62 != V_29 -> V_64 -> V_33 ) {
F_36 ( V_29 ,
L_59 ) ;
return;
}
if ( V_163 == V_60 ) {
V_29 -> V_47 = V_204 ;
if ( V_190 -> V_59 == V_60 ) {
if ( V_29 -> V_67 == V_190 )
V_29 -> V_67 = NULL ;
goto V_205;
}
}
V_203 = F_122 ( F_9 ( V_202 -> V_9 . V_10 [ 3 ] ) ) ;
switch ( V_203 ) {
case V_206 :
F_97 ( V_29 , V_78 , V_190 , V_163 ) ;
break;
case V_207 :
F_98 ( V_29 , V_78 ) ;
break;
case V_208 :
if ( ! V_190 -> V_191 )
F_101 ( V_29 , V_78 , V_147 ,
V_163 ) ;
break;
case V_209 :
break;
case V_210 :
break;
case V_211 :
F_123 ( V_78 != F_117 (
F_9 ( V_202 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_71 ( V_29 , V_78 , V_202 , V_147 ) ;
break;
case V_212 :
F_123 ( V_78 != F_117 (
F_9 ( V_202 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_88 ( V_29 , V_78 , V_202 , V_163 ) ;
break;
case V_63 :
if ( V_190 -> V_59 == V_61 )
V_163 = V_61 ;
break;
case V_213 :
F_123 ( V_78 != F_117 (
F_9 ( V_202 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_94 ( V_29 , V_78 , V_202 , V_163 ) ;
break;
case V_214 :
V_78 = F_117 (
F_9 ( V_202 -> V_9 . V_10 [ 3 ] ) ) ;
F_104 ( V_29 , V_78 , V_147 ) ;
break;
case V_215 :
F_105 ( V_29 , V_147 ) ;
break;
default:
F_124 ( V_29 , L_60 , V_203 ) ;
break;
}
if ( ! F_125 ( & V_29 -> V_56 ) ) {
V_29 -> V_67 = F_79 ( & V_190 -> V_56 ,
struct V_55 , V_56 ) ;
F_25 ( V_29 , V_68 ) ;
} else if ( V_29 -> V_67 == V_190 ) {
V_29 -> V_67 = NULL ;
}
V_205:
F_108 ( V_190 , V_163 ) ;
F_16 ( V_29 , V_29 -> V_64 ) ;
}
static void F_126 ( struct V_28 * V_29 ,
union V_3 * V_147 )
{
T_2 V_216 ;
V_216 = F_122 ( F_9 ( V_147 -> V_9 . V_10 [ 3 ] ) ) ;
F_22 ( V_29 , L_61 , V_216 ) ;
if ( V_216 == V_217 && ( V_29 -> V_41 & V_189 ) )
F_116 ( V_29 , & V_147 -> V_218 ) ;
}
static unsigned int F_127 ( struct V_126 * V_127 ,
struct V_28 * V_29 , T_2 V_219 )
{
unsigned int V_156 ;
unsigned int V_220 = 0 ;
for ( V_156 = 0 ; V_156 < ( V_219 - 1 ) ; V_156 ++ ) {
T_6 V_221 = V_29 -> V_222 [ V_156 ] ;
if ( V_221 == 0 || V_221 == V_223 )
continue;
if ( ( V_221 == 0x03 ) == ( V_127 -> V_224 >= V_225 ) )
V_220 ++ ;
}
return V_220 ;
}
static void F_128 ( struct V_28 * V_29 ,
union V_3 * V_147 )
{
T_2 V_78 ;
struct V_226 * V_227 ;
V_78 = F_117 ( F_9 ( V_147 -> V_9 . V_10 [ 3 ] ) ) ;
if ( ! V_29 -> V_84 [ V_78 ] ) {
F_48 ( V_29 , L_62
L_63 , V_78 ) ;
return;
}
F_22 ( V_29 , L_64 ,
V_78 ) ;
V_227 = V_29 -> V_84 [ V_78 ] -> V_227 ;
if ( V_227 && V_227 -> V_228 )
F_129 ( V_227 -> V_228 , V_227 -> V_229 ) ;
}
static void F_130 ( struct V_28 * V_29 ,
union V_3 * V_147 )
{
struct V_126 * V_127 ;
T_2 V_219 ;
T_2 V_230 , V_231 ;
int V_232 ;
int V_78 ;
unsigned int V_233 ;
T_6 V_234 ;
struct V_235 * V_236 ;
T_4 T_5 * * V_222 ;
bool V_237 = false ;
if ( F_120 ( F_9 ( V_147 -> V_9 . V_10 [ 2 ] ) ) != V_167 )
F_48 ( V_29 ,
L_65 ) ;
V_219 = F_131 ( F_9 ( V_147 -> V_9 . V_10 [ 0 ] ) ) ;
F_22 ( V_29 , L_66 , V_219 ) ;
V_232 = F_132 ( V_29 -> V_238 ) ;
if ( ( V_219 <= 0 ) || ( V_219 > V_232 ) ) {
F_48 ( V_29 , L_67 , V_219 ) ;
F_16 ( V_29 , V_29 -> V_239 ) ;
return;
}
V_234 = V_29 -> V_222 [ V_219 - 1 ] ;
V_127 = F_59 ( V_29 ) ;
if ( ( V_234 == 0x03 ) != ( V_127 -> V_224 >= V_225 ) )
V_127 = V_29 -> V_240 ;
if ( V_234 == 0 ) {
F_48 ( V_29 , L_68
L_69 ,
V_219 ) ;
V_237 = true ;
goto V_166;
}
if ( V_234 == V_223 ) {
F_48 ( V_29 , L_70
L_69 ,
V_219 ) ;
V_237 = true ;
goto V_166;
}
V_236 = & V_29 -> V_236 [ F_133 ( V_127 ) ] ;
if ( V_127 -> V_224 >= V_225 )
V_222 = V_29 -> V_241 ;
else
V_222 = V_29 -> V_242 ;
V_233 = F_127 ( V_127 , V_29 ,
V_219 ) ;
V_230 = F_24 ( V_222 [ V_233 ] ) ;
if ( V_127 -> V_98 == V_243 ) {
F_22 ( V_29 , L_71 ) ;
F_134 ( V_127 ) ;
}
if ( V_127 -> V_224 >= V_225 && ( V_230 & V_244 ) == V_245 )
V_236 -> V_246 &= ~ ( 1 << V_233 ) ;
if ( ( V_230 & V_247 ) && ( V_230 & V_244 ) == V_248 ) {
F_22 ( V_29 , L_72 , V_219 ) ;
V_231 = F_24 ( & V_29 -> V_73 -> V_178 ) ;
if ( ! ( V_231 & V_249 ) ) {
F_48 ( V_29 , L_73 ) ;
goto V_166;
}
if ( F_135 ( V_230 ) ) {
F_22 ( V_29 , L_74 , V_219 ) ;
V_236 -> V_246 |= 1 << V_233 ;
F_136 ( V_29 , V_222 ,
V_233 , V_247 ) ;
F_137 ( V_29 , V_222 , V_233 ,
V_250 ) ;
V_237 = true ;
goto V_166;
} else if ( ! F_138 ( V_233 ,
& V_236 -> V_251 ) ) {
F_22 ( V_29 , L_75 , V_219 ) ;
V_236 -> V_252 [ V_233 ] = V_253 +
F_40 ( V_254 ) ;
F_139 ( V_233 , & V_236 -> V_251 ) ;
F_140 ( & V_127 -> V_255 ,
V_236 -> V_252 [ V_233 ] ) ;
}
}
if ( ( V_230 & V_247 ) && ( V_230 & V_244 ) == V_250 &&
F_135 ( V_230 ) ) {
F_22 ( V_29 , L_76 , V_219 ) ;
V_78 = F_141 ( V_127 , V_29 ,
V_233 + 1 ) ;
if ( V_78 && V_29 -> V_84 [ V_78 ] )
F_142 ( V_29 , V_78 ) ;
if ( V_236 -> V_246 & ( 1 << V_233 ) ) {
V_236 -> V_246 &=
~ ( 1 << V_233 ) ;
F_136 ( V_29 , V_222 ,
V_233 , V_247 ) ;
F_129 ( V_127 -> V_131 . V_256 ,
V_233 + 1 ) ;
V_237 = true ;
goto V_166;
}
}
if ( ! F_135 ( V_230 ) &&
F_143 ( V_233 ,
& V_236 -> V_257 ) ) {
F_110 ( & V_236 -> V_258 [ V_233 ] ) ;
V_237 = true ;
goto V_166;
}
if ( V_127 -> V_224 < V_225 )
F_136 ( V_29 , V_222 , V_233 ,
V_247 ) ;
V_166:
F_16 ( V_29 , V_29 -> V_239 ) ;
if ( V_237 )
return;
F_22 ( V_29 , L_77 , V_259 ) ;
F_139 ( V_260 , & V_127 -> V_69 ) ;
F_63 ( & V_29 -> V_77 ) ;
F_144 ( V_127 ) ;
F_66 ( & V_29 -> V_77 ) ;
}
struct V_1 * F_145 ( struct V_28 * V_29 ,
struct V_1 * V_122 ,
union V_3 * V_261 ,
union V_3 * V_262 ,
T_1 V_263 ,
bool V_264 )
{
T_1 V_265 ;
T_1 V_266 ;
T_1 V_267 ;
struct V_1 * V_268 ;
V_265 = F_1 ( V_122 , V_261 ) ;
V_268 = V_122 ;
do {
if ( V_265 == 0 )
return NULL ;
V_266 = F_1 ( V_268 ,
& V_268 -> V_6 [ V_7 - 1 ] ) ;
V_267 = F_1 ( V_268 , V_262 ) ;
if ( V_264 )
F_48 ( V_29 ,
L_78 ,
( unsigned long long ) V_263 ,
( unsigned long long ) V_265 ,
( unsigned long long ) V_267 ,
( unsigned long long ) V_268 -> V_8 ,
( unsigned long long ) V_266 ) ;
if ( V_267 > 0 ) {
if ( V_265 <= V_267 ) {
if ( V_263 >= V_265 && V_263 <= V_267 )
return V_268 ;
} else {
if ( ( V_263 >= V_265 &&
V_263 <= V_266 ) ||
( V_263 >= V_268 -> V_8 &&
V_263 <= V_267 ) )
return V_268 ;
}
return NULL ;
} else {
if ( V_263 >= V_265 && V_263 <= V_266 )
return V_268 ;
}
V_268 = V_268 -> V_15 ;
V_265 = F_1 ( V_268 , & V_268 -> V_6 [ 0 ] ) ;
} while ( V_268 != V_122 );
return NULL ;
}
static void F_146 ( struct V_28 * V_29 ,
unsigned int V_78 , unsigned int V_79 ,
unsigned int V_80 ,
struct V_18 * V_19 , union V_3 * V_269 )
{
struct V_82 * V_83 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
struct V_55 * V_178 ;
V_178 = F_95 ( V_29 , false , false , V_179 ) ;
if ( ! V_178 )
return;
V_83 -> V_86 |= V_89 ;
V_83 -> V_270 = V_80 ;
F_147 ( V_29 , V_178 , V_78 , V_79 ) ;
F_148 ( V_29 , V_79 , V_19 ) ;
V_83 -> V_270 = 0 ;
F_21 ( V_29 ) ;
}
static int F_149 ( struct V_28 * V_29 ,
struct V_113 * V_114 ,
unsigned int V_271 )
{
if ( V_271 == V_272 ||
V_271 == V_273 ||
V_271 == V_274 )
if ( F_92 ( V_114 ) == V_275 )
return 1 ;
return 0 ;
}
int F_150 ( struct V_28 * V_29 , unsigned int V_271 )
{
if ( V_271 >= 224 && V_271 <= 255 ) {
F_22 ( V_29 , L_79 ,
V_271 ) ;
F_22 ( V_29 , L_80 ) ;
return 1 ;
}
return 0 ;
}
static int F_151 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_13 * V_101 , int * V_59 )
{
struct V_20 * V_20 ;
struct V_21 * V_21 = NULL ;
V_21 = V_19 -> V_21 ;
V_20 = V_21 -> V_22 ;
F_67 ( V_29 , V_101 , V_19 ) ;
if ( V_21 -> V_276 > V_21 -> V_277 ) {
F_48 ( V_29 , L_81 ,
V_21 -> V_277 , V_21 -> V_276 ) ;
V_21 -> V_276 = 0 ;
* V_59 = 0 ;
}
F_77 ( & V_19 -> V_91 ) ;
if ( ! F_46 ( & V_19 -> V_150 ) )
F_77 ( & V_19 -> V_150 ) ;
F_11 ( V_21 ) ;
if ( F_10 ( V_19 ) ) {
if ( ( V_21 -> V_276 != V_21 -> V_277 &&
( V_21 -> V_278 & V_279 ) ) ||
( * V_59 != 0 && ! F_152 ( & V_21 -> V_83 -> V_280 ) ) )
F_22 ( V_29 , L_82 ,
V_21 , V_21 -> V_276 ,
V_21 -> V_277 , * V_59 ) ;
if ( F_58 ( V_21 -> V_129 ) == V_130 )
* V_59 = 0 ;
F_56 ( V_29 , V_19 , * V_59 ) ;
}
return 0 ;
}
static int F_153 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_269 , struct V_281 * V_147 ,
struct V_82 * V_83 , int * V_59 , bool V_282 )
{
struct V_99 * V_283 ;
struct V_113 * V_114 ;
struct V_13 * V_101 ;
unsigned int V_78 ;
T_2 V_271 ;
int V_79 ;
V_78 = F_117 ( F_9 ( V_147 -> V_69 ) ) ;
V_283 = V_29 -> V_84 [ V_78 ] ;
V_79 = F_154 ( F_9 ( V_147 -> V_69 ) ) - 1 ;
V_101 = F_155 ( V_83 , F_51 ( V_147 -> V_284 ) ) ;
V_114 = F_52 ( V_29 , V_283 -> V_115 , V_79 ) ;
V_271 = F_120 ( F_9 ( V_147 -> V_285 ) ) ;
if ( V_282 )
goto V_286;
if ( V_271 == V_287 ||
V_271 == V_61 ||
V_271 == V_288 ) {
V_83 -> V_151 = V_19 ;
return 0 ;
}
if ( V_271 == V_289 ||
F_149 ( V_29 , V_114 ,
V_271 ) ) {
F_146 ( V_29 , V_78 , V_79 ,
V_101 -> V_80 , V_19 , V_269 ) ;
} else {
while ( V_101 -> V_33 != V_19 -> V_118 )
F_16 ( V_29 , V_101 ) ;
F_16 ( V_29 , V_101 ) ;
}
V_286:
return F_151 ( V_29 , V_19 , V_101 , V_59 ) ;
}
static int F_156 ( struct V_28 * V_29 , struct V_13 * V_14 ,
union V_3 * V_290 )
{
T_2 V_291 ;
union V_3 * V_4 = V_14 -> V_33 ;
struct V_1 * V_2 = V_14 -> V_32 ;
for ( V_291 = 0 ; V_4 != V_290 ; F_15 ( V_29 , V_14 , & V_2 , & V_4 ) ) {
if ( ! F_2 ( V_4 ) && ! F_4 ( V_4 ) )
V_291 += F_157 ( F_9 ( V_4 -> V_9 . V_10 [ 2 ] ) ) ;
}
return V_291 ;
}
static int F_158 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_269 , struct V_281 * V_147 ,
struct V_82 * V_83 , int * V_59 )
{
struct V_99 * V_283 ;
struct V_13 * V_101 ;
unsigned int V_78 ;
int V_79 ;
struct V_113 * V_114 ;
T_2 V_271 ;
T_2 V_292 , V_293 ;
T_2 V_216 ;
V_216 = F_122 ( F_9 ( V_269 -> V_9 . V_10 [ 3 ] ) ) ;
V_78 = F_117 ( F_9 ( V_147 -> V_69 ) ) ;
V_283 = V_29 -> V_84 [ V_78 ] ;
V_79 = F_154 ( F_9 ( V_147 -> V_69 ) ) - 1 ;
V_101 = F_155 ( V_83 , F_51 ( V_147 -> V_284 ) ) ;
V_114 = F_52 ( V_29 , V_283 -> V_115 , V_79 ) ;
V_271 = F_120 ( F_9 ( V_147 -> V_285 ) ) ;
V_293 = V_19 -> V_21 -> V_277 ;
V_292 = F_159 ( F_9 ( V_147 -> V_285 ) ) ;
switch ( V_271 ) {
case V_167 :
if ( V_216 != V_294 ) {
F_48 ( V_29 , L_83 ,
( V_216 == V_295 ) ? L_84 : L_85 ) ;
* V_59 = - V_76 ;
break;
}
* V_59 = 0 ;
break;
case V_296 :
* V_59 = 0 ;
break;
case V_288 :
if ( V_216 == V_295 || V_216 == V_297 )
V_19 -> V_21 -> V_276 = V_292 ;
else
F_48 ( V_29 , L_86 ) ;
goto F_153;
case V_61 :
switch ( V_216 ) {
case V_298 :
V_19 -> V_21 -> V_276 = 0 ;
goto F_153;
case V_295 :
case V_297 :
V_19 -> V_21 -> V_276 = V_293 - V_292 ;
goto F_153;
case V_294 :
V_19 -> V_21 -> V_276 = V_293 ;
goto F_153;
default:
F_48 ( V_29 , L_87 ,
V_216 ) ;
goto F_153;
}
case V_287 :
goto F_153;
default:
if ( ! F_149 ( V_29 ,
V_114 , V_271 ) )
break;
F_22 ( V_29 , L_88 ,
V_271 , V_79 ) ;
case V_289 :
if ( V_216 == V_295 || V_216 == V_297 )
V_19 -> V_21 -> V_276 = V_293 - V_292 ;
else if ( ! V_19 -> V_299 )
V_19 -> V_21 -> V_276 = 0 ;
goto F_153;
}
if ( V_216 == V_298 )
goto F_153;
if ( V_216 == V_295 ||
V_216 == V_297 ) {
V_19 -> V_299 = true ;
V_19 -> V_21 -> V_276 = V_293 - V_292 ;
F_22 ( V_29 , L_89 ) ;
return 0 ;
}
if ( ! V_19 -> V_299 )
V_19 -> V_21 -> V_276 = V_293 ;
F_153:
return F_153 ( V_29 , V_19 , V_269 , V_147 , V_83 , V_59 , false ) ;
}
static int F_160 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_269 , struct V_281 * V_147 ,
struct V_82 * V_83 , int * V_59 )
{
struct V_13 * V_101 ;
struct V_20 * V_20 ;
int V_300 ;
struct V_301 * V_302 ;
T_2 V_271 ;
bool V_303 = false ;
T_2 V_292 , V_293 , V_304 ;
int V_305 ;
V_101 = F_155 ( V_83 , F_51 ( V_147 -> V_284 ) ) ;
V_271 = F_120 ( F_9 ( V_147 -> V_285 ) ) ;
V_20 = V_19 -> V_21 -> V_22 ;
V_300 = V_20 -> V_23 ;
V_302 = & V_19 -> V_21 -> V_306 [ V_300 ] ;
V_293 = V_302 -> V_307 ;
V_292 = F_159 ( F_9 ( V_147 -> V_285 ) ) ;
V_304 = F_157 ( F_9 ( V_269 -> V_9 . V_10 [ 2 ] ) ) ;
V_305 = V_19 -> V_21 -> V_278 & V_279 ?
- V_308 : 0 ;
switch ( V_271 ) {
case V_167 :
if ( V_292 ) {
V_302 -> V_59 = V_305 ;
if ( V_29 -> V_41 & V_309 )
V_303 = true ;
break;
}
V_302 -> V_59 = 0 ;
break;
case V_296 :
V_302 -> V_59 = V_305 ;
V_303 = true ;
break;
case V_310 :
V_302 -> V_59 = - V_311 ;
break;
case V_312 :
case V_273 :
V_302 -> V_59 = - V_313 ;
break;
case V_314 :
case V_289 :
V_302 -> V_59 = - V_315 ;
break;
case V_272 :
V_302 -> V_59 = - V_315 ;
if ( V_269 != V_19 -> V_118 )
return 0 ;
break;
case V_61 :
V_303 = true ;
break;
case V_288 :
V_302 -> V_59 = V_305 ;
V_293 = V_292 ;
break;
case V_287 :
V_293 = 0 ;
V_292 = 0 ;
break;
default:
V_303 = true ;
V_302 -> V_59 = - 1 ;
break;
}
if ( V_303 )
V_302 -> V_276 = F_156 ( V_29 , V_101 , V_269 ) +
V_304 - V_292 ;
else
V_302 -> V_276 = V_293 ;
V_19 -> V_21 -> V_276 += V_302 -> V_276 ;
return F_153 ( V_29 , V_19 , V_269 , V_147 , V_83 , V_59 , false ) ;
}
static int F_161 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_281 * V_147 ,
struct V_82 * V_83 , int * V_59 )
{
struct V_13 * V_101 ;
struct V_20 * V_20 ;
struct V_301 * V_302 ;
int V_300 ;
V_101 = F_155 ( V_83 , F_51 ( V_147 -> V_284 ) ) ;
V_20 = V_19 -> V_21 -> V_22 ;
V_300 = V_20 -> V_23 ;
V_302 = & V_19 -> V_21 -> V_306 [ V_300 ] ;
V_302 -> V_59 = - V_316 ;
V_302 -> V_276 = 0 ;
while ( V_101 -> V_33 != V_19 -> V_118 )
F_16 ( V_29 , V_101 ) ;
F_16 ( V_29 , V_101 ) ;
return F_153 ( V_29 , V_19 , NULL , V_147 , V_83 , V_59 , true ) ;
}
static int F_162 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_269 , struct V_281 * V_147 ,
struct V_82 * V_83 , int * V_59 )
{
struct V_13 * V_101 ;
T_2 V_271 ;
T_2 V_292 , V_293 , V_304 ;
V_101 = F_155 ( V_83 , F_51 ( V_147 -> V_284 ) ) ;
V_271 = F_120 ( F_9 ( V_147 -> V_285 ) ) ;
V_292 = F_159 ( F_9 ( V_147 -> V_285 ) ) ;
V_304 = F_157 ( F_9 ( V_269 -> V_9 . V_10 [ 2 ] ) ) ;
V_293 = V_19 -> V_21 -> V_277 ;
switch ( V_271 ) {
case V_167 :
if ( V_269 != V_19 -> V_118 || V_292 ) {
F_48 ( V_29 , L_90 ) ;
F_22 ( V_29 , L_91 ,
V_19 -> V_21 -> V_83 -> V_280 . V_317 ,
V_293 , V_292 ) ;
}
* V_59 = 0 ;
break;
case V_296 :
F_22 ( V_29 , L_91 ,
V_19 -> V_21 -> V_83 -> V_280 . V_317 ,
V_293 , V_292 ) ;
* V_59 = 0 ;
break;
case V_288 :
V_19 -> V_21 -> V_276 = V_292 ;
goto F_153;
case V_287 :
V_304 = 0 ;
V_292 = 0 ;
break;
default:
break;
}
if ( V_269 == V_19 -> V_118 )
V_19 -> V_21 -> V_276 = V_293 - V_292 ;
else
V_19 -> V_21 -> V_276 =
F_156 ( V_29 , V_101 , V_269 ) +
V_304 - V_292 ;
F_153:
if ( V_292 > V_293 ) {
F_48 ( V_29 , L_92 ,
V_292 ) ;
V_19 -> V_21 -> V_276 = 0 ;
}
return F_153 ( V_29 , V_19 , V_269 , V_147 , V_83 , V_59 , false ) ;
}
static int F_163 ( struct V_28 * V_29 ,
struct V_281 * V_147 )
{
struct V_99 * V_283 ;
struct V_82 * V_83 ;
struct V_13 * V_101 ;
unsigned int V_78 ;
int V_79 ;
struct V_18 * V_19 = NULL ;
T_1 V_318 ;
struct V_1 * V_319 ;
union V_3 * V_269 ;
int V_59 = - V_320 ;
struct V_113 * V_114 ;
struct V_321 * V_153 ;
T_2 V_271 ;
int V_322 = 0 ;
bool V_323 = false ;
V_78 = F_117 ( F_9 ( V_147 -> V_69 ) ) ;
V_283 = V_29 -> V_84 [ V_78 ] ;
if ( ! V_283 ) {
F_36 ( V_29 , L_93 ) ;
F_36 ( V_29 , L_94 ,
( unsigned long long ) F_1 (
V_29 -> V_239 -> V_32 ,
V_29 -> V_239 -> V_33 ) ,
F_164 ( F_51 ( V_147 -> V_284 ) ) ,
F_165 ( F_51 ( V_147 -> V_284 ) ) ,
F_9 ( V_147 -> V_285 ) ,
F_9 ( V_147 -> V_69 ) ) ;
F_22 ( V_29 , L_95 ) ;
F_166 ( V_29 , V_29 -> V_239 -> V_32 ) ;
return - V_324 ;
}
V_79 = F_154 ( F_9 ( V_147 -> V_69 ) ) - 1 ;
V_83 = & V_283 -> V_85 [ V_79 ] ;
V_101 = F_155 ( V_83 , F_51 ( V_147 -> V_284 ) ) ;
V_114 = F_52 ( V_29 , V_283 -> V_115 , V_79 ) ;
if ( ! V_101 || F_92 ( V_114 ) == V_325 ) {
F_36 ( V_29 , L_96
L_97 ) ;
F_36 ( V_29 , L_94 ,
( unsigned long long ) F_1 (
V_29 -> V_239 -> V_32 ,
V_29 -> V_239 -> V_33 ) ,
F_164 ( F_51 ( V_147 -> V_284 ) ) ,
F_165 ( F_51 ( V_147 -> V_284 ) ) ,
F_9 ( V_147 -> V_285 ) ,
F_9 ( V_147 -> V_69 ) ) ;
F_22 ( V_29 , L_95 ) ;
F_166 ( V_29 , V_29 -> V_239 -> V_32 ) ;
return - V_324 ;
}
if ( V_83 -> V_282 ) {
F_167 (tmp, &ep_ring->td_list)
V_322 ++ ;
}
V_318 = F_51 ( V_147 -> V_284 ) ;
V_271 = F_120 ( F_9 ( V_147 -> V_285 ) ) ;
switch ( V_271 ) {
case V_167 :
if ( F_159 ( F_9 ( V_147 -> V_285 ) ) == 0 )
break;
if ( V_29 -> V_41 & V_309 )
V_271 = V_296 ;
else
F_168 ( V_29 ,
L_98 ) ;
case V_296 :
break;
case V_61 :
F_22 ( V_29 , L_99 ) ;
break;
case V_287 :
F_22 ( V_29 , L_100 ) ;
break;
case V_288 :
F_22 ( V_29 , L_101 ) ;
break;
case V_289 :
F_22 ( V_29 , L_102 ) ;
V_83 -> V_86 |= V_89 ;
V_59 = - V_326 ;
break;
case V_169 :
F_48 ( V_29 , L_103 ) ;
V_59 = - V_327 ;
break;
case V_274 :
case V_272 :
F_22 ( V_29 , L_104 ) ;
V_59 = - V_315 ;
break;
case V_273 :
F_22 ( V_29 , L_105 ) ;
V_59 = - V_313 ;
break;
case V_328 :
F_48 ( V_29 , L_106 ) ;
V_59 = - V_329 ;
break;
case V_310 :
F_48 ( V_29 , L_107 ) ;
break;
case V_312 :
F_48 ( V_29 , L_108 ) ;
break;
case V_330 :
F_22 ( V_29 , L_109 ) ;
if ( ! F_46 ( & V_101 -> V_91 ) )
F_22 ( V_29 , L_110
L_111 ,
F_117 ( F_9 ( V_147 -> V_69 ) ) ,
V_79 ) ;
goto V_166;
case V_331 :
F_22 ( V_29 , L_112 ) ;
if ( ! F_46 ( & V_101 -> V_91 ) )
F_22 ( V_29 , L_113
L_111 ,
F_117 ( F_9 ( V_147 -> V_69 ) ) ,
V_79 ) ;
goto V_166;
case V_314 :
F_48 ( V_29 , L_114 ) ;
V_59 = - V_315 ;
break;
case V_332 :
V_83 -> V_282 = true ;
F_22 ( V_29 , L_115 ) ;
goto V_166;
case V_333 :
V_83 -> V_282 = true ;
F_22 ( V_29 , L_116 ) ;
goto V_166;
default:
if ( F_150 ( V_29 , V_271 ) ) {
V_59 = 0 ;
break;
}
F_48 ( V_29 , L_117 ,
V_271 ) ;
goto V_166;
}
do {
if ( F_46 ( & V_101 -> V_91 ) ) {
if ( ! ( V_271 == V_61 ||
V_271 == V_287 ) ) {
F_48 ( V_29 , L_118 ,
F_117 ( F_9 ( V_147 -> V_69 ) ) ,
V_79 ) ;
F_22 ( V_29 , L_119 ,
( F_9 ( V_147 -> V_69 ) &
V_334 ) >> 10 ) ;
F_169 ( V_29 , (union V_3 * ) V_147 ) ;
}
if ( V_83 -> V_282 ) {
V_83 -> V_282 = false ;
F_22 ( V_29 , L_120
L_121 ) ;
}
goto V_166;
}
if ( V_83 -> V_282 && V_322 == 0 ) {
V_83 -> V_282 = false ;
F_22 ( V_29 , L_122
L_123 ) ;
goto V_166;
}
V_19 = F_79 ( & V_101 -> V_91 , struct V_18 ,
V_91 ) ;
if ( V_83 -> V_282 )
V_322 -- ;
V_319 = F_145 ( V_29 , V_101 -> V_32 , V_101 -> V_33 ,
V_19 -> V_118 , V_318 , false ) ;
if ( ! V_319 && ( V_271 == V_61 ||
V_271 == V_287 ) ) {
goto V_166;
}
if ( ! V_319 ) {
if ( ! V_83 -> V_282 ||
! F_152 ( & V_19 -> V_21 -> V_83 -> V_280 ) ) {
if ( ( V_29 -> V_41 & V_335 ) &&
V_101 -> V_336 ) {
V_101 -> V_336 = false ;
goto V_166;
}
F_36 ( V_29 ,
L_124
L_125
L_126 , V_79 ,
V_271 ) ;
F_145 ( V_29 , V_101 -> V_32 ,
V_101 -> V_33 , V_19 -> V_118 ,
V_318 , true ) ;
return - V_76 ;
}
F_161 ( V_29 , V_19 , V_147 , V_83 , & V_59 ) ;
goto V_166;
}
if ( V_271 == V_296 )
V_101 -> V_336 = true ;
else
V_101 -> V_336 = false ;
if ( V_83 -> V_282 ) {
F_22 ( V_29 , L_127 ) ;
V_83 -> V_282 = false ;
}
V_269 = & V_319 -> V_6 [ ( V_318 - V_319 -> V_8 ) /
sizeof( * V_269 ) ] ;
F_170 ( V_101 ,
(struct V_337 * ) V_269 ) ;
if ( F_2 ( V_269 ) ) {
F_22 ( V_29 , L_128 ) ;
goto V_166;
}
if ( F_171 ( & V_19 -> V_21 -> V_83 -> V_280 ) )
F_158 ( V_29 , V_19 , V_269 , V_147 , V_83 , & V_59 ) ;
else if ( F_152 ( & V_19 -> V_21 -> V_83 -> V_280 ) )
F_160 ( V_29 , V_19 , V_269 , V_147 , V_83 , & V_59 ) ;
else
F_162 ( V_29 , V_19 , V_269 , V_147 , V_83 ,
& V_59 ) ;
V_166:
V_323 = V_83 -> V_282 &&
V_271 != V_332 &&
V_271 != V_333 ;
if ( ! V_323 )
F_16 ( V_29 , V_29 -> V_239 ) ;
} while ( V_323 );
return 0 ;
}
static int F_172 ( struct V_28 * V_29 )
{
union V_3 * V_147 ;
int V_338 = 1 ;
int V_71 ;
if ( ! V_29 -> V_239 || ! V_29 -> V_239 -> V_33 ) {
F_36 ( V_29 , L_129 ) ;
return - V_339 ;
}
V_147 = V_29 -> V_239 -> V_33 ;
if ( ( F_9 ( V_147 -> V_218 . V_69 ) & V_27 ) !=
V_29 -> V_239 -> V_34 )
return 0 ;
F_173 ( V_29 -> V_239 , & V_147 -> V_9 ) ;
F_174 () ;
switch ( F_9 ( V_147 -> V_218 . V_69 ) & V_334 ) {
case F_14 ( V_340 ) :
F_116 ( V_29 , & V_147 -> V_218 ) ;
break;
case F_14 ( V_341 ) :
F_130 ( V_29 , V_147 ) ;
V_338 = 0 ;
break;
case F_14 ( V_342 ) :
V_71 = F_163 ( V_29 , & V_147 -> V_343 ) ;
if ( V_71 >= 0 )
V_338 = 0 ;
break;
case F_14 ( V_344 ) :
F_128 ( V_29 , V_147 ) ;
break;
default:
if ( ( F_9 ( V_147 -> V_218 . V_69 ) & V_334 ) >=
F_14 ( 48 ) )
F_126 ( V_29 , V_147 ) ;
else
F_48 ( V_29 , L_130 ,
F_122 (
F_9 ( V_147 -> V_218 . V_69 ) ) ) ;
}
if ( V_29 -> V_65 & V_66 ) {
F_22 ( V_29 , L_131
L_132 ) ;
return 0 ;
}
if ( V_338 )
F_16 ( V_29 , V_29 -> V_239 ) ;
return 1 ;
}
T_7 F_175 ( struct V_126 * V_127 )
{
struct V_28 * V_29 = F_176 ( V_127 ) ;
union V_3 * V_345 ;
T_7 V_71 = V_346 ;
T_1 V_116 ;
T_3 V_70 ;
T_2 V_59 ;
F_66 ( & V_29 -> V_77 ) ;
V_59 = F_24 ( & V_29 -> V_73 -> V_59 ) ;
if ( V_59 == 0xffffffff ) {
V_71 = V_347 ;
goto V_348;
}
if ( ! ( V_59 & V_349 ) )
goto V_348;
if ( V_59 & V_350 ) {
F_48 ( V_29 , L_133 ) ;
F_37 ( V_29 ) ;
V_71 = V_347 ;
goto V_348;
}
V_59 |= V_349 ;
F_23 ( V_59 , & V_29 -> V_73 -> V_59 ) ;
if ( V_127 -> V_351 ) {
T_2 V_352 ;
V_352 = F_24 ( & V_29 -> V_353 -> V_352 ) ;
V_352 |= V_354 ;
F_23 ( V_352 , & V_29 -> V_353 -> V_352 ) ;
}
if ( V_29 -> V_65 & V_66 ||
V_29 -> V_65 & V_355 ) {
F_22 ( V_29 , L_134
L_135 ) ;
V_70 = F_33 ( V_29 , & V_29 -> V_353 -> V_356 ) ;
F_34 ( V_29 , V_70 | V_357 ,
& V_29 -> V_353 -> V_356 ) ;
V_71 = V_347 ;
goto V_348;
}
V_345 = V_29 -> V_239 -> V_33 ;
while ( F_172 ( V_29 ) > 0 ) {}
V_70 = F_33 ( V_29 , & V_29 -> V_353 -> V_356 ) ;
if ( V_345 != V_29 -> V_239 -> V_33 ) {
V_116 = F_1 ( V_29 -> V_239 -> V_32 ,
V_29 -> V_239 -> V_33 ) ;
if ( V_116 == 0 )
F_48 ( V_29 , L_136
L_137 ) ;
V_70 &= V_358 ;
V_70 |= ( ( T_3 ) V_116 & ( T_3 ) ~ V_358 ) ;
}
V_70 |= V_357 ;
F_34 ( V_29 , V_70 , & V_29 -> V_353 -> V_356 ) ;
V_71 = V_347 ;
V_348:
F_63 ( & V_29 -> V_77 ) ;
return V_71 ;
}
T_7 F_177 ( int V_351 , void * V_127 )
{
return F_175 ( V_127 ) ;
}
static void F_178 ( struct V_28 * V_29 , struct V_13 * V_14 ,
bool V_36 ,
T_2 V_359 , T_2 V_360 , T_2 V_361 , T_2 V_362 )
{
struct V_337 * V_4 ;
V_4 = & V_14 -> V_38 -> V_9 ;
V_4 -> V_10 [ 0 ] = F_13 ( V_359 ) ;
V_4 -> V_10 [ 1 ] = F_13 ( V_360 ) ;
V_4 -> V_10 [ 2 ] = F_13 ( V_361 ) ;
V_4 -> V_10 [ 3 ] = F_13 ( V_362 ) ;
F_179 ( V_14 , V_4 ) ;
F_17 ( V_29 , V_14 , V_36 ) ;
}
static int F_180 ( struct V_28 * V_29 , struct V_13 * V_101 ,
T_2 V_86 , unsigned int V_44 , T_8 V_363 )
{
unsigned int V_364 ;
switch ( V_86 ) {
case V_325 :
F_48 ( V_29 , L_138 ) ;
return - V_365 ;
case V_366 :
F_48 ( V_29 , L_139 ) ;
return - V_367 ;
case V_275 :
F_22 ( V_29 , L_140 ) ;
case V_368 :
case V_369 :
break;
default:
F_36 ( V_29 , L_141 ) ;
return - V_367 ;
}
while ( 1 ) {
if ( F_20 ( V_29 , V_101 , V_44 ) )
break;
if ( V_101 == V_29 -> V_64 ) {
F_36 ( V_29 , L_142 ) ;
return - V_339 ;
}
F_50 ( V_29 , V_370 ,
L_143 ) ;
V_364 = V_44 - V_101 -> V_35 ;
if ( F_181 ( V_29 , V_101 , V_364 ,
V_363 ) ) {
F_36 ( V_29 , L_144 ) ;
return - V_339 ;
}
}
while ( F_4 ( V_101 -> V_38 ) ) {
if ( ! F_18 ( V_29 ) &&
! ( V_101 -> type == V_40 &&
( V_29 -> V_41 & V_42 ) ) )
V_101 -> V_38 -> V_11 . V_12 &=
F_13 ( ~ V_26 ) ;
else
V_101 -> V_38 -> V_11 . V_12 |=
F_13 ( V_26 ) ;
F_19 () ;
V_101 -> V_38 -> V_11 . V_12 ^= F_13 ( V_27 ) ;
if ( F_8 ( V_101 -> V_38 ) )
V_101 -> V_34 ^= 1 ;
V_101 -> V_43 = V_101 -> V_43 -> V_15 ;
V_101 -> V_38 = V_101 -> V_43 -> V_6 ;
}
return 0 ;
}
static int F_182 ( struct V_28 * V_29 ,
struct V_99 * V_283 ,
unsigned int V_79 ,
unsigned int V_80 ,
unsigned int V_44 ,
struct V_21 * V_21 ,
unsigned int V_371 ,
T_8 V_363 )
{
int V_71 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
struct V_13 * V_101 ;
struct V_113 * V_114 = F_52 ( V_29 , V_283 -> V_115 , V_79 ) ;
V_101 = F_90 ( V_283 , V_79 , V_80 ) ;
if ( ! V_101 ) {
F_22 ( V_29 , L_145 ,
V_80 ) ;
return - V_367 ;
}
V_71 = F_180 ( V_29 , V_101 , F_92 ( V_114 ) ,
V_44 , V_363 ) ;
if ( V_71 )
return V_71 ;
V_20 = V_21 -> V_22 ;
V_19 = & V_20 -> V_19 [ V_371 ] ;
F_183 ( & V_19 -> V_91 ) ;
F_183 ( & V_19 -> V_150 ) ;
if ( V_371 == 0 ) {
V_71 = F_184 ( F_57 ( V_21 -> V_100 -> V_128 ) , V_21 ) ;
if ( F_72 ( V_71 ) )
return V_71 ;
}
V_19 -> V_21 = V_21 ;
F_185 ( & V_19 -> V_91 , & V_101 -> V_91 ) ;
V_19 -> V_122 = V_101 -> V_43 ;
V_19 -> V_123 = V_101 -> V_38 ;
return 0 ;
}
static unsigned int F_186 ( T_3 V_104 , T_3 V_372 )
{
unsigned int V_44 ;
V_44 = F_187 ( V_372 + ( V_104 & ( V_373 - 1 ) ) ,
V_373 ) ;
if ( V_44 == 0 )
V_44 ++ ;
return V_44 ;
}
static inline unsigned int F_188 ( struct V_21 * V_21 )
{
return F_186 ( V_21 -> V_374 , V_21 -> V_277 ) ;
}
static unsigned int F_189 ( struct V_21 * V_21 )
{
struct V_375 * V_140 ;
unsigned int V_156 , V_372 , V_376 , V_44 = 0 ;
V_376 = V_21 -> V_277 ;
F_190 (urb->sg, sg, urb->num_mapped_sgs, i) {
V_372 = F_191 ( V_140 ) ;
V_44 += F_186 ( F_192 ( V_140 ) , V_372 ) ;
V_372 = F_193 (unsigned int, len, full_len) ;
V_376 -= V_372 ;
if ( V_376 == 0 )
break;
}
return V_44 ;
}
static unsigned int F_194 ( struct V_21 * V_21 , int V_156 )
{
T_3 V_104 , V_372 ;
V_104 = ( T_3 ) ( V_21 -> V_374 + V_21 -> V_306 [ V_156 ] . V_377 ) ;
V_372 = V_21 -> V_306 [ V_156 ] . V_307 ;
return F_186 ( V_104 , V_372 ) ;
}
static void F_195 ( struct V_21 * V_21 , int V_378 )
{
if ( F_72 ( V_378 != V_21 -> V_277 ) )
F_196 ( & V_21 -> V_100 -> V_100 , L_146
L_147 ,
V_259 ,
V_21 -> V_83 -> V_280 . V_317 ,
V_378 , V_378 ,
V_21 -> V_277 ,
V_21 -> V_277 ) ;
}
static void F_197 ( struct V_28 * V_29 , int V_78 ,
unsigned int V_79 , unsigned int V_80 , int V_379 ,
struct V_337 * V_261 )
{
F_19 () ;
if ( V_379 )
V_261 -> V_10 [ 3 ] |= F_13 ( V_379 ) ;
else
V_261 -> V_10 [ 3 ] &= F_13 ( ~ V_27 ) ;
F_43 ( V_29 , V_78 , V_79 , V_80 ) ;
}
static void F_198 ( struct V_28 * V_29 , struct V_21 * V_21 ,
struct V_113 * V_114 )
{
int V_380 ;
int V_381 ;
V_380 = F_199 ( F_9 ( V_114 -> V_382 ) ) ;
V_381 = V_21 -> V_383 ;
if ( V_21 -> V_100 -> V_224 == V_384 ||
V_21 -> V_100 -> V_224 == V_385 )
V_381 *= 8 ;
if ( V_380 != V_381 ) {
F_200 ( & V_21 -> V_100 -> V_100 ,
L_148 ,
V_381 , V_381 == 1 ? L_149 : L_150 ,
V_380 , V_380 == 1 ? L_149 : L_150 ) ;
V_21 -> V_383 = V_380 ;
if ( V_21 -> V_100 -> V_224 == V_384 ||
V_21 -> V_100 -> V_224 == V_385 )
V_21 -> V_383 /= 8 ;
}
}
int F_201 ( struct V_28 * V_29 , T_8 V_363 ,
struct V_21 * V_21 , int V_78 , unsigned int V_79 )
{
struct V_113 * V_114 ;
V_114 = F_52 ( V_29 , V_29 -> V_84 [ V_78 ] -> V_115 , V_79 ) ;
F_198 ( V_29 , V_21 , V_114 ) ;
return F_202 ( V_29 , V_363 , V_21 , V_78 , V_79 ) ;
}
static T_2 F_203 ( struct V_28 * V_29 , int V_386 ,
int V_387 , unsigned int V_388 ,
struct V_21 * V_21 , bool V_36 )
{
T_2 V_389 , V_390 ;
if ( V_29 -> V_391 < 0x100 && ! ( V_29 -> V_41 & V_392 ) )
return ( ( V_388 - V_386 ) >> 10 ) ;
if ( ! V_36 || ( V_386 == 0 && V_387 == 0 ) ||
V_387 == V_388 )
return 0 ;
if ( V_29 -> V_41 & V_392 )
V_387 = 0 ;
V_389 = F_204 ( & V_21 -> V_83 -> V_280 ) ;
V_390 = F_187 ( V_388 , V_389 ) ;
return ( V_390 - ( ( V_386 + V_387 ) / V_389 ) ) ;
}
static int F_205 ( struct V_28 * V_29 , struct V_21 * V_21 , T_2 V_393 ,
T_2 * V_387 , struct V_1 * V_2 )
{
struct V_134 * V_100 = F_59 ( V_29 ) -> V_131 . V_135 ;
unsigned int V_394 ;
unsigned int V_395 ;
T_2 V_396 ;
V_395 = F_204 ( & V_21 -> V_83 -> V_280 ) ;
V_394 = ( V_393 + * V_387 ) % V_395 ;
if ( V_394 == 0 )
return 0 ;
F_22 ( V_29 , L_151 ,
V_394 , * V_387 ) ;
if ( * V_387 > V_394 ) {
* V_387 -= V_394 ;
F_22 ( V_29 , L_152 , * V_387 ) ;
return 0 ;
}
V_396 = V_395 - ( V_393 % V_395 ) ;
if ( V_396 > ( V_21 -> V_277 - V_393 ) )
V_396 = ( V_21 -> V_277 - V_393 ) ;
if ( F_68 ( V_21 ) ) {
F_206 ( V_21 -> V_140 , V_21 -> V_141 ,
V_2 -> V_142 , V_396 , V_393 ) ;
V_2 -> V_137 = F_207 ( V_100 , V_2 -> V_142 ,
V_395 , V_139 ) ;
} else {
V_2 -> V_137 = F_207 ( V_100 , V_2 -> V_142 ,
V_395 , V_145 ) ;
}
if ( F_208 ( V_100 , V_2 -> V_137 ) ) {
F_48 ( V_29 , L_153 ) ;
return 0 ;
}
* V_387 = V_396 ;
V_2 -> V_143 = V_396 ;
V_2 -> V_144 = V_393 ;
F_22 ( V_29 , L_154 , * V_387 ) ;
return 1 ;
}
int F_202 ( struct V_28 * V_29 , T_8 V_363 ,
struct V_21 * V_21 , int V_78 , unsigned int V_79 )
{
struct V_13 * V_14 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
struct V_337 * V_261 ;
struct V_375 * V_140 = NULL ;
bool V_36 = true ;
bool V_397 = false ;
bool V_123 = true ;
unsigned int V_44 ;
unsigned int V_379 , V_398 = 0 ;
unsigned int V_393 , V_399 , V_387 , V_376 ;
int V_400 , V_71 ;
T_2 V_10 , V_401 , V_402 ;
T_3 V_104 , V_403 ;
V_14 = F_76 ( V_29 , V_21 ) ;
if ( ! V_14 )
return - V_367 ;
V_376 = V_21 -> V_277 ;
if ( V_21 -> V_398 ) {
V_398 = V_21 -> V_141 ;
V_140 = V_21 -> V_140 ;
V_104 = ( T_3 ) F_192 ( V_140 ) ;
V_399 = F_191 ( V_140 ) ;
V_44 = F_189 ( V_21 ) ;
} else {
V_44 = F_188 ( V_21 ) ;
V_104 = ( T_3 ) V_21 -> V_374 ;
V_399 = V_376 ;
}
V_71 = F_182 ( V_29 , V_29 -> V_84 [ V_78 ] ,
V_79 , V_21 -> V_80 ,
V_44 , V_21 , 0 , V_363 ) ;
if ( F_72 ( V_71 < 0 ) )
return V_71 ;
V_20 = V_21 -> V_22 ;
if ( V_21 -> V_278 & V_404 && V_20 -> V_24 > 1 )
V_397 = true ;
V_19 = & V_20 -> V_19 [ 0 ] ;
V_261 = & V_14 -> V_38 -> V_9 ;
V_379 = V_14 -> V_34 ;
V_403 = V_104 ;
for ( V_393 = 0 ; V_123 || V_393 < V_376 ;
V_393 += V_387 ) {
V_10 = F_14 ( V_297 ) ;
V_387 = F_209 ( V_104 ) ;
V_387 = F_193 (unsigned int, trb_buff_len, block_len) ;
if ( V_393 + V_387 > V_376 )
V_387 = V_376 - V_393 ;
if ( V_123 ) {
V_123 = false ;
if ( V_379 == 0 )
V_10 |= V_27 ;
} else
V_10 |= V_14 -> V_34 ;
if ( V_393 + V_387 < V_376 ) {
V_10 |= V_26 ;
if ( F_4 ( V_14 -> V_38 + 1 ) ) {
if ( F_205 ( V_29 , V_21 , V_393 ,
& V_387 ,
V_14 -> V_43 ) ) {
V_403 = V_14 -> V_43 -> V_137 ;
V_19 -> V_136 = V_14 -> V_43 ;
}
}
}
if ( V_393 + V_387 >= V_376 ) {
V_10 &= ~ V_26 ;
V_10 |= V_405 ;
V_36 = false ;
V_19 -> V_118 = V_14 -> V_38 ;
}
if ( F_210 ( V_21 ) )
V_10 |= V_406 ;
V_402 = F_203 ( V_29 , V_393 , V_387 ,
V_376 , V_21 , V_36 ) ;
V_401 = F_157 ( V_387 ) |
F_211 ( V_402 ) |
F_212 ( 0 ) ;
F_178 ( V_29 , V_14 , V_36 | V_397 ,
F_164 ( V_403 ) ,
F_165 ( V_403 ) ,
V_401 ,
V_10 ) ;
V_104 += V_387 ;
V_400 = V_387 ;
while ( V_140 && V_400 >= V_399 ) {
-- V_398 ;
V_400 -= V_399 ;
if ( V_398 != 0 ) {
V_140 = F_213 ( V_140 ) ;
V_399 = F_191 ( V_140 ) ;
V_104 = ( T_3 ) F_192 ( V_140 ) ;
V_104 += V_400 ;
}
}
V_399 -= V_400 ;
V_403 = V_104 ;
}
if ( V_397 ) {
V_71 = F_182 ( V_29 , V_29 -> V_84 [ V_78 ] ,
V_79 , V_21 -> V_80 ,
1 , V_21 , 1 , V_363 ) ;
V_20 -> V_19 [ 1 ] . V_118 = V_14 -> V_38 ;
V_10 = F_14 ( V_297 ) | V_14 -> V_34 | V_405 ;
F_178 ( V_29 , V_14 , 0 , 0 , 0 , F_212 ( 0 ) , V_10 ) ;
}
F_195 ( V_21 , V_393 ) ;
F_197 ( V_29 , V_78 , V_79 , V_21 -> V_80 ,
V_379 , V_261 ) ;
return 0 ;
}
int F_214 ( struct V_28 * V_29 , T_8 V_363 ,
struct V_21 * V_21 , int V_78 , unsigned int V_79 )
{
struct V_13 * V_101 ;
int V_44 ;
int V_71 ;
struct V_407 * V_408 ;
struct V_337 * V_261 ;
int V_379 ;
T_2 V_10 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
V_101 = F_76 ( V_29 , V_21 ) ;
if ( ! V_101 )
return - V_367 ;
if ( ! V_21 -> V_409 )
return - V_367 ;
V_44 = 2 ;
if ( V_21 -> V_277 > 0 )
V_44 ++ ;
V_71 = F_182 ( V_29 , V_29 -> V_84 [ V_78 ] ,
V_79 , V_21 -> V_80 ,
V_44 , V_21 , 0 , V_363 ) ;
if ( V_71 < 0 )
return V_71 ;
V_20 = V_21 -> V_22 ;
V_19 = & V_20 -> V_19 [ 0 ] ;
V_261 = & V_101 -> V_38 -> V_9 ;
V_379 = V_101 -> V_34 ;
V_408 = (struct V_407 * ) V_21 -> V_409 ;
V_10 = 0 ;
V_10 |= V_410 | F_14 ( V_298 ) ;
if ( V_379 == 0 )
V_10 |= 0x1 ;
if ( ( V_29 -> V_391 >= 0x100 ) || ( V_29 -> V_41 & V_392 ) ) {
if ( V_21 -> V_277 > 0 ) {
if ( V_408 -> V_411 & V_412 )
V_10 |= F_215 ( V_413 ) ;
else
V_10 |= F_215 ( V_414 ) ;
}
}
F_178 ( V_29 , V_101 , true ,
V_408 -> V_411 | V_408 -> V_415 << 8 | F_216 ( V_408 -> V_416 ) << 16 ,
F_216 ( V_408 -> V_417 ) | F_216 ( V_408 -> V_418 ) << 16 ,
F_157 ( 8 ) | F_212 ( 0 ) ,
V_10 ) ;
if ( F_210 ( V_21 ) )
V_10 = V_406 | F_14 ( V_295 ) ;
else
V_10 = F_14 ( V_295 ) ;
if ( V_21 -> V_277 > 0 ) {
T_2 V_401 , V_402 ;
V_402 = F_203 ( V_29 , 0 ,
V_21 -> V_277 ,
V_21 -> V_277 ,
V_21 , 1 ) ;
V_401 = F_157 ( V_21 -> V_277 ) |
F_211 ( V_402 ) |
F_212 ( 0 ) ;
if ( V_408 -> V_411 & V_412 )
V_10 |= V_419 ;
F_178 ( V_29 , V_101 , true ,
F_164 ( V_21 -> V_374 ) ,
F_165 ( V_21 -> V_374 ) ,
V_401 ,
V_10 | V_101 -> V_34 ) ;
}
V_19 -> V_118 = V_101 -> V_38 ;
if ( V_21 -> V_277 > 0 && V_408 -> V_411 & V_412 )
V_10 = 0 ;
else
V_10 = V_419 ;
F_178 ( V_29 , V_101 , false ,
0 ,
0 ,
F_212 ( 0 ) ,
V_10 | V_405 | F_14 ( V_294 ) | V_101 -> V_34 ) ;
F_197 ( V_29 , V_78 , V_79 , 0 ,
V_379 , V_261 ) ;
return 0 ;
}
static unsigned int F_217 ( struct V_28 * V_29 ,
struct V_21 * V_21 , unsigned int V_390 )
{
unsigned int V_420 ;
if ( V_29 -> V_391 < 0x100 || V_21 -> V_100 -> V_224 < V_421 )
return 0 ;
V_420 = V_21 -> V_83 -> V_422 . V_423 ;
return F_187 ( V_390 , V_420 + 1 ) - 1 ;
}
static unsigned int F_218 ( struct V_28 * V_29 ,
struct V_21 * V_21 , unsigned int V_390 )
{
unsigned int V_420 ;
unsigned int V_424 ;
if ( V_29 -> V_391 < 0x100 )
return 0 ;
if ( V_21 -> V_100 -> V_224 >= V_421 ) {
V_420 = V_21 -> V_83 -> V_422 . V_423 ;
V_424 = V_390 % ( V_420 + 1 ) ;
if ( V_424 == 0 )
return V_420 ;
return V_424 - 1 ;
}
if ( V_390 == 0 )
return 0 ;
return V_390 - 1 ;
}
static int F_219 ( struct V_28 * V_29 ,
struct V_21 * V_21 , int V_425 )
{
int V_426 , V_427 , V_71 = 0 ;
int V_428 , V_429 , V_430 ;
if ( V_21 -> V_100 -> V_224 == V_384 ||
V_21 -> V_100 -> V_224 == V_385 )
V_426 = V_21 -> V_426 + V_425 * V_21 -> V_383 ;
else
V_426 = ( V_21 -> V_426 + V_425 * V_21 -> V_383 ) >> 3 ;
V_427 = F_220 ( V_29 -> V_431 ) & 0x7 ;
if ( F_220 ( V_29 -> V_431 ) & ( 1 << 3 ) )
V_427 <<= 3 ;
V_430 = F_24 ( & V_29 -> V_432 -> V_433 ) ;
V_428 = F_221 ( V_430 + V_427 + 1 , 8 ) ;
V_429 = F_222 ( V_430 + 895 * 8 , 8 ) ;
V_426 &= 0x7ff ;
V_428 = ( V_428 >> 3 ) & 0x7ff ;
V_429 = ( V_429 >> 3 ) & 0x7ff ;
F_22 ( V_29 , L_155 ,
V_259 , V_425 , F_24 ( & V_29 -> V_432 -> V_433 ) ,
V_428 , V_429 , V_426 ) ;
if ( V_428 < V_429 ) {
if ( V_426 > V_429 ||
V_426 < V_428 )
V_71 = - V_367 ;
} else if ( V_428 > V_429 ) {
if ( ( V_426 > V_429 &&
V_426 < V_428 ) )
V_71 = - V_367 ;
} else {
V_71 = - V_367 ;
}
if ( V_425 == 0 ) {
if ( V_71 == - V_367 || V_426 == V_428 ) {
V_426 = V_428 + 1 ;
if ( V_21 -> V_100 -> V_224 == V_384 ||
V_21 -> V_100 -> V_224 == V_385 )
V_21 -> V_426 = V_426 ;
else
V_21 -> V_426 = V_426 << 3 ;
V_71 = 0 ;
}
}
if ( V_71 ) {
F_48 ( V_29 , L_156 ,
V_426 , V_430 , V_425 ,
V_428 , V_429 ) ;
F_48 ( V_29 , L_157 ) ;
return V_71 ;
}
return V_426 ;
}
static int F_223 ( struct V_28 * V_29 , T_8 V_363 ,
struct V_21 * V_21 , int V_78 , unsigned int V_79 )
{
struct V_13 * V_101 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
int V_24 , V_434 ;
struct V_337 * V_261 ;
bool V_123 ;
int V_379 ;
T_2 V_10 , V_401 ;
int V_378 , V_387 , V_435 , V_436 , V_71 ;
T_3 V_437 , V_104 ;
int V_156 , V_157 ;
bool V_36 ;
struct V_82 * V_438 ;
int V_439 ;
V_438 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
V_101 = V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] . V_14 ;
V_24 = V_21 -> V_440 ;
if ( V_24 < 1 ) {
F_22 ( V_29 , L_158 ) ;
return - V_367 ;
}
V_437 = ( T_3 ) V_21 -> V_374 ;
V_261 = & V_101 -> V_38 -> V_9 ;
V_379 = V_101 -> V_34 ;
V_20 = V_21 -> V_22 ;
for ( V_156 = 0 ; V_156 < V_24 ; V_156 ++ ) {
unsigned int V_441 , V_395 ;
unsigned int V_442 , V_443 ;
T_2 V_444 ;
V_123 = true ;
V_378 = 0 ;
V_104 = V_437 + V_21 -> V_306 [ V_156 ] . V_377 ;
V_435 = V_21 -> V_306 [ V_156 ] . V_307 ;
V_436 = V_435 ;
V_395 = F_204 ( & V_21 -> V_83 -> V_280 ) ;
V_441 = F_187 ( V_435 , V_395 ) ;
if ( V_441 == 0 )
V_441 ++ ;
V_442 = F_217 ( V_29 , V_21 , V_441 ) ;
V_443 = F_218 ( V_29 ,
V_21 , V_441 ) ;
V_434 = F_194 ( V_21 , V_156 ) ;
V_71 = F_182 ( V_29 , V_29 -> V_84 [ V_78 ] , V_79 ,
V_21 -> V_80 , V_434 , V_21 , V_156 , V_363 ) ;
if ( V_71 < 0 ) {
if ( V_156 == 0 )
return V_71 ;
goto V_166;
}
V_19 = & V_20 -> V_19 [ V_156 ] ;
V_444 = V_445 ;
if ( ! ( V_21 -> V_278 & V_446 ) &&
F_224 ( V_29 -> V_447 ) ) {
V_439 = F_219 ( V_29 , V_21 , V_156 ) ;
if ( V_439 >= 0 )
V_444 = F_225 ( V_439 ) ;
}
V_10 = F_14 ( V_448 ) |
F_226 ( V_443 ) |
V_444 |
( V_156 ? V_101 -> V_34 : ! V_379 ) ;
if ( ! V_438 -> V_449 )
V_10 |= F_227 ( V_442 ) ;
for ( V_157 = 0 ; V_157 < V_434 ; V_157 ++ ) {
T_2 V_402 = 0 ;
if ( ! V_123 )
V_10 = F_14 ( V_297 ) |
V_101 -> V_34 ;
if ( F_210 ( V_21 ) )
V_10 |= V_406 ;
if ( V_157 < V_434 - 1 ) {
V_36 = true ;
V_10 |= V_26 ;
} else {
V_36 = false ;
V_19 -> V_118 = V_101 -> V_38 ;
V_10 |= V_405 ;
if ( V_29 -> V_391 >= 0x100 &&
! ( V_29 -> V_41 & V_450 ) &&
V_156 < V_24 - 1 )
V_10 |= V_451 ;
}
V_387 = F_209 ( V_104 ) ;
if ( V_387 > V_436 )
V_387 = V_436 ;
V_402 = F_203 ( V_29 , V_378 ,
V_387 , V_435 ,
V_21 , V_36 ) ;
V_401 = F_157 ( V_387 ) |
F_212 ( 0 ) ;
if ( V_123 && V_438 -> V_449 )
V_401 |= F_228 ( V_442 ) ;
else
V_401 |= F_211 ( V_402 ) ;
V_123 = false ;
F_178 ( V_29 , V_101 , V_36 ,
F_164 ( V_104 ) ,
F_165 ( V_104 ) ,
V_401 ,
V_10 ) ;
V_378 += V_387 ;
V_104 += V_387 ;
V_436 -= V_387 ;
}
if ( V_378 != V_435 ) {
F_36 ( V_29 , L_159 ) ;
V_71 = - V_367 ;
goto V_166;
}
}
if ( F_224 ( V_29 -> V_447 ) )
V_438 -> V_452 = V_21 -> V_426 + V_24 * V_21 -> V_383 ;
if ( F_59 ( V_29 ) -> V_131 . V_132 == 0 ) {
if ( V_29 -> V_41 & V_133 )
F_229 () ;
}
F_59 ( V_29 ) -> V_131 . V_132 ++ ;
F_197 ( V_29 , V_78 , V_79 , V_21 -> V_80 ,
V_379 , V_261 ) ;
return 0 ;
V_166:
for ( V_156 -- ; V_156 >= 0 ; V_156 -- )
F_77 ( & V_20 -> V_19 [ V_156 ] . V_91 ) ;
V_20 -> V_19 [ 0 ] . V_118 = V_101 -> V_38 ;
F_53 ( V_29 , V_101 , & V_20 -> V_19 [ 0 ] , true ) ;
V_101 -> V_38 = V_20 -> V_19 [ 0 ] . V_123 ;
V_101 -> V_43 = V_20 -> V_19 [ 0 ] . V_122 ;
V_101 -> V_34 = V_379 ;
V_101 -> V_35 = V_101 -> V_160 ;
F_62 ( F_57 ( V_21 -> V_100 -> V_128 ) , V_21 ) ;
return V_71 ;
}
int F_230 ( struct V_28 * V_29 , T_8 V_363 ,
struct V_21 * V_21 , int V_78 , unsigned int V_79 )
{
struct V_99 * V_283 ;
struct V_13 * V_101 ;
struct V_113 * V_114 ;
int V_426 ;
int V_24 , V_44 , V_156 ;
int V_71 ;
struct V_82 * V_438 ;
int V_427 ;
V_283 = V_29 -> V_84 [ V_78 ] ;
V_438 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
V_101 = V_283 -> V_85 [ V_79 ] . V_14 ;
V_114 = F_52 ( V_29 , V_283 -> V_115 , V_79 ) ;
V_44 = 0 ;
V_24 = V_21 -> V_440 ;
for ( V_156 = 0 ; V_156 < V_24 ; V_156 ++ )
V_44 += F_194 ( V_21 , V_156 ) ;
V_71 = F_180 ( V_29 , V_101 , F_92 ( V_114 ) ,
V_44 , V_363 ) ;
if ( V_71 )
return V_71 ;
F_198 ( V_29 , V_21 , V_114 ) ;
if ( F_224 ( V_29 -> V_447 ) && ! F_46 ( & V_101 -> V_91 ) ) {
if ( F_92 ( V_114 ) == V_369 ) {
V_21 -> V_426 = V_438 -> V_452 ;
goto V_453;
}
}
V_426 = F_24 ( & V_29 -> V_432 -> V_433 ) ;
V_426 &= 0x3fff ;
V_427 = F_220 ( V_29 -> V_431 ) & 0x7 ;
if ( F_220 ( V_29 -> V_431 ) & ( 1 << 3 ) )
V_427 <<= 3 ;
V_426 += V_427 + V_454 ;
V_426 = F_221 ( V_426 , 8 ) ;
if ( V_21 -> V_100 -> V_224 == V_384 ||
V_21 -> V_100 -> V_224 == V_385 ) {
V_426 = F_221 ( V_426 , V_21 -> V_383 << 3 ) ;
V_21 -> V_426 = V_426 >> 3 ;
} else {
V_426 = F_221 ( V_426 , V_21 -> V_383 ) ;
V_21 -> V_426 = V_426 ;
}
V_453:
V_101 -> V_160 = V_101 -> V_35 ;
return F_223 ( V_29 , V_363 , V_21 , V_78 , V_79 ) ;
}
static int F_231 ( struct V_28 * V_29 , struct V_55 * V_190 ,
T_2 V_359 , T_2 V_360 ,
T_2 V_361 , T_2 V_362 , bool V_455 )
{
int V_456 = V_29 -> V_457 ;
int V_71 ;
if ( ( V_29 -> V_65 & V_66 ) ||
( V_29 -> V_65 & V_355 ) ) {
F_22 ( V_29 , L_160 ) ;
return - V_76 ;
}
if ( ! V_455 )
V_456 ++ ;
V_71 = F_180 ( V_29 , V_29 -> V_64 , V_369 ,
V_456 , V_179 ) ;
if ( V_71 < 0 ) {
F_36 ( V_29 , L_161 ) ;
if ( V_455 )
F_36 ( V_29 , L_162
L_163 ) ;
return V_71 ;
}
V_190 -> V_62 = V_29 -> V_64 -> V_38 ;
if ( F_46 ( & V_29 -> V_56 ) ) {
V_29 -> V_67 = V_190 ;
F_25 ( V_29 , V_68 ) ;
}
F_185 ( & V_190 -> V_56 , & V_29 -> V_56 ) ;
F_178 ( V_29 , V_29 -> V_64 , false , V_359 , V_360 , V_361 ,
V_362 | V_29 -> V_64 -> V_34 ) ;
return 0 ;
}
int F_232 ( struct V_28 * V_29 , struct V_55 * V_190 ,
T_2 V_216 , T_2 V_78 )
{
return F_231 ( V_29 , V_190 , 0 , 0 , 0 ,
F_14 ( V_216 ) | F_233 ( V_78 ) , false ) ;
}
int F_234 ( struct V_28 * V_29 , struct V_55 * V_190 ,
T_1 V_458 , T_2 V_78 , enum V_459 V_408 )
{
return F_231 ( V_29 , V_190 , F_164 ( V_458 ) ,
F_165 ( V_458 ) , 0 ,
F_14 ( V_210 ) | F_233 ( V_78 )
| ( V_408 == V_460 ? V_461 : 0 ) , false ) ;
}
int F_235 ( struct V_28 * V_29 , struct V_55 * V_190 ,
T_2 V_359 , T_2 V_360 , T_2 V_361 , T_2 V_362 )
{
return F_231 ( V_29 , V_190 , V_359 , V_360 , V_361 , V_362 , false ) ;
}
int F_236 ( struct V_28 * V_29 , struct V_55 * V_190 ,
T_2 V_78 )
{
return F_231 ( V_29 , V_190 , 0 , 0 , 0 ,
F_14 ( V_214 ) | F_233 ( V_78 ) ,
false ) ;
}
int F_96 ( struct V_28 * V_29 ,
struct V_55 * V_190 , T_1 V_458 ,
T_2 V_78 , bool V_455 )
{
return F_231 ( V_29 , V_190 , F_164 ( V_458 ) ,
F_165 ( V_458 ) , 0 ,
F_14 ( V_208 ) | F_233 ( V_78 ) ,
V_455 ) ;
}
int F_237 ( struct V_28 * V_29 , struct V_55 * V_190 ,
T_1 V_458 , T_2 V_78 , bool V_455 )
{
return F_231 ( V_29 , V_190 , F_164 ( V_458 ) ,
F_165 ( V_458 ) , 0 ,
F_14 ( V_209 ) | F_233 ( V_78 ) ,
V_455 ) ;
}
int F_238 ( struct V_28 * V_29 , struct V_55 * V_190 ,
int V_78 , unsigned int V_79 , int V_462 )
{
T_2 V_463 = F_233 ( V_78 ) ;
T_2 V_464 = F_239 ( V_79 ) ;
T_2 type = F_14 ( V_211 ) ;
T_2 V_465 = F_240 ( V_462 ) ;
return F_231 ( V_29 , V_190 , 0 , 0 , 0 ,
V_463 | V_464 | type | V_465 , false ) ;
}
void F_78 ( struct V_28 * V_29 ,
unsigned int V_78 , unsigned int V_79 ,
unsigned int V_80 ,
struct V_97 * V_149 )
{
T_1 V_104 ;
T_2 V_463 = F_233 ( V_78 ) ;
T_2 V_464 = F_239 ( V_79 ) ;
T_2 V_466 = F_241 ( V_80 ) ;
T_2 V_467 = 0 ;
T_2 type = F_14 ( V_212 ) ;
struct V_82 * V_83 ;
struct V_55 * V_190 ;
int V_71 ;
F_50 ( V_29 , V_108 ,
L_164 ,
V_149 -> V_119 ,
( unsigned long long ) V_149 -> V_119 -> V_8 ,
V_149 -> V_120 ,
( unsigned long long ) F_1 (
V_149 -> V_119 , V_149 -> V_120 ) ,
V_149 -> V_117 ) ;
V_104 = F_1 ( V_149 -> V_119 ,
V_149 -> V_120 ) ;
if ( V_104 == 0 ) {
F_48 ( V_29 , L_165 ) ;
F_48 ( V_29 , L_166 ,
V_149 -> V_119 , V_149 -> V_120 ) ;
return;
}
V_83 = & V_29 -> V_84 [ V_78 ] -> V_85 [ V_79 ] ;
if ( ( V_83 -> V_86 & V_88 ) ) {
F_48 ( V_29 , L_165 ) ;
F_48 ( V_29 , L_167 ) ;
return;
}
V_190 = F_95 ( V_29 , false , false , V_179 ) ;
if ( ! V_190 ) {
F_48 ( V_29 , L_168 ) ;
return;
}
V_83 -> V_175 = V_149 -> V_119 ;
V_83 -> V_162 = V_149 -> V_120 ;
if ( V_80 )
V_467 = F_242 ( V_468 ) ;
V_71 = F_231 ( V_29 , V_190 ,
F_164 ( V_104 ) | V_467 | V_149 -> V_117 ,
F_165 ( V_104 ) , V_466 ,
V_463 | V_464 | type , false ) ;
if ( V_71 < 0 ) {
F_243 ( V_29 , V_190 ) ;
return;
}
V_83 -> V_86 |= V_88 ;
}
int F_147 ( struct V_28 * V_29 , struct V_55 * V_190 ,
int V_78 , unsigned int V_79 )
{
T_2 V_463 = F_233 ( V_78 ) ;
T_2 V_464 = F_239 ( V_79 ) ;
T_2 type = F_14 ( V_213 ) ;
return F_231 ( V_29 , V_190 , 0 , 0 , 0 ,
V_463 | V_464 | type , false ) ;
}
