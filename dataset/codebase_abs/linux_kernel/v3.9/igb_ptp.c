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
F_9 ( & V_14 -> V_30 , V_24 ) ;
V_25 = F_10 ( & V_14 -> V_31 , V_23 ) ;
F_11 ( & V_14 -> V_30 , V_24 ) ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_32 = F_12 ( V_25 ) ;
break;
case V_33 :
case V_34 :
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_32 = F_13 ( V_23 >> 32 ,
V_23 & 0xFFFFFFFF ) ;
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
unsigned long V_24 ;
T_5 V_50 ;
F_9 ( & V_4 -> V_30 , V_24 ) ;
V_50 = F_18 ( & V_4 -> V_31 ) ;
V_50 += V_49 ;
F_19 ( & V_4 -> V_31 , & V_4 -> V_2 , V_50 ) ;
F_11 ( & V_4 -> V_30 , V_24 ) ;
return 0 ;
}
static int F_20 ( struct V_35 * V_36 , T_5 V_49 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_24 ;
struct V_15 V_50 , V_51 = F_21 ( V_49 ) ;
F_9 ( & V_4 -> V_30 , V_24 ) ;
F_5 ( V_4 , & V_50 ) ;
V_50 = F_22 ( V_50 , V_51 ) ;
F_6 ( V_4 , ( const struct V_15 * ) & V_50 ) ;
F_11 ( & V_4 -> V_30 , V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_24 ;
T_2 V_25 ;
T_3 V_52 ;
F_9 ( & V_4 -> V_30 , V_24 ) ;
V_25 = F_18 ( & V_4 -> V_31 ) ;
F_11 ( & V_4 -> V_30 , V_24 ) ;
V_16 -> V_19 = F_24 ( V_25 , 1000000000 , & V_52 ) ;
V_16 -> V_20 = V_52 ;
return 0 ;
}
static int F_25 ( struct V_35 * V_36 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_24 ;
F_9 ( & V_4 -> V_30 , V_24 ) ;
F_5 ( V_4 , V_16 ) ;
F_11 ( & V_4 -> V_30 , V_24 ) ;
return 0 ;
}
static int F_26 ( struct V_35 * V_36 ,
const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_24 ;
T_2 V_25 ;
V_25 = V_16 -> V_19 * 1000000000ULL ;
V_25 += V_16 -> V_20 ;
F_9 ( & V_4 -> V_30 , V_24 ) ;
F_19 ( & V_4 -> V_31 , & V_4 -> V_2 , V_25 ) ;
F_11 ( & V_4 -> V_30 , V_24 ) ;
return 0 ;
}
static int F_27 ( struct V_35 * V_36 ,
const struct V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_24 ;
F_9 ( & V_4 -> V_30 , V_24 ) ;
F_6 ( V_4 , V_16 ) ;
F_11 ( & V_4 -> V_30 , V_24 ) ;
return 0 ;
}
static int F_28 ( struct V_35 * V_36 ,
struct V_53 * V_54 , int V_55 )
{
return - V_56 ;
}
void F_29 ( struct V_57 * V_58 )
{
struct V_3 * V_14 = F_2 ( V_58 , struct V_3 ,
V_59 ) ;
struct V_5 * V_6 = & V_14 -> V_6 ;
T_3 V_60 ;
if ( ! V_14 -> V_61 )
return;
if ( F_30 ( V_14 -> V_62 +
V_63 ) ) {
F_31 ( V_14 -> V_61 ) ;
V_14 -> V_61 = NULL ;
V_14 -> V_64 ++ ;
F_32 ( & V_14 -> V_65 -> V_66 , L_1 ) ;
return;
}
V_60 = F_3 ( V_67 ) ;
if ( V_60 & V_68 )
F_33 ( V_14 ) ;
else
F_34 ( & V_14 -> V_59 ) ;
}
static void F_35 ( struct V_57 * V_58 )
{
struct V_3 * V_4 =
F_2 ( V_58 , struct V_3 , V_69 . V_58 ) ;
struct V_15 V_16 ;
V_4 -> V_38 . V_70 ( & V_4 -> V_38 , & V_16 ) ;
F_36 ( L_2 , V_16 . V_19 , V_16 . V_20 ) ;
F_37 ( & V_4 -> V_69 ,
V_71 ) ;
}
void F_38 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_72 * V_73 ;
T_3 V_74 = F_3 ( V_75 ) ;
unsigned long V_76 ;
int V_77 ;
if ( V_6 -> V_26 . type != V_27 )
return;
if ( ! ( V_74 & V_78 ) ) {
V_14 -> V_79 = V_80 ;
return;
}
V_76 = V_14 -> V_79 ;
for ( V_77 = 0 ; V_77 < V_14 -> V_81 ; V_77 ++ ) {
V_73 = V_14 -> V_73 [ V_77 ] ;
if ( F_39 ( V_73 -> V_82 , V_76 ) )
V_76 = V_73 -> V_82 ;
}
if ( F_30 ( V_76 + 5 * V_83 ) ) {
F_3 ( V_84 ) ;
V_14 -> V_79 = V_80 ;
V_14 -> V_85 ++ ;
F_32 ( & V_14 -> V_65 -> V_66 , L_3 ) ;
}
}
void F_33 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_21 V_86 ;
T_2 V_87 ;
V_87 = F_3 ( V_88 ) ;
V_87 |= ( T_2 ) F_3 ( V_89 ) << 32 ;
F_8 ( V_14 , & V_86 , V_87 ) ;
F_40 ( V_14 -> V_61 , & V_86 ) ;
F_31 ( V_14 -> V_61 ) ;
V_14 -> V_61 = NULL ;
}
void F_41 ( struct V_90 * V_91 ,
unsigned char * V_92 ,
struct V_93 * V_94 )
{
T_6 * V_87 = ( T_6 * ) V_92 ;
F_8 ( V_91 -> V_14 , F_42 ( V_94 ) ,
F_43 ( V_87 [ 1 ] ) ) ;
}
void F_44 ( struct V_90 * V_91 ,
struct V_93 * V_94 )
{
struct V_3 * V_14 = V_91 -> V_14 ;
struct V_5 * V_6 = & V_14 -> V_6 ;
T_2 V_87 ;
if ( ! ( F_3 ( V_75 ) & V_78 ) )
return;
V_87 = F_3 ( V_95 ) ;
V_87 |= ( T_2 ) F_3 ( V_84 ) << 32 ;
F_8 ( V_14 , F_42 ( V_94 ) , V_87 ) ;
}
int F_45 ( struct V_96 * V_97 ,
struct V_98 * V_99 , int V_100 )
{
struct V_3 * V_14 = F_46 ( V_97 ) ;
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_101 V_102 ;
T_3 V_103 = V_104 ;
T_3 V_105 = V_106 ;
T_3 V_107 = 0 ;
bool V_108 = false ;
bool V_109 = false ;
T_3 V_87 ;
if ( F_47 ( & V_102 , V_99 -> V_110 , sizeof( V_102 ) ) )
return - V_111 ;
if ( V_102 . V_24 )
return - V_112 ;
switch ( V_102 . V_113 ) {
case V_114 :
V_103 = 0 ;
case V_115 :
break;
default:
return - V_116 ;
}
switch ( V_102 . V_117 ) {
case V_118 :
V_105 = 0 ;
break;
case V_119 :
V_105 |= V_120 ;
V_107 = V_121 ;
V_108 = true ;
break;
case V_122 :
V_105 |= V_120 ;
V_107 = V_123 ;
V_108 = true ;
break;
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
V_105 |= V_133 ;
V_102 . V_117 = V_124 ;
V_109 = true ;
V_108 = true ;
break;
case V_134 :
case V_135 :
if ( V_6 -> V_26 . type != V_27 ) {
V_105 |= V_136 ;
V_102 . V_117 = V_135 ;
break;
}
default:
V_102 . V_117 = V_118 ;
return - V_116 ;
}
if ( V_6 -> V_26 . type == V_137 ) {
if ( V_105 | V_103 )
return - V_112 ;
return 0 ;
}
if ( ( V_6 -> V_26 . type >= V_28 ) && V_105 ) {
V_105 = V_106 ;
V_105 |= V_136 ;
V_102 . V_117 = V_135 ;
V_109 = true ;
V_108 = true ;
if ( ( V_6 -> V_26 . type == V_33 ) ||
( V_6 -> V_26 . type == V_34 ) ) {
V_87 = F_3 ( V_138 ) ;
V_87 |= V_139 ;
F_7 ( V_138 , V_87 ) ;
}
}
V_87 = F_3 ( V_67 ) ;
V_87 &= ~ V_104 ;
V_87 |= V_103 ;
F_7 ( V_67 , V_87 ) ;
V_87 = F_3 ( V_75 ) ;
V_87 &= ~ ( V_106 | V_140 ) ;
V_87 |= V_105 ;
F_7 ( V_75 , V_87 ) ;
F_7 ( V_141 , V_107 ) ;
if ( V_109 )
F_7 ( F_48 ( 3 ) ,
( V_142 |
V_143 |
V_144 ) ) ;
else
F_7 ( F_48 ( 3 ) , 0 ) ;
if ( V_108 ) {
T_3 V_145 = ( V_146
| V_147
| V_148
| V_149 ) ;
V_145 &= ~ V_150 ;
F_7 ( F_49 ( 3 ) , F_50 ( V_151 ) ) ;
F_7 ( F_51 ( 3 ) ,
( V_152 | V_153 ) ) ;
if ( V_6 -> V_26 . type == V_27 ) {
F_7 ( F_52 ( 3 ) , F_50 ( V_151 ) ) ;
V_145 &= ~ V_154 ;
}
F_7 ( F_53 ( 3 ) , V_145 ) ;
} else {
F_7 ( F_53 ( 3 ) , V_149 ) ;
}
F_54 () ;
V_87 = F_3 ( V_88 ) ;
V_87 = F_3 ( V_89 ) ;
V_87 = F_3 ( V_95 ) ;
V_87 = F_3 ( V_84 ) ;
return F_55 ( V_99 -> V_110 , & V_102 , sizeof( V_102 ) ) ?
- V_111 : 0 ;
}
void F_56 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_96 * V_97 = V_14 -> V_97 ;
switch ( V_6 -> V_26 . type ) {
case V_27 :
snprintf ( V_14 -> V_38 . V_155 , 16 , L_4 , V_97 -> V_156 ) ;
V_14 -> V_38 . V_157 = V_158 ;
V_14 -> V_38 . V_159 = 999999881 ;
V_14 -> V_38 . V_160 = 0 ;
V_14 -> V_38 . V_161 = 0 ;
V_14 -> V_38 . V_162 = F_14 ;
V_14 -> V_38 . V_163 = F_17 ;
V_14 -> V_38 . V_70 = F_23 ;
V_14 -> V_38 . V_164 = F_26 ;
V_14 -> V_38 . V_165 = F_28 ;
V_14 -> V_2 . V_166 = F_1 ;
V_14 -> V_2 . V_167 = F_57 ( 64 ) ;
V_14 -> V_2 . V_168 = 1 ;
V_14 -> V_2 . V_169 = V_42 ;
F_7 ( V_43 , V_44 | V_170 ) ;
break;
case V_28 :
case V_29 :
snprintf ( V_14 -> V_38 . V_155 , 16 , L_4 , V_97 -> V_156 ) ;
V_14 -> V_38 . V_157 = V_158 ;
V_14 -> V_38 . V_159 = 62499999 ;
V_14 -> V_38 . V_160 = 0 ;
V_14 -> V_38 . V_161 = 0 ;
V_14 -> V_38 . V_162 = F_16 ;
V_14 -> V_38 . V_163 = F_17 ;
V_14 -> V_38 . V_70 = F_23 ;
V_14 -> V_38 . V_164 = F_26 ;
V_14 -> V_38 . V_165 = F_28 ;
V_14 -> V_2 . V_166 = F_4 ;
V_14 -> V_2 . V_167 = F_57 ( V_171 ) ;
V_14 -> V_2 . V_168 = 1 ;
V_14 -> V_2 . V_169 = 0 ;
F_7 ( V_172 , 0x0 ) ;
break;
case V_33 :
case V_34 :
snprintf ( V_14 -> V_38 . V_155 , 16 , L_4 , V_97 -> V_156 ) ;
V_14 -> V_38 . V_157 = V_158 ;
V_14 -> V_38 . V_159 = 62499999 ;
V_14 -> V_38 . V_160 = 0 ;
V_14 -> V_38 . V_161 = 0 ;
V_14 -> V_38 . V_162 = F_16 ;
V_14 -> V_38 . V_163 = F_20 ;
V_14 -> V_38 . V_70 = F_25 ;
V_14 -> V_38 . V_164 = F_27 ;
V_14 -> V_38 . V_165 = F_28 ;
F_7 ( V_172 , 0x0 ) ;
break;
default:
V_14 -> V_173 = NULL ;
return;
}
F_54 () ;
F_58 ( & V_14 -> V_30 ) ;
F_59 ( & V_14 -> V_59 , F_29 ) ;
if ( ( V_6 -> V_26 . type == V_33 ) || ( V_6 -> V_26 . type == V_34 ) ) {
struct V_15 V_16 = F_60 ( F_61 () ) ;
F_27 ( & V_14 -> V_38 , & V_16 ) ;
} else {
F_19 ( & V_14 -> V_31 , & V_14 -> V_2 ,
F_62 ( F_61 () ) ) ;
F_63 ( & V_14 -> V_69 ,
F_35 ) ;
F_37 ( & V_14 -> V_69 ,
V_71 ) ;
}
if ( V_6 -> V_26 . type >= V_28 ) {
F_7 ( V_174 , V_175 ) ;
F_7 ( V_176 , V_177 ) ;
}
V_14 -> V_173 = F_64 ( & V_14 -> V_38 ,
& V_14 -> V_65 -> V_66 ) ;
if ( F_65 ( V_14 -> V_173 ) ) {
V_14 -> V_173 = NULL ;
F_66 ( & V_14 -> V_65 -> V_66 , L_5 ) ;
} else {
F_67 ( & V_14 -> V_65 -> V_66 , L_6 ,
V_14 -> V_97 -> V_155 ) ;
V_14 -> V_24 |= V_178 ;
}
}
void F_68 ( struct V_3 * V_14 )
{
switch ( V_14 -> V_6 . V_26 . type ) {
case V_27 :
case V_28 :
case V_29 :
F_69 ( & V_14 -> V_69 ) ;
break;
case V_33 :
case V_34 :
break;
default:
return;
}
F_70 ( & V_14 -> V_59 ) ;
if ( V_14 -> V_61 ) {
F_31 ( V_14 -> V_61 ) ;
V_14 -> V_61 = NULL ;
}
if ( V_14 -> V_173 ) {
F_71 ( V_14 -> V_173 ) ;
F_67 ( & V_14 -> V_65 -> V_66 , L_7 ,
V_14 -> V_97 -> V_155 ) ;
V_14 -> V_24 &= ~ V_178 ;
}
}
void F_72 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
if ( ! ( V_14 -> V_24 & V_178 ) )
return;
switch ( V_14 -> V_6 . V_26 . type ) {
case V_27 :
F_7 ( V_43 , V_44 | V_170 ) ;
break;
case V_28 :
case V_29 :
case V_33 :
case V_34 :
F_7 ( V_172 , 0x0 ) ;
F_7 ( V_174 , V_175 ) ;
F_7 ( V_176 , V_177 ) ;
break;
default:
return;
}
if ( ( V_6 -> V_26 . type == V_33 ) || ( V_6 -> V_26 . type == V_34 ) ) {
struct V_15 V_16 = F_60 ( F_61 () ) ;
F_27 ( & V_14 -> V_38 , & V_16 ) ;
} else {
F_19 ( & V_14 -> V_31 , & V_14 -> V_2 ,
F_62 ( F_61 () ) ) ;
}
}
