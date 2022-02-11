static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & ( V_3 -> V_4 -> V_5 ) ;
}
static inline void F_2 ( struct V_2 * V_3 )
{
F_3 ( V_3 -> V_6 , V_7 ,
V_8 | V_9 , V_8 | V_9 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
T_1 V_11 ;
T_2 * V_12 ;
F_5 ( V_6 ) ;
for ( V_11 = 0xFD40 ; V_11 <= 0xFD44 ; V_11 ++ )
F_6 ( V_6 , V_13 , V_11 , 0 , 0 ) ;
for ( V_11 = 0xFD52 ; V_11 <= 0xFD69 ; V_11 ++ )
F_6 ( V_6 , V_13 , V_11 , 0 , 0 ) ;
F_7 ( V_6 , 100 ) ;
V_12 = F_8 ( V_6 ) ;
for ( V_11 = 0xFD40 ; V_11 <= 0xFD44 ; V_11 ++ )
F_9 ( F_1 ( V_3 ) , L_1 , V_11 , * ( V_12 ++ ) ) ;
for ( V_11 = 0xFD52 ; V_11 <= 0xFD69 ; V_11 ++ )
F_9 ( F_1 ( V_3 ) , L_1 , V_11 , * ( V_12 ++ ) ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_14 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_15 , V_16 , 0x07 , V_17 ) ;
F_6 ( V_6 , V_15 , V_18 ,
V_19 , V_20 ) ;
F_6 ( V_6 , V_15 , V_21 ,
V_22 , V_22 ) ;
V_14 = F_7 ( V_6 , 100 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_11 ( V_6 , V_23 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_12 ( V_6 , V_23 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( 150 ) ;
V_14 = F_3 ( V_6 , V_24 ,
V_25 , V_25 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_14 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_15 , V_21 , V_22 , 0 ) ;
F_6 ( V_6 , V_15 , V_24 , V_25 , 0 ) ;
V_14 = F_7 ( V_6 , 100 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_15 ( V_6 , V_23 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_16 ( V_6 , V_23 ) ;
}
static int F_17 ( struct V_2 * V_3 , unsigned char V_26 ,
T_2 V_27 , T_2 V_28 , struct V_29 * V_30 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_14 ;
unsigned int V_31 = V_30 -> V_31 ;
T_1 V_32 = ( T_1 ) ( V_31 / 512 ) ;
T_2 V_33 , V_34 , V_35 ;
struct V_36 * V_37 = V_3 -> V_38 -> V_37 ;
bool V_39 = V_37 -> V_40 . type == V_41 ;
F_9 ( F_1 ( V_3 ) , L_2 ,
V_42 , V_27 , ( V_26 == V_43 ) ? L_3 : L_4 ,
V_31 ) ;
if ( V_26 == V_43 ) {
V_35 = V_44 ;
V_34 = V_39 ? V_45 : V_46 ;
} else {
V_35 = V_47 ;
V_34 = V_39 ? V_48 : V_49 ;
}
F_5 ( V_6 ) ;
F_6 ( V_6 , V_15 , V_50 , 0xFF , V_27 ) ;
if ( V_39 ) {
F_6 ( V_6 , V_15 , V_51 ,
0xFF , ( T_2 ) ( V_32 >> 8 ) ) ;
F_6 ( V_6 , V_15 , V_52 ,
0xFF , ( T_2 ) V_32 ) ;
}
F_6 ( V_6 , V_15 , V_53 , 0xFF , V_28 ) ;
F_6 ( V_6 , V_15 , V_54 ,
V_55 , V_55 ) ;
F_6 ( V_6 , V_15 , V_56 , 0xFF , ( T_2 ) ( V_31 >> 24 ) ) ;
F_6 ( V_6 , V_15 , V_57 , 0xFF , ( T_2 ) ( V_31 >> 16 ) ) ;
F_6 ( V_6 , V_15 , V_58 , 0xFF , ( T_2 ) ( V_31 >> 8 ) ) ;
F_6 ( V_6 , V_15 , V_59 , 0xFF , ( T_2 ) V_31 ) ;
F_6 ( V_6 , V_15 , V_60 ,
0x03 | V_61 , V_35 | V_62 | V_63 ) ;
F_6 ( V_6 , V_15 , V_64 ,
0x01 , V_65 ) ;
F_6 ( V_6 , V_15 , V_66 ,
0xFF , V_67 | V_34 ) ;
F_6 ( V_6 , V_68 , V_66 ,
V_69 , V_69 ) ;
F_18 ( V_6 ) ;
V_14 = F_19 ( V_6 , V_30 , 1 , V_26 == V_43 , 10000 ) ;
if ( V_14 < 0 ) {
F_2 ( V_3 ) ;
return V_14 ;
}
F_20 ( V_6 , V_53 , & V_33 ) ;
if ( V_39 ) {
if ( V_33 & ( V_70 | V_71 |
V_72 | V_73 ) )
return - V_74 ;
} else {
if ( V_33 & ( V_72 | V_73 ) )
return - V_74 ;
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_27 ,
T_2 V_28 , T_2 V_75 , T_2 * V_76 , T_2 * V_77 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_14 , V_11 ;
F_9 ( F_1 ( V_3 ) , L_5 , V_42 , V_27 ) ;
if ( ! V_76 )
return - V_78 ;
F_5 ( V_6 ) ;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ )
F_6 ( V_6 , V_15 ,
V_79 + V_11 , 0xFF , V_76 [ V_11 ] ) ;
if ( V_75 % 2 )
F_6 ( V_6 , V_15 ,
V_79 + V_11 , 0xFF , 0xFF ) ;
F_6 ( V_6 , V_15 , V_50 , 0xFF , V_27 ) ;
F_6 ( V_6 , V_15 , V_80 , 0xFF , V_75 ) ;
F_6 ( V_6 , V_15 , V_53 , 0xFF , V_28 ) ;
F_6 ( V_6 , V_15 , V_64 ,
0x01 , V_81 ) ;
F_6 ( V_6 , V_15 , V_66 ,
0xFF , V_67 | V_82 ) ;
F_6 ( V_6 , V_68 , V_66 ,
V_69 , V_69 ) ;
if ( V_77 )
F_6 ( V_6 , V_13 , V_53 , 0 , 0 ) ;
V_14 = F_7 ( V_6 , 5000 ) ;
if ( V_14 < 0 ) {
T_2 V_33 ;
F_20 ( V_6 , V_53 , & V_33 ) ;
F_9 ( F_1 ( V_3 ) , L_6 , V_33 ) ;
if ( V_77 )
* V_77 = V_33 & 0x0F ;
F_4 ( V_3 ) ;
F_2 ( V_3 ) ;
if ( ! ( V_27 & 0x08 ) ) {
if ( V_33 & V_72 )
return - V_74 ;
} else {
if ( ! ( V_33 & 0x80 ) ) {
if ( V_33 & ( V_71 | V_70 ) )
return - V_74 ;
}
}
return - V_83 ;
}
if ( V_77 ) {
T_2 * V_12 = F_8 ( V_6 ) + 1 ;
* V_77 = * V_12 & 0x0F ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , T_2 V_27 ,
T_2 V_28 , T_2 V_75 , T_2 * V_76 , T_2 * V_77 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_14 , V_11 ;
T_2 * V_12 ;
F_9 ( F_1 ( V_3 ) , L_5 , V_42 , V_27 ) ;
if ( ! V_76 )
return - V_78 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_15 , V_50 , 0xFF , V_27 ) ;
F_6 ( V_6 , V_15 , V_80 , 0xFF , V_75 ) ;
F_6 ( V_6 , V_15 , V_53 , 0xFF , V_28 ) ;
F_6 ( V_6 , V_15 , V_64 ,
0x01 , V_81 ) ;
F_6 ( V_6 , V_15 , V_66 ,
0xFF , V_67 | V_84 ) ;
F_6 ( V_6 , V_68 , V_66 ,
V_69 , V_69 ) ;
for ( V_11 = 0 ; V_11 < V_75 - 1 ; V_11 ++ )
F_6 ( V_6 , V_13 , V_79 + V_11 , 0 , 0 ) ;
if ( V_75 % 2 )
F_6 ( V_6 , V_13 , V_79 + V_75 , 0 , 0 ) ;
else
F_6 ( V_6 , V_13 ,
V_79 + V_75 - 1 , 0 , 0 ) ;
if ( V_77 )
F_6 ( V_6 , V_13 , V_53 , 0 , 0 ) ;
V_14 = F_7 ( V_6 , 5000 ) ;
if ( V_14 < 0 ) {
T_2 V_33 ;
F_20 ( V_6 , V_53 , & V_33 ) ;
F_9 ( F_1 ( V_3 ) , L_6 , V_33 ) ;
if ( V_77 )
* V_77 = V_33 & 0x0F ;
F_4 ( V_3 ) ;
F_2 ( V_3 ) ;
if ( ! ( V_27 & 0x08 ) ) {
if ( V_33 & V_72 )
return - V_74 ;
} else {
if ( ! ( V_33 & 0x80 ) ) {
if ( V_33 & ( V_71 | V_70 ) )
return - V_74 ;
}
}
return - V_83 ;
}
V_12 = F_8 ( V_6 ) + 1 ;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ )
V_76 [ V_11 ] = * V_12 ++ ;
if ( V_77 )
* V_77 = * V_12 & 0x0F ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_85 * V_86 = V_3 -> V_86 ;
int V_14 = 0 ;
T_2 V_28 = 0 , V_77 ;
F_9 ( F_1 ( V_3 ) , L_7 , V_42 ) ;
if ( V_86 -> V_87 ) {
if ( V_3 -> V_88 != V_89 )
V_28 = V_90 ;
}
if ( V_86 -> V_91 ) {
V_14 = F_17 ( V_3 , V_86 -> V_26 ,
V_86 -> V_27 , V_28 , & ( V_86 -> V_30 ) ) ;
} else {
if ( V_86 -> V_26 == V_43 ) {
V_14 = F_22 ( V_3 , V_86 -> V_27 , V_28 ,
V_86 -> V_92 , V_86 -> V_76 , & V_77 ) ;
} else {
V_14 = F_21 ( V_3 , V_86 -> V_27 , V_28 ,
V_86 -> V_92 , V_86 -> V_76 , & V_77 ) ;
}
}
if ( V_14 < 0 )
return V_14 ;
if ( V_86 -> V_87 && ( V_3 -> V_88 == V_89 ) ) {
V_14 = F_22 ( V_3 , V_93 ,
V_94 , 1 , & V_77 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_86 -> V_87 ) {
F_9 ( F_1 ( V_3 ) , L_8 , V_77 ) ;
if ( V_77 & V_70 )
V_86 -> V_77 |= V_95 ;
if ( V_77 & V_96 )
V_86 -> V_77 |= V_97 ;
if ( V_77 & V_71 )
V_86 -> V_77 |= V_98 ;
if ( V_77 & V_99 )
V_86 -> V_77 |= V_100 ;
}
return 0 ;
}
static void F_24 ( struct V_101 * V_102 )
{
struct V_2 * V_3 = F_25 ( V_102 ,
struct V_2 , V_103 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_104 * V_38 = V_3 -> V_38 ;
int V_105 ;
F_26 ( & V_6 -> V_106 ) ;
F_27 ( V_6 ) ;
F_28 ( V_3 -> V_6 , V_3 -> clock , V_3 -> V_107 ,
false , true , false ) ;
F_3 ( V_6 , V_16 , 0x07 , V_17 ) ;
F_3 ( V_6 , V_18 ,
V_19 , V_20 ) ;
if ( ! V_3 -> V_86 ) {
do {
V_105 = F_29 ( V_38 , & V_3 -> V_86 ) ;
F_9 ( F_1 ( V_3 ) , L_9 , V_105 ) ;
if ( ! V_105 )
V_3 -> V_86 -> error = F_23 ( V_3 ) ;
} while ( ! V_105 );
}
F_30 ( & V_6 -> V_106 ) ;
}
static void F_31 ( struct V_104 * V_38 )
{
struct V_2 * V_3 = F_32 ( V_38 ) ;
F_9 ( F_1 ( V_3 ) , L_10 , V_42 ) ;
if ( F_33 ( V_3 -> V_6 , V_23 ) )
return;
F_34 ( & V_3 -> V_103 ) ;
}
static int F_35 ( struct V_104 * V_38 ,
enum V_108 V_109 , int V_110 )
{
struct V_2 * V_3 = F_32 ( V_38 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
unsigned int clock = 0 ;
T_2 V_107 = 0 ;
int V_14 ;
F_9 ( F_1 ( V_3 ) , L_11 ,
V_42 , V_109 , V_110 ) ;
V_14 = F_33 ( V_3 -> V_6 , V_23 ) ;
if ( V_14 )
return V_14 ;
switch ( V_109 ) {
case V_111 :
if ( V_110 == V_112 )
V_14 = F_10 ( V_3 ) ;
else if ( V_110 == V_113 )
V_14 = F_14 ( V_3 ) ;
else
return - V_78 ;
break;
case V_114 :
if ( V_110 == V_89 ) {
clock = 19000000 ;
V_107 = V_115 ;
V_14 = F_3 ( V_6 , V_116 , 0x58 ,
V_117 | V_118 ) ;
if ( V_14 < 0 )
return V_14 ;
} else if ( V_110 == V_119 ) {
clock = 39000000 ;
V_107 = V_120 ;
V_14 = F_3 ( V_6 , V_116 ,
0x58 , V_121 | V_122 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
return - V_78 ;
}
V_14 = F_28 ( V_6 , clock ,
V_107 , false , true , false ) ;
if ( V_14 < 0 )
return V_14 ;
V_3 -> V_107 = V_107 ;
V_3 -> clock = clock ;
V_3 -> V_88 = V_110 ;
break;
}
return 0 ;
}
static int F_36 ( struct V_123 * V_4 , T_3 V_124 )
{
struct V_2 * V_3 = F_37 ( V_4 ) ;
struct V_104 * V_38 = V_3 -> V_38 ;
F_9 ( F_1 ( V_3 ) , L_10 , V_42 ) ;
F_38 ( V_38 ) ;
return 0 ;
}
static int F_39 ( struct V_123 * V_4 )
{
struct V_2 * V_3 = F_37 ( V_4 ) ;
struct V_104 * V_38 = V_3 -> V_38 ;
F_9 ( F_1 ( V_3 ) , L_10 , V_42 ) ;
F_40 ( V_38 ) ;
return 0 ;
}
static void F_41 ( struct V_123 * V_4 )
{
struct V_2 * V_3 = F_37 ( V_4 ) ;
F_42 ( V_3 -> V_38 ) ;
}
static int F_43 ( struct V_123 * V_4 )
{
struct V_104 * V_38 ;
struct V_2 * V_3 ;
struct V_10 * V_6 ;
struct V_125 * V_126 = V_4 -> V_5 . V_127 ;
int V_105 ;
if ( ! V_126 )
return - V_128 ;
V_6 = V_126 -> V_6 ;
if ( ! V_6 )
return - V_128 ;
F_9 ( & ( V_4 -> V_5 ) ,
L_12 ) ;
V_38 = F_44 ( sizeof( * V_3 ) , & V_4 -> V_5 ) ;
if ( ! V_38 )
return - V_129 ;
V_3 = F_32 ( V_38 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_38 = V_38 ;
V_3 -> V_4 = V_4 ;
F_45 ( V_4 , V_3 ) ;
V_6 -> V_130 [ V_23 ] . V_131 = V_4 ;
V_6 -> V_130 [ V_23 ] . V_132 = F_41 ;
F_46 ( & V_3 -> V_133 ) ;
F_47 ( & V_3 -> V_103 , F_24 ) ;
V_38 -> V_134 = F_31 ;
V_38 -> V_135 = F_35 ;
V_38 -> V_136 = V_137 ;
V_105 = F_48 ( V_38 ) ;
if ( V_105 ) {
F_49 ( V_38 ) ;
return V_105 ;
}
return 0 ;
}
static int F_50 ( struct V_123 * V_4 )
{
struct V_2 * V_3 = F_37 ( V_4 ) ;
struct V_10 * V_6 ;
struct V_104 * V_38 ;
int V_105 ;
if ( ! V_3 )
return 0 ;
V_6 = V_3 -> V_6 ;
V_6 -> V_130 [ V_23 ] . V_131 = NULL ;
V_6 -> V_130 [ V_23 ] . V_132 = NULL ;
V_38 = V_3 -> V_38 ;
V_3 -> V_138 = true ;
F_26 ( & V_3 -> V_133 ) ;
if ( V_3 -> V_86 ) {
F_9 ( & ( V_4 -> V_5 ) ,
L_13 ,
F_51 ( & V_38 -> V_5 ) ) ;
F_52 ( V_6 ) ;
V_3 -> V_86 -> error = - V_139 ;
do {
V_105 = F_29 ( V_38 , & V_3 -> V_86 ) ;
if ( ! V_105 )
V_3 -> V_86 -> error = - V_139 ;
} while ( ! V_105 );
}
F_30 ( & V_3 -> V_133 ) ;
F_53 ( V_38 ) ;
F_49 ( V_38 ) ;
F_9 ( & ( V_4 -> V_5 ) ,
L_14 ) ;
return 0 ;
}
