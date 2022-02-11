int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , bool V_6 , bool V_7 )
{
struct V_8 * V_8 = V_2 -> V_8 ;
T_2 V_9 ;
int V_10 , V_11 , V_12 ;
T_3 V_13 , V_14 ;
unsigned long V_15 ;
unsigned long V_16 , V_17 , V_18 ;
unsigned long V_19 , V_20 , V_21 ;
unsigned long V_22 ;
unsigned long V_23 ;
switch ( V_3 >> 62 ) {
case 0 :
V_9 = V_2 -> V_24 . V_9 ;
break;
case 3 :
V_9 = 0 ;
break;
default:
return - V_25 ;
}
V_23 = 1 << ( ( V_8 -> V_24 . V_26 & V_27 ) + 12 ) ;
if ( V_9 * 16 >= V_23 )
return - V_25 ;
V_15 = ( V_8 -> V_24 . V_26 & V_28 ) + ( V_9 * 16 ) ;
V_10 = F_2 ( V_8 , V_15 , & V_13 , sizeof( V_13 ) ) ;
if ( V_10 )
return V_10 ;
V_16 = F_3 ( V_13 ) ;
V_19 = ( ( V_16 & V_29 ) >> ( V_30 - 3 ) ) |
( ( V_16 & V_31 ) >> V_32 ) ;
V_20 = V_16 & V_33 ;
V_16 = V_16 & V_34 ;
V_21 = V_19 + 31 ;
if ( F_4 ( V_35 ) )
V_21 -= 3 ;
if ( V_21 != 52 )
return - V_25 ;
for ( V_11 = 3 ; V_11 >= 0 ; -- V_11 ) {
if ( V_11 && V_20 != V_36 [ V_11 ] )
return - V_25 ;
if ( V_11 == 0 && ! ( V_20 == 5 || V_20 == 9 ) )
return - V_25 ;
V_21 -= V_20 ;
V_18 = ( V_3 >> V_21 ) & ( ( 1UL << V_20 ) - 1 ) ;
if ( V_16 & ( ( 1UL << ( V_20 + 3 ) ) - 1 ) )
return - V_25 ;
V_10 = F_2 ( V_8 , V_16 + V_18 * 8 ,
& V_14 , sizeof( V_14 ) ) ;
if ( V_10 )
return V_10 ;
V_17 = F_5 ( V_14 ) ;
if ( ! ( V_17 & V_37 ) )
return - V_38 ;
if ( V_17 & V_39 )
break;
V_20 = V_17 & 0x1f ;
V_16 = V_17 & 0x0fffffffffffff00ul ;
}
if ( V_11 < 0 || V_11 == 3 )
return - V_25 ;
V_22 = V_17 & 0x01fffffffffff000ul ;
if ( V_22 & ( ( 1ul << V_21 ) - 1 ) )
return - V_25 ;
V_22 += V_3 & ( ( 1ul << V_21 ) - 1 ) ;
for ( V_12 = V_40 ; V_12 < V_41 ; ++ V_12 )
if ( V_21 == V_42 [ V_12 ] . V_43 )
break;
V_5 -> V_44 = V_12 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_45 = V_22 ;
V_5 -> V_46 = ! ! ( V_17 & V_47 ) ;
V_5 -> V_48 = ! ! ( V_17 & V_49 ) ;
V_5 -> V_50 = ! ! ( V_17 & V_51 ) ;
if ( F_6 ( V_2 ) & V_52 ) {
if ( V_17 & V_53 ) {
V_5 -> V_46 = 0 ;
V_5 -> V_48 = 0 ;
V_5 -> V_50 = 0 ;
}
} else {
if ( ! ( V_17 & V_53 ) ) {
if ( V_2 -> V_24 . V_54 & ( 1ul << 62 ) )
V_5 -> V_46 = 0 ;
if ( V_2 -> V_24 . V_54 & ( 1ul << 63 ) )
V_5 -> V_48 = 0 ;
if ( V_2 -> V_24 . V_55 & ( 1ul << 62 ) )
V_5 -> V_50 = 0 ;
}
}
return 0 ;
}
static void F_7 ( struct V_8 * V_8 , unsigned long V_56 ,
unsigned int V_57 )
{
int V_58 = V_59 ;
if ( V_57 >= V_60 )
V_58 = V_61 ;
V_56 &= ~ 0xfffUL ;
V_56 |= V_42 [ V_58 ] . V_62 << 5 ;
asm volatile("ptesync": : :"memory");
asm volatile(PPC_TLBIE_5(%0, %1, 0, 0, 1)
: : "r" (addr), "r" (kvm->arch.lpid) : "memory");
asm volatile("ptesync": : :"memory");
}
unsigned long F_8 ( struct V_8 * V_8 , T_4 * V_63 ,
unsigned long V_64 , unsigned long V_65 ,
unsigned long V_56 , unsigned int V_43 )
{
unsigned long V_66 = 0 ;
if ( ! ( V_64 & V_37 ) && F_4 ( V_35 ) &&
F_9 ( * V_63 ) ) {
V_66 = F_10 ( V_63 , V_37 , 0 ) ;
F_7 ( V_8 , V_56 , V_43 ) ;
V_65 |= V_37 ;
V_66 &= V_37 ;
}
return F_10 ( V_63 , V_64 , V_65 ) | V_66 ;
}
void F_11 ( struct V_8 * V_8 , unsigned long V_56 ,
T_4 * V_63 , T_4 V_17 )
{
F_12 ( V_8 -> V_67 , V_56 , V_63 , V_17 , 0 ) ;
}
static T_4 * F_13 ( void )
{
return F_14 ( V_68 , V_69 ) ;
}
static void F_15 ( T_4 * V_63 )
{
F_16 ( V_68 , V_63 ) ;
}
static int F_17 ( struct V_8 * V_8 , T_4 V_17 , unsigned long V_22 ,
unsigned int V_11 , unsigned long V_70 )
{
T_5 * V_71 ;
T_6 * V_72 , * V_73 = NULL ;
T_7 * V_74 , * V_75 = NULL ;
T_4 * V_63 , * V_76 = NULL ;
unsigned long V_66 ;
int V_10 ;
V_71 = V_8 -> V_24 . V_77 + F_18 ( V_22 ) ;
V_72 = NULL ;
if ( F_19 ( * V_71 ) )
V_72 = F_20 ( V_71 , V_22 ) ;
else
V_73 = F_21 ( V_8 -> V_67 , V_22 ) ;
V_74 = NULL ;
if ( V_72 && F_22 ( * V_72 ) )
V_74 = F_23 ( V_72 , V_22 ) ;
else
V_75 = F_24 ( V_8 -> V_67 , V_22 ) ;
if ( V_11 == 0 && ! ( V_74 && F_25 ( * V_74 ) ) )
V_76 = F_13 () ;
F_26 ( & V_8 -> V_78 ) ;
V_10 = - V_79 ;
if ( F_27 ( V_8 , V_70 ) )
goto V_80;
V_10 = - V_81 ;
if ( F_28 ( * V_71 ) ) {
if ( ! V_73 )
goto V_80;
F_29 ( V_8 -> V_67 , V_71 , V_73 ) ;
V_73 = NULL ;
}
V_72 = F_20 ( V_71 , V_22 ) ;
if ( F_30 ( * V_72 ) ) {
if ( ! V_75 )
goto V_80;
F_31 ( V_8 -> V_67 , V_72 , V_75 ) ;
V_75 = NULL ;
}
V_74 = F_23 ( V_72 , V_22 ) ;
if ( F_32 ( * V_74 ) ) {
V_10 = - V_79 ;
goto V_80;
}
if ( V_11 == 1 && ! F_33 ( * V_74 ) ) {
V_10 = - V_82 ;
goto V_80;
}
if ( V_11 == 0 ) {
if ( F_33 ( * V_74 ) ) {
if ( ! V_76 )
goto V_80;
F_34 ( V_8 -> V_67 , V_74 , V_76 ) ;
V_76 = NULL ;
}
V_63 = F_35 ( V_74 , V_22 ) ;
if ( F_9 ( * V_63 ) ) {
V_66 = F_8 ( V_8 , V_63 , V_37 ,
0 , V_22 , 0 ) ;
F_7 ( V_8 , V_22 , 0 ) ;
if ( V_66 & V_83 )
F_36 ( V_8 , V_22 >> V_84 ) ;
}
F_11 ( V_8 , V_22 , V_63 , V_17 ) ;
} else {
F_11 ( V_8 , V_22 , F_37 ( V_74 ) , V_17 ) ;
}
V_10 = 0 ;
V_80:
F_38 ( & V_8 -> V_78 ) ;
if ( V_73 )
F_39 ( V_8 -> V_67 , V_73 ) ;
if ( V_75 )
F_40 ( V_8 -> V_67 , V_75 ) ;
if ( V_76 )
F_15 ( V_76 ) ;
return V_10 ;
}
int F_41 ( struct V_85 * V_86 , struct V_1 * V_2 ,
unsigned long V_87 , unsigned long V_88 )
{
struct V_8 * V_8 = V_2 -> V_8 ;
unsigned long V_70 , V_89 ;
unsigned long V_22 , V_90 , V_91 , V_92 ;
struct V_93 * V_94 ;
struct V_95 * V_95 = NULL , * V_96 [ 1 ] ;
long V_10 , V_97 , V_98 ;
unsigned int V_99 ;
struct V_100 * V_101 ;
unsigned long V_102 ;
T_4 V_17 , * V_63 ;
unsigned long V_103 ;
unsigned int V_43 , V_11 ;
if ( V_88 & V_104 ) {
F_42 ( L_1 ) ;
return - V_105 ;
}
if ( V_88 & V_106 ) {
F_42 ( L_2 , V_88 ) ;
F_43 ( V_2 , V_87 , V_88 ) ;
return V_107 ;
}
V_22 = V_2 -> V_24 . V_108 & ~ 0xfffUL ;
V_22 &= ~ 0xF000000000000000ul ;
V_90 = V_22 >> V_84 ;
if ( ! ( V_88 & V_109 ) )
V_22 |= V_87 & 0xfff ;
V_94 = F_44 ( V_8 , V_90 ) ;
if ( ! V_94 || ( V_94 -> V_102 & V_110 ) ) {
if ( V_88 & ( V_109 | V_106 |
V_111 ) ) {
F_43 ( V_2 , V_87 , V_88 ) ;
return V_107 ;
}
return F_45 ( V_86 , V_2 , V_22 , V_87 ,
V_88 & V_112 ) ;
}
V_70 = V_8 -> V_113 ;
F_46 () ;
V_99 = ( V_88 & V_112 ) != 0 ;
V_91 = F_47 ( V_94 , V_90 ) ;
if ( V_88 & V_111 ) {
V_98 = 0 ;
V_103 = V_114 ;
if ( V_99 )
V_103 |= V_83 ;
F_48 ( V_102 ) ;
V_63 = F_49 ( V_115 -> V_67 -> V_71 , V_91 ,
NULL , NULL ) ;
if ( V_63 ) {
V_17 = F_50 ( * V_63 ) ;
if ( F_9 ( V_17 ) &&
( F_51 ( V_17 ) & V_103 ) == V_103 )
V_98 = 1 ;
}
F_52 ( V_102 ) ;
if ( V_98 ) {
F_26 ( & V_8 -> V_78 ) ;
if ( F_27 ( V_2 -> V_8 , V_70 ) ) {
F_38 ( & V_8 -> V_78 ) ;
return V_107 ;
}
V_63 = F_49 ( V_8 -> V_24 . V_77 ,
V_22 , NULL , & V_43 ) ;
if ( V_63 && F_9 ( * V_63 ) ) {
F_8 ( V_8 , V_63 , 0 , V_103 ,
V_22 , V_43 ) ;
F_38 ( & V_8 -> V_78 ) ;
return V_107 ;
}
F_38 ( & V_8 -> V_78 ) ;
}
}
V_10 = - V_105 ;
V_92 = 0 ;
V_89 = V_116 ;
V_103 = V_47 | V_51 ;
V_11 = 0 ;
V_97 = F_53 ( V_91 , 1 , V_99 , V_96 ) ;
if ( V_97 < 1 ) {
F_54 ( & V_115 -> V_67 -> V_117 ) ;
V_101 = F_55 ( V_115 -> V_67 , V_91 ) ;
if ( V_101 && V_101 -> V_118 <= V_91 && V_91 < V_101 -> V_119 &&
( V_101 -> V_120 & V_121 ) ) {
V_92 = V_101 -> V_122 +
( ( V_91 - V_101 -> V_118 ) >> V_84 ) ;
V_103 = F_56 ( V_101 -> V_123 ) ;
}
F_57 ( & V_115 -> V_67 -> V_117 ) ;
if ( ! V_92 )
return - V_105 ;
} else {
V_95 = V_96 [ 0 ] ;
V_92 = F_58 ( V_95 ) ;
if ( F_59 ( V_95 ) ) {
V_95 = F_60 ( V_95 ) ;
V_89 <<= F_61 ( V_95 ) ;
if ( V_89 >= V_124 &&
( V_22 & V_125 & V_126 ) ==
( V_91 & V_125 & V_126 ) ) {
V_11 = 1 ;
V_92 &= ~ ( ( V_124 >> V_84 ) - 1 ) ;
}
}
if ( V_99 ) {
V_103 |= V_49 ;
} else {
F_48 ( V_102 ) ;
V_63 = F_49 ( V_115 -> V_67 -> V_71 ,
V_91 , NULL , NULL ) ;
if ( V_63 && F_62 ( * V_63 ) && F_63 ( * V_63 ) )
V_103 |= V_49 ;
F_52 ( V_102 ) ;
}
}
V_103 |= V_37 | V_39 | V_114 ;
if ( V_103 & V_49 )
V_103 |= V_83 ;
V_17 = F_64 ( V_92 , F_65 ( V_103 ) ) ;
V_10 = F_17 ( V_8 , V_17 , V_22 , V_11 , V_70 ) ;
if ( V_10 == - V_82 ) {
V_11 = 0 ;
V_92 |= V_90 & ( ( V_124 >> V_84 ) - 1 ) ;
V_17 = F_64 ( V_92 , F_65 ( V_103 ) ) ;
V_10 = F_17 ( V_8 , V_17 , V_22 , V_11 , V_70 ) ;
}
if ( V_10 == 0 || V_10 == - V_79 )
V_10 = V_107 ;
if ( V_95 ) {
F_66 ( V_96 [ 0 ] ) ;
}
return V_10 ;
}
static void F_67 ( struct V_8 * V_8 , struct V_93 * V_94 ,
unsigned long V_90 , unsigned int V_127 )
{
unsigned long V_128 , V_129 ;
unsigned long * V_130 ;
if ( ! V_94 -> V_131 )
return;
V_129 = 1ul << V_127 ;
if ( V_129 < V_132 ) {
for ( V_128 = 0 ; V_128 < V_129 ; ++ V_128 )
F_36 ( V_8 , V_90 + V_128 ) ;
return;
}
V_130 = V_94 -> V_131 + ( V_90 - V_94 -> V_133 ) ;
V_129 /= V_132 ;
for ( V_128 = 0 ; V_128 < V_129 ; ++ V_128 )
* V_130 ++ = ~ 0ul ;
}
int F_68 ( struct V_8 * V_8 , struct V_93 * V_94 ,
unsigned long V_90 )
{
T_4 * V_63 ;
unsigned long V_22 = V_90 << V_84 ;
unsigned int V_43 ;
unsigned long V_66 ;
V_63 = F_49 ( V_8 -> V_24 . V_77 , V_22 ,
NULL , & V_43 ) ;
if ( V_63 && F_9 ( * V_63 ) ) {
V_66 = F_8 ( V_8 , V_63 , V_37 , 0 ,
V_22 , V_43 ) ;
F_7 ( V_8 , V_22 , V_43 ) ;
if ( V_66 & V_83 ) {
if ( ! V_43 )
F_36 ( V_8 , V_90 ) ;
else
F_67 ( V_8 , V_94 ,
V_90 , V_43 - V_84 ) ;
}
}
return 0 ;
}
int F_69 ( struct V_8 * V_8 , struct V_93 * V_94 ,
unsigned long V_90 )
{
T_4 * V_63 ;
unsigned long V_22 = V_90 << V_84 ;
unsigned int V_43 ;
int V_134 = 0 ;
V_63 = F_49 ( V_8 -> V_24 . V_77 , V_22 ,
NULL , & V_43 ) ;
if ( V_63 && F_9 ( * V_63 ) && F_70 ( * V_63 ) ) {
F_8 ( V_8 , V_63 , V_114 , 0 ,
V_22 , V_43 ) ;
V_134 = 1 ;
}
return V_134 ;
}
int F_71 ( struct V_8 * V_8 , struct V_93 * V_94 ,
unsigned long V_90 )
{
T_4 * V_63 ;
unsigned long V_22 = V_90 << V_84 ;
unsigned int V_43 ;
int V_134 = 0 ;
V_63 = F_49 ( V_8 -> V_24 . V_77 , V_22 ,
NULL , & V_43 ) ;
if ( V_63 && F_9 ( * V_63 ) && F_70 ( * V_63 ) )
V_134 = 1 ;
return V_134 ;
}
static int F_72 ( struct V_8 * V_8 ,
struct V_93 * V_94 , int V_135 )
{
unsigned long V_90 = V_94 -> V_133 + V_135 ;
unsigned long V_22 = V_90 << V_84 ;
T_4 * V_63 ;
unsigned int V_43 ;
int V_10 = 0 ;
V_63 = F_49 ( V_8 -> V_24 . V_77 , V_22 ,
NULL , & V_43 ) ;
if ( V_63 && F_9 ( * V_63 ) && F_63 ( * V_63 ) ) {
V_10 = 1 ;
if ( V_43 )
V_10 = 1 << ( V_43 - V_84 ) ;
F_8 ( V_8 , V_63 , V_83 , 0 ,
V_22 , V_43 ) ;
F_7 ( V_8 , V_22 , V_43 ) ;
}
return V_10 ;
}
long F_73 ( struct V_8 * V_8 ,
struct V_93 * V_94 , unsigned long * V_136 )
{
unsigned long V_128 , V_137 ;
unsigned long V_138 , * V_139 ;
int V_97 ;
V_138 = F_74 ( V_94 ) / sizeof( long ) ;
V_139 = V_94 -> V_131 ;
for ( V_128 = 0 ; V_128 < V_138 ; ++ V_128 )
V_136 [ V_128 ] |= F_75 ( & V_139 [ V_128 ] , 0 ) ;
for ( V_128 = 0 ; V_128 < V_94 -> V_97 ; V_128 = V_137 ) {
V_97 = F_72 ( V_8 , V_94 , V_128 ) ;
V_137 = V_128 + 1 ;
if ( V_97 )
for ( V_137 = V_128 ; V_97 ; ++ V_137 , -- V_97 )
F_76 ( V_137 , V_136 ) ;
}
return 0 ;
}
static void F_77 ( struct V_140 * V_141 ,
int V_58 , int * V_142 )
{
if ( ! V_42 [ V_58 ] . V_43 )
return;
V_141 -> V_143 [ * V_142 ] = V_42 [ V_58 ] . V_43 |
( V_42 [ V_58 ] . V_62 << 29 ) ;
++ ( * V_142 ) ;
}
int F_78 ( struct V_8 * V_8 , struct V_140 * V_141 )
{
int V_128 ;
if ( ! F_79 () )
return - V_25 ;
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_141 -> V_144 [ 0 ] . V_145 = 12 ;
V_141 -> V_144 [ 0 ] . V_146 [ 0 ] = 9 ;
for ( V_128 = 1 ; V_128 < 4 ; ++ V_128 )
V_141 -> V_144 [ 0 ] . V_146 [ V_128 ] = V_36 [ V_128 ] ;
V_141 -> V_144 [ 1 ] . V_145 = 16 ;
for ( V_128 = 0 ; V_128 < 4 ; ++ V_128 )
V_141 -> V_144 [ 1 ] . V_146 [ V_128 ] = V_36 [ V_128 ] ;
V_128 = 0 ;
F_77 ( V_141 , V_40 , & V_128 ) ;
F_77 ( V_141 , V_147 , & V_128 ) ;
F_77 ( V_141 , V_61 , & V_128 ) ;
F_77 ( V_141 , V_148 , & V_128 ) ;
return 0 ;
}
int F_80 ( struct V_8 * V_8 )
{
V_8 -> V_24 . V_77 = F_81 ( V_8 -> V_67 ) ;
if ( ! V_8 -> V_24 . V_77 )
return - V_81 ;
return 0 ;
}
void F_82 ( struct V_8 * V_8 )
{
unsigned long V_149 , V_150 , V_151 ;
T_4 * V_17 ;
T_7 * V_74 ;
T_6 * V_72 ;
T_5 * V_71 ;
if ( ! V_8 -> V_24 . V_77 )
return;
V_71 = V_8 -> V_24 . V_77 ;
for ( V_149 = 0 ; V_149 < V_152 ; ++ V_149 , ++ V_71 ) {
if ( ! F_19 ( * V_71 ) )
continue;
V_72 = F_20 ( V_71 , 0 ) ;
for ( V_150 = 0 ; V_150 < V_153 ; ++ V_150 , ++ V_72 ) {
if ( ! F_22 ( * V_72 ) )
continue;
V_74 = F_23 ( V_72 , 0 ) ;
for ( V_151 = 0 ; V_151 < V_154 ; ++ V_151 , ++ V_74 ) {
if ( F_83 ( * V_74 ) ) {
F_84 ( V_74 ) ;
continue;
}
if ( ! F_25 ( * V_74 ) )
continue;
V_17 = F_85 ( V_74 , 0 ) ;
memset ( V_17 , 0 , sizeof( long ) << V_155 ) ;
F_15 ( V_17 ) ;
F_84 ( V_74 ) ;
}
F_40 ( V_8 -> V_67 , F_23 ( V_72 , 0 ) ) ;
F_86 ( V_72 ) ;
}
F_39 ( V_8 -> V_67 , F_20 ( V_71 , 0 ) ) ;
F_87 ( V_71 ) ;
}
F_88 ( V_8 -> V_67 , V_8 -> V_24 . V_77 ) ;
}
static void F_89 ( void * V_56 )
{
memset ( V_56 , 0 , V_156 ) ;
}
int F_90 ( void )
{
unsigned long V_157 = sizeof( void * ) << V_155 ;
V_68 = F_91 ( L_3 , V_157 , V_157 , 0 , F_89 ) ;
if ( ! V_68 )
return - V_81 ;
return 0 ;
}
void F_92 ( void )
{
F_93 ( V_68 ) ;
}
