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
struct V_18 * V_19 = V_17 -> V_20 ;
unsigned long V_9 ;
int V_21 ;
F_3 ( V_2 , V_2 -> V_22 , V_23 ) ;
F_3 ( V_2 , V_2 -> V_24 , V_25 ) ;
if ( V_19 -> V_26 . V_27 == V_28 ) {
F_3 ( V_2 , ( ( V_17 -> V_29 & V_30 )
<< V_31 ) , V_32 ) ;
F_3 ( V_2 , V_33
| V_34 , V_35 ) ;
} else {
if ( V_2 -> V_11 == V_36 )
F_3 ( V_2 , V_34
| V_37
| V_38 , V_35 ) ;
else
F_3 ( V_2 , V_33
| V_34
| V_39
| V_37
| V_40
| V_38 , V_35 ) ;
}
V_9 = ( V_41 | V_42
| V_43 | V_44
| V_45 | V_46
| ( ( V_2 -> V_47 == 4 ? 1 : 0 )
<< V_48 )
| ( ( V_2 -> V_49 & V_50 )
<< V_51 ) ) ;
if ( V_15 )
V_9 |= V_52 ;
F_10 ( & V_2 -> V_53 ) ;
F_3 ( V_2 , V_9 , V_54 ) ;
V_21 = F_11 ( & V_2 -> V_53 ,
V_55 ) ;
if ( ! V_21 ) {
F_8 ( V_2 -> V_14 , L_2 ) ;
V_9 = F_1 ( V_2 , V_54 ) ;
if ( ! ( V_9 & V_41 ) )
F_8 ( V_2 -> V_14 , L_3 ) ;
else
F_8 ( V_2 -> V_14 , L_4 ) ;
}
}
static int F_12 ( struct V_1 * V_2 )
{
V_2 -> V_56 [ 0 ] &= 0xffff0000 ;
F_3 ( V_2 , V_2 -> V_56 [ 0 ] , V_57 ) ;
F_3 ( V_2 , V_2 -> V_56 [ 1 ] , V_58 ) ;
F_3 ( V_2 , V_59 << 8 | V_60 ,
V_61 ) ;
F_9 ( V_2 , 1 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_17 ;
if ( ( V_2 -> V_56 [ 0 ] == V_2 -> V_62 [ 0 ] ) &&
( V_2 -> V_56 [ 1 ] == V_2 -> V_62 [ 1 ] ) )
return 0 ;
V_2 -> V_56 [ 0 ] &= 0xffff0000 ;
F_3 ( V_2 , V_2 -> V_56 [ 0 ] , V_57 ) ;
F_3 ( V_2 , V_2 -> V_56 [ 1 ] , V_58 ) ;
F_3 ( V_2 , V_63 << 8 | V_64 ,
V_61 ) ;
F_3 ( V_2 , 0 , V_65 ) ;
F_3 ( V_2 , V_17 -> V_66 + V_17 -> V_29 ,
V_67 ) ;
F_9 ( V_2 , 0 ) ;
V_2 -> V_62 [ 0 ] = V_2 -> V_56 [ 0 ] ;
V_2 -> V_62 [ 1 ] = V_2 -> V_56 [ 1 ] ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_2 -> V_56 [ 0 ] , V_57 ) ;
F_3 ( V_2 , ( V_12 << 8 ) | V_68 ,
V_61 ) ;
F_3 ( V_2 , V_69
| V_70
| V_71
| V_72
| ( ( V_2 -> V_49 & V_73 )
<< V_74 )
| ( ( V_2 -> V_47 & V_75 )
<< V_76 ) ,
V_77 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_78 , V_79 ) ;
F_3 ( V_2 , V_80 , V_61 ) ;
F_3 ( V_2 , 0 , V_57 ) ;
F_3 ( V_2 , V_71 | V_72
| V_81
| ( ( V_2 -> V_49 & V_73 )
<< V_74 )
| 1 << V_76 , V_77 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_78 , V_79 ) ;
F_3 ( V_2 , V_82 , V_61 ) ;
F_3 ( V_2 , V_71
| V_81
| ( ( V_2 -> V_49 & V_73 )
<< V_74 ) ,
V_77 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_49 )
{
F_3 ( V_2 , V_83 , V_61 ) ;
F_3 ( V_2 , V_71
| ( ( V_49 & V_73 )
<< V_74 )
| V_69 ,
V_77 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_16 * V_17 , int V_49 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_20 ;
if ( V_49 < 0 )
return;
V_2 -> V_49 = V_49 ;
}
static T_1 F_19 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_20 ;
if ( V_2 -> V_11 == V_82 )
return * ( T_1 * ) ( V_2 -> V_84 ) ;
V_2 -> V_85 ++ ;
if ( V_2 -> V_11 == V_80 )
return * ( T_1 * ) ( V_2 -> V_84 + V_2 -> V_85 - 1 ) ;
return * ( T_1 * ) ( V_2 -> V_86 + V_2 -> V_85 - 1 ) ;
}
static T_2 F_20 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_20 ;
V_2 -> V_85 += 2 ;
return * ( T_2 * ) ( V_2 -> V_86 + V_2 -> V_85 - 2 ) ;
}
static void
F_21 ( struct V_16 * V_17 , const T_1 * V_87 , int V_88 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_20 ;
memcpy ( V_2 -> V_86 + V_2 -> V_85 , V_87 , V_88 ) ;
V_2 -> V_85 += V_88 ;
}
static void F_22 ( struct V_16 * V_17 , T_1 * V_87 , int V_88 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_20 ;
memcpy ( V_87 , V_2 -> V_86 + V_2 -> V_85 , V_88 ) ;
V_2 -> V_85 += V_88 ;
}
static void F_23 ( struct V_16 * V_17 , int V_89 , int V_90 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_20 ;
unsigned int V_11 = V_2 -> V_11 ;
V_2 -> V_47 = 0 ;
V_2 -> V_56 [ 0 ] = 0 ;
V_2 -> V_56 [ 1 ] = 0 ;
if ( V_89 != - 1 ) {
if ( V_19 -> V_91 & V_92 &&
! F_24 ( V_11 ) )
V_89 >>= 1 ;
V_2 -> V_56 [ 0 ] = V_89 & 0xffff ;
V_2 -> V_47 = 2 ;
}
if ( V_90 != - 1 ) {
V_2 -> V_56 [ 0 ] |= ( V_90 & 0xffff )
<< ( V_2 -> V_47 * 8 ) ;
V_2 -> V_47 += 2 ;
if ( V_19 -> V_93 > ( 128 << 20 ) ) {
V_2 -> V_47 += 1 ;
if ( V_2 -> V_11 == V_68 )
V_2 -> V_56 [ 0 ] |= ( ( V_90 >> 16 ) & 0xff ) << 16 ;
else
V_2 -> V_56 [ 1 ] |= ( ( V_90 >> 16 ) & 0xff ) ;
}
}
}
static void F_25 ( struct V_16 * V_17 , unsigned V_11 , int V_89 ,
int V_90 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
struct V_1 * V_2 = V_19 -> V_20 ;
int V_94 = 1 ;
unsigned int V_95 = 0 ;
V_2 -> V_11 = V_11 ;
switch ( V_11 ) {
case V_64 :
case V_36 :
if ( V_11 == V_64 )
V_2 -> V_85 = V_89 ;
else
V_2 -> V_85 = V_89 + V_17 -> V_66 ;
V_94 = 0 ;
F_23 ( V_17 , V_89 , V_90 ) ;
F_13 ( V_2 ) ;
break;
case V_60 :
V_2 -> V_85 = V_89 ;
F_23 ( V_17 , V_89 , V_90 ) ;
break;
case V_68 :
F_23 ( V_17 , V_89 , V_90 ) ;
break;
case V_59 :
F_12 ( V_2 ) ;
break;
case V_12 :
F_14 ( V_2 ) ;
break;
case V_80 :
V_2 -> V_85 = V_89 ;
memset ( V_2 -> V_84 , 0 , 0x10 ) ;
F_15 ( V_2 ) ;
break;
case V_82 :
V_95 = F_1 ( V_2 , V_96 ) ;
if ( V_19 -> V_26 . V_27 == V_97 )
F_3 ( V_2 ,
V_95 & ~ ( V_98 <<
V_99 ) , V_96 ) ;
V_2 -> V_85 = 0 ;
memset ( V_2 -> V_84 , 0 , 0x10 ) ;
F_16 ( V_2 ) ;
F_3 ( V_2 , V_95 , V_96 ) ;
break;
case V_83 :
F_17 ( V_2 , V_2 -> V_49 ) ;
break;
default:
F_8 ( V_2 -> V_14 , L_5 ,
V_11 , V_89 , V_90 ) ;
}
if ( V_94 ) {
V_2 -> V_62 [ 0 ] = ~ 0 ;
V_2 -> V_62 [ 1 ] = ~ 0 ;
}
}
static T_3 F_26 ( int V_100 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
unsigned int V_95 ;
V_95 = F_1 ( V_2 , V_102 ) ;
V_2 -> V_103 |= V_95 ;
if ( V_95 & V_104 ) {
F_3 ( V_2 , V_105 , V_106 ) ;
F_27 ( & V_2 -> V_53 ) ;
} else if ( V_95 & V_107 ) {
F_3 ( V_2 , V_108 , V_106 ) ;
} else if ( V_95 & V_109 ) {
F_3 ( V_2 , V_110 , V_106 ) ;
}
return V_111 ;
}
static int F_28 ( struct V_16 * V_17 ,
struct V_18 * V_19 , T_1 * V_87 , int V_112 , int V_113 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
int V_114 = 0 , V_115 = 0 , V_116 = 0 , V_117 ;
int V_118 , V_119 ;
V_19 -> V_120 ( V_17 , V_87 , V_17 -> V_66 ) ;
V_19 -> V_120 ( V_17 , V_19 -> V_121 , V_17 -> V_29 ) ;
if ( V_2 -> V_103 & V_109 ) {
V_17 -> V_122 . V_123 ++ ;
} else if ( V_2 -> V_103 & V_107 ) {
switch ( V_19 -> V_26 . V_124 ) {
case 16 :
V_117 = F_1 ( V_2 , V_125 ) >>
V_126 & 0x0fff ;
V_119 = V_117 & 0x3f ;
V_118 = V_117 >> 6 & 0x3f ;
V_115 = V_118 + V_119 ;
V_116 = F_29 ( int , V_118 , V_119 ) ;
}
V_17 -> V_122 . V_127 += V_115 ;
V_114 = F_29 ( int , V_114 , V_116 ) ;
}
V_2 -> V_103 = 0 ;
return V_114 ;
}
static int F_30 ( struct V_16 * V_17 , struct V_18 * V_19 ,
int V_113 )
{
struct V_1 * V_2 = V_19 -> V_20 ;
V_19 -> V_128 ( V_17 , V_36 , 0 , V_113 ) ;
V_19 -> V_120 ( V_17 , V_19 -> V_121 , V_17 -> V_29 ) ;
if ( V_2 -> V_103 & V_109 ) {
V_2 -> V_103 = 0 ;
return - V_129 ;
}
V_2 -> V_103 = 0 ;
return 0 ;
}
static int F_31 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const T_1 * V_87 , int V_112 )
{
V_19 -> V_130 ( V_17 , V_87 , V_17 -> V_66 ) ;
if ( V_112 )
V_19 -> V_130 ( V_17 , V_19 -> V_121 , V_17 -> V_29 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_19 ;
unsigned int V_95 = 0 ;
V_2 -> V_131 = F_1 ( V_2 , V_132 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_56 [ 0 ] = 0 ;
V_2 -> V_56 [ 1 ] = 0 ;
V_2 -> V_62 [ 0 ] = ~ 0 ;
V_2 -> V_62 [ 1 ] = ~ 0 ;
V_2 -> V_49 = 0 ;
V_95 = V_133 | V_134
| ( ( 0x001 & V_135 )
<< V_136 )
| ( ( 0x0 & V_98 )
<< V_99 )
| ( ( V_19 -> V_91 & V_92 ) ?
V_137 : 0 ) ;
F_3 ( V_2 , V_95 , V_96 ) ;
memset ( V_2 -> V_84 , 0xff , V_138 ) ;
F_3 ( V_2 , F_33 ( V_139 ,
V_140 , V_141 ) , V_142 ) ;
F_3 ( V_2 , V_143 , V_144 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
unsigned int V_95 ;
int V_145 , V_124 , V_146 ;
struct V_147 * V_14 = V_2 -> V_14 ;
struct V_18 * V_19 = & V_2 -> V_19 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_148 * V_149 = V_2 -> V_14 -> V_150 ;
V_145 = F_35 ( V_149 ) ;
V_124 = F_36 ( V_149 ) ;
if ( V_145 != 1024 ) {
F_8 ( V_14 , L_6 , V_145 ) ;
return - V_151 ;
}
if ( ( V_145 == 1024 ) && ( ( V_124 != 8 ) && ( V_124 != 16 ) &&
( V_124 != 24 ) && ( V_124 != 40 ) ) ) {
F_8 ( V_14 , L_7 ) ;
return - V_151 ;
}
V_19 -> V_26 . V_145 = V_145 ;
V_19 -> V_26 . V_124 = V_124 ;
V_19 -> V_26 . V_152 = F_28 ;
V_19 -> V_26 . V_153 = F_30 ;
V_19 -> V_26 . V_154 = F_31 ;
switch ( V_19 -> V_26 . V_124 ) {
case 16 :
V_146 = 6 ;
if ( V_17 -> V_66 == 2048 )
V_19 -> V_26 . V_155 = & V_156 ;
break;
default:
F_8 ( V_14 , L_8 , V_19 -> V_26 . V_124 ) ;
return - V_151 ;
}
V_95 = F_1 ( V_2 , V_96 ) ;
V_95 |= ( ( V_146 & V_98 )
<< V_99 ) ;
F_3 ( V_2 , V_95 , V_96 ) ;
V_95 = F_1 ( V_2 , V_144 ) & 0xfff ;
F_3 ( V_2 , V_95 | V_157 | V_158 ,
V_144 ) ;
return 0 ;
}
static int F_37 ( struct V_159 * V_160 )
{
int V_21 = 0 , V_100 , V_161 , V_95 , V_162 = V_163 ;
struct V_147 * V_14 = & V_160 -> V_14 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
struct V_16 * V_17 ;
struct V_164 * V_165 ;
struct V_148 * V_149 = V_14 -> V_150 ;
struct V_166 V_167 ;
V_2 = F_38 ( V_14 , sizeof( * V_2 ) , V_168 ) ;
if ( ! V_2 )
return - V_169 ;
V_2 -> V_14 = V_14 ;
F_39 ( V_160 , V_2 ) ;
V_19 = & V_2 -> V_19 ;
V_17 = & V_2 -> V_17 ;
V_100 = F_40 ( V_160 , 0 ) ;
if ( V_100 < 0 ) {
F_8 ( V_14 , L_9 ) ;
V_21 = - V_170 ;
goto V_171;
}
V_165 = F_41 ( V_160 , V_172 , 0 ) ;
V_2 -> V_4 = F_42 ( V_14 , V_165 ) ;
if ( F_43 ( V_2 -> V_4 ) ) {
V_21 = F_44 ( V_2 -> V_4 ) ;
goto V_171;
}
V_165 = F_41 ( V_160 , V_172 , 1 ) ;
V_2 -> V_84 = F_42 ( V_14 , V_165 ) ;
if ( F_43 ( V_2 -> V_84 ) ) {
V_21 = F_44 ( V_2 -> V_84 ) ;
F_8 ( V_14 , L_10 ) ;
goto V_171;
}
V_17 -> V_20 = V_19 ;
V_17 -> V_173 = V_174 ;
V_17 -> V_175 = L_11 ;
V_17 -> V_14 . V_176 = & V_160 -> V_14 ;
V_19 -> V_20 = V_2 ;
V_19 -> V_128 = F_25 ;
V_19 -> V_177 = F_18 ;
V_19 -> V_178 = F_19 ;
V_19 -> V_179 = F_20 ;
V_19 -> V_130 = F_21 ;
V_19 -> V_120 = F_22 ;
V_19 -> V_180 = V_181 ;
V_19 -> V_26 . V_27 = F_45 ( V_149 ) ;
V_161 = F_46 ( V_149 ) ;
if ( V_161 == 16 )
V_19 -> V_91 |= V_92 ;
F_32 ( V_2 ) ;
V_21 = F_47 ( V_14 , V_100 , F_26 , 0x0 , L_12 , V_2 ) ;
if ( V_21 ) {
F_8 ( V_14 , L_13 ) ;
goto V_171;
}
V_21 = F_48 ( V_17 , V_162 , NULL ) ;
if ( V_21 ) {
V_21 = - V_182 ;
goto V_171;
}
V_2 -> V_86 = F_49 ( V_14 , V_17 -> V_66 + V_17 -> V_29 ,
& V_2 -> V_22 , V_168 ) ;
if ( ! V_2 -> V_86 ) {
V_21 = - V_169 ;
goto V_171;
}
V_2 -> V_24 = V_2 -> V_22 + V_17 -> V_66 ;
memset ( V_2 -> V_86 , 0xff , V_17 -> V_66 + V_17 -> V_29 ) ;
V_95 = F_1 ( V_2 , V_96 ) ;
V_95 &= ~ ( V_135 << V_136 ) ;
switch ( V_17 -> V_66 ) {
case 2048 :
V_95 |= ( 0x001 << V_136 ) ; break;
default:
F_8 ( V_14 , L_14 ) ;
V_21 = - V_151 ;
goto V_171;
}
F_3 ( V_2 , V_95 , V_96 ) ;
if ( V_19 -> V_26 . V_27 == V_97 )
F_34 ( V_2 ) ;
V_21 = F_50 ( V_17 ) ;
if ( V_21 ) {
F_8 ( V_14 , L_15 , V_21 ) ;
goto V_171;
}
V_167 . V_150 = V_149 ;
V_21 = F_51 ( V_17 , NULL , & V_167 , NULL , 0 ) ;
if ( V_21 ) {
F_8 ( V_14 , L_16 , V_21 ) ;
goto V_183;
}
return 0 ;
V_183:
F_52 ( V_17 ) ;
V_171:
return V_21 ;
}
static int F_53 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = F_54 ( V_160 ) ;
struct V_16 * V_17 = & V_2 -> V_17 ;
F_52 ( V_17 ) ;
return 0 ;
}
static int F_55 ( struct V_147 * V_14 )
{
struct V_1 * V_2 = F_56 ( V_14 ) ;
unsigned long V_6 = V_7 + V_184 ;
while ( F_6 ( V_7 , V_6 ) ) {
if ( ( ( F_1 ( V_2 , V_10 ) & 0x1 ) == 0x0 ) &&
( F_1 ( V_2 , V_54 ) &
V_41 ) ) {
F_57 () ;
return 0 ;
}
}
F_8 ( V_2 -> V_14 , L_17 ) ;
return - V_185 ;
}
static int F_58 ( struct V_147 * V_14 )
{
int V_186 ;
struct V_1 * V_2 = F_56 ( V_14 ) ;
struct V_18 * V_19 = & V_2 -> V_19 ;
for ( V_186 = 0 ; V_186 < V_19 -> V_187 ; V_186 ++ )
F_17 ( V_2 , V_186 ) ;
F_3 ( V_2 , F_33 ( V_139 ,
V_140 , V_141 ) , V_142 ) ;
return 0 ;
}
