static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline void F_3 ( struct V_5 * V_6 , unsigned int V_7 , T_1 V_8 )
{
F_4 ( ( V_8 ) , ( V_6 -> V_9 ) + ( V_7 ) ) ;
}
static inline T_1 F_5 ( struct V_5 * V_6 , unsigned int V_7 )
{
return F_6 ( ( V_6 -> V_9 ) + ( V_7 ) ) ;
}
static void F_7 ( struct V_5 * V_6 , struct V_1 * V_10 )
{
unsigned long V_11 = 0 ;
if ( V_6 -> V_12 . V_13 == V_14 )
V_11 = V_6 -> V_12 . V_15 * 2 ;
F_8 ( & V_6 -> V_16 ) ;
F_3 ( V_6 , V_17 , F_5 ( V_6 , V_17 ) | V_18 ) ;
F_3 ( V_6 , V_19 , ( T_1 ) V_10 -> V_20 ) ;
F_3 ( V_6 , V_21 , ( T_1 ) V_10 -> V_20 + V_11 ) ;
F_9 ( & V_6 -> V_16 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
F_11 ( & V_6 -> V_22 ) ;
if ( F_12 ( & V_6 -> V_23 ) ) {
F_13 ( & V_6 -> V_22 ) ;
return;
}
V_6 -> V_24 = F_14 ( & V_6 -> V_23 ,
struct V_1 ,
V_25 ) ;
V_6 -> V_26 = 0 ;
V_6 -> V_27 = 0 ;
F_13 ( & V_6 -> V_22 ) ;
if ( F_15 ( & V_6 -> V_28 ) ) {
F_7 ( V_6 , V_6 -> V_24 ) ;
}
}
static int F_16 ( struct V_29 * V_30 , const struct V_31 * V_32 ,
unsigned int * V_33 , unsigned int * V_34 ,
unsigned int V_35 [] , void * V_36 [] )
{
struct V_5 * V_6 = F_17 ( V_30 ) ;
if ( ! ( * V_33 ) || * V_33 < V_37 )
* V_33 = V_37 ;
* V_34 = 1 ;
V_35 [ 0 ] = V_6 -> V_12 . V_38 ;
V_36 [ 0 ] = V_6 -> V_39 ;
V_6 -> V_40 = 0 ;
V_6 -> V_24 = NULL ;
V_6 -> V_26 = 0 ;
V_6 -> V_27 = 0 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_4 )
{
struct V_1 * V_10 = F_1 ( V_4 ) ;
V_10 -> V_20 = F_19 ( V_4 , 0 ) ;
F_20 ( & V_10 -> V_25 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_17 ( V_4 -> V_29 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
unsigned long V_41 ;
V_41 = V_6 -> V_12 . V_38 ;
if ( F_22 ( V_4 , 0 ) < V_41 ) {
F_23 ( & V_6 -> V_42 , L_1 ,
F_22 ( V_4 , 0 ) , V_41 ) ;
return - V_43 ;
}
F_24 ( & V_10 -> V_4 , 0 , V_41 ) ;
return 0 ;
}
static void F_25 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_17 ( V_4 -> V_29 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_11 ( & V_6 -> V_22 ) ;
F_26 ( & V_10 -> V_25 , & V_6 -> V_23 ) ;
if ( ! V_6 -> V_24 ) {
V_6 -> V_24 = F_14 ( & V_6 -> V_23 ,
struct V_1 ,
V_25 ) ;
if ( F_15 ( & V_6 -> V_28 ) )
F_7 ( V_6 , V_10 ) ;
}
F_13 ( & V_6 -> V_22 ) ;
}
static void F_27 ( struct V_2 * V_4 )
{
struct V_5 * V_6 = F_17 ( V_4 -> V_29 ) ;
struct V_1 * V_10 = F_1 ( V_4 ) ;
F_11 ( & V_6 -> V_22 ) ;
F_28 ( & V_10 -> V_25 ) ;
F_13 ( & V_6 -> V_22 ) ;
if ( F_15 ( V_4 -> V_29 ) )
F_10 ( V_6 ) ;
}
static int F_29 ( struct V_29 * V_30 , unsigned int V_44 )
{
struct V_5 * V_6 = F_17 ( V_30 ) ;
F_8 ( & V_6 -> V_16 ) ;
F_3 ( V_6 , V_45 , V_46 | V_47 ) ;
F_9 ( & V_6 -> V_16 ) ;
if ( V_44 )
F_7 ( V_6 , V_6 -> V_24 ) ;
return 0 ;
}
static void F_30 ( struct V_29 * V_30 )
{
struct V_5 * V_6 = F_17 ( V_30 ) ;
struct V_1 * V_10 , * V_48 ;
F_3 ( V_6 , V_17 , F_5 ( V_6 , V_17 ) & ~ V_18 ) ;
F_3 ( V_6 , V_45 , 0 ) ;
F_11 ( & V_6 -> V_22 ) ;
F_31 (vip_buf, node, &vip->buffer_list, list) {
F_32 ( & V_10 -> V_4 , V_49 ) ;
F_33 ( & V_10 -> V_25 ) ;
}
F_13 ( & V_6 -> V_22 ) ;
}
static int F_34 ( struct V_50 * V_50 , void * V_51 ,
struct V_52 * V_53 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
strcpy ( V_53 -> V_54 , V_55 ) ;
strcpy ( V_53 -> V_56 , V_55 ) ;
snprintf ( V_53 -> V_57 , sizeof( V_53 -> V_57 ) , L_2 ,
F_36 ( V_6 -> V_58 ) ) ;
V_53 -> V_59 = V_60 | V_61 |
V_62 ;
V_53 -> V_63 = V_53 -> V_59 | V_64 ;
return 0 ;
}
static int F_37 ( struct V_50 * V_50 , void * V_51 , T_2 V_65 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
T_2 V_66 = V_6 -> V_65 , V_67 ;
int V_68 ;
if ( V_69 == V_65 ) {
F_38 ( V_6 -> V_70 , V_71 , V_72 , V_65 ) ;
F_39 ( 2 ) ;
F_38 ( V_6 -> V_70 , V_71 , V_73 , & V_67 ) ;
F_38 ( V_6 -> V_70 , V_71 , V_74 , & V_68 ) ;
if ( V_68 & V_75 )
return - V_76 ;
V_65 = V_6 -> V_65 = V_67 ;
if ( V_66 != V_65 ) {
if ( V_77 & V_65 )
V_6 -> V_12 = V_78 [ 0 ] ;
else
V_6 -> V_12 = V_79 [ 0 ] ;
}
return 0 ;
}
if ( V_66 != V_65 ) {
if ( V_77 & V_65 )
V_6 -> V_12 = V_78 [ 0 ] ;
else
V_6 -> V_12 = V_79 [ 0 ] ;
}
return F_38 ( V_6 -> V_70 , V_71 , V_72 , V_65 ) ;
}
static int F_40 ( struct V_50 * V_50 , void * V_51 , T_2 * V_65 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
* V_65 = V_6 -> V_65 ;
return 0 ;
}
static int F_41 ( struct V_50 * V_50 , void * V_51 , T_2 * V_65 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
return F_38 ( V_6 -> V_70 , V_71 , V_73 , V_65 ) ;
}
static int F_42 ( struct V_50 * V_50 , void * V_51 ,
struct V_80 * V_81 )
{
if ( V_81 -> V_82 > 1 )
return - V_43 ;
V_81 -> type = V_83 ;
V_81 -> V_65 = V_69 ;
sprintf ( V_81 -> V_84 , L_3 , V_81 -> V_82 ) ;
return 0 ;
}
static int F_43 ( struct V_50 * V_50 , void * V_51 , unsigned int V_85 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
int V_86 ;
if ( V_85 > 1 )
return - V_43 ;
V_86 = F_38 ( V_6 -> V_70 , V_71 , V_87 , V_85 , 0 , 0 ) ;
if ( ! V_86 )
V_6 -> V_88 = V_85 ;
return 0 ;
}
static int F_44 ( struct V_50 * V_50 , void * V_51 , unsigned int * V_85 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
* V_85 = V_6 -> V_88 ;
return 0 ;
}
static int F_45 ( struct V_50 * V_50 , void * V_51 ,
struct V_89 * V_90 )
{
if ( V_90 -> V_82 != 0 )
return - V_43 ;
strcpy ( V_90 -> V_91 , L_4 ) ;
V_90 -> V_92 = V_93 ;
V_90 -> V_94 = 0 ;
return 0 ;
}
static int F_46 ( struct V_50 * V_50 , void * V_51 ,
struct V_31 * V_90 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
int V_95 ;
if ( V_93 != V_90 -> V_32 . V_96 . V_92 ) {
F_47 ( & V_6 -> V_42 , L_5 ) ;
return - V_43 ;
}
if ( V_77 & V_6 -> V_65 )
V_95 = 240 ;
else
V_95 = 288 ;
switch ( V_90 -> V_32 . V_96 . V_13 ) {
default:
case V_97 :
if ( V_95 < V_90 -> V_32 . V_96 . V_98 )
V_90 -> V_32 . V_96 . V_13 = V_14 ;
else
V_90 -> V_32 . V_96 . V_13 = V_99 ;
break;
case V_100 :
case V_99 :
if ( V_95 < V_90 -> V_32 . V_96 . V_98 )
V_90 -> V_32 . V_96 . V_98 = V_95 ;
break;
case V_14 :
break;
}
V_90 -> V_32 . V_96 . V_92 = V_93 ;
V_90 -> V_32 . V_96 . V_98 &= ~ 1 ;
if ( 2 * V_95 < V_90 -> V_32 . V_96 . V_98 )
V_90 -> V_32 . V_96 . V_98 = 2 * V_95 ;
if ( 200 > V_90 -> V_32 . V_96 . V_98 )
V_90 -> V_32 . V_96 . V_98 = 200 ;
V_90 -> V_32 . V_96 . V_15 = 720 ;
V_90 -> V_32 . V_96 . V_101 = V_90 -> V_32 . V_96 . V_15 * 2 ;
V_90 -> V_32 . V_96 . V_38 = V_90 -> V_32 . V_96 . V_15 * 2 * V_90 -> V_32 . V_96 . V_98 ;
V_90 -> V_32 . V_96 . V_102 = V_103 ;
return 0 ;
}
static int F_48 ( struct V_50 * V_50 , void * V_51 ,
struct V_31 * V_90 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
unsigned int V_104 , V_105 , V_106 ;
int V_86 ;
V_86 = F_46 ( V_50 , V_51 , V_90 ) ;
if ( V_86 )
return V_86 ;
if ( F_49 ( & V_6 -> V_28 ) ) {
F_23 ( & V_6 -> V_42 , L_6 ) ;
return - V_107 ;
}
V_6 -> V_12 = V_90 -> V_32 . V_96 ;
switch ( V_6 -> V_12 . V_13 ) {
case V_14 :
V_104 = ( ( V_6 -> V_12 . V_98 / 2 - 1 ) << 16 ) |
( 2 * V_6 -> V_12 . V_15 - 1 ) ;
V_105 = V_104 ;
V_106 = 4 * V_6 -> V_12 . V_15 ;
break;
case V_100 :
V_104 = ( ( V_6 -> V_12 . V_98 - 1 ) << 16 ) |
( 2 * V_6 -> V_12 . V_15 - 1 ) ;
V_105 = ( 0 << 16 ) | ( 2 * V_6 -> V_12 . V_15 - 1 ) ;
V_106 = 2 * V_6 -> V_12 . V_15 ;
break;
case V_99 :
V_104 = ( 0 << 16 ) | ( 2 * V_6 -> V_12 . V_15 - 1 ) ;
V_105 = ( V_6 -> V_12 . V_98 << 16 ) |
( 2 * V_6 -> V_12 . V_15 - 1 ) ;
V_106 = 2 * V_6 -> V_12 . V_15 ;
break;
default:
F_23 ( & V_6 -> V_42 , L_7 ) ;
return - V_43 ;
}
F_8 ( & V_6 -> V_16 ) ;
F_3 ( V_6 , V_108 , 0 ) ;
F_3 ( V_6 , V_109 , 0 ) ;
F_3 ( V_6 , V_110 , V_104 ) ;
F_3 ( V_6 , V_111 , V_105 ) ;
F_3 ( V_6 , V_112 , V_106 ) ;
F_9 ( & V_6 -> V_16 ) ;
return 0 ;
}
static int F_50 ( struct V_50 * V_50 , void * V_51 ,
struct V_31 * V_90 )
{
struct V_5 * V_6 = F_35 ( V_50 ) ;
V_90 -> V_32 . V_96 = V_6 -> V_12 ;
return 0 ;
}
static T_3 F_51 ( int V_113 , struct V_5 * V_6 )
{
unsigned int V_68 ;
V_68 = F_5 ( V_6 , V_114 ) ;
if ( ! V_68 )
return V_115 ;
if ( V_68 & V_116 )
if ( V_6 -> V_117 ++ > 5 )
F_52 ( L_8 ) ;
if ( ( V_68 & V_47 ) && ( V_68 & V_46 ) ) {
return V_118 ;
}
if ( V_68 & V_47 )
if ( ( ++ V_6 -> V_26 ) < 2 )
return V_118 ;
if ( V_68 & V_46 ) {
V_6 -> V_27 ++ ;
return V_118 ;
}
if ( V_6 -> V_24 ) {
F_3 ( V_6 , V_17 , F_5 ( V_6 , V_17 ) & ~ V_18 ) ;
F_53 ( & V_6 -> V_24 -> V_4 . V_119 . V_120 ) ;
V_6 -> V_24 -> V_4 . V_119 . V_40 = V_6 -> V_40 ++ ;
F_32 ( & V_6 -> V_24 -> V_4 , V_121 ) ;
}
return V_118 ;
}
static void F_54 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_16 ) ;
F_5 ( V_6 , V_114 ) ;
F_3 ( V_6 , V_122 , V_123 ) ;
F_3 ( V_6 , V_17 , V_124 ) ;
F_3 ( V_6 , V_17 , 0 ) ;
F_9 ( & V_6 -> V_16 ) ;
}
static void F_55 ( struct V_5 * V_6 )
{
F_8 ( & V_6 -> V_16 ) ;
F_3 ( V_6 , V_45 , 0 ) ;
F_3 ( V_6 , V_17 , V_124 ) ;
F_3 ( V_6 , V_17 , 0 ) ;
F_5 ( V_6 , V_114 ) ;
F_9 ( & V_6 -> V_16 ) ;
}
static int F_56 ( struct V_5 * V_6 )
{
int V_125 ;
V_125 = F_57 ( & V_6 -> V_58 -> V_126 , F_58 ( 29 ) ) ;
if ( V_125 ) {
F_23 ( & V_6 -> V_42 , L_9 ) ;
return V_125 ;
}
memset ( & V_6 -> V_28 , 0 , sizeof( struct V_29 ) ) ;
V_6 -> V_28 . type = V_127 ;
V_6 -> V_28 . V_128 = V_129 | V_130 ;
V_6 -> V_28 . V_131 = V_6 ;
V_6 -> V_28 . V_132 = sizeof( struct V_1 ) ;
V_6 -> V_28 . V_133 = & V_134 ;
V_6 -> V_28 . V_135 = & V_136 ;
V_125 = F_59 ( & V_6 -> V_28 ) ;
if ( V_125 )
return V_125 ;
F_20 ( & V_6 -> V_23 ) ;
F_60 ( & V_6 -> V_22 ) ;
V_6 -> V_39 = F_61 ( & V_6 -> V_58 -> V_126 ) ;
if ( F_62 ( V_6 -> V_39 ) ) {
F_23 ( & V_6 -> V_42 , L_10 ) ;
return F_63 ( V_6 -> V_39 ) ;
}
return 0 ;
}
static void F_64 ( struct V_5 * V_6 )
{
F_65 ( V_6 -> V_39 ) ;
}
static int F_66 ( struct V_5 * V_6 )
{
F_67 ( & V_6 -> V_137 , 0 ) ;
V_6 -> V_42 . V_138 = & V_6 -> V_137 ;
if ( V_6 -> V_137 . error ) {
int V_125 = V_6 -> V_137 . error ;
F_68 ( & V_6 -> V_137 ) ;
return V_125 ;
}
return 0 ;
}
static int F_69 ( struct V_139 * V_126 , int V_140 , int V_141 ,
const char * V_84 )
{
int V_86 ;
if ( V_140 == - 1 )
return 0 ;
V_86 = F_70 ( V_140 , V_84 ) ;
if ( V_86 ) {
F_71 ( V_126 , L_11 , V_140 , V_84 ) ;
return V_86 ;
}
V_86 = F_72 ( V_140 , V_141 ) ;
if ( V_86 ) {
F_71 ( V_126 , L_12 ,
V_140 , V_84 ) ;
F_73 ( V_140 ) ;
return V_86 ;
}
V_86 = F_74 ( V_140 , false ) ;
if ( V_86 ) {
F_71 ( V_126 , L_13 , V_140 , V_84 ) ;
F_73 ( V_140 ) ;
return V_86 ;
}
return 0 ;
}
static void F_75 ( struct V_139 * V_126 , int V_140 , const char * V_84 )
{
if ( V_140 != - 1 ) {
F_76 ( V_126 , L_14 , V_140 , V_84 ) ;
F_77 ( V_140 ) ;
F_73 ( V_140 ) ;
}
}
static int F_78 ( struct V_142 * V_58 ,
const struct V_143 * V_144 )
{
int V_86 ;
struct V_5 * V_6 ;
struct V_145 * V_146 ;
if ( F_79 ( & V_58 -> V_126 , F_58 ( 26 ) ) ) {
F_71 ( & V_58 -> V_126 , L_15 ) ;
return - V_43 ;
}
V_86 = F_80 ( V_58 ) ;
if ( V_86 )
return V_86 ;
V_146 = F_81 ( & V_58 -> V_126 ) ;
if ( ! V_146 ) {
F_82 ( & V_58 -> V_126 , L_16 ) ;
V_86 = - V_43 ;
goto V_147;
}
V_86 = F_69 ( & V_58 -> V_126 , V_146 -> V_148 , 0 ,
V_146 -> V_149 ) ;
if ( V_86 )
goto V_147;
if ( V_146 -> V_150 >= 0 ) {
V_86 = F_69 ( & V_58 -> V_126 , V_146 -> V_150 , 0 ,
V_146 -> V_151 ) ;
if ( V_86 ) {
F_75 ( & V_58 -> V_126 , V_146 -> V_148 ,
V_146 -> V_149 ) ;
goto V_147;
}
}
if ( V_146 -> V_148 != - 1 ) {
F_83 ( 5000 , 25000 ) ;
V_86 = F_72 ( V_146 -> V_148 , 1 ) ;
}
if ( V_146 -> V_150 != - 1 ) {
F_83 ( 5000 , 25000 ) ;
V_86 = F_72 ( V_146 -> V_150 , 1 ) ;
}
F_83 ( 5000 , 25000 ) ;
V_6 = F_84 ( sizeof( struct V_5 ) , V_152 ) ;
if ( ! V_6 ) {
V_86 = - V_153 ;
goto V_154;
}
V_6 -> V_58 = V_58 ;
V_6 -> V_65 = V_155 ;
V_6 -> V_12 = V_79 [ 0 ] ;
V_6 -> V_146 = V_146 ;
V_86 = F_66 ( V_6 ) ;
if ( V_86 )
goto V_156;
V_86 = F_85 ( & V_58 -> V_126 , & V_6 -> V_42 ) ;
if ( V_86 )
goto V_156;
F_76 ( & V_58 -> V_126 , L_17 ,
( unsigned long ) F_86 ( V_58 , 0 ) ,
( unsigned long ) F_87 ( V_58 , 0 ) , V_58 -> V_113 ) ;
F_88 ( V_58 ) ;
V_86 = F_89 ( V_58 , V_55 ) ;
if ( V_86 )
goto V_157;
V_6 -> V_9 = F_90 ( V_58 , 0 , 0x100 ) ;
if ( ! V_6 -> V_9 ) {
V_86 = - V_153 ;
goto V_158;
}
F_91 ( V_58 ) ;
V_86 = F_56 ( V_6 ) ;
if ( V_86 )
goto V_159;
F_60 ( & V_6 -> V_16 ) ;
V_86 = F_92 ( V_58 -> V_113 ,
( V_160 ) F_51 ,
V_161 , V_55 , V_6 ) ;
if ( V_86 ) {
F_71 ( & V_58 -> V_126 , L_18 ) ;
V_86 = - V_162 ;
goto V_163;
}
V_6 -> V_164 = F_93 () ;
if ( ! V_6 -> V_164 ) {
V_86 = - V_153 ;
goto V_165;
}
V_6 -> V_164 = & V_166 ;
V_6 -> V_164 -> V_42 = & V_6 -> V_42 ;
V_6 -> V_164 -> V_167 = & V_6 -> V_28 ;
F_94 ( V_6 -> V_164 , V_6 ) ;
V_86 = F_95 ( V_6 -> V_164 , V_168 , - 1 ) ;
if ( V_86 )
goto V_169;
V_6 -> V_170 = F_96 ( V_6 -> V_146 -> V_171 ) ;
if ( ! V_6 -> V_170 ) {
V_86 = - V_162 ;
F_71 ( & V_58 -> V_126 , L_19 ) ;
goto V_172;
}
V_6 -> V_70 = F_97 ( & V_6 -> V_42 , V_6 -> V_170 ,
L_20 , V_6 -> V_146 -> V_173 ,
NULL ) ;
if ( ! V_6 -> V_70 ) {
V_86 = - V_162 ;
F_71 ( & V_58 -> V_126 , L_21 ) ;
goto V_172;
}
F_98 ( V_6 -> V_170 ) ;
F_38 ( V_6 -> V_70 , V_174 , V_175 , 0 ) ;
F_54 ( V_6 ) ;
F_82 ( & V_58 -> V_126 , L_22 ) ;
return 0 ;
V_172:
F_94 ( V_6 -> V_164 , NULL ) ;
V_169:
if ( F_99 ( V_6 -> V_164 ) )
F_100 ( V_6 -> V_164 ) ;
else
F_101 ( V_6 -> V_164 ) ;
V_165:
F_102 ( V_58 -> V_113 , V_6 ) ;
V_163:
F_64 ( V_6 ) ;
F_103 ( V_58 ) ;
V_159:
F_104 ( & V_6 -> V_28 ) ;
F_105 ( V_58 , V_6 -> V_9 ) ;
V_158:
F_106 ( V_58 ) ;
V_157:
F_107 ( & V_6 -> V_42 ) ;
V_156:
F_108 ( V_6 ) ;
V_154:
F_75 ( & V_58 -> V_126 , V_146 -> V_150 , V_146 -> V_151 ) ;
F_75 ( & V_58 -> V_126 , V_146 -> V_148 , V_146 -> V_149 ) ;
V_147:
return V_86 ;
}
static void F_109 ( struct V_142 * V_58 )
{
struct V_176 * V_42 = F_110 ( V_58 ) ;
struct V_5 * V_6 =
F_2 ( V_42 , struct V_5 , V_42 ) ;
F_55 ( V_6 ) ;
F_94 ( V_6 -> V_164 , NULL ) ;
F_100 ( V_6 -> V_164 ) ;
F_102 ( V_58 -> V_113 , V_6 ) ;
F_103 ( V_58 ) ;
F_104 ( & V_6 -> V_28 ) ;
F_105 ( V_58 , V_6 -> V_9 ) ;
F_106 ( V_58 ) ;
F_107 ( & V_6 -> V_42 ) ;
F_75 ( & V_58 -> V_126 , V_6 -> V_146 -> V_148 ,
V_6 -> V_146 -> V_149 ) ;
F_75 ( & V_58 -> V_126 , V_6 -> V_146 -> V_150 ,
V_6 -> V_146 -> V_151 ) ;
F_108 ( V_6 ) ;
}
static int F_111 ( struct V_142 * V_58 , T_4 V_177 )
{
struct V_176 * V_42 = F_110 ( V_58 ) ;
struct V_5 * V_6 =
F_2 ( V_42 , struct V_5 , V_42 ) ;
unsigned long V_94 ;
int V_85 ;
F_112 ( & V_6 -> V_16 , V_94 ) ;
V_6 -> V_178 [ 0 ] = F_5 ( V_6 , V_17 ) ;
F_3 ( V_6 , V_17 , V_6 -> V_178 [ 0 ] & V_179 ) ;
V_6 -> V_178 [ V_180 ] = F_5 ( V_6 , V_45 ) ;
F_3 ( V_6 , V_45 , 0 ) ;
for ( V_85 = 1 ; V_85 < V_180 ; V_85 ++ )
V_6 -> V_178 [ V_85 ] = F_5 ( V_6 , 4 * V_85 ) ;
for ( V_85 = 0 ; V_85 < V_181 ; V_85 ++ )
V_6 -> V_178 [ V_180 + V_182 + V_85 ] =
F_5 ( V_6 , V_183 [ V_85 ] ) ;
F_113 ( & V_6 -> V_16 , V_94 ) ;
F_114 ( V_58 ) ;
if ( F_115 ( V_58 , F_116 ( V_58 , V_177 ) ) ) {
V_6 -> V_184 = 1 ;
}
F_52 ( L_23 ) ;
return 0 ;
}
static int F_117 ( struct V_142 * V_58 )
{
struct V_176 * V_42 = F_110 ( V_58 ) ;
struct V_5 * V_6 =
F_2 ( V_42 , struct V_5 , V_42 ) ;
unsigned long V_94 ;
int V_86 , V_85 ;
F_52 ( L_24 ) ;
if ( V_6 -> V_184 ) {
V_86 = F_80 ( V_58 ) ;
if ( V_86 ) {
F_118 ( L_25 ) ;
return V_86 ;
}
V_6 -> V_184 = 0 ;
}
V_86 = F_115 ( V_58 , V_185 ) ;
if ( V_86 ) {
F_118 ( L_25 ) ;
V_6 -> V_184 = 1 ;
return V_86 ;
}
F_119 ( V_58 ) ;
F_112 ( & V_6 -> V_16 , V_94 ) ;
for ( V_85 = 1 ; V_85 < V_180 ; V_85 ++ )
F_3 ( V_6 , 4 * V_85 , V_6 -> V_178 [ V_85 ] ) ;
for ( V_85 = 0 ; V_85 < V_181 ; V_85 ++ )
F_3 ( V_6 , V_183 [ V_85 ] ,
V_6 -> V_178 [ V_180 + V_182 + V_85 ] ) ;
F_3 ( V_6 , V_17 , V_6 -> V_178 [ 0 ] ) ;
F_3 ( V_6 , V_45 , V_6 -> V_178 [ V_180 ] ) ;
F_113 ( & V_6 -> V_16 , V_94 ) ;
return 0 ;
}
static int T_5 F_120 ( void )
{
return F_121 ( & V_186 ) ;
}
static void T_6 F_122 ( void )
{
F_123 ( & V_186 ) ;
}
