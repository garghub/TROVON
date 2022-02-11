static inline T_1 F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 , V_2 ) & V_3 ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_4 ,
unsigned long V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_1 , V_7 ) ;
F_4 ( V_1 , V_8 | V_9 | V_10 ,
V_7 ) ;
F_5 ( V_1 , ( 1 << V_4 ) , V_5 ) ;
F_6 ( V_1 , V_6 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_4 ,
unsigned long V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_1 , V_7 ) ;
F_4 ( V_1 , V_8 | V_9 | V_10 ,
V_7 ) ;
F_4 ( V_1 , ( 1 << V_4 ) , V_5 ) ;
F_6 ( V_1 , V_6 , V_7 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_5 ( V_1 , V_11 , V_7 ) ;
F_5 ( V_1 , V_8 | V_10 , V_7 ) ;
F_5 ( V_1 , V_12 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_1 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
F_4 ( V_1 , V_11 , V_7 ) ;
F_4 ( V_1 , V_8 | V_10 , V_7 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
V_1 -> V_15 . V_16 = V_17 ;
F_10 ( & V_1 -> V_14 ) ;
V_1 -> V_18 -> V_19 ( & V_1 -> V_15 ) ;
F_11 ( & V_1 -> V_14 ) ;
F_12 ( V_1 ) ;
F_13 ( V_1 ) ;
F_5 ( V_1 , V_20 , V_7 ) ;
F_14 ( & V_1 -> V_21 [ 0 ] . V_22 ) ;
}
static inline T_1 F_15 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_23 = 0 ;
unsigned long V_24 ;
if ( V_4 == 0 )
V_23 = F_2 ( V_1 , V_25 ) & V_26 ;
else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
V_23 = F_2 ( V_1 , V_24 ) & V_26 ;
} else
F_17 ( V_28 L_1 , V_4 ) ;
return V_23 ;
}
static inline void F_18 ( struct V_1 * V_1 , T_1 V_4 ,
T_1 V_23 )
{
unsigned long V_24 ;
if ( V_4 == 0 )
F_19 ( V_1 , V_23 , V_26 , V_25 ) ;
else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
F_19 ( V_1 , V_23 , V_26 , V_24 ) ;
} else
F_17 ( V_28 L_1 , V_4 ) ;
}
static inline void F_20 ( struct V_1 * V_1 , T_1 V_4 )
{
F_18 ( V_1 , V_4 , V_29 ) ;
}
static inline void F_21 ( struct V_1 * V_1 , T_1 V_4 )
{
F_18 ( V_1 , V_4 , V_30 ) ;
}
static inline void F_22 ( struct V_1 * V_1 , T_1 V_4 )
{
F_18 ( V_1 , V_4 , V_31 ) ;
}
static inline T_1 F_23 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_32 = 0 ;
unsigned long V_24 ;
if ( V_4 == 0 )
V_32 = F_2 ( V_1 , V_25 ) ;
else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
V_32 = F_2 ( V_1 , V_24 ) ;
} else
F_17 ( V_28 L_1 , V_4 ) ;
return V_32 ;
}
static inline void F_24 ( struct V_1 * V_1 , T_1 V_4 )
{
unsigned long V_24 ;
F_21 ( V_1 , V_4 ) ;
if ( V_4 == 0 )
F_5 ( V_1 , V_33 , V_25 ) ;
else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
F_5 ( V_1 , V_33 , V_24 ) ;
} else
F_17 ( V_28 L_2 , V_4 ) ;
}
static inline int F_25 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_6 ;
int V_34 ;
if ( V_4 == 0 ) {
V_6 = F_2 ( V_1 , V_35 ) ;
if ( ( V_6 & V_36 ) != 0 )
V_34 = 256 ;
else {
V_6 = F_2 ( V_1 , V_37 ) ;
V_34 = V_6 & V_38 ;
}
} else {
F_6 ( V_1 , V_4 , V_39 ) ;
V_6 = F_2 ( V_1 , V_40 ) ;
if ( ( V_6 & V_36 ) != 0 ) {
V_6 = F_2 ( V_1 , V_41 ) ;
V_34 = ( ( V_6 >> 10 ) + 1 ) * 64 ;
} else {
V_6 = F_2 ( V_1 , V_42 ) ;
V_34 = V_6 & V_43 ;
}
}
return V_34 ;
}
static inline unsigned short F_26 ( struct V_1 * V_1 )
{
if ( V_1 -> V_44 -> V_45 )
return V_46 ;
else
return V_47 ;
}
static inline void F_27 ( struct V_1 * V_1 , T_1 V_4 )
{
struct V_48 * V_21 = V_1 -> V_49 [ V_4 ] ;
if ( V_21 -> V_50 )
return;
F_19 ( V_1 , V_4 , V_51 , V_21 -> V_52 ) ;
F_28 ( 450 ) ;
F_5 ( V_1 , F_26 ( V_1 ) , V_21 -> V_52 ) ;
}
static int F_29 ( struct V_1 * V_1 ,
struct V_53 * V_54 )
{
T_1 V_55 = 0 , V_56 = 0 ;
T_1 V_57 = 0 ;
if ( V_54 -> V_58 == 0 )
return - V_59 ;
F_6 ( V_1 , V_54 -> V_58 , V_39 ) ;
if ( V_54 -> V_60 )
V_57 |= V_61 ;
V_57 |= V_54 -> type ;
V_57 |= V_54 -> V_62 ;
switch ( V_54 -> type ) {
case V_63 :
V_55 = 4 + ( V_54 -> V_58 - V_64 ) ;
V_56 = 0 ;
break;
case V_65 :
if ( V_54 -> V_58 >= V_66 )
V_55 = V_54 -> V_58 - V_66 ;
else
V_55 = V_54 -> V_58 - V_67 ;
V_55 = V_68 + ( V_55 * 16 ) ;
V_56 = 7 ;
V_57 |= V_69 ;
if ( ! V_54 -> V_60 )
V_57 |= V_70 ;
break;
case V_71 :
V_55 = V_68 +
( V_54 -> V_58 - V_67 ) * 16 ;
V_56 = 7 ;
break;
}
if ( V_56 && ( ( V_55 + 16 ) >= V_72 ) ) {
F_30 ( L_3 ) ;
return - V_73 ;
}
F_6 ( V_1 , V_57 , V_40 ) ;
F_6 ( V_1 , ( V_56 << 10 ) | ( V_55 ) , V_41 ) ;
F_6 ( V_1 , V_54 -> V_74 , V_42 ) ;
if ( V_54 -> V_75 )
V_54 -> V_75 -- ;
F_6 ( V_1 , V_54 -> V_75 , V_76 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_1 ,
struct V_53 * V_54 )
{
if ( V_54 -> V_58 == 0 )
return;
if ( F_32 ( V_54 -> V_58 ) )
V_1 -> V_77 -- ;
else if ( F_33 ( V_54 -> V_58 ) )
V_1 -> V_78 -- ;
else if ( F_34 ( V_54 -> V_58 ) ) {
V_1 -> V_79 -- ;
if ( V_54 -> type == V_65 )
V_1 -> V_77 -- ;
} else
F_17 ( V_28 L_4 ,
V_54 -> V_58 ) ;
}
static void F_35 ( struct V_48 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
F_19 ( V_1 , 0 , V_51 , V_21 -> V_52 ) ;
F_6 ( V_1 , V_80 , V_21 -> V_81 ) ;
F_6 ( V_1 , 0 , V_21 -> V_81 ) ;
F_6 ( V_1 , V_33 , V_21 -> V_81 ) ;
if ( V_21 -> V_50 ) {
F_19 ( V_1 , V_21 -> V_4 , V_51 , V_21 -> V_52 ) ;
F_28 ( 450 ) ;
F_5 ( V_1 , F_26 ( V_1 ) , V_21 -> V_52 ) ;
}
}
static void F_36 ( struct V_1 * V_1 ,
struct V_48 * V_21 ,
const struct V_82 * V_83 ,
T_1 V_4 , int V_84 )
{
V_21 -> V_50 = 0 ;
V_21 -> V_85 = V_86 ;
V_21 -> V_52 = V_87 ;
V_21 -> V_88 = V_89 ;
V_21 -> V_90 = 0 ;
V_21 -> V_81 = F_16 ( V_4 ) ;
V_21 -> V_4 = V_4 ;
V_21 -> V_21 . V_74 = F_37 ( V_83 -> V_91 ) ;
V_1 -> V_49 [ V_4 ] = V_21 ;
V_1 -> V_92 [ V_83 -> V_93 & V_94 ]
= V_21 ;
F_14 ( & V_21 -> V_22 ) ;
}
static void F_38 ( struct V_48 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_4 = V_21 -> V_4 ;
if ( V_4 == 0 )
return;
if ( V_21 -> V_50 )
V_1 -> V_95 -- ;
V_21 -> V_4 = 0 ;
V_21 -> V_96 = 0 ;
V_21 -> V_50 = 0 ;
}
static int F_39 ( struct V_48 * V_21 ,
const struct V_82 * V_83 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_53 V_54 ;
int V_84 = 0 ;
unsigned char * V_97 ;
int V_32 ;
V_21 -> V_83 = V_83 ;
if ( V_21 -> V_4 )
return 0 ;
switch ( V_83 -> V_98 & V_99 ) {
case V_100 :
if ( V_1 -> V_77 >= V_101 ) {
if ( V_1 -> V_79 >= V_102 ) {
F_17 ( V_28 L_5 ) ;
return - V_103 ;
} else {
V_54 . V_58 = V_67
+ V_1 -> V_79 ;
V_97 = & V_1 -> V_79 ;
}
} else {
V_54 . V_58 = V_66 + V_1 -> V_77 ;
V_97 = & V_1 -> V_77 ;
}
V_54 . type = V_65 ;
V_84 = 1 ;
break;
case V_104 :
if ( V_1 -> V_78 >= V_105 ) {
F_17 ( V_28 L_6 ) ;
return - V_103 ;
}
V_54 . V_58 = V_64 + V_1 -> V_78 ;
V_54 . type = V_63 ;
V_97 = & V_1 -> V_78 ;
break;
case V_106 :
if ( V_1 -> V_79 >= V_102 ) {
F_17 ( V_28 L_7 ) ;
return - V_103 ;
}
V_54 . V_58 = V_67 + V_1 -> V_79 ;
V_54 . type = V_71 ;
V_97 = & V_1 -> V_79 ;
break;
default:
F_17 ( V_28 L_8 ) ;
return - V_59 ;
}
V_21 -> type = V_54 . type ;
V_54 . V_62 = V_83 -> V_93 & V_94 ;
V_54 . V_74 = F_37 ( V_83 -> V_91 ) ;
V_54 . V_75 = V_83 -> V_107 ;
if ( V_83 -> V_93 & V_108 )
V_54 . V_60 = 1 ;
else
V_54 . V_60 = 0 ;
V_32 = F_29 ( V_1 , & V_54 ) ;
if ( V_32 < 0 ) {
F_17 ( V_28 L_9 ) ;
return V_32 ;
}
( * V_97 ) ++ ;
if ( ( V_97 == & V_1 -> V_79 ) && V_54 . type == V_65 )
V_1 -> V_77 ++ ;
F_36 ( V_1 , V_21 , V_83 , V_54 . V_58 , V_84 ) ;
F_35 ( V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_48 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_53 V_54 ;
V_54 . V_58 = V_21 -> V_4 ;
V_54 . type = V_21 -> type ;
F_31 ( V_1 , & V_54 ) ;
F_38 ( V_21 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_1 , T_1 V_4 )
{
F_42 ( V_1 , V_4 ) ;
F_43 ( V_1 , V_4 ) ;
}
static void F_44 ( struct V_1 * V_1 , T_1 V_4 )
{
F_45 ( V_1 , V_4 ) ;
F_46 ( V_1 , V_4 ) ;
}
static void F_47 ( struct V_1 * V_1 , unsigned V_109 )
{
V_1 -> V_21 [ 0 ] . V_110 = V_109 ;
F_20 ( V_1 , 0 ) ;
F_5 ( V_1 , V_111 , V_25 ) ;
}
static void F_48 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
F_27 ( V_1 , V_21 -> V_4 ) ;
F_19 ( V_1 , V_114 , ( V_114 | V_51 ) , V_87 ) ;
F_6 ( V_1 , V_115 , V_21 -> V_88 ) ;
if ( V_113 -> V_113 . V_116 == 0 ) {
F_5 ( V_1 , V_117 , V_21 -> V_88 ) ;
F_20 ( V_1 , 0 ) ;
F_49 ( V_21 , V_113 , 0 ) ;
} else {
F_6 ( V_1 , ~ V_118 , V_119 ) ;
F_50 ( V_21 , V_113 ) ;
}
}
static void F_51 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_6 ;
F_27 ( V_1 , V_21 -> V_4 ) ;
F_52 ( V_1 , V_21 -> V_4 ) ;
F_20 ( V_1 , V_21 -> V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_88 ) ;
if ( F_53 ( ( V_6 & V_120 ) == 0 ) )
F_41 ( V_1 , V_21 -> V_4 ) ;
else
F_54 ( V_21 , V_113 ) ;
}
static void F_55 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_4 = V_21 -> V_4 ;
if ( V_21 -> V_4 == 0 ) {
F_19 ( V_1 , 0 , ( V_114 | V_51 ) , V_87 ) ;
F_6 ( V_1 , V_115 , V_21 -> V_88 ) ;
F_20 ( V_1 , V_4 ) ;
F_41 ( V_1 , V_4 ) ;
} else {
if ( V_21 -> V_50 ) {
F_5 ( V_1 , V_121 , V_21 -> V_52 ) ;
F_27 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_122 , V_21 -> V_52 ) ;
F_6 ( V_1 ,
( V_113 -> V_113 . V_116 + V_21 -> V_21 . V_74 - 1 )
/ V_21 -> V_21 . V_74 ,
V_21 -> V_90 ) ;
}
F_20 ( V_1 , V_4 ) ;
F_41 ( V_1 , V_4 ) ;
}
}
static void F_56 ( struct V_48 * V_21 , struct V_112 * V_113 )
{
if ( V_21 -> V_83 -> V_93 & V_123 )
F_51 ( V_21 , V_113 ) ;
else
F_55 ( V_21 , V_113 ) ;
}
static void F_57 ( struct V_48 * V_21 , struct V_112 * V_113 )
{
T_1 V_124 ;
V_124 = F_2 ( V_21 -> V_1 , V_125 ) & V_126 ;
switch ( V_124 ) {
case V_127 :
F_48 ( V_21 , V_113 ) ;
break;
case V_128 :
F_55 ( V_21 , V_113 ) ;
break;
case V_129 :
F_47 ( V_21 -> V_1 , 0 ) ;
break;
default:
F_17 ( V_28 L_10 , V_124 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_1 )
{
T_1 V_130 = V_1 -> V_44 -> V_130 ? V_131 : 0 ;
T_1 V_132 = V_1 -> V_133 ? V_134 : 0 ;
T_1 V_135 = V_1 -> V_44 -> V_135 ? V_136 : 0 ;
if ( V_1 -> V_44 -> V_45 ) {
if ( V_1 -> V_44 -> V_137 )
F_6 ( V_1 , V_1 -> V_44 -> V_137 ,
V_138 ) ;
else
F_6 ( V_1 , 0x0f , V_138 ) ;
F_5 ( V_1 , V_139 , V_13 ) ;
F_4 ( V_1 , V_140 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_140 , V_13 ) ;
F_5 ( V_1 , V_141 , V_13 ) ;
F_5 ( V_1 , V_132 , V_142 ) ;
F_6 ( V_1 , V_143 | V_144 ,
V_145 ) ;
} else {
F_5 ( V_1 , V_130 | V_135 , V_146 ) ;
F_5 ( V_1 , V_139 , V_13 ) ;
F_19 ( V_1 , F_58 ( V_1 -> V_44 ) ,
V_147 , V_13 ) ;
F_4 ( V_1 , V_140 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_140 , V_13 ) ;
F_5 ( V_1 , V_148 , V_13 ) ;
F_59 ( 3 ) ;
F_5 ( V_1 , V_149 , V_13 ) ;
F_59 ( 1 ) ;
F_5 ( V_1 , V_141 , V_13 ) ;
F_5 ( V_1 , V_132 , V_142 ) ;
F_6 ( V_1 , V_143 | V_144 ,
V_145 ) ;
}
}
static void F_12 ( struct V_1 * V_1 )
{
if ( V_1 -> V_44 -> V_45 ) {
F_5 ( V_1 , V_141 , V_13 ) ;
F_4 ( V_1 , V_150 , V_151 ) ;
F_6 ( V_1 , 0 , V_7 ) ;
F_6 ( V_1 , 0 , V_142 ) ;
F_6 ( V_1 , 0 , V_152 ) ;
F_6 ( V_1 , 0 , V_153 ) ;
F_6 ( V_1 , 0 , V_154 ) ;
F_6 ( V_1 , 0 , V_155 ) ;
F_6 ( V_1 , 0 , V_156 ) ;
F_6 ( V_1 , 0 , V_119 ) ;
F_4 ( V_1 , V_140 , V_13 ) ;
F_4 ( V_1 , V_141 , V_13 ) ;
} else {
F_4 ( V_1 , V_150 , V_151 ) ;
F_4 ( V_1 , V_141 , V_13 ) ;
F_60 ( 1 ) ;
F_4 ( V_1 , V_149 , V_13 ) ;
F_60 ( 1 ) ;
F_60 ( 1 ) ;
F_4 ( V_1 , V_148 , V_13 ) ;
}
}
static void F_61 ( struct V_1 * V_1 )
{
T_1 V_6 ;
if ( ! V_1 -> V_44 -> V_45 ) {
V_6 = F_2 ( V_1 , V_13 ) ;
if ( ! ( V_6 & V_148 ) )
F_5 ( V_1 , V_148 , V_13 ) ;
}
}
static struct V_112 * F_62 ( struct V_48 * V_21 )
{
return F_63 ( V_21 -> V_22 . V_157 , struct V_112 , V_22 ) ;
}
static void F_49 ( struct V_48 * V_21 ,
struct V_112 * V_113 , int V_158 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
int V_159 = 0 ;
if ( F_53 ( V_21 -> V_4 == 0 ) ) {
if ( V_21 -> V_110 ) {
V_21 -> V_110 = 0 ;
return;
}
}
F_64 ( & V_113 -> V_22 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
V_113 -> V_113 . V_158 = - V_160 ;
else
V_113 -> V_113 . V_158 = V_158 ;
if ( ! F_65 ( & V_21 -> V_22 ) )
V_159 = 1 ;
F_10 ( & V_21 -> V_1 -> V_14 ) ;
V_113 -> V_113 . V_161 ( & V_21 -> V_21 , & V_113 -> V_113 ) ;
F_11 ( & V_21 -> V_1 -> V_14 ) ;
if ( V_159 ) {
V_113 = F_62 ( V_21 ) ;
if ( V_21 -> V_83 )
F_56 ( V_21 , V_113 ) ;
}
}
static void F_50 ( struct V_48 * V_21 , struct V_112 * V_113 )
{
int V_162 ;
T_1 V_6 ;
unsigned V_163 ;
T_2 V_34 ;
void * V_164 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
F_27 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_114 , V_21 -> V_52 ) ;
V_162 = 0 ;
do {
V_6 = F_2 ( V_1 , V_21 -> V_88 ) ;
if ( V_162 ++ > 100000 ) {
F_17 ( V_28 L_11
L_12 ) ;
return;
}
F_28 ( 1 ) ;
} while ( ( V_6 & V_120 ) == 0 );
V_163 = F_25 ( V_1 , V_4 ) ;
V_164 = V_113 -> V_113 . V_164 + V_113 -> V_113 . V_165 ;
V_34 = F_66 ( V_163 , V_113 -> V_113 . V_116 - V_113 -> V_113 . V_165 ) ;
if ( V_113 -> V_113 . V_164 ) {
if ( V_34 > 0 )
F_67 ( V_1 , V_21 -> V_85 , V_164 , V_34 ) ;
if ( ( V_34 == 0 ) || ( ( V_34 % V_21 -> V_21 . V_74 ) != 0 ) )
F_5 ( V_1 , V_117 , V_21 -> V_88 ) ;
}
V_113 -> V_113 . V_165 += V_34 ;
if ( ( ! V_113 -> V_113 . V_166 && ( V_113 -> V_113 . V_165 == V_113 -> V_113 . V_116 ) )
|| ( V_34 % V_21 -> V_21 . V_74 )
|| ( V_34 == 0 ) ) {
F_45 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 ) ;
} else {
F_45 ( V_1 , V_4 ) ;
F_68 ( V_1 , V_4 ) ;
}
F_20 ( V_1 , V_4 ) ;
}
static void F_54 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
T_1 V_6 ;
unsigned V_163 ;
T_2 V_34 ;
void * V_164 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
F_27 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_88 ) ;
if ( F_53 ( ( V_6 & V_120 ) == 0 ) ) {
F_21 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
F_17 ( V_28 L_13 , V_4 ) ;
return;
}
V_163 = F_25 ( V_1 , V_4 ) ;
V_164 = V_113 -> V_113 . V_164 + V_113 -> V_113 . V_165 ;
V_34 = F_66 ( V_163 , V_113 -> V_113 . V_116 - V_113 -> V_113 . V_165 ) ;
if ( V_113 -> V_113 . V_164 ) {
F_67 ( V_1 , V_21 -> V_85 , V_164 , V_34 ) ;
if ( ( V_34 == 0 )
|| ( ( V_34 % V_21 -> V_21 . V_74 ) != 0 )
|| ( ( V_163 != V_21 -> V_21 . V_74 )
&& ( V_163 > V_34 ) ) )
F_5 ( V_1 , V_117 , V_21 -> V_88 ) ;
}
V_113 -> V_113 . V_165 += V_34 ;
if ( ( ! V_113 -> V_113 . V_166 && ( V_113 -> V_113 . V_165 == V_113 -> V_113 . V_116 ) )
|| ( V_34 % V_21 -> V_21 . V_74 )
|| ( V_34 == 0 ) ) {
F_45 ( V_1 , V_4 ) ;
F_68 ( V_1 , V_4 ) ;
} else {
F_52 ( V_1 , V_4 ) ;
F_41 ( V_1 , V_4 ) ;
}
}
static void F_69 ( struct V_48 * V_21 ,
struct V_112 * V_113 )
{
T_1 V_6 ;
int V_167 , V_163 , V_168 ;
int V_34 ;
void * V_164 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
int V_169 = 0 ;
F_27 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_88 ) ;
if ( F_53 ( ( V_6 & V_120 ) == 0 ) ) {
V_113 -> V_113 . V_158 = - V_170 ;
F_21 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
F_17 ( V_28 L_14 ) ;
return;
}
V_167 = V_6 & V_171 ;
V_163 = F_25 ( V_1 , V_4 ) ;
V_164 = V_113 -> V_113 . V_164 + V_113 -> V_113 . V_165 ;
V_168 = V_113 -> V_113 . V_116 - V_113 -> V_113 . V_165 ;
if ( V_167 < V_163 )
V_34 = F_66 ( V_167 , V_168 ) ;
else
V_34 = F_66 ( V_163 , V_168 ) ;
V_113 -> V_113 . V_165 += V_34 ;
if ( ( ! V_113 -> V_113 . V_166 && ( V_113 -> V_113 . V_165 == V_113 -> V_113 . V_116 ) )
|| ( V_34 % V_21 -> V_21 . V_74 )
|| ( V_34 == 0 ) ) {
F_21 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
V_169 = 1 ;
}
if ( V_113 -> V_113 . V_164 ) {
if ( V_34 == 0 )
F_6 ( V_1 , V_115 , V_21 -> V_88 ) ;
else
F_70 ( V_1 , V_21 -> V_85 , V_164 , V_34 ) ;
}
if ( ( V_21 -> V_4 != 0 ) && V_169 )
F_49 ( V_21 , V_113 , 0 ) ;
}
static void F_71 ( struct V_1 * V_1 , T_1 V_158 , T_1 V_172 )
{
T_1 V_173 ;
T_1 V_4 ;
struct V_48 * V_21 ;
struct V_112 * V_113 ;
if ( ( V_158 & V_174 ) && ( V_172 & V_174 ) ) {
F_6 ( V_1 , ~ V_174 , V_155 ) ;
F_19 ( V_1 , 0 , V_51 , V_87 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_113 = F_62 ( V_21 ) ;
F_69 ( V_21 , V_113 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_173 = 1 << V_4 ;
if ( ( V_158 & V_173 ) && ( V_172 & V_173 ) ) {
F_6 ( V_1 , ~ V_173 , V_155 ) ;
V_21 = V_1 -> V_49 [ V_4 ] ;
V_113 = F_62 ( V_21 ) ;
if ( V_21 -> V_83 -> V_93 & V_123 )
F_54 ( V_21 , V_113 ) ;
else
F_69 ( V_21 , V_113 ) ;
}
}
}
}
static void F_72 ( struct V_1 * V_1 , T_1 V_158 , T_1 V_172 )
{
T_1 V_6 ;
T_1 V_173 ;
T_1 V_4 ;
struct V_48 * V_21 ;
struct V_112 * V_113 ;
if ( ( V_158 & V_118 ) && ( V_172 & V_118 ) ) {
F_6 ( V_1 , ~ V_118 , V_119 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_113 = F_62 ( V_21 ) ;
F_50 ( V_21 , V_113 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_173 = 1 << V_4 ;
if ( ( V_158 & V_173 ) && ( V_172 & V_173 ) ) {
F_6 ( V_1 , ~ V_173 , V_119 ) ;
V_6 = F_23 ( V_1 , V_4 ) ;
if ( ( V_6 & V_175 ) == 0 ) {
F_52 ( V_1 , V_4 ) ;
F_44 ( V_1 , V_4 ) ;
F_21 ( V_1 , V_4 ) ;
V_21 = V_1 -> V_49 [ V_4 ] ;
V_113 = F_62 ( V_21 ) ;
if ( ! F_65 ( & V_21 -> V_22 ) )
F_49 ( V_21 , V_113 , 0 ) ;
}
}
}
}
}
static void F_73 ( struct V_1 * V_1 , struct V_176 * V_177 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_48 * V_21 ;
T_1 V_23 ;
T_1 V_158 = 0 ;
T_1 V_178 = F_37 ( V_177 -> V_179 ) ;
switch ( V_177 -> V_180 & V_181 ) {
case V_182 :
V_158 = 1 << V_183 ;
break;
case V_184 :
V_158 = 0 ;
break;
case V_185 :
V_21 = V_1 -> V_92 [ V_178 & V_94 ] ;
V_23 = F_15 ( V_1 , V_21 -> V_4 ) ;
if ( V_23 == V_31 )
V_158 = 1 << V_186 ;
else
V_158 = 0 ;
break;
default:
F_22 ( V_1 , 0 ) ;
return;
}
V_1 -> V_187 = F_74 ( V_158 ) ;
V_1 -> V_188 -> V_164 = & V_1 -> V_187 ;
V_1 -> V_188 -> V_116 = 2 ;
F_10 ( & V_1 -> V_14 ) ;
F_75 ( V_1 -> V_15 . V_189 , V_1 -> V_188 , V_190 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
static void F_76 ( struct V_1 * V_1 ,
struct V_176 * V_177 )
{
switch ( V_177 -> V_180 & V_181 ) {
case V_182 :
F_47 ( V_1 , 1 ) ;
break;
case V_184 :
F_47 ( V_1 , 1 ) ;
break;
case V_185 : {
struct V_48 * V_21 ;
struct V_112 * V_113 ;
T_1 V_178 = F_37 ( V_177 -> V_179 ) ;
V_21 = V_1 -> V_92 [ V_178 & V_94 ] ;
if ( ! V_21 -> V_191 ) {
F_21 ( V_1 , V_21 -> V_4 ) ;
F_24 ( V_1 , V_21 -> V_4 ) ;
F_10 ( & V_1 -> V_14 ) ;
F_77 ( & V_21 -> V_21 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
F_47 ( V_1 , 1 ) ;
V_113 = F_62 ( V_21 ) ;
if ( V_21 -> V_96 ) {
V_21 -> V_96 = 0 ;
if ( F_65 ( & V_21 -> V_22 ) )
break;
F_56 ( V_21 , V_113 ) ;
} else if ( ! F_65 ( & V_21 -> V_22 ) )
F_20 ( V_1 , V_21 -> V_4 ) ;
}
break;
default:
F_22 ( V_1 , 0 ) ;
break;
}
}
static void F_78 ( struct V_1 * V_1 , struct V_176 * V_177 )
{
T_1 V_6 ;
int V_192 = 3000 ;
switch ( V_177 -> V_180 & V_181 ) {
case V_182 :
switch ( F_37 ( V_177 -> V_193 ) ) {
case V_194 :
F_47 ( V_1 , 1 ) ;
do {
V_6 = F_2 ( V_1 , V_125 ) & V_126 ;
F_60 ( 1 ) ;
} while ( V_6 != V_195 || V_192 -- > 0 );
if ( V_6 == V_195 )
F_5 ( V_1 ,
F_37 ( V_177 -> V_179 >> 8 ) ,
V_151 ) ;
break;
default:
F_22 ( V_1 , 0 ) ;
break;
}
break;
case V_184 :
F_47 ( V_1 , 1 ) ;
break;
case V_185 : {
struct V_48 * V_21 ;
T_1 V_178 = F_37 ( V_177 -> V_179 ) ;
V_21 = V_1 -> V_92 [ V_178 & V_94 ] ;
F_22 ( V_1 , V_21 -> V_4 ) ;
F_47 ( V_1 , 1 ) ;
}
break;
default:
F_22 ( V_1 , 0 ) ;
break;
}
}
static int F_79 ( struct V_1 * V_1 , struct V_176 * V_177 )
{
T_1 * V_196 = ( T_1 * ) V_177 ;
unsigned long V_24 = V_197 ;
int V_162 , V_32 = 0 ;
F_6 ( V_1 , ~ V_198 , V_125 ) ;
for ( V_162 = 0 ; V_162 < 4 ; V_162 ++ )
V_196 [ V_162 ] = F_2 ( V_1 , V_24 + V_162 * 2 ) ;
if ( ( V_177 -> V_180 & V_199 ) == V_200 ) {
switch ( V_177 -> V_201 ) {
case V_202 :
F_73 ( V_1 , V_177 ) ;
break;
case V_203 :
F_76 ( V_1 , V_177 ) ;
break;
case V_204 :
F_78 ( V_1 , V_177 ) ;
break;
default:
V_32 = 1 ;
break;
}
} else
V_32 = 1 ;
return V_32 ;
}
static void F_80 ( struct V_1 * V_1 )
{
T_1 V_16 = F_1 ( V_1 ) ;
switch ( V_16 ) {
case V_205 :
V_1 -> V_15 . V_16 = V_206 ;
break;
case V_207 :
V_1 -> V_15 . V_16 = V_208 ;
break;
default:
V_1 -> V_15 . V_16 = V_17 ;
F_17 ( V_28 L_15 ) ;
}
}
static void F_81 ( struct V_1 * V_1 )
{
T_1 V_209 ;
V_209 = F_2 ( V_1 , V_125 ) & V_210 ;
F_6 ( V_1 , ~ V_211 , V_125 ) ;
if ( V_209 == V_212 ) {
F_10 ( & V_1 -> V_14 ) ;
V_1 -> V_18 -> V_19 ( & V_1 -> V_15 ) ;
F_11 ( & V_1 -> V_14 ) ;
F_80 ( V_1 ) ;
}
if ( V_1 -> V_213 == V_214 && V_209 != V_214 )
F_80 ( V_1 ) ;
if ( ( V_209 == V_214 || V_209 == V_215 )
&& V_1 -> V_15 . V_16 == V_17 )
F_80 ( V_1 ) ;
V_1 -> V_213 = V_209 ;
}
static void F_82 ( struct V_1 * V_1 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_176 V_177 ;
T_1 V_124 ;
V_124 = F_2 ( V_1 , V_125 ) & V_126 ;
F_6 ( V_1 , ~ V_216 , V_125 ) ;
switch ( V_124 ) {
case V_195 : {
struct V_48 * V_21 ;
struct V_112 * V_113 ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_113 = F_62 ( V_21 ) ;
F_49 ( V_21 , V_113 , 0 ) ;
}
break;
case V_127 :
case V_128 :
case V_129 :
if ( F_79 ( V_1 , & V_177 ) ) {
F_10 ( & V_1 -> V_14 ) ;
if ( V_1 -> V_18 -> V_217 ( & V_1 -> V_15 , & V_177 )
< 0 )
F_22 ( V_1 , 0 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
break;
case V_218 :
case V_219 :
F_47 ( V_1 , 0 ) ;
break;
default:
F_17 ( V_28 L_16 , V_124 ) ;
break;
}
}
static T_3 F_83 ( int V_220 , void * V_221 )
{
struct V_1 * V_1 = V_221 ;
T_1 V_222 ;
T_1 V_223 ;
T_1 V_224 , V_225 , V_226 ;
T_1 V_227 , V_228 , V_229 ;
T_1 V_230 ;
T_1 V_231 ;
F_11 ( & V_1 -> V_14 ) ;
V_222 = F_2 ( V_1 , V_125 ) ;
V_223 = F_2 ( V_1 , V_7 ) ;
V_230 = F_2 ( V_1 , V_87 ) ;
V_231 = V_222 & V_223 ;
if ( V_231 ) {
V_224 = F_2 ( V_1 , V_155 ) ;
V_225 = F_2 ( V_1 , V_156 ) ;
V_226 = F_2 ( V_1 , V_119 ) ;
V_227 = F_2 ( V_1 , V_152 ) ;
V_228 = F_2 ( V_1 , V_154 ) ;
V_229 = F_2 ( V_1 , V_153 ) ;
if ( V_231 & V_232 ) {
F_6 ( V_1 , 0xffff & ~ V_232 ,
V_125 ) ;
F_61 ( V_1 ) ;
V_1 -> V_233 = F_2 ( V_1 , V_125 )
& V_234 ;
V_1 -> V_235 = V_236 ;
F_84 ( & V_1 -> V_237 ,
V_238 + F_85 ( 50 ) ) ;
}
if ( V_222 & V_210 )
F_81 ( V_1 ) ;
if ( ( V_222 & V_239 ) && ( V_223 & V_10 )
&& ( V_224 & V_227 ) )
F_71 ( V_1 , V_224 , V_227 ) ;
if ( ( V_222 & V_240 ) && ( V_223 & V_8 )
&& ( V_226 & V_229 ) )
F_72 ( V_1 , V_226 , V_229 ) ;
if ( V_222 & V_216 )
F_82 ( V_1 ) ;
}
F_6 ( V_1 , V_230 , V_87 ) ;
F_10 ( & V_1 -> V_14 ) ;
return V_241 ;
}
static void F_86 ( unsigned long V_221 )
{
struct V_1 * V_1 = (struct V_1 * ) V_221 ;
unsigned long V_242 ;
T_1 V_6 ;
F_87 ( & V_1 -> V_14 , V_242 ) ;
V_6 = F_2 ( V_1 , V_13 ) ;
if ( V_1 -> V_235 > 0 ) {
V_6 = F_2 ( V_1 , V_125 ) & V_234 ;
if ( V_6 == V_1 -> V_233 ) {
V_1 -> V_235 -- ;
if ( V_1 -> V_235 == 0 ) {
if ( V_6 == V_234 )
F_8 ( V_1 ) ;
else
F_9 ( V_1 ) ;
} else {
F_84 ( & V_1 -> V_237 ,
V_238 + F_85 ( 50 ) ) ;
}
} else {
V_1 -> V_235 = V_236 ;
V_1 -> V_233 = V_6 ;
F_84 ( & V_1 -> V_237 ,
V_238 + F_85 ( 50 ) ) ;
}
}
F_88 ( & V_1 -> V_14 , V_242 ) ;
}
static int F_89 ( struct V_243 * V_244 ,
const struct V_82 * V_83 )
{
struct V_48 * V_21 ;
V_21 = F_90 ( V_244 , struct V_48 , V_21 ) ;
return F_39 ( V_21 , V_83 ) ;
}
static int F_91 ( struct V_243 * V_244 )
{
struct V_48 * V_21 ;
struct V_112 * V_113 ;
unsigned long V_242 ;
V_21 = F_90 ( V_244 , struct V_48 , V_21 ) ;
F_92 ( ! V_21 ) ;
while ( ! F_65 ( & V_21 -> V_22 ) ) {
V_113 = F_62 ( V_21 ) ;
F_87 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
F_49 ( V_21 , V_113 , - V_245 ) ;
F_88 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
}
F_44 ( V_21 -> V_1 , V_21 -> V_4 ) ;
return F_40 ( V_21 ) ;
}
static struct V_246 * F_93 ( struct V_243 * V_244 ,
T_4 V_247 )
{
struct V_112 * V_113 ;
V_113 = F_94 ( sizeof( struct V_112 ) , V_247 ) ;
if ( ! V_113 )
return NULL ;
F_14 ( & V_113 -> V_22 ) ;
return & V_113 -> V_113 ;
}
static void F_95 ( struct V_243 * V_244 , struct V_246 * V_248 )
{
struct V_112 * V_113 ;
V_113 = F_90 ( V_248 , struct V_112 , V_113 ) ;
F_96 ( V_113 ) ;
}
static int F_75 ( struct V_243 * V_244 , struct V_246 * V_248 ,
T_4 V_247 )
{
struct V_48 * V_21 ;
struct V_112 * V_113 ;
unsigned long V_242 ;
int V_249 = 0 ;
V_21 = F_90 ( V_244 , struct V_48 , V_21 ) ;
V_113 = F_90 ( V_248 , struct V_112 , V_113 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
return - V_160 ;
F_87 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
if ( F_65 ( & V_21 -> V_22 ) )
V_249 = 1 ;
F_97 ( & V_113 -> V_22 , & V_21 -> V_22 ) ;
V_113 -> V_113 . V_165 = 0 ;
V_113 -> V_113 . V_158 = - V_250 ;
if ( V_21 -> V_83 == NULL )
F_57 ( V_21 , V_113 ) ;
else {
if ( V_249 && ! V_21 -> V_96 )
F_56 ( V_21 , V_113 ) ;
}
F_88 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
return 0 ;
}
static int F_98 ( struct V_243 * V_244 , struct V_246 * V_248 )
{
struct V_48 * V_21 ;
struct V_112 * V_113 ;
unsigned long V_242 ;
V_21 = F_90 ( V_244 , struct V_48 , V_21 ) ;
V_113 = F_90 ( V_248 , struct V_112 , V_113 ) ;
F_87 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
if ( ! F_65 ( & V_21 -> V_22 ) )
F_49 ( V_21 , V_113 , - V_245 ) ;
F_88 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
return 0 ;
}
static int F_99 ( struct V_243 * V_244 , int V_251 )
{
struct V_48 * V_21 ;
struct V_112 * V_113 ;
unsigned long V_242 ;
int V_32 = 0 ;
V_21 = F_90 ( V_244 , struct V_48 , V_21 ) ;
V_113 = F_62 ( V_21 ) ;
F_87 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
if ( ! F_65 ( & V_21 -> V_22 ) ) {
V_32 = - V_252 ;
goto V_253;
}
if ( V_251 ) {
V_21 -> V_96 = 1 ;
F_22 ( V_21 -> V_1 , V_21 -> V_4 ) ;
} else {
V_21 -> V_96 = 0 ;
V_21 -> V_191 = 0 ;
F_21 ( V_21 -> V_1 , V_21 -> V_4 ) ;
}
V_253:
F_88 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
return V_32 ;
}
static int F_100 ( struct V_243 * V_244 )
{
struct V_48 * V_21 ;
unsigned long V_242 ;
V_21 = F_90 ( V_244 , struct V_48 , V_21 ) ;
if ( ! V_21 || ! V_21 -> V_83 )
return - V_59 ;
F_87 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
V_21 -> V_191 = 1 ;
F_88 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
return F_101 ( V_244 ) ;
}
static void F_102 ( struct V_243 * V_244 )
{
struct V_48 * V_21 ;
unsigned long V_242 ;
V_21 = F_90 ( V_244 , struct V_48 , V_21 ) ;
F_87 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
if ( F_65 ( & V_21 -> V_22 ) && ! V_21 -> V_96 ) {
F_21 ( V_21 -> V_1 , V_21 -> V_4 ) ;
F_4 ( V_21 -> V_1 , V_115 , V_21 -> V_88 ) ;
}
F_88 ( & V_21 -> V_1 -> V_14 , V_242 ) ;
}
static int F_103 ( struct V_254 * V_18 ,
int (* F_104)( struct V_255 * ) )
{
struct V_1 * V_1 = V_256 ;
int V_257 ;
if ( ! V_18
|| V_18 -> V_16 != V_206
|| ! F_104
|| ! V_18 -> V_217 )
return - V_59 ;
if ( ! V_1 )
return - V_103 ;
if ( V_1 -> V_18 )
return - V_258 ;
V_18 -> V_18 . V_259 = NULL ;
V_1 -> V_18 = V_18 ;
V_1 -> V_15 . V_260 . V_18 = & V_18 -> V_18 ;
V_257 = F_105 ( & V_1 -> V_15 . V_260 ) ;
if ( V_257 ) {
F_17 ( V_28 L_17 , V_257 ) ;
goto error;
}
V_257 = F_104 ( & V_1 -> V_15 ) ;
if ( V_257 ) {
F_17 ( V_28 L_18 , V_257 ) ;
F_106 ( & V_1 -> V_15 . V_260 ) ;
goto error;
}
F_13 ( V_1 ) ;
F_5 ( V_1 , V_20 , V_7 ) ;
if ( F_2 ( V_1 , V_125 ) & V_234 ) {
F_61 ( V_1 ) ;
V_1 -> V_233 = F_2 ( V_1 ,
V_125 ) & V_234 ;
V_1 -> V_235 = V_236 ;
F_84 ( & V_1 -> V_237 , V_238 + F_85 ( 50 ) ) ;
}
return 0 ;
error:
V_1 -> V_18 = NULL ;
V_1 -> V_15 . V_260 . V_18 = NULL ;
return V_257 ;
}
static int F_107 ( struct V_254 * V_18 )
{
struct V_1 * V_1 = V_256 ;
unsigned long V_242 ;
if ( V_18 != V_1 -> V_18 || ! V_18 -> V_261 )
return - V_59 ;
F_87 ( & V_1 -> V_14 , V_242 ) ;
if ( V_1 -> V_15 . V_16 != V_17 )
F_9 ( V_1 ) ;
F_4 ( V_1 , V_20 , V_7 ) ;
F_12 ( V_1 ) ;
F_88 ( & V_1 -> V_14 , V_242 ) ;
V_18 -> V_261 ( & V_1 -> V_15 ) ;
F_106 ( & V_1 -> V_15 . V_260 ) ;
V_1 -> V_18 = NULL ;
return 0 ;
}
static int F_108 ( struct V_255 * V_262 )
{
struct V_1 * V_1 = F_109 ( V_262 ) ;
return F_2 ( V_1 , V_263 ) & 0x03FF ;
}
static int F_110 ( struct V_255 * V_15 , int V_264 )
{
struct V_1 * V_1 = F_109 ( V_15 ) ;
unsigned long V_242 ;
F_87 ( & V_1 -> V_14 , V_242 ) ;
if ( V_264 )
F_5 ( V_1 , V_12 , V_13 ) ;
else
F_4 ( V_1 , V_12 , V_13 ) ;
F_88 ( & V_1 -> V_14 , V_242 ) ;
return 0 ;
}
static int T_5 F_111 ( struct V_265 * V_266 )
{
struct V_1 * V_1 = F_112 ( & V_266 -> V_260 ) ;
F_113 ( & V_1 -> V_15 ) ;
F_114 ( & V_1 -> V_237 ) ;
F_115 ( V_1 -> V_5 ) ;
F_116 ( F_117 ( V_266 , 0 ) , V_1 ) ;
F_95 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_188 ) ;
#ifdef F_118
if ( V_1 -> V_44 -> V_45 ) {
F_119 ( V_1 -> V_267 ) ;
F_120 ( V_1 -> V_267 ) ;
}
#endif
F_96 ( V_1 ) ;
return 0 ;
}
static void F_121 ( struct V_243 * V_21 , struct V_246 * V_268 )
{
}
static int T_6 F_122 ( struct V_265 * V_266 )
{
#ifdef F_118
char V_269 [ 8 ] ;
#endif
struct V_270 * V_271 , * V_272 ;
int V_220 ;
void T_7 * V_5 = NULL ;
struct V_1 * V_1 = NULL ;
int V_32 = 0 ;
int V_162 ;
unsigned long V_273 ;
V_271 = F_123 ( V_266 , V_274 , 0 ) ;
if ( ! V_271 ) {
V_32 = - V_103 ;
F_17 ( V_28 L_19 ) ;
goto V_275;
}
V_272 = F_123 ( V_266 , V_276 , 0 ) ;
V_220 = V_272 -> V_277 ;
V_273 = V_272 -> V_242 & V_278 ;
if ( V_220 < 0 ) {
V_32 = - V_103 ;
F_17 ( V_28 L_20 ) ;
goto V_275;
}
V_5 = F_124 ( V_271 -> V_277 , F_125 ( V_271 ) ) ;
if ( V_5 == NULL ) {
V_32 = - V_73 ;
F_17 ( V_28 L_21 ) ;
goto V_275;
}
V_1 = F_94 ( sizeof( struct V_1 ) , V_190 ) ;
if ( V_1 == NULL ) {
V_32 = - V_73 ;
F_17 ( V_28 L_22 ) ;
goto V_275;
}
F_126 ( & V_1 -> V_14 ) ;
F_127 ( & V_266 -> V_260 , V_1 ) ;
V_1 -> V_44 = V_266 -> V_260 . V_279 ;
V_1 -> V_133 = V_273 == V_280 ;
V_1 -> V_15 . V_281 = & V_282 ;
F_128 ( & V_1 -> V_15 . V_260 ) ;
F_129 ( & V_1 -> V_15 . V_260 , L_23 ) ;
V_1 -> V_15 . V_283 = 1 ;
V_1 -> V_15 . V_260 . V_284 = & V_266 -> V_260 ;
V_1 -> V_15 . V_260 . V_285 = V_266 -> V_260 . V_285 ;
V_1 -> V_15 . V_260 . V_286 = V_266 -> V_260 . V_286 ;
V_1 -> V_15 . V_287 = V_288 ;
F_130 ( & V_1 -> V_237 ) ;
V_1 -> V_237 . V_289 = F_86 ;
V_1 -> V_237 . V_290 = ( unsigned long ) V_1 ;
V_1 -> V_5 = V_5 ;
#ifdef F_118
if ( V_1 -> V_44 -> V_45 ) {
snprintf ( V_269 , sizeof( V_269 ) , L_24 , V_266 -> V_291 ) ;
V_1 -> V_267 = F_131 ( & V_266 -> V_260 , V_269 ) ;
if ( F_132 ( V_1 -> V_267 ) ) {
F_133 ( & V_266 -> V_260 , L_25 ,
V_269 ) ;
V_32 = F_134 ( V_1 -> V_267 ) ;
goto V_275;
}
F_135 ( V_1 -> V_267 ) ;
}
#endif
F_12 ( V_1 ) ;
V_32 = F_136 ( V_220 , F_83 , V_292 | V_293 ,
V_288 , V_1 ) ;
if ( V_32 < 0 ) {
F_17 ( V_28 L_26 , V_32 ) ;
goto V_294;
}
F_14 ( & V_1 -> V_15 . V_295 ) ;
V_1 -> V_15 . V_189 = & V_1 -> V_21 [ 0 ] . V_21 ;
F_14 ( & V_1 -> V_15 . V_189 -> V_295 ) ;
for ( V_162 = 0 ; V_162 < V_27 ; V_162 ++ ) {
struct V_48 * V_21 = & V_1 -> V_21 [ V_162 ] ;
if ( V_162 != 0 ) {
F_14 ( & V_1 -> V_21 [ V_162 ] . V_21 . V_295 ) ;
F_97 ( & V_1 -> V_21 [ V_162 ] . V_21 . V_295 ,
& V_1 -> V_15 . V_295 ) ;
}
V_21 -> V_1 = V_1 ;
F_14 ( & V_21 -> V_22 ) ;
V_21 -> V_21 . V_287 = V_296 [ V_162 ] ;
V_21 -> V_21 . V_281 = & V_297 ;
V_21 -> V_21 . V_74 = 512 ;
}
V_1 -> V_21 [ 0 ] . V_21 . V_74 = 64 ;
V_1 -> V_21 [ 0 ] . V_4 = 0 ;
V_1 -> V_21 [ 0 ] . V_85 = V_86 ;
V_1 -> V_21 [ 0 ] . V_52 = V_87 ;
V_1 -> V_21 [ 0 ] . V_88 = V_89 ;
V_1 -> V_21 [ 0 ] . V_90 = 0 ;
V_1 -> V_21 [ 0 ] . V_81 = F_16 ( 0 ) ;
V_1 -> V_49 [ 0 ] = & V_1 -> V_21 [ 0 ] ;
V_1 -> V_92 [ 0 ] = & V_1 -> V_21 [ 0 ] ;
V_256 = V_1 ;
V_1 -> V_188 = F_93 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_190 ) ;
if ( V_1 -> V_188 == NULL )
goto V_298;
V_1 -> V_188 -> V_161 = F_121 ;
V_32 = F_137 ( & V_266 -> V_260 , & V_1 -> V_15 ) ;
if ( V_32 )
goto V_299;
F_138 ( & V_266 -> V_260 , L_27 , V_300 ) ;
return 0 ;
V_299:
F_95 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_188 ) ;
V_298:
F_116 ( V_220 , V_1 ) ;
V_294:
#ifdef F_118
if ( V_1 -> V_44 -> V_45 ) {
F_119 ( V_1 -> V_267 ) ;
F_120 ( V_1 -> V_267 ) ;
}
#endif
V_275:
if ( V_1 ) {
if ( V_1 -> V_188 )
F_95 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_1 -> V_188 ) ;
F_96 ( V_1 ) ;
}
if ( V_5 )
F_115 ( V_5 ) ;
return V_32 ;
}
static int T_6 F_139 ( void )
{
return F_140 ( & V_301 , F_122 ) ;
}
static void T_5 F_141 ( void )
{
F_142 ( & V_301 ) ;
}
