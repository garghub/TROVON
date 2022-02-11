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
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , int V_5 )
{
int V_6 = - V_7 ;
T_2 V_8 = F_7 ( V_4 ) ;
switch ( V_5 ) {
case 1 :
V_6 = F_8 ( V_2 , V_3 , V_8 ) ;
break;
case 2 :
V_6 = F_9 ( V_2 , V_3 , V_8 ) ;
break;
case 4 :
V_6 = F_10 ( V_2 , V_3 , V_8 ) ;
break;
}
return V_6 ;
}
static int F_11 ( struct V_10 * V_11 , int V_12 ,
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
static int F_12 ( struct V_10 * V_11 , int V_12 ,
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
V_6 = F_6 ( V_2 , V_12 , V_17 , V_5 ) ;
if ( V_6 )
return V_6 ;
}
return V_5 ;
}
static int F_13 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
int V_6 ;
V_6 = F_1 ( V_11 -> V_2 , V_12 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
if ( V_12 >= V_20 ) {
if ( V_3 < 4 )
memcpy ( V_4 , V_11 -> V_16 + V_12 , V_5 ) ;
} else if ( V_12 >= V_21 ) {
if ( V_3 == V_22 && V_5 > 1 )
memcpy ( V_4 , V_11 -> V_16 + V_12 ,
F_14 ( V_23 , V_5 ) ) ;
else if ( V_3 == V_24 )
memcpy ( V_4 , V_11 -> V_16 + V_12 , 1 ) ;
}
return V_5 ;
}
static int F_15 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
int V_6 ;
V_6 = F_6 ( V_11 -> V_2 , V_12 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
return V_5 ;
}
static int F_16 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
int V_6 ;
V_6 = F_1 ( V_11 -> V_2 , V_12 , V_4 , V_5 ) ;
if ( V_6 )
return V_6 ;
return V_5 ;
}
static int F_17 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
memcpy ( V_11 -> V_16 + V_12 , & V_4 , V_5 ) ;
return V_5 ;
}
static int F_18 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
memcpy ( V_4 , V_11 -> V_16 + V_12 , V_5 ) ;
return V_5 ;
}
static void F_19 ( struct V_13 * V_14 )
{
F_20 ( V_14 -> V_15 ) ;
F_20 ( V_14 -> V_18 ) ;
V_14 -> V_15 = NULL ;
V_14 -> V_18 = NULL ;
}
static int F_21 ( struct V_13 * V_14 , int V_25 )
{
V_25 = F_22 ( V_25 , 4 ) ;
V_14 -> V_15 = F_23 ( V_25 , V_26 ) ;
V_14 -> V_18 = F_23 ( V_25 , V_26 ) ;
if ( ! V_14 -> V_15 || ! V_14 -> V_18 ) {
F_19 ( V_14 ) ;
return - V_27 ;
}
V_14 -> V_28 = F_11 ;
V_14 -> V_29 = F_12 ;
return 0 ;
}
static inline void F_24 ( struct V_13 * V_30 , int V_31 , T_3 V_15 , T_3 V_18 )
{
V_30 -> V_15 [ V_31 ] = V_15 ;
V_30 -> V_18 [ V_31 ] = V_18 ;
}
static inline void F_25 ( struct V_13 * V_30 , int V_31 , T_4 V_15 , T_4 V_18 )
{
* ( V_32 * ) ( & V_30 -> V_15 [ V_31 ] ) = F_26 ( V_15 ) ;
* ( V_32 * ) ( & V_30 -> V_18 [ V_31 ] ) = F_26 ( V_18 ) ;
}
static inline void F_27 ( struct V_13 * V_30 , int V_31 , T_2 V_15 , T_2 V_18 )
{
* ( T_1 * ) ( & V_30 -> V_15 [ V_31 ] ) = F_5 ( V_15 ) ;
* ( T_1 * ) ( & V_30 -> V_18 [ V_31 ] ) = F_5 ( V_18 ) ;
}
static void F_28 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 * V_33 = V_11 -> V_33 ;
T_4 V_34 ;
int V_35 ;
if ( V_2 -> V_36 )
return;
F_29 ( L_1 ,
V_37 , F_30 ( & V_2 -> V_38 ) ) ;
for ( V_35 = V_39 ; V_35 <= V_40 ; V_35 += 4 , V_33 ++ )
F_10 ( V_2 , V_35 , * V_33 ) ;
F_10 ( V_2 , V_41 , * V_33 ) ;
if ( V_11 -> V_42 ) {
F_3 ( V_2 , V_43 , & V_34 ) ;
V_34 |= V_44 ;
F_9 ( V_2 , V_43 , V_34 ) ;
}
}
static T_1 F_31 ( struct V_1 * V_2 , int V_45 )
{
unsigned long V_46 = F_32 ( V_2 , V_45 ) ;
T_2 V_4 ;
if ( V_46 & V_47 )
return F_5 ( V_48 ) ;
V_4 = V_49 ;
if ( V_46 & V_50 )
V_4 |= V_51 ;
if ( V_46 & V_52 )
V_4 |= V_53 ;
return F_5 ( V_4 ) ;
}
static void F_33 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_35 ;
T_1 * V_45 ;
T_5 V_54 ;
V_45 = ( T_1 * ) & V_11 -> V_16 [ V_39 ] ;
for ( V_35 = V_55 ; V_35 <= V_56 ; V_35 ++ , V_45 ++ ) {
if ( ! F_34 ( V_2 , V_35 ) ) {
* V_45 = 0 ;
continue;
}
V_54 = ~ ( F_35 ( V_2 , V_35 ) - 1 ) ;
* V_45 &= F_5 ( ( T_2 ) V_54 ) ;
* V_45 |= F_31 ( V_2 , V_35 ) ;
if ( * V_45 & F_5 ( V_53 ) ) {
V_45 ++ ;
* V_45 &= F_5 ( ( T_2 ) ( V_54 >> 32 ) ) ;
V_35 ++ ;
}
}
V_45 = ( T_1 * ) & V_11 -> V_16 [ V_41 ] ;
if ( F_34 ( V_2 , V_57 ) ) {
V_54 = ~ ( F_35 ( V_2 , V_57 ) - 1 ) ;
V_54 |= V_58 ;
* V_45 &= F_5 ( ( T_2 ) V_54 ) ;
} else if ( V_2 -> V_59 [ V_57 ] . V_46 &
V_60 ) {
V_54 = ~ ( 0x20000 - 1 ) ;
V_54 |= V_58 ;
* V_45 &= F_5 ( ( T_2 ) V_54 ) ;
} else
* V_45 = 0 ;
V_11 -> V_61 = false ;
}
static int F_36 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( F_37 ( V_3 ) )
F_33 ( V_11 ) ;
V_5 = F_11 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_3 == V_43 && V_11 -> V_2 -> V_36 ) {
T_4 V_34 = F_38 ( * ( V_32 * ) & V_11 -> V_16 [ V_43 ] ) ;
T_2 V_8 = F_7 ( * V_4 ) ;
V_8 |= V_34 & V_62 ;
* V_4 = F_5 ( V_8 ) ;
}
return V_5 ;
}
static bool F_39 ( struct V_10 * V_11 )
{
int V_35 = 0 , V_12 = V_39 , V_6 ;
T_2 V_45 ;
for (; V_12 <= V_40 ; V_35 ++ , V_12 += 4 ) {
if ( V_11 -> V_33 [ V_35 ] ) {
V_6 = F_4 ( V_11 -> V_2 , V_12 , & V_45 ) ;
if ( V_6 || V_11 -> V_33 [ V_35 ] != V_45 )
return true ;
}
}
return false ;
}
static int F_40 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_32 * V_63 ;
T_4 V_64 = 0 ;
int V_6 ;
V_63 = ( V_32 * ) & V_11 -> V_16 [ V_43 ] ;
if ( V_3 == V_43 ) {
bool V_65 , V_66 , V_67 , V_68 , V_69 , V_70 ;
T_4 V_71 ;
V_6 = F_3 ( V_2 , V_43 , & V_71 ) ;
if ( V_6 )
return V_6 ;
V_64 = F_7 ( V_4 ) ;
V_65 = ! ! ( V_71 & V_62 ) ;
V_66 = ! ! ( F_38 ( * V_63 ) & V_62 ) ;
V_67 = ! ! ( V_64 & V_62 ) ;
V_68 = ! ! ( V_71 & V_72 ) ;
V_69 = ! ! ( F_38 ( * V_63 ) & V_72 ) ;
V_70 = ! ! ( V_64 & V_72 ) ;
if ( ( V_67 && V_66 && ! V_65 ) ||
( V_70 && V_69 && ! V_68 ) ||
F_39 ( V_11 ) )
F_28 ( V_11 ) ;
}
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 == V_43 ) {
T_4 V_54 = V_62 | V_72 ;
* V_63 &= F_26 ( ~ V_54 ) ;
* V_63 |= F_26 ( V_64 & V_54 ) ;
}
if ( V_3 >= V_43 && V_3 <= V_43 + 1 ) {
bool V_73 ;
V_73 = ! ! ( F_38 ( * V_63 ) &
V_44 ) ;
if ( V_73 && ! V_11 -> V_74 ) {
V_11 -> V_74 = true ;
F_41 ( V_11 ) ;
} else if ( ! V_73 && V_11 -> V_74 ) {
V_11 -> V_74 = false ;
F_42 ( V_11 ) ;
}
}
if ( F_37 ( V_3 ) )
V_11 -> V_61 = true ;
return V_5 ;
}
static int T_6 F_43 ( struct V_13 * V_14 )
{
if ( F_21 ( V_14 , V_21 ) )
return - V_27 ;
V_14 -> V_28 = F_36 ;
V_14 -> V_29 = F_40 ;
F_25 ( V_14 , V_75 , ( T_4 ) V_76 , V_77 ) ;
F_25 ( V_14 , V_78 , ( T_4 ) V_76 , V_77 ) ;
F_25 ( V_14 , V_43 , V_44 , ( T_4 ) V_79 ) ;
F_25 ( V_14 , V_80 , V_81 , V_77 ) ;
F_24 ( V_14 , V_82 , V_83 , ( T_3 ) V_79 ) ;
F_24 ( V_14 , V_84 , V_83 , ( T_3 ) V_79 ) ;
F_24 ( V_14 , V_85 , V_83 , ( T_3 ) V_79 ) ;
F_27 ( V_14 , V_39 , V_76 , V_79 ) ;
F_27 ( V_14 , V_86 , V_76 , V_79 ) ;
F_27 ( V_14 , V_87 , V_76 , V_79 ) ;
F_27 ( V_14 , V_88 , V_76 , V_79 ) ;
F_27 ( V_14 , V_89 , V_76 , V_79 ) ;
F_27 ( V_14 , V_40 , V_76 , V_79 ) ;
F_27 ( V_14 , V_41 , V_76 , V_79 ) ;
F_24 ( V_14 , V_90 , ( T_3 ) V_76 , V_77 ) ;
F_24 ( V_14 , V_91 , ( T_3 ) V_76 , ( T_3 ) V_79 ) ;
F_24 ( V_14 , V_92 , ( T_3 ) V_76 , ( T_3 ) V_77 ) ;
return 0 ;
}
static int F_44 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 == V_93 ) {
T_7 V_94 ;
switch ( F_7 ( V_4 ) & V_95 ) {
case 0 :
V_94 = V_96 ;
break;
case 1 :
V_94 = V_97 ;
break;
case 2 :
V_94 = V_98 ;
break;
case 3 :
V_94 = V_99 ;
break;
}
F_45 ( V_11 -> V_2 , V_94 ) ;
}
return V_5 ;
}
static int T_6 F_46 ( struct V_13 * V_14 )
{
if ( F_21 ( V_14 , V_100 [ V_101 ] ) )
return - V_27 ;
V_14 -> V_29 = F_44 ;
F_24 ( V_14 , V_24 , ( T_3 ) V_76 , V_77 ) ;
F_27 ( V_14 , V_93 , V_83 , ~ V_95 ) ;
return 0 ;
}
static int F_47 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
V_32 * V_102 = ( V_32 * ) ( V_11 -> V_16 + V_12 - V_3 + V_103 ) ;
T_1 * V_104 = ( T_1 * ) ( V_11 -> V_16 + V_12 - V_3 + V_105 ) ;
T_4 V_106 ;
T_2 V_107 ;
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 || V_3 > V_103 + 1 ||
V_3 + V_5 <= V_103 + 1 )
return V_5 ;
V_106 = F_38 ( * V_102 ) ;
if ( V_106 & V_108 ) {
V_107 = F_7 ( * V_104 ) ;
if ( F_48 ( V_2 , V_106 & ~ V_108 , 4 , & V_107 ) != 4 )
return V_5 ;
} else {
V_107 = 0 ;
if ( F_49 ( V_2 , V_106 , 4 , & V_107 ) < 0 )
return V_5 ;
* V_104 = F_5 ( V_107 ) ;
}
V_106 ^= V_108 ;
* V_102 = F_26 ( V_106 ) ;
return V_5 ;
}
static int T_6 F_50 ( struct V_13 * V_14 )
{
if ( F_21 ( V_14 , V_100 [ V_109 ] ) )
return - V_27 ;
V_14 -> V_29 = F_47 ;
F_24 ( V_14 , V_24 , ( T_3 ) V_76 , V_77 ) ;
F_25 ( V_14 , V_103 , ( T_4 ) V_76 , ( T_4 ) V_79 ) ;
F_27 ( V_14 , V_105 , V_76 , V_79 ) ;
return 0 ;
}
static int T_6 F_51 ( struct V_13 * V_14 )
{
if ( F_21 ( V_14 , V_110 ) )
return - V_27 ;
F_24 ( V_14 , V_24 , ( T_3 ) V_76 , V_77 ) ;
F_25 ( V_14 , V_111 , V_83 , ( T_4 ) V_79 ) ;
F_27 ( V_14 , V_112 , V_83 , V_79 ) ;
return 0 ;
}
static int F_52 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_32 * V_113 = ( V_32 * ) ( V_11 -> V_16 + V_12 -
V_3 + V_114 ) ;
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( * V_113 & F_26 ( V_115 ) ) {
T_2 V_116 ;
int V_6 ;
* V_113 &= ~ F_26 ( V_115 ) ;
V_6 = F_4 ( V_11 -> V_2 ,
V_12 - V_3 + V_117 ,
& V_116 ) ;
if ( ! V_6 && ( V_116 & V_118 ) )
F_53 ( V_11 -> V_2 ) ;
}
return V_5 ;
}
static int T_6 F_54 ( struct V_13 * V_14 )
{
if ( F_21 ( V_14 , V_119 ) )
return - V_27 ;
V_14 -> V_29 = F_52 ;
F_24 ( V_14 , V_24 , ( T_3 ) V_76 , V_77 ) ;
F_25 ( V_14 , V_114 ,
V_115 , ~ V_120 ) ;
F_25 ( V_14 , V_121 , V_83 , ~ V_122 ) ;
return 0 ;
}
static int F_55 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
T_3 * V_113 = V_11 -> V_16 + V_12 - V_3 + V_123 ;
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( * V_113 & V_124 ) {
T_3 V_116 ;
int V_6 ;
* V_113 &= ~ V_124 ;
V_6 = F_2 ( V_11 -> V_2 ,
V_12 - V_3 + V_125 ,
& V_116 ) ;
if ( ! V_6 && ( V_116 & V_126 ) && ( V_116 & V_127 ) )
F_53 ( V_11 -> V_2 ) ;
}
return V_5 ;
}
static int T_6 F_56 ( struct V_13 * V_14 )
{
if ( F_21 ( V_14 , V_100 [ V_128 ] ) )
return - V_27 ;
V_14 -> V_29 = F_55 ;
F_24 ( V_14 , V_24 , ( T_3 ) V_76 , V_77 ) ;
F_24 ( V_14 , V_123 , V_124 , V_124 ) ;
return 0 ;
}
static int T_6 F_57 ( struct V_13 * V_14 )
{
T_2 V_54 ;
if ( F_21 ( V_14 , V_129 [ V_130 ] ) )
return - V_27 ;
F_27 ( V_14 , 0 , V_76 , V_77 ) ;
V_54 = V_131 |
V_132 |
V_133 |
V_134 |
V_135 |
V_136 |
V_137 |
V_138 |
V_139 |
V_140 |
V_141 |
V_142 |
V_143 |
V_144 |
V_145 |
V_146 |
V_147 ;
F_27 ( V_14 , V_148 , V_83 , V_54 ) ;
F_27 ( V_14 , V_149 , V_83 , V_54 ) ;
F_27 ( V_14 , V_150 , V_83 , V_54 ) ;
V_54 = V_151 |
V_152 |
V_153 |
V_154 |
V_155 |
V_156 |
V_157 |
V_158 ;
F_27 ( V_14 , V_159 , V_83 , V_54 ) ;
F_27 ( V_14 , V_160 , V_83 , V_54 ) ;
V_54 = V_161 |
V_162 ;
F_27 ( V_14 , V_163 , V_83 , V_54 ) ;
return 0 ;
}
static int T_6 F_58 ( struct V_13 * V_14 )
{
if ( F_21 ( V_14 , V_129 [ V_164 ] ) )
return - V_27 ;
F_27 ( V_14 , 0 , V_76 , V_77 ) ;
F_24 ( V_14 , V_165 , V_83 , ( T_3 ) V_79 ) ;
return 0 ;
}
void F_59 ( void )
{
F_19 ( & V_166 [ V_167 ] ) ;
F_19 ( & V_166 [ V_101 ] ) ;
F_19 ( & V_166 [ V_109 ] ) ;
F_19 ( & V_166 [ V_168 ] ) ;
F_19 ( & V_166 [ V_169 ] ) ;
F_19 ( & V_166 [ V_128 ] ) ;
F_19 ( & V_170 [ V_130 ] ) ;
F_19 ( & V_170 [ V_164 ] ) ;
}
int T_6 F_60 ( void )
{
int V_6 ;
V_6 = F_43 ( & V_166 [ V_167 ] ) ;
V_6 |= F_46 ( & V_166 [ V_101 ] ) ;
V_6 |= F_50 ( & V_166 [ V_109 ] ) ;
V_6 |= F_51 ( & V_166 [ V_168 ] ) ;
V_166 [ V_171 ] . V_29 = F_15 ;
V_6 |= F_54 ( & V_166 [ V_169 ] ) ;
V_6 |= F_56 ( & V_166 [ V_128 ] ) ;
V_6 |= F_57 ( & V_170 [ V_130 ] ) ;
V_6 |= F_58 ( & V_170 [ V_164 ] ) ;
V_170 [ V_172 ] . V_29 = F_15 ;
if ( V_6 )
F_59 () ;
return V_6 ;
}
static int F_61 ( struct V_10 * V_11 , int V_12 )
{
T_3 V_116 ;
int V_173 = ( V_12 >= V_20 ) ? V_20 :
V_21 ;
V_116 = V_11 -> V_174 [ V_12 ] ;
if ( V_116 == V_167 )
return 0 ;
while ( V_12 - 1 >= V_173 && V_11 -> V_174 [ V_12 - 1 ] == V_116 )
V_12 -- ;
return V_12 ;
}
static int F_62 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 * V_4 )
{
if ( V_3 <= V_175 && V_3 + V_5 >= V_175 ) {
V_32 * V_46 ;
int V_176 ;
V_176 = F_61 ( V_11 , V_12 ) ;
V_46 = ( V_32 * ) & V_11 -> V_16 [ V_176 ] ;
* V_46 &= F_26 ( ~ V_177 ) ;
* V_46 |= F_26 ( V_11 -> V_178 << 1 ) ;
}
return F_11 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
}
static int F_63 ( struct V_10 * V_11 , int V_12 ,
int V_5 , struct V_13 * V_14 ,
int V_3 , T_1 V_4 )
{
V_5 = F_12 ( V_11 , V_12 , V_5 , V_14 , V_3 , V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_3 <= V_175 && V_3 + V_5 >= V_175 ) {
V_32 * V_179 ;
T_4 V_46 ;
int V_176 , V_6 ;
V_176 = F_61 ( V_11 , V_12 ) ;
V_179 = ( V_32 * ) & V_11 -> V_16 [ V_176 + V_175 ] ;
V_46 = F_38 ( * V_179 ) ;
if ( ! F_64 ( V_11 ) )
V_46 &= ~ V_180 ;
if ( ( V_46 & V_181 ) >> 4 > V_11 -> V_178 ) {
V_46 &= ~ V_181 ;
V_46 |= V_11 -> V_178 << 4 ;
}
* V_179 = F_26 ( V_46 ) ;
V_6 = F_9 ( V_11 -> V_2 ,
V_176 + V_175 ,
V_46 ) ;
if ( V_6 )
return V_6 ;
}
return V_5 ;
}
static int F_65 ( struct V_13 * V_14 , int V_182 , T_4 V_46 )
{
if ( F_21 ( V_14 , V_182 ) )
return - V_27 ;
V_14 -> V_28 = F_62 ;
V_14 -> V_29 = F_63 ;
F_24 ( V_14 , V_24 , ( T_3 ) V_76 , V_77 ) ;
F_24 ( V_14 , V_175 , ( T_3 ) V_76 , ( T_3 ) V_79 ) ;
F_27 ( V_14 , V_183 , V_76 , V_79 ) ;
if ( V_46 & V_184 ) {
F_27 ( V_14 , V_185 , V_76 , V_79 ) ;
F_25 ( V_14 , V_186 , ( T_4 ) V_76 , ( T_4 ) V_79 ) ;
if ( V_46 & V_187 ) {
F_27 ( V_14 , V_188 , V_83 , V_79 ) ;
F_27 ( V_14 , V_189 , V_83 , V_79 ) ;
}
} else {
F_25 ( V_14 , V_190 , ( T_4 ) V_76 , ( T_4 ) V_79 ) ;
if ( V_46 & V_187 ) {
F_27 ( V_14 , V_191 , V_83 , V_79 ) ;
F_27 ( V_14 , V_192 , V_83 , V_79 ) ;
}
}
return 0 ;
}
static int F_66 ( struct V_10 * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_182 , V_6 ;
T_4 V_46 ;
V_6 = F_67 ( V_2 , V_12 + V_175 , & V_46 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
V_182 = 10 ;
if ( V_46 & V_184 )
V_182 += 4 ;
if ( V_46 & V_187 )
V_182 += 10 ;
if ( V_11 -> V_193 )
return V_182 ;
V_11 -> V_193 = F_69 ( sizeof( struct V_13 ) , V_26 ) ;
if ( ! V_11 -> V_193 )
return - V_27 ;
V_6 = F_65 ( V_11 -> V_193 , V_182 , V_46 ) ;
if ( V_6 )
return V_6 ;
return V_182 ;
}
static int F_70 ( struct V_10 * V_11 , T_4 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_9 ;
int V_6 , V_194 , V_195 , V_196 ;
int V_182 = V_197 ;
V_6 = F_71 ( V_2 , V_12 + V_198 , & V_9 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
V_194 = V_9 & V_199 ;
V_6 = F_71 ( V_2 , V_12 + V_200 , & V_9 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
if ( V_9 & V_201 )
V_195 = 128 ;
else if ( V_9 & V_202 )
V_195 = 64 ;
else if ( V_9 & V_203 )
V_195 = 32 ;
else
V_195 = 0 ;
V_196 = V_195 * 4 ;
V_182 += ( 1 + V_194 ) * V_204 ;
if ( V_196 ) {
V_182 = F_22 ( V_182 , 16 ) ;
V_182 += V_196 / 8 ;
}
return V_182 ;
}
static int F_72 ( struct V_10 * V_11 , T_3 V_116 , T_3 V_12 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_2 V_205 ;
T_4 V_206 ;
T_3 V_207 ;
int V_6 ;
switch ( V_116 ) {
case V_208 :
return F_66 ( V_11 , V_12 ) ;
case V_168 :
V_6 = F_67 ( V_2 , V_12 + V_111 , & V_206 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
if ( F_73 ( V_206 ) ) {
if ( V_2 -> V_209 > V_20 ) {
F_71 ( V_2 , V_20 ,
& V_205 ) ;
V_11 -> V_210 = ( V_205 != 0 ) ;
}
return V_110 ;
} else
return V_211 ;
case V_171 :
V_6 = F_74 ( V_2 , V_12 + V_23 , & V_207 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
return V_207 ;
case V_169 :
if ( V_2 -> V_209 > V_20 ) {
F_71 ( V_2 , V_20 , & V_205 ) ;
V_11 -> V_210 = ( V_205 != 0 ) ;
}
if ( ( F_75 ( V_2 ) & V_212 ) == 1 ) {
if ( F_76 ( V_2 ) == V_213 )
return 0xc ;
return V_214 ;
} else {
if ( F_76 ( V_2 ) == V_213 )
return 0x2c ;
return V_119 ;
}
case V_215 :
V_6 = F_74 ( V_2 , V_12 + 3 , & V_207 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
return ( V_207 & V_216 ) ?
V_217 : V_218 ;
case V_219 :
V_6 = F_74 ( V_2 , V_12 + V_220 , & V_207 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
V_207 &= V_221 ;
if ( V_207 == V_222 )
return V_223 ;
else
return V_224 ;
default:
F_77 ( L_2 ,
F_30 ( & V_2 -> V_38 ) , V_37 , V_116 , V_12 ) ;
}
return 0 ;
}
static int F_78 ( struct V_10 * V_11 , T_4 V_225 , T_4 V_226 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 V_207 ;
T_2 V_205 ;
int V_6 ;
switch ( V_225 ) {
case V_172 :
V_6 = F_71 ( V_2 , V_226 + V_227 , & V_205 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
return V_205 >> V_228 ;
case V_229 :
case V_230 :
case V_231 :
return F_70 ( V_11 , V_226 ) ;
case V_232 :
V_6 = F_74 ( V_2 , V_226 + V_233 , & V_207 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
if ( V_207 & V_234 ) {
int V_235 ;
V_6 = F_74 ( V_2 ,
V_226 + V_236 ,
& V_207 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
V_235 = V_207 ? F_22 ( V_207 , 32 ) : 256 ;
return 8 + ( V_235 / 8 ) ;
}
return 8 ;
case V_237 :
V_6 = F_74 ( V_2 , V_226 + V_238 , & V_207 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
V_207 &= V_239 ;
V_207 >>= V_240 ;
return 4 + ( V_207 * 8 ) ;
case V_241 :
V_6 = F_74 ( V_2 , V_226 + V_242 , & V_207 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
V_207 &= V_243 ;
return V_244 + V_207 + 1 ;
case V_245 :
V_6 = F_71 ( V_2 , V_226 + V_246 , & V_205 ) ;
if ( V_6 )
return F_68 ( V_6 ) ;
if ( ( V_205 & V_247 ) == V_248 ) {
int V_249 ;
V_249 = V_205 & V_250 ;
V_249 >>= V_251 ;
return V_252 + ( V_249 * 2 ) + 2 ;
}
return V_252 ;
default:
F_77 ( L_3 ,
F_30 ( & V_2 -> V_38 ) , V_37 , V_225 , V_226 ) ;
}
return 0 ;
}
static int F_79 ( struct V_10 * V_11 ,
int V_3 , int V_25 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
int V_6 = 0 ;
while ( V_25 ) {
int V_253 ;
if ( V_25 >= 4 && ! ( V_3 % 4 ) ) {
T_1 * V_254 = ( T_1 * ) & V_11 -> V_16 [ V_3 ] ;
T_2 V_205 ;
V_6 = F_71 ( V_2 , V_3 , & V_205 ) ;
if ( V_6 )
return V_6 ;
* V_254 = F_5 ( V_205 ) ;
V_253 = 4 ;
} else if ( V_25 >= 2 && ! ( V_3 % 2 ) ) {
V_32 * V_255 = ( V_32 * ) & V_11 -> V_16 [ V_3 ] ;
T_4 V_206 ;
V_6 = F_67 ( V_2 , V_3 , & V_206 ) ;
if ( V_6 )
return V_6 ;
* V_255 = F_26 ( V_206 ) ;
V_253 = 2 ;
} else {
T_3 * V_207 = & V_11 -> V_16 [ V_3 ] ;
V_6 = F_74 ( V_2 , V_3 , V_207 ) ;
if ( V_6 )
return V_6 ;
V_253 = 1 ;
}
V_3 += V_253 ;
V_25 -= V_253 ;
}
return V_6 ;
}
static int F_80 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_256 = V_11 -> V_174 ;
T_4 V_257 ;
T_3 V_12 , * V_258 , V_116 ;
int V_259 , V_6 , V_260 = 0 ;
V_6 = F_67 ( V_2 , V_80 , & V_257 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_257 & V_81 ) )
return 0 ;
V_6 = F_74 ( V_2 , V_90 , & V_12 ) ;
if ( V_6 )
return V_6 ;
V_258 = & V_11 -> V_16 [ V_90 ] ;
V_259 = ( V_20 - V_21 ) / V_261 ;
while ( V_12 && V_259 -- ) {
T_3 V_262 ;
int V_35 , V_182 = 0 ;
V_6 = F_74 ( V_2 , V_12 , & V_116 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_74 ( V_2 ,
V_12 + V_24 , & V_262 ) ;
if ( V_6 )
return V_6 ;
if ( V_116 <= V_263 ) {
V_182 = V_100 [ V_116 ] ;
if ( V_182 == 0xFF ) {
V_182 = F_72 ( V_11 , V_116 , V_12 ) ;
if ( V_182 < 0 )
return V_182 ;
}
}
if ( ! V_182 ) {
F_29 ( L_4 ,
V_37 , F_30 ( & V_2 -> V_38 ) , V_116 ) ;
* V_258 = V_262 ;
V_12 = V_262 ;
continue;
}
for ( V_35 = 0 ; V_35 < V_182 ; V_35 ++ ) {
if ( F_81 ( V_256 [ V_12 + V_35 ] == V_264 ) )
continue;
F_77 ( L_5 ,
V_37 , F_30 ( & V_2 -> V_38 ) ,
V_12 + V_35 , V_256 [ V_12 + V_35 ] , V_116 ) ;
}
F_82 ( V_263 >= V_265 ) ;
memset ( V_256 + V_12 , V_116 , V_182 ) ;
V_6 = F_79 ( V_11 , V_12 , V_182 ) ;
if ( V_6 )
return V_6 ;
V_258 = & V_11 -> V_16 [ V_12 + V_24 ] ;
V_12 = V_262 ;
V_260 ++ ;
}
if ( ! V_260 ) {
V_32 * V_266 = ( V_32 * ) & V_11 -> V_16 [ V_80 ] ;
* V_266 &= ~ F_26 ( V_81 ) ;
}
return 0 ;
}
static int F_83 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_256 = V_11 -> V_174 ;
T_4 V_226 ;
T_1 * V_258 = NULL ;
int V_259 , V_6 , V_267 = 0 ;
if ( ! V_11 -> V_210 )
return 0 ;
V_226 = V_20 ;
V_259 = ( V_2 -> V_209 - V_20 ) / V_261 ;
while ( V_259 -- && V_226 >= V_20 ) {
T_2 V_268 ;
T_4 V_225 ;
int V_35 , V_182 = 0 ;
bool V_269 = false ;
V_6 = F_71 ( V_2 , V_226 , & V_268 ) ;
if ( V_6 )
return V_6 ;
V_225 = F_84 ( V_268 ) ;
if ( V_225 <= V_270 ) {
V_182 = V_129 [ V_225 ] ;
if ( V_182 == 0xFF ) {
V_182 = F_78 ( V_11 , V_225 , V_226 ) ;
if ( V_182 < 0 )
return V_6 ;
}
}
if ( ! V_182 ) {
F_29 ( L_6 ,
V_37 , F_30 ( & V_2 -> V_38 ) , V_225 , V_226 ) ;
if ( V_258 ) {
T_2 V_4 = V_226 = F_85 ( V_268 ) ;
* V_258 &= F_5 ( ~ ( 0xffcU << 20 ) ) ;
* V_258 |= F_5 ( V_4 << 20 ) ;
continue;
}
V_182 = V_261 ;
V_269 = true ;
}
for ( V_35 = 0 ; V_35 < V_182 ; V_35 ++ ) {
if ( F_81 ( V_256 [ V_226 + V_35 ] == V_264 ) )
continue;
F_77 ( L_7 ,
V_37 , F_30 ( & V_2 -> V_38 ) ,
V_226 + V_35 , V_256 [ V_226 + V_35 ] , V_225 ) ;
}
F_82 ( V_270 >= V_265 ) ;
memset ( V_256 + V_226 , V_225 , V_182 ) ;
V_6 = F_79 ( V_11 , V_226 , V_182 ) ;
if ( V_6 )
return V_6 ;
if ( V_269 )
* ( T_1 * ) & V_11 -> V_16 [ V_226 ] &=
F_5 ( ( 0xffcU << 20 ) ) ;
else
V_267 ++ ;
V_258 = ( T_1 * ) & V_11 -> V_16 [ V_226 ] ;
V_226 = F_85 ( V_268 ) ;
}
if ( ! V_267 )
* ( T_2 * ) & V_11 -> V_16 [ V_20 ] = 0 ;
return 0 ;
}
int F_86 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_3 * V_256 , * V_16 ;
int V_6 ;
V_256 = F_69 ( V_2 -> V_209 , V_26 ) ;
if ( ! V_256 )
return - V_27 ;
V_16 = F_69 ( V_2 -> V_209 , V_26 ) ;
if ( ! V_16 ) {
F_20 ( V_256 ) ;
return - V_27 ;
}
V_11 -> V_174 = V_256 ;
V_11 -> V_16 = V_16 ;
memset ( V_256 , V_167 , V_21 ) ;
memset ( V_256 + V_21 , V_264 ,
V_2 -> V_209 - V_21 ) ;
V_6 = F_79 ( V_11 , 0 , V_21 ) ;
if ( V_6 )
goto V_271;
V_11 -> V_61 = true ;
V_11 -> V_33 [ 0 ] = F_7 ( * ( T_1 * ) & V_16 [ V_39 ] ) ;
V_11 -> V_33 [ 1 ] = F_7 ( * ( T_1 * ) & V_16 [ V_86 ] ) ;
V_11 -> V_33 [ 2 ] = F_7 ( * ( T_1 * ) & V_16 [ V_87 ] ) ;
V_11 -> V_33 [ 3 ] = F_7 ( * ( T_1 * ) & V_16 [ V_88 ] ) ;
V_11 -> V_33 [ 4 ] = F_7 ( * ( T_1 * ) & V_16 [ V_89 ] ) ;
V_11 -> V_33 [ 5 ] = F_7 ( * ( T_1 * ) & V_16 [ V_40 ] ) ;
V_11 -> V_33 [ 6 ] = F_7 ( * ( T_1 * ) & V_16 [ V_41 ] ) ;
if ( V_2 -> V_36 ) {
* ( V_32 * ) & V_16 [ V_75 ] = F_26 ( V_2 -> V_272 ) ;
* ( V_32 * ) & V_16 [ V_78 ] = F_26 ( V_2 -> V_273 ) ;
}
if ( ! F_87 ( V_274 ) || V_11 -> V_42 )
V_16 [ V_92 ] = 0 ;
V_6 = F_80 ( V_11 ) ;
if ( V_6 )
goto V_271;
V_6 = F_83 ( V_11 ) ;
if ( V_6 )
goto V_271;
return 0 ;
V_271:
F_20 ( V_256 ) ;
V_11 -> V_174 = NULL ;
F_20 ( V_16 ) ;
V_11 -> V_16 = NULL ;
return F_68 ( V_6 ) ;
}
void F_88 ( struct V_10 * V_11 )
{
F_20 ( V_11 -> V_16 ) ;
V_11 -> V_16 = NULL ;
F_20 ( V_11 -> V_174 ) ;
V_11 -> V_174 = NULL ;
F_20 ( V_11 -> V_193 ) ;
V_11 -> V_193 = NULL ;
}
static T_8 F_89 ( struct V_10 * V_11 ,
T_9 V_12 )
{
T_3 V_116 = V_11 -> V_174 [ V_12 ] ;
T_8 V_35 ;
for ( V_35 = 1 ; ( V_12 + V_35 ) % 4 && V_11 -> V_174 [ V_12 + V_35 ] == V_116 ; V_35 ++ )
;
return V_35 ;
}
static T_10 F_90 ( struct V_10 * V_11 , char T_11 * V_275 ,
T_8 V_5 , T_9 * V_276 , bool V_277 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_13 * V_14 ;
T_1 V_4 = 0 ;
int V_278 = 0 , V_3 ;
T_3 V_279 ;
T_10 V_6 ;
if ( * V_276 < 0 || * V_276 >= V_2 -> V_209 ||
* V_276 + V_5 > V_2 -> V_209 )
return - V_280 ;
V_5 = F_14 ( V_5 , F_89 ( V_11 , * V_276 ) ) ;
if ( V_5 >= 4 && ! ( * V_276 % 4 ) )
V_5 = 4 ;
else if ( V_5 >= 2 && ! ( * V_276 % 2 ) )
V_5 = 2 ;
else
V_5 = 1 ;
V_6 = V_5 ;
V_279 = V_11 -> V_174 [ * V_276 ] ;
if ( V_279 == V_264 ) {
V_14 = & V_281 ;
V_278 = * V_276 ;
} else if ( V_279 == V_265 ) {
V_14 = & V_282 ;
V_278 = * V_276 ;
} else {
if ( * V_276 >= V_20 ) {
F_91 ( V_279 > V_270 ) ;
V_14 = & V_170 [ V_279 ] ;
V_278 = F_61 ( V_11 , * V_276 ) ;
} else {
F_91 ( V_279 > V_263 ) ;
V_14 = & V_166 [ V_279 ] ;
if ( V_279 == V_208 )
V_14 = V_11 -> V_193 ;
if ( V_279 > V_167 )
V_278 = F_61 ( V_11 , * V_276 ) ;
}
}
F_91 ( ! V_278 && V_279 != V_167 ) ;
F_91 ( V_278 > * V_276 ) ;
V_3 = * V_276 - V_278 ;
if ( V_277 ) {
if ( ! V_14 -> V_29 )
return V_6 ;
if ( F_92 ( & V_4 , V_275 , V_5 ) )
return - V_280 ;
V_6 = V_14 -> V_29 ( V_11 , * V_276 , V_5 , V_14 , V_3 , V_4 ) ;
} else {
if ( V_14 -> V_28 ) {
V_6 = V_14 -> V_28 ( V_11 , * V_276 , V_5 ,
V_14 , V_3 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( F_93 ( V_275 , & V_4 , V_5 ) )
return - V_280 ;
}
return V_6 ;
}
T_10 F_94 ( struct V_10 * V_11 , char T_11 * V_275 ,
T_8 V_5 , T_9 * V_276 , bool V_277 )
{
T_8 V_283 = 0 ;
int V_6 = 0 ;
T_9 V_12 = * V_276 ;
V_12 &= V_284 ;
while ( V_5 ) {
V_6 = F_90 ( V_11 , V_275 , V_5 , & V_12 , V_277 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -= V_6 ;
V_283 += V_6 ;
V_275 += V_6 ;
V_12 += V_6 ;
}
* V_276 += V_283 ;
return V_283 ;
}
