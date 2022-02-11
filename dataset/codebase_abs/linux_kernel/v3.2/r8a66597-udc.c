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
if ( V_4 == 0 ) {
V_23 = F_2 ( V_1 , V_25 ) & V_26 ;
} else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
V_23 = F_2 ( V_1 , V_24 ) & V_26 ;
} else {
F_17 ( F_18 ( V_1 ) , L_1 ,
V_4 ) ;
}
return V_23 ;
}
static inline void F_19 ( struct V_1 * V_1 , T_1 V_4 ,
T_1 V_23 )
{
unsigned long V_24 ;
if ( V_4 == 0 ) {
F_20 ( V_1 , V_23 , V_26 , V_25 ) ;
} else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
F_20 ( V_1 , V_23 , V_26 , V_24 ) ;
} else {
F_17 ( F_18 ( V_1 ) , L_1 ,
V_4 ) ;
}
}
static inline void F_21 ( struct V_1 * V_1 , T_1 V_4 )
{
F_19 ( V_1 , V_4 , V_28 ) ;
}
static inline void F_22 ( struct V_1 * V_1 , T_1 V_4 )
{
F_19 ( V_1 , V_4 , V_29 ) ;
}
static inline void F_23 ( struct V_1 * V_1 , T_1 V_4 )
{
F_19 ( V_1 , V_4 , V_30 ) ;
}
static inline T_1 F_24 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_31 = 0 ;
unsigned long V_24 ;
if ( V_4 == 0 ) {
V_31 = F_2 ( V_1 , V_25 ) ;
} else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
V_31 = F_2 ( V_1 , V_24 ) ;
} else {
F_17 ( F_18 ( V_1 ) , L_1 ,
V_4 ) ;
}
return V_31 ;
}
static inline void F_25 ( struct V_1 * V_1 , T_1 V_4 )
{
unsigned long V_24 ;
F_22 ( V_1 , V_4 ) ;
if ( V_4 == 0 ) {
F_5 ( V_1 , V_32 , V_25 ) ;
} else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
F_5 ( V_1 , V_32 , V_24 ) ;
} else {
F_17 ( F_18 ( V_1 ) , L_1 ,
V_4 ) ;
}
}
static void F_26 ( struct V_1 * V_1 , T_1 V_4 )
{
unsigned long V_24 ;
F_22 ( V_1 , V_4 ) ;
if ( V_4 == 0 ) {
F_5 ( V_1 , V_33 , V_25 ) ;
} else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
F_5 ( V_1 , V_33 , V_24 ) ;
} else {
F_17 ( F_18 ( V_1 ) ,
L_2 , V_4 ) ;
}
}
static T_1 F_27 ( struct V_1 * V_1 , T_1 V_4 )
{
unsigned long V_24 ;
if ( V_4 == 0 ) {
return F_2 ( V_1 , V_25 ) & V_34 ;
} else if ( V_4 < V_27 ) {
V_24 = F_16 ( V_4 ) ;
return F_2 ( V_1 , V_24 ) & V_34 ;
} else {
F_17 ( F_18 ( V_1 ) ,
L_2 , V_4 ) ;
}
return 0 ;
}
static T_1 F_28 ( struct V_1 * V_1 , T_1 V_4 )
{
return F_27 ( V_1 , V_4 ) ;
}
static void F_29 ( struct V_1 * V_1 , T_1 V_4 ,
T_1 V_35 )
{
if ( V_35 )
F_26 ( V_1 , V_4 ) ;
else
F_25 ( V_1 , V_4 ) ;
}
static inline int F_30 ( struct V_1 * V_1 , T_1 V_4 )
{
T_1 V_6 ;
int V_36 ;
if ( V_4 == 0 ) {
V_6 = F_2 ( V_1 , V_37 ) ;
if ( ( V_6 & V_38 ) != 0 )
V_36 = 256 ;
else {
V_6 = F_2 ( V_1 , V_39 ) ;
V_36 = V_6 & V_40 ;
}
} else {
F_6 ( V_1 , V_4 , V_41 ) ;
V_6 = F_2 ( V_1 , V_42 ) ;
if ( ( V_6 & V_38 ) != 0 ) {
V_6 = F_2 ( V_1 , V_43 ) ;
V_36 = ( ( V_6 >> 10 ) + 1 ) * 64 ;
} else {
V_6 = F_2 ( V_1 , V_44 ) ;
V_36 = V_6 & V_45 ;
}
}
return V_36 ;
}
static inline unsigned short F_31 ( struct V_1 * V_1 )
{
if ( V_1 -> V_46 -> V_47 )
return V_48 ;
else
return V_49 ;
}
static void F_32 ( struct V_1 * V_1 , T_1 V_4 ,
T_1 V_50 , T_1 V_51 )
{
T_1 V_6 , V_52 , V_53 ;
int V_54 = 0 ;
if ( ! V_4 ) {
V_52 = V_55 | V_56 ;
V_53 = V_50 ;
} else {
V_52 = V_56 ;
V_53 = V_4 ;
}
F_20 ( V_1 , V_53 , V_52 , V_51 ) ;
do {
V_6 = F_2 ( V_1 , V_51 ) ;
if ( V_54 ++ > 1000000 ) {
F_17 ( F_18 ( V_1 ) ,
L_3
L_4 , V_51 , V_53 ) ;
break;
}
F_33 ( 1 ) ;
} while ( ( V_6 & V_52 ) != V_53 );
}
static inline void F_34 ( struct V_1 * V_1 , T_1 V_4 )
{
struct V_57 * V_21 = V_1 -> V_58 [ V_4 ] ;
if ( V_21 -> V_59 )
F_4 ( V_1 , V_60 , V_21 -> V_51 ) ;
F_20 ( V_1 , V_4 , V_56 , V_21 -> V_51 ) ;
F_33 ( 450 ) ;
if ( F_35 ( V_1 ) && V_21 -> V_59 )
F_4 ( V_1 , F_31 ( V_1 ) , V_21 -> V_51 ) ;
else
F_5 ( V_1 , F_31 ( V_1 ) , V_21 -> V_51 ) ;
if ( V_21 -> V_59 )
F_5 ( V_1 , V_60 , V_21 -> V_51 ) ;
}
static int F_36 ( struct V_1 * V_1 ,
struct V_61 * V_62 )
{
T_1 V_63 = 0 , V_64 = 0 ;
T_1 V_65 = 0 ;
if ( V_62 -> V_66 == 0 )
return - V_67 ;
F_6 ( V_1 , V_62 -> V_66 , V_41 ) ;
if ( V_62 -> V_68 )
V_65 |= V_69 ;
V_65 |= V_62 -> type ;
V_65 |= V_62 -> V_70 ;
switch ( V_62 -> type ) {
case V_71 :
V_63 = 4 + ( V_62 -> V_66 - V_72 ) ;
V_64 = 0 ;
break;
case V_73 :
if ( V_62 -> V_66 >= V_74 )
V_63 = V_62 -> V_66 - V_74 ;
else
V_63 = V_62 -> V_66 - V_75 ;
V_63 = V_76 + ( V_63 * 16 ) ;
V_64 = 7 ;
V_65 |= V_77 ;
if ( ! V_62 -> V_68 )
V_65 |= V_78 ;
break;
case V_79 :
V_63 = V_76 +
( V_62 -> V_66 - V_75 ) * 16 ;
V_64 = 7 ;
break;
}
if ( V_64 && ( ( V_63 + 16 ) >= V_80 ) ) {
F_37 ( L_5 ) ;
return - V_81 ;
}
F_6 ( V_1 , V_65 , V_42 ) ;
F_6 ( V_1 , ( V_64 << 10 ) | ( V_63 ) , V_43 ) ;
F_6 ( V_1 , V_62 -> V_82 , V_44 ) ;
if ( V_62 -> V_83 )
V_62 -> V_83 -- ;
F_6 ( V_1 , V_62 -> V_83 , V_84 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_1 ,
struct V_61 * V_62 )
{
if ( V_62 -> V_66 == 0 )
return;
if ( F_39 ( V_62 -> V_66 ) ) {
V_1 -> V_85 -- ;
} else if ( F_40 ( V_62 -> V_66 ) ) {
V_1 -> V_86 -- ;
} else if ( F_41 ( V_62 -> V_66 ) ) {
V_1 -> V_87 -- ;
if ( V_62 -> type == V_73 )
V_1 -> V_85 -- ;
} else {
F_17 ( F_18 ( V_1 ) ,
L_6 , V_62 -> V_66 ) ;
}
}
static void F_42 ( struct V_57 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
F_20 ( V_1 , 0 , V_56 , V_21 -> V_51 ) ;
F_6 ( V_1 , V_88 , V_21 -> V_89 ) ;
F_6 ( V_1 , 0 , V_21 -> V_89 ) ;
F_6 ( V_1 , V_32 , V_21 -> V_89 ) ;
if ( V_21 -> V_59 ) {
F_20 ( V_1 , V_21 -> V_4 , V_56 , V_21 -> V_51 ) ;
F_33 ( 450 ) ;
F_5 ( V_1 , F_31 ( V_1 ) , V_21 -> V_51 ) ;
}
}
static void F_43 ( struct V_1 * V_1 ,
struct V_57 * V_21 ,
const struct V_90 * V_91 ,
T_1 V_4 , int V_92 )
{
V_21 -> V_59 = 0 ;
V_21 -> V_93 = V_94 ;
V_21 -> V_51 = V_95 ;
V_21 -> V_96 = V_97 ;
V_21 -> V_89 = F_16 ( V_4 ) ;
if ( F_39 ( V_4 ) || F_41 ( V_4 ) ) {
V_21 -> V_98 = F_44 ( V_4 ) ;
V_21 -> V_99 = F_45 ( V_4 ) ;
} else {
V_21 -> V_98 = 0 ;
V_21 -> V_99 = 0 ;
}
V_21 -> V_4 = V_4 ;
V_21 -> V_21 . V_82 = F_46 ( V_91 ) ;
V_1 -> V_58 [ V_4 ] = V_21 ;
V_1 -> V_100 [ V_91 -> V_101 & V_102 ]
= V_21 ;
F_14 ( & V_21 -> V_22 ) ;
}
static void F_47 ( struct V_57 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_4 = V_21 -> V_4 ;
if ( V_4 == 0 )
return;
if ( V_21 -> V_59 )
V_1 -> V_103 -- ;
V_21 -> V_4 = 0 ;
V_21 -> V_104 = 0 ;
V_21 -> V_59 = 0 ;
}
static int F_48 ( struct V_57 * V_21 ,
const struct V_90 * V_91 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_61 V_62 ;
int V_92 = 0 ;
unsigned char * V_105 ;
int V_31 ;
V_21 -> V_91 = V_91 ;
if ( V_21 -> V_4 )
return 0 ;
switch ( V_91 -> V_106 & V_107 ) {
case V_108 :
if ( V_1 -> V_85 >= V_109 ) {
if ( V_1 -> V_87 >= V_110 ) {
F_17 ( F_18 ( V_1 ) ,
L_7 ) ;
return - V_111 ;
} else {
V_62 . V_66 = V_75
+ V_1 -> V_87 ;
V_105 = & V_1 -> V_87 ;
}
} else {
V_62 . V_66 = V_74 + V_1 -> V_85 ;
V_105 = & V_1 -> V_85 ;
}
V_62 . type = V_73 ;
V_92 = 1 ;
break;
case V_112 :
if ( V_1 -> V_86 >= V_113 ) {
F_17 ( F_18 ( V_1 ) ,
L_8 ) ;
return - V_111 ;
}
V_62 . V_66 = V_72 + V_1 -> V_86 ;
V_62 . type = V_71 ;
V_105 = & V_1 -> V_86 ;
break;
case V_114 :
if ( V_1 -> V_87 >= V_110 ) {
F_17 ( F_18 ( V_1 ) ,
L_9 ) ;
return - V_111 ;
}
V_62 . V_66 = V_75 + V_1 -> V_87 ;
V_62 . type = V_79 ;
V_105 = & V_1 -> V_87 ;
break;
default:
F_17 ( F_18 ( V_1 ) , L_10 ) ;
return - V_67 ;
}
V_21 -> type = V_62 . type ;
V_62 . V_70 = V_91 -> V_101 & V_102 ;
V_62 . V_82 = F_46 ( V_91 ) ;
V_62 . V_83 = V_91 -> V_115 ;
if ( V_91 -> V_101 & V_116 )
V_62 . V_68 = 1 ;
else
V_62 . V_68 = 0 ;
V_31 = F_36 ( V_1 , & V_62 ) ;
if ( V_31 < 0 ) {
F_17 ( F_18 ( V_1 ) ,
L_11 ) ;
return V_31 ;
}
( * V_105 ) ++ ;
if ( ( V_105 == & V_1 -> V_87 ) && V_62 . type == V_73 )
V_1 -> V_85 ++ ;
F_43 ( V_1 , V_21 , V_91 , V_62 . V_66 , V_92 ) ;
F_42 ( V_21 ) ;
return 0 ;
}
static int F_49 ( struct V_57 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_61 V_62 ;
V_62 . V_66 = V_21 -> V_4 ;
V_62 . type = V_21 -> type ;
F_38 ( V_1 , & V_62 ) ;
F_47 ( V_21 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_1 , T_1 V_4 )
{
F_51 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 ) ;
}
static void F_53 ( struct V_1 * V_1 , T_1 V_4 )
{
F_54 ( V_1 , V_4 ) ;
F_55 ( V_1 , V_4 ) ;
}
static void F_56 ( struct V_1 * V_1 , unsigned V_117 )
{
V_1 -> V_21 [ 0 ] . V_118 = V_117 ;
F_21 ( V_1 , 0 ) ;
F_5 ( V_1 , V_119 , V_25 ) ;
}
static void F_57 ( struct V_57 * V_21 ,
struct V_120 * V_121 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
F_34 ( V_1 , V_21 -> V_4 ) ;
F_20 ( V_1 , V_55 , ( V_55 | V_56 ) , V_95 ) ;
F_6 ( V_1 , V_122 , V_21 -> V_96 ) ;
if ( V_121 -> V_121 . V_123 == 0 ) {
F_5 ( V_1 , V_124 , V_21 -> V_96 ) ;
F_21 ( V_1 , 0 ) ;
F_58 ( V_21 , V_121 , 0 ) ;
} else {
F_6 ( V_1 , ~ V_125 , V_126 ) ;
F_59 ( V_21 , V_121 ) ;
}
}
static void F_60 ( struct V_1 * V_1 , T_1 V_4 ,
T_1 V_51 )
{
T_1 V_6 ;
V_6 = F_2 ( V_1 , V_51 ) & V_56 ;
if ( V_6 == V_4 )
F_32 ( V_1 , 0 , 0 , V_51 ) ;
}
static void F_61 ( struct V_1 * V_1 , T_1 V_4 ,
int V_127 )
{
struct V_57 * V_21 = V_1 -> V_58 [ V_4 ] ;
T_1 V_6 , V_35 ;
F_6 ( V_1 , V_4 , V_41 ) ;
V_6 = F_2 ( V_1 , V_42 ) & V_128 ;
if ( ( V_127 && V_6 ) || ( ! V_127 && ! V_6 ) )
return;
F_22 ( V_1 , V_4 ) ;
F_60 ( V_1 , V_4 , V_95 ) ;
F_60 ( V_1 , V_4 , V_129 ) ;
F_60 ( V_1 , V_4 , V_130 ) ;
V_35 = F_28 ( V_1 , V_4 ) ;
F_6 ( V_1 , V_4 , V_41 ) ;
if ( V_127 )
F_5 ( V_1 , V_128 , V_42 ) ;
else
F_4 ( V_1 , V_128 , V_42 ) ;
F_5 ( V_1 , V_88 , V_21 -> V_89 ) ;
F_4 ( V_1 , V_88 , V_21 -> V_89 ) ;
F_29 ( V_1 , V_4 , V_35 ) ;
}
static int F_62 ( struct V_1 * V_1 ,
struct V_57 * V_21 ,
struct V_120 * V_121 )
{
struct V_131 * V_92 ;
if ( ! F_35 ( V_1 ) )
return - V_111 ;
if ( ! F_39 ( V_21 -> V_4 ) )
return - V_132 ;
if ( V_1 -> V_92 . V_133 )
return - V_134 ;
V_92 = & V_1 -> V_92 ;
V_92 -> V_133 = 1 ;
if ( V_21 -> V_91 -> V_101 & V_135 ) {
V_92 -> V_136 = 1 ;
} else {
V_92 -> V_136 = 0 ;
F_61 ( V_1 , V_21 -> V_4 , 1 ) ;
}
V_21 -> V_59 = 1 ;
V_21 -> V_92 = V_92 ;
V_21 -> V_93 = V_137 ;
V_21 -> V_51 = V_129 ;
V_21 -> V_96 = V_138 ;
V_121 -> V_121 . V_92 = F_63 ( F_18 ( V_21 -> V_1 ) ,
V_121 -> V_121 . V_139 , V_121 -> V_121 . V_123 ,
V_92 -> V_136 ? V_140 : V_141 ) ;
return 0 ;
}
static void F_64 ( struct V_1 * V_1 ,
struct V_57 * V_21 ,
struct V_120 * V_121 )
{
if ( ! F_35 ( V_1 ) )
return;
F_65 ( F_18 ( V_21 -> V_1 ) ,
V_121 -> V_121 . V_92 , V_121 -> V_121 . V_123 ,
V_21 -> V_92 -> V_136 ? V_140 : V_141 ) ;
F_4 ( V_1 , V_60 , V_21 -> V_51 ) ;
F_32 ( V_1 , 0 , 0 , V_21 -> V_51 ) ;
V_21 -> V_92 -> V_133 = 0 ;
V_21 -> V_59 = 0 ;
V_21 -> V_93 = V_94 ;
V_21 -> V_51 = V_95 ;
V_21 -> V_96 = V_97 ;
}
static void F_66 ( struct V_1 * V_1 , struct V_57 * V_21 ,
struct V_120 * V_121 )
{
F_67 ( V_121 -> V_121 . V_123 == 0 ) ;
F_68 ( V_1 , V_142 , V_143 ) ;
F_68 ( V_1 , V_121 -> V_121 . V_92 , V_144 ) ;
F_68 ( V_1 , V_121 -> V_121 . V_123 , V_145 ) ;
F_68 ( V_1 , V_146 , V_147 ) ;
F_68 ( V_1 , V_148 , V_149 ) ;
}
static void F_69 ( struct V_57 * V_21 ,
struct V_120 * V_121 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_6 ;
F_34 ( V_1 , V_21 -> V_4 ) ;
F_70 ( V_1 , V_21 -> V_4 ) ;
F_21 ( V_1 , V_21 -> V_4 ) ;
if ( V_121 -> V_121 . V_123 == 0 ) {
F_58 ( V_21 , V_121 , 0 ) ;
} else {
F_6 ( V_1 , ~ ( 1 << V_21 -> V_4 ) , V_150 ) ;
if ( F_62 ( V_1 , V_21 , V_121 ) < 0 ) {
F_34 ( V_1 , V_21 -> V_4 ) ;
F_70 ( V_1 , V_21 -> V_4 ) ;
F_21 ( V_1 , V_21 -> V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_71 ( ( V_6 & V_151 ) == 0 ) )
F_50 ( V_1 , V_21 -> V_4 ) ;
else
F_72 ( V_21 , V_121 ) ;
} else {
F_34 ( V_1 , V_21 -> V_4 ) ;
F_55 ( V_1 , V_21 -> V_4 ) ;
F_21 ( V_1 , V_21 -> V_4 ) ;
F_52 ( V_1 , V_21 -> V_4 ) ;
F_66 ( V_1 , V_21 , V_121 ) ;
}
}
}
static void F_73 ( struct V_57 * V_21 ,
struct V_120 * V_121 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_4 = V_21 -> V_4 ;
if ( V_21 -> V_4 == 0 ) {
F_20 ( V_1 , 0 , ( V_55 | V_56 ) , V_95 ) ;
F_6 ( V_1 , V_122 , V_21 -> V_96 ) ;
F_21 ( V_1 , V_4 ) ;
F_50 ( V_1 , V_4 ) ;
} else {
F_22 ( V_1 , V_4 ) ;
if ( V_21 -> V_98 ) {
F_52 ( V_1 , V_4 ) ;
F_6 ( V_1 , V_152 , V_21 -> V_98 ) ;
F_6 ( V_1 ,
F_74 ( V_121 -> V_121 . V_123 , V_21 -> V_21 . V_82 ) ,
V_21 -> V_99 ) ;
F_5 ( V_1 , V_153 , V_21 -> V_98 ) ;
}
if ( F_62 ( V_1 , V_21 , V_121 ) < 0 ) {
F_61 ( V_1 , V_21 -> V_4 , 0 ) ;
F_21 ( V_1 , V_4 ) ;
F_50 ( V_1 , V_4 ) ;
} else {
F_34 ( V_1 , V_4 ) ;
F_66 ( V_1 , V_21 , V_121 ) ;
F_21 ( V_1 , V_4 ) ;
}
}
}
static void F_75 ( struct V_57 * V_21 , struct V_120 * V_121 )
{
if ( V_21 -> V_91 -> V_101 & V_135 )
F_69 ( V_21 , V_121 ) ;
else
F_73 ( V_21 , V_121 ) ;
}
static void F_76 ( struct V_57 * V_21 , struct V_120 * V_121 )
{
T_1 V_154 ;
V_154 = F_2 ( V_21 -> V_1 , V_155 ) & V_156 ;
switch ( V_154 ) {
case V_157 :
F_57 ( V_21 , V_121 ) ;
break;
case V_158 :
F_73 ( V_21 , V_121 ) ;
break;
case V_159 :
F_56 ( V_21 -> V_1 , 0 ) ;
break;
default:
F_17 ( F_18 ( V_21 -> V_1 ) ,
L_12 , V_154 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_1 )
{
T_1 V_160 = V_1 -> V_46 -> V_160 ? V_161 : 0 ;
T_1 V_162 = V_1 -> V_163 ? V_164 : 0 ;
T_1 V_165 = V_1 -> V_46 -> V_165 ? V_166 : 0 ;
if ( V_1 -> V_46 -> V_47 ) {
if ( V_1 -> V_46 -> V_167 )
F_6 ( V_1 , V_1 -> V_46 -> V_167 ,
V_168 ) ;
else
F_6 ( V_1 , 0x0f , V_168 ) ;
F_5 ( V_1 , V_169 , V_13 ) ;
F_4 ( V_1 , V_170 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_170 , V_13 ) ;
F_5 ( V_1 , V_171 , V_13 ) ;
F_5 ( V_1 , V_162 , V_172 ) ;
F_6 ( V_1 , V_173 | V_174 ,
V_175 ) ;
} else {
F_5 ( V_1 , V_160 | V_165 , V_176 ) ;
F_5 ( V_1 , V_169 , V_13 ) ;
F_20 ( V_1 , F_77 ( V_1 -> V_46 ) ,
V_177 , V_13 ) ;
F_4 ( V_1 , V_170 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_170 , V_13 ) ;
F_5 ( V_1 , V_178 , V_13 ) ;
F_78 ( 3 ) ;
F_5 ( V_1 , V_179 , V_13 ) ;
F_78 ( 1 ) ;
F_5 ( V_1 , V_171 , V_13 ) ;
F_5 ( V_1 , V_162 , V_172 ) ;
F_6 ( V_1 , V_173 | V_174 ,
V_175 ) ;
}
}
static void F_12 ( struct V_1 * V_1 )
{
if ( V_1 -> V_46 -> V_47 ) {
F_5 ( V_1 , V_171 , V_13 ) ;
F_4 ( V_1 , V_180 , V_181 ) ;
F_6 ( V_1 , 0 , V_7 ) ;
F_6 ( V_1 , 0 , V_172 ) ;
F_6 ( V_1 , 0 , V_182 ) ;
F_6 ( V_1 , 0 , V_183 ) ;
F_6 ( V_1 , 0 , V_184 ) ;
F_6 ( V_1 , 0 , V_150 ) ;
F_6 ( V_1 , 0 , V_185 ) ;
F_6 ( V_1 , 0 , V_126 ) ;
F_4 ( V_1 , V_170 , V_13 ) ;
F_4 ( V_1 , V_171 , V_13 ) ;
} else {
F_4 ( V_1 , V_180 , V_181 ) ;
F_4 ( V_1 , V_171 , V_13 ) ;
F_79 ( 1 ) ;
F_4 ( V_1 , V_179 , V_13 ) ;
F_79 ( 1 ) ;
F_79 ( 1 ) ;
F_4 ( V_1 , V_178 , V_13 ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
T_1 V_6 ;
if ( ! V_1 -> V_46 -> V_47 ) {
V_6 = F_2 ( V_1 , V_13 ) ;
if ( ! ( V_6 & V_178 ) )
F_5 ( V_1 , V_178 , V_13 ) ;
}
}
static struct V_120 * F_81 ( struct V_57 * V_21 )
{
return F_82 ( V_21 -> V_22 . V_186 , struct V_120 , V_22 ) ;
}
static void F_58 ( struct V_57 * V_21 ,
struct V_120 * V_121 , int V_187 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
int V_188 = 0 ;
if ( F_71 ( V_21 -> V_4 == 0 ) ) {
if ( V_21 -> V_118 ) {
V_21 -> V_118 = 0 ;
return;
}
}
F_83 ( & V_121 -> V_22 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
V_121 -> V_121 . V_187 = - V_189 ;
else
V_121 -> V_121 . V_187 = V_187 ;
if ( ! F_84 ( & V_21 -> V_22 ) )
V_188 = 1 ;
if ( V_21 -> V_59 )
F_64 ( V_21 -> V_1 , V_21 , V_121 ) ;
F_10 ( & V_21 -> V_1 -> V_14 ) ;
V_121 -> V_121 . V_190 ( & V_21 -> V_21 , & V_121 -> V_121 ) ;
F_11 ( & V_21 -> V_1 -> V_14 ) ;
if ( V_188 ) {
V_121 = F_81 ( V_21 ) ;
if ( V_21 -> V_91 )
F_75 ( V_21 , V_121 ) ;
}
}
static void F_59 ( struct V_57 * V_21 , struct V_120 * V_121 )
{
int V_54 ;
T_1 V_6 ;
unsigned V_191 ;
T_2 V_36 ;
void * V_139 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
F_34 ( V_1 , V_4 ) ;
F_5 ( V_1 , V_55 , V_21 -> V_51 ) ;
V_54 = 0 ;
do {
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( V_54 ++ > 100000 ) {
F_17 ( F_18 ( V_1 ) ,
L_13
L_14 ) ;
return;
}
F_33 ( 1 ) ;
} while ( ( V_6 & V_151 ) == 0 );
V_191 = F_30 ( V_1 , V_4 ) ;
V_139 = V_121 -> V_121 . V_139 + V_121 -> V_121 . V_192 ;
V_36 = F_85 ( V_191 , V_121 -> V_121 . V_123 - V_121 -> V_121 . V_192 ) ;
if ( V_121 -> V_121 . V_139 ) {
if ( V_36 > 0 )
F_86 ( V_1 , V_21 , V_139 , V_36 ) ;
if ( ( V_36 == 0 ) || ( ( V_36 % V_21 -> V_21 . V_82 ) != 0 ) )
F_5 ( V_1 , V_124 , V_21 -> V_96 ) ;
}
V_121 -> V_121 . V_192 += V_36 ;
if ( ( ! V_121 -> V_121 . V_193 && ( V_121 -> V_121 . V_192 == V_121 -> V_121 . V_123 ) )
|| ( V_36 % V_21 -> V_21 . V_82 )
|| ( V_36 == 0 ) ) {
F_54 ( V_1 , V_4 ) ;
F_70 ( V_1 , V_4 ) ;
} else {
F_54 ( V_1 , V_4 ) ;
F_87 ( V_1 , V_4 ) ;
}
F_21 ( V_1 , V_4 ) ;
}
static void F_72 ( struct V_57 * V_21 ,
struct V_120 * V_121 )
{
T_1 V_6 ;
unsigned V_191 ;
T_2 V_36 ;
void * V_139 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
F_34 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_71 ( ( V_6 & V_151 ) == 0 ) ) {
F_22 ( V_1 , V_4 ) ;
F_53 ( V_1 , V_4 ) ;
F_17 ( F_18 ( V_1 ) ,
L_15 , V_4 ) ;
return;
}
V_191 = F_30 ( V_1 , V_4 ) ;
V_139 = V_121 -> V_121 . V_139 + V_121 -> V_121 . V_192 ;
V_36 = F_85 ( V_191 , V_121 -> V_121 . V_123 - V_121 -> V_121 . V_192 ) ;
if ( V_121 -> V_121 . V_139 ) {
F_86 ( V_1 , V_21 , V_139 , V_36 ) ;
if ( ( V_36 == 0 )
|| ( ( V_36 % V_21 -> V_21 . V_82 ) != 0 )
|| ( ( V_191 != V_21 -> V_21 . V_82 )
&& ( V_191 > V_36 ) ) )
F_5 ( V_1 , V_124 , V_21 -> V_96 ) ;
}
V_121 -> V_121 . V_192 += V_36 ;
if ( ( ! V_121 -> V_121 . V_193 && ( V_121 -> V_121 . V_192 == V_121 -> V_121 . V_123 ) )
|| ( V_36 % V_21 -> V_21 . V_82 )
|| ( V_36 == 0 ) ) {
F_54 ( V_1 , V_4 ) ;
F_87 ( V_1 , V_4 ) ;
} else {
F_70 ( V_1 , V_4 ) ;
F_50 ( V_1 , V_4 ) ;
}
}
static void F_88 ( struct V_57 * V_21 ,
struct V_120 * V_121 )
{
T_1 V_6 ;
int V_194 , V_191 , V_195 ;
int V_36 ;
void * V_139 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
int V_196 = 0 ;
F_34 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_71 ( ( V_6 & V_151 ) == 0 ) ) {
V_121 -> V_121 . V_187 = - V_197 ;
F_22 ( V_1 , V_4 ) ;
F_53 ( V_1 , V_4 ) ;
F_17 ( F_18 ( V_1 ) , L_16 ) ;
return;
}
V_194 = V_6 & V_198 ;
V_191 = F_30 ( V_1 , V_4 ) ;
V_139 = V_121 -> V_121 . V_139 + V_121 -> V_121 . V_192 ;
V_195 = V_121 -> V_121 . V_123 - V_121 -> V_121 . V_192 ;
if ( V_194 < V_191 )
V_36 = F_85 ( V_194 , V_195 ) ;
else
V_36 = F_85 ( V_191 , V_195 ) ;
V_121 -> V_121 . V_192 += V_36 ;
if ( ( ! V_121 -> V_121 . V_193 && ( V_121 -> V_121 . V_192 == V_121 -> V_121 . V_123 ) )
|| ( V_36 % V_21 -> V_21 . V_82 )
|| ( V_36 == 0 ) ) {
F_22 ( V_1 , V_4 ) ;
F_53 ( V_1 , V_4 ) ;
V_196 = 1 ;
}
if ( V_121 -> V_121 . V_139 ) {
if ( V_36 == 0 )
F_6 ( V_1 , V_122 , V_21 -> V_96 ) ;
else
F_89 ( V_1 , V_21 -> V_93 , V_139 , V_36 ) ;
}
if ( ( V_21 -> V_4 != 0 ) && V_196 )
F_58 ( V_21 , V_121 , 0 ) ;
}
static void F_90 ( struct V_1 * V_1 , T_1 V_187 , T_1 V_199 )
{
T_1 V_200 ;
T_1 V_4 ;
struct V_57 * V_21 ;
struct V_120 * V_121 ;
if ( ( V_187 & V_201 ) && ( V_199 & V_201 ) ) {
F_6 ( V_1 , ~ V_201 , V_150 ) ;
F_20 ( V_1 , 0 , V_56 , V_95 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_121 = F_81 ( V_21 ) ;
F_88 ( V_21 , V_121 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_200 = 1 << V_4 ;
if ( ( V_187 & V_200 ) && ( V_199 & V_200 ) ) {
F_6 ( V_1 , ~ V_200 , V_150 ) ;
V_21 = V_1 -> V_58 [ V_4 ] ;
V_121 = F_81 ( V_21 ) ;
if ( V_21 -> V_91 -> V_101 & V_135 )
F_72 ( V_21 , V_121 ) ;
else
F_88 ( V_21 , V_121 ) ;
}
}
}
}
static void F_91 ( struct V_1 * V_1 , T_1 V_187 , T_1 V_199 )
{
T_1 V_6 ;
T_1 V_200 ;
T_1 V_4 ;
struct V_57 * V_21 ;
struct V_120 * V_121 ;
if ( ( V_187 & V_125 ) && ( V_199 & V_125 ) ) {
F_6 ( V_1 , ~ V_125 , V_126 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_121 = F_81 ( V_21 ) ;
F_59 ( V_21 , V_121 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_200 = 1 << V_4 ;
if ( ( V_187 & V_200 ) && ( V_199 & V_200 ) ) {
F_6 ( V_1 , ~ V_200 , V_126 ) ;
V_6 = F_24 ( V_1 , V_4 ) ;
if ( ( V_6 & V_202 ) == 0 ) {
F_70 ( V_1 , V_4 ) ;
F_53 ( V_1 , V_4 ) ;
F_22 ( V_1 , V_4 ) ;
V_21 = V_1 -> V_58 [ V_4 ] ;
V_121 = F_81 ( V_21 ) ;
if ( ! F_84 ( & V_21 -> V_22 ) )
F_58 ( V_21 , V_121 , 0 ) ;
}
}
}
}
}
static void F_92 ( struct V_1 * V_1 , struct V_203 * V_204 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_57 * V_21 ;
T_1 V_23 ;
T_1 V_187 = 0 ;
T_1 V_205 = F_93 ( V_204 -> V_206 ) ;
switch ( V_204 -> V_207 & V_208 ) {
case V_209 :
V_187 = 1 << V_210 ;
break;
case V_211 :
V_187 = 0 ;
break;
case V_212 :
V_21 = V_1 -> V_100 [ V_205 & V_102 ] ;
V_23 = F_15 ( V_1 , V_21 -> V_4 ) ;
if ( V_23 == V_30 )
V_187 = 1 << V_213 ;
else
V_187 = 0 ;
break;
default:
F_23 ( V_1 , 0 ) ;
return;
}
V_1 -> V_214 = F_94 ( V_187 ) ;
V_1 -> V_215 -> V_139 = & V_1 -> V_214 ;
V_1 -> V_215 -> V_123 = 2 ;
F_10 ( & V_1 -> V_14 ) ;
F_95 ( V_1 -> V_15 . V_216 , V_1 -> V_215 , V_217 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
static void F_96 ( struct V_1 * V_1 ,
struct V_203 * V_204 )
{
switch ( V_204 -> V_207 & V_208 ) {
case V_209 :
F_56 ( V_1 , 1 ) ;
break;
case V_211 :
F_56 ( V_1 , 1 ) ;
break;
case V_212 : {
struct V_57 * V_21 ;
struct V_120 * V_121 ;
T_1 V_205 = F_93 ( V_204 -> V_206 ) ;
V_21 = V_1 -> V_100 [ V_205 & V_102 ] ;
if ( ! V_21 -> V_218 ) {
F_22 ( V_1 , V_21 -> V_4 ) ;
F_25 ( V_1 , V_21 -> V_4 ) ;
F_10 ( & V_1 -> V_14 ) ;
F_97 ( & V_21 -> V_21 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
F_56 ( V_1 , 1 ) ;
V_121 = F_81 ( V_21 ) ;
if ( V_21 -> V_104 ) {
V_21 -> V_104 = 0 ;
if ( F_84 ( & V_21 -> V_22 ) )
break;
F_75 ( V_21 , V_121 ) ;
} else if ( ! F_84 ( & V_21 -> V_22 ) )
F_21 ( V_1 , V_21 -> V_4 ) ;
}
break;
default:
F_23 ( V_1 , 0 ) ;
break;
}
}
static void F_98 ( struct V_1 * V_1 , struct V_203 * V_204 )
{
T_1 V_6 ;
int V_219 = 3000 ;
switch ( V_204 -> V_207 & V_208 ) {
case V_209 :
switch ( F_93 ( V_204 -> V_220 ) ) {
case V_221 :
F_56 ( V_1 , 1 ) ;
do {
V_6 = F_2 ( V_1 , V_155 ) & V_156 ;
F_79 ( 1 ) ;
} while ( V_6 != V_222 || V_219 -- > 0 );
if ( V_6 == V_222 )
F_5 ( V_1 ,
F_93 ( V_204 -> V_206 >> 8 ) ,
V_181 ) ;
break;
default:
F_23 ( V_1 , 0 ) ;
break;
}
break;
case V_211 :
F_56 ( V_1 , 1 ) ;
break;
case V_212 : {
struct V_57 * V_21 ;
T_1 V_205 = F_93 ( V_204 -> V_206 ) ;
V_21 = V_1 -> V_100 [ V_205 & V_102 ] ;
F_23 ( V_1 , V_21 -> V_4 ) ;
F_56 ( V_1 , 1 ) ;
}
break;
default:
F_23 ( V_1 , 0 ) ;
break;
}
}
static int F_99 ( struct V_1 * V_1 , struct V_203 * V_204 )
{
T_1 * V_223 = ( T_1 * ) V_204 ;
unsigned long V_24 = V_224 ;
int V_54 , V_31 = 0 ;
F_6 ( V_1 , ~ V_225 , V_155 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ )
V_223 [ V_54 ] = F_2 ( V_1 , V_24 + V_54 * 2 ) ;
if ( ( V_204 -> V_207 & V_226 ) == V_227 ) {
switch ( V_204 -> V_228 ) {
case V_229 :
F_92 ( V_1 , V_204 ) ;
break;
case V_230 :
F_96 ( V_1 , V_204 ) ;
break;
case V_231 :
F_98 ( V_1 , V_204 ) ;
break;
default:
V_31 = 1 ;
break;
}
} else
V_31 = 1 ;
return V_31 ;
}
static void F_100 ( struct V_1 * V_1 )
{
T_1 V_16 = F_1 ( V_1 ) ;
switch ( V_16 ) {
case V_232 :
V_1 -> V_15 . V_16 = V_233 ;
break;
case V_234 :
V_1 -> V_15 . V_16 = V_235 ;
break;
default:
V_1 -> V_15 . V_16 = V_17 ;
F_17 ( F_18 ( V_1 ) , L_17 ) ;
}
}
static void F_101 ( struct V_1 * V_1 )
{
T_1 V_236 ;
V_236 = F_2 ( V_1 , V_155 ) & V_237 ;
F_6 ( V_1 , ~ V_238 , V_155 ) ;
if ( V_236 == V_239 ) {
F_10 ( & V_1 -> V_14 ) ;
V_1 -> V_18 -> V_19 ( & V_1 -> V_15 ) ;
F_11 ( & V_1 -> V_14 ) ;
F_100 ( V_1 ) ;
}
if ( V_1 -> V_240 == V_241 && V_236 != V_241 )
F_100 ( V_1 ) ;
if ( ( V_236 == V_241 || V_236 == V_242 )
&& V_1 -> V_15 . V_16 == V_17 )
F_100 ( V_1 ) ;
V_1 -> V_240 = V_236 ;
}
static void F_102 ( struct V_1 * V_1 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_203 V_204 ;
T_1 V_154 ;
V_154 = F_2 ( V_1 , V_155 ) & V_156 ;
F_6 ( V_1 , ~ V_243 , V_155 ) ;
switch ( V_154 ) {
case V_222 : {
struct V_57 * V_21 ;
struct V_120 * V_121 ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_121 = F_81 ( V_21 ) ;
F_58 ( V_21 , V_121 , 0 ) ;
}
break;
case V_157 :
case V_158 :
case V_159 :
if ( F_99 ( V_1 , & V_204 ) ) {
F_10 ( & V_1 -> V_14 ) ;
if ( V_1 -> V_18 -> V_244 ( & V_1 -> V_15 , & V_204 )
< 0 )
F_23 ( V_1 , 0 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
break;
case V_245 :
case V_246 :
F_56 ( V_1 , 0 ) ;
break;
default:
F_17 ( F_18 ( V_1 ) ,
L_18 , V_154 ) ;
break;
}
}
static void F_103 ( struct V_1 * V_1 , struct V_57 * V_21 )
{
T_1 V_4 ;
struct V_120 * V_121 ;
T_3 V_247 ;
int V_54 = 0 ;
V_4 = V_21 -> V_4 ;
F_34 ( V_1 , V_4 ) ;
while ( ! ( F_2 ( V_1 , V_21 -> V_96 ) & V_151 ) ) {
F_79 ( 1 ) ;
if ( F_71 ( V_54 ++ >= 10000 ) ) {
F_17 ( F_18 ( V_1 ) ,
L_19 ,
V_248 , V_4 ) ;
return;
}
}
F_5 ( V_1 , V_122 , V_21 -> V_96 ) ;
V_121 = F_81 ( V_21 ) ;
V_247 = F_104 ( V_1 , V_249 ) ;
V_121 -> V_121 . V_192 += V_247 ;
F_68 ( V_1 , V_250 , V_251 ) ;
if ( ( ! V_121 -> V_121 . V_193 && ( V_121 -> V_121 . V_192 == V_121 -> V_121 . V_123 ) )
|| ( V_247 % V_21 -> V_21 . V_82 ) ) {
if ( V_21 -> V_92 -> V_136 ) {
F_54 ( V_1 , V_4 ) ;
F_87 ( V_1 , V_4 ) ;
} else {
F_6 ( V_1 , ~ ( 1 << V_4 ) , V_150 ) ;
F_58 ( V_21 , V_121 , 0 ) ;
}
}
}
static void F_105 ( struct V_1 * V_1 )
{
T_3 V_252 ;
struct V_57 * V_21 ;
T_1 V_4 ;
V_252 = F_104 ( V_1 , V_253 ) ;
if ( V_252 & V_254 ) {
F_68 ( V_1 , V_255 , V_256 ) ;
V_4 = ( F_2 ( V_1 , V_129 ) & V_56 ) ;
V_21 = V_1 -> V_58 [ V_4 ] ;
F_103 ( V_1 , V_21 ) ;
}
}
static T_4 F_106 ( int V_257 , void * V_258 )
{
struct V_1 * V_1 = V_258 ;
T_1 V_259 ;
T_1 V_260 ;
T_1 V_261 , V_262 , V_263 ;
T_1 V_264 , V_265 , V_266 ;
T_1 V_267 ;
T_1 V_268 ;
if ( F_35 ( V_1 ) )
F_105 ( V_1 ) ;
F_11 ( & V_1 -> V_14 ) ;
V_259 = F_2 ( V_1 , V_155 ) ;
V_260 = F_2 ( V_1 , V_7 ) ;
V_267 = F_2 ( V_1 , V_95 ) ;
V_268 = V_259 & V_260 ;
if ( V_268 ) {
V_261 = F_2 ( V_1 , V_150 ) ;
V_262 = F_2 ( V_1 , V_185 ) ;
V_263 = F_2 ( V_1 , V_126 ) ;
V_264 = F_2 ( V_1 , V_182 ) ;
V_265 = F_2 ( V_1 , V_184 ) ;
V_266 = F_2 ( V_1 , V_183 ) ;
if ( V_268 & V_269 ) {
F_6 ( V_1 , 0xffff & ~ V_269 ,
V_155 ) ;
F_80 ( V_1 ) ;
V_1 -> V_270 = F_2 ( V_1 , V_155 )
& V_271 ;
V_1 -> V_272 = V_273 ;
F_107 ( & V_1 -> V_274 ,
V_275 + F_108 ( 50 ) ) ;
}
if ( V_259 & V_237 )
F_101 ( V_1 ) ;
if ( ( V_259 & V_276 ) && ( V_260 & V_10 )
&& ( V_261 & V_264 ) )
F_90 ( V_1 , V_261 , V_264 ) ;
if ( ( V_259 & V_277 ) && ( V_260 & V_8 )
&& ( V_263 & V_266 ) )
F_91 ( V_1 , V_263 , V_266 ) ;
if ( V_259 & V_243 )
F_102 ( V_1 ) ;
}
F_6 ( V_1 , V_267 , V_95 ) ;
F_10 ( & V_1 -> V_14 ) ;
return V_278 ;
}
static void F_109 ( unsigned long V_258 )
{
struct V_1 * V_1 = (struct V_1 * ) V_258 ;
unsigned long V_279 ;
T_1 V_6 ;
F_110 ( & V_1 -> V_14 , V_279 ) ;
V_6 = F_2 ( V_1 , V_13 ) ;
if ( V_1 -> V_272 > 0 ) {
V_6 = F_2 ( V_1 , V_155 ) & V_271 ;
if ( V_6 == V_1 -> V_270 ) {
V_1 -> V_272 -- ;
if ( V_1 -> V_272 == 0 ) {
if ( V_6 == V_271 )
F_8 ( V_1 ) ;
else
F_9 ( V_1 ) ;
} else {
F_107 ( & V_1 -> V_274 ,
V_275 + F_108 ( 50 ) ) ;
}
} else {
V_1 -> V_272 = V_273 ;
V_1 -> V_270 = V_6 ;
F_107 ( & V_1 -> V_274 ,
V_275 + F_108 ( 50 ) ) ;
}
}
F_111 ( & V_1 -> V_14 , V_279 ) ;
}
static int F_112 ( struct V_280 * V_281 ,
const struct V_90 * V_91 )
{
struct V_57 * V_21 ;
V_21 = F_113 ( V_281 , struct V_57 , V_21 ) ;
return F_48 ( V_21 , V_91 ) ;
}
static int F_114 ( struct V_280 * V_281 )
{
struct V_57 * V_21 ;
struct V_120 * V_121 ;
unsigned long V_279 ;
V_21 = F_113 ( V_281 , struct V_57 , V_21 ) ;
F_67 ( ! V_21 ) ;
while ( ! F_84 ( & V_21 -> V_22 ) ) {
V_121 = F_81 ( V_21 ) ;
F_110 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
F_58 ( V_21 , V_121 , - V_282 ) ;
F_111 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
}
F_53 ( V_21 -> V_1 , V_21 -> V_4 ) ;
return F_49 ( V_21 ) ;
}
static struct V_283 * F_115 ( struct V_280 * V_281 ,
T_5 V_284 )
{
struct V_120 * V_121 ;
V_121 = F_116 ( sizeof( struct V_120 ) , V_284 ) ;
if ( ! V_121 )
return NULL ;
F_14 ( & V_121 -> V_22 ) ;
return & V_121 -> V_121 ;
}
static void F_117 ( struct V_280 * V_281 , struct V_283 * V_285 )
{
struct V_120 * V_121 ;
V_121 = F_113 ( V_285 , struct V_120 , V_121 ) ;
F_118 ( V_121 ) ;
}
static int F_95 ( struct V_280 * V_281 , struct V_283 * V_285 ,
T_5 V_284 )
{
struct V_57 * V_21 ;
struct V_120 * V_121 ;
unsigned long V_279 ;
int V_286 = 0 ;
V_21 = F_113 ( V_281 , struct V_57 , V_21 ) ;
V_121 = F_113 ( V_285 , struct V_120 , V_121 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
return - V_189 ;
F_110 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
if ( F_84 ( & V_21 -> V_22 ) )
V_286 = 1 ;
F_119 ( & V_121 -> V_22 , & V_21 -> V_22 ) ;
V_121 -> V_121 . V_192 = 0 ;
V_121 -> V_121 . V_187 = - V_287 ;
if ( V_21 -> V_91 == NULL )
F_76 ( V_21 , V_121 ) ;
else {
if ( V_286 && ! V_21 -> V_104 )
F_75 ( V_21 , V_121 ) ;
}
F_111 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
return 0 ;
}
static int F_120 ( struct V_280 * V_281 , struct V_283 * V_285 )
{
struct V_57 * V_21 ;
struct V_120 * V_121 ;
unsigned long V_279 ;
V_21 = F_113 ( V_281 , struct V_57 , V_21 ) ;
V_121 = F_113 ( V_285 , struct V_120 , V_121 ) ;
F_110 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
if ( ! F_84 ( & V_21 -> V_22 ) )
F_58 ( V_21 , V_121 , - V_282 ) ;
F_111 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
return 0 ;
}
static int F_121 ( struct V_280 * V_281 , int V_288 )
{
struct V_57 * V_21 ;
struct V_120 * V_121 ;
unsigned long V_279 ;
int V_31 = 0 ;
V_21 = F_113 ( V_281 , struct V_57 , V_21 ) ;
V_121 = F_81 ( V_21 ) ;
F_110 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
if ( ! F_84 ( & V_21 -> V_22 ) ) {
V_31 = - V_289 ;
goto V_290;
}
if ( V_288 ) {
V_21 -> V_104 = 1 ;
F_23 ( V_21 -> V_1 , V_21 -> V_4 ) ;
} else {
V_21 -> V_104 = 0 ;
V_21 -> V_218 = 0 ;
F_22 ( V_21 -> V_1 , V_21 -> V_4 ) ;
}
V_290:
F_111 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
return V_31 ;
}
static int F_122 ( struct V_280 * V_281 )
{
struct V_57 * V_21 ;
unsigned long V_279 ;
V_21 = F_113 ( V_281 , struct V_57 , V_21 ) ;
if ( ! V_21 || ! V_21 -> V_91 )
return - V_67 ;
F_110 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
V_21 -> V_218 = 1 ;
F_111 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
return F_123 ( V_281 ) ;
}
static void F_124 ( struct V_280 * V_281 )
{
struct V_57 * V_21 ;
unsigned long V_279 ;
V_21 = F_113 ( V_281 , struct V_57 , V_21 ) ;
F_110 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
if ( F_84 ( & V_21 -> V_22 ) && ! V_21 -> V_104 ) {
F_22 ( V_21 -> V_1 , V_21 -> V_4 ) ;
F_4 ( V_21 -> V_1 , V_122 , V_21 -> V_96 ) ;
F_6 ( V_21 -> V_1 , V_88 , V_21 -> V_89 ) ;
F_6 ( V_21 -> V_1 , 0 , V_21 -> V_89 ) ;
}
F_111 ( & V_21 -> V_1 -> V_14 , V_279 ) ;
}
static int F_125 ( struct V_291 * V_15 ,
struct V_292 * V_18 )
{
struct V_1 * V_1 = F_126 ( V_15 ) ;
if ( ! V_18
|| V_18 -> V_16 < V_233
|| ! V_18 -> V_244 )
return - V_67 ;
if ( ! V_1 )
return - V_111 ;
V_1 -> V_18 = V_18 ;
F_13 ( V_1 ) ;
F_5 ( V_1 , V_20 , V_7 ) ;
if ( F_2 ( V_1 , V_155 ) & V_271 ) {
F_80 ( V_1 ) ;
V_1 -> V_270 = F_2 ( V_1 ,
V_155 ) & V_271 ;
V_1 -> V_272 = V_273 ;
F_107 ( & V_1 -> V_274 , V_275 + F_108 ( 50 ) ) ;
}
return 0 ;
}
static int F_127 ( struct V_291 * V_15 ,
struct V_292 * V_18 )
{
struct V_1 * V_1 = F_126 ( V_15 ) ;
unsigned long V_279 ;
F_110 ( & V_1 -> V_14 , V_279 ) ;
F_4 ( V_1 , V_20 , V_7 ) ;
F_12 ( V_1 ) ;
F_111 ( & V_1 -> V_14 , V_279 ) ;
V_1 -> V_18 = NULL ;
return 0 ;
}
static int F_128 ( struct V_291 * V_293 )
{
struct V_1 * V_1 = F_126 ( V_293 ) ;
return F_2 ( V_1 , V_294 ) & 0x03FF ;
}
static int F_129 ( struct V_291 * V_15 , int V_295 )
{
struct V_1 * V_1 = F_126 ( V_15 ) ;
unsigned long V_279 ;
F_110 ( & V_1 -> V_14 , V_279 ) ;
if ( V_295 )
F_5 ( V_1 , V_12 , V_13 ) ;
else
F_4 ( V_1 , V_12 , V_13 ) ;
F_111 ( & V_1 -> V_14 , V_279 ) ;
return 0 ;
}
static int T_6 F_130 ( struct V_296 * V_297 )
{
struct V_1 * V_1 = F_131 ( & V_297 -> V_298 ) ;
F_132 ( & V_1 -> V_15 ) ;
F_133 ( & V_1 -> V_274 ) ;
F_134 ( V_1 -> V_5 ) ;
if ( V_1 -> V_46 -> V_299 )
F_134 ( V_1 -> V_300 ) ;
F_135 ( F_136 ( V_297 , 0 ) , V_1 ) ;
F_117 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_215 ) ;
#ifdef F_137
if ( V_1 -> V_46 -> V_47 ) {
F_138 ( V_1 -> V_301 ) ;
F_139 ( V_1 -> V_301 ) ;
}
#endif
F_140 ( & V_1 -> V_15 . V_298 ) ;
F_118 ( V_1 ) ;
return 0 ;
}
static void F_141 ( struct V_280 * V_21 , struct V_283 * V_302 )
{
}
static int T_7 F_142 ( struct V_1 * V_1 ,
struct V_296 * V_297 )
{
struct V_303 * V_304 ;
V_304 = F_143 ( V_297 , V_305 , L_20 ) ;
if ( ! V_304 ) {
F_17 ( & V_297 -> V_298 , L_21 ) ;
return - V_111 ;
}
V_1 -> V_300 = F_144 ( V_304 -> V_306 , F_145 ( V_304 ) ) ;
if ( V_1 -> V_300 == NULL ) {
F_17 ( & V_297 -> V_298 , L_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int T_7 F_146 ( struct V_296 * V_297 )
{
#ifdef F_137
char V_307 [ 8 ] ;
#endif
struct V_303 * V_304 , * V_308 ;
int V_257 ;
void T_8 * V_5 = NULL ;
struct V_1 * V_1 = NULL ;
int V_31 = 0 ;
int V_54 ;
unsigned long V_309 ;
V_304 = F_147 ( V_297 , V_305 , 0 ) ;
if ( ! V_304 ) {
V_31 = - V_111 ;
F_17 ( & V_297 -> V_298 , L_23 ) ;
goto V_310;
}
V_308 = F_147 ( V_297 , V_311 , 0 ) ;
V_257 = V_308 -> V_306 ;
V_309 = V_308 -> V_279 & V_312 ;
if ( V_257 < 0 ) {
V_31 = - V_111 ;
F_17 ( & V_297 -> V_298 , L_24 ) ;
goto V_310;
}
V_5 = F_144 ( V_304 -> V_306 , F_145 ( V_304 ) ) ;
if ( V_5 == NULL ) {
V_31 = - V_81 ;
F_17 ( & V_297 -> V_298 , L_25 ) ;
goto V_310;
}
V_1 = F_116 ( sizeof( struct V_1 ) , V_217 ) ;
if ( V_1 == NULL ) {
V_31 = - V_81 ;
F_17 ( & V_297 -> V_298 , L_26 ) ;
goto V_310;
}
F_148 ( & V_1 -> V_14 ) ;
F_149 ( & V_297 -> V_298 , V_1 ) ;
V_1 -> V_46 = V_297 -> V_298 . V_313 ;
V_1 -> V_163 = V_309 == V_314 ;
V_1 -> V_15 . V_315 = & V_316 ;
F_150 ( & V_1 -> V_15 . V_298 , L_27 ) ;
V_1 -> V_15 . V_317 = 1 ;
V_1 -> V_15 . V_298 . V_318 = & V_297 -> V_298 ;
V_1 -> V_15 . V_298 . V_319 = V_297 -> V_298 . V_319 ;
V_1 -> V_15 . V_298 . V_320 = V_297 -> V_298 . V_320 ;
V_1 -> V_15 . V_321 = V_322 ;
V_31 = F_151 ( & V_1 -> V_15 . V_298 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_297 -> V_298 , L_28 ) ;
goto V_310;
}
F_152 ( & V_1 -> V_274 ) ;
V_1 -> V_274 . V_323 = F_109 ;
V_1 -> V_274 . V_324 = ( unsigned long ) V_1 ;
V_1 -> V_5 = V_5 ;
#ifdef F_137
if ( V_1 -> V_46 -> V_47 ) {
snprintf ( V_307 , sizeof( V_307 ) , L_29 , V_297 -> V_325 ) ;
V_1 -> V_301 = F_153 ( & V_297 -> V_298 , V_307 ) ;
if ( F_154 ( V_1 -> V_301 ) ) {
F_17 ( & V_297 -> V_298 , L_30 ,
V_307 ) ;
V_31 = F_155 ( V_1 -> V_301 ) ;
goto V_326;
}
F_156 ( V_1 -> V_301 ) ;
}
#endif
if ( V_1 -> V_46 -> V_299 ) {
V_31 = F_142 ( V_1 , V_297 ) ;
if ( V_31 < 0 )
goto V_327;
}
F_12 ( V_1 ) ;
V_31 = F_157 ( V_257 , F_106 , V_328 ,
V_322 , V_1 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_297 -> V_298 , L_31 , V_31 ) ;
goto V_327;
}
F_14 ( & V_1 -> V_15 . V_329 ) ;
V_1 -> V_15 . V_216 = & V_1 -> V_21 [ 0 ] . V_21 ;
F_14 ( & V_1 -> V_15 . V_216 -> V_329 ) ;
for ( V_54 = 0 ; V_54 < V_27 ; V_54 ++ ) {
struct V_57 * V_21 = & V_1 -> V_21 [ V_54 ] ;
if ( V_54 != 0 ) {
F_14 ( & V_1 -> V_21 [ V_54 ] . V_21 . V_329 ) ;
F_119 ( & V_1 -> V_21 [ V_54 ] . V_21 . V_329 ,
& V_1 -> V_15 . V_329 ) ;
}
V_21 -> V_1 = V_1 ;
F_14 ( & V_21 -> V_22 ) ;
V_21 -> V_21 . V_321 = V_330 [ V_54 ] ;
V_21 -> V_21 . V_315 = & V_331 ;
V_21 -> V_21 . V_82 = 512 ;
}
V_1 -> V_21 [ 0 ] . V_21 . V_82 = 64 ;
V_1 -> V_21 [ 0 ] . V_4 = 0 ;
V_1 -> V_21 [ 0 ] . V_93 = V_94 ;
V_1 -> V_21 [ 0 ] . V_51 = V_95 ;
V_1 -> V_21 [ 0 ] . V_96 = V_97 ;
V_1 -> V_21 [ 0 ] . V_89 = F_16 ( 0 ) ;
V_1 -> V_58 [ 0 ] = & V_1 -> V_21 [ 0 ] ;
V_1 -> V_100 [ 0 ] = & V_1 -> V_21 [ 0 ] ;
V_1 -> V_215 = F_115 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_217 ) ;
if ( V_1 -> V_215 == NULL )
goto V_332;
V_1 -> V_215 -> V_190 = F_141 ;
V_31 = F_158 ( & V_297 -> V_298 , & V_1 -> V_15 ) ;
if ( V_31 )
goto V_333;
F_159 ( & V_297 -> V_298 , L_32 , V_334 ) ;
return 0 ;
V_333:
F_117 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_215 ) ;
V_332:
F_135 ( V_257 , V_1 ) ;
V_327:
#ifdef F_137
if ( V_1 -> V_46 -> V_47 ) {
F_138 ( V_1 -> V_301 ) ;
F_139 ( V_1 -> V_301 ) ;
}
V_326:
#endif
F_140 ( & V_1 -> V_15 . V_298 ) ;
V_310:
if ( V_1 ) {
if ( V_1 -> V_300 )
F_134 ( V_1 -> V_300 ) ;
if ( V_1 -> V_215 )
F_117 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_1 -> V_215 ) ;
F_118 ( V_1 ) ;
}
if ( V_5 )
F_134 ( V_5 ) ;
return V_31 ;
}
static int T_7 F_160 ( void )
{
return F_161 ( & V_335 , F_146 ) ;
}
static void T_6 F_162 ( void )
{
F_163 ( & V_335 ) ;
}
