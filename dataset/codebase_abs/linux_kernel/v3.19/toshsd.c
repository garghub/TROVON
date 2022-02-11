static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 ) ;
F_2 ( V_2 -> V_3 , V_6 , 2 ) ;
F_3 ( 0 , V_2 -> V_7 + V_8 ) ;
F_4 ( 2 ) ;
F_3 ( 1 , V_2 -> V_7 + V_8 ) ;
F_4 ( 2 ) ;
F_3 ( 0 , V_2 -> V_7 + V_9 ) ;
F_5 ( 0 , V_2 -> V_7 + V_10 ) ;
F_5 ( 0 , V_2 -> V_7 + V_11 ) ;
F_3 ( 0 , V_2 -> V_7 + V_12 ) ;
F_3 ( 0x100 , V_2 -> V_7 + V_13 + V_14 ) ;
F_2 ( V_2 -> V_3 , V_15 ,
V_16 ) ;
F_2 ( V_2 -> V_3 , V_17 ,
V_18 ) ;
F_5 ( ~ ( V_19 ) ( V_20 | V_21
| V_22 | V_23
| V_24 | V_25
| V_26 ) ,
V_2 -> V_7 + V_27 ) ;
F_3 ( 0x1000 , V_2 -> V_7 + V_28 ) ;
}
static void F_6 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
if ( V_32 -> clock ) {
T_1 V_33 ;
int div = 1 ;
while ( V_32 -> clock < V_34 / div )
div *= 2 ;
V_33 = div >> 2 ;
if ( div == 1 ) {
F_2 ( V_2 -> V_3 , V_35 ,
V_36 ) ;
V_33 |= V_37 ;
} else
F_2 ( V_2 -> V_3 , V_35 , 0 ) ;
V_33 |= V_38 ;
F_3 ( V_33 , V_2 -> V_7 + V_9 ) ;
F_4 ( 10 ) ;
} else
F_3 ( 0 , V_2 -> V_7 + V_9 ) ;
switch ( V_32 -> V_39 ) {
case V_40 :
F_2 ( V_2 -> V_3 , V_41 ,
V_42 ) ;
F_4 ( 1 ) ;
break;
case V_43 :
break;
case V_44 :
F_2 ( V_2 -> V_3 , V_41 ,
V_45 ) ;
F_2 ( V_2 -> V_3 , V_46 ,
V_47 ) ;
F_4 ( 20 ) ;
break;
}
switch ( V_32 -> V_48 ) {
case V_49 :
F_3 ( V_50 | F_8 ( 14 )
| V_51
| V_52 ,
V_2 -> V_7 + V_53 ) ;
break;
case V_54 :
F_3 ( V_50 | F_8 ( 14 )
| V_51
| V_55 ,
V_2 -> V_7 + V_53 ) ;
break;
}
}
static void F_9 ( struct V_1 * V_2 , unsigned char V_56 )
{
F_3 ( V_56 , V_2 -> V_7 + V_13 + V_57 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = V_2 -> V_59 ;
V_2 -> V_59 = NULL ;
V_2 -> V_60 = NULL ;
V_2 -> V_61 = NULL ;
F_9 ( V_2 , 0 ) ;
F_11 ( V_2 -> V_30 , V_59 ) ;
}
static T_2 F_12 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_64 * V_61 = V_2 -> V_61 ;
struct V_65 * V_66 = & V_2 -> V_66 ;
unsigned short * V_67 ;
int V_68 ;
unsigned long V_69 ;
if ( ! V_61 ) {
F_13 ( & V_2 -> V_3 -> V_70 , L_1 ) ;
if ( V_2 -> V_60 ) {
V_2 -> V_60 -> error = - V_71 ;
F_10 ( V_2 ) ;
}
return V_72 ;
}
F_14 ( & V_2 -> V_73 , V_69 ) ;
if ( ! F_15 ( V_66 ) )
return V_74 ;
V_67 = V_66 -> V_75 ;
V_68 = V_66 -> V_76 ;
if ( V_68 > V_61 -> V_77 )
V_68 = V_61 -> V_77 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_2 , V_68 ,
V_61 -> V_69 ) ;
if ( V_61 -> V_69 & V_78 )
F_17 ( V_2 -> V_7 + V_79 , V_67 , V_68 >> 2 ) ;
else
F_18 ( V_2 -> V_7 + V_79 , V_67 , V_68 >> 2 ) ;
V_66 -> V_80 = V_68 ;
F_19 ( V_66 ) ;
F_20 ( & V_2 -> V_73 , V_69 ) ;
return V_74 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_81 * V_60 = V_2 -> V_60 ;
T_3 * V_67 ;
T_1 V_61 ;
if ( ! V_2 -> V_60 ) {
F_13 ( & V_2 -> V_3 -> V_70 , L_3 ) ;
return;
}
V_67 = ( T_3 * ) V_60 -> V_82 ;
V_2 -> V_60 = NULL ;
if ( V_60 -> V_69 & V_83 && V_60 -> V_69 & V_84 ) {
V_67 [ 12 ] = 0xff ;
V_61 = F_22 ( V_2 -> V_7 + V_85 ) ;
V_67 [ 13 ] = V_61 & 0xff ;
V_67 [ 14 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_86 ) ;
V_67 [ 15 ] = V_61 & 0xff ;
V_67 [ 8 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_87 ) ;
V_67 [ 9 ] = V_61 & 0xff ;
V_67 [ 10 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_88 ) ;
V_67 [ 11 ] = V_61 & 0xff ;
V_67 [ 4 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_89 ) ;
V_67 [ 5 ] = V_61 & 0xff ;
V_67 [ 6 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_90 ) ;
V_67 [ 7 ] = V_61 & 0xff ;
V_67 [ 0 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_91 ) ;
V_67 [ 1 ] = V_61 & 0xff ;
V_67 [ 2 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_92 ) ;
V_67 [ 3 ] = V_61 & 0xff ;
} else if ( V_60 -> V_69 & V_83 ) {
V_61 = F_22 ( V_2 -> V_7 + V_85 ) ;
V_67 [ 0 ] = V_61 & 0xff ;
V_67 [ 1 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_86 ) ;
V_67 [ 2 ] = V_61 & 0xff ;
V_67 [ 3 ] = V_61 >> 8 ;
}
F_16 ( & V_2 -> V_3 -> V_70 , L_4 ,
V_60 -> V_93 , V_60 -> error , V_60 -> V_69 ) ;
if ( V_2 -> V_61 )
return;
F_10 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_64 * V_61 = V_2 -> V_61 ;
V_2 -> V_61 = NULL ;
if ( ! V_61 ) {
F_13 ( & V_2 -> V_3 -> V_70 , L_5 ) ;
return;
}
if ( V_61 -> error == 0 )
V_61 -> V_94 = V_61 -> V_95 * V_61 -> V_77 ;
else
V_61 -> V_94 = 0 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_6 ,
V_61 -> V_94 ) ;
F_3 ( 0 , V_2 -> V_7 + V_12 ) ;
F_10 ( V_2 ) ;
}
static T_2 F_24 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
V_19 V_96 , V_97 , V_98 , V_99 ;
int error = 0 , V_100 = V_74 ;
F_25 ( & V_2 -> V_73 ) ;
V_98 = F_26 ( V_2 -> V_7 + V_10 ) ;
V_97 = F_26 ( V_2 -> V_7 + V_27 ) ;
V_96 = V_98 & ~ V_97 & ~ V_101 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_7 ,
V_98 , V_97 ) ;
if ( ! V_96 ) {
V_100 = V_72 ;
goto V_102;
}
if ( V_96 & V_26 ) {
error = - V_103 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_8 ) ;
} else if ( V_96 & V_104 ) {
error = - V_105 ;
F_27 ( & V_2 -> V_3 -> V_70 , L_9 ) ;
} else if ( V_96 & ( V_106
| V_107
| V_108
| V_109
| V_110
| V_111 ) ) {
F_27 ( & V_2 -> V_3 -> V_70 , L_10 ,
V_96 & V_106 ? L_11 : L_12 ,
V_96 & V_107 ? L_13 : L_12 ,
V_96 & V_108 ? L_14 : L_12 ,
V_96 & V_109 ? L_15 : L_12 ,
V_96 & V_110 ? L_16 : L_12 ,
V_96 & V_111 ? L_17 : L_12 ) ;
V_99 = F_26 ( V_2 -> V_7 + V_11 ) ;
F_27 ( & V_2 -> V_3 -> V_70 , L_18 ,
V_99 & V_112 ? L_19 : L_12 ,
V_99 & V_113 ? L_20 : L_12 ,
V_99 & V_114 ? L_20 : L_12 ,
V_99 & V_115 ? L_21 : L_12 ,
V_99 & V_116 ? L_22 : L_12 ,
V_99 & V_117 ? L_23 : L_12 ,
V_99 & V_118 ? L_23 : L_12 ,
V_99 & V_119 ? L_24 : L_12 ,
V_99 & V_120 ? L_25 : L_12 ,
V_99 & V_121 ? L_26 : L_12 ,
V_99 & V_122 ? L_27 : L_12 ,
V_99 & V_123 ? L_28 : L_12 ,
V_99 & V_124 ? L_29 : L_12 ) ;
error = - V_71 ;
}
if ( error ) {
if ( V_2 -> V_60 )
V_2 -> V_60 -> error = error ;
if ( error == - V_103 ) {
F_5 ( V_98 &
~ ( V_26 | V_20 ) ,
V_2 -> V_7 + V_10 ) ;
} else {
F_1 ( V_2 ) ;
F_6 ( V_2 -> V_30 , & V_2 -> V_30 -> V_32 ) ;
goto V_102;
}
}
if ( V_96 & ( V_23 | V_22 ) ) {
F_5 ( V_98 &
~ ( V_22 | V_23 ) ,
V_2 -> V_7 + V_10 ) ;
if ( V_96 & V_23 )
F_1 ( V_2 ) ;
F_28 ( V_2 -> V_30 , 1 ) ;
}
if ( V_96 & ( V_24 | V_25 ) ) {
F_5 ( V_98 &
~ ( V_25 | V_24 ) ,
V_2 -> V_7 + V_10 ) ;
V_100 = V_125 ;
goto V_102;
}
if ( V_96 & V_20 ) {
F_5 ( V_98 & ~ ( V_20 ) ,
V_2 -> V_7 + V_10 ) ;
F_21 ( V_2 ) ;
}
if ( V_96 & V_21 ) {
F_5 ( V_98 & ~ ( V_21 ) ,
V_2 -> V_7 + V_10 ) ;
F_23 ( V_2 ) ;
}
V_102:
F_29 ( & V_2 -> V_73 ) ;
return V_100 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_81 * V_60 )
{
struct V_64 * V_61 = V_2 -> V_61 ;
int V_126 = V_60 -> V_93 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_30 , V_60 -> V_93 ) ;
if ( V_60 -> V_93 == V_127 ) {
F_3 ( V_128 ,
V_2 -> V_7 + V_12 ) ;
V_60 -> V_82 [ 0 ] = V_60 -> V_93 ;
V_60 -> V_82 [ 1 ] = 0 ;
V_60 -> V_82 [ 2 ] = 0 ;
V_60 -> V_82 [ 3 ] = 0 ;
F_10 ( V_2 ) ;
return;
}
switch ( F_31 ( V_60 ) ) {
case V_129 :
V_126 |= V_130 ;
break;
case V_131 :
V_126 |= V_132 ;
break;
case V_133 :
V_126 |= V_134 ;
break;
case V_135 :
V_126 |= V_136 ;
break;
case V_137 :
V_126 |= V_138 ;
break;
default:
F_27 ( & V_2 -> V_3 -> V_70 , L_31 ,
F_31 ( V_60 ) ) ;
break;
}
V_2 -> V_60 = V_60 ;
if ( V_60 -> V_93 == V_139 )
V_126 |= V_140 ;
if ( V_60 -> V_93 == V_141 )
V_126 |= ( 3 << 8 ) ;
if ( V_61 ) {
V_126 |= V_142 ;
if ( V_61 -> V_95 > 1 ) {
F_3 ( V_143 ,
V_2 -> V_7 + V_12 ) ;
V_126 |= V_144 ;
}
if ( V_61 -> V_69 & V_78 )
V_126 |= V_145 ;
}
F_5 ( V_60 -> V_146 , V_2 -> V_7 + V_147 ) ;
F_3 ( V_126 , V_2 -> V_7 + V_148 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_64 * V_61 )
{
unsigned int V_69 = V_149 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_32 ,
V_61 -> V_77 , V_61 -> V_95 , V_61 -> V_150 -> V_151 ) ;
V_2 -> V_61 = V_61 ;
if ( V_61 -> V_69 & V_78 )
V_69 |= V_152 ;
else
V_69 |= V_153 ;
F_33 ( & V_2 -> V_66 , V_61 -> V_150 , V_61 -> V_154 , V_69 ) ;
F_3 ( V_61 -> V_95 , V_2 -> V_7 + V_155 ) ;
F_3 ( V_61 -> V_77 , V_2 -> V_7 + V_156 ) ;
}
static void F_34 ( struct V_29 * V_30 , struct V_58 * V_59 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
unsigned long V_69 ;
if ( ! ( F_22 ( V_2 -> V_7 + V_10 ) & V_157 ) ) {
V_59 -> V_60 -> error = - V_158 ;
F_11 ( V_30 , V_59 ) ;
return;
}
F_14 ( & V_2 -> V_73 , V_69 ) ;
F_35 ( V_2 -> V_59 != NULL ) ;
V_2 -> V_59 = V_59 ;
if ( V_59 -> V_61 )
F_32 ( V_2 , V_59 -> V_61 ) ;
F_9 ( V_2 , 1 ) ;
F_30 ( V_2 , V_59 -> V_60 ) ;
F_20 ( & V_2 -> V_73 , V_69 ) ;
}
static void F_36 ( struct V_29 * V_30 , struct V_31 * V_32 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
unsigned long V_69 ;
F_14 ( & V_2 -> V_73 , V_69 ) ;
F_6 ( V_30 , V_32 ) ;
F_20 ( & V_2 -> V_73 , V_69 ) ;
}
static int F_37 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
return ! ( F_22 ( V_2 -> V_7 + V_10 ) & V_159 ) ;
}
static int F_38 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
return ! ! ( F_22 ( V_2 -> V_7 + V_10 ) & V_157 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_5 ( 0xffffffff , V_2 -> V_7 + V_27 ) ;
F_3 ( 0x000 , V_2 -> V_7 + V_13 + V_14 ) ;
F_3 ( 0 , V_2 -> V_7 + V_9 ) ;
F_2 ( V_2 -> V_3 , V_41 , V_42 ) ;
F_2 ( V_2 -> V_3 , V_4 , 0 ) ;
}
static int F_40 ( struct V_160 * V_70 )
{
struct V_161 * V_3 = F_41 ( V_70 ) ;
struct V_1 * V_2 = F_42 ( V_3 ) ;
F_39 ( V_2 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 , V_162 , 0 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 , V_162 ) ;
return 0 ;
}
static int F_47 ( struct V_160 * V_70 )
{
struct V_161 * V_3 = F_41 ( V_70 ) ;
struct V_1 * V_2 = F_42 ( V_3 ) ;
int V_100 ;
F_46 ( V_3 , V_163 ) ;
F_48 ( V_3 ) ;
V_100 = F_49 ( V_3 ) ;
if ( V_100 )
return V_100 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_161 * V_3 , const struct V_164 * V_165 )
{
int V_100 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
T_4 V_166 ;
V_100 = F_49 ( V_3 ) ;
if ( V_100 )
return V_100 ;
V_30 = F_51 ( sizeof( struct V_1 ) , & V_3 -> V_70 ) ;
if ( ! V_30 ) {
V_100 = - V_167 ;
goto V_168;
}
V_2 = F_7 ( V_30 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_3 = V_3 ;
F_52 ( V_3 , V_2 ) ;
V_100 = F_53 ( V_3 , V_169 ) ;
if ( V_100 )
goto free;
V_2 -> V_7 = F_54 ( V_3 , 0 , 0 ) ;
if ( ! V_2 -> V_7 ) {
V_100 = - V_167 ;
goto V_170;
}
V_30 -> V_171 = & V_172 ;
V_30 -> V_173 = V_174 ;
V_30 -> V_175 = V_176 ;
V_30 -> V_177 = V_34 / 512 ;
V_30 -> V_178 = V_34 ;
F_55 ( & V_2 -> V_73 ) ;
F_1 ( V_2 ) ;
V_100 = F_56 ( V_3 -> V_62 , F_24 , F_12 ,
V_179 , V_169 , V_2 ) ;
if ( V_100 )
goto V_180;
F_57 ( V_30 ) ;
V_166 = F_58 ( V_3 , 0 ) ;
F_16 ( & V_3 -> V_70 , L_33 , & V_166 , V_3 -> V_62 ) ;
F_59 ( & V_3 -> V_70 , 1 ) ;
return 0 ;
V_180:
F_60 ( V_3 , V_2 -> V_7 ) ;
V_170:
F_61 ( V_3 ) ;
free:
F_62 ( V_30 ) ;
F_52 ( V_3 , NULL ) ;
V_168:
F_45 ( V_3 ) ;
return V_100 ;
}
static void F_63 ( struct V_161 * V_3 )
{
struct V_1 * V_2 = F_42 ( V_3 ) ;
F_64 ( V_2 -> V_30 ) ;
F_39 ( V_2 ) ;
F_65 ( V_3 -> V_62 , V_2 ) ;
F_60 ( V_3 , V_2 -> V_7 ) ;
F_61 ( V_3 ) ;
F_62 ( V_2 -> V_30 ) ;
F_52 ( V_3 , NULL ) ;
F_45 ( V_3 ) ;
}
static int T_5 F_66 ( void )
{
return F_67 ( & V_181 ) ;
}
static void T_6 F_68 ( void )
{
F_69 ( & V_181 ) ;
}
