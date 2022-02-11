static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_6 )
return V_3 ;
if ( V_2 -> V_7 -> V_8 -> V_9 == V_10 ) {
if ( V_3 > 4800 ) {
F_3 ( & V_2 -> V_8 ,
L_1 ,
V_11 , V_3 ) ;
return - 1 ;
}
}
switch ( V_5 -> V_12 ) {
case V_13 :
if ( V_3 <= 600 ) {
F_3 ( & V_2 -> V_8 ,
L_2 ,
V_11 , V_3 ) ;
return - 1 ;
}
break;
default:
break;
}
return V_3 ;
}
static int F_4 ( struct V_14 * V_15 ,
struct V_1 * V_2 , T_1 V_16 , int V_17 ,
int V_18 , int V_19 , int V_20 , int V_21 ,
int V_22 )
{
int V_23 = 0 , V_24 = 0 , V_25 = 0 ;
struct V_4 * V_5 ;
struct V_26 * V_8 = & V_2 -> V_8 ;
T_2 * V_27 ;
const unsigned int V_28 = 5 ;
unsigned long V_29 ;
V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_30 )
return - V_31 ;
V_27 = F_5 ( V_28 , sizeof( T_2 ) , V_32 ) ;
if ( ! V_27 )
return - V_33 ;
switch ( V_22 ) {
case V_34 :
V_23 = V_5 -> V_16 ;
if ( V_16 && V_16 != V_5 -> V_16 ) {
F_3 ( V_8 , L_3 , V_11 ) ;
V_24 = F_1 ( V_2 , V_16 ) ;
if ( V_24 >= 0 ) {
V_23 = V_24 ;
F_3 ( V_8 , L_4 ,
V_11 , V_23 ) ;
}
}
F_3 ( V_8 , L_5 , V_11 ,
V_23 ) ;
F_6 ( V_23 , V_27 ) ;
V_27 [ 4 ] |= V_17 ;
V_27 [ 4 ] |= ( V_18 << 3 ) ;
V_27 [ 4 ] |= ( V_19 << 4 ) ;
V_27 [ 4 ] |= ( V_20 << 5 ) ;
V_27 [ 4 ] |= ( V_21 << 7 ) ;
F_3 ( V_8 , L_6 , V_11 ) ;
F_3 ( V_8 , L_7 , V_11 ,
V_27 [ 0 ] , V_27 [ 1 ] ,
V_27 [ 2 ] , V_27 [ 3 ] ,
V_27 [ 4 ] ) ;
do {
V_24 = F_7 ( V_2 -> V_7 -> V_8 ,
F_8 ( V_2 -> V_7 -> V_8 , 0 ) ,
V_35 ,
V_36 | V_37 | V_38 ,
0x0300 , 0 , V_27 ,
V_28 , 500 ) ;
if ( V_25 ++ >= 3 )
break;
} while ( V_24 != V_28 &&
V_24 != - V_31 );
if ( V_24 != V_28 ) {
F_9 ( V_8 , L_8 ,
V_11 , V_24 ) ;
F_10 ( V_2 ) ;
} else {
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_5 -> V_16 = V_23 ;
V_5 -> V_40 = V_27 [ 4 ] ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
if ( V_16 )
F_13 ( V_15 ,
V_23 , V_23 ) ;
}
break;
case V_41 :
if ( V_5 -> V_42 ) {
V_24 = - V_43 ;
goto V_44;
}
F_3 ( V_8 , L_9 , V_11 ) ;
do {
V_24 = F_7 ( V_2 -> V_7 -> V_8 ,
F_14 ( V_2 -> V_7 -> V_8 , 0 ) ,
V_45 ,
V_46 | V_37 | V_38 ,
0x0300 , 0 , V_27 ,
V_28 , 500 ) ;
if ( V_25 ++ >= 3 )
break;
} while ( V_24 != V_28
&& V_24 != - V_31 );
if ( V_24 != V_28 ) {
F_9 ( V_8 , L_10 ,
V_11 , V_24 ) ;
F_10 ( V_2 ) ;
goto V_44;
} else {
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_5 -> V_40 = V_27 [ 4 ] ;
V_5 -> V_16 = F_15 ( V_27 ) ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
}
}
F_11 ( & V_5 -> V_39 , V_29 ) ;
++ V_5 -> V_47 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
V_44:
F_16 ( V_27 ) ;
return V_24 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_29 ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( ! V_5 -> V_30 ) {
F_12 ( & V_5 -> V_39 , V_29 ) ;
return;
}
V_5 -> V_30 = 0 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
F_9 ( & V_2 -> V_8 , L_11
L_12 , V_2 -> V_48 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_49 * V_7 = V_2 -> V_7 ;
struct V_4 * V_5 ;
V_5 = F_18 ( sizeof( struct V_4 ) , V_32 ) ;
if ( ! V_5 )
return - V_33 ;
V_5 -> V_30 = ! 0 ;
F_19 ( & V_5 -> V_39 ) ;
if ( F_20 ( & V_5 -> V_50 , V_51 , V_32 ) ) {
F_16 ( V_5 ) ;
return - V_33 ;
}
F_21 ( V_7 -> V_8 ) ;
V_5 -> V_52 = 0 ;
V_5 -> V_53 = 0 ;
V_5 -> V_54 = 0 ;
V_5 -> V_55 = 0 ;
if ( V_2 -> V_56 > 9 )
V_5 -> V_57 = V_58 ;
else
V_5 -> V_57 = V_59 ;
if ( V_60 > 0 ) {
V_5 -> V_61 = V_60 ;
V_5 -> V_62 = V_60 ;
F_3 ( & V_2 -> V_8 , L_13 ,
V_11 , V_60 ) ;
} else {
V_5 -> V_61 = V_2 -> V_63 -> V_60 ;
V_5 -> V_62 = V_2 -> V_64 -> V_60 ;
F_3 ( & V_2 -> V_8 , L_14 ,
V_11 , V_5 -> V_62 ,
V_5 -> V_61 ) ;
}
F_22 ( V_2 , V_5 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_49 * V_7 = V_2 -> V_7 ;
struct V_4 * V_5 ;
int V_65 ;
V_65 = F_17 ( V_2 ) ;
if ( V_65 ) {
F_3 ( & V_2 -> V_8 , L_15 , V_11 ) ;
return V_65 ;
}
V_5 = F_2 ( V_2 ) ;
V_5 -> V_12 = V_13 ;
V_5 -> V_57 = V_58 ;
if ( V_7 -> V_8 -> V_66 . V_67 !=
F_24 ( V_68 ) ) {
F_3 ( & V_2 -> V_8 ,
L_16 ,
V_11 ) ;
V_5 -> V_42 = ! 0 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_65 ;
V_65 = F_17 ( V_2 ) ;
if ( V_65 ) {
F_3 ( & V_2 -> V_8 , L_15 , V_11 ) ;
return V_65 ;
}
V_5 = F_2 ( V_2 ) ;
V_5 -> V_12 = V_69 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_65 ;
V_65 = F_17 ( V_2 ) ;
if ( V_65 ) {
F_3 ( & V_2 -> V_8 , L_15 , V_11 ) ;
return V_65 ;
}
V_5 = F_2 ( V_2 ) ;
V_5 -> V_12 = V_70 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
F_28 ( & V_5 -> V_50 ) ;
F_16 ( V_5 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_49 * V_7 = V_2 -> V_7 ;
unsigned long V_29 ;
int V_71 = 0 ;
if ( ! V_5 -> V_30 )
return - V_72 ;
F_30 ( V_7 -> V_8 , 0x81 ) ;
F_30 ( V_7 -> V_8 , 0x02 ) ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_5 -> V_73 = 0 ;
V_5 -> V_74 = 0 ;
V_5 -> V_47 = 0 ;
V_5 -> V_55 = 0 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
F_31 ( V_2 ) ;
if ( V_15 )
F_32 ( V_15 , V_2 , & V_5 -> V_75 ) ;
if ( ! V_2 -> V_64 ) {
F_9 ( & V_2 -> V_8 , L_17 ,
V_11 ) ;
return - 1 ;
}
F_33 ( V_2 -> V_64 , V_7 -> V_8 ,
F_34 ( V_7 -> V_8 , V_2 -> V_76 ) ,
V_2 -> V_64 -> V_77 ,
V_2 -> V_64 -> V_78 ,
V_79 , V_2 , V_5 -> V_62 ) ;
V_71 = F_35 ( V_2 -> V_64 , V_32 ) ;
if ( V_71 ) {
F_9 ( & V_2 -> V_8 ,
L_18 ,
V_11 , V_71 ) ;
F_10 ( V_2 ) ;
}
V_2 -> V_2 . V_80 = 256 ;
return V_71 ;
}
static void F_36 ( struct V_1 * V_2 , int V_81 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_37 ( & V_5 -> V_39 ) ;
if ( V_81 == 0 )
V_5 -> V_53 = 0 ;
else
V_5 -> V_53 = V_82 | V_83 ;
V_5 -> V_52 = 1 ;
F_38 ( & V_5 -> V_39 ) ;
F_39 ( NULL , V_2 , NULL , 0 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_29 ;
F_41 ( & V_2 -> V_7 -> V_84 ) ;
if ( V_2 -> V_7 -> V_85 ) {
F_42 ( & V_2 -> V_7 -> V_84 ) ;
return;
}
F_11 ( & V_5 -> V_39 , V_29 ) ;
F_43 ( & V_5 -> V_50 ) ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
F_3 ( & V_2 -> V_8 , L_19 , V_11 ) ;
F_44 ( V_2 -> V_64 ) ;
F_44 ( V_2 -> V_63 ) ;
if ( V_86 )
F_45 ( & V_2 -> V_8 , L_20 ,
V_5 -> V_73 , V_5 -> V_74 , V_5 -> V_47 ) ;
F_42 ( & V_2 -> V_7 -> V_84 ) ;
}
static int F_39 ( struct V_14 * V_15 , struct V_1 * V_2 ,
const unsigned char * V_87 , int V_88 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_8 , L_21 , V_11 , V_2 -> V_48 , V_88 ) ;
if ( V_5 -> V_52 ) {
V_88 = 0 ;
goto V_89;
}
if ( ! V_88 )
return V_88 ;
V_88 = F_46 ( & V_5 -> V_50 , V_87 , V_88 , & V_5 -> V_39 ) ;
V_89:
F_31 ( V_2 ) ;
return V_88 ;
}
static void F_31 ( struct V_1 * V_2 )
{
int V_88 = 0 , V_71 , V_90 , V_91 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_26 * V_8 = & V_2 -> V_8 ;
unsigned long V_29 ;
if ( ! V_5 -> V_30 )
return;
F_3 ( V_8 , L_22 , V_11 ,
V_2 -> V_56 ) ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( V_5 -> V_92 ) {
F_3 ( V_8 , L_23 , V_11 ) ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
return;
}
F_12 ( & V_5 -> V_39 , V_29 ) ;
memset ( V_2 -> V_63 -> V_77 , 0 ,
V_2 -> V_56 ) ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
switch ( V_5 -> V_57 ) {
default:
case V_58 :
V_90 = 2 ;
V_2 -> V_93 [ 0 ] = V_5 -> V_53 ;
break;
case V_59 :
V_90 = 1 ;
V_2 -> V_93 [ 0 ] = V_5 -> V_53 ;
break;
}
if ( V_5 -> V_53 & V_94 )
V_5 -> V_53 &= ~ V_94 ;
if ( V_5 -> V_52 ) {
V_5 -> V_47 ++ ;
F_3 ( V_8 , L_24 , V_11 ) ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
goto V_95;
} else
F_12 ( & V_5 -> V_39 , V_29 ) ;
V_88 = F_47 ( & V_5 -> V_50 ,
& V_2 -> V_93 [ V_90 ] ,
V_2 -> V_56 - V_90 ,
& V_5 -> V_39 ) ;
if ( V_88 == 0 )
return;
switch ( V_5 -> V_57 ) {
default:
case V_58 :
V_2 -> V_93 [ 1 ] = V_88 ;
break;
case V_59 :
V_2 -> V_93 [ 0 ] |= V_88 ;
}
F_3 ( V_8 , L_25 , V_11 , V_88 ) ;
V_95:
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_5 -> V_92 = 1 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
if ( V_5 -> V_52 )
V_91 = 1 ;
else
V_91 = V_88 +
( V_5 -> V_57 == V_58 ? 2 : 1 ) ;
F_48 ( V_8 , V_11 , V_2 -> V_56 ,
V_2 -> V_63 -> V_77 ) ;
F_33 ( V_2 -> V_63 , V_2 -> V_7 -> V_8 ,
F_49 ( V_2 -> V_7 -> V_8 , V_2 -> V_96 ) ,
V_2 -> V_93 , V_2 -> V_56 ,
V_97 , V_2 , V_5 -> V_61 ) ;
V_71 = F_35 ( V_2 -> V_63 , V_98 ) ;
if ( V_71 ) {
F_50 ( V_2 ,
L_26 ,
V_11 , V_71 ) ;
V_5 -> V_92 = 0 ;
F_10 ( V_2 ) ;
}
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( V_5 -> V_52 )
V_5 -> V_52 = 0 ;
V_5 -> V_74 += V_88 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
F_51 ( V_2 ) ;
}
static int F_52 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_100 = 0 ;
unsigned long V_29 ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_100 = F_53 ( & V_5 -> V_50 ) ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
F_3 ( & V_2 -> V_8 , L_27 , V_11 , V_100 ) ;
return V_100 ;
}
static int F_54 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_3 V_101 , V_102 ;
unsigned int V_71 = 0 ;
unsigned long V_29 ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_102 = V_5 -> V_53 ;
V_101 = V_5 -> V_103 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
V_71 = ( ( V_102 & V_82 ) ? V_104 : 0 )
| ( ( V_102 & V_83 ) ? V_105 : 0 )
| ( ( V_101 & V_106 ) ? V_107 : 0 )
| ( ( V_101 & V_108 ) ? V_109 : 0 )
| ( ( V_101 & V_110 ) ? V_111 : 0 )
| ( ( V_101 & V_112 ) ? V_113 : 0 ) ;
F_3 ( & V_2 -> V_8 , L_28 , V_11 , V_71 ) ;
return V_71 ;
}
static int F_55 ( struct V_14 * V_15 ,
unsigned int V_114 , unsigned int V_115 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_29 ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( V_114 & V_105 )
V_5 -> V_53 |= V_83 ;
if ( V_114 & V_104 )
V_5 -> V_53 |= V_82 ;
if ( V_115 & V_105 )
V_5 -> V_53 &= ~ V_83 ;
if ( V_115 & V_104 )
V_5 -> V_53 &= ~ V_82 ;
V_5 -> V_52 = 1 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
return F_39 ( V_15 , V_2 , NULL , 0 ) ;
}
static int F_56 ( struct V_14 * V_15 ,
unsigned int V_116 , unsigned long V_117 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_8 , L_29 , V_11 , V_2 -> V_48 , V_116 ) ;
switch ( V_116 ) {
case V_118 :
for (; ; ) {
F_57 ( & V_2 -> V_119 ) ;
if ( F_58 ( V_120 ) )
return - V_121 ;
if ( V_2 -> V_7 -> V_85 )
return - V_72 ;
{
char V_122 = V_5 -> V_123 ;
if ( V_122 == 0 )
return - V_72 ;
V_5 -> V_123 = 0 ;
if ( ( ( V_117 & V_124 ) && ( V_122 & V_110 ) ) ||
( ( V_117 & V_109 ) && ( V_122 & V_108 ) ) ||
( ( V_117 & V_113 ) && ( V_122 & V_112 ) ) ||
( ( V_117 & V_107 ) && ( V_122 & V_106 ) ) )
return 0 ;
}
}
return 0 ;
default:
break;
}
F_3 ( & V_2 -> V_8 , L_30 , V_11 , V_116 ) ;
return - V_125 ;
}
static void F_32 ( struct V_14 * V_15 ,
struct V_1 * V_2 , struct V_126 * V_127 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_26 * V_8 = & V_2 -> V_8 ;
int V_17 , V_18 , V_20 , V_19 ;
unsigned V_128 , V_129 ;
unsigned long V_29 ;
T_3 V_130 ;
int V_131 = 0 ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( ! V_5 -> V_54 ) {
if ( V_5 -> V_12 == V_13 ) {
V_15 -> V_132 = V_133 ;
V_15 -> V_132 . V_134 = V_135 | V_136 | V_137 | V_138 |
V_139 ;
V_15 -> V_132 . V_140 = 4800 ;
V_15 -> V_132 . V_141 = 4800 ;
} else if ( V_5 -> V_12 == V_69 ) {
V_15 -> V_132 = V_133 ;
V_15 -> V_132 . V_134 = V_142 | V_136 | V_137 | V_138 |
V_139 ;
V_15 -> V_132 . V_140 = 9600 ;
V_15 -> V_132 . V_141 = 9600 ;
} else if ( V_5 -> V_12 == V_70 ) {
V_15 -> V_132 = V_133 ;
V_15 -> V_132 . V_134 = V_142 | V_136 | V_137 | V_138 |
V_139 ;
V_15 -> V_132 . V_140 = 9600 ;
V_15 -> V_132 . V_141 = 9600 ;
}
V_5 -> V_54 = 1 ;
}
F_12 ( & V_5 -> V_39 , V_29 ) ;
V_15 -> V_132 . V_134 &= ~ ( V_143 | V_144 ) ;
V_128 = V_15 -> V_132 . V_134 ;
V_129 = V_15 -> V_132 . V_145 ;
if ( V_127 ) {
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_5 -> V_75 = V_15 -> V_132 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
}
V_18 = V_128 & V_146 ? 1 : 0 ;
if ( V_128 & V_147 ) {
V_19 = 1 ;
V_20 = V_128 & V_148 ? 1 : 0 ;
} else
V_19 = V_20 = 0 ;
switch ( V_128 & V_149 ) {
case V_150 :
V_17 = 0 ;
break;
case V_151 :
V_17 = 1 ;
break;
case V_152 :
V_17 = 2 ;
break;
case V_136 :
V_17 = 3 ;
break;
default:
F_9 ( V_8 , L_31 , V_11 ) ;
V_17 = 3 ;
}
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_130 = V_5 -> V_53 ;
if ( ( V_128 & V_153 ) == V_154 ) {
F_3 ( V_8 , L_32 , V_11 ) ;
V_5 -> V_53 &= ~ ( V_82 | V_83 ) ;
} else
V_5 -> V_53 = ( V_82 | V_83 ) ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
F_3 ( V_8 , L_33 ,
V_11 , V_18 , V_19 , V_20 , V_17 ) ;
F_4 ( V_15 , V_2 , F_59 ( V_15 ) ,
V_17 , V_18 ,
V_19 , V_20 ,
0 , V_34 ) ;
F_4 ( V_15 , V_2 , 0 , 0 , 0 , 0 , 0 , 0 , V_41 ) ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( V_5 -> V_12 == V_13 && V_5 -> V_16 == 4800 ) {
F_3 ( V_8 , L_34 ) ;
V_15 -> V_132 . V_145
&= ~ ( V_155
| V_156
| V_157
| V_158
| V_159
| V_160
| V_161
| V_162 ) ;
V_15 -> V_132 . V_163
&= ~ V_164 ;
V_15 -> V_132 . V_165
&= ~ ( V_166
| V_167
| V_168
| V_169
| V_170 ) ;
}
V_131 = ( V_5 -> V_53 != V_130 ) ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
if ( V_131 ) {
V_5 -> V_52 = 1 ;
F_39 ( V_15 , V_2 , NULL , 0 ) ;
}
}
static int F_60 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_171 = 0 ;
unsigned long V_29 ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_171 = F_61 ( & V_5 -> V_50 ) ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
F_3 ( & V_2 -> V_8 , L_27 , V_11 , V_171 ) ;
return V_171 ;
}
static void F_62 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_37 ( & V_5 -> V_39 ) ;
V_5 -> V_55 = V_172 ;
F_38 ( & V_5 -> V_39 ) ;
}
static void F_63 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_99 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_173 , V_71 ;
F_37 ( & V_5 -> V_39 ) ;
V_173 = V_5 -> V_55 & V_174 ;
V_5 -> V_55 = 0 ;
F_38 ( & V_5 -> V_39 ) ;
if ( ! V_5 -> V_30 )
return;
if ( V_173 ) {
V_71 = F_35 ( V_2 -> V_64 , V_32 ) ;
if ( V_71 ) {
F_9 ( & V_2 -> V_8 , L_35
L_36 , V_11 , V_71 ) ;
F_10 ( V_2 ) ;
}
}
}
static void V_79 ( struct V_175 * V_175 )
{
struct V_1 * V_2 = V_175 -> V_176 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_26 * V_8 = & V_175 -> V_8 -> V_8 ;
struct V_14 * V_15 ;
unsigned char * V_177 = V_175 -> V_77 ;
unsigned long V_29 ;
char V_178 = V_179 ;
int V_180 = 0 ;
int V_181 = 0 ;
int V_71 ;
int V_182 = 0 ;
int V_101 = V_175 -> V_101 ;
switch ( V_101 ) {
case 0 :
break;
case - V_183 :
case - V_184 :
case - V_185 :
return;
case - V_186 :
default:
F_9 ( V_8 , L_37 ,
V_11 , V_101 ) ;
F_10 ( V_2 ) ;
return;
}
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( V_5 -> V_55 & V_172 ) {
F_3 ( V_8 , L_38 , V_11 ) ;
V_5 -> V_55 |= V_174 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
return;
}
F_12 ( & V_5 -> V_39 , V_29 ) ;
V_15 = F_64 ( & V_2 -> V_2 ) ;
if ( ! V_15 ) {
F_3 ( V_8 , L_39 , V_11 ) ;
return;
}
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_71 = V_175 -> V_187 ;
switch ( V_5 -> V_57 ) {
default:
case V_58 :
V_5 -> V_103 = V_177 [ 0 ] & 0xF8 ;
V_181 = V_177 [ 1 ] + 2 ;
V_182 = 2 ;
if ( V_181 > 2 )
V_180 = 1 ;
break;
case V_59 :
V_5 -> V_103 = V_177 [ 0 ] & 0xF8 ;
V_181 = ( V_177 [ 0 ] & 0x07 ) + 1 ;
V_182 = 1 ;
if ( V_181 > 1 )
V_180 = 1 ;
break;
}
F_12 ( & V_5 -> V_39 , V_29 ) ;
if ( V_71 < V_181 ) {
F_3 ( V_8 ,
L_40 ,
V_11 , V_71 , V_181 ) ;
goto V_188;
}
F_48 ( & V_2 -> V_8 , V_11 , V_175 -> V_187 , V_177 ) ;
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( V_5 -> V_103 != V_5 -> V_189 ) {
V_5 -> V_123 |= V_5 -> V_103 ^
V_5 -> V_189 ;
F_65 ( & V_2 -> V_119 ) ;
V_5 -> V_189 = V_5 -> V_103 ;
}
F_12 ( & V_5 -> V_39 , V_29 ) ;
if ( V_15 && ! ( V_15 -> V_132 . V_134 & V_139 ) &&
! ( V_5 -> V_103 & V_112 ) ) {
F_3 ( V_8 , L_41 , V_11 ) ;
F_66 ( V_15 ) ;
goto V_188;
}
F_11 ( & V_5 -> V_39 , V_29 ) ;
if ( V_5 -> V_103 & V_190 ) {
F_12 ( & V_5 -> V_39 , V_29 ) ;
V_178 = V_191 ;
F_3 ( V_8 , L_42 , V_11 ) ;
} else
F_12 ( & V_5 -> V_39 , V_29 ) ;
if ( V_181 > V_182 ) {
F_67 ( & V_2 -> V_2 , V_177 + V_182 ,
V_178 , V_181 - V_182 ) ;
F_68 ( & V_2 -> V_2 ) ;
}
F_11 ( & V_5 -> V_39 , V_29 ) ;
V_5 -> V_73 += V_181 ;
F_12 ( & V_5 -> V_39 , V_29 ) ;
V_188:
F_69 ( V_15 ) ;
if ( V_5 -> V_30 ) {
F_33 ( V_2 -> V_64 , V_2 -> V_7 -> V_8 ,
F_34 ( V_2 -> V_7 -> V_8 ,
V_2 -> V_76 ) ,
V_2 -> V_64 -> V_77 ,
V_2 -> V_64 -> V_78 ,
V_79 , V_2 ,
V_5 -> V_62 ) ;
V_71 = F_35 ( V_2 -> V_64 , V_98 ) ;
if ( V_71 && V_71 != - V_192 ) {
F_9 ( V_8 , L_43 ,
V_11 , V_71 ) ;
F_10 ( V_2 ) ;
}
}
}
static void V_97 ( struct V_175 * V_175 )
{
struct V_1 * V_2 = V_175 -> V_176 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_26 * V_8 = & V_175 -> V_8 -> V_8 ;
int V_71 ;
int V_101 = V_175 -> V_101 ;
switch ( V_101 ) {
case 0 :
break;
case - V_183 :
case - V_184 :
case - V_185 :
F_3 ( V_8 , L_44 ,
V_11 , V_101 ) ;
V_5 -> V_92 = 0 ;
return;
case - V_186 :
if ( ! V_5 -> V_30 )
break;
F_30 ( V_2 -> V_7 -> V_8 , 0x02 ) ;
F_3 ( V_8 , L_45 ,
V_11 , V_101 ) ;
V_2 -> V_63 -> V_78 = 1 ;
V_71 = F_35 ( V_2 -> V_63 , V_98 ) ;
if ( ! V_71 )
return;
F_9 ( V_8 , L_46 ,
V_11 , V_71 ) ;
F_10 ( V_2 ) ;
break;
default:
F_9 ( V_8 , L_47 ,
V_11 , V_101 ) ;
F_10 ( V_2 ) ;
break;
}
V_5 -> V_92 = 0 ;
F_31 ( V_2 ) ;
}
