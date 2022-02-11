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
F_7 ( V_29 , V_28 -> V_40 ,
( 1 << V_28 -> V_41 ) << V_28 -> V_42 ) ;
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
case V_55 :
if ( V_50 & V_56 ) {
V_4 -> V_15 -> V_16 -> V_17 = V_55 ;
F_25 ( V_4 ) ;
} else {
V_4 -> V_15 -> V_16 -> V_17 = V_54 ;
F_26 ( V_4 ) ;
}
if ( ! ( V_50 & V_57 ) && ! V_52 )
F_5 ( V_47 , V_48 , V_57 ) ;
F_18 ( & V_10 -> V_19 , V_12 + V_28 -> V_58 * V_59 ) ;
break;
case V_60 :
V_4 -> V_15 -> V_16 -> V_17 = V_61 ;
F_7 ( V_4 -> V_30 , V_28 -> V_40 ,
V_62 << V_28 -> V_42 ) ;
break;
default:
break;
}
F_27 ( & V_4 -> V_53 , V_51 ) ;
}
static T_4 F_28 ( int V_63 , void * V_64 )
{
struct V_4 * V_4 = V_64 ;
void T_2 * V_29 = V_4 -> V_30 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
unsigned long V_51 ;
T_4 V_65 = V_66 ;
T_3 V_67 , V_68 ;
F_24 ( & V_4 -> V_53 , V_51 ) ;
V_67 = F_3 ( V_29 , V_28 -> V_69 ) ;
V_4 -> V_70 = ( V_67 & V_28 -> V_46 ) >> V_28 -> V_36 ;
V_4 -> V_71 = ( V_67 & V_28 -> V_45 ) >> V_28 -> V_34 ;
if ( V_67 )
F_7 ( V_29 , V_28 -> V_69 , V_67 ) ;
V_68 = F_3 ( V_29 , V_28 -> V_72 ) ;
if ( ! V_68 && ! V_67 )
goto V_73;
V_4 -> V_74 = ( V_68 & V_28 -> V_37 ) >> V_28 -> V_42 ;
if ( V_68 )
F_7 ( V_29 , V_28 -> V_72 , V_68 ) ;
F_12 ( V_4 -> V_8 , L_5 ,
V_68 , V_67 ) ;
if ( F_29 ( V_4 ) && V_68 & V_75 ) {
F_30 ( L_6 ) ;
V_4 -> V_74 = V_75 | V_76 ;
V_4 -> V_71 = V_4 -> V_70 = 0 ;
}
if ( V_68 & ( ( 1 << V_28 -> V_41 ) << V_28 -> V_42 ) ) {
int V_41 = F_3 ( V_29 , V_28 -> V_77 ) ;
void T_2 * V_47 = V_4 -> V_47 ;
T_1 V_50 = F_1 ( V_47 , V_48 ) ;
int V_78 ;
V_78 = V_4 -> V_74 & V_62 ;
if ( V_78 ) {
V_4 -> V_74 &= ~ V_62 ;
V_4 -> V_15 -> V_16 -> V_17 = V_60 ;
F_18 ( & V_10 -> V_19 ,
V_12 + V_28 -> V_58 * V_59 ) ;
F_31 ( L_7 ) ;
} else if ( V_41 ) {
F_26 ( V_4 ) ;
V_4 -> V_15 -> V_16 -> V_79 = 1 ;
V_4 -> V_15 -> V_16 -> V_17 = V_61 ;
F_14 ( & V_10 -> V_19 ) ;
} else {
V_4 -> V_13 = 0 ;
F_25 ( V_4 ) ;
V_4 -> V_15 -> V_16 -> V_79 = 0 ;
V_4 -> V_15 -> V_16 -> V_17 = V_55 ;
}
F_12 ( V_4 -> V_8 , L_8 ,
V_41 ? L_9 : L_10 ,
F_13 ( V_4 -> V_15 -> V_16 -> V_17 ) ,
V_78 ? L_11 : L_12 ,
V_50 ) ;
V_65 = V_80 ;
}
if ( V_4 -> V_71 || V_4 -> V_70 || V_4 -> V_74 )
V_65 |= F_32 ( V_4 ) ;
if ( V_4 -> V_15 -> V_16 -> V_17 == V_55 &&
V_4 -> V_21 == V_22 )
F_18 ( & V_10 -> V_19 , V_12 + V_28 -> V_58 * V_59 ) ;
V_73:
F_27 ( & V_4 -> V_53 , V_51 ) ;
return V_65 ;
}
static int F_33 ( struct V_4 * V_4 , struct V_9 * V_10 )
{
struct V_81 * V_82 ;
struct V_81 * V_83 ;
char V_84 [ 128 ] ;
sprintf ( V_84 , L_13 , F_34 ( V_4 -> V_8 ) ) ;
V_82 = F_35 ( V_84 , NULL ) ;
if ( ! V_82 )
return - V_85 ;
V_10 -> V_86 = V_82 ;
V_10 -> V_87 . V_88 = V_89 ;
V_10 -> V_87 . V_90 = F_36 ( V_89 ) ;
V_10 -> V_87 . V_91 = V_4 -> V_30 ;
V_83 = F_37 ( L_14 , V_92 , V_82 , & V_10 -> V_87 ) ;
if ( ! V_83 ) {
F_38 ( V_82 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_39 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
struct V_25 * V_11 = F_20 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
void T_2 * V_29 ;
struct V_93 * V_94 ;
T_3 V_95 , V_96 ;
int V_65 ;
V_94 = F_40 ( V_11 , V_97 , L_15 ) ;
V_29 = F_41 ( V_7 , V_94 ) ;
if ( F_42 ( V_29 ) )
return F_43 ( V_29 ) ;
V_4 -> V_30 = V_29 ;
V_4 -> V_15 = F_44 ( V_7 , L_16 , 0 ) ;
if ( F_42 ( V_4 -> V_15 ) )
return F_43 ( V_4 -> V_15 ) ;
V_4 -> V_98 = F_45 ( V_7 -> V_11 , L_17 ) ;
V_95 = F_3 ( V_29 , V_28 -> V_99 ) ;
if ( ! V_95 )
return - V_100 ;
F_46 ( V_4 -> V_15 ) ;
if ( F_42 ( V_4 -> V_98 ) ) {
V_4 -> V_98 = NULL ;
} else {
V_65 = F_47 ( V_4 -> V_98 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_48 ( V_4 -> V_98 ) ;
if ( V_65 ) {
F_49 ( V_4 -> V_98 ) ;
return V_65 ;
}
}
F_50 ( & V_10 -> V_19 , F_23 , ( unsigned long ) V_4 ) ;
F_7 ( V_29 , V_28 -> V_101 , ( 1 << V_28 -> V_102 ) ) ;
V_4 -> V_103 = F_28 ;
V_96 = F_3 ( V_29 , V_28 -> V_104 ) ;
V_96 &= ~ ( 1 << V_28 -> V_105 ) ;
F_7 ( V_4 -> V_30 , V_28 -> V_104 , V_96 ) ;
V_96 = F_1 ( V_4 -> V_47 , V_106 ) ;
if ( V_96 == V_107 ) {
V_10 -> V_108 = true ;
V_96 |= V_109 ;
F_5 ( V_4 -> V_47 , V_106 , V_96 ) ;
}
V_65 = F_33 ( V_4 , V_10 ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
F_52 ( & V_10 -> V_19 ) ;
F_53 ( V_4 -> V_15 ) ;
F_54 ( V_4 -> V_98 ) ;
F_49 ( V_4 -> V_98 ) ;
F_38 ( V_10 -> V_86 ) ;
return 0 ;
}
static int F_55 ( struct V_4 * V_4 , T_1 V_110 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
void T_2 * V_30 = V_4 -> V_30 ;
T_3 V_111 ;
V_111 = F_3 ( V_30 , V_28 -> V_110 ) ;
switch ( V_110 ) {
case V_112 :
V_111 &= ~ ( 1 << V_28 -> V_113 ) ;
V_111 |= ( 1 << V_28 -> V_114 ) ;
F_7 ( V_30 , V_28 -> V_110 , V_111 ) ;
F_7 ( V_30 , V_28 -> V_104 , 0x02 ) ;
break;
case V_115 :
V_111 |= ( 1 << V_28 -> V_113 ) ;
V_111 |= ( 1 << V_28 -> V_114 ) ;
F_7 ( V_30 , V_28 -> V_110 , V_111 ) ;
break;
case V_116 :
F_7 ( V_30 , V_28 -> V_104 , 0x02 ) ;
break;
default:
F_56 ( V_10 -> V_7 , L_18 , V_110 ) ;
return - V_117 ;
}
return 0 ;
}
static bool F_57 ( struct V_4 * V_4 )
{
T_1 V_118 ;
bool V_119 = false ;
V_118 = F_1 ( V_4 -> V_47 , V_106 ) ;
F_12 ( V_4 -> V_8 , L_19 ,
V_118 ) ;
F_12 ( V_4 -> V_8 , L_20 ,
V_118 & V_120 ? L_21 : L_22 ) ;
if ( V_118 & V_120 ) {
int V_5 = 10 ;
V_118 = F_1 ( V_4 -> V_47 , V_106 ) ;
V_118 |= V_121 ;
F_5 ( V_4 -> V_47 , V_106 , V_118 ) ;
F_12 ( V_4 -> V_8 , L_23 ) ;
do {
V_118 = F_1 ( V_4 -> V_47 , V_106 ) ;
F_58 ( 1 ) ;
} while ( ( V_118 & V_120 ) && V_5 -- );
if ( V_118 & V_120 ) {
F_12 ( V_4 -> V_8 , L_24 ,
V_118 ) ;
V_119 = true ;
}
} else {
V_119 = true ;
}
return V_119 ;
}
static int F_59 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
int V_119 = 0 , error ;
if ( V_10 -> V_108 )
V_119 = F_57 ( V_4 ) ;
if ( V_119 || ! V_10 -> V_108 ) {
F_60 ( V_4 -> V_8 , L_25 ) ;
F_7 ( V_4 -> V_30 , V_28 -> V_101 , ( 1 << V_28 -> V_102 ) ) ;
F_61 ( 100 , 200 ) ;
F_53 ( V_4 -> V_15 ) ;
error = F_54 ( V_4 -> V_98 ) ;
if ( error )
F_56 ( V_7 , L_26 , error ) ;
F_61 ( 100 , 200 ) ;
F_46 ( V_4 -> V_15 ) ;
error = F_48 ( V_4 -> V_98 ) ;
if ( error )
F_56 ( V_7 , L_27 , error ) ;
V_119 = 1 ;
}
return ! V_119 ;
}
static int F_62 ( struct V_122 * V_123 , const char * V_124 )
{
int V_65 ;
T_3 V_96 ;
V_65 = F_63 ( V_123 , V_124 , & V_96 ) ;
if ( V_65 )
return 0 ;
return V_96 ;
}
static int F_64 ( struct V_6 * V_7 )
{
enum V_125 V_110 ;
V_110 = F_65 ( V_7 -> V_126 ) ;
switch ( V_110 ) {
case V_127 :
return V_128 ;
case V_129 :
return V_130 ;
case V_131 :
case V_132 :
default:
return V_22 ;
}
}
static int F_66 ( struct V_9 * V_10 ,
struct V_25 * V_11 )
{
struct V_133 V_134 ;
struct V_93 V_135 [ 2 ] ;
struct V_93 * V_136 ;
struct V_6 * V_7 = & V_11 -> V_7 ;
struct V_137 * V_138 ;
struct V_25 * V_4 ;
struct V_122 * V_123 = V_11 -> V_7 . V_126 ;
int V_65 , V_96 ;
memset ( V_135 , 0 , sizeof( V_135 ) ) ;
V_136 = F_40 ( V_11 , V_97 , L_28 ) ;
if ( ! V_136 ) {
F_56 ( V_7 , L_29 ) ;
return - V_117 ;
}
V_135 [ 0 ] = * V_136 ;
V_136 = F_40 ( V_11 , V_139 , L_28 ) ;
if ( ! V_136 ) {
F_56 ( V_7 , L_30 ) ;
return - V_117 ;
}
V_135 [ 1 ] = * V_136 ;
V_4 = F_67 ( L_31 , V_140 ) ;
if ( ! V_4 ) {
F_56 ( V_7 , L_32 ) ;
return - V_85 ;
}
V_4 -> V_7 . V_11 = V_7 ;
V_4 -> V_7 . V_141 = & V_142 ;
V_4 -> V_7 . V_143 = V_142 ;
V_4 -> V_7 . V_126 = F_68 ( V_123 ) ;
V_10 -> V_4 = V_4 ;
V_65 = F_69 ( V_4 , V_135 ,
F_36 ( V_135 ) ) ;
if ( V_65 ) {
F_56 ( V_7 , L_33 ) ;
goto V_78;
}
V_138 = F_70 ( & V_11 -> V_7 , sizeof( * V_138 ) , V_144 ) ;
if ( ! V_138 ) {
V_65 = - V_85 ;
goto V_78;
}
V_134 . V_138 = V_138 ;
V_134 . V_145 = & V_146 ;
V_138 -> V_147 = F_62 ( V_123 , L_34 ) ;
V_138 -> V_148 = F_62 ( V_123 , L_35 ) ;
V_138 -> V_149 = 1 ;
V_134 . V_110 = F_64 ( V_7 ) ;
V_134 . V_150 = F_62 ( V_123 , L_36 ) / 2 ;
V_65 = F_63 ( V_123 , L_37 , & V_96 ) ;
if ( ! V_65 && V_96 )
V_138 -> V_151 = true ;
V_65 = F_71 ( V_4 , & V_134 , sizeof( V_134 ) ) ;
if ( V_65 ) {
F_56 ( V_7 , L_38 ) ;
goto V_78;
}
V_65 = F_72 ( V_4 ) ;
if ( V_65 ) {
F_56 ( V_7 , L_39 ) ;
goto V_78;
}
return 0 ;
V_78:
F_73 ( V_4 ) ;
return V_65 ;
}
static int F_74 ( struct V_25 * V_26 )
{
const struct V_152 * V_153 ;
const struct V_27 * V_28 ;
struct V_9 * V_10 ;
int V_65 ;
if ( ! strcmp ( V_26 -> V_154 , L_31 ) )
return - V_100 ;
V_153 = F_75 ( V_155 , V_26 -> V_7 . V_126 ) ;
if ( ! V_153 ) {
F_56 ( & V_26 -> V_7 , L_40 ) ;
return - V_117 ;
}
V_28 = V_153 -> V_3 ;
V_10 = F_70 ( & V_26 -> V_7 , sizeof( * V_10 ) , V_144 ) ;
if ( ! V_10 )
return - V_85 ;
V_10 -> V_7 = & V_26 -> V_7 ;
V_10 -> V_28 = V_28 ;
F_76 ( V_26 , V_10 ) ;
F_77 ( & V_26 -> V_7 ) ;
V_65 = F_78 ( & V_26 -> V_7 ) ;
if ( V_65 < 0 ) {
F_56 ( & V_26 -> V_7 , L_41 ) ;
goto V_156;
}
V_65 = F_66 ( V_10 , V_26 ) ;
if ( V_65 )
goto V_157;
return 0 ;
V_157:
F_79 ( & V_26 -> V_7 ) ;
V_156:
F_80 ( & V_26 -> V_7 ) ;
return V_65 ;
}
static int F_81 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_21 ( V_26 ) ;
F_82 ( V_10 -> V_4 ) ;
F_79 ( & V_26 -> V_7 ) ;
F_80 ( & V_26 -> V_7 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_10 ( V_7 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
struct V_4 * V_4 = F_21 ( V_10 -> V_4 ) ;
void T_2 * V_158 ;
F_52 ( & V_10 -> V_19 ) ;
if ( ! V_4 )
return 0 ;
V_158 = V_4 -> V_30 ;
V_10 -> V_159 . V_101 = F_3 ( V_158 , V_28 -> V_101 ) ;
V_10 -> V_159 . V_67 = F_3 ( V_158 , V_28 -> V_39 ) ;
V_10 -> V_159 . V_160 = F_3 ( V_158 , V_28 -> V_40 ) ;
V_10 -> V_159 . V_104 = F_3 ( V_158 , V_28 -> V_104 ) ;
V_10 -> V_159 . V_110 = F_3 ( V_158 , V_28 -> V_110 ) ;
V_10 -> V_159 . V_161 = F_3 ( V_158 , V_28 -> V_161 ) ;
V_10 -> V_159 . V_162 = F_3 ( V_158 , V_28 -> V_162 ) ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_10 ( V_7 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
struct V_4 * V_4 = F_21 ( V_10 -> V_4 ) ;
void T_2 * V_158 ;
if ( ! V_4 )
return 0 ;
V_158 = V_4 -> V_30 ;
F_7 ( V_158 , V_28 -> V_101 , V_10 -> V_159 . V_101 ) ;
F_7 ( V_158 , V_28 -> V_39 , V_10 -> V_159 . V_67 ) ;
F_7 ( V_158 , V_28 -> V_40 , V_10 -> V_159 . V_160 ) ;
F_7 ( V_158 , V_28 -> V_104 , V_10 -> V_159 . V_104 ) ;
F_7 ( V_158 , V_28 -> V_110 , V_10 -> V_159 . V_110 ) ;
F_7 ( V_158 , V_28 -> V_161 , V_10 -> V_159 . V_161 ) ;
F_7 ( V_158 , V_28 -> V_162 , V_10 -> V_159 . V_162 ) ;
if ( V_4 -> V_15 -> V_16 -> V_17 == V_55 &&
V_4 -> V_21 == V_22 )
F_18 ( & V_10 -> V_19 , V_12 + V_28 -> V_58 * V_59 ) ;
return 0 ;
}
