static inline unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned long V_6 = V_7 + V_8 ;
int V_9 ;
while ( F_6 ( V_7 , V_6 ) ) {
V_9 = F_1 ( V_2 , V_10 ) ;
if ( V_2 -> V_11 == V_12 ) {
while ( ! ( V_9 & V_13 ) ) {
F_7 ( 500 , 1000 ) ;
V_9 = F_1 ( V_2 , V_10 ) ;
}
return;
}
if ( V_9 & V_13 )
return;
}
F_8 ( V_2 -> V_14 , L_1 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_15 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_18 * V_19 = F_10 ( V_17 ) ;
unsigned long V_9 ;
int V_20 ;
F_3 ( V_2 , V_2 -> V_21 , V_22 ) ;
F_3 ( V_2 , V_2 -> V_23 , V_24 ) ;
if ( V_17 -> V_25 . V_26 == V_27 ) {
F_3 ( V_2 , ( ( V_19 -> V_28 & V_29 )
<< V_30 ) , V_31 ) ;
F_3 ( V_2 , V_32
| V_33 , V_34 ) ;
} else {
if ( V_2 -> V_11 == V_35 )
F_3 ( V_2 , V_33
| V_36
| V_37 , V_34 ) ;
else
F_3 ( V_2 , V_32
| V_33
| V_38
| V_36
| V_39
| V_37 , V_34 ) ;
}
V_9 = ( V_40 | V_41
| V_42 | V_43
| V_44 | V_45
| ( ( V_2 -> V_46 == 4 ? 1 : 0 )
<< V_47 )
| ( ( V_2 -> V_48 & V_49 )
<< V_50 ) ) ;
if ( V_15 )
V_9 |= V_51 ;
F_11 ( & V_2 -> V_52 ) ;
F_3 ( V_2 , V_9 , V_53 ) ;
V_20 = F_12 ( & V_2 -> V_52 ,
V_54 ) ;
if ( ! V_20 ) {
F_8 ( V_2 -> V_14 , L_2 ) ;
V_9 = F_1 ( V_2 , V_53 ) ;
if ( ! ( V_9 & V_40 ) )
F_8 ( V_2 -> V_14 , L_3 ) ;
else
F_8 ( V_2 -> V_14 , L_4 ) ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_55 [ 0 ] &= 0xffff0000 ;
F_3 ( V_2 , V_2 -> V_55 [ 0 ] , V_56 ) ;
F_3 ( V_2 , V_2 -> V_55 [ 1 ] , V_57 ) ;
F_3 ( V_2 , V_58 << 8 | V_59 ,
V_60 ) ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_10 ( & V_2 -> V_17 ) ;
if ( ( V_2 -> V_55 [ 0 ] == V_2 -> V_61 [ 0 ] ) &&
( V_2 -> V_55 [ 1 ] == V_2 -> V_61 [ 1 ] ) )
return 0 ;
V_2 -> V_55 [ 0 ] &= 0xffff0000 ;
F_3 ( V_2 , V_2 -> V_55 [ 0 ] , V_56 ) ;
F_3 ( V_2 , V_2 -> V_55 [ 1 ] , V_57 ) ;
F_3 ( V_2 , V_62 << 8 | V_63 ,
V_60 ) ;
F_3 ( V_2 , 0 , V_64 ) ;
F_3 ( V_2 , V_19 -> V_65 + V_19 -> V_28 ,
V_66 ) ;
F_9 ( V_2 , 0 ) ;
V_2 -> V_61 [ 0 ] = V_2 -> V_55 [ 0 ] ;
V_2 -> V_61 [ 1 ] = V_2 -> V_55 [ 1 ] ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_2 -> V_55 [ 0 ] , V_56 ) ;
F_3 ( V_2 , ( V_12 << 8 ) | V_67 ,
V_60 ) ;
F_3 ( V_2 , V_68
| V_69
| V_70
| V_71
| ( ( V_2 -> V_48 & V_72 )
<< V_73 )
| ( ( V_2 -> V_46 & V_74 )
<< V_75 ) ,
V_76 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_77 , V_78 ) ;
F_3 ( V_2 , V_79 , V_60 ) ;
F_3 ( V_2 , 0 , V_56 ) ;
F_3 ( V_2 , V_70 | V_71
| V_80
| ( ( V_2 -> V_48 & V_72 )
<< V_73 )
| 1 << V_75 , V_76 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_77 , V_78 ) ;
F_3 ( V_2 , V_81 , V_60 ) ;
F_3 ( V_2 , V_70
| V_80
| ( ( V_2 -> V_48 & V_72 )
<< V_73 ) ,
V_76 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_48 )
{
F_3 ( V_2 , V_82 , V_60 ) ;
F_3 ( V_2 , V_70
| ( ( V_48 & V_72 )
<< V_73 )
| V_68 ,
V_76 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_18 * V_19 , int V_48 )
{
struct V_16 * V_17 = F_20 ( V_19 ) ;
struct V_1 * V_2 = F_21 ( V_17 ) ;
if ( V_48 < 0 )
return;
V_2 -> V_48 = V_48 ;
}
static T_1 F_22 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = F_20 ( V_19 ) ;
struct V_1 * V_2 = F_21 ( V_17 ) ;
if ( V_2 -> V_11 == V_81 )
return * ( T_1 * ) ( V_2 -> V_83 ) ;
V_2 -> V_84 ++ ;
if ( V_2 -> V_11 == V_79 )
return * ( T_1 * ) ( V_2 -> V_83 + V_2 -> V_84 - 1 ) ;
return * ( T_1 * ) ( V_2 -> V_85 + V_2 -> V_84 - 1 ) ;
}
static T_2 F_23 ( struct V_18 * V_19 )
{
struct V_16 * V_17 = F_20 ( V_19 ) ;
struct V_1 * V_2 = F_21 ( V_17 ) ;
V_2 -> V_84 += 2 ;
return * ( T_2 * ) ( V_2 -> V_85 + V_2 -> V_84 - 2 ) ;
}
static void
F_24 ( struct V_18 * V_19 , const T_1 * V_86 , int V_87 )
{
struct V_16 * V_17 = F_20 ( V_19 ) ;
struct V_1 * V_2 = F_21 ( V_17 ) ;
memcpy ( V_2 -> V_85 + V_2 -> V_84 , V_86 , V_87 ) ;
V_2 -> V_84 += V_87 ;
}
static void F_25 ( struct V_18 * V_19 , T_1 * V_86 , int V_87 )
{
struct V_16 * V_17 = F_20 ( V_19 ) ;
struct V_1 * V_2 = F_21 ( V_17 ) ;
memcpy ( V_86 , V_2 -> V_85 + V_2 -> V_84 , V_87 ) ;
V_2 -> V_84 += V_87 ;
}
static void F_26 ( struct V_18 * V_19 , int V_88 , int V_89 )
{
struct V_16 * V_17 = F_20 ( V_19 ) ;
struct V_1 * V_2 = F_21 ( V_17 ) ;
unsigned int V_11 = V_2 -> V_11 ;
V_2 -> V_46 = 0 ;
V_2 -> V_55 [ 0 ] = 0 ;
V_2 -> V_55 [ 1 ] = 0 ;
if ( V_88 != - 1 ) {
if ( V_17 -> V_90 & V_91 &&
! F_27 ( V_11 ) )
V_88 >>= 1 ;
V_2 -> V_55 [ 0 ] = V_88 & 0xffff ;
V_2 -> V_46 = 2 ;
}
if ( V_89 != - 1 ) {
V_2 -> V_55 [ 0 ] |= ( V_89 & 0xffff )
<< ( V_2 -> V_46 * 8 ) ;
V_2 -> V_46 += 2 ;
if ( V_17 -> V_92 > ( 128 << 20 ) ) {
V_2 -> V_46 += 1 ;
if ( V_2 -> V_11 == V_67 )
V_2 -> V_55 [ 0 ] |= ( ( V_89 >> 16 ) & 0xff ) << 16 ;
else
V_2 -> V_55 [ 1 ] |= ( ( V_89 >> 16 ) & 0xff ) ;
}
}
}
static void F_28 ( struct V_18 * V_19 , unsigned V_11 , int V_88 ,
int V_89 )
{
struct V_16 * V_17 = F_20 ( V_19 ) ;
struct V_1 * V_2 = F_21 ( V_17 ) ;
int V_93 = 1 ;
unsigned int V_94 = 0 ;
V_2 -> V_11 = V_11 ;
switch ( V_11 ) {
case V_63 :
case V_35 :
if ( V_11 == V_63 )
V_2 -> V_84 = V_88 ;
else
V_2 -> V_84 = V_88 + V_19 -> V_65 ;
V_93 = 0 ;
F_26 ( V_19 , V_88 , V_89 ) ;
F_14 ( V_2 ) ;
break;
case V_59 :
V_2 -> V_84 = V_88 ;
F_26 ( V_19 , V_88 , V_89 ) ;
break;
case V_67 :
F_26 ( V_19 , V_88 , V_89 ) ;
break;
case V_58 :
F_13 ( V_2 ) ;
break;
case V_12 :
F_15 ( V_2 ) ;
break;
case V_79 :
V_2 -> V_84 = V_88 ;
memset ( V_2 -> V_83 , 0 , 0x10 ) ;
F_16 ( V_2 ) ;
break;
case V_81 :
V_94 = F_1 ( V_2 , V_95 ) ;
if ( V_17 -> V_25 . V_26 == V_96 )
F_3 ( V_2 ,
V_94 & ~ ( V_97 <<
V_98 ) , V_95 ) ;
V_2 -> V_84 = 0 ;
memset ( V_2 -> V_83 , 0 , 0x10 ) ;
F_17 ( V_2 ) ;
F_3 ( V_2 , V_94 , V_95 ) ;
break;
case V_82 :
F_18 ( V_2 , V_2 -> V_48 ) ;
break;
default:
F_8 ( V_2 -> V_14 , L_5 ,
V_11 , V_88 , V_89 ) ;
}
if ( V_93 ) {
V_2 -> V_61 [ 0 ] = ~ 0 ;
V_2 -> V_61 [ 1 ] = ~ 0 ;
}
}
static T_3 F_29 ( int V_99 , void * V_100 )
{
struct V_1 * V_2 = V_100 ;
unsigned int V_94 ;
V_94 = F_1 ( V_2 , V_101 ) ;
V_2 -> V_102 |= V_94 ;
if ( V_94 & V_103 ) {
F_3 ( V_2 , V_104 , V_105 ) ;
F_30 ( & V_2 -> V_52 ) ;
} else if ( V_94 & V_106 ) {
F_3 ( V_2 , V_107 , V_105 ) ;
} else if ( V_94 & V_108 ) {
F_3 ( V_2 , V_109 , V_105 ) ;
}
return V_110 ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_16 * V_17 , T_1 * V_86 , int V_111 , int V_112 )
{
struct V_1 * V_2 = F_21 ( V_17 ) ;
int V_113 = 0 , V_114 = 0 , V_115 = 0 , V_116 ;
int V_117 , V_118 ;
V_17 -> V_119 ( V_19 , V_86 , V_19 -> V_65 ) ;
V_17 -> V_119 ( V_19 , V_17 -> V_120 , V_19 -> V_28 ) ;
if ( V_2 -> V_102 & V_108 ) {
V_19 -> V_121 . V_122 ++ ;
} else if ( V_2 -> V_102 & V_106 ) {
switch ( V_17 -> V_25 . V_123 ) {
case 16 :
V_116 = F_1 ( V_2 , V_124 ) >>
V_125 & 0x0fff ;
V_118 = V_116 & 0x3f ;
V_117 = V_116 >> 6 & 0x3f ;
V_114 = V_117 + V_118 ;
V_115 = F_32 ( int , V_117 , V_118 ) ;
}
V_19 -> V_121 . V_126 += V_114 ;
V_113 = F_32 ( int , V_113 , V_115 ) ;
}
V_2 -> V_102 = 0 ;
return V_113 ;
}
static int F_33 ( struct V_18 * V_19 , struct V_16 * V_17 ,
int V_112 )
{
struct V_1 * V_2 = F_21 ( V_17 ) ;
V_17 -> V_127 ( V_19 , V_35 , 0 , V_112 ) ;
V_17 -> V_119 ( V_19 , V_17 -> V_120 , V_19 -> V_28 ) ;
if ( V_2 -> V_102 & V_108 ) {
V_2 -> V_102 = 0 ;
return - V_128 ;
}
V_2 -> V_102 = 0 ;
return 0 ;
}
static int F_34 ( struct V_18 * V_19 ,
struct V_16 * V_17 , const T_1 * V_86 , int V_111 ,
int V_112 )
{
V_17 -> V_129 ( V_19 , V_86 , V_19 -> V_65 ) ;
if ( V_111 )
V_17 -> V_129 ( V_19 , V_17 -> V_120 , V_19 -> V_28 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
unsigned int V_94 = 0 ;
V_2 -> V_130 = F_1 ( V_2 , V_131 ) ;
V_2 -> V_46 = 0 ;
V_2 -> V_55 [ 0 ] = 0 ;
V_2 -> V_55 [ 1 ] = 0 ;
V_2 -> V_61 [ 0 ] = ~ 0 ;
V_2 -> V_61 [ 1 ] = ~ 0 ;
V_2 -> V_48 = 0 ;
V_94 = V_132 | V_133
| ( ( 0x001 & V_134 )
<< V_135 )
| ( ( 0x0 & V_97 )
<< V_98 )
| ( ( V_17 -> V_90 & V_91 ) ?
V_136 : 0 ) ;
F_3 ( V_2 , V_94 , V_95 ) ;
memset ( V_2 -> V_83 , 0xff , V_137 ) ;
F_3 ( V_2 , F_36 ( V_138 ,
V_139 , V_140 ) , V_141 ) ;
F_3 ( V_2 , V_142 , V_143 ) ;
}
static int F_37 ( struct V_18 * V_19 , int V_144 ,
struct V_145 * V_146 )
{
return - V_147 ;
}
static int F_38 ( struct V_18 * V_19 , int V_144 ,
struct V_145 * V_146 )
{
if ( V_144 )
return - V_148 ;
V_146 -> V_84 = 2 ;
V_146 -> V_149 = 6 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
unsigned int V_94 ;
int V_150 , V_123 , V_151 ;
struct V_152 * V_14 = V_2 -> V_14 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_18 * V_19 = F_10 ( V_17 ) ;
V_150 = V_17 -> V_25 . V_150 ;
V_123 = V_17 -> V_25 . V_123 ;
if ( V_150 != 1024 ) {
F_8 ( V_14 , L_6 , V_150 ) ;
return - V_153 ;
}
if ( ( V_150 == 1024 ) && ( ( V_123 != 8 ) && ( V_123 != 16 ) &&
( V_123 != 24 ) && ( V_123 != 40 ) ) ) {
F_8 ( V_14 , L_7 ) ;
return - V_153 ;
}
V_17 -> V_25 . V_150 = V_150 ;
V_17 -> V_25 . V_123 = V_123 ;
V_17 -> V_25 . V_154 = F_31 ;
V_17 -> V_25 . V_155 = F_33 ;
V_17 -> V_25 . V_156 = F_34 ;
switch ( V_17 -> V_25 . V_123 ) {
case 16 :
V_151 = 6 ;
if ( V_19 -> V_65 == 2048 )
F_40 ( V_19 , & V_157 ) ;
break;
default:
F_8 ( V_14 , L_8 , V_17 -> V_25 . V_123 ) ;
return - V_153 ;
}
V_94 = F_1 ( V_2 , V_95 ) ;
V_94 |= ( ( V_151 & V_97 )
<< V_98 ) ;
F_3 ( V_2 , V_94 , V_95 ) ;
V_94 = F_1 ( V_2 , V_143 ) & 0xfff ;
F_3 ( V_2 , V_94 | V_158 | V_159 ,
V_143 ) ;
return 0 ;
}
static int F_41 ( struct V_160 * V_161 )
{
int V_20 = 0 , V_99 , V_94 , V_162 = V_163 ;
struct V_152 * V_14 = & V_161 -> V_14 ;
struct V_1 * V_2 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_164 * V_165 ;
struct V_166 * V_167 = V_14 -> V_168 ;
V_2 = F_42 ( V_14 , sizeof( * V_2 ) , V_169 ) ;
if ( ! V_2 )
return - V_170 ;
V_2 -> V_14 = V_14 ;
F_43 ( V_161 , V_2 ) ;
V_17 = & V_2 -> V_17 ;
V_19 = F_10 ( V_17 ) ;
V_99 = F_44 ( V_161 , 0 ) ;
if ( V_99 < 0 ) {
F_8 ( V_14 , L_9 ) ;
V_20 = - V_171 ;
goto V_172;
}
V_165 = F_45 ( V_161 , V_173 , 0 ) ;
V_2 -> V_4 = F_46 ( V_14 , V_165 ) ;
if ( F_47 ( V_2 -> V_4 ) ) {
V_20 = F_48 ( V_2 -> V_4 ) ;
goto V_172;
}
V_165 = F_45 ( V_161 , V_173 , 1 ) ;
V_2 -> V_83 = F_46 ( V_14 , V_165 ) ;
if ( F_47 ( V_2 -> V_83 ) ) {
V_20 = F_48 ( V_2 -> V_83 ) ;
F_8 ( V_14 , L_10 ) ;
goto V_172;
}
V_19 -> V_174 = L_11 ;
V_19 -> V_14 . V_175 = & V_161 -> V_14 ;
F_49 ( V_17 , V_2 ) ;
F_50 ( V_17 , V_167 ) ;
V_17 -> V_127 = F_28 ;
V_17 -> V_176 = F_19 ;
V_17 -> V_177 = F_22 ;
V_17 -> V_178 = F_23 ;
V_17 -> V_129 = F_24 ;
V_17 -> V_119 = F_25 ;
V_17 -> V_179 = V_180 ;
F_35 ( V_2 ) ;
V_20 = F_51 ( V_14 , V_99 , F_29 , 0x0 , L_12 , V_2 ) ;
if ( V_20 ) {
F_8 ( V_14 , L_13 ) ;
goto V_172;
}
V_20 = F_52 ( V_19 , V_162 , NULL ) ;
if ( V_20 )
goto V_172;
V_2 -> V_85 = F_53 ( V_14 , V_19 -> V_65 + V_19 -> V_28 ,
& V_2 -> V_21 , V_169 ) ;
if ( ! V_2 -> V_85 ) {
V_20 = - V_170 ;
goto V_172;
}
V_2 -> V_23 = V_2 -> V_21 + V_19 -> V_65 ;
memset ( V_2 -> V_85 , 0xff , V_19 -> V_65 + V_19 -> V_28 ) ;
V_94 = F_1 ( V_2 , V_95 ) ;
V_94 &= ~ ( V_134 << V_135 ) ;
switch ( V_19 -> V_65 ) {
case 2048 :
V_94 |= ( 0x001 << V_135 ) ; break;
default:
F_8 ( V_14 , L_14 ) ;
V_20 = - V_153 ;
goto V_172;
}
F_3 ( V_2 , V_94 , V_95 ) ;
if ( V_17 -> V_25 . V_26 == V_96 )
F_39 ( V_2 ) ;
V_20 = F_54 ( V_19 ) ;
if ( V_20 ) {
F_8 ( V_14 , L_15 , V_20 ) ;
goto V_172;
}
V_20 = F_55 ( V_19 , NULL , 0 ) ;
if ( V_20 ) {
F_8 ( V_14 , L_16 , V_20 ) ;
goto V_181;
}
return 0 ;
V_181:
F_56 ( V_19 ) ;
V_172:
return V_20 ;
}
static int F_57 ( struct V_160 * V_161 )
{
struct V_1 * V_2 = F_58 ( V_161 ) ;
struct V_18 * V_19 = F_10 ( & V_2 -> V_17 ) ;
F_56 ( V_19 ) ;
return 0 ;
}
static int F_59 ( struct V_152 * V_14 )
{
struct V_1 * V_2 = F_60 ( V_14 ) ;
unsigned long V_6 = V_7 + V_182 ;
while ( F_6 ( V_7 , V_6 ) ) {
if ( ( ( F_1 ( V_2 , V_10 ) & 0x1 ) == 0x0 ) &&
( F_1 ( V_2 , V_53 ) &
V_40 ) ) {
F_61 () ;
return 0 ;
}
}
F_8 ( V_2 -> V_14 , L_17 ) ;
return - V_183 ;
}
static int F_62 ( struct V_152 * V_14 )
{
int V_184 ;
struct V_1 * V_2 = F_60 ( V_14 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
for ( V_184 = 0 ; V_184 < V_17 -> V_185 ; V_184 ++ )
F_18 ( V_2 , V_184 ) ;
F_3 ( V_2 , F_36 ( V_138 ,
V_139 , V_140 ) , V_141 ) ;
return 0 ;
}
