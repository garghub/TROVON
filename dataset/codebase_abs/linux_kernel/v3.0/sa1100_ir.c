static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return 0 ;
V_2 -> V_3 = F_2 ( V_4 + 1 , V_5 ) ;
if ( ! V_2 -> V_3 ) {
F_3 ( V_6 L_1 ) ;
return - V_7 ;
}
F_4 ( V_2 -> V_3 , 1 ) ;
V_2 -> V_8 = F_5 ( V_2 -> V_9 , V_2 -> V_3 -> V_10 ,
V_4 ,
V_11 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
F_3 ( V_6 L_2 ) ;
return;
}
V_12 = V_2 -> V_13 | V_14 ;
F_7 ( V_2 -> V_15 ) ;
F_8 ( V_2 -> V_15 , V_2 -> V_8 , V_4 ) ;
V_12 = V_2 -> V_13 | V_14 | V_16 ;
}
static int F_9 ( struct V_1 * V_2 , int V_17 )
{
unsigned long V_18 ;
int V_19 , V_20 = - V_21 ;
switch ( V_17 ) {
case 9600 : case 19200 : case 38400 :
case 57600 : case 115200 :
V_19 = 3686400 / ( 16 * V_17 ) - 1 ;
if ( F_10 ( V_2 ) )
F_11 ( V_2 -> V_15 ) ;
F_12 ( V_18 ) ;
V_22 = 0 ;
V_12 = V_23 ;
V_24 = V_19 >> 8 ;
V_25 = V_19 ;
V_26 = V_27 | V_28 | V_29 ;
V_22 = V_30 | V_31 | V_32 ;
if ( V_2 -> V_33 -> V_34 )
V_2 -> V_33 -> V_34 ( V_2 -> V_9 , V_17 ) ;
V_2 -> V_17 = V_17 ;
F_13 ( V_18 ) ;
V_20 = 0 ;
break;
case 4000000 :
F_12 ( V_18 ) ;
V_2 -> V_13 = 0 ;
V_35 = 0xff ;
V_12 = V_2 -> V_13 | V_14 ;
V_22 = 0 ;
V_2 -> V_17 = V_17 ;
if ( V_2 -> V_33 -> V_34 )
V_2 -> V_33 -> V_34 ( V_2 -> V_9 , V_17 ) ;
F_1 ( V_2 ) ;
F_6 ( V_2 ) ;
F_13 ( V_18 ) ;
break;
default:
break;
}
return V_20 ;
}
static int
F_14 ( struct V_1 * V_2 , unsigned int V_36 )
{
int V_20 = 0 ;
if ( V_2 -> V_33 -> V_37 )
V_20 = V_2 -> V_33 -> V_37 ( V_2 -> V_9 , V_36 ) ;
return V_20 ;
}
static inline int
F_15 ( struct V_1 * V_2 , unsigned int V_36 )
{
int V_20 ;
V_20 = F_14 ( V_2 , V_36 ) ;
if ( V_20 == 0 )
V_2 -> V_38 = V_36 ;
return V_20 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_20 ;
if ( V_2 -> V_33 -> V_39 ) {
V_20 = V_2 -> V_33 -> V_39 ( V_2 -> V_9 ) ;
if ( V_20 )
return V_20 ;
}
V_40 &= ~ V_41 ;
V_42 &= ~ V_41 ;
V_43 |= V_41 ;
V_22 = 0 ;
V_12 = V_23 ;
V_44 = V_2 -> V_45 ;
V_46 = V_47 ;
V_48 = V_49 | V_50 ;
V_26 = V_27 | V_28 | V_29 ;
V_20 = F_9 ( V_2 , V_2 -> V_17 = 9600 ) ;
if ( V_20 ) {
V_22 = 0 ;
V_12 = 0 ;
if ( V_2 -> V_33 -> V_51 )
V_2 -> V_33 -> V_51 ( V_2 -> V_9 ) ;
}
return V_20 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_15 ) ;
F_11 ( V_2 -> V_52 ) ;
V_22 = 0 ;
V_12 = 0 ;
if ( V_2 -> V_33 -> V_51 )
V_2 -> V_33 -> V_51 ( V_2 -> V_9 ) ;
}
static int F_18 ( struct V_53 * V_54 , T_1 V_36 )
{
struct V_55 * V_9 = F_19 ( V_54 ) ;
struct V_1 * V_2 ;
if ( ! V_9 )
return 0 ;
V_2 = F_20 ( V_9 ) ;
if ( V_2 -> V_56 ) {
F_21 ( V_9 ) ;
F_22 ( V_9 -> V_57 ) ;
F_17 ( V_2 ) ;
F_14 ( V_2 , 0 ) ;
}
return 0 ;
}
static int F_23 ( struct V_53 * V_54 )
{
struct V_55 * V_9 = F_19 ( V_54 ) ;
struct V_1 * V_2 ;
if ( ! V_9 )
return 0 ;
V_2 = F_20 ( V_9 ) ;
if ( V_2 -> V_56 ) {
if ( V_2 -> V_58 ) {
V_2 -> V_17 = V_2 -> V_58 ;
V_2 -> V_58 = 0 ;
}
F_16 ( V_2 ) ;
F_14 ( V_2 , V_2 -> V_38 ) ;
F_24 ( V_9 -> V_57 ) ;
F_25 ( V_9 ) ;
}
return 0 ;
}
static void F_26 ( struct V_55 * V_9 )
{
struct V_1 * V_2 = F_20 ( V_9 ) ;
int V_59 ;
V_59 = V_26 ;
while ( V_59 & V_60 ) {
int V_61 , V_10 ;
V_61 = V_62 ;
V_10 = V_63 ;
if ( V_61 & ( V_64 | V_65 ) ) {
V_9 -> V_66 . V_67 ++ ;
if ( V_61 & V_64 )
V_9 -> V_66 . V_68 ++ ;
if ( V_61 & V_65 )
V_9 -> V_66 . V_69 ++ ;
} else
F_27 ( V_9 , & V_9 -> V_66 , & V_2 -> V_70 , V_10 ) ;
V_59 = V_26 ;
}
V_26 = V_59 & ( V_29 | V_28 | V_27 ) ;
if ( V_59 & V_71 ) {
F_27 ( V_9 , & V_9 -> V_66 , & V_2 -> V_70 , V_63 ) ;
F_27 ( V_9 , & V_9 -> V_66 , & V_2 -> V_70 , V_63 ) ;
F_27 ( V_9 , & V_9 -> V_66 , & V_2 -> V_70 , V_63 ) ;
}
if ( V_59 & ( V_71 | V_29 ) ) {
do {
F_27 ( V_9 , & V_9 -> V_66 , & V_2 -> V_70 ,
V_63 ) ;
} while ( V_62 & V_72 );
}
if ( V_59 & V_73 && V_2 -> V_74 . V_75 ) {
do {
V_63 = * V_2 -> V_74 . V_10 ++ ;
V_2 -> V_74 . V_75 -= 1 ;
} while ( V_62 & V_76 && V_2 -> V_74 . V_75 );
if ( V_2 -> V_74 . V_75 == 0 ) {
V_9 -> V_66 . V_77 ++ ;
V_9 -> V_66 . V_78 += V_2 -> V_74 . V_10 -
V_2 -> V_74 . V_79 ;
do
F_28 () ;
while ( V_62 & V_80 );
V_26 = V_27 | V_28 | V_29 ;
V_22 = V_30 | V_31 | V_32 ;
if ( V_2 -> V_58 ) {
F_9 ( V_2 , V_2 -> V_58 ) ;
V_2 -> V_58 = 0 ;
}
F_29 ( V_9 ) ;
}
}
}
static void F_30 ( struct V_1 * V_2 , struct V_55 * V_9 )
{
struct V_81 * V_82 = V_2 -> V_3 ;
T_2 V_83 ;
unsigned int V_75 , V_61 , V_10 ;
if ( ! V_82 ) {
F_3 ( V_6 L_3 ) ;
return;
}
V_83 = F_31 ( V_2 -> V_15 ) ;
V_75 = V_83 - V_2 -> V_8 ;
if ( V_75 > V_4 )
V_75 = V_4 ;
F_32 ( V_2 -> V_9 , V_2 -> V_8 , V_75 , V_11 ) ;
do {
V_61 = V_84 ;
F_28 () ;
V_10 = V_85 ;
if ( V_61 & ( V_86 | V_87 ) ) {
V_9 -> V_66 . V_67 ++ ;
if ( V_61 & V_86 )
V_9 -> V_66 . V_88 ++ ;
if ( V_61 & V_87 )
V_9 -> V_66 . V_68 ++ ;
} else
V_82 -> V_10 [ V_75 ++ ] = V_10 ;
if ( V_61 & V_89 )
break;
} while ( V_35 & V_90 );
if ( V_61 & V_89 ) {
V_2 -> V_3 = NULL ;
F_33 ( V_82 , V_75 ) ;
V_82 -> V_9 = V_9 ;
F_34 ( V_82 ) ;
V_82 -> V_91 = F_35 ( V_92 ) ;
V_9 -> V_66 . V_93 ++ ;
V_9 -> V_66 . V_94 += V_75 ;
F_1 ( V_2 ) ;
F_36 ( V_82 ) ;
} else {
V_2 -> V_8 = F_5 ( V_2 -> V_9 , V_2 -> V_3 -> V_10 ,
V_4 ,
V_11 ) ;
}
}
static void F_37 ( struct V_55 * V_9 )
{
struct V_1 * V_2 = F_20 ( V_9 ) ;
F_11 ( V_2 -> V_15 ) ;
if ( V_35 & ( V_95 | V_96 ) ) {
V_9 -> V_66 . V_67 ++ ;
if ( V_35 & V_95 )
V_9 -> V_66 . V_68 ++ ;
V_12 = V_2 -> V_13 | V_14 ;
V_35 = V_95 | V_96 ;
}
if ( V_35 & V_90 )
F_30 ( V_2 , V_9 ) ;
F_6 ( V_2 ) ;
}
static T_3 F_38 ( int V_57 , void * V_97 )
{
struct V_55 * V_9 = V_97 ;
if ( F_10 ( ( (struct V_1 * ) F_20 ( V_9 ) ) ) )
F_37 ( V_9 ) ;
else
F_26 ( V_9 ) ;
return V_98 ;
}
static void F_39 ( void * V_99 )
{
struct V_55 * V_9 = V_99 ;
struct V_1 * V_2 = F_20 ( V_9 ) ;
struct V_81 * V_82 = V_2 -> V_100 ;
V_2 -> V_100 = NULL ;
do
F_28 () ;
while ( ! ( V_35 & V_101 ) || V_84 & V_102 );
V_35 = V_101 ;
if ( V_2 -> V_58 ) {
F_9 ( V_2 , V_2 -> V_58 ) ;
V_2 -> V_58 = 0 ;
}
F_6 ( V_2 ) ;
if ( V_82 ) {
F_32 ( V_2 -> V_9 , V_2 -> V_103 , V_82 -> V_75 , V_104 ) ;
V_9 -> V_66 . V_77 ++ ;
V_9 -> V_66 . V_78 += V_82 -> V_75 ;
F_40 ( V_82 ) ;
}
F_29 ( V_9 ) ;
}
static int F_41 ( struct V_81 * V_82 , struct V_55 * V_9 )
{
struct V_1 * V_2 = F_20 ( V_9 ) ;
int V_17 = F_42 ( V_82 ) ;
if ( V_17 != V_2 -> V_17 && V_17 != - 1 )
V_2 -> V_58 = V_17 ;
if ( V_82 -> V_75 == 0 ) {
if ( V_2 -> V_58 ) {
V_2 -> V_58 = 0 ;
F_9 ( V_2 , V_17 ) ;
}
F_43 ( V_82 ) ;
return V_105 ;
}
if ( ! F_10 ( V_2 ) ) {
F_44 ( V_9 ) ;
V_2 -> V_74 . V_10 = V_2 -> V_74 . V_79 ;
V_2 -> V_74 . V_75 = F_45 ( V_82 , V_2 -> V_74 . V_10 ,
V_2 -> V_74 . V_106 ) ;
V_22 = V_107 | V_32 ;
F_43 ( V_82 ) ;
} else {
int V_108 = F_46 ( V_82 ) ;
F_47 ( V_2 -> V_100 ) ;
F_44 ( V_9 ) ;
V_2 -> V_100 = V_82 ;
V_2 -> V_103 = F_5 ( V_2 -> V_9 , V_82 -> V_10 ,
V_82 -> V_75 , V_104 ) ;
F_8 ( V_2 -> V_52 , V_2 -> V_103 , V_82 -> V_75 ) ;
if ( V_108 )
F_48 ( V_108 ) ;
V_12 = V_2 -> V_13 | V_14 | V_109 ;
}
return V_105 ;
}
static int
F_49 ( struct V_55 * V_9 , struct V_110 * V_110 , int V_111 )
{
struct V_112 * V_113 = (struct V_112 * ) V_110 ;
struct V_1 * V_2 = F_20 ( V_9 ) ;
int V_20 = - V_114 ;
switch ( V_111 ) {
case V_115 :
if ( F_50 ( V_116 ) ) {
if ( V_2 -> V_56 ) {
V_20 = F_9 ( V_2 ,
V_113 -> V_117 ) ;
} else {
F_3 ( L_4 ) ;
V_20 = 0 ;
}
}
break;
case V_118 :
V_20 = - V_119 ;
if ( F_50 ( V_116 ) ) {
F_51 ( V_9 , TRUE ) ;
V_20 = 0 ;
}
break;
case V_120 :
V_113 -> V_121 = F_10 ( V_2 ) ? 0
: V_2 -> V_70 . V_36 != V_122 ;
break;
default:
break;
}
return V_20 ;
}
static int F_52 ( struct V_55 * V_9 )
{
struct V_1 * V_2 = F_20 ( V_9 ) ;
int V_123 ;
V_2 -> V_17 = 9600 ;
V_123 = F_53 ( V_9 -> V_57 , F_38 , 0 , V_9 -> V_124 , V_9 ) ;
if ( V_123 )
goto V_125;
V_123 = F_54 ( V_126 , L_5 ,
NULL , NULL , & V_2 -> V_15 ) ;
if ( V_123 )
goto V_127;
V_123 = F_54 ( V_128 , L_6 ,
F_39 , V_9 , & V_2 -> V_52 ) ;
if ( V_123 )
goto V_129;
F_22 ( V_9 -> V_57 ) ;
V_123 = F_16 ( V_2 ) ;
if ( V_123 )
goto V_130;
V_2 -> V_131 = F_55 ( V_9 , & V_2 -> V_132 , L_7 ) ;
V_123 = - V_7 ;
if ( ! V_2 -> V_131 )
goto V_133;
V_2 -> V_56 = 1 ;
F_15 ( V_2 , V_134 ) ;
F_24 ( V_9 -> V_57 ) ;
F_56 ( V_9 ) ;
return 0 ;
V_133:
V_2 -> V_56 = 0 ;
F_17 ( V_2 ) ;
V_130:
F_57 ( V_2 -> V_52 ) ;
V_129:
F_57 ( V_2 -> V_15 ) ;
V_127:
F_58 ( V_9 -> V_57 , V_9 ) ;
V_125:
return V_123 ;
}
static int F_59 ( struct V_55 * V_9 )
{
struct V_1 * V_2 = F_20 ( V_9 ) ;
F_22 ( V_9 -> V_57 ) ;
F_17 ( V_2 ) ;
if ( V_2 -> V_3 ) {
F_32 ( V_2 -> V_9 , V_2 -> V_8 , V_4 ,
V_11 ) ;
F_43 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
if ( V_2 -> V_131 ) {
F_60 ( V_2 -> V_131 ) ;
V_2 -> V_131 = NULL ;
}
F_44 ( V_9 ) ;
V_2 -> V_56 = 0 ;
F_57 ( V_2 -> V_52 ) ;
F_57 ( V_2 -> V_15 ) ;
F_58 ( V_9 -> V_57 , V_9 ) ;
F_15 ( V_2 , 0 ) ;
return 0 ;
}
static int F_61 ( T_4 * V_135 , int V_136 )
{
V_135 -> V_79 = F_62 ( V_136 , V_137 | V_138 ) ;
if ( V_135 -> V_79 != NULL ) {
V_135 -> V_106 = V_136 ;
V_135 -> V_139 = FALSE ;
V_135 -> V_36 = V_122 ;
V_135 -> V_10 = V_135 -> V_79 ;
}
return V_135 -> V_79 ? 0 : - V_7 ;
}
static int F_63 ( struct V_53 * V_54 )
{
struct V_55 * V_9 ;
struct V_1 * V_2 ;
unsigned int V_140 ;
int V_123 ;
if ( ! V_54 -> V_9 . V_141 )
return - V_21 ;
V_123 = F_64 ( F_65 ( V_46 ) , 0x24 , L_8 ) ? 0 : - V_142 ;
if ( V_123 )
goto V_143;
V_123 = F_64 ( F_65 ( V_12 ) , 0x1c , L_8 ) ? 0 : - V_142 ;
if ( V_123 )
goto V_144;
V_123 = F_64 ( F_65 ( V_48 ) , 0x04 , L_8 ) ? 0 : - V_142 ;
if ( V_123 )
goto V_145;
V_9 = F_66 ( sizeof( struct V_1 ) ) ;
if ( ! V_9 )
goto V_146;
V_2 = F_20 ( V_9 ) ;
V_2 -> V_9 = & V_54 -> V_9 ;
V_2 -> V_33 = V_54 -> V_9 . V_141 ;
V_123 = F_61 ( & V_2 -> V_70 , 14384 ) ;
if ( V_123 )
goto V_147;
V_123 = F_61 ( & V_2 -> V_74 , 4000 ) ;
if ( V_123 )
goto V_147;
V_9 -> V_148 = & V_149 ;
V_9 -> V_57 = V_150 ;
F_67 ( & V_2 -> V_132 ) ;
V_140 = V_151 ;
switch ( V_152 ) {
case 4000000 : V_140 |= V_153 << 8 ;
case 115200 : V_140 |= V_154 ;
case 57600 : V_140 |= V_155 ;
case 38400 : V_140 |= V_156 ;
case 19200 : V_140 |= V_157 ;
}
V_2 -> V_132 . V_158 . V_159 &= V_140 ;
V_2 -> V_132 . V_160 . V_159 = 7 ;
F_68 ( & V_2 -> V_132 ) ;
V_2 -> V_45 = V_161 ;
if ( V_162 )
V_2 -> V_45 |= V_163 ;
V_22 = 0 ;
V_44 = V_2 -> V_45 ;
V_12 = V_23 ;
V_123 = F_69 ( V_9 ) ;
if ( V_123 == 0 )
F_70 ( V_54 , V_9 ) ;
if ( V_123 ) {
V_147:
F_71 ( V_2 -> V_74 . V_79 ) ;
F_71 ( V_2 -> V_70 . V_79 ) ;
F_72 ( V_9 ) ;
V_146:
F_73 ( F_65 ( V_48 ) , 0x04 ) ;
V_145:
F_73 ( F_65 ( V_12 ) , 0x1c ) ;
V_144:
F_73 ( F_65 ( V_46 ) , 0x24 ) ;
}
V_143:
return V_123 ;
}
static int F_74 ( struct V_53 * V_54 )
{
struct V_55 * V_9 = F_19 ( V_54 ) ;
if ( V_9 ) {
struct V_1 * V_2 = F_20 ( V_9 ) ;
F_75 ( V_9 ) ;
F_71 ( V_2 -> V_74 . V_79 ) ;
F_71 ( V_2 -> V_70 . V_79 ) ;
F_72 ( V_9 ) ;
}
F_73 ( F_65 ( V_48 ) , 0x04 ) ;
F_73 ( F_65 ( V_12 ) , 0x1c ) ;
F_73 ( F_65 ( V_46 ) , 0x24 ) ;
return 0 ;
}
static int T_5 F_76 ( void )
{
if ( V_134 < 1 )
V_134 = 1 ;
if ( V_134 > 3 )
V_134 = 3 ;
return F_77 ( & V_164 ) ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_164 ) ;
}
