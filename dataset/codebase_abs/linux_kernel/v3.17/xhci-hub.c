static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_1 V_6 ;
V_4 -> V_7 = 10 ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = V_5 ;
V_6 = 0 ;
if ( F_2 ( V_2 -> V_10 ) )
V_6 |= V_11 ;
else
V_6 |= V_12 ;
V_6 |= V_13 ;
V_4 -> V_14 = F_3 ( V_6 ) ;
}
static void F_4 ( struct V_15 * V_16 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 ;
T_2 V_17 [ ( V_18 + 1 + 7 ) / 8 ] ;
T_3 V_19 ;
unsigned int V_20 ;
V_5 = V_2 -> V_21 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_4 -> V_22 = V_23 ;
V_6 = 1 + ( V_5 / 8 ) ;
V_4 -> V_24 = V_25 + 2 * V_6 ;
memset ( V_17 , 0 , sizeof( V_17 ) ) ;
for ( V_20 = 0 ; V_20 < V_5 ; V_20 ++ ) {
V_19 = F_5 ( V_2 -> V_26 [ V_20 ] ) ;
if ( V_19 & V_27 )
V_17 [ ( V_20 + 1 ) / 8 ] |= 1 << ( ( V_20 + 1 ) % 8 ) ;
}
memset ( V_4 -> V_28 . V_29 . V_30 , 0xff ,
sizeof( V_4 -> V_28 . V_29 . V_30 ) ) ;
memset ( V_4 -> V_28 . V_29 . V_31 , 0xff ,
sizeof( V_4 -> V_28 . V_29 . V_31 ) ) ;
for ( V_20 = 0 ; V_20 < ( V_5 + 1 + 7 ) / 8 ; V_20 ++ )
memset ( & V_4 -> V_28 . V_29 . V_30 [ V_20 ] , V_17 [ V_20 ] ,
sizeof( T_2 ) ) ;
}
static void F_6 ( struct V_15 * V_16 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
T_1 V_17 ;
T_3 V_19 ;
unsigned int V_20 ;
V_5 = V_2 -> V_32 ;
F_1 ( V_2 , V_4 , V_5 ) ;
V_4 -> V_22 = V_33 ;
V_4 -> V_24 = V_34 ;
V_4 -> V_28 . V_35 . V_36 = 0 ;
V_4 -> V_28 . V_35 . V_37 = 0 ;
V_17 = 0 ;
for ( V_20 = 0 ; V_20 < V_5 ; V_20 ++ ) {
V_19 = F_5 ( V_2 -> V_38 [ V_20 ] ) ;
if ( V_19 & V_27 )
V_17 |= 1 << ( V_20 + 1 ) ;
}
V_4 -> V_28 . V_35 . V_30 = F_3 ( V_17 ) ;
}
static void F_7 ( struct V_15 * V_16 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_16 -> V_39 == V_40 )
F_6 ( V_16 , V_2 , V_4 ) ;
else
F_4 ( V_16 , V_2 , V_4 ) ;
}
static unsigned int F_8 ( unsigned int V_41 )
{
if ( F_9 ( V_41 ) )
return V_42 ;
if ( F_10 ( V_41 ) )
return V_43 ;
return 0 ;
}
T_3 F_11 ( T_3 V_44 )
{
return ( V_44 & V_45 ) | ( V_44 & V_46 ) ;
}
int F_12 ( struct V_15 * V_16 , struct V_1 * V_2 ,
T_1 V_47 )
{
int V_48 ;
int V_20 ;
enum V_49 V_39 ;
V_48 = 0 ;
for ( V_20 = 0 ; V_20 < V_50 ; V_20 ++ ) {
if ( ! V_2 -> V_51 [ V_20 ] )
continue;
V_39 = V_2 -> V_51 [ V_20 ] -> V_52 -> V_39 ;
if ( ( ( V_39 == V_53 ) == ( V_16 -> V_39 == V_40 ) )
&& V_2 -> V_51 [ V_20 ] -> V_54 == V_47 ) {
V_48 = V_20 ;
break;
}
}
return V_48 ;
}
static int F_13 ( struct V_1 * V_2 , int V_48 , int V_55 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
unsigned long V_60 ;
int V_61 ;
int V_20 ;
V_61 = 0 ;
V_57 = V_2 -> V_51 [ V_48 ] ;
V_59 = F_14 ( V_2 , false , true , V_62 ) ;
if ( ! V_59 ) {
F_15 ( V_2 , L_1 ) ;
return - V_63 ;
}
F_16 ( & V_2 -> V_64 , V_60 ) ;
for ( V_20 = V_65 ; V_20 > 0 ; V_20 -- ) {
if ( V_57 -> V_66 [ V_20 ] . V_67 && V_57 -> V_66 [ V_20 ] . V_67 -> V_68 ) {
struct V_58 * V_69 ;
V_69 = F_14 ( V_2 , false , false ,
V_70 ) ;
if ( ! V_69 ) {
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_18 ( V_2 , V_59 ) ;
return - V_63 ;
}
F_19 ( V_2 , V_69 , V_48 , V_20 ,
V_55 ) ;
}
}
F_19 ( V_2 , V_59 , V_48 , 0 , V_55 ) ;
F_20 ( V_2 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_21 ( V_59 -> V_71 ) ;
if ( V_59 -> V_72 == V_73 || V_59 -> V_72 == V_74 ) {
F_22 ( V_2 , L_2 ) ;
V_61 = - V_75 ;
}
F_18 ( V_2 , V_59 ) ;
return V_61 ;
}
void F_23 ( struct V_1 * V_2 , int V_48 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_65 + 1 ; V_20 ++ )
if ( V_2 -> V_51 [ V_48 ] -> V_66 [ V_20 ] . V_67 &&
V_2 -> V_51 [ V_48 ] -> V_66 [ V_20 ] . V_67 -> V_68 )
F_24 ( V_2 , V_48 , V_20 , 0 ) ;
return;
}
static void F_25 ( struct V_15 * V_16 , struct V_1 * V_2 ,
T_1 V_76 , T_4 T_5 * V_77 , T_3 V_41 )
{
if ( V_16 -> V_39 == V_40 ) {
F_15 ( V_2 , L_3
L_4 ) ;
return;
}
F_26 ( V_41 | V_78 , V_77 ) ;
V_41 = F_5 ( V_77 ) ;
F_15 ( V_2 , L_5 ,
V_76 , V_41 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_79 ,
T_1 V_76 , T_4 T_5 * V_77 , T_3 V_41 )
{
char * V_80 ;
T_3 V_72 ;
switch ( V_79 ) {
case V_81 :
V_72 = V_82 ;
V_80 = L_6 ;
break;
case V_83 :
V_72 = V_84 ;
V_80 = L_7 ;
break;
case V_85 :
V_72 = V_86 ;
V_80 = L_8 ;
break;
case V_87 :
V_72 = V_88 ;
V_80 = L_9 ;
break;
case V_89 :
V_72 = V_90 ;
V_80 = L_10 ;
break;
case V_91 :
V_72 = V_92 ;
V_80 = L_11 ;
break;
case V_93 :
V_72 = V_92 ;
V_80 = L_12 ;
break;
default:
return;
}
F_26 ( V_41 | V_72 , V_77 ) ;
V_41 = F_5 ( V_77 ) ;
F_15 ( V_2 , L_13 ,
V_80 , V_76 , V_41 ) ;
}
static int F_28 ( struct V_15 * V_16 , T_4 T_5 * * * V_94 )
{
int V_95 ;
struct V_1 * V_2 = F_29 ( V_16 ) ;
if ( V_16 -> V_39 == V_40 ) {
V_95 = V_2 -> V_32 ;
* V_94 = V_2 -> V_38 ;
} else {
V_95 = V_2 -> V_21 ;
* V_94 = V_2 -> V_26 ;
}
return V_95 ;
}
void F_30 ( struct V_1 * V_2 , T_4 T_5 * * V_94 ,
int V_96 , T_3 V_97 )
{
T_3 V_6 ;
V_6 = F_5 ( V_94 [ V_96 ] ) ;
V_6 = F_11 ( V_6 ) ;
V_6 &= ~ V_98 ;
V_6 |= V_99 | V_97 ;
F_26 ( V_6 , V_94 [ V_96 ] ) ;
}
static void F_31 ( struct V_1 * V_2 ,
T_4 T_5 * * V_94 , int V_96 , T_1 V_100 )
{
T_3 V_6 ;
V_6 = F_5 ( V_94 [ V_96 ] ) ;
V_6 = F_11 ( V_6 ) ;
if ( V_100 & V_101 )
V_6 |= V_102 ;
else
V_6 &= ~ V_102 ;
if ( V_100 & V_103 )
V_6 |= V_104 ;
else
V_6 &= ~ V_104 ;
if ( V_100 & V_105 )
V_6 |= V_106 ;
else
V_6 &= ~ V_106 ;
F_26 ( V_6 , V_94 [ V_96 ] ) ;
}
void F_32 ( struct V_1 * V_2 , T_4 T_5 * * V_94 ,
int V_96 , T_3 V_107 )
{
T_3 V_6 ;
V_6 = F_5 ( V_94 [ V_96 ] ) ;
if ( V_6 & V_107 ) {
V_6 = F_11 ( V_6 ) ;
V_6 |= V_107 ;
F_26 ( V_6 , V_94 [ V_96 ] ) ;
}
}
static void F_33 ( T_3 * V_72 , T_3 V_108 )
{
if ( ( V_108 & V_98 ) == V_109 )
* V_72 |= V_110 ;
}
static void F_34 ( struct V_1 * V_2 ,
T_3 * V_72 , T_3 V_108 )
{
T_3 V_111 = V_108 & V_98 ;
if ( V_111 == V_112 )
return;
if ( V_108 & V_113 ) {
if ( V_111 != V_114 &&
V_111 != V_115 ) {
V_111 = V_114 ;
}
V_111 |= V_116 ;
} else {
if ( ( V_2 -> V_117 & V_118 ) &&
( V_111 == V_114 ) )
V_111 |= V_116 ;
}
* V_72 |= V_111 ;
}
static void F_35 ( struct V_1 * V_2 , T_3 V_72 ,
T_1 V_76 )
{
T_3 V_119 = ( ( 1 << V_2 -> V_32 ) - 1 ) ;
bool V_120 = ( ( V_72 & V_98 ) == V_121 ) ;
if ( ! ( V_2 -> V_117 & V_118 ) )
return;
if ( ( V_2 -> V_122 != V_119 ) && V_120 ) {
V_2 -> V_122 |= 1 << V_76 ;
if ( V_2 -> V_122 == V_119 ) {
F_36 ( & V_2 -> V_123 ) ;
F_37 ( V_2 , V_124 ,
L_14 ) ;
F_37 ( V_2 , V_124 ,
L_15 ) ;
}
}
}
static T_3 F_38 ( struct V_15 * V_16 ,
struct V_125 * V_126 ,
T_4 T_5 * * V_94 ,
T_1 V_76 , T_3 V_127 ,
unsigned long V_60 )
__releases( &xhci->lock
int F_39 ( struct V_15 * V_16 , T_1 V_128 , T_1 V_79 ,
T_1 V_76 , char * V_129 , T_1 V_130 )
{
struct V_1 * V_2 = F_29 ( V_16 ) ;
int V_95 ;
unsigned long V_60 ;
T_3 V_6 , V_72 ;
int V_131 = 0 ;
T_4 T_5 * * V_94 ;
int V_48 ;
struct V_125 * V_126 ;
T_1 V_97 = 0 ;
T_1 V_100 = 0 ;
T_1 V_132 = 0 ;
V_95 = F_28 ( V_16 , & V_94 ) ;
V_126 = & V_2 -> V_126 [ F_40 ( V_16 ) ] ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
switch ( V_128 ) {
case V_133 :
memset ( V_129 , 0 , 4 ) ;
break;
case V_134 :
if ( V_16 -> V_39 == V_40 &&
( V_130 < V_34 ||
V_79 != ( V_33 << 8 ) ) ) {
F_15 ( V_2 , L_16
L_17 ) ;
goto error;
}
F_7 ( V_16 , V_2 ,
(struct V_3 * ) V_129 ) ;
break;
case V_135 | V_136 :
if ( ( V_79 & 0xff00 ) != ( V_137 << 8 ) )
goto error;
if ( V_16 -> V_39 != V_40 )
goto error;
memcpy ( V_129 , & V_138 ,
V_139 + V_140 ) ;
if ( ( V_2 -> V_117 & V_141 ) ) {
V_6 = F_5 ( & V_2 -> V_142 -> V_143 ) ;
V_129 [ 12 ] = F_41 ( V_6 ) ;
F_42 ( F_43 ( V_6 ) , & V_129 [ 13 ] ) ;
}
V_6 = F_5 ( & V_2 -> V_142 -> V_10 ) ;
if ( F_44 ( V_6 ) )
V_129 [ 8 ] |= V_144 ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
return V_139 + V_140 ;
case V_145 :
if ( ! V_76 || V_76 > V_95 )
goto error;
V_76 -- ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
if ( V_6 == 0xffffffff ) {
V_131 = - V_146 ;
break;
}
V_72 = F_38 ( V_16 , V_126 , V_94 ,
V_76 , V_6 , V_60 ) ;
if ( V_72 == 0xffffffff )
goto error;
F_15 ( V_2 , L_18 ,
V_76 , V_6 ) ;
F_15 ( V_2 , L_19 , V_72 ) ;
F_45 ( F_46 ( V_72 ) , ( T_4 * ) V_129 ) ;
break;
case V_147 :
if ( V_79 == V_148 )
V_97 = ( V_76 & 0xff00 ) >> 3 ;
if ( V_79 == V_149 )
V_100 = V_76 & 0xff00 ;
V_132 = ( V_76 & 0xff00 ) >> 8 ;
V_76 &= 0xff ;
if ( ! V_76 || V_76 > V_95 )
goto error;
V_76 -- ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
if ( V_6 == 0xffffffff ) {
V_131 = - V_146 ;
break;
}
V_6 = F_11 ( V_6 ) ;
switch ( V_79 ) {
case V_150 :
V_6 = F_5 ( V_94 [ V_76 ] ) ;
if ( ( V_6 & V_98 ) != V_121 ) {
F_30 ( V_2 , V_94 , V_76 ,
V_121 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_47 ( 10 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
}
V_6 = F_5 ( V_94 [ V_76 ] ) ;
if ( ( V_6 & V_78 ) == 0 || ( V_6 & V_151 )
|| ( V_6 & V_98 ) >= V_152 ) {
F_22 ( V_2 , L_20
L_21 ) ;
goto error;
}
V_48 = F_12 ( V_16 , V_2 ,
V_76 + 1 ) ;
if ( ! V_48 ) {
F_22 ( V_2 , L_22 ) ;
goto error;
}
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_13 ( V_2 , V_48 , 1 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
F_30 ( V_2 , V_94 , V_76 , V_152 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_47 ( 10 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
V_126 -> V_153 |= 1 << V_76 ;
break;
case V_148 :
V_6 = F_5 ( V_94 [ V_76 ] ) ;
if ( V_97 == V_154 ) {
F_15 ( V_2 , L_23 , V_76 ) ;
V_6 = F_11 ( V_6 ) ;
V_6 |= V_86 | V_90 | V_84 |
V_88 | V_82 | V_92 |
V_155 ;
F_26 ( V_6 | V_78 , V_94 [ V_76 ] ) ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
break;
}
if ( V_97 == V_156 ) {
F_15 ( V_2 , L_24 , V_76 ) ;
F_30 ( V_2 , V_94 , V_76 ,
V_97 ) ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
break;
}
if ( ( V_6 & V_78 ) == 0 ||
( V_97 > V_157 ) ) {
F_22 ( V_2 , L_25 ) ;
goto error;
}
if ( V_97 == V_157 ) {
V_48 = F_12 ( V_16 , V_2 ,
V_76 + 1 ) ;
if ( V_48 ) {
F_17 ( & V_2 -> V_64 ,
V_60 ) ;
F_13 ( V_2 , V_48 , 1 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
}
}
F_30 ( V_2 , V_94 , V_76 ,
V_97 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_47 ( 20 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
if ( V_97 == V_157 )
V_126 -> V_153 |= 1 << V_76 ;
break;
case V_158 :
F_26 ( V_6 | V_159 , V_94 [ V_76 ] ) ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
F_15 ( V_2 , L_26 , V_76 , V_6 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
V_6 = F_48 ( V_16 -> V_160 . V_161 ,
V_76 ) ;
if ( V_6 )
F_49 ( V_16 -> V_160 . V_161 ,
V_76 , true ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
break;
case V_162 :
V_6 = ( V_6 | V_151 ) ;
F_26 ( V_6 , V_94 [ V_76 ] ) ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
F_15 ( V_2 , L_27 , V_76 , V_6 ) ;
break;
case V_149 :
F_31 ( V_2 , V_94 ,
V_76 , V_100 ) ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
F_15 ( V_2 , L_28
L_29 ,
V_76 , V_6 ) ;
break;
case V_163 :
V_6 |= V_164 ;
F_26 ( V_6 , V_94 [ V_76 ] ) ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
break;
case V_165 :
if ( V_16 -> V_39 != V_40 )
goto error;
V_6 = F_5 ( V_94 [ V_76 ] + V_166 ) ;
V_6 &= ~ V_167 ;
V_6 |= F_50 ( V_132 ) ;
F_26 ( V_6 , V_94 [ V_76 ] + V_166 ) ;
break;
case V_168 :
if ( V_16 -> V_39 != V_40 )
goto error;
V_6 = F_5 ( V_94 [ V_76 ] + V_166 ) ;
V_6 &= ~ V_169 ;
V_6 |= F_51 ( V_132 ) ;
F_26 ( V_6 , V_94 [ V_76 ] + V_166 ) ;
break;
default:
goto error;
}
V_6 = F_5 ( V_94 [ V_76 ] ) ;
break;
case V_170 :
if ( ! V_76 || V_76 > V_95 )
goto error;
V_76 -- ;
V_6 = F_5 ( V_94 [ V_76 ] ) ;
if ( V_6 == 0xffffffff ) {
V_131 = - V_146 ;
break;
}
V_6 = F_11 ( V_6 ) ;
switch ( V_79 ) {
case V_150 :
V_6 = F_5 ( V_94 [ V_76 ] ) ;
F_15 ( V_2 , L_30 ) ;
F_15 ( V_2 , L_31 , V_6 ) ;
if ( V_6 & V_151 )
goto error;
if ( ( V_6 & V_98 ) == V_152 ) {
if ( ( V_6 & V_78 ) == 0 )
goto error;
F_30 ( V_2 , V_94 , V_76 ,
V_112 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_47 ( 20 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
F_30 ( V_2 , V_94 , V_76 ,
V_121 ) ;
}
V_126 -> V_171 |= 1 << V_76 ;
V_48 = F_12 ( V_16 , V_2 ,
V_76 + 1 ) ;
if ( ! V_48 ) {
F_15 ( V_2 , L_22 ) ;
goto error;
}
F_23 ( V_2 , V_48 ) ;
break;
case V_91 :
V_126 -> V_171 &= ~ ( 1 << V_76 ) ;
case V_81 :
case V_83 :
case V_85 :
case V_87 :
case V_89 :
case V_93 :
F_27 ( V_2 , V_79 , V_76 ,
V_94 [ V_76 ] , V_6 ) ;
break;
case V_172 :
F_25 ( V_16 , V_2 , V_76 ,
V_94 [ V_76 ] , V_6 ) ;
break;
case V_158 :
F_26 ( V_6 & ~ V_159 , V_94 [ V_76 ] ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
V_6 = F_48 ( V_16 -> V_160 . V_161 ,
V_76 ) ;
if ( V_6 )
F_49 ( V_16 -> V_160 . V_161 ,
V_76 , false ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
break;
default:
goto error;
}
break;
default:
error:
V_131 = - V_173 ;
}
F_17 ( & V_2 -> V_64 , V_60 ) ;
return V_131 ;
}
int F_52 ( struct V_15 * V_16 , char * V_129 )
{
unsigned long V_60 ;
T_3 V_6 , V_72 ;
T_3 V_174 ;
int V_20 , V_131 ;
struct V_1 * V_2 = F_29 ( V_16 ) ;
int V_95 ;
T_4 T_5 * * V_94 ;
struct V_125 * V_126 ;
bool V_175 = false ;
V_95 = F_28 ( V_16 , & V_94 ) ;
V_126 = & V_2 -> V_126 [ F_40 ( V_16 ) ] ;
V_131 = ( V_95 + 8 ) / 8 ;
memset ( V_129 , 0 , V_131 ) ;
V_72 = V_126 -> V_176 ;
V_174 = V_86 | V_90 | V_88 | V_92 | V_84 ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
for ( V_20 = 0 ; V_20 < V_95 ; V_20 ++ ) {
V_6 = F_5 ( V_94 [ V_20 ] ) ;
if ( V_6 == 0xffffffff ) {
V_131 = - V_146 ;
break;
}
if ( ( V_6 & V_174 ) != 0 ||
( V_126 -> V_171 & 1 << V_20 ) ||
( V_126 -> V_177 [ V_20 ] && F_53 (
V_178 , V_126 -> V_177 [ V_20 ] ) ) ) {
V_129 [ ( V_20 + 1 ) / 8 ] |= 1 << ( V_20 + 1 ) % 8 ;
V_72 = 1 ;
}
if ( ( V_6 & V_82 ) )
V_175 = true ;
}
if ( ! V_72 && ! V_175 ) {
F_15 ( V_2 , L_32 , V_179 ) ;
F_54 ( V_180 , & V_16 -> V_60 ) ;
}
F_17 ( & V_2 -> V_64 , V_60 ) ;
return V_72 ? V_131 : 0 ;
}
int F_55 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_29 ( V_16 ) ;
int V_95 , V_181 ;
T_4 T_5 * * V_94 ;
struct V_125 * V_126 ;
unsigned long V_60 ;
V_95 = F_28 ( V_16 , & V_94 ) ;
V_126 = & V_2 -> V_126 [ F_40 ( V_16 ) ] ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
if ( V_16 -> V_160 . V_161 -> V_182 ) {
if ( V_126 -> V_176 ) {
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_15 ( V_2 , L_33
L_34 ) ;
return - V_183 ;
}
}
V_181 = V_95 ;
V_126 -> V_184 = 0 ;
while ( V_181 -- ) {
T_3 V_185 , V_186 ;
int V_48 ;
V_185 = F_5 ( V_94 [ V_181 ] ) ;
V_186 = F_11 ( V_185 ) ;
if ( ( V_185 & V_78 ) && ! ( V_185 & V_98 ) ) {
F_15 ( V_2 , L_35 , V_181 ) ;
V_48 = F_12 ( V_16 , V_2 ,
V_181 + 1 ) ;
if ( V_48 ) {
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_13 ( V_2 , V_48 , 1 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
}
V_186 &= ~ V_98 ;
V_186 |= V_99 | V_152 ;
F_56 ( V_181 , & V_126 -> V_184 ) ;
}
if ( V_16 -> V_160 . V_161 -> V_182
&& F_57 ( V_16 -> V_160 . V_187 ) ) {
if ( V_185 & V_188 ) {
V_186 |= V_106 | V_104 ;
V_186 &= ~ V_102 ;
} else {
V_186 |= V_106 | V_102 ;
V_186 &= ~ V_104 ;
}
} else
V_186 &= ~ V_189 ;
V_185 = F_11 ( V_185 ) ;
if ( V_185 != V_186 )
F_26 ( V_186 , V_94 [ V_181 ] ) ;
}
V_16 -> V_44 = V_190 ;
V_126 -> V_191 = V_178 + F_58 ( 10 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
return 0 ;
}
int F_59 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_29 ( V_16 ) ;
int V_95 , V_181 ;
T_4 T_5 * * V_94 ;
struct V_125 * V_126 ;
T_3 V_6 ;
unsigned long V_60 ;
V_95 = F_28 ( V_16 , & V_94 ) ;
V_126 = & V_2 -> V_126 [ F_40 ( V_16 ) ] ;
if ( F_60 ( V_178 , V_126 -> V_191 ) )
F_47 ( 5 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
if ( ! F_61 ( V_16 ) ) {
F_17 ( & V_2 -> V_64 , V_60 ) ;
return - V_192 ;
}
V_6 = F_5 ( & V_2 -> V_193 -> V_69 ) ;
V_6 &= ~ V_194 ;
F_26 ( V_6 , & V_2 -> V_193 -> V_69 ) ;
V_181 = V_95 ;
while ( V_181 -- ) {
T_3 V_6 ;
int V_48 ;
V_6 = F_5 ( V_94 [ V_181 ] ) ;
if ( F_62 ( V_6 ) )
V_6 &= ~ ( V_195 | V_155 | V_189 ) ;
else
V_6 &= ~ ( V_195 | V_189 ) ;
if ( F_63 ( V_181 , & V_126 -> V_184 ) &&
( V_6 & V_98 ) ) {
if ( F_62 ( V_6 ) ) {
F_30 ( V_2 , V_94 ,
V_181 , V_121 ) ;
} else {
F_30 ( V_2 , V_94 ,
V_181 , V_112 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_47 ( 20 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
F_30 ( V_2 , V_94 ,
V_181 , V_121 ) ;
}
F_17 ( & V_2 -> V_64 , V_60 ) ;
F_47 ( 20 ) ;
F_16 ( & V_2 -> V_64 , V_60 ) ;
F_32 ( V_2 , V_94 , V_181 ,
V_92 ) ;
V_48 = F_12 ( V_16 ,
V_2 , V_181 + 1 ) ;
if ( V_48 )
F_23 ( V_2 , V_48 ) ;
} else
F_26 ( V_6 , V_94 [ V_181 ] ) ;
}
( void ) F_5 ( & V_2 -> V_193 -> V_69 ) ;
V_126 -> V_191 = V_178 + F_58 ( 5 ) ;
V_6 = F_5 ( & V_2 -> V_193 -> V_69 ) ;
V_6 |= V_194 ;
F_26 ( V_6 , & V_2 -> V_193 -> V_69 ) ;
V_6 = F_5 ( & V_2 -> V_193 -> V_69 ) ;
F_17 ( & V_2 -> V_64 , V_60 ) ;
return 0 ;
}
