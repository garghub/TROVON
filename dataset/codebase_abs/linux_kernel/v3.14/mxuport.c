static int F_1 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 )
{
T_2 * V_5 = V_3 ;
int V_6 ;
V_6 = F_2 ( & V_2 -> V_7 , V_5 + V_8 ,
V_4 - V_8 ,
& V_2 -> V_9 ) ;
F_3 ( V_2 -> V_10 , V_5 ) ;
F_3 ( V_6 , V_5 + 2 ) ;
F_4 ( & V_2 -> V_11 , L_1 , V_12 ,
V_4 , V_6 ) ;
return V_6 + V_8 ;
}
static int F_5 ( struct V_13 * V_14 ,
T_2 V_15 , T_3 V_16 , T_3 V_17 ,
T_2 * V_18 , T_1 V_4 )
{
int V_19 ;
V_19 = F_6 ( V_14 -> V_11 ,
F_7 ( V_14 -> V_11 , 0 ) ,
V_15 ,
( V_20 | V_21 |
V_22 ) , V_16 , V_17 ,
V_18 , V_4 ,
V_23 ) ;
if ( V_19 < 0 ) {
F_8 ( & V_14 -> V_24 -> V_11 ,
L_2 ,
V_12 , V_19 ) ;
return V_19 ;
}
if ( V_19 != V_4 ) {
F_8 ( & V_14 -> V_24 -> V_11 ,
L_3 ,
V_12 , V_19 , V_4 ) ;
return - V_25 ;
}
return V_19 ;
}
static int F_9 ( struct V_13 * V_14 ,
T_2 V_15 ,
T_3 V_16 , T_3 V_17 ,
T_2 * V_18 , T_1 V_4 )
{
int V_19 ;
V_19 = F_6 ( V_14 -> V_11 ,
F_10 ( V_14 -> V_11 , 0 ) ,
V_15 ,
( V_26 | V_21 |
V_22 ) , V_16 , V_17 ,
V_18 , V_4 ,
V_27 ) ;
if ( V_19 < 0 ) {
F_8 ( & V_14 -> V_24 -> V_11 ,
L_2 ,
V_12 , V_19 ) ;
return V_19 ;
}
if ( V_19 != V_4 ) {
F_8 ( & V_14 -> V_24 -> V_11 ,
L_4 ,
V_12 , V_19 , V_4 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_11 ( struct V_13 * V_14 ,
T_2 V_15 , T_3 V_16 , T_3 V_17 )
{
return F_9 ( V_14 , V_15 , V_16 , V_17 ,
NULL , 0 ) ;
}
static void F_12 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_4 ( & V_2 -> V_11 , L_5 , V_12 ) ;
F_11 ( V_14 , V_31 ,
0 , V_2 -> V_10 ) ;
}
static void F_13 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_4 ( & V_2 -> V_11 , L_5 , V_12 ) ;
F_11 ( V_14 , V_31 ,
1 , V_2 -> V_10 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
char * V_18 , int V_4 )
{
int V_32 ;
if ( ! V_2 -> V_2 . V_33 || ! V_2 -> V_34 ) {
F_15 ( & V_2 -> V_2 , V_18 , V_4 ) ;
} else {
for ( V_32 = 0 ; V_32 < V_4 ; V_32 ++ , V_18 ++ ) {
if ( ! F_16 ( V_2 , * V_18 ) )
F_17 ( & V_2 -> V_2 , * V_18 ,
V_35 ) ;
}
}
F_18 ( & V_2 -> V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_5 [ 4 ] )
{
struct V_36 * V_37 = F_20 ( V_2 ) ;
T_2 V_38 = V_5 [ 2 ] & 0xF0 ;
T_3 V_39 = F_21 ( V_5 ) ;
unsigned long V_40 ;
if ( V_39 == 0 )
return;
F_22 ( & V_37 -> V_41 , V_40 ) ;
F_4 ( & V_2 -> V_11 , L_6 ,
V_12 , V_37 -> V_42 ) ;
if ( V_38 & V_43 ) {
V_37 -> V_42 |= V_43 ;
F_4 ( & V_2 -> V_11 , L_7 , V_12 ) ;
} else {
V_37 -> V_42 &= ~ V_43 ;
F_4 ( & V_2 -> V_11 , L_8 , V_12 ) ;
}
if ( V_38 & V_44 ) {
V_37 -> V_42 |= V_44 ;
F_4 ( & V_2 -> V_11 , L_9 , V_12 ) ;
} else {
V_37 -> V_42 &= ~ V_44 ;
F_4 ( & V_2 -> V_11 , L_10 , V_12 ) ;
}
if ( V_38 & V_45 ) {
V_37 -> V_42 |= V_45 ;
F_4 ( & V_2 -> V_11 , L_11 , V_12 ) ;
} else {
V_37 -> V_42 &= ~ V_45 ;
F_4 ( & V_2 -> V_11 , L_12 , V_12 ) ;
}
F_23 ( & V_37 -> V_41 , V_40 ) ;
if ( V_39 &
( V_46 | V_47 | V_48 ) ) {
if ( V_39 & V_46 ) {
V_2 -> V_49 . V_50 ++ ;
F_4 ( & V_2 -> V_11 , L_13 , V_12 ) ;
}
if ( V_39 & V_47 ) {
V_2 -> V_49 . V_51 ++ ;
F_4 ( & V_2 -> V_11 , L_14 , V_12 ) ;
}
if ( V_39 & V_48 ) {
V_2 -> V_49 . V_52 ++ ;
F_4 ( & V_2 -> V_11 , L_15 , V_12 ) ;
}
F_24 ( & V_2 -> V_2 . V_53 ) ;
}
}
static void F_25 ( struct V_1 * V_2 , T_2 V_5 [ 4 ] )
{
T_2 V_54 = V_5 [ 2 ] ;
if ( V_54 & V_55 ) {
V_2 -> V_49 . V_56 ++ ;
F_4 ( & V_2 -> V_11 , L_16 , V_12 ) ;
}
if ( V_54 & V_57 ) {
V_2 -> V_49 . V_58 ++ ;
F_4 ( & V_2 -> V_11 , L_17 , V_12 ) ;
}
if ( V_54 & V_59 ) {
V_2 -> V_49 . V_60 ++ ;
F_4 ( & V_2 -> V_11 , L_18 , V_12 ) ;
}
if ( V_54 & V_61 ) {
V_2 -> V_49 . V_62 ++ ;
F_4 ( & V_2 -> V_11 , L_19 , V_12 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
T_2 V_5 [ 4 ] , T_4 V_63 )
{
F_4 ( & V_2 -> V_11 , L_20 , V_12 , V_63 ) ;
switch ( V_63 ) {
case V_64 :
break;
case V_65 :
F_19 ( V_2 , V_5 ) ;
break;
case V_66 :
F_25 ( V_2 , V_5 ) ;
break;
case V_67 :
break;
default:
F_4 ( & V_2 -> V_11 , L_21 ) ;
break;
}
}
static void F_27 ( struct V_68 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 * V_18 = V_68 -> V_70 ;
T_2 * V_71 = V_18 + V_68 -> V_72 ;
struct V_1 * V_73 ;
T_2 * V_74 ;
T_3 V_75 ;
T_3 V_76 ;
while ( V_18 < V_71 ) {
if ( V_18 + V_8 > V_71 ) {
F_28 ( & V_2 -> V_11 , L_22 ,
V_12 ) ;
return;
}
V_75 = F_21 ( V_18 ) ;
if ( V_75 >= V_14 -> V_77 ) {
F_28 ( & V_2 -> V_11 , L_23 ,
V_12 ) ;
return;
}
V_73 = V_14 -> V_2 [ V_75 ] ;
V_76 = F_21 ( V_18 + 2 ) ;
if ( ! V_76 || V_18 + V_8 + V_76 > V_71 ) {
F_28 ( & V_2 -> V_11 , L_24 , V_12 ) ;
return;
}
if ( F_29 ( V_78 , & V_73 -> V_2 . V_40 ) ) {
V_74 = V_18 + V_8 ;
F_14 ( V_73 , V_74 , V_76 ) ;
} else {
F_4 ( & V_73 -> V_11 , L_25 ,
V_12 ) ;
}
V_18 += V_8 + V_76 ;
}
}
static void F_30 ( struct V_68 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 * V_18 = V_68 -> V_70 ;
T_2 * V_71 = V_18 + V_68 -> V_72 ;
struct V_1 * V_73 ;
T_2 * V_74 ;
T_3 V_75 ;
T_3 V_79 ;
while ( V_18 < V_71 ) {
if ( V_18 + V_80 > V_71 ) {
F_28 ( & V_2 -> V_11 , L_26 ,
V_12 ) ;
return;
}
V_75 = F_21 ( V_18 ) ;
if ( V_75 >= V_14 -> V_77 ) {
F_28 ( & V_2 -> V_11 , L_23 ,
V_12 ) ;
return;
}
V_73 = V_14 -> V_2 [ V_75 ] ;
if ( F_29 ( V_78 , & V_73 -> V_2 . V_40 ) ) {
V_74 = V_18 + V_8 ;
V_79 = F_21 ( V_18 + 2 ) ;
F_26 ( V_73 , V_74 ,
V_79 ) ;
} else {
F_4 ( & V_73 -> V_11 ,
L_27 , V_12 ) ;
}
V_18 += V_80 ;
}
}
static void F_31 ( struct V_68 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_69 ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_2 == V_14 -> V_2 [ 0 ] )
F_27 ( V_68 ) ;
if ( V_2 == V_14 -> V_2 [ 1 ] )
F_30 ( V_68 ) ;
}
static bool F_32 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
bool V_81 = true ;
T_4 V_82 ;
T_2 * V_83 ;
int V_84 ;
V_83 = F_33 ( 4 , V_85 ) ;
if ( ! V_83 )
goto V_86;
V_84 = F_5 ( V_14 , V_87 , 0 ,
V_2 -> V_10 , V_83 , 4 ) ;
if ( V_84 < 0 )
goto V_86;
V_82 = F_34 ( V_83 ) ;
F_4 ( & V_2 -> V_11 , L_28 , V_12 , V_82 ) ;
if ( V_82 != 0 )
V_81 = false ;
V_86:
F_35 ( V_83 ) ;
return V_81 ;
}
static int F_36 ( struct V_1 * V_2 , T_2 V_88 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_84 ;
F_4 ( & V_2 -> V_11 , L_29 , V_12 , V_88 ) ;
V_84 = F_11 ( V_14 , V_89 ,
V_88 , V_2 -> V_10 ) ;
if ( V_84 )
F_8 ( & V_2 -> V_11 , L_30 , V_12 ) ;
return V_84 ;
}
static int F_37 ( struct V_1 * V_2 , int V_90 )
{
struct V_36 * V_37 = F_20 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_84 ;
F_38 ( & V_37 -> V_91 ) ;
V_84 = F_11 ( V_14 , V_92 ,
! ! V_90 , V_2 -> V_10 ) ;
if ( ! V_84 ) {
if ( V_90 )
V_37 -> V_88 |= V_93 ;
else
V_37 -> V_88 &= ~ V_93 ;
}
F_39 ( & V_37 -> V_91 ) ;
return V_84 ;
}
static int F_40 ( struct V_1 * V_2 , T_2 V_94 )
{
struct V_36 * V_37 = F_20 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_84 ;
T_2 V_88 ;
F_38 ( & V_37 -> V_91 ) ;
V_88 = V_37 -> V_88 ;
switch ( V_94 ) {
case V_95 :
V_88 &= ~ V_96 ;
break;
case V_97 :
V_88 |= V_96 ;
break;
case V_98 :
break;
default:
V_84 = - V_99 ;
goto V_86;
}
V_84 = F_11 ( V_14 , V_100 ,
V_94 , V_2 -> V_10 ) ;
if ( ! V_84 )
V_37 -> V_88 = V_88 ;
V_86:
F_39 ( & V_37 -> V_91 ) ;
return V_84 ;
}
static void F_41 ( struct V_1 * V_2 , int V_90 )
{
struct V_36 * V_37 = F_20 ( V_2 ) ;
T_2 V_88 ;
int V_84 ;
F_38 ( & V_37 -> V_91 ) ;
V_88 = V_37 -> V_88 ;
if ( V_90 )
V_88 |= ( V_96 | V_93 ) ;
else
V_88 &= ~ ( V_96 | V_93 ) ;
V_84 = F_36 ( V_2 , V_88 ) ;
if ( ! V_84 )
V_37 -> V_88 = V_88 ;
F_39 ( & V_37 -> V_91 ) ;
}
static int F_42 ( struct V_28 * V_29 , unsigned int V_101 ,
unsigned int V_102 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
struct V_36 * V_37 = F_20 ( V_2 ) ;
int V_84 ;
T_2 V_88 ;
F_38 ( & V_37 -> V_91 ) ;
V_88 = V_37 -> V_88 ;
if ( V_101 & V_103 )
V_88 |= V_96 ;
if ( V_101 & V_104 )
V_88 |= V_93 ;
if ( V_102 & V_103 )
V_88 &= ~ V_96 ;
if ( V_102 & V_104 )
V_88 &= ~ V_93 ;
V_84 = F_36 ( V_2 , V_88 ) ;
if ( ! V_84 )
V_37 -> V_88 = V_88 ;
F_39 ( & V_37 -> V_91 ) ;
return V_84 ;
}
static int F_43 ( struct V_28 * V_29 )
{
struct V_36 * V_37 ;
struct V_1 * V_2 = V_29 -> V_30 ;
unsigned int V_105 ;
unsigned long V_40 ;
unsigned int V_106 ;
unsigned int V_107 ;
V_37 = F_20 ( V_2 ) ;
F_38 ( & V_37 -> V_91 ) ;
F_22 ( & V_37 -> V_41 , V_40 ) ;
V_106 = V_37 -> V_42 ;
V_107 = V_37 -> V_88 ;
F_23 ( & V_37 -> V_41 , V_40 ) ;
F_39 ( & V_37 -> V_91 ) ;
V_105 = ( ( ( V_107 & V_93 ) ? V_104 : 0 ) |
( ( V_107 & V_96 ) ? V_103 : 0 ) |
( ( V_106 & V_43 ) ? V_108 : 0 ) |
( ( V_106 & V_45 ) ? V_109 : 0 ) |
( ( V_106 & V_110 ) ? V_111 : 0 ) |
( ( V_106 & V_44 ) ? V_112 : 0 ) ) ;
F_4 ( & V_2 -> V_11 , L_31 , V_12 , V_105 ) ;
return V_105 ;
}
static int F_44 ( struct V_28 * V_29 ,
struct V_113 * V_114 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_2 V_115 = F_45 ( V_29 ) ;
T_2 V_116 = F_46 ( V_29 ) ;
int V_117 ;
int V_84 ;
T_2 * V_5 ;
T_2 V_118 ;
V_5 = F_47 ( 2 , V_85 ) ;
if ( ! V_5 )
return - V_119 ;
if ( F_48 ( V_29 ) || F_49 ( V_29 ) ) {
V_117 = 1 ;
V_5 [ 0 ] = V_115 ;
V_5 [ 1 ] = V_116 ;
V_84 = F_9 ( V_14 , V_120 ,
0 , V_2 -> V_10 ,
V_5 , 2 ) ;
if ( V_84 )
goto V_86;
F_4 ( & V_2 -> V_11 , L_32 ,
V_12 , V_115 , V_116 ) ;
} else {
V_117 = 0 ;
}
V_84 = F_11 ( V_14 , V_121 ,
V_117 , V_2 -> V_10 ) ;
if ( V_84 )
goto V_86;
V_118 = V_122 ;
if ( ! V_114 ||
F_50 ( V_29 ) != ( V_114 -> V_123 & V_124 ) ) {
if ( F_50 ( V_29 ) )
V_118 = V_98 ;
else
V_118 = V_97 ;
}
if ( F_51 ( V_29 ) ) {
if ( V_114 && ( V_114 -> V_123 & V_125 ) == V_126 ) {
if ( F_50 ( V_29 ) )
V_118 = V_98 ;
else
V_118 = V_97 ;
F_37 ( V_2 , 1 ) ;
}
} else {
V_118 = V_95 ;
F_37 ( V_2 , 0 ) ;
}
if ( V_118 != V_122 )
V_84 = F_40 ( V_2 , V_118 ) ;
V_86:
F_35 ( V_5 ) ;
return V_84 ;
}
static void F_52 ( struct V_28 * V_29 ,
struct V_1 * V_2 ,
struct V_113 * V_114 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_2 * V_5 ;
T_2 V_127 ;
T_2 V_128 ;
T_2 V_60 ;
int V_129 ;
int V_84 ;
if ( V_114 &&
! F_53 ( & V_29 -> V_130 , V_114 ) &&
V_29 -> V_130 . V_131 == V_114 -> V_131 ) {
F_4 ( & V_2 -> V_11 , L_33 , V_12 ) ;
return;
}
V_5 = F_47 ( 4 , V_85 ) ;
if ( ! V_5 )
return;
switch ( F_54 ( V_29 ) ) {
case V_132 :
V_127 = V_133 ;
break;
case V_134 :
V_127 = V_135 ;
break;
case V_136 :
V_127 = V_137 ;
break;
case V_138 :
default:
V_127 = V_139 ;
break;
}
if ( F_55 ( V_29 ) ) {
if ( F_56 ( V_29 ) ) {
if ( F_57 ( V_29 ) )
V_60 = V_140 ;
else
V_60 = V_141 ;
} else {
if ( F_57 ( V_29 ) )
V_60 = V_142 ;
else
V_60 = V_143 ;
}
} else {
V_60 = V_144 ;
}
if ( F_58 ( V_29 ) )
V_128 = V_145 ;
else
V_128 = V_146 ;
V_5 [ 0 ] = V_127 ;
V_5 [ 1 ] = V_60 ;
V_5 [ 2 ] = V_128 ;
V_5 [ 3 ] = 0 ;
V_84 = F_9 ( V_14 , V_147 ,
0 , V_2 -> V_10 , V_5 , 4 ) ;
if ( V_84 )
goto V_86;
V_84 = F_44 ( V_29 , V_114 , V_2 , V_14 ) ;
if ( V_84 )
goto V_86;
V_129 = F_59 ( V_29 ) ;
if ( ! V_129 )
V_129 = 9600 ;
F_60 ( V_129 , V_5 ) ;
V_84 = F_9 ( V_14 , V_148 ,
0 , V_2 -> V_10 ,
V_5 , 4 ) ;
if ( V_84 )
goto V_86;
F_4 ( & V_2 -> V_11 , L_34 , V_129 ) ;
F_4 ( & V_2 -> V_11 , L_35 , V_127 ) ;
F_4 ( & V_2 -> V_11 , L_36 , V_60 ) ;
F_4 ( & V_2 -> V_11 , L_37 , V_128 ) ;
V_86:
F_35 ( V_5 ) ;
}
static int F_61 ( struct V_13 * V_14 )
{
unsigned long V_149 = ( unsigned long ) F_62 ( V_14 ) ;
if ( V_149 & V_150 )
return 2 ;
if ( V_149 & V_151 )
return 4 ;
if ( V_149 & V_152 )
return 8 ;
if ( V_149 & V_153 )
return 16 ;
return 0 ;
}
static int F_63 ( struct V_13 * V_14 , T_4 * V_154 )
{
T_2 * V_155 ;
int V_84 ;
V_155 = F_33 ( 4 , V_85 ) ;
if ( ! V_155 )
return - V_119 ;
V_84 = F_5 ( V_14 , V_156 , 0 , 0 ,
V_155 , 4 ) ;
if ( V_84 != 4 ) {
V_84 = - V_25 ;
goto V_86;
}
* V_154 = ( V_155 [ 0 ] << 16 ) | ( V_155 [ 1 ] << 8 ) | V_155 [ 2 ] ;
V_84 = 0 ;
V_86:
F_35 ( V_155 ) ;
return V_84 ;
}
static int F_64 ( struct V_13 * V_14 ,
const struct V_157 * V_158 )
{
T_2 * V_159 ;
T_1 V_82 ;
T_1 V_160 ;
int V_84 ;
V_159 = F_47 ( V_161 , V_85 ) ;
if ( ! V_159 )
return - V_119 ;
F_4 ( & V_14 -> V_24 -> V_11 , L_38 ) ;
V_84 = F_11 ( V_14 , V_162 , 0 , 0 ) ;
if ( V_84 )
goto V_86;
V_160 = 0 ;
do {
V_82 = F_65 ( T_1 , ( V_158 -> V_4 - V_160 ) , V_161 ) ;
memcpy ( V_159 , & V_158 -> V_18 [ V_160 ] , V_82 ) ;
V_84 = F_9 ( V_14 , V_163 ,
0 , 0 , V_159 , V_82 ) ;
if ( V_84 ) {
F_11 ( V_14 , V_164 ,
0 , 0 ) ;
goto V_86;
}
V_160 += V_82 ;
F_66 ( 1000 , 2000 ) ;
} while ( V_160 < V_158 -> V_4 );
F_67 ( 1000 ) ;
V_84 = F_11 ( V_14 , V_164 , 0 , 0 ) ;
if ( V_84 )
goto V_86;
F_67 ( 1000 ) ;
V_84 = F_11 ( V_14 , V_165 , 0 , 0 ) ;
V_86:
F_35 ( V_159 ) ;
return V_84 ;
}
static int F_68 ( struct V_13 * V_14 ,
const struct V_166 * V_167 )
{
T_3 V_168 = F_69 ( V_14 -> V_11 -> V_169 . V_170 ) ;
const struct V_157 * V_158 = NULL ;
T_4 V_154 ;
int V_171 ;
char V_5 [ 32 ] ;
int V_84 ;
V_84 = F_11 ( V_14 , V_172 , 0 , 0 ) ;
if ( V_84 ) {
F_11 ( V_14 , V_173 , 0 , 0 ) ;
return V_84 ;
}
V_84 = F_63 ( V_14 , & V_154 ) ;
if ( V_84 < 0 )
return V_84 ;
F_4 ( & V_14 -> V_24 -> V_11 , L_39 ,
( V_154 & 0xff0000 ) >> 16 ,
( V_154 & 0xff00 ) >> 8 ,
( V_154 & 0xff ) ) ;
snprintf ( V_5 , sizeof( V_5 ) - 1 , L_40 , V_168 ) ;
V_84 = F_70 ( & V_158 , V_5 , & V_14 -> V_24 -> V_11 ) ;
if ( V_84 ) {
F_28 ( & V_14 -> V_24 -> V_11 , L_41 ,
V_5 ) ;
V_84 = 0 ;
} else {
V_171 = ( ( V_158 -> V_18 [ V_174 ] << 16 ) |
( V_158 -> V_18 [ V_175 ] << 8 ) |
V_158 -> V_18 [ V_176 ] ) ;
F_4 ( & V_14 -> V_24 -> V_11 ,
L_42 ,
V_158 -> V_18 [ V_174 ] , V_158 -> V_18 [ V_175 ] ,
V_158 -> V_18 [ V_176 ] ) ;
if ( V_171 > V_154 ) {
V_84 = F_64 ( V_14 , V_158 ) ;
if ( V_84 )
goto V_86;
V_84 = F_63 ( V_14 , & V_154 ) ;
if ( V_84 < 0 )
goto V_86;
}
}
F_71 ( & V_14 -> V_24 -> V_11 ,
L_43 ,
( V_154 & 0xff0000 ) >> 16 ,
( V_154 & 0xff00 ) >> 8 ,
( V_154 & 0xff ) ) ;
F_72 ( V_14 , ( void * ) V_167 -> V_177 ) ;
V_86:
if ( V_158 )
F_73 ( V_158 ) ;
return V_84 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_36 * V_37 ;
int V_84 ;
V_37 = F_75 ( & V_2 -> V_11 , sizeof( struct V_36 ) ,
V_85 ) ;
if ( ! V_37 )
return - V_119 ;
F_76 ( & V_37 -> V_91 ) ;
F_77 ( & V_37 -> V_41 ) ;
F_78 ( V_2 , V_37 ) ;
V_84 = F_11 ( V_14 , V_178 ,
0 , V_2 -> V_10 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_11 ( V_14 , V_179 ,
0 , V_2 -> V_10 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_11 ( V_14 , V_180 ,
V_181 ,
V_2 -> V_10 ) ;
if ( V_84 )
return V_84 ;
return 0 ;
}
static int F_79 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_1 * V_182 ,
int V_183 )
{
struct V_184 * V_11 = F_80 ( V_14 -> V_24 ) ;
F_81 ( V_183 , & V_2 -> V_185 ) ;
V_2 -> V_186 [ V_183 ] = F_82 ( 0 , V_85 ) ;
if ( ! V_2 -> V_186 [ V_183 ] )
return - V_119 ;
V_2 -> V_187 [ V_183 ] = F_47 ( V_182 -> V_188 , V_85 ) ;
if ( ! V_2 -> V_187 [ V_183 ] )
return - V_119 ;
F_83 ( V_2 -> V_186 [ V_183 ] , V_11 ,
F_84 ( V_11 , V_2 -> V_189 ) ,
V_2 -> V_187 [ V_183 ] ,
V_2 -> V_188 ,
V_14 -> type -> V_190 ,
V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
struct V_1 * V_182 )
{
int V_183 ;
int V_191 ;
for ( V_183 = 0 ; V_183 < F_86 ( V_2 -> V_186 ) ; ++ V_183 ) {
V_191 = F_79 ( V_14 , V_2 , V_182 , V_183 ) ;
if ( V_191 )
return V_191 ;
}
return 0 ;
}
static int F_87 ( struct V_13 * V_14 )
{
struct V_1 * V_182 = V_14 -> V_2 [ 0 ] ;
struct V_1 * V_192 = V_14 -> V_2 [ 1 ] ;
struct V_1 * V_2 ;
int V_84 ;
int V_32 ;
int V_183 ;
for ( V_32 = 1 ; V_32 < V_14 -> V_193 ; ++ V_32 ) {
V_2 = V_14 -> V_2 [ V_32 ] ;
for ( V_183 = 0 ; V_183 < F_86 ( V_2 -> V_186 ) ; ++ V_183 ) {
F_88 ( V_2 -> V_186 [ V_183 ] ) ;
F_35 ( V_2 -> V_187 [ V_183 ] ) ;
V_2 -> V_186 [ V_183 ] = NULL ;
V_2 -> V_187 [ V_183 ] = NULL ;
}
V_2 -> V_185 = 0 ;
}
for ( V_32 = 1 ; V_32 < V_14 -> V_77 ; ++ V_32 ) {
V_2 = V_14 -> V_2 [ V_32 ] ;
V_2 -> V_188 = V_182 -> V_188 ;
V_2 -> V_189 =
V_182 -> V_189 ;
V_84 = F_85 ( V_14 , V_2 , V_182 ) ;
if ( V_84 )
return V_84 ;
V_2 -> V_194 = V_2 -> V_186 [ 0 ] ;
V_2 -> V_195 = V_2 -> V_187 [ 0 ] ;
if ( ! F_89 ( & V_2 -> V_7 ) ) {
V_84 = F_90 ( & V_2 -> V_7 , V_196 ,
V_85 ) ;
if ( V_84 )
return V_84 ;
}
}
V_84 = F_91 ( V_182 , V_85 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_91 ( V_192 , V_85 ) ;
if ( V_84 ) {
F_92 ( V_182 ) ;
return V_84 ;
}
return 0 ;
}
static int F_93 ( struct V_28 * V_29 , struct V_1 * V_2 )
{
struct V_36 * V_37 = F_20 ( V_2 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_84 ;
V_84 = F_11 ( V_14 , V_31 ,
1 , V_2 -> V_10 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_11 ( V_14 , V_197 ,
1 , V_2 -> V_10 ) ;
if ( V_84 ) {
F_11 ( V_14 , V_31 ,
0 , V_2 -> V_10 ) ;
return V_84 ;
}
F_52 ( V_29 , V_2 , NULL ) ;
V_37 -> V_42 = 0 ;
return V_84 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_11 ( V_14 , V_197 , 0 ,
V_2 -> V_10 ) ;
F_11 ( V_14 , V_31 , 0 ,
V_2 -> V_10 ) ;
}
static void F_95 ( struct V_28 * V_29 , int V_198 )
{
struct V_1 * V_2 = V_29 -> V_30 ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_117 ;
if ( V_198 == - 1 ) {
V_117 = 1 ;
F_4 ( & V_2 -> V_11 , L_44 , V_12 ) ;
} else {
V_117 = 0 ;
F_4 ( & V_2 -> V_11 , L_45 , V_12 ) ;
}
F_11 ( V_14 , V_199 ,
V_117 , V_2 -> V_10 ) ;
}
static int F_96 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_200 = 0 ;
int V_32 ;
int V_201 ;
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ ) {
V_2 = V_14 -> V_2 [ V_32 ] ;
V_201 = F_91 ( V_2 , V_202 ) ;
if ( V_201 < 0 )
V_200 ++ ;
}
for ( V_32 = 0 ; V_32 < V_14 -> V_77 ; V_32 ++ ) {
V_2 = V_14 -> V_2 [ V_32 ] ;
if ( ! F_29 ( V_78 , & V_2 -> V_2 . V_40 ) )
continue;
V_201 = F_97 ( V_2 , V_202 ) ;
if ( V_201 < 0 )
V_200 ++ ;
}
return V_200 ? - V_25 : 0 ;
}
