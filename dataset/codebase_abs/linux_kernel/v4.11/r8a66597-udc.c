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
static void F_34 ( struct V_1 * V_1 , T_1 V_4 )
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
V_1 -> V_100 [ F_47 ( V_91 ) ]
= V_21 ;
F_14 ( & V_21 -> V_22 ) ;
}
static void F_48 ( struct V_57 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_4 = V_21 -> V_4 ;
if ( V_4 == 0 )
return;
if ( V_21 -> V_59 )
V_1 -> V_101 -- ;
V_21 -> V_4 = 0 ;
V_21 -> V_102 = 0 ;
V_21 -> V_59 = 0 ;
}
static int F_49 ( struct V_57 * V_21 ,
const struct V_90 * V_91 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_61 V_62 ;
int V_92 = 0 ;
unsigned char * V_103 ;
int V_31 ;
V_21 -> V_21 . V_91 = V_91 ;
if ( V_21 -> V_4 )
return 0 ;
switch ( F_50 ( V_91 ) ) {
case V_104 :
if ( V_1 -> V_85 >= V_105 ) {
if ( V_1 -> V_87 >= V_106 ) {
F_17 ( F_18 ( V_1 ) ,
L_7 ) ;
return - V_107 ;
} else {
V_62 . V_66 = V_75
+ V_1 -> V_87 ;
V_103 = & V_1 -> V_87 ;
}
} else {
V_62 . V_66 = V_74 + V_1 -> V_85 ;
V_103 = & V_1 -> V_85 ;
}
V_62 . type = V_73 ;
V_92 = 1 ;
break;
case V_108 :
if ( V_1 -> V_86 >= V_109 ) {
F_17 ( F_18 ( V_1 ) ,
L_8 ) ;
return - V_107 ;
}
V_62 . V_66 = V_72 + V_1 -> V_86 ;
V_62 . type = V_71 ;
V_103 = & V_1 -> V_86 ;
break;
case V_110 :
if ( V_1 -> V_87 >= V_106 ) {
F_17 ( F_18 ( V_1 ) ,
L_9 ) ;
return - V_107 ;
}
V_62 . V_66 = V_75 + V_1 -> V_87 ;
V_62 . type = V_79 ;
V_103 = & V_1 -> V_87 ;
break;
default:
F_17 ( F_18 ( V_1 ) , L_10 ) ;
return - V_67 ;
}
V_21 -> type = V_62 . type ;
V_62 . V_70 = F_47 ( V_91 ) ;
V_62 . V_82 = F_46 ( V_91 ) ;
V_62 . V_83 = V_91 -> V_111 ;
if ( V_91 -> V_112 & V_113 )
V_62 . V_68 = 1 ;
else
V_62 . V_68 = 0 ;
V_31 = F_36 ( V_1 , & V_62 ) ;
if ( V_31 < 0 ) {
F_17 ( F_18 ( V_1 ) ,
L_11 ) ;
return V_31 ;
}
( * V_103 ) ++ ;
if ( ( V_103 == & V_1 -> V_87 ) && V_62 . type == V_73 )
V_1 -> V_85 ++ ;
F_43 ( V_1 , V_21 , V_91 , V_62 . V_66 , V_92 ) ;
F_42 ( V_21 ) ;
return 0 ;
}
static int F_51 ( struct V_57 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_61 V_62 ;
V_62 . V_66 = V_21 -> V_4 ;
V_62 . type = V_21 -> type ;
F_38 ( V_1 , & V_62 ) ;
F_48 ( V_21 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_1 , T_1 V_4 )
{
F_53 ( V_1 , V_4 ) ;
F_54 ( V_1 , V_4 ) ;
}
static void F_55 ( struct V_1 * V_1 , T_1 V_4 )
{
F_56 ( V_1 , V_4 ) ;
F_57 ( V_1 , V_4 ) ;
}
static void F_58 ( struct V_1 * V_1 , unsigned V_114 )
{
V_1 -> V_21 [ 0 ] . V_115 = V_114 ;
F_21 ( V_1 , 0 ) ;
F_5 ( V_1 , V_116 , V_25 ) ;
}
static void F_59 ( struct V_57 * V_21 ,
struct V_117 * V_118 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
F_34 ( V_1 , V_21 -> V_4 ) ;
F_20 ( V_1 , V_55 , ( V_55 | V_56 ) , V_95 ) ;
F_6 ( V_1 , V_119 , V_21 -> V_96 ) ;
if ( V_118 -> V_118 . V_120 == 0 ) {
F_5 ( V_1 , V_121 , V_21 -> V_96 ) ;
F_21 ( V_1 , 0 ) ;
F_60 ( V_21 , V_118 , 0 ) ;
} else {
F_6 ( V_1 , ~ V_122 , V_123 ) ;
F_61 ( V_21 , V_118 ) ;
}
}
static void F_62 ( struct V_1 * V_1 , T_1 V_4 ,
T_1 V_51 )
{
T_1 V_6 ;
V_6 = F_2 ( V_1 , V_51 ) & V_56 ;
if ( V_6 == V_4 )
F_32 ( V_1 , 0 , 0 , V_51 ) ;
}
static void F_63 ( struct V_1 * V_1 , T_1 V_4 ,
int V_124 )
{
struct V_57 * V_21 = V_1 -> V_58 [ V_4 ] ;
T_1 V_6 , V_35 ;
F_6 ( V_1 , V_4 , V_41 ) ;
V_6 = F_2 ( V_1 , V_42 ) & V_125 ;
if ( ( V_124 && V_6 ) || ( ! V_124 && ! V_6 ) )
return;
F_22 ( V_1 , V_4 ) ;
F_62 ( V_1 , V_4 , V_95 ) ;
F_62 ( V_1 , V_4 , V_126 ) ;
F_62 ( V_1 , V_4 , V_127 ) ;
V_35 = F_28 ( V_1 , V_4 ) ;
F_6 ( V_1 , V_4 , V_41 ) ;
if ( V_124 )
F_5 ( V_1 , V_125 , V_42 ) ;
else
F_4 ( V_1 , V_125 , V_42 ) ;
F_5 ( V_1 , V_88 , V_21 -> V_89 ) ;
F_4 ( V_1 , V_88 , V_21 -> V_89 ) ;
F_29 ( V_1 , V_4 , V_35 ) ;
}
static int F_64 ( struct V_1 * V_1 ,
struct V_57 * V_21 ,
struct V_117 * V_118 )
{
struct V_128 * V_92 ;
if ( ! F_35 ( V_1 ) )
return - V_107 ;
if ( ! F_39 ( V_21 -> V_4 ) )
return - V_129 ;
if ( V_1 -> V_92 . V_130 )
return - V_131 ;
V_92 = & V_1 -> V_92 ;
V_92 -> V_130 = 1 ;
if ( V_21 -> V_21 . V_91 -> V_112 & V_132 ) {
V_92 -> V_133 = 1 ;
} else {
V_92 -> V_133 = 0 ;
F_63 ( V_1 , V_21 -> V_4 , 1 ) ;
}
V_21 -> V_59 = 1 ;
V_21 -> V_92 = V_92 ;
V_21 -> V_93 = V_134 ;
V_21 -> V_51 = V_126 ;
V_21 -> V_96 = V_135 ;
return F_65 ( & V_1 -> V_15 , & V_118 -> V_118 , V_92 -> V_133 ) ;
}
static void F_66 ( struct V_1 * V_1 ,
struct V_57 * V_21 ,
struct V_117 * V_118 )
{
if ( ! F_35 ( V_1 ) )
return;
F_67 ( & V_1 -> V_15 , & V_118 -> V_118 , V_21 -> V_92 -> V_133 ) ;
F_4 ( V_1 , V_60 , V_21 -> V_51 ) ;
F_32 ( V_1 , 0 , 0 , V_21 -> V_51 ) ;
V_21 -> V_92 -> V_130 = 0 ;
V_21 -> V_59 = 0 ;
V_21 -> V_93 = V_94 ;
V_21 -> V_51 = V_95 ;
V_21 -> V_96 = V_97 ;
}
static void F_68 ( struct V_1 * V_1 , struct V_57 * V_21 ,
struct V_117 * V_118 )
{
F_69 ( V_118 -> V_118 . V_120 == 0 ) ;
F_70 ( V_1 , V_136 , V_137 ) ;
F_70 ( V_1 , V_118 -> V_118 . V_92 , V_138 ) ;
F_70 ( V_1 , V_118 -> V_118 . V_120 , V_139 ) ;
F_70 ( V_1 , V_140 , V_141 ) ;
F_70 ( V_1 , V_142 , V_143 ) ;
}
static void F_71 ( struct V_57 * V_21 ,
struct V_117 * V_118 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_6 ;
F_34 ( V_1 , V_21 -> V_4 ) ;
F_72 ( V_1 , V_21 -> V_4 ) ;
F_21 ( V_1 , V_21 -> V_4 ) ;
if ( V_118 -> V_118 . V_120 == 0 ) {
F_60 ( V_21 , V_118 , 0 ) ;
} else {
F_6 ( V_1 , ~ ( 1 << V_21 -> V_4 ) , V_144 ) ;
if ( F_64 ( V_1 , V_21 , V_118 ) < 0 ) {
F_34 ( V_1 , V_21 -> V_4 ) ;
F_72 ( V_1 , V_21 -> V_4 ) ;
F_21 ( V_1 , V_21 -> V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_73 ( ( V_6 & V_145 ) == 0 ) )
F_52 ( V_1 , V_21 -> V_4 ) ;
else
F_74 ( V_21 , V_118 ) ;
} else {
F_34 ( V_1 , V_21 -> V_4 ) ;
F_57 ( V_1 , V_21 -> V_4 ) ;
F_21 ( V_1 , V_21 -> V_4 ) ;
F_54 ( V_1 , V_21 -> V_4 ) ;
F_68 ( V_1 , V_21 , V_118 ) ;
}
}
}
static void F_75 ( struct V_57 * V_21 ,
struct V_117 * V_118 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_4 = V_21 -> V_4 ;
if ( V_21 -> V_4 == 0 ) {
F_20 ( V_1 , 0 , ( V_55 | V_56 ) , V_95 ) ;
F_6 ( V_1 , V_119 , V_21 -> V_96 ) ;
F_21 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 ) ;
} else {
F_22 ( V_1 , V_4 ) ;
if ( V_21 -> V_98 ) {
F_54 ( V_1 , V_4 ) ;
F_6 ( V_1 , V_146 , V_21 -> V_98 ) ;
F_6 ( V_1 ,
F_76 ( V_118 -> V_118 . V_120 , V_21 -> V_21 . V_82 ) ,
V_21 -> V_99 ) ;
F_5 ( V_1 , V_147 , V_21 -> V_98 ) ;
}
if ( F_64 ( V_1 , V_21 , V_118 ) < 0 ) {
F_63 ( V_1 , V_21 -> V_4 , 0 ) ;
F_21 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 ) ;
} else {
F_34 ( V_1 , V_4 ) ;
F_68 ( V_1 , V_21 , V_118 ) ;
F_21 ( V_1 , V_4 ) ;
}
}
}
static void F_77 ( struct V_57 * V_21 , struct V_117 * V_118 )
{
if ( V_21 -> V_21 . V_91 -> V_112 & V_132 )
F_71 ( V_21 , V_118 ) ;
else
F_75 ( V_21 , V_118 ) ;
}
static void F_78 ( struct V_57 * V_21 , struct V_117 * V_118 )
{
T_1 V_148 ;
V_148 = F_2 ( V_21 -> V_1 , V_149 ) & V_150 ;
switch ( V_148 ) {
case V_151 :
F_59 ( V_21 , V_118 ) ;
break;
case V_152 :
F_75 ( V_21 , V_118 ) ;
break;
case V_153 :
F_58 ( V_21 -> V_1 , 0 ) ;
break;
default:
F_17 ( F_18 ( V_21 -> V_1 ) ,
L_12 , V_148 ) ;
break;
}
}
static void F_13 ( struct V_1 * V_1 )
{
T_1 V_154 = V_1 -> V_46 -> V_154 ? V_155 : 0 ;
T_1 V_156 = V_1 -> V_157 ? V_158 : 0 ;
T_1 V_159 = V_1 -> V_46 -> V_159 ? V_160 : 0 ;
if ( V_1 -> V_46 -> V_47 ) {
if ( V_1 -> V_46 -> V_161 )
F_6 ( V_1 , V_1 -> V_46 -> V_161 ,
V_162 ) ;
else
F_6 ( V_1 , 0x0f , V_162 ) ;
F_5 ( V_1 , V_163 , V_13 ) ;
F_4 ( V_1 , V_164 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_164 , V_13 ) ;
F_5 ( V_1 , V_165 , V_13 ) ;
F_5 ( V_1 , V_156 , V_166 ) ;
F_6 ( V_1 , V_167 | V_168 ,
V_169 ) ;
} else {
F_5 ( V_1 , V_154 | V_159 , V_170 ) ;
F_5 ( V_1 , V_163 , V_13 ) ;
F_20 ( V_1 , F_79 ( V_1 -> V_46 ) ,
V_171 , V_13 ) ;
F_4 ( V_1 , V_164 , V_13 ) ;
F_4 ( V_1 , V_12 , V_13 ) ;
F_5 ( V_1 , V_164 , V_13 ) ;
F_5 ( V_1 , V_172 , V_13 ) ;
F_80 ( 3 ) ;
F_5 ( V_1 , V_173 , V_13 ) ;
F_80 ( 1 ) ;
F_5 ( V_1 , V_165 , V_13 ) ;
F_5 ( V_1 , V_156 , V_166 ) ;
F_6 ( V_1 , V_167 | V_168 ,
V_169 ) ;
}
}
static void F_12 ( struct V_1 * V_1 )
{
if ( V_1 -> V_46 -> V_47 ) {
F_5 ( V_1 , V_165 , V_13 ) ;
F_4 ( V_1 , V_174 , V_175 ) ;
F_6 ( V_1 , 0 , V_7 ) ;
F_6 ( V_1 , 0 , V_166 ) ;
F_6 ( V_1 , 0 , V_176 ) ;
F_6 ( V_1 , 0 , V_177 ) ;
F_6 ( V_1 , 0 , V_178 ) ;
F_6 ( V_1 , 0 , V_144 ) ;
F_6 ( V_1 , 0 , V_179 ) ;
F_6 ( V_1 , 0 , V_123 ) ;
F_4 ( V_1 , V_164 , V_13 ) ;
F_4 ( V_1 , V_165 , V_13 ) ;
} else {
F_4 ( V_1 , V_174 , V_175 ) ;
F_4 ( V_1 , V_165 , V_13 ) ;
F_81 ( 1 ) ;
F_4 ( V_1 , V_173 , V_13 ) ;
F_81 ( 1 ) ;
F_81 ( 1 ) ;
F_4 ( V_1 , V_172 , V_13 ) ;
}
}
static void F_82 ( struct V_1 * V_1 )
{
T_1 V_6 ;
if ( ! V_1 -> V_46 -> V_47 ) {
V_6 = F_2 ( V_1 , V_13 ) ;
if ( ! ( V_6 & V_172 ) )
F_5 ( V_1 , V_172 , V_13 ) ;
}
}
static struct V_117 * F_83 ( struct V_57 * V_21 )
{
return F_84 ( V_21 -> V_22 . V_180 , struct V_117 , V_22 ) ;
}
static void F_60 ( struct V_57 * V_21 ,
struct V_117 * V_118 , int V_181 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
int V_182 = 0 ;
if ( F_73 ( V_21 -> V_4 == 0 ) ) {
if ( V_21 -> V_115 ) {
V_21 -> V_115 = 0 ;
return;
}
}
F_85 ( & V_118 -> V_22 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
V_118 -> V_118 . V_181 = - V_183 ;
else
V_118 -> V_118 . V_181 = V_181 ;
if ( ! F_86 ( & V_21 -> V_22 ) )
V_182 = 1 ;
if ( V_21 -> V_59 )
F_66 ( V_21 -> V_1 , V_21 , V_118 ) ;
F_10 ( & V_21 -> V_1 -> V_14 ) ;
F_87 ( & V_21 -> V_21 , & V_118 -> V_118 ) ;
F_11 ( & V_21 -> V_1 -> V_14 ) ;
if ( V_182 ) {
V_118 = F_83 ( V_21 ) ;
if ( V_21 -> V_21 . V_91 )
F_77 ( V_21 , V_118 ) ;
}
}
static void F_61 ( struct V_57 * V_21 , struct V_117 * V_118 )
{
int V_54 ;
T_1 V_6 ;
unsigned V_184 ;
T_2 V_36 ;
void * V_185 ;
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
} while ( ( V_6 & V_145 ) == 0 );
V_184 = F_30 ( V_1 , V_4 ) ;
V_185 = V_118 -> V_118 . V_185 + V_118 -> V_118 . V_186 ;
V_36 = F_88 ( V_184 , V_118 -> V_118 . V_120 - V_118 -> V_118 . V_186 ) ;
if ( V_118 -> V_118 . V_185 ) {
if ( V_36 > 0 )
F_89 ( V_1 , V_21 , V_185 , V_36 ) ;
if ( ( V_36 == 0 ) || ( ( V_36 % V_21 -> V_21 . V_82 ) != 0 ) )
F_5 ( V_1 , V_121 , V_21 -> V_96 ) ;
}
V_118 -> V_118 . V_186 += V_36 ;
if ( ( ! V_118 -> V_118 . V_187 && ( V_118 -> V_118 . V_186 == V_118 -> V_118 . V_120 ) )
|| ( V_36 % V_21 -> V_21 . V_82 )
|| ( V_36 == 0 ) ) {
F_56 ( V_1 , V_4 ) ;
F_72 ( V_1 , V_4 ) ;
} else {
F_56 ( V_1 , V_4 ) ;
F_90 ( V_1 , V_4 ) ;
}
F_21 ( V_1 , V_4 ) ;
}
static void F_74 ( struct V_57 * V_21 ,
struct V_117 * V_118 )
{
T_1 V_6 ;
unsigned V_184 ;
T_2 V_36 ;
void * V_185 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
F_34 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_73 ( ( V_6 & V_145 ) == 0 ) ) {
F_22 ( V_1 , V_4 ) ;
F_55 ( V_1 , V_4 ) ;
F_17 ( F_18 ( V_1 ) ,
L_15 , V_4 ) ;
return;
}
V_184 = F_30 ( V_1 , V_4 ) ;
V_185 = V_118 -> V_118 . V_185 + V_118 -> V_118 . V_186 ;
V_36 = F_88 ( V_184 , V_118 -> V_118 . V_120 - V_118 -> V_118 . V_186 ) ;
if ( V_118 -> V_118 . V_185 ) {
F_89 ( V_1 , V_21 , V_185 , V_36 ) ;
if ( ( V_36 == 0 )
|| ( ( V_36 % V_21 -> V_21 . V_82 ) != 0 )
|| ( ( V_184 != V_21 -> V_21 . V_82 )
&& ( V_184 > V_36 ) ) )
F_5 ( V_1 , V_121 , V_21 -> V_96 ) ;
}
V_118 -> V_118 . V_186 += V_36 ;
if ( ( ! V_118 -> V_118 . V_187 && ( V_118 -> V_118 . V_186 == V_118 -> V_118 . V_120 ) )
|| ( V_36 % V_21 -> V_21 . V_82 )
|| ( V_36 == 0 ) ) {
F_56 ( V_1 , V_4 ) ;
F_90 ( V_1 , V_4 ) ;
} else {
F_72 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 ) ;
}
}
static void F_91 ( struct V_57 * V_21 ,
struct V_117 * V_118 )
{
T_1 V_6 ;
int V_188 , V_184 , V_189 ;
int V_36 ;
void * V_185 ;
T_1 V_4 = V_21 -> V_4 ;
struct V_1 * V_1 = V_21 -> V_1 ;
int V_190 = 0 ;
F_34 ( V_1 , V_4 ) ;
V_6 = F_2 ( V_1 , V_21 -> V_96 ) ;
if ( F_73 ( ( V_6 & V_145 ) == 0 ) ) {
V_118 -> V_118 . V_181 = - V_191 ;
F_22 ( V_1 , V_4 ) ;
F_55 ( V_1 , V_4 ) ;
F_17 ( F_18 ( V_1 ) , L_16 ) ;
return;
}
V_188 = V_6 & V_192 ;
V_184 = F_30 ( V_1 , V_4 ) ;
V_185 = V_118 -> V_118 . V_185 + V_118 -> V_118 . V_186 ;
V_189 = V_118 -> V_118 . V_120 - V_118 -> V_118 . V_186 ;
if ( V_188 < V_184 )
V_36 = F_88 ( V_188 , V_189 ) ;
else
V_36 = F_88 ( V_184 , V_189 ) ;
V_118 -> V_118 . V_186 += V_36 ;
if ( ( ! V_118 -> V_118 . V_187 && ( V_118 -> V_118 . V_186 == V_118 -> V_118 . V_120 ) )
|| ( V_36 % V_21 -> V_21 . V_82 )
|| ( V_36 == 0 ) ) {
F_22 ( V_1 , V_4 ) ;
F_55 ( V_1 , V_4 ) ;
V_190 = 1 ;
}
if ( V_118 -> V_118 . V_185 ) {
if ( V_36 == 0 )
F_6 ( V_1 , V_119 , V_21 -> V_96 ) ;
else
F_92 ( V_1 , V_21 -> V_93 , V_185 , V_36 ) ;
}
if ( ( V_21 -> V_4 != 0 ) && V_190 )
F_60 ( V_21 , V_118 , 0 ) ;
}
static void F_93 ( struct V_1 * V_1 , T_1 V_181 , T_1 V_193 )
{
T_1 V_194 ;
T_1 V_4 ;
struct V_57 * V_21 ;
struct V_117 * V_118 ;
if ( ( V_181 & V_195 ) && ( V_193 & V_195 ) ) {
F_6 ( V_1 , ~ V_195 , V_144 ) ;
F_20 ( V_1 , 0 , V_56 , V_95 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_118 = F_83 ( V_21 ) ;
F_91 ( V_21 , V_118 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_194 = 1 << V_4 ;
if ( ( V_181 & V_194 ) && ( V_193 & V_194 ) ) {
F_6 ( V_1 , ~ V_194 , V_144 ) ;
V_21 = V_1 -> V_58 [ V_4 ] ;
V_118 = F_83 ( V_21 ) ;
if ( V_21 -> V_21 . V_91 -> V_112 & V_132 )
F_74 ( V_21 , V_118 ) ;
else
F_91 ( V_21 , V_118 ) ;
}
}
}
}
static void F_94 ( struct V_1 * V_1 , T_1 V_181 , T_1 V_193 )
{
T_1 V_6 ;
T_1 V_194 ;
T_1 V_4 ;
struct V_57 * V_21 ;
struct V_117 * V_118 ;
if ( ( V_181 & V_122 ) && ( V_193 & V_122 ) ) {
F_6 ( V_1 , ~ V_122 , V_123 ) ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_118 = F_83 ( V_21 ) ;
F_61 ( V_21 , V_118 ) ;
} else {
for ( V_4 = 1 ; V_4 < V_27 ; V_4 ++ ) {
V_194 = 1 << V_4 ;
if ( ( V_181 & V_194 ) && ( V_193 & V_194 ) ) {
F_6 ( V_1 , ~ V_194 , V_123 ) ;
V_6 = F_24 ( V_1 , V_4 ) ;
if ( ( V_6 & V_196 ) == 0 ) {
F_72 ( V_1 , V_4 ) ;
F_55 ( V_1 , V_4 ) ;
F_22 ( V_1 , V_4 ) ;
V_21 = V_1 -> V_58 [ V_4 ] ;
V_118 = F_83 ( V_21 ) ;
if ( ! F_86 ( & V_21 -> V_22 ) )
F_60 ( V_21 , V_118 , 0 ) ;
}
}
}
}
}
static void F_95 ( struct V_1 * V_1 , struct V_197 * V_198 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_57 * V_21 ;
T_1 V_23 ;
T_1 V_181 = 0 ;
T_1 V_199 = F_96 ( V_198 -> V_200 ) ;
switch ( V_198 -> V_201 & V_202 ) {
case V_203 :
V_181 = V_1 -> V_204 ;
break;
case V_205 :
V_181 = 0 ;
break;
case V_206 :
V_21 = V_1 -> V_100 [ V_199 & V_207 ] ;
V_23 = F_15 ( V_1 , V_21 -> V_4 ) ;
if ( V_23 == V_30 )
V_181 = 1 << V_208 ;
else
V_181 = 0 ;
break;
default:
F_23 ( V_1 , 0 ) ;
return;
}
V_1 -> V_209 = F_97 ( V_181 ) ;
V_1 -> V_210 -> V_185 = & V_1 -> V_209 ;
V_1 -> V_210 -> V_120 = 2 ;
F_10 ( & V_1 -> V_14 ) ;
F_98 ( V_1 -> V_15 . V_211 , V_1 -> V_210 , V_212 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
static void F_99 ( struct V_1 * V_1 ,
struct V_197 * V_198 )
{
switch ( V_198 -> V_201 & V_202 ) {
case V_203 :
F_58 ( V_1 , 1 ) ;
break;
case V_205 :
F_58 ( V_1 , 1 ) ;
break;
case V_206 : {
struct V_57 * V_21 ;
struct V_117 * V_118 ;
T_1 V_199 = F_96 ( V_198 -> V_200 ) ;
V_21 = V_1 -> V_100 [ V_199 & V_207 ] ;
if ( ! V_21 -> V_213 ) {
F_22 ( V_1 , V_21 -> V_4 ) ;
F_25 ( V_1 , V_21 -> V_4 ) ;
F_10 ( & V_1 -> V_14 ) ;
F_100 ( & V_21 -> V_21 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
F_58 ( V_1 , 1 ) ;
V_118 = F_83 ( V_21 ) ;
if ( V_21 -> V_102 ) {
V_21 -> V_102 = 0 ;
if ( F_86 ( & V_21 -> V_22 ) )
break;
F_77 ( V_21 , V_118 ) ;
} else if ( ! F_86 ( & V_21 -> V_22 ) )
F_21 ( V_1 , V_21 -> V_4 ) ;
}
break;
default:
F_23 ( V_1 , 0 ) ;
break;
}
}
static void F_101 ( struct V_1 * V_1 , struct V_197 * V_198 )
{
T_1 V_6 ;
int V_214 = 3000 ;
switch ( V_198 -> V_201 & V_202 ) {
case V_203 :
switch ( F_96 ( V_198 -> V_215 ) ) {
case V_216 :
F_58 ( V_1 , 1 ) ;
do {
V_6 = F_2 ( V_1 , V_149 ) & V_150 ;
F_81 ( 1 ) ;
} while ( V_6 != V_217 || V_214 -- > 0 );
if ( V_6 == V_217 )
F_5 ( V_1 ,
F_96 ( V_198 -> V_200 >> 8 ) ,
V_175 ) ;
break;
default:
F_23 ( V_1 , 0 ) ;
break;
}
break;
case V_205 :
F_58 ( V_1 , 1 ) ;
break;
case V_206 : {
struct V_57 * V_21 ;
T_1 V_199 = F_96 ( V_198 -> V_200 ) ;
V_21 = V_1 -> V_100 [ V_199 & V_207 ] ;
F_23 ( V_1 , V_21 -> V_4 ) ;
F_58 ( V_1 , 1 ) ;
}
break;
default:
F_23 ( V_1 , 0 ) ;
break;
}
}
static int F_102 ( struct V_1 * V_1 , struct V_197 * V_198 )
{
T_1 * V_218 = ( T_1 * ) V_198 ;
unsigned long V_24 = V_219 ;
int V_54 , V_31 = 0 ;
F_6 ( V_1 , ~ V_220 , V_149 ) ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ )
V_218 [ V_54 ] = F_2 ( V_1 , V_24 + V_54 * 2 ) ;
if ( ( V_198 -> V_201 & V_221 ) == V_222 ) {
switch ( V_198 -> V_223 ) {
case V_224 :
F_95 ( V_1 , V_198 ) ;
break;
case V_225 :
F_99 ( V_1 , V_198 ) ;
break;
case V_226 :
F_101 ( V_1 , V_198 ) ;
break;
default:
V_31 = 1 ;
break;
}
} else
V_31 = 1 ;
return V_31 ;
}
static void F_103 ( struct V_1 * V_1 )
{
T_1 V_16 = F_1 ( V_1 ) ;
switch ( V_16 ) {
case V_227 :
V_1 -> V_15 . V_16 = V_228 ;
break;
case V_229 :
V_1 -> V_15 . V_16 = V_230 ;
break;
default:
V_1 -> V_15 . V_16 = V_17 ;
F_17 ( F_18 ( V_1 ) , L_17 ) ;
}
}
static void F_104 ( struct V_1 * V_1 )
{
T_1 V_231 ;
V_231 = F_2 ( V_1 , V_149 ) & V_232 ;
F_6 ( V_1 , ~ V_233 , V_149 ) ;
if ( V_231 == V_234 ) {
F_10 ( & V_1 -> V_14 ) ;
F_105 ( & V_1 -> V_15 , V_1 -> V_18 ) ;
F_11 ( & V_1 -> V_14 ) ;
F_103 ( V_1 ) ;
}
if ( V_1 -> V_235 == V_236 && V_231 != V_236 )
F_103 ( V_1 ) ;
if ( ( V_231 == V_236 || V_231 == V_237 )
&& V_1 -> V_15 . V_16 == V_17 )
F_103 ( V_1 ) ;
V_1 -> V_235 = V_231 ;
}
static void F_106 ( struct V_1 * V_1 )
__releases( V_1 -> V_14 )
__acquires( V_1 -> V_14 )
{
struct V_197 V_198 ;
T_1 V_148 ;
V_148 = F_2 ( V_1 , V_149 ) & V_150 ;
F_6 ( V_1 , ~ V_238 , V_149 ) ;
switch ( V_148 ) {
case V_217 : {
struct V_57 * V_21 ;
struct V_117 * V_118 ;
V_21 = & V_1 -> V_21 [ 0 ] ;
V_118 = F_83 ( V_21 ) ;
F_60 ( V_21 , V_118 , 0 ) ;
}
break;
case V_151 :
case V_152 :
case V_153 :
if ( F_102 ( V_1 , & V_198 ) ) {
F_10 ( & V_1 -> V_14 ) ;
if ( V_1 -> V_18 -> V_239 ( & V_1 -> V_15 , & V_198 )
< 0 )
F_23 ( V_1 , 0 ) ;
F_11 ( & V_1 -> V_14 ) ;
}
break;
case V_240 :
case V_241 :
F_58 ( V_1 , 0 ) ;
break;
default:
F_17 ( F_18 ( V_1 ) ,
L_18 , V_148 ) ;
break;
}
}
static void F_107 ( struct V_1 * V_1 , struct V_57 * V_21 )
{
T_1 V_4 ;
struct V_117 * V_118 ;
T_3 V_242 ;
int V_54 = 0 ;
V_4 = V_21 -> V_4 ;
F_34 ( V_1 , V_4 ) ;
while ( ! ( F_2 ( V_1 , V_21 -> V_96 ) & V_145 ) ) {
F_81 ( 1 ) ;
if ( F_73 ( V_54 ++ >= 10000 ) ) {
F_17 ( F_18 ( V_1 ) ,
L_19 ,
V_243 , V_4 ) ;
return;
}
}
F_5 ( V_1 , V_119 , V_21 -> V_96 ) ;
V_118 = F_83 ( V_21 ) ;
V_242 = F_108 ( V_1 , V_244 ) ;
V_118 -> V_118 . V_186 += V_242 ;
F_70 ( V_1 , V_245 , V_246 ) ;
if ( ( ! V_118 -> V_118 . V_187 && ( V_118 -> V_118 . V_186 == V_118 -> V_118 . V_120 ) )
|| ( V_242 % V_21 -> V_21 . V_82 ) ) {
if ( V_21 -> V_92 -> V_133 ) {
F_56 ( V_1 , V_4 ) ;
F_90 ( V_1 , V_4 ) ;
} else {
F_6 ( V_1 , ~ ( 1 << V_4 ) , V_144 ) ;
F_60 ( V_21 , V_118 , 0 ) ;
}
}
}
static void F_109 ( struct V_1 * V_1 )
{
T_3 V_247 ;
struct V_57 * V_21 ;
T_1 V_4 ;
V_247 = F_108 ( V_1 , V_248 ) ;
if ( V_247 & V_249 ) {
F_70 ( V_1 , V_250 , V_251 ) ;
V_4 = ( F_2 ( V_1 , V_126 ) & V_56 ) ;
V_21 = V_1 -> V_58 [ V_4 ] ;
F_107 ( V_1 , V_21 ) ;
}
}
static T_4 F_110 ( int V_252 , void * V_253 )
{
struct V_1 * V_1 = V_253 ;
T_1 V_254 ;
T_1 V_255 ;
T_1 V_256 ;
T_1 V_257 ;
F_11 ( & V_1 -> V_14 ) ;
if ( F_35 ( V_1 ) )
F_109 ( V_1 ) ;
V_254 = F_2 ( V_1 , V_149 ) ;
V_255 = F_2 ( V_1 , V_7 ) ;
V_256 = F_2 ( V_1 , V_95 ) ;
V_257 = V_254 & V_255 ;
if ( V_257 ) {
T_1 V_258 = F_2 ( V_1 , V_144 ) ;
T_1 V_259 = F_2 ( V_1 , V_123 ) ;
T_1 V_260 = F_2 ( V_1 , V_176 ) ;
T_1 V_261 = F_2 ( V_1 , V_177 ) ;
if ( V_257 & V_262 ) {
F_6 ( V_1 , 0xffff & ~ V_262 ,
V_149 ) ;
F_82 ( V_1 ) ;
V_1 -> V_263 = F_2 ( V_1 , V_149 )
& V_264 ;
V_1 -> V_265 = V_266 ;
F_111 ( & V_1 -> V_267 ,
V_268 + F_112 ( 50 ) ) ;
}
if ( V_254 & V_232 )
F_104 ( V_1 ) ;
if ( ( V_254 & V_269 ) && ( V_255 & V_10 )
&& ( V_258 & V_260 ) )
F_93 ( V_1 , V_258 , V_260 ) ;
if ( ( V_254 & V_270 ) && ( V_255 & V_8 )
&& ( V_259 & V_261 ) )
F_94 ( V_1 , V_259 , V_261 ) ;
if ( V_254 & V_238 )
F_106 ( V_1 ) ;
}
F_6 ( V_1 , V_256 , V_95 ) ;
F_10 ( & V_1 -> V_14 ) ;
return V_271 ;
}
static void F_113 ( unsigned long V_253 )
{
struct V_1 * V_1 = (struct V_1 * ) V_253 ;
unsigned long V_272 ;
T_1 V_6 ;
F_114 ( & V_1 -> V_14 , V_272 ) ;
V_6 = F_2 ( V_1 , V_13 ) ;
if ( V_1 -> V_265 > 0 ) {
V_6 = F_2 ( V_1 , V_149 ) & V_264 ;
if ( V_6 == V_1 -> V_263 ) {
V_1 -> V_265 -- ;
if ( V_1 -> V_265 == 0 ) {
if ( V_6 == V_264 )
F_8 ( V_1 ) ;
else
F_9 ( V_1 ) ;
} else {
F_111 ( & V_1 -> V_267 ,
V_268 + F_112 ( 50 ) ) ;
}
} else {
V_1 -> V_265 = V_266 ;
V_1 -> V_263 = V_6 ;
F_111 ( & V_1 -> V_267 ,
V_268 + F_112 ( 50 ) ) ;
}
}
F_115 ( & V_1 -> V_14 , V_272 ) ;
}
static int F_116 ( struct V_273 * V_274 ,
const struct V_90 * V_91 )
{
struct V_57 * V_21 ;
V_21 = F_117 ( V_274 , struct V_57 , V_21 ) ;
return F_49 ( V_21 , V_91 ) ;
}
static int F_118 ( struct V_273 * V_274 )
{
struct V_57 * V_21 ;
struct V_117 * V_118 ;
unsigned long V_272 ;
V_21 = F_117 ( V_274 , struct V_57 , V_21 ) ;
F_69 ( ! V_21 ) ;
while ( ! F_86 ( & V_21 -> V_22 ) ) {
V_118 = F_83 ( V_21 ) ;
F_114 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
F_60 ( V_21 , V_118 , - V_275 ) ;
F_115 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
}
F_55 ( V_21 -> V_1 , V_21 -> V_4 ) ;
return F_51 ( V_21 ) ;
}
static struct V_276 * F_119 ( struct V_273 * V_274 ,
T_5 V_277 )
{
struct V_117 * V_118 ;
V_118 = F_120 ( sizeof( struct V_117 ) , V_277 ) ;
if ( ! V_118 )
return NULL ;
F_14 ( & V_118 -> V_22 ) ;
return & V_118 -> V_118 ;
}
static void F_121 ( struct V_273 * V_274 , struct V_276 * V_278 )
{
struct V_117 * V_118 ;
V_118 = F_117 ( V_278 , struct V_117 , V_118 ) ;
F_122 ( V_118 ) ;
}
static int F_98 ( struct V_273 * V_274 , struct V_276 * V_278 ,
T_5 V_277 )
{
struct V_57 * V_21 ;
struct V_117 * V_118 ;
unsigned long V_272 ;
int V_279 = 0 ;
V_21 = F_117 ( V_274 , struct V_57 , V_21 ) ;
V_118 = F_117 ( V_278 , struct V_117 , V_118 ) ;
if ( V_21 -> V_1 -> V_15 . V_16 == V_17 )
return - V_183 ;
F_114 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
if ( F_86 ( & V_21 -> V_22 ) )
V_279 = 1 ;
F_123 ( & V_118 -> V_22 , & V_21 -> V_22 ) ;
V_118 -> V_118 . V_186 = 0 ;
V_118 -> V_118 . V_181 = - V_280 ;
if ( V_21 -> V_21 . V_91 == NULL )
F_78 ( V_21 , V_118 ) ;
else {
if ( V_279 && ! V_21 -> V_102 )
F_77 ( V_21 , V_118 ) ;
}
F_115 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
return 0 ;
}
static int F_124 ( struct V_273 * V_274 , struct V_276 * V_278 )
{
struct V_57 * V_21 ;
struct V_117 * V_118 ;
unsigned long V_272 ;
V_21 = F_117 ( V_274 , struct V_57 , V_21 ) ;
V_118 = F_117 ( V_278 , struct V_117 , V_118 ) ;
F_114 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
if ( ! F_86 ( & V_21 -> V_22 ) )
F_60 ( V_21 , V_118 , - V_275 ) ;
F_115 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
return 0 ;
}
static int F_125 ( struct V_273 * V_274 , int V_281 )
{
struct V_57 * V_21 = F_117 ( V_274 , struct V_57 , V_21 ) ;
unsigned long V_272 ;
int V_31 = 0 ;
F_114 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
if ( ! F_86 ( & V_21 -> V_22 ) ) {
V_31 = - V_282 ;
} else if ( V_281 ) {
V_21 -> V_102 = 1 ;
F_23 ( V_21 -> V_1 , V_21 -> V_4 ) ;
} else {
V_21 -> V_102 = 0 ;
V_21 -> V_213 = 0 ;
F_22 ( V_21 -> V_1 , V_21 -> V_4 ) ;
}
F_115 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
return V_31 ;
}
static int F_126 ( struct V_273 * V_274 )
{
struct V_57 * V_21 ;
unsigned long V_272 ;
V_21 = F_117 ( V_274 , struct V_57 , V_21 ) ;
if ( ! V_21 || ! V_21 -> V_21 . V_91 )
return - V_67 ;
F_114 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
V_21 -> V_213 = 1 ;
F_115 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
return F_127 ( V_274 ) ;
}
static void F_128 ( struct V_273 * V_274 )
{
struct V_57 * V_21 ;
unsigned long V_272 ;
V_21 = F_117 ( V_274 , struct V_57 , V_21 ) ;
F_114 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
if ( F_86 ( & V_21 -> V_22 ) && ! V_21 -> V_102 ) {
F_22 ( V_21 -> V_1 , V_21 -> V_4 ) ;
F_4 ( V_21 -> V_1 , V_119 , V_21 -> V_96 ) ;
F_6 ( V_21 -> V_1 , V_88 , V_21 -> V_89 ) ;
F_6 ( V_21 -> V_1 , 0 , V_21 -> V_89 ) ;
}
F_115 ( & V_21 -> V_1 -> V_14 , V_272 ) ;
}
static int F_129 ( struct V_283 * V_15 ,
struct V_284 * V_18 )
{
struct V_1 * V_1 = F_130 ( V_15 ) ;
if ( ! V_18
|| V_18 -> V_285 < V_228
|| ! V_18 -> V_239 )
return - V_67 ;
if ( ! V_1 )
return - V_107 ;
V_1 -> V_18 = V_18 ;
F_13 ( V_1 ) ;
F_5 ( V_1 , V_20 , V_7 ) ;
if ( F_2 ( V_1 , V_149 ) & V_264 ) {
F_82 ( V_1 ) ;
V_1 -> V_263 = F_2 ( V_1 ,
V_149 ) & V_264 ;
V_1 -> V_265 = V_266 ;
F_111 ( & V_1 -> V_267 , V_268 + F_112 ( 50 ) ) ;
}
return 0 ;
}
static int F_131 ( struct V_283 * V_15 )
{
struct V_1 * V_1 = F_130 ( V_15 ) ;
unsigned long V_272 ;
F_114 ( & V_1 -> V_14 , V_272 ) ;
F_4 ( V_1 , V_20 , V_7 ) ;
F_12 ( V_1 ) ;
F_115 ( & V_1 -> V_14 , V_272 ) ;
V_1 -> V_18 = NULL ;
return 0 ;
}
static int F_132 ( struct V_283 * V_286 )
{
struct V_1 * V_1 = F_130 ( V_286 ) ;
return F_2 ( V_1 , V_287 ) & 0x03FF ;
}
static int F_133 ( struct V_283 * V_15 , int V_288 )
{
struct V_1 * V_1 = F_130 ( V_15 ) ;
unsigned long V_272 ;
F_114 ( & V_1 -> V_14 , V_272 ) ;
if ( V_288 )
F_5 ( V_1 , V_12 , V_13 ) ;
else
F_4 ( V_1 , V_12 , V_13 ) ;
F_115 ( & V_1 -> V_14 , V_272 ) ;
return 0 ;
}
static int F_134 ( struct V_283 * V_15 , int V_289 )
{
struct V_1 * V_1 = F_130 ( V_15 ) ;
V_15 -> V_290 = ( V_289 != 0 ) ;
if ( V_289 )
V_1 -> V_204 |= 1 << V_291 ;
else
V_1 -> V_204 &= ~ ( 1 << V_291 ) ;
return 0 ;
}
static int F_135 ( struct V_292 * V_293 )
{
struct V_1 * V_1 = F_136 ( V_293 ) ;
F_137 ( & V_1 -> V_15 ) ;
F_138 ( & V_1 -> V_267 ) ;
F_121 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_210 ) ;
if ( V_1 -> V_46 -> V_47 ) {
F_139 ( V_1 -> V_294 ) ;
}
return 0 ;
}
static void F_140 ( struct V_273 * V_21 , struct V_276 * V_295 )
{
}
static int F_141 ( struct V_1 * V_1 ,
struct V_292 * V_293 )
{
struct V_296 * V_297 ;
V_297 = F_142 ( V_293 , V_298 , L_20 ) ;
V_1 -> V_299 = F_143 ( & V_293 -> V_300 , V_297 ) ;
return F_144 ( V_1 -> V_299 ) ;
}
static int F_145 ( struct V_292 * V_293 )
{
struct V_301 * V_300 = & V_293 -> V_300 ;
char V_302 [ 8 ] ;
struct V_296 * V_297 , * V_303 ;
int V_252 ;
void T_6 * V_5 = NULL ;
struct V_1 * V_1 = NULL ;
int V_31 = 0 ;
int V_54 ;
unsigned long V_304 ;
V_297 = F_146 ( V_293 , V_298 , 0 ) ;
V_5 = F_143 ( & V_293 -> V_300 , V_297 ) ;
if ( F_147 ( V_5 ) )
return F_148 ( V_5 ) ;
V_303 = F_146 ( V_293 , V_305 , 0 ) ;
V_252 = V_303 -> V_306 ;
V_304 = V_303 -> V_272 & V_307 ;
if ( V_252 < 0 ) {
F_17 ( V_300 , L_21 ) ;
return - V_107 ;
}
V_1 = F_149 ( V_300 , sizeof( struct V_1 ) , V_212 ) ;
if ( V_1 == NULL )
return - V_81 ;
F_150 ( & V_1 -> V_14 ) ;
F_151 ( V_293 , V_1 ) ;
V_1 -> V_46 = F_152 ( V_300 ) ;
V_1 -> V_157 = V_304 == V_308 ;
V_1 -> V_15 . V_309 = & V_310 ;
V_1 -> V_15 . V_285 = V_228 ;
V_1 -> V_15 . V_311 = V_312 ;
F_153 ( & V_1 -> V_267 ) ;
V_1 -> V_267 . V_313 = F_113 ;
V_1 -> V_267 . V_314 = ( unsigned long ) V_1 ;
V_1 -> V_5 = V_5 ;
if ( V_1 -> V_46 -> V_47 ) {
snprintf ( V_302 , sizeof( V_302 ) , L_22 , V_293 -> V_315 ) ;
V_1 -> V_294 = F_154 ( V_300 , V_302 ) ;
if ( F_147 ( V_1 -> V_294 ) ) {
F_17 ( V_300 , L_23 , V_302 ) ;
return F_148 ( V_1 -> V_294 ) ;
}
F_155 ( V_1 -> V_294 ) ;
}
if ( V_1 -> V_46 -> V_316 ) {
V_31 = F_141 ( V_1 , V_293 ) ;
if ( V_31 < 0 )
goto V_317;
}
F_12 ( V_1 ) ;
V_31 = F_156 ( V_300 , V_252 , F_110 , V_318 ,
V_312 , V_1 ) ;
if ( V_31 < 0 ) {
F_17 ( V_300 , L_24 , V_31 ) ;
goto V_317;
}
F_14 ( & V_1 -> V_15 . V_319 ) ;
V_1 -> V_15 . V_211 = & V_1 -> V_21 [ 0 ] . V_21 ;
F_14 ( & V_1 -> V_15 . V_211 -> V_319 ) ;
for ( V_54 = 0 ; V_54 < V_27 ; V_54 ++ ) {
struct V_57 * V_21 = & V_1 -> V_21 [ V_54 ] ;
if ( V_54 != 0 ) {
F_14 ( & V_1 -> V_21 [ V_54 ] . V_21 . V_319 ) ;
F_123 ( & V_1 -> V_21 [ V_54 ] . V_21 . V_319 ,
& V_1 -> V_15 . V_319 ) ;
}
V_21 -> V_1 = V_1 ;
F_14 ( & V_21 -> V_22 ) ;
V_21 -> V_21 . V_311 = V_320 [ V_54 ] ;
V_21 -> V_21 . V_309 = & V_321 ;
F_157 ( & V_21 -> V_21 , 512 ) ;
if ( V_54 == 0 ) {
V_21 -> V_21 . V_322 . V_323 = true ;
} else {
V_21 -> V_21 . V_322 . V_324 = true ;
V_21 -> V_21 . V_322 . V_325 = true ;
V_21 -> V_21 . V_322 . V_326 = true ;
}
V_21 -> V_21 . V_322 . V_68 = true ;
V_21 -> V_21 . V_322 . V_327 = true ;
}
F_157 ( & V_1 -> V_21 [ 0 ] . V_21 , 64 ) ;
V_1 -> V_21 [ 0 ] . V_4 = 0 ;
V_1 -> V_21 [ 0 ] . V_93 = V_94 ;
V_1 -> V_21 [ 0 ] . V_51 = V_95 ;
V_1 -> V_21 [ 0 ] . V_96 = V_97 ;
V_1 -> V_21 [ 0 ] . V_89 = F_16 ( 0 ) ;
V_1 -> V_58 [ 0 ] = & V_1 -> V_21 [ 0 ] ;
V_1 -> V_100 [ 0 ] = & V_1 -> V_21 [ 0 ] ;
V_1 -> V_210 = F_119 ( & V_1 -> V_21 [ 0 ] . V_21 ,
V_212 ) ;
if ( V_1 -> V_210 == NULL ) {
V_31 = - V_81 ;
goto V_317;
}
V_1 -> V_210 -> V_328 = F_140 ;
V_31 = F_158 ( V_300 , & V_1 -> V_15 ) ;
if ( V_31 )
goto V_329;
F_159 ( V_300 , L_25 , V_330 ) ;
return 0 ;
V_329:
F_121 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_210 ) ;
V_317:
if ( V_1 -> V_46 -> V_47 )
F_139 ( V_1 -> V_294 ) ;
if ( V_1 -> V_210 )
F_121 ( & V_1 -> V_21 [ 0 ] . V_21 , V_1 -> V_210 ) ;
return V_31 ;
}
