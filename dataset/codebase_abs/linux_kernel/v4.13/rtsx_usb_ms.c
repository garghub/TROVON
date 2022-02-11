static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & ( V_3 -> V_4 -> V_5 ) ;
}
static inline void F_2 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
F_3 ( V_7 , V_8 ,
V_9 | V_10 ,
V_9 | V_10 ) ;
F_4 ( V_7 ) ;
F_5 ( V_7 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
T_1 V_11 ;
T_2 * V_12 ;
F_7 ( V_7 ) ;
for ( V_11 = 0xFD40 ; V_11 <= 0xFD44 ; V_11 ++ )
F_8 ( V_7 , V_13 , V_11 , 0 , 0 ) ;
for ( V_11 = 0xFD51 ; V_11 <= 0xFD56 ; V_11 ++ )
F_8 ( V_7 , V_13 , V_11 , 0 , 0 ) ;
for ( V_11 = 0xFD60 ; V_11 <= 0xFD65 ; V_11 ++ )
F_8 ( V_7 , V_13 , V_11 , 0 , 0 ) ;
F_8 ( V_7 , V_13 , V_14 , 0 , 0 ) ;
F_8 ( V_7 , V_13 , V_15 , 0 , 0 ) ;
F_8 ( V_7 , V_13 , V_16 , 0 , 0 ) ;
F_8 ( V_7 , V_13 , V_17 , 0 , 0 ) ;
F_9 ( V_7 , V_18 , 100 ) ;
F_10 ( V_7 , 21 , 100 ) ;
V_12 = V_7 -> V_19 ;
for ( V_11 = 0xFD40 ; V_11 <= 0xFD44 ; V_11 ++ )
F_11 ( F_1 ( V_3 ) , L_1 , V_11 , * ( V_12 ++ ) ) ;
for ( V_11 = 0xFD51 ; V_11 <= 0xFD56 ; V_11 ++ )
F_11 ( F_1 ( V_3 ) , L_1 , V_11 , * ( V_12 ++ ) ) ;
for ( V_11 = 0xFD60 ; V_11 <= 0xFD65 ; V_11 ++ )
F_11 ( F_1 ( V_3 ) , L_1 , V_11 , * ( V_12 ++ ) ) ;
F_11 ( F_1 ( V_3 ) , L_1 , V_14 , * ( V_12 ++ ) ) ;
F_11 ( F_1 ( V_3 ) , L_1 , V_15 , * ( V_12 ++ ) ) ;
F_11 ( F_1 ( V_3 ) , L_1 , V_16 , * ( V_12 ++ ) ) ;
F_11 ( F_1 ( V_3 ) , L_1 , V_17 , * ( V_12 ++ ) ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
}
static int F_12 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_21 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_22 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_23 , 0xFF , 0x95 ) ;
F_8 ( V_7 , V_20 , V_24 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_25 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_26 , 0xFF , 0xA5 ) ;
return F_9 ( V_7 , V_27 , 100 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_21 , 0xFF , 0x65 ) ;
F_8 ( V_7 , V_20 , V_22 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_23 , 0xFF , 0x95 ) ;
F_8 ( V_7 , V_20 , V_24 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_25 , 0xFF , 0x56 ) ;
F_8 ( V_7 , V_20 , V_26 , 0xFF , 0x59 ) ;
return F_9 ( V_7 , V_27 , 100 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_21 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_22 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_23 , 0xFF , 0x95 ) ;
F_8 ( V_7 , V_20 , V_24 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_25 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_26 , 0xFF , 0xA5 ) ;
return F_9 ( V_7 , V_27 , 100 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_21 , 0xFF , 0x65 ) ;
F_8 ( V_7 , V_20 , V_22 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_23 , 0xFF , 0x95 ) ;
F_8 ( V_7 , V_20 , V_24 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_25 , 0xFF , 0x55 ) ;
F_8 ( V_7 , V_20 , V_26 , 0xFF , 0x59 ) ;
return F_9 ( V_7 , V_27 , 100 ) ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_28 ;
F_11 ( F_1 ( V_3 ) , L_2 , V_29 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_15 , 0x07 , V_30 ) ;
F_8 ( V_7 , V_20 , V_31 ,
V_32 , V_33 ) ;
F_8 ( V_7 , V_20 , V_16 ,
V_34 , V_34 ) ;
V_28 = F_9 ( V_7 , V_27 , 100 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_17 ( V_7 , V_35 ) )
V_28 = F_14 ( V_7 ) ;
else
V_28 = F_15 ( V_7 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_18 ( V_7 , V_17 ,
V_36 , V_37 ) ;
if ( V_28 )
return V_28 ;
F_19 ( 800 , 1000 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_17 ,
V_36 , V_38 ) ;
F_8 ( V_7 , V_20 , V_39 ,
V_40 , V_40 ) ;
return F_9 ( V_7 , V_27 , 100 ) ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_28 ;
F_11 ( F_1 ( V_3 ) , L_2 , V_29 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_16 , V_34 , 0 ) ;
F_8 ( V_7 , V_20 , V_39 , V_40 , 0 ) ;
V_28 = F_9 ( V_7 , V_27 , 100 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( F_17 ( V_7 , V_35 ) )
return F_12 ( V_7 ) ;
return F_13 ( V_7 ) ;
}
static int F_21 ( struct V_2 * V_3 , unsigned char V_41 ,
T_2 V_42 , T_2 V_43 , struct V_44 * V_45 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_28 ;
unsigned int V_46 = V_45 -> V_46 ;
T_1 V_47 = ( T_1 ) ( V_46 / 512 ) ;
T_2 V_48 , V_49 , V_50 ;
unsigned int V_51 ;
struct V_52 * V_53 = V_3 -> V_54 -> V_53 ;
F_11 ( F_1 ( V_3 ) , L_3 ,
V_29 , V_42 , ( V_41 == V_55 ) ? L_4 : L_5 ,
V_46 ) ;
if ( V_41 == V_55 ) {
V_50 = V_56 ;
V_49 = V_57 ;
if ( V_53 -> V_58 . type != V_59 )
V_48 = V_60 ;
else
V_48 = V_61 ;
V_51 = F_22 ( V_7 -> V_62 , V_63 ) ;
} else {
V_50 = V_64 ;
V_49 = V_65 ;
if ( V_53 -> V_58 . type != V_59 )
V_48 = V_66 ;
else
V_48 = V_67 ;
V_51 = F_23 ( V_7 -> V_62 , V_68 ) ;
}
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_69 , 0xFF , V_42 ) ;
if ( V_53 -> V_58 . type == V_59 ) {
F_8 ( V_7 , V_20 , V_70 ,
0xFF , ( T_2 ) ( V_47 >> 8 ) ) ;
F_8 ( V_7 , V_20 , V_71 ,
0xFF , ( T_2 ) V_47 ) ;
}
F_8 ( V_7 , V_20 , V_72 , 0xFF , V_43 ) ;
F_8 ( V_7 , V_20 , V_73 ,
0xFF , ( T_2 ) ( V_46 >> 24 ) ) ;
F_8 ( V_7 , V_20 , V_74 ,
0xFF , ( T_2 ) ( V_46 >> 16 ) ) ;
F_8 ( V_7 , V_20 , V_75 ,
0xFF , ( T_2 ) ( V_46 >> 8 ) ) ;
F_8 ( V_7 , V_20 , V_76 , 0xFF ,
( T_2 ) V_46 ) ;
F_8 ( V_7 , V_20 , V_77 ,
0x03 | V_78 , V_49 | V_79 | V_80 ) ;
F_8 ( V_7 , V_20 , V_14 ,
0x01 , V_81 ) ;
F_8 ( V_7 , V_20 , V_82 ,
0xFF , V_83 | V_48 ) ;
F_8 ( V_7 , V_84 , V_82 ,
V_85 , V_85 ) ;
V_28 = F_9 ( V_7 , V_50 | V_86 , 100 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_24 ( V_7 , V_51 , V_45 , V_46 ,
1 , NULL , 10000 ) ;
if ( V_28 )
goto V_87;
V_28 = F_10 ( V_7 , 3 , 15000 ) ;
if ( V_28 )
goto V_87;
if ( V_7 -> V_19 [ 0 ] & V_88 ||
V_7 -> V_19 [ 1 ] & ( V_89 | V_90 ) ) {
V_28 = - V_91 ;
goto V_87;
}
return 0 ;
V_87:
F_2 ( V_3 ) ;
return V_28 ;
}
static int F_25 ( struct V_2 * V_3 , T_2 V_42 ,
T_2 V_43 , T_2 V_92 , T_2 * V_93 , T_2 * V_94 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_28 , V_11 ;
F_11 ( F_1 ( V_3 ) , L_6 , V_29 , V_42 ) ;
F_7 ( V_7 ) ;
for ( V_11 = 0 ; V_11 < V_92 ; V_11 ++ )
F_8 ( V_7 , V_20 ,
V_95 + V_11 , 0xFF , V_93 [ V_11 ] ) ;
if ( V_92 % 2 )
F_8 ( V_7 , V_20 ,
V_95 + V_11 , 0xFF , 0xFF ) ;
F_8 ( V_7 , V_20 , V_69 , 0xFF , V_42 ) ;
F_8 ( V_7 , V_20 , V_96 , 0xFF , V_92 ) ;
F_8 ( V_7 , V_20 , V_72 , 0xFF , V_43 ) ;
F_8 ( V_7 , V_20 , V_14 ,
0x01 , V_97 ) ;
F_8 ( V_7 , V_20 , V_82 ,
0xFF , V_83 | V_98 ) ;
F_8 ( V_7 , V_84 , V_82 ,
V_85 , V_85 ) ;
F_8 ( V_7 , V_13 , V_72 , 0 , 0 ) ;
V_28 = F_9 ( V_7 , V_18 , 100 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_10 ( V_7 , 2 , 5000 ) ;
if ( V_28 || ( V_7 -> V_19 [ 0 ] & V_88 ) ) {
T_2 V_99 ;
F_26 ( V_7 , V_72 , & V_99 ) ;
F_11 ( F_1 ( V_3 ) , L_7 , V_99 ) ;
if ( V_94 )
* V_94 = V_99 & 0x0F ;
F_6 ( V_3 ) ;
F_2 ( V_3 ) ;
if ( ! ( V_42 & 0x08 ) ) {
if ( V_99 & V_89 )
return - V_91 ;
} else {
if ( ! ( V_99 & 0x80 ) ) {
if ( V_99 & ( V_100 | V_101 ) )
return - V_91 ;
}
}
return - V_102 ;
}
if ( V_94 )
* V_94 = V_7 -> V_19 [ 1 ] & 0x0F ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , T_2 V_42 ,
T_2 V_43 , T_2 V_92 , T_2 * V_93 , T_2 * V_94 )
{
struct V_6 * V_7 = V_3 -> V_7 ;
int V_28 , V_11 ;
T_2 * V_12 ;
F_11 ( F_1 ( V_3 ) , L_6 , V_29 , V_42 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 , V_20 , V_69 , 0xFF , V_42 ) ;
F_8 ( V_7 , V_20 , V_96 , 0xFF , V_92 ) ;
F_8 ( V_7 , V_20 , V_72 , 0xFF , V_43 ) ;
F_8 ( V_7 , V_20 , V_14 ,
0x01 , V_97 ) ;
F_8 ( V_7 , V_20 , V_82 ,
0xFF , V_83 | V_103 ) ;
F_8 ( V_7 , V_84 , V_82 ,
V_85 , V_85 ) ;
for ( V_11 = 0 ; V_11 < V_92 - 1 ; V_11 ++ )
F_8 ( V_7 , V_13 , V_95 + V_11 , 0 , 0 ) ;
if ( V_92 % 2 )
F_8 ( V_7 , V_13 , V_95 + V_92 , 0 , 0 ) ;
else
F_8 ( V_7 , V_13 ,
V_95 + V_92 - 1 , 0 , 0 ) ;
F_8 ( V_7 , V_13 , V_72 , 0 , 0 ) ;
V_28 = F_9 ( V_7 , V_18 , 100 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_10 ( V_7 , V_92 + 2 , 5000 ) ;
if ( V_28 || ( V_7 -> V_19 [ 0 ] & V_88 ) ) {
T_2 V_99 ;
F_26 ( V_7 , V_72 , & V_99 ) ;
F_11 ( F_1 ( V_3 ) , L_7 , V_99 ) ;
if ( V_94 && ( V_3 -> V_104 != V_105 ) )
* V_94 = V_99 & 0x0F ;
F_6 ( V_3 ) ;
F_2 ( V_3 ) ;
if ( ! ( V_42 & 0x08 ) ) {
if ( V_99 & V_89 )
return - V_91 ;
} else {
if ( ! ( V_99 & 0x80 ) ) {
if ( V_99 & ( V_100 | V_101 ) )
return - V_91 ;
}
}
return - V_102 ;
}
V_12 = V_7 -> V_19 + 1 ;
for ( V_11 = 0 ; V_11 < V_92 ; V_11 ++ )
V_93 [ V_11 ] = * V_12 ++ ;
if ( V_94 && ( V_3 -> V_104 != V_105 ) )
* V_94 = * V_12 & 0x0F ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_106 * V_107 = V_3 -> V_107 ;
int V_28 = 0 ;
T_2 V_43 = 0 , V_94 ;
F_11 ( F_1 ( V_3 ) , L_2 , V_29 ) ;
if ( V_107 -> V_108 ) {
if ( V_3 -> V_104 != V_105 )
V_43 = V_109 ;
}
if ( V_107 -> V_110 ) {
V_28 = F_21 ( V_3 , V_107 -> V_41 ,
V_107 -> V_42 , V_43 , & ( V_107 -> V_45 ) ) ;
} else {
if ( V_107 -> V_41 == V_55 )
V_28 = F_27 ( V_3 , V_107 -> V_42 , V_43 ,
V_107 -> V_111 , V_107 -> V_93 , & V_94 ) ;
else
V_28 = F_25 ( V_3 , V_107 -> V_42 , V_43 ,
V_107 -> V_111 , V_107 -> V_93 , & V_94 ) ;
}
if ( V_28 < 0 )
return V_28 ;
if ( V_107 -> V_108 ) {
if ( V_3 -> V_104 == V_105 ) {
V_28 = F_27 ( V_3 , V_112 ,
V_113 , 1 , & V_107 -> V_94 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
} else {
if ( V_94 & V_101 )
V_107 -> V_94 |= V_114 ;
if ( V_94 & V_115 )
V_107 -> V_94 |= V_116 ;
if ( V_94 & V_100 )
V_107 -> V_94 |= V_117 ;
if ( V_94 & V_118 )
V_107 -> V_94 |= V_119 ;
}
F_11 ( F_1 ( V_3 ) , L_8 , V_107 -> V_94 ) ;
}
return 0 ;
}
static void F_29 ( struct V_120 * V_121 )
{
struct V_2 * V_3 = F_30 ( V_121 ,
struct V_2 , V_122 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
struct V_123 * V_54 = V_3 -> V_54 ;
int V_124 ;
if ( ! V_3 -> V_107 ) {
F_31 ( F_1 ( V_3 ) ) ;
do {
V_124 = F_32 ( V_54 , & V_3 -> V_107 ) ;
F_11 ( F_1 ( V_3 ) , L_9 , V_124 ) ;
if ( ! V_124 ) {
F_33 ( & V_7 -> V_125 ) ;
if ( F_34 ( V_7 ,
V_126 ) )
V_3 -> V_107 -> error = - V_91 ;
else
V_3 -> V_107 -> error =
F_28 ( V_3 ) ;
F_35 ( & V_7 -> V_125 ) ;
F_11 ( F_1 ( V_3 ) , L_10 ,
V_3 -> V_107 -> error ) ;
}
} while ( ! V_124 );
F_36 ( F_1 ( V_3 ) ) ;
}
}
static void F_37 ( struct V_123 * V_54 )
{
struct V_2 * V_3 = F_38 ( V_54 ) ;
F_11 ( F_1 ( V_3 ) , L_11 , V_29 ) ;
if ( ! V_3 -> V_127 )
F_39 ( & V_3 -> V_122 ) ;
}
static int F_40 ( struct V_123 * V_54 ,
enum V_128 V_129 , int V_130 )
{
struct V_2 * V_3 = F_38 ( V_54 ) ;
struct V_6 * V_7 = V_3 -> V_7 ;
unsigned int clock = 0 ;
T_2 V_131 = 0 ;
int V_28 ;
F_11 ( F_1 ( V_3 ) , L_12 ,
V_29 , V_129 , V_130 ) ;
F_31 ( F_1 ( V_3 ) ) ;
F_33 ( & V_7 -> V_125 ) ;
V_28 = F_34 ( V_7 , V_126 ) ;
if ( V_28 )
goto V_132;
switch ( V_129 ) {
case V_133 :
if ( V_130 == V_3 -> V_134 )
break;
if ( V_130 == V_135 ) {
F_31 ( F_1 ( V_3 ) ) ;
V_28 = F_16 ( V_3 ) ;
} else if ( V_130 == V_136 ) {
V_28 = F_20 ( V_3 ) ;
if ( V_3 -> V_54 -> V_53 )
F_41 ( F_1 ( V_3 ) ) ;
else
F_36 ( F_1 ( V_3 ) ) ;
} else
V_28 = - V_137 ;
if ( ! V_28 )
V_3 -> V_134 = V_130 ;
break;
case V_138 :
if ( V_130 == V_105 ) {
clock = 19000000 ;
V_131 = V_139 ;
V_28 = F_18 ( V_7 , V_140 , 0x5A ,
V_141 | V_142 ) ;
if ( V_28 < 0 )
break;
} else if ( V_130 == V_143 ) {
clock = 39000000 ;
V_131 = V_144 ;
V_28 = F_18 ( V_7 , V_140 , 0x5A ,
V_145 | V_146 |
V_147 ) ;
if ( V_28 < 0 )
break;
} else {
V_28 = - V_137 ;
break;
}
V_28 = F_42 ( V_7 , clock ,
V_131 , false , true , false ) ;
if ( V_28 < 0 ) {
F_11 ( F_1 ( V_3 ) , L_13 ) ;
break;
}
V_3 -> V_131 = V_131 ;
V_3 -> clock = clock ;
V_3 -> V_104 = V_130 ;
break;
default:
V_28 = - V_137 ;
break;
}
V_132:
F_35 ( & V_7 -> V_125 ) ;
F_36 ( F_1 ( V_3 ) ) ;
if ( V_129 == V_133 && V_130 == V_135 )
F_19 ( 10000 , 12000 ) ;
F_11 ( F_1 ( V_3 ) , L_14 , V_29 , V_28 ) ;
return V_28 ;
}
static int F_43 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_44 ( V_5 ) ;
struct V_123 * V_54 = V_3 -> V_54 ;
F_11 ( F_1 ( V_3 ) , L_11 , V_29 ) ;
F_45 ( V_54 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = F_44 ( V_5 ) ;
struct V_123 * V_54 = V_3 -> V_54 ;
F_11 ( F_1 ( V_3 ) , L_11 , V_29 ) ;
F_47 ( V_54 ) ;
return 0 ;
}
static int F_48 ( void * V_148 )
{
struct V_2 * V_3 = (struct V_2 * ) V_148 ;
struct V_6 * V_7 = V_3 -> V_7 ;
T_2 V_99 = 0 ;
int V_28 ;
for (; ; ) {
F_31 ( F_1 ( V_3 ) ) ;
F_33 ( & V_7 -> V_125 ) ;
V_28 = F_49 ( V_7 , V_149 , & V_99 ) ;
if ( V_28 ) {
F_35 ( & V_7 -> V_125 ) ;
goto V_150;
}
F_18 ( V_7 , V_149 ,
V_151 | V_152 | V_153 ,
V_151 | V_152 | V_153 ) ;
F_35 ( & V_7 -> V_125 ) ;
if ( V_99 & V_152 ) {
F_11 ( F_1 ( V_3 ) , L_15 ) ;
F_50 ( V_3 -> V_54 ) ;
}
V_150:
F_36 ( F_1 ( V_3 ) ) ;
if ( V_3 -> V_127 )
break;
F_51 ( V_154 ) ;
}
F_52 ( & V_3 -> V_155 ) ;
return 0 ;
}
static int F_53 ( struct V_156 * V_4 )
{
struct V_123 * V_54 ;
struct V_2 * V_3 ;
struct V_6 * V_7 ;
int V_28 ;
V_7 = F_54 ( F_55 ( V_4 -> V_5 . V_157 ) ) ;
if ( ! V_7 )
return - V_158 ;
F_11 ( & ( V_4 -> V_5 ) ,
L_16 ) ;
V_54 = F_56 ( sizeof( * V_3 ) , & V_4 -> V_5 ) ;
if ( ! V_54 )
return - V_159 ;
V_3 = F_38 ( V_54 ) ;
V_3 -> V_7 = V_7 ;
V_3 -> V_54 = V_54 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_134 = V_136 ;
F_57 ( V_4 , V_3 ) ;
F_58 ( & V_3 -> V_160 ) ;
F_59 ( & V_3 -> V_122 , F_29 ) ;
F_60 ( & V_3 -> V_155 ) ;
V_3 -> V_161 = F_61 ( F_48 , V_3 ,
L_17 , V_4 -> V_58 ) ;
if ( F_62 ( V_3 -> V_161 ) ) {
F_11 ( & ( V_4 -> V_5 ) ,
L_18 ) ;
V_28 = F_63 ( V_3 -> V_161 ) ;
goto V_87;
}
V_54 -> V_162 = F_37 ;
V_54 -> V_163 = F_40 ;
V_54 -> V_164 = V_165 ;
F_64 ( & V_4 -> V_5 ) ;
V_28 = F_65 ( V_54 ) ;
if ( V_28 )
goto V_87;
F_66 ( V_3 -> V_161 ) ;
return 0 ;
V_87:
F_67 ( V_54 ) ;
return V_28 ;
}
static int F_68 ( struct V_156 * V_4 )
{
struct V_2 * V_3 = F_69 ( V_4 ) ;
struct V_123 * V_54 ;
int V_28 ;
V_54 = V_3 -> V_54 ;
V_3 -> V_127 = true ;
F_70 ( & V_3 -> V_122 ) ;
F_33 ( & V_3 -> V_160 ) ;
if ( V_3 -> V_107 ) {
F_11 ( & ( V_4 -> V_5 ) ,
L_19 ,
F_71 ( & V_54 -> V_5 ) ) ;
V_3 -> V_107 -> error = - V_166 ;
do {
V_28 = F_32 ( V_54 , & V_3 -> V_107 ) ;
if ( ! V_28 )
V_3 -> V_107 -> error = - V_166 ;
} while ( ! V_28 );
}
F_35 ( & V_3 -> V_160 ) ;
F_72 ( & V_3 -> V_155 ) ;
F_73 ( V_54 ) ;
F_67 ( V_54 ) ;
if ( F_74 ( F_1 ( V_3 ) ) )
F_36 ( F_1 ( V_3 ) ) ;
F_75 ( & V_4 -> V_5 ) ;
F_57 ( V_4 , NULL ) ;
F_11 ( & ( V_4 -> V_5 ) ,
L_20 ) ;
return 0 ;
}
