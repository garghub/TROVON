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
F_20 ( & V_10 -> V_51 , V_52 + ( 2 * V_53 ) ) ;
F_21 ( V_10 , V_46 | V_54 ,
& V_10 -> V_48 -> V_49 ) ;
V_47 = F_22 ( & V_10 -> V_48 -> V_49 ,
V_55 , 0 , 5 * 1000 * 1000 ) ;
if ( V_47 < 0 ) {
F_21 ( V_10 , V_46 | V_54 ,
& V_10 -> V_48 -> V_49 ) ;
F_23 ( 1000 ) ;
V_47 = F_22 ( & V_10 -> V_48 -> V_49 ,
V_55 , 0 , 3 * 1000 * 1000 ) ;
if ( V_47 == 0 )
return 0 ;
F_24 ( V_10 , L_3
L_4 ) ;
F_25 ( & V_10 -> V_51 ) ;
V_10 -> V_56 |= V_57 ;
F_26 ( V_10 ) ;
F_27 ( V_10 ) ;
return - V_58 ;
}
return 0 ;
}
void F_28 ( struct V_9 * V_10 ,
unsigned int V_59 ,
unsigned int V_60 ,
unsigned int V_61 )
{
T_4 T_5 * V_62 = & V_10 -> V_44 -> V_45 [ V_59 ] ;
struct V_63 * V_64 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
unsigned int V_67 = V_64 -> V_67 ;
if ( ( V_67 & V_68 ) || ( V_67 & V_69 ) ||
( V_67 & V_70 ) )
return;
F_16 ( F_29 ( V_60 , V_61 ) , V_62 ) ;
}
static void F_30 ( struct V_9 * V_10 ,
unsigned int V_59 ,
unsigned int V_60 )
{
unsigned int V_61 ;
struct V_63 * V_64 ;
V_64 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
if ( ! ( V_64 -> V_67 & V_71 ) ) {
if ( V_64 -> V_12 && ! ( F_31 ( & V_64 -> V_12 -> V_72 ) ) )
F_28 ( V_10 , V_59 , V_60 , 0 ) ;
return;
}
for ( V_61 = 1 ; V_61 < V_64 -> V_73 -> V_74 ;
V_61 ++ ) {
struct V_75 * V_73 = V_64 -> V_73 ;
if ( ! F_31 ( & V_73 -> V_76 [ V_61 ] -> V_72 ) )
F_28 ( V_10 , V_59 , V_60 ,
V_61 ) ;
}
}
struct V_11 * F_32 ( struct V_9 * V_10 ,
unsigned int V_59 , unsigned int V_60 ,
unsigned int V_61 )
{
struct V_63 * V_64 ;
V_64 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
if ( ! ( V_64 -> V_67 & V_71 ) )
return V_64 -> V_12 ;
if ( V_61 == 0 ) {
F_33 ( V_10 ,
L_5
L_6 ,
V_59 , V_60 ) ;
return NULL ;
}
if ( V_61 < V_64 -> V_73 -> V_74 )
return V_64 -> V_73 -> V_76 [ V_61 ] ;
F_33 ( V_10 ,
L_7
L_8
L_9 ,
V_59 , V_60 ,
V_64 -> V_73 -> V_74 - 1 ,
V_61 ) ;
return NULL ;
}
void F_34 ( struct V_9 * V_10 ,
unsigned int V_59 , unsigned int V_60 ,
unsigned int V_61 , struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = V_10 -> V_65 [ V_59 ] ;
struct V_63 * V_64 = & V_82 -> V_66 [ V_60 ] ;
struct V_11 * V_83 ;
struct V_1 * V_84 ;
union V_3 * V_85 ;
T_1 V_86 ;
T_3 V_87 ;
bool V_88 = false ;
bool V_89 = false ;
V_83 = F_32 ( V_10 , V_59 ,
V_60 , V_61 ) ;
if ( ! V_83 ) {
F_33 ( V_10 , L_10
L_11 ,
V_61 ) ;
return;
}
F_35 ( V_10 , V_90 ,
L_12 ) ;
if ( V_64 -> V_67 & V_71 ) {
struct V_91 * V_92 =
& V_64 -> V_73 -> V_93 [ V_61 ] ;
V_87 = F_36 ( V_92 -> V_94 ) ;
} else {
struct V_95 * V_96
= F_37 ( V_10 , V_82 -> V_97 , V_60 ) ;
V_87 = F_36 ( V_96 -> V_98 ) ;
}
V_84 = V_83 -> V_23 ;
V_85 = V_83 -> V_24 ;
V_80 -> V_99 = V_87 & 0x1 ;
do {
if ( ! V_88 && F_1 ( V_84 , V_85 )
== ( T_1 ) ( V_87 & ~ 0xf ) ) {
V_88 = true ;
if ( V_89 )
break;
}
if ( V_85 == V_78 -> F_4 )
V_89 = true ;
if ( V_88 &&
F_5 ( V_85 -> V_29 . V_30 [ 3 ] ) &&
V_85 -> V_29 . V_30 [ 3 ] & F_11 ( V_18 ) )
V_80 -> V_99 ^= 0x1 ;
F_7 ( V_10 , V_83 , & V_84 , & V_85 ) ;
if ( V_85 == V_64 -> V_12 -> V_24 ) {
F_24 ( V_10 , L_13 ) ;
V_80 -> V_100 = NULL ;
V_80 -> V_101 = NULL ;
return;
}
} while ( ! V_88 || ! V_89 );
V_80 -> V_100 = V_84 ;
V_80 -> V_101 = V_85 ;
F_35 ( V_10 , V_90 ,
L_14 , V_80 -> V_99 ) ;
F_35 ( V_10 , V_90 ,
L_15 ,
V_80 -> V_100 ) ;
V_86 = F_1 ( V_80 -> V_100 , V_80 -> V_101 ) ;
F_35 ( V_10 , V_90 ,
L_16 ,
( unsigned long long ) V_86 ) ;
}
static void F_38 ( struct V_9 * V_10 , struct V_11 * V_83 ,
struct V_77 * V_78 , bool V_102 )
{
struct V_1 * V_103 ;
union V_3 * V_104 ;
for ( V_103 = V_78 -> V_105 , V_104 = V_78 -> V_106 ;
true ;
F_7 ( V_10 , V_83 , & V_103 , & V_104 ) ) {
if ( F_5 ( V_104 -> V_29 . V_30 [ 3 ] ) ) {
V_104 -> V_29 . V_30 [ 3 ] &= F_11 ( ~ V_31 ) ;
if ( V_102 )
V_104 -> V_29 . V_30 [ 3 ] ^=
F_11 ( V_37 ) ;
F_35 ( V_10 , V_90 ,
L_17 ) ;
F_35 ( V_10 , V_90 ,
L_18
L_19 ,
V_104 ,
( unsigned long long ) F_1 ( V_103 , V_104 ) ,
V_103 ,
( unsigned long long ) V_103 -> V_8 ) ;
} else {
V_104 -> V_29 . V_30 [ 0 ] = 0 ;
V_104 -> V_29 . V_30 [ 1 ] = 0 ;
V_104 -> V_29 . V_30 [ 2 ] = 0 ;
V_104 -> V_29 . V_30 [ 3 ] &= F_11 ( V_37 ) ;
if ( V_102 && V_104 != V_78 -> V_106 &&
V_104 != V_78 -> F_4 )
V_104 -> V_29 . V_30 [ 3 ] ^=
F_11 ( V_37 ) ;
V_104 -> V_29 . V_30 [ 3 ] |= F_11 (
F_39 ( V_107 ) ) ;
F_35 ( V_10 , V_90 ,
L_20 ,
( unsigned long long )
F_1 ( V_103 , V_104 ) ) ;
}
if ( V_104 == V_78 -> F_4 )
break;
}
}
static void F_40 ( struct V_9 * V_10 ,
struct V_63 * V_64 )
{
V_64 -> V_67 &= ~ V_68 ;
if ( F_25 ( & V_64 -> V_108 ) )
V_64 -> V_109 -- ;
}
static void F_41 ( struct V_9 * V_10 ,
struct V_77 * V_78 , int V_110 )
{
struct V_111 * V_112 ;
struct V_113 * V_113 ;
struct V_114 * V_114 ;
V_113 = V_78 -> V_113 ;
V_114 = V_113 -> V_115 ;
V_114 -> V_116 ++ ;
V_112 = F_42 ( V_113 -> V_82 -> V_117 ) ;
if ( V_114 -> V_116 == V_114 -> V_118 ) {
if ( F_43 ( V_113 -> V_119 ) == V_120 ) {
F_44 ( V_10 ) -> V_121 . V_122 -- ;
if ( F_44 ( V_10 ) -> V_121 . V_122 == 0 ) {
if ( V_10 -> V_35 & V_123 )
F_45 () ;
}
}
F_46 ( V_112 , V_113 ) ;
F_47 ( & V_10 -> V_124 ) ;
F_48 ( V_112 , V_113 , V_110 ) ;
F_49 ( V_114 ) ;
F_50 ( & V_10 -> V_124 ) ;
}
}
static void F_51 ( struct V_9 * V_10 , int V_59 ,
union V_3 * V_4 , struct V_125 * V_126 )
{
unsigned int V_60 ;
struct V_11 * V_83 ;
struct V_63 * V_64 ;
struct V_127 * V_128 ;
struct V_77 * V_78 = NULL ;
struct V_77 * V_129 ;
struct V_79 V_130 ;
if ( F_52 ( F_53 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ) ) {
if ( ! V_10 -> V_65 [ V_59 ] )
F_33 ( V_10 , L_21
L_22 ,
V_59 ) ;
return;
}
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_60 = F_54 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_64 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
if ( F_31 ( & V_64 -> V_131 ) ) {
F_40 ( V_10 , V_64 ) ;
V_64 -> V_132 = NULL ;
F_30 ( V_10 , V_59 , V_60 ) ;
return;
}
F_55 (entry, &ep->cancelled_td_list) {
V_78 = F_56 ( V_128 , struct V_77 , V_131 ) ;
F_35 ( V_10 , V_90 ,
L_23 ,
( unsigned long long ) F_1 (
V_78 -> V_105 , V_78 -> V_106 ) ) ;
V_83 = F_57 ( V_10 , V_78 -> V_113 ) ;
if ( ! V_83 ) {
F_33 ( V_10 , L_24
L_25 ,
V_78 -> V_113 ,
V_78 -> V_113 -> V_61 ) ;
goto V_133;
}
if ( V_78 == V_64 -> V_132 )
F_34 ( V_10 , V_59 , V_60 ,
V_78 -> V_113 -> V_61 ,
V_78 , & V_130 ) ;
else
F_38 ( V_10 , V_83 , V_78 , false ) ;
V_133:
F_58 ( & V_78 -> V_72 ) ;
}
V_129 = V_78 ;
F_40 ( V_10 , V_64 ) ;
if ( V_130 . V_101 && V_130 . V_100 ) {
F_59 ( V_10 , V_59 , V_60 ,
V_64 -> V_132 -> V_113 -> V_61 , & V_130 ) ;
F_14 ( V_10 ) ;
} else {
F_30 ( V_10 , V_59 , V_60 ) ;
}
V_64 -> V_132 = NULL ;
do {
V_78 = F_56 ( V_64 -> V_131 . V_14 ,
struct V_77 , V_131 ) ;
F_58 ( & V_78 -> V_131 ) ;
F_41 ( V_10 , V_78 , 0 ) ;
if ( V_10 -> V_56 & V_57 )
return;
} while ( V_78 != V_129 );
}
static void F_60 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_77 * V_78 ;
while ( ! F_31 ( & V_12 -> V_72 ) ) {
V_78 = F_61 ( & V_12 -> V_72 ,
struct V_77 , V_72 ) ;
F_58 ( & V_78 -> V_72 ) ;
if ( ! F_31 ( & V_78 -> V_131 ) )
F_58 ( & V_78 -> V_131 ) ;
F_41 ( V_10 , V_78 , - V_58 ) ;
}
}
static void F_62 ( struct V_9 * V_10 ,
int V_59 , int V_60 )
{
struct V_77 * V_78 ;
struct V_63 * V_64 ;
struct V_11 * V_12 ;
V_64 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
if ( ( V_64 -> V_67 & V_71 ) ||
( V_64 -> V_67 & V_134 ) ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_64 -> V_73 -> V_74 ;
V_61 ++ ) {
F_35 ( V_10 , V_90 ,
L_26 ,
V_59 , V_60 , V_61 + 1 ) ;
F_60 ( V_10 ,
V_64 -> V_73 -> V_76 [ V_61 ] ) ;
}
} else {
V_12 = V_64 -> V_12 ;
if ( ! V_12 )
return;
F_35 ( V_10 , V_90 ,
L_27 ,
V_59 , V_60 ) ;
F_60 ( V_10 , V_12 ) ;
}
while ( ! F_31 ( & V_64 -> V_131 ) ) {
V_78 = F_61 ( & V_64 -> V_131 ,
struct V_77 , V_131 ) ;
F_58 ( & V_78 -> V_131 ) ;
F_41 ( V_10 , V_78 , - V_58 ) ;
}
}
void F_63 ( unsigned long V_135 )
{
struct V_9 * V_10 ;
struct V_63 * V_64 ;
int V_47 , V_136 , V_137 ;
unsigned long V_138 ;
V_64 = (struct V_63 * ) V_135 ;
V_10 = V_64 -> V_10 ;
F_64 ( & V_10 -> V_124 , V_138 ) ;
V_64 -> V_109 -- ;
if ( V_10 -> V_56 & V_57 ) {
F_35 ( V_10 , V_90 ,
L_28
L_29 ) ;
F_65 ( & V_10 -> V_124 , V_138 ) ;
return;
}
if ( ! ( V_64 -> V_109 == 0 && ( V_64 -> V_67 & V_68 ) ) ) {
F_35 ( V_10 , V_90 ,
L_30
L_31 ) ;
F_65 ( & V_10 -> V_124 , V_138 ) ;
return;
}
F_33 ( V_10 , L_32 ) ;
F_33 ( V_10 , L_33 ) ;
V_10 -> V_56 |= V_57 ;
F_26 ( V_10 ) ;
F_65 ( & V_10 -> V_124 , V_138 ) ;
V_47 = F_27 ( V_10 ) ;
F_64 ( & V_10 -> V_124 , V_138 ) ;
if ( V_47 < 0 ) {
F_33 ( V_10 , L_34 ) ;
F_33 ( V_10 , L_35 ) ;
}
for ( V_136 = 0 ; V_136 < V_139 ; V_136 ++ ) {
if ( ! V_10 -> V_65 [ V_136 ] )
continue;
for ( V_137 = 0 ; V_137 < 31 ; V_137 ++ )
F_62 ( V_10 , V_136 , V_137 ) ;
}
F_65 ( & V_10 -> V_124 , V_138 ) ;
F_35 ( V_10 , V_90 ,
L_36 ) ;
F_66 ( F_44 ( V_10 ) -> V_140 ) ;
F_35 ( V_10 , V_90 ,
L_37 ) ;
}
static void F_67 ( struct V_9 * V_10 ,
struct V_81 * V_82 ,
struct V_11 * V_83 ,
unsigned int V_60 )
{
union V_3 * V_141 ;
int V_142 ;
bool V_143 = false ;
V_142 = V_83 -> V_25 ;
V_141 = V_83 -> V_24 ;
if ( F_4 ( V_10 , V_83 , V_83 -> V_23 , V_83 -> V_24 ) ) {
V_83 -> V_23 = V_83 -> V_23 -> V_14 ;
V_83 -> V_24 = V_83 -> V_23 -> V_6 ;
}
while ( V_83 -> V_24 != V_82 -> V_66 [ V_60 ] . V_144 ) {
V_83 -> V_25 ++ ;
V_83 -> V_24 ++ ;
if ( F_4 ( V_10 , V_83 , V_83 -> V_23 ,
V_83 -> V_24 ) ) {
if ( V_83 -> V_24 ==
V_82 -> V_66 [ V_60 ] . V_144 )
break;
V_83 -> V_23 = V_83 -> V_23 -> V_14 ;
V_83 -> V_24 = V_83 -> V_23 -> V_6 ;
}
if ( V_83 -> V_24 == V_141 ) {
V_143 = true ;
break;
}
}
if ( V_143 ) {
F_15 ( V_10 , L_38 ) ;
V_83 -> V_25 = V_142 ;
}
}
static void F_68 ( struct V_9 * V_10 , int V_59 ,
union V_3 * V_4 , T_2 V_145 )
{
unsigned int V_60 ;
unsigned int V_61 ;
struct V_11 * V_83 ;
struct V_81 * V_82 ;
struct V_63 * V_64 ;
struct V_95 * V_96 ;
struct V_146 * V_147 ;
V_60 = F_54 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
V_61 = F_69 ( F_3 ( V_4 -> V_29 . V_30 [ 2 ] ) ) ;
V_82 = V_10 -> V_65 [ V_59 ] ;
V_64 = & V_82 -> V_66 [ V_60 ] ;
V_83 = F_70 ( V_82 , V_60 , V_61 ) ;
if ( ! V_83 ) {
F_33 ( V_10 , L_39 ,
V_61 ) ;
goto V_148;
}
V_96 = F_37 ( V_10 , V_82 -> V_97 , V_60 ) ;
V_147 = F_71 ( V_10 , V_82 -> V_97 ) ;
if ( V_145 != V_149 ) {
unsigned int V_67 ;
unsigned int V_150 ;
switch ( V_145 ) {
case V_151 :
F_33 ( V_10 , L_40 ) ;
break;
case V_152 :
F_33 ( V_10 , L_41 ) ;
V_67 = F_3 ( V_96 -> V_153 ) ;
V_67 &= V_154 ;
V_150 = F_3 ( V_147 -> V_155 ) ;
V_150 = F_72 ( V_150 ) ;
F_35 ( V_10 , V_90 ,
L_42 ,
V_150 , V_67 ) ;
break;
case V_156 :
F_33 ( V_10 , L_43 ,
V_59 ) ;
break;
default:
F_33 ( V_10 , L_44 ,
V_145 ) ;
break;
}
} else {
T_3 V_98 ;
if ( V_64 -> V_67 & V_71 ) {
struct V_91 * V_92 =
& V_64 -> V_73 -> V_93 [ V_61 ] ;
V_98 = F_36 ( V_92 -> V_94 ) & V_157 ;
} else {
V_98 = F_36 ( V_96 -> V_98 ) & ~ V_158 ;
}
F_35 ( V_10 , V_90 ,
L_45 , V_98 ) ;
if ( F_1 ( V_64 -> V_159 ,
V_64 -> V_144 ) == V_98 ) {
F_67 ( V_10 , V_82 ,
V_83 , V_60 ) ;
} else {
F_33 ( V_10 , L_46 ) ;
F_33 ( V_10 , L_47 ,
V_64 -> V_159 , V_64 -> V_144 ) ;
}
}
V_148:
V_82 -> V_66 [ V_60 ] . V_67 &= ~ V_69 ;
V_82 -> V_66 [ V_60 ] . V_159 = NULL ;
V_82 -> V_66 [ V_60 ] . V_144 = NULL ;
F_30 ( V_10 , V_59 , V_60 ) ;
}
static void F_73 ( struct V_9 * V_10 , int V_59 ,
union V_3 * V_4 , T_2 V_145 )
{
unsigned int V_60 ;
V_60 = F_54 ( F_3 ( V_4 -> V_29 . V_30 [ 3 ] ) ) ;
F_35 ( V_10 , V_160 ,
L_48 , V_145 ) ;
if ( V_10 -> V_35 & V_161 ) {
struct V_162 * V_163 ;
V_163 = F_74 ( V_10 , false , false , V_164 ) ;
if ( ! V_163 ) {
F_33 ( V_10 , L_49 ) ;
return;
}
F_35 ( V_10 , V_165 ,
L_50 ) ;
F_75 ( V_10 , V_163 ,
V_10 -> V_65 [ V_59 ] -> V_166 -> V_8 , V_59 ,
false ) ;
F_14 ( V_10 ) ;
} else {
V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] . V_67 &= ~ V_70 ;
}
}
static void F_76 ( struct V_9 * V_10 , int V_59 ,
T_2 V_145 )
{
if ( V_145 == V_149 )
V_10 -> V_59 = V_59 ;
else
V_10 -> V_59 = 0 ;
}
static void F_77 ( struct V_9 * V_10 , int V_59 )
{
struct V_81 * V_167 ;
V_167 = V_10 -> V_65 [ V_59 ] ;
if ( ! V_167 )
return;
if ( V_10 -> V_35 & V_168 )
F_78 ( V_10 , V_167 , true ) ;
F_79 ( V_10 , V_59 ) ;
}
static void F_80 ( struct V_9 * V_10 , int V_59 ,
struct V_125 * V_126 , T_2 V_145 )
{
struct V_81 * V_167 ;
struct V_169 * V_170 ;
unsigned int V_60 ;
unsigned int V_67 ;
T_2 V_171 , V_172 ;
V_167 = V_10 -> V_65 [ V_59 ] ;
V_170 = F_81 ( V_167 -> V_166 ) ;
if ( ! V_170 ) {
F_33 ( V_10 , L_51 ) ;
return;
}
V_171 = F_3 ( V_170 -> V_171 ) ;
V_172 = F_3 ( V_170 -> V_172 ) ;
V_60 = F_82 ( V_171 ) - 1 ;
if ( V_10 -> V_35 & V_161 &&
V_60 != ( unsigned int ) - 1 &&
V_171 - V_173 == V_172 ) {
V_67 = V_167 -> V_66 [ V_60 ] . V_67 ;
if ( ! ( V_67 & V_70 ) )
return;
F_35 ( V_10 , V_165 ,
L_52
L_53 ,
V_60 , V_67 ) ;
V_167 -> V_66 [ V_60 ] . V_67 &= ~ V_70 ;
F_30 ( V_10 , V_59 , V_60 ) ;
return;
}
return;
}
static void F_83 ( struct V_9 * V_10 , int V_59 ,
struct V_125 * V_126 )
{
F_15 ( V_10 , L_54 ) ;
if ( ! V_10 -> V_65 [ V_59 ] )
F_33 ( V_10 , L_55
L_56 , V_59 ) ;
}
static void F_84 ( struct V_9 * V_10 ,
struct V_125 * V_126 )
{
if ( ! ( V_10 -> V_35 & V_174 ) ) {
V_10 -> V_175 |= 1 << 6 ;
return;
}
F_35 ( V_10 , V_165 ,
L_57 ,
F_85 ( F_3 ( V_126 -> V_110 ) ) ,
F_86 ( F_3 ( V_126 -> V_110 ) ) ) ;
}
static void F_87 ( struct V_162 * V_176 , T_2 V_110 )
{
F_88 ( & V_176 -> V_177 ) ;
if ( V_176 -> V_178 ) {
V_176 -> V_110 = V_110 ;
F_89 ( V_176 -> V_178 ) ;
} else {
F_90 ( V_176 ) ;
}
}
void F_91 ( struct V_9 * V_10 )
{
struct V_162 * V_179 , * V_180 ;
F_92 (cur_cmd, tmp_cmd, &xhci->cmd_list, cmd_list)
F_87 ( V_179 , V_181 ) ;
}
static void F_93 ( struct V_9 * V_10 ,
struct V_162 * V_179 )
{
struct V_162 * V_182 , * V_180 ;
T_2 V_26 ;
F_92 (i_cmd, tmp_cmd, &xhci->cmd_list,
cmd_list) {
if ( V_182 -> V_110 != V_181 )
continue;
V_182 -> V_110 = V_183 ;
F_15 ( V_10 , L_58 ,
V_182 -> V_184 ) ;
V_26 = F_3 (
V_182 -> V_184 -> V_29 . V_30 [ 3 ] ) & V_37 ;
V_182 -> V_184 -> V_29 . V_30 [ 0 ] = 0 ;
V_182 -> V_184 -> V_29 . V_30 [ 1 ] = 0 ;
V_182 -> V_184 -> V_29 . V_30 [ 2 ] = 0 ;
V_182 -> V_184 -> V_29 . V_30 [ 3 ] = F_11 (
F_39 ( V_185 ) | V_26 ) ;
}
V_10 -> V_41 = V_42 ;
if ( ( V_10 -> V_49 -> V_24 != V_10 -> V_49 -> V_20 ) &&
! ( V_10 -> V_56 & V_57 ) ) {
V_10 -> V_186 = V_179 ;
F_20 ( & V_10 -> V_51 , V_52 + V_53 ) ;
F_14 ( V_10 ) ;
}
return;
}
void F_94 ( unsigned long V_187 )
{
struct V_9 * V_10 ;
int V_47 ;
unsigned long V_138 ;
T_3 V_188 ;
bool V_189 = false ;
V_10 = (struct V_9 * ) V_187 ;
F_64 ( & V_10 -> V_124 , V_138 ) ;
if ( V_10 -> V_186 ) {
if ( V_10 -> V_186 -> V_110 == V_181 )
V_189 = true ;
V_10 -> V_186 -> V_110 = V_181 ;
}
V_188 = F_19 ( V_10 , & V_10 -> V_48 -> V_49 ) ;
if ( ( V_10 -> V_41 & V_42 ) &&
( V_188 & V_55 ) ) {
F_65 ( & V_10 -> V_124 , V_138 ) ;
F_15 ( V_10 , L_59 ) ;
V_47 = F_18 ( V_10 ) ;
if ( F_52 ( V_47 == - V_58 ) ) {
F_24 ( V_10 , L_60 ) ;
F_91 ( V_10 ) ;
F_66 ( F_44 ( V_10 ) -> V_140 ) ;
F_15 ( V_10 , L_61 ) ;
}
return;
}
if ( V_189 || V_10 -> V_56 & V_190 ) {
F_65 ( & V_10 -> V_124 , V_138 ) ;
F_15 ( V_10 , L_62 ) ;
F_91 ( V_10 ) ;
return;
}
F_15 ( V_10 , L_63 ) ;
F_93 ( V_10 , V_10 -> V_186 ) ;
F_65 ( & V_10 -> V_124 , V_138 ) ;
return;
}
static void F_95 ( struct V_9 * V_10 ,
struct V_125 * V_126 )
{
int V_59 = F_96 ( F_3 ( V_126 -> V_138 ) ) ;
T_3 V_191 ;
T_1 V_192 ;
T_2 V_145 ;
union V_3 * V_193 ;
struct V_162 * V_176 ;
T_2 V_194 ;
V_191 = F_36 ( V_126 -> V_193 ) ;
V_193 = V_10 -> V_49 -> V_24 ;
V_192 = F_1 ( V_10 -> V_49 -> V_23 ,
V_193 ) ;
if ( V_192 == 0 ) {
V_10 -> V_175 |= 1 << 4 ;
return;
}
if ( V_191 != ( T_3 ) V_192 ) {
V_10 -> V_175 |= 1 << 5 ;
return;
}
V_176 = F_56 ( V_10 -> V_177 . V_14 , struct V_162 , V_177 ) ;
if ( V_176 -> V_184 != V_10 -> V_49 -> V_24 ) {
F_24 ( V_10 ,
L_64 ) ;
return;
}
F_25 ( & V_10 -> V_51 ) ;
F_97 ( V_193 , (struct V_195 * ) V_126 ) ;
V_145 = F_98 ( F_3 ( V_126 -> V_110 ) ) ;
if ( V_145 == V_183 ) {
F_93 ( V_10 , V_176 ) ;
return;
}
if ( V_145 == V_181 ) {
V_10 -> V_41 = V_196 ;
if ( V_176 -> V_110 == V_181 )
goto V_197;
}
V_194 = F_99 ( F_3 ( V_193 -> V_29 . V_30 [ 3 ] ) ) ;
switch ( V_194 ) {
case V_198 :
F_76 ( V_10 , V_59 , V_145 ) ;
break;
case V_199 :
F_77 ( V_10 , V_59 ) ;
break;
case V_200 :
if ( ! V_176 -> V_178 )
F_80 ( V_10 , V_59 , V_126 ,
V_145 ) ;
break;
case V_201 :
break;
case V_202 :
break;
case V_203 :
F_100 ( V_59 != F_96 (
F_3 ( V_193 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_51 ( V_10 , V_59 , V_193 , V_126 ) ;
break;
case V_204 :
F_100 ( V_59 != F_96 (
F_3 ( V_193 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_68 ( V_10 , V_59 , V_193 , V_145 ) ;
break;
case V_185 :
if ( V_176 -> V_110 == V_183 )
V_145 = V_183 ;
break;
case V_205 :
F_100 ( V_59 != F_96 (
F_3 ( V_193 -> V_29 . V_30 [ 3 ] ) ) ) ;
F_73 ( V_10 , V_59 , V_193 , V_145 ) ;
break;
case V_206 :
V_59 = F_96 (
F_3 ( V_193 -> V_29 . V_30 [ 3 ] ) ) ;
F_83 ( V_10 , V_59 , V_126 ) ;
break;
case V_207 :
F_84 ( V_10 , V_126 ) ;
break;
default:
V_10 -> V_175 |= 1 << 6 ;
break;
}
if ( V_176 -> V_177 . V_14 != & V_10 -> V_177 ) {
V_10 -> V_186 = F_56 ( V_176 -> V_177 . V_14 ,
struct V_162 , V_177 ) ;
F_20 ( & V_10 -> V_51 , V_52 + V_53 ) ;
}
V_197:
F_87 ( V_176 , V_145 ) ;
F_8 ( V_10 , V_10 -> V_49 ) ;
}
static void F_101 ( struct V_9 * V_10 ,
union V_3 * V_126 )
{
T_2 V_208 ;
V_208 = F_99 ( F_3 ( V_126 -> V_29 . V_30 [ 3 ] ) ) ;
F_15 ( V_10 , L_65 , V_208 ) ;
if ( V_208 == V_209 && ( V_10 -> V_35 & V_174 ) )
F_95 ( V_10 , & V_126 -> V_210 ) ;
}
static unsigned int F_102 ( struct V_111 * V_112 ,
struct V_9 * V_10 , T_2 V_211 )
{
unsigned int V_136 ;
unsigned int V_212 = 0 ;
for ( V_136 = 0 ; V_136 < ( V_211 - 1 ) ; V_136 ++ ) {
T_6 V_213 = V_10 -> V_214 [ V_136 ] ;
if ( V_213 == 0 || V_213 == V_215 )
continue;
if ( ( V_213 == 0x03 ) == ( V_112 -> V_216 >= V_217 ) )
V_212 ++ ;
}
return V_212 ;
}
static void F_103 ( struct V_9 * V_10 ,
union V_3 * V_126 )
{
T_2 V_59 ;
struct V_218 * V_219 ;
V_59 = F_96 ( F_3 ( V_126 -> V_29 . V_30 [ 3 ] ) ) ;
if ( ! V_10 -> V_65 [ V_59 ] ) {
F_33 ( V_10 , L_66
L_67 , V_59 ) ;
return;
}
F_15 ( V_10 , L_68 ,
V_59 ) ;
V_219 = V_10 -> V_65 [ V_59 ] -> V_219 ;
if ( V_219 && V_219 -> V_220 )
F_104 ( V_219 -> V_220 , V_219 -> V_221 ) ;
}
static void F_105 ( struct V_9 * V_10 ,
union V_3 * V_126 )
{
struct V_111 * V_112 ;
T_2 V_211 ;
T_2 V_222 , V_223 ;
int V_224 ;
int V_59 ;
unsigned int V_225 ;
T_6 V_226 ;
struct V_227 * V_228 ;
T_4 T_5 * * V_214 ;
bool V_229 = false ;
if ( F_98 ( F_3 ( V_126 -> V_29 . V_30 [ 2 ] ) ) != V_149 ) {
F_33 ( V_10 , L_69 ) ;
V_10 -> V_175 |= 1 << 8 ;
}
V_211 = F_106 ( F_3 ( V_126 -> V_29 . V_30 [ 0 ] ) ) ;
F_15 ( V_10 , L_70 , V_211 ) ;
V_224 = F_107 ( V_10 -> V_230 ) ;
if ( ( V_211 <= 0 ) || ( V_211 > V_224 ) ) {
F_33 ( V_10 , L_71 , V_211 ) ;
F_8 ( V_10 , V_10 -> V_13 ) ;
return;
}
V_226 = V_10 -> V_214 [ V_211 - 1 ] ;
V_112 = F_44 ( V_10 ) ;
if ( ( V_226 == 0x03 ) != ( V_112 -> V_216 >= V_217 ) )
V_112 = V_10 -> V_231 ;
if ( V_226 == 0 ) {
F_33 ( V_10 , L_72
L_73 ,
V_211 ) ;
V_229 = true ;
goto V_148;
}
if ( V_226 == V_215 ) {
F_33 ( V_10 , L_74
L_73 ,
V_211 ) ;
V_229 = true ;
goto V_148;
}
V_228 = & V_10 -> V_228 [ F_108 ( V_112 ) ] ;
if ( V_112 -> V_216 >= V_217 )
V_214 = V_10 -> V_232 ;
else
V_214 = V_10 -> V_233 ;
V_225 = F_102 ( V_112 , V_10 ,
V_211 ) ;
V_222 = F_17 ( V_214 [ V_225 ] ) ;
if ( V_112 -> V_80 == V_234 ) {
F_15 ( V_10 , L_75 ) ;
F_109 ( V_112 ) ;
}
if ( V_112 -> V_216 >= V_217 && ( V_222 & V_235 ) == V_236 )
V_228 -> V_237 &= ~ ( 1 << V_225 ) ;
if ( ( V_222 & V_238 ) && ( V_222 & V_235 ) == V_239 ) {
F_15 ( V_10 , L_76 , V_211 ) ;
V_223 = F_17 ( & V_10 -> V_48 -> V_163 ) ;
if ( ! ( V_223 & V_240 ) ) {
F_33 ( V_10 , L_77 ) ;
goto V_148;
}
if ( F_110 ( V_222 ) ) {
F_15 ( V_10 , L_78 , V_211 ) ;
V_228 -> V_237 |= 1 << V_225 ;
F_111 ( V_10 , V_214 ,
V_225 , V_238 ) ;
F_112 ( V_10 , V_214 , V_225 ,
V_241 ) ;
V_229 = true ;
goto V_148;
} else if ( ! F_113 ( V_225 ,
& V_228 -> V_242 ) ) {
F_15 ( V_10 , L_79 , V_211 ) ;
V_228 -> V_243 [ V_225 ] = V_52 +
F_114 ( V_244 ) ;
F_115 ( V_225 , & V_228 -> V_242 ) ;
F_20 ( & V_112 -> V_245 ,
V_228 -> V_243 [ V_225 ] ) ;
}
}
if ( ( V_222 & V_238 ) && ( V_222 & V_235 ) == V_241 &&
F_110 ( V_222 ) ) {
F_15 ( V_10 , L_80 , V_211 ) ;
V_59 = F_116 ( V_112 , V_10 ,
V_225 + 1 ) ;
if ( V_59 && V_10 -> V_65 [ V_59 ] )
F_117 ( V_10 , V_59 ) ;
if ( V_228 -> V_237 & ( 1 << V_225 ) ) {
V_228 -> V_237 &=
~ ( 1 << V_225 ) ;
F_111 ( V_10 , V_214 ,
V_225 , V_238 ) ;
F_104 ( V_112 -> V_121 . V_246 ,
V_225 + 1 ) ;
V_229 = true ;
goto V_148;
}
}
if ( ! F_110 ( V_222 ) &&
F_118 ( V_225 ,
& V_228 -> V_247 ) ) {
F_89 ( & V_228 -> V_248 [ V_225 ] ) ;
V_229 = true ;
goto V_148;
}
if ( V_112 -> V_216 < V_217 )
F_111 ( V_10 , V_214 , V_225 ,
V_238 ) ;
V_148:
F_8 ( V_10 , V_10 -> V_13 ) ;
if ( V_229 )
return;
F_15 ( V_10 , L_81 , V_249 ) ;
F_115 ( V_250 , & V_112 -> V_138 ) ;
F_47 ( & V_10 -> V_124 ) ;
F_119 ( V_112 ) ;
F_50 ( & V_10 -> V_124 ) ;
}
struct V_1 * F_120 ( struct V_9 * V_10 ,
struct V_1 * V_105 ,
union V_3 * V_251 ,
union V_3 * V_252 ,
T_1 V_253 ,
bool V_254 )
{
T_1 V_255 ;
T_1 V_256 ;
T_1 V_257 ;
struct V_1 * V_103 ;
V_255 = F_1 ( V_105 , V_251 ) ;
V_103 = V_105 ;
do {
if ( V_255 == 0 )
return NULL ;
V_256 = F_1 ( V_103 ,
& V_103 -> V_6 [ V_7 - 1 ] ) ;
V_257 = F_1 ( V_103 , V_252 ) ;
if ( V_254 )
F_33 ( V_10 ,
L_82 ,
( unsigned long long ) V_253 ,
( unsigned long long ) V_255 ,
( unsigned long long ) V_257 ,
( unsigned long long ) V_103 -> V_8 ,
( unsigned long long ) V_256 ) ;
if ( V_257 > 0 ) {
if ( V_255 <= V_257 ) {
if ( V_253 >= V_255 && V_253 <= V_257 )
return V_103 ;
} else {
if ( ( V_253 >= V_255 &&
V_253 <= V_256 ) ||
( V_253 >= V_103 -> V_8 &&
V_253 <= V_257 ) )
return V_103 ;
}
return NULL ;
} else {
if ( V_253 >= V_255 && V_253 <= V_256 )
return V_103 ;
}
V_103 = V_103 -> V_14 ;
V_255 = F_1 ( V_103 , & V_103 -> V_6 [ 0 ] ) ;
} while ( V_103 != V_105 );
return NULL ;
}
static void F_121 ( struct V_9 * V_10 ,
unsigned int V_59 , unsigned int V_60 ,
unsigned int V_61 ,
struct V_77 * V_258 , union V_3 * V_259 )
{
struct V_63 * V_64 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
struct V_162 * V_163 ;
V_163 = F_74 ( V_10 , false , false , V_164 ) ;
if ( ! V_163 )
return;
V_64 -> V_67 |= V_70 ;
V_64 -> V_260 = V_61 ;
F_122 ( V_10 , V_163 , V_59 , V_60 ) ;
F_123 ( V_10 , V_60 , V_258 ) ;
V_64 -> V_260 = 0 ;
F_14 ( V_10 ) ;
}
static int F_124 ( struct V_9 * V_10 ,
struct V_95 * V_96 ,
unsigned int V_261 )
{
if ( V_261 == V_262 ||
V_261 == V_263 ||
V_261 == V_264 )
if ( ( V_96 -> V_153 & F_11 ( V_154 ) ) ==
F_11 ( V_265 ) )
return 1 ;
return 0 ;
}
int F_125 ( struct V_9 * V_10 , unsigned int V_261 )
{
if ( V_261 >= 224 && V_261 <= 255 ) {
F_15 ( V_10 , L_83 ,
V_261 ) ;
F_15 ( V_10 , L_84 ) ;
return 1 ;
}
return 0 ;
}
static int F_126 ( struct V_9 * V_10 , struct V_77 * V_258 ,
union V_3 * V_259 , struct V_266 * V_126 ,
struct V_63 * V_64 , int * V_110 , bool V_267 )
{
struct V_81 * V_268 ;
struct V_11 * V_83 ;
unsigned int V_59 ;
int V_60 ;
struct V_113 * V_113 = NULL ;
struct V_95 * V_96 ;
int V_47 = 0 ;
struct V_114 * V_114 ;
T_2 V_261 ;
V_59 = F_96 ( F_3 ( V_126 -> V_138 ) ) ;
V_268 = V_10 -> V_65 [ V_59 ] ;
V_60 = F_127 ( F_3 ( V_126 -> V_138 ) ) - 1 ;
V_83 = F_128 ( V_64 , F_36 ( V_126 -> V_269 ) ) ;
V_96 = F_37 ( V_10 , V_268 -> V_97 , V_60 ) ;
V_261 = F_98 ( F_3 ( V_126 -> V_270 ) ) ;
if ( V_267 )
goto V_271;
if ( V_261 == V_272 ||
V_261 == V_273 ||
V_261 == V_274 ) {
V_64 -> V_132 = V_258 ;
return 0 ;
}
if ( V_261 == V_275 ||
F_124 ( V_10 , V_96 ,
V_261 ) ) {
F_121 ( V_10 , V_59 , V_60 ,
V_83 -> V_61 , V_258 , V_259 ) ;
} else {
while ( V_83 -> V_24 != V_258 -> F_4 )
F_8 ( V_10 , V_83 ) ;
F_8 ( V_10 , V_83 ) ;
}
V_271:
V_113 = V_258 -> V_113 ;
V_114 = V_113 -> V_115 ;
if ( V_113 -> V_276 > V_113 -> V_277 ) {
F_33 ( V_10 , L_85 ,
V_113 -> V_277 ,
V_113 -> V_276 ) ;
V_113 -> V_276 = 0 ;
if ( V_258 -> V_113 -> V_278 & V_279 )
* V_110 = - V_280 ;
else
* V_110 = 0 ;
}
F_58 ( & V_258 -> V_72 ) ;
if ( ! F_31 ( & V_258 -> V_131 ) )
F_58 ( & V_258 -> V_131 ) ;
V_114 -> V_116 ++ ;
if ( V_114 -> V_116 == V_114 -> V_118 ) {
V_47 = 1 ;
if ( F_43 ( V_113 -> V_119 ) == V_120 ) {
F_44 ( V_10 ) -> V_121 . V_122 -- ;
if ( F_44 ( V_10 ) -> V_121 . V_122 == 0 ) {
if ( V_10 -> V_35 & V_123 )
F_45 () ;
}
}
}
return V_47 ;
}
static int F_129 ( struct V_9 * V_10 , struct V_77 * V_258 ,
union V_3 * V_259 , struct V_266 * V_126 ,
struct V_63 * V_64 , int * V_110 )
{
struct V_81 * V_268 ;
struct V_11 * V_83 ;
unsigned int V_59 ;
int V_60 ;
struct V_95 * V_96 ;
T_2 V_261 ;
V_59 = F_96 ( F_3 ( V_126 -> V_138 ) ) ;
V_268 = V_10 -> V_65 [ V_59 ] ;
V_60 = F_127 ( F_3 ( V_126 -> V_138 ) ) - 1 ;
V_83 = F_128 ( V_64 , F_36 ( V_126 -> V_269 ) ) ;
V_96 = F_37 ( V_10 , V_268 -> V_97 , V_60 ) ;
V_261 = F_98 ( F_3 ( V_126 -> V_270 ) ) ;
switch ( V_261 ) {
case V_149 :
if ( V_259 == V_83 -> V_24 ) {
F_33 ( V_10 , L_86
L_87 ) ;
* V_110 = - V_58 ;
} else if ( V_259 != V_258 -> F_4 ) {
F_33 ( V_10 , L_88
L_87 ) ;
* V_110 = - V_58 ;
} else {
* V_110 = 0 ;
}
break;
case V_281 :
if ( V_258 -> V_113 -> V_278 & V_279 )
* V_110 = - V_280 ;
else
* V_110 = 0 ;
break;
case V_274 :
if ( V_259 == V_83 -> V_24 || V_259 == V_258 -> F_4 )
F_33 ( V_10 , L_89 ) ;
else
V_258 -> V_113 -> V_276 =
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
return F_126 ( V_10 , V_258 , V_259 , V_126 , V_64 , V_110 , false ) ;
case V_273 :
if ( V_259 != V_83 -> V_24 && V_259 != V_258 -> F_4 )
V_258 -> V_113 -> V_276 =
V_258 -> V_113 -> V_277 -
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
case V_272 :
return F_126 ( V_10 , V_258 , V_259 , V_126 , V_64 , V_110 , false ) ;
default:
if ( ! F_124 ( V_10 ,
V_96 , V_261 ) )
break;
F_15 ( V_10 , L_90
L_91 ,
V_261 , V_60 ) ;
case V_275 :
if ( V_259 != V_83 -> V_24 &&
V_259 != V_258 -> F_4 )
V_258 -> V_113 -> V_276 =
V_258 -> V_113 -> V_277 -
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
else if ( ! V_258 -> V_282 )
V_258 -> V_113 -> V_276 = 0 ;
return F_126 ( V_10 , V_258 , V_259 , V_126 , V_64 , V_110 , false ) ;
}
if ( V_259 != V_83 -> V_24 ) {
if ( V_259 == V_258 -> F_4 ) {
if ( V_258 -> V_282 ) {
if ( ( * V_110 == - V_283 || * V_110 == 0 ) &&
( V_258 -> V_113 -> V_278
& V_279 ) )
* V_110 = - V_280 ;
} else {
V_258 -> V_113 -> V_276 =
V_258 -> V_113 -> V_277 ;
}
} else {
V_258 -> V_282 = true ;
V_258 -> V_113 -> V_276 =
V_258 -> V_113 -> V_277 -
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
F_15 ( V_10 , L_92
L_93 ) ;
return 0 ;
}
}
return F_126 ( V_10 , V_258 , V_259 , V_126 , V_64 , V_110 , false ) ;
}
static int F_131 ( struct V_9 * V_10 , struct V_77 * V_258 ,
union V_3 * V_259 , struct V_266 * V_126 ,
struct V_63 * V_64 , int * V_110 )
{
struct V_11 * V_83 ;
struct V_114 * V_114 ;
int V_284 ;
int V_285 = 0 ;
union V_3 * V_104 ;
struct V_1 * V_103 ;
struct V_286 * V_287 ;
T_2 V_261 ;
bool V_288 = false ;
V_83 = F_128 ( V_64 , F_36 ( V_126 -> V_269 ) ) ;
V_261 = F_98 ( F_3 ( V_126 -> V_270 ) ) ;
V_114 = V_258 -> V_113 -> V_115 ;
V_284 = V_114 -> V_116 ;
V_287 = & V_258 -> V_113 -> V_289 [ V_284 ] ;
switch ( V_261 ) {
case V_149 :
if ( F_130 ( F_3 ( V_126 -> V_270 ) ) == 0 ) {
V_287 -> V_110 = 0 ;
break;
}
if ( ( V_10 -> V_35 & V_290 ) )
V_261 = V_281 ;
case V_274 :
case V_281 :
V_287 -> V_110 = V_258 -> V_113 -> V_278 & V_279 ?
- V_280 : 0 ;
break;
case V_291 :
V_287 -> V_110 = - V_292 ;
V_288 = true ;
break;
case V_293 :
case V_263 :
V_287 -> V_110 = - V_294 ;
V_288 = true ;
break;
case V_295 :
case V_275 :
V_287 -> V_110 = - V_296 ;
V_288 = true ;
break;
case V_262 :
V_287 -> V_110 = - V_296 ;
if ( V_259 != V_258 -> F_4 )
return 0 ;
V_288 = true ;
break;
case V_273 :
case V_272 :
break;
default:
V_287 -> V_110 = - 1 ;
break;
}
if ( V_261 == V_149 || V_288 ) {
V_287 -> V_276 = V_287 -> V_118 ;
V_258 -> V_113 -> V_276 += V_287 -> V_118 ;
} else if ( V_261 == V_274 ) {
V_287 -> V_276 =
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
V_258 -> V_113 -> V_276 += V_287 -> V_276 ;
} else {
for ( V_104 = V_83 -> V_24 ,
V_103 = V_83 -> V_23 ; V_104 != V_259 ;
F_7 ( V_10 , V_83 , & V_103 , & V_104 ) ) {
if ( ! F_132 ( V_104 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_104 -> V_29 . V_30 [ 3 ] ) )
V_285 += F_133 ( F_3 ( V_104 -> V_29 . V_30 [ 2 ] ) ) ;
}
V_285 += F_133 ( F_3 ( V_104 -> V_29 . V_30 [ 2 ] ) ) -
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
if ( V_261 != V_272 ) {
V_287 -> V_276 = V_285 ;
V_258 -> V_113 -> V_276 += V_285 ;
}
}
return F_126 ( V_10 , V_258 , V_259 , V_126 , V_64 , V_110 , false ) ;
}
static int F_134 ( struct V_9 * V_10 , struct V_77 * V_258 ,
struct V_266 * V_126 ,
struct V_63 * V_64 , int * V_110 )
{
struct V_11 * V_83 ;
struct V_114 * V_114 ;
struct V_286 * V_287 ;
int V_284 ;
V_83 = F_128 ( V_64 , F_36 ( V_126 -> V_269 ) ) ;
V_114 = V_258 -> V_113 -> V_115 ;
V_284 = V_114 -> V_116 ;
V_287 = & V_258 -> V_113 -> V_289 [ V_284 ] ;
V_287 -> V_110 = - V_297 ;
V_287 -> V_276 = 0 ;
while ( V_83 -> V_24 != V_258 -> F_4 )
F_8 ( V_10 , V_83 ) ;
F_8 ( V_10 , V_83 ) ;
return F_126 ( V_10 , V_258 , NULL , V_126 , V_64 , V_110 , true ) ;
}
static int F_135 ( struct V_9 * V_10 , struct V_77 * V_258 ,
union V_3 * V_259 , struct V_266 * V_126 ,
struct V_63 * V_64 , int * V_110 )
{
struct V_11 * V_83 ;
union V_3 * V_104 ;
struct V_1 * V_103 ;
T_2 V_261 ;
V_83 = F_128 ( V_64 , F_36 ( V_126 -> V_269 ) ) ;
V_261 = F_98 ( F_3 ( V_126 -> V_270 ) ) ;
switch ( V_261 ) {
case V_149 :
if ( V_259 != V_258 -> F_4 ||
F_130 ( F_3 ( V_126 -> V_270 ) ) != 0 ) {
F_33 ( V_10 , L_94
L_95 ) ;
if ( V_258 -> V_113 -> V_278 & V_279 )
* V_110 = - V_280 ;
else
* V_110 = 0 ;
if ( ( V_10 -> V_35 & V_290 ) )
V_261 = V_281 ;
} else {
* V_110 = 0 ;
}
break;
case V_274 :
case V_281 :
if ( V_258 -> V_113 -> V_278 & V_279 )
* V_110 = - V_280 ;
else
* V_110 = 0 ;
break;
default:
break;
}
if ( V_261 == V_281 )
F_15 ( V_10 , L_96
L_97 ,
V_258 -> V_113 -> V_64 -> V_298 . V_299 ,
V_258 -> V_113 -> V_277 ,
F_130 ( F_3 ( V_126 -> V_270 ) ) ) ;
if ( V_261 == V_274 ) {
V_258 -> V_113 -> V_276 =
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
if ( V_258 -> V_113 -> V_277 <
V_258 -> V_113 -> V_276 ) {
F_33 ( V_10 , L_98 ,
F_130 ( F_3 ( V_126 -> V_270 ) ) ) ;
V_258 -> V_113 -> V_276 = 0 ;
}
} else if ( V_259 == V_258 -> F_4 ) {
if ( F_130 ( F_3 ( V_126 -> V_270 ) ) != 0 ) {
V_258 -> V_113 -> V_276 =
V_258 -> V_113 -> V_277 -
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
if ( V_258 -> V_113 -> V_277 <
V_258 -> V_113 -> V_276 ) {
F_33 ( V_10 , L_99
L_100 ,
F_130 ( F_3 ( V_126 -> V_270 ) ) ) ;
V_258 -> V_113 -> V_276 = 0 ;
if ( V_258 -> V_113 -> V_278 & V_279 )
* V_110 = - V_280 ;
else
* V_110 = 0 ;
}
if ( * V_110 == - V_283 ) {
if ( V_258 -> V_113 -> V_278 & V_279 )
* V_110 = - V_280 ;
else
* V_110 = 0 ;
}
} else {
V_258 -> V_113 -> V_276 =
V_258 -> V_113 -> V_277 ;
if ( * V_110 == - V_280 )
* V_110 = 0 ;
}
} else {
V_258 -> V_113 -> V_276 = 0 ;
for ( V_104 = V_83 -> V_24 , V_103 = V_83 -> V_23 ;
V_104 != V_259 ;
F_7 ( V_10 , V_83 , & V_103 , & V_104 ) ) {
if ( ! F_132 ( V_104 -> V_29 . V_30 [ 3 ] ) &&
! F_5 ( V_104 -> V_29 . V_30 [ 3 ] ) )
V_258 -> V_113 -> V_276 +=
F_133 ( F_3 ( V_104 -> V_29 . V_30 [ 2 ] ) ) ;
}
if ( V_261 != V_272 )
V_258 -> V_113 -> V_276 +=
F_133 ( F_3 ( V_104 -> V_29 . V_30 [ 2 ] ) ) -
F_130 ( F_3 ( V_126 -> V_270 ) ) ;
}
return F_126 ( V_10 , V_258 , V_259 , V_126 , V_64 , V_110 , false ) ;
}
static int F_136 ( struct V_9 * V_10 ,
struct V_266 * V_126 )
__releases( &xhci->lock
static int F_137 ( struct V_9 * V_10 )
{
union V_3 * V_126 ;
int V_300 = 1 ;
int V_47 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_24 ) {
V_10 -> V_175 |= 1 << 1 ;
return 0 ;
}
V_126 = V_10 -> V_13 -> V_24 ;
if ( ( F_3 ( V_126 -> V_210 . V_138 ) & V_37 ) !=
V_10 -> V_13 -> V_26 ) {
V_10 -> V_175 |= 1 << 2 ;
return 0 ;
}
F_138 () ;
switch ( ( F_3 ( V_126 -> V_210 . V_138 ) & V_301 ) ) {
case F_39 ( V_302 ) :
F_95 ( V_10 , & V_126 -> V_210 ) ;
break;
case F_39 ( V_303 ) :
F_105 ( V_10 , V_126 ) ;
V_300 = 0 ;
break;
case F_39 ( V_304 ) :
V_47 = F_136 ( V_10 , & V_126 -> V_305 ) ;
if ( V_47 < 0 )
V_10 -> V_175 |= 1 << 9 ;
else
V_300 = 0 ;
break;
case F_39 ( V_306 ) :
F_103 ( V_10 , V_126 ) ;
break;
default:
if ( ( F_3 ( V_126 -> V_210 . V_138 ) & V_301 ) >=
F_39 ( 48 ) )
F_101 ( V_10 , V_126 ) ;
else
V_10 -> V_175 |= 1 << 3 ;
}
if ( V_10 -> V_56 & V_57 ) {
F_15 ( V_10 , L_101
L_102 ) ;
return 0 ;
}
if ( V_300 )
F_8 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_139 ( struct V_111 * V_112 )
{
struct V_9 * V_10 = F_140 ( V_112 ) ;
T_2 V_110 ;
T_3 V_46 ;
union V_3 * V_307 ;
T_1 V_98 ;
F_50 ( & V_10 -> V_124 ) ;
V_110 = F_17 ( & V_10 -> V_48 -> V_110 ) ;
if ( V_110 == 0xffffffff )
goto V_308;
if ( ! ( V_110 & V_309 ) ) {
F_47 ( & V_10 -> V_124 ) ;
return V_310 ;
}
if ( V_110 & V_311 ) {
F_33 ( V_10 , L_103 ) ;
F_27 ( V_10 ) ;
V_308:
F_47 ( & V_10 -> V_124 ) ;
return V_312 ;
}
V_110 |= V_309 ;
F_16 ( V_110 , & V_10 -> V_48 -> V_110 ) ;
if ( V_112 -> V_313 ) {
T_2 V_314 ;
V_314 = F_17 ( & V_10 -> V_315 -> V_314 ) ;
V_314 |= V_316 ;
F_16 ( V_314 , & V_10 -> V_315 -> V_314 ) ;
}
if ( V_10 -> V_56 & V_57 ||
V_10 -> V_56 & V_317 ) {
F_15 ( V_10 , L_104
L_105 ) ;
V_46 = F_19 ( V_10 , & V_10 -> V_315 -> V_318 ) ;
F_21 ( V_10 , V_46 | V_319 ,
& V_10 -> V_315 -> V_318 ) ;
F_47 ( & V_10 -> V_124 ) ;
return V_312 ;
}
V_307 = V_10 -> V_13 -> V_24 ;
while ( F_137 ( V_10 ) > 0 ) {}
V_46 = F_19 ( V_10 , & V_10 -> V_315 -> V_318 ) ;
if ( V_307 != V_10 -> V_13 -> V_24 ) {
V_98 = F_1 ( V_10 -> V_13 -> V_23 ,
V_10 -> V_13 -> V_24 ) ;
if ( V_98 == 0 )
F_33 ( V_10 , L_106
L_107 ) ;
V_46 &= V_320 ;
V_46 |= ( ( T_3 ) V_98 & ( T_3 ) ~ V_320 ) ;
}
V_46 |= V_319 ;
F_21 ( V_10 , V_46 , & V_10 -> V_315 -> V_318 ) ;
F_47 ( & V_10 -> V_124 ) ;
return V_312 ;
}
T_7 F_141 ( int V_313 , void * V_112 )
{
return F_139 ( V_112 ) ;
}
static void F_142 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_27 ,
T_2 V_321 , T_2 V_322 , T_2 V_323 , T_2 V_324 )
{
struct V_195 * V_4 ;
V_4 = & V_12 -> V_20 -> V_29 ;
V_4 -> V_30 [ 0 ] = F_11 ( V_321 ) ;
V_4 -> V_30 [ 1 ] = F_11 ( V_322 ) ;
V_4 -> V_30 [ 2 ] = F_11 ( V_323 ) ;
V_4 -> V_30 [ 3 ] = F_11 ( V_324 ) ;
F_9 ( V_10 , V_12 , V_27 ) ;
}
static int F_143 ( struct V_9 * V_10 , struct V_11 * V_83 ,
T_2 V_67 , unsigned int V_38 , T_8 V_325 )
{
unsigned int V_326 ;
switch ( V_67 ) {
case V_327 :
F_33 ( V_10 , L_108 ) ;
return - V_328 ;
case V_329 :
F_33 ( V_10 , L_109 ) ;
return - V_330 ;
case V_265 :
F_15 ( V_10 , L_110 ) ;
case V_331 :
case V_332 :
break;
default:
F_24 ( V_10 , L_111 ) ;
return - V_330 ;
}
while ( 1 ) {
if ( F_13 ( V_10 , V_83 , V_38 ) )
break;
if ( V_83 == V_10 -> V_49 ) {
F_24 ( V_10 , L_112 ) ;
return - V_333 ;
}
F_35 ( V_10 , V_334 ,
L_113 ) ;
V_326 = V_38 - V_83 -> V_25 ;
if ( F_144 ( V_10 , V_83 , V_326 ,
V_325 ) ) {
F_24 ( V_10 , L_114 ) ;
return - V_333 ;
}
}
if ( F_6 ( V_83 ) ) {
struct V_11 * V_12 = V_83 ;
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
static int F_145 ( struct V_9 * V_10 ,
struct V_81 * V_268 ,
unsigned int V_60 ,
unsigned int V_61 ,
unsigned int V_38 ,
struct V_113 * V_113 ,
unsigned int V_335 ,
T_8 V_325 )
{
int V_47 ;
struct V_114 * V_114 ;
struct V_77 * V_258 ;
struct V_11 * V_83 ;
struct V_95 * V_96 = F_37 ( V_10 , V_268 -> V_97 , V_60 ) ;
V_83 = F_70 ( V_268 , V_60 , V_61 ) ;
if ( ! V_83 ) {
F_15 ( V_10 , L_115 ,
V_61 ) ;
return - V_330 ;
}
V_47 = F_143 ( V_10 , V_83 ,
F_3 ( V_96 -> V_153 ) & V_154 ,
V_38 , V_325 ) ;
if ( V_47 )
return V_47 ;
V_114 = V_113 -> V_115 ;
V_258 = V_114 -> V_258 [ V_335 ] ;
F_146 ( & V_258 -> V_72 ) ;
F_146 ( & V_258 -> V_131 ) ;
if ( V_335 == 0 ) {
V_47 = F_147 ( F_42 ( V_113 -> V_82 -> V_117 ) , V_113 ) ;
if ( F_52 ( V_47 ) )
return V_47 ;
}
V_258 -> V_113 = V_113 ;
F_148 ( & V_258 -> V_72 , & V_83 -> V_72 ) ;
V_258 -> V_105 = V_83 -> V_32 ;
V_258 -> V_106 = V_83 -> V_20 ;
V_114 -> V_258 [ V_335 ] = V_258 ;
return 0 ;
}
static unsigned int F_149 ( T_3 V_86 , T_3 V_285 )
{
unsigned int V_38 ;
V_38 = F_150 ( V_285 + ( V_86 & ( V_336 - 1 ) ) ,
V_336 ) ;
if ( V_38 == 0 )
V_38 ++ ;
return V_38 ;
}
static inline unsigned int F_151 ( struct V_113 * V_113 )
{
return F_149 ( V_113 -> V_337 , V_113 -> V_277 ) ;
}
static unsigned int F_152 ( struct V_113 * V_113 )
{
struct V_338 * V_339 ;
unsigned int V_136 , V_285 , V_340 , V_38 = 0 ;
V_340 = V_113 -> V_277 ;
F_153 (urb->sg, sg, urb->num_mapped_sgs, i) {
V_285 = F_154 ( V_339 ) ;
V_38 += F_149 ( F_155 ( V_339 ) , V_285 ) ;
V_285 = F_156 (unsigned int, len, full_len) ;
V_340 -= V_285 ;
if ( V_340 == 0 )
break;
}
return V_38 ;
}
static unsigned int F_157 ( struct V_113 * V_113 , int V_136 )
{
T_3 V_86 , V_285 ;
V_86 = ( T_3 ) ( V_113 -> V_337 + V_113 -> V_289 [ V_136 ] . V_341 ) ;
V_285 = V_113 -> V_289 [ V_136 ] . V_118 ;
return F_149 ( V_86 , V_285 ) ;
}
static void F_158 ( struct V_113 * V_113 , int V_342 )
{
if ( F_52 ( V_342 != V_113 -> V_277 ) )
F_159 ( & V_113 -> V_82 -> V_82 , L_116
L_117 ,
V_249 ,
V_113 -> V_64 -> V_298 . V_299 ,
V_342 , V_342 ,
V_113 -> V_277 ,
V_113 -> V_277 ) ;
}
static void F_160 ( struct V_9 * V_10 , int V_59 ,
unsigned int V_60 , unsigned int V_61 , int V_343 ,
struct V_195 * V_251 )
{
F_12 () ;
if ( V_343 )
V_251 -> V_30 [ 3 ] |= F_11 ( V_343 ) ;
else
V_251 -> V_30 [ 3 ] &= F_11 ( ~ V_37 ) ;
F_28 ( V_10 , V_59 , V_60 , V_61 ) ;
}
static void F_161 ( struct V_9 * V_10 , struct V_113 * V_113 ,
struct V_95 * V_96 )
{
int V_344 ;
int V_345 ;
V_344 = F_162 ( F_3 ( V_96 -> V_153 ) ) ;
V_345 = V_113 -> V_346 ;
if ( V_113 -> V_82 -> V_216 == V_347 ||
V_113 -> V_82 -> V_216 == V_348 )
V_345 *= 8 ;
if ( V_344 != V_345 ) {
F_163 ( & V_113 -> V_82 -> V_82 ,
L_118 ,
V_345 , V_345 == 1 ? L_119 : L_120 ,
V_344 , V_344 == 1 ? L_119 : L_120 ) ;
V_113 -> V_346 = V_344 ;
if ( V_113 -> V_82 -> V_216 == V_347 ||
V_113 -> V_82 -> V_216 == V_348 )
V_113 -> V_346 /= 8 ;
}
}
int F_164 ( struct V_9 * V_10 , T_8 V_325 ,
struct V_113 * V_113 , int V_59 , unsigned int V_60 )
{
struct V_95 * V_96 ;
V_96 = F_37 ( V_10 , V_10 -> V_65 [ V_59 ] -> V_97 , V_60 ) ;
F_161 ( V_10 , V_113 , V_96 ) ;
return F_165 ( V_10 , V_325 , V_113 , V_59 , V_60 ) ;
}
static T_2 F_166 ( struct V_9 * V_10 , int V_349 ,
int V_350 , unsigned int V_351 ,
struct V_113 * V_113 , unsigned int V_352 )
{
T_2 V_353 , V_354 ;
if ( V_10 -> V_355 < 0x100 && ! ( V_10 -> V_35 & V_356 ) )
return ( ( V_351 - V_349 ) >> 10 ) ;
if ( V_352 == 0 || ( V_349 == 0 && V_350 == 0 ) ||
V_350 == V_351 )
return 0 ;
if ( V_10 -> V_35 & V_356 )
V_350 = 0 ;
V_353 = F_167 ( F_168 ( & V_113 -> V_64 -> V_298 ) ) ;
V_354 = F_150 ( V_351 , V_353 ) ;
return ( V_354 - ( ( V_349 + V_350 ) / V_353 ) ) ;
}
int F_165 ( struct V_9 * V_10 , T_8 V_325 ,
struct V_113 * V_113 , int V_59 , unsigned int V_60 )
{
struct V_11 * V_83 ;
struct V_114 * V_114 ;
struct V_77 * V_258 ;
struct V_195 * V_251 ;
struct V_338 * V_339 = NULL ;
bool V_27 ;
bool V_357 ;
unsigned int V_38 , V_358 , V_136 ;
unsigned int V_343 , V_359 = 0 ;
unsigned int V_342 , V_360 , V_350 ;
unsigned int V_340 ;
int V_47 ;
T_2 V_30 , V_361 , V_362 ;
T_3 V_86 ;
V_83 = F_57 ( V_10 , V_113 ) ;
if ( ! V_83 )
return - V_330 ;
if ( V_113 -> V_359 ) {
V_359 = V_113 -> V_363 ;
V_339 = V_113 -> V_339 ;
V_38 = F_152 ( V_113 ) ;
} else
V_38 = F_151 ( V_113 ) ;
V_47 = F_145 ( V_10 , V_10 -> V_65 [ V_59 ] ,
V_60 , V_113 -> V_61 ,
V_38 , V_113 , 0 , V_325 ) ;
if ( F_52 ( V_47 < 0 ) )
return V_47 ;
V_114 = V_113 -> V_115 ;
V_358 = V_38 - 1 ;
V_357 = V_113 -> V_278 & V_364 &&
V_114 -> V_118 == 2 ;
if ( V_357 ) {
V_38 ++ ;
F_15 ( V_10 , L_121 ) ;
V_47 = F_145 ( V_10 , V_10 -> V_65 [ V_59 ] ,
V_60 , V_113 -> V_61 ,
1 , V_113 , 1 , V_325 ) ;
if ( F_52 ( V_47 < 0 ) )
return V_47 ;
}
V_258 = V_114 -> V_258 [ 0 ] ;
V_251 = & V_83 -> V_20 -> V_29 ;
V_343 = V_83 -> V_26 ;
V_340 = V_113 -> V_277 ;
V_342 = 0 ;
V_360 = 0 ;
for ( V_136 = 0 ; V_136 < V_38 ; V_136 ++ ) {
V_30 = F_39 ( V_365 ) ;
if ( V_360 == 0 ) {
if ( V_339 ) {
V_86 = ( T_3 ) F_155 ( V_339 ) ;
V_360 = F_154 ( V_339 ) ;
} else {
V_86 = ( T_3 ) V_113 -> V_337 ;
V_360 = V_340 ;
}
V_350 = F_169 ( V_86 ) ;
V_350 = F_156 (unsigned int,
trb_buff_len,
block_len) ;
} else {
V_350 = V_360 ;
if ( V_350 > V_336 )
V_350 = V_336 ;
}
if ( V_342 + V_350 > V_340 )
V_350 = V_340 - V_342 ;
if ( V_136 == 0 ) {
if ( V_343 == 0 )
V_30 |= V_37 ;
} else
V_30 |= V_83 -> V_26 ;
if ( V_136 < V_358 ) {
V_30 |= V_31 ;
} else {
V_30 |= V_366 ;
if ( V_136 == V_358 )
V_258 -> F_4 = V_83 -> V_20 ;
else if ( V_357 ) {
V_350 = 0 ;
V_114 -> V_258 [ 1 ] -> F_4 = V_83 -> V_20 ;
}
}
if ( F_170 ( V_113 ) )
V_30 |= V_367 ;
V_362 = F_166 ( V_10 , V_342 ,
V_350 , V_340 ,
V_113 , V_38 - V_136 - 1 ) ;
V_361 = F_133 ( V_350 ) |
F_171 ( V_362 ) |
F_172 ( 0 ) ;
if ( V_136 < V_38 - 1 )
V_27 = true ;
else
V_27 = false ;
F_142 ( V_10 , V_83 , V_27 ,
F_173 ( V_86 ) ,
F_174 ( V_86 ) ,
V_361 ,
V_30 ) ;
V_342 += V_350 ;
V_86 += V_350 ;
V_360 -= V_350 ;
if ( V_339 ) {
if ( V_360 == 0 ) {
-- V_359 ;
if ( V_359 == 0 )
break;
V_339 = F_175 ( V_339 ) ;
}
}
}
F_158 ( V_113 , V_342 ) ;
F_160 ( V_10 , V_59 , V_60 , V_113 -> V_61 ,
V_343 , V_251 ) ;
return 0 ;
}
int F_176 ( struct V_9 * V_10 , T_8 V_325 ,
struct V_113 * V_113 , int V_59 , unsigned int V_60 )
{
struct V_11 * V_83 ;
int V_38 ;
int V_47 ;
struct V_368 * V_369 ;
struct V_195 * V_251 ;
int V_343 ;
T_2 V_30 , V_361 , V_362 ;
struct V_114 * V_114 ;
struct V_77 * V_258 ;
V_83 = F_57 ( V_10 , V_113 ) ;
if ( ! V_83 )
return - V_330 ;
if ( ! V_113 -> V_370 )
return - V_330 ;
V_38 = 2 ;
if ( V_113 -> V_277 > 0 )
V_38 ++ ;
V_47 = F_145 ( V_10 , V_10 -> V_65 [ V_59 ] ,
V_60 , V_113 -> V_61 ,
V_38 , V_113 , 0 , V_325 ) ;
if ( V_47 < 0 )
return V_47 ;
V_114 = V_113 -> V_115 ;
V_258 = V_114 -> V_258 [ 0 ] ;
V_251 = & V_83 -> V_20 -> V_29 ;
V_343 = V_83 -> V_26 ;
V_369 = (struct V_368 * ) V_113 -> V_370 ;
V_30 = 0 ;
V_30 |= V_371 | F_39 ( V_372 ) ;
if ( V_343 == 0 )
V_30 |= 0x1 ;
if ( ( V_10 -> V_355 >= 0x100 ) || ( V_10 -> V_35 & V_356 ) ) {
if ( V_113 -> V_277 > 0 ) {
if ( V_369 -> V_373 & V_374 )
V_30 |= F_177 ( V_375 ) ;
else
V_30 |= F_177 ( V_376 ) ;
}
}
F_142 ( V_10 , V_83 , true ,
V_369 -> V_373 | V_369 -> V_377 << 8 | F_178 ( V_369 -> V_378 ) << 16 ,
F_178 ( V_369 -> V_379 ) | F_178 ( V_369 -> V_380 ) << 16 ,
F_133 ( 8 ) | F_172 ( 0 ) ,
V_30 ) ;
if ( F_170 ( V_113 ) )
V_30 = V_367 | F_39 ( V_381 ) ;
else
V_30 = F_39 ( V_381 ) ;
V_362 = F_166 ( V_10 , 0 ,
V_113 -> V_277 ,
V_113 -> V_277 ,
V_113 , 1 ) ;
V_361 = F_133 ( V_113 -> V_277 ) |
F_171 ( V_362 ) |
F_172 ( 0 ) ;
if ( V_113 -> V_277 > 0 ) {
if ( V_369 -> V_373 & V_374 )
V_30 |= V_382 ;
F_142 ( V_10 , V_83 , true ,
F_173 ( V_113 -> V_337 ) ,
F_174 ( V_113 -> V_337 ) ,
V_361 ,
V_30 | V_83 -> V_26 ) ;
}
V_258 -> F_4 = V_83 -> V_20 ;
if ( V_113 -> V_277 > 0 && V_369 -> V_373 & V_374 )
V_30 = 0 ;
else
V_30 = V_382 ;
F_142 ( V_10 , V_83 , false ,
0 ,
0 ,
F_172 ( 0 ) ,
V_30 | V_366 | F_39 ( V_383 ) | V_83 -> V_26 ) ;
F_160 ( V_10 , V_59 , V_60 , 0 ,
V_343 , V_251 ) ;
return 0 ;
}
static unsigned int F_179 ( struct V_9 * V_10 ,
struct V_113 * V_113 , unsigned int V_354 )
{
unsigned int V_384 ;
if ( V_10 -> V_355 < 0x100 || V_113 -> V_82 -> V_216 < V_385 )
return 0 ;
V_384 = V_113 -> V_64 -> V_386 . V_387 ;
return F_150 ( V_354 , V_384 + 1 ) - 1 ;
}
static unsigned int F_180 ( struct V_9 * V_10 ,
struct V_113 * V_113 , unsigned int V_354 )
{
unsigned int V_384 ;
unsigned int V_388 ;
if ( V_10 -> V_355 < 0x100 )
return 0 ;
if ( V_113 -> V_82 -> V_216 >= V_385 ) {
V_384 = V_113 -> V_64 -> V_386 . V_387 ;
V_388 = V_354 % ( V_384 + 1 ) ;
if ( V_388 == 0 )
return V_384 ;
return V_388 - 1 ;
}
if ( V_354 == 0 )
return 0 ;
return V_354 - 1 ;
}
static int F_181 ( struct V_9 * V_10 ,
struct V_113 * V_113 , int V_389 )
{
int V_390 , V_391 , V_47 = 0 ;
int V_392 , V_393 , V_394 ;
if ( V_113 -> V_82 -> V_216 == V_347 ||
V_113 -> V_82 -> V_216 == V_348 )
V_390 = V_113 -> V_390 + V_389 * V_113 -> V_346 ;
else
V_390 = ( V_113 -> V_390 + V_389 * V_113 -> V_346 ) >> 3 ;
V_391 = F_182 ( V_10 -> V_395 ) & 0x7 ;
if ( F_182 ( V_10 -> V_395 ) & ( 1 << 3 ) )
V_391 <<= 3 ;
V_394 = F_17 ( & V_10 -> V_396 -> V_397 ) ;
V_392 = F_183 ( V_394 + V_391 + 1 , 8 ) ;
V_393 = F_184 ( V_394 + 895 * 8 , 8 ) ;
V_390 &= 0x7ff ;
V_392 = ( V_392 >> 3 ) & 0x7ff ;
V_393 = ( V_393 >> 3 ) & 0x7ff ;
F_15 ( V_10 , L_122 ,
V_249 , V_389 , F_17 ( & V_10 -> V_396 -> V_397 ) ,
V_392 , V_393 , V_390 ) ;
if ( V_392 < V_393 ) {
if ( V_390 > V_393 ||
V_390 < V_392 )
V_47 = - V_330 ;
} else if ( V_392 > V_393 ) {
if ( ( V_390 > V_393 &&
V_390 < V_392 ) )
V_47 = - V_330 ;
} else {
V_47 = - V_330 ;
}
if ( V_389 == 0 ) {
if ( V_47 == - V_330 || V_390 == V_392 ) {
V_390 = V_392 + 1 ;
if ( V_113 -> V_82 -> V_216 == V_347 ||
V_113 -> V_82 -> V_216 == V_348 )
V_113 -> V_390 = V_390 ;
else
V_113 -> V_390 = V_390 << 3 ;
V_47 = 0 ;
}
}
if ( V_47 ) {
F_33 ( V_10 , L_123 ,
V_390 , V_394 , V_389 ,
V_392 , V_393 ) ;
F_33 ( V_10 , L_124 ) ;
return V_47 ;
}
return V_390 ;
}
static int F_185 ( struct V_9 * V_10 , T_8 V_325 ,
struct V_113 * V_113 , int V_59 , unsigned int V_60 )
{
struct V_11 * V_83 ;
struct V_114 * V_114 ;
struct V_77 * V_258 ;
int V_398 , V_399 ;
struct V_195 * V_251 ;
bool V_106 ;
int V_343 ;
T_2 V_30 , V_361 ;
int V_342 , V_350 , V_400 , V_401 , V_47 ;
T_3 V_402 , V_86 ;
int V_136 , V_137 ;
bool V_27 ;
struct V_63 * V_403 ;
int V_404 ;
V_403 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
V_83 = V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] . V_12 ;
V_398 = V_113 -> V_405 ;
if ( V_398 < 1 ) {
F_15 ( V_10 , L_125 ) ;
return - V_330 ;
}
V_402 = ( T_3 ) V_113 -> V_337 ;
V_251 = & V_83 -> V_20 -> V_29 ;
V_343 = V_83 -> V_26 ;
V_114 = V_113 -> V_115 ;
for ( V_136 = 0 ; V_136 < V_398 ; V_136 ++ ) {
unsigned int V_406 , V_407 ;
unsigned int V_408 , V_409 ;
T_2 V_410 ;
V_106 = true ;
V_342 = 0 ;
V_86 = V_402 + V_113 -> V_289 [ V_136 ] . V_341 ;
V_400 = V_113 -> V_289 [ V_136 ] . V_118 ;
V_401 = V_400 ;
V_407 = F_167 ( F_168 ( & V_113 -> V_64 -> V_298 ) ) ;
V_406 = F_150 ( V_400 , V_407 ) ;
if ( V_406 == 0 )
V_406 ++ ;
V_408 = F_179 ( V_10 , V_113 , V_406 ) ;
V_409 = F_180 ( V_10 ,
V_113 , V_406 ) ;
V_399 = F_157 ( V_113 , V_136 ) ;
V_47 = F_145 ( V_10 , V_10 -> V_65 [ V_59 ] , V_60 ,
V_113 -> V_61 , V_399 , V_113 , V_136 , V_325 ) ;
if ( V_47 < 0 ) {
if ( V_136 == 0 )
return V_47 ;
goto V_148;
}
V_258 = V_114 -> V_258 [ V_136 ] ;
V_410 = V_411 ;
if ( ! ( V_113 -> V_278 & V_412 ) &&
F_186 ( V_10 -> V_413 ) ) {
V_404 = F_181 ( V_10 , V_113 , V_136 ) ;
if ( V_404 >= 0 )
V_410 = F_187 ( V_404 ) ;
}
V_30 = F_39 ( V_414 ) |
F_188 ( V_409 ) |
V_410 |
( V_136 ? V_83 -> V_26 : ! V_343 ) ;
if ( ! V_403 -> V_415 )
V_30 |= F_189 ( V_408 ) ;
for ( V_137 = 0 ; V_137 < V_399 ; V_137 ++ ) {
T_2 V_362 = 0 ;
if ( ! V_106 )
V_30 = F_39 ( V_365 ) |
V_83 -> V_26 ;
if ( F_170 ( V_113 ) )
V_30 |= V_367 ;
if ( V_137 < V_399 - 1 ) {
V_27 = true ;
V_30 |= V_31 ;
} else {
V_27 = false ;
V_258 -> F_4 = V_83 -> V_20 ;
V_30 |= V_366 ;
if ( V_10 -> V_355 >= 0x100 &&
! ( V_10 -> V_35 & V_416 ) &&
V_136 < V_398 - 1 )
V_30 |= V_417 ;
}
V_350 = F_169 ( V_86 ) ;
if ( V_350 > V_401 )
V_350 = V_401 ;
V_362 = F_166 ( V_10 , V_342 ,
V_350 , V_400 ,
V_113 , V_399 - V_137 - 1 ) ;
V_361 = F_133 ( V_350 ) |
F_172 ( 0 ) ;
if ( V_106 && V_403 -> V_415 )
V_361 |= F_190 ( V_408 ) ;
else
V_361 |= F_171 ( V_362 ) ;
V_106 = false ;
F_142 ( V_10 , V_83 , V_27 ,
F_173 ( V_86 ) ,
F_174 ( V_86 ) ,
V_361 ,
V_30 ) ;
V_342 += V_350 ;
V_86 += V_350 ;
V_401 -= V_350 ;
}
if ( V_342 != V_400 ) {
F_24 ( V_10 , L_126 ) ;
V_47 = - V_330 ;
goto V_148;
}
}
if ( F_186 ( V_10 -> V_413 ) )
V_403 -> V_418 = V_113 -> V_390 + V_398 * V_113 -> V_346 ;
if ( F_44 ( V_10 ) -> V_121 . V_122 == 0 ) {
if ( V_10 -> V_35 & V_123 )
F_191 () ;
}
F_44 ( V_10 ) -> V_121 . V_122 ++ ;
F_160 ( V_10 , V_59 , V_60 , V_113 -> V_61 ,
V_343 , V_251 ) ;
return 0 ;
V_148:
for ( V_136 -- ; V_136 >= 0 ; V_136 -- )
F_58 ( & V_114 -> V_258 [ V_136 ] -> V_72 ) ;
V_114 -> V_258 [ 0 ] -> F_4 = V_83 -> V_20 ;
F_38 ( V_10 , V_83 , V_114 -> V_258 [ 0 ] , true ) ;
V_83 -> V_20 = V_114 -> V_258 [ 0 ] -> V_106 ;
V_83 -> V_32 = V_114 -> V_258 [ 0 ] -> V_105 ;
V_83 -> V_26 = V_343 ;
V_83 -> V_25 = V_83 -> V_142 ;
F_46 ( F_42 ( V_113 -> V_82 -> V_117 ) , V_113 ) ;
return V_47 ;
}
int F_192 ( struct V_9 * V_10 , T_8 V_325 ,
struct V_113 * V_113 , int V_59 , unsigned int V_60 )
{
struct V_81 * V_268 ;
struct V_11 * V_83 ;
struct V_95 * V_96 ;
int V_390 ;
int V_398 , V_38 , V_136 ;
int V_47 ;
struct V_63 * V_403 ;
int V_391 ;
V_268 = V_10 -> V_65 [ V_59 ] ;
V_403 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
V_83 = V_268 -> V_66 [ V_60 ] . V_12 ;
V_96 = F_37 ( V_10 , V_268 -> V_97 , V_60 ) ;
V_38 = 0 ;
V_398 = V_113 -> V_405 ;
for ( V_136 = 0 ; V_136 < V_398 ; V_136 ++ )
V_38 += F_157 ( V_113 , V_136 ) ;
V_47 = F_143 ( V_10 , V_83 , F_3 ( V_96 -> V_153 ) & V_154 ,
V_38 , V_325 ) ;
if ( V_47 )
return V_47 ;
F_161 ( V_10 , V_113 , V_96 ) ;
if ( F_186 ( V_10 -> V_413 ) && ! F_31 ( & V_83 -> V_72 ) ) {
if ( ( F_3 ( V_96 -> V_153 ) & V_154 ) ==
V_332 ) {
V_113 -> V_390 = V_403 -> V_418 ;
goto V_419;
}
}
V_390 = F_17 ( & V_10 -> V_396 -> V_397 ) ;
V_390 &= 0x3fff ;
V_391 = F_182 ( V_10 -> V_395 ) & 0x7 ;
if ( F_182 ( V_10 -> V_395 ) & ( 1 << 3 ) )
V_391 <<= 3 ;
V_390 += V_391 + V_420 ;
V_390 = F_183 ( V_390 , 8 ) ;
if ( V_113 -> V_82 -> V_216 == V_347 ||
V_113 -> V_82 -> V_216 == V_348 ) {
V_390 = F_183 ( V_390 , V_113 -> V_346 << 3 ) ;
V_113 -> V_390 = V_390 >> 3 ;
} else {
V_390 = F_183 ( V_390 , V_113 -> V_346 ) ;
V_113 -> V_390 = V_390 ;
}
V_419:
V_83 -> V_142 = V_83 -> V_25 ;
return F_185 ( V_10 , V_325 , V_113 , V_59 , V_60 ) ;
}
static int F_193 ( struct V_9 * V_10 , struct V_162 * V_176 ,
T_2 V_321 , T_2 V_322 ,
T_2 V_323 , T_2 V_324 , bool V_421 )
{
int V_422 = V_10 -> V_423 ;
int V_47 ;
if ( ( V_10 -> V_56 & V_57 ) ||
( V_10 -> V_56 & V_317 ) ) {
F_15 ( V_10 , L_127 ) ;
return - V_58 ;
}
if ( ! V_421 )
V_422 ++ ;
V_47 = F_143 ( V_10 , V_10 -> V_49 , V_332 ,
V_422 , V_164 ) ;
if ( V_47 < 0 ) {
F_24 ( V_10 , L_128 ) ;
if ( V_421 )
F_24 ( V_10 , L_129
L_130 ) ;
return V_47 ;
}
V_176 -> V_184 = V_10 -> V_49 -> V_20 ;
F_148 ( & V_176 -> V_177 , & V_10 -> V_177 ) ;
if ( V_10 -> V_177 . V_14 == & V_176 -> V_177 &&
! F_194 ( & V_10 -> V_51 ) ) {
V_10 -> V_186 = V_176 ;
F_20 ( & V_10 -> V_51 , V_52 + V_53 ) ;
}
F_142 ( V_10 , V_10 -> V_49 , false , V_321 , V_322 , V_323 ,
V_324 | V_10 -> V_49 -> V_26 ) ;
return 0 ;
}
int F_195 ( struct V_9 * V_10 , struct V_162 * V_176 ,
T_2 V_208 , T_2 V_59 )
{
return F_193 ( V_10 , V_176 , 0 , 0 , 0 ,
F_39 ( V_208 ) | F_196 ( V_59 ) , false ) ;
}
int F_197 ( struct V_9 * V_10 , struct V_162 * V_176 ,
T_1 V_424 , T_2 V_59 , enum V_425 V_369 )
{
return F_193 ( V_10 , V_176 , F_173 ( V_424 ) ,
F_174 ( V_424 ) , 0 ,
F_39 ( V_202 ) | F_196 ( V_59 )
| ( V_369 == V_426 ? V_427 : 0 ) , false ) ;
}
int F_198 ( struct V_9 * V_10 , struct V_162 * V_176 ,
T_2 V_321 , T_2 V_322 , T_2 V_323 , T_2 V_324 )
{
return F_193 ( V_10 , V_176 , V_321 , V_322 , V_323 , V_324 , false ) ;
}
int F_199 ( struct V_9 * V_10 , struct V_162 * V_176 ,
T_2 V_59 )
{
return F_193 ( V_10 , V_176 , 0 , 0 , 0 ,
F_39 ( V_206 ) | F_196 ( V_59 ) ,
false ) ;
}
int F_75 ( struct V_9 * V_10 ,
struct V_162 * V_176 , T_1 V_424 ,
T_2 V_59 , bool V_421 )
{
return F_193 ( V_10 , V_176 , F_173 ( V_424 ) ,
F_174 ( V_424 ) , 0 ,
F_39 ( V_200 ) | F_196 ( V_59 ) ,
V_421 ) ;
}
int F_200 ( struct V_9 * V_10 , struct V_162 * V_176 ,
T_1 V_424 , T_2 V_59 , bool V_421 )
{
return F_193 ( V_10 , V_176 , F_173 ( V_424 ) ,
F_174 ( V_424 ) , 0 ,
F_39 ( V_201 ) | F_196 ( V_59 ) ,
V_421 ) ;
}
int F_201 ( struct V_9 * V_10 , struct V_162 * V_176 ,
int V_59 , unsigned int V_60 , int V_428 )
{
T_2 V_429 = F_196 ( V_59 ) ;
T_2 V_430 = F_202 ( V_60 ) ;
T_2 type = F_39 ( V_203 ) ;
T_2 V_431 = F_203 ( V_428 ) ;
return F_193 ( V_10 , V_176 , 0 , 0 , 0 ,
V_429 | V_430 | type | V_431 , false ) ;
}
void F_59 ( struct V_9 * V_10 ,
unsigned int V_59 , unsigned int V_60 ,
unsigned int V_61 ,
struct V_79 * V_130 )
{
T_1 V_86 ;
T_2 V_429 = F_196 ( V_59 ) ;
T_2 V_430 = F_202 ( V_60 ) ;
T_2 V_432 = F_204 ( V_61 ) ;
T_2 V_433 = 0 ;
T_2 type = F_39 ( V_204 ) ;
struct V_63 * V_64 ;
struct V_162 * V_176 ;
int V_47 ;
F_35 ( V_10 , V_90 ,
L_131 ,
V_130 -> V_100 ,
( unsigned long long ) V_130 -> V_100 -> V_8 ,
V_130 -> V_101 ,
( unsigned long long ) F_1 (
V_130 -> V_100 , V_130 -> V_101 ) ,
V_130 -> V_99 ) ;
V_86 = F_1 ( V_130 -> V_100 ,
V_130 -> V_101 ) ;
if ( V_86 == 0 ) {
F_33 ( V_10 , L_132 ) ;
F_33 ( V_10 , L_133 ,
V_130 -> V_100 , V_130 -> V_101 ) ;
return;
}
V_64 = & V_10 -> V_65 [ V_59 ] -> V_66 [ V_60 ] ;
if ( ( V_64 -> V_67 & V_69 ) ) {
F_33 ( V_10 , L_132 ) ;
F_33 ( V_10 , L_134 ) ;
return;
}
V_176 = F_74 ( V_10 , false , false , V_164 ) ;
if ( ! V_176 ) {
F_33 ( V_10 , L_135 ) ;
return;
}
V_64 -> V_159 = V_130 -> V_100 ;
V_64 -> V_144 = V_130 -> V_101 ;
if ( V_61 )
V_433 = F_205 ( V_434 ) ;
V_47 = F_193 ( V_10 , V_176 ,
F_173 ( V_86 ) | V_433 | V_130 -> V_99 ,
F_174 ( V_86 ) , V_432 ,
V_429 | V_430 | type , false ) ;
if ( V_47 < 0 ) {
F_206 ( V_10 , V_176 ) ;
return;
}
V_64 -> V_67 |= V_69 ;
}
int F_122 ( struct V_9 * V_10 , struct V_162 * V_176 ,
int V_59 , unsigned int V_60 )
{
T_2 V_429 = F_196 ( V_59 ) ;
T_2 V_430 = F_202 ( V_60 ) ;
T_2 type = F_39 ( V_205 ) ;
return F_193 ( V_10 , V_176 , 0 , 0 , 0 ,
V_429 | V_430 | type , false ) ;
}
