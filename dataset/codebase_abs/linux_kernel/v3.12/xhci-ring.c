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
unsigned long long V_22 ;
V_12 -> V_23 ++ ;
if ( V_12 -> type != V_24 &&
! F_4 ( V_10 , V_12 , V_12 -> V_25 , V_12 -> V_26 ) )
V_12 -> V_27 ++ ;
do {
if ( F_4 ( V_10 , V_12 , V_12 -> V_25 , V_12 -> V_26 ) ) {
if ( V_12 -> type == V_24 &&
F_2 ( V_10 , V_12 ,
V_12 -> V_25 , V_12 -> V_26 ) ) {
V_12 -> V_28 = ( V_12 -> V_28 ? 0 : 1 ) ;
}
V_12 -> V_25 = V_12 -> V_25 -> V_14 ;
V_12 -> V_26 = V_12 -> V_25 -> V_6 ;
} else {
V_12 -> V_26 ++ ;
}
} while ( F_4 ( V_10 , V_12 , V_12 -> V_25 , V_12 -> V_26 ) );
V_22 = ( unsigned long long ) F_1 ( V_12 -> V_25 , V_12 -> V_26 ) ;
}
static void F_10 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_29 )
{
T_2 V_30 ;
union V_3 * V_14 ;
unsigned long long V_22 ;
V_30 = F_3 ( V_12 -> V_20 -> V_31 . V_32 [ 3 ] ) & V_33 ;
if ( V_12 -> type != V_24 &&
! F_4 ( V_10 , V_12 , V_12 -> V_21 , V_12 -> V_20 ) )
V_12 -> V_27 -- ;
V_14 = ++ ( V_12 -> V_20 ) ;
V_12 -> V_34 ++ ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_21 , V_14 ) ) {
if ( V_12 -> type != V_24 ) {
if ( ! V_30 && ! V_29 )
break;
if ( ! ( V_12 -> type == V_35 &&
( V_10 -> V_36 & V_37 ) )
&& ! F_11 ( V_10 ) ) {
V_14 -> V_16 . V_17 &=
F_12 ( ~ V_33 ) ;
V_14 -> V_16 . V_17 |=
F_12 ( V_30 ) ;
}
F_13 () ;
V_14 -> V_16 . V_17 ^= F_12 ( V_38 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_21 , V_14 ) ) {
V_12 -> V_28 = ( V_12 -> V_28 ? 0 : 1 ) ;
}
}
V_12 -> V_21 = V_12 -> V_21 -> V_14 ;
V_12 -> V_20 = V_12 -> V_21 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
V_22 = ( unsigned long long ) F_1 ( V_12 -> V_21 , V_12 -> V_20 ) ;
}
static inline int F_14 ( struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned int V_39 )
{
int V_40 ;
if ( V_12 -> V_27 < V_39 )
return 0 ;
if ( V_12 -> type != V_41 && V_12 -> type != V_24 ) {
V_40 = V_12 -> V_26 - V_12 -> V_25 -> V_6 ;
if ( V_12 -> V_27 < V_39 + V_40 )
return 0 ;
}
return 1 ;
}
void F_15 ( struct V_9 * V_10 )
{
if ( ! ( V_10 -> V_42 & V_43 ) )
return;
F_16 ( V_10 , L_1 ) ;
F_17 ( V_10 , V_44 , & V_10 -> V_45 -> V_46 [ 0 ] ) ;
F_18 ( V_10 , & V_10 -> V_45 -> V_46 [ 0 ] ) ;
}
static int F_19 ( struct V_9 * V_10 )
{
T_3 V_47 ;
int V_48 ;
F_16 ( V_10 , L_2 ) ;
if ( ! ( V_10 -> V_42 & V_43 ) ) {
F_16 ( V_10 , L_3
L_4 ) ;
return 0 ;
}
V_47 = F_20 ( V_10 , & V_10 -> V_49 -> V_50 ) ;
if ( ! ( V_47 & V_51 ) ) {
F_16 ( V_10 , L_5 ) ;
return 0 ;
}
V_10 -> V_42 = V_52 ;
F_21 ( V_10 , V_47 | V_53 ,
& V_10 -> V_49 -> V_50 ) ;
V_48 = F_22 ( V_10 , & V_10 -> V_49 -> V_50 ,
V_51 , 0 , 5 * 1000 * 1000 ) ;
if ( V_48 < 0 ) {
F_23 ( V_10 , L_6
L_7 ) ;
V_10 -> V_54 |= V_55 ;
F_24 ( V_10 ) ;
F_25 ( V_10 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
struct V_57 * V_58 ,
union V_3 * V_59 )
{
struct V_60 * V_61 ;
V_61 = F_27 ( sizeof( struct V_60 ) , V_62 ) ;
if ( ! V_61 )
return - V_63 ;
F_28 ( & V_61 -> V_64 ) ;
V_61 -> V_58 = V_58 ;
V_61 -> V_59 = V_59 ;
F_29 ( & V_61 -> V_64 , & V_10 -> V_64 ) ;
return 0 ;
}
int F_30 ( struct V_9 * V_10 , struct V_57 * V_58 ,
union V_3 * V_59 )
{
int V_65 = 0 ;
unsigned long V_66 ;
F_31 ( & V_10 -> V_67 , V_66 ) ;
if ( V_10 -> V_54 & V_55 ) {
F_32 ( V_10 , L_8
L_9 ) ;
V_65 = - V_56 ;
goto V_68;
}
V_65 = F_26 ( V_10 , V_58 , V_59 ) ;
if ( V_65 ) {
F_32 ( V_10 , L_10 ) ;
goto V_68;
}
V_65 = F_19 ( V_10 ) ;
if ( V_65 ) {
F_23 ( V_10 , L_11 ) ;
if ( F_33 ( V_65 == - V_56 ) ) {
F_34 ( & V_10 -> V_67 , V_66 ) ;
F_35 ( F_36 ( V_10 ) -> V_69 ) ;
F_16 ( V_10 , L_12 ) ;
return V_65 ;
}
}
V_68:
F_34 ( & V_10 -> V_67 , V_66 ) ;
return V_65 ;
}
void F_37 ( struct V_9 * V_10 ,
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
F_17 ( V_10 , F_38 ( V_71 , V_72 ) , V_73 ) ;
}
static void F_39 ( struct V_9 * V_10 ,
unsigned int V_70 ,
unsigned int V_71 )
{
unsigned int V_72 ;
struct V_74 * V_75 ;
V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
if ( ! ( V_75 -> V_78 & V_82 ) ) {
if ( V_75 -> V_12 && ! ( F_40 ( & V_75 -> V_12 -> V_83 ) ) )
F_37 ( V_10 , V_70 , V_71 , 0 ) ;
return;
}
for ( V_72 = 1 ; V_72 < V_75 -> V_84 -> V_85 ;
V_72 ++ ) {
struct V_86 * V_84 = V_75 -> V_84 ;
if ( ! F_40 ( & V_84 -> V_87 [ V_72 ] -> V_83 ) )
F_37 ( V_10 , V_70 , V_71 ,
V_72 ) ;
}
}
static struct V_1 * F_41 (
struct V_1 * V_88 ,
union V_3 * V_4 , int * V_28 )
{
struct V_1 * V_89 = V_88 ;
struct V_90 * V_91 ;
while ( V_89 -> V_6 > V_4 ||
& V_89 -> V_6 [ V_7 - 1 ] < V_4 ) {
V_91 = & V_89 -> V_6 [ V_7 - 1 ] . V_31 ;
if ( V_91 -> V_32 [ 3 ] & F_12 ( V_18 ) )
* V_28 ^= 0x1 ;
V_89 = V_89 -> V_14 ;
if ( V_89 == V_88 )
return NULL ;
}
return V_89 ;
}
static struct V_11 * F_42 ( struct V_9 * V_10 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 )
{
struct V_74 * V_75 ;
V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
if ( ! ( V_75 -> V_78 & V_82 ) )
return V_75 -> V_12 ;
if ( V_72 == 0 ) {
F_32 ( V_10 ,
L_13
L_14 ,
V_70 , V_71 ) ;
return NULL ;
}
if ( V_72 < V_75 -> V_84 -> V_85 )
return V_75 -> V_84 -> V_87 [ V_72 ] ;
F_32 ( V_10 ,
L_15
L_16
L_17 ,
V_70 , V_71 ,
V_75 -> V_84 -> V_85 - 1 ,
V_72 ) ;
return NULL ;
}
static struct V_11 * F_43 ( struct V_9 * V_10 ,
struct V_92 * V_92 )
{
return F_42 ( V_10 , V_92 -> V_93 -> V_70 ,
F_44 ( & V_92 -> V_75 -> V_94 ) , V_92 -> V_72 ) ;
}
void F_45 ( struct V_9 * V_10 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 , struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_99 * V_93 = V_10 -> V_76 [ V_70 ] ;
struct V_11 * V_100 ;
struct V_90 * V_4 ;
struct V_101 * V_102 ;
T_1 V_22 ;
V_100 = F_42 ( V_10 , V_70 ,
V_71 , V_72 ) ;
if ( ! V_100 ) {
F_32 ( V_10 , L_18
L_19 ,
V_72 ) ;
return;
}
V_98 -> V_103 = 0 ;
F_46 ( V_10 , V_104 ,
L_20 ) ;
V_98 -> V_105 = F_41 ( V_96 -> V_88 ,
V_93 -> V_77 [ V_71 ] . V_106 ,
& V_98 -> V_103 ) ;
if ( ! V_98 -> V_105 ) {
F_47 ( 1 ) ;
return;
}
F_46 ( V_10 , V_104 ,
L_21 ) ;
V_102 = F_48 ( V_10 , V_93 -> V_107 , V_71 ) ;
V_98 -> V_103 = 0x1 & F_49 ( V_102 -> V_108 ) ;
V_98 -> V_109 = V_96 -> F_4 ;
F_46 ( V_10 , V_104 ,
L_22 ) ;
V_98 -> V_105 = F_41 ( V_98 -> V_105 ,
V_98 -> V_109 ,
& V_98 -> V_103 ) ;
if ( ! V_98 -> V_105 ) {
F_47 ( 1 ) ;
return;
}
V_4 = & V_98 -> V_109 -> V_31 ;
if ( F_5 ( V_4 -> V_32 [ 3 ] ) &&
( V_4 -> V_32 [ 3 ] & F_12 ( V_18 ) ) )
V_98 -> V_103 ^= 0x1 ;
F_8 ( V_10 , V_100 , & V_98 -> V_105 , & V_98 -> V_109 ) ;
if ( V_100 -> V_15 == V_100 -> V_15 -> V_14 &&
V_98 -> V_109 < V_93 -> V_77 [ V_71 ] . V_106 )
V_98 -> V_103 ^= 0x1 ;
F_46 ( V_10 , V_104 ,
L_23 , V_98 -> V_103 ) ;
F_46 ( V_10 , V_104 ,
L_24 ,
V_98 -> V_105 ) ;
V_22 = F_1 ( V_98 -> V_105 , V_98 -> V_109 ) ;
F_46 ( V_10 , V_104 ,
L_25 ,
( unsigned long long ) V_22 ) ;
}
static void F_50 ( struct V_9 * V_10 , struct V_11 * V_100 ,
struct V_95 * V_96 , bool V_110 )
{
struct V_1 * V_89 ;
union V_3 * V_111 ;
for ( V_89 = V_96 -> V_88 , V_111 = V_96 -> V_112 ;
true ;
F_8 ( V_10 , V_100 , & V_89 , & V_111 ) ) {
if ( F_5 ( V_111 -> V_31 . V_32 [ 3 ] ) ) {
V_111 -> V_31 . V_32 [ 3 ] &= F_12 ( ~ V_33 ) ;
if ( V_110 )
V_111 -> V_31 . V_32 [ 3 ] ^=
F_12 ( V_38 ) ;
F_46 ( V_10 , V_104 ,
L_26 ) ;
F_46 ( V_10 , V_104 ,
L_27
L_28 ,
V_111 ,
( unsigned long long ) F_1 ( V_89 , V_111 ) ,
V_89 ,
( unsigned long long ) V_89 -> V_8 ) ;
} else {
V_111 -> V_31 . V_32 [ 0 ] = 0 ;
V_111 -> V_31 . V_32 [ 1 ] = 0 ;
V_111 -> V_31 . V_32 [ 2 ] = 0 ;
V_111 -> V_31 . V_32 [ 3 ] &= F_12 ( V_38 ) ;
if ( V_110 && V_111 != V_96 -> V_112 &&
V_111 != V_96 -> F_4 )
V_111 -> V_31 . V_32 [ 3 ] ^=
F_12 ( V_38 ) ;
V_111 -> V_31 . V_32 [ 3 ] |= F_12 (
F_51 ( V_113 ) ) ;
F_46 ( V_10 , V_104 ,
L_29 ,
( unsigned long long )
F_1 ( V_89 , V_111 ) ) ;
}
if ( V_111 == V_96 -> F_4 )
break;
}
}
void F_52 ( struct V_9 * V_10 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 ,
struct V_97 * V_114 )
{
struct V_74 * V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
F_46 ( V_10 , V_104 ,
L_30
L_31 ,
V_114 -> V_105 ,
( unsigned long long ) V_114 -> V_105 -> V_8 ,
V_114 -> V_109 ,
( unsigned long long ) F_1 ( V_114 -> V_105 , V_114 -> V_109 ) ,
V_114 -> V_103 ) ;
F_53 ( V_10 , V_70 , V_71 , V_72 ,
V_114 -> V_105 ,
V_114 -> V_109 ,
( T_2 ) V_114 -> V_103 ) ;
V_75 -> V_78 |= V_80 ;
}
static void F_54 ( struct V_9 * V_10 ,
struct V_74 * V_75 )
{
V_75 -> V_78 &= ~ V_79 ;
if ( F_55 ( & V_75 -> V_115 ) )
V_75 -> V_116 -- ;
}
static void F_56 ( struct V_9 * V_10 ,
struct V_95 * V_96 , int V_117 , char * V_118 )
{
struct V_119 * V_120 ;
struct V_92 * V_92 ;
struct V_121 * V_121 ;
V_92 = V_96 -> V_92 ;
V_121 = V_92 -> V_122 ;
V_121 -> V_123 ++ ;
V_120 = F_57 ( V_92 -> V_93 -> V_124 ) ;
if ( V_121 -> V_123 == V_121 -> V_125 ) {
if ( F_58 ( V_92 -> V_126 ) == V_127 ) {
F_36 ( V_10 ) -> V_128 . V_129 -- ;
if ( F_36 ( V_10 ) -> V_128 . V_129 == 0 ) {
if ( V_10 -> V_36 & V_130 )
F_59 () ;
}
}
F_60 ( V_120 , V_92 ) ;
F_61 ( & V_10 -> V_67 ) ;
F_62 ( V_120 , V_92 , V_117 ) ;
F_63 ( V_10 , V_121 ) ;
F_64 ( & V_10 -> V_67 ) ;
}
}
static void F_65 ( struct V_9 * V_10 ,
union V_3 * V_4 , struct V_131 * V_132 )
{
unsigned int V_70 ;
unsigned int V_71 ;
struct V_99 * V_133 ;
struct V_11 * V_100 ;
struct V_74 * V_75 ;
struct V_134 * V_135 ;
struct V_95 * V_96 = NULL ;
struct V_95 * V_136 ;
struct V_97 V_114 ;
if ( F_33 ( F_66 (
F_3 ( V_10 -> V_50 -> V_26 -> V_31 . V_32 [ 3 ] ) ) ) ) {
V_70 = F_67 (
F_3 ( V_10 -> V_50 -> V_26 -> V_31 . V_32 [ 3 ] ) ) ;
V_133 = V_10 -> V_76 [ V_70 ] ;
if ( V_133 )
F_68 ( V_10 , V_133 ,
V_132 ) ;
else
F_32 ( V_10 , L_32
L_33 ,
V_70 ) ;
return;
}
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_70 = F_67 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_71 = F_69 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
if ( F_40 ( & V_75 -> V_137 ) ) {
F_54 ( V_10 , V_75 ) ;
V_75 -> V_138 = NULL ;
V_75 -> V_106 = NULL ;
F_39 ( V_10 , V_70 , V_71 ) ;
return;
}
F_70 (entry, &ep->cancelled_td_list) {
V_96 = F_71 ( V_135 , struct V_95 , V_137 ) ;
F_46 ( V_10 , V_104 ,
L_34 ,
( unsigned long long ) F_1 (
V_96 -> V_88 , V_96 -> V_112 ) ) ;
V_100 = F_43 ( V_10 , V_96 -> V_92 ) ;
if ( ! V_100 ) {
F_32 ( V_10 , L_35
L_36 ,
V_96 -> V_92 ,
V_96 -> V_92 -> V_72 ) ;
goto V_139;
}
if ( V_96 == V_75 -> V_138 )
F_45 ( V_10 , V_70 , V_71 ,
V_96 -> V_92 -> V_72 ,
V_96 , & V_114 ) ;
else
F_50 ( V_10 , V_100 , V_96 , false ) ;
V_139:
F_72 ( & V_96 -> V_83 ) ;
}
V_136 = V_96 ;
F_54 ( V_10 , V_75 ) ;
if ( V_114 . V_109 && V_114 . V_105 ) {
F_52 ( V_10 ,
V_70 , V_71 ,
V_75 -> V_138 -> V_92 -> V_72 ,
& V_114 ) ;
F_15 ( V_10 ) ;
} else {
F_39 ( V_10 , V_70 , V_71 ) ;
}
if ( ! ( V_75 -> V_78 & V_81 ) ) {
V_75 -> V_138 = NULL ;
V_75 -> V_106 = NULL ;
}
do {
V_96 = F_71 ( V_75 -> V_137 . V_14 ,
struct V_95 , V_137 ) ;
F_72 ( & V_96 -> V_137 ) ;
F_56 ( V_10 , V_96 , 0 , L_37 ) ;
if ( V_10 -> V_54 & V_55 )
return;
} while ( V_96 != V_136 );
}
void F_73 ( unsigned long V_140 )
{
struct V_9 * V_10 ;
struct V_74 * V_75 ;
struct V_74 * V_141 ;
struct V_11 * V_12 ;
struct V_95 * V_96 ;
int V_48 , V_142 , V_143 ;
unsigned long V_66 ;
V_75 = (struct V_74 * ) V_140 ;
V_10 = V_75 -> V_10 ;
F_31 ( & V_10 -> V_67 , V_66 ) ;
V_75 -> V_116 -- ;
if ( V_10 -> V_54 & V_55 ) {
F_46 ( V_10 , V_104 ,
L_38
L_39 ) ;
F_34 ( & V_10 -> V_67 , V_66 ) ;
return;
}
if ( ! ( V_75 -> V_116 == 0 && ( V_75 -> V_78 & V_79 ) ) ) {
F_46 ( V_10 , V_104 ,
L_40
L_41 ) ;
F_34 ( & V_10 -> V_67 , V_66 ) ;
return;
}
F_32 ( V_10 , L_42 ) ;
F_32 ( V_10 , L_43 ) ;
V_10 -> V_54 |= V_55 ;
F_24 ( V_10 ) ;
F_34 ( & V_10 -> V_67 , V_66 ) ;
V_48 = F_25 ( V_10 ) ;
F_31 ( & V_10 -> V_67 , V_66 ) ;
if ( V_48 < 0 ) {
F_32 ( V_10 , L_44 ) ;
F_32 ( V_10 , L_45 ) ;
}
for ( V_142 = 0 ; V_142 < V_144 ; V_142 ++ ) {
if ( ! V_10 -> V_76 [ V_142 ] )
continue;
for ( V_143 = 0 ; V_143 < 31 ; V_143 ++ ) {
V_141 = & V_10 -> V_76 [ V_142 ] -> V_77 [ V_143 ] ;
V_12 = V_141 -> V_12 ;
if ( ! V_12 )
continue;
F_46 ( V_10 , V_104 ,
L_46
L_47 , V_142 , V_143 ) ;
while ( ! F_40 ( & V_12 -> V_83 ) ) {
V_96 = F_74 ( & V_12 -> V_83 ,
struct V_95 ,
V_83 ) ;
F_72 ( & V_96 -> V_83 ) ;
if ( ! F_40 ( & V_96 -> V_137 ) )
F_72 ( & V_96 -> V_137 ) ;
F_56 ( V_10 , V_96 ,
- V_56 , L_48 ) ;
}
while ( ! F_40 ( & V_141 -> V_137 ) ) {
V_96 = F_74 (
& V_141 -> V_137 ,
struct V_95 ,
V_137 ) ;
F_72 ( & V_96 -> V_137 ) ;
F_56 ( V_10 , V_96 ,
- V_56 , L_48 ) ;
}
}
}
F_34 ( & V_10 -> V_67 , V_66 ) ;
F_46 ( V_10 , V_104 ,
L_49 ) ;
F_35 ( F_36 ( V_10 ) -> V_69 ) ;
F_46 ( V_10 , V_104 ,
L_50 ) ;
}
static void F_75 ( struct V_9 * V_10 ,
struct V_99 * V_93 ,
struct V_11 * V_100 ,
unsigned int V_71 )
{
union V_3 * V_145 ;
int V_146 ;
bool V_147 = false ;
V_146 = V_100 -> V_27 ;
V_145 = V_100 -> V_26 ;
if ( F_4 ( V_10 , V_100 , V_100 -> V_25 , V_100 -> V_26 ) ) {
V_100 -> V_25 = V_100 -> V_25 -> V_14 ;
V_100 -> V_26 = V_100 -> V_25 -> V_6 ;
}
while ( V_100 -> V_26 != V_93 -> V_77 [ V_71 ] . V_148 ) {
V_100 -> V_27 ++ ;
V_100 -> V_26 ++ ;
if ( F_4 ( V_10 , V_100 , V_100 -> V_25 ,
V_100 -> V_26 ) ) {
if ( V_100 -> V_26 ==
V_93 -> V_77 [ V_71 ] . V_148 )
break;
V_100 -> V_25 = V_100 -> V_25 -> V_14 ;
V_100 -> V_26 = V_100 -> V_25 -> V_6 ;
}
if ( V_100 -> V_26 == V_145 ) {
V_147 = true ;
break;
}
}
if ( V_147 ) {
F_16 ( V_10 , L_51 ) ;
V_100 -> V_27 = V_146 ;
}
}
static void F_76 ( struct V_9 * V_10 ,
struct V_131 * V_132 ,
union V_3 * V_4 )
{
unsigned int V_70 ;
unsigned int V_71 ;
unsigned int V_72 ;
struct V_11 * V_100 ;
struct V_99 * V_93 ;
struct V_101 * V_102 ;
struct V_149 * V_150 ;
V_70 = F_67 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_71 = F_69 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_72 = F_77 ( F_3 ( V_4 -> V_31 . V_32 [ 2 ] ) ) ;
V_93 = V_10 -> V_76 [ V_70 ] ;
V_100 = F_78 ( V_93 , V_71 , V_72 ) ;
if ( ! V_100 ) {
F_32 ( V_10 , L_52
L_53 ,
V_72 ) ;
V_93 -> V_77 [ V_71 ] . V_78 &= ~ V_80 ;
return;
}
V_102 = F_48 ( V_10 , V_93 -> V_107 , V_71 ) ;
V_150 = F_79 ( V_10 , V_93 -> V_107 ) ;
if ( F_80 ( F_3 ( V_132 -> V_117 ) ) != V_151 ) {
unsigned int V_78 ;
unsigned int V_152 ;
switch ( F_80 ( F_3 ( V_132 -> V_117 ) ) ) {
case V_153 :
F_32 ( V_10 , L_54
L_55 ) ;
break;
case V_154 :
F_32 ( V_10 , L_56
L_57 ) ;
V_78 = F_3 ( V_102 -> V_155 ) ;
V_78 &= V_156 ;
V_152 = F_3 ( V_150 -> V_157 ) ;
V_152 = F_81 ( V_152 ) ;
F_46 ( V_10 , V_104 ,
L_58 ,
V_152 , V_78 ) ;
break;
case V_158 :
F_32 ( V_10 , L_59
L_60 , V_70 ) ;
break;
default:
F_32 ( V_10 , L_61
L_62 ,
F_80 ( F_3 ( V_132 -> V_117 ) ) ) ;
break;
}
} else {
F_46 ( V_10 , V_104 ,
L_63 ,
F_49 ( V_102 -> V_108 ) ) ;
if ( F_1 ( V_93 -> V_77 [ V_71 ] . V_159 ,
V_93 -> V_77 [ V_71 ] . V_148 ) ==
( F_49 ( V_102 -> V_108 ) & ~ ( V_160 ) ) ) {
F_75 ( V_10 , V_93 ,
V_100 , V_71 ) ;
} else {
F_32 ( V_10 , L_64
L_65 ) ;
F_32 ( V_10 , L_66 ,
V_93 -> V_77 [ V_71 ] . V_159 ,
V_93 -> V_77 [ V_71 ] . V_148 ) ;
}
}
V_93 -> V_77 [ V_71 ] . V_78 &= ~ V_80 ;
V_93 -> V_77 [ V_71 ] . V_159 = NULL ;
V_93 -> V_77 [ V_71 ] . V_148 = NULL ;
F_39 ( V_10 , V_70 , V_71 ) ;
}
static void F_82 ( struct V_9 * V_10 ,
struct V_131 * V_132 ,
union V_3 * V_4 )
{
int V_70 ;
unsigned int V_71 ;
V_70 = F_67 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
V_71 = F_69 ( F_3 ( V_4 -> V_31 . V_32 [ 3 ] ) ) ;
F_46 ( V_10 , V_161 ,
L_67 ,
F_80 ( F_3 ( V_132 -> V_117 ) ) ) ;
if ( V_10 -> V_36 & V_162 ) {
F_46 ( V_10 , V_163 ,
L_68 ) ;
F_83 ( V_10 ,
V_10 -> V_76 [ V_70 ] -> V_164 -> V_8 , V_70 ,
false ) ;
F_15 ( V_10 ) ;
} else {
V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_78 &= ~ V_81 ;
F_39 ( V_10 , V_70 , V_71 ) ;
}
}
static void F_84 ( struct V_9 * V_10 ,
struct V_57 * V_58 , T_2 V_117 )
{
V_58 -> V_117 = V_117 ;
F_85 ( & V_58 -> V_165 ) ;
if ( V_58 -> V_166 )
F_86 ( V_58 -> V_166 ) ;
else
F_87 ( V_10 , V_58 ) ;
}
static int F_68 ( struct V_9 * V_10 ,
struct V_99 * V_133 ,
struct V_131 * V_132 )
{
struct V_57 * V_58 ;
if ( F_40 ( & V_133 -> V_165 ) )
return 0 ;
V_58 = F_71 ( V_133 -> V_165 . V_14 ,
struct V_57 , V_165 ) ;
if ( V_10 -> V_50 -> V_26 != V_58 -> V_167 )
return 0 ;
F_84 ( V_10 , V_58 ,
F_80 ( F_3 ( V_132 -> V_117 ) ) ) ;
return 1 ;
}
static void F_88 ( struct V_9 * V_10 , struct V_60 * V_168 )
{
struct V_1 * V_89 ;
union V_3 * V_59 ;
T_2 V_28 ;
if ( V_10 -> V_50 -> V_26 == V_10 -> V_50 -> V_20 )
return;
V_89 = F_41 ( V_10 -> V_50 -> V_15 ,
V_10 -> V_50 -> V_26 , & V_28 ) ;
if ( ! V_89 ) {
F_32 ( V_10 , L_69 ,
V_10 -> V_50 -> V_26 ,
( unsigned long long )
F_1 ( V_10 -> V_50 -> V_25 ,
V_10 -> V_50 -> V_26 ) ) ;
F_89 ( V_10 , V_10 -> V_50 ) ;
F_90 ( V_10 , V_10 -> V_50 ) ;
return;
}
for ( V_59 = V_10 -> V_50 -> V_26 ;
V_59 != V_10 -> V_50 -> V_20 ;
F_8 ( V_10 , V_10 -> V_50 , & V_89 , & V_59 ) ) {
if ( F_5 ( V_59 -> V_31 . V_32 [ 3 ] ) )
continue;
if ( V_168 -> V_59 == V_59 ) {
if ( V_168 -> V_58 )
F_84 ( V_10 ,
V_168 -> V_58 , V_169 ) ;
V_28 = F_3 ( V_59 -> V_31 . V_32 [ 3 ] )
& V_38 ;
V_59 -> V_31 . V_32 [ 0 ] = 0 ;
V_59 -> V_31 . V_32 [ 1 ] = 0 ;
V_59 -> V_31 . V_32 [ 2 ] = 0 ;
V_59 -> V_31 . V_32 [ 3 ] = F_12 (
F_51 ( V_170 ) | V_28 ) ;
break;
}
}
}
static void F_91 ( struct V_9 * V_10 )
{
struct V_60 * V_168 , * V_171 ;
if ( F_40 ( & V_10 -> V_64 ) )
return;
F_92 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
F_88 ( V_10 , V_168 ) ;
F_85 ( & V_168 -> V_64 ) ;
F_93 ( V_168 ) ;
}
}
static int F_94 ( struct V_9 * V_10 ,
union V_3 * V_59 )
{
struct V_60 * V_168 , * V_171 ;
if ( F_40 ( & V_10 -> V_64 ) )
return 0 ;
F_92 (cur_cd, next_cd,
&xhci->cancel_cmd_list, cancel_cmd_list) {
if ( V_168 -> V_59 == V_59 ) {
if ( V_168 -> V_58 )
F_84 ( V_10 ,
V_168 -> V_58 , V_169 ) ;
F_85 ( & V_168 -> V_64 ) ;
F_93 ( V_168 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_95 ( struct V_9 * V_10 ,
int V_172 )
{
int V_173 = 0 ;
V_173 = F_94 ( V_10 ,
V_10 -> V_50 -> V_26 ) ;
if ( V_172 == V_174 )
V_10 -> V_42 = V_175 ;
else if ( V_172 == V_169 ) {
F_91 ( V_10 ) ;
V_10 -> V_42 = V_43 ;
if ( V_10 -> V_50 -> V_26 != V_10 -> V_50 -> V_20 )
F_15 ( V_10 ) ;
}
return V_173 ;
}
static void F_96 ( struct V_9 * V_10 ,
struct V_131 * V_132 )
{
int V_70 = F_67 ( F_3 ( V_132 -> V_66 ) ) ;
T_3 V_176 ;
T_1 V_177 ;
struct V_178 * V_179 ;
struct V_99 * V_133 ;
unsigned int V_71 ;
struct V_11 * V_100 ;
unsigned int V_78 ;
V_176 = F_49 ( V_132 -> V_59 ) ;
V_177 = F_1 ( V_10 -> V_50 -> V_25 ,
V_10 -> V_50 -> V_26 ) ;
if ( V_177 == 0 ) {
V_10 -> V_180 |= 1 << 4 ;
return;
}
if ( V_176 != ( T_3 ) V_177 ) {
V_10 -> V_180 |= 1 << 5 ;
return;
}
F_97 ( & V_10 -> V_50 -> V_26 -> V_31 ,
(struct V_90 * ) V_132 ) ;
if ( ( F_80 ( F_3 ( V_132 -> V_117 ) ) == V_174 ) ||
( F_80 ( F_3 ( V_132 -> V_117 ) ) == V_169 ) ) {
if ( F_95 ( V_10 ,
F_80 ( F_3 ( V_132 -> V_117 ) ) ) ) {
F_9 ( V_10 , V_10 -> V_50 ) ;
return;
}
if ( V_10 -> V_50 -> V_26 == V_10 -> V_50 -> V_20 )
return;
}
switch ( F_3 ( V_10 -> V_50 -> V_26 -> V_31 . V_32 [ 3 ] )
& V_181 ) {
case F_51 ( V_182 ) :
if ( F_80 ( F_3 ( V_132 -> V_117 ) ) == V_151 )
V_10 -> V_70 = V_70 ;
else
V_10 -> V_70 = 0 ;
F_86 ( & V_10 -> V_183 ) ;
break;
case F_51 ( V_184 ) :
if ( V_10 -> V_76 [ V_70 ] ) {
if ( V_10 -> V_36 & V_185 )
F_98 ( V_10 ,
V_10 -> V_76 [ V_70 ] , true ) ;
F_99 ( V_10 , V_70 ) ;
}
break;
case F_51 ( V_186 ) :
V_133 = V_10 -> V_76 [ V_70 ] ;
if ( F_68 ( V_10 , V_133 , V_132 ) )
break;
V_179 = F_100 ( V_10 ,
V_133 -> V_164 ) ;
if ( ! V_179 ) {
F_32 ( V_10 , L_70 ) ;
break;
}
V_71 = F_101 ( F_3 ( V_179 -> V_187 ) ) - 1 ;
if ( V_10 -> V_36 & V_162 &&
V_71 != ( unsigned int ) - 1 &&
F_3 ( V_179 -> V_187 ) - V_188 ==
F_3 ( V_179 -> V_189 ) ) {
V_100 = V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_12 ;
V_78 = V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_78 ;
if ( ! ( V_78 & V_81 ) )
goto V_190;
F_46 ( V_10 , V_163 ,
L_71
L_72 ,
V_71 , V_78 ) ;
V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_78 &=
~ V_81 ;
F_39 ( V_10 , V_70 , V_71 ) ;
break;
}
V_190:
F_46 ( V_10 , V_191 ,
L_73 ) ;
V_10 -> V_76 [ V_70 ] -> V_192 =
F_80 ( F_3 ( V_132 -> V_117 ) ) ;
F_86 ( & V_10 -> V_76 [ V_70 ] -> V_193 ) ;
break;
case F_51 ( V_194 ) :
V_133 = V_10 -> V_76 [ V_70 ] ;
if ( F_68 ( V_10 , V_133 , V_132 ) )
break;
V_10 -> V_76 [ V_70 ] -> V_192 = F_80 ( F_3 ( V_132 -> V_117 ) ) ;
F_86 ( & V_10 -> V_76 [ V_70 ] -> V_193 ) ;
break;
case F_51 ( V_195 ) :
V_10 -> V_76 [ V_70 ] -> V_192 = F_80 ( F_3 ( V_132 -> V_117 ) ) ;
F_86 ( & V_10 -> V_183 ) ;
break;
case F_51 ( V_196 ) :
F_65 ( V_10 , V_10 -> V_50 -> V_26 , V_132 ) ;
break;
case F_51 ( V_197 ) :
F_76 ( V_10 , V_132 , V_10 -> V_50 -> V_26 ) ;
break;
case F_51 ( V_170 ) :
break;
case F_51 ( V_198 ) :
F_82 ( V_10 , V_132 , V_10 -> V_50 -> V_26 ) ;
break;
case F_51 ( V_199 ) :
F_16 ( V_10 , L_74 ) ;
V_70 = F_67 (
F_3 ( V_10 -> V_50 -> V_26 -> V_31 . V_32 [ 3 ] ) ) ;
V_133 = V_10 -> V_76 [ V_70 ] ;
if ( V_133 )
F_68 ( V_10 , V_133 , V_132 ) ;
else
F_32 ( V_10 , L_75
L_76 , V_70 ) ;
break;
case F_51 ( V_200 ) :
if ( ! ( V_10 -> V_36 & V_201 ) ) {
V_10 -> V_180 |= 1 << 6 ;
break;
}
F_46 ( V_10 , V_163 ,
L_77 ,
F_102 ( F_3 ( V_132 -> V_117 ) ) ,
F_103 ( F_3 ( V_132 -> V_117 ) ) ) ;
break;
default:
V_10 -> V_180 |= 1 << 6 ;
break;
}
F_9 ( V_10 , V_10 -> V_50 ) ;
}
static void F_104 ( struct V_9 * V_10 ,
union V_3 * V_132 )
{
T_2 V_202 ;
V_202 = F_105 ( F_3 ( V_132 -> V_31 . V_32 [ 3 ] ) ) ;
F_16 ( V_10 , L_78 , V_202 ) ;
if ( V_202 == V_203 && ( V_10 -> V_36 & V_201 ) )
F_96 ( V_10 , & V_132 -> V_204 ) ;
}
static unsigned int F_106 ( struct V_119 * V_120 ,
struct V_9 * V_10 , T_2 V_205 )
{
unsigned int V_142 ;
unsigned int V_206 = 0 ;
for ( V_142 = 0 ; V_142 < ( V_205 - 1 ) ; V_142 ++ ) {
T_6 V_207 = V_10 -> V_208 [ V_142 ] ;
if ( V_207 == 0 || V_207 == V_209 )
continue;
if ( ( V_207 == 0x03 ) == ( V_120 -> V_210 == V_211 ) )
V_206 ++ ;
}
return V_206 ;
}
static void F_107 ( struct V_9 * V_10 ,
union V_3 * V_132 )
{
T_2 V_70 ;
struct V_212 * V_213 ;
V_70 = F_67 ( V_132 -> V_31 . V_32 [ 3 ] ) ;
if ( ! V_10 -> V_76 [ V_70 ] ) {
F_32 ( V_10 , L_79
L_80 , V_70 ) ;
return;
}
F_16 ( V_10 , L_81 ,
V_70 ) ;
V_213 = V_10 -> V_76 [ V_70 ] -> V_213 ;
if ( V_213 && V_213 -> V_214 )
F_108 ( V_213 -> V_214 , V_213 -> V_215 ) ;
}
static void F_109 ( struct V_9 * V_10 ,
union V_3 * V_132 )
{
struct V_119 * V_120 ;
T_2 V_205 ;
T_2 V_216 , V_217 ;
int V_218 ;
int V_70 ;
unsigned int V_219 ;
T_6 V_220 ;
struct V_221 * V_222 ;
T_4 T_5 * * V_208 ;
bool V_223 = false ;
if ( F_80 ( F_3 ( V_132 -> V_31 . V_32 [ 2 ] ) ) != V_151 ) {
F_32 ( V_10 , L_82 ) ;
V_10 -> V_180 |= 1 << 8 ;
}
V_205 = F_110 ( F_3 ( V_132 -> V_31 . V_32 [ 0 ] ) ) ;
F_16 ( V_10 , L_83 , V_205 ) ;
V_218 = F_111 ( V_10 -> V_224 ) ;
if ( ( V_205 <= 0 ) || ( V_205 > V_218 ) ) {
F_32 ( V_10 , L_84 , V_205 ) ;
F_9 ( V_10 , V_10 -> V_13 ) ;
return;
}
V_220 = V_10 -> V_208 [ V_205 - 1 ] ;
V_120 = F_36 ( V_10 ) ;
if ( ( V_220 == 0x03 ) != ( V_120 -> V_210 == V_211 ) )
V_120 = V_10 -> V_225 ;
if ( V_220 == 0 ) {
F_32 ( V_10 , L_85
L_86 ,
V_205 ) ;
V_223 = true ;
goto V_226;
}
if ( V_220 == V_209 ) {
F_32 ( V_10 , L_87
L_86 ,
V_205 ) ;
V_223 = true ;
goto V_226;
}
V_222 = & V_10 -> V_222 [ F_112 ( V_120 ) ] ;
if ( V_120 -> V_210 == V_211 )
V_208 = V_10 -> V_227 ;
else
V_208 = V_10 -> V_228 ;
V_219 = F_106 ( V_120 , V_10 ,
V_205 ) ;
V_216 = F_18 ( V_10 , V_208 [ V_219 ] ) ;
if ( V_120 -> V_98 == V_229 ) {
F_16 ( V_10 , L_88 ) ;
F_113 ( V_120 ) ;
}
if ( ( V_216 & V_230 ) && ( V_216 & V_231 ) == V_232 ) {
F_16 ( V_10 , L_89 , V_205 ) ;
V_217 = F_18 ( V_10 , & V_10 -> V_49 -> V_58 ) ;
if ( ! ( V_217 & V_233 ) ) {
F_32 ( V_10 , L_90 ) ;
goto V_226;
}
if ( F_114 ( V_216 ) ) {
F_16 ( V_10 , L_91 , V_205 ) ;
V_222 -> V_234 |= 1 << V_219 ;
F_115 ( V_10 , V_208 ,
V_219 , V_230 ) ;
F_116 ( V_10 , V_208 , V_219 ,
V_235 ) ;
V_223 = true ;
goto V_226;
} else {
F_16 ( V_10 , L_92 , V_205 ) ;
V_222 -> V_236 [ V_219 ] = V_237 +
F_117 ( 20 ) ;
F_118 ( V_219 , & V_222 -> V_238 ) ;
F_119 ( & V_120 -> V_239 ,
V_222 -> V_236 [ V_219 ] ) ;
}
}
if ( ( V_216 & V_230 ) && ( V_216 & V_231 ) == V_235 &&
F_114 ( V_216 ) ) {
F_16 ( V_10 , L_93 , V_205 ) ;
V_70 = F_120 ( V_120 , V_10 ,
V_219 + 1 ) ;
if ( V_70 && V_10 -> V_76 [ V_70 ] )
F_121 ( V_10 , V_70 ) ;
if ( V_222 -> V_234 & ( 1 << V_219 ) ) {
V_222 -> V_234 &=
~ ( 1 << V_219 ) ;
F_115 ( V_10 , V_208 ,
V_219 , V_230 ) ;
F_108 ( V_120 -> V_128 . V_240 ,
V_219 + 1 ) ;
V_223 = true ;
goto V_226;
}
}
if ( ! F_114 ( V_216 ) &&
F_122 ( V_219 ,
& V_222 -> V_241 ) ) {
F_86 ( & V_222 -> V_242 [ V_219 ] ) ;
V_223 = true ;
goto V_226;
}
if ( V_120 -> V_210 != V_211 )
F_115 ( V_10 , V_208 , V_219 ,
V_230 ) ;
V_226:
F_9 ( V_10 , V_10 -> V_13 ) ;
if ( V_223 )
return;
F_16 ( V_10 , L_94 , V_243 ) ;
F_118 ( V_244 , & V_120 -> V_66 ) ;
F_61 ( & V_10 -> V_67 ) ;
F_123 ( V_120 ) ;
F_64 ( & V_10 -> V_67 ) ;
}
struct V_1 * F_124 ( struct V_1 * V_88 ,
union V_3 * V_245 ,
union V_3 * V_246 ,
T_1 V_247 )
{
T_1 V_248 ;
T_1 V_249 ;
T_1 V_250 ;
struct V_1 * V_89 ;
V_248 = F_1 ( V_88 , V_245 ) ;
V_89 = V_88 ;
do {
if ( V_248 == 0 )
return NULL ;
V_249 = F_1 ( V_89 ,
& V_89 -> V_6 [ V_7 - 1 ] ) ;
V_250 = F_1 ( V_89 , V_246 ) ;
if ( V_250 > 0 ) {
if ( V_248 <= V_250 ) {
if ( V_247 >= V_248 && V_247 <= V_250 )
return V_89 ;
} else {
if ( ( V_247 >= V_248 &&
V_247 <= V_249 ) ||
( V_247 >= V_89 -> V_8 &&
V_247 <= V_250 ) )
return V_89 ;
}
return NULL ;
} else {
if ( V_247 >= V_248 && V_247 <= V_249 )
return V_89 ;
}
V_89 = V_89 -> V_14 ;
V_248 = F_1 ( V_89 , & V_89 -> V_6 [ 0 ] ) ;
} while ( V_89 != V_88 );
return NULL ;
}
static void F_125 ( struct V_9 * V_10 ,
unsigned int V_70 , unsigned int V_71 ,
unsigned int V_72 ,
struct V_95 * V_251 , union V_3 * V_252 )
{
struct V_74 * V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
V_75 -> V_78 |= V_81 ;
V_75 -> V_138 = V_251 ;
V_75 -> V_106 = V_252 ;
V_75 -> V_253 = V_72 ;
F_126 ( V_10 , V_70 , V_71 ) ;
F_127 ( V_10 , V_251 -> V_92 -> V_93 , V_71 ) ;
V_75 -> V_138 = NULL ;
V_75 -> V_106 = NULL ;
V_75 -> V_253 = 0 ;
F_15 ( V_10 ) ;
}
static int F_128 ( struct V_9 * V_10 ,
struct V_101 * V_102 ,
unsigned int V_254 )
{
if ( V_254 == V_255 ||
V_254 == V_256 ||
V_254 == V_257 )
if ( ( V_102 -> V_155 & F_12 ( V_156 ) ) ==
F_12 ( V_258 ) )
return 1 ;
return 0 ;
}
int F_129 ( struct V_9 * V_10 , unsigned int V_254 )
{
if ( V_254 >= 224 && V_254 <= 255 ) {
F_16 ( V_10 , L_95 ,
V_254 ) ;
F_16 ( V_10 , L_96 ) ;
return 1 ;
}
return 0 ;
}
static int F_130 ( struct V_9 * V_10 , struct V_95 * V_251 ,
union V_3 * V_252 , struct V_259 * V_132 ,
struct V_74 * V_75 , int * V_117 , bool V_260 )
{
struct V_99 * V_261 ;
struct V_11 * V_100 ;
unsigned int V_70 ;
int V_71 ;
struct V_92 * V_92 = NULL ;
struct V_101 * V_102 ;
int V_48 = 0 ;
struct V_121 * V_121 ;
T_2 V_254 ;
V_70 = F_67 ( F_3 ( V_132 -> V_66 ) ) ;
V_261 = V_10 -> V_76 [ V_70 ] ;
V_71 = F_131 ( F_3 ( V_132 -> V_66 ) ) - 1 ;
V_100 = F_132 ( V_75 , F_49 ( V_132 -> V_262 ) ) ;
V_102 = F_48 ( V_10 , V_261 -> V_107 , V_71 ) ;
V_254 = F_80 ( F_3 ( V_132 -> V_263 ) ) ;
if ( V_260 )
goto V_264;
if ( V_254 == V_265 ||
V_254 == V_266 ) {
V_75 -> V_138 = V_251 ;
V_75 -> V_106 = V_252 ;
return 0 ;
} else {
if ( V_254 == V_267 ) {
V_75 -> V_138 = V_251 ;
V_75 -> V_106 = V_252 ;
V_75 -> V_253 = V_100 -> V_72 ;
} else if ( F_128 ( V_10 ,
V_102 , V_254 ) ) {
F_125 ( V_10 ,
V_70 , V_71 , V_100 -> V_72 ,
V_251 , V_252 ) ;
} else {
while ( V_100 -> V_26 != V_251 -> F_4 )
F_9 ( V_10 , V_100 ) ;
F_9 ( V_10 , V_100 ) ;
}
V_264:
V_92 = V_251 -> V_92 ;
V_121 = V_92 -> V_122 ;
if ( V_92 -> V_268 > V_92 -> V_269 ) {
F_32 ( V_10 , L_97
L_98
L_99 ,
V_92 -> V_269 ,
V_92 -> V_268 ) ;
V_92 -> V_268 = 0 ;
if ( V_251 -> V_92 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
}
F_72 ( & V_251 -> V_83 ) ;
if ( ! F_40 ( & V_251 -> V_137 ) )
F_72 ( & V_251 -> V_137 ) ;
V_121 -> V_123 ++ ;
if ( V_121 -> V_123 == V_121 -> V_125 ) {
V_48 = 1 ;
if ( F_58 ( V_92 -> V_126 ) == V_127 ) {
F_36 ( V_10 ) -> V_128 . V_129 -- ;
if ( F_36 ( V_10 ) -> V_128 . V_129
== 0 ) {
if ( V_10 -> V_36 & V_130 )
F_59 () ;
}
}
}
}
return V_48 ;
}
static int F_133 ( struct V_9 * V_10 , struct V_95 * V_251 ,
union V_3 * V_252 , struct V_259 * V_132 ,
struct V_74 * V_75 , int * V_117 )
{
struct V_99 * V_261 ;
struct V_11 * V_100 ;
unsigned int V_70 ;
int V_71 ;
struct V_101 * V_102 ;
T_2 V_254 ;
V_70 = F_67 ( F_3 ( V_132 -> V_66 ) ) ;
V_261 = V_10 -> V_76 [ V_70 ] ;
V_71 = F_131 ( F_3 ( V_132 -> V_66 ) ) - 1 ;
V_100 = F_132 ( V_75 , F_49 ( V_132 -> V_262 ) ) ;
V_102 = F_48 ( V_10 , V_261 -> V_107 , V_71 ) ;
V_254 = F_80 ( F_3 ( V_132 -> V_263 ) ) ;
switch ( V_254 ) {
case V_151 :
if ( V_252 == V_100 -> V_26 ) {
F_32 ( V_10 , L_100
L_101 ) ;
* V_117 = - V_56 ;
} else if ( V_252 != V_251 -> F_4 ) {
F_32 ( V_10 , L_102
L_101 ) ;
* V_117 = - V_56 ;
} else {
* V_117 = 0 ;
}
break;
case V_273 :
if ( V_251 -> V_92 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
break;
case V_265 :
case V_266 :
return F_130 ( V_10 , V_251 , V_252 , V_132 , V_75 , V_117 , false ) ;
default:
if ( ! F_128 ( V_10 ,
V_102 , V_254 ) )
break;
F_16 ( V_10 , L_103
L_104 ,
V_254 , V_71 ) ;
case V_267 :
if ( V_252 != V_100 -> V_26 &&
V_252 != V_251 -> F_4 )
V_251 -> V_92 -> V_268 =
V_251 -> V_92 -> V_269 -
F_134 ( F_3 ( V_132 -> V_263 ) ) ;
else
V_251 -> V_92 -> V_268 = 0 ;
F_125 ( V_10 ,
V_70 , V_71 , 0 , V_251 , V_252 ) ;
return F_130 ( V_10 , V_251 , V_252 , V_132 , V_75 , V_117 , true ) ;
}
if ( V_252 != V_100 -> V_26 ) {
if ( V_252 == V_251 -> F_4 ) {
if ( V_251 -> V_92 -> V_268 != 0 ) {
if ( ( * V_117 == - V_274 || * V_117 == 0 ) &&
( V_251 -> V_92 -> V_270
& V_271 ) )
* V_117 = - V_272 ;
} else {
V_251 -> V_92 -> V_268 =
V_251 -> V_92 -> V_269 ;
}
} else {
V_251 -> V_92 -> V_268 =
V_251 -> V_92 -> V_269 -
F_134 ( F_3 ( V_132 -> V_263 ) ) ;
F_16 ( V_10 , L_105
L_106 ) ;
return 0 ;
}
}
return F_130 ( V_10 , V_251 , V_252 , V_132 , V_75 , V_117 , false ) ;
}
static int F_135 ( struct V_9 * V_10 , struct V_95 * V_251 ,
union V_3 * V_252 , struct V_259 * V_132 ,
struct V_74 * V_75 , int * V_117 )
{
struct V_11 * V_100 ;
struct V_121 * V_121 ;
int V_275 ;
int V_276 = 0 ;
union V_3 * V_111 ;
struct V_1 * V_89 ;
struct V_277 * V_278 ;
T_2 V_254 ;
bool V_279 = false ;
V_100 = F_132 ( V_75 , F_49 ( V_132 -> V_262 ) ) ;
V_254 = F_80 ( F_3 ( V_132 -> V_263 ) ) ;
V_121 = V_251 -> V_92 -> V_122 ;
V_275 = V_121 -> V_123 ;
V_278 = & V_251 -> V_92 -> V_280 [ V_275 ] ;
switch ( V_254 ) {
case V_151 :
if ( F_134 ( F_3 ( V_132 -> V_263 ) ) == 0 ) {
V_278 -> V_117 = 0 ;
break;
}
if ( ( V_10 -> V_36 & V_281 ) )
V_254 = V_273 ;
case V_273 :
V_278 -> V_117 = V_251 -> V_92 -> V_270 & V_271 ?
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
V_278 -> V_268 = V_278 -> V_125 ;
V_251 -> V_92 -> V_268 += V_278 -> V_125 ;
} else {
for ( V_111 = V_100 -> V_26 ,
V_89 = V_100 -> V_25 ; V_111 != V_252 ;
F_8 ( V_10 , V_100 , & V_89 , & V_111 ) ) {
if ( ! F_136 ( V_111 -> V_31 . V_32 [ 3 ] ) &&
! F_5 ( V_111 -> V_31 . V_32 [ 3 ] ) )
V_276 += F_137 ( F_3 ( V_111 -> V_31 . V_32 [ 2 ] ) ) ;
}
V_276 += F_137 ( F_3 ( V_111 -> V_31 . V_32 [ 2 ] ) ) -
F_134 ( F_3 ( V_132 -> V_263 ) ) ;
if ( V_254 != V_265 ) {
V_278 -> V_268 = V_276 ;
V_251 -> V_92 -> V_268 += V_276 ;
}
}
return F_130 ( V_10 , V_251 , V_252 , V_132 , V_75 , V_117 , false ) ;
}
static int F_138 ( struct V_9 * V_10 , struct V_95 * V_251 ,
struct V_259 * V_132 ,
struct V_74 * V_75 , int * V_117 )
{
struct V_11 * V_100 ;
struct V_121 * V_121 ;
struct V_277 * V_278 ;
int V_275 ;
V_100 = F_132 ( V_75 , F_49 ( V_132 -> V_262 ) ) ;
V_121 = V_251 -> V_92 -> V_122 ;
V_275 = V_121 -> V_123 ;
V_278 = & V_251 -> V_92 -> V_280 [ V_275 ] ;
V_278 -> V_117 = - V_288 ;
V_278 -> V_268 = 0 ;
while ( V_100 -> V_26 != V_251 -> F_4 )
F_9 ( V_10 , V_100 ) ;
F_9 ( V_10 , V_100 ) ;
return F_130 ( V_10 , V_251 , NULL , V_132 , V_75 , V_117 , true ) ;
}
static int F_139 ( struct V_9 * V_10 , struct V_95 * V_251 ,
union V_3 * V_252 , struct V_259 * V_132 ,
struct V_74 * V_75 , int * V_117 )
{
struct V_11 * V_100 ;
union V_3 * V_111 ;
struct V_1 * V_89 ;
T_2 V_254 ;
V_100 = F_132 ( V_75 , F_49 ( V_132 -> V_262 ) ) ;
V_254 = F_80 ( F_3 ( V_132 -> V_263 ) ) ;
switch ( V_254 ) {
case V_151 :
if ( V_252 != V_251 -> F_4 ||
F_134 ( F_3 ( V_132 -> V_263 ) ) != 0 ) {
F_32 ( V_10 , L_107
L_108 ) ;
if ( V_251 -> V_92 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
if ( ( V_10 -> V_36 & V_281 ) )
V_254 = V_273 ;
} else {
* V_117 = 0 ;
}
break;
case V_273 :
if ( V_251 -> V_92 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
break;
default:
break;
}
if ( V_254 == V_273 )
F_16 ( V_10 , L_109
L_110 ,
V_251 -> V_92 -> V_75 -> V_94 . V_289 ,
V_251 -> V_92 -> V_269 ,
F_134 ( F_3 ( V_132 -> V_263 ) ) ) ;
if ( V_252 == V_251 -> F_4 ) {
if ( F_134 ( F_3 ( V_132 -> V_263 ) ) != 0 ) {
V_251 -> V_92 -> V_268 =
V_251 -> V_92 -> V_269 -
F_134 ( F_3 ( V_132 -> V_263 ) ) ;
if ( V_251 -> V_92 -> V_269 <
V_251 -> V_92 -> V_268 ) {
F_32 ( V_10 , L_111
L_112 ,
F_134 ( F_3 ( V_132 -> V_263 ) ) ) ;
V_251 -> V_92 -> V_268 = 0 ;
if ( V_251 -> V_92 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
}
if ( * V_117 == - V_274 ) {
if ( V_251 -> V_92 -> V_270 & V_271 )
* V_117 = - V_272 ;
else
* V_117 = 0 ;
}
} else {
V_251 -> V_92 -> V_268 =
V_251 -> V_92 -> V_269 ;
if ( * V_117 == - V_272 )
* V_117 = 0 ;
}
} else {
V_251 -> V_92 -> V_268 = 0 ;
for ( V_111 = V_100 -> V_26 , V_89 = V_100 -> V_25 ;
V_111 != V_252 ;
F_8 ( V_10 , V_100 , & V_89 , & V_111 ) ) {
if ( ! F_136 ( V_111 -> V_31 . V_32 [ 3 ] ) &&
! F_5 ( V_111 -> V_31 . V_32 [ 3 ] ) )
V_251 -> V_92 -> V_268 +=
F_137 ( F_3 ( V_111 -> V_31 . V_32 [ 2 ] ) ) ;
}
if ( V_254 != V_265 )
V_251 -> V_92 -> V_268 +=
F_137 ( F_3 ( V_111 -> V_31 . V_32 [ 2 ] ) ) -
F_134 ( F_3 ( V_132 -> V_263 ) ) ;
}
return F_130 ( V_10 , V_251 , V_252 , V_132 , V_75 , V_117 , false ) ;
}
static int F_140 ( struct V_9 * V_10 ,
struct V_259 * V_132 )
__releases( &xhci->lock
static int F_141 ( struct V_9 * V_10 )
{
union V_3 * V_132 ;
int V_290 = 1 ;
int V_48 ;
if ( ! V_10 -> V_13 || ! V_10 -> V_13 -> V_26 ) {
V_10 -> V_180 |= 1 << 1 ;
return 0 ;
}
V_132 = V_10 -> V_13 -> V_26 ;
if ( ( F_3 ( V_132 -> V_204 . V_66 ) & V_38 ) !=
V_10 -> V_13 -> V_28 ) {
V_10 -> V_180 |= 1 << 2 ;
return 0 ;
}
F_142 () ;
switch ( ( F_3 ( V_132 -> V_204 . V_66 ) & V_181 ) ) {
case F_51 ( V_291 ) :
F_96 ( V_10 , & V_132 -> V_204 ) ;
break;
case F_51 ( V_292 ) :
F_109 ( V_10 , V_132 ) ;
V_290 = 0 ;
break;
case F_51 ( V_293 ) :
V_48 = F_140 ( V_10 , & V_132 -> V_294 ) ;
if ( V_48 < 0 )
V_10 -> V_180 |= 1 << 9 ;
else
V_290 = 0 ;
break;
case F_51 ( V_295 ) :
F_107 ( V_10 , V_132 ) ;
break;
default:
if ( ( F_3 ( V_132 -> V_204 . V_66 ) & V_181 ) >=
F_51 ( 48 ) )
F_104 ( V_10 , V_132 ) ;
else
V_10 -> V_180 |= 1 << 3 ;
}
if ( V_10 -> V_54 & V_55 ) {
F_16 ( V_10 , L_113
L_114 ) ;
return 0 ;
}
if ( V_290 )
F_9 ( V_10 , V_10 -> V_13 ) ;
return 1 ;
}
T_7 F_143 ( struct V_119 * V_120 )
{
struct V_9 * V_10 = F_144 ( V_120 ) ;
T_2 V_117 ;
T_3 V_47 ;
union V_3 * V_296 ;
T_1 V_108 ;
F_64 ( & V_10 -> V_67 ) ;
V_117 = F_18 ( V_10 , & V_10 -> V_49 -> V_117 ) ;
if ( V_117 == 0xffffffff )
goto V_297;
if ( ! ( V_117 & V_298 ) ) {
F_61 ( & V_10 -> V_67 ) ;
return V_299 ;
}
if ( V_117 & V_300 ) {
F_32 ( V_10 , L_115 ) ;
F_25 ( V_10 ) ;
V_297:
F_61 ( & V_10 -> V_67 ) ;
return - V_56 ;
}
V_117 |= V_298 ;
F_17 ( V_10 , V_117 , & V_10 -> V_49 -> V_117 ) ;
if ( V_120 -> V_301 ) {
T_2 V_302 ;
V_302 = F_18 ( V_10 , & V_10 -> V_303 -> V_302 ) ;
V_302 |= V_304 ;
F_17 ( V_10 , V_302 , & V_10 -> V_303 -> V_302 ) ;
}
if ( V_10 -> V_54 & V_55 ) {
F_16 ( V_10 , L_116
L_117 ) ;
V_47 = F_20 ( V_10 , & V_10 -> V_303 -> V_305 ) ;
F_21 ( V_10 , V_47 | V_306 ,
& V_10 -> V_303 -> V_305 ) ;
F_61 ( & V_10 -> V_67 ) ;
return V_307 ;
}
V_296 = V_10 -> V_13 -> V_26 ;
while ( F_141 ( V_10 ) > 0 ) {}
V_47 = F_20 ( V_10 , & V_10 -> V_303 -> V_305 ) ;
if ( V_296 != V_10 -> V_13 -> V_26 ) {
V_108 = F_1 ( V_10 -> V_13 -> V_25 ,
V_10 -> V_13 -> V_26 ) ;
if ( V_108 == 0 )
F_32 ( V_10 , L_118
L_119 ) ;
V_47 &= V_308 ;
V_47 |= ( ( T_3 ) V_108 & ( T_3 ) ~ V_308 ) ;
}
V_47 |= V_306 ;
F_21 ( V_10 , V_47 , & V_10 -> V_303 -> V_305 ) ;
F_61 ( & V_10 -> V_67 ) ;
return V_307 ;
}
T_7 F_145 ( int V_301 , void * V_120 )
{
return F_143 ( V_120 ) ;
}
static void F_146 ( struct V_9 * V_10 , struct V_11 * V_12 ,
bool V_29 ,
T_2 V_309 , T_2 V_310 , T_2 V_311 , T_2 V_312 )
{
struct V_90 * V_4 ;
V_4 = & V_12 -> V_20 -> V_31 ;
V_4 -> V_32 [ 0 ] = F_12 ( V_309 ) ;
V_4 -> V_32 [ 1 ] = F_12 ( V_310 ) ;
V_4 -> V_32 [ 2 ] = F_12 ( V_311 ) ;
V_4 -> V_32 [ 3 ] = F_12 ( V_312 ) ;
F_10 ( V_10 , V_12 , V_29 ) ;
}
static int F_147 ( struct V_9 * V_10 , struct V_11 * V_100 ,
T_2 V_78 , unsigned int V_39 , T_8 V_313 )
{
unsigned int V_314 ;
switch ( V_78 ) {
case V_315 :
F_32 ( V_10 , L_120 ) ;
return - V_316 ;
case V_317 :
F_32 ( V_10 , L_121 ) ;
return - V_318 ;
case V_258 :
F_16 ( V_10 , L_122 ) ;
case V_319 :
case V_320 :
break;
default:
F_23 ( V_10 , L_123 ) ;
return - V_318 ;
}
while ( 1 ) {
if ( F_14 ( V_10 , V_100 , V_39 ) )
break;
if ( V_100 == V_10 -> V_50 ) {
F_23 ( V_10 , L_124 ) ;
return - V_63 ;
}
F_46 ( V_10 , V_321 ,
L_125 ) ;
V_314 = V_39 - V_100 -> V_27 ;
if ( F_148 ( V_10 , V_100 , V_314 ,
V_313 ) ) {
F_23 ( V_10 , L_126 ) ;
return - V_63 ;
}
}
if ( F_6 ( V_100 ) ) {
struct V_11 * V_12 = V_100 ;
union V_3 * V_14 ;
V_14 = V_12 -> V_20 ;
while ( F_4 ( V_10 , V_12 , V_12 -> V_21 , V_14 ) ) {
if ( ! F_11 ( V_10 ) &&
! ( V_12 -> type == V_35 &&
( V_10 -> V_36 & V_37 ) ) )
V_14 -> V_16 . V_17 &= F_12 ( ~ V_33 ) ;
else
V_14 -> V_16 . V_17 |= F_12 ( V_33 ) ;
F_13 () ;
V_14 -> V_16 . V_17 ^= F_12 ( V_38 ) ;
if ( F_2 ( V_10 , V_12 , V_12 -> V_21 , V_14 ) ) {
V_12 -> V_28 = ( V_12 -> V_28 ? 0 : 1 ) ;
}
V_12 -> V_21 = V_12 -> V_21 -> V_14 ;
V_12 -> V_20 = V_12 -> V_21 -> V_6 ;
V_14 = V_12 -> V_20 ;
}
}
return 0 ;
}
static int F_149 ( struct V_9 * V_10 ,
struct V_99 * V_261 ,
unsigned int V_71 ,
unsigned int V_72 ,
unsigned int V_39 ,
struct V_92 * V_92 ,
unsigned int V_322 ,
T_8 V_313 )
{
int V_48 ;
struct V_121 * V_121 ;
struct V_95 * V_251 ;
struct V_11 * V_100 ;
struct V_101 * V_102 = F_48 ( V_10 , V_261 -> V_107 , V_71 ) ;
V_100 = F_78 ( V_261 , V_71 , V_72 ) ;
if ( ! V_100 ) {
F_16 ( V_10 , L_127 ,
V_72 ) ;
return - V_318 ;
}
V_48 = F_147 ( V_10 , V_100 ,
F_3 ( V_102 -> V_155 ) & V_156 ,
V_39 , V_313 ) ;
if ( V_48 )
return V_48 ;
V_121 = V_92 -> V_122 ;
V_251 = V_121 -> V_251 [ V_322 ] ;
F_28 ( & V_251 -> V_83 ) ;
F_28 ( & V_251 -> V_137 ) ;
if ( V_322 == 0 ) {
V_48 = F_150 ( F_57 ( V_92 -> V_93 -> V_124 ) , V_92 ) ;
if ( F_33 ( V_48 ) )
return V_48 ;
}
V_251 -> V_92 = V_92 ;
F_29 ( & V_251 -> V_83 , & V_100 -> V_83 ) ;
V_251 -> V_88 = V_100 -> V_21 ;
V_251 -> V_112 = V_100 -> V_20 ;
V_121 -> V_251 [ V_322 ] = V_251 ;
return 0 ;
}
static unsigned int F_151 ( struct V_9 * V_10 , struct V_92 * V_92 )
{
int V_323 , V_39 , V_324 , V_216 , V_142 ;
struct V_325 * V_326 ;
V_326 = NULL ;
V_323 = V_92 -> V_327 ;
V_216 = V_92 -> V_269 ;
V_39 = 0 ;
F_152 (urb->sg, sg, num_sgs, i) {
unsigned int V_276 = F_153 ( V_326 ) ;
V_324 = V_328 -
( F_154 ( V_326 ) & ( V_328 - 1 ) ) ;
V_324 &= V_328 - 1 ;
if ( V_324 != 0 )
V_39 ++ ;
while ( V_324 < F_153 ( V_326 ) && V_324 < V_216 ) {
V_39 ++ ;
V_324 += V_328 ;
}
V_276 = F_155 ( int , V_276 , V_216 ) ;
V_216 -= V_276 ;
if ( V_216 == 0 )
break;
}
return V_39 ;
}
static void F_156 ( struct V_92 * V_92 , int V_39 , int V_324 )
{
if ( V_39 != 0 )
F_157 ( & V_92 -> V_93 -> V_93 , L_128
L_129 , V_243 ,
V_92 -> V_75 -> V_94 . V_289 , V_39 ) ;
if ( V_324 != V_92 -> V_269 )
F_157 ( & V_92 -> V_93 -> V_93 , L_130
L_131 ,
V_243 ,
V_92 -> V_75 -> V_94 . V_289 ,
V_324 , V_324 ,
V_92 -> V_269 ,
V_92 -> V_269 ) ;
}
static void F_158 ( struct V_9 * V_10 , int V_70 ,
unsigned int V_71 , unsigned int V_72 , int V_329 ,
struct V_90 * V_245 )
{
F_13 () ;
if ( V_329 )
V_245 -> V_32 [ 3 ] |= F_12 ( V_329 ) ;
else
V_245 -> V_32 [ 3 ] &= F_12 ( ~ V_38 ) ;
F_37 ( V_10 , V_70 , V_71 , V_72 ) ;
}
int F_159 ( struct V_9 * V_10 , T_8 V_313 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_101 * V_102 = F_48 ( V_10 ,
V_10 -> V_76 [ V_70 ] -> V_107 , V_71 ) ;
int V_330 ;
int V_331 ;
V_330 = F_160 ( F_3 ( V_102 -> V_155 ) ) ;
V_331 = V_92 -> V_332 ;
if ( V_92 -> V_93 -> V_210 == V_333 ||
V_92 -> V_93 -> V_210 == V_334 )
V_331 *= 8 ;
if ( V_330 != V_331 ) {
F_161 ( & V_92 -> V_93 -> V_93 ,
L_132 ,
V_331 , V_331 == 1 ? L_133 : L_134 ,
V_330 , V_330 == 1 ? L_133 : L_134 ) ;
V_92 -> V_332 = V_330 ;
if ( V_92 -> V_93 -> V_210 == V_333 ||
V_92 -> V_93 -> V_210 == V_334 )
V_92 -> V_332 /= 8 ;
}
return F_162 ( V_10 , V_313 , V_92 , V_70 , V_71 ) ;
}
static T_2 F_163 ( unsigned int V_335 )
{
T_2 V_336 = ( 1 << ( 21 - 17 + 1 ) ) - 1 ;
if ( ( V_335 >> 10 ) >= V_336 )
return V_336 << 17 ;
else
return ( V_335 >> 10 ) << 17 ;
}
static T_2 F_164 ( int V_324 , int V_337 ,
unsigned int V_338 , struct V_92 * V_92 ,
unsigned int V_339 )
{
int V_340 ;
if ( V_339 == 0 || ( V_324 == 0 && V_337 == 0 ) )
return 0 ;
V_340 = ( V_324 + V_337 ) /
F_165 ( F_166 ( & V_92 -> V_75 -> V_94 ) ) ;
if ( ( V_338 - V_340 ) > 31 )
return 31 << 17 ;
return ( V_338 - V_340 ) << 17 ;
}
static int F_167 ( struct V_9 * V_10 , T_8 V_313 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_11 * V_100 ;
unsigned int V_39 ;
struct V_121 * V_121 ;
struct V_95 * V_251 ;
struct V_325 * V_326 ;
int V_323 ;
int V_337 , V_341 , V_324 ;
unsigned int V_338 ;
bool V_112 ;
T_3 V_22 ;
bool V_29 ;
struct V_90 * V_245 ;
int V_329 ;
V_100 = F_43 ( V_10 , V_92 ) ;
if ( ! V_100 )
return - V_318 ;
V_39 = F_151 ( V_10 , V_92 ) ;
V_323 = V_92 -> V_327 ;
V_338 = F_168 ( V_92 -> V_269 ,
F_166 ( & V_92 -> V_75 -> V_94 ) ) ;
V_337 = F_149 ( V_10 , V_10 -> V_76 [ V_70 ] ,
V_71 , V_92 -> V_72 ,
V_39 , V_92 , 0 , V_313 ) ;
if ( V_337 < 0 )
return V_337 ;
V_121 = V_92 -> V_122 ;
V_251 = V_121 -> V_251 [ 0 ] ;
V_245 = & V_100 -> V_20 -> V_31 ;
V_329 = V_100 -> V_28 ;
V_324 = 0 ;
V_326 = V_92 -> V_326 ;
V_22 = ( T_3 ) F_154 ( V_326 ) ;
V_341 = F_153 ( V_326 ) ;
V_337 = V_328 - ( V_22 & ( V_328 - 1 ) ) ;
V_337 = F_155 ( int , V_337 , V_341 ) ;
if ( V_337 > V_92 -> V_269 )
V_337 = V_92 -> V_269 ;
V_112 = true ;
do {
T_2 V_32 = 0 ;
T_2 V_342 = 0 ;
T_2 V_335 = 0 ;
if ( V_112 ) {
V_112 = false ;
if ( V_329 == 0 )
V_32 |= 0x1 ;
} else
V_32 |= V_100 -> V_28 ;
if ( V_39 > 1 ) {
V_32 |= V_33 ;
} else {
V_251 -> F_4 = V_100 -> V_20 ;
V_32 |= V_343 ;
}
if ( F_169 ( V_92 ) )
V_32 |= V_344 ;
if ( V_328 -
( V_22 & ( V_328 - 1 ) ) < V_337 ) {
F_32 ( V_10 , L_135 ) ;
F_16 ( V_10 , L_136 ,
( unsigned int ) ( V_22 + V_328 ) & ~ ( V_328 - 1 ) ,
( unsigned int ) V_22 + V_337 ) ;
}
if ( V_10 -> V_345 < 0x100 ) {
V_335 = F_163 (
V_92 -> V_269 -
V_324 ) ;
} else {
V_335 = F_164 ( V_324 ,
V_337 , V_338 , V_92 ,
V_39 - 1 ) ;
}
V_342 = F_137 ( V_337 ) |
V_335 |
F_170 ( 0 ) ;
if ( V_39 > 1 )
V_29 = true ;
else
V_29 = false ;
F_146 ( V_10 , V_100 , V_29 ,
F_171 ( V_22 ) ,
F_172 ( V_22 ) ,
V_342 ,
V_32 | F_51 ( V_346 ) ) ;
-- V_39 ;
V_324 += V_337 ;
V_341 -= V_337 ;
if ( V_341 == 0 ) {
-- V_323 ;
if ( V_323 == 0 )
break;
V_326 = F_173 ( V_326 ) ;
V_22 = ( T_3 ) F_154 ( V_326 ) ;
V_341 = F_153 ( V_326 ) ;
} else {
V_22 += V_337 ;
}
V_337 = V_328 -
( V_22 & ( V_328 - 1 ) ) ;
V_337 = F_155 ( int , V_337 , V_341 ) ;
if ( V_324 + V_337 > V_92 -> V_269 )
V_337 =
V_92 -> V_269 - V_324 ;
} while ( V_324 < V_92 -> V_269 );
F_156 ( V_92 , V_39 , V_324 ) ;
F_158 ( V_10 , V_70 , V_71 , V_92 -> V_72 ,
V_329 , V_245 ) ;
return 0 ;
}
int F_162 ( struct V_9 * V_10 , T_8 V_313 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_11 * V_100 ;
struct V_121 * V_121 ;
struct V_95 * V_251 ;
int V_39 ;
struct V_90 * V_245 ;
bool V_112 ;
bool V_29 ;
int V_329 ;
T_2 V_32 , V_342 ;
int V_324 , V_337 , V_48 ;
unsigned int V_338 ;
T_3 V_22 ;
if ( V_92 -> V_323 )
return F_167 ( V_10 , V_313 , V_92 , V_70 , V_71 ) ;
V_100 = F_43 ( V_10 , V_92 ) ;
if ( ! V_100 )
return - V_318 ;
V_39 = 0 ;
V_324 = V_328 -
( V_92 -> V_347 & ( V_328 - 1 ) ) ;
V_324 &= V_328 - 1 ;
if ( V_324 != 0 || V_92 -> V_269 == 0 )
V_39 ++ ;
while ( V_324 < V_92 -> V_269 ) {
V_39 ++ ;
V_324 += V_328 ;
}
V_48 = F_149 ( V_10 , V_10 -> V_76 [ V_70 ] ,
V_71 , V_92 -> V_72 ,
V_39 , V_92 , 0 , V_313 ) ;
if ( V_48 < 0 )
return V_48 ;
V_121 = V_92 -> V_122 ;
V_251 = V_121 -> V_251 [ 0 ] ;
V_245 = & V_100 -> V_20 -> V_31 ;
V_329 = V_100 -> V_28 ;
V_324 = 0 ;
V_338 = F_168 ( V_92 -> V_269 ,
F_166 ( & V_92 -> V_75 -> V_94 ) ) ;
V_22 = ( T_3 ) V_92 -> V_347 ;
V_337 = V_328 -
( V_92 -> V_347 & ( V_328 - 1 ) ) ;
if ( V_337 > V_92 -> V_269 )
V_337 = V_92 -> V_269 ;
V_112 = true ;
do {
T_2 V_335 = 0 ;
V_32 = 0 ;
if ( V_112 ) {
V_112 = false ;
if ( V_329 == 0 )
V_32 |= 0x1 ;
} else
V_32 |= V_100 -> V_28 ;
if ( V_39 > 1 ) {
V_32 |= V_33 ;
} else {
V_251 -> F_4 = V_100 -> V_20 ;
V_32 |= V_343 ;
}
if ( F_169 ( V_92 ) )
V_32 |= V_344 ;
if ( V_10 -> V_345 < 0x100 ) {
V_335 = F_163 (
V_92 -> V_269 -
V_324 ) ;
} else {
V_335 = F_164 ( V_324 ,
V_337 , V_338 , V_92 ,
V_39 - 1 ) ;
}
V_342 = F_137 ( V_337 ) |
V_335 |
F_170 ( 0 ) ;
if ( V_39 > 1 )
V_29 = true ;
else
V_29 = false ;
F_146 ( V_10 , V_100 , V_29 ,
F_171 ( V_22 ) ,
F_172 ( V_22 ) ,
V_342 ,
V_32 | F_51 ( V_346 ) ) ;
-- V_39 ;
V_324 += V_337 ;
V_22 += V_337 ;
V_337 = V_92 -> V_269 - V_324 ;
if ( V_337 > V_328 )
V_337 = V_328 ;
} while ( V_324 < V_92 -> V_269 );
F_156 ( V_92 , V_39 , V_324 ) ;
F_158 ( V_10 , V_70 , V_71 , V_92 -> V_72 ,
V_329 , V_245 ) ;
return 0 ;
}
int F_174 ( struct V_9 * V_10 , T_8 V_313 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_11 * V_100 ;
int V_39 ;
int V_48 ;
struct V_348 * V_349 ;
struct V_90 * V_245 ;
int V_329 ;
T_2 V_32 , V_342 ;
struct V_121 * V_121 ;
struct V_95 * V_251 ;
V_100 = F_43 ( V_10 , V_92 ) ;
if ( ! V_100 )
return - V_318 ;
if ( ! V_92 -> V_350 )
return - V_318 ;
V_39 = 2 ;
if ( V_92 -> V_269 > 0 )
V_39 ++ ;
V_48 = F_149 ( V_10 , V_10 -> V_76 [ V_70 ] ,
V_71 , V_92 -> V_72 ,
V_39 , V_92 , 0 , V_313 ) ;
if ( V_48 < 0 )
return V_48 ;
V_121 = V_92 -> V_122 ;
V_251 = V_121 -> V_251 [ 0 ] ;
V_245 = & V_100 -> V_20 -> V_31 ;
V_329 = V_100 -> V_28 ;
V_349 = (struct V_348 * ) V_92 -> V_350 ;
V_32 = 0 ;
V_32 |= V_351 | F_51 ( V_352 ) ;
if ( V_329 == 0 )
V_32 |= 0x1 ;
if ( V_10 -> V_345 == 0x100 ) {
if ( V_92 -> V_269 > 0 ) {
if ( V_349 -> V_353 & V_354 )
V_32 |= F_175 ( V_355 ) ;
else
V_32 |= F_175 ( V_356 ) ;
}
}
F_146 ( V_10 , V_100 , true ,
V_349 -> V_353 | V_349 -> V_357 << 8 | F_176 ( V_349 -> V_358 ) << 16 ,
F_176 ( V_349 -> V_359 ) | F_176 ( V_349 -> V_360 ) << 16 ,
F_137 ( 8 ) | F_170 ( 0 ) ,
V_32 ) ;
if ( F_169 ( V_92 ) )
V_32 = V_344 | F_51 ( V_361 ) ;
else
V_32 = F_51 ( V_361 ) ;
V_342 = F_137 ( V_92 -> V_269 ) |
F_163 ( V_92 -> V_269 ) |
F_170 ( 0 ) ;
if ( V_92 -> V_269 > 0 ) {
if ( V_349 -> V_353 & V_354 )
V_32 |= V_362 ;
F_146 ( V_10 , V_100 , true ,
F_171 ( V_92 -> V_347 ) ,
F_172 ( V_92 -> V_347 ) ,
V_342 ,
V_32 | V_100 -> V_28 ) ;
}
V_251 -> F_4 = V_100 -> V_20 ;
if ( V_92 -> V_269 > 0 && V_349 -> V_353 & V_354 )
V_32 = 0 ;
else
V_32 = V_362 ;
F_146 ( V_10 , V_100 , false ,
0 ,
0 ,
F_170 ( 0 ) ,
V_32 | V_343 | F_51 ( V_363 ) | V_100 -> V_28 ) ;
F_158 ( V_10 , V_70 , V_71 , 0 ,
V_329 , V_245 ) ;
return 0 ;
}
static int F_177 ( struct V_9 * V_10 ,
struct V_92 * V_92 , int V_142 )
{
int V_39 = 0 ;
T_3 V_22 , V_364 ;
V_22 = ( T_3 ) ( V_92 -> V_347 + V_92 -> V_280 [ V_142 ] . V_365 ) ;
V_364 = V_92 -> V_280 [ V_142 ] . V_125 ;
V_39 = F_168 ( V_364 + ( V_22 & ( V_328 - 1 ) ) ,
V_328 ) ;
if ( V_39 == 0 )
V_39 ++ ;
return V_39 ;
}
static unsigned int F_178 ( struct V_9 * V_10 ,
struct V_212 * V_213 ,
struct V_92 * V_92 , unsigned int V_338 )
{
unsigned int V_366 ;
if ( V_10 -> V_345 < 0x100 || V_213 -> V_210 != V_367 )
return 0 ;
V_366 = V_92 -> V_75 -> V_368 . V_369 ;
return F_179 ( V_338 , V_366 + 1 ) - 1 ;
}
static unsigned int F_180 ( struct V_9 * V_10 ,
struct V_212 * V_213 ,
struct V_92 * V_92 , unsigned int V_338 )
{
unsigned int V_366 ;
unsigned int V_370 ;
if ( V_10 -> V_345 < 0x100 )
return 0 ;
switch ( V_213 -> V_210 ) {
case V_367 :
V_366 = V_92 -> V_75 -> V_368 . V_369 ;
V_370 = V_338 % ( V_366 + 1 ) ;
if ( V_370 == 0 )
return V_366 ;
return V_370 - 1 ;
default:
if ( V_338 == 0 )
return 0 ;
return V_338 - 1 ;
}
}
static int F_181 ( struct V_9 * V_10 , T_8 V_313 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_11 * V_100 ;
struct V_121 * V_121 ;
struct V_95 * V_251 ;
int V_371 , V_372 ;
struct V_90 * V_245 ;
bool V_112 ;
int V_329 ;
T_2 V_32 , V_342 ;
int V_324 , V_337 , V_364 , V_373 , V_48 ;
T_3 V_374 , V_22 ;
int V_142 , V_143 ;
bool V_29 ;
V_100 = V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] . V_12 ;
V_371 = V_92 -> V_375 ;
if ( V_371 < 1 ) {
F_16 ( V_10 , L_137 ) ;
return - V_318 ;
}
V_374 = ( T_3 ) V_92 -> V_347 ;
V_245 = & V_100 -> V_20 -> V_31 ;
V_329 = V_100 -> V_28 ;
V_121 = V_92 -> V_122 ;
for ( V_142 = 0 ; V_142 < V_371 ; V_142 ++ ) {
unsigned int V_338 ;
unsigned int V_376 ;
unsigned int V_370 ;
V_112 = true ;
V_324 = 0 ;
V_22 = V_374 + V_92 -> V_280 [ V_142 ] . V_365 ;
V_364 = V_92 -> V_280 [ V_142 ] . V_125 ;
V_373 = V_364 ;
V_338 = F_168 ( V_364 ,
F_165 (
F_166 ( & V_92 -> V_75 -> V_94 ) ) ) ;
if ( V_338 == 0 )
V_338 ++ ;
V_376 = F_178 ( V_10 , V_92 -> V_93 , V_92 ,
V_338 ) ;
V_370 = F_180 ( V_10 ,
V_92 -> V_93 , V_92 , V_338 ) ;
V_372 = F_177 ( V_10 , V_92 , V_142 ) ;
V_48 = F_149 ( V_10 , V_10 -> V_76 [ V_70 ] , V_71 ,
V_92 -> V_72 , V_372 , V_92 , V_142 , V_313 ) ;
if ( V_48 < 0 ) {
if ( V_142 == 0 )
return V_48 ;
goto V_226;
}
V_251 = V_121 -> V_251 [ V_142 ] ;
for ( V_143 = 0 ; V_143 < V_372 ; V_143 ++ ) {
T_2 V_335 = 0 ;
V_32 = 0 ;
if ( V_112 ) {
V_32 = F_182 ( V_376 ) |
F_183 ( V_370 ) ;
V_32 |= F_51 ( V_377 ) ;
V_32 |= V_378 ;
if ( V_142 == 0 ) {
if ( V_329 == 0 )
V_32 |= 0x1 ;
} else
V_32 |= V_100 -> V_28 ;
V_112 = false ;
} else {
V_32 |= F_51 ( V_346 ) ;
V_32 |= V_100 -> V_28 ;
}
if ( F_169 ( V_92 ) )
V_32 |= V_344 ;
if ( V_143 < V_372 - 1 ) {
V_32 |= V_33 ;
V_29 = true ;
} else {
V_251 -> F_4 = V_100 -> V_20 ;
V_32 |= V_343 ;
if ( V_10 -> V_345 == 0x100 &&
! ( V_10 -> V_36 &
V_379 ) ) {
if ( V_142 < V_371 - 1 )
V_32 |= V_380 ;
}
V_29 = false ;
}
V_337 = V_328 -
( V_22 & ( ( 1 << V_381 ) - 1 ) ) ;
if ( V_337 > V_373 )
V_337 = V_373 ;
if ( V_10 -> V_345 < 0x100 ) {
V_335 = F_163 (
V_364 - V_324 ) ;
} else {
V_335 = F_164 (
V_324 , V_337 ,
V_338 , V_92 ,
( V_372 - V_143 - 1 ) ) ;
}
V_342 = F_137 ( V_337 ) |
V_335 |
F_170 ( 0 ) ;
F_146 ( V_10 , V_100 , V_29 ,
F_171 ( V_22 ) ,
F_172 ( V_22 ) ,
V_342 ,
V_32 ) ;
V_324 += V_337 ;
V_22 += V_337 ;
V_373 -= V_337 ;
}
if ( V_324 != V_364 ) {
F_23 ( V_10 , L_138 ) ;
V_48 = - V_318 ;
goto V_226;
}
}
if ( F_36 ( V_10 ) -> V_128 . V_129 == 0 ) {
if ( V_10 -> V_36 & V_130 )
F_184 () ;
}
F_36 ( V_10 ) -> V_128 . V_129 ++ ;
F_158 ( V_10 , V_70 , V_71 , V_92 -> V_72 ,
V_329 , V_245 ) ;
return 0 ;
V_226:
for ( V_142 -- ; V_142 >= 0 ; V_142 -- )
F_72 ( & V_121 -> V_251 [ V_142 ] -> V_83 ) ;
V_121 -> V_251 [ 0 ] -> F_4 = V_100 -> V_20 ;
F_50 ( V_10 , V_100 , V_121 -> V_251 [ 0 ] , true ) ;
V_100 -> V_20 = V_121 -> V_251 [ 0 ] -> V_112 ;
V_100 -> V_21 = V_121 -> V_251 [ 0 ] -> V_88 ;
V_100 -> V_28 = V_329 ;
V_100 -> V_27 = V_100 -> V_146 ;
F_60 ( F_57 ( V_92 -> V_93 -> V_124 ) , V_92 ) ;
return V_48 ;
}
int F_185 ( struct V_9 * V_10 , T_8 V_313 ,
struct V_92 * V_92 , int V_70 , unsigned int V_71 )
{
struct V_99 * V_261 ;
struct V_11 * V_100 ;
struct V_101 * V_102 ;
int V_382 ;
int V_330 ;
int V_331 ;
int V_371 , V_39 , V_142 ;
int V_48 ;
V_261 = V_10 -> V_76 [ V_70 ] ;
V_100 = V_261 -> V_77 [ V_71 ] . V_12 ;
V_102 = F_48 ( V_10 , V_261 -> V_107 , V_71 ) ;
V_39 = 0 ;
V_371 = V_92 -> V_375 ;
for ( V_142 = 0 ; V_142 < V_371 ; V_142 ++ )
V_39 += F_177 ( V_10 , V_92 , V_142 ) ;
V_48 = F_147 ( V_10 , V_100 , F_3 ( V_102 -> V_155 ) & V_156 ,
V_39 , V_313 ) ;
if ( V_48 )
return V_48 ;
V_382 = F_18 ( V_10 , & V_10 -> V_383 -> V_384 ) ;
V_382 &= 0x3fff ;
V_92 -> V_382 = V_382 ;
if ( V_92 -> V_93 -> V_210 == V_333 ||
V_92 -> V_93 -> V_210 == V_334 )
V_92 -> V_382 >>= 3 ;
V_330 = F_160 ( F_3 ( V_102 -> V_155 ) ) ;
V_331 = V_92 -> V_332 ;
if ( V_92 -> V_93 -> V_210 == V_333 ||
V_92 -> V_93 -> V_210 == V_334 )
V_331 *= 8 ;
if ( V_330 != V_331 ) {
F_161 ( & V_92 -> V_93 -> V_93 ,
L_132 ,
V_331 , V_331 == 1 ? L_133 : L_134 ,
V_330 , V_330 == 1 ? L_133 : L_134 ) ;
V_92 -> V_332 = V_330 ;
if ( V_92 -> V_93 -> V_210 == V_333 ||
V_92 -> V_93 -> V_210 == V_334 )
V_92 -> V_332 /= 8 ;
}
V_100 -> V_146 = V_100 -> V_27 ;
return F_181 ( V_10 , V_313 , V_92 , V_70 , V_71 ) ;
}
static int F_186 ( struct V_9 * V_10 , T_2 V_309 , T_2 V_310 ,
T_2 V_311 , T_2 V_312 , bool V_385 )
{
int V_386 = V_10 -> V_387 ;
int V_48 ;
if ( ! V_385 )
V_386 ++ ;
V_48 = F_147 ( V_10 , V_10 -> V_50 , V_320 ,
V_386 , V_62 ) ;
if ( V_48 < 0 ) {
F_23 ( V_10 , L_139 ) ;
if ( V_385 )
F_23 ( V_10 , L_140
L_141 ) ;
return V_48 ;
}
F_146 ( V_10 , V_10 -> V_50 , false , V_309 , V_310 , V_311 ,
V_312 | V_10 -> V_50 -> V_28 ) ;
return 0 ;
}
int F_187 ( struct V_9 * V_10 , T_2 V_202 , T_2 V_70 )
{
return F_186 ( V_10 , 0 , 0 , 0 ,
F_51 ( V_202 ) | F_188 ( V_70 ) , false ) ;
}
int F_189 ( struct V_9 * V_10 , T_1 V_388 ,
T_2 V_70 )
{
return F_186 ( V_10 , F_171 ( V_388 ) ,
F_172 ( V_388 ) , 0 ,
F_51 ( V_195 ) | F_188 ( V_70 ) ,
false ) ;
}
int F_190 ( struct V_9 * V_10 ,
T_2 V_309 , T_2 V_310 , T_2 V_311 , T_2 V_312 )
{
return F_186 ( V_10 , V_309 , V_310 , V_311 , V_312 , false ) ;
}
int F_191 ( struct V_9 * V_10 , T_2 V_70 )
{
return F_186 ( V_10 , 0 , 0 , 0 ,
F_51 ( V_199 ) | F_188 ( V_70 ) ,
false ) ;
}
int F_83 ( struct V_9 * V_10 , T_1 V_388 ,
T_2 V_70 , bool V_385 )
{
return F_186 ( V_10 , F_171 ( V_388 ) ,
F_172 ( V_388 ) , 0 ,
F_51 ( V_186 ) | F_188 ( V_70 ) ,
V_385 ) ;
}
int F_192 ( struct V_9 * V_10 , T_1 V_388 ,
T_2 V_70 , bool V_385 )
{
return F_186 ( V_10 , F_171 ( V_388 ) ,
F_172 ( V_388 ) , 0 ,
F_51 ( V_194 ) | F_188 ( V_70 ) ,
V_385 ) ;
}
int F_193 ( struct V_9 * V_10 , int V_70 ,
unsigned int V_71 , int V_389 )
{
T_2 V_390 = F_188 ( V_70 ) ;
T_2 V_391 = F_194 ( V_71 ) ;
T_2 type = F_51 ( V_196 ) ;
T_2 V_392 = F_195 ( V_389 ) ;
return F_186 ( V_10 , 0 , 0 , 0 ,
V_390 | V_391 | type | V_392 , false ) ;
}
static int F_53 ( struct V_9 * V_10 , int V_70 ,
unsigned int V_71 , unsigned int V_72 ,
struct V_1 * V_25 ,
union V_3 * V_393 , T_2 V_28 )
{
T_1 V_22 ;
T_2 V_390 = F_188 ( V_70 ) ;
T_2 V_391 = F_194 ( V_71 ) ;
T_2 V_394 = F_196 ( V_72 ) ;
T_2 type = F_51 ( V_197 ) ;
struct V_74 * V_75 ;
V_22 = F_1 ( V_25 , V_393 ) ;
if ( V_22 == 0 ) {
F_32 ( V_10 , L_142 ) ;
F_32 ( V_10 , L_143 ,
V_25 , V_393 ) ;
return 0 ;
}
V_75 = & V_10 -> V_76 [ V_70 ] -> V_77 [ V_71 ] ;
if ( ( V_75 -> V_78 & V_80 ) ) {
F_32 ( V_10 , L_142 ) ;
F_32 ( V_10 , L_144 ) ;
return 0 ;
}
V_75 -> V_159 = V_25 ;
V_75 -> V_148 = V_393 ;
return F_186 ( V_10 , F_171 ( V_22 ) | V_28 ,
F_172 ( V_22 ) , V_394 ,
V_390 | V_391 | type , false ) ;
}
int F_126 ( struct V_9 * V_10 , int V_70 ,
unsigned int V_71 )
{
T_2 V_390 = F_188 ( V_70 ) ;
T_2 V_391 = F_194 ( V_71 ) ;
T_2 type = F_51 ( V_198 ) ;
return F_186 ( V_10 , 0 , 0 , 0 , V_390 | V_391 | type ,
false ) ;
}
