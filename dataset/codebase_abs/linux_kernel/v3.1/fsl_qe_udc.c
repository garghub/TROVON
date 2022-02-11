static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned char V_8 = V_2 -> V_8 ;
F_2 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_4 . V_5 == - V_10 )
V_4 -> V_4 . V_5 = V_5 ;
else
V_5 = V_4 -> V_4 . V_5 ;
if ( V_4 -> V_11 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_4 -> V_4 . V_15 , V_4 -> V_4 . V_16 ,
F_4 ( V_2 )
? V_17
: V_18 ) ;
V_4 -> V_4 . V_15 = V_19 ;
V_4 -> V_11 = 0 ;
} else
F_5 ( V_7 -> V_12 . V_13 . V_14 ,
V_4 -> V_4 . V_15 , V_4 -> V_4 . V_16 ,
F_4 ( V_2 )
? V_17
: V_18 ) ;
if ( V_5 && ( V_5 != - V_20 ) )
F_6 ( V_7 -> V_13 , L_1 ,
V_2 -> V_2 . V_21 , & V_4 -> V_4 , V_5 ,
V_4 -> V_4 . V_22 , V_4 -> V_4 . V_16 ) ;
V_2 -> V_8 = 1 ;
F_7 ( & V_7 -> V_23 ) ;
if ( V_4 -> V_4 . V_24 )
V_4 -> V_4 . V_24 ( & V_2 -> V_2 , & V_4 -> V_4 ) ;
F_8 ( & V_7 -> V_23 ) ;
V_2 -> V_8 = V_8 ;
}
static void F_9 ( struct V_1 * V_2 , int V_5 )
{
while ( ! F_10 ( & V_2 -> V_9 ) ) {
struct V_3 * V_4 = NULL ;
V_4 = F_11 ( V_2 -> V_9 . V_25 , struct V_3 , V_9 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
}
}
static int F_12 ( struct V_1 * V_2 , int V_26 )
{
T_1 V_27 ;
T_2 V_28 = V_2 -> V_28 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_27 = F_13 ( & V_7 -> V_29 -> V_30 [ V_28 ] ) ;
V_27 = V_27 & ~ V_31 ;
if ( V_26 == 1 )
V_27 |= V_32 ;
else if ( V_2 -> V_33 == V_34 )
V_27 |= V_35 ;
F_14 ( & V_7 -> V_29 -> V_30 [ V_28 ] , V_27 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_26 )
{
T_1 V_27 ;
T_2 V_28 = V_2 -> V_28 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_27 = F_13 ( & V_7 -> V_29 -> V_30 [ V_28 ] ) ;
V_27 = V_27 & ~ V_36 ;
if ( V_26 == 1 )
V_27 |= V_37 ;
else if ( V_2 -> V_33 == V_38 )
V_27 |= V_39 ;
F_14 ( & V_7 -> V_29 -> V_30 [ V_28 ] , V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 )
{
F_15 ( & V_7 -> V_40 [ 0 ] , 1 ) ;
F_12 ( & V_7 -> V_40 [ 0 ] , 1 ) ;
V_41 -> V_42 = V_43 ;
V_41 -> V_44 = 0 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_28 = V_2 -> V_28 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_45 == V_46 ) {
F_18 ( & V_7 -> V_29 -> V_30 [ V_28 ] ,
V_31 , V_47 ) ;
F_19 ( & V_7 -> V_29 -> V_48 ,
( V_49 | V_50 ) ) ;
V_2 -> V_45 = V_51 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_45 == V_51 ) {
F_18 ( & V_7 -> V_29 -> V_30 [ V_2 -> V_28 ] ,
V_52 , V_39 ) ;
F_14 ( & V_7 -> V_29 -> V_53 ,
V_50 | V_49 ) ;
F_21 ( & V_7 -> V_29 -> V_48 ,
( V_49 | V_50 ) ) ;
V_2 -> V_45 = V_46 ;
V_2 -> V_54 = 0 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 -> V_55 == V_56 )
F_23 ( V_57 | ( V_2 -> V_28 << V_58 ) ,
V_59 ) ;
else
F_24 ( V_60 , V_61 ,
V_2 -> V_28 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 -> V_55 == V_56 )
F_23 ( V_62 | ( V_2 -> V_28 <<
V_58 ) , V_63 ) ;
else
F_24 ( V_64 , V_61 ,
V_2 -> V_28 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_65 ;
V_65 = ( int ) V_2 -> V_28 ;
F_22 ( V_2 ) ;
F_27 ( & V_7 -> V_29 -> V_66 ,
V_67 | ( V_68 & ( V_2 -> V_28 ) ) ) ;
F_14 ( & V_7 -> V_69 [ V_65 ] -> V_70 , F_13 ( & V_7 -> V_69 [ V_65 ] -> V_71 ) ) ;
F_28 ( & V_7 -> V_69 [ V_65 ] -> V_72 , 0 ) ;
F_14 ( & V_7 -> V_69 [ V_65 ] -> V_73 , 0 ) ;
V_2 -> V_74 = V_2 -> V_75 ;
V_2 -> V_76 = V_2 -> V_75 ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_27 ( & V_7 -> V_29 -> V_66 ,
V_77 | ( V_68 & ( V_2 -> V_28 ) ) ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 , int V_78 )
{
struct V_1 * V_2 ;
T_3 V_79 ;
struct V_80 T_4 * V_81 ;
int V_65 ;
V_2 = & V_7 -> V_40 [ V_78 ] ;
if ( V_2 -> V_33 == V_38 )
V_79 = V_82 ;
else
V_79 = V_83 ;
V_81 = V_2 -> V_84 ;
for ( V_65 = 0 ; V_65 < ( V_79 - 1 ) ; V_65 ++ ) {
F_28 ( ( T_3 T_4 * ) V_81 , V_85 | V_86 ) ;
V_81 ++ ;
}
F_28 ( ( T_3 T_4 * ) V_81 , V_85 | V_86 | V_87 ) ;
V_81 = V_2 -> V_75 ;
for ( V_65 = 0 ; V_65 < V_88 - 1 ; V_65 ++ ) {
F_28 ( & V_81 -> V_89 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , 0 ) ;
V_81 ++ ;
}
F_28 ( ( T_3 T_4 * ) V_81 , V_90 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , int V_78 )
{
struct V_1 * V_2 ;
T_1 V_91 ;
V_2 = & V_7 -> V_40 [ V_78 ] ;
V_91 = F_13 ( & V_7 -> V_29 -> V_30 [ V_78 ] ) ;
V_91 &= ~ V_52 ;
switch ( V_2 -> V_33 ) {
case V_92 :
F_26 ( V_2 ) ;
break;
case V_38 :
V_91 |= V_39 ;
break;
case V_34 :
F_26 ( V_2 ) ;
V_91 |= V_35 ;
break;
default:
break;
}
F_14 ( & V_7 -> V_29 -> V_30 [ V_78 ] , V_91 ) ;
F_30 ( V_7 , V_78 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
V_2 -> V_93 ^= 0x1 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , unsigned char V_78 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_78 ] ;
unsigned long V_94 = 0 ;
struct V_95 T_4 * V_96 ;
int V_65 ;
struct V_80 T_4 * V_81 ;
int V_79 ;
if ( V_2 -> V_33 == V_38 )
V_79 = V_82 ;
else
V_79 = V_83 ;
V_96 = V_7 -> V_69 [ V_78 ] ;
V_94 = F_34 ( sizeof( struct V_80 ) * ( V_79 +
V_88 ) , V_97 ) ;
if ( F_35 ( V_94 ) )
return - V_98 ;
F_14 ( & V_96 -> V_99 , ( T_1 ) V_94 ) ;
F_14 ( & V_96 -> V_71 , ( T_1 ) ( V_94 +
( sizeof( struct V_80 ) * V_79 ) ) ) ;
F_14 ( & V_96 -> V_100 , F_13 ( & V_96 -> V_99 ) ) ;
F_14 ( & V_96 -> V_70 , F_13 ( & V_96 -> V_71 ) ) ;
V_2 -> V_84 = F_36 ( V_94 ) ;
V_2 -> V_75 = F_36 ( V_94 + ( sizeof( struct V_80 )
* V_79 ) ) ;
V_2 -> V_101 = V_2 -> V_84 ;
V_2 -> V_102 = V_2 -> V_84 ;
V_2 -> V_76 = V_2 -> V_75 ;
V_2 -> V_74 = V_2 -> V_75 ;
V_2 -> V_93 = 0 ;
V_81 = V_2 -> V_84 ;
for ( V_65 = 0 ; V_65 < V_79 - 1 ; V_65 ++ ) {
F_28 ( & V_81 -> V_89 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , 0 ) ;
V_81 ++ ;
}
F_28 ( & V_81 -> V_89 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , V_87 ) ;
V_81 = V_2 -> V_75 ;
for ( V_65 = 0 ; V_65 < V_88 - 1 ; V_65 ++ ) {
F_28 ( & V_81 -> V_89 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , 0 ) ;
V_81 ++ ;
}
F_28 ( & V_81 -> V_89 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , V_90 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned int V_103 ;
int V_65 ;
unsigned int V_104 ;
struct V_80 T_4 * V_81 ;
unsigned int V_79 ;
if ( V_2 -> V_84 == NULL )
return - V_105 ;
V_81 = V_2 -> V_84 ;
V_2 -> V_106 = F_38 ( sizeof( * V_2 -> V_106 ) , V_107 ) ;
if ( V_2 -> V_106 == NULL ) {
F_39 ( V_2 -> V_7 -> V_13 , L_2 ) ;
return - V_98 ;
}
F_40 ( V_2 -> V_106 ) ;
if ( V_2 -> V_33 == V_38 )
V_79 = V_82 ;
else
V_79 = V_83 ;
V_103 = ( V_2 -> V_2 . V_108 + V_109 + 2 ) * ( V_79 + 1 ) ;
V_2 -> V_110 = F_41 ( V_103 , V_107 ) ;
if ( V_2 -> V_110 == NULL ) {
F_39 ( V_2 -> V_7 -> V_13 , L_3 ,
V_103 ) ;
F_42 ( V_2 -> V_106 ) ;
return - V_98 ;
}
V_2 -> V_111 = F_43 ( ( void * ) V_2 -> V_110 ) ;
if ( V_2 -> V_111 == V_19 ) {
V_2 -> V_111 = F_44 ( V_41 -> V_12 . V_13 . V_14 ,
V_2 -> V_110 ,
V_103 ,
V_18 ) ;
V_2 -> V_112 = 1 ;
} else {
F_45 ( V_41 -> V_12 . V_13 . V_14 ,
V_2 -> V_111 , V_103 ,
V_18 ) ;
V_2 -> V_112 = 0 ;
}
V_103 = V_2 -> V_2 . V_108 + V_109 + 2 ;
V_104 = V_2 -> V_111 ;
V_104 = ( T_3 ) ( ( ( V_104 >> 2 ) << 2 ) + 4 ) ;
for ( V_65 = 0 ; V_65 < V_79 - 1 ; V_65 ++ ) {
F_28 ( & V_81 -> V_89 , V_104 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , ( V_85 | V_86 ) ) ;
V_104 = V_104 + V_103 ;
V_81 ++ ;
}
F_28 ( & V_81 -> V_89 , V_104 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , ( V_85 | V_86 | V_87 ) ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_7 , unsigned char V_78 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_78 ] ;
struct V_95 T_4 * V_96 ;
T_1 V_113 , V_114 ;
T_1 V_104 ;
T_2 V_115 = 0 ;
V_96 = V_7 -> V_69 [ V_78 ] ;
V_113 = 0 ;
V_114 = ( V_2 -> V_116 -> V_117 & V_118 ) ;
V_113 |= ( V_114 << V_119 ) ;
switch ( V_2 -> V_116 -> V_120 & 0x03 ) {
case V_121 :
V_113 |= V_122 ;
break;
case V_123 :
V_113 |= V_124 ;
break;
case V_125 :
V_113 |= V_126 ;
break;
default:
V_113 |= V_127 ;
break;
}
switch ( V_2 -> V_33 ) {
case V_38 :
V_113 |= V_39 ;
break;
case V_34 :
V_113 |= V_35 ;
break;
default:
break;
}
F_14 ( & V_7 -> V_29 -> V_30 [ V_78 ] , V_113 ) ;
V_115 = 0x30 ;
F_27 ( & V_96 -> V_128 , V_115 ) ;
F_27 ( & V_96 -> V_129 , V_115 ) ;
V_104 = ( T_1 ) ( V_2 -> V_2 . V_108 + V_109 ) ;
V_104 = ( T_1 ) ( ( ( V_104 >> 2 ) << 2 ) + 4 ) ;
F_14 ( & V_96 -> V_130 , V_104 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 ,
unsigned char V_78 ,
const struct V_131 * V_116 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_78 ] ;
unsigned long V_132 ;
int V_133 = 0 ;
T_1 V_134 = 0 ;
V_134 = F_48 ( V_116 -> V_135 ) ;
if ( V_78 != 0 ) {
switch ( V_116 -> V_120 & V_136 ) {
case V_121 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_137;
switch ( V_7 -> V_12 . V_138 ) {
case V_139 :
if ( ( V_134 == 128 ) || ( V_134 == 256 ) || ( V_134 == 512 ) )
break;
default:
switch ( V_134 ) {
case 4 :
case 8 :
case 16 :
case 32 :
case 64 :
break;
default:
case V_140 :
goto V_137;
}
}
break;
case V_125 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 ) )
goto V_137;
switch ( V_7 -> V_12 . V_138 ) {
case V_139 :
if ( V_134 <= 1024 )
break;
case V_141 :
if ( V_134 <= 64 )
break;
default:
if ( V_134 <= 8 )
break;
goto V_137;
}
break;
case V_123 :
if ( strstr ( V_2 -> V_2 . V_21 , L_6 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_137;
switch ( V_7 -> V_12 . V_138 ) {
case V_139 :
if ( V_134 <= 1024 )
break;
case V_141 :
if ( V_134 <= 1023 )
break;
default:
goto V_137;
}
break;
case V_142 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_137;
switch ( V_7 -> V_12 . V_138 ) {
case V_139 :
case V_141 :
switch ( V_134 ) {
case 1 :
case 2 :
case 4 :
case 8 :
case 16 :
case 32 :
case 64 :
break;
default:
goto V_137;
}
case V_140 :
switch ( V_134 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
goto V_137;
}
default:
goto V_137;
}
break;
default:
goto V_137;
}
}
F_49 ( & V_7 -> V_23 , V_132 ) ;
V_2 -> V_2 . V_108 = V_134 ;
V_2 -> V_143 = ( T_2 ) ( V_116 -> V_120 & V_136 ) ;
V_2 -> V_116 = V_116 ;
V_2 -> V_8 = 0 ;
V_2 -> V_144 = 1 ;
if ( V_78 == 0 ) {
V_2 -> V_33 = V_92 ;
V_7 -> V_44 = V_38 ;
V_7 -> V_42 = V_43 ;
} else {
switch ( V_116 -> V_117 & V_145 ) {
case V_38 :
V_2 -> V_33 = V_38 ;
break;
case V_34 :
V_2 -> V_33 = V_34 ;
default:
break;
}
}
F_33 ( V_7 , V_78 ) ;
if ( ( V_2 -> V_143 == V_146 ) || ( V_2 -> V_33 == V_38 ) ) {
V_133 = F_37 ( V_2 ) ;
if ( V_133 )
goto V_147;
}
if ( ( V_2 -> V_143 == V_146 ) || ( V_2 -> V_33 == V_34 ) ) {
V_2 -> V_148 = F_38 ( sizeof( * V_2 -> V_148 ) , V_107 ) ;
if ( V_2 -> V_148 == NULL ) {
F_39 ( V_7 -> V_13 , L_7 ) ;
goto V_149;
}
F_40 ( V_2 -> V_148 ) ;
}
F_46 ( V_7 , V_78 ) ;
F_50 ( & V_7 -> V_23 , V_132 ) ;
return 0 ;
V_149:
F_42 ( V_2 -> V_110 ) ;
F_42 ( V_2 -> V_106 ) ;
V_147:
F_50 ( & V_7 -> V_23 , V_132 ) ;
V_137:
F_39 ( V_7 -> V_13 , L_8 , V_2 -> V_2 . V_21 ) ;
return - V_150 ;
}
static inline void F_51 ( void )
{
F_52 ( & V_41 -> V_29 -> V_151 , V_152 ) ;
}
static inline void F_53 ( void )
{
F_54 ( & V_41 -> V_29 -> V_151 , V_152 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_3 V_153 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_2 -> V_102 ) ;
V_153 = V_86 | V_85 | ( V_153 & V_87 ) ;
F_28 ( ( T_3 T_4 * ) V_2 -> V_102 , V_153 ) ;
if ( V_153 & V_87 )
V_2 -> V_102 = V_2 -> V_84 ;
else
V_2 -> V_102 ++ ;
}
static void F_57 ( struct V_1 * V_2 , unsigned char V_154 )
{
T_3 V_153 ;
struct V_80 T_4 * V_81 , * V_155 ;
unsigned char V_156 = 0 ;
V_155 = V_2 -> V_101 ;
V_81 = V_2 -> V_102 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
while ( ! ( V_153 & V_85 ) && ! ( V_153 & V_157 ) && ! V_156 ) {
V_153 = V_85 | V_86 | ( V_153 & V_87 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , V_153 ) ;
if ( V_153 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
if ( V_154 && ( V_81 == V_155 ) )
V_156 = 1 ;
}
V_2 -> V_102 = V_81 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_80 T_4 * V_81 = V_2 -> V_101 ;
T_3 V_153 ;
T_2 V_28 = V_2 -> V_28 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
if ( ! ( V_153 & V_85 ) && ! ( V_153 & V_157 ) ) {
V_81 = V_2 -> V_84 +
( ( F_13 ( & V_7 -> V_69 [ V_28 ] -> V_100 ) -
F_13 ( & V_7 -> V_69 [ V_28 ] -> V_99 ) )
>> 3 ) ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
if ( V_153 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_2 -> V_102 = V_81 ;
F_57 ( V_2 , 0 ) ;
V_2 -> V_102 = V_2 -> V_101 ;
} else
F_57 ( V_2 , 1 ) ;
if ( F_13 ( & V_7 -> V_29 -> V_53 ) & V_50 )
F_14 ( & V_7 -> V_29 -> V_53 , V_50 ) ;
if ( V_2 -> V_54 <= 0 && ( ! F_10 ( & V_2 -> V_9 ) ) )
F_20 ( V_2 ) ;
V_2 -> V_158 = 0 ;
}
static int F_59 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
struct V_159 * V_160 ;
unsigned int V_161 ;
T_2 * V_162 ;
V_160 = V_2 -> V_106 ;
if ( ( F_60 ( V_160 ) & V_163 )
&& ( V_7 -> V_42 == V_43 ) ) {
V_161 = F_61 ( V_160 ) ;
if ( F_62 ( V_161 != 8 ) )
return - V_105 ;
V_162 = ( T_2 * ) & V_7 -> V_164 ;
memcpy ( V_162 , V_160 -> V_165 , V_161 ) ;
V_2 -> V_93 = 1 ;
F_63 ( V_7 , & V_7 -> V_164 ) ;
return 0 ;
}
return - V_105 ;
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
struct V_159 * V_160 ;
struct V_80 T_4 * V_81 ;
T_3 V_153 , V_16 ;
T_3 V_166 ;
V_160 = V_2 -> V_106 ;
if ( V_2 -> V_33 == V_34 ) {
F_39 ( V_7 -> V_13 , L_9 ) ;
return - V_105 ;
}
V_81 = V_2 -> V_101 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_153 & V_157 ;
while ( ! ( V_153 & V_85 ) && V_16 ) {
if ( ( V_153 & V_167 ) && ( V_153 & V_168 )
&& ! ( V_153 & V_169 ) ) {
if ( V_16 == V_109 ) {
V_7 -> V_42 = V_43 ;
F_6 ( V_7 -> V_13 ,
L_10 ) ;
} else {
F_65 ( V_160 ) ;
V_166 = ( T_3 ) F_66 ( F_56 ( & V_81 -> V_89 ) ) ;
F_67 ( V_160 , ( T_2 * ) V_166 ) ;
F_68 ( V_160 ,
( V_16 - V_109 ) ) ;
F_69 ( V_160 , V_170 ) ;
switch ( V_153 & V_171 ) {
case V_172 :
F_70 ( V_160 , V_163 ) ;
break;
case V_173 :
F_70 ( V_160 , V_174 ) ;
break;
default:
F_70 ( V_160 , V_175 ) ;
break;
}
if ( ( V_153 & V_171 ) == V_172 )
F_59 ( V_7 ) ;
else
F_71 ( V_2 ) ;
}
} else {
F_39 ( V_7 -> V_13 , L_11 ) ;
}
F_55 ( V_2 ) ;
if ( V_153 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_153 & V_157 ;
}
V_2 -> V_101 = V_81 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_159 * V_160 ;
T_2 V_176 = 0 ;
unsigned int V_161 ;
T_2 * V_162 ;
struct V_3 * V_4 ;
V_160 = V_2 -> V_106 ;
if ( F_60 ( V_160 ) & V_174 )
V_176 = 0x1 ;
if ( V_176 != V_2 -> V_93 ) {
F_39 ( V_2 -> V_7 -> V_13 , L_12 ) ;
return - V_177 ;
}
V_161 = F_61 ( V_160 ) ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_39 ( V_2 -> V_7 -> V_13 , L_13 , V_2 -> V_21 ) ;
} else {
V_4 = F_11 ( V_2 -> V_9 . V_25 , struct V_3 , V_9 ) ;
V_162 = ( T_2 * ) ( V_4 -> V_4 . V_89 ) + V_4 -> V_4 . V_22 ;
if ( V_162 ) {
memcpy ( V_162 , V_160 -> V_165 , V_161 ) ;
V_4 -> V_4 . V_22 += V_161 ;
if ( ( V_161 < V_2 -> V_2 . V_108 ) ||
( V_4 -> V_4 . V_22 >= V_4 -> V_4 . V_16 ) ) {
if ( V_2 -> V_28 == 0 )
F_72 ( V_2 -> V_7 , V_4 ) ;
else
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_10 ( & V_2 -> V_9 ) && V_2 -> V_28 != 0 )
F_17 ( V_2 ) ;
}
}
}
F_32 ( V_2 ) ;
return 0 ;
}
static void F_73 ( unsigned long V_165 )
{
struct V_6 * V_7 = (struct V_6 * ) V_165 ;
struct V_1 * V_2 ;
struct V_159 * V_160 ;
struct V_80 T_4 * V_81 ;
unsigned long V_132 ;
T_3 V_153 , V_16 ;
T_3 V_166 , V_65 ;
F_49 ( & V_7 -> V_23 , V_132 ) ;
for ( V_65 = 1 ; V_65 < V_178 ; V_65 ++ ) {
V_2 = & V_7 -> V_40 [ V_65 ] ;
if ( V_2 -> V_33 == V_34 || V_2 -> V_179 == 0 ) {
F_74 ( V_7 -> V_13 ,
L_14 ) ;
continue;
}
V_160 = V_2 -> V_106 ;
V_81 = V_2 -> V_101 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_153 & V_157 ;
while ( ! ( V_153 & V_85 ) && V_16 ) {
if ( F_10 ( & V_2 -> V_9 ) ) {
F_17 ( V_2 ) ;
F_74 ( V_7 -> V_13 ,
L_15 ,
V_2 -> V_54 ) ;
break;
}
if ( ( V_153 & V_167 ) && ( V_153 & V_168 )
&& ! ( V_153 & V_169 ) ) {
F_65 ( V_160 ) ;
V_166 = ( T_3 ) F_66 ( F_56 ( & V_81 -> V_89 ) ) ;
F_67 ( V_160 , ( T_2 * ) V_166 ) ;
F_68 ( V_160 ,
( V_16 - V_109 ) ) ;
F_69 ( V_160 , V_170 ) ;
switch ( V_153 & V_171 ) {
case V_173 :
F_70 ( V_160 , V_174 ) ;
break;
case V_172 :
F_70 ( V_160 , V_163 ) ;
break;
default:
F_70 ( V_160 , V_175 ) ;
break;
}
F_71 ( V_2 ) ;
} else {
F_39 ( V_7 -> V_13 ,
L_16 ) ;
}
F_28 ( ( T_3 T_4 * ) V_81 , V_153 & V_180 ) ;
V_2 -> V_54 -- ;
if ( ! ( V_2 -> V_158 ) )
F_55 ( V_2 ) ;
if ( V_153 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_153 & V_157 ;
}
V_2 -> V_101 = V_81 ;
if ( V_2 -> V_158 )
F_58 ( V_2 ) ;
V_2 -> V_179 = 0 ;
}
F_50 ( & V_7 -> V_23 , V_132 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_159 * V_160 ;
struct V_80 T_4 * V_81 ;
T_1 V_181 , V_182 , V_183 ;
V_7 = V_2 -> V_7 ;
V_160 = V_2 -> V_106 ;
if ( V_2 -> V_33 == V_34 ) {
F_39 ( V_7 -> V_13 , L_17 ) ;
return - V_105 ;
}
V_81 = V_2 -> V_101 ;
V_181 = ( T_1 ) ( V_81 - V_2 -> V_84 ) ;
V_182 = ( T_1 ) ( ( F_13 ( & V_7 -> V_69 [ V_2 -> V_28 ] -> V_100 ) -
F_13 ( & V_7 -> V_69 [ V_2 -> V_28 ] -> V_99 ) ) >> 3 ) ;
if ( V_181 < V_182 )
V_183 = V_82 - V_182 + V_181 ;
else
V_183 = V_181 - V_182 ;
if ( V_183 < V_184 ) {
F_17 ( V_2 ) ;
V_2 -> V_158 = 1 ;
F_6 ( V_7 -> V_13 , L_18 , V_183 ) ;
}
V_2 -> V_54 = V_82 - V_183 ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_17 ( V_2 ) ;
F_6 ( V_7 -> V_13 , L_19 ,
V_2 -> V_54 ) ;
return 0 ;
}
F_76 ( & V_7 -> V_185 ) ;
V_2 -> V_179 = 1 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_159 * V_186 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_80 T_4 * V_81 ;
T_1 V_187 ;
T_3 V_153 , V_188 ;
T_3 V_189 ;
if ( V_2 -> V_33 == V_38 ) {
F_39 ( V_7 -> V_13 , L_20 ) ;
return - V_105 ;
}
V_187 = F_13 ( & V_7 -> V_29 -> V_48 ) ;
F_14 ( & V_7 -> V_29 -> V_48 ,
V_187 & ~ ( V_190 | V_191 ) ) ;
V_81 = V_2 -> V_76 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
if ( ! ( V_153 & ( V_192 | V_157 ) ) ) {
if ( F_61 ( V_186 ) == 0 ) {
F_67 ( V_186 , V_7 -> V_193 ) ;
F_68 ( V_186 , 2 ) ;
V_186 -> V_194 |= ( V_195 | V_196 ) ;
F_6 ( V_7 -> V_13 , L_21 ) ;
}
V_189 = F_43 ( ( void * ) V_186 -> V_165 ) ;
F_28 ( & V_81 -> V_89 , V_189 ) ;
V_153 = ( V_153 & V_90 ) ;
if ( ! ( F_60 ( V_186 ) & V_196 ) )
V_153 |= V_192 | V_197 | V_198 | V_199
| F_61 ( V_186 ) ;
else
V_153 |= V_192 | V_197 | V_198 | F_61 ( V_186 ) ;
if ( ( V_2 -> V_28 == 0 ) && ( V_7 -> V_42 == V_200 ) )
V_2 -> V_93 = 0x1 ;
if ( V_2 -> V_93 ) {
V_188 = V_201 ;
V_186 -> V_194 |= V_174 ;
} else {
V_188 = V_202 ;
V_186 -> V_194 |= V_175 ;
}
V_153 |= V_203 ;
V_153 |= V_188 ;
F_28 ( ( T_3 T_4 * ) V_81 , V_153 ) ;
F_29 ( V_2 ) ;
F_14 ( & V_7 -> V_29 -> V_48 , V_187 ) ;
F_32 ( V_2 ) ;
if ( V_153 & V_90 )
V_2 -> V_76 = V_2 -> V_75 ;
else
V_2 -> V_76 ++ ;
return 0 ;
} else {
F_14 ( & V_7 -> V_29 -> V_48 , V_187 ) ;
F_6 ( V_7 -> V_13 , L_22 ) ;
return - V_204 ;
}
}
static int F_78 ( struct V_1 * V_2 , unsigned char V_205 )
{
if ( V_2 -> V_206 != NULL ) {
struct V_3 * V_4 = V_2 -> V_206 ;
unsigned V_207 = 0 , V_208 = 0 ;
V_208 = F_79 ( unsigned , V_4 -> V_4 . V_16 - V_2 -> V_209 ,
V_2 -> V_2 . V_108 ) ;
if ( ! V_205 ) {
int V_210 = V_2 -> V_211 ;
V_2 -> V_209 += V_210 ;
V_2 -> V_211 -= V_210 ;
} else {
V_2 -> V_211 = 0 ;
}
if ( V_4 -> V_4 . V_212 ) {
if ( V_208 == 0 ||
( V_4 -> V_4 . V_16 % V_2 -> V_2 . V_108 ) != 0 )
V_207 = 0 ;
else
V_207 = 1 ;
} else
V_207 = 0 ;
if ( ( ( V_2 -> V_206 -> V_4 . V_16 - V_2 -> V_209 ) <= 0 ) && ! V_207 ) {
F_1 ( V_2 , V_2 -> V_206 , 0 ) ;
V_2 -> V_206 = NULL ;
V_2 -> V_211 = 0 ;
V_2 -> V_209 = 0 ;
}
}
if ( V_2 -> V_206 == NULL ) {
if ( ! F_10 ( & V_2 -> V_9 ) ) {
V_2 -> V_206 = F_11 ( V_2 -> V_9 . V_25 , struct V_3 ,
V_9 ) ;
V_2 -> V_211 = 0 ;
V_2 -> V_209 = 0 ;
}
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_159 * V_186 )
{
unsigned int V_103 ;
T_2 * V_89 ;
F_65 ( V_186 ) ;
V_103 = F_79 ( T_3 , ( V_2 -> V_206 -> V_4 . V_16 - V_2 -> V_209 ) ,
V_2 -> V_2 . V_108 ) ;
V_89 = ( T_2 * ) V_2 -> V_206 -> V_4 . V_89 + V_2 -> V_209 ;
if ( V_89 && V_103 ) {
V_2 -> V_211 = V_103 ;
V_2 -> V_206 -> V_4 . V_22 += V_103 ;
F_67 ( V_186 , V_89 ) ;
F_68 ( V_186 , V_103 ) ;
F_69 ( V_186 , V_170 ) ;
F_70 ( V_186 , 0 ) ;
return F_77 ( V_2 , V_186 ) ;
}
return - V_177 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_159 * V_186 , T_5 V_213 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_186 == NULL )
return - V_150 ;
F_65 ( V_186 ) ;
F_67 ( V_186 , ( T_2 * ) V_7 -> V_193 ) ;
F_68 ( V_186 , 2 ) ;
F_69 ( V_186 , V_170 ) ;
F_70 ( V_186 , ( V_195 | V_196 | V_213 ) ) ;
return F_77 ( V_2 , V_186 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_159 * V_186 )
{
struct V_3 * V_4 = V_2 -> V_206 ;
int V_133 ;
if ( V_4 == NULL )
return - V_150 ;
if ( ( V_4 -> V_4 . V_16 - V_2 -> V_209 ) > 0 )
V_133 = F_80 ( V_2 , V_186 ) ;
else
V_133 = F_81 ( V_2 , V_186 , 0 ) ;
return V_133 ;
}
static int F_83 ( struct V_6 * V_7 , int V_214 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
if ( V_214 == V_34 ) {
V_7 -> V_42 = V_200 ;
V_7 -> V_44 = V_34 ;
F_81 ( V_2 , V_2 -> V_148 , V_215 | V_216 ) ;
} else {
V_7 -> V_44 = V_38 ;
V_7 -> V_42 = V_217 ;
}
return 0 ;
}
static void F_72 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
switch ( V_7 -> V_42 ) {
case V_218 :
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_83 ( V_7 , V_38 ) )
F_16 ( V_7 ) ;
break;
case V_200 :
F_1 ( V_2 , V_4 , 0 ) ;
V_7 -> V_42 = V_43 ;
break;
case V_219 :
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_83 ( V_7 , V_34 ) )
F_16 ( V_7 ) ;
break;
case V_217 :
F_1 ( V_2 , V_4 , 0 ) ;
V_7 -> V_42 = V_43 ;
break;
case V_43 :
F_6 ( V_7 -> V_13 , L_23 ) ;
break;
default:
F_16 ( V_7 ) ;
break;
}
}
static int F_84 ( struct V_1 * V_2 , unsigned char V_205 )
{
struct V_3 * V_206 = NULL ;
struct V_159 * V_186 = V_2 -> V_148 ;
if ( ( F_60 ( V_186 ) & ( V_195 | V_216 ) ) == ( V_195 | V_216 ) ) {
if ( ! V_205 )
V_2 -> V_7 -> V_42 = V_43 ;
else
F_81 ( V_2 , V_2 -> V_148 , V_215 | V_216 ) ;
return 0 ;
}
V_206 = V_2 -> V_206 ;
if ( V_206 != NULL ) {
if ( ! V_205 ) {
int V_210 = V_2 -> V_211 ;
V_2 -> V_209 += V_210 ;
V_2 -> V_211 -= V_210 ;
} else {
V_2 -> V_211 = 0 ;
}
if ( ( V_2 -> V_206 -> V_4 . V_16 - V_2 -> V_209 ) <= 0 ) {
V_2 -> V_206 -> V_4 . V_22 = ( unsigned int ) V_2 -> V_209 ;
F_72 ( V_2 -> V_7 , V_2 -> V_206 ) ;
V_2 -> V_206 = NULL ;
V_2 -> V_211 = 0 ;
V_2 -> V_209 = 0 ;
}
} else {
F_6 ( V_2 -> V_7 -> V_13 , L_24 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_148 ) & V_220 ) {
F_26 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_13 , L_25 ) ;
if ( F_60 ( V_2 -> V_148 ) & V_175 )
V_2 -> V_93 = 0 ;
else
V_2 -> V_93 = 1 ;
F_84 ( V_2 , 1 ) ;
} else
F_84 ( V_2 , 0 ) ;
F_82 ( V_2 , V_2 -> V_148 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_80 T_4 * V_81 ;
struct V_159 * V_160 ;
T_3 V_153 ;
V_81 = V_2 -> V_74 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
while ( ! ( V_153 & V_192 ) && ( V_153 & ~ V_90 ) ) {
V_160 = V_2 -> V_148 ;
F_28 ( ( T_3 T_4 * ) V_81 , V_153 & V_90 ) ;
F_28 ( & V_81 -> V_89 , 0 ) ;
if ( V_153 & V_90 )
V_2 -> V_74 = V_2 -> V_75 ;
else
V_2 -> V_74 ++ ;
if ( V_2 -> V_74 == V_2 -> V_76 ) {
if ( V_153 & V_221 ) {
F_69 ( V_160 , V_220 ) ;
if ( V_153 & V_222 )
V_160 -> V_5 |= V_223 ;
if ( V_153 & V_224 )
V_160 -> V_5 |= V_225 ;
}
F_85 ( V_2 ) ;
}
V_81 = V_2 -> V_74 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_148 ) & V_220 ) {
F_26 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_13 , L_25 ) ;
if ( F_60 ( V_2 -> V_148 ) & V_175 )
V_2 -> V_93 = 0 ;
else
V_2 -> V_93 = 1 ;
F_78 ( V_2 , 1 ) ;
} else
F_78 ( V_2 , 0 ) ;
F_82 ( V_2 , V_2 -> V_148 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_80 T_4 * V_81 ;
struct V_159 * V_160 = NULL ;
T_3 V_153 ;
unsigned char V_226 = 0 ;
V_81 = V_2 -> V_74 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
while ( ! ( V_153 & V_192 ) && ( V_153 & ~ V_90 ) ) {
V_160 = V_2 -> V_148 ;
if ( V_153 & V_221 ) {
F_69 ( V_160 , V_220 ) ;
if ( V_153 & V_222 )
V_160 -> V_5 |= V_223 ;
if ( V_153 & V_224 )
V_160 -> V_5 |= V_225 ;
}
F_28 ( ( T_3 T_4 * ) V_81 , V_153 & V_90 ) ;
F_28 ( & V_81 -> V_89 , 0 ) ;
if ( V_153 & V_90 )
V_2 -> V_74 = V_2 -> V_75 ;
else
V_2 -> V_74 ++ ;
F_88 ( V_2 ) ;
V_81 = V_2 -> V_74 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
}
if ( V_226 )
return - V_177 ;
else
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_133 = 0 ;
if ( V_2 -> V_206 == NULL ) {
V_2 -> V_209 = 0 ;
V_2 -> V_211 = 0 ;
F_78 ( V_2 , 0 ) ;
V_133 = F_82 ( V_2 , V_2 -> V_148 ) ;
}
return V_133 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_159 * V_160 = NULL ;
struct V_80 T_4 * V_81 ;
T_3 V_153 , V_16 ;
T_3 V_166 , V_161 ;
T_2 * V_162 ;
T_2 V_227 = 0 ;
T_2 V_176 ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_6 ( V_7 -> V_13 , L_26 ) ;
return 0 ;
}
V_160 = V_2 -> V_106 ;
V_81 = V_2 -> V_101 ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_153 & V_157 ;
while ( ! ( V_153 & V_85 ) && V_16 ) {
if ( V_227 )
break;
if ( ( V_153 & V_167 ) && ( V_153 & V_168 )
&& ! ( V_153 & V_169 ) ) {
F_65 ( V_160 ) ;
V_166 = ( T_3 ) F_66 ( F_56 ( & V_81 -> V_89 ) ) ;
F_67 ( V_160 , ( T_2 * ) V_166 ) ;
F_68 ( V_160 , ( V_16 - V_109 ) ) ;
F_69 ( V_160 , V_170 ) ;
switch ( V_153 & V_171 ) {
case V_173 :
F_70 ( V_160 , V_174 ) ; break;
default:
F_70 ( V_160 , V_175 ) ; break;
}
if ( F_60 ( V_160 ) & V_174 )
V_176 = 0x1 ;
else
V_176 = 0 ;
if ( V_176 != V_2 -> V_93 ) {
F_6 ( V_7 -> V_13 , L_12 ) ;
} else {
V_161 = F_61 ( V_160 ) ;
V_162 = ( T_2 * ) ( V_4 -> V_4 . V_89 ) + V_4 -> V_4 . V_22 ;
if ( V_162 ) {
memcpy ( V_162 , V_160 -> V_165 , V_161 ) ;
V_4 -> V_4 . V_22 += V_161 ;
if ( ( V_161 < V_2 -> V_2 . V_108 )
|| ( V_4 -> V_4 . V_22 >=
V_4 -> V_4 . V_16 ) ) {
V_227 = 1 ;
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_10 ( & V_2 -> V_9 ) )
F_17 ( V_2 ) ;
}
}
F_32 ( V_2 ) ;
}
} else {
F_39 ( V_7 -> V_13 , L_11 ) ;
}
F_28 ( ( T_3 T_4 * ) V_81 , ( V_153 & V_180 ) ) ;
V_2 -> V_54 -- ;
if ( V_153 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_153 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_153 & V_157 ;
}
V_2 -> V_101 = V_81 ;
F_58 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_45 == V_51 ) {
if ( V_2 -> V_54 <= 0 ) {
F_20 ( V_2 ) ;
} else {
F_91 ( V_2 , V_4 ) ;
}
}
return 0 ;
}
static int F_93 ( struct V_228 * V_229 ,
const struct V_131 * V_116 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_230 = 0 ;
unsigned char V_28 ;
V_2 = F_94 ( V_229 , struct V_1 , V_2 ) ;
if ( ! V_229 || ! V_116 || V_2 -> V_116 || V_229 -> V_21 == V_231 [ 0 ] ||
( V_116 -> V_232 != V_233 ) )
return - V_105 ;
V_7 = V_2 -> V_7 ;
if ( ! V_7 -> V_234 || ( V_7 -> V_12 . V_138 == V_235 ) )
return - V_20 ;
V_28 = ( T_2 ) V_116 -> V_117 & 0xF ;
V_230 = F_47 ( V_7 , V_28 , V_116 ) ;
if ( V_230 != 0 ) {
F_95 ( F_96 ( V_2 -> V_84 ) ) ;
F_74 ( V_7 -> V_13 , L_27 , V_2 -> V_28 ) ;
return - V_105 ;
}
F_74 ( V_7 -> V_13 , L_28 , V_2 -> V_28 ) ;
return 0 ;
}
static int F_97 ( struct V_228 * V_229 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
unsigned long V_132 ;
unsigned int V_103 ;
V_2 = F_94 ( V_229 , struct V_1 , V_2 ) ;
V_7 = V_2 -> V_7 ;
if ( ! V_229 || ! V_2 -> V_116 ) {
F_74 ( V_7 -> V_13 , L_29 , V_229 ? V_2 -> V_2 . V_21 : NULL ) ;
return - V_105 ;
}
F_49 ( & V_7 -> V_23 , V_132 ) ;
F_9 ( V_2 , - V_20 ) ;
V_2 -> V_116 = NULL ;
V_2 -> V_8 = 1 ;
V_2 -> V_206 = NULL ;
F_31 ( V_7 , V_2 -> V_28 ) ;
F_50 ( & V_7 -> V_23 , V_132 ) ;
F_95 ( F_96 ( V_2 -> V_84 ) ) ;
if ( V_2 -> V_33 == V_38 )
V_103 = ( V_2 -> V_2 . V_108 + V_109 + 2 ) *
( V_82 + 1 ) ;
else
V_103 = ( V_2 -> V_2 . V_108 + V_109 + 2 ) *
( V_83 + 1 ) ;
if ( V_2 -> V_33 != V_34 ) {
F_42 ( V_2 -> V_106 ) ;
if ( V_2 -> V_112 ) {
F_3 ( V_41 -> V_12 . V_13 . V_14 ,
V_2 -> V_111 , V_103 ,
V_18 ) ;
V_2 -> V_111 = V_19 ;
} else {
F_5 (
V_41 -> V_12 . V_13 . V_14 ,
V_2 -> V_111 , V_103 ,
V_18 ) ;
}
F_42 ( V_2 -> V_110 ) ;
}
if ( V_2 -> V_33 != V_38 )
F_42 ( V_2 -> V_148 ) ;
F_74 ( V_7 -> V_13 , L_30 , V_229 -> V_21 ) ;
return 0 ;
}
static struct V_236 * F_98 ( struct V_228 * V_229 , T_6 V_237 )
{
struct V_3 * V_4 ;
V_4 = F_41 ( sizeof( * V_4 ) , V_237 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_4 . V_15 = V_19 ;
F_99 ( & V_4 -> V_9 ) ;
return & V_4 -> V_4 ;
}
static void F_100 ( struct V_228 * V_229 , struct V_236 * V_238 )
{
struct V_3 * V_4 ;
V_4 = F_94 ( V_238 , struct V_3 , V_4 ) ;
if ( V_238 )
F_42 ( V_4 ) ;
}
static int F_101 ( struct V_228 * V_229 , struct V_236 * V_238 )
{
struct V_1 * V_2 = F_94 ( V_229 , struct V_1 , V_2 ) ;
struct V_3 * V_4 = F_94 ( V_238 , struct V_3 , V_4 ) ;
struct V_6 * V_7 ;
int V_133 ;
V_7 = V_2 -> V_7 ;
if ( ! V_238 || ! V_4 -> V_4 . V_24 || ! V_4 -> V_4 . V_89
|| ! F_10 ( & V_4 -> V_9 ) ) {
F_74 ( V_7 -> V_13 , L_31 ) ;
return - V_105 ;
}
if ( ! V_229 || ( ! V_2 -> V_116 && F_102 ( V_2 ) ) ) {
F_74 ( V_7 -> V_13 , L_32 ) ;
return - V_105 ;
}
if ( ! V_7 -> V_234 || V_7 -> V_12 . V_138 == V_235 )
return - V_20 ;
V_4 -> V_2 = V_2 ;
if ( V_4 -> V_4 . V_15 == V_19 ) {
V_4 -> V_4 . V_15 = F_44 ( V_2 -> V_7 -> V_12 . V_13 . V_14 ,
V_4 -> V_4 . V_89 ,
V_4 -> V_4 . V_16 ,
F_4 ( V_2 )
? V_17 :
V_18 ) ;
V_4 -> V_11 = 1 ;
} else {
F_45 ( V_2 -> V_7 -> V_12 . V_13 . V_14 ,
V_4 -> V_4 . V_15 , V_4 -> V_4 . V_16 ,
F_4 ( V_2 )
? V_17 :
V_18 ) ;
V_4 -> V_11 = 0 ;
}
V_4 -> V_4 . V_5 = - V_10 ;
V_4 -> V_4 . V_22 = 0 ;
F_103 ( & V_4 -> V_9 , & V_2 -> V_9 ) ;
F_6 ( V_7 -> V_13 , L_33 ,
V_2 -> V_21 , V_4 -> V_4 . V_16 ) ;
if ( F_4 ( V_2 ) )
V_133 = F_90 ( V_2 , V_4 ) ;
if ( F_102 ( V_2 ) == 0 && V_4 -> V_4 . V_16 > 0 ) {
if ( F_4 ( V_2 ) )
V_7 -> V_42 = V_218 ;
else
V_7 -> V_42 = V_219 ;
}
if ( V_2 -> V_33 == V_38 )
V_133 = F_92 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_104 ( struct V_228 * V_229 , struct V_236 * V_238 ,
T_6 V_237 )
{
struct V_1 * V_2 = F_94 ( V_229 , struct V_1 , V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_132 ;
int V_239 ;
F_49 ( & V_7 -> V_23 , V_132 ) ;
V_239 = F_101 ( V_229 , V_238 ) ;
F_50 ( & V_7 -> V_23 , V_132 ) ;
return V_239 ;
}
static int F_105 ( struct V_228 * V_229 , struct V_236 * V_238 )
{
struct V_1 * V_2 = F_94 ( V_229 , struct V_1 , V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_132 ;
if ( ! V_229 || ! V_238 )
return - V_105 ;
F_49 ( & V_2 -> V_7 -> V_23 , V_132 ) ;
F_106 (req, &ep->queue, queue) {
if ( & V_4 -> V_4 == V_238 )
break;
}
if ( & V_4 -> V_4 != V_238 ) {
F_50 ( & V_2 -> V_7 -> V_23 , V_132 ) ;
return - V_105 ;
}
F_1 ( V_2 , V_4 , - V_240 ) ;
F_50 ( & V_2 -> V_7 -> V_23 , V_132 ) ;
return 0 ;
}
static int F_107 ( struct V_228 * V_229 , int V_26 )
{
struct V_1 * V_2 ;
unsigned long V_132 ;
int V_5 = - V_241 ;
struct V_6 * V_7 ;
V_2 = F_94 ( V_229 , struct V_1 , V_2 ) ;
if ( ! V_229 || ! V_2 -> V_116 ) {
V_5 = - V_105 ;
goto V_242;
}
V_7 = V_2 -> V_7 ;
if ( V_26 && F_4 ( V_2 ) && ! F_10 ( & V_2 -> V_9 ) ) {
V_5 = - V_243 ;
goto V_242;
}
V_5 = 0 ;
F_49 ( & V_2 -> V_7 -> V_23 , V_132 ) ;
F_15 ( V_2 , V_26 ) ;
F_12 ( V_2 , V_26 ) ;
F_50 ( & V_2 -> V_7 -> V_23 , V_132 ) ;
if ( V_2 -> V_28 == 0 ) {
V_7 -> V_42 = V_43 ;
V_7 -> V_44 = 0 ;
}
if ( V_26 == 0 )
V_2 -> V_93 = 0 ;
V_242:
F_6 ( V_7 -> V_13 , L_34 , V_2 -> V_2 . V_21 ,
V_26 ? L_35 : L_36 , V_5 ) ;
return V_5 ;
}
static int F_108 ( struct V_244 * V_12 )
{
T_1 V_104 ;
V_104 = F_13 ( & V_41 -> V_245 -> V_246 ) ;
if ( V_104 & 0x8000 )
V_104 = V_104 & 0x07ff ;
else
V_104 = - V_105 ;
return ( int ) V_104 ;
}
static int F_109 ( struct V_244 * V_12 )
{
return - V_247 ;
}
static int F_110 ( struct V_244 * V_12 , int V_248 )
{
return - V_247 ;
}
static int F_111 ( struct V_244 * V_12 , unsigned V_249 )
{
return - V_247 ;
}
static int F_112 ( struct V_244 * V_12 , int V_250 )
{
return - V_247 ;
}
static int F_113 ( struct V_6 * V_7 , T_2 V_251 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_251 ] ;
F_9 ( V_2 , - V_240 ) ;
V_2 -> V_206 = NULL ;
return 0 ;
}
static int F_114 ( struct V_6 * V_7 )
{
T_2 V_251 ;
for ( V_251 = 0 ; V_251 < V_178 ; V_251 ++ )
F_113 ( V_7 , V_251 ) ;
F_7 ( & V_7 -> V_23 ) ;
V_7 -> V_234 -> V_252 ( & V_7 -> V_12 ) ;
F_8 ( & V_7 -> V_23 ) ;
return 0 ;
}
static void F_115 ( struct V_6 * V_7 , T_1 V_26 , T_1 V_253 ,
T_1 V_16 )
{
V_7 -> V_254 = ( T_2 ) V_26 ;
V_7 -> V_255 = V_256 ;
if ( F_83 ( V_7 , V_34 ) )
F_16 ( V_7 ) ;
}
static void F_116 ( struct V_228 * V_229 , struct V_236 * V_238 )
{
struct V_3 * V_4 = F_94 ( V_238 , struct V_3 , V_4 ) ;
V_4 -> V_4 . V_89 = NULL ;
F_42 ( V_4 ) ;
}
static void F_117 ( struct V_6 * V_7 , T_2 V_257 , T_1 V_26 ,
T_1 V_253 , T_1 V_16 )
{
T_1 V_258 = 0 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_5 = 0 ;
V_2 = & V_7 -> V_40 [ 0 ] ;
if ( ( V_257 & V_259 ) == V_260 ) {
V_258 = 1 << V_261 ;
} else if ( ( V_257 & V_259 ) == V_262 ) {
V_258 = 0 ;
} else if ( ( V_257 & V_259 ) == V_263 ) {
int V_251 = V_253 & V_118 ;
struct V_1 * V_264 = & V_7 -> V_40 [ V_251 ] ;
T_1 V_113 ;
if ( ! V_264 -> V_116 )
goto V_265;
V_113 = F_13 ( & V_7 -> V_29 -> V_30 [ V_251 ] ) ;
if ( V_253 & V_34 ) {
if ( V_264 -> V_33 != V_34 )
goto V_265;
if ( ( V_113 & V_36 ) == V_37 )
V_258 = 1 << V_266 ;
} else {
if ( V_264 -> V_33 != V_38 )
goto V_265;
if ( ( V_113 & V_31 ) == V_32 )
V_258 = 1 << V_266 ;
}
}
V_4 = F_94 ( F_98 ( & V_2 -> V_2 , V_267 ) ,
struct V_3 , V_4 ) ;
V_4 -> V_4 . V_16 = 2 ;
V_4 -> V_4 . V_89 = V_7 -> V_268 ;
* ( T_1 * ) V_4 -> V_4 . V_89 = F_118 ( V_258 ) ;
V_4 -> V_4 . V_5 = - V_10 ;
V_4 -> V_4 . V_22 = 0 ;
V_4 -> V_4 . V_24 = F_116 ;
V_7 -> V_44 = V_34 ;
V_5 = F_101 ( & V_2 -> V_2 , & V_4 -> V_4 ) ;
if ( V_5 == 0 )
return;
V_265:
F_39 ( V_7 -> V_13 , L_37 ) ;
F_16 ( V_7 ) ;
}
static void F_63 ( struct V_6 * V_7 ,
struct V_269 * V_270 )
{
T_1 V_271 = F_48 ( V_270 -> V_271 ) ;
T_1 V_272 = F_48 ( V_270 -> V_272 ) ;
T_1 V_273 = F_48 ( V_270 -> V_273 ) ;
F_113 ( V_7 , 0 ) ;
if ( V_270 -> V_274 & V_34 )
V_7 -> V_44 = V_34 ;
else
V_7 -> V_44 = V_38 ;
switch ( V_270 -> V_275 ) {
case V_276 :
if ( ( V_270 -> V_274 & ( V_34 | V_277 ) )
!= ( V_34 | V_278 ) )
break;
F_117 ( V_7 , V_270 -> V_274 , V_271 , V_272 ,
V_273 ) ;
return;
case V_279 :
if ( V_270 -> V_274 != ( V_38 | V_278 |
V_260 ) )
break;
F_115 ( V_7 , V_271 , V_272 , V_273 ) ;
return;
case V_280 :
case V_281 :
if ( ( V_270 -> V_274 & V_277 )
!= V_278 )
break;
if ( ( V_270 -> V_274 & V_259 )
== V_263 ) {
int V_251 = V_272 & V_118 ;
struct V_1 * V_2 ;
if ( V_271 != 0 || V_273 != 0
|| V_251 > V_178 )
break;
V_2 = & V_7 -> V_40 [ V_251 ] ;
F_7 ( & V_7 -> V_23 ) ;
F_107 ( & V_2 -> V_2 ,
( V_270 -> V_275 == V_281 )
? 1 : 0 ) ;
F_8 ( & V_7 -> V_23 ) ;
}
F_83 ( V_7 , V_34 ) ;
return;
default:
break;
}
if ( V_273 ) {
if ( V_270 -> V_274 & V_34 ) {
V_7 -> V_42 = V_218 ;
V_7 -> V_44 = V_34 ;
} else {
V_7 -> V_42 = V_219 ;
V_7 -> V_44 = V_38 ;
}
F_7 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_234 -> V_270 ( & V_7 -> V_12 ,
& V_7 -> V_164 ) < 0 )
F_16 ( V_7 ) ;
F_8 ( & V_7 -> V_23 ) ;
} else {
V_7 -> V_44 = V_34 ;
F_7 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_234 -> V_270 ( & V_7 -> V_12 ,
& V_7 -> V_164 ) < 0 )
F_16 ( V_7 ) ;
F_8 ( & V_7 -> V_23 ) ;
V_7 -> V_42 = V_200 ;
}
}
static void F_119 ( struct V_6 * V_7 )
{
V_7 -> V_282 = V_7 -> V_255 ;
V_7 -> V_255 = V_283 ;
if ( V_7 -> V_234 -> V_284 )
V_7 -> V_234 -> V_284 ( & V_7 -> V_12 ) ;
}
static void F_120 ( struct V_6 * V_7 )
{
V_7 -> V_255 = V_7 -> V_282 ;
V_7 -> V_282 = 0 ;
if ( V_7 -> V_234 -> V_285 )
V_7 -> V_234 -> V_285 ( & V_7 -> V_12 ) ;
}
static void F_121 ( struct V_6 * V_7 )
{
T_2 V_286 ;
V_286 = F_122 ( & V_7 -> V_29 -> V_287 ) ;
if ( V_286 & V_288 ) {
if ( ( V_7 -> V_255 ) != V_283 )
F_119 ( V_7 ) ;
} else {
if ( V_7 -> V_255 == V_283 )
F_120 ( V_7 ) ;
}
}
static int F_123 ( struct V_6 * V_7 )
{
unsigned char V_65 ;
if ( V_7 -> V_255 == V_289 )
return 0 ;
F_53 () ;
F_27 ( & V_7 -> V_29 -> V_290 , 0 ) ;
for ( V_65 = 0 ; V_65 < V_178 ; V_65 ++ ) {
if ( V_7 -> V_40 [ V_65 ] . V_144 )
F_31 ( V_7 , V_65 ) ;
}
F_114 ( V_7 ) ;
V_7 -> V_255 = V_289 ;
V_7 -> V_42 = V_43 ;
V_7 -> V_44 = V_38 ;
F_51 () ;
return 0 ;
}
static int F_124 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_125 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_126 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_80 T_4 * V_81 ;
int V_65 , V_291 = 0 ;
if ( ( V_7 -> V_255 == V_256 )
&& ( F_122 ( & V_7 -> V_29 -> V_290 ) == 0 ) )
F_27 ( & V_7 -> V_29 -> V_290 , V_7 -> V_254 ) ;
for ( V_65 = ( V_178 - 1 ) ; ( ( V_65 >= 0 ) && ( V_291 == 0 ) ) ; V_65 -- ) {
V_2 = & V_7 -> V_40 [ V_65 ] ;
if ( V_2 && V_2 -> V_144 && ( V_2 -> V_33 != V_38 ) ) {
V_81 = V_2 -> V_74 ;
if ( ! ( F_56 ( ( T_3 T_4 * ) V_81 ) & V_192 )
&& ( F_56 ( & V_81 -> V_89 ) ) ) {
if ( V_2 -> V_28 == 0 )
V_291 = F_87 ( V_2 ) ;
else
V_291 = F_89 ( V_2 ) ;
}
}
}
return V_291 ;
}
static void F_127 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_80 T_4 * V_81 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_178 ; V_65 ++ ) {
V_2 = & V_7 -> V_40 [ V_65 ] ;
if ( V_2 && V_2 -> V_144 && ( V_2 -> V_33 != V_34 ) ) {
V_81 = V_2 -> V_101 ;
if ( ! ( F_56 ( ( T_3 T_4 * ) V_81 ) & V_85 )
&& ( F_56 ( & V_81 -> V_89 ) ) ) {
if ( V_2 -> V_28 == 0 ) {
F_64 ( V_7 ) ;
} else {
F_75 ( V_2 ) ;
}
}
}
}
}
static T_7 F_128 ( int V_292 , void * V_293 )
{
struct V_6 * V_7 = (struct V_6 * ) V_293 ;
T_1 V_294 ;
T_7 V_5 = V_295 ;
unsigned long V_132 ;
F_49 ( & V_7 -> V_23 , V_132 ) ;
V_294 = F_13 ( & V_7 -> V_29 -> V_53 ) &
F_13 ( & V_7 -> V_29 -> V_48 ) ;
F_14 ( & V_7 -> V_29 -> V_53 , V_294 ) ;
if ( V_294 & V_296 ) {
F_121 ( V_7 ) ;
V_294 &= ~ V_296 ;
V_5 = V_297 ;
}
if ( V_294 & V_190 ) {
F_126 ( V_7 ) ;
V_294 &= ~ V_190 ;
V_5 = V_297 ;
}
if ( V_294 & V_49 ) {
F_127 ( V_7 ) ;
V_294 &= ~ V_49 ;
V_5 = V_297 ;
}
if ( V_294 & V_298 ) {
F_123 ( V_7 ) ;
V_294 &= ~ V_298 ;
V_5 = V_297 ;
}
if ( V_294 & V_50 ) {
F_124 ( V_7 ) ;
V_294 &= ~ V_50 ;
V_5 = V_297 ;
}
if ( V_294 & V_191 ) {
F_125 ( V_7 ) ;
V_294 &= ~ V_191 ;
V_5 = V_297 ;
}
F_50 ( & V_7 -> V_23 , V_132 ) ;
return V_5 ;
}
static int F_129 ( struct V_299 * V_234 ,
int (* F_130)( struct V_244 * ) )
{
int V_230 ;
unsigned long V_132 = 0 ;
if ( ! V_41 )
return - V_150 ;
if ( ! V_234 || ( V_234 -> V_138 != V_141
&& V_234 -> V_138 != V_139 )
|| ! F_130 || ! V_234 -> V_252 || ! V_234 -> V_270 )
return - V_105 ;
if ( V_41 -> V_234 )
return - V_204 ;
F_49 ( & V_41 -> V_23 , V_132 ) ;
V_234 -> V_234 . V_300 = NULL ;
V_41 -> V_234 = V_234 ;
V_41 -> V_12 . V_13 . V_234 = & V_234 -> V_234 ;
V_41 -> V_12 . V_138 = (enum V_301 ) ( V_234 -> V_138 ) ;
F_50 ( & V_41 -> V_23 , V_132 ) ;
V_230 = F_130 ( & V_41 -> V_12 ) ;
if ( V_230 ) {
F_39 ( V_41 -> V_13 , L_38 ,
V_234 -> V_234 . V_21 , V_230 ) ;
V_41 -> V_12 . V_13 . V_234 = NULL ;
V_41 -> V_234 = NULL ;
return V_230 ;
}
F_51 () ;
F_14 ( & V_41 -> V_29 -> V_53 , 0xffff ) ;
F_14 ( & V_41 -> V_29 -> V_48 , V_302 ) ;
V_41 -> V_255 = V_303 ;
V_41 -> V_42 = V_43 ;
V_41 -> V_44 = V_38 ;
F_131 ( V_41 -> V_13 , L_39 ,
V_41 -> V_12 . V_21 , V_234 -> V_234 . V_21 ) ;
return 0 ;
}
static int F_132 ( struct V_299 * V_234 )
{
struct V_1 * V_304 ;
unsigned long V_132 ;
if ( ! V_41 )
return - V_150 ;
if ( ! V_234 || V_234 != V_41 -> V_234 )
return - V_105 ;
F_53 () ;
V_41 -> V_255 = V_303 ;
V_41 -> V_42 = V_43 ;
V_41 -> V_44 = 0 ;
F_49 ( & V_41 -> V_23 , V_132 ) ;
V_41 -> V_12 . V_138 = V_235 ;
F_9 ( & V_41 -> V_40 [ 0 ] , - V_20 ) ;
F_106 (loop_ep, &udc_controller->gadget.ep_list,
ep.ep_list)
F_9 ( V_304 , - V_20 ) ;
F_50 ( & V_41 -> V_23 , V_132 ) ;
V_234 -> V_252 ( & V_41 -> V_12 ) ;
V_234 -> V_305 ( & V_41 -> V_12 ) ;
V_41 -> V_12 . V_13 . V_234 = NULL ;
V_41 -> V_234 = NULL ;
F_131 ( V_41 -> V_13 , L_40 ,
V_234 -> V_234 . V_21 ) ;
return 0 ;
}
static struct V_6 T_8 * F_133 ( struct V_306 * V_307 )
{
struct V_6 * V_7 ;
struct V_308 * V_309 = V_307 -> V_13 . V_310 ;
unsigned int V_94 = 0 ;
struct V_311 T_4 * V_312 ;
unsigned int V_65 ;
T_9 V_103 ;
T_3 V_313 ;
V_7 = F_41 ( sizeof( * V_7 ) , V_267 ) ;
if ( V_7 == NULL ) {
F_39 ( & V_307 -> V_13 , L_41 ) ;
goto V_314;
}
V_7 -> V_13 = & V_307 -> V_13 ;
V_313 = * F_134 ( V_309 , 1 , & V_103 , NULL ) ;
V_7 -> V_245 = F_36 ( V_313 ) ;
F_135 ( V_7 -> V_245 , 0 , V_103 ) ;
V_312 = V_7 -> V_245 ;
F_14 ( & V_312 -> V_246 , 0 ) ;
F_28 ( & V_312 -> V_315 , 0 ) ;
V_94 = F_34 ( ( V_178 *
sizeof( struct V_95 ) ) ,
V_316 ) ;
if ( F_35 ( V_94 ) )
goto V_314;
for ( V_65 = 0 ; V_65 < V_178 ; V_65 ++ ) {
F_14 ( & V_312 -> V_317 [ V_65 ] , ( T_1 ) V_94 ) ;
V_7 -> V_69 [ V_65 ] = F_36 ( V_94 ) ;
V_94 += 32 ;
}
F_135 ( V_7 -> V_69 [ 0 ] , 0 ,
V_178 * sizeof( struct V_95 ) ) ;
V_7 -> V_282 = V_318 ;
V_7 -> V_255 = V_319 ;
V_7 -> V_44 = 0 ;
F_136 ( & V_7 -> V_23 ) ;
return V_7 ;
V_314:
F_42 ( V_7 ) ;
return NULL ;
}
static int T_8 F_137 ( struct V_6 * V_7 )
{
struct V_320 T_4 * V_321 ;
V_321 = V_7 -> V_29 ;
F_27 ( & V_321 -> V_151 , 0x01 ) ;
F_27 ( & V_321 -> V_151 , 0x00 ) ;
F_14 ( & V_321 -> V_48 , 0 ) ;
F_27 ( & V_321 -> V_66 , 0 ) ;
F_14 ( & V_321 -> V_53 , V_322 ) ;
return 0 ;
}
static int T_8 F_138 ( struct V_6 * V_7 , unsigned char V_78 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_78 ] ;
V_2 -> V_7 = V_7 ;
strcpy ( V_2 -> V_21 , V_231 [ V_78 ] ) ;
V_2 -> V_2 . V_21 = V_231 [ V_78 ] ;
V_2 -> V_2 . V_323 = & V_324 ;
V_2 -> V_8 = 1 ;
V_2 -> V_2 . V_108 = ( unsigned short ) ~ 0 ;
V_2 -> V_116 = NULL ;
V_2 -> V_33 = 0xff ;
V_2 -> V_28 = ( T_2 ) V_78 ;
V_2 -> V_209 = 0 ;
V_2 -> V_211 = 0 ;
V_2 -> V_144 = 0 ;
V_2 -> V_106 = NULL ;
V_2 -> V_148 = NULL ;
V_2 -> V_206 = NULL ;
V_2 -> V_45 = V_46 ;
V_2 -> V_54 = 0 ;
F_99 ( & V_2 -> V_9 ) ;
if ( V_78 != 0 )
F_103 ( & V_2 -> V_2 . V_325 , & V_7 -> V_12 . V_325 ) ;
V_2 -> V_12 = & V_7 -> V_12 ;
return 0 ;
}
static void F_139 ( struct V_326 * V_13 )
{
int V_65 = 0 ;
V_24 ( V_41 -> F_1 ) ;
F_95 ( F_96 ( V_41 -> V_69 [ 0 ] ) ) ;
for ( V_65 = 0 ; V_65 < V_178 ; V_65 ++ )
V_41 -> V_69 [ V_65 ] = NULL ;
F_42 ( V_41 ) ;
V_41 = NULL ;
}
static int T_8 F_140 ( struct V_306 * V_307 )
{
const struct V_327 * V_328 ;
struct V_308 * V_309 = V_307 -> V_13 . V_310 ;
struct V_1 * V_2 ;
unsigned int V_239 = 0 ;
unsigned int V_65 ;
const void * V_329 ;
V_328 = F_141 ( V_330 , & V_307 -> V_13 ) ;
if ( ! V_328 )
return - V_105 ;
V_329 = F_142 ( V_309 , L_42 , NULL ) ;
if ( ! V_329 || strcmp ( V_329 , L_43 ) )
return - V_150 ;
V_41 = F_133 ( V_307 ) ;
if ( ! V_41 ) {
F_39 ( & V_307 -> V_13 , L_44 ) ;
return - V_98 ;
}
V_41 -> V_55 = ( unsigned long ) V_328 -> V_165 ;
V_41 -> V_29 = F_143 ( V_309 , 0 ) ;
if ( ! V_41 -> V_29 ) {
V_239 = - V_98 ;
goto V_331;
}
F_137 ( V_41 ) ;
V_41 -> V_12 . V_323 = & V_332 ;
V_41 -> V_12 . V_333 = & V_41 -> V_40 [ 0 ] . V_2 ;
F_99 ( & V_41 -> V_12 . V_325 ) ;
V_41 -> V_12 . V_138 = V_235 ;
V_41 -> V_12 . V_21 = V_334 ;
F_144 ( & V_41 -> V_12 . V_13 ) ;
F_145 ( & V_41 -> V_12 . V_13 , L_45 ) ;
V_41 -> V_12 . V_13 . V_335 = F_139 ;
V_41 -> V_12 . V_13 . V_14 = & V_307 -> V_13 ;
for ( V_65 = 0 ; V_65 < V_178 ; V_65 ++ ) {
F_138 ( V_41 , ( unsigned char ) V_65 ) ;
}
V_239 = F_47 ( V_41 , 0 , & V_336 ) ;
if ( V_239 )
goto V_337;
V_41 -> V_193 = F_41 ( 256 , V_267 ) ;
if ( V_41 -> V_193 == NULL ) {
F_39 ( V_41 -> V_13 , L_46 ) ;
V_239 = - V_98 ;
goto V_338;
}
V_41 -> V_268 = F_41 ( 2 , V_267 ) ;
if ( V_41 -> V_268 == NULL ) {
V_239 = - V_98 ;
goto V_339;
}
V_41 -> V_340 = F_43 ( ( void * ) V_41 -> V_193 ) ;
if ( V_41 -> V_340 == V_19 ) {
V_41 -> V_340 = F_44 (
V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_193 ,
256 ,
V_17 ) ;
V_41 -> V_341 = 1 ;
} else {
F_45 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_340 , 256 ,
V_17 ) ;
}
F_146 ( & V_41 -> V_185 , F_73 ,
( unsigned long ) V_41 ) ;
V_41 -> V_342 = F_147 ( V_309 , 0 ) ;
if ( ! V_41 -> V_342 ) {
V_239 = - V_105 ;
goto V_343;
}
V_239 = F_148 ( V_41 -> V_342 , F_128 , 0 ,
V_334 , V_41 ) ;
if ( V_239 ) {
F_39 ( V_41 -> V_13 , L_47 ,
V_41 -> V_342 , V_239 ) ;
goto V_344;
}
V_239 = F_149 ( & V_41 -> V_12 . V_13 ) ;
if ( V_239 )
goto V_345;
V_239 = F_150 ( & V_307 -> V_13 , & V_41 -> V_12 ) ;
if ( V_239 )
goto V_346;
F_131 ( V_41 -> V_13 ,
L_48 ,
( V_41 -> V_55 == V_347 ) ? L_49 : L_50 ) ;
return 0 ;
V_346:
F_151 ( & V_41 -> V_12 . V_13 ) ;
V_345:
F_152 ( V_41 -> V_342 , V_41 ) ;
V_344:
F_153 ( V_41 -> V_342 ) ;
V_343:
if ( V_41 -> V_341 ) {
F_3 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_340 , 256 ,
V_17 ) ;
V_41 -> V_340 = V_19 ;
} else {
F_5 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_340 , 256 ,
V_17 ) ;
}
F_42 ( V_41 -> V_268 ) ;
V_339:
F_42 ( V_41 -> V_193 ) ;
V_338:
V_2 = & V_41 -> V_40 [ 0 ] ;
F_95 ( F_96 ( V_2 -> V_84 ) ) ;
F_42 ( V_2 -> V_106 ) ;
F_42 ( V_2 -> V_110 ) ;
F_42 ( V_2 -> V_148 ) ;
V_337:
F_154 ( V_41 -> V_29 ) ;
V_331:
F_42 ( V_41 ) ;
V_41 = NULL ;
return V_239 ;
}
static int F_155 ( struct V_306 * V_13 , T_10 V_45 )
{
return - V_247 ;
}
static int F_156 ( struct V_306 * V_13 )
{
return - V_247 ;
}
static int T_11 F_157 ( struct V_306 * V_307 )
{
struct V_1 * V_2 ;
unsigned int V_103 ;
F_158 ( F_1 ) ;
if ( ! V_41 )
return - V_150 ;
F_159 ( & V_41 -> V_12 ) ;
V_41 -> F_1 = & F_1 ;
F_160 ( & V_41 -> V_185 ) ;
if ( V_41 -> V_341 ) {
F_3 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_340 , 256 ,
V_17 ) ;
V_41 -> V_340 = V_19 ;
} else {
F_5 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_340 , 256 ,
V_17 ) ;
}
F_42 ( V_41 -> V_268 ) ;
F_42 ( V_41 -> V_193 ) ;
V_2 = & V_41 -> V_40 [ 0 ] ;
F_95 ( F_96 ( V_2 -> V_84 ) ) ;
V_103 = ( V_2 -> V_2 . V_108 + V_109 + 2 ) * ( V_83 + 1 ) ;
F_42 ( V_2 -> V_106 ) ;
if ( V_2 -> V_112 ) {
F_3 ( V_41 -> V_12 . V_13 . V_14 ,
V_2 -> V_111 , V_103 ,
V_18 ) ;
V_2 -> V_111 = V_19 ;
} else {
F_5 ( V_41 -> V_12 . V_13 . V_14 ,
V_2 -> V_111 , V_103 ,
V_18 ) ;
}
F_42 ( V_2 -> V_110 ) ;
F_42 ( V_2 -> V_148 ) ;
F_152 ( V_41 -> V_342 , V_41 ) ;
F_153 ( V_41 -> V_342 ) ;
F_161 ( & V_41 -> V_185 ) ;
F_154 ( V_41 -> V_29 ) ;
F_151 ( & V_41 -> V_12 . V_13 ) ;
F_162 ( & F_1 ) ;
return 0 ;
}
static int T_12 F_163 ( void )
{
F_164 ( V_348 L_51 , V_334 , V_349 ,
V_350 ) ;
return F_165 ( & V_351 ) ;
}
static void T_13 F_166 ( void )
{
F_167 ( & V_351 ) ;
}
