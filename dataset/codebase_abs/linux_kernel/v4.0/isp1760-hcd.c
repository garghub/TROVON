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
int V_53 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_54 = F_2 ( V_3 -> V_50 , V_55 ) ;
V_54 |= V_56 ;
F_4 ( V_3 -> V_50 , V_55 , V_54 ) ;
V_3 -> V_57 = V_58 ;
V_25 -> V_59 = V_60 ;
V_53 = F_23 ( V_3 , V_55 ,
V_56 , 0 , 250 * 1000 ) ;
return V_53 ;
}
static struct V_61 * F_26 ( T_5 V_62 )
{
struct V_61 * V_63 ;
V_63 = F_27 ( V_64 , V_62 ) ;
if ( ! V_63 )
return NULL ;
F_28 ( & V_63 -> V_65 ) ;
F_28 ( & V_63 -> V_66 ) ;
V_63 -> V_21 = - 1 ;
return V_63 ;
}
static void F_29 ( struct V_61 * V_63 )
{
F_19 ( ! F_30 ( & V_63 -> V_66 ) ) ;
F_19 ( V_63 -> V_21 > - 1 ) ;
F_31 ( V_64 , V_63 ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_67 ;
int V_26 ;
F_33 ( & V_25 -> V_68 ) ;
for ( V_26 = 0 ; V_26 < V_69 ; V_26 ++ )
F_28 ( & V_25 -> V_65 [ V_26 ] ) ;
V_25 -> V_70 = V_71 ;
V_67 = F_2 ( V_3 -> V_50 , V_72 ) ;
if ( F_34 ( V_67 ) )
V_25 -> V_73 = 8 ;
else
V_25 -> V_73 = 2 + F_35 ( V_67 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_49 ;
T_1 V_74 , V_75 ;
F_4 ( V_3 -> V_50 , V_76 , 0xdeadbabe ) ;
V_74 = F_2 ( V_3 -> V_50 , V_77 ) ;
V_74 = F_2 ( V_3 -> V_50 , V_76 ) ;
if ( V_74 != 0xdeadbabe ) {
F_22 ( V_3 -> V_43 . V_44 , L_2 ) ;
return - V_51 ;
}
F_4 ( V_3 -> V_50 , V_78 , 0 ) ;
F_4 ( V_3 -> V_50 , V_79 , V_80 ) ;
F_4 ( V_3 -> V_50 , V_81 , V_80 ) ;
F_4 ( V_3 -> V_50 , V_82 , V_80 ) ;
V_49 = F_25 ( V_3 ) ;
if ( V_49 )
return V_49 ;
V_75 = F_2 ( V_3 -> V_50 , V_83 ) & ~ V_84 ;
F_4 ( V_3 -> V_50 , V_83 , V_75 | V_84 ) ;
F_37 ( 10 ) ;
F_4 ( V_3 -> V_50 , V_83 , V_75 ) ;
F_4 ( V_3 -> V_50 , V_85 , V_86 ) ;
V_25 -> V_87 = F_2 ( V_3 -> V_50 , V_88 ) ;
return F_32 ( V_3 ) ;
}
static T_1 F_38 ( T_1 V_5 )
{
return ( ( V_5 - 0x400 ) >> 3 ) ;
}
static int F_39 ( struct V_39 * V_40 , struct V_61 * V_63 )
{
struct V_89 * V_89 ;
if ( F_40 ( & V_40 -> V_66 , & V_63 -> V_66 ) )
return 1 ;
V_89 = V_40 -> V_89 ;
V_40 = F_41 ( V_40 -> V_66 . V_90 , F_42 ( * V_40 ) , V_66 ) ;
return ( V_40 -> V_89 != V_89 ) ;
}
static void F_43 ( struct V_61 * V_63 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
T_1 V_91 ;
T_1 V_92 ;
T_1 V_93 = V_94 ;
T_1 V_95 = V_96 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_91 = F_44 ( V_40 -> V_89 -> V_97 , V_40 -> V_89 -> V_98 ,
F_45 ( V_40 -> V_89 -> V_98 ) ) ;
V_92 = 1 + ( ( V_91 >> 11 ) & 0x3 ) ;
V_91 &= 0x7ff ;
V_22 -> V_23 = V_99 ;
V_22 -> V_23 |= F_46 ( V_40 -> V_41 ) ;
V_22 -> V_23 |= F_47 ( V_91 ) ;
V_22 -> V_23 |= F_48 ( F_49 ( V_40 -> V_89 -> V_98 ) ) ;
V_22 -> V_24 = F_49 ( V_40 -> V_89 -> V_98 ) >> 1 ;
V_22 -> V_24 |= F_50 ( F_51 ( V_40 -> V_89 -> V_98 ) ) ;
V_22 -> V_24 |= F_52 ( V_40 -> V_100 ) ;
if ( F_53 ( V_40 -> V_89 -> V_98 ) )
V_22 -> V_24 |= V_101 ;
else if ( F_54 ( V_40 -> V_89 -> V_98 ) )
V_22 -> V_24 |= V_102 ;
if ( V_40 -> V_89 -> V_97 -> V_103 != V_104 ) {
V_22 -> V_24 |= V_105 ;
if ( V_40 -> V_89 -> V_97 -> V_103 == V_106 )
V_22 -> V_24 |= V_107 ;
V_22 -> V_24 |= F_55 ( V_40 -> V_89 -> V_97 -> V_108 ) ;
V_22 -> V_24 |= F_56 ( V_40 -> V_89 -> V_97 -> V_109 -> V_110 -> V_111 ) ;
if ( F_54 ( V_40 -> V_89 -> V_98 ) &&
( V_40 -> V_89 -> V_97 -> V_103 == V_106 ) )
V_22 -> V_24 |= 2 << 16 ;
V_93 = 0 ;
V_95 = 0 ;
} else {
V_22 -> V_23 |= F_57 ( V_92 ) ;
if ( F_58 ( V_40 -> V_89 -> V_98 ) ||
F_53 ( V_40 -> V_89 -> V_98 ) )
V_22 -> V_112 |= F_59 ( V_63 -> V_113 ) ;
}
V_22 -> V_114 = 0 ;
V_22 -> V_114 |= F_60 ( F_38 ( V_40 -> V_28 ) ) ;
V_22 -> V_114 |= F_61 ( V_93 ) ;
V_22 -> V_112 |= F_62 ( V_95 ) ;
V_22 -> V_112 |= F_63 ( V_63 -> V_115 ) ;
if ( F_58 ( V_40 -> V_89 -> V_98 ) ) {
if ( V_40 -> V_116 == V_40 -> V_89 -> V_117 )
V_22 -> V_112 &= ~ F_63 ( 1 ) ;
else if ( F_39 ( V_40 , V_63 ) )
V_22 -> V_112 |= F_63 ( 1 ) ;
}
V_22 -> V_112 |= V_118 ;
V_22 -> V_112 |= F_64 ( V_119 ) ;
}
static void F_65 ( struct V_61 * V_63 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
T_1 V_120 ;
T_1 V_121 ;
if ( V_40 -> V_89 -> V_97 -> V_103 == V_104 ) {
V_121 = V_40 -> V_89 -> V_122 >> 3 ;
if ( V_40 -> V_89 -> V_122 > 4 )
V_120 = 0x01 ;
else if ( V_40 -> V_89 -> V_122 > 2 )
V_120 = 0x22 ;
else if ( V_40 -> V_89 -> V_122 > 1 )
V_120 = 0x55 ;
else
V_120 = 0xff ;
} else {
V_121 = V_40 -> V_89 -> V_122 ;
V_120 = 0x0f ;
V_22 -> V_123 = 0xff ;
}
V_121 = V_121 >> 1 ;
V_121 &= 0xf8 ;
V_22 -> V_114 |= V_121 ;
V_22 -> V_124 = V_120 ;
}
static void F_66 ( struct V_61 * V_63 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
F_43 ( V_63 , V_40 , V_22 ) ;
F_65 ( V_63 , V_40 , V_22 ) ;
}
static void F_67 ( struct V_2 * V_3 , struct V_89 * V_89 )
__releases( V_25 -> V_68 )
__acquires( V_25 -> V_68 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( ! V_89 -> V_125 ) {
if ( V_89 -> V_126 == - V_127 )
V_89 -> V_126 = 0 ;
}
if ( F_68 ( V_89 -> V_98 ) && F_69 ( V_89 -> V_98 ) != V_128 ) {
void * V_129 ;
for ( V_129 = V_89 -> V_130 ;
V_129 < V_89 -> V_130 + V_89 -> V_131 ;
V_129 += V_132 )
F_70 ( F_71 ( V_129 ) ) ;
}
F_72 ( V_3 , V_89 ) ;
F_73 ( & V_25 -> V_68 ) ;
F_74 ( V_3 , V_89 , V_89 -> V_126 ) ;
F_75 ( & V_25 -> V_68 ) ;
}
static struct V_39 * F_76 ( T_5 V_62 , struct V_89 * V_89 ,
T_6 V_100 )
{
struct V_39 * V_40 ;
V_40 = F_27 ( V_133 , V_62 ) ;
if ( ! V_40 )
return NULL ;
F_28 ( & V_40 -> V_66 ) ;
V_40 -> V_89 = V_89 ;
V_40 -> V_100 = V_100 ;
V_40 -> V_126 = V_134 ;
V_40 -> V_135 = 0 ;
return V_40 ;
}
static void F_77 ( struct V_39 * V_40 )
{
F_19 ( V_40 -> V_28 ) ;
F_31 ( V_133 , V_40 ) ;
}
static void F_78 ( struct V_2 * V_3 , T_1 V_20 , int V_21 ,
struct V_136 * V_137 ,
struct V_39 * V_40 , struct V_61 * V_63 ,
struct V_22 * V_22 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_138 ;
F_19 ( ( V_21 < 0 ) || ( V_21 > 31 ) ) ;
F_19 ( V_40 -> V_41 && ! V_40 -> V_28 ) ;
F_19 ( V_137 [ V_21 ] . V_40 ) ;
F_19 ( V_137 [ V_21 ] . V_63 ) ;
F_19 ( V_40 -> V_126 != V_139 ) ;
if ( V_20 == V_140 ) {
V_25 -> V_141 |= F_2 ( V_3 -> V_50 ,
V_142 ) ;
V_25 -> V_141 &= ~ ( 1 << V_21 ) ;
} else {
V_25 -> V_143 |= F_2 ( V_3 -> V_50 ,
V_144 ) ;
V_25 -> V_143 &= ~ ( 1 << V_21 ) ;
}
V_63 -> V_21 = V_21 ;
V_40 -> V_126 = V_145 ;
V_137 [ V_21 ] . V_146 = V_60 ;
V_137 [ V_21 ] . V_40 = V_40 ;
V_137 [ V_21 ] . V_63 = V_63 ;
F_16 ( V_3 -> V_50 , V_20 , V_21 , V_22 ) ;
if ( V_20 == V_140 ) {
V_138 = F_2 ( V_3 -> V_50 , V_79 ) ;
V_138 &= ~ ( 1 << V_63 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_79 , V_138 ) ;
} else {
V_138 = F_2 ( V_3 -> V_50 , V_81 ) ;
V_138 &= ~ ( 1 << V_63 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_81 , V_138 ) ;
}
}
static int F_79 ( struct V_39 * V_40 )
{
return ( F_53 ( V_40 -> V_89 -> V_98 ) &&
( V_40 -> V_135 < V_40 -> V_41 ) ) ;
}
static void F_80 ( struct V_2 * V_3 , struct V_61 * V_63 ,
struct V_147 * V_148 )
{
int V_149 ;
struct V_39 * V_40 , * V_150 ;
struct V_151 * V_151 ;
F_81 (qtd, qtd_next, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_126 < V_152 )
break;
V_149 = F_39 ( V_40 , V_63 ) ;
if ( ( ! V_149 ) && ( V_40 -> V_126 == V_153 ) )
V_150 -> V_126 = V_153 ;
if ( V_40 -> V_126 == V_152 ) {
if ( V_40 -> V_135 ) {
switch ( V_40 -> V_100 ) {
case V_154 :
F_9 ( V_3 -> V_50 , V_40 -> V_28 ,
V_40 -> V_116 ,
V_40 -> V_135 ) ;
case V_155 :
V_40 -> V_89 -> V_135 +=
V_40 -> V_135 ;
case V_156 :
break;
}
}
if ( F_79 ( V_40 ) ) {
if ( V_40 -> V_89 -> V_157 & V_158 )
V_40 -> V_89 -> V_126 = - V_159 ;
if ( ! V_149 )
V_150 -> V_126 = V_153 ;
}
}
if ( V_40 -> V_28 )
F_21 ( V_3 , V_40 ) ;
if ( V_149 ) {
if ( ( V_40 -> V_126 == V_153 ) &&
( V_40 -> V_89 -> V_126 == - V_127 ) )
V_40 -> V_89 -> V_126 = - V_160 ;
V_151 = F_27 ( V_161 ,
V_162 ) ;
if ( F_82 ( ! V_151 ) )
break;
V_151 -> V_89 = V_40 -> V_89 ;
F_83 ( & V_151 -> V_148 , V_148 ) ;
}
F_84 ( & V_40 -> V_66 ) ;
F_77 ( V_40 ) ;
}
}
static void F_85 ( struct V_2 * V_3 , struct V_61 * V_63 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_20 ;
struct V_136 * V_137 ;
int V_163 , V_164 ;
int V_165 ;
struct V_22 V_22 ;
struct V_39 * V_40 ;
if ( F_82 ( F_30 ( & V_63 -> V_66 ) ) ) {
F_19 ( 1 ) ;
return;
}
if ( V_63 -> V_166 )
return;
if ( F_54 ( F_41 ( V_63 -> V_66 . V_90 , struct V_39 ,
V_66 ) -> V_89 -> V_98 ) ) {
V_20 = V_167 ;
V_137 = V_25 -> V_168 ;
} else {
V_20 = V_140 ;
V_137 = V_25 -> V_169 ;
}
V_164 = - 1 ;
for ( V_163 = 0 ; V_163 < 32 ; V_163 ++ ) {
if ( ( V_164 == - 1 ) && ( V_137 [ V_163 ] . V_40 == NULL ) )
V_164 = V_163 ;
if ( V_137 [ V_163 ] . V_63 == V_63 )
break;
}
V_165 = 0 ;
F_86 (qtd, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_126 == V_134 ) {
F_19 ( V_40 -> V_28 ) ;
F_20 ( V_3 , V_40 ) ;
if ( ( V_40 -> V_41 ) && ( ! V_40 -> V_28 ) )
break;
if ( ( V_40 -> V_41 ) &&
( ( V_40 -> V_100 == V_156 ) ||
( V_40 -> V_100 == V_155 ) ) ) {
F_12 ( V_3 -> V_50 , V_40 -> V_28 ,
V_40 -> V_116 , V_40 -> V_41 ) ;
}
V_40 -> V_126 = V_139 ;
}
if ( V_40 -> V_126 == V_139 ) {
if ( ( V_163 > 31 ) && ( V_164 > - 1 ) ) {
if ( F_54 ( V_40 -> V_89 -> V_98 ) )
F_66 ( V_63 , V_40 , & V_22 ) ;
else
F_43 ( V_63 , V_40 , & V_22 ) ;
F_78 ( V_3 , V_20 , V_164 ,
V_137 , V_40 , V_63 , & V_22 ) ;
V_163 = V_164 ;
}
V_165 ++ ;
if ( V_165 >= V_170 )
break;
}
}
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_25 ;
struct V_61 * V_63 , * V_171 ;
struct V_147 * V_172 ;
F_88 ( V_148 ) ;
struct V_151 * V_151 , * V_173 ;
int V_26 ;
if ( ! V_3 ) {
F_19 ( 1 ) ;
return;
}
V_25 = F_1 ( V_3 ) ;
for ( V_26 = 0 ; V_26 < V_69 ; V_26 ++ ) {
V_172 = & V_25 -> V_65 [ V_26 ] ;
F_81 (qh, qh_next, ep_queue, qh_list) {
F_80 ( V_3 , V_63 , & V_148 ) ;
if ( F_30 ( & V_63 -> V_66 ) )
F_84 ( & V_63 -> V_65 ) ;
}
}
F_81 (urb_listitem, urb_listitem_next, &urb_list,
urb_list) {
F_67 ( V_3 , V_151 -> V_89 ) ;
F_31 ( V_161 , V_151 ) ;
}
for ( V_26 = 0 ; V_26 < V_69 ; V_26 ++ ) {
V_172 = & V_25 -> V_65 [ V_26 ] ;
F_81 (qh, qh_next, ep_queue, qh_list)
F_85 ( V_3 , V_63 ) ;
}
}
static int F_89 ( struct V_2 * V_3 , struct V_22 * V_22 ,
struct V_89 * V_89 )
{
T_7 V_124 ;
int V_26 ;
V_124 = V_22 -> V_124 ;
V_124 >>= 8 ;
if ( V_22 -> V_112 & V_174 ) {
V_89 -> V_126 = - V_175 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ ) {
switch ( V_124 & 0x7 ) {
case V_176 :
F_90 ( V_3 -> V_43 . V_44 , L_3
L_4 ,
V_45 , V_26 ) ;
V_89 -> V_126 = - V_177 ;
break;
case V_178 :
F_90 ( V_3 -> V_43 . V_44 , L_5
L_6 ,
V_45 , V_26 ) ;
V_89 -> V_126 = - V_175 ;
break;
case V_179 :
F_90 ( V_3 -> V_43 . V_44 , L_7
L_6 ,
V_45 , V_26 ) ;
V_89 -> V_126 = - V_180 ;
break;
}
V_124 >>= 3 ;
}
return V_181 ;
}
return V_182 ;
}
static int F_91 ( struct V_2 * V_3 , struct V_22 * V_22 ,
struct V_89 * V_89 )
{
F_19 ( ! V_22 ) ;
if ( V_22 -> V_112 & V_174 ) {
if ( V_22 -> V_112 & V_183 )
V_89 -> V_126 = - V_180 ;
else if ( F_92 ( V_22 -> V_112 ) )
V_89 -> V_126 = - V_160 ;
else if ( V_22 -> V_112 & V_184 )
V_89 -> V_126 = - V_175 ;
else
V_89 -> V_126 = - V_175 ;
return V_181 ;
}
if ( ( V_22 -> V_112 & V_184 ) && ( V_22 -> V_112 & V_118 ) ) {
F_90 ( V_3 -> V_43 . V_44 , L_8 ) ;
return V_185 ;
}
if ( ! F_93 ( V_22 -> V_112 ) && ( V_22 -> V_112 & V_118 ) ) {
return V_185 ;
}
return V_182 ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_22 V_22 ;
struct V_61 * V_63 ;
int V_21 ;
int V_57 ;
struct V_136 * V_137 ;
T_1 V_20 ;
struct V_39 * V_40 ;
int V_186 ;
int V_138 ;
V_138 = F_2 ( V_3 -> V_50 , V_81 ) ;
V_25 -> V_143 &= ~ V_138 ;
V_138 = F_2 ( V_3 -> V_50 , V_79 ) ;
V_25 -> V_141 &= ~ V_138 ;
V_186 = V_25 -> V_143 || V_25 -> V_141 ;
while ( V_25 -> V_143 || V_25 -> V_141 ) {
if ( V_25 -> V_143 ) {
V_21 = F_95 ( V_25 -> V_143 ) ;
V_25 -> V_143 &= ~ ( 1 << V_21 ) ;
V_137 = V_25 -> V_168 ;
if ( ! V_137 [ V_21 ] . V_63 ) {
F_19 ( 1 ) ;
continue;
}
V_20 = V_167 ;
F_15 ( V_3 -> V_50 , V_167 , V_21 , & V_22 ) ;
V_57 = F_89 ( V_3 , & V_22 ,
V_137 [ V_21 ] . V_40 -> V_89 ) ;
} else {
V_21 = F_95 ( V_25 -> V_141 ) ;
V_25 -> V_141 &= ~ ( 1 << V_21 ) ;
V_137 = V_25 -> V_169 ;
if ( ! V_137 [ V_21 ] . V_63 ) {
F_19 ( 1 ) ;
continue;
}
V_20 = V_140 ;
F_15 ( V_3 -> V_50 , V_140 , V_21 , & V_22 ) ;
V_57 = F_91 ( V_3 , & V_22 ,
V_137 [ V_21 ] . V_40 -> V_89 ) ;
}
V_40 = V_137 [ V_21 ] . V_40 ;
V_137 [ V_21 ] . V_40 = NULL ;
V_63 = V_137 [ V_21 ] . V_63 ;
V_137 [ V_21 ] . V_63 = NULL ;
V_63 -> V_21 = - 1 ;
F_19 ( V_40 -> V_126 != V_145 ) ;
switch ( V_57 ) {
case V_182 :
if ( ( F_54 ( V_40 -> V_89 -> V_98 ) ) &&
( V_40 -> V_89 -> V_97 -> V_103 != V_104 ) )
V_40 -> V_135 =
F_96 ( V_22 . V_112 ) ;
else
V_40 -> V_135 =
F_97 ( V_22 . V_112 ) ;
V_40 -> V_126 = V_152 ;
if ( F_40 ( & V_40 -> V_66 , & V_63 -> V_66 ) ||
F_79 ( V_40 ) )
V_40 = NULL ;
else
V_40 = F_41 ( V_40 -> V_66 . V_90 ,
F_42 ( * V_40 ) , V_66 ) ;
V_63 -> V_115 = F_98 ( V_22 . V_112 ) ;
V_63 -> V_113 = F_99 ( V_22 . V_112 ) ;
break;
case V_185 :
V_40 -> V_126 = V_139 ;
V_22 . V_23 |= V_99 ;
V_22 . V_112 &= ~ F_62 ( 0xf ) ;
V_22 . V_112 |= F_62 ( F_100 ( V_22 . V_114 ) ) ;
V_22 . V_112 &= ~ F_64 ( 3 ) ;
V_22 . V_112 |= F_64 ( V_119 ) ;
V_63 -> V_115 = F_98 ( V_22 . V_112 ) ;
V_63 -> V_113 = F_99 ( V_22 . V_112 ) ;
break;
case V_181 :
V_40 -> V_126 = V_153 ;
if ( ( V_40 -> V_89 -> V_97 -> V_103 != V_104 ) &&
( V_40 -> V_89 -> V_126 != - V_160 ) &&
( V_40 -> V_89 -> V_126 != - V_159 ) ) {
V_63 -> V_166 = 1 ;
if ( F_101 ( V_40 -> V_89 ) )
V_63 -> V_166 = 0 ;
}
V_40 = NULL ;
V_63 -> V_115 = 0 ;
V_63 -> V_113 = 0 ;
break;
default:
F_19 ( 1 ) ;
continue;
}
if ( V_40 && ( V_40 -> V_126 == V_139 ) ) {
if ( V_137 == V_25 -> V_168 ) {
if ( V_57 == V_185 )
F_22 ( V_3 -> V_43 . V_44 ,
L_9
L_10 , V_45 ) ;
if ( V_57 != V_185 )
F_66 ( V_63 , V_40 , & V_22 ) ;
} else {
if ( V_57 != V_185 )
F_43 ( V_63 , V_40 , & V_22 ) ;
}
F_78 ( V_3 , V_20 , V_21 , V_137 , V_40 ,
V_63 , & V_22 ) ;
}
}
if ( V_186 )
F_87 ( V_3 ) ;
}
static T_8 F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_187 ;
T_8 V_188 = V_189 ;
F_75 ( & V_25 -> V_68 ) ;
if ( ! ( V_3 -> V_57 & V_190 ) )
goto V_191;
V_187 = F_2 ( V_3 -> V_50 , V_192 ) ;
if ( F_82 ( ! V_187 ) )
goto V_191;
F_4 ( V_3 -> V_50 , V_192 , V_187 ) ;
V_25 -> V_143 |= F_2 ( V_3 -> V_50 , V_144 ) ;
V_25 -> V_141 |= F_2 ( V_3 -> V_50 , V_142 ) ;
F_94 ( V_3 ) ;
V_188 = V_193 ;
V_191:
F_73 ( & V_25 -> V_68 ) ;
return V_188 ;
}
static void F_103 ( unsigned long V_194 )
{
struct V_2 * V_3 = (struct V_2 * ) V_194 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_21 ;
struct V_22 V_22 ;
unsigned long V_195 ;
F_104 ( & V_25 -> V_68 , V_195 ) ;
for ( V_21 = 0 ; V_21 < 32 ; V_21 ++ )
if ( V_25 -> V_169 [ V_21 ] . V_63 && F_105 ( V_60 ,
V_25 -> V_169 [ V_21 ] . V_146 +
F_106 ( V_196 ) ) ) {
F_15 ( V_3 -> V_50 , V_140 , V_21 , & V_22 ) ;
if ( ! F_107 ( V_22 . V_23 ) &&
! F_108 ( V_22 . V_112 ) )
V_25 -> V_141 |= 1 << V_21 ;
}
if ( V_25 -> V_141 )
F_94 ( V_3 ) ;
F_109 ( & V_25 -> V_68 , V_195 ) ;
V_197 . V_198 = V_60 + F_106 ( V_199 ) ;
F_110 ( & V_197 ) ;
}
static int F_111 ( struct V_2 * V_3 )
{
int V_53 ;
T_1 V_200 ;
T_1 V_54 ;
T_1 V_201 ;
V_3 -> V_202 = 1 ;
V_3 -> V_57 = V_190 ;
F_4 ( V_3 -> V_50 , V_203 , 0 ) ;
F_4 ( V_3 -> V_50 , V_204 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_205 , 0 ) ;
F_4 ( V_3 -> V_50 , V_206 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_207 , 0 ) ;
F_4 ( V_3 -> V_50 , V_208 , 0xffffffff ) ;
V_200 = F_2 ( V_3 -> V_50 , V_83 ) ;
F_4 ( V_3 -> V_50 , V_83 , V_200 | V_209 ) ;
V_54 = F_2 ( V_3 -> V_50 , V_55 ) ;
V_54 &= ~ ( V_210 | V_56 ) ;
V_54 |= V_211 ;
F_4 ( V_3 -> V_50 , V_55 , V_54 ) ;
V_53 = F_23 ( V_3 , V_55 , V_211 , V_211 , 250 * 1000 ) ;
if ( V_53 )
return V_53 ;
F_112 ( & V_212 ) ;
F_4 ( V_3 -> V_50 , V_213 , V_214 ) ;
V_53 = F_23 ( V_3 , V_213 , V_214 , V_214 , 250 * 1000 ) ;
F_113 ( & V_212 ) ;
if ( V_53 )
return V_53 ;
F_114 ( & V_197 , F_103 , ( unsigned long ) V_3 ) ;
V_197 . V_198 = V_60 + F_106 ( V_199 ) ;
F_110 ( & V_197 ) ;
V_201 = F_2 ( V_3 -> V_50 , V_77 ) ;
F_115 ( V_3 -> V_43 . V_44 , L_11 ,
V_201 & 0xffff , V_201 >> 16 ) ;
F_4 ( V_3 -> V_50 , V_215 , 0x80000000 ) ;
F_4 ( V_3 -> V_50 , V_216 , 0x80000000 ) ;
F_4 ( V_3 -> V_50 , V_217 , 0x00000001 ) ;
F_4 ( V_3 -> V_50 , V_79 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_81 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_82 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_78 ,
V_218 | V_219 ) ;
return 0 ;
}
static int F_116 ( struct V_39 * V_40 , void * V_220 , T_9 V_221 )
{
V_40 -> V_116 = V_220 ;
if ( V_221 > V_222 )
V_221 = V_222 ;
V_40 -> V_41 = V_221 ;
return V_40 -> V_41 ;
}
static void F_117 ( struct V_147 * V_66 )
{
struct V_39 * V_40 , * V_150 ;
F_81 (qtd, qtd_next, qtd_list, qtd_list) {
F_84 ( & V_40 -> V_66 ) ;
F_77 ( V_40 ) ;
}
}
static void F_118 ( struct V_2 * V_3 ,
struct V_89 * V_89 , struct V_147 * V_223 , T_5 V_62 )
{
struct V_39 * V_40 ;
void * V_224 ;
int V_221 , V_225 ;
T_6 V_100 ;
if ( ! V_89 -> V_130 && V_89 -> V_131 ) {
F_22 ( V_3 -> V_43 . V_44 ,
L_12 ,
( long unsigned ) V_89 -> V_226 ,
V_89 -> V_131 ) ;
F_19 ( 1 ) ;
}
if ( F_68 ( V_89 -> V_98 ) )
V_100 = V_154 ;
else
V_100 = V_155 ;
if ( F_58 ( V_89 -> V_98 ) ) {
V_40 = F_76 ( V_62 , V_89 , V_156 ) ;
if ( ! V_40 )
goto V_227;
F_116 ( V_40 , V_89 -> V_117 , sizeof( struct V_228 ) ) ;
F_83 ( & V_40 -> V_66 , V_223 ) ;
if ( V_89 -> V_131 == 0 )
V_100 = V_154 ;
}
V_225 = F_119 ( F_44 ( V_89 -> V_97 , V_89 -> V_98 ,
F_45 ( V_89 -> V_98 ) ) ) ;
V_224 = V_89 -> V_130 ;
V_221 = V_89 -> V_131 ;
for (; ; ) {
int V_229 ;
V_40 = F_76 ( V_62 , V_89 , V_100 ) ;
if ( ! V_40 )
goto V_227;
V_229 = F_116 ( V_40 , V_224 , V_221 ) ;
F_83 ( & V_40 -> V_66 , V_223 ) ;
V_221 -= V_229 ;
V_224 += V_229 ;
if ( V_221 <= 0 )
break;
}
if ( V_89 -> V_131 != 0 ) {
int V_230 = 0 ;
if ( F_58 ( V_89 -> V_98 ) ) {
V_230 = 1 ;
if ( V_100 == V_154 )
V_100 = V_155 ;
else
V_100 = V_154 ;
} else if ( F_53 ( V_89 -> V_98 )
&& ( V_89 -> V_157 & V_231 )
&& ! ( V_89 -> V_131 %
V_225 ) ) {
V_230 = 1 ;
}
if ( V_230 ) {
V_40 = F_76 ( V_62 , V_89 , V_100 ) ;
if ( ! V_40 )
goto V_227;
F_116 ( V_40 , NULL , 0 ) ;
F_83 ( & V_40 -> V_66 , V_223 ) ;
}
}
return;
V_227:
F_117 ( V_223 ) ;
}
static int F_120 ( struct V_2 * V_3 , struct V_89 * V_89 ,
T_5 V_232 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_147 * V_172 ;
struct V_61 * V_63 , * V_233 ;
unsigned long V_195 ;
F_88 ( V_234 ) ;
int V_53 ;
int V_235 ;
switch ( F_69 ( V_89 -> V_98 ) ) {
case V_128 :
V_172 = & V_25 -> V_65 [ V_236 ] ;
break;
case V_237 :
V_172 = & V_25 -> V_65 [ V_238 ] ;
break;
case V_239 :
if ( V_89 -> V_122 < 0 )
return - V_240 ;
V_172 = & V_25 -> V_65 [ V_241 ] ;
break;
case V_242 :
F_22 ( V_3 -> V_43 . V_44 , L_13
L_14 ,
V_45 ) ;
return - V_160 ;
default:
F_22 ( V_3 -> V_43 . V_44 , L_15 ,
V_45 ) ;
return - V_160 ;
}
if ( F_68 ( V_89 -> V_98 ) )
V_89 -> V_135 = 0 ;
F_118 ( V_3 , V_89 , & V_234 , V_232 ) ;
if ( F_30 ( & V_234 ) )
return - V_243 ;
V_53 = 0 ;
F_104 ( & V_25 -> V_68 , V_195 ) ;
if ( ! F_121 ( V_244 , & V_3 -> V_62 ) ) {
V_53 = - V_245 ;
F_117 ( & V_234 ) ;
goto V_246;
}
V_53 = F_122 ( V_3 , V_89 ) ;
if ( V_53 ) {
F_117 ( & V_234 ) ;
goto V_246;
}
V_63 = V_89 -> V_247 -> V_248 ;
if ( V_63 ) {
V_235 = 0 ;
F_86 (qhit, ep_queue, qh_list) {
if ( V_233 == V_63 ) {
V_235 = 1 ;
break;
}
}
if ( ! V_235 )
F_83 ( & V_63 -> V_65 , V_172 ) ;
} else {
V_63 = F_26 ( V_162 ) ;
if ( ! V_63 ) {
V_53 = - V_243 ;
F_72 ( V_3 , V_89 ) ;
F_117 ( & V_234 ) ;
goto V_246;
}
F_83 ( & V_63 -> V_65 , V_172 ) ;
V_89 -> V_247 -> V_248 = V_63 ;
}
F_123 ( & V_234 , & V_63 -> V_66 ) ;
F_87 ( V_3 ) ;
V_246:
F_109 ( & V_25 -> V_68 , V_195 ) ;
return V_53 ;
}
static void F_124 ( struct V_2 * V_3 , struct V_89 * V_89 ,
struct V_61 * V_63 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_138 ;
F_19 ( V_63 -> V_21 == - 1 ) ;
if ( F_58 ( V_89 -> V_98 ) || F_53 ( V_89 -> V_98 ) ) {
V_138 = F_2 ( V_3 -> V_50 , V_79 ) ;
V_138 |= ( 1 << V_63 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_79 , V_138 ) ;
V_25 -> V_169 [ V_63 -> V_21 ] . V_63 = NULL ;
V_25 -> V_169 [ V_63 -> V_21 ] . V_40 = NULL ;
} else {
V_138 = F_2 ( V_3 -> V_50 , V_81 ) ;
V_138 |= ( 1 << V_63 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_81 , V_138 ) ;
V_25 -> V_168 [ V_63 -> V_21 ] . V_63 = NULL ;
V_25 -> V_168 [ V_63 -> V_21 ] . V_40 = NULL ;
}
V_63 -> V_21 = - 1 ;
}
static void F_125 ( struct V_2 * V_3 , struct V_61 * V_63 ,
struct V_39 * V_40 )
{
struct V_89 * V_89 ;
int V_249 ;
V_89 = V_40 -> V_89 ;
V_249 = 0 ;
F_126 (qtd, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_89 != V_89 )
break;
if ( V_40 -> V_126 >= V_145 )
V_249 = 1 ;
if ( F_39 ( V_40 , V_63 ) &&
( V_40 -> V_126 >= V_152 ) )
V_249 = 0 ;
if ( V_40 -> V_126 == V_145 )
F_124 ( V_3 , V_89 , V_63 ) ;
V_40 -> V_126 = V_153 ;
}
if ( ( V_89 -> V_97 -> V_103 != V_104 ) && V_249 ) {
V_63 -> V_166 = 1 ;
if ( F_101 ( V_89 ) )
V_63 -> V_166 = 0 ;
}
}
static int F_127 ( struct V_2 * V_3 , struct V_89 * V_89 ,
int V_126 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned long V_195 ;
struct V_61 * V_63 ;
struct V_39 * V_40 ;
int V_53 = 0 ;
F_104 ( & V_25 -> V_68 , V_195 ) ;
V_53 = F_128 ( V_3 , V_89 , V_126 ) ;
if ( V_53 )
goto V_246;
V_63 = V_89 -> V_247 -> V_248 ;
if ( ! V_63 ) {
V_53 = - V_240 ;
goto V_246;
}
F_86 (qtd, &qh->qtd_list, qtd_list)
if ( V_40 -> V_89 == V_89 ) {
F_125 ( V_3 , V_63 , V_40 ) ;
F_129 ( & V_40 -> V_66 , & V_63 -> V_66 ) ;
break;
}
V_89 -> V_126 = V_126 ;
F_87 ( V_3 ) ;
V_246:
F_109 ( & V_25 -> V_68 , V_195 ) ;
return V_53 ;
}
static void F_130 ( struct V_2 * V_3 ,
struct V_250 * V_247 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned long V_195 ;
struct V_61 * V_63 , * V_251 ;
int V_26 ;
F_104 ( & V_25 -> V_68 , V_195 ) ;
V_63 = V_247 -> V_248 ;
if ( ! V_63 )
goto V_246;
F_19 ( ! F_30 ( & V_63 -> V_66 ) ) ;
for ( V_26 = 0 ; V_26 < V_69 ; V_26 ++ )
F_86 (qh_iter, &priv->qh_list[i], qh_list)
if ( V_251 == V_63 ) {
F_84 ( & V_251 -> V_65 ) ;
V_26 = V_69 ;
break;
}
F_29 ( V_63 ) ;
V_247 -> V_248 = NULL ;
F_87 ( V_3 ) ;
V_246:
F_109 ( & V_25 -> V_68 , V_195 ) ;
}
static int F_131 ( struct V_2 * V_3 , char * V_224 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_200 , V_126 = 0 ;
T_1 V_46 ;
int V_53 = 1 ;
unsigned long V_62 ;
if ( ! F_132 ( V_3 -> V_57 ) )
return 0 ;
V_224 [ 0 ] = 0 ;
V_46 = V_252 ;
F_104 ( & V_25 -> V_68 , V_62 ) ;
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
&& F_133 ( V_60 ,
V_25 -> V_256 ) ) ) {
V_224 [ 0 ] |= 1 << ( 0 + 1 ) ;
V_126 = V_257 ;
}
V_47:
F_109 ( & V_25 -> V_68 , V_62 ) ;
return V_126 ? V_53 : 0 ;
}
static void F_134 ( struct V_1 * V_25 ,
struct V_258 * V_259 )
{
int V_260 = F_135 ( V_25 -> V_87 ) ;
T_10 V_200 ;
V_259 -> V_261 = 0x29 ;
V_259 -> V_262 = 10 ;
V_259 -> V_263 = 0 ;
V_259 -> V_264 = V_260 ;
V_200 = 1 + ( V_260 / 8 ) ;
V_259 -> V_265 = 7 + 2 * V_200 ;
memset ( & V_259 -> V_266 . V_267 . V_268 [ 0 ] , 0 , V_200 ) ;
memset ( & V_259 -> V_266 . V_267 . V_268 [ V_200 ] , 0xff , V_200 ) ;
V_200 = V_269 ;
if ( F_136 ( V_25 -> V_87 ) )
V_200 |= V_270 ;
else
V_200 |= V_271 ;
V_259 -> V_272 = F_137 ( V_200 ) ;
}
static int F_138 ( struct V_2 * V_3 , int V_273 ,
int V_274 )
{
if ( ! ( V_274 & V_275 ) )
return V_274 ;
if ( ! ( V_274 & V_276 ) ) {
F_115 ( V_3 -> V_43 . V_44 ,
L_16 ,
V_273 + 1 ) ;
V_274 |= V_254 ;
V_274 &= ~ V_277 ;
F_4 ( V_3 -> V_50 , V_253 , V_274 ) ;
} else
F_115 ( V_3 -> V_43 . V_44 , L_17 ,
V_273 + 1 ) ;
return V_274 ;
}
static int F_139 ( struct V_2 * V_3 , T_10 V_278 ,
T_10 V_279 , T_10 V_280 , char * V_224 , T_10 V_281 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_260 = F_135 ( V_25 -> V_87 ) ;
T_1 V_200 , V_126 ;
unsigned long V_62 ;
int V_53 = 0 ;
unsigned V_282 ;
F_104 ( & V_25 -> V_68 , V_62 ) ;
switch ( V_278 ) {
case V_283 :
switch ( V_279 ) {
case V_284 :
case V_285 :
break;
default:
goto error;
}
break;
case V_286 :
if ( ! V_280 || V_280 > V_260 )
goto error;
V_280 -- ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
switch ( V_279 ) {
case V_287 :
F_4 ( V_3 -> V_50 , V_253 , V_200 & ~ V_276 ) ;
break;
case V_288 :
break;
case V_289 :
if ( V_200 & V_290 )
goto error;
if ( V_200 & V_291 ) {
if ( ( V_200 & V_276 ) == 0 )
goto error;
V_200 &= ~ ( V_277 ) ;
F_4 ( V_3 -> V_50 , V_253 ,
V_200 | V_255 ) ;
V_25 -> V_256 = V_60 +
F_106 ( 20 ) ;
}
break;
case V_292 :
break;
case V_293 :
if ( F_136 ( V_25 -> V_87 ) )
F_4 ( V_3 -> V_50 , V_253 ,
V_200 & ~ V_294 ) ;
break;
case V_295 :
F_4 ( V_3 -> V_50 , V_253 , V_200 | V_252 ) ;
break;
case V_296 :
break;
case V_297 :
break;
default:
goto error;
}
F_2 ( V_3 -> V_50 , V_55 ) ;
break;
case V_298 :
F_134 ( V_25 , (struct V_258 * )
V_224 ) ;
break;
case V_299 :
memset ( V_224 , 0 , 4 ) ;
break;
case V_300 :
if ( ! V_280 || V_280 > V_260 )
goto error;
V_280 -- ;
V_126 = 0 ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
if ( V_200 & V_252 )
V_126 |= V_301 << 16 ;
if ( V_200 & V_255 ) {
F_22 ( V_3 -> V_43 . V_44 , L_18 ) ;
if ( ! V_25 -> V_256 ) {
V_25 -> V_256 = V_60
+ F_106 ( 20 ) ;
F_140 ( & V_3 -> V_302 , V_25 -> V_256 ) ;
}
else if ( F_133 ( V_60 ,
V_25 -> V_256 ) ) {
V_126 |= V_303 << 16 ;
V_25 -> V_256 = 0 ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
F_4 ( V_3 -> V_50 , V_253 ,
V_200 & ~ ( V_277 | V_255 ) ) ;
V_53 = F_23 ( V_3 , V_253 ,
V_255 , 0 , 2000 ) ;
if ( V_53 != 0 ) {
F_22 ( V_3 -> V_43 . V_44 ,
L_19 ,
V_280 + 1 , V_53 ) ;
goto error;
}
V_200 &= ~ ( V_291 | V_255 | ( 3 << 10 ) ) ;
}
}
if ( ( V_200 & V_290 )
&& F_133 ( V_60 ,
V_25 -> V_256 ) ) {
V_126 |= V_304 << 16 ;
V_25 -> V_256 = 0 ;
F_4 ( V_3 -> V_50 , V_253 , V_200 & ~ V_290 ) ;
V_53 = F_23 ( V_3 , V_253 ,
V_290 , 0 , 750 ) ;
if ( V_53 != 0 ) {
F_22 ( V_3 -> V_43 . V_44 , L_20 ,
V_280 + 1 , V_53 ) ;
goto error;
}
V_200 = F_138 ( V_3 , V_280 ,
F_2 ( V_3 -> V_50 , V_253 ) ) ;
}
if ( V_200 & V_254 )
F_22 ( V_3 -> V_43 . V_44 , L_21 ) ;
if ( V_200 & V_275 ) {
V_126 |= V_305 ;
V_126 |= V_306 ;
}
if ( V_200 & V_276 )
V_126 |= V_307 ;
if ( V_200 & ( V_291 | V_255 ) )
V_126 |= V_308 ;
if ( V_200 & V_290 )
V_126 |= V_309 ;
if ( V_200 & V_294 )
V_126 |= V_310 ;
F_141 ( F_14 ( V_126 ) , ( V_311 * ) V_224 ) ;
break;
case V_312 :
switch ( V_279 ) {
case V_284 :
case V_285 :
break;
default:
goto error;
}
break;
case V_313 :
V_282 = V_280 >> 8 ;
V_280 &= 0xff ;
if ( ! V_280 || V_280 > V_260 )
goto error;
V_280 -- ;
V_200 = F_2 ( V_3 -> V_50 , V_253 ) ;
if ( V_200 & V_254 )
break;
switch ( V_279 ) {
case V_287 :
F_4 ( V_3 -> V_50 , V_253 , V_200 | V_276 ) ;
break;
case V_289 :
if ( ( V_200 & V_276 ) == 0
|| ( V_200 & V_290 ) != 0 )
goto error;
F_4 ( V_3 -> V_50 , V_253 , V_200 | V_291 ) ;
break;
case V_293 :
if ( F_136 ( V_25 -> V_87 ) )
F_4 ( V_3 -> V_50 , V_253 ,
V_200 | V_294 ) ;
break;
case V_314 :
if ( V_200 & V_255 )
goto error;
if ( ( V_200 & ( V_276 | V_275 ) ) == V_275
&& F_142 ( V_200 ) ) {
V_200 |= V_254 ;
} else {
V_200 |= V_290 ;
V_200 &= ~ V_276 ;
V_25 -> V_256 = V_60 +
F_106 ( 50 ) ;
}
F_4 ( V_3 -> V_50 , V_253 , V_200 ) ;
break;
default:
goto error;
}
F_2 ( V_3 -> V_50 , V_55 ) ;
break;
default:
error:
V_53 = - V_160 ;
}
F_109 ( & V_25 -> V_68 , V_62 ) ;
return V_53 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_315 ;
V_315 = F_2 ( V_3 -> V_50 , V_316 ) ;
return ( V_315 >> 3 ) % V_25 -> V_70 ;
}
static void F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_200 ;
F_145 ( & V_197 ) ;
F_139 ( V_3 , V_286 , V_293 , 1 ,
NULL , 0 ) ;
F_37 ( 20 ) ;
F_146 ( & V_25 -> V_68 ) ;
F_25 ( V_3 ) ;
V_200 = F_2 ( V_3 -> V_50 , V_83 ) ;
F_4 ( V_3 -> V_50 , V_83 , V_200 &= ~ V_209 ) ;
F_147 ( & V_25 -> V_68 ) ;
F_4 ( V_3 -> V_50 , V_213 , 0 ) ;
}
static void F_148 ( struct V_2 * V_3 )
{
T_1 V_54 , V_200 ;
F_144 ( V_3 ) ;
V_200 = F_2 ( V_3 -> V_50 , V_83 ) ;
F_4 ( V_3 -> V_50 , V_83 , V_200 &= ~ V_209 ) ;
V_54 = F_2 ( V_3 -> V_50 , V_55 ) ;
V_54 &= ~ V_211 ;
F_4 ( V_3 -> V_50 , V_55 , V_54 ) ;
}
static void F_149 ( struct V_2 * V_3 ,
struct V_250 * V_247 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_61 * V_63 = V_247 -> V_248 ;
unsigned long V_195 ;
if ( ! V_63 )
return;
F_104 ( & V_25 -> V_68 , V_195 ) ;
V_63 -> V_166 = 0 ;
F_87 ( V_3 ) ;
F_109 ( & V_25 -> V_68 , V_195 ) ;
}
int T_11 F_150 ( void )
{
V_161 = F_151 ( L_22 ,
sizeof( struct V_151 ) , 0 , V_317 |
V_318 , NULL ) ;
if ( ! V_161 )
return - V_243 ;
V_133 = F_151 ( L_23 ,
sizeof( struct V_39 ) , 0 , V_317 |
V_318 , NULL ) ;
if ( ! V_133 )
return - V_243 ;
V_64 = F_151 ( L_24 , sizeof( struct V_61 ) ,
0 , V_317 | V_318 , NULL ) ;
if ( ! V_64 ) {
F_152 ( V_133 ) ;
return - V_243 ;
}
return 0 ;
}
void F_153 ( void )
{
F_152 ( V_133 ) ;
F_152 ( V_64 ) ;
F_152 ( V_161 ) ;
}
int F_154 ( struct V_1 * V_25 , void T_2 * V_50 ,
struct V_319 * V_320 , int V_321 , unsigned long V_322 ,
struct V_323 * V_97 )
{
struct V_2 * V_3 ;
int V_324 ;
V_3 = F_155 ( & V_325 , V_97 , F_156 ( V_97 ) ) ;
if ( ! V_3 )
return - V_243 ;
* (struct V_1 * * ) V_3 -> V_4 = V_25 ;
V_25 -> V_3 = V_3 ;
F_18 ( V_25 ) ;
V_3 -> V_321 = V_321 ;
V_3 -> V_50 = V_50 ;
V_3 -> V_326 = V_320 -> V_31 ;
V_3 -> V_327 = F_157 ( V_320 ) ;
V_3 -> V_328 = 1 ;
V_324 = F_158 ( V_3 , V_321 , V_322 ) ;
if ( V_324 )
goto error;
F_159 ( V_3 -> V_43 . V_44 ) ;
return 0 ;
error:
F_160 ( V_3 ) ;
return V_324 ;
}
void F_161 ( struct V_1 * V_25 )
{
if ( ! V_25 -> V_3 )
return;
F_162 ( V_25 -> V_3 ) ;
F_160 ( V_25 -> V_3 ) ;
}
