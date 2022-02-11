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
V_134 = F_48 ( V_116 ) ;
if ( V_78 != 0 ) {
switch ( V_116 -> V_120 & V_135 ) {
case V_121 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_136;
switch ( V_7 -> V_12 . V_137 ) {
case V_138 :
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
case V_139 :
goto V_136;
}
}
break;
case V_125 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 ) )
goto V_136;
switch ( V_7 -> V_12 . V_137 ) {
case V_138 :
if ( V_134 <= 1024 )
break;
case V_140 :
if ( V_134 <= 64 )
break;
default:
if ( V_134 <= 8 )
break;
goto V_136;
}
break;
case V_123 :
if ( strstr ( V_2 -> V_2 . V_21 , L_6 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_136;
switch ( V_7 -> V_12 . V_137 ) {
case V_138 :
if ( V_134 <= 1024 )
break;
case V_140 :
if ( V_134 <= 1023 )
break;
default:
goto V_136;
}
break;
case V_141 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 )
|| strstr ( V_2 -> V_2 . V_21 , L_5 ) )
goto V_136;
switch ( V_7 -> V_12 . V_137 ) {
case V_138 :
case V_140 :
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
goto V_136;
}
case V_139 :
switch ( V_134 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
goto V_136;
}
default:
goto V_136;
}
break;
default:
goto V_136;
}
}
F_49 ( & V_7 -> V_23 , V_132 ) ;
V_2 -> V_2 . V_108 = V_134 ;
V_2 -> V_142 = ( T_2 ) ( V_116 -> V_120 & V_135 ) ;
V_2 -> V_116 = V_116 ;
V_2 -> V_8 = 0 ;
V_2 -> V_143 = 1 ;
if ( V_78 == 0 ) {
V_2 -> V_33 = V_92 ;
V_7 -> V_44 = V_38 ;
V_7 -> V_42 = V_43 ;
} else {
switch ( V_116 -> V_117 & V_144 ) {
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
if ( ( V_2 -> V_142 == V_145 ) || ( V_2 -> V_33 == V_38 ) ) {
V_133 = F_37 ( V_2 ) ;
if ( V_133 )
goto V_146;
}
if ( ( V_2 -> V_142 == V_145 ) || ( V_2 -> V_33 == V_34 ) ) {
V_2 -> V_147 = F_38 ( sizeof( * V_2 -> V_147 ) , V_107 ) ;
if ( V_2 -> V_147 == NULL ) {
F_39 ( V_7 -> V_13 , L_7 ) ;
goto V_148;
}
F_40 ( V_2 -> V_147 ) ;
}
F_46 ( V_7 , V_78 ) ;
F_50 ( & V_7 -> V_23 , V_132 ) ;
return 0 ;
V_148:
F_42 ( V_2 -> V_110 ) ;
F_42 ( V_2 -> V_106 ) ;
V_146:
F_50 ( & V_7 -> V_23 , V_132 ) ;
V_136:
F_39 ( V_7 -> V_13 , L_8 , V_2 -> V_2 . V_21 ) ;
return - V_149 ;
}
static inline void F_51 ( void )
{
F_52 ( & V_41 -> V_29 -> V_150 , V_151 ) ;
}
static inline void F_53 ( void )
{
F_54 ( & V_41 -> V_29 -> V_150 , V_151 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_3 V_152 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_2 -> V_102 ) ;
V_152 = V_86 | V_85 | ( V_152 & V_87 ) ;
F_28 ( ( T_3 T_4 * ) V_2 -> V_102 , V_152 ) ;
if ( V_152 & V_87 )
V_2 -> V_102 = V_2 -> V_84 ;
else
V_2 -> V_102 ++ ;
}
static void F_57 ( struct V_1 * V_2 , unsigned char V_153 )
{
T_3 V_152 ;
struct V_80 T_4 * V_81 , * V_154 ;
unsigned char V_155 = 0 ;
V_154 = V_2 -> V_101 ;
V_81 = V_2 -> V_102 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
while ( ! ( V_152 & V_85 ) && ! ( V_152 & V_156 ) && ! V_155 ) {
V_152 = V_85 | V_86 | ( V_152 & V_87 ) ;
F_28 ( ( T_3 T_4 * ) V_81 , V_152 ) ;
if ( V_152 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
if ( V_153 && ( V_81 == V_154 ) )
V_155 = 1 ;
}
V_2 -> V_102 = V_81 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_80 T_4 * V_81 = V_2 -> V_101 ;
T_3 V_152 ;
T_2 V_28 = V_2 -> V_28 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
if ( ! ( V_152 & V_85 ) && ! ( V_152 & V_156 ) ) {
V_81 = V_2 -> V_84 +
( ( F_13 ( & V_7 -> V_69 [ V_28 ] -> V_100 ) -
F_13 ( & V_7 -> V_69 [ V_28 ] -> V_99 ) )
>> 3 ) ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
if ( V_152 & V_87 )
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
V_2 -> V_157 = 0 ;
}
static int F_59 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
struct V_158 * V_159 ;
unsigned int V_160 ;
T_2 * V_161 ;
V_159 = V_2 -> V_106 ;
if ( ( F_60 ( V_159 ) & V_162 )
&& ( V_7 -> V_42 == V_43 ) ) {
V_160 = F_61 ( V_159 ) ;
if ( F_62 ( V_160 != 8 ) )
return - V_105 ;
V_161 = ( T_2 * ) & V_7 -> V_163 ;
memcpy ( V_161 , V_159 -> V_164 , V_160 ) ;
V_2 -> V_93 = 1 ;
F_63 ( V_7 , & V_7 -> V_163 ) ;
return 0 ;
}
return - V_105 ;
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
struct V_158 * V_159 ;
struct V_80 T_4 * V_81 ;
T_3 V_152 , V_16 ;
T_3 V_165 ;
V_159 = V_2 -> V_106 ;
if ( V_2 -> V_33 == V_34 ) {
F_39 ( V_7 -> V_13 , L_9 ) ;
return - V_105 ;
}
V_81 = V_2 -> V_101 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_152 & V_156 ;
while ( ! ( V_152 & V_85 ) && V_16 ) {
if ( ( V_152 & V_166 ) && ( V_152 & V_167 )
&& ! ( V_152 & V_168 ) ) {
if ( V_16 == V_109 ) {
V_7 -> V_42 = V_43 ;
F_6 ( V_7 -> V_13 ,
L_10 ) ;
} else {
F_65 ( V_159 ) ;
V_165 = ( T_3 ) F_66 ( F_56 ( & V_81 -> V_89 ) ) ;
F_67 ( V_159 , ( T_2 * ) V_165 ) ;
F_68 ( V_159 ,
( V_16 - V_109 ) ) ;
F_69 ( V_159 , V_169 ) ;
switch ( V_152 & V_170 ) {
case V_171 :
F_70 ( V_159 , V_162 ) ;
break;
case V_172 :
F_70 ( V_159 , V_173 ) ;
break;
default:
F_70 ( V_159 , V_174 ) ;
break;
}
if ( ( V_152 & V_170 ) == V_171 )
F_59 ( V_7 ) ;
else
F_71 ( V_2 ) ;
}
} else {
F_39 ( V_7 -> V_13 , L_11 ) ;
}
F_55 ( V_2 ) ;
if ( V_152 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_152 & V_156 ;
}
V_2 -> V_101 = V_81 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_158 * V_159 ;
T_2 V_175 = 0 ;
unsigned int V_160 ;
T_2 * V_161 ;
struct V_3 * V_4 ;
V_159 = V_2 -> V_106 ;
if ( F_60 ( V_159 ) & V_173 )
V_175 = 0x1 ;
if ( V_175 != V_2 -> V_93 ) {
F_39 ( V_2 -> V_7 -> V_13 , L_12 ) ;
return - V_176 ;
}
V_160 = F_61 ( V_159 ) ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_39 ( V_2 -> V_7 -> V_13 , L_13 , V_2 -> V_21 ) ;
} else {
V_4 = F_11 ( V_2 -> V_9 . V_25 , struct V_3 , V_9 ) ;
V_161 = ( T_2 * ) ( V_4 -> V_4 . V_89 ) + V_4 -> V_4 . V_22 ;
if ( V_161 ) {
memcpy ( V_161 , V_159 -> V_164 , V_160 ) ;
V_4 -> V_4 . V_22 += V_160 ;
if ( ( V_160 < V_2 -> V_2 . V_108 ) ||
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
static void F_73 ( unsigned long V_164 )
{
struct V_6 * V_7 = (struct V_6 * ) V_164 ;
struct V_1 * V_2 ;
struct V_158 * V_159 ;
struct V_80 T_4 * V_81 ;
unsigned long V_132 ;
T_3 V_152 , V_16 ;
T_3 V_165 , V_65 ;
F_49 ( & V_7 -> V_23 , V_132 ) ;
for ( V_65 = 1 ; V_65 < V_177 ; V_65 ++ ) {
V_2 = & V_7 -> V_40 [ V_65 ] ;
if ( V_2 -> V_33 == V_34 || V_2 -> V_178 == 0 ) {
F_74 ( V_7 -> V_13 ,
L_14 ) ;
continue;
}
V_159 = V_2 -> V_106 ;
V_81 = V_2 -> V_101 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_152 & V_156 ;
while ( ! ( V_152 & V_85 ) && V_16 ) {
if ( F_10 ( & V_2 -> V_9 ) ) {
F_17 ( V_2 ) ;
F_74 ( V_7 -> V_13 ,
L_15 ,
V_2 -> V_54 ) ;
break;
}
if ( ( V_152 & V_166 ) && ( V_152 & V_167 )
&& ! ( V_152 & V_168 ) ) {
F_65 ( V_159 ) ;
V_165 = ( T_3 ) F_66 ( F_56 ( & V_81 -> V_89 ) ) ;
F_67 ( V_159 , ( T_2 * ) V_165 ) ;
F_68 ( V_159 ,
( V_16 - V_109 ) ) ;
F_69 ( V_159 , V_169 ) ;
switch ( V_152 & V_170 ) {
case V_172 :
F_70 ( V_159 , V_173 ) ;
break;
case V_171 :
F_70 ( V_159 , V_162 ) ;
break;
default:
F_70 ( V_159 , V_174 ) ;
break;
}
F_71 ( V_2 ) ;
} else {
F_39 ( V_7 -> V_13 ,
L_16 ) ;
}
F_28 ( ( T_3 T_4 * ) V_81 , V_152 & V_179 ) ;
V_2 -> V_54 -- ;
if ( ! ( V_2 -> V_157 ) )
F_55 ( V_2 ) ;
if ( V_152 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_152 & V_156 ;
}
V_2 -> V_101 = V_81 ;
if ( V_2 -> V_157 )
F_58 ( V_2 ) ;
V_2 -> V_178 = 0 ;
}
F_50 ( & V_7 -> V_23 , V_132 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_158 * V_159 ;
struct V_80 T_4 * V_81 ;
T_1 V_180 , V_181 , V_182 ;
V_7 = V_2 -> V_7 ;
V_159 = V_2 -> V_106 ;
if ( V_2 -> V_33 == V_34 ) {
F_39 ( V_7 -> V_13 , L_17 ) ;
return - V_105 ;
}
V_81 = V_2 -> V_101 ;
V_180 = ( T_1 ) ( V_81 - V_2 -> V_84 ) ;
V_181 = ( T_1 ) ( ( F_13 ( & V_7 -> V_69 [ V_2 -> V_28 ] -> V_100 ) -
F_13 ( & V_7 -> V_69 [ V_2 -> V_28 ] -> V_99 ) ) >> 3 ) ;
if ( V_180 < V_181 )
V_182 = V_82 - V_181 + V_180 ;
else
V_182 = V_180 - V_181 ;
if ( V_182 < V_183 ) {
F_17 ( V_2 ) ;
V_2 -> V_157 = 1 ;
F_6 ( V_7 -> V_13 , L_18 , V_182 ) ;
}
V_2 -> V_54 = V_82 - V_182 ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_17 ( V_2 ) ;
F_6 ( V_7 -> V_13 , L_19 ,
V_2 -> V_54 ) ;
return 0 ;
}
F_76 ( & V_7 -> V_184 ) ;
V_2 -> V_178 = 1 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_158 * V_185 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_80 T_4 * V_81 ;
T_1 V_186 ;
T_3 V_152 , V_187 ;
T_3 V_188 ;
if ( V_2 -> V_33 == V_38 ) {
F_39 ( V_7 -> V_13 , L_20 ) ;
return - V_105 ;
}
V_186 = F_13 ( & V_7 -> V_29 -> V_48 ) ;
F_14 ( & V_7 -> V_29 -> V_48 ,
V_186 & ~ ( V_189 | V_190 ) ) ;
V_81 = V_2 -> V_76 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
if ( ! ( V_152 & ( V_191 | V_156 ) ) ) {
if ( F_61 ( V_185 ) == 0 ) {
F_67 ( V_185 , V_7 -> V_192 ) ;
F_68 ( V_185 , 2 ) ;
V_185 -> V_193 |= ( V_194 | V_195 ) ;
F_6 ( V_7 -> V_13 , L_21 ) ;
}
V_188 = F_43 ( ( void * ) V_185 -> V_164 ) ;
F_28 ( & V_81 -> V_89 , V_188 ) ;
V_152 = ( V_152 & V_90 ) ;
if ( ! ( F_60 ( V_185 ) & V_195 ) )
V_152 |= V_191 | V_196 | V_197 | V_198
| F_61 ( V_185 ) ;
else
V_152 |= V_191 | V_196 | V_197 | F_61 ( V_185 ) ;
if ( ( V_2 -> V_28 == 0 ) && ( V_7 -> V_42 == V_199 ) )
V_2 -> V_93 = 0x1 ;
if ( V_2 -> V_93 ) {
V_187 = V_200 ;
V_185 -> V_193 |= V_173 ;
} else {
V_187 = V_201 ;
V_185 -> V_193 |= V_174 ;
}
V_152 |= V_202 ;
V_152 |= V_187 ;
F_28 ( ( T_3 T_4 * ) V_81 , V_152 ) ;
F_29 ( V_2 ) ;
F_14 ( & V_7 -> V_29 -> V_48 , V_186 ) ;
F_32 ( V_2 ) ;
if ( V_152 & V_90 )
V_2 -> V_76 = V_2 -> V_75 ;
else
V_2 -> V_76 ++ ;
return 0 ;
} else {
F_14 ( & V_7 -> V_29 -> V_48 , V_186 ) ;
F_6 ( V_7 -> V_13 , L_22 ) ;
return - V_203 ;
}
}
static int F_78 ( struct V_1 * V_2 , unsigned char V_204 )
{
if ( V_2 -> V_205 != NULL ) {
struct V_3 * V_4 = V_2 -> V_205 ;
unsigned V_206 = 0 , V_207 = 0 ;
V_207 = F_79 ( unsigned , V_4 -> V_4 . V_16 - V_2 -> V_208 ,
V_2 -> V_2 . V_108 ) ;
if ( ! V_204 ) {
int V_209 = V_2 -> V_210 ;
V_2 -> V_208 += V_209 ;
V_2 -> V_210 -= V_209 ;
} else {
V_2 -> V_210 = 0 ;
}
if ( V_4 -> V_4 . V_211 ) {
if ( V_207 == 0 ||
( V_4 -> V_4 . V_16 % V_2 -> V_2 . V_108 ) != 0 )
V_206 = 0 ;
else
V_206 = 1 ;
} else
V_206 = 0 ;
if ( ( ( V_2 -> V_205 -> V_4 . V_16 - V_2 -> V_208 ) <= 0 ) && ! V_206 ) {
F_1 ( V_2 , V_2 -> V_205 , 0 ) ;
V_2 -> V_205 = NULL ;
V_2 -> V_210 = 0 ;
V_2 -> V_208 = 0 ;
}
}
if ( V_2 -> V_205 == NULL ) {
if ( ! F_10 ( & V_2 -> V_9 ) ) {
V_2 -> V_205 = F_11 ( V_2 -> V_9 . V_25 , struct V_3 ,
V_9 ) ;
V_2 -> V_210 = 0 ;
V_2 -> V_208 = 0 ;
}
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_158 * V_185 )
{
unsigned int V_103 ;
T_2 * V_89 ;
F_65 ( V_185 ) ;
V_103 = F_79 ( T_3 , ( V_2 -> V_205 -> V_4 . V_16 - V_2 -> V_208 ) ,
V_2 -> V_2 . V_108 ) ;
V_89 = ( T_2 * ) V_2 -> V_205 -> V_4 . V_89 + V_2 -> V_208 ;
if ( V_89 && V_103 ) {
V_2 -> V_210 = V_103 ;
V_2 -> V_205 -> V_4 . V_22 += V_103 ;
F_67 ( V_185 , V_89 ) ;
F_68 ( V_185 , V_103 ) ;
F_69 ( V_185 , V_169 ) ;
F_70 ( V_185 , 0 ) ;
return F_77 ( V_2 , V_185 ) ;
}
return - V_176 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_158 * V_185 , T_5 V_212 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_185 == NULL )
return - V_149 ;
F_65 ( V_185 ) ;
F_67 ( V_185 , ( T_2 * ) V_7 -> V_192 ) ;
F_68 ( V_185 , 2 ) ;
F_69 ( V_185 , V_169 ) ;
F_70 ( V_185 , ( V_194 | V_195 | V_212 ) ) ;
return F_77 ( V_2 , V_185 ) ;
}
static int F_82 ( struct V_1 * V_2 , struct V_158 * V_185 )
{
struct V_3 * V_4 = V_2 -> V_205 ;
int V_133 ;
if ( V_4 == NULL )
return - V_149 ;
if ( ( V_4 -> V_4 . V_16 - V_2 -> V_208 ) > 0 )
V_133 = F_80 ( V_2 , V_185 ) ;
else
V_133 = F_81 ( V_2 , V_185 , 0 ) ;
return V_133 ;
}
static int F_83 ( struct V_6 * V_7 , int V_213 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
if ( V_213 == V_34 ) {
V_7 -> V_42 = V_199 ;
V_7 -> V_44 = V_34 ;
F_81 ( V_2 , V_2 -> V_147 , V_214 | V_215 ) ;
} else {
V_7 -> V_44 = V_38 ;
V_7 -> V_42 = V_216 ;
}
return 0 ;
}
static void F_72 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ 0 ] ;
switch ( V_7 -> V_42 ) {
case V_217 :
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_83 ( V_7 , V_38 ) )
F_16 ( V_7 ) ;
break;
case V_199 :
F_1 ( V_2 , V_4 , 0 ) ;
V_7 -> V_42 = V_43 ;
break;
case V_218 :
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_83 ( V_7 , V_34 ) )
F_16 ( V_7 ) ;
break;
case V_216 :
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
static int F_84 ( struct V_1 * V_2 , unsigned char V_204 )
{
struct V_3 * V_205 = NULL ;
struct V_158 * V_185 = V_2 -> V_147 ;
if ( ( F_60 ( V_185 ) & ( V_194 | V_215 ) ) == ( V_194 | V_215 ) ) {
if ( ! V_204 )
V_2 -> V_7 -> V_42 = V_43 ;
else
F_81 ( V_2 , V_2 -> V_147 , V_214 | V_215 ) ;
return 0 ;
}
V_205 = V_2 -> V_205 ;
if ( V_205 != NULL ) {
if ( ! V_204 ) {
int V_209 = V_2 -> V_210 ;
V_2 -> V_208 += V_209 ;
V_2 -> V_210 -= V_209 ;
} else {
V_2 -> V_210 = 0 ;
}
if ( ( V_2 -> V_205 -> V_4 . V_16 - V_2 -> V_208 ) <= 0 ) {
V_2 -> V_205 -> V_4 . V_22 = ( unsigned int ) V_2 -> V_208 ;
F_72 ( V_2 -> V_7 , V_2 -> V_205 ) ;
V_2 -> V_205 = NULL ;
V_2 -> V_210 = 0 ;
V_2 -> V_208 = 0 ;
}
} else {
F_6 ( V_2 -> V_7 -> V_13 , L_24 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_147 ) & V_219 ) {
F_26 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_13 , L_25 ) ;
if ( F_60 ( V_2 -> V_147 ) & V_174 )
V_2 -> V_93 = 0 ;
else
V_2 -> V_93 = 1 ;
F_84 ( V_2 , 1 ) ;
} else
F_84 ( V_2 , 0 ) ;
F_82 ( V_2 , V_2 -> V_147 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_80 T_4 * V_81 ;
struct V_158 * V_159 ;
T_3 V_152 ;
V_81 = V_2 -> V_74 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
while ( ! ( V_152 & V_191 ) && ( V_152 & ~ V_90 ) ) {
V_159 = V_2 -> V_147 ;
F_28 ( ( T_3 T_4 * ) V_81 , V_152 & V_90 ) ;
F_28 ( & V_81 -> V_89 , 0 ) ;
if ( V_152 & V_90 )
V_2 -> V_74 = V_2 -> V_75 ;
else
V_2 -> V_74 ++ ;
if ( V_2 -> V_74 == V_2 -> V_76 ) {
if ( V_152 & V_220 ) {
F_69 ( V_159 , V_219 ) ;
if ( V_152 & V_221 )
V_159 -> V_5 |= V_222 ;
if ( V_152 & V_223 )
V_159 -> V_5 |= V_224 ;
}
F_85 ( V_2 ) ;
}
V_81 = V_2 -> V_74 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
if ( F_86 ( V_2 -> V_147 ) & V_219 ) {
F_26 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_13 , L_25 ) ;
if ( F_60 ( V_2 -> V_147 ) & V_174 )
V_2 -> V_93 = 0 ;
else
V_2 -> V_93 = 1 ;
F_78 ( V_2 , 1 ) ;
} else
F_78 ( V_2 , 0 ) ;
F_82 ( V_2 , V_2 -> V_147 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_80 T_4 * V_81 ;
struct V_158 * V_159 = NULL ;
T_3 V_152 ;
unsigned char V_225 = 0 ;
V_81 = V_2 -> V_74 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
while ( ! ( V_152 & V_191 ) && ( V_152 & ~ V_90 ) ) {
V_159 = V_2 -> V_147 ;
if ( V_152 & V_220 ) {
F_69 ( V_159 , V_219 ) ;
if ( V_152 & V_221 )
V_159 -> V_5 |= V_222 ;
if ( V_152 & V_223 )
V_159 -> V_5 |= V_224 ;
}
F_28 ( ( T_3 T_4 * ) V_81 , V_152 & V_90 ) ;
F_28 ( & V_81 -> V_89 , 0 ) ;
if ( V_152 & V_90 )
V_2 -> V_74 = V_2 -> V_75 ;
else
V_2 -> V_74 ++ ;
F_88 ( V_2 ) ;
V_81 = V_2 -> V_74 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
}
if ( V_225 )
return - V_176 ;
else
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_133 = 0 ;
if ( V_2 -> V_205 == NULL ) {
V_2 -> V_208 = 0 ;
V_2 -> V_210 = 0 ;
F_78 ( V_2 , 0 ) ;
V_133 = F_82 ( V_2 , V_2 -> V_147 ) ;
}
return V_133 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_158 * V_159 = NULL ;
struct V_80 T_4 * V_81 ;
T_3 V_152 , V_16 ;
T_3 V_165 , V_160 ;
T_2 * V_161 ;
T_2 V_226 = 0 ;
T_2 V_175 ;
if ( F_10 ( & V_2 -> V_9 ) ) {
F_6 ( V_7 -> V_13 , L_26 ) ;
return 0 ;
}
V_159 = V_2 -> V_106 ;
V_81 = V_2 -> V_101 ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_152 & V_156 ;
while ( ! ( V_152 & V_85 ) && V_16 ) {
if ( V_226 )
break;
if ( ( V_152 & V_166 ) && ( V_152 & V_167 )
&& ! ( V_152 & V_168 ) ) {
F_65 ( V_159 ) ;
V_165 = ( T_3 ) F_66 ( F_56 ( & V_81 -> V_89 ) ) ;
F_67 ( V_159 , ( T_2 * ) V_165 ) ;
F_68 ( V_159 , ( V_16 - V_109 ) ) ;
F_69 ( V_159 , V_169 ) ;
switch ( V_152 & V_170 ) {
case V_172 :
F_70 ( V_159 , V_173 ) ; break;
default:
F_70 ( V_159 , V_174 ) ; break;
}
if ( F_60 ( V_159 ) & V_173 )
V_175 = 0x1 ;
else
V_175 = 0 ;
if ( V_175 != V_2 -> V_93 ) {
F_6 ( V_7 -> V_13 , L_12 ) ;
} else {
V_160 = F_61 ( V_159 ) ;
V_161 = ( T_2 * ) ( V_4 -> V_4 . V_89 ) + V_4 -> V_4 . V_22 ;
if ( V_161 ) {
memcpy ( V_161 , V_159 -> V_164 , V_160 ) ;
V_4 -> V_4 . V_22 += V_160 ;
if ( ( V_160 < V_2 -> V_2 . V_108 )
|| ( V_4 -> V_4 . V_22 >=
V_4 -> V_4 . V_16 ) ) {
V_226 = 1 ;
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
F_28 ( ( T_3 T_4 * ) V_81 , ( V_152 & V_179 ) ) ;
V_2 -> V_54 -- ;
if ( V_152 & V_87 )
V_81 = V_2 -> V_84 ;
else
V_81 ++ ;
V_152 = F_56 ( ( T_3 T_4 * ) V_81 ) ;
V_16 = V_152 & V_156 ;
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
static int F_93 ( struct V_227 * V_228 ,
const struct V_131 * V_116 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_229 = 0 ;
unsigned char V_28 ;
V_2 = F_94 ( V_228 , struct V_1 , V_2 ) ;
if ( ! V_228 || ! V_116 || V_2 -> V_116 || V_228 -> V_21 == V_230 [ 0 ] ||
( V_116 -> V_231 != V_232 ) )
return - V_105 ;
V_7 = V_2 -> V_7 ;
if ( ! V_7 -> V_233 || ( V_7 -> V_12 . V_137 == V_234 ) )
return - V_20 ;
V_28 = ( T_2 ) V_116 -> V_117 & 0xF ;
V_229 = F_47 ( V_7 , V_28 , V_116 ) ;
if ( V_229 != 0 ) {
F_95 ( F_96 ( V_2 -> V_84 ) ) ;
F_74 ( V_7 -> V_13 , L_27 , V_2 -> V_28 ) ;
return - V_105 ;
}
F_74 ( V_7 -> V_13 , L_28 , V_2 -> V_28 ) ;
return 0 ;
}
static int F_97 ( struct V_227 * V_228 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
unsigned long V_132 ;
unsigned int V_103 ;
V_2 = F_94 ( V_228 , struct V_1 , V_2 ) ;
V_7 = V_2 -> V_7 ;
if ( ! V_228 || ! V_2 -> V_116 ) {
F_74 ( V_7 -> V_13 , L_29 , V_228 ? V_2 -> V_2 . V_21 : NULL ) ;
return - V_105 ;
}
F_49 ( & V_7 -> V_23 , V_132 ) ;
F_9 ( V_2 , - V_20 ) ;
V_2 -> V_116 = NULL ;
V_2 -> V_2 . V_116 = NULL ;
V_2 -> V_8 = 1 ;
V_2 -> V_205 = NULL ;
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
F_42 ( V_2 -> V_147 ) ;
F_74 ( V_7 -> V_13 , L_30 , V_228 -> V_21 ) ;
return 0 ;
}
static struct V_235 * F_98 ( struct V_227 * V_228 , T_6 V_236 )
{
struct V_3 * V_4 ;
V_4 = F_41 ( sizeof( * V_4 ) , V_236 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_4 . V_15 = V_19 ;
F_99 ( & V_4 -> V_9 ) ;
return & V_4 -> V_4 ;
}
static void F_100 ( struct V_227 * V_228 , struct V_235 * V_237 )
{
struct V_3 * V_4 ;
V_4 = F_94 ( V_237 , struct V_3 , V_4 ) ;
if ( V_237 )
F_42 ( V_4 ) ;
}
static int F_101 ( struct V_227 * V_228 , struct V_235 * V_237 )
{
struct V_1 * V_2 = F_94 ( V_228 , struct V_1 , V_2 ) ;
struct V_3 * V_4 = F_94 ( V_237 , struct V_3 , V_4 ) ;
struct V_6 * V_7 ;
int V_133 ;
V_7 = V_2 -> V_7 ;
if ( ! V_237 || ! V_4 -> V_4 . V_24 || ! V_4 -> V_4 . V_89
|| ! F_10 ( & V_4 -> V_9 ) ) {
F_74 ( V_7 -> V_13 , L_31 ) ;
return - V_105 ;
}
if ( ! V_228 || ( ! V_2 -> V_116 && F_102 ( V_2 ) ) ) {
F_74 ( V_7 -> V_13 , L_32 ) ;
return - V_105 ;
}
if ( ! V_7 -> V_233 || V_7 -> V_12 . V_137 == V_234 )
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
V_7 -> V_42 = V_217 ;
else
V_7 -> V_42 = V_218 ;
}
if ( V_2 -> V_33 == V_38 )
V_133 = F_92 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_104 ( struct V_227 * V_228 , struct V_235 * V_237 ,
T_6 V_236 )
{
struct V_1 * V_2 = F_94 ( V_228 , struct V_1 , V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_132 ;
int V_238 ;
F_49 ( & V_7 -> V_23 , V_132 ) ;
V_238 = F_101 ( V_228 , V_237 ) ;
F_50 ( & V_7 -> V_23 , V_132 ) ;
return V_238 ;
}
static int F_105 ( struct V_227 * V_228 , struct V_235 * V_237 )
{
struct V_1 * V_2 = F_94 ( V_228 , struct V_1 , V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_132 ;
if ( ! V_228 || ! V_237 )
return - V_105 ;
F_49 ( & V_2 -> V_7 -> V_23 , V_132 ) ;
F_106 (req, &ep->queue, queue) {
if ( & V_4 -> V_4 == V_237 )
break;
}
if ( & V_4 -> V_4 != V_237 ) {
F_50 ( & V_2 -> V_7 -> V_23 , V_132 ) ;
return - V_105 ;
}
F_1 ( V_2 , V_4 , - V_239 ) ;
F_50 ( & V_2 -> V_7 -> V_23 , V_132 ) ;
return 0 ;
}
static int F_107 ( struct V_227 * V_228 , int V_26 )
{
struct V_1 * V_2 ;
unsigned long V_132 ;
int V_5 = - V_240 ;
struct V_6 * V_7 ;
V_2 = F_94 ( V_228 , struct V_1 , V_2 ) ;
if ( ! V_228 || ! V_2 -> V_116 ) {
V_5 = - V_105 ;
goto V_241;
}
V_7 = V_2 -> V_7 ;
if ( V_26 && F_4 ( V_2 ) && ! F_10 ( & V_2 -> V_9 ) ) {
V_5 = - V_242 ;
goto V_241;
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
V_241:
F_6 ( V_7 -> V_13 , L_34 , V_2 -> V_2 . V_21 ,
V_26 ? L_35 : L_36 , V_5 ) ;
return V_5 ;
}
static int F_108 ( struct V_243 * V_12 )
{
T_1 V_104 ;
V_104 = F_13 ( & V_41 -> V_244 -> V_245 ) ;
if ( V_104 & 0x8000 )
V_104 = V_104 & 0x07ff ;
else
V_104 = - V_105 ;
return ( int ) V_104 ;
}
static int F_109 ( struct V_243 * V_12 )
{
return - V_246 ;
}
static int F_110 ( struct V_243 * V_12 , int V_247 )
{
return - V_246 ;
}
static int F_111 ( struct V_243 * V_12 , unsigned V_248 )
{
return - V_246 ;
}
static int F_112 ( struct V_243 * V_12 , int V_249 )
{
return - V_246 ;
}
static int F_113 ( struct V_6 * V_7 , T_2 V_250 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_250 ] ;
F_9 ( V_2 , - V_239 ) ;
V_2 -> V_205 = NULL ;
return 0 ;
}
static int F_114 ( struct V_6 * V_7 )
{
T_2 V_250 ;
for ( V_250 = 0 ; V_250 < V_177 ; V_250 ++ )
F_113 ( V_7 , V_250 ) ;
F_7 ( & V_7 -> V_23 ) ;
V_7 -> V_233 -> V_251 ( & V_7 -> V_12 ) ;
F_8 ( & V_7 -> V_23 ) ;
return 0 ;
}
static void F_115 ( struct V_6 * V_7 , T_1 V_26 , T_1 V_252 ,
T_1 V_16 )
{
V_7 -> V_253 = ( T_2 ) V_26 ;
V_7 -> V_254 = V_255 ;
if ( F_83 ( V_7 , V_34 ) )
F_16 ( V_7 ) ;
}
static void F_116 ( struct V_227 * V_228 , struct V_235 * V_237 )
{
struct V_3 * V_4 = F_94 ( V_237 , struct V_3 , V_4 ) ;
V_4 -> V_4 . V_89 = NULL ;
F_42 ( V_4 ) ;
}
static void F_117 ( struct V_6 * V_7 , T_2 V_256 , T_1 V_26 ,
T_1 V_252 , T_1 V_16 )
{
T_1 V_257 = 0 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_5 = 0 ;
V_2 = & V_7 -> V_40 [ 0 ] ;
if ( ( V_256 & V_258 ) == V_259 ) {
V_257 = 1 << V_260 ;
} else if ( ( V_256 & V_258 ) == V_261 ) {
V_257 = 0 ;
} else if ( ( V_256 & V_258 ) == V_262 ) {
int V_250 = V_252 & V_118 ;
struct V_1 * V_263 = & V_7 -> V_40 [ V_250 ] ;
T_1 V_113 ;
if ( ! V_263 -> V_116 )
goto V_264;
V_113 = F_13 ( & V_7 -> V_29 -> V_30 [ V_250 ] ) ;
if ( V_252 & V_34 ) {
if ( V_263 -> V_33 != V_34 )
goto V_264;
if ( ( V_113 & V_36 ) == V_37 )
V_257 = 1 << V_265 ;
} else {
if ( V_263 -> V_33 != V_38 )
goto V_264;
if ( ( V_113 & V_31 ) == V_32 )
V_257 = 1 << V_265 ;
}
}
V_4 = F_94 ( F_98 ( & V_2 -> V_2 , V_266 ) ,
struct V_3 , V_4 ) ;
V_4 -> V_4 . V_16 = 2 ;
V_4 -> V_4 . V_89 = V_7 -> V_267 ;
* ( T_1 * ) V_4 -> V_4 . V_89 = F_118 ( V_257 ) ;
V_4 -> V_4 . V_5 = - V_10 ;
V_4 -> V_4 . V_22 = 0 ;
V_4 -> V_4 . V_24 = F_116 ;
V_7 -> V_44 = V_34 ;
V_5 = F_101 ( & V_2 -> V_2 , & V_4 -> V_4 ) ;
if ( V_5 == 0 )
return;
V_264:
F_39 ( V_7 -> V_13 , L_37 ) ;
F_16 ( V_7 ) ;
}
static void F_63 ( struct V_6 * V_7 ,
struct V_268 * V_269 )
{
T_1 V_270 = F_119 ( V_269 -> V_270 ) ;
T_1 V_271 = F_119 ( V_269 -> V_271 ) ;
T_1 V_272 = F_119 ( V_269 -> V_272 ) ;
F_113 ( V_7 , 0 ) ;
if ( V_269 -> V_273 & V_34 )
V_7 -> V_44 = V_34 ;
else
V_7 -> V_44 = V_38 ;
switch ( V_269 -> V_274 ) {
case V_275 :
if ( ( V_269 -> V_273 & ( V_34 | V_276 ) )
!= ( V_34 | V_277 ) )
break;
F_117 ( V_7 , V_269 -> V_273 , V_270 , V_271 ,
V_272 ) ;
return;
case V_278 :
if ( V_269 -> V_273 != ( V_38 | V_277 |
V_259 ) )
break;
F_115 ( V_7 , V_270 , V_271 , V_272 ) ;
return;
case V_279 :
case V_280 :
if ( ( V_269 -> V_273 & V_276 )
!= V_277 )
break;
if ( ( V_269 -> V_273 & V_258 )
== V_262 ) {
int V_250 = V_271 & V_118 ;
struct V_1 * V_2 ;
if ( V_270 != 0 || V_272 != 0
|| V_250 > V_177 )
break;
V_2 = & V_7 -> V_40 [ V_250 ] ;
F_7 ( & V_7 -> V_23 ) ;
F_107 ( & V_2 -> V_2 ,
( V_269 -> V_274 == V_280 )
? 1 : 0 ) ;
F_8 ( & V_7 -> V_23 ) ;
}
F_83 ( V_7 , V_34 ) ;
return;
default:
break;
}
if ( V_272 ) {
if ( V_269 -> V_273 & V_34 ) {
V_7 -> V_42 = V_217 ;
V_7 -> V_44 = V_34 ;
} else {
V_7 -> V_42 = V_218 ;
V_7 -> V_44 = V_38 ;
}
F_7 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_233 -> V_269 ( & V_7 -> V_12 ,
& V_7 -> V_163 ) < 0 )
F_16 ( V_7 ) ;
F_8 ( & V_7 -> V_23 ) ;
} else {
V_7 -> V_44 = V_34 ;
F_7 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_233 -> V_269 ( & V_7 -> V_12 ,
& V_7 -> V_163 ) < 0 )
F_16 ( V_7 ) ;
F_8 ( & V_7 -> V_23 ) ;
V_7 -> V_42 = V_199 ;
}
}
static void F_120 ( struct V_6 * V_7 )
{
V_7 -> V_281 = V_7 -> V_254 ;
V_7 -> V_254 = V_282 ;
if ( V_7 -> V_233 -> V_283 )
V_7 -> V_233 -> V_283 ( & V_7 -> V_12 ) ;
}
static void F_121 ( struct V_6 * V_7 )
{
V_7 -> V_254 = V_7 -> V_281 ;
V_7 -> V_281 = 0 ;
if ( V_7 -> V_233 -> V_284 )
V_7 -> V_233 -> V_284 ( & V_7 -> V_12 ) ;
}
static void F_122 ( struct V_6 * V_7 )
{
T_2 V_285 ;
V_285 = F_123 ( & V_7 -> V_29 -> V_286 ) ;
if ( V_285 & V_287 ) {
if ( ( V_7 -> V_254 ) != V_282 )
F_120 ( V_7 ) ;
} else {
if ( V_7 -> V_254 == V_282 )
F_121 ( V_7 ) ;
}
}
static int F_124 ( struct V_6 * V_7 )
{
unsigned char V_65 ;
if ( V_7 -> V_254 == V_288 )
return 0 ;
F_53 () ;
F_27 ( & V_7 -> V_29 -> V_289 , 0 ) ;
for ( V_65 = 0 ; V_65 < V_177 ; V_65 ++ ) {
if ( V_7 -> V_40 [ V_65 ] . V_143 )
F_31 ( V_7 , V_65 ) ;
}
F_114 ( V_7 ) ;
V_7 -> V_254 = V_288 ;
V_7 -> V_42 = V_43 ;
V_7 -> V_44 = V_38 ;
F_51 () ;
return 0 ;
}
static int F_125 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_126 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_127 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_80 T_4 * V_81 ;
int V_65 , V_290 = 0 ;
if ( ( V_7 -> V_254 == V_255 )
&& ( F_123 ( & V_7 -> V_29 -> V_289 ) == 0 ) )
F_27 ( & V_7 -> V_29 -> V_289 , V_7 -> V_253 ) ;
for ( V_65 = ( V_177 - 1 ) ; ( ( V_65 >= 0 ) && ( V_290 == 0 ) ) ; V_65 -- ) {
V_2 = & V_7 -> V_40 [ V_65 ] ;
if ( V_2 && V_2 -> V_143 && ( V_2 -> V_33 != V_38 ) ) {
V_81 = V_2 -> V_74 ;
if ( ! ( F_56 ( ( T_3 T_4 * ) V_81 ) & V_191 )
&& ( F_56 ( & V_81 -> V_89 ) ) ) {
if ( V_2 -> V_28 == 0 )
V_290 = F_87 ( V_2 ) ;
else
V_290 = F_89 ( V_2 ) ;
}
}
}
return V_290 ;
}
static void F_128 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_80 T_4 * V_81 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_177 ; V_65 ++ ) {
V_2 = & V_7 -> V_40 [ V_65 ] ;
if ( V_2 && V_2 -> V_143 && ( V_2 -> V_33 != V_34 ) ) {
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
static T_7 F_129 ( int V_291 , void * V_292 )
{
struct V_6 * V_7 = (struct V_6 * ) V_292 ;
T_1 V_293 ;
T_7 V_5 = V_294 ;
unsigned long V_132 ;
F_49 ( & V_7 -> V_23 , V_132 ) ;
V_293 = F_13 ( & V_7 -> V_29 -> V_53 ) &
F_13 ( & V_7 -> V_29 -> V_48 ) ;
F_14 ( & V_7 -> V_29 -> V_53 , V_293 ) ;
if ( V_293 & V_295 ) {
F_122 ( V_7 ) ;
V_293 &= ~ V_295 ;
V_5 = V_296 ;
}
if ( V_293 & V_189 ) {
F_127 ( V_7 ) ;
V_293 &= ~ V_189 ;
V_5 = V_296 ;
}
if ( V_293 & V_49 ) {
F_128 ( V_7 ) ;
V_293 &= ~ V_49 ;
V_5 = V_296 ;
}
if ( V_293 & V_297 ) {
F_124 ( V_7 ) ;
V_293 &= ~ V_297 ;
V_5 = V_296 ;
}
if ( V_293 & V_50 ) {
F_125 ( V_7 ) ;
V_293 &= ~ V_50 ;
V_5 = V_296 ;
}
if ( V_293 & V_190 ) {
F_126 ( V_7 ) ;
V_293 &= ~ V_190 ;
V_5 = V_296 ;
}
F_50 ( & V_7 -> V_23 , V_132 ) ;
return V_5 ;
}
static int F_130 ( struct V_298 * V_233 ,
int (* F_131)( struct V_243 * ) )
{
int V_229 ;
unsigned long V_132 = 0 ;
if ( ! V_41 )
return - V_149 ;
if ( ! V_233 || V_233 -> V_299 < V_140
|| ! F_131 || ! V_233 -> V_251 || ! V_233 -> V_269 )
return - V_105 ;
if ( V_41 -> V_233 )
return - V_203 ;
F_49 ( & V_41 -> V_23 , V_132 ) ;
V_233 -> V_233 . V_300 = NULL ;
V_41 -> V_233 = V_233 ;
V_41 -> V_12 . V_13 . V_233 = & V_233 -> V_233 ;
V_41 -> V_12 . V_137 = V_233 -> V_299 ;
F_50 ( & V_41 -> V_23 , V_132 ) ;
V_229 = F_131 ( & V_41 -> V_12 ) ;
if ( V_229 ) {
F_39 ( V_41 -> V_13 , L_38 ,
V_233 -> V_233 . V_21 , V_229 ) ;
V_41 -> V_12 . V_13 . V_233 = NULL ;
V_41 -> V_233 = NULL ;
return V_229 ;
}
F_51 () ;
F_14 ( & V_41 -> V_29 -> V_53 , 0xffff ) ;
F_14 ( & V_41 -> V_29 -> V_48 , V_301 ) ;
V_41 -> V_254 = V_302 ;
V_41 -> V_42 = V_43 ;
V_41 -> V_44 = V_38 ;
F_132 ( V_41 -> V_13 , L_39 ,
V_41 -> V_12 . V_21 , V_233 -> V_233 . V_21 ) ;
return 0 ;
}
static int F_133 ( struct V_298 * V_233 )
{
struct V_1 * V_303 ;
unsigned long V_132 ;
if ( ! V_41 )
return - V_149 ;
if ( ! V_233 || V_233 != V_41 -> V_233 )
return - V_105 ;
F_53 () ;
V_41 -> V_254 = V_302 ;
V_41 -> V_42 = V_43 ;
V_41 -> V_44 = 0 ;
F_49 ( & V_41 -> V_23 , V_132 ) ;
V_41 -> V_12 . V_137 = V_234 ;
F_9 ( & V_41 -> V_40 [ 0 ] , - V_20 ) ;
F_106 (loop_ep, &udc_controller->gadget.ep_list,
ep.ep_list)
F_9 ( V_303 , - V_20 ) ;
F_50 ( & V_41 -> V_23 , V_132 ) ;
V_233 -> V_251 ( & V_41 -> V_12 ) ;
V_233 -> V_304 ( & V_41 -> V_12 ) ;
V_41 -> V_12 . V_13 . V_233 = NULL ;
V_41 -> V_233 = NULL ;
F_132 ( V_41 -> V_13 , L_40 ,
V_233 -> V_233 . V_21 ) ;
return 0 ;
}
static struct V_6 T_8 * F_134 ( struct V_305 * V_306 )
{
struct V_6 * V_7 ;
struct V_307 * V_308 = V_306 -> V_13 . V_309 ;
unsigned int V_94 = 0 ;
struct V_310 T_4 * V_311 ;
unsigned int V_65 ;
T_9 V_103 ;
T_3 V_312 ;
V_7 = F_41 ( sizeof( * V_7 ) , V_266 ) ;
if ( V_7 == NULL ) {
F_39 ( & V_306 -> V_13 , L_41 ) ;
goto V_313;
}
V_7 -> V_13 = & V_306 -> V_13 ;
V_312 = * F_135 ( V_308 , 1 , & V_103 , NULL ) ;
V_7 -> V_244 = F_36 ( V_312 ) ;
F_136 ( V_7 -> V_244 , 0 , V_103 ) ;
V_311 = V_7 -> V_244 ;
F_14 ( & V_311 -> V_245 , 0 ) ;
F_28 ( & V_311 -> V_314 , 0 ) ;
V_94 = F_34 ( ( V_177 *
sizeof( struct V_95 ) ) ,
V_315 ) ;
if ( F_35 ( V_94 ) )
goto V_313;
for ( V_65 = 0 ; V_65 < V_177 ; V_65 ++ ) {
F_14 ( & V_311 -> V_316 [ V_65 ] , ( T_1 ) V_94 ) ;
V_7 -> V_69 [ V_65 ] = F_36 ( V_94 ) ;
V_94 += 32 ;
}
F_136 ( V_7 -> V_69 [ 0 ] , 0 ,
V_177 * sizeof( struct V_95 ) ) ;
V_7 -> V_281 = V_317 ;
V_7 -> V_254 = V_318 ;
V_7 -> V_44 = 0 ;
F_137 ( & V_7 -> V_23 ) ;
return V_7 ;
V_313:
F_42 ( V_7 ) ;
return NULL ;
}
static int T_8 F_138 ( struct V_6 * V_7 )
{
struct V_319 T_4 * V_320 ;
V_320 = V_7 -> V_29 ;
F_27 ( & V_320 -> V_150 , 0x01 ) ;
F_27 ( & V_320 -> V_150 , 0x00 ) ;
F_14 ( & V_320 -> V_48 , 0 ) ;
F_27 ( & V_320 -> V_66 , 0 ) ;
F_14 ( & V_320 -> V_53 , V_321 ) ;
return 0 ;
}
static int T_8 F_139 ( struct V_6 * V_7 , unsigned char V_78 )
{
struct V_1 * V_2 = & V_7 -> V_40 [ V_78 ] ;
V_2 -> V_7 = V_7 ;
strcpy ( V_2 -> V_21 , V_230 [ V_78 ] ) ;
V_2 -> V_2 . V_21 = V_230 [ V_78 ] ;
V_2 -> V_2 . V_322 = & V_323 ;
V_2 -> V_8 = 1 ;
V_2 -> V_2 . V_108 = ( unsigned short ) ~ 0 ;
V_2 -> V_116 = NULL ;
V_2 -> V_33 = 0xff ;
V_2 -> V_28 = ( T_2 ) V_78 ;
V_2 -> V_208 = 0 ;
V_2 -> V_210 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_106 = NULL ;
V_2 -> V_147 = NULL ;
V_2 -> V_205 = NULL ;
V_2 -> V_45 = V_46 ;
V_2 -> V_54 = 0 ;
F_99 ( & V_2 -> V_9 ) ;
if ( V_78 != 0 )
F_103 ( & V_2 -> V_2 . V_324 , & V_7 -> V_12 . V_324 ) ;
V_2 -> V_12 = & V_7 -> V_12 ;
return 0 ;
}
static void F_140 ( struct V_325 * V_13 )
{
int V_65 = 0 ;
V_24 ( V_41 -> F_1 ) ;
F_95 ( F_96 ( V_41 -> V_69 [ 0 ] ) ) ;
for ( V_65 = 0 ; V_65 < V_177 ; V_65 ++ )
V_41 -> V_69 [ V_65 ] = NULL ;
F_42 ( V_41 ) ;
V_41 = NULL ;
}
static int T_8 F_141 ( struct V_305 * V_306 )
{
const struct V_326 * V_327 ;
struct V_307 * V_308 = V_306 -> V_13 . V_309 ;
struct V_1 * V_2 ;
unsigned int V_238 = 0 ;
unsigned int V_65 ;
const void * V_328 ;
V_327 = F_142 ( V_329 , & V_306 -> V_13 ) ;
if ( ! V_327 )
return - V_105 ;
V_328 = F_143 ( V_308 , L_42 , NULL ) ;
if ( ! V_328 || strcmp ( V_328 , L_43 ) )
return - V_149 ;
V_41 = F_134 ( V_306 ) ;
if ( ! V_41 ) {
F_39 ( & V_306 -> V_13 , L_44 ) ;
return - V_98 ;
}
V_41 -> V_55 = ( unsigned long ) V_327 -> V_164 ;
V_41 -> V_29 = F_144 ( V_308 , 0 ) ;
if ( ! V_41 -> V_29 ) {
V_238 = - V_98 ;
goto V_330;
}
F_138 ( V_41 ) ;
V_41 -> V_12 . V_322 = & V_331 ;
V_41 -> V_12 . V_332 = & V_41 -> V_40 [ 0 ] . V_2 ;
F_99 ( & V_41 -> V_12 . V_324 ) ;
V_41 -> V_12 . V_137 = V_234 ;
V_41 -> V_12 . V_21 = V_333 ;
F_145 ( & V_41 -> V_12 . V_13 ) ;
F_146 ( & V_41 -> V_12 . V_13 , L_45 ) ;
V_41 -> V_12 . V_13 . V_334 = F_140 ;
V_41 -> V_12 . V_13 . V_14 = & V_306 -> V_13 ;
for ( V_65 = 0 ; V_65 < V_177 ; V_65 ++ ) {
F_139 ( V_41 , ( unsigned char ) V_65 ) ;
}
V_238 = F_47 ( V_41 , 0 , & V_335 ) ;
if ( V_238 )
goto V_336;
V_41 -> V_192 = F_41 ( 256 , V_266 ) ;
if ( V_41 -> V_192 == NULL ) {
F_39 ( V_41 -> V_13 , L_46 ) ;
V_238 = - V_98 ;
goto V_337;
}
V_41 -> V_267 = F_41 ( 2 , V_266 ) ;
if ( V_41 -> V_267 == NULL ) {
V_238 = - V_98 ;
goto V_338;
}
V_41 -> V_339 = F_43 ( ( void * ) V_41 -> V_192 ) ;
if ( V_41 -> V_339 == V_19 ) {
V_41 -> V_339 = F_44 (
V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_192 ,
256 ,
V_17 ) ;
V_41 -> V_340 = 1 ;
} else {
F_45 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_339 , 256 ,
V_17 ) ;
}
F_147 ( & V_41 -> V_184 , F_73 ,
( unsigned long ) V_41 ) ;
V_41 -> V_341 = F_148 ( V_308 , 0 ) ;
if ( ! V_41 -> V_341 ) {
V_238 = - V_105 ;
goto V_342;
}
V_238 = F_149 ( V_41 -> V_341 , F_129 , 0 ,
V_333 , V_41 ) ;
if ( V_238 ) {
F_39 ( V_41 -> V_13 , L_47 ,
V_41 -> V_341 , V_238 ) ;
goto V_343;
}
V_238 = F_150 ( & V_41 -> V_12 . V_13 ) ;
if ( V_238 )
goto V_344;
V_238 = F_151 ( & V_306 -> V_13 , & V_41 -> V_12 ) ;
if ( V_238 )
goto V_345;
F_132 ( V_41 -> V_13 ,
L_48 ,
( V_41 -> V_55 == V_346 ) ? L_49 : L_50 ) ;
return 0 ;
V_345:
F_152 ( & V_41 -> V_12 . V_13 ) ;
V_344:
F_153 ( V_41 -> V_341 , V_41 ) ;
V_343:
F_154 ( V_41 -> V_341 ) ;
V_342:
if ( V_41 -> V_340 ) {
F_3 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_339 , 256 ,
V_17 ) ;
V_41 -> V_339 = V_19 ;
} else {
F_5 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_339 , 256 ,
V_17 ) ;
}
F_42 ( V_41 -> V_267 ) ;
V_338:
F_42 ( V_41 -> V_192 ) ;
V_337:
V_2 = & V_41 -> V_40 [ 0 ] ;
F_95 ( F_96 ( V_2 -> V_84 ) ) ;
F_42 ( V_2 -> V_106 ) ;
F_42 ( V_2 -> V_110 ) ;
F_42 ( V_2 -> V_147 ) ;
V_336:
F_155 ( V_41 -> V_29 ) ;
V_330:
F_42 ( V_41 ) ;
V_41 = NULL ;
return V_238 ;
}
static int F_156 ( struct V_305 * V_13 , T_10 V_45 )
{
return - V_246 ;
}
static int F_157 ( struct V_305 * V_13 )
{
return - V_246 ;
}
static int T_11 F_158 ( struct V_305 * V_306 )
{
struct V_1 * V_2 ;
unsigned int V_103 ;
F_159 ( F_1 ) ;
if ( ! V_41 )
return - V_149 ;
F_160 ( & V_41 -> V_12 ) ;
V_41 -> F_1 = & F_1 ;
F_161 ( & V_41 -> V_184 ) ;
if ( V_41 -> V_340 ) {
F_3 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_339 , 256 ,
V_17 ) ;
V_41 -> V_339 = V_19 ;
} else {
F_5 ( V_41 -> V_12 . V_13 . V_14 ,
V_41 -> V_339 , 256 ,
V_17 ) ;
}
F_42 ( V_41 -> V_267 ) ;
F_42 ( V_41 -> V_192 ) ;
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
F_42 ( V_2 -> V_147 ) ;
F_153 ( V_41 -> V_341 , V_41 ) ;
F_154 ( V_41 -> V_341 ) ;
F_162 ( & V_41 -> V_184 ) ;
F_155 ( V_41 -> V_29 ) ;
F_152 ( & V_41 -> V_12 . V_13 ) ;
F_163 ( & F_1 ) ;
return 0 ;
}
