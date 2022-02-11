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
goto V_74;
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
V_74:
F_20 ( & V_2 -> V_73 , V_69 ) ;
return V_81 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_82 * V_60 = V_2 -> V_60 ;
T_3 * V_67 ;
T_1 V_61 ;
if ( ! V_2 -> V_60 ) {
F_13 ( & V_2 -> V_3 -> V_70 , L_3 ) ;
return;
}
V_67 = ( T_3 * ) V_60 -> V_83 ;
V_2 -> V_60 = NULL ;
if ( V_60 -> V_69 & V_84 && V_60 -> V_69 & V_85 ) {
V_67 [ 12 ] = 0xff ;
V_61 = F_22 ( V_2 -> V_7 + V_86 ) ;
V_67 [ 13 ] = V_61 & 0xff ;
V_67 [ 14 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_87 ) ;
V_67 [ 15 ] = V_61 & 0xff ;
V_67 [ 8 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_88 ) ;
V_67 [ 9 ] = V_61 & 0xff ;
V_67 [ 10 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_89 ) ;
V_67 [ 11 ] = V_61 & 0xff ;
V_67 [ 4 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_90 ) ;
V_67 [ 5 ] = V_61 & 0xff ;
V_67 [ 6 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_91 ) ;
V_67 [ 7 ] = V_61 & 0xff ;
V_67 [ 0 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_92 ) ;
V_67 [ 1 ] = V_61 & 0xff ;
V_67 [ 2 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_93 ) ;
V_67 [ 3 ] = V_61 & 0xff ;
} else if ( V_60 -> V_69 & V_84 ) {
V_61 = F_22 ( V_2 -> V_7 + V_86 ) ;
V_67 [ 0 ] = V_61 & 0xff ;
V_67 [ 1 ] = V_61 >> 8 ;
V_61 = F_22 ( V_2 -> V_7 + V_87 ) ;
V_67 [ 2 ] = V_61 & 0xff ;
V_67 [ 3 ] = V_61 >> 8 ;
}
F_16 ( & V_2 -> V_3 -> V_70 , L_4 ,
V_60 -> V_94 , V_60 -> error , V_60 -> V_69 ) ;
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
V_61 -> V_95 = V_61 -> V_96 * V_61 -> V_77 ;
else
V_61 -> V_95 = 0 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_6 ,
V_61 -> V_95 ) ;
F_3 ( 0 , V_2 -> V_7 + V_12 ) ;
F_10 ( V_2 ) ;
}
static T_2 F_24 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
V_19 V_97 , V_98 , V_99 , V_100 ;
int error = 0 , V_101 = V_81 ;
F_25 ( & V_2 -> V_73 ) ;
V_99 = F_26 ( V_2 -> V_7 + V_10 ) ;
V_98 = F_26 ( V_2 -> V_7 + V_27 ) ;
V_97 = V_99 & ~ V_98 & ~ V_102 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_7 ,
V_99 , V_98 ) ;
if ( ! V_97 ) {
V_101 = V_72 ;
goto V_103;
}
if ( V_97 & V_26 ) {
error = - V_104 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_8 ) ;
} else if ( V_97 & V_105 ) {
error = - V_106 ;
F_27 ( & V_2 -> V_3 -> V_70 , L_9 ) ;
} else if ( V_97 & ( V_107
| V_108
| V_109
| V_110
| V_111
| V_112 ) ) {
F_27 ( & V_2 -> V_3 -> V_70 , L_10 ,
V_97 & V_107 ? L_11 : L_12 ,
V_97 & V_108 ? L_13 : L_12 ,
V_97 & V_109 ? L_14 : L_12 ,
V_97 & V_110 ? L_15 : L_12 ,
V_97 & V_111 ? L_16 : L_12 ,
V_97 & V_112 ? L_17 : L_12 ) ;
V_100 = F_26 ( V_2 -> V_7 + V_11 ) ;
F_27 ( & V_2 -> V_3 -> V_70 , L_18 ,
V_100 & V_113 ? L_19 : L_12 ,
V_100 & V_114 ? L_20 : L_12 ,
V_100 & V_115 ? L_20 : L_12 ,
V_100 & V_116 ? L_21 : L_12 ,
V_100 & V_117 ? L_22 : L_12 ,
V_100 & V_118 ? L_23 : L_12 ,
V_100 & V_119 ? L_23 : L_12 ,
V_100 & V_120 ? L_24 : L_12 ,
V_100 & V_121 ? L_25 : L_12 ,
V_100 & V_122 ? L_26 : L_12 ,
V_100 & V_123 ? L_27 : L_12 ,
V_100 & V_124 ? L_28 : L_12 ,
V_100 & V_125 ? L_29 : L_12 ) ;
error = - V_71 ;
}
if ( error ) {
if ( V_2 -> V_60 )
V_2 -> V_60 -> error = error ;
if ( error == - V_104 ) {
F_5 ( V_99 &
~ ( V_26 | V_20 ) ,
V_2 -> V_7 + V_10 ) ;
} else {
F_1 ( V_2 ) ;
F_6 ( V_2 -> V_30 , & V_2 -> V_30 -> V_32 ) ;
goto V_103;
}
}
if ( V_97 & ( V_23 | V_22 ) ) {
F_5 ( V_99 &
~ ( V_22 | V_23 ) ,
V_2 -> V_7 + V_10 ) ;
if ( V_97 & V_23 )
F_1 ( V_2 ) ;
F_28 ( V_2 -> V_30 , 1 ) ;
}
if ( V_97 & ( V_24 | V_25 ) ) {
F_5 ( V_99 &
~ ( V_25 | V_24 ) ,
V_2 -> V_7 + V_10 ) ;
V_101 = V_126 ;
goto V_103;
}
if ( V_97 & V_20 ) {
F_5 ( V_99 & ~ ( V_20 ) ,
V_2 -> V_7 + V_10 ) ;
F_21 ( V_2 ) ;
}
if ( V_97 & V_21 ) {
F_5 ( V_99 & ~ ( V_21 ) ,
V_2 -> V_7 + V_10 ) ;
F_23 ( V_2 ) ;
}
V_103:
F_29 ( & V_2 -> V_73 ) ;
return V_101 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_82 * V_60 )
{
struct V_64 * V_61 = V_2 -> V_61 ;
int V_127 = V_60 -> V_94 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_30 , V_60 -> V_94 ) ;
if ( V_60 -> V_94 == V_128 ) {
F_3 ( V_129 ,
V_2 -> V_7 + V_12 ) ;
V_60 -> V_83 [ 0 ] = V_60 -> V_94 ;
V_60 -> V_83 [ 1 ] = 0 ;
V_60 -> V_83 [ 2 ] = 0 ;
V_60 -> V_83 [ 3 ] = 0 ;
F_10 ( V_2 ) ;
return;
}
switch ( F_31 ( V_60 ) ) {
case V_130 :
V_127 |= V_131 ;
break;
case V_132 :
V_127 |= V_133 ;
break;
case V_134 :
V_127 |= V_135 ;
break;
case V_136 :
V_127 |= V_137 ;
break;
case V_138 :
V_127 |= V_139 ;
break;
default:
F_27 ( & V_2 -> V_3 -> V_70 , L_31 ,
F_31 ( V_60 ) ) ;
break;
}
V_2 -> V_60 = V_60 ;
if ( V_60 -> V_94 == V_140 )
V_127 |= V_141 ;
if ( V_60 -> V_94 == V_142 )
V_127 |= ( 3 << 8 ) ;
if ( V_61 ) {
V_127 |= V_143 ;
if ( V_61 -> V_96 > 1 ) {
F_3 ( V_144 ,
V_2 -> V_7 + V_12 ) ;
V_127 |= V_145 ;
}
if ( V_61 -> V_69 & V_78 )
V_127 |= V_146 ;
}
F_5 ( V_60 -> V_147 , V_2 -> V_7 + V_148 ) ;
F_3 ( V_127 , V_2 -> V_7 + V_149 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_64 * V_61 )
{
unsigned int V_69 = V_150 ;
F_16 ( & V_2 -> V_3 -> V_70 , L_32 ,
V_61 -> V_77 , V_61 -> V_96 , V_61 -> V_151 -> V_152 ) ;
V_2 -> V_61 = V_61 ;
if ( V_61 -> V_69 & V_78 )
V_69 |= V_153 ;
else
V_69 |= V_154 ;
F_33 ( & V_2 -> V_66 , V_61 -> V_151 , V_61 -> V_155 , V_69 ) ;
F_3 ( V_61 -> V_96 , V_2 -> V_7 + V_156 ) ;
F_3 ( V_61 -> V_77 , V_2 -> V_7 + V_157 ) ;
}
static void F_34 ( struct V_29 * V_30 , struct V_58 * V_59 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
unsigned long V_69 ;
if ( ! ( F_22 ( V_2 -> V_7 + V_10 ) & V_158 ) ) {
V_59 -> V_60 -> error = - V_159 ;
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
return ! ( F_22 ( V_2 -> V_7 + V_10 ) & V_160 ) ;
}
static int F_38 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_7 ( V_30 ) ;
return ! ! ( F_22 ( V_2 -> V_7 + V_10 ) & V_158 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_5 ( 0xffffffff , V_2 -> V_7 + V_27 ) ;
F_3 ( 0x000 , V_2 -> V_7 + V_13 + V_14 ) ;
F_3 ( 0 , V_2 -> V_7 + V_9 ) ;
F_2 ( V_2 -> V_3 , V_41 , V_42 ) ;
F_2 ( V_2 -> V_3 , V_4 , 0 ) ;
}
static int F_40 ( struct V_161 * V_70 )
{
struct V_162 * V_3 = F_41 ( V_70 ) ;
struct V_1 * V_2 = F_42 ( V_3 ) ;
F_39 ( V_2 ) ;
F_43 ( V_3 ) ;
F_44 ( V_3 , V_163 , 0 ) ;
F_45 ( V_3 ) ;
F_46 ( V_3 , V_163 ) ;
return 0 ;
}
static int F_47 ( struct V_161 * V_70 )
{
struct V_162 * V_3 = F_41 ( V_70 ) ;
struct V_1 * V_2 = F_42 ( V_3 ) ;
int V_101 ;
F_46 ( V_3 , V_164 ) ;
F_48 ( V_3 ) ;
V_101 = F_49 ( V_3 ) ;
if ( V_101 )
return V_101 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_50 ( struct V_162 * V_3 , const struct V_165 * V_166 )
{
int V_101 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
T_4 V_167 ;
V_101 = F_49 ( V_3 ) ;
if ( V_101 )
return V_101 ;
V_30 = F_51 ( sizeof( struct V_1 ) , & V_3 -> V_70 ) ;
if ( ! V_30 ) {
V_101 = - V_168 ;
goto V_169;
}
V_2 = F_7 ( V_30 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_3 = V_3 ;
F_52 ( V_3 , V_2 ) ;
V_101 = F_53 ( V_3 , V_170 ) ;
if ( V_101 )
goto free;
V_2 -> V_7 = F_54 ( V_3 , 0 , 0 ) ;
if ( ! V_2 -> V_7 ) {
V_101 = - V_168 ;
goto V_171;
}
V_30 -> V_172 = & V_173 ;
V_30 -> V_174 = V_175 ;
V_30 -> V_176 = V_177 ;
V_30 -> V_178 = V_34 / 512 ;
V_30 -> V_179 = V_34 ;
F_55 ( & V_2 -> V_73 ) ;
F_1 ( V_2 ) ;
V_101 = F_56 ( V_3 -> V_62 , F_24 , F_12 ,
V_180 , V_170 , V_2 ) ;
if ( V_101 )
goto V_181;
F_57 ( V_30 ) ;
V_167 = F_58 ( V_3 , 0 ) ;
F_16 ( & V_3 -> V_70 , L_33 , & V_167 , V_3 -> V_62 ) ;
F_59 ( & V_3 -> V_70 , 1 ) ;
return 0 ;
V_181:
F_60 ( V_3 , V_2 -> V_7 ) ;
V_171:
F_61 ( V_3 ) ;
free:
F_62 ( V_30 ) ;
F_52 ( V_3 , NULL ) ;
V_169:
F_45 ( V_3 ) ;
return V_101 ;
}
static void F_63 ( struct V_162 * V_3 )
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
