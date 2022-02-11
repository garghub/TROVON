T_1 F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
unsigned long V_5 ;
if ( ! V_2 || ! V_4 || V_4 < V_2 -> V_6 )
return 0 ;
V_5 = V_4 - V_2 -> V_6 ;
if ( V_5 > V_7 )
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
V_12 -> V_26 = ( V_12 -> V_26 ? 0 : 1 ) ;
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
V_47 = F_21 ( V_10 , & V_10 -> V_48 -> V_49 ,
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
void F_39 ( struct V_9 * V_10 ,
struct V_107 * V_108 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 ,
struct V_79 * V_109 )
{
struct V_60 * V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
F_34 ( V_10 , V_89 ,
L_21
L_22 ,
V_109 -> V_99 ,
( unsigned long long ) V_109 -> V_99 -> V_8 ,
V_109 -> V_100 ,
( unsigned long long ) F_1 ( V_109 -> V_99 , V_109 -> V_100 ) ,
V_109 -> V_98 ) ;
F_40 ( V_10 , V_108 , V_56 , V_57 , V_58 ,
V_109 -> V_99 ,
V_109 -> V_100 ,
( T_2 ) V_109 -> V_98 ) ;
V_61 -> V_64 |= V_66 ;
}
static void F_41 ( struct V_9 * V_10 ,
struct V_60 * V_61 )
{
V_61 -> V_64 &= ~ V_65 ;
if ( F_42 ( & V_61 -> V_110 ) )
V_61 -> V_111 -- ;
}
static void F_43 ( struct V_9 * V_10 ,
struct V_77 * V_78 , int V_112 )
{
struct V_113 * V_114 ;
struct V_74 * V_74 ;
struct V_115 * V_115 ;
V_74 = V_78 -> V_74 ;
V_115 = V_74 -> V_116 ;
V_115 -> V_117 ++ ;
V_114 = F_44 ( V_74 -> V_75 -> V_118 ) ;
if ( V_115 -> V_117 == V_115 -> V_119 ) {
if ( F_45 ( V_74 -> V_120 ) == V_121 ) {
F_46 ( V_10 ) -> V_122 . V_123 -- ;
if ( F_46 ( V_10 ) -> V_122 . V_123 == 0 ) {
if ( V_10 -> V_35 & V_124 )
F_47 () ;
}
}
F_48 ( V_114 , V_74 ) ;
F_49 ( & V_10 -> V_125 ) ;
F_50 ( V_114 , V_74 , V_112 ) ;
F_51 ( V_10 , V_115 ) ;
F_52 ( & V_10 -> V_125 ) ;
}
}
static void F_53 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , struct V_126 * V_127 )
{
unsigned int V_57 ;
struct V_11 * V_82 ;
struct V_60 * V_61 ;
struct V_128 * V_129 ;
struct V_77 * V_78 = NULL ;
struct V_77 * V_130 ;
struct V_79 V_109 ;
if ( F_54 ( F_55 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ) ) {
if ( ! V_10 -> V_62 [ V_56 ] )
F_30 ( V_10 , L_23
L_24 ,
V_56 ) ;
return;
}
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_57 = F_56 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( F_28 ( & V_61 -> V_131 ) ) {
F_41 ( V_10 , V_61 ) ;
V_61 -> V_132 = NULL ;
F_27 ( V_10 , V_56 , V_57 ) ;
return;
}
F_57 (entry, &ep->cancelled_td_list) {
V_78 = F_58 ( V_129 , struct V_77 , V_131 ) ;
F_34 ( V_10 , V_89 ,
L_25 ,
( unsigned long long ) F_1 (
V_78 -> V_104 , V_78 -> V_105 ) ) ;
V_82 = F_31 ( V_10 , V_78 -> V_74 ) ;
if ( ! V_82 ) {
F_30 ( V_10 , L_26
L_27 ,
V_78 -> V_74 ,
V_78 -> V_74 -> V_58 ) ;
goto V_133;
}
if ( V_78 == V_61 -> V_132 )
F_33 ( V_10 , V_56 , V_57 ,
V_78 -> V_74 -> V_58 ,
V_78 , & V_109 ) ;
else
F_37 ( V_10 , V_82 , V_78 , false ) ;
V_133:
F_59 ( & V_78 -> V_69 ) ;
}
V_130 = V_78 ;
F_41 ( V_10 , V_61 ) ;
if ( V_109 . V_100 && V_109 . V_99 ) {
struct V_107 * V_134 ;
V_134 = F_60 ( V_10 , false , false , V_135 ) ;
F_39 ( V_10 , V_134 ,
V_56 , V_57 ,
V_61 -> V_132 -> V_74 -> V_58 ,
& V_109 ) ;
F_14 ( V_10 ) ;
} else {
F_27 ( V_10 , V_56 , V_57 ) ;
}
if ( ! ( V_61 -> V_64 & V_67 ) )
V_61 -> V_132 = NULL ;
do {
V_78 = F_58 ( V_61 -> V_131 . V_14 ,
struct V_77 , V_131 ) ;
F_59 ( & V_78 -> V_131 ) ;
F_43 ( V_10 , V_78 , 0 ) ;
if ( V_10 -> V_53 & V_54 )
return;
} while ( V_78 != V_130 );
}
static void F_61 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_77 * V_78 ;
while ( ! F_28 ( & V_12 -> V_69 ) ) {
V_78 = F_62 ( & V_12 -> V_69 ,
struct V_77 , V_69 ) ;
F_59 ( & V_78 -> V_69 ) ;
if ( ! F_28 ( & V_78 -> V_131 ) )
F_59 ( & V_78 -> V_131 ) ;
F_43 ( V_10 , V_78 , - V_55 ) ;
}
}
static void F_63 ( struct V_9 * V_10 ,
int V_56 , int V_57 )
{
struct V_77 * V_78 ;
struct V_60 * V_61 ;
struct V_11 * V_12 ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ( V_61 -> V_64 & V_68 ) ||
( V_61 -> V_64 & V_136 ) ) {
int V_58 ;
for ( V_58 = 0 ; V_58 < V_61 -> V_70 -> V_71 ;
V_58 ++ ) {
F_34 ( V_10 , V_89 ,
L_28 ,
V_56 , V_57 , V_58 + 1 ) ;
F_61 ( V_10 ,
V_61 -> V_70 -> V_73 [ V_58 ] ) ;
}
} else {
V_12 = V_61 -> V_12 ;
if ( ! V_12 )
return;
F_34 ( V_10 , V_89 ,
L_29 ,
V_56 , V_57 ) ;
F_61 ( V_10 , V_12 ) ;
}
while ( ! F_28 ( & V_61 -> V_131 ) ) {
V_78 = F_62 ( & V_61 -> V_131 ,
struct V_77 , V_131 ) ;
F_59 ( & V_78 -> V_131 ) ;
F_43 ( V_10 , V_78 , - V_55 ) ;
}
}
void F_64 ( unsigned long V_137 )
{
struct V_9 * V_10 ;
struct V_60 * V_61 ;
int V_47 , V_138 , V_139 ;
unsigned long V_140 ;
V_61 = (struct V_60 * ) V_137 ;
V_10 = V_61 -> V_10 ;
F_65 ( & V_10 -> V_125 , V_140 ) ;
V_61 -> V_111 -- ;
if ( V_10 -> V_53 & V_54 ) {
F_34 ( V_10 , V_89 ,
L_30
L_31 ) ;
F_66 ( & V_10 -> V_125 , V_140 ) ;
return;
}
if ( ! ( V_61 -> V_111 == 0 && ( V_61 -> V_64 & V_65 ) ) ) {
F_34 ( V_10 , V_89 ,
L_32
L_33 ) ;
F_66 ( & V_10 -> V_125 , V_140 ) ;
return;
}
F_30 ( V_10 , L_34 ) ;
F_30 ( V_10 , L_35 ) ;
V_10 -> V_53 |= V_54 ;
F_23 ( V_10 ) ;
F_66 ( & V_10 -> V_125 , V_140 ) ;
V_47 = F_24 ( V_10 ) ;
F_65 ( & V_10 -> V_125 , V_140 ) ;
if ( V_47 < 0 ) {
F_30 ( V_10 , L_36 ) ;
F_30 ( V_10 , L_37 ) ;
}
for ( V_138 = 0 ; V_138 < V_141 ; V_138 ++ ) {
if ( ! V_10 -> V_62 [ V_138 ] )
continue;
for ( V_139 = 0 ; V_139 < 31 ; V_139 ++ )
F_63 ( V_10 , V_138 , V_139 ) ;
}
F_66 ( & V_10 -> V_125 , V_140 ) ;
F_34 ( V_10 , V_89 ,
L_38 ) ;
F_67 ( F_46 ( V_10 ) -> V_142 ) ;
F_34 ( V_10 , V_89 ,
L_39 ) ;
}
static void F_68 ( struct V_9 * V_10 ,
struct V_81 * V_75 ,
struct V_11 * V_82 ,
unsigned int V_57 )
{
union V_3 * V_143 ;
int V_144 ;
bool V_145 = false ;
V_144 = V_82 -> V_25 ;
V_143 = V_82 -> V_24 ;
if ( F_4 ( V_10 , V_82 , V_82 -> V_23 , V_82 -> V_24 ) ) {
V_82 -> V_23 = V_82 -> V_23 -> V_14 ;
V_82 -> V_24 = V_82 -> V_23 -> V_6 ;
}
while ( V_82 -> V_24 != V_75 -> V_63 [ V_57 ] . V_146 ) {
V_82 -> V_25 ++ ;
V_82 -> V_24 ++ ;
if ( F_4 ( V_10 , V_82 , V_82 -> V_23 ,
V_82 -> V_24 ) ) {
if ( V_82 -> V_24 ==
V_75 -> V_63 [ V_57 ] . V_146 )
break;
V_82 -> V_23 = V_82 -> V_23 -> V_14 ;
V_82 -> V_24 = V_82 -> V_23 -> V_6 ;
}
if ( V_82 -> V_24 == V_143 ) {
V_145 = true ;
break;
}
}
if ( V_145 ) {
F_15 ( V_10 , L_40 ) ;
V_82 -> V_25 = V_144 ;
}
}
static void F_69 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , T_2 V_147 )
{
unsigned int V_57 ;
unsigned int V_58 ;
struct V_11 * V_82 ;
struct V_81 * V_75 ;
struct V_60 * V_61 ;
struct V_94 * V_95 ;
struct V_148 * V_149 ;
V_57 = F_56 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_58 = F_70 ( F_3 ( V_4 -> V_29 . V_30 [ 2 ] ) ) ;
V_75 = V_10 -> V_62 [ V_56 ] ;
V_61 = & V_75 -> V_63 [ V_57 ] ;
V_82 = F_71 ( V_75 , V_57 , V_58 ) ;
if ( ! V_82 ) {
F_30 ( V_10 , L_41 ,
V_58 ) ;
V_75 -> V_63 [ V_57 ] . V_64 &= ~ V_66 ;
return;
}
V_95 = F_36 ( V_10 , V_75 -> V_96 , V_57 ) ;
V_149 = F_72 ( V_10 , V_75 -> V_96 ) ;
if ( V_147 != V_150 ) {
unsigned int V_64 ;
unsigned int V_151 ;
switch ( V_147 ) {
case V_152 :
F_30 ( V_10 , L_42 ) ;
break;
case V_153 :
F_30 ( V_10 , L_43 ) ;
V_64 = F_3 ( V_95 -> V_154 ) ;
V_64 &= V_155 ;
V_151 = F_3 ( V_149 -> V_156 ) ;
V_151 = F_73 ( V_151 ) ;
F_34 ( V_10 , V_89 ,
L_44 ,
V_151 , V_64 ) ;
break;
case V_157 :
F_30 ( V_10 , L_45 ,
V_56 ) ;
break;
default:
F_30 ( V_10 , L_46 ,
V_147 ) ;
break;
}
} else {
T_3 V_97 ;
if ( V_61 -> V_64 & V_68 ) {
struct V_90 * V_91 =
& V_61 -> V_70 -> V_92 [ V_58 ] ;
V_97 = F_35 ( V_91 -> V_93 ) & V_158 ;
} else {
V_97 = F_35 ( V_95 -> V_97 ) & ~ V_159 ;
}
F_34 ( V_10 , V_89 ,
L_47 , V_97 ) ;
if ( F_1 ( V_61 -> V_160 ,
V_61 -> V_146 ) == V_97 ) {
F_68 ( V_10 , V_75 ,
V_82 , V_57 ) ;
} else {
F_30 ( V_10 , L_48 ) ;
F_30 ( V_10 , L_49 ,
V_61 -> V_160 , V_61 -> V_146 ) ;
}
}
V_75 -> V_63 [ V_57 ] . V_64 &= ~ V_66 ;
V_75 -> V_63 [ V_57 ] . V_160 = NULL ;
V_75 -> V_63 [ V_57 ] . V_146 = NULL ;
F_27 ( V_10 , V_56 , V_57 ) ;
}
static void F_74 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , T_2 V_147 )
{
unsigned int V_57 ;
V_57 = F_56 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
F_34 ( V_10 , V_161 ,
L_50 , V_147 ) ;
if ( V_10 -> V_35 & V_162 ) {
struct V_107 * V_134 ;
V_134 = F_60 ( V_10 , false , false , V_135 ) ;
if ( ! V_134 ) {
F_30 ( V_10 , L_51 ) ;
return;
}
F_34 ( V_10 , V_163 ,
L_52 ) ;
F_75 ( V_10 , V_134 ,
V_10 -> V_62 [ V_56 ] -> V_164 -> V_8 , V_56 ,
false ) ;
F_14 ( V_10 ) ;
} else {
V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] . V_64 &= ~ V_67 ;
F_27 ( V_10 , V_56 , V_57 ) ;
}
}
static void F_76 ( struct V_9 * V_10 , int V_56 ,
T_2 V_147 )
{
if ( V_147 == V_150 )
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
struct V_126 * V_127 , T_2 V_147 )
{
struct V_81 * V_165 ;
struct V_167 * V_168 ;
unsigned int V_57 ;
unsigned int V_64 ;
T_2 V_169 , V_170 ;
V_165 = V_10 -> V_62 [ V_56 ] ;
V_168 = F_81 ( V_10 , V_165 -> V_164 ) ;
if ( ! V_168 ) {
F_30 ( V_10 , L_53 ) ;
return;
}
V_169 = F_3 ( V_168 -> V_169 ) ;
V_170 = F_3 ( V_168 -> V_170 ) ;
V_57 = F_82 ( V_169 ) - 1 ;
if ( V_10 -> V_35 & V_162 &&
V_57 != ( unsigned int ) - 1 &&
V_169 - V_171 == V_170 ) {
V_64 = V_165 -> V_63 [ V_57 ] . V_64 ;
if ( ! ( V_64 & V_67 ) )
return;
F_34 ( V_10 , V_163 ,
L_54
L_55 ,
V_57 , V_64 ) ;
V_165 -> V_63 [ V_57 ] . V_64 &= ~ V_67 ;
F_27 ( V_10 , V_56 , V_57 ) ;
return;
}
return;
}
static void F_83 ( struct V_9 * V_10 , int V_56 ,
struct V_126 * V_127 )
{
F_15 ( V_10 , L_56 ) ;
if ( ! V_10 -> V_62 [ V_56 ] )
F_30 ( V_10 , L_57
L_58 , V_56 ) ;
}
static void F_84 ( struct V_9 * V_10 ,
struct V_126 * V_127 )
{
if ( ! ( V_10 -> V_35 & V_172 ) ) {
V_10 -> V_173 |= 1 << 6 ;
return;
}
F_34 ( V_10 , V_163 ,
L_59 ,
F_85 ( F_3 ( V_127 -> V_112 ) ) ,
F_86 ( F_3 ( V_127 -> V_112 ) ) ) ;
}
static void F_87 ( struct V_107 * V_108 , T_2 V_112 )
{
F_88 ( & V_108 -> V_174 ) ;
if ( V_108 -> V_175 ) {
V_108 -> V_112 = V_112 ;
F_89 ( V_108 -> V_175 ) ;
} else {
F_90 ( V_108 ) ;
}
}
void F_91 ( struct V_9 * V_10 )
{
struct V_107 * V_176 , * V_177 ;
F_92 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_87 ( V_176 , V_178 ) ;
}
static void F_93 ( struct V_9 * V_10 ,
struct V_107 * V_176 )
{
struct V_107 * V_179 , * V_177 ;
T_2 V_26 ;
F_92 (i_cmd, tmp_cmd, &xhci->cmd_list,
cmd_list) {
if ( V_179 -> V_112 != V_178 )
continue;
V_179 -> V_112 = V_180 ;
F_15 ( V_10 , L_60 ,
V_179 -> V_181 ) ;
V_26 = F_3 (
V_179 -> V_181 -> V_29 . V_30 [ 3 ] ) & V_37 ;
V_179 -> V_181 -> V_29 . V_30 [ 0 ] = 0 ;
V_179 -> V_181 -> V_29 . V_30 [ 1 ] = 0 ;
V_179 -> V_181 -> V_29 . V_30 [ 2 ] = 0 ;
V_179 -> V_181 -> V_29 . V_30 [ 3 ] = F_11 (
F_38 ( V_182 ) | V_26 ) ;
}
V_10 -> V_41 = V_42 ;
if ( ( V_10 -> V_49 -> V_24 != V_10 -> V_49 -> V_20 ) &&
! ( V_10 -> V_53 & V_54 ) ) {
V_10 -> V_183 = V_176 ;
F_94 ( & V_10 -> V_184 , V_185 + V_186 ) ;
F_14 ( V_10 ) ;
}
return;
}
void F_95 ( unsigned long V_187 )
{
struct V_9 * V_10 ;
int V_47 ;
unsigned long V_140 ;
T_3 V_188 ;
struct V_107 * V_176 = NULL ;
V_10 = (struct V_9 * ) V_187 ;
F_65 ( & V_10 -> V_125 , V_140 ) ;
if ( V_10 -> V_183 ) {
V_176 = V_10 -> V_183 ;
V_176 -> V_112 = V_178 ;
}
V_188 = F_19 ( V_10 , & V_10 -> V_48 -> V_49 ) ;
if ( ( V_10 -> V_41 & V_42 ) &&
( V_188 & V_52 ) ) {
F_66 ( & V_10 -> V_125 , V_140 ) ;
F_15 ( V_10 , L_61 ) ;
V_47 = F_18 ( V_10 ) ;
if ( F_54 ( V_47 == - V_55 ) ) {
F_22 ( V_10 , L_62 ) ;
F_91 ( V_10 ) ;
F_67 ( F_46 ( V_10 ) -> V_142 ) ;
F_15 ( V_10 , L_63 ) ;
}
return;
}
F_15 ( V_10 , L_64 ) ;
F_93 ( V_10 , V_10 -> V_183 ) ;
F_66 ( & V_10 -> V_125 , V_140 ) ;
return;
}
static void F_96 ( struct V_9 * V_10 ,
struct V_126 * V_127 )
{
int V_56 = F_97 ( F_3 ( V_127 -> V_140 ) ) ;
T_3 V_189 ;
T_1 V_190 ;
T_2 V_147 ;
union V_3 * V_191 ;
struct V_107 * V_108 ;
T_2 V_192 ;
V_189 = F_35 ( V_127 -> V_191 ) ;
V_191 = V_10 -> V_49 -> V_24 ;
V_190 = F_1 ( V_10 -> V_49 -> V_23 ,
V_191 ) ;
if ( V_190 == 0 ) {
V_10 -> V_173 |= 1 << 4 ;
return;
}
if ( V_189 != ( T_3 ) V_190 ) {
V_10 -> V_173 |= 1 << 5 ;
return;
}
V_108 = F_58 ( V_10 -> V_174 . V_14 , struct V_107 , V_174 ) ;
if ( V_108 -> V_181 != V_10 -> V_49 -> V_24 ) {
F_22 ( V_10 ,
L_65 ) ;
return;
}
F_42 ( & V_10 -> V_184 ) ;
F_98 ( V_191 , (struct V_193 * ) V_127 ) ;
V_147 = F_99 ( F_3 ( V_127 -> V_112 ) ) ;
if ( V_147 == V_180 ) {
F_93 ( V_10 , V_108 ) ;
return;
}
if ( V_147 == V_178 ) {
V_10 -> V_41 = V_194 ;
if ( V_108 -> V_112 == V_178 )
goto V_195;
}
V_192 = F_100 ( F_3 ( V_191 -> V_29 . V_30 [ 3 ] ) ) ;
switch ( V_192 ) {
case V_196 :
F_76 ( V_10 , V_56 , V_147 ) ;
break;
case V_197 :
F_77 ( V_10 , V_56 ) ;
break;
case V_198 :
if ( ! V_108 -> V_175 )
F_80 ( V_10 , V_56 , V_127 ,
V_147 ) ;
break;
case V_199 :
break;
case V_200 :
break;
case V_201 :
F_101 ( V_56 != F_97 (
F_3 ( V_191 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_53 ( V_10 , V_56 , V_191 , V_127 ) ;
break;
case V_202 :
F_101 ( V_56 != F_97 (
F_3 ( V_191 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_69 ( V_10 , V_56 , V_191 , V_147 ) ;
break;
case V_182 :
if ( V_108 -> V_112 == V_180 )
V_147 = V_180 ;
break;
case V_203 :
F_101 ( V_56 != F_97 (
F_3 ( V_191 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_74 ( V_10 , V_56 , V_191 , V_147 ) ;
break;
case V_204 :
V_56 = F_97 (
F_3 ( V_191 -> V_29 . V_30 [ 3 ] ) ) ;
F_83 ( V_10 , V_56 , V_127 ) ;
break;
case V_205 :
F_84 ( V_10 , V_127 ) ;
break;
default:
V_10 -> V_173 |= 1 << 6 ;
break;
}
if ( V_108 -> V_174 . V_14 != & V_10 -> V_174 ) {
V_10 -> V_183 = F_58 ( V_108 -> V_174 . V_14 ,
struct V_107 , V_174 ) ;
F_94 ( & V_10 -> V_184 , V_185 + V_186 ) ;
}
V_195:
F_87 ( V_108 , V_147 ) ;
F_8 ( V_10 , V_10 -> V_49 ) ;
}
static void F_102 ( struct V_9 * V_10 ,
union V_3 * V_127 )
{
T_2 V_206 ;
V_206 = F_100 ( F_3 ( V_127 -> V_29 . V_30 [ 3 ] ) ) ;
F_15 ( V_10 , L_66 , V_206 ) ;
if ( V_206 == V_207 && ( V_10 -> V_35 & V_172 ) )
F_96 ( V_10 , & V_127 -> V_208 ) ;
}
static unsigned int F_103 ( struct V_113 * V_114 ,
struct V_9 * V_10 , T_2 V_209 )
{
unsigned int V_138 ;
unsigned int V_210 = 0 ;
for ( V_138 = 0 ; V_138 < ( V_209 - 1 ) ; V_138 ++ ) {
T_6 V_211 = V_10 -> V_212 [ V_138 ] ;
if ( V_211 == 0 || V_211 == V_213 )
continue;
if ( ( V_211 == 0x03 ) == ( V_114 -> V_214 == V_215 ) )
V_210 ++ ;
}
return V_210 ;
}
static void F_104 ( struct V_9 * V_10 ,
union V_3 * V_127 )
{
T_2 V_56 ;
struct V_216 * V_217 ;
V_56 = F_97 ( F_3 ( V_127 -> V_29 . V_30 [ 3 ] ) ) ;
if ( ! V_10 -> V_62 [ V_56 ] ) {
F_30 ( V_10 , L_67
L_68 , V_56 ) ;
return;
}
F_15 ( V_10 , L_69 ,
V_56 ) ;
V_217 = V_10 -> V_62 [ V_56 ] -> V_217 ;
if ( V_217 && V_217 -> V_218 )
F_105 ( V_217 -> V_218 , V_217 -> V_219 ) ;
}
static void F_106 ( struct V_9 * V_10 ,
union V_3 * V_127 )
{
struct V_113 * V_114 ;
T_2 V_209 ;
T_2 V_220 , V_221 ;
int V_222 ;
int V_56 ;
unsigned int V_223 ;
T_6 V_224 ;
struct V_225 * V_226 ;
T_4 T_5 * * V_212 ;
bool V_227 = false ;
if ( F_99 ( F_3 ( V_127 -> V_29 . V_30 [ 2 ] ) ) != V_150 ) {
F_30 ( V_10 , L_70 ) ;
V_10 -> V_173 |= 1 << 8 ;
}
V_209 = F_107 ( F_3 ( V_127 -> V_29 . V_30 [ 0 ] ) ) ;
F_15 ( V_10 , L_71 , V_209 ) ;
V_222 = F_108 ( V_10 -> V_228 ) ;
if ( ( V_209 <= 0 ) || ( V_209 > V_222 ) ) {
F_30 ( V_10 , L_72 , V_209 ) ;
F_8 ( V_10 , V_10 -> V_13 ) ;
return;
}
V_224 = V_10 -> V_212 [ V_209 - 1 ] ;
V_114 = F_46 ( V_10 ) ;
if ( ( V_224 == 0x03 ) != ( V_114 -> V_214 == V_215 ) )
V_114 = V_10 -> V_229 ;
if ( V_224 == 0 ) {
F_30 ( V_10 , L_73
L_74 ,
V_209 ) ;
V_227 = true ;
goto V_230;
}
if ( V_224 == V_213 ) {
F_30 ( V_10 , L_75
L_74 ,
V_209 ) ;
V_227 = true ;
goto V_230;
}
V_226 = & V_10 -> V_226 [ F_109 ( V_114 ) ] ;
if ( V_114 -> V_214 == V_215 )
V_212 = V_10 -> V_231 ;
else
V_212 = V_10 -> V_232 ;
V_223 = F_103 ( V_114 , V_10 ,
V_209 ) ;
V_220 = F_17 ( V_212 [ V_223 ] ) ;
if ( V_114 -> V_80 == V_233 ) {
F_15 ( V_10 , L_76 ) ;
F_110 ( V_114 ) ;
}
if ( ( V_220 & V_234 ) && ( V_220 & V_235 ) == V_236 ) {
F_15 ( V_10 , L_77 , V_209 ) ;
V_221 = F_17 ( & V_10 -> V_48 -> V_134 ) ;
if ( ! ( V_221 & V_237 ) ) {
F_30 ( V_10 , L_78 ) ;
goto V_230;
}
if ( F_111 ( V_220 ) ) {
F_15 ( V_10 , L_79 , V_209 ) ;
V_226 -> V_238 |= 1 << V_223 ;
F_112 ( V_10 , V_212 ,
V_223 , V_234 ) ;
F_113 ( V_10 , V_212 , V_223 ,
V_239 ) ;
V_227 = true ;
goto V_230;
} else {
F_15 ( V_10 , L_80 , V_209 ) ;
V_226 -> V_240 [ V_223 ] = V_185 +
F_114 ( 20 ) ;
F_115 ( V_223 , & V_226 -> V_241 ) ;
F_94 ( & V_114 -> V_242 ,
V_226 -> V_240 [ V_223 ] ) ;
}
}
if ( ( V_220 & V_234 ) && ( V_220 & V_235 ) == V_239 &&
F_111 ( V_220 ) ) {
F_15 ( V_10 , L_81 , V_209 ) ;
V_56 = F_116 ( V_114 , V_10 ,
V_223 + 1 ) ;
if ( V_56 && V_10 -> V_62 [ V_56 ] )
F_117 ( V_10 , V_56 ) ;
if ( V_226 -> V_238 & ( 1 << V_223 ) ) {
V_226 -> V_238 &=
~ ( 1 << V_223 ) ;
F_112 ( V_10 , V_212 ,
V_223 , V_234 ) ;
F_105 ( V_114 -> V_122 . V_243 ,
V_223 + 1 ) ;
V_227 = true ;
goto V_230;
}
}
if ( ! F_111 ( V_220 ) &&
F_118 ( V_223 ,
& V_226 -> V_244 ) ) {
F_89 ( & V_226 -> V_245 [ V_223 ] ) ;
V_227 = true ;
goto V_230;
}
if ( V_114 -> V_214 != V_215 )
F_112 ( V_10 , V_212 , V_223 ,
V_234 ) ;
V_230:
F_8 ( V_10 , V_10 -> V_13 ) ;
if ( V_227 )
return;
F_15 ( V_10 , L_82 , V_246 ) ;
F_115 ( V_247 , & V_114 -> V_140 ) ;
F_49 ( & V_10 -> V_125 ) ;
F_119 ( V_114 ) ;
F_52 ( & V_10 -> V_125 ) ;
}
struct V_1 * F_120 ( struct V_1 * V_104 ,
union V_3 * V_248 ,
union V_3 * V_249 ,
T_1 V_250 )
{
T_1 V_251 ;
T_1 V_252 ;
T_1 V_253 ;
struct V_1 * V_102 ;
V_251 = F_1 ( V_104 , V_248 ) ;
V_102 = V_104 ;
do {
if ( V_251 == 0 )
return NULL ;
V_252 = F_1 ( V_102 ,
& V_102 -> V_6 [ V_7 - 1 ] ) ;
V_253 = F_1 ( V_102 , V_249 ) ;
if ( V_253 > 0 ) {
if ( V_251 <= V_253 ) {
if ( V_250 >= V_251 && V_250 <= V_253 )
return V_102 ;
} else {
if ( ( V_250 >= V_251 &&
V_250 <= V_252 ) ||
( V_250 >= V_102 -> V_8 &&
V_250 <= V_253 ) )
return V_102 ;
}
return NULL ;
} else {
if ( V_250 >= V_251 && V_250 <= V_252 )
return V_102 ;
}
V_102 = V_102 -> V_14 ;
V_251 = F_1 ( V_102 , & V_102 -> V_6 [ 0 ] ) ;
} while ( V_102 != V_104 );
return NULL ;
}
static void F_121 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 ,
struct V_77 * V_254 , union V_3 * V_255 )
{
struct V_60 * V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
struct V_107 * V_134 ;
V_134 = F_60 ( V_10 , false , false , V_135 ) ;
if ( ! V_134 )
return;
V_61 -> V_64 |= V_67 ;
V_61 -> V_132 = V_254 ;
V_61 -> V_256 = V_58 ;
F_122 ( V_10 , V_134 , V_56 , V_57 ) ;
F_123 ( V_10 , V_254 -> V_74 -> V_75 , V_57 ) ;
V_61 -> V_132 = NULL ;
V_61 -> V_256 = 0 ;
F_14 ( V_10 ) ;
}
static int F_124 ( struct V_9 * V_10 ,
struct V_94 * V_95 ,
unsigned int V_257 )
{
if ( V_257 == V_258 ||
V_257 == V_259 ||
V_257 == V_260 )
if ( ( V_95 -> V_154 & F_11 ( V_155 ) ) ==
F_11 ( V_261 ) )
return 1 ;
return 0 ;
}
int F_125 ( struct V_9 * V_10 , unsigned int V_257 )
{
if ( V_257 >= 224 && V_257 <= 255 ) {
F_15 ( V_10 , L_83 ,
V_257 ) ;
F_15 ( V_10 , L_84 ) ;
return 1 ;
}
return 0 ;
}
static int F_126 ( struct V_9 * V_10 , struct V_77 * V_254 ,
union V_3 * V_255 , struct V_262 * V_127 ,
struct V_60 * V_61 , int * V_112 , bool V_263 )
{
struct V_81 * V_264 ;
struct V_11 * V_82 ;
unsigned int V_56 ;
int V_57 ;
struct V_74 * V_74 = NULL ;
struct V_94 * V_95 ;
int V_47 = 0 ;
struct V_115 * V_115 ;
T_2 V_257 ;
V_56 = F_97 ( F_3 ( V_127 -> V_140 ) ) ;
V_264 = V_10 -> V_62 [ V_56 ] ;
V_57 = F_127 ( F_3 ( V_127 -> V_140 ) ) - 1 ;
V_82 = F_128 ( V_61 , F_35 ( V_127 -> V_265 ) ) ;
V_95 = F_36 ( V_10 , V_264 -> V_96 , V_57 ) ;
V_257 = F_99 ( F_3 ( V_127 -> V_266 ) ) ;
if ( V_263 )
goto V_267;
if ( V_257 == V_268 ||
V_257 == V_269 ) {
V_61 -> V_132 = V_254 ;
return 0 ;
} else {
if ( V_257 == V_270 ) {
V_61 -> V_132 = V_254 ;
V_61 -> V_256 = V_82 -> V_58 ;
} else if ( F_124 ( V_10 ,
V_95 , V_257 ) ) {
F_121 ( V_10 ,
V_56 , V_57 , V_82 -> V_58 ,
V_254 , V_255 ) ;
} else {
while ( V_82 -> V_24 != V_254 -> F_4 )
F_8 ( V_10 , V_82 ) ;
F_8 ( V_10 , V_82 ) ;
}
V_267:
V_74 = V_254 -> V_74 ;
V_115 = V_74 -> V_116 ;
if ( V_74 -> V_271 > V_74 -> V_272 ) {
F_30 ( V_10 , L_85
L_86
L_87 ,
V_74 -> V_272 ,
V_74 -> V_271 ) ;
V_74 -> V_271 = 0 ;
if ( V_254 -> V_74 -> V_273 & V_274 )
* V_112 = - V_275 ;
else
* V_112 = 0 ;
}
F_59 ( & V_254 -> V_69 ) ;
if ( ! F_28 ( & V_254 -> V_131 ) )
F_59 ( & V_254 -> V_131 ) ;
V_115 -> V_117 ++ ;
if ( V_115 -> V_117 == V_115 -> V_119 ) {
V_47 = 1 ;
if ( F_45 ( V_74 -> V_120 ) == V_121 ) {
F_46 ( V_10 ) -> V_122 . V_123 -- ;
if ( F_46 ( V_10 ) -> V_122 . V_123
== 0 ) {
if ( V_10 -> V_35 & V_124 )
F_47 () ;
}
}
}
}
return V_47 ;
}
static int F_129 ( struct V_9 * V_10 , struct V_77 * V_254 ,
union V_3 * V_255 , struct V_262 * V_127 ,
struct V_60 * V_61 , int * V_112 )
{
struct V_81 * V_264 ;
struct V_11 * V_82 ;
unsigned int V_56 ;
int V_57 ;
struct V_94 * V_95 ;
T_2 V_257 ;
V_56 = F_97 ( F_3 ( V_127 -> V_140 ) ) ;
V_264 = V_10 -> V_62 [ V_56 ] ;
V_57 = F_127 ( F_3 ( V_127 -> V_140 ) ) - 1 ;
V_82 = F_128 ( V_61 , F_35 ( V_127 -> V_265 ) ) ;
V_95 = F_36 ( V_10 , V_264 -> V_96 , V_57 ) ;
V_257 = F_99 ( F_3 ( V_127 -> V_266 ) ) ;
switch ( V_257 ) {
case V_150 :
if ( V_255 == V_82 -> V_24 ) {
F_30 ( V_10 , L_88
L_89 ) ;
* V_112 = - V_55 ;
} else if ( V_255 != V_254 -> F_4 ) {
F_30 ( V_10 , L_90
L_89 ) ;
* V_112 = - V_55 ;
} else {
* V_112 = 0 ;
}
break;
case V_276 :
if ( V_254 -> V_74 -> V_273 & V_274 )
* V_112 = - V_275 ;
else
* V_112 = 0 ;
break;
case V_268 :
case V_269 :
return F_126 ( V_10 , V_254 , V_255 , V_127 , V_61 , V_112 , false ) ;
default:
if ( ! F_124 ( V_10 ,
V_95 , V_257 ) )
break;
F_15 ( V_10 , L_91
L_92 ,
V_257 , V_57 ) ;
case V_270 :
if ( V_255 != V_82 -> V_24 &&
V_255 != V_254 -> F_4 )
V_254 -> V_74 -> V_271 =
V_254 -> V_74 -> V_272 -
F_130 ( F_3 ( V_127 -> V_266 ) ) ;
else
V_254 -> V_74 -> V_271 = 0 ;
F_121 ( V_10 ,
V_56 , V_57 , 0 , V_254 , V_255 ) ;
return F_126 ( V_10 , V_254 , V_255 , V_127 , V_61 , V_112 , true ) ;
}
if ( V_255 != V_82 -> V_24 ) {
if ( V_255 == V_254 -> F_4 ) {
if ( V_254 -> V_74 -> V_271 != 0 ) {
if ( ( * V_112 == - V_277 || * V_112 == 0 ) &&
( V_254 -> V_74 -> V_273
& V_274 ) )
* V_112 = - V_275 ;
} else {
V_254 -> V_74 -> V_271 =
V_254 -> V_74 -> V_272 ;
}
} else {
V_254 -> V_74 -> V_271 =
V_254 -> V_74 -> V_272 -
F_130 ( F_3 ( V_127 -> V_266 ) ) ;
F_15 ( V_10 , L_93
L_94 ) ;
return 0 ;
}
}
return F_126 ( V_10 , V_254 , V_255 , V_127 , V_61 , V_112 , false ) ;
}
static int F_131 ( struct V_9 * V_10 , struct V_77 * V_254 ,
union V_3 * V_255 , struct V_262 * V_127 ,
struct V_60 * V_61 , int * V_112 )
{
struct V_11 * V_82 ;
struct V_115 * V_115 ;
int V_278 ;
int V_279 = 0 ;
union V_3 * V_103 ;
struct V_1 * V_102 ;
struct V_280 * V_281 ;
T_2 V_257 ;
bool V_282 = false ;
V_82 = F_128 ( V_61 , F_35 ( V_127 -> V_265 ) ) ;
V_257 = F_99 ( F_3 ( V_127 -> V_266 ) ) ;
V_115 = V_254 -> V_74 -> V_116 ;
V_278 = V_115 -> V_117 ;
V_281 = & V_254 -> V_74 -> V_283 [ V_278 ] ;
switch ( V_257 ) {
case V_150 :
if ( F_130 ( F_3 ( V_127 -> V_266 ) ) == 0 ) {
V_281 -> V_112 = 0 ;
break;
}
if ( ( V_10 -> V_35 & V_284 ) )
V_257 = V_276 ;
case V_276 :
V_281 -> V_112 = V_254 -> V_74 -> V_273 & V_274 ?
- V_275 : 0 ;
break;
case V_285 :
V_281 -> V_112 = - V_286 ;
V_282 = true ;
break;
case V_287 :
case V_259 :
V_281 -> V_112 = - V_288 ;
V_282 = true ;
break;
case V_289 :
case V_270 :
case V_258 :
V_281 -> V_112 = - V_290 ;
V_282 = true ;
break;
case V_269 :
case V_268 :
break;
default:
V_281 -> V_112 = - 1 ;
break;
}
if ( V_257 == V_150 || V_282 ) {
V_281 -> V_271 = V_281 -> V_119 ;
V_254 -> V_74 -> V_271 += V_281 -> V_119 ;
} else {
for ( V_103 = V_82 -> V_24 ,
V_102 = V_82 -> V_23 ; V_103 != V_255 ;
F_7 ( V_10 , V_82 , & V_102 , & V_103 ) ) {
if ( ! F_132 ( V_103 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_103 -> V_29 . V_30 [ 3 ] ) )
V_279 += F_133 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) ;
}
V_279 += F_133 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) -
F_130 ( F_3 ( V_127 -> V_266 ) ) ;
if ( V_257 != V_268 ) {
V_281 -> V_271 = V_279 ;
V_254 -> V_74 -> V_271 += V_279 ;
}
}
return F_126 ( V_10 , V_254 , V_255 , V_127 , V_61 , V_112 , false ) ;
}
static int F_134 ( struct V_9 * V_10 , struct V_77 * V_254 ,
struct V_262 * V_127 ,
struct V_60 * V_61 , int * V_112 )
{
struct V_11 * V_82 ;
struct V_115 * V_115 ;
struct V_280 * V_281 ;
int V_278 ;
V_82 = F_128 ( V_61 , F_35 ( V_127 -> V_265 ) ) ;
V_115 = V_254 -> V_74 -> V_116 ;
V_278 = V_115 -> V_117 ;
V_281 = & V_254 -> V_74 -> V_283 [ V_278 ] ;
V_281 -> V_112 = - V_291 ;
V_281 -> V_271 = 0 ;
while ( V_82 -> V_24 != V_254 -> F_4 )
F_8 ( V_10 , V_82 ) ;
F_8 ( V_10 , V_82 ) ;
return F_126 ( V_10 , V_254 , NULL , V_127 , V_61 , V_112 , true ) ;
}
static int F_135 ( struct V_9 * V_10 , struct V_77 * V_254 ,
union V_3 * V_255 , struct V_262 * V_127 ,
struct V_60 * V_61 , int * V_112 )
{
struct V_11 * V_82 ;
union V_3 * V_103 ;
struct V_1 * V_102 ;
T_2 V_257 ;
V_82 = F_128 ( V_61 , F_35 ( V_127 -> V_265 ) ) ;
V_257 = F_99 ( F_3 ( V_127 -> V_266 ) ) ;
switch ( V_257 ) {
case V_150 :
if ( V_255 != V_254 -> F_4 ||
F_130 ( F_3 ( V_127 -> V_266 ) ) != 0 ) {
F_30 ( V_10 , L_95
L_96 ) ;
if ( V_254 -> V_74 -> V_273 & V_274 )
* V_112 = - V_275 ;
else
* V_112 = 0 ;
if ( ( V_10 -> V_35 & V_284 ) )
V_257 = V_276 ;
} else {
* V_112 = 0 ;
}
break;
case V_276 :
if ( V_254 -> V_74 -> V_273 & V_274 )
* V_112 = - V_275 ;
else
* V_112 = 0 ;
break;
default:
break;
}
if ( V_257 == V_276 )
F_15 ( V_10 , L_97
L_98 ,
V_254 -> V_74 -> V_61 -> V_76 . V_292 ,
V_254 -> V_74 -> V_272 ,
F_130 ( F_3 ( V_127 -> V_266 ) ) ) ;
if ( V_255 == V_254 -> F_4 ) {
if ( F_130 ( F_3 ( V_127 -> V_266 ) ) != 0 ) {
V_254 -> V_74 -> V_271 =
V_254 -> V_74 -> V_272 -
F_130 ( F_3 ( V_127 -> V_266 ) ) ;
if ( V_254 -> V_74 -> V_272 <
V_254 -> V_74 -> V_271 ) {
F_30 ( V_10 , L_99
L_100 ,
F_130 ( F_3 ( V_127 -> V_266 ) ) ) ;
V_254 -> V_74 -> V_271 = 0 ;
if ( V_254 -> V_74 -> V_273 & V_274 )
* V_112 = - V_275 ;
else
* V_112 = 0 ;
}
if ( * V_112 == - V_277 ) {
if ( V_254 -> V_74 -> V_273 & V_274 )
* V_112 = - V_275 ;
else
* V_112 = 0 ;
}
} else {
V_254 -> V_74 -> V_271 =
V_254 -> V_74 -> V_272 ;
if ( * V_112 == - V_275 )
* V_112 = 0 ;
}
} else {
V_254 -> V_74 -> V_271 = 0 ;
for ( V_103 = V_82 -> V_24 , V_102 = V_82 -> V_23 ;
V_103 != V_255 ;
F_7 ( V_10 , V_82 , & V_102 , & V_103 ) ) {
if ( ! F_132 ( V_103 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_103 -> V_29 . V_30 [ 3 ] ) )
V_254 -> V_74 -> V_271 +=
F_133 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) ;
}
if ( V_257 != V_268 )
V_254 -> V_74 -> V_271 +=
F_133 ( F_3 ( V_103 -> V_29 . V_30 [ 2 ] ) ) -
F_130 ( F_3 ( V_127 -> V_266 ) ) ;
}
return F_126 ( V_10 , V_254 , V_255 , V_127 , V_61 , V_112 , false ) ;
}
static int F_136 ( struct V_9 * V_10 ,
struct V_262 * V_127 )
__releases( &xhci->lock
static int F_137 ( struct V_9 * V_10 )
{
union V_3 * V_127 ;
int V_293 = 1 ;
int V_47 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_24 ) {
V_10 -> V_173 |= 1 << 1 ;
return 0 ;
}
V_127 = V_10 -> V_13 -> V_24 ;
if ( ( F_3 ( V_127 -> V_208 . V_140 ) & V_37 ) !=
V_10 -> V_13 -> V_26 ) {
V_10 -> V_173 |= 1 << 2 ;
return 0 ;
}
F_138 () ;
switch ( ( F_3 ( V_127 -> V_208 . V_140 ) & V_294 ) ) {
case F_38 ( V_295 ) :
F_96 ( V_10 , & V_127 -> V_208 ) ;
break;
case F_38 ( V_296 ) :
F_106 ( V_10 , V_127 ) ;
V_293 = 0 ;
break;
case F_38 ( V_297 ) :
V_47 = F_136 ( V_10 , & V_127 -> V_298 ) ;
if ( V_47 < 0 )
V_10 -> V_173 |= 1 << 9 ;
else
V_293 = 0 ;
break;
case F_38 ( V_299 ) :
F_104 ( V_10 , V_127 ) ;
break;
default:
if ( ( F_3 ( V_127 -> V_208 . V_140 ) & V_294 ) >=
F_38 ( 48 ) )
F_102 ( V_10 , V_127 ) ;
else
V_10 -> V_173 |= 1 << 3 ;
}
if ( V_10 -> V_53 & V_54 ) {
F_15 ( V_10 , L_101
L_102 ) ;
return 0 ;
}
if ( V_293 )
F_8 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_139 ( struct V_113 * V_114 )
{
struct V_9 * V_10 = F_140 ( V_114 ) ;
T_2 V_112 ;
T_3 V_46 ;
union V_3 * V_300 ;
T_1 V_97 ;
F_52 ( & V_10 -> V_125 ) ;
V_112 = F_17 ( & V_10 -> V_48 -> V_112 ) ;
if ( V_112 == 0xffffffff )
goto V_301;
if ( ! ( V_112 & V_302 ) ) {
F_49 ( & V_10 -> V_125 ) ;
return V_303 ;
}
if ( V_112 & V_304 ) {
F_30 ( V_10 , L_103 ) ;
F_24 ( V_10 ) ;
V_301:
F_49 ( & V_10 -> V_125 ) ;
return - V_55 ;
}
V_112 |= V_302 ;
F_16 ( V_112 , & V_10 -> V_48 -> V_112 ) ;
if ( V_114 -> V_305 ) {
T_2 V_306 ;
V_306 = F_17 ( & V_10 -> V_307 -> V_306 ) ;
V_306 |= V_308 ;
F_16 ( V_306 , & V_10 -> V_307 -> V_306 ) ;
}
if ( V_10 -> V_53 & V_54 ) {
F_15 ( V_10 , L_104
L_105 ) ;
V_46 = F_19 ( V_10 , & V_10 -> V_307 -> V_309 ) ;
F_20 ( V_10 , V_46 | V_310 ,
& V_10 -> V_307 -> V_309 ) ;
F_49 ( & V_10 -> V_125 ) ;
return V_311 ;
}
V_300 = V_10 -> V_13 -> V_24 ;
while ( F_137 ( V_10 ) > 0 ) {}
V_46 = F_19 ( V_10 , & V_10 -> V_307 -> V_309 ) ;
if ( V_300 != V_10 -> V_13 -> V_24 ) {
V_97 = F_1 ( V_10 -> V_13 -> V_23 ,
V_10 -> V_13 -> V_24 ) ;
if ( V_97 == 0 )
F_30 ( V_10 , L_106
L_107 ) ;
V_46 &= V_312 ;
V_46 |= ( ( T_3 ) V_97 & ( T_3 ) ~ V_312 ) ;
}
V_46 |= V_310 ;
F_20 ( V_10 , V_46 , & V_10 -> V_307 -> V_309 ) ;
F_49 ( & V_10 -> V_125 ) ;
return V_311 ;
}
T_7 F_141 ( int V_305 , void * V_114 )
{
return F_139 ( V_114 ) ;
}
static void F_142 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_27 ,
T_2 V_313 , T_2 V_314 , T_2 V_315 , T_2 V_316 )
{
struct V_193 * V_4 ;
V_4 = & V_12 -> V_20 -> V_29 ;
V_4 -> V_30 [ 0 ] = F_11 ( V_313 ) ;
V_4 -> V_30 [ 1 ] = F_11 ( V_314 ) ;
V_4 -> V_30 [ 2 ] = F_11 ( V_315 ) ;
V_4 -> V_30 [ 3 ] = F_11 ( V_316 ) ;
F_9 ( V_10 , V_12 , V_27 ) ;
}
static int F_143 ( struct V_9 * V_10 , struct V_11 * V_82 ,
T_2 V_64 , unsigned int V_38 , T_8 V_317 )
{
unsigned int V_318 ;
switch ( V_64 ) {
case V_319 :
F_30 ( V_10 , L_108 ) ;
return - V_320 ;
case V_321 :
F_30 ( V_10 , L_109 ) ;
return - V_322 ;
case V_261 :
F_15 ( V_10 , L_110 ) ;
case V_323 :
case V_324 :
break;
default:
F_22 ( V_10 , L_111 ) ;
return - V_322 ;
}
while ( 1 ) {
if ( F_13 ( V_10 , V_82 , V_38 ) )
break;
if ( V_82 == V_10 -> V_49 ) {
F_22 ( V_10 , L_112 ) ;
return - V_325 ;
}
F_34 ( V_10 , V_326 ,
L_113 ) ;
V_318 = V_38 - V_82 -> V_25 ;
if ( F_144 ( V_10 , V_82 , V_318 ,
V_317 ) ) {
F_22 ( V_10 , L_114 ) ;
return - V_325 ;
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
V_12 -> V_26 = ( V_12 -> V_26 ? 0 : 1 ) ;
}
V_12 -> V_32 = V_12 -> V_32 -> V_14 ;
V_12 -> V_20 = V_12 -> V_32 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
return 0 ;
}
static int F_145 ( struct V_9 * V_10 ,
struct V_81 * V_264 ,
unsigned int V_57 ,
unsigned int V_58 ,
unsigned int V_38 ,
struct V_74 * V_74 ,
unsigned int V_327 ,
T_8 V_317 )
{
int V_47 ;
struct V_115 * V_115 ;
struct V_77 * V_254 ;
struct V_11 * V_82 ;
struct V_94 * V_95 = F_36 ( V_10 , V_264 -> V_96 , V_57 ) ;
V_82 = F_71 ( V_264 , V_57 , V_58 ) ;
if ( ! V_82 ) {
F_15 ( V_10 , L_115 ,
V_58 ) ;
return - V_322 ;
}
V_47 = F_143 ( V_10 , V_82 ,
F_3 ( V_95 -> V_154 ) & V_155 ,
V_38 , V_317 ) ;
if ( V_47 )
return V_47 ;
V_115 = V_74 -> V_116 ;
V_254 = V_115 -> V_254 [ V_327 ] ;
F_146 ( & V_254 -> V_69 ) ;
F_146 ( & V_254 -> V_131 ) ;
if ( V_327 == 0 ) {
V_47 = F_147 ( F_44 ( V_74 -> V_75 -> V_118 ) , V_74 ) ;
if ( F_54 ( V_47 ) )
return V_47 ;
}
V_254 -> V_74 = V_74 ;
F_148 ( & V_254 -> V_69 , & V_82 -> V_69 ) ;
V_254 -> V_104 = V_82 -> V_32 ;
V_254 -> V_105 = V_82 -> V_20 ;
V_115 -> V_254 [ V_327 ] = V_254 ;
return 0 ;
}
static unsigned int F_149 ( struct V_9 * V_10 , struct V_74 * V_74 )
{
int V_328 , V_38 , V_329 , V_220 , V_138 ;
struct V_330 * V_331 ;
V_331 = NULL ;
V_328 = V_74 -> V_332 ;
V_220 = V_74 -> V_272 ;
V_38 = 0 ;
F_150 (urb->sg, sg, num_sgs, i) {
unsigned int V_279 = F_151 ( V_331 ) ;
V_329 = V_333 -
( F_152 ( V_331 ) & ( V_333 - 1 ) ) ;
V_329 &= V_333 - 1 ;
if ( V_329 != 0 )
V_38 ++ ;
while ( V_329 < F_151 ( V_331 ) && V_329 < V_220 ) {
V_38 ++ ;
V_329 += V_333 ;
}
V_279 = F_153 ( int , V_279 , V_220 ) ;
V_220 -= V_279 ;
if ( V_220 == 0 )
break;
}
return V_38 ;
}
static void F_154 ( struct V_74 * V_74 , int V_38 , int V_329 )
{
if ( V_38 != 0 )
F_155 ( & V_74 -> V_75 -> V_75 , L_116
L_117 , V_246 ,
V_74 -> V_61 -> V_76 . V_292 , V_38 ) ;
if ( V_329 != V_74 -> V_272 )
F_155 ( & V_74 -> V_75 -> V_75 , L_118
L_119 ,
V_246 ,
V_74 -> V_61 -> V_76 . V_292 ,
V_329 , V_329 ,
V_74 -> V_272 ,
V_74 -> V_272 ) ;
}
static void F_156 ( struct V_9 * V_10 , int V_56 ,
unsigned int V_57 , unsigned int V_58 , int V_334 ,
struct V_193 * V_248 )
{
F_12 () ;
if ( V_334 )
V_248 -> V_30 [ 3 ] |= F_11 ( V_334 ) ;
else
V_248 -> V_30 [ 3 ] &= F_11 ( ~ V_37 ) ;
F_25 ( V_10 , V_56 , V_57 , V_58 ) ;
}
int F_157 ( struct V_9 * V_10 , T_8 V_317 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_94 * V_95 = F_36 ( V_10 ,
V_10 -> V_62 [ V_56 ] -> V_96 , V_57 ) ;
int V_335 ;
int V_336 ;
V_335 = F_158 ( F_3 ( V_95 -> V_154 ) ) ;
V_336 = V_74 -> V_337 ;
if ( V_74 -> V_75 -> V_214 == V_338 ||
V_74 -> V_75 -> V_214 == V_339 )
V_336 *= 8 ;
if ( V_335 != V_336 ) {
F_159 ( & V_74 -> V_75 -> V_75 ,
L_120 ,
V_336 , V_336 == 1 ? L_121 : L_122 ,
V_335 , V_335 == 1 ? L_121 : L_122 ) ;
V_74 -> V_337 = V_335 ;
if ( V_74 -> V_75 -> V_214 == V_338 ||
V_74 -> V_75 -> V_214 == V_339 )
V_74 -> V_337 /= 8 ;
}
return F_160 ( V_10 , V_317 , V_74 , V_56 , V_57 ) ;
}
static T_2 F_161 ( unsigned int V_340 )
{
T_2 V_341 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_340 >> 10 ) >= V_341 )
return V_341 << 17 ;
else
return ( V_340 >> 10 ) << 17 ;
}
static T_2 F_162 ( int V_329 , int V_342 ,
unsigned int V_343 , struct V_74 * V_74 ,
unsigned int V_344 )
{
int V_345 ;
if ( V_344 == 0 || ( V_329 == 0 && V_342 == 0 ) )
return 0 ;
V_345 = ( V_329 + V_342 ) /
F_163 ( F_164 ( & V_74 -> V_61 -> V_76 ) ) ;
if ( ( V_343 - V_345 ) > 31 )
return 31 << 17 ;
return ( V_343 - V_345 ) << 17 ;
}
static int F_165 ( struct V_9 * V_10 , T_8 V_317 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
unsigned int V_38 ;
struct V_115 * V_115 ;
struct V_77 * V_254 ;
struct V_330 * V_331 ;
int V_328 ;
int V_342 , V_346 , V_329 ;
unsigned int V_343 ;
bool V_105 ;
T_3 V_85 ;
bool V_27 ;
struct V_193 * V_248 ;
int V_334 ;
V_82 = F_31 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_322 ;
V_38 = F_149 ( V_10 , V_74 ) ;
V_328 = V_74 -> V_332 ;
V_343 = F_166 ( V_74 -> V_272 ,
F_164 ( & V_74 -> V_61 -> V_76 ) ) ;
V_342 = F_145 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_317 ) ;
if ( V_342 < 0 )
return V_342 ;
V_115 = V_74 -> V_116 ;
V_254 = V_115 -> V_254 [ 0 ] ;
V_248 = & V_82 -> V_20 -> V_29 ;
V_334 = V_82 -> V_26 ;
V_329 = 0 ;
V_331 = V_74 -> V_331 ;
V_85 = ( T_3 ) F_152 ( V_331 ) ;
V_346 = F_151 ( V_331 ) ;
V_342 = V_333 - ( V_85 & ( V_333 - 1 ) ) ;
V_342 = F_153 ( int , V_342 , V_346 ) ;
if ( V_342 > V_74 -> V_272 )
V_342 = V_74 -> V_272 ;
V_105 = true ;
do {
T_2 V_30 = 0 ;
T_2 V_347 = 0 ;
T_2 V_340 = 0 ;
if ( V_105 ) {
V_105 = false ;
if ( V_334 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_82 -> V_26 ;
if ( V_38 > 1 ) {
V_30 |= V_31 ;
} else {
V_254 -> F_4 = V_82 -> V_20 ;
V_30 |= V_348 ;
}
if ( F_167 ( V_74 ) )
V_30 |= V_349 ;
if ( V_333 -
( V_85 & ( V_333 - 1 ) ) < V_342 ) {
F_30 ( V_10 , L_123 ) ;
F_15 ( V_10 , L_124 ,
( unsigned int ) ( V_85 + V_333 ) & ~ ( V_333 - 1 ) ,
( unsigned int ) V_85 + V_342 ) ;
}
if ( V_10 -> V_350 < 0x100 ) {
V_340 = F_161 (
V_74 -> V_272 -
V_329 ) ;
} else {
V_340 = F_162 ( V_329 ,
V_342 , V_343 , V_74 ,
V_38 - 1 ) ;
}
V_347 = F_133 ( V_342 ) |
V_340 |
F_168 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_142 ( V_10 , V_82 , V_27 ,
F_169 ( V_85 ) ,
F_170 ( V_85 ) ,
V_347 ,
V_30 | F_38 ( V_351 ) ) ;
-- V_38 ;
V_329 += V_342 ;
V_346 -= V_342 ;
if ( V_346 == 0 ) {
-- V_328 ;
if ( V_328 == 0 )
break;
V_331 = F_171 ( V_331 ) ;
V_85 = ( T_3 ) F_152 ( V_331 ) ;
V_346 = F_151 ( V_331 ) ;
} else {
V_85 += V_342 ;
}
V_342 = V_333 -
( V_85 & ( V_333 - 1 ) ) ;
V_342 = F_153 ( int , V_342 , V_346 ) ;
if ( V_329 + V_342 > V_74 -> V_272 )
V_342 =
V_74 -> V_272 - V_329 ;
} while ( V_329 < V_74 -> V_272 );
F_154 ( V_74 , V_38 , V_329 ) ;
F_156 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_334 , V_248 ) ;
return 0 ;
}
int F_160 ( struct V_9 * V_10 , T_8 V_317 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
struct V_115 * V_115 ;
struct V_77 * V_254 ;
int V_38 ;
struct V_193 * V_248 ;
bool V_105 ;
bool V_27 ;
int V_334 ;
T_2 V_30 , V_347 ;
int V_329 , V_342 , V_47 ;
unsigned int V_343 ;
T_3 V_85 ;
if ( V_74 -> V_328 )
return F_165 ( V_10 , V_317 , V_74 , V_56 , V_57 ) ;
V_82 = F_31 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_322 ;
V_38 = 0 ;
V_329 = V_333 -
( V_74 -> V_352 & ( V_333 - 1 ) ) ;
V_329 &= V_333 - 1 ;
if ( V_329 != 0 || V_74 -> V_272 == 0 )
V_38 ++ ;
while ( V_329 < V_74 -> V_272 ) {
V_38 ++ ;
V_329 += V_333 ;
}
V_47 = F_145 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_317 ) ;
if ( V_47 < 0 )
return V_47 ;
V_115 = V_74 -> V_116 ;
V_254 = V_115 -> V_254 [ 0 ] ;
V_248 = & V_82 -> V_20 -> V_29 ;
V_334 = V_82 -> V_26 ;
V_329 = 0 ;
V_343 = F_166 ( V_74 -> V_272 ,
F_164 ( & V_74 -> V_61 -> V_76 ) ) ;
V_85 = ( T_3 ) V_74 -> V_352 ;
V_342 = V_333 -
( V_74 -> V_352 & ( V_333 - 1 ) ) ;
if ( V_342 > V_74 -> V_272 )
V_342 = V_74 -> V_272 ;
V_105 = true ;
do {
T_2 V_340 = 0 ;
V_30 = 0 ;
if ( V_105 ) {
V_105 = false ;
if ( V_334 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_82 -> V_26 ;
if ( V_38 > 1 ) {
V_30 |= V_31 ;
} else {
V_254 -> F_4 = V_82 -> V_20 ;
V_30 |= V_348 ;
}
if ( F_167 ( V_74 ) )
V_30 |= V_349 ;
if ( V_10 -> V_350 < 0x100 ) {
V_340 = F_161 (
V_74 -> V_272 -
V_329 ) ;
} else {
V_340 = F_162 ( V_329 ,
V_342 , V_343 , V_74 ,
V_38 - 1 ) ;
}
V_347 = F_133 ( V_342 ) |
V_340 |
F_168 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_142 ( V_10 , V_82 , V_27 ,
F_169 ( V_85 ) ,
F_170 ( V_85 ) ,
V_347 ,
V_30 | F_38 ( V_351 ) ) ;
-- V_38 ;
V_329 += V_342 ;
V_85 += V_342 ;
V_342 = V_74 -> V_272 - V_329 ;
if ( V_342 > V_333 )
V_342 = V_333 ;
} while ( V_329 < V_74 -> V_272 );
F_154 ( V_74 , V_38 , V_329 ) ;
F_156 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_334 , V_248 ) ;
return 0 ;
}
int F_172 ( struct V_9 * V_10 , T_8 V_317 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
int V_38 ;
int V_47 ;
struct V_353 * V_354 ;
struct V_193 * V_248 ;
int V_334 ;
T_2 V_30 , V_347 ;
struct V_115 * V_115 ;
struct V_77 * V_254 ;
V_82 = F_31 ( V_10 , V_74 ) ;
if ( ! V_82 )
return - V_322 ;
if ( ! V_74 -> V_355 )
return - V_322 ;
V_38 = 2 ;
if ( V_74 -> V_272 > 0 )
V_38 ++ ;
V_47 = F_145 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_74 -> V_58 ,
V_38 , V_74 , 0 , V_317 ) ;
if ( V_47 < 0 )
return V_47 ;
V_115 = V_74 -> V_116 ;
V_254 = V_115 -> V_254 [ 0 ] ;
V_248 = & V_82 -> V_20 -> V_29 ;
V_334 = V_82 -> V_26 ;
V_354 = (struct V_353 * ) V_74 -> V_355 ;
V_30 = 0 ;
V_30 |= V_356 | F_38 ( V_357 ) ;
if ( V_334 == 0 )
V_30 |= 0x1 ;
if ( V_10 -> V_350 == 0x100 ) {
if ( V_74 -> V_272 > 0 ) {
if ( V_354 -> V_358 & V_359 )
V_30 |= F_173 ( V_360 ) ;
else
V_30 |= F_173 ( V_361 ) ;
}
}
F_142 ( V_10 , V_82 , true ,
V_354 -> V_358 | V_354 -> V_362 << 8 | F_174 ( V_354 -> V_363 ) << 16 ,
F_174 ( V_354 -> V_364 ) | F_174 ( V_354 -> V_365 ) << 16 ,
F_133 ( 8 ) | F_168 ( 0 ) ,
V_30 ) ;
if ( F_167 ( V_74 ) )
V_30 = V_349 | F_38 ( V_366 ) ;
else
V_30 = F_38 ( V_366 ) ;
V_347 = F_133 ( V_74 -> V_272 ) |
F_161 ( V_74 -> V_272 ) |
F_168 ( 0 ) ;
if ( V_74 -> V_272 > 0 ) {
if ( V_354 -> V_358 & V_359 )
V_30 |= V_367 ;
F_142 ( V_10 , V_82 , true ,
F_169 ( V_74 -> V_352 ) ,
F_170 ( V_74 -> V_352 ) ,
V_347 ,
V_30 | V_82 -> V_26 ) ;
}
V_254 -> F_4 = V_82 -> V_20 ;
if ( V_74 -> V_272 > 0 && V_354 -> V_358 & V_359 )
V_30 = 0 ;
else
V_30 = V_367 ;
F_142 ( V_10 , V_82 , false ,
0 ,
0 ,
F_168 ( 0 ) ,
V_30 | V_348 | F_38 ( V_368 ) | V_82 -> V_26 ) ;
F_156 ( V_10 , V_56 , V_57 , 0 ,
V_334 , V_248 ) ;
return 0 ;
}
static int F_175 ( struct V_9 * V_10 ,
struct V_74 * V_74 , int V_138 )
{
int V_38 = 0 ;
T_3 V_85 , V_369 ;
V_85 = ( T_3 ) ( V_74 -> V_352 + V_74 -> V_283 [ V_138 ] . V_370 ) ;
V_369 = V_74 -> V_283 [ V_138 ] . V_119 ;
V_38 = F_166 ( V_369 + ( V_85 & ( V_333 - 1 ) ) ,
V_333 ) ;
if ( V_38 == 0 )
V_38 ++ ;
return V_38 ;
}
static unsigned int F_176 ( struct V_9 * V_10 ,
struct V_216 * V_217 ,
struct V_74 * V_74 , unsigned int V_343 )
{
unsigned int V_371 ;
if ( V_10 -> V_350 < 0x100 || V_217 -> V_214 != V_372 )
return 0 ;
V_371 = V_74 -> V_61 -> V_373 . V_374 ;
return F_166 ( V_343 , V_371 + 1 ) - 1 ;
}
static unsigned int F_177 ( struct V_9 * V_10 ,
struct V_216 * V_217 ,
struct V_74 * V_74 , unsigned int V_343 )
{
unsigned int V_371 ;
unsigned int V_375 ;
if ( V_10 -> V_350 < 0x100 )
return 0 ;
switch ( V_217 -> V_214 ) {
case V_372 :
V_371 = V_74 -> V_61 -> V_373 . V_374 ;
V_375 = V_343 % ( V_371 + 1 ) ;
if ( V_375 == 0 )
return V_371 ;
return V_375 - 1 ;
default:
if ( V_343 == 0 )
return 0 ;
return V_343 - 1 ;
}
}
static int F_178 ( struct V_9 * V_10 , T_8 V_317 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_82 ;
struct V_115 * V_115 ;
struct V_77 * V_254 ;
int V_376 , V_377 ;
struct V_193 * V_248 ;
bool V_105 ;
int V_334 ;
T_2 V_30 , V_347 ;
int V_329 , V_342 , V_369 , V_378 , V_47 ;
T_3 V_379 , V_85 ;
int V_138 , V_139 ;
bool V_27 ;
V_82 = V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] . V_12 ;
V_376 = V_74 -> V_380 ;
if ( V_376 < 1 ) {
F_15 ( V_10 , L_125 ) ;
return - V_322 ;
}
V_379 = ( T_3 ) V_74 -> V_352 ;
V_248 = & V_82 -> V_20 -> V_29 ;
V_334 = V_82 -> V_26 ;
V_115 = V_74 -> V_116 ;
for ( V_138 = 0 ; V_138 < V_376 ; V_138 ++ ) {
unsigned int V_343 ;
unsigned int V_381 ;
unsigned int V_375 ;
V_105 = true ;
V_329 = 0 ;
V_85 = V_379 + V_74 -> V_283 [ V_138 ] . V_370 ;
V_369 = V_74 -> V_283 [ V_138 ] . V_119 ;
V_378 = V_369 ;
V_343 = F_166 ( V_369 ,
F_163 (
F_164 ( & V_74 -> V_61 -> V_76 ) ) ) ;
if ( V_343 == 0 )
V_343 ++ ;
V_381 = F_176 ( V_10 , V_74 -> V_75 , V_74 ,
V_343 ) ;
V_375 = F_177 ( V_10 ,
V_74 -> V_75 , V_74 , V_343 ) ;
V_377 = F_175 ( V_10 , V_74 , V_138 ) ;
V_47 = F_145 ( V_10 , V_10 -> V_62 [ V_56 ] , V_57 ,
V_74 -> V_58 , V_377 , V_74 , V_138 , V_317 ) ;
if ( V_47 < 0 ) {
if ( V_138 == 0 )
return V_47 ;
goto V_230;
}
V_254 = V_115 -> V_254 [ V_138 ] ;
for ( V_139 = 0 ; V_139 < V_377 ; V_139 ++ ) {
T_2 V_340 = 0 ;
V_30 = 0 ;
if ( V_105 ) {
V_30 = F_179 ( V_381 ) |
F_180 ( V_375 ) ;
V_30 |= F_38 ( V_382 ) ;
V_30 |= V_383 ;
if ( V_138 == 0 ) {
if ( V_334 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_82 -> V_26 ;
V_105 = false ;
} else {
V_30 |= F_38 ( V_351 ) ;
V_30 |= V_82 -> V_26 ;
}
if ( F_167 ( V_74 ) )
V_30 |= V_349 ;
if ( V_139 < V_377 - 1 ) {
V_30 |= V_31 ;
V_27 = true ;
} else {
V_254 -> F_4 = V_82 -> V_20 ;
V_30 |= V_348 ;
if ( V_10 -> V_350 == 0x100 &&
! ( V_10 -> V_35 &
V_384 ) ) {
if ( V_138 < V_376 - 1 )
V_30 |= V_385 ;
}
V_27 = false ;
}
V_342 = V_333 -
( V_85 & ( ( 1 << V_386 ) - 1 ) ) ;
if ( V_342 > V_378 )
V_342 = V_378 ;
if ( V_10 -> V_350 < 0x100 ) {
V_340 = F_161 (
V_369 - V_329 ) ;
} else {
V_340 = F_162 (
V_329 , V_342 ,
V_343 , V_74 ,
( V_377 - V_139 - 1 ) ) ;
}
V_347 = F_133 ( V_342 ) |
V_340 |
F_168 ( 0 ) ;
F_142 ( V_10 , V_82 , V_27 ,
F_169 ( V_85 ) ,
F_170 ( V_85 ) ,
V_347 ,
V_30 ) ;
V_329 += V_342 ;
V_85 += V_342 ;
V_378 -= V_342 ;
}
if ( V_329 != V_369 ) {
F_22 ( V_10 , L_126 ) ;
V_47 = - V_322 ;
goto V_230;
}
}
if ( F_46 ( V_10 ) -> V_122 . V_123 == 0 ) {
if ( V_10 -> V_35 & V_124 )
F_181 () ;
}
F_46 ( V_10 ) -> V_122 . V_123 ++ ;
F_156 ( V_10 , V_56 , V_57 , V_74 -> V_58 ,
V_334 , V_248 ) ;
return 0 ;
V_230:
for ( V_138 -- ; V_138 >= 0 ; V_138 -- )
F_59 ( & V_115 -> V_254 [ V_138 ] -> V_69 ) ;
V_115 -> V_254 [ 0 ] -> F_4 = V_82 -> V_20 ;
F_37 ( V_10 , V_82 , V_115 -> V_254 [ 0 ] , true ) ;
V_82 -> V_20 = V_115 -> V_254 [ 0 ] -> V_105 ;
V_82 -> V_32 = V_115 -> V_254 [ 0 ] -> V_104 ;
V_82 -> V_26 = V_334 ;
V_82 -> V_25 = V_82 -> V_144 ;
F_48 ( F_44 ( V_74 -> V_75 -> V_118 ) , V_74 ) ;
return V_47 ;
}
int F_182 ( struct V_9 * V_10 , T_8 V_317 ,
struct V_74 * V_74 , int V_56 , unsigned int V_57 )
{
struct V_81 * V_264 ;
struct V_11 * V_82 ;
struct V_94 * V_95 ;
int V_387 ;
int V_335 ;
int V_336 ;
int V_376 , V_38 , V_138 ;
int V_47 ;
V_264 = V_10 -> V_62 [ V_56 ] ;
V_82 = V_264 -> V_63 [ V_57 ] . V_12 ;
V_95 = F_36 ( V_10 , V_264 -> V_96 , V_57 ) ;
V_38 = 0 ;
V_376 = V_74 -> V_380 ;
for ( V_138 = 0 ; V_138 < V_376 ; V_138 ++ )
V_38 += F_175 ( V_10 , V_74 , V_138 ) ;
V_47 = F_143 ( V_10 , V_82 , F_3 ( V_95 -> V_154 ) & V_155 ,
V_38 , V_317 ) ;
if ( V_47 )
return V_47 ;
V_387 = F_17 ( & V_10 -> V_388 -> V_389 ) ;
V_387 &= 0x3fff ;
V_74 -> V_387 = V_387 ;
if ( V_74 -> V_75 -> V_214 == V_338 ||
V_74 -> V_75 -> V_214 == V_339 )
V_74 -> V_387 >>= 3 ;
V_335 = F_158 ( F_3 ( V_95 -> V_154 ) ) ;
V_336 = V_74 -> V_337 ;
if ( V_74 -> V_75 -> V_214 == V_338 ||
V_74 -> V_75 -> V_214 == V_339 )
V_336 *= 8 ;
if ( V_335 != V_336 ) {
F_159 ( & V_74 -> V_75 -> V_75 ,
L_120 ,
V_336 , V_336 == 1 ? L_121 : L_122 ,
V_335 , V_335 == 1 ? L_121 : L_122 ) ;
V_74 -> V_337 = V_335 ;
if ( V_74 -> V_75 -> V_214 == V_338 ||
V_74 -> V_75 -> V_214 == V_339 )
V_74 -> V_337 /= 8 ;
}
V_82 -> V_144 = V_82 -> V_25 ;
return F_178 ( V_10 , V_317 , V_74 , V_56 , V_57 ) ;
}
static int F_183 ( struct V_9 * V_10 , struct V_107 * V_108 ,
T_2 V_313 , T_2 V_314 ,
T_2 V_315 , T_2 V_316 , bool V_390 )
{
int V_391 = V_10 -> V_392 ;
int V_47 ;
if ( V_10 -> V_53 & V_54 )
return - V_55 ;
if ( ! V_390 )
V_391 ++ ;
V_47 = F_143 ( V_10 , V_10 -> V_49 , V_324 ,
V_391 , V_135 ) ;
if ( V_47 < 0 ) {
F_22 ( V_10 , L_127 ) ;
if ( V_390 )
F_22 ( V_10 , L_128
L_129 ) ;
return V_47 ;
}
V_108 -> V_181 = V_10 -> V_49 -> V_20 ;
F_148 ( & V_108 -> V_174 , & V_10 -> V_174 ) ;
if ( V_10 -> V_174 . V_14 == & V_108 -> V_174 &&
! F_184 ( & V_10 -> V_184 ) ) {
V_10 -> V_183 = V_108 ;
F_94 ( & V_10 -> V_184 , V_185 + V_186 ) ;
}
F_142 ( V_10 , V_10 -> V_49 , false , V_313 , V_314 , V_315 ,
V_316 | V_10 -> V_49 -> V_26 ) ;
return 0 ;
}
int F_185 ( struct V_9 * V_10 , struct V_107 * V_108 ,
T_2 V_206 , T_2 V_56 )
{
return F_183 ( V_10 , V_108 , 0 , 0 , 0 ,
F_38 ( V_206 ) | F_186 ( V_56 ) , false ) ;
}
int F_187 ( struct V_9 * V_10 , struct V_107 * V_108 ,
T_1 V_393 , T_2 V_56 , enum V_394 V_354 )
{
return F_183 ( V_10 , V_108 , F_169 ( V_393 ) ,
F_170 ( V_393 ) , 0 ,
F_38 ( V_200 ) | F_186 ( V_56 )
| ( V_354 == V_395 ? V_396 : 0 ) , false ) ;
}
int F_188 ( struct V_9 * V_10 , struct V_107 * V_108 ,
T_2 V_313 , T_2 V_314 , T_2 V_315 , T_2 V_316 )
{
return F_183 ( V_10 , V_108 , V_313 , V_314 , V_315 , V_316 , false ) ;
}
int F_189 ( struct V_9 * V_10 , struct V_107 * V_108 ,
T_2 V_56 )
{
return F_183 ( V_10 , V_108 , 0 , 0 , 0 ,
F_38 ( V_204 ) | F_186 ( V_56 ) ,
false ) ;
}
int F_75 ( struct V_9 * V_10 ,
struct V_107 * V_108 , T_1 V_393 ,
T_2 V_56 , bool V_390 )
{
return F_183 ( V_10 , V_108 , F_169 ( V_393 ) ,
F_170 ( V_393 ) , 0 ,
F_38 ( V_198 ) | F_186 ( V_56 ) ,
V_390 ) ;
}
int F_190 ( struct V_9 * V_10 , struct V_107 * V_108 ,
T_1 V_393 , T_2 V_56 , bool V_390 )
{
return F_183 ( V_10 , V_108 , F_169 ( V_393 ) ,
F_170 ( V_393 ) , 0 ,
F_38 ( V_199 ) | F_186 ( V_56 ) ,
V_390 ) ;
}
int F_191 ( struct V_9 * V_10 , struct V_107 * V_108 ,
int V_56 , unsigned int V_57 , int V_397 )
{
T_2 V_398 = F_186 ( V_56 ) ;
T_2 V_399 = F_192 ( V_57 ) ;
T_2 type = F_38 ( V_201 ) ;
T_2 V_400 = F_193 ( V_397 ) ;
return F_183 ( V_10 , V_108 , 0 , 0 , 0 ,
V_398 | V_399 | type | V_400 , false ) ;
}
static int F_40 ( struct V_9 * V_10 , struct V_107 * V_108 ,
int V_56 ,
unsigned int V_57 , unsigned int V_58 ,
struct V_1 * V_23 ,
union V_3 * V_401 , T_2 V_26 )
{
T_1 V_85 ;
T_2 V_398 = F_186 ( V_56 ) ;
T_2 V_399 = F_192 ( V_57 ) ;
T_2 V_402 = F_194 ( V_58 ) ;
T_2 V_403 = 0 ;
T_2 type = F_38 ( V_202 ) ;
struct V_60 * V_61 ;
V_85 = F_1 ( V_23 , V_401 ) ;
if ( V_85 == 0 ) {
F_30 ( V_10 , L_130 ) ;
F_30 ( V_10 , L_131 ,
V_23 , V_401 ) ;
return 0 ;
}
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ( V_61 -> V_64 & V_66 ) ) {
F_30 ( V_10 , L_130 ) ;
F_30 ( V_10 , L_132 ) ;
return 0 ;
}
V_61 -> V_160 = V_23 ;
V_61 -> V_146 = V_401 ;
if ( V_58 )
V_403 = F_195 ( V_404 ) ;
return F_183 ( V_10 , V_108 ,
F_169 ( V_85 ) | V_403 | V_26 ,
F_170 ( V_85 ) , V_402 ,
V_398 | V_399 | type , false ) ;
}
int F_122 ( struct V_9 * V_10 , struct V_107 * V_108 ,
int V_56 , unsigned int V_57 )
{
T_2 V_398 = F_186 ( V_56 ) ;
T_2 V_399 = F_192 ( V_57 ) ;
T_2 type = F_38 ( V_203 ) ;
return F_183 ( V_10 , V_108 , 0 , 0 , 0 ,
V_398 | V_399 | type , false ) ;
}
