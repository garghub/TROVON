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
int V_8 ;
V_8 = F_2 ( V_2 , F_6 ( V_2 , 0 ) ,
V_7 , 0xc0 , 0 , 0 ,
V_4 , 3 , 300 ) ;
if ( V_8 < 3 ) {
if ( V_8 >= 0 )
V_8 = - V_9 ;
}
return V_8 ;
}
static inline int F_7 ( struct V_1 * V_2 ,
unsigned short V_10 ,
unsigned short V_11 ,
T_1 * V_4 )
{
int V_8 ;
V_8 = F_2 ( V_2 , F_6 ( V_2 , 0 ) ,
V_12 , 0xc0 , V_11 ,
V_10 , V_4 , sizeof( * V_4 ) , 300 ) ;
if ( V_8 < sizeof( * V_4 ) ) {
if ( V_8 >= 0 )
V_8 = - V_9 ;
}
return V_8 ;
}
static inline int F_8 ( struct V_1 * V_2 ,
unsigned short V_10 ,
unsigned short V_11 ,
T_2 V_4 )
{
T_2 V_13 = ( V_4 << 8 ) | V_11 ;
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
V_12 , 0x40 , V_13 , V_10 ,
NULL , 0 , 300 ) ;
}
static inline int F_9 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 )
{
unsigned V_16 ;
int V_17 ;
if ( ( ( V_14 | V_15 ) & ( V_18 | V_19 ) ) == 0 ) {
F_10 ( & V_2 -> V_2 , L_1 , V_20 ) ;
return 0 ;
}
V_15 &= ~ V_14 ;
V_16 = 0 ;
if ( V_14 & V_18 )
V_16 |= V_21 ;
if ( V_14 & V_19 )
V_16 |= V_22 ;
V_17 = F_8 ( V_2 , 0 , V_23 , V_16 ) ;
if ( V_17 < 0 )
F_10 ( & V_2 -> V_2 , L_2 , V_20 ) ;
return V_17 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 * V_4 ;
int V_17 = 0 ;
V_4 = F_12 ( 3 , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_17 = F_5 ( V_2 , V_4 ) ;
if ( V_17 < 0 ) {
F_10 ( & V_2 -> V_2 , L_3 , V_20 , V_17 ) ;
goto V_26;
}
V_4 [ 1 ] &= ~ V_27 ;
V_17 = F_4 ( V_2 , V_4 ) ;
if ( V_17 < 0 ) {
F_10 ( & V_2 -> V_2 , L_4 , V_20 , V_17 ) ;
goto V_26;
}
V_17 = F_1 ( V_2 , V_28 , 128 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( & V_2 -> V_2 , L_5 , V_20 , V_17 ) ;
goto V_26;
}
V_17 = F_1 ( V_2 , V_29 , V_30 , 0 ) ;
if ( V_17 < 0 ) {
F_10 ( & V_2 -> V_2 , L_6 , V_20 , V_17 ) ;
goto V_26;
}
V_17 = F_5 ( V_2 , V_4 ) ;
if ( V_17 < 0 ) {
F_10 ( & V_2 -> V_2 , L_3 , V_20 , V_17 ) ;
goto V_26;
}
V_4 [ 0 ] &= ~ ( V_31 | V_32 ) ;
V_4 [ 0 ] |= V_33 ;
V_4 [ 1 ] &= ~ ( V_34 ) ;
V_4 [ 1 ] |= V_35 ;
V_17 = F_4 ( V_2 , V_4 ) ;
if ( V_17 < 0 ) {
F_10 ( & V_2 -> V_2 , L_4 , V_20 , V_17 ) ;
goto V_26;
}
V_26: F_13 ( V_4 ) ;
return V_17 ;
}
static void F_14 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_39 -> V_42 -> V_2 ;
struct V_40 * V_43 = & V_37 -> V_43 ;
T_2 V_44 , V_45 , V_46 ;
unsigned int V_47 = V_43 -> V_48 ;
T_2 V_16 = 0 ;
int V_17 ;
if ( V_47 & V_49 ) {
if ( V_47 & V_50 )
V_16 |= V_51 ;
else
V_16 |= V_52 ;
}
switch ( V_47 & V_53 ) {
case V_54 :
V_16 |= V_55 ;
break;
case V_56 :
V_16 |= V_57 ;
break;
case V_58 :
V_16 |= V_59 ;
break;
default:
case V_60 :
V_16 |= V_61 ;
break;
}
V_44 = F_15 ( V_37 ) ;
if ( ! V_44 )
V_44 = 9600 ;
F_10 ( & V_39 -> V_2 , L_7 , V_20 , V_44 ) ;
V_45 = V_62 / V_44 ;
V_46 = V_62 % V_44 ;
if ( ( ( V_46 * 2 ) >= V_44 ) && ( V_44 != 110 ) )
V_45 ++ ;
V_16 = V_16 << 8 ;
V_17 = F_1 ( V_2 , V_63 , V_45 , V_16 ) ;
if ( V_17 < 0 )
F_10 ( & V_39 -> V_2 , L_8 , V_20 ) ;
if ( V_47 & V_64 )
V_17 = F_1 ( V_2 , V_65 ,
V_66 , 0 ) ;
else
V_17 = F_1 ( V_2 , V_65 ,
0 , 0 ) ;
if ( V_17 < 0 )
F_10 ( & V_39 -> V_2 , L_9 , V_20 ) ;
if ( F_16 ( V_37 ) || F_17 ( V_37 ) ) {
T_2 V_6 = ( ( T_2 ) ( F_18 ( V_37 ) << 8 ) | ( T_2 ) ( F_19 ( V_37 ) ) ) ;
V_17 = F_1 ( V_2 , V_67 ,
V_6 , 0 ) ;
} else
V_17 = F_1 ( V_2 , V_67 ,
0 , 0 ) ;
if ( V_17 < 0 )
F_10 ( & V_39 -> V_2 , L_10 , V_20 ) ;
}
static int F_20 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_42 -> V_2 ;
struct V_68 * V_69 = F_21 ( V_39 ) ;
T_1 * V_4 ;
int V_17 ;
unsigned long V_70 ;
V_4 = F_12 ( 2 , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_17 = F_2 ( V_2 , F_6 ( V_2 , 0 ) ,
V_71 ,
V_72 , 0x01 ,
0 , V_4 , 2 , 300 ) ;
if ( V_17 < 2 ) {
F_10 ( & V_39 -> V_2 , L_11 , V_20 , V_17 ) ;
if ( V_17 >= 0 )
V_17 = - V_9 ;
F_13 ( V_4 ) ;
return V_17 ;
}
F_22 ( & V_69 -> V_73 , V_70 ) ;
V_69 -> V_74 = V_4 [ 0 ] ;
V_69 -> V_75 = V_4 [ 1 ] ;
F_23 ( & V_69 -> V_73 , V_70 ) ;
F_13 ( V_4 ) ;
V_17 = F_1 ( V_2 , V_63 , 0x30 , 0x0300 ) ;
if ( V_17 < 0 )
F_10 ( & V_39 -> V_2 , L_8 , V_20 ) ;
if ( V_37 )
F_14 ( V_37 , V_39 , & V_37 -> V_43 ) ;
return F_24 ( V_37 , V_39 ) ;
}
static int F_25 ( struct V_38 * V_39 ,
struct V_76 T_3 * V_77 )
{
struct V_76 V_78 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . line = V_39 -> V_79 ;
V_78 . V_39 = 0 ;
V_78 . V_80 = 0 ;
V_78 . V_81 = V_39 -> V_82 ;
V_78 . V_83 = 9600 ;
V_78 . V_84 = 5 * V_85 ;
V_78 . V_86 = 30 * V_85 ;
if ( F_26 ( V_77 , & V_78 , sizeof( * V_77 ) ) )
return - V_87 ;
return 0 ;
}
static int F_27 ( struct V_36 * V_37 ,
unsigned int V_88 , unsigned long V_89 )
{
struct V_38 * V_39 = V_37 -> V_90 ;
switch ( V_88 ) {
case V_91 :
return F_25 ( V_39 ,
(struct V_76 T_3 * ) V_89 ) ;
default:
break;
}
return - V_92 ;
}
static int F_28 ( struct V_93 * V_42 )
{
return F_11 ( V_42 -> V_2 ) ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_68 * V_69 ;
V_69 = F_12 ( sizeof( * V_69 ) , V_24 ) ;
if ( ! V_69 )
return - V_25 ;
F_30 ( & V_69 -> V_73 ) ;
F_31 ( V_39 , V_69 ) ;
return 0 ;
}
static int F_32 ( struct V_38 * V_39 )
{
struct V_68 * V_69 ;
V_69 = F_21 ( V_39 ) ;
F_13 ( V_69 ) ;
return 0 ;
}
static int F_33 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_90 ;
struct V_1 * V_2 = V_39 -> V_42 -> V_2 ;
T_1 * V_94 ;
int V_95 ;
V_94 = F_12 ( 2 , V_24 ) ;
if ( ! V_94 )
return - V_25 ;
V_95 = F_7 ( V_2 , 0 , V_23 , V_94 ) ;
if ( V_95 < 0 )
goto V_96;
V_95 = F_7 ( V_2 , 0 , V_97 , V_94 + 1 ) ;
if ( V_95 < 0 )
goto V_96;
V_95 = ( V_94 [ 0 ] & V_21 ? V_18 : 0 ) |
( V_94 [ 0 ] & V_22 ? V_19 : 0 ) |
( V_94 [ 1 ] & V_98 ? V_99 : 0 ) |
( V_94 [ 1 ] & V_100 ? V_101 : 0 ) |
( V_94 [ 1 ] & V_102 ? V_103 : 0 ) |
( V_94 [ 1 ] & V_104 ? V_105 : 0 ) ;
V_96:
F_13 ( V_94 ) ;
return V_95 ;
}
static int F_34 ( struct V_36 * V_37 ,
unsigned int V_14 , unsigned int V_15 )
{
struct V_38 * V_39 = V_37 -> V_90 ;
struct V_1 * V_2 = V_39 -> V_42 -> V_2 ;
return F_9 ( V_2 , V_14 , V_15 ) ;
}
static void F_35 ( struct V_38 * V_39 , int V_106 )
{
struct V_1 * V_2 = V_39 -> V_42 -> V_2 ;
if ( ! V_106 ) {
if ( F_8 ( V_2 , 0 , V_23 , 0 ) < 0 )
F_36 ( & V_39 -> V_2 , L_12 ) ;
}
if ( V_106 )
F_37 ( V_2 , V_18 | V_19 ) ;
else
F_38 ( V_2 , V_18 | V_19 ) ;
}
static void F_39 ( struct V_38 * V_39 , T_1 V_107 )
{
struct V_68 * V_69 = F_21 ( V_39 ) ;
unsigned long V_70 ;
F_22 ( & V_69 -> V_73 , V_70 ) ;
V_69 -> V_75 = V_107 ;
F_23 ( & V_69 -> V_73 , V_70 ) ;
if ( V_107 & V_108 ) {
if ( V_107 & V_109 )
V_39 -> V_110 . V_111 ++ ;
if ( V_107 & V_112 )
V_39 -> V_110 . V_113 ++ ;
if ( V_107 & V_114 )
V_39 -> V_110 . V_115 ++ ;
if ( V_107 & V_116 )
V_39 -> V_110 . V_117 ++ ;
F_40 ( & V_39 -> V_39 . V_118 ) ;
}
}
static void F_41 ( struct V_38 * V_39 , T_1 V_119 ,
char * V_120 )
{
struct V_68 * V_69 = F_21 ( V_39 ) ;
unsigned long V_70 ;
F_22 ( & V_69 -> V_73 , V_70 ) ;
V_69 -> V_74 = V_119 ;
F_23 ( & V_69 -> V_73 , V_70 ) ;
* V_120 = V_121 ;
if ( V_119 & V_122 ) {
if ( V_119 & V_123 ) {
V_39 -> V_110 . V_124 ++ ;
* V_120 = V_125 ;
F_42 ( V_39 ) ;
}
if ( V_119 & V_126 ) {
V_39 -> V_110 . V_127 ++ ;
if ( * V_120 == V_121 )
* V_120 = V_128 ;
}
if ( V_119 & V_129 ) {
V_39 -> V_110 . V_130 ++ ;
if ( * V_120 == V_121 )
* V_120 = V_131 ;
}
if ( V_119 & V_132 ) {
V_39 -> V_110 . V_133 ++ ;
F_43 ( & V_39 -> V_39 , 0 , V_134 ) ;
}
}
}
static void F_44 ( struct V_135 * V_135 )
{
struct V_38 * V_39 = V_135 -> V_136 ;
char * V_137 = ( char * ) V_135 -> V_138 ;
char V_139 = V_121 ;
T_4 V_140 = V_135 -> V_141 ;
int V_142 ;
char * V_143 ;
if ( ( V_140 >= 4 ) &&
( V_137 [ 0 ] == 0x1b ) && ( V_137 [ 1 ] == 0x1b ) &&
( ( V_137 [ 2 ] == 0x00 ) || ( V_137 [ 2 ] == 0x01 ) ) ) {
if ( V_137 [ 2 ] == 0x00 )
F_41 ( V_39 , V_137 [ 3 ] , & V_139 ) ;
if ( V_137 [ 2 ] == 0x01 )
F_39 ( V_39 , V_137 [ 3 ] ) ;
V_140 -= 4 ;
V_143 = V_137 + 4 ;
} else
V_143 = V_137 ;
if ( ! V_140 )
return;
if ( V_39 -> V_39 . V_144 && V_39 -> V_145 ) {
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ , V_143 ++ ) {
if ( ! F_45 ( V_39 , * V_143 ) )
F_43 ( & V_39 -> V_39 , * V_143 , V_139 ) ;
}
} else
F_46 ( & V_39 -> V_39 , V_143 , V_139 , V_140 ) ;
F_47 ( & V_39 -> V_39 ) ;
}
