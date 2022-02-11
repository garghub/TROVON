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
F_22 ( V_10 , L_3
L_4 ) ;
V_10 -> V_53 |= V_54 ;
F_23 ( V_10 ) ;
F_24 ( V_10 ) ;
return - V_55 ;
}
return 0 ;
}
void F_25 ( struct V_9 * V_10 ,
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
F_16 ( F_26 ( V_57 , V_58 ) , V_59 ) ;
}
static void F_27 ( struct V_9 * V_10 ,
unsigned int V_56 ,
unsigned int V_57 )
{
unsigned int V_58 ;
struct V_60 * V_61 ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ! ( V_61 -> V_64 & V_68 ) ) {
if ( V_61 -> V_12 && ! ( F_28 ( & V_61 -> V_12 -> V_69 ) ) )
F_25 ( V_10 , V_56 , V_57 , 0 ) ;
return;
}
for ( V_58 = 1 ; V_58 < V_61 -> V_70 -> V_71 ;
V_58 ++ ) {
struct V_72 * V_70 = V_61 -> V_70 ;
if ( ! F_28 ( & V_70 -> V_73 [ V_58 ] -> V_69 ) )
F_25 ( V_10 , V_56 , V_57 ,
V_58 ) ;
}
}
static struct V_11 * F_29 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 )
{
struct V_60 * V_61 ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ! ( V_61 -> V_64 & V_68 ) )
return V_61 -> V_12 ;
if ( V_58 == 0 ) {
F_30 ( V_10 ,
L_5
L_6 ,
V_56 , V_57 ) ;
return NULL ;
}
if ( V_58 < V_61 -> V_70 -> V_71 )
return V_61 -> V_70 -> V_73 [ V_58 ] ;
F_30 ( V_10 ,
L_7
L_8
L_9 ,
V_56 , V_57 ,
V_61 -> V_70 -> V_71 - 1 ,
V_58 ) ;
return NULL ;
}
static struct V_11 * F_31 ( struct V_9 * V_10 ,
struct V_74 * V_74 )
{
return F_29 ( V_10 , V_74 -> V_75 -> V_56 ,
F_32 ( & V_74 -> V_61 -> V_76 ) , V_74 -> V_58 ) ;
}
void F_33 ( struct V_9 * V_10 ,
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
V_82 = F_29 ( V_10 , V_56 ,
V_57 , V_58 ) ;
if ( ! V_82 ) {
F_30 ( V_10 , L_10
L_11 ,
V_58 ) ;
return;
}
F_34 ( V_10 , V_89 ,
L_12 ) ;
if ( V_61 -> V_64 & V_68 ) {
struct V_90 * V_91 =
& V_61 -> V_70 -> V_92 [ V_58 ] ;
V_86 = F_35 ( V_91 -> V_93 ) ;
} else {
struct V_94 * V_95
= F_36 ( V_10 , V_75 -> V_96 , V_57 ) ;
V_86 = F_35 ( V_95 -> V_97 ) ;
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
F_22 ( V_10 , L_13 ) ;
V_80 -> V_99 = NULL ;
V_80 -> V_100 = NULL ;
return;
}
} while ( ! V_87 || ! V_88 );
V_80 -> V_99 = V_83 ;
V_80 -> V_100 = V_84 ;
F_34 ( V_10 , V_89 ,
L_14 , V_80 -> V_98 ) ;
F_34 ( V_10 , V_89 ,
L_15 ,
V_80 -> V_99 ) ;
V_85 = F_1 ( V_80 -> V_99 , V_80 -> V_100 ) ;
F_34 ( V_10 , V_89 ,
L_16 ,
( unsigned long long ) V_85 ) ;
}
static void F_37 ( struct V_9 * V_10 , struct V_11 * V_82 ,
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
F_34 ( V_10 , V_89 ,
L_17 ) ;
F_34 ( V_10 , V_89 ,
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
F_38 ( V_106 ) ) ;
F_34 ( V_10 , V_89 ,
L_20 ,
( unsigned long long )
F_1 ( V_102 , V_103 ) ) ;
}
if ( V_103 == V_78 -> F_4 )
break;
}
}
static void F_39 ( struct V_9 * V_10 ,
struct V_60 * V_61 )
{
V_61 -> V_64 &= ~ V_65 ;
if ( F_40 ( & V_61 -> V_107 ) )
V_61 -> V_108 -- ;
}
static void F_41 ( struct V_9 * V_10 ,
struct V_77 * V_78 , int V_109 )
{
struct V_110 * V_111 ;
struct V_74 * V_74 ;
struct V_112 * V_112 ;
V_74 = V_78 -> V_74 ;
V_112 = V_74 -> V_113 ;
V_112 -> V_114 ++ ;
V_111 = F_42 ( V_74 -> V_75 -> V_115 ) ;
if ( V_112 -> V_114 == V_112 -> V_116 ) {
if ( F_43 ( V_74 -> V_117 ) == V_118 ) {
F_44 ( V_10 ) -> V_119 . V_120 -- ;
if ( F_44 ( V_10 ) -> V_119 . V_120 == 0 ) {
if ( V_10 -> V_35 & V_121 )
F_45 () ;
}
}
F_46 ( V_111 , V_74 ) ;
F_47 ( & V_10 -> V_122 ) ;
F_48 ( V_111 , V_74 , V_109 ) ;
F_49 ( V_112 ) ;
F_50 ( & V_10 -> V_122 ) ;
}
}
static void F_51 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , struct V_123 * V_124 )
{
unsigned int V_57 ;
struct V_11 * V_82 ;
struct V_60 * V_61 ;
struct V_125 * V_126 ;
struct V_77 * V_78 = NULL ;
struct V_77 * V_127 ;
struct V_79 V_128 ;
if ( F_52 ( F_53 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ) ) {
if ( ! V_10 -> V_62 [ V_56 ] )
F_30 ( V_10 , L_21
L_22 ,
V_56 ) ;
return;
}
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_57 = F_54 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( F_28 ( & V_61 -> V_129 ) ) {
F_39 ( V_10 , V_61 ) ;
V_61 -> V_130 = NULL ;
F_27 ( V_10 , V_56 , V_57 ) ;
return;
}
F_55 (entry, &ep->cancelled_td_list) {
V_78 = F_56 ( V_126 , struct V_77 , V_129 ) ;
F_34 ( V_10 , V_89 ,
L_23 ,
( unsigned long long ) F_1 (
V_78 -> V_104 , V_78 -> V_105 ) ) ;
V_82 = F_31 ( V_10 , V_78 -> V_74 ) ;
if ( ! V_82 ) {
F_30 ( V_10 , L_24
L_25 ,
V_78 -> V_74 ,
V_78 -> V_74 -> V_58 ) ;
goto V_131;
}
if ( V_78 == V_61 -> V_130 )
F_33 ( V_10 , V_56 , V_57 ,
V_78 -> V_74 -> V_58 ,
V_78 , & V_128 ) ;
else
F_37 ( V_10 , V_82 , V_78 , false ) ;
V_131:
F_57 ( & V_78 -> V_69 ) ;
}
V_127 = V_78 ;
F_39 ( V_10 , V_61 ) ;
if ( V_128 . V_100 && V_128 . V_99 ) {
F_58 ( V_10 , V_56 , V_57 ,
V_61 -> V_130 -> V_74 -> V_58 , & V_128 ) ;
F_14 ( V_10 ) ;
} else {
F_27 ( V_10 , V_56 , V_57 ) ;
}
V_61 -> V_130 = NULL ;
do {
V_78 = F_56 ( V_61 -> V_129 . V_14 ,
struct V_77 , V_129 ) ;
F_57 ( & V_78 -> V_129 ) ;
F_41 ( V_10 , V_78 , 0 ) ;
if ( V_10 -> V_53 & V_54 )
return;
} while ( V_78 != V_127 );
}
static void F_59 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_77 * V_78 ;
while ( ! F_28 ( & V_12 -> V_69 ) ) {
V_78 = F_60 ( & V_12 -> V_69 ,
struct V_77 , V_69 ) ;
F_57 ( & V_78 -> V_69 ) ;
if ( ! F_28 ( & V_78 -> V_129 ) )
F_57 ( & V_78 -> V_129 ) ;
F_41 ( V_10 , V_78 , - V_55 ) ;
}
}
static void F_61 ( struct V_9 * V_10 ,
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
F_34 ( V_10 , V_89 ,
L_26 ,
V_56 , V_57 , V_58 + 1 ) ;
F_59 ( V_10 ,
V_61 -> V_70 -> V_73 [ V_58 ] ) ;
}
} else {
V_12 = V_61 -> V_12 ;
if ( ! V_12 )
return;
F_34 ( V_10 , V_89 ,
L_27 ,
V_56 , V_57 ) ;
F_59 ( V_10 , V_12 ) ;
}
while ( ! F_28 ( & V_61 -> V_129 ) ) {
V_78 = F_60 ( & V_61 -> V_129 ,
struct V_77 , V_129 ) ;
F_57 ( & V_78 -> V_129 ) ;
F_41 ( V_10 , V_78 , - V_55 ) ;
}
}
void F_62 ( unsigned long V_133 )
{
struct V_9 * V_10 ;
struct V_60 * V_61 ;
int V_47 , V_134 , V_135 ;
unsigned long V_136 ;
V_61 = (struct V_60 * ) V_133 ;
V_10 = V_61 -> V_10 ;
F_63 ( & V_10 -> V_122 , V_136 ) ;
V_61 -> V_108 -- ;
if ( V_10 -> V_53 & V_54 ) {
F_34 ( V_10 , V_89 ,
L_28
L_29 ) ;
F_64 ( & V_10 -> V_122 , V_136 ) ;
return;
}
if ( ! ( V_61 -> V_108 == 0 && ( V_61 -> V_64 & V_65 ) ) ) {
F_34 ( V_10 , V_89 ,
L_30
L_31 ) ;
F_64 ( & V_10 -> V_122 , V_136 ) ;
return;
}
F_30 ( V_10 , L_32 ) ;
F_30 ( V_10 , L_33 ) ;
V_10 -> V_53 |= V_54 ;
F_23 ( V_10 ) ;
F_64 ( & V_10 -> V_122 , V_136 ) ;
V_47 = F_24 ( V_10 ) ;
F_63 ( & V_10 -> V_122 , V_136 ) ;
if ( V_47 < 0 ) {
F_30 ( V_10 , L_34 ) ;
F_30 ( V_10 , L_35 ) ;
}
for ( V_134 = 0 ; V_134 < V_137 ; V_134 ++ ) {
if ( ! V_10 -> V_62 [ V_134 ] )
continue;
for ( V_135 = 0 ; V_135 < 31 ; V_135 ++ )
F_61 ( V_10 , V_134 , V_135 ) ;
}
F_64 ( & V_10 -> V_122 , V_136 ) ;
F_34 ( V_10 , V_89 ,
L_36 ) ;
F_65 ( F_44 ( V_10 ) -> V_138 ) ;
F_34 ( V_10 , V_89 ,
L_37 ) ;
}
static void F_66 ( struct V_9 * V_10 ,
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
static void F_67 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , T_2 V_143 )
{
unsigned int V_57 ;
unsigned int V_58 ;
struct V_11 * V_82 ;
struct V_81 * V_75 ;
struct V_60 * V_61 ;
struct V_94 * V_95 ;
struct V_144 * V_145 ;
V_57 = F_54 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_58 = F_68 ( F_3 ( V_4 -> V_29 . V_30 [ 2 ] ) ) ;
V_75 = V_10 -> V_62 [ V_56 ] ;
V_61 = & V_75 -> V_63 [ V_57 ] ;
V_82 = F_69 ( V_75 , V_57 , V_58 ) ;
if ( ! V_82 ) {
F_30 ( V_10 , L_39 ,
V_58 ) ;
goto V_146;
}
V_95 = F_36 ( V_10 , V_75 -> V_96 , V_57 ) ;
V_145 = F_70 ( V_10 , V_75 -> V_96 ) ;
if ( V_143 != V_147 ) {
unsigned int V_64 ;
unsigned int V_148 ;
switch ( V_143 ) {
case V_149 :
F_30 ( V_10 , L_40 ) ;
break;
case V_150 :
F_30 ( V_10 , L_41 ) ;
V_64 = F_3 ( V_95 -> V_151 ) ;
V_64 &= V_152 ;
V_148 = F_3 ( V_145 -> V_153 ) ;
V_148 = F_71 ( V_148 ) ;
F_34 ( V_10 , V_89 ,
L_42 ,
V_148 , V_64 ) ;
break;
case V_154 :
F_30 ( V_10 , L_43 ,
V_56 ) ;
break;
default:
F_30 ( V_10 , L_44 ,
V_143 ) ;
break;
}
} else {
T_3 V_97 ;
if ( V_61 -> V_64 & V_68 ) {
struct V_90 * V_91 =
& V_61 -> V_70 -> V_92 [ V_58 ] ;
V_97 = F_35 ( V_91 -> V_93 ) & V_155 ;
} else {
V_97 = F_35 ( V_95 -> V_97 ) & ~ V_156 ;
}
F_34 ( V_10 , V_89 ,
L_45 , V_97 ) ;
if ( F_1 ( V_61 -> V_157 ,
V_61 -> V_142 ) == V_97 ) {
F_66 ( V_10 , V_75 ,
V_82 , V_57 ) ;
} else {
F_30 ( V_10 , L_46 ) ;
F_30 ( V_10 , L_47 ,
V_61 -> V_157 , V_61 -> V_142 ) ;
}
}
V_146:
V_75 -> V_63 [ V_57 ] . V_64 &= ~ V_66 ;
V_75 -> V_63 [ V_57 ] . V_157 = NULL ;
V_75 -> V_63 [ V_57 ] . V_142 = NULL ;
F_27 ( V_10 , V_56 , V_57 ) ;
}
static void F_72 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , T_2 V_143 )
{
unsigned int V_57 ;
V_57 = F_54 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
F_34 ( V_10 , V_158 ,
L_48 , V_143 ) ;
if ( V_10 -> V_35 & V_159 ) {
struct V_160 * V_161 ;
V_161 = F_73 ( V_10 , false , false , V_162 ) ;
if ( ! V_161 ) {
F_30 ( V_10 , L_49 ) ;
return;
}
F_34 ( V_10 , V_163 ,
L_50 ) ;
F_74 ( V_10 , V_161 ,
V_10 -> V_62 [ V_56 ] -> V_164 -> V_8 , V_56 ,
false ) ;
F_14 ( V_10 ) ;
} else {
V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] . V_64 &= ~ V_67 ;
}
}
static void F_75 ( struct V_9 * V_10 , int V_56 ,
T_2 V_143 )
{
if ( V_143 == V_147 )
V_10 -> V_56 = V_56 ;
else
V_10 -> V_56 = 0 ;
}
static void F_76 ( struct V_9 * V_10 , int V_56 )
{
struct V_81 * V_165 ;
V_165 = V_10 -> V_62 [ V_56 ] ;
if ( ! V_165 )
return;
if ( V_10 -> V_35 & V_166 )
F_77 ( V_10 , V_165 , true ) ;
F_78 ( V_10 , V_56 ) ;
}
static void F_79 ( struct V_9 * V_10 , int V_56 ,
struct V_123 * V_124 , T_2 V_143 )
{
struct V_81 * V_165 ;
struct V_167 * V_168 ;
unsigned int V_57 ;
unsigned int V_64 ;
T_2 V_169 , V_170 ;
V_165 = V_10 -> V_62 [ V_56 ] ;
V_168 = F_80 ( V_165 -> V_164 ) ;
if ( ! V_168 ) {
F_30 ( V_10 , L_51 ) ;
return;
}
V_169 = F_3 ( V_168 -> V_169 ) ;
V_170 = F_3 ( V_168 -> V_170 ) ;
V_57 = F_81 ( V_169 ) - 1 ;
if ( V_10 -> V_35 & V_159 &&
V_57 != ( unsigned int ) - 1 &&
V_169 - V_171 == V_170 ) {
V_64 = V_165 -> V_63 [ V_57 ] . V_64 ;
if ( ! ( V_64 & V_67 ) )
return;
F_34 ( V_10 , V_163 ,
L_52
L_53 ,
V_57 , V_64 ) ;
V_165 -> V_63 [ V_57 ] . V_64 &= ~ V_67 ;
F_27 ( V_10 , V_56 , V_57 ) ;
return;
}
return;
}
static void F_82 ( struct V_9 * V_10 , int V_56 ,
struct V_123 * V_124 )
{
F_15 ( V_10 , L_54 ) ;
if ( ! V_10 -> V_62 [ V_56 ] )
F_30 ( V_10 , L_55
L_56 , V_56 ) ;
}
static void F_83 ( struct V_9 * V_10 ,
struct V_123 * V_124 )
{
if ( ! ( V_10 -> V_35 & V_172 ) ) {
V_10 -> V_173 |= 1 << 6 ;
return;
}
F_34 ( V_10 , V_163 ,
L_57 ,
F_84 ( F_3 ( V_124 -> V_109 ) ) ,
F_85 ( F_3 ( V_124 -> V_109 ) ) ) ;
}
static void F_86 ( struct V_160 * V_174 , T_2 V_109 )
{
F_87 ( & V_174 -> V_175 ) ;
if ( V_174 -> V_176 ) {
V_174 -> V_109 = V_109 ;
F_88 ( V_174 -> V_176 ) ;
} else {
F_89 ( V_174 ) ;
}
}
void F_90 ( struct V_9 * V_10 )
{
struct V_160 * V_177 , * V_178 ;
F_91 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_86 ( V_177 , V_179 ) ;
}
static void F_92 ( struct V_9 * V_10 ,
struct V_160 * V_177 )
{
struct V_160 * V_180 , * V_178 ;
T_2 V_26 ;
F_91 (i_cmd, tmp_cmd, &xhci->cmd_list,
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
F_38 ( V_183 ) | V_26 ) ;
}
V_10 -> V_41 = V_42 ;
if ( ( V_10 -> V_49 -> V_24 != V_10 -> V_49 -> V_20 ) &&
! ( V_10 -> V_53 & V_54 ) ) {
V_10 -> V_184 = V_177 ;
F_93 ( & V_10 -> V_185 , V_186 + V_187 ) ;
F_14 ( V_10 ) ;
}
return;
}
void F_94 ( unsigned long V_188 )
{
struct V_9 * V_10 ;
int V_47 ;
unsigned long V_136 ;
T_3 V_189 ;
struct V_160 * V_177 = NULL ;
V_10 = (struct V_9 * ) V_188 ;
F_63 ( & V_10 -> V_122 , V_136 ) ;
if ( V_10 -> V_184 ) {
V_177 = V_10 -> V_184 ;
V_177 -> V_109 = V_179 ;
}
V_189 = F_19 ( V_10 , & V_10 -> V_48 -> V_49 ) ;
if ( ( V_10 -> V_41 & V_42 ) &&
( V_189 & V_52 ) ) {
F_64 ( & V_10 -> V_122 , V_136 ) ;
F_15 ( V_10 , L_59 ) ;
V_47 = F_18 ( V_10 ) ;
if ( F_52 ( V_47 == - V_55 ) ) {
F_22 ( V_10 , L_60 ) ;
F_90 ( V_10 ) ;
F_65 ( F_44 ( V_10 ) -> V_138 ) ;
F_15 ( V_10 , L_61 ) ;
}
return;
}
F_15 ( V_10 , L_62 ) ;
F_92 ( V_10 , V_10 -> V_184 ) ;
F_64 ( & V_10 -> V_122 , V_136 ) ;
return;
}
static void F_95 ( struct V_9 * V_10 ,
struct V_123 * V_124 )
{
int V_56 = F_96 ( F_3 ( V_124 -> V_136 ) ) ;
T_3 V_190 ;
T_1 V_191 ;
T_2 V_143 ;
union V_3 * V_192 ;
struct V_160 * V_174 ;
T_2 V_193 ;
V_190 = F_35 ( V_124 -> V_192 ) ;
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
V_174 = F_56 ( V_10 -> V_175 . V_14 , struct V_160 , V_175 ) ;
if ( V_174 -> V_182 != V_10 -> V_49 -> V_24 ) {
F_22 ( V_10 ,
L_63 ) ;
return;
}
F_40 ( & V_10 -> V_185 ) ;
F_97 ( V_192 , (struct V_194 * ) V_124 ) ;
V_143 = F_98 ( F_3 ( V_124 -> V_109 ) ) ;
if ( V_143 == V_181 ) {
F_92 ( V_10 , V_174 ) ;
return;
}
if ( V_143 == V_179 ) {
V_10 -> V_41 = V_195 ;
if ( V_174 -> V_109 == V_179 )
goto V_196;
}
V_193 = F_99 ( F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ;
switch ( V_193 ) {
case V_197 :
F_75 ( V_10 , V_56 , V_143 ) ;
break;
case V_198 :
F_76 ( V_10 , V_56 ) ;
break;
case V_199 :
if ( ! V_174 -> V_176 )
F_79 ( V_10 , V_56 , V_124 ,
V_143 ) ;
break;
case V_200 :
break;
case V_201 :
break;
case V_202 :
F_100 ( V_56 != F_96 (
F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_51 ( V_10 , V_56 , V_192 , V_124 ) ;
break;
case V_203 :
F_100 ( V_56 != F_96 (
F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_67 ( V_10 , V_56 , V_192 , V_143 ) ;
break;
case V_183 :
if ( V_174 -> V_109 == V_181 )
V_143 = V_181 ;
break;
case V_204 :
F_100 ( V_56 != F_96 (
F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_72 ( V_10 , V_56 , V_192 , V_143 ) ;
break;
case V_205 :
V_56 = F_96 (
F_3 ( V_192 -> V_29 . V_30 [ 3 ] ) ) ;
F_82 ( V_10 , V_56 , V_124 ) ;
break;
case V_206 :
F_83 ( V_10 , V_124 ) ;
break;
default:
V_10 -> V_173 |= 1 << 6 ;
break;
}
if ( V_174 -> V_175 . V_14 != & V_10 -> V_175 ) {
V_10 -> V_184 = F_56 ( V_174 -> V_175 . V_14 ,
struct V_160 , V_175 ) ;
F_93 ( & V_10 -> V_185 , V_186 + V_187 ) ;
}
V_196:
F_86 ( V_174 , V_143 ) ;
F_8 ( V_10 , V_10 -> V_49 ) ;
}
static void F_101 ( struct V_9 * V_10 ,
union V_3 * V_124 )
{
T_2 V_207 ;
V_207 = F_99 ( F_3 ( V_124 -> V_29 . V_30 [ 3 ] ) ) ;
F_15 ( V_10 , L_64 , V_207 ) ;
if ( V_207 == V_208 && ( V_10 -> V_35 & V_172 ) )
F_95 ( V_10 , & V_124 -> V_209 ) ;
}
static unsigned int F_102 ( struct V_110 * V_111 ,
struct V_9 * V_10 , T_2 V_210 )
{
unsigned int V_134 ;
unsigned int V_211 = 0 ;
for ( V_134 = 0 ; V_134 < ( V_210 - 1 ) ; V_134 ++ ) {
T_6 V_212 = V_10 -> V_213 [ V_134 ] ;
if ( V_212 == 0 || V_212 == V_214 )
continue;
if ( ( V_212 == 0x03 ) == ( V_111 -> V_215 == V_216 ) )
V_211 ++ ;
}
return V_211 ;
}
static void F_103 ( struct V_9 * V_10 ,
union V_3 * V_124 )
{
T_2 V_56 ;
struct V_217 * V_218 ;
V_56 = F_96 ( F_3 ( V_124 -> V_29 . V_30 [ 3 ] ) ) ;
if ( ! V_10 -> V_62 [ V_56 ] ) {
F_30 ( V_10 , L_65
L_66 , V_56 ) ;
return;
}
F_15 ( V_10 , L_67 ,
V_56 ) ;
V_218 = V_10 -> V_62 [ V_56 ] -> V_218 ;
if ( V_218 && V_218 -> V_219 )
F_104 ( V_218 -> V_219 , V_218 -> V_220 ) ;
}
static void F_105 ( struct V_9 * V_10 ,
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
if ( F_98 ( F_3 ( V_124 -> V_29 . V_30 [ 2 ] ) ) != V_147 ) {
F_30 ( V_10 , L_68 ) ;
V_10 -> V_173 |= 1 << 8 ;
}
V_210 = F_106 ( F_3 ( V_124 -> V_29 . V_30 [ 0 ] ) ) ;
F_15 ( V_10 , L_69 , V_210 ) ;
V_223 = F_107 ( V_10 -> V_229 ) ;
if ( ( V_210 <= 0 ) || ( V_210 > V_223 ) ) {
F_30 ( V_10 , L_70 , V_210 ) ;
F_8 ( V_10 , V_10 -> V_13 ) ;
return;
}
V_225 = V_10 -> V_213 [ V_210 - 1 ] ;
V_111 = F_44 ( V_10 ) ;
if ( ( V_225 == 0x03 ) != ( V_111 -> V_215 == V_216 ) )
V_111 = V_10 -> V_230 ;
if ( V_225 == 0 ) {
F_30 ( V_10 , L_71
L_72 ,
V_210 ) ;
V_228 = true ;
goto V_146;
}
if ( V_225 == V_214 ) {
F_30 ( V_10 , L_73
L_72 ,
V_210 ) ;
V_228 = true ;
goto V_146;
}
V_227 = & V_10 -> V_227 [ F_108 ( V_111 ) ] ;
if ( V_111 -> V_215 == V_216 )
V_213 = V_10 -> V_231 ;
else
V_213 = V_10 -> V_232 ;
V_224 = F_102 ( V_111 , V_10 ,
V_210 ) ;
V_221 = F_17 ( V_213 [ V_224 ] ) ;
if ( V_111 -> V_80 == V_233 ) {
F_15 ( V_10 , L_74 ) ;
F_109 ( V_111 ) ;
}
if ( V_111 -> V_215 == V_216 && ( V_221 & V_234 ) == V_235 )
V_227 -> V_236 &= ~ ( 1 << V_224 ) ;
if ( ( V_221 & V_237 ) && ( V_221 & V_234 ) == V_238 ) {
F_15 ( V_10 , L_75 , V_210 ) ;
V_222 = F_17 ( & V_10 -> V_48 -> V_161 ) ;
if ( ! ( V_222 & V_239 ) ) {
F_30 ( V_10 , L_76 ) ;
goto V_146;
}
if ( F_110 ( V_221 ) ) {
F_15 ( V_10 , L_77 , V_210 ) ;
V_227 -> V_236 |= 1 << V_224 ;
F_111 ( V_10 , V_213 ,
V_224 , V_237 ) ;
F_112 ( V_10 , V_213 , V_224 ,
V_240 ) ;
V_228 = true ;
goto V_146;
} else {
F_15 ( V_10 , L_78 , V_210 ) ;
V_227 -> V_241 [ V_224 ] = V_186 +
F_113 ( V_242 ) ;
F_114 ( V_224 , & V_227 -> V_243 ) ;
F_93 ( & V_111 -> V_244 ,
V_227 -> V_241 [ V_224 ] ) ;
}
}
if ( ( V_221 & V_237 ) && ( V_221 & V_234 ) == V_240 &&
F_110 ( V_221 ) ) {
F_15 ( V_10 , L_79 , V_210 ) ;
V_56 = F_115 ( V_111 , V_10 ,
V_224 + 1 ) ;
if ( V_56 && V_10 -> V_62 [ V_56 ] )
F_116 ( V_10 , V_56 ) ;
if ( V_227 -> V_236 & ( 1 << V_224 ) ) {
V_227 -> V_236 &=
~ ( 1 << V_224 ) ;
F_111 ( V_10 , V_213 ,
V_224 , V_237 ) ;
F_104 ( V_111 -> V_119 . V_245 ,
V_224 + 1 ) ;
V_228 = true ;
goto V_146;
}
}
if ( ! F_110 ( V_221 ) &&
F_117 ( V_224 ,
& V_227 -> V_246 ) ) {
F_88 ( & V_227 -> V_247 [ V_224 ] ) ;
V_228 = true ;
goto V_146;
}
if ( V_111 -> V_215 != V_216 )
F_111 ( V_10 , V_213 , V_224 ,
V_237 ) ;
V_146:
F_8 ( V_10 , V_10 -> V_13 ) ;
if ( V_228 )
return;
F_15 ( V_10 , L_80 , V_248 ) ;
F_114 ( V_249 , & V_111 -> V_136 ) ;
F_47 ( & V_10 -> V_122 ) ;
F_118 ( V_111 ) ;
F_50 ( & V_10 -> V_122 ) ;
}
struct V_1 * F_119 ( struct V_9 * V_10 ,
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
F_30 ( V_10 ,
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
static void F_120 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 ,
struct V_77 * V_257 , union V_3 * V_258 )
{
struct V_60 * V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
struct V_160 * V_161 ;
V_161 = F_73 ( V_10 , false , false , V_162 ) ;
if ( ! V_161 )
return;
V_61 -> V_64 |= V_67 ;
V_61 -> V_259 = V_58 ;
F_121 ( V_10 , V_161 , V_56 , V_57 ) ;
F_122 ( V_10 , V_57 , V_257 ) ;
V_61 -> V_259 = 0 ;
F_14 ( V_10 ) ;
}
static int F_123 ( struct V_9 * V_10 ,
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
int F_124 ( struct V_9 * V_10 , unsigned int V_260 )
{
if ( V_260 >= 224 && V_260 <= 255 ) {
F_15 ( V_10 , L_82 ,
V_260 ) ;
F_15 ( V_10 , L_83 ) ;
return 1 ;
}
return 0 ;
}
static int F_125 ( struct V_9 * V_10 , struct V_77 * V_257 ,
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
V_56 = F_96 ( F_3 ( V_124 -> V_136 ) ) ;
V_267 = V_10 -> V_62 [ V_56 ] ;
V_57 = F_126 ( F_3 ( V_124 -> V_136 ) ) - 1 ;
V_82 = F_127 ( V_61 , F_35 ( V_124 -> V_268 ) ) ;
V_95 = F_36 ( V_10 , V_267 -> V_96 , V_57 ) ;
V_260 = F_98 ( F_3 ( V_124 -> V_269 ) ) ;
if ( V_266 )
goto V_270;
if ( V_260 == V_271 || V_260 == V_272 ) {
V_61 -> V_130 = V_257 ;
return 0 ;
}
if ( V_260 == V_273 ||
F_123 ( V_10 , V_95 ,
V_260 ) ) {
F_120 ( V_10 , V_56 , V_57 ,
V_82 -> V_58 , V_257 , V_258 ) ;
} else {
while ( V_82 -> V_24 != V_257 -> F_4 )
F_8 ( V_10 , V_82 ) ;
F_8 ( V_10 , V_82 ) ;
}
V_270:
V_74 = V_257 -> V_74 ;
V_112 = V_74 -> V_113 ;
if ( V_74 -> V_274 > V_74 -> V_275 ) {
F_30 ( V_10 , L_84 ,
V_74 -> V_275 ,
V_74 -> V_274 ) ;
V_74 -> V_274 = 0 ;
if ( V_257 -> V_74 -> V_276 & V_277 )
* V_109 = - V_278 ;
else
* V_109 = 0 ;
}
F_57 ( & V_257 -> V_69 ) ;
if ( ! F_28 ( & V_257 -> V_129 ) )
F_57 ( & V_257 -> V_129 ) ;
V_112 -> V_114 ++ ;
if ( V_112 -> V_114 == V_112 -> V_116 ) {
V_47 = 1 ;
if ( F_43 ( V_74 -> V_117 ) == V_118 ) {
F_44 ( V_10 ) -> V_119 . V_120 -- ;
if ( F_44 ( V_10 ) -> V_119 . V_120 == 0 ) {
if ( V_10 -> V_35 & V_121 )
F_45 () ;
}
}
}
return V_47 ;
}
static int F_128 ( struct V_9 * V_10 , struct V_77 * V_257 ,
union V_3 * V_258 , struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 )
{
struct V_81 * V_267 ;
struct V_11 * V_82 ;
unsigned int V_56 ;
int V_57 ;
struct V_94 * V_95 ;
T_2 V_260 ;
V_56 = F_96 ( F_3 ( V_124 -> V_136 ) ) ;
V_267 = V_10 -> V_62 [ V_56 ] ;
V_57 = F_126 ( F_3 ( V_124 -> V_136 ) ) - 1 ;
V_82 = F_127 ( V_61 , F_35 ( V_124 -> V_268 ) ) ;
V_95 = F_36 ( V_10 , V_267 -> V_96 , V_57 ) ;
V_260 = F_98 ( F_3 ( V_124 -> V_269 ) ) ;
switch ( V_260 ) {
case V_147 :
if ( V_258 == V_82 -> V_24 ) {
F_30 ( V_10 , L_85
L_86 ) ;
* V_109 = - V_55 ;
} else if ( V_258 != V_257 -> F_4 ) {
F_30 ( V_10 , L_87
L_86 ) ;
* V_109 = - V_55 ;
} else {
* V_109 = 0 ;
}
break;
case V_279 :
if ( V_257 -> V_74 -> V_276 & V_277 )
* V_109 = - V_278 ;
else
* V_109 = 0 ;
break;
case V_271 :
case V_272 :
return F_125 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
default:
if ( ! F_123 ( V_10 ,
V_95 , V_260 ) )
break;
F_15 ( V_10 , L_88
L_89 ,
V_260 , V_57 ) ;
case V_273 :
if ( V_258 != V_82 -> V_24 &&
V_258 != V_257 -> F_4 )
V_257 -> V_74 -> V_274 =
V_257 -> V_74 -> V_275 -
F_129 ( F_3 ( V_124 -> V_269 ) ) ;
else if ( ! V_257 -> V_280 )
V_257 -> V_74 -> V_274 = 0 ;
return F_125 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
}
if ( V_258 != V_82 -> V_24 ) {
if ( V_258 == V_257 -> F_4 ) {
if ( V_257 -> V_280 ) {
if ( ( * V_109 == - V_281 || * V_109 == 0 ) &&
( V_257 -> V_74 -> V_276
& V_277 ) )
* V_109 = - V_278 ;
} else {
V_257 -> V_74 -> V_274 =
V_257 -> V_74 -> V_275 ;
}
} else {
V_257 -> V_280 = true ;
V_257 -> V_74 -> V_274 =
V_257 -> V_74 -> V_275 -
F_129 ( F_3 ( V_124 -> V_269 ) ) ;
F_15 ( V_10 , L_90
L_91 ) ;
return 0 ;
}
}
return F_125 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
}
static int F_130 ( struct V_9 * V_10 , struct V_77 * V_257 ,
union V_3 * V_258 , struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 )
{
struct V_11 * V_82 ;
struct V_112 * V_112 ;
int V_282 ;
int V_283 = 0 ;
union V_3 * V_103 ;
struct V_1 * V_102 ;
struct V_284 * V_285 ;
T_2 V_260 ;
bool V_286 = false ;
V_82 = F_127 ( V_61 , F_35 ( V_124 -> V_268 ) ) ;
V_260 = F_98 ( F_3 ( V_124 -> V_269 ) ) ;
V_112 = V_257 -> V_74 -> V_113 ;
V_282 = V_112 -> V_114 ;
V_285 = & V_257 -> V_74 -> V_287 [ V_282 ] ;
switch ( V_260 ) {
case V_147 :
if ( F_129 ( F_3 ( V_124 -> V_269 ) ) == 0 ) {
V_285 -> V_109 = 0 ;
break;
}
if ( ( V_10 -> V_35 & V_288 ) )
V_260 = V_279 ;
case V_279 :
V_285 -> V_109 = V_257 -> V_74 -> V_276 & V_277 ?
- V_278 : 0 ;
break;
case V_289 :
V_285 -> V_109 = - V_290 ;
V_286 = true ;
break;
case V_291 :
case V_262 :
V_285 -> V_109 = - V_292 ;
V_286 = true ;
break;
case V_293 :
case V_273 :
V_285 -> V_109 = - V_294 ;
V_286 = true ;
break;
case V_261 :
V_285 -> V_109 = - V_294 ;
if ( V_258 != V_257 -> F_4 )
return 0 ;
V_286 = true ;
break;
case V_272 :
case V_271 :
break;
default:
V_285 -> V_109 = - 1 ;
break;
}
if ( V_260 == V_147 || V_286 ) {
V_285 -> V_274 = V_285 -> V_116 ;
V_257 -> V_74 -> V_274 += V_285 -> V_116 ;
} else {
for ( V_103 = V_82 -> V_24 ,
V_102 = V_82 -> V_23 ; V_103 != V_258 ;
F_7 ( V_10 , V_82 , & V_102 , & V_103 ) ) {
if ( ! F_131 ( V_103 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_103 -> V_29 . V_30 [ 3 ] ) )
V_283 += F_132 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) ;
}
V_283 += F_132 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) -
F_129 ( F_3 ( V_124 -> V_269 ) ) ;
if ( V_260 != V_271 ) {
V_285 -> V_274 = V_283 ;
V_257 -> V_74 -> V_274 += V_283 ;
}
}
return F_125 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
}
static int F_133 ( struct V_9 * V_10 , struct V_77 * V_257 ,
struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 )
{
struct V_11 * V_82 ;
struct V_112 * V_112 ;
struct V_284 * V_285 ;
int V_282 ;
V_82 = F_127 ( V_61 , F_35 ( V_124 -> V_268 ) ) ;
V_112 = V_257 -> V_74 -> V_113 ;
V_282 = V_112 -> V_114 ;
V_285 = & V_257 -> V_74 -> V_287 [ V_282 ] ;
V_285 -> V_109 = - V_295 ;
V_285 -> V_274 = 0 ;
while ( V_82 -> V_24 != V_257 -> F_4 )
F_8 ( V_10 , V_82 ) ;
F_8 ( V_10 , V_82 ) ;
return F_125 ( V_10 , V_257 , NULL , V_124 , V_61 , V_109 , true ) ;
}
static int F_134 ( struct V_9 * V_10 , struct V_77 * V_257 ,
union V_3 * V_258 , struct V_265 * V_124 ,
struct V_60 * V_61 , int * V_109 )
{
struct V_11 * V_82 ;
union V_3 * V_103 ;
struct V_1 * V_102 ;
T_2 V_260 ;
V_82 = F_127 ( V_61 , F_35 ( V_124 -> V_268 ) ) ;
V_260 = F_98 ( F_3 ( V_124 -> V_269 ) ) ;
switch ( V_260 ) {
case V_147 :
if ( V_258 != V_257 -> F_4 ||
F_129 ( F_3 ( V_124 -> V_269 ) ) != 0 ) {
F_30 ( V_10 , L_92
L_93 ) ;
if ( V_257 -> V_74 -> V_276 & V_277 )
* V_109 = - V_278 ;
else
* V_109 = 0 ;
if ( ( V_10 -> V_35 & V_288 ) )
V_260 = V_279 ;
} else {
* V_109 = 0 ;
}
break;
case V_279 :
if ( V_257 -> V_74 -> V_276 & V_277 )
* V_109 = - V_278 ;
else
* V_109 = 0 ;
break;
default:
break;
}
if ( V_260 == V_279 )
F_15 ( V_10 , L_94
L_95 ,
V_257 -> V_74 -> V_61 -> V_76 . V_296 ,
V_257 -> V_74 -> V_275 ,
F_129 ( F_3 ( V_124 -> V_269 ) ) ) ;
if ( V_258 == V_257 -> F_4 ) {
if ( F_129 ( F_3 ( V_124 -> V_269 ) ) != 0 ) {
V_257 -> V_74 -> V_274 =
V_257 -> V_74 -> V_275 -
F_129 ( F_3 ( V_124 -> V_269 ) ) ;
if ( V_257 -> V_74 -> V_275 <
V_257 -> V_74 -> V_274 ) {
F_30 ( V_10 , L_96
L_97 ,
F_129 ( F_3 ( V_124 -> V_269 ) ) ) ;
V_257 -> V_74 -> V_274 = 0 ;
if ( V_257 -> V_74 -> V_276 & V_277 )
* V_109 = - V_278 ;
else
* V_109 = 0 ;
}
if ( * V_109 == - V_281 ) {
if ( V_257 -> V_74 -> V_276 & V_277 )
* V_109 = - V_278 ;
else
* V_109 = 0 ;
}
} else {
V_257 -> V_74 -> V_274 =
V_257 -> V_74 -> V_275 ;
if ( * V_109 == - V_278 )
* V_109 = 0 ;
}
} else {
V_257 -> V_74 -> V_274 = 0 ;
for ( V_103 = V_82 -> V_24 , V_102 = V_82 -> V_23 ;
V_103 != V_258 ;
F_7 ( V_10 , V_82 , & V_102 , & V_103 ) ) {
if ( ! F_131 ( V_103 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_103 -> V_29 . V_30 [ 3 ] ) )
V_257 -> V_74 -> V_274 +=
F_132 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) ;
}
if ( V_260 != V_271 )
V_257 -> V_74 -> V_274 +=
F_132 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) -
F_129 ( F_3 ( V_124 -> V_269 ) ) ;
}
return F_125 ( V_10 , V_257 , V_258 , V_124 , V_61 , V_109 , false ) ;
}
static int F_135 ( struct V_9 * V_10 ,
struct V_265 * V_124 )
__releases( &xhci->lock
static int F_136 ( struct V_9 * V_10 )
{
union V_3 * V_124 ;
int V_297 = 1 ;
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
F_137 () ;
switch ( ( F_3 ( V_124 -> V_209 . V_136 ) & V_298 ) ) {
case F_38 ( V_299 ) :
F_95 ( V_10 , & V_124 -> V_209 ) ;
break;
case F_38 ( V_300 ) :
F_105 ( V_10 , V_124 ) ;
V_297 = 0 ;
break;
case F_38 ( V_301 ) :
V_47 = F_135 ( V_10 , & V_124 -> V_302 ) ;
if ( V_47 < 0 )
V_10 -> V_173 |= 1 << 9 ;
else
V_297 = 0 ;
break;
case F_38 ( V_303 ) :
F_103 ( V_10 , V_124 ) ;
break;
default:
if ( ( F_3 ( V_124 -> V_209 . V_136 ) & V_298 ) >=
F_38 ( 48 ) )
F_101 ( V_10 , V_124 ) ;
else
V_10 -> V_173 |= 1 << 3 ;
}
if ( V_10 -> V_53 & V_54 ) {
F_15 ( V_10 , L_98
L_99 ) ;
return 0 ;
}
if ( V_297 )
F_8 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_138 ( struct V_110 * V_111 )
{
struct V_9 * V_10 = F_139 ( V_111 ) ;
T_2 V_109 ;
T_3 V_46 ;
union V_3 * V_304 ;
T_1 V_97 ;
F_50 ( & V_10 -> V_122 ) ;
V_109 = F_17 ( & V_10 -> V_48 -> V_109 ) ;
if ( V_109 == 0xffffffff )
goto V_305;
if ( ! ( V_109 & V_306 ) ) {
F_47 ( & V_10 -> V_122 ) ;
return V_307 ;
}
if ( V_109 & V_308 ) {
F_30 ( V_10 , L_100 ) ;
F_24 ( V_10 ) ;
V_305:
F_47 ( & V_10 -> V_122 ) ;
return V_309 ;
}
V_109 |= V_306 ;
F_16 ( V_109 , & V_10 -> V_48 -> V_109 ) ;
if ( V_111 -> V_310 ) {
T_2 V_311 ;
V_311 = F_17 ( & V_10 -> V_312 -> V_311 ) ;
V_311 |= V_313 ;
F_16 ( V_311 , & V_10 -> V_312 -> V_311 ) ;
}
if ( V_10 -> V_53 & V_54 ) {
F_15 ( V_10 , L_101
L_102 ) ;
V_46 = F_19 ( V_10 , & V_10 -> V_312 -> V_314 ) ;
F_20 ( V_10 , V_46 | V_315 ,
& V_10 -> V_312 -> V_314 ) ;
F_47 ( & V_10 -> V_122 ) ;
return V_309 ;
}
V_304 = V_10 -> V_13 -> V_24 ;
while ( F_136 ( V_10 ) > 0 ) {}
V_46 = F_19 ( V_10 , & V_10 -> V_312 -> V_314 ) ;
if ( V_304 != V_10 -> V_13 -> V_24 ) {
V_97 = F_1 ( V_10 -> V_13 -> V_23 ,
V_10 -> V_13 -> V_24 ) ;
if ( V_97 == 0 )
F_30 ( V_10 , L_103
L_104 ) ;
V_46 &= V_316 ;
V_46 |= ( ( T_3 ) V_97 & ( T_3 ) ~ V_316 ) ;
}
V_46 |= V_315 ;
F_20 ( V_10 , V_46 , & V_10 -> V_312 -> V_314 ) ;
F_47 ( & V_10 -> V_122 ) ;
return V_309 ;
}
T_7 F_140 ( int V_310 , void * V_111 )
{
return F_138 ( V_111 ) ;
}
static void F_141 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_27 ,
T_2 V_317 , T_2 V_318 , T_2 V_319 , T_2 V_320 )
{
struct V_194 * V_4 ;
V_4 = & V_12 -> V_20 -> V_29 ;
V_4 -> V_30 [ 0 ] = F_11 ( V_317 ) ;
V_4 -> V_30 [ 1 ] = F_11 ( V_318 ) ;
V_4 -> V_30 [ 2 ] = F_11 ( V_319 ) ;
V_4 -> V_30 [ 3 ] = F_11 ( V_320 ) ;
F_9 ( V_10 , V_12 , V_27 ) ;
}
static int F_142 ( struct V_9 * V_10 , struct V_11 * V_82 ,
T_2 V_64 , unsigned int V_38 , T_8 V_321 )
{
unsigned int V_322 ;
switch ( V_64 ) {
case V_323 :
F_30 ( V_10 , L_105 ) ;
return - V_324 ;
case V_325 :
F_30 ( V_10 , L_106 ) ;
return - V_326 ;
case V_264 :
F_15 ( V_10 , L_107 ) ;
case V_327 :
case V_328 :
break;
default:
F_22 ( V_10 , L_108 ) ;
return - V_326 ;
}
while ( 1 ) {
if ( F_13 ( V_10 , V_82 , V_38 ) )
break;
if ( V_82 == V_10 -> V_49 ) {
F_22 ( V_10 , L_109 ) ;
return - V_329 ;
}
F_34 ( V_10 , V_330 ,
L_110 ) ;
V_322 = V_38 - V_82 -> V_25 ;
if ( F_143 ( V_10 , V_82 , V_322 ,
V_321 ) ) {
F_22 ( V_10 , L_111 ) ;
return - V_329 ;
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
static int F_144 ( struct V_9 * V_10 ,
struct V_81 * V_267 ,
unsigned int V_57 ,
unsigned int V_58 ,
unsigned int V_38 ,
struct V_74 * V_74 ,
unsigned int V_331 ,
T_8 V_321 )
{
int V_47 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
struct V_11 * V_82 ;
struct V_94 * V_95 = F_36 ( V_10 , V_267 -> V_96 , V_57 ) ;
V_82 = F_69 ( V_267 , V_57 , V_58 ) ;
if ( ! V_82 ) {
F_15 ( V_10 , L_112 ,
V_58 ) ;
return - V_326 ;
}
V_47 = F_142 ( V_10 , V_82 ,
F_3 ( V_95 -> V_151 ) & V_152 ,
V_38 , V_321 ) ;
if ( V_47 )
return V_47 ;
V_112 = V_74 -> V_113 ;
V_257 = V_112 -> V_257 [ V_331 ] ;
F_145 ( & V_257 -> V_69 ) ;
F_145 ( & V_257 -> V_129 ) ;
if ( V_331 == 0 ) {
V_47 = F_146 ( F_42 ( V_74 -> V_75 -> V_115 ) , V_74 ) ;
if ( F_52 ( V_47 ) )
return V_47 ;
}
V_257 -> V_74 = V_74 ;
F_147 ( & V_257 -> V_69 , & V_82 -> V_69 ) ;
V_257 -> V_104 = V_82 -> V_32 ;
V_257 -> V_105 = V_82 -> V_20 ;
V_112 -> V_257 [ V_331 ] = V_257 ;
return 0 ;
}
static unsigned int F_148 ( struct V_9 * V_10 , struct V_74 * V_74 )
{
int V_332 , V_38 , V_333 , V_221 , V_134 ;
struct V_334 * V_335 ;
V_335 = NULL ;
V_332 = V_74 -> V_336 ;
V_221 = V_74 -> V_275 ;
V_38 = 0 ;
F_149 (urb->sg, sg, num_sgs, i) {
unsigned int V_283 = F_150 ( V_335 ) ;
V_333 = V_337 -
( F_151 ( V_335 ) & ( V_337 - 1 ) ) ;
V_333 &= V_337 - 1 ;
if ( V_333 != 0 )
V_38 ++ ;
while ( V_333 < F_150 ( V_335 ) && V_333 < V_221 ) {
V_38 ++ ;
V_333 += V_337 ;
}
V_283 = F_152 ( int , V_283 , V_221 ) ;
V_221 -= V_283 ;
if ( V_221 == 0 )
break;
}
return V_38 ;
}
static void F_153 ( struct V_74 * V_74 , int V_38 , int V_333 )
{
if ( V_38 != 0 )
F_154 ( & V_74 -> V_75 -> V_75 , L_113
L_114 , V_248 ,
V_74 -> V_61 -> V_76 . V_296 , V_38 ) ;
if ( V_333 != V_74 -> V_275 )
F_154 ( & V_74 -> V_75 -> V_75 , L_115
L_116 ,
V_248 ,
V_74 -> V_61 -> V_76 . V_296 ,
V_333 , V_333 ,
V_74 -> V_275 ,
V_74 -> V_275 ) ;
}
static void F_155 ( struct V_9 * V_10 , int V_56 ,
unsigned int V_57 , unsigned int V_58 , int V_338 ,
struct V_194 * V_250 )
{
F_12 () ;
if ( V_338 )
V_250 -> V_30 [ 3 ] |= F_11 ( V_338 ) ;
else
V_250 -> V_30 [ 3 ] &= F_11 ( ~ V_37 ) ;
F_25 ( V_10 , V_56 , V_57 , V_58 ) ;
}
int F_156 ( struct V_9 * V_10 , T_8 V_321 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_94 * V_95 = F_36 ( V_10 ,
V_10 -> V_62 [ V_56 ] -> V_96 , V_57 ) ;
int V_339 ;
int V_340 ;
V_339 = F_157 ( F_3 ( V_95 -> V_151 ) ) ;
V_340 = V_74 -> V_341 ;
if ( V_74 -> V_75 -> V_215 == V_342 ||
V_74 -> V_75 -> V_215 == V_343 )
V_340 *= 8 ;
if ( V_339 != V_340 ) {
F_158 ( & V_74 -> V_75 -> V_75 ,
L_117 ,
V_340 , V_340 == 1 ? L_118 : L_119 ,
V_339 , V_339 == 1 ? L_118 : L_119 ) ;
V_74 -> V_341 = V_339 ;
if ( V_74 -> V_75 -> V_215 == V_342 ||
V_74 -> V_75 -> V_215 == V_343 )
V_74 -> V_341 /= 8 ;
}
return F_159 ( V_10 , V_321 , V_74 , V_56 , V_57 ) ;
}
static T_2 F_160 ( unsigned int V_344 )
{
T_2 V_345 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_344 >> 10 ) >= V_345 )
return V_345 << 17 ;
else
return ( V_344 >> 10 ) << 17 ;
}
static T_2 F_161 ( int V_333 , int V_346 ,
unsigned int V_347 , struct V_74 * V_74 ,
unsigned int V_348 )
{
int V_349 ;
if ( V_348 == 0 || ( V_333 == 0 && V_346 == 0 ) )
return 0 ;
V_349 = ( V_333 + V_346 ) /
F_162 ( F_163 ( & V_74 -> V_61 -> V_76 ) ) ;
if ( ( V_347 - V_349 ) > 31 )
return 31 << 17 ;
return ( V_347 - V_349 ) << 17 ;
}
static int F_164 ( struct V_9 * V_10 , T_8 V_321 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
unsigned int V_38 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
struct V_334 * V_335 ;
int V_332 ;
int V_346 , V_350 , V_333 ;
unsigned int V_347 ;
bool V_105 ;
T_3 V_85 ;
bool V_27 ;
struct V_194 * V_250 ;
int V_338 ;
V_82 = F_31 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_326 ;
V_38 = F_148 ( V_10 , V_74 ) ;
V_332 = V_74 -> V_336 ;
V_347 = F_165 ( V_74 -> V_275 ,
F_163 ( & V_74 -> V_61 -> V_76 ) ) ;
V_346 = F_144 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_321 ) ;
if ( V_346 < 0 )
return V_346 ;
V_112 = V_74 -> V_113 ;
V_257 = V_112 -> V_257 [ 0 ] ;
V_250 = & V_82 -> V_20 -> V_29 ;
V_338 = V_82 -> V_26 ;
V_333 = 0 ;
V_335 = V_74 -> V_335 ;
V_85 = ( T_3 ) F_151 ( V_335 ) ;
V_350 = F_150 ( V_335 ) ;
V_346 = V_337 - ( V_85 & ( V_337 - 1 ) ) ;
V_346 = F_152 ( int , V_346 , V_350 ) ;
if ( V_346 > V_74 -> V_275 )
V_346 = V_74 -> V_275 ;
V_105 = true ;
do {
T_2 V_30 = 0 ;
T_2 V_351 = 0 ;
T_2 V_344 = 0 ;
if ( V_105 ) {
V_105 = false ;
if ( V_338 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_82 -> V_26 ;
if ( V_38 > 1 ) {
V_30 |= V_31 ;
} else {
V_257 -> F_4 = V_82 -> V_20 ;
V_30 |= V_352 ;
}
if ( F_166 ( V_74 ) )
V_30 |= V_353 ;
if ( V_337 -
( V_85 & ( V_337 - 1 ) ) < V_346 ) {
F_30 ( V_10 , L_120 ) ;
F_15 ( V_10 , L_121 ,
( unsigned int ) ( V_85 + V_337 ) & ~ ( V_337 - 1 ) ,
( unsigned int ) V_85 + V_346 ) ;
}
if ( V_10 -> V_354 < 0x100 ) {
V_344 = F_160 (
V_74 -> V_275 -
V_333 ) ;
} else {
V_344 = F_161 ( V_333 ,
V_346 , V_347 , V_74 ,
V_38 - 1 ) ;
}
V_351 = F_132 ( V_346 ) |
V_344 |
F_167 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_141 ( V_10 , V_82 , V_27 ,
F_168 ( V_85 ) ,
F_169 ( V_85 ) ,
V_351 ,
V_30 | F_38 ( V_355 ) ) ;
-- V_38 ;
V_333 += V_346 ;
V_350 -= V_346 ;
if ( V_350 == 0 ) {
-- V_332 ;
if ( V_332 == 0 )
break;
V_335 = F_170 ( V_335 ) ;
V_85 = ( T_3 ) F_151 ( V_335 ) ;
V_350 = F_150 ( V_335 ) ;
} else {
V_85 += V_346 ;
}
V_346 = V_337 -
( V_85 & ( V_337 - 1 ) ) ;
V_346 = F_152 ( int , V_346 , V_350 ) ;
if ( V_333 + V_346 > V_74 -> V_275 )
V_346 =
V_74 -> V_275 - V_333 ;
} while ( V_333 < V_74 -> V_275 );
F_153 ( V_74 , V_38 , V_333 ) ;
F_155 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_338 , V_250 ) ;
return 0 ;
}
int F_159 ( struct V_9 * V_10 , T_8 V_321 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
int V_38 ;
struct V_194 * V_250 ;
bool V_105 ;
bool V_27 ;
int V_338 ;
T_2 V_30 , V_351 ;
int V_333 , V_346 , V_47 ;
unsigned int V_347 ;
T_3 V_85 ;
if ( V_74 -> V_332 )
return F_164 ( V_10 , V_321 , V_74 , V_56 , V_57 ) ;
V_82 = F_31 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_326 ;
V_38 = 0 ;
V_333 = V_337 -
( V_74 -> V_356 & ( V_337 - 1 ) ) ;
V_333 &= V_337 - 1 ;
if ( V_333 != 0 || V_74 -> V_275 == 0 )
V_38 ++ ;
while ( V_333 < V_74 -> V_275 ) {
V_38 ++ ;
V_333 += V_337 ;
}
V_47 = F_144 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_321 ) ;
if ( V_47 < 0 )
return V_47 ;
V_112 = V_74 -> V_113 ;
V_257 = V_112 -> V_257 [ 0 ] ;
V_250 = & V_82 -> V_20 -> V_29 ;
V_338 = V_82 -> V_26 ;
V_333 = 0 ;
V_347 = F_165 ( V_74 -> V_275 ,
F_163 ( & V_74 -> V_61 -> V_76 ) ) ;
V_85 = ( T_3 ) V_74 -> V_356 ;
V_346 = V_337 -
( V_74 -> V_356 & ( V_337 - 1 ) ) ;
if ( V_346 > V_74 -> V_275 )
V_346 = V_74 -> V_275 ;
V_105 = true ;
do {
T_2 V_344 = 0 ;
V_30 = 0 ;
if ( V_105 ) {
V_105 = false ;
if ( V_338 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_82 -> V_26 ;
if ( V_38 > 1 ) {
V_30 |= V_31 ;
} else {
V_257 -> F_4 = V_82 -> V_20 ;
V_30 |= V_352 ;
}
if ( F_166 ( V_74 ) )
V_30 |= V_353 ;
if ( V_10 -> V_354 < 0x100 ) {
V_344 = F_160 (
V_74 -> V_275 -
V_333 ) ;
} else {
V_344 = F_161 ( V_333 ,
V_346 , V_347 , V_74 ,
V_38 - 1 ) ;
}
V_351 = F_132 ( V_346 ) |
V_344 |
F_167 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_141 ( V_10 , V_82 , V_27 ,
F_168 ( V_85 ) ,
F_169 ( V_85 ) ,
V_351 ,
V_30 | F_38 ( V_355 ) ) ;
-- V_38 ;
V_333 += V_346 ;
V_85 += V_346 ;
V_346 = V_74 -> V_275 - V_333 ;
if ( V_346 > V_337 )
V_346 = V_337 ;
} while ( V_333 < V_74 -> V_275 );
F_153 ( V_74 , V_38 , V_333 ) ;
F_155 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_338 , V_250 ) ;
return 0 ;
}
int F_171 ( struct V_9 * V_10 , T_8 V_321 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
int V_38 ;
int V_47 ;
struct V_357 * V_358 ;
struct V_194 * V_250 ;
int V_338 ;
T_2 V_30 , V_351 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
V_82 = F_31 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_326 ;
if ( ! V_74 -> V_359 )
return - V_326 ;
V_38 = 2 ;
if ( V_74 -> V_275 > 0 )
V_38 ++ ;
V_47 = F_144 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_321 ) ;
if ( V_47 < 0 )
return V_47 ;
V_112 = V_74 -> V_113 ;
V_257 = V_112 -> V_257 [ 0 ] ;
V_250 = & V_82 -> V_20 -> V_29 ;
V_338 = V_82 -> V_26 ;
V_358 = (struct V_357 * ) V_74 -> V_359 ;
V_30 = 0 ;
V_30 |= V_360 | F_38 ( V_361 ) ;
if ( V_338 == 0 )
V_30 |= 0x1 ;
if ( V_10 -> V_354 == 0x100 ) {
if ( V_74 -> V_275 > 0 ) {
if ( V_358 -> V_362 & V_363 )
V_30 |= F_172 ( V_364 ) ;
else
V_30 |= F_172 ( V_365 ) ;
}
}
F_141 ( V_10 , V_82 , true ,
V_358 -> V_362 | V_358 -> V_366 << 8 | F_173 ( V_358 -> V_367 ) << 16 ,
F_173 ( V_358 -> V_368 ) | F_173 ( V_358 -> V_369 ) << 16 ,
F_132 ( 8 ) | F_167 ( 0 ) ,
V_30 ) ;
if ( F_166 ( V_74 ) )
V_30 = V_353 | F_38 ( V_370 ) ;
else
V_30 = F_38 ( V_370 ) ;
V_351 = F_132 ( V_74 -> V_275 ) |
F_160 ( V_74 -> V_275 ) |
F_167 ( 0 ) ;
if ( V_74 -> V_275 > 0 ) {
if ( V_358 -> V_362 & V_363 )
V_30 |= V_371 ;
F_141 ( V_10 , V_82 , true ,
F_168 ( V_74 -> V_356 ) ,
F_169 ( V_74 -> V_356 ) ,
V_351 ,
V_30 | V_82 -> V_26 ) ;
}
V_257 -> F_4 = V_82 -> V_20 ;
if ( V_74 -> V_275 > 0 && V_358 -> V_362 & V_363 )
V_30 = 0 ;
else
V_30 = V_371 ;
F_141 ( V_10 , V_82 , false ,
0 ,
0 ,
F_167 ( 0 ) ,
V_30 | V_352 | F_38 ( V_372 ) | V_82 -> V_26 ) ;
F_155 ( V_10 , V_56 , V_57 , 0 ,
V_338 , V_250 ) ;
return 0 ;
}
static int F_174 ( struct V_9 * V_10 ,
struct V_74 * V_74 , int V_134 )
{
int V_38 = 0 ;
T_3 V_85 , V_373 ;
V_85 = ( T_3 ) ( V_74 -> V_356 + V_74 -> V_287 [ V_134 ] . V_374 ) ;
V_373 = V_74 -> V_287 [ V_134 ] . V_116 ;
V_38 = F_165 ( V_373 + ( V_85 & ( V_337 - 1 ) ) ,
V_337 ) ;
if ( V_38 == 0 )
V_38 ++ ;
return V_38 ;
}
static unsigned int F_175 ( struct V_9 * V_10 ,
struct V_217 * V_218 ,
struct V_74 * V_74 , unsigned int V_347 )
{
unsigned int V_375 ;
if ( V_10 -> V_354 < 0x100 || V_218 -> V_215 != V_376 )
return 0 ;
V_375 = V_74 -> V_61 -> V_377 . V_378 ;
return F_165 ( V_347 , V_375 + 1 ) - 1 ;
}
static unsigned int F_176 ( struct V_9 * V_10 ,
struct V_217 * V_218 ,
struct V_74 * V_74 , unsigned int V_347 )
{
unsigned int V_375 ;
unsigned int V_379 ;
if ( V_10 -> V_354 < 0x100 )
return 0 ;
switch ( V_218 -> V_215 ) {
case V_376 :
V_375 = V_74 -> V_61 -> V_377 . V_378 ;
V_379 = V_347 % ( V_375 + 1 ) ;
if ( V_379 == 0 )
return V_375 ;
return V_379 - 1 ;
default:
if ( V_347 == 0 )
return 0 ;
return V_347 - 1 ;
}
}
static int F_177 ( struct V_9 * V_10 , T_8 V_321 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
struct V_112 * V_112 ;
struct V_77 * V_257 ;
int V_380 , V_381 ;
struct V_194 * V_250 ;
bool V_105 ;
int V_338 ;
T_2 V_30 , V_351 ;
int V_333 , V_346 , V_373 , V_382 , V_47 ;
T_3 V_383 , V_85 ;
int V_134 , V_135 ;
bool V_27 ;
V_82 = V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] . V_12 ;
V_380 = V_74 -> V_384 ;
if ( V_380 < 1 ) {
F_15 ( V_10 , L_122 ) ;
return - V_326 ;
}
V_383 = ( T_3 ) V_74 -> V_356 ;
V_250 = & V_82 -> V_20 -> V_29 ;
V_338 = V_82 -> V_26 ;
V_112 = V_74 -> V_113 ;
for ( V_134 = 0 ; V_134 < V_380 ; V_134 ++ ) {
unsigned int V_347 ;
unsigned int V_385 ;
unsigned int V_379 ;
V_105 = true ;
V_333 = 0 ;
V_85 = V_383 + V_74 -> V_287 [ V_134 ] . V_374 ;
V_373 = V_74 -> V_287 [ V_134 ] . V_116 ;
V_382 = V_373 ;
V_347 = F_165 ( V_373 ,
F_162 (
F_163 ( & V_74 -> V_61 -> V_76 ) ) ) ;
if ( V_347 == 0 )
V_347 ++ ;
V_385 = F_175 ( V_10 , V_74 -> V_75 , V_74 ,
V_347 ) ;
V_379 = F_176 ( V_10 ,
V_74 -> V_75 , V_74 , V_347 ) ;
V_381 = F_174 ( V_10 , V_74 , V_134 ) ;
V_47 = F_144 ( V_10 , V_10 -> V_62 [ V_56 ] , V_57 ,
V_74 -> V_58 , V_381 , V_74 , V_134 , V_321 ) ;
if ( V_47 < 0 ) {
if ( V_134 == 0 )
return V_47 ;
goto V_146;
}
V_257 = V_112 -> V_257 [ V_134 ] ;
for ( V_135 = 0 ; V_135 < V_381 ; V_135 ++ ) {
T_2 V_344 = 0 ;
V_30 = 0 ;
if ( V_105 ) {
V_30 = F_178 ( V_385 ) |
F_179 ( V_379 ) ;
V_30 |= F_38 ( V_386 ) ;
V_30 |= V_387 ;
if ( V_134 == 0 ) {
if ( V_338 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_82 -> V_26 ;
V_105 = false ;
} else {
V_30 |= F_38 ( V_355 ) ;
V_30 |= V_82 -> V_26 ;
}
if ( F_166 ( V_74 ) )
V_30 |= V_353 ;
if ( V_135 < V_381 - 1 ) {
V_30 |= V_31 ;
V_27 = true ;
} else {
V_257 -> F_4 = V_82 -> V_20 ;
V_30 |= V_352 ;
if ( V_10 -> V_354 == 0x100 &&
! ( V_10 -> V_35 &
V_388 ) ) {
if ( V_134 < V_380 - 1 )
V_30 |= V_389 ;
}
V_27 = false ;
}
V_346 = V_337 -
( V_85 & ( ( 1 << V_390 ) - 1 ) ) ;
if ( V_346 > V_382 )
V_346 = V_382 ;
if ( V_10 -> V_354 < 0x100 ) {
V_344 = F_160 (
V_373 - V_333 ) ;
} else {
V_344 = F_161 (
V_333 , V_346 ,
V_347 , V_74 ,
( V_381 - V_135 - 1 ) ) ;
}
V_351 = F_132 ( V_346 ) |
V_344 |
F_167 ( 0 ) ;
F_141 ( V_10 , V_82 , V_27 ,
F_168 ( V_85 ) ,
F_169 ( V_85 ) ,
V_351 ,
V_30 ) ;
V_333 += V_346 ;
V_85 += V_346 ;
V_382 -= V_346 ;
}
if ( V_333 != V_373 ) {
F_22 ( V_10 , L_123 ) ;
V_47 = - V_326 ;
goto V_146;
}
}
if ( F_44 ( V_10 ) -> V_119 . V_120 == 0 ) {
if ( V_10 -> V_35 & V_121 )
F_180 () ;
}
F_44 ( V_10 ) -> V_119 . V_120 ++ ;
F_155 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_338 , V_250 ) ;
return 0 ;
V_146:
for ( V_134 -- ; V_134 >= 0 ; V_134 -- )
F_57 ( & V_112 -> V_257 [ V_134 ] -> V_69 ) ;
V_112 -> V_257 [ 0 ] -> F_4 = V_82 -> V_20 ;
F_37 ( V_10 , V_82 , V_112 -> V_257 [ 0 ] , true ) ;
V_82 -> V_20 = V_112 -> V_257 [ 0 ] -> V_105 ;
V_82 -> V_32 = V_112 -> V_257 [ 0 ] -> V_104 ;
V_82 -> V_26 = V_338 ;
V_82 -> V_25 = V_82 -> V_140 ;
F_46 ( F_42 ( V_74 -> V_75 -> V_115 ) , V_74 ) ;
return V_47 ;
}
int F_181 ( struct V_9 * V_10 , T_8 V_321 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_81 * V_267 ;
struct V_11 * V_82 ;
struct V_94 * V_95 ;
int V_391 ;
int V_339 ;
int V_340 ;
int V_380 , V_38 , V_134 ;
int V_47 ;
V_267 = V_10 -> V_62 [ V_56 ] ;
V_82 = V_267 -> V_63 [ V_57 ] . V_12 ;
V_95 = F_36 ( V_10 , V_267 -> V_96 , V_57 ) ;
V_38 = 0 ;
V_380 = V_74 -> V_384 ;
for ( V_134 = 0 ; V_134 < V_380 ; V_134 ++ )
V_38 += F_174 ( V_10 , V_74 , V_134 ) ;
V_47 = F_142 ( V_10 , V_82 , F_3 ( V_95 -> V_151 ) & V_152 ,
V_38 , V_321 ) ;
if ( V_47 )
return V_47 ;
V_391 = F_17 ( & V_10 -> V_392 -> V_393 ) ;
V_391 &= 0x3fff ;
V_74 -> V_391 = V_391 ;
if ( V_74 -> V_75 -> V_215 == V_342 ||
V_74 -> V_75 -> V_215 == V_343 )
V_74 -> V_391 >>= 3 ;
V_339 = F_157 ( F_3 ( V_95 -> V_151 ) ) ;
V_340 = V_74 -> V_341 ;
if ( V_74 -> V_75 -> V_215 == V_342 ||
V_74 -> V_75 -> V_215 == V_343 )
V_340 *= 8 ;
if ( V_339 != V_340 ) {
F_158 ( & V_74 -> V_75 -> V_75 ,
L_117 ,
V_340 , V_340 == 1 ? L_118 : L_119 ,
V_339 , V_339 == 1 ? L_118 : L_119 ) ;
V_74 -> V_341 = V_339 ;
if ( V_74 -> V_75 -> V_215 == V_342 ||
V_74 -> V_75 -> V_215 == V_343 )
V_74 -> V_341 /= 8 ;
}
V_82 -> V_140 = V_82 -> V_25 ;
return F_177 ( V_10 , V_321 , V_74 , V_56 , V_57 ) ;
}
static int F_182 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_2 V_317 , T_2 V_318 ,
T_2 V_319 , T_2 V_320 , bool V_394 )
{
int V_395 = V_10 -> V_396 ;
int V_47 ;
if ( V_10 -> V_53 ) {
F_15 ( V_10 , L_124 ) ;
return - V_55 ;
}
if ( ! V_394 )
V_395 ++ ;
V_47 = F_142 ( V_10 , V_10 -> V_49 , V_328 ,
V_395 , V_162 ) ;
if ( V_47 < 0 ) {
F_22 ( V_10 , L_125 ) ;
if ( V_394 )
F_22 ( V_10 , L_126
L_127 ) ;
return V_47 ;
}
V_174 -> V_182 = V_10 -> V_49 -> V_20 ;
F_147 ( & V_174 -> V_175 , & V_10 -> V_175 ) ;
if ( V_10 -> V_175 . V_14 == & V_174 -> V_175 &&
! F_183 ( & V_10 -> V_185 ) ) {
V_10 -> V_184 = V_174 ;
F_93 ( & V_10 -> V_185 , V_186 + V_187 ) ;
}
F_141 ( V_10 , V_10 -> V_49 , false , V_317 , V_318 , V_319 ,
V_320 | V_10 -> V_49 -> V_26 ) ;
return 0 ;
}
int F_184 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_2 V_207 , T_2 V_56 )
{
return F_182 ( V_10 , V_174 , 0 , 0 , 0 ,
F_38 ( V_207 ) | F_185 ( V_56 ) , false ) ;
}
int F_186 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_1 V_397 , T_2 V_56 , enum V_398 V_358 )
{
return F_182 ( V_10 , V_174 , F_168 ( V_397 ) ,
F_169 ( V_397 ) , 0 ,
F_38 ( V_201 ) | F_185 ( V_56 )
| ( V_358 == V_399 ? V_400 : 0 ) , false ) ;
}
int F_187 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_2 V_317 , T_2 V_318 , T_2 V_319 , T_2 V_320 )
{
return F_182 ( V_10 , V_174 , V_317 , V_318 , V_319 , V_320 , false ) ;
}
int F_188 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_2 V_56 )
{
return F_182 ( V_10 , V_174 , 0 , 0 , 0 ,
F_38 ( V_205 ) | F_185 ( V_56 ) ,
false ) ;
}
int F_74 ( struct V_9 * V_10 ,
struct V_160 * V_174 , T_1 V_397 ,
T_2 V_56 , bool V_394 )
{
return F_182 ( V_10 , V_174 , F_168 ( V_397 ) ,
F_169 ( V_397 ) , 0 ,
F_38 ( V_199 ) | F_185 ( V_56 ) ,
V_394 ) ;
}
int F_189 ( struct V_9 * V_10 , struct V_160 * V_174 ,
T_1 V_397 , T_2 V_56 , bool V_394 )
{
return F_182 ( V_10 , V_174 , F_168 ( V_397 ) ,
F_169 ( V_397 ) , 0 ,
F_38 ( V_200 ) | F_185 ( V_56 ) ,
V_394 ) ;
}
int F_190 ( struct V_9 * V_10 , struct V_160 * V_174 ,
int V_56 , unsigned int V_57 , int V_401 )
{
T_2 V_402 = F_185 ( V_56 ) ;
T_2 V_403 = F_191 ( V_57 ) ;
T_2 type = F_38 ( V_202 ) ;
T_2 V_404 = F_192 ( V_401 ) ;
return F_182 ( V_10 , V_174 , 0 , 0 , 0 ,
V_402 | V_403 | type | V_404 , false ) ;
}
void F_58 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 ,
struct V_79 * V_128 )
{
T_1 V_85 ;
T_2 V_402 = F_185 ( V_56 ) ;
T_2 V_403 = F_191 ( V_57 ) ;
T_2 V_405 = F_193 ( V_58 ) ;
T_2 V_406 = 0 ;
T_2 type = F_38 ( V_203 ) ;
struct V_60 * V_61 ;
struct V_160 * V_174 ;
int V_47 ;
F_34 ( V_10 , V_89 ,
L_128 ,
V_128 -> V_99 ,
( unsigned long long ) V_128 -> V_99 -> V_8 ,
V_128 -> V_100 ,
( unsigned long long ) F_1 (
V_128 -> V_99 , V_128 -> V_100 ) ,
V_128 -> V_98 ) ;
V_85 = F_1 ( V_128 -> V_99 ,
V_128 -> V_100 ) ;
if ( V_85 == 0 ) {
F_30 ( V_10 , L_129 ) ;
F_30 ( V_10 , L_130 ,
V_128 -> V_99 , V_128 -> V_100 ) ;
return;
}
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ( V_61 -> V_64 & V_66 ) ) {
F_30 ( V_10 , L_129 ) ;
F_30 ( V_10 , L_131 ) ;
return;
}
V_174 = F_73 ( V_10 , false , false , V_162 ) ;
if ( ! V_174 ) {
F_30 ( V_10 , L_132 ) ;
return;
}
V_61 -> V_157 = V_128 -> V_99 ;
V_61 -> V_142 = V_128 -> V_100 ;
if ( V_58 )
V_406 = F_194 ( V_407 ) ;
V_47 = F_182 ( V_10 , V_174 ,
F_168 ( V_85 ) | V_406 | V_128 -> V_98 ,
F_169 ( V_85 ) , V_405 ,
V_402 | V_403 | type , false ) ;
if ( V_47 < 0 ) {
F_195 ( V_10 , V_174 ) ;
return;
}
V_61 -> V_64 |= V_66 ;
}
int F_121 ( struct V_9 * V_10 , struct V_160 * V_174 ,
int V_56 , unsigned int V_57 )
{
T_2 V_402 = F_185 ( V_56 ) ;
T_2 V_403 = F_191 ( V_57 ) ;
T_2 type = F_38 ( V_204 ) ;
return F_182 ( V_10 , V_174 , 0 , 0 , 0 ,
V_402 | V_403 | type , false ) ;
}
