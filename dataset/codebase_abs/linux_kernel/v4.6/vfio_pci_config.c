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
static int F_18 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
memcpy ( V_11 -> V_16 + V_12 , & V_4 , V_5 ) ;
return V_5 ;
}
static int F_19 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
memcpy ( V_4 , V_11 -> V_16 + V_12 , V_5 ) ;
return V_5 ;
}
static void F_20 ( struct V_13 * V_14 )
{
F_21 ( V_14 -> V_15 ) ;
F_21 ( V_14 -> V_18 ) ;
V_14 -> V_15 = NULL ;
V_14 -> V_18 = NULL ;
}
static int F_22 ( struct V_13 * V_14 , int V_25 )
{
V_25 = F_23 ( V_25 , 4 ) ;
V_14 -> V_15 = F_24 ( V_25 , V_26 ) ;
V_14 -> V_18 = F_24 ( V_25 , V_26 ) ;
if ( ! V_14 -> V_15 || ! V_14 -> V_18 ) {
F_20 ( V_14 ) ;
return - V_27 ;
}
V_14 -> V_28 = F_12 ;
V_14 -> V_29 = F_13 ;
return 0 ;
}
static inline void F_25 ( struct V_13 * V_30 , int V_31 , T_3 V_15 , T_3 V_18 )
{
V_30 -> V_15 [ V_31 ] = V_15 ;
V_30 -> V_18 [ V_31 ] = V_18 ;
}
static inline void F_26 ( struct V_13 * V_30 , int V_31 , T_4 V_15 , T_4 V_18 )
{
* ( V_32 * ) ( & V_30 -> V_15 [ V_31 ] ) = F_27 ( V_15 ) ;
* ( V_32 * ) ( & V_30 -> V_18 [ V_31 ] ) = F_27 ( V_18 ) ;
}
static inline void F_28 ( struct V_13 * V_30 , int V_31 , T_2 V_15 , T_2 V_18 )
{
* ( T_1 * ) ( & V_30 -> V_15 [ V_31 ] ) = F_5 ( V_15 ) ;
* ( T_1 * ) ( & V_30 -> V_18 [ V_31 ] ) = F_5 ( V_18 ) ;
}
static void F_29 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 * V_33 = V_11 -> V_33 ;
int V_34 ;
if ( V_2 -> V_35 )
return;
F_30 ( L_1 ,
V_36 , F_31 ( & V_2 -> V_37 ) ) ;
for ( V_34 = V_38 ; V_34 <= V_39 ; V_34 += 4 , V_33 ++ )
F_11 ( V_2 , V_34 , * V_33 ) ;
F_11 ( V_2 , V_40 , * V_33 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 , int V_41 )
{
unsigned long V_42 = F_33 ( V_2 , V_41 ) ;
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
static void F_34 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_34 ;
T_1 * V_41 ;
T_5 V_50 ;
V_41 = ( T_1 * ) & V_11 -> V_16 [ V_38 ] ;
for ( V_34 = V_51 ; V_34 <= V_52 ; V_34 ++ , V_41 ++ ) {
if ( ! F_35 ( V_2 , V_34 ) ) {
* V_41 = 0 ;
continue;
}
V_50 = ~ ( F_36 ( V_2 , V_34 ) - 1 ) ;
* V_41 &= F_5 ( ( T_2 ) V_50 ) ;
* V_41 |= F_32 ( V_2 , V_34 ) ;
if ( * V_41 & F_5 ( V_49 ) ) {
V_41 ++ ;
* V_41 &= F_5 ( ( T_2 ) ( V_50 >> 32 ) ) ;
V_34 ++ ;
}
}
V_41 = ( T_1 * ) & V_11 -> V_16 [ V_40 ] ;
if ( F_35 ( V_2 , V_53 ) ) {
V_50 = ~ ( F_36 ( V_2 , V_53 ) - 1 ) ;
V_50 |= V_54 ;
* V_41 &= F_5 ( ( T_2 ) V_50 ) ;
} else if ( V_2 -> V_55 [ V_53 ] . V_42 &
V_56 ) {
V_50 = ~ ( 0x20000 - 1 ) ;
V_50 |= V_54 ;
* V_41 &= F_5 ( ( T_2 ) V_50 ) ;
} else
* V_41 = 0 ;
V_11 -> V_57 = false ;
}
static int F_37 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( F_38 ( V_3 ) )
F_34 ( V_11 ) ;
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_3 == V_58 && V_11 -> V_2 -> V_35 ) {
T_4 V_59 = F_39 ( * ( V_32 * ) & V_11 -> V_16 [ V_58 ] ) ;
T_2 V_8 = F_8 ( * V_4 ) ;
V_8 |= V_59 & V_60 ;
* V_4 = F_5 ( V_8 ) ;
}
return V_5 ;
}
static int F_40 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_32 * V_61 ;
T_4 V_62 = 0 ;
int V_6 ;
V_61 = ( V_32 * ) & V_11 -> V_16 [ V_58 ] ;
if ( V_3 == V_58 ) {
bool V_63 , V_64 , V_65 , V_66 , V_67 , V_68 ;
T_4 V_69 ;
V_6 = F_3 ( V_2 , V_58 , & V_69 ) ;
if ( V_6 )
return V_6 ;
V_62 = F_8 ( V_4 ) ;
V_63 = ! ! ( V_69 & V_60 ) ;
V_64 = ! ! ( F_39 ( * V_61 ) & V_60 ) ;
V_65 = ! ! ( V_62 & V_60 ) ;
V_66 = ! ! ( V_69 & V_70 ) ;
V_67 = ! ! ( F_39 ( * V_61 ) & V_70 ) ;
V_68 = ! ! ( V_62 & V_70 ) ;
if ( ( V_65 && V_64 && ! V_63 ) ||
( V_68 && V_67 && ! V_66 ) )
F_29 ( V_11 ) ;
}
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 == V_58 ) {
T_4 V_50 = V_60 | V_70 ;
* V_61 &= F_27 ( ~ V_50 ) ;
* V_61 |= F_27 ( V_62 & V_50 ) ;
}
if ( V_3 >= V_58 && V_3 <= V_58 + 1 ) {
bool V_71 ;
V_71 = ! ! ( F_39 ( * V_61 ) &
V_72 ) ;
if ( V_71 && ! V_11 -> V_73 ) {
V_11 -> V_73 = true ;
F_41 ( V_11 ) ;
} else if ( ! V_71 && V_11 -> V_73 ) {
V_11 -> V_73 = false ;
F_42 ( V_11 ) ;
}
}
if ( F_38 ( V_3 ) )
V_11 -> V_57 = true ;
return V_5 ;
}
static int T_6 F_43 ( struct V_13 * V_14 )
{
if ( F_22 ( V_14 , V_21 ) )
return - V_27 ;
V_14 -> V_28 = F_37 ;
V_14 -> V_29 = F_40 ;
F_26 ( V_14 , V_74 , ( T_4 ) V_75 , V_76 ) ;
F_26 ( V_14 , V_77 , ( T_4 ) V_75 , V_76 ) ;
F_26 ( V_14 , V_58 , V_72 , ( T_4 ) V_78 ) ;
F_26 ( V_14 , V_79 , V_80 , V_76 ) ;
F_25 ( V_14 , V_81 , V_82 , ( T_3 ) V_78 ) ;
F_25 ( V_14 , V_83 , V_82 , ( T_3 ) V_78 ) ;
F_25 ( V_14 , V_84 , V_82 , ( T_3 ) V_78 ) ;
F_28 ( V_14 , V_38 , V_75 , V_78 ) ;
F_28 ( V_14 , V_85 , V_75 , V_78 ) ;
F_28 ( V_14 , V_86 , V_75 , V_78 ) ;
F_28 ( V_14 , V_87 , V_75 , V_78 ) ;
F_28 ( V_14 , V_88 , V_75 , V_78 ) ;
F_28 ( V_14 , V_39 , V_75 , V_78 ) ;
F_28 ( V_14 , V_40 , V_75 , V_78 ) ;
F_25 ( V_14 , V_89 , ( T_3 ) V_75 , V_76 ) ;
F_25 ( V_14 , V_90 , ( T_3 ) V_75 , ( T_3 ) V_78 ) ;
F_25 ( V_14 , V_91 , ( T_3 ) V_75 , ( T_3 ) V_76 ) ;
return 0 ;
}
static int F_44 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 == V_92 ) {
T_7 V_93 ;
switch ( F_8 ( V_4 ) & V_94 ) {
case 0 :
V_93 = V_95 ;
break;
case 1 :
V_93 = V_96 ;
break;
case 2 :
V_93 = V_97 ;
break;
case 3 :
V_93 = V_98 ;
break;
}
F_45 ( V_11 -> V_2 , V_93 ) ;
}
return V_5 ;
}
static int T_6 F_46 ( struct V_13 * V_14 )
{
if ( F_22 ( V_14 , V_99 [ V_100 ] ) )
return - V_27 ;
V_14 -> V_29 = F_44 ;
F_25 ( V_14 , V_24 , ( T_3 ) V_75 , V_76 ) ;
F_28 ( V_14 , V_92 , V_82 , ~ V_94 ) ;
return 0 ;
}
static int F_47 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_32 * V_101 = ( V_32 * ) ( V_11 -> V_16 + V_12 - V_3 + V_102 ) ;
T_1 * V_103 = ( T_1 * ) ( V_11 -> V_16 + V_12 - V_3 + V_104 ) ;
T_4 V_105 ;
T_2 V_106 ;
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 || V_3 > V_102 + 1 ||
V_3 + V_5 <= V_102 + 1 )
return V_5 ;
V_105 = F_39 ( * V_101 ) ;
if ( V_105 & V_107 ) {
V_106 = F_8 ( * V_103 ) ;
if ( F_48 ( V_2 , V_105 & ~ V_107 , 4 , & V_106 ) != 4 )
return V_5 ;
} else {
if ( F_49 ( V_2 , V_105 , 4 , & V_106 ) != 4 )
return V_5 ;
* V_103 = F_5 ( V_106 ) ;
}
V_105 ^= V_107 ;
* V_101 = F_27 ( V_105 ) ;
return V_5 ;
}
static int T_6 F_50 ( struct V_13 * V_14 )
{
if ( F_22 ( V_14 , V_99 [ V_108 ] ) )
return - V_27 ;
V_14 -> V_29 = F_47 ;
F_25 ( V_14 , V_24 , ( T_3 ) V_75 , V_76 ) ;
F_26 ( V_14 , V_102 , ( T_4 ) V_75 , ( T_4 ) V_78 ) ;
F_28 ( V_14 , V_104 , V_75 , V_78 ) ;
return 0 ;
}
static int T_6 F_51 ( struct V_13 * V_14 )
{
if ( F_22 ( V_14 , V_109 ) )
return - V_27 ;
F_25 ( V_14 , V_24 , ( T_3 ) V_75 , V_76 ) ;
F_26 ( V_14 , V_110 , V_82 , ( T_4 ) V_78 ) ;
F_28 ( V_14 , V_111 , V_82 , V_78 ) ;
return 0 ;
}
static int T_6 F_52 ( struct V_13 * V_14 )
{
if ( F_22 ( V_14 , V_112 ) )
return - V_27 ;
F_25 ( V_14 , V_24 , ( T_3 ) V_75 , V_76 ) ;
F_26 ( V_14 , V_113 , V_82 , ~ V_114 ) ;
F_26 ( V_14 , V_115 , V_82 , ~ V_116 ) ;
return 0 ;
}
static int T_6 F_53 ( struct V_13 * V_14 )
{
if ( F_22 ( V_14 , V_99 [ V_117 ] ) )
return - V_27 ;
F_25 ( V_14 , V_24 , ( T_3 ) V_75 , V_76 ) ;
F_25 ( V_14 , V_118 , V_82 , V_119 ) ;
return 0 ;
}
static int T_6 F_54 ( struct V_13 * V_14 )
{
T_2 V_50 ;
if ( F_22 ( V_14 , V_120 [ V_121 ] ) )
return - V_27 ;
F_28 ( V_14 , 0 , V_75 , V_76 ) ;
V_50 = V_122 |
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
V_136 |
V_137 |
V_138 ;
F_28 ( V_14 , V_139 , V_82 , V_50 ) ;
F_28 ( V_14 , V_140 , V_82 , V_50 ) ;
F_28 ( V_14 , V_141 , V_82 , V_50 ) ;
V_50 = V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 |
V_148 |
V_149 ;
F_28 ( V_14 , V_150 , V_82 , V_50 ) ;
F_28 ( V_14 , V_151 , V_82 , V_50 ) ;
V_50 = V_152 |
V_153 ;
F_28 ( V_14 , V_154 , V_82 , V_50 ) ;
return 0 ;
}
static int T_6 F_55 ( struct V_13 * V_14 )
{
if ( F_22 ( V_14 , V_120 [ V_155 ] ) )
return - V_27 ;
F_28 ( V_14 , 0 , V_75 , V_76 ) ;
F_25 ( V_14 , V_156 , V_82 , ( T_3 ) V_78 ) ;
return 0 ;
}
void F_56 ( void )
{
F_20 ( & V_157 [ V_158 ] ) ;
F_20 ( & V_157 [ V_100 ] ) ;
F_20 ( & V_157 [ V_108 ] ) ;
F_20 ( & V_157 [ V_159 ] ) ;
F_20 ( & V_157 [ V_160 ] ) ;
F_20 ( & V_157 [ V_117 ] ) ;
F_20 ( & V_161 [ V_121 ] ) ;
F_20 ( & V_161 [ V_155 ] ) ;
}
int T_6 F_57 ( void )
{
int V_6 ;
V_6 = F_43 ( & V_157 [ V_158 ] ) ;
V_6 |= F_46 ( & V_157 [ V_100 ] ) ;
V_6 |= F_50 ( & V_157 [ V_108 ] ) ;
V_6 |= F_51 ( & V_157 [ V_159 ] ) ;
V_157 [ V_162 ] . V_29 = F_16 ;
V_6 |= F_52 ( & V_157 [ V_160 ] ) ;
V_6 |= F_53 ( & V_157 [ V_117 ] ) ;
V_6 |= F_54 ( & V_161 [ V_121 ] ) ;
V_6 |= F_55 ( & V_161 [ V_155 ] ) ;
V_161 [ V_163 ] . V_29 = F_16 ;
if ( V_6 )
F_56 () ;
return V_6 ;
}
static int F_58 ( struct V_10 * V_11 , int V_12 )
{
T_3 V_164 ;
int V_165 = ( V_12 >= V_20 ) ? V_20 :
V_21 ;
V_164 = V_11 -> V_166 [ V_12 ] ;
if ( V_164 == V_158 )
return 0 ;
while ( V_12 - 1 >= V_165 && V_11 -> V_166 [ V_12 - 1 ] == V_164 )
V_12 -- ;
return V_12 ;
}
static int F_59 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( V_3 <= V_167 && V_3 + V_5 >= V_167 ) {
V_32 * V_42 ;
int V_168 ;
V_168 = F_58 ( V_11 , V_12 ) ;
V_42 = ( V_32 * ) & V_11 -> V_16 [ V_168 ] ;
* V_42 &= F_27 ( ~ V_169 ) ;
* V_42 |= F_27 ( V_11 -> V_170 << 1 ) ;
}
return F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
}
static int F_60 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_13 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 <= V_167 && V_3 + V_5 >= V_167 ) {
V_32 * V_171 ;
T_4 V_42 ;
int V_168 , V_6 ;
V_168 = F_58 ( V_11 , V_12 ) ;
V_171 = ( V_32 * ) & V_11 -> V_16 [ V_168 + V_167 ] ;
V_42 = F_39 ( * V_171 ) ;
if ( ! F_61 ( V_11 ) )
V_42 &= ~ V_172 ;
if ( ( V_42 & V_173 ) >> 4 > V_11 -> V_170 ) {
V_42 &= ~ V_173 ;
V_42 |= V_11 -> V_170 << 4 ;
}
* V_171 = F_27 ( V_42 ) ;
V_6 = F_10 ( V_11 -> V_2 ,
V_168 + V_167 ,
V_42 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
}
return V_5 ;
}
static int F_62 ( struct V_13 * V_14 , int V_174 , T_4 V_42 )
{
if ( F_22 ( V_14 , V_174 ) )
return - V_27 ;
V_14 -> V_28 = F_59 ;
V_14 -> V_29 = F_60 ;
F_25 ( V_14 , V_24 , ( T_3 ) V_75 , V_76 ) ;
F_25 ( V_14 , V_167 , ( T_3 ) V_75 , ( T_3 ) V_78 ) ;
F_28 ( V_14 , V_175 , V_75 , V_78 ) ;
if ( V_42 & V_176 ) {
F_28 ( V_14 , V_177 , V_75 , V_78 ) ;
F_26 ( V_14 , V_178 , ( T_4 ) V_75 , ( T_4 ) V_78 ) ;
if ( V_42 & V_179 ) {
F_28 ( V_14 , V_180 , V_82 , V_78 ) ;
F_28 ( V_14 , V_181 , V_82 , V_78 ) ;
}
} else {
F_26 ( V_14 , V_182 , ( T_4 ) V_75 , ( T_4 ) V_78 ) ;
if ( V_42 & V_179 ) {
F_28 ( V_14 , V_183 , V_82 , V_78 ) ;
F_28 ( V_14 , V_184 , V_82 , V_78 ) ;
}
}
return 0 ;
}
static int F_63 ( struct V_10 * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_174 , V_6 ;
T_4 V_42 ;
V_6 = F_64 ( V_2 , V_12 + V_167 , & V_42 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_174 = 10 ;
if ( V_42 & V_176 )
V_174 += 4 ;
if ( V_42 & V_179 )
V_174 += 10 ;
if ( V_11 -> V_185 )
return V_174 ;
V_11 -> V_185 = F_65 ( sizeof( struct V_13 ) , V_26 ) ;
if ( ! V_11 -> V_185 )
return - V_27 ;
V_6 = F_62 ( V_11 -> V_185 , V_174 , V_42 ) ;
if ( V_6 )
return V_6 ;
return V_174 ;
}
static int F_66 ( struct V_10 * V_11 , T_4 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_9 ;
int V_6 , V_186 , V_187 , V_188 ;
int V_174 = V_189 ;
V_6 = F_67 ( V_2 , V_12 + V_190 , & V_9 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_186 = V_9 & V_191 ;
V_6 = F_67 ( V_2 , V_12 + V_192 , & V_9 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_9 & V_193 )
V_187 = 128 ;
else if ( V_9 & V_194 )
V_187 = 64 ;
else if ( V_9 & V_195 )
V_187 = 32 ;
else
V_187 = 0 ;
V_188 = V_187 * 4 ;
V_174 += ( 1 + V_186 ) * V_196 ;
if ( V_188 ) {
V_174 = F_23 ( V_174 , 16 ) ;
V_174 += V_188 / 8 ;
}
return V_174 ;
}
static int F_68 ( struct V_10 * V_11 , T_3 V_164 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_197 ;
T_4 V_198 ;
T_3 V_199 ;
int V_6 ;
switch ( V_164 ) {
case V_200 :
return F_63 ( V_11 , V_12 ) ;
case V_159 :
V_6 = F_64 ( V_2 , V_12 + V_110 , & V_198 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( F_69 ( V_198 ) ) {
F_67 ( V_2 , V_20 , & V_197 ) ;
V_11 -> V_201 = ( V_197 != 0 ) ;
return V_109 ;
} else
return V_202 ;
case V_162 :
V_6 = F_70 ( V_2 , V_12 + V_23 , & V_199 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_199 ;
case V_160 :
F_67 ( V_2 , V_20 , & V_197 ) ;
V_11 -> V_201 = ( V_197 != 0 ) ;
if ( ( F_71 ( V_2 ) & V_203 ) == 1 )
return V_204 ;
else
return V_112 ;
case V_205 :
V_6 = F_70 ( V_2 , V_12 + 3 , & V_199 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return ( V_199 & V_206 ) ?
V_207 : V_208 ;
case V_209 :
V_6 = F_70 ( V_2 , V_12 + V_210 , & V_199 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_199 &= V_211 ;
if ( V_199 == V_212 )
return V_213 ;
else
return V_214 ;
default:
F_72 ( L_2 ,
F_31 ( & V_2 -> V_37 ) , V_36 , V_164 , V_12 ) ;
}
return 0 ;
}
static int F_73 ( struct V_10 * V_11 , T_4 V_215 , T_4 V_216 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_199 ;
T_2 V_197 ;
int V_6 ;
switch ( V_215 ) {
case V_163 :
V_6 = F_67 ( V_2 , V_216 + V_217 , & V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
return V_197 >> V_218 ;
case V_219 :
case V_220 :
case V_221 :
return F_66 ( V_11 , V_216 ) ;
case V_222 :
V_6 = F_70 ( V_2 , V_216 + V_223 , & V_199 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( V_199 & V_224 ) {
int V_225 ;
V_6 = F_70 ( V_2 ,
V_216 + V_226 ,
& V_199 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_225 = V_199 ? F_23 ( V_199 , 32 ) : 256 ;
return 8 + ( V_225 / 8 ) ;
}
return 8 ;
case V_227 :
V_6 = F_70 ( V_2 , V_216 + V_228 , & V_199 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_199 &= V_229 ;
V_199 >>= V_230 ;
return 4 + ( V_199 * 8 ) ;
case V_231 :
V_6 = F_70 ( V_2 , V_216 + V_232 , & V_199 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
V_199 &= V_233 ;
return V_234 + V_199 + 1 ;
case V_235 :
V_6 = F_67 ( V_2 , V_216 + V_236 , & V_197 ) ;
if ( V_6 )
return F_6 ( V_6 ) ;
if ( ( V_197 & V_237 ) == V_238 ) {
int V_239 ;
V_239 = V_197 & V_240 ;
V_239 >>= V_241 ;
return V_242 + ( V_239 * 2 ) + 2 ;
}
return V_242 ;
default:
F_72 ( L_3 ,
F_31 ( & V_2 -> V_37 ) , V_36 , V_215 , V_216 ) ;
}
return 0 ;
}
static int F_74 ( struct V_10 * V_11 ,
int V_3 , int V_25 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_6 = 0 ;
while ( V_25 ) {
int V_243 ;
if ( V_25 >= 4 && ! ( V_3 % 4 ) ) {
T_1 * V_244 = ( T_1 * ) & V_11 -> V_16 [ V_3 ] ;
T_2 V_197 ;
V_6 = F_67 ( V_2 , V_3 , & V_197 ) ;
if ( V_6 )
return V_6 ;
* V_244 = F_5 ( V_197 ) ;
V_243 = 4 ;
} else if ( V_25 >= 2 && ! ( V_3 % 2 ) ) {
V_32 * V_245 = ( V_32 * ) & V_11 -> V_16 [ V_3 ] ;
T_4 V_198 ;
V_6 = F_64 ( V_2 , V_3 , & V_198 ) ;
if ( V_6 )
return V_6 ;
* V_245 = F_27 ( V_198 ) ;
V_243 = 2 ;
} else {
T_3 * V_199 = & V_11 -> V_16 [ V_3 ] ;
V_6 = F_70 ( V_2 , V_3 , V_199 ) ;
if ( V_6 )
return V_6 ;
V_243 = 1 ;
}
V_3 += V_243 ;
V_25 -= V_243 ;
}
return V_6 ;
}
static int F_75 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_246 = V_11 -> V_166 ;
T_4 V_247 ;
T_3 V_12 , * V_248 , V_164 ;
int V_249 , V_6 , V_250 = 0 ;
V_6 = F_64 ( V_2 , V_79 , & V_247 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_247 & V_80 ) )
return 0 ;
V_6 = F_70 ( V_2 , V_89 , & V_12 ) ;
if ( V_6 )
return V_6 ;
V_248 = & V_11 -> V_16 [ V_89 ] ;
V_249 = ( V_20 - V_21 ) / V_251 ;
while ( V_12 && V_249 -- ) {
T_3 V_252 ;
int V_34 , V_174 = 0 ;
V_6 = F_70 ( V_2 , V_12 , & V_164 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_70 ( V_2 ,
V_12 + V_24 , & V_252 ) ;
if ( V_6 )
return V_6 ;
if ( V_164 <= V_253 ) {
V_174 = V_99 [ V_164 ] ;
if ( V_174 == 0xFF ) {
V_174 = F_68 ( V_11 , V_164 , V_12 ) ;
if ( V_174 < 0 )
return V_174 ;
}
}
if ( ! V_174 ) {
F_30 ( L_4 ,
V_36 , F_31 ( & V_2 -> V_37 ) , V_164 ) ;
* V_248 = V_252 ;
V_12 = V_252 ;
continue;
}
for ( V_34 = 0 ; V_34 < V_174 ; V_34 ++ ) {
if ( F_76 ( V_246 [ V_12 + V_34 ] == V_254 ) )
continue;
F_72 ( L_5 ,
V_36 , F_31 ( & V_2 -> V_37 ) ,
V_12 + V_34 , V_246 [ V_12 + V_34 ] , V_164 ) ;
}
F_77 ( V_253 >= V_255 ) ;
memset ( V_246 + V_12 , V_164 , V_174 ) ;
V_6 = F_74 ( V_11 , V_12 , V_174 ) ;
if ( V_6 )
return V_6 ;
V_248 = & V_11 -> V_16 [ V_12 + V_24 ] ;
V_12 = V_252 ;
V_250 ++ ;
}
if ( ! V_250 ) {
V_32 * V_256 = ( V_32 * ) & V_11 -> V_16 [ V_79 ] ;
* V_256 &= ~ F_27 ( V_80 ) ;
}
return 0 ;
}
static int F_78 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_246 = V_11 -> V_166 ;
T_4 V_216 ;
T_1 * V_248 = NULL ;
int V_249 , V_6 , V_257 = 0 ;
if ( ! V_11 -> V_201 )
return 0 ;
V_216 = V_20 ;
V_249 = ( V_2 -> V_258 - V_20 ) / V_251 ;
while ( V_249 -- && V_216 >= V_20 ) {
T_2 V_259 ;
T_4 V_215 ;
int V_34 , V_174 = 0 ;
bool V_260 = false ;
V_6 = F_67 ( V_2 , V_216 , & V_259 ) ;
if ( V_6 )
return V_6 ;
V_215 = F_79 ( V_259 ) ;
if ( V_215 <= V_261 ) {
V_174 = V_120 [ V_215 ] ;
if ( V_174 == 0xFF ) {
V_174 = F_73 ( V_11 , V_215 , V_216 ) ;
if ( V_174 < 0 )
return V_6 ;
}
}
if ( ! V_174 ) {
F_30 ( L_6 ,
V_36 , F_31 ( & V_2 -> V_37 ) , V_215 , V_216 ) ;
if ( V_248 ) {
T_2 V_4 = V_216 = F_80 ( V_259 ) ;
* V_248 &= F_5 ( ~ ( 0xffcU << 20 ) ) ;
* V_248 |= F_5 ( V_4 << 20 ) ;
continue;
}
V_174 = V_251 ;
V_260 = true ;
}
for ( V_34 = 0 ; V_34 < V_174 ; V_34 ++ ) {
if ( F_76 ( V_246 [ V_216 + V_34 ] == V_254 ) )
continue;
F_72 ( L_7 ,
V_36 , F_31 ( & V_2 -> V_37 ) ,
V_216 + V_34 , V_246 [ V_216 + V_34 ] , V_215 ) ;
}
F_77 ( V_261 >= V_255 ) ;
memset ( V_246 + V_216 , V_215 , V_174 ) ;
V_6 = F_74 ( V_11 , V_216 , V_174 ) ;
if ( V_6 )
return V_6 ;
if ( V_260 )
* ( T_1 * ) & V_11 -> V_16 [ V_216 ] &=
F_5 ( ( 0xffcU << 20 ) ) ;
else
V_257 ++ ;
V_248 = ( T_1 * ) & V_11 -> V_16 [ V_216 ] ;
V_216 = F_80 ( V_259 ) ;
}
if ( ! V_257 )
* ( T_2 * ) & V_11 -> V_16 [ V_20 ] = 0 ;
return 0 ;
}
int F_81 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_246 , * V_16 ;
int V_6 ;
V_246 = F_65 ( V_2 -> V_258 , V_26 ) ;
if ( ! V_246 )
return - V_27 ;
V_16 = F_65 ( V_2 -> V_258 , V_26 ) ;
if ( ! V_16 ) {
F_21 ( V_246 ) ;
return - V_27 ;
}
V_11 -> V_166 = V_246 ;
V_11 -> V_16 = V_16 ;
memset ( V_246 , V_158 , V_21 ) ;
memset ( V_246 + V_21 , V_254 ,
V_2 -> V_258 - V_21 ) ;
V_6 = F_74 ( V_11 , 0 , V_21 ) ;
if ( V_6 )
goto V_262;
V_11 -> V_57 = true ;
V_11 -> V_33 [ 0 ] = F_8 ( * ( T_1 * ) & V_16 [ V_38 ] ) ;
V_11 -> V_33 [ 1 ] = F_8 ( * ( T_1 * ) & V_16 [ V_85 ] ) ;
V_11 -> V_33 [ 2 ] = F_8 ( * ( T_1 * ) & V_16 [ V_86 ] ) ;
V_11 -> V_33 [ 3 ] = F_8 ( * ( T_1 * ) & V_16 [ V_87 ] ) ;
V_11 -> V_33 [ 4 ] = F_8 ( * ( T_1 * ) & V_16 [ V_88 ] ) ;
V_11 -> V_33 [ 5 ] = F_8 ( * ( T_1 * ) & V_16 [ V_39 ] ) ;
V_11 -> V_33 [ 6 ] = F_8 ( * ( T_1 * ) & V_16 [ V_40 ] ) ;
if ( V_2 -> V_35 ) {
* ( V_32 * ) & V_16 [ V_74 ] = F_27 ( V_2 -> V_263 ) ;
* ( V_32 * ) & V_16 [ V_77 ] = F_27 ( V_2 -> V_264 ) ;
}
if ( ! F_82 ( V_265 ) )
V_16 [ V_91 ] = 0 ;
V_6 = F_75 ( V_11 ) ;
if ( V_6 )
goto V_262;
V_6 = F_78 ( V_11 ) ;
if ( V_6 )
goto V_262;
return 0 ;
V_262:
F_21 ( V_246 ) ;
V_11 -> V_166 = NULL ;
F_21 ( V_16 ) ;
V_11 -> V_16 = NULL ;
return F_6 ( V_6 ) ;
}
void F_83 ( struct V_10 * V_11 )
{
F_21 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
F_21 ( V_11 -> V_166 ) ;
V_11 -> V_166 = NULL ;
F_21 ( V_11 -> V_185 ) ;
V_11 -> V_185 = NULL ;
}
static T_8 F_84 ( struct V_10 * V_11 ,
T_9 V_12 )
{
T_3 V_164 = V_11 -> V_166 [ V_12 ] ;
T_8 V_34 ;
for ( V_34 = 1 ; ( V_12 + V_34 ) % 4 && V_11 -> V_166 [ V_12 + V_34 ] == V_164 ; V_34 ++ )
;
return V_34 ;
}
static T_10 F_85 ( struct V_10 * V_11 , char T_11 * V_266 ,
T_8 V_5 , T_9 * V_267 , bool V_268 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_13 * V_14 ;
T_1 V_4 = 0 ;
int V_269 = 0 , V_3 ;
T_3 V_270 ;
T_10 V_6 ;
if ( * V_267 < 0 || * V_267 >= V_2 -> V_258 ||
* V_267 + V_5 > V_2 -> V_258 )
return - V_271 ;
V_5 = F_15 ( V_5 , F_84 ( V_11 , * V_267 ) ) ;
if ( V_5 >= 4 && ! ( * V_267 % 4 ) )
V_5 = 4 ;
else if ( V_5 >= 2 && ! ( * V_267 % 2 ) )
V_5 = 2 ;
else
V_5 = 1 ;
V_6 = V_5 ;
V_270 = V_11 -> V_166 [ * V_267 ] ;
if ( V_270 == V_254 ) {
V_14 = & V_272 ;
V_269 = * V_267 ;
} else if ( V_270 == V_255 ) {
V_14 = & V_273 ;
V_269 = * V_267 ;
} else {
if ( * V_267 >= V_20 ) {
F_86 ( V_270 > V_261 ) ;
V_14 = & V_161 [ V_270 ] ;
V_269 = F_58 ( V_11 , * V_267 ) ;
} else {
F_86 ( V_270 > V_253 ) ;
V_14 = & V_157 [ V_270 ] ;
if ( V_270 == V_200 )
V_14 = V_11 -> V_185 ;
if ( V_270 > V_158 )
V_269 = F_58 ( V_11 , * V_267 ) ;
}
}
F_86 ( ! V_269 && V_270 != V_158 ) ;
F_86 ( V_269 > * V_267 ) ;
V_3 = * V_267 - V_269 ;
if ( V_268 ) {
if ( ! V_14 -> V_29 )
return V_6 ;
if ( F_87 ( & V_4 , V_266 , V_5 ) )
return - V_271 ;
V_6 = V_14 -> V_29 ( V_11 , * V_267 , V_5 , V_14 , V_3 , V_4 ) ;
} else {
if ( V_14 -> V_28 ) {
V_6 = V_14 -> V_28 ( V_11 , * V_267 , V_5 ,
V_14 , V_3 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( F_88 ( V_266 , & V_4 , V_5 ) )
return - V_271 ;
}
return V_6 ;
}
T_10 F_89 ( struct V_10 * V_11 , char T_11 * V_266 ,
T_8 V_5 , T_9 * V_267 , bool V_268 )
{
T_8 V_274 = 0 ;
int V_6 = 0 ;
T_9 V_12 = * V_267 ;
V_12 &= V_275 ;
while ( V_5 ) {
V_6 = F_85 ( V_11 , V_266 , V_5 , & V_12 , V_268 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -= V_6 ;
V_274 += V_6 ;
V_266 += V_6 ;
V_12 += V_6 ;
}
* V_267 += V_274 ;
return V_274 ;
}
