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
F_17 ( V_10 -> V_41 , V_44 , 0 ) ;
V_43 = 1 ;
case V_47 :
case V_33 :
if ( ! V_2 -> V_9 ) {
if ( V_42 & V_48 ) {
V_10 -> V_30 -> V_31 -> V_32 = V_33 ;
F_18 ( V_10 ) ;
} else {
V_10 -> V_30 -> V_31 -> V_32 = V_47 ;
F_19 ( V_10 ) ;
}
if ( ! ( V_42 & V_49 ) && ! V_43 )
F_17 ( V_41 , V_44 ,
V_49 ) ;
}
F_4 ( V_2 ) ;
break;
case V_50 :
V_10 -> V_30 -> V_31 -> V_32 = V_45 ;
F_8 ( V_10 -> V_19 , V_5 -> V_29 ,
V_51 << V_5 -> V_52 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_20 ( unsigned long V_53 )
{
struct V_10 * V_10 = ( void * ) V_53 ;
struct V_11 * V_12 = V_10 -> V_13 ;
unsigned long V_54 ;
int V_55 ;
V_55 = F_21 ( V_12 ) ;
if ( ( V_55 != - V_56 ) && V_55 < 0 ) {
F_22 ( V_12 , L_2 , V_55 ) ;
F_23 ( V_12 ) ;
return;
}
F_24 ( & V_10 -> V_57 , V_54 ) ;
V_55 = F_25 ( V_10 , F_11 , NULL ) ;
if ( V_55 < 0 )
F_22 ( V_12 , L_3 , V_58 , V_55 ) ;
F_26 ( & V_10 -> V_57 , V_54 ) ;
F_27 ( V_12 ) ;
F_28 ( V_12 ) ;
}
static void F_29 ( struct V_10 * V_10 , int V_59 )
{
T_2 V_60 ;
struct V_1 * V_2 = F_12 ( V_10 -> V_13 -> V_16 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
V_60 = ( 1 << V_59 ) << V_5 -> V_25 ;
F_8 ( V_10 -> V_19 , V_5 -> V_61 , V_60 ) ;
}
static T_4 F_30 ( int V_62 , void * V_63 )
{
struct V_10 * V_10 = V_63 ;
void T_1 * V_18 = V_10 -> V_19 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
unsigned long V_54 ;
T_4 V_64 = V_65 ;
T_2 V_60 , V_66 ;
F_24 ( & V_10 -> V_57 , V_54 ) ;
V_60 = F_31 ( V_18 , V_5 -> V_61 ) ;
V_10 -> V_67 = ( V_60 & V_5 -> V_39 ) >> V_5 -> V_25 ;
V_10 -> V_68 = ( V_60 & V_5 -> V_38 ) >> V_5 -> V_23 ;
if ( V_60 )
F_8 ( V_18 , V_5 -> V_61 , V_60 ) ;
V_66 = F_31 ( V_18 , V_5 -> V_69 ) ;
if ( ! V_66 && ! V_60 )
goto V_70;
V_10 -> V_71 = ( V_66 & V_5 -> V_26 ) >> V_5 -> V_52 ;
if ( V_66 )
F_8 ( V_18 , V_5 -> V_69 , V_66 ) ;
F_15 ( V_10 -> V_13 , L_4 ,
V_66 , V_60 ) ;
if ( V_66 & ( ( 1 << V_5 -> V_72 ) << V_5 -> V_52 ) ) {
int V_72 = F_31 ( V_18 , V_5 -> V_73 ) ;
void T_1 * V_41 = V_10 -> V_41 ;
T_3 V_42 = F_14 ( V_41 , V_44 ) ;
int V_55 ;
V_55 = V_10 -> V_71 & V_51 ;
if ( V_55 ) {
V_10 -> V_71 &= ~ V_51 ;
V_10 -> V_30 -> V_31 -> V_32 = V_50 ;
F_4 ( V_2 ) ;
F_32 ( L_5 ) ;
} else if ( V_72 ) {
F_19 ( V_10 ) ;
V_10 -> V_30 -> V_31 -> V_74 = 1 ;
V_10 -> V_30 -> V_31 -> V_32 = V_45 ;
F_4 ( V_2 ) ;
} else {
V_10 -> V_75 = 0 ;
F_18 ( V_10 ) ;
V_10 -> V_30 -> V_31 -> V_74 = 0 ;
V_10 -> V_30 -> V_31 -> V_32 = V_33 ;
}
F_15 ( V_10 -> V_13 , L_6 ,
V_72 ? L_7 : L_8 ,
F_16 ( V_10 -> V_30 -> V_31 -> V_32 ) ,
V_55 ? L_9 : L_10 ,
V_42 ) ;
V_64 = V_76 ;
}
if ( V_10 -> V_68 || V_10 -> V_67 || V_10 -> V_71 )
V_64 |= F_33 ( V_10 ) ;
switch ( V_10 -> V_30 -> V_31 -> V_32 ) {
case V_33 :
case V_46 :
F_4 ( V_2 ) ;
break;
default:
break;
}
V_70:
F_26 ( & V_10 -> V_57 , V_54 ) ;
return V_64 ;
}
static int F_34 ( struct V_10 * V_10 , struct V_1 * V_2 )
{
struct V_77 * V_78 ;
struct V_77 * V_79 ;
char V_80 [ 128 ] ;
sprintf ( V_80 , L_11 , F_35 ( V_10 -> V_13 ) ) ;
V_78 = F_36 ( V_80 , NULL ) ;
if ( ! V_78 )
return - V_81 ;
V_2 -> V_82 = V_78 ;
V_2 -> V_83 . V_84 = V_85 ;
V_2 -> V_83 . V_86 = F_37 ( V_85 ) ;
V_2 -> V_83 . V_87 = V_10 -> V_19 ;
V_79 = F_38 ( L_12 , V_88 , V_78 , & V_2 -> V_83 ) ;
if ( ! V_79 ) {
F_39 ( V_78 ) ;
return - V_81 ;
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
struct V_89 * V_90 ;
T_2 V_91 , V_92 ;
int V_64 ;
V_90 = F_41 ( V_16 , V_93 , L_13 ) ;
V_18 = F_42 ( V_12 , V_90 ) ;
if ( F_43 ( V_18 ) )
return F_44 ( V_18 ) ;
V_10 -> V_19 = V_18 ;
V_10 -> V_30 = F_45 ( V_12 -> V_16 , L_14 , 0 ) ;
if ( F_43 ( V_10 -> V_30 ) )
return F_44 ( V_10 -> V_30 ) ;
V_10 -> V_94 = F_46 ( V_12 -> V_16 , L_15 ) ;
V_91 = F_31 ( V_18 , V_5 -> V_95 ) ;
if ( ! V_91 )
return - V_96 ;
F_47 ( V_10 -> V_30 ) ;
if ( F_43 ( V_10 -> V_94 ) ) {
V_10 -> V_94 = NULL ;
} else {
V_64 = F_48 ( V_10 -> V_94 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_49 ( V_10 -> V_94 ) ;
if ( V_64 ) {
F_50 ( V_10 -> V_94 ) ;
return V_64 ;
}
}
F_51 ( & V_2 -> V_7 , F_20 , ( unsigned long ) V_10 ) ;
F_8 ( V_18 , V_5 -> V_97 , ( 1 << V_5 -> V_98 ) ) ;
V_10 -> V_99 = F_30 ;
V_92 = F_31 ( V_18 , V_5 -> V_100 ) ;
V_92 &= ~ ( 1 << V_5 -> V_101 ) ;
F_8 ( V_10 -> V_19 , V_5 -> V_100 , V_92 ) ;
V_92 = F_14 ( V_10 -> V_41 , V_102 ) ;
if ( V_92 & V_103 ) {
V_2 -> V_104 = true ;
V_92 |= V_105 ;
F_17 ( V_10 -> V_41 , V_102 , V_92 ) ;
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
F_54 ( V_10 -> V_94 ) ;
F_50 ( V_10 -> V_94 ) ;
F_39 ( V_2 -> V_82 ) ;
return 0 ;
}
static int F_55 ( struct V_10 * V_10 , T_3 V_106 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
const struct V_17 * V_5 = V_2 -> V_5 ;
void T_1 * V_19 = V_10 -> V_19 ;
T_2 V_107 ;
V_107 = F_31 ( V_19 , V_5 -> V_106 ) ;
switch ( V_106 ) {
case V_108 :
V_107 &= ~ ( 1 << V_5 -> V_109 ) ;
V_107 |= ( 1 << V_5 -> V_110 ) ;
F_8 ( V_19 , V_5 -> V_106 , V_107 ) ;
F_8 ( V_19 , V_5 -> V_100 , 0x02 ) ;
break;
case V_111 :
V_107 |= ( 1 << V_5 -> V_109 ) ;
V_107 |= ( 1 << V_5 -> V_110 ) ;
F_8 ( V_19 , V_5 -> V_106 , V_107 ) ;
break;
case V_112 :
F_8 ( V_19 , V_5 -> V_100 , 0x02 ) ;
break;
default:
F_22 ( V_2 -> V_12 , L_16 , V_106 ) ;
return - V_113 ;
}
return 0 ;
}
static bool F_56 ( struct V_10 * V_10 )
{
T_3 V_114 ;
bool V_115 = false ;
V_114 = F_14 ( V_10 -> V_41 , V_102 ) ;
F_15 ( V_10 -> V_13 , L_17 ,
V_114 ) ;
F_15 ( V_10 -> V_13 , L_18 ,
V_114 & V_116 ? L_19 : L_20 ) ;
if ( V_114 & V_116 ) {
int V_117 = 10 ;
V_114 = F_14 ( V_10 -> V_41 , V_102 ) ;
V_114 |= V_118 ;
F_17 ( V_10 -> V_41 , V_102 , V_114 ) ;
F_15 ( V_10 -> V_13 , L_21 ) ;
do {
V_114 = F_14 ( V_10 -> V_41 , V_102 ) ;
F_57 ( 1 ) ;
} while ( ( V_114 & V_116 ) && V_117 -- );
if ( V_114 & V_116 ) {
F_15 ( V_10 -> V_13 , L_22 ,
V_114 ) ;
V_115 = true ;
}
} else {
V_115 = true ;
}
return V_115 ;
}
static int F_58 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_2 = F_12 ( V_12 -> V_16 ) ;
int V_115 = 0 ;
if ( V_2 -> V_104 )
V_115 = F_56 ( V_10 ) ;
else
V_115 = 1 ;
return V_115 ? 0 : - V_119 ;
}
static void F_59 ( struct V_120 * V_121 , T_5 V_122 , T_3 * V_123 )
{
void T_1 * V_124 = V_121 -> V_124 ;
if ( V_122 >= 4 ) {
F_60 ( V_124 , V_123 , V_122 >> 2 ) ;
V_123 += V_122 & ~ 0x03 ;
V_122 &= 0x03 ;
}
if ( V_122 > 0 ) {
T_2 V_92 = F_31 ( V_124 , 0 ) ;
memcpy ( V_123 , & V_92 , V_122 ) ;
}
}
static void F_61 ( struct V_125 * V_126 )
{
struct V_10 * V_10 = V_126 -> V_10 ;
struct V_1 * V_2 = F_12 ( V_10 -> V_13 -> V_16 ) ;
void T_1 * V_127 = V_2 -> V_127 ;
T_2 V_73 ;
V_73 = F_31 ( V_127 , V_128 ) ;
if ( V_73 & V_129 )
F_8 ( V_127 , V_128 , V_129 ) ;
}
static struct V_125 *
F_62 ( struct V_10 * V_10 , void T_1 * V_87 )
{
struct V_125 * V_13 ;
struct V_1 * V_2 = F_12 ( V_10 -> V_13 -> V_16 ) ;
void T_1 * V_127 = V_2 -> V_127 ;
V_13 = F_63 ( V_10 , V_87 ) ;
if ( F_64 ( V_13 ) )
return V_13 ;
F_8 ( V_127 , V_130 , V_129 ) ;
V_13 -> V_131 = F_61 ;
return V_13 ;
}
static void F_65 ( struct V_125 * V_126 )
{
struct V_10 * V_10 = V_126 -> V_10 ;
struct V_1 * V_2 = F_12 ( V_10 -> V_13 -> V_16 ) ;
void T_1 * V_127 = V_2 -> V_127 ;
F_8 ( V_127 , V_132 , V_129 ) ;
F_66 ( V_126 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
void T_1 * V_127 = V_2 -> V_127 ;
F_8 ( V_127 , V_132 , V_129 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
void T_1 * V_127 = V_2 -> V_127 ;
F_8 ( V_127 , V_130 , V_129 ) ;
}
static void F_67 ( struct V_1 * V_2 ) {}
static void F_68 ( struct V_1 * V_2 ) {}
static int F_69 ( struct V_133 * V_134 , const char * V_135 )
{
int V_64 ;
T_2 V_92 ;
V_64 = F_70 ( V_134 , V_135 , & V_92 ) ;
if ( V_64 )
return 0 ;
return V_92 ;
}
static int F_71 ( struct V_11 * V_12 )
{
enum V_136 V_106 ;
V_106 = F_72 ( V_12 ) ;
switch ( V_106 ) {
case V_137 :
return V_138 ;
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
struct V_89 V_145 [ 2 ] ;
struct V_89 * V_146 ;
struct V_11 * V_12 = & V_16 -> V_12 ;
struct V_147 * V_148 ;
struct V_14 * V_10 ;
struct V_133 * V_134 = V_16 -> V_12 . V_149 ;
int V_64 , V_92 ;
memset ( V_145 , 0 , sizeof( V_145 ) ) ;
V_146 = F_41 ( V_16 , V_93 , L_23 ) ;
if ( ! V_146 ) {
F_22 ( V_12 , L_24 ) ;
return - V_113 ;
}
V_145 [ 0 ] = * V_146 ;
V_146 = F_41 ( V_16 , V_150 , L_23 ) ;
if ( ! V_146 ) {
F_22 ( V_12 , L_25 ) ;
return - V_113 ;
}
V_145 [ 1 ] = * V_146 ;
V_10 = F_74 ( L_26 ,
( V_145 [ 0 ] . V_151 & 0xFFF ) == 0x400 ? 0 : 1 ) ;
if ( ! V_10 ) {
F_22 ( V_12 , L_27 ) ;
return - V_81 ;
}
V_10 -> V_12 . V_16 = V_12 ;
V_10 -> V_12 . V_152 = & V_153 ;
V_10 -> V_12 . V_154 = V_153 ;
V_2 -> V_10 = V_10 ;
V_64 = F_75 ( V_10 , V_145 ,
F_37 ( V_145 ) ) ;
if ( V_64 ) {
F_22 ( V_12 , L_28 ) ;
goto V_55;
}
V_148 = F_76 ( & V_16 -> V_12 , sizeof( * V_148 ) , V_155 ) ;
if ( ! V_148 ) {
V_64 = - V_81 ;
goto V_55;
}
V_144 . V_148 = V_148 ;
V_144 . V_156 = & V_157 ;
V_148 -> V_158 = F_69 ( V_134 , L_29 ) ;
V_148 -> V_159 = F_69 ( V_134 , L_30 ) ;
V_148 -> V_160 = 1 ;
V_144 . V_106 = F_71 ( V_12 ) ;
V_144 . V_161 = F_69 ( V_134 , L_31 ) / 2 ;
V_64 = F_70 ( V_134 , L_32 , & V_92 ) ;
if ( ! V_64 && V_92 )
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
V_64 = F_79 ( V_10 , & V_144 , sizeof( V_144 ) ) ;
if ( V_64 ) {
F_22 ( V_12 , L_35 ) ;
goto V_55;
}
V_64 = F_80 ( V_10 ) ;
if ( V_64 ) {
F_22 ( V_12 , L_36 ) ;
goto V_55;
}
return 0 ;
V_55:
F_81 ( V_10 ) ;
return V_64 ;
}
static T_4 F_82 ( int V_62 , void * V_168 )
{
struct V_1 * V_2 = V_168 ;
struct V_10 * V_10 = F_7 ( V_2 -> V_10 ) ;
if ( ! V_10 )
return V_65 ;
F_15 ( V_2 -> V_12 , L_37 ) ;
F_1 ( V_2 , 0 ) ;
return V_76 ;
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
int V_64 ;
if ( ! strcmp ( V_15 -> V_173 , L_26 ) )
return - V_96 ;
V_172 = F_87 ( V_174 , V_15 -> V_12 . V_149 ) ;
if ( ! V_172 ) {
F_22 ( & V_15 -> V_12 , L_40 ) ;
return - V_113 ;
}
V_5 = V_172 -> V_175 ;
if ( F_88 ( V_15 -> V_12 . V_149 , L_41 ) )
V_157 . V_176 = F_59 ;
V_2 = F_76 ( & V_15 -> V_12 , sizeof( * V_2 ) , V_155 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_12 = & V_15 -> V_12 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_127 = F_89 ( V_15 -> V_12 . V_16 -> V_149 , 0 ) ;
if ( ! V_2 -> V_127 )
return - V_177 ;
if ( F_72 ( & V_15 -> V_12 ) == V_139 ) {
V_64 = F_83 ( V_15 , V_2 ) ;
if ( V_64 )
goto V_178;
}
F_90 ( V_15 , V_2 ) ;
F_91 ( & V_15 -> V_12 ) ;
V_64 = F_73 ( V_2 , V_15 ) ;
if ( V_64 )
goto V_55;
return 0 ;
V_55:
F_92 ( & V_15 -> V_12 ) ;
V_178:
F_93 ( V_2 -> V_127 ) ;
return V_64 ;
}
static int F_94 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_95 ( V_2 -> V_10 ) ;
F_92 ( & V_15 -> V_12 ) ;
F_93 ( V_2 -> V_127 ) ;
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
V_2 -> V_180 . V_97 = F_31 ( V_179 , V_5 -> V_97 ) ;
V_2 -> V_180 . V_60 = F_31 ( V_179 , V_5 -> V_28 ) ;
V_2 -> V_180 . V_181 = F_31 ( V_179 , V_5 -> V_29 ) ;
V_2 -> V_180 . V_100 = F_31 ( V_179 , V_5 -> V_100 ) ;
V_2 -> V_180 . V_106 = F_31 ( V_179 , V_5 -> V_106 ) ;
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
F_8 ( V_179 , V_5 -> V_97 , V_2 -> V_180 . V_97 ) ;
F_8 ( V_179 , V_5 -> V_28 , V_2 -> V_180 . V_60 ) ;
F_8 ( V_179 , V_5 -> V_29 , V_2 -> V_180 . V_181 ) ;
F_8 ( V_179 , V_5 -> V_100 , V_2 -> V_180 . V_100 ) ;
F_8 ( V_179 , V_5 -> V_106 , V_2 -> V_180 . V_106 ) ;
F_8 ( V_179 , V_5 -> V_182 , V_2 -> V_180 . V_182 ) ;
F_8 ( V_179 , V_5 -> V_183 , V_2 -> V_180 . V_183 ) ;
if ( V_10 -> V_30 -> V_31 -> V_32 == V_33 &&
V_10 -> V_34 == V_35 )
F_1 ( V_2 , - 1 ) ;
return 0 ;
}
