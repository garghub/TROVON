static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) ( V_3 -> V_4 ) ;
}
static T_1 F_2 ( void T_2 * V_5 , T_1 V_6 )
{
return F_3 ( V_5 + V_6 ) ;
}
static void F_4 ( void T_2 * V_5 , T_1 V_6 , T_1 V_7 )
{
F_5 ( V_7 , V_5 + V_6 ) ;
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
F_33 ( & V_25 -> V_68 ) ;
F_28 ( & V_25 -> V_69 ) ;
F_28 ( & V_25 -> V_70 ) ;
F_28 ( & V_25 -> V_71 ) ;
V_25 -> V_72 = V_73 ;
V_67 = F_2 ( V_3 -> V_50 , V_74 ) ;
if ( F_34 ( V_67 ) )
V_25 -> V_75 = 8 ;
else
V_25 -> V_75 = 2 + F_35 ( V_67 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_49 ;
T_1 V_76 , V_77 ;
if ( F_37 ( V_25 -> V_78 ) ) {
unsigned int V_79 ;
V_79 = ( V_25 -> V_80 &
V_81 ) ? 1 : 0 ;
F_38 ( V_25 -> V_78 , V_79 ) ;
F_39 ( 50 ) ;
F_38 ( V_25 -> V_78 , ! V_79 ) ;
}
V_77 = V_82 ;
if ( V_25 -> V_80 & V_83 )
V_77 &= ~ V_82 ;
if ( V_25 -> V_80 & V_84 )
V_77 |= V_85 ;
if ( V_25 -> V_80 & V_86 )
V_77 |= V_87 ;
if ( V_25 -> V_80 & V_88 )
V_77 |= V_89 ;
if ( V_25 -> V_80 & V_90 )
V_77 |= V_91 ;
if ( V_25 -> V_80 & V_92 )
V_77 |= V_93 ;
F_4 ( V_3 -> V_50 , V_94 , V_77 ) ;
F_4 ( V_3 -> V_50 , V_94 , V_77 ) ;
F_4 ( V_3 -> V_50 , V_95 , 0xdeadbabe ) ;
V_76 = F_2 ( V_3 -> V_50 , V_96 ) ;
V_76 = F_2 ( V_3 -> V_50 , V_95 ) ;
if ( V_76 != 0xdeadbabe ) {
F_22 ( V_3 -> V_43 . V_44 , L_2 ) ;
return - V_51 ;
}
F_4 ( V_3 -> V_50 , V_97 , 0 ) ;
F_4 ( V_3 -> V_50 , V_98 , V_99 ) ;
F_4 ( V_3 -> V_50 , V_100 , V_99 ) ;
F_4 ( V_3 -> V_50 , V_101 , V_99 ) ;
F_4 ( V_3 -> V_50 , V_102 , V_103 ) ;
F_39 ( 100 ) ;
F_4 ( V_3 -> V_50 , V_102 , V_104 ) ;
F_39 ( 100 ) ;
V_49 = F_25 ( V_3 ) ;
if ( V_49 )
return V_49 ;
F_40 ( V_3 -> V_43 . V_44 , L_3 ,
( V_25 -> V_80 & V_83 ) ?
16 : 32 , ( V_25 -> V_80 & V_84 ) ?
L_4 : L_5 ) ;
F_4 ( V_3 -> V_50 , V_94 , V_77 | V_105 ) ;
F_39 ( 10 ) ;
F_4 ( V_3 -> V_50 , V_94 , V_77 ) ;
F_4 ( V_3 -> V_50 , V_106 , V_107 ) ;
F_4 ( V_3 -> V_50 , V_108 , V_109 | V_110 ) ;
F_39 ( 10 ) ;
V_25 -> V_111 = F_2 ( V_3 -> V_50 , V_112 ) ;
return F_32 ( V_3 ) ;
}
static T_1 F_41 ( T_1 V_5 )
{
return ( ( V_5 - 0x400 ) >> 3 ) ;
}
static int F_42 ( struct V_39 * V_40 , struct V_61 * V_63 )
{
struct V_113 * V_113 ;
if ( F_43 ( & V_40 -> V_66 , & V_63 -> V_66 ) )
return 1 ;
V_113 = V_40 -> V_113 ;
V_40 = F_44 ( V_40 -> V_66 . V_114 , F_45 ( * V_40 ) , V_66 ) ;
return ( V_40 -> V_113 != V_113 ) ;
}
static void F_46 ( struct V_61 * V_63 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
T_1 V_115 ;
T_1 V_116 ;
T_1 V_117 = V_118 ;
T_1 V_119 = V_120 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_115 = F_47 ( V_40 -> V_113 -> V_121 , V_40 -> V_113 -> V_122 ,
F_48 ( V_40 -> V_113 -> V_122 ) ) ;
V_116 = 1 + ( ( V_115 >> 11 ) & 0x3 ) ;
V_115 &= 0x7ff ;
V_22 -> V_23 = V_123 ;
V_22 -> V_23 |= F_49 ( V_40 -> V_41 ) ;
V_22 -> V_23 |= F_50 ( V_115 ) ;
V_22 -> V_23 |= F_51 ( F_52 ( V_40 -> V_113 -> V_122 ) ) ;
V_22 -> V_24 = F_52 ( V_40 -> V_113 -> V_122 ) >> 1 ;
V_22 -> V_24 |= F_53 ( F_54 ( V_40 -> V_113 -> V_122 ) ) ;
V_22 -> V_24 |= F_55 ( V_40 -> V_124 ) ;
if ( F_56 ( V_40 -> V_113 -> V_122 ) )
V_22 -> V_24 |= V_125 ;
else if ( F_57 ( V_40 -> V_113 -> V_122 ) )
V_22 -> V_24 |= V_126 ;
if ( V_40 -> V_113 -> V_121 -> V_127 != V_128 ) {
V_22 -> V_24 |= V_129 ;
if ( V_40 -> V_113 -> V_121 -> V_127 == V_130 )
V_22 -> V_24 |= V_131 ;
V_22 -> V_24 |= F_58 ( V_40 -> V_113 -> V_121 -> V_132 ) ;
V_22 -> V_24 |= F_59 ( V_40 -> V_113 -> V_121 -> V_133 -> V_134 -> V_135 ) ;
if ( F_57 ( V_40 -> V_113 -> V_122 ) &&
( V_40 -> V_113 -> V_121 -> V_127 == V_130 ) )
V_22 -> V_24 |= 2 << 16 ;
V_117 = 0 ;
V_119 = 0 ;
} else {
V_22 -> V_23 |= F_60 ( V_116 ) ;
if ( F_61 ( V_40 -> V_113 -> V_122 ) ||
F_56 ( V_40 -> V_113 -> V_122 ) )
V_22 -> V_136 |= F_62 ( V_63 -> V_137 ) ;
}
V_22 -> V_138 = 0 ;
V_22 -> V_138 |= F_63 ( F_41 ( V_40 -> V_28 ) ) ;
V_22 -> V_138 |= F_64 ( V_117 ) ;
V_22 -> V_136 |= F_65 ( V_119 ) ;
V_22 -> V_136 |= F_66 ( V_63 -> V_139 ) ;
if ( F_61 ( V_40 -> V_113 -> V_122 ) ) {
if ( V_40 -> V_140 == V_40 -> V_113 -> V_141 )
V_22 -> V_136 &= ~ F_66 ( 1 ) ;
else if ( F_42 ( V_40 , V_63 ) )
V_22 -> V_136 |= F_66 ( 1 ) ;
}
V_22 -> V_136 |= V_142 ;
V_22 -> V_136 |= F_67 ( V_143 ) ;
}
static void F_68 ( struct V_61 * V_63 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
T_1 V_144 ;
T_1 V_145 ;
if ( V_40 -> V_113 -> V_121 -> V_127 == V_128 ) {
V_145 = V_40 -> V_113 -> V_146 >> 3 ;
if ( V_40 -> V_113 -> V_146 > 4 )
V_144 = 0x01 ;
else if ( V_40 -> V_113 -> V_146 > 2 )
V_144 = 0x22 ;
else if ( V_40 -> V_113 -> V_146 > 1 )
V_144 = 0x55 ;
else
V_144 = 0xff ;
} else {
V_145 = V_40 -> V_113 -> V_146 ;
V_144 = 0x0f ;
V_22 -> V_147 = 0xff ;
}
V_145 = V_145 >> 1 ;
V_145 &= 0xf8 ;
V_22 -> V_138 |= V_145 ;
V_22 -> V_148 = V_144 ;
}
static void F_69 ( struct V_61 * V_63 ,
struct V_39 * V_40 , struct V_22 * V_22 )
{
F_46 ( V_63 , V_40 , V_22 ) ;
F_68 ( V_63 , V_40 , V_22 ) ;
}
static void F_70 ( struct V_2 * V_3 , struct V_113 * V_113 )
__releases( V_25 -> V_68 )
__acquires( V_25 -> V_68 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
if ( ! V_113 -> V_149 ) {
if ( V_113 -> V_150 == - V_151 )
V_113 -> V_150 = 0 ;
}
if ( F_71 ( V_113 -> V_122 ) && F_72 ( V_113 -> V_122 ) != V_152 ) {
void * V_153 ;
for ( V_153 = V_113 -> V_154 ;
V_153 < V_113 -> V_154 + V_113 -> V_155 ;
V_153 += V_156 )
F_73 ( F_74 ( V_153 ) ) ;
}
F_75 ( V_3 , V_113 ) ;
F_76 ( & V_25 -> V_68 ) ;
F_77 ( V_3 , V_113 , V_113 -> V_150 ) ;
F_78 ( & V_25 -> V_68 ) ;
}
static struct V_39 * F_79 ( T_5 V_62 , struct V_113 * V_113 ,
T_6 V_124 )
{
struct V_39 * V_40 ;
V_40 = F_27 ( V_157 , V_62 ) ;
if ( ! V_40 )
return NULL ;
F_28 ( & V_40 -> V_66 ) ;
V_40 -> V_113 = V_113 ;
V_40 -> V_124 = V_124 ;
V_40 -> V_150 = V_158 ;
V_40 -> V_159 = 0 ;
return V_40 ;
}
static void F_80 ( struct V_39 * V_40 )
{
F_19 ( V_40 -> V_28 ) ;
F_31 ( V_157 , V_40 ) ;
}
static void F_81 ( struct V_2 * V_3 , T_1 V_20 , int V_21 ,
struct V_160 * V_161 , struct V_39 * V_40 ,
struct V_61 * V_63 , struct V_22 * V_22 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_162 ;
F_19 ( ( V_21 < 0 ) || ( V_21 > 31 ) ) ;
F_19 ( V_40 -> V_41 && ! V_40 -> V_28 ) ;
F_19 ( V_161 [ V_21 ] . V_40 ) ;
F_19 ( V_161 [ V_21 ] . V_63 ) ;
F_19 ( V_40 -> V_150 != V_163 ) ;
if ( V_20 == V_164 ) {
V_25 -> V_165 |= F_2 ( V_3 -> V_50 ,
V_166 ) ;
V_25 -> V_165 &= ~ ( 1 << V_21 ) ;
} else {
V_25 -> V_167 |= F_2 ( V_3 -> V_50 ,
V_168 ) ;
V_25 -> V_167 &= ~ ( 1 << V_21 ) ;
}
V_63 -> V_21 = V_21 ;
V_40 -> V_150 = V_169 ;
V_161 [ V_21 ] . V_170 = V_60 ;
V_161 [ V_21 ] . V_40 = V_40 ;
V_161 [ V_21 ] . V_63 = V_63 ;
F_16 ( V_3 -> V_50 , V_20 , V_21 , V_22 ) ;
if ( V_20 == V_164 ) {
V_162 = F_2 ( V_3 -> V_50 , V_98 ) ;
V_162 &= ~ ( 1 << V_63 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_98 , V_162 ) ;
} else {
V_162 = F_2 ( V_3 -> V_50 , V_100 ) ;
V_162 &= ~ ( 1 << V_63 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_100 , V_162 ) ;
}
}
static int F_82 ( struct V_39 * V_40 )
{
return ( F_56 ( V_40 -> V_113 -> V_122 ) &&
( V_40 -> V_159 < V_40 -> V_41 ) ) ;
}
static void F_83 ( struct V_2 * V_3 , struct V_61 * V_63 ,
struct V_171 * V_172 )
{
int V_173 ;
struct V_39 * V_40 , * V_174 ;
struct V_175 * V_175 ;
F_84 (qtd, qtd_next, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_150 < V_176 )
break;
V_173 = F_42 ( V_40 , V_63 ) ;
if ( ( ! V_173 ) && ( V_40 -> V_150 == V_177 ) )
V_174 -> V_150 = V_177 ;
if ( V_40 -> V_150 == V_176 ) {
if ( V_40 -> V_159 ) {
switch ( V_40 -> V_124 ) {
case V_178 :
F_9 ( V_3 -> V_50 , V_40 -> V_28 ,
V_40 -> V_140 ,
V_40 -> V_159 ) ;
case V_179 :
V_40 -> V_113 -> V_159 +=
V_40 -> V_159 ;
case V_180 :
break;
}
}
if ( F_82 ( V_40 ) ) {
if ( V_40 -> V_113 -> V_181 & V_182 )
V_40 -> V_113 -> V_150 = - V_183 ;
if ( ! V_173 )
V_174 -> V_150 = V_177 ;
}
}
if ( V_40 -> V_28 )
F_21 ( V_3 , V_40 ) ;
if ( V_173 ) {
if ( ( V_40 -> V_150 == V_177 ) &&
( V_40 -> V_113 -> V_150 == - V_151 ) )
V_40 -> V_113 -> V_150 = - V_184 ;
V_175 = F_27 ( V_185 ,
V_186 ) ;
if ( F_85 ( ! V_175 ) )
break;
V_175 -> V_113 = V_40 -> V_113 ;
F_86 ( & V_175 -> V_172 , V_172 ) ;
}
F_87 ( & V_40 -> V_66 ) ;
F_80 ( V_40 ) ;
}
}
static void F_88 ( struct V_2 * V_3 , struct V_61 * V_63 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_20 ;
struct V_160 * V_161 ;
int V_187 , V_188 ;
int V_189 ;
struct V_22 V_22 ;
struct V_39 * V_40 ;
if ( F_85 ( F_30 ( & V_63 -> V_66 ) ) ) {
F_19 ( 1 ) ;
return;
}
if ( V_63 -> V_190 )
return;
if ( F_57 ( F_44 ( V_63 -> V_66 . V_114 , struct V_39 ,
V_66 ) -> V_113 -> V_122 ) ) {
V_20 = V_191 ;
V_161 = V_25 -> V_192 ;
} else {
V_20 = V_164 ;
V_161 = V_25 -> V_193 ;
}
V_188 = - 1 ;
for ( V_187 = 0 ; V_187 < 32 ; V_187 ++ ) {
if ( ( V_188 == - 1 ) && ( V_161 [ V_187 ] . V_40 == NULL ) )
V_188 = V_187 ;
if ( V_161 [ V_187 ] . V_63 == V_63 )
break;
}
V_189 = 0 ;
F_89 (qtd, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_150 == V_158 ) {
F_19 ( V_40 -> V_28 ) ;
F_20 ( V_3 , V_40 ) ;
if ( ( V_40 -> V_41 ) && ( ! V_40 -> V_28 ) )
break;
if ( ( V_40 -> V_41 ) &&
( ( V_40 -> V_124 == V_180 ) ||
( V_40 -> V_124 == V_179 ) ) ) {
F_12 ( V_3 -> V_50 , V_40 -> V_28 ,
V_40 -> V_140 , V_40 -> V_41 ) ;
}
V_40 -> V_150 = V_163 ;
}
if ( V_40 -> V_150 == V_163 ) {
if ( ( V_187 > 31 ) && ( V_188 > - 1 ) ) {
if ( F_57 ( V_40 -> V_113 -> V_122 ) )
F_69 ( V_63 , V_40 , & V_22 ) ;
else
F_46 ( V_63 , V_40 , & V_22 ) ;
F_81 ( V_3 , V_20 , V_188 ,
V_161 , V_40 , V_63 , & V_22 ) ;
V_187 = V_188 ;
}
V_189 ++ ;
if ( V_189 >= V_194 )
break;
}
}
}
void F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_25 ;
struct V_61 * V_63 , * V_195 ;
struct V_171 * V_196 ;
struct V_197 * V_198 ;
F_91 ( V_172 ) ;
struct V_175 * V_175 , * V_199 ;
if ( ! V_3 ) {
F_19 ( 1 ) ;
return;
}
V_25 = F_1 ( V_3 ) ;
V_196 = & V_25 -> V_69 ;
while ( V_196 ) {
F_84 (qh, qh_next, ep_queue, qh_list) {
V_198 = F_44 ( V_63 -> V_66 . V_114 , struct V_39 ,
V_66 ) -> V_113 -> V_198 ;
F_83 ( V_3 , V_63 , & V_172 ) ;
if ( F_30 ( & V_63 -> V_66 ) ) {
F_87 ( & V_63 -> V_65 ) ;
if ( V_198 -> V_200 == NULL ) {
F_29 ( V_63 ) ;
}
}
}
if ( V_196 == & V_25 -> V_69 )
V_196 = & V_25 -> V_70 ;
else if ( V_196 == & V_25 -> V_70 )
V_196 = & V_25 -> V_71 ;
else
V_196 = NULL ;
}
F_84 (urb_listitem, urb_listitem_next, &urb_list,
urb_list) {
F_70 ( V_3 , V_175 -> V_113 ) ;
F_31 ( V_185 , V_175 ) ;
}
V_196 = & V_25 -> V_70 ;
while ( V_196 ) {
F_84 (qh, qh_next, ep_queue, qh_list)
F_88 ( V_3 , V_63 ) ;
if ( V_196 == & V_25 -> V_70 )
V_196 = & V_25 -> V_69 ;
else if ( V_196 == & V_25 -> V_69 )
V_196 = & V_25 -> V_71 ;
else
V_196 = NULL ;
}
}
static int F_92 ( struct V_2 * V_3 , struct V_22 * V_22 ,
struct V_113 * V_113 )
{
T_7 V_148 ;
int V_26 ;
V_148 = V_22 -> V_148 ;
V_148 >>= 8 ;
if ( V_22 -> V_136 & V_201 ) {
V_113 -> V_150 = - V_202 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ ) {
switch ( V_148 & 0x7 ) {
case V_203 :
F_93 ( V_3 -> V_43 . V_44 , L_6
L_7 ,
V_45 , V_26 ) ;
V_113 -> V_150 = - V_204 ;
break;
case V_205 :
F_93 ( V_3 -> V_43 . V_44 , L_8
L_9 ,
V_45 , V_26 ) ;
V_113 -> V_150 = - V_202 ;
break;
case V_206 :
F_93 ( V_3 -> V_43 . V_44 , L_10
L_9 ,
V_45 , V_26 ) ;
V_113 -> V_150 = - V_207 ;
break;
}
V_148 >>= 3 ;
}
return V_208 ;
}
return V_209 ;
}
static int F_94 ( struct V_2 * V_3 , struct V_22 * V_22 ,
struct V_113 * V_113 )
{
F_19 ( ! V_22 ) ;
if ( V_22 -> V_136 & V_201 ) {
if ( V_22 -> V_136 & V_210 )
V_113 -> V_150 = - V_207 ;
else if ( F_95 ( V_22 -> V_136 ) )
V_113 -> V_150 = - V_184 ;
else if ( V_22 -> V_136 & V_211 )
V_113 -> V_150 = - V_202 ;
else
V_113 -> V_150 = - V_202 ;
return V_208 ;
}
if ( ( V_22 -> V_136 & V_211 ) && ( V_22 -> V_136 & V_142 ) ) {
F_93 ( V_3 -> V_43 . V_44 , L_11 ) ;
return V_212 ;
}
if ( ! F_96 ( V_22 -> V_136 ) && ( V_22 -> V_136 & V_142 ) ) {
return V_212 ;
}
return V_209 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_22 V_22 ;
struct V_61 * V_63 ;
int V_21 ;
int V_57 ;
struct V_160 * V_161 ;
T_1 V_20 ;
struct V_39 * V_40 ;
int V_213 ;
int V_162 ;
V_162 = F_2 ( V_3 -> V_50 , V_100 ) ;
V_25 -> V_167 &= ~ V_162 ;
V_162 = F_2 ( V_3 -> V_50 , V_98 ) ;
V_25 -> V_165 &= ~ V_162 ;
V_213 = V_25 -> V_167 || V_25 -> V_165 ;
while ( V_25 -> V_167 || V_25 -> V_165 ) {
if ( V_25 -> V_167 ) {
V_21 = F_98 ( V_25 -> V_167 ) ;
V_25 -> V_167 &= ~ ( 1 << V_21 ) ;
V_161 = V_25 -> V_192 ;
if ( ! V_161 [ V_21 ] . V_63 ) {
F_19 ( 1 ) ;
continue;
}
V_20 = V_191 ;
F_15 ( V_3 -> V_50 , V_191 , V_21 , & V_22 ) ;
V_57 = F_92 ( V_3 , & V_22 ,
V_161 [ V_21 ] . V_40 -> V_113 ) ;
} else {
V_21 = F_98 ( V_25 -> V_165 ) ;
V_25 -> V_165 &= ~ ( 1 << V_21 ) ;
V_161 = V_25 -> V_193 ;
if ( ! V_161 [ V_21 ] . V_63 ) {
F_19 ( 1 ) ;
continue;
}
V_20 = V_164 ;
F_15 ( V_3 -> V_50 , V_164 , V_21 , & V_22 ) ;
V_57 = F_94 ( V_3 , & V_22 ,
V_161 [ V_21 ] . V_40 -> V_113 ) ;
}
V_40 = V_161 [ V_21 ] . V_40 ;
V_161 [ V_21 ] . V_40 = NULL ;
V_63 = V_161 [ V_21 ] . V_63 ;
V_161 [ V_21 ] . V_63 = NULL ;
V_63 -> V_21 = - 1 ;
F_19 ( V_40 -> V_150 != V_169 ) ;
switch ( V_57 ) {
case V_209 :
if ( ( F_57 ( V_40 -> V_113 -> V_122 ) ) &&
( V_40 -> V_113 -> V_121 -> V_127 != V_128 ) )
V_40 -> V_159 =
F_99 ( V_22 . V_136 ) ;
else
V_40 -> V_159 =
F_100 ( V_22 . V_136 ) ;
V_40 -> V_150 = V_176 ;
if ( F_43 ( & V_40 -> V_66 , & V_63 -> V_66 ) ||
F_82 ( V_40 ) )
V_40 = NULL ;
else
V_40 = F_44 ( V_40 -> V_66 . V_114 ,
F_45 ( * V_40 ) , V_66 ) ;
V_63 -> V_139 = F_101 ( V_22 . V_136 ) ;
V_63 -> V_137 = F_102 ( V_22 . V_136 ) ;
break;
case V_212 :
V_40 -> V_150 = V_163 ;
V_22 . V_23 |= V_123 ;
V_22 . V_136 &= ~ F_65 ( 0xf ) ;
V_22 . V_136 |= F_65 ( F_103 ( V_22 . V_138 ) ) ;
V_22 . V_136 &= ~ F_67 ( 3 ) ;
V_22 . V_136 |= F_67 ( V_143 ) ;
V_63 -> V_139 = F_101 ( V_22 . V_136 ) ;
V_63 -> V_137 = F_102 ( V_22 . V_136 ) ;
break;
case V_208 :
V_40 -> V_150 = V_177 ;
if ( ( V_40 -> V_113 -> V_121 -> V_127 != V_128 ) &&
( V_40 -> V_113 -> V_150 != - V_184 ) &&
( V_40 -> V_113 -> V_150 != - V_183 ) ) {
V_63 -> V_190 = 1 ;
if ( F_104 ( V_40 -> V_113 ) )
V_63 -> V_190 = 0 ;
}
V_40 = NULL ;
V_63 -> V_139 = 0 ;
V_63 -> V_137 = 0 ;
break;
default:
F_19 ( 1 ) ;
continue;
}
if ( V_40 && ( V_40 -> V_150 == V_163 ) ) {
if ( V_161 == V_25 -> V_192 ) {
if ( V_57 == V_212 )
F_22 ( V_3 -> V_43 . V_44 ,
L_12
L_13 , V_45 ) ;
if ( V_57 != V_212 )
F_69 ( V_63 , V_40 , & V_22 ) ;
} else {
if ( V_57 != V_212 )
F_46 ( V_63 , V_40 , & V_22 ) ;
}
F_81 ( V_3 , V_20 , V_21 , V_161 , V_40 ,
V_63 , & V_22 ) ;
}
}
if ( V_213 )
F_90 ( V_3 ) ;
}
static T_8 F_105 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_214 ;
T_8 V_215 = V_216 ;
F_78 ( & V_25 -> V_68 ) ;
if ( ! ( V_3 -> V_57 & V_217 ) )
goto V_218;
V_214 = F_2 ( V_3 -> V_50 , V_219 ) ;
if ( F_85 ( ! V_214 ) )
goto V_218;
F_4 ( V_3 -> V_50 , V_219 , V_214 ) ;
V_25 -> V_167 |= F_2 ( V_3 -> V_50 , V_168 ) ;
V_25 -> V_165 |= F_2 ( V_3 -> V_50 , V_166 ) ;
F_97 ( V_3 ) ;
V_215 = V_220 ;
V_218:
F_76 ( & V_25 -> V_68 ) ;
return V_215 ;
}
void F_106 ( unsigned long V_221 )
{
struct V_2 * V_3 = (struct V_2 * ) V_221 ;
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_21 ;
struct V_22 V_22 ;
unsigned long V_222 ;
F_107 ( & V_25 -> V_68 , V_222 ) ;
for ( V_21 = 0 ; V_21 < 32 ; V_21 ++ )
if ( V_25 -> V_193 [ V_21 ] . V_63 && F_108 ( V_60 ,
V_25 -> V_193 [ V_21 ] . V_170 +
V_223 * V_224 / 1000 ) ) {
F_15 ( V_3 -> V_50 , V_164 , V_21 , & V_22 ) ;
if ( ! F_109 ( V_22 . V_23 ) &&
! F_110 ( V_22 . V_136 ) )
V_25 -> V_165 |= 1 << V_21 ;
}
if ( V_25 -> V_165 )
F_97 ( V_3 ) ;
F_111 ( & V_25 -> V_68 , V_222 ) ;
V_225 . V_226 = V_60 + V_227 * V_224 / 1000 ;
F_112 ( & V_225 ) ;
}
static int F_113 ( struct V_2 * V_3 )
{
int V_53 ;
T_1 V_228 ;
T_1 V_54 ;
T_1 V_229 ;
V_3 -> V_230 = 1 ;
V_3 -> V_57 = V_217 ;
F_4 ( V_3 -> V_50 , V_231 , 0 ) ;
F_4 ( V_3 -> V_50 , V_232 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_233 , 0 ) ;
F_4 ( V_3 -> V_50 , V_234 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_235 , 0 ) ;
F_4 ( V_3 -> V_50 , V_236 , 0xffffffff ) ;
V_228 = F_2 ( V_3 -> V_50 , V_94 ) ;
F_4 ( V_3 -> V_50 , V_94 , V_228 | V_237 ) ;
V_54 = F_2 ( V_3 -> V_50 , V_55 ) ;
V_54 &= ~ ( V_238 | V_56 ) ;
V_54 |= V_239 ;
F_4 ( V_3 -> V_50 , V_55 , V_54 ) ;
V_53 = F_23 ( V_3 , V_55 , V_239 , V_239 , 250 * 1000 ) ;
if ( V_53 )
return V_53 ;
F_114 ( & V_240 ) ;
F_4 ( V_3 -> V_50 , V_241 , V_242 ) ;
V_53 = F_23 ( V_3 , V_241 , V_242 , V_242 , 250 * 1000 ) ;
F_115 ( & V_240 ) ;
if ( V_53 )
return V_53 ;
F_116 ( & V_225 ) ;
V_225 . V_243 = F_106 ;
V_225 . V_221 = ( unsigned long ) V_3 ;
V_225 . V_226 = V_60 + V_227 * V_224 / 1000 ;
F_112 ( & V_225 ) ;
V_229 = F_2 ( V_3 -> V_50 , V_96 ) ;
F_40 ( V_3 -> V_43 . V_44 , L_14 ,
V_229 & 0xffff , V_229 >> 16 ) ;
F_4 ( V_3 -> V_50 , V_244 , 0x80000000 ) ;
F_4 ( V_3 -> V_50 , V_245 , 0x80000000 ) ;
F_4 ( V_3 -> V_50 , V_246 , 0x00000001 ) ;
F_4 ( V_3 -> V_50 , V_98 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_100 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_101 , 0xffffffff ) ;
F_4 ( V_3 -> V_50 , V_97 ,
V_247 | V_248 ) ;
return 0 ;
}
static int F_117 ( struct V_39 * V_40 , void * V_249 , T_9 V_250 )
{
V_40 -> V_140 = V_249 ;
if ( V_250 > V_251 )
V_250 = V_251 ;
V_40 -> V_41 = V_250 ;
return V_40 -> V_41 ;
}
static void F_118 ( struct V_171 * V_66 )
{
struct V_39 * V_40 , * V_174 ;
F_84 (qtd, qtd_next, qtd_list, qtd_list) {
F_87 ( & V_40 -> V_66 ) ;
F_80 ( V_40 ) ;
}
}
static void F_119 ( struct V_2 * V_3 ,
struct V_113 * V_113 , struct V_171 * V_252 , T_5 V_62 )
{
struct V_39 * V_40 ;
void * V_253 ;
int V_250 , V_254 ;
T_6 V_124 ;
if ( ! V_113 -> V_154 && V_113 -> V_155 ) {
F_22 ( V_3 -> V_43 . V_44 ,
L_15 ,
( long unsigned ) V_113 -> V_255 ,
V_113 -> V_155 ) ;
F_19 ( 1 ) ;
}
if ( F_71 ( V_113 -> V_122 ) )
V_124 = V_178 ;
else
V_124 = V_179 ;
if ( F_61 ( V_113 -> V_122 ) ) {
V_40 = F_79 ( V_62 , V_113 , V_180 ) ;
if ( ! V_40 )
goto V_256;
F_117 ( V_40 , V_113 -> V_141 , sizeof( struct V_257 ) ) ;
F_86 ( & V_40 -> V_66 , V_252 ) ;
if ( V_113 -> V_155 == 0 )
V_124 = V_178 ;
}
V_254 = F_120 ( F_47 ( V_113 -> V_121 , V_113 -> V_122 ,
F_48 ( V_113 -> V_122 ) ) ) ;
V_253 = V_113 -> V_154 ;
V_250 = V_113 -> V_155 ;
for (; ; ) {
int V_258 ;
V_40 = F_79 ( V_62 , V_113 , V_124 ) ;
if ( ! V_40 )
goto V_256;
V_258 = F_117 ( V_40 , V_253 , V_250 ) ;
F_86 ( & V_40 -> V_66 , V_252 ) ;
V_250 -= V_258 ;
V_253 += V_258 ;
if ( V_250 <= 0 )
break;
}
if ( V_113 -> V_155 != 0 ) {
int V_259 = 0 ;
if ( F_61 ( V_113 -> V_122 ) ) {
V_259 = 1 ;
if ( V_124 == V_178 )
V_124 = V_179 ;
else
V_124 = V_178 ;
} else if ( F_56 ( V_113 -> V_122 )
&& ( V_113 -> V_181 & V_260 )
&& ! ( V_113 -> V_155 %
V_254 ) ) {
V_259 = 1 ;
}
if ( V_259 ) {
V_40 = F_79 ( V_62 , V_113 , V_124 ) ;
if ( ! V_40 )
goto V_256;
F_117 ( V_40 , NULL , 0 ) ;
F_86 ( & V_40 -> V_66 , V_252 ) ;
}
}
return;
V_256:
F_118 ( V_252 ) ;
}
static int F_121 ( struct V_2 * V_3 , struct V_113 * V_113 ,
T_5 V_261 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_171 * V_196 ;
struct V_61 * V_63 , * V_262 ;
unsigned long V_222 ;
F_91 ( V_263 ) ;
int V_53 ;
int V_264 ;
switch ( F_72 ( V_113 -> V_122 ) ) {
case V_152 :
V_196 = & V_25 -> V_70 ;
break;
case V_265 :
V_196 = & V_25 -> V_71 ;
break;
case V_266 :
if ( V_113 -> V_146 < 0 )
return - V_267 ;
V_196 = & V_25 -> V_69 ;
break;
case V_268 :
F_22 ( V_3 -> V_43 . V_44 , L_16
L_17 ,
V_45 ) ;
return - V_184 ;
default:
F_22 ( V_3 -> V_43 . V_44 , L_18 ,
V_45 ) ;
return - V_184 ;
}
if ( F_71 ( V_113 -> V_122 ) )
V_113 -> V_159 = 0 ;
F_119 ( V_3 , V_113 , & V_263 , V_261 ) ;
if ( F_30 ( & V_263 ) )
return - V_269 ;
V_53 = 0 ;
F_107 ( & V_25 -> V_68 , V_222 ) ;
if ( ! F_122 ( V_270 , & V_3 -> V_62 ) ) {
V_53 = - V_271 ;
goto V_272;
}
V_53 = F_123 ( V_3 , V_113 ) ;
if ( V_53 )
goto V_272;
V_63 = V_113 -> V_198 -> V_200 ;
if ( V_63 ) {
V_264 = 0 ;
F_89 (qhit, ep_queue, qh_list) {
if ( V_262 == V_63 ) {
V_264 = 1 ;
break;
}
}
if ( ! V_264 )
F_86 ( & V_63 -> V_65 , V_196 ) ;
} else {
V_63 = F_26 ( V_186 ) ;
if ( ! V_63 ) {
V_53 = - V_269 ;
F_75 ( V_3 , V_113 ) ;
goto V_272;
}
F_86 ( & V_63 -> V_65 , V_196 ) ;
V_113 -> V_198 -> V_200 = V_63 ;
}
F_124 ( & V_263 , & V_63 -> V_66 ) ;
F_90 ( V_3 ) ;
V_272:
F_111 ( & V_25 -> V_68 , V_222 ) ;
return V_53 ;
}
static void F_125 ( struct V_2 * V_3 , struct V_113 * V_113 ,
struct V_61 * V_63 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_162 ;
F_19 ( V_63 -> V_21 == - 1 ) ;
if ( F_61 ( V_113 -> V_122 ) || F_56 ( V_113 -> V_122 ) ) {
V_162 = F_2 ( V_3 -> V_50 , V_98 ) ;
V_162 |= ( 1 << V_63 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_98 , V_162 ) ;
V_25 -> V_193 [ V_63 -> V_21 ] . V_63 = NULL ;
V_25 -> V_193 [ V_63 -> V_21 ] . V_40 = NULL ;
} else {
V_162 = F_2 ( V_3 -> V_50 , V_100 ) ;
V_162 |= ( 1 << V_63 -> V_21 ) ;
F_4 ( V_3 -> V_50 , V_100 , V_162 ) ;
V_25 -> V_192 [ V_63 -> V_21 ] . V_63 = NULL ;
V_25 -> V_192 [ V_63 -> V_21 ] . V_40 = NULL ;
}
V_63 -> V_21 = - 1 ;
}
static void F_126 ( struct V_2 * V_3 , struct V_61 * V_63 ,
struct V_39 * V_40 )
{
struct V_113 * V_113 ;
int V_273 ;
V_113 = V_40 -> V_113 ;
V_273 = 0 ;
F_127 (qtd, &qh->qtd_list, qtd_list) {
if ( V_40 -> V_113 != V_113 )
break;
if ( V_40 -> V_150 >= V_169 )
V_273 = 1 ;
if ( F_42 ( V_40 , V_63 ) &&
( V_40 -> V_150 >= V_176 ) )
V_273 = 0 ;
if ( V_40 -> V_150 == V_169 )
F_125 ( V_3 , V_113 , V_63 ) ;
V_40 -> V_150 = V_177 ;
}
if ( ( V_113 -> V_121 -> V_127 != V_128 ) && V_273 ) {
V_63 -> V_190 = 1 ;
if ( F_104 ( V_113 ) )
V_63 -> V_190 = 0 ;
}
}
static int F_128 ( struct V_2 * V_3 , struct V_113 * V_113 ,
int V_150 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned long V_222 ;
struct V_61 * V_63 ;
struct V_39 * V_40 ;
int V_53 = 0 ;
F_107 ( & V_25 -> V_68 , V_222 ) ;
V_53 = F_129 ( V_3 , V_113 , V_150 ) ;
if ( V_53 )
goto V_272;
V_63 = V_113 -> V_198 -> V_200 ;
if ( ! V_63 ) {
V_53 = - V_267 ;
goto V_272;
}
F_89 (qtd, &qh->qtd_list, qtd_list)
if ( V_40 -> V_113 == V_113 ) {
F_126 ( V_3 , V_63 , V_40 ) ;
break;
}
V_113 -> V_150 = V_150 ;
F_90 ( V_3 ) ;
V_272:
F_111 ( & V_25 -> V_68 , V_222 ) ;
return V_53 ;
}
static void F_130 ( struct V_2 * V_3 ,
struct V_197 * V_198 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
unsigned long V_222 ;
struct V_61 * V_63 ;
struct V_39 * V_40 ;
F_107 ( & V_25 -> V_68 , V_222 ) ;
V_63 = V_198 -> V_200 ;
if ( ! V_63 )
goto V_272;
F_89 (qtd, &qh->qtd_list, qtd_list)
if ( V_40 -> V_150 != V_177 ) {
F_126 ( V_3 , V_63 , V_40 ) ;
V_40 -> V_113 -> V_150 = - V_274 ;
}
V_198 -> V_200 = NULL ;
F_90 ( V_3 ) ;
V_272:
F_111 ( & V_25 -> V_68 , V_222 ) ;
}
static int F_131 ( struct V_2 * V_3 , char * V_253 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_228 , V_150 = 0 ;
T_1 V_46 ;
int V_53 = 1 ;
unsigned long V_62 ;
if ( ! F_132 ( V_3 -> V_57 ) )
return 0 ;
V_253 [ 0 ] = 0 ;
V_46 = V_275 ;
F_107 ( & V_25 -> V_68 , V_62 ) ;
V_228 = F_2 ( V_3 -> V_50 , V_276 ) ;
if ( V_228 & V_277 ) {
if ( V_228 & V_275 ) {
V_228 &= ~ V_275 ;
F_4 ( V_3 -> V_50 , V_276 , V_228 ) ;
goto V_47;
}
}
if ( ( V_228 & V_46 ) != 0
|| ( ( V_228 & V_278 ) != 0
&& F_133 ( V_60 ,
V_25 -> V_279 ) ) ) {
V_253 [ 0 ] |= 1 << ( 0 + 1 ) ;
V_150 = V_280 ;
}
V_47:
F_111 ( & V_25 -> V_68 , V_62 ) ;
return V_150 ? V_53 : 0 ;
}
static void F_134 ( struct V_1 * V_25 ,
struct V_281 * V_282 )
{
int V_283 = F_135 ( V_25 -> V_111 ) ;
T_10 V_228 ;
V_282 -> V_284 = 0x29 ;
V_282 -> V_285 = 10 ;
V_282 -> V_286 = 0 ;
V_282 -> V_287 = V_283 ;
V_228 = 1 + ( V_283 / 8 ) ;
V_282 -> V_288 = 7 + 2 * V_228 ;
memset ( & V_282 -> V_289 . V_290 . V_291 [ 0 ] , 0 , V_228 ) ;
memset ( & V_282 -> V_289 . V_290 . V_291 [ V_228 ] , 0xff , V_228 ) ;
V_228 = 0x0008 ;
if ( F_136 ( V_25 -> V_111 ) )
V_228 |= 0x0001 ;
else
V_228 |= 0x0002 ;
V_282 -> V_292 = F_137 ( V_228 ) ;
}
static int F_138 ( struct V_2 * V_3 , int V_293 ,
int V_294 )
{
if ( ! ( V_294 & V_295 ) )
return V_294 ;
if ( ! ( V_294 & V_296 ) ) {
F_40 ( V_3 -> V_43 . V_44 ,
L_19 ,
V_293 + 1 ) ;
V_294 |= V_277 ;
V_294 &= ~ V_297 ;
F_4 ( V_3 -> V_50 , V_276 , V_294 ) ;
} else
F_40 ( V_3 -> V_43 . V_44 , L_20 ,
V_293 + 1 ) ;
return V_294 ;
}
static int F_139 ( struct V_2 * V_3 , T_10 V_298 ,
T_10 V_299 , T_10 V_300 , char * V_253 , T_10 V_301 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
int V_283 = F_135 ( V_25 -> V_111 ) ;
T_1 V_228 , V_150 ;
unsigned long V_62 ;
int V_53 = 0 ;
unsigned V_302 ;
F_107 ( & V_25 -> V_68 , V_62 ) ;
switch ( V_298 ) {
case V_303 :
switch ( V_299 ) {
case V_304 :
case V_305 :
break;
default:
goto error;
}
break;
case V_306 :
if ( ! V_300 || V_300 > V_283 )
goto error;
V_300 -- ;
V_228 = F_2 ( V_3 -> V_50 , V_276 ) ;
switch ( V_299 ) {
case V_307 :
F_4 ( V_3 -> V_50 , V_276 , V_228 & ~ V_296 ) ;
break;
case V_308 :
break;
case V_309 :
if ( V_228 & V_310 )
goto error;
if ( V_228 & V_311 ) {
if ( ( V_228 & V_296 ) == 0 )
goto error;
V_228 &= ~ ( V_297 ) ;
F_4 ( V_3 -> V_50 , V_276 ,
V_228 | V_278 ) ;
V_25 -> V_279 = V_60 +
F_140 ( 20 ) ;
}
break;
case V_312 :
break;
case V_313 :
if ( F_136 ( V_25 -> V_111 ) )
F_4 ( V_3 -> V_50 , V_276 ,
V_228 & ~ V_314 ) ;
break;
case V_315 :
F_4 ( V_3 -> V_50 , V_276 , V_228 | V_275 ) ;
break;
case V_316 :
break;
case V_317 :
break;
default:
goto error;
}
F_2 ( V_3 -> V_50 , V_55 ) ;
break;
case V_318 :
F_134 ( V_25 , (struct V_281 * )
V_253 ) ;
break;
case V_319 :
memset ( V_253 , 0 , 4 ) ;
break;
case V_320 :
if ( ! V_300 || V_300 > V_283 )
goto error;
V_300 -- ;
V_150 = 0 ;
V_228 = F_2 ( V_3 -> V_50 , V_276 ) ;
if ( V_228 & V_275 )
V_150 |= V_321 << 16 ;
if ( V_228 & V_278 ) {
F_22 ( V_3 -> V_43 . V_44 , L_21 ) ;
if ( ! V_25 -> V_279 ) {
V_25 -> V_279 = V_60
+ F_140 ( 20 ) ;
F_141 ( & V_3 -> V_322 , V_25 -> V_279 ) ;
}
else if ( F_133 ( V_60 ,
V_25 -> V_279 ) ) {
V_150 |= V_323 << 16 ;
V_25 -> V_279 = 0 ;
V_228 = F_2 ( V_3 -> V_50 , V_276 ) ;
F_4 ( V_3 -> V_50 , V_276 ,
V_228 & ~ ( V_297 | V_278 ) ) ;
V_53 = F_23 ( V_3 , V_276 ,
V_278 , 0 , 2000 ) ;
if ( V_53 != 0 ) {
F_22 ( V_3 -> V_43 . V_44 ,
L_22 ,
V_300 + 1 , V_53 ) ;
goto error;
}
V_228 &= ~ ( V_311 | V_278 | ( 3 << 10 ) ) ;
}
}
if ( ( V_228 & V_310 )
&& F_133 ( V_60 ,
V_25 -> V_279 ) ) {
V_150 |= V_324 << 16 ;
V_25 -> V_279 = 0 ;
F_4 ( V_3 -> V_50 , V_276 , V_228 & ~ V_310 ) ;
V_53 = F_23 ( V_3 , V_276 ,
V_310 , 0 , 750 ) ;
if ( V_53 != 0 ) {
F_22 ( V_3 -> V_43 . V_44 , L_23 ,
V_300 + 1 , V_53 ) ;
goto error;
}
V_228 = F_138 ( V_3 , V_300 ,
F_2 ( V_3 -> V_50 , V_276 ) ) ;
}
if ( V_228 & V_277 )
F_22 ( V_3 -> V_43 . V_44 , L_24 ) ;
if ( V_228 & V_295 ) {
V_150 |= V_325 ;
V_150 |= V_326 ;
}
if ( V_228 & V_296 )
V_150 |= V_327 ;
if ( V_228 & ( V_311 | V_278 ) )
V_150 |= V_328 ;
if ( V_228 & V_310 )
V_150 |= V_329 ;
if ( V_228 & V_314 )
V_150 |= V_330 ;
F_142 ( F_14 ( V_150 ) , ( V_331 * ) V_253 ) ;
break;
case V_332 :
switch ( V_299 ) {
case V_304 :
case V_305 :
break;
default:
goto error;
}
break;
case V_333 :
V_302 = V_300 >> 8 ;
V_300 &= 0xff ;
if ( ! V_300 || V_300 > V_283 )
goto error;
V_300 -- ;
V_228 = F_2 ( V_3 -> V_50 , V_276 ) ;
if ( V_228 & V_277 )
break;
switch ( V_299 ) {
case V_307 :
F_4 ( V_3 -> V_50 , V_276 , V_228 | V_296 ) ;
break;
case V_309 :
if ( ( V_228 & V_296 ) == 0
|| ( V_228 & V_310 ) != 0 )
goto error;
F_4 ( V_3 -> V_50 , V_276 , V_228 | V_311 ) ;
break;
case V_313 :
if ( F_136 ( V_25 -> V_111 ) )
F_4 ( V_3 -> V_50 , V_276 ,
V_228 | V_314 ) ;
break;
case V_334 :
if ( V_228 & V_278 )
goto error;
if ( ( V_228 & ( V_296 | V_295 ) ) == V_295
&& F_143 ( V_228 ) ) {
V_228 |= V_277 ;
} else {
V_228 |= V_310 ;
V_228 &= ~ V_296 ;
V_25 -> V_279 = V_60 +
F_140 ( 50 ) ;
}
F_4 ( V_3 -> V_50 , V_276 , V_228 ) ;
break;
default:
goto error;
}
F_2 ( V_3 -> V_50 , V_55 ) ;
break;
default:
error:
V_53 = - V_184 ;
}
F_111 ( & V_25 -> V_68 , V_62 ) ;
return V_53 ;
}
static int F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_335 ;
V_335 = F_2 ( V_3 -> V_50 , V_336 ) ;
return ( V_335 >> 3 ) % V_25 -> V_72 ;
}
static void F_145 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
T_1 V_228 ;
F_146 ( & V_225 ) ;
F_139 ( V_3 , V_306 , V_313 , 1 ,
NULL , 0 ) ;
F_39 ( 20 ) ;
F_147 ( & V_25 -> V_68 ) ;
F_25 ( V_3 ) ;
V_228 = F_2 ( V_3 -> V_50 , V_94 ) ;
F_4 ( V_3 -> V_50 , V_94 , V_228 &= ~ V_237 ) ;
F_148 ( & V_25 -> V_68 ) ;
F_4 ( V_3 -> V_50 , V_241 , 0 ) ;
}
static void F_149 ( struct V_2 * V_3 )
{
T_1 V_54 , V_228 ;
F_145 ( V_3 ) ;
V_228 = F_2 ( V_3 -> V_50 , V_94 ) ;
F_4 ( V_3 -> V_50 , V_94 , V_228 &= ~ V_237 ) ;
V_54 = F_2 ( V_3 -> V_50 , V_55 ) ;
V_54 &= ~ V_239 ;
F_4 ( V_3 -> V_50 , V_55 , V_54 ) ;
}
static void F_150 ( struct V_2 * V_3 ,
struct V_197 * V_198 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
struct V_61 * V_63 = V_198 -> V_200 ;
unsigned long V_222 ;
if ( ! V_63 )
return;
F_107 ( & V_25 -> V_68 , V_222 ) ;
V_63 -> V_190 = 0 ;
F_90 ( V_3 ) ;
F_111 ( & V_25 -> V_68 , V_222 ) ;
}
int T_11 F_151 ( void )
{
V_185 = F_152 ( L_25 ,
sizeof( struct V_175 ) , 0 , V_337 |
V_338 , NULL ) ;
if ( ! V_185 )
return - V_269 ;
V_157 = F_152 ( L_26 ,
sizeof( struct V_39 ) , 0 , V_337 |
V_338 , NULL ) ;
if ( ! V_157 )
return - V_269 ;
V_64 = F_152 ( L_27 , sizeof( struct V_61 ) ,
0 , V_337 | V_338 , NULL ) ;
if ( ! V_64 ) {
F_153 ( V_157 ) ;
return - V_269 ;
}
return 0 ;
}
void F_154 ( void )
{
F_153 ( V_157 ) ;
F_153 ( V_64 ) ;
F_153 ( V_185 ) ;
}
struct V_2 * F_155 ( T_12 V_339 , T_13 V_340 ,
int V_341 , unsigned long V_342 ,
int V_78 ,
struct V_343 * V_121 , const char * V_344 ,
unsigned int V_80 )
{
struct V_2 * V_3 ;
struct V_1 * V_25 ;
int V_345 ;
if ( F_156 () )
return F_157 ( - V_51 ) ;
V_121 -> V_346 = NULL ;
V_3 = F_158 ( & V_347 , V_121 , F_159 ( V_121 ) ) ;
if ( ! V_3 )
return F_157 ( - V_269 ) ;
V_25 = F_1 ( V_3 ) ;
V_25 -> V_80 = V_80 ;
V_25 -> V_78 = V_78 ;
F_18 ( V_25 ) ;
V_3 -> V_50 = F_160 ( V_339 , V_340 ) ;
if ( ! V_3 -> V_50 ) {
V_345 = - V_348 ;
goto V_349;
}
V_3 -> V_341 = V_341 ;
V_3 -> V_350 = V_339 ;
V_3 -> V_351 = V_340 ;
V_345 = F_161 ( V_3 , V_341 , V_342 ) ;
if ( V_345 )
goto V_352;
return V_3 ;
V_352:
F_162 ( V_3 -> V_50 ) ;
V_349:
F_163 ( V_3 ) ;
return F_157 ( V_345 ) ;
}
