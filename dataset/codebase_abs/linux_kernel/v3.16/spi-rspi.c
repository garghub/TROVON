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
if ( V_52 ) {
V_59 = F_33 ( V_2 -> V_50 -> V_64 ,
V_52 -> V_65 , V_52 -> V_66 , V_67 ,
V_68 | V_69 ) ;
if ( ! V_59 )
return - V_70 ;
V_61 |= V_47 ;
}
if ( V_53 ) {
V_60 = F_33 ( V_2 -> V_50 -> V_71 ,
V_53 -> V_65 , V_53 -> V_66 , V_72 ,
V_68 | V_69 ) ;
if ( ! V_60 )
return - V_70 ;
V_61 |= V_49 ;
}
if ( V_52 )
F_34 ( V_62 = V_2 -> V_73 ) ;
if ( V_53 && V_2 -> V_74 != V_62 )
F_34 ( V_2 -> V_74 ) ;
F_20 ( V_2 , V_61 ) ;
V_2 -> V_56 = 0 ;
if ( V_53 ) {
V_60 -> V_75 = F_30 ;
V_60 -> V_76 = V_2 ;
V_63 = F_35 ( V_60 ) ;
if ( F_36 ( V_63 ) )
return V_63 ;
F_37 ( V_2 -> V_50 -> V_71 ) ;
}
if ( V_52 ) {
if ( V_53 ) {
V_59 -> V_75 = NULL ;
} else {
V_59 -> V_75 = F_30 ;
V_59 -> V_76 = V_2 ;
}
V_63 = F_35 ( V_59 ) ;
if ( F_36 ( V_63 ) )
return V_63 ;
F_37 ( V_2 -> V_50 -> V_64 ) ;
}
V_40 = F_38 ( V_2 -> V_43 ,
V_2 -> V_56 , V_44 ) ;
if ( V_40 > 0 && V_2 -> V_56 )
V_40 = 0 ;
else if ( ! V_40 )
V_40 = - V_45 ;
F_21 ( V_2 , V_61 ) ;
if ( V_52 )
F_39 ( V_2 -> V_73 ) ;
if ( V_53 && V_2 -> V_74 != V_62 )
F_39 ( V_2 -> V_74 ) ;
return V_40 ;
}
static void F_40 ( const struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_48 )
F_12 ( V_2 ) ;
if ( V_41 & V_77 )
F_1 ( V_2 , F_7 ( V_2 , V_42 ) & ~ V_77 ,
V_42 ) ;
}
static void F_41 ( const struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
F_1 ( V_2 , V_32 | V_33 , V_78 ) ;
F_1 ( V_2 , 0 , V_78 ) ;
}
static void F_42 ( const struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_48 )
F_12 ( V_2 ) ;
F_1 ( V_2 , V_32 | V_33 , V_34 ) ;
F_1 ( V_2 , 0 , V_34 ) ;
}
static bool F_43 ( const struct V_1 * V_2 ,
const struct V_79 * V_80 )
{
return V_80 -> V_81 > V_2 -> V_82 -> V_83 ;
}
static bool F_44 ( struct V_84 * V_50 , struct V_85 * V_86 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_45 ( V_50 ) ;
return F_43 ( V_2 , V_80 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
int V_40 ;
if ( V_2 -> V_50 -> V_87 && F_43 ( V_2 , V_80 ) ) {
return F_32 ( V_2 , & V_80 -> V_88 ,
V_80 -> V_89 ? & V_80 -> V_90 : NULL ) ;
}
V_40 = F_29 ( V_2 , V_80 -> V_91 , V_80 -> V_89 , V_80 -> V_81 ) ;
if ( V_40 < 0 )
return V_40 ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_84 * V_50 , struct V_85 * V_86 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_45 ( V_50 ) ;
T_1 V_92 ;
V_92 = F_7 ( V_2 , V_23 ) ;
if ( V_80 -> V_89 ) {
F_40 ( V_2 ) ;
V_92 &= ~ V_93 ;
} else {
V_92 |= V_93 ;
}
F_1 ( V_2 , V_92 , V_23 ) ;
return F_46 ( V_2 , V_80 ) ;
}
static int F_48 ( struct V_84 * V_50 ,
struct V_85 * V_86 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_45 ( V_50 ) ;
int V_40 ;
F_41 ( V_2 ) ;
return F_46 ( V_2 , V_80 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
F_42 ( V_2 ) ;
return F_46 ( V_2 , V_80 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
int V_40 ;
if ( V_2 -> V_50 -> V_87 && F_43 ( V_2 , V_80 ) )
return F_32 ( V_2 , & V_80 -> V_88 , NULL ) ;
V_40 = F_29 ( V_2 , V_80 -> V_91 , NULL , V_80 -> V_81 ) ;
if ( V_40 < 0 )
return V_40 ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
if ( V_2 -> V_50 -> V_87 && F_43 ( V_2 , V_80 ) )
return F_32 ( V_2 , NULL , & V_80 -> V_90 ) ;
return F_29 ( V_2 , NULL , V_80 -> V_89 , V_80 -> V_81 ) ;
}
static int F_52 ( struct V_84 * V_50 , struct V_85 * V_86 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_45 ( V_50 ) ;
if ( V_86 -> V_94 & V_95 ) {
return F_49 ( V_2 , V_80 ) ;
} else if ( V_80 -> V_96 > V_97 ) {
return F_50 ( V_2 , V_80 ) ;
} else if ( V_80 -> V_98 > V_97 ) {
return F_51 ( V_2 , V_80 ) ;
} else {
return F_49 ( V_2 , V_80 ) ;
}
}
static int F_53 ( struct V_85 * V_86 )
{
struct V_1 * V_2 = F_45 ( V_86 -> V_50 ) ;
V_2 -> V_13 = V_86 -> V_13 ;
V_2 -> V_20 = V_99 ;
if ( V_86 -> V_94 & V_100 )
V_2 -> V_20 |= V_101 ;
if ( V_86 -> V_94 & V_102 )
V_2 -> V_20 |= V_103 ;
V_2 -> V_10 = 0 ;
if ( V_86 -> V_94 & V_95 )
V_2 -> V_10 |= V_104 ;
F_54 ( V_2 , 8 ) ;
return 0 ;
}
static T_2 F_55 ( const struct V_79 * V_80 )
{
if ( V_80 -> V_91 )
switch ( V_80 -> V_96 ) {
case V_105 :
return V_106 ;
case V_107 :
return V_108 ;
default:
return 0 ;
}
if ( V_80 -> V_89 )
switch ( V_80 -> V_98 ) {
case V_105 :
return V_106 | V_109 ;
case V_107 :
return V_108 | V_109 ;
default:
return 0 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
const struct V_110 * V_111 )
{
const struct V_79 * V_80 ;
unsigned int V_112 = 0 , V_81 = 0 ;
T_2 V_113 = 0xffff , V_94 ;
F_57 (xfer, &msg->transfers, transfer_list) {
V_94 = F_55 ( V_80 ) ;
if ( V_94 == V_113 ) {
V_81 += V_80 -> V_81 ;
continue;
}
if ( V_112 ) {
F_5 ( V_2 , V_81 , F_58 ( V_112 - 1 ) ) ;
}
if ( V_112 >= V_114 ) {
F_27 ( & V_111 -> V_86 -> V_51 ,
L_3 ) ;
return - V_115 ;
}
F_3 ( V_2 , V_2 -> V_20 | V_94 , F_59 ( V_112 ) ) ;
V_113 = V_94 ;
V_81 = V_80 -> V_81 ;
V_112 ++ ;
}
if ( V_112 ) {
F_5 ( V_2 , V_81 , F_58 ( V_112 - 1 ) ) ;
F_1 ( V_2 , V_112 - 1 , V_116 ) ;
}
return 0 ;
}
static int F_60 ( struct V_84 * V_50 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 = F_45 ( V_50 ) ;
int V_40 ;
if ( V_111 -> V_86 -> V_94 &
( V_117 | V_118 | V_119 | V_120 ) ) {
V_40 = F_56 ( V_2 , V_111 ) ;
if ( V_40 < 0 )
return V_40 ;
}
F_1 ( V_2 , F_7 ( V_2 , V_23 ) | V_35 , V_23 ) ;
return 0 ;
}
static int F_61 ( struct V_84 * V_50 ,
struct V_110 * V_111 )
{
struct V_1 * V_2 = F_45 ( V_50 ) ;
F_1 ( V_2 , F_7 ( V_2 , V_23 ) & ~ V_35 , V_23 ) ;
F_3 ( V_2 , V_2 -> V_20 , V_21 ) ;
F_1 ( V_2 , 0 , V_116 ) ;
return 0 ;
}
static T_5 F_62 ( int V_121 , void * V_122 )
{
struct V_1 * V_2 = V_122 ;
T_1 V_41 ;
T_5 V_40 = V_123 ;
T_1 F_34 = 0 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_48 )
F_34 |= V_49 ;
if ( V_41 & V_46 )
F_34 |= V_47 ;
if ( F_34 ) {
V_40 = V_124 ;
F_21 ( V_2 , F_34 ) ;
F_63 ( & V_2 -> V_43 ) ;
}
return V_40 ;
}
static T_5 F_64 ( int V_121 , void * V_122 )
{
struct V_1 * V_2 = V_122 ;
T_1 V_41 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_48 ) {
F_21 ( V_2 , V_49 ) ;
F_63 ( & V_2 -> V_43 ) ;
return V_124 ;
}
return 0 ;
}
static T_5 F_65 ( int V_121 , void * V_122 )
{
struct V_1 * V_2 = V_122 ;
T_1 V_41 ;
V_2 -> V_41 = V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 & V_46 ) {
F_21 ( V_2 , V_47 ) ;
F_63 ( & V_2 -> V_43 ) ;
return V_124 ;
}
return 0 ;
}
static struct V_125 * F_66 ( struct V_126 * V_51 ,
enum V_127 V_128 ,
unsigned int V_129 ,
T_6 V_130 )
{
T_7 V_131 ;
struct V_125 * V_132 ;
struct V_133 V_134 ;
int V_40 ;
F_67 ( V_131 ) ;
F_68 ( V_135 , V_131 ) ;
V_132 = F_69 ( V_131 , V_136 ,
( void * ) ( unsigned long ) V_129 ) ;
if ( ! V_132 ) {
F_70 ( V_51 , L_4 ) ;
return NULL ;
}
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_137 = V_129 ;
V_134 . V_138 = V_128 ;
if ( V_128 == V_139 )
V_134 . V_140 = V_130 ;
else
V_134 . V_141 = V_130 ;
V_40 = F_71 ( V_132 , & V_134 ) ;
if ( V_40 ) {
F_70 ( V_51 , L_5 , V_40 ) ;
F_72 ( V_132 ) ;
return NULL ;
}
return V_132 ;
}
static int F_73 ( struct V_126 * V_51 , struct V_84 * V_50 ,
const struct V_142 * V_143 )
{
const struct V_144 * V_145 = F_74 ( V_51 ) ;
if ( ! V_145 || ! V_145 -> V_146 || ! V_145 -> V_147 )
return 0 ;
V_50 -> V_71 = F_66 ( V_51 , V_148 ,
V_145 -> V_146 ,
V_143 -> V_149 + V_7 ) ;
if ( ! V_50 -> V_71 )
return - V_150 ;
V_50 -> V_64 = F_66 ( V_51 , V_139 ,
V_145 -> V_147 ,
V_143 -> V_149 + V_7 ) ;
if ( ! V_50 -> V_64 ) {
F_72 ( V_50 -> V_71 ) ;
V_50 -> V_71 = NULL ;
return - V_150 ;
}
V_50 -> V_87 = F_44 ;
F_75 ( V_51 , L_6 ) ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
if ( V_2 -> V_50 -> V_64 )
F_72 ( V_2 -> V_50 -> V_64 ) ;
if ( V_2 -> V_50 -> V_71 )
F_72 ( V_2 -> V_50 -> V_71 ) ;
}
static int F_77 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = F_78 ( V_152 ) ;
F_76 ( V_2 ) ;
F_79 ( & V_152 -> V_51 ) ;
return 0 ;
}
static int F_80 ( struct V_126 * V_51 , struct V_84 * V_50 )
{
T_3 V_153 ;
int error ;
error = F_81 ( V_51 -> V_154 , L_7 , & V_153 ) ;
if ( error ) {
F_27 ( V_51 , L_8 , error ) ;
return error ;
}
V_50 -> V_155 = V_153 ;
return 0 ;
}
static inline int F_80 ( struct V_126 * V_51 , struct V_84 * V_50 )
{
return - V_115 ;
}
static int F_82 ( struct V_126 * V_51 , unsigned int V_121 ,
T_8 V_156 , const char * V_157 ,
void * V_158 )
{
const char * V_159 = F_83 ( V_51 ) ;
T_9 V_81 = strlen ( V_159 ) + strlen ( V_157 ) + 2 ;
char * V_160 = F_84 ( V_51 , V_81 , V_161 ) ;
if ( ! V_160 )
return - V_162 ;
snprintf ( V_160 , V_81 , L_9 , V_159 , V_157 ) ;
return F_85 ( V_51 , V_121 , V_156 , 0 , V_160 , V_158 ) ;
}
static int F_86 ( struct V_151 * V_152 )
{
struct V_142 * V_143 ;
struct V_84 * V_50 ;
struct V_1 * V_2 ;
int V_40 ;
const struct V_163 * V_164 ;
const struct V_144 * V_145 ;
const struct V_165 * V_82 ;
V_50 = F_87 ( & V_152 -> V_51 , sizeof( struct V_1 ) ) ;
if ( V_50 == NULL ) {
F_27 ( & V_152 -> V_51 , L_10 ) ;
return - V_162 ;
}
V_164 = F_88 ( V_166 , & V_152 -> V_51 ) ;
if ( V_164 ) {
V_82 = V_164 -> V_3 ;
V_40 = F_80 ( & V_152 -> V_51 , V_50 ) ;
if ( V_40 )
goto V_167;
} else {
V_82 = (struct V_165 * ) V_152 -> V_168 -> V_169 ;
V_145 = F_74 ( & V_152 -> V_51 ) ;
if ( V_145 && V_145 -> V_155 )
V_50 -> V_155 = V_145 -> V_155 ;
else
V_50 -> V_155 = 2 ;
} ;
if ( ! V_82 -> F_54 ) {
F_27 ( & V_152 -> V_51 , L_11 ) ;
V_40 = - V_150 ;
goto V_167;
}
V_2 = F_45 ( V_50 ) ;
F_89 ( V_152 , V_2 ) ;
V_2 -> V_82 = V_82 ;
V_2 -> V_50 = V_50 ;
V_143 = F_90 ( V_152 , V_170 , 0 ) ;
V_2 -> V_5 = F_91 ( & V_152 -> V_51 , V_143 ) ;
if ( F_92 ( V_2 -> V_5 ) ) {
V_40 = F_93 ( V_2 -> V_5 ) ;
goto V_167;
}
V_2 -> V_12 = F_94 ( & V_152 -> V_51 , NULL ) ;
if ( F_92 ( V_2 -> V_12 ) ) {
F_27 ( & V_152 -> V_51 , L_12 ) ;
V_40 = F_93 ( V_2 -> V_12 ) ;
goto V_167;
}
F_95 ( & V_152 -> V_51 ) ;
F_96 ( & V_2 -> V_43 ) ;
V_50 -> V_171 = V_152 -> V_129 ;
V_50 -> V_172 = F_53 ;
V_50 -> V_173 = true ;
V_50 -> V_174 = V_82 -> V_174 ;
V_50 -> V_175 = F_60 ;
V_50 -> V_176 = F_61 ;
V_50 -> V_177 = V_82 -> V_177 ;
V_50 -> V_178 = V_82 -> V_178 ;
V_50 -> V_51 . V_154 = V_152 -> V_51 . V_154 ;
V_40 = F_97 ( V_152 , L_13 ) ;
if ( V_40 < 0 ) {
V_40 = F_97 ( V_152 , L_14 ) ;
if ( V_40 < 0 )
V_40 = F_98 ( V_152 , 0 ) ;
if ( V_40 >= 0 )
V_2 -> V_74 = V_2 -> V_73 = V_40 ;
} else {
V_2 -> V_74 = V_40 ;
V_40 = F_97 ( V_152 , L_15 ) ;
if ( V_40 >= 0 )
V_2 -> V_73 = V_40 ;
}
if ( V_40 < 0 ) {
F_27 ( & V_152 -> V_51 , L_16 ) ;
goto V_179;
}
if ( V_2 -> V_74 == V_2 -> V_73 ) {
V_40 = F_82 ( & V_152 -> V_51 , V_2 -> V_74 , F_62 ,
L_14 , V_2 ) ;
} else {
V_40 = F_82 ( & V_152 -> V_51 , V_2 -> V_74 , F_64 ,
L_13 , V_2 ) ;
if ( ! V_40 )
V_40 = F_82 ( & V_152 -> V_51 , V_2 -> V_73 ,
F_65 , L_15 , V_2 ) ;
}
if ( V_40 < 0 ) {
F_27 ( & V_152 -> V_51 , L_17 ) ;
goto V_179;
}
V_40 = F_73 ( & V_152 -> V_51 , V_50 , V_143 ) ;
if ( V_40 < 0 )
F_70 ( & V_152 -> V_51 , L_18 ) ;
V_40 = F_99 ( & V_152 -> V_51 , V_50 ) ;
if ( V_40 < 0 ) {
F_27 ( & V_152 -> V_51 , L_19 ) ;
goto V_180;
}
F_75 ( & V_152 -> V_51 , L_20 ) ;
return 0 ;
V_180:
F_76 ( V_2 ) ;
V_179:
F_79 ( & V_152 -> V_51 ) ;
V_167:
F_100 ( V_50 ) ;
return V_40 ;
}
