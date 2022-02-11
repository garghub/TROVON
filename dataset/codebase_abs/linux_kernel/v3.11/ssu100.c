static inline int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 V_5 )
{
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
V_3 , 0x40 , V_4 , V_5 ,
NULL , 0 , 300 ) ;
}
static inline int F_4 ( struct V_1 * V_2 , T_1 * V_4 )
{
T_2 V_6 = ( ( T_2 ) ( V_4 [ 1 ] << 8 ) | ( T_2 ) ( V_4 [ 0 ] ) ) ;
return F_1 ( V_2 , V_7 , V_6 , 0 ) ;
}
static inline int F_5 ( struct V_1 * V_2 , T_1 * V_4 )
{
return F_2 ( V_2 , F_6 ( V_2 , 0 ) ,
V_7 , 0xc0 , 0 , 0 ,
V_4 , 3 , 300 ) ;
}
static inline int F_7 ( struct V_1 * V_2 ,
unsigned short V_8 ,
unsigned short V_9 ,
T_1 * V_4 )
{
return F_2 ( V_2 , F_6 ( V_2 , 0 ) ,
V_10 , 0xc0 , V_9 ,
V_8 , V_4 , sizeof( * V_4 ) , 300 ) ;
}
static inline int F_8 ( struct V_1 * V_2 ,
unsigned short V_8 ,
unsigned short V_9 ,
T_2 V_4 )
{
T_2 V_11 = ( V_4 << 8 ) | V_9 ;
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
V_10 , 0x40 , V_11 , V_8 ,
NULL , 0 , 300 ) ;
}
static inline int F_9 ( struct V_1 * V_2 , unsigned int V_12 ,
unsigned int V_13 )
{
unsigned V_14 ;
int V_15 ;
if ( ( ( V_12 | V_13 ) & ( V_16 | V_17 ) ) == 0 ) {
F_10 ( & V_2 -> V_2 , L_1 , V_18 ) ;
return 0 ;
}
V_13 &= ~ V_12 ;
V_14 = 0 ;
if ( V_12 & V_16 )
V_14 |= V_19 ;
if ( V_12 & V_17 )
V_14 |= V_20 ;
V_15 = F_8 ( V_2 , 0 , V_21 , V_14 ) ;
if ( V_15 < 0 )
F_10 ( & V_2 -> V_2 , L_2 , V_18 ) ;
return V_15 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 * V_4 ;
int V_15 = 0 ;
V_4 = F_12 ( 3 , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_15 = F_5 ( V_2 , V_4 ) ;
if ( V_15 < 0 ) {
F_10 ( & V_2 -> V_2 , L_3 , V_18 , V_15 ) ;
goto V_24;
}
V_4 [ 1 ] &= ~ V_25 ;
V_15 = F_4 ( V_2 , V_4 ) ;
if ( V_15 < 0 ) {
F_10 ( & V_2 -> V_2 , L_4 , V_18 , V_15 ) ;
goto V_24;
}
V_15 = F_1 ( V_2 , V_26 , 128 , 0 ) ;
if ( V_15 < 0 ) {
F_10 ( & V_2 -> V_2 , L_5 , V_18 , V_15 ) ;
goto V_24;
}
V_15 = F_1 ( V_2 , V_27 , V_28 , 0 ) ;
if ( V_15 < 0 ) {
F_10 ( & V_2 -> V_2 , L_6 , V_18 , V_15 ) ;
goto V_24;
}
V_15 = F_5 ( V_2 , V_4 ) ;
if ( V_15 < 0 ) {
F_10 ( & V_2 -> V_2 , L_3 , V_18 , V_15 ) ;
goto V_24;
}
V_4 [ 0 ] &= ~ ( V_29 | V_30 ) ;
V_4 [ 0 ] |= V_31 ;
V_4 [ 1 ] &= ~ ( V_32 ) ;
V_4 [ 1 ] |= V_33 ;
V_15 = F_4 ( V_2 , V_4 ) ;
if ( V_15 < 0 ) {
F_10 ( & V_2 -> V_2 , L_4 , V_18 , V_15 ) ;
goto V_24;
}
V_24: F_13 ( V_4 ) ;
return V_15 ;
}
static void F_14 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_37 -> V_40 -> V_2 ;
struct V_38 * V_41 = & V_35 -> V_41 ;
T_2 V_42 , V_43 , V_44 ;
unsigned int V_45 = V_41 -> V_46 ;
T_2 V_14 = 0 ;
int V_15 ;
if ( V_45 & V_47 ) {
if ( V_45 & V_48 )
V_14 |= V_49 ;
else
V_14 |= V_50 ;
}
switch ( V_45 & V_51 ) {
case V_52 :
V_14 |= V_53 ;
break;
case V_54 :
V_14 |= V_55 ;
break;
case V_56 :
V_14 |= V_57 ;
break;
default:
case V_58 :
V_14 |= V_59 ;
break;
}
V_42 = F_15 ( V_35 ) ;
if ( ! V_42 )
V_42 = 9600 ;
F_10 ( & V_37 -> V_2 , L_7 , V_18 , V_42 ) ;
V_43 = V_60 / V_42 ;
V_44 = V_60 % V_42 ;
if ( ( ( V_44 * 2 ) >= V_42 ) && ( V_42 != 110 ) )
V_43 ++ ;
V_14 = V_14 << 8 ;
V_15 = F_1 ( V_2 , V_61 , V_43 , V_14 ) ;
if ( V_15 < 0 )
F_10 ( & V_37 -> V_2 , L_8 , V_18 ) ;
if ( V_45 & V_62 )
V_15 = F_1 ( V_2 , V_63 ,
V_64 , 0 ) ;
else
V_15 = F_1 ( V_2 , V_63 ,
0 , 0 ) ;
if ( V_15 < 0 )
F_10 ( & V_37 -> V_2 , L_9 , V_18 ) ;
if ( F_16 ( V_35 ) || F_17 ( V_35 ) ) {
T_2 V_6 = ( ( T_2 ) ( F_18 ( V_35 ) << 8 ) | ( T_2 ) ( F_19 ( V_35 ) ) ) ;
V_15 = F_1 ( V_2 , V_65 ,
V_6 , 0 ) ;
} else
V_15 = F_1 ( V_2 , V_65 ,
0 , 0 ) ;
if ( V_15 < 0 )
F_10 ( & V_37 -> V_2 , L_10 , V_18 ) ;
}
static int F_20 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_40 -> V_2 ;
struct V_66 * V_67 = F_21 ( V_37 ) ;
T_1 * V_4 ;
int V_15 ;
unsigned long V_68 ;
V_4 = F_12 ( 2 , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_15 = F_2 ( V_2 , F_6 ( V_2 , 0 ) ,
V_69 ,
V_70 , 0x01 ,
0 , V_4 , 2 , 300 ) ;
if ( V_15 < 0 ) {
F_10 ( & V_37 -> V_2 , L_11 , V_18 , V_15 ) ;
F_13 ( V_4 ) ;
return V_15 ;
}
F_22 ( & V_67 -> V_71 , V_68 ) ;
V_67 -> V_72 = V_4 [ 0 ] ;
V_67 -> V_73 = V_4 [ 1 ] ;
F_23 ( & V_67 -> V_71 , V_68 ) ;
F_13 ( V_4 ) ;
V_15 = F_1 ( V_2 , V_61 , 0x30 , 0x0300 ) ;
if ( V_15 < 0 )
F_10 ( & V_37 -> V_2 , L_8 , V_18 ) ;
if ( V_35 )
F_14 ( V_35 , V_37 , & V_35 -> V_41 ) ;
return F_24 ( V_35 , V_37 ) ;
}
static int F_25 ( struct V_36 * V_37 ,
struct V_74 T_3 * V_75 )
{
struct V_74 V_76 ;
if ( ! V_75 )
return - V_77 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . line = V_37 -> V_78 ;
V_76 . V_37 = 0 ;
V_76 . V_79 = 0 ;
V_76 . V_68 = V_80 | V_81 ;
V_76 . V_82 = V_37 -> V_83 ;
V_76 . V_84 = 9600 ;
V_76 . V_85 = 5 * V_86 ;
V_76 . V_87 = 30 * V_86 ;
if ( F_26 ( V_75 , & V_76 , sizeof( * V_75 ) ) )
return - V_77 ;
return 0 ;
}
static int F_27 ( struct V_34 * V_35 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_36 * V_37 = V_35 -> V_90 ;
F_10 ( & V_37 -> V_2 , L_12 , V_18 , V_88 ) ;
switch ( V_88 ) {
case V_91 :
return F_25 ( V_37 ,
(struct V_74 T_3 * ) V_89 ) ;
default:
break;
}
F_10 ( & V_37 -> V_2 , L_13 , V_18 ) ;
return - V_92 ;
}
static int F_28 ( struct V_93 * V_40 )
{
return F_11 ( V_40 -> V_2 ) ;
}
static int F_29 ( struct V_36 * V_37 )
{
struct V_66 * V_67 ;
V_67 = F_12 ( sizeof( * V_67 ) , V_22 ) ;
if ( ! V_67 )
return - V_23 ;
F_30 ( & V_67 -> V_71 ) ;
F_31 ( V_37 , V_67 ) ;
return 0 ;
}
static int F_32 ( struct V_36 * V_37 )
{
struct V_66 * V_67 ;
V_67 = F_21 ( V_37 ) ;
F_13 ( V_67 ) ;
return 0 ;
}
static int F_33 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_90 ;
struct V_1 * V_2 = V_37 -> V_40 -> V_2 ;
T_1 * V_94 ;
int V_95 ;
V_94 = F_12 ( 2 , V_22 ) ;
if ( ! V_94 )
return - V_23 ;
V_95 = F_7 ( V_2 , 0 , V_21 , V_94 ) ;
if ( V_95 < 0 )
goto V_96;
V_95 = F_7 ( V_2 , 0 , V_97 , V_94 + 1 ) ;
if ( V_95 < 0 )
goto V_96;
V_95 = ( V_94 [ 0 ] & V_19 ? V_16 : 0 ) |
( V_94 [ 0 ] & V_20 ? V_17 : 0 ) |
( V_94 [ 1 ] & V_98 ? V_99 : 0 ) |
( V_94 [ 1 ] & V_100 ? V_101 : 0 ) |
( V_94 [ 1 ] & V_102 ? V_103 : 0 ) |
( V_94 [ 1 ] & V_104 ? V_105 : 0 ) ;
V_96:
F_13 ( V_94 ) ;
return V_95 ;
}
static int F_34 ( struct V_34 * V_35 ,
unsigned int V_12 , unsigned int V_13 )
{
struct V_36 * V_37 = V_35 -> V_90 ;
struct V_1 * V_2 = V_37 -> V_40 -> V_2 ;
return F_9 ( V_2 , V_12 , V_13 ) ;
}
static void F_35 ( struct V_36 * V_37 , int V_106 )
{
struct V_1 * V_2 = V_37 -> V_40 -> V_2 ;
if ( ! V_106 ) {
if ( F_8 ( V_2 , 0 , V_21 , 0 ) < 0 )
F_36 ( & V_37 -> V_2 , L_14 ) ;
}
if ( V_106 )
F_37 ( V_2 , V_16 | V_17 ) ;
else
F_38 ( V_2 , V_16 | V_17 ) ;
}
static void F_39 ( struct V_36 * V_37 , T_1 V_107 )
{
struct V_66 * V_67 = F_21 ( V_37 ) ;
unsigned long V_68 ;
F_22 ( & V_67 -> V_71 , V_68 ) ;
V_67 -> V_73 = V_107 ;
F_23 ( & V_67 -> V_71 , V_68 ) ;
if ( V_107 & V_108 ) {
if ( V_107 & V_109 )
V_37 -> V_110 . V_111 ++ ;
if ( V_107 & V_112 )
V_37 -> V_110 . V_113 ++ ;
if ( V_107 & V_114 )
V_37 -> V_110 . V_115 ++ ;
if ( V_107 & V_116 )
V_37 -> V_110 . V_117 ++ ;
F_40 ( & V_37 -> V_37 . V_118 ) ;
}
}
static void F_41 ( struct V_36 * V_37 , T_1 V_119 ,
char * V_120 )
{
struct V_66 * V_67 = F_21 ( V_37 ) ;
unsigned long V_68 ;
F_22 ( & V_67 -> V_71 , V_68 ) ;
V_67 -> V_72 = V_119 ;
F_23 ( & V_67 -> V_71 , V_68 ) ;
* V_120 = V_121 ;
if ( V_119 & V_122 ) {
if ( V_119 & V_123 ) {
V_37 -> V_110 . V_124 ++ ;
* V_120 = V_125 ;
F_42 ( V_37 ) ;
}
if ( V_119 & V_126 ) {
V_37 -> V_110 . V_127 ++ ;
if ( * V_120 == V_121 )
* V_120 = V_128 ;
}
if ( V_119 & V_129 ) {
V_37 -> V_110 . V_130 ++ ;
if ( * V_120 == V_121 )
* V_120 = V_131 ;
}
if ( V_119 & V_132 ) {
V_37 -> V_110 . V_133 ++ ;
if ( * V_120 == V_121 )
* V_120 = V_134 ;
}
}
}
static void F_43 ( struct V_135 * V_135 )
{
struct V_36 * V_37 = V_135 -> V_136 ;
char * V_137 = ( char * ) V_135 -> V_138 ;
char V_139 = V_121 ;
T_4 V_140 = V_135 -> V_141 ;
int V_142 ;
char * V_143 ;
if ( ( V_140 >= 4 ) &&
( V_137 [ 0 ] == 0x1b ) && ( V_137 [ 1 ] == 0x1b ) &&
( ( V_137 [ 2 ] == 0x00 ) || ( V_137 [ 2 ] == 0x01 ) ) ) {
if ( V_137 [ 2 ] == 0x00 ) {
F_41 ( V_37 , V_137 [ 3 ] , & V_139 ) ;
if ( V_139 == V_134 )
F_44 ( & V_37 -> V_37 , 0 ,
V_134 ) ;
}
if ( V_137 [ 2 ] == 0x01 )
F_39 ( V_37 , V_137 [ 3 ] ) ;
V_140 -= 4 ;
V_143 = V_137 + 4 ;
} else
V_143 = V_137 ;
if ( ! V_140 )
return;
if ( V_37 -> V_37 . V_144 && V_37 -> V_145 ) {
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ , V_143 ++ ) {
if ( ! F_45 ( V_37 , * V_143 ) )
F_44 ( & V_37 -> V_37 , * V_143 , V_139 ) ;
}
} else
F_46 ( & V_37 -> V_37 , V_143 , V_139 , V_140 ) ;
F_47 ( & V_37 -> V_37 ) ;
}
