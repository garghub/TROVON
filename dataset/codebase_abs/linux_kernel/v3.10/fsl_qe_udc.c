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
V_7 -> V_41 = V_42 ;
V_7 -> V_43 = 0 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_28 = V_2 -> V_28 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_44 == V_45 ) {
F_18 ( & V_7 -> V_29 -> V_30 [ V_28 ] ,
V_31 , V_46 ) ;
F_19 ( & V_7 -> V_29 -> V_47 ,
( V_48 | V_49 ) ) ;
V_2 -> V_44 = V_50 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_44 == V_50 ) {
F_18 ( & V_7 -> V_29 -> V_30 [ V_2 -> V_28 ] ,
V_51 , V_39 ) ;
F_14 ( & V_7 -> V_29 -> V_52 ,
V_49 | V_48 ) ;
F_21 ( & V_7 -> V_29 -> V_47 ,
( V_48 | V_49 ) ) ;
V_2 -> V_44 = V_45 ;
V_2 -> V_53 = 0 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 -> V_54 == V_55 )
F_23 ( V_56 | ( V_2 -> V_28 << V_57 ) ,
V_58 ) ;
else
F_24 ( V_59 , V_60 ,
V_2 -> V_28 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 -> V_54 == V_55 )
F_23 ( V_61 | ( V_2 -> V_28 <<
V_57 ) , V_62 ) ;
else
F_24 ( V_63 , V_60 ,
V_2 -> V_28 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_64 ;
V_64 = ( int ) V_2 -> V_28 ;
F_22 ( V_2 ) ;
F_27 ( & V_7 -> V_29 -> V_65 ,
V_66 | ( V_67 & ( V_2 -> V_28 ) ) ) ;
F_14 ( & V_7 -> V_68 [ V_64 ] -> V_69 , F_13 ( & V_7 -> V_68 [ V_64 ] -> V_70 ) ) ;
F_28 ( & V_7 -> V_68 [ V_64 ] -> V_71 , 0 ) ;
F_14 ( & V_7 -> V_68 [ V_64 ] -> V_72 , 0 ) ;
V_2 -> V_73 = V_2 -> V_74 ;
V_2 -> V_75 = V_2 -> V_74 ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_27 ( & V_7 -> V_29 -> V_65 ,
V_76 | ( V_67 & ( V_2 -> V_28 ) ) ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 , int V_77 )
{
struct V_1 * V_2 ;
T_3 V_78 ;
struct V_79 T_4 * V_80 ;
int V_64 ;
V_2 = & V_7 -> V_40 [ V_77 ] ;
if ( V_2 -> V_33 == V_38 )
V_78 = V_81 ;
else
V_78 = V_82 ;
V_80 = V_2 -> V_83 ;
for ( V_64 = 0 ; V_64 < ( V_78 - 1 ) ; V_64 ++ ) {
F_28 ( ( T_3 T_4 * ) V_80 , V_84 | V_85 ) ;
V_80 ++ ;
}
F_28 ( ( T_3 T_4 * ) V_80 , V_84 | V_85 | V_86 ) ;
V_80 = V_2 -> V_74 ;
for ( V_64 = 0 ; V_64 < V_87 - 1 ; V_64 ++ ) {
F_28 ( & V_80 -> V_88 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_80 , 0 ) ;
V_80 ++ ;
}
F_28 ( ( T_3 T_4 * ) V_80 , V_89 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , int V_77 )
{
struct V_1 * V_2 ;
T_1 V_90 ;
V_2 = & V_7 -> V_40 [ V_77 ] ;
V_90 = F_13 ( & V_7 -> V_29 -> V_30 [ V_77 ] ) ;
V_90 &= ~ V_51 ;
switch ( V_2 -> V_33 ) {
case V_91 :
F_26 ( V_2 ) ;
break;
case V_38 :
V_90 |= V_39 ;
break;
case V_34 :
F_26 ( V_2 ) ;
V_90 |= V_35 ;
break;
default:
break;
}
F_14 ( & V_7 -> V_29 -> V_30 [ V_77 ] , V_90 ) ;
F_30 ( V_7 , V_77 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
V_2 -> V_92 ^= 0x1 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , unsigned char V_77 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_77 ] ;
unsigned long V_93 = 0 ;
struct V_94 T_4 * V_95 ;
int V_64 ;
struct V_79 T_4 * V_80 ;
int V_78 ;
if ( V_2 -> V_33 == V_38 )
V_78 = V_81 ;
else
V_78 = V_82 ;
V_95 = V_7 -> V_68 [ V_77 ] ;
V_93 = F_34 ( sizeof( struct V_79 ) * ( V_78 +
V_87 ) , V_96 ) ;
if ( F_35 ( V_93 ) )
return - V_97 ;
F_14 ( & V_95 -> V_98 , ( T_1 ) V_93 ) ;
F_14 ( & V_95 -> V_70 , ( T_1 ) ( V_93 +
( sizeof( struct V_79 ) * V_78 ) ) ) ;
F_14 ( & V_95 -> V_99 , F_13 ( & V_95 -> V_98 ) ) ;
F_14 ( & V_95 -> V_69 , F_13 ( & V_95 -> V_70 ) ) ;
V_2 -> V_83 = F_36 ( V_93 ) ;
V_2 -> V_74 = F_36 ( V_93 + ( sizeof( struct V_79 )
* V_78 ) ) ;
V_2 -> V_100 = V_2 -> V_83 ;
V_2 -> V_101 = V_2 -> V_83 ;
V_2 -> V_75 = V_2 -> V_74 ;
V_2 -> V_73 = V_2 -> V_74 ;
V_2 -> V_92 = 0 ;
V_80 = V_2 -> V_83 ;
for ( V_64 = 0 ; V_64 < V_78 - 1 ; V_64 ++ ) {
F_28 ( & V_80 -> V_88 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_80 , 0 ) ;
V_80 ++ ;
}
F_28 ( & V_80 -> V_88 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_80 , V_86 ) ;
V_80 = V_2 -> V_74 ;
for ( V_64 = 0 ; V_64 < V_87 - 1 ; V_64 ++ ) {
F_28 ( & V_80 -> V_88 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_80 , 0 ) ;
V_80 ++ ;
}
F_28 ( & V_80 -> V_88 , 0 ) ;
F_28 ( ( T_3 T_4 * ) V_80 , V_89 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned int V_102 ;
int V_64 ;
unsigned int V_103 ;
struct V_79 T_4 * V_80 ;
unsigned int V_78 ;
if ( V_2 -> V_83 == NULL )
return - V_104 ;
V_80 = V_2 -> V_83 ;
V_2 -> V_105 = F_38 ( sizeof( * V_2 -> V_105 ) , V_106 ) ;
if ( V_2 -> V_105 == NULL ) {
F_39 ( V_2 -> V_7 -> V_13 , L_2 ) ;
return - V_97 ;
}
F_40 ( V_2 -> V_105 ) ;
if ( V_2 -> V_33 == V_38 )
V_78 = V_81 ;
else
V_78 = V_82 ;
V_102 = ( V_2 -> V_2 . V_107 + V_108 + 2 ) * ( V_78 + 1 ) ;
V_2 -> V_109 = F_41 ( V_102 , V_106 ) ;
if ( V_2 -> V_109 == NULL ) {
F_39 ( V_2 -> V_7 -> V_13 , L_3 ,
V_102 ) ;
F_42 ( V_2 -> V_105 ) ;
return - V_97 ;
}
V_2 -> V_110 = F_43 ( ( void * ) V_2 -> V_109 ) ;
if ( V_2 -> V_110 == V_19 ) {
V_2 -> V_110 = F_44 ( V_2 -> V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_109 ,
V_102 ,
V_18 ) ;
V_2 -> V_111 = 1 ;
} else {
F_45 ( V_2 -> V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_110 , V_102 ,
V_18 ) ;
V_2 -> V_111 = 0 ;
}
V_102 = V_2 -> V_2 . V_107 + V_108 + 2 ;
V_103 = V_2 -> V_110 ;
V_103 = ( T_3 ) ( ( ( V_103 >> 2 ) << 2 ) + 4 ) ;
for ( V_64 = 0 ; V_64 < V_78 - 1 ; V_64 ++ ) {
F_28 ( & V_80 -> V_88 , V_103 ) ;
F_28 ( ( T_3 T_4 * ) V_80 , ( V_84 | V_85 ) ) ;
V_103 = V_103 + V_102 ;
V_80 ++ ;
}
F_28 ( & V_80 -> V_88 , V_103 ) ;
F_28 ( ( T_3 T_4 * ) V_80 , ( V_84 | V_85 | V_86 ) ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_7 , unsigned char V_77 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_77 ] ;
struct V_94 T_4 * V_95 ;
T_1 V_112 , V_113 ;
T_1 V_103 ;
T_2 V_114 = 0 ;
V_95 = V_7 -> V_68 [ V_77 ] ;
V_112 = 0 ;
V_113 = ( V_2 -> V_2 . V_115 -> V_116 & V_117 ) ;
V_112 |= ( V_113 << V_118 ) ;
switch ( V_2 -> V_2 . V_115 -> V_119 & 0x03 ) {
case V_120 :
V_112 |= V_121 ;
break;
case V_122 :
V_112 |= V_123 ;
break;
case V_124 :
V_112 |= V_125 ;
break;
default:
V_112 |= V_126 ;
break;
}
switch ( V_2 -> V_33 ) {
case V_38 :
V_112 |= V_39 ;
break;
case V_34 :
V_112 |= V_35 ;
break;
default:
break;
}
F_14 ( & V_7 -> V_29 -> V_30 [ V_77 ] , V_112 ) ;
V_114 = 0x30 ;
F_27 ( & V_95 -> V_127 , V_114 ) ;
F_27 ( & V_95 -> V_128 , V_114 ) ;
V_103 = ( T_1 ) ( V_2 -> V_2 . V_107 + V_108 ) ;
V_103 = ( T_1 ) ( ( ( V_103 >> 2 ) << 2 ) + 4 ) ;
F_14 ( & V_95 -> V_129 , V_103 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 ,
unsigned char V_77 ,
const struct V_130 * V_115 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_77 ] ;
unsigned long V_131 ;
int V_132 = 0 ;
T_1 V_133 = 0 ;
V_133 = F_48 ( V_115 ) ;
if ( V_77 != 0 ) {
switch ( V_115 -> V_119 & V_134 ) {
case V_120 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_135;
switch ( V_7 -> V_12 . V_136 ) {
case V_137 :
if ( ( V_133 == 128 ) || ( V_133 == 256 ) || ( V_133 == 512 ) )
break;
default:
switch ( V_133 ) {
case 4 :
case 8 :
case 16 :
case 32 :
case 64 :
break;
default:
case V_138 :
goto V_135;
}
}
break;
case V_124 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 ) )
goto V_135;
switch ( V_7 -> V_12 . V_136 ) {
case V_137 :
if ( V_133 <= 1024 )
break;
case V_139 :
if ( V_133 <= 64 )
break;
default:
if ( V_133 <= 8 )
break;
goto V_135;
}
break;
case V_122 :
if ( strstr ( V_2 -> V_2 . V_21 , L_6 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_135;
switch ( V_7 -> V_12 . V_136 ) {
case V_137 :
if ( V_133 <= 1024 )
break;
case V_139 :
if ( V_133 <= 1023 )
break;
default:
goto V_135;
}
break;
case V_140 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_135;
switch ( V_7 -> V_12 . V_136 ) {
case V_137 :
case V_139 :
switch ( V_133 ) {
case 1 :
case 2 :
case 4 :
case 8 :
case 16 :
case 32 :
case 64 :
break;
default:
goto V_135;
}
case V_138 :
switch ( V_133 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
goto V_135;
}
default:
goto V_135;
}
break;
default:
goto V_135;
}
}
F_49 ( & V_7 -> V_23 , V_131 ) ;
V_2 -> V_2 . V_107 = V_133 ;
V_2 -> V_141 = ( T_2 ) ( V_115 -> V_119 & V_134 ) ;
V_2 -> V_2 . V_115 = V_115 ;
V_2 -> V_8 = 0 ;
V_2 -> V_142 = 1 ;
if ( V_77 == 0 ) {
V_2 -> V_33 = V_91 ;
V_7 -> V_43 = V_38 ;
V_7 -> V_41 = V_42 ;
} else {
switch ( V_115 -> V_116 & V_143 ) {
case V_38 :
V_2 -> V_33 = V_38 ;
break;
case V_34 :
V_2 -> V_33 = V_34 ;
default:
break;
}
}
F_33 ( V_7 , V_77 ) ;
if ( ( V_2 -> V_141 == V_144 ) || ( V_2 -> V_33 == V_38 ) ) {
V_132 = F_37 ( V_2 ) ;
if ( V_132 )
goto V_145;
}
if ( ( V_2 -> V_141 == V_144 ) || ( V_2 -> V_33 == V_34 ) ) {
V_2 -> V_146 = F_38 ( sizeof( * V_2 -> V_146 ) , V_106 ) ;
if ( V_2 -> V_146 == NULL ) {
F_39 ( V_7 -> V_13 , L_7 ) ;
goto V_147;
}
F_40 ( V_2 -> V_146 ) ;
}
F_46 ( V_7 , V_77 ) ;
F_50 ( & V_7 -> V_23 , V_131 ) ;
return 0 ;
V_147:
F_42 ( V_2 -> V_109 ) ;
F_42 ( V_2 -> V_105 ) ;
V_145:
F_50 ( & V_7 -> V_23 , V_131 ) ;
V_135:
F_39 ( V_7 -> V_13 , L_8 , V_2 -> V_2 . V_21 ) ;
return - V_148 ;
}
static inline void F_51 ( struct V_6 * V_7 )
{
F_52 ( & V_7 -> V_29 -> V_149 , V_150 ) ;
}
static inline void F_53 ( struct V_6 * V_7 )
{
F_54 ( & V_7 -> V_29 -> V_149 , V_150 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_3 V_151 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_2 -> V_101 ) ;
V_151 = V_85 | V_84 | ( V_151 & V_86 ) ;
F_28 ( ( T_3 T_4 * ) V_2 -> V_101 , V_151 ) ;
if ( V_151 & V_86 )
V_2 -> V_101 = V_2 -> V_83 ;
else
V_2 -> V_101 ++ ;
}
static void F_57 ( struct V_1 * V_2 , unsigned char V_152 )
{
T_3 V_151 ;
struct V_79 T_4 * V_80 , * V_153 ;
unsigned char V_154 = 0 ;
V_153 = V_2 -> V_100 ;
V_80 = V_2 -> V_101 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
while ( ! ( V_151 & V_84 ) && ! ( V_151 & V_155 ) && ! V_154 ) {
V_151 = V_84 | V_85 | ( V_151 & V_86 ) ;
F_28 ( ( T_3 T_4 * ) V_80 , V_151 ) ;
if ( V_151 & V_86 )
V_80 = V_2 -> V_83 ;
else
V_80 ++ ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
if ( V_152 && ( V_80 == V_153 ) )
V_154 = 1 ;
}
V_2 -> V_101 = V_80 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_79 T_4 * V_80 = V_2 -> V_100 ;
T_3 V_151 ;
T_2 V_28 = V_2 -> V_28 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
if ( ! ( V_151 & V_84 ) && ! ( V_151 & V_155 ) ) {
V_80 = V_2 -> V_83 +
( ( F_13 ( & V_7 -> V_68 [ V_28 ] -> V_99 ) -
F_13 ( & V_7 -> V_68 [ V_28 ] -> V_98 ) )
>> 3 ) ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
if ( V_151 & V_86 )
V_80 = V_2 -> V_83 ;
else
V_80 ++ ;
V_2 -> V_101 = V_80 ;
F_57 ( V_2 , 0 ) ;
V_2 -> V_101 = V_2 -> V_100 ;
} else
F_57 ( V_2 , 1 ) ;
if ( F_13 ( & V_7 -> V_29 -> V_52 ) & V_49 )
F_14 ( & V_7 -> V_29 -> V_52 , V_49 ) ;
if ( V_2 -> V_53 <= 0 && ( ! F_10 ( & V_2 -> V_9 ) ) )
F_20 ( V_2 ) ;
V_2 -> V_156 = 0 ;
}
static int F_59 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
struct V_157 * V_158 ;
unsigned int V_159 ;
T_2 * V_160 ;
V_158 = V_2 -> V_105 ;
if ( ( F_60 ( V_158 ) & V_161 )
&& ( V_7 -> V_41 == V_42 ) ) {
V_159 = F_61 ( V_158 ) ;
if ( F_62 ( V_159 != 8 ) )
return - V_104 ;
V_160 = ( T_2 * ) & V_7 -> V_162 ;
memcpy ( V_160 , V_158 -> V_163 , V_159 ) ;
V_2 -> V_92 = 1 ;
F_63 ( V_7 , & V_7 -> V_162 ) ;
return 0 ;
}
return - V_104 ;
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
struct V_157 * V_158 ;
struct V_79 T_4 * V_80 ;
T_3 V_151 , V_16 ;
T_3 V_164 ;
V_158 = V_2 -> V_105 ;
if ( V_2 -> V_33 == V_34 ) {
F_39 ( V_7 -> V_13 , L_9 ) ;
return - V_104 ;
}
V_80 = V_2 -> V_100 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
V_16 = V_151 & V_155 ;
while ( ! ( V_151 & V_84 ) && V_16 ) {
if ( ( V_151 & V_165 ) && ( V_151 & V_166 )
&& ! ( V_151 & V_167 ) ) {
if ( V_16 == V_108 ) {
V_7 -> V_41 = V_42 ;
F_6 ( V_7 -> V_13 ,
L_10 ) ;
} else {
F_65 ( V_158 ) ;
V_164 = ( T_3 ) F_66 ( F_56 ( & V_80 -> V_88 ) ) ;
F_67 ( V_158 , ( T_2 * ) V_164 ) ;
F_68 ( V_158 ,
( V_16 - V_108 ) ) ;
F_69 ( V_158 , V_168 ) ;
switch ( V_151 & V_169 ) {
case V_170 :
F_70 ( V_158 , V_161 ) ;
break;
case V_171 :
F_70 ( V_158 , V_172 ) ;
break;
default:
F_70 ( V_158 , V_173 ) ;
break;
}
if ( ( V_151 & V_169 ) == V_170 )
F_59 ( V_7 ) ;
else
F_71 ( V_2 ) ;
}
} else {
F_39 ( V_7 -> V_13 , L_11 ) ;
}
F_55 ( V_2 ) ;
if ( V_151 & V_86 )
V_80 = V_2 -> V_83 ;
else
V_80 ++ ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
V_16 = V_151 & V_155 ;
}
V_2 -> V_100 = V_80 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_157 * V_158 ;
T_2 V_174 = 0 ;
unsigned int V_159 ;
T_2 * V_160 ;
struct V_3 * V_4 ;
V_158 = V_2 -> V_105 ;
if ( F_60 ( V_158 ) & V_172 )
V_174 = 0x1 ;
if ( V_174 != V_2 -> V_92 ) {
F_39 ( V_2 -> V_7 -> V_13 , L_12 ) ;
return - V_175 ;
}
V_159 = F_61 ( V_158 ) ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_39 ( V_2 -> V_7 -> V_13 , L_13 , V_2 -> V_21 ) ;
} else {
V_4 = F_11 ( V_2 -> V_9 . V_25 , struct V_3 , V_9 ) ;
V_160 = ( T_2 * ) ( V_4 -> V_4 . V_88 ) + V_4 -> V_4 . V_22 ;
if ( V_160 ) {
memcpy ( V_160 , V_158 -> V_163 , V_159 ) ;
V_4 -> V_4 . V_22 += V_159 ;
if ( ( V_159 < V_2 -> V_2 . V_107 ) ||
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
static void F_73 ( unsigned long V_163 )
{
struct V_6 * V_7 = (struct V_6 * ) V_163 ;
struct V_1 * V_2 ;
struct V_157 * V_158 ;
struct V_79 T_4 * V_80 ;
unsigned long V_131 ;
T_3 V_151 , V_16 ;
T_3 V_164 , V_64 ;
F_49 ( & V_7 -> V_23 , V_131 ) ;
for ( V_64 = 1 ; V_64 < V_176 ; V_64 ++ ) {
V_2 = & V_7 -> V_40 [ V_64 ] ;
if ( V_2 -> V_33 == V_34 || V_2 -> V_177 == 0 ) {
F_74 ( V_7 -> V_13 ,
L_14 ) ;
continue;
}
V_158 = V_2 -> V_105 ;
V_80 = V_2 -> V_100 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
V_16 = V_151 & V_155 ;
while ( ! ( V_151 & V_84 ) && V_16 ) {
if ( F_10 ( & V_2 -> V_9 ) ) {
F_17 ( V_2 ) ;
F_74 ( V_7 -> V_13 ,
L_15 ,
V_2 -> V_53 ) ;
break;
}
if ( ( V_151 & V_165 ) && ( V_151 & V_166 )
&& ! ( V_151 & V_167 ) ) {
F_65 ( V_158 ) ;
V_164 = ( T_3 ) F_66 ( F_56 ( & V_80 -> V_88 ) ) ;
F_67 ( V_158 , ( T_2 * ) V_164 ) ;
F_68 ( V_158 ,
( V_16 - V_108 ) ) ;
F_69 ( V_158 , V_168 ) ;
switch ( V_151 & V_169 ) {
case V_171 :
F_70 ( V_158 , V_172 ) ;
break;
case V_170 :
F_70 ( V_158 , V_161 ) ;
break;
default:
F_70 ( V_158 , V_173 ) ;
break;
}
F_71 ( V_2 ) ;
} else {
F_39 ( V_7 -> V_13 ,
L_16 ) ;
}
F_28 ( ( T_3 T_4 * ) V_80 , V_151 & V_178 ) ;
V_2 -> V_53 -- ;
if ( ! ( V_2 -> V_156 ) )
F_55 ( V_2 ) ;
if ( V_151 & V_86 )
V_80 = V_2 -> V_83 ;
else
V_80 ++ ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
V_16 = V_151 & V_155 ;
}
V_2 -> V_100 = V_80 ;
if ( V_2 -> V_156 )
F_58 ( V_2 ) ;
V_2 -> V_177 = 0 ;
}
F_50 ( & V_7 -> V_23 , V_131 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_157 * V_158 ;
struct V_79 T_4 * V_80 ;
T_1 V_179 , V_180 , V_181 ;
V_7 = V_2 -> V_7 ;
V_158 = V_2 -> V_105 ;
if ( V_2 -> V_33 == V_34 ) {
F_39 ( V_7 -> V_13 , L_17 ) ;
return - V_104 ;
}
V_80 = V_2 -> V_100 ;
V_179 = ( T_1 ) ( V_80 - V_2 -> V_83 ) ;
V_180 = ( T_1 ) ( ( F_13 ( & V_7 -> V_68 [ V_2 -> V_28 ] -> V_99 ) -
F_13 ( & V_7 -> V_68 [ V_2 -> V_28 ] -> V_98 ) ) >> 3 ) ;
if ( V_179 < V_180 )
V_181 = V_81 - V_180 + V_179 ;
else
V_181 = V_179 - V_180 ;
if ( V_181 < V_182 ) {
F_17 ( V_2 ) ;
V_2 -> V_156 = 1 ;
F_6 ( V_7 -> V_13 , L_18 , V_181 ) ;
}
V_2 -> V_53 = V_81 - V_181 ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_17 ( V_2 ) ;
F_6 ( V_7 -> V_13 , L_19 ,
V_2 -> V_53 ) ;
return 0 ;
}
F_76 ( & V_7 -> V_183 ) ;
V_2 -> V_177 = 1 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_157 * V_184 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_79 T_4 * V_80 ;
T_1 V_185 ;
T_3 V_151 , V_186 ;
T_3 V_187 ;
if ( V_2 -> V_33 == V_38 ) {
F_39 ( V_7 -> V_13 , L_20 ) ;
return - V_104 ;
}
V_185 = F_13 ( & V_7 -> V_29 -> V_47 ) ;
F_14 ( & V_7 -> V_29 -> V_47 ,
V_185 & ~ ( V_188 | V_189 ) ) ;
V_80 = V_2 -> V_75 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
if ( ! ( V_151 & ( V_190 | V_155 ) ) ) {
if ( F_61 ( V_184 ) == 0 ) {
F_67 ( V_184 , V_7 -> V_191 ) ;
F_68 ( V_184 , 2 ) ;
V_184 -> V_192 |= ( V_193 | V_194 ) ;
F_6 ( V_7 -> V_13 , L_21 ) ;
}
V_187 = F_43 ( ( void * ) V_184 -> V_163 ) ;
F_28 ( & V_80 -> V_88 , V_187 ) ;
V_151 = ( V_151 & V_89 ) ;
if ( ! ( F_60 ( V_184 ) & V_194 ) )
V_151 |= V_190 | V_195 | V_196 | V_197
| F_61 ( V_184 ) ;
else
V_151 |= V_190 | V_195 | V_196 | F_61 ( V_184 ) ;
if ( ( V_2 -> V_28 == 0 ) && ( V_7 -> V_41 == V_198 ) )
V_2 -> V_92 = 0x1 ;
if ( V_2 -> V_92 ) {
V_186 = V_199 ;
V_184 -> V_192 |= V_172 ;
} else {
V_186 = V_200 ;
V_184 -> V_192 |= V_173 ;
}
V_151 |= V_201 ;
V_151 |= V_186 ;
F_28 ( ( T_3 T_4 * ) V_80 , V_151 ) ;
F_29 ( V_2 ) ;
F_14 ( & V_7 -> V_29 -> V_47 , V_185 ) ;
F_32 ( V_2 ) ;
if ( V_151 & V_89 )
V_2 -> V_75 = V_2 -> V_74 ;
else
V_2 -> V_75 ++ ;
return 0 ;
} else {
F_14 ( & V_7 -> V_29 -> V_47 , V_185 ) ;
F_6 ( V_7 -> V_13 , L_22 ) ;
return - V_202 ;
}
}
static int F_78 ( struct V_1 * V_2 , unsigned char V_203 )
{
if ( V_2 -> V_204 != NULL ) {
struct V_3 * V_4 = V_2 -> V_204 ;
unsigned V_205 = 0 , V_206 = 0 ;
V_206 = F_79 ( unsigned , V_4 -> V_4 . V_16 - V_2 -> V_207 ,
V_2 -> V_2 . V_107 ) ;
if ( ! V_203 ) {
int V_208 = V_2 -> V_209 ;
V_2 -> V_207 += V_208 ;
V_2 -> V_209 -= V_208 ;
} else {
V_2 -> V_209 = 0 ;
}
if ( V_4 -> V_4 . V_210 ) {
if ( V_206 == 0 ||
( V_4 -> V_4 . V_16 % V_2 -> V_2 . V_107 ) != 0 )
V_205 = 0 ;
else
V_205 = 1 ;
} else
V_205 = 0 ;
if ( ( ( V_2 -> V_204 -> V_4 . V_16 - V_2 -> V_207 ) <= 0 ) && ! V_205 ) {
F_1 ( V_2 , V_2 -> V_204 , 0 ) ;
V_2 -> V_204 = NULL ;
V_2 -> V_209 = 0 ;
V_2 -> V_207 = 0 ;
}
}
if ( V_2 -> V_204 == NULL ) {
if ( ! F_10 ( & V_2 -> V_9 ) ) {
V_2 -> V_204 = F_11 ( V_2 -> V_9 . V_25 , struct V_3 ,
V_9 ) ;
V_2 -> V_209 = 0 ;
V_2 -> V_207 = 0 ;
}
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_157 * V_184 )
{
unsigned int V_102 ;
T_2 * V_88 ;
F_65 ( V_184 ) ;
V_102 = F_79 ( T_3 , ( V_2 -> V_204 -> V_4 . V_16 - V_2 -> V_207 ) ,
V_2 -> V_2 . V_107 ) ;
V_88 = ( T_2 * ) V_2 -> V_204 -> V_4 . V_88 + V_2 -> V_207 ;
if ( V_88 && V_102 ) {
V_2 -> V_209 = V_102 ;
V_2 -> V_204 -> V_4 . V_22 += V_102 ;
F_67 ( V_184 , V_88 ) ;
F_68 ( V_184 , V_102 ) ;
F_69 ( V_184 , V_168 ) ;
F_70 ( V_184 , 0 ) ;
return F_77 ( V_2 , V_184 ) ;
}
return - V_175 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_157 * V_184 , T_5 V_211 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_184 == NULL )
return - V_148 ;
F_65 ( V_184 ) ;
F_67 ( V_184 , ( T_2 * ) V_7 -> V_191 ) ;
F_68 ( V_184 , 2 ) ;
F_69 ( V_184 , V_168 ) ;
F_70 ( V_184 , ( V_193 | V_194 | V_211 ) ) ;
return F_77 ( V_2 , V_184 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_157 * V_184 )
{
struct V_3 * V_4 = V_2 -> V_204 ;
int V_132 ;
if ( V_4 == NULL )
return - V_148 ;
if ( ( V_4 -> V_4 . V_16 - V_2 -> V_207 ) > 0 )
V_132 = F_80 ( V_2 , V_184 ) ;
else
V_132 = F_81 ( V_2 , V_184 , 0 ) ;
return V_132 ;
}
static int F_83 ( struct V_6 * V_7 , int V_212 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
if ( V_212 == V_34 ) {
V_7 -> V_41 = V_198 ;
V_7 -> V_43 = V_34 ;
F_81 ( V_2 , V_2 -> V_146 , V_213 | V_214 ) ;
} else {
V_7 -> V_43 = V_38 ;
V_7 -> V_41 = V_215 ;
}
return 0 ;
}
static void F_72 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
switch ( V_7 -> V_41 ) {
case V_216 :
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_83 ( V_7 , V_38 ) )
F_16 ( V_7 ) ;
break;
case V_198 :
F_1 ( V_2 , V_4 , 0 ) ;
V_7 -> V_41 = V_42 ;
break;
case V_217 :
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_83 ( V_7 , V_34 ) )
F_16 ( V_7 ) ;
break;
case V_215 :
F_1 ( V_2 , V_4 , 0 ) ;
V_7 -> V_41 = V_42 ;
break;
case V_42 :
F_6 ( V_7 -> V_13 , L_23 ) ;
break;
default:
F_16 ( V_7 ) ;
break;
}
}
static int F_84 ( struct V_1 * V_2 , unsigned char V_203 )
{
struct V_3 * V_204 = NULL ;
struct V_157 * V_184 = V_2 -> V_146 ;
if ( ( F_60 ( V_184 ) & ( V_193 | V_214 ) ) == ( V_193 | V_214 ) ) {
if ( ! V_203 )
V_2 -> V_7 -> V_41 = V_42 ;
else
F_81 ( V_2 , V_2 -> V_146 , V_213 | V_214 ) ;
return 0 ;
}
V_204 = V_2 -> V_204 ;
if ( V_204 != NULL ) {
if ( ! V_203 ) {
int V_208 = V_2 -> V_209 ;
V_2 -> V_207 += V_208 ;
V_2 -> V_209 -= V_208 ;
} else {
V_2 -> V_209 = 0 ;
}
if ( ( V_2 -> V_204 -> V_4 . V_16 - V_2 -> V_207 ) <= 0 ) {
V_2 -> V_204 -> V_4 . V_22 = ( unsigned int ) V_2 -> V_207 ;
F_72 ( V_2 -> V_7 , V_2 -> V_204 ) ;
V_2 -> V_204 = NULL ;
V_2 -> V_209 = 0 ;
V_2 -> V_207 = 0 ;
}
} else {
F_6 ( V_2 -> V_7 -> V_13 , L_24 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_146 ) & V_218 ) {
F_26 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_13 , L_25 ) ;
if ( F_60 ( V_2 -> V_146 ) & V_173 )
V_2 -> V_92 = 0 ;
else
V_2 -> V_92 = 1 ;
F_84 ( V_2 , 1 ) ;
} else
F_84 ( V_2 , 0 ) ;
F_82 ( V_2 , V_2 -> V_146 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_79 T_4 * V_80 ;
struct V_157 * V_158 ;
T_3 V_151 ;
V_80 = V_2 -> V_73 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
while ( ! ( V_151 & V_190 ) && ( V_151 & ~ V_89 ) ) {
V_158 = V_2 -> V_146 ;
F_28 ( ( T_3 T_4 * ) V_80 , V_151 & V_89 ) ;
F_28 ( & V_80 -> V_88 , 0 ) ;
if ( V_151 & V_89 )
V_2 -> V_73 = V_2 -> V_74 ;
else
V_2 -> V_73 ++ ;
if ( V_2 -> V_73 == V_2 -> V_75 ) {
if ( V_151 & V_219 ) {
F_69 ( V_158 , V_218 ) ;
if ( V_151 & V_220 )
V_158 -> V_5 |= V_221 ;
if ( V_151 & V_222 )
V_158 -> V_5 |= V_223 ;
}
F_85 ( V_2 ) ;
}
V_80 = V_2 -> V_73 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_146 ) & V_218 ) {
F_26 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_13 , L_25 ) ;
if ( F_60 ( V_2 -> V_146 ) & V_173 )
V_2 -> V_92 = 0 ;
else
V_2 -> V_92 = 1 ;
F_78 ( V_2 , 1 ) ;
} else
F_78 ( V_2 , 0 ) ;
F_82 ( V_2 , V_2 -> V_146 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_79 T_4 * V_80 ;
struct V_157 * V_158 = NULL ;
T_3 V_151 ;
unsigned char V_224 = 0 ;
V_80 = V_2 -> V_73 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
while ( ! ( V_151 & V_190 ) && ( V_151 & ~ V_89 ) ) {
V_158 = V_2 -> V_146 ;
if ( V_151 & V_219 ) {
F_69 ( V_158 , V_218 ) ;
if ( V_151 & V_220 )
V_158 -> V_5 |= V_221 ;
if ( V_151 & V_222 )
V_158 -> V_5 |= V_223 ;
}
F_28 ( ( T_3 T_4 * ) V_80 , V_151 & V_89 ) ;
F_28 ( & V_80 -> V_88 , 0 ) ;
if ( V_151 & V_89 )
V_2 -> V_73 = V_2 -> V_74 ;
else
V_2 -> V_73 ++ ;
F_88 ( V_2 ) ;
V_80 = V_2 -> V_73 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
}
if ( V_224 )
return - V_175 ;
else
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_132 = 0 ;
if ( V_2 -> V_204 == NULL ) {
V_2 -> V_207 = 0 ;
V_2 -> V_209 = 0 ;
F_78 ( V_2 , 0 ) ;
V_132 = F_82 ( V_2 , V_2 -> V_146 ) ;
}
return V_132 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_157 * V_158 = NULL ;
struct V_79 T_4 * V_80 ;
T_3 V_151 , V_16 ;
T_3 V_164 , V_159 ;
T_2 * V_160 ;
T_2 V_225 = 0 ;
T_2 V_174 ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_6 ( V_7 -> V_13 , L_26 ) ;
return 0 ;
}
V_158 = V_2 -> V_105 ;
V_80 = V_2 -> V_100 ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
V_16 = V_151 & V_155 ;
while ( ! ( V_151 & V_84 ) && V_16 ) {
if ( V_225 )
break;
if ( ( V_151 & V_165 ) && ( V_151 & V_166 )
&& ! ( V_151 & V_167 ) ) {
F_65 ( V_158 ) ;
V_164 = ( T_3 ) F_66 ( F_56 ( & V_80 -> V_88 ) ) ;
F_67 ( V_158 , ( T_2 * ) V_164 ) ;
F_68 ( V_158 , ( V_16 - V_108 ) ) ;
F_69 ( V_158 , V_168 ) ;
switch ( V_151 & V_169 ) {
case V_171 :
F_70 ( V_158 , V_172 ) ; break;
default:
F_70 ( V_158 , V_173 ) ; break;
}
if ( F_60 ( V_158 ) & V_172 )
V_174 = 0x1 ;
else
V_174 = 0 ;
if ( V_174 != V_2 -> V_92 ) {
F_6 ( V_7 -> V_13 , L_12 ) ;
} else {
V_159 = F_61 ( V_158 ) ;
V_160 = ( T_2 * ) ( V_4 -> V_4 . V_88 ) + V_4 -> V_4 . V_22 ;
if ( V_160 ) {
memcpy ( V_160 , V_158 -> V_163 , V_159 ) ;
V_4 -> V_4 . V_22 += V_159 ;
if ( ( V_159 < V_2 -> V_2 . V_107 )
|| ( V_4 -> V_4 . V_22 >=
V_4 -> V_4 . V_16 ) ) {
V_225 = 1 ;
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
F_28 ( ( T_3 T_4 * ) V_80 , ( V_151 & V_178 ) ) ;
V_2 -> V_53 -- ;
if ( V_151 & V_86 )
V_80 = V_2 -> V_83 ;
else
V_80 ++ ;
V_151 = F_56 ( ( T_3 T_4 * ) V_80 ) ;
V_16 = V_151 & V_155 ;
}
V_2 -> V_100 = V_80 ;
F_58 ( V_2 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_44 == V_50 ) {
if ( V_2 -> V_53 <= 0 ) {
F_20 ( V_2 ) ;
} else {
F_91 ( V_2 , V_4 ) ;
}
}
return 0 ;
}
static int F_93 ( struct V_226 * V_227 ,
const struct V_130 * V_115 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_228 = 0 ;
unsigned char V_28 ;
V_2 = F_94 ( V_227 , struct V_1 , V_2 ) ;
if ( ! V_227 || ! V_115 || V_227 -> V_21 == V_229 [ 0 ] ||
( V_115 -> V_230 != V_231 ) )
return - V_104 ;
V_7 = V_2 -> V_7 ;
if ( ! V_7 -> V_232 || ( V_7 -> V_12 . V_136 == V_233 ) )
return - V_20 ;
V_28 = ( T_2 ) V_115 -> V_116 & 0xF ;
V_228 = F_47 ( V_7 , V_28 , V_115 ) ;
if ( V_228 != 0 ) {
F_95 ( F_96 ( V_2 -> V_83 ) ) ;
F_74 ( V_7 -> V_13 , L_27 , V_2 -> V_28 ) ;
return - V_104 ;
}
F_74 ( V_7 -> V_13 , L_28 , V_2 -> V_28 ) ;
return 0 ;
}
static int F_97 ( struct V_226 * V_227 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
unsigned long V_131 ;
unsigned int V_102 ;
V_2 = F_94 ( V_227 , struct V_1 , V_2 ) ;
V_7 = V_2 -> V_7 ;
if ( ! V_227 || ! V_2 -> V_2 . V_115 ) {
F_74 ( V_7 -> V_13 , L_29 , V_227 ? V_2 -> V_2 . V_21 : NULL ) ;
return - V_104 ;
}
F_49 ( & V_7 -> V_23 , V_131 ) ;
F_9 ( V_2 , - V_20 ) ;
V_2 -> V_2 . V_115 = NULL ;
V_2 -> V_8 = 1 ;
V_2 -> V_204 = NULL ;
F_31 ( V_7 , V_2 -> V_28 ) ;
F_50 ( & V_7 -> V_23 , V_131 ) ;
F_95 ( F_96 ( V_2 -> V_83 ) ) ;
if ( V_2 -> V_33 == V_38 )
V_102 = ( V_2 -> V_2 . V_107 + V_108 + 2 ) *
( V_81 + 1 ) ;
else
V_102 = ( V_2 -> V_2 . V_107 + V_108 + 2 ) *
( V_82 + 1 ) ;
if ( V_2 -> V_33 != V_34 ) {
F_42 ( V_2 -> V_105 ) ;
if ( V_2 -> V_111 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_110 , V_102 ,
V_18 ) ;
V_2 -> V_110 = V_19 ;
} else {
F_5 (
V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_110 , V_102 ,
V_18 ) ;
}
F_42 ( V_2 -> V_109 ) ;
}
if ( V_2 -> V_33 != V_38 )
F_42 ( V_2 -> V_146 ) ;
F_74 ( V_7 -> V_13 , L_30 , V_227 -> V_21 ) ;
return 0 ;
}
static struct V_234 * F_98 ( struct V_226 * V_227 , T_6 V_235 )
{
struct V_3 * V_4 ;
V_4 = F_41 ( sizeof( * V_4 ) , V_235 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_4 . V_15 = V_19 ;
F_99 ( & V_4 -> V_9 ) ;
return & V_4 -> V_4 ;
}
static void F_100 ( struct V_226 * V_227 , struct V_234 * V_236 )
{
struct V_3 * V_4 ;
V_4 = F_94 ( V_236 , struct V_3 , V_4 ) ;
if ( V_236 )
F_42 ( V_4 ) ;
}
static int F_101 ( struct V_226 * V_227 , struct V_234 * V_236 )
{
struct V_1 * V_2 = F_94 ( V_227 , struct V_1 , V_2 ) ;
struct V_3 * V_4 = F_94 ( V_236 , struct V_3 , V_4 ) ;
struct V_6 * V_7 ;
int V_132 ;
V_7 = V_2 -> V_7 ;
if ( ! V_236 || ! V_4 -> V_4 . V_24 || ! V_4 -> V_4 . V_88
|| ! F_10 ( & V_4 -> V_9 ) ) {
F_74 ( V_7 -> V_13 , L_31 ) ;
return - V_104 ;
}
if ( ! V_227 || ( ! V_2 -> V_2 . V_115 && F_102 ( V_2 ) ) ) {
F_74 ( V_7 -> V_13 , L_32 ) ;
return - V_104 ;
}
if ( ! V_7 -> V_232 || V_7 -> V_12 . V_136 == V_233 )
return - V_20 ;
V_4 -> V_2 = V_2 ;
if ( V_4 -> V_4 . V_15 == V_19 ) {
V_4 -> V_4 . V_15 = F_44 ( V_2 -> V_7 -> V_12 . V_13 . V_14 ,
V_4 -> V_4 . V_88 ,
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
V_132 = F_90 ( V_2 , V_4 ) ;
if ( F_102 ( V_2 ) == 0 && V_4 -> V_4 . V_16 > 0 ) {
if ( F_4 ( V_2 ) )
V_7 -> V_41 = V_216 ;
else
V_7 -> V_41 = V_217 ;
}
if ( V_2 -> V_33 == V_38 )
V_132 = F_92 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_104 ( struct V_226 * V_227 , struct V_234 * V_236 ,
T_6 V_235 )
{
struct V_1 * V_2 = F_94 ( V_227 , struct V_1 , V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_131 ;
int V_237 ;
F_49 ( & V_7 -> V_23 , V_131 ) ;
V_237 = F_101 ( V_227 , V_236 ) ;
F_50 ( & V_7 -> V_23 , V_131 ) ;
return V_237 ;
}
static int F_105 ( struct V_226 * V_227 , struct V_234 * V_236 )
{
struct V_1 * V_2 = F_94 ( V_227 , struct V_1 , V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_131 ;
if ( ! V_227 || ! V_236 )
return - V_104 ;
F_49 ( & V_2 -> V_7 -> V_23 , V_131 ) ;
F_106 (req, &ep->queue, queue) {
if ( & V_4 -> V_4 == V_236 )
break;
}
if ( & V_4 -> V_4 != V_236 ) {
F_50 ( & V_2 -> V_7 -> V_23 , V_131 ) ;
return - V_104 ;
}
F_1 ( V_2 , V_4 , - V_238 ) ;
F_50 ( & V_2 -> V_7 -> V_23 , V_131 ) ;
return 0 ;
}
static int F_107 ( struct V_226 * V_227 , int V_26 )
{
struct V_1 * V_2 ;
unsigned long V_131 ;
int V_5 = - V_239 ;
struct V_6 * V_7 ;
V_2 = F_94 ( V_227 , struct V_1 , V_2 ) ;
if ( ! V_227 || ! V_2 -> V_2 . V_115 ) {
V_5 = - V_104 ;
goto V_240;
}
V_7 = V_2 -> V_7 ;
if ( V_26 && F_4 ( V_2 ) && ! F_10 ( & V_2 -> V_9 ) ) {
V_5 = - V_241 ;
goto V_240;
}
V_5 = 0 ;
F_49 ( & V_2 -> V_7 -> V_23 , V_131 ) ;
F_15 ( V_2 , V_26 ) ;
F_12 ( V_2 , V_26 ) ;
F_50 ( & V_2 -> V_7 -> V_23 , V_131 ) ;
if ( V_2 -> V_28 == 0 ) {
V_7 -> V_41 = V_42 ;
V_7 -> V_43 = 0 ;
}
if ( V_26 == 0 )
V_2 -> V_92 = 0 ;
V_240:
F_6 ( V_7 -> V_13 , L_34 , V_2 -> V_2 . V_21 ,
V_26 ? L_35 : L_36 , V_5 ) ;
return V_5 ;
}
static int F_108 ( struct V_242 * V_12 )
{
struct V_6 * V_7 = F_94 ( V_12 , struct V_6 , V_12 ) ;
T_1 V_103 ;
V_103 = F_13 ( & V_7 -> V_243 -> V_244 ) ;
if ( V_103 & 0x8000 )
V_103 = V_103 & 0x07ff ;
else
V_103 = - V_104 ;
return ( int ) V_103 ;
}
static int F_109 ( struct V_6 * V_7 , T_2 V_245 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_245 ] ;
F_9 ( V_2 , - V_238 ) ;
V_2 -> V_204 = NULL ;
return 0 ;
}
static int F_110 ( struct V_6 * V_7 )
{
T_2 V_245 ;
for ( V_245 = 0 ; V_245 < V_176 ; V_245 ++ )
F_109 ( V_7 , V_245 ) ;
F_7 ( & V_7 -> V_23 ) ;
V_7 -> V_232 -> V_246 ( & V_7 -> V_12 ) ;
F_8 ( & V_7 -> V_23 ) ;
return 0 ;
}
static void F_111 ( struct V_6 * V_7 , T_1 V_26 , T_1 V_247 ,
T_1 V_16 )
{
V_7 -> V_248 = ( T_2 ) V_26 ;
V_7 -> V_249 = V_250 ;
if ( F_83 ( V_7 , V_34 ) )
F_16 ( V_7 ) ;
}
static void F_112 ( struct V_226 * V_227 , struct V_234 * V_236 )
{
struct V_3 * V_4 = F_94 ( V_236 , struct V_3 , V_4 ) ;
V_4 -> V_4 . V_88 = NULL ;
F_42 ( V_4 ) ;
}
static void F_113 ( struct V_6 * V_7 , T_2 V_251 , T_1 V_26 ,
T_1 V_247 , T_1 V_16 )
{
T_1 V_252 = 0 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_5 = 0 ;
V_2 = & V_7 -> V_40 [ 0 ] ;
if ( ( V_251 & V_253 ) == V_254 ) {
V_252 = 1 << V_255 ;
} else if ( ( V_251 & V_253 ) == V_256 ) {
V_252 = 0 ;
} else if ( ( V_251 & V_253 ) == V_257 ) {
int V_245 = V_247 & V_117 ;
struct V_1 * V_258 = & V_7 -> V_40 [ V_245 ] ;
T_1 V_112 ;
if ( ! V_258 -> V_2 . V_115 )
goto V_259;
V_112 = F_13 ( & V_7 -> V_29 -> V_30 [ V_245 ] ) ;
if ( V_247 & V_34 ) {
if ( V_258 -> V_33 != V_34 )
goto V_259;
if ( ( V_112 & V_36 ) == V_37 )
V_252 = 1 << V_260 ;
} else {
if ( V_258 -> V_33 != V_38 )
goto V_259;
if ( ( V_112 & V_31 ) == V_32 )
V_252 = 1 << V_260 ;
}
}
V_4 = F_94 ( F_98 ( & V_2 -> V_2 , V_261 ) ,
struct V_3 , V_4 ) ;
V_4 -> V_4 . V_16 = 2 ;
V_4 -> V_4 . V_88 = V_7 -> V_262 ;
* ( T_1 * ) V_4 -> V_4 . V_88 = F_114 ( V_252 ) ;
V_4 -> V_4 . V_5 = - V_10 ;
V_4 -> V_4 . V_22 = 0 ;
V_4 -> V_4 . V_24 = F_112 ;
V_7 -> V_43 = V_34 ;
V_5 = F_101 ( & V_2 -> V_2 , & V_4 -> V_4 ) ;
if ( V_5 == 0 )
return;
V_259:
F_39 ( V_7 -> V_13 , L_37 ) ;
F_16 ( V_7 ) ;
}
static void F_63 ( struct V_6 * V_7 ,
struct V_263 * V_264 )
{
T_1 V_265 = F_115 ( V_264 -> V_265 ) ;
T_1 V_266 = F_115 ( V_264 -> V_266 ) ;
T_1 V_267 = F_115 ( V_264 -> V_267 ) ;
F_109 ( V_7 , 0 ) ;
if ( V_264 -> V_268 & V_34 )
V_7 -> V_43 = V_34 ;
else
V_7 -> V_43 = V_38 ;
switch ( V_264 -> V_269 ) {
case V_270 :
if ( ( V_264 -> V_268 & ( V_34 | V_271 ) )
!= ( V_34 | V_272 ) )
break;
F_113 ( V_7 , V_264 -> V_268 , V_265 , V_266 ,
V_267 ) ;
return;
case V_273 :
if ( V_264 -> V_268 != ( V_38 | V_272 |
V_254 ) )
break;
F_111 ( V_7 , V_265 , V_266 , V_267 ) ;
return;
case V_274 :
case V_275 :
if ( ( V_264 -> V_268 & V_271 )
!= V_272 )
break;
if ( ( V_264 -> V_268 & V_253 )
== V_257 ) {
int V_245 = V_266 & V_117 ;
struct V_1 * V_2 ;
if ( V_265 != 0 || V_267 != 0
|| V_245 > V_176 )
break;
V_2 = & V_7 -> V_40 [ V_245 ] ;
F_7 ( & V_7 -> V_23 ) ;
F_107 ( & V_2 -> V_2 ,
( V_264 -> V_269 == V_275 )
? 1 : 0 ) ;
F_8 ( & V_7 -> V_23 ) ;
}
F_83 ( V_7 , V_34 ) ;
return;
default:
break;
}
if ( V_267 ) {
if ( V_264 -> V_268 & V_34 ) {
V_7 -> V_41 = V_216 ;
V_7 -> V_43 = V_34 ;
} else {
V_7 -> V_41 = V_217 ;
V_7 -> V_43 = V_38 ;
}
F_7 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_232 -> V_264 ( & V_7 -> V_12 ,
& V_7 -> V_162 ) < 0 )
F_16 ( V_7 ) ;
F_8 ( & V_7 -> V_23 ) ;
} else {
V_7 -> V_43 = V_34 ;
F_7 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_232 -> V_264 ( & V_7 -> V_12 ,
& V_7 -> V_162 ) < 0 )
F_16 ( V_7 ) ;
F_8 ( & V_7 -> V_23 ) ;
V_7 -> V_41 = V_198 ;
}
}
static void F_116 ( struct V_6 * V_7 )
{
V_7 -> V_276 = V_7 -> V_249 ;
V_7 -> V_249 = V_277 ;
if ( V_7 -> V_232 -> V_278 )
V_7 -> V_232 -> V_278 ( & V_7 -> V_12 ) ;
}
static void F_117 ( struct V_6 * V_7 )
{
V_7 -> V_249 = V_7 -> V_276 ;
V_7 -> V_276 = 0 ;
if ( V_7 -> V_232 -> V_279 )
V_7 -> V_232 -> V_279 ( & V_7 -> V_12 ) ;
}
static void F_118 ( struct V_6 * V_7 )
{
T_2 V_280 ;
V_280 = F_119 ( & V_7 -> V_29 -> V_281 ) ;
if ( V_280 & V_282 ) {
if ( ( V_7 -> V_249 ) != V_277 )
F_116 ( V_7 ) ;
} else {
if ( V_7 -> V_249 == V_277 )
F_117 ( V_7 ) ;
}
}
static int F_120 ( struct V_6 * V_7 )
{
unsigned char V_64 ;
if ( V_7 -> V_249 == V_283 )
return 0 ;
F_53 ( V_7 ) ;
F_27 ( & V_7 -> V_29 -> V_284 , 0 ) ;
for ( V_64 = 0 ; V_64 < V_176 ; V_64 ++ ) {
if ( V_7 -> V_40 [ V_64 ] . V_142 )
F_31 ( V_7 , V_64 ) ;
}
F_110 ( V_7 ) ;
V_7 -> V_249 = V_283 ;
V_7 -> V_41 = V_42 ;
V_7 -> V_43 = V_38 ;
F_51 ( V_7 ) ;
return 0 ;
}
static int F_121 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_122 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_123 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_79 T_4 * V_80 ;
int V_64 , V_285 = 0 ;
if ( ( V_7 -> V_249 == V_250 )
&& ( F_119 ( & V_7 -> V_29 -> V_284 ) == 0 ) )
F_27 ( & V_7 -> V_29 -> V_284 , V_7 -> V_248 ) ;
for ( V_64 = ( V_176 - 1 ) ; ( ( V_64 >= 0 ) && ( V_285 == 0 ) ) ; V_64 -- ) {
V_2 = & V_7 -> V_40 [ V_64 ] ;
if ( V_2 && V_2 -> V_142 && ( V_2 -> V_33 != V_38 ) ) {
V_80 = V_2 -> V_73 ;
if ( ! ( F_56 ( ( T_3 T_4 * ) V_80 ) & V_190 )
&& ( F_56 ( & V_80 -> V_88 ) ) ) {
if ( V_2 -> V_28 == 0 )
V_285 = F_87 ( V_2 ) ;
else
V_285 = F_89 ( V_2 ) ;
}
}
}
return V_285 ;
}
static void F_124 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_79 T_4 * V_80 ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_176 ; V_64 ++ ) {
V_2 = & V_7 -> V_40 [ V_64 ] ;
if ( V_2 && V_2 -> V_142 && ( V_2 -> V_33 != V_34 ) ) {
V_80 = V_2 -> V_100 ;
if ( ! ( F_56 ( ( T_3 T_4 * ) V_80 ) & V_84 )
&& ( F_56 ( & V_80 -> V_88 ) ) ) {
if ( V_2 -> V_28 == 0 ) {
F_64 ( V_7 ) ;
} else {
F_75 ( V_2 ) ;
}
}
}
}
}
static T_7 F_125 ( int V_286 , void * V_287 )
{
struct V_6 * V_7 = (struct V_6 * ) V_287 ;
T_1 V_288 ;
T_7 V_5 = V_289 ;
unsigned long V_131 ;
F_49 ( & V_7 -> V_23 , V_131 ) ;
V_288 = F_13 ( & V_7 -> V_29 -> V_52 ) &
F_13 ( & V_7 -> V_29 -> V_47 ) ;
F_14 ( & V_7 -> V_29 -> V_52 , V_288 ) ;
if ( V_288 & V_290 ) {
F_118 ( V_7 ) ;
V_288 &= ~ V_290 ;
V_5 = V_291 ;
}
if ( V_288 & V_188 ) {
F_123 ( V_7 ) ;
V_288 &= ~ V_188 ;
V_5 = V_291 ;
}
if ( V_288 & V_48 ) {
F_124 ( V_7 ) ;
V_288 &= ~ V_48 ;
V_5 = V_291 ;
}
if ( V_288 & V_292 ) {
F_120 ( V_7 ) ;
V_288 &= ~ V_292 ;
V_5 = V_291 ;
}
if ( V_288 & V_49 ) {
F_121 ( V_7 ) ;
V_288 &= ~ V_49 ;
V_5 = V_291 ;
}
if ( V_288 & V_189 ) {
F_122 ( V_7 ) ;
V_288 &= ~ V_189 ;
V_5 = V_291 ;
}
F_50 ( & V_7 -> V_23 , V_131 ) ;
return V_5 ;
}
static int F_126 ( struct V_242 * V_12 ,
struct V_293 * V_232 )
{
struct V_6 * V_7 ;
unsigned long V_131 ;
V_7 = F_94 ( V_12 , struct V_6 , V_12 ) ;
F_49 ( & V_7 -> V_23 , V_131 ) ;
V_232 -> V_232 . V_294 = NULL ;
V_7 -> V_232 = V_232 ;
V_7 -> V_12 . V_136 = V_232 -> V_295 ;
F_51 ( V_7 ) ;
F_14 ( & V_7 -> V_29 -> V_52 , 0xffff ) ;
F_14 ( & V_7 -> V_29 -> V_47 , V_296 ) ;
V_7 -> V_249 = V_297 ;
V_7 -> V_41 = V_42 ;
V_7 -> V_43 = V_38 ;
F_50 ( & V_7 -> V_23 , V_131 ) ;
F_127 ( V_7 -> V_13 , L_38 , V_7 -> V_12 . V_21 ,
V_232 -> V_232 . V_21 ) ;
return 0 ;
}
static int F_128 ( struct V_242 * V_12 ,
struct V_293 * V_232 )
{
struct V_6 * V_7 ;
struct V_1 * V_298 ;
unsigned long V_131 ;
V_7 = F_94 ( V_12 , struct V_6 , V_12 ) ;
F_53 ( V_7 ) ;
V_7 -> V_249 = V_297 ;
V_7 -> V_41 = V_42 ;
V_7 -> V_43 = 0 ;
F_49 ( & V_7 -> V_23 , V_131 ) ;
V_7 -> V_12 . V_136 = V_233 ;
F_9 ( & V_7 -> V_40 [ 0 ] , - V_20 ) ;
F_106 (loop_ep, &udc->gadget.ep_list, ep.ep_list)
F_9 ( V_298 , - V_20 ) ;
F_50 ( & V_7 -> V_23 , V_131 ) ;
V_7 -> V_232 = NULL ;
F_127 ( V_7 -> V_13 , L_39 ,
V_232 -> V_232 . V_21 ) ;
return 0 ;
}
static struct V_6 * F_129 ( struct V_299 * V_300 )
{
struct V_6 * V_7 ;
struct V_301 * V_302 = V_300 -> V_13 . V_303 ;
unsigned int V_93 = 0 ;
struct V_304 T_4 * V_305 ;
unsigned int V_64 ;
T_8 V_102 ;
T_3 V_306 ;
V_7 = F_41 ( sizeof( * V_7 ) , V_261 ) ;
if ( V_7 == NULL ) {
F_39 ( & V_300 -> V_13 , L_40 ) ;
goto V_307;
}
V_7 -> V_13 = & V_300 -> V_13 ;
V_306 = * F_130 ( V_302 , 1 , & V_102 , NULL ) ;
V_7 -> V_243 = F_36 ( V_306 ) ;
F_131 ( V_7 -> V_243 , 0 , V_102 ) ;
V_305 = V_7 -> V_243 ;
F_14 ( & V_305 -> V_244 , 0 ) ;
F_28 ( & V_305 -> V_308 , 0 ) ;
V_93 = F_34 ( ( V_176 *
sizeof( struct V_94 ) ) ,
V_309 ) ;
if ( F_35 ( V_93 ) )
goto V_307;
for ( V_64 = 0 ; V_64 < V_176 ; V_64 ++ ) {
F_14 ( & V_305 -> V_310 [ V_64 ] , ( T_1 ) V_93 ) ;
V_7 -> V_68 [ V_64 ] = F_36 ( V_93 ) ;
V_93 += 32 ;
}
F_131 ( V_7 -> V_68 [ 0 ] , 0 ,
V_176 * sizeof( struct V_94 ) ) ;
V_7 -> V_276 = V_311 ;
V_7 -> V_249 = V_312 ;
V_7 -> V_43 = 0 ;
F_132 ( & V_7 -> V_23 ) ;
return V_7 ;
V_307:
F_42 ( V_7 ) ;
return NULL ;
}
static int F_133 ( struct V_6 * V_7 )
{
struct V_313 T_4 * V_314 ;
V_314 = V_7 -> V_29 ;
F_27 ( & V_314 -> V_149 , 0x01 ) ;
F_27 ( & V_314 -> V_149 , 0x00 ) ;
F_14 ( & V_314 -> V_47 , 0 ) ;
F_27 ( & V_314 -> V_65 , 0 ) ;
F_14 ( & V_314 -> V_52 , V_315 ) ;
return 0 ;
}
static int F_134 ( struct V_6 * V_7 , unsigned char V_77 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_77 ] ;
V_2 -> V_7 = V_7 ;
strcpy ( V_2 -> V_21 , V_229 [ V_77 ] ) ;
V_2 -> V_2 . V_21 = V_229 [ V_77 ] ;
V_2 -> V_2 . V_316 = & V_317 ;
V_2 -> V_8 = 1 ;
V_2 -> V_2 . V_107 = ( unsigned short ) ~ 0 ;
V_2 -> V_2 . V_115 = NULL ;
V_2 -> V_33 = 0xff ;
V_2 -> V_28 = ( T_2 ) V_77 ;
V_2 -> V_207 = 0 ;
V_2 -> V_209 = 0 ;
V_2 -> V_142 = 0 ;
V_2 -> V_105 = NULL ;
V_2 -> V_146 = NULL ;
V_2 -> V_204 = NULL ;
V_2 -> V_44 = V_45 ;
V_2 -> V_53 = 0 ;
F_99 ( & V_2 -> V_9 ) ;
if ( V_77 != 0 )
F_103 ( & V_2 -> V_2 . V_318 , & V_7 -> V_12 . V_318 ) ;
V_2 -> V_12 = & V_7 -> V_12 ;
return 0 ;
}
static void F_135 ( struct V_319 * V_13 )
{
struct V_6 * V_7 = F_94 ( V_13 , struct V_6 , V_12 . V_13 ) ;
int V_64 ;
V_24 ( V_7 -> F_1 ) ;
F_95 ( F_96 ( V_7 -> V_68 [ 0 ] ) ) ;
for ( V_64 = 0 ; V_64 < V_176 ; V_64 ++ )
V_7 -> V_68 [ V_64 ] = NULL ;
F_42 ( V_7 ) ;
}
static int F_136 ( struct V_299 * V_300 )
{
struct V_6 * V_7 ;
const struct V_320 * V_321 ;
struct V_301 * V_302 = V_300 -> V_13 . V_303 ;
struct V_1 * V_2 ;
unsigned int V_237 = 0 ;
unsigned int V_64 ;
const void * V_322 ;
V_321 = F_137 ( V_323 , & V_300 -> V_13 ) ;
if ( ! V_321 )
return - V_104 ;
V_322 = F_138 ( V_302 , L_41 , NULL ) ;
if ( ! V_322 || strcmp ( V_322 , L_42 ) )
return - V_148 ;
V_7 = F_129 ( V_300 ) ;
if ( ! V_7 ) {
F_39 ( & V_300 -> V_13 , L_43 ) ;
return - V_97 ;
}
V_7 -> V_54 = ( unsigned long ) V_321 -> V_163 ;
V_7 -> V_29 = F_139 ( V_302 , 0 ) ;
if ( ! V_7 -> V_29 ) {
V_237 = - V_97 ;
goto V_324;
}
F_133 ( V_7 ) ;
V_7 -> V_12 . V_316 = & V_325 ;
V_7 -> V_12 . V_326 = & V_7 -> V_40 [ 0 ] . V_2 ;
F_99 ( & V_7 -> V_12 . V_318 ) ;
V_7 -> V_12 . V_136 = V_233 ;
V_7 -> V_12 . V_21 = V_327 ;
V_7 -> V_12 . V_13 . V_14 = & V_300 -> V_13 ;
for ( V_64 = 0 ; V_64 < V_176 ; V_64 ++ ) {
F_134 ( V_7 , ( unsigned char ) V_64 ) ;
}
V_237 = F_47 ( V_7 , 0 , & V_328 ) ;
if ( V_237 )
goto V_329;
V_7 -> V_191 = F_41 ( 256 , V_261 ) ;
if ( V_7 -> V_191 == NULL ) {
F_39 ( V_7 -> V_13 , L_44 ) ;
V_237 = - V_97 ;
goto V_330;
}
V_7 -> V_262 = F_41 ( 2 , V_261 ) ;
if ( V_7 -> V_262 == NULL ) {
V_237 = - V_97 ;
goto V_331;
}
V_7 -> V_332 = F_43 ( ( void * ) V_7 -> V_191 ) ;
if ( V_7 -> V_332 == V_19 ) {
V_7 -> V_332 = F_44 (
V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_191 ,
256 ,
V_17 ) ;
V_7 -> V_333 = 1 ;
} else {
F_45 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_332 , 256 ,
V_17 ) ;
}
F_140 ( & V_7 -> V_183 , F_73 ,
( unsigned long ) V_7 ) ;
V_7 -> V_334 = F_141 ( V_302 , 0 ) ;
if ( ! V_7 -> V_334 ) {
V_237 = - V_104 ;
goto V_335;
}
V_237 = F_142 ( V_7 -> V_334 , F_125 , 0 ,
V_327 , V_7 ) ;
if ( V_237 ) {
F_39 ( V_7 -> V_13 , L_45 ,
V_7 -> V_334 , V_237 ) ;
goto V_336;
}
V_237 = F_143 ( & V_300 -> V_13 , & V_7 -> V_12 ,
F_135 ) ;
if ( V_237 )
goto V_337;
F_144 ( & V_300 -> V_13 , V_7 ) ;
F_127 ( V_7 -> V_13 ,
L_46 ,
( V_7 -> V_54 == V_338 ) ? L_47 : L_48 ) ;
return 0 ;
V_337:
F_145 ( V_7 -> V_334 , V_7 ) ;
V_336:
F_146 ( V_7 -> V_334 ) ;
V_335:
if ( V_7 -> V_333 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_332 , 256 ,
V_17 ) ;
V_7 -> V_332 = V_19 ;
} else {
F_5 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_332 , 256 ,
V_17 ) ;
}
F_42 ( V_7 -> V_262 ) ;
V_331:
F_42 ( V_7 -> V_191 ) ;
V_330:
V_2 = & V_7 -> V_40 [ 0 ] ;
F_95 ( F_96 ( V_2 -> V_83 ) ) ;
F_42 ( V_2 -> V_105 ) ;
F_42 ( V_2 -> V_109 ) ;
F_42 ( V_2 -> V_146 ) ;
V_329:
F_147 ( V_7 -> V_29 ) ;
V_324:
F_42 ( V_7 ) ;
return V_237 ;
}
static int F_148 ( struct V_299 * V_13 , T_9 V_44 )
{
return - V_339 ;
}
static int F_149 ( struct V_299 * V_13 )
{
return - V_339 ;
}
static int F_150 ( struct V_299 * V_300 )
{
struct V_6 * V_7 = F_151 ( & V_300 -> V_13 ) ;
struct V_1 * V_2 ;
unsigned int V_102 ;
F_152 ( F_1 ) ;
F_153 ( & V_7 -> V_12 ) ;
V_7 -> F_1 = & F_1 ;
F_154 ( & V_7 -> V_183 ) ;
if ( V_7 -> V_333 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_332 , 256 ,
V_17 ) ;
V_7 -> V_332 = V_19 ;
} else {
F_5 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_332 , 256 ,
V_17 ) ;
}
F_42 ( V_7 -> V_262 ) ;
F_42 ( V_7 -> V_191 ) ;
V_2 = & V_7 -> V_40 [ 0 ] ;
F_95 ( F_96 ( V_2 -> V_83 ) ) ;
V_102 = ( V_2 -> V_2 . V_107 + V_108 + 2 ) * ( V_82 + 1 ) ;
F_42 ( V_2 -> V_105 ) ;
if ( V_2 -> V_111 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_110 , V_102 ,
V_18 ) ;
V_2 -> V_110 = V_19 ;
} else {
F_5 ( V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_110 , V_102 ,
V_18 ) ;
}
F_42 ( V_2 -> V_109 ) ;
F_42 ( V_2 -> V_146 ) ;
F_145 ( V_7 -> V_334 , V_7 ) ;
F_146 ( V_7 -> V_334 ) ;
F_155 ( & V_7 -> V_183 ) ;
F_147 ( V_7 -> V_29 ) ;
F_156 ( & F_1 ) ;
return 0 ;
}
