static inline T_1 F_1 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_2 ( V_1 + V_2 ) ; }
static inline T_3 F_3 ( const void T_2 * V_1 , unsigned V_2 )
{ return F_4 ( V_1 + V_2 ) ; }
static inline void F_5 ( void T_2 * V_1 , unsigned V_2 , T_1 V_3 )
{ F_6 ( V_3 , V_1 + V_2 ) ; }
static inline void F_7 ( void T_2 * V_1 , unsigned V_2 , T_3 V_3 )
{ F_8 ( V_3 , V_1 + V_2 ) ; }
static void F_9 ( struct V_4 * V_4 , unsigned long V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
if ( V_5 == 0 )
V_5 = V_12 + F_11 ( 3 ) ;
if ( V_4 -> V_13 || ( V_4 -> V_14 == 0 &&
V_4 -> V_15 -> V_16 == V_17 ) ) {
F_12 ( V_4 -> V_8 , L_1 ,
F_13 ( V_4 -> V_15 -> V_16 ) ) ;
F_14 ( & V_10 -> V_18 ) ;
V_10 -> V_19 = V_12 ;
return;
}
if ( V_4 -> V_20 != V_21 )
return;
if ( ! V_4 -> V_22 . V_7 . V_23 )
return;
if ( F_15 ( V_10 -> V_19 , V_5 ) &&
F_16 ( & V_10 -> V_18 ) ) {
F_12 ( V_4 -> V_8 ,
L_2 ) ;
return;
}
V_10 -> V_19 = V_5 ;
F_12 ( V_4 -> V_8 , L_3 ,
F_13 ( V_4 -> V_15 -> V_16 ) ,
F_17 ( V_5 - V_12 ) ) ;
F_18 ( & V_10 -> V_18 , V_5 ) ;
}
static void F_19 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_24 * V_25 = F_20 ( V_7 -> V_11 ) ;
struct V_9 * V_10 = F_21 ( V_25 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
void T_2 * V_28 = V_4 -> V_29 ;
T_3 V_30 , V_31 ;
V_30 = ( ( V_4 -> V_30 & V_27 -> V_32 ) << V_27 -> V_33 ) |
( ( V_4 -> V_30 & V_27 -> V_34 ) << V_27 -> V_35 ) ;
V_31 = ( V_27 -> V_36 & ~ V_37 ) ;
F_7 ( V_28 , V_27 -> V_38 , V_30 ) ;
F_7 ( V_28 , V_27 -> V_39 , V_31 ) ;
F_7 ( V_28 , V_27 -> V_39 ,
( 1 << V_27 -> V_40 ) << V_27 -> V_41 ) ;
F_9 ( V_4 , 0 ) ;
}
static void F_22 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_24 * V_25 = F_20 ( V_7 -> V_11 ) ;
struct V_9 * V_10 = F_21 ( V_25 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
void T_2 * V_28 = V_4 -> V_29 ;
F_7 ( V_28 , V_27 -> V_42 , V_27 -> V_36 ) ;
F_7 ( V_28 , V_27 -> V_43 ,
V_27 -> V_44 | V_27 -> V_45 ) ;
F_5 ( V_4 -> V_46 , V_47 , 0 ) ;
}
static void F_23 ( unsigned long V_48 )
{
struct V_4 * V_4 = ( void * ) V_48 ;
void T_2 * V_46 = V_4 -> V_46 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
T_1 V_49 ;
unsigned long V_50 ;
int V_51 = 0 ;
V_49 = F_1 ( V_46 , V_47 ) ;
F_12 ( V_4 -> V_8 , L_4 , V_49 ,
F_13 ( V_4 -> V_15 -> V_16 ) ) ;
F_24 ( & V_4 -> V_52 , V_50 ) ;
switch ( V_4 -> V_15 -> V_16 ) {
case V_17 :
F_5 ( V_4 -> V_46 , V_47 , 0 ) ;
V_51 = 1 ;
case V_53 :
case V_54 :
if ( V_49 & V_55 ) {
V_4 -> V_15 -> V_16 = V_54 ;
F_25 ( V_4 ) ;
} else {
V_4 -> V_15 -> V_16 = V_53 ;
F_26 ( V_4 ) ;
}
if ( ! ( V_49 & V_56 ) && ! V_51 )
F_5 ( V_46 , V_47 , V_56 ) ;
F_18 ( & V_10 -> V_18 , V_12 + V_27 -> V_57 * V_58 ) ;
break;
case V_59 :
V_4 -> V_15 -> V_16 = V_60 ;
F_7 ( V_4 -> V_29 , V_27 -> V_39 ,
V_61 << V_27 -> V_41 ) ;
break;
default:
break;
}
F_27 ( & V_4 -> V_52 , V_50 ) ;
}
static T_4 F_28 ( int V_62 , void * V_63 )
{
struct V_4 * V_4 = V_63 ;
void T_2 * V_28 = V_4 -> V_29 ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
unsigned long V_50 ;
T_4 V_64 = V_65 ;
T_3 V_66 , V_67 ;
F_24 ( & V_4 -> V_52 , V_50 ) ;
V_66 = F_3 ( V_28 , V_27 -> V_68 ) ;
V_4 -> V_69 = ( V_66 & V_27 -> V_45 ) >> V_27 -> V_35 ;
V_4 -> V_70 = ( V_66 & V_27 -> V_44 ) >> V_27 -> V_33 ;
if ( V_66 )
F_7 ( V_28 , V_27 -> V_68 , V_66 ) ;
V_67 = F_3 ( V_28 , V_27 -> V_71 ) ;
if ( ! V_67 && ! V_66 )
goto V_72;
V_4 -> V_73 = ( V_67 & V_27 -> V_36 ) >> V_27 -> V_41 ;
if ( V_67 )
F_7 ( V_28 , V_27 -> V_71 , V_67 ) ;
F_12 ( V_4 -> V_8 , L_5 ,
V_67 , V_66 ) ;
if ( F_29 ( V_4 ) && V_67 & V_74 ) {
F_30 ( L_6 ) ;
V_4 -> V_73 = V_74 | V_75 ;
V_4 -> V_70 = V_4 -> V_69 = 0 ;
}
if ( V_67 & ( ( 1 << V_27 -> V_40 ) << V_27 -> V_41 ) ) {
int V_40 = F_3 ( V_28 , V_27 -> V_76 ) ;
void T_2 * V_46 = V_4 -> V_46 ;
T_1 V_49 = F_1 ( V_46 , V_47 ) ;
int V_77 ;
V_77 = V_4 -> V_73 & V_61 ;
if ( V_77 ) {
V_4 -> V_73 &= ~ V_61 ;
V_4 -> V_15 -> V_16 = V_59 ;
F_18 ( & V_10 -> V_18 ,
V_12 + V_27 -> V_57 * V_58 ) ;
F_31 ( L_7 ) ;
} else if ( V_40 ) {
F_26 ( V_4 ) ;
V_4 -> V_15 -> V_78 -> V_79 = 1 ;
V_4 -> V_15 -> V_16 = V_60 ;
F_14 ( & V_10 -> V_18 ) ;
} else {
V_4 -> V_13 = 0 ;
F_25 ( V_4 ) ;
V_4 -> V_15 -> V_78 -> V_79 = 0 ;
V_4 -> V_15 -> V_16 = V_54 ;
}
F_12 ( V_4 -> V_8 , L_8 ,
V_40 ? L_9 : L_10 ,
F_13 ( V_4 -> V_15 -> V_16 ) ,
V_77 ? L_11 : L_12 ,
V_49 ) ;
V_64 = V_80 ;
}
if ( V_4 -> V_70 || V_4 -> V_69 || V_4 -> V_73 )
V_64 |= F_32 ( V_4 ) ;
if ( V_4 -> V_15 -> V_16 == V_54 &&
V_4 -> V_20 == V_21 )
F_18 ( & V_10 -> V_18 , V_12 + V_27 -> V_57 * V_58 ) ;
V_72:
F_27 ( & V_4 -> V_52 , V_50 ) ;
return V_64 ;
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
V_10 -> V_87 . V_91 = V_4 -> V_29 ;
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
struct V_24 * V_11 = F_20 ( V_7 -> V_11 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
void T_2 * V_28 ;
struct V_93 * V_94 ;
T_3 V_95 , V_96 ;
int V_64 ;
V_94 = F_40 ( V_11 , V_97 , L_15 ) ;
if ( ! V_94 )
return - V_98 ;
V_28 = F_41 ( V_7 , V_94 ) ;
if ( F_42 ( V_28 ) )
return F_43 ( V_28 ) ;
V_4 -> V_29 = V_28 ;
V_4 -> V_15 = F_44 ( V_7 , L_16 , 0 ) ;
if ( F_42 ( V_4 -> V_15 ) )
return F_43 ( V_4 -> V_15 ) ;
V_95 = F_3 ( V_28 , V_27 -> V_99 ) ;
if ( ! V_95 )
return - V_100 ;
F_45 ( V_4 -> V_15 ) ;
F_46 ( & V_10 -> V_18 , F_23 , ( unsigned long ) V_4 ) ;
F_7 ( V_28 , V_27 -> V_101 , ( 1 << V_27 -> V_102 ) ) ;
V_4 -> V_103 = F_28 ;
V_96 = F_3 ( V_28 , V_27 -> V_104 ) ;
V_96 &= ~ ( 1 << V_27 -> V_105 ) ;
F_7 ( V_4 -> V_29 , V_27 -> V_104 , V_96 ) ;
V_64 = F_33 ( V_4 , V_10 ) ;
if ( V_64 )
return V_64 ;
return 0 ;
}
static int F_47 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
F_48 ( & V_10 -> V_18 ) ;
F_49 ( V_4 -> V_15 ) ;
F_38 ( V_10 -> V_86 ) ;
return 0 ;
}
static int F_50 ( struct V_4 * V_4 , T_1 V_106 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
void T_2 * V_29 = V_4 -> V_29 ;
T_3 V_107 ;
V_107 = F_3 ( V_29 , V_27 -> V_106 ) ;
switch ( V_106 ) {
case V_108 :
V_107 &= ~ ( 1 << V_27 -> V_109 ) ;
V_107 |= ( 1 << V_27 -> V_110 ) ;
F_7 ( V_29 , V_27 -> V_106 , V_107 ) ;
F_7 ( V_29 , V_27 -> V_104 , 0x02 ) ;
break;
case V_111 :
V_107 |= ( 1 << V_27 -> V_109 ) ;
V_107 |= ( 1 << V_27 -> V_110 ) ;
F_7 ( V_29 , V_27 -> V_106 , V_107 ) ;
break;
case V_112 :
F_7 ( V_29 , V_27 -> V_104 , 0x02 ) ;
break;
default:
F_51 ( V_10 -> V_7 , L_17 , V_106 ) ;
return - V_98 ;
}
return 0 ;
}
static void F_52 ( struct V_4 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 = F_10 ( V_7 -> V_11 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
F_7 ( V_4 -> V_29 , V_27 -> V_101 , ( 1 << V_27 -> V_102 ) ) ;
F_53 ( 100 ) ;
}
static int F_54 ( struct V_113 * V_114 , const char * V_115 )
{
int V_64 ;
T_3 V_96 ;
V_64 = F_55 ( V_114 , V_115 , & V_96 ) ;
if ( V_64 )
return 0 ;
return V_96 ;
}
static int F_56 ( struct V_6 * V_7 )
{
enum V_116 V_106 ;
V_106 = F_57 ( V_7 -> V_117 ) ;
switch ( V_106 ) {
case V_118 :
return V_119 ;
case V_120 :
return V_121 ;
case V_122 :
case V_123 :
default:
return V_21 ;
}
}
static int F_58 ( struct V_9 * V_10 ,
struct V_24 * V_11 )
{
struct V_124 V_125 ;
struct V_93 V_126 [ 2 ] ;
struct V_93 * V_127 ;
struct V_6 * V_7 = & V_11 -> V_7 ;
struct V_128 * V_129 ;
struct V_24 * V_4 ;
struct V_113 * V_114 = V_11 -> V_7 . V_117 ;
int V_64 ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
V_127 = F_40 ( V_11 , V_97 , L_18 ) ;
if ( ! V_127 ) {
F_51 ( V_7 , L_19 ) ;
return - V_98 ;
}
V_126 [ 0 ] = * V_127 ;
V_127 = F_40 ( V_11 , V_130 , L_18 ) ;
if ( ! V_127 ) {
F_51 ( V_7 , L_20 ) ;
return - V_98 ;
}
V_126 [ 1 ] = * V_127 ;
V_4 = F_59 ( L_21 , V_131 ) ;
if ( ! V_4 ) {
F_51 ( V_7 , L_22 ) ;
return - V_85 ;
}
V_4 -> V_7 . V_11 = V_7 ;
V_4 -> V_7 . V_132 = & V_133 ;
V_4 -> V_7 . V_134 = V_133 ;
V_4 -> V_7 . V_117 = F_60 ( V_114 ) ;
V_10 -> V_4 = V_4 ;
V_64 = F_61 ( V_4 , V_126 ,
F_36 ( V_126 ) ) ;
if ( V_64 ) {
F_51 ( V_7 , L_23 ) ;
goto V_77;
}
V_129 = F_62 ( & V_11 -> V_7 , sizeof( * V_129 ) , V_135 ) ;
if ( ! V_129 ) {
F_51 ( V_7 , L_24 ) ;
V_64 = - V_85 ;
goto V_77;
}
V_125 . V_129 = V_129 ;
V_125 . V_136 = & V_137 ;
V_129 -> V_138 = F_54 ( V_114 , L_25 ) ;
V_129 -> V_139 = F_54 ( V_114 , L_26 ) ;
V_129 -> V_140 = 1 ;
V_125 . V_106 = F_56 ( V_7 ) ;
V_125 . V_141 = F_54 ( V_114 , L_27 ) / 2 ;
V_129 -> V_142 = F_63 ( V_114 , L_28 ) ;
V_64 = F_64 ( V_4 , & V_125 , sizeof( V_125 ) ) ;
if ( V_64 ) {
F_51 ( V_7 , L_29 ) ;
goto V_77;
}
V_64 = F_65 ( V_4 ) ;
if ( V_64 ) {
F_51 ( V_7 , L_30 ) ;
goto V_77;
}
return 0 ;
V_77:
F_66 ( V_4 ) ;
return V_64 ;
}
static int F_67 ( struct V_24 * V_25 )
{
const struct V_143 * V_144 ;
const struct V_26 * V_27 ;
struct V_9 * V_10 ;
int V_64 ;
if ( ! strcmp ( V_25 -> V_145 , L_21 ) )
return - V_100 ;
V_144 = F_68 ( V_146 , V_25 -> V_7 . V_117 ) ;
if ( ! V_144 ) {
F_51 ( & V_25 -> V_7 , L_31 ) ;
return - V_98 ;
}
V_27 = V_144 -> V_3 ;
V_10 = F_62 ( & V_25 -> V_7 , sizeof( * V_10 ) , V_135 ) ;
if ( ! V_10 ) {
F_51 ( & V_25 -> V_7 , L_32 ) ;
return - V_85 ;
}
V_10 -> V_7 = & V_25 -> V_7 ;
V_10 -> V_27 = V_27 ;
F_69 ( V_25 , V_10 ) ;
F_70 ( & V_25 -> V_7 ) ;
V_64 = F_71 ( & V_25 -> V_7 ) ;
if ( V_64 < 0 ) {
F_51 ( & V_25 -> V_7 , L_33 ) ;
goto V_147;
}
V_64 = F_58 ( V_10 , V_25 ) ;
if ( V_64 )
goto V_148;
return 0 ;
V_148:
F_72 ( & V_25 -> V_7 ) ;
V_147:
F_73 ( & V_25 -> V_7 ) ;
return V_64 ;
}
static int F_74 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_21 ( V_25 ) ;
F_75 ( V_10 -> V_4 ) ;
F_72 ( & V_25 -> V_7 ) ;
F_73 ( & V_25 -> V_7 ) ;
return 0 ;
}
static int F_76 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_10 ( V_7 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
struct V_4 * V_4 = F_21 ( V_10 -> V_4 ) ;
void T_2 * V_149 = V_4 -> V_29 ;
V_10 -> V_150 . V_101 = F_3 ( V_149 , V_27 -> V_101 ) ;
V_10 -> V_150 . V_66 = F_3 ( V_149 , V_27 -> V_38 ) ;
V_10 -> V_150 . V_151 = F_3 ( V_149 , V_27 -> V_39 ) ;
V_10 -> V_150 . V_104 = F_3 ( V_149 , V_27 -> V_104 ) ;
V_10 -> V_150 . V_106 = F_3 ( V_149 , V_27 -> V_106 ) ;
V_10 -> V_150 . V_152 = F_3 ( V_149 , V_27 -> V_152 ) ;
V_10 -> V_150 . V_153 = F_3 ( V_149 , V_27 -> V_153 ) ;
return 0 ;
}
static int F_77 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_10 ( V_7 ) ;
const struct V_26 * V_27 = V_10 -> V_27 ;
struct V_4 * V_4 = F_21 ( V_10 -> V_4 ) ;
void T_2 * V_149 = V_4 -> V_29 ;
F_7 ( V_149 , V_27 -> V_101 , V_10 -> V_150 . V_101 ) ;
F_7 ( V_149 , V_27 -> V_38 , V_10 -> V_150 . V_66 ) ;
F_7 ( V_149 , V_27 -> V_39 , V_10 -> V_150 . V_151 ) ;
F_7 ( V_149 , V_27 -> V_104 , V_10 -> V_150 . V_104 ) ;
F_7 ( V_149 , V_27 -> V_106 , V_10 -> V_150 . V_106 ) ;
F_7 ( V_149 , V_27 -> V_152 , V_10 -> V_150 . V_152 ) ;
F_7 ( V_149 , V_27 -> V_153 , V_10 -> V_150 . V_153 ) ;
return 0 ;
}
