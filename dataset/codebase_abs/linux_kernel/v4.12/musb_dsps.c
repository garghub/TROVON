static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
if ( V_3 < 0 )
V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
else
V_4 = F_2 ( V_3 ) ;
F_3 ( & V_2 -> V_7 , V_8 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
return;
F_1 ( V_2 , - 1 ) ;
}
static void F_5 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_14 * V_15 = F_6 ( V_12 -> V_16 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
void T_1 * V_18 = V_10 -> V_19 ;
T_2 V_20 , V_21 ;
V_20 = ( ( V_10 -> V_20 & V_5 -> V_22 ) << V_5 -> V_23 ) |
( ( V_10 -> V_20 & V_5 -> V_24 ) << V_5 -> V_25 ) ;
V_21 = ( V_5 -> V_26 & ~ V_27 ) ;
F_8 ( V_18 , V_5 -> V_28 , V_20 ) ;
F_8 ( V_18 , V_5 -> V_29 , V_21 ) ;
if ( V_10 -> V_30 -> V_31 -> V_32 == V_33 &&
V_10 -> V_34 == V_35 )
F_1 ( V_2 , - 1 ) ;
}
static void F_9 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_14 * V_15 = F_6 ( V_12 -> V_16 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
void T_1 * V_18 = V_10 -> V_19 ;
F_8 ( V_18 , V_5 -> V_36 , V_5 -> V_26 ) ;
F_8 ( V_18 , V_5 -> V_37 ,
V_5 -> V_38 | V_5 -> V_39 ) ;
F_10 ( & V_2 -> V_7 ) ;
}
static int F_11 ( struct V_10 * V_10 , void * V_40 )
{
void T_1 * V_41 = V_10 -> V_41 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
T_3 V_42 ;
int V_43 = 0 ;
if ( V_2 -> V_9 )
F_13 ( & V_2 -> V_7 ) ;
V_42 = F_14 ( V_41 , V_44 ) ;
F_15 ( V_10 -> V_13 , L_1 , V_42 ,
F_16 ( V_10 -> V_30 -> V_31 -> V_32 ) ) ;
switch ( V_10 -> V_30 -> V_31 -> V_32 ) {
case V_45 :
F_4 ( V_2 ) ;
break;
case V_46 :
if ( V_10 -> V_34 == V_47 ) {
F_4 ( V_2 ) ;
break;
}
F_17 ( V_10 -> V_41 , V_44 , 0 ) ;
V_43 = 1 ;
case V_48 :
case V_33 :
if ( ! V_2 -> V_9 ) {
if ( V_42 & V_49 ) {
V_10 -> V_30 -> V_31 -> V_32 = V_33 ;
F_18 ( V_10 ) ;
} else {
V_10 -> V_30 -> V_31 -> V_32 = V_48 ;
F_19 ( V_10 ) ;
}
if ( ! ( V_42 & V_50 ) && ! V_43 )
F_17 ( V_41 , V_44 ,
V_50 ) ;
}
F_4 ( V_2 ) ;
break;
case V_51 :
V_10 -> V_30 -> V_31 -> V_32 = V_45 ;
F_8 ( V_10 -> V_19 , V_5 -> V_29 ,
V_52 << V_5 -> V_53 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_20 ( unsigned long V_54 )
{
struct V_10 * V_10 = ( void * ) V_54 ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_55 ;
int V_56 ;
V_56 = F_21 ( V_12 ) ;
if ( ( V_56 != - V_57 ) && V_56 < 0 ) {
F_22 ( V_12 , L_2 , V_56 ) ;
F_23 ( V_12 ) ;
return;
}
F_24 ( & V_10 -> V_58 , V_55 ) ;
V_56 = F_25 ( V_10 , F_11 , NULL ) ;
if ( V_56 < 0 )
F_22 ( V_12 , L_3 , V_59 , V_56 ) ;
F_26 ( & V_10 -> V_58 , V_55 ) ;
F_27 ( V_12 ) ;
F_28 ( V_12 ) ;
}
static void F_29 ( struct V_10 * V_10 , int V_60 )
{
T_2 V_61 ;
struct V_1 * V_2 = F_12 ( V_10 -> V_13 -> V_16 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
V_61 = ( 1 << V_60 ) << V_5 -> V_25 ;
F_8 ( V_10 -> V_19 , V_5 -> V_62 , V_61 ) ;
}
static T_4 F_30 ( int V_63 , void * V_64 )
{
struct V_10 * V_10 = V_64 ;
void T_1 * V_18 = V_10 -> V_19 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
unsigned long V_55 ;
T_4 V_65 = V_66 ;
T_2 V_61 , V_67 ;
F_24 ( & V_10 -> V_58 , V_55 ) ;
V_61 = F_31 ( V_18 , V_5 -> V_62 ) ;
V_10 -> V_68 = ( V_61 & V_5 -> V_39 ) >> V_5 -> V_25 ;
V_10 -> V_69 = ( V_61 & V_5 -> V_38 ) >> V_5 -> V_23 ;
if ( V_61 )
F_8 ( V_18 , V_5 -> V_62 , V_61 ) ;
V_67 = F_31 ( V_18 , V_5 -> V_70 ) ;
if ( ! V_67 && ! V_61 )
goto V_71;
V_10 -> V_72 = ( V_67 & V_5 -> V_26 ) >> V_5 -> V_53 ;
if ( V_67 )
F_8 ( V_18 , V_5 -> V_70 , V_67 ) ;
F_15 ( V_10 -> V_13 , L_4 ,
V_67 , V_61 ) ;
if ( V_67 & ( ( 1 << V_5 -> V_73 ) << V_5 -> V_53 ) ) {
int V_73 = F_31 ( V_18 , V_5 -> V_74 ) ;
void T_1 * V_41 = V_10 -> V_41 ;
T_3 V_42 = F_14 ( V_41 , V_44 ) ;
int V_56 ;
V_56 = V_10 -> V_72 & V_52 ;
if ( V_56 ) {
V_10 -> V_72 &= ~ V_52 ;
V_10 -> V_30 -> V_31 -> V_32 = V_51 ;
F_4 ( V_2 ) ;
F_32 ( L_5 ) ;
} else if ( V_73 ) {
F_19 ( V_10 ) ;
V_10 -> V_30 -> V_31 -> V_75 = 1 ;
V_10 -> V_30 -> V_31 -> V_32 = V_45 ;
F_4 ( V_2 ) ;
} else {
V_10 -> V_76 = 0 ;
F_18 ( V_10 ) ;
V_10 -> V_30 -> V_31 -> V_75 = 0 ;
V_10 -> V_30 -> V_31 -> V_32 = V_33 ;
}
F_15 ( V_10 -> V_13 , L_6 ,
V_73 ? L_7 : L_8 ,
F_16 ( V_10 -> V_30 -> V_31 -> V_32 ) ,
V_56 ? L_9 : L_10 ,
V_42 ) ;
V_65 = V_77 ;
}
if ( V_10 -> V_69 || V_10 -> V_68 || V_10 -> V_72 )
V_65 |= F_33 ( V_10 ) ;
switch ( V_10 -> V_30 -> V_31 -> V_32 ) {
case V_33 :
case V_46 :
F_4 ( V_2 ) ;
break;
default:
break;
}
V_71:
F_26 ( & V_10 -> V_58 , V_55 ) ;
return V_65 ;
}
static int F_34 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
struct V_78 * V_79 ;
struct V_78 * V_80 ;
char V_81 [ 128 ] ;
sprintf ( V_81 , L_11 , F_35 ( V_10 -> V_13 ) ) ;
V_79 = F_36 ( V_81 , NULL ) ;
if ( ! V_79 )
return - V_82 ;
V_2 -> V_83 = V_79 ;
V_2 -> V_84 . V_85 = V_86 ;
V_2 -> V_84 . V_87 = F_37 ( V_86 ) ;
V_2 -> V_84 . V_88 = V_10 -> V_19 ;
V_80 = F_38 ( L_12 , V_89 , V_79 , & V_2 -> V_84 ) ;
if ( ! V_80 ) {
F_39 ( V_79 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_40 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
struct V_14 * V_16 = F_6 ( V_12 -> V_16 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
void T_1 * V_18 ;
struct V_90 * V_91 ;
T_2 V_92 , V_93 ;
int V_65 ;
V_91 = F_41 ( V_16 , V_94 , L_13 ) ;
V_18 = F_42 ( V_12 , V_91 ) ;
if ( F_43 ( V_18 ) )
return F_44 ( V_18 ) ;
V_10 -> V_19 = V_18 ;
V_10 -> V_30 = F_45 ( V_12 -> V_16 , L_14 , 0 ) ;
if ( F_43 ( V_10 -> V_30 ) )
return F_44 ( V_10 -> V_30 ) ;
V_10 -> V_95 = F_46 ( V_12 -> V_16 , L_15 ) ;
V_92 = F_31 ( V_18 , V_5 -> V_96 ) ;
if ( ! V_92 )
return - V_97 ;
F_47 ( V_10 -> V_30 ) ;
if ( F_43 ( V_10 -> V_95 ) ) {
V_10 -> V_95 = NULL ;
} else {
V_65 = F_48 ( V_10 -> V_95 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_49 ( V_10 -> V_95 ) ;
if ( V_65 ) {
F_50 ( V_10 -> V_95 ) ;
return V_65 ;
}
}
F_51 ( & V_2 -> V_7 , F_20 , ( unsigned long ) V_10 ) ;
F_8 ( V_18 , V_5 -> V_98 , ( 1 << V_5 -> V_99 ) ) ;
V_10 -> V_100 = F_30 ;
V_93 = F_31 ( V_18 , V_5 -> V_101 ) ;
V_93 &= ~ ( 1 << V_5 -> V_102 ) ;
F_8 ( V_10 -> V_19 , V_5 -> V_101 , V_93 ) ;
V_93 = F_14 ( V_10 -> V_41 , V_103 ) ;
if ( V_93 & V_104 ) {
V_2 -> V_105 = true ;
V_93 |= V_106 ;
F_17 ( V_10 -> V_41 , V_103 , V_93 ) ;
}
F_1 ( V_2 , - 1 ) ;
return F_34 ( V_10 , V_2 ) ;
}
static int F_52 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_53 ( V_10 -> V_30 ) ;
F_54 ( V_10 -> V_95 ) ;
F_50 ( V_10 -> V_95 ) ;
F_39 ( V_2 -> V_83 ) ;
return 0 ;
}
static int F_55 ( struct V_10 * V_10 , T_3 V_107 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
void T_1 * V_19 = V_10 -> V_19 ;
T_2 V_108 ;
V_108 = F_31 ( V_19 , V_5 -> V_107 ) ;
switch ( V_107 ) {
case V_109 :
V_108 &= ~ ( 1 << V_5 -> V_110 ) ;
V_108 |= ( 1 << V_5 -> V_111 ) ;
F_8 ( V_19 , V_5 -> V_107 , V_108 ) ;
F_8 ( V_19 , V_5 -> V_101 , 0x02 ) ;
break;
case V_112 :
V_108 |= ( 1 << V_5 -> V_110 ) ;
V_108 |= ( 1 << V_5 -> V_111 ) ;
F_8 ( V_19 , V_5 -> V_107 , V_108 ) ;
break;
case V_113 :
F_8 ( V_19 , V_5 -> V_101 , 0x02 ) ;
break;
default:
F_22 ( V_2 -> V_12 , L_16 , V_107 ) ;
return - V_114 ;
}
return 0 ;
}
static bool F_56 ( struct V_10 * V_10 )
{
T_3 V_115 ;
bool V_116 = false ;
V_115 = F_14 ( V_10 -> V_41 , V_103 ) ;
F_15 ( V_10 -> V_13 , L_17 ,
V_115 ) ;
F_15 ( V_10 -> V_13 , L_18 ,
V_115 & V_117 ? L_19 : L_20 ) ;
if ( V_115 & V_117 ) {
int V_118 = 10 ;
V_115 = F_14 ( V_10 -> V_41 , V_103 ) ;
V_115 |= V_119 ;
F_17 ( V_10 -> V_41 , V_103 , V_115 ) ;
F_15 ( V_10 -> V_13 , L_21 ) ;
do {
V_115 = F_14 ( V_10 -> V_41 , V_103 ) ;
F_57 ( 1 ) ;
} while ( ( V_115 & V_117 ) && V_118 -- );
if ( V_115 & V_117 ) {
F_15 ( V_10 -> V_13 , L_22 ,
V_115 ) ;
V_116 = true ;
}
} else {
V_116 = true ;
}
return V_116 ;
}
static int F_58 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
int V_116 = 0 ;
if ( V_2 -> V_105 )
V_116 = F_56 ( V_10 ) ;
else
V_116 = 1 ;
return V_116 ? 0 : - V_120 ;
}
static void F_59 ( struct V_121 * V_122 , T_5 V_123 , T_3 * V_124 )
{
void T_1 * V_125 = V_122 -> V_125 ;
if ( V_123 >= 4 ) {
F_60 ( V_125 , V_124 , V_123 >> 2 ) ;
V_124 += V_123 & ~ 0x03 ;
V_123 &= 0x03 ;
}
if ( V_123 > 0 ) {
T_2 V_93 = F_31 ( V_125 , 0 ) ;
memcpy ( V_124 , & V_93 , V_123 ) ;
}
}
static void F_61 ( struct V_126 * V_127 )
{
struct V_10 * V_10 = V_127 -> V_10 ;
struct V_1 * V_2 = F_12 ( V_10 -> V_13 -> V_16 ) ;
void T_1 * V_128 = V_2 -> V_128 ;
T_2 V_74 ;
V_74 = F_31 ( V_128 , V_129 ) ;
if ( V_74 & V_130 )
F_8 ( V_128 , V_129 , V_130 ) ;
}
static struct V_126 *
F_62 ( struct V_10 * V_10 , void T_1 * V_88 )
{
struct V_126 * V_13 ;
struct V_1 * V_2 = F_12 ( V_10 -> V_13 -> V_16 ) ;
void T_1 * V_128 = V_2 -> V_128 ;
V_13 = F_63 ( V_10 , V_88 ) ;
if ( F_64 ( V_13 ) )
return V_13 ;
F_8 ( V_128 , V_131 , V_130 ) ;
V_13 -> V_132 = F_61 ;
return V_13 ;
}
static void F_65 ( struct V_126 * V_127 )
{
struct V_10 * V_10 = V_127 -> V_10 ;
struct V_1 * V_2 = F_12 ( V_10 -> V_13 -> V_16 ) ;
void T_1 * V_128 = V_2 -> V_128 ;
F_8 ( V_128 , V_133 , V_130 ) ;
F_66 ( V_127 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
void T_1 * V_128 = V_2 -> V_128 ;
F_8 ( V_128 , V_133 , V_130 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
void T_1 * V_128 = V_2 -> V_128 ;
F_8 ( V_128 , V_131 , V_130 ) ;
}
static void F_67 ( struct V_1 * V_2 ) {}
static void F_68 ( struct V_1 * V_2 ) {}
static int F_69 ( struct V_134 * V_135 , const char * V_136 )
{
int V_65 ;
T_2 V_93 ;
V_65 = F_70 ( V_135 , V_136 , & V_93 ) ;
if ( V_65 )
return 0 ;
return V_93 ;
}
static int F_71 ( struct V_11 * V_12 )
{
enum V_137 V_107 ;
V_107 = F_72 ( V_12 ) ;
switch ( V_107 ) {
case V_138 :
return V_47 ;
case V_139 :
return V_140 ;
case V_141 :
case V_142 :
default:
return V_35 ;
}
}
static int F_73 ( struct V_1 * V_2 ,
struct V_14 * V_16 )
{
struct V_143 V_144 ;
struct V_90 V_145 [ 2 ] ;
struct V_90 * V_146 ;
struct V_11 * V_12 = & V_16 -> V_12 ;
struct V_147 * V_148 ;
struct V_14 * V_10 ;
struct V_134 * V_135 = V_16 -> V_12 . V_149 ;
int V_65 , V_93 ;
memset ( V_145 , 0 , sizeof( V_145 ) ) ;
V_146 = F_41 ( V_16 , V_94 , L_23 ) ;
if ( ! V_146 ) {
F_22 ( V_12 , L_24 ) ;
return - V_114 ;
}
V_145 [ 0 ] = * V_146 ;
V_146 = F_41 ( V_16 , V_150 , L_23 ) ;
if ( ! V_146 ) {
F_22 ( V_12 , L_25 ) ;
return - V_114 ;
}
V_145 [ 1 ] = * V_146 ;
V_10 = F_74 ( L_26 ,
( V_145 [ 0 ] . V_151 & 0xFFF ) == 0x400 ? 0 : 1 ) ;
if ( ! V_10 ) {
F_22 ( V_12 , L_27 ) ;
return - V_82 ;
}
V_10 -> V_12 . V_16 = V_12 ;
V_10 -> V_12 . V_152 = & V_153 ;
V_10 -> V_12 . V_154 = V_153 ;
V_2 -> V_10 = V_10 ;
V_65 = F_75 ( V_10 , V_145 ,
F_37 ( V_145 ) ) ;
if ( V_65 ) {
F_22 ( V_12 , L_28 ) ;
goto V_56;
}
V_148 = F_76 ( & V_16 -> V_12 , sizeof( * V_148 ) , V_155 ) ;
if ( ! V_148 ) {
V_65 = - V_82 ;
goto V_56;
}
V_144 . V_148 = V_148 ;
V_144 . V_156 = & V_157 ;
V_148 -> V_158 = F_69 ( V_135 , L_29 ) ;
V_148 -> V_159 = F_69 ( V_135 , L_30 ) ;
V_148 -> V_160 = 1 ;
V_144 . V_107 = F_71 ( V_12 ) ;
V_144 . V_161 = F_69 ( V_135 , L_31 ) / 2 ;
V_65 = F_70 ( V_135 , L_32 , & V_93 ) ;
if ( ! V_65 && V_93 )
V_148 -> V_162 = true ;
V_148 -> V_163 = F_77 ( & V_16 -> V_12 ) ;
switch ( V_148 -> V_163 ) {
case V_164 :
case V_165 :
break;
case V_166 :
F_78 ( V_12 , L_33
L_34 ) ;
default:
V_148 -> V_163 = V_167 ;
}
V_65 = F_79 ( V_10 , & V_144 , sizeof( V_144 ) ) ;
if ( V_65 ) {
F_22 ( V_12 , L_35 ) ;
goto V_56;
}
V_65 = F_80 ( V_10 ) ;
if ( V_65 ) {
F_22 ( V_12 , L_36 ) ;
goto V_56;
}
return 0 ;
V_56:
F_81 ( V_10 ) ;
return V_65 ;
}
static T_4 F_82 ( int V_63 , void * V_168 )
{
struct V_1 * V_2 = V_168 ;
struct V_10 * V_10 = F_7 ( V_2 -> V_10 ) ;
if ( ! V_10 )
return V_66 ;
F_15 ( V_2 -> V_12 , L_37 ) ;
F_1 ( V_2 , 0 ) ;
return V_77 ;
}
static int F_83 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
int error ;
V_2 -> V_9 = F_84 ( V_15 , L_38 ) ;
if ( V_2 -> V_9 == - V_169 )
return - V_169 ;
if ( V_2 -> V_9 <= 0 ) {
V_2 -> V_9 = 0 ;
return 0 ;
}
error = F_85 ( V_2 -> V_12 , V_2 -> V_9 ,
NULL , F_82 ,
V_170 ,
L_38 , V_2 ) ;
if ( error ) {
V_2 -> V_9 = 0 ;
return error ;
}
F_15 ( V_2 -> V_12 , L_39 , V_2 -> V_9 ) ;
return 0 ;
}
static int F_86 ( struct V_14 * V_15 )
{
const struct V_171 * V_172 ;
const struct V_17 * V_5 ;
struct V_1 * V_2 ;
int V_65 ;
if ( ! strcmp ( V_15 -> V_173 , L_26 ) )
return - V_97 ;
V_172 = F_87 ( V_174 , V_15 -> V_12 . V_149 ) ;
if ( ! V_172 ) {
F_22 ( & V_15 -> V_12 , L_40 ) ;
return - V_114 ;
}
V_5 = V_172 -> V_175 ;
if ( F_88 ( V_15 -> V_12 . V_149 , L_41 ) )
V_157 . V_176 = F_59 ;
V_2 = F_76 ( & V_15 -> V_12 , sizeof( * V_2 ) , V_155 ) ;
if ( ! V_2 )
return - V_82 ;
V_2 -> V_12 = & V_15 -> V_12 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_128 = F_89 ( V_15 -> V_12 . V_16 -> V_149 , 0 ) ;
if ( ! V_2 -> V_128 )
return - V_177 ;
if ( F_72 ( & V_15 -> V_12 ) == V_139 ) {
V_65 = F_83 ( V_15 , V_2 ) ;
if ( V_65 )
goto V_178;
}
F_90 ( V_15 , V_2 ) ;
F_91 ( & V_15 -> V_12 ) ;
V_65 = F_73 ( V_2 , V_15 ) ;
if ( V_65 )
goto V_56;
return 0 ;
V_56:
F_92 ( & V_15 -> V_12 ) ;
V_178:
F_93 ( V_2 -> V_128 ) ;
return V_65 ;
}
static int F_94 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_95 ( V_2 -> V_10 ) ;
F_92 ( & V_15 -> V_12 ) ;
F_93 ( V_2 -> V_128 ) ;
return 0 ;
}
static int F_96 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
struct V_10 * V_10 = F_7 ( V_2 -> V_10 ) ;
void T_1 * V_179 ;
F_10 ( & V_2 -> V_7 ) ;
if ( ! V_10 )
return 0 ;
V_179 = V_10 -> V_19 ;
V_2 -> V_180 . V_98 = F_31 ( V_179 , V_5 -> V_98 ) ;
V_2 -> V_180 . V_61 = F_31 ( V_179 , V_5 -> V_28 ) ;
V_2 -> V_180 . V_181 = F_31 ( V_179 , V_5 -> V_29 ) ;
V_2 -> V_180 . V_101 = F_31 ( V_179 , V_5 -> V_101 ) ;
V_2 -> V_180 . V_107 = F_31 ( V_179 , V_5 -> V_107 ) ;
V_2 -> V_180 . V_182 = F_31 ( V_179 , V_5 -> V_182 ) ;
V_2 -> V_180 . V_183 = F_31 ( V_179 , V_5 -> V_183 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int F_97 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
struct V_10 * V_10 = F_7 ( V_2 -> V_10 ) ;
void T_1 * V_179 ;
if ( ! V_10 )
return 0 ;
F_68 ( V_2 ) ;
V_179 = V_10 -> V_19 ;
F_8 ( V_179 , V_5 -> V_98 , V_2 -> V_180 . V_98 ) ;
F_8 ( V_179 , V_5 -> V_28 , V_2 -> V_180 . V_61 ) ;
F_8 ( V_179 , V_5 -> V_29 , V_2 -> V_180 . V_181 ) ;
F_8 ( V_179 , V_5 -> V_101 , V_2 -> V_180 . V_101 ) ;
F_8 ( V_179 , V_5 -> V_107 , V_2 -> V_180 . V_107 ) ;
F_8 ( V_179 , V_5 -> V_182 , V_2 -> V_180 . V_182 ) ;
F_8 ( V_179 , V_5 -> V_183 , V_2 -> V_180 . V_183 ) ;
if ( V_10 -> V_30 -> V_31 -> V_32 == V_33 &&
V_10 -> V_34 == V_35 )
F_1 ( V_2 , - 1 ) ;
return 0 ;
}
