static int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_4 , int V_5 )
{
int V_6 = - V_7 ;
T_2 V_8 = 0 ;
switch ( V_5 ) {
case 1 :
{
T_3 V_9 ;
V_6 = F_2 ( V_2 , V_3 , & V_9 ) ;
V_8 = V_9 ;
break;
}
case 2 :
{
T_4 V_9 ;
V_6 = F_3 ( V_2 , V_3 , & V_9 ) ;
V_8 = V_9 ;
break;
}
case 4 :
V_6 = F_4 ( V_2 , V_3 , & V_8 ) ;
break;
}
* V_4 = F_5 ( V_8 ) ;
return F_6 ( V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , int V_5 )
{
int V_6 = - V_7 ;
T_2 V_8 = F_8 ( V_4 ) ;
switch ( V_5 ) {
case 1 :
V_6 = F_9 ( V_2 , V_3 , V_8 ) ;
break;
case 2 :
V_6 = F_10 ( V_2 , V_3 , V_8 ) ;
break;
case 4 :
V_6 = F_11 ( V_2 , V_3 , V_8 ) ;
break;
}
return F_6 ( V_6 ) ;
}
static int F_12 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
T_1 V_15 = 0 ;
memcpy ( V_4 , V_11 -> V_16 + V_12 , V_5 ) ;
memcpy ( & V_15 , V_14 -> V_15 + V_3 , V_5 ) ;
if ( F_5 ( ~ 0U >> ( 32 - ( V_5 * 8 ) ) ) != V_15 ) {
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_17 = 0 ;
int V_6 ;
V_6 = F_1 ( V_2 , V_12 , & V_17 , V_5 ) ;
if ( V_6 )
return V_6 ;
* V_4 = ( V_17 & ~ V_15 ) | ( * V_4 & V_15 ) ;
}
return V_5 ;
}
static int F_13 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
T_1 V_15 = 0 , V_18 = 0 ;
memcpy ( & V_18 , V_14 -> V_18 + V_3 , V_5 ) ;
if ( ! V_18 )
return V_5 ;
memcpy ( & V_15 , V_14 -> V_15 + V_3 , V_5 ) ;
if ( V_18 & V_15 ) {
T_1 V_19 = 0 ;
memcpy ( & V_19 , V_11 -> V_16 + V_12 , V_5 ) ;
V_19 &= ~ ( V_18 & V_15 ) ;
V_19 |= ( V_4 & ( V_18 & V_15 ) ) ;
memcpy ( V_11 -> V_16 + V_12 , & V_19 , V_5 ) ;
}
if ( V_18 & ~ V_15 ) {
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_17 = 0 ;
int V_6 ;
V_6 = F_1 ( V_2 , V_12 , & V_17 , V_5 ) ;
if ( V_6 )
return V_6 ;
V_17 &= ~ ( V_18 & ~ V_15 ) ;
V_17 |= ( V_4 & ( V_18 & ~ V_15 ) ) ;
V_6 = F_7 ( V_2 , V_12 , V_17 , V_5 ) ;
if ( V_6 )
return V_6 ;
}
return V_5 ;
}
static int F_14 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
int V_6 ;
V_6 = F_1 ( V_11 -> V_2 , V_12 , V_4 , V_5 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_12 >= V_20 ) {
if ( V_3 < 4 )
memcpy ( V_4 , V_11 -> V_16 + V_12 , V_5 ) ;
} else if ( V_12 >= V_21 ) {
if ( V_3 == V_22 && V_5 > 1 )
memcpy ( V_4 , V_11 -> V_16 + V_12 ,
F_15 ( V_23 , V_5 ) ) ;
else if ( V_3 == V_24 )
memcpy ( V_4 , V_11 -> V_16 + V_12 , 1 ) ;
}
return V_5 ;
}
static int F_16 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
int V_6 ;
V_6 = F_7 ( V_11 -> V_2 , V_12 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
return V_5 ;
}
static void F_17 ( struct V_13 * V_14 )
{
F_18 ( V_14 -> V_15 ) ;
F_18 ( V_14 -> V_18 ) ;
V_14 -> V_15 = NULL ;
V_14 -> V_18 = NULL ;
}
static int F_19 ( struct V_13 * V_14 , int V_25 )
{
V_25 = F_20 ( V_25 , 4 ) ;
V_14 -> V_15 = F_21 ( V_25 , V_26 ) ;
V_14 -> V_18 = F_21 ( V_25 , V_26 ) ;
if ( ! V_14 -> V_15 || ! V_14 -> V_18 ) {
F_17 ( V_14 ) ;
return - V_27 ;
}
V_14 -> V_28 = F_12 ;
V_14 -> V_29 = F_13 ;
return 0 ;
}
static inline void F_22 ( struct V_13 * V_30 , int V_31 , T_3 V_15 , T_3 V_18 )
{
V_30 -> V_15 [ V_31 ] = V_15 ;
V_30 -> V_18 [ V_31 ] = V_18 ;
}
static inline void F_23 ( struct V_13 * V_30 , int V_31 , T_4 V_15 , T_4 V_18 )
{
* ( V_32 * ) ( & V_30 -> V_15 [ V_31 ] ) = F_24 ( V_15 ) ;
* ( V_32 * ) ( & V_30 -> V_18 [ V_31 ] ) = F_24 ( V_18 ) ;
}
static inline void F_25 ( struct V_13 * V_30 , int V_31 , T_2 V_15 , T_2 V_18 )
{
* ( T_1 * ) ( & V_30 -> V_15 [ V_31 ] ) = F_5 ( V_15 ) ;
* ( T_1 * ) ( & V_30 -> V_18 [ V_31 ] ) = F_5 ( V_18 ) ;
}
static void F_26 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 * V_33 = V_11 -> V_33 ;
int V_34 ;
if ( V_2 -> V_35 )
return;
F_27 ( L_1 ,
V_36 , F_28 ( & V_2 -> V_37 ) ) ;
for ( V_34 = V_38 ; V_34 <= V_39 ; V_34 += 4 , V_33 ++ )
F_11 ( V_2 , V_34 , * V_33 ) ;
F_11 ( V_2 , V_40 , * V_33 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 , int V_41 )
{
unsigned long V_42 = F_30 ( V_2 , V_41 ) ;
T_2 V_4 ;
if ( V_42 & V_43 )
return F_5 ( V_44 ) ;
V_4 = V_45 ;
if ( V_42 & V_46 )
V_4 |= V_47 ;
if ( V_42 & V_48 )
V_4 |= V_49 ;
return F_5 ( V_4 ) ;
}
static void F_31 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_34 ;
T_1 * V_41 ;
T_5 V_50 ;
V_41 = ( T_1 * ) & V_11 -> V_16 [ V_38 ] ;
for ( V_34 = V_51 ; V_34 <= V_52 ; V_34 ++ , V_41 ++ ) {
if ( ! F_32 ( V_2 , V_34 ) ) {
* V_41 = 0 ;
continue;
}
V_50 = ~ ( F_33 ( V_2 , V_34 ) - 1 ) ;
* V_41 &= F_5 ( ( T_2 ) V_50 ) ;
* V_41 |= F_29 ( V_2 , V_34 ) ;
if ( * V_41 & F_5 ( V_49 ) ) {
V_41 ++ ;
* V_41 &= F_5 ( ( T_2 ) ( V_50 >> 32 ) ) ;
V_34 ++ ;
}
}
V_41 = ( T_1 * ) & V_11 -> V_16 [ V_40 ] ;
if ( F_32 ( V_2 , V_53 ) ) {
V_50 = ~ ( F_33 ( V_2 , V_53 ) - 1 ) ;
V_50 |= V_54 ;
* V_41 &= F_5 ( ( T_2 ) V_50 ) ;
} else
* V_41 = 0 ;
V_11 -> V_55 = false ;
}
static int F_34 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( F_35 ( V_3 ) )
F_31 ( V_11 ) ;
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_3 == V_56 && V_11 -> V_2 -> V_35 ) {
T_4 V_57 = F_36 ( * ( V_32 * ) & V_11 -> V_16 [ V_56 ] ) ;
T_2 V_8 = F_8 ( * V_4 ) ;
V_8 |= V_57 & V_58 ;
* V_4 = F_5 ( V_8 ) ;
}
return V_5 ;
}
static int F_37 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_32 * V_59 ;
T_4 V_60 = 0 ;
int V_6 ;
V_59 = ( V_32 * ) & V_11 -> V_16 [ V_56 ] ;
if ( V_3 == V_56 ) {
bool V_61 , V_62 , V_63 , V_64 , V_65 , V_66 ;
T_4 V_67 ;
V_6 = F_3 ( V_2 , V_56 , & V_67 ) ;
if ( V_6 )
return V_6 ;
V_60 = F_8 ( V_4 ) ;
V_61 = ! ! ( V_67 & V_58 ) ;
V_62 = ! ! ( F_36 ( * V_59 ) & V_58 ) ;
V_63 = ! ! ( V_60 & V_58 ) ;
V_64 = ! ! ( V_67 & V_68 ) ;
V_65 = ! ! ( F_36 ( * V_59 ) & V_68 ) ;
V_66 = ! ! ( V_60 & V_68 ) ;
if ( ( V_63 && V_62 && ! V_61 ) ||
( V_66 && V_65 && ! V_64 ) )
F_26 ( V_11 ) ;
}
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 == V_56 ) {
T_4 V_50 = V_58 | V_68 ;
* V_59 &= F_24 ( ~ V_50 ) ;
* V_59 |= F_24 ( V_60 & V_50 ) ;
}
if ( V_3 >= V_56 && V_3 <= V_56 + 1 ) {
bool V_69 ;
V_69 = ! ! ( F_36 ( * V_59 ) &
V_70 ) ;
if ( V_69 && ! V_11 -> V_71 ) {
V_11 -> V_71 = true ;
F_38 ( V_11 ) ;
} else if ( ! V_69 && V_11 -> V_71 ) {
V_11 -> V_71 = false ;
F_39 ( V_11 ) ;
}
}
if ( F_35 ( V_3 ) )
V_11 -> V_55 = true ;
return V_5 ;
}
static int T_6 F_40 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_21 ) )
return - V_27 ;
V_14 -> V_28 = F_34 ;
V_14 -> V_29 = F_37 ;
F_23 ( V_14 , V_72 , ( T_4 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_75 , ( T_4 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_56 , V_70 , ( T_4 ) V_76 ) ;
F_23 ( V_14 , V_77 , V_78 , V_74 ) ;
F_22 ( V_14 , V_79 , V_80 , ( T_3 ) V_76 ) ;
F_22 ( V_14 , V_81 , V_80 , ( T_3 ) V_76 ) ;
F_22 ( V_14 , V_82 , V_80 , ( T_3 ) V_76 ) ;
F_25 ( V_14 , V_38 , V_73 , V_76 ) ;
F_25 ( V_14 , V_83 , V_73 , V_76 ) ;
F_25 ( V_14 , V_84 , V_73 , V_76 ) ;
F_25 ( V_14 , V_85 , V_73 , V_76 ) ;
F_25 ( V_14 , V_86 , V_73 , V_76 ) ;
F_25 ( V_14 , V_39 , V_73 , V_76 ) ;
F_25 ( V_14 , V_40 , V_73 , V_76 ) ;
F_22 ( V_14 , V_87 , ( T_3 ) V_73 , V_74 ) ;
F_22 ( V_14 , V_88 , ( T_3 ) V_73 , ( T_3 ) V_76 ) ;
return 0 ;
}
static int T_6 F_41 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_89 [ V_90 ] ) )
return - V_27 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_25 ( V_14 , V_91 , V_80 , V_76 ) ;
return 0 ;
}
static int T_6 F_42 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_92 ) )
return - V_27 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_93 , V_80 , ( T_4 ) V_76 ) ;
F_25 ( V_14 , V_94 , V_80 , V_76 ) ;
return 0 ;
}
static int T_6 F_43 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_95 ) )
return - V_27 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_96 , V_80 , ~ V_97 ) ;
F_23 ( V_14 , V_98 , V_80 , ~ V_99 ) ;
return 0 ;
}
static int T_6 F_44 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_89 [ V_100 ] ) )
return - V_27 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_22 ( V_14 , V_101 , V_80 , V_102 ) ;
return 0 ;
}
static int T_6 F_45 ( struct V_13 * V_14 )
{
T_2 V_50 ;
if ( F_19 ( V_14 , V_103 [ V_104 ] ) )
return - V_27 ;
F_25 ( V_14 , 0 , V_73 , V_74 ) ;
V_50 = V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 ;
F_25 ( V_14 , V_122 , V_80 , V_50 ) ;
F_25 ( V_14 , V_123 , V_80 , V_50 ) ;
F_25 ( V_14 , V_124 , V_80 , V_50 ) ;
V_50 = V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 ;
F_25 ( V_14 , V_133 , V_80 , V_50 ) ;
F_25 ( V_14 , V_134 , V_80 , V_50 ) ;
V_50 = V_135 |
V_136 ;
F_25 ( V_14 , V_137 , V_80 , V_50 ) ;
return 0 ;
}
static int T_6 F_46 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_103 [ V_138 ] ) )
return - V_27 ;
F_25 ( V_14 , 0 , V_73 , V_74 ) ;
F_22 ( V_14 , V_139 , V_80 , ( T_3 ) V_76 ) ;
return 0 ;
}
void F_47 ( void )
{
F_17 ( & V_140 [ V_141 ] ) ;
F_17 ( & V_140 [ V_90 ] ) ;
F_17 ( & V_140 [ V_142 ] ) ;
F_17 ( & V_140 [ V_143 ] ) ;
F_17 ( & V_140 [ V_100 ] ) ;
F_17 ( & V_144 [ V_104 ] ) ;
F_17 ( & V_144 [ V_138 ] ) ;
}
int T_6 F_48 ( void )
{
int V_6 ;
V_6 = F_40 ( & V_140 [ V_141 ] ) ;
V_6 |= F_41 ( & V_140 [ V_90 ] ) ;
V_140 [ V_145 ] . V_29 = F_16 ;
V_6 |= F_42 ( & V_140 [ V_142 ] ) ;
V_140 [ V_146 ] . V_29 = F_16 ;
V_6 |= F_43 ( & V_140 [ V_143 ] ) ;
V_6 |= F_44 ( & V_140 [ V_100 ] ) ;
V_6 |= F_45 ( & V_144 [ V_104 ] ) ;
V_6 |= F_46 ( & V_144 [ V_138 ] ) ;
V_144 [ V_147 ] . V_29 = F_16 ;
if ( V_6 )
F_47 () ;
return V_6 ;
}
static int F_49 ( struct V_10 * V_11 , int V_12 )
{
T_3 V_148 ;
int V_149 = ( V_12 >= V_20 ) ? V_20 :
V_21 ;
V_149 /= 4 ;
V_12 /= 4 ;
V_148 = V_11 -> V_150 [ V_12 ] ;
if ( V_148 == V_141 )
return 0 ;
while ( V_12 - 1 >= V_149 && V_11 -> V_150 [ V_12 - 1 ] == V_148 )
V_12 -- ;
return V_12 * 4 ;
}
static int F_50 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( V_3 <= V_151 && V_3 + V_5 >= V_151 ) {
V_32 * V_42 ;
int V_152 ;
V_152 = F_49 ( V_11 , V_12 ) ;
V_42 = ( V_32 * ) & V_11 -> V_16 [ V_152 ] ;
* V_42 &= F_24 ( ~ V_153 ) ;
* V_42 |= F_24 ( V_11 -> V_154 << 1 ) ;
}
return F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
}
static int F_51 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 <= V_151 && V_3 + V_5 >= V_151 ) {
V_32 * V_155 ;
T_4 V_42 ;
int V_152 , V_6 ;
V_152 = F_49 ( V_11 , V_12 ) ;
V_155 = ( V_32 * ) & V_11 -> V_16 [ V_152 + V_151 ] ;
V_42 = F_36 ( * V_155 ) ;
if ( ! F_52 ( V_11 ) )
V_42 &= ~ V_156 ;
if ( ( V_42 & V_157 ) >> 4 > V_11 -> V_154 ) {
V_42 &= ~ V_157 ;
V_42 |= V_11 -> V_154 << 4 ;
}
* V_155 = F_24 ( V_42 ) ;
V_6 = F_10 ( V_11 -> V_2 ,
V_152 + V_151 ,
V_42 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
}
return V_5 ;
}
static int F_53 ( struct V_13 * V_14 , int V_158 , T_4 V_42 )
{
if ( F_19 ( V_14 , V_158 ) )
return - V_27 ;
V_14 -> V_28 = F_50 ;
V_14 -> V_29 = F_51 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_22 ( V_14 , V_151 , ( T_3 ) V_73 , ( T_3 ) V_76 ) ;
F_25 ( V_14 , V_159 , V_73 , V_76 ) ;
if ( V_42 & V_160 ) {
F_25 ( V_14 , V_161 , V_73 , V_76 ) ;
F_23 ( V_14 , V_162 , ( T_4 ) V_73 , ( T_4 ) V_76 ) ;
if ( V_42 & V_163 ) {
F_25 ( V_14 , V_164 , V_80 , V_76 ) ;
F_25 ( V_14 , V_165 , V_80 , V_76 ) ;
}
} else {
F_23 ( V_14 , V_166 , ( T_4 ) V_73 , ( T_4 ) V_76 ) ;
if ( V_42 & V_163 ) {
F_25 ( V_14 , V_167 , V_80 , V_76 ) ;
F_25 ( V_14 , V_168 , V_80 , V_76 ) ;
}
}
return 0 ;
}
static int F_54 ( struct V_10 * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_158 , V_6 ;
T_4 V_42 ;
V_6 = F_55 ( V_2 , V_12 + V_151 , & V_42 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_158 = 10 ;
if ( V_42 & V_160 )
V_158 += 4 ;
if ( V_42 & V_163 )
V_158 += 10 ;
if ( V_11 -> V_169 )
return V_158 ;
V_11 -> V_169 = F_56 ( sizeof( struct V_13 ) , V_26 ) ;
if ( ! V_11 -> V_169 )
return - V_27 ;
V_6 = F_53 ( V_11 -> V_169 , V_158 , V_42 ) ;
if ( V_6 )
return V_6 ;
return V_158 ;
}
static int F_57 ( struct V_10 * V_11 , T_4 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_9 ;
int V_6 , V_170 , V_171 , V_172 ;
int V_158 = V_173 ;
V_6 = F_58 ( V_2 , V_12 + V_174 , & V_9 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_170 = V_9 & V_175 ;
V_6 = F_58 ( V_2 , V_12 + V_176 , & V_9 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_9 & V_177 )
V_171 = 128 ;
else if ( V_9 & V_178 )
V_171 = 64 ;
else if ( V_9 & V_179 )
V_171 = 32 ;
else
V_171 = 0 ;
V_172 = V_171 * 4 ;
V_158 += ( 1 + V_170 ) * V_180 ;
if ( V_172 ) {
V_158 = F_20 ( V_158 , 16 ) ;
V_158 += V_172 / 8 ;
}
return V_158 ;
}
static int F_59 ( struct V_10 * V_11 , T_3 V_148 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_4 V_181 ;
T_3 V_182 ;
int V_6 ;
switch ( V_148 ) {
case V_183 :
return F_54 ( V_11 , V_12 ) ;
case V_142 :
V_6 = F_55 ( V_2 , V_12 + V_93 , & V_181 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( F_60 ( V_181 ) ) {
V_11 -> V_184 = true ;
return V_92 ;
} else
return V_185 ;
case V_146 :
V_6 = F_61 ( V_2 , V_12 + V_23 , & V_182 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_182 ;
case V_143 :
V_6 = F_55 ( V_2 , V_12 + V_186 , & V_181 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( ( V_181 & V_187 ) == 1 )
return V_188 ;
else {
V_11 -> V_184 = true ;
return V_95 ;
}
case V_189 :
V_6 = F_61 ( V_2 , V_12 + 3 , & V_182 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return ( V_182 & V_190 ) ?
V_191 : V_192 ;
case V_193 :
V_6 = F_61 ( V_2 , V_12 + V_194 , & V_182 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_182 &= V_195 ;
if ( V_182 == V_196 )
return V_197 ;
else
return V_198 ;
default:
F_62 ( L_2 ,
F_28 ( & V_2 -> V_37 ) , V_36 , V_148 , V_12 ) ;
}
return 0 ;
}
static int F_63 ( struct V_10 * V_11 , T_4 V_199 , T_4 V_200 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_182 ;
T_2 V_201 ;
int V_6 ;
switch ( V_199 ) {
case V_147 :
V_6 = F_58 ( V_2 , V_200 + V_202 , & V_201 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_201 >> V_203 ;
case V_204 :
case V_205 :
case V_206 :
return F_57 ( V_11 , V_200 ) ;
case V_207 :
V_6 = F_61 ( V_2 , V_200 + V_208 , & V_182 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_182 & V_209 ) {
int V_210 ;
V_6 = F_61 ( V_2 ,
V_200 + V_211 ,
& V_182 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_210 = V_182 ? F_20 ( V_182 , 32 ) : 256 ;
return 8 + ( V_210 / 8 ) ;
}
return 8 ;
case V_212 :
V_6 = F_61 ( V_2 , V_200 + V_213 , & V_182 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_182 &= V_214 ;
V_182 >>= V_215 ;
return 4 + ( V_182 * 8 ) ;
case V_216 :
V_6 = F_61 ( V_2 , V_200 + V_217 , & V_182 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_182 &= V_218 ;
V_182 = F_20 ( V_182 + 1 , 4 ) ;
return V_219 + V_182 ;
case V_220 :
V_6 = F_58 ( V_2 , V_200 + V_221 , & V_201 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( ( V_201 & V_222 ) == V_223 ) {
int V_224 ;
V_224 = V_182 & V_225 ;
V_224 >>= V_226 ;
return V_227 + F_20 ( V_224 * 2 , 4 ) ;
}
return V_227 ;
default:
F_62 ( L_3 ,
F_28 ( & V_2 -> V_37 ) , V_36 , V_199 , V_200 ) ;
}
return 0 ;
}
static int F_64 ( struct V_10 * V_11 ,
int V_3 , int V_25 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_6 = 0 ;
while ( V_25 ) {
int V_228 ;
if ( V_25 >= 4 && ! ( V_3 % 4 ) ) {
T_1 * V_229 = ( T_1 * ) & V_11 -> V_16 [ V_3 ] ;
T_2 V_201 ;
V_6 = F_58 ( V_2 , V_3 , & V_201 ) ;
if ( V_6 )
return V_6 ;
* V_229 = F_5 ( V_201 ) ;
V_228 = 4 ;
} else if ( V_25 >= 2 && ! ( V_3 % 2 ) ) {
V_32 * V_230 = ( V_32 * ) & V_11 -> V_16 [ V_3 ] ;
T_4 V_181 ;
V_6 = F_55 ( V_2 , V_3 , & V_181 ) ;
if ( V_6 )
return V_6 ;
* V_230 = F_24 ( V_181 ) ;
V_228 = 2 ;
} else {
T_3 * V_182 = & V_11 -> V_16 [ V_3 ] ;
V_6 = F_61 ( V_2 , V_3 , V_182 ) ;
if ( V_6 )
return V_6 ;
V_228 = 1 ;
}
V_3 += V_228 ;
V_25 -= V_228 ;
}
return V_6 ;
}
static int F_65 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_231 = V_11 -> V_150 ;
T_4 V_232 ;
T_3 V_12 , * V_233 , V_148 ;
int V_234 , V_6 , V_235 = 0 ;
V_6 = F_55 ( V_2 , V_77 , & V_232 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_232 & V_78 ) )
return 0 ;
V_6 = F_61 ( V_2 , V_87 , & V_12 ) ;
if ( V_6 )
return V_6 ;
V_233 = & V_11 -> V_16 [ V_87 ] ;
V_234 = ( V_20 - V_21 ) / V_236 ;
while ( V_12 && V_234 -- ) {
T_3 V_237 ;
int V_34 , V_158 = 0 ;
V_6 = F_61 ( V_2 , V_12 , & V_148 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_61 ( V_2 ,
V_12 + V_24 , & V_237 ) ;
if ( V_6 )
return V_6 ;
if ( V_148 <= V_238 ) {
V_158 = V_89 [ V_148 ] ;
if ( V_158 == 0xFF ) {
V_158 = F_59 ( V_11 , V_148 , V_12 ) ;
if ( V_158 < 0 )
return V_158 ;
}
}
if ( ! V_158 ) {
F_27 ( L_4 ,
V_36 , F_28 ( & V_2 -> V_37 ) , V_148 ) ;
* V_233 = V_237 ;
V_12 = V_237 ;
continue;
}
for ( V_34 = 0 ; V_34 < V_158 ; V_34 += 4 ) {
if ( F_66 ( V_231 [ ( V_12 + V_34 ) / 4 ] == V_239 ) )
continue;
F_62 ( L_5 ,
V_36 , F_28 ( & V_2 -> V_37 ) ,
V_12 + V_34 , V_231 [ V_12 + V_34 ] , V_148 ) ;
}
memset ( V_231 + ( V_12 / 4 ) , V_148 , V_158 / 4 ) ;
V_6 = F_64 ( V_11 , V_12 , V_158 ) ;
if ( V_6 )
return V_6 ;
V_233 = & V_11 -> V_16 [ V_12 + V_24 ] ;
V_12 = V_237 ;
V_235 ++ ;
}
if ( ! V_235 ) {
V_32 * V_240 = ( V_32 * ) & V_11 -> V_16 [ V_77 ] ;
* V_240 &= ~ F_24 ( V_78 ) ;
}
return 0 ;
}
static int F_67 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_231 = V_11 -> V_150 ;
T_4 V_200 ;
T_1 * V_233 = NULL ;
int V_234 , V_6 , V_241 = 0 ;
if ( ! V_11 -> V_184 )
return 0 ;
V_200 = V_20 ;
V_234 = ( V_2 -> V_242 - V_20 ) / V_236 ;
while ( V_234 -- && V_200 >= V_20 ) {
T_2 V_243 ;
T_4 V_199 ;
int V_34 , V_158 = 0 ;
bool V_244 = false ;
V_6 = F_58 ( V_2 , V_200 , & V_243 ) ;
if ( V_6 )
return V_6 ;
V_199 = F_68 ( V_243 ) ;
if ( V_199 <= V_245 ) {
V_158 = V_103 [ V_199 ] ;
if ( V_158 == 0xFF ) {
V_158 = F_63 ( V_11 , V_199 , V_200 ) ;
if ( V_158 < 0 )
return V_6 ;
}
}
if ( ! V_158 ) {
F_27 ( L_6 ,
V_36 , F_28 ( & V_2 -> V_37 ) , V_199 , V_200 ) ;
if ( V_233 ) {
T_2 V_4 = V_200 = F_69 ( V_243 ) ;
* V_233 &= F_5 ( ~ ( 0xffcU << 20 ) ) ;
* V_233 |= F_5 ( V_4 << 20 ) ;
continue;
}
V_158 = V_236 ;
V_244 = true ;
}
for ( V_34 = 0 ; V_34 < V_158 ; V_34 += 4 ) {
if ( F_66 ( V_231 [ ( V_200 + V_34 ) / 4 ] == V_239 ) )
continue;
F_62 ( L_7 ,
V_36 , F_28 ( & V_2 -> V_37 ) ,
V_200 + V_34 , V_231 [ V_200 + V_34 ] , V_199 ) ;
}
F_70 ( V_245 >= V_239 ) ;
memset ( V_231 + ( V_200 / 4 ) , V_199 , V_158 / 4 ) ;
V_6 = F_64 ( V_11 , V_200 , V_158 ) ;
if ( V_6 )
return V_6 ;
if ( V_244 )
* ( T_1 * ) & V_11 -> V_16 [ V_200 ] &=
F_5 ( ( 0xffcU << 20 ) ) ;
else
V_241 ++ ;
V_233 = ( T_1 * ) & V_11 -> V_16 [ V_200 ] ;
V_200 = F_69 ( V_243 ) ;
}
if ( ! V_241 )
* ( T_2 * ) & V_11 -> V_16 [ V_20 ] = 0 ;
return 0 ;
}
int F_71 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_231 , * V_16 ;
int V_6 ;
V_231 = F_56 ( V_2 -> V_242 / 4 , V_26 ) ;
if ( ! V_231 )
return - V_27 ;
V_16 = F_56 ( V_2 -> V_242 , V_26 ) ;
if ( ! V_16 ) {
F_18 ( V_231 ) ;
return - V_27 ;
}
V_11 -> V_150 = V_231 ;
V_11 -> V_16 = V_16 ;
memset ( V_231 , V_141 , V_21 / 4 ) ;
memset ( V_231 + ( V_21 / 4 ) , V_239 ,
( V_2 -> V_242 - V_21 ) / 4 ) ;
V_6 = F_64 ( V_11 , 0 , V_21 ) ;
if ( V_6 )
goto V_246;
V_11 -> V_55 = true ;
V_11 -> V_33 [ 0 ] = F_8 ( * ( T_1 * ) & V_16 [ V_38 ] ) ;
V_11 -> V_33 [ 1 ] = F_8 ( * ( T_1 * ) & V_16 [ V_83 ] ) ;
V_11 -> V_33 [ 2 ] = F_8 ( * ( T_1 * ) & V_16 [ V_84 ] ) ;
V_11 -> V_33 [ 3 ] = F_8 ( * ( T_1 * ) & V_16 [ V_85 ] ) ;
V_11 -> V_33 [ 4 ] = F_8 ( * ( T_1 * ) & V_16 [ V_86 ] ) ;
V_11 -> V_33 [ 5 ] = F_8 ( * ( T_1 * ) & V_16 [ V_39 ] ) ;
V_11 -> V_33 [ 6 ] = F_8 ( * ( T_1 * ) & V_16 [ V_40 ] ) ;
if ( V_2 -> V_35 ) {
* ( V_32 * ) & V_16 [ V_72 ] = F_24 ( V_2 -> V_247 ) ;
* ( V_32 * ) & V_16 [ V_75 ] = F_24 ( V_2 -> V_248 ) ;
}
V_6 = F_65 ( V_11 ) ;
if ( V_6 )
goto V_246;
V_6 = F_67 ( V_11 ) ;
if ( V_6 )
goto V_246;
return 0 ;
V_246:
F_18 ( V_231 ) ;
V_11 -> V_150 = NULL ;
F_18 ( V_16 ) ;
V_11 -> V_16 = NULL ;
return F_6 ( V_6 ) ;
}
void F_72 ( struct V_10 * V_11 )
{
F_18 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
F_18 ( V_11 -> V_150 ) ;
V_11 -> V_150 = NULL ;
F_18 ( V_11 -> V_169 ) ;
V_11 -> V_169 = NULL ;
}
static T_7 F_73 ( struct V_10 * V_11 , char T_8 * V_249 ,
T_9 V_5 , T_10 * V_250 , bool V_251 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_13 * V_14 ;
T_1 V_4 = 0 ;
int V_252 = 0 , V_3 ;
T_3 V_253 ;
T_7 V_6 = V_5 ;
if ( * V_250 < 0 || * V_250 + V_5 > V_2 -> V_242 )
return - V_254 ;
if ( V_5 > sizeof( V_4 ) )
return - V_7 ;
V_253 = V_11 -> V_150 [ * V_250 / 4 ] ;
if ( V_253 == V_239 ) {
if ( V_251 )
return V_6 ;
if ( F_74 ( V_249 , & V_4 , V_5 ) )
return - V_254 ;
return V_6 ;
}
if ( * V_250 >= V_20 ) {
F_75 ( V_253 > V_245 ) ;
V_14 = & V_144 [ V_253 ] ;
V_252 = F_49 ( V_11 , * V_250 ) ;
} else {
F_75 ( V_253 > V_238 ) ;
V_14 = & V_140 [ V_253 ] ;
if ( V_253 == V_183 )
V_14 = V_11 -> V_169 ;
if ( V_253 > V_141 )
V_252 = F_49 ( V_11 , * V_250 ) ;
}
F_75 ( ! V_252 && V_253 != V_141 ) ;
F_75 ( V_252 > * V_250 ) ;
V_3 = * V_250 - V_252 ;
if ( V_251 ) {
if ( ! V_14 -> V_29 )
return V_6 ;
if ( F_76 ( & V_4 , V_249 , V_5 ) )
return - V_254 ;
V_6 = V_14 -> V_29 ( V_11 , * V_250 , V_5 , V_14 , V_3 , V_4 ) ;
} else {
if ( V_14 -> V_28 ) {
V_6 = V_14 -> V_28 ( V_11 , * V_250 , V_5 ,
V_14 , V_3 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( F_74 ( V_249 , & V_4 , V_5 ) )
return - V_254 ;
}
return V_6 ;
}
T_7 F_77 ( struct V_10 * V_11 ,
char T_8 * V_249 , T_9 V_5 ,
T_10 * V_250 , bool V_251 )
{
T_9 V_255 = 0 ;
int V_6 = 0 ;
T_10 V_12 = * V_250 ;
V_12 &= V_256 ;
while ( V_5 ) {
if ( V_5 >= 4 && ! ( V_12 % 4 ) )
V_6 = F_73 ( V_11 , V_249 , 4 , & V_12 , V_251 ) ;
else if ( V_5 >= 2 && ! ( V_12 % 2 ) )
V_6 = F_73 ( V_11 , V_249 , 2 , & V_12 , V_251 ) ;
else
V_6 = F_73 ( V_11 , V_249 , 1 , & V_12 , V_251 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -= V_6 ;
V_255 += V_6 ;
V_249 += V_6 ;
V_12 += V_6 ;
}
* V_250 += V_255 ;
return V_255 ;
}
