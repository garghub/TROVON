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
V_21 -> V_21 . V_91 = V_91 ;
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
if ( V_21 -> V_21 . V_91 -> V_101 & V_135 ) {
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
return F_63 ( & V_1 -> V_15 , & V_121 -> V_121 , V_92 -> V_136 ) ;
}
static void F_64 ( struct V_1 * V_1 ,
struct V_57 * V_21 ,
struct V_120 * V_121 )
{
if ( ! F_35 ( V_1 ) )
return;
F_65 ( & V_1 -> V_15 , & V_121 -> V_121 , V_21 -> V_92 -> V_136 ) ;
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
F_68 ( V_1 , V_139 , V_140 ) ;
F_68 ( V_1 , V_121 -> V_121 . V_92 , V_141 ) ;
F_68 ( V_1 , V_121 -> V_121 . V_123 , V_142 ) ;
F_68 ( V_1 , V_143 , V_144 ) ;
F_68 ( V_1 , V_145 , V_146 ) ;
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
F_6 ( V_1 , ~ ( 1 << V_21 -> V_4 ) , V_147 ) ;
if ( F_62 ( V_1 , V_21 , V_121 ) < 0 ) {
F_34 ( V_1 , V_21 -> V_4 ) ;
F_70 ( V_1 , V_21 -> V_4 ) ;
F_21 ( V_1 , V_21 -> V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_71 ( ( V_6 & V_148 ) == 0 ) )
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
F_6 ( V_1 , V_149 , V_21 -> V_98 ) ;
F_6 ( V_1 ,
F_74 ( V_121 -> V_121 . V_123 , V_21 -> V_21 . V_82 ) ,
V_21 -> V_99 ) ;
F_5 ( V_1 , V_150 , V_21 -> V_98 ) ;
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
if ( V_21 -> V_21 . V_91 -> V_101 & V_135 )
F_69 ( V_21 , V_121 ) ;
else
F_73 ( V_21 , V_121 ) ;
}
static void F_76 ( struct V_57 * V_21 , struct V_120 * V_121 )
{
T_1 V_151 ;
V_151 = F_2 ( V_21 -> V_1 , V_152 ) & V_153 ;
switch ( V_151 ) {
case V_154 :
F_57 ( V_21 , V_121 ) ;
break;
case V_155 :
F_73 ( V_21 , V_121 ) ;
break;
case V_156 :
F_56 ( V_21 -> V_1 , 0 ) ;
break;
default:
F_17 ( F_18 ( V_21 -> V_1 ) ,
L_12 , V_151 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_1 )
{
T_1 V_157 = V_1 -> V_46 -> V_157 ? V_158 : 0 ;
T_1 V_159 = V_1 -> V_160 ? V_161 : 0 ;
T_1 V_162 = V_1 -> V_46 -> V_162 ? V_163 : 0 ;
if ( V_1 -> V_46 -> V_47 ) {
if ( V_1 -> V_46 -> V_164 )
F_6 ( V_1 , V_1 -> V_46 -> V_164 ,
V_165 ) ;
else
F_6 ( V_1 , 0x0f , V_165 ) ;
F_5 ( V_1 , V_166 , V_13 ) ;
F_4 ( V_1 , V_167 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_167 , V_13 ) ;
F_5 ( V_1 , V_168 , V_13 ) ;
F_5 ( V_1 , V_159 , V_169 ) ;
F_6 ( V_1 , V_170 | V_171 ,
V_172 ) ;
} else {
F_5 ( V_1 , V_157 | V_162 , V_173 ) ;
F_5 ( V_1 , V_166 , V_13 ) ;
F_20 ( V_1 , F_77 ( V_1 -> V_46 ) ,
V_174 , V_13 ) ;
F_4 ( V_1 , V_167 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_167 , V_13 ) ;
F_5 ( V_1 , V_175 , V_13 ) ;
F_78 ( 3 ) ;
F_5 ( V_1 , V_176 , V_13 ) ;
F_78 ( 1 ) ;
F_5 ( V_1 , V_168 , V_13 ) ;
F_5 ( V_1 , V_159 , V_169 ) ;
F_6 ( V_1 , V_170 | V_171 ,
V_172 ) ;
}
}
static void F_12 ( struct V_1 * V_1 )
{
if ( V_1 -> V_46 -> V_47 ) {
F_5 ( V_1 , V_168 , V_13 ) ;
F_4 ( V_1 , V_177 , V_178 ) ;
F_6 ( V_1 , 0 , V_7 ) ;
F_6 ( V_1 , 0 , V_169 ) ;
F_6 ( V_1 , 0 , V_179 ) ;
F_6 ( V_1 , 0 , V_180 ) ;
F_6 ( V_1 , 0 , V_181 ) ;
F_6 ( V_1 , 0 , V_147 ) ;
F_6 ( V_1 , 0 , V_182 ) ;
F_6 ( V_1 , 0 , V_126 ) ;
F_4 ( V_1 , V_167 , V_13 ) ;
F_4 ( V_1 , V_168 , V_13 ) ;
} else {
F_4 ( V_1 , V_177 , V_178 ) ;
F_4 ( V_1 , V_168 , V_13 ) ;
F_79 ( 1 ) ;
F_4 ( V_1 , V_176 , V_13 ) ;
F_79 ( 1 ) ;
F_79 ( 1 ) ;
F_4 ( V_1 , V_175 , V_13 ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
T_1 V_6 ;
if ( ! V_1 -> V_46 -> V_47 ) {
V_6 = F_2 ( V_1 , V_13 ) ;
if ( ! ( V_6 & V_175 ) )
F_5 ( V_1 , V_175 , V_13 ) ;
}
}
static struct V_120 * F_81 ( struct V_57 * V_21 )
{
return F_82 ( V_21 -> V_22 . V_183 , struct V_120 , V_22 ) ;
}
static void F_58 ( struct V_57 * V_21 ,
struct V_120 * V_121 , int V_184 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
int V_185 = 0 ;
if ( F_71 ( V_21 -> V_4 == 0 ) ) {
if ( V_21 -> V_118 ) {
V_21 -> V_118 = 0 ;
return;
}
}
F_83 ( & V_121 -> V_22 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
V_121 -> V_121 . V_184 = - V_186 ;
else
V_121 -> V_121 . V_184 = V_184 ;
if ( ! F_84 ( & V_21 -> V_22 ) )
V_185 = 1 ;
if ( V_21 -> V_59 )
F_64 ( V_21 -> V_1 , V_21 , V_121 ) ;
F_10 ( & V_21 -> V_1 -> V_14 ) ;
V_121 -> V_121 . V_187 ( & V_21 -> V_21 , & V_121 -> V_121 ) ;
F_11 ( & V_21 -> V_1 -> V_14 ) ;
if ( V_185 ) {
V_121 = F_81 ( V_21 ) ;
if ( V_21 -> V_21 . V_91 )
F_75 ( V_21 , V_121 ) ;
}
}
static void F_59 ( struct V_57 * V_21 , struct V_120 * V_121 )
{
int V_54 ;
T_1 V_6 ;
unsigned V_188 ;
T_2 V_36 ;
void * V_189 ;
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
} while ( ( V_6 & V_148 ) == 0 );
V_188 = F_30 ( V_1 , V_4 ) ;
V_189 = V_121 -> V_121 . V_189 + V_121 -> V_121 . V_190 ;
V_36 = F_85 ( V_188 , V_121 -> V_121 . V_123 - V_121 -> V_121 . V_190 ) ;
if ( V_121 -> V_121 . V_189 ) {
if ( V_36 > 0 )
F_86 ( V_1 , V_21 , V_189 , V_36 ) ;
if ( ( V_36 == 0 ) || ( ( V_36 % V_21 -> V_21 . V_82 ) != 0 ) )
F_5 ( V_1 , V_124 , V_21 -> V_96 ) ;
}
V_121 -> V_121 . V_190 += V_36 ;
if ( ( ! V_121 -> V_121 . V_191 && ( V_121 -> V_121 . V_190 == V_121 -> V_121 . V_123 ) )
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
unsigned V_188 ;
T_2 V_36 ;
void * V_189 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
F_34 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_71 ( ( V_6 & V_148 ) == 0 ) ) {
F_22 ( V_1 , V_4 ) ;
F_53 ( V_1 , V_4 ) ;
F_17 ( F_18 ( V_1 ) ,
L_15 , V_4 ) ;
return;
}
V_188 = F_30 ( V_1 , V_4 ) ;
V_189 = V_121 -> V_121 . V_189 + V_121 -> V_121 . V_190 ;
V_36 = F_85 ( V_188 , V_121 -> V_121 . V_123 - V_121 -> V_121 . V_190 ) ;
if ( V_121 -> V_121 . V_189 ) {
F_86 ( V_1 , V_21 , V_189 , V_36 ) ;
if ( ( V_36 == 0 )
|| ( ( V_36 % V_21 -> V_21 . V_82 ) != 0 )
|| ( ( V_188 != V_21 -> V_21 . V_82 )
&& ( V_188 > V_36 ) ) )
F_5 ( V_1 , V_124 , V_21 -> V_96 ) ;
}
V_121 -> V_121 . V_190 += V_36 ;
if ( ( ! V_121 -> V_121 . V_191 && ( V_121 -> V_121 . V_190 == V_121 -> V_121 . V_123 ) )
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
int V_192 , V_188 , V_193 ;
int V_36 ;
void * V_189 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
int V_194 = 0 ;
F_34 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_71 ( ( V_6 & V_148 ) == 0 ) ) {
V_121 -> V_121 . V_184 = - V_195 ;
F_22 ( V_1 , V_4 ) ;
F_53 ( V_1 , V_4 ) ;
F_17 ( F_18 ( V_1 ) , L_16 ) ;
return;
}
V_192 = V_6 & V_196 ;
V_188 = F_30 ( V_1 , V_4 ) ;
V_189 = V_121 -> V_121 . V_189 + V_121 -> V_121 . V_190 ;
V_193 = V_121 -> V_121 . V_123 - V_121 -> V_121 . V_190 ;
if ( V_192 < V_188 )
V_36 = F_85 ( V_192 , V_193 ) ;
else
V_36 = F_85 ( V_188 , V_193 ) ;
V_121 -> V_121 . V_190 += V_36 ;
if ( ( ! V_121 -> V_121 . V_191 && ( V_121 -> V_121 . V_190 == V_121 -> V_121 . V_123 ) )
|| ( V_36 % V_21 -> V_21 . V_82 )
|| ( V_36 == 0 ) ) {
F_22 ( V_1 , V_4 ) ;
F_53 ( V_1 , V_4 ) ;
V_194 = 1 ;
}
if ( V_121 -> V_121 . V_189 ) {
if ( V_36 == 0 )
F_6 ( V_1 , V_122 , V_21 -> V_96 ) ;
else
F_89 ( V_1 , V_21 -> V_93 , V_189 , V_36 ) ;
}
if ( ( V_21 -> V_4 != 0 ) && V_194 )
F_58 ( V_21 , V_121 , 0 ) ;
}
static void F_90 ( struct V_1 * V_1 , T_1 V_184 , T_1 V_197 )
{
T_1 V_198 ;
T_1 V_4 ;
struct V_57 * V_21 ;
struct V_120 * V_121 ;
if ( ( V_184 & V_199 ) && ( V_197 & V_199 ) ) {
F_6 ( V_1 , ~ V_199 , V_147 ) ;
F_20 ( V_1 , 0 , V_56 , V_95 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_121 = F_81 ( V_21 ) ;
F_88 ( V_21 , V_121 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_198 = 1 << V_4 ;
if ( ( V_184 & V_198 ) && ( V_197 & V_198 ) ) {
F_6 ( V_1 , ~ V_198 , V_147 ) ;
V_21 = V_1 -> V_58 [ V_4 ] ;
V_121 = F_81 ( V_21 ) ;
if ( V_21 -> V_21 . V_91 -> V_101 & V_135 )
F_72 ( V_21 , V_121 ) ;
else
F_88 ( V_21 , V_121 ) ;
}
}
}
}
static void F_91 ( struct V_1 * V_1 , T_1 V_184 , T_1 V_197 )
{
T_1 V_6 ;
T_1 V_198 ;
T_1 V_4 ;
struct V_57 * V_21 ;
struct V_120 * V_121 ;
if ( ( V_184 & V_125 ) && ( V_197 & V_125 ) ) {
F_6 ( V_1 , ~ V_125 , V_126 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_121 = F_81 ( V_21 ) ;
F_59 ( V_21 , V_121 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_198 = 1 << V_4 ;
if ( ( V_184 & V_198 ) && ( V_197 & V_198 ) ) {
F_6 ( V_1 , ~ V_198 , V_126 ) ;
V_6 = F_24 ( V_1 , V_4 ) ;
if ( ( V_6 & V_200 ) == 0 ) {
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
static void F_92 ( struct V_1 * V_1 , struct V_201 * V_202 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_57 * V_21 ;
T_1 V_23 ;
T_1 V_184 = 0 ;
T_1 V_203 = F_93 ( V_202 -> V_204 ) ;
switch ( V_202 -> V_205 & V_206 ) {
case V_207 :
V_184 = V_1 -> V_208 ;
break;
case V_209 :
V_184 = 0 ;
break;
case V_210 :
V_21 = V_1 -> V_100 [ V_203 & V_102 ] ;
V_23 = F_15 ( V_1 , V_21 -> V_4 ) ;
if ( V_23 == V_30 )
V_184 = 1 << V_211 ;
else
V_184 = 0 ;
break;
default:
F_23 ( V_1 , 0 ) ;
return;
}
V_1 -> V_212 = F_94 ( V_184 ) ;
V_1 -> V_213 -> V_189 = & V_1 -> V_212 ;
V_1 -> V_213 -> V_123 = 2 ;
F_10 ( & V_1 -> V_14 ) ;
F_95 ( V_1 -> V_15 . V_214 , V_1 -> V_213 , V_215 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
static void F_96 ( struct V_1 * V_1 ,
struct V_201 * V_202 )
{
switch ( V_202 -> V_205 & V_206 ) {
case V_207 :
F_56 ( V_1 , 1 ) ;
break;
case V_209 :
F_56 ( V_1 , 1 ) ;
break;
case V_210 : {
struct V_57 * V_21 ;
struct V_120 * V_121 ;
T_1 V_203 = F_93 ( V_202 -> V_204 ) ;
V_21 = V_1 -> V_100 [ V_203 & V_102 ] ;
if ( ! V_21 -> V_216 ) {
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
static void F_98 ( struct V_1 * V_1 , struct V_201 * V_202 )
{
T_1 V_6 ;
int V_217 = 3000 ;
switch ( V_202 -> V_205 & V_206 ) {
case V_207 :
switch ( F_93 ( V_202 -> V_218 ) ) {
case V_219 :
F_56 ( V_1 , 1 ) ;
do {
V_6 = F_2 ( V_1 , V_152 ) & V_153 ;
F_79 ( 1 ) ;
} while ( V_6 != V_220 || V_217 -- > 0 );
if ( V_6 == V_220 )
F_5 ( V_1 ,
F_93 ( V_202 -> V_204 >> 8 ) ,
V_178 ) ;
break;
default:
F_23 ( V_1 , 0 ) ;
break;
}
break;
case V_209 :
F_56 ( V_1 , 1 ) ;
break;
case V_210 : {
struct V_57 * V_21 ;
T_1 V_203 = F_93 ( V_202 -> V_204 ) ;
V_21 = V_1 -> V_100 [ V_203 & V_102 ] ;
F_23 ( V_1 , V_21 -> V_4 ) ;
F_56 ( V_1 , 1 ) ;
}
break;
default:
F_23 ( V_1 , 0 ) ;
break;
}
}
static int F_99 ( struct V_1 * V_1 , struct V_201 * V_202 )
{
T_1 * V_221 = ( T_1 * ) V_202 ;
unsigned long V_24 = V_222 ;
int V_54 , V_31 = 0 ;
F_6 ( V_1 , ~ V_223 , V_152 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ )
V_221 [ V_54 ] = F_2 ( V_1 , V_24 + V_54 * 2 ) ;
if ( ( V_202 -> V_205 & V_224 ) == V_225 ) {
switch ( V_202 -> V_226 ) {
case V_227 :
F_92 ( V_1 , V_202 ) ;
break;
case V_228 :
F_96 ( V_1 , V_202 ) ;
break;
case V_229 :
F_98 ( V_1 , V_202 ) ;
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
case V_230 :
V_1 -> V_15 . V_16 = V_231 ;
break;
case V_232 :
V_1 -> V_15 . V_16 = V_233 ;
break;
default:
V_1 -> V_15 . V_16 = V_17 ;
F_17 ( F_18 ( V_1 ) , L_17 ) ;
}
}
static void F_101 ( struct V_1 * V_1 )
{
T_1 V_234 ;
V_234 = F_2 ( V_1 , V_152 ) & V_235 ;
F_6 ( V_1 , ~ V_236 , V_152 ) ;
if ( V_234 == V_237 ) {
F_10 ( & V_1 -> V_14 ) ;
V_1 -> V_18 -> V_19 ( & V_1 -> V_15 ) ;
F_11 ( & V_1 -> V_14 ) ;
F_100 ( V_1 ) ;
}
if ( V_1 -> V_238 == V_239 && V_234 != V_239 )
F_100 ( V_1 ) ;
if ( ( V_234 == V_239 || V_234 == V_240 )
&& V_1 -> V_15 . V_16 == V_17 )
F_100 ( V_1 ) ;
V_1 -> V_238 = V_234 ;
}
static void F_102 ( struct V_1 * V_1 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_201 V_202 ;
T_1 V_151 ;
V_151 = F_2 ( V_1 , V_152 ) & V_153 ;
F_6 ( V_1 , ~ V_241 , V_152 ) ;
switch ( V_151 ) {
case V_220 : {
struct V_57 * V_21 ;
struct V_120 * V_121 ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_121 = F_81 ( V_21 ) ;
F_58 ( V_21 , V_121 , 0 ) ;
}
break;
case V_154 :
case V_155 :
case V_156 :
if ( F_99 ( V_1 , & V_202 ) ) {
F_10 ( & V_1 -> V_14 ) ;
if ( V_1 -> V_18 -> V_242 ( & V_1 -> V_15 , & V_202 )
< 0 )
F_23 ( V_1 , 0 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
break;
case V_243 :
case V_244 :
F_56 ( V_1 , 0 ) ;
break;
default:
F_17 ( F_18 ( V_1 ) ,
L_18 , V_151 ) ;
break;
}
}
static void F_103 ( struct V_1 * V_1 , struct V_57 * V_21 )
{
T_1 V_4 ;
struct V_120 * V_121 ;
T_3 V_245 ;
int V_54 = 0 ;
V_4 = V_21 -> V_4 ;
F_34 ( V_1 , V_4 ) ;
while ( ! ( F_2 ( V_1 , V_21 -> V_96 ) & V_148 ) ) {
F_79 ( 1 ) ;
if ( F_71 ( V_54 ++ >= 10000 ) ) {
F_17 ( F_18 ( V_1 ) ,
L_19 ,
V_246 , V_4 ) ;
return;
}
}
F_5 ( V_1 , V_122 , V_21 -> V_96 ) ;
V_121 = F_81 ( V_21 ) ;
V_245 = F_104 ( V_1 , V_247 ) ;
V_121 -> V_121 . V_190 += V_245 ;
F_68 ( V_1 , V_248 , V_249 ) ;
if ( ( ! V_121 -> V_121 . V_191 && ( V_121 -> V_121 . V_190 == V_121 -> V_121 . V_123 ) )
|| ( V_245 % V_21 -> V_21 . V_82 ) ) {
if ( V_21 -> V_92 -> V_136 ) {
F_54 ( V_1 , V_4 ) ;
F_87 ( V_1 , V_4 ) ;
} else {
F_6 ( V_1 , ~ ( 1 << V_4 ) , V_147 ) ;
F_58 ( V_21 , V_121 , 0 ) ;
}
}
}
static void F_105 ( struct V_1 * V_1 )
{
T_3 V_250 ;
struct V_57 * V_21 ;
T_1 V_4 ;
V_250 = F_104 ( V_1 , V_251 ) ;
if ( V_250 & V_252 ) {
F_68 ( V_1 , V_253 , V_254 ) ;
V_4 = ( F_2 ( V_1 , V_129 ) & V_56 ) ;
V_21 = V_1 -> V_58 [ V_4 ] ;
F_103 ( V_1 , V_21 ) ;
}
}
static T_4 F_106 ( int V_255 , void * V_256 )
{
struct V_1 * V_1 = V_256 ;
T_1 V_257 ;
T_1 V_258 ;
T_1 V_259 , V_260 , V_261 ;
T_1 V_262 , V_263 , V_264 ;
T_1 V_265 ;
T_1 V_266 ;
if ( F_35 ( V_1 ) )
F_105 ( V_1 ) ;
F_11 ( & V_1 -> V_14 ) ;
V_257 = F_2 ( V_1 , V_152 ) ;
V_258 = F_2 ( V_1 , V_7 ) ;
V_265 = F_2 ( V_1 , V_95 ) ;
V_266 = V_257 & V_258 ;
if ( V_266 ) {
V_259 = F_2 ( V_1 , V_147 ) ;
V_260 = F_2 ( V_1 , V_182 ) ;
V_261 = F_2 ( V_1 , V_126 ) ;
V_262 = F_2 ( V_1 , V_179 ) ;
V_263 = F_2 ( V_1 , V_181 ) ;
V_264 = F_2 ( V_1 , V_180 ) ;
if ( V_266 & V_267 ) {
F_6 ( V_1 , 0xffff & ~ V_267 ,
V_152 ) ;
F_80 ( V_1 ) ;
V_1 -> V_268 = F_2 ( V_1 , V_152 )
& V_269 ;
V_1 -> V_270 = V_271 ;
F_107 ( & V_1 -> V_272 ,
V_273 + F_108 ( 50 ) ) ;
}
if ( V_257 & V_235 )
F_101 ( V_1 ) ;
if ( ( V_257 & V_274 ) && ( V_258 & V_10 )
&& ( V_259 & V_262 ) )
F_90 ( V_1 , V_259 , V_262 ) ;
if ( ( V_257 & V_275 ) && ( V_258 & V_8 )
&& ( V_261 & V_264 ) )
F_91 ( V_1 , V_261 , V_264 ) ;
if ( V_257 & V_241 )
F_102 ( V_1 ) ;
}
F_6 ( V_1 , V_265 , V_95 ) ;
F_10 ( & V_1 -> V_14 ) ;
return V_276 ;
}
static void F_109 ( unsigned long V_256 )
{
struct V_1 * V_1 = (struct V_1 * ) V_256 ;
unsigned long V_277 ;
T_1 V_6 ;
F_110 ( & V_1 -> V_14 , V_277 ) ;
V_6 = F_2 ( V_1 , V_13 ) ;
if ( V_1 -> V_270 > 0 ) {
V_6 = F_2 ( V_1 , V_152 ) & V_269 ;
if ( V_6 == V_1 -> V_268 ) {
V_1 -> V_270 -- ;
if ( V_1 -> V_270 == 0 ) {
if ( V_6 == V_269 )
F_8 ( V_1 ) ;
else
F_9 ( V_1 ) ;
} else {
F_107 ( & V_1 -> V_272 ,
V_273 + F_108 ( 50 ) ) ;
}
} else {
V_1 -> V_270 = V_271 ;
V_1 -> V_268 = V_6 ;
F_107 ( & V_1 -> V_272 ,
V_273 + F_108 ( 50 ) ) ;
}
}
F_111 ( & V_1 -> V_14 , V_277 ) ;
}
static int F_112 ( struct V_278 * V_279 ,
const struct V_90 * V_91 )
{
struct V_57 * V_21 ;
V_21 = F_113 ( V_279 , struct V_57 , V_21 ) ;
return F_48 ( V_21 , V_91 ) ;
}
static int F_114 ( struct V_278 * V_279 )
{
struct V_57 * V_21 ;
struct V_120 * V_121 ;
unsigned long V_277 ;
V_21 = F_113 ( V_279 , struct V_57 , V_21 ) ;
F_67 ( ! V_21 ) ;
while ( ! F_84 ( & V_21 -> V_22 ) ) {
V_121 = F_81 ( V_21 ) ;
F_110 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
F_58 ( V_21 , V_121 , - V_280 ) ;
F_111 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
}
F_53 ( V_21 -> V_1 , V_21 -> V_4 ) ;
return F_49 ( V_21 ) ;
}
static struct V_281 * F_115 ( struct V_278 * V_279 ,
T_5 V_282 )
{
struct V_120 * V_121 ;
V_121 = F_116 ( sizeof( struct V_120 ) , V_282 ) ;
if ( ! V_121 )
return NULL ;
F_14 ( & V_121 -> V_22 ) ;
return & V_121 -> V_121 ;
}
static void F_117 ( struct V_278 * V_279 , struct V_281 * V_283 )
{
struct V_120 * V_121 ;
V_121 = F_113 ( V_283 , struct V_120 , V_121 ) ;
F_118 ( V_121 ) ;
}
static int F_95 ( struct V_278 * V_279 , struct V_281 * V_283 ,
T_5 V_282 )
{
struct V_57 * V_21 ;
struct V_120 * V_121 ;
unsigned long V_277 ;
int V_284 = 0 ;
V_21 = F_113 ( V_279 , struct V_57 , V_21 ) ;
V_121 = F_113 ( V_283 , struct V_120 , V_121 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
return - V_186 ;
F_110 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
if ( F_84 ( & V_21 -> V_22 ) )
V_284 = 1 ;
F_119 ( & V_121 -> V_22 , & V_21 -> V_22 ) ;
V_121 -> V_121 . V_190 = 0 ;
V_121 -> V_121 . V_184 = - V_285 ;
if ( V_21 -> V_21 . V_91 == NULL )
F_76 ( V_21 , V_121 ) ;
else {
if ( V_284 && ! V_21 -> V_104 )
F_75 ( V_21 , V_121 ) ;
}
F_111 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
return 0 ;
}
static int F_120 ( struct V_278 * V_279 , struct V_281 * V_283 )
{
struct V_57 * V_21 ;
struct V_120 * V_121 ;
unsigned long V_277 ;
V_21 = F_113 ( V_279 , struct V_57 , V_21 ) ;
V_121 = F_113 ( V_283 , struct V_120 , V_121 ) ;
F_110 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
if ( ! F_84 ( & V_21 -> V_22 ) )
F_58 ( V_21 , V_121 , - V_280 ) ;
F_111 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
return 0 ;
}
static int F_121 ( struct V_278 * V_279 , int V_286 )
{
struct V_57 * V_21 ;
struct V_120 * V_121 ;
unsigned long V_277 ;
int V_31 = 0 ;
V_21 = F_113 ( V_279 , struct V_57 , V_21 ) ;
V_121 = F_81 ( V_21 ) ;
F_110 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
if ( ! F_84 ( & V_21 -> V_22 ) ) {
V_31 = - V_287 ;
goto V_288;
}
if ( V_286 ) {
V_21 -> V_104 = 1 ;
F_23 ( V_21 -> V_1 , V_21 -> V_4 ) ;
} else {
V_21 -> V_104 = 0 ;
V_21 -> V_216 = 0 ;
F_22 ( V_21 -> V_1 , V_21 -> V_4 ) ;
}
V_288:
F_111 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
return V_31 ;
}
static int F_122 ( struct V_278 * V_279 )
{
struct V_57 * V_21 ;
unsigned long V_277 ;
V_21 = F_113 ( V_279 , struct V_57 , V_21 ) ;
if ( ! V_21 || ! V_21 -> V_21 . V_91 )
return - V_67 ;
F_110 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
V_21 -> V_216 = 1 ;
F_111 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
return F_123 ( V_279 ) ;
}
static void F_124 ( struct V_278 * V_279 )
{
struct V_57 * V_21 ;
unsigned long V_277 ;
V_21 = F_113 ( V_279 , struct V_57 , V_21 ) ;
F_110 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
if ( F_84 ( & V_21 -> V_22 ) && ! V_21 -> V_104 ) {
F_22 ( V_21 -> V_1 , V_21 -> V_4 ) ;
F_4 ( V_21 -> V_1 , V_122 , V_21 -> V_96 ) ;
F_6 ( V_21 -> V_1 , V_88 , V_21 -> V_89 ) ;
F_6 ( V_21 -> V_1 , 0 , V_21 -> V_89 ) ;
}
F_111 ( & V_21 -> V_1 -> V_14 , V_277 ) ;
}
static int F_125 ( struct V_289 * V_15 ,
struct V_290 * V_18 )
{
struct V_1 * V_1 = F_126 ( V_15 ) ;
if ( ! V_18
|| V_18 -> V_291 < V_231
|| ! V_18 -> V_242 )
return - V_67 ;
if ( ! V_1 )
return - V_111 ;
V_1 -> V_18 = V_18 ;
F_13 ( V_1 ) ;
F_5 ( V_1 , V_20 , V_7 ) ;
if ( F_2 ( V_1 , V_152 ) & V_269 ) {
F_80 ( V_1 ) ;
V_1 -> V_268 = F_2 ( V_1 ,
V_152 ) & V_269 ;
V_1 -> V_270 = V_271 ;
F_107 ( & V_1 -> V_272 , V_273 + F_108 ( 50 ) ) ;
}
return 0 ;
}
static int F_127 ( struct V_289 * V_15 ,
struct V_290 * V_18 )
{
struct V_1 * V_1 = F_126 ( V_15 ) ;
unsigned long V_277 ;
F_110 ( & V_1 -> V_14 , V_277 ) ;
F_4 ( V_1 , V_20 , V_7 ) ;
F_12 ( V_1 ) ;
F_111 ( & V_1 -> V_14 , V_277 ) ;
V_1 -> V_18 = NULL ;
return 0 ;
}
static int F_128 ( struct V_289 * V_292 )
{
struct V_1 * V_1 = F_126 ( V_292 ) ;
return F_2 ( V_1 , V_293 ) & 0x03FF ;
}
static int F_129 ( struct V_289 * V_15 , int V_294 )
{
struct V_1 * V_1 = F_126 ( V_15 ) ;
unsigned long V_277 ;
F_110 ( & V_1 -> V_14 , V_277 ) ;
if ( V_294 )
F_5 ( V_1 , V_12 , V_13 ) ;
else
F_4 ( V_1 , V_12 , V_13 ) ;
F_111 ( & V_1 -> V_14 , V_277 ) ;
return 0 ;
}
static int F_130 ( struct V_289 * V_15 , int V_295 )
{
struct V_1 * V_1 = F_126 ( V_15 ) ;
if ( V_295 )
V_1 -> V_208 |= 1 << V_296 ;
else
V_1 -> V_208 &= ~ ( 1 << V_296 ) ;
return 0 ;
}
static int T_6 F_131 ( struct V_297 * V_298 )
{
struct V_1 * V_1 = F_132 ( & V_298 -> V_299 ) ;
F_133 ( & V_1 -> V_15 ) ;
F_134 ( & V_1 -> V_272 ) ;
F_135 ( V_1 -> V_5 ) ;
if ( V_1 -> V_46 -> V_300 )
F_135 ( V_1 -> V_301 ) ;
F_136 ( F_137 ( V_298 , 0 ) , V_1 ) ;
F_117 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_213 ) ;
#ifdef F_138
if ( V_1 -> V_46 -> V_47 ) {
F_139 ( V_1 -> V_302 ) ;
F_140 ( V_1 -> V_302 ) ;
}
#endif
F_141 ( & V_1 -> V_15 . V_299 ) ;
F_118 ( V_1 ) ;
return 0 ;
}
static void F_142 ( struct V_278 * V_21 , struct V_281 * V_303 )
{
}
static int T_7 F_143 ( struct V_1 * V_1 ,
struct V_297 * V_298 )
{
struct V_304 * V_305 ;
V_305 = F_144 ( V_298 , V_306 , L_20 ) ;
if ( ! V_305 ) {
F_17 ( & V_298 -> V_299 , L_21 ) ;
return - V_111 ;
}
V_1 -> V_301 = F_145 ( V_305 -> V_307 , F_146 ( V_305 ) ) ;
if ( V_1 -> V_301 == NULL ) {
F_17 ( & V_298 -> V_299 , L_22 ) ;
return - V_81 ;
}
return 0 ;
}
static int T_7 F_147 ( struct V_297 * V_298 )
{
#ifdef F_138
char V_308 [ 8 ] ;
#endif
struct V_304 * V_305 , * V_309 ;
int V_255 ;
void T_8 * V_5 = NULL ;
struct V_1 * V_1 = NULL ;
int V_31 = 0 ;
int V_54 ;
unsigned long V_310 ;
V_305 = F_148 ( V_298 , V_306 , 0 ) ;
if ( ! V_305 ) {
V_31 = - V_111 ;
F_17 ( & V_298 -> V_299 , L_23 ) ;
goto V_311;
}
V_309 = F_148 ( V_298 , V_312 , 0 ) ;
V_255 = V_309 -> V_307 ;
V_310 = V_309 -> V_277 & V_313 ;
if ( V_255 < 0 ) {
V_31 = - V_111 ;
F_17 ( & V_298 -> V_299 , L_24 ) ;
goto V_311;
}
V_5 = F_145 ( V_305 -> V_307 , F_146 ( V_305 ) ) ;
if ( V_5 == NULL ) {
V_31 = - V_81 ;
F_17 ( & V_298 -> V_299 , L_25 ) ;
goto V_311;
}
V_1 = F_116 ( sizeof( struct V_1 ) , V_215 ) ;
if ( V_1 == NULL ) {
V_31 = - V_81 ;
F_17 ( & V_298 -> V_299 , L_26 ) ;
goto V_311;
}
F_149 ( & V_1 -> V_14 ) ;
F_150 ( & V_298 -> V_299 , V_1 ) ;
V_1 -> V_46 = V_298 -> V_299 . V_314 ;
V_1 -> V_160 = V_310 == V_315 ;
V_1 -> V_15 . V_316 = & V_317 ;
F_151 ( & V_1 -> V_15 . V_299 , L_27 ) ;
V_1 -> V_15 . V_291 = V_231 ;
V_1 -> V_15 . V_299 . V_318 = & V_298 -> V_299 ;
V_1 -> V_15 . V_299 . V_319 = V_298 -> V_299 . V_319 ;
V_1 -> V_15 . V_299 . V_320 = V_298 -> V_299 . V_320 ;
V_1 -> V_15 . V_321 = V_322 ;
V_31 = F_152 ( & V_1 -> V_15 . V_299 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_298 -> V_299 , L_28 ) ;
goto V_311;
}
F_153 ( & V_1 -> V_272 ) ;
V_1 -> V_272 . V_323 = F_109 ;
V_1 -> V_272 . V_324 = ( unsigned long ) V_1 ;
V_1 -> V_5 = V_5 ;
#ifdef F_138
if ( V_1 -> V_46 -> V_47 ) {
snprintf ( V_308 , sizeof( V_308 ) , L_29 , V_298 -> V_325 ) ;
V_1 -> V_302 = F_154 ( & V_298 -> V_299 , V_308 ) ;
if ( F_155 ( V_1 -> V_302 ) ) {
F_17 ( & V_298 -> V_299 , L_30 ,
V_308 ) ;
V_31 = F_156 ( V_1 -> V_302 ) ;
goto V_326;
}
F_157 ( V_1 -> V_302 ) ;
}
#endif
if ( V_1 -> V_46 -> V_300 ) {
V_31 = F_143 ( V_1 , V_298 ) ;
if ( V_31 < 0 )
goto V_327;
}
F_12 ( V_1 ) ;
V_31 = F_158 ( V_255 , F_106 , V_328 ,
V_322 , V_1 ) ;
if ( V_31 < 0 ) {
F_17 ( & V_298 -> V_299 , L_31 , V_31 ) ;
goto V_327;
}
F_14 ( & V_1 -> V_15 . V_329 ) ;
V_1 -> V_15 . V_214 = & V_1 -> V_21 [ 0 ] . V_21 ;
F_14 ( & V_1 -> V_15 . V_214 -> V_329 ) ;
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
V_21 -> V_21 . V_316 = & V_331 ;
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
V_1 -> V_213 = F_115 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_215 ) ;
if ( V_1 -> V_213 == NULL )
goto V_332;
V_1 -> V_213 -> V_187 = F_142 ;
V_31 = F_159 ( & V_298 -> V_299 , & V_1 -> V_15 ) ;
if ( V_31 )
goto V_333;
F_160 ( & V_298 -> V_299 , L_32 , V_334 ) ;
return 0 ;
V_333:
F_117 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_213 ) ;
V_332:
F_136 ( V_255 , V_1 ) ;
V_327:
#ifdef F_138
if ( V_1 -> V_46 -> V_47 ) {
F_139 ( V_1 -> V_302 ) ;
F_140 ( V_1 -> V_302 ) ;
}
V_326:
#endif
F_141 ( & V_1 -> V_15 . V_299 ) ;
V_311:
if ( V_1 ) {
if ( V_1 -> V_301 )
F_135 ( V_1 -> V_301 ) ;
if ( V_1 -> V_213 )
F_117 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_1 -> V_213 ) ;
F_118 ( V_1 ) ;
}
if ( V_5 )
F_135 ( V_5 ) ;
return V_31 ;
}
static int T_7 F_161 ( void )
{
return F_162 ( & V_335 , F_147 ) ;
}
static void T_6 F_163 ( void )
{
F_164 ( & V_335 ) ;
}
