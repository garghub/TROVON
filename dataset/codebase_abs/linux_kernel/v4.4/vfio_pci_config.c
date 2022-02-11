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
static int F_17 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
int V_6 ;
V_6 = F_1 ( V_11 -> V_2 , V_12 , V_4 , V_5 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_5 ;
}
static void F_18 ( struct V_13 * V_14 )
{
F_19 ( V_14 -> V_15 ) ;
F_19 ( V_14 -> V_18 ) ;
V_14 -> V_15 = NULL ;
V_14 -> V_18 = NULL ;
}
static int F_20 ( struct V_13 * V_14 , int V_25 )
{
V_25 = F_21 ( V_25 , 4 ) ;
V_14 -> V_15 = F_22 ( V_25 , V_26 ) ;
V_14 -> V_18 = F_22 ( V_25 , V_26 ) ;
if ( ! V_14 -> V_15 || ! V_14 -> V_18 ) {
F_18 ( V_14 ) ;
return - V_27 ;
}
V_14 -> V_28 = F_12 ;
V_14 -> V_29 = F_13 ;
return 0 ;
}
static inline void F_23 ( struct V_13 * V_30 , int V_31 , T_3 V_15 , T_3 V_18 )
{
V_30 -> V_15 [ V_31 ] = V_15 ;
V_30 -> V_18 [ V_31 ] = V_18 ;
}
static inline void F_24 ( struct V_13 * V_30 , int V_31 , T_4 V_15 , T_4 V_18 )
{
* ( V_32 * ) ( & V_30 -> V_15 [ V_31 ] ) = F_25 ( V_15 ) ;
* ( V_32 * ) ( & V_30 -> V_18 [ V_31 ] ) = F_25 ( V_18 ) ;
}
static inline void F_26 ( struct V_13 * V_30 , int V_31 , T_2 V_15 , T_2 V_18 )
{
* ( T_1 * ) ( & V_30 -> V_15 [ V_31 ] ) = F_5 ( V_15 ) ;
* ( T_1 * ) ( & V_30 -> V_18 [ V_31 ] ) = F_5 ( V_18 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 * V_33 = V_11 -> V_33 ;
int V_34 ;
if ( V_2 -> V_35 )
return;
F_28 ( L_1 ,
V_36 , F_29 ( & V_2 -> V_37 ) ) ;
for ( V_34 = V_38 ; V_34 <= V_39 ; V_34 += 4 , V_33 ++ )
F_11 ( V_2 , V_34 , * V_33 ) ;
F_11 ( V_2 , V_40 , * V_33 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 , int V_41 )
{
unsigned long V_42 = F_31 ( V_2 , V_41 ) ;
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
static void F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_34 ;
T_1 * V_41 ;
T_5 V_50 ;
V_41 = ( T_1 * ) & V_11 -> V_16 [ V_38 ] ;
for ( V_34 = V_51 ; V_34 <= V_52 ; V_34 ++ , V_41 ++ ) {
if ( ! F_33 ( V_2 , V_34 ) ) {
* V_41 = 0 ;
continue;
}
V_50 = ~ ( F_34 ( V_2 , V_34 ) - 1 ) ;
* V_41 &= F_5 ( ( T_2 ) V_50 ) ;
* V_41 |= F_30 ( V_2 , V_34 ) ;
if ( * V_41 & F_5 ( V_49 ) ) {
V_41 ++ ;
* V_41 &= F_5 ( ( T_2 ) ( V_50 >> 32 ) ) ;
V_34 ++ ;
}
}
V_41 = ( T_1 * ) & V_11 -> V_16 [ V_40 ] ;
if ( F_33 ( V_2 , V_53 ) ) {
V_50 = ~ ( F_34 ( V_2 , V_53 ) - 1 ) ;
V_50 |= V_54 ;
* V_41 &= F_5 ( ( T_2 ) V_50 ) ;
} else
* V_41 = 0 ;
V_11 -> V_55 = false ;
}
static int F_35 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( F_36 ( V_3 ) )
F_32 ( V_11 ) ;
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_3 == V_56 && V_11 -> V_2 -> V_35 ) {
T_4 V_57 = F_37 ( * ( V_32 * ) & V_11 -> V_16 [ V_56 ] ) ;
T_2 V_8 = F_8 ( * V_4 ) ;
V_8 |= V_57 & V_58 ;
* V_4 = F_5 ( V_8 ) ;
}
return V_5 ;
}
static int F_38 ( struct V_10 * V_11 , int V_12 ,
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
V_62 = ! ! ( F_37 ( * V_59 ) & V_58 ) ;
V_63 = ! ! ( V_60 & V_58 ) ;
V_64 = ! ! ( V_67 & V_68 ) ;
V_65 = ! ! ( F_37 ( * V_59 ) & V_68 ) ;
V_66 = ! ! ( V_60 & V_68 ) ;
if ( ( V_63 && V_62 && ! V_61 ) ||
( V_66 && V_65 && ! V_64 ) )
F_27 ( V_11 ) ;
}
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 == V_56 ) {
T_4 V_50 = V_58 | V_68 ;
* V_59 &= F_25 ( ~ V_50 ) ;
* V_59 |= F_25 ( V_60 & V_50 ) ;
}
if ( V_3 >= V_56 && V_3 <= V_56 + 1 ) {
bool V_69 ;
V_69 = ! ! ( F_37 ( * V_59 ) &
V_70 ) ;
if ( V_69 && ! V_11 -> V_71 ) {
V_11 -> V_71 = true ;
F_39 ( V_11 ) ;
} else if ( ! V_69 && V_11 -> V_71 ) {
V_11 -> V_71 = false ;
F_40 ( V_11 ) ;
}
}
if ( F_36 ( V_3 ) )
V_11 -> V_55 = true ;
return V_5 ;
}
static int T_6 F_41 ( struct V_13 * V_14 )
{
if ( F_20 ( V_14 , V_21 ) )
return - V_27 ;
V_14 -> V_28 = F_35 ;
V_14 -> V_29 = F_38 ;
F_24 ( V_14 , V_72 , ( T_4 ) V_73 , V_74 ) ;
F_24 ( V_14 , V_75 , ( T_4 ) V_73 , V_74 ) ;
F_24 ( V_14 , V_56 , V_70 , ( T_4 ) V_76 ) ;
F_24 ( V_14 , V_77 , V_78 , V_74 ) ;
F_23 ( V_14 , V_79 , V_80 , ( T_3 ) V_76 ) ;
F_23 ( V_14 , V_81 , V_80 , ( T_3 ) V_76 ) ;
F_23 ( V_14 , V_82 , V_80 , ( T_3 ) V_76 ) ;
F_26 ( V_14 , V_38 , V_73 , V_76 ) ;
F_26 ( V_14 , V_83 , V_73 , V_76 ) ;
F_26 ( V_14 , V_84 , V_73 , V_76 ) ;
F_26 ( V_14 , V_85 , V_73 , V_76 ) ;
F_26 ( V_14 , V_86 , V_73 , V_76 ) ;
F_26 ( V_14 , V_39 , V_73 , V_76 ) ;
F_26 ( V_14 , V_40 , V_73 , V_76 ) ;
F_23 ( V_14 , V_87 , ( T_3 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_88 , ( T_3 ) V_73 , ( T_3 ) V_76 ) ;
F_23 ( V_14 , V_89 , ( T_3 ) V_73 , ( T_3 ) V_74 ) ;
return 0 ;
}
static int F_42 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 == V_90 ) {
T_7 V_91 ;
switch ( F_8 ( V_4 ) & V_92 ) {
case 0 :
V_91 = V_93 ;
break;
case 1 :
V_91 = V_94 ;
break;
case 2 :
V_91 = V_95 ;
break;
case 3 :
V_91 = V_96 ;
break;
}
F_43 ( V_11 -> V_2 , V_91 ) ;
}
return V_5 ;
}
static int T_6 F_44 ( struct V_13 * V_14 )
{
if ( F_20 ( V_14 , V_97 [ V_98 ] ) )
return - V_27 ;
V_14 -> V_29 = F_42 ;
F_23 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_26 ( V_14 , V_90 , V_80 , ~ V_92 ) ;
return 0 ;
}
static int F_45 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_32 * V_99 = ( V_32 * ) ( V_11 -> V_16 + V_12 - V_3 + V_100 ) ;
T_1 * V_101 = ( T_1 * ) ( V_11 -> V_16 + V_12 - V_3 + V_102 ) ;
T_4 V_103 ;
T_2 V_104 ;
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 || V_3 > V_100 + 1 ||
V_3 + V_5 <= V_100 + 1 )
return V_5 ;
V_103 = F_37 ( * V_99 ) ;
if ( V_103 & V_105 ) {
V_104 = F_8 ( * V_101 ) ;
if ( F_46 ( V_2 , V_103 & ~ V_105 , 4 , & V_104 ) != 4 )
return V_5 ;
} else {
if ( F_47 ( V_2 , V_103 , 4 , & V_104 ) != 4 )
return V_5 ;
* V_101 = F_5 ( V_104 ) ;
}
V_103 ^= V_105 ;
* V_99 = F_25 ( V_103 ) ;
return V_5 ;
}
static int T_6 F_48 ( struct V_13 * V_14 )
{
if ( F_20 ( V_14 , V_97 [ V_106 ] ) )
return - V_27 ;
V_14 -> V_29 = F_45 ;
F_23 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_24 ( V_14 , V_100 , ( T_4 ) V_73 , ( T_4 ) V_76 ) ;
F_26 ( V_14 , V_102 , V_73 , V_76 ) ;
return 0 ;
}
static int T_6 F_49 ( struct V_13 * V_14 )
{
if ( F_20 ( V_14 , V_107 ) )
return - V_27 ;
F_23 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_24 ( V_14 , V_108 , V_80 , ( T_4 ) V_76 ) ;
F_26 ( V_14 , V_109 , V_80 , V_76 ) ;
return 0 ;
}
static int T_6 F_50 ( struct V_13 * V_14 )
{
if ( F_20 ( V_14 , V_110 ) )
return - V_27 ;
F_23 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_24 ( V_14 , V_111 , V_80 , ~ V_112 ) ;
F_24 ( V_14 , V_113 , V_80 , ~ V_114 ) ;
return 0 ;
}
static int T_6 F_51 ( struct V_13 * V_14 )
{
if ( F_20 ( V_14 , V_97 [ V_115 ] ) )
return - V_27 ;
F_23 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_116 , V_80 , V_117 ) ;
return 0 ;
}
static int T_6 F_52 ( struct V_13 * V_14 )
{
T_2 V_50 ;
if ( F_20 ( V_14 , V_118 [ V_119 ] ) )
return - V_27 ;
F_26 ( V_14 , 0 , V_73 , V_74 ) ;
V_50 = V_120 |
V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 |
V_128 |
V_129 |
V_130 |
V_131 |
V_132 |
V_133 |
V_134 |
V_135 |
V_136 ;
F_26 ( V_14 , V_137 , V_80 , V_50 ) ;
F_26 ( V_14 , V_138 , V_80 , V_50 ) ;
F_26 ( V_14 , V_139 , V_80 , V_50 ) ;
V_50 = V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 ;
F_26 ( V_14 , V_148 , V_80 , V_50 ) ;
F_26 ( V_14 , V_149 , V_80 , V_50 ) ;
V_50 = V_150 |
V_151 ;
F_26 ( V_14 , V_152 , V_80 , V_50 ) ;
return 0 ;
}
static int T_6 F_53 ( struct V_13 * V_14 )
{
if ( F_20 ( V_14 , V_118 [ V_153 ] ) )
return - V_27 ;
F_26 ( V_14 , 0 , V_73 , V_74 ) ;
F_23 ( V_14 , V_154 , V_80 , ( T_3 ) V_76 ) ;
return 0 ;
}
void F_54 ( void )
{
F_18 ( & V_155 [ V_156 ] ) ;
F_18 ( & V_155 [ V_98 ] ) ;
F_18 ( & V_155 [ V_106 ] ) ;
F_18 ( & V_155 [ V_157 ] ) ;
F_18 ( & V_155 [ V_158 ] ) ;
F_18 ( & V_155 [ V_115 ] ) ;
F_18 ( & V_159 [ V_119 ] ) ;
F_18 ( & V_159 [ V_153 ] ) ;
}
int T_6 F_55 ( void )
{
int V_6 ;
V_6 = F_41 ( & V_155 [ V_156 ] ) ;
V_6 |= F_44 ( & V_155 [ V_98 ] ) ;
V_6 |= F_48 ( & V_155 [ V_106 ] ) ;
V_6 |= F_49 ( & V_155 [ V_157 ] ) ;
V_155 [ V_160 ] . V_29 = F_16 ;
V_6 |= F_50 ( & V_155 [ V_158 ] ) ;
V_6 |= F_51 ( & V_155 [ V_115 ] ) ;
V_6 |= F_52 ( & V_159 [ V_119 ] ) ;
V_6 |= F_53 ( & V_159 [ V_153 ] ) ;
V_159 [ V_161 ] . V_29 = F_16 ;
if ( V_6 )
F_54 () ;
return V_6 ;
}
static int F_56 ( struct V_10 * V_11 , int V_12 )
{
T_3 V_162 ;
int V_163 = ( V_12 >= V_20 ) ? V_20 :
V_21 ;
V_162 = V_11 -> V_164 [ V_12 ] ;
if ( V_162 == V_156 )
return 0 ;
while ( V_12 - 1 >= V_163 && V_11 -> V_164 [ V_12 - 1 ] == V_162 )
V_12 -- ;
return V_12 ;
}
static int F_57 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( V_3 <= V_165 && V_3 + V_5 >= V_165 ) {
V_32 * V_42 ;
int V_166 ;
V_166 = F_56 ( V_11 , V_12 ) ;
V_42 = ( V_32 * ) & V_11 -> V_16 [ V_166 ] ;
* V_42 &= F_25 ( ~ V_167 ) ;
* V_42 |= F_25 ( V_11 -> V_168 << 1 ) ;
}
return F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
}
static int F_58 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 <= V_165 && V_3 + V_5 >= V_165 ) {
V_32 * V_169 ;
T_4 V_42 ;
int V_166 , V_6 ;
V_166 = F_56 ( V_11 , V_12 ) ;
V_169 = ( V_32 * ) & V_11 -> V_16 [ V_166 + V_165 ] ;
V_42 = F_37 ( * V_169 ) ;
if ( ! F_59 ( V_11 ) )
V_42 &= ~ V_170 ;
if ( ( V_42 & V_171 ) >> 4 > V_11 -> V_168 ) {
V_42 &= ~ V_171 ;
V_42 |= V_11 -> V_168 << 4 ;
}
* V_169 = F_25 ( V_42 ) ;
V_6 = F_10 ( V_11 -> V_2 ,
V_166 + V_165 ,
V_42 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
}
return V_5 ;
}
static int F_60 ( struct V_13 * V_14 , int V_172 , T_4 V_42 )
{
if ( F_20 ( V_14 , V_172 ) )
return - V_27 ;
V_14 -> V_28 = F_57 ;
V_14 -> V_29 = F_58 ;
F_23 ( V_14 , V_24 , ( T_3 ) V_73 , V_74 ) ;
F_23 ( V_14 , V_165 , ( T_3 ) V_73 , ( T_3 ) V_76 ) ;
F_26 ( V_14 , V_173 , V_73 , V_76 ) ;
if ( V_42 & V_174 ) {
F_26 ( V_14 , V_175 , V_73 , V_76 ) ;
F_24 ( V_14 , V_176 , ( T_4 ) V_73 , ( T_4 ) V_76 ) ;
if ( V_42 & V_177 ) {
F_26 ( V_14 , V_178 , V_80 , V_76 ) ;
F_26 ( V_14 , V_179 , V_80 , V_76 ) ;
}
} else {
F_24 ( V_14 , V_180 , ( T_4 ) V_73 , ( T_4 ) V_76 ) ;
if ( V_42 & V_177 ) {
F_26 ( V_14 , V_181 , V_80 , V_76 ) ;
F_26 ( V_14 , V_182 , V_80 , V_76 ) ;
}
}
return 0 ;
}
static int F_61 ( struct V_10 * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_172 , V_6 ;
T_4 V_42 ;
V_6 = F_62 ( V_2 , V_12 + V_165 , & V_42 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_172 = 10 ;
if ( V_42 & V_174 )
V_172 += 4 ;
if ( V_42 & V_177 )
V_172 += 10 ;
if ( V_11 -> V_183 )
return V_172 ;
V_11 -> V_183 = F_63 ( sizeof( struct V_13 ) , V_26 ) ;
if ( ! V_11 -> V_183 )
return - V_27 ;
V_6 = F_60 ( V_11 -> V_183 , V_172 , V_42 ) ;
if ( V_6 )
return V_6 ;
return V_172 ;
}
static int F_64 ( struct V_10 * V_11 , T_4 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_9 ;
int V_6 , V_184 , V_185 , V_186 ;
int V_172 = V_187 ;
V_6 = F_65 ( V_2 , V_12 + V_188 , & V_9 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_184 = V_9 & V_189 ;
V_6 = F_65 ( V_2 , V_12 + V_190 , & V_9 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_9 & V_191 )
V_185 = 128 ;
else if ( V_9 & V_192 )
V_185 = 64 ;
else if ( V_9 & V_193 )
V_185 = 32 ;
else
V_185 = 0 ;
V_186 = V_185 * 4 ;
V_172 += ( 1 + V_184 ) * V_194 ;
if ( V_186 ) {
V_172 = F_21 ( V_172 , 16 ) ;
V_172 += V_186 / 8 ;
}
return V_172 ;
}
static int F_66 ( struct V_10 * V_11 , T_3 V_162 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_195 ;
T_4 V_196 ;
T_3 V_197 ;
int V_6 ;
switch ( V_162 ) {
case V_198 :
return F_61 ( V_11 , V_12 ) ;
case V_157 :
V_6 = F_62 ( V_2 , V_12 + V_108 , & V_196 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( F_67 ( V_196 ) ) {
F_65 ( V_2 , V_20 , & V_195 ) ;
V_11 -> V_199 = ( V_195 != 0 ) ;
return V_107 ;
} else
return V_200 ;
case V_160 :
V_6 = F_68 ( V_2 , V_12 + V_23 , & V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_197 ;
case V_158 :
F_65 ( V_2 , V_20 , & V_195 ) ;
V_11 -> V_199 = ( V_195 != 0 ) ;
if ( ( F_69 ( V_2 ) & V_201 ) == 1 )
return V_202 ;
else
return V_110 ;
case V_203 :
V_6 = F_68 ( V_2 , V_12 + 3 , & V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return ( V_197 & V_204 ) ?
V_205 : V_206 ;
case V_207 :
V_6 = F_68 ( V_2 , V_12 + V_208 , & V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_197 &= V_209 ;
if ( V_197 == V_210 )
return V_211 ;
else
return V_212 ;
default:
F_70 ( L_2 ,
F_29 ( & V_2 -> V_37 ) , V_36 , V_162 , V_12 ) ;
}
return 0 ;
}
static int F_71 ( struct V_10 * V_11 , T_4 V_213 , T_4 V_214 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_197 ;
T_2 V_195 ;
int V_6 ;
switch ( V_213 ) {
case V_161 :
V_6 = F_65 ( V_2 , V_214 + V_215 , & V_195 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_195 >> V_216 ;
case V_217 :
case V_218 :
case V_219 :
return F_64 ( V_11 , V_214 ) ;
case V_220 :
V_6 = F_68 ( V_2 , V_214 + V_221 , & V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_197 & V_222 ) {
int V_223 ;
V_6 = F_68 ( V_2 ,
V_214 + V_224 ,
& V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_223 = V_197 ? F_21 ( V_197 , 32 ) : 256 ;
return 8 + ( V_223 / 8 ) ;
}
return 8 ;
case V_225 :
V_6 = F_68 ( V_2 , V_214 + V_226 , & V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_197 &= V_227 ;
V_197 >>= V_228 ;
return 4 + ( V_197 * 8 ) ;
case V_229 :
V_6 = F_68 ( V_2 , V_214 + V_230 , & V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_197 &= V_231 ;
return V_232 + V_197 + 1 ;
case V_233 :
V_6 = F_65 ( V_2 , V_214 + V_234 , & V_195 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( ( V_195 & V_235 ) == V_236 ) {
int V_237 ;
V_237 = V_195 & V_238 ;
V_237 >>= V_239 ;
return V_240 + ( V_237 * 2 ) + 2 ;
}
return V_240 ;
default:
F_70 ( L_3 ,
F_29 ( & V_2 -> V_37 ) , V_36 , V_213 , V_214 ) ;
}
return 0 ;
}
static int F_72 ( struct V_10 * V_11 ,
int V_3 , int V_25 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_6 = 0 ;
while ( V_25 ) {
int V_241 ;
if ( V_25 >= 4 && ! ( V_3 % 4 ) ) {
T_1 * V_242 = ( T_1 * ) & V_11 -> V_16 [ V_3 ] ;
T_2 V_195 ;
V_6 = F_65 ( V_2 , V_3 , & V_195 ) ;
if ( V_6 )
return V_6 ;
* V_242 = F_5 ( V_195 ) ;
V_241 = 4 ;
} else if ( V_25 >= 2 && ! ( V_3 % 2 ) ) {
V_32 * V_243 = ( V_32 * ) & V_11 -> V_16 [ V_3 ] ;
T_4 V_196 ;
V_6 = F_62 ( V_2 , V_3 , & V_196 ) ;
if ( V_6 )
return V_6 ;
* V_243 = F_25 ( V_196 ) ;
V_241 = 2 ;
} else {
T_3 * V_197 = & V_11 -> V_16 [ V_3 ] ;
V_6 = F_68 ( V_2 , V_3 , V_197 ) ;
if ( V_6 )
return V_6 ;
V_241 = 1 ;
}
V_3 += V_241 ;
V_25 -= V_241 ;
}
return V_6 ;
}
static int F_73 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_244 = V_11 -> V_164 ;
T_4 V_245 ;
T_3 V_12 , * V_246 , V_162 ;
int V_247 , V_6 , V_248 = 0 ;
V_6 = F_62 ( V_2 , V_77 , & V_245 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_245 & V_78 ) )
return 0 ;
V_6 = F_68 ( V_2 , V_87 , & V_12 ) ;
if ( V_6 )
return V_6 ;
V_246 = & V_11 -> V_16 [ V_87 ] ;
V_247 = ( V_20 - V_21 ) / V_249 ;
while ( V_12 && V_247 -- ) {
T_3 V_250 ;
int V_34 , V_172 = 0 ;
V_6 = F_68 ( V_2 , V_12 , & V_162 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_68 ( V_2 ,
V_12 + V_24 , & V_250 ) ;
if ( V_6 )
return V_6 ;
if ( V_162 <= V_251 ) {
V_172 = V_97 [ V_162 ] ;
if ( V_172 == 0xFF ) {
V_172 = F_66 ( V_11 , V_162 , V_12 ) ;
if ( V_172 < 0 )
return V_172 ;
}
}
if ( ! V_172 ) {
F_28 ( L_4 ,
V_36 , F_29 ( & V_2 -> V_37 ) , V_162 ) ;
* V_246 = V_250 ;
V_12 = V_250 ;
continue;
}
for ( V_34 = 0 ; V_34 < V_172 ; V_34 ++ ) {
if ( F_74 ( V_244 [ V_12 + V_34 ] == V_252 ) )
continue;
F_70 ( L_5 ,
V_36 , F_29 ( & V_2 -> V_37 ) ,
V_12 + V_34 , V_244 [ V_12 + V_34 ] , V_162 ) ;
}
memset ( V_244 + V_12 , V_162 , V_172 ) ;
V_6 = F_72 ( V_11 , V_12 , V_172 ) ;
if ( V_6 )
return V_6 ;
V_246 = & V_11 -> V_16 [ V_12 + V_24 ] ;
V_12 = V_250 ;
V_248 ++ ;
}
if ( ! V_248 ) {
V_32 * V_253 = ( V_32 * ) & V_11 -> V_16 [ V_77 ] ;
* V_253 &= ~ F_25 ( V_78 ) ;
}
return 0 ;
}
static int F_75 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_244 = V_11 -> V_164 ;
T_4 V_214 ;
T_1 * V_246 = NULL ;
int V_247 , V_6 , V_254 = 0 ;
if ( ! V_11 -> V_199 )
return 0 ;
V_214 = V_20 ;
V_247 = ( V_2 -> V_255 - V_20 ) / V_249 ;
while ( V_247 -- && V_214 >= V_20 ) {
T_2 V_256 ;
T_4 V_213 ;
int V_34 , V_172 = 0 ;
bool V_257 = false ;
V_6 = F_65 ( V_2 , V_214 , & V_256 ) ;
if ( V_6 )
return V_6 ;
V_213 = F_76 ( V_256 ) ;
if ( V_213 <= V_258 ) {
V_172 = V_118 [ V_213 ] ;
if ( V_172 == 0xFF ) {
V_172 = F_71 ( V_11 , V_213 , V_214 ) ;
if ( V_172 < 0 )
return V_6 ;
}
}
if ( ! V_172 ) {
F_28 ( L_6 ,
V_36 , F_29 ( & V_2 -> V_37 ) , V_213 , V_214 ) ;
if ( V_246 ) {
T_2 V_4 = V_214 = F_77 ( V_256 ) ;
* V_246 &= F_5 ( ~ ( 0xffcU << 20 ) ) ;
* V_246 |= F_5 ( V_4 << 20 ) ;
continue;
}
V_172 = V_249 ;
V_257 = true ;
}
for ( V_34 = 0 ; V_34 < V_172 ; V_34 ++ ) {
if ( F_74 ( V_244 [ V_214 + V_34 ] == V_252 ) )
continue;
F_70 ( L_7 ,
V_36 , F_29 ( & V_2 -> V_37 ) ,
V_214 + V_34 , V_244 [ V_214 + V_34 ] , V_213 ) ;
}
F_78 ( V_258 >= V_252 ) ;
memset ( V_244 + V_214 , V_213 , V_172 ) ;
V_6 = F_72 ( V_11 , V_214 , V_172 ) ;
if ( V_6 )
return V_6 ;
if ( V_257 )
* ( T_1 * ) & V_11 -> V_16 [ V_214 ] &=
F_5 ( ( 0xffcU << 20 ) ) ;
else
V_254 ++ ;
V_246 = ( T_1 * ) & V_11 -> V_16 [ V_214 ] ;
V_214 = F_77 ( V_256 ) ;
}
if ( ! V_254 )
* ( T_2 * ) & V_11 -> V_16 [ V_20 ] = 0 ;
return 0 ;
}
int F_79 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_244 , * V_16 ;
int V_6 ;
V_244 = F_63 ( V_2 -> V_255 , V_26 ) ;
if ( ! V_244 )
return - V_27 ;
V_16 = F_63 ( V_2 -> V_255 , V_26 ) ;
if ( ! V_16 ) {
F_19 ( V_244 ) ;
return - V_27 ;
}
V_11 -> V_164 = V_244 ;
V_11 -> V_16 = V_16 ;
memset ( V_244 , V_156 , V_21 ) ;
memset ( V_244 + V_21 , V_252 ,
V_2 -> V_255 - V_21 ) ;
V_6 = F_72 ( V_11 , 0 , V_21 ) ;
if ( V_6 )
goto V_259;
V_11 -> V_55 = true ;
V_11 -> V_33 [ 0 ] = F_8 ( * ( T_1 * ) & V_16 [ V_38 ] ) ;
V_11 -> V_33 [ 1 ] = F_8 ( * ( T_1 * ) & V_16 [ V_83 ] ) ;
V_11 -> V_33 [ 2 ] = F_8 ( * ( T_1 * ) & V_16 [ V_84 ] ) ;
V_11 -> V_33 [ 3 ] = F_8 ( * ( T_1 * ) & V_16 [ V_85 ] ) ;
V_11 -> V_33 [ 4 ] = F_8 ( * ( T_1 * ) & V_16 [ V_86 ] ) ;
V_11 -> V_33 [ 5 ] = F_8 ( * ( T_1 * ) & V_16 [ V_39 ] ) ;
V_11 -> V_33 [ 6 ] = F_8 ( * ( T_1 * ) & V_16 [ V_40 ] ) ;
if ( V_2 -> V_35 ) {
* ( V_32 * ) & V_16 [ V_72 ] = F_25 ( V_2 -> V_260 ) ;
* ( V_32 * ) & V_16 [ V_75 ] = F_25 ( V_2 -> V_261 ) ;
}
if ( ! F_80 ( V_262 ) )
V_16 [ V_89 ] = 0 ;
V_6 = F_73 ( V_11 ) ;
if ( V_6 )
goto V_259;
V_6 = F_75 ( V_11 ) ;
if ( V_6 )
goto V_259;
return 0 ;
V_259:
F_19 ( V_244 ) ;
V_11 -> V_164 = NULL ;
F_19 ( V_16 ) ;
V_11 -> V_16 = NULL ;
return F_6 ( V_6 ) ;
}
void F_81 ( struct V_10 * V_11 )
{
F_19 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
F_19 ( V_11 -> V_164 ) ;
V_11 -> V_164 = NULL ;
F_19 ( V_11 -> V_183 ) ;
V_11 -> V_183 = NULL ;
}
static T_8 F_82 ( struct V_10 * V_11 ,
T_9 V_12 )
{
T_3 V_162 = V_11 -> V_164 [ V_12 ] ;
T_8 V_34 ;
for ( V_34 = 1 ; ( V_12 + V_34 ) % 4 && V_11 -> V_164 [ V_12 + V_34 ] == V_162 ; V_34 ++ )
;
return V_34 ;
}
static T_10 F_83 ( struct V_10 * V_11 , char T_11 * V_263 ,
T_8 V_5 , T_9 * V_264 , bool V_265 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_13 * V_14 ;
T_1 V_4 = 0 ;
int V_266 = 0 , V_3 ;
T_3 V_267 ;
T_10 V_6 ;
if ( * V_264 < 0 || * V_264 >= V_2 -> V_255 ||
* V_264 + V_5 > V_2 -> V_255 )
return - V_268 ;
V_5 = F_15 ( V_5 , F_82 ( V_11 , * V_264 ) ) ;
if ( V_5 >= 4 && ! ( * V_264 % 4 ) )
V_5 = 4 ;
else if ( V_5 >= 2 && ! ( * V_264 % 2 ) )
V_5 = 2 ;
else
V_5 = 1 ;
V_6 = V_5 ;
V_267 = V_11 -> V_164 [ * V_264 ] ;
if ( V_267 == V_252 ) {
V_14 = & V_269 ;
V_266 = * V_264 ;
} else {
if ( * V_264 >= V_20 ) {
F_84 ( V_267 > V_258 ) ;
V_14 = & V_159 [ V_267 ] ;
V_266 = F_56 ( V_11 , * V_264 ) ;
} else {
F_84 ( V_267 > V_251 ) ;
V_14 = & V_155 [ V_267 ] ;
if ( V_267 == V_198 )
V_14 = V_11 -> V_183 ;
if ( V_267 > V_156 )
V_266 = F_56 ( V_11 , * V_264 ) ;
}
}
F_84 ( ! V_266 && V_267 != V_156 ) ;
F_84 ( V_266 > * V_264 ) ;
V_3 = * V_264 - V_266 ;
if ( V_265 ) {
if ( ! V_14 -> V_29 )
return V_6 ;
if ( F_85 ( & V_4 , V_263 , V_5 ) )
return - V_268 ;
V_6 = V_14 -> V_29 ( V_11 , * V_264 , V_5 , V_14 , V_3 , V_4 ) ;
} else {
if ( V_14 -> V_28 ) {
V_6 = V_14 -> V_28 ( V_11 , * V_264 , V_5 ,
V_14 , V_3 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( F_86 ( V_263 , & V_4 , V_5 ) )
return - V_268 ;
}
return V_6 ;
}
T_10 F_87 ( struct V_10 * V_11 , char T_11 * V_263 ,
T_8 V_5 , T_9 * V_264 , bool V_265 )
{
T_8 V_270 = 0 ;
int V_6 = 0 ;
T_9 V_12 = * V_264 ;
V_12 &= V_271 ;
while ( V_5 ) {
V_6 = F_83 ( V_11 , V_263 , V_5 , & V_12 , V_265 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -= V_6 ;
V_270 += V_6 ;
V_263 += V_6 ;
V_12 += V_6 ;
}
* V_264 += V_270 ;
return V_270 ;
}
