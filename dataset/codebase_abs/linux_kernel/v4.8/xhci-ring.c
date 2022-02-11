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
return F_3 ( V_4 -> V_9 . V_10 ) ;
}
static bool F_4 ( struct V_1 * V_2 , union V_3 * V_4 )
{
return V_4 == & V_2 -> V_6 [ V_7 - 1 ] ;
}
static bool F_5 ( struct V_11 * V_12 ,
struct V_1 * V_2 , union V_3 * V_4 )
{
return F_4 ( V_2 , V_4 ) && ( V_2 -> V_13 == V_12 -> V_14 ) ;
}
static bool F_6 ( union V_3 * V_4 )
{
return F_7 ( V_4 -> V_9 . V_10 ) & V_15 ;
}
static void F_8 ( struct V_16 * V_17 ,
struct V_11 * V_12 ,
struct V_1 * * V_2 ,
union V_3 * * V_4 )
{
if ( F_2 ( * V_4 ) ) {
* V_2 = ( * V_2 ) -> V_13 ;
* V_4 = ( ( * V_2 ) -> V_6 ) ;
} else {
( * V_4 ) ++ ;
}
}
static void F_9 ( struct V_16 * V_17 , struct V_11 * V_12 )
{
V_12 -> V_18 ++ ;
if ( V_12 -> type == V_19 ) {
if ( ! F_4 ( V_12 -> V_20 , V_12 -> V_21 ) ) {
V_12 -> V_21 ++ ;
return;
}
if ( F_5 ( V_12 , V_12 -> V_20 , V_12 -> V_21 ) )
V_12 -> V_22 ^= 1 ;
V_12 -> V_20 = V_12 -> V_20 -> V_13 ;
V_12 -> V_21 = V_12 -> V_20 -> V_6 ;
return;
}
if ( ! F_2 ( V_12 -> V_21 ) ) {
V_12 -> V_21 ++ ;
V_12 -> V_23 ++ ;
}
while ( F_2 ( V_12 -> V_21 ) ) {
V_12 -> V_20 = V_12 -> V_20 -> V_13 ;
V_12 -> V_21 = V_12 -> V_20 -> V_6 ;
}
return;
}
static void F_10 ( struct V_16 * V_17 , struct V_11 * V_12 ,
bool V_24 )
{
T_2 V_25 ;
union V_3 * V_13 ;
V_25 = F_7 ( V_12 -> V_26 -> V_27 . V_28 [ 3 ] ) & V_29 ;
if ( ! F_2 ( V_12 -> V_26 ) )
V_12 -> V_23 -- ;
V_13 = ++ ( V_12 -> V_26 ) ;
V_12 -> V_30 ++ ;
while ( F_2 ( V_13 ) ) {
if ( ! V_25 && ! V_24 )
break;
if ( ! ( V_12 -> type == V_31 &&
( V_17 -> V_32 & V_33 ) ) &&
! F_11 ( V_17 ) ) {
V_13 -> V_9 . V_10 &= F_12 ( ~ V_29 ) ;
V_13 -> V_9 . V_10 |= F_12 ( V_25 ) ;
}
F_13 () ;
V_13 -> V_9 . V_10 ^= F_12 ( V_34 ) ;
if ( F_6 ( V_13 ) )
V_12 -> V_22 ^= 1 ;
V_12 -> V_35 = V_12 -> V_35 -> V_13 ;
V_12 -> V_26 = V_12 -> V_35 -> V_6 ;
V_13 = V_12 -> V_26 ;
}
}
static inline int F_14 ( struct V_16 * V_17 , struct V_11 * V_12 ,
unsigned int V_36 )
{
int V_37 ;
if ( V_12 -> V_23 < V_36 )
return 0 ;
if ( V_12 -> type != V_38 && V_12 -> type != V_19 ) {
V_37 = V_12 -> V_21 - V_12 -> V_20 -> V_6 ;
if ( V_12 -> V_23 < V_36 + V_37 )
return 0 ;
}
return 1 ;
}
void F_15 ( struct V_16 * V_17 )
{
if ( ! ( V_17 -> V_39 & V_40 ) )
return;
F_16 ( V_17 , L_1 ) ;
F_17 ( V_41 , & V_17 -> V_42 -> V_43 [ 0 ] ) ;
F_18 ( & V_17 -> V_42 -> V_43 [ 0 ] ) ;
}
static int F_19 ( struct V_16 * V_17 )
{
T_3 V_44 ;
int V_45 ;
F_16 ( V_17 , L_2 ) ;
V_44 = F_20 ( V_17 , & V_17 -> V_46 -> V_47 ) ;
V_17 -> V_39 = V_48 ;
F_21 ( & V_17 -> V_49 , V_50 + ( 2 * V_51 ) ) ;
F_22 ( V_17 , V_44 | V_52 ,
& V_17 -> V_46 -> V_47 ) ;
V_45 = F_23 ( & V_17 -> V_46 -> V_47 ,
V_53 , 0 , 5 * 1000 * 1000 ) ;
if ( V_45 < 0 ) {
F_22 ( V_17 , V_44 | V_52 ,
& V_17 -> V_46 -> V_47 ) ;
F_24 ( 1000 ) ;
V_45 = F_23 ( & V_17 -> V_46 -> V_47 ,
V_53 , 0 , 3 * 1000 * 1000 ) ;
if ( V_45 == 0 )
return 0 ;
F_25 ( V_17 , L_3
L_4 ) ;
F_26 ( & V_17 -> V_49 ) ;
V_17 -> V_54 |= V_55 ;
F_27 ( V_17 ) ;
F_28 ( V_17 ) ;
return - V_56 ;
}
return 0 ;
}
void F_29 ( struct V_16 * V_17 ,
unsigned int V_57 ,
unsigned int V_58 ,
unsigned int V_59 )
{
T_4 T_5 * V_60 = & V_17 -> V_42 -> V_43 [ V_57 ] ;
struct V_61 * V_62 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
unsigned int V_65 = V_62 -> V_65 ;
if ( ( V_65 & V_66 ) || ( V_65 & V_67 ) ||
( V_65 & V_68 ) )
return;
F_17 ( F_30 ( V_58 , V_59 ) , V_60 ) ;
}
static void F_31 ( struct V_16 * V_17 ,
unsigned int V_57 ,
unsigned int V_58 )
{
unsigned int V_59 ;
struct V_61 * V_62 ;
V_62 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
if ( ! ( V_62 -> V_65 & V_69 ) ) {
if ( V_62 -> V_12 && ! ( F_32 ( & V_62 -> V_12 -> V_70 ) ) )
F_29 ( V_17 , V_57 , V_58 , 0 ) ;
return;
}
for ( V_59 = 1 ; V_59 < V_62 -> V_71 -> V_72 ;
V_59 ++ ) {
struct V_73 * V_71 = V_62 -> V_71 ;
if ( ! F_32 ( & V_71 -> V_74 [ V_59 ] -> V_70 ) )
F_29 ( V_17 , V_57 , V_58 ,
V_59 ) ;
}
}
struct V_11 * F_33 ( struct V_16 * V_17 ,
unsigned int V_57 , unsigned int V_58 ,
unsigned int V_59 )
{
struct V_61 * V_62 ;
V_62 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
if ( ! ( V_62 -> V_65 & V_69 ) )
return V_62 -> V_12 ;
if ( V_59 == 0 ) {
F_34 ( V_17 ,
L_5
L_6 ,
V_57 , V_58 ) ;
return NULL ;
}
if ( V_59 < V_62 -> V_71 -> V_72 )
return V_62 -> V_71 -> V_74 [ V_59 ] ;
F_34 ( V_17 ,
L_7
L_8
L_9 ,
V_57 , V_58 ,
V_62 -> V_71 -> V_72 - 1 ,
V_59 ) ;
return NULL ;
}
void F_35 ( struct V_16 * V_17 ,
unsigned int V_57 , unsigned int V_58 ,
unsigned int V_59 , struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = V_17 -> V_63 [ V_57 ] ;
struct V_61 * V_62 = & V_80 -> V_64 [ V_58 ] ;
struct V_11 * V_81 ;
struct V_1 * V_82 ;
union V_3 * V_83 ;
T_1 V_84 ;
T_3 V_85 ;
bool V_86 = false ;
bool V_87 = false ;
V_81 = F_33 ( V_17 , V_57 ,
V_58 , V_59 ) ;
if ( ! V_81 ) {
F_34 ( V_17 , L_10
L_11 ,
V_59 ) ;
return;
}
F_36 ( V_17 , V_88 ,
L_12 ) ;
if ( V_62 -> V_65 & V_69 ) {
struct V_89 * V_90 =
& V_62 -> V_71 -> V_91 [ V_59 ] ;
V_85 = F_37 ( V_90 -> V_92 ) ;
} else {
struct V_93 * V_94
= F_38 ( V_17 , V_80 -> V_95 , V_58 ) ;
V_85 = F_37 ( V_94 -> V_96 ) ;
}
V_82 = V_81 -> V_20 ;
V_83 = V_81 -> V_21 ;
V_78 -> V_97 = V_85 & 0x1 ;
do {
if ( ! V_86 && F_1 ( V_82 , V_83 )
== ( T_1 ) ( V_85 & ~ 0xf ) ) {
V_86 = true ;
if ( V_87 )
break;
}
if ( V_83 == V_76 -> V_98 )
V_87 = true ;
if ( V_86 &&
F_3 ( V_83 -> V_27 . V_28 [ 3 ] ) &&
V_83 -> V_27 . V_28 [ 3 ] & F_12 ( V_15 ) )
V_78 -> V_97 ^= 0x1 ;
F_8 ( V_17 , V_81 , & V_82 , & V_83 ) ;
if ( V_83 == V_62 -> V_12 -> V_21 ) {
F_25 ( V_17 , L_13 ) ;
V_78 -> V_99 = NULL ;
V_78 -> V_100 = NULL ;
return;
}
} while ( ! V_86 || ! V_87 );
V_78 -> V_99 = V_82 ;
V_78 -> V_100 = V_83 ;
F_36 ( V_17 , V_88 ,
L_14 , V_78 -> V_97 ) ;
F_36 ( V_17 , V_88 ,
L_15 ,
V_78 -> V_99 ) ;
V_84 = F_1 ( V_78 -> V_99 , V_78 -> V_100 ) ;
F_36 ( V_17 , V_88 ,
L_16 ,
( unsigned long long ) V_84 ) ;
}
static void F_39 ( struct V_16 * V_17 , struct V_11 * V_81 ,
struct V_75 * V_76 , bool V_101 )
{
struct V_1 * V_102 ;
union V_3 * V_103 ;
for ( V_102 = V_76 -> V_104 , V_103 = V_76 -> V_105 ;
true ;
F_8 ( V_17 , V_81 , & V_102 , & V_103 ) ) {
if ( F_3 ( V_103 -> V_27 . V_28 [ 3 ] ) ) {
V_103 -> V_27 . V_28 [ 3 ] &= F_12 ( ~ V_29 ) ;
if ( V_101 )
V_103 -> V_27 . V_28 [ 3 ] ^=
F_12 ( V_34 ) ;
F_36 ( V_17 , V_88 ,
L_17 ) ;
F_36 ( V_17 , V_88 ,
L_18
L_19 ,
V_103 ,
( unsigned long long ) F_1 ( V_102 , V_103 ) ,
V_102 ,
( unsigned long long ) V_102 -> V_8 ) ;
} else {
V_103 -> V_27 . V_28 [ 0 ] = 0 ;
V_103 -> V_27 . V_28 [ 1 ] = 0 ;
V_103 -> V_27 . V_28 [ 2 ] = 0 ;
V_103 -> V_27 . V_28 [ 3 ] &= F_12 ( V_34 ) ;
if ( V_101 && V_103 != V_76 -> V_105 &&
V_103 != V_76 -> V_98 )
V_103 -> V_27 . V_28 [ 3 ] ^=
F_12 ( V_34 ) ;
V_103 -> V_27 . V_28 [ 3 ] |= F_12 (
F_40 ( V_106 ) ) ;
F_36 ( V_17 , V_88 ,
L_20 ,
( unsigned long long )
F_1 ( V_102 , V_103 ) ) ;
}
if ( V_103 == V_76 -> V_98 )
break;
}
}
static void F_41 ( struct V_16 * V_17 ,
struct V_61 * V_62 )
{
V_62 -> V_65 &= ~ V_66 ;
if ( F_26 ( & V_62 -> V_107 ) )
V_62 -> V_108 -- ;
}
static void F_42 ( struct V_16 * V_17 ,
struct V_75 * V_76 , int V_109 )
{
struct V_110 * V_111 ;
struct V_112 * V_112 ;
struct V_113 * V_113 ;
V_112 = V_76 -> V_112 ;
V_113 = V_112 -> V_114 ;
V_113 -> V_115 ++ ;
V_111 = F_43 ( V_112 -> V_80 -> V_116 ) ;
if ( V_113 -> V_115 == V_113 -> V_117 ) {
if ( F_44 ( V_112 -> V_118 ) == V_119 ) {
F_45 ( V_17 ) -> V_120 . V_121 -- ;
if ( F_45 ( V_17 ) -> V_120 . V_121 == 0 ) {
if ( V_17 -> V_32 & V_122 )
F_46 () ;
}
}
F_47 ( V_111 , V_112 ) ;
F_48 ( & V_17 -> V_123 ) ;
F_49 ( V_111 , V_112 , V_109 ) ;
F_50 ( V_113 ) ;
F_51 ( & V_17 -> V_123 ) ;
}
}
void F_52 ( struct V_16 * V_17 , struct V_11 * V_12 ,
struct V_75 * V_124 )
{
struct V_125 * V_80 = F_45 ( V_17 ) -> V_120 . V_126 ;
struct V_1 * V_2 = V_124 -> V_127 ;
struct V_112 * V_112 = V_124 -> V_112 ;
if ( ! V_2 || ! V_112 )
return;
if ( F_53 ( V_112 ) ) {
F_54 ( V_80 , V_2 -> V_128 , V_12 -> V_129 ,
V_130 ) ;
return;
}
F_55 ( V_112 -> V_131 , V_112 -> V_132 , V_2 -> V_133 ,
V_2 -> V_134 , V_2 -> V_135 ) ;
F_54 ( V_80 , V_2 -> V_128 , V_12 -> V_129 ,
V_136 ) ;
V_2 -> V_134 = 0 ;
V_2 -> V_135 = 0 ;
}
static void F_56 ( struct V_16 * V_17 , int V_57 ,
union V_3 * V_4 , struct V_137 * V_138 )
{
unsigned int V_58 ;
struct V_11 * V_81 ;
struct V_61 * V_62 ;
struct V_139 * V_140 ;
struct V_75 * V_76 = NULL ;
struct V_75 * V_141 ;
struct V_77 V_142 ;
if ( F_57 ( F_58 ( F_7 ( V_4 -> V_27 . V_28 [ 3 ] ) ) ) ) {
if ( ! V_17 -> V_63 [ V_57 ] )
F_34 ( V_17 , L_21
L_22 ,
V_57 ) ;
return;
}
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_58 = F_59 ( F_7 ( V_4 -> V_27 . V_28 [ 3 ] ) ) ;
V_62 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
if ( F_32 ( & V_62 -> V_143 ) ) {
F_41 ( V_17 , V_62 ) ;
V_62 -> V_144 = NULL ;
F_31 ( V_17 , V_57 , V_58 ) ;
return;
}
F_60 (entry, &ep->cancelled_td_list) {
V_76 = F_61 ( V_140 , struct V_75 , V_143 ) ;
F_36 ( V_17 , V_88 ,
L_23 ,
( unsigned long long ) F_1 (
V_76 -> V_104 , V_76 -> V_105 ) ) ;
V_81 = F_62 ( V_17 , V_76 -> V_112 ) ;
if ( ! V_81 ) {
F_34 ( V_17 , L_24
L_25 ,
V_76 -> V_112 ,
V_76 -> V_112 -> V_59 ) ;
goto V_145;
}
if ( V_76 == V_62 -> V_144 )
F_35 ( V_17 , V_57 , V_58 ,
V_76 -> V_112 -> V_59 ,
V_76 , & V_142 ) ;
else
F_39 ( V_17 , V_81 , V_76 , false ) ;
V_145:
F_63 ( & V_76 -> V_70 ) ;
}
V_141 = V_76 ;
F_41 ( V_17 , V_62 ) ;
if ( V_142 . V_100 && V_142 . V_99 ) {
F_64 ( V_17 , V_57 , V_58 ,
V_62 -> V_144 -> V_112 -> V_59 , & V_142 ) ;
F_15 ( V_17 ) ;
} else {
F_31 ( V_17 , V_57 , V_58 ) ;
}
V_62 -> V_144 = NULL ;
do {
V_76 = F_61 ( V_62 -> V_143 . V_13 ,
struct V_75 , V_143 ) ;
F_63 ( & V_76 -> V_143 ) ;
V_81 = F_62 ( V_17 , V_76 -> V_112 ) ;
if ( V_81 && V_76 -> V_127 )
F_52 ( V_17 , V_81 , V_76 ) ;
F_42 ( V_17 , V_76 , 0 ) ;
if ( V_17 -> V_54 & V_55 )
return;
} while ( V_76 != V_141 );
}
static void F_65 ( struct V_16 * V_17 , struct V_11 * V_12 )
{
struct V_75 * V_76 ;
while ( ! F_32 ( & V_12 -> V_70 ) ) {
V_76 = F_66 ( & V_12 -> V_70 ,
struct V_75 , V_70 ) ;
F_63 ( & V_76 -> V_70 ) ;
if ( ! F_32 ( & V_76 -> V_143 ) )
F_63 ( & V_76 -> V_143 ) ;
if ( V_76 -> V_127 )
F_52 ( V_17 , V_12 , V_76 ) ;
F_42 ( V_17 , V_76 , - V_56 ) ;
}
}
static void F_67 ( struct V_16 * V_17 ,
int V_57 , int V_58 )
{
struct V_75 * V_76 ;
struct V_61 * V_62 ;
struct V_11 * V_12 ;
V_62 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
if ( ( V_62 -> V_65 & V_69 ) ||
( V_62 -> V_65 & V_146 ) ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_62 -> V_71 -> V_72 ;
V_59 ++ ) {
F_36 ( V_17 , V_88 ,
L_26 ,
V_57 , V_58 , V_59 + 1 ) ;
F_65 ( V_17 ,
V_62 -> V_71 -> V_74 [ V_59 ] ) ;
}
} else {
V_12 = V_62 -> V_12 ;
if ( ! V_12 )
return;
F_36 ( V_17 , V_88 ,
L_27 ,
V_57 , V_58 ) ;
F_65 ( V_17 , V_12 ) ;
}
while ( ! F_32 ( & V_62 -> V_143 ) ) {
V_76 = F_66 ( & V_62 -> V_143 ,
struct V_75 , V_143 ) ;
F_63 ( & V_76 -> V_143 ) ;
F_42 ( V_17 , V_76 , - V_56 ) ;
}
}
void F_68 ( unsigned long V_147 )
{
struct V_16 * V_17 ;
struct V_61 * V_62 ;
int V_45 , V_148 , V_149 ;
unsigned long V_150 ;
V_62 = (struct V_61 * ) V_147 ;
V_17 = V_62 -> V_17 ;
F_69 ( & V_17 -> V_123 , V_150 ) ;
V_62 -> V_108 -- ;
if ( V_17 -> V_54 & V_151 ) {
F_70 ( & V_17 -> V_123 , V_150 ) ;
return;
}
if ( V_17 -> V_54 & V_55 ) {
F_36 ( V_17 , V_88 ,
L_28
L_29 ) ;
F_70 ( & V_17 -> V_123 , V_150 ) ;
return;
}
if ( ! ( V_62 -> V_108 == 0 && ( V_62 -> V_65 & V_66 ) ) ) {
F_36 ( V_17 , V_88 ,
L_30
L_31 ) ;
F_70 ( & V_17 -> V_123 , V_150 ) ;
return;
}
F_34 ( V_17 , L_32 ) ;
F_34 ( V_17 , L_33 ) ;
V_17 -> V_54 |= V_55 ;
F_27 ( V_17 ) ;
F_70 ( & V_17 -> V_123 , V_150 ) ;
V_45 = F_28 ( V_17 ) ;
F_69 ( & V_17 -> V_123 , V_150 ) ;
if ( V_45 < 0 ) {
F_34 ( V_17 , L_34 ) ;
F_34 ( V_17 , L_35 ) ;
}
for ( V_148 = 0 ; V_148 < V_152 ; V_148 ++ ) {
if ( ! V_17 -> V_63 [ V_148 ] )
continue;
for ( V_149 = 0 ; V_149 < 31 ; V_149 ++ )
F_67 ( V_17 , V_148 , V_149 ) ;
}
F_70 ( & V_17 -> V_123 , V_150 ) ;
F_36 ( V_17 , V_88 ,
L_36 ) ;
F_71 ( F_45 ( V_17 ) ) ;
F_36 ( V_17 , V_88 ,
L_37 ) ;
}
static void F_72 ( struct V_16 * V_17 ,
struct V_79 * V_80 ,
struct V_11 * V_81 ,
unsigned int V_58 )
{
union V_3 * V_153 ;
int V_154 ;
bool V_155 = false ;
V_154 = V_81 -> V_23 ;
V_153 = V_81 -> V_21 ;
if ( F_2 ( V_81 -> V_21 ) ) {
V_81 -> V_20 = V_81 -> V_20 -> V_13 ;
V_81 -> V_21 = V_81 -> V_20 -> V_6 ;
}
while ( V_81 -> V_21 != V_80 -> V_64 [ V_58 ] . V_156 ) {
V_81 -> V_23 ++ ;
V_81 -> V_21 ++ ;
if ( F_2 ( V_81 -> V_21 ) ) {
if ( V_81 -> V_21 ==
V_80 -> V_64 [ V_58 ] . V_156 )
break;
V_81 -> V_20 = V_81 -> V_20 -> V_13 ;
V_81 -> V_21 = V_81 -> V_20 -> V_6 ;
}
if ( V_81 -> V_21 == V_153 ) {
V_155 = true ;
break;
}
}
if ( V_155 ) {
F_16 ( V_17 , L_38 ) ;
V_81 -> V_23 = V_154 ;
}
}
static void F_73 ( struct V_16 * V_17 , int V_57 ,
union V_3 * V_4 , T_2 V_157 )
{
unsigned int V_58 ;
unsigned int V_59 ;
struct V_11 * V_81 ;
struct V_79 * V_80 ;
struct V_61 * V_62 ;
struct V_93 * V_94 ;
struct V_158 * V_159 ;
V_58 = F_59 ( F_7 ( V_4 -> V_27 . V_28 [ 3 ] ) ) ;
V_59 = F_74 ( F_7 ( V_4 -> V_27 . V_28 [ 2 ] ) ) ;
V_80 = V_17 -> V_63 [ V_57 ] ;
V_62 = & V_80 -> V_64 [ V_58 ] ;
V_81 = F_75 ( V_80 , V_58 , V_59 ) ;
if ( ! V_81 ) {
F_34 ( V_17 , L_39 ,
V_59 ) ;
goto V_160;
}
V_94 = F_38 ( V_17 , V_80 -> V_95 , V_58 ) ;
V_159 = F_76 ( V_17 , V_80 -> V_95 ) ;
if ( V_157 != V_161 ) {
unsigned int V_65 ;
unsigned int V_162 ;
switch ( V_157 ) {
case V_163 :
F_34 ( V_17 , L_40 ) ;
break;
case V_164 :
F_34 ( V_17 , L_41 ) ;
V_65 = F_7 ( V_94 -> V_165 ) ;
V_65 &= V_166 ;
V_162 = F_7 ( V_159 -> V_167 ) ;
V_162 = F_77 ( V_162 ) ;
F_36 ( V_17 , V_88 ,
L_42 ,
V_162 , V_65 ) ;
break;
case V_168 :
F_34 ( V_17 , L_43 ,
V_57 ) ;
break;
default:
F_34 ( V_17 , L_44 ,
V_157 ) ;
break;
}
} else {
T_3 V_96 ;
if ( V_62 -> V_65 & V_69 ) {
struct V_89 * V_90 =
& V_62 -> V_71 -> V_91 [ V_59 ] ;
V_96 = F_37 ( V_90 -> V_92 ) & V_169 ;
} else {
V_96 = F_37 ( V_94 -> V_96 ) & ~ V_170 ;
}
F_36 ( V_17 , V_88 ,
L_45 , V_96 ) ;
if ( F_1 ( V_62 -> V_171 ,
V_62 -> V_156 ) == V_96 ) {
F_72 ( V_17 , V_80 ,
V_81 , V_58 ) ;
} else {
F_34 ( V_17 , L_46 ) ;
F_34 ( V_17 , L_47 ,
V_62 -> V_171 , V_62 -> V_156 ) ;
}
}
V_160:
V_80 -> V_64 [ V_58 ] . V_65 &= ~ V_67 ;
V_80 -> V_64 [ V_58 ] . V_171 = NULL ;
V_80 -> V_64 [ V_58 ] . V_156 = NULL ;
F_31 ( V_17 , V_57 , V_58 ) ;
}
static void F_78 ( struct V_16 * V_17 , int V_57 ,
union V_3 * V_4 , T_2 V_157 )
{
unsigned int V_58 ;
V_58 = F_59 ( F_7 ( V_4 -> V_27 . V_28 [ 3 ] ) ) ;
F_36 ( V_17 , V_172 ,
L_48 , V_157 ) ;
if ( V_17 -> V_32 & V_173 ) {
struct V_174 * V_175 ;
V_175 = F_79 ( V_17 , false , false , V_176 ) ;
if ( ! V_175 ) {
F_34 ( V_17 , L_49 ) ;
return;
}
F_36 ( V_17 , V_177 ,
L_50 ) ;
F_80 ( V_17 , V_175 ,
V_17 -> V_63 [ V_57 ] -> V_178 -> V_8 , V_57 ,
false ) ;
F_15 ( V_17 ) ;
} else {
V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] . V_65 &= ~ V_68 ;
}
}
static void F_81 ( struct V_16 * V_17 , int V_57 ,
T_2 V_157 )
{
if ( V_157 == V_161 )
V_17 -> V_57 = V_57 ;
else
V_17 -> V_57 = 0 ;
}
static void F_82 ( struct V_16 * V_17 , int V_57 )
{
struct V_79 * V_179 ;
V_179 = V_17 -> V_63 [ V_57 ] ;
if ( ! V_179 )
return;
if ( V_17 -> V_32 & V_180 )
F_83 ( V_17 , V_179 , true ) ;
F_84 ( V_17 , V_57 ) ;
}
static void F_85 ( struct V_16 * V_17 , int V_57 ,
struct V_137 * V_138 , T_2 V_157 )
{
struct V_79 * V_179 ;
struct V_181 * V_182 ;
unsigned int V_58 ;
unsigned int V_65 ;
T_2 V_183 , V_184 ;
V_179 = V_17 -> V_63 [ V_57 ] ;
V_182 = F_86 ( V_179 -> V_178 ) ;
if ( ! V_182 ) {
F_34 ( V_17 , L_51 ) ;
return;
}
V_183 = F_7 ( V_182 -> V_183 ) ;
V_184 = F_7 ( V_182 -> V_184 ) ;
V_58 = F_87 ( V_183 ) - 1 ;
if ( V_17 -> V_32 & V_173 &&
V_58 != ( unsigned int ) - 1 &&
V_183 - V_185 == V_184 ) {
V_65 = V_179 -> V_64 [ V_58 ] . V_65 ;
if ( ! ( V_65 & V_68 ) )
return;
F_36 ( V_17 , V_177 ,
L_52
L_53 ,
V_58 , V_65 ) ;
V_179 -> V_64 [ V_58 ] . V_65 &= ~ V_68 ;
F_31 ( V_17 , V_57 , V_58 ) ;
return;
}
return;
}
static void F_88 ( struct V_16 * V_17 , int V_57 ,
struct V_137 * V_138 )
{
F_16 ( V_17 , L_54 ) ;
if ( ! V_17 -> V_63 [ V_57 ] )
F_34 ( V_17 , L_55
L_56 , V_57 ) ;
}
static void F_89 ( struct V_16 * V_17 ,
struct V_137 * V_138 )
{
if ( ! ( V_17 -> V_32 & V_186 ) ) {
V_17 -> V_187 |= 1 << 6 ;
return;
}
F_36 ( V_17 , V_177 ,
L_57 ,
F_90 ( F_7 ( V_138 -> V_109 ) ) ,
F_91 ( F_7 ( V_138 -> V_109 ) ) ) ;
}
static void F_92 ( struct V_174 * V_188 , T_2 V_109 )
{
F_93 ( & V_188 -> V_189 ) ;
if ( V_188 -> V_190 ) {
V_188 -> V_109 = V_109 ;
F_94 ( V_188 -> V_190 ) ;
} else {
F_95 ( V_188 ) ;
}
}
void F_96 ( struct V_16 * V_17 )
{
struct V_174 * V_191 , * V_192 ;
F_97 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_92 ( V_191 , V_193 ) ;
}
static void F_98 ( struct V_16 * V_17 ,
struct V_174 * V_191 )
{
struct V_174 * V_194 , * V_192 ;
T_2 V_22 ;
F_97 (i_cmd, tmp_cmd, &xhci->cmd_list,
cmd_list) {
if ( V_194 -> V_109 != V_193 )
continue;
V_194 -> V_109 = V_195 ;
F_16 ( V_17 , L_58 ,
V_194 -> V_196 ) ;
V_22 = F_7 (
V_194 -> V_196 -> V_27 . V_28 [ 3 ] ) & V_34 ;
V_194 -> V_196 -> V_27 . V_28 [ 0 ] = 0 ;
V_194 -> V_196 -> V_27 . V_28 [ 1 ] = 0 ;
V_194 -> V_196 -> V_27 . V_28 [ 2 ] = 0 ;
V_194 -> V_196 -> V_27 . V_28 [ 3 ] = F_12 (
F_40 ( V_197 ) | V_22 ) ;
}
V_17 -> V_39 = V_40 ;
if ( ( V_17 -> V_47 -> V_21 != V_17 -> V_47 -> V_26 ) &&
! ( V_17 -> V_54 & V_55 ) ) {
V_17 -> V_198 = V_191 ;
F_21 ( & V_17 -> V_49 , V_50 + V_51 ) ;
F_15 ( V_17 ) ;
}
return;
}
void F_99 ( unsigned long V_199 )
{
struct V_16 * V_17 ;
int V_45 ;
unsigned long V_150 ;
T_3 V_200 ;
bool V_201 = false ;
V_17 = (struct V_16 * ) V_199 ;
F_69 ( & V_17 -> V_123 , V_150 ) ;
if ( V_17 -> V_198 ) {
if ( V_17 -> V_198 -> V_109 == V_193 )
V_201 = true ;
V_17 -> V_198 -> V_109 = V_193 ;
}
V_200 = F_20 ( V_17 , & V_17 -> V_46 -> V_47 ) ;
if ( ( V_17 -> V_39 & V_40 ) &&
( V_200 & V_53 ) ) {
F_70 ( & V_17 -> V_123 , V_150 ) ;
F_16 ( V_17 , L_59 ) ;
V_45 = F_19 ( V_17 ) ;
if ( F_57 ( V_45 == - V_56 ) ) {
F_25 ( V_17 , L_60 ) ;
F_96 ( V_17 ) ;
F_71 ( F_45 ( V_17 ) -> V_202 ) ;
F_16 ( V_17 , L_61 ) ;
}
return;
}
if ( V_201 || V_17 -> V_54 & V_151 ) {
F_70 ( & V_17 -> V_123 , V_150 ) ;
F_16 ( V_17 , L_62 ) ;
F_96 ( V_17 ) ;
return;
}
F_16 ( V_17 , L_63 ) ;
F_98 ( V_17 , V_17 -> V_198 ) ;
F_70 ( & V_17 -> V_123 , V_150 ) ;
return;
}
static void F_100 ( struct V_16 * V_17 ,
struct V_137 * V_138 )
{
int V_57 = F_101 ( F_7 ( V_138 -> V_150 ) ) ;
T_3 V_203 ;
T_1 V_204 ;
T_2 V_157 ;
union V_3 * V_205 ;
struct V_174 * V_188 ;
T_2 V_206 ;
V_203 = F_37 ( V_138 -> V_205 ) ;
V_205 = V_17 -> V_47 -> V_21 ;
V_204 = F_1 ( V_17 -> V_47 -> V_20 ,
V_205 ) ;
if ( V_204 == 0 ) {
V_17 -> V_187 |= 1 << 4 ;
return;
}
if ( V_203 != ( T_3 ) V_204 ) {
V_17 -> V_187 |= 1 << 5 ;
return;
}
V_188 = F_61 ( V_17 -> V_189 . V_13 , struct V_174 , V_189 ) ;
F_26 ( & V_17 -> V_49 ) ;
F_102 ( V_205 , (struct V_207 * ) V_138 ) ;
V_157 = F_103 ( F_7 ( V_138 -> V_109 ) ) ;
if ( V_157 == V_195 ) {
F_98 ( V_17 , V_188 ) ;
return;
}
if ( V_188 -> V_196 != V_17 -> V_47 -> V_21 ) {
F_25 ( V_17 ,
L_64 ) ;
return;
}
if ( V_157 == V_193 ) {
V_17 -> V_39 = V_208 ;
if ( V_188 -> V_109 == V_193 )
goto V_209;
}
V_206 = F_104 ( F_7 ( V_205 -> V_27 . V_28 [ 3 ] ) ) ;
switch ( V_206 ) {
case V_210 :
F_81 ( V_17 , V_57 , V_157 ) ;
break;
case V_211 :
F_82 ( V_17 , V_57 ) ;
break;
case V_212 :
if ( ! V_188 -> V_190 )
F_85 ( V_17 , V_57 , V_138 ,
V_157 ) ;
break;
case V_213 :
break;
case V_214 :
break;
case V_215 :
F_105 ( V_57 != F_101 (
F_7 ( V_205 -> V_27 . V_28 [ 3 ] ) ) ) ;
F_56 ( V_17 , V_57 , V_205 , V_138 ) ;
break;
case V_216 :
F_105 ( V_57 != F_101 (
F_7 ( V_205 -> V_27 . V_28 [ 3 ] ) ) ) ;
F_73 ( V_17 , V_57 , V_205 , V_157 ) ;
break;
case V_197 :
if ( V_188 -> V_109 == V_195 )
V_157 = V_195 ;
break;
case V_217 :
F_105 ( V_57 != F_101 (
F_7 ( V_205 -> V_27 . V_28 [ 3 ] ) ) ) ;
F_78 ( V_17 , V_57 , V_205 , V_157 ) ;
break;
case V_218 :
V_57 = F_101 (
F_7 ( V_205 -> V_27 . V_28 [ 3 ] ) ) ;
F_88 ( V_17 , V_57 , V_138 ) ;
break;
case V_219 :
F_89 ( V_17 , V_138 ) ;
break;
default:
V_17 -> V_187 |= 1 << 6 ;
break;
}
if ( V_188 -> V_189 . V_13 != & V_17 -> V_189 ) {
V_17 -> V_198 = F_61 ( V_188 -> V_189 . V_13 ,
struct V_174 , V_189 ) ;
F_21 ( & V_17 -> V_49 , V_50 + V_51 ) ;
}
V_209:
F_92 ( V_188 , V_157 ) ;
F_9 ( V_17 , V_17 -> V_47 ) ;
}
static void F_106 ( struct V_16 * V_17 ,
union V_3 * V_138 )
{
T_2 V_220 ;
V_220 = F_104 ( F_7 ( V_138 -> V_27 . V_28 [ 3 ] ) ) ;
F_16 ( V_17 , L_65 , V_220 ) ;
if ( V_220 == V_221 && ( V_17 -> V_32 & V_186 ) )
F_100 ( V_17 , & V_138 -> V_222 ) ;
}
static unsigned int F_107 ( struct V_110 * V_111 ,
struct V_16 * V_17 , T_2 V_223 )
{
unsigned int V_148 ;
unsigned int V_224 = 0 ;
for ( V_148 = 0 ; V_148 < ( V_223 - 1 ) ; V_148 ++ ) {
T_6 V_225 = V_17 -> V_226 [ V_148 ] ;
if ( V_225 == 0 || V_225 == V_227 )
continue;
if ( ( V_225 == 0x03 ) == ( V_111 -> V_228 >= V_229 ) )
V_224 ++ ;
}
return V_224 ;
}
static void F_108 ( struct V_16 * V_17 ,
union V_3 * V_138 )
{
T_2 V_57 ;
struct V_230 * V_231 ;
V_57 = F_101 ( F_7 ( V_138 -> V_27 . V_28 [ 3 ] ) ) ;
if ( ! V_17 -> V_63 [ V_57 ] ) {
F_34 ( V_17 , L_66
L_67 , V_57 ) ;
return;
}
F_16 ( V_17 , L_68 ,
V_57 ) ;
V_231 = V_17 -> V_63 [ V_57 ] -> V_231 ;
if ( V_231 && V_231 -> V_232 )
F_109 ( V_231 -> V_232 , V_231 -> V_233 ) ;
}
static void F_110 ( struct V_16 * V_17 ,
union V_3 * V_138 )
{
struct V_110 * V_111 ;
T_2 V_223 ;
T_2 V_234 , V_235 ;
int V_236 ;
int V_57 ;
unsigned int V_237 ;
T_6 V_238 ;
struct V_239 * V_240 ;
T_4 T_5 * * V_226 ;
bool V_241 = false ;
if ( F_103 ( F_7 ( V_138 -> V_27 . V_28 [ 2 ] ) ) != V_161 ) {
F_34 ( V_17 , L_69 ) ;
V_17 -> V_187 |= 1 << 8 ;
}
V_223 = F_111 ( F_7 ( V_138 -> V_27 . V_28 [ 0 ] ) ) ;
F_16 ( V_17 , L_70 , V_223 ) ;
V_236 = F_112 ( V_17 -> V_242 ) ;
if ( ( V_223 <= 0 ) || ( V_223 > V_236 ) ) {
F_34 ( V_17 , L_71 , V_223 ) ;
F_9 ( V_17 , V_17 -> V_243 ) ;
return;
}
V_238 = V_17 -> V_226 [ V_223 - 1 ] ;
V_111 = F_45 ( V_17 ) ;
if ( ( V_238 == 0x03 ) != ( V_111 -> V_228 >= V_229 ) )
V_111 = V_17 -> V_244 ;
if ( V_238 == 0 ) {
F_34 ( V_17 , L_72
L_73 ,
V_223 ) ;
V_241 = true ;
goto V_160;
}
if ( V_238 == V_227 ) {
F_34 ( V_17 , L_74
L_73 ,
V_223 ) ;
V_241 = true ;
goto V_160;
}
V_240 = & V_17 -> V_240 [ F_113 ( V_111 ) ] ;
if ( V_111 -> V_228 >= V_229 )
V_226 = V_17 -> V_245 ;
else
V_226 = V_17 -> V_246 ;
V_237 = F_107 ( V_111 , V_17 ,
V_223 ) ;
V_234 = F_18 ( V_226 [ V_237 ] ) ;
if ( V_111 -> V_78 == V_247 ) {
F_16 ( V_17 , L_75 ) ;
F_114 ( V_111 ) ;
}
if ( V_111 -> V_228 >= V_229 && ( V_234 & V_248 ) == V_249 )
V_240 -> V_250 &= ~ ( 1 << V_237 ) ;
if ( ( V_234 & V_251 ) && ( V_234 & V_248 ) == V_252 ) {
F_16 ( V_17 , L_76 , V_223 ) ;
V_235 = F_18 ( & V_17 -> V_46 -> V_175 ) ;
if ( ! ( V_235 & V_253 ) ) {
F_34 ( V_17 , L_77 ) ;
goto V_160;
}
if ( F_115 ( V_234 ) ) {
F_16 ( V_17 , L_78 , V_223 ) ;
V_240 -> V_250 |= 1 << V_237 ;
F_116 ( V_17 , V_226 ,
V_237 , V_251 ) ;
F_117 ( V_17 , V_226 , V_237 ,
V_254 ) ;
V_241 = true ;
goto V_160;
} else if ( ! F_118 ( V_237 ,
& V_240 -> V_255 ) ) {
F_16 ( V_17 , L_79 , V_223 ) ;
V_240 -> V_256 [ V_237 ] = V_50 +
F_119 ( V_257 ) ;
F_120 ( V_237 , & V_240 -> V_255 ) ;
F_21 ( & V_111 -> V_258 ,
V_240 -> V_256 [ V_237 ] ) ;
}
}
if ( ( V_234 & V_251 ) && ( V_234 & V_248 ) == V_254 &&
F_115 ( V_234 ) ) {
F_16 ( V_17 , L_80 , V_223 ) ;
V_57 = F_121 ( V_111 , V_17 ,
V_237 + 1 ) ;
if ( V_57 && V_17 -> V_63 [ V_57 ] )
F_122 ( V_17 , V_57 ) ;
if ( V_240 -> V_250 & ( 1 << V_237 ) ) {
V_240 -> V_250 &=
~ ( 1 << V_237 ) ;
F_116 ( V_17 , V_226 ,
V_237 , V_251 ) ;
F_109 ( V_111 -> V_120 . V_259 ,
V_237 + 1 ) ;
V_241 = true ;
goto V_160;
}
}
if ( ! F_115 ( V_234 ) &&
F_123 ( V_237 ,
& V_240 -> V_260 ) ) {
F_94 ( & V_240 -> V_261 [ V_237 ] ) ;
V_241 = true ;
goto V_160;
}
if ( V_111 -> V_228 < V_229 )
F_116 ( V_17 , V_226 , V_237 ,
V_251 ) ;
V_160:
F_9 ( V_17 , V_17 -> V_243 ) ;
if ( V_241 )
return;
F_16 ( V_17 , L_81 , V_262 ) ;
F_120 ( V_263 , & V_111 -> V_150 ) ;
F_48 ( & V_17 -> V_123 ) ;
F_124 ( V_111 ) ;
F_51 ( & V_17 -> V_123 ) ;
}
struct V_1 * F_125 ( struct V_16 * V_17 ,
struct V_1 * V_104 ,
union V_3 * V_264 ,
union V_3 * V_265 ,
T_1 V_266 ,
bool V_267 )
{
T_1 V_268 ;
T_1 V_269 ;
T_1 V_270 ;
struct V_1 * V_102 ;
V_268 = F_1 ( V_104 , V_264 ) ;
V_102 = V_104 ;
do {
if ( V_268 == 0 )
return NULL ;
V_269 = F_1 ( V_102 ,
& V_102 -> V_6 [ V_7 - 1 ] ) ;
V_270 = F_1 ( V_102 , V_265 ) ;
if ( V_267 )
F_34 ( V_17 ,
L_82 ,
( unsigned long long ) V_266 ,
( unsigned long long ) V_268 ,
( unsigned long long ) V_270 ,
( unsigned long long ) V_102 -> V_8 ,
( unsigned long long ) V_269 ) ;
if ( V_270 > 0 ) {
if ( V_268 <= V_270 ) {
if ( V_266 >= V_268 && V_266 <= V_270 )
return V_102 ;
} else {
if ( ( V_266 >= V_268 &&
V_266 <= V_269 ) ||
( V_266 >= V_102 -> V_8 &&
V_266 <= V_270 ) )
return V_102 ;
}
return NULL ;
} else {
if ( V_266 >= V_268 && V_266 <= V_269 )
return V_102 ;
}
V_102 = V_102 -> V_13 ;
V_268 = F_1 ( V_102 , & V_102 -> V_6 [ 0 ] ) ;
} while ( V_102 != V_104 );
return NULL ;
}
static void F_126 ( struct V_16 * V_17 ,
unsigned int V_57 , unsigned int V_58 ,
unsigned int V_59 ,
struct V_75 * V_124 , union V_3 * V_271 )
{
struct V_61 * V_62 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
struct V_174 * V_175 ;
V_175 = F_79 ( V_17 , false , false , V_176 ) ;
if ( ! V_175 )
return;
V_62 -> V_65 |= V_68 ;
V_62 -> V_272 = V_59 ;
F_127 ( V_17 , V_175 , V_57 , V_58 ) ;
F_128 ( V_17 , V_58 , V_124 ) ;
V_62 -> V_272 = 0 ;
F_15 ( V_17 ) ;
}
static int F_129 ( struct V_16 * V_17 ,
struct V_93 * V_94 ,
unsigned int V_273 )
{
if ( V_273 == V_274 ||
V_273 == V_275 ||
V_273 == V_276 )
if ( ( V_94 -> V_165 & F_12 ( V_166 ) ) ==
F_12 ( V_277 ) )
return 1 ;
return 0 ;
}
int F_130 ( struct V_16 * V_17 , unsigned int V_273 )
{
if ( V_273 >= 224 && V_273 <= 255 ) {
F_16 ( V_17 , L_83 ,
V_273 ) ;
F_16 ( V_17 , L_84 ) ;
return 1 ;
}
return 0 ;
}
static int F_131 ( struct V_16 * V_17 , struct V_75 * V_124 ,
union V_3 * V_271 , struct V_278 * V_138 ,
struct V_61 * V_62 , int * V_109 , bool V_279 )
{
struct V_79 * V_280 ;
struct V_11 * V_81 ;
unsigned int V_57 ;
int V_58 ;
struct V_112 * V_112 = NULL ;
struct V_93 * V_94 ;
int V_45 = 0 ;
struct V_113 * V_113 ;
T_2 V_273 ;
V_57 = F_101 ( F_7 ( V_138 -> V_150 ) ) ;
V_280 = V_17 -> V_63 [ V_57 ] ;
V_58 = F_132 ( F_7 ( V_138 -> V_150 ) ) - 1 ;
V_81 = F_133 ( V_62 , F_37 ( V_138 -> V_281 ) ) ;
V_94 = F_38 ( V_17 , V_280 -> V_95 , V_58 ) ;
V_273 = F_103 ( F_7 ( V_138 -> V_282 ) ) ;
if ( V_279 )
goto V_283;
if ( V_273 == V_284 ||
V_273 == V_285 ||
V_273 == V_286 ) {
V_62 -> V_144 = V_124 ;
return 0 ;
}
if ( V_273 == V_287 ||
F_129 ( V_17 , V_94 ,
V_273 ) ) {
F_126 ( V_17 , V_57 , V_58 ,
V_81 -> V_59 , V_124 , V_271 ) ;
} else {
while ( V_81 -> V_21 != V_124 -> V_98 )
F_9 ( V_17 , V_81 ) ;
F_9 ( V_17 , V_81 ) ;
}
V_283:
V_112 = V_124 -> V_112 ;
V_113 = V_112 -> V_114 ;
if ( V_124 -> V_127 )
F_52 ( V_17 , V_81 , V_124 ) ;
if ( V_112 -> V_288 > V_112 -> V_289 ) {
F_34 ( V_17 , L_85 ,
V_112 -> V_289 ,
V_112 -> V_288 ) ;
V_112 -> V_288 = 0 ;
if ( V_124 -> V_112 -> V_290 & V_291 )
* V_109 = - V_292 ;
else
* V_109 = 0 ;
}
F_63 ( & V_124 -> V_70 ) ;
if ( ! F_32 ( & V_124 -> V_143 ) )
F_63 ( & V_124 -> V_143 ) ;
V_113 -> V_115 ++ ;
if ( V_113 -> V_115 == V_113 -> V_117 ) {
V_45 = 1 ;
if ( F_44 ( V_112 -> V_118 ) == V_119 ) {
F_45 ( V_17 ) -> V_120 . V_121 -- ;
if ( F_45 ( V_17 ) -> V_120 . V_121 == 0 ) {
if ( V_17 -> V_32 & V_122 )
F_46 () ;
}
}
}
return V_45 ;
}
static int F_134 ( struct V_16 * V_17 , struct V_75 * V_124 ,
union V_3 * V_271 , struct V_278 * V_138 ,
struct V_61 * V_62 , int * V_109 )
{
struct V_79 * V_280 ;
struct V_11 * V_81 ;
unsigned int V_57 ;
int V_58 ;
struct V_93 * V_94 ;
T_2 V_273 ;
V_57 = F_101 ( F_7 ( V_138 -> V_150 ) ) ;
V_280 = V_17 -> V_63 [ V_57 ] ;
V_58 = F_132 ( F_7 ( V_138 -> V_150 ) ) - 1 ;
V_81 = F_133 ( V_62 , F_37 ( V_138 -> V_281 ) ) ;
V_94 = F_38 ( V_17 , V_280 -> V_95 , V_58 ) ;
V_273 = F_103 ( F_7 ( V_138 -> V_282 ) ) ;
switch ( V_273 ) {
case V_161 :
if ( V_271 == V_81 -> V_21 ) {
F_34 ( V_17 , L_86
L_87 ) ;
* V_109 = - V_56 ;
} else if ( V_271 != V_124 -> V_98 ) {
F_34 ( V_17 , L_88
L_87 ) ;
* V_109 = - V_56 ;
} else {
* V_109 = 0 ;
}
break;
case V_293 :
if ( V_124 -> V_112 -> V_290 & V_291 )
* V_109 = - V_292 ;
else
* V_109 = 0 ;
break;
case V_286 :
if ( V_271 == V_81 -> V_21 || V_271 == V_124 -> V_98 )
F_34 ( V_17 , L_89 ) ;
else
V_124 -> V_112 -> V_288 =
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
return F_131 ( V_17 , V_124 , V_271 , V_138 , V_62 , V_109 , false ) ;
case V_285 :
if ( V_271 != V_81 -> V_21 && V_271 != V_124 -> V_98 )
V_124 -> V_112 -> V_288 =
V_124 -> V_112 -> V_289 -
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
case V_284 :
return F_131 ( V_17 , V_124 , V_271 , V_138 , V_62 , V_109 , false ) ;
default:
if ( ! F_129 ( V_17 ,
V_94 , V_273 ) )
break;
F_16 ( V_17 , L_90
L_91 ,
V_273 , V_58 ) ;
case V_287 :
if ( V_271 != V_81 -> V_21 &&
V_271 != V_124 -> V_98 )
V_124 -> V_112 -> V_288 =
V_124 -> V_112 -> V_289 -
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
else if ( ! V_124 -> V_294 )
V_124 -> V_112 -> V_288 = 0 ;
return F_131 ( V_17 , V_124 , V_271 , V_138 , V_62 , V_109 , false ) ;
}
if ( V_271 != V_81 -> V_21 ) {
if ( V_271 == V_124 -> V_98 ) {
if ( V_124 -> V_294 ) {
if ( ( * V_109 == - V_295 || * V_109 == 0 ) &&
( V_124 -> V_112 -> V_290
& V_291 ) )
* V_109 = - V_292 ;
} else {
V_124 -> V_112 -> V_288 =
V_124 -> V_112 -> V_289 ;
}
} else {
V_124 -> V_294 = true ;
V_124 -> V_112 -> V_288 =
V_124 -> V_112 -> V_289 -
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
F_16 ( V_17 , L_92
L_93 ) ;
return 0 ;
}
}
return F_131 ( V_17 , V_124 , V_271 , V_138 , V_62 , V_109 , false ) ;
}
static int F_136 ( struct V_16 * V_17 , struct V_75 * V_124 ,
union V_3 * V_271 , struct V_278 * V_138 ,
struct V_61 * V_62 , int * V_109 )
{
struct V_11 * V_81 ;
struct V_113 * V_113 ;
int V_296 ;
int V_297 = 0 ;
union V_3 * V_103 ;
struct V_1 * V_102 ;
struct V_298 * V_299 ;
T_2 V_273 ;
bool V_300 = false ;
V_81 = F_133 ( V_62 , F_37 ( V_138 -> V_281 ) ) ;
V_273 = F_103 ( F_7 ( V_138 -> V_282 ) ) ;
V_113 = V_124 -> V_112 -> V_114 ;
V_296 = V_113 -> V_115 ;
V_299 = & V_124 -> V_112 -> V_301 [ V_296 ] ;
switch ( V_273 ) {
case V_161 :
if ( F_135 ( F_7 ( V_138 -> V_282 ) ) == 0 ) {
V_299 -> V_109 = 0 ;
break;
}
if ( ( V_17 -> V_32 & V_302 ) )
V_273 = V_293 ;
case V_286 :
case V_293 :
V_299 -> V_109 = V_124 -> V_112 -> V_290 & V_291 ?
- V_292 : 0 ;
break;
case V_303 :
V_299 -> V_109 = - V_304 ;
V_300 = true ;
break;
case V_305 :
case V_275 :
V_299 -> V_109 = - V_306 ;
V_300 = true ;
break;
case V_307 :
case V_287 :
V_299 -> V_109 = - V_308 ;
V_300 = true ;
break;
case V_274 :
V_299 -> V_109 = - V_308 ;
if ( V_271 != V_124 -> V_98 )
return 0 ;
V_300 = true ;
break;
case V_285 :
case V_284 :
break;
default:
V_299 -> V_109 = - 1 ;
break;
}
if ( V_273 == V_161 || V_300 ) {
V_299 -> V_288 = V_299 -> V_117 ;
V_124 -> V_112 -> V_288 += V_299 -> V_117 ;
} else if ( V_273 == V_286 ) {
V_299 -> V_288 =
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
V_124 -> V_112 -> V_288 += V_299 -> V_288 ;
} else {
for ( V_103 = V_81 -> V_21 ,
V_102 = V_81 -> V_20 ; V_103 != V_271 ;
F_8 ( V_17 , V_81 , & V_102 , & V_103 ) ) {
if ( ! F_137 ( V_103 -> V_27 . V_28 [ 3 ] ) &&
! F_3 ( V_103 -> V_27 . V_28 [ 3 ] ) )
V_297 += F_138 ( F_7 ( V_103 -> V_27 . V_28 [ 2 ] ) ) ;
}
V_297 += F_138 ( F_7 ( V_103 -> V_27 . V_28 [ 2 ] ) ) -
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
if ( V_273 != V_284 ) {
V_299 -> V_288 = V_297 ;
V_124 -> V_112 -> V_288 += V_297 ;
}
}
return F_131 ( V_17 , V_124 , V_271 , V_138 , V_62 , V_109 , false ) ;
}
static int F_139 ( struct V_16 * V_17 , struct V_75 * V_124 ,
struct V_278 * V_138 ,
struct V_61 * V_62 , int * V_109 )
{
struct V_11 * V_81 ;
struct V_113 * V_113 ;
struct V_298 * V_299 ;
int V_296 ;
V_81 = F_133 ( V_62 , F_37 ( V_138 -> V_281 ) ) ;
V_113 = V_124 -> V_112 -> V_114 ;
V_296 = V_113 -> V_115 ;
V_299 = & V_124 -> V_112 -> V_301 [ V_296 ] ;
V_299 -> V_109 = - V_309 ;
V_299 -> V_288 = 0 ;
while ( V_81 -> V_21 != V_124 -> V_98 )
F_9 ( V_17 , V_81 ) ;
F_9 ( V_17 , V_81 ) ;
return F_131 ( V_17 , V_124 , NULL , V_138 , V_62 , V_109 , true ) ;
}
static int F_140 ( struct V_16 * V_17 , struct V_75 * V_124 ,
union V_3 * V_271 , struct V_278 * V_138 ,
struct V_61 * V_62 , int * V_109 )
{
struct V_11 * V_81 ;
union V_3 * V_103 ;
struct V_1 * V_102 ;
T_2 V_273 ;
V_81 = F_133 ( V_62 , F_37 ( V_138 -> V_281 ) ) ;
V_273 = F_103 ( F_7 ( V_138 -> V_282 ) ) ;
switch ( V_273 ) {
case V_161 :
if ( V_271 != V_124 -> V_98 ||
F_135 ( F_7 ( V_138 -> V_282 ) ) != 0 ) {
F_34 ( V_17 , L_94
L_95 ) ;
if ( V_124 -> V_112 -> V_290 & V_291 )
* V_109 = - V_292 ;
else
* V_109 = 0 ;
if ( ( V_17 -> V_32 & V_302 ) )
V_273 = V_293 ;
} else {
* V_109 = 0 ;
}
break;
case V_286 :
case V_293 :
if ( V_124 -> V_112 -> V_290 & V_291 )
* V_109 = - V_292 ;
else
* V_109 = 0 ;
break;
default:
break;
}
if ( V_273 == V_293 )
F_16 ( V_17 , L_96
L_97 ,
V_124 -> V_112 -> V_62 -> V_310 . V_311 ,
V_124 -> V_112 -> V_289 ,
F_135 ( F_7 ( V_138 -> V_282 ) ) ) ;
if ( V_273 == V_286 ) {
V_124 -> V_112 -> V_288 =
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
if ( V_124 -> V_112 -> V_289 <
V_124 -> V_112 -> V_288 ) {
F_34 ( V_17 , L_98 ,
F_135 ( F_7 ( V_138 -> V_282 ) ) ) ;
V_124 -> V_112 -> V_288 = 0 ;
}
} else if ( V_271 == V_124 -> V_98 ) {
if ( F_135 ( F_7 ( V_138 -> V_282 ) ) != 0 ) {
V_124 -> V_112 -> V_288 =
V_124 -> V_112 -> V_289 -
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
if ( V_124 -> V_112 -> V_289 <
V_124 -> V_112 -> V_288 ) {
F_34 ( V_17 , L_99
L_100 ,
F_135 ( F_7 ( V_138 -> V_282 ) ) ) ;
V_124 -> V_112 -> V_288 = 0 ;
if ( V_124 -> V_112 -> V_290 & V_291 )
* V_109 = - V_292 ;
else
* V_109 = 0 ;
}
if ( * V_109 == - V_295 ) {
if ( V_124 -> V_112 -> V_290 & V_291 )
* V_109 = - V_292 ;
else
* V_109 = 0 ;
}
} else {
V_124 -> V_112 -> V_288 =
V_124 -> V_112 -> V_289 ;
if ( * V_109 == - V_292 )
* V_109 = 0 ;
}
} else {
V_124 -> V_112 -> V_288 = 0 ;
for ( V_103 = V_81 -> V_21 , V_102 = V_81 -> V_20 ;
V_103 != V_271 ;
F_8 ( V_17 , V_81 , & V_102 , & V_103 ) ) {
if ( ! F_137 ( V_103 -> V_27 . V_28 [ 3 ] ) &&
! F_3 ( V_103 -> V_27 . V_28 [ 3 ] ) )
V_124 -> V_112 -> V_288 +=
F_138 ( F_7 ( V_103 -> V_27 . V_28 [ 2 ] ) ) ;
}
if ( V_273 != V_284 )
V_124 -> V_112 -> V_288 +=
F_138 ( F_7 ( V_103 -> V_27 . V_28 [ 2 ] ) ) -
F_135 ( F_7 ( V_138 -> V_282 ) ) ;
}
return F_131 ( V_17 , V_124 , V_271 , V_138 , V_62 , V_109 , false ) ;
}
static int F_141 ( struct V_16 * V_17 ,
struct V_278 * V_138 )
__releases( &xhci->lock
static int F_142 ( struct V_16 * V_17 )
{
union V_3 * V_138 ;
int V_312 = 1 ;
int V_45 ;
if ( ! V_17 -> V_243 || ! V_17 -> V_243 -> V_21 ) {
V_17 -> V_187 |= 1 << 1 ;
return 0 ;
}
V_138 = V_17 -> V_243 -> V_21 ;
if ( ( F_7 ( V_138 -> V_222 . V_150 ) & V_34 ) !=
V_17 -> V_243 -> V_22 ) {
V_17 -> V_187 |= 1 << 2 ;
return 0 ;
}
F_143 () ;
switch ( ( F_7 ( V_138 -> V_222 . V_150 ) & V_313 ) ) {
case F_40 ( V_314 ) :
F_100 ( V_17 , & V_138 -> V_222 ) ;
break;
case F_40 ( V_315 ) :
F_110 ( V_17 , V_138 ) ;
V_312 = 0 ;
break;
case F_40 ( V_316 ) :
V_45 = F_141 ( V_17 , & V_138 -> V_317 ) ;
if ( V_45 < 0 )
V_17 -> V_187 |= 1 << 9 ;
else
V_312 = 0 ;
break;
case F_40 ( V_318 ) :
F_108 ( V_17 , V_138 ) ;
break;
default:
if ( ( F_7 ( V_138 -> V_222 . V_150 ) & V_313 ) >=
F_40 ( 48 ) )
F_106 ( V_17 , V_138 ) ;
else
V_17 -> V_187 |= 1 << 3 ;
}
if ( V_17 -> V_54 & V_55 ) {
F_16 ( V_17 , L_101
L_102 ) ;
return 0 ;
}
if ( V_312 )
F_9 ( V_17 , V_17 -> V_243 ) ;
return 1 ;
}
T_7 F_144 ( struct V_110 * V_111 )
{
struct V_16 * V_17 = F_145 ( V_111 ) ;
T_2 V_109 ;
T_3 V_44 ;
union V_3 * V_319 ;
T_1 V_96 ;
F_51 ( & V_17 -> V_123 ) ;
V_109 = F_18 ( & V_17 -> V_46 -> V_109 ) ;
if ( V_109 == 0xffffffff )
goto V_320;
if ( ! ( V_109 & V_321 ) ) {
F_48 ( & V_17 -> V_123 ) ;
return V_322 ;
}
if ( V_109 & V_323 ) {
F_34 ( V_17 , L_103 ) ;
F_28 ( V_17 ) ;
V_320:
F_48 ( & V_17 -> V_123 ) ;
return V_324 ;
}
V_109 |= V_321 ;
F_17 ( V_109 , & V_17 -> V_46 -> V_109 ) ;
if ( V_111 -> V_325 ) {
T_2 V_326 ;
V_326 = F_18 ( & V_17 -> V_327 -> V_326 ) ;
V_326 |= V_328 ;
F_17 ( V_326 , & V_17 -> V_327 -> V_326 ) ;
}
if ( V_17 -> V_54 & V_55 ||
V_17 -> V_54 & V_329 ) {
F_16 ( V_17 , L_104
L_105 ) ;
V_44 = F_20 ( V_17 , & V_17 -> V_327 -> V_330 ) ;
F_22 ( V_17 , V_44 | V_331 ,
& V_17 -> V_327 -> V_330 ) ;
F_48 ( & V_17 -> V_123 ) ;
return V_324 ;
}
V_319 = V_17 -> V_243 -> V_21 ;
while ( F_142 ( V_17 ) > 0 ) {}
V_44 = F_20 ( V_17 , & V_17 -> V_327 -> V_330 ) ;
if ( V_319 != V_17 -> V_243 -> V_21 ) {
V_96 = F_1 ( V_17 -> V_243 -> V_20 ,
V_17 -> V_243 -> V_21 ) ;
if ( V_96 == 0 )
F_34 ( V_17 , L_106
L_107 ) ;
V_44 &= V_332 ;
V_44 |= ( ( T_3 ) V_96 & ( T_3 ) ~ V_332 ) ;
}
V_44 |= V_331 ;
F_22 ( V_17 , V_44 , & V_17 -> V_327 -> V_330 ) ;
F_48 ( & V_17 -> V_123 ) ;
return V_324 ;
}
T_7 F_146 ( int V_325 , void * V_111 )
{
return F_144 ( V_111 ) ;
}
static void F_147 ( struct V_16 * V_17 , struct V_11 * V_12 ,
bool V_24 ,
T_2 V_333 , T_2 V_334 , T_2 V_335 , T_2 V_336 )
{
struct V_207 * V_4 ;
V_4 = & V_12 -> V_26 -> V_27 ;
V_4 -> V_28 [ 0 ] = F_12 ( V_333 ) ;
V_4 -> V_28 [ 1 ] = F_12 ( V_334 ) ;
V_4 -> V_28 [ 2 ] = F_12 ( V_335 ) ;
V_4 -> V_28 [ 3 ] = F_12 ( V_336 ) ;
F_10 ( V_17 , V_12 , V_24 ) ;
}
static int F_148 ( struct V_16 * V_17 , struct V_11 * V_81 ,
T_2 V_65 , unsigned int V_36 , T_8 V_337 )
{
unsigned int V_338 ;
switch ( V_65 ) {
case V_339 :
F_34 ( V_17 , L_108 ) ;
return - V_340 ;
case V_341 :
F_34 ( V_17 , L_109 ) ;
return - V_342 ;
case V_277 :
F_16 ( V_17 , L_110 ) ;
case V_343 :
case V_344 :
break;
default:
F_25 ( V_17 , L_111 ) ;
return - V_342 ;
}
while ( 1 ) {
if ( F_14 ( V_17 , V_81 , V_36 ) )
break;
if ( V_81 == V_17 -> V_47 ) {
F_25 ( V_17 , L_112 ) ;
return - V_345 ;
}
F_36 ( V_17 , V_346 ,
L_113 ) ;
V_338 = V_36 - V_81 -> V_23 ;
if ( F_149 ( V_17 , V_81 , V_338 ,
V_337 ) ) {
F_25 ( V_17 , L_114 ) ;
return - V_345 ;
}
}
while ( F_2 ( V_81 -> V_26 ) ) {
if ( ! F_11 ( V_17 ) &&
! ( V_81 -> type == V_31 &&
( V_17 -> V_32 & V_33 ) ) )
V_81 -> V_26 -> V_9 . V_10 &=
F_12 ( ~ V_29 ) ;
else
V_81 -> V_26 -> V_9 . V_10 |=
F_12 ( V_29 ) ;
F_13 () ;
V_81 -> V_26 -> V_9 . V_10 ^= F_12 ( V_34 ) ;
if ( F_6 ( V_81 -> V_26 ) )
V_81 -> V_22 ^= 1 ;
V_81 -> V_35 = V_81 -> V_35 -> V_13 ;
V_81 -> V_26 = V_81 -> V_35 -> V_6 ;
}
return 0 ;
}
static int F_150 ( struct V_16 * V_17 ,
struct V_79 * V_280 ,
unsigned int V_58 ,
unsigned int V_59 ,
unsigned int V_36 ,
struct V_112 * V_112 ,
unsigned int V_347 ,
T_8 V_337 )
{
int V_45 ;
struct V_113 * V_113 ;
struct V_75 * V_124 ;
struct V_11 * V_81 ;
struct V_93 * V_94 = F_38 ( V_17 , V_280 -> V_95 , V_58 ) ;
V_81 = F_75 ( V_280 , V_58 , V_59 ) ;
if ( ! V_81 ) {
F_16 ( V_17 , L_115 ,
V_59 ) ;
return - V_342 ;
}
V_45 = F_148 ( V_17 , V_81 ,
F_7 ( V_94 -> V_165 ) & V_166 ,
V_36 , V_337 ) ;
if ( V_45 )
return V_45 ;
V_113 = V_112 -> V_114 ;
V_124 = V_113 -> V_124 [ V_347 ] ;
F_151 ( & V_124 -> V_70 ) ;
F_151 ( & V_124 -> V_143 ) ;
if ( V_347 == 0 ) {
V_45 = F_152 ( F_43 ( V_112 -> V_80 -> V_116 ) , V_112 ) ;
if ( F_57 ( V_45 ) )
return V_45 ;
}
V_124 -> V_112 = V_112 ;
F_153 ( & V_124 -> V_70 , & V_81 -> V_70 ) ;
V_124 -> V_104 = V_81 -> V_35 ;
V_124 -> V_105 = V_81 -> V_26 ;
V_113 -> V_124 [ V_347 ] = V_124 ;
return 0 ;
}
static unsigned int F_154 ( T_3 V_84 , T_3 V_297 )
{
unsigned int V_36 ;
V_36 = F_155 ( V_297 + ( V_84 & ( V_348 - 1 ) ) ,
V_348 ) ;
if ( V_36 == 0 )
V_36 ++ ;
return V_36 ;
}
static inline unsigned int F_156 ( struct V_112 * V_112 )
{
return F_154 ( V_112 -> V_349 , V_112 -> V_289 ) ;
}
static unsigned int F_157 ( struct V_112 * V_112 )
{
struct V_350 * V_131 ;
unsigned int V_148 , V_297 , V_351 , V_36 = 0 ;
V_351 = V_112 -> V_289 ;
F_158 (urb->sg, sg, urb->num_mapped_sgs, i) {
V_297 = F_159 ( V_131 ) ;
V_36 += F_154 ( F_160 ( V_131 ) , V_297 ) ;
V_297 = F_161 (unsigned int, len, full_len) ;
V_351 -= V_297 ;
if ( V_351 == 0 )
break;
}
return V_36 ;
}
static unsigned int F_162 ( struct V_112 * V_112 , int V_148 )
{
T_3 V_84 , V_297 ;
V_84 = ( T_3 ) ( V_112 -> V_349 + V_112 -> V_301 [ V_148 ] . V_352 ) ;
V_297 = V_112 -> V_301 [ V_148 ] . V_117 ;
return F_154 ( V_84 , V_297 ) ;
}
static void F_163 ( struct V_112 * V_112 , int V_353 )
{
if ( F_57 ( V_353 != V_112 -> V_289 ) )
F_164 ( & V_112 -> V_80 -> V_80 , L_116
L_117 ,
V_262 ,
V_112 -> V_62 -> V_310 . V_311 ,
V_353 , V_353 ,
V_112 -> V_289 ,
V_112 -> V_289 ) ;
}
static void F_165 ( struct V_16 * V_17 , int V_57 ,
unsigned int V_58 , unsigned int V_59 , int V_354 ,
struct V_207 * V_264 )
{
F_13 () ;
if ( V_354 )
V_264 -> V_28 [ 3 ] |= F_12 ( V_354 ) ;
else
V_264 -> V_28 [ 3 ] &= F_12 ( ~ V_34 ) ;
F_29 ( V_17 , V_57 , V_58 , V_59 ) ;
}
static void F_166 ( struct V_16 * V_17 , struct V_112 * V_112 ,
struct V_93 * V_94 )
{
int V_355 ;
int V_356 ;
V_355 = F_167 ( F_7 ( V_94 -> V_165 ) ) ;
V_356 = V_112 -> V_357 ;
if ( V_112 -> V_80 -> V_228 == V_358 ||
V_112 -> V_80 -> V_228 == V_359 )
V_356 *= 8 ;
if ( V_355 != V_356 ) {
F_168 ( & V_112 -> V_80 -> V_80 ,
L_118 ,
V_356 , V_356 == 1 ? L_119 : L_120 ,
V_355 , V_355 == 1 ? L_119 : L_120 ) ;
V_112 -> V_357 = V_355 ;
if ( V_112 -> V_80 -> V_228 == V_358 ||
V_112 -> V_80 -> V_228 == V_359 )
V_112 -> V_357 /= 8 ;
}
}
int F_169 ( struct V_16 * V_17 , T_8 V_337 ,
struct V_112 * V_112 , int V_57 , unsigned int V_58 )
{
struct V_93 * V_94 ;
V_94 = F_38 ( V_17 , V_17 -> V_63 [ V_57 ] -> V_95 , V_58 ) ;
F_166 ( V_17 , V_112 , V_94 ) ;
return F_170 ( V_17 , V_337 , V_112 , V_57 , V_58 ) ;
}
static T_2 F_171 ( struct V_16 * V_17 , int V_360 ,
int V_361 , unsigned int V_362 ,
struct V_112 * V_112 , bool V_24 )
{
T_2 V_363 , V_364 ;
if ( V_17 -> V_365 < 0x100 && ! ( V_17 -> V_32 & V_366 ) )
return ( ( V_362 - V_360 ) >> 10 ) ;
if ( ! V_24 || ( V_360 == 0 && V_361 == 0 ) ||
V_361 == V_362 )
return 0 ;
if ( V_17 -> V_32 & V_366 )
V_361 = 0 ;
V_363 = F_172 ( F_173 ( & V_112 -> V_62 -> V_310 ) ) ;
V_364 = F_155 ( V_362 , V_363 ) ;
return ( V_364 - ( ( V_360 + V_361 ) / V_363 ) ) ;
}
static int F_174 ( struct V_16 * V_17 , struct V_112 * V_112 , T_2 V_367 ,
T_2 * V_361 , struct V_1 * V_2 )
{
struct V_125 * V_80 = F_45 ( V_17 ) -> V_120 . V_126 ;
unsigned int V_368 ;
unsigned int V_369 ;
T_2 V_370 ;
V_369 = F_172 ( F_173 ( & V_112 -> V_62 -> V_310 ) ) ;
V_368 = ( V_367 + * V_361 ) % V_369 ;
if ( V_368 == 0 )
return 0 ;
F_16 ( V_17 , L_121 ,
V_368 , * V_361 ) ;
if ( * V_361 > V_368 ) {
* V_361 -= V_368 ;
F_16 ( V_17 , L_122 , * V_361 ) ;
return 0 ;
}
V_370 = V_369 - ( V_367 % V_369 ) ;
if ( V_370 > ( V_112 -> V_289 - V_367 ) )
V_370 = ( V_112 -> V_289 - V_367 ) ;
if ( F_53 ( V_112 ) ) {
F_175 ( V_112 -> V_131 , V_112 -> V_132 ,
V_2 -> V_133 , V_370 , V_367 ) ;
V_2 -> V_128 = F_176 ( V_80 , V_2 -> V_133 ,
V_369 , V_130 ) ;
} else {
V_2 -> V_128 = F_176 ( V_80 , V_2 -> V_133 ,
V_369 , V_136 ) ;
}
if ( F_177 ( V_80 , V_2 -> V_128 ) ) {
F_34 ( V_17 , L_123 ) ;
return 0 ;
}
* V_361 = V_370 ;
V_2 -> V_134 = V_370 ;
V_2 -> V_135 = V_367 ;
F_16 ( V_17 , L_124 , * V_361 ) ;
return 1 ;
}
int F_170 ( struct V_16 * V_17 , T_8 V_337 ,
struct V_112 * V_112 , int V_57 , unsigned int V_58 )
{
struct V_11 * V_12 ;
struct V_113 * V_113 ;
struct V_75 * V_124 ;
struct V_207 * V_264 ;
struct V_350 * V_131 = NULL ;
bool V_24 = true ;
bool V_371 = false ;
bool V_105 = true ;
unsigned int V_36 ;
unsigned int V_354 , V_372 = 0 ;
unsigned int V_367 , V_373 , V_361 , V_351 ;
int V_374 , V_45 ;
T_2 V_28 , V_375 , V_376 ;
T_3 V_84 , V_377 ;
V_12 = F_62 ( V_17 , V_112 ) ;
if ( ! V_12 )
return - V_342 ;
V_351 = V_112 -> V_289 ;
if ( V_112 -> V_372 ) {
V_372 = V_112 -> V_132 ;
V_131 = V_112 -> V_131 ;
V_84 = ( T_3 ) F_160 ( V_131 ) ;
V_373 = F_159 ( V_131 ) ;
V_36 = F_157 ( V_112 ) ;
} else {
V_36 = F_156 ( V_112 ) ;
V_84 = ( T_3 ) V_112 -> V_349 ;
V_373 = V_351 ;
}
V_45 = F_150 ( V_17 , V_17 -> V_63 [ V_57 ] ,
V_58 , V_112 -> V_59 ,
V_36 , V_112 , 0 , V_337 ) ;
if ( F_57 ( V_45 < 0 ) )
return V_45 ;
V_113 = V_112 -> V_114 ;
if ( V_112 -> V_290 & V_378 && V_113 -> V_117 > 1 )
V_371 = true ;
V_124 = V_113 -> V_124 [ 0 ] ;
V_264 = & V_12 -> V_26 -> V_27 ;
V_354 = V_12 -> V_22 ;
V_377 = V_84 ;
for ( V_367 = 0 ; V_105 || V_367 < V_351 ;
V_367 += V_361 ) {
V_28 = F_40 ( V_379 ) ;
V_361 = F_178 ( V_84 ) ;
V_361 = F_161 (unsigned int, trb_buff_len, block_len) ;
if ( V_367 + V_361 > V_351 )
V_361 = V_351 - V_367 ;
if ( V_105 ) {
V_105 = false ;
if ( V_354 == 0 )
V_28 |= V_34 ;
} else
V_28 |= V_12 -> V_22 ;
if ( V_367 + V_361 < V_351 ) {
V_28 |= V_29 ;
if ( F_2 ( V_12 -> V_26 + 1 ) ) {
if ( F_174 ( V_17 , V_112 , V_367 ,
& V_361 ,
V_12 -> V_35 ) ) {
V_377 = V_12 -> V_35 -> V_128 ;
V_124 -> V_127 = V_12 -> V_35 ;
}
}
}
if ( V_367 + V_361 >= V_351 ) {
V_28 &= ~ V_29 ;
V_28 |= V_380 ;
V_24 = false ;
V_124 -> V_98 = V_12 -> V_26 ;
}
if ( F_179 ( V_112 ) )
V_28 |= V_381 ;
V_376 = F_171 ( V_17 , V_367 , V_361 ,
V_351 , V_112 , V_24 ) ;
V_375 = F_138 ( V_361 ) |
F_180 ( V_376 ) |
F_181 ( 0 ) ;
F_147 ( V_17 , V_12 , V_24 | V_371 ,
F_182 ( V_377 ) ,
F_183 ( V_377 ) ,
V_375 ,
V_28 ) ;
V_84 += V_361 ;
V_374 = V_361 ;
while ( V_131 && V_374 >= V_373 ) {
-- V_372 ;
V_374 -= V_373 ;
if ( V_372 != 0 ) {
V_131 = F_184 ( V_131 ) ;
V_373 = F_159 ( V_131 ) ;
V_84 = ( T_3 ) F_160 ( V_131 ) ;
V_84 += V_374 ;
}
}
V_373 -= V_374 ;
V_377 = V_84 ;
}
if ( V_371 ) {
V_45 = F_150 ( V_17 , V_17 -> V_63 [ V_57 ] ,
V_58 , V_112 -> V_59 ,
1 , V_112 , 1 , V_337 ) ;
V_113 -> V_124 [ 1 ] -> V_98 = V_12 -> V_26 ;
V_28 = F_40 ( V_379 ) | V_12 -> V_22 | V_380 ;
F_147 ( V_17 , V_12 , 0 , 0 , 0 , F_181 ( 0 ) , V_28 ) ;
}
F_163 ( V_112 , V_367 ) ;
F_165 ( V_17 , V_57 , V_58 , V_112 -> V_59 ,
V_354 , V_264 ) ;
return 0 ;
}
int F_185 ( struct V_16 * V_17 , T_8 V_337 ,
struct V_112 * V_112 , int V_57 , unsigned int V_58 )
{
struct V_11 * V_81 ;
int V_36 ;
int V_45 ;
struct V_382 * V_383 ;
struct V_207 * V_264 ;
int V_354 ;
T_2 V_28 , V_375 , V_376 ;
struct V_113 * V_113 ;
struct V_75 * V_124 ;
V_81 = F_62 ( V_17 , V_112 ) ;
if ( ! V_81 )
return - V_342 ;
if ( ! V_112 -> V_384 )
return - V_342 ;
V_36 = 2 ;
if ( V_112 -> V_289 > 0 )
V_36 ++ ;
V_45 = F_150 ( V_17 , V_17 -> V_63 [ V_57 ] ,
V_58 , V_112 -> V_59 ,
V_36 , V_112 , 0 , V_337 ) ;
if ( V_45 < 0 )
return V_45 ;
V_113 = V_112 -> V_114 ;
V_124 = V_113 -> V_124 [ 0 ] ;
V_264 = & V_81 -> V_26 -> V_27 ;
V_354 = V_81 -> V_22 ;
V_383 = (struct V_382 * ) V_112 -> V_384 ;
V_28 = 0 ;
V_28 |= V_385 | F_40 ( V_386 ) ;
if ( V_354 == 0 )
V_28 |= 0x1 ;
if ( ( V_17 -> V_365 >= 0x100 ) || ( V_17 -> V_32 & V_366 ) ) {
if ( V_112 -> V_289 > 0 ) {
if ( V_383 -> V_387 & V_388 )
V_28 |= F_186 ( V_389 ) ;
else
V_28 |= F_186 ( V_390 ) ;
}
}
F_147 ( V_17 , V_81 , true ,
V_383 -> V_387 | V_383 -> V_391 << 8 | F_187 ( V_383 -> V_392 ) << 16 ,
F_187 ( V_383 -> V_393 ) | F_187 ( V_383 -> V_394 ) << 16 ,
F_138 ( 8 ) | F_181 ( 0 ) ,
V_28 ) ;
if ( F_179 ( V_112 ) )
V_28 = V_381 | F_40 ( V_395 ) ;
else
V_28 = F_40 ( V_395 ) ;
V_376 = F_171 ( V_17 , 0 ,
V_112 -> V_289 ,
V_112 -> V_289 ,
V_112 , 1 ) ;
V_375 = F_138 ( V_112 -> V_289 ) |
F_180 ( V_376 ) |
F_181 ( 0 ) ;
if ( V_112 -> V_289 > 0 ) {
if ( V_383 -> V_387 & V_388 )
V_28 |= V_396 ;
F_147 ( V_17 , V_81 , true ,
F_182 ( V_112 -> V_349 ) ,
F_183 ( V_112 -> V_349 ) ,
V_375 ,
V_28 | V_81 -> V_22 ) ;
}
V_124 -> V_98 = V_81 -> V_26 ;
if ( V_112 -> V_289 > 0 && V_383 -> V_387 & V_388 )
V_28 = 0 ;
else
V_28 = V_396 ;
F_147 ( V_17 , V_81 , false ,
0 ,
0 ,
F_181 ( 0 ) ,
V_28 | V_380 | F_40 ( V_397 ) | V_81 -> V_22 ) ;
F_165 ( V_17 , V_57 , V_58 , 0 ,
V_354 , V_264 ) ;
return 0 ;
}
static unsigned int F_188 ( struct V_16 * V_17 ,
struct V_112 * V_112 , unsigned int V_364 )
{
unsigned int V_398 ;
if ( V_17 -> V_365 < 0x100 || V_112 -> V_80 -> V_228 < V_399 )
return 0 ;
V_398 = V_112 -> V_62 -> V_400 . V_401 ;
return F_155 ( V_364 , V_398 + 1 ) - 1 ;
}
static unsigned int F_189 ( struct V_16 * V_17 ,
struct V_112 * V_112 , unsigned int V_364 )
{
unsigned int V_398 ;
unsigned int V_402 ;
if ( V_17 -> V_365 < 0x100 )
return 0 ;
if ( V_112 -> V_80 -> V_228 >= V_399 ) {
V_398 = V_112 -> V_62 -> V_400 . V_401 ;
V_402 = V_364 % ( V_398 + 1 ) ;
if ( V_402 == 0 )
return V_398 ;
return V_402 - 1 ;
}
if ( V_364 == 0 )
return 0 ;
return V_364 - 1 ;
}
static int F_190 ( struct V_16 * V_17 ,
struct V_112 * V_112 , int V_403 )
{
int V_404 , V_405 , V_45 = 0 ;
int V_406 , V_407 , V_408 ;
if ( V_112 -> V_80 -> V_228 == V_358 ||
V_112 -> V_80 -> V_228 == V_359 )
V_404 = V_112 -> V_404 + V_403 * V_112 -> V_357 ;
else
V_404 = ( V_112 -> V_404 + V_403 * V_112 -> V_357 ) >> 3 ;
V_405 = F_191 ( V_17 -> V_409 ) & 0x7 ;
if ( F_191 ( V_17 -> V_409 ) & ( 1 << 3 ) )
V_405 <<= 3 ;
V_408 = F_18 ( & V_17 -> V_410 -> V_411 ) ;
V_406 = F_192 ( V_408 + V_405 + 1 , 8 ) ;
V_407 = F_193 ( V_408 + 895 * 8 , 8 ) ;
V_404 &= 0x7ff ;
V_406 = ( V_406 >> 3 ) & 0x7ff ;
V_407 = ( V_407 >> 3 ) & 0x7ff ;
F_16 ( V_17 , L_125 ,
V_262 , V_403 , F_18 ( & V_17 -> V_410 -> V_411 ) ,
V_406 , V_407 , V_404 ) ;
if ( V_406 < V_407 ) {
if ( V_404 > V_407 ||
V_404 < V_406 )
V_45 = - V_342 ;
} else if ( V_406 > V_407 ) {
if ( ( V_404 > V_407 &&
V_404 < V_406 ) )
V_45 = - V_342 ;
} else {
V_45 = - V_342 ;
}
if ( V_403 == 0 ) {
if ( V_45 == - V_342 || V_404 == V_406 ) {
V_404 = V_406 + 1 ;
if ( V_112 -> V_80 -> V_228 == V_358 ||
V_112 -> V_80 -> V_228 == V_359 )
V_112 -> V_404 = V_404 ;
else
V_112 -> V_404 = V_404 << 3 ;
V_45 = 0 ;
}
}
if ( V_45 ) {
F_34 ( V_17 , L_126 ,
V_404 , V_408 , V_403 ,
V_406 , V_407 ) ;
F_34 ( V_17 , L_127 ) ;
return V_45 ;
}
return V_404 ;
}
static int F_194 ( struct V_16 * V_17 , T_8 V_337 ,
struct V_112 * V_112 , int V_57 , unsigned int V_58 )
{
struct V_11 * V_81 ;
struct V_113 * V_113 ;
struct V_75 * V_124 ;
int V_412 , V_413 ;
struct V_207 * V_264 ;
bool V_105 ;
int V_354 ;
T_2 V_28 , V_375 ;
int V_353 , V_361 , V_414 , V_415 , V_45 ;
T_3 V_416 , V_84 ;
int V_148 , V_149 ;
bool V_24 ;
struct V_61 * V_417 ;
int V_418 ;
V_417 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
V_81 = V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] . V_12 ;
V_412 = V_112 -> V_419 ;
if ( V_412 < 1 ) {
F_16 ( V_17 , L_128 ) ;
return - V_342 ;
}
V_416 = ( T_3 ) V_112 -> V_349 ;
V_264 = & V_81 -> V_26 -> V_27 ;
V_354 = V_81 -> V_22 ;
V_113 = V_112 -> V_114 ;
for ( V_148 = 0 ; V_148 < V_412 ; V_148 ++ ) {
unsigned int V_420 , V_369 ;
unsigned int V_421 , V_422 ;
T_2 V_423 ;
V_105 = true ;
V_353 = 0 ;
V_84 = V_416 + V_112 -> V_301 [ V_148 ] . V_352 ;
V_414 = V_112 -> V_301 [ V_148 ] . V_117 ;
V_415 = V_414 ;
V_369 = F_172 ( F_173 ( & V_112 -> V_62 -> V_310 ) ) ;
V_420 = F_155 ( V_414 , V_369 ) ;
if ( V_420 == 0 )
V_420 ++ ;
V_421 = F_188 ( V_17 , V_112 , V_420 ) ;
V_422 = F_189 ( V_17 ,
V_112 , V_420 ) ;
V_413 = F_162 ( V_112 , V_148 ) ;
V_45 = F_150 ( V_17 , V_17 -> V_63 [ V_57 ] , V_58 ,
V_112 -> V_59 , V_413 , V_112 , V_148 , V_337 ) ;
if ( V_45 < 0 ) {
if ( V_148 == 0 )
return V_45 ;
goto V_160;
}
V_124 = V_113 -> V_124 [ V_148 ] ;
V_423 = V_424 ;
if ( ! ( V_112 -> V_290 & V_425 ) &&
F_195 ( V_17 -> V_426 ) ) {
V_418 = F_190 ( V_17 , V_112 , V_148 ) ;
if ( V_418 >= 0 )
V_423 = F_196 ( V_418 ) ;
}
V_28 = F_40 ( V_427 ) |
F_197 ( V_422 ) |
V_423 |
( V_148 ? V_81 -> V_22 : ! V_354 ) ;
if ( ! V_417 -> V_428 )
V_28 |= F_198 ( V_421 ) ;
for ( V_149 = 0 ; V_149 < V_413 ; V_149 ++ ) {
T_2 V_376 = 0 ;
if ( ! V_105 )
V_28 = F_40 ( V_379 ) |
V_81 -> V_22 ;
if ( F_179 ( V_112 ) )
V_28 |= V_381 ;
if ( V_149 < V_413 - 1 ) {
V_24 = true ;
V_28 |= V_29 ;
} else {
V_24 = false ;
V_124 -> V_98 = V_81 -> V_26 ;
V_28 |= V_380 ;
if ( V_17 -> V_365 >= 0x100 &&
! ( V_17 -> V_32 & V_429 ) &&
V_148 < V_412 - 1 )
V_28 |= V_430 ;
}
V_361 = F_178 ( V_84 ) ;
if ( V_361 > V_415 )
V_361 = V_415 ;
V_376 = F_171 ( V_17 , V_353 ,
V_361 , V_414 ,
V_112 , V_24 ) ;
V_375 = F_138 ( V_361 ) |
F_181 ( 0 ) ;
if ( V_105 && V_417 -> V_428 )
V_375 |= F_199 ( V_421 ) ;
else
V_375 |= F_180 ( V_376 ) ;
V_105 = false ;
F_147 ( V_17 , V_81 , V_24 ,
F_182 ( V_84 ) ,
F_183 ( V_84 ) ,
V_375 ,
V_28 ) ;
V_353 += V_361 ;
V_84 += V_361 ;
V_415 -= V_361 ;
}
if ( V_353 != V_414 ) {
F_25 ( V_17 , L_129 ) ;
V_45 = - V_342 ;
goto V_160;
}
}
if ( F_195 ( V_17 -> V_426 ) )
V_417 -> V_431 = V_112 -> V_404 + V_412 * V_112 -> V_357 ;
if ( F_45 ( V_17 ) -> V_120 . V_121 == 0 ) {
if ( V_17 -> V_32 & V_122 )
F_200 () ;
}
F_45 ( V_17 ) -> V_120 . V_121 ++ ;
F_165 ( V_17 , V_57 , V_58 , V_112 -> V_59 ,
V_354 , V_264 ) ;
return 0 ;
V_160:
for ( V_148 -- ; V_148 >= 0 ; V_148 -- )
F_63 ( & V_113 -> V_124 [ V_148 ] -> V_70 ) ;
V_113 -> V_124 [ 0 ] -> V_98 = V_81 -> V_26 ;
F_39 ( V_17 , V_81 , V_113 -> V_124 [ 0 ] , true ) ;
V_81 -> V_26 = V_113 -> V_124 [ 0 ] -> V_105 ;
V_81 -> V_35 = V_113 -> V_124 [ 0 ] -> V_104 ;
V_81 -> V_22 = V_354 ;
V_81 -> V_23 = V_81 -> V_154 ;
F_47 ( F_43 ( V_112 -> V_80 -> V_116 ) , V_112 ) ;
return V_45 ;
}
int F_201 ( struct V_16 * V_17 , T_8 V_337 ,
struct V_112 * V_112 , int V_57 , unsigned int V_58 )
{
struct V_79 * V_280 ;
struct V_11 * V_81 ;
struct V_93 * V_94 ;
int V_404 ;
int V_412 , V_36 , V_148 ;
int V_45 ;
struct V_61 * V_417 ;
int V_405 ;
V_280 = V_17 -> V_63 [ V_57 ] ;
V_417 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
V_81 = V_280 -> V_64 [ V_58 ] . V_12 ;
V_94 = F_38 ( V_17 , V_280 -> V_95 , V_58 ) ;
V_36 = 0 ;
V_412 = V_112 -> V_419 ;
for ( V_148 = 0 ; V_148 < V_412 ; V_148 ++ )
V_36 += F_162 ( V_112 , V_148 ) ;
V_45 = F_148 ( V_17 , V_81 , F_7 ( V_94 -> V_165 ) & V_166 ,
V_36 , V_337 ) ;
if ( V_45 )
return V_45 ;
F_166 ( V_17 , V_112 , V_94 ) ;
if ( F_195 ( V_17 -> V_426 ) && ! F_32 ( & V_81 -> V_70 ) ) {
if ( ( F_7 ( V_94 -> V_165 ) & V_166 ) ==
V_344 ) {
V_112 -> V_404 = V_417 -> V_431 ;
goto V_432;
}
}
V_404 = F_18 ( & V_17 -> V_410 -> V_411 ) ;
V_404 &= 0x3fff ;
V_405 = F_191 ( V_17 -> V_409 ) & 0x7 ;
if ( F_191 ( V_17 -> V_409 ) & ( 1 << 3 ) )
V_405 <<= 3 ;
V_404 += V_405 + V_433 ;
V_404 = F_192 ( V_404 , 8 ) ;
if ( V_112 -> V_80 -> V_228 == V_358 ||
V_112 -> V_80 -> V_228 == V_359 ) {
V_404 = F_192 ( V_404 , V_112 -> V_357 << 3 ) ;
V_112 -> V_404 = V_404 >> 3 ;
} else {
V_404 = F_192 ( V_404 , V_112 -> V_357 ) ;
V_112 -> V_404 = V_404 ;
}
V_432:
V_81 -> V_154 = V_81 -> V_23 ;
return F_194 ( V_17 , V_337 , V_112 , V_57 , V_58 ) ;
}
static int F_202 ( struct V_16 * V_17 , struct V_174 * V_188 ,
T_2 V_333 , T_2 V_334 ,
T_2 V_335 , T_2 V_336 , bool V_434 )
{
int V_435 = V_17 -> V_436 ;
int V_45 ;
if ( ( V_17 -> V_54 & V_55 ) ||
( V_17 -> V_54 & V_329 ) ) {
F_16 ( V_17 , L_130 ) ;
return - V_56 ;
}
if ( ! V_434 )
V_435 ++ ;
V_45 = F_148 ( V_17 , V_17 -> V_47 , V_344 ,
V_435 , V_176 ) ;
if ( V_45 < 0 ) {
F_25 ( V_17 , L_131 ) ;
if ( V_434 )
F_25 ( V_17 , L_132
L_133 ) ;
return V_45 ;
}
V_188 -> V_196 = V_17 -> V_47 -> V_26 ;
F_153 ( & V_188 -> V_189 , & V_17 -> V_189 ) ;
if ( V_17 -> V_189 . V_13 == & V_188 -> V_189 &&
! F_203 ( & V_17 -> V_49 ) ) {
V_17 -> V_198 = V_188 ;
F_21 ( & V_17 -> V_49 , V_50 + V_51 ) ;
}
F_147 ( V_17 , V_17 -> V_47 , false , V_333 , V_334 , V_335 ,
V_336 | V_17 -> V_47 -> V_22 ) ;
return 0 ;
}
int F_204 ( struct V_16 * V_17 , struct V_174 * V_188 ,
T_2 V_220 , T_2 V_57 )
{
return F_202 ( V_17 , V_188 , 0 , 0 , 0 ,
F_40 ( V_220 ) | F_205 ( V_57 ) , false ) ;
}
int F_206 ( struct V_16 * V_17 , struct V_174 * V_188 ,
T_1 V_437 , T_2 V_57 , enum V_438 V_383 )
{
return F_202 ( V_17 , V_188 , F_182 ( V_437 ) ,
F_183 ( V_437 ) , 0 ,
F_40 ( V_214 ) | F_205 ( V_57 )
| ( V_383 == V_439 ? V_440 : 0 ) , false ) ;
}
int F_207 ( struct V_16 * V_17 , struct V_174 * V_188 ,
T_2 V_333 , T_2 V_334 , T_2 V_335 , T_2 V_336 )
{
return F_202 ( V_17 , V_188 , V_333 , V_334 , V_335 , V_336 , false ) ;
}
int F_208 ( struct V_16 * V_17 , struct V_174 * V_188 ,
T_2 V_57 )
{
return F_202 ( V_17 , V_188 , 0 , 0 , 0 ,
F_40 ( V_218 ) | F_205 ( V_57 ) ,
false ) ;
}
int F_80 ( struct V_16 * V_17 ,
struct V_174 * V_188 , T_1 V_437 ,
T_2 V_57 , bool V_434 )
{
return F_202 ( V_17 , V_188 , F_182 ( V_437 ) ,
F_183 ( V_437 ) , 0 ,
F_40 ( V_212 ) | F_205 ( V_57 ) ,
V_434 ) ;
}
int F_209 ( struct V_16 * V_17 , struct V_174 * V_188 ,
T_1 V_437 , T_2 V_57 , bool V_434 )
{
return F_202 ( V_17 , V_188 , F_182 ( V_437 ) ,
F_183 ( V_437 ) , 0 ,
F_40 ( V_213 ) | F_205 ( V_57 ) ,
V_434 ) ;
}
int F_210 ( struct V_16 * V_17 , struct V_174 * V_188 ,
int V_57 , unsigned int V_58 , int V_441 )
{
T_2 V_442 = F_205 ( V_57 ) ;
T_2 V_443 = F_211 ( V_58 ) ;
T_2 type = F_40 ( V_215 ) ;
T_2 V_444 = F_212 ( V_441 ) ;
return F_202 ( V_17 , V_188 , 0 , 0 , 0 ,
V_442 | V_443 | type | V_444 , false ) ;
}
void F_64 ( struct V_16 * V_17 ,
unsigned int V_57 , unsigned int V_58 ,
unsigned int V_59 ,
struct V_77 * V_142 )
{
T_1 V_84 ;
T_2 V_442 = F_205 ( V_57 ) ;
T_2 V_443 = F_211 ( V_58 ) ;
T_2 V_445 = F_213 ( V_59 ) ;
T_2 V_446 = 0 ;
T_2 type = F_40 ( V_216 ) ;
struct V_61 * V_62 ;
struct V_174 * V_188 ;
int V_45 ;
F_36 ( V_17 , V_88 ,
L_134 ,
V_142 -> V_99 ,
( unsigned long long ) V_142 -> V_99 -> V_8 ,
V_142 -> V_100 ,
( unsigned long long ) F_1 (
V_142 -> V_99 , V_142 -> V_100 ) ,
V_142 -> V_97 ) ;
V_84 = F_1 ( V_142 -> V_99 ,
V_142 -> V_100 ) ;
if ( V_84 == 0 ) {
F_34 ( V_17 , L_135 ) ;
F_34 ( V_17 , L_136 ,
V_142 -> V_99 , V_142 -> V_100 ) ;
return;
}
V_62 = & V_17 -> V_63 [ V_57 ] -> V_64 [ V_58 ] ;
if ( ( V_62 -> V_65 & V_67 ) ) {
F_34 ( V_17 , L_135 ) ;
F_34 ( V_17 , L_137 ) ;
return;
}
V_188 = F_79 ( V_17 , false , false , V_176 ) ;
if ( ! V_188 ) {
F_34 ( V_17 , L_138 ) ;
return;
}
V_62 -> V_171 = V_142 -> V_99 ;
V_62 -> V_156 = V_142 -> V_100 ;
if ( V_59 )
V_446 = F_214 ( V_447 ) ;
V_45 = F_202 ( V_17 , V_188 ,
F_182 ( V_84 ) | V_446 | V_142 -> V_97 ,
F_183 ( V_84 ) , V_445 ,
V_442 | V_443 | type , false ) ;
if ( V_45 < 0 ) {
F_215 ( V_17 , V_188 ) ;
return;
}
V_62 -> V_65 |= V_67 ;
}
int F_127 ( struct V_16 * V_17 , struct V_174 * V_188 ,
int V_57 , unsigned int V_58 )
{
T_2 V_442 = F_205 ( V_57 ) ;
T_2 V_443 = F_211 ( V_58 ) ;
T_2 type = F_40 ( V_217 ) ;
return F_202 ( V_17 , V_188 , 0 , 0 , 0 ,
V_442 | V_443 | type , false ) ;
}
