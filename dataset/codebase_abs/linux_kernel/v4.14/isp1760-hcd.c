static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return * (struct V_1 * * ) V_3 -> V_4 ;
}
static T_1 F_2 ( void T_2 * V_5 , T_1 V_6 )
{
return F_3 ( V_5 , V_6 ) ;
}
static void F_4 ( void T_2 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_5 ( V_5 , V_6 , V_7 ) ;
}
static void F_6 ( void T_2 * V_8 , T_1 V_9 , T_1 V_10 ,
T_3 * V_11 , T_1 V_12 )
{
T_3 T_2 * V_13 ;
T_1 V_7 ;
T_4 * V_14 ;
T_4 * V_15 ;
V_13 = V_8 + ( V_10 | V_9 ) ;
if ( V_9 < V_16 ) {
while ( V_12 >= 4 ) {
* V_11 = F_7 ( F_8 ( V_13 ) ) ;
V_12 -= 4 ;
V_13 ++ ;
V_11 ++ ;
}
} else {
while ( V_12 >= 4 ) {
* V_11 = F_8 ( V_13 ) ;
V_12 -= 4 ;
V_13 ++ ;
V_11 ++ ;
}
}
if ( ! V_12 )
return;
if ( V_9 < V_16 )
V_7 = F_7 ( F_8 ( V_13 ) ) ;
else
V_7 = F_8 ( V_13 ) ;
V_15 = ( void * ) V_11 ;
V_14 = ( void * ) & V_7 ;
while ( V_12 > 0 ) {
* V_15 = * V_14 ;
V_15 ++ ;
V_14 ++ ;
V_12 -- ;
}
}
static void F_9 ( void T_2 * V_8 , T_1 V_9 , void * V_11 ,
T_1 V_12 )
{
F_4 ( V_8 , V_17 , V_9 + F_10 ( 0 ) ) ;
F_11 ( 90 ) ;
F_6 ( V_8 , V_9 , F_10 ( 0 ) , V_11 , V_12 ) ;
}
static void F_12 ( void T_2 * V_18 , T_1 V_19 ,
T_3 const * V_13 , T_1 V_12 )
{
T_3 T_2 * V_11 ;
V_11 = V_18 + V_19 ;
if ( V_19 < V_16 ) {
while ( V_12 >= 4 ) {
F_13 ( F_14 ( * V_13 ) , V_11 ) ;
V_12 -= 4 ;
V_13 ++ ;
V_11 ++ ;
}
} else {
while ( V_12 >= 4 ) {
F_13 ( * V_13 , V_11 ) ;
V_12 -= 4 ;
V_13 ++ ;
V_11 ++ ;
}
}
if ( ! V_12 )
return;
if ( V_19 < V_16 )
F_13 ( F_14 ( * V_13 ) , V_11 ) ;
else
F_13 ( * V_13 , V_11 ) ;
}
static void F_15 ( void T_2 * V_5 , T_1 V_20 , T_1 V_21 ,
struct V_22 * V_22 )
{
F_4 ( V_5 , V_17 ,
F_10 ( 0 ) + V_20 + V_21 * sizeof( * V_22 ) ) ;
F_11 ( 90 ) ;
F_6 ( V_5 , V_20 + V_21 * sizeof( * V_22 ) , F_10 ( 0 ) ,
( void * ) V_22 , sizeof( * V_22 ) ) ;
}
static void F_16 ( void T_2 * V_5 , T_1 V_20 , T_1 V_21 ,
struct V_22 * V_22 )
{
F_12 ( V_5 , V_20 + V_21 * sizeof( * V_22 ) + sizeof( V_22 -> V_23 ) ,
& V_22 -> V_24 , 7 * sizeof( V_22 -> V_24 ) ) ;
F_17 () ;
F_12 ( V_5 , V_20 + V_21 * sizeof( * V_22 ) , & V_22 -> V_23 ,
sizeof( V_22 -> V_23 ) ) ;
}
static void F_18 ( struct V_1 * V_25 )
{
int V_26 , V_27 ;
T_1 V_28 ;
V_28 = V_16 ;
for ( V_26 = 0 ; V_26 < V_29 ; V_26 ++ ) {
V_25 -> V_30 [ V_26 ] . V_31 = V_28 ;
V_25 -> V_30 [ V_26 ] . V_32 = V_33 ;
V_25 -> V_30 [ V_26 ] . free = 1 ;
V_28 += V_25 -> V_30 [ V_26 ] . V_32 ;
}
V_27 = V_26 ;
for ( V_26 = 0 ; V_26 < V_34 ; V_26 ++ ) {
V_25 -> V_30 [ V_27 + V_26 ] . V_31 = V_28 ;
V_25 -> V_30 [ V_27 + V_26 ] . V_32 = V_35 ;
V_25 -> V_30 [ V_27 + V_26 ] . free = 1 ;
V_28 += V_25 -> V_30 [ V_27 + V_26 ] . V_32 ;
}
V_27 = V_26 ;
for ( V_26 = 0 ; V_26 < V_36 ; V_26 ++ ) {
V_25 -> V_30 [ V_27 + V_26 ] . V_31 = V_28 ;
V_25 -> V_30 [ V_27 + V_26 ] . V_32 = V_37 ;
V_25 -> V_30 [ V_27 + V_26 ] . free = 1 ;
V_28 += V_25 -> V_30 [ V_27 + V_26 ] . V_32 ;
}
F_19 ( V_28 - V_25 -> V_30 [ 0 ] . V_31 > V_38 ) ;
}
static void F_20 ( struct V_2 * V_3 , struct V_39 * V_40 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_26 ;
F_19 ( V_40 -> V_28 ) ;
if ( ! V_40 -> V_41 )
return;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ ) {
if ( V_25 -> V_30 [ V_26 ] . V_32 >= V_40 -> V_41 &&
V_25 -> V_30 [ V_26 ] . free ) {
V_25 -> V_30 [ V_26 ] . free = 0 ;
V_40 -> V_28 = V_25 -> V_30 [ V_26 ] . V_31 ;
return;
}
}
}
static void F_21 ( struct V_2 * V_3 , struct V_39 * V_40 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_26 ;
if ( ! V_40 -> V_28 )
return;
for ( V_26 = 0 ; V_26 < V_42 ; V_26 ++ ) {
if ( V_25 -> V_30 [ V_26 ] . V_31 == V_40 -> V_28 ) {
F_19 ( V_25 -> V_30 [ V_26 ] . free ) ;
V_25 -> V_30 [ V_26 ] . free = 1 ;
V_40 -> V_28 = 0 ;
return;
}
}
F_22 ( V_3 -> V_43 . V_44 , L_1 ,
V_45 , V_40 -> V_28 ) ;
F_19 ( 1 ) ;
V_40 -> V_28 = 0 ;
}
static int F_23 ( struct V_2 * V_3 , T_1 V_6 ,
T_1 V_46 , T_1 V_47 , int V_48 )
{
T_1 V_49 ;
do {
V_49 = F_2 ( V_3 -> V_50 , V_6 ) ;
if ( V_49 == ~ 0 )
return - V_51 ;
V_49 &= V_46 ;
if ( V_49 == V_47 )
return 0 ;
F_24 ( 1 ) ;
V_48 -- ;
} while ( V_48 > 0 );
return - V_52 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_53 = F_2 ( V_3 -> V_50 , V_54 ) ;
V_53 |= V_55 ;
F_4 ( V_3 -> V_50 , V_54 , V_53 ) ;
V_3 -> V_56 = V_57 ;
V_25 -> V_58 = V_59 ;
return F_23 ( V_3 , V_54 , V_55 , 0 , 250 * 1000 ) ;
}
static struct V_60 * F_26 ( T_5 V_61 )
{
struct V_60 * V_62 ;
V_62 = F_27 ( V_63 , V_61 ) ;
if ( ! V_62 )
return NULL ;
F_28 ( & V_62 -> V_64 ) ;
F_28 ( & V_62 -> V_65 ) ;
V_62 -> V_21 = - 1 ;
return V_62 ;
}
static void F_29 ( struct V_60 * V_62 )
{
F_19 ( ! F_30 ( & V_62 -> V_65 ) ) ;
F_19 ( V_62 -> V_21 > - 1 ) ;
F_31 ( V_63 , V_62 ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_66 ;
int V_26 ;
F_33 ( & V_25 -> V_67 ) ;
for ( V_26 = 0 ; V_26 < V_68 ; V_26 ++ )
F_28 ( & V_25 -> V_64 [ V_26 ] ) ;
V_25 -> V_69 = V_70 ;
V_66 = F_2 ( V_3 -> V_50 , V_71 ) ;
if ( F_34 ( V_66 ) )
V_25 -> V_72 = 8 ;
else
V_25 -> V_72 = 2 + F_35 ( V_66 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_49 ;
T_1 V_73 , V_74 ;
F_4 ( V_3 -> V_50 , V_75 , 0xdeadbabe ) ;
V_73 = F_2 ( V_3 -> V_50 , V_76 ) ;
V_73 = F_2 ( V_3 -> V_50 , V_75 ) ;
if ( V_73 != 0xdeadbabe ) {
F_22 ( V_3 -> V_43 . V_44 , L_2 ) ;
return - V_51 ;
}
F_4 ( V_3 -> V_50 , V_77 , 0 ) ;
F_4 ( V_3 -> V_50 , V_78 , V_79 ) ;
F_4 ( V_3 -> V_50 , V_80 , V_79 ) ;
F_4 ( V_3 -> V_50 , V_81 , V_79 ) ;
V_49 = F_25 ( V_3 ) ;
if ( V_49 )
return V_49 ;
V_74 = F_2 ( V_3 -> V_50 , V_82 ) & ~ V_83 ;
F_4 ( V_3 -> V_50 , V_82 , V_74 | V_83 ) ;
F_37 ( 10 ) ;
F_4 ( V_3 -> V_50 , V_82 , V_74 ) ;
F_4 ( V_3 -> V_50 , V_84 , V_85 ) ;
V_25 -> V_86 = F_2 ( V_3 -> V_50 , V_87 ) ;
return F_32 ( V_3 ) ;
}
static T_1 F_38 ( T_1 V_5 )
{
return ( ( V_5 - 0x400 ) >> 3 ) ;
}
static int F_39 ( struct V_39 * V_40 , struct V_60 * V_62 )
{
struct V_88 * V_88 ;
if ( F_40 ( & V_40 -> V_65 , & V_62 -> V_65 ) )
return 1 ;
V_88 = V_40 -> V_88 ;
V_40 = F_41 ( V_40 -> V_65 . V_89 , F_42 ( * V_40 ) , V_65 ) ;
return ( V_40 -> V_88 != V_88 ) ;
}
static void F_43 ( struct V_60 * V_62 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
T_1 V_90 ;
T_1 V_91 ;
T_1 V_92 = V_93 ;
T_1 V_94 = V_95 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_90 = F_44 ( V_40 -> V_88 -> V_96 , V_40 -> V_88 -> V_97 ,
F_45 ( V_40 -> V_88 -> V_97 ) ) ;
V_91 = 1 + ( ( V_90 >> 11 ) & 0x3 ) ;
V_90 &= 0x7ff ;
V_22 -> V_23 = V_98 ;
V_22 -> V_23 |= F_46 ( V_40 -> V_41 ) ;
V_22 -> V_23 |= F_47 ( V_90 ) ;
V_22 -> V_23 |= F_48 ( F_49 ( V_40 -> V_88 -> V_97 ) ) ;
V_22 -> V_24 = F_49 ( V_40 -> V_88 -> V_97 ) >> 1 ;
V_22 -> V_24 |= F_50 ( F_51 ( V_40 -> V_88 -> V_97 ) ) ;
V_22 -> V_24 |= F_52 ( V_40 -> V_99 ) ;
if ( F_53 ( V_40 -> V_88 -> V_97 ) )
V_22 -> V_24 |= V_100 ;
else if ( F_54 ( V_40 -> V_88 -> V_97 ) )
V_22 -> V_24 |= V_101 ;
if ( V_40 -> V_88 -> V_96 -> V_102 != V_103 ) {
V_22 -> V_24 |= V_104 ;
if ( V_40 -> V_88 -> V_96 -> V_102 == V_105 )
V_22 -> V_24 |= V_106 ;
V_22 -> V_24 |= F_55 ( V_40 -> V_88 -> V_96 -> V_107 ) ;
V_22 -> V_24 |= F_56 ( V_40 -> V_88 -> V_96 -> V_108 -> V_109 -> V_110 ) ;
if ( F_54 ( V_40 -> V_88 -> V_97 ) &&
( V_40 -> V_88 -> V_96 -> V_102 == V_105 ) )
V_22 -> V_24 |= 2 << 16 ;
V_92 = 0 ;
V_94 = 0 ;
} else {
V_22 -> V_23 |= F_57 ( V_91 ) ;
if ( F_58 ( V_40 -> V_88 -> V_97 ) ||
F_53 ( V_40 -> V_88 -> V_97 ) )
V_22 -> V_111 |= F_59 ( V_62 -> V_112 ) ;
}
V_22 -> V_113 = 0 ;
V_22 -> V_113 |= F_60 ( F_38 ( V_40 -> V_28 ) ) ;
V_22 -> V_113 |= F_61 ( V_92 ) ;
V_22 -> V_111 |= F_62 ( V_94 ) ;
V_22 -> V_111 |= F_63 ( V_62 -> V_114 ) ;
if ( F_58 ( V_40 -> V_88 -> V_97 ) ) {
if ( V_40 -> V_115 == V_40 -> V_88 -> V_116 )
V_22 -> V_111 &= ~ F_63 ( 1 ) ;
else if ( F_39 ( V_40 , V_62 ) )
V_22 -> V_111 |= F_63 ( 1 ) ;
}
V_22 -> V_111 |= V_117 ;
V_22 -> V_111 |= F_64 ( V_118 ) ;
}
static void F_65 ( struct V_60 * V_62 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
T_1 V_119 ;
T_1 V_120 ;
if ( V_40 -> V_88 -> V_96 -> V_102 == V_103 ) {
V_120 = V_40 -> V_88 -> V_121 >> 3 ;
if ( V_40 -> V_88 -> V_121 > 4 )
V_119 = 0x01 ;
else if ( V_40 -> V_88 -> V_121 > 2 )
V_119 = 0x22 ;
else if ( V_40 -> V_88 -> V_121 > 1 )
V_119 = 0x55 ;
else
V_119 = 0xff ;
} else {
V_120 = V_40 -> V_88 -> V_121 ;
V_119 = 0x0f ;
V_22 -> V_122 = 0xff ;
}
V_120 = V_120 >> 1 ;
V_120 &= 0xf8 ;
V_22 -> V_113 |= V_120 ;
V_22 -> V_123 = V_119 ;
}
static void F_66 ( struct V_60 * V_62 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
F_43 ( V_62 , V_40 , V_22 ) ;
F_65 ( V_62 , V_40 , V_22 ) ;
}
static void F_67 ( struct V_2 * V_3 , struct V_88 * V_88 )
__releases( V_25 -> V_67 )
__acquires( V_25 -> V_67 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( ! V_88 -> V_124 ) {
if ( V_88 -> V_125 == - V_126 )
V_88 -> V_125 = 0 ;
}
if ( F_68 ( V_88 -> V_97 ) && F_69 ( V_88 -> V_97 ) != V_127 ) {
void * V_128 ;
for ( V_128 = V_88 -> V_129 ;
V_128 < V_88 -> V_129 + V_88 -> V_130 ;
V_128 += V_131 )
F_70 ( F_71 ( V_128 ) ) ;
}
F_72 ( V_3 , V_88 ) ;
F_73 ( & V_25 -> V_67 ) ;
F_74 ( V_3 , V_88 , V_88 -> V_125 ) ;
F_75 ( & V_25 -> V_67 ) ;
}
static struct V_39 * F_76 ( T_5 V_61 , struct V_88 * V_88 ,
T_6 V_99 )
{
struct V_39 * V_40 ;
V_40 = F_27 ( V_132 , V_61 ) ;
if ( ! V_40 )
return NULL ;
F_28 ( & V_40 -> V_65 ) ;
V_40 -> V_88 = V_88 ;
V_40 -> V_99 = V_99 ;
V_40 -> V_125 = V_133 ;
V_40 -> V_134 = 0 ;
return V_40 ;
}
static void F_77 ( struct V_39 * V_40 )
{
F_19 ( V_40 -> V_28 ) ;
F_31 ( V_132 , V_40 ) ;
}
static void F_78 ( struct V_2 * V_3 , T_1 V_20 , int V_21 ,
struct V_135 * V_136 ,
struct V_39 * V_40 , struct V_60 * V_62 ,
struct V_22 * V_22 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_137 ;
F_19 ( ( V_21 < 0 ) || ( V_21 > 31 ) ) ;
F_19 ( V_40 -> V_41 && ! V_40 -> V_28 ) ;
F_19 ( V_136 [ V_21 ] . V_40 ) ;
F_19 ( V_136 [ V_21 ] . V_62 ) ;
F_19 ( V_40 -> V_125 != V_138 ) ;
if ( V_20 == V_139 ) {
V_25 -> V_140 |= F_2 ( V_3 -> V_50 ,
V_141 ) ;
V_25 -> V_140 &= ~ ( 1 << V_21 ) ;
} else {
V_25 -> V_142 |= F_2 ( V_3 -> V_50 ,
V_143 ) ;
V_25 -> V_142 &= ~ ( 1 << V_21 ) ;
}
V_62 -> V_21 = V_21 ;
V_40 -> V_125 = V_144 ;
V_136 [ V_21 ] . V_145 = V_59 ;
V_136 [ V_21 ] . V_40 = V_40 ;
V_136 [ V_21 ] . V_62 = V_62 ;
F_16 ( V_3 -> V_50 , V_20 , V_21 , V_22 ) ;
if ( V_20 == V_139 ) {
V_137 = F_2 ( V_3 -> V_50 , V_78 ) ;
V_137 &= ~ ( 1 << V_62 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_78 , V_137 ) ;
} else {
V_137 = F_2 ( V_3 -> V_50 , V_80 ) ;
V_137 &= ~ ( 1 << V_62 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_80 , V_137 ) ;
}
}
static int F_79 ( struct V_39 * V_40 )
{
return ( F_53 ( V_40 -> V_88 -> V_97 ) &&
( V_40 -> V_134 < V_40 -> V_41 ) ) ;
}
static void F_80 ( struct V_2 * V_3 , struct V_60 * V_62 ,
struct V_146 * V_147 )
{
int V_148 ;
struct V_39 * V_40 , * V_149 ;
struct V_150 * V_150 ;
F_81 (qtd, qtd_next, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_125 < V_151 )
break;
V_148 = F_39 ( V_40 , V_62 ) ;
if ( ( ! V_148 ) && ( V_40 -> V_125 == V_152 ) )
V_149 -> V_125 = V_152 ;
if ( V_40 -> V_125 == V_151 ) {
if ( V_40 -> V_134 ) {
switch ( V_40 -> V_99 ) {
case V_153 :
F_9 ( V_3 -> V_50 , V_40 -> V_28 ,
V_40 -> V_115 ,
V_40 -> V_134 ) ;
case V_154 :
V_40 -> V_88 -> V_134 +=
V_40 -> V_134 ;
case V_155 :
break;
}
}
if ( F_79 ( V_40 ) ) {
if ( V_40 -> V_88 -> V_156 & V_157 )
V_40 -> V_88 -> V_125 = - V_158 ;
if ( ! V_148 )
V_149 -> V_125 = V_152 ;
}
}
if ( V_40 -> V_28 )
F_21 ( V_3 , V_40 ) ;
if ( V_148 ) {
if ( ( V_40 -> V_125 == V_152 ) &&
( V_40 -> V_88 -> V_125 == - V_126 ) )
V_40 -> V_88 -> V_125 = - V_159 ;
V_150 = F_27 ( V_160 ,
V_161 ) ;
if ( F_82 ( ! V_150 ) )
break;
V_150 -> V_88 = V_40 -> V_88 ;
F_83 ( & V_150 -> V_147 , V_147 ) ;
}
F_84 ( & V_40 -> V_65 ) ;
F_77 ( V_40 ) ;
}
}
static void F_85 ( struct V_2 * V_3 , struct V_60 * V_62 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_20 ;
struct V_135 * V_136 ;
int V_162 , V_163 ;
int V_164 ;
struct V_22 V_22 ;
struct V_39 * V_40 ;
if ( F_82 ( F_30 ( & V_62 -> V_65 ) ) ) {
F_19 ( 1 ) ;
return;
}
if ( V_62 -> V_165 )
return;
if ( F_54 ( F_41 ( V_62 -> V_65 . V_89 , struct V_39 ,
V_65 ) -> V_88 -> V_97 ) ) {
V_20 = V_166 ;
V_136 = V_25 -> V_167 ;
} else {
V_20 = V_139 ;
V_136 = V_25 -> V_168 ;
}
V_163 = - 1 ;
for ( V_162 = 0 ; V_162 < 32 ; V_162 ++ ) {
if ( ( V_163 == - 1 ) && ( V_136 [ V_162 ] . V_40 == NULL ) )
V_163 = V_162 ;
if ( V_136 [ V_162 ] . V_62 == V_62 )
break;
}
V_164 = 0 ;
F_86 (qtd, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_125 == V_133 ) {
F_19 ( V_40 -> V_28 ) ;
F_20 ( V_3 , V_40 ) ;
if ( ( V_40 -> V_41 ) && ( ! V_40 -> V_28 ) )
break;
if ( ( V_40 -> V_41 ) &&
( ( V_40 -> V_99 == V_155 ) ||
( V_40 -> V_99 == V_154 ) ) ) {
F_12 ( V_3 -> V_50 , V_40 -> V_28 ,
V_40 -> V_115 , V_40 -> V_41 ) ;
}
V_40 -> V_125 = V_138 ;
}
if ( V_40 -> V_125 == V_138 ) {
if ( ( V_162 > 31 ) && ( V_163 > - 1 ) ) {
if ( F_54 ( V_40 -> V_88 -> V_97 ) )
F_66 ( V_62 , V_40 , & V_22 ) ;
else
F_43 ( V_62 , V_40 , & V_22 ) ;
F_78 ( V_3 , V_20 , V_163 ,
V_136 , V_40 , V_62 , & V_22 ) ;
V_162 = V_163 ;
}
V_164 ++ ;
if ( V_164 >= V_169 )
break;
}
}
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_25 ;
struct V_60 * V_62 , * V_170 ;
struct V_146 * V_171 ;
F_88 ( V_147 ) ;
struct V_150 * V_150 , * V_172 ;
int V_26 ;
if ( ! V_3 ) {
F_19 ( 1 ) ;
return;
}
V_25 = F_1 ( V_3 ) ;
for ( V_26 = 0 ; V_26 < V_68 ; V_26 ++ ) {
V_171 = & V_25 -> V_64 [ V_26 ] ;
F_81 (qh, qh_next, ep_queue, qh_list) {
F_80 ( V_3 , V_62 , & V_147 ) ;
if ( F_30 ( & V_62 -> V_65 ) )
F_84 ( & V_62 -> V_64 ) ;
}
}
F_81 (urb_listitem, urb_listitem_next, &urb_list,
urb_list) {
F_67 ( V_3 , V_150 -> V_88 ) ;
F_31 ( V_160 , V_150 ) ;
}
for ( V_26 = 0 ; V_26 < V_68 ; V_26 ++ ) {
V_171 = & V_25 -> V_64 [ V_26 ] ;
F_81 (qh, qh_next, ep_queue, qh_list)
F_85 ( V_3 , V_62 ) ;
}
}
static int F_89 ( struct V_2 * V_3 , struct V_22 * V_22 ,
struct V_88 * V_88 )
{
T_7 V_123 ;
int V_26 ;
V_123 = V_22 -> V_123 ;
V_123 >>= 8 ;
if ( V_22 -> V_111 & V_173 ) {
V_88 -> V_125 = - V_174 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ ) {
switch ( V_123 & 0x7 ) {
case V_175 :
F_90 ( V_3 -> V_43 . V_44 , L_3
L_4 ,
V_45 , V_26 ) ;
V_88 -> V_125 = - V_176 ;
break;
case V_177 :
F_90 ( V_3 -> V_43 . V_44 , L_5
L_6 ,
V_45 , V_26 ) ;
V_88 -> V_125 = - V_174 ;
break;
case V_178 :
F_90 ( V_3 -> V_43 . V_44 , L_7
L_6 ,
V_45 , V_26 ) ;
V_88 -> V_125 = - V_179 ;
break;
}
V_123 >>= 3 ;
}
return V_180 ;
}
return V_181 ;
}
static int F_91 ( struct V_2 * V_3 , struct V_22 * V_22 ,
struct V_88 * V_88 )
{
F_19 ( ! V_22 ) ;
if ( V_22 -> V_111 & V_173 ) {
if ( V_22 -> V_111 & V_182 )
V_88 -> V_125 = - V_179 ;
else if ( F_92 ( V_22 -> V_111 ) )
V_88 -> V_125 = - V_159 ;
else if ( V_22 -> V_111 & V_183 )
V_88 -> V_125 = - V_174 ;
else
V_88 -> V_125 = - V_174 ;
return V_180 ;
}
if ( ( V_22 -> V_111 & V_183 ) && ( V_22 -> V_111 & V_117 ) ) {
F_90 ( V_3 -> V_43 . V_44 , L_8 ) ;
return V_184 ;
}
if ( ! F_93 ( V_22 -> V_111 ) && ( V_22 -> V_111 & V_117 ) ) {
return V_184 ;
}
return V_181 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_22 V_22 ;
struct V_60 * V_62 ;
int V_21 ;
int V_56 ;
struct V_135 * V_136 ;
T_1 V_20 ;
struct V_39 * V_40 ;
int V_185 ;
int V_137 ;
V_137 = F_2 ( V_3 -> V_50 , V_80 ) ;
V_25 -> V_142 &= ~ V_137 ;
V_137 = F_2 ( V_3 -> V_50 , V_78 ) ;
V_25 -> V_140 &= ~ V_137 ;
V_185 = V_25 -> V_142 || V_25 -> V_140 ;
while ( V_25 -> V_142 || V_25 -> V_140 ) {
if ( V_25 -> V_142 ) {
V_21 = F_95 ( V_25 -> V_142 ) ;
V_25 -> V_142 &= ~ ( 1 << V_21 ) ;
V_136 = V_25 -> V_167 ;
if ( ! V_136 [ V_21 ] . V_62 ) {
F_19 ( 1 ) ;
continue;
}
V_20 = V_166 ;
F_15 ( V_3 -> V_50 , V_166 , V_21 , & V_22 ) ;
V_56 = F_89 ( V_3 , & V_22 ,
V_136 [ V_21 ] . V_40 -> V_88 ) ;
} else {
V_21 = F_95 ( V_25 -> V_140 ) ;
V_25 -> V_140 &= ~ ( 1 << V_21 ) ;
V_136 = V_25 -> V_168 ;
if ( ! V_136 [ V_21 ] . V_62 ) {
F_19 ( 1 ) ;
continue;
}
V_20 = V_139 ;
F_15 ( V_3 -> V_50 , V_139 , V_21 , & V_22 ) ;
V_56 = F_91 ( V_3 , & V_22 ,
V_136 [ V_21 ] . V_40 -> V_88 ) ;
}
V_40 = V_136 [ V_21 ] . V_40 ;
V_136 [ V_21 ] . V_40 = NULL ;
V_62 = V_136 [ V_21 ] . V_62 ;
V_136 [ V_21 ] . V_62 = NULL ;
V_62 -> V_21 = - 1 ;
F_19 ( V_40 -> V_125 != V_144 ) ;
switch ( V_56 ) {
case V_181 :
if ( ( F_54 ( V_40 -> V_88 -> V_97 ) ) &&
( V_40 -> V_88 -> V_96 -> V_102 != V_103 ) )
V_40 -> V_134 =
F_96 ( V_22 . V_111 ) ;
else
V_40 -> V_134 =
F_97 ( V_22 . V_111 ) ;
V_40 -> V_125 = V_151 ;
if ( F_40 ( & V_40 -> V_65 , & V_62 -> V_65 ) ||
F_79 ( V_40 ) )
V_40 = NULL ;
else
V_40 = F_41 ( V_40 -> V_65 . V_89 ,
F_42 ( * V_40 ) , V_65 ) ;
V_62 -> V_114 = F_98 ( V_22 . V_111 ) ;
V_62 -> V_112 = F_99 ( V_22 . V_111 ) ;
break;
case V_184 :
V_40 -> V_125 = V_138 ;
V_22 . V_23 |= V_98 ;
V_22 . V_111 &= ~ F_62 ( 0xf ) ;
V_22 . V_111 |= F_62 ( F_100 ( V_22 . V_113 ) ) ;
V_22 . V_111 &= ~ F_64 ( 3 ) ;
V_22 . V_111 |= F_64 ( V_118 ) ;
V_62 -> V_114 = F_98 ( V_22 . V_111 ) ;
V_62 -> V_112 = F_99 ( V_22 . V_111 ) ;
break;
case V_180 :
V_40 -> V_125 = V_152 ;
if ( ( V_40 -> V_88 -> V_96 -> V_102 != V_103 ) &&
( V_40 -> V_88 -> V_125 != - V_159 ) &&
( V_40 -> V_88 -> V_125 != - V_158 ) ) {
V_62 -> V_165 = 1 ;
if ( F_101 ( V_40 -> V_88 ) )
V_62 -> V_165 = 0 ;
}
V_40 = NULL ;
V_62 -> V_114 = 0 ;
V_62 -> V_112 = 0 ;
break;
default:
F_19 ( 1 ) ;
continue;
}
if ( V_40 && ( V_40 -> V_125 == V_138 ) ) {
if ( V_136 == V_25 -> V_167 ) {
if ( V_56 == V_184 )
F_22 ( V_3 -> V_43 . V_44 ,
L_9
L_10 , V_45 ) ;
if ( V_56 != V_184 )
F_66 ( V_62 , V_40 , & V_22 ) ;
} else {
if ( V_56 != V_184 )
F_43 ( V_62 , V_40 , & V_22 ) ;
}
F_78 ( V_3 , V_20 , V_21 , V_136 , V_40 ,
V_62 , & V_22 ) ;
}
}
if ( V_185 )
F_87 ( V_3 ) ;
}
static T_8 F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_186 ;
T_8 V_187 = V_188 ;
F_75 ( & V_25 -> V_67 ) ;
if ( ! ( V_3 -> V_56 & V_189 ) )
goto V_190;
V_186 = F_2 ( V_3 -> V_50 , V_191 ) ;
if ( F_82 ( ! V_186 ) )
goto V_190;
F_4 ( V_3 -> V_50 , V_191 , V_186 ) ;
V_25 -> V_142 |= F_2 ( V_3 -> V_50 , V_143 ) ;
V_25 -> V_140 |= F_2 ( V_3 -> V_50 , V_141 ) ;
F_94 ( V_3 ) ;
V_187 = V_192 ;
V_190:
F_73 ( & V_25 -> V_67 ) ;
return V_187 ;
}
static void F_103 ( unsigned long V_193 )
{
struct V_2 * V_3 = (struct V_2 * ) V_193 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_21 ;
struct V_22 V_22 ;
unsigned long V_194 ;
F_104 ( & V_25 -> V_67 , V_194 ) ;
for ( V_21 = 0 ; V_21 < 32 ; V_21 ++ )
if ( V_25 -> V_168 [ V_21 ] . V_62 && F_105 ( V_59 ,
V_25 -> V_168 [ V_21 ] . V_145 +
F_106 ( V_195 ) ) ) {
F_15 ( V_3 -> V_50 , V_139 , V_21 , & V_22 ) ;
if ( ! F_107 ( V_22 . V_23 ) &&
! F_108 ( V_22 . V_111 ) )
V_25 -> V_140 |= 1 << V_21 ;
}
if ( V_25 -> V_140 )
F_94 ( V_3 ) ;
F_109 ( & V_25 -> V_67 , V_194 ) ;
V_196 . V_197 = V_59 + F_106 ( V_198 ) ;
F_110 ( & V_196 ) ;
}
static int F_111 ( struct V_2 * V_3 )
{
int V_199 ;
T_1 V_200 ;
T_1 V_53 ;
T_1 V_201 ;
V_3 -> V_202 = 1 ;
V_3 -> V_56 = V_189 ;
F_4 ( V_3 -> V_50 , V_203 , 0 ) ;
F_4 ( V_3 -> V_50 , V_204 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_205 , 0 ) ;
F_4 ( V_3 -> V_50 , V_206 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_207 , 0 ) ;
F_4 ( V_3 -> V_50 , V_208 , 0xffffffff ) ;
V_200 = F_2 ( V_3 -> V_50 , V_82 ) ;
F_4 ( V_3 -> V_50 , V_82 , V_200 | V_209 ) ;
V_53 = F_2 ( V_3 -> V_50 , V_54 ) ;
V_53 &= ~ ( V_210 | V_55 ) ;
V_53 |= V_211 ;
F_4 ( V_3 -> V_50 , V_54 , V_53 ) ;
V_199 = F_23 ( V_3 , V_54 , V_211 , V_211 , 250 * 1000 ) ;
if ( V_199 )
return V_199 ;
F_112 ( & V_212 ) ;
F_4 ( V_3 -> V_50 , V_213 , V_214 ) ;
V_199 = F_23 ( V_3 , V_213 , V_214 , V_214 , 250 * 1000 ) ;
F_113 ( & V_212 ) ;
if ( V_199 )
return V_199 ;
F_114 ( & V_196 , F_103 , ( unsigned long ) V_3 ) ;
V_196 . V_197 = V_59 + F_106 ( V_198 ) ;
F_110 ( & V_196 ) ;
V_201 = F_2 ( V_3 -> V_50 , V_76 ) ;
F_115 ( V_3 -> V_43 . V_44 , L_11 ,
V_201 & 0xffff , V_201 >> 16 ) ;
F_4 ( V_3 -> V_50 , V_215 , 0x80000000 ) ;
F_4 ( V_3 -> V_50 , V_216 , 0x80000000 ) ;
F_4 ( V_3 -> V_50 , V_217 , 0x00000001 ) ;
F_4 ( V_3 -> V_50 , V_78 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_80 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_81 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_77 ,
V_218 | V_219 ) ;
return 0 ;
}
static int F_116 ( struct V_39 * V_40 , void * V_220 , T_9 V_221 )
{
V_40 -> V_115 = V_220 ;
if ( V_221 > V_222 )
V_221 = V_222 ;
V_40 -> V_41 = V_221 ;
return V_40 -> V_41 ;
}
static void F_117 ( struct V_146 * V_65 )
{
struct V_39 * V_40 , * V_149 ;
F_81 (qtd, qtd_next, qtd_list, qtd_list) {
F_84 ( & V_40 -> V_65 ) ;
F_77 ( V_40 ) ;
}
}
static void F_118 ( struct V_2 * V_3 ,
struct V_88 * V_88 , struct V_146 * V_223 , T_5 V_61 )
{
struct V_39 * V_40 ;
void * V_224 ;
int V_221 , V_225 ;
T_6 V_99 ;
if ( ! V_88 -> V_129 && V_88 -> V_130 ) {
F_22 ( V_3 -> V_43 . V_44 ,
L_12 ,
( long unsigned ) V_88 -> V_226 ,
V_88 -> V_130 ) ;
F_19 ( 1 ) ;
}
if ( F_68 ( V_88 -> V_97 ) )
V_99 = V_153 ;
else
V_99 = V_154 ;
if ( F_58 ( V_88 -> V_97 ) ) {
V_40 = F_76 ( V_61 , V_88 , V_155 ) ;
if ( ! V_40 )
goto V_227;
F_116 ( V_40 , V_88 -> V_116 , sizeof( struct V_228 ) ) ;
F_83 ( & V_40 -> V_65 , V_223 ) ;
if ( V_88 -> V_130 == 0 )
V_99 = V_153 ;
}
V_225 = F_119 ( F_44 ( V_88 -> V_96 , V_88 -> V_97 ,
F_45 ( V_88 -> V_97 ) ) ) ;
V_224 = V_88 -> V_129 ;
V_221 = V_88 -> V_130 ;
for (; ; ) {
int V_229 ;
V_40 = F_76 ( V_61 , V_88 , V_99 ) ;
if ( ! V_40 )
goto V_227;
V_229 = F_116 ( V_40 , V_224 , V_221 ) ;
F_83 ( & V_40 -> V_65 , V_223 ) ;
V_221 -= V_229 ;
V_224 += V_229 ;
if ( V_221 <= 0 )
break;
}
if ( V_88 -> V_130 != 0 ) {
int V_230 = 0 ;
if ( F_58 ( V_88 -> V_97 ) ) {
V_230 = 1 ;
if ( V_99 == V_153 )
V_99 = V_154 ;
else
V_99 = V_153 ;
} else if ( F_53 ( V_88 -> V_97 )
&& ( V_88 -> V_156 & V_231 )
&& ! ( V_88 -> V_130 %
V_225 ) ) {
V_230 = 1 ;
}
if ( V_230 ) {
V_40 = F_76 ( V_61 , V_88 , V_99 ) ;
if ( ! V_40 )
goto V_227;
F_116 ( V_40 , NULL , 0 ) ;
F_83 ( & V_40 -> V_65 , V_223 ) ;
}
}
return;
V_227:
F_117 ( V_223 ) ;
}
static int F_120 ( struct V_2 * V_3 , struct V_88 * V_88 ,
T_5 V_232 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_146 * V_171 ;
struct V_60 * V_62 , * V_233 ;
unsigned long V_194 ;
F_88 ( V_234 ) ;
int V_199 ;
int V_235 ;
switch ( F_69 ( V_88 -> V_97 ) ) {
case V_127 :
V_171 = & V_25 -> V_64 [ V_236 ] ;
break;
case V_237 :
V_171 = & V_25 -> V_64 [ V_238 ] ;
break;
case V_239 :
if ( V_88 -> V_121 < 0 )
return - V_240 ;
V_171 = & V_25 -> V_64 [ V_241 ] ;
break;
case V_242 :
F_22 ( V_3 -> V_43 . V_44 , L_13
L_14 ,
V_45 ) ;
return - V_159 ;
default:
F_22 ( V_3 -> V_43 . V_44 , L_15 ,
V_45 ) ;
return - V_159 ;
}
if ( F_68 ( V_88 -> V_97 ) )
V_88 -> V_134 = 0 ;
F_118 ( V_3 , V_88 , & V_234 , V_232 ) ;
if ( F_30 ( & V_234 ) )
return - V_243 ;
V_199 = 0 ;
F_104 ( & V_25 -> V_67 , V_194 ) ;
if ( ! F_121 ( V_244 , & V_3 -> V_61 ) ) {
V_199 = - V_245 ;
F_117 ( & V_234 ) ;
goto V_246;
}
V_199 = F_122 ( V_3 , V_88 ) ;
if ( V_199 ) {
F_117 ( & V_234 ) ;
goto V_246;
}
V_62 = V_88 -> V_247 -> V_248 ;
if ( V_62 ) {
V_235 = 0 ;
F_86 (qhit, ep_queue, qh_list) {
if ( V_233 == V_62 ) {
V_235 = 1 ;
break;
}
}
if ( ! V_235 )
F_83 ( & V_62 -> V_64 , V_171 ) ;
} else {
V_62 = F_26 ( V_161 ) ;
if ( ! V_62 ) {
V_199 = - V_243 ;
F_72 ( V_3 , V_88 ) ;
F_117 ( & V_234 ) ;
goto V_246;
}
F_83 ( & V_62 -> V_64 , V_171 ) ;
V_88 -> V_247 -> V_248 = V_62 ;
}
F_123 ( & V_234 , & V_62 -> V_65 ) ;
F_87 ( V_3 ) ;
V_246:
F_109 ( & V_25 -> V_67 , V_194 ) ;
return V_199 ;
}
static void F_124 ( struct V_2 * V_3 , struct V_88 * V_88 ,
struct V_60 * V_62 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_137 ;
F_19 ( V_62 -> V_21 == - 1 ) ;
if ( F_58 ( V_88 -> V_97 ) || F_53 ( V_88 -> V_97 ) ) {
V_137 = F_2 ( V_3 -> V_50 , V_78 ) ;
V_137 |= ( 1 << V_62 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_78 , V_137 ) ;
V_25 -> V_168 [ V_62 -> V_21 ] . V_62 = NULL ;
V_25 -> V_168 [ V_62 -> V_21 ] . V_40 = NULL ;
} else {
V_137 = F_2 ( V_3 -> V_50 , V_80 ) ;
V_137 |= ( 1 << V_62 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_80 , V_137 ) ;
V_25 -> V_167 [ V_62 -> V_21 ] . V_62 = NULL ;
V_25 -> V_167 [ V_62 -> V_21 ] . V_40 = NULL ;
}
V_62 -> V_21 = - 1 ;
}
static void F_125 ( struct V_2 * V_3 , struct V_60 * V_62 ,
struct V_39 * V_40 )
{
struct V_88 * V_88 ;
int V_249 ;
V_88 = V_40 -> V_88 ;
V_249 = 0 ;
F_126 (qtd, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_88 != V_88 )
break;
if ( V_40 -> V_125 >= V_144 )
V_249 = 1 ;
if ( F_39 ( V_40 , V_62 ) &&
( V_40 -> V_125 >= V_151 ) )
V_249 = 0 ;
if ( V_40 -> V_125 == V_144 )
F_124 ( V_3 , V_88 , V_62 ) ;
V_40 -> V_125 = V_152 ;
}
if ( ( V_88 -> V_96 -> V_102 != V_103 ) && V_249 ) {
V_62 -> V_165 = 1 ;
if ( F_101 ( V_88 ) )
V_62 -> V_165 = 0 ;
}
}
static int F_127 ( struct V_2 * V_3 , struct V_88 * V_88 ,
int V_125 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned long V_194 ;
struct V_60 * V_62 ;
struct V_39 * V_40 ;
int V_199 = 0 ;
F_104 ( & V_25 -> V_67 , V_194 ) ;
V_199 = F_128 ( V_3 , V_88 , V_125 ) ;
if ( V_199 )
goto V_246;
V_62 = V_88 -> V_247 -> V_248 ;
if ( ! V_62 ) {
V_199 = - V_240 ;
goto V_246;
}
F_86 (qtd, &qh->qtd_list, qtd_list)
if ( V_40 -> V_88 == V_88 ) {
F_125 ( V_3 , V_62 , V_40 ) ;
F_129 ( & V_40 -> V_65 , & V_62 -> V_65 ) ;
break;
}
V_88 -> V_125 = V_125 ;
F_87 ( V_3 ) ;
V_246:
F_109 ( & V_25 -> V_67 , V_194 ) ;
return V_199 ;
}
static void F_130 ( struct V_2 * V_3 ,
struct V_250 * V_247 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned long V_194 ;
struct V_60 * V_62 , * V_251 ;
int V_26 ;
F_104 ( & V_25 -> V_67 , V_194 ) ;
V_62 = V_247 -> V_248 ;
if ( ! V_62 )
goto V_246;
F_19 ( ! F_30 ( & V_62 -> V_65 ) ) ;
for ( V_26 = 0 ; V_26 < V_68 ; V_26 ++ )
F_86 (qh_iter, &priv->qh_list[i], qh_list)
if ( V_251 == V_62 ) {
F_84 ( & V_251 -> V_64 ) ;
V_26 = V_68 ;
break;
}
F_29 ( V_62 ) ;
V_247 -> V_248 = NULL ;
F_87 ( V_3 ) ;
V_246:
F_109 ( & V_25 -> V_67 , V_194 ) ;
}
static int F_131 ( struct V_2 * V_3 , char * V_224 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_200 , V_125 = 0 ;
T_1 V_46 ;
int V_199 = 1 ;
unsigned long V_61 ;
if ( ! F_132 ( V_3 -> V_56 ) )
return 0 ;
V_224 [ 0 ] = 0 ;
V_46 = V_252 ;
F_104 ( & V_25 -> V_67 , V_61 ) ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
if ( V_200 & V_254 ) {
if ( V_200 & V_252 ) {
V_200 &= ~ V_252 ;
F_4 ( V_3 -> V_50 , V_253 , V_200 ) ;
goto V_47;
}
}
if ( ( V_200 & V_46 ) != 0
|| ( ( V_200 & V_255 ) != 0
&& F_133 ( V_59 ,
V_25 -> V_256 ) ) ) {
V_224 [ 0 ] |= 1 << ( 0 + 1 ) ;
V_125 = V_257 ;
}
V_47:
F_109 ( & V_25 -> V_67 , V_61 ) ;
return V_125 ? V_199 : 0 ;
}
static void F_134 ( struct V_1 * V_25 ,
struct V_258 * V_259 )
{
int V_260 = F_135 ( V_25 -> V_86 ) ;
T_10 V_200 ;
V_259 -> V_261 = V_262 ;
V_259 -> V_263 = 10 ;
V_259 -> V_264 = 0 ;
V_259 -> V_265 = V_260 ;
V_200 = 1 + ( V_260 / 8 ) ;
V_259 -> V_266 = 7 + 2 * V_200 ;
memset ( & V_259 -> V_267 . V_268 . V_269 [ 0 ] , 0 , V_200 ) ;
memset ( & V_259 -> V_267 . V_268 . V_269 [ V_200 ] , 0xff , V_200 ) ;
V_200 = V_270 ;
if ( F_136 ( V_25 -> V_86 ) )
V_200 |= V_271 ;
else
V_200 |= V_272 ;
V_259 -> V_273 = F_137 ( V_200 ) ;
}
static int F_138 ( struct V_2 * V_3 , int V_274 ,
int V_275 )
{
if ( ! ( V_275 & V_276 ) )
return V_275 ;
if ( ! ( V_275 & V_277 ) ) {
F_115 ( V_3 -> V_43 . V_44 ,
L_16 ,
V_274 + 1 ) ;
V_275 |= V_254 ;
V_275 &= ~ V_278 ;
F_4 ( V_3 -> V_50 , V_253 , V_275 ) ;
} else
F_115 ( V_3 -> V_43 . V_44 , L_17 ,
V_274 + 1 ) ;
return V_275 ;
}
static int F_139 ( struct V_2 * V_3 , T_10 V_279 ,
T_10 V_280 , T_10 V_281 , char * V_224 , T_10 V_282 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_260 = F_135 ( V_25 -> V_86 ) ;
T_1 V_200 , V_125 ;
unsigned long V_61 ;
int V_199 = 0 ;
unsigned V_283 ;
F_104 ( & V_25 -> V_67 , V_61 ) ;
switch ( V_279 ) {
case V_284 :
switch ( V_280 ) {
case V_285 :
case V_286 :
break;
default:
goto error;
}
break;
case V_287 :
if ( ! V_281 || V_281 > V_260 )
goto error;
V_281 -- ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
switch ( V_280 ) {
case V_288 :
F_4 ( V_3 -> V_50 , V_253 , V_200 & ~ V_277 ) ;
break;
case V_289 :
break;
case V_290 :
if ( V_200 & V_291 )
goto error;
if ( V_200 & V_292 ) {
if ( ( V_200 & V_277 ) == 0 )
goto error;
V_200 &= ~ ( V_278 ) ;
F_4 ( V_3 -> V_50 , V_253 ,
V_200 | V_255 ) ;
V_25 -> V_256 = V_59 +
F_106 ( V_293 ) ;
}
break;
case V_294 :
break;
case V_295 :
if ( F_136 ( V_25 -> V_86 ) )
F_4 ( V_3 -> V_50 , V_253 ,
V_200 & ~ V_296 ) ;
break;
case V_297 :
F_4 ( V_3 -> V_50 , V_253 , V_200 | V_252 ) ;
break;
case V_298 :
break;
case V_299 :
break;
default:
goto error;
}
F_2 ( V_3 -> V_50 , V_54 ) ;
break;
case V_300 :
F_134 ( V_25 , (struct V_258 * )
V_224 ) ;
break;
case V_301 :
memset ( V_224 , 0 , 4 ) ;
break;
case V_302 :
if ( ! V_281 || V_281 > V_260 )
goto error;
V_281 -- ;
V_125 = 0 ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
if ( V_200 & V_252 )
V_125 |= V_303 << 16 ;
if ( V_200 & V_255 ) {
F_22 ( V_3 -> V_43 . V_44 , L_18 ) ;
if ( ! V_25 -> V_256 ) {
V_25 -> V_256 = V_59
+ F_106 ( 20 ) ;
F_140 ( & V_3 -> V_304 , V_25 -> V_256 ) ;
}
else if ( F_133 ( V_59 ,
V_25 -> V_256 ) ) {
V_125 |= V_305 << 16 ;
V_25 -> V_256 = 0 ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
F_4 ( V_3 -> V_50 , V_253 ,
V_200 & ~ ( V_278 | V_255 ) ) ;
V_199 = F_23 ( V_3 , V_253 ,
V_255 , 0 , 2000 ) ;
if ( V_199 != 0 ) {
F_22 ( V_3 -> V_43 . V_44 ,
L_19 ,
V_281 + 1 , V_199 ) ;
goto error;
}
V_200 &= ~ ( V_292 | V_255 | ( 3 << 10 ) ) ;
}
}
if ( ( V_200 & V_291 )
&& F_133 ( V_59 ,
V_25 -> V_256 ) ) {
V_125 |= V_306 << 16 ;
V_25 -> V_256 = 0 ;
F_4 ( V_3 -> V_50 , V_253 , V_200 & ~ V_291 ) ;
V_199 = F_23 ( V_3 , V_253 ,
V_291 , 0 , 750 ) ;
if ( V_199 != 0 ) {
F_22 ( V_3 -> V_43 . V_44 , L_20 ,
V_281 + 1 , V_199 ) ;
goto error;
}
V_200 = F_138 ( V_3 , V_281 ,
F_2 ( V_3 -> V_50 , V_253 ) ) ;
}
if ( V_200 & V_254 )
F_22 ( V_3 -> V_43 . V_44 , L_21 ) ;
if ( V_200 & V_276 ) {
V_125 |= V_307 ;
V_125 |= V_308 ;
}
if ( V_200 & V_277 )
V_125 |= V_309 ;
if ( V_200 & ( V_292 | V_255 ) )
V_125 |= V_310 ;
if ( V_200 & V_291 )
V_125 |= V_311 ;
if ( V_200 & V_296 )
V_125 |= V_312 ;
F_141 ( F_14 ( V_125 ) , ( V_313 * ) V_224 ) ;
break;
case V_314 :
switch ( V_280 ) {
case V_285 :
case V_286 :
break;
default:
goto error;
}
break;
case V_315 :
V_283 = V_281 >> 8 ;
V_281 &= 0xff ;
if ( ! V_281 || V_281 > V_260 )
goto error;
V_281 -- ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
if ( V_200 & V_254 )
break;
switch ( V_280 ) {
case V_288 :
F_4 ( V_3 -> V_50 , V_253 , V_200 | V_277 ) ;
break;
case V_290 :
if ( ( V_200 & V_277 ) == 0
|| ( V_200 & V_291 ) != 0 )
goto error;
F_4 ( V_3 -> V_50 , V_253 , V_200 | V_292 ) ;
break;
case V_295 :
if ( F_136 ( V_25 -> V_86 ) )
F_4 ( V_3 -> V_50 , V_253 ,
V_200 | V_296 ) ;
break;
case V_316 :
if ( V_200 & V_255 )
goto error;
if ( ( V_200 & ( V_277 | V_276 ) ) == V_276
&& F_142 ( V_200 ) ) {
V_200 |= V_254 ;
} else {
V_200 |= V_291 ;
V_200 &= ~ V_277 ;
V_25 -> V_256 = V_59 +
F_106 ( 50 ) ;
}
F_4 ( V_3 -> V_50 , V_253 , V_200 ) ;
break;
default:
goto error;
}
F_2 ( V_3 -> V_50 , V_54 ) ;
break;
default:
error:
V_199 = - V_159 ;
}
F_109 ( & V_25 -> V_67 , V_61 ) ;
return V_199 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_317 ;
V_317 = F_2 ( V_3 -> V_50 , V_318 ) ;
return ( V_317 >> 3 ) % V_25 -> V_69 ;
}
static void F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_200 ;
F_145 ( & V_196 ) ;
F_139 ( V_3 , V_287 , V_295 , 1 ,
NULL , 0 ) ;
F_37 ( 20 ) ;
F_146 ( & V_25 -> V_67 ) ;
F_25 ( V_3 ) ;
V_200 = F_2 ( V_3 -> V_50 , V_82 ) ;
F_4 ( V_3 -> V_50 , V_82 , V_200 &= ~ V_209 ) ;
F_147 ( & V_25 -> V_67 ) ;
F_4 ( V_3 -> V_50 , V_213 , 0 ) ;
}
static void F_148 ( struct V_2 * V_3 )
{
T_1 V_53 , V_200 ;
F_144 ( V_3 ) ;
V_200 = F_2 ( V_3 -> V_50 , V_82 ) ;
F_4 ( V_3 -> V_50 , V_82 , V_200 &= ~ V_209 ) ;
V_53 = F_2 ( V_3 -> V_50 , V_54 ) ;
V_53 &= ~ V_211 ;
F_4 ( V_3 -> V_50 , V_54 , V_53 ) ;
}
static void F_149 ( struct V_2 * V_3 ,
struct V_250 * V_247 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_60 * V_62 = V_247 -> V_248 ;
unsigned long V_194 ;
if ( ! V_62 )
return;
F_104 ( & V_25 -> V_67 , V_194 ) ;
V_62 -> V_165 = 0 ;
F_87 ( V_3 ) ;
F_109 ( & V_25 -> V_67 , V_194 ) ;
}
int T_11 F_150 ( void )
{
V_160 = F_151 ( L_22 ,
sizeof( struct V_150 ) , 0 , V_319 |
V_320 , NULL ) ;
if ( ! V_160 )
return - V_243 ;
V_132 = F_151 ( L_23 ,
sizeof( struct V_39 ) , 0 , V_319 |
V_320 , NULL ) ;
if ( ! V_132 )
return - V_243 ;
V_63 = F_151 ( L_24 , sizeof( struct V_60 ) ,
0 , V_319 | V_320 , NULL ) ;
if ( ! V_63 ) {
F_152 ( V_132 ) ;
return - V_243 ;
}
return 0 ;
}
void F_153 ( void )
{
F_152 ( V_132 ) ;
F_152 ( V_63 ) ;
F_152 ( V_160 ) ;
}
int F_154 ( struct V_1 * V_25 , void T_2 * V_50 ,
struct V_321 * V_322 , int V_323 , unsigned long V_324 ,
struct V_325 * V_96 )
{
struct V_2 * V_3 ;
int V_326 ;
V_3 = F_155 ( & V_327 , V_96 , F_156 ( V_96 ) ) ;
if ( ! V_3 )
return - V_243 ;
* (struct V_1 * * ) V_3 -> V_4 = V_25 ;
V_25 -> V_3 = V_3 ;
F_18 ( V_25 ) ;
V_3 -> V_323 = V_323 ;
V_3 -> V_50 = V_50 ;
V_3 -> V_328 = V_322 -> V_31 ;
V_3 -> V_329 = F_157 ( V_322 ) ;
V_3 -> V_330 = 1 ;
V_326 = F_158 ( V_3 , V_323 , V_324 ) ;
if ( V_326 )
goto error;
F_159 ( V_3 -> V_43 . V_44 ) ;
return 0 ;
error:
F_160 ( V_3 ) ;
return V_326 ;
}
void F_161 ( struct V_1 * V_25 )
{
if ( ! V_25 -> V_3 )
return;
F_162 ( V_25 -> V_3 ) ;
F_160 ( V_25 -> V_3 ) ;
}
