static T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_7 ;
T_3 V_8 , V_9 ;
V_8 = F_3 ( V_10 ) ;
V_9 = F_3 ( V_11 ) ;
V_7 = ( ( T_2 ) V_9 ) << 32 ;
V_7 |= V_8 ;
return V_7 ;
}
static T_1 F_4 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_3 V_8 , V_9 ;
T_2 V_7 ;
F_3 ( V_12 ) ;
V_8 = F_3 ( V_10 ) ;
V_9 = F_3 ( V_11 ) ;
V_7 = ( ( T_2 ) V_9 ) << 32 ;
V_7 |= V_8 ;
return V_7 ;
}
static void F_5 ( struct V_3 * V_13 , struct V_14 * V_15 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_16 , V_17 ;
F_3 ( V_12 ) ;
V_17 = F_3 ( V_10 ) ;
V_16 = F_3 ( V_11 ) ;
V_15 -> V_18 = V_16 ;
V_15 -> V_19 = V_17 ;
}
static void F_6 ( struct V_3 * V_13 ,
const struct V_14 * V_15 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
F_7 ( V_10 , V_15 -> V_19 ) ;
F_7 ( V_11 , V_15 -> V_18 ) ;
}
static void F_8 ( struct V_3 * V_13 ,
struct V_20 * V_21 ,
T_2 V_22 )
{
unsigned long V_23 ;
T_2 V_24 ;
switch ( V_13 -> V_6 . V_25 . type ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
F_9 ( & V_13 -> V_30 , V_23 ) ;
V_24 = F_10 ( & V_13 -> V_31 , V_22 ) ;
F_11 ( & V_13 -> V_30 , V_23 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_32 = F_12 ( V_24 ) ;
break;
case V_33 :
case V_34 :
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_32 = F_13 ( V_22 >> 32 ,
V_22 & 0xFFFFFFFF ) ;
break;
default:
break;
}
}
static int F_14 ( struct V_35 * V_36 , T_4 V_37 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_39 = 0 ;
T_2 V_40 ;
T_3 V_41 ;
if ( V_37 < 0 ) {
V_39 = 1 ;
V_37 = - V_37 ;
}
V_40 = V_37 ;
V_40 <<= 14 ;
V_40 = F_15 ( V_40 , 1953125 ) ;
V_41 = 16 << V_42 ;
if ( V_39 )
V_41 -= V_40 ;
else
V_41 += V_40 ;
F_7 ( V_43 , V_44 | ( V_41 & V_45 ) ) ;
return 0 ;
}
static int F_16 ( struct V_35 * V_36 , T_4 V_37 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_39 = 0 ;
T_2 V_40 ;
T_3 V_46 ;
if ( V_37 < 0 ) {
V_39 = 1 ;
V_37 = - V_37 ;
}
V_40 = V_37 ;
V_40 <<= 26 ;
V_40 = F_15 ( V_40 , 1953125 ) ;
V_46 = V_40 & V_47 ;
if ( V_39 )
V_46 |= V_48 ;
F_7 ( V_43 , V_46 ) ;
return 0 ;
}
static int F_17 ( struct V_35 * V_36 , T_5 V_49 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
T_5 V_50 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_50 = F_18 ( & V_4 -> V_31 ) ;
V_50 += V_49 ;
F_19 ( & V_4 -> V_31 , & V_4 -> V_2 , V_50 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_20 ( struct V_35 * V_36 , T_5 V_49 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
struct V_14 V_50 , V_51 = F_21 ( V_49 ) ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_5 ( V_4 , & V_50 ) ;
V_50 = F_22 ( V_50 , V_51 ) ;
F_6 ( V_4 , ( const struct V_14 * ) & V_50 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
T_2 V_24 ;
T_3 V_52 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_24 = F_18 ( & V_4 -> V_31 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
V_15 -> V_18 = F_24 ( V_24 , 1000000000 , & V_52 ) ;
V_15 -> V_19 = V_52 ;
return 0 ;
}
static int F_25 ( struct V_35 * V_36 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_5 ( V_4 , V_15 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_26 ( struct V_35 * V_36 ,
const struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
T_2 V_24 ;
V_24 = V_15 -> V_18 * 1000000000ULL ;
V_24 += V_15 -> V_19 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_19 ( & V_4 -> V_31 , & V_4 -> V_2 , V_24 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_36 ,
const struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_6 ( V_4 , V_15 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_28 ( struct V_35 * V_36 ,
struct V_53 * V_54 , int V_55 )
{
return - V_56 ;
}
static void F_29 ( struct V_57 * V_58 )
{
struct V_3 * V_13 = F_2 ( V_58 , struct V_3 ,
V_59 ) ;
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_60 ;
if ( ! V_13 -> V_61 )
return;
if ( F_30 ( V_13 -> V_62 +
V_63 ) ) {
F_31 ( V_13 -> V_61 ) ;
V_13 -> V_61 = NULL ;
F_32 ( V_64 , & V_13 -> V_65 ) ;
V_13 -> V_66 ++ ;
F_33 ( & V_13 -> V_67 -> V_68 , L_1 ) ;
return;
}
V_60 = F_3 ( V_69 ) ;
if ( V_60 & V_70 )
F_34 ( V_13 ) ;
else
F_35 ( & V_13 -> V_59 ) ;
}
static void F_36 ( struct V_57 * V_58 )
{
struct V_3 * V_4 =
F_2 ( V_58 , struct V_3 , V_71 . V_58 ) ;
struct V_14 V_15 ;
V_4 -> V_38 . V_72 ( & V_4 -> V_38 , & V_15 ) ;
F_37 ( L_2 , V_15 . V_18 , V_15 . V_19 ) ;
F_38 ( & V_4 -> V_71 ,
V_73 ) ;
}
void F_39 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_74 = F_3 ( V_75 ) ;
unsigned long V_76 ;
if ( V_6 -> V_25 . type != V_26 )
return;
if ( ! ( V_74 & V_77 ) ) {
V_13 -> V_78 = V_79 ;
return;
}
V_76 = V_13 -> V_78 ;
if ( F_40 ( V_13 -> V_80 , V_76 ) )
V_76 = V_13 -> V_80 ;
if ( F_30 ( V_76 + 5 * V_81 ) ) {
F_3 ( V_82 ) ;
V_13 -> V_78 = V_79 ;
V_13 -> V_83 ++ ;
F_33 ( & V_13 -> V_67 -> V_68 , L_3 ) ;
}
}
static void F_34 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_20 V_84 ;
T_2 V_85 ;
V_85 = F_3 ( V_86 ) ;
V_85 |= ( T_2 ) F_3 ( V_87 ) << 32 ;
F_8 ( V_13 , & V_84 , V_85 ) ;
F_41 ( V_13 -> V_61 , & V_84 ) ;
F_31 ( V_13 -> V_61 ) ;
V_13 -> V_61 = NULL ;
F_32 ( V_64 , & V_13 -> V_65 ) ;
}
void F_42 ( struct V_88 * V_89 ,
unsigned char * V_90 ,
struct V_91 * V_92 )
{
T_6 * V_85 = ( T_6 * ) V_90 ;
F_8 ( V_89 -> V_13 , F_43 ( V_92 ) ,
F_44 ( V_85 [ 1 ] ) ) ;
}
void F_45 ( struct V_88 * V_89 ,
struct V_91 * V_92 )
{
struct V_3 * V_13 = V_89 -> V_13 ;
struct V_5 * V_6 = & V_13 -> V_6 ;
T_2 V_85 ;
if ( ! ( F_3 ( V_75 ) & V_77 ) )
return;
V_85 = F_3 ( V_93 ) ;
V_85 |= ( T_2 ) F_3 ( V_82 ) << 32 ;
F_8 ( V_13 , F_43 ( V_92 ) , V_85 ) ;
V_13 -> V_80 = V_79 ;
}
int F_46 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_3 * V_13 = F_47 ( V_95 ) ;
struct V_98 * V_99 = & V_13 -> V_100 ;
return F_48 ( V_97 -> V_101 , V_99 , sizeof( * V_99 ) ) ?
- V_102 : 0 ;
}
static int F_49 ( struct V_3 * V_13 ,
struct V_98 * V_99 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_103 = V_104 ;
T_3 V_105 = V_106 ;
T_3 V_107 = 0 ;
bool V_108 = false ;
bool V_109 = false ;
T_3 V_85 ;
if ( V_99 -> V_23 )
return - V_110 ;
switch ( V_99 -> V_111 ) {
case V_112 :
V_103 = 0 ;
case V_113 :
break;
default:
return - V_114 ;
}
switch ( V_99 -> V_115 ) {
case V_116 :
V_105 = 0 ;
break;
case V_117 :
V_105 |= V_118 ;
V_107 = V_119 ;
V_108 = true ;
break;
case V_120 :
V_105 |= V_118 ;
V_107 = V_121 ;
V_108 = true ;
break;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_105 |= V_131 ;
V_99 -> V_115 = V_122 ;
V_109 = true ;
V_108 = true ;
break;
case V_132 :
case V_133 :
if ( V_6 -> V_25 . type != V_26 ) {
V_105 |= V_134 ;
V_99 -> V_115 = V_133 ;
break;
}
default:
V_99 -> V_115 = V_116 ;
return - V_114 ;
}
if ( V_6 -> V_25 . type == V_135 ) {
if ( V_105 | V_103 )
return - V_110 ;
return 0 ;
}
if ( ( V_6 -> V_25 . type >= V_27 ) && V_105 ) {
V_105 = V_106 ;
V_105 |= V_134 ;
V_99 -> V_115 = V_133 ;
V_109 = true ;
V_108 = true ;
if ( ( V_6 -> V_25 . type == V_33 ) ||
( V_6 -> V_25 . type == V_34 ) ) {
V_85 = F_3 ( V_136 ) ;
V_85 |= V_137 ;
F_7 ( V_136 , V_85 ) ;
}
}
V_85 = F_3 ( V_69 ) ;
V_85 &= ~ V_104 ;
V_85 |= V_103 ;
F_7 ( V_69 , V_85 ) ;
V_85 = F_3 ( V_75 ) ;
V_85 &= ~ ( V_106 | V_138 ) ;
V_85 |= V_105 ;
F_7 ( V_75 , V_85 ) ;
F_7 ( V_139 , V_107 ) ;
if ( V_109 )
F_7 ( F_50 ( 3 ) ,
( V_140 |
V_141 |
V_142 ) ) ;
else
F_7 ( F_50 ( 3 ) , 0 ) ;
if ( V_108 ) {
T_3 V_143 = ( V_144
| V_145
| V_146
| V_147 ) ;
V_143 &= ~ V_148 ;
F_7 ( F_51 ( 3 ) , F_52 ( V_149 ) ) ;
F_7 ( F_53 ( 3 ) ,
( V_150 | V_151 ) ) ;
if ( V_6 -> V_25 . type == V_26 ) {
F_7 ( F_54 ( 3 ) , F_52 ( V_149 ) ) ;
V_143 &= ~ V_152 ;
}
F_7 ( F_55 ( 3 ) , V_143 ) ;
} else {
F_7 ( F_55 ( 3 ) , V_147 ) ;
}
F_56 () ;
V_85 = F_3 ( V_86 ) ;
V_85 = F_3 ( V_87 ) ;
V_85 = F_3 ( V_93 ) ;
V_85 = F_3 ( V_82 ) ;
return 0 ;
}
int F_57 ( struct V_94 * V_95 , struct V_96 * V_97 )
{
struct V_3 * V_13 = F_47 ( V_95 ) ;
struct V_98 V_99 ;
int V_153 ;
if ( F_58 ( & V_99 , V_97 -> V_101 , sizeof( V_99 ) ) )
return - V_102 ;
V_153 = F_49 ( V_13 , & V_99 ) ;
if ( V_153 )
return V_153 ;
memcpy ( & V_13 -> V_100 , & V_99 ,
sizeof( V_13 -> V_100 ) ) ;
return F_48 ( V_97 -> V_101 , & V_99 , sizeof( V_99 ) ) ?
- V_102 : 0 ;
}
void F_59 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_94 * V_95 = V_13 -> V_95 ;
switch ( V_6 -> V_25 . type ) {
case V_26 :
snprintf ( V_13 -> V_38 . V_154 , 16 , L_4 , V_95 -> V_155 ) ;
V_13 -> V_38 . V_156 = V_157 ;
V_13 -> V_38 . V_158 = 999999881 ;
V_13 -> V_38 . V_159 = 0 ;
V_13 -> V_38 . V_160 = 0 ;
V_13 -> V_38 . V_161 = F_14 ;
V_13 -> V_38 . V_162 = F_17 ;
V_13 -> V_38 . V_72 = F_23 ;
V_13 -> V_38 . V_163 = F_26 ;
V_13 -> V_38 . V_164 = F_28 ;
V_13 -> V_2 . V_165 = F_1 ;
V_13 -> V_2 . V_166 = F_60 ( 64 ) ;
V_13 -> V_2 . V_167 = 1 ;
V_13 -> V_2 . V_168 = V_42 ;
F_7 ( V_43 , V_44 | V_169 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
snprintf ( V_13 -> V_38 . V_154 , 16 , L_4 , V_95 -> V_155 ) ;
V_13 -> V_38 . V_156 = V_157 ;
V_13 -> V_38 . V_158 = 62499999 ;
V_13 -> V_38 . V_159 = 0 ;
V_13 -> V_38 . V_160 = 0 ;
V_13 -> V_38 . V_161 = F_16 ;
V_13 -> V_38 . V_162 = F_17 ;
V_13 -> V_38 . V_72 = F_23 ;
V_13 -> V_38 . V_163 = F_26 ;
V_13 -> V_38 . V_164 = F_28 ;
V_13 -> V_2 . V_165 = F_4 ;
V_13 -> V_2 . V_166 = F_60 ( V_170 ) ;
V_13 -> V_2 . V_167 = 1 ;
V_13 -> V_2 . V_168 = 0 ;
F_7 ( V_171 , 0x0 ) ;
break;
case V_33 :
case V_34 :
snprintf ( V_13 -> V_38 . V_154 , 16 , L_4 , V_95 -> V_155 ) ;
V_13 -> V_38 . V_156 = V_157 ;
V_13 -> V_38 . V_158 = 62499999 ;
V_13 -> V_38 . V_159 = 0 ;
V_13 -> V_38 . V_160 = 0 ;
V_13 -> V_38 . V_161 = F_16 ;
V_13 -> V_38 . V_162 = F_20 ;
V_13 -> V_38 . V_72 = F_25 ;
V_13 -> V_38 . V_163 = F_27 ;
V_13 -> V_38 . V_164 = F_28 ;
F_7 ( V_171 , 0x0 ) ;
break;
default:
V_13 -> V_172 = NULL ;
return;
}
F_56 () ;
F_61 ( & V_13 -> V_30 ) ;
F_62 ( & V_13 -> V_59 , F_29 ) ;
if ( ( V_6 -> V_25 . type == V_33 ) || ( V_6 -> V_25 . type == V_34 ) ) {
struct V_14 V_15 = F_63 ( F_64 () ) ;
F_27 ( & V_13 -> V_38 , & V_15 ) ;
} else {
F_19 ( & V_13 -> V_31 , & V_13 -> V_2 ,
F_65 ( F_64 () ) ) ;
F_66 ( & V_13 -> V_71 ,
F_36 ) ;
F_38 ( & V_13 -> V_71 ,
V_73 ) ;
}
if ( V_6 -> V_25 . type >= V_27 ) {
F_7 ( V_173 , V_174 ) ;
F_7 ( V_175 , V_176 ) ;
}
V_13 -> V_100 . V_115 = V_116 ;
V_13 -> V_100 . V_111 = V_112 ;
V_13 -> V_172 = F_67 ( & V_13 -> V_38 ,
& V_13 -> V_67 -> V_68 ) ;
if ( F_68 ( V_13 -> V_172 ) ) {
V_13 -> V_172 = NULL ;
F_69 ( & V_13 -> V_67 -> V_68 , L_5 ) ;
} else {
F_70 ( & V_13 -> V_67 -> V_68 , L_6 ,
V_13 -> V_95 -> V_154 ) ;
V_13 -> V_23 |= V_177 ;
}
}
void F_71 ( struct V_3 * V_13 )
{
switch ( V_13 -> V_6 . V_25 . type ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
F_72 ( & V_13 -> V_71 ) ;
break;
case V_33 :
case V_34 :
break;
default:
return;
}
F_73 ( & V_13 -> V_59 ) ;
if ( V_13 -> V_61 ) {
F_31 ( V_13 -> V_61 ) ;
V_13 -> V_61 = NULL ;
F_32 ( V_64 , & V_13 -> V_65 ) ;
}
if ( V_13 -> V_172 ) {
F_74 ( V_13 -> V_172 ) ;
F_70 ( & V_13 -> V_67 -> V_68 , L_7 ,
V_13 -> V_95 -> V_154 ) ;
V_13 -> V_23 &= ~ V_177 ;
}
}
void F_75 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
if ( ! ( V_13 -> V_23 & V_177 ) )
return;
F_49 ( V_13 , & V_13 -> V_100 ) ;
switch ( V_13 -> V_6 . V_25 . type ) {
case V_26 :
F_7 ( V_43 , V_44 | V_169 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_33 :
case V_34 :
F_7 ( V_171 , 0x0 ) ;
F_7 ( V_173 , V_174 ) ;
F_7 ( V_175 , V_176 ) ;
break;
default:
return;
}
if ( ( V_6 -> V_25 . type == V_33 ) || ( V_6 -> V_25 . type == V_34 ) ) {
struct V_14 V_15 = F_63 ( F_64 () ) ;
F_27 ( & V_13 -> V_38 , & V_15 ) ;
} else {
F_19 ( & V_13 -> V_31 , & V_13 -> V_2 ,
F_65 ( F_64 () ) ) ;
}
}
