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
static int F_41 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 == V_89 ) {
T_7 V_90 ;
switch ( F_8 ( V_4 ) & V_91 ) {
case 0 :
V_90 = V_92 ;
break;
case 1 :
V_90 = V_93 ;
break;
case 2 :
V_90 = V_94 ;
break;
case 3 :
V_90 = V_95 ;
break;
}
F_42 ( V_11 -> V_2 , V_90 ) ;
}
return V_5 ;
}
static int T_6 F_43 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_96 [ V_97 ] ) )
return - V_27 ;
V_14 -> V_29 = F_41 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_25 ( V_14 , V_89 , V_80 , ~ V_91 ) ;
return 0 ;
}
static int T_6 F_44 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_98 ) )
return - V_27 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_99 , V_80 , ( T_4 ) V_76 ) ;
F_25 ( V_14 , V_100 , V_80 , V_76 ) ;
return 0 ;
}
static int T_6 F_45 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_101 ) )
return - V_27 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_102 , V_80 , ~ V_103 ) ;
F_23 ( V_14 , V_104 , V_80 , ~ V_105 ) ;
return 0 ;
}
static int T_6 F_46 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_96 [ V_106 ] ) )
return - V_27 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_22 ( V_14 , V_107 , V_80 , V_108 ) ;
return 0 ;
}
static int T_6 F_47 ( struct V_13 * V_14 )
{
T_2 V_50 ;
if ( F_19 ( V_14 , V_109 [ V_110 ] ) )
return - V_27 ;
F_25 ( V_14 , 0 , V_73 , V_74 ) ;
V_50 = V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 ;
F_25 ( V_14 , V_128 , V_80 , V_50 ) ;
F_25 ( V_14 , V_129 , V_80 , V_50 ) ;
F_25 ( V_14 , V_130 , V_80 , V_50 ) ;
V_50 = V_131 |
V_132 |
V_133 |
V_134 |
V_135 |
V_136 |
V_137 |
V_138 ;
F_25 ( V_14 , V_139 , V_80 , V_50 ) ;
F_25 ( V_14 , V_140 , V_80 , V_50 ) ;
V_50 = V_141 |
V_142 ;
F_25 ( V_14 , V_143 , V_80 , V_50 ) ;
return 0 ;
}
static int T_6 F_48 ( struct V_13 * V_14 )
{
if ( F_19 ( V_14 , V_109 [ V_144 ] ) )
return - V_27 ;
F_25 ( V_14 , 0 , V_73 , V_74 ) ;
F_22 ( V_14 , V_145 , V_80 , ( T_3 ) V_76 ) ;
return 0 ;
}
void F_49 ( void )
{
F_17 ( & V_146 [ V_147 ] ) ;
F_17 ( & V_146 [ V_97 ] ) ;
F_17 ( & V_146 [ V_148 ] ) ;
F_17 ( & V_146 [ V_149 ] ) ;
F_17 ( & V_146 [ V_106 ] ) ;
F_17 ( & V_150 [ V_110 ] ) ;
F_17 ( & V_150 [ V_144 ] ) ;
}
int T_6 F_50 ( void )
{
int V_6 ;
V_6 = F_40 ( & V_146 [ V_147 ] ) ;
V_6 |= F_43 ( & V_146 [ V_97 ] ) ;
V_146 [ V_151 ] . V_29 = F_16 ;
V_6 |= F_44 ( & V_146 [ V_148 ] ) ;
V_146 [ V_152 ] . V_29 = F_16 ;
V_6 |= F_45 ( & V_146 [ V_149 ] ) ;
V_6 |= F_46 ( & V_146 [ V_106 ] ) ;
V_6 |= F_47 ( & V_150 [ V_110 ] ) ;
V_6 |= F_48 ( & V_150 [ V_144 ] ) ;
V_150 [ V_153 ] . V_29 = F_16 ;
if ( V_6 )
F_49 () ;
return V_6 ;
}
static int F_51 ( struct V_10 * V_11 , int V_12 )
{
T_3 V_154 ;
int V_155 = ( V_12 >= V_20 ) ? V_20 :
V_21 ;
V_155 /= 4 ;
V_12 /= 4 ;
V_154 = V_11 -> V_156 [ V_12 ] ;
if ( V_154 == V_147 )
return 0 ;
while ( V_12 - 1 >= V_155 && V_11 -> V_156 [ V_12 - 1 ] == V_154 )
V_12 -- ;
return V_12 * 4 ;
}
static int F_52 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( V_3 <= V_157 && V_3 + V_5 >= V_157 ) {
V_32 * V_42 ;
int V_158 ;
V_158 = F_51 ( V_11 , V_12 ) ;
V_42 = ( V_32 * ) & V_11 -> V_16 [ V_158 ] ;
* V_42 &= F_24 ( ~ V_159 ) ;
* V_42 |= F_24 ( V_11 -> V_160 << 1 ) ;
}
return F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
}
static int F_53 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 <= V_157 && V_3 + V_5 >= V_157 ) {
V_32 * V_161 ;
T_4 V_42 ;
int V_158 , V_6 ;
V_158 = F_51 ( V_11 , V_12 ) ;
V_161 = ( V_32 * ) & V_11 -> V_16 [ V_158 + V_157 ] ;
V_42 = F_36 ( * V_161 ) ;
if ( ! F_54 ( V_11 ) )
V_42 &= ~ V_162 ;
if ( ( V_42 & V_163 ) >> 4 > V_11 -> V_160 ) {
V_42 &= ~ V_163 ;
V_42 |= V_11 -> V_160 << 4 ;
}
* V_161 = F_24 ( V_42 ) ;
V_6 = F_10 ( V_11 -> V_2 ,
V_158 + V_157 ,
V_42 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
}
return V_5 ;
}
static int F_55 ( struct V_13 * V_14 , int V_164 , T_4 V_42 )
{
if ( F_19 ( V_14 , V_164 ) )
return - V_27 ;
V_14 -> V_28 = F_52 ;
V_14 -> V_29 = F_53 ;
F_22 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_22 ( V_14 , V_157 , ( T_3 ) V_73 , ( T_3 ) V_76 ) ;
F_25 ( V_14 , V_165 , V_73 , V_76 ) ;
if ( V_42 & V_166 ) {
F_25 ( V_14 , V_167 , V_73 , V_76 ) ;
F_23 ( V_14 , V_168 , ( T_4 ) V_73 , ( T_4 ) V_76 ) ;
if ( V_42 & V_169 ) {
F_25 ( V_14 , V_170 , V_80 , V_76 ) ;
F_25 ( V_14 , V_171 , V_80 , V_76 ) ;
}
} else {
F_23 ( V_14 , V_172 , ( T_4 ) V_73 , ( T_4 ) V_76 ) ;
if ( V_42 & V_169 ) {
F_25 ( V_14 , V_173 , V_80 , V_76 ) ;
F_25 ( V_14 , V_174 , V_80 , V_76 ) ;
}
}
return 0 ;
}
static int F_56 ( struct V_10 * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_164 , V_6 ;
T_4 V_42 ;
V_6 = F_57 ( V_2 , V_12 + V_157 , & V_42 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_164 = 10 ;
if ( V_42 & V_166 )
V_164 += 4 ;
if ( V_42 & V_169 )
V_164 += 10 ;
if ( V_11 -> V_175 )
return V_164 ;
V_11 -> V_175 = F_58 ( sizeof( struct V_13 ) , V_26 ) ;
if ( ! V_11 -> V_175 )
return - V_27 ;
V_6 = F_55 ( V_11 -> V_175 , V_164 , V_42 ) ;
if ( V_6 )
return V_6 ;
return V_164 ;
}
static int F_59 ( struct V_10 * V_11 , T_4 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_9 ;
int V_6 , V_176 , V_177 , V_178 ;
int V_164 = V_179 ;
V_6 = F_60 ( V_2 , V_12 + V_180 , & V_9 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_176 = V_9 & V_181 ;
V_6 = F_60 ( V_2 , V_12 + V_182 , & V_9 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_9 & V_183 )
V_177 = 128 ;
else if ( V_9 & V_184 )
V_177 = 64 ;
else if ( V_9 & V_185 )
V_177 = 32 ;
else
V_177 = 0 ;
V_178 = V_177 * 4 ;
V_164 += ( 1 + V_176 ) * V_186 ;
if ( V_178 ) {
V_164 = F_20 ( V_164 , 16 ) ;
V_164 += V_178 / 8 ;
}
return V_164 ;
}
static int F_61 ( struct V_10 * V_11 , T_3 V_154 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_4 V_187 ;
T_3 V_188 ;
int V_6 ;
switch ( V_154 ) {
case V_189 :
return F_56 ( V_11 , V_12 ) ;
case V_148 :
V_6 = F_57 ( V_2 , V_12 + V_99 , & V_187 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( F_62 ( V_187 ) ) {
V_11 -> V_190 = true ;
return V_98 ;
} else
return V_191 ;
case V_152 :
V_6 = F_63 ( V_2 , V_12 + V_23 , & V_188 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_188 ;
case V_149 :
V_6 = F_57 ( V_2 , V_12 + V_192 , & V_187 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_11 -> V_190 = true ;
if ( ( V_187 & V_193 ) == 1 )
return V_194 ;
else
return V_101 ;
case V_195 :
V_6 = F_63 ( V_2 , V_12 + 3 , & V_188 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return ( V_188 & V_196 ) ?
V_197 : V_198 ;
case V_199 :
V_6 = F_63 ( V_2 , V_12 + V_200 , & V_188 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_188 &= V_201 ;
if ( V_188 == V_202 )
return V_203 ;
else
return V_204 ;
default:
F_64 ( L_2 ,
F_28 ( & V_2 -> V_37 ) , V_36 , V_154 , V_12 ) ;
}
return 0 ;
}
static int F_65 ( struct V_10 * V_11 , T_4 V_205 , T_4 V_206 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_188 ;
T_2 V_207 ;
int V_6 ;
switch ( V_205 ) {
case V_153 :
V_6 = F_60 ( V_2 , V_206 + V_208 , & V_207 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_207 >> V_209 ;
case V_210 :
case V_211 :
case V_212 :
return F_59 ( V_11 , V_206 ) ;
case V_213 :
V_6 = F_63 ( V_2 , V_206 + V_214 , & V_188 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_188 & V_215 ) {
int V_216 ;
V_6 = F_63 ( V_2 ,
V_206 + V_217 ,
& V_188 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_216 = V_188 ? F_20 ( V_188 , 32 ) : 256 ;
return 8 + ( V_216 / 8 ) ;
}
return 8 ;
case V_218 :
V_6 = F_63 ( V_2 , V_206 + V_219 , & V_188 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_188 &= V_220 ;
V_188 >>= V_221 ;
return 4 + ( V_188 * 8 ) ;
case V_222 :
V_6 = F_63 ( V_2 , V_206 + V_223 , & V_188 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_188 &= V_224 ;
V_188 = F_20 ( V_188 + 1 , 4 ) ;
return V_225 + V_188 ;
case V_226 :
V_6 = F_60 ( V_2 , V_206 + V_227 , & V_207 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( ( V_207 & V_228 ) == V_229 ) {
int V_230 ;
V_230 = V_188 & V_231 ;
V_230 >>= V_232 ;
return V_233 + F_20 ( V_230 * 2 , 4 ) ;
}
return V_233 ;
default:
F_64 ( L_3 ,
F_28 ( & V_2 -> V_37 ) , V_36 , V_205 , V_206 ) ;
}
return 0 ;
}
static int F_66 ( struct V_10 * V_11 ,
int V_3 , int V_25 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_6 = 0 ;
while ( V_25 ) {
int V_234 ;
if ( V_25 >= 4 && ! ( V_3 % 4 ) ) {
T_1 * V_235 = ( T_1 * ) & V_11 -> V_16 [ V_3 ] ;
T_2 V_207 ;
V_6 = F_60 ( V_2 , V_3 , & V_207 ) ;
if ( V_6 )
return V_6 ;
* V_235 = F_5 ( V_207 ) ;
V_234 = 4 ;
} else if ( V_25 >= 2 && ! ( V_3 % 2 ) ) {
V_32 * V_236 = ( V_32 * ) & V_11 -> V_16 [ V_3 ] ;
T_4 V_187 ;
V_6 = F_57 ( V_2 , V_3 , & V_187 ) ;
if ( V_6 )
return V_6 ;
* V_236 = F_24 ( V_187 ) ;
V_234 = 2 ;
} else {
T_3 * V_188 = & V_11 -> V_16 [ V_3 ] ;
V_6 = F_63 ( V_2 , V_3 , V_188 ) ;
if ( V_6 )
return V_6 ;
V_234 = 1 ;
}
V_3 += V_234 ;
V_25 -= V_234 ;
}
return V_6 ;
}
static int F_67 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_237 = V_11 -> V_156 ;
T_4 V_238 ;
T_3 V_12 , * V_239 , V_154 ;
int V_240 , V_6 , V_241 = 0 ;
V_6 = F_57 ( V_2 , V_77 , & V_238 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_238 & V_78 ) )
return 0 ;
V_6 = F_63 ( V_2 , V_87 , & V_12 ) ;
if ( V_6 )
return V_6 ;
V_239 = & V_11 -> V_16 [ V_87 ] ;
V_240 = ( V_20 - V_21 ) / V_242 ;
while ( V_12 && V_240 -- ) {
T_3 V_243 ;
int V_34 , V_164 = 0 ;
V_6 = F_63 ( V_2 , V_12 , & V_154 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_63 ( V_2 ,
V_12 + V_24 , & V_243 ) ;
if ( V_6 )
return V_6 ;
if ( V_154 <= V_244 ) {
V_164 = V_96 [ V_154 ] ;
if ( V_164 == 0xFF ) {
V_164 = F_61 ( V_11 , V_154 , V_12 ) ;
if ( V_164 < 0 )
return V_164 ;
}
}
if ( ! V_164 ) {
F_27 ( L_4 ,
V_36 , F_28 ( & V_2 -> V_37 ) , V_154 ) ;
* V_239 = V_243 ;
V_12 = V_243 ;
continue;
}
for ( V_34 = 0 ; V_34 < V_164 ; V_34 += 4 ) {
if ( F_68 ( V_237 [ ( V_12 + V_34 ) / 4 ] == V_245 ) )
continue;
F_64 ( L_5 ,
V_36 , F_28 ( & V_2 -> V_37 ) ,
V_12 + V_34 , V_237 [ V_12 + V_34 ] , V_154 ) ;
}
memset ( V_237 + ( V_12 / 4 ) , V_154 , V_164 / 4 ) ;
V_6 = F_66 ( V_11 , V_12 , V_164 ) ;
if ( V_6 )
return V_6 ;
V_239 = & V_11 -> V_16 [ V_12 + V_24 ] ;
V_12 = V_243 ;
V_241 ++ ;
}
if ( ! V_241 ) {
V_32 * V_246 = ( V_32 * ) & V_11 -> V_16 [ V_77 ] ;
* V_246 &= ~ F_24 ( V_78 ) ;
}
return 0 ;
}
static int F_69 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_237 = V_11 -> V_156 ;
T_4 V_206 ;
T_1 * V_239 = NULL ;
int V_240 , V_6 , V_247 = 0 ;
if ( ! V_11 -> V_190 )
return 0 ;
V_206 = V_20 ;
V_240 = ( V_2 -> V_248 - V_20 ) / V_242 ;
while ( V_240 -- && V_206 >= V_20 ) {
T_2 V_249 ;
T_4 V_205 ;
int V_34 , V_164 = 0 ;
bool V_250 = false ;
V_6 = F_60 ( V_2 , V_206 , & V_249 ) ;
if ( V_6 )
return V_6 ;
V_205 = F_70 ( V_249 ) ;
if ( V_205 <= V_251 ) {
V_164 = V_109 [ V_205 ] ;
if ( V_164 == 0xFF ) {
V_164 = F_65 ( V_11 , V_205 , V_206 ) ;
if ( V_164 < 0 )
return V_6 ;
}
}
if ( ! V_164 ) {
F_27 ( L_6 ,
V_36 , F_28 ( & V_2 -> V_37 ) , V_205 , V_206 ) ;
if ( V_239 ) {
T_2 V_4 = V_206 = F_71 ( V_249 ) ;
* V_239 &= F_5 ( ~ ( 0xffcU << 20 ) ) ;
* V_239 |= F_5 ( V_4 << 20 ) ;
continue;
}
V_164 = V_242 ;
V_250 = true ;
}
for ( V_34 = 0 ; V_34 < V_164 ; V_34 += 4 ) {
if ( F_68 ( V_237 [ ( V_206 + V_34 ) / 4 ] == V_245 ) )
continue;
F_64 ( L_7 ,
V_36 , F_28 ( & V_2 -> V_37 ) ,
V_206 + V_34 , V_237 [ V_206 + V_34 ] , V_205 ) ;
}
F_72 ( V_251 >= V_245 ) ;
memset ( V_237 + ( V_206 / 4 ) , V_205 , V_164 / 4 ) ;
V_6 = F_66 ( V_11 , V_206 , V_164 ) ;
if ( V_6 )
return V_6 ;
if ( V_250 )
* ( T_1 * ) & V_11 -> V_16 [ V_206 ] &=
F_5 ( ( 0xffcU << 20 ) ) ;
else
V_247 ++ ;
V_239 = ( T_1 * ) & V_11 -> V_16 [ V_206 ] ;
V_206 = F_71 ( V_249 ) ;
}
if ( ! V_247 )
* ( T_2 * ) & V_11 -> V_16 [ V_20 ] = 0 ;
return 0 ;
}
int F_73 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_237 , * V_16 ;
int V_6 ;
V_237 = F_58 ( V_2 -> V_248 / 4 , V_26 ) ;
if ( ! V_237 )
return - V_27 ;
V_16 = F_58 ( V_2 -> V_248 , V_26 ) ;
if ( ! V_16 ) {
F_18 ( V_237 ) ;
return - V_27 ;
}
V_11 -> V_156 = V_237 ;
V_11 -> V_16 = V_16 ;
memset ( V_237 , V_147 , V_21 / 4 ) ;
memset ( V_237 + ( V_21 / 4 ) , V_245 ,
( V_2 -> V_248 - V_21 ) / 4 ) ;
V_6 = F_66 ( V_11 , 0 , V_21 ) ;
if ( V_6 )
goto V_252;
V_11 -> V_55 = true ;
V_11 -> V_33 [ 0 ] = F_8 ( * ( T_1 * ) & V_16 [ V_38 ] ) ;
V_11 -> V_33 [ 1 ] = F_8 ( * ( T_1 * ) & V_16 [ V_83 ] ) ;
V_11 -> V_33 [ 2 ] = F_8 ( * ( T_1 * ) & V_16 [ V_84 ] ) ;
V_11 -> V_33 [ 3 ] = F_8 ( * ( T_1 * ) & V_16 [ V_85 ] ) ;
V_11 -> V_33 [ 4 ] = F_8 ( * ( T_1 * ) & V_16 [ V_86 ] ) ;
V_11 -> V_33 [ 5 ] = F_8 ( * ( T_1 * ) & V_16 [ V_39 ] ) ;
V_11 -> V_33 [ 6 ] = F_8 ( * ( T_1 * ) & V_16 [ V_40 ] ) ;
if ( V_2 -> V_35 ) {
* ( V_32 * ) & V_16 [ V_72 ] = F_24 ( V_2 -> V_253 ) ;
* ( V_32 * ) & V_16 [ V_75 ] = F_24 ( V_2 -> V_254 ) ;
}
V_6 = F_67 ( V_11 ) ;
if ( V_6 )
goto V_252;
V_6 = F_69 ( V_11 ) ;
if ( V_6 )
goto V_252;
return 0 ;
V_252:
F_18 ( V_237 ) ;
V_11 -> V_156 = NULL ;
F_18 ( V_16 ) ;
V_11 -> V_16 = NULL ;
return F_6 ( V_6 ) ;
}
void F_74 ( struct V_10 * V_11 )
{
F_18 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
F_18 ( V_11 -> V_156 ) ;
V_11 -> V_156 = NULL ;
F_18 ( V_11 -> V_175 ) ;
V_11 -> V_175 = NULL ;
}
static T_8 F_75 ( struct V_10 * V_11 , char T_9 * V_255 ,
T_10 V_5 , T_11 * V_256 , bool V_257 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_13 * V_14 ;
T_1 V_4 = 0 ;
int V_258 = 0 , V_3 ;
T_3 V_259 ;
T_8 V_6 = V_5 ;
if ( * V_256 < 0 || * V_256 + V_5 > V_2 -> V_248 )
return - V_260 ;
if ( V_5 > sizeof( V_4 ) )
return - V_7 ;
V_259 = V_11 -> V_156 [ * V_256 / 4 ] ;
if ( V_259 == V_245 ) {
if ( V_257 )
return V_6 ;
if ( F_76 ( V_255 , & V_4 , V_5 ) )
return - V_260 ;
return V_6 ;
}
if ( * V_256 >= V_20 ) {
F_77 ( V_259 > V_251 ) ;
V_14 = & V_150 [ V_259 ] ;
V_258 = F_51 ( V_11 , * V_256 ) ;
} else {
F_77 ( V_259 > V_244 ) ;
V_14 = & V_146 [ V_259 ] ;
if ( V_259 == V_189 )
V_14 = V_11 -> V_175 ;
if ( V_259 > V_147 )
V_258 = F_51 ( V_11 , * V_256 ) ;
}
F_77 ( ! V_258 && V_259 != V_147 ) ;
F_77 ( V_258 > * V_256 ) ;
V_3 = * V_256 - V_258 ;
if ( V_257 ) {
if ( ! V_14 -> V_29 )
return V_6 ;
if ( F_78 ( & V_4 , V_255 , V_5 ) )
return - V_260 ;
V_6 = V_14 -> V_29 ( V_11 , * V_256 , V_5 , V_14 , V_3 , V_4 ) ;
} else {
if ( V_14 -> V_28 ) {
V_6 = V_14 -> V_28 ( V_11 , * V_256 , V_5 ,
V_14 , V_3 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( F_76 ( V_255 , & V_4 , V_5 ) )
return - V_260 ;
}
return V_6 ;
}
T_8 F_79 ( struct V_10 * V_11 , char T_9 * V_255 ,
T_10 V_5 , T_11 * V_256 , bool V_257 )
{
T_10 V_261 = 0 ;
int V_6 = 0 ;
T_11 V_12 = * V_256 ;
V_12 &= V_262 ;
while ( V_5 ) {
if ( V_5 >= 4 && ! ( V_12 % 4 ) )
V_6 = F_75 ( V_11 , V_255 , 4 , & V_12 , V_257 ) ;
else if ( V_5 >= 2 && ! ( V_12 % 2 ) )
V_6 = F_75 ( V_11 , V_255 , 2 , & V_12 , V_257 ) ;
else
V_6 = F_75 ( V_11 , V_255 , 1 , & V_12 , V_257 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -= V_6 ;
V_261 += V_6 ;
V_255 += V_6 ;
V_12 += V_6 ;
}
* V_256 += V_261 ;
return V_261 ;
}
