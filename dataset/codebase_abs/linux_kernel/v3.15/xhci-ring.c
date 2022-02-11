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
union V_3 * F_7 ( struct V_11 * V_12 )
{
if ( F_5 ( V_12 -> V_20 -> V_16 . V_17 ) )
return V_12 -> V_21 -> V_14 -> V_6 ;
return V_12 -> V_20 ;
}
static void F_8 ( struct V_9 * V_10 ,
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
static void F_9 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
V_12 -> V_22 ++ ;
if ( V_12 -> type != V_23 &&
! F_4 ( V_10 , V_12 , V_12 -> V_24 , V_12 -> V_25 ) )
V_12 -> V_26 ++ ;
do {
if ( F_4 ( V_10 , V_12 , V_12 -> V_24 , V_12 -> V_25 ) ) {
if ( V_12 -> type == V_23 &&
F_2 ( V_10 , V_12 ,
V_12 -> V_24 , V_12 -> V_25 ) ) {
V_12 -> V_27 ^= 1 ;
}
V_12 -> V_24 = V_12 -> V_24 -> V_14 ;
V_12 -> V_25 = V_12 -> V_24 -> V_6 ;
} else {
V_12 -> V_25 ++ ;
}
} while ( F_4 ( V_10 , V_12 , V_12 -> V_24 , V_12 -> V_25 ) );
}
static void F_10 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_28 )
{
T_2 V_29 ;
union V_3 * V_14 ;
V_29 = F_3 ( V_12 -> V_20 -> V_30 . V_31 [ 3 ] ) & V_32 ;
if ( V_12 -> type != V_23 &&
! F_4 ( V_10 , V_12 , V_12 -> V_21 , V_12 -> V_20 ) )
V_12 -> V_26 -- ;
V_14 = ++ ( V_12 -> V_20 ) ;
V_12 -> V_33 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_21 , V_14 ) ) {
if ( V_12 -> type != V_23 ) {
if ( ! V_29 && ! V_28 )
break;
if ( ! ( V_12 -> type == V_34 &&
( V_10 -> V_35 & V_36 ) )
&& ! F_11 ( V_10 ) ) {
V_14 -> V_16 . V_17 &=
F_12 ( ~ V_32 ) ;
V_14 -> V_16 . V_17 |=
F_12 ( V_29 ) ;
}
F_13 () ;
V_14 -> V_16 . V_17 ^= F_12 ( V_37 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_21 , V_14 ) ) {
V_12 -> V_27 = ( V_12 -> V_27 ? 0 : 1 ) ;
}
}
V_12 -> V_21 = V_12 -> V_21 -> V_14 ;
V_12 -> V_20 = V_12 -> V_21 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
static inline int F_14 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_38 )
{
int V_39 ;
if ( V_12 -> V_26 < V_38 )
return 0 ;
if ( V_12 -> type != V_40 && V_12 -> type != V_23 ) {
V_39 = V_12 -> V_25 - V_12 -> V_24 -> V_6 ;
if ( V_12 -> V_26 < V_38 + V_39 )
return 0 ;
}
return 1 ;
}
void F_15 ( struct V_9 * V_10 )
{
if ( ! ( V_10 -> V_41 & V_42 ) )
return;
F_16 ( V_10 , L_1 ) ;
F_17 ( V_43 , & V_10 -> V_44 -> V_45 [ 0 ] ) ;
F_18 ( & V_10 -> V_44 -> V_45 [ 0 ] ) ;
}
static int F_19 ( struct V_9 * V_10 )
{
T_3 V_46 ;
int V_47 ;
F_16 ( V_10 , L_2 ) ;
if ( ! ( V_10 -> V_41 & V_42 ) ) {
F_16 ( V_10 , L_3
L_4 ) ;
return 0 ;
}
V_46 = F_20 ( V_10 , & V_10 -> V_48 -> V_49 ) ;
if ( ! ( V_46 & V_50 ) ) {
F_16 ( V_10 , L_5 ) ;
return 0 ;
}
V_10 -> V_41 = V_51 ;
F_21 ( V_10 , V_46 | V_52 ,
& V_10 -> V_48 -> V_49 ) ;
V_47 = F_22 ( V_10 , & V_10 -> V_48 -> V_49 ,
V_50 , 0 , 5 * 1000 * 1000 ) ;
if ( V_47 < 0 ) {
F_23 ( V_10 , L_6
L_7 ) ;
V_10 -> V_53 |= V_54 ;
F_24 ( V_10 ) ;
F_25 ( V_10 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
struct V_56 * V_57 ,
union V_3 * V_58 )
{
struct V_59 * V_60 ;
V_60 = F_27 ( sizeof( struct V_59 ) , V_61 ) ;
if ( ! V_60 )
return - V_62 ;
F_28 ( & V_60 -> V_63 ) ;
V_60 -> V_57 = V_57 ;
V_60 -> V_58 = V_58 ;
F_29 ( & V_60 -> V_63 , & V_10 -> V_63 ) ;
return 0 ;
}
int F_30 ( struct V_9 * V_10 , struct V_56 * V_57 ,
union V_3 * V_58 )
{
int V_64 = 0 ;
unsigned long V_65 ;
F_31 ( & V_10 -> V_66 , V_65 ) ;
if ( V_10 -> V_53 & V_54 ) {
F_32 ( V_10 , L_8
L_9 ) ;
V_64 = - V_55 ;
goto V_67;
}
V_64 = F_26 ( V_10 , V_57 , V_58 ) ;
if ( V_64 ) {
F_32 ( V_10 , L_10 ) ;
goto V_67;
}
V_64 = F_19 ( V_10 ) ;
if ( V_64 ) {
F_23 ( V_10 , L_11 ) ;
if ( F_33 ( V_64 == - V_55 ) ) {
F_34 ( & V_10 -> V_66 , V_65 ) ;
F_35 ( F_36 ( V_10 ) -> V_68 ) ;
F_16 ( V_10 , L_12 ) ;
return V_64 ;
}
}
V_67:
F_34 ( & V_10 -> V_66 , V_65 ) ;
return V_64 ;
}
void F_37 ( struct V_9 * V_10 ,
unsigned int V_69 ,
unsigned int V_70 ,
unsigned int V_71 )
{
T_4 T_5 * V_72 = & V_10 -> V_44 -> V_45 [ V_69 ] ;
struct V_73 * V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
unsigned int V_77 = V_74 -> V_77 ;
if ( ( V_77 & V_78 ) || ( V_77 & V_79 ) ||
( V_77 & V_80 ) )
return;
F_17 ( F_38 ( V_70 , V_71 ) , V_72 ) ;
}
static void F_39 ( struct V_9 * V_10 ,
unsigned int V_69 ,
unsigned int V_70 )
{
unsigned int V_71 ;
struct V_73 * V_74 ;
V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
if ( ! ( V_74 -> V_77 & V_81 ) ) {
if ( V_74 -> V_12 && ! ( F_40 ( & V_74 -> V_12 -> V_82 ) ) )
F_37 ( V_10 , V_69 , V_70 , 0 ) ;
return;
}
for ( V_71 = 1 ; V_71 < V_74 -> V_83 -> V_84 ;
V_71 ++ ) {
struct V_85 * V_83 = V_74 -> V_83 ;
if ( ! F_40 ( & V_83 -> V_86 [ V_71 ] -> V_82 ) )
F_37 ( V_10 , V_69 , V_70 ,
V_71 ) ;
}
}
static struct V_1 * F_41 (
struct V_1 * V_87 ,
union V_3 * V_4 , int * V_27 )
{
struct V_1 * V_88 = V_87 ;
struct V_89 * V_90 ;
while ( V_88 -> V_6 > V_4 ||
& V_88 -> V_6 [ V_7 - 1 ] < V_4 ) {
V_90 = & V_88 -> V_6 [ V_7 - 1 ] . V_30 ;
if ( V_90 -> V_31 [ 3 ] & F_12 ( V_18 ) )
* V_27 ^= 0x1 ;
V_88 = V_88 -> V_14 ;
if ( V_88 == V_87 )
return NULL ;
}
return V_88 ;
}
static struct V_11 * F_42 ( struct V_9 * V_10 ,
unsigned int V_69 , unsigned int V_70 ,
unsigned int V_71 )
{
struct V_73 * V_74 ;
V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
if ( ! ( V_74 -> V_77 & V_81 ) )
return V_74 -> V_12 ;
if ( V_71 == 0 ) {
F_32 ( V_10 ,
L_13
L_14 ,
V_69 , V_70 ) ;
return NULL ;
}
if ( V_71 < V_74 -> V_83 -> V_84 )
return V_74 -> V_83 -> V_86 [ V_71 ] ;
F_32 ( V_10 ,
L_15
L_16
L_17 ,
V_69 , V_70 ,
V_74 -> V_83 -> V_84 - 1 ,
V_71 ) ;
return NULL ;
}
static struct V_11 * F_43 ( struct V_9 * V_10 ,
struct V_91 * V_91 )
{
return F_42 ( V_10 , V_91 -> V_92 -> V_69 ,
F_44 ( & V_91 -> V_74 -> V_93 ) , V_91 -> V_71 ) ;
}
void F_45 ( struct V_9 * V_10 ,
unsigned int V_69 , unsigned int V_70 ,
unsigned int V_71 , struct V_94 * V_95 ,
struct V_96 * V_97 )
{
struct V_98 * V_92 = V_10 -> V_75 [ V_69 ] ;
struct V_73 * V_74 = & V_92 -> V_76 [ V_70 ] ;
struct V_11 * V_99 ;
struct V_89 * V_4 ;
T_1 V_100 ;
T_3 V_101 ;
V_99 = F_42 ( V_10 , V_69 ,
V_70 , V_71 ) ;
if ( ! V_99 ) {
F_32 ( V_10 , L_18
L_19 ,
V_71 ) ;
return;
}
F_46 ( V_10 , V_102 ,
L_20 ) ;
if ( V_74 -> V_77 & V_81 ) {
struct V_103 * V_104 =
& V_74 -> V_83 -> V_105 [ V_71 ] ;
V_101 = F_47 ( V_104 -> V_106 ) ;
} else {
struct V_107 * V_108
= F_48 ( V_10 , V_92 -> V_109 , V_70 ) ;
V_101 = F_47 ( V_108 -> V_110 ) ;
}
V_97 -> V_111 = V_99 -> V_24 ;
V_97 -> V_112 = V_99 -> V_25 ;
while ( F_1 ( V_97 -> V_111 , V_97 -> V_112 )
!= ( T_1 ) ( V_101 & ~ 0xf ) ) {
F_8 ( V_10 , V_99 , & V_97 -> V_111 ,
& V_97 -> V_112 ) ;
if ( V_97 -> V_112 == V_99 -> V_25 ) {
F_49 ( 1 ) ;
return;
}
}
V_97 -> V_113 = V_101 & 0x1 ;
if ( V_99 -> V_15 == V_99 -> V_15 -> V_14 &&
V_95 -> F_4 < V_97 -> V_112 )
V_97 -> V_113 ^= 0x1 ;
V_97 -> V_112 = V_95 -> F_4 ;
F_46 ( V_10 , V_102 ,
L_21 ) ;
V_97 -> V_111 = F_41 ( V_97 -> V_111 ,
V_97 -> V_112 , & V_97 -> V_113 ) ;
if ( ! V_97 -> V_111 ) {
F_49 ( 1 ) ;
return;
}
V_4 = & V_97 -> V_112 -> V_30 ;
if ( F_5 ( V_4 -> V_31 [ 3 ] ) &&
( V_4 -> V_31 [ 3 ] & F_12 ( V_18 ) ) )
V_97 -> V_113 ^= 0x1 ;
F_8 ( V_10 , V_99 , & V_97 -> V_111 , & V_97 -> V_112 ) ;
F_46 ( V_10 , V_102 ,
L_22 , V_97 -> V_113 ) ;
F_46 ( V_10 , V_102 ,
L_23 ,
V_97 -> V_111 ) ;
V_100 = F_1 ( V_97 -> V_111 , V_97 -> V_112 ) ;
F_46 ( V_10 , V_102 ,
L_24 ,
( unsigned long long ) V_100 ) ;
}
static void F_50 ( struct V_9 * V_10 , struct V_11 * V_99 ,
struct V_94 * V_95 , bool V_114 )
{
struct V_1 * V_88 ;
union V_3 * V_115 ;
for ( V_88 = V_95 -> V_87 , V_115 = V_95 -> V_116 ;
true ;
F_8 ( V_10 , V_99 , & V_88 , & V_115 ) ) {
if ( F_5 ( V_115 -> V_30 . V_31 [ 3 ] ) ) {
V_115 -> V_30 . V_31 [ 3 ] &= F_12 ( ~ V_32 ) ;
if ( V_114 )
V_115 -> V_30 . V_31 [ 3 ] ^=
F_12 ( V_37 ) ;
F_46 ( V_10 , V_102 ,
L_25 ) ;
F_46 ( V_10 , V_102 ,
L_26
L_27 ,
V_115 ,
( unsigned long long ) F_1 ( V_88 , V_115 ) ,
V_88 ,
( unsigned long long ) V_88 -> V_8 ) ;
} else {
V_115 -> V_30 . V_31 [ 0 ] = 0 ;
V_115 -> V_30 . V_31 [ 1 ] = 0 ;
V_115 -> V_30 . V_31 [ 2 ] = 0 ;
V_115 -> V_30 . V_31 [ 3 ] &= F_12 ( V_37 ) ;
if ( V_114 && V_115 != V_95 -> V_116 &&
V_115 != V_95 -> F_4 )
V_115 -> V_30 . V_31 [ 3 ] ^=
F_12 ( V_37 ) ;
V_115 -> V_30 . V_31 [ 3 ] |= F_12 (
F_51 ( V_117 ) ) ;
F_46 ( V_10 , V_102 ,
L_28 ,
( unsigned long long )
F_1 ( V_88 , V_115 ) ) ;
}
if ( V_115 == V_95 -> F_4 )
break;
}
}
void F_52 ( struct V_9 * V_10 ,
unsigned int V_69 , unsigned int V_70 ,
unsigned int V_71 ,
struct V_96 * V_118 )
{
struct V_73 * V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
F_46 ( V_10 , V_102 ,
L_29
L_30 ,
V_118 -> V_111 ,
( unsigned long long ) V_118 -> V_111 -> V_8 ,
V_118 -> V_112 ,
( unsigned long long ) F_1 ( V_118 -> V_111 , V_118 -> V_112 ) ,
V_118 -> V_113 ) ;
F_53 ( V_10 , V_69 , V_70 , V_71 ,
V_118 -> V_111 ,
V_118 -> V_112 ,
( T_2 ) V_118 -> V_113 ) ;
V_74 -> V_77 |= V_79 ;
}
static void F_54 ( struct V_9 * V_10 ,
struct V_73 * V_74 )
{
V_74 -> V_77 &= ~ V_78 ;
if ( F_55 ( & V_74 -> V_119 ) )
V_74 -> V_120 -- ;
}
static void F_56 ( struct V_9 * V_10 ,
struct V_94 * V_95 , int V_121 )
{
struct V_122 * V_123 ;
struct V_91 * V_91 ;
struct V_124 * V_124 ;
V_91 = V_95 -> V_91 ;
V_124 = V_91 -> V_125 ;
V_124 -> V_126 ++ ;
V_123 = F_57 ( V_91 -> V_92 -> V_127 ) ;
if ( V_124 -> V_126 == V_124 -> V_128 ) {
if ( F_58 ( V_91 -> V_129 ) == V_130 ) {
F_36 ( V_10 ) -> V_131 . V_132 -- ;
if ( F_36 ( V_10 ) -> V_131 . V_132 == 0 ) {
if ( V_10 -> V_35 & V_133 )
F_59 () ;
}
}
F_60 ( V_123 , V_91 ) ;
F_61 ( & V_10 -> V_66 ) ;
F_62 ( V_123 , V_91 , V_121 ) ;
F_63 ( V_10 , V_124 ) ;
F_64 ( & V_10 -> V_66 ) ;
}
}
static void F_65 ( struct V_9 * V_10 , int V_69 ,
union V_3 * V_4 , struct V_134 * V_135 )
{
unsigned int V_70 ;
struct V_98 * V_136 ;
struct V_11 * V_99 ;
struct V_73 * V_74 ;
struct V_137 * V_138 ;
struct V_94 * V_95 = NULL ;
struct V_94 * V_139 ;
struct V_96 V_118 ;
if ( F_33 ( F_66 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ) ) {
V_136 = V_10 -> V_75 [ V_69 ] ;
if ( V_136 )
F_67 ( V_10 , V_136 ,
V_135 ) ;
else
F_32 ( V_10 , L_31
L_32 ,
V_69 ) ;
return;
}
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_70 = F_68 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
if ( F_40 ( & V_74 -> V_140 ) ) {
F_54 ( V_10 , V_74 ) ;
V_74 -> V_141 = NULL ;
F_39 ( V_10 , V_69 , V_70 ) ;
return;
}
F_69 (entry, &ep->cancelled_td_list) {
V_95 = F_70 ( V_138 , struct V_94 , V_140 ) ;
F_46 ( V_10 , V_102 ,
L_33 ,
( unsigned long long ) F_1 (
V_95 -> V_87 , V_95 -> V_116 ) ) ;
V_99 = F_43 ( V_10 , V_95 -> V_91 ) ;
if ( ! V_99 ) {
F_32 ( V_10 , L_34
L_35 ,
V_95 -> V_91 ,
V_95 -> V_91 -> V_71 ) ;
goto V_142;
}
if ( V_95 == V_74 -> V_141 )
F_45 ( V_10 , V_69 , V_70 ,
V_95 -> V_91 -> V_71 ,
V_95 , & V_118 ) ;
else
F_50 ( V_10 , V_99 , V_95 , false ) ;
V_142:
F_71 ( & V_95 -> V_82 ) ;
}
V_139 = V_95 ;
F_54 ( V_10 , V_74 ) ;
if ( V_118 . V_112 && V_118 . V_111 ) {
F_52 ( V_10 ,
V_69 , V_70 ,
V_74 -> V_141 -> V_91 -> V_71 ,
& V_118 ) ;
F_15 ( V_10 ) ;
} else {
F_39 ( V_10 , V_69 , V_70 ) ;
}
if ( ! ( V_74 -> V_77 & V_80 ) )
V_74 -> V_141 = NULL ;
do {
V_95 = F_70 ( V_74 -> V_140 . V_14 ,
struct V_94 , V_140 ) ;
F_71 ( & V_95 -> V_140 ) ;
F_56 ( V_10 , V_95 , 0 ) ;
if ( V_10 -> V_53 & V_54 )
return;
} while ( V_95 != V_139 );
}
static void F_72 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_94 * V_95 ;
while ( ! F_40 ( & V_12 -> V_82 ) ) {
V_95 = F_73 ( & V_12 -> V_82 ,
struct V_94 , V_82 ) ;
F_71 ( & V_95 -> V_82 ) ;
if ( ! F_40 ( & V_95 -> V_140 ) )
F_71 ( & V_95 -> V_140 ) ;
F_56 ( V_10 , V_95 , - V_55 ) ;
}
}
static void F_74 ( struct V_9 * V_10 ,
int V_69 , int V_70 )
{
struct V_94 * V_95 ;
struct V_73 * V_74 ;
struct V_11 * V_12 ;
V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
if ( ( V_74 -> V_77 & V_81 ) ||
( V_74 -> V_77 & V_143 ) ) {
int V_71 ;
for ( V_71 = 0 ; V_71 < V_74 -> V_83 -> V_84 ;
V_71 ++ ) {
F_46 ( V_10 , V_102 ,
L_36 ,
V_69 , V_70 , V_71 + 1 ) ;
F_72 ( V_10 ,
V_74 -> V_83 -> V_86 [ V_71 ] ) ;
}
} else {
V_12 = V_74 -> V_12 ;
if ( ! V_12 )
return;
F_46 ( V_10 , V_102 ,
L_37 ,
V_69 , V_70 ) ;
F_72 ( V_10 , V_12 ) ;
}
while ( ! F_40 ( & V_74 -> V_140 ) ) {
V_95 = F_73 ( & V_74 -> V_140 ,
struct V_94 , V_140 ) ;
F_71 ( & V_95 -> V_140 ) ;
F_56 ( V_10 , V_95 , - V_55 ) ;
}
}
void F_75 ( unsigned long V_144 )
{
struct V_9 * V_10 ;
struct V_73 * V_74 ;
int V_47 , V_145 , V_146 ;
unsigned long V_65 ;
V_74 = (struct V_73 * ) V_144 ;
V_10 = V_74 -> V_10 ;
F_31 ( & V_10 -> V_66 , V_65 ) ;
V_74 -> V_120 -- ;
if ( V_10 -> V_53 & V_54 ) {
F_46 ( V_10 , V_102 ,
L_38
L_39 ) ;
F_34 ( & V_10 -> V_66 , V_65 ) ;
return;
}
if ( ! ( V_74 -> V_120 == 0 && ( V_74 -> V_77 & V_78 ) ) ) {
F_46 ( V_10 , V_102 ,
L_40
L_41 ) ;
F_34 ( & V_10 -> V_66 , V_65 ) ;
return;
}
F_32 ( V_10 , L_42 ) ;
F_32 ( V_10 , L_43 ) ;
V_10 -> V_53 |= V_54 ;
F_24 ( V_10 ) ;
F_34 ( & V_10 -> V_66 , V_65 ) ;
V_47 = F_25 ( V_10 ) ;
F_31 ( & V_10 -> V_66 , V_65 ) ;
if ( V_47 < 0 ) {
F_32 ( V_10 , L_44 ) ;
F_32 ( V_10 , L_45 ) ;
}
for ( V_145 = 0 ; V_145 < V_147 ; V_145 ++ ) {
if ( ! V_10 -> V_75 [ V_145 ] )
continue;
for ( V_146 = 0 ; V_146 < 31 ; V_146 ++ )
F_74 ( V_10 , V_145 , V_146 ) ;
}
F_34 ( & V_10 -> V_66 , V_65 ) ;
F_46 ( V_10 , V_102 ,
L_46 ) ;
F_35 ( F_36 ( V_10 ) -> V_68 ) ;
F_46 ( V_10 , V_102 ,
L_47 ) ;
}
static void F_76 ( struct V_9 * V_10 ,
struct V_98 * V_92 ,
struct V_11 * V_99 ,
unsigned int V_70 )
{
union V_3 * V_148 ;
int V_149 ;
bool V_150 = false ;
V_149 = V_99 -> V_26 ;
V_148 = V_99 -> V_25 ;
if ( F_4 ( V_10 , V_99 , V_99 -> V_24 , V_99 -> V_25 ) ) {
V_99 -> V_24 = V_99 -> V_24 -> V_14 ;
V_99 -> V_25 = V_99 -> V_24 -> V_6 ;
}
while ( V_99 -> V_25 != V_92 -> V_76 [ V_70 ] . V_151 ) {
V_99 -> V_26 ++ ;
V_99 -> V_25 ++ ;
if ( F_4 ( V_10 , V_99 , V_99 -> V_24 ,
V_99 -> V_25 ) ) {
if ( V_99 -> V_25 ==
V_92 -> V_76 [ V_70 ] . V_151 )
break;
V_99 -> V_24 = V_99 -> V_24 -> V_14 ;
V_99 -> V_25 = V_99 -> V_24 -> V_6 ;
}
if ( V_99 -> V_25 == V_148 ) {
V_150 = true ;
break;
}
}
if ( V_150 ) {
F_16 ( V_10 , L_48 ) ;
V_99 -> V_26 = V_149 ;
}
}
static void F_77 ( struct V_9 * V_10 , int V_69 ,
union V_3 * V_4 , T_2 V_152 )
{
unsigned int V_70 ;
unsigned int V_71 ;
struct V_11 * V_99 ;
struct V_98 * V_92 ;
struct V_73 * V_74 ;
struct V_107 * V_108 ;
struct V_153 * V_154 ;
V_70 = F_68 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_71 = F_78 ( F_3 ( V_4 -> V_30 . V_31 [ 2 ] ) ) ;
V_92 = V_10 -> V_75 [ V_69 ] ;
V_74 = & V_92 -> V_76 [ V_70 ] ;
V_99 = F_79 ( V_92 , V_70 , V_71 ) ;
if ( ! V_99 ) {
F_32 ( V_10 , L_49 ,
V_71 ) ;
V_92 -> V_76 [ V_70 ] . V_77 &= ~ V_79 ;
return;
}
V_108 = F_48 ( V_10 , V_92 -> V_109 , V_70 ) ;
V_154 = F_80 ( V_10 , V_92 -> V_109 ) ;
if ( V_152 != V_155 ) {
unsigned int V_77 ;
unsigned int V_156 ;
switch ( V_152 ) {
case V_157 :
F_32 ( V_10 , L_50 ) ;
break;
case V_158 :
F_32 ( V_10 , L_51 ) ;
V_77 = F_3 ( V_108 -> V_159 ) ;
V_77 &= V_160 ;
V_156 = F_3 ( V_154 -> V_161 ) ;
V_156 = F_81 ( V_156 ) ;
F_46 ( V_10 , V_102 ,
L_52 ,
V_156 , V_77 ) ;
break;
case V_162 :
F_32 ( V_10 , L_53 ,
V_69 ) ;
break;
default:
F_32 ( V_10 , L_54 ,
V_152 ) ;
break;
}
} else {
T_3 V_110 ;
if ( V_74 -> V_77 & V_81 ) {
struct V_103 * V_104 =
& V_74 -> V_83 -> V_105 [ V_71 ] ;
V_110 = F_47 ( V_104 -> V_106 ) & V_163 ;
} else {
V_110 = F_47 ( V_108 -> V_110 ) & ~ V_164 ;
}
F_46 ( V_10 , V_102 ,
L_55 , V_110 ) ;
if ( F_1 ( V_74 -> V_165 ,
V_74 -> V_151 ) == V_110 ) {
F_76 ( V_10 , V_92 ,
V_99 , V_70 ) ;
} else {
F_32 ( V_10 , L_56 ) ;
F_32 ( V_10 , L_57 ,
V_74 -> V_165 , V_74 -> V_151 ) ;
}
}
V_92 -> V_76 [ V_70 ] . V_77 &= ~ V_79 ;
V_92 -> V_76 [ V_70 ] . V_165 = NULL ;
V_92 -> V_76 [ V_70 ] . V_151 = NULL ;
F_39 ( V_10 , V_69 , V_70 ) ;
}
static void F_82 ( struct V_9 * V_10 , int V_69 ,
union V_3 * V_4 , T_2 V_152 )
{
unsigned int V_70 ;
V_70 = F_68 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
F_46 ( V_10 , V_166 ,
L_58 , V_152 ) ;
if ( V_10 -> V_35 & V_167 ) {
F_46 ( V_10 , V_168 ,
L_59 ) ;
F_83 ( V_10 ,
V_10 -> V_75 [ V_69 ] -> V_169 -> V_8 , V_69 ,
false ) ;
F_15 ( V_10 ) ;
} else {
V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] . V_77 &= ~ V_80 ;
F_39 ( V_10 , V_69 , V_70 ) ;
}
}
static void F_84 ( struct V_9 * V_10 ,
struct V_56 * V_57 , T_2 V_121 )
{
V_57 -> V_121 = V_121 ;
F_85 ( & V_57 -> V_170 ) ;
if ( V_57 -> V_171 )
F_86 ( V_57 -> V_171 ) ;
else
F_87 ( V_10 , V_57 ) ;
}
static int F_67 ( struct V_9 * V_10 ,
struct V_98 * V_136 ,
struct V_134 * V_135 )
{
struct V_56 * V_57 ;
if ( F_40 ( & V_136 -> V_170 ) )
return 0 ;
V_57 = F_70 ( V_136 -> V_170 . V_14 ,
struct V_56 , V_170 ) ;
if ( V_10 -> V_49 -> V_25 != V_57 -> V_172 )
return 0 ;
F_84 ( V_10 , V_57 ,
F_88 ( F_3 ( V_135 -> V_121 ) ) ) ;
return 1 ;
}
static void F_89 ( struct V_9 * V_10 , struct V_59 * V_173 )
{
struct V_1 * V_88 ;
union V_3 * V_58 ;
T_2 V_27 ;
if ( V_10 -> V_49 -> V_25 == V_10 -> V_49 -> V_20 )
return;
V_88 = F_41 ( V_10 -> V_49 -> V_15 ,
V_10 -> V_49 -> V_25 , & V_27 ) ;
if ( ! V_88 ) {
F_32 ( V_10 , L_60 ,
V_10 -> V_49 -> V_25 ,
( unsigned long long )
F_1 ( V_10 -> V_49 -> V_24 ,
V_10 -> V_49 -> V_25 ) ) ;
F_90 ( V_10 , V_10 -> V_49 ) ;
F_91 ( V_10 , V_10 -> V_49 ) ;
return;
}
for ( V_58 = V_10 -> V_49 -> V_25 ;
V_58 != V_10 -> V_49 -> V_20 ;
F_8 ( V_10 , V_10 -> V_49 , & V_88 , & V_58 ) ) {
if ( F_5 ( V_58 -> V_30 . V_31 [ 3 ] ) )
continue;
if ( V_173 -> V_58 == V_58 ) {
if ( V_173 -> V_57 )
F_84 ( V_10 ,
V_173 -> V_57 , V_174 ) ;
V_27 = F_3 ( V_58 -> V_30 . V_31 [ 3 ] )
& V_37 ;
V_58 -> V_30 . V_31 [ 0 ] = 0 ;
V_58 -> V_30 . V_31 [ 1 ] = 0 ;
V_58 -> V_30 . V_31 [ 2 ] = 0 ;
V_58 -> V_30 . V_31 [ 3 ] = F_12 (
F_51 ( V_175 ) | V_27 ) ;
break;
}
}
}
static void F_92 ( struct V_9 * V_10 )
{
struct V_59 * V_173 , * V_176 ;
if ( F_40 ( & V_10 -> V_63 ) )
return;
F_93 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
F_89 ( V_10 , V_173 ) ;
F_85 ( & V_173 -> V_63 ) ;
F_94 ( V_173 ) ;
}
}
static int F_95 ( struct V_9 * V_10 ,
union V_3 * V_58 )
{
struct V_59 * V_173 , * V_176 ;
if ( F_40 ( & V_10 -> V_63 ) )
return 0 ;
F_93 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
if ( V_173 -> V_58 == V_58 ) {
if ( V_173 -> V_57 )
F_84 ( V_10 ,
V_173 -> V_57 , V_174 ) ;
F_85 ( & V_173 -> V_63 ) ;
F_94 ( V_173 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_96 ( struct V_9 * V_10 ,
int V_177 )
{
int V_178 = 0 ;
V_178 = F_95 ( V_10 ,
V_10 -> V_49 -> V_25 ) ;
if ( V_177 == V_179 )
V_10 -> V_41 = V_180 ;
else if ( V_177 == V_174 ) {
F_92 ( V_10 ) ;
V_10 -> V_41 = V_42 ;
if ( V_10 -> V_49 -> V_25 != V_10 -> V_49 -> V_20 )
F_15 ( V_10 ) ;
}
return V_178 ;
}
static void F_97 ( struct V_9 * V_10 , int V_69 ,
T_2 V_152 )
{
if ( V_152 == V_155 )
V_10 -> V_69 = V_69 ;
else
V_10 -> V_69 = 0 ;
F_86 ( & V_10 -> V_181 ) ;
}
static void F_98 ( struct V_9 * V_10 , int V_69 )
{
struct V_98 * V_136 ;
V_136 = V_10 -> V_75 [ V_69 ] ;
if ( ! V_136 )
return;
if ( V_10 -> V_35 & V_182 )
F_99 ( V_10 , V_136 , true ) ;
F_100 ( V_10 , V_69 ) ;
}
static void F_101 ( struct V_9 * V_10 , int V_69 ,
struct V_134 * V_135 , T_2 V_152 )
{
struct V_98 * V_136 ;
struct V_183 * V_184 ;
unsigned int V_70 ;
unsigned int V_77 ;
T_2 V_185 , V_186 ;
V_136 = V_10 -> V_75 [ V_69 ] ;
if ( F_67 ( V_10 , V_136 , V_135 ) )
return;
V_184 = F_102 ( V_10 , V_136 -> V_169 ) ;
if ( ! V_184 ) {
F_32 ( V_10 , L_61 ) ;
return;
}
V_185 = F_3 ( V_184 -> V_185 ) ;
V_186 = F_3 ( V_184 -> V_186 ) ;
V_70 = F_103 ( V_185 ) - 1 ;
if ( V_10 -> V_35 & V_167 &&
V_70 != ( unsigned int ) - 1 &&
V_185 - V_187 == V_186 ) {
V_77 = V_136 -> V_76 [ V_70 ] . V_77 ;
if ( ! ( V_77 & V_80 ) )
goto V_188;
F_46 ( V_10 , V_168 ,
L_62
L_63 ,
V_70 , V_77 ) ;
V_136 -> V_76 [ V_70 ] . V_77 &= ~ V_80 ;
F_39 ( V_10 , V_69 , V_70 ) ;
return;
}
V_188:
F_46 ( V_10 , V_189 ,
L_64 ) ;
V_136 -> V_190 = V_152 ;
F_86 ( & V_136 -> V_191 ) ;
return;
}
static void F_104 ( struct V_9 * V_10 , int V_69 ,
struct V_134 * V_135 , T_2 V_152 )
{
struct V_98 * V_136 ;
V_136 = V_10 -> V_75 [ V_69 ] ;
if ( F_67 ( V_10 , V_136 , V_135 ) )
return;
V_136 -> V_190 = V_152 ;
F_86 ( & V_136 -> V_191 ) ;
}
static void F_105 ( struct V_9 * V_10 , int V_69 ,
T_2 V_152 )
{
V_10 -> V_75 [ V_69 ] -> V_190 = V_152 ;
F_86 ( & V_10 -> V_181 ) ;
}
static void F_106 ( struct V_9 * V_10 , int V_69 ,
struct V_134 * V_135 )
{
struct V_98 * V_136 ;
F_16 ( V_10 , L_65 ) ;
V_136 = V_10 -> V_75 [ V_69 ] ;
if ( V_136 )
F_67 ( V_10 , V_136 , V_135 ) ;
else
F_32 ( V_10 , L_66
L_67 , V_69 ) ;
}
static void F_107 ( struct V_9 * V_10 ,
struct V_134 * V_135 )
{
if ( ! ( V_10 -> V_35 & V_192 ) ) {
V_10 -> V_193 |= 1 << 6 ;
return;
}
F_46 ( V_10 , V_168 ,
L_68 ,
F_108 ( F_3 ( V_135 -> V_121 ) ) ,
F_109 ( F_3 ( V_135 -> V_121 ) ) ) ;
}
static void F_110 ( struct V_9 * V_10 ,
struct V_134 * V_135 )
{
int V_69 = F_111 ( F_3 ( V_135 -> V_65 ) ) ;
T_3 V_194 ;
T_1 V_195 ;
T_2 V_152 ;
union V_3 * V_58 ;
T_2 V_196 ;
V_194 = F_47 ( V_135 -> V_58 ) ;
V_58 = V_10 -> V_49 -> V_25 ;
V_195 = F_1 ( V_10 -> V_49 -> V_24 ,
V_58 ) ;
if ( V_195 == 0 ) {
V_10 -> V_193 |= 1 << 4 ;
return;
}
if ( V_194 != ( T_3 ) V_195 ) {
V_10 -> V_193 |= 1 << 5 ;
return;
}
F_112 ( V_58 , (struct V_89 * ) V_135 ) ;
V_152 = F_88 ( F_3 ( V_135 -> V_121 ) ) ;
if ( V_152 == V_179 || V_152 == V_174 ) {
if ( F_96 ( V_10 , V_152 ) ) {
F_9 ( V_10 , V_10 -> V_49 ) ;
return;
}
if ( V_10 -> V_49 -> V_25 == V_10 -> V_49 -> V_20 )
return;
}
V_196 = F_113 ( F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ;
switch ( V_196 ) {
case V_197 :
F_97 ( V_10 , V_69 , V_152 ) ;
break;
case V_198 :
F_98 ( V_10 , V_69 ) ;
break;
case V_199 :
F_101 ( V_10 , V_69 , V_135 , V_152 ) ;
break;
case V_200 :
F_104 ( V_10 , V_69 , V_135 , V_152 ) ;
break;
case V_201 :
F_105 ( V_10 , V_69 , V_152 ) ;
break;
case V_202 :
F_49 ( V_69 != F_111 (
F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ) ;
F_65 ( V_10 , V_69 , V_58 , V_135 ) ;
break;
case V_203 :
F_49 ( V_69 != F_111 (
F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ) ;
F_77 ( V_10 , V_69 , V_58 , V_152 ) ;
break;
case V_175 :
break;
case V_204 :
F_49 ( V_69 != F_111 (
F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ) ;
F_82 ( V_10 , V_69 , V_58 , V_152 ) ;
break;
case V_205 :
F_49 ( V_69 != F_111 (
F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ) ;
F_106 ( V_10 , V_69 , V_135 ) ;
break;
case V_206 :
F_107 ( V_10 , V_135 ) ;
break;
default:
V_10 -> V_193 |= 1 << 6 ;
break;
}
F_9 ( V_10 , V_10 -> V_49 ) ;
}
static void F_114 ( struct V_9 * V_10 ,
union V_3 * V_135 )
{
T_2 V_207 ;
V_207 = F_113 ( F_3 ( V_135 -> V_30 . V_31 [ 3 ] ) ) ;
F_16 ( V_10 , L_69 , V_207 ) ;
if ( V_207 == V_208 && ( V_10 -> V_35 & V_192 ) )
F_110 ( V_10 , & V_135 -> V_209 ) ;
}
static unsigned int F_115 ( struct V_122 * V_123 ,
struct V_9 * V_10 , T_2 V_210 )
{
unsigned int V_145 ;
unsigned int V_211 = 0 ;
for ( V_145 = 0 ; V_145 < ( V_210 - 1 ) ; V_145 ++ ) {
T_6 V_212 = V_10 -> V_213 [ V_145 ] ;
if ( V_212 == 0 || V_212 == V_214 )
continue;
if ( ( V_212 == 0x03 ) == ( V_123 -> V_215 == V_216 ) )
V_211 ++ ;
}
return V_211 ;
}
static void F_116 ( struct V_9 * V_10 ,
union V_3 * V_135 )
{
T_2 V_69 ;
struct V_217 * V_218 ;
V_69 = F_111 ( F_3 ( V_135 -> V_30 . V_31 [ 3 ] ) ) ;
if ( ! V_10 -> V_75 [ V_69 ] ) {
F_32 ( V_10 , L_70
L_71 , V_69 ) ;
return;
}
F_16 ( V_10 , L_72 ,
V_69 ) ;
V_218 = V_10 -> V_75 [ V_69 ] -> V_218 ;
if ( V_218 && V_218 -> V_219 )
F_117 ( V_218 -> V_219 , V_218 -> V_220 ) ;
}
static void F_118 ( struct V_9 * V_10 ,
union V_3 * V_135 )
{
struct V_122 * V_123 ;
T_2 V_210 ;
T_2 V_221 , V_222 ;
int V_223 ;
int V_69 ;
unsigned int V_224 ;
T_6 V_225 ;
struct V_226 * V_227 ;
T_4 T_5 * * V_213 ;
bool V_228 = false ;
if ( F_88 ( F_3 ( V_135 -> V_30 . V_31 [ 2 ] ) ) != V_155 ) {
F_32 ( V_10 , L_73 ) ;
V_10 -> V_193 |= 1 << 8 ;
}
V_210 = F_119 ( F_3 ( V_135 -> V_30 . V_31 [ 0 ] ) ) ;
F_16 ( V_10 , L_74 , V_210 ) ;
V_223 = F_120 ( V_10 -> V_229 ) ;
if ( ( V_210 <= 0 ) || ( V_210 > V_223 ) ) {
F_32 ( V_10 , L_75 , V_210 ) ;
F_9 ( V_10 , V_10 -> V_13 ) ;
return;
}
V_225 = V_10 -> V_213 [ V_210 - 1 ] ;
V_123 = F_36 ( V_10 ) ;
if ( ( V_225 == 0x03 ) != ( V_123 -> V_215 == V_216 ) )
V_123 = V_10 -> V_230 ;
if ( V_225 == 0 ) {
F_32 ( V_10 , L_76
L_77 ,
V_210 ) ;
V_228 = true ;
goto V_231;
}
if ( V_225 == V_214 ) {
F_32 ( V_10 , L_78
L_77 ,
V_210 ) ;
V_228 = true ;
goto V_231;
}
V_227 = & V_10 -> V_227 [ F_121 ( V_123 ) ] ;
if ( V_123 -> V_215 == V_216 )
V_213 = V_10 -> V_232 ;
else
V_213 = V_10 -> V_233 ;
V_224 = F_115 ( V_123 , V_10 ,
V_210 ) ;
V_221 = F_18 ( V_213 [ V_224 ] ) ;
if ( V_123 -> V_97 == V_234 ) {
F_16 ( V_10 , L_79 ) ;
F_122 ( V_123 ) ;
}
if ( ( V_221 & V_235 ) && ( V_221 & V_236 ) == V_237 ) {
F_16 ( V_10 , L_80 , V_210 ) ;
V_222 = F_18 ( & V_10 -> V_48 -> V_57 ) ;
if ( ! ( V_222 & V_238 ) ) {
F_32 ( V_10 , L_81 ) ;
goto V_231;
}
if ( F_123 ( V_221 ) ) {
F_16 ( V_10 , L_82 , V_210 ) ;
V_227 -> V_239 |= 1 << V_224 ;
F_124 ( V_10 , V_213 ,
V_224 , V_235 ) ;
F_125 ( V_10 , V_213 , V_224 ,
V_240 ) ;
V_228 = true ;
goto V_231;
} else {
F_16 ( V_10 , L_83 , V_210 ) ;
V_227 -> V_241 [ V_224 ] = V_242 +
F_126 ( 20 ) ;
F_127 ( V_224 , & V_227 -> V_243 ) ;
F_128 ( & V_123 -> V_244 ,
V_227 -> V_241 [ V_224 ] ) ;
}
}
if ( ( V_221 & V_235 ) && ( V_221 & V_236 ) == V_240 &&
F_123 ( V_221 ) ) {
F_16 ( V_10 , L_84 , V_210 ) ;
V_69 = F_129 ( V_123 , V_10 ,
V_224 + 1 ) ;
if ( V_69 && V_10 -> V_75 [ V_69 ] )
F_130 ( V_10 , V_69 ) ;
if ( V_227 -> V_239 & ( 1 << V_224 ) ) {
V_227 -> V_239 &=
~ ( 1 << V_224 ) ;
F_124 ( V_10 , V_213 ,
V_224 , V_235 ) ;
F_117 ( V_123 -> V_131 . V_245 ,
V_224 + 1 ) ;
V_228 = true ;
goto V_231;
}
}
if ( ! F_123 ( V_221 ) &&
F_131 ( V_224 ,
& V_227 -> V_246 ) ) {
F_86 ( & V_227 -> V_247 [ V_224 ] ) ;
V_228 = true ;
goto V_231;
}
if ( V_123 -> V_215 != V_216 )
F_124 ( V_10 , V_213 , V_224 ,
V_235 ) ;
V_231:
F_9 ( V_10 , V_10 -> V_13 ) ;
if ( V_228 )
return;
F_16 ( V_10 , L_85 , V_248 ) ;
F_127 ( V_249 , & V_123 -> V_65 ) ;
F_61 ( & V_10 -> V_66 ) ;
F_132 ( V_123 ) ;
F_64 ( & V_10 -> V_66 ) ;
}
struct V_1 * F_133 ( struct V_1 * V_87 ,
union V_3 * V_250 ,
union V_3 * V_251 ,
T_1 V_252 )
{
T_1 V_253 ;
T_1 V_254 ;
T_1 V_255 ;
struct V_1 * V_88 ;
V_253 = F_1 ( V_87 , V_250 ) ;
V_88 = V_87 ;
do {
if ( V_253 == 0 )
return NULL ;
V_254 = F_1 ( V_88 ,
& V_88 -> V_6 [ V_7 - 1 ] ) ;
V_255 = F_1 ( V_88 , V_251 ) ;
if ( V_255 > 0 ) {
if ( V_253 <= V_255 ) {
if ( V_252 >= V_253 && V_252 <= V_255 )
return V_88 ;
} else {
if ( ( V_252 >= V_253 &&
V_252 <= V_254 ) ||
( V_252 >= V_88 -> V_8 &&
V_252 <= V_255 ) )
return V_88 ;
}
return NULL ;
} else {
if ( V_252 >= V_253 && V_252 <= V_254 )
return V_88 ;
}
V_88 = V_88 -> V_14 ;
V_253 = F_1 ( V_88 , & V_88 -> V_6 [ 0 ] ) ;
} while ( V_88 != V_87 );
return NULL ;
}
static void F_134 ( struct V_9 * V_10 ,
unsigned int V_69 , unsigned int V_70 ,
unsigned int V_71 ,
struct V_94 * V_256 , union V_3 * V_257 )
{
struct V_73 * V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
V_74 -> V_77 |= V_80 ;
V_74 -> V_141 = V_256 ;
V_74 -> V_258 = V_71 ;
F_135 ( V_10 , V_69 , V_70 ) ;
F_136 ( V_10 , V_256 -> V_91 -> V_92 , V_70 ) ;
V_74 -> V_141 = NULL ;
V_74 -> V_258 = 0 ;
F_15 ( V_10 ) ;
}
static int F_137 ( struct V_9 * V_10 ,
struct V_107 * V_108 ,
unsigned int V_259 )
{
if ( V_259 == V_260 ||
V_259 == V_261 ||
V_259 == V_262 )
if ( ( V_108 -> V_159 & F_12 ( V_160 ) ) ==
F_12 ( V_263 ) )
return 1 ;
return 0 ;
}
int F_138 ( struct V_9 * V_10 , unsigned int V_259 )
{
if ( V_259 >= 224 && V_259 <= 255 ) {
F_16 ( V_10 , L_86 ,
V_259 ) ;
F_16 ( V_10 , L_87 ) ;
return 1 ;
}
return 0 ;
}
static int F_139 ( struct V_9 * V_10 , struct V_94 * V_256 ,
union V_3 * V_257 , struct V_264 * V_135 ,
struct V_73 * V_74 , int * V_121 , bool V_265 )
{
struct V_98 * V_266 ;
struct V_11 * V_99 ;
unsigned int V_69 ;
int V_70 ;
struct V_91 * V_91 = NULL ;
struct V_107 * V_108 ;
int V_47 = 0 ;
struct V_124 * V_124 ;
T_2 V_259 ;
V_69 = F_111 ( F_3 ( V_135 -> V_65 ) ) ;
V_266 = V_10 -> V_75 [ V_69 ] ;
V_70 = F_140 ( F_3 ( V_135 -> V_65 ) ) - 1 ;
V_99 = F_141 ( V_74 , F_47 ( V_135 -> V_267 ) ) ;
V_108 = F_48 ( V_10 , V_266 -> V_109 , V_70 ) ;
V_259 = F_88 ( F_3 ( V_135 -> V_268 ) ) ;
if ( V_265 )
goto V_269;
if ( V_259 == V_270 ||
V_259 == V_271 ) {
V_74 -> V_141 = V_256 ;
return 0 ;
} else {
if ( V_259 == V_272 ) {
V_74 -> V_141 = V_256 ;
V_74 -> V_258 = V_99 -> V_71 ;
} else if ( F_137 ( V_10 ,
V_108 , V_259 ) ) {
F_134 ( V_10 ,
V_69 , V_70 , V_99 -> V_71 ,
V_256 , V_257 ) ;
} else {
while ( V_99 -> V_25 != V_256 -> F_4 )
F_9 ( V_10 , V_99 ) ;
F_9 ( V_10 , V_99 ) ;
}
V_269:
V_91 = V_256 -> V_91 ;
V_124 = V_91 -> V_125 ;
if ( V_91 -> V_273 > V_91 -> V_274 ) {
F_32 ( V_10 , L_88
L_89
L_90 ,
V_91 -> V_274 ,
V_91 -> V_273 ) ;
V_91 -> V_273 = 0 ;
if ( V_256 -> V_91 -> V_275 & V_276 )
* V_121 = - V_277 ;
else
* V_121 = 0 ;
}
F_71 ( & V_256 -> V_82 ) ;
if ( ! F_40 ( & V_256 -> V_140 ) )
F_71 ( & V_256 -> V_140 ) ;
V_124 -> V_126 ++ ;
if ( V_124 -> V_126 == V_124 -> V_128 ) {
V_47 = 1 ;
if ( F_58 ( V_91 -> V_129 ) == V_130 ) {
F_36 ( V_10 ) -> V_131 . V_132 -- ;
if ( F_36 ( V_10 ) -> V_131 . V_132
== 0 ) {
if ( V_10 -> V_35 & V_133 )
F_59 () ;
}
}
}
}
return V_47 ;
}
static int F_142 ( struct V_9 * V_10 , struct V_94 * V_256 ,
union V_3 * V_257 , struct V_264 * V_135 ,
struct V_73 * V_74 , int * V_121 )
{
struct V_98 * V_266 ;
struct V_11 * V_99 ;
unsigned int V_69 ;
int V_70 ;
struct V_107 * V_108 ;
T_2 V_259 ;
V_69 = F_111 ( F_3 ( V_135 -> V_65 ) ) ;
V_266 = V_10 -> V_75 [ V_69 ] ;
V_70 = F_140 ( F_3 ( V_135 -> V_65 ) ) - 1 ;
V_99 = F_141 ( V_74 , F_47 ( V_135 -> V_267 ) ) ;
V_108 = F_48 ( V_10 , V_266 -> V_109 , V_70 ) ;
V_259 = F_88 ( F_3 ( V_135 -> V_268 ) ) ;
switch ( V_259 ) {
case V_155 :
if ( V_257 == V_99 -> V_25 ) {
F_32 ( V_10 , L_91
L_92 ) ;
* V_121 = - V_55 ;
} else if ( V_257 != V_256 -> F_4 ) {
F_32 ( V_10 , L_93
L_92 ) ;
* V_121 = - V_55 ;
} else {
* V_121 = 0 ;
}
break;
case V_278 :
if ( V_256 -> V_91 -> V_275 & V_276 )
* V_121 = - V_277 ;
else
* V_121 = 0 ;
break;
case V_270 :
case V_271 :
return F_139 ( V_10 , V_256 , V_257 , V_135 , V_74 , V_121 , false ) ;
default:
if ( ! F_137 ( V_10 ,
V_108 , V_259 ) )
break;
F_16 ( V_10 , L_94
L_95 ,
V_259 , V_70 ) ;
case V_272 :
if ( V_257 != V_99 -> V_25 &&
V_257 != V_256 -> F_4 )
V_256 -> V_91 -> V_273 =
V_256 -> V_91 -> V_274 -
F_143 ( F_3 ( V_135 -> V_268 ) ) ;
else
V_256 -> V_91 -> V_273 = 0 ;
F_134 ( V_10 ,
V_69 , V_70 , 0 , V_256 , V_257 ) ;
return F_139 ( V_10 , V_256 , V_257 , V_135 , V_74 , V_121 , true ) ;
}
if ( V_257 != V_99 -> V_25 ) {
if ( V_257 == V_256 -> F_4 ) {
if ( V_256 -> V_91 -> V_273 != 0 ) {
if ( ( * V_121 == - V_279 || * V_121 == 0 ) &&
( V_256 -> V_91 -> V_275
& V_276 ) )
* V_121 = - V_277 ;
} else {
V_256 -> V_91 -> V_273 =
V_256 -> V_91 -> V_274 ;
}
} else {
V_256 -> V_91 -> V_273 =
V_256 -> V_91 -> V_274 -
F_143 ( F_3 ( V_135 -> V_268 ) ) ;
F_16 ( V_10 , L_96
L_97 ) ;
return 0 ;
}
}
return F_139 ( V_10 , V_256 , V_257 , V_135 , V_74 , V_121 , false ) ;
}
static int F_144 ( struct V_9 * V_10 , struct V_94 * V_256 ,
union V_3 * V_257 , struct V_264 * V_135 ,
struct V_73 * V_74 , int * V_121 )
{
struct V_11 * V_99 ;
struct V_124 * V_124 ;
int V_280 ;
int V_281 = 0 ;
union V_3 * V_115 ;
struct V_1 * V_88 ;
struct V_282 * V_283 ;
T_2 V_259 ;
bool V_284 = false ;
V_99 = F_141 ( V_74 , F_47 ( V_135 -> V_267 ) ) ;
V_259 = F_88 ( F_3 ( V_135 -> V_268 ) ) ;
V_124 = V_256 -> V_91 -> V_125 ;
V_280 = V_124 -> V_126 ;
V_283 = & V_256 -> V_91 -> V_285 [ V_280 ] ;
switch ( V_259 ) {
case V_155 :
if ( F_143 ( F_3 ( V_135 -> V_268 ) ) == 0 ) {
V_283 -> V_121 = 0 ;
break;
}
if ( ( V_10 -> V_35 & V_286 ) )
V_259 = V_278 ;
case V_278 :
V_283 -> V_121 = V_256 -> V_91 -> V_275 & V_276 ?
- V_277 : 0 ;
break;
case V_287 :
V_283 -> V_121 = - V_288 ;
V_284 = true ;
break;
case V_289 :
case V_261 :
V_283 -> V_121 = - V_290 ;
V_284 = true ;
break;
case V_291 :
case V_272 :
case V_260 :
V_283 -> V_121 = - V_292 ;
V_284 = true ;
break;
case V_271 :
case V_270 :
break;
default:
V_283 -> V_121 = - 1 ;
break;
}
if ( V_259 == V_155 || V_284 ) {
V_283 -> V_273 = V_283 -> V_128 ;
V_256 -> V_91 -> V_273 += V_283 -> V_128 ;
} else {
for ( V_115 = V_99 -> V_25 ,
V_88 = V_99 -> V_24 ; V_115 != V_257 ;
F_8 ( V_10 , V_99 , & V_88 , & V_115 ) ) {
if ( ! F_145 ( V_115 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_115 -> V_30 . V_31 [ 3 ] ) )
V_281 += F_146 ( F_3 ( V_115 -> V_30 . V_31 [ 2 ] ) ) ;
}
V_281 += F_146 ( F_3 ( V_115 -> V_30 . V_31 [ 2 ] ) ) -
F_143 ( F_3 ( V_135 -> V_268 ) ) ;
if ( V_259 != V_270 ) {
V_283 -> V_273 = V_281 ;
V_256 -> V_91 -> V_273 += V_281 ;
}
}
return F_139 ( V_10 , V_256 , V_257 , V_135 , V_74 , V_121 , false ) ;
}
static int F_147 ( struct V_9 * V_10 , struct V_94 * V_256 ,
struct V_264 * V_135 ,
struct V_73 * V_74 , int * V_121 )
{
struct V_11 * V_99 ;
struct V_124 * V_124 ;
struct V_282 * V_283 ;
int V_280 ;
V_99 = F_141 ( V_74 , F_47 ( V_135 -> V_267 ) ) ;
V_124 = V_256 -> V_91 -> V_125 ;
V_280 = V_124 -> V_126 ;
V_283 = & V_256 -> V_91 -> V_285 [ V_280 ] ;
V_283 -> V_121 = - V_293 ;
V_283 -> V_273 = 0 ;
while ( V_99 -> V_25 != V_256 -> F_4 )
F_9 ( V_10 , V_99 ) ;
F_9 ( V_10 , V_99 ) ;
return F_139 ( V_10 , V_256 , NULL , V_135 , V_74 , V_121 , true ) ;
}
static int F_148 ( struct V_9 * V_10 , struct V_94 * V_256 ,
union V_3 * V_257 , struct V_264 * V_135 ,
struct V_73 * V_74 , int * V_121 )
{
struct V_11 * V_99 ;
union V_3 * V_115 ;
struct V_1 * V_88 ;
T_2 V_259 ;
V_99 = F_141 ( V_74 , F_47 ( V_135 -> V_267 ) ) ;
V_259 = F_88 ( F_3 ( V_135 -> V_268 ) ) ;
switch ( V_259 ) {
case V_155 :
if ( V_257 != V_256 -> F_4 ||
F_143 ( F_3 ( V_135 -> V_268 ) ) != 0 ) {
F_32 ( V_10 , L_98
L_99 ) ;
if ( V_256 -> V_91 -> V_275 & V_276 )
* V_121 = - V_277 ;
else
* V_121 = 0 ;
if ( ( V_10 -> V_35 & V_286 ) )
V_259 = V_278 ;
} else {
* V_121 = 0 ;
}
break;
case V_278 :
if ( V_256 -> V_91 -> V_275 & V_276 )
* V_121 = - V_277 ;
else
* V_121 = 0 ;
break;
default:
break;
}
if ( V_259 == V_278 )
F_16 ( V_10 , L_100
L_101 ,
V_256 -> V_91 -> V_74 -> V_93 . V_294 ,
V_256 -> V_91 -> V_274 ,
F_143 ( F_3 ( V_135 -> V_268 ) ) ) ;
if ( V_257 == V_256 -> F_4 ) {
if ( F_143 ( F_3 ( V_135 -> V_268 ) ) != 0 ) {
V_256 -> V_91 -> V_273 =
V_256 -> V_91 -> V_274 -
F_143 ( F_3 ( V_135 -> V_268 ) ) ;
if ( V_256 -> V_91 -> V_274 <
V_256 -> V_91 -> V_273 ) {
F_32 ( V_10 , L_102
L_103 ,
F_143 ( F_3 ( V_135 -> V_268 ) ) ) ;
V_256 -> V_91 -> V_273 = 0 ;
if ( V_256 -> V_91 -> V_275 & V_276 )
* V_121 = - V_277 ;
else
* V_121 = 0 ;
}
if ( * V_121 == - V_279 ) {
if ( V_256 -> V_91 -> V_275 & V_276 )
* V_121 = - V_277 ;
else
* V_121 = 0 ;
}
} else {
V_256 -> V_91 -> V_273 =
V_256 -> V_91 -> V_274 ;
if ( * V_121 == - V_277 )
* V_121 = 0 ;
}
} else {
V_256 -> V_91 -> V_273 = 0 ;
for ( V_115 = V_99 -> V_25 , V_88 = V_99 -> V_24 ;
V_115 != V_257 ;
F_8 ( V_10 , V_99 , & V_88 , & V_115 ) ) {
if ( ! F_145 ( V_115 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_115 -> V_30 . V_31 [ 3 ] ) )
V_256 -> V_91 -> V_273 +=
F_146 ( F_3 ( V_115 -> V_30 . V_31 [ 2 ] ) ) ;
}
if ( V_259 != V_270 )
V_256 -> V_91 -> V_273 +=
F_146 ( F_3 ( V_115 -> V_30 . V_31 [ 2 ] ) ) -
F_143 ( F_3 ( V_135 -> V_268 ) ) ;
}
return F_139 ( V_10 , V_256 , V_257 , V_135 , V_74 , V_121 , false ) ;
}
static int F_149 ( struct V_9 * V_10 ,
struct V_264 * V_135 )
__releases( &xhci->lock
static int F_150 ( struct V_9 * V_10 )
{
union V_3 * V_135 ;
int V_295 = 1 ;
int V_47 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_25 ) {
V_10 -> V_193 |= 1 << 1 ;
return 0 ;
}
V_135 = V_10 -> V_13 -> V_25 ;
if ( ( F_3 ( V_135 -> V_209 . V_65 ) & V_37 ) !=
V_10 -> V_13 -> V_27 ) {
V_10 -> V_193 |= 1 << 2 ;
return 0 ;
}
F_151 () ;
switch ( ( F_3 ( V_135 -> V_209 . V_65 ) & V_296 ) ) {
case F_51 ( V_297 ) :
F_110 ( V_10 , & V_135 -> V_209 ) ;
break;
case F_51 ( V_298 ) :
F_118 ( V_10 , V_135 ) ;
V_295 = 0 ;
break;
case F_51 ( V_299 ) :
V_47 = F_149 ( V_10 , & V_135 -> V_300 ) ;
if ( V_47 < 0 )
V_10 -> V_193 |= 1 << 9 ;
else
V_295 = 0 ;
break;
case F_51 ( V_301 ) :
F_116 ( V_10 , V_135 ) ;
break;
default:
if ( ( F_3 ( V_135 -> V_209 . V_65 ) & V_296 ) >=
F_51 ( 48 ) )
F_114 ( V_10 , V_135 ) ;
else
V_10 -> V_193 |= 1 << 3 ;
}
if ( V_10 -> V_53 & V_54 ) {
F_16 ( V_10 , L_104
L_105 ) ;
return 0 ;
}
if ( V_295 )
F_9 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_152 ( struct V_122 * V_123 )
{
struct V_9 * V_10 = F_153 ( V_123 ) ;
T_2 V_121 ;
T_3 V_46 ;
union V_3 * V_302 ;
T_1 V_110 ;
F_64 ( & V_10 -> V_66 ) ;
V_121 = F_18 ( & V_10 -> V_48 -> V_121 ) ;
if ( V_121 == 0xffffffff )
goto V_303;
if ( ! ( V_121 & V_304 ) ) {
F_61 ( & V_10 -> V_66 ) ;
return V_305 ;
}
if ( V_121 & V_306 ) {
F_32 ( V_10 , L_106 ) ;
F_25 ( V_10 ) ;
V_303:
F_61 ( & V_10 -> V_66 ) ;
return - V_55 ;
}
V_121 |= V_304 ;
F_17 ( V_121 , & V_10 -> V_48 -> V_121 ) ;
if ( V_123 -> V_307 ) {
T_2 V_308 ;
V_308 = F_18 ( & V_10 -> V_309 -> V_308 ) ;
V_308 |= V_310 ;
F_17 ( V_308 , & V_10 -> V_309 -> V_308 ) ;
}
if ( V_10 -> V_53 & V_54 ) {
F_16 ( V_10 , L_107
L_108 ) ;
V_46 = F_20 ( V_10 , & V_10 -> V_309 -> V_311 ) ;
F_21 ( V_10 , V_46 | V_312 ,
& V_10 -> V_309 -> V_311 ) ;
F_61 ( & V_10 -> V_66 ) ;
return V_313 ;
}
V_302 = V_10 -> V_13 -> V_25 ;
while ( F_150 ( V_10 ) > 0 ) {}
V_46 = F_20 ( V_10 , & V_10 -> V_309 -> V_311 ) ;
if ( V_302 != V_10 -> V_13 -> V_25 ) {
V_110 = F_1 ( V_10 -> V_13 -> V_24 ,
V_10 -> V_13 -> V_25 ) ;
if ( V_110 == 0 )
F_32 ( V_10 , L_109
L_110 ) ;
V_46 &= V_314 ;
V_46 |= ( ( T_3 ) V_110 & ( T_3 ) ~ V_314 ) ;
}
V_46 |= V_312 ;
F_21 ( V_10 , V_46 , & V_10 -> V_309 -> V_311 ) ;
F_61 ( & V_10 -> V_66 ) ;
return V_313 ;
}
T_7 F_154 ( int V_307 , void * V_123 )
{
return F_152 ( V_123 ) ;
}
static void F_155 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_28 ,
T_2 V_315 , T_2 V_316 , T_2 V_317 , T_2 V_318 )
{
struct V_89 * V_4 ;
V_4 = & V_12 -> V_20 -> V_30 ;
V_4 -> V_31 [ 0 ] = F_12 ( V_315 ) ;
V_4 -> V_31 [ 1 ] = F_12 ( V_316 ) ;
V_4 -> V_31 [ 2 ] = F_12 ( V_317 ) ;
V_4 -> V_31 [ 3 ] = F_12 ( V_318 ) ;
F_10 ( V_10 , V_12 , V_28 ) ;
}
static int F_156 ( struct V_9 * V_10 , struct V_11 * V_99 ,
T_2 V_77 , unsigned int V_38 , T_8 V_319 )
{
unsigned int V_320 ;
switch ( V_77 ) {
case V_321 :
F_32 ( V_10 , L_111 ) ;
return - V_322 ;
case V_323 :
F_32 ( V_10 , L_112 ) ;
return - V_324 ;
case V_263 :
F_16 ( V_10 , L_113 ) ;
case V_325 :
case V_326 :
break;
default:
F_23 ( V_10 , L_114 ) ;
return - V_324 ;
}
while ( 1 ) {
if ( F_14 ( V_10 , V_99 , V_38 ) )
break;
if ( V_99 == V_10 -> V_49 ) {
F_23 ( V_10 , L_115 ) ;
return - V_62 ;
}
F_46 ( V_10 , V_327 ,
L_116 ) ;
V_320 = V_38 - V_99 -> V_26 ;
if ( F_157 ( V_10 , V_99 , V_320 ,
V_319 ) ) {
F_23 ( V_10 , L_117 ) ;
return - V_62 ;
}
}
if ( F_6 ( V_99 ) ) {
struct V_11 * V_12 = V_99 ;
union V_3 * V_14 ;
V_14 = V_12 -> V_20 ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_21 , V_14 ) ) {
if ( ! F_11 ( V_10 ) &&
! ( V_12 -> type == V_34 &&
( V_10 -> V_35 & V_36 ) ) )
V_14 -> V_16 . V_17 &= F_12 ( ~ V_32 ) ;
else
V_14 -> V_16 . V_17 |= F_12 ( V_32 ) ;
F_13 () ;
V_14 -> V_16 . V_17 ^= F_12 ( V_37 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_21 , V_14 ) ) {
V_12 -> V_27 = ( V_12 -> V_27 ? 0 : 1 ) ;
}
V_12 -> V_21 = V_12 -> V_21 -> V_14 ;
V_12 -> V_20 = V_12 -> V_21 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
return 0 ;
}
static int F_158 ( struct V_9 * V_10 ,
struct V_98 * V_266 ,
unsigned int V_70 ,
unsigned int V_71 ,
unsigned int V_38 ,
struct V_91 * V_91 ,
unsigned int V_328 ,
T_8 V_319 )
{
int V_47 ;
struct V_124 * V_124 ;
struct V_94 * V_256 ;
struct V_11 * V_99 ;
struct V_107 * V_108 = F_48 ( V_10 , V_266 -> V_109 , V_70 ) ;
V_99 = F_79 ( V_266 , V_70 , V_71 ) ;
if ( ! V_99 ) {
F_16 ( V_10 , L_118 ,
V_71 ) ;
return - V_324 ;
}
V_47 = F_156 ( V_10 , V_99 ,
F_3 ( V_108 -> V_159 ) & V_160 ,
V_38 , V_319 ) ;
if ( V_47 )
return V_47 ;
V_124 = V_91 -> V_125 ;
V_256 = V_124 -> V_256 [ V_328 ] ;
F_28 ( & V_256 -> V_82 ) ;
F_28 ( & V_256 -> V_140 ) ;
if ( V_328 == 0 ) {
V_47 = F_159 ( F_57 ( V_91 -> V_92 -> V_127 ) , V_91 ) ;
if ( F_33 ( V_47 ) )
return V_47 ;
}
V_256 -> V_91 = V_91 ;
F_29 ( & V_256 -> V_82 , & V_99 -> V_82 ) ;
V_256 -> V_87 = V_99 -> V_21 ;
V_256 -> V_116 = V_99 -> V_20 ;
V_124 -> V_256 [ V_328 ] = V_256 ;
return 0 ;
}
static unsigned int F_160 ( struct V_9 * V_10 , struct V_91 * V_91 )
{
int V_329 , V_38 , V_330 , V_221 , V_145 ;
struct V_331 * V_332 ;
V_332 = NULL ;
V_329 = V_91 -> V_333 ;
V_221 = V_91 -> V_274 ;
V_38 = 0 ;
F_161 (urb->sg, sg, num_sgs, i) {
unsigned int V_281 = F_162 ( V_332 ) ;
V_330 = V_334 -
( F_163 ( V_332 ) & ( V_334 - 1 ) ) ;
V_330 &= V_334 - 1 ;
if ( V_330 != 0 )
V_38 ++ ;
while ( V_330 < F_162 ( V_332 ) && V_330 < V_221 ) {
V_38 ++ ;
V_330 += V_334 ;
}
V_281 = F_164 ( int , V_281 , V_221 ) ;
V_221 -= V_281 ;
if ( V_221 == 0 )
break;
}
return V_38 ;
}
static void F_165 ( struct V_91 * V_91 , int V_38 , int V_330 )
{
if ( V_38 != 0 )
F_166 ( & V_91 -> V_92 -> V_92 , L_119
L_120 , V_248 ,
V_91 -> V_74 -> V_93 . V_294 , V_38 ) ;
if ( V_330 != V_91 -> V_274 )
F_166 ( & V_91 -> V_92 -> V_92 , L_121
L_122 ,
V_248 ,
V_91 -> V_74 -> V_93 . V_294 ,
V_330 , V_330 ,
V_91 -> V_274 ,
V_91 -> V_274 ) ;
}
static void F_167 ( struct V_9 * V_10 , int V_69 ,
unsigned int V_70 , unsigned int V_71 , int V_335 ,
struct V_89 * V_250 )
{
F_13 () ;
if ( V_335 )
V_250 -> V_31 [ 3 ] |= F_12 ( V_335 ) ;
else
V_250 -> V_31 [ 3 ] &= F_12 ( ~ V_37 ) ;
F_37 ( V_10 , V_69 , V_70 , V_71 ) ;
}
int F_168 ( struct V_9 * V_10 , T_8 V_319 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_107 * V_108 = F_48 ( V_10 ,
V_10 -> V_75 [ V_69 ] -> V_109 , V_70 ) ;
int V_336 ;
int V_337 ;
V_336 = F_169 ( F_3 ( V_108 -> V_159 ) ) ;
V_337 = V_91 -> V_338 ;
if ( V_91 -> V_92 -> V_215 == V_339 ||
V_91 -> V_92 -> V_215 == V_340 )
V_337 *= 8 ;
if ( V_336 != V_337 ) {
F_170 ( & V_91 -> V_92 -> V_92 ,
L_123 ,
V_337 , V_337 == 1 ? L_124 : L_125 ,
V_336 , V_336 == 1 ? L_124 : L_125 ) ;
V_91 -> V_338 = V_336 ;
if ( V_91 -> V_92 -> V_215 == V_339 ||
V_91 -> V_92 -> V_215 == V_340 )
V_91 -> V_338 /= 8 ;
}
return F_171 ( V_10 , V_319 , V_91 , V_69 , V_70 ) ;
}
static T_2 F_172 ( unsigned int V_341 )
{
T_2 V_342 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_341 >> 10 ) >= V_342 )
return V_342 << 17 ;
else
return ( V_341 >> 10 ) << 17 ;
}
static T_2 F_173 ( int V_330 , int V_343 ,
unsigned int V_344 , struct V_91 * V_91 ,
unsigned int V_345 )
{
int V_346 ;
if ( V_345 == 0 || ( V_330 == 0 && V_343 == 0 ) )
return 0 ;
V_346 = ( V_330 + V_343 ) /
F_174 ( F_175 ( & V_91 -> V_74 -> V_93 ) ) ;
if ( ( V_344 - V_346 ) > 31 )
return 31 << 17 ;
return ( V_344 - V_346 ) << 17 ;
}
static int F_176 ( struct V_9 * V_10 , T_8 V_319 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_11 * V_99 ;
unsigned int V_38 ;
struct V_124 * V_124 ;
struct V_94 * V_256 ;
struct V_331 * V_332 ;
int V_329 ;
int V_343 , V_347 , V_330 ;
unsigned int V_344 ;
bool V_116 ;
T_3 V_100 ;
bool V_28 ;
struct V_89 * V_250 ;
int V_335 ;
V_99 = F_43 ( V_10 , V_91 ) ;
if ( ! V_99 )
return - V_324 ;
V_38 = F_160 ( V_10 , V_91 ) ;
V_329 = V_91 -> V_333 ;
V_344 = F_177 ( V_91 -> V_274 ,
F_175 ( & V_91 -> V_74 -> V_93 ) ) ;
V_343 = F_158 ( V_10 , V_10 -> V_75 [ V_69 ] ,
V_70 , V_91 -> V_71 ,
V_38 , V_91 , 0 , V_319 ) ;
if ( V_343 < 0 )
return V_343 ;
V_124 = V_91 -> V_125 ;
V_256 = V_124 -> V_256 [ 0 ] ;
V_250 = & V_99 -> V_20 -> V_30 ;
V_335 = V_99 -> V_27 ;
V_330 = 0 ;
V_332 = V_91 -> V_332 ;
V_100 = ( T_3 ) F_163 ( V_332 ) ;
V_347 = F_162 ( V_332 ) ;
V_343 = V_334 - ( V_100 & ( V_334 - 1 ) ) ;
V_343 = F_164 ( int , V_343 , V_347 ) ;
if ( V_343 > V_91 -> V_274 )
V_343 = V_91 -> V_274 ;
V_116 = true ;
do {
T_2 V_31 = 0 ;
T_2 V_348 = 0 ;
T_2 V_341 = 0 ;
if ( V_116 ) {
V_116 = false ;
if ( V_335 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_99 -> V_27 ;
if ( V_38 > 1 ) {
V_31 |= V_32 ;
} else {
V_256 -> F_4 = V_99 -> V_20 ;
V_31 |= V_349 ;
}
if ( F_178 ( V_91 ) )
V_31 |= V_350 ;
if ( V_334 -
( V_100 & ( V_334 - 1 ) ) < V_343 ) {
F_32 ( V_10 , L_126 ) ;
F_16 ( V_10 , L_127 ,
( unsigned int ) ( V_100 + V_334 ) & ~ ( V_334 - 1 ) ,
( unsigned int ) V_100 + V_343 ) ;
}
if ( V_10 -> V_351 < 0x100 ) {
V_341 = F_172 (
V_91 -> V_274 -
V_330 ) ;
} else {
V_341 = F_173 ( V_330 ,
V_343 , V_344 , V_91 ,
V_38 - 1 ) ;
}
V_348 = F_146 ( V_343 ) |
V_341 |
F_179 ( 0 ) ;
if ( V_38 > 1 )
V_28 = true ;
else
V_28 = false ;
F_155 ( V_10 , V_99 , V_28 ,
F_180 ( V_100 ) ,
F_181 ( V_100 ) ,
V_348 ,
V_31 | F_51 ( V_352 ) ) ;
-- V_38 ;
V_330 += V_343 ;
V_347 -= V_343 ;
if ( V_347 == 0 ) {
-- V_329 ;
if ( V_329 == 0 )
break;
V_332 = F_182 ( V_332 ) ;
V_100 = ( T_3 ) F_163 ( V_332 ) ;
V_347 = F_162 ( V_332 ) ;
} else {
V_100 += V_343 ;
}
V_343 = V_334 -
( V_100 & ( V_334 - 1 ) ) ;
V_343 = F_164 ( int , V_343 , V_347 ) ;
if ( V_330 + V_343 > V_91 -> V_274 )
V_343 =
V_91 -> V_274 - V_330 ;
} while ( V_330 < V_91 -> V_274 );
F_165 ( V_91 , V_38 , V_330 ) ;
F_167 ( V_10 , V_69 , V_70 , V_91 -> V_71 ,
V_335 , V_250 ) ;
return 0 ;
}
int F_171 ( struct V_9 * V_10 , T_8 V_319 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_11 * V_99 ;
struct V_124 * V_124 ;
struct V_94 * V_256 ;
int V_38 ;
struct V_89 * V_250 ;
bool V_116 ;
bool V_28 ;
int V_335 ;
T_2 V_31 , V_348 ;
int V_330 , V_343 , V_47 ;
unsigned int V_344 ;
T_3 V_100 ;
if ( V_91 -> V_329 )
return F_176 ( V_10 , V_319 , V_91 , V_69 , V_70 ) ;
V_99 = F_43 ( V_10 , V_91 ) ;
if ( ! V_99 )
return - V_324 ;
V_38 = 0 ;
V_330 = V_334 -
( V_91 -> V_353 & ( V_334 - 1 ) ) ;
V_330 &= V_334 - 1 ;
if ( V_330 != 0 || V_91 -> V_274 == 0 )
V_38 ++ ;
while ( V_330 < V_91 -> V_274 ) {
V_38 ++ ;
V_330 += V_334 ;
}
V_47 = F_158 ( V_10 , V_10 -> V_75 [ V_69 ] ,
V_70 , V_91 -> V_71 ,
V_38 , V_91 , 0 , V_319 ) ;
if ( V_47 < 0 )
return V_47 ;
V_124 = V_91 -> V_125 ;
V_256 = V_124 -> V_256 [ 0 ] ;
V_250 = & V_99 -> V_20 -> V_30 ;
V_335 = V_99 -> V_27 ;
V_330 = 0 ;
V_344 = F_177 ( V_91 -> V_274 ,
F_175 ( & V_91 -> V_74 -> V_93 ) ) ;
V_100 = ( T_3 ) V_91 -> V_353 ;
V_343 = V_334 -
( V_91 -> V_353 & ( V_334 - 1 ) ) ;
if ( V_343 > V_91 -> V_274 )
V_343 = V_91 -> V_274 ;
V_116 = true ;
do {
T_2 V_341 = 0 ;
V_31 = 0 ;
if ( V_116 ) {
V_116 = false ;
if ( V_335 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_99 -> V_27 ;
if ( V_38 > 1 ) {
V_31 |= V_32 ;
} else {
V_256 -> F_4 = V_99 -> V_20 ;
V_31 |= V_349 ;
}
if ( F_178 ( V_91 ) )
V_31 |= V_350 ;
if ( V_10 -> V_351 < 0x100 ) {
V_341 = F_172 (
V_91 -> V_274 -
V_330 ) ;
} else {
V_341 = F_173 ( V_330 ,
V_343 , V_344 , V_91 ,
V_38 - 1 ) ;
}
V_348 = F_146 ( V_343 ) |
V_341 |
F_179 ( 0 ) ;
if ( V_38 > 1 )
V_28 = true ;
else
V_28 = false ;
F_155 ( V_10 , V_99 , V_28 ,
F_180 ( V_100 ) ,
F_181 ( V_100 ) ,
V_348 ,
V_31 | F_51 ( V_352 ) ) ;
-- V_38 ;
V_330 += V_343 ;
V_100 += V_343 ;
V_343 = V_91 -> V_274 - V_330 ;
if ( V_343 > V_334 )
V_343 = V_334 ;
} while ( V_330 < V_91 -> V_274 );
F_165 ( V_91 , V_38 , V_330 ) ;
F_167 ( V_10 , V_69 , V_70 , V_91 -> V_71 ,
V_335 , V_250 ) ;
return 0 ;
}
int F_183 ( struct V_9 * V_10 , T_8 V_319 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_11 * V_99 ;
int V_38 ;
int V_47 ;
struct V_354 * V_355 ;
struct V_89 * V_250 ;
int V_335 ;
T_2 V_31 , V_348 ;
struct V_124 * V_124 ;
struct V_94 * V_256 ;
V_99 = F_43 ( V_10 , V_91 ) ;
if ( ! V_99 )
return - V_324 ;
if ( ! V_91 -> V_356 )
return - V_324 ;
V_38 = 2 ;
if ( V_91 -> V_274 > 0 )
V_38 ++ ;
V_47 = F_158 ( V_10 , V_10 -> V_75 [ V_69 ] ,
V_70 , V_91 -> V_71 ,
V_38 , V_91 , 0 , V_319 ) ;
if ( V_47 < 0 )
return V_47 ;
V_124 = V_91 -> V_125 ;
V_256 = V_124 -> V_256 [ 0 ] ;
V_250 = & V_99 -> V_20 -> V_30 ;
V_335 = V_99 -> V_27 ;
V_355 = (struct V_354 * ) V_91 -> V_356 ;
V_31 = 0 ;
V_31 |= V_357 | F_51 ( V_358 ) ;
if ( V_335 == 0 )
V_31 |= 0x1 ;
if ( V_10 -> V_351 == 0x100 ) {
if ( V_91 -> V_274 > 0 ) {
if ( V_355 -> V_359 & V_360 )
V_31 |= F_184 ( V_361 ) ;
else
V_31 |= F_184 ( V_362 ) ;
}
}
F_155 ( V_10 , V_99 , true ,
V_355 -> V_359 | V_355 -> V_363 << 8 | F_185 ( V_355 -> V_364 ) << 16 ,
F_185 ( V_355 -> V_365 ) | F_185 ( V_355 -> V_366 ) << 16 ,
F_146 ( 8 ) | F_179 ( 0 ) ,
V_31 ) ;
if ( F_178 ( V_91 ) )
V_31 = V_350 | F_51 ( V_367 ) ;
else
V_31 = F_51 ( V_367 ) ;
V_348 = F_146 ( V_91 -> V_274 ) |
F_172 ( V_91 -> V_274 ) |
F_179 ( 0 ) ;
if ( V_91 -> V_274 > 0 ) {
if ( V_355 -> V_359 & V_360 )
V_31 |= V_368 ;
F_155 ( V_10 , V_99 , true ,
F_180 ( V_91 -> V_353 ) ,
F_181 ( V_91 -> V_353 ) ,
V_348 ,
V_31 | V_99 -> V_27 ) ;
}
V_256 -> F_4 = V_99 -> V_20 ;
if ( V_91 -> V_274 > 0 && V_355 -> V_359 & V_360 )
V_31 = 0 ;
else
V_31 = V_368 ;
F_155 ( V_10 , V_99 , false ,
0 ,
0 ,
F_179 ( 0 ) ,
V_31 | V_349 | F_51 ( V_369 ) | V_99 -> V_27 ) ;
F_167 ( V_10 , V_69 , V_70 , 0 ,
V_335 , V_250 ) ;
return 0 ;
}
static int F_186 ( struct V_9 * V_10 ,
struct V_91 * V_91 , int V_145 )
{
int V_38 = 0 ;
T_3 V_100 , V_370 ;
V_100 = ( T_3 ) ( V_91 -> V_353 + V_91 -> V_285 [ V_145 ] . V_371 ) ;
V_370 = V_91 -> V_285 [ V_145 ] . V_128 ;
V_38 = F_177 ( V_370 + ( V_100 & ( V_334 - 1 ) ) ,
V_334 ) ;
if ( V_38 == 0 )
V_38 ++ ;
return V_38 ;
}
static unsigned int F_187 ( struct V_9 * V_10 ,
struct V_217 * V_218 ,
struct V_91 * V_91 , unsigned int V_344 )
{
unsigned int V_372 ;
if ( V_10 -> V_351 < 0x100 || V_218 -> V_215 != V_373 )
return 0 ;
V_372 = V_91 -> V_74 -> V_374 . V_375 ;
return F_188 ( V_344 , V_372 + 1 ) - 1 ;
}
static unsigned int F_189 ( struct V_9 * V_10 ,
struct V_217 * V_218 ,
struct V_91 * V_91 , unsigned int V_344 )
{
unsigned int V_372 ;
unsigned int V_376 ;
if ( V_10 -> V_351 < 0x100 )
return 0 ;
switch ( V_218 -> V_215 ) {
case V_373 :
V_372 = V_91 -> V_74 -> V_374 . V_375 ;
V_376 = V_344 % ( V_372 + 1 ) ;
if ( V_376 == 0 )
return V_372 ;
return V_376 - 1 ;
default:
if ( V_344 == 0 )
return 0 ;
return V_344 - 1 ;
}
}
static int F_190 ( struct V_9 * V_10 , T_8 V_319 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_11 * V_99 ;
struct V_124 * V_124 ;
struct V_94 * V_256 ;
int V_377 , V_378 ;
struct V_89 * V_250 ;
bool V_116 ;
int V_335 ;
T_2 V_31 , V_348 ;
int V_330 , V_343 , V_370 , V_379 , V_47 ;
T_3 V_380 , V_100 ;
int V_145 , V_146 ;
bool V_28 ;
V_99 = V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] . V_12 ;
V_377 = V_91 -> V_381 ;
if ( V_377 < 1 ) {
F_16 ( V_10 , L_128 ) ;
return - V_324 ;
}
V_380 = ( T_3 ) V_91 -> V_353 ;
V_250 = & V_99 -> V_20 -> V_30 ;
V_335 = V_99 -> V_27 ;
V_124 = V_91 -> V_125 ;
for ( V_145 = 0 ; V_145 < V_377 ; V_145 ++ ) {
unsigned int V_344 ;
unsigned int V_382 ;
unsigned int V_376 ;
V_116 = true ;
V_330 = 0 ;
V_100 = V_380 + V_91 -> V_285 [ V_145 ] . V_371 ;
V_370 = V_91 -> V_285 [ V_145 ] . V_128 ;
V_379 = V_370 ;
V_344 = F_177 ( V_370 ,
F_174 (
F_175 ( & V_91 -> V_74 -> V_93 ) ) ) ;
if ( V_344 == 0 )
V_344 ++ ;
V_382 = F_187 ( V_10 , V_91 -> V_92 , V_91 ,
V_344 ) ;
V_376 = F_189 ( V_10 ,
V_91 -> V_92 , V_91 , V_344 ) ;
V_378 = F_186 ( V_10 , V_91 , V_145 ) ;
V_47 = F_158 ( V_10 , V_10 -> V_75 [ V_69 ] , V_70 ,
V_91 -> V_71 , V_378 , V_91 , V_145 , V_319 ) ;
if ( V_47 < 0 ) {
if ( V_145 == 0 )
return V_47 ;
goto V_231;
}
V_256 = V_124 -> V_256 [ V_145 ] ;
for ( V_146 = 0 ; V_146 < V_378 ; V_146 ++ ) {
T_2 V_341 = 0 ;
V_31 = 0 ;
if ( V_116 ) {
V_31 = F_191 ( V_382 ) |
F_192 ( V_376 ) ;
V_31 |= F_51 ( V_383 ) ;
V_31 |= V_384 ;
if ( V_145 == 0 ) {
if ( V_335 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_99 -> V_27 ;
V_116 = false ;
} else {
V_31 |= F_51 ( V_352 ) ;
V_31 |= V_99 -> V_27 ;
}
if ( F_178 ( V_91 ) )
V_31 |= V_350 ;
if ( V_146 < V_378 - 1 ) {
V_31 |= V_32 ;
V_28 = true ;
} else {
V_256 -> F_4 = V_99 -> V_20 ;
V_31 |= V_349 ;
if ( V_10 -> V_351 == 0x100 &&
! ( V_10 -> V_35 &
V_385 ) ) {
if ( V_145 < V_377 - 1 )
V_31 |= V_386 ;
}
V_28 = false ;
}
V_343 = V_334 -
( V_100 & ( ( 1 << V_387 ) - 1 ) ) ;
if ( V_343 > V_379 )
V_343 = V_379 ;
if ( V_10 -> V_351 < 0x100 ) {
V_341 = F_172 (
V_370 - V_330 ) ;
} else {
V_341 = F_173 (
V_330 , V_343 ,
V_344 , V_91 ,
( V_378 - V_146 - 1 ) ) ;
}
V_348 = F_146 ( V_343 ) |
V_341 |
F_179 ( 0 ) ;
F_155 ( V_10 , V_99 , V_28 ,
F_180 ( V_100 ) ,
F_181 ( V_100 ) ,
V_348 ,
V_31 ) ;
V_330 += V_343 ;
V_100 += V_343 ;
V_379 -= V_343 ;
}
if ( V_330 != V_370 ) {
F_23 ( V_10 , L_129 ) ;
V_47 = - V_324 ;
goto V_231;
}
}
if ( F_36 ( V_10 ) -> V_131 . V_132 == 0 ) {
if ( V_10 -> V_35 & V_133 )
F_193 () ;
}
F_36 ( V_10 ) -> V_131 . V_132 ++ ;
F_167 ( V_10 , V_69 , V_70 , V_91 -> V_71 ,
V_335 , V_250 ) ;
return 0 ;
V_231:
for ( V_145 -- ; V_145 >= 0 ; V_145 -- )
F_71 ( & V_124 -> V_256 [ V_145 ] -> V_82 ) ;
V_124 -> V_256 [ 0 ] -> F_4 = V_99 -> V_20 ;
F_50 ( V_10 , V_99 , V_124 -> V_256 [ 0 ] , true ) ;
V_99 -> V_20 = V_124 -> V_256 [ 0 ] -> V_116 ;
V_99 -> V_21 = V_124 -> V_256 [ 0 ] -> V_87 ;
V_99 -> V_27 = V_335 ;
V_99 -> V_26 = V_99 -> V_149 ;
F_60 ( F_57 ( V_91 -> V_92 -> V_127 ) , V_91 ) ;
return V_47 ;
}
int F_194 ( struct V_9 * V_10 , T_8 V_319 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_98 * V_266 ;
struct V_11 * V_99 ;
struct V_107 * V_108 ;
int V_388 ;
int V_336 ;
int V_337 ;
int V_377 , V_38 , V_145 ;
int V_47 ;
V_266 = V_10 -> V_75 [ V_69 ] ;
V_99 = V_266 -> V_76 [ V_70 ] . V_12 ;
V_108 = F_48 ( V_10 , V_266 -> V_109 , V_70 ) ;
V_38 = 0 ;
V_377 = V_91 -> V_381 ;
for ( V_145 = 0 ; V_145 < V_377 ; V_145 ++ )
V_38 += F_186 ( V_10 , V_91 , V_145 ) ;
V_47 = F_156 ( V_10 , V_99 , F_3 ( V_108 -> V_159 ) & V_160 ,
V_38 , V_319 ) ;
if ( V_47 )
return V_47 ;
V_388 = F_18 ( & V_10 -> V_389 -> V_390 ) ;
V_388 &= 0x3fff ;
V_91 -> V_388 = V_388 ;
if ( V_91 -> V_92 -> V_215 == V_339 ||
V_91 -> V_92 -> V_215 == V_340 )
V_91 -> V_388 >>= 3 ;
V_336 = F_169 ( F_3 ( V_108 -> V_159 ) ) ;
V_337 = V_91 -> V_338 ;
if ( V_91 -> V_92 -> V_215 == V_339 ||
V_91 -> V_92 -> V_215 == V_340 )
V_337 *= 8 ;
if ( V_336 != V_337 ) {
F_170 ( & V_91 -> V_92 -> V_92 ,
L_123 ,
V_337 , V_337 == 1 ? L_124 : L_125 ,
V_336 , V_336 == 1 ? L_124 : L_125 ) ;
V_91 -> V_338 = V_336 ;
if ( V_91 -> V_92 -> V_215 == V_339 ||
V_91 -> V_92 -> V_215 == V_340 )
V_91 -> V_338 /= 8 ;
}
V_99 -> V_149 = V_99 -> V_26 ;
return F_190 ( V_10 , V_319 , V_91 , V_69 , V_70 ) ;
}
static int F_195 ( struct V_9 * V_10 , T_2 V_315 , T_2 V_316 ,
T_2 V_317 , T_2 V_318 , bool V_391 )
{
int V_392 = V_10 -> V_393 ;
int V_47 ;
if ( ! V_391 )
V_392 ++ ;
V_47 = F_156 ( V_10 , V_10 -> V_49 , V_326 ,
V_392 , V_61 ) ;
if ( V_47 < 0 ) {
F_23 ( V_10 , L_130 ) ;
if ( V_391 )
F_23 ( V_10 , L_131
L_132 ) ;
return V_47 ;
}
F_155 ( V_10 , V_10 -> V_49 , false , V_315 , V_316 , V_317 ,
V_318 | V_10 -> V_49 -> V_27 ) ;
return 0 ;
}
int F_196 ( struct V_9 * V_10 , T_2 V_207 , T_2 V_69 )
{
return F_195 ( V_10 , 0 , 0 , 0 ,
F_51 ( V_207 ) | F_197 ( V_69 ) , false ) ;
}
int F_198 ( struct V_9 * V_10 , T_1 V_394 ,
T_2 V_69 , enum V_395 V_355 )
{
return F_195 ( V_10 , F_180 ( V_394 ) ,
F_181 ( V_394 ) , 0 ,
F_51 ( V_201 ) | F_197 ( V_69 )
| ( V_355 == V_396 ? V_397 : 0 ) , false ) ;
}
int F_199 ( struct V_9 * V_10 ,
T_2 V_315 , T_2 V_316 , T_2 V_317 , T_2 V_318 )
{
return F_195 ( V_10 , V_315 , V_316 , V_317 , V_318 , false ) ;
}
int F_200 ( struct V_9 * V_10 , T_2 V_69 )
{
return F_195 ( V_10 , 0 , 0 , 0 ,
F_51 ( V_205 ) | F_197 ( V_69 ) ,
false ) ;
}
int F_83 ( struct V_9 * V_10 , T_1 V_394 ,
T_2 V_69 , bool V_391 )
{
return F_195 ( V_10 , F_180 ( V_394 ) ,
F_181 ( V_394 ) , 0 ,
F_51 ( V_199 ) | F_197 ( V_69 ) ,
V_391 ) ;
}
int F_201 ( struct V_9 * V_10 , T_1 V_394 ,
T_2 V_69 , bool V_391 )
{
return F_195 ( V_10 , F_180 ( V_394 ) ,
F_181 ( V_394 ) , 0 ,
F_51 ( V_200 ) | F_197 ( V_69 ) ,
V_391 ) ;
}
int F_202 ( struct V_9 * V_10 , int V_69 ,
unsigned int V_70 , int V_398 )
{
T_2 V_399 = F_197 ( V_69 ) ;
T_2 V_400 = F_203 ( V_70 ) ;
T_2 type = F_51 ( V_202 ) ;
T_2 V_401 = F_204 ( V_398 ) ;
return F_195 ( V_10 , 0 , 0 , 0 ,
V_399 | V_400 | type | V_401 , false ) ;
}
static int F_53 ( struct V_9 * V_10 , int V_69 ,
unsigned int V_70 , unsigned int V_71 ,
struct V_1 * V_24 ,
union V_3 * V_402 , T_2 V_27 )
{
T_1 V_100 ;
T_2 V_399 = F_197 ( V_69 ) ;
T_2 V_400 = F_203 ( V_70 ) ;
T_2 V_403 = F_205 ( V_71 ) ;
T_2 V_404 = 0 ;
T_2 type = F_51 ( V_203 ) ;
struct V_73 * V_74 ;
V_100 = F_1 ( V_24 , V_402 ) ;
if ( V_100 == 0 ) {
F_32 ( V_10 , L_133 ) ;
F_32 ( V_10 , L_134 ,
V_24 , V_402 ) ;
return 0 ;
}
V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
if ( ( V_74 -> V_77 & V_79 ) ) {
F_32 ( V_10 , L_133 ) ;
F_32 ( V_10 , L_135 ) ;
return 0 ;
}
V_74 -> V_165 = V_24 ;
V_74 -> V_151 = V_402 ;
if ( V_71 )
V_404 = F_206 ( V_405 ) ;
return F_195 ( V_10 , F_180 ( V_100 ) | V_404 | V_27 ,
F_181 ( V_100 ) , V_403 ,
V_399 | V_400 | type , false ) ;
}
int F_135 ( struct V_9 * V_10 , int V_69 ,
unsigned int V_70 )
{
T_2 V_399 = F_197 ( V_69 ) ;
T_2 V_400 = F_203 ( V_70 ) ;
T_2 type = F_51 ( V_204 ) ;
return F_195 ( V_10 , 0 , 0 , 0 , V_399 | V_400 | type ,
false ) ;
}
