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
struct V_11 * V_99 ;
struct V_89 * V_4 ;
struct V_100 * V_101 ;
T_1 V_102 ;
V_99 = F_42 ( V_10 , V_69 ,
V_70 , V_71 ) ;
if ( ! V_99 ) {
F_32 ( V_10 , L_18
L_19 ,
V_71 ) ;
return;
}
V_97 -> V_103 = 0 ;
F_46 ( V_10 , V_104 ,
L_20 ) ;
V_97 -> V_105 = F_41 ( V_95 -> V_87 ,
V_92 -> V_76 [ V_70 ] . V_106 ,
& V_97 -> V_103 ) ;
if ( ! V_97 -> V_105 ) {
F_47 ( 1 ) ;
return;
}
F_46 ( V_10 , V_104 ,
L_21 ) ;
V_101 = F_48 ( V_10 , V_92 -> V_107 , V_70 ) ;
V_97 -> V_103 = 0x1 & F_49 ( V_101 -> V_108 ) ;
V_97 -> V_109 = V_95 -> F_4 ;
F_46 ( V_10 , V_104 ,
L_22 ) ;
V_97 -> V_105 = F_41 ( V_97 -> V_105 ,
V_97 -> V_109 ,
& V_97 -> V_103 ) ;
if ( ! V_97 -> V_105 ) {
F_47 ( 1 ) ;
return;
}
V_4 = & V_97 -> V_109 -> V_30 ;
if ( F_5 ( V_4 -> V_31 [ 3 ] ) &&
( V_4 -> V_31 [ 3 ] & F_12 ( V_18 ) ) )
V_97 -> V_103 ^= 0x1 ;
F_8 ( V_10 , V_99 , & V_97 -> V_105 , & V_97 -> V_109 ) ;
if ( V_99 -> V_15 == V_99 -> V_15 -> V_14 &&
V_97 -> V_109 < V_92 -> V_76 [ V_70 ] . V_106 )
V_97 -> V_103 ^= 0x1 ;
F_46 ( V_10 , V_104 ,
L_23 , V_97 -> V_103 ) ;
F_46 ( V_10 , V_104 ,
L_24 ,
V_97 -> V_105 ) ;
V_102 = F_1 ( V_97 -> V_105 , V_97 -> V_109 ) ;
F_46 ( V_10 , V_104 ,
L_25 ,
( unsigned long long ) V_102 ) ;
}
static void F_50 ( struct V_9 * V_10 , struct V_11 * V_99 ,
struct V_94 * V_95 , bool V_110 )
{
struct V_1 * V_88 ;
union V_3 * V_111 ;
for ( V_88 = V_95 -> V_87 , V_111 = V_95 -> V_112 ;
true ;
F_8 ( V_10 , V_99 , & V_88 , & V_111 ) ) {
if ( F_5 ( V_111 -> V_30 . V_31 [ 3 ] ) ) {
V_111 -> V_30 . V_31 [ 3 ] &= F_12 ( ~ V_32 ) ;
if ( V_110 )
V_111 -> V_30 . V_31 [ 3 ] ^=
F_12 ( V_37 ) ;
F_46 ( V_10 , V_104 ,
L_26 ) ;
F_46 ( V_10 , V_104 ,
L_27
L_28 ,
V_111 ,
( unsigned long long ) F_1 ( V_88 , V_111 ) ,
V_88 ,
( unsigned long long ) V_88 -> V_8 ) ;
} else {
V_111 -> V_30 . V_31 [ 0 ] = 0 ;
V_111 -> V_30 . V_31 [ 1 ] = 0 ;
V_111 -> V_30 . V_31 [ 2 ] = 0 ;
V_111 -> V_30 . V_31 [ 3 ] &= F_12 ( V_37 ) ;
if ( V_110 && V_111 != V_95 -> V_112 &&
V_111 != V_95 -> F_4 )
V_111 -> V_30 . V_31 [ 3 ] ^=
F_12 ( V_37 ) ;
V_111 -> V_30 . V_31 [ 3 ] |= F_12 (
F_51 ( V_113 ) ) ;
F_46 ( V_10 , V_104 ,
L_29 ,
( unsigned long long )
F_1 ( V_88 , V_111 ) ) ;
}
if ( V_111 == V_95 -> F_4 )
break;
}
}
void F_52 ( struct V_9 * V_10 ,
unsigned int V_69 , unsigned int V_70 ,
unsigned int V_71 ,
struct V_96 * V_114 )
{
struct V_73 * V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
F_46 ( V_10 , V_104 ,
L_30
L_31 ,
V_114 -> V_105 ,
( unsigned long long ) V_114 -> V_105 -> V_8 ,
V_114 -> V_109 ,
( unsigned long long ) F_1 ( V_114 -> V_105 , V_114 -> V_109 ) ,
V_114 -> V_103 ) ;
F_53 ( V_10 , V_69 , V_70 , V_71 ,
V_114 -> V_105 ,
V_114 -> V_109 ,
( T_2 ) V_114 -> V_103 ) ;
V_74 -> V_77 |= V_79 ;
}
static void F_54 ( struct V_9 * V_10 ,
struct V_73 * V_74 )
{
V_74 -> V_77 &= ~ V_78 ;
if ( F_55 ( & V_74 -> V_115 ) )
V_74 -> V_116 -- ;
}
static void F_56 ( struct V_9 * V_10 ,
struct V_94 * V_95 , int V_117 )
{
struct V_118 * V_119 ;
struct V_91 * V_91 ;
struct V_120 * V_120 ;
V_91 = V_95 -> V_91 ;
V_120 = V_91 -> V_121 ;
V_120 -> V_122 ++ ;
V_119 = F_57 ( V_91 -> V_92 -> V_123 ) ;
if ( V_120 -> V_122 == V_120 -> V_124 ) {
if ( F_58 ( V_91 -> V_125 ) == V_126 ) {
F_36 ( V_10 ) -> V_127 . V_128 -- ;
if ( F_36 ( V_10 ) -> V_127 . V_128 == 0 ) {
if ( V_10 -> V_35 & V_129 )
F_59 () ;
}
}
F_60 ( V_119 , V_91 ) ;
F_61 ( & V_10 -> V_66 ) ;
F_62 ( V_119 , V_91 , V_117 ) ;
F_63 ( V_10 , V_120 ) ;
F_64 ( & V_10 -> V_66 ) ;
}
}
static void F_65 ( struct V_9 * V_10 , int V_69 ,
union V_3 * V_4 , struct V_130 * V_131 )
{
unsigned int V_70 ;
struct V_98 * V_132 ;
struct V_11 * V_99 ;
struct V_73 * V_74 ;
struct V_133 * V_134 ;
struct V_94 * V_95 = NULL ;
struct V_94 * V_135 ;
struct V_96 V_114 ;
if ( F_33 ( F_66 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ) ) {
V_132 = V_10 -> V_75 [ V_69 ] ;
if ( V_132 )
F_67 ( V_10 , V_132 ,
V_131 ) ;
else
F_32 ( V_10 , L_32
L_33 ,
V_69 ) ;
return;
}
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_70 = F_68 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
if ( F_40 ( & V_74 -> V_136 ) ) {
F_54 ( V_10 , V_74 ) ;
V_74 -> V_137 = NULL ;
V_74 -> V_106 = NULL ;
F_39 ( V_10 , V_69 , V_70 ) ;
return;
}
F_69 (entry, &ep->cancelled_td_list) {
V_95 = F_70 ( V_134 , struct V_94 , V_136 ) ;
F_46 ( V_10 , V_104 ,
L_34 ,
( unsigned long long ) F_1 (
V_95 -> V_87 , V_95 -> V_112 ) ) ;
V_99 = F_43 ( V_10 , V_95 -> V_91 ) ;
if ( ! V_99 ) {
F_32 ( V_10 , L_35
L_36 ,
V_95 -> V_91 ,
V_95 -> V_91 -> V_71 ) ;
goto V_138;
}
if ( V_95 == V_74 -> V_137 )
F_45 ( V_10 , V_69 , V_70 ,
V_95 -> V_91 -> V_71 ,
V_95 , & V_114 ) ;
else
F_50 ( V_10 , V_99 , V_95 , false ) ;
V_138:
F_71 ( & V_95 -> V_82 ) ;
}
V_135 = V_95 ;
F_54 ( V_10 , V_74 ) ;
if ( V_114 . V_109 && V_114 . V_105 ) {
F_52 ( V_10 ,
V_69 , V_70 ,
V_74 -> V_137 -> V_91 -> V_71 ,
& V_114 ) ;
F_15 ( V_10 ) ;
} else {
F_39 ( V_10 , V_69 , V_70 ) ;
}
if ( ! ( V_74 -> V_77 & V_80 ) ) {
V_74 -> V_137 = NULL ;
V_74 -> V_106 = NULL ;
}
do {
V_95 = F_70 ( V_74 -> V_136 . V_14 ,
struct V_94 , V_136 ) ;
F_71 ( & V_95 -> V_136 ) ;
F_56 ( V_10 , V_95 , 0 ) ;
if ( V_10 -> V_53 & V_54 )
return;
} while ( V_95 != V_135 );
}
void F_72 ( unsigned long V_139 )
{
struct V_9 * V_10 ;
struct V_73 * V_74 ;
struct V_73 * V_140 ;
struct V_11 * V_12 ;
struct V_94 * V_95 ;
int V_47 , V_141 , V_142 ;
unsigned long V_65 ;
V_74 = (struct V_73 * ) V_139 ;
V_10 = V_74 -> V_10 ;
F_31 ( & V_10 -> V_66 , V_65 ) ;
V_74 -> V_116 -- ;
if ( V_10 -> V_53 & V_54 ) {
F_46 ( V_10 , V_104 ,
L_37
L_38 ) ;
F_34 ( & V_10 -> V_66 , V_65 ) ;
return;
}
if ( ! ( V_74 -> V_116 == 0 && ( V_74 -> V_77 & V_78 ) ) ) {
F_46 ( V_10 , V_104 ,
L_39
L_40 ) ;
F_34 ( & V_10 -> V_66 , V_65 ) ;
return;
}
F_32 ( V_10 , L_41 ) ;
F_32 ( V_10 , L_42 ) ;
V_10 -> V_53 |= V_54 ;
F_24 ( V_10 ) ;
F_34 ( & V_10 -> V_66 , V_65 ) ;
V_47 = F_25 ( V_10 ) ;
F_31 ( & V_10 -> V_66 , V_65 ) ;
if ( V_47 < 0 ) {
F_32 ( V_10 , L_43 ) ;
F_32 ( V_10 , L_44 ) ;
}
for ( V_141 = 0 ; V_141 < V_143 ; V_141 ++ ) {
if ( ! V_10 -> V_75 [ V_141 ] )
continue;
for ( V_142 = 0 ; V_142 < 31 ; V_142 ++ ) {
V_140 = & V_10 -> V_75 [ V_141 ] -> V_76 [ V_142 ] ;
V_12 = V_140 -> V_12 ;
if ( ! V_12 )
continue;
F_46 ( V_10 , V_104 ,
L_45
L_46 , V_141 , V_142 ) ;
while ( ! F_40 ( & V_12 -> V_82 ) ) {
V_95 = F_73 ( & V_12 -> V_82 ,
struct V_94 ,
V_82 ) ;
F_71 ( & V_95 -> V_82 ) ;
if ( ! F_40 ( & V_95 -> V_136 ) )
F_71 ( & V_95 -> V_136 ) ;
F_56 ( V_10 , V_95 ,
- V_55 ) ;
}
while ( ! F_40 ( & V_140 -> V_136 ) ) {
V_95 = F_73 (
& V_140 -> V_136 ,
struct V_94 ,
V_136 ) ;
F_71 ( & V_95 -> V_136 ) ;
F_56 ( V_10 , V_95 ,
- V_55 ) ;
}
}
}
F_34 ( & V_10 -> V_66 , V_65 ) ;
F_46 ( V_10 , V_104 ,
L_47 ) ;
F_35 ( F_36 ( V_10 ) -> V_68 ) ;
F_46 ( V_10 , V_104 ,
L_48 ) ;
}
static void F_74 ( struct V_9 * V_10 ,
struct V_98 * V_92 ,
struct V_11 * V_99 ,
unsigned int V_70 )
{
union V_3 * V_144 ;
int V_145 ;
bool V_146 = false ;
V_145 = V_99 -> V_26 ;
V_144 = V_99 -> V_25 ;
if ( F_4 ( V_10 , V_99 , V_99 -> V_24 , V_99 -> V_25 ) ) {
V_99 -> V_24 = V_99 -> V_24 -> V_14 ;
V_99 -> V_25 = V_99 -> V_24 -> V_6 ;
}
while ( V_99 -> V_25 != V_92 -> V_76 [ V_70 ] . V_147 ) {
V_99 -> V_26 ++ ;
V_99 -> V_25 ++ ;
if ( F_4 ( V_10 , V_99 , V_99 -> V_24 ,
V_99 -> V_25 ) ) {
if ( V_99 -> V_25 ==
V_92 -> V_76 [ V_70 ] . V_147 )
break;
V_99 -> V_24 = V_99 -> V_24 -> V_14 ;
V_99 -> V_25 = V_99 -> V_24 -> V_6 ;
}
if ( V_99 -> V_25 == V_144 ) {
V_146 = true ;
break;
}
}
if ( V_146 ) {
F_16 ( V_10 , L_49 ) ;
V_99 -> V_26 = V_145 ;
}
}
static void F_75 ( struct V_9 * V_10 , int V_69 ,
union V_3 * V_4 , T_2 V_148 )
{
unsigned int V_70 ;
unsigned int V_71 ;
struct V_11 * V_99 ;
struct V_98 * V_92 ;
struct V_100 * V_101 ;
struct V_149 * V_150 ;
V_70 = F_68 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_71 = F_76 ( F_3 ( V_4 -> V_30 . V_31 [ 2 ] ) ) ;
V_92 = V_10 -> V_75 [ V_69 ] ;
V_99 = F_77 ( V_92 , V_70 , V_71 ) ;
if ( ! V_99 ) {
F_32 ( V_10 , L_50
L_51 ,
V_71 ) ;
V_92 -> V_76 [ V_70 ] . V_77 &= ~ V_79 ;
return;
}
V_101 = F_48 ( V_10 , V_92 -> V_107 , V_70 ) ;
V_150 = F_78 ( V_10 , V_92 -> V_107 ) ;
if ( V_148 != V_151 ) {
unsigned int V_77 ;
unsigned int V_152 ;
switch ( V_148 ) {
case V_153 :
F_32 ( V_10 , L_52
L_53 ) ;
break;
case V_154 :
F_32 ( V_10 , L_54
L_55 ) ;
V_77 = F_3 ( V_101 -> V_155 ) ;
V_77 &= V_156 ;
V_152 = F_3 ( V_150 -> V_157 ) ;
V_152 = F_79 ( V_152 ) ;
F_46 ( V_10 , V_104 ,
L_56 ,
V_152 , V_77 ) ;
break;
case V_158 :
F_32 ( V_10 , L_57
L_58 , V_69 ) ;
break;
default:
F_32 ( V_10 , L_59
L_60 ,
V_148 ) ;
break;
}
} else {
F_46 ( V_10 , V_104 ,
L_61 ,
F_49 ( V_101 -> V_108 ) ) ;
if ( F_1 ( V_92 -> V_76 [ V_70 ] . V_159 ,
V_92 -> V_76 [ V_70 ] . V_147 ) ==
( F_49 ( V_101 -> V_108 ) & ~ ( V_160 ) ) ) {
F_74 ( V_10 , V_92 ,
V_99 , V_70 ) ;
} else {
F_32 ( V_10 , L_62
L_63 ) ;
F_32 ( V_10 , L_64 ,
V_92 -> V_76 [ V_70 ] . V_159 ,
V_92 -> V_76 [ V_70 ] . V_147 ) ;
}
}
V_92 -> V_76 [ V_70 ] . V_77 &= ~ V_79 ;
V_92 -> V_76 [ V_70 ] . V_159 = NULL ;
V_92 -> V_76 [ V_70 ] . V_147 = NULL ;
F_39 ( V_10 , V_69 , V_70 ) ;
}
static void F_80 ( struct V_9 * V_10 , int V_69 ,
union V_3 * V_4 , T_2 V_148 )
{
unsigned int V_70 ;
V_70 = F_68 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
F_46 ( V_10 , V_161 ,
L_65 , V_148 ) ;
if ( V_10 -> V_35 & V_162 ) {
F_46 ( V_10 , V_163 ,
L_66 ) ;
F_81 ( V_10 ,
V_10 -> V_75 [ V_69 ] -> V_164 -> V_8 , V_69 ,
false ) ;
F_15 ( V_10 ) ;
} else {
V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] . V_77 &= ~ V_80 ;
F_39 ( V_10 , V_69 , V_70 ) ;
}
}
static void F_82 ( struct V_9 * V_10 ,
struct V_56 * V_57 , T_2 V_117 )
{
V_57 -> V_117 = V_117 ;
F_83 ( & V_57 -> V_165 ) ;
if ( V_57 -> V_166 )
F_84 ( V_57 -> V_166 ) ;
else
F_85 ( V_10 , V_57 ) ;
}
static int F_67 ( struct V_9 * V_10 ,
struct V_98 * V_132 ,
struct V_130 * V_131 )
{
struct V_56 * V_57 ;
if ( F_40 ( & V_132 -> V_165 ) )
return 0 ;
V_57 = F_70 ( V_132 -> V_165 . V_14 ,
struct V_56 , V_165 ) ;
if ( V_10 -> V_49 -> V_25 != V_57 -> V_167 )
return 0 ;
F_82 ( V_10 , V_57 ,
F_86 ( F_3 ( V_131 -> V_117 ) ) ) ;
return 1 ;
}
static void F_87 ( struct V_9 * V_10 , struct V_59 * V_168 )
{
struct V_1 * V_88 ;
union V_3 * V_58 ;
T_2 V_27 ;
if ( V_10 -> V_49 -> V_25 == V_10 -> V_49 -> V_20 )
return;
V_88 = F_41 ( V_10 -> V_49 -> V_15 ,
V_10 -> V_49 -> V_25 , & V_27 ) ;
if ( ! V_88 ) {
F_32 ( V_10 , L_67 ,
V_10 -> V_49 -> V_25 ,
( unsigned long long )
F_1 ( V_10 -> V_49 -> V_24 ,
V_10 -> V_49 -> V_25 ) ) ;
F_88 ( V_10 , V_10 -> V_49 ) ;
F_89 ( V_10 , V_10 -> V_49 ) ;
return;
}
for ( V_58 = V_10 -> V_49 -> V_25 ;
V_58 != V_10 -> V_49 -> V_20 ;
F_8 ( V_10 , V_10 -> V_49 , & V_88 , & V_58 ) ) {
if ( F_5 ( V_58 -> V_30 . V_31 [ 3 ] ) )
continue;
if ( V_168 -> V_58 == V_58 ) {
if ( V_168 -> V_57 )
F_82 ( V_10 ,
V_168 -> V_57 , V_169 ) ;
V_27 = F_3 ( V_58 -> V_30 . V_31 [ 3 ] )
& V_37 ;
V_58 -> V_30 . V_31 [ 0 ] = 0 ;
V_58 -> V_30 . V_31 [ 1 ] = 0 ;
V_58 -> V_30 . V_31 [ 2 ] = 0 ;
V_58 -> V_30 . V_31 [ 3 ] = F_12 (
F_51 ( V_170 ) | V_27 ) ;
break;
}
}
}
static void F_90 ( struct V_9 * V_10 )
{
struct V_59 * V_168 , * V_171 ;
if ( F_40 ( & V_10 -> V_63 ) )
return;
F_91 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
F_87 ( V_10 , V_168 ) ;
F_83 ( & V_168 -> V_63 ) ;
F_92 ( V_168 ) ;
}
}
static int F_93 ( struct V_9 * V_10 ,
union V_3 * V_58 )
{
struct V_59 * V_168 , * V_171 ;
if ( F_40 ( & V_10 -> V_63 ) )
return 0 ;
F_91 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
if ( V_168 -> V_58 == V_58 ) {
if ( V_168 -> V_57 )
F_82 ( V_10 ,
V_168 -> V_57 , V_169 ) ;
F_83 ( & V_168 -> V_63 ) ;
F_92 ( V_168 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_94 ( struct V_9 * V_10 ,
int V_172 )
{
int V_173 = 0 ;
V_173 = F_93 ( V_10 ,
V_10 -> V_49 -> V_25 ) ;
if ( V_172 == V_174 )
V_10 -> V_41 = V_175 ;
else if ( V_172 == V_169 ) {
F_90 ( V_10 ) ;
V_10 -> V_41 = V_42 ;
if ( V_10 -> V_49 -> V_25 != V_10 -> V_49 -> V_20 )
F_15 ( V_10 ) ;
}
return V_173 ;
}
static void F_95 ( struct V_9 * V_10 , int V_69 ,
T_2 V_148 )
{
if ( V_148 == V_151 )
V_10 -> V_69 = V_69 ;
else
V_10 -> V_69 = 0 ;
F_84 ( & V_10 -> V_176 ) ;
}
static void F_96 ( struct V_9 * V_10 , int V_69 )
{
struct V_98 * V_132 ;
V_132 = V_10 -> V_75 [ V_69 ] ;
if ( ! V_132 )
return;
if ( V_10 -> V_35 & V_177 )
F_97 ( V_10 , V_132 , true ) ;
F_98 ( V_10 , V_69 ) ;
}
static void F_99 ( struct V_9 * V_10 , int V_69 ,
struct V_130 * V_131 , T_2 V_148 )
{
struct V_98 * V_132 ;
struct V_178 * V_179 ;
unsigned int V_70 ;
unsigned int V_77 ;
T_2 V_180 , V_181 ;
V_132 = V_10 -> V_75 [ V_69 ] ;
if ( F_67 ( V_10 , V_132 , V_131 ) )
return;
V_179 = F_100 ( V_10 , V_132 -> V_164 ) ;
if ( ! V_179 ) {
F_32 ( V_10 , L_68 ) ;
return;
}
V_180 = F_3 ( V_179 -> V_180 ) ;
V_181 = F_3 ( V_179 -> V_181 ) ;
V_70 = F_101 ( V_180 ) - 1 ;
if ( V_10 -> V_35 & V_162 &&
V_70 != ( unsigned int ) - 1 &&
V_180 - V_182 == V_181 ) {
V_77 = V_132 -> V_76 [ V_70 ] . V_77 ;
if ( ! ( V_77 & V_80 ) )
goto V_183;
F_46 ( V_10 , V_163 ,
L_69
L_70 ,
V_70 , V_77 ) ;
V_132 -> V_76 [ V_70 ] . V_77 &= ~ V_80 ;
F_39 ( V_10 , V_69 , V_70 ) ;
return;
}
V_183:
F_46 ( V_10 , V_184 ,
L_71 ) ;
V_132 -> V_185 = V_148 ;
F_84 ( & V_132 -> V_186 ) ;
return;
}
static void F_102 ( struct V_9 * V_10 , int V_69 ,
struct V_130 * V_131 , T_2 V_148 )
{
struct V_98 * V_132 ;
V_132 = V_10 -> V_75 [ V_69 ] ;
if ( F_67 ( V_10 , V_132 , V_131 ) )
return;
V_132 -> V_185 = V_148 ;
F_84 ( & V_132 -> V_186 ) ;
}
static void F_103 ( struct V_9 * V_10 , int V_69 ,
T_2 V_148 )
{
V_10 -> V_75 [ V_69 ] -> V_185 = V_148 ;
F_84 ( & V_10 -> V_176 ) ;
}
static void F_104 ( struct V_9 * V_10 , int V_69 ,
struct V_130 * V_131 )
{
struct V_98 * V_132 ;
F_16 ( V_10 , L_72 ) ;
V_132 = V_10 -> V_75 [ V_69 ] ;
if ( V_132 )
F_67 ( V_10 , V_132 , V_131 ) ;
else
F_32 ( V_10 , L_73
L_74 , V_69 ) ;
}
static void F_105 ( struct V_9 * V_10 ,
struct V_130 * V_131 )
{
if ( ! ( V_10 -> V_35 & V_187 ) ) {
V_10 -> V_188 |= 1 << 6 ;
return;
}
F_46 ( V_10 , V_163 ,
L_75 ,
F_106 ( F_3 ( V_131 -> V_117 ) ) ,
F_107 ( F_3 ( V_131 -> V_117 ) ) ) ;
}
static void F_108 ( struct V_9 * V_10 ,
struct V_130 * V_131 )
{
int V_69 = F_109 ( F_3 ( V_131 -> V_65 ) ) ;
T_3 V_189 ;
T_1 V_190 ;
T_2 V_148 ;
union V_3 * V_58 ;
T_2 V_191 ;
V_189 = F_49 ( V_131 -> V_58 ) ;
V_58 = V_10 -> V_49 -> V_25 ;
V_190 = F_1 ( V_10 -> V_49 -> V_24 ,
V_58 ) ;
if ( V_190 == 0 ) {
V_10 -> V_188 |= 1 << 4 ;
return;
}
if ( V_189 != ( T_3 ) V_190 ) {
V_10 -> V_188 |= 1 << 5 ;
return;
}
F_110 ( V_58 , (struct V_89 * ) V_131 ) ;
V_148 = F_86 ( F_3 ( V_131 -> V_117 ) ) ;
if ( V_148 == V_174 || V_148 == V_169 ) {
if ( F_94 ( V_10 , V_148 ) ) {
F_9 ( V_10 , V_10 -> V_49 ) ;
return;
}
if ( V_10 -> V_49 -> V_25 == V_10 -> V_49 -> V_20 )
return;
}
V_191 = F_111 ( F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ;
switch ( V_191 ) {
case V_192 :
F_95 ( V_10 , V_69 , V_148 ) ;
break;
case V_193 :
F_96 ( V_10 , V_69 ) ;
break;
case V_194 :
F_99 ( V_10 , V_69 , V_131 , V_148 ) ;
break;
case V_195 :
F_102 ( V_10 , V_69 , V_131 , V_148 ) ;
break;
case V_196 :
F_103 ( V_10 , V_69 , V_148 ) ;
break;
case V_197 :
F_47 ( V_69 != F_109 (
F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ) ;
F_65 ( V_10 , V_69 , V_58 , V_131 ) ;
break;
case V_198 :
F_47 ( V_69 != F_109 (
F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ) ;
F_75 ( V_10 , V_69 , V_58 , V_148 ) ;
break;
case V_170 :
break;
case V_199 :
F_47 ( V_69 != F_109 (
F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ) ;
F_80 ( V_10 , V_69 , V_58 , V_148 ) ;
break;
case V_200 :
F_47 ( V_69 != F_109 (
F_3 ( V_58 -> V_30 . V_31 [ 3 ] ) ) ) ;
F_104 ( V_10 , V_69 , V_131 ) ;
break;
case V_201 :
F_105 ( V_10 , V_131 ) ;
break;
default:
V_10 -> V_188 |= 1 << 6 ;
break;
}
F_9 ( V_10 , V_10 -> V_49 ) ;
}
static void F_112 ( struct V_9 * V_10 ,
union V_3 * V_131 )
{
T_2 V_202 ;
V_202 = F_111 ( F_3 ( V_131 -> V_30 . V_31 [ 3 ] ) ) ;
F_16 ( V_10 , L_76 , V_202 ) ;
if ( V_202 == V_203 && ( V_10 -> V_35 & V_187 ) )
F_108 ( V_10 , & V_131 -> V_204 ) ;
}
static unsigned int F_113 ( struct V_118 * V_119 ,
struct V_9 * V_10 , T_2 V_205 )
{
unsigned int V_141 ;
unsigned int V_206 = 0 ;
for ( V_141 = 0 ; V_141 < ( V_205 - 1 ) ; V_141 ++ ) {
T_6 V_207 = V_10 -> V_208 [ V_141 ] ;
if ( V_207 == 0 || V_207 == V_209 )
continue;
if ( ( V_207 == 0x03 ) == ( V_119 -> V_210 == V_211 ) )
V_206 ++ ;
}
return V_206 ;
}
static void F_114 ( struct V_9 * V_10 ,
union V_3 * V_131 )
{
T_2 V_69 ;
struct V_212 * V_213 ;
V_69 = F_109 ( F_3 ( V_131 -> V_30 . V_31 [ 3 ] ) ) ;
if ( ! V_10 -> V_75 [ V_69 ] ) {
F_32 ( V_10 , L_77
L_78 , V_69 ) ;
return;
}
F_16 ( V_10 , L_79 ,
V_69 ) ;
V_213 = V_10 -> V_75 [ V_69 ] -> V_213 ;
if ( V_213 && V_213 -> V_214 )
F_115 ( V_213 -> V_214 , V_213 -> V_215 ) ;
}
static void F_116 ( struct V_9 * V_10 ,
union V_3 * V_131 )
{
struct V_118 * V_119 ;
T_2 V_205 ;
T_2 V_216 , V_217 ;
int V_218 ;
int V_69 ;
unsigned int V_219 ;
T_6 V_220 ;
struct V_221 * V_222 ;
T_4 T_5 * * V_208 ;
bool V_223 = false ;
if ( F_86 ( F_3 ( V_131 -> V_30 . V_31 [ 2 ] ) ) != V_151 ) {
F_32 ( V_10 , L_80 ) ;
V_10 -> V_188 |= 1 << 8 ;
}
V_205 = F_117 ( F_3 ( V_131 -> V_30 . V_31 [ 0 ] ) ) ;
F_16 ( V_10 , L_81 , V_205 ) ;
V_218 = F_118 ( V_10 -> V_224 ) ;
if ( ( V_205 <= 0 ) || ( V_205 > V_218 ) ) {
F_32 ( V_10 , L_82 , V_205 ) ;
F_9 ( V_10 , V_10 -> V_13 ) ;
return;
}
V_220 = V_10 -> V_208 [ V_205 - 1 ] ;
V_119 = F_36 ( V_10 ) ;
if ( ( V_220 == 0x03 ) != ( V_119 -> V_210 == V_211 ) )
V_119 = V_10 -> V_225 ;
if ( V_220 == 0 ) {
F_32 ( V_10 , L_83
L_84 ,
V_205 ) ;
V_223 = true ;
goto V_226;
}
if ( V_220 == V_209 ) {
F_32 ( V_10 , L_85
L_84 ,
V_205 ) ;
V_223 = true ;
goto V_226;
}
V_222 = & V_10 -> V_222 [ F_119 ( V_119 ) ] ;
if ( V_119 -> V_210 == V_211 )
V_208 = V_10 -> V_227 ;
else
V_208 = V_10 -> V_228 ;
V_219 = F_113 ( V_119 , V_10 ,
V_205 ) ;
V_216 = F_18 ( V_208 [ V_219 ] ) ;
if ( V_119 -> V_97 == V_229 ) {
F_16 ( V_10 , L_86 ) ;
F_120 ( V_119 ) ;
}
if ( ( V_216 & V_230 ) && ( V_216 & V_231 ) == V_232 ) {
F_16 ( V_10 , L_87 , V_205 ) ;
V_217 = F_18 ( & V_10 -> V_48 -> V_57 ) ;
if ( ! ( V_217 & V_233 ) ) {
F_32 ( V_10 , L_88 ) ;
goto V_226;
}
if ( F_121 ( V_216 ) ) {
F_16 ( V_10 , L_89 , V_205 ) ;
V_222 -> V_234 |= 1 << V_219 ;
F_122 ( V_10 , V_208 ,
V_219 , V_230 ) ;
F_123 ( V_10 , V_208 , V_219 ,
V_235 ) ;
V_223 = true ;
goto V_226;
} else {
F_16 ( V_10 , L_90 , V_205 ) ;
V_222 -> V_236 [ V_219 ] = V_237 +
F_124 ( 20 ) ;
F_125 ( V_219 , & V_222 -> V_238 ) ;
F_126 ( & V_119 -> V_239 ,
V_222 -> V_236 [ V_219 ] ) ;
}
}
if ( ( V_216 & V_230 ) && ( V_216 & V_231 ) == V_235 &&
F_121 ( V_216 ) ) {
F_16 ( V_10 , L_91 , V_205 ) ;
V_69 = F_127 ( V_119 , V_10 ,
V_219 + 1 ) ;
if ( V_69 && V_10 -> V_75 [ V_69 ] )
F_128 ( V_10 , V_69 ) ;
if ( V_222 -> V_234 & ( 1 << V_219 ) ) {
V_222 -> V_234 &=
~ ( 1 << V_219 ) ;
F_122 ( V_10 , V_208 ,
V_219 , V_230 ) ;
F_115 ( V_119 -> V_127 . V_240 ,
V_219 + 1 ) ;
V_223 = true ;
goto V_226;
}
}
if ( ! F_121 ( V_216 ) &&
F_129 ( V_219 ,
& V_222 -> V_241 ) ) {
F_84 ( & V_222 -> V_242 [ V_219 ] ) ;
V_223 = true ;
goto V_226;
}
if ( V_119 -> V_210 != V_211 )
F_122 ( V_10 , V_208 , V_219 ,
V_230 ) ;
V_226:
F_9 ( V_10 , V_10 -> V_13 ) ;
if ( V_223 )
return;
F_16 ( V_10 , L_92 , V_243 ) ;
F_125 ( V_244 , & V_119 -> V_65 ) ;
F_61 ( & V_10 -> V_66 ) ;
F_130 ( V_119 ) ;
F_64 ( & V_10 -> V_66 ) ;
}
struct V_1 * F_131 ( struct V_1 * V_87 ,
union V_3 * V_245 ,
union V_3 * V_246 ,
T_1 V_247 )
{
T_1 V_248 ;
T_1 V_249 ;
T_1 V_250 ;
struct V_1 * V_88 ;
V_248 = F_1 ( V_87 , V_245 ) ;
V_88 = V_87 ;
do {
if ( V_248 == 0 )
return NULL ;
V_249 = F_1 ( V_88 ,
& V_88 -> V_6 [ V_7 - 1 ] ) ;
V_250 = F_1 ( V_88 , V_246 ) ;
if ( V_250 > 0 ) {
if ( V_248 <= V_250 ) {
if ( V_247 >= V_248 && V_247 <= V_250 )
return V_88 ;
} else {
if ( ( V_247 >= V_248 &&
V_247 <= V_249 ) ||
( V_247 >= V_88 -> V_8 &&
V_247 <= V_250 ) )
return V_88 ;
}
return NULL ;
} else {
if ( V_247 >= V_248 && V_247 <= V_249 )
return V_88 ;
}
V_88 = V_88 -> V_14 ;
V_248 = F_1 ( V_88 , & V_88 -> V_6 [ 0 ] ) ;
} while ( V_88 != V_87 );
return NULL ;
}
static void F_132 ( struct V_9 * V_10 ,
unsigned int V_69 , unsigned int V_70 ,
unsigned int V_71 ,
struct V_94 * V_251 , union V_3 * V_252 )
{
struct V_73 * V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
V_74 -> V_77 |= V_80 ;
V_74 -> V_137 = V_251 ;
V_74 -> V_106 = V_252 ;
V_74 -> V_253 = V_71 ;
F_133 ( V_10 , V_69 , V_70 ) ;
F_134 ( V_10 , V_251 -> V_91 -> V_92 , V_70 ) ;
V_74 -> V_137 = NULL ;
V_74 -> V_106 = NULL ;
V_74 -> V_253 = 0 ;
F_15 ( V_10 ) ;
}
static int F_135 ( struct V_9 * V_10 ,
struct V_100 * V_101 ,
unsigned int V_254 )
{
if ( V_254 == V_255 ||
V_254 == V_256 ||
V_254 == V_257 )
if ( ( V_101 -> V_155 & F_12 ( V_156 ) ) ==
F_12 ( V_258 ) )
return 1 ;
return 0 ;
}
int F_136 ( struct V_9 * V_10 , unsigned int V_254 )
{
if ( V_254 >= 224 && V_254 <= 255 ) {
F_16 ( V_10 , L_93 ,
V_254 ) ;
F_16 ( V_10 , L_94 ) ;
return 1 ;
}
return 0 ;
}
static int F_137 ( struct V_9 * V_10 , struct V_94 * V_251 ,
union V_3 * V_252 , struct V_259 * V_131 ,
struct V_73 * V_74 , int * V_117 , bool V_260 )
{
struct V_98 * V_261 ;
struct V_11 * V_99 ;
unsigned int V_69 ;
int V_70 ;
struct V_91 * V_91 = NULL ;
struct V_100 * V_101 ;
int V_47 = 0 ;
struct V_120 * V_120 ;
T_2 V_254 ;
V_69 = F_109 ( F_3 ( V_131 -> V_65 ) ) ;
V_261 = V_10 -> V_75 [ V_69 ] ;
V_70 = F_138 ( F_3 ( V_131 -> V_65 ) ) - 1 ;
V_99 = F_139 ( V_74 , F_49 ( V_131 -> V_262 ) ) ;
V_101 = F_48 ( V_10 , V_261 -> V_107 , V_70 ) ;
V_254 = F_86 ( F_3 ( V_131 -> V_263 ) ) ;
if ( V_260 )
goto V_264;
if ( V_254 == V_265 ||
V_254 == V_266 ) {
V_74 -> V_137 = V_251 ;
V_74 -> V_106 = V_252 ;
return 0 ;
} else {
if ( V_254 == V_267 ) {
V_74 -> V_137 = V_251 ;
V_74 -> V_106 = V_252 ;
V_74 -> V_253 = V_99 -> V_71 ;
} else if ( F_135 ( V_10 ,
V_101 , V_254 ) ) {
F_132 ( V_10 ,
V_69 , V_70 , V_99 -> V_71 ,
V_251 , V_252 ) ;
} else {
while ( V_99 -> V_25 != V_251 -> F_4 )
F_9 ( V_10 , V_99 ) ;
F_9 ( V_10 , V_99 ) ;
}
V_264:
V_91 = V_251 -> V_91 ;
V_120 = V_91 -> V_121 ;
if ( V_91 -> V_268 > V_91 -> V_269 ) {
F_32 ( V_10 , L_95
L_96
L_97 ,
V_91 -> V_269 ,
V_91 -> V_268 ) ;
V_91 -> V_268 = 0 ;
if ( V_251 -> V_91 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
}
F_71 ( & V_251 -> V_82 ) ;
if ( ! F_40 ( & V_251 -> V_136 ) )
F_71 ( & V_251 -> V_136 ) ;
V_120 -> V_122 ++ ;
if ( V_120 -> V_122 == V_120 -> V_124 ) {
V_47 = 1 ;
if ( F_58 ( V_91 -> V_125 ) == V_126 ) {
F_36 ( V_10 ) -> V_127 . V_128 -- ;
if ( F_36 ( V_10 ) -> V_127 . V_128
== 0 ) {
if ( V_10 -> V_35 & V_129 )
F_59 () ;
}
}
}
}
return V_47 ;
}
static int F_140 ( struct V_9 * V_10 , struct V_94 * V_251 ,
union V_3 * V_252 , struct V_259 * V_131 ,
struct V_73 * V_74 , int * V_117 )
{
struct V_98 * V_261 ;
struct V_11 * V_99 ;
unsigned int V_69 ;
int V_70 ;
struct V_100 * V_101 ;
T_2 V_254 ;
V_69 = F_109 ( F_3 ( V_131 -> V_65 ) ) ;
V_261 = V_10 -> V_75 [ V_69 ] ;
V_70 = F_138 ( F_3 ( V_131 -> V_65 ) ) - 1 ;
V_99 = F_139 ( V_74 , F_49 ( V_131 -> V_262 ) ) ;
V_101 = F_48 ( V_10 , V_261 -> V_107 , V_70 ) ;
V_254 = F_86 ( F_3 ( V_131 -> V_263 ) ) ;
switch ( V_254 ) {
case V_151 :
if ( V_252 == V_99 -> V_25 ) {
F_32 ( V_10 , L_98
L_99 ) ;
* V_117 = - V_55 ;
} else if ( V_252 != V_251 -> F_4 ) {
F_32 ( V_10 , L_100
L_99 ) ;
* V_117 = - V_55 ;
} else {
* V_117 = 0 ;
}
break;
case V_273 :
if ( V_251 -> V_91 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
break;
case V_265 :
case V_266 :
return F_137 ( V_10 , V_251 , V_252 , V_131 , V_74 , V_117 , false ) ;
default:
if ( ! F_135 ( V_10 ,
V_101 , V_254 ) )
break;
F_16 ( V_10 , L_101
L_102 ,
V_254 , V_70 ) ;
case V_267 :
if ( V_252 != V_99 -> V_25 &&
V_252 != V_251 -> F_4 )
V_251 -> V_91 -> V_268 =
V_251 -> V_91 -> V_269 -
F_141 ( F_3 ( V_131 -> V_263 ) ) ;
else
V_251 -> V_91 -> V_268 = 0 ;
F_132 ( V_10 ,
V_69 , V_70 , 0 , V_251 , V_252 ) ;
return F_137 ( V_10 , V_251 , V_252 , V_131 , V_74 , V_117 , true ) ;
}
if ( V_252 != V_99 -> V_25 ) {
if ( V_252 == V_251 -> F_4 ) {
if ( V_251 -> V_91 -> V_268 != 0 ) {
if ( ( * V_117 == - V_274 || * V_117 == 0 ) &&
( V_251 -> V_91 -> V_270
& V_271 ) )
* V_117 = - V_272 ;
} else {
V_251 -> V_91 -> V_268 =
V_251 -> V_91 -> V_269 ;
}
} else {
V_251 -> V_91 -> V_268 =
V_251 -> V_91 -> V_269 -
F_141 ( F_3 ( V_131 -> V_263 ) ) ;
F_16 ( V_10 , L_103
L_104 ) ;
return 0 ;
}
}
return F_137 ( V_10 , V_251 , V_252 , V_131 , V_74 , V_117 , false ) ;
}
static int F_142 ( struct V_9 * V_10 , struct V_94 * V_251 ,
union V_3 * V_252 , struct V_259 * V_131 ,
struct V_73 * V_74 , int * V_117 )
{
struct V_11 * V_99 ;
struct V_120 * V_120 ;
int V_275 ;
int V_276 = 0 ;
union V_3 * V_111 ;
struct V_1 * V_88 ;
struct V_277 * V_278 ;
T_2 V_254 ;
bool V_279 = false ;
V_99 = F_139 ( V_74 , F_49 ( V_131 -> V_262 ) ) ;
V_254 = F_86 ( F_3 ( V_131 -> V_263 ) ) ;
V_120 = V_251 -> V_91 -> V_121 ;
V_275 = V_120 -> V_122 ;
V_278 = & V_251 -> V_91 -> V_280 [ V_275 ] ;
switch ( V_254 ) {
case V_151 :
if ( F_141 ( F_3 ( V_131 -> V_263 ) ) == 0 ) {
V_278 -> V_117 = 0 ;
break;
}
if ( ( V_10 -> V_35 & V_281 ) )
V_254 = V_273 ;
case V_273 :
V_278 -> V_117 = V_251 -> V_91 -> V_270 & V_271 ?
- V_272 : 0 ;
break;
case V_282 :
V_278 -> V_117 = - V_283 ;
V_279 = true ;
break;
case V_284 :
case V_256 :
V_278 -> V_117 = - V_285 ;
V_279 = true ;
break;
case V_286 :
case V_267 :
case V_255 :
V_278 -> V_117 = - V_287 ;
V_279 = true ;
break;
case V_266 :
case V_265 :
break;
default:
V_278 -> V_117 = - 1 ;
break;
}
if ( V_254 == V_151 || V_279 ) {
V_278 -> V_268 = V_278 -> V_124 ;
V_251 -> V_91 -> V_268 += V_278 -> V_124 ;
} else {
for ( V_111 = V_99 -> V_25 ,
V_88 = V_99 -> V_24 ; V_111 != V_252 ;
F_8 ( V_10 , V_99 , & V_88 , & V_111 ) ) {
if ( ! F_143 ( V_111 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_111 -> V_30 . V_31 [ 3 ] ) )
V_276 += F_144 ( F_3 ( V_111 -> V_30 . V_31 [ 2 ] ) ) ;
}
V_276 += F_144 ( F_3 ( V_111 -> V_30 . V_31 [ 2 ] ) ) -
F_141 ( F_3 ( V_131 -> V_263 ) ) ;
if ( V_254 != V_265 ) {
V_278 -> V_268 = V_276 ;
V_251 -> V_91 -> V_268 += V_276 ;
}
}
return F_137 ( V_10 , V_251 , V_252 , V_131 , V_74 , V_117 , false ) ;
}
static int F_145 ( struct V_9 * V_10 , struct V_94 * V_251 ,
struct V_259 * V_131 ,
struct V_73 * V_74 , int * V_117 )
{
struct V_11 * V_99 ;
struct V_120 * V_120 ;
struct V_277 * V_278 ;
int V_275 ;
V_99 = F_139 ( V_74 , F_49 ( V_131 -> V_262 ) ) ;
V_120 = V_251 -> V_91 -> V_121 ;
V_275 = V_120 -> V_122 ;
V_278 = & V_251 -> V_91 -> V_280 [ V_275 ] ;
V_278 -> V_117 = - V_288 ;
V_278 -> V_268 = 0 ;
while ( V_99 -> V_25 != V_251 -> F_4 )
F_9 ( V_10 , V_99 ) ;
F_9 ( V_10 , V_99 ) ;
return F_137 ( V_10 , V_251 , NULL , V_131 , V_74 , V_117 , true ) ;
}
static int F_146 ( struct V_9 * V_10 , struct V_94 * V_251 ,
union V_3 * V_252 , struct V_259 * V_131 ,
struct V_73 * V_74 , int * V_117 )
{
struct V_11 * V_99 ;
union V_3 * V_111 ;
struct V_1 * V_88 ;
T_2 V_254 ;
V_99 = F_139 ( V_74 , F_49 ( V_131 -> V_262 ) ) ;
V_254 = F_86 ( F_3 ( V_131 -> V_263 ) ) ;
switch ( V_254 ) {
case V_151 :
if ( V_252 != V_251 -> F_4 ||
F_141 ( F_3 ( V_131 -> V_263 ) ) != 0 ) {
F_32 ( V_10 , L_105
L_106 ) ;
if ( V_251 -> V_91 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
if ( ( V_10 -> V_35 & V_281 ) )
V_254 = V_273 ;
} else {
* V_117 = 0 ;
}
break;
case V_273 :
if ( V_251 -> V_91 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
break;
default:
break;
}
if ( V_254 == V_273 )
F_16 ( V_10 , L_107
L_108 ,
V_251 -> V_91 -> V_74 -> V_93 . V_289 ,
V_251 -> V_91 -> V_269 ,
F_141 ( F_3 ( V_131 -> V_263 ) ) ) ;
if ( V_252 == V_251 -> F_4 ) {
if ( F_141 ( F_3 ( V_131 -> V_263 ) ) != 0 ) {
V_251 -> V_91 -> V_268 =
V_251 -> V_91 -> V_269 -
F_141 ( F_3 ( V_131 -> V_263 ) ) ;
if ( V_251 -> V_91 -> V_269 <
V_251 -> V_91 -> V_268 ) {
F_32 ( V_10 , L_109
L_110 ,
F_141 ( F_3 ( V_131 -> V_263 ) ) ) ;
V_251 -> V_91 -> V_268 = 0 ;
if ( V_251 -> V_91 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
}
if ( * V_117 == - V_274 ) {
if ( V_251 -> V_91 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
}
} else {
V_251 -> V_91 -> V_268 =
V_251 -> V_91 -> V_269 ;
if ( * V_117 == - V_272 )
* V_117 = 0 ;
}
} else {
V_251 -> V_91 -> V_268 = 0 ;
for ( V_111 = V_99 -> V_25 , V_88 = V_99 -> V_24 ;
V_111 != V_252 ;
F_8 ( V_10 , V_99 , & V_88 , & V_111 ) ) {
if ( ! F_143 ( V_111 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_111 -> V_30 . V_31 [ 3 ] ) )
V_251 -> V_91 -> V_268 +=
F_144 ( F_3 ( V_111 -> V_30 . V_31 [ 2 ] ) ) ;
}
if ( V_254 != V_265 )
V_251 -> V_91 -> V_268 +=
F_144 ( F_3 ( V_111 -> V_30 . V_31 [ 2 ] ) ) -
F_141 ( F_3 ( V_131 -> V_263 ) ) ;
}
return F_137 ( V_10 , V_251 , V_252 , V_131 , V_74 , V_117 , false ) ;
}
static int F_147 ( struct V_9 * V_10 ,
struct V_259 * V_131 )
__releases( &xhci->lock
static int F_148 ( struct V_9 * V_10 )
{
union V_3 * V_131 ;
int V_290 = 1 ;
int V_47 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_25 ) {
V_10 -> V_188 |= 1 << 1 ;
return 0 ;
}
V_131 = V_10 -> V_13 -> V_25 ;
if ( ( F_3 ( V_131 -> V_204 . V_65 ) & V_37 ) !=
V_10 -> V_13 -> V_27 ) {
V_10 -> V_188 |= 1 << 2 ;
return 0 ;
}
F_149 () ;
switch ( ( F_3 ( V_131 -> V_204 . V_65 ) & V_291 ) ) {
case F_51 ( V_292 ) :
F_108 ( V_10 , & V_131 -> V_204 ) ;
break;
case F_51 ( V_293 ) :
F_116 ( V_10 , V_131 ) ;
V_290 = 0 ;
break;
case F_51 ( V_294 ) :
V_47 = F_147 ( V_10 , & V_131 -> V_295 ) ;
if ( V_47 < 0 )
V_10 -> V_188 |= 1 << 9 ;
else
V_290 = 0 ;
break;
case F_51 ( V_296 ) :
F_114 ( V_10 , V_131 ) ;
break;
default:
if ( ( F_3 ( V_131 -> V_204 . V_65 ) & V_291 ) >=
F_51 ( 48 ) )
F_112 ( V_10 , V_131 ) ;
else
V_10 -> V_188 |= 1 << 3 ;
}
if ( V_10 -> V_53 & V_54 ) {
F_16 ( V_10 , L_111
L_112 ) ;
return 0 ;
}
if ( V_290 )
F_9 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_150 ( struct V_118 * V_119 )
{
struct V_9 * V_10 = F_151 ( V_119 ) ;
T_2 V_117 ;
T_3 V_46 ;
union V_3 * V_297 ;
T_1 V_108 ;
F_64 ( & V_10 -> V_66 ) ;
V_117 = F_18 ( & V_10 -> V_48 -> V_117 ) ;
if ( V_117 == 0xffffffff )
goto V_298;
if ( ! ( V_117 & V_299 ) ) {
F_61 ( & V_10 -> V_66 ) ;
return V_300 ;
}
if ( V_117 & V_301 ) {
F_32 ( V_10 , L_113 ) ;
F_25 ( V_10 ) ;
V_298:
F_61 ( & V_10 -> V_66 ) ;
return - V_55 ;
}
V_117 |= V_299 ;
F_17 ( V_117 , & V_10 -> V_48 -> V_117 ) ;
if ( V_119 -> V_302 ) {
T_2 V_303 ;
V_303 = F_18 ( & V_10 -> V_304 -> V_303 ) ;
V_303 |= V_305 ;
F_17 ( V_303 , & V_10 -> V_304 -> V_303 ) ;
}
if ( V_10 -> V_53 & V_54 ) {
F_16 ( V_10 , L_114
L_115 ) ;
V_46 = F_20 ( V_10 , & V_10 -> V_304 -> V_306 ) ;
F_21 ( V_10 , V_46 | V_307 ,
& V_10 -> V_304 -> V_306 ) ;
F_61 ( & V_10 -> V_66 ) ;
return V_308 ;
}
V_297 = V_10 -> V_13 -> V_25 ;
while ( F_148 ( V_10 ) > 0 ) {}
V_46 = F_20 ( V_10 , & V_10 -> V_304 -> V_306 ) ;
if ( V_297 != V_10 -> V_13 -> V_25 ) {
V_108 = F_1 ( V_10 -> V_13 -> V_24 ,
V_10 -> V_13 -> V_25 ) ;
if ( V_108 == 0 )
F_32 ( V_10 , L_116
L_117 ) ;
V_46 &= V_309 ;
V_46 |= ( ( T_3 ) V_108 & ( T_3 ) ~ V_309 ) ;
}
V_46 |= V_307 ;
F_21 ( V_10 , V_46 , & V_10 -> V_304 -> V_306 ) ;
F_61 ( & V_10 -> V_66 ) ;
return V_308 ;
}
T_7 F_152 ( int V_302 , void * V_119 )
{
return F_150 ( V_119 ) ;
}
static void F_153 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_28 ,
T_2 V_310 , T_2 V_311 , T_2 V_312 , T_2 V_313 )
{
struct V_89 * V_4 ;
V_4 = & V_12 -> V_20 -> V_30 ;
V_4 -> V_31 [ 0 ] = F_12 ( V_310 ) ;
V_4 -> V_31 [ 1 ] = F_12 ( V_311 ) ;
V_4 -> V_31 [ 2 ] = F_12 ( V_312 ) ;
V_4 -> V_31 [ 3 ] = F_12 ( V_313 ) ;
F_10 ( V_10 , V_12 , V_28 ) ;
}
static int F_154 ( struct V_9 * V_10 , struct V_11 * V_99 ,
T_2 V_77 , unsigned int V_38 , T_8 V_314 )
{
unsigned int V_315 ;
switch ( V_77 ) {
case V_316 :
F_32 ( V_10 , L_118 ) ;
return - V_317 ;
case V_318 :
F_32 ( V_10 , L_119 ) ;
return - V_319 ;
case V_258 :
F_16 ( V_10 , L_120 ) ;
case V_320 :
case V_321 :
break;
default:
F_23 ( V_10 , L_121 ) ;
return - V_319 ;
}
while ( 1 ) {
if ( F_14 ( V_10 , V_99 , V_38 ) )
break;
if ( V_99 == V_10 -> V_49 ) {
F_23 ( V_10 , L_122 ) ;
return - V_62 ;
}
F_46 ( V_10 , V_322 ,
L_123 ) ;
V_315 = V_38 - V_99 -> V_26 ;
if ( F_155 ( V_10 , V_99 , V_315 ,
V_314 ) ) {
F_23 ( V_10 , L_124 ) ;
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
static int F_156 ( struct V_9 * V_10 ,
struct V_98 * V_261 ,
unsigned int V_70 ,
unsigned int V_71 ,
unsigned int V_38 ,
struct V_91 * V_91 ,
unsigned int V_323 ,
T_8 V_314 )
{
int V_47 ;
struct V_120 * V_120 ;
struct V_94 * V_251 ;
struct V_11 * V_99 ;
struct V_100 * V_101 = F_48 ( V_10 , V_261 -> V_107 , V_70 ) ;
V_99 = F_77 ( V_261 , V_70 , V_71 ) ;
if ( ! V_99 ) {
F_16 ( V_10 , L_125 ,
V_71 ) ;
return - V_319 ;
}
V_47 = F_154 ( V_10 , V_99 ,
F_3 ( V_101 -> V_155 ) & V_156 ,
V_38 , V_314 ) ;
if ( V_47 )
return V_47 ;
V_120 = V_91 -> V_121 ;
V_251 = V_120 -> V_251 [ V_323 ] ;
F_28 ( & V_251 -> V_82 ) ;
F_28 ( & V_251 -> V_136 ) ;
if ( V_323 == 0 ) {
V_47 = F_157 ( F_57 ( V_91 -> V_92 -> V_123 ) , V_91 ) ;
if ( F_33 ( V_47 ) )
return V_47 ;
}
V_251 -> V_91 = V_91 ;
F_29 ( & V_251 -> V_82 , & V_99 -> V_82 ) ;
V_251 -> V_87 = V_99 -> V_21 ;
V_251 -> V_112 = V_99 -> V_20 ;
V_120 -> V_251 [ V_323 ] = V_251 ;
return 0 ;
}
static unsigned int F_158 ( struct V_9 * V_10 , struct V_91 * V_91 )
{
int V_324 , V_38 , V_325 , V_216 , V_141 ;
struct V_326 * V_327 ;
V_327 = NULL ;
V_324 = V_91 -> V_328 ;
V_216 = V_91 -> V_269 ;
V_38 = 0 ;
F_159 (urb->sg, sg, num_sgs, i) {
unsigned int V_276 = F_160 ( V_327 ) ;
V_325 = V_329 -
( F_161 ( V_327 ) & ( V_329 - 1 ) ) ;
V_325 &= V_329 - 1 ;
if ( V_325 != 0 )
V_38 ++ ;
while ( V_325 < F_160 ( V_327 ) && V_325 < V_216 ) {
V_38 ++ ;
V_325 += V_329 ;
}
V_276 = F_162 ( int , V_276 , V_216 ) ;
V_216 -= V_276 ;
if ( V_216 == 0 )
break;
}
return V_38 ;
}
static void F_163 ( struct V_91 * V_91 , int V_38 , int V_325 )
{
if ( V_38 != 0 )
F_164 ( & V_91 -> V_92 -> V_92 , L_126
L_127 , V_243 ,
V_91 -> V_74 -> V_93 . V_289 , V_38 ) ;
if ( V_325 != V_91 -> V_269 )
F_164 ( & V_91 -> V_92 -> V_92 , L_128
L_129 ,
V_243 ,
V_91 -> V_74 -> V_93 . V_289 ,
V_325 , V_325 ,
V_91 -> V_269 ,
V_91 -> V_269 ) ;
}
static void F_165 ( struct V_9 * V_10 , int V_69 ,
unsigned int V_70 , unsigned int V_71 , int V_330 ,
struct V_89 * V_245 )
{
F_13 () ;
if ( V_330 )
V_245 -> V_31 [ 3 ] |= F_12 ( V_330 ) ;
else
V_245 -> V_31 [ 3 ] &= F_12 ( ~ V_37 ) ;
F_37 ( V_10 , V_69 , V_70 , V_71 ) ;
}
int F_166 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_100 * V_101 = F_48 ( V_10 ,
V_10 -> V_75 [ V_69 ] -> V_107 , V_70 ) ;
int V_331 ;
int V_332 ;
V_331 = F_167 ( F_3 ( V_101 -> V_155 ) ) ;
V_332 = V_91 -> V_333 ;
if ( V_91 -> V_92 -> V_210 == V_334 ||
V_91 -> V_92 -> V_210 == V_335 )
V_332 *= 8 ;
if ( V_331 != V_332 ) {
F_168 ( & V_91 -> V_92 -> V_92 ,
L_130 ,
V_332 , V_332 == 1 ? L_131 : L_132 ,
V_331 , V_331 == 1 ? L_131 : L_132 ) ;
V_91 -> V_333 = V_331 ;
if ( V_91 -> V_92 -> V_210 == V_334 ||
V_91 -> V_92 -> V_210 == V_335 )
V_91 -> V_333 /= 8 ;
}
return F_169 ( V_10 , V_314 , V_91 , V_69 , V_70 ) ;
}
static T_2 F_170 ( unsigned int V_336 )
{
T_2 V_337 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_336 >> 10 ) >= V_337 )
return V_337 << 17 ;
else
return ( V_336 >> 10 ) << 17 ;
}
static T_2 F_171 ( int V_325 , int V_338 ,
unsigned int V_339 , struct V_91 * V_91 ,
unsigned int V_340 )
{
int V_341 ;
if ( V_340 == 0 || ( V_325 == 0 && V_338 == 0 ) )
return 0 ;
V_341 = ( V_325 + V_338 ) /
F_172 ( F_173 ( & V_91 -> V_74 -> V_93 ) ) ;
if ( ( V_339 - V_341 ) > 31 )
return 31 << 17 ;
return ( V_339 - V_341 ) << 17 ;
}
static int F_174 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_11 * V_99 ;
unsigned int V_38 ;
struct V_120 * V_120 ;
struct V_94 * V_251 ;
struct V_326 * V_327 ;
int V_324 ;
int V_338 , V_342 , V_325 ;
unsigned int V_339 ;
bool V_112 ;
T_3 V_102 ;
bool V_28 ;
struct V_89 * V_245 ;
int V_330 ;
V_99 = F_43 ( V_10 , V_91 ) ;
if ( ! V_99 )
return - V_319 ;
V_38 = F_158 ( V_10 , V_91 ) ;
V_324 = V_91 -> V_328 ;
V_339 = F_175 ( V_91 -> V_269 ,
F_173 ( & V_91 -> V_74 -> V_93 ) ) ;
V_338 = F_156 ( V_10 , V_10 -> V_75 [ V_69 ] ,
V_70 , V_91 -> V_71 ,
V_38 , V_91 , 0 , V_314 ) ;
if ( V_338 < 0 )
return V_338 ;
V_120 = V_91 -> V_121 ;
V_251 = V_120 -> V_251 [ 0 ] ;
V_245 = & V_99 -> V_20 -> V_30 ;
V_330 = V_99 -> V_27 ;
V_325 = 0 ;
V_327 = V_91 -> V_327 ;
V_102 = ( T_3 ) F_161 ( V_327 ) ;
V_342 = F_160 ( V_327 ) ;
V_338 = V_329 - ( V_102 & ( V_329 - 1 ) ) ;
V_338 = F_162 ( int , V_338 , V_342 ) ;
if ( V_338 > V_91 -> V_269 )
V_338 = V_91 -> V_269 ;
V_112 = true ;
do {
T_2 V_31 = 0 ;
T_2 V_343 = 0 ;
T_2 V_336 = 0 ;
if ( V_112 ) {
V_112 = false ;
if ( V_330 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_99 -> V_27 ;
if ( V_38 > 1 ) {
V_31 |= V_32 ;
} else {
V_251 -> F_4 = V_99 -> V_20 ;
V_31 |= V_344 ;
}
if ( F_176 ( V_91 ) )
V_31 |= V_345 ;
if ( V_329 -
( V_102 & ( V_329 - 1 ) ) < V_338 ) {
F_32 ( V_10 , L_133 ) ;
F_16 ( V_10 , L_134 ,
( unsigned int ) ( V_102 + V_329 ) & ~ ( V_329 - 1 ) ,
( unsigned int ) V_102 + V_338 ) ;
}
if ( V_10 -> V_346 < 0x100 ) {
V_336 = F_170 (
V_91 -> V_269 -
V_325 ) ;
} else {
V_336 = F_171 ( V_325 ,
V_338 , V_339 , V_91 ,
V_38 - 1 ) ;
}
V_343 = F_144 ( V_338 ) |
V_336 |
F_177 ( 0 ) ;
if ( V_38 > 1 )
V_28 = true ;
else
V_28 = false ;
F_153 ( V_10 , V_99 , V_28 ,
F_178 ( V_102 ) ,
F_179 ( V_102 ) ,
V_343 ,
V_31 | F_51 ( V_347 ) ) ;
-- V_38 ;
V_325 += V_338 ;
V_342 -= V_338 ;
if ( V_342 == 0 ) {
-- V_324 ;
if ( V_324 == 0 )
break;
V_327 = F_180 ( V_327 ) ;
V_102 = ( T_3 ) F_161 ( V_327 ) ;
V_342 = F_160 ( V_327 ) ;
} else {
V_102 += V_338 ;
}
V_338 = V_329 -
( V_102 & ( V_329 - 1 ) ) ;
V_338 = F_162 ( int , V_338 , V_342 ) ;
if ( V_325 + V_338 > V_91 -> V_269 )
V_338 =
V_91 -> V_269 - V_325 ;
} while ( V_325 < V_91 -> V_269 );
F_163 ( V_91 , V_38 , V_325 ) ;
F_165 ( V_10 , V_69 , V_70 , V_91 -> V_71 ,
V_330 , V_245 ) ;
return 0 ;
}
int F_169 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_11 * V_99 ;
struct V_120 * V_120 ;
struct V_94 * V_251 ;
int V_38 ;
struct V_89 * V_245 ;
bool V_112 ;
bool V_28 ;
int V_330 ;
T_2 V_31 , V_343 ;
int V_325 , V_338 , V_47 ;
unsigned int V_339 ;
T_3 V_102 ;
if ( V_91 -> V_324 )
return F_174 ( V_10 , V_314 , V_91 , V_69 , V_70 ) ;
V_99 = F_43 ( V_10 , V_91 ) ;
if ( ! V_99 )
return - V_319 ;
V_38 = 0 ;
V_325 = V_329 -
( V_91 -> V_348 & ( V_329 - 1 ) ) ;
V_325 &= V_329 - 1 ;
if ( V_325 != 0 || V_91 -> V_269 == 0 )
V_38 ++ ;
while ( V_325 < V_91 -> V_269 ) {
V_38 ++ ;
V_325 += V_329 ;
}
V_47 = F_156 ( V_10 , V_10 -> V_75 [ V_69 ] ,
V_70 , V_91 -> V_71 ,
V_38 , V_91 , 0 , V_314 ) ;
if ( V_47 < 0 )
return V_47 ;
V_120 = V_91 -> V_121 ;
V_251 = V_120 -> V_251 [ 0 ] ;
V_245 = & V_99 -> V_20 -> V_30 ;
V_330 = V_99 -> V_27 ;
V_325 = 0 ;
V_339 = F_175 ( V_91 -> V_269 ,
F_173 ( & V_91 -> V_74 -> V_93 ) ) ;
V_102 = ( T_3 ) V_91 -> V_348 ;
V_338 = V_329 -
( V_91 -> V_348 & ( V_329 - 1 ) ) ;
if ( V_338 > V_91 -> V_269 )
V_338 = V_91 -> V_269 ;
V_112 = true ;
do {
T_2 V_336 = 0 ;
V_31 = 0 ;
if ( V_112 ) {
V_112 = false ;
if ( V_330 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_99 -> V_27 ;
if ( V_38 > 1 ) {
V_31 |= V_32 ;
} else {
V_251 -> F_4 = V_99 -> V_20 ;
V_31 |= V_344 ;
}
if ( F_176 ( V_91 ) )
V_31 |= V_345 ;
if ( V_10 -> V_346 < 0x100 ) {
V_336 = F_170 (
V_91 -> V_269 -
V_325 ) ;
} else {
V_336 = F_171 ( V_325 ,
V_338 , V_339 , V_91 ,
V_38 - 1 ) ;
}
V_343 = F_144 ( V_338 ) |
V_336 |
F_177 ( 0 ) ;
if ( V_38 > 1 )
V_28 = true ;
else
V_28 = false ;
F_153 ( V_10 , V_99 , V_28 ,
F_178 ( V_102 ) ,
F_179 ( V_102 ) ,
V_343 ,
V_31 | F_51 ( V_347 ) ) ;
-- V_38 ;
V_325 += V_338 ;
V_102 += V_338 ;
V_338 = V_91 -> V_269 - V_325 ;
if ( V_338 > V_329 )
V_338 = V_329 ;
} while ( V_325 < V_91 -> V_269 );
F_163 ( V_91 , V_38 , V_325 ) ;
F_165 ( V_10 , V_69 , V_70 , V_91 -> V_71 ,
V_330 , V_245 ) ;
return 0 ;
}
int F_181 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_11 * V_99 ;
int V_38 ;
int V_47 ;
struct V_349 * V_350 ;
struct V_89 * V_245 ;
int V_330 ;
T_2 V_31 , V_343 ;
struct V_120 * V_120 ;
struct V_94 * V_251 ;
V_99 = F_43 ( V_10 , V_91 ) ;
if ( ! V_99 )
return - V_319 ;
if ( ! V_91 -> V_351 )
return - V_319 ;
V_38 = 2 ;
if ( V_91 -> V_269 > 0 )
V_38 ++ ;
V_47 = F_156 ( V_10 , V_10 -> V_75 [ V_69 ] ,
V_70 , V_91 -> V_71 ,
V_38 , V_91 , 0 , V_314 ) ;
if ( V_47 < 0 )
return V_47 ;
V_120 = V_91 -> V_121 ;
V_251 = V_120 -> V_251 [ 0 ] ;
V_245 = & V_99 -> V_20 -> V_30 ;
V_330 = V_99 -> V_27 ;
V_350 = (struct V_349 * ) V_91 -> V_351 ;
V_31 = 0 ;
V_31 |= V_352 | F_51 ( V_353 ) ;
if ( V_330 == 0 )
V_31 |= 0x1 ;
if ( V_10 -> V_346 == 0x100 ) {
if ( V_91 -> V_269 > 0 ) {
if ( V_350 -> V_354 & V_355 )
V_31 |= F_182 ( V_356 ) ;
else
V_31 |= F_182 ( V_357 ) ;
}
}
F_153 ( V_10 , V_99 , true ,
V_350 -> V_354 | V_350 -> V_358 << 8 | F_183 ( V_350 -> V_359 ) << 16 ,
F_183 ( V_350 -> V_360 ) | F_183 ( V_350 -> V_361 ) << 16 ,
F_144 ( 8 ) | F_177 ( 0 ) ,
V_31 ) ;
if ( F_176 ( V_91 ) )
V_31 = V_345 | F_51 ( V_362 ) ;
else
V_31 = F_51 ( V_362 ) ;
V_343 = F_144 ( V_91 -> V_269 ) |
F_170 ( V_91 -> V_269 ) |
F_177 ( 0 ) ;
if ( V_91 -> V_269 > 0 ) {
if ( V_350 -> V_354 & V_355 )
V_31 |= V_363 ;
F_153 ( V_10 , V_99 , true ,
F_178 ( V_91 -> V_348 ) ,
F_179 ( V_91 -> V_348 ) ,
V_343 ,
V_31 | V_99 -> V_27 ) ;
}
V_251 -> F_4 = V_99 -> V_20 ;
if ( V_91 -> V_269 > 0 && V_350 -> V_354 & V_355 )
V_31 = 0 ;
else
V_31 = V_363 ;
F_153 ( V_10 , V_99 , false ,
0 ,
0 ,
F_177 ( 0 ) ,
V_31 | V_344 | F_51 ( V_364 ) | V_99 -> V_27 ) ;
F_165 ( V_10 , V_69 , V_70 , 0 ,
V_330 , V_245 ) ;
return 0 ;
}
static int F_184 ( struct V_9 * V_10 ,
struct V_91 * V_91 , int V_141 )
{
int V_38 = 0 ;
T_3 V_102 , V_365 ;
V_102 = ( T_3 ) ( V_91 -> V_348 + V_91 -> V_280 [ V_141 ] . V_366 ) ;
V_365 = V_91 -> V_280 [ V_141 ] . V_124 ;
V_38 = F_175 ( V_365 + ( V_102 & ( V_329 - 1 ) ) ,
V_329 ) ;
if ( V_38 == 0 )
V_38 ++ ;
return V_38 ;
}
static unsigned int F_185 ( struct V_9 * V_10 ,
struct V_212 * V_213 ,
struct V_91 * V_91 , unsigned int V_339 )
{
unsigned int V_367 ;
if ( V_10 -> V_346 < 0x100 || V_213 -> V_210 != V_368 )
return 0 ;
V_367 = V_91 -> V_74 -> V_369 . V_370 ;
return F_186 ( V_339 , V_367 + 1 ) - 1 ;
}
static unsigned int F_187 ( struct V_9 * V_10 ,
struct V_212 * V_213 ,
struct V_91 * V_91 , unsigned int V_339 )
{
unsigned int V_367 ;
unsigned int V_371 ;
if ( V_10 -> V_346 < 0x100 )
return 0 ;
switch ( V_213 -> V_210 ) {
case V_368 :
V_367 = V_91 -> V_74 -> V_369 . V_370 ;
V_371 = V_339 % ( V_367 + 1 ) ;
if ( V_371 == 0 )
return V_367 ;
return V_371 - 1 ;
default:
if ( V_339 == 0 )
return 0 ;
return V_339 - 1 ;
}
}
static int F_188 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_11 * V_99 ;
struct V_120 * V_120 ;
struct V_94 * V_251 ;
int V_372 , V_373 ;
struct V_89 * V_245 ;
bool V_112 ;
int V_330 ;
T_2 V_31 , V_343 ;
int V_325 , V_338 , V_365 , V_374 , V_47 ;
T_3 V_375 , V_102 ;
int V_141 , V_142 ;
bool V_28 ;
V_99 = V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] . V_12 ;
V_372 = V_91 -> V_376 ;
if ( V_372 < 1 ) {
F_16 ( V_10 , L_135 ) ;
return - V_319 ;
}
V_375 = ( T_3 ) V_91 -> V_348 ;
V_245 = & V_99 -> V_20 -> V_30 ;
V_330 = V_99 -> V_27 ;
V_120 = V_91 -> V_121 ;
for ( V_141 = 0 ; V_141 < V_372 ; V_141 ++ ) {
unsigned int V_339 ;
unsigned int V_377 ;
unsigned int V_371 ;
V_112 = true ;
V_325 = 0 ;
V_102 = V_375 + V_91 -> V_280 [ V_141 ] . V_366 ;
V_365 = V_91 -> V_280 [ V_141 ] . V_124 ;
V_374 = V_365 ;
V_339 = F_175 ( V_365 ,
F_172 (
F_173 ( & V_91 -> V_74 -> V_93 ) ) ) ;
if ( V_339 == 0 )
V_339 ++ ;
V_377 = F_185 ( V_10 , V_91 -> V_92 , V_91 ,
V_339 ) ;
V_371 = F_187 ( V_10 ,
V_91 -> V_92 , V_91 , V_339 ) ;
V_373 = F_184 ( V_10 , V_91 , V_141 ) ;
V_47 = F_156 ( V_10 , V_10 -> V_75 [ V_69 ] , V_70 ,
V_91 -> V_71 , V_373 , V_91 , V_141 , V_314 ) ;
if ( V_47 < 0 ) {
if ( V_141 == 0 )
return V_47 ;
goto V_226;
}
V_251 = V_120 -> V_251 [ V_141 ] ;
for ( V_142 = 0 ; V_142 < V_373 ; V_142 ++ ) {
T_2 V_336 = 0 ;
V_31 = 0 ;
if ( V_112 ) {
V_31 = F_189 ( V_377 ) |
F_190 ( V_371 ) ;
V_31 |= F_51 ( V_378 ) ;
V_31 |= V_379 ;
if ( V_141 == 0 ) {
if ( V_330 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_99 -> V_27 ;
V_112 = false ;
} else {
V_31 |= F_51 ( V_347 ) ;
V_31 |= V_99 -> V_27 ;
}
if ( F_176 ( V_91 ) )
V_31 |= V_345 ;
if ( V_142 < V_373 - 1 ) {
V_31 |= V_32 ;
V_28 = true ;
} else {
V_251 -> F_4 = V_99 -> V_20 ;
V_31 |= V_344 ;
if ( V_10 -> V_346 == 0x100 &&
! ( V_10 -> V_35 &
V_380 ) ) {
if ( V_141 < V_372 - 1 )
V_31 |= V_381 ;
}
V_28 = false ;
}
V_338 = V_329 -
( V_102 & ( ( 1 << V_382 ) - 1 ) ) ;
if ( V_338 > V_374 )
V_338 = V_374 ;
if ( V_10 -> V_346 < 0x100 ) {
V_336 = F_170 (
V_365 - V_325 ) ;
} else {
V_336 = F_171 (
V_325 , V_338 ,
V_339 , V_91 ,
( V_373 - V_142 - 1 ) ) ;
}
V_343 = F_144 ( V_338 ) |
V_336 |
F_177 ( 0 ) ;
F_153 ( V_10 , V_99 , V_28 ,
F_178 ( V_102 ) ,
F_179 ( V_102 ) ,
V_343 ,
V_31 ) ;
V_325 += V_338 ;
V_102 += V_338 ;
V_374 -= V_338 ;
}
if ( V_325 != V_365 ) {
F_23 ( V_10 , L_136 ) ;
V_47 = - V_319 ;
goto V_226;
}
}
if ( F_36 ( V_10 ) -> V_127 . V_128 == 0 ) {
if ( V_10 -> V_35 & V_129 )
F_191 () ;
}
F_36 ( V_10 ) -> V_127 . V_128 ++ ;
F_165 ( V_10 , V_69 , V_70 , V_91 -> V_71 ,
V_330 , V_245 ) ;
return 0 ;
V_226:
for ( V_141 -- ; V_141 >= 0 ; V_141 -- )
F_71 ( & V_120 -> V_251 [ V_141 ] -> V_82 ) ;
V_120 -> V_251 [ 0 ] -> F_4 = V_99 -> V_20 ;
F_50 ( V_10 , V_99 , V_120 -> V_251 [ 0 ] , true ) ;
V_99 -> V_20 = V_120 -> V_251 [ 0 ] -> V_112 ;
V_99 -> V_21 = V_120 -> V_251 [ 0 ] -> V_87 ;
V_99 -> V_27 = V_330 ;
V_99 -> V_26 = V_99 -> V_145 ;
F_60 ( F_57 ( V_91 -> V_92 -> V_123 ) , V_91 ) ;
return V_47 ;
}
int F_192 ( struct V_9 * V_10 , T_8 V_314 ,
struct V_91 * V_91 , int V_69 , unsigned int V_70 )
{
struct V_98 * V_261 ;
struct V_11 * V_99 ;
struct V_100 * V_101 ;
int V_383 ;
int V_331 ;
int V_332 ;
int V_372 , V_38 , V_141 ;
int V_47 ;
V_261 = V_10 -> V_75 [ V_69 ] ;
V_99 = V_261 -> V_76 [ V_70 ] . V_12 ;
V_101 = F_48 ( V_10 , V_261 -> V_107 , V_70 ) ;
V_38 = 0 ;
V_372 = V_91 -> V_376 ;
for ( V_141 = 0 ; V_141 < V_372 ; V_141 ++ )
V_38 += F_184 ( V_10 , V_91 , V_141 ) ;
V_47 = F_154 ( V_10 , V_99 , F_3 ( V_101 -> V_155 ) & V_156 ,
V_38 , V_314 ) ;
if ( V_47 )
return V_47 ;
V_383 = F_18 ( & V_10 -> V_384 -> V_385 ) ;
V_383 &= 0x3fff ;
V_91 -> V_383 = V_383 ;
if ( V_91 -> V_92 -> V_210 == V_334 ||
V_91 -> V_92 -> V_210 == V_335 )
V_91 -> V_383 >>= 3 ;
V_331 = F_167 ( F_3 ( V_101 -> V_155 ) ) ;
V_332 = V_91 -> V_333 ;
if ( V_91 -> V_92 -> V_210 == V_334 ||
V_91 -> V_92 -> V_210 == V_335 )
V_332 *= 8 ;
if ( V_331 != V_332 ) {
F_168 ( & V_91 -> V_92 -> V_92 ,
L_130 ,
V_332 , V_332 == 1 ? L_131 : L_132 ,
V_331 , V_331 == 1 ? L_131 : L_132 ) ;
V_91 -> V_333 = V_331 ;
if ( V_91 -> V_92 -> V_210 == V_334 ||
V_91 -> V_92 -> V_210 == V_335 )
V_91 -> V_333 /= 8 ;
}
V_99 -> V_145 = V_99 -> V_26 ;
return F_188 ( V_10 , V_314 , V_91 , V_69 , V_70 ) ;
}
static int F_193 ( struct V_9 * V_10 , T_2 V_310 , T_2 V_311 ,
T_2 V_312 , T_2 V_313 , bool V_386 )
{
int V_387 = V_10 -> V_388 ;
int V_47 ;
if ( ! V_386 )
V_387 ++ ;
V_47 = F_154 ( V_10 , V_10 -> V_49 , V_321 ,
V_387 , V_61 ) ;
if ( V_47 < 0 ) {
F_23 ( V_10 , L_137 ) ;
if ( V_386 )
F_23 ( V_10 , L_138
L_139 ) ;
return V_47 ;
}
F_153 ( V_10 , V_10 -> V_49 , false , V_310 , V_311 , V_312 ,
V_313 | V_10 -> V_49 -> V_27 ) ;
return 0 ;
}
int F_194 ( struct V_9 * V_10 , T_2 V_202 , T_2 V_69 )
{
return F_193 ( V_10 , 0 , 0 , 0 ,
F_51 ( V_202 ) | F_195 ( V_69 ) , false ) ;
}
int F_196 ( struct V_9 * V_10 , T_1 V_389 ,
T_2 V_69 , enum V_390 V_350 )
{
return F_193 ( V_10 , F_178 ( V_389 ) ,
F_179 ( V_389 ) , 0 ,
F_51 ( V_196 ) | F_195 ( V_69 )
| ( V_350 == V_391 ? V_392 : 0 ) , false ) ;
}
int F_197 ( struct V_9 * V_10 ,
T_2 V_310 , T_2 V_311 , T_2 V_312 , T_2 V_313 )
{
return F_193 ( V_10 , V_310 , V_311 , V_312 , V_313 , false ) ;
}
int F_198 ( struct V_9 * V_10 , T_2 V_69 )
{
return F_193 ( V_10 , 0 , 0 , 0 ,
F_51 ( V_200 ) | F_195 ( V_69 ) ,
false ) ;
}
int F_81 ( struct V_9 * V_10 , T_1 V_389 ,
T_2 V_69 , bool V_386 )
{
return F_193 ( V_10 , F_178 ( V_389 ) ,
F_179 ( V_389 ) , 0 ,
F_51 ( V_194 ) | F_195 ( V_69 ) ,
V_386 ) ;
}
int F_199 ( struct V_9 * V_10 , T_1 V_389 ,
T_2 V_69 , bool V_386 )
{
return F_193 ( V_10 , F_178 ( V_389 ) ,
F_179 ( V_389 ) , 0 ,
F_51 ( V_195 ) | F_195 ( V_69 ) ,
V_386 ) ;
}
int F_200 ( struct V_9 * V_10 , int V_69 ,
unsigned int V_70 , int V_393 )
{
T_2 V_394 = F_195 ( V_69 ) ;
T_2 V_395 = F_201 ( V_70 ) ;
T_2 type = F_51 ( V_197 ) ;
T_2 V_396 = F_202 ( V_393 ) ;
return F_193 ( V_10 , 0 , 0 , 0 ,
V_394 | V_395 | type | V_396 , false ) ;
}
static int F_53 ( struct V_9 * V_10 , int V_69 ,
unsigned int V_70 , unsigned int V_71 ,
struct V_1 * V_24 ,
union V_3 * V_397 , T_2 V_27 )
{
T_1 V_102 ;
T_2 V_394 = F_195 ( V_69 ) ;
T_2 V_395 = F_201 ( V_70 ) ;
T_2 V_398 = F_203 ( V_71 ) ;
T_2 type = F_51 ( V_198 ) ;
struct V_73 * V_74 ;
V_102 = F_1 ( V_24 , V_397 ) ;
if ( V_102 == 0 ) {
F_32 ( V_10 , L_140 ) ;
F_32 ( V_10 , L_141 ,
V_24 , V_397 ) ;
return 0 ;
}
V_74 = & V_10 -> V_75 [ V_69 ] -> V_76 [ V_70 ] ;
if ( ( V_74 -> V_77 & V_79 ) ) {
F_32 ( V_10 , L_140 ) ;
F_32 ( V_10 , L_142 ) ;
return 0 ;
}
V_74 -> V_159 = V_24 ;
V_74 -> V_147 = V_397 ;
return F_193 ( V_10 , F_178 ( V_102 ) | V_27 ,
F_179 ( V_102 ) , V_398 ,
V_394 | V_395 | type , false ) ;
}
int F_133 ( struct V_9 * V_10 , int V_69 ,
unsigned int V_70 )
{
T_2 V_394 = F_195 ( V_69 ) ;
T_2 V_395 = F_201 ( V_70 ) ;
T_2 type = F_51 ( V_199 ) ;
return F_193 ( V_10 , 0 , 0 , 0 , V_394 | V_395 | type ,
false ) ;
}
