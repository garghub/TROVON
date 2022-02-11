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
F_8 ( & V_2 -> V_2 , & V_4 -> V_4 ) ;
F_9 ( & V_7 -> V_23 ) ;
V_2 -> V_8 = V_8 ;
}
static void F_10 ( struct V_1 * V_2 , int V_5 )
{
while ( ! F_11 ( & V_2 -> V_9 ) ) {
struct V_3 * V_4 = NULL ;
V_4 = F_12 ( V_2 -> V_9 . V_24 , struct V_3 , V_9 ) ;
F_1 ( V_2 , V_4 , V_5 ) ;
}
}
static int F_13 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_26 ;
T_2 V_27 = V_2 -> V_27 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_26 = F_14 ( & V_7 -> V_28 -> V_29 [ V_27 ] ) ;
V_26 = V_26 & ~ V_30 ;
if ( V_25 == 1 )
V_26 |= V_31 ;
else if ( V_2 -> V_32 == V_33 )
V_26 |= V_34 ;
F_15 ( & V_7 -> V_28 -> V_29 [ V_27 ] , V_26 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_26 ;
T_2 V_27 = V_2 -> V_27 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_26 = F_14 ( & V_7 -> V_28 -> V_29 [ V_27 ] ) ;
V_26 = V_26 & ~ V_35 ;
if ( V_25 == 1 )
V_26 |= V_36 ;
else if ( V_2 -> V_32 == V_37 )
V_26 |= V_38 ;
F_15 ( & V_7 -> V_28 -> V_29 [ V_27 ] , V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 )
{
F_16 ( & V_7 -> V_39 [ 0 ] , 1 ) ;
F_13 ( & V_7 -> V_39 [ 0 ] , 1 ) ;
V_7 -> V_40 = V_41 ;
V_7 -> V_42 = 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_2 V_27 = V_2 -> V_27 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_43 == V_44 ) {
F_19 ( & V_7 -> V_28 -> V_29 [ V_27 ] ,
V_30 , V_45 ) ;
F_20 ( & V_7 -> V_28 -> V_46 ,
( V_47 | V_48 ) ) ;
V_2 -> V_43 = V_49 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_43 == V_49 ) {
F_19 ( & V_7 -> V_28 -> V_29 [ V_2 -> V_27 ] ,
V_50 , V_38 ) ;
F_15 ( & V_7 -> V_28 -> V_51 ,
V_48 | V_47 ) ;
F_22 ( & V_7 -> V_28 -> V_46 ,
( V_47 | V_48 ) ) ;
V_2 -> V_43 = V_44 ;
V_2 -> V_52 = 0 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 -> V_53 == V_54 )
F_24 ( V_55 | ( V_2 -> V_27 << V_56 ) ,
V_57 ) ;
else
F_25 ( V_58 , V_59 ,
V_2 -> V_27 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 -> V_53 == V_54 )
F_24 ( V_60 | ( V_2 -> V_27 <<
V_56 ) , V_61 ) ;
else
F_25 ( V_62 , V_59 ,
V_2 -> V_27 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_63 ;
V_63 = ( int ) V_2 -> V_27 ;
F_23 ( V_2 ) ;
F_28 ( & V_7 -> V_28 -> V_64 ,
V_65 | ( V_66 & ( V_2 -> V_27 ) ) ) ;
F_15 ( & V_7 -> V_67 [ V_63 ] -> V_68 , F_14 ( & V_7 -> V_67 [ V_63 ] -> V_69 ) ) ;
F_29 ( & V_7 -> V_67 [ V_63 ] -> V_70 , 0 ) ;
F_15 ( & V_7 -> V_67 [ V_63 ] -> V_71 , 0 ) ;
V_2 -> V_72 = V_2 -> V_73 ;
V_2 -> V_74 = V_2 -> V_73 ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_28 ( & V_7 -> V_28 -> V_64 ,
V_75 | ( V_66 & ( V_2 -> V_27 ) ) ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , int V_76 )
{
struct V_1 * V_2 ;
T_3 V_77 ;
struct V_78 T_4 * V_79 ;
int V_63 ;
V_2 = & V_7 -> V_39 [ V_76 ] ;
if ( V_2 -> V_32 == V_37 )
V_77 = V_80 ;
else
V_77 = V_81 ;
V_79 = V_2 -> V_82 ;
for ( V_63 = 0 ; V_63 < ( V_77 - 1 ) ; V_63 ++ ) {
F_29 ( ( T_3 T_4 * ) V_79 , V_83 | V_84 ) ;
V_79 ++ ;
}
F_29 ( ( T_3 T_4 * ) V_79 , V_83 | V_84 | V_85 ) ;
V_79 = V_2 -> V_73 ;
for ( V_63 = 0 ; V_63 < V_86 - 1 ; V_63 ++ ) {
F_29 ( & V_79 -> V_87 , 0 ) ;
F_29 ( ( T_3 T_4 * ) V_79 , 0 ) ;
V_79 ++ ;
}
F_29 ( ( T_3 T_4 * ) V_79 , V_88 ) ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 , int V_76 )
{
struct V_1 * V_2 ;
T_1 V_89 ;
V_2 = & V_7 -> V_39 [ V_76 ] ;
V_89 = F_14 ( & V_7 -> V_28 -> V_29 [ V_76 ] ) ;
V_89 &= ~ V_50 ;
switch ( V_2 -> V_32 ) {
case V_90 :
F_27 ( V_2 ) ;
break;
case V_37 :
V_89 |= V_38 ;
break;
case V_33 :
F_27 ( V_2 ) ;
V_89 |= V_34 ;
break;
default:
break;
}
F_15 ( & V_7 -> V_28 -> V_29 [ V_76 ] , V_89 ) ;
F_31 ( V_7 , V_76 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
V_2 -> V_91 ^= 0x1 ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 , unsigned char V_76 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ V_76 ] ;
unsigned long V_92 = 0 ;
struct V_93 T_4 * V_94 ;
int V_63 ;
struct V_78 T_4 * V_79 ;
int V_77 ;
if ( V_2 -> V_32 == V_37 )
V_77 = V_80 ;
else
V_77 = V_81 ;
V_94 = V_7 -> V_67 [ V_76 ] ;
V_92 = F_35 ( sizeof( struct V_78 ) * ( V_77 +
V_86 ) , V_95 ) ;
if ( F_36 ( V_92 ) )
return - V_96 ;
F_15 ( & V_94 -> V_97 , ( T_1 ) V_92 ) ;
F_15 ( & V_94 -> V_69 , ( T_1 ) ( V_92 +
( sizeof( struct V_78 ) * V_77 ) ) ) ;
F_15 ( & V_94 -> V_98 , F_14 ( & V_94 -> V_97 ) ) ;
F_15 ( & V_94 -> V_68 , F_14 ( & V_94 -> V_69 ) ) ;
V_2 -> V_82 = F_37 ( V_92 ) ;
V_2 -> V_73 = F_37 ( V_92 + ( sizeof( struct V_78 )
* V_77 ) ) ;
V_2 -> V_99 = V_2 -> V_82 ;
V_2 -> V_100 = V_2 -> V_82 ;
V_2 -> V_74 = V_2 -> V_73 ;
V_2 -> V_72 = V_2 -> V_73 ;
V_2 -> V_91 = 0 ;
V_79 = V_2 -> V_82 ;
for ( V_63 = 0 ; V_63 < V_77 - 1 ; V_63 ++ ) {
F_29 ( & V_79 -> V_87 , 0 ) ;
F_29 ( ( T_3 T_4 * ) V_79 , 0 ) ;
V_79 ++ ;
}
F_29 ( & V_79 -> V_87 , 0 ) ;
F_29 ( ( T_3 T_4 * ) V_79 , V_85 ) ;
V_79 = V_2 -> V_73 ;
for ( V_63 = 0 ; V_63 < V_86 - 1 ; V_63 ++ ) {
F_29 ( & V_79 -> V_87 , 0 ) ;
F_29 ( ( T_3 T_4 * ) V_79 , 0 ) ;
V_79 ++ ;
}
F_29 ( & V_79 -> V_87 , 0 ) ;
F_29 ( ( T_3 T_4 * ) V_79 , V_88 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
unsigned int V_101 ;
int V_63 ;
unsigned int V_102 ;
struct V_78 T_4 * V_79 ;
unsigned int V_77 ;
if ( V_2 -> V_82 == NULL )
return - V_103 ;
V_79 = V_2 -> V_82 ;
V_2 -> V_104 = F_39 ( sizeof( * V_2 -> V_104 ) , V_105 ) ;
if ( ! V_2 -> V_104 )
return - V_96 ;
F_40 ( V_2 -> V_104 ) ;
if ( V_2 -> V_32 == V_37 )
V_77 = V_80 ;
else
V_77 = V_81 ;
V_101 = ( V_2 -> V_2 . V_106 + V_107 + 2 ) * ( V_77 + 1 ) ;
V_2 -> V_108 = F_41 ( V_101 , V_105 ) ;
if ( ! V_2 -> V_108 ) {
F_42 ( V_2 -> V_104 ) ;
return - V_96 ;
}
V_2 -> V_109 = F_43 ( ( void * ) V_2 -> V_108 ) ;
if ( V_2 -> V_109 == V_19 ) {
V_2 -> V_109 = F_44 ( V_2 -> V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_108 ,
V_101 ,
V_18 ) ;
V_2 -> V_110 = 1 ;
} else {
F_45 ( V_2 -> V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_109 , V_101 ,
V_18 ) ;
V_2 -> V_110 = 0 ;
}
V_101 = V_2 -> V_2 . V_106 + V_107 + 2 ;
V_102 = V_2 -> V_109 ;
V_102 = ( T_3 ) ( ( ( V_102 >> 2 ) << 2 ) + 4 ) ;
for ( V_63 = 0 ; V_63 < V_77 - 1 ; V_63 ++ ) {
F_29 ( & V_79 -> V_87 , V_102 ) ;
F_29 ( ( T_3 T_4 * ) V_79 , ( V_83 | V_84 ) ) ;
V_102 = V_102 + V_101 ;
V_79 ++ ;
}
F_29 ( & V_79 -> V_87 , V_102 ) ;
F_29 ( ( T_3 T_4 * ) V_79 , ( V_83 | V_84 | V_85 ) ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_7 , unsigned char V_76 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ V_76 ] ;
struct V_93 T_4 * V_94 ;
T_1 V_111 , V_112 ;
T_1 V_102 ;
T_2 V_113 = 0 ;
V_94 = V_7 -> V_67 [ V_76 ] ;
V_111 = 0 ;
V_112 = ( V_2 -> V_2 . V_114 -> V_115 & V_116 ) ;
V_111 |= ( V_112 << V_117 ) ;
switch ( V_2 -> V_2 . V_114 -> V_118 & 0x03 ) {
case V_119 :
V_111 |= V_120 ;
break;
case V_121 :
V_111 |= V_122 ;
break;
case V_123 :
V_111 |= V_124 ;
break;
default:
V_111 |= V_125 ;
break;
}
switch ( V_2 -> V_32 ) {
case V_37 :
V_111 |= V_38 ;
break;
case V_33 :
V_111 |= V_34 ;
break;
default:
break;
}
F_15 ( & V_7 -> V_28 -> V_29 [ V_76 ] , V_111 ) ;
V_113 = 0x30 ;
F_28 ( & V_94 -> V_126 , V_113 ) ;
F_28 ( & V_94 -> V_127 , V_113 ) ;
V_102 = ( T_1 ) ( V_2 -> V_2 . V_106 + V_107 ) ;
V_102 = ( T_1 ) ( ( ( V_102 >> 2 ) << 2 ) + 4 ) ;
F_15 ( & V_94 -> V_128 , V_102 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 ,
unsigned char V_76 ,
const struct V_129 * V_114 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ V_76 ] ;
unsigned long V_130 ;
int V_131 = 0 ;
T_1 V_132 = 0 ;
V_132 = F_48 ( V_114 ) ;
if ( V_76 != 0 ) {
switch ( V_114 -> V_118 & V_133 ) {
case V_119 :
if ( strstr ( V_2 -> V_2 . V_21 , L_2 )
|| strstr ( V_2 -> V_2 . V_21 , L_3 ) )
goto V_134;
switch ( V_7 -> V_12 . V_135 ) {
case V_136 :
if ( ( V_132 == 128 ) || ( V_132 == 256 ) || ( V_132 == 512 ) )
break;
default:
switch ( V_132 ) {
case 4 :
case 8 :
case 16 :
case 32 :
case 64 :
break;
default:
case V_137 :
goto V_134;
}
}
break;
case V_123 :
if ( strstr ( V_2 -> V_2 . V_21 , L_2 ) )
goto V_134;
switch ( V_7 -> V_12 . V_135 ) {
case V_136 :
if ( V_132 <= 1024 )
break;
case V_138 :
if ( V_132 <= 64 )
break;
default:
if ( V_132 <= 8 )
break;
goto V_134;
}
break;
case V_121 :
if ( strstr ( V_2 -> V_2 . V_21 , L_4 )
|| strstr ( V_2 -> V_2 . V_21 , L_3 ) )
goto V_134;
switch ( V_7 -> V_12 . V_135 ) {
case V_136 :
if ( V_132 <= 1024 )
break;
case V_138 :
if ( V_132 <= 1023 )
break;
default:
goto V_134;
}
break;
case V_139 :
if ( strstr ( V_2 -> V_2 . V_21 , L_2 )
|| strstr ( V_2 -> V_2 . V_21 , L_3 ) )
goto V_134;
switch ( V_7 -> V_12 . V_135 ) {
case V_136 :
case V_138 :
switch ( V_132 ) {
case 1 :
case 2 :
case 4 :
case 8 :
case 16 :
case 32 :
case 64 :
break;
default:
goto V_134;
}
case V_137 :
switch ( V_132 ) {
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
goto V_134;
}
default:
goto V_134;
}
break;
default:
goto V_134;
}
}
F_49 ( & V_7 -> V_23 , V_130 ) ;
V_2 -> V_2 . V_106 = V_132 ;
V_2 -> V_140 = ( T_2 ) ( V_114 -> V_118 & V_133 ) ;
V_2 -> V_2 . V_114 = V_114 ;
V_2 -> V_8 = 0 ;
V_2 -> V_141 = 1 ;
if ( V_76 == 0 ) {
V_2 -> V_32 = V_90 ;
V_7 -> V_42 = V_37 ;
V_7 -> V_40 = V_41 ;
} else {
switch ( V_114 -> V_115 & V_142 ) {
case V_37 :
V_2 -> V_32 = V_37 ;
break;
case V_33 :
V_2 -> V_32 = V_33 ;
default:
break;
}
}
F_34 ( V_7 , V_76 ) ;
if ( ( V_2 -> V_140 == V_143 ) || ( V_2 -> V_32 == V_37 ) ) {
V_131 = F_38 ( V_2 ) ;
if ( V_131 )
goto V_144;
}
if ( ( V_2 -> V_140 == V_143 ) || ( V_2 -> V_32 == V_33 ) ) {
V_2 -> V_145 = F_39 ( sizeof( * V_2 -> V_145 ) , V_105 ) ;
if ( ! V_2 -> V_145 )
goto V_146;
F_40 ( V_2 -> V_145 ) ;
}
F_46 ( V_7 , V_76 ) ;
F_50 ( & V_7 -> V_23 , V_130 ) ;
return 0 ;
V_146:
F_42 ( V_2 -> V_108 ) ;
F_42 ( V_2 -> V_104 ) ;
V_144:
F_50 ( & V_7 -> V_23 , V_130 ) ;
V_134:
F_51 ( V_7 -> V_13 , L_5 , V_2 -> V_2 . V_21 ) ;
return - V_147 ;
}
static inline void F_52 ( struct V_6 * V_7 )
{
F_53 ( & V_7 -> V_28 -> V_148 , V_149 ) ;
}
static inline void F_54 ( struct V_6 * V_7 )
{
F_55 ( & V_7 -> V_28 -> V_148 , V_149 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_3 V_150 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_2 -> V_100 ) ;
V_150 = V_84 | V_83 | ( V_150 & V_85 ) ;
F_29 ( ( T_3 T_4 * ) V_2 -> V_100 , V_150 ) ;
if ( V_150 & V_85 )
V_2 -> V_100 = V_2 -> V_82 ;
else
V_2 -> V_100 ++ ;
}
static void F_58 ( struct V_1 * V_2 , unsigned char V_151 )
{
T_3 V_150 ;
struct V_78 T_4 * V_79 , * V_152 ;
unsigned char V_153 = 0 ;
V_152 = V_2 -> V_99 ;
V_79 = V_2 -> V_100 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
while ( ! ( V_150 & V_83 ) && ! ( V_150 & V_154 ) && ! V_153 ) {
V_150 = V_83 | V_84 | ( V_150 & V_85 ) ;
F_29 ( ( T_3 T_4 * ) V_79 , V_150 ) ;
if ( V_150 & V_85 )
V_79 = V_2 -> V_82 ;
else
V_79 ++ ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
if ( V_151 && ( V_79 == V_152 ) )
V_153 = 1 ;
}
V_2 -> V_100 = V_79 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_78 T_4 * V_79 = V_2 -> V_99 ;
T_3 V_150 ;
T_2 V_27 = V_2 -> V_27 ;
struct V_6 * V_7 = V_2 -> V_7 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
if ( ! ( V_150 & V_83 ) && ! ( V_150 & V_154 ) ) {
V_79 = V_2 -> V_82 +
( ( F_14 ( & V_7 -> V_67 [ V_27 ] -> V_98 ) -
F_14 ( & V_7 -> V_67 [ V_27 ] -> V_97 ) )
>> 3 ) ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
if ( V_150 & V_85 )
V_79 = V_2 -> V_82 ;
else
V_79 ++ ;
V_2 -> V_100 = V_79 ;
F_58 ( V_2 , 0 ) ;
V_2 -> V_100 = V_2 -> V_99 ;
} else
F_58 ( V_2 , 1 ) ;
if ( F_14 ( & V_7 -> V_28 -> V_51 ) & V_48 )
F_15 ( & V_7 -> V_28 -> V_51 , V_48 ) ;
if ( V_2 -> V_52 <= 0 && ( ! F_11 ( & V_2 -> V_9 ) ) )
F_21 ( V_2 ) ;
V_2 -> V_155 = 0 ;
}
static int F_60 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ 0 ] ;
struct V_156 * V_157 ;
unsigned int V_158 ;
T_2 * V_159 ;
V_157 = V_2 -> V_104 ;
if ( ( F_61 ( V_157 ) & V_160 )
&& ( V_7 -> V_40 == V_41 ) ) {
V_158 = F_62 ( V_157 ) ;
if ( F_63 ( V_158 != 8 ) )
return - V_103 ;
V_159 = ( T_2 * ) & V_7 -> V_161 ;
memcpy ( V_159 , V_157 -> V_162 , V_158 ) ;
V_2 -> V_91 = 1 ;
F_64 ( V_7 , & V_7 -> V_161 ) ;
return 0 ;
}
return - V_103 ;
}
static int F_65 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ 0 ] ;
struct V_156 * V_157 ;
struct V_78 T_4 * V_79 ;
T_3 V_150 , V_16 ;
T_3 V_163 ;
V_157 = V_2 -> V_104 ;
if ( V_2 -> V_32 == V_33 ) {
F_51 ( V_7 -> V_13 , L_6 ) ;
return - V_103 ;
}
V_79 = V_2 -> V_99 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
V_16 = V_150 & V_154 ;
while ( ! ( V_150 & V_83 ) && V_16 ) {
if ( ( V_150 & V_164 ) && ( V_150 & V_165 )
&& ! ( V_150 & V_166 ) ) {
if ( V_16 == V_107 ) {
V_7 -> V_40 = V_41 ;
F_6 ( V_7 -> V_13 ,
L_7 ) ;
} else {
F_66 ( V_157 ) ;
V_163 = ( T_3 ) F_67 ( F_57 ( & V_79 -> V_87 ) ) ;
F_68 ( V_157 , ( T_2 * ) V_163 ) ;
F_69 ( V_157 ,
( V_16 - V_107 ) ) ;
F_70 ( V_157 , V_167 ) ;
switch ( V_150 & V_168 ) {
case V_169 :
F_71 ( V_157 , V_160 ) ;
break;
case V_170 :
F_71 ( V_157 , V_171 ) ;
break;
default:
F_71 ( V_157 , V_172 ) ;
break;
}
if ( ( V_150 & V_168 ) == V_169 )
F_60 ( V_7 ) ;
else
F_72 ( V_2 ) ;
}
} else {
F_51 ( V_7 -> V_13 , L_8 ) ;
}
F_56 ( V_2 ) ;
if ( V_150 & V_85 )
V_79 = V_2 -> V_82 ;
else
V_79 ++ ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
V_16 = V_150 & V_154 ;
}
V_2 -> V_99 = V_79 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_156 * V_157 ;
T_2 V_173 = 0 ;
unsigned int V_158 ;
T_2 * V_159 ;
struct V_3 * V_4 ;
V_157 = V_2 -> V_104 ;
if ( F_61 ( V_157 ) & V_171 )
V_173 = 0x1 ;
if ( V_173 != V_2 -> V_91 ) {
F_51 ( V_2 -> V_7 -> V_13 , L_9 ) ;
return - V_174 ;
}
V_158 = F_62 ( V_157 ) ;
if ( F_11 ( & V_2 -> V_9 ) ) {
F_51 ( V_2 -> V_7 -> V_13 , L_10 , V_2 -> V_21 ) ;
} else {
V_4 = F_12 ( V_2 -> V_9 . V_24 , struct V_3 , V_9 ) ;
V_159 = ( T_2 * ) ( V_4 -> V_4 . V_87 ) + V_4 -> V_4 . V_22 ;
if ( V_159 ) {
memcpy ( V_159 , V_157 -> V_162 , V_158 ) ;
V_4 -> V_4 . V_22 += V_158 ;
if ( ( V_158 < V_2 -> V_2 . V_106 ) ||
( V_4 -> V_4 . V_22 >= V_4 -> V_4 . V_16 ) ) {
if ( V_2 -> V_27 == 0 )
F_73 ( V_2 -> V_7 , V_4 ) ;
else
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_11 ( & V_2 -> V_9 ) && V_2 -> V_27 != 0 )
F_18 ( V_2 ) ;
}
}
}
F_33 ( V_2 ) ;
return 0 ;
}
static void F_74 ( unsigned long V_162 )
{
struct V_6 * V_7 = (struct V_6 * ) V_162 ;
struct V_1 * V_2 ;
struct V_156 * V_157 ;
struct V_78 T_4 * V_79 ;
unsigned long V_130 ;
T_3 V_150 , V_16 ;
T_3 V_163 , V_63 ;
F_49 ( & V_7 -> V_23 , V_130 ) ;
for ( V_63 = 1 ; V_63 < V_175 ; V_63 ++ ) {
V_2 = & V_7 -> V_39 [ V_63 ] ;
if ( V_2 -> V_32 == V_33 || V_2 -> V_176 == 0 ) {
F_75 ( V_7 -> V_13 ,
L_11 ) ;
continue;
}
V_157 = V_2 -> V_104 ;
V_79 = V_2 -> V_99 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
V_16 = V_150 & V_154 ;
while ( ! ( V_150 & V_83 ) && V_16 ) {
if ( F_11 ( & V_2 -> V_9 ) ) {
F_18 ( V_2 ) ;
F_75 ( V_7 -> V_13 ,
L_12 ,
V_2 -> V_52 ) ;
break;
}
if ( ( V_150 & V_164 ) && ( V_150 & V_165 )
&& ! ( V_150 & V_166 ) ) {
F_66 ( V_157 ) ;
V_163 = ( T_3 ) F_67 ( F_57 ( & V_79 -> V_87 ) ) ;
F_68 ( V_157 , ( T_2 * ) V_163 ) ;
F_69 ( V_157 ,
( V_16 - V_107 ) ) ;
F_70 ( V_157 , V_167 ) ;
switch ( V_150 & V_168 ) {
case V_170 :
F_71 ( V_157 , V_171 ) ;
break;
case V_169 :
F_71 ( V_157 , V_160 ) ;
break;
default:
F_71 ( V_157 , V_172 ) ;
break;
}
F_72 ( V_2 ) ;
} else {
F_51 ( V_7 -> V_13 ,
L_13 ) ;
}
F_29 ( ( T_3 T_4 * ) V_79 , V_150 & V_177 ) ;
V_2 -> V_52 -- ;
if ( ! ( V_2 -> V_155 ) )
F_56 ( V_2 ) ;
if ( V_150 & V_85 )
V_79 = V_2 -> V_82 ;
else
V_79 ++ ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
V_16 = V_150 & V_154 ;
}
V_2 -> V_99 = V_79 ;
if ( V_2 -> V_155 )
F_59 ( V_2 ) ;
V_2 -> V_176 = 0 ;
}
F_50 ( & V_7 -> V_23 , V_130 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_156 * V_157 ;
struct V_78 T_4 * V_79 ;
T_1 V_178 , V_179 , V_180 ;
V_7 = V_2 -> V_7 ;
V_157 = V_2 -> V_104 ;
if ( V_2 -> V_32 == V_33 ) {
F_51 ( V_7 -> V_13 , L_14 ) ;
return - V_103 ;
}
V_79 = V_2 -> V_99 ;
V_178 = ( T_1 ) ( V_79 - V_2 -> V_82 ) ;
V_179 = ( T_1 ) ( ( F_14 ( & V_7 -> V_67 [ V_2 -> V_27 ] -> V_98 ) -
F_14 ( & V_7 -> V_67 [ V_2 -> V_27 ] -> V_97 ) ) >> 3 ) ;
if ( V_178 < V_179 )
V_180 = V_80 - V_179 + V_178 ;
else
V_180 = V_178 - V_179 ;
if ( V_180 < V_181 ) {
F_18 ( V_2 ) ;
V_2 -> V_155 = 1 ;
F_6 ( V_7 -> V_13 , L_15 , V_180 ) ;
}
V_2 -> V_52 = V_80 - V_180 ;
if ( F_11 ( & V_2 -> V_9 ) ) {
F_18 ( V_2 ) ;
F_6 ( V_7 -> V_13 , L_16 ,
V_2 -> V_52 ) ;
return 0 ;
}
F_77 ( & V_7 -> V_182 ) ;
V_2 -> V_176 = 1 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_156 * V_183 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_78 T_4 * V_79 ;
T_1 V_184 ;
T_3 V_150 , V_185 ;
T_3 V_186 ;
if ( V_2 -> V_32 == V_37 ) {
F_51 ( V_7 -> V_13 , L_17 ) ;
return - V_103 ;
}
V_184 = F_14 ( & V_7 -> V_28 -> V_46 ) ;
F_15 ( & V_7 -> V_28 -> V_46 ,
V_184 & ~ ( V_187 | V_188 ) ) ;
V_79 = V_2 -> V_74 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
if ( ! ( V_150 & ( V_189 | V_154 ) ) ) {
if ( F_62 ( V_183 ) == 0 ) {
F_68 ( V_183 , V_7 -> V_190 ) ;
F_69 ( V_183 , 2 ) ;
V_183 -> V_191 |= ( V_192 | V_193 ) ;
F_6 ( V_7 -> V_13 , L_18 ) ;
}
V_186 = F_43 ( ( void * ) V_183 -> V_162 ) ;
F_29 ( & V_79 -> V_87 , V_186 ) ;
V_150 = ( V_150 & V_88 ) ;
if ( ! ( F_61 ( V_183 ) & V_193 ) )
V_150 |= V_189 | V_194 | V_195 | V_196
| F_62 ( V_183 ) ;
else
V_150 |= V_189 | V_194 | V_195 | F_62 ( V_183 ) ;
if ( ( V_2 -> V_27 == 0 ) && ( V_7 -> V_40 == V_197 ) )
V_2 -> V_91 = 0x1 ;
if ( V_2 -> V_91 ) {
V_185 = V_198 ;
V_183 -> V_191 |= V_171 ;
} else {
V_185 = V_199 ;
V_183 -> V_191 |= V_172 ;
}
V_150 |= V_200 ;
V_150 |= V_185 ;
F_29 ( ( T_3 T_4 * ) V_79 , V_150 ) ;
F_30 ( V_2 ) ;
F_15 ( & V_7 -> V_28 -> V_46 , V_184 ) ;
F_33 ( V_2 ) ;
if ( V_150 & V_88 )
V_2 -> V_74 = V_2 -> V_73 ;
else
V_2 -> V_74 ++ ;
return 0 ;
} else {
F_15 ( & V_7 -> V_28 -> V_46 , V_184 ) ;
F_6 ( V_7 -> V_13 , L_19 ) ;
return - V_201 ;
}
}
static int F_79 ( struct V_1 * V_2 , unsigned char V_202 )
{
if ( V_2 -> V_203 != NULL ) {
struct V_3 * V_4 = V_2 -> V_203 ;
unsigned V_204 = 0 , V_205 = 0 ;
V_205 = F_80 ( unsigned , V_4 -> V_4 . V_16 - V_2 -> V_206 ,
V_2 -> V_2 . V_106 ) ;
if ( ! V_202 ) {
int V_207 = V_2 -> V_208 ;
V_2 -> V_206 += V_207 ;
V_2 -> V_208 -= V_207 ;
} else {
V_2 -> V_208 = 0 ;
}
if ( V_4 -> V_4 . V_209 ) {
if ( V_205 == 0 ||
( V_4 -> V_4 . V_16 % V_2 -> V_2 . V_106 ) != 0 )
V_204 = 0 ;
else
V_204 = 1 ;
} else
V_204 = 0 ;
if ( ( ( V_2 -> V_203 -> V_4 . V_16 - V_2 -> V_206 ) <= 0 ) && ! V_204 ) {
F_1 ( V_2 , V_2 -> V_203 , 0 ) ;
V_2 -> V_203 = NULL ;
V_2 -> V_208 = 0 ;
V_2 -> V_206 = 0 ;
}
}
if ( V_2 -> V_203 == NULL ) {
if ( ! F_11 ( & V_2 -> V_9 ) ) {
V_2 -> V_203 = F_12 ( V_2 -> V_9 . V_24 , struct V_3 ,
V_9 ) ;
V_2 -> V_208 = 0 ;
V_2 -> V_206 = 0 ;
}
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_156 * V_183 )
{
unsigned int V_101 ;
T_2 * V_87 ;
F_66 ( V_183 ) ;
V_101 = F_80 ( T_3 , ( V_2 -> V_203 -> V_4 . V_16 - V_2 -> V_206 ) ,
V_2 -> V_2 . V_106 ) ;
V_87 = ( T_2 * ) V_2 -> V_203 -> V_4 . V_87 + V_2 -> V_206 ;
if ( V_87 && V_101 ) {
V_2 -> V_208 = V_101 ;
V_2 -> V_203 -> V_4 . V_22 += V_101 ;
F_68 ( V_183 , V_87 ) ;
F_69 ( V_183 , V_101 ) ;
F_70 ( V_183 , V_167 ) ;
F_71 ( V_183 , 0 ) ;
return F_78 ( V_2 , V_183 ) ;
}
return - V_174 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_156 * V_183 , T_5 V_210 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_183 == NULL )
return - V_147 ;
F_66 ( V_183 ) ;
F_68 ( V_183 , ( T_2 * ) V_7 -> V_190 ) ;
F_69 ( V_183 , 2 ) ;
F_70 ( V_183 , V_167 ) ;
F_71 ( V_183 , ( V_192 | V_193 | V_210 ) ) ;
return F_78 ( V_2 , V_183 ) ;
}
static int F_83 ( struct V_1 * V_2 , struct V_156 * V_183 )
{
struct V_3 * V_4 = V_2 -> V_203 ;
int V_131 ;
if ( V_4 == NULL )
return - V_147 ;
if ( ( V_4 -> V_4 . V_16 - V_2 -> V_206 ) > 0 )
V_131 = F_81 ( V_2 , V_183 ) ;
else
V_131 = F_82 ( V_2 , V_183 , 0 ) ;
return V_131 ;
}
static int F_84 ( struct V_6 * V_7 , int V_211 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ 0 ] ;
if ( V_211 == V_33 ) {
V_7 -> V_40 = V_197 ;
V_7 -> V_42 = V_33 ;
F_82 ( V_2 , V_2 -> V_145 , V_212 | V_213 ) ;
} else {
V_7 -> V_42 = V_37 ;
V_7 -> V_40 = V_214 ;
}
return 0 ;
}
static void F_73 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ 0 ] ;
switch ( V_7 -> V_40 ) {
case V_215 :
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_84 ( V_7 , V_37 ) )
F_17 ( V_7 ) ;
break;
case V_197 :
F_1 ( V_2 , V_4 , 0 ) ;
V_7 -> V_40 = V_41 ;
break;
case V_216 :
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_84 ( V_7 , V_33 ) )
F_17 ( V_7 ) ;
break;
case V_214 :
F_1 ( V_2 , V_4 , 0 ) ;
V_7 -> V_40 = V_41 ;
break;
case V_41 :
F_6 ( V_7 -> V_13 , L_20 ) ;
break;
default:
F_17 ( V_7 ) ;
break;
}
}
static int F_85 ( struct V_1 * V_2 , unsigned char V_202 )
{
struct V_3 * V_203 = NULL ;
struct V_156 * V_183 = V_2 -> V_145 ;
if ( ( F_61 ( V_183 ) & ( V_192 | V_213 ) ) == ( V_192 | V_213 ) ) {
if ( ! V_202 )
V_2 -> V_7 -> V_40 = V_41 ;
else
F_82 ( V_2 , V_2 -> V_145 , V_212 | V_213 ) ;
return 0 ;
}
V_203 = V_2 -> V_203 ;
if ( V_203 != NULL ) {
if ( ! V_202 ) {
int V_207 = V_2 -> V_208 ;
V_2 -> V_206 += V_207 ;
V_2 -> V_208 -= V_207 ;
} else {
V_2 -> V_208 = 0 ;
}
if ( ( V_2 -> V_203 -> V_4 . V_16 - V_2 -> V_206 ) <= 0 ) {
V_2 -> V_203 -> V_4 . V_22 = ( unsigned int ) V_2 -> V_206 ;
F_73 ( V_2 -> V_7 , V_2 -> V_203 ) ;
V_2 -> V_203 = NULL ;
V_2 -> V_208 = 0 ;
V_2 -> V_206 = 0 ;
}
} else {
F_6 ( V_2 -> V_7 -> V_13 , L_21 ) ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
if ( F_87 ( V_2 -> V_145 ) & V_217 ) {
F_27 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_13 , L_22 ) ;
if ( F_61 ( V_2 -> V_145 ) & V_172 )
V_2 -> V_91 = 0 ;
else
V_2 -> V_91 = 1 ;
F_85 ( V_2 , 1 ) ;
} else
F_85 ( V_2 , 0 ) ;
F_83 ( V_2 , V_2 -> V_145 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_78 T_4 * V_79 ;
struct V_156 * V_157 ;
T_3 V_150 ;
V_79 = V_2 -> V_72 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
while ( ! ( V_150 & V_189 ) && ( V_150 & ~ V_88 ) ) {
V_157 = V_2 -> V_145 ;
F_29 ( ( T_3 T_4 * ) V_79 , V_150 & V_88 ) ;
F_29 ( & V_79 -> V_87 , 0 ) ;
if ( V_150 & V_88 )
V_2 -> V_72 = V_2 -> V_73 ;
else
V_2 -> V_72 ++ ;
if ( V_2 -> V_72 == V_2 -> V_74 ) {
if ( V_150 & V_218 ) {
F_70 ( V_157 , V_217 ) ;
if ( V_150 & V_219 )
V_157 -> V_5 |= V_220 ;
if ( V_150 & V_221 )
V_157 -> V_5 |= V_222 ;
}
F_86 ( V_2 ) ;
}
V_79 = V_2 -> V_72 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
if ( F_87 ( V_2 -> V_145 ) & V_217 ) {
F_27 ( V_2 ) ;
F_6 ( V_2 -> V_7 -> V_13 , L_22 ) ;
if ( F_61 ( V_2 -> V_145 ) & V_172 )
V_2 -> V_91 = 0 ;
else
V_2 -> V_91 = 1 ;
F_79 ( V_2 , 1 ) ;
} else
F_79 ( V_2 , 0 ) ;
F_83 ( V_2 , V_2 -> V_145 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_78 T_4 * V_79 ;
struct V_156 * V_157 = NULL ;
T_3 V_150 ;
unsigned char V_223 = 0 ;
V_79 = V_2 -> V_72 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
while ( ! ( V_150 & V_189 ) && ( V_150 & ~ V_88 ) ) {
V_157 = V_2 -> V_145 ;
if ( V_150 & V_218 ) {
F_70 ( V_157 , V_217 ) ;
if ( V_150 & V_219 )
V_157 -> V_5 |= V_220 ;
if ( V_150 & V_221 )
V_157 -> V_5 |= V_222 ;
}
F_29 ( ( T_3 T_4 * ) V_79 , V_150 & V_88 ) ;
F_29 ( & V_79 -> V_87 , 0 ) ;
if ( V_150 & V_88 )
V_2 -> V_72 = V_2 -> V_73 ;
else
V_2 -> V_72 ++ ;
F_89 ( V_2 ) ;
V_79 = V_2 -> V_72 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
}
if ( V_223 )
return - V_174 ;
else
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_131 = 0 ;
if ( V_2 -> V_203 == NULL ) {
V_2 -> V_206 = 0 ;
V_2 -> V_208 = 0 ;
F_79 ( V_2 , 0 ) ;
V_131 = F_83 ( V_2 , V_2 -> V_145 ) ;
}
return V_131 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_156 * V_157 = NULL ;
struct V_78 T_4 * V_79 ;
T_3 V_150 , V_16 ;
T_3 V_163 , V_158 ;
T_2 * V_159 ;
T_2 V_224 = 0 ;
T_2 V_173 ;
if ( F_11 ( & V_2 -> V_9 ) ) {
F_6 ( V_7 -> V_13 , L_23 ) ;
return 0 ;
}
V_157 = V_2 -> V_104 ;
V_79 = V_2 -> V_99 ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
V_16 = V_150 & V_154 ;
while ( ! ( V_150 & V_83 ) && V_16 ) {
if ( V_224 )
break;
if ( ( V_150 & V_164 ) && ( V_150 & V_165 )
&& ! ( V_150 & V_166 ) ) {
F_66 ( V_157 ) ;
V_163 = ( T_3 ) F_67 ( F_57 ( & V_79 -> V_87 ) ) ;
F_68 ( V_157 , ( T_2 * ) V_163 ) ;
F_69 ( V_157 , ( V_16 - V_107 ) ) ;
F_70 ( V_157 , V_167 ) ;
switch ( V_150 & V_168 ) {
case V_170 :
F_71 ( V_157 , V_171 ) ; break;
default:
F_71 ( V_157 , V_172 ) ; break;
}
if ( F_61 ( V_157 ) & V_171 )
V_173 = 0x1 ;
else
V_173 = 0 ;
if ( V_173 != V_2 -> V_91 ) {
F_6 ( V_7 -> V_13 , L_9 ) ;
} else {
V_158 = F_62 ( V_157 ) ;
V_159 = ( T_2 * ) ( V_4 -> V_4 . V_87 ) + V_4 -> V_4 . V_22 ;
if ( V_159 ) {
memcpy ( V_159 , V_157 -> V_162 , V_158 ) ;
V_4 -> V_4 . V_22 += V_158 ;
if ( ( V_158 < V_2 -> V_2 . V_106 )
|| ( V_4 -> V_4 . V_22 >=
V_4 -> V_4 . V_16 ) ) {
V_224 = 1 ;
F_1 ( V_2 , V_4 , 0 ) ;
if ( F_11 ( & V_2 -> V_9 ) )
F_18 ( V_2 ) ;
}
}
F_33 ( V_2 ) ;
}
} else {
F_51 ( V_7 -> V_13 , L_8 ) ;
}
F_29 ( ( T_3 T_4 * ) V_79 , ( V_150 & V_177 ) ) ;
V_2 -> V_52 -- ;
if ( V_150 & V_85 )
V_79 = V_2 -> V_82 ;
else
V_79 ++ ;
V_150 = F_57 ( ( T_3 T_4 * ) V_79 ) ;
V_16 = V_150 & V_154 ;
}
V_2 -> V_99 = V_79 ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_43 == V_49 ) {
if ( V_2 -> V_52 <= 0 ) {
F_21 ( V_2 ) ;
} else {
F_92 ( V_2 , V_4 ) ;
}
}
return 0 ;
}
static int F_94 ( struct V_225 * V_226 ,
const struct V_129 * V_114 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_227 = 0 ;
unsigned char V_27 ;
V_2 = F_95 ( V_226 , struct V_1 , V_2 ) ;
if ( ! V_226 || ! V_114 || V_226 -> V_21 == V_228 [ 0 ] ||
( V_114 -> V_229 != V_230 ) )
return - V_103 ;
V_7 = V_2 -> V_7 ;
if ( ! V_7 -> V_231 || ( V_7 -> V_12 . V_135 == V_232 ) )
return - V_20 ;
V_27 = ( T_2 ) V_114 -> V_115 & 0xF ;
V_227 = F_47 ( V_7 , V_27 , V_114 ) ;
if ( V_227 != 0 ) {
F_96 ( F_97 ( V_2 -> V_82 ) ) ;
F_75 ( V_7 -> V_13 , L_24 , V_2 -> V_27 ) ;
return - V_103 ;
}
F_75 ( V_7 -> V_13 , L_25 , V_2 -> V_27 ) ;
return 0 ;
}
static int F_98 ( struct V_225 * V_226 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
unsigned long V_130 ;
unsigned int V_101 ;
V_2 = F_95 ( V_226 , struct V_1 , V_2 ) ;
V_7 = V_2 -> V_7 ;
if ( ! V_226 || ! V_2 -> V_2 . V_114 ) {
F_75 ( V_7 -> V_13 , L_26 , V_226 ? V_2 -> V_2 . V_21 : NULL ) ;
return - V_103 ;
}
F_49 ( & V_7 -> V_23 , V_130 ) ;
F_10 ( V_2 , - V_20 ) ;
V_2 -> V_2 . V_114 = NULL ;
V_2 -> V_8 = 1 ;
V_2 -> V_203 = NULL ;
F_32 ( V_7 , V_2 -> V_27 ) ;
F_50 ( & V_7 -> V_23 , V_130 ) ;
F_96 ( F_97 ( V_2 -> V_82 ) ) ;
if ( V_2 -> V_32 == V_37 )
V_101 = ( V_2 -> V_2 . V_106 + V_107 + 2 ) *
( V_80 + 1 ) ;
else
V_101 = ( V_2 -> V_2 . V_106 + V_107 + 2 ) *
( V_81 + 1 ) ;
if ( V_2 -> V_32 != V_33 ) {
F_42 ( V_2 -> V_104 ) ;
if ( V_2 -> V_110 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_109 , V_101 ,
V_18 ) ;
V_2 -> V_109 = V_19 ;
} else {
F_5 (
V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_109 , V_101 ,
V_18 ) ;
}
F_42 ( V_2 -> V_108 ) ;
}
if ( V_2 -> V_32 != V_37 )
F_42 ( V_2 -> V_145 ) ;
F_75 ( V_7 -> V_13 , L_27 , V_226 -> V_21 ) ;
return 0 ;
}
static struct V_233 * F_99 ( struct V_225 * V_226 , T_6 V_234 )
{
struct V_3 * V_4 ;
V_4 = F_41 ( sizeof( * V_4 ) , V_234 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_4 . V_15 = V_19 ;
F_100 ( & V_4 -> V_9 ) ;
return & V_4 -> V_4 ;
}
static void F_101 ( struct V_225 * V_226 , struct V_233 * V_235 )
{
struct V_3 * V_4 ;
V_4 = F_95 ( V_235 , struct V_3 , V_4 ) ;
if ( V_235 )
F_42 ( V_4 ) ;
}
static int F_102 ( struct V_225 * V_226 , struct V_233 * V_235 )
{
struct V_1 * V_2 = F_95 ( V_226 , struct V_1 , V_2 ) ;
struct V_3 * V_4 = F_95 ( V_235 , struct V_3 , V_4 ) ;
struct V_6 * V_7 ;
int V_131 ;
V_7 = V_2 -> V_7 ;
if ( ! V_235 || ! V_4 -> V_4 . V_236 || ! V_4 -> V_4 . V_87
|| ! F_11 ( & V_4 -> V_9 ) ) {
F_75 ( V_7 -> V_13 , L_28 ) ;
return - V_103 ;
}
if ( ! V_226 || ( ! V_2 -> V_2 . V_114 && F_103 ( V_2 ) ) ) {
F_75 ( V_7 -> V_13 , L_29 ) ;
return - V_103 ;
}
if ( ! V_7 -> V_231 || V_7 -> V_12 . V_135 == V_232 )
return - V_20 ;
V_4 -> V_2 = V_2 ;
if ( V_4 -> V_4 . V_15 == V_19 ) {
V_4 -> V_4 . V_15 = F_44 ( V_2 -> V_7 -> V_12 . V_13 . V_14 ,
V_4 -> V_4 . V_87 ,
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
F_104 ( & V_4 -> V_9 , & V_2 -> V_9 ) ;
F_6 ( V_7 -> V_13 , L_30 ,
V_2 -> V_21 , V_4 -> V_4 . V_16 ) ;
if ( F_4 ( V_2 ) )
V_131 = F_91 ( V_2 , V_4 ) ;
if ( F_103 ( V_2 ) == 0 && V_4 -> V_4 . V_16 > 0 ) {
if ( F_4 ( V_2 ) )
V_7 -> V_40 = V_215 ;
else
V_7 -> V_40 = V_216 ;
}
if ( V_2 -> V_32 == V_37 )
V_131 = F_93 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_105 ( struct V_225 * V_226 , struct V_233 * V_235 ,
T_6 V_234 )
{
struct V_1 * V_2 = F_95 ( V_226 , struct V_1 , V_2 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
unsigned long V_130 ;
int V_237 ;
F_49 ( & V_7 -> V_23 , V_130 ) ;
V_237 = F_102 ( V_226 , V_235 ) ;
F_50 ( & V_7 -> V_23 , V_130 ) ;
return V_237 ;
}
static int F_106 ( struct V_225 * V_226 , struct V_233 * V_235 )
{
struct V_1 * V_2 = F_95 ( V_226 , struct V_1 , V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_130 ;
if ( ! V_226 || ! V_235 )
return - V_103 ;
F_49 ( & V_2 -> V_7 -> V_23 , V_130 ) ;
F_107 (req, &ep->queue, queue) {
if ( & V_4 -> V_4 == V_235 )
break;
}
if ( & V_4 -> V_4 != V_235 ) {
F_50 ( & V_2 -> V_7 -> V_23 , V_130 ) ;
return - V_103 ;
}
F_1 ( V_2 , V_4 , - V_238 ) ;
F_50 ( & V_2 -> V_7 -> V_23 , V_130 ) ;
return 0 ;
}
static int F_108 ( struct V_225 * V_226 , int V_25 )
{
struct V_1 * V_2 ;
unsigned long V_130 ;
int V_5 = - V_239 ;
struct V_6 * V_7 ;
V_2 = F_95 ( V_226 , struct V_1 , V_2 ) ;
if ( ! V_226 || ! V_2 -> V_2 . V_114 ) {
V_5 = - V_103 ;
goto V_240;
}
V_7 = V_2 -> V_7 ;
if ( V_25 && F_4 ( V_2 ) && ! F_11 ( & V_2 -> V_9 ) ) {
V_5 = - V_241 ;
goto V_240;
}
V_5 = 0 ;
F_49 ( & V_2 -> V_7 -> V_23 , V_130 ) ;
F_16 ( V_2 , V_25 ) ;
F_13 ( V_2 , V_25 ) ;
F_50 ( & V_2 -> V_7 -> V_23 , V_130 ) ;
if ( V_2 -> V_27 == 0 ) {
V_7 -> V_40 = V_41 ;
V_7 -> V_42 = 0 ;
}
if ( V_25 == 0 )
V_2 -> V_91 = 0 ;
V_240:
F_6 ( V_7 -> V_13 , L_31 , V_2 -> V_2 . V_21 ,
V_25 ? L_32 : L_33 , V_5 ) ;
return V_5 ;
}
static int F_109 ( struct V_242 * V_12 )
{
struct V_6 * V_7 = F_95 ( V_12 , struct V_6 , V_12 ) ;
T_1 V_102 ;
V_102 = F_14 ( & V_7 -> V_243 -> V_244 ) ;
if ( V_102 & 0x8000 )
return V_102 & 0x07ff ;
return - V_103 ;
}
static int F_110 ( struct V_6 * V_7 , T_2 V_245 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ V_245 ] ;
F_10 ( V_2 , - V_238 ) ;
V_2 -> V_203 = NULL ;
return 0 ;
}
static int F_111 ( struct V_6 * V_7 )
{
T_2 V_245 ;
for ( V_245 = 0 ; V_245 < V_175 ; V_245 ++ )
F_110 ( V_7 , V_245 ) ;
F_7 ( & V_7 -> V_23 ) ;
F_112 ( & V_7 -> V_12 , V_7 -> V_231 ) ;
F_9 ( & V_7 -> V_23 ) ;
return 0 ;
}
static void F_113 ( struct V_6 * V_7 , T_1 V_25 , T_1 V_246 ,
T_1 V_16 )
{
V_7 -> V_247 = ( T_2 ) V_25 ;
V_7 -> V_248 = V_249 ;
if ( F_84 ( V_7 , V_33 ) )
F_17 ( V_7 ) ;
}
static void F_114 ( struct V_225 * V_226 , struct V_233 * V_235 )
{
struct V_3 * V_4 = F_95 ( V_235 , struct V_3 , V_4 ) ;
V_4 -> V_4 . V_87 = NULL ;
F_42 ( V_4 ) ;
}
static void F_115 ( struct V_6 * V_7 , T_2 V_250 , T_1 V_25 ,
T_1 V_246 , T_1 V_16 )
{
T_1 V_251 = 0 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_5 = 0 ;
V_2 = & V_7 -> V_39 [ 0 ] ;
if ( ( V_250 & V_252 ) == V_253 ) {
V_251 = 1 << V_254 ;
} else if ( ( V_250 & V_252 ) == V_255 ) {
V_251 = 0 ;
} else if ( ( V_250 & V_252 ) == V_256 ) {
int V_245 = V_246 & V_116 ;
struct V_1 * V_257 = & V_7 -> V_39 [ V_245 ] ;
T_1 V_111 ;
if ( ! V_257 -> V_2 . V_114 )
goto V_258;
V_111 = F_14 ( & V_7 -> V_28 -> V_29 [ V_245 ] ) ;
if ( V_246 & V_33 ) {
if ( V_257 -> V_32 != V_33 )
goto V_258;
if ( ( V_111 & V_35 ) == V_36 )
V_251 = 1 << V_259 ;
} else {
if ( V_257 -> V_32 != V_37 )
goto V_258;
if ( ( V_111 & V_30 ) == V_31 )
V_251 = 1 << V_259 ;
}
}
V_4 = F_95 ( F_99 ( & V_2 -> V_2 , V_260 ) ,
struct V_3 , V_4 ) ;
V_4 -> V_4 . V_16 = 2 ;
V_4 -> V_4 . V_87 = V_7 -> V_261 ;
* ( T_1 * ) V_4 -> V_4 . V_87 = F_116 ( V_251 ) ;
V_4 -> V_4 . V_5 = - V_10 ;
V_4 -> V_4 . V_22 = 0 ;
V_4 -> V_4 . V_236 = F_114 ;
V_7 -> V_42 = V_33 ;
V_5 = F_102 ( & V_2 -> V_2 , & V_4 -> V_4 ) ;
if ( V_5 == 0 )
return;
V_258:
F_51 ( V_7 -> V_13 , L_34 ) ;
F_17 ( V_7 ) ;
}
static void F_64 ( struct V_6 * V_7 ,
struct V_262 * V_263 )
{
T_1 V_264 = F_117 ( V_263 -> V_264 ) ;
T_1 V_265 = F_117 ( V_263 -> V_265 ) ;
T_1 V_266 = F_117 ( V_263 -> V_266 ) ;
F_110 ( V_7 , 0 ) ;
if ( V_263 -> V_267 & V_33 )
V_7 -> V_42 = V_33 ;
else
V_7 -> V_42 = V_37 ;
switch ( V_263 -> V_268 ) {
case V_269 :
if ( ( V_263 -> V_267 & ( V_33 | V_270 ) )
!= ( V_33 | V_271 ) )
break;
F_115 ( V_7 , V_263 -> V_267 , V_264 , V_265 ,
V_266 ) ;
return;
case V_272 :
if ( V_263 -> V_267 != ( V_37 | V_271 |
V_253 ) )
break;
F_113 ( V_7 , V_264 , V_265 , V_266 ) ;
return;
case V_273 :
case V_274 :
if ( ( V_263 -> V_267 & V_270 )
!= V_271 )
break;
if ( ( V_263 -> V_267 & V_252 )
== V_256 ) {
int V_245 = V_265 & V_116 ;
struct V_1 * V_2 ;
if ( V_264 != 0 || V_266 != 0
|| V_245 >= V_175 )
break;
V_2 = & V_7 -> V_39 [ V_245 ] ;
F_7 ( & V_7 -> V_23 ) ;
F_108 ( & V_2 -> V_2 ,
( V_263 -> V_268 == V_274 )
? 1 : 0 ) ;
F_9 ( & V_7 -> V_23 ) ;
}
F_84 ( V_7 , V_33 ) ;
return;
default:
break;
}
if ( V_266 ) {
if ( V_263 -> V_267 & V_33 ) {
V_7 -> V_40 = V_215 ;
V_7 -> V_42 = V_33 ;
} else {
V_7 -> V_40 = V_216 ;
V_7 -> V_42 = V_37 ;
}
F_7 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_231 -> V_263 ( & V_7 -> V_12 ,
& V_7 -> V_161 ) < 0 )
F_17 ( V_7 ) ;
F_9 ( & V_7 -> V_23 ) ;
} else {
V_7 -> V_42 = V_33 ;
F_7 ( & V_7 -> V_23 ) ;
if ( V_7 -> V_231 -> V_263 ( & V_7 -> V_12 ,
& V_7 -> V_161 ) < 0 )
F_17 ( V_7 ) ;
F_9 ( & V_7 -> V_23 ) ;
V_7 -> V_40 = V_197 ;
}
}
static void F_118 ( struct V_6 * V_7 )
{
V_7 -> V_275 = V_7 -> V_248 ;
V_7 -> V_248 = V_276 ;
if ( V_7 -> V_231 -> V_277 )
V_7 -> V_231 -> V_277 ( & V_7 -> V_12 ) ;
}
static void F_119 ( struct V_6 * V_7 )
{
V_7 -> V_248 = V_7 -> V_275 ;
V_7 -> V_275 = 0 ;
if ( V_7 -> V_231 -> V_278 )
V_7 -> V_231 -> V_278 ( & V_7 -> V_12 ) ;
}
static void F_120 ( struct V_6 * V_7 )
{
T_2 V_279 ;
V_279 = F_121 ( & V_7 -> V_28 -> V_280 ) ;
if ( V_279 & V_281 ) {
if ( ( V_7 -> V_248 ) != V_276 )
F_118 ( V_7 ) ;
} else {
if ( V_7 -> V_248 == V_276 )
F_119 ( V_7 ) ;
}
}
static int F_122 ( struct V_6 * V_7 )
{
unsigned char V_63 ;
if ( V_7 -> V_248 == V_282 )
return 0 ;
F_54 ( V_7 ) ;
F_28 ( & V_7 -> V_28 -> V_283 , 0 ) ;
for ( V_63 = 0 ; V_63 < V_175 ; V_63 ++ ) {
if ( V_7 -> V_39 [ V_63 ] . V_141 )
F_32 ( V_7 , V_63 ) ;
}
F_111 ( V_7 ) ;
V_7 -> V_248 = V_282 ;
V_7 -> V_40 = V_41 ;
V_7 -> V_42 = V_37 ;
F_52 ( V_7 ) ;
return 0 ;
}
static int F_123 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_124 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_125 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_78 T_4 * V_79 ;
int V_63 , V_284 = 0 ;
if ( ( V_7 -> V_248 == V_249 )
&& ( F_121 ( & V_7 -> V_28 -> V_283 ) == 0 ) )
F_28 ( & V_7 -> V_28 -> V_283 , V_7 -> V_247 ) ;
for ( V_63 = ( V_175 - 1 ) ; ( ( V_63 >= 0 ) && ( V_284 == 0 ) ) ; V_63 -- ) {
V_2 = & V_7 -> V_39 [ V_63 ] ;
if ( V_2 && V_2 -> V_141 && ( V_2 -> V_32 != V_37 ) ) {
V_79 = V_2 -> V_72 ;
if ( ! ( F_57 ( ( T_3 T_4 * ) V_79 ) & V_189 )
&& ( F_57 ( & V_79 -> V_87 ) ) ) {
if ( V_2 -> V_27 == 0 )
V_284 = F_88 ( V_2 ) ;
else
V_284 = F_90 ( V_2 ) ;
}
}
}
return V_284 ;
}
static void F_126 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_78 T_4 * V_79 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_175 ; V_63 ++ ) {
V_2 = & V_7 -> V_39 [ V_63 ] ;
if ( V_2 && V_2 -> V_141 && ( V_2 -> V_32 != V_33 ) ) {
V_79 = V_2 -> V_99 ;
if ( ! ( F_57 ( ( T_3 T_4 * ) V_79 ) & V_83 )
&& ( F_57 ( & V_79 -> V_87 ) ) ) {
if ( V_2 -> V_27 == 0 ) {
F_65 ( V_7 ) ;
} else {
F_76 ( V_2 ) ;
}
}
}
}
}
static T_7 F_127 ( int V_285 , void * V_286 )
{
struct V_6 * V_7 = (struct V_6 * ) V_286 ;
T_1 V_287 ;
T_7 V_5 = V_288 ;
unsigned long V_130 ;
F_49 ( & V_7 -> V_23 , V_130 ) ;
V_287 = F_14 ( & V_7 -> V_28 -> V_51 ) &
F_14 ( & V_7 -> V_28 -> V_46 ) ;
F_15 ( & V_7 -> V_28 -> V_51 , V_287 ) ;
if ( V_287 & V_289 ) {
F_120 ( V_7 ) ;
V_287 &= ~ V_289 ;
V_5 = V_290 ;
}
if ( V_287 & V_187 ) {
F_125 ( V_7 ) ;
V_287 &= ~ V_187 ;
V_5 = V_290 ;
}
if ( V_287 & V_47 ) {
F_126 ( V_7 ) ;
V_287 &= ~ V_47 ;
V_5 = V_290 ;
}
if ( V_287 & V_291 ) {
F_122 ( V_7 ) ;
V_287 &= ~ V_291 ;
V_5 = V_290 ;
}
if ( V_287 & V_48 ) {
F_123 ( V_7 ) ;
V_287 &= ~ V_48 ;
V_5 = V_290 ;
}
if ( V_287 & V_188 ) {
F_124 ( V_7 ) ;
V_287 &= ~ V_188 ;
V_5 = V_290 ;
}
F_50 ( & V_7 -> V_23 , V_130 ) ;
return V_5 ;
}
static int F_128 ( struct V_242 * V_12 ,
struct V_292 * V_231 )
{
struct V_6 * V_7 ;
unsigned long V_130 ;
V_7 = F_95 ( V_12 , struct V_6 , V_12 ) ;
F_49 ( & V_7 -> V_23 , V_130 ) ;
V_231 -> V_231 . V_293 = NULL ;
V_7 -> V_231 = V_231 ;
V_7 -> V_12 . V_135 = V_231 -> V_294 ;
F_52 ( V_7 ) ;
F_15 ( & V_7 -> V_28 -> V_51 , 0xffff ) ;
F_15 ( & V_7 -> V_28 -> V_46 , V_295 ) ;
V_7 -> V_248 = V_296 ;
V_7 -> V_40 = V_41 ;
V_7 -> V_42 = V_37 ;
F_50 ( & V_7 -> V_23 , V_130 ) ;
return 0 ;
}
static int F_129 ( struct V_242 * V_12 )
{
struct V_6 * V_7 ;
struct V_1 * V_297 ;
unsigned long V_130 ;
V_7 = F_95 ( V_12 , struct V_6 , V_12 ) ;
F_54 ( V_7 ) ;
V_7 -> V_248 = V_296 ;
V_7 -> V_40 = V_41 ;
V_7 -> V_42 = 0 ;
F_49 ( & V_7 -> V_23 , V_130 ) ;
V_7 -> V_12 . V_135 = V_232 ;
F_10 ( & V_7 -> V_39 [ 0 ] , - V_20 ) ;
F_107 (loop_ep, &udc->gadget.ep_list, ep.ep_list)
F_10 ( V_297 , - V_20 ) ;
F_50 ( & V_7 -> V_23 , V_130 ) ;
V_7 -> V_231 = NULL ;
return 0 ;
}
static struct V_6 * F_130 ( struct V_298 * V_299 )
{
struct V_6 * V_7 ;
struct V_300 * V_301 = V_299 -> V_13 . V_302 ;
unsigned long V_92 = 0 ;
struct V_303 T_4 * V_304 ;
unsigned int V_63 ;
T_8 V_101 ;
T_3 V_305 ;
V_7 = F_41 ( sizeof( * V_7 ) , V_260 ) ;
if ( ! V_7 )
goto V_306;
V_7 -> V_13 = & V_299 -> V_13 ;
V_305 = * F_131 ( V_301 , 1 , & V_101 , NULL ) ;
V_7 -> V_243 = F_37 ( V_305 ) ;
F_132 ( V_7 -> V_243 , 0 , V_101 ) ;
V_304 = V_7 -> V_243 ;
F_15 ( & V_304 -> V_244 , 0 ) ;
F_29 ( & V_304 -> V_307 , 0 ) ;
V_92 = F_35 ( ( V_175 *
sizeof( struct V_93 ) ) ,
V_308 ) ;
if ( F_36 ( V_92 ) )
goto V_306;
for ( V_63 = 0 ; V_63 < V_175 ; V_63 ++ ) {
F_15 ( & V_304 -> V_309 [ V_63 ] , ( T_1 ) V_92 ) ;
V_7 -> V_67 [ V_63 ] = F_37 ( V_92 ) ;
V_92 += 32 ;
}
F_132 ( V_7 -> V_67 [ 0 ] , 0 ,
V_175 * sizeof( struct V_93 ) ) ;
V_7 -> V_275 = V_310 ;
V_7 -> V_248 = V_311 ;
V_7 -> V_42 = 0 ;
F_133 ( & V_7 -> V_23 ) ;
return V_7 ;
V_306:
F_42 ( V_7 ) ;
return NULL ;
}
static int F_134 ( struct V_6 * V_7 )
{
struct V_312 T_4 * V_313 ;
V_313 = V_7 -> V_28 ;
F_28 ( & V_313 -> V_148 , 0x01 ) ;
F_28 ( & V_313 -> V_148 , 0x00 ) ;
F_15 ( & V_313 -> V_46 , 0 ) ;
F_28 ( & V_313 -> V_64 , 0 ) ;
F_15 ( & V_313 -> V_51 , V_314 ) ;
return 0 ;
}
static int F_135 ( struct V_6 * V_7 , unsigned char V_76 )
{
struct V_1 * V_2 = & V_7 -> V_39 [ V_76 ] ;
V_2 -> V_7 = V_7 ;
strcpy ( V_2 -> V_21 , V_228 [ V_76 ] ) ;
V_2 -> V_2 . V_21 = V_228 [ V_76 ] ;
if ( V_76 == 0 ) {
V_2 -> V_2 . V_315 . V_316 = true ;
} else {
V_2 -> V_2 . V_315 . V_317 = true ;
V_2 -> V_2 . V_315 . V_318 = true ;
V_2 -> V_2 . V_315 . V_319 = true ;
}
V_2 -> V_2 . V_315 . V_320 = true ;
V_2 -> V_2 . V_315 . V_321 = true ;
V_2 -> V_2 . V_322 = & V_323 ;
V_2 -> V_8 = 1 ;
F_136 ( & V_2 -> V_2 , ( unsigned short ) ~ 0 ) ;
V_2 -> V_2 . V_114 = NULL ;
V_2 -> V_32 = 0xff ;
V_2 -> V_27 = ( T_2 ) V_76 ;
V_2 -> V_206 = 0 ;
V_2 -> V_208 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_104 = NULL ;
V_2 -> V_145 = NULL ;
V_2 -> V_203 = NULL ;
V_2 -> V_43 = V_44 ;
V_2 -> V_52 = 0 ;
F_100 ( & V_2 -> V_9 ) ;
if ( V_76 != 0 )
F_104 ( & V_2 -> V_2 . V_324 , & V_7 -> V_12 . V_324 ) ;
V_2 -> V_12 = & V_7 -> V_12 ;
return 0 ;
}
static void F_137 ( struct V_325 * V_13 )
{
struct V_6 * V_7 = F_95 ( V_13 , struct V_6 , V_12 . V_13 ) ;
int V_63 ;
V_236 ( V_7 -> F_1 ) ;
F_96 ( F_97 ( V_7 -> V_67 [ 0 ] ) ) ;
for ( V_63 = 0 ; V_63 < V_175 ; V_63 ++ )
V_7 -> V_67 [ V_63 ] = NULL ;
F_42 ( V_7 ) ;
}
static int F_138 ( struct V_298 * V_299 )
{
struct V_6 * V_7 ;
const struct V_326 * V_327 ;
struct V_300 * V_301 = V_299 -> V_13 . V_302 ;
struct V_1 * V_2 ;
unsigned int V_237 = 0 ;
unsigned int V_63 ;
const void * V_328 ;
V_327 = F_139 ( V_329 , & V_299 -> V_13 ) ;
if ( ! V_327 )
return - V_103 ;
V_328 = F_140 ( V_301 , L_35 , NULL ) ;
if ( ! V_328 || strcmp ( V_328 , L_36 ) )
return - V_147 ;
V_7 = F_130 ( V_299 ) ;
if ( ! V_7 ) {
F_51 ( & V_299 -> V_13 , L_37 ) ;
return - V_96 ;
}
V_7 -> V_53 = ( unsigned long ) V_327 -> V_162 ;
V_7 -> V_28 = F_141 ( V_301 , 0 ) ;
if ( ! V_7 -> V_28 ) {
V_237 = - V_96 ;
goto V_330;
}
F_134 ( V_7 ) ;
V_7 -> V_12 . V_322 = & V_331 ;
V_7 -> V_12 . V_332 = & V_7 -> V_39 [ 0 ] . V_2 ;
F_100 ( & V_7 -> V_12 . V_324 ) ;
V_7 -> V_12 . V_135 = V_232 ;
V_7 -> V_12 . V_21 = V_333 ;
V_7 -> V_12 . V_13 . V_14 = & V_299 -> V_13 ;
for ( V_63 = 0 ; V_63 < V_175 ; V_63 ++ ) {
F_135 ( V_7 , ( unsigned char ) V_63 ) ;
}
V_237 = F_47 ( V_7 , 0 , & V_334 ) ;
if ( V_237 )
goto V_335;
V_7 -> V_190 = F_142 ( & V_299 -> V_13 , 256 , V_260 ) ;
if ( V_7 -> V_190 == NULL ) {
V_237 = - V_96 ;
goto V_336;
}
V_7 -> V_261 = F_142 ( & V_299 -> V_13 , 2 , V_260 ) ;
if ( V_7 -> V_261 == NULL ) {
V_237 = - V_96 ;
goto V_336;
}
V_7 -> V_337 = F_43 ( ( void * ) V_7 -> V_190 ) ;
if ( V_7 -> V_337 == V_19 ) {
V_7 -> V_337 = F_44 (
V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_190 ,
256 ,
V_17 ) ;
V_7 -> V_338 = 1 ;
} else {
F_45 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_337 , 256 ,
V_17 ) ;
}
F_143 ( & V_7 -> V_182 , F_74 ,
( unsigned long ) V_7 ) ;
V_7 -> V_339 = F_144 ( V_301 , 0 ) ;
if ( ! V_7 -> V_339 ) {
V_237 = - V_103 ;
goto V_340;
}
V_237 = F_145 ( V_7 -> V_339 , F_127 , 0 ,
V_333 , V_7 ) ;
if ( V_237 ) {
F_51 ( V_7 -> V_13 , L_38 ,
V_7 -> V_339 , V_237 ) ;
goto V_341;
}
V_237 = F_146 ( & V_299 -> V_13 , & V_7 -> V_12 ,
F_137 ) ;
if ( V_237 )
goto V_342;
F_147 ( V_299 , V_7 ) ;
F_148 ( V_7 -> V_13 ,
L_39 ,
( V_7 -> V_53 == V_343 ) ? L_40 : L_41 ) ;
return 0 ;
V_342:
F_149 ( V_7 -> V_339 , V_7 ) ;
V_341:
F_150 ( V_7 -> V_339 ) ;
V_340:
if ( V_7 -> V_338 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_337 , 256 ,
V_17 ) ;
V_7 -> V_337 = V_19 ;
} else {
F_5 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_337 , 256 ,
V_17 ) ;
}
V_336:
V_2 = & V_7 -> V_39 [ 0 ] ;
F_96 ( F_97 ( V_2 -> V_82 ) ) ;
F_42 ( V_2 -> V_104 ) ;
F_42 ( V_2 -> V_108 ) ;
F_42 ( V_2 -> V_145 ) ;
V_335:
F_151 ( V_7 -> V_28 ) ;
V_330:
F_42 ( V_7 ) ;
return V_237 ;
}
static int F_152 ( struct V_298 * V_13 , T_9 V_43 )
{
return - V_344 ;
}
static int F_153 ( struct V_298 * V_13 )
{
return - V_344 ;
}
static int F_154 ( struct V_298 * V_299 )
{
struct V_6 * V_7 = F_155 ( V_299 ) ;
struct V_1 * V_2 ;
unsigned int V_101 ;
F_156 ( F_1 ) ;
F_157 ( & V_7 -> V_12 ) ;
V_7 -> F_1 = & F_1 ;
F_158 ( & V_7 -> V_182 ) ;
if ( V_7 -> V_338 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_337 , 256 ,
V_17 ) ;
V_7 -> V_337 = V_19 ;
} else {
F_5 ( V_7 -> V_12 . V_13 . V_14 ,
V_7 -> V_337 , 256 ,
V_17 ) ;
}
V_2 = & V_7 -> V_39 [ 0 ] ;
F_96 ( F_97 ( V_2 -> V_82 ) ) ;
V_101 = ( V_2 -> V_2 . V_106 + V_107 + 2 ) * ( V_81 + 1 ) ;
F_42 ( V_2 -> V_104 ) ;
if ( V_2 -> V_110 ) {
F_3 ( V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_109 , V_101 ,
V_18 ) ;
V_2 -> V_109 = V_19 ;
} else {
F_5 ( V_7 -> V_12 . V_13 . V_14 ,
V_2 -> V_109 , V_101 ,
V_18 ) ;
}
F_42 ( V_2 -> V_108 ) ;
F_42 ( V_2 -> V_145 ) ;
F_149 ( V_7 -> V_339 , V_7 ) ;
F_150 ( V_7 -> V_339 ) ;
F_159 ( & V_7 -> V_182 ) ;
F_151 ( V_7 -> V_28 ) ;
F_160 ( & F_1 ) ;
return 0 ;
}
