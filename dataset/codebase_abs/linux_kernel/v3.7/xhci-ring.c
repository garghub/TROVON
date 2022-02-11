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
unsigned long long V_21 ;
V_12 -> V_22 ++ ;
if ( V_12 -> type != V_23 &&
! F_4 ( V_10 , V_12 , V_12 -> V_24 , V_12 -> V_25 ) )
V_12 -> V_26 ++ ;
do {
if ( F_4 ( V_10 , V_12 , V_12 -> V_24 , V_12 -> V_25 ) ) {
if ( V_12 -> type == V_23 &&
F_2 ( V_10 , V_12 ,
V_12 -> V_24 , V_12 -> V_25 ) ) {
V_12 -> V_27 = ( V_12 -> V_27 ? 0 : 1 ) ;
}
V_12 -> V_24 = V_12 -> V_24 -> V_14 ;
V_12 -> V_25 = V_12 -> V_24 -> V_6 ;
} else {
V_12 -> V_25 ++ ;
}
} while ( F_4 ( V_10 , V_12 , V_12 -> V_24 , V_12 -> V_25 ) );
V_21 = ( unsigned long long ) F_1 ( V_12 -> V_24 , V_12 -> V_25 ) ;
}
static void F_9 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_28 )
{
T_2 V_29 ;
union V_3 * V_14 ;
unsigned long long V_21 ;
V_29 = F_3 ( V_12 -> V_20 -> V_30 . V_31 [ 3 ] ) & V_32 ;
if ( V_12 -> type != V_23 &&
! F_4 ( V_10 , V_12 , V_12 -> V_33 , V_12 -> V_20 ) )
V_12 -> V_26 -- ;
V_14 = ++ ( V_12 -> V_20 ) ;
V_12 -> V_34 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
if ( V_12 -> type != V_23 ) {
if ( ! V_29 && ! V_28 )
break;
if ( ! ( V_12 -> type == V_35 &&
( V_10 -> V_36 & V_37 ) )
&& ! F_10 ( V_10 ) ) {
V_14 -> V_16 . V_17 &=
F_11 ( ~ V_32 ) ;
V_14 -> V_16 . V_17 |=
F_11 ( V_29 ) ;
}
F_12 () ;
V_14 -> V_16 . V_17 ^= F_11 ( V_38 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
V_12 -> V_27 = ( V_12 -> V_27 ? 0 : 1 ) ;
}
}
V_12 -> V_33 = V_12 -> V_33 -> V_14 ;
V_12 -> V_20 = V_12 -> V_33 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
V_21 = ( unsigned long long ) F_1 ( V_12 -> V_33 , V_12 -> V_20 ) ;
}
static inline int F_13 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_39 )
{
int V_40 ;
if ( V_12 -> V_26 < V_39 )
return 0 ;
if ( V_12 -> type != V_41 && V_12 -> type != V_23 ) {
V_40 = V_12 -> V_25 - V_12 -> V_24 -> V_6 ;
if ( V_12 -> V_26 < V_39 + V_40 )
return 0 ;
}
return 1 ;
}
void F_14 ( struct V_9 * V_10 )
{
if ( ! ( V_10 -> V_42 & V_43 ) )
return;
F_15 ( V_10 , L_1 ) ;
F_16 ( V_10 , V_44 , & V_10 -> V_45 -> V_46 [ 0 ] ) ;
F_17 ( V_10 , & V_10 -> V_45 -> V_46 [ 0 ] ) ;
}
static int F_18 ( struct V_9 * V_10 )
{
T_3 V_47 ;
int V_48 ;
F_15 ( V_10 , L_2 ) ;
if ( ! ( V_10 -> V_42 & V_43 ) ) {
F_15 ( V_10 , L_3
L_4 ) ;
return 0 ;
}
V_47 = F_19 ( V_10 , & V_10 -> V_49 -> V_50 ) ;
if ( ! ( V_47 & V_51 ) ) {
F_15 ( V_10 , L_5 ) ;
return 0 ;
}
V_10 -> V_42 = V_52 ;
F_20 ( V_10 , V_47 | V_53 ,
& V_10 -> V_49 -> V_50 ) ;
V_48 = F_21 ( V_10 , & V_10 -> V_49 -> V_50 ,
V_51 , 0 , 5 * 1000 * 1000 ) ;
if ( V_48 < 0 ) {
F_22 ( V_10 , L_6
L_7 ) ;
V_10 -> V_54 |= V_55 ;
F_23 ( V_10 ) ;
F_24 ( V_10 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
struct V_57 * V_58 ,
union V_3 * V_59 )
{
struct V_60 * V_61 ;
V_61 = F_26 ( sizeof( struct V_60 ) , V_62 ) ;
if ( ! V_61 )
return - V_63 ;
F_27 ( & V_61 -> V_64 ) ;
V_61 -> V_58 = V_58 ;
V_61 -> V_59 = V_59 ;
F_28 ( & V_61 -> V_64 , & V_10 -> V_64 ) ;
return 0 ;
}
int F_29 ( struct V_9 * V_10 , struct V_57 * V_58 ,
union V_3 * V_59 )
{
int V_65 = 0 ;
unsigned long V_66 ;
F_30 ( & V_10 -> V_67 , V_66 ) ;
if ( V_10 -> V_54 & V_55 ) {
F_31 ( V_10 , L_8
L_9 ) ;
V_65 = - V_56 ;
goto V_68;
}
V_65 = F_25 ( V_10 , V_58 , V_59 ) ;
if ( V_65 ) {
F_31 ( V_10 , L_10 ) ;
goto V_68;
}
V_65 = F_18 ( V_10 ) ;
if ( V_65 ) {
F_22 ( V_10 , L_11 ) ;
if ( F_32 ( V_65 == - V_56 ) ) {
F_33 ( & V_10 -> V_67 , V_66 ) ;
F_34 ( F_35 ( V_10 ) -> V_69 ) ;
F_15 ( V_10 , L_12 ) ;
return V_65 ;
}
}
V_68:
F_33 ( & V_10 -> V_67 , V_66 ) ;
return V_65 ;
}
void F_36 ( struct V_9 * V_10 ,
unsigned int V_70 ,
unsigned int V_71 ,
unsigned int V_72 )
{
T_4 T_5 * V_73 = & V_10 -> V_45 -> V_46 [ V_70 ] ;
struct V_74 * V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
unsigned int V_78 = V_75 -> V_78 ;
if ( ( V_78 & V_79 ) || ( V_78 & V_80 ) ||
( V_78 & V_81 ) )
return;
F_16 ( V_10 , F_37 ( V_71 , V_72 ) , V_73 ) ;
}
static void F_38 ( struct V_9 * V_10 ,
unsigned int V_70 ,
unsigned int V_71 )
{
unsigned int V_72 ;
struct V_74 * V_75 ;
V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
if ( ! ( V_75 -> V_78 & V_82 ) ) {
if ( ! ( F_39 ( & V_75 -> V_12 -> V_83 ) ) )
F_36 ( V_10 , V_70 , V_71 , 0 ) ;
return;
}
for ( V_72 = 1 ; V_72 < V_75 -> V_84 -> V_85 ;
V_72 ++ ) {
struct V_86 * V_84 = V_75 -> V_84 ;
if ( ! F_39 ( & V_84 -> V_87 [ V_72 ] -> V_83 ) )
F_36 ( V_10 , V_70 , V_71 ,
V_72 ) ;
}
}
static struct V_1 * F_40 (
struct V_1 * V_88 ,
union V_3 * V_4 , int * V_27 )
{
struct V_1 * V_89 = V_88 ;
struct V_90 * V_91 ;
while ( V_89 -> V_6 > V_4 ||
& V_89 -> V_6 [ V_7 - 1 ] < V_4 ) {
V_91 = & V_89 -> V_6 [ V_7 - 1 ] . V_30 ;
if ( V_91 -> V_31 [ 3 ] & F_11 ( V_18 ) )
* V_27 ^= 0x1 ;
V_89 = V_89 -> V_14 ;
if ( V_89 == V_88 )
return NULL ;
}
return V_89 ;
}
static struct V_11 * F_41 ( struct V_9 * V_10 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 )
{
struct V_74 * V_75 ;
V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
if ( ! ( V_75 -> V_78 & V_82 ) )
return V_75 -> V_12 ;
if ( V_72 == 0 ) {
F_31 ( V_10 ,
L_13
L_14 ,
V_70 , V_71 ) ;
return NULL ;
}
if ( V_72 < V_75 -> V_84 -> V_85 )
return V_75 -> V_84 -> V_87 [ V_72 ] ;
F_31 ( V_10 ,
L_15
L_16
L_17 ,
V_70 , V_71 ,
V_75 -> V_84 -> V_85 - 1 ,
V_72 ) ;
return NULL ;
}
static struct V_11 * F_42 ( struct V_9 * V_10 ,
struct V_92 * V_92 )
{
return F_41 ( V_10 , V_92 -> V_93 -> V_70 ,
F_43 ( & V_92 -> V_75 -> V_94 ) , V_92 -> V_72 ) ;
}
void F_44 ( struct V_9 * V_10 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 , struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_99 * V_93 = V_10 -> V_76 [ V_70 ] ;
struct V_11 * V_100 ;
struct V_90 * V_4 ;
struct V_101 * V_102 ;
T_1 V_21 ;
V_100 = F_41 ( V_10 , V_70 ,
V_71 , V_72 ) ;
if ( ! V_100 ) {
F_31 ( V_10 , L_18
L_19 ,
V_72 ) ;
return;
}
V_98 -> V_103 = 0 ;
F_15 ( V_10 , L_20 ) ;
V_98 -> V_104 = F_40 ( V_96 -> V_88 ,
V_93 -> V_77 [ V_71 ] . V_105 ,
& V_98 -> V_103 ) ;
if ( ! V_98 -> V_104 ) {
F_45 ( 1 ) ;
return;
}
F_15 ( V_10 , L_21 ) ;
V_102 = F_46 ( V_10 , V_93 -> V_106 , V_71 ) ;
V_98 -> V_103 = 0x1 & F_47 ( V_102 -> V_107 ) ;
V_98 -> V_108 = V_96 -> F_4 ;
F_15 ( V_10 , L_22 ) ;
V_98 -> V_104 = F_40 ( V_98 -> V_104 ,
V_98 -> V_108 ,
& V_98 -> V_103 ) ;
if ( ! V_98 -> V_104 ) {
F_45 ( 1 ) ;
return;
}
V_4 = & V_98 -> V_108 -> V_30 ;
if ( F_5 ( V_4 -> V_31 [ 3 ] ) &&
( V_4 -> V_31 [ 3 ] & F_11 ( V_18 ) ) )
V_98 -> V_103 ^= 0x1 ;
F_7 ( V_10 , V_100 , & V_98 -> V_104 , & V_98 -> V_108 ) ;
if ( V_100 -> V_15 == V_100 -> V_15 -> V_14 &&
V_98 -> V_108 < V_93 -> V_77 [ V_71 ] . V_105 )
V_98 -> V_103 ^= 0x1 ;
F_15 ( V_10 , L_23 , V_98 -> V_103 ) ;
F_15 ( V_10 , L_24 ,
V_98 -> V_104 ) ;
V_21 = F_1 ( V_98 -> V_104 , V_98 -> V_108 ) ;
F_15 ( V_10 , L_25 ,
( unsigned long long ) V_21 ) ;
}
static void F_48 ( struct V_9 * V_10 , struct V_11 * V_100 ,
struct V_95 * V_96 , bool V_109 )
{
struct V_1 * V_89 ;
union V_3 * V_110 ;
for ( V_89 = V_96 -> V_88 , V_110 = V_96 -> V_111 ;
true ;
F_7 ( V_10 , V_100 , & V_89 , & V_110 ) ) {
if ( F_5 ( V_110 -> V_30 . V_31 [ 3 ] ) ) {
V_110 -> V_30 . V_31 [ 3 ] &= F_11 ( ~ V_32 ) ;
if ( V_109 )
V_110 -> V_30 . V_31 [ 3 ] ^=
F_11 ( V_38 ) ;
F_15 ( V_10 , L_26 ) ;
F_15 ( V_10 , L_27
L_28 ,
V_110 ,
( unsigned long long ) F_1 ( V_89 , V_110 ) ,
V_89 ,
( unsigned long long ) V_89 -> V_8 ) ;
} else {
V_110 -> V_30 . V_31 [ 0 ] = 0 ;
V_110 -> V_30 . V_31 [ 1 ] = 0 ;
V_110 -> V_30 . V_31 [ 2 ] = 0 ;
V_110 -> V_30 . V_31 [ 3 ] &= F_11 ( V_38 ) ;
if ( V_109 && V_110 != V_96 -> V_111 &&
V_110 != V_96 -> F_4 )
V_110 -> V_30 . V_31 [ 3 ] ^=
F_11 ( V_38 ) ;
V_110 -> V_30 . V_31 [ 3 ] |= F_11 (
F_49 ( V_112 ) ) ;
F_15 ( V_10 , L_29 ,
( unsigned long long )
F_1 ( V_89 , V_110 ) ) ;
}
if ( V_110 == V_96 -> F_4 )
break;
}
}
void F_50 ( struct V_9 * V_10 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 ,
struct V_97 * V_113 )
{
struct V_74 * V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
F_15 ( V_10 , L_30
L_31 ,
V_113 -> V_104 ,
( unsigned long long ) V_113 -> V_104 -> V_8 ,
V_113 -> V_108 ,
( unsigned long long ) F_1 ( V_113 -> V_104 , V_113 -> V_108 ) ,
V_113 -> V_103 ) ;
F_51 ( V_10 , V_70 , V_71 , V_72 ,
V_113 -> V_104 ,
V_113 -> V_108 ,
( T_2 ) V_113 -> V_103 ) ;
V_75 -> V_78 |= V_80 ;
}
static void F_52 ( struct V_9 * V_10 ,
struct V_74 * V_75 )
{
V_75 -> V_78 &= ~ V_79 ;
if ( F_53 ( & V_75 -> V_114 ) )
V_75 -> V_115 -- ;
}
static void F_54 ( struct V_9 * V_10 ,
struct V_95 * V_96 , int V_116 , char * V_117 )
{
struct V_118 * V_119 ;
struct V_92 * V_92 ;
struct V_120 * V_120 ;
V_92 = V_96 -> V_92 ;
V_120 = V_92 -> V_121 ;
V_120 -> V_122 ++ ;
V_119 = F_55 ( V_92 -> V_93 -> V_123 ) ;
if ( V_120 -> V_122 == V_120 -> V_124 ) {
if ( F_56 ( V_92 -> V_125 ) == V_126 ) {
F_35 ( V_10 ) -> V_127 . V_128 -- ;
if ( F_35 ( V_10 ) -> V_127 . V_128 == 0 ) {
if ( V_10 -> V_36 & V_129 )
F_57 () ;
}
}
F_58 ( V_119 , V_92 ) ;
F_59 ( & V_10 -> V_67 ) ;
F_60 ( V_119 , V_92 , V_116 ) ;
F_61 ( V_10 , V_120 ) ;
F_62 ( & V_10 -> V_67 ) ;
}
}
static void F_63 ( struct V_9 * V_10 ,
union V_3 * V_4 , struct V_130 * V_131 )
{
unsigned int V_70 ;
unsigned int V_71 ;
struct V_99 * V_132 ;
struct V_11 * V_100 ;
struct V_74 * V_75 ;
struct V_133 * V_134 ;
struct V_95 * V_96 = NULL ;
struct V_95 * V_135 ;
struct V_97 V_113 ;
if ( F_32 ( F_64 (
F_3 ( V_10 -> V_50 -> V_25 -> V_30 . V_31 [ 3 ] ) ) ) ) {
V_70 = F_65 (
F_3 ( V_10 -> V_50 -> V_25 -> V_30 . V_31 [ 3 ] ) ) ;
V_132 = V_10 -> V_76 [ V_70 ] ;
if ( V_132 )
F_66 ( V_10 , V_132 ,
V_131 ) ;
else
F_31 ( V_10 , L_32
L_33 ,
V_70 ) ;
return;
}
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_70 = F_65 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_71 = F_67 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
if ( F_39 ( & V_75 -> V_136 ) ) {
F_52 ( V_10 , V_75 ) ;
V_75 -> V_137 = NULL ;
V_75 -> V_105 = NULL ;
F_38 ( V_10 , V_70 , V_71 ) ;
return;
}
F_68 (entry, &ep->cancelled_td_list) {
V_96 = F_69 ( V_134 , struct V_95 , V_136 ) ;
F_15 ( V_10 , L_34 ,
( unsigned long long ) F_1 (
V_96 -> V_88 , V_96 -> V_111 ) ) ;
V_100 = F_42 ( V_10 , V_96 -> V_92 ) ;
if ( ! V_100 ) {
F_31 ( V_10 , L_35
L_36 ,
V_96 -> V_92 ,
V_96 -> V_92 -> V_72 ) ;
goto V_138;
}
if ( V_96 == V_75 -> V_137 )
F_44 ( V_10 , V_70 , V_71 ,
V_96 -> V_92 -> V_72 ,
V_96 , & V_113 ) ;
else
F_48 ( V_10 , V_100 , V_96 , false ) ;
V_138:
F_70 ( & V_96 -> V_83 ) ;
}
V_135 = V_96 ;
F_52 ( V_10 , V_75 ) ;
if ( V_113 . V_108 && V_113 . V_104 ) {
F_50 ( V_10 ,
V_70 , V_71 ,
V_75 -> V_137 -> V_92 -> V_72 ,
& V_113 ) ;
F_14 ( V_10 ) ;
} else {
F_38 ( V_10 , V_70 , V_71 ) ;
}
V_75 -> V_137 = NULL ;
V_75 -> V_105 = NULL ;
do {
V_96 = F_69 ( V_75 -> V_136 . V_14 ,
struct V_95 , V_136 ) ;
F_70 ( & V_96 -> V_136 ) ;
F_54 ( V_10 , V_96 , 0 , L_37 ) ;
if ( V_10 -> V_54 & V_55 )
return;
} while ( V_96 != V_135 );
}
void F_71 ( unsigned long V_139 )
{
struct V_9 * V_10 ;
struct V_74 * V_75 ;
struct V_74 * V_140 ;
struct V_11 * V_12 ;
struct V_95 * V_96 ;
int V_48 , V_141 , V_142 ;
unsigned long V_66 ;
V_75 = (struct V_74 * ) V_139 ;
V_10 = V_75 -> V_10 ;
F_30 ( & V_10 -> V_67 , V_66 ) ;
V_75 -> V_115 -- ;
if ( V_10 -> V_54 & V_55 ) {
F_15 ( V_10 , L_38
L_39 ) ;
F_33 ( & V_10 -> V_67 , V_66 ) ;
return;
}
if ( ! ( V_75 -> V_115 == 0 && ( V_75 -> V_78 & V_79 ) ) ) {
F_15 ( V_10 , L_40
L_41 ) ;
F_33 ( & V_10 -> V_67 , V_66 ) ;
return;
}
F_31 ( V_10 , L_42 ) ;
F_31 ( V_10 , L_43 ) ;
V_10 -> V_54 |= V_55 ;
F_23 ( V_10 ) ;
F_33 ( & V_10 -> V_67 , V_66 ) ;
V_48 = F_24 ( V_10 ) ;
F_30 ( & V_10 -> V_67 , V_66 ) ;
if ( V_48 < 0 ) {
F_31 ( V_10 , L_44 ) ;
F_31 ( V_10 , L_45 ) ;
}
for ( V_141 = 0 ; V_141 < V_143 ; V_141 ++ ) {
if ( ! V_10 -> V_76 [ V_141 ] )
continue;
for ( V_142 = 0 ; V_142 < 31 ; V_142 ++ ) {
V_140 = & V_10 -> V_76 [ V_141 ] -> V_77 [ V_142 ] ;
V_12 = V_140 -> V_12 ;
if ( ! V_12 )
continue;
F_15 ( V_10 , L_46
L_47 , V_141 , V_142 ) ;
while ( ! F_39 ( & V_12 -> V_83 ) ) {
V_96 = F_72 ( & V_12 -> V_83 ,
struct V_95 ,
V_83 ) ;
F_70 ( & V_96 -> V_83 ) ;
if ( ! F_39 ( & V_96 -> V_136 ) )
F_70 ( & V_96 -> V_136 ) ;
F_54 ( V_10 , V_96 ,
- V_56 , L_48 ) ;
}
while ( ! F_39 ( & V_140 -> V_136 ) ) {
V_96 = F_72 (
& V_140 -> V_136 ,
struct V_95 ,
V_136 ) ;
F_70 ( & V_96 -> V_136 ) ;
F_54 ( V_10 , V_96 ,
- V_56 , L_48 ) ;
}
}
}
F_33 ( & V_10 -> V_67 , V_66 ) ;
F_15 ( V_10 , L_49 ) ;
F_34 ( F_35 ( V_10 ) -> V_69 ) ;
F_15 ( V_10 , L_12 ) ;
}
static void F_73 ( struct V_9 * V_10 ,
struct V_99 * V_93 ,
struct V_11 * V_100 ,
unsigned int V_71 )
{
union V_3 * V_144 ;
int V_145 ;
bool V_146 = false ;
V_145 = V_100 -> V_26 ;
V_144 = V_100 -> V_25 ;
if ( F_4 ( V_10 , V_100 , V_100 -> V_24 , V_100 -> V_25 ) ) {
V_100 -> V_24 = V_100 -> V_24 -> V_14 ;
V_100 -> V_25 = V_100 -> V_24 -> V_6 ;
}
while ( V_100 -> V_25 != V_93 -> V_77 [ V_71 ] . V_147 ) {
V_100 -> V_26 ++ ;
V_100 -> V_25 ++ ;
if ( F_4 ( V_10 , V_100 , V_100 -> V_24 ,
V_100 -> V_25 ) ) {
if ( V_100 -> V_25 ==
V_93 -> V_77 [ V_71 ] . V_147 )
break;
V_100 -> V_24 = V_100 -> V_24 -> V_14 ;
V_100 -> V_25 = V_100 -> V_24 -> V_6 ;
}
if ( V_100 -> V_25 == V_144 ) {
V_146 = true ;
break;
}
}
if ( V_146 ) {
F_15 ( V_10 , L_50 ) ;
V_100 -> V_26 = V_145 ;
}
}
static void F_74 ( struct V_9 * V_10 ,
struct V_130 * V_131 ,
union V_3 * V_4 )
{
unsigned int V_70 ;
unsigned int V_71 ;
unsigned int V_72 ;
struct V_11 * V_100 ;
struct V_99 * V_93 ;
struct V_101 * V_102 ;
struct V_148 * V_149 ;
V_70 = F_65 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_71 = F_67 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_72 = F_75 ( F_3 ( V_4 -> V_30 . V_31 [ 2 ] ) ) ;
V_93 = V_10 -> V_76 [ V_70 ] ;
V_100 = F_76 ( V_93 , V_71 , V_72 ) ;
if ( ! V_100 ) {
F_31 ( V_10 , L_51
L_52 ,
V_72 ) ;
V_93 -> V_77 [ V_71 ] . V_78 &= ~ V_80 ;
return;
}
V_102 = F_46 ( V_10 , V_93 -> V_106 , V_71 ) ;
V_149 = F_77 ( V_10 , V_93 -> V_106 ) ;
if ( F_78 ( F_3 ( V_131 -> V_116 ) ) != V_150 ) {
unsigned int V_78 ;
unsigned int V_151 ;
switch ( F_78 ( F_3 ( V_131 -> V_116 ) ) ) {
case V_152 :
F_31 ( V_10 , L_53
L_54 ) ;
break;
case V_153 :
F_31 ( V_10 , L_55
L_56 ) ;
V_78 = F_3 ( V_102 -> V_154 ) ;
V_78 &= V_155 ;
V_151 = F_3 ( V_149 -> V_156 ) ;
V_151 = F_79 ( V_151 ) ;
F_15 ( V_10 , L_57 ,
V_151 , V_78 ) ;
break;
case V_157 :
F_31 ( V_10 , L_58
L_59 , V_70 ) ;
break;
default:
F_31 ( V_10 , L_60
L_61 ,
F_78 ( F_3 ( V_131 -> V_116 ) ) ) ;
break;
}
} else {
F_15 ( V_10 , L_62 ,
F_47 ( V_102 -> V_107 ) ) ;
if ( F_1 ( V_93 -> V_77 [ V_71 ] . V_158 ,
V_93 -> V_77 [ V_71 ] . V_147 ) ==
( F_47 ( V_102 -> V_107 ) & ~ ( V_159 ) ) ) {
F_73 ( V_10 , V_93 ,
V_100 , V_71 ) ;
} else {
F_31 ( V_10 , L_63
L_64 ) ;
F_31 ( V_10 , L_65 ,
V_93 -> V_77 [ V_71 ] . V_158 ,
V_93 -> V_77 [ V_71 ] . V_147 ) ;
}
}
V_93 -> V_77 [ V_71 ] . V_78 &= ~ V_80 ;
V_93 -> V_77 [ V_71 ] . V_158 = NULL ;
V_93 -> V_77 [ V_71 ] . V_147 = NULL ;
F_38 ( V_10 , V_70 , V_71 ) ;
}
static void F_80 ( struct V_9 * V_10 ,
struct V_130 * V_131 ,
union V_3 * V_4 )
{
int V_70 ;
unsigned int V_71 ;
V_70 = F_65 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
V_71 = F_67 ( F_3 ( V_4 -> V_30 . V_31 [ 3 ] ) ) ;
F_15 ( V_10 , L_66 ,
F_78 ( F_3 ( V_131 -> V_116 ) ) ) ;
if ( V_10 -> V_36 & V_160 ) {
F_15 ( V_10 , L_67 ) ;
F_81 ( V_10 ,
V_10 -> V_76 [ V_70 ] -> V_161 -> V_8 , V_70 ,
false ) ;
F_14 ( V_10 ) ;
} else {
V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_78 &= ~ V_81 ;
F_38 ( V_10 , V_70 , V_71 ) ;
}
}
static void F_82 ( struct V_9 * V_10 ,
struct V_57 * V_58 , T_2 V_116 )
{
V_58 -> V_116 = V_116 ;
F_83 ( & V_58 -> V_162 ) ;
if ( V_58 -> V_163 )
F_84 ( V_58 -> V_163 ) ;
else
F_85 ( V_10 , V_58 ) ;
}
static int F_66 ( struct V_9 * V_10 ,
struct V_99 * V_132 ,
struct V_130 * V_131 )
{
struct V_57 * V_58 ;
if ( F_39 ( & V_132 -> V_162 ) )
return 0 ;
V_58 = F_69 ( V_132 -> V_162 . V_14 ,
struct V_57 , V_162 ) ;
if ( V_10 -> V_50 -> V_25 != V_58 -> V_164 )
return 0 ;
F_82 ( V_10 , V_58 ,
F_78 ( F_3 ( V_131 -> V_116 ) ) ) ;
return 1 ;
}
static void F_86 ( struct V_9 * V_10 , struct V_60 * V_165 )
{
struct V_1 * V_89 ;
union V_3 * V_59 ;
T_2 V_27 ;
if ( V_10 -> V_50 -> V_25 == V_10 -> V_50 -> V_20 )
return;
V_89 = F_40 ( V_10 -> V_50 -> V_15 ,
V_10 -> V_50 -> V_25 , & V_27 ) ;
if ( ! V_89 ) {
F_31 ( V_10 , L_68 ,
V_10 -> V_50 -> V_25 ,
( unsigned long long )
F_1 ( V_10 -> V_50 -> V_24 ,
V_10 -> V_50 -> V_25 ) ) ;
F_87 ( V_10 , V_10 -> V_50 ) ;
F_88 ( V_10 , V_10 -> V_50 ) ;
return;
}
for ( V_59 = V_10 -> V_50 -> V_25 ;
V_59 != V_10 -> V_50 -> V_20 ;
F_7 ( V_10 , V_10 -> V_50 , & V_89 , & V_59 ) ) {
if ( F_5 ( V_59 -> V_30 . V_31 [ 3 ] ) )
continue;
if ( V_165 -> V_59 == V_59 ) {
if ( V_165 -> V_58 )
F_82 ( V_10 ,
V_165 -> V_58 , V_166 ) ;
V_27 = F_3 ( V_59 -> V_30 . V_31 [ 3 ] )
& V_38 ;
V_59 -> V_30 . V_31 [ 0 ] = 0 ;
V_59 -> V_30 . V_31 [ 1 ] = 0 ;
V_59 -> V_30 . V_31 [ 2 ] = 0 ;
V_59 -> V_30 . V_31 [ 3 ] = F_11 (
F_49 ( V_167 ) | V_27 ) ;
break;
}
}
}
static void F_89 ( struct V_9 * V_10 )
{
struct V_60 * V_165 , * V_168 ;
if ( F_39 ( & V_10 -> V_64 ) )
return;
F_90 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
F_86 ( V_10 , V_165 ) ;
F_83 ( & V_165 -> V_64 ) ;
F_91 ( V_165 ) ;
}
}
static int F_92 ( struct V_9 * V_10 ,
union V_3 * V_59 )
{
struct V_60 * V_165 , * V_168 ;
if ( F_39 ( & V_10 -> V_64 ) )
return 0 ;
F_90 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
if ( V_165 -> V_59 == V_59 ) {
if ( V_165 -> V_58 )
F_82 ( V_10 ,
V_165 -> V_58 , V_166 ) ;
F_83 ( & V_165 -> V_64 ) ;
F_91 ( V_165 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_93 ( struct V_9 * V_10 ,
int V_169 )
{
int V_170 = 0 ;
V_170 = F_92 ( V_10 ,
V_10 -> V_50 -> V_25 ) ;
if ( V_169 == V_171 )
V_10 -> V_42 = V_172 ;
else if ( V_169 == V_166 ) {
F_89 ( V_10 ) ;
V_10 -> V_42 = V_43 ;
if ( V_10 -> V_50 -> V_25 != V_10 -> V_50 -> V_20 )
F_14 ( V_10 ) ;
}
return V_170 ;
}
static void F_94 ( struct V_9 * V_10 ,
struct V_130 * V_131 )
{
int V_70 = F_65 ( F_3 ( V_131 -> V_66 ) ) ;
T_3 V_173 ;
T_1 V_174 ;
struct V_175 * V_176 ;
struct V_99 * V_132 ;
unsigned int V_71 ;
struct V_11 * V_100 ;
unsigned int V_78 ;
V_173 = F_47 ( V_131 -> V_59 ) ;
V_174 = F_1 ( V_10 -> V_50 -> V_24 ,
V_10 -> V_50 -> V_25 ) ;
if ( V_174 == 0 ) {
V_10 -> V_177 |= 1 << 4 ;
return;
}
if ( V_173 != ( T_3 ) V_174 ) {
V_10 -> V_177 |= 1 << 5 ;
return;
}
if ( ( F_78 ( F_3 ( V_131 -> V_116 ) ) == V_171 ) ||
( F_78 ( F_3 ( V_131 -> V_116 ) ) == V_166 ) ) {
if ( F_93 ( V_10 ,
F_78 ( F_3 ( V_131 -> V_116 ) ) ) ) {
F_8 ( V_10 , V_10 -> V_50 ) ;
return;
}
}
switch ( F_3 ( V_10 -> V_50 -> V_25 -> V_30 . V_31 [ 3 ] )
& V_178 ) {
case F_49 ( V_179 ) :
if ( F_78 ( F_3 ( V_131 -> V_116 ) ) == V_150 )
V_10 -> V_70 = V_70 ;
else
V_10 -> V_70 = 0 ;
F_84 ( & V_10 -> V_180 ) ;
break;
case F_49 ( V_181 ) :
if ( V_10 -> V_76 [ V_70 ] ) {
if ( V_10 -> V_36 & V_182 )
F_95 ( V_10 ,
V_10 -> V_76 [ V_70 ] , true ) ;
F_96 ( V_10 , V_70 ) ;
}
break;
case F_49 ( V_183 ) :
V_132 = V_10 -> V_76 [ V_70 ] ;
if ( F_66 ( V_10 , V_132 , V_131 ) )
break;
V_176 = F_97 ( V_10 ,
V_132 -> V_161 ) ;
V_71 = F_98 ( F_3 ( V_176 -> V_184 ) ) - 1 ;
if ( V_10 -> V_36 & V_160 &&
V_71 != ( unsigned int ) - 1 &&
F_3 ( V_176 -> V_184 ) - V_185 ==
F_3 ( V_176 -> V_186 ) ) {
V_100 = V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_12 ;
V_78 = V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_78 ;
if ( ! ( V_78 & V_81 ) )
goto V_187;
F_15 ( V_10 , L_69
L_70 ,
V_71 , V_78 ) ;
V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_78 &=
~ V_81 ;
F_38 ( V_10 , V_70 , V_71 ) ;
break;
}
V_187:
F_15 ( V_10 , L_71 ) ;
V_10 -> V_76 [ V_70 ] -> V_188 =
F_78 ( F_3 ( V_131 -> V_116 ) ) ;
F_84 ( & V_10 -> V_76 [ V_70 ] -> V_189 ) ;
break;
case F_49 ( V_190 ) :
V_132 = V_10 -> V_76 [ V_70 ] ;
if ( F_66 ( V_10 , V_132 , V_131 ) )
break;
V_10 -> V_76 [ V_70 ] -> V_188 = F_78 ( F_3 ( V_131 -> V_116 ) ) ;
F_84 ( & V_10 -> V_76 [ V_70 ] -> V_189 ) ;
break;
case F_49 ( V_191 ) :
V_10 -> V_76 [ V_70 ] -> V_188 = F_78 ( F_3 ( V_131 -> V_116 ) ) ;
F_84 ( & V_10 -> V_180 ) ;
break;
case F_49 ( V_192 ) :
F_63 ( V_10 , V_10 -> V_50 -> V_25 , V_131 ) ;
break;
case F_49 ( V_193 ) :
F_74 ( V_10 , V_131 , V_10 -> V_50 -> V_25 ) ;
break;
case F_49 ( V_167 ) :
break;
case F_49 ( V_194 ) :
F_80 ( V_10 , V_131 , V_10 -> V_50 -> V_25 ) ;
break;
case F_49 ( V_195 ) :
F_15 ( V_10 , L_72 ) ;
V_70 = F_65 (
F_3 ( V_10 -> V_50 -> V_25 -> V_30 . V_31 [ 3 ] ) ) ;
V_132 = V_10 -> V_76 [ V_70 ] ;
if ( V_132 )
F_66 ( V_10 , V_132 , V_131 ) ;
else
F_31 ( V_10 , L_73
L_74 , V_70 ) ;
break;
case F_49 ( V_196 ) :
if ( ! ( V_10 -> V_36 & V_197 ) ) {
V_10 -> V_177 |= 1 << 6 ;
break;
}
F_15 ( V_10 , L_75 ,
F_99 ( F_3 ( V_131 -> V_116 ) ) ,
F_100 ( F_3 ( V_131 -> V_116 ) ) ) ;
break;
default:
V_10 -> V_177 |= 1 << 6 ;
break;
}
F_8 ( V_10 , V_10 -> V_50 ) ;
}
static void F_101 ( struct V_9 * V_10 ,
union V_3 * V_131 )
{
T_2 V_198 ;
V_198 = F_102 ( F_3 ( V_131 -> V_30 . V_31 [ 3 ] ) ) ;
F_15 ( V_10 , L_76 , V_198 ) ;
if ( V_198 == V_199 && ( V_10 -> V_36 & V_197 ) )
F_94 ( V_10 , & V_131 -> V_200 ) ;
}
static unsigned int F_103 ( struct V_118 * V_119 ,
struct V_9 * V_10 , T_2 V_201 )
{
unsigned int V_141 ;
unsigned int V_202 = 0 ;
for ( V_141 = 0 ; V_141 < ( V_201 - 1 ) ; V_141 ++ ) {
T_6 V_203 = V_10 -> V_204 [ V_141 ] ;
if ( V_203 == 0 || V_203 == V_205 )
continue;
if ( ( V_203 == 0x03 ) == ( V_119 -> V_206 == V_207 ) )
V_202 ++ ;
}
return V_202 ;
}
static void F_104 ( struct V_9 * V_10 ,
union V_3 * V_131 )
{
T_2 V_70 ;
struct V_208 * V_209 ;
V_70 = F_65 ( V_131 -> V_30 . V_31 [ 3 ] ) ;
if ( ! V_10 -> V_76 [ V_70 ] ) {
F_31 ( V_10 , L_77
L_78 , V_70 ) ;
return;
}
F_15 ( V_10 , L_79 ,
V_70 ) ;
V_209 = V_10 -> V_76 [ V_70 ] -> V_209 ;
if ( V_209 && V_209 -> V_210 )
F_105 ( V_209 -> V_210 , V_209 -> V_211 ) ;
}
static void F_106 ( struct V_9 * V_10 ,
union V_3 * V_131 )
{
struct V_118 * V_119 ;
T_2 V_201 ;
T_2 V_212 , V_213 ;
int V_214 ;
int V_70 ;
unsigned int V_215 ;
T_6 V_216 ;
struct V_217 * V_218 ;
T_4 T_5 * * V_204 ;
bool V_219 = false ;
if ( F_78 ( F_3 ( V_131 -> V_30 . V_31 [ 2 ] ) ) != V_150 ) {
F_31 ( V_10 , L_80 ) ;
V_10 -> V_177 |= 1 << 8 ;
}
V_201 = F_107 ( F_3 ( V_131 -> V_30 . V_31 [ 0 ] ) ) ;
F_15 ( V_10 , L_81 , V_201 ) ;
V_214 = F_108 ( V_10 -> V_220 ) ;
if ( ( V_201 <= 0 ) || ( V_201 > V_214 ) ) {
F_31 ( V_10 , L_82 , V_201 ) ;
V_219 = true ;
goto V_221;
}
V_216 = V_10 -> V_204 [ V_201 - 1 ] ;
if ( V_216 == 0 ) {
F_31 ( V_10 , L_83
L_84 ,
V_201 ) ;
V_219 = true ;
goto V_221;
}
if ( V_216 == V_205 ) {
F_31 ( V_10 , L_85
L_84 ,
V_201 ) ;
V_219 = true ;
goto V_221;
}
V_119 = F_35 ( V_10 ) ;
if ( ( V_216 == 0x03 ) != ( V_119 -> V_206 == V_207 ) )
V_119 = V_10 -> V_222 ;
V_218 = & V_10 -> V_218 [ F_109 ( V_119 ) ] ;
if ( V_119 -> V_206 == V_207 )
V_204 = V_10 -> V_223 ;
else
V_204 = V_10 -> V_224 ;
V_215 = F_103 ( V_119 , V_10 ,
V_201 ) ;
V_212 = F_17 ( V_10 , V_204 [ V_215 ] ) ;
if ( V_119 -> V_98 == V_225 ) {
F_15 ( V_10 , L_86 ) ;
F_110 ( V_119 ) ;
}
if ( ( V_212 & V_226 ) && ( V_212 & V_227 ) == V_228 ) {
F_15 ( V_10 , L_87 , V_201 ) ;
V_213 = F_17 ( V_10 , & V_10 -> V_49 -> V_58 ) ;
if ( ! ( V_213 & V_229 ) ) {
F_31 ( V_10 , L_88 ) ;
goto V_221;
}
if ( F_111 ( V_212 ) ) {
F_15 ( V_10 , L_89 , V_201 ) ;
V_218 -> V_230 |= 1 << V_215 ;
F_112 ( V_10 , V_204 ,
V_215 , V_226 ) ;
F_113 ( V_10 , V_204 , V_215 ,
V_231 ) ;
V_219 = true ;
goto V_221;
} else {
F_15 ( V_10 , L_90 , V_201 ) ;
V_218 -> V_232 [ V_215 ] = V_233 +
F_114 ( 20 ) ;
F_115 ( V_215 , & V_218 -> V_234 ) ;
F_116 ( & V_119 -> V_235 ,
V_218 -> V_232 [ V_215 ] ) ;
}
}
if ( ( V_212 & V_226 ) && ( V_212 & V_227 ) == V_231 &&
F_111 ( V_212 ) ) {
F_15 ( V_10 , L_91 , V_201 ) ;
V_70 = F_117 ( V_119 , V_10 ,
V_215 + 1 ) ;
if ( V_70 && V_10 -> V_76 [ V_70 ] )
F_118 ( V_10 , V_70 ) ;
if ( V_218 -> V_230 && ( 1 << V_215 ) ) {
V_218 -> V_230 &=
~ ( 1 << V_215 ) ;
F_112 ( V_10 , V_204 ,
V_215 , V_226 ) ;
F_105 ( V_119 -> V_127 . V_236 ,
V_215 + 1 ) ;
V_219 = true ;
goto V_221;
}
}
if ( V_119 -> V_206 != V_207 )
F_112 ( V_10 , V_204 , V_215 ,
V_226 ) ;
V_221:
F_8 ( V_10 , V_10 -> V_13 ) ;
if ( V_219 )
return;
F_59 ( & V_10 -> V_67 ) ;
F_119 ( V_119 ) ;
F_62 ( & V_10 -> V_67 ) ;
}
struct V_1 * F_120 ( struct V_1 * V_88 ,
union V_3 * V_237 ,
union V_3 * V_238 ,
T_1 V_239 )
{
T_1 V_240 ;
T_1 V_241 ;
T_1 V_242 ;
struct V_1 * V_89 ;
V_240 = F_1 ( V_88 , V_237 ) ;
V_89 = V_88 ;
do {
if ( V_240 == 0 )
return NULL ;
V_241 = F_1 ( V_89 ,
& V_89 -> V_6 [ V_7 - 1 ] ) ;
V_242 = F_1 ( V_89 , V_238 ) ;
if ( V_242 > 0 ) {
if ( V_240 <= V_242 ) {
if ( V_239 >= V_240 && V_239 <= V_242 )
return V_89 ;
} else {
if ( ( V_239 >= V_240 &&
V_239 <= V_241 ) ||
( V_239 >= V_89 -> V_8 &&
V_239 <= V_242 ) )
return V_89 ;
}
return NULL ;
} else {
if ( V_239 >= V_240 && V_239 <= V_241 )
return V_89 ;
}
V_89 = V_89 -> V_14 ;
V_240 = F_1 ( V_89 , & V_89 -> V_6 [ 0 ] ) ;
} while ( V_89 != V_88 );
return NULL ;
}
static void F_121 ( struct V_9 * V_10 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 ,
struct V_95 * V_243 , union V_3 * V_244 )
{
struct V_74 * V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
V_75 -> V_78 |= V_81 ;
V_75 -> V_137 = V_243 ;
V_75 -> V_105 = V_244 ;
V_75 -> V_245 = V_72 ;
F_122 ( V_10 , V_70 , V_71 ) ;
F_123 ( V_10 , V_243 -> V_92 -> V_93 , V_71 ) ;
V_75 -> V_137 = NULL ;
V_75 -> V_105 = NULL ;
V_75 -> V_245 = 0 ;
F_14 ( V_10 ) ;
}
static int F_124 ( struct V_9 * V_10 ,
struct V_101 * V_102 ,
unsigned int V_246 )
{
if ( V_246 == V_247 ||
V_246 == V_248 ||
V_246 == V_249 )
if ( ( V_102 -> V_154 & F_11 ( V_155 ) ) ==
F_11 ( V_250 ) )
return 1 ;
return 0 ;
}
int F_125 ( struct V_9 * V_10 , unsigned int V_246 )
{
if ( V_246 >= 224 && V_246 <= 255 ) {
F_15 ( V_10 , L_92 ,
V_246 ) ;
F_15 ( V_10 , L_93 ) ;
return 1 ;
}
return 0 ;
}
static int F_126 ( struct V_9 * V_10 , struct V_95 * V_243 ,
union V_3 * V_244 , struct V_251 * V_131 ,
struct V_74 * V_75 , int * V_116 , bool V_252 )
{
struct V_99 * V_253 ;
struct V_11 * V_100 ;
unsigned int V_70 ;
int V_71 ;
struct V_92 * V_92 = NULL ;
struct V_101 * V_102 ;
int V_48 = 0 ;
struct V_120 * V_120 ;
T_2 V_246 ;
V_70 = F_65 ( F_3 ( V_131 -> V_66 ) ) ;
V_253 = V_10 -> V_76 [ V_70 ] ;
V_71 = F_127 ( F_3 ( V_131 -> V_66 ) ) - 1 ;
V_100 = F_128 ( V_75 , F_47 ( V_131 -> V_254 ) ) ;
V_102 = F_46 ( V_10 , V_253 -> V_106 , V_71 ) ;
V_246 = F_78 ( F_3 ( V_131 -> V_255 ) ) ;
if ( V_252 )
goto V_256;
if ( V_246 == V_257 ||
V_246 == V_258 ) {
V_75 -> V_137 = V_243 ;
V_75 -> V_105 = V_244 ;
return 0 ;
} else {
if ( V_246 == V_259 ) {
V_75 -> V_137 = V_243 ;
V_75 -> V_105 = V_244 ;
V_75 -> V_245 = V_100 -> V_72 ;
} else if ( F_124 ( V_10 ,
V_102 , V_246 ) ) {
F_121 ( V_10 ,
V_70 , V_71 , V_100 -> V_72 ,
V_243 , V_244 ) ;
} else {
while ( V_100 -> V_25 != V_243 -> F_4 )
F_8 ( V_10 , V_100 ) ;
F_8 ( V_10 , V_100 ) ;
}
V_256:
V_92 = V_243 -> V_92 ;
V_120 = V_92 -> V_121 ;
if ( V_92 -> V_260 > V_92 -> V_261 ) {
F_31 ( V_10 , L_94
L_95
L_96 ,
V_92 -> V_261 ,
V_92 -> V_260 ) ;
V_92 -> V_260 = 0 ;
if ( V_243 -> V_92 -> V_262 & V_263 )
* V_116 = - V_264 ;
else
* V_116 = 0 ;
}
F_70 ( & V_243 -> V_83 ) ;
if ( ! F_39 ( & V_243 -> V_136 ) )
F_70 ( & V_243 -> V_136 ) ;
V_120 -> V_122 ++ ;
if ( V_120 -> V_122 == V_120 -> V_124 ) {
V_48 = 1 ;
if ( F_56 ( V_92 -> V_125 ) == V_126 ) {
F_35 ( V_10 ) -> V_127 . V_128 -- ;
if ( F_35 ( V_10 ) -> V_127 . V_128
== 0 ) {
if ( V_10 -> V_36 & V_129 )
F_57 () ;
}
}
}
}
return V_48 ;
}
static int F_129 ( struct V_9 * V_10 , struct V_95 * V_243 ,
union V_3 * V_244 , struct V_251 * V_131 ,
struct V_74 * V_75 , int * V_116 )
{
struct V_99 * V_253 ;
struct V_11 * V_100 ;
unsigned int V_70 ;
int V_71 ;
struct V_101 * V_102 ;
T_2 V_246 ;
V_70 = F_65 ( F_3 ( V_131 -> V_66 ) ) ;
V_253 = V_10 -> V_76 [ V_70 ] ;
V_71 = F_127 ( F_3 ( V_131 -> V_66 ) ) - 1 ;
V_100 = F_128 ( V_75 , F_47 ( V_131 -> V_254 ) ) ;
V_102 = F_46 ( V_10 , V_253 -> V_106 , V_71 ) ;
V_246 = F_78 ( F_3 ( V_131 -> V_255 ) ) ;
switch ( V_246 ) {
case V_150 :
if ( V_244 == V_100 -> V_25 ) {
F_31 ( V_10 , L_97
L_98 ) ;
* V_116 = - V_56 ;
} else if ( V_244 != V_243 -> F_4 ) {
F_31 ( V_10 , L_99
L_98 ) ;
* V_116 = - V_56 ;
} else {
* V_116 = 0 ;
}
break;
case V_265 :
if ( V_243 -> V_92 -> V_262 & V_263 )
* V_116 = - V_264 ;
else
* V_116 = 0 ;
break;
case V_257 :
case V_258 :
return F_126 ( V_10 , V_243 , V_244 , V_131 , V_75 , V_116 , false ) ;
default:
if ( ! F_124 ( V_10 ,
V_102 , V_246 ) )
break;
F_15 ( V_10 , L_100
L_101 ,
V_246 , V_71 ) ;
case V_259 :
if ( V_244 != V_100 -> V_25 &&
V_244 != V_243 -> F_4 )
V_243 -> V_92 -> V_260 =
V_243 -> V_92 -> V_261
- F_130 ( F_3 ( V_131 -> V_255 ) ) ;
else
V_243 -> V_92 -> V_260 = 0 ;
F_121 ( V_10 ,
V_70 , V_71 , 0 , V_243 , V_244 ) ;
return F_126 ( V_10 , V_243 , V_244 , V_131 , V_75 , V_116 , true ) ;
}
if ( V_244 != V_100 -> V_25 ) {
if ( V_244 == V_243 -> F_4 ) {
if ( V_243 -> V_92 -> V_260 != 0 ) {
if ( ( * V_116 == - V_266 || * V_116 == 0 ) &&
( V_243 -> V_92 -> V_262
& V_263 ) )
* V_116 = - V_264 ;
} else {
V_243 -> V_92 -> V_260 =
V_243 -> V_92 -> V_261 ;
}
} else {
V_243 -> V_92 -> V_260 =
V_243 -> V_92 -> V_261 -
F_130 ( F_3 ( V_131 -> V_255 ) ) ;
F_15 ( V_10 , L_102
L_103 ) ;
return 0 ;
}
}
return F_126 ( V_10 , V_243 , V_244 , V_131 , V_75 , V_116 , false ) ;
}
static int F_131 ( struct V_9 * V_10 , struct V_95 * V_243 ,
union V_3 * V_244 , struct V_251 * V_131 ,
struct V_74 * V_75 , int * V_116 )
{
struct V_11 * V_100 ;
struct V_120 * V_120 ;
int V_267 ;
int V_268 = 0 ;
union V_3 * V_110 ;
struct V_1 * V_89 ;
struct V_269 * V_270 ;
T_2 V_246 ;
bool V_271 = false ;
V_100 = F_128 ( V_75 , F_47 ( V_131 -> V_254 ) ) ;
V_246 = F_78 ( F_3 ( V_131 -> V_255 ) ) ;
V_120 = V_243 -> V_92 -> V_121 ;
V_267 = V_120 -> V_122 ;
V_270 = & V_243 -> V_92 -> V_272 [ V_267 ] ;
switch ( V_246 ) {
case V_150 :
if ( F_130 ( F_3 ( V_131 -> V_255 ) ) == 0 ) {
V_270 -> V_116 = 0 ;
break;
}
if ( ( V_10 -> V_36 & V_273 ) )
V_246 = V_265 ;
case V_265 :
V_270 -> V_116 = V_243 -> V_92 -> V_262 & V_263 ?
- V_264 : 0 ;
break;
case V_274 :
V_270 -> V_116 = - V_275 ;
V_271 = true ;
break;
case V_276 :
case V_248 :
V_270 -> V_116 = - V_277 ;
V_271 = true ;
break;
case V_278 :
case V_259 :
case V_247 :
V_270 -> V_116 = - V_279 ;
V_271 = true ;
break;
case V_258 :
case V_257 :
break;
default:
V_270 -> V_116 = - 1 ;
break;
}
if ( V_246 == V_150 || V_271 ) {
V_270 -> V_260 = V_270 -> V_124 ;
V_243 -> V_92 -> V_260 += V_270 -> V_124 ;
} else {
for ( V_110 = V_100 -> V_25 ,
V_89 = V_100 -> V_24 ; V_110 != V_244 ;
F_7 ( V_10 , V_100 , & V_89 , & V_110 ) ) {
if ( ! F_132 ( V_110 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_110 -> V_30 . V_31 [ 3 ] ) )
V_268 += F_130 ( F_3 ( V_110 -> V_30 . V_31 [ 2 ] ) ) ;
}
V_268 += F_130 ( F_3 ( V_110 -> V_30 . V_31 [ 2 ] ) ) -
F_130 ( F_3 ( V_131 -> V_255 ) ) ;
if ( V_246 != V_257 ) {
V_270 -> V_260 = V_268 ;
V_243 -> V_92 -> V_260 += V_268 ;
}
}
return F_126 ( V_10 , V_243 , V_244 , V_131 , V_75 , V_116 , false ) ;
}
static int F_133 ( struct V_9 * V_10 , struct V_95 * V_243 ,
struct V_251 * V_131 ,
struct V_74 * V_75 , int * V_116 )
{
struct V_11 * V_100 ;
struct V_120 * V_120 ;
struct V_269 * V_270 ;
int V_267 ;
V_100 = F_128 ( V_75 , F_47 ( V_131 -> V_254 ) ) ;
V_120 = V_243 -> V_92 -> V_121 ;
V_267 = V_120 -> V_122 ;
V_270 = & V_243 -> V_92 -> V_272 [ V_267 ] ;
V_270 -> V_116 = - V_280 ;
V_270 -> V_260 = 0 ;
while ( V_100 -> V_25 != V_243 -> F_4 )
F_8 ( V_10 , V_100 ) ;
F_8 ( V_10 , V_100 ) ;
return F_126 ( V_10 , V_243 , NULL , V_131 , V_75 , V_116 , true ) ;
}
static int F_134 ( struct V_9 * V_10 , struct V_95 * V_243 ,
union V_3 * V_244 , struct V_251 * V_131 ,
struct V_74 * V_75 , int * V_116 )
{
struct V_11 * V_100 ;
union V_3 * V_110 ;
struct V_1 * V_89 ;
T_2 V_246 ;
V_100 = F_128 ( V_75 , F_47 ( V_131 -> V_254 ) ) ;
V_246 = F_78 ( F_3 ( V_131 -> V_255 ) ) ;
switch ( V_246 ) {
case V_150 :
if ( V_244 != V_243 -> F_4 ||
F_130 ( F_3 ( V_131 -> V_255 ) ) != 0 ) {
F_31 ( V_10 , L_104
L_105 ) ;
if ( V_243 -> V_92 -> V_262 & V_263 )
* V_116 = - V_264 ;
else
* V_116 = 0 ;
if ( ( V_10 -> V_36 & V_273 ) )
V_246 = V_265 ;
} else {
* V_116 = 0 ;
}
break;
case V_265 :
if ( V_243 -> V_92 -> V_262 & V_263 )
* V_116 = - V_264 ;
else
* V_116 = 0 ;
break;
default:
break;
}
if ( V_246 == V_265 )
F_15 ( V_10 , L_106
L_107 ,
V_243 -> V_92 -> V_75 -> V_94 . V_281 ,
V_243 -> V_92 -> V_261 ,
F_130 ( F_3 ( V_131 -> V_255 ) ) ) ;
if ( V_244 == V_243 -> F_4 ) {
if ( F_130 ( F_3 ( V_131 -> V_255 ) ) != 0 ) {
V_243 -> V_92 -> V_260 =
V_243 -> V_92 -> V_261 -
F_130 ( F_3 ( V_131 -> V_255 ) ) ;
if ( V_243 -> V_92 -> V_261 <
V_243 -> V_92 -> V_260 ) {
F_31 ( V_10 , L_108
L_109 ,
F_130 ( F_3 ( V_131 -> V_255 ) ) ) ;
V_243 -> V_92 -> V_260 = 0 ;
if ( V_243 -> V_92 -> V_262 & V_263 )
* V_116 = - V_264 ;
else
* V_116 = 0 ;
}
if ( * V_116 == - V_266 ) {
if ( V_243 -> V_92 -> V_262 & V_263 )
* V_116 = - V_264 ;
else
* V_116 = 0 ;
}
} else {
V_243 -> V_92 -> V_260 =
V_243 -> V_92 -> V_261 ;
if ( * V_116 == - V_264 )
* V_116 = 0 ;
}
} else {
V_243 -> V_92 -> V_260 = 0 ;
for ( V_110 = V_100 -> V_25 , V_89 = V_100 -> V_24 ;
V_110 != V_244 ;
F_7 ( V_10 , V_100 , & V_89 , & V_110 ) ) {
if ( ! F_132 ( V_110 -> V_30 . V_31 [ 3 ] ) &&
! F_5 ( V_110 -> V_30 . V_31 [ 3 ] ) )
V_243 -> V_92 -> V_260 +=
F_130 ( F_3 ( V_110 -> V_30 . V_31 [ 2 ] ) ) ;
}
if ( V_246 != V_257 )
V_243 -> V_92 -> V_260 +=
F_130 ( F_3 ( V_110 -> V_30 . V_31 [ 2 ] ) ) -
F_130 ( F_3 ( V_131 -> V_255 ) ) ;
}
return F_126 ( V_10 , V_243 , V_244 , V_131 , V_75 , V_116 , false ) ;
}
static int F_135 ( struct V_9 * V_10 ,
struct V_251 * V_131 )
__releases( &xhci->lock
static int F_136 ( struct V_9 * V_10 )
{
union V_3 * V_131 ;
int V_282 = 1 ;
int V_48 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_25 ) {
V_10 -> V_177 |= 1 << 1 ;
return 0 ;
}
V_131 = V_10 -> V_13 -> V_25 ;
if ( ( F_3 ( V_131 -> V_200 . V_66 ) & V_38 ) !=
V_10 -> V_13 -> V_27 ) {
V_10 -> V_177 |= 1 << 2 ;
return 0 ;
}
F_137 () ;
switch ( ( F_3 ( V_131 -> V_200 . V_66 ) & V_178 ) ) {
case F_49 ( V_283 ) :
F_94 ( V_10 , & V_131 -> V_200 ) ;
break;
case F_49 ( V_284 ) :
F_106 ( V_10 , V_131 ) ;
V_282 = 0 ;
break;
case F_49 ( V_285 ) :
V_48 = F_135 ( V_10 , & V_131 -> V_286 ) ;
if ( V_48 < 0 )
V_10 -> V_177 |= 1 << 9 ;
else
V_282 = 0 ;
break;
case F_49 ( V_287 ) :
F_104 ( V_10 , V_131 ) ;
break;
default:
if ( ( F_3 ( V_131 -> V_200 . V_66 ) & V_178 ) >=
F_49 ( 48 ) )
F_101 ( V_10 , V_131 ) ;
else
V_10 -> V_177 |= 1 << 3 ;
}
if ( V_10 -> V_54 & V_55 ) {
F_15 ( V_10 , L_110
L_111 ) ;
return 0 ;
}
if ( V_282 )
F_8 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_138 ( struct V_118 * V_119 )
{
struct V_9 * V_10 = F_139 ( V_119 ) ;
T_2 V_116 ;
union V_3 * V_4 ;
T_3 V_47 ;
union V_3 * V_288 ;
T_1 V_107 ;
F_62 ( & V_10 -> V_67 ) ;
V_4 = V_10 -> V_13 -> V_25 ;
V_116 = F_17 ( V_10 , & V_10 -> V_49 -> V_116 ) ;
if ( V_116 == 0xffffffff )
goto V_289;
if ( ! ( V_116 & V_290 ) ) {
F_59 ( & V_10 -> V_67 ) ;
return V_291 ;
}
if ( V_116 & V_292 ) {
F_31 ( V_10 , L_112 ) ;
F_24 ( V_10 ) ;
V_289:
F_59 ( & V_10 -> V_67 ) ;
return - V_56 ;
}
V_116 |= V_290 ;
F_16 ( V_10 , V_116 , & V_10 -> V_49 -> V_116 ) ;
if ( V_119 -> V_293 ) {
T_2 V_294 ;
V_294 = F_17 ( V_10 , & V_10 -> V_295 -> V_294 ) ;
V_294 |= V_296 ;
F_16 ( V_10 , V_294 , & V_10 -> V_295 -> V_294 ) ;
}
if ( V_10 -> V_54 & V_55 ) {
F_15 ( V_10 , L_113
L_114 ) ;
V_47 = F_19 ( V_10 , & V_10 -> V_295 -> V_297 ) ;
F_20 ( V_10 , V_47 | V_298 ,
& V_10 -> V_295 -> V_297 ) ;
F_59 ( & V_10 -> V_67 ) ;
return V_299 ;
}
V_288 = V_10 -> V_13 -> V_25 ;
while ( F_136 ( V_10 ) > 0 ) {}
V_47 = F_19 ( V_10 , & V_10 -> V_295 -> V_297 ) ;
if ( V_288 != V_10 -> V_13 -> V_25 ) {
V_107 = F_1 ( V_10 -> V_13 -> V_24 ,
V_10 -> V_13 -> V_25 ) ;
if ( V_107 == 0 )
F_31 ( V_10 , L_115
L_116 ) ;
V_47 &= V_300 ;
V_47 |= ( ( T_3 ) V_107 & ( T_3 ) ~ V_300 ) ;
}
V_47 |= V_298 ;
F_20 ( V_10 , V_47 , & V_10 -> V_295 -> V_297 ) ;
F_59 ( & V_10 -> V_67 ) ;
return V_299 ;
}
T_7 F_140 ( int V_293 , struct V_118 * V_119 )
{
return F_138 ( V_119 ) ;
}
static void F_141 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_28 ,
T_2 V_301 , T_2 V_302 , T_2 V_303 , T_2 V_304 )
{
struct V_90 * V_4 ;
V_4 = & V_12 -> V_20 -> V_30 ;
V_4 -> V_31 [ 0 ] = F_11 ( V_301 ) ;
V_4 -> V_31 [ 1 ] = F_11 ( V_302 ) ;
V_4 -> V_31 [ 2 ] = F_11 ( V_303 ) ;
V_4 -> V_31 [ 3 ] = F_11 ( V_304 ) ;
F_9 ( V_10 , V_12 , V_28 ) ;
}
static int F_142 ( struct V_9 * V_10 , struct V_11 * V_100 ,
T_2 V_78 , unsigned int V_39 , T_8 V_305 )
{
unsigned int V_306 ;
switch ( V_78 ) {
case V_307 :
F_31 ( V_10 , L_117 ) ;
return - V_308 ;
case V_309 :
F_31 ( V_10 , L_118 ) ;
return - V_310 ;
case V_250 :
F_15 ( V_10 , L_119 ) ;
case V_311 :
case V_312 :
break;
default:
F_22 ( V_10 , L_120 ) ;
return - V_310 ;
}
while ( 1 ) {
if ( F_13 ( V_10 , V_100 , V_39 ) )
break;
if ( V_100 == V_10 -> V_50 ) {
F_22 ( V_10 , L_121 ) ;
return - V_63 ;
}
F_15 ( V_10 , L_122
L_123 ) ;
V_306 = V_39 - V_100 -> V_26 ;
if ( F_143 ( V_10 , V_100 , V_306 ,
V_305 ) ) {
F_22 ( V_10 , L_124 ) ;
return - V_63 ;
}
}
if ( F_6 ( V_100 ) ) {
struct V_11 * V_12 = V_100 ;
union V_3 * V_14 ;
V_14 = V_12 -> V_20 ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
if ( ! F_10 ( V_10 ) &&
! ( V_12 -> type == V_35 &&
( V_10 -> V_36 & V_37 ) ) )
V_14 -> V_16 . V_17 &= F_11 ( ~ V_32 ) ;
else
V_14 -> V_16 . V_17 |= F_11 ( V_32 ) ;
F_12 () ;
V_14 -> V_16 . V_17 ^= F_11 ( V_38 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_33 , V_14 ) ) {
V_12 -> V_27 = ( V_12 -> V_27 ? 0 : 1 ) ;
}
V_12 -> V_33 = V_12 -> V_33 -> V_14 ;
V_12 -> V_20 = V_12 -> V_33 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
return 0 ;
}
static int F_144 ( struct V_9 * V_10 ,
struct V_99 * V_253 ,
unsigned int V_71 ,
unsigned int V_72 ,
unsigned int V_39 ,
struct V_92 * V_92 ,
unsigned int V_313 ,
T_8 V_305 )
{
int V_48 ;
struct V_120 * V_120 ;
struct V_95 * V_243 ;
struct V_11 * V_100 ;
struct V_101 * V_102 = F_46 ( V_10 , V_253 -> V_106 , V_71 ) ;
V_100 = F_76 ( V_253 , V_71 , V_72 ) ;
if ( ! V_100 ) {
F_15 ( V_10 , L_125 ,
V_72 ) ;
return - V_310 ;
}
V_48 = F_142 ( V_10 , V_100 ,
F_3 ( V_102 -> V_154 ) & V_155 ,
V_39 , V_305 ) ;
if ( V_48 )
return V_48 ;
V_120 = V_92 -> V_121 ;
V_243 = V_120 -> V_243 [ V_313 ] ;
F_27 ( & V_243 -> V_83 ) ;
F_27 ( & V_243 -> V_136 ) ;
if ( V_313 == 0 ) {
V_48 = F_145 ( F_55 ( V_92 -> V_93 -> V_123 ) , V_92 ) ;
if ( F_32 ( V_48 ) )
return V_48 ;
}
V_243 -> V_92 = V_92 ;
F_28 ( & V_243 -> V_83 , & V_100 -> V_83 ) ;
V_243 -> V_88 = V_100 -> V_33 ;
V_243 -> V_111 = V_100 -> V_20 ;
V_120 -> V_243 [ V_313 ] = V_243 ;
return 0 ;
}
static unsigned int F_146 ( struct V_9 * V_10 , struct V_92 * V_92 )
{
int V_314 , V_39 , V_315 , V_212 , V_141 ;
struct V_316 * V_317 ;
V_317 = NULL ;
V_314 = V_92 -> V_318 ;
V_212 = V_92 -> V_261 ;
V_39 = 0 ;
F_147 (urb->sg, sg, num_sgs, i) {
unsigned int V_268 = F_148 ( V_317 ) ;
V_315 = V_319 -
( F_149 ( V_317 ) & ( V_319 - 1 ) ) ;
V_315 &= V_319 - 1 ;
if ( V_315 != 0 )
V_39 ++ ;
while ( V_315 < F_148 ( V_317 ) && V_315 < V_212 ) {
V_39 ++ ;
V_315 += V_319 ;
}
V_268 = F_150 ( int , V_268 , V_212 ) ;
V_212 -= V_268 ;
if ( V_212 == 0 )
break;
}
return V_39 ;
}
static void F_151 ( struct V_92 * V_92 , int V_39 , int V_315 )
{
if ( V_39 != 0 )
F_152 ( & V_92 -> V_93 -> V_93 , L_126
L_127 , V_320 ,
V_92 -> V_75 -> V_94 . V_281 , V_39 ) ;
if ( V_315 != V_92 -> V_261 )
F_152 ( & V_92 -> V_93 -> V_93 , L_128
L_129 ,
V_320 ,
V_92 -> V_75 -> V_94 . V_281 ,
V_315 , V_315 ,
V_92 -> V_261 ,
V_92 -> V_261 ) ;
}
static void F_153 ( struct V_9 * V_10 , int V_70 ,
unsigned int V_71 , unsigned int V_72 , int V_321 ,
struct V_90 * V_237 )
{
F_12 () ;
if ( V_321 )
V_237 -> V_31 [ 3 ] |= F_11 ( V_321 ) ;
else
V_237 -> V_31 [ 3 ] &= F_11 ( ~ V_38 ) ;
F_36 ( V_10 , V_70 , V_71 , V_72 ) ;
}
int F_154 ( struct V_9 * V_10 , T_8 V_305 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_101 * V_102 = F_46 ( V_10 ,
V_10 -> V_76 [ V_70 ] -> V_106 , V_71 ) ;
int V_322 ;
int V_323 ;
V_322 = F_155 ( F_3 ( V_102 -> V_154 ) ) ;
V_323 = V_92 -> V_324 ;
if ( V_92 -> V_93 -> V_206 == V_325 ||
V_92 -> V_93 -> V_206 == V_326 )
V_323 *= 8 ;
if ( V_322 != V_323 ) {
if ( F_156 () )
F_157 ( & V_92 -> V_93 -> V_93 , L_130
L_131
L_132 ,
V_323 ,
V_323 == 1 ? L_133 : L_134 ,
V_322 ,
V_322 == 1 ? L_133 : L_134 ) ;
V_92 -> V_324 = V_322 ;
if ( V_92 -> V_93 -> V_206 == V_325 ||
V_92 -> V_93 -> V_206 == V_326 )
V_92 -> V_324 /= 8 ;
}
return F_158 ( V_10 , V_305 , V_92 , V_70 , V_71 ) ;
}
static T_2 F_159 ( unsigned int V_327 )
{
T_2 V_328 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_327 >> 10 ) >= V_328 )
return V_328 << 17 ;
else
return ( V_327 >> 10 ) << 17 ;
}
static T_2 F_160 ( int V_315 , int V_329 ,
unsigned int V_330 , struct V_92 * V_92 )
{
int V_331 ;
if ( V_315 == 0 && V_329 == 0 )
return 0 ;
V_331 = ( V_315 + V_329 ) /
F_161 ( & V_92 -> V_75 -> V_94 ) ;
return F_159 ( V_330 - V_331 ) ;
}
static int F_162 ( struct V_9 * V_10 , T_8 V_305 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_11 * V_100 ;
unsigned int V_39 ;
struct V_120 * V_120 ;
struct V_95 * V_243 ;
struct V_316 * V_317 ;
int V_314 ;
int V_329 , V_332 , V_315 ;
unsigned int V_330 ;
bool V_111 ;
T_3 V_21 ;
bool V_28 ;
struct V_90 * V_237 ;
int V_321 ;
V_100 = F_42 ( V_10 , V_92 ) ;
if ( ! V_100 )
return - V_310 ;
V_39 = F_146 ( V_10 , V_92 ) ;
V_314 = V_92 -> V_318 ;
V_330 = F_163 ( V_92 -> V_261 ,
F_161 ( & V_92 -> V_75 -> V_94 ) ) ;
V_329 = F_144 ( V_10 , V_10 -> V_76 [ V_70 ] ,
V_71 , V_92 -> V_72 ,
V_39 , V_92 , 0 , V_305 ) ;
if ( V_329 < 0 )
return V_329 ;
V_120 = V_92 -> V_121 ;
V_243 = V_120 -> V_243 [ 0 ] ;
V_237 = & V_100 -> V_20 -> V_30 ;
V_321 = V_100 -> V_27 ;
V_315 = 0 ;
V_317 = V_92 -> V_317 ;
V_21 = ( T_3 ) F_149 ( V_317 ) ;
V_332 = F_148 ( V_317 ) ;
V_329 = V_319 - ( V_21 & ( V_319 - 1 ) ) ;
V_329 = F_150 ( int , V_329 , V_332 ) ;
if ( V_329 > V_92 -> V_261 )
V_329 = V_92 -> V_261 ;
V_111 = true ;
do {
T_2 V_31 = 0 ;
T_2 V_333 = 0 ;
T_2 V_327 = 0 ;
if ( V_111 ) {
V_111 = false ;
if ( V_321 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_100 -> V_27 ;
if ( V_39 > 1 ) {
V_31 |= V_32 ;
} else {
V_243 -> F_4 = V_100 -> V_20 ;
V_31 |= V_334 ;
}
if ( F_164 ( V_92 ) )
V_31 |= V_335 ;
if ( V_319 -
( V_21 & ( V_319 - 1 ) ) < V_329 ) {
F_31 ( V_10 , L_135 ) ;
F_15 ( V_10 , L_136 ,
( unsigned int ) ( V_21 + V_319 ) & ~ ( V_319 - 1 ) ,
( unsigned int ) V_21 + V_329 ) ;
}
if ( V_10 -> V_336 < 0x100 ) {
V_327 = F_159 (
V_92 -> V_261 -
V_315 ) ;
} else {
V_327 = F_160 ( V_315 ,
V_329 , V_330 , V_92 ) ;
}
V_333 = F_130 ( V_329 ) |
V_327 |
F_165 ( 0 ) ;
if ( V_39 > 1 )
V_28 = true ;
else
V_28 = false ;
F_141 ( V_10 , V_100 , V_28 ,
F_166 ( V_21 ) ,
F_167 ( V_21 ) ,
V_333 ,
V_31 | F_49 ( V_337 ) ) ;
-- V_39 ;
V_315 += V_329 ;
V_332 -= V_329 ;
if ( V_332 == 0 ) {
-- V_314 ;
if ( V_314 == 0 )
break;
V_317 = F_168 ( V_317 ) ;
V_21 = ( T_3 ) F_149 ( V_317 ) ;
V_332 = F_148 ( V_317 ) ;
} else {
V_21 += V_329 ;
}
V_329 = V_319 -
( V_21 & ( V_319 - 1 ) ) ;
V_329 = F_150 ( int , V_329 , V_332 ) ;
if ( V_315 + V_329 > V_92 -> V_261 )
V_329 =
V_92 -> V_261 - V_315 ;
} while ( V_315 < V_92 -> V_261 );
F_151 ( V_92 , V_39 , V_315 ) ;
F_153 ( V_10 , V_70 , V_71 , V_92 -> V_72 ,
V_321 , V_237 ) ;
return 0 ;
}
int F_158 ( struct V_9 * V_10 , T_8 V_305 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_11 * V_100 ;
struct V_120 * V_120 ;
struct V_95 * V_243 ;
int V_39 ;
struct V_90 * V_237 ;
bool V_111 ;
bool V_28 ;
int V_321 ;
T_2 V_31 , V_333 ;
int V_315 , V_329 , V_48 ;
unsigned int V_330 ;
T_3 V_21 ;
if ( V_92 -> V_314 )
return F_162 ( V_10 , V_305 , V_92 , V_70 , V_71 ) ;
V_100 = F_42 ( V_10 , V_92 ) ;
if ( ! V_100 )
return - V_310 ;
V_39 = 0 ;
V_315 = V_319 -
( V_92 -> V_338 & ( V_319 - 1 ) ) ;
V_315 &= V_319 - 1 ;
if ( V_315 != 0 || V_92 -> V_261 == 0 )
V_39 ++ ;
while ( V_315 < V_92 -> V_261 ) {
V_39 ++ ;
V_315 += V_319 ;
}
V_48 = F_144 ( V_10 , V_10 -> V_76 [ V_70 ] ,
V_71 , V_92 -> V_72 ,
V_39 , V_92 , 0 , V_305 ) ;
if ( V_48 < 0 )
return V_48 ;
V_120 = V_92 -> V_121 ;
V_243 = V_120 -> V_243 [ 0 ] ;
V_237 = & V_100 -> V_20 -> V_30 ;
V_321 = V_100 -> V_27 ;
V_315 = 0 ;
V_330 = F_163 ( V_92 -> V_261 ,
F_161 ( & V_92 -> V_75 -> V_94 ) ) ;
V_21 = ( T_3 ) V_92 -> V_338 ;
V_329 = V_319 -
( V_92 -> V_338 & ( V_319 - 1 ) ) ;
if ( V_329 > V_92 -> V_261 )
V_329 = V_92 -> V_261 ;
V_111 = true ;
do {
T_2 V_327 = 0 ;
V_31 = 0 ;
if ( V_111 ) {
V_111 = false ;
if ( V_321 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_100 -> V_27 ;
if ( V_39 > 1 ) {
V_31 |= V_32 ;
} else {
V_243 -> F_4 = V_100 -> V_20 ;
V_31 |= V_334 ;
}
if ( F_164 ( V_92 ) )
V_31 |= V_335 ;
if ( V_10 -> V_336 < 0x100 ) {
V_327 = F_159 (
V_92 -> V_261 -
V_315 ) ;
} else {
V_327 = F_160 ( V_315 ,
V_329 , V_330 , V_92 ) ;
}
V_333 = F_130 ( V_329 ) |
V_327 |
F_165 ( 0 ) ;
if ( V_39 > 1 )
V_28 = true ;
else
V_28 = false ;
F_141 ( V_10 , V_100 , V_28 ,
F_166 ( V_21 ) ,
F_167 ( V_21 ) ,
V_333 ,
V_31 | F_49 ( V_337 ) ) ;
-- V_39 ;
V_315 += V_329 ;
V_21 += V_329 ;
V_329 = V_92 -> V_261 - V_315 ;
if ( V_329 > V_319 )
V_329 = V_319 ;
} while ( V_315 < V_92 -> V_261 );
F_151 ( V_92 , V_39 , V_315 ) ;
F_153 ( V_10 , V_70 , V_71 , V_92 -> V_72 ,
V_321 , V_237 ) ;
return 0 ;
}
int F_169 ( struct V_9 * V_10 , T_8 V_305 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_11 * V_100 ;
int V_39 ;
int V_48 ;
struct V_339 * V_340 ;
struct V_90 * V_237 ;
int V_321 ;
T_2 V_31 , V_333 ;
struct V_120 * V_120 ;
struct V_95 * V_243 ;
V_100 = F_42 ( V_10 , V_92 ) ;
if ( ! V_100 )
return - V_310 ;
if ( ! V_92 -> V_341 )
return - V_310 ;
V_39 = 2 ;
if ( V_92 -> V_261 > 0 )
V_39 ++ ;
V_48 = F_144 ( V_10 , V_10 -> V_76 [ V_70 ] ,
V_71 , V_92 -> V_72 ,
V_39 , V_92 , 0 , V_305 ) ;
if ( V_48 < 0 )
return V_48 ;
V_120 = V_92 -> V_121 ;
V_243 = V_120 -> V_243 [ 0 ] ;
V_237 = & V_100 -> V_20 -> V_30 ;
V_321 = V_100 -> V_27 ;
V_340 = (struct V_339 * ) V_92 -> V_341 ;
V_31 = 0 ;
V_31 |= V_342 | F_49 ( V_343 ) ;
if ( V_321 == 0 )
V_31 |= 0x1 ;
if ( V_10 -> V_336 == 0x100 ) {
if ( V_92 -> V_261 > 0 ) {
if ( V_340 -> V_344 & V_345 )
V_31 |= F_170 ( V_346 ) ;
else
V_31 |= F_170 ( V_347 ) ;
}
}
F_141 ( V_10 , V_100 , true ,
V_340 -> V_344 | V_340 -> V_348 << 8 | F_171 ( V_340 -> V_349 ) << 16 ,
F_171 ( V_340 -> V_350 ) | F_171 ( V_340 -> V_351 ) << 16 ,
F_130 ( 8 ) | F_165 ( 0 ) ,
V_31 ) ;
if ( F_164 ( V_92 ) )
V_31 = V_335 | F_49 ( V_352 ) ;
else
V_31 = F_49 ( V_352 ) ;
V_333 = F_130 ( V_92 -> V_261 ) |
F_159 ( V_92 -> V_261 ) |
F_165 ( 0 ) ;
if ( V_92 -> V_261 > 0 ) {
if ( V_340 -> V_344 & V_345 )
V_31 |= V_353 ;
F_141 ( V_10 , V_100 , true ,
F_166 ( V_92 -> V_338 ) ,
F_167 ( V_92 -> V_338 ) ,
V_333 ,
V_31 | V_100 -> V_27 ) ;
}
V_243 -> F_4 = V_100 -> V_20 ;
if ( V_92 -> V_261 > 0 && V_340 -> V_344 & V_345 )
V_31 = 0 ;
else
V_31 = V_353 ;
F_141 ( V_10 , V_100 , false ,
0 ,
0 ,
F_165 ( 0 ) ,
V_31 | V_334 | F_49 ( V_354 ) | V_100 -> V_27 ) ;
F_153 ( V_10 , V_70 , V_71 , 0 ,
V_321 , V_237 ) ;
return 0 ;
}
static int F_172 ( struct V_9 * V_10 ,
struct V_92 * V_92 , int V_141 )
{
int V_39 = 0 ;
T_3 V_21 , V_355 ;
V_21 = ( T_3 ) ( V_92 -> V_338 + V_92 -> V_272 [ V_141 ] . V_356 ) ;
V_355 = V_92 -> V_272 [ V_141 ] . V_124 ;
V_39 = F_173 ( V_355 + ( V_21 & ( V_319 - 1 ) ) ,
V_319 ) ;
if ( V_39 == 0 )
V_39 ++ ;
return V_39 ;
}
static unsigned int F_174 ( struct V_9 * V_10 ,
struct V_208 * V_209 ,
struct V_92 * V_92 , unsigned int V_330 )
{
unsigned int V_357 ;
if ( V_10 -> V_336 < 0x100 || V_209 -> V_206 != V_358 )
return 0 ;
V_357 = V_92 -> V_75 -> V_359 . V_360 ;
return F_163 ( V_330 , V_357 + 1 ) - 1 ;
}
static unsigned int F_175 ( struct V_9 * V_10 ,
struct V_208 * V_209 ,
struct V_92 * V_92 , unsigned int V_330 )
{
unsigned int V_357 ;
unsigned int V_361 ;
if ( V_10 -> V_336 < 0x100 )
return 0 ;
switch ( V_209 -> V_206 ) {
case V_358 :
V_357 = V_92 -> V_75 -> V_359 . V_360 ;
V_361 = V_330 % ( V_357 + 1 ) ;
if ( V_361 == 0 )
return V_357 ;
return V_361 - 1 ;
default:
if ( V_330 == 0 )
return 0 ;
return V_330 - 1 ;
}
}
static int F_176 ( struct V_9 * V_10 , T_8 V_305 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_11 * V_100 ;
struct V_120 * V_120 ;
struct V_95 * V_243 ;
int V_362 , V_363 ;
struct V_90 * V_237 ;
bool V_111 ;
int V_321 ;
T_2 V_31 , V_333 ;
int V_315 , V_329 , V_355 , V_364 , V_48 ;
T_3 V_365 , V_21 ;
int V_141 , V_142 ;
bool V_28 ;
V_100 = V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_12 ;
V_362 = V_92 -> V_366 ;
if ( V_362 < 1 ) {
F_15 ( V_10 , L_137 ) ;
return - V_310 ;
}
V_365 = ( T_3 ) V_92 -> V_338 ;
V_237 = & V_100 -> V_20 -> V_30 ;
V_321 = V_100 -> V_27 ;
V_120 = V_92 -> V_121 ;
for ( V_141 = 0 ; V_141 < V_362 ; V_141 ++ ) {
unsigned int V_330 ;
unsigned int V_367 ;
unsigned int V_361 ;
V_111 = true ;
V_315 = 0 ;
V_21 = V_365 + V_92 -> V_272 [ V_141 ] . V_356 ;
V_355 = V_92 -> V_272 [ V_141 ] . V_124 ;
V_364 = V_355 ;
V_330 = F_163 ( V_355 ,
F_161 ( & V_92 -> V_75 -> V_94 ) ) ;
if ( V_330 == 0 )
V_330 ++ ;
V_367 = F_174 ( V_10 , V_92 -> V_93 , V_92 ,
V_330 ) ;
V_361 = F_175 ( V_10 ,
V_92 -> V_93 , V_92 , V_330 ) ;
V_363 = F_172 ( V_10 , V_92 , V_141 ) ;
V_48 = F_144 ( V_10 , V_10 -> V_76 [ V_70 ] , V_71 ,
V_92 -> V_72 , V_363 , V_92 , V_141 , V_305 ) ;
if ( V_48 < 0 ) {
if ( V_141 == 0 )
return V_48 ;
goto V_221;
}
V_243 = V_120 -> V_243 [ V_141 ] ;
for ( V_142 = 0 ; V_142 < V_363 ; V_142 ++ ) {
T_2 V_327 = 0 ;
V_31 = F_177 ( V_367 ) | F_178 ( V_361 ) ;
if ( V_111 ) {
V_31 |= F_49 ( V_368 ) ;
V_31 |= V_369 ;
if ( V_141 == 0 ) {
if ( V_321 == 0 )
V_31 |= 0x1 ;
} else
V_31 |= V_100 -> V_27 ;
V_111 = false ;
} else {
V_31 |= F_49 ( V_337 ) ;
V_31 |= V_100 -> V_27 ;
}
if ( F_164 ( V_92 ) )
V_31 |= V_335 ;
if ( V_142 < V_363 - 1 ) {
V_31 |= V_32 ;
V_28 = true ;
} else {
V_243 -> F_4 = V_100 -> V_20 ;
V_31 |= V_334 ;
if ( V_10 -> V_336 == 0x100 &&
! ( V_10 -> V_36 &
V_370 ) ) {
if ( V_141 < V_362 - 1 )
V_31 |= V_371 ;
}
V_28 = false ;
}
V_329 = V_319 -
( V_21 & ( ( 1 << V_372 ) - 1 ) ) ;
if ( V_329 > V_364 )
V_329 = V_364 ;
if ( V_10 -> V_336 < 0x100 ) {
V_327 = F_159 (
V_355 - V_315 ) ;
} else {
V_327 = F_160 (
V_315 , V_329 ,
V_330 , V_92 ) ;
}
V_333 = F_130 ( V_329 ) |
V_327 |
F_165 ( 0 ) ;
F_141 ( V_10 , V_100 , V_28 ,
F_166 ( V_21 ) ,
F_167 ( V_21 ) ,
V_333 ,
V_31 ) ;
V_315 += V_329 ;
V_21 += V_329 ;
V_364 -= V_329 ;
}
if ( V_315 != V_355 ) {
F_22 ( V_10 , L_138 ) ;
V_48 = - V_310 ;
goto V_221;
}
}
if ( F_35 ( V_10 ) -> V_127 . V_128 == 0 ) {
if ( V_10 -> V_36 & V_129 )
F_179 () ;
}
F_35 ( V_10 ) -> V_127 . V_128 ++ ;
F_153 ( V_10 , V_70 , V_71 , V_92 -> V_72 ,
V_321 , V_237 ) ;
return 0 ;
V_221:
for ( V_141 -- ; V_141 >= 0 ; V_141 -- )
F_70 ( & V_120 -> V_243 [ V_141 ] -> V_83 ) ;
V_120 -> V_243 [ 0 ] -> F_4 = V_100 -> V_20 ;
F_48 ( V_10 , V_100 , V_120 -> V_243 [ 0 ] , true ) ;
V_100 -> V_20 = V_120 -> V_243 [ 0 ] -> V_111 ;
V_100 -> V_33 = V_120 -> V_243 [ 0 ] -> V_88 ;
V_100 -> V_27 = V_321 ;
V_100 -> V_26 = V_100 -> V_145 ;
F_58 ( F_55 ( V_92 -> V_93 -> V_123 ) , V_92 ) ;
return V_48 ;
}
int F_180 ( struct V_9 * V_10 , T_8 V_305 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_99 * V_253 ;
struct V_11 * V_100 ;
struct V_101 * V_102 ;
int V_373 ;
int V_322 ;
int V_323 ;
int V_362 , V_39 , V_141 ;
int V_48 ;
V_253 = V_10 -> V_76 [ V_70 ] ;
V_100 = V_253 -> V_77 [ V_71 ] . V_12 ;
V_102 = F_46 ( V_10 , V_253 -> V_106 , V_71 ) ;
V_39 = 0 ;
V_362 = V_92 -> V_366 ;
for ( V_141 = 0 ; V_141 < V_362 ; V_141 ++ )
V_39 += F_172 ( V_10 , V_92 , V_141 ) ;
V_48 = F_142 ( V_10 , V_100 , F_3 ( V_102 -> V_154 ) & V_155 ,
V_39 , V_305 ) ;
if ( V_48 )
return V_48 ;
V_373 = F_17 ( V_10 , & V_10 -> V_374 -> V_375 ) ;
V_373 &= 0x3fff ;
V_92 -> V_373 = V_373 ;
if ( V_92 -> V_93 -> V_206 == V_325 ||
V_92 -> V_93 -> V_206 == V_326 )
V_92 -> V_373 >>= 3 ;
V_322 = F_155 ( F_3 ( V_102 -> V_154 ) ) ;
V_323 = V_92 -> V_324 ;
if ( V_92 -> V_93 -> V_206 == V_325 ||
V_92 -> V_93 -> V_206 == V_326 )
V_323 *= 8 ;
if ( V_322 != V_323 ) {
if ( F_156 () )
F_157 ( & V_92 -> V_93 -> V_93 , L_130
L_131
L_132 ,
V_323 ,
V_323 == 1 ? L_133 : L_134 ,
V_322 ,
V_322 == 1 ? L_133 : L_134 ) ;
V_92 -> V_324 = V_322 ;
if ( V_92 -> V_93 -> V_206 == V_325 ||
V_92 -> V_93 -> V_206 == V_326 )
V_92 -> V_324 /= 8 ;
}
V_100 -> V_145 = V_100 -> V_26 ;
return F_176 ( V_10 , V_305 , V_92 , V_70 , V_71 ) ;
}
static int F_181 ( struct V_9 * V_10 , T_2 V_301 , T_2 V_302 ,
T_2 V_303 , T_2 V_304 , bool V_376 )
{
int V_377 = V_10 -> V_378 ;
int V_48 ;
if ( ! V_376 )
V_377 ++ ;
V_48 = F_142 ( V_10 , V_10 -> V_50 , V_312 ,
V_377 , V_62 ) ;
if ( V_48 < 0 ) {
F_22 ( V_10 , L_139 ) ;
if ( V_376 )
F_22 ( V_10 , L_140
L_141 ) ;
return V_48 ;
}
F_141 ( V_10 , V_10 -> V_50 , false , V_301 , V_302 , V_303 ,
V_304 | V_10 -> V_50 -> V_27 ) ;
return 0 ;
}
int F_182 ( struct V_9 * V_10 , T_2 V_198 , T_2 V_70 )
{
return F_181 ( V_10 , 0 , 0 , 0 ,
F_49 ( V_198 ) | F_183 ( V_70 ) , false ) ;
}
int F_184 ( struct V_9 * V_10 , T_1 V_379 ,
T_2 V_70 )
{
return F_181 ( V_10 , F_166 ( V_379 ) ,
F_167 ( V_379 ) , 0 ,
F_49 ( V_191 ) | F_183 ( V_70 ) ,
false ) ;
}
int F_185 ( struct V_9 * V_10 ,
T_2 V_301 , T_2 V_302 , T_2 V_303 , T_2 V_304 )
{
return F_181 ( V_10 , V_301 , V_302 , V_303 , V_304 , false ) ;
}
int F_186 ( struct V_9 * V_10 , T_2 V_70 )
{
return F_181 ( V_10 , 0 , 0 , 0 ,
F_49 ( V_195 ) | F_183 ( V_70 ) ,
false ) ;
}
int F_81 ( struct V_9 * V_10 , T_1 V_379 ,
T_2 V_70 , bool V_376 )
{
return F_181 ( V_10 , F_166 ( V_379 ) ,
F_167 ( V_379 ) , 0 ,
F_49 ( V_183 ) | F_183 ( V_70 ) ,
V_376 ) ;
}
int F_187 ( struct V_9 * V_10 , T_1 V_379 ,
T_2 V_70 , bool V_376 )
{
return F_181 ( V_10 , F_166 ( V_379 ) ,
F_167 ( V_379 ) , 0 ,
F_49 ( V_190 ) | F_183 ( V_70 ) ,
V_376 ) ;
}
int F_188 ( struct V_9 * V_10 , int V_70 ,
unsigned int V_71 , int V_380 )
{
T_2 V_381 = F_183 ( V_70 ) ;
T_2 V_382 = F_189 ( V_71 ) ;
T_2 type = F_49 ( V_192 ) ;
T_2 V_383 = F_190 ( V_380 ) ;
return F_181 ( V_10 , 0 , 0 , 0 ,
V_381 | V_382 | type | V_383 , false ) ;
}
static int F_51 ( struct V_9 * V_10 , int V_70 ,
unsigned int V_71 , unsigned int V_72 ,
struct V_1 * V_24 ,
union V_3 * V_384 , T_2 V_27 )
{
T_1 V_21 ;
T_2 V_381 = F_183 ( V_70 ) ;
T_2 V_382 = F_189 ( V_71 ) ;
T_2 V_385 = F_191 ( V_72 ) ;
T_2 type = F_49 ( V_193 ) ;
struct V_74 * V_75 ;
V_21 = F_1 ( V_24 , V_384 ) ;
if ( V_21 == 0 ) {
F_31 ( V_10 , L_142 ) ;
F_31 ( V_10 , L_143 ,
V_24 , V_384 ) ;
return 0 ;
}
V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
if ( ( V_75 -> V_78 & V_80 ) ) {
F_31 ( V_10 , L_142 ) ;
F_31 ( V_10 , L_144 ) ;
return 0 ;
}
V_75 -> V_158 = V_24 ;
V_75 -> V_147 = V_384 ;
return F_181 ( V_10 , F_166 ( V_21 ) | V_27 ,
F_167 ( V_21 ) , V_385 ,
V_381 | V_382 | type , false ) ;
}
int F_122 ( struct V_9 * V_10 , int V_70 ,
unsigned int V_71 )
{
T_2 V_381 = F_183 ( V_70 ) ;
T_2 V_382 = F_189 ( V_71 ) ;
T_2 type = F_49 ( V_194 ) ;
return F_181 ( V_10 , 0 , 0 , 0 , V_381 | V_382 | type ,
false ) ;
}
