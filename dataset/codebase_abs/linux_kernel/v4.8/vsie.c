static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
V_2 -> V_4 = 0x1000 ;
V_2 -> V_5 = ( ( V_6 ) V_3 ) << 16 ;
V_2 -> V_7 = V_8 ;
return 1 ;
}
static void F_2 ( struct V_9 * V_9 )
{
F_3 ( V_10 , & V_9 -> V_11 . V_12 ) ;
}
static void F_4 ( struct V_9 * V_9 )
{
F_2 ( V_9 ) ;
if ( V_9 -> V_11 . V_13 & V_14 )
F_3 ( V_15 , & V_9 -> V_11 . V_16 ) ;
while ( V_9 -> V_11 . V_13 & V_14 )
F_5 () ;
}
static void F_6 ( struct V_9 * V_9 )
{
F_7 ( V_10 , & V_9 -> V_11 . V_12 ) ;
}
static int F_8 ( struct V_9 * V_9 )
{
return ! ( F_9 ( & V_9 -> V_11 . V_12 ) & V_10 ) ;
}
static void F_10 ( struct V_9 * V_9 )
{
const int V_17 = V_15 | V_18 | V_19 ;
int V_16 ;
V_16 = F_9 ( & V_9 -> V_20 -> V_16 ) ;
F_7 ( V_17 , & V_9 -> V_11 . V_16 ) ;
F_3 ( V_16 & V_17 , & V_9 -> V_11 . V_16 ) ;
}
static int F_11 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
struct V_1 * V_20 = V_9 -> V_20 ;
int V_23 , V_16 = F_9 ( & V_20 -> V_16 ) ;
if ( ! ( V_16 & V_24 ) )
return F_1 ( V_11 , 0x0001U ) ;
if ( V_16 & ( V_25 | V_26 ) )
return F_1 ( V_11 , 0x0001U ) ;
else if ( V_16 & ( V_27 | V_28 ) )
return F_1 ( V_11 , 0x0007U ) ;
V_23 = V_24 ;
if ( V_16 & V_29 && F_12 ( V_22 -> V_30 , 8 ) )
V_23 |= V_29 ;
if ( V_16 & V_31 && F_12 ( V_22 -> V_30 , 78 ) ) {
if ( V_16 & V_29 )
return F_1 ( V_11 , 0x0001U ) ;
V_23 |= V_31 ;
}
if ( F_13 ( V_22 -> V_30 , V_32 ) )
V_23 |= V_16 & V_33 ;
if ( F_13 ( V_22 -> V_30 , V_34 ) )
V_23 |= V_16 & V_35 ;
if ( F_13 ( V_22 -> V_30 , V_36 ) )
V_23 |= V_16 & V_37 ;
F_14 ( & V_11 -> V_16 , V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
struct V_1 * V_20 = V_9 -> V_20 ;
T_2 V_38 = V_20 -> V_39 & 0x7ffffff8U ;
unsigned long * V_40 , * V_41 ;
T_3 V_42 ;
V_11 -> V_39 = 0 ;
if ( ! ( V_20 -> V_39 & V_22 -> V_43 . V_44 -> V_39 & V_45 ) )
return 0 ;
if ( ! F_12 ( V_22 -> V_30 , 76 ) )
return 0 ;
V_42 = V_20 -> V_46 & V_22 -> V_43 . V_44 -> V_46 &
( V_47 | V_48 ) ;
if ( ! V_42 )
return 0 ;
if ( ( V_38 & V_49 ) != ( ( V_38 + 128 ) & V_49 ) )
return F_1 ( V_11 , 0x003CU ) ;
else if ( ! V_38 )
return F_1 ( V_11 , 0x0039U ) ;
if ( F_16 ( V_22 , V_38 + 72 , & V_9 -> V_50 , 56 ) )
return F_1 ( V_11 , 0x0035U ) ;
V_11 -> V_46 |= V_42 ;
V_11 -> V_39 = ( ( V_6 ) ( V_51 ) & V_9 -> V_50 ) | V_45 |
V_52 ;
V_40 = ( unsigned long * ) V_9 -> V_50 . V_53 ;
V_41 = ( unsigned long * )
V_22 -> V_30 -> V_43 . V_54 . V_50 -> V_53 ;
F_17 ( V_40 , V_40 , V_41 , V_55 * 56 ) ;
return 0 ;
}
static void F_18 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
struct V_1 * V_20 = V_9 -> V_20 ;
V_51 V_56 = ( V_57 . V_58 >> 16 ) & 0x0fffU ;
V_11 -> V_58 = 0 ;
if ( V_22 -> V_30 -> V_43 . V_59 . V_58 && ( V_20 -> V_58 & 0x0fffU ) ) {
V_11 -> V_58 = V_20 -> V_58 & 0x0fffU ;
if ( V_11 -> V_58 < V_56 )
V_11 -> V_58 = V_56 ;
if ( V_11 -> V_58 > V_22 -> V_30 -> V_43 . V_59 . V_58 )
V_11 -> V_58 = V_22 -> V_30 -> V_43 . V_59 . V_58 ;
}
}
static void F_19 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
struct V_1 * V_20 = V_9 -> V_20 ;
V_20 -> V_7 = V_11 -> V_7 ;
V_20 -> V_60 = V_11 -> V_60 ;
V_20 -> V_4 = V_11 -> V_4 ;
V_20 -> V_5 = V_11 -> V_5 ;
V_20 -> V_61 = V_11 -> V_61 ;
V_20 -> V_62 = V_11 -> V_62 ;
V_20 -> V_63 = V_11 -> V_63 ;
V_20 -> V_64 = V_11 -> V_64 ;
V_20 -> V_65 = V_11 -> V_65 ;
V_20 -> V_66 = V_11 -> V_66 ;
V_20 -> V_67 = V_11 -> V_67 ;
memcpy ( V_20 -> V_68 , V_11 -> V_68 , 128 ) ;
V_20 -> V_69 = V_11 -> V_69 ;
switch ( V_11 -> V_7 ) {
case V_70 :
case V_71 :
case V_72 :
memcpy ( ( void * ) ( ( V_73 ) V_20 + 0xc0 ) ,
( void * ) ( ( V_73 ) V_11 + 0xc0 ) , 0xf0 - 0xc0 ) ;
break;
case V_74 :
memcpy ( ( void * ) ( ( V_73 ) V_20 + 0xc0 ) ,
( void * ) ( ( V_73 ) V_11 + 0xc0 ) , 0xd0 - 0xc0 ) ;
break;
}
if ( V_11 -> V_75 != 0xffffU )
V_20 -> V_75 = V_11 -> V_75 ;
}
static int F_20 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_20 = V_9 -> V_20 ;
struct V_1 * V_11 = & V_9 -> V_11 ;
bool V_76 = V_11 -> V_77 & 0x10U ;
unsigned long V_78 = 0 ;
int V_79 ;
V_11 -> V_7 = 0 ;
V_11 -> V_80 = 0 ;
V_11 -> V_77 = 0 ;
V_11 -> V_81 = 0 ;
V_11 -> V_46 = 0 ;
V_11 -> V_82 = 0 ;
V_11 -> V_83 = 0 ;
V_79 = F_11 ( V_22 , V_9 ) ;
if ( V_79 )
goto V_84;
V_11 -> V_62 = V_20 -> V_62 ;
V_11 -> V_63 = V_20 -> V_63 ;
V_11 -> V_64 = V_20 -> V_64 ;
V_11 -> V_85 = V_20 -> V_85 ;
V_11 -> V_65 = V_20 -> V_65 ;
V_11 -> V_66 = V_20 -> V_66 ;
V_11 -> V_67 = V_20 -> V_67 ;
memcpy ( V_11 -> V_68 , V_20 -> V_68 , 128 ) ;
V_11 -> V_69 = V_20 -> V_69 ;
V_11 -> V_61 = V_20 -> V_61 ;
V_11 -> V_86 = V_20 -> V_86 ;
V_11 -> V_87 = V_20 -> V_87 ;
V_11 -> V_88 = V_20 -> V_88 ;
V_11 -> V_88 |= V_89 | V_90 | V_91 ;
V_11 -> V_92 = V_20 -> V_92 ;
if ( ! ( F_9 ( & V_11 -> V_16 ) & V_35 ) )
V_78 = V_20 -> V_93 & 0xfffffffffff00000UL ;
if ( V_11 -> V_93 != V_78 || V_11 -> V_94 != V_20 -> V_94 )
F_2 ( V_9 ) ;
V_11 -> V_95 = V_20 -> V_95 & 0xfffffffffff00000UL ;
V_11 -> V_93 = V_78 ;
V_11 -> V_94 = V_20 -> V_94 ;
if ( V_11 -> V_75 != 0xffffU )
V_11 -> V_75 = V_20 -> V_75 ;
V_11 -> V_80 |= V_20 -> V_80 & 0x01002000U ;
if ( F_13 ( V_22 -> V_30 , V_96 ) )
V_11 -> V_77 |= V_20 -> V_77 & 0x02U ;
if ( F_12 ( V_22 -> V_30 , 73 ) ) {
if ( ( V_20 -> V_77 & 0x10U ) && ! V_76 )
F_2 ( V_9 ) ;
V_11 -> V_77 |= V_20 -> V_77 & 0x10U ;
}
if ( F_12 ( V_22 -> V_30 , 129 ) ) {
V_11 -> V_80 |= V_20 -> V_80 & 0x00020000U ;
V_11 -> V_82 |= V_20 -> V_82 & 0x20000000U ;
}
if ( F_12 ( V_22 -> V_30 , 64 ) )
V_11 -> V_46 |= V_20 -> V_46 & 0x01U ;
if ( F_13 ( V_22 -> V_30 , V_97 ) )
V_11 -> V_80 |= V_20 -> V_80 & 0x00000001U ;
if ( F_13 ( V_22 -> V_30 , V_98 ) )
V_11 -> V_80 |= V_20 -> V_80 & 0x40000000U ;
if ( F_13 ( V_22 -> V_30 , V_99 ) )
V_11 -> V_80 |= V_20 -> V_80 & 0x80000000U ;
F_18 ( V_22 , V_9 ) ;
V_79 = F_15 ( V_22 , V_9 ) ;
V_84:
if ( V_79 )
F_19 ( V_22 , V_9 ) ;
return V_79 ;
}
void F_21 ( struct V_100 * V_100 , unsigned long V_101 ,
unsigned long V_102 )
{
struct V_30 * V_30 = V_100 -> V_103 ;
struct V_9 * V_104 ;
unsigned long V_94 ;
struct V_105 * V_105 ;
int V_106 ;
if ( ! F_22 ( V_100 ) )
return;
if ( V_101 >= 1UL << 31 )
return;
for ( V_106 = 0 ; V_106 < V_30 -> V_43 . V_107 . V_108 ; V_106 ++ ) {
V_105 = F_23 ( V_30 -> V_43 . V_107 . V_109 [ V_106 ] ) ;
if ( ! V_105 )
continue;
V_104 = F_24 ( V_105 ) ;
if ( F_23 ( V_104 -> V_100 ) != V_100 )
continue;
V_94 = V_104 -> V_11 . V_94 << V_110 ;
V_94 += V_104 -> V_11 . V_93 ;
if ( V_94 <= V_102 && V_101 <= V_94 + 2 * V_111 - 1 )
F_4 ( V_104 ) ;
}
}
static int F_25 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
V_73 V_94 = V_11 -> V_94 << V_110 ;
int V_79 ;
if ( F_8 ( V_9 ) )
return 0 ;
F_6 ( V_9 ) ;
V_94 += V_11 -> V_93 ;
V_79 = F_26 ( V_22 , V_9 -> V_100 , V_94 ) ;
if ( ! V_79 && ( V_11 -> V_77 & 0x10U ) )
V_79 = F_26 ( V_22 , V_9 -> V_100 ,
V_94 + V_111 ) ;
if ( V_79 )
F_2 ( V_9 ) ;
if ( V_79 > 0 || V_79 == - V_112 )
V_79 = F_1 ( V_11 , 0x0037U ) ;
return V_79 ;
}
static int F_27 ( struct V_30 * V_30 , T_4 V_113 , T_5 * V_114 )
{
struct V_105 * V_105 ;
T_6 V_115 ;
int V_79 ;
V_115 = F_28 ( V_30 , F_29 ( V_113 ) ) ;
if ( F_30 ( V_115 ) )
return - V_116 ;
V_79 = F_31 ( V_115 , 1 , 1 , & V_105 ) ;
if ( V_79 < 0 )
return V_79 ;
else if ( V_79 != 1 )
return - V_117 ;
* V_114 = ( T_5 ) F_24 ( V_105 ) + ( V_113 & ~ V_49 ) ;
return 0 ;
}
static void F_32 ( struct V_30 * V_30 , T_4 V_113 , T_5 V_114 )
{
struct V_105 * V_105 ;
V_105 = F_33 ( V_114 ) ;
F_34 ( V_105 ) ;
F_35 ( V_105 ) ;
F_36 ( V_30 , F_29 ( V_113 ) ) ;
}
static void F_37 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_20 = V_9 -> V_20 ;
struct V_1 * V_11 = & V_9 -> V_11 ;
T_5 V_114 ;
T_4 V_113 ;
V_114 = ( V_73 ) V_11 -> V_118 << 32 | V_11 -> V_119 ;
if ( V_114 ) {
V_113 = V_20 -> V_119 & ~ 0xfUL ;
if ( F_13 ( V_22 -> V_30 , V_120 ) )
V_113 |= ( V_73 ) V_20 -> V_118 << 32 ;
F_32 ( V_22 -> V_30 , V_113 , V_114 ) ;
V_11 -> V_119 = 0 ;
V_11 -> V_118 = 0 ;
}
V_114 = V_11 -> V_121 ;
if ( V_114 ) {
V_113 = V_20 -> V_121 & ~ 0xffUL ;
F_32 ( V_22 -> V_30 , V_113 , V_114 ) ;
V_11 -> V_121 = 0 ;
}
V_114 = V_11 -> V_122 ;
if ( V_114 ) {
V_113 = V_20 -> V_122 & ~ 0x1ffUL ;
F_32 ( V_22 -> V_30 , V_113 , V_114 ) ;
V_11 -> V_122 = 0 ;
}
V_114 = V_11 -> V_123 ;
if ( V_114 ) {
V_113 = V_20 -> V_123 & ~ 0x3fUL ;
F_32 ( V_22 -> V_30 , V_113 , V_114 ) ;
V_11 -> V_123 = 0 ;
}
}
static int F_38 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_20 = V_9 -> V_20 ;
struct V_1 * V_11 = & V_9 -> V_11 ;
T_5 V_114 ;
T_4 V_113 ;
int V_79 = 0 ;
V_113 = V_20 -> V_119 & ~ 0xfUL ;
if ( F_13 ( V_22 -> V_30 , V_120 ) )
V_113 |= ( V_73 ) V_20 -> V_118 << 32 ;
if ( V_113 ) {
if ( ! ( V_113 & ~ 0x1fffUL ) )
V_79 = F_1 ( V_11 , 0x0038U ) ;
else if ( ( V_113 & ~ 0x1fffUL ) == F_39 ( V_22 ) )
V_79 = F_1 ( V_11 , 0x0011U ) ;
else if ( ( V_113 & V_49 ) !=
( ( V_113 + sizeof( struct V_124 ) - 1 ) & V_49 ) )
V_79 = F_1 ( V_11 , 0x003bU ) ;
if ( ! V_79 ) {
V_79 = F_27 ( V_22 -> V_30 , V_113 , & V_114 ) ;
if ( V_79 == - V_116 )
V_79 = F_1 ( V_11 , 0x0034U ) ;
}
if ( V_79 )
goto V_125;
V_11 -> V_118 = ( T_2 ) ( ( V_73 ) V_114 >> 32 ) ;
V_11 -> V_119 = ( T_2 ) ( V_73 ) V_114 ;
}
V_113 = V_20 -> V_121 & ~ 0xffUL ;
if ( V_113 && ( V_11 -> V_77 & 0x10U ) ) {
if ( ! ( V_113 & ~ 0x1fffU ) ) {
V_79 = F_1 ( V_11 , 0x0080U ) ;
goto V_125;
}
V_79 = F_27 ( V_22 -> V_30 , V_113 , & V_114 ) ;
if ( V_79 == - V_116 )
V_79 = F_1 ( V_11 , 0x0080U ) ;
if ( V_79 )
goto V_125;
V_11 -> V_121 = V_114 ;
}
V_113 = V_20 -> V_122 & ~ 0x1ffUL ;
if ( V_113 && ( V_11 -> V_80 & 0x00020000U ) &&
! ( V_11 -> V_82 & 0x20000000U ) ) {
if ( ! ( V_113 & ~ 0x1fffUL ) ) {
V_79 = F_1 ( V_11 , 0x1310U ) ;
goto V_125;
}
V_79 = F_27 ( V_22 -> V_30 , V_113 , & V_114 ) ;
if ( V_79 == - V_116 )
V_79 = F_1 ( V_11 , 0x1310U ) ;
if ( V_79 )
goto V_125;
V_11 -> V_122 = V_114 ;
}
V_113 = V_20 -> V_123 & ~ 0x3fUL ;
if ( V_113 && ( V_11 -> V_46 & 0x01U ) ) {
if ( ! ( V_113 & ~ 0x1fffUL ) ) {
V_79 = F_1 ( V_11 , 0x0043U ) ;
goto V_125;
}
V_79 = F_27 ( V_22 -> V_30 , V_113 , & V_114 ) ;
if ( V_79 == - V_116 )
V_79 = F_1 ( V_11 , 0x0043U ) ;
if ( V_79 )
goto V_125;
V_11 -> V_123 = V_114 ;
}
return 0 ;
V_125:
F_37 ( V_22 , V_9 ) ;
return V_79 ;
}
static void F_40 ( struct V_21 * V_22 , struct V_9 * V_9 ,
T_4 V_113 )
{
T_5 V_114 = ( T_5 ) V_9 -> V_20 ;
if ( V_114 )
F_32 ( V_22 -> V_30 , V_113 , V_114 ) ;
V_9 -> V_20 = NULL ;
}
static int F_41 ( struct V_21 * V_22 , struct V_9 * V_9 ,
T_4 V_113 )
{
T_5 V_114 ;
int V_79 ;
V_79 = F_27 ( V_22 -> V_30 , V_113 , & V_114 ) ;
if ( V_79 == - V_116 ) {
V_79 = F_42 ( V_22 , V_126 ) ;
if ( ! V_79 )
V_79 = 1 ;
}
if ( ! V_79 )
V_9 -> V_20 = (struct V_1 * ) V_114 ;
return V_79 ;
}
static int F_43 ( struct V_21 * V_22 , T_1 V_127 , V_51 V_128 ,
bool V_129 )
{
struct V_130 V_131 = {
. V_127 = V_127 ,
. V_132 =
( V_128 & 0xfffffffffffff000UL ) |
( ( ( unsigned int ) ! V_129 ) + 1 ) << 10 ,
. V_133 = 0 ,
. V_134 = 0 ,
} ;
int V_79 ;
if ( V_127 == V_135 )
V_131 . V_132 |= 0x4UL ;
V_79 = F_44 ( V_22 , & V_131 ) ;
return V_79 ? V_79 : 1 ;
}
static int F_45 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
int V_79 ;
if ( V_136 -> V_137 . V_138 == V_135 )
return F_43 ( V_22 , V_135 ,
V_136 -> V_137 . V_139 , 1 ) ;
V_79 = F_26 ( V_22 , V_9 -> V_100 ,
V_136 -> V_137 . V_139 ) ;
if ( V_79 > 0 ) {
V_79 = F_43 ( V_22 , V_79 ,
V_136 -> V_137 . V_139 ,
V_136 -> V_137 . V_140 ) ;
if ( V_79 >= 0 )
V_9 -> V_141 = V_136 -> V_137 . V_139 ;
}
return V_79 ;
}
static void F_46 ( struct V_21 * V_22 ,
struct V_9 * V_9 )
{
if ( V_9 -> V_141 )
F_26 ( V_22 , V_9 -> V_100 ,
V_9 -> V_141 ) ;
V_9 -> V_141 = 0 ;
}
static inline void F_47 ( struct V_9 * V_9 )
{
V_9 -> V_11 . V_7 = 0 ;
}
static void F_48 ( struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
int V_142 = F_49 ( V_11 -> V_4 >> 8 ) ;
if ( V_11 -> V_60 & 1 ) {
V_142 = ( V_11 -> V_60 >> 4 ) & 0x6 ;
if ( ! V_142 )
V_142 = 4 ;
}
V_11 -> V_65 . V_143 = F_50 ( V_11 -> V_65 , V_142 ) ;
F_47 ( V_9 ) ;
}
static int F_51 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
V_6 V_83 = V_9 -> V_20 -> V_83 & 0x7ffffff8U ;
if ( V_83 && F_12 ( V_22 -> V_30 , 7 ) ) {
F_48 ( V_9 ) ;
if ( F_16 ( V_22 , V_83 , & V_9 -> V_83 ,
sizeof( V_9 -> V_83 ) ) )
return F_1 ( V_11 , 0x1090U ) ;
V_11 -> V_83 = ( V_6 ) ( V_51 ) & V_9 -> V_83 ;
}
return 0 ;
}
static int F_52 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
struct V_1 * V_20 = V_9 -> V_20 ;
int V_79 ;
F_46 ( V_22 , V_9 ) ;
if ( F_53 () )
F_54 () ;
if ( F_55 ( V_144 ) )
F_56 () ;
F_57 ( & V_22 -> V_30 -> V_145 , V_22 -> V_146 ) ;
F_58 () ;
F_59 () ;
F_60 () ;
V_79 = F_61 ( V_11 , V_22 -> V_147 -> V_148 . V_149 . V_150 ) ;
F_58 () ;
F_62 () ;
F_60 () ;
V_22 -> V_146 = F_63 ( & V_22 -> V_30 -> V_145 ) ;
if ( V_79 > 0 )
V_79 = 0 ;
else if ( V_79 == - V_112 )
return F_45 ( V_22 , V_9 ) ;
switch ( V_11 -> V_7 ) {
case V_151 :
if ( V_11 -> V_4 == 0xb2b0 )
V_79 = F_51 ( V_22 , V_9 ) ;
break;
case V_152 :
if ( ! ( F_9 ( & V_20 -> V_16 ) & V_15 ) )
F_47 ( V_9 ) ;
break;
case V_8 :
if ( ( V_11 -> V_4 & 0xf000 ) != 0xf000 )
V_11 -> V_4 += 0x1000 ;
break;
}
return V_79 ;
}
static void F_64 ( struct V_9 * V_9 )
{
if ( V_9 -> V_100 )
F_65 ( V_9 -> V_100 ) ;
F_66 ( V_9 -> V_100 , NULL ) ;
F_2 ( V_9 ) ;
}
static int F_67 ( struct V_21 * V_22 ,
struct V_9 * V_9 )
{
unsigned long V_153 ;
union V_154 V_155 ;
struct V_100 * V_100 ;
int V_156 ;
V_153 = V_22 -> V_43 . V_44 -> V_68 [ 1 ] ;
V_155 . V_157 = V_22 -> V_43 . V_44 -> V_68 [ 0 ] ;
V_156 = V_155 . V_156 && F_12 ( V_22 -> V_30 , 8 ) ;
V_156 += V_156 && F_12 ( V_22 -> V_30 , 78 ) ;
if ( V_9 -> V_100 && F_68 ( V_9 -> V_100 , V_153 , V_156 ) )
return 0 ;
F_64 ( V_9 ) ;
V_100 = F_69 ( V_22 -> V_43 . V_100 , V_153 , V_156 ) ;
if ( F_70 ( V_100 ) )
return F_71 ( V_100 ) ;
V_100 -> V_103 = V_22 -> V_30 ;
F_66 ( V_9 -> V_100 , V_100 ) ;
return 0 ;
}
static void F_72 ( struct V_21 * V_22 ,
struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
F_66 ( V_22 -> V_43 . V_158 , & V_9 -> V_11 ) ;
F_3 ( V_159 , & V_22 -> V_43 . V_44 -> V_16 ) ;
F_73 () ;
V_11 -> V_85 += V_22 -> V_30 -> V_43 . V_85 ;
F_74 () ;
}
static void F_75 ( struct V_21 * V_22 )
{
F_7 ( V_159 , & V_22 -> V_43 . V_44 -> V_16 ) ;
F_66 ( V_22 -> V_43 . V_158 , NULL ) ;
}
static int F_76 ( struct V_21 * V_22 , struct V_9 * V_9 )
{
struct V_1 * V_11 = & V_9 -> V_11 ;
int V_79 = 0 ;
while ( 1 ) {
V_79 = F_67 ( V_22 , V_9 ) ;
if ( ! V_79 )
V_79 = F_25 ( V_22 , V_9 ) ;
if ( ! V_79 ) {
F_77 ( V_9 -> V_100 ) ;
F_10 ( V_9 ) ;
V_79 = F_52 ( V_22 , V_9 ) ;
F_77 ( V_22 -> V_43 . V_100 ) ;
}
F_7 ( V_160 , & V_11 -> V_12 ) ;
if ( V_79 == - V_161 )
V_79 = 0 ;
if ( V_79 || V_11 -> V_7 || F_78 ( V_136 ) ||
F_79 ( V_22 , 0 ) )
break;
} ;
if ( V_79 == - V_112 ) {
V_11 -> V_7 = V_70 ;
V_11 -> V_162 = V_126 ;
V_11 -> V_163 = 4 ;
V_11 -> V_65 . V_143 = F_50 ( V_11 -> V_65 , 4 ) ;
}
return V_79 ;
}
static struct V_9 * F_80 ( struct V_30 * V_30 , unsigned long V_143 )
{
struct V_9 * V_9 ;
struct V_105 * V_105 ;
int V_164 ;
F_81 () ;
V_105 = F_82 ( & V_30 -> V_43 . V_107 . V_165 , V_143 >> 9 ) ;
F_83 () ;
if ( V_105 ) {
if ( F_84 ( V_105 ) == 2 )
return F_24 ( V_105 ) ;
F_85 ( V_105 ) ;
}
V_164 = F_9 ( & V_30 -> V_166 ) ;
F_86 ( & V_30 -> V_43 . V_107 . V_167 ) ;
if ( V_30 -> V_43 . V_107 . V_108 < V_164 ) {
V_105 = F_87 ( V_168 | V_169 | V_170 ) ;
if ( ! V_105 ) {
F_88 ( & V_30 -> V_43 . V_107 . V_167 ) ;
return F_89 ( - V_117 ) ;
}
F_90 ( V_105 ) ;
V_30 -> V_43 . V_107 . V_109 [ V_30 -> V_43 . V_107 . V_108 ] = V_105 ;
V_30 -> V_43 . V_107 . V_108 ++ ;
} else {
while ( true ) {
V_105 = V_30 -> V_43 . V_107 . V_109 [ V_30 -> V_43 . V_107 . V_171 ] ;
if ( F_84 ( V_105 ) == 2 )
break;
F_85 ( V_105 ) ;
V_30 -> V_43 . V_107 . V_171 ++ ;
V_30 -> V_43 . V_107 . V_171 %= V_164 ;
}
F_91 ( & V_30 -> V_43 . V_107 . V_165 , V_105 -> V_172 >> 9 ) ;
}
V_105 -> V_172 = V_143 ;
if ( F_92 ( & V_30 -> V_43 . V_107 . V_165 , V_143 >> 9 , V_105 ) ) {
F_85 ( V_105 ) ;
F_88 ( & V_30 -> V_43 . V_107 . V_167 ) ;
return NULL ;
}
F_88 ( & V_30 -> V_43 . V_107 . V_167 ) ;
V_9 = F_24 ( V_105 ) ;
memset ( & V_9 -> V_11 , 0 , sizeof( struct V_1 ) ) ;
F_64 ( V_9 ) ;
V_9 -> V_141 = 0 ;
V_9 -> V_11 . V_75 = 0xffffU ;
return V_9 ;
}
static void F_93 ( struct V_30 * V_30 , struct V_9 * V_9 )
{
struct V_105 * V_105 = F_94 ( F_95 ( V_9 ) >> V_173 ) ;
F_85 ( V_105 ) ;
}
int F_96 ( struct V_21 * V_22 )
{
struct V_9 * V_9 ;
unsigned long V_174 ;
int V_79 ;
V_22 -> V_175 . V_176 ++ ;
if ( ! F_13 ( V_22 -> V_30 , V_177 ) )
return - V_178 ;
if ( V_22 -> V_43 . V_44 -> V_65 . V_179 & V_180 )
return F_42 ( V_22 , V_181 ) ;
F_97 ( sizeof( struct V_9 ) != 4096 ) ;
V_174 = F_98 ( V_22 , NULL ) ;
if ( F_99 ( V_174 & 0x1ffUL ) )
return F_42 ( V_22 , V_182 ) ;
if ( F_78 ( V_136 ) || F_79 ( V_22 , 0 ) )
return 0 ;
V_9 = F_80 ( V_22 -> V_30 , V_174 ) ;
if ( F_70 ( V_9 ) )
return F_71 ( V_9 ) ;
else if ( ! V_9 )
return 0 ;
V_79 = F_41 ( V_22 , V_9 , V_174 ) ;
if ( V_79 )
goto V_183;
V_79 = F_20 ( V_22 , V_9 ) ;
if ( V_79 )
goto V_184;
V_79 = F_38 ( V_22 , V_9 ) ;
if ( V_79 )
goto V_185;
F_72 ( V_22 , V_9 ) ;
V_79 = F_76 ( V_22 , V_9 ) ;
F_75 ( V_22 ) ;
F_37 ( V_22 , V_9 ) ;
V_185:
F_19 ( V_22 , V_9 ) ;
V_184:
F_40 ( V_22 , V_9 , V_174 ) ;
V_183:
F_93 ( V_22 -> V_30 , V_9 ) ;
return V_79 < 0 ? V_79 : 0 ;
}
void F_100 ( struct V_30 * V_30 )
{
F_101 ( & V_30 -> V_43 . V_107 . V_167 ) ;
F_102 ( & V_30 -> V_43 . V_107 . V_165 , V_168 ) ;
}
void F_103 ( struct V_30 * V_30 )
{
struct V_9 * V_9 ;
struct V_105 * V_105 ;
int V_106 ;
F_86 ( & V_30 -> V_43 . V_107 . V_167 ) ;
for ( V_106 = 0 ; V_106 < V_30 -> V_43 . V_107 . V_108 ; V_106 ++ ) {
V_105 = V_30 -> V_43 . V_107 . V_109 [ V_106 ] ;
V_30 -> V_43 . V_107 . V_109 [ V_106 ] = NULL ;
V_9 = F_24 ( V_105 ) ;
F_64 ( V_9 ) ;
F_91 ( & V_30 -> V_43 . V_107 . V_165 , V_105 -> V_172 >> 9 ) ;
F_104 ( V_105 ) ;
}
V_30 -> V_43 . V_107 . V_108 = 0 ;
F_88 ( & V_30 -> V_43 . V_107 . V_167 ) ;
}
void F_105 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_23 ( V_22 -> V_43 . V_158 ) ;
if ( V_2 ) {
F_3 ( V_160 , & V_2 -> V_12 ) ;
if ( V_2 -> V_13 & V_14 )
F_3 ( V_15 , & V_2 -> V_16 ) ;
}
}
