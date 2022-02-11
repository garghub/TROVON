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
T_2 V_7 ;
T_3 V_8 , V_9 , V_12 ;
V_12 = F_3 ( V_13 ) ;
V_8 = F_3 ( V_10 ) ;
V_9 = F_3 ( V_11 ) ;
V_7 = ( ( T_2 ) V_9 ) << 32 ;
V_7 |= V_8 ;
return V_7 ;
}
static void F_5 ( struct V_3 * V_14 , struct V_15 * V_16 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
T_3 V_17 , V_18 , V_12 ;
V_12 = F_3 ( V_13 ) ;
V_18 = F_3 ( V_10 ) ;
V_17 = F_3 ( V_11 ) ;
V_16 -> V_19 = V_17 ;
V_16 -> V_20 = V_18 ;
}
static void F_6 ( struct V_3 * V_14 ,
const struct V_15 * V_16 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
F_7 ( V_10 , V_16 -> V_20 ) ;
F_7 ( V_11 , V_16 -> V_19 ) ;
}
static void F_8 ( struct V_3 * V_14 ,
struct V_21 * V_22 ,
T_2 V_23 )
{
unsigned long V_24 ;
T_2 V_25 ;
switch ( V_14 -> V_6 . V_26 . type ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
F_9 ( & V_14 -> V_31 , V_24 ) ;
V_25 = F_10 ( & V_14 -> V_32 , V_23 ) ;
F_11 ( & V_14 -> V_31 , V_24 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_33 = F_12 ( V_25 ) ;
break;
case V_34 :
case V_35 :
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_33 = F_13 ( V_23 >> 32 ,
V_23 & 0xFFFFFFFF ) ;
break;
default:
break;
}
}
static int F_14 ( struct V_36 * V_37 , T_4 V_38 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 ,
V_39 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_40 = 0 ;
T_2 V_41 ;
T_3 V_42 ;
if ( V_38 < 0 ) {
V_40 = 1 ;
V_38 = - V_38 ;
}
V_41 = V_38 ;
V_41 <<= 14 ;
V_41 = F_15 ( V_41 , 1953125 ) ;
V_42 = 16 << V_43 ;
if ( V_40 )
V_42 -= V_41 ;
else
V_42 += V_41 ;
F_7 ( V_44 , V_45 | ( V_42 & V_46 ) ) ;
return 0 ;
}
static int F_16 ( struct V_36 * V_37 , T_4 V_38 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 ,
V_39 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_40 = 0 ;
T_2 V_41 ;
T_3 V_47 ;
if ( V_38 < 0 ) {
V_40 = 1 ;
V_38 = - V_38 ;
}
V_41 = V_38 ;
V_41 <<= 26 ;
V_41 = F_15 ( V_41 , 1953125 ) ;
V_47 = V_41 & V_48 ;
if ( V_40 )
V_47 |= V_49 ;
F_7 ( V_44 , V_47 ) ;
return 0 ;
}
static int F_17 ( struct V_36 * V_37 , T_5 V_50 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 ,
V_39 ) ;
unsigned long V_24 ;
T_5 V_51 ;
F_9 ( & V_4 -> V_31 , V_24 ) ;
V_51 = F_18 ( & V_4 -> V_32 ) ;
V_51 += V_50 ;
F_19 ( & V_4 -> V_32 , & V_4 -> V_2 , V_51 ) ;
F_11 ( & V_4 -> V_31 , V_24 ) ;
return 0 ;
}
static int F_20 ( struct V_36 * V_37 , T_5 V_50 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 ,
V_39 ) ;
unsigned long V_24 ;
struct V_15 V_51 , V_52 = F_21 ( V_50 ) ;
F_9 ( & V_4 -> V_31 , V_24 ) ;
F_5 ( V_4 , & V_51 ) ;
V_51 = F_22 ( V_51 , V_52 ) ;
F_6 ( V_4 , ( const struct V_15 * ) & V_51 ) ;
F_11 ( & V_4 -> V_31 , V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_37 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 ,
V_39 ) ;
unsigned long V_24 ;
T_2 V_25 ;
T_3 V_53 ;
F_9 ( & V_4 -> V_31 , V_24 ) ;
V_25 = F_18 ( & V_4 -> V_32 ) ;
F_11 ( & V_4 -> V_31 , V_24 ) ;
V_16 -> V_19 = F_24 ( V_25 , 1000000000 , & V_53 ) ;
V_16 -> V_20 = V_53 ;
return 0 ;
}
static int F_25 ( struct V_36 * V_37 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 ,
V_39 ) ;
unsigned long V_24 ;
F_9 ( & V_4 -> V_31 , V_24 ) ;
F_5 ( V_4 , V_16 ) ;
F_11 ( & V_4 -> V_31 , V_24 ) ;
return 0 ;
}
static int F_26 ( struct V_36 * V_37 ,
const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 ,
V_39 ) ;
unsigned long V_24 ;
T_2 V_25 ;
V_25 = V_16 -> V_19 * 1000000000ULL ;
V_25 += V_16 -> V_20 ;
F_9 ( & V_4 -> V_31 , V_24 ) ;
F_19 ( & V_4 -> V_32 , & V_4 -> V_2 , V_25 ) ;
F_11 ( & V_4 -> V_31 , V_24 ) ;
return 0 ;
}
static int F_27 ( struct V_36 * V_37 ,
const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_37 , struct V_3 ,
V_39 ) ;
unsigned long V_24 ;
F_9 ( & V_4 -> V_31 , V_24 ) ;
F_6 ( V_4 , V_16 ) ;
F_11 ( & V_4 -> V_31 , V_24 ) ;
return 0 ;
}
static int F_28 ( struct V_36 * V_37 ,
struct V_54 * V_55 , int V_56 )
{
return - V_57 ;
}
void F_29 ( struct V_58 * V_59 )
{
struct V_3 * V_14 = F_2 ( V_59 , struct V_3 ,
V_60 ) ;
struct V_5 * V_6 = & V_14 -> V_6 ;
T_3 V_61 ;
if ( ! V_14 -> V_62 )
return;
if ( F_30 ( V_14 -> V_63 +
V_64 ) ) {
F_31 ( V_14 -> V_62 ) ;
V_14 -> V_62 = NULL ;
V_14 -> V_65 ++ ;
F_32 ( & V_14 -> V_66 -> V_67 , L_1 ) ;
return;
}
V_61 = F_3 ( V_68 ) ;
if ( V_61 & V_69 )
F_33 ( V_14 ) ;
else
F_34 ( & V_14 -> V_60 ) ;
}
static void F_35 ( struct V_58 * V_59 )
{
struct V_3 * V_4 =
F_2 ( V_59 , struct V_3 , V_70 . V_59 ) ;
struct V_15 V_16 ;
V_4 -> V_39 . V_71 ( & V_4 -> V_39 , & V_16 ) ;
F_36 ( L_2 , V_16 . V_19 , V_16 . V_20 ) ;
F_37 ( & V_4 -> V_70 ,
V_72 ) ;
}
void F_38 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_73 * V_74 ;
T_3 V_75 = F_3 ( V_76 ) ;
unsigned long V_77 ;
int V_78 ;
if ( V_6 -> V_26 . type != V_27 )
return;
if ( ! ( V_75 & V_79 ) ) {
V_14 -> V_80 = V_81 ;
return;
}
V_77 = V_14 -> V_80 ;
for ( V_78 = 0 ; V_78 < V_14 -> V_82 ; V_78 ++ ) {
V_74 = V_14 -> V_74 [ V_78 ] ;
if ( F_39 ( V_74 -> V_83 , V_77 ) )
V_77 = V_74 -> V_83 ;
}
if ( F_30 ( V_77 + 5 * V_84 ) ) {
F_3 ( V_85 ) ;
V_14 -> V_80 = V_81 ;
V_14 -> V_86 ++ ;
F_32 ( & V_14 -> V_66 -> V_67 , L_3 ) ;
}
}
void F_33 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_21 V_87 ;
T_2 V_88 ;
V_88 = F_3 ( V_89 ) ;
V_88 |= ( T_2 ) F_3 ( V_90 ) << 32 ;
F_8 ( V_14 , & V_87 , V_88 ) ;
F_40 ( V_14 -> V_62 , & V_87 ) ;
F_31 ( V_14 -> V_62 ) ;
V_14 -> V_62 = NULL ;
}
void F_41 ( struct V_91 * V_92 ,
unsigned char * V_93 ,
struct V_94 * V_95 )
{
T_6 * V_88 = ( T_6 * ) V_93 ;
F_8 ( V_92 -> V_14 , F_42 ( V_95 ) ,
F_43 ( V_88 [ 1 ] ) ) ;
}
void F_44 ( struct V_91 * V_92 ,
struct V_94 * V_95 )
{
struct V_3 * V_14 = V_92 -> V_14 ;
struct V_5 * V_6 = & V_14 -> V_6 ;
T_2 V_88 ;
if ( ! ( F_3 ( V_76 ) & V_79 ) )
return;
V_88 = F_3 ( V_96 ) ;
V_88 |= ( T_2 ) F_3 ( V_85 ) << 32 ;
F_8 ( V_14 , F_42 ( V_95 ) , V_88 ) ;
}
int F_45 ( struct V_97 * V_98 ,
struct V_99 * V_100 , int V_101 )
{
struct V_3 * V_14 = F_46 ( V_98 ) ;
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_102 V_103 ;
T_3 V_104 = V_105 ;
T_3 V_106 = V_107 ;
T_3 V_108 = 0 ;
bool V_109 = false ;
bool V_110 = false ;
T_3 V_88 ;
if ( F_47 ( & V_103 , V_100 -> V_111 , sizeof( V_103 ) ) )
return - V_112 ;
if ( V_103 . V_24 )
return - V_113 ;
switch ( V_103 . V_114 ) {
case V_115 :
V_104 = 0 ;
case V_116 :
break;
default:
return - V_117 ;
}
switch ( V_103 . V_118 ) {
case V_119 :
V_106 = 0 ;
break;
case V_120 :
V_106 |= V_121 ;
V_108 = V_122 ;
V_109 = true ;
break;
case V_123 :
V_106 |= V_121 ;
V_108 = V_124 ;
V_109 = true ;
break;
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
V_106 |= V_134 ;
V_103 . V_118 = V_125 ;
V_110 = true ;
V_109 = true ;
break;
case V_135 :
case V_136 :
if ( V_6 -> V_26 . type != V_27 ) {
V_106 |= V_137 ;
V_103 . V_118 = V_136 ;
break;
}
default:
V_103 . V_118 = V_119 ;
return - V_117 ;
}
if ( V_6 -> V_26 . type == V_138 ) {
if ( V_106 | V_104 )
return - V_113 ;
return 0 ;
}
if ( ( V_6 -> V_26 . type >= V_28 ) && V_106 ) {
V_106 = V_107 ;
V_106 |= V_137 ;
V_103 . V_118 = V_136 ;
V_110 = true ;
V_109 = true ;
if ( ( V_6 -> V_26 . type == V_34 ) ||
( V_6 -> V_26 . type == V_35 ) ) {
V_88 = F_3 ( V_139 ) ;
V_88 |= V_140 ;
F_7 ( V_139 , V_88 ) ;
}
}
V_88 = F_3 ( V_68 ) ;
V_88 &= ~ V_105 ;
V_88 |= V_104 ;
F_7 ( V_68 , V_88 ) ;
V_88 = F_3 ( V_76 ) ;
V_88 &= ~ ( V_107 | V_141 ) ;
V_88 |= V_106 ;
F_7 ( V_76 , V_88 ) ;
F_7 ( V_142 , V_108 ) ;
if ( V_110 )
F_7 ( F_48 ( 3 ) ,
( V_143 |
V_144 |
V_145 ) ) ;
else
F_7 ( F_48 ( 3 ) , 0 ) ;
if ( V_109 ) {
T_3 V_146 = ( V_147
| V_148
| V_149
| V_150 ) ;
V_146 &= ~ V_151 ;
F_7 ( F_49 ( 3 ) , F_50 ( V_152 ) ) ;
F_7 ( F_51 ( 3 ) ,
( V_153 | V_154 ) ) ;
if ( V_6 -> V_26 . type == V_27 ) {
F_7 ( F_52 ( 3 ) , F_50 ( V_152 ) ) ;
V_146 &= ~ V_155 ;
}
F_7 ( F_53 ( 3 ) , V_146 ) ;
} else {
F_7 ( F_53 ( 3 ) , V_150 ) ;
}
F_54 () ;
V_88 = F_3 ( V_89 ) ;
V_88 = F_3 ( V_90 ) ;
V_88 = F_3 ( V_96 ) ;
V_88 = F_3 ( V_85 ) ;
return F_55 ( V_100 -> V_111 , & V_103 , sizeof( V_103 ) ) ?
- V_112 : 0 ;
}
void F_56 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_97 * V_98 = V_14 -> V_98 ;
switch ( V_6 -> V_26 . type ) {
case V_27 :
snprintf ( V_14 -> V_39 . V_156 , 16 , L_4 , V_98 -> V_157 ) ;
V_14 -> V_39 . V_158 = V_159 ;
V_14 -> V_39 . V_160 = 999999881 ;
V_14 -> V_39 . V_161 = 0 ;
V_14 -> V_39 . V_162 = 0 ;
V_14 -> V_39 . V_163 = F_14 ;
V_14 -> V_39 . V_164 = F_17 ;
V_14 -> V_39 . V_71 = F_23 ;
V_14 -> V_39 . V_165 = F_26 ;
V_14 -> V_39 . V_166 = F_28 ;
V_14 -> V_2 . V_167 = F_1 ;
V_14 -> V_2 . V_168 = F_57 ( 64 ) ;
V_14 -> V_2 . V_169 = 1 ;
V_14 -> V_2 . V_170 = V_43 ;
F_7 ( V_44 , V_45 | V_171 ) ;
break;
case V_28 :
case V_29 :
case V_30 :
snprintf ( V_14 -> V_39 . V_156 , 16 , L_4 , V_98 -> V_157 ) ;
V_14 -> V_39 . V_158 = V_159 ;
V_14 -> V_39 . V_160 = 62499999 ;
V_14 -> V_39 . V_161 = 0 ;
V_14 -> V_39 . V_162 = 0 ;
V_14 -> V_39 . V_163 = F_16 ;
V_14 -> V_39 . V_164 = F_17 ;
V_14 -> V_39 . V_71 = F_23 ;
V_14 -> V_39 . V_165 = F_26 ;
V_14 -> V_39 . V_166 = F_28 ;
V_14 -> V_2 . V_167 = F_4 ;
V_14 -> V_2 . V_168 = F_57 ( V_172 ) ;
V_14 -> V_2 . V_169 = 1 ;
V_14 -> V_2 . V_170 = 0 ;
F_7 ( V_173 , 0x0 ) ;
break;
case V_34 :
case V_35 :
snprintf ( V_14 -> V_39 . V_156 , 16 , L_4 , V_98 -> V_157 ) ;
V_14 -> V_39 . V_158 = V_159 ;
V_14 -> V_39 . V_160 = 62499999 ;
V_14 -> V_39 . V_161 = 0 ;
V_14 -> V_39 . V_162 = 0 ;
V_14 -> V_39 . V_163 = F_16 ;
V_14 -> V_39 . V_164 = F_20 ;
V_14 -> V_39 . V_71 = F_25 ;
V_14 -> V_39 . V_165 = F_27 ;
V_14 -> V_39 . V_166 = F_28 ;
F_7 ( V_173 , 0x0 ) ;
break;
default:
V_14 -> V_174 = NULL ;
return;
}
F_54 () ;
F_58 ( & V_14 -> V_31 ) ;
F_59 ( & V_14 -> V_60 , F_29 ) ;
if ( ( V_6 -> V_26 . type == V_34 ) || ( V_6 -> V_26 . type == V_35 ) ) {
struct V_15 V_16 = F_60 ( F_61 () ) ;
F_27 ( & V_14 -> V_39 , & V_16 ) ;
} else {
F_19 ( & V_14 -> V_32 , & V_14 -> V_2 ,
F_62 ( F_61 () ) ) ;
F_63 ( & V_14 -> V_70 ,
F_35 ) ;
F_37 ( & V_14 -> V_70 ,
V_72 ) ;
}
if ( V_6 -> V_26 . type >= V_28 ) {
F_7 ( V_175 , V_176 ) ;
F_7 ( V_177 , V_178 ) ;
}
V_14 -> V_174 = F_64 ( & V_14 -> V_39 ,
& V_14 -> V_66 -> V_67 ) ;
if ( F_65 ( V_14 -> V_174 ) ) {
V_14 -> V_174 = NULL ;
F_66 ( & V_14 -> V_66 -> V_67 , L_5 ) ;
} else {
F_67 ( & V_14 -> V_66 -> V_67 , L_6 ,
V_14 -> V_98 -> V_156 ) ;
V_14 -> V_24 |= V_179 ;
}
}
void F_68 ( struct V_3 * V_14 )
{
switch ( V_14 -> V_6 . V_26 . type ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
F_69 ( & V_14 -> V_70 ) ;
break;
case V_34 :
case V_35 :
break;
default:
return;
}
F_70 ( & V_14 -> V_60 ) ;
if ( V_14 -> V_62 ) {
F_31 ( V_14 -> V_62 ) ;
V_14 -> V_62 = NULL ;
}
if ( V_14 -> V_174 ) {
F_71 ( V_14 -> V_174 ) ;
F_67 ( & V_14 -> V_66 -> V_67 , L_7 ,
V_14 -> V_98 -> V_156 ) ;
V_14 -> V_24 &= ~ V_179 ;
}
}
void F_72 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
if ( ! ( V_14 -> V_24 & V_179 ) )
return;
switch ( V_14 -> V_6 . V_26 . type ) {
case V_27 :
F_7 ( V_44 , V_45 | V_171 ) ;
break;
case V_28 :
case V_29 :
case V_30 :
case V_34 :
case V_35 :
F_7 ( V_173 , 0x0 ) ;
F_7 ( V_175 , V_176 ) ;
F_7 ( V_177 , V_178 ) ;
break;
default:
return;
}
if ( ( V_6 -> V_26 . type == V_34 ) || ( V_6 -> V_26 . type == V_35 ) ) {
struct V_15 V_16 = F_60 ( F_61 () ) ;
F_27 ( & V_14 -> V_39 , & V_16 ) ;
} else {
F_19 ( & V_14 -> V_32 , & V_14 -> V_2 ,
F_62 ( F_61 () ) ) ;
}
}
