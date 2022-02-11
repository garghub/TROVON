static inline T_1
F_1 ( T_2 V_1 , T_2 V_2 )
{
return ( ( unsigned ) ( V_1 - V_2 ) ) % ( V_3 + 1 ) ;
}
static inline struct V_4 *
F_2 ( struct V_5 * V_6 )
{
return (struct V_4 * ) V_6 -> V_7 ;
}
static inline struct V_5 *
F_3 ( struct V_4 * V_4 )
{
return F_4 ( ( void * ) V_4 , struct V_5 , V_7 ) ;
}
static T_3
F_5 ( struct V_5 * V_6 , unsigned int V_8 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_13 V_14 ;
struct V_15 V_16 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
F_7 ( & V_16 ) ;
V_4 -> V_17 -> V_18 [ 0 ] =
( F_8 ( V_8 , V_19 ) |
F_8 ( V_20 , V_21 ) ) ;
V_14 . V_22 = V_4 -> V_17 -> V_18 ;
V_14 . V_23 = V_4 -> V_24 -> V_18 ;
V_14 . V_25 = 2 ;
F_9 ( & V_14 , & V_16 ) ;
F_10 ( V_10 , & V_16 ) ;
return V_4 -> V_24 -> V_18 [ 1 ] ;
}
static void
F_11 ( struct V_5 * V_6 , unsigned int V_8 , T_3 V_26 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_13 V_14 ;
struct V_15 V_16 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
F_7 ( & V_16 ) ;
V_4 -> V_17 -> V_18 [ 0 ] =
( F_8 ( V_8 , V_19 ) |
F_8 ( V_27 , V_21 ) ) ;
V_4 -> V_17 -> V_18 [ 1 ] = V_26 ;
V_14 . V_22 = V_4 -> V_17 -> V_18 ;
V_14 . V_25 = 2 ;
F_9 ( & V_14 , & V_16 ) ;
F_10 ( V_10 , & V_16 ) ;
}
static void
F_12 ( struct V_5 * V_6 , unsigned int V_8 , void * V_28 , T_4 V_25 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_13 V_14 [ 2 ] ;
struct V_15 V_16 ;
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
F_7 ( & V_16 ) ;
V_4 -> V_17 -> V_18 [ 0 ] =
( F_8 ( V_8 , V_19 ) |
F_8 ( V_20 , V_21 ) ) ;
V_14 [ 0 ] . V_22 = V_4 -> V_17 -> V_18 ;
V_14 [ 0 ] . V_25 = 1 ;
V_14 [ 1 ] . V_23 = V_28 ;
V_14 [ 1 ] . V_25 = V_25 ;
F_9 ( & V_14 [ 0 ] , & V_16 ) ;
F_9 ( & V_14 [ 1 ] , & V_16 ) ;
F_10 ( V_10 , & V_16 ) ;
}
static void
F_13 ( struct V_5 * V_6 , unsigned int V_8 , void * V_28 , T_4 V_25 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_13 V_14 [ 2 ] ;
struct V_15 V_16 ;
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
F_7 ( & V_16 ) ;
V_4 -> V_17 -> V_18 [ 0 ] =
( F_8 ( V_8 , V_19 ) |
F_8 ( V_27 , V_21 ) ) ;
V_14 [ 0 ] . V_22 = V_4 -> V_17 -> V_18 ;
V_14 [ 0 ] . V_25 = 1 ;
V_14 [ 1 ] . V_22 = V_28 ;
V_14 [ 1 ] . V_25 = V_25 ;
F_9 ( & V_14 [ 0 ] , & V_16 ) ;
F_9 ( & V_14 [ 1 ] , & V_16 ) ;
F_10 ( V_10 , & V_16 ) ;
}
static void
F_14 ( struct V_5 * V_6 , struct V_29 * V_30 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
T_3 V_31 , V_32 , V_33 = V_4 -> V_33 ;
V_31 = F_15 ( V_34 ) ;
V_32 = F_15 ( V_35 ) ;
if ( V_4 -> V_36 & V_37 ) {
V_33 |= V_31 ;
V_33 &= ~ V_32 ;
} else if ( V_30 -> V_38 == V_39 ) {
V_33 |= V_31 | V_32 ;
} else {
V_33 &= ~ ( V_31 | V_32 ) ;
}
if ( V_33 != V_4 -> V_33 ) {
V_4 -> V_33 = V_33 ;
F_11 ( V_6 , V_40 , V_4 -> V_33 ) ;
}
}
static void
F_16 ( struct V_5 * V_6 , struct V_29 * V_30 , int V_41 ,
int V_42 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
int V_43 , V_44 , V_45 , V_46 ;
struct V_29 * V_47 ;
T_3 V_48 ;
V_47 = V_4 -> V_49 ;
V_43 = V_4 -> V_50 ;
V_44 = ( V_30 == V_47 && V_41 == V_43 ) ;
if ( V_44 && ! V_42 )
return;
if ( V_47 && ! V_44 ) {
T_3 V_51 = F_5 ( V_6 , V_52 ) ;
V_45 = ( V_51 >> V_53 ) & 1 ;
V_46 = ( V_51 >> V_54 ) & 1 ;
F_17 ( V_47 , V_43 , 0 , V_45 ) ;
F_17 ( V_47 , V_43 , 1 , V_46 ) ;
}
V_45 = F_18 ( V_30 , V_41 , 0 ) ;
V_46 = F_18 ( V_30 , V_41 , 1 ) ;
V_48 = ( F_15 ( V_45 + V_55 ) |
F_15 ( V_46 + V_56 ) ) ;
V_4 -> V_50 = V_41 ;
F_11 ( V_6 , V_57 , V_48 ) ;
V_4 -> V_49 = V_30 ;
F_11 ( V_6 , V_58 , V_30 -> V_59 ) ;
}
static int
F_19 ( struct V_5 * V_6 , struct V_60 * V_60 )
{
F_13 ( V_6 , V_61 , V_60 -> V_62 , 8 ) ;
return V_63 ;
}
static int
F_20 ( struct V_5 * V_6 , struct V_60 * V_60 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
int V_41 = F_21 ( V_60 -> V_64 ) ;
V_4 -> V_65 = 0 ;
V_4 -> V_66 |= F_15 ( V_67 ) ;
return F_22 ( V_41 ) ;
}
static int
F_23 ( struct V_5 * V_6 , struct V_60 * V_60 , int V_68 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
int V_41 = F_21 ( V_60 -> V_64 ) ;
T_5 V_69 ;
void * V_70 ;
V_70 = V_60 -> V_71 + V_60 -> V_72 ;
if ( V_68 ) {
if ( V_4 -> V_73 == 0x12 ) {
F_11 ( V_6 , V_74 , 0 ) ;
F_11 ( V_6 , V_75 , ( ( T_3 * ) V_70 ) [ 0 ] ) ;
F_11 ( V_6 , V_74 , V_4 -> V_65 ) ;
}
return F_24 ( V_41 ) ;
}
V_69 = F_25 ( V_60 -> V_30 , V_60 -> V_64 , 1 ) ;
if ( V_69 > V_76 ) {
F_26 ( & V_10 -> V_30 ,
L_1 ,
V_77 , V_69 , V_76 ) ;
V_4 -> V_78 = - V_79 ;
return - V_79 ;
}
V_4 -> V_65 = F_27 ( ( V_60 -> V_80 -
V_60 -> V_72 ) , V_69 ) ;
F_13 ( V_6 , V_75 , V_70 , V_4 -> V_65 ) ;
F_11 ( V_6 , V_74 , V_4 -> V_65 ) ;
return F_24 ( V_41 ) ;
}
static void
F_28 ( struct V_5 * V_6 , int V_68 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_60 * V_60 = V_4 -> V_81 ;
struct V_82 * V_82 ;
int V_83 = - V_84 ;
if ( ! V_60 )
return;
V_82 = V_60 -> V_85 -> V_86 ;
switch ( V_82 -> V_87 ) {
case V_88 :
V_83 = F_19 ( V_6 , V_60 ) ;
break;
case V_89 :
if ( F_29 ( V_60 ) )
V_83 = F_20 ( V_6 , V_60 ) ;
else
V_83 = F_23 ( V_6 , V_60 , V_68 ) ;
break;
case V_90 :
if ( F_29 ( V_60 ) )
V_83 = V_91 ;
else
V_83 = V_92 ;
break;
}
if ( V_83 < 0 )
return;
F_11 ( V_6 , V_93 , V_83 ) ;
V_4 -> V_66 |= F_15 ( V_94 ) ;
}
static int
F_30 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_60 * V_60 , * V_81 = NULL ;
struct V_82 * V_82 ;
int V_41 , V_42 = 0 ;
struct V_95 * V_85 ;
struct V_96 * V_97 ;
unsigned long V_98 ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
for (;
V_4 -> V_100 < V_101 ;
++ V_4 -> V_100 )
F_32 (pos, &max3421_hcd->ep_list) {
V_60 = NULL ;
V_82 = F_4 ( V_97 , struct V_82 ,
V_102 ) ;
V_85 = V_82 -> V_85 ;
switch ( F_33 ( & V_85 -> V_103 ) ) {
case V_104 :
case V_105 :
if ( V_4 -> V_100 !=
V_106 )
continue;
break;
case V_107 :
case V_108 :
if ( V_4 -> V_100 !=
V_109 )
continue;
break;
}
if ( F_34 ( & V_85 -> V_110 ) )
continue;
V_60 = F_35 ( & V_85 -> V_110 , struct V_60 ,
V_110 ) ;
if ( V_60 -> V_111 ) {
F_36 ( & V_10 -> V_30 , L_2 ,
V_77 , V_60 , V_60 -> V_111 ) ;
V_4 -> V_81 = V_60 ;
V_4 -> V_78 = 1 ;
F_37 ( & V_4 -> V_99 ,
V_98 ) ;
return 1 ;
}
switch ( F_33 ( & V_85 -> V_103 ) ) {
case V_107 :
if ( F_1 ( V_82 -> V_112 ,
V_4 -> V_113 ) == 0 )
continue;
break;
case V_108 :
if ( V_82 -> V_114
&& ( F_1 ( V_82 -> V_112 ,
V_4 -> V_113 )
== 0 ) )
continue;
break;
case V_104 :
case V_105 :
if ( F_1 ( V_4 -> V_113 ,
V_82 -> V_112 )
< V_60 -> V_115 )
continue;
break;
}
F_38 ( V_97 , & V_4 -> V_102 ) ;
V_81 = V_60 ;
goto V_116;
}
V_116:
if ( ! V_81 ) {
F_37 ( & V_4 -> V_99 , V_98 ) ;
return 0 ;
}
V_60 = V_4 -> V_81 = V_81 ;
V_41 = F_39 ( & V_60 -> V_85 -> V_103 ) ;
if ( V_82 -> V_114 )
V_82 -> V_114 = 0 ;
else {
if ( F_40 ( & V_85 -> V_103 ) ) {
F_17 ( V_60 -> V_30 , V_41 , 0 , 1 ) ;
F_17 ( V_60 -> V_30 , V_41 , 1 , 1 ) ;
V_82 -> V_87 = V_88 ;
V_42 = 1 ;
} else
V_82 -> V_87 = V_89 ;
}
F_37 ( & V_4 -> V_99 , V_98 ) ;
V_82 -> V_112 = V_4 -> V_113 ;
F_16 ( V_6 , V_60 -> V_30 , V_41 , V_42 ) ;
F_14 ( V_6 , V_60 -> V_30 ) ;
F_28 ( V_6 , 0 ) ;
return 1 ;
}
static int
F_41 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_96 * V_97 , * V_117 , * V_118 ;
struct V_82 * V_82 ;
struct V_95 * V_85 ;
struct V_60 * V_60 ;
unsigned long V_98 ;
int V_119 = 0 ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
F_32 (pos, &max3421_hcd->ep_list) {
V_82 = F_4 ( V_97 , struct V_82 , V_102 ) ;
V_85 = V_82 -> V_85 ;
F_42 (upos, next_upos, &ep->urb_list) {
V_60 = F_4 ( V_117 , struct V_60 , V_110 ) ;
if ( V_60 -> V_111 ) {
V_119 = 1 ;
F_36 ( & V_10 -> V_30 , L_2 ,
V_77 , V_60 , V_60 -> V_111 ) ;
F_43 ( V_6 , V_60 ) ;
F_37 ( & V_4 -> V_99 ,
V_98 ) ;
F_44 ( V_6 , V_60 , 0 ) ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
}
}
}
F_37 ( & V_4 -> V_99 , V_98 ) ;
return V_119 ;
}
static void
F_45 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_60 * V_60 = V_4 -> V_81 ;
struct V_82 * V_82 ;
V_82 = V_60 -> V_85 -> V_86 ;
V_82 -> V_114 = 1 ;
V_4 -> V_81 = NULL ;
}
static void
F_46 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_60 * V_60 = V_4 -> V_81 ;
T_4 V_120 , V_121 ;
T_3 V_122 ;
V_122 = F_5 ( V_6 , V_123 ) ;
if ( V_122 > V_76 )
V_122 = V_76 ;
if ( V_60 -> V_72 >= V_60 -> V_80 )
V_120 = 0 ;
else
V_120 = V_60 -> V_80 - V_60 -> V_72 ;
V_121 = V_122 ;
if ( V_121 > V_120 )
V_121 = V_120 ;
if ( V_121 > 0 ) {
void * V_124 = V_60 -> V_71 + V_60 -> V_72 ;
F_12 ( V_6 , V_125 , V_124 , V_121 ) ;
V_60 -> V_72 += V_121 ;
V_4 -> V_65 = V_121 ;
}
F_11 ( V_6 , V_126 , F_15 ( V_67 ) ) ;
}
static void
F_47 ( struct V_5 * V_6 , T_3 V_51 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
T_3 V_127 = V_51 & V_128 ;
struct V_60 * V_60 = V_4 -> V_81 ;
struct V_82 * V_82 = V_60 -> V_85 -> V_86 ;
int V_129 ;
V_129 = ( V_82 -> V_87 == V_89 &&
F_48 ( V_60 ) ) ;
switch ( V_127 ) {
case V_130 :
return;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
V_4 -> V_78 = V_137 [ V_127 ] ;
F_36 ( & V_10 -> V_30 , L_3 ,
V_77 , V_51 ) ;
break;
case V_138 :
if ( F_29 ( V_60 ) )
;
else {
int V_46 = ( V_51 >> V_54 ) & 1 ;
V_46 ^= 1 ;
F_11 ( V_6 , V_57 ,
F_15 ( V_46 + V_56 ) ) ;
}
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
if ( V_82 -> V_145 ++ < V_146 )
F_45 ( V_6 ) ;
else {
V_4 -> V_78 = V_137 [ V_127 ] ;
F_36 ( & V_10 -> V_30 , L_3 ,
V_77 , V_51 ) ;
}
break;
case V_147 :
F_36 ( & V_10 -> V_30 , L_3 ,
V_77 , V_51 ) ;
V_4 -> V_78 = V_137 [ V_127 ] ;
break;
case V_148 :
if ( V_82 -> V_149 ++ < V_150 ) {
F_28 ( V_6 , 1 ) ;
V_129 = 0 ;
} else
F_45 ( V_6 ) ;
break;
}
if ( V_129 )
F_11 ( V_6 , V_74 , 0 ) ;
}
static int
F_49 ( struct V_5 * V_6 , struct V_60 * V_60 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
T_5 V_69 ;
if ( V_60 -> V_72 >= V_60 -> V_80 )
return 1 ;
V_69 = F_25 ( V_60 -> V_30 , V_60 -> V_64 , 0 ) ;
if ( V_69 > V_76 ) {
F_26 ( & V_10 -> V_30 ,
L_1 ,
V_77 , V_69 , V_76 ) ;
return - V_84 ;
}
if ( V_4 -> V_65 < V_69 ) {
if ( V_60 -> V_151 & V_152 ) {
return - V_153 ;
} else
return 1 ;
}
return 0 ;
}
static int
F_50 ( struct V_5 * V_6 , struct V_60 * V_60 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_60 -> V_72 += V_4 -> V_65 ;
if ( V_60 -> V_72 < V_60 -> V_80 )
return 0 ;
if ( V_60 -> V_151 & V_154 ) {
T_5 V_69 = F_25 ( V_60 -> V_30 , V_60 -> V_64 , 1 ) ;
if ( V_4 -> V_65 == V_69 )
return 0 ;
}
return 1 ;
}
static void
F_51 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_60 * V_60 = V_4 -> V_81 ;
struct V_82 * V_82 ;
T_3 V_127 , V_51 ;
int V_78 = 0 ;
V_4 -> V_66 &= ~ ( F_15 ( V_94 ) |
F_15 ( V_67 ) ) ;
V_51 = F_5 ( V_6 , V_52 ) ;
V_127 = V_51 & V_128 ;
#ifdef F_52
++ V_4 -> V_155 [ V_127 ] ;
#endif
V_82 = V_60 -> V_85 -> V_86 ;
if ( F_53 ( V_127 != V_130 ) ) {
F_47 ( V_6 , V_51 ) ;
return;
}
V_82 -> V_149 = 0 ;
V_82 -> V_145 = 0 ;
switch ( V_82 -> V_87 ) {
case V_88 :
if ( V_60 -> V_80 > 0 )
V_82 -> V_87 = V_89 ;
else
V_82 -> V_87 = V_90 ;
break;
case V_89 :
if ( F_29 ( V_60 ) )
V_78 = F_49 ( V_6 , V_60 ) ;
else
V_78 = F_50 ( V_6 , V_60 ) ;
if ( V_78 > 0 && F_54 ( V_60 -> V_64 ) == V_156 ) {
V_4 -> V_78 = V_78 = 0 ;
V_82 -> V_87 = V_90 ;
}
break;
case V_90 :
V_78 = 1 ;
break;
}
if ( V_78 )
V_4 -> V_78 = V_78 ;
else
F_28 ( V_6 , 0 ) ;
}
static void
F_55 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
unsigned int V_157 , V_158 = 0 ;
T_5 V_159 , V_160 ;
unsigned long V_98 ;
T_3 V_51 , V_33 ;
V_51 = F_5 ( V_6 , V_52 ) ;
V_157 = ( ( ( ( V_51 >> V_161 ) & 1 ) << 0 ) |
( ( ( V_51 >> V_162 ) & 1 ) << 1 ) ) ;
V_33 = V_4 -> V_33 ;
switch ( V_157 ) {
case 0x0 :
V_33 &= ~ F_15 ( V_163 ) ;
break;
case 0x1 :
case 0x2 :
if ( V_157 == 0x2 )
V_33 ^= F_15 ( V_34 ) ;
V_33 |= F_15 ( V_163 ) ;
V_158 = 1 ;
break;
case 0x3 :
break;
}
V_4 -> V_33 = V_33 ;
F_11 ( V_6 , V_40 , V_4 -> V_33 ) ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
V_159 = V_4 -> V_36 ;
if ( V_158 )
V_4 -> V_36 |= V_164 ;
else
V_4 -> V_36 &= ~ V_164 ;
if ( V_33 & F_15 ( V_34 ) )
V_4 -> V_36 |= V_37 ;
else
V_4 -> V_36 &= ~ V_37 ;
V_160 = ( V_159 ^ V_4 -> V_36 ) ;
V_4 -> V_36 |= V_160 << 16 ;
F_37 ( & V_4 -> V_99 , V_98 ) ;
}
static T_6
F_56 ( int V_165 , void * V_166 )
{
struct V_5 * V_6 = V_166 ;
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
if ( V_4 -> V_167 &&
V_4 -> V_167 -> V_168 != V_169 )
F_57 ( V_4 -> V_167 ) ;
if ( ! F_58 ( V_170 , & V_4 -> V_171 ) )
F_59 ( V_10 -> V_165 ) ;
return V_172 ;
}
static void
F_60 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_82 * V_82 ;
struct V_95 * V_85 ;
struct V_96 * V_97 , * V_117 ;
char V_173 [ 512 ] , * V_174 , * V_175 ;
unsigned long V_98 ;
struct V_60 * V_60 ;
int V_41 , V_176 ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
F_32 (pos, &max3421_hcd->ep_list) {
V_82 = F_4 ( V_97 , struct V_82 , V_102 ) ;
V_85 = V_82 -> V_85 ;
V_174 = V_173 ;
V_175 = V_174 + sizeof( V_173 ) ;
* V_174 = '\0' ;
F_32 (upos, &ep->urb_list) {
V_60 = F_4 ( V_117 , struct V_60 , V_110 ) ;
V_176 = snprintf ( V_174 , V_175 - V_174 , L_4 , V_60 ,
F_54 ( V_60 -> V_64 ) ,
F_29 ( V_60 ) ? L_5 : L_6 ,
V_60 -> V_72 ,
V_60 -> V_80 ) ;
if ( V_176 < 0 || V_176 >= V_175 - V_174 )
break;
V_174 += V_176 ;
}
V_41 = F_39 ( & V_85 -> V_103 ) ;
F_61 ( L_7 ,
V_41 , V_82 -> V_87 , V_82 -> V_112 ,
V_82 -> V_145 , V_82 -> V_149 ,
V_82 -> V_114 , V_173 ) ;
}
F_37 ( & V_4 -> V_99 , V_98 ) ;
}
static int
F_62 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
T_5 V_160 , V_159 ;
unsigned long V_98 ;
T_3 V_177 ;
V_177 = F_5 ( V_6 , V_126 ) ;
V_177 &= V_4 -> V_66 ;
if ( ! V_177 )
return 0 ;
F_11 ( V_6 , V_126 ,
V_177 & ~ ( F_15 ( V_178 ) |
F_15 ( V_67 ) ) ) ;
if ( V_177 & F_15 ( V_179 ) ) {
V_4 -> V_113 = ( ( V_4 -> V_113 + 1 )
& V_3 ) ;
V_4 -> V_100 = V_106 ;
}
if ( V_177 & F_15 ( V_67 ) )
F_46 ( V_6 ) ;
if ( V_177 & F_15 ( V_94 ) )
F_51 ( V_6 ) ;
if ( V_177 & F_15 ( V_180 ) )
F_55 ( V_6 ) ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
V_159 = V_4 -> V_36 ;
if ( V_177 & F_15 ( V_181 ) ) {
if ( V_4 -> V_36 & V_182 ) {
V_4 -> V_36 &= ~ V_182 ;
V_4 -> V_36 |= V_183 ;
} else {
F_61 ( L_8 , V_77 ) ;
}
}
if ( V_177 & F_15 ( V_184 ) )
F_61 ( L_9 , V_77 ) ;
if ( V_177 & F_15 ( V_185 ) )
F_61 ( L_10 , V_77 ) ;
V_160 = ( V_159 ^ V_4 -> V_36 ) ;
V_4 -> V_36 |= V_160 << 16 ;
F_37 ( & V_4 -> V_99 , V_98 ) ;
#ifdef F_52
{
static unsigned long V_186 ;
char V_187 [ 16 * 16 ] , * V_174 , * V_175 ;
int V_188 ;
if ( V_189 - V_186 > 5 * V_190 ) {
V_174 = V_187 ;
V_175 = V_187 + sizeof( V_187 ) ;
* V_174 = '\0' ;
for ( V_188 = 0 ; V_188 < 16 ; ++ V_188 ) {
int V_176 = snprintf ( V_174 , V_175 - V_174 , L_11 ,
V_4 -> V_155 [ V_188 ] ) ;
if ( V_176 < 0 || V_176 >= V_175 - V_174 )
break;
V_174 += V_176 ;
}
F_61 ( L_12 , V_77 , V_187 ) ;
memset ( V_4 -> V_155 , 0 ,
sizeof( V_4 -> V_155 ) ) ;
V_186 = V_189 ;
F_60 ( V_6 ) ;
}
}
#endif
return 1 ;
}
static int
F_63 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
int V_191 ;
F_11 ( V_6 , V_192 , F_15 ( V_193 ) ) ;
F_11 ( V_6 , V_192 , 0 ) ;
V_191 = 1000 ;
while ( 1 ) {
if ( F_5 ( V_6 , V_194 )
& F_15 ( V_195 ) )
break;
if ( -- V_191 < 0 ) {
F_26 ( & V_10 -> V_30 ,
L_13 ) ;
return 1 ;
}
F_64 () ;
}
V_4 -> V_33 = ( F_15 ( V_196 ) |
F_15 ( V_163 ) |
F_15 ( V_197 ) |
F_15 ( V_198 ) ) ;
F_11 ( V_6 , V_40 , V_4 -> V_33 ) ;
V_4 -> V_113 = V_3 ;
F_11 ( V_6 , V_57 , F_15 ( V_199 ) ) ;
F_11 ( V_6 , V_57 , F_15 ( V_200 ) ) ;
F_55 ( V_6 ) ;
V_4 -> V_66 = ( F_15 ( V_179 ) |
F_15 ( V_180 ) |
F_15 ( V_181 ) ) ;
F_11 ( V_6 , V_201 , V_4 -> V_66 ) ;
F_11 ( V_6 , V_202 , F_15 ( V_203 ) ) ;
return 1 ;
}
static int
F_65 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
unsigned long V_98 ;
struct V_60 * V_60 ;
int V_204 ;
V_204 = V_4 -> V_78 ;
V_4 -> V_78 = 0 ;
if ( V_204 > 0 )
V_204 = 0 ;
V_60 = V_4 -> V_81 ;
if ( V_60 ) {
V_4 -> V_81 = NULL ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
F_43 ( V_6 , V_60 ) ;
F_37 ( & V_4 -> V_99 , V_98 ) ;
F_44 ( V_6 , V_60 , V_204 ) ;
}
return 1 ;
}
static int
F_66 ( void * V_166 )
{
struct V_5 * V_6 = V_166 ;
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
int V_188 , V_205 = 1 ;
F_11 ( V_6 , V_206 ,
( F_15 ( V_207 ) |
F_15 ( V_208 ) ) ) ;
while ( ! F_67 () ) {
V_4 -> V_73 = F_5 ( V_6 , V_209 ) ;
if ( V_4 -> V_73 == 0x12 || V_4 -> V_73 == 0x13 )
break;
F_26 ( & V_10 -> V_30 , L_14 , V_4 -> V_73 ) ;
F_68 ( 10000 ) ;
}
F_69 ( & V_10 -> V_30 , L_15 ,
V_4 -> V_73 , V_10 -> V_210 , V_10 -> V_211 ,
V_10 -> V_165 ) ;
while ( ! F_67 () ) {
if ( ! V_205 ) {
F_11 ( V_6 , V_201 , V_4 -> V_66 ) ;
F_70 ( V_212 ) ;
if ( F_71 ( V_170 , & V_4 -> V_171 ) )
F_72 ( V_10 -> V_165 ) ;
F_73 () ;
F_74 ( V_169 ) ;
}
V_205 = 0 ;
if ( V_4 -> V_78 )
V_205 |= F_65 ( V_6 ) ;
else if ( F_62 ( V_6 ) )
V_205 = 1 ;
else if ( ! V_4 -> V_81 )
V_205 |= F_30 ( V_6 ) ;
if ( F_71 ( V_213 , & V_4 -> V_171 ) )
V_205 |= F_63 ( V_6 ) ;
if ( F_71 ( V_214 , & V_4 -> V_171 ) ) {
F_11 ( V_6 , V_57 ,
F_15 ( V_215 ) ) ;
V_205 = 1 ;
}
if ( F_71 ( V_216 , & V_4 -> V_171 ) )
V_205 |= F_41 ( V_6 ) ;
if ( F_71 ( V_217 , & V_4 -> V_171 ) ) {
for ( V_188 = 0 ; V_188 < F_75 ( V_4 -> V_218 ) ; ++ V_188 ) {
T_3 V_26 = F_5 ( V_6 , V_219 ) ;
V_26 = ( ( V_26 & 0xf0 ) |
( V_4 -> V_218 [ V_188 ] & 0x0f ) ) ;
F_11 ( V_6 , V_219 + V_188 , V_26 ) ;
V_4 -> V_218 [ V_188 ] = V_26 ;
}
V_205 = 1 ;
}
}
F_70 ( V_169 ) ;
F_69 ( & V_10 -> V_30 , L_16 ) ;
return 0 ;
}
static int
F_76 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_4 -> V_36 &= ~ ( V_183 |
V_37 ) ;
V_4 -> V_36 |= V_182 ;
F_77 ( V_214 , & V_4 -> V_171 ) ;
F_57 ( V_4 -> V_167 ) ;
return 0 ;
}
static int
F_78 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
V_6 -> V_11 . V_220 = 0 ;
V_6 -> V_38 = V_221 ;
V_6 -> V_11 . V_222 -> V_38 = V_223 ;
F_77 ( V_213 , & V_4 -> V_171 ) ;
F_57 ( V_4 -> V_167 ) ;
return 0 ;
}
static int
F_79 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
F_80 ( & V_4 -> V_99 ) ;
V_4 -> V_224 = V_225 ;
F_81 ( & V_4 -> V_102 ) ;
V_6 -> V_226 = V_227 ;
V_6 -> V_168 = V_228 ;
V_6 -> V_229 = 1 ;
return 0 ;
}
static void
F_82 ( struct V_5 * V_6 )
{
}
static int
F_83 ( struct V_5 * V_6 , struct V_60 * V_60 , T_7 V_230 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_82 * V_82 ;
unsigned long V_98 ;
int V_119 ;
switch ( F_54 ( V_60 -> V_64 ) ) {
case V_231 :
case V_232 :
if ( V_60 -> V_115 < 0 ) {
F_26 ( & V_10 -> V_30 ,
L_17 ,
V_77 , V_60 -> V_115 ) ;
return - V_84 ;
}
default:
break;
}
F_31 ( & V_4 -> V_99 , V_98 ) ;
V_82 = V_60 -> V_85 -> V_86 ;
if ( ! V_82 ) {
V_82 = F_84 ( sizeof( struct V_82 ) , V_233 ) ;
if ( ! V_82 ) {
V_119 = - V_234 ;
goto V_235;
}
V_82 -> V_85 = V_60 -> V_85 ;
V_82 -> V_112 = V_4 -> V_113 ;
V_60 -> V_85 -> V_86 = V_82 ;
F_85 ( & V_82 -> V_102 , & V_4 -> V_102 ) ;
}
V_119 = F_86 ( V_6 , V_60 ) ;
if ( V_119 == 0 ) {
V_4 -> V_100 = V_106 ;
F_57 ( V_4 -> V_167 ) ;
}
V_235:
F_37 ( & V_4 -> V_99 , V_98 ) ;
return V_119 ;
}
static int
F_87 ( struct V_5 * V_6 , struct V_60 * V_60 , int V_204 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
unsigned long V_98 ;
int V_119 ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
V_119 = F_88 ( V_6 , V_60 , V_204 ) ;
if ( V_119 == 0 ) {
F_77 ( V_216 , & V_4 -> V_171 ) ;
F_57 ( V_4 -> V_167 ) ;
}
F_37 ( & V_4 -> V_99 , V_98 ) ;
return V_119 ;
}
static void
F_89 ( struct V_5 * V_6 , struct V_95 * V_85 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
unsigned long V_98 ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
if ( V_85 -> V_86 ) {
struct V_82 * V_82 = V_85 -> V_86 ;
if ( ! F_34 ( & V_82 -> V_102 ) )
F_90 ( & V_82 -> V_102 ) ;
F_91 ( V_82 ) ;
V_85 -> V_86 = NULL ;
}
F_37 ( & V_4 -> V_99 , V_98 ) ;
}
static int
F_92 ( struct V_5 * V_6 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
return V_4 -> V_113 ;
}
static int
F_93 ( struct V_5 * V_6 , char * V_28 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
unsigned long V_98 ;
int V_119 = 0 ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
if ( ! F_94 ( V_6 ) )
goto V_116;
* V_28 = 0 ;
if ( ( V_4 -> V_36 & V_236 ) != 0 ) {
* V_28 = ( 1 << 1 ) ;
F_36 ( V_6 -> V_11 . V_12 ,
L_18 ,
V_4 -> V_36 ) ;
V_119 = 1 ;
if ( V_4 -> V_224 == V_237 )
F_95 ( V_6 ) ;
}
V_116:
F_37 ( & V_4 -> V_99 , V_98 ) ;
return V_119 ;
}
static inline void
F_96 ( struct V_238 * V_103 )
{
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_103 -> V_239 = 0x29 ;
V_103 -> V_240 = 9 ;
V_103 -> V_241 = F_97 ( 0x0001 ) ;
V_103 -> V_242 = 1 ;
}
static void
F_98 ( struct V_5 * V_6 , T_3 V_243 , T_3 V_244 )
{
struct V_4 * V_4 = F_2 ( V_6 ) ;
T_3 V_245 , V_246 ;
-- V_243 ;
if ( V_243 > 7 )
return;
V_245 = 1u << V_243 ;
V_246 = V_243 / 4 ;
if ( V_244 )
V_4 -> V_218 [ V_246 ] |= V_245 ;
else
V_4 -> V_218 [ V_246 ] &= ~ V_245 ;
F_77 ( V_217 , & V_4 -> V_171 ) ;
F_57 ( V_4 -> V_167 ) ;
}
static int
F_99 ( struct V_5 * V_6 , T_2 V_247 , T_2 V_244 , T_2 V_248 ,
char * V_28 , T_2 V_249 )
{
struct V_9 * V_10 = F_6 ( V_6 -> V_11 . V_12 ) ;
struct V_4 * V_4 = F_2 ( V_6 ) ;
struct V_250 * V_251 ;
unsigned long V_98 ;
int V_119 = 0 ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
V_251 = V_10 -> V_30 . V_252 ;
switch ( V_247 ) {
case V_253 :
break;
case V_254 :
switch ( V_244 ) {
case V_255 :
break;
case V_256 :
F_36 ( V_6 -> V_11 . V_12 , L_19 ) ;
F_98 ( V_6 , V_251 -> V_257 ,
! V_251 -> V_258 ) ;
default:
V_4 -> V_36 &= ~ ( 1 << V_244 ) ;
}
break;
case V_259 :
F_96 ( (struct V_238 * ) V_28 ) ;
break;
case V_260 | V_261 :
case V_262 :
case V_263 :
goto error;
case V_264 :
* ( V_265 * ) V_28 = F_100 ( 0 ) ;
break;
case V_266 :
if ( V_248 != 1 ) {
V_119 = - V_267 ;
goto error;
}
( ( V_268 * ) V_28 ) [ 0 ] = F_97 ( V_4 -> V_36 ) ;
( ( V_268 * ) V_28 ) [ 1 ] =
F_97 ( V_4 -> V_36 >> 16 ) ;
break;
case V_269 :
V_119 = - V_267 ;
break;
case V_270 :
switch ( V_244 ) {
case V_271 :
case V_272 :
case V_273 :
case V_274 :
goto error;
case V_255 :
if ( V_4 -> V_275 )
V_4 -> V_36 |=
V_276 ;
break;
case V_256 :
F_36 ( V_6 -> V_11 . V_12 , L_20 ) ;
V_4 -> V_36 |= V_277 ;
F_98 ( V_6 , V_251 -> V_257 ,
V_251 -> V_258 ) ;
break;
case V_278 :
F_76 ( V_6 ) ;
default:
if ( ( V_4 -> V_36 & V_277 )
!= 0 )
V_4 -> V_36 |= ( 1 << V_244 ) ;
}
break;
default:
F_36 ( V_6 -> V_11 . V_12 ,
L_21 ,
V_247 , V_244 , V_248 , V_249 ) ;
error:
V_119 = - V_267 ;
}
F_37 ( & V_4 -> V_99 , V_98 ) ;
return V_119 ;
}
static int
F_101 ( struct V_5 * V_6 )
{
return - 1 ;
}
static int
F_102 ( struct V_5 * V_6 )
{
return - 1 ;
}
static int
F_103 ( struct V_5 * V_6 , struct V_60 * V_60 , T_7 V_230 )
{
return 0 ;
}
static void
F_104 ( struct V_5 * V_6 , struct V_60 * V_60 )
{
}
static int
F_105 ( struct V_9 * V_10 )
{
struct V_4 * V_4 ;
struct V_5 * V_6 = NULL ;
int V_119 = - V_234 ;
if ( F_106 ( V_10 ) < 0 ) {
F_26 ( & V_10 -> V_30 , L_22 ) ;
return - V_279 ;
}
V_6 = F_107 ( & V_280 , & V_10 -> V_30 ,
F_108 ( & V_10 -> V_30 ) ) ;
if ( ! V_6 ) {
F_26 ( & V_10 -> V_30 , L_23 ) ;
goto error;
}
F_77 ( V_281 , & V_6 -> V_98 ) ;
V_4 = F_2 ( V_6 ) ;
V_4 -> V_282 = V_283 ;
V_283 = V_4 ;
F_81 ( & V_4 -> V_102 ) ;
V_4 -> V_17 = F_109 ( sizeof( * V_4 -> V_17 ) , V_284 ) ;
if ( ! V_4 -> V_17 ) {
F_26 ( & V_10 -> V_30 , L_24 ) ;
goto error;
}
V_4 -> V_24 = F_109 ( sizeof( * V_4 -> V_24 ) , V_284 ) ;
if ( ! V_4 -> V_24 ) {
F_26 ( & V_10 -> V_30 , L_25 ) ;
goto error;
}
V_4 -> V_167 = F_110 ( F_66 , V_6 ,
L_26 ) ;
if ( V_4 -> V_167 == F_111 ( - V_234 ) ) {
F_26 ( & V_10 -> V_30 ,
L_27 ) ;
goto error;
}
V_119 = F_112 ( V_6 , 0 , 0 ) ;
if ( V_119 ) {
F_26 ( & V_10 -> V_30 , L_28 ) ;
goto error;
}
V_119 = F_113 ( V_10 -> V_165 , F_56 ,
V_285 , L_29 , V_6 ) ;
if ( V_119 < 0 ) {
F_26 ( & V_10 -> V_30 , L_30 , V_10 -> V_165 ) ;
goto error;
}
return 0 ;
error:
if ( V_6 ) {
F_91 ( V_4 -> V_17 ) ;
F_91 ( V_4 -> V_24 ) ;
if ( V_4 -> V_167 )
F_114 ( V_4 -> V_167 ) ;
F_115 ( V_6 ) ;
}
return V_119 ;
}
static int
F_116 ( struct V_9 * V_10 )
{
struct V_4 * V_4 = NULL , * * V_286 ;
struct V_5 * V_6 = NULL ;
unsigned long V_98 ;
for ( V_286 = & V_283 ; * V_286 ; V_286 = & ( * V_286 ) -> V_282 ) {
V_4 = * V_286 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 -> V_11 . V_12 == & V_10 -> V_30 )
break;
}
if ( ! V_4 ) {
F_26 ( & V_10 -> V_30 , L_31 ,
V_10 ) ;
return - V_287 ;
}
F_117 ( V_6 ) ;
F_31 ( & V_4 -> V_99 , V_98 ) ;
F_114 ( V_4 -> V_167 ) ;
* V_286 = V_4 -> V_282 ;
F_37 ( & V_4 -> V_99 , V_98 ) ;
F_118 ( V_10 -> V_165 , V_6 ) ;
F_115 ( V_6 ) ;
return 0 ;
}
