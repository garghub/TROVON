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
V_60 = F_3 ( V_62 ) ;
if ( V_60 & V_63 )
F_30 ( V_14 ) ;
else
F_31 ( & V_14 -> V_59 ) ;
}
static void F_32 ( struct V_57 * V_58 )
{
struct V_3 * V_4 =
F_2 ( V_58 , struct V_3 , V_64 . V_58 ) ;
struct V_15 V_16 ;
V_4 -> V_38 . V_65 ( & V_4 -> V_38 , & V_16 ) ;
F_33 ( L_1 , V_16 . V_19 , V_16 . V_20 ) ;
F_34 ( & V_4 -> V_64 ,
V_66 ) ;
}
void F_30 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_21 V_67 ;
T_2 V_68 ;
V_68 = F_3 ( V_69 ) ;
V_68 |= ( T_2 ) F_3 ( V_70 ) << 32 ;
F_8 ( V_14 , & V_67 , V_68 ) ;
F_35 ( V_14 -> V_61 , & V_67 ) ;
F_36 ( V_14 -> V_61 ) ;
V_14 -> V_61 = NULL ;
}
void F_37 ( struct V_71 * V_72 ,
unsigned char * V_73 ,
struct V_74 * V_75 )
{
T_6 * V_68 = ( T_6 * ) V_73 ;
F_8 ( V_72 -> V_14 , F_38 ( V_75 ) ,
F_39 ( V_68 [ 1 ] ) ) ;
}
void F_40 ( struct V_71 * V_72 ,
struct V_74 * V_75 )
{
struct V_3 * V_14 = V_72 -> V_14 ;
struct V_5 * V_6 = & V_14 -> V_6 ;
T_2 V_68 ;
if ( ! ( F_3 ( V_76 ) & V_77 ) )
return;
V_68 = F_3 ( V_78 ) ;
V_68 |= ( T_2 ) F_3 ( V_79 ) << 32 ;
F_8 ( V_14 , F_38 ( V_75 ) , V_68 ) ;
}
int F_41 ( struct V_80 * V_81 ,
struct V_82 * V_83 , int V_84 )
{
struct V_3 * V_14 = F_42 ( V_81 ) ;
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_85 V_86 ;
T_3 V_87 = V_88 ;
T_3 V_89 = V_90 ;
T_3 V_91 = 0 ;
bool V_92 = false ;
bool V_93 = false ;
T_3 V_68 ;
if ( F_43 ( & V_86 , V_83 -> V_94 , sizeof( V_86 ) ) )
return - V_95 ;
if ( V_86 . V_24 )
return - V_96 ;
switch ( V_86 . V_97 ) {
case V_98 :
V_87 = 0 ;
case V_99 :
break;
default:
return - V_100 ;
}
switch ( V_86 . V_101 ) {
case V_102 :
V_89 = 0 ;
break;
case V_103 :
V_89 |= V_104 ;
V_91 = V_105 ;
V_92 = true ;
break;
case V_106 :
V_89 |= V_104 ;
V_91 = V_107 ;
V_92 = true ;
break;
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_89 |= V_117 ;
V_86 . V_101 = V_108 ;
V_93 = true ;
V_92 = true ;
break;
case V_118 :
case V_119 :
if ( V_6 -> V_26 . type != V_27 ) {
V_89 |= V_120 ;
V_86 . V_101 = V_119 ;
break;
}
default:
V_86 . V_101 = V_102 ;
return - V_100 ;
}
if ( V_6 -> V_26 . type == V_121 ) {
if ( V_89 | V_87 )
return - V_96 ;
return 0 ;
}
if ( ( V_6 -> V_26 . type >= V_28 ) && V_89 ) {
V_89 = V_90 ;
V_89 |= V_120 ;
V_86 . V_101 = V_119 ;
V_93 = true ;
V_92 = true ;
if ( ( V_6 -> V_26 . type == V_33 ) ||
( V_6 -> V_26 . type == V_34 ) ) {
V_68 = F_3 ( V_122 ) ;
V_68 |= V_123 ;
F_7 ( V_122 , V_68 ) ;
}
}
V_68 = F_3 ( V_62 ) ;
V_68 &= ~ V_88 ;
V_68 |= V_87 ;
F_7 ( V_62 , V_68 ) ;
V_68 = F_3 ( V_76 ) ;
V_68 &= ~ ( V_90 | V_124 ) ;
V_68 |= V_89 ;
F_7 ( V_76 , V_68 ) ;
F_7 ( V_125 , V_91 ) ;
if ( V_93 )
F_7 ( F_44 ( 3 ) ,
( V_126 |
V_127 |
V_128 ) ) ;
else
F_7 ( F_44 ( 3 ) , 0 ) ;
#define F_45 319
if ( V_92 ) {
T_3 V_129 = ( V_130
| V_131
| V_132
| V_133 ) ;
V_129 &= ~ V_134 ;
F_7 ( F_46 ( 3 ) , F_47 ( F_45 ) ) ;
F_7 ( F_48 ( 3 ) ,
( V_135 | V_136 ) ) ;
if ( V_6 -> V_26 . type == V_27 ) {
F_7 ( F_49 ( 3 ) , F_47 ( F_45 ) ) ;
V_129 &= ~ V_137 ;
}
F_7 ( F_50 ( 3 ) , V_129 ) ;
} else {
F_7 ( F_50 ( 3 ) , V_133 ) ;
}
F_51 () ;
V_68 = F_3 ( V_69 ) ;
V_68 = F_3 ( V_70 ) ;
V_68 = F_3 ( V_78 ) ;
V_68 = F_3 ( V_79 ) ;
return F_52 ( V_83 -> V_94 , & V_86 , sizeof( V_86 ) ) ?
- V_95 : 0 ;
}
void F_53 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
struct V_80 * V_81 = V_14 -> V_81 ;
switch ( V_6 -> V_26 . type ) {
case V_27 :
snprintf ( V_14 -> V_38 . V_138 , 16 , L_2 , V_81 -> V_139 ) ;
V_14 -> V_38 . V_140 = V_141 ;
V_14 -> V_38 . V_142 = 1000000000 ;
V_14 -> V_38 . V_143 = 0 ;
V_14 -> V_38 . V_144 = 0 ;
V_14 -> V_38 . V_145 = F_14 ;
V_14 -> V_38 . V_146 = F_17 ;
V_14 -> V_38 . V_65 = F_23 ;
V_14 -> V_38 . V_147 = F_26 ;
V_14 -> V_38 . V_148 = F_28 ;
V_14 -> V_2 . V_149 = F_1 ;
V_14 -> V_2 . V_150 = F_54 ( 64 ) ;
V_14 -> V_2 . V_151 = 1 ;
V_14 -> V_2 . V_152 = V_42 ;
F_7 ( V_43 , V_44 | V_153 ) ;
break;
case V_28 :
case V_29 :
snprintf ( V_14 -> V_38 . V_138 , 16 , L_2 , V_81 -> V_139 ) ;
V_14 -> V_38 . V_140 = V_141 ;
V_14 -> V_38 . V_142 = 62499999 ;
V_14 -> V_38 . V_143 = 0 ;
V_14 -> V_38 . V_144 = 0 ;
V_14 -> V_38 . V_145 = F_16 ;
V_14 -> V_38 . V_146 = F_17 ;
V_14 -> V_38 . V_65 = F_23 ;
V_14 -> V_38 . V_147 = F_26 ;
V_14 -> V_38 . V_148 = F_28 ;
V_14 -> V_2 . V_149 = F_4 ;
V_14 -> V_2 . V_150 = F_54 ( V_154 ) ;
V_14 -> V_2 . V_151 = 1 ;
V_14 -> V_2 . V_152 = 0 ;
F_7 ( V_155 , 0x0 ) ;
break;
case V_33 :
case V_34 :
snprintf ( V_14 -> V_38 . V_138 , 16 , L_2 , V_81 -> V_139 ) ;
V_14 -> V_38 . V_140 = V_141 ;
V_14 -> V_38 . V_142 = 62499999 ;
V_14 -> V_38 . V_143 = 0 ;
V_14 -> V_38 . V_144 = 0 ;
V_14 -> V_38 . V_145 = F_16 ;
V_14 -> V_38 . V_146 = F_20 ;
V_14 -> V_38 . V_65 = F_25 ;
V_14 -> V_38 . V_147 = F_27 ;
V_14 -> V_38 . V_148 = F_28 ;
F_7 ( V_155 , 0x0 ) ;
break;
default:
V_14 -> V_156 = NULL ;
return;
}
F_51 () ;
F_55 ( & V_14 -> V_30 ) ;
F_56 ( & V_14 -> V_59 , F_29 ) ;
if ( ( V_6 -> V_26 . type == V_33 ) || ( V_6 -> V_26 . type == V_34 ) ) {
struct V_15 V_16 = F_57 ( F_58 () ) ;
F_27 ( & V_14 -> V_38 , & V_16 ) ;
} else {
F_19 ( & V_14 -> V_31 , & V_14 -> V_2 ,
F_59 ( F_58 () ) ) ;
F_60 ( & V_14 -> V_64 ,
F_32 ) ;
F_34 ( & V_14 -> V_64 ,
V_66 ) ;
}
if ( V_6 -> V_26 . type >= V_28 ) {
F_7 ( V_157 , V_158 ) ;
F_7 ( V_159 , V_160 ) ;
}
V_14 -> V_156 = F_61 ( & V_14 -> V_38 ,
& V_14 -> V_161 -> V_162 ) ;
if ( F_62 ( V_14 -> V_156 ) ) {
V_14 -> V_156 = NULL ;
F_63 ( & V_14 -> V_161 -> V_162 , L_3 ) ;
} else {
F_64 ( & V_14 -> V_161 -> V_162 , L_4 ,
V_14 -> V_81 -> V_138 ) ;
V_14 -> V_24 |= V_163 ;
}
}
void F_65 ( struct V_3 * V_14 )
{
switch ( V_14 -> V_6 . V_26 . type ) {
case V_27 :
case V_28 :
case V_29 :
F_66 ( & V_14 -> V_64 ) ;
break;
case V_33 :
case V_34 :
break;
default:
return;
}
F_67 ( & V_14 -> V_59 ) ;
if ( V_14 -> V_156 ) {
F_68 ( V_14 -> V_156 ) ;
F_64 ( & V_14 -> V_161 -> V_162 , L_5 ,
V_14 -> V_81 -> V_138 ) ;
V_14 -> V_24 &= ~ V_163 ;
}
}
void F_69 ( struct V_3 * V_14 )
{
struct V_5 * V_6 = & V_14 -> V_6 ;
if ( ! ( V_14 -> V_24 & V_163 ) )
return;
switch ( V_14 -> V_6 . V_26 . type ) {
case V_27 :
F_7 ( V_43 , V_44 | V_153 ) ;
break;
case V_28 :
case V_29 :
case V_33 :
case V_34 :
F_7 ( V_155 , 0x0 ) ;
F_7 ( V_157 , V_158 ) ;
F_7 ( V_159 , V_160 ) ;
break;
default:
return;
}
if ( ( V_6 -> V_26 . type == V_33 ) || ( V_6 -> V_26 . type == V_34 ) ) {
struct V_15 V_16 = F_57 ( F_58 () ) ;
F_27 ( & V_14 -> V_38 , & V_16 ) ;
} else {
F_19 ( & V_14 -> V_31 , & V_14 -> V_2 ,
F_59 ( F_58 () ) ) ;
}
}
