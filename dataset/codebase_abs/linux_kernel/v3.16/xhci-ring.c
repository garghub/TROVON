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
static struct V_1 * F_29 (
struct V_1 * V_74 ,
union V_3 * V_4 , int * V_26 )
{
struct V_1 * V_75 = V_74 ;
struct V_76 * V_77 ;
while ( V_75 -> V_6 > V_4 ||
& V_75 -> V_6 [ V_7 - 1 ] < V_4 ) {
V_77 = & V_75 -> V_6 [ V_7 - 1 ] . V_29 ;
if ( V_77 -> V_30 [ 3 ] & F_11 ( V_18 ) )
* V_26 ^= 0x1 ;
V_75 = V_75 -> V_14 ;
if ( V_75 == V_74 )
return NULL ;
}
return V_75 ;
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
struct V_78 * V_78 )
{
return F_30 ( V_10 , V_78 -> V_79 -> V_56 ,
F_33 ( & V_78 -> V_61 -> V_80 ) , V_78 -> V_58 ) ;
}
void F_34 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 , struct V_81 * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * V_79 = V_10 -> V_62 [ V_56 ] ;
struct V_60 * V_61 = & V_79 -> V_63 [ V_57 ] ;
struct V_11 * V_86 ;
struct V_76 * V_4 ;
T_1 V_87 ;
T_3 V_88 ;
V_86 = F_30 ( V_10 , V_56 ,
V_57 , V_58 ) ;
if ( ! V_86 ) {
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
V_88 = F_36 ( V_91 -> V_93 ) ;
} else {
struct V_94 * V_95
= F_37 ( V_10 , V_79 -> V_96 , V_57 ) ;
V_88 = F_36 ( V_95 -> V_97 ) ;
}
V_84 -> V_98 = V_86 -> V_23 ;
V_84 -> V_99 = V_86 -> V_24 ;
while ( F_1 ( V_84 -> V_98 , V_84 -> V_99 )
!= ( T_1 ) ( V_88 & ~ 0xf ) ) {
F_7 ( V_10 , V_86 , & V_84 -> V_98 ,
& V_84 -> V_99 ) ;
if ( V_84 -> V_99 == V_86 -> V_24 ) {
F_38 ( 1 ) ;
return;
}
}
V_84 -> V_100 = V_88 & 0x1 ;
if ( V_86 -> V_15 == V_86 -> V_15 -> V_14 &&
V_82 -> F_4 < V_84 -> V_99 )
V_84 -> V_100 ^= 0x1 ;
V_84 -> V_99 = V_82 -> F_4 ;
F_35 ( V_10 , V_89 ,
L_13 ) ;
V_84 -> V_98 = F_29 ( V_84 -> V_98 ,
V_84 -> V_99 , & V_84 -> V_100 ) ;
if ( ! V_84 -> V_98 ) {
F_38 ( 1 ) ;
return;
}
V_4 = & V_84 -> V_99 -> V_29 ;
if ( F_5 ( V_4 -> V_30 [ 3 ] ) &&
( V_4 -> V_30 [ 3 ] & F_11 ( V_18 ) ) )
V_84 -> V_100 ^= 0x1 ;
F_7 ( V_10 , V_86 , & V_84 -> V_98 , & V_84 -> V_99 ) ;
F_35 ( V_10 , V_89 ,
L_14 , V_84 -> V_100 ) ;
F_35 ( V_10 , V_89 ,
L_15 ,
V_84 -> V_98 ) ;
V_87 = F_1 ( V_84 -> V_98 , V_84 -> V_99 ) ;
F_35 ( V_10 , V_89 ,
L_16 ,
( unsigned long long ) V_87 ) ;
}
static void F_39 ( struct V_9 * V_10 , struct V_11 * V_86 ,
struct V_81 * V_82 , bool V_101 )
{
struct V_1 * V_75 ;
union V_3 * V_102 ;
for ( V_75 = V_82 -> V_74 , V_102 = V_82 -> V_103 ;
true ;
F_7 ( V_10 , V_86 , & V_75 , & V_102 ) ) {
if ( F_5 ( V_102 -> V_29 . V_30 [ 3 ] ) ) {
V_102 -> V_29 . V_30 [ 3 ] &= F_11 ( ~ V_31 ) ;
if ( V_101 )
V_102 -> V_29 . V_30 [ 3 ] ^=
F_11 ( V_37 ) ;
F_35 ( V_10 , V_89 ,
L_17 ) ;
F_35 ( V_10 , V_89 ,
L_18
L_19 ,
V_102 ,
( unsigned long long ) F_1 ( V_75 , V_102 ) ,
V_75 ,
( unsigned long long ) V_75 -> V_8 ) ;
} else {
V_102 -> V_29 . V_30 [ 0 ] = 0 ;
V_102 -> V_29 . V_30 [ 1 ] = 0 ;
V_102 -> V_29 . V_30 [ 2 ] = 0 ;
V_102 -> V_29 . V_30 [ 3 ] &= F_11 ( V_37 ) ;
if ( V_101 && V_102 != V_82 -> V_103 &&
V_102 != V_82 -> F_4 )
V_102 -> V_29 . V_30 [ 3 ] ^=
F_11 ( V_37 ) ;
V_102 -> V_29 . V_30 [ 3 ] |= F_11 (
F_40 ( V_104 ) ) ;
F_35 ( V_10 , V_89 ,
L_20 ,
( unsigned long long )
F_1 ( V_75 , V_102 ) ) ;
}
if ( V_102 == V_82 -> F_4 )
break;
}
}
void F_41 ( struct V_9 * V_10 ,
struct V_105 * V_106 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 ,
struct V_83 * V_107 )
{
struct V_60 * V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
F_35 ( V_10 , V_89 ,
L_21
L_22 ,
V_107 -> V_98 ,
( unsigned long long ) V_107 -> V_98 -> V_8 ,
V_107 -> V_99 ,
( unsigned long long ) F_1 ( V_107 -> V_98 , V_107 -> V_99 ) ,
V_107 -> V_100 ) ;
F_42 ( V_10 , V_106 , V_56 , V_57 , V_58 ,
V_107 -> V_98 ,
V_107 -> V_99 ,
( T_2 ) V_107 -> V_100 ) ;
V_61 -> V_64 |= V_66 ;
}
static void F_43 ( struct V_9 * V_10 ,
struct V_60 * V_61 )
{
V_61 -> V_64 &= ~ V_65 ;
if ( F_44 ( & V_61 -> V_108 ) )
V_61 -> V_109 -- ;
}
static void F_45 ( struct V_9 * V_10 ,
struct V_81 * V_82 , int V_110 )
{
struct V_111 * V_112 ;
struct V_78 * V_78 ;
struct V_113 * V_113 ;
V_78 = V_82 -> V_78 ;
V_113 = V_78 -> V_114 ;
V_113 -> V_115 ++ ;
V_112 = F_46 ( V_78 -> V_79 -> V_116 ) ;
if ( V_113 -> V_115 == V_113 -> V_117 ) {
if ( F_47 ( V_78 -> V_118 ) == V_119 ) {
F_48 ( V_10 ) -> V_120 . V_121 -- ;
if ( F_48 ( V_10 ) -> V_120 . V_121 == 0 ) {
if ( V_10 -> V_35 & V_122 )
F_49 () ;
}
}
F_50 ( V_112 , V_78 ) ;
F_51 ( & V_10 -> V_123 ) ;
F_52 ( V_112 , V_78 , V_110 ) ;
F_53 ( V_10 , V_113 ) ;
F_54 ( & V_10 -> V_123 ) ;
}
}
static void F_55 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , struct V_124 * V_125 )
{
unsigned int V_57 ;
struct V_11 * V_86 ;
struct V_60 * V_61 ;
struct V_126 * V_127 ;
struct V_81 * V_82 = NULL ;
struct V_81 * V_128 ;
struct V_83 V_107 ;
if ( F_56 ( F_57 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ) ) {
if ( ! V_10 -> V_62 [ V_56 ] )
F_31 ( V_10 , L_23
L_24 ,
V_56 ) ;
return;
}
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
V_57 = F_58 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( F_28 ( & V_61 -> V_129 ) ) {
F_43 ( V_10 , V_61 ) ;
V_61 -> V_130 = NULL ;
F_27 ( V_10 , V_56 , V_57 ) ;
return;
}
F_59 (entry, &ep->cancelled_td_list) {
V_82 = F_60 ( V_127 , struct V_81 , V_129 ) ;
F_35 ( V_10 , V_89 ,
L_25 ,
( unsigned long long ) F_1 (
V_82 -> V_74 , V_82 -> V_103 ) ) ;
V_86 = F_32 ( V_10 , V_82 -> V_78 ) ;
if ( ! V_86 ) {
F_31 ( V_10 , L_26
L_27 ,
V_82 -> V_78 ,
V_82 -> V_78 -> V_58 ) ;
goto V_131;
}
if ( V_82 == V_61 -> V_130 )
F_34 ( V_10 , V_56 , V_57 ,
V_82 -> V_78 -> V_58 ,
V_82 , & V_107 ) ;
else
F_39 ( V_10 , V_86 , V_82 , false ) ;
V_131:
F_61 ( & V_82 -> V_69 ) ;
}
V_128 = V_82 ;
F_43 ( V_10 , V_61 ) ;
if ( V_107 . V_99 && V_107 . V_98 ) {
struct V_105 * V_132 ;
V_132 = F_62 ( V_10 , false , false , V_133 ) ;
F_41 ( V_10 , V_132 ,
V_56 , V_57 ,
V_61 -> V_130 -> V_78 -> V_58 ,
& V_107 ) ;
F_14 ( V_10 ) ;
} else {
F_27 ( V_10 , V_56 , V_57 ) ;
}
if ( ! ( V_61 -> V_64 & V_67 ) )
V_61 -> V_130 = NULL ;
do {
V_82 = F_60 ( V_61 -> V_129 . V_14 ,
struct V_81 , V_129 ) ;
F_61 ( & V_82 -> V_129 ) ;
F_45 ( V_10 , V_82 , 0 ) ;
if ( V_10 -> V_53 & V_54 )
return;
} while ( V_82 != V_128 );
}
static void F_63 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_81 * V_82 ;
while ( ! F_28 ( & V_12 -> V_69 ) ) {
V_82 = F_64 ( & V_12 -> V_69 ,
struct V_81 , V_69 ) ;
F_61 ( & V_82 -> V_69 ) ;
if ( ! F_28 ( & V_82 -> V_129 ) )
F_61 ( & V_82 -> V_129 ) ;
F_45 ( V_10 , V_82 , - V_55 ) ;
}
}
static void F_65 ( struct V_9 * V_10 ,
int V_56 , int V_57 )
{
struct V_81 * V_82 ;
struct V_60 * V_61 ;
struct V_11 * V_12 ;
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ( V_61 -> V_64 & V_68 ) ||
( V_61 -> V_64 & V_134 ) ) {
int V_58 ;
for ( V_58 = 0 ; V_58 < V_61 -> V_70 -> V_71 ;
V_58 ++ ) {
F_35 ( V_10 , V_89 ,
L_28 ,
V_56 , V_57 , V_58 + 1 ) ;
F_63 ( V_10 ,
V_61 -> V_70 -> V_73 [ V_58 ] ) ;
}
} else {
V_12 = V_61 -> V_12 ;
if ( ! V_12 )
return;
F_35 ( V_10 , V_89 ,
L_29 ,
V_56 , V_57 ) ;
F_63 ( V_10 , V_12 ) ;
}
while ( ! F_28 ( & V_61 -> V_129 ) ) {
V_82 = F_64 ( & V_61 -> V_129 ,
struct V_81 , V_129 ) ;
F_61 ( & V_82 -> V_129 ) ;
F_45 ( V_10 , V_82 , - V_55 ) ;
}
}
void F_66 ( unsigned long V_135 )
{
struct V_9 * V_10 ;
struct V_60 * V_61 ;
int V_47 , V_136 , V_137 ;
unsigned long V_138 ;
V_61 = (struct V_60 * ) V_135 ;
V_10 = V_61 -> V_10 ;
F_67 ( & V_10 -> V_123 , V_138 ) ;
V_61 -> V_109 -- ;
if ( V_10 -> V_53 & V_54 ) {
F_35 ( V_10 , V_89 ,
L_30
L_31 ) ;
F_68 ( & V_10 -> V_123 , V_138 ) ;
return;
}
if ( ! ( V_61 -> V_109 == 0 && ( V_61 -> V_64 & V_65 ) ) ) {
F_35 ( V_10 , V_89 ,
L_32
L_33 ) ;
F_68 ( & V_10 -> V_123 , V_138 ) ;
return;
}
F_31 ( V_10 , L_34 ) ;
F_31 ( V_10 , L_35 ) ;
V_10 -> V_53 |= V_54 ;
F_23 ( V_10 ) ;
F_68 ( & V_10 -> V_123 , V_138 ) ;
V_47 = F_24 ( V_10 ) ;
F_67 ( & V_10 -> V_123 , V_138 ) ;
if ( V_47 < 0 ) {
F_31 ( V_10 , L_36 ) ;
F_31 ( V_10 , L_37 ) ;
}
for ( V_136 = 0 ; V_136 < V_139 ; V_136 ++ ) {
if ( ! V_10 -> V_62 [ V_136 ] )
continue;
for ( V_137 = 0 ; V_137 < 31 ; V_137 ++ )
F_65 ( V_10 , V_136 , V_137 ) ;
}
F_68 ( & V_10 -> V_123 , V_138 ) ;
F_35 ( V_10 , V_89 ,
L_38 ) ;
F_69 ( F_48 ( V_10 ) -> V_140 ) ;
F_35 ( V_10 , V_89 ,
L_39 ) ;
}
static void F_70 ( struct V_9 * V_10 ,
struct V_85 * V_79 ,
struct V_11 * V_86 ,
unsigned int V_57 )
{
union V_3 * V_141 ;
int V_142 ;
bool V_143 = false ;
V_142 = V_86 -> V_25 ;
V_141 = V_86 -> V_24 ;
if ( F_4 ( V_10 , V_86 , V_86 -> V_23 , V_86 -> V_24 ) ) {
V_86 -> V_23 = V_86 -> V_23 -> V_14 ;
V_86 -> V_24 = V_86 -> V_23 -> V_6 ;
}
while ( V_86 -> V_24 != V_79 -> V_63 [ V_57 ] . V_144 ) {
V_86 -> V_25 ++ ;
V_86 -> V_24 ++ ;
if ( F_4 ( V_10 , V_86 , V_86 -> V_23 ,
V_86 -> V_24 ) ) {
if ( V_86 -> V_24 ==
V_79 -> V_63 [ V_57 ] . V_144 )
break;
V_86 -> V_23 = V_86 -> V_23 -> V_14 ;
V_86 -> V_24 = V_86 -> V_23 -> V_6 ;
}
if ( V_86 -> V_24 == V_141 ) {
V_143 = true ;
break;
}
}
if ( V_143 ) {
F_15 ( V_10 , L_40 ) ;
V_86 -> V_25 = V_142 ;
}
}
static void F_71 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , T_2 V_145 )
{
unsigned int V_57 ;
unsigned int V_58 ;
struct V_11 * V_86 ;
struct V_85 * V_79 ;
struct V_60 * V_61 ;
struct V_94 * V_95 ;
struct V_146 * V_147 ;
V_57 = F_58 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_58 = F_72 ( F_3 ( V_4 -> V_29 . V_30 [ 2 ] ) ) ;
V_79 = V_10 -> V_62 [ V_56 ] ;
V_61 = & V_79 -> V_63 [ V_57 ] ;
V_86 = F_73 ( V_79 , V_57 , V_58 ) ;
if ( ! V_86 ) {
F_31 ( V_10 , L_41 ,
V_58 ) ;
V_79 -> V_63 [ V_57 ] . V_64 &= ~ V_66 ;
return;
}
V_95 = F_37 ( V_10 , V_79 -> V_96 , V_57 ) ;
V_147 = F_74 ( V_10 , V_79 -> V_96 ) ;
if ( V_145 != V_148 ) {
unsigned int V_64 ;
unsigned int V_149 ;
switch ( V_145 ) {
case V_150 :
F_31 ( V_10 , L_42 ) ;
break;
case V_151 :
F_31 ( V_10 , L_43 ) ;
V_64 = F_3 ( V_95 -> V_152 ) ;
V_64 &= V_153 ;
V_149 = F_3 ( V_147 -> V_154 ) ;
V_149 = F_75 ( V_149 ) ;
F_35 ( V_10 , V_89 ,
L_44 ,
V_149 , V_64 ) ;
break;
case V_155 :
F_31 ( V_10 , L_45 ,
V_56 ) ;
break;
default:
F_31 ( V_10 , L_46 ,
V_145 ) ;
break;
}
} else {
T_3 V_97 ;
if ( V_61 -> V_64 & V_68 ) {
struct V_90 * V_91 =
& V_61 -> V_70 -> V_92 [ V_58 ] ;
V_97 = F_36 ( V_91 -> V_93 ) & V_156 ;
} else {
V_97 = F_36 ( V_95 -> V_97 ) & ~ V_157 ;
}
F_35 ( V_10 , V_89 ,
L_47 , V_97 ) ;
if ( F_1 ( V_61 -> V_158 ,
V_61 -> V_144 ) == V_97 ) {
F_70 ( V_10 , V_79 ,
V_86 , V_57 ) ;
} else {
F_31 ( V_10 , L_48 ) ;
F_31 ( V_10 , L_49 ,
V_61 -> V_158 , V_61 -> V_144 ) ;
}
}
V_79 -> V_63 [ V_57 ] . V_64 &= ~ V_66 ;
V_79 -> V_63 [ V_57 ] . V_158 = NULL ;
V_79 -> V_63 [ V_57 ] . V_144 = NULL ;
F_27 ( V_10 , V_56 , V_57 ) ;
}
static void F_76 ( struct V_9 * V_10 , int V_56 ,
union V_3 * V_4 , T_2 V_145 )
{
unsigned int V_57 ;
V_57 = F_58 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
F_35 ( V_10 , V_159 ,
L_50 , V_145 ) ;
if ( V_10 -> V_35 & V_160 ) {
struct V_105 * V_132 ;
V_132 = F_62 ( V_10 , false , false , V_133 ) ;
F_35 ( V_10 , V_161 ,
L_51 ) ;
F_77 ( V_10 , V_132 ,
V_10 -> V_62 [ V_56 ] -> V_162 -> V_8 , V_56 ,
false ) ;
F_14 ( V_10 ) ;
} else {
V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] . V_64 &= ~ V_67 ;
F_27 ( V_10 , V_56 , V_57 ) ;
}
}
static void F_78 ( struct V_9 * V_10 , int V_56 ,
T_2 V_145 )
{
if ( V_145 == V_148 )
V_10 -> V_56 = V_56 ;
else
V_10 -> V_56 = 0 ;
}
static void F_79 ( struct V_9 * V_10 , int V_56 )
{
struct V_85 * V_163 ;
V_163 = V_10 -> V_62 [ V_56 ] ;
if ( ! V_163 )
return;
if ( V_10 -> V_35 & V_164 )
F_80 ( V_10 , V_163 , true ) ;
F_81 ( V_10 , V_56 ) ;
}
static void F_82 ( struct V_9 * V_10 , int V_56 ,
struct V_124 * V_125 , T_2 V_145 )
{
struct V_85 * V_163 ;
struct V_165 * V_166 ;
unsigned int V_57 ;
unsigned int V_64 ;
T_2 V_167 , V_168 ;
V_163 = V_10 -> V_62 [ V_56 ] ;
V_166 = F_83 ( V_10 , V_163 -> V_162 ) ;
if ( ! V_166 ) {
F_31 ( V_10 , L_52 ) ;
return;
}
V_167 = F_3 ( V_166 -> V_167 ) ;
V_168 = F_3 ( V_166 -> V_168 ) ;
V_57 = F_84 ( V_167 ) - 1 ;
if ( V_10 -> V_35 & V_160 &&
V_57 != ( unsigned int ) - 1 &&
V_167 - V_169 == V_168 ) {
V_64 = V_163 -> V_63 [ V_57 ] . V_64 ;
if ( ! ( V_64 & V_67 ) )
return;
F_35 ( V_10 , V_161 ,
L_53
L_54 ,
V_57 , V_64 ) ;
V_163 -> V_63 [ V_57 ] . V_64 &= ~ V_67 ;
F_27 ( V_10 , V_56 , V_57 ) ;
return;
}
return;
}
static void F_85 ( struct V_9 * V_10 , int V_56 ,
struct V_124 * V_125 )
{
F_15 ( V_10 , L_55 ) ;
if ( ! V_10 -> V_62 [ V_56 ] )
F_31 ( V_10 , L_56
L_57 , V_56 ) ;
}
static void F_86 ( struct V_9 * V_10 ,
struct V_124 * V_125 )
{
if ( ! ( V_10 -> V_35 & V_170 ) ) {
V_10 -> V_171 |= 1 << 6 ;
return;
}
F_35 ( V_10 , V_161 ,
L_58 ,
F_87 ( F_3 ( V_125 -> V_110 ) ) ,
F_88 ( F_3 ( V_125 -> V_110 ) ) ) ;
}
static void F_89 ( struct V_105 * V_106 , T_2 V_110 )
{
F_90 ( & V_106 -> V_172 ) ;
if ( V_106 -> V_173 ) {
V_106 -> V_110 = V_110 ;
F_91 ( V_106 -> V_173 ) ;
} else {
F_92 ( V_106 ) ;
}
}
void F_93 ( struct V_9 * V_10 )
{
struct V_105 * V_174 , * V_175 ;
F_94 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_89 ( V_174 , V_176 ) ;
}
static void F_95 ( struct V_9 * V_10 ,
struct V_105 * V_174 )
{
struct V_105 * V_177 , * V_175 ;
T_2 V_26 ;
F_94 (i_cmd, tmp_cmd, &xhci->cmd_list,
cmd_list) {
if ( V_177 -> V_110 != V_176 )
continue;
V_177 -> V_110 = V_178 ;
F_15 ( V_10 , L_59 ,
V_177 -> V_179 ) ;
V_26 = F_3 (
V_177 -> V_179 -> V_29 . V_30 [ 3 ] ) & V_37 ;
V_177 -> V_179 -> V_29 . V_30 [ 0 ] = 0 ;
V_177 -> V_179 -> V_29 . V_30 [ 1 ] = 0 ;
V_177 -> V_179 -> V_29 . V_30 [ 2 ] = 0 ;
V_177 -> V_179 -> V_29 . V_30 [ 3 ] = F_11 (
F_40 ( V_180 ) | V_26 ) ;
}
V_10 -> V_41 = V_42 ;
if ( ( V_10 -> V_49 -> V_24 != V_10 -> V_49 -> V_20 ) &&
! ( V_10 -> V_53 & V_54 ) ) {
V_10 -> V_181 = V_174 ;
F_96 ( & V_10 -> V_182 , V_183 + V_184 ) ;
F_14 ( V_10 ) ;
}
return;
}
void F_97 ( unsigned long V_185 )
{
struct V_9 * V_10 ;
int V_47 ;
unsigned long V_138 ;
T_3 V_186 ;
struct V_105 * V_174 = NULL ;
V_10 = (struct V_9 * ) V_185 ;
F_67 ( & V_10 -> V_123 , V_138 ) ;
if ( V_10 -> V_181 ) {
V_174 = V_10 -> V_181 ;
V_174 -> V_110 = V_176 ;
}
V_186 = F_19 ( V_10 , & V_10 -> V_48 -> V_49 ) ;
if ( ( V_10 -> V_41 & V_42 ) &&
( V_186 & V_52 ) ) {
F_68 ( & V_10 -> V_123 , V_138 ) ;
F_15 ( V_10 , L_60 ) ;
V_47 = F_18 ( V_10 ) ;
if ( F_56 ( V_47 == - V_55 ) ) {
F_22 ( V_10 , L_61 ) ;
F_93 ( V_10 ) ;
F_69 ( F_48 ( V_10 ) -> V_140 ) ;
F_15 ( V_10 , L_62 ) ;
}
return;
}
F_15 ( V_10 , L_63 ) ;
F_95 ( V_10 , V_10 -> V_181 ) ;
F_68 ( & V_10 -> V_123 , V_138 ) ;
return;
}
static void F_98 ( struct V_9 * V_10 ,
struct V_124 * V_125 )
{
int V_56 = F_99 ( F_3 ( V_125 -> V_138 ) ) ;
T_3 V_187 ;
T_1 V_188 ;
T_2 V_145 ;
union V_3 * V_189 ;
struct V_105 * V_106 ;
T_2 V_190 ;
V_187 = F_36 ( V_125 -> V_189 ) ;
V_189 = V_10 -> V_49 -> V_24 ;
V_188 = F_1 ( V_10 -> V_49 -> V_23 ,
V_189 ) ;
if ( V_188 == 0 ) {
V_10 -> V_171 |= 1 << 4 ;
return;
}
if ( V_187 != ( T_3 ) V_188 ) {
V_10 -> V_171 |= 1 << 5 ;
return;
}
V_106 = F_60 ( V_10 -> V_172 . V_14 , struct V_105 , V_172 ) ;
if ( V_106 -> V_179 != V_10 -> V_49 -> V_24 ) {
F_22 ( V_10 ,
L_64 ) ;
return;
}
F_44 ( & V_10 -> V_182 ) ;
F_100 ( V_189 , (struct V_76 * ) V_125 ) ;
V_145 = F_101 ( F_3 ( V_125 -> V_110 ) ) ;
if ( V_145 == V_178 ) {
F_95 ( V_10 , V_106 ) ;
return;
}
if ( V_145 == V_176 ) {
V_10 -> V_41 = V_191 ;
if ( V_106 -> V_110 == V_176 )
goto V_192;
}
V_190 = F_102 ( F_3 ( V_189 -> V_29 . V_30 [ 3 ] ) ) ;
switch ( V_190 ) {
case V_193 :
F_78 ( V_10 , V_56 , V_145 ) ;
break;
case V_194 :
F_79 ( V_10 , V_56 ) ;
break;
case V_195 :
if ( ! V_106 -> V_173 )
F_82 ( V_10 , V_56 , V_125 ,
V_145 ) ;
break;
case V_196 :
break;
case V_197 :
break;
case V_198 :
F_38 ( V_56 != F_99 (
F_3 ( V_189 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_55 ( V_10 , V_56 , V_189 , V_125 ) ;
break;
case V_199 :
F_38 ( V_56 != F_99 (
F_3 ( V_189 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_71 ( V_10 , V_56 , V_189 , V_145 ) ;
break;
case V_180 :
if ( V_106 -> V_110 == V_178 )
V_145 = V_178 ;
break;
case V_200 :
F_38 ( V_56 != F_99 (
F_3 ( V_189 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_76 ( V_10 , V_56 , V_189 , V_145 ) ;
break;
case V_201 :
V_56 = F_99 (
F_3 ( V_189 -> V_29 . V_30 [ 3 ] ) ) ;
F_85 ( V_10 , V_56 , V_125 ) ;
break;
case V_202 :
F_86 ( V_10 , V_125 ) ;
break;
default:
V_10 -> V_171 |= 1 << 6 ;
break;
}
if ( V_106 -> V_172 . V_14 != & V_10 -> V_172 ) {
V_10 -> V_181 = F_60 ( V_106 -> V_172 . V_14 ,
struct V_105 , V_172 ) ;
F_96 ( & V_10 -> V_182 , V_183 + V_184 ) ;
}
V_192:
F_89 ( V_106 , V_145 ) ;
F_8 ( V_10 , V_10 -> V_49 ) ;
}
static void F_103 ( struct V_9 * V_10 ,
union V_3 * V_125 )
{
T_2 V_203 ;
V_203 = F_102 ( F_3 ( V_125 -> V_29 . V_30 [ 3 ] ) ) ;
F_15 ( V_10 , L_65 , V_203 ) ;
if ( V_203 == V_204 && ( V_10 -> V_35 & V_170 ) )
F_98 ( V_10 , & V_125 -> V_205 ) ;
}
static unsigned int F_104 ( struct V_111 * V_112 ,
struct V_9 * V_10 , T_2 V_206 )
{
unsigned int V_136 ;
unsigned int V_207 = 0 ;
for ( V_136 = 0 ; V_136 < ( V_206 - 1 ) ; V_136 ++ ) {
T_6 V_208 = V_10 -> V_209 [ V_136 ] ;
if ( V_208 == 0 || V_208 == V_210 )
continue;
if ( ( V_208 == 0x03 ) == ( V_112 -> V_211 == V_212 ) )
V_207 ++ ;
}
return V_207 ;
}
static void F_105 ( struct V_9 * V_10 ,
union V_3 * V_125 )
{
T_2 V_56 ;
struct V_213 * V_214 ;
V_56 = F_99 ( F_3 ( V_125 -> V_29 . V_30 [ 3 ] ) ) ;
if ( ! V_10 -> V_62 [ V_56 ] ) {
F_31 ( V_10 , L_66
L_67 , V_56 ) ;
return;
}
F_15 ( V_10 , L_68 ,
V_56 ) ;
V_214 = V_10 -> V_62 [ V_56 ] -> V_214 ;
if ( V_214 && V_214 -> V_215 )
F_106 ( V_214 -> V_215 , V_214 -> V_216 ) ;
}
static void F_107 ( struct V_9 * V_10 ,
union V_3 * V_125 )
{
struct V_111 * V_112 ;
T_2 V_206 ;
T_2 V_217 , V_218 ;
int V_219 ;
int V_56 ;
unsigned int V_220 ;
T_6 V_221 ;
struct V_222 * V_223 ;
T_4 T_5 * * V_209 ;
bool V_224 = false ;
if ( F_101 ( F_3 ( V_125 -> V_29 . V_30 [ 2 ] ) ) != V_148 ) {
F_31 ( V_10 , L_69 ) ;
V_10 -> V_171 |= 1 << 8 ;
}
V_206 = F_108 ( F_3 ( V_125 -> V_29 . V_30 [ 0 ] ) ) ;
F_15 ( V_10 , L_70 , V_206 ) ;
V_219 = F_109 ( V_10 -> V_225 ) ;
if ( ( V_206 <= 0 ) || ( V_206 > V_219 ) ) {
F_31 ( V_10 , L_71 , V_206 ) ;
F_8 ( V_10 , V_10 -> V_13 ) ;
return;
}
V_221 = V_10 -> V_209 [ V_206 - 1 ] ;
V_112 = F_48 ( V_10 ) ;
if ( ( V_221 == 0x03 ) != ( V_112 -> V_211 == V_212 ) )
V_112 = V_10 -> V_226 ;
if ( V_221 == 0 ) {
F_31 ( V_10 , L_72
L_73 ,
V_206 ) ;
V_224 = true ;
goto V_227;
}
if ( V_221 == V_210 ) {
F_31 ( V_10 , L_74
L_73 ,
V_206 ) ;
V_224 = true ;
goto V_227;
}
V_223 = & V_10 -> V_223 [ F_110 ( V_112 ) ] ;
if ( V_112 -> V_211 == V_212 )
V_209 = V_10 -> V_228 ;
else
V_209 = V_10 -> V_229 ;
V_220 = F_104 ( V_112 , V_10 ,
V_206 ) ;
V_217 = F_17 ( V_209 [ V_220 ] ) ;
if ( V_112 -> V_84 == V_230 ) {
F_15 ( V_10 , L_75 ) ;
F_111 ( V_112 ) ;
}
if ( ( V_217 & V_231 ) && ( V_217 & V_232 ) == V_233 ) {
F_15 ( V_10 , L_76 , V_206 ) ;
V_218 = F_17 ( & V_10 -> V_48 -> V_132 ) ;
if ( ! ( V_218 & V_234 ) ) {
F_31 ( V_10 , L_77 ) ;
goto V_227;
}
if ( F_112 ( V_217 ) ) {
F_15 ( V_10 , L_78 , V_206 ) ;
V_223 -> V_235 |= 1 << V_220 ;
F_113 ( V_10 , V_209 ,
V_220 , V_231 ) ;
F_114 ( V_10 , V_209 , V_220 ,
V_236 ) ;
V_224 = true ;
goto V_227;
} else {
F_15 ( V_10 , L_79 , V_206 ) ;
V_223 -> V_237 [ V_220 ] = V_183 +
F_115 ( 20 ) ;
F_116 ( V_220 , & V_223 -> V_238 ) ;
F_96 ( & V_112 -> V_239 ,
V_223 -> V_237 [ V_220 ] ) ;
}
}
if ( ( V_217 & V_231 ) && ( V_217 & V_232 ) == V_236 &&
F_112 ( V_217 ) ) {
F_15 ( V_10 , L_80 , V_206 ) ;
V_56 = F_117 ( V_112 , V_10 ,
V_220 + 1 ) ;
if ( V_56 && V_10 -> V_62 [ V_56 ] )
F_118 ( V_10 , V_56 ) ;
if ( V_223 -> V_235 & ( 1 << V_220 ) ) {
V_223 -> V_235 &=
~ ( 1 << V_220 ) ;
F_113 ( V_10 , V_209 ,
V_220 , V_231 ) ;
F_106 ( V_112 -> V_120 . V_240 ,
V_220 + 1 ) ;
V_224 = true ;
goto V_227;
}
}
if ( ! F_112 ( V_217 ) &&
F_119 ( V_220 ,
& V_223 -> V_241 ) ) {
F_91 ( & V_223 -> V_242 [ V_220 ] ) ;
V_224 = true ;
goto V_227;
}
if ( V_112 -> V_211 != V_212 )
F_113 ( V_10 , V_209 , V_220 ,
V_231 ) ;
V_227:
F_8 ( V_10 , V_10 -> V_13 ) ;
if ( V_224 )
return;
F_15 ( V_10 , L_81 , V_243 ) ;
F_116 ( V_244 , & V_112 -> V_138 ) ;
F_51 ( & V_10 -> V_123 ) ;
F_120 ( V_112 ) ;
F_54 ( & V_10 -> V_123 ) ;
}
struct V_1 * F_121 ( struct V_1 * V_74 ,
union V_3 * V_245 ,
union V_3 * V_246 ,
T_1 V_247 )
{
T_1 V_248 ;
T_1 V_249 ;
T_1 V_250 ;
struct V_1 * V_75 ;
V_248 = F_1 ( V_74 , V_245 ) ;
V_75 = V_74 ;
do {
if ( V_248 == 0 )
return NULL ;
V_249 = F_1 ( V_75 ,
& V_75 -> V_6 [ V_7 - 1 ] ) ;
V_250 = F_1 ( V_75 , V_246 ) ;
if ( V_250 > 0 ) {
if ( V_248 <= V_250 ) {
if ( V_247 >= V_248 && V_247 <= V_250 )
return V_75 ;
} else {
if ( ( V_247 >= V_248 &&
V_247 <= V_249 ) ||
( V_247 >= V_75 -> V_8 &&
V_247 <= V_250 ) )
return V_75 ;
}
return NULL ;
} else {
if ( V_247 >= V_248 && V_247 <= V_249 )
return V_75 ;
}
V_75 = V_75 -> V_14 ;
V_248 = F_1 ( V_75 , & V_75 -> V_6 [ 0 ] ) ;
} while ( V_75 != V_74 );
return NULL ;
}
static void F_122 ( struct V_9 * V_10 ,
unsigned int V_56 , unsigned int V_57 ,
unsigned int V_58 ,
struct V_81 * V_251 , union V_3 * V_252 )
{
struct V_60 * V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
struct V_105 * V_132 ;
V_132 = F_62 ( V_10 , false , false , V_133 ) ;
if ( ! V_132 )
return;
V_61 -> V_64 |= V_67 ;
V_61 -> V_130 = V_251 ;
V_61 -> V_253 = V_58 ;
F_123 ( V_10 , V_132 , V_56 , V_57 ) ;
F_124 ( V_10 , V_251 -> V_78 -> V_79 , V_57 ) ;
V_61 -> V_130 = NULL ;
V_61 -> V_253 = 0 ;
F_14 ( V_10 ) ;
}
static int F_125 ( struct V_9 * V_10 ,
struct V_94 * V_95 ,
unsigned int V_254 )
{
if ( V_254 == V_255 ||
V_254 == V_256 ||
V_254 == V_257 )
if ( ( V_95 -> V_152 & F_11 ( V_153 ) ) ==
F_11 ( V_258 ) )
return 1 ;
return 0 ;
}
int F_126 ( struct V_9 * V_10 , unsigned int V_254 )
{
if ( V_254 >= 224 && V_254 <= 255 ) {
F_15 ( V_10 , L_82 ,
V_254 ) ;
F_15 ( V_10 , L_83 ) ;
return 1 ;
}
return 0 ;
}
static int F_127 ( struct V_9 * V_10 , struct V_81 * V_251 ,
union V_3 * V_252 , struct V_259 * V_125 ,
struct V_60 * V_61 , int * V_110 , bool V_260 )
{
struct V_85 * V_261 ;
struct V_11 * V_86 ;
unsigned int V_56 ;
int V_57 ;
struct V_78 * V_78 = NULL ;
struct V_94 * V_95 ;
int V_47 = 0 ;
struct V_113 * V_113 ;
T_2 V_254 ;
V_56 = F_99 ( F_3 ( V_125 -> V_138 ) ) ;
V_261 = V_10 -> V_62 [ V_56 ] ;
V_57 = F_128 ( F_3 ( V_125 -> V_138 ) ) - 1 ;
V_86 = F_129 ( V_61 , F_36 ( V_125 -> V_262 ) ) ;
V_95 = F_37 ( V_10 , V_261 -> V_96 , V_57 ) ;
V_254 = F_101 ( F_3 ( V_125 -> V_263 ) ) ;
if ( V_260 )
goto V_264;
if ( V_254 == V_265 ||
V_254 == V_266 ) {
V_61 -> V_130 = V_251 ;
return 0 ;
} else {
if ( V_254 == V_267 ) {
V_61 -> V_130 = V_251 ;
V_61 -> V_253 = V_86 -> V_58 ;
} else if ( F_125 ( V_10 ,
V_95 , V_254 ) ) {
F_122 ( V_10 ,
V_56 , V_57 , V_86 -> V_58 ,
V_251 , V_252 ) ;
} else {
while ( V_86 -> V_24 != V_251 -> F_4 )
F_8 ( V_10 , V_86 ) ;
F_8 ( V_10 , V_86 ) ;
}
V_264:
V_78 = V_251 -> V_78 ;
V_113 = V_78 -> V_114 ;
if ( V_78 -> V_268 > V_78 -> V_269 ) {
F_31 ( V_10 , L_84
L_85
L_86 ,
V_78 -> V_269 ,
V_78 -> V_268 ) ;
V_78 -> V_268 = 0 ;
if ( V_251 -> V_78 -> V_270 & V_271 )
* V_110 = - V_272 ;
else
* V_110 = 0 ;
}
F_61 ( & V_251 -> V_69 ) ;
if ( ! F_28 ( & V_251 -> V_129 ) )
F_61 ( & V_251 -> V_129 ) ;
V_113 -> V_115 ++ ;
if ( V_113 -> V_115 == V_113 -> V_117 ) {
V_47 = 1 ;
if ( F_47 ( V_78 -> V_118 ) == V_119 ) {
F_48 ( V_10 ) -> V_120 . V_121 -- ;
if ( F_48 ( V_10 ) -> V_120 . V_121
== 0 ) {
if ( V_10 -> V_35 & V_122 )
F_49 () ;
}
}
}
}
return V_47 ;
}
static int F_130 ( struct V_9 * V_10 , struct V_81 * V_251 ,
union V_3 * V_252 , struct V_259 * V_125 ,
struct V_60 * V_61 , int * V_110 )
{
struct V_85 * V_261 ;
struct V_11 * V_86 ;
unsigned int V_56 ;
int V_57 ;
struct V_94 * V_95 ;
T_2 V_254 ;
V_56 = F_99 ( F_3 ( V_125 -> V_138 ) ) ;
V_261 = V_10 -> V_62 [ V_56 ] ;
V_57 = F_128 ( F_3 ( V_125 -> V_138 ) ) - 1 ;
V_86 = F_129 ( V_61 , F_36 ( V_125 -> V_262 ) ) ;
V_95 = F_37 ( V_10 , V_261 -> V_96 , V_57 ) ;
V_254 = F_101 ( F_3 ( V_125 -> V_263 ) ) ;
switch ( V_254 ) {
case V_148 :
if ( V_252 == V_86 -> V_24 ) {
F_31 ( V_10 , L_87
L_88 ) ;
* V_110 = - V_55 ;
} else if ( V_252 != V_251 -> F_4 ) {
F_31 ( V_10 , L_89
L_88 ) ;
* V_110 = - V_55 ;
} else {
* V_110 = 0 ;
}
break;
case V_273 :
if ( V_251 -> V_78 -> V_270 & V_271 )
* V_110 = - V_272 ;
else
* V_110 = 0 ;
break;
case V_265 :
case V_266 :
return F_127 ( V_10 , V_251 , V_252 , V_125 , V_61 , V_110 , false ) ;
default:
if ( ! F_125 ( V_10 ,
V_95 , V_254 ) )
break;
F_15 ( V_10 , L_90
L_91 ,
V_254 , V_57 ) ;
case V_267 :
if ( V_252 != V_86 -> V_24 &&
V_252 != V_251 -> F_4 )
V_251 -> V_78 -> V_268 =
V_251 -> V_78 -> V_269 -
F_131 ( F_3 ( V_125 -> V_263 ) ) ;
else
V_251 -> V_78 -> V_268 = 0 ;
F_122 ( V_10 ,
V_56 , V_57 , 0 , V_251 , V_252 ) ;
return F_127 ( V_10 , V_251 , V_252 , V_125 , V_61 , V_110 , true ) ;
}
if ( V_252 != V_86 -> V_24 ) {
if ( V_252 == V_251 -> F_4 ) {
if ( V_251 -> V_78 -> V_268 != 0 ) {
if ( ( * V_110 == - V_274 || * V_110 == 0 ) &&
( V_251 -> V_78 -> V_270
& V_271 ) )
* V_110 = - V_272 ;
} else {
V_251 -> V_78 -> V_268 =
V_251 -> V_78 -> V_269 ;
}
} else {
V_251 -> V_78 -> V_268 =
V_251 -> V_78 -> V_269 -
F_131 ( F_3 ( V_125 -> V_263 ) ) ;
F_15 ( V_10 , L_92
L_93 ) ;
return 0 ;
}
}
return F_127 ( V_10 , V_251 , V_252 , V_125 , V_61 , V_110 , false ) ;
}
static int F_132 ( struct V_9 * V_10 , struct V_81 * V_251 ,
union V_3 * V_252 , struct V_259 * V_125 ,
struct V_60 * V_61 , int * V_110 )
{
struct V_11 * V_86 ;
struct V_113 * V_113 ;
int V_275 ;
int V_276 = 0 ;
union V_3 * V_102 ;
struct V_1 * V_75 ;
struct V_277 * V_278 ;
T_2 V_254 ;
bool V_279 = false ;
V_86 = F_129 ( V_61 , F_36 ( V_125 -> V_262 ) ) ;
V_254 = F_101 ( F_3 ( V_125 -> V_263 ) ) ;
V_113 = V_251 -> V_78 -> V_114 ;
V_275 = V_113 -> V_115 ;
V_278 = & V_251 -> V_78 -> V_280 [ V_275 ] ;
switch ( V_254 ) {
case V_148 :
if ( F_131 ( F_3 ( V_125 -> V_263 ) ) == 0 ) {
V_278 -> V_110 = 0 ;
break;
}
if ( ( V_10 -> V_35 & V_281 ) )
V_254 = V_273 ;
case V_273 :
V_278 -> V_110 = V_251 -> V_78 -> V_270 & V_271 ?
- V_272 : 0 ;
break;
case V_282 :
V_278 -> V_110 = - V_283 ;
V_279 = true ;
break;
case V_284 :
case V_256 :
V_278 -> V_110 = - V_285 ;
V_279 = true ;
break;
case V_286 :
case V_267 :
case V_255 :
V_278 -> V_110 = - V_287 ;
V_279 = true ;
break;
case V_266 :
case V_265 :
break;
default:
V_278 -> V_110 = - 1 ;
break;
}
if ( V_254 == V_148 || V_279 ) {
V_278 -> V_268 = V_278 -> V_117 ;
V_251 -> V_78 -> V_268 += V_278 -> V_117 ;
} else {
for ( V_102 = V_86 -> V_24 ,
V_75 = V_86 -> V_23 ; V_102 != V_252 ;
F_7 ( V_10 , V_86 , & V_75 , & V_102 ) ) {
if ( ! F_133 ( V_102 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_102 -> V_29 . V_30 [ 3 ] ) )
V_276 += F_134 ( F_3 ( V_102 -> V_29 . V_30 [ 2 ] ) ) ;
}
V_276 += F_134 ( F_3 ( V_102 -> V_29 . V_30 [ 2 ] ) ) -
F_131 ( F_3 ( V_125 -> V_263 ) ) ;
if ( V_254 != V_265 ) {
V_278 -> V_268 = V_276 ;
V_251 -> V_78 -> V_268 += V_276 ;
}
}
return F_127 ( V_10 , V_251 , V_252 , V_125 , V_61 , V_110 , false ) ;
}
static int F_135 ( struct V_9 * V_10 , struct V_81 * V_251 ,
struct V_259 * V_125 ,
struct V_60 * V_61 , int * V_110 )
{
struct V_11 * V_86 ;
struct V_113 * V_113 ;
struct V_277 * V_278 ;
int V_275 ;
V_86 = F_129 ( V_61 , F_36 ( V_125 -> V_262 ) ) ;
V_113 = V_251 -> V_78 -> V_114 ;
V_275 = V_113 -> V_115 ;
V_278 = & V_251 -> V_78 -> V_280 [ V_275 ] ;
V_278 -> V_110 = - V_288 ;
V_278 -> V_268 = 0 ;
while ( V_86 -> V_24 != V_251 -> F_4 )
F_8 ( V_10 , V_86 ) ;
F_8 ( V_10 , V_86 ) ;
return F_127 ( V_10 , V_251 , NULL , V_125 , V_61 , V_110 , true ) ;
}
static int F_136 ( struct V_9 * V_10 , struct V_81 * V_251 ,
union V_3 * V_252 , struct V_259 * V_125 ,
struct V_60 * V_61 , int * V_110 )
{
struct V_11 * V_86 ;
union V_3 * V_102 ;
struct V_1 * V_75 ;
T_2 V_254 ;
V_86 = F_129 ( V_61 , F_36 ( V_125 -> V_262 ) ) ;
V_254 = F_101 ( F_3 ( V_125 -> V_263 ) ) ;
switch ( V_254 ) {
case V_148 :
if ( V_252 != V_251 -> F_4 ||
F_131 ( F_3 ( V_125 -> V_263 ) ) != 0 ) {
F_31 ( V_10 , L_94
L_95 ) ;
if ( V_251 -> V_78 -> V_270 & V_271 )
* V_110 = - V_272 ;
else
* V_110 = 0 ;
if ( ( V_10 -> V_35 & V_281 ) )
V_254 = V_273 ;
} else {
* V_110 = 0 ;
}
break;
case V_273 :
if ( V_251 -> V_78 -> V_270 & V_271 )
* V_110 = - V_272 ;
else
* V_110 = 0 ;
break;
default:
break;
}
if ( V_254 == V_273 )
F_15 ( V_10 , L_96
L_97 ,
V_251 -> V_78 -> V_61 -> V_80 . V_289 ,
V_251 -> V_78 -> V_269 ,
F_131 ( F_3 ( V_125 -> V_263 ) ) ) ;
if ( V_252 == V_251 -> F_4 ) {
if ( F_131 ( F_3 ( V_125 -> V_263 ) ) != 0 ) {
V_251 -> V_78 -> V_268 =
V_251 -> V_78 -> V_269 -
F_131 ( F_3 ( V_125 -> V_263 ) ) ;
if ( V_251 -> V_78 -> V_269 <
V_251 -> V_78 -> V_268 ) {
F_31 ( V_10 , L_98
L_99 ,
F_131 ( F_3 ( V_125 -> V_263 ) ) ) ;
V_251 -> V_78 -> V_268 = 0 ;
if ( V_251 -> V_78 -> V_270 & V_271 )
* V_110 = - V_272 ;
else
* V_110 = 0 ;
}
if ( * V_110 == - V_274 ) {
if ( V_251 -> V_78 -> V_270 & V_271 )
* V_110 = - V_272 ;
else
* V_110 = 0 ;
}
} else {
V_251 -> V_78 -> V_268 =
V_251 -> V_78 -> V_269 ;
if ( * V_110 == - V_272 )
* V_110 = 0 ;
}
} else {
V_251 -> V_78 -> V_268 = 0 ;
for ( V_102 = V_86 -> V_24 , V_75 = V_86 -> V_23 ;
V_102 != V_252 ;
F_7 ( V_10 , V_86 , & V_75 , & V_102 ) ) {
if ( ! F_133 ( V_102 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_102 -> V_29 . V_30 [ 3 ] ) )
V_251 -> V_78 -> V_268 +=
F_134 ( F_3 ( V_102 -> V_29 . V_30 [ 2 ] ) ) ;
}
if ( V_254 != V_265 )
V_251 -> V_78 -> V_268 +=
F_134 ( F_3 ( V_102 -> V_29 . V_30 [ 2 ] ) ) -
F_131 ( F_3 ( V_125 -> V_263 ) ) ;
}
return F_127 ( V_10 , V_251 , V_252 , V_125 , V_61 , V_110 , false ) ;
}
static int F_137 ( struct V_9 * V_10 ,
struct V_259 * V_125 )
__releases( &xhci->lock
static int F_138 ( struct V_9 * V_10 )
{
union V_3 * V_125 ;
int V_290 = 1 ;
int V_47 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_24 ) {
V_10 -> V_171 |= 1 << 1 ;
return 0 ;
}
V_125 = V_10 -> V_13 -> V_24 ;
if ( ( F_3 ( V_125 -> V_205 . V_138 ) & V_37 ) !=
V_10 -> V_13 -> V_26 ) {
V_10 -> V_171 |= 1 << 2 ;
return 0 ;
}
F_139 () ;
switch ( ( F_3 ( V_125 -> V_205 . V_138 ) & V_291 ) ) {
case F_40 ( V_292 ) :
F_98 ( V_10 , & V_125 -> V_205 ) ;
break;
case F_40 ( V_293 ) :
F_107 ( V_10 , V_125 ) ;
V_290 = 0 ;
break;
case F_40 ( V_294 ) :
V_47 = F_137 ( V_10 , & V_125 -> V_295 ) ;
if ( V_47 < 0 )
V_10 -> V_171 |= 1 << 9 ;
else
V_290 = 0 ;
break;
case F_40 ( V_296 ) :
F_105 ( V_10 , V_125 ) ;
break;
default:
if ( ( F_3 ( V_125 -> V_205 . V_138 ) & V_291 ) >=
F_40 ( 48 ) )
F_103 ( V_10 , V_125 ) ;
else
V_10 -> V_171 |= 1 << 3 ;
}
if ( V_10 -> V_53 & V_54 ) {
F_15 ( V_10 , L_100
L_101 ) ;
return 0 ;
}
if ( V_290 )
F_8 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_140 ( struct V_111 * V_112 )
{
struct V_9 * V_10 = F_141 ( V_112 ) ;
T_2 V_110 ;
T_3 V_46 ;
union V_3 * V_297 ;
T_1 V_97 ;
F_54 ( & V_10 -> V_123 ) ;
V_110 = F_17 ( & V_10 -> V_48 -> V_110 ) ;
if ( V_110 == 0xffffffff )
goto V_298;
if ( ! ( V_110 & V_299 ) ) {
F_51 ( & V_10 -> V_123 ) ;
return V_300 ;
}
if ( V_110 & V_301 ) {
F_31 ( V_10 , L_102 ) ;
F_24 ( V_10 ) ;
V_298:
F_51 ( & V_10 -> V_123 ) ;
return - V_55 ;
}
V_110 |= V_299 ;
F_16 ( V_110 , & V_10 -> V_48 -> V_110 ) ;
if ( V_112 -> V_302 ) {
T_2 V_303 ;
V_303 = F_17 ( & V_10 -> V_304 -> V_303 ) ;
V_303 |= V_305 ;
F_16 ( V_303 , & V_10 -> V_304 -> V_303 ) ;
}
if ( V_10 -> V_53 & V_54 ) {
F_15 ( V_10 , L_103
L_104 ) ;
V_46 = F_19 ( V_10 , & V_10 -> V_304 -> V_306 ) ;
F_20 ( V_10 , V_46 | V_307 ,
& V_10 -> V_304 -> V_306 ) ;
F_51 ( & V_10 -> V_123 ) ;
return V_308 ;
}
V_297 = V_10 -> V_13 -> V_24 ;
while ( F_138 ( V_10 ) > 0 ) {}
V_46 = F_19 ( V_10 , & V_10 -> V_304 -> V_306 ) ;
if ( V_297 != V_10 -> V_13 -> V_24 ) {
V_97 = F_1 ( V_10 -> V_13 -> V_23 ,
V_10 -> V_13 -> V_24 ) ;
if ( V_97 == 0 )
F_31 ( V_10 , L_105
L_106 ) ;
V_46 &= V_309 ;
V_46 |= ( ( T_3 ) V_97 & ( T_3 ) ~ V_309 ) ;
}
V_46 |= V_307 ;
F_20 ( V_10 , V_46 , & V_10 -> V_304 -> V_306 ) ;
F_51 ( & V_10 -> V_123 ) ;
return V_308 ;
}
T_7 F_142 ( int V_302 , void * V_112 )
{
return F_140 ( V_112 ) ;
}
static void F_143 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_27 ,
T_2 V_310 , T_2 V_311 , T_2 V_312 , T_2 V_313 )
{
struct V_76 * V_4 ;
V_4 = & V_12 -> V_20 -> V_29 ;
V_4 -> V_30 [ 0 ] = F_11 ( V_310 ) ;
V_4 -> V_30 [ 1 ] = F_11 ( V_311 ) ;
V_4 -> V_30 [ 2 ] = F_11 ( V_312 ) ;
V_4 -> V_30 [ 3 ] = F_11 ( V_313 ) ;
F_9 ( V_10 , V_12 , V_27 ) ;
}
static int F_144 ( struct V_9 * V_10 , struct V_11 * V_86 ,
T_2 V_64 , unsigned int V_38 , T_8 V_314 )
{
unsigned int V_315 ;
switch ( V_64 ) {
case V_316 :
F_31 ( V_10 , L_107 ) ;
return - V_317 ;
case V_318 :
F_31 ( V_10 , L_108 ) ;
return - V_319 ;
case V_258 :
F_15 ( V_10 , L_109 ) ;
case V_320 :
case V_321 :
break;
default:
F_22 ( V_10 , L_110 ) ;
return - V_319 ;
}
while ( 1 ) {
if ( F_13 ( V_10 , V_86 , V_38 ) )
break;
if ( V_86 == V_10 -> V_49 ) {
F_22 ( V_10 , L_111 ) ;
return - V_322 ;
}
F_35 ( V_10 , V_323 ,
L_112 ) ;
V_315 = V_38 - V_86 -> V_25 ;
if ( F_145 ( V_10 , V_86 , V_315 ,
V_314 ) ) {
F_22 ( V_10 , L_113 ) ;
return - V_322 ;
}
}
if ( F_6 ( V_86 ) ) {
struct V_11 * V_12 = V_86 ;
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
static int F_146 ( struct V_9 * V_10 ,
struct V_85 * V_261 ,
unsigned int V_57 ,
unsigned int V_58 ,
unsigned int V_38 ,
struct V_78 * V_78 ,
unsigned int V_324 ,
T_8 V_314 )
{
int V_47 ;
struct V_113 * V_113 ;
struct V_81 * V_251 ;
struct V_11 * V_86 ;
struct V_94 * V_95 = F_37 ( V_10 , V_261 -> V_96 , V_57 ) ;
V_86 = F_73 ( V_261 , V_57 , V_58 ) ;
if ( ! V_86 ) {
F_15 ( V_10 , L_114 ,
V_58 ) ;
return - V_319 ;
}
V_47 = F_144 ( V_10 , V_86 ,
F_3 ( V_95 -> V_152 ) & V_153 ,
V_38 , V_314 ) ;
if ( V_47 )
return V_47 ;
V_113 = V_78 -> V_114 ;
V_251 = V_113 -> V_251 [ V_324 ] ;
F_147 ( & V_251 -> V_69 ) ;
F_147 ( & V_251 -> V_129 ) ;
if ( V_324 == 0 ) {
V_47 = F_148 ( F_46 ( V_78 -> V_79 -> V_116 ) , V_78 ) ;
if ( F_56 ( V_47 ) )
return V_47 ;
}
V_251 -> V_78 = V_78 ;
F_149 ( & V_251 -> V_69 , & V_86 -> V_69 ) ;
V_251 -> V_74 = V_86 -> V_32 ;
V_251 -> V_103 = V_86 -> V_20 ;
V_113 -> V_251 [ V_324 ] = V_251 ;
return 0 ;
}
static unsigned int F_150 ( struct V_9 * V_10 , struct V_78 * V_78 )
{
int V_325 , V_38 , V_326 , V_217 , V_136 ;
struct V_327 * V_328 ;
V_328 = NULL ;
V_325 = V_78 -> V_329 ;
V_217 = V_78 -> V_269 ;
V_38 = 0 ;
F_151 (urb->sg, sg, num_sgs, i) {
unsigned int V_276 = F_152 ( V_328 ) ;
V_326 = V_330 -
( F_153 ( V_328 ) & ( V_330 - 1 ) ) ;
V_326 &= V_330 - 1 ;
if ( V_326 != 0 )
V_38 ++ ;
while ( V_326 < F_152 ( V_328 ) && V_326 < V_217 ) {
V_38 ++ ;
V_326 += V_330 ;
}
V_276 = F_154 ( int , V_276 , V_217 ) ;
V_217 -= V_276 ;
if ( V_217 == 0 )
break;
}
return V_38 ;
}
static void F_155 ( struct V_78 * V_78 , int V_38 , int V_326 )
{
if ( V_38 != 0 )
F_156 ( & V_78 -> V_79 -> V_79 , L_115
L_116 , V_243 ,
V_78 -> V_61 -> V_80 . V_289 , V_38 ) ;
if ( V_326 != V_78 -> V_269 )
F_156 ( & V_78 -> V_79 -> V_79 , L_117
L_118 ,
V_243 ,
V_78 -> V_61 -> V_80 . V_289 ,
V_326 , V_326 ,
V_78 -> V_269 ,
V_78 -> V_269 ) ;
}
static void F_157 ( struct V_9 * V_10 , int V_56 ,
unsigned int V_57 , unsigned int V_58 , int V_331 ,
struct V_76 * V_245 )
{
F_12 () ;
if ( V_331 )
V_245 -> V_30 [ 3 ] |= F_11 ( V_331 ) ;
else
V_245 -> V_30 [ 3 ] &= F_11 ( ~ V_37 ) ;
F_25 ( V_10 , V_56 , V_57 , V_58 ) ;
}
int F_158 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_78 * V_78 , int V_56 , unsigned int V_57 )
{
struct V_94 * V_95 = F_37 ( V_10 ,
V_10 -> V_62 [ V_56 ] -> V_96 , V_57 ) ;
int V_332 ;
int V_333 ;
V_332 = F_159 ( F_3 ( V_95 -> V_152 ) ) ;
V_333 = V_78 -> V_334 ;
if ( V_78 -> V_79 -> V_211 == V_335 ||
V_78 -> V_79 -> V_211 == V_336 )
V_333 *= 8 ;
if ( V_332 != V_333 ) {
F_160 ( & V_78 -> V_79 -> V_79 ,
L_119 ,
V_333 , V_333 == 1 ? L_120 : L_121 ,
V_332 , V_332 == 1 ? L_120 : L_121 ) ;
V_78 -> V_334 = V_332 ;
if ( V_78 -> V_79 -> V_211 == V_335 ||
V_78 -> V_79 -> V_211 == V_336 )
V_78 -> V_334 /= 8 ;
}
return F_161 ( V_10 , V_314 , V_78 , V_56 , V_57 ) ;
}
static T_2 F_162 ( unsigned int V_337 )
{
T_2 V_338 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_337 >> 10 ) >= V_338 )
return V_338 << 17 ;
else
return ( V_337 >> 10 ) << 17 ;
}
static T_2 F_163 ( int V_326 , int V_339 ,
unsigned int V_340 , struct V_78 * V_78 ,
unsigned int V_341 )
{
int V_342 ;
if ( V_341 == 0 || ( V_326 == 0 && V_339 == 0 ) )
return 0 ;
V_342 = ( V_326 + V_339 ) /
F_164 ( F_165 ( & V_78 -> V_61 -> V_80 ) ) ;
if ( ( V_340 - V_342 ) > 31 )
return 31 << 17 ;
return ( V_340 - V_342 ) << 17 ;
}
static int F_166 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_78 * V_78 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_86 ;
unsigned int V_38 ;
struct V_113 * V_113 ;
struct V_81 * V_251 ;
struct V_327 * V_328 ;
int V_325 ;
int V_339 , V_343 , V_326 ;
unsigned int V_340 ;
bool V_103 ;
T_3 V_87 ;
bool V_27 ;
struct V_76 * V_245 ;
int V_331 ;
V_86 = F_32 ( V_10 , V_78 ) ;
if ( ! V_86 )
return - V_319 ;
V_38 = F_150 ( V_10 , V_78 ) ;
V_325 = V_78 -> V_329 ;
V_340 = F_167 ( V_78 -> V_269 ,
F_165 ( & V_78 -> V_61 -> V_80 ) ) ;
V_339 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_78 -> V_58 ,
V_38 , V_78 , 0 , V_314 ) ;
if ( V_339 < 0 )
return V_339 ;
V_113 = V_78 -> V_114 ;
V_251 = V_113 -> V_251 [ 0 ] ;
V_245 = & V_86 -> V_20 -> V_29 ;
V_331 = V_86 -> V_26 ;
V_326 = 0 ;
V_328 = V_78 -> V_328 ;
V_87 = ( T_3 ) F_153 ( V_328 ) ;
V_343 = F_152 ( V_328 ) ;
V_339 = V_330 - ( V_87 & ( V_330 - 1 ) ) ;
V_339 = F_154 ( int , V_339 , V_343 ) ;
if ( V_339 > V_78 -> V_269 )
V_339 = V_78 -> V_269 ;
V_103 = true ;
do {
T_2 V_30 = 0 ;
T_2 V_344 = 0 ;
T_2 V_337 = 0 ;
if ( V_103 ) {
V_103 = false ;
if ( V_331 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_86 -> V_26 ;
if ( V_38 > 1 ) {
V_30 |= V_31 ;
} else {
V_251 -> F_4 = V_86 -> V_20 ;
V_30 |= V_345 ;
}
if ( F_168 ( V_78 ) )
V_30 |= V_346 ;
if ( V_330 -
( V_87 & ( V_330 - 1 ) ) < V_339 ) {
F_31 ( V_10 , L_122 ) ;
F_15 ( V_10 , L_123 ,
( unsigned int ) ( V_87 + V_330 ) & ~ ( V_330 - 1 ) ,
( unsigned int ) V_87 + V_339 ) ;
}
if ( V_10 -> V_347 < 0x100 ) {
V_337 = F_162 (
V_78 -> V_269 -
V_326 ) ;
} else {
V_337 = F_163 ( V_326 ,
V_339 , V_340 , V_78 ,
V_38 - 1 ) ;
}
V_344 = F_134 ( V_339 ) |
V_337 |
F_169 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_143 ( V_10 , V_86 , V_27 ,
F_170 ( V_87 ) ,
F_171 ( V_87 ) ,
V_344 ,
V_30 | F_40 ( V_348 ) ) ;
-- V_38 ;
V_326 += V_339 ;
V_343 -= V_339 ;
if ( V_343 == 0 ) {
-- V_325 ;
if ( V_325 == 0 )
break;
V_328 = F_172 ( V_328 ) ;
V_87 = ( T_3 ) F_153 ( V_328 ) ;
V_343 = F_152 ( V_328 ) ;
} else {
V_87 += V_339 ;
}
V_339 = V_330 -
( V_87 & ( V_330 - 1 ) ) ;
V_339 = F_154 ( int , V_339 , V_343 ) ;
if ( V_326 + V_339 > V_78 -> V_269 )
V_339 =
V_78 -> V_269 - V_326 ;
} while ( V_326 < V_78 -> V_269 );
F_155 ( V_78 , V_38 , V_326 ) ;
F_157 ( V_10 , V_56 , V_57 , V_78 -> V_58 ,
V_331 , V_245 ) ;
return 0 ;
}
int F_161 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_78 * V_78 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_86 ;
struct V_113 * V_113 ;
struct V_81 * V_251 ;
int V_38 ;
struct V_76 * V_245 ;
bool V_103 ;
bool V_27 ;
int V_331 ;
T_2 V_30 , V_344 ;
int V_326 , V_339 , V_47 ;
unsigned int V_340 ;
T_3 V_87 ;
if ( V_78 -> V_325 )
return F_166 ( V_10 , V_314 , V_78 , V_56 , V_57 ) ;
V_86 = F_32 ( V_10 , V_78 ) ;
if ( ! V_86 )
return - V_319 ;
V_38 = 0 ;
V_326 = V_330 -
( V_78 -> V_349 & ( V_330 - 1 ) ) ;
V_326 &= V_330 - 1 ;
if ( V_326 != 0 || V_78 -> V_269 == 0 )
V_38 ++ ;
while ( V_326 < V_78 -> V_269 ) {
V_38 ++ ;
V_326 += V_330 ;
}
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_78 -> V_58 ,
V_38 , V_78 , 0 , V_314 ) ;
if ( V_47 < 0 )
return V_47 ;
V_113 = V_78 -> V_114 ;
V_251 = V_113 -> V_251 [ 0 ] ;
V_245 = & V_86 -> V_20 -> V_29 ;
V_331 = V_86 -> V_26 ;
V_326 = 0 ;
V_340 = F_167 ( V_78 -> V_269 ,
F_165 ( & V_78 -> V_61 -> V_80 ) ) ;
V_87 = ( T_3 ) V_78 -> V_349 ;
V_339 = V_330 -
( V_78 -> V_349 & ( V_330 - 1 ) ) ;
if ( V_339 > V_78 -> V_269 )
V_339 = V_78 -> V_269 ;
V_103 = true ;
do {
T_2 V_337 = 0 ;
V_30 = 0 ;
if ( V_103 ) {
V_103 = false ;
if ( V_331 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_86 -> V_26 ;
if ( V_38 > 1 ) {
V_30 |= V_31 ;
} else {
V_251 -> F_4 = V_86 -> V_20 ;
V_30 |= V_345 ;
}
if ( F_168 ( V_78 ) )
V_30 |= V_346 ;
if ( V_10 -> V_347 < 0x100 ) {
V_337 = F_162 (
V_78 -> V_269 -
V_326 ) ;
} else {
V_337 = F_163 ( V_326 ,
V_339 , V_340 , V_78 ,
V_38 - 1 ) ;
}
V_344 = F_134 ( V_339 ) |
V_337 |
F_169 ( 0 ) ;
if ( V_38 > 1 )
V_27 = true ;
else
V_27 = false ;
F_143 ( V_10 , V_86 , V_27 ,
F_170 ( V_87 ) ,
F_171 ( V_87 ) ,
V_344 ,
V_30 | F_40 ( V_348 ) ) ;
-- V_38 ;
V_326 += V_339 ;
V_87 += V_339 ;
V_339 = V_78 -> V_269 - V_326 ;
if ( V_339 > V_330 )
V_339 = V_330 ;
} while ( V_326 < V_78 -> V_269 );
F_155 ( V_78 , V_38 , V_326 ) ;
F_157 ( V_10 , V_56 , V_57 , V_78 -> V_58 ,
V_331 , V_245 ) ;
return 0 ;
}
int F_173 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_78 * V_78 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_86 ;
int V_38 ;
int V_47 ;
struct V_350 * V_351 ;
struct V_76 * V_245 ;
int V_331 ;
T_2 V_30 , V_344 ;
struct V_113 * V_113 ;
struct V_81 * V_251 ;
V_86 = F_32 ( V_10 , V_78 ) ;
if ( ! V_86 )
return - V_319 ;
if ( ! V_78 -> V_352 )
return - V_319 ;
V_38 = 2 ;
if ( V_78 -> V_269 > 0 )
V_38 ++ ;
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] ,
V_57 , V_78 -> V_58 ,
V_38 , V_78 , 0 , V_314 ) ;
if ( V_47 < 0 )
return V_47 ;
V_113 = V_78 -> V_114 ;
V_251 = V_113 -> V_251 [ 0 ] ;
V_245 = & V_86 -> V_20 -> V_29 ;
V_331 = V_86 -> V_26 ;
V_351 = (struct V_350 * ) V_78 -> V_352 ;
V_30 = 0 ;
V_30 |= V_353 | F_40 ( V_354 ) ;
if ( V_331 == 0 )
V_30 |= 0x1 ;
if ( V_10 -> V_347 == 0x100 ) {
if ( V_78 -> V_269 > 0 ) {
if ( V_351 -> V_355 & V_356 )
V_30 |= F_174 ( V_357 ) ;
else
V_30 |= F_174 ( V_358 ) ;
}
}
F_143 ( V_10 , V_86 , true ,
V_351 -> V_355 | V_351 -> V_359 << 8 | F_175 ( V_351 -> V_360 ) << 16 ,
F_175 ( V_351 -> V_361 ) | F_175 ( V_351 -> V_362 ) << 16 ,
F_134 ( 8 ) | F_169 ( 0 ) ,
V_30 ) ;
if ( F_168 ( V_78 ) )
V_30 = V_346 | F_40 ( V_363 ) ;
else
V_30 = F_40 ( V_363 ) ;
V_344 = F_134 ( V_78 -> V_269 ) |
F_162 ( V_78 -> V_269 ) |
F_169 ( 0 ) ;
if ( V_78 -> V_269 > 0 ) {
if ( V_351 -> V_355 & V_356 )
V_30 |= V_364 ;
F_143 ( V_10 , V_86 , true ,
F_170 ( V_78 -> V_349 ) ,
F_171 ( V_78 -> V_349 ) ,
V_344 ,
V_30 | V_86 -> V_26 ) ;
}
V_251 -> F_4 = V_86 -> V_20 ;
if ( V_78 -> V_269 > 0 && V_351 -> V_355 & V_356 )
V_30 = 0 ;
else
V_30 = V_364 ;
F_143 ( V_10 , V_86 , false ,
0 ,
0 ,
F_169 ( 0 ) ,
V_30 | V_345 | F_40 ( V_365 ) | V_86 -> V_26 ) ;
F_157 ( V_10 , V_56 , V_57 , 0 ,
V_331 , V_245 ) ;
return 0 ;
}
static int F_176 ( struct V_9 * V_10 ,
struct V_78 * V_78 , int V_136 )
{
int V_38 = 0 ;
T_3 V_87 , V_366 ;
V_87 = ( T_3 ) ( V_78 -> V_349 + V_78 -> V_280 [ V_136 ] . V_367 ) ;
V_366 = V_78 -> V_280 [ V_136 ] . V_117 ;
V_38 = F_167 ( V_366 + ( V_87 & ( V_330 - 1 ) ) ,
V_330 ) ;
if ( V_38 == 0 )
V_38 ++ ;
return V_38 ;
}
static unsigned int F_177 ( struct V_9 * V_10 ,
struct V_213 * V_214 ,
struct V_78 * V_78 , unsigned int V_340 )
{
unsigned int V_368 ;
if ( V_10 -> V_347 < 0x100 || V_214 -> V_211 != V_369 )
return 0 ;
V_368 = V_78 -> V_61 -> V_370 . V_371 ;
return F_167 ( V_340 , V_368 + 1 ) - 1 ;
}
static unsigned int F_178 ( struct V_9 * V_10 ,
struct V_213 * V_214 ,
struct V_78 * V_78 , unsigned int V_340 )
{
unsigned int V_368 ;
unsigned int V_372 ;
if ( V_10 -> V_347 < 0x100 )
return 0 ;
switch ( V_214 -> V_211 ) {
case V_369 :
V_368 = V_78 -> V_61 -> V_370 . V_371 ;
V_372 = V_340 % ( V_368 + 1 ) ;
if ( V_372 == 0 )
return V_368 ;
return V_372 - 1 ;
default:
if ( V_340 == 0 )
return 0 ;
return V_340 - 1 ;
}
}
static int F_179 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_78 * V_78 , int V_56 , unsigned int V_57 )
{
struct V_11 * V_86 ;
struct V_113 * V_113 ;
struct V_81 * V_251 ;
int V_373 , V_374 ;
struct V_76 * V_245 ;
bool V_103 ;
int V_331 ;
T_2 V_30 , V_344 ;
int V_326 , V_339 , V_366 , V_375 , V_47 ;
T_3 V_376 , V_87 ;
int V_136 , V_137 ;
bool V_27 ;
V_86 = V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] . V_12 ;
V_373 = V_78 -> V_377 ;
if ( V_373 < 1 ) {
F_15 ( V_10 , L_124 ) ;
return - V_319 ;
}
V_376 = ( T_3 ) V_78 -> V_349 ;
V_245 = & V_86 -> V_20 -> V_29 ;
V_331 = V_86 -> V_26 ;
V_113 = V_78 -> V_114 ;
for ( V_136 = 0 ; V_136 < V_373 ; V_136 ++ ) {
unsigned int V_340 ;
unsigned int V_378 ;
unsigned int V_372 ;
V_103 = true ;
V_326 = 0 ;
V_87 = V_376 + V_78 -> V_280 [ V_136 ] . V_367 ;
V_366 = V_78 -> V_280 [ V_136 ] . V_117 ;
V_375 = V_366 ;
V_340 = F_167 ( V_366 ,
F_164 (
F_165 ( & V_78 -> V_61 -> V_80 ) ) ) ;
if ( V_340 == 0 )
V_340 ++ ;
V_378 = F_177 ( V_10 , V_78 -> V_79 , V_78 ,
V_340 ) ;
V_372 = F_178 ( V_10 ,
V_78 -> V_79 , V_78 , V_340 ) ;
V_374 = F_176 ( V_10 , V_78 , V_136 ) ;
V_47 = F_146 ( V_10 , V_10 -> V_62 [ V_56 ] , V_57 ,
V_78 -> V_58 , V_374 , V_78 , V_136 , V_314 ) ;
if ( V_47 < 0 ) {
if ( V_136 == 0 )
return V_47 ;
goto V_227;
}
V_251 = V_113 -> V_251 [ V_136 ] ;
for ( V_137 = 0 ; V_137 < V_374 ; V_137 ++ ) {
T_2 V_337 = 0 ;
V_30 = 0 ;
if ( V_103 ) {
V_30 = F_180 ( V_378 ) |
F_181 ( V_372 ) ;
V_30 |= F_40 ( V_379 ) ;
V_30 |= V_380 ;
if ( V_136 == 0 ) {
if ( V_331 == 0 )
V_30 |= 0x1 ;
} else
V_30 |= V_86 -> V_26 ;
V_103 = false ;
} else {
V_30 |= F_40 ( V_348 ) ;
V_30 |= V_86 -> V_26 ;
}
if ( F_168 ( V_78 ) )
V_30 |= V_346 ;
if ( V_137 < V_374 - 1 ) {
V_30 |= V_31 ;
V_27 = true ;
} else {
V_251 -> F_4 = V_86 -> V_20 ;
V_30 |= V_345 ;
if ( V_10 -> V_347 == 0x100 &&
! ( V_10 -> V_35 &
V_381 ) ) {
if ( V_136 < V_373 - 1 )
V_30 |= V_382 ;
}
V_27 = false ;
}
V_339 = V_330 -
( V_87 & ( ( 1 << V_383 ) - 1 ) ) ;
if ( V_339 > V_375 )
V_339 = V_375 ;
if ( V_10 -> V_347 < 0x100 ) {
V_337 = F_162 (
V_366 - V_326 ) ;
} else {
V_337 = F_163 (
V_326 , V_339 ,
V_340 , V_78 ,
( V_374 - V_137 - 1 ) ) ;
}
V_344 = F_134 ( V_339 ) |
V_337 |
F_169 ( 0 ) ;
F_143 ( V_10 , V_86 , V_27 ,
F_170 ( V_87 ) ,
F_171 ( V_87 ) ,
V_344 ,
V_30 ) ;
V_326 += V_339 ;
V_87 += V_339 ;
V_375 -= V_339 ;
}
if ( V_326 != V_366 ) {
F_22 ( V_10 , L_125 ) ;
V_47 = - V_319 ;
goto V_227;
}
}
if ( F_48 ( V_10 ) -> V_120 . V_121 == 0 ) {
if ( V_10 -> V_35 & V_122 )
F_182 () ;
}
F_48 ( V_10 ) -> V_120 . V_121 ++ ;
F_157 ( V_10 , V_56 , V_57 , V_78 -> V_58 ,
V_331 , V_245 ) ;
return 0 ;
V_227:
for ( V_136 -- ; V_136 >= 0 ; V_136 -- )
F_61 ( & V_113 -> V_251 [ V_136 ] -> V_69 ) ;
V_113 -> V_251 [ 0 ] -> F_4 = V_86 -> V_20 ;
F_39 ( V_10 , V_86 , V_113 -> V_251 [ 0 ] , true ) ;
V_86 -> V_20 = V_113 -> V_251 [ 0 ] -> V_103 ;
V_86 -> V_32 = V_113 -> V_251 [ 0 ] -> V_74 ;
V_86 -> V_26 = V_331 ;
V_86 -> V_25 = V_86 -> V_142 ;
F_50 ( F_46 ( V_78 -> V_79 -> V_116 ) , V_78 ) ;
return V_47 ;
}
int F_183 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_78 * V_78 , int V_56 , unsigned int V_57 )
{
struct V_85 * V_261 ;
struct V_11 * V_86 ;
struct V_94 * V_95 ;
int V_384 ;
int V_332 ;
int V_333 ;
int V_373 , V_38 , V_136 ;
int V_47 ;
V_261 = V_10 -> V_62 [ V_56 ] ;
V_86 = V_261 -> V_63 [ V_57 ] . V_12 ;
V_95 = F_37 ( V_10 , V_261 -> V_96 , V_57 ) ;
V_38 = 0 ;
V_373 = V_78 -> V_377 ;
for ( V_136 = 0 ; V_136 < V_373 ; V_136 ++ )
V_38 += F_176 ( V_10 , V_78 , V_136 ) ;
V_47 = F_144 ( V_10 , V_86 , F_3 ( V_95 -> V_152 ) & V_153 ,
V_38 , V_314 ) ;
if ( V_47 )
return V_47 ;
V_384 = F_17 ( & V_10 -> V_385 -> V_386 ) ;
V_384 &= 0x3fff ;
V_78 -> V_384 = V_384 ;
if ( V_78 -> V_79 -> V_211 == V_335 ||
V_78 -> V_79 -> V_211 == V_336 )
V_78 -> V_384 >>= 3 ;
V_332 = F_159 ( F_3 ( V_95 -> V_152 ) ) ;
V_333 = V_78 -> V_334 ;
if ( V_78 -> V_79 -> V_211 == V_335 ||
V_78 -> V_79 -> V_211 == V_336 )
V_333 *= 8 ;
if ( V_332 != V_333 ) {
F_160 ( & V_78 -> V_79 -> V_79 ,
L_119 ,
V_333 , V_333 == 1 ? L_120 : L_121 ,
V_332 , V_332 == 1 ? L_120 : L_121 ) ;
V_78 -> V_334 = V_332 ;
if ( V_78 -> V_79 -> V_211 == V_335 ||
V_78 -> V_79 -> V_211 == V_336 )
V_78 -> V_334 /= 8 ;
}
V_86 -> V_142 = V_86 -> V_25 ;
return F_179 ( V_10 , V_314 , V_78 , V_56 , V_57 ) ;
}
static int F_184 ( struct V_9 * V_10 , struct V_105 * V_106 ,
T_2 V_310 , T_2 V_311 ,
T_2 V_312 , T_2 V_313 , bool V_387 )
{
int V_388 = V_10 -> V_389 ;
int V_47 ;
if ( V_10 -> V_53 & V_54 )
return - V_55 ;
if ( ! V_387 )
V_388 ++ ;
V_47 = F_144 ( V_10 , V_10 -> V_49 , V_321 ,
V_388 , V_133 ) ;
if ( V_47 < 0 ) {
F_22 ( V_10 , L_126 ) ;
if ( V_387 )
F_22 ( V_10 , L_127
L_128 ) ;
return V_47 ;
}
V_106 -> V_179 = V_10 -> V_49 -> V_20 ;
F_149 ( & V_106 -> V_172 , & V_10 -> V_172 ) ;
if ( V_10 -> V_172 . V_14 == & V_106 -> V_172 &&
! F_185 ( & V_10 -> V_182 ) ) {
V_10 -> V_181 = V_106 ;
F_96 ( & V_10 -> V_182 , V_183 + V_184 ) ;
}
F_143 ( V_10 , V_10 -> V_49 , false , V_310 , V_311 , V_312 ,
V_313 | V_10 -> V_49 -> V_26 ) ;
return 0 ;
}
int F_186 ( struct V_9 * V_10 , struct V_105 * V_106 ,
T_2 V_203 , T_2 V_56 )
{
return F_184 ( V_10 , V_106 , 0 , 0 , 0 ,
F_40 ( V_203 ) | F_187 ( V_56 ) , false ) ;
}
int F_188 ( struct V_9 * V_10 , struct V_105 * V_106 ,
T_1 V_390 , T_2 V_56 , enum V_391 V_351 )
{
return F_184 ( V_10 , V_106 , F_170 ( V_390 ) ,
F_171 ( V_390 ) , 0 ,
F_40 ( V_197 ) | F_187 ( V_56 )
| ( V_351 == V_392 ? V_393 : 0 ) , false ) ;
}
int F_189 ( struct V_9 * V_10 , struct V_105 * V_106 ,
T_2 V_310 , T_2 V_311 , T_2 V_312 , T_2 V_313 )
{
return F_184 ( V_10 , V_106 , V_310 , V_311 , V_312 , V_313 , false ) ;
}
int F_190 ( struct V_9 * V_10 , struct V_105 * V_106 ,
T_2 V_56 )
{
return F_184 ( V_10 , V_106 , 0 , 0 , 0 ,
F_40 ( V_201 ) | F_187 ( V_56 ) ,
false ) ;
}
int F_77 ( struct V_9 * V_10 ,
struct V_105 * V_106 , T_1 V_390 ,
T_2 V_56 , bool V_387 )
{
return F_184 ( V_10 , V_106 , F_170 ( V_390 ) ,
F_171 ( V_390 ) , 0 ,
F_40 ( V_195 ) | F_187 ( V_56 ) ,
V_387 ) ;
}
int F_191 ( struct V_9 * V_10 , struct V_105 * V_106 ,
T_1 V_390 , T_2 V_56 , bool V_387 )
{
return F_184 ( V_10 , V_106 , F_170 ( V_390 ) ,
F_171 ( V_390 ) , 0 ,
F_40 ( V_196 ) | F_187 ( V_56 ) ,
V_387 ) ;
}
int F_192 ( struct V_9 * V_10 , struct V_105 * V_106 ,
int V_56 , unsigned int V_57 , int V_394 )
{
T_2 V_395 = F_187 ( V_56 ) ;
T_2 V_396 = F_193 ( V_57 ) ;
T_2 type = F_40 ( V_198 ) ;
T_2 V_397 = F_194 ( V_394 ) ;
return F_184 ( V_10 , V_106 , 0 , 0 , 0 ,
V_395 | V_396 | type | V_397 , false ) ;
}
static int F_42 ( struct V_9 * V_10 , struct V_105 * V_106 ,
int V_56 ,
unsigned int V_57 , unsigned int V_58 ,
struct V_1 * V_23 ,
union V_3 * V_398 , T_2 V_26 )
{
T_1 V_87 ;
T_2 V_395 = F_187 ( V_56 ) ;
T_2 V_396 = F_193 ( V_57 ) ;
T_2 V_399 = F_195 ( V_58 ) ;
T_2 V_400 = 0 ;
T_2 type = F_40 ( V_199 ) ;
struct V_60 * V_61 ;
V_87 = F_1 ( V_23 , V_398 ) ;
if ( V_87 == 0 ) {
F_31 ( V_10 , L_129 ) ;
F_31 ( V_10 , L_130 ,
V_23 , V_398 ) ;
return 0 ;
}
V_61 = & V_10 -> V_62 [ V_56 ] -> V_63 [ V_57 ] ;
if ( ( V_61 -> V_64 & V_66 ) ) {
F_31 ( V_10 , L_129 ) ;
F_31 ( V_10 , L_131 ) ;
return 0 ;
}
V_61 -> V_158 = V_23 ;
V_61 -> V_144 = V_398 ;
if ( V_58 )
V_400 = F_196 ( V_401 ) ;
return F_184 ( V_10 , V_106 ,
F_170 ( V_87 ) | V_400 | V_26 ,
F_171 ( V_87 ) , V_399 ,
V_395 | V_396 | type , false ) ;
}
int F_123 ( struct V_9 * V_10 , struct V_105 * V_106 ,
int V_56 , unsigned int V_57 )
{
T_2 V_395 = F_187 ( V_56 ) ;
T_2 V_396 = F_193 ( V_57 ) ;
T_2 type = F_40 ( V_200 ) ;
return F_184 ( V_10 , V_106 , 0 , 0 , 0 ,
V_395 | V_396 | type , false ) ;
}
