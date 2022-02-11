static void F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static void F_3 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
F_4 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( const struct V_1 * V_2 , T_3 V_3 , T_2 V_4 )
{
F_6 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_7 ( const struct V_1 * V_2 , T_2 V_4 )
{
return F_8 ( V_2 -> V_5 + V_4 ) ;
}
static T_2 F_9 ( const struct V_1 * V_2 , T_2 V_4 )
{
return F_10 ( V_2 -> V_5 + V_4 ) ;
}
static void F_11 ( const struct V_1 * V_2 , T_2 V_3 )
{
if ( V_2 -> V_6 )
F_1 ( V_2 , V_3 , V_7 ) ;
else
F_3 ( V_2 , V_3 , V_7 ) ;
}
static T_2 F_12 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
return F_7 ( V_2 , V_7 ) ;
else
return F_9 ( V_2 , V_7 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_9 = F_14 ( F_15 ( V_2 -> V_12 ) ,
2 * V_2 -> V_13 ) - 1 ;
F_1 ( V_2 , F_16 ( V_9 , 0 , 255 ) , V_14 ) ;
F_1 ( V_2 , 0 , V_15 ) ;
V_2 -> V_6 = 0 ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_1 ( V_2 , 0x00 , V_17 ) ;
F_1 ( V_2 , 0x00 , V_18 ) ;
F_1 ( V_2 , 0x00 , V_19 ) ;
V_2 -> V_20 |= F_17 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_9 = F_14 ( F_15 ( V_2 -> V_12 ) ,
2 * V_2 -> V_13 ) - 1 ;
F_1 ( V_2 , F_16 ( V_9 , 0 , 255 ) , V_14 ) ;
F_1 ( V_2 , V_24 , V_15 ) ;
V_2 -> V_6 = 1 ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_1 ( V_2 , 0x00 , V_17 ) ;
F_1 ( V_2 , 0x00 , V_18 ) ;
V_2 -> V_20 |= F_17 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_22 , V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_8 )
{
int V_9 ;
F_1 ( V_2 , V_2 -> V_10 , V_11 ) ;
V_9 = F_14 ( F_15 ( V_2 -> V_12 ) , 2 * V_2 -> V_13 ) ;
F_1 ( V_2 , F_16 ( V_9 , 0 , 255 ) , V_14 ) ;
F_1 ( V_2 , 0 , V_15 ) ;
V_2 -> V_6 = 1 ;
F_1 ( V_2 , 0x00 , V_16 ) ;
F_1 ( V_2 , 0x00 , V_17 ) ;
F_1 ( V_2 , 0x00 , V_18 ) ;
if ( V_8 == 8 )
V_2 -> V_20 |= V_25 ;
else if ( V_8 == 16 )
V_2 -> V_20 |= V_26 ;
else
V_2 -> V_20 |= V_27 ;
V_2 -> V_20 |= V_28 | V_29 | V_30 ;
F_5 ( V_2 , 0 , V_31 ) ;
F_1 ( V_2 , V_32 | V_33 , V_34 ) ;
F_1 ( V_2 , 0x00 , V_34 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_35 | V_22 , V_23 ) ;
return 0 ;
}
static void F_20 ( const struct V_1 * V_2 , T_1 V_36 )
{
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_36 , V_23 ) ;
}
static void F_21 ( const struct V_1 * V_2 , T_1 V_37 )
{
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_37 , V_23 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_38 ,
T_1 V_39 )
{
int V_40 ;
V_2 -> V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_2 -> V_41 & V_38 )
return 0 ;
F_20 ( V_2 , V_39 ) ;
V_40 = F_23 ( V_2 -> V_43 , V_2 -> V_41 & V_38 , V_44 ) ;
if ( V_40 == 0 && ! ( V_2 -> V_41 & V_38 ) )
return - V_45 ;
return 0 ;
}
static inline int F_24 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_46 , V_47 ) ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
return F_22 ( V_2 , V_48 , V_49 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_3 )
{
int error = F_24 ( V_2 ) ;
if ( error < 0 ) {
F_27 ( & V_2 -> V_50 -> V_51 , L_1 ) ;
return error ;
}
F_11 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int error ;
T_1 V_3 ;
error = F_25 ( V_2 ) ;
if ( error < 0 ) {
F_27 ( & V_2 -> V_50 -> V_51 , L_2 ) ;
return error ;
}
V_3 = F_12 ( V_2 ) ;
return V_3 ;
}
static int F_29 ( struct V_1 * V_2 , const T_1 * V_52 , T_1 * V_53 ,
unsigned int V_54 )
{
while ( V_54 -- > 0 ) {
if ( V_52 ) {
int V_40 = F_26 ( V_2 , * V_52 ++ ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_53 ) {
int V_40 = F_28 ( V_2 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_53 ++ = V_40 ;
}
}
return 0 ;
}
static void F_30 ( void * V_55 )
{
struct V_1 * V_2 = V_55 ;
V_2 -> V_56 = 1 ;
F_31 ( & V_2 -> V_43 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_57 * V_52 ,
struct V_57 * V_53 )
{
struct V_58 * V_59 = NULL , * V_60 = NULL ;
T_1 V_61 = 0 ;
unsigned int V_62 = 0 ;
T_4 V_63 ;
int V_40 ;
if ( V_53 ) {
V_60 = F_33 ( V_2 -> V_50 -> V_64 ,
V_53 -> V_65 , V_53 -> V_66 , V_67 ,
V_68 | V_69 ) ;
if ( ! V_60 ) {
V_40 = - V_70 ;
goto V_71;
}
V_60 -> V_72 = F_30 ;
V_60 -> V_73 = V_2 ;
V_63 = F_34 ( V_60 ) ;
if ( F_35 ( V_63 ) ) {
V_40 = V_63 ;
goto V_71;
}
V_61 |= V_49 ;
}
if ( V_52 ) {
V_59 = F_33 ( V_2 -> V_50 -> V_74 ,
V_52 -> V_65 , V_52 -> V_66 , V_75 ,
V_68 | V_69 ) ;
if ( ! V_59 ) {
V_40 = - V_70 ;
goto V_76;
}
if ( V_53 ) {
V_59 -> V_72 = NULL ;
} else {
V_59 -> V_72 = F_30 ;
V_59 -> V_73 = V_2 ;
}
V_63 = F_34 ( V_59 ) ;
if ( F_35 ( V_63 ) ) {
V_40 = V_63 ;
goto V_76;
}
V_61 |= V_47 ;
}
if ( V_52 )
F_36 ( V_62 = V_2 -> V_77 ) ;
if ( V_53 && V_2 -> V_78 != V_62 )
F_36 ( V_2 -> V_78 ) ;
F_20 ( V_2 , V_61 ) ;
V_2 -> V_56 = 0 ;
if ( V_53 )
F_37 ( V_2 -> V_50 -> V_64 ) ;
if ( V_52 )
F_37 ( V_2 -> V_50 -> V_74 ) ;
V_40 = F_38 ( V_2 -> V_43 ,
V_2 -> V_56 , V_44 ) ;
if ( V_40 > 0 && V_2 -> V_56 )
V_40 = 0 ;
else if ( ! V_40 ) {
F_27 ( & V_2 -> V_50 -> V_51 , L_3 ) ;
V_40 = - V_45 ;
if ( V_52 )
F_39 ( V_2 -> V_50 -> V_74 ) ;
if ( V_53 )
F_39 ( V_2 -> V_50 -> V_64 ) ;
}
F_21 ( V_2 , V_61 ) ;
if ( V_52 )
F_40 ( V_2 -> V_77 ) ;
if ( V_53 && V_2 -> V_78 != V_62 )
F_40 ( V_2 -> V_78 ) ;
return V_40 ;
V_76:
if ( V_53 )
F_39 ( V_2 -> V_50 -> V_64 ) ;
V_71:
if ( V_40 == - V_70 ) {
F_41 ( L_4 ,
F_42 ( & V_2 -> V_50 -> V_51 ) ,
F_43 ( & V_2 -> V_50 -> V_51 ) ) ;
}
return V_40 ;
}
static void F_44 ( const struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_48 )
F_12 ( V_2 ) ;
if ( V_41 & V_79 )
F_1 ( V_2 , F_7 ( V_2 , V_42 ) & ~ V_79 ,
V_42 ) ;
}
static void F_45 ( const struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_1 ( V_2 , V_32 | V_33 , V_80 ) ;
F_1 ( V_2 , 0 , V_80 ) ;
}
static void F_46 ( const struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_48 )
F_12 ( V_2 ) ;
F_1 ( V_2 , V_32 | V_33 , V_34 ) ;
F_1 ( V_2 , 0 , V_34 ) ;
}
static bool F_47 ( const struct V_1 * V_2 ,
const struct V_81 * V_82 )
{
return V_82 -> V_83 > V_2 -> V_84 -> V_85 ;
}
static bool F_48 ( struct V_86 * V_50 , struct V_87 * V_88 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_49 ( V_50 ) ;
return F_47 ( V_2 , V_82 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
int V_40 ;
if ( V_2 -> V_50 -> V_89 && F_47 ( V_2 , V_82 ) ) {
V_40 = F_32 ( V_2 , & V_82 -> V_90 ,
V_82 -> V_91 ? & V_82 -> V_92 : NULL ) ;
if ( V_40 != - V_70 )
return V_40 ;
}
V_40 = F_29 ( V_2 , V_82 -> V_93 , V_82 -> V_91 , V_82 -> V_83 ) ;
if ( V_40 < 0 )
return V_40 ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_86 * V_50 , struct V_87 * V_88 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_49 ( V_50 ) ;
T_1 V_94 ;
V_94 = F_7 ( V_2 , V_23 ) ;
if ( V_82 -> V_91 ) {
F_44 ( V_2 ) ;
V_94 &= ~ V_95 ;
} else {
V_94 |= V_95 ;
}
F_1 ( V_2 , V_94 , V_23 ) ;
return F_50 ( V_2 , V_82 ) ;
}
static int F_52 ( struct V_86 * V_50 ,
struct V_87 * V_88 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_49 ( V_50 ) ;
F_45 ( V_2 ) ;
return F_50 ( V_2 , V_82 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_81 * V_82 )
{
F_46 ( V_2 ) ;
return F_50 ( V_2 , V_82 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
int V_40 ;
if ( V_2 -> V_50 -> V_89 && F_47 ( V_2 , V_82 ) ) {
V_40 = F_32 ( V_2 , & V_82 -> V_90 , NULL ) ;
if ( V_40 != - V_70 )
return V_40 ;
}
V_40 = F_29 ( V_2 , V_82 -> V_93 , NULL , V_82 -> V_83 ) ;
if ( V_40 < 0 )
return V_40 ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
if ( V_2 -> V_50 -> V_89 && F_47 ( V_2 , V_82 ) ) {
int V_40 = F_32 ( V_2 , NULL , & V_82 -> V_92 ) ;
if ( V_40 != - V_70 )
return V_40 ;
}
return F_29 ( V_2 , NULL , V_82 -> V_91 , V_82 -> V_83 ) ;
}
static int F_56 ( struct V_86 * V_50 , struct V_87 * V_88 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_49 ( V_50 ) ;
if ( V_88 -> V_96 & V_97 ) {
return F_53 ( V_2 , V_82 ) ;
} else if ( V_82 -> V_98 > V_99 ) {
return F_54 ( V_2 , V_82 ) ;
} else if ( V_82 -> V_100 > V_99 ) {
return F_55 ( V_2 , V_82 ) ;
} else {
return F_53 ( V_2 , V_82 ) ;
}
}
static int F_57 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_49 ( V_88 -> V_50 ) ;
V_2 -> V_13 = V_88 -> V_13 ;
V_2 -> V_20 = V_101 ;
if ( V_88 -> V_96 & V_102 )
V_2 -> V_20 |= V_103 ;
if ( V_88 -> V_96 & V_104 )
V_2 -> V_20 |= V_105 ;
V_2 -> V_10 = 0 ;
if ( V_88 -> V_96 & V_97 )
V_2 -> V_10 |= V_106 ;
F_58 ( V_2 , 8 ) ;
return 0 ;
}
static T_2 F_59 ( const struct V_81 * V_82 )
{
if ( V_82 -> V_93 )
switch ( V_82 -> V_98 ) {
case V_107 :
return V_108 ;
case V_109 :
return V_110 ;
default:
return 0 ;
}
if ( V_82 -> V_91 )
switch ( V_82 -> V_100 ) {
case V_107 :
return V_108 | V_111 ;
case V_109 :
return V_110 | V_111 ;
default:
return 0 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
const struct V_112 * V_113 )
{
const struct V_81 * V_82 ;
unsigned int V_114 = 0 , V_83 = 0 ;
T_2 V_115 = 0xffff , V_96 ;
F_61 (xfer, &msg->transfers, transfer_list) {
V_96 = F_59 ( V_82 ) ;
if ( V_96 == V_115 ) {
V_83 += V_82 -> V_83 ;
continue;
}
if ( V_114 ) {
F_5 ( V_2 , V_83 , F_62 ( V_114 - 1 ) ) ;
}
if ( V_114 >= V_116 ) {
F_27 ( & V_113 -> V_88 -> V_51 ,
L_5 ) ;
return - V_117 ;
}
F_3 ( V_2 , V_2 -> V_20 | V_96 , F_63 ( V_114 ) ) ;
V_115 = V_96 ;
V_83 = V_82 -> V_83 ;
V_114 ++ ;
}
if ( V_114 ) {
F_5 ( V_2 , V_83 , F_62 ( V_114 - 1 ) ) ;
F_1 ( V_2 , V_114 - 1 , V_118 ) ;
}
return 0 ;
}
static int F_64 ( struct V_86 * V_50 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_49 ( V_50 ) ;
int V_40 ;
if ( V_113 -> V_88 -> V_96 &
( V_119 | V_120 | V_121 | V_122 ) ) {
V_40 = F_60 ( V_2 , V_113 ) ;
if ( V_40 < 0 )
return V_40 ;
}
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_35 , V_23 ) ;
return 0 ;
}
static int F_65 ( struct V_86 * V_50 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_49 ( V_50 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_35 , V_23 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , 0 , V_118 ) ;
return 0 ;
}
static T_5 F_66 ( int V_123 , void * V_124 )
{
struct V_1 * V_2 = V_124 ;
T_1 V_41 ;
T_5 V_40 = V_125 ;
T_1 F_36 = 0 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_48 )
F_36 |= V_49 ;
if ( V_41 & V_46 )
F_36 |= V_47 ;
if ( F_36 ) {
V_40 = V_126 ;
F_21 ( V_2 , F_36 ) ;
F_67 ( & V_2 -> V_43 ) ;
}
return V_40 ;
}
static T_5 F_68 ( int V_123 , void * V_124 )
{
struct V_1 * V_2 = V_124 ;
T_1 V_41 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_48 ) {
F_21 ( V_2 , V_49 ) ;
F_67 ( & V_2 -> V_43 ) ;
return V_126 ;
}
return 0 ;
}
static T_5 F_69 ( int V_123 , void * V_124 )
{
struct V_1 * V_2 = V_124 ;
T_1 V_41 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_46 ) {
F_21 ( V_2 , V_47 ) ;
F_67 ( & V_2 -> V_43 ) ;
return V_126 ;
}
return 0 ;
}
static struct V_127 * F_70 ( struct V_128 * V_51 ,
enum V_129 V_130 ,
unsigned int V_131 ,
T_6 V_132 )
{
T_7 V_133 ;
struct V_127 * V_134 ;
struct V_135 V_136 ;
int V_40 ;
F_71 ( V_133 ) ;
F_72 ( V_137 , V_133 ) ;
V_134 = F_73 ( V_133 , V_138 ,
( void * ) ( unsigned long ) V_131 , V_51 ,
V_130 == V_139 ? L_6 : L_7 ) ;
if ( ! V_134 ) {
F_74 ( V_51 , L_8 ) ;
return NULL ;
}
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
V_136 . V_140 = V_131 ;
V_136 . V_141 = V_130 ;
if ( V_130 == V_139 ) {
V_136 . V_142 = V_132 ;
V_136 . V_143 = V_144 ;
} else {
V_136 . V_145 = V_132 ;
V_136 . V_146 = V_144 ;
}
V_40 = F_75 ( V_134 , & V_136 ) ;
if ( V_40 ) {
F_74 ( V_51 , L_9 , V_40 ) ;
F_76 ( V_134 ) ;
return NULL ;
}
return V_134 ;
}
static int F_77 ( struct V_128 * V_51 , struct V_86 * V_50 ,
const struct V_147 * V_148 )
{
const struct V_149 * V_150 = F_78 ( V_51 ) ;
unsigned int V_151 , V_152 ;
if ( V_51 -> V_153 ) {
V_151 = 0 ;
V_152 = 0 ;
} else if ( V_150 && V_150 -> V_151 && V_150 -> V_152 ) {
V_151 = V_150 -> V_151 ;
V_152 = V_150 -> V_152 ;
} else {
return 0 ;
}
V_50 -> V_74 = F_70 ( V_51 , V_139 , V_151 ,
V_148 -> V_154 + V_7 ) ;
if ( ! V_50 -> V_74 )
return - V_155 ;
V_50 -> V_64 = F_70 ( V_51 , V_156 , V_152 ,
V_148 -> V_154 + V_7 ) ;
if ( ! V_50 -> V_64 ) {
F_76 ( V_50 -> V_74 ) ;
V_50 -> V_74 = NULL ;
return - V_155 ;
}
V_50 -> V_89 = F_48 ;
F_79 ( V_51 , L_10 ) ;
return 0 ;
}
static void F_80 ( struct V_86 * V_50 )
{
if ( V_50 -> V_74 )
F_76 ( V_50 -> V_74 ) ;
if ( V_50 -> V_64 )
F_76 ( V_50 -> V_64 ) ;
}
static int F_81 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_82 ( V_158 ) ;
F_80 ( V_2 -> V_50 ) ;
F_83 ( & V_158 -> V_51 ) ;
return 0 ;
}
static int F_84 ( struct V_128 * V_51 , struct V_86 * V_50 )
{
T_3 V_159 ;
int error ;
error = F_85 ( V_51 -> V_153 , L_11 , & V_159 ) ;
if ( error ) {
F_27 ( V_51 , L_12 , error ) ;
return error ;
}
V_50 -> V_160 = V_159 ;
return 0 ;
}
static inline int F_84 ( struct V_128 * V_51 , struct V_86 * V_50 )
{
return - V_117 ;
}
static int F_86 ( struct V_128 * V_51 , unsigned int V_123 ,
T_8 V_161 , const char * V_162 ,
void * V_163 )
{
const char * V_164 = F_87 ( V_51 , V_165 , L_13 ,
F_43 ( V_51 ) , V_162 ) ;
if ( ! V_164 )
return - V_166 ;
return F_88 ( V_51 , V_123 , V_161 , 0 , V_164 , V_163 ) ;
}
static int F_89 ( struct V_157 * V_158 )
{
struct V_147 * V_148 ;
struct V_86 * V_50 ;
struct V_1 * V_2 ;
int V_40 ;
const struct V_167 * V_168 ;
const struct V_149 * V_150 ;
const struct V_169 * V_84 ;
V_50 = F_90 ( & V_158 -> V_51 , sizeof( struct V_1 ) ) ;
if ( V_50 == NULL ) {
F_27 ( & V_158 -> V_51 , L_14 ) ;
return - V_166 ;
}
V_168 = F_91 ( V_170 , & V_158 -> V_51 ) ;
if ( V_168 ) {
V_84 = V_168 -> V_3 ;
V_40 = F_84 ( & V_158 -> V_51 , V_50 ) ;
if ( V_40 )
goto V_171;
} else {
V_84 = (struct V_169 * ) V_158 -> V_172 -> V_173 ;
V_150 = F_78 ( & V_158 -> V_51 ) ;
if ( V_150 && V_150 -> V_160 )
V_50 -> V_160 = V_150 -> V_160 ;
else
V_50 -> V_160 = 2 ;
}
if ( ! V_84 -> F_58 ) {
F_27 ( & V_158 -> V_51 , L_15 ) ;
V_40 = - V_155 ;
goto V_171;
}
V_2 = F_49 ( V_50 ) ;
F_92 ( V_158 , V_2 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_50 = V_50 ;
V_148 = F_93 ( V_158 , V_174 , 0 ) ;
V_2 -> V_5 = F_94 ( & V_158 -> V_51 , V_148 ) ;
if ( F_95 ( V_2 -> V_5 ) ) {
V_40 = F_96 ( V_2 -> V_5 ) ;
goto V_171;
}
V_2 -> V_12 = F_97 ( & V_158 -> V_51 , NULL ) ;
if ( F_95 ( V_2 -> V_12 ) ) {
F_27 ( & V_158 -> V_51 , L_16 ) ;
V_40 = F_96 ( V_2 -> V_12 ) ;
goto V_171;
}
F_98 ( & V_158 -> V_51 ) ;
F_99 ( & V_2 -> V_43 ) ;
V_50 -> V_175 = V_158 -> V_131 ;
V_50 -> V_176 = F_57 ;
V_50 -> V_177 = true ;
V_50 -> V_178 = V_84 -> V_178 ;
V_50 -> V_179 = F_64 ;
V_50 -> V_180 = F_65 ;
V_50 -> V_181 = V_84 -> V_181 ;
V_50 -> V_182 = V_84 -> V_182 ;
V_50 -> V_51 . V_153 = V_158 -> V_51 . V_153 ;
V_40 = F_100 ( V_158 , L_7 ) ;
if ( V_40 < 0 ) {
V_40 = F_100 ( V_158 , L_17 ) ;
if ( V_40 < 0 )
V_40 = F_101 ( V_158 , 0 ) ;
if ( V_40 >= 0 )
V_2 -> V_78 = V_2 -> V_77 = V_40 ;
} else {
V_2 -> V_78 = V_40 ;
V_40 = F_100 ( V_158 , L_6 ) ;
if ( V_40 >= 0 )
V_2 -> V_77 = V_40 ;
}
if ( V_40 < 0 ) {
F_27 ( & V_158 -> V_51 , L_18 ) ;
goto V_183;
}
if ( V_2 -> V_78 == V_2 -> V_77 ) {
V_40 = F_86 ( & V_158 -> V_51 , V_2 -> V_78 , F_66 ,
L_17 , V_2 ) ;
} else {
V_40 = F_86 ( & V_158 -> V_51 , V_2 -> V_78 , F_68 ,
L_7 , V_2 ) ;
if ( ! V_40 )
V_40 = F_86 ( & V_158 -> V_51 , V_2 -> V_77 ,
F_69 , L_6 , V_2 ) ;
}
if ( V_40 < 0 ) {
F_27 ( & V_158 -> V_51 , L_19 ) ;
goto V_183;
}
V_40 = F_77 ( & V_158 -> V_51 , V_50 , V_148 ) ;
if ( V_40 < 0 )
F_74 ( & V_158 -> V_51 , L_20 ) ;
V_40 = F_102 ( & V_158 -> V_51 , V_50 ) ;
if ( V_40 < 0 ) {
F_27 ( & V_158 -> V_51 , L_21 ) ;
goto V_184;
}
F_79 ( & V_158 -> V_51 , L_22 ) ;
return 0 ;
V_184:
F_80 ( V_50 ) ;
V_183:
F_83 ( & V_158 -> V_51 ) ;
V_171:
F_103 ( V_50 ) ;
return V_40 ;
}
