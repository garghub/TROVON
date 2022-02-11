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
static bool F_2 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_1 * V_2 , union V_3 * V_4 )
{
if ( V_12 == V_10 -> V_13 )
return ( V_4 == & V_2 -> V_6 [ V_7 ] ) &&
( V_2 -> V_14 == V_10 -> V_13 -> V_15 ) ;
else
return F_3 ( V_4 -> V_16 . V_17 ) & V_18 ;
}
static int F_4 ( struct V_9 * V_10 , struct V_11 * V_12 ,
struct V_1 * V_2 , union V_3 * V_4 )
{
if ( V_12 == V_10 -> V_13 )
return V_4 == & V_2 -> V_6 [ V_7 ] ;
else
return F_5 ( V_4 -> V_16 . V_17 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_19 * V_16 = & V_12 -> V_20 -> V_16 ;
return F_5 ( V_16 -> V_17 ) ;
}
static void F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_1 * * V_2 ,
union V_3 * * V_4 )
{
if ( F_4 ( V_10 , V_12 , * V_2 , * V_4 ) ) {
* V_2 = ( * V_2 ) -> V_14 ;
* V_4 = ( ( * V_2 ) -> V_6 ) ;
} else {
( * V_4 ) ++ ;
}
}
static void F_8 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
V_12 -> V_21 ++ ;
if ( V_12 -> type != V_22 &&
! F_4 ( V_10 , V_12 , V_12 -> V_23 , V_12 -> V_24 ) )
V_12 -> V_25 ++ ;
do {
if ( F_4 ( V_10 , V_12 , V_12 -> V_23 , V_12 -> V_24 ) ) {
if ( V_12 -> type == V_22 &&
F_2 ( V_10 , V_12 ,
V_12 -> V_23 , V_12 -> V_24 ) ) {
V_12 -> V_26 ^= 1 ;
}
V_12 -> V_23 = V_12 -> V_23 -> V_14 ;
V_12 -> V_24 = V_12 -> V_23 -> V_6 ;
} else {
V_12 -> V_24 ++ ;
}
} while ( F_4 ( V_10 , V_12 , V_12 -> V_23 , V_12 -> V_24 ) );
}
static void F_9 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_27 )
{
T_2 V_28 ;
union V_3 * V_14 ;
V_28 = F_3 ( V_12 -> V_20 -> V_29 . V_30 [ 3 ] ) & V_31 ;
if ( V_12 -> type != V_22 &&
! F_4 ( V_10 , V_12 , V_12 -> V_32 , V_12 -> V_20 ) )
V_12 -> V_25 -- ;
V_14 = ++ ( V_12 -> V_20 ) ;
V_12 -> V_33 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_32 , V_14 ) ) {
if ( V_12 -> type != V_22 ) {
if ( ! V_28 && ! V_27 )
break;
if ( ! ( V_12 -> type == V_34 &&
( V_10 -> V_35 & V_36 ) )
&& ! F_10 ( V_10 ) ) {
V_14 -> V_16 . V_17 &=
F_11 ( ~ V_31 ) ;
V_14 -> V_16 . V_17 |=
F_11 ( V_28 ) ;
}
F_12 () ;
V_14 -> V_16 . V_17 ^= F_11 ( V_37 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_32 , V_14 ) ) {
V_12 -> V_26 ^= 1 ;
}
}
V_12 -> V_32 = V_12 -> V_32 -> V_14 ;
V_12 -> V_20 = V_12 -> V_32 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
static inline int F_13 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_38 )
{
int V_39 ;
if ( V_12 -> V_25 < V_38 )
return 0 ;
if ( V_12 -> type != V_40 && V_12 -> type != V_22 ) {
V_39 = V_12 -> V_24 - V_12 -> V_23 -> V_6 ;
if ( V_12 -> V_25 < V_38 + V_39 )
return 0 ;
}
return 1 ;
}
void F_14 ( struct V_9 * V_10 )
{
if ( ! ( V_10 -> V_41 & V_42 ) )
return;
F_15 ( V_10 , L_1 ) ;
F_16 ( V_43 , & V_10 -> V_44 -> V_45 [ 0 ] ) ;
F_17 ( & V_10 -> V_44 -> V_45 [ 0 ] ) ;
}
static int F_18 ( struct V_9 * V_10 )
{
T_3 V_46 ;
int V_47 ;
F_15 ( V_10 , L_2 ) ;
V_46 = F_19 ( V_10 , & V_10 -> V_48 -> V_49 ) ;
V_10 -> V_41 = V_50 ;
F_20 ( V_10 , V_46 | V_51 ,
& V_10 -> V_48 -> V_49 ) ;
V_47 = F_21 ( & V_10 -> V_48 -> V_49 ,
V_52 , 0 , 5 * 1000 * 1000 ) ;
if ( V_47 < 0 ) {
F_20 ( V_10 , V_46 | V_51 ,
& V_10 -> V_48 -> V_49 ) ;
F_22 ( 1000 ) ;
V_47 = F_21 ( & V_10 -> V_48 -> V_49 ,
V_52 , 0 , 3 * 1000 * 1000 ) ;
if ( V_47 == 0 )
return 0 ;
F_23 ( V_10 , L_3
L_4 ) ;
V_10 -> V_53 |= V_54 ;
F_24 ( V_10 ) ;
F_25 ( V_10 ) ;
return - V_55 ;
}
return 0 ;
}
void F_26 ( struct V_9 * V_10 ,
unsigned int V_56 ,
unsigned int V_57 ,
unsigned int V_58 )
{
T_4 T_5 * V_59 = & V_10 -> V_44 -> V_45 [ V_56 ] ;
struct V_60 * V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
unsigned int V_64 = V_61 -> V_64 ;
if ( ( V_64 & V_65 ) || ( V_64 & V_66 ) ||
( V_64 & V_67 ) )
return;
F_16 ( F_27 ( V_57 , V_58 ) , V_59 ) ;
}
static void F_28 ( struct V_9 * V_10 ,
unsigned int V_56 ,
unsigned int V_57 )
{
unsigned int V_58 ;
struct V_60 * V_61 ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ! ( V_61 -> V_64 & V_68 ) ) {
if ( V_61 -> V_12 && ! ( F_29 ( & V_61 -> V_12 -> V_69 ) ) )
F_26 ( V_10 , V_56 , V_57 , 0 ) ;
return;
}
for ( V_58 = 1 ; V_58 < V_61 -> V_70 -> V_71 ;
V_58 ++ ) {
struct V_72 * V_70 = V_61 -> V_70 ;
if ( ! F_29 ( & V_70 -> V_73 [ V_58 ] -> V_69 ) )
F_26 ( V_10 , V_56 , V_57 ,
V_58 ) ;
}
}
static struct V_11 * F_30 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 )
{
struct V_60 * V_61 ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ! ( V_61 -> V_64 & V_68 ) )
return V_61 -> V_12 ;
if ( V_58 == 0 ) {
F_31 ( V_10 ,
L_5
L_6 ,
V_56 , V_57 ) ;
return NULL ;
}
if ( V_58 < V_61 -> V_70 -> V_71 )
return V_61 -> V_70 -> V_73 [ V_58 ] ;
F_31 ( V_10 ,
L_7
L_8
L_9 ,
V_56 , V_57 ,
V_61 -> V_70 -> V_71 - 1 ,
V_58 ) ;
return NULL ;
}
static struct V_11 * F_32 ( struct V_9 * V_10 ,
struct V_74 * V_74 )
{
return F_30 ( V_10 , V_74 -> V_75 -> V_56 ,
F_33 ( & V_74 -> V_61 -> V_76 ) , V_74 -> V_58 ) ;
}
void F_34 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 , struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_81 * V_75 = V_10 -> V_62 [ V_56 ] ;
struct V_60 * V_61 = & V_75 -> V_63 [ V_57 ] ;
struct V_11 * V_82 ;
struct V_1 * V_83 ;
union V_3 * V_84 ;
T_1 V_85 ;
T_3 V_86 ;
bool V_87 = false ;
bool V_88 = false ;
V_82 = F_30 ( V_10 , V_56 ,
V_57 , V_58 ) ;
if ( ! V_82 ) {
F_31 ( V_10 , L_10
L_11 ,
V_58 ) ;
return;
}
F_35 ( V_10 , V_89 ,
L_12 ) ;
if ( V_61 -> V_64 & V_68 ) {
struct V_90 * V_91 =
& V_61 -> V_70 -> V_92 [ V_58 ] ;
V_86 = F_36 ( V_91 -> V_93 ) ;
} else {
struct V_94 * V_95
= F_37 ( V_10 , V_75 -> V_96 , V_57 ) ;
V_86 = F_36 ( V_95 -> V_97 ) ;
}
V_83 = V_82 -> V_23 ;
V_84 = V_82 -> V_24 ;
V_80 -> V_98 = V_86 & 0x1 ;
do {
if ( ! V_87 && F_1 ( V_83 , V_84 )
== ( T_1 ) ( V_86 & ~ 0xf ) ) {
V_87 = true ;
if ( V_88 )
break;
}
if ( V_84 == V_78 -> F_4 )
V_88 = true ;
if ( V_87 &&
F_5 ( V_84 -> V_29 . V_30 [ 3 ] ) &&
V_84 -> V_29 . V_30 [ 3 ] & F_11 ( V_18 ) )
V_80 -> V_98 ^= 0x1 ;
F_7 ( V_10 , V_82 , & V_83 , & V_84 ) ;
if ( V_84 == V_61 -> V_12 -> V_24 ) {
F_23 ( V_10 , L_13 ) ;
V_80 -> V_99 = NULL ;
V_80 -> V_100 = NULL ;
return;
}
} while ( ! V_87 || ! V_88 );
V_80 -> V_99 = V_83 ;
V_80 -> V_100 = V_84 ;
F_35 ( V_10 , V_89 ,
L_14 , V_80 -> V_98 ) ;
F_35 ( V_10 , V_89 ,
L_15 ,
V_80 -> V_99 ) ;
V_85 = F_1 ( V_80 -> V_99 , V_80 -> V_100 ) ;
F_35 ( V_10 , V_89 ,
L_16 ,
( unsigned long long ) V_85 ) ;
}
static void F_38 ( struct V_9 * V_10 , struct V_11 * V_82 ,
struct V_77 * V_78 , bool V_101 )
{
struct V_1 * V_102 ;
union V_3 * V_103 ;
for ( V_102 = V_78 -> V_104 , V_103 = V_78 -> V_105 ;
true ;
F_7 ( V_10 , V_82 , & V_102 , & V_103 ) ) {
if ( F_5 ( V_103 -> V_29 . V_30 [ 3 ] ) ) {
V_103 -> V_29 . V_30 [ 3 ] &= F_11 ( ~ V_31 ) ;
if ( V_101 )
V_103 -> V_29 . V_30 [ 3 ] ^=
F_11 ( V_37 ) ;
F_35 ( V_10 , V_89 ,
L_17 ) ;
F_35 ( V_10 , V_89 ,
L_18
L_19 ,
V_103 ,
( unsigned long long ) F_1 ( V_102 , V_103 ) ,
V_102 ,
( unsigned long long ) V_102 -> V_8 ) ;
} else {
V_103 -> V_29 . V_30 [ 0 ] = 0 ;
V_103 -> V_29 . V_30 [ 1 ] = 0 ;
V_103 -> V_29 . V_30 [ 2 ] = 0 ;
V_103 -> V_29 . V_30 [ 3 ] &= F_11 ( V_37 ) ;
if ( V_101 && V_103 != V_78 -> V_105 &&
V_103 != V_78 -> F_4 )
V_103 -> V_29 . V_30 [ 3 ] ^=
F_11 ( V_37 ) ;
V_103 -> V_29 . V_30 [ 3 ] |= F_11 (
F_39 ( V_106 ) ) ;
F_35 ( V_10 , V_89 ,
L_20 ,
( unsigned long long )
F_1 ( V_102 , V_103 ) ) ;
}
if ( V_103 == V_78 -> F_4 )
break;
}
}
static void F_40 ( struct V_9 * V_10 ,
struct V_60 * V_61 )
{
V_61 -> V_64 &= ~ V_65 ;
if ( F_41 ( & V_61 -> V_107 ) )
V_61 -> V_108 -- ;
}
static void F_42 ( struct V_9 * V_10 ,
struct V_77 * V_78 , int V_109 )
{
struct V_110 * V_111 ;
struct V_74 * V_74 ;
struct V_112 * V_112 ;
V_74 = V_78 -> V_74 ;
V_112 = V_74 -> V_113 ;
V_112 -> V_114 ++ ;
V_111 = F_43 ( V_74 -> V_75 -> V_115 ) ;
if ( V_112 -> V_114 == V_112 -> V_116 ) {
if ( F_44 ( V_74 -> V_117 ) == V_118 ) {
F_45 ( V_10 ) -> V_119 . V_120 -- ;
if ( F_45 ( V_10 ) -> V_119 . V_120 == 0 ) {
if ( V_10 -> V_35 & V_121 )
F_46 () ;
}
}
F_47 ( V_111 , V_74 ) ;
F_48 ( & V_10 -> V_122 ) ;
F_49 ( V_111 , V_74 , V_109 ) ;
F_50 ( V_112 ) ;
F_51 ( & V_10 -> V_122 ) ;
}
}
static void F_52 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , struct V_123 * V_124 )
{
unsigned int V_57 ;
struct V_11 * V_82 ;
struct V_60 * V_61 ;
struct V_125 * V_126 ;
struct V_77 * V_78 = NULL ;
struct V_77 * V_127 ;
struct V_79 V_128 ;
if ( F_53 ( F_54 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ) ) {
if ( ! V_10 -> V_62 [ V_56 ] )
F_31 ( V_10 , L_21
L_22 ,
V_56 ) ;
return;
}
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_57 = F_55 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( F_29 ( & V_61 -> V_129 ) ) {
F_40 ( V_10 , V_61 ) ;
V_61 -> V_130 = NULL ;
F_28 ( V_10 , V_56 , V_57 ) ;
return;
}
F_56 (entry, &ep->cancelled_td_list) {
V_78 = F_57 ( V_126 , struct V_77 , V_129 ) ;
F_35 ( V_10 , V_89 ,
L_23 ,
( unsigned long long ) F_1 (
V_78 -> V_104 , V_78 -> V_105 ) ) ;
V_82 = F_32 ( V_10 , V_78 -> V_74 ) ;
if ( ! V_82 ) {
F_31 ( V_10 , L_24
L_25 ,
V_78 -> V_74 ,
V_78 -> V_74 -> V_58 ) ;
goto V_131;
}
if ( V_78 == V_61 -> V_130 )
F_34 ( V_10 , V_56 , V_57 ,
V_78 -> V_74 -> V_58 ,
V_78 , & V_128 ) ;
else
F_38 ( V_10 , V_82 , V_78 , false ) ;
V_131:
F_58 ( & V_78 -> V_69 ) ;
}
V_127 = V_78 ;
F_40 ( V_10 , V_61 ) ;
if ( V_128 . V_100 && V_128 . V_99 ) {
F_59 ( V_10 , V_56 , V_57 ,
V_61 -> V_130 -> V_74 -> V_58 , & V_128 ) ;
F_14 ( V_10 ) ;
} else {
F_28 ( V_10 , V_56 , V_57 ) ;
}
V_61 -> V_130 = NULL ;
do {
V_78 = F_57 ( V_61 -> V_129 . V_14 ,
struct V_77 , V_129 ) ;
F_58 ( & V_78 -> V_129 ) ;
F_42 ( V_10 , V_78 , 0 ) ;
if ( V_10 -> V_53 & V_54 )
return;
} while ( V_78 != V_127 );
}
static void F_60 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_77 * V_78 ;
while ( ! F_29 ( & V_12 -> V_69 ) ) {
V_78 = F_61 ( & V_12 -> V_69 ,
struct V_77 , V_69 ) ;
F_58 ( & V_78 -> V_69 ) ;
if ( ! F_29 ( & V_78 -> V_129 ) )
F_58 ( & V_78 -> V_129 ) ;
F_42 ( V_10 , V_78 , - V_55 ) ;
}
}
static void F_62 ( struct V_9 * V_10 ,
int V_56 , int V_57 )
{
struct V_77 * V_78 ;
struct V_60 * V_61 ;
struct V_11 * V_12 ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ( V_61 -> V_64 & V_68 ) ||
( V_61 -> V_64 & V_132 ) ) {
int V_58 ;
for ( V_58 = 0 ; V_58 < V_61 -> V_70 -> V_71 ;
V_58 ++ ) {
F_35 ( V_10 , V_89 ,
L_26 ,
V_56 , V_57 , V_58 + 1 ) ;
F_60 ( V_10 ,
V_61 -> V_70 -> V_73 [ V_58 ] ) ;
}
} else {
V_12 = V_61 -> V_12 ;
if ( ! V_12 )
return;
F_35 ( V_10 , V_89 ,
L_27 ,
V_56 , V_57 ) ;
F_60 ( V_10 , V_12 ) ;
}
while ( ! F_29 ( & V_61 -> V_129 ) ) {
V_78 = F_61 ( & V_61 -> V_129 ,
struct V_77 , V_129 ) ;
F_58 ( & V_78 -> V_129 ) ;
F_42 ( V_10 , V_78 , - V_55 ) ;
}
}
void F_63 ( unsigned long V_133 )
{
struct V_9 * V_10 ;
struct V_60 * V_61 ;
int V_47 , V_134 , V_135 ;
unsigned long V_136 ;
V_61 = (struct V_60 * ) V_133 ;
V_10 = V_61 -> V_10 ;
F_64 ( & V_10 -> V_122 , V_136 ) ;
V_61 -> V_108 -- ;
if ( V_10 -> V_53 & V_54 ) {
F_35 ( V_10 , V_89 ,
L_28
L_29 ) ;
F_65 ( & V_10 -> V_122 , V_136 ) ;
return;
}
if ( ! ( V_61 -> V_108 == 0 && ( V_61 -> V_64 & V_65 ) ) ) {
F_35 ( V_10 , V_89 ,
L_30
L_31 ) ;
F_65 ( & V_10 -> V_122 , V_136 ) ;
return;
}
F_31 ( V_10 , L_32 ) ;
F_31 ( V_10 , L_33 ) ;
V_10 -> V_53 |= V_54 ;
F_24 ( V_10 ) ;
F_65 ( & V_10 -> V_122 , V_136 ) ;
V_47 = F_25 ( V_10 ) ;
F_64 ( & V_10 -> V_122 , V_136 ) ;
if ( V_47 < 0 ) {
F_31 ( V_10 , L_34 ) ;
F_31 ( V_10 , L_35 ) ;
}
for ( V_134 = 0 ; V_134 < V_137 ; V_134 ++ ) {
if ( ! V_10 -> V_62 [ V_134 ] )
continue;
for ( V_135 = 0 ; V_135 < 31 ; V_135 ++ )
F_62 ( V_10 , V_134 , V_135 ) ;
}
F_65 ( & V_10 -> V_122 , V_136 ) ;
F_35 ( V_10 , V_89 ,
L_36 ) ;
F_66 ( F_45 ( V_10 ) -> V_138 ) ;
F_35 ( V_10 , V_89 ,
L_37 ) ;
}
static void F_67 ( struct V_9 * V_10 ,
struct V_81 * V_75 ,
struct V_11 * V_82 ,
unsigned int V_57 )
{
union V_3 * V_139 ;
int V_140 ;
bool V_141 = false ;
V_140 = V_82 -> V_25 ;
V_139 = V_82 -> V_24 ;
if ( F_4 ( V_10 , V_82 , V_82 -> V_23 , V_82 -> V_24 ) ) {
V_82 -> V_23 = V_82 -> V_23 -> V_14 ;
V_82 -> V_24 = V_82 -> V_23 -> V_6 ;
}
while ( V_82 -> V_24 != V_75 -> V_63 [ V_57 ] . V_142 ) {
V_82 -> V_25 ++ ;
V_82 -> V_24 ++ ;
if ( F_4 ( V_10 , V_82 , V_82 -> V_23 ,
V_82 -> V_24 ) ) {
if ( V_82 -> V_24 ==
V_75 -> V_63 [ V_57 ] . V_142 )
break;
V_82 -> V_23 = V_82 -> V_23 -> V_14 ;
V_82 -> V_24 = V_82 -> V_23 -> V_6 ;
}
if ( V_82 -> V_24 == V_139 ) {
V_141 = true ;
break;
}
}
if ( V_141 ) {
F_15 ( V_10 , L_38 ) ;
V_82 -> V_25 = V_140 ;
}
}
static void F_68 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , T_2 V_143 )
{
unsigned int V_57 ;
unsigned int V_58 ;
struct V_11 * V_82 ;
struct V_81 * V_75 ;
struct V_60 * V_61 ;
struct V_94 * V_95 ;
struct V_144 * V_145 ;
V_57 = F_55 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_58 = F_69 ( F_3 ( V_4 -> V_29 . V_30 [ 2 ] ) ) ;
V_75 = V_10 -> V_62 [ V_56 ] ;
V_61 = & V_75 -> V_63 [ V_57 ] ;
V_82 = F_70 ( V_75 , V_57 , V_58 ) ;
if ( ! V_82 ) {
F_31 ( V_10 , L_39 ,
V_58 ) ;
goto V_146;
}
V_95 = F_37 ( V_10 , V_75 -> V_96 , V_57 ) ;
V_145 = F_71 ( V_10 , V_75 -> V_96 ) ;
if ( V_143 != V_147 ) {
unsigned int V_64 ;
unsigned int V_148 ;
switch ( V_143 ) {
case V_149 :
F_31 ( V_10 , L_40 ) ;
break;
case V_150 :
F_31 ( V_10 , L_41 ) ;
V_64 = F_3 ( V_95 -> V_151 ) ;
V_64 &= V_152 ;
V_148 = F_3 ( V_145 -> V_153 ) ;
V_148 = F_72 ( V_148 ) ;
F_35 ( V_10 , V_89 ,
L_42 ,
V_148 , V_64 ) ;
break;
case V_154 :
F_31 ( V_10 , L_43 ,
V_56 ) ;
break;
default:
F_31 ( V_10 , L_44 ,
V_143 ) ;
break;
}
} else {
T_3 V_97 ;
if ( V_61 -> V_64 & V_68 ) {
struct V_90 * V_91 =
& V_61 -> V_70 -> V_92 [ V_58 ] ;
V_97 = F_36 ( V_91 -> V_93 ) & V_155 ;
} else {
V_97 = F_36 ( V_95 -> V_97 ) & ~ V_156 ;
}
F_35 ( V_10 , V_89 ,
L_45 , V_97 ) ;
if ( F_1 ( V_61 -> V_157 ,
V_61 -> V_142 ) == V_97 ) {
F_67 ( V_10 , V_75 ,
V_82 , V_57 ) ;
} else {
F_31 ( V_10 , L_46 ) ;
F_31 ( V_10 , L_47 ,
V_61 -> V_157 , V_61 -> V_142 ) ;
}
}
V_146:
V_75 -> V_63 [ V_57 ] . V_64 &= ~ V_66 ;
V_75 -> V_63 [ V_57 ] . V_157 = NULL ;
V_75 -> V_63 [ V_57 ] . V_142 = NULL ;
F_28 ( V_10 , V_56 , V_57 ) ;
}
static void F_73 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , T_2 V_143 )
{
unsigned int V_57 ;
V_57 = F_55 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
F_35 ( V_10 , V_158 ,
L_48 , V_143 ) ;
if ( V_10 -> V_35 & V_159 ) {
struct V_160 * V_161 ;
V_161 = F_74 ( V_10 , false , false , V_162 ) ;
if ( ! V_161 ) {
F_31 ( V_10 , L_49 ) ;
return;
}
F_35 ( V_10 , V_163 ,
L_50 ) ;
F_75 ( V_10 , V_161 ,
V_10 -> V_62 [ V_56 ] -> V_164 -> V_8 , V_56 ,
false ) ;
F_14 ( V_10 ) ;
} else {
V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] . V_64 &= ~ V_67 ;
}
}
static void F_76 ( struct V_9 * V_10 , int V_56 ,
T_2 V_143 )
{
if ( V_143 == V_147 )
V_10 -> V_56 = V_56 ;
else
V_10 -> V_56 = 0 ;
}
static void F_77 ( struct V_9 * V_10 , int V_56 )
{
struct V_81 * V_165 ;
V_165 = V_10 -> V_62 [ V_56 ] ;
if ( ! V_165 )
return;
if ( V_10 -> V_35 & V_166 )
F_78 ( V_10 , V_165 , true ) ;
F_79 ( V_10 , V_56 ) ;
}
static void F_80 ( struct V_9 * V_10 , int V_56 ,
struct V_123 * V_124 , T_2 V_143 )
{
struct V_81 * V_165 ;
struct V_167 * V_168 ;
unsigned int V_57 ;
unsigned int V_64 ;
T_2 V_169 , V_170 ;
V_165 = V_10 -> V_62 [ V_56 ] ;
V_168 = F_81 ( V_165 -> V_164 ) ;
if ( ! V_168 ) {
F_31 ( V_10 , L_51 ) ;
return;
}
V_169 = F_3 ( V_168 -> V_169 ) ;
V_170 = F_3 ( V_168 -> V_170 ) ;
V_57 = F_82 ( V_169 ) - 1 ;
if ( V_10 -> V_35 & V_159 &&
V_57 != ( unsigned int ) - 1 &&
V_169 - V_171 == V_170 ) {
V_64 = V_165 -> V_63 [ V_57 ] . V_64 ;
if ( ! ( V_64 & V_67 ) )
return;
F_35 ( V_10 , V_163 ,
L_52
L_53 ,
V_57 , V_64 ) ;
V_165 -> V_63 [ V_57 ] . V_64 &= ~ V_67 ;
F_28 ( V_10 , V_56 , V_57 ) ;
return;
}
return;
}
static void F_83 ( struct V_9 * V_10 , int V_56 ,
struct V_123 * V_124 )
{
F_15 ( V_10 , L_54 ) ;
if ( ! V_10 -> V_62 [ V_56 ] )
F_31 ( V_10 , L_55
L_56 , V_56 ) ;
}
static void F_84 ( struct V_9 * V_10 ,
struct V_123 * V_124 )
{
if ( ! ( V_10 -> V_35 & V_172 ) ) {
V_10 -> V_173 |= 1 << 6 ;
return;
}
F_35 ( V_10 , V_163 ,
L_57 ,
F_85 ( F_3 ( V_124 -> V_109 ) ) ,
F_86 ( F_3 ( V_124 -> V_109 ) ) ) ;
}
static void F_87 ( struct V_160 * V_174 , T_2 V_109 )
{
F_88 ( & V_174 -> V_175 ) ;
if ( V_174 -> V_176 ) {
V_174 -> V_109 = V_109 ;
F_89 ( V_174 -> V_176 ) ;
} else {
F_90 ( V_174 ) ;
}
}
void F_91 ( struct V_9 * V_10 )
{
struct V_160 * V_177 , * V_178 ;
F_92 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_87 ( V_177 , V_179 ) ;
}
static void F_93 ( struct V_9 * V_10 ,
struct V_160 * V_177 )
{
struct V_160 * V_180 , * V_178 ;
T_2 V_26 ;
F_92 (i_cmd, tmp_cmd, &xhci->cmd_list,
cmd_list) {
if ( V_180 -> V_109 != V_179 )
continue;
V_180 -> V_109 = V_181 ;
F_15 ( V_10 , L_58 ,
V_180 -> V_182 ) ;
V_26 = F_3 (
V_180 -> V_182 -> V_29 . V_30 [ 3 ] ) & V_37 ;
V_180 -> V_182 -> V_29 . V_30 [ 0 ] = 0 ;
V_180 -> V_182 -> V_29 . V_30 [ 1 ] = 0 ;
V_180 -> V_182 -> V_29 . V_30 [ 2 ] = 0 ;
V_180 -> V_182 -> V_29 . V_30 [ 3 ] = F_11 (
F_39 ( V_183 ) | V_26 ) ;
}
V_10 -> V_41 = V_42 ;
if ( ( V_10 -> V_49 -> V_24 != V_10 -> V_49 -> V_20 ) &&
! ( V_10 -> V_53 & V_54 ) ) {
V_10 -> V_184 = V_177 ;
F_94 ( & V_10 -> V_185 , V_186 + V_187 ) ;
F_14 ( V_10 ) ;
}
return;
}
void F_95 ( unsigned long V_188 )
{
struct V_9 * V_10 ;
int V_47 ;
unsigned long V_136 ;
T_3 V_189 ;
struct V_160 * V_177 = NULL ;
V_10 = (struct V_9 * ) V_188 ;
F_64 ( & V_10 -> V_122 , V_136 ) ;
if ( V_10 -> V_184 ) {
V_177 = V_10 -> V_184 ;
V_177 -> V_109 = V_179 ;
}
V_189 = F_19 ( V_10 , & V_10 -> V_48 -> V_49 ) ;
if ( ( V_10 -> V_41 & V_42 ) &&
( V_189 & V_52 ) ) {
F_65 ( & V_10 -> V_122 , V_136 ) ;
F_15 ( V_10 , L_59 ) ;
V_47 = F_18 ( V_10 ) ;
if ( F_53 ( V_47 == - V_55 ) ) {
F_23 ( V_10 , L_60 ) ;
F_91 ( V_10 ) ;
F_66 ( F_45 ( V_10 ) -> V_138 ) ;
F_15 ( V_10 , L_61 ) ;
}
return;
}
F_15 ( V_10 , L_62 ) ;
F_93 ( V_10 , V_10 -> V_184 ) ;
F_65 ( & V_10 -> V_122 , V_136 ) ;
return;
}
static void F_96 ( struct V_9 * V_10 ,
struct V_123 * V_124 )
{
int V_56 = F_97 ( F_3 ( V_124 -> V_136 ) ) ;
T_3 V_190 ;
T_1 V_191 ;
T_2 V_143 ;
union V_3 * V_192 ;
struct V_160 * V_174 ;
T_2 V_193 ;
V_190 = F_36 ( V_124 -> V_192 ) ;
V_192 = V_10 -> V_49 -> V_24 ;
V_191 = F_1 ( V_10 -> V_49 -> V_23 ,
V_192 ) ;
if ( V_191 == 0 ) {
V_10 -> V_173 |= 1 << 4 ;
return;
}
if ( V_190 != ( T_3 ) V_191 ) {
V_10 -> V_173 |= 1 << 5 ;
return;
}
V_174 = F_57 ( V_10 -> V_175 . V_14 , struct V_160 , V_175 ) ;
if ( V_174 -> V_182 != V_10 -> V_49 -> V_24 ) {
F_23 ( V_10 ,
L_63 ) ;
return;
}
F_41 ( & V_10 -> V_185 ) ;
F_98 ( V_192 , (struct V_194 * ) V_124 ) ;
V_143 = F_99 ( F_3 ( V_124 -> V_109 ) ) ;
if ( V_143 == V_181 ) {
F_93 ( V_10 , V_174 ) ;
return;
}
if ( V_143 == V_179 ) {
V_10 -> V_41 = V_195 ;
if ( V_174 -> V_109 == V_179 )
goto V_196;
}
V_193 = F_100 ( F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ;
switch ( V_193 ) {
case V_197 :
F_76 ( V_10 , V_56 , V_143 ) ;
break;
case V_198 :
F_77 ( V_10 , V_56 ) ;
break;
case V_199 :
if ( ! V_174 -> V_176 )
F_80 ( V_10 , V_56 , V_124 ,
V_143 ) ;
break;
case V_200 :
break;
case V_201 :
break;
case V_202 :
F_101 ( V_56 != F_97 (
F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_52 ( V_10 , V_56 , V_192 , V_124 ) ;
break;
case V_203 :
F_101 ( V_56 != F_97 (
F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_68 ( V_10 , V_56 , V_192 , V_143 ) ;
break;
case V_183 :
if ( V_174 -> V_109 == V_181 )
V_143 = V_181 ;
break;
case V_204 :
F_101 ( V_56 != F_97 (
F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_73 ( V_10 , V_56 , V_192 , V_143 ) ;
break;
case V_205 :
V_56 = F_97 (
F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ;
F_83 ( V_10 , V_56 , V_124 ) ;
break;
case V_206 :
F_84 ( V_10 , V_124 ) ;
break;
default:
V_10 -> V_173 |= 1 << 6 ;
break;
}
if ( V_174 -> V_175 . V_14 != & V_10 -> V_175 ) {
V_10 -> V_184 = F_57 ( V_174 -> V_175 . V_14 ,
struct V_160 , V_175 ) ;
F_94 ( & V_10 -> V_185 , V_186 + V_187 ) ;
}
V_196:
F_87 ( V_174 , V_143 ) ;
F_8 ( V_10 , V_10 -> V_49 ) ;
}
static void F_102 ( struct V_9 * V_10 ,
union V_3 * V_124 )
{
T_2 V_207 ;
V_207 = F_100 ( F_3 ( V_124 -> V_29 . V_30 [ 3 ] ) ) ;
F_15 ( V_10 , L_64 , V_207 ) ;
if ( V_207 == V_208 && ( V_10 -> V_35 & V_172 ) )
F_96 ( V_10 , & V_124 -> V_209 ) ;
}
static unsigned int F_103 ( struct V_110 * V_111 ,
struct V_9 * V_10 , T_2 V_210 )
{
unsigned int V_134 ;
unsigned int V_211 = 0 ;
for ( V_134 = 0 ; V_134 < ( V_210 - 1 ) ; V_134 ++ ) {
T_6 V_212 = V_10 -> V_213 [ V_134 ] ;
if ( V_212 == 0 || V_212 == V_214 )
continue;
if ( ( V_212 == 0x03 ) == ( V_111 -> V_215 >= V_216 ) )
V_211 ++ ;
}
return V_211 ;
}
static void F_104 ( struct V_9 * V_10 ,
union V_3 * V_124 )
{
T_2 V_56 ;
struct V_217 * V_218 ;
V_56 = F_97 ( F_3 ( V_124 -> V_29 . V_30 [ 3 ] ) ) ;
if ( ! V_10 -> V_62 [ V_56 ] ) {
F_31 ( V_10 , L_65
L_66 , V_56 ) ;
return;
}
F_15 ( V_10 , L_67 ,
V_56 ) ;
V_218 = V_10 -> V_62 [ V_56 ] -> V_218 ;
if ( V_218 && V_218 -> V_219 )
F_105 ( V_218 -> V_219 , V_218 -> V_220 ) ;
}
static void F_106 ( struct V_9 * V_10 ,
union V_3 * V_124 )
{
struct V_110 * V_111 ;
T_2 V_210 ;
T_2 V_221 , V_222 ;
int V_223 ;
int V_56 ;
unsigned int V_224 ;
T_6 V_225 ;
struct V_226 * V_227 ;
T_4 T_5 * * V_213 ;
bool V_228 = false ;
if ( F_99 ( F_3 ( V_124 -> V_29 . V_30 [ 2 ] ) ) != V_147 ) {
F_31 ( V_10 , L_68 ) ;
V_10 -> V_173 |= 1 << 8 ;
}
V_210 = F_107 ( F_3 ( V_124 -> V_29 . V_30 [ 0 ] ) ) ;
F_15 ( V_10 , L_69 , V_210 ) ;
V_223 = F_108 ( V_10 -> V_229 ) ;
if ( ( V_210 <= 0 ) || ( V_210 > V_223 ) ) {
F_31 ( V_10 , L_70 , V_210 ) ;
F_8 ( V_10 , V_10 -> V_13 ) ;
return;
}
V_225 = V_10 -> V_213 [ V_210 - 1 ] ;
V_111 = F_45 ( V_10 ) ;
if ( ( V_225 == 0x03 ) != ( V_111 -> V_215 >= V_216 ) )
V_111 = V_10 -> V_230 ;
if ( V_225 == 0 ) {
F_31 ( V_10 , L_71
L_72 ,
V_210 ) ;
V_228 = true ;
goto V_146;
}
if ( V_225 == V_214 ) {
F_31 ( V_10 , L_73
L_72 ,
V_210 ) ;
V_228 = true ;
goto V_146;
}
V_227 = & V_10 -> V_227 [ F_109 ( V_111 ) ] ;
if ( V_111 -> V_215 >= V_216 )
V_213 = V_10 -> V_231 ;
else
V_213 = V_10 -> V_232 ;
V_224 = F_103 ( V_111 , V_10 ,
V_210 ) ;
V_221 = F_17 ( V_213 [ V_224 ] ) ;
if ( V_111 -> V_80 == V_233 ) {
F_15 ( V_10 , L_74 ) ;
F_110 ( V_111 ) ;
}
if ( V_111 -> V_215 >= V_216 && ( V_221 & V_234 ) == V_235 )
V_227 -> V_236 &= ~ ( 1 << V_224 ) ;
if ( ( V_221 & V_237 ) && ( V_221 & V_234 ) == V_238 ) {
F_15 ( V_10 , L_75 , V_210 ) ;
V_222 = F_17 ( & V_10 -> V_48 -> V_161 ) ;
if ( ! ( V_222 & V_239 ) ) {
F_31 ( V_10 , L_76 ) ;
goto V_146;
}
if ( F_111 ( V_221 ) ) {
F_15 ( V_10 , L_77 , V_210 ) ;
V_227 -> V_236 |= 1 << V_224 ;
F_112 ( V_10 , V_213 ,
V_224 , V_237 ) ;
F_113 ( V_10 , V_213 , V_224 ,
V_240 ) ;
V_228 = true ;
goto V_146;
} else if ( ! F_114 ( V_224 ,
& V_227 -> V_241 ) ) {
F_15 ( V_10 , L_78 , V_210 ) ;
V_227 -> V_242 [ V_224 ] = V_186 +
F_115 ( V_243 ) ;
F_116 ( V_224 , & V_227 -> V_241 ) ;
F_94 ( & V_111 -> V_244 ,
V_227 -> V_242 [ V_224 ] ) ;
}
}
if ( ( V_221 & V_237 ) && ( V_221 & V_234 ) == V_240 &&
F_111 ( V_221 ) ) {
F_15 ( V_10 , L_79 , V_210 ) ;
V_56 = F_117 ( V_111 , V_10 ,
V_224 + 1 ) ;
if ( V_56 && V_10 -> V_62 [ V_56 ] )
F_118 ( V_10 , V_56 ) ;
if ( V_227 -> V_236 & ( 1 << V_224 ) ) {
V_227 -> V_236 &=
~ ( 1 << V_224 ) ;
F_112 ( V_10 , V_213 ,
V_224 , V_237 ) ;
F_105 ( V_111 -> V_119 . V_245 ,
V_224 + 1 ) ;
V_228 = true ;
goto V_146;
}
}
if ( ! F_111 ( V_221 ) &&
F_119 ( V_224 ,
& V_227 -> V_246 ) ) {
F_89 ( & V_227 -> V_247 [ V_224 ] ) ;
V_228 = true ;
goto V_146;
}
if ( V_111 -> V_215 < V_216 )
F_112 ( V_10 , V_213 , V_224 ,
V_237 ) ;
V_146:
F_8 ( V_10 , V_10 -> V_13 ) ;
if ( V_228 )
return;
F_15 ( V_10 , L_80 , V_248 ) ;
F_116 ( V_249 , & V_111 -> V_136 ) ;
F_48 ( & V_10 -> V_122 ) ;
F_120 ( V_111 ) ;
F_51 ( & V_10 -> V_122 ) ;
}
struct V_1 * F_121 ( struct V_9 * V_10 ,
struct V_1 * V_104 ,
union V_3 * V_250 ,
union V_3 * V_251 ,
T_1 V_252 ,
bool V_253 )
{
T_1 V_254 ;
T_1 V_255 ;
T_1 V_256 ;
struct V_1 * V_102 ;
V_254 = F_1 ( V_104 , V_250 ) ;
V_102 = V_104 ;
do {
if ( V_254 == 0 )
return NULL ;
V_255 = F_1 ( V_102 ,
& V_102 -> V_6 [ V_7 - 1 ] ) ;
V_256 = F_1 ( V_102 , V_251 ) ;
if ( V_253 )
F_31 ( V_10 ,
L_81 ,
( unsigned long long ) V_252 ,
( unsigned long long ) V_254 ,
( unsigned long long ) V_256 ,
( unsigned long long ) V_102 -> V_8 ,
( unsigned long long ) V_255 ) ;
if ( V_256 > 0 ) {
if ( V_254 <= V_256 ) {
if ( V_252 >= V_254 && V_252 <= V_256 )
return V_102 ;
} else {
if ( ( V_252 >= V_254 &&
V_252 <= V_255 ) ||
( V_252 >= V_102 -> V_8 &&
V_252 <= V_256 ) )
return V_102 ;
}
return NULL ;
} else {
if ( V_252 >= V_254 && V_252 <= V_255 )
return V_102 ;
}
V_102 = V_102 -> V_14 ;
V_254 = F_1 ( V_102 , & V_102 -> V_6 [ 0 ] ) ;
} while ( V_102 != V_104 );
return NULL ;
}
static void F_122 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 ,
struct V_77 * V_257 , union V_3 * V_258 )
{
struct V_60 * V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
struct V_160 * V_161 ;
V_161 = F_74 ( V_10 , false , false , V_162 ) ;
if ( ! V_161 )
return;
V_61 -> V_64 |= V_67 ;
V_61 -> V_259 = V_58 ;
F_123 ( V_10 , V_161 , V_56 , V_57 ) ;
F_124 ( V_10 , V_57 , V_257 ) ;
V_61 -> V_259 = 0 ;
F_14 ( V_10 ) ;
}
static int F_125 ( struct V_9 * V_10 ,
struct V_94 * V_95 ,
unsigned int V_260 )
{
if ( V_260 == V_261 ||
V_260 == V_262 ||
V_260 == V_263 )
if ( ( V_95 -> V_151 & F_11 ( V_152 ) ) ==
F_11 ( V_264 ) )
return 1 ;
return 0 ;
}
int F_126 ( struct V_9 * V_10 , unsigned int V_260 )
{
if ( V_260 >= 224 && V_260 <= 255 ) {
F_15 ( V_10 , L_82 ,
V_260 ) ;
F_15 ( V_10 , L_83 ) ;
return 1 ;
}
return 0 ;
}
static int F_127 ( struct V_9 * V_10 , struct V_77 * V_257 ,
union V_3 * V_258 , struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 , bool V_266 )
{
struct V_81 * V_267 ;
struct V_11 * V_82 ;
unsigned int V_56 ;
int V_57 ;
struct V_74 * V_74 = NULL ;
struct V_94 * V_95 ;
int V_47 = 0 ;
struct V_112 * V_112 ;
T_2 V_260 ;
V_56 = F_97 ( F_3 ( V_124 -> V_136 ) ) ;
V_267 = V_10 -> V_62 [ V_56 ] ;
V_57 = F_128 ( F_3 ( V_124 -> V_136 ) ) - 1 ;
V_82 = F_129 ( V_61 , F_36 ( V_124 -> V_268 ) ) ;
V_95 = F_37 ( V_10 , V_267 -> V_96 , V_57 ) ;
V_260 = F_99 ( F_3 ( V_124 -> V_269 ) ) ;
if ( V_266 )
goto V_270;
if ( V_260 == V_271 ||
V_260 == V_272 ||
V_260 == V_273 ) {
V_61 -> V_130 = V_257 ;
return 0 ;
}
if ( V_260 == V_274 ||
F_125 ( V_10 , V_95 ,
V_260 ) ) {
F_122 ( V_10 , V_56 , V_57 ,
V_82 -> V_58 , V_257 , V_258 ) ;
} else {
while ( V_82 -> V_24 != V_257 -> F_4 )
F_8 ( V_10 , V_82 ) ;
F_8 ( V_10 , V_82 ) ;
}
V_270:
V_74 = V_257 -> V_74 ;
V_112 = V_74 -> V_113 ;
if ( V_74 -> V_275 > V_74 -> V_276 ) {
F_31 ( V_10 , L_84 ,
V_74 -> V_276 ,
V_74 -> V_275 ) ;
V_74 -> V_275 = 0 ;
if ( V_257 -> V_74 -> V_277 & V_278 )
* V_109 = - V_279 ;
else
* V_109 = 0 ;
}
F_58 ( & V_257 -> V_69 ) ;
if ( ! F_29 ( & V_257 -> V_129 ) )
F_58 ( & V_257 -> V_129 ) ;
V_112 -> V_114 ++ ;
if ( V_112 -> V_114 == V_112 -> V_116 ) {
V_47 = 1 ;
if ( F_44 ( V_74 -> V_117 ) == V_118 ) {
F_45 ( V_10 ) -> V_119 . V_120 -- ;
if ( F_45 ( V_10 ) -> V_119 . V_120 == 0 ) {
if ( V_10 -> V_35 & V_121 )
F_46 () ;
}
}
}
return V_47 ;
}
static int F_130 ( struct V_9 * V_10 , struct V_77 * V_257 ,
union V_3 * V_258 , struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 )
{
struct V_81 * V_267 ;
struct V_11 * V_82 ;
unsigned int V_56 ;
int V_57 ;
struct V_94 * V_95 ;
T_2 V_260 ;
V_56 = F_97 ( F_3 ( V_124 -> V_136 ) ) ;
V_267 = V_10 -> V_62 [ V_56 ] ;
V_57 = F_128 ( F_3 ( V_124 -> V_136 ) ) - 1 ;
V_82 = F_129 ( V_61 , F_36 ( V_124 -> V_268 ) ) ;
V_95 = F_37 ( V_10 , V_267 -> V_96 , V_57 ) ;
V_260 = F_99 ( F_3 ( V_124 -> V_269 ) ) ;
switch ( V_260 ) {
case V_147 :
if ( V_258 == V_82 -> V_24 ) {
F_31 ( V_10 , L_85
L_86 ) ;
* V_109 = - V_55 ;
} else if ( V_258 != V_257 -> F_4 ) {
F_31 ( V_10 , L_87
L_86 ) ;
* V_109 = - V_55 ;
} else {
* V_109 = 0 ;
}
break;
case V_280 :
if ( V_257 -> V_74 -> V_277 & V_278 )
* V_109 = - V_279 ;
else
* V_109 = 0 ;
break;
case V_273 :
if ( V_258 == V_82 -> V_24 || V_258 == V_257 -> F_4 )
F_31 ( V_10 , L_88 ) ;
else
V_257 -> V_74 -> V_275 =
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
return F_127 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
case V_272 :
if ( V_258 != V_82 -> V_24 && V_258 != V_257 -> F_4 )
V_257 -> V_74 -> V_275 =
V_257 -> V_74 -> V_276 -
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
case V_271 :
return F_127 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
default:
if ( ! F_125 ( V_10 ,
V_95 , V_260 ) )
break;
F_15 ( V_10 , L_89
L_90 ,
V_260 , V_57 ) ;
case V_274 :
if ( V_258 != V_82 -> V_24 &&
V_258 != V_257 -> F_4 )
V_257 -> V_74 -> V_275 =
V_257 -> V_74 -> V_276 -
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
else if ( ! V_257 -> V_281 )
V_257 -> V_74 -> V_275 = 0 ;
return F_127 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
}
if ( V_258 != V_82 -> V_24 ) {
if ( V_258 == V_257 -> F_4 ) {
if ( V_257 -> V_281 ) {
if ( ( * V_109 == - V_282 || * V_109 == 0 ) &&
( V_257 -> V_74 -> V_277
& V_278 ) )
* V_109 = - V_279 ;
} else {
V_257 -> V_74 -> V_275 =
V_257 -> V_74 -> V_276 ;
}
} else {
V_257 -> V_281 = true ;
V_257 -> V_74 -> V_275 =
V_257 -> V_74 -> V_276 -
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
F_15 ( V_10 , L_91
L_92 ) ;
return 0 ;
}
}
return F_127 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
}
static int F_132 ( struct V_9 * V_10 , struct V_77 * V_257 ,
union V_3 * V_258 , struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 )
{
struct V_11 * V_82 ;
struct V_112 * V_112 ;
int V_283 ;
int V_284 = 0 ;
union V_3 * V_103 ;
struct V_1 * V_102 ;
struct V_285 * V_286 ;
T_2 V_260 ;
bool V_287 = false ;
V_82 = F_129 ( V_61 , F_36 ( V_124 -> V_268 ) ) ;
V_260 = F_99 ( F_3 ( V_124 -> V_269 ) ) ;
V_112 = V_257 -> V_74 -> V_113 ;
V_283 = V_112 -> V_114 ;
V_286 = & V_257 -> V_74 -> V_288 [ V_283 ] ;
switch ( V_260 ) {
case V_147 :
if ( F_131 ( F_3 ( V_124 -> V_269 ) ) == 0 ) {
V_286 -> V_109 = 0 ;
break;
}
if ( ( V_10 -> V_35 & V_289 ) )
V_260 = V_280 ;
case V_273 :
case V_280 :
V_286 -> V_109 = V_257 -> V_74 -> V_277 & V_278 ?
- V_279 : 0 ;
break;
case V_290 :
V_286 -> V_109 = - V_291 ;
V_287 = true ;
break;
case V_292 :
case V_262 :
V_286 -> V_109 = - V_293 ;
V_287 = true ;
break;
case V_294 :
case V_274 :
V_286 -> V_109 = - V_295 ;
V_287 = true ;
break;
case V_261 :
V_286 -> V_109 = - V_295 ;
if ( V_258 != V_257 -> F_4 )
return 0 ;
V_287 = true ;
break;
case V_272 :
case V_271 :
break;
default:
V_286 -> V_109 = - 1 ;
break;
}
if ( V_260 == V_147 || V_287 ) {
V_286 -> V_275 = V_286 -> V_116 ;
V_257 -> V_74 -> V_275 += V_286 -> V_116 ;
} else if ( V_260 == V_273 ) {
V_286 -> V_275 =
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
V_257 -> V_74 -> V_275 += V_286 -> V_275 ;
} else {
for ( V_103 = V_82 -> V_24 ,
V_102 = V_82 -> V_23 ; V_103 != V_258 ;
F_7 ( V_10 , V_82 , & V_102 , & V_103 ) ) {
if ( ! F_133 ( V_103 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_103 -> V_29 . V_30 [ 3 ] ) )
V_284 += F_134 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) ;
}
V_284 += F_134 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) -
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
if ( V_260 != V_271 ) {
V_286 -> V_275 = V_284 ;
V_257 -> V_74 -> V_275 += V_284 ;
}
}
return F_127 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
}
static int F_135 ( struct V_9 * V_10 , struct V_77 * V_257 ,
struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 )
{
struct V_11 * V_82 ;
struct V_112 * V_112 ;
struct V_285 * V_286 ;
int V_283 ;
V_82 = F_129 ( V_61 , F_36 ( V_124 -> V_268 ) ) ;
V_112 = V_257 -> V_74 -> V_113 ;
V_283 = V_112 -> V_114 ;
V_286 = & V_257 -> V_74 -> V_288 [ V_283 ] ;
V_286 -> V_109 = - V_296 ;
V_286 -> V_275 = 0 ;
while ( V_82 -> V_24 != V_257 -> F_4 )
F_8 ( V_10 , V_82 ) ;
F_8 ( V_10 , V_82 ) ;
return F_127 ( V_10 , V_257 , NULL , V_124 , V_61 , V_109 , true ) ;
}
static int F_136 ( struct V_9 * V_10 , struct V_77 * V_257 ,
union V_3 * V_258 , struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 )
{
struct V_11 * V_82 ;
union V_3 * V_103 ;
struct V_1 * V_102 ;
T_2 V_260 ;
V_82 = F_129 ( V_61 , F_36 ( V_124 -> V_268 ) ) ;
V_260 = F_99 ( F_3 ( V_124 -> V_269 ) ) ;
switch ( V_260 ) {
case V_147 :
if ( V_258 != V_257 -> F_4 ||
F_131 ( F_3 ( V_124 -> V_269 ) ) != 0 ) {
F_31 ( V_10 , L_93
L_94 ) ;
if ( V_257 -> V_74 -> V_277 & V_278 )
* V_109 = - V_279 ;
else
* V_109 = 0 ;
if ( ( V_10 -> V_35 & V_289 ) )
V_260 = V_280 ;
} else {
* V_109 = 0 ;
}
break;
case V_273 :
case V_280 :
if ( V_257 -> V_74 -> V_277 & V_278 )
* V_109 = - V_279 ;
else
* V_109 = 0 ;
break;
default:
break;
}
if ( V_260 == V_280 )
F_15 ( V_10 , L_95
L_96 ,
V_257 -> V_74 -> V_61 -> V_76 . V_297 ,
V_257 -> V_74 -> V_276 ,
F_131 ( F_3 ( V_124 -> V_269 ) ) ) ;
if ( V_260 == V_273 ) {
V_257 -> V_74 -> V_275 =
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
if ( V_257 -> V_74 -> V_276 <
V_257 -> V_74 -> V_275 ) {
F_31 ( V_10 , L_97 ,
F_131 ( F_3 ( V_124 -> V_269 ) ) ) ;
V_257 -> V_74 -> V_275 = 0 ;
}
} else if ( V_258 == V_257 -> F_4 ) {
if ( F_131 ( F_3 ( V_124 -> V_269 ) ) != 0 ) {
V_257 -> V_74 -> V_275 =
V_257 -> V_74 -> V_276 -
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
if ( V_257 -> V_74 -> V_276 <
V_257 -> V_74 -> V_275 ) {
F_31 ( V_10 , L_98
L_99 ,
F_131 ( F_3 ( V_124 -> V_269 ) ) ) ;
V_257 -> V_74 -> V_275 = 0 ;
if ( V_257 -> V_74 -> V_277 & V_278 )
* V_109 = - V_279 ;
else
* V_109 = 0 ;
}
if ( * V_109 == - V_282 ) {
if ( V_257 -> V_74 -> V_277 & V_278 )
* V_109 = - V_279 ;
else
* V_109 = 0 ;
}
} else {
V_257 -> V_74 -> V_275 =
V_257 -> V_74 -> V_276 ;
if ( * V_109 == - V_279 )
* V_109 = 0 ;
}
} else {
V_257 -> V_74 -> V_275 = 0 ;
for ( V_103 = V_82 -> V_24 , V_102 = V_82 -> V_23 ;
V_103 != V_258 ;
F_7 ( V_10 , V_82 , & V_102 , & V_103 ) ) {
if ( ! F_133 ( V_103 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_103 -> V_29 . V_30 [ 3 ] ) )
V_257 -> V_74 -> V_275 +=
F_134 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) ;
}
if ( V_260 != V_271 )
V_257 -> V_74 -> V_275 +=
F_134 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) -
F_131 ( F_3 ( V_124 -> V_269 ) ) ;
}
return F_127 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
}
static int F_137 ( struct V_9 * V_10 ,
struct V_265 * V_124 )
__releases( &xhci->lock
static int F_138 ( struct V_9 * V_10 )
{
union V_3 * V_124 ;
int V_298 = 1 ;
int V_47 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_24 ) {
V_10 -> V_173 |= 1 << 1 ;
return 0 ;
}
V_124 = V_10 -> V_13 -> V_24 ;
if ( ( F_3 ( V_124 -> V_209 . V_136 ) & V_37 ) !=
V_10 -> V_13 -> V_26 ) {
V_10 -> V_173 |= 1 << 2 ;
return 0 ;
}
F_139 () ;
switch ( ( F_3 ( V_124 -> V_209 . V_136 ) & V_299 ) ) {
case F_39 ( V_300 ) :
F_96 ( V_10 , & V_124 -> V_209 ) ;
break;
case F_39 ( V_301 ) :
F_106 ( V_10 , V_124 ) ;
V_298 = 0 ;
break;
case F_39 ( V_302 ) :
V_47 = F_137 ( V_10 , & V_124 -> V_303 ) ;
if ( V_47 < 0 )
V_10 -> V_173 |= 1 << 9 ;
else
V_298 = 0 ;
break;
case F_39 ( V_304 ) :
F_104 ( V_10 , V_124 ) ;
break;
default:
if ( ( F_3 ( V_124 -> V_209 . V_136 ) & V_299 ) >=
F_39 ( 48 ) )
F_102 ( V_10 , V_124 ) ;
else
V_10 -> V_173 |= 1 << 3 ;
}
if ( V_10 -> V_53 & V_54 ) {
F_15 ( V_10 , L_100
L_101 ) ;
return 0 ;
}
if ( V_298 )
F_8 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_140 ( struct V_110 * V_111 )
{
struct V_9 * V_10 = F_141 ( V_111 ) ;
T_2 V_109 ;
T_3 V_46 ;
union V_3 * V_305 ;
T_1 V_97 ;
F_51 ( & V_10 -> V_122 ) ;
V_109 = F_17 ( & V_10 -> V_48 -> V_109 ) ;
if ( V_109 == 0xffffffff )
goto V_306;
if ( ! ( V_109 & V_307 ) ) {
F_48 ( & V_10 -> V_122 ) ;
return V_308 ;
}
if ( V_109 & V_309 ) {
F_31 ( V_10 , L_102 ) ;
F_25 ( V_10 ) ;
V_306:
F_48 ( & V_10 -> V_122 ) ;
return V_310 ;
}
V_109 |= V_307 ;
F_16 ( V_109 , & V_10 -> V_48 -> V_109 ) ;
if ( V_111 -> V_311 ) {
T_2 V_312 ;
V_312 = F_17 ( & V_10 -> V_313 -> V_312 ) ;
V_312 |= V_314 ;
F_16 ( V_312 , & V_10 -> V_313 -> V_312 ) ;
}
if ( V_10 -> V_53 & V_54 ) {
F_15 ( V_10 , L_103
L_104 ) ;
V_46 = F_19 ( V_10 , & V_10 -> V_313 -> V_315 ) ;
F_20 ( V_10 , V_46 | V_316 ,
& V_10 -> V_313 -> V_315 ) ;
F_48 ( & V_10 -> V_122 ) ;
return V_310 ;
}
V_305 = V_10 -> V_13 -> V_24 ;
while ( F_138 ( V_10 ) > 0 ) {}
V_46 = F_19 ( V_10 , & V_10 -> V_313 -> V_315 ) ;
if ( V_305 != V_10 -> V_13 -> V_24 ) {
V_97 = F_1 ( V_10 -> V_13 -> V_23 ,
V_10 -> V_13 -> V_24 ) ;
if ( V_97 == 0 )
F_31 ( V_10 , L_105
L_106 ) ;
V_46 &= V_317 ;
V_46 |= ( ( T_3 ) V_97 & ( T_3 ) ~ V_317 ) ;
}
V_46 |= V_316 ;
F_20 ( V_10 , V_46 , & V_10 -> V_313 -> V_315 ) ;
F_48 ( & V_10 -> V_122 ) ;
return V_310 ;
}
T_7 F_142 ( int V_311 , void * V_111 )
{
return F_140 ( V_111 ) ;
}
static void F_143 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_27 ,
T_2 V_318 , T_2 V_319 , T_2 V_320 , T_2 V_321 )
{
struct V_194 * V_4 ;
V_4 = & V_12 -> V_20 -> V_29 ;
V_4 -> V_30 [ 0 ] = F_11 ( V_318 ) ;
V_4 -> V_30 [ 1 ] = F_11 ( V_319 ) ;
V_4 -> V_30 [ 2 ] = F_11 ( V_320 ) ;
V_4 -> V_30 [ 3 ] = F_11 ( V_321 ) ;
F_9 ( V_10 , V_12 , V_27 ) ;
}
static int F_144 ( struct V_9 * V_10 , struct V_11 * V_82 ,
T_2 V_64 , unsigned int V_38 , T_8 V_322 )
{
unsigned int V_323 ;
switch ( V_64 ) {
case V_324 :
F_31 ( V_10 , L_107 ) ;
return - V_325 ;
case V_326 :
F_31 ( V_10 , L_108 ) ;
return - V_327 ;
case V_264 :
F_15 ( V_10 , L_109 ) ;
case V_328 :
case V_329 :
break;
default:
F_23 ( V_10 , L_110 ) ;
return - V_327 ;
}
while ( 1 ) {
if ( F_13 ( V_10 , V_82 , V_38 ) )
break;
if ( V_82 == V_10 -> V_49 ) {
F_23 ( V_10 , L_111 ) ;
return - V_330 ;
}
F_35 ( V_10 , V_331 ,
L_112 ) ;
V_323 = V_38 - V_82 -> V_25 ;
if ( F_145 ( V_10 , V_82 , V_323 ,
V_322 ) ) {
F_23 ( V_10 , L_113 ) ;
return - V_330 ;
}
}
if ( F_6 ( V_82 ) ) {
struct V_11 * V_12 = V_82 ;
union V_3 * V_14 ;
V_14 = V_12 -> V_20 ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_32 , V_14 ) ) {
if ( ! F_10 ( V_10 ) &&
! ( V_12 -> type == V_34 &&
( V_10 -> V_35 & V_36 ) ) )
V_14 -> V_16 . V_17 &= F_11 ( ~ V_31 ) ;
else
V_14 -> V_16 . V_17 |= F_11 ( V_31 ) ;
F_12 () ;
V_14 -> V_16 . V_17 ^= F_11 ( V_37 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_32 , V_14 ) ) {
V_12 -> V_26 ^= 1 ;
}
V_12 -> V_32 = V_12 -> V_32 -> V_14 ;
V_12 -> V_20 = V_12 -> V_32 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
return 0 ;
}
static int F_146 ( struct V_9 * V_10 ,
struct V_81 * V_267 ,
unsigned int V_57 ,
unsigned int V_58 ,
unsigned int V_38 ,
struct V_74 * V_74 ,
unsigned int V_332 ,
T_8 V_322 )
{
int V_47 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
struct V_11 * V_82 ;
struct V_94 * V_95 = F_37 ( V_10 , V_267 -> V_96 , V_57 ) ;
V_82 = F_70 ( V_267 , V_57 , V_58 ) ;
if ( ! V_82 ) {
F_15 ( V_10 , L_114 ,
V_58 ) ;
return - V_327 ;
}
V_47 = F_144 ( V_10 , V_82 ,
F_3 ( V_95 -> V_151 ) & V_152 ,
V_38 , V_322 ) ;
if ( V_47 )
return V_47 ;
V_112 = V_74 -> V_113 ;
V_257 = V_112 -> V_257 [ V_332 ] ;
F_147 ( & V_257 -> V_69 ) ;
F_147 ( & V_257 -> V_129 ) ;
if ( V_332 == 0 ) {
V_47 = F_148 ( F_43 ( V_74 -> V_75 -> V_115 ) , V_74 ) ;
if ( F_53 ( V_47 ) )
return V_47 ;
}
V_257 -> V_74 = V_74 ;
F_149 ( & V_257 -> V_69 , & V_82 -> V_69 ) ;
V_257 -> V_104 = V_82 -> V_32 ;
V_257 -> V_105 = V_82 -> V_20 ;
V_112 -> V_257 [ V_332 ] = V_257 ;
return 0 ;
}
static unsigned int F_150 ( struct V_9 * V_10 , struct V_74 * V_74 )
{
int V_333 , V_38 , V_334 , V_221 , V_134 ;
struct V_335 * V_336 ;
V_336 = NULL ;
V_333 = V_74 -> V_337 ;
V_221 = V_74 -> V_276 ;
V_38 = 0 ;
F_151 (urb->sg, sg, num_sgs, i) {
unsigned int V_284 = F_152 ( V_336 ) ;
V_334 = V_338 -
( F_153 ( V_336 ) & ( V_338 - 1 ) ) ;
V_334 &= V_338 - 1 ;
if ( V_334 != 0 )
V_38 ++ ;
while ( V_334 < F_152 ( V_336 ) && V_334 < V_221 ) {
V_38 ++ ;
V_334 += V_338 ;
}
V_284 = F_154 ( int , V_284 , V_221 ) ;
V_221 -= V_284 ;
if ( V_221 == 0 )
break;
}
return V_38 ;
}
static void F_155 ( struct V_74 * V_74 , int V_38 , int V_334 )
{
if ( V_38 != 0 )
F_156 ( & V_74 -> V_75 -> V_75 , L_115
L_116 , V_248 ,
V_74 -> V_61 -> V_76 . V_297 , V_38 ) ;
if ( V_334 != V_74 -> V_276 )
F_156 ( & V_74 -> V_75 -> V_75 , L_117
L_118 ,
V_248 ,
V_74 -> V_61 -> V_76 . V_297 ,
V_334 , V_334 ,
V_74 -> V_276 ,
V_74 -> V_276 ) ;
}
static void F_157 ( struct V_9 * V_10 , int V_56 ,
unsigned int V_57 , unsigned int V_58 , int V_339 ,
struct V_194 * V_250 )
{
F_12 () ;
if ( V_339 )
V_250 -> V_30 [ 3 ] |= F_11 ( V_339 ) ;
else
V_250 -> V_30 [ 3 ] &= F_11 ( ~ V_37 ) ;
F_26 ( V_10 , V_56 , V_57 , V_58 ) ;
}
int F_158 ( struct V_9 * V_10 , T_8 V_322 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_94 * V_95 = F_37 ( V_10 ,
V_10 -> V_62 [ V_56 ] -> V_96 , V_57 ) ;
int V_340 ;
int V_341 ;
V_340 = F_159 ( F_3 ( V_95 -> V_151 ) ) ;
V_341 = V_74 -> V_342 ;
if ( V_74 -> V_75 -> V_215 == V_343 ||
V_74 -> V_75 -> V_215 == V_344 )
V_341 *= 8 ;
if ( V_340 != V_341 ) {
F_160 ( & V_74 -> V_75 -> V_75 ,
L_119 ,
V_341 , V_341 == 1 ? L_120 : L_121 ,
V_340 , V_340 == 1 ? L_120 : L_121 ) ;
V_74 -> V_342 = V_340 ;
if ( V_74 -> V_75 -> V_215 == V_343 ||
V_74 -> V_75 -> V_215 == V_344 )
V_74 -> V_342 /= 8 ;
}
return F_161 ( V_10 , V_322 , V_74 , V_56 , V_57 ) ;
}
static T_2 F_162 ( struct V_9 * V_10 , int V_345 ,
int V_346 , unsigned int V_347 ,
struct V_74 * V_74 , unsigned int V_348 )
{
T_2 V_349 , V_350 ;
if ( V_10 -> V_351 < 0x100 && ! ( V_10 -> V_35 & V_352 ) )
return ( ( V_347 - V_345 ) >> 10 ) ;
if ( V_348 == 0 || ( V_345 == 0 && V_346 == 0 ) ||
V_346 == V_347 )
return 0 ;
if ( V_10 -> V_35 & V_352 )
V_346 = 0 ;
V_349 = F_163 ( F_164 ( & V_74 -> V_61 -> V_76 ) ) ;
V_350 = F_165 ( V_347 , V_349 ) ;
return ( V_350 - ( ( V_345 + V_346 ) / V_349 ) ) ;
}
static int F_166 ( struct V_9 * V_10 , T_8 V_322 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
unsigned int V_38 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
struct V_335 * V_336 ;
int V_333 ;
int V_346 , V_353 , V_334 , V_47 ;
unsigned int V_350 ;
bool V_354 ;
bool V_105 ;
int V_355 ;
T_3 V_85 ;
bool V_27 ;
struct V_194 * V_250 ;
int V_339 ;
V_82 = F_32 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_327 ;
V_38 = F_150 ( V_10 , V_74 ) ;
V_333 = V_74 -> V_337 ;
V_350 = F_165 ( V_74 -> V_276 ,
F_164 ( & V_74 -> V_61 -> V_76 ) ) ;
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_322 ) ;
if ( V_47 < 0 )
return V_47 ;
V_112 = V_74 -> V_113 ;
V_354 = V_74 -> V_277 & V_356 &&
V_112 -> V_116 == 2 ;
if ( V_354 ) {
V_38 ++ ;
F_15 ( V_10 , L_122 ) ;
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
1 , V_74 , 1 , V_322 ) ;
if ( V_47 < 0 )
return V_47 ;
}
V_257 = V_112 -> V_257 [ 0 ] ;
V_250 = & V_82 -> V_20 -> V_29 ;
V_339 = V_82 -> V_26 ;
V_334 = 0 ;
V_336 = V_74 -> V_336 ;
V_85 = ( T_3 ) F_153 ( V_336 ) ;
V_353 = F_152 ( V_336 ) ;
V_346 = V_338 - ( V_85 & ( V_338 - 1 ) ) ;
V_346 = F_154 ( int , V_346 , V_353 ) ;
if ( V_346 > V_74 -> V_276 )
V_346 = V_74 -> V_276 ;
V_105 = true ;
V_355 = V_354 ? 2 : 1 ;
do {
T_2 V_30 = 0 ;
T_2 V_357 = 0 ;
T_2 V_358 = 0 ;
if ( V_105 ) {
V_105 = false ;
if ( V_339 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_82 -> V_26 ;
if ( V_38 > V_355 ) {
V_30 |= V_31 ;
} else if ( V_38 == V_355 ) {
V_257 -> F_4 = V_82 -> V_20 ;
V_30 |= V_359 ;
} else if ( V_354 && V_38 == 1 ) {
V_346 = 0 ;
V_112 -> V_257 [ 1 ] -> F_4 = V_82 -> V_20 ;
V_30 |= V_359 ;
}
if ( F_167 ( V_74 ) )
V_30 |= V_360 ;
if ( V_338 -
( V_85 & ( V_338 - 1 ) ) < V_346 ) {
F_31 ( V_10 , L_123 ) ;
F_15 ( V_10 , L_124 ,
( unsigned int ) ( V_85 + V_338 ) & ~ ( V_338 - 1 ) ,
( unsigned int ) V_85 + V_346 ) ;
}
V_358 = F_162 ( V_10 , V_334 , V_346 ,
V_74 -> V_276 ,
V_74 , V_38 - 1 ) ;
V_357 = F_134 ( V_346 ) |
F_168 ( V_358 ) |
F_169 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_143 ( V_10 , V_82 , V_27 ,
F_170 ( V_85 ) ,
F_171 ( V_85 ) ,
V_357 ,
V_30 | F_39 ( V_361 ) ) ;
-- V_38 ;
V_334 += V_346 ;
V_353 -= V_346 ;
if ( V_353 == 0 ) {
-- V_333 ;
if ( V_333 == 0 )
break;
V_336 = F_172 ( V_336 ) ;
V_85 = ( T_3 ) F_153 ( V_336 ) ;
V_353 = F_152 ( V_336 ) ;
} else {
V_85 += V_346 ;
}
V_346 = V_338 -
( V_85 & ( V_338 - 1 ) ) ;
V_346 = F_154 ( int , V_346 , V_353 ) ;
if ( V_334 + V_346 > V_74 -> V_276 )
V_346 =
V_74 -> V_276 - V_334 ;
} while ( V_38 > 0 );
F_155 ( V_74 , V_38 , V_334 ) ;
F_157 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_339 , V_250 ) ;
return 0 ;
}
int F_161 ( struct V_9 * V_10 , T_8 V_322 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
int V_38 ;
struct V_194 * V_250 ;
bool V_105 ;
int V_355 ;
bool V_27 ;
bool V_354 ;
int V_339 ;
T_2 V_30 , V_357 ;
int V_334 , V_346 , V_47 ;
unsigned int V_350 ;
T_3 V_85 ;
if ( V_74 -> V_333 )
return F_166 ( V_10 , V_322 , V_74 , V_56 , V_57 ) ;
V_82 = F_32 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_327 ;
V_38 = 0 ;
V_334 = V_338 -
( V_74 -> V_362 & ( V_338 - 1 ) ) ;
V_334 &= V_338 - 1 ;
if ( V_334 != 0 || V_74 -> V_276 == 0 )
V_38 ++ ;
while ( V_334 < V_74 -> V_276 ) {
V_38 ++ ;
V_334 += V_338 ;
}
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_322 ) ;
if ( V_47 < 0 )
return V_47 ;
V_112 = V_74 -> V_113 ;
V_354 = V_74 -> V_277 & V_356 &&
V_112 -> V_116 == 2 ;
if ( V_354 ) {
V_38 ++ ;
F_15 ( V_10 , L_122 ) ;
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
1 , V_74 , 1 , V_322 ) ;
if ( V_47 < 0 )
return V_47 ;
}
V_257 = V_112 -> V_257 [ 0 ] ;
V_250 = & V_82 -> V_20 -> V_29 ;
V_339 = V_82 -> V_26 ;
V_334 = 0 ;
V_350 = F_165 ( V_74 -> V_276 ,
F_164 ( & V_74 -> V_61 -> V_76 ) ) ;
V_85 = ( T_3 ) V_74 -> V_362 ;
V_346 = V_338 -
( V_74 -> V_362 & ( V_338 - 1 ) ) ;
if ( V_346 > V_74 -> V_276 )
V_346 = V_74 -> V_276 ;
V_105 = true ;
V_355 = V_354 ? 2 : 1 ;
do {
T_2 V_358 = 0 ;
V_30 = 0 ;
if ( V_105 ) {
V_105 = false ;
if ( V_339 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_82 -> V_26 ;
if ( V_38 > V_355 ) {
V_30 |= V_31 ;
} else if ( V_38 == V_355 ) {
V_257 -> F_4 = V_82 -> V_20 ;
V_30 |= V_359 ;
} else if ( V_354 && V_38 == 1 ) {
V_346 = 0 ;
V_112 -> V_257 [ 1 ] -> F_4 = V_82 -> V_20 ;
V_30 |= V_359 ;
}
if ( F_167 ( V_74 ) )
V_30 |= V_360 ;
V_358 = F_162 ( V_10 , V_334 , V_346 ,
V_74 -> V_276 ,
V_74 , V_38 - 1 ) ;
V_357 = F_134 ( V_346 ) |
F_168 ( V_358 ) |
F_169 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_143 ( V_10 , V_82 , V_27 ,
F_170 ( V_85 ) ,
F_171 ( V_85 ) ,
V_357 ,
V_30 | F_39 ( V_361 ) ) ;
-- V_38 ;
V_334 += V_346 ;
V_85 += V_346 ;
V_346 = V_74 -> V_276 - V_334 ;
if ( V_346 > V_338 )
V_346 = V_338 ;
} while ( V_38 > 0 );
F_155 ( V_74 , V_38 , V_334 ) ;
F_157 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_339 , V_250 ) ;
return 0 ;
}
int F_173 ( struct V_9 * V_10 , T_8 V_322 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
int V_38 ;
int V_47 ;
struct V_363 * V_364 ;
struct V_194 * V_250 ;
int V_339 ;
T_2 V_30 , V_357 , V_358 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
V_82 = F_32 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_327 ;
if ( ! V_74 -> V_365 )
return - V_327 ;
V_38 = 2 ;
if ( V_74 -> V_276 > 0 )
V_38 ++ ;
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_322 ) ;
if ( V_47 < 0 )
return V_47 ;
V_112 = V_74 -> V_113 ;
V_257 = V_112 -> V_257 [ 0 ] ;
V_250 = & V_82 -> V_20 -> V_29 ;
V_339 = V_82 -> V_26 ;
V_364 = (struct V_363 * ) V_74 -> V_365 ;
V_30 = 0 ;
V_30 |= V_366 | F_39 ( V_367 ) ;
if ( V_339 == 0 )
V_30 |= 0x1 ;
if ( ( V_10 -> V_351 >= 0x100 ) || ( V_10 -> V_35 & V_352 ) ) {
if ( V_74 -> V_276 > 0 ) {
if ( V_364 -> V_368 & V_369 )
V_30 |= F_174 ( V_370 ) ;
else
V_30 |= F_174 ( V_371 ) ;
}
}
F_143 ( V_10 , V_82 , true ,
V_364 -> V_368 | V_364 -> V_372 << 8 | F_175 ( V_364 -> V_373 ) << 16 ,
F_175 ( V_364 -> V_374 ) | F_175 ( V_364 -> V_375 ) << 16 ,
F_134 ( 8 ) | F_169 ( 0 ) ,
V_30 ) ;
if ( F_167 ( V_74 ) )
V_30 = V_360 | F_39 ( V_376 ) ;
else
V_30 = F_39 ( V_376 ) ;
V_358 = F_162 ( V_10 , 0 ,
V_74 -> V_276 ,
V_74 -> V_276 ,
V_74 , 1 ) ;
V_357 = F_134 ( V_74 -> V_276 ) |
F_168 ( V_358 ) |
F_169 ( 0 ) ;
if ( V_74 -> V_276 > 0 ) {
if ( V_364 -> V_368 & V_369 )
V_30 |= V_377 ;
F_143 ( V_10 , V_82 , true ,
F_170 ( V_74 -> V_362 ) ,
F_171 ( V_74 -> V_362 ) ,
V_357 ,
V_30 | V_82 -> V_26 ) ;
}
V_257 -> F_4 = V_82 -> V_20 ;
if ( V_74 -> V_276 > 0 && V_364 -> V_368 & V_369 )
V_30 = 0 ;
else
V_30 = V_377 ;
F_143 ( V_10 , V_82 , false ,
0 ,
0 ,
F_169 ( 0 ) ,
V_30 | V_359 | F_39 ( V_378 ) | V_82 -> V_26 ) ;
F_157 ( V_10 , V_56 , V_57 , 0 ,
V_339 , V_250 ) ;
return 0 ;
}
static int F_176 ( struct V_9 * V_10 ,
struct V_74 * V_74 , int V_134 )
{
int V_38 = 0 ;
T_3 V_85 , V_379 ;
V_85 = ( T_3 ) ( V_74 -> V_362 + V_74 -> V_288 [ V_134 ] . V_380 ) ;
V_379 = V_74 -> V_288 [ V_134 ] . V_116 ;
V_38 = F_165 ( V_379 + ( V_85 & ( V_338 - 1 ) ) ,
V_338 ) ;
if ( V_38 == 0 )
V_38 ++ ;
return V_38 ;
}
static unsigned int F_177 ( struct V_9 * V_10 ,
struct V_74 * V_74 , unsigned int V_350 )
{
unsigned int V_381 ;
if ( V_10 -> V_351 < 0x100 || V_74 -> V_75 -> V_215 < V_382 )
return 0 ;
V_381 = V_74 -> V_61 -> V_383 . V_384 ;
return F_165 ( V_350 , V_381 + 1 ) - 1 ;
}
static unsigned int F_178 ( struct V_9 * V_10 ,
struct V_74 * V_74 , unsigned int V_350 )
{
unsigned int V_381 ;
unsigned int V_385 ;
if ( V_10 -> V_351 < 0x100 )
return 0 ;
if ( V_74 -> V_75 -> V_215 >= V_382 ) {
V_381 = V_74 -> V_61 -> V_383 . V_384 ;
V_385 = V_350 % ( V_381 + 1 ) ;
if ( V_385 == 0 )
return V_381 ;
return V_385 - 1 ;
}
if ( V_350 == 0 )
return 0 ;
return V_350 - 1 ;
}
static int F_179 ( struct V_9 * V_10 ,
struct V_74 * V_74 , int V_386 )
{
int V_387 , V_388 , V_47 = 0 ;
int V_389 , V_390 , V_391 ;
if ( V_74 -> V_75 -> V_215 == V_343 ||
V_74 -> V_75 -> V_215 == V_344 )
V_387 = V_74 -> V_387 + V_386 * V_74 -> V_342 ;
else
V_387 = ( V_74 -> V_387 + V_386 * V_74 -> V_342 ) >> 3 ;
V_388 = F_180 ( V_10 -> V_392 ) & 0x7 ;
if ( F_180 ( V_10 -> V_392 ) & ( 1 << 3 ) )
V_388 <<= 3 ;
V_391 = F_17 ( & V_10 -> V_393 -> V_394 ) ;
V_389 = F_181 ( V_391 + V_388 + 1 , 8 ) ;
V_390 = F_182 ( V_391 + 895 * 8 , 8 ) ;
V_387 &= 0x7ff ;
V_389 = ( V_389 >> 3 ) & 0x7ff ;
V_390 = ( V_390 >> 3 ) & 0x7ff ;
F_15 ( V_10 , L_125 ,
V_248 , V_386 , F_17 ( & V_10 -> V_393 -> V_394 ) ,
V_389 , V_390 , V_387 ) ;
if ( V_389 < V_390 ) {
if ( V_387 > V_390 ||
V_387 < V_389 )
V_47 = - V_327 ;
} else if ( V_389 > V_390 ) {
if ( ( V_387 > V_390 &&
V_387 < V_389 ) )
V_47 = - V_327 ;
} else {
V_47 = - V_327 ;
}
if ( V_386 == 0 ) {
if ( V_47 == - V_327 || V_387 == V_389 ) {
V_387 = V_389 + 1 ;
if ( V_74 -> V_75 -> V_215 == V_343 ||
V_74 -> V_75 -> V_215 == V_344 )
V_74 -> V_387 = V_387 ;
else
V_74 -> V_387 = V_387 << 3 ;
V_47 = 0 ;
}
}
if ( V_47 ) {
F_31 ( V_10 , L_126 ,
V_387 , V_391 , V_386 ,
V_389 , V_390 ) ;
F_31 ( V_10 , L_127 ) ;
return V_47 ;
}
return V_387 ;
}
static int F_183 ( struct V_9 * V_10 , T_8 V_322 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
int V_395 , V_396 ;
struct V_194 * V_250 ;
bool V_105 ;
int V_339 ;
T_2 V_30 , V_357 ;
int V_334 , V_346 , V_379 , V_397 , V_47 ;
T_3 V_398 , V_85 ;
int V_134 , V_135 ;
bool V_27 ;
struct V_60 * V_399 ;
int V_400 ;
V_399 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
V_82 = V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] . V_12 ;
V_395 = V_74 -> V_401 ;
if ( V_395 < 1 ) {
F_15 ( V_10 , L_128 ) ;
return - V_327 ;
}
V_398 = ( T_3 ) V_74 -> V_362 ;
V_250 = & V_82 -> V_20 -> V_29 ;
V_339 = V_82 -> V_26 ;
V_112 = V_74 -> V_113 ;
for ( V_134 = 0 ; V_134 < V_395 ; V_134 ++ ) {
unsigned int V_402 , V_403 ;
unsigned int V_404 , V_405 ;
T_2 V_406 ;
V_105 = true ;
V_334 = 0 ;
V_85 = V_398 + V_74 -> V_288 [ V_134 ] . V_380 ;
V_379 = V_74 -> V_288 [ V_134 ] . V_116 ;
V_397 = V_379 ;
V_403 = F_163 ( F_164 ( & V_74 -> V_61 -> V_76 ) ) ;
V_402 = F_165 ( V_379 , V_403 ) ;
if ( V_402 == 0 )
V_402 ++ ;
V_404 = F_177 ( V_10 , V_74 , V_402 ) ;
V_405 = F_178 ( V_10 ,
V_74 , V_402 ) ;
V_396 = F_176 ( V_10 , V_74 , V_134 ) ;
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] , V_57 ,
V_74 -> V_58 , V_396 , V_74 , V_134 , V_322 ) ;
if ( V_47 < 0 ) {
if ( V_134 == 0 )
return V_47 ;
goto V_146;
}
V_257 = V_112 -> V_257 [ V_134 ] ;
V_406 = V_407 ;
if ( ! ( V_74 -> V_277 & V_408 ) &&
F_184 ( V_10 -> V_409 ) ) {
V_400 = F_179 ( V_10 , V_74 , V_134 ) ;
if ( V_400 >= 0 )
V_406 = F_185 ( V_400 ) ;
}
V_30 = F_39 ( V_410 ) |
F_186 ( V_405 ) |
V_406 |
( V_134 ? V_82 -> V_26 : ! V_339 ) ;
if ( ! V_399 -> V_411 )
V_30 |= F_187 ( V_404 ) ;
for ( V_135 = 0 ; V_135 < V_396 ; V_135 ++ ) {
T_2 V_358 = 0 ;
if ( ! V_105 )
V_30 = F_39 ( V_361 ) |
V_82 -> V_26 ;
if ( F_167 ( V_74 ) )
V_30 |= V_360 ;
if ( V_135 < V_396 - 1 ) {
V_27 = true ;
V_30 |= V_31 ;
} else {
V_27 = false ;
V_257 -> F_4 = V_82 -> V_20 ;
V_30 |= V_359 ;
if ( V_10 -> V_351 >= 0x100 &&
! ( V_10 -> V_35 & V_412 ) &&
V_134 < V_395 - 1 )
V_30 |= V_413 ;
}
V_346 = V_338 -
( V_85 & ( ( 1 << V_414 ) - 1 ) ) ;
if ( V_346 > V_397 )
V_346 = V_397 ;
V_358 = F_162 ( V_10 , V_334 ,
V_346 , V_379 ,
V_74 , V_396 - V_135 - 1 ) ;
V_357 = F_134 ( V_346 ) |
F_169 ( 0 ) ;
if ( V_105 && V_399 -> V_411 )
V_357 |= F_188 ( V_404 ) ;
else
V_357 |= F_168 ( V_358 ) ;
V_105 = false ;
F_143 ( V_10 , V_82 , V_27 ,
F_170 ( V_85 ) ,
F_171 ( V_85 ) ,
V_357 ,
V_30 ) ;
V_334 += V_346 ;
V_85 += V_346 ;
V_397 -= V_346 ;
}
if ( V_334 != V_379 ) {
F_23 ( V_10 , L_129 ) ;
V_47 = - V_327 ;
goto V_146;
}
}
if ( F_184 ( V_10 -> V_409 ) )
V_399 -> V_415 = V_74 -> V_387 + V_395 * V_74 -> V_342 ;
if ( F_45 ( V_10 ) -> V_119 . V_120 == 0 ) {
if ( V_10 -> V_35 & V_121 )
F_189 () ;
}
F_45 ( V_10 ) -> V_119 . V_120 ++ ;
F_157 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_339 , V_250 ) ;
return 0 ;
V_146:
for ( V_134 -- ; V_134 >= 0 ; V_134 -- )
F_58 ( & V_112 -> V_257 [ V_134 ] -> V_69 ) ;
V_112 -> V_257 [ 0 ] -> F_4 = V_82 -> V_20 ;
F_38 ( V_10 , V_82 , V_112 -> V_257 [ 0 ] , true ) ;
V_82 -> V_20 = V_112 -> V_257 [ 0 ] -> V_105 ;
V_82 -> V_32 = V_112 -> V_257 [ 0 ] -> V_104 ;
V_82 -> V_26 = V_339 ;
V_82 -> V_25 = V_82 -> V_140 ;
F_47 ( F_43 ( V_74 -> V_75 -> V_115 ) , V_74 ) ;
return V_47 ;
}
int F_190 ( struct V_9 * V_10 , T_8 V_322 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_81 * V_267 ;
struct V_11 * V_82 ;
struct V_94 * V_95 ;
int V_387 ;
int V_340 ;
int V_341 ;
int V_395 , V_38 , V_134 ;
int V_47 ;
struct V_60 * V_399 ;
int V_388 ;
V_267 = V_10 -> V_62 [ V_56 ] ;
V_399 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
V_82 = V_267 -> V_63 [ V_57 ] . V_12 ;
V_95 = F_37 ( V_10 , V_267 -> V_96 , V_57 ) ;
V_38 = 0 ;
V_395 = V_74 -> V_401 ;
for ( V_134 = 0 ; V_134 < V_395 ; V_134 ++ )
V_38 += F_176 ( V_10 , V_74 , V_134 ) ;
V_47 = F_144 ( V_10 , V_82 , F_3 ( V_95 -> V_151 ) & V_152 ,
V_38 , V_322 ) ;
if ( V_47 )
return V_47 ;
V_340 = F_159 ( F_3 ( V_95 -> V_151 ) ) ;
V_341 = V_74 -> V_342 ;
if ( V_74 -> V_75 -> V_215 == V_343 ||
V_74 -> V_75 -> V_215 == V_344 )
V_341 *= 8 ;
if ( V_340 != V_341 ) {
F_160 ( & V_74 -> V_75 -> V_75 ,
L_119 ,
V_341 , V_341 == 1 ? L_120 : L_121 ,
V_340 , V_340 == 1 ? L_120 : L_121 ) ;
V_74 -> V_342 = V_340 ;
if ( V_74 -> V_75 -> V_215 == V_343 ||
V_74 -> V_75 -> V_215 == V_344 )
V_74 -> V_342 /= 8 ;
}
if ( F_184 ( V_10 -> V_409 ) && ! F_29 ( & V_82 -> V_69 ) ) {
if ( ( F_3 ( V_95 -> V_151 ) & V_152 ) ==
V_329 ) {
V_74 -> V_387 = V_399 -> V_415 ;
goto V_416;
}
}
V_387 = F_17 ( & V_10 -> V_393 -> V_394 ) ;
V_387 &= 0x3fff ;
V_388 = F_180 ( V_10 -> V_392 ) & 0x7 ;
if ( F_180 ( V_10 -> V_392 ) & ( 1 << 3 ) )
V_388 <<= 3 ;
V_387 += V_388 + V_417 ;
V_387 = F_181 ( V_387 , 8 ) ;
if ( V_74 -> V_75 -> V_215 == V_343 ||
V_74 -> V_75 -> V_215 == V_344 ) {
V_387 = F_181 ( V_387 , V_74 -> V_342 << 3 ) ;
V_74 -> V_387 = V_387 >> 3 ;
} else {
V_387 = F_181 ( V_387 , V_74 -> V_342 ) ;
V_74 -> V_387 = V_387 ;
}
V_416:
V_82 -> V_140 = V_82 -> V_25 ;
return F_183 ( V_10 , V_322 , V_74 , V_56 , V_57 ) ;
}
static int F_191 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_2 V_318 , T_2 V_319 ,
T_2 V_320 , T_2 V_321 , bool V_418 )
{
int V_419 = V_10 -> V_420 ;
int V_47 ;
if ( ( V_10 -> V_53 & V_54 ) ||
( V_10 -> V_53 & V_421 ) ) {
F_15 ( V_10 , L_130 ) ;
return - V_55 ;
}
if ( ! V_418 )
V_419 ++ ;
V_47 = F_144 ( V_10 , V_10 -> V_49 , V_329 ,
V_419 , V_162 ) ;
if ( V_47 < 0 ) {
F_23 ( V_10 , L_131 ) ;
if ( V_418 )
F_23 ( V_10 , L_132
L_133 ) ;
return V_47 ;
}
V_174 -> V_182 = V_10 -> V_49 -> V_20 ;
F_149 ( & V_174 -> V_175 , & V_10 -> V_175 ) ;
if ( V_10 -> V_175 . V_14 == & V_174 -> V_175 &&
! F_192 ( & V_10 -> V_185 ) ) {
V_10 -> V_184 = V_174 ;
F_94 ( & V_10 -> V_185 , V_186 + V_187 ) ;
}
F_143 ( V_10 , V_10 -> V_49 , false , V_318 , V_319 , V_320 ,
V_321 | V_10 -> V_49 -> V_26 ) ;
return 0 ;
}
int F_193 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_2 V_207 , T_2 V_56 )
{
return F_191 ( V_10 , V_174 , 0 , 0 , 0 ,
F_39 ( V_207 ) | F_194 ( V_56 ) , false ) ;
}
int F_195 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_1 V_422 , T_2 V_56 , enum V_423 V_364 )
{
return F_191 ( V_10 , V_174 , F_170 ( V_422 ) ,
F_171 ( V_422 ) , 0 ,
F_39 ( V_201 ) | F_194 ( V_56 )
| ( V_364 == V_424 ? V_425 : 0 ) , false ) ;
}
int F_196 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_2 V_318 , T_2 V_319 , T_2 V_320 , T_2 V_321 )
{
return F_191 ( V_10 , V_174 , V_318 , V_319 , V_320 , V_321 , false ) ;
}
int F_197 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_2 V_56 )
{
return F_191 ( V_10 , V_174 , 0 , 0 , 0 ,
F_39 ( V_205 ) | F_194 ( V_56 ) ,
false ) ;
}
int F_75 ( struct V_9 * V_10 ,
struct V_160 * V_174 , T_1 V_422 ,
T_2 V_56 , bool V_418 )
{
return F_191 ( V_10 , V_174 , F_170 ( V_422 ) ,
F_171 ( V_422 ) , 0 ,
F_39 ( V_199 ) | F_194 ( V_56 ) ,
V_418 ) ;
}
int F_198 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_1 V_422 , T_2 V_56 , bool V_418 )
{
return F_191 ( V_10 , V_174 , F_170 ( V_422 ) ,
F_171 ( V_422 ) , 0 ,
F_39 ( V_200 ) | F_194 ( V_56 ) ,
V_418 ) ;
}
int F_199 ( struct V_9 * V_10 , struct V_160 * V_174 ,
int V_56 , unsigned int V_57 , int V_426 )
{
T_2 V_427 = F_194 ( V_56 ) ;
T_2 V_428 = F_200 ( V_57 ) ;
T_2 type = F_39 ( V_202 ) ;
T_2 V_429 = F_201 ( V_426 ) ;
return F_191 ( V_10 , V_174 , 0 , 0 , 0 ,
V_427 | V_428 | type | V_429 , false ) ;
}
void F_59 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 ,
struct V_79 * V_128 )
{
T_1 V_85 ;
T_2 V_427 = F_194 ( V_56 ) ;
T_2 V_428 = F_200 ( V_57 ) ;
T_2 V_430 = F_202 ( V_58 ) ;
T_2 V_431 = 0 ;
T_2 type = F_39 ( V_203 ) ;
struct V_60 * V_61 ;
struct V_160 * V_174 ;
int V_47 ;
F_35 ( V_10 , V_89 ,
L_134 ,
V_128 -> V_99 ,
( unsigned long long ) V_128 -> V_99 -> V_8 ,
V_128 -> V_100 ,
( unsigned long long ) F_1 (
V_128 -> V_99 , V_128 -> V_100 ) ,
V_128 -> V_98 ) ;
V_85 = F_1 ( V_128 -> V_99 ,
V_128 -> V_100 ) ;
if ( V_85 == 0 ) {
F_31 ( V_10 , L_135 ) ;
F_31 ( V_10 , L_136 ,
V_128 -> V_99 , V_128 -> V_100 ) ;
return;
}
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ( V_61 -> V_64 & V_66 ) ) {
F_31 ( V_10 , L_135 ) ;
F_31 ( V_10 , L_137 ) ;
return;
}
V_174 = F_74 ( V_10 , false , false , V_162 ) ;
if ( ! V_174 ) {
F_31 ( V_10 , L_138 ) ;
return;
}
V_61 -> V_157 = V_128 -> V_99 ;
V_61 -> V_142 = V_128 -> V_100 ;
if ( V_58 )
V_431 = F_203 ( V_432 ) ;
V_47 = F_191 ( V_10 , V_174 ,
F_170 ( V_85 ) | V_431 | V_128 -> V_98 ,
F_171 ( V_85 ) , V_430 ,
V_427 | V_428 | type , false ) ;
if ( V_47 < 0 ) {
F_204 ( V_10 , V_174 ) ;
return;
}
V_61 -> V_64 |= V_66 ;
}
int F_123 ( struct V_9 * V_10 , struct V_160 * V_174 ,
int V_56 , unsigned int V_57 )
{
T_2 V_427 = F_194 ( V_56 ) ;
T_2 V_428 = F_200 ( V_57 ) ;
T_2 type = F_39 ( V_204 ) ;
return F_191 ( V_10 , V_174 , 0 , 0 , 0 ,
V_427 | V_428 | type , false ) ;
}
