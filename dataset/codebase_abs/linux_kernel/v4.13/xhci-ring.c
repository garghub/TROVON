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
static T_3 F_52 ( struct V_28 * V_29 , struct V_93 * V_94 ,
unsigned int V_76 , unsigned int V_77 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_79 * V_80 ;
V_80 = & V_94 -> V_82 [ V_76 ] ;
if ( V_80 -> V_83 & V_87 ) {
V_98 = & V_80 -> V_89 -> V_99 [ V_77 ] ;
return F_53 ( V_98 -> V_100 ) ;
}
V_96 = F_54 ( V_29 , V_94 -> V_101 , V_76 ) ;
return F_53 ( V_96 -> V_102 ) ;
}
void F_55 ( struct V_28 * V_29 ,
unsigned int V_75 , unsigned int V_76 ,
unsigned int V_77 , struct V_18 * V_103 ,
struct V_104 * V_105 )
{
struct V_93 * V_106 = V_29 -> V_81 [ V_75 ] ;
struct V_79 * V_80 = & V_106 -> V_82 [ V_76 ] ;
struct V_13 * V_107 ;
struct V_1 * V_108 ;
union V_3 * V_109 ;
T_1 V_110 ;
T_3 V_111 ;
bool V_112 = false ;
bool V_113 = false ;
V_107 = F_50 ( V_29 , V_75 ,
V_76 , V_77 ) ;
if ( ! V_107 ) {
F_51 ( V_29 , L_11
L_12 ,
V_77 ) ;
return;
}
F_56 ( V_29 , V_114 ,
L_13 ) ;
V_111 = F_52 ( V_29 , V_106 , V_76 , V_77 ) ;
V_108 = V_107 -> V_31 ;
V_109 = V_107 -> V_32 ;
V_105 -> V_115 = V_111 & 0x1 ;
V_105 -> V_77 = V_77 ;
do {
if ( ! V_112 && F_1 ( V_108 , V_109 )
== ( T_1 ) ( V_111 & ~ 0xf ) ) {
V_112 = true ;
if ( V_113 )
break;
}
if ( V_109 == V_103 -> V_116 )
V_113 = true ;
if ( V_112 && F_4 ( V_109 ) &&
F_8 ( V_109 ) )
V_105 -> V_115 ^= 0x1 ;
F_15 ( V_29 , V_107 , & V_108 , & V_109 ) ;
if ( V_109 == V_80 -> V_14 -> V_32 ) {
F_38 ( V_29 , L_14 ) ;
V_105 -> V_117 = NULL ;
V_105 -> V_118 = NULL ;
return;
}
} while ( ! V_112 || ! V_113 );
V_105 -> V_117 = V_108 ;
V_105 -> V_118 = V_109 ;
F_56 ( V_29 , V_114 ,
L_15 , V_105 -> V_115 ) ;
F_56 ( V_29 , V_114 ,
L_16 ,
V_105 -> V_117 ) ;
V_110 = F_1 ( V_105 -> V_117 , V_105 -> V_118 ) ;
F_56 ( V_29 , V_114 ,
L_17 ,
( unsigned long long ) V_110 ) ;
}
static void F_57 ( struct V_28 * V_29 , struct V_13 * V_107 ,
struct V_18 * V_19 , bool V_119 )
{
struct V_1 * V_2 = V_19 -> V_120 ;
union V_3 * V_4 = V_19 -> V_121 ;
while ( 1 ) {
F_12 ( V_4 , V_122 ) ;
if ( V_119 && V_4 != V_19 -> V_121 && V_4 != V_19 -> V_116 )
V_4 -> V_9 . V_10 [ 3 ] ^= F_13 ( V_27 ) ;
if ( V_4 == V_19 -> V_116 )
break;
F_15 ( V_29 , V_107 , & V_2 , & V_4 ) ;
}
}
static void F_58 ( struct V_28 * V_29 ,
struct V_79 * V_80 )
{
V_80 -> V_83 &= ~ V_84 ;
F_59 ( & V_80 -> V_123 ) ;
}
static void F_60 ( struct V_28 * V_29 ,
struct V_18 * V_103 , int V_57 )
{
struct V_21 * V_21 = V_103 -> V_21 ;
struct V_20 * V_20 = V_21 -> V_22 ;
struct V_124 * V_125 = F_61 ( V_21 -> V_106 -> V_126 ) ;
if ( F_62 ( V_21 -> V_127 ) == V_128 ) {
F_63 ( V_29 ) -> V_129 . V_130 -- ;
if ( F_63 ( V_29 ) -> V_129 . V_130 == 0 ) {
if ( V_29 -> V_39 & V_131 )
F_64 () ;
}
}
F_65 ( V_20 ) ;
F_66 ( V_125 , V_21 ) ;
F_67 ( & V_29 -> V_74 ) ;
F_68 ( V_21 ) ;
F_69 ( V_125 , V_21 , V_57 ) ;
F_70 ( & V_29 -> V_74 ) ;
}
static void F_71 ( struct V_28 * V_29 ,
struct V_13 * V_14 , struct V_18 * V_19 )
{
struct V_132 * V_106 = F_63 ( V_29 ) -> V_129 . V_133 ;
struct V_1 * V_2 = V_19 -> V_134 ;
struct V_21 * V_21 = V_19 -> V_21 ;
if ( ! V_14 || ! V_2 || ! V_21 )
return;
if ( F_72 ( V_21 ) ) {
F_73 ( V_106 , V_2 -> V_135 , V_14 -> V_136 ,
V_137 ) ;
return;
}
F_74 ( V_21 -> V_138 , V_21 -> V_139 , V_2 -> V_140 ,
V_2 -> V_141 , V_2 -> V_142 ) ;
F_73 ( V_106 , V_2 -> V_135 , V_14 -> V_136 ,
V_143 ) ;
V_2 -> V_141 = 0 ;
V_2 -> V_142 = 0 ;
}
static void F_75 ( struct V_28 * V_29 , int V_75 ,
union V_3 * V_4 , struct V_144 * V_145 )
{
unsigned int V_76 ;
struct V_13 * V_107 ;
struct V_79 * V_80 ;
struct V_18 * V_103 = NULL ;
struct V_18 * V_146 ;
struct V_95 * V_96 ;
struct V_93 * V_94 ;
T_3 V_147 ;
struct V_104 V_148 ;
if ( F_76 ( F_77 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ) ) {
if ( ! V_29 -> V_81 [ V_75 ] )
F_51 ( V_29 , L_18
L_19 ,
V_75 ) ;
return;
}
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_76 = F_78 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_94 = V_29 -> V_81 [ V_75 ] ;
V_96 = F_54 ( V_29 , V_94 -> V_101 , V_76 ) ;
F_79 ( V_96 ) ;
V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
V_146 = F_80 ( & V_80 -> V_149 ,
struct V_18 , V_149 ) ;
if ( F_49 ( & V_80 -> V_149 ) ) {
F_58 ( V_29 , V_80 ) ;
F_48 ( V_29 , V_75 , V_76 ) ;
return;
}
F_32 (cur_td, &ep->cancelled_td_list, cancelled_td_list) {
F_56 ( V_29 , V_114 ,
L_20 ,
( unsigned long long ) F_1 (
V_103 -> V_120 , V_103 -> V_121 ) ) ;
V_107 = F_81 ( V_29 , V_103 -> V_21 ) ;
if ( ! V_107 ) {
F_51 ( V_29 , L_21
L_22 ,
V_103 -> V_21 ,
V_103 -> V_21 -> V_77 ) ;
goto V_150;
}
V_147 = F_52 ( V_29 , V_94 , V_76 ,
V_103 -> V_21 -> V_77 ) ;
V_147 &= ~ 0xf ;
if ( F_82 ( V_29 , V_103 -> V_120 , V_103 -> V_121 ,
V_103 -> V_116 , V_147 , false ) ) {
F_55 ( V_29 , V_75 , V_76 ,
V_103 -> V_21 -> V_77 ,
V_103 , & V_148 ) ;
} else {
F_57 ( V_29 , V_107 , V_103 , false ) ;
}
V_150:
F_83 ( & V_103 -> V_88 ) ;
}
F_58 ( V_29 , V_80 ) ;
if ( V_148 . V_118 && V_148 . V_117 ) {
F_84 ( V_29 , V_75 , V_76 ,
& V_148 ) ;
F_23 ( V_29 ) ;
} else {
F_48 ( V_29 , V_75 , V_76 ) ;
}
do {
V_103 = F_85 ( & V_80 -> V_149 ,
struct V_18 , V_149 ) ;
F_83 ( & V_103 -> V_149 ) ;
V_107 = F_81 ( V_29 , V_103 -> V_21 ) ;
F_71 ( V_29 , V_107 , V_103 ) ;
F_11 ( V_103 -> V_21 ) ;
if ( F_10 ( V_103 ) )
F_60 ( V_29 , V_103 , 0 ) ;
if ( V_29 -> V_63 & V_64 )
return;
} while ( V_103 != V_146 );
}
static void F_86 ( struct V_28 * V_29 , struct V_13 * V_14 )
{
struct V_18 * V_103 ;
struct V_18 * V_151 ;
F_87 (cur_td, tmp, &ring->td_list, td_list) {
F_83 ( & V_103 -> V_88 ) ;
if ( ! F_49 ( & V_103 -> V_149 ) )
F_83 ( & V_103 -> V_149 ) ;
F_71 ( V_29 , V_14 , V_103 ) ;
F_11 ( V_103 -> V_21 ) ;
if ( F_10 ( V_103 ) )
F_60 ( V_29 , V_103 , - V_152 ) ;
}
}
static void F_88 ( struct V_28 * V_29 ,
int V_75 , int V_76 )
{
struct V_18 * V_103 ;
struct V_18 * V_151 ;
struct V_79 * V_80 ;
struct V_13 * V_14 ;
V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
if ( ( V_80 -> V_83 & V_87 ) ||
( V_80 -> V_83 & V_153 ) ) {
int V_77 ;
for ( V_77 = 1 ; V_77 < V_80 -> V_89 -> V_90 ;
V_77 ++ ) {
V_14 = V_80 -> V_89 -> V_92 [ V_77 ] ;
if ( ! V_14 )
continue;
F_56 ( V_29 , V_114 ,
L_23 ,
V_75 , V_76 , V_77 ) ;
F_86 ( V_29 , V_14 ) ;
}
} else {
V_14 = V_80 -> V_14 ;
if ( ! V_14 )
return;
F_56 ( V_29 , V_114 ,
L_24 ,
V_75 , V_76 ) ;
F_86 ( V_29 , V_14 ) ;
}
F_87 (cur_td, tmp, &ep->cancelled_td_list,
cancelled_td_list) {
F_83 ( & V_103 -> V_149 ) ;
F_11 ( V_103 -> V_21 ) ;
if ( F_10 ( V_103 ) )
F_60 ( V_29 , V_103 , - V_152 ) ;
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
for ( V_154 = 0 ; V_154 <= F_89 ( V_29 -> V_156 ) ; V_154 ++ ) {
if ( ! V_29 -> V_81 [ V_154 ] )
continue;
for ( V_155 = 0 ; V_155 < 31 ; V_155 ++ )
F_88 ( V_29 , V_154 , V_155 ) ;
}
if ( ! ( V_29 -> V_63 & V_157 ) )
F_90 ( F_63 ( V_29 ) ) ;
}
void F_91 ( unsigned long V_158 )
{
struct V_28 * V_29 ;
struct V_79 * V_80 ;
unsigned long V_67 ;
V_80 = (struct V_79 * ) V_158 ;
V_29 = V_80 -> V_29 ;
F_44 ( & V_29 -> V_74 , V_67 ) ;
if ( ! ( V_80 -> V_83 & V_84 ) ||
F_92 ( & V_80 -> V_123 ) ) {
F_41 ( & V_29 -> V_74 , V_67 ) ;
F_24 ( V_29 , L_26 ) ;
return;
}
F_51 ( V_29 , L_27 ) ;
V_80 -> V_83 &= ~ V_84 ;
F_39 ( V_29 ) ;
F_40 ( V_29 ) ;
F_41 ( & V_29 -> V_74 , V_67 ) ;
F_56 ( V_29 , V_114 ,
L_28 ) ;
}
static void F_93 ( struct V_28 * V_29 ,
struct V_93 * V_106 ,
struct V_13 * V_107 ,
unsigned int V_76 )
{
union V_3 * V_159 ;
int V_160 ;
bool V_161 = false ;
V_160 = V_107 -> V_34 ;
V_159 = V_107 -> V_32 ;
if ( F_4 ( V_107 -> V_32 ) ) {
V_107 -> V_31 = V_107 -> V_31 -> V_15 ;
V_107 -> V_32 = V_107 -> V_31 -> V_6 ;
}
while ( V_107 -> V_32 != V_106 -> V_82 [ V_76 ] . V_162 ) {
V_107 -> V_34 ++ ;
V_107 -> V_32 ++ ;
if ( F_4 ( V_107 -> V_32 ) ) {
if ( V_107 -> V_32 ==
V_106 -> V_82 [ V_76 ] . V_162 )
break;
V_107 -> V_31 = V_107 -> V_31 -> V_15 ;
V_107 -> V_32 = V_107 -> V_31 -> V_6 ;
}
if ( V_107 -> V_32 == V_159 ) {
V_161 = true ;
break;
}
}
if ( V_161 ) {
F_24 ( V_29 , L_29 ) ;
V_107 -> V_34 = V_160 ;
}
}
static void F_94 ( struct V_28 * V_29 , int V_75 ,
union V_3 * V_4 , T_2 V_163 )
{
unsigned int V_76 ;
unsigned int V_77 ;
struct V_13 * V_107 ;
struct V_93 * V_106 ;
struct V_79 * V_80 ;
struct V_95 * V_96 ;
struct V_164 * V_165 ;
V_76 = F_78 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_77 = F_95 ( F_9 ( V_4 -> V_9 . V_10 [ 2 ] ) ) ;
V_106 = V_29 -> V_81 [ V_75 ] ;
V_80 = & V_106 -> V_82 [ V_76 ] ;
V_107 = F_96 ( V_106 , V_76 , V_77 ) ;
if ( ! V_107 ) {
F_51 ( V_29 , L_30 ,
V_77 ) ;
goto V_166;
}
V_96 = F_54 ( V_29 , V_106 -> V_101 , V_76 ) ;
V_165 = F_97 ( V_29 , V_106 -> V_101 ) ;
F_98 ( V_165 ) ;
F_99 ( V_96 ) ;
if ( V_163 != V_167 ) {
unsigned int V_83 ;
unsigned int V_168 ;
switch ( V_163 ) {
case V_169 :
F_51 ( V_29 , L_31 ) ;
break;
case V_170 :
F_51 ( V_29 , L_32 ) ;
V_83 = F_100 ( V_96 ) ;
V_168 = F_9 ( V_165 -> V_171 ) ;
V_168 = F_101 ( V_168 ) ;
F_56 ( V_29 , V_114 ,
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
T_3 V_102 ;
if ( V_80 -> V_83 & V_87 ) {
struct V_97 * V_173 =
& V_80 -> V_89 -> V_99 [ V_77 ] ;
V_102 = F_53 ( V_173 -> V_100 ) & V_174 ;
} else {
V_102 = F_53 ( V_96 -> V_102 ) & ~ V_175 ;
}
F_56 ( V_29 , V_114 ,
L_36 , V_102 ) ;
if ( F_1 ( V_80 -> V_176 ,
V_80 -> V_162 ) == V_102 ) {
F_93 ( V_29 , V_106 ,
V_107 , V_76 ) ;
} else {
F_51 ( V_29 , L_37 ) ;
F_51 ( V_29 , L_38 ,
V_80 -> V_176 , V_80 -> V_162 ) ;
}
}
V_166:
V_106 -> V_82 [ V_76 ] . V_83 &= ~ V_85 ;
V_106 -> V_82 [ V_76 ] . V_176 = NULL ;
V_106 -> V_82 [ V_76 ] . V_162 = NULL ;
F_48 ( V_29 , V_75 , V_76 ) ;
}
static void F_102 ( struct V_28 * V_29 , int V_75 ,
union V_3 * V_4 , T_2 V_163 )
{
struct V_93 * V_94 ;
struct V_95 * V_96 ;
unsigned int V_76 ;
V_76 = F_78 ( F_9 ( V_4 -> V_9 . V_10 [ 3 ] ) ) ;
V_94 = V_29 -> V_81 [ V_75 ] ;
V_96 = F_54 ( V_29 , V_94 -> V_101 , V_76 ) ;
F_103 ( V_96 ) ;
F_56 ( V_29 , V_177 ,
L_39 , V_163 ) ;
if ( V_29 -> V_39 & V_178 ) {
struct V_53 * V_179 ;
V_179 = F_104 ( V_29 , false , false , V_180 ) ;
if ( ! V_179 )
return;
F_56 ( V_29 , V_181 ,
L_40 ) ;
F_105 ( V_29 , V_179 ,
V_29 -> V_81 [ V_75 ] -> V_182 -> V_8 , V_75 ,
false ) ;
F_23 ( V_29 ) ;
} else {
V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] . V_83 &= ~ V_86 ;
}
}
static void F_106 ( struct V_28 * V_29 , int V_75 ,
struct V_53 * V_179 , T_2 V_163 )
{
if ( V_163 == V_167 )
V_179 -> V_75 = V_75 ;
else
V_179 -> V_75 = 0 ;
}
static void F_107 ( struct V_28 * V_29 , int V_75 )
{
struct V_93 * V_183 ;
struct V_164 * V_165 ;
V_183 = V_29 -> V_81 [ V_75 ] ;
if ( ! V_183 )
return;
V_165 = F_97 ( V_29 , V_183 -> V_101 ) ;
F_108 ( V_165 ) ;
if ( V_29 -> V_39 & V_184 )
F_109 ( V_29 , V_183 , true ) ;
F_110 ( V_29 , V_75 ) ;
}
static void F_111 ( struct V_28 * V_29 , int V_75 ,
struct V_144 * V_145 , T_2 V_163 )
{
struct V_93 * V_183 ;
struct V_185 * V_186 ;
struct V_95 * V_96 ;
unsigned int V_76 ;
unsigned int V_83 ;
T_2 V_187 , V_188 ;
V_183 = V_29 -> V_81 [ V_75 ] ;
V_186 = F_112 ( V_183 -> V_182 ) ;
if ( ! V_186 ) {
F_51 ( V_29 , L_41 ) ;
return;
}
V_187 = F_9 ( V_186 -> V_187 ) ;
V_188 = F_9 ( V_186 -> V_188 ) ;
V_76 = F_113 ( V_187 ) - 1 ;
V_96 = F_54 ( V_29 , V_183 -> V_101 , V_76 ) ;
F_114 ( V_96 ) ;
if ( V_29 -> V_39 & V_178 &&
V_76 != ( unsigned int ) - 1 &&
V_187 - V_189 == V_188 ) {
V_83 = V_183 -> V_82 [ V_76 ] . V_83 ;
if ( ! ( V_83 & V_86 ) )
return;
F_56 ( V_29 , V_181 ,
L_42
L_43 ,
V_76 , V_83 ) ;
V_183 -> V_82 [ V_76 ] . V_83 &= ~ V_86 ;
F_48 ( V_29 , V_75 , V_76 ) ;
return;
}
return;
}
static void F_115 ( struct V_28 * V_29 , int V_75 )
{
struct V_93 * V_94 ;
struct V_164 * V_165 ;
V_94 = V_29 -> V_81 [ V_75 ] ;
V_165 = F_97 ( V_29 , V_94 -> V_101 ) ;
F_116 ( V_165 ) ;
}
static void F_117 ( struct V_28 * V_29 , int V_75 ,
struct V_144 * V_145 )
{
struct V_93 * V_94 ;
struct V_164 * V_165 ;
V_94 = V_29 -> V_81 [ V_75 ] ;
V_165 = F_97 ( V_29 , V_94 -> V_101 ) ;
F_118 ( V_165 ) ;
F_24 ( V_29 , L_44 ) ;
if ( ! V_29 -> V_81 [ V_75 ] )
F_51 ( V_29 , L_45
L_46 , V_75 ) ;
}
static void F_119 ( struct V_28 * V_29 ,
struct V_144 * V_145 )
{
if ( ! ( V_29 -> V_39 & V_190 ) ) {
F_51 ( V_29 , L_47 ) ;
return;
}
F_56 ( V_29 , V_181 ,
L_48 ,
F_120 ( F_9 ( V_145 -> V_57 ) ) ,
F_121 ( F_9 ( V_145 -> V_57 ) ) ) ;
}
static void F_122 ( struct V_53 * V_191 , T_2 V_57 )
{
F_123 ( & V_191 -> V_54 ) ;
if ( V_191 -> V_192 ) {
V_191 -> V_57 = V_57 ;
F_124 ( V_191 -> V_192 ) ;
} else {
F_125 ( V_191 ) ;
}
}
void F_45 ( struct V_28 * V_29 )
{
struct V_53 * V_55 , * V_193 ;
F_87 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_122 ( V_55 , V_58 ) ;
}
void F_126 ( struct V_194 * V_195 )
{
struct V_28 * V_29 ;
unsigned long V_67 ;
T_3 V_196 ;
V_29 = F_127 ( F_128 ( V_195 ) , struct V_28 , V_52 ) ;
F_44 ( & V_29 -> V_74 , V_67 ) ;
if ( ! V_29 -> V_65 || F_129 ( & V_29 -> V_52 ) ) {
F_41 ( & V_29 -> V_74 , V_67 ) ;
return;
}
V_29 -> V_65 -> V_57 = V_58 ;
V_196 = F_35 ( V_29 , & V_29 -> V_71 -> V_62 ) ;
if ( V_196 == ~ ( T_3 ) 0 ) {
F_40 ( V_29 ) ;
goto V_197;
}
if ( ( V_29 -> V_45 & V_46 ) &&
( V_196 & V_73 ) ) {
V_29 -> V_45 = V_198 ;
F_24 ( V_29 , L_49 ) ;
F_33 ( V_29 , V_67 ) ;
goto V_197;
}
if ( V_29 -> V_63 & V_157 ) {
F_24 ( V_29 , L_50 ) ;
F_45 ( V_29 ) ;
goto V_197;
}
F_24 ( V_29 , L_51 ) ;
F_31 ( V_29 , V_29 -> V_65 ) ;
V_197:
F_41 ( & V_29 -> V_74 , V_67 ) ;
return;
}
static void F_130 ( struct V_28 * V_29 ,
struct V_144 * V_145 )
{
int V_75 = F_131 ( F_9 ( V_145 -> V_67 ) ) ;
T_3 V_199 ;
T_1 V_200 ;
T_2 V_163 ;
union V_3 * V_201 ;
struct V_53 * V_191 ;
T_2 V_202 ;
V_199 = F_53 ( V_145 -> V_201 ) ;
V_201 = V_29 -> V_62 -> V_32 ;
F_132 ( V_29 -> V_62 , & V_201 -> V_9 ) ;
V_200 = F_1 ( V_29 -> V_62 -> V_31 ,
V_201 ) ;
if ( ! V_200 || V_199 != ( T_3 ) V_200 ) {
F_51 ( V_29 ,
L_52 ) ;
return;
}
V_191 = F_85 ( & V_29 -> V_54 , struct V_53 , V_54 ) ;
F_133 ( & V_29 -> V_52 ) ;
V_163 = F_134 ( F_9 ( V_145 -> V_57 ) ) ;
if ( V_163 == V_59 ) {
F_135 ( & V_29 -> V_70 ) ;
return;
}
if ( V_191 -> V_60 != V_29 -> V_62 -> V_32 ) {
F_38 ( V_29 ,
L_53 ) ;
return;
}
if ( V_163 == V_58 ) {
V_29 -> V_45 = V_203 ;
if ( V_191 -> V_57 == V_58 ) {
if ( V_29 -> V_65 == V_191 )
V_29 -> V_65 = NULL ;
goto V_204;
}
}
V_202 = F_136 ( F_9 ( V_201 -> V_9 . V_10 [ 3 ] ) ) ;
switch ( V_202 ) {
case V_205 :
F_106 ( V_29 , V_75 , V_191 , V_163 ) ;
break;
case V_206 :
F_107 ( V_29 , V_75 ) ;
break;
case V_207 :
if ( ! V_191 -> V_192 )
F_111 ( V_29 , V_75 , V_145 ,
V_163 ) ;
break;
case V_208 :
break;
case V_209 :
F_115 ( V_29 , V_75 ) ;
break;
case V_210 :
F_137 ( V_75 != F_131 (
F_9 ( V_201 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_75 ( V_29 , V_75 , V_201 , V_145 ) ;
break;
case V_211 :
F_137 ( V_75 != F_131 (
F_9 ( V_201 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_94 ( V_29 , V_75 , V_201 , V_163 ) ;
break;
case V_61 :
if ( V_191 -> V_57 == V_59 )
V_163 = V_59 ;
break;
case V_212 :
F_137 ( V_75 != F_131 (
F_9 ( V_201 -> V_9 . V_10 [ 3 ] ) ) ) ;
F_102 ( V_29 , V_75 , V_201 , V_163 ) ;
break;
case V_213 :
V_75 = F_131 (
F_9 ( V_201 -> V_9 . V_10 [ 3 ] ) ) ;
F_117 ( V_29 , V_75 , V_145 ) ;
break;
case V_214 :
F_119 ( V_29 , V_145 ) ;
break;
default:
F_138 ( V_29 , L_54 , V_202 ) ;
break;
}
if ( ! F_139 ( & V_29 -> V_54 ) ) {
V_29 -> V_65 = F_85 ( & V_191 -> V_54 ,
struct V_53 , V_54 ) ;
F_27 ( V_29 , V_66 ) ;
} else if ( V_29 -> V_65 == V_191 ) {
V_29 -> V_65 = NULL ;
}
V_204:
F_122 ( V_191 , V_163 ) ;
F_16 ( V_29 , V_29 -> V_62 ) ;
}
static void F_140 ( struct V_28 * V_29 ,
union V_3 * V_145 )
{
T_2 V_215 ;
V_215 = F_136 ( F_9 ( V_145 -> V_9 . V_10 [ 3 ] ) ) ;
F_24 ( V_29 , L_55 , V_215 ) ;
if ( V_215 == V_216 && ( V_29 -> V_39 & V_190 ) )
F_130 ( V_29 , & V_145 -> V_217 ) ;
}
static unsigned int F_141 ( struct V_124 * V_125 ,
struct V_28 * V_29 , T_2 V_218 )
{
unsigned int V_154 ;
unsigned int V_219 = 0 ;
for ( V_154 = 0 ; V_154 < ( V_218 - 1 ) ; V_154 ++ ) {
T_6 V_220 = V_29 -> V_221 [ V_154 ] ;
if ( V_220 == 0 || V_220 == V_222 )
continue;
if ( ( V_220 == 0x03 ) == ( V_125 -> V_223 >= V_224 ) )
V_219 ++ ;
}
return V_219 ;
}
static void F_142 ( struct V_28 * V_29 ,
union V_3 * V_145 )
{
T_2 V_75 ;
struct V_225 * V_226 ;
V_75 = F_131 ( F_9 ( V_145 -> V_9 . V_10 [ 3 ] ) ) ;
if ( ! V_29 -> V_81 [ V_75 ] ) {
F_51 ( V_29 , L_56
L_57 , V_75 ) ;
return;
}
F_24 ( V_29 , L_58 ,
V_75 ) ;
V_226 = V_29 -> V_81 [ V_75 ] -> V_226 ;
if ( V_226 && V_226 -> V_227 )
F_143 ( V_226 -> V_227 , V_226 -> V_228 ) ;
}
static void F_144 ( struct V_28 * V_29 ,
union V_3 * V_145 )
{
struct V_124 * V_125 ;
T_2 V_218 ;
T_2 V_229 , V_230 ;
int V_231 ;
int V_75 ;
unsigned int V_232 ;
T_6 V_233 ;
struct V_234 * V_235 ;
T_4 T_5 * * V_221 ;
bool V_236 = false ;
if ( F_134 ( F_9 ( V_145 -> V_9 . V_10 [ 2 ] ) ) != V_167 )
F_51 ( V_29 ,
L_59 ) ;
V_218 = F_145 ( F_9 ( V_145 -> V_9 . V_10 [ 0 ] ) ) ;
F_24 ( V_29 , L_60 , V_218 ) ;
V_231 = F_146 ( V_29 -> V_156 ) ;
if ( ( V_218 <= 0 ) || ( V_218 > V_231 ) ) {
F_51 ( V_29 , L_61 , V_218 ) ;
F_16 ( V_29 , V_29 -> V_237 ) ;
return;
}
V_233 = V_29 -> V_221 [ V_218 - 1 ] ;
V_125 = F_63 ( V_29 ) ;
if ( ( V_233 == 0x03 ) != ( V_125 -> V_223 >= V_224 ) )
V_125 = V_29 -> V_238 ;
if ( V_233 == 0 ) {
F_51 ( V_29 , L_62
L_63 ,
V_218 ) ;
V_236 = true ;
goto V_166;
}
if ( V_233 == V_222 ) {
F_51 ( V_29 , L_64
L_63 ,
V_218 ) ;
V_236 = true ;
goto V_166;
}
V_235 = & V_29 -> V_235 [ F_147 ( V_125 ) ] ;
if ( V_125 -> V_223 >= V_224 )
V_221 = V_29 -> V_239 ;
else
V_221 = V_29 -> V_240 ;
V_232 = F_141 ( V_125 , V_29 ,
V_218 ) ;
V_229 = F_26 ( V_221 [ V_232 ] ) ;
if ( V_125 -> V_105 == V_241 ) {
F_24 ( V_29 , L_65 ) ;
F_148 ( V_125 ) ;
}
if ( V_125 -> V_223 >= V_224 && ( V_229 & V_242 ) == V_243 )
V_235 -> V_244 &= ~ ( 1 << V_232 ) ;
if ( ( V_229 & V_245 ) && ( V_229 & V_242 ) == V_246 ) {
F_24 ( V_29 , L_66 , V_218 ) ;
V_230 = F_26 ( & V_29 -> V_71 -> V_179 ) ;
if ( ! ( V_230 & V_247 ) ) {
F_51 ( V_29 , L_67 ) ;
goto V_166;
}
if ( F_149 ( V_229 ) ) {
F_24 ( V_29 , L_68 , V_218 ) ;
V_235 -> V_244 |= 1 << V_232 ;
F_150 ( V_29 , V_221 ,
V_232 , V_245 ) ;
F_151 ( V_29 , V_221 , V_232 ,
V_248 ) ;
V_236 = true ;
goto V_166;
} else if ( ! F_152 ( V_232 ,
& V_235 -> V_249 ) ) {
F_24 ( V_29 , L_69 , V_218 ) ;
V_235 -> V_250 [ V_232 ] = V_251 +
F_43 ( V_252 ) ;
F_153 ( V_232 , & V_235 -> V_249 ) ;
F_154 ( & V_125 -> V_253 ,
V_235 -> V_250 [ V_232 ] ) ;
}
}
if ( ( V_229 & V_245 ) && ( V_229 & V_242 ) == V_248 &&
F_149 ( V_229 ) ) {
F_24 ( V_29 , L_70 , V_218 ) ;
V_75 = F_155 ( V_125 , V_29 ,
V_232 + 1 ) ;
if ( V_75 && V_29 -> V_81 [ V_75 ] )
F_156 ( V_29 , V_75 ) ;
if ( V_235 -> V_244 & ( 1 << V_232 ) ) {
V_235 -> V_244 &=
~ ( 1 << V_232 ) ;
F_150 ( V_29 , V_221 ,
V_232 , V_245 ) ;
F_143 ( V_125 -> V_129 . V_254 ,
V_232 + 1 ) ;
V_236 = true ;
goto V_166;
}
}
if ( ! F_149 ( V_229 ) &&
F_157 ( V_232 ,
& V_235 -> V_255 ) ) {
F_124 ( & V_235 -> V_256 [ V_232 ] ) ;
V_236 = true ;
goto V_166;
}
if ( V_125 -> V_223 < V_224 )
F_150 ( V_29 , V_221 , V_232 ,
V_245 ) ;
V_166:
F_16 ( V_29 , V_29 -> V_237 ) ;
if ( V_236 )
return;
F_24 ( V_29 , L_71 , V_257 ) ;
F_153 ( V_258 , & V_125 -> V_67 ) ;
F_67 ( & V_29 -> V_74 ) ;
F_158 ( V_125 ) ;
F_70 ( & V_29 -> V_74 ) ;
}
struct V_1 * F_82 ( struct V_28 * V_29 ,
struct V_1 * V_120 ,
union V_3 * V_259 ,
union V_3 * V_260 ,
T_1 V_261 ,
bool V_262 )
{
T_1 V_263 ;
T_1 V_264 ;
T_1 V_265 ;
struct V_1 * V_266 ;
V_263 = F_1 ( V_120 , V_259 ) ;
V_266 = V_120 ;
do {
if ( V_263 == 0 )
return NULL ;
V_264 = F_1 ( V_266 ,
& V_266 -> V_6 [ V_7 - 1 ] ) ;
V_265 = F_1 ( V_266 , V_260 ) ;
if ( V_262 )
F_51 ( V_29 ,
L_72 ,
( unsigned long long ) V_261 ,
( unsigned long long ) V_263 ,
( unsigned long long ) V_265 ,
( unsigned long long ) V_266 -> V_8 ,
( unsigned long long ) V_264 ) ;
if ( V_265 > 0 ) {
if ( V_263 <= V_265 ) {
if ( V_261 >= V_263 && V_261 <= V_265 )
return V_266 ;
} else {
if ( ( V_261 >= V_263 &&
V_261 <= V_264 ) ||
( V_261 >= V_266 -> V_8 &&
V_261 <= V_265 ) )
return V_266 ;
}
return NULL ;
} else {
if ( V_261 >= V_263 && V_261 <= V_264 )
return V_266 ;
}
V_266 = V_266 -> V_15 ;
V_263 = F_1 ( V_266 , & V_266 -> V_6 [ 0 ] ) ;
} while ( V_266 != V_120 );
return NULL ;
}
static void F_159 ( struct V_28 * V_29 ,
unsigned int V_75 , unsigned int V_76 ,
unsigned int V_77 ,
struct V_18 * V_19 , union V_3 * V_267 ,
enum V_268 V_269 )
{
struct V_79 * V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
struct V_53 * V_179 ;
V_179 = F_104 ( V_29 , false , false , V_180 ) ;
if ( ! V_179 )
return;
V_80 -> V_83 |= V_86 ;
F_160 ( V_29 , V_179 , V_75 , V_76 , V_269 ) ;
if ( V_269 == V_270 )
F_161 ( V_29 , V_76 , V_77 , V_19 ) ;
F_23 ( V_29 ) ;
}
static int F_162 ( struct V_28 * V_29 ,
struct V_95 * V_96 ,
unsigned int V_271 )
{
if ( V_271 == V_272 ||
V_271 == V_273 ||
V_271 == V_274 )
if ( F_100 ( V_96 ) == V_275 )
return 1 ;
return 0 ;
}
int F_163 ( struct V_28 * V_29 , unsigned int V_271 )
{
if ( V_271 >= 224 && V_271 <= 255 ) {
F_24 ( V_29 , L_73 ,
V_271 ) ;
F_24 ( V_29 , L_74 ) ;
return 1 ;
}
return 0 ;
}
static int F_164 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_13 * V_107 , int * V_57 )
{
struct V_20 * V_20 ;
struct V_21 * V_21 = NULL ;
V_21 = V_19 -> V_21 ;
V_20 = V_21 -> V_22 ;
F_71 ( V_29 , V_107 , V_19 ) ;
if ( V_21 -> V_276 > V_21 -> V_277 ) {
F_51 ( V_29 , L_75 ,
V_21 -> V_277 , V_21 -> V_276 ) ;
V_21 -> V_276 = 0 ;
* V_57 = 0 ;
}
F_83 ( & V_19 -> V_88 ) ;
if ( ! F_49 ( & V_19 -> V_149 ) )
F_83 ( & V_19 -> V_149 ) ;
F_11 ( V_21 ) ;
if ( F_10 ( V_19 ) ) {
if ( ( V_21 -> V_276 != V_21 -> V_277 &&
( V_21 -> V_278 & V_279 ) ) ||
( * V_57 != 0 && ! F_165 ( & V_21 -> V_80 -> V_280 ) ) )
F_24 ( V_29 , L_76 ,
V_21 , V_21 -> V_276 ,
V_21 -> V_277 , * V_57 ) ;
if ( F_62 ( V_21 -> V_127 ) == V_128 )
* V_57 = 0 ;
F_60 ( V_29 , V_19 , * V_57 ) ;
}
return 0 ;
}
static int F_166 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_267 , struct V_281 * V_145 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_93 * V_282 ;
struct V_95 * V_96 ;
struct V_13 * V_107 ;
unsigned int V_75 ;
T_2 V_271 ;
int V_76 ;
V_75 = F_131 ( F_9 ( V_145 -> V_67 ) ) ;
V_282 = V_29 -> V_81 [ V_75 ] ;
V_76 = F_167 ( F_9 ( V_145 -> V_67 ) ) - 1 ;
V_107 = F_168 ( V_80 , F_53 ( V_145 -> V_283 ) ) ;
V_96 = F_54 ( V_29 , V_282 -> V_101 , V_76 ) ;
V_271 = F_134 ( F_9 ( V_145 -> V_284 ) ) ;
if ( V_271 == V_285 ||
V_271 == V_286 ||
V_271 == V_287 ) {
return 0 ;
}
if ( V_271 == V_288 ||
F_162 ( V_29 , V_96 ,
V_271 ) ) {
F_159 ( V_29 , V_75 , V_76 ,
V_107 -> V_77 , V_19 , V_267 ,
V_270 ) ;
} else {
while ( V_107 -> V_32 != V_19 -> V_116 )
F_16 ( V_29 , V_107 ) ;
F_16 ( V_29 , V_107 ) ;
}
return F_164 ( V_29 , V_19 , V_107 , V_57 ) ;
}
static int F_169 ( struct V_28 * V_29 , struct V_13 * V_14 ,
union V_3 * V_289 )
{
T_2 V_290 ;
union V_3 * V_4 = V_14 -> V_32 ;
struct V_1 * V_2 = V_14 -> V_31 ;
for ( V_290 = 0 ; V_4 != V_289 ; F_15 ( V_29 , V_14 , & V_2 , & V_4 ) ) {
if ( ! F_2 ( V_4 ) && ! F_4 ( V_4 ) )
V_290 += F_170 ( F_9 ( V_4 -> V_9 . V_10 [ 2 ] ) ) ;
}
return V_290 ;
}
static int F_171 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_267 , struct V_281 * V_145 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_93 * V_282 ;
struct V_13 * V_107 ;
unsigned int V_75 ;
int V_76 ;
struct V_95 * V_96 ;
T_2 V_271 ;
T_2 V_291 , V_292 ;
T_2 V_215 ;
V_215 = F_136 ( F_9 ( V_267 -> V_9 . V_10 [ 3 ] ) ) ;
V_75 = F_131 ( F_9 ( V_145 -> V_67 ) ) ;
V_282 = V_29 -> V_81 [ V_75 ] ;
V_76 = F_167 ( F_9 ( V_145 -> V_67 ) ) - 1 ;
V_107 = F_168 ( V_80 , F_53 ( V_145 -> V_283 ) ) ;
V_96 = F_54 ( V_29 , V_282 -> V_101 , V_76 ) ;
V_271 = F_134 ( F_9 ( V_145 -> V_284 ) ) ;
V_292 = V_19 -> V_21 -> V_277 ;
V_291 = F_172 ( F_9 ( V_145 -> V_284 ) ) ;
switch ( V_271 ) {
case V_167 :
if ( V_215 != V_293 ) {
F_51 ( V_29 , L_77 ,
( V_215 == V_294 ) ? L_78 : L_79 ) ;
* V_57 = - V_152 ;
break;
}
* V_57 = 0 ;
break;
case V_295 :
* V_57 = 0 ;
break;
case V_287 :
if ( V_215 == V_294 || V_215 == V_296 )
V_19 -> V_21 -> V_276 = V_291 ;
else
F_51 ( V_29 , L_80 ) ;
goto F_166;
case V_286 :
switch ( V_215 ) {
case V_297 :
V_19 -> V_21 -> V_276 = 0 ;
goto F_166;
case V_294 :
case V_296 :
V_19 -> V_21 -> V_276 = V_292 - V_291 ;
goto F_166;
case V_293 :
V_19 -> V_21 -> V_276 = V_292 ;
goto F_166;
default:
F_51 ( V_29 , L_81 ,
V_215 ) ;
goto F_166;
}
case V_285 :
goto F_166;
default:
if ( ! F_162 ( V_29 ,
V_96 , V_271 ) )
break;
F_24 ( V_29 , L_82 ,
V_271 , V_76 ) ;
case V_288 :
if ( V_215 == V_294 || V_215 == V_296 )
V_19 -> V_21 -> V_276 = V_292 - V_291 ;
else if ( ! V_19 -> V_298 )
V_19 -> V_21 -> V_276 = 0 ;
goto F_166;
}
if ( V_215 == V_297 )
goto F_166;
if ( V_215 == V_294 ||
V_215 == V_296 ) {
V_19 -> V_298 = true ;
V_19 -> V_21 -> V_276 = V_292 - V_291 ;
F_24 ( V_29 , L_83 ) ;
return 0 ;
}
if ( ! V_19 -> V_298 )
V_19 -> V_21 -> V_276 = V_292 ;
F_166:
return F_166 ( V_29 , V_19 , V_267 , V_145 , V_80 , V_57 ) ;
}
static int F_173 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_267 , struct V_281 * V_145 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_13 * V_107 ;
struct V_20 * V_20 ;
int V_299 ;
struct V_300 * V_301 ;
T_2 V_271 ;
bool V_302 = false ;
T_2 V_291 , V_292 , V_303 ;
int V_304 ;
V_107 = F_168 ( V_80 , F_53 ( V_145 -> V_283 ) ) ;
V_271 = F_134 ( F_9 ( V_145 -> V_284 ) ) ;
V_20 = V_19 -> V_21 -> V_22 ;
V_299 = V_20 -> V_23 ;
V_301 = & V_19 -> V_21 -> V_305 [ V_299 ] ;
V_292 = V_301 -> V_306 ;
V_291 = F_172 ( F_9 ( V_145 -> V_284 ) ) ;
V_303 = F_170 ( F_9 ( V_267 -> V_9 . V_10 [ 2 ] ) ) ;
V_304 = V_19 -> V_21 -> V_278 & V_279 ?
- V_307 : 0 ;
switch ( V_271 ) {
case V_167 :
if ( V_291 ) {
V_301 -> V_57 = V_304 ;
if ( V_29 -> V_39 & V_308 )
V_302 = true ;
break;
}
V_301 -> V_57 = 0 ;
break;
case V_295 :
V_301 -> V_57 = V_304 ;
V_302 = true ;
break;
case V_309 :
V_301 -> V_57 = - V_310 ;
break;
case V_311 :
case V_273 :
V_301 -> V_57 = - V_312 ;
break;
case V_313 :
case V_288 :
V_301 -> V_57 = - V_314 ;
break;
case V_272 :
V_301 -> V_57 = - V_314 ;
if ( V_267 != V_19 -> V_116 )
return 0 ;
break;
case V_286 :
V_302 = true ;
break;
case V_287 :
V_301 -> V_57 = V_304 ;
V_292 = V_291 ;
break;
case V_285 :
V_292 = 0 ;
V_291 = 0 ;
break;
default:
V_302 = true ;
V_301 -> V_57 = - 1 ;
break;
}
if ( V_302 )
V_301 -> V_276 = F_169 ( V_29 , V_107 , V_267 ) +
V_303 - V_291 ;
else
V_301 -> V_276 = V_292 ;
V_19 -> V_21 -> V_276 += V_301 -> V_276 ;
return F_166 ( V_29 , V_19 , V_267 , V_145 , V_80 , V_57 ) ;
}
static int F_174 ( struct V_28 * V_29 , struct V_18 * V_19 ,
struct V_281 * V_145 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_13 * V_107 ;
struct V_20 * V_20 ;
struct V_300 * V_301 ;
int V_299 ;
V_107 = F_168 ( V_80 , F_53 ( V_145 -> V_283 ) ) ;
V_20 = V_19 -> V_21 -> V_22 ;
V_299 = V_20 -> V_23 ;
V_301 = & V_19 -> V_21 -> V_305 [ V_299 ] ;
V_301 -> V_57 = - V_315 ;
V_301 -> V_276 = 0 ;
while ( V_107 -> V_32 != V_19 -> V_116 )
F_16 ( V_29 , V_107 ) ;
F_16 ( V_29 , V_107 ) ;
return F_164 ( V_29 , V_19 , V_107 , V_57 ) ;
}
static int F_175 ( struct V_28 * V_29 , struct V_18 * V_19 ,
union V_3 * V_267 , struct V_281 * V_145 ,
struct V_79 * V_80 , int * V_57 )
{
struct V_13 * V_107 ;
T_2 V_271 ;
T_2 V_291 , V_292 , V_303 ;
V_107 = F_168 ( V_80 , F_53 ( V_145 -> V_283 ) ) ;
V_271 = F_134 ( F_9 ( V_145 -> V_284 ) ) ;
V_291 = F_172 ( F_9 ( V_145 -> V_284 ) ) ;
V_303 = F_170 ( F_9 ( V_267 -> V_9 . V_10 [ 2 ] ) ) ;
V_292 = V_19 -> V_21 -> V_277 ;
switch ( V_271 ) {
case V_167 :
if ( V_267 != V_19 -> V_116 || V_291 ) {
F_51 ( V_29 , L_84 ) ;
F_24 ( V_29 , L_85 ,
V_19 -> V_21 -> V_80 -> V_280 . V_316 ,
V_292 , V_291 ) ;
}
* V_57 = 0 ;
break;
case V_295 :
F_24 ( V_29 , L_85 ,
V_19 -> V_21 -> V_80 -> V_280 . V_316 ,
V_292 , V_291 ) ;
* V_57 = 0 ;
break;
case V_287 :
V_19 -> V_21 -> V_276 = V_291 ;
goto F_166;
case V_285 :
V_303 = 0 ;
V_291 = 0 ;
break;
default:
break;
}
if ( V_267 == V_19 -> V_116 )
V_19 -> V_21 -> V_276 = V_292 - V_291 ;
else
V_19 -> V_21 -> V_276 =
F_169 ( V_29 , V_107 , V_267 ) +
V_303 - V_291 ;
F_166:
if ( V_291 > V_292 ) {
F_51 ( V_29 , L_86 ,
V_291 ) ;
V_19 -> V_21 -> V_276 = 0 ;
}
return F_166 ( V_29 , V_19 , V_267 , V_145 , V_80 , V_57 ) ;
}
static int F_176 ( struct V_28 * V_29 ,
struct V_281 * V_145 )
{
struct V_93 * V_282 ;
struct V_79 * V_80 ;
struct V_13 * V_107 ;
unsigned int V_75 ;
int V_76 ;
struct V_18 * V_19 = NULL ;
T_1 V_317 ;
struct V_1 * V_318 ;
union V_3 * V_267 ;
int V_57 = - V_319 ;
struct V_95 * V_96 ;
struct V_320 * V_151 ;
T_2 V_271 ;
int V_321 = 0 ;
bool V_322 = false ;
V_75 = F_131 ( F_9 ( V_145 -> V_67 ) ) ;
V_76 = F_167 ( F_9 ( V_145 -> V_67 ) ) - 1 ;
V_271 = F_134 ( F_9 ( V_145 -> V_284 ) ) ;
V_317 = F_53 ( V_145 -> V_283 ) ;
V_282 = V_29 -> V_81 [ V_75 ] ;
if ( ! V_282 ) {
F_38 ( V_29 , L_87 ,
V_75 ) ;
goto V_323;
}
V_80 = & V_282 -> V_82 [ V_76 ] ;
V_107 = F_168 ( V_80 , V_317 ) ;
V_96 = F_54 ( V_29 , V_282 -> V_101 , V_76 ) ;
if ( F_100 ( V_96 ) == V_324 ) {
F_38 ( V_29 ,
L_88 ,
V_75 , V_76 ) ;
goto V_323;
}
if ( ! V_107 ) {
switch ( V_271 ) {
case V_288 :
case V_272 :
case V_325 :
case V_326 :
F_159 ( V_29 , V_75 , V_76 , 0 ,
NULL , NULL , V_327 ) ;
goto V_166;
case V_328 :
case V_329 :
goto V_166;
default:
F_38 ( V_29 , L_89 ,
V_75 , V_76 ) ;
goto V_323;
}
}
if ( V_80 -> V_330 ) {
F_177 (tmp, &ep_ring->td_list)
V_321 ++ ;
}
switch ( V_271 ) {
case V_167 :
if ( F_172 ( F_9 ( V_145 -> V_284 ) ) == 0 )
break;
if ( V_29 -> V_39 & V_308 )
V_271 = V_295 ;
else
F_178 ( V_29 ,
L_90 ,
V_75 , V_76 ) ;
case V_295 :
break;
case V_286 :
F_24 ( V_29 , L_91 ,
V_75 , V_76 ) ;
break;
case V_285 :
F_24 ( V_29 ,
L_92 ,
V_75 , V_76 ) ;
break;
case V_287 :
F_24 ( V_29 ,
L_93 ,
V_75 , V_76 ) ;
break;
case V_288 :
F_24 ( V_29 , L_94 , V_75 ,
V_76 ) ;
V_80 -> V_83 |= V_86 ;
V_57 = - V_331 ;
break;
case V_274 :
case V_272 :
F_24 ( V_29 , L_95 ,
V_75 , V_76 ) ;
V_57 = - V_314 ;
break;
case V_273 :
F_24 ( V_29 , L_96 ,
V_75 , V_76 ) ;
V_57 = - V_312 ;
break;
case V_169 :
F_51 ( V_29 ,
L_97 ,
V_75 , V_76 ) ;
V_57 = - V_332 ;
break;
case V_333 :
F_51 ( V_29 ,
L_98 ,
V_75 , V_76 ) ;
V_57 = - V_334 ;
break;
case V_309 :
F_51 ( V_29 ,
L_99 ,
V_75 , V_76 ) ;
break;
case V_311 :
F_51 ( V_29 ,
L_100 ,
V_75 , V_76 ) ;
break;
case V_328 :
F_24 ( V_29 , L_101 ) ;
if ( ! F_49 ( & V_107 -> V_88 ) )
F_24 ( V_29 , L_102
L_103 ,
F_131 ( F_9 ( V_145 -> V_67 ) ) ,
V_76 ) ;
goto V_166;
case V_329 :
F_24 ( V_29 , L_104 ) ;
if ( ! F_49 ( & V_107 -> V_88 ) )
F_24 ( V_29 , L_105
L_103 ,
F_131 ( F_9 ( V_145 -> V_67 ) ) ,
V_76 ) ;
goto V_166;
case V_335 :
V_80 -> V_330 = true ;
F_24 ( V_29 ,
L_106 ,
V_75 , V_76 ) ;
goto V_166;
case V_336 :
V_80 -> V_330 = true ;
F_24 ( V_29 ,
L_107 ,
V_75 , V_76 ) ;
goto V_166;
case V_313 :
F_51 ( V_29 ,
L_108 ,
V_75 , V_76 ) ;
V_57 = - V_314 ;
break;
default:
if ( F_163 ( V_29 , V_271 ) ) {
V_57 = 0 ;
break;
}
F_51 ( V_29 ,
L_109 ,
V_271 , V_75 , V_76 ) ;
goto V_166;
}
do {
if ( F_49 ( & V_107 -> V_88 ) ) {
if ( ! ( V_271 == V_286 ||
V_271 == V_285 ) ) {
F_51 ( V_29 , L_110 ,
F_131 ( F_9 ( V_145 -> V_67 ) ) ,
V_76 ) ;
}
if ( V_80 -> V_330 ) {
V_80 -> V_330 = false ;
F_24 ( V_29 , L_111 ,
V_75 , V_76 ) ;
}
goto V_166;
}
if ( V_80 -> V_330 && V_321 == 0 ) {
V_80 -> V_330 = false ;
F_24 ( V_29 , L_112 ,
V_75 , V_76 ) ;
goto V_166;
}
V_19 = F_85 ( & V_107 -> V_88 , struct V_18 ,
V_88 ) ;
if ( V_80 -> V_330 )
V_321 -- ;
V_318 = F_82 ( V_29 , V_107 -> V_31 , V_107 -> V_32 ,
V_19 -> V_116 , V_317 , false ) ;
if ( ! V_318 && ( V_271 == V_286 ||
V_271 == V_285 ) ) {
goto V_166;
}
if ( ! V_318 ) {
if ( ! V_80 -> V_330 ||
! F_165 ( & V_19 -> V_21 -> V_80 -> V_280 ) ) {
if ( ( V_29 -> V_39 & V_337 ) &&
V_107 -> V_338 ) {
V_107 -> V_338 = false ;
goto V_166;
}
F_38 ( V_29 ,
L_113
L_114
L_115 , V_76 ,
V_271 ) ;
F_82 ( V_29 , V_107 -> V_31 ,
V_107 -> V_32 , V_19 -> V_116 ,
V_317 , true ) ;
return - V_152 ;
}
F_174 ( V_29 , V_19 , V_145 , V_80 , & V_57 ) ;
goto V_166;
}
if ( V_271 == V_295 )
V_107 -> V_338 = true ;
else
V_107 -> V_338 = false ;
if ( V_80 -> V_330 ) {
F_24 ( V_29 ,
L_116 ,
V_75 , V_76 ) ;
V_80 -> V_330 = false ;
}
V_267 = & V_318 -> V_6 [ ( V_317 - V_318 -> V_8 ) /
sizeof( * V_267 ) ] ;
F_179 ( V_107 ,
(struct V_339 * ) V_267 ) ;
if ( F_2 ( V_267 ) ) {
F_24 ( V_29 ,
L_117 ,
V_75 , V_76 ) ;
goto V_166;
}
if ( F_180 ( & V_19 -> V_21 -> V_80 -> V_280 ) )
F_171 ( V_29 , V_19 , V_267 , V_145 , V_80 , & V_57 ) ;
else if ( F_165 ( & V_19 -> V_21 -> V_80 -> V_280 ) )
F_173 ( V_29 , V_19 , V_267 , V_145 , V_80 , & V_57 ) ;
else
F_175 ( V_29 , V_19 , V_267 , V_145 , V_80 ,
& V_57 ) ;
V_166:
V_322 = V_80 -> V_330 &&
V_271 != V_335 &&
V_271 != V_336 ;
if ( ! V_322 )
F_16 ( V_29 , V_29 -> V_237 ) ;
} while ( V_322 );
return 0 ;
V_323:
F_38 ( V_29 , L_118 ,
( unsigned long long ) F_1 (
V_29 -> V_237 -> V_31 ,
V_29 -> V_237 -> V_32 ) ,
F_181 ( F_53 ( V_145 -> V_283 ) ) ,
F_182 ( F_53 ( V_145 -> V_283 ) ) ,
F_9 ( V_145 -> V_284 ) ,
F_9 ( V_145 -> V_67 ) ) ;
return - V_340 ;
}
static int F_183 ( struct V_28 * V_29 )
{
union V_3 * V_145 ;
int V_341 = 1 ;
int V_69 ;
if ( ! V_29 -> V_237 || ! V_29 -> V_237 -> V_32 ) {
F_38 ( V_29 , L_119 ) ;
return - V_342 ;
}
V_145 = V_29 -> V_237 -> V_32 ;
if ( ( F_9 ( V_145 -> V_217 . V_67 ) & V_27 ) !=
V_29 -> V_237 -> V_33 )
return 0 ;
F_184 ( V_29 -> V_237 , & V_145 -> V_9 ) ;
F_185 () ;
switch ( F_9 ( V_145 -> V_217 . V_67 ) & V_343 ) {
case F_14 ( V_344 ) :
F_130 ( V_29 , & V_145 -> V_217 ) ;
break;
case F_14 ( V_345 ) :
F_144 ( V_29 , V_145 ) ;
V_341 = 0 ;
break;
case F_14 ( V_346 ) :
V_69 = F_176 ( V_29 , & V_145 -> V_347 ) ;
if ( V_69 >= 0 )
V_341 = 0 ;
break;
case F_14 ( V_348 ) :
F_142 ( V_29 , V_145 ) ;
break;
default:
if ( ( F_9 ( V_145 -> V_217 . V_67 ) & V_343 ) >=
F_14 ( 48 ) )
F_140 ( V_29 , V_145 ) ;
else
F_51 ( V_29 , L_120 ,
F_136 (
F_9 ( V_145 -> V_217 . V_67 ) ) ) ;
}
if ( V_29 -> V_63 & V_64 ) {
F_24 ( V_29 , L_121
L_122 ) ;
return 0 ;
}
if ( V_341 )
F_16 ( V_29 , V_29 -> V_237 ) ;
return 1 ;
}
T_7 F_186 ( struct V_124 * V_125 )
{
struct V_28 * V_29 = F_187 ( V_125 ) ;
union V_3 * V_349 ;
T_7 V_69 = V_350 ;
unsigned long V_67 ;
T_1 V_102 ;
T_3 V_68 ;
T_2 V_57 ;
F_44 ( & V_29 -> V_74 , V_67 ) ;
V_57 = F_26 ( & V_29 -> V_71 -> V_57 ) ;
if ( V_57 == ~ ( T_2 ) 0 ) {
F_40 ( V_29 ) ;
V_69 = V_351 ;
goto V_352;
}
if ( ! ( V_57 & V_353 ) )
goto V_352;
if ( V_57 & V_354 ) {
F_51 ( V_29 , L_123 ) ;
F_39 ( V_29 ) ;
V_69 = V_351 ;
goto V_352;
}
V_57 |= V_353 ;
F_25 ( V_57 , & V_29 -> V_71 -> V_57 ) ;
if ( ! V_125 -> V_355 ) {
T_2 V_356 ;
V_356 = F_26 ( & V_29 -> V_357 -> V_356 ) ;
V_356 |= V_358 ;
F_25 ( V_356 , & V_29 -> V_357 -> V_356 ) ;
}
if ( V_29 -> V_63 & V_64 ||
V_29 -> V_63 & V_359 ) {
F_24 ( V_29 , L_124
L_125 ) ;
V_68 = F_35 ( V_29 , & V_29 -> V_357 -> V_360 ) ;
F_36 ( V_29 , V_68 | V_361 ,
& V_29 -> V_357 -> V_360 ) ;
V_69 = V_351 ;
goto V_352;
}
V_349 = V_29 -> V_237 -> V_32 ;
while ( F_183 ( V_29 ) > 0 ) {}
V_68 = F_35 ( V_29 , & V_29 -> V_357 -> V_360 ) ;
if ( V_349 != V_29 -> V_237 -> V_32 ) {
V_102 = F_1 ( V_29 -> V_237 -> V_31 ,
V_29 -> V_237 -> V_32 ) ;
if ( V_102 == 0 )
F_51 ( V_29 , L_126
L_127 ) ;
V_68 &= V_362 ;
V_68 |= ( ( T_3 ) V_102 & ( T_3 ) ~ V_362 ) ;
}
V_68 |= V_361 ;
F_36 ( V_29 , V_68 , & V_29 -> V_357 -> V_360 ) ;
V_69 = V_351 ;
V_352:
F_41 ( & V_29 -> V_74 , V_67 ) ;
return V_69 ;
}
T_7 F_188 ( int V_363 , void * V_125 )
{
return F_186 ( V_125 ) ;
}
static void F_189 ( struct V_28 * V_29 , struct V_13 * V_14 ,
bool V_35 ,
T_2 V_364 , T_2 V_365 , T_2 V_366 , T_2 V_367 )
{
struct V_339 * V_4 ;
V_4 = & V_14 -> V_37 -> V_9 ;
V_4 -> V_10 [ 0 ] = F_13 ( V_364 ) ;
V_4 -> V_10 [ 1 ] = F_13 ( V_365 ) ;
V_4 -> V_10 [ 2 ] = F_13 ( V_366 ) ;
V_4 -> V_10 [ 3 ] = F_13 ( V_367 ) ;
F_190 ( V_14 , V_4 ) ;
F_18 ( V_29 , V_14 , V_35 ) ;
}
static int F_191 ( struct V_28 * V_29 , struct V_13 * V_107 ,
T_2 V_83 , unsigned int V_42 , T_8 V_368 )
{
unsigned int V_369 ;
switch ( V_83 ) {
case V_324 :
F_51 ( V_29 , L_128 ) ;
return - V_370 ;
case V_371 :
F_51 ( V_29 , L_129 ) ;
return - V_372 ;
case V_275 :
F_24 ( V_29 , L_130 ) ;
case V_373 :
case V_374 :
break;
default:
F_38 ( V_29 , L_131 ) ;
return - V_372 ;
}
while ( 1 ) {
if ( F_22 ( V_29 , V_107 , V_42 ) )
break;
if ( V_107 == V_29 -> V_62 ) {
F_38 ( V_29 , L_132 ) ;
return - V_342 ;
}
F_56 ( V_29 , V_375 ,
L_133 ) ;
V_369 = V_42 - V_107 -> V_34 ;
if ( F_192 ( V_29 , V_107 , V_369 ,
V_368 ) ) {
F_38 ( V_29 , L_134 ) ;
return - V_342 ;
}
}
while ( F_4 ( V_107 -> V_37 ) ) {
if ( ! F_19 ( V_29 ) &&
! ( V_107 -> type == V_38 &&
( V_29 -> V_39 & V_40 ) ) )
V_107 -> V_37 -> V_11 . V_12 &=
F_13 ( ~ V_26 ) ;
else
V_107 -> V_37 -> V_11 . V_12 |=
F_13 ( V_26 ) ;
F_20 () ;
V_107 -> V_37 -> V_11 . V_12 ^= F_13 ( V_27 ) ;
if ( F_8 ( V_107 -> V_37 ) )
V_107 -> V_33 ^= 1 ;
V_107 -> V_41 = V_107 -> V_41 -> V_15 ;
V_107 -> V_37 = V_107 -> V_41 -> V_6 ;
}
return 0 ;
}
static int F_193 ( struct V_28 * V_29 ,
struct V_93 * V_282 ,
unsigned int V_76 ,
unsigned int V_77 ,
unsigned int V_42 ,
struct V_21 * V_21 ,
unsigned int V_376 ,
T_8 V_368 )
{
int V_69 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
struct V_13 * V_107 ;
struct V_95 * V_96 = F_54 ( V_29 , V_282 -> V_101 , V_76 ) ;
V_107 = F_96 ( V_282 , V_76 , V_77 ) ;
if ( ! V_107 ) {
F_24 ( V_29 , L_135 ,
V_77 ) ;
return - V_372 ;
}
V_69 = F_191 ( V_29 , V_107 , F_100 ( V_96 ) ,
V_42 , V_368 ) ;
if ( V_69 )
return V_69 ;
V_20 = V_21 -> V_22 ;
V_19 = & V_20 -> V_19 [ V_376 ] ;
F_194 ( & V_19 -> V_88 ) ;
F_194 ( & V_19 -> V_149 ) ;
if ( V_376 == 0 ) {
V_69 = F_195 ( F_61 ( V_21 -> V_106 -> V_126 ) , V_21 ) ;
if ( F_76 ( V_69 ) )
return V_69 ;
}
V_19 -> V_21 = V_21 ;
F_196 ( & V_19 -> V_88 , & V_107 -> V_88 ) ;
V_19 -> V_120 = V_107 -> V_41 ;
V_19 -> V_121 = V_107 -> V_37 ;
return 0 ;
}
static unsigned int F_197 ( T_3 V_110 , T_3 V_377 )
{
unsigned int V_42 ;
V_42 = F_198 ( V_377 + ( V_110 & ( V_378 - 1 ) ) ,
V_378 ) ;
if ( V_42 == 0 )
V_42 ++ ;
return V_42 ;
}
static inline unsigned int F_199 ( struct V_21 * V_21 )
{
return F_197 ( V_21 -> V_379 , V_21 -> V_277 ) ;
}
static unsigned int F_200 ( struct V_21 * V_21 )
{
struct V_380 * V_138 ;
unsigned int V_154 , V_377 , V_381 , V_42 = 0 ;
V_381 = V_21 -> V_277 ;
F_201 (urb->sg, sg, urb->num_mapped_sgs, i) {
V_377 = F_202 ( V_138 ) ;
V_42 += F_197 ( F_203 ( V_138 ) , V_377 ) ;
V_377 = F_204 (unsigned int, len, full_len) ;
V_381 -= V_377 ;
if ( V_381 == 0 )
break;
}
return V_42 ;
}
static unsigned int F_205 ( struct V_21 * V_21 , int V_154 )
{
T_3 V_110 , V_377 ;
V_110 = ( T_3 ) ( V_21 -> V_379 + V_21 -> V_305 [ V_154 ] . V_382 ) ;
V_377 = V_21 -> V_305 [ V_154 ] . V_306 ;
return F_197 ( V_110 , V_377 ) ;
}
static void F_206 ( struct V_21 * V_21 , int V_383 )
{
if ( F_76 ( V_383 != V_21 -> V_277 ) )
F_207 ( & V_21 -> V_106 -> V_106 , L_136
L_137 ,
V_257 ,
V_21 -> V_80 -> V_280 . V_316 ,
V_383 , V_383 ,
V_21 -> V_277 ,
V_21 -> V_277 ) ;
}
static void F_208 ( struct V_28 * V_29 , int V_75 ,
unsigned int V_76 , unsigned int V_77 , int V_384 ,
struct V_339 * V_259 )
{
F_20 () ;
if ( V_384 )
V_259 -> V_10 [ 3 ] |= F_13 ( V_384 ) ;
else
V_259 -> V_10 [ 3 ] &= F_13 ( ~ V_27 ) ;
F_46 ( V_29 , V_75 , V_76 , V_77 ) ;
}
static void F_209 ( struct V_28 * V_29 , struct V_21 * V_21 ,
struct V_95 * V_96 )
{
int V_385 ;
int V_386 ;
V_385 = F_210 ( F_9 ( V_96 -> V_387 ) ) ;
V_386 = V_21 -> V_388 ;
if ( V_21 -> V_106 -> V_223 == V_389 ||
V_21 -> V_106 -> V_223 == V_390 )
V_386 *= 8 ;
if ( V_385 != V_386 ) {
F_211 ( & V_21 -> V_106 -> V_106 ,
L_138 ,
V_386 , V_386 == 1 ? L_139 : L_140 ,
V_385 , V_385 == 1 ? L_139 : L_140 ) ;
V_21 -> V_388 = V_385 ;
if ( V_21 -> V_106 -> V_223 == V_389 ||
V_21 -> V_106 -> V_223 == V_390 )
V_21 -> V_388 /= 8 ;
}
}
int F_212 ( struct V_28 * V_29 , T_8 V_368 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_95 * V_96 ;
V_96 = F_54 ( V_29 , V_29 -> V_81 [ V_75 ] -> V_101 , V_76 ) ;
F_209 ( V_29 , V_21 , V_96 ) ;
return F_213 ( V_29 , V_368 , V_21 , V_75 , V_76 ) ;
}
static T_2 F_214 ( struct V_28 * V_29 , int V_391 ,
int V_392 , unsigned int V_393 ,
struct V_21 * V_21 , bool V_35 )
{
T_2 V_394 , V_395 ;
if ( V_29 -> V_396 < 0x100 && ! ( V_29 -> V_39 & V_397 ) )
return ( ( V_393 - V_391 ) >> 10 ) ;
if ( ! V_35 || ( V_391 == 0 && V_392 == 0 ) ||
V_392 == V_393 )
return 0 ;
if ( V_29 -> V_39 & V_397 )
V_392 = 0 ;
V_394 = F_215 ( & V_21 -> V_80 -> V_280 ) ;
V_395 = F_198 ( V_393 , V_394 ) ;
return ( V_395 - ( ( V_391 + V_392 ) / V_394 ) ) ;
}
static int F_216 ( struct V_28 * V_29 , struct V_21 * V_21 , T_2 V_398 ,
T_2 * V_392 , struct V_1 * V_2 )
{
struct V_132 * V_106 = F_63 ( V_29 ) -> V_129 . V_133 ;
unsigned int V_399 ;
unsigned int V_400 ;
T_2 V_401 ;
V_400 = F_215 ( & V_21 -> V_80 -> V_280 ) ;
V_399 = ( V_398 + * V_392 ) % V_400 ;
if ( V_399 == 0 )
return 0 ;
F_24 ( V_29 , L_141 ,
V_399 , * V_392 ) ;
if ( * V_392 > V_399 ) {
* V_392 -= V_399 ;
F_24 ( V_29 , L_142 , * V_392 ) ;
return 0 ;
}
V_401 = V_400 - ( V_398 % V_400 ) ;
if ( V_401 > ( V_21 -> V_277 - V_398 ) )
V_401 = ( V_21 -> V_277 - V_398 ) ;
if ( F_72 ( V_21 ) ) {
F_217 ( V_21 -> V_138 , V_21 -> V_139 ,
V_2 -> V_140 , V_401 , V_398 ) ;
V_2 -> V_135 = F_218 ( V_106 , V_2 -> V_140 ,
V_400 , V_137 ) ;
} else {
V_2 -> V_135 = F_218 ( V_106 , V_2 -> V_140 ,
V_400 , V_143 ) ;
}
if ( F_219 ( V_106 , V_2 -> V_135 ) ) {
F_51 ( V_29 , L_143 ) ;
return 0 ;
}
* V_392 = V_401 ;
V_2 -> V_141 = V_401 ;
V_2 -> V_142 = V_398 ;
F_24 ( V_29 , L_144 , * V_392 ) ;
return 1 ;
}
int F_213 ( struct V_28 * V_29 , T_8 V_368 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_13 * V_14 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
struct V_339 * V_259 ;
struct V_380 * V_138 = NULL ;
bool V_35 = true ;
bool V_402 = false ;
bool V_121 = true ;
unsigned int V_42 ;
unsigned int V_384 , V_403 = 0 ;
unsigned int V_398 , V_404 , V_392 , V_381 ;
int V_405 , V_69 ;
T_2 V_10 , V_406 , V_407 ;
T_3 V_110 , V_408 ;
V_14 = F_81 ( V_29 , V_21 ) ;
if ( ! V_14 )
return - V_372 ;
V_381 = V_21 -> V_277 ;
if ( V_21 -> V_403 ) {
V_403 = V_21 -> V_139 ;
V_138 = V_21 -> V_138 ;
V_110 = ( T_3 ) F_203 ( V_138 ) ;
V_404 = F_202 ( V_138 ) ;
V_42 = F_200 ( V_21 ) ;
} else {
V_42 = F_199 ( V_21 ) ;
V_110 = ( T_3 ) V_21 -> V_379 ;
V_404 = V_381 ;
}
V_69 = F_193 ( V_29 , V_29 -> V_81 [ V_75 ] ,
V_76 , V_21 -> V_77 ,
V_42 , V_21 , 0 , V_368 ) ;
if ( F_76 ( V_69 < 0 ) )
return V_69 ;
V_20 = V_21 -> V_22 ;
if ( V_21 -> V_278 & V_409 && V_20 -> V_24 > 1 )
V_402 = true ;
V_19 = & V_20 -> V_19 [ 0 ] ;
V_259 = & V_14 -> V_37 -> V_9 ;
V_384 = V_14 -> V_33 ;
V_408 = V_110 ;
for ( V_398 = 0 ; V_121 || V_398 < V_381 ;
V_398 += V_392 ) {
V_10 = F_14 ( V_296 ) ;
V_392 = F_220 ( V_110 ) ;
V_392 = F_204 (unsigned int, trb_buff_len, block_len) ;
if ( V_398 + V_392 > V_381 )
V_392 = V_381 - V_398 ;
if ( V_121 ) {
V_121 = false ;
if ( V_384 == 0 )
V_10 |= V_27 ;
} else
V_10 |= V_14 -> V_33 ;
if ( V_398 + V_392 < V_381 ) {
V_10 |= V_26 ;
if ( F_4 ( V_14 -> V_37 + 1 ) ) {
if ( F_216 ( V_29 , V_21 , V_398 ,
& V_392 ,
V_14 -> V_41 ) ) {
V_408 = V_14 -> V_41 -> V_135 ;
V_19 -> V_134 = V_14 -> V_41 ;
}
}
}
if ( V_398 + V_392 >= V_381 ) {
V_10 &= ~ V_26 ;
V_10 |= V_410 ;
V_35 = false ;
V_19 -> V_116 = V_14 -> V_37 ;
}
if ( F_221 ( V_21 ) )
V_10 |= V_411 ;
V_407 = F_214 ( V_29 , V_398 , V_392 ,
V_381 , V_21 , V_35 ) ;
V_406 = F_170 ( V_392 ) |
F_222 ( V_407 ) |
F_223 ( 0 ) ;
F_189 ( V_29 , V_14 , V_35 | V_402 ,
F_181 ( V_408 ) ,
F_182 ( V_408 ) ,
V_406 ,
V_10 ) ;
V_110 += V_392 ;
V_405 = V_392 ;
while ( V_138 && V_405 >= V_404 ) {
-- V_403 ;
V_405 -= V_404 ;
if ( V_403 != 0 ) {
V_138 = F_224 ( V_138 ) ;
V_404 = F_202 ( V_138 ) ;
V_110 = ( T_3 ) F_203 ( V_138 ) ;
V_110 += V_405 ;
}
}
V_404 -= V_405 ;
V_408 = V_110 ;
}
if ( V_402 ) {
V_69 = F_193 ( V_29 , V_29 -> V_81 [ V_75 ] ,
V_76 , V_21 -> V_77 ,
1 , V_21 , 1 , V_368 ) ;
V_20 -> V_19 [ 1 ] . V_116 = V_14 -> V_37 ;
V_10 = F_14 ( V_296 ) | V_14 -> V_33 | V_410 ;
F_189 ( V_29 , V_14 , 0 , 0 , 0 , F_223 ( 0 ) , V_10 ) ;
}
F_206 ( V_21 , V_398 ) ;
F_208 ( V_29 , V_75 , V_76 , V_21 -> V_77 ,
V_384 , V_259 ) ;
return 0 ;
}
int F_225 ( struct V_28 * V_29 , T_8 V_368 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_13 * V_107 ;
int V_42 ;
int V_69 ;
struct V_412 * V_413 ;
struct V_339 * V_259 ;
int V_384 ;
T_2 V_10 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
V_107 = F_81 ( V_29 , V_21 ) ;
if ( ! V_107 )
return - V_372 ;
if ( ! V_21 -> V_414 )
return - V_372 ;
V_42 = 2 ;
if ( V_21 -> V_277 > 0 )
V_42 ++ ;
V_69 = F_193 ( V_29 , V_29 -> V_81 [ V_75 ] ,
V_76 , V_21 -> V_77 ,
V_42 , V_21 , 0 , V_368 ) ;
if ( V_69 < 0 )
return V_69 ;
V_20 = V_21 -> V_22 ;
V_19 = & V_20 -> V_19 [ 0 ] ;
V_259 = & V_107 -> V_37 -> V_9 ;
V_384 = V_107 -> V_33 ;
V_413 = (struct V_412 * ) V_21 -> V_414 ;
V_10 = 0 ;
V_10 |= V_415 | F_14 ( V_297 ) ;
if ( V_384 == 0 )
V_10 |= 0x1 ;
if ( ( V_29 -> V_396 >= 0x100 ) || ( V_29 -> V_39 & V_397 ) ) {
if ( V_21 -> V_277 > 0 ) {
if ( V_413 -> V_416 & V_417 )
V_10 |= F_226 ( V_418 ) ;
else
V_10 |= F_226 ( V_419 ) ;
}
}
F_189 ( V_29 , V_107 , true ,
V_413 -> V_416 | V_413 -> V_420 << 8 | F_227 ( V_413 -> V_421 ) << 16 ,
F_227 ( V_413 -> V_422 ) | F_227 ( V_413 -> V_423 ) << 16 ,
F_170 ( 8 ) | F_223 ( 0 ) ,
V_10 ) ;
if ( F_221 ( V_21 ) )
V_10 = V_411 | F_14 ( V_294 ) ;
else
V_10 = F_14 ( V_294 ) ;
if ( V_21 -> V_277 > 0 ) {
T_2 V_406 , V_407 ;
V_407 = F_214 ( V_29 , 0 ,
V_21 -> V_277 ,
V_21 -> V_277 ,
V_21 , 1 ) ;
V_406 = F_170 ( V_21 -> V_277 ) |
F_222 ( V_407 ) |
F_223 ( 0 ) ;
if ( V_413 -> V_416 & V_417 )
V_10 |= V_424 ;
F_189 ( V_29 , V_107 , true ,
F_181 ( V_21 -> V_379 ) ,
F_182 ( V_21 -> V_379 ) ,
V_406 ,
V_10 | V_107 -> V_33 ) ;
}
V_19 -> V_116 = V_107 -> V_37 ;
if ( V_21 -> V_277 > 0 && V_413 -> V_416 & V_417 )
V_10 = 0 ;
else
V_10 = V_424 ;
F_189 ( V_29 , V_107 , false ,
0 ,
0 ,
F_223 ( 0 ) ,
V_10 | V_410 | F_14 ( V_293 ) | V_107 -> V_33 ) ;
F_208 ( V_29 , V_75 , V_76 , 0 ,
V_384 , V_259 ) ;
return 0 ;
}
static unsigned int F_228 ( struct V_28 * V_29 ,
struct V_21 * V_21 , unsigned int V_395 )
{
unsigned int V_425 ;
if ( V_29 -> V_396 < 0x100 || V_21 -> V_106 -> V_223 < V_426 )
return 0 ;
V_425 = V_21 -> V_80 -> V_427 . V_428 ;
return F_198 ( V_395 , V_425 + 1 ) - 1 ;
}
static unsigned int F_229 ( struct V_28 * V_29 ,
struct V_21 * V_21 , unsigned int V_395 )
{
unsigned int V_425 ;
unsigned int V_429 ;
if ( V_29 -> V_396 < 0x100 )
return 0 ;
if ( V_21 -> V_106 -> V_223 >= V_426 ) {
V_425 = V_21 -> V_80 -> V_427 . V_428 ;
V_429 = V_395 % ( V_425 + 1 ) ;
if ( V_429 == 0 )
return V_425 ;
return V_429 - 1 ;
}
if ( V_395 == 0 )
return 0 ;
return V_395 - 1 ;
}
static int F_230 ( struct V_28 * V_29 ,
struct V_21 * V_21 , int V_430 )
{
int V_431 , V_432 , V_69 = 0 ;
int V_433 , V_434 , V_435 ;
if ( V_21 -> V_106 -> V_223 == V_389 ||
V_21 -> V_106 -> V_223 == V_390 )
V_431 = V_21 -> V_431 + V_430 * V_21 -> V_388 ;
else
V_431 = ( V_21 -> V_431 + V_430 * V_21 -> V_388 ) >> 3 ;
V_432 = F_231 ( V_29 -> V_436 ) & 0x7 ;
if ( F_231 ( V_29 -> V_436 ) & ( 1 << 3 ) )
V_432 <<= 3 ;
V_435 = F_26 ( & V_29 -> V_437 -> V_438 ) ;
V_433 = F_232 ( V_435 + V_432 + 1 , 8 ) ;
V_434 = F_233 ( V_435 + 895 * 8 , 8 ) ;
V_431 &= 0x7ff ;
V_433 = ( V_433 >> 3 ) & 0x7ff ;
V_434 = ( V_434 >> 3 ) & 0x7ff ;
F_24 ( V_29 , L_145 ,
V_257 , V_430 , F_26 ( & V_29 -> V_437 -> V_438 ) ,
V_433 , V_434 , V_431 ) ;
if ( V_433 < V_434 ) {
if ( V_431 > V_434 ||
V_431 < V_433 )
V_69 = - V_372 ;
} else if ( V_433 > V_434 ) {
if ( ( V_431 > V_434 &&
V_431 < V_433 ) )
V_69 = - V_372 ;
} else {
V_69 = - V_372 ;
}
if ( V_430 == 0 ) {
if ( V_69 == - V_372 || V_431 == V_433 ) {
V_431 = V_433 + 1 ;
if ( V_21 -> V_106 -> V_223 == V_389 ||
V_21 -> V_106 -> V_223 == V_390 )
V_21 -> V_431 = V_431 ;
else
V_21 -> V_431 = V_431 << 3 ;
V_69 = 0 ;
}
}
if ( V_69 ) {
F_51 ( V_29 , L_146 ,
V_431 , V_435 , V_430 ,
V_433 , V_434 ) ;
F_51 ( V_29 , L_147 ) ;
return V_69 ;
}
return V_431 ;
}
static int F_234 ( struct V_28 * V_29 , T_8 V_368 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_13 * V_107 ;
struct V_20 * V_20 ;
struct V_18 * V_19 ;
int V_24 , V_439 ;
struct V_339 * V_259 ;
bool V_121 ;
int V_384 ;
T_2 V_10 , V_406 ;
int V_383 , V_392 , V_440 , V_441 , V_69 ;
T_3 V_442 , V_110 ;
int V_154 , V_155 ;
bool V_35 ;
struct V_79 * V_443 ;
int V_444 ;
V_443 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
V_107 = V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] . V_14 ;
V_24 = V_21 -> V_445 ;
if ( V_24 < 1 ) {
F_24 ( V_29 , L_148 ) ;
return - V_372 ;
}
V_442 = ( T_3 ) V_21 -> V_379 ;
V_259 = & V_107 -> V_37 -> V_9 ;
V_384 = V_107 -> V_33 ;
V_20 = V_21 -> V_22 ;
for ( V_154 = 0 ; V_154 < V_24 ; V_154 ++ ) {
unsigned int V_446 , V_400 ;
unsigned int V_447 , V_448 ;
T_2 V_449 ;
V_121 = true ;
V_383 = 0 ;
V_110 = V_442 + V_21 -> V_305 [ V_154 ] . V_382 ;
V_440 = V_21 -> V_305 [ V_154 ] . V_306 ;
V_441 = V_440 ;
V_400 = F_215 ( & V_21 -> V_80 -> V_280 ) ;
V_446 = F_198 ( V_440 , V_400 ) ;
if ( V_446 == 0 )
V_446 ++ ;
V_447 = F_228 ( V_29 , V_21 , V_446 ) ;
V_448 = F_229 ( V_29 ,
V_21 , V_446 ) ;
V_439 = F_205 ( V_21 , V_154 ) ;
V_69 = F_193 ( V_29 , V_29 -> V_81 [ V_75 ] , V_76 ,
V_21 -> V_77 , V_439 , V_21 , V_154 , V_368 ) ;
if ( V_69 < 0 ) {
if ( V_154 == 0 )
return V_69 ;
goto V_166;
}
V_19 = & V_20 -> V_19 [ V_154 ] ;
V_449 = V_450 ;
if ( ! ( V_21 -> V_278 & V_451 ) &&
F_235 ( V_29 -> V_452 ) ) {
V_444 = F_230 ( V_29 , V_21 , V_154 ) ;
if ( V_444 >= 0 )
V_449 = F_236 ( V_444 ) ;
}
V_10 = F_14 ( V_453 ) |
F_237 ( V_448 ) |
V_449 |
( V_154 ? V_107 -> V_33 : ! V_384 ) ;
if ( ! V_443 -> V_454 )
V_10 |= F_238 ( V_447 ) ;
for ( V_155 = 0 ; V_155 < V_439 ; V_155 ++ ) {
T_2 V_407 = 0 ;
if ( ! V_121 )
V_10 = F_14 ( V_296 ) |
V_107 -> V_33 ;
if ( F_221 ( V_21 ) )
V_10 |= V_411 ;
if ( V_155 < V_439 - 1 ) {
V_35 = true ;
V_10 |= V_26 ;
} else {
V_35 = false ;
V_19 -> V_116 = V_107 -> V_37 ;
V_10 |= V_410 ;
if ( V_29 -> V_396 >= 0x100 &&
! ( V_29 -> V_39 & V_455 ) &&
V_154 < V_24 - 1 )
V_10 |= V_456 ;
}
V_392 = F_220 ( V_110 ) ;
if ( V_392 > V_441 )
V_392 = V_441 ;
V_407 = F_214 ( V_29 , V_383 ,
V_392 , V_440 ,
V_21 , V_35 ) ;
V_406 = F_170 ( V_392 ) |
F_223 ( 0 ) ;
if ( V_121 && V_443 -> V_454 )
V_406 |= F_239 ( V_447 ) ;
else
V_406 |= F_222 ( V_407 ) ;
V_121 = false ;
F_189 ( V_29 , V_107 , V_35 ,
F_181 ( V_110 ) ,
F_182 ( V_110 ) ,
V_406 ,
V_10 ) ;
V_383 += V_392 ;
V_110 += V_392 ;
V_441 -= V_392 ;
}
if ( V_383 != V_440 ) {
F_38 ( V_29 , L_149 ) ;
V_69 = - V_372 ;
goto V_166;
}
}
if ( F_235 ( V_29 -> V_452 ) )
V_443 -> V_457 = V_21 -> V_431 + V_24 * V_21 -> V_388 ;
if ( F_63 ( V_29 ) -> V_129 . V_130 == 0 ) {
if ( V_29 -> V_39 & V_131 )
F_240 () ;
}
F_63 ( V_29 ) -> V_129 . V_130 ++ ;
F_208 ( V_29 , V_75 , V_76 , V_21 -> V_77 ,
V_384 , V_259 ) ;
return 0 ;
V_166:
for ( V_154 -- ; V_154 >= 0 ; V_154 -- )
F_83 ( & V_20 -> V_19 [ V_154 ] . V_88 ) ;
V_20 -> V_19 [ 0 ] . V_116 = V_107 -> V_37 ;
F_57 ( V_29 , V_107 , & V_20 -> V_19 [ 0 ] , true ) ;
V_107 -> V_37 = V_20 -> V_19 [ 0 ] . V_121 ;
V_107 -> V_41 = V_20 -> V_19 [ 0 ] . V_120 ;
V_107 -> V_33 = V_384 ;
V_107 -> V_34 = V_107 -> V_160 ;
F_66 ( F_61 ( V_21 -> V_106 -> V_126 ) , V_21 ) ;
return V_69 ;
}
int F_241 ( struct V_28 * V_29 , T_8 V_368 ,
struct V_21 * V_21 , int V_75 , unsigned int V_76 )
{
struct V_93 * V_282 ;
struct V_13 * V_107 ;
struct V_95 * V_96 ;
int V_431 ;
int V_24 , V_42 , V_154 ;
int V_69 ;
struct V_79 * V_443 ;
int V_432 ;
V_282 = V_29 -> V_81 [ V_75 ] ;
V_443 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
V_107 = V_282 -> V_82 [ V_76 ] . V_14 ;
V_96 = F_54 ( V_29 , V_282 -> V_101 , V_76 ) ;
V_42 = 0 ;
V_24 = V_21 -> V_445 ;
for ( V_154 = 0 ; V_154 < V_24 ; V_154 ++ )
V_42 += F_205 ( V_21 , V_154 ) ;
V_69 = F_191 ( V_29 , V_107 , F_100 ( V_96 ) ,
V_42 , V_368 ) ;
if ( V_69 )
return V_69 ;
F_209 ( V_29 , V_21 , V_96 ) ;
if ( F_235 ( V_29 -> V_452 ) && ! F_49 ( & V_107 -> V_88 ) ) {
if ( F_100 ( V_96 ) == V_374 ) {
V_21 -> V_431 = V_443 -> V_457 ;
goto V_458;
}
}
V_431 = F_26 ( & V_29 -> V_437 -> V_438 ) ;
V_431 &= 0x3fff ;
V_432 = F_231 ( V_29 -> V_436 ) & 0x7 ;
if ( F_231 ( V_29 -> V_436 ) & ( 1 << 3 ) )
V_432 <<= 3 ;
V_431 += V_432 + V_459 ;
V_431 = F_232 ( V_431 , 8 ) ;
if ( V_21 -> V_106 -> V_223 == V_389 ||
V_21 -> V_106 -> V_223 == V_390 ) {
V_431 = F_232 ( V_431 , V_21 -> V_388 << 3 ) ;
V_21 -> V_431 = V_431 >> 3 ;
} else {
V_431 = F_232 ( V_431 , V_21 -> V_388 ) ;
V_21 -> V_431 = V_431 ;
}
V_458:
V_107 -> V_160 = V_107 -> V_34 ;
return F_234 ( V_29 , V_368 , V_21 , V_75 , V_76 ) ;
}
static int F_242 ( struct V_28 * V_29 , struct V_53 * V_191 ,
T_2 V_364 , T_2 V_365 ,
T_2 V_366 , T_2 V_367 , bool V_460 )
{
int V_461 = V_29 -> V_462 ;
int V_69 ;
if ( ( V_29 -> V_63 & V_64 ) ||
( V_29 -> V_63 & V_359 ) ) {
F_24 ( V_29 , L_150 ) ;
return - V_152 ;
}
if ( ! V_460 )
V_461 ++ ;
V_69 = F_191 ( V_29 , V_29 -> V_62 , V_374 ,
V_461 , V_180 ) ;
if ( V_69 < 0 ) {
F_38 ( V_29 , L_151 ) ;
if ( V_460 )
F_38 ( V_29 , L_152
L_153 ) ;
return V_69 ;
}
V_191 -> V_60 = V_29 -> V_62 -> V_37 ;
if ( F_49 ( & V_29 -> V_54 ) ) {
V_29 -> V_65 = V_191 ;
F_27 ( V_29 , V_66 ) ;
}
F_196 ( & V_191 -> V_54 , & V_29 -> V_54 ) ;
F_189 ( V_29 , V_29 -> V_62 , false , V_364 , V_365 , V_366 ,
V_367 | V_29 -> V_62 -> V_33 ) ;
return 0 ;
}
int F_243 ( struct V_28 * V_29 , struct V_53 * V_191 ,
T_2 V_215 , T_2 V_75 )
{
return F_242 ( V_29 , V_191 , 0 , 0 , 0 ,
F_14 ( V_215 ) | F_244 ( V_75 ) , false ) ;
}
int F_245 ( struct V_28 * V_29 , struct V_53 * V_191 ,
T_1 V_463 , T_2 V_75 , enum V_464 V_413 )
{
return F_242 ( V_29 , V_191 , F_181 ( V_463 ) ,
F_182 ( V_463 ) , 0 ,
F_14 ( V_209 ) | F_244 ( V_75 )
| ( V_413 == V_465 ? V_466 : 0 ) , false ) ;
}
int F_246 ( struct V_28 * V_29 , struct V_53 * V_191 ,
T_2 V_364 , T_2 V_365 , T_2 V_366 , T_2 V_367 )
{
return F_242 ( V_29 , V_191 , V_364 , V_365 , V_366 , V_367 , false ) ;
}
int F_247 ( struct V_28 * V_29 , struct V_53 * V_191 ,
T_2 V_75 )
{
return F_242 ( V_29 , V_191 , 0 , 0 , 0 ,
F_14 ( V_213 ) | F_244 ( V_75 ) ,
false ) ;
}
int F_105 ( struct V_28 * V_29 ,
struct V_53 * V_191 , T_1 V_463 ,
T_2 V_75 , bool V_460 )
{
return F_242 ( V_29 , V_191 , F_181 ( V_463 ) ,
F_182 ( V_463 ) , 0 ,
F_14 ( V_207 ) | F_244 ( V_75 ) ,
V_460 ) ;
}
int F_248 ( struct V_28 * V_29 , struct V_53 * V_191 ,
T_1 V_463 , T_2 V_75 , bool V_460 )
{
return F_242 ( V_29 , V_191 , F_181 ( V_463 ) ,
F_182 ( V_463 ) , 0 ,
F_14 ( V_208 ) | F_244 ( V_75 ) ,
V_460 ) ;
}
int F_249 ( struct V_28 * V_29 , struct V_53 * V_191 ,
int V_75 , unsigned int V_76 , int V_467 )
{
T_2 V_468 = F_244 ( V_75 ) ;
T_2 V_469 = F_250 ( V_76 ) ;
T_2 type = F_14 ( V_210 ) ;
T_2 V_470 = F_251 ( V_467 ) ;
return F_242 ( V_29 , V_191 , 0 , 0 , 0 ,
V_468 | V_469 | type | V_470 , false ) ;
}
void F_84 ( struct V_28 * V_29 ,
unsigned int V_75 , unsigned int V_76 ,
struct V_104 * V_148 )
{
T_1 V_110 ;
T_2 V_468 = F_244 ( V_75 ) ;
T_2 V_469 = F_250 ( V_76 ) ;
T_2 V_471 = F_252 ( V_148 -> V_77 ) ;
T_2 V_472 = 0 ;
T_2 type = F_14 ( V_211 ) ;
struct V_79 * V_80 ;
struct V_53 * V_191 ;
int V_69 ;
F_56 ( V_29 , V_114 ,
L_154 ,
V_148 -> V_117 ,
( unsigned long long ) V_148 -> V_117 -> V_8 ,
V_148 -> V_118 ,
( unsigned long long ) F_1 (
V_148 -> V_117 , V_148 -> V_118 ) ,
V_148 -> V_115 ) ;
V_110 = F_1 ( V_148 -> V_117 ,
V_148 -> V_118 ) ;
if ( V_110 == 0 ) {
F_51 ( V_29 , L_155 ) ;
F_51 ( V_29 , L_156 ,
V_148 -> V_117 , V_148 -> V_118 ) ;
return;
}
V_80 = & V_29 -> V_81 [ V_75 ] -> V_82 [ V_76 ] ;
if ( ( V_80 -> V_83 & V_85 ) ) {
F_51 ( V_29 , L_155 ) ;
F_51 ( V_29 , L_157 ) ;
return;
}
V_191 = F_104 ( V_29 , false , false , V_180 ) ;
if ( ! V_191 )
return;
V_80 -> V_176 = V_148 -> V_117 ;
V_80 -> V_162 = V_148 -> V_118 ;
if ( V_148 -> V_77 )
V_472 = F_253 ( V_473 ) ;
V_69 = F_242 ( V_29 , V_191 ,
F_181 ( V_110 ) | V_472 | V_148 -> V_115 ,
F_182 ( V_110 ) , V_471 ,
V_468 | V_469 | type , false ) ;
if ( V_69 < 0 ) {
F_254 ( V_29 , V_191 ) ;
return;
}
V_80 -> V_83 |= V_85 ;
}
int F_160 ( struct V_28 * V_29 , struct V_53 * V_191 ,
int V_75 , unsigned int V_76 ,
enum V_268 V_269 )
{
T_2 V_468 = F_244 ( V_75 ) ;
T_2 V_469 = F_250 ( V_76 ) ;
T_2 type = F_14 ( V_212 ) ;
if ( V_269 == V_327 )
type |= V_474 ;
return F_242 ( V_29 , V_191 , 0 , 0 , 0 ,
V_468 | V_469 | type , false ) ;
}
