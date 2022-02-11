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
V_95 = F_3 ( V_29 , V_28 -> V_98 ) ;
if ( ! V_95 )
return - V_99 ;
F_45 ( V_4 -> V_15 ) ;
F_46 ( & V_10 -> V_19 , F_23 , ( unsigned long ) V_4 ) ;
F_7 ( V_29 , V_28 -> V_100 , ( 1 << V_28 -> V_101 ) ) ;
V_4 -> V_102 = F_28 ;
V_96 = F_3 ( V_29 , V_28 -> V_103 ) ;
V_96 &= ~ ( 1 << V_28 -> V_104 ) ;
F_7 ( V_4 -> V_30 , V_28 -> V_103 , V_96 ) ;
V_96 = F_1 ( V_4 -> V_47 , V_105 ) ;
if ( V_96 == V_106 ) {
V_10 -> V_107 = true ;
V_96 |= V_108 ;
F_5 ( V_4 -> V_47 , V_105 , V_96 ) ;
}
V_65 = F_33 ( V_4 , V_10 ) ;
if ( V_65 )
return V_65 ;
return 0 ;
}
static int F_47 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
F_48 ( & V_10 -> V_19 ) ;
F_49 ( V_4 -> V_15 ) ;
F_38 ( V_10 -> V_86 ) ;
return 0 ;
}
static int F_50 ( struct V_4 * V_4 , T_1 V_109 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
void T_2 * V_30 = V_4 -> V_30 ;
T_3 V_110 ;
V_110 = F_3 ( V_30 , V_28 -> V_109 ) ;
switch ( V_109 ) {
case V_111 :
V_110 &= ~ ( 1 << V_28 -> V_112 ) ;
V_110 |= ( 1 << V_28 -> V_113 ) ;
F_7 ( V_30 , V_28 -> V_109 , V_110 ) ;
F_7 ( V_30 , V_28 -> V_103 , 0x02 ) ;
break;
case V_114 :
V_110 |= ( 1 << V_28 -> V_112 ) ;
V_110 |= ( 1 << V_28 -> V_113 ) ;
F_7 ( V_30 , V_28 -> V_109 , V_110 ) ;
break;
case V_115 :
F_7 ( V_30 , V_28 -> V_103 , 0x02 ) ;
break;
default:
F_51 ( V_10 -> V_7 , L_17 , V_109 ) ;
return - V_116 ;
}
return 0 ;
}
static bool F_52 ( struct V_4 * V_4 )
{
T_1 V_117 ;
bool V_118 = false ;
V_117 = F_1 ( V_4 -> V_47 , V_105 ) ;
F_12 ( V_4 -> V_8 , L_18 ,
V_117 ) ;
F_12 ( V_4 -> V_8 , L_19 ,
V_117 & V_119 ? L_20 : L_21 ) ;
if ( V_117 & V_119 ) {
int V_5 = 10 ;
V_117 = F_1 ( V_4 -> V_47 , V_105 ) ;
V_117 |= V_120 ;
F_5 ( V_4 -> V_47 , V_105 , V_117 ) ;
F_12 ( V_4 -> V_8 , L_22 ) ;
do {
V_117 = F_1 ( V_4 -> V_47 , V_105 ) ;
F_53 ( 1 ) ;
} while ( ( V_117 & V_119 ) && V_5 -- );
if ( V_117 & V_119 ) {
F_12 ( V_4 -> V_8 , L_23 ,
V_117 ) ;
V_118 = true ;
}
} else {
V_118 = true ;
}
return V_118 ;
}
static int F_54 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
int V_118 = 0 ;
if ( V_10 -> V_107 )
V_118 = F_52 ( V_4 ) ;
if ( V_118 || ! V_10 -> V_107 ) {
F_55 ( V_4 -> V_8 , L_24 ) ;
F_7 ( V_4 -> V_30 , V_28 -> V_100 , ( 1 << V_28 -> V_101 ) ) ;
F_56 ( 100 , 200 ) ;
F_49 ( V_4 -> V_15 ) ;
F_56 ( 100 , 200 ) ;
F_45 ( V_4 -> V_15 ) ;
V_118 = 1 ;
}
return ! V_118 ;
}
static int F_57 ( struct V_121 * V_122 , const char * V_123 )
{
int V_65 ;
T_3 V_96 ;
V_65 = F_58 ( V_122 , V_123 , & V_96 ) ;
if ( V_65 )
return 0 ;
return V_96 ;
}
static int F_59 ( struct V_6 * V_7 )
{
enum V_124 V_109 ;
V_109 = F_60 ( V_7 -> V_125 ) ;
switch ( V_109 ) {
case V_126 :
return V_127 ;
case V_128 :
return V_129 ;
case V_130 :
case V_131 :
default:
return V_22 ;
}
}
static int F_61 ( struct V_9 * V_10 ,
struct V_25 * V_11 )
{
struct V_132 V_133 ;
struct V_93 V_134 [ 2 ] ;
struct V_93 * V_135 ;
struct V_6 * V_7 = & V_11 -> V_7 ;
struct V_136 * V_137 ;
struct V_25 * V_4 ;
struct V_121 * V_122 = V_11 -> V_7 . V_125 ;
int V_65 ;
memset ( V_134 , 0 , sizeof( V_134 ) ) ;
V_135 = F_40 ( V_11 , V_97 , L_25 ) ;
if ( ! V_135 ) {
F_51 ( V_7 , L_26 ) ;
return - V_116 ;
}
V_134 [ 0 ] = * V_135 ;
V_135 = F_40 ( V_11 , V_138 , L_25 ) ;
if ( ! V_135 ) {
F_51 ( V_7 , L_27 ) ;
return - V_116 ;
}
V_134 [ 1 ] = * V_135 ;
V_4 = F_62 ( L_28 , V_139 ) ;
if ( ! V_4 ) {
F_51 ( V_7 , L_29 ) ;
return - V_85 ;
}
V_4 -> V_7 . V_11 = V_7 ;
V_4 -> V_7 . V_140 = & V_141 ;
V_4 -> V_7 . V_142 = V_141 ;
V_4 -> V_7 . V_125 = F_63 ( V_122 ) ;
V_10 -> V_4 = V_4 ;
V_65 = F_64 ( V_4 , V_134 ,
F_36 ( V_134 ) ) ;
if ( V_65 ) {
F_51 ( V_7 , L_30 ) ;
goto V_78;
}
V_137 = F_65 ( & V_11 -> V_7 , sizeof( * V_137 ) , V_143 ) ;
if ( ! V_137 ) {
V_65 = - V_85 ;
goto V_78;
}
V_133 . V_137 = V_137 ;
V_133 . V_144 = & V_145 ;
V_137 -> V_146 = F_57 ( V_122 , L_31 ) ;
V_137 -> V_147 = F_57 ( V_122 , L_32 ) ;
V_137 -> V_148 = 1 ;
V_133 . V_109 = F_59 ( V_7 ) ;
V_133 . V_149 = F_57 ( V_122 , L_33 ) / 2 ;
V_137 -> V_150 = F_66 ( V_122 , L_34 ) ;
V_65 = F_67 ( V_4 , & V_133 , sizeof( V_133 ) ) ;
if ( V_65 ) {
F_51 ( V_7 , L_35 ) ;
goto V_78;
}
V_65 = F_68 ( V_4 ) ;
if ( V_65 ) {
F_51 ( V_7 , L_36 ) ;
goto V_78;
}
return 0 ;
V_78:
F_69 ( V_4 ) ;
return V_65 ;
}
static int F_70 ( struct V_25 * V_26 )
{
const struct V_151 * V_152 ;
const struct V_27 * V_28 ;
struct V_9 * V_10 ;
int V_65 ;
if ( ! strcmp ( V_26 -> V_153 , L_28 ) )
return - V_99 ;
V_152 = F_71 ( V_154 , V_26 -> V_7 . V_125 ) ;
if ( ! V_152 ) {
F_51 ( & V_26 -> V_7 , L_37 ) ;
return - V_116 ;
}
V_28 = V_152 -> V_3 ;
V_10 = F_65 ( & V_26 -> V_7 , sizeof( * V_10 ) , V_143 ) ;
if ( ! V_10 )
return - V_85 ;
V_10 -> V_7 = & V_26 -> V_7 ;
V_10 -> V_28 = V_28 ;
F_72 ( V_26 , V_10 ) ;
F_73 ( & V_26 -> V_7 ) ;
V_65 = F_74 ( & V_26 -> V_7 ) ;
if ( V_65 < 0 ) {
F_51 ( & V_26 -> V_7 , L_38 ) ;
goto V_155;
}
V_65 = F_61 ( V_10 , V_26 ) ;
if ( V_65 )
goto V_156;
return 0 ;
V_156:
F_75 ( & V_26 -> V_7 ) ;
V_155:
F_76 ( & V_26 -> V_7 ) ;
return V_65 ;
}
static int F_77 ( struct V_25 * V_26 )
{
struct V_9 * V_10 = F_21 ( V_26 ) ;
F_78 ( V_10 -> V_4 ) ;
F_75 ( & V_26 -> V_7 ) ;
F_76 ( & V_26 -> V_7 ) ;
return 0 ;
}
static int F_79 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_10 ( V_7 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
struct V_4 * V_4 = F_21 ( V_10 -> V_4 ) ;
void T_2 * V_157 ;
F_48 ( & V_10 -> V_19 ) ;
if ( ! V_4 )
return 0 ;
V_157 = V_4 -> V_30 ;
V_10 -> V_158 . V_100 = F_3 ( V_157 , V_28 -> V_100 ) ;
V_10 -> V_158 . V_67 = F_3 ( V_157 , V_28 -> V_39 ) ;
V_10 -> V_158 . V_159 = F_3 ( V_157 , V_28 -> V_40 ) ;
V_10 -> V_158 . V_103 = F_3 ( V_157 , V_28 -> V_103 ) ;
V_10 -> V_158 . V_109 = F_3 ( V_157 , V_28 -> V_109 ) ;
V_10 -> V_158 . V_160 = F_3 ( V_157 , V_28 -> V_160 ) ;
V_10 -> V_158 . V_161 = F_3 ( V_157 , V_28 -> V_161 ) ;
return 0 ;
}
static int F_80 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_10 ( V_7 ) ;
const struct V_27 * V_28 = V_10 -> V_28 ;
struct V_4 * V_4 = F_21 ( V_10 -> V_4 ) ;
void T_2 * V_157 ;
if ( ! V_4 )
return 0 ;
V_157 = V_4 -> V_30 ;
F_7 ( V_157 , V_28 -> V_100 , V_10 -> V_158 . V_100 ) ;
F_7 ( V_157 , V_28 -> V_39 , V_10 -> V_158 . V_67 ) ;
F_7 ( V_157 , V_28 -> V_40 , V_10 -> V_158 . V_159 ) ;
F_7 ( V_157 , V_28 -> V_103 , V_10 -> V_158 . V_103 ) ;
F_7 ( V_157 , V_28 -> V_109 , V_10 -> V_158 . V_109 ) ;
F_7 ( V_157 , V_28 -> V_160 , V_10 -> V_158 . V_160 ) ;
F_7 ( V_157 , V_28 -> V_161 , V_10 -> V_158 . V_161 ) ;
if ( V_4 -> V_15 -> V_16 -> V_17 == V_55 &&
V_4 -> V_21 == V_22 )
F_18 ( & V_10 -> V_19 , V_12 + V_28 -> V_58 * V_59 ) ;
return 0 ;
}
