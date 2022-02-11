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
F_9 ( F_1 ( V_3 ) , L_2 ,
V_36 , V_27 , ( V_26 == V_37 ) ? L_3 : L_4 ,
V_31 ) ;
if ( V_26 == V_37 ) {
V_35 = V_38 ;
V_34 = V_39 ;
} else {
V_35 = V_40 ;
V_34 = V_41 ;
}
F_5 ( V_6 ) ;
F_6 ( V_6 , V_15 , V_42 , 0xFF , V_27 ) ;
F_6 ( V_6 , V_15 , V_43 ,
0xFF , ( T_2 ) ( V_32 >> 8 ) ) ;
F_6 ( V_6 , V_15 , V_44 ,
0xFF , ( T_2 ) V_32 ) ;
F_6 ( V_6 , V_15 , V_45 , 0xFF , V_28 ) ;
F_6 ( V_6 , V_15 , V_46 ,
V_47 , V_47 ) ;
F_6 ( V_6 , V_15 , V_48 , 0xFF , ( T_2 ) ( V_31 >> 24 ) ) ;
F_6 ( V_6 , V_15 , V_49 , 0xFF , ( T_2 ) ( V_31 >> 16 ) ) ;
F_6 ( V_6 , V_15 , V_50 , 0xFF , ( T_2 ) ( V_31 >> 8 ) ) ;
F_6 ( V_6 , V_15 , V_51 , 0xFF , ( T_2 ) V_31 ) ;
F_6 ( V_6 , V_15 , V_52 ,
0x03 | V_53 , V_35 | V_54 | V_55 ) ;
F_6 ( V_6 , V_15 , V_56 ,
0x01 , V_57 ) ;
F_6 ( V_6 , V_15 , V_58 ,
0xFF , V_59 | V_34 ) ;
F_6 ( V_6 , V_60 , V_58 ,
V_61 , V_61 ) ;
F_18 ( V_6 ) ;
V_14 = F_19 ( V_6 , V_30 , 1 , V_26 == V_37 , 10000 ) ;
if ( V_14 < 0 ) {
F_2 ( V_3 ) ;
return V_14 ;
}
F_20 ( V_6 , V_45 , & V_33 ) ;
if ( V_33 & ( V_62 | V_63 | V_64 | V_65 ) )
return - V_66 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_27 ,
T_2 V_28 , T_2 V_67 , T_2 * V_68 , T_2 * V_69 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_14 , V_11 ;
F_9 ( F_1 ( V_3 ) , L_5 , V_36 , V_27 ) ;
if ( ! V_68 )
return - V_70 ;
F_5 ( V_6 ) ;
for ( V_11 = 0 ; V_11 < V_67 ; V_11 ++ )
F_6 ( V_6 , V_15 ,
V_71 + V_11 , 0xFF , V_68 [ V_11 ] ) ;
if ( V_67 % 2 )
F_6 ( V_6 , V_15 ,
V_71 + V_11 , 0xFF , 0xFF ) ;
F_6 ( V_6 , V_15 , V_42 , 0xFF , V_27 ) ;
F_6 ( V_6 , V_15 , V_72 , 0xFF , V_67 ) ;
F_6 ( V_6 , V_15 , V_45 , 0xFF , V_28 ) ;
F_6 ( V_6 , V_15 , V_56 ,
0x01 , V_73 ) ;
F_6 ( V_6 , V_15 , V_58 ,
0xFF , V_59 | V_74 ) ;
F_6 ( V_6 , V_60 , V_58 ,
V_61 , V_61 ) ;
if ( V_69 )
F_6 ( V_6 , V_13 , V_45 , 0 , 0 ) ;
V_14 = F_7 ( V_6 , 5000 ) ;
if ( V_14 < 0 ) {
T_2 V_33 ;
F_20 ( V_6 , V_45 , & V_33 ) ;
F_9 ( F_1 ( V_3 ) , L_6 , V_33 ) ;
if ( V_69 )
* V_69 = V_33 & 0x0F ;
F_4 ( V_3 ) ;
F_2 ( V_3 ) ;
if ( ! ( V_27 & 0x08 ) ) {
if ( V_33 & V_64 )
return - V_66 ;
} else {
if ( ! ( V_33 & 0x80 ) ) {
if ( V_33 & ( V_63 | V_62 ) )
return - V_66 ;
}
}
return - V_75 ;
}
if ( V_69 ) {
T_2 * V_12 = F_8 ( V_6 ) + 1 ;
* V_69 = * V_12 & 0x0F ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , T_2 V_27 ,
T_2 V_28 , T_2 V_67 , T_2 * V_68 , T_2 * V_69 )
{
struct V_10 * V_6 = V_3 -> V_6 ;
int V_14 , V_11 ;
T_2 * V_12 ;
F_9 ( F_1 ( V_3 ) , L_5 , V_36 , V_27 ) ;
if ( ! V_68 )
return - V_70 ;
F_5 ( V_6 ) ;
F_6 ( V_6 , V_15 , V_42 , 0xFF , V_27 ) ;
F_6 ( V_6 , V_15 , V_72 , 0xFF , V_67 ) ;
F_6 ( V_6 , V_15 , V_45 , 0xFF , V_28 ) ;
F_6 ( V_6 , V_15 , V_56 ,
0x01 , V_73 ) ;
F_6 ( V_6 , V_15 , V_58 ,
0xFF , V_59 | V_76 ) ;
F_6 ( V_6 , V_60 , V_58 ,
V_61 , V_61 ) ;
for ( V_11 = 0 ; V_11 < V_67 - 1 ; V_11 ++ )
F_6 ( V_6 , V_13 , V_71 + V_11 , 0 , 0 ) ;
if ( V_67 % 2 )
F_6 ( V_6 , V_13 , V_71 + V_67 , 0 , 0 ) ;
else
F_6 ( V_6 , V_13 ,
V_71 + V_67 - 1 , 0 , 0 ) ;
if ( V_69 )
F_6 ( V_6 , V_13 , V_45 , 0 , 0 ) ;
V_14 = F_7 ( V_6 , 5000 ) ;
if ( V_14 < 0 ) {
T_2 V_33 ;
F_20 ( V_6 , V_45 , & V_33 ) ;
F_9 ( F_1 ( V_3 ) , L_6 , V_33 ) ;
if ( V_69 )
* V_69 = V_33 & 0x0F ;
F_4 ( V_3 ) ;
F_2 ( V_3 ) ;
if ( ! ( V_27 & 0x08 ) ) {
if ( V_33 & V_64 )
return - V_66 ;
} else {
if ( ! ( V_33 & 0x80 ) ) {
if ( V_33 & ( V_63 | V_62 ) )
return - V_66 ;
}
}
return - V_75 ;
}
V_12 = F_8 ( V_6 ) + 1 ;
for ( V_11 = 0 ; V_11 < V_67 ; V_11 ++ )
V_68 [ V_11 ] = * V_12 ++ ;
if ( V_69 )
* V_69 = * V_12 & 0x0F ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_77 * V_78 = V_3 -> V_78 ;
int V_14 = 0 ;
T_2 V_28 = 0 , V_69 ;
F_9 ( F_1 ( V_3 ) , L_7 , V_36 ) ;
if ( V_78 -> V_79 ) {
if ( V_3 -> V_80 != V_81 )
V_28 = V_82 ;
}
if ( V_78 -> V_83 ) {
V_14 = F_17 ( V_3 , V_78 -> V_26 ,
V_78 -> V_27 , V_28 , & ( V_78 -> V_30 ) ) ;
} else {
if ( V_78 -> V_26 == V_37 ) {
V_14 = F_22 ( V_3 , V_78 -> V_27 , V_28 ,
V_78 -> V_84 , V_78 -> V_68 , & V_69 ) ;
} else {
V_14 = F_21 ( V_3 , V_78 -> V_27 , V_28 ,
V_78 -> V_84 , V_78 -> V_68 , & V_69 ) ;
}
}
if ( V_14 < 0 )
return V_14 ;
if ( V_78 -> V_79 && ( V_3 -> V_80 == V_81 ) ) {
V_14 = F_22 ( V_3 , V_85 ,
V_86 , 1 , & V_69 , NULL ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_78 -> V_79 ) {
F_9 ( F_1 ( V_3 ) , L_8 , V_69 ) ;
if ( V_69 & V_62 )
V_78 -> V_69 |= V_87 ;
if ( V_69 & V_88 )
V_78 -> V_69 |= V_89 ;
if ( V_69 & V_63 )
V_78 -> V_69 |= V_90 ;
if ( V_69 & V_91 )
V_78 -> V_69 |= V_92 ;
}
return 0 ;
}
static void F_24 ( struct V_93 * V_94 )
{
struct V_2 * V_3 = F_25 ( V_94 ,
struct V_2 , V_95 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
struct V_96 * V_97 = V_3 -> V_97 ;
int V_98 ;
F_26 ( & V_6 -> V_99 ) ;
F_27 ( V_6 ) ;
F_28 ( V_3 -> V_6 , V_3 -> clock , V_3 -> V_100 ,
false , true , false ) ;
F_3 ( V_6 , V_16 , 0x07 , V_17 ) ;
F_3 ( V_6 , V_18 ,
V_19 , V_20 ) ;
if ( ! V_3 -> V_78 ) {
do {
V_98 = F_29 ( V_97 , & V_3 -> V_78 ) ;
F_9 ( F_1 ( V_3 ) , L_9 , V_98 ) ;
if ( ! V_98 )
V_3 -> V_78 -> error = F_23 ( V_3 ) ;
} while ( ! V_98 );
}
F_30 ( & V_6 -> V_99 ) ;
}
static void F_31 ( struct V_96 * V_97 )
{
struct V_2 * V_3 = F_32 ( V_97 ) ;
F_9 ( F_1 ( V_3 ) , L_10 , V_36 ) ;
if ( F_33 ( V_3 -> V_6 , V_23 ) )
return;
F_34 ( & V_3 -> V_95 ) ;
}
static int F_35 ( struct V_96 * V_97 ,
enum V_101 V_102 , int V_103 )
{
struct V_2 * V_3 = F_32 ( V_97 ) ;
struct V_10 * V_6 = V_3 -> V_6 ;
unsigned int clock = 0 ;
T_2 V_100 = 0 ;
int V_14 ;
F_9 ( F_1 ( V_3 ) , L_11 ,
V_36 , V_102 , V_103 ) ;
V_14 = F_33 ( V_3 -> V_6 , V_23 ) ;
if ( V_14 )
return V_14 ;
switch ( V_102 ) {
case V_104 :
if ( V_103 == V_105 )
V_14 = F_10 ( V_3 ) ;
else if ( V_103 == V_106 )
V_14 = F_14 ( V_3 ) ;
else
return - V_70 ;
break;
case V_107 :
if ( V_103 == V_81 ) {
clock = 19000000 ;
V_100 = V_108 ;
V_14 = F_3 ( V_6 , V_109 ,
0x18 , V_110 ) ;
if ( V_14 < 0 )
return V_14 ;
} else if ( V_103 == V_111 ) {
clock = 39000000 ;
V_100 = V_112 ;
V_14 = F_3 ( V_6 , V_109 ,
0x58 , V_113 | V_114 ) ;
if ( V_14 < 0 )
return V_14 ;
} else {
return - V_70 ;
}
V_14 = F_28 ( V_6 , clock ,
V_100 , false , true , false ) ;
if ( V_14 < 0 )
return V_14 ;
V_3 -> V_100 = V_100 ;
V_3 -> clock = clock ;
V_3 -> V_80 = V_103 ;
break;
}
return 0 ;
}
static int F_36 ( struct V_115 * V_4 , T_3 V_116 )
{
struct V_2 * V_3 = F_37 ( V_4 ) ;
struct V_96 * V_97 = V_3 -> V_97 ;
F_9 ( F_1 ( V_3 ) , L_10 , V_36 ) ;
F_38 ( V_97 ) ;
return 0 ;
}
static int F_39 ( struct V_115 * V_4 )
{
struct V_2 * V_3 = F_37 ( V_4 ) ;
struct V_96 * V_97 = V_3 -> V_97 ;
F_9 ( F_1 ( V_3 ) , L_10 , V_36 ) ;
F_40 ( V_97 ) ;
return 0 ;
}
static void F_41 ( struct V_115 * V_4 )
{
struct V_2 * V_3 = F_37 ( V_4 ) ;
F_42 ( V_3 -> V_97 ) ;
}
static int F_43 ( struct V_115 * V_4 )
{
struct V_96 * V_97 ;
struct V_2 * V_3 ;
struct V_10 * V_6 ;
struct V_117 * V_118 = V_4 -> V_5 . V_119 ;
int V_98 ;
if ( ! V_118 )
return - V_120 ;
V_6 = V_118 -> V_6 ;
if ( ! V_6 )
return - V_120 ;
F_9 ( & ( V_4 -> V_5 ) ,
L_12 ) ;
V_97 = F_44 ( sizeof( * V_3 ) , & V_4 -> V_5 ) ;
if ( ! V_97 )
return - V_121 ;
V_3 = F_32 ( V_97 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_97 = V_97 ;
V_3 -> V_4 = V_4 ;
F_45 ( V_4 , V_3 ) ;
V_6 -> V_122 [ V_23 ] . V_123 = V_4 ;
V_6 -> V_122 [ V_23 ] . V_124 = F_41 ;
F_46 ( & V_3 -> V_125 ) ;
F_47 ( & V_3 -> V_95 , F_24 ) ;
V_97 -> V_126 = F_31 ;
V_97 -> V_127 = F_35 ;
V_97 -> V_128 = V_129 ;
V_98 = F_48 ( V_97 ) ;
if ( V_98 ) {
F_49 ( V_97 ) ;
return V_98 ;
}
return 0 ;
}
static int F_50 ( struct V_115 * V_4 )
{
struct V_2 * V_3 = F_37 ( V_4 ) ;
struct V_10 * V_6 ;
struct V_96 * V_97 ;
int V_98 ;
if ( ! V_3 )
return 0 ;
V_6 = V_3 -> V_6 ;
V_6 -> V_122 [ V_23 ] . V_123 = NULL ;
V_6 -> V_122 [ V_23 ] . V_124 = NULL ;
V_97 = V_3 -> V_97 ;
V_3 -> V_130 = true ;
F_26 ( & V_3 -> V_125 ) ;
if ( V_3 -> V_78 ) {
F_9 ( & ( V_4 -> V_5 ) ,
L_13 ,
F_51 ( & V_97 -> V_5 ) ) ;
F_52 ( V_6 ) ;
V_3 -> V_78 -> error = - V_131 ;
do {
V_98 = F_29 ( V_97 , & V_3 -> V_78 ) ;
if ( ! V_98 )
V_3 -> V_78 -> error = - V_131 ;
} while ( ! V_98 );
}
F_30 ( & V_3 -> V_125 ) ;
F_53 ( V_97 ) ;
F_49 ( V_97 ) ;
F_45 ( V_4 , NULL ) ;
F_9 ( & ( V_4 -> V_5 ) ,
L_14 ) ;
return 0 ;
}
