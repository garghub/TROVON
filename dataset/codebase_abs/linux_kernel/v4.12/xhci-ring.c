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
if ( V_14 -> type == V_30 ) {
if ( ! F_6 ( V_14 -> V_31 , V_14 -> V_32 ) ) {
V_14 -> V_32 ++ ;
return;
}
if ( F_7 ( V_14 , V_14 -> V_31 , V_14 -> V_32 ) )
V_14 -> V_33 ^= 1 ;
V_14 -> V_31 = V_14 -> V_31 -> V_15 ;
V_14 -> V_32 = V_14 -> V_31 -> V_6 ;
return;
}
if ( ! F_4 ( V_14 -> V_32 ) ) {
V_14 -> V_32 ++ ;
V_14 -> V_34 ++ ;
}
while ( F_4 ( V_14 -> V_32 ) ) {
V_14 -> V_31 = V_14 -> V_31 -> V_15 ;
V_14 -> V_32 = V_14 -> V_31 -> V_6 ;
}
F_17 ( V_14 ) ;
return;
}
static void F_18 ( struct V_28 * V_29 , struct V_13 * V_14 ,
bool V_35 )
{
T_2 V_36 ;
union V_3 * V_15 ;
V_36 = F_9 ( V_14 -> V_37 -> V_9 . V_10 [ 3 ] ) & V_26 ;
if ( ! F_4 ( V_14 -> V_37 ) )
V_14 -> V_34 -- ;
V_15 = ++ ( V_14 -> V_37 ) ;
while ( F_4 ( V_15 ) ) {
if ( ! V_36 && ! V_35 )
break;
if ( ! ( V_14 -> type == V_38 &&
( V_29 -> V_39 & V_40 ) ) &&
! F_19 ( V_29 ) ) {
V_15 -> V_11 . V_12 &= F_13 ( ~ V_26 ) ;
V_15 -> V_11 . V_12 |= F_13 ( V_36 ) ;
}
F_20 () ;
V_15 -> V_11 . V_12 ^= F_13 ( V_27 ) ;
if ( F_8 ( V_15 ) )
V_14 -> V_33 ^= 1 ;
V_14 -> V_41 = V_14 -> V_41 -> V_15 ;
V_14 -> V_37 = V_14 -> V_41 -> V_6 ;
V_15 = V_14 -> V_37 ;
}
F_21 ( V_14 ) ;
}
static inline int F_22 ( struct V_28 * V_29 , struct V_13 * V_14 ,
unsigned int V_42 )
{
int V_43 ;
if ( V_14 -> V_34 < V_42 )
return 0 ;
if ( V_14 -> type != V_44 && V_14 -> type != V_30 ) {
V_43 = V_14 -> V_32 - V_14 -> V_31 -> V_6 ;
if ( V_14 -> V_34 < V_42 + V_43 )
return 0 ;
}
return 1 ;
}
void F_23 ( struct V_28 * V_29 )
{
if ( ! ( V_29 -> V_45 & V_46 ) )
return;
F_24 ( V_29 , L_1 ) ;
F_25 ( V_47 , & V_29 -> V_48 -> V_49 [ 0 ] ) ;
F_26 ( & V_29 -> V_48 -> V_49 [ 0 ] ) ;
}
static bool F_27 ( struct V_28 * V_29 , unsigned long V_50 )
{
return F_28 ( V_51 , & V_29 -> V_52 , V_50 ) ;
}
static struct V_53 * F_29 ( struct V_28 * V_29 )
{
return F_30 ( & V_29 -> V_54 , struct V_53 ,
V_54 ) ;
}
static void F_31 ( struct V_28 * V_29 ,
struct V_53 * V_55 )
{
struct V_53 * V_56 ;
F_32 (i_cmd, &xhci->cmd_list, cmd_list) {
if ( V_56 -> V_57 != V_58 )
continue;
V_56 -> V_57 = V_59 ;
F_24 ( V_29 , L_2 ,
V_56 -> V_60 ) ;
F_12 ( V_56 -> V_60 , V_61 ) ;
}
V_29 -> V_45 = V_46 ;
if ( ( V_29 -> V_62 -> V_32 != V_29 -> V_62 -> V_37 ) &&
! ( V_29 -> V_63 & V_64 ) ) {
V_29 -> V_65 = V_55 ;
F_27 ( V_29 , V_66 ) ;
F_23 ( V_29 ) ;
}
}
static int F_33 ( struct V_28 * V_29 , unsigned long V_67 )
{
T_3 V_68 ;
int V_69 ;
F_24 ( V_29 , L_3 ) ;
F_34 ( & V_29 -> V_70 ) ;
V_68 = F_35 ( V_29 , & V_29 -> V_71 -> V_62 ) ;
F_36 ( V_29 , V_68 | V_72 ,
& V_29 -> V_71 -> V_62 ) ;
V_69 = F_37 ( & V_29 -> V_71 -> V_62 ,
V_73 , 0 , 5 * 1000 * 1000 ) ;
if ( V_69 < 0 ) {
F_38 ( V_29 , L_4 , V_69 ) ;
F_39 ( V_29 ) ;
F_40 ( V_29 ) ;
return V_69 ;
}
F_41 ( & V_29 -> V_74 , V_67 ) ;
V_69 = F_42 ( & V_29 -> V_70 ,
F_43 ( 2000 ) ) ;
F_44 ( & V_29 -> V_74 , V_67 ) ;
if ( ! V_69 ) {
F_24 ( V_29 , L_5 ) ;
F_45 ( V_29 ) ;
} else {
F_31 ( V_29 , F_29 ( V_29 ) ) ;
}
return 0 ;
}
void F_46 ( struct V_28 * V_29 ,
unsigned int V_75 ,
unsigned int V_76 ,
unsigned int V_77 )
{
T_4 T_5 * V_78 = & V_29 -> V_48 -> V_49 [ V_75 ] ;
struct V_79 * V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
unsigned int V_83 = V_80 -> V_83 ;
if ( ( V_83 & V_84 ) || ( V_83 & V_85 ) ||
( V_83 & V_86 ) )
return;
F_25 ( F_47 ( V_76 , V_77 ) , V_78 ) ;
}
static void F_48 ( struct V_28 * V_29 ,
unsigned int V_75 ,
unsigned int V_76 )
{
unsigned int V_77 ;
struct V_79 * V_80 ;
V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
if ( ! ( V_80 -> V_83 & V_87 ) ) {
if ( V_80 -> V_14 && ! ( F_49 ( & V_80 -> V_14 -> V_88 ) ) )
F_46 ( V_29 , V_75 , V_76 , 0 ) ;
return;
}
for ( V_77 = 1 ; V_77 < V_80 -> V_89 -> V_90 ;
V_77 ++ ) {
struct V_91 * V_89 = V_80 -> V_89 ;
if ( ! F_49 ( & V_89 -> V_92 [ V_77 ] -> V_88 ) )
F_46 ( V_29 , V_75 , V_76 ,
V_77 ) ;
}
}
struct V_13 * F_50 ( struct V_28 * V_29 ,
unsigned int V_75 , unsigned int V_76 ,
unsigned int V_77 )
{
struct V_79 * V_80 ;
V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
if ( ! ( V_80 -> V_83 & V_87 ) )
return V_80 -> V_14 ;
if ( V_77 == 0 ) {
F_51 ( V_29 ,
L_6
L_7 ,
V_75 , V_76 ) ;
return NULL ;
}
if ( V_77 < V_80 -> V_89 -> V_90 )
return V_80 -> V_89 -> V_92 [ V_77 ] ;
F_51 ( V_29 ,
L_8
L_9
L_10 ,
V_75 , V_76 ,
V_80 -> V_89 -> V_90 - 1 ,
V_77 ) ;
return NULL ;
}
void F_52 ( struct V_28 * V_29 ,
unsigned int V_75 , unsigned int V_76 ,
unsigned int V_77 , struct V_18 * V_93 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 = V_29 -> V_81 [ V_75 ] ;
struct V_79 * V_80 = & V_97 -> V_82 [ V_76 ] ;
struct V_13 * V_98 ;
struct V_1 * V_99 ;
union V_3 * V_100 ;
T_1 V_101 ;
T_3 V_102 ;
bool V_103 = false ;
bool V_104 = false ;
V_98 = F_50 ( V_29 , V_75 ,
V_76 , V_77 ) ;
if ( ! V_98 ) {
F_51 ( V_29 , L_11
L_12 ,
V_77 ) ;
return;
}
F_53 ( V_29 , V_105 ,
L_13 ) ;
if ( V_80 -> V_83 & V_87 ) {
struct V_106 * V_107 =
& V_80 -> V_89 -> V_108 [ V_77 ] ;
V_102 = F_54 ( V_107 -> V_109 ) ;
} else {
struct V_110 * V_111
= F_55 ( V_29 , V_97 -> V_112 , V_76 ) ;
V_102 = F_54 ( V_111 -> V_113 ) ;
}
V_99 = V_98 -> V_31 ;
V_100 = V_98 -> V_32 ;
V_95 -> V_114 = V_102 & 0x1 ;
do {
if ( ! V_103 && F_1 ( V_99 , V_100 )
== ( T_1 ) ( V_102 & ~ 0xf ) ) {
V_103 = true ;
if ( V_104 )
break;
}
if ( V_100 == V_93 -> V_115 )
V_104 = true ;
if ( V_103 && F_4 ( V_100 ) &&
F_8 ( V_100 ) )
V_95 -> V_114 ^= 0x1 ;
F_15 ( V_29 , V_98 , & V_99 , & V_100 ) ;
if ( V_100 == V_80 -> V_14 -> V_32 ) {
F_38 ( V_29 , L_14 ) ;
V_95 -> V_116 = NULL ;
V_95 -> V_117 = NULL ;
return;
}
} while ( ! V_103 || ! V_104 );
V_95 -> V_116 = V_99 ;
V_95 -> V_117 = V_100 ;
F_53 ( V_29 , V_105 ,
L_15 , V_95 -> V_114 ) ;
F_53 ( V_29 , V_105 ,
L_16 ,
V_95 -> V_116 ) ;
V_101 = F_1 ( V_95 -> V_116 , V_95 -> V_117 ) ;
F_53 ( V_29 , V_105 ,
L_17 ,
( unsigned long long ) V_101 ) ;
}
static void F_56 ( struct V_28 * V_29 , struct V_13 * V_98 ,
struct V_18 * V_19 , bool V_118 )
{
struct V_1 * V_2 = V_19 -> V_119 ;
union V_3 * V_4 = V_19 -> V_120 ;
while ( 1 ) {
F_12 ( V_4 , V_121 ) ;
if ( V_118 && V_4 != V_19 -> V_120 && V_4 != V_19 -> V_115 )
V_4 -> V_9 . V_10 [ 3 ] ^= F_13 ( V_27 ) ;
if ( V_4 == V_19 -> V_115 )
break;
F_15 ( V_29 , V_98 , & V_2 , & V_4 ) ;
}
}
static void F_57 ( struct V_28 * V_29 ,
struct V_79 * V_80 )
{
V_80 -> V_83 &= ~ V_84 ;
F_58 ( & V_80 -> V_122 ) ;
}
static void F_59 ( struct V_28 * V_29 ,
struct V_18 * V_93 , int V_57 )
{
struct V_21 * V_21 = V_93 -> V_21 ;
struct V_20 * V_20 = V_21 -> V_22 ;
struct V_123 * V_124 = F_60 ( V_21 -> V_97 -> V_125 ) ;
if ( F_61 ( V_21 -> V_126 ) == V_127 ) {
F_62 ( V_29 ) -> V_128 . V_129 -- ;
if ( F_62 ( V_29 ) -> V_128 . V_129 == 0 ) {
if ( V_29 -> V_39 & V_130 )
F_63 () ;
}
}
F_64 ( V_20 ) ;
F_65 ( V_124 , V_21 ) ;
F_66 ( & V_29 -> V_74 ) ;
F_67 ( V_21 ) ;
F_68 ( V_124 , V_21 , V_57 ) ;
F_69 ( & V_29 -> V_74 ) ;
}
static void F_70 ( struct V_28 * V_29 ,
struct V_13 * V_14 , struct V_18 * V_19 )
{
struct V_131 * V_97 = F_62 ( V_29 ) -> V_128 . V_132 ;
struct V_1 * V_2 = V_19 -> V_133 ;
struct V_21 * V_21 = V_19 -> V_21 ;
if ( ! V_14 || ! V_2 || ! V_21 )
return;
if ( F_71 ( V_21 ) ) {
F_72 ( V_97 , V_2 -> V_134 , V_14 -> V_135 ,
V_136 ) ;
return;
}
F_73 ( V_21 -> V_137 , V_21 -> V_138 , V_2 -> V_139 ,
V_2 -> V_140 , V_2 -> V_141 ) ;
F_72 ( V_97 , V_2 -> V_134 , V_14 -> V_135 ,
V_142 ) ;
V_2 -> V_140 = 0 ;
V_2 -> V_141 = 0 ;
}
static void F_74 ( struct V_28 * V_29 , int V_75 ,
union V_3 * V_4 , struct V_143 * V_144 )
{
unsigned int V_76 ;
struct V_13 * V_98 ;
struct V_79 * V_80 ;
struct V_18 * V_93 = NULL ;
struct V_18 * V_145 ;
struct V_110 * V_111 ;
struct V_96 * V_146 ;
struct V_94 V_147 ;
if ( F_75 ( F_76 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ) ) {
if ( ! V_29 -> V_81 [ V_75 ] )
F_51 ( V_29 , L_18
L_19 ,
V_75 ) ;
return;
}
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_76 = F_77 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_146 = V_29 -> V_81 [ V_75 ] ;
V_111 = F_55 ( V_29 , V_146 -> V_112 , V_76 ) ;
F_78 ( V_111 ) ;
V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
V_145 = F_79 ( & V_80 -> V_148 ,
struct V_18 , V_148 ) ;
if ( F_49 ( & V_80 -> V_148 ) ) {
F_57 ( V_29 , V_80 ) ;
V_80 -> V_149 = NULL ;
F_48 ( V_29 , V_75 , V_76 ) ;
return;
}
F_32 (cur_td, &ep->cancelled_td_list, cancelled_td_list) {
F_53 ( V_29 , V_105 ,
L_20 ,
( unsigned long long ) F_1 (
V_93 -> V_119 , V_93 -> V_120 ) ) ;
V_98 = F_80 ( V_29 , V_93 -> V_21 ) ;
if ( ! V_98 ) {
F_51 ( V_29 , L_21
L_22 ,
V_93 -> V_21 ,
V_93 -> V_21 -> V_77 ) ;
goto V_150;
}
if ( V_93 == V_80 -> V_149 )
F_52 ( V_29 , V_75 , V_76 ,
V_93 -> V_21 -> V_77 ,
V_93 , & V_147 ) ;
else
F_56 ( V_29 , V_98 , V_93 , false ) ;
V_150:
F_81 ( & V_93 -> V_88 ) ;
}
F_57 ( V_29 , V_80 ) ;
if ( V_147 . V_117 && V_147 . V_116 ) {
F_82 ( V_29 , V_75 , V_76 ,
V_80 -> V_149 -> V_21 -> V_77 , & V_147 ) ;
F_23 ( V_29 ) ;
} else {
F_48 ( V_29 , V_75 , V_76 ) ;
}
V_80 -> V_149 = NULL ;
do {
V_93 = F_83 ( & V_80 -> V_148 ,
struct V_18 , V_148 ) ;
F_81 ( & V_93 -> V_148 ) ;
V_98 = F_80 ( V_29 , V_93 -> V_21 ) ;
F_70 ( V_29 , V_98 , V_93 ) ;
F_11 ( V_93 -> V_21 ) ;
if ( F_10 ( V_93 ) )
F_59 ( V_29 , V_93 , 0 ) ;
if ( V_29 -> V_63 & V_64 )
return;
} while ( V_93 != V_145 );
}
static void F_84 ( struct V_28 * V_29 , struct V_13 * V_14 )
{
struct V_18 * V_93 ;
struct V_18 * V_151 ;
F_85 (cur_td, tmp, &ring->td_list, td_list) {
F_81 ( & V_93 -> V_88 ) ;
if ( ! F_49 ( & V_93 -> V_148 ) )
F_81 ( & V_93 -> V_148 ) ;
F_70 ( V_29 , V_14 , V_93 ) ;
F_11 ( V_93 -> V_21 ) ;
if ( F_10 ( V_93 ) )
F_59 ( V_29 , V_93 , - V_152 ) ;
}
}
static void F_86 ( struct V_28 * V_29 ,
int V_75 , int V_76 )
{
struct V_18 * V_93 ;
struct V_18 * V_151 ;
struct V_79 * V_80 ;
struct V_13 * V_14 ;
V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
if ( ( V_80 -> V_83 & V_87 ) ||
( V_80 -> V_83 & V_153 ) ) {
int V_77 ;
for ( V_77 = 0 ; V_77 < V_80 -> V_89 -> V_90 ;
V_77 ++ ) {
F_53 ( V_29 , V_105 ,
L_23 ,
V_75 , V_76 , V_77 + 1 ) ;
F_84 ( V_29 ,
V_80 -> V_89 -> V_92 [ V_77 ] ) ;
}
} else {
V_14 = V_80 -> V_14 ;
if ( ! V_14 )
return;
F_53 ( V_29 , V_105 ,
L_24 ,
V_75 , V_76 ) ;
F_84 ( V_29 , V_14 ) ;
}
F_85 (cur_td, tmp, &ep->cancelled_td_list,
cancelled_td_list) {
F_81 ( & V_93 -> V_148 ) ;
F_11 ( V_93 -> V_21 ) ;
if ( F_10 ( V_93 ) )
F_59 ( V_29 , V_93 , - V_152 ) ;
}
}
void F_40 ( struct V_28 * V_29 )
{
int V_154 , V_155 ;
if ( V_29 -> V_63 & V_64 )
return;
F_38 ( V_29 , L_25 ) ;
V_29 -> V_63 |= V_64 ;
F_45 ( V_29 ) ;
for ( V_154 = 0 ; V_154 <= F_87 ( V_29 -> V_156 ) ; V_154 ++ ) {
if ( ! V_29 -> V_81 [ V_154 ] )
continue;
for ( V_155 = 0 ; V_155 < 31 ; V_155 ++ )
F_86 ( V_29 , V_154 , V_155 ) ;
}
if ( ! ( V_29 -> V_63 & V_157 ) )
F_88 ( F_62 ( V_29 ) ) ;
}
void F_89 ( unsigned long V_158 )
{
struct V_28 * V_29 ;
struct V_79 * V_80 ;
unsigned long V_67 ;
V_80 = (struct V_79 * ) V_158 ;
V_29 = V_80 -> V_29 ;
F_44 ( & V_29 -> V_74 , V_67 ) ;
if ( ! ( V_80 -> V_83 & V_84 ) ||
F_90 ( & V_80 -> V_122 ) ) {
F_41 ( & V_29 -> V_74 , V_67 ) ;
F_24 ( V_29 , L_26 ) ;
return;
}
F_51 ( V_29 , L_27 ) ;
V_80 -> V_83 &= ~ V_84 ;
F_39 ( V_29 ) ;
F_40 ( V_29 ) ;
F_41 ( & V_29 -> V_74 , V_67 ) ;
F_53 ( V_29 , V_105 ,
L_28 ) ;
}
static void F_91 ( struct V_28 * V_29 ,
struct V_96 * V_97 ,
struct V_13 * V_98 ,
unsigned int V_76 )
{
union V_3 * V_159 ;
int V_160 ;
bool V_161 = false ;
V_160 = V_98 -> V_34 ;
V_159 = V_98 -> V_32 ;
if ( F_4 ( V_98 -> V_32 ) ) {
V_98 -> V_31 = V_98 -> V_31 -> V_15 ;
V_98 -> V_32 = V_98 -> V_31 -> V_6 ;
}
while ( V_98 -> V_32 != V_97 -> V_82 [ V_76 ] . V_162 ) {
V_98 -> V_34 ++ ;
V_98 -> V_32 ++ ;
if ( F_4 ( V_98 -> V_32 ) ) {
if ( V_98 -> V_32 ==
V_97 -> V_82 [ V_76 ] . V_162 )
break;
V_98 -> V_31 = V_98 -> V_31 -> V_15 ;
V_98 -> V_32 = V_98 -> V_31 -> V_6 ;
}
if ( V_98 -> V_32 == V_159 ) {
V_161 = true ;
break;
}
}
if ( V_161 ) {
F_24 ( V_29 , L_29 ) ;
V_98 -> V_34 = V_160 ;
}
}
static void F_92 ( struct V_28 * V_29 , int V_75 ,
union V_3 * V_4 , T_2 V_163 )
{
unsigned int V_76 ;
unsigned int V_77 ;
struct V_13 * V_98 ;
struct V_96 * V_97 ;
struct V_79 * V_80 ;
struct V_110 * V_111 ;
struct V_164 * V_165 ;
V_76 = F_77 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_77 = F_93 ( F_9 ( V_4 -> V_9 . V_10 [ 2 ] ) ) ;
V_97 = V_29 -> V_81 [ V_75 ] ;
V_80 = & V_97 -> V_82 [ V_76 ] ;
V_98 = F_94 ( V_97 , V_76 , V_77 ) ;
if ( ! V_98 ) {
F_51 ( V_29 , L_30 ,
V_77 ) ;
goto V_166;
}
V_111 = F_55 ( V_29 , V_97 -> V_112 , V_76 ) ;
V_165 = F_95 ( V_29 , V_97 -> V_112 ) ;
F_96 ( V_165 ) ;
F_97 ( V_111 ) ;
if ( V_163 != V_167 ) {
unsigned int V_83 ;
unsigned int V_168 ;
switch ( V_163 ) {
case V_169 :
F_51 ( V_29 , L_31 ) ;
break;
case V_170 :
F_51 ( V_29 , L_32 ) ;
V_83 = F_98 ( V_111 ) ;
V_168 = F_9 ( V_165 -> V_171 ) ;
V_168 = F_99 ( V_168 ) ;
F_53 ( V_29 , V_105 ,
L_33 ,
V_168 , V_83 ) ;
break;
case V_172 :
F_51 ( V_29 , L_34 ,
V_75 ) ;
break;
default:
F_51 ( V_29 , L_35 ,
V_163 ) ;
break;
}
} else {
T_3 V_113 ;
if ( V_80 -> V_83 & V_87 ) {
struct V_106 * V_107 =
& V_80 -> V_89 -> V_108 [ V_77 ] ;
V_113 = F_54 ( V_107 -> V_109 ) & V_173 ;
} else {
V_113 = F_54 ( V_111 -> V_113 ) & ~ V_174 ;
}
F_53 ( V_29 , V_105 ,
L_36 , V_113 ) ;
if ( F_1 ( V_80 -> V_175 ,
V_80 -> V_162 ) == V_113 ) {
F_91 ( V_29 , V_97 ,
V_98 , V_76 ) ;
} else {
F_51 ( V_29 , L_37 ) ;
F_51 ( V_29 , L_38 ,
V_80 -> V_175 , V_80 -> V_162 ) ;
}
}
V_166:
V_97 -> V_82 [ V_76 ] . V_83 &= ~ V_85 ;
V_97 -> V_82 [ V_76 ] . V_175 = NULL ;
V_97 -> V_82 [ V_76 ] . V_162 = NULL ;
F_48 ( V_29 , V_75 , V_76 ) ;
}
static void F_100 ( struct V_28 * V_29 , int V_75 ,
union V_3 * V_4 , T_2 V_163 )
{
struct V_96 * V_146 ;
struct V_110 * V_111 ;
unsigned int V_76 ;
V_76 = F_77 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_146 = V_29 -> V_81 [ V_75 ] ;
V_111 = F_55 ( V_29 , V_146 -> V_112 , V_76 ) ;
F_101 ( V_111 ) ;
F_53 ( V_29 , V_176 ,
L_39 , V_163 ) ;
if ( V_29 -> V_39 & V_177 ) {
struct V_53 * V_178 ;
V_178 = F_102 ( V_29 , false , false , V_179 ) ;
if ( ! V_178 )
return;
F_53 ( V_29 , V_180 ,
L_40 ) ;
F_103 ( V_29 , V_178 ,
V_29 -> V_81 [ V_75 ] -> V_181 -> V_8 , V_75 ,
false ) ;
F_23 ( V_29 ) ;
} else {
V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] . V_83 &= ~ V_86 ;
}
}
static void F_104 ( struct V_28 * V_29 , int V_75 ,
struct V_53 * V_178 , T_2 V_163 )
{
if ( V_163 == V_167 )
V_178 -> V_75 = V_75 ;
else
V_178 -> V_75 = 0 ;
}
static void F_105 ( struct V_28 * V_29 , int V_75 )
{
struct V_96 * V_182 ;
struct V_164 * V_165 ;
V_182 = V_29 -> V_81 [ V_75 ] ;
if ( ! V_182 )
return;
V_165 = F_95 ( V_29 , V_182 -> V_112 ) ;
F_106 ( V_165 ) ;
if ( V_29 -> V_39 & V_183 )
F_107 ( V_29 , V_182 , true ) ;
F_108 ( V_29 , V_75 ) ;
}
static void F_109 ( struct V_28 * V_29 , int V_75 ,
struct V_143 * V_144 , T_2 V_163 )
{
struct V_96 * V_182 ;
struct V_184 * V_185 ;
struct V_110 * V_111 ;
unsigned int V_76 ;
unsigned int V_83 ;
T_2 V_186 , V_187 ;
V_182 = V_29 -> V_81 [ V_75 ] ;
V_185 = F_110 ( V_182 -> V_181 ) ;
if ( ! V_185 ) {
F_51 ( V_29 , L_41 ) ;
return;
}
V_186 = F_9 ( V_185 -> V_186 ) ;
V_187 = F_9 ( V_185 -> V_187 ) ;
V_76 = F_111 ( V_186 ) - 1 ;
V_111 = F_55 ( V_29 , V_182 -> V_112 , V_76 ) ;
F_112 ( V_111 ) ;
if ( V_29 -> V_39 & V_177 &&
V_76 != ( unsigned int ) - 1 &&
V_186 - V_188 == V_187 ) {
V_83 = V_182 -> V_82 [ V_76 ] . V_83 ;
if ( ! ( V_83 & V_86 ) )
return;
F_53 ( V_29 , V_180 ,
L_42
L_43 ,
V_76 , V_83 ) ;
V_182 -> V_82 [ V_76 ] . V_83 &= ~ V_86 ;
F_48 ( V_29 , V_75 , V_76 ) ;
return;
}
return;
}
static void F_113 ( struct V_28 * V_29 , int V_75 )
{
struct V_96 * V_146 ;
struct V_164 * V_165 ;
V_146 = V_29 -> V_81 [ V_75 ] ;
V_165 = F_95 ( V_29 , V_146 -> V_112 ) ;
F_114 ( V_165 ) ;
}
static void F_115 ( struct V_28 * V_29 , int V_75 ,
struct V_143 * V_144 )
{
struct V_96 * V_146 ;
struct V_164 * V_165 ;
V_146 = V_29 -> V_81 [ V_75 ] ;
V_165 = F_95 ( V_29 , V_146 -> V_112 ) ;
F_116 ( V_165 ) ;
F_24 ( V_29 , L_44 ) ;
if ( ! V_29 -> V_81 [ V_75 ] )
F_51 ( V_29 , L_45
L_46 , V_75 ) ;
}
static void F_117 ( struct V_28 * V_29 ,
struct V_143 * V_144 )
{
if ( ! ( V_29 -> V_39 & V_189 ) ) {
F_51 ( V_29 , L_47 ) ;
return;
}
F_53 ( V_29 , V_180 ,
L_48 ,
F_118 ( F_9 ( V_144 -> V_57 ) ) ,
F_119 ( F_9 ( V_144 -> V_57 ) ) ) ;
}
static void F_120 ( struct V_53 * V_190 , T_2 V_57 )
{
F_121 ( & V_190 -> V_54 ) ;
if ( V_190 -> V_191 ) {
V_190 -> V_57 = V_57 ;
F_122 ( V_190 -> V_191 ) ;
} else {
F_123 ( V_190 ) ;
}
}
void F_45 ( struct V_28 * V_29 )
{
struct V_53 * V_55 , * V_192 ;
F_85 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_120 ( V_55 , V_58 ) ;
}
void F_124 ( struct V_193 * V_194 )
{
struct V_28 * V_29 ;
unsigned long V_67 ;
T_3 V_195 ;
V_29 = F_125 ( F_126 ( V_194 ) , struct V_28 , V_52 ) ;
F_44 ( & V_29 -> V_74 , V_67 ) ;
if ( ! V_29 -> V_65 || F_127 ( & V_29 -> V_52 ) ) {
F_41 ( & V_29 -> V_74 , V_67 ) ;
return;
}
V_29 -> V_65 -> V_57 = V_58 ;
V_195 = F_35 ( V_29 , & V_29 -> V_71 -> V_62 ) ;
if ( V_195 == ~ ( T_3 ) 0 ) {
F_40 ( V_29 ) ;
goto V_196;
}
if ( ( V_29 -> V_45 & V_46 ) &&
( V_195 & V_73 ) ) {
V_29 -> V_45 = V_197 ;
F_24 ( V_29 , L_49 ) ;
F_33 ( V_29 , V_67 ) ;
goto V_196;
}
if ( V_29 -> V_63 & V_157 ) {
F_24 ( V_29 , L_50 ) ;
F_45 ( V_29 ) ;
goto V_196;
}
F_24 ( V_29 , L_51 ) ;
F_31 ( V_29 , V_29 -> V_65 ) ;
V_196:
F_41 ( & V_29 -> V_74 , V_67 ) ;
return;
}
static void F_128 ( struct V_28 * V_29 ,
struct V_143 * V_144 )
{
int V_75 = F_129 ( F_9 ( V_144 -> V_67 ) ) ;
T_3 V_198 ;
T_1 V_199 ;
T_2 V_163 ;
union V_3 * V_200 ;
struct V_53 * V_190 ;
T_2 V_201 ;
V_198 = F_54 ( V_144 -> V_200 ) ;
V_200 = V_29 -> V_62 -> V_32 ;
F_130 ( V_29 -> V_62 , & V_200 -> V_9 ) ;
V_199 = F_1 ( V_29 -> V_62 -> V_31 ,
V_200 ) ;
if ( ! V_199 || V_198 != ( T_3 ) V_199 ) {
F_51 ( V_29 ,
L_52 ) ;
return;
}
V_190 = F_83 ( & V_29 -> V_54 , struct V_53 , V_54 ) ;
F_131 ( & V_29 -> V_52 ) ;
V_163 = F_132 ( F_9 ( V_144 -> V_57 ) ) ;
if ( V_163 == V_59 ) {
F_133 ( & V_29 -> V_70 ) ;
return;
}
if ( V_190 -> V_60 != V_29 -> V_62 -> V_32 ) {
F_38 ( V_29 ,
L_53 ) ;
return;
}
if ( V_163 == V_58 ) {
V_29 -> V_45 = V_202 ;
if ( V_190 -> V_57 == V_58 ) {
if ( V_29 -> V_65 == V_190 )
V_29 -> V_65 = NULL ;
goto V_203;
}
}
V_201 = F_134 ( F_9 ( V_200 -> V_9 . V_10 [ 3 ] ) ) ;
switch ( V_201 ) {
case V_204 :
F_104 ( V_29 , V_75 , V_190 , V_163 ) ;
break;
case V_205 :
F_105 ( V_29 , V_75 ) ;
break;
case V_206 :
if ( ! V_190 -> V_191 )
F_109 ( V_29 , V_75 , V_144 ,
V_163 ) ;
break;
case V_207 :
break;
case V_208 :
F_113 ( V_29 , V_75 ) ;
break;
case V_209 :
F_135 ( V_75 != F_129 (
F_9 ( V_200 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_74 ( V_29 , V_75 , V_200 , V_144 ) ;
break;
case V_210 :
F_135 ( V_75 != F_129 (
F_9 ( V_200 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_92 ( V_29 , V_75 , V_200 , V_163 ) ;
break;
case V_61 :
if ( V_190 -> V_57 == V_59 )
V_163 = V_59 ;
break;
case V_211 :
F_135 ( V_75 != F_129 (
F_9 ( V_200 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_100 ( V_29 , V_75 , V_200 , V_163 ) ;
break;
case V_212 :
V_75 = F_129 (
F_9 ( V_200 -> V_9 . V_10 [ 3 ] ) ) ;
F_115 ( V_29 , V_75 , V_144 ) ;
break;
case V_213 :
F_117 ( V_29 , V_144 ) ;
break;
default:
F_136 ( V_29 , L_54 , V_201 ) ;
break;
}
if ( ! F_137 ( & V_29 -> V_54 ) ) {
V_29 -> V_65 = F_83 ( & V_190 -> V_54 ,
struct V_53 , V_54 ) ;
F_27 ( V_29 , V_66 ) ;
} else if ( V_29 -> V_65 == V_190 ) {
V_29 -> V_65 = NULL ;
}
V_203:
F_120 ( V_190 , V_163 ) ;
F_16 ( V_29 , V_29 -> V_62 ) ;
}
static void F_138 ( struct V_28 * V_29 ,
union V_3 * V_144 )
{
T_2 V_214 ;
V_214 = F_134 ( F_9 ( V_144 -> V_9 . V_10 [ 3 ] ) ) ;
F_24 ( V_29 , L_55 , V_214 ) ;
if ( V_214 == V_215 && ( V_29 -> V_39 & V_189 ) )
F_128 ( V_29 , & V_144 -> V_216 ) ;
}
static unsigned int F_139 ( struct V_123 * V_124 ,
struct V_28 * V_29 , T_2 V_217 )
{
unsigned int V_154 ;
unsigned int V_218 = 0 ;
for ( V_154 = 0 ; V_154 < ( V_217 - 1 ) ; V_154 ++ ) {
T_6 V_219 = V_29 -> V_220 [ V_154 ] ;
if ( V_219 == 0 || V_219 == V_221 )
continue;
if ( ( V_219 == 0x03 ) == ( V_124 -> V_222 >= V_223 ) )
V_218 ++ ;
}
return V_218 ;
}
static void F_140 ( struct V_28 * V_29 ,
union V_3 * V_144 )
{
T_2 V_75 ;
struct V_224 * V_225 ;
V_75 = F_129 ( F_9 ( V_144 -> V_9 . V_10 [ 3 ] ) ) ;
if ( ! V_29 -> V_81 [ V_75 ] ) {
F_51 ( V_29 , L_56
L_57 , V_75 ) ;
return;
}
F_24 ( V_29 , L_58 ,
V_75 ) ;
V_225 = V_29 -> V_81 [ V_75 ] -> V_225 ;
if ( V_225 && V_225 -> V_226 )
F_141 ( V_225 -> V_226 , V_225 -> V_227 ) ;
}
static void F_142 ( struct V_28 * V_29 ,
union V_3 * V_144 )
{
struct V_123 * V_124 ;
T_2 V_217 ;
T_2 V_228 , V_229 ;
int V_230 ;
int V_75 ;
unsigned int V_231 ;
T_6 V_232 ;
struct V_233 * V_234 ;
T_4 T_5 * * V_220 ;
bool V_235 = false ;
if ( F_132 ( F_9 ( V_144 -> V_9 . V_10 [ 2 ] ) ) != V_167 )
F_51 ( V_29 ,
L_59 ) ;
V_217 = F_143 ( F_9 ( V_144 -> V_9 . V_10 [ 0 ] ) ) ;
F_24 ( V_29 , L_60 , V_217 ) ;
V_230 = F_144 ( V_29 -> V_156 ) ;
if ( ( V_217 <= 0 ) || ( V_217 > V_230 ) ) {
F_51 ( V_29 , L_61 , V_217 ) ;
F_16 ( V_29 , V_29 -> V_236 ) ;
return;
}
V_232 = V_29 -> V_220 [ V_217 - 1 ] ;
V_124 = F_62 ( V_29 ) ;
if ( ( V_232 == 0x03 ) != ( V_124 -> V_222 >= V_223 ) )
V_124 = V_29 -> V_237 ;
if ( V_232 == 0 ) {
F_51 ( V_29 , L_62
L_63 ,
V_217 ) ;
V_235 = true ;
goto V_166;
}
if ( V_232 == V_221 ) {
F_51 ( V_29 , L_64
L_63 ,
V_217 ) ;
V_235 = true ;
goto V_166;
}
V_234 = & V_29 -> V_234 [ F_145 ( V_124 ) ] ;
if ( V_124 -> V_222 >= V_223 )
V_220 = V_29 -> V_238 ;
else
V_220 = V_29 -> V_239 ;
V_231 = F_139 ( V_124 , V_29 ,
V_217 ) ;
V_228 = F_26 ( V_220 [ V_231 ] ) ;
if ( V_124 -> V_95 == V_240 ) {
F_24 ( V_29 , L_65 ) ;
F_146 ( V_124 ) ;
}
if ( V_124 -> V_222 >= V_223 && ( V_228 & V_241 ) == V_242 )
V_234 -> V_243 &= ~ ( 1 << V_231 ) ;
if ( ( V_228 & V_244 ) && ( V_228 & V_241 ) == V_245 ) {
F_24 ( V_29 , L_66 , V_217 ) ;
V_229 = F_26 ( & V_29 -> V_71 -> V_178 ) ;
if ( ! ( V_229 & V_246 ) ) {
F_51 ( V_29 , L_67 ) ;
goto V_166;
}
if ( F_147 ( V_228 ) ) {
F_24 ( V_29 , L_68 , V_217 ) ;
V_234 -> V_243 |= 1 << V_231 ;
F_148 ( V_29 , V_220 ,
V_231 , V_244 ) ;
F_149 ( V_29 , V_220 , V_231 ,
V_247 ) ;
V_235 = true ;
goto V_166;
} else if ( ! F_150 ( V_231 ,
& V_234 -> V_248 ) ) {
F_24 ( V_29 , L_69 , V_217 ) ;
V_234 -> V_249 [ V_231 ] = V_250 +
F_43 ( V_251 ) ;
F_151 ( V_231 , & V_234 -> V_248 ) ;
F_152 ( & V_124 -> V_252 ,
V_234 -> V_249 [ V_231 ] ) ;
}
}
if ( ( V_228 & V_244 ) && ( V_228 & V_241 ) == V_247 &&
F_147 ( V_228 ) ) {
F_24 ( V_29 , L_70 , V_217 ) ;
V_75 = F_153 ( V_124 , V_29 ,
V_231 + 1 ) ;
if ( V_75 && V_29 -> V_81 [ V_75 ] )
F_154 ( V_29 , V_75 ) ;
if ( V_234 -> V_243 & ( 1 << V_231 ) ) {
V_234 -> V_243 &=
~ ( 1 << V_231 ) ;
F_148 ( V_29 , V_220 ,
V_231 , V_244 ) ;
F_141 ( V_124 -> V_128 . V_253 ,
V_231 + 1 ) ;
V_235 = true ;
goto V_166;
}
}
if ( ! F_147 ( V_228 ) &&
F_155 ( V_231 ,
& V_234 -> V_254 ) ) {
F_122 ( & V_234 -> V_255 [ V_231 ] ) ;
V_235 = true ;
goto V_166;
}
if ( V_124 -> V_222 < V_223 )
F_148 ( V_29 , V_220 , V_231 ,
V_244 ) ;
V_166:
F_16 ( V_29 , V_29 -> V_236 ) ;
if ( V_235 )
return;
F_24 ( V_29 , L_71 , V_256 ) ;
F_151 ( V_257 , & V_124 -> V_67 ) ;
F_66 ( & V_29 -> V_74 ) ;
F_156 ( V_124 ) ;
F_69 ( & V_29 -> V_74 ) ;
}
struct V_1 * F_157 ( struct V_28 * V_29 ,
struct V_1 * V_119 ,
union V_3 * V_258 ,
union V_3 * V_259 ,
T_1 V_260 ,
bool V_261 )
{
T_1 V_262 ;
T_1 V_263 ;
T_1 V_264 ;
struct V_1 * V_265 ;
V_262 = F_1 ( V_119 , V_258 ) ;
V_265 = V_119 ;
do {
if ( V_262 == 0 )
return NULL ;
V_263 = F_1 ( V_265 ,
& V_265 -> V_6 [ V_7 - 1 ] ) ;
V_264 = F_1 ( V_265 , V_259 ) ;
if ( V_261 )
F_51 ( V_29 ,
L_72 ,
( unsigned long long ) V_260 ,
( unsigned long long ) V_262 ,
( unsigned long long ) V_264 ,
( unsigned long long ) V_265 -> V_8 ,
( unsigned long long ) V_263 ) ;
if ( V_264 > 0 ) {
if ( V_262 <= V_264 ) {
if ( V_260 >= V_262 && V_260 <= V_264 )
return V_265 ;
} else {
if ( ( V_260 >= V_262 &&
V_260 <= V_263 ) ||
( V_260 >= V_265 -> V_8 &&
V_260 <= V_264 ) )
return V_265 ;
}
return NULL ;
} else {
if ( V_260 >= V_262 && V_260 <= V_263 )
return V_265 ;
}
V_265 = V_265 -> V_15 ;
V_262 = F_1 ( V_265 , & V_265 -> V_6 [ 0 ] ) ;
} while ( V_265 != V_119 );
return NULL ;
}
static void F_158 ( struct V_28 * V_29 ,
unsigned int V_75 , unsigned int V_76 ,
unsigned int V_77 ,
struct V_18 * V_19 , union V_3 * V_266 )
{
struct V_79 * V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
struct V_53 * V_178 ;
V_178 = F_102 ( V_29 , false , false , V_179 ) ;
if ( ! V_178 )
return;
V_80 -> V_83 |= V_86 ;
V_80 -> V_267 = V_77 ;
F_159 ( V_29 , V_178 , V_75 , V_76 ) ;
F_160 ( V_29 , V_76 , V_19 ) ;
V_80 -> V_267 = 0 ;
F_23 ( V_29 ) ;
}
static int F_161 ( struct V_28 * V_29 ,
struct V_110 * V_111 ,
unsigned int V_268 )
{
if ( V_268 == V_269 ||
V_268 == V_270 ||
V_268 == V_271 )
if ( F_98 ( V_111 ) == V_272 )
return 1 ;
return 0 ;
}
int F_162 ( struct V_28 * V_29 , unsigned int V_268 )
{
if ( V_268 >= 224 && V_268 <= 255 ) {
F_24 ( V_29 , L_73 ,
V_268 ) ;
F_24 ( V_29 , L_74 ) ;
return 1 ;
}
return 0 ;
}
static int F_163 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_13 * V_98 , int * V_57 )
{
struct V_20 * V_20 ;
struct V_21 * V_21 = NULL ;
V_21 = V_19 -> V_21 ;
V_20 = V_21 -> V_22 ;
F_70 ( V_29 , V_98 , V_19 ) ;
if ( V_21 -> V_273 > V_21 -> V_274 ) {
F_51 ( V_29 , L_75 ,
V_21 -> V_274 , V_21 -> V_273 ) ;
V_21 -> V_273 = 0 ;
* V_57 = 0 ;
}
F_81 ( & V_19 -> V_88 ) ;
if ( ! F_49 ( & V_19 -> V_148 ) )
F_81 ( & V_19 -> V_148 ) ;
F_11 ( V_21 ) ;
if ( F_10 ( V_19 ) ) {
if ( ( V_21 -> V_273 != V_21 -> V_274 &&
( V_21 -> V_275 & V_276 ) ) ||
( * V_57 != 0 && ! F_164 ( & V_21 -> V_80 -> V_277 ) ) )
F_24 ( V_29 , L_76 ,
V_21 , V_21 -> V_273 ,
V_21 -> V_274 , * V_57 ) ;
if ( F_61 ( V_21 -> V_126 ) == V_127 )
* V_57 = 0 ;
F_59 ( V_29 , V_19 , * V_57 ) ;
}
return 0 ;
}
static int F_165 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_266 , struct V_278 * V_144 ,
struct V_79 * V_80 , int * V_57 , bool V_279 )
{
struct V_96 * V_280 ;
struct V_110 * V_111 ;
struct V_13 * V_98 ;
unsigned int V_75 ;
T_2 V_268 ;
int V_76 ;
V_75 = F_129 ( F_9 ( V_144 -> V_67 ) ) ;
V_280 = V_29 -> V_81 [ V_75 ] ;
V_76 = F_166 ( F_9 ( V_144 -> V_67 ) ) - 1 ;
V_98 = F_167 ( V_80 , F_54 ( V_144 -> V_281 ) ) ;
V_111 = F_55 ( V_29 , V_280 -> V_112 , V_76 ) ;
V_268 = F_132 ( F_9 ( V_144 -> V_282 ) ) ;
if ( V_279 )
goto V_283;
if ( V_268 == V_284 ||
V_268 == V_285 ||
V_268 == V_286 ) {
V_80 -> V_149 = V_19 ;
return 0 ;
}
if ( V_268 == V_287 ||
F_161 ( V_29 , V_111 ,
V_268 ) ) {
F_158 ( V_29 , V_75 , V_76 ,
V_98 -> V_77 , V_19 , V_266 ) ;
} else {
while ( V_98 -> V_32 != V_19 -> V_115 )
F_16 ( V_29 , V_98 ) ;
F_16 ( V_29 , V_98 ) ;
}
V_283:
return F_163 ( V_29 , V_19 , V_98 , V_57 ) ;
}
static int F_168 ( struct V_28 * V_29 , struct V_13 * V_14 ,
union V_3 * V_288 )
{
T_2 V_289 ;
union V_3 * V_4 = V_14 -> V_32 ;
struct V_1 * V_2 = V_14 -> V_31 ;
for ( V_289 = 0 ; V_4 != V_288 ; F_15 ( V_29 , V_14 , & V_2 , & V_4 ) ) {
if ( ! F_2 ( V_4 ) && ! F_4 ( V_4 ) )
V_289 += F_169 ( F_9 ( V_4 -> V_9 . V_10 [ 2 ] ) ) ;
}
return V_289 ;
}
static int F_170 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_266 , struct V_278 * V_144 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_96 * V_280 ;
struct V_13 * V_98 ;
unsigned int V_75 ;
int V_76 ;
struct V_110 * V_111 ;
T_2 V_268 ;
T_2 V_290 , V_291 ;
T_2 V_214 ;
V_214 = F_134 ( F_9 ( V_266 -> V_9 . V_10 [ 3 ] ) ) ;
V_75 = F_129 ( F_9 ( V_144 -> V_67 ) ) ;
V_280 = V_29 -> V_81 [ V_75 ] ;
V_76 = F_166 ( F_9 ( V_144 -> V_67 ) ) - 1 ;
V_98 = F_167 ( V_80 , F_54 ( V_144 -> V_281 ) ) ;
V_111 = F_55 ( V_29 , V_280 -> V_112 , V_76 ) ;
V_268 = F_132 ( F_9 ( V_144 -> V_282 ) ) ;
V_291 = V_19 -> V_21 -> V_274 ;
V_290 = F_171 ( F_9 ( V_144 -> V_282 ) ) ;
switch ( V_268 ) {
case V_167 :
if ( V_214 != V_292 ) {
F_51 ( V_29 , L_77 ,
( V_214 == V_293 ) ? L_78 : L_79 ) ;
* V_57 = - V_152 ;
break;
}
* V_57 = 0 ;
break;
case V_294 :
* V_57 = 0 ;
break;
case V_286 :
if ( V_214 == V_293 || V_214 == V_295 )
V_19 -> V_21 -> V_273 = V_290 ;
else
F_51 ( V_29 , L_80 ) ;
goto F_165;
case V_285 :
switch ( V_214 ) {
case V_296 :
V_19 -> V_21 -> V_273 = 0 ;
goto F_165;
case V_293 :
case V_295 :
V_19 -> V_21 -> V_273 = V_291 - V_290 ;
goto F_165;
case V_292 :
V_19 -> V_21 -> V_273 = V_291 ;
goto F_165;
default:
F_51 ( V_29 , L_81 ,
V_214 ) ;
goto F_165;
}
case V_284 :
goto F_165;
default:
if ( ! F_161 ( V_29 ,
V_111 , V_268 ) )
break;
F_24 ( V_29 , L_82 ,
V_268 , V_76 ) ;
case V_287 :
if ( V_214 == V_293 || V_214 == V_295 )
V_19 -> V_21 -> V_273 = V_291 - V_290 ;
else if ( ! V_19 -> V_297 )
V_19 -> V_21 -> V_273 = 0 ;
goto F_165;
}
if ( V_214 == V_296 )
goto F_165;
if ( V_214 == V_293 ||
V_214 == V_295 ) {
V_19 -> V_297 = true ;
V_19 -> V_21 -> V_273 = V_291 - V_290 ;
F_24 ( V_29 , L_83 ) ;
return 0 ;
}
if ( ! V_19 -> V_297 )
V_19 -> V_21 -> V_273 = V_291 ;
F_165:
return F_165 ( V_29 , V_19 , V_266 , V_144 , V_80 , V_57 , false ) ;
}
static int F_172 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_266 , struct V_278 * V_144 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_13 * V_98 ;
struct V_20 * V_20 ;
int V_298 ;
struct V_299 * V_300 ;
T_2 V_268 ;
bool V_301 = false ;
T_2 V_290 , V_291 , V_302 ;
int V_303 ;
V_98 = F_167 ( V_80 , F_54 ( V_144 -> V_281 ) ) ;
V_268 = F_132 ( F_9 ( V_144 -> V_282 ) ) ;
V_20 = V_19 -> V_21 -> V_22 ;
V_298 = V_20 -> V_23 ;
V_300 = & V_19 -> V_21 -> V_304 [ V_298 ] ;
V_291 = V_300 -> V_305 ;
V_290 = F_171 ( F_9 ( V_144 -> V_282 ) ) ;
V_302 = F_169 ( F_9 ( V_266 -> V_9 . V_10 [ 2 ] ) ) ;
V_303 = V_19 -> V_21 -> V_275 & V_276 ?
- V_306 : 0 ;
switch ( V_268 ) {
case V_167 :
if ( V_290 ) {
V_300 -> V_57 = V_303 ;
if ( V_29 -> V_39 & V_307 )
V_301 = true ;
break;
}
V_300 -> V_57 = 0 ;
break;
case V_294 :
V_300 -> V_57 = V_303 ;
V_301 = true ;
break;
case V_308 :
V_300 -> V_57 = - V_309 ;
break;
case V_310 :
case V_270 :
V_300 -> V_57 = - V_311 ;
break;
case V_312 :
case V_287 :
V_300 -> V_57 = - V_313 ;
break;
case V_269 :
V_300 -> V_57 = - V_313 ;
if ( V_266 != V_19 -> V_115 )
return 0 ;
break;
case V_285 :
V_301 = true ;
break;
case V_286 :
V_300 -> V_57 = V_303 ;
V_291 = V_290 ;
break;
case V_284 :
V_291 = 0 ;
V_290 = 0 ;
break;
default:
V_301 = true ;
V_300 -> V_57 = - 1 ;
break;
}
if ( V_301 )
V_300 -> V_273 = F_168 ( V_29 , V_98 , V_266 ) +
V_302 - V_290 ;
else
V_300 -> V_273 = V_291 ;
V_19 -> V_21 -> V_273 += V_300 -> V_273 ;
return F_165 ( V_29 , V_19 , V_266 , V_144 , V_80 , V_57 , false ) ;
}
static int F_173 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_278 * V_144 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_13 * V_98 ;
struct V_20 * V_20 ;
struct V_299 * V_300 ;
int V_298 ;
V_98 = F_167 ( V_80 , F_54 ( V_144 -> V_281 ) ) ;
V_20 = V_19 -> V_21 -> V_22 ;
V_298 = V_20 -> V_23 ;
V_300 = & V_19 -> V_21 -> V_304 [ V_298 ] ;
V_300 -> V_57 = - V_314 ;
V_300 -> V_273 = 0 ;
while ( V_98 -> V_32 != V_19 -> V_115 )
F_16 ( V_29 , V_98 ) ;
F_16 ( V_29 , V_98 ) ;
return F_165 ( V_29 , V_19 , NULL , V_144 , V_80 , V_57 , true ) ;
}
static int F_174 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_266 , struct V_278 * V_144 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_13 * V_98 ;
T_2 V_268 ;
T_2 V_290 , V_291 , V_302 ;
V_98 = F_167 ( V_80 , F_54 ( V_144 -> V_281 ) ) ;
V_268 = F_132 ( F_9 ( V_144 -> V_282 ) ) ;
V_290 = F_171 ( F_9 ( V_144 -> V_282 ) ) ;
V_302 = F_169 ( F_9 ( V_266 -> V_9 . V_10 [ 2 ] ) ) ;
V_291 = V_19 -> V_21 -> V_274 ;
switch ( V_268 ) {
case V_167 :
if ( V_266 != V_19 -> V_115 || V_290 ) {
F_51 ( V_29 , L_84 ) ;
F_24 ( V_29 , L_85 ,
V_19 -> V_21 -> V_80 -> V_277 . V_315 ,
V_291 , V_290 ) ;
}
* V_57 = 0 ;
break;
case V_294 :
F_24 ( V_29 , L_85 ,
V_19 -> V_21 -> V_80 -> V_277 . V_315 ,
V_291 , V_290 ) ;
* V_57 = 0 ;
break;
case V_286 :
V_19 -> V_21 -> V_273 = V_290 ;
goto F_165;
case V_284 :
V_302 = 0 ;
V_290 = 0 ;
break;
default:
break;
}
if ( V_266 == V_19 -> V_115 )
V_19 -> V_21 -> V_273 = V_291 - V_290 ;
else
V_19 -> V_21 -> V_273 =
F_168 ( V_29 , V_98 , V_266 ) +
V_302 - V_290 ;
F_165:
if ( V_290 > V_291 ) {
F_51 ( V_29 , L_86 ,
V_290 ) ;
V_19 -> V_21 -> V_273 = 0 ;
}
return F_165 ( V_29 , V_19 , V_266 , V_144 , V_80 , V_57 , false ) ;
}
static int F_175 ( struct V_28 * V_29 ,
struct V_278 * V_144 )
{
struct V_96 * V_280 ;
struct V_79 * V_80 ;
struct V_13 * V_98 ;
unsigned int V_75 ;
int V_76 ;
struct V_18 * V_19 = NULL ;
T_1 V_316 ;
struct V_1 * V_317 ;
union V_3 * V_266 ;
int V_57 = - V_318 ;
struct V_110 * V_111 ;
struct V_319 * V_151 ;
T_2 V_268 ;
int V_320 = 0 ;
bool V_321 = false ;
V_75 = F_129 ( F_9 ( V_144 -> V_67 ) ) ;
V_280 = V_29 -> V_81 [ V_75 ] ;
if ( ! V_280 ) {
F_38 ( V_29 , L_87 ,
V_75 ) ;
F_38 ( V_29 , L_88 ,
( unsigned long long ) F_1 (
V_29 -> V_236 -> V_31 ,
V_29 -> V_236 -> V_32 ) ,
F_176 ( F_54 ( V_144 -> V_281 ) ) ,
F_177 ( F_54 ( V_144 -> V_281 ) ) ,
F_9 ( V_144 -> V_282 ) ,
F_9 ( V_144 -> V_67 ) ) ;
return - V_322 ;
}
V_76 = F_166 ( F_9 ( V_144 -> V_67 ) ) - 1 ;
V_80 = & V_280 -> V_82 [ V_76 ] ;
V_98 = F_167 ( V_80 , F_54 ( V_144 -> V_281 ) ) ;
V_111 = F_55 ( V_29 , V_280 -> V_112 , V_76 ) ;
if ( ! V_98 || F_98 ( V_111 ) == V_323 ) {
F_38 ( V_29 ,
L_89 ,
V_75 , V_76 ) ;
F_38 ( V_29 , L_88 ,
( unsigned long long ) F_1 (
V_29 -> V_236 -> V_31 ,
V_29 -> V_236 -> V_32 ) ,
F_176 ( F_54 ( V_144 -> V_281 ) ) ,
F_177 ( F_54 ( V_144 -> V_281 ) ) ,
F_9 ( V_144 -> V_282 ) ,
F_9 ( V_144 -> V_67 ) ) ;
return - V_322 ;
}
if ( V_80 -> V_279 ) {
F_178 (tmp, &ep_ring->td_list)
V_320 ++ ;
}
V_316 = F_54 ( V_144 -> V_281 ) ;
V_268 = F_132 ( F_9 ( V_144 -> V_282 ) ) ;
switch ( V_268 ) {
case V_167 :
if ( F_171 ( F_9 ( V_144 -> V_282 ) ) == 0 )
break;
if ( V_29 -> V_39 & V_307 )
V_268 = V_294 ;
else
F_179 ( V_29 ,
L_90 ,
V_75 , V_76 ) ;
case V_294 :
break;
case V_285 :
F_24 ( V_29 , L_91 ,
V_75 , V_76 ) ;
break;
case V_284 :
F_24 ( V_29 ,
L_92 ,
V_75 , V_76 ) ;
break;
case V_286 :
F_24 ( V_29 ,
L_93 ,
V_75 , V_76 ) ;
break;
case V_287 :
F_24 ( V_29 , L_94 , V_75 ,
V_76 ) ;
V_80 -> V_83 |= V_86 ;
V_57 = - V_324 ;
break;
case V_169 :
F_51 ( V_29 ,
L_95 ,
V_75 , V_76 ) ;
V_57 = - V_325 ;
break;
case V_271 :
case V_269 :
F_24 ( V_29 , L_96 ,
V_75 , V_76 ) ;
V_57 = - V_313 ;
break;
case V_270 :
F_24 ( V_29 , L_97 ,
V_75 , V_76 ) ;
V_57 = - V_311 ;
break;
case V_326 :
F_51 ( V_29 ,
L_98 ,
V_75 , V_76 ) ;
V_57 = - V_327 ;
break;
case V_308 :
F_51 ( V_29 ,
L_99 ,
V_75 , V_76 ) ;
break;
case V_310 :
F_51 ( V_29 ,
L_100 ,
V_75 , V_76 ) ;
break;
case V_328 :
F_24 ( V_29 , L_101 ) ;
if ( ! F_49 ( & V_98 -> V_88 ) )
F_24 ( V_29 , L_102
L_103 ,
F_129 ( F_9 ( V_144 -> V_67 ) ) ,
V_76 ) ;
goto V_166;
case V_329 :
F_24 ( V_29 , L_104 ) ;
if ( ! F_49 ( & V_98 -> V_88 ) )
F_24 ( V_29 , L_105
L_103 ,
F_129 ( F_9 ( V_144 -> V_67 ) ) ,
V_76 ) ;
goto V_166;
case V_312 :
F_51 ( V_29 ,
L_106 ,
V_75 , V_76 ) ;
V_57 = - V_313 ;
break;
case V_330 :
V_80 -> V_279 = true ;
F_24 ( V_29 ,
L_107 ,
V_75 , V_76 ) ;
goto V_166;
case V_331 :
V_80 -> V_279 = true ;
F_24 ( V_29 ,
L_108 ,
V_75 , V_76 ) ;
goto V_166;
default:
if ( F_162 ( V_29 , V_268 ) ) {
V_57 = 0 ;
break;
}
F_51 ( V_29 ,
L_109 ,
V_268 , V_75 , V_76 ) ;
goto V_166;
}
do {
if ( F_49 ( & V_98 -> V_88 ) ) {
if ( ! ( V_268 == V_285 ||
V_268 == V_284 ) ) {
F_51 ( V_29 , L_110 ,
F_129 ( F_9 ( V_144 -> V_67 ) ) ,
V_76 ) ;
}
if ( V_80 -> V_279 ) {
V_80 -> V_279 = false ;
F_24 ( V_29 , L_111 ,
V_75 , V_76 ) ;
}
goto V_166;
}
if ( V_80 -> V_279 && V_320 == 0 ) {
V_80 -> V_279 = false ;
F_24 ( V_29 , L_112 ,
V_75 , V_76 ) ;
goto V_166;
}
V_19 = F_83 ( & V_98 -> V_88 , struct V_18 ,
V_88 ) ;
if ( V_80 -> V_279 )
V_320 -- ;
V_317 = F_157 ( V_29 , V_98 -> V_31 , V_98 -> V_32 ,
V_19 -> V_115 , V_316 , false ) ;
if ( ! V_317 && ( V_268 == V_285 ||
V_268 == V_284 ) ) {
goto V_166;
}
if ( ! V_317 ) {
if ( ! V_80 -> V_279 ||
! F_164 ( & V_19 -> V_21 -> V_80 -> V_277 ) ) {
if ( ( V_29 -> V_39 & V_332 ) &&
V_98 -> V_333 ) {
V_98 -> V_333 = false ;
goto V_166;
}
F_38 ( V_29 ,
L_113
L_114
L_115 , V_76 ,
V_268 ) ;
F_157 ( V_29 , V_98 -> V_31 ,
V_98 -> V_32 , V_19 -> V_115 ,
V_316 , true ) ;
return - V_152 ;
}
F_173 ( V_29 , V_19 , V_144 , V_80 , & V_57 ) ;
goto V_166;
}
if ( V_268 == V_294 )
V_98 -> V_333 = true ;
else
V_98 -> V_333 = false ;
if ( V_80 -> V_279 ) {
F_24 ( V_29 ,
L_116 ,
V_75 , V_76 ) ;
V_80 -> V_279 = false ;
}
V_266 = & V_317 -> V_6 [ ( V_316 - V_317 -> V_8 ) /
sizeof( * V_266 ) ] ;
F_180 ( V_98 ,
(struct V_334 * ) V_266 ) ;
if ( F_2 ( V_266 ) ) {
F_24 ( V_29 ,
L_117 ,
V_75 , V_76 ) ;
goto V_166;
}
if ( F_181 ( & V_19 -> V_21 -> V_80 -> V_277 ) )
F_170 ( V_29 , V_19 , V_266 , V_144 , V_80 , & V_57 ) ;
else if ( F_164 ( & V_19 -> V_21 -> V_80 -> V_277 ) )
F_172 ( V_29 , V_19 , V_266 , V_144 , V_80 , & V_57 ) ;
else
F_174 ( V_29 , V_19 , V_266 , V_144 , V_80 ,
& V_57 ) ;
V_166:
V_321 = V_80 -> V_279 &&
V_268 != V_330 &&
V_268 != V_331 ;
if ( ! V_321 )
F_16 ( V_29 , V_29 -> V_236 ) ;
} while ( V_321 );
return 0 ;
}
static int F_182 ( struct V_28 * V_29 )
{
union V_3 * V_144 ;
int V_335 = 1 ;
int V_69 ;
if ( ! V_29 -> V_236 || ! V_29 -> V_236 -> V_32 ) {
F_38 ( V_29 , L_118 ) ;
return - V_336 ;
}
V_144 = V_29 -> V_236 -> V_32 ;
if ( ( F_9 ( V_144 -> V_216 . V_67 ) & V_27 ) !=
V_29 -> V_236 -> V_33 )
return 0 ;
F_183 ( V_29 -> V_236 , & V_144 -> V_9 ) ;
F_184 () ;
switch ( F_9 ( V_144 -> V_216 . V_67 ) & V_337 ) {
case F_14 ( V_338 ) :
F_128 ( V_29 , & V_144 -> V_216 ) ;
break;
case F_14 ( V_339 ) :
F_142 ( V_29 , V_144 ) ;
V_335 = 0 ;
break;
case F_14 ( V_340 ) :
V_69 = F_175 ( V_29 , & V_144 -> V_341 ) ;
if ( V_69 >= 0 )
V_335 = 0 ;
break;
case F_14 ( V_342 ) :
F_140 ( V_29 , V_144 ) ;
break;
default:
if ( ( F_9 ( V_144 -> V_216 . V_67 ) & V_337 ) >=
F_14 ( 48 ) )
F_138 ( V_29 , V_144 ) ;
else
F_51 ( V_29 , L_119 ,
F_134 (
F_9 ( V_144 -> V_216 . V_67 ) ) ) ;
}
if ( V_29 -> V_63 & V_64 ) {
F_24 ( V_29 , L_120
L_121 ) ;
return 0 ;
}
if ( V_335 )
F_16 ( V_29 , V_29 -> V_236 ) ;
return 1 ;
}
T_7 F_185 ( struct V_123 * V_124 )
{
struct V_28 * V_29 = F_186 ( V_124 ) ;
union V_3 * V_343 ;
T_7 V_69 = V_344 ;
unsigned long V_67 ;
T_1 V_113 ;
T_3 V_68 ;
T_2 V_57 ;
F_44 ( & V_29 -> V_74 , V_67 ) ;
V_57 = F_26 ( & V_29 -> V_71 -> V_57 ) ;
if ( V_57 == ~ ( T_2 ) 0 ) {
F_40 ( V_29 ) ;
V_69 = V_345 ;
goto V_346;
}
if ( ! ( V_57 & V_347 ) )
goto V_346;
if ( V_57 & V_348 ) {
F_51 ( V_29 , L_122 ) ;
F_39 ( V_29 ) ;
V_69 = V_345 ;
goto V_346;
}
V_57 |= V_347 ;
F_25 ( V_57 , & V_29 -> V_71 -> V_57 ) ;
if ( ! V_124 -> V_349 ) {
T_2 V_350 ;
V_350 = F_26 ( & V_29 -> V_351 -> V_350 ) ;
V_350 |= V_352 ;
F_25 ( V_350 , & V_29 -> V_351 -> V_350 ) ;
}
if ( V_29 -> V_63 & V_64 ||
V_29 -> V_63 & V_353 ) {
F_24 ( V_29 , L_123
L_124 ) ;
V_68 = F_35 ( V_29 , & V_29 -> V_351 -> V_354 ) ;
F_36 ( V_29 , V_68 | V_355 ,
& V_29 -> V_351 -> V_354 ) ;
V_69 = V_345 ;
goto V_346;
}
V_343 = V_29 -> V_236 -> V_32 ;
while ( F_182 ( V_29 ) > 0 ) {}
V_68 = F_35 ( V_29 , & V_29 -> V_351 -> V_354 ) ;
if ( V_343 != V_29 -> V_236 -> V_32 ) {
V_113 = F_1 ( V_29 -> V_236 -> V_31 ,
V_29 -> V_236 -> V_32 ) ;
if ( V_113 == 0 )
F_51 ( V_29 , L_125
L_126 ) ;
V_68 &= V_356 ;
V_68 |= ( ( T_3 ) V_113 & ( T_3 ) ~ V_356 ) ;
}
V_68 |= V_355 ;
F_36 ( V_29 , V_68 , & V_29 -> V_351 -> V_354 ) ;
V_69 = V_345 ;
V_346:
F_41 ( & V_29 -> V_74 , V_67 ) ;
return V_69 ;
}
T_7 F_187 ( int V_357 , void * V_124 )
{
return F_185 ( V_124 ) ;
}
static void F_188 ( struct V_28 * V_29 , struct V_13 * V_14 ,
bool V_35 ,
T_2 V_358 , T_2 V_359 , T_2 V_360 , T_2 V_361 )
{
struct V_334 * V_4 ;
V_4 = & V_14 -> V_37 -> V_9 ;
V_4 -> V_10 [ 0 ] = F_13 ( V_358 ) ;
V_4 -> V_10 [ 1 ] = F_13 ( V_359 ) ;
V_4 -> V_10 [ 2 ] = F_13 ( V_360 ) ;
V_4 -> V_10 [ 3 ] = F_13 ( V_361 ) ;
F_189 ( V_14 , V_4 ) ;
F_18 ( V_29 , V_14 , V_35 ) ;
}
static int F_190 ( struct V_28 * V_29 , struct V_13 * V_98 ,
T_2 V_83 , unsigned int V_42 , T_8 V_362 )
{
unsigned int V_363 ;
switch ( V_83 ) {
case V_323 :
F_51 ( V_29 , L_127 ) ;
return - V_364 ;
case V_365 :
F_51 ( V_29 , L_128 ) ;
return - V_366 ;
case V_272 :
F_24 ( V_29 , L_129 ) ;
case V_367 :
case V_368 :
break;
default:
F_38 ( V_29 , L_130 ) ;
return - V_366 ;
}
while ( 1 ) {
if ( F_22 ( V_29 , V_98 , V_42 ) )
break;
if ( V_98 == V_29 -> V_62 ) {
F_38 ( V_29 , L_131 ) ;
return - V_336 ;
}
F_53 ( V_29 , V_369 ,
L_132 ) ;
V_363 = V_42 - V_98 -> V_34 ;
if ( F_191 ( V_29 , V_98 , V_363 ,
V_362 ) ) {
F_38 ( V_29 , L_133 ) ;
return - V_336 ;
}
}
while ( F_4 ( V_98 -> V_37 ) ) {
if ( ! F_19 ( V_29 ) &&
! ( V_98 -> type == V_38 &&
( V_29 -> V_39 & V_40 ) ) )
V_98 -> V_37 -> V_11 . V_12 &=
F_13 ( ~ V_26 ) ;
else
V_98 -> V_37 -> V_11 . V_12 |=
F_13 ( V_26 ) ;
F_20 () ;
V_98 -> V_37 -> V_11 . V_12 ^= F_13 ( V_27 ) ;
if ( F_8 ( V_98 -> V_37 ) )
V_98 -> V_33 ^= 1 ;
V_98 -> V_41 = V_98 -> V_41 -> V_15 ;
V_98 -> V_37 = V_98 -> V_41 -> V_6 ;
}
return 0 ;
}
static int F_192 ( struct V_28 * V_29 ,
struct V_96 * V_280 ,
unsigned int V_76 ,
unsigned int V_77 ,
unsigned int V_42 ,
struct V_21 * V_21 ,
unsigned int V_370 ,
T_8 V_362 )
{
int V_69 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
struct V_13 * V_98 ;
struct V_110 * V_111 = F_55 ( V_29 , V_280 -> V_112 , V_76 ) ;
V_98 = F_94 ( V_280 , V_76 , V_77 ) ;
if ( ! V_98 ) {
F_24 ( V_29 , L_134 ,
V_77 ) ;
return - V_366 ;
}
V_69 = F_190 ( V_29 , V_98 , F_98 ( V_111 ) ,
V_42 , V_362 ) ;
if ( V_69 )
return V_69 ;
V_20 = V_21 -> V_22 ;
V_19 = & V_20 -> V_19 [ V_370 ] ;
F_193 ( & V_19 -> V_88 ) ;
F_193 ( & V_19 -> V_148 ) ;
if ( V_370 == 0 ) {
V_69 = F_194 ( F_60 ( V_21 -> V_97 -> V_125 ) , V_21 ) ;
if ( F_75 ( V_69 ) )
return V_69 ;
}
V_19 -> V_21 = V_21 ;
F_195 ( & V_19 -> V_88 , & V_98 -> V_88 ) ;
V_19 -> V_119 = V_98 -> V_41 ;
V_19 -> V_120 = V_98 -> V_37 ;
return 0 ;
}
static unsigned int F_196 ( T_3 V_101 , T_3 V_371 )
{
unsigned int V_42 ;
V_42 = F_197 ( V_371 + ( V_101 & ( V_372 - 1 ) ) ,
V_372 ) ;
if ( V_42 == 0 )
V_42 ++ ;
return V_42 ;
}
static inline unsigned int F_198 ( struct V_21 * V_21 )
{
return F_196 ( V_21 -> V_373 , V_21 -> V_274 ) ;
}
static unsigned int F_199 ( struct V_21 * V_21 )
{
struct V_374 * V_137 ;
unsigned int V_154 , V_371 , V_375 , V_42 = 0 ;
V_375 = V_21 -> V_274 ;
F_200 (urb->sg, sg, urb->num_mapped_sgs, i) {
V_371 = F_201 ( V_137 ) ;
V_42 += F_196 ( F_202 ( V_137 ) , V_371 ) ;
V_371 = F_203 (unsigned int, len, full_len) ;
V_375 -= V_371 ;
if ( V_375 == 0 )
break;
}
return V_42 ;
}
static unsigned int F_204 ( struct V_21 * V_21 , int V_154 )
{
T_3 V_101 , V_371 ;
V_101 = ( T_3 ) ( V_21 -> V_373 + V_21 -> V_304 [ V_154 ] . V_376 ) ;
V_371 = V_21 -> V_304 [ V_154 ] . V_305 ;
return F_196 ( V_101 , V_371 ) ;
}
static void F_205 ( struct V_21 * V_21 , int V_377 )
{
if ( F_75 ( V_377 != V_21 -> V_274 ) )
F_206 ( & V_21 -> V_97 -> V_97 , L_135
L_136 ,
V_256 ,
V_21 -> V_80 -> V_277 . V_315 ,
V_377 , V_377 ,
V_21 -> V_274 ,
V_21 -> V_274 ) ;
}
static void F_207 ( struct V_28 * V_29 , int V_75 ,
unsigned int V_76 , unsigned int V_77 , int V_378 ,
struct V_334 * V_258 )
{
F_20 () ;
if ( V_378 )
V_258 -> V_10 [ 3 ] |= F_13 ( V_378 ) ;
else
V_258 -> V_10 [ 3 ] &= F_13 ( ~ V_27 ) ;
F_46 ( V_29 , V_75 , V_76 , V_77 ) ;
}
static void F_208 ( struct V_28 * V_29 , struct V_21 * V_21 ,
struct V_110 * V_111 )
{
int V_379 ;
int V_380 ;
V_379 = F_209 ( F_9 ( V_111 -> V_381 ) ) ;
V_380 = V_21 -> V_382 ;
if ( V_21 -> V_97 -> V_222 == V_383 ||
V_21 -> V_97 -> V_222 == V_384 )
V_380 *= 8 ;
if ( V_379 != V_380 ) {
F_210 ( & V_21 -> V_97 -> V_97 ,
L_137 ,
V_380 , V_380 == 1 ? L_138 : L_139 ,
V_379 , V_379 == 1 ? L_138 : L_139 ) ;
V_21 -> V_382 = V_379 ;
if ( V_21 -> V_97 -> V_222 == V_383 ||
V_21 -> V_97 -> V_222 == V_384 )
V_21 -> V_382 /= 8 ;
}
}
int F_211 ( struct V_28 * V_29 , T_8 V_362 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_110 * V_111 ;
V_111 = F_55 ( V_29 , V_29 -> V_81 [ V_75 ] -> V_112 , V_76 ) ;
F_208 ( V_29 , V_21 , V_111 ) ;
return F_212 ( V_29 , V_362 , V_21 , V_75 , V_76 ) ;
}
static T_2 F_213 ( struct V_28 * V_29 , int V_385 ,
int V_386 , unsigned int V_387 ,
struct V_21 * V_21 , bool V_35 )
{
T_2 V_388 , V_389 ;
if ( V_29 -> V_390 < 0x100 && ! ( V_29 -> V_39 & V_391 ) )
return ( ( V_387 - V_385 ) >> 10 ) ;
if ( ! V_35 || ( V_385 == 0 && V_386 == 0 ) ||
V_386 == V_387 )
return 0 ;
if ( V_29 -> V_39 & V_391 )
V_386 = 0 ;
V_388 = F_214 ( & V_21 -> V_80 -> V_277 ) ;
V_389 = F_197 ( V_387 , V_388 ) ;
return ( V_389 - ( ( V_385 + V_386 ) / V_388 ) ) ;
}
static int F_215 ( struct V_28 * V_29 , struct V_21 * V_21 , T_2 V_392 ,
T_2 * V_386 , struct V_1 * V_2 )
{
struct V_131 * V_97 = F_62 ( V_29 ) -> V_128 . V_132 ;
unsigned int V_393 ;
unsigned int V_394 ;
T_2 V_395 ;
V_394 = F_214 ( & V_21 -> V_80 -> V_277 ) ;
V_393 = ( V_392 + * V_386 ) % V_394 ;
if ( V_393 == 0 )
return 0 ;
F_24 ( V_29 , L_140 ,
V_393 , * V_386 ) ;
if ( * V_386 > V_393 ) {
* V_386 -= V_393 ;
F_24 ( V_29 , L_141 , * V_386 ) ;
return 0 ;
}
V_395 = V_394 - ( V_392 % V_394 ) ;
if ( V_395 > ( V_21 -> V_274 - V_392 ) )
V_395 = ( V_21 -> V_274 - V_392 ) ;
if ( F_71 ( V_21 ) ) {
F_216 ( V_21 -> V_137 , V_21 -> V_138 ,
V_2 -> V_139 , V_395 , V_392 ) ;
V_2 -> V_134 = F_217 ( V_97 , V_2 -> V_139 ,
V_394 , V_136 ) ;
} else {
V_2 -> V_134 = F_217 ( V_97 , V_2 -> V_139 ,
V_394 , V_142 ) ;
}
if ( F_218 ( V_97 , V_2 -> V_134 ) ) {
F_51 ( V_29 , L_142 ) ;
return 0 ;
}
* V_386 = V_395 ;
V_2 -> V_140 = V_395 ;
V_2 -> V_141 = V_392 ;
F_24 ( V_29 , L_143 , * V_386 ) ;
return 1 ;
}
int F_212 ( struct V_28 * V_29 , T_8 V_362 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_13 * V_14 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
struct V_334 * V_258 ;
struct V_374 * V_137 = NULL ;
bool V_35 = true ;
bool V_396 = false ;
bool V_120 = true ;
unsigned int V_42 ;
unsigned int V_378 , V_397 = 0 ;
unsigned int V_392 , V_398 , V_386 , V_375 ;
int V_399 , V_69 ;
T_2 V_10 , V_400 , V_401 ;
T_3 V_101 , V_402 ;
V_14 = F_80 ( V_29 , V_21 ) ;
if ( ! V_14 )
return - V_366 ;
V_375 = V_21 -> V_274 ;
if ( V_21 -> V_397 ) {
V_397 = V_21 -> V_138 ;
V_137 = V_21 -> V_137 ;
V_101 = ( T_3 ) F_202 ( V_137 ) ;
V_398 = F_201 ( V_137 ) ;
V_42 = F_199 ( V_21 ) ;
} else {
V_42 = F_198 ( V_21 ) ;
V_101 = ( T_3 ) V_21 -> V_373 ;
V_398 = V_375 ;
}
V_69 = F_192 ( V_29 , V_29 -> V_81 [ V_75 ] ,
V_76 , V_21 -> V_77 ,
V_42 , V_21 , 0 , V_362 ) ;
if ( F_75 ( V_69 < 0 ) )
return V_69 ;
V_20 = V_21 -> V_22 ;
if ( V_21 -> V_275 & V_403 && V_20 -> V_24 > 1 )
V_396 = true ;
V_19 = & V_20 -> V_19 [ 0 ] ;
V_258 = & V_14 -> V_37 -> V_9 ;
V_378 = V_14 -> V_33 ;
V_402 = V_101 ;
for ( V_392 = 0 ; V_120 || V_392 < V_375 ;
V_392 += V_386 ) {
V_10 = F_14 ( V_295 ) ;
V_386 = F_219 ( V_101 ) ;
V_386 = F_203 (unsigned int, trb_buff_len, block_len) ;
if ( V_392 + V_386 > V_375 )
V_386 = V_375 - V_392 ;
if ( V_120 ) {
V_120 = false ;
if ( V_378 == 0 )
V_10 |= V_27 ;
} else
V_10 |= V_14 -> V_33 ;
if ( V_392 + V_386 < V_375 ) {
V_10 |= V_26 ;
if ( F_4 ( V_14 -> V_37 + 1 ) ) {
if ( F_215 ( V_29 , V_21 , V_392 ,
& V_386 ,
V_14 -> V_41 ) ) {
V_402 = V_14 -> V_41 -> V_134 ;
V_19 -> V_133 = V_14 -> V_41 ;
}
}
}
if ( V_392 + V_386 >= V_375 ) {
V_10 &= ~ V_26 ;
V_10 |= V_404 ;
V_35 = false ;
V_19 -> V_115 = V_14 -> V_37 ;
}
if ( F_220 ( V_21 ) )
V_10 |= V_405 ;
V_401 = F_213 ( V_29 , V_392 , V_386 ,
V_375 , V_21 , V_35 ) ;
V_400 = F_169 ( V_386 ) |
F_221 ( V_401 ) |
F_222 ( 0 ) ;
F_188 ( V_29 , V_14 , V_35 | V_396 ,
F_176 ( V_402 ) ,
F_177 ( V_402 ) ,
V_400 ,
V_10 ) ;
V_101 += V_386 ;
V_399 = V_386 ;
while ( V_137 && V_399 >= V_398 ) {
-- V_397 ;
V_399 -= V_398 ;
if ( V_397 != 0 ) {
V_137 = F_223 ( V_137 ) ;
V_398 = F_201 ( V_137 ) ;
V_101 = ( T_3 ) F_202 ( V_137 ) ;
V_101 += V_399 ;
}
}
V_398 -= V_399 ;
V_402 = V_101 ;
}
if ( V_396 ) {
V_69 = F_192 ( V_29 , V_29 -> V_81 [ V_75 ] ,
V_76 , V_21 -> V_77 ,
1 , V_21 , 1 , V_362 ) ;
V_20 -> V_19 [ 1 ] . V_115 = V_14 -> V_37 ;
V_10 = F_14 ( V_295 ) | V_14 -> V_33 | V_404 ;
F_188 ( V_29 , V_14 , 0 , 0 , 0 , F_222 ( 0 ) , V_10 ) ;
}
F_205 ( V_21 , V_392 ) ;
F_207 ( V_29 , V_75 , V_76 , V_21 -> V_77 ,
V_378 , V_258 ) ;
return 0 ;
}
int F_224 ( struct V_28 * V_29 , T_8 V_362 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_13 * V_98 ;
int V_42 ;
int V_69 ;
struct V_406 * V_407 ;
struct V_334 * V_258 ;
int V_378 ;
T_2 V_10 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
V_98 = F_80 ( V_29 , V_21 ) ;
if ( ! V_98 )
return - V_366 ;
if ( ! V_21 -> V_408 )
return - V_366 ;
V_42 = 2 ;
if ( V_21 -> V_274 > 0 )
V_42 ++ ;
V_69 = F_192 ( V_29 , V_29 -> V_81 [ V_75 ] ,
V_76 , V_21 -> V_77 ,
V_42 , V_21 , 0 , V_362 ) ;
if ( V_69 < 0 )
return V_69 ;
V_20 = V_21 -> V_22 ;
V_19 = & V_20 -> V_19 [ 0 ] ;
V_258 = & V_98 -> V_37 -> V_9 ;
V_378 = V_98 -> V_33 ;
V_407 = (struct V_406 * ) V_21 -> V_408 ;
V_10 = 0 ;
V_10 |= V_409 | F_14 ( V_296 ) ;
if ( V_378 == 0 )
V_10 |= 0x1 ;
if ( ( V_29 -> V_390 >= 0x100 ) || ( V_29 -> V_39 & V_391 ) ) {
if ( V_21 -> V_274 > 0 ) {
if ( V_407 -> V_410 & V_411 )
V_10 |= F_225 ( V_412 ) ;
else
V_10 |= F_225 ( V_413 ) ;
}
}
F_188 ( V_29 , V_98 , true ,
V_407 -> V_410 | V_407 -> V_414 << 8 | F_226 ( V_407 -> V_415 ) << 16 ,
F_226 ( V_407 -> V_416 ) | F_226 ( V_407 -> V_417 ) << 16 ,
F_169 ( 8 ) | F_222 ( 0 ) ,
V_10 ) ;
if ( F_220 ( V_21 ) )
V_10 = V_405 | F_14 ( V_293 ) ;
else
V_10 = F_14 ( V_293 ) ;
if ( V_21 -> V_274 > 0 ) {
T_2 V_400 , V_401 ;
V_401 = F_213 ( V_29 , 0 ,
V_21 -> V_274 ,
V_21 -> V_274 ,
V_21 , 1 ) ;
V_400 = F_169 ( V_21 -> V_274 ) |
F_221 ( V_401 ) |
F_222 ( 0 ) ;
if ( V_407 -> V_410 & V_411 )
V_10 |= V_418 ;
F_188 ( V_29 , V_98 , true ,
F_176 ( V_21 -> V_373 ) ,
F_177 ( V_21 -> V_373 ) ,
V_400 ,
V_10 | V_98 -> V_33 ) ;
}
V_19 -> V_115 = V_98 -> V_37 ;
if ( V_21 -> V_274 > 0 && V_407 -> V_410 & V_411 )
V_10 = 0 ;
else
V_10 = V_418 ;
F_188 ( V_29 , V_98 , false ,
0 ,
0 ,
F_222 ( 0 ) ,
V_10 | V_404 | F_14 ( V_292 ) | V_98 -> V_33 ) ;
F_207 ( V_29 , V_75 , V_76 , 0 ,
V_378 , V_258 ) ;
return 0 ;
}
static unsigned int F_227 ( struct V_28 * V_29 ,
struct V_21 * V_21 , unsigned int V_389 )
{
unsigned int V_419 ;
if ( V_29 -> V_390 < 0x100 || V_21 -> V_97 -> V_222 < V_420 )
return 0 ;
V_419 = V_21 -> V_80 -> V_421 . V_422 ;
return F_197 ( V_389 , V_419 + 1 ) - 1 ;
}
static unsigned int F_228 ( struct V_28 * V_29 ,
struct V_21 * V_21 , unsigned int V_389 )
{
unsigned int V_419 ;
unsigned int V_423 ;
if ( V_29 -> V_390 < 0x100 )
return 0 ;
if ( V_21 -> V_97 -> V_222 >= V_420 ) {
V_419 = V_21 -> V_80 -> V_421 . V_422 ;
V_423 = V_389 % ( V_419 + 1 ) ;
if ( V_423 == 0 )
return V_419 ;
return V_423 - 1 ;
}
if ( V_389 == 0 )
return 0 ;
return V_389 - 1 ;
}
static int F_229 ( struct V_28 * V_29 ,
struct V_21 * V_21 , int V_424 )
{
int V_425 , V_426 , V_69 = 0 ;
int V_427 , V_428 , V_429 ;
if ( V_21 -> V_97 -> V_222 == V_383 ||
V_21 -> V_97 -> V_222 == V_384 )
V_425 = V_21 -> V_425 + V_424 * V_21 -> V_382 ;
else
V_425 = ( V_21 -> V_425 + V_424 * V_21 -> V_382 ) >> 3 ;
V_426 = F_230 ( V_29 -> V_430 ) & 0x7 ;
if ( F_230 ( V_29 -> V_430 ) & ( 1 << 3 ) )
V_426 <<= 3 ;
V_429 = F_26 ( & V_29 -> V_431 -> V_432 ) ;
V_427 = F_231 ( V_429 + V_426 + 1 , 8 ) ;
V_428 = F_232 ( V_429 + 895 * 8 , 8 ) ;
V_425 &= 0x7ff ;
V_427 = ( V_427 >> 3 ) & 0x7ff ;
V_428 = ( V_428 >> 3 ) & 0x7ff ;
F_24 ( V_29 , L_144 ,
V_256 , V_424 , F_26 ( & V_29 -> V_431 -> V_432 ) ,
V_427 , V_428 , V_425 ) ;
if ( V_427 < V_428 ) {
if ( V_425 > V_428 ||
V_425 < V_427 )
V_69 = - V_366 ;
} else if ( V_427 > V_428 ) {
if ( ( V_425 > V_428 &&
V_425 < V_427 ) )
V_69 = - V_366 ;
} else {
V_69 = - V_366 ;
}
if ( V_424 == 0 ) {
if ( V_69 == - V_366 || V_425 == V_427 ) {
V_425 = V_427 + 1 ;
if ( V_21 -> V_97 -> V_222 == V_383 ||
V_21 -> V_97 -> V_222 == V_384 )
V_21 -> V_425 = V_425 ;
else
V_21 -> V_425 = V_425 << 3 ;
V_69 = 0 ;
}
}
if ( V_69 ) {
F_51 ( V_29 , L_145 ,
V_425 , V_429 , V_424 ,
V_427 , V_428 ) ;
F_51 ( V_29 , L_146 ) ;
return V_69 ;
}
return V_425 ;
}
static int F_233 ( struct V_28 * V_29 , T_8 V_362 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_13 * V_98 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
int V_24 , V_433 ;
struct V_334 * V_258 ;
bool V_120 ;
int V_378 ;
T_2 V_10 , V_400 ;
int V_377 , V_386 , V_434 , V_435 , V_69 ;
T_3 V_436 , V_101 ;
int V_154 , V_155 ;
bool V_35 ;
struct V_79 * V_437 ;
int V_438 ;
V_437 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
V_98 = V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] . V_14 ;
V_24 = V_21 -> V_439 ;
if ( V_24 < 1 ) {
F_24 ( V_29 , L_147 ) ;
return - V_366 ;
}
V_436 = ( T_3 ) V_21 -> V_373 ;
V_258 = & V_98 -> V_37 -> V_9 ;
V_378 = V_98 -> V_33 ;
V_20 = V_21 -> V_22 ;
for ( V_154 = 0 ; V_154 < V_24 ; V_154 ++ ) {
unsigned int V_440 , V_394 ;
unsigned int V_441 , V_442 ;
T_2 V_443 ;
V_120 = true ;
V_377 = 0 ;
V_101 = V_436 + V_21 -> V_304 [ V_154 ] . V_376 ;
V_434 = V_21 -> V_304 [ V_154 ] . V_305 ;
V_435 = V_434 ;
V_394 = F_214 ( & V_21 -> V_80 -> V_277 ) ;
V_440 = F_197 ( V_434 , V_394 ) ;
if ( V_440 == 0 )
V_440 ++ ;
V_441 = F_227 ( V_29 , V_21 , V_440 ) ;
V_442 = F_228 ( V_29 ,
V_21 , V_440 ) ;
V_433 = F_204 ( V_21 , V_154 ) ;
V_69 = F_192 ( V_29 , V_29 -> V_81 [ V_75 ] , V_76 ,
V_21 -> V_77 , V_433 , V_21 , V_154 , V_362 ) ;
if ( V_69 < 0 ) {
if ( V_154 == 0 )
return V_69 ;
goto V_166;
}
V_19 = & V_20 -> V_19 [ V_154 ] ;
V_443 = V_444 ;
if ( ! ( V_21 -> V_275 & V_445 ) &&
F_234 ( V_29 -> V_446 ) ) {
V_438 = F_229 ( V_29 , V_21 , V_154 ) ;
if ( V_438 >= 0 )
V_443 = F_235 ( V_438 ) ;
}
V_10 = F_14 ( V_447 ) |
F_236 ( V_442 ) |
V_443 |
( V_154 ? V_98 -> V_33 : ! V_378 ) ;
if ( ! V_437 -> V_448 )
V_10 |= F_237 ( V_441 ) ;
for ( V_155 = 0 ; V_155 < V_433 ; V_155 ++ ) {
T_2 V_401 = 0 ;
if ( ! V_120 )
V_10 = F_14 ( V_295 ) |
V_98 -> V_33 ;
if ( F_220 ( V_21 ) )
V_10 |= V_405 ;
if ( V_155 < V_433 - 1 ) {
V_35 = true ;
V_10 |= V_26 ;
} else {
V_35 = false ;
V_19 -> V_115 = V_98 -> V_37 ;
V_10 |= V_404 ;
if ( V_29 -> V_390 >= 0x100 &&
! ( V_29 -> V_39 & V_449 ) &&
V_154 < V_24 - 1 )
V_10 |= V_450 ;
}
V_386 = F_219 ( V_101 ) ;
if ( V_386 > V_435 )
V_386 = V_435 ;
V_401 = F_213 ( V_29 , V_377 ,
V_386 , V_434 ,
V_21 , V_35 ) ;
V_400 = F_169 ( V_386 ) |
F_222 ( 0 ) ;
if ( V_120 && V_437 -> V_448 )
V_400 |= F_238 ( V_441 ) ;
else
V_400 |= F_221 ( V_401 ) ;
V_120 = false ;
F_188 ( V_29 , V_98 , V_35 ,
F_176 ( V_101 ) ,
F_177 ( V_101 ) ,
V_400 ,
V_10 ) ;
V_377 += V_386 ;
V_101 += V_386 ;
V_435 -= V_386 ;
}
if ( V_377 != V_434 ) {
F_38 ( V_29 , L_148 ) ;
V_69 = - V_366 ;
goto V_166;
}
}
if ( F_234 ( V_29 -> V_446 ) )
V_437 -> V_451 = V_21 -> V_425 + V_24 * V_21 -> V_382 ;
if ( F_62 ( V_29 ) -> V_128 . V_129 == 0 ) {
if ( V_29 -> V_39 & V_130 )
F_239 () ;
}
F_62 ( V_29 ) -> V_128 . V_129 ++ ;
F_207 ( V_29 , V_75 , V_76 , V_21 -> V_77 ,
V_378 , V_258 ) ;
return 0 ;
V_166:
for ( V_154 -- ; V_154 >= 0 ; V_154 -- )
F_81 ( & V_20 -> V_19 [ V_154 ] . V_88 ) ;
V_20 -> V_19 [ 0 ] . V_115 = V_98 -> V_37 ;
F_56 ( V_29 , V_98 , & V_20 -> V_19 [ 0 ] , true ) ;
V_98 -> V_37 = V_20 -> V_19 [ 0 ] . V_120 ;
V_98 -> V_41 = V_20 -> V_19 [ 0 ] . V_119 ;
V_98 -> V_33 = V_378 ;
V_98 -> V_34 = V_98 -> V_160 ;
F_65 ( F_60 ( V_21 -> V_97 -> V_125 ) , V_21 ) ;
return V_69 ;
}
int F_240 ( struct V_28 * V_29 , T_8 V_362 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_96 * V_280 ;
struct V_13 * V_98 ;
struct V_110 * V_111 ;
int V_425 ;
int V_24 , V_42 , V_154 ;
int V_69 ;
struct V_79 * V_437 ;
int V_426 ;
V_280 = V_29 -> V_81 [ V_75 ] ;
V_437 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
V_98 = V_280 -> V_82 [ V_76 ] . V_14 ;
V_111 = F_55 ( V_29 , V_280 -> V_112 , V_76 ) ;
V_42 = 0 ;
V_24 = V_21 -> V_439 ;
for ( V_154 = 0 ; V_154 < V_24 ; V_154 ++ )
V_42 += F_204 ( V_21 , V_154 ) ;
V_69 = F_190 ( V_29 , V_98 , F_98 ( V_111 ) ,
V_42 , V_362 ) ;
if ( V_69 )
return V_69 ;
F_208 ( V_29 , V_21 , V_111 ) ;
if ( F_234 ( V_29 -> V_446 ) && ! F_49 ( & V_98 -> V_88 ) ) {
if ( F_98 ( V_111 ) == V_368 ) {
V_21 -> V_425 = V_437 -> V_451 ;
goto V_452;
}
}
V_425 = F_26 ( & V_29 -> V_431 -> V_432 ) ;
V_425 &= 0x3fff ;
V_426 = F_230 ( V_29 -> V_430 ) & 0x7 ;
if ( F_230 ( V_29 -> V_430 ) & ( 1 << 3 ) )
V_426 <<= 3 ;
V_425 += V_426 + V_453 ;
V_425 = F_231 ( V_425 , 8 ) ;
if ( V_21 -> V_97 -> V_222 == V_383 ||
V_21 -> V_97 -> V_222 == V_384 ) {
V_425 = F_231 ( V_425 , V_21 -> V_382 << 3 ) ;
V_21 -> V_425 = V_425 >> 3 ;
} else {
V_425 = F_231 ( V_425 , V_21 -> V_382 ) ;
V_21 -> V_425 = V_425 ;
}
V_452:
V_98 -> V_160 = V_98 -> V_34 ;
return F_233 ( V_29 , V_362 , V_21 , V_75 , V_76 ) ;
}
static int F_241 ( struct V_28 * V_29 , struct V_53 * V_190 ,
T_2 V_358 , T_2 V_359 ,
T_2 V_360 , T_2 V_361 , bool V_454 )
{
int V_455 = V_29 -> V_456 ;
int V_69 ;
if ( ( V_29 -> V_63 & V_64 ) ||
( V_29 -> V_63 & V_353 ) ) {
F_24 ( V_29 , L_149 ) ;
return - V_152 ;
}
if ( ! V_454 )
V_455 ++ ;
V_69 = F_190 ( V_29 , V_29 -> V_62 , V_368 ,
V_455 , V_179 ) ;
if ( V_69 < 0 ) {
F_38 ( V_29 , L_150 ) ;
if ( V_454 )
F_38 ( V_29 , L_151
L_152 ) ;
return V_69 ;
}
V_190 -> V_60 = V_29 -> V_62 -> V_37 ;
if ( F_49 ( & V_29 -> V_54 ) ) {
V_29 -> V_65 = V_190 ;
F_27 ( V_29 , V_66 ) ;
}
F_195 ( & V_190 -> V_54 , & V_29 -> V_54 ) ;
F_188 ( V_29 , V_29 -> V_62 , false , V_358 , V_359 , V_360 ,
V_361 | V_29 -> V_62 -> V_33 ) ;
return 0 ;
}
int F_242 ( struct V_28 * V_29 , struct V_53 * V_190 ,
T_2 V_214 , T_2 V_75 )
{
return F_241 ( V_29 , V_190 , 0 , 0 , 0 ,
F_14 ( V_214 ) | F_243 ( V_75 ) , false ) ;
}
int F_244 ( struct V_28 * V_29 , struct V_53 * V_190 ,
T_1 V_457 , T_2 V_75 , enum V_458 V_407 )
{
return F_241 ( V_29 , V_190 , F_176 ( V_457 ) ,
F_177 ( V_457 ) , 0 ,
F_14 ( V_208 ) | F_243 ( V_75 )
| ( V_407 == V_459 ? V_460 : 0 ) , false ) ;
}
int F_245 ( struct V_28 * V_29 , struct V_53 * V_190 ,
T_2 V_358 , T_2 V_359 , T_2 V_360 , T_2 V_361 )
{
return F_241 ( V_29 , V_190 , V_358 , V_359 , V_360 , V_361 , false ) ;
}
int F_246 ( struct V_28 * V_29 , struct V_53 * V_190 ,
T_2 V_75 )
{
return F_241 ( V_29 , V_190 , 0 , 0 , 0 ,
F_14 ( V_212 ) | F_243 ( V_75 ) ,
false ) ;
}
int F_103 ( struct V_28 * V_29 ,
struct V_53 * V_190 , T_1 V_457 ,
T_2 V_75 , bool V_454 )
{
return F_241 ( V_29 , V_190 , F_176 ( V_457 ) ,
F_177 ( V_457 ) , 0 ,
F_14 ( V_206 ) | F_243 ( V_75 ) ,
V_454 ) ;
}
int F_247 ( struct V_28 * V_29 , struct V_53 * V_190 ,
T_1 V_457 , T_2 V_75 , bool V_454 )
{
return F_241 ( V_29 , V_190 , F_176 ( V_457 ) ,
F_177 ( V_457 ) , 0 ,
F_14 ( V_207 ) | F_243 ( V_75 ) ,
V_454 ) ;
}
int F_248 ( struct V_28 * V_29 , struct V_53 * V_190 ,
int V_75 , unsigned int V_76 , int V_461 )
{
T_2 V_462 = F_243 ( V_75 ) ;
T_2 V_463 = F_249 ( V_76 ) ;
T_2 type = F_14 ( V_209 ) ;
T_2 V_464 = F_250 ( V_461 ) ;
return F_241 ( V_29 , V_190 , 0 , 0 , 0 ,
V_462 | V_463 | type | V_464 , false ) ;
}
void F_82 ( struct V_28 * V_29 ,
unsigned int V_75 , unsigned int V_76 ,
unsigned int V_77 ,
struct V_94 * V_147 )
{
T_1 V_101 ;
T_2 V_462 = F_243 ( V_75 ) ;
T_2 V_463 = F_249 ( V_76 ) ;
T_2 V_465 = F_251 ( V_77 ) ;
T_2 V_466 = 0 ;
T_2 type = F_14 ( V_210 ) ;
struct V_79 * V_80 ;
struct V_53 * V_190 ;
int V_69 ;
F_53 ( V_29 , V_105 ,
L_153 ,
V_147 -> V_116 ,
( unsigned long long ) V_147 -> V_116 -> V_8 ,
V_147 -> V_117 ,
( unsigned long long ) F_1 (
V_147 -> V_116 , V_147 -> V_117 ) ,
V_147 -> V_114 ) ;
V_101 = F_1 ( V_147 -> V_116 ,
V_147 -> V_117 ) ;
if ( V_101 == 0 ) {
F_51 ( V_29 , L_154 ) ;
F_51 ( V_29 , L_155 ,
V_147 -> V_116 , V_147 -> V_117 ) ;
return;
}
V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
if ( ( V_80 -> V_83 & V_85 ) ) {
F_51 ( V_29 , L_154 ) ;
F_51 ( V_29 , L_156 ) ;
return;
}
V_190 = F_102 ( V_29 , false , false , V_179 ) ;
if ( ! V_190 )
return;
V_80 -> V_175 = V_147 -> V_116 ;
V_80 -> V_162 = V_147 -> V_117 ;
if ( V_77 )
V_466 = F_252 ( V_467 ) ;
V_69 = F_241 ( V_29 , V_190 ,
F_176 ( V_101 ) | V_466 | V_147 -> V_114 ,
F_177 ( V_101 ) , V_465 ,
V_462 | V_463 | type , false ) ;
if ( V_69 < 0 ) {
F_253 ( V_29 , V_190 ) ;
return;
}
V_80 -> V_83 |= V_85 ;
}
int F_159 ( struct V_28 * V_29 , struct V_53 * V_190 ,
int V_75 , unsigned int V_76 )
{
T_2 V_462 = F_243 ( V_75 ) ;
T_2 V_463 = F_249 ( V_76 ) ;
T_2 type = F_14 ( V_211 ) ;
return F_241 ( V_29 , V_190 , 0 , 0 , 0 ,
V_462 | V_463 | type , false ) ;
}
