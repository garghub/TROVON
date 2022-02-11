static inline T_1 F_1 ( const void T_2 * V_1 , unsigned V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline T_3 F_3 ( const void T_2 * V_1 , unsigned V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static inline void F_5 ( void T_2 * V_1 , unsigned V_2 , T_1 V_3 )
{
F_6 ( V_3 , V_1 + V_2 ) ;
}
static inline void F_7 ( void T_2 * V_1 , unsigned V_2 , T_3 V_3 )
{
F_8 ( V_3 , V_1 + V_2 ) ;
}
static void F_9 ( struct V_4 * V_4 , unsigned long V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
if ( V_5 == 0 )
V_5 = V_12 + F_11 ( 3 ) ;
if ( V_4 -> V_13 || ( V_4 -> V_14 == 0 &&
V_4 -> V_15 -> V_16 -> V_17 == V_18 ) ) {
F_12 ( V_4 -> V_8 , L_1 ,
F_13 ( V_4 -> V_15 -> V_16 -> V_17 ) ) ;
F_14 ( & V_10 -> V_19 ) ;
V_10 -> V_20 = V_12 ;
return;
}
if ( V_4 -> V_21 != V_22 )
return;
if ( ! V_4 -> V_23 . V_7 . V_24 )
return;
if ( F_15 ( V_10 -> V_20 , V_5 ) &&
F_16 ( & V_10 -> V_19 ) ) {
F_12 ( V_4 -> V_8 ,
L_2 ) ;
return;
}
V_10 -> V_20 = V_5 ;
F_12 ( V_4 -> V_8 , L_3 ,
F_13 ( V_4 -> V_15 -> V_16 -> V_17 ) ,
F_17 ( V_5 - V_12 ) ) ;
F_18 ( & V_10 -> V_19 , V_5 ) ;
}
static void F_19 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_25 * V_26 = F_20 ( V_7 -> V_11 ) ;
struct V_9 * V_10 = F_21 ( V_26 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
void T_2 * V_29 = V_4 -> V_30 ;
T_3 V_31 , V_32 ;
V_31 = ( ( V_4 -> V_31 & V_28 -> V_33 ) << V_28 -> V_34 ) |
( ( V_4 -> V_31 & V_28 -> V_35 ) << V_28 -> V_36 ) ;
V_32 = ( V_28 -> V_37 & ~ V_38 ) ;
F_7 ( V_29 , V_28 -> V_39 , V_31 ) ;
F_7 ( V_29 , V_28 -> V_40 , V_32 ) ;
if ( V_4 -> V_15 -> V_16 -> V_17 == V_41 &&
V_4 -> V_21 == V_22 )
F_18 ( & V_10 -> V_19 , V_12 +
F_11 ( V_28 -> V_42 ) ) ;
F_9 ( V_4 , 0 ) ;
}
static void F_22 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_25 * V_26 = F_20 ( V_7 -> V_11 ) ;
struct V_9 * V_10 = F_21 ( V_26 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
void T_2 * V_29 = V_4 -> V_30 ;
F_7 ( V_29 , V_28 -> V_43 , V_28 -> V_37 ) ;
F_7 ( V_29 , V_28 -> V_44 ,
V_28 -> V_45 | V_28 -> V_46 ) ;
F_5 ( V_4 -> V_47 , V_48 , 0 ) ;
}
static void F_23 ( unsigned long V_49 )
{
struct V_4 * V_4 = ( void * ) V_49 ;
void T_2 * V_47 = V_4 -> V_47 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
T_1 V_50 ;
unsigned long V_51 ;
int V_52 = 0 ;
V_50 = F_1 ( V_47 , V_48 ) ;
F_12 ( V_4 -> V_8 , L_4 , V_50 ,
F_13 ( V_4 -> V_15 -> V_16 -> V_17 ) ) ;
F_24 ( & V_4 -> V_53 , V_51 ) ;
switch ( V_4 -> V_15 -> V_16 -> V_17 ) {
case V_18 :
F_5 ( V_4 -> V_47 , V_48 , 0 ) ;
V_52 = 1 ;
case V_54 :
case V_41 :
if ( V_50 & V_55 ) {
V_4 -> V_15 -> V_16 -> V_17 = V_41 ;
F_25 ( V_4 ) ;
} else {
V_4 -> V_15 -> V_16 -> V_17 = V_54 ;
F_26 ( V_4 ) ;
}
if ( ! ( V_50 & V_56 ) && ! V_52 )
F_5 ( V_47 , V_48 , V_56 ) ;
F_18 ( & V_10 -> V_19 , V_12 +
F_11 ( V_28 -> V_42 ) ) ;
break;
case V_57 :
V_4 -> V_15 -> V_16 -> V_17 = V_58 ;
F_7 ( V_4 -> V_30 , V_28 -> V_40 ,
V_59 << V_28 -> V_60 ) ;
break;
default:
break;
}
F_27 ( & V_4 -> V_53 , V_51 ) ;
}
static T_4 F_28 ( int V_61 , void * V_62 )
{
struct V_4 * V_4 = V_62 ;
void T_2 * V_29 = V_4 -> V_30 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
unsigned long V_51 ;
T_4 V_63 = V_64 ;
T_3 V_65 , V_66 ;
F_24 ( & V_4 -> V_53 , V_51 ) ;
V_65 = F_3 ( V_29 , V_28 -> V_67 ) ;
V_4 -> V_68 = ( V_65 & V_28 -> V_46 ) >> V_28 -> V_36 ;
V_4 -> V_69 = ( V_65 & V_28 -> V_45 ) >> V_28 -> V_34 ;
if ( V_65 )
F_7 ( V_29 , V_28 -> V_67 , V_65 ) ;
V_66 = F_3 ( V_29 , V_28 -> V_70 ) ;
if ( ! V_66 && ! V_65 )
goto V_71;
V_4 -> V_72 = ( V_66 & V_28 -> V_37 ) >> V_28 -> V_60 ;
if ( V_66 )
F_7 ( V_29 , V_28 -> V_70 , V_66 ) ;
F_12 ( V_4 -> V_8 , L_5 ,
V_66 , V_65 ) ;
if ( V_66 & ( ( 1 << V_28 -> V_73 ) << V_28 -> V_60 ) ) {
int V_73 = F_3 ( V_29 , V_28 -> V_74 ) ;
void T_2 * V_47 = V_4 -> V_47 ;
T_1 V_50 = F_1 ( V_47 , V_48 ) ;
int V_75 ;
V_75 = V_4 -> V_72 & V_59 ;
if ( V_75 ) {
V_4 -> V_72 &= ~ V_59 ;
V_4 -> V_15 -> V_16 -> V_17 = V_57 ;
F_18 ( & V_10 -> V_19 , V_12 +
F_11 ( V_28 -> V_42 ) ) ;
F_29 ( L_6 ) ;
} else if ( V_73 ) {
F_26 ( V_4 ) ;
V_4 -> V_15 -> V_16 -> V_76 = 1 ;
V_4 -> V_15 -> V_16 -> V_17 = V_58 ;
F_14 ( & V_10 -> V_19 ) ;
} else {
V_4 -> V_13 = 0 ;
F_25 ( V_4 ) ;
V_4 -> V_15 -> V_16 -> V_76 = 0 ;
V_4 -> V_15 -> V_16 -> V_17 = V_41 ;
}
F_12 ( V_4 -> V_8 , L_7 ,
V_73 ? L_8 : L_9 ,
F_13 ( V_4 -> V_15 -> V_16 -> V_17 ) ,
V_75 ? L_10 : L_11 ,
V_50 ) ;
V_63 = V_77 ;
}
if ( V_4 -> V_69 || V_4 -> V_68 || V_4 -> V_72 )
V_63 |= F_30 ( V_4 ) ;
if ( V_4 -> V_15 -> V_16 -> V_17 == V_41 &&
V_4 -> V_21 == V_22 )
F_18 ( & V_10 -> V_19 , V_12 +
F_11 ( V_28 -> V_42 ) ) ;
V_71:
F_27 ( & V_4 -> V_53 , V_51 ) ;
return V_63 ;
}
static int F_31 ( struct V_4 * V_4 , struct V_9 * V_10 )
{
struct V_78 * V_79 ;
struct V_78 * V_80 ;
char V_81 [ 128 ] ;
sprintf ( V_81 , L_12 , F_32 ( V_4 -> V_8 ) ) ;
V_79 = F_33 ( V_81 , NULL ) ;
if ( ! V_79 )
return - V_82 ;
V_10 -> V_83 = V_79 ;
V_10 -> V_84 . V_85 = V_86 ;
V_10 -> V_84 . V_87 = F_34 ( V_86 ) ;
V_10 -> V_84 . V_88 = V_4 -> V_30 ;
V_80 = F_35 ( L_13 , V_89 , V_79 , & V_10 -> V_84 ) ;
if ( ! V_80 ) {
F_36 ( V_79 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_37 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
struct V_25 * V_11 = F_20 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
void T_2 * V_29 ;
struct V_90 * V_91 ;
T_3 V_92 , V_93 ;
int V_63 ;
V_91 = F_38 ( V_11 , V_94 , L_14 ) ;
V_29 = F_39 ( V_7 , V_91 ) ;
if ( F_40 ( V_29 ) )
return F_41 ( V_29 ) ;
V_4 -> V_30 = V_29 ;
V_4 -> V_15 = F_42 ( V_7 -> V_11 , L_15 , 0 ) ;
if ( F_40 ( V_4 -> V_15 ) )
return F_41 ( V_4 -> V_15 ) ;
V_4 -> V_95 = F_43 ( V_7 -> V_11 , L_16 ) ;
V_92 = F_3 ( V_29 , V_28 -> V_96 ) ;
if ( ! V_92 )
return - V_97 ;
F_44 ( V_4 -> V_15 ) ;
if ( F_40 ( V_4 -> V_95 ) ) {
V_4 -> V_95 = NULL ;
} else {
V_63 = F_45 ( V_4 -> V_95 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_46 ( V_4 -> V_95 ) ;
if ( V_63 ) {
F_47 ( V_4 -> V_95 ) ;
return V_63 ;
}
}
F_48 ( & V_10 -> V_19 , F_23 , ( unsigned long ) V_4 ) ;
F_7 ( V_29 , V_28 -> V_98 , ( 1 << V_28 -> V_99 ) ) ;
V_4 -> V_100 = F_28 ;
V_93 = F_3 ( V_29 , V_28 -> V_101 ) ;
V_93 &= ~ ( 1 << V_28 -> V_102 ) ;
F_7 ( V_4 -> V_30 , V_28 -> V_101 , V_93 ) ;
V_93 = F_1 ( V_4 -> V_47 , V_103 ) ;
if ( V_93 & V_104 ) {
V_10 -> V_105 = true ;
V_93 |= V_106 ;
F_5 ( V_4 -> V_47 , V_103 , V_93 ) ;
}
return F_31 ( V_4 , V_10 ) ;
}
static int F_49 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
F_50 ( & V_10 -> V_19 ) ;
F_51 ( V_4 -> V_15 ) ;
F_52 ( V_4 -> V_95 ) ;
F_47 ( V_4 -> V_95 ) ;
F_36 ( V_10 -> V_83 ) ;
return 0 ;
}
static int F_53 ( struct V_4 * V_4 , T_1 V_107 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
void T_2 * V_30 = V_4 -> V_30 ;
T_3 V_108 ;
V_108 = F_3 ( V_30 , V_28 -> V_107 ) ;
switch ( V_107 ) {
case V_109 :
V_108 &= ~ ( 1 << V_28 -> V_110 ) ;
V_108 |= ( 1 << V_28 -> V_111 ) ;
F_7 ( V_30 , V_28 -> V_107 , V_108 ) ;
F_7 ( V_30 , V_28 -> V_101 , 0x02 ) ;
break;
case V_112 :
V_108 |= ( 1 << V_28 -> V_110 ) ;
V_108 |= ( 1 << V_28 -> V_111 ) ;
F_7 ( V_30 , V_28 -> V_107 , V_108 ) ;
break;
case V_113 :
F_7 ( V_30 , V_28 -> V_101 , 0x02 ) ;
break;
default:
F_54 ( V_10 -> V_7 , L_17 , V_107 ) ;
return - V_114 ;
}
return 0 ;
}
static bool F_55 ( struct V_4 * V_4 )
{
T_1 V_115 ;
bool V_116 = false ;
V_115 = F_1 ( V_4 -> V_47 , V_103 ) ;
F_12 ( V_4 -> V_8 , L_18 ,
V_115 ) ;
F_12 ( V_4 -> V_8 , L_19 ,
V_115 & V_117 ? L_20 : L_21 ) ;
if ( V_115 & V_117 ) {
int V_5 = 10 ;
V_115 = F_1 ( V_4 -> V_47 , V_103 ) ;
V_115 |= V_118 ;
F_5 ( V_4 -> V_47 , V_103 , V_115 ) ;
F_12 ( V_4 -> V_8 , L_22 ) ;
do {
V_115 = F_1 ( V_4 -> V_47 , V_103 ) ;
F_56 ( 1 ) ;
} while ( ( V_115 & V_117 ) && V_5 -- );
if ( V_115 & V_117 ) {
F_12 ( V_4 -> V_8 , L_23 ,
V_115 ) ;
V_116 = true ;
}
} else {
V_116 = true ;
}
return V_116 ;
}
static int F_57 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
int V_116 = 0 ;
if ( V_10 -> V_105 )
V_116 = F_55 ( V_4 ) ;
else
V_116 = 1 ;
return V_116 ? 0 : - V_119 ;
}
static void F_58 ( struct V_120 * V_121 , T_5 V_122 , T_1 * V_123 )
{
void T_2 * V_124 = V_121 -> V_124 ;
if ( V_122 >= 4 ) {
F_59 ( V_124 , V_123 , V_122 >> 2 ) ;
V_123 += V_122 & ~ 0x03 ;
V_122 &= 0x03 ;
}
if ( V_122 > 0 ) {
T_3 V_93 = F_60 ( V_124 , 0 ) ;
memcpy ( V_123 , & V_93 , V_122 ) ;
}
}
static int F_61 ( struct V_125 * V_126 , const char * V_127 )
{
int V_63 ;
T_3 V_93 ;
V_63 = F_62 ( V_126 , V_127 , & V_93 ) ;
if ( V_63 )
return 0 ;
return V_93 ;
}
static int F_63 ( struct V_6 * V_7 )
{
enum V_128 V_107 ;
V_107 = F_64 ( V_7 ) ;
switch ( V_107 ) {
case V_129 :
return V_130 ;
case V_131 :
return V_132 ;
case V_133 :
case V_134 :
default:
return V_22 ;
}
}
static int F_65 ( struct V_9 * V_10 ,
struct V_25 * V_11 )
{
struct V_135 V_136 ;
struct V_90 V_137 [ 2 ] ;
struct V_90 * V_138 ;
struct V_6 * V_7 = & V_11 -> V_7 ;
struct V_139 * V_140 ;
struct V_25 * V_4 ;
struct V_125 * V_126 = V_11 -> V_7 . V_141 ;
int V_63 , V_93 ;
memset ( V_137 , 0 , sizeof( V_137 ) ) ;
V_138 = F_38 ( V_11 , V_94 , L_24 ) ;
if ( ! V_138 ) {
F_54 ( V_7 , L_25 ) ;
return - V_114 ;
}
V_137 [ 0 ] = * V_138 ;
V_138 = F_38 ( V_11 , V_142 , L_24 ) ;
if ( ! V_138 ) {
F_54 ( V_7 , L_26 ) ;
return - V_114 ;
}
V_137 [ 1 ] = * V_138 ;
V_4 = F_66 ( L_27 , V_143 ) ;
if ( ! V_4 ) {
F_54 ( V_7 , L_28 ) ;
return - V_82 ;
}
V_4 -> V_7 . V_11 = V_7 ;
V_4 -> V_7 . V_144 = & V_145 ;
V_4 -> V_7 . V_146 = V_145 ;
V_10 -> V_4 = V_4 ;
V_63 = F_67 ( V_4 , V_137 ,
F_34 ( V_137 ) ) ;
if ( V_63 ) {
F_54 ( V_7 , L_29 ) ;
goto V_75;
}
V_140 = F_68 ( & V_11 -> V_7 , sizeof( * V_140 ) , V_147 ) ;
if ( ! V_140 ) {
V_63 = - V_82 ;
goto V_75;
}
V_136 . V_140 = V_140 ;
V_136 . V_148 = & V_149 ;
V_140 -> V_150 = F_61 ( V_126 , L_30 ) ;
V_140 -> V_151 = F_61 ( V_126 , L_31 ) ;
V_140 -> V_152 = 1 ;
V_136 . V_107 = F_63 ( V_7 ) ;
V_136 . V_153 = F_61 ( V_126 , L_32 ) / 2 ;
V_63 = F_62 ( V_126 , L_33 , & V_93 ) ;
if ( ! V_63 && V_93 )
V_140 -> V_154 = true ;
V_140 -> V_155 = F_69 ( & V_11 -> V_7 ) ;
switch ( V_140 -> V_155 ) {
case V_156 :
case V_157 :
break;
case V_158 :
F_70 ( V_7 , L_34
L_35 ) ;
default:
V_140 -> V_155 = V_159 ;
}
V_63 = F_71 ( V_4 , & V_136 , sizeof( V_136 ) ) ;
if ( V_63 ) {
F_54 ( V_7 , L_36 ) ;
goto V_75;
}
V_63 = F_72 ( V_4 ) ;
if ( V_63 ) {
F_54 ( V_7 , L_37 ) ;
goto V_75;
}
return 0 ;
V_75:
F_73 ( V_4 ) ;
return V_63 ;
}
static int F_74 ( struct V_25 * V_26 )
{
const struct V_160 * V_161 ;
const struct V_27 * V_28 ;
struct V_9 * V_10 ;
int V_63 ;
if ( ! strcmp ( V_26 -> V_162 , L_27 ) )
return - V_97 ;
V_161 = F_75 ( V_163 , V_26 -> V_7 . V_141 ) ;
if ( ! V_161 ) {
F_54 ( & V_26 -> V_7 , L_38 ) ;
return - V_114 ;
}
V_28 = V_161 -> V_3 ;
if ( F_76 ( V_26 -> V_7 . V_141 , L_39 ) )
V_149 . V_164 = F_58 ;
V_10 = F_68 ( & V_26 -> V_7 , sizeof( * V_10 ) , V_147 ) ;
if ( ! V_10 )
return - V_82 ;
V_10 -> V_7 = & V_26 -> V_7 ;
V_10 -> V_28 = V_28 ;
F_77 ( V_26 , V_10 ) ;
F_78 ( & V_26 -> V_7 ) ;
V_63 = F_79 ( & V_26 -> V_7 ) ;
if ( V_63 < 0 ) {
F_54 ( & V_26 -> V_7 , L_40 ) ;
goto V_165;
}
V_63 = F_65 ( V_10 , V_26 ) ;
if ( V_63 )
goto V_166;
return 0 ;
V_166:
F_80 ( & V_26 -> V_7 ) ;
V_165:
F_81 ( & V_26 -> V_7 ) ;
return V_63 ;
}
static int F_82 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_21 ( V_26 ) ;
F_83 ( V_10 -> V_4 ) ;
F_80 ( & V_26 -> V_7 ) ;
F_81 ( & V_26 -> V_7 ) ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_10 ( V_7 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
struct V_4 * V_4 = F_21 ( V_10 -> V_4 ) ;
void T_2 * V_167 ;
F_50 ( & V_10 -> V_19 ) ;
if ( ! V_4 )
return 0 ;
V_167 = V_4 -> V_30 ;
V_10 -> V_168 . V_98 = F_3 ( V_167 , V_28 -> V_98 ) ;
V_10 -> V_168 . V_65 = F_3 ( V_167 , V_28 -> V_39 ) ;
V_10 -> V_168 . V_169 = F_3 ( V_167 , V_28 -> V_40 ) ;
V_10 -> V_168 . V_101 = F_3 ( V_167 , V_28 -> V_101 ) ;
V_10 -> V_168 . V_107 = F_3 ( V_167 , V_28 -> V_107 ) ;
V_10 -> V_168 . V_170 = F_3 ( V_167 , V_28 -> V_170 ) ;
V_10 -> V_168 . V_171 = F_3 ( V_167 , V_28 -> V_171 ) ;
return 0 ;
}
static int F_85 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_10 ( V_7 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
struct V_4 * V_4 = F_21 ( V_10 -> V_4 ) ;
void T_2 * V_167 ;
if ( ! V_4 )
return 0 ;
V_167 = V_4 -> V_30 ;
F_7 ( V_167 , V_28 -> V_98 , V_10 -> V_168 . V_98 ) ;
F_7 ( V_167 , V_28 -> V_39 , V_10 -> V_168 . V_65 ) ;
F_7 ( V_167 , V_28 -> V_40 , V_10 -> V_168 . V_169 ) ;
F_7 ( V_167 , V_28 -> V_101 , V_10 -> V_168 . V_101 ) ;
F_7 ( V_167 , V_28 -> V_107 , V_10 -> V_168 . V_107 ) ;
F_7 ( V_167 , V_28 -> V_170 , V_10 -> V_168 . V_170 ) ;
F_7 ( V_167 , V_28 -> V_171 , V_10 -> V_168 . V_171 ) ;
if ( V_4 -> V_15 -> V_16 -> V_17 == V_41 &&
V_4 -> V_21 == V_22 )
F_18 ( & V_10 -> V_19 , V_12 +
F_11 ( V_28 -> V_42 ) ) ;
return 0 ;
}
