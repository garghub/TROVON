static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
char * V_8 ;
T_5 V_9 = 0 ;
T_1 V_10 ;
V_8 = F_2 ( V_11 , V_12 ) ;
if ( ! V_8 )
return 0 ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_1 , F_3 ( & V_6 -> V_13 -> V_14 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_2 ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_3 , F_4 ( V_6 , V_15 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_4 , F_4 ( V_6 , V_16 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_5 , F_4 ( V_6 , V_17 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_6 , F_4 ( V_6 , V_18 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_7 , F_4 ( V_6 , V_19 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_8 , F_4 ( V_6 , V_20 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_9 , F_4 ( V_6 , V_21 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_10 , F_4 ( V_6 , V_22 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_11 , F_4 ( V_6 , V_23 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_12 , F_4 ( V_6 , V_24 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_13 , F_4 ( V_6 , V_25 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_14 , F_4 ( V_6 , V_26 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_15 , F_4 ( V_6 , V_27 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_16 , F_4 ( V_6 , V_28 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_17 , F_4 ( V_6 , V_29 ) ) ;
V_9 += snprintf ( V_8 + V_9 , V_11 - V_9 ,
L_2 ) ;
V_10 = F_5 ( V_2 , V_3 , V_4 , V_8 , V_9 ) ;
F_6 ( V_8 ) ;
return V_10 ;
}
static int F_7 ( struct V_5 * V_6 )
{
V_6 -> V_30 = F_8 ( L_18 , NULL ) ;
if ( ! V_6 -> V_30 )
return - V_31 ;
F_9 ( L_19 , V_32 | V_33 ,
V_6 -> V_30 , ( void * ) V_6 , & V_34 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_6 )
{
F_11 ( V_6 -> V_30 ) ;
}
static inline int F_7 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline void F_10 ( struct V_5 * V_6 )
{
}
static inline T_5 F_12 ( struct V_5 * V_6 )
{
T_5 V_35 , V_36 , V_37 ;
V_35 = ( V_6 -> V_38 - V_6 -> V_39 ) / V_6 -> V_40 ;
V_36 = V_6 -> V_41 - F_13 ( V_6 , V_22 ) ;
V_37 = ( ( V_6 -> V_42 - V_6 -> V_43 ) - ( V_6 -> V_38 - V_6 -> V_39 ) )
/ V_6 -> V_40 ;
return F_14 ( V_35 , V_36 , ( T_5 ) ( V_6 -> V_41 - V_37 ) ) ;
}
static inline T_5 F_15 ( struct V_5 * V_6 )
{
T_5 V_44 = ( V_6 -> V_42 - V_6 -> V_43 ) / V_6 -> V_40 ;
return F_16 ( T_5 , V_44 , F_13 ( V_6 , V_23 ) ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
T_5 V_45 = F_12 ( V_6 ) ;
T_6 V_46 = 0 ;
while ( V_45 -- ) {
if ( V_6 -> V_38 - V_6 -> V_9 ) {
if ( V_6 -> V_40 == 1 )
V_46 = * ( V_47 * ) ( V_6 -> V_39 ) ;
else
V_46 = * ( T_6 * ) ( V_6 -> V_39 ) ;
}
F_18 ( V_6 , V_48 , V_46 ) ;
V_6 -> V_39 += V_6 -> V_40 ;
}
}
static void F_19 ( struct V_5 * V_6 )
{
T_5 V_45 = F_15 ( V_6 ) ;
T_6 V_49 ;
while ( V_45 -- ) {
V_49 = F_13 ( V_6 , V_48 ) ;
if ( V_6 -> V_42 - V_6 -> V_9 ) {
if ( V_6 -> V_40 == 1 )
* ( V_47 * ) ( V_6 -> V_43 ) = V_49 ;
else
* ( T_6 * ) ( V_6 -> V_43 ) = V_49 ;
}
V_6 -> V_43 += V_6 -> V_40 ;
}
}
static void * F_20 ( struct V_5 * V_6 )
{
struct V_50 * V_51 = V_6 -> V_52 ;
struct V_53 * V_54 = V_6 -> V_55 ;
if ( V_54 -> V_56 . V_57 != & V_51 -> V_58 ) {
V_6 -> V_55 =
F_21 ( V_54 -> V_56 . V_57 ,
struct V_53 ,
V_56 ) ;
return V_59 ;
}
return V_60 ;
}
static int F_22 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_52 -> V_61
|| ! V_6 -> V_62
|| ! V_6 -> V_63 -> V_64
|| ! V_6 -> V_65 )
return 0 ;
if ( V_6 -> V_55 -> V_66 )
V_6 -> V_66 = V_6 -> V_55 -> V_66 ;
if ( V_6 -> V_55 -> V_67 )
V_6 -> V_67 = V_6 -> V_55 -> V_67 ;
return 1 ;
}
static void F_23 ( struct V_5 * V_6 )
{
struct V_53 * V_68 ;
struct V_50 * V_51 ;
V_51 = V_6 -> V_52 ;
V_6 -> V_52 = NULL ;
V_6 -> V_55 = NULL ;
V_6 -> V_69 = V_6 -> V_63 ;
V_6 -> V_63 = NULL ;
V_6 -> V_70 = 0 ;
V_68 = F_24 ( & V_51 -> V_58 , struct V_53 ,
V_56 ) ;
if ( ! V_68 -> V_71 )
F_25 ( V_6 , V_51 -> V_72 , 0 ) ;
F_26 ( V_6 -> V_13 ) ;
}
static void F_27 ( struct V_5 * V_6 , const char * V_51 )
{
F_28 ( V_6 , 0 ) ;
F_29 ( & V_6 -> V_13 -> V_14 , L_20 , V_51 ) ;
V_6 -> V_52 -> V_73 = V_74 ;
F_30 ( & V_6 -> V_75 ) ;
}
void F_31 ( struct V_5 * V_6 )
{
V_6 -> V_52 -> V_76 += V_6 -> V_9 ;
V_6 -> V_52 -> V_73 = F_20 ( V_6 ) ;
if ( V_6 -> V_52 -> V_73 == V_60 ) {
V_6 -> V_52 -> V_77 = 0 ;
F_23 ( V_6 ) ;
} else
F_30 ( & V_6 -> V_75 ) ;
}
static T_7 F_32 ( struct V_5 * V_6 )
{
T_6 V_78 = F_13 ( V_6 , V_26 ) ;
if ( V_78 & ( V_79 | V_80 | V_81 ) ) {
F_13 ( V_6 , V_82 ) ;
F_13 ( V_6 , V_83 ) ;
F_13 ( V_6 , V_84 ) ;
F_27 ( V_6 , L_21 ) ;
return V_85 ;
}
F_19 ( V_6 ) ;
if ( V_6 -> V_42 == V_6 -> V_43 ) {
F_33 ( V_6 , V_86 ) ;
F_31 ( V_6 ) ;
return V_85 ;
}
if ( V_78 & V_86 ) {
F_33 ( V_6 , V_86 ) ;
F_17 ( V_6 ) ;
F_34 ( V_6 , V_86 ) ;
}
return V_85 ;
}
static T_7 F_35 ( int V_87 , void * V_88 )
{
struct V_5 * V_6 = V_88 ;
T_6 V_78 = F_13 ( V_6 , V_26 ) & 0x3f ;
if ( ! V_78 )
return V_89 ;
if ( ! V_6 -> V_52 ) {
F_33 ( V_6 , V_86 ) ;
return V_85 ;
}
return V_6 -> V_90 ( V_6 ) ;
}
static void F_36 ( struct V_5 * V_6 )
{
do {
F_17 ( V_6 ) ;
F_19 ( V_6 ) ;
F_37 () ;
} while ( V_6 -> V_42 > V_6 -> V_43 );
F_31 ( V_6 ) ;
}
static void V_75 ( unsigned long V_91 )
{
struct V_5 * V_6 = (struct V_5 * ) V_91 ;
struct V_50 * V_92 = NULL ;
struct V_53 * V_93 = NULL ;
struct V_53 * V_94 = NULL ;
struct V_95 * V_72 = NULL ;
struct V_96 * V_97 = NULL ;
V_47 V_98 = 0 ;
V_47 V_99 = 0 ;
V_47 V_71 = 0 ;
T_6 V_100 = 0 ;
T_6 V_101 = 0 ;
T_5 V_102 = 0 ;
T_5 V_103 = 0 ;
V_92 = V_6 -> V_52 ;
V_93 = V_6 -> V_55 ;
V_97 = V_6 -> V_63 ;
V_72 = V_92 -> V_72 ;
if ( V_92 -> V_73 == V_74 ) {
V_92 -> V_77 = - V_104 ;
goto V_105;
}
if ( V_92 -> V_73 == V_60 ) {
V_92 -> V_77 = 0 ;
goto V_105;
}
if ( V_92 -> V_73 == V_59 ) {
V_94 = F_21 ( V_93 -> V_56 . V_106 ,
struct V_53 ,
V_56 ) ;
if ( V_94 -> V_107 )
F_38 ( V_94 -> V_107 ) ;
}
V_6 -> V_40 = V_97 -> V_40 ;
V_6 -> V_108 = V_97 -> V_108 ;
V_6 -> V_109 = V_97 -> V_109 ;
V_6 -> V_67 = V_93 -> V_67 ;
V_6 -> V_66 = V_93 -> V_66 ;
V_6 -> V_39 = ( void * ) V_93 -> V_110 ;
V_6 -> V_38 = V_6 -> V_39 + V_93 -> V_9 ;
V_6 -> V_43 = V_93 -> V_111 ;
V_6 -> V_42 = V_6 -> V_43 + V_93 -> V_9 ;
V_6 -> V_9 = V_6 -> V_55 -> V_9 ;
if ( V_97 != V_6 -> V_69 )
V_71 = 1 ;
V_103 = V_97 -> V_103 ;
if ( V_93 -> V_112 ) {
V_102 = V_97 -> V_112 ;
if ( ( V_93 -> V_112 != V_102 ) || ( ! V_97 -> V_101 ) ) {
V_102 = V_93 -> V_112 ;
V_101 = V_6 -> V_113 / V_102 ;
V_101 = ( V_101 + 1 ) & 0xfffe ;
V_97 -> V_112 = V_102 ;
V_97 -> V_101 = V_101 ;
}
}
if ( V_93 -> V_114 ) {
V_98 = V_93 -> V_114 ;
V_6 -> V_40 = V_6 -> V_108 = V_98 >> 3 ;
V_103 = ( V_98 - 1 )
| ( V_97 -> type << V_115 )
| ( V_72 -> V_116 << V_117 )
| ( V_97 -> V_118 << V_119 ) ;
}
V_92 -> V_73 = V_59 ;
if ( V_6 -> V_109 ) {
if ( V_6 -> V_43 && V_6 -> V_39 )
V_97 -> V_118 = V_120 ;
else if ( V_6 -> V_43 )
V_97 -> V_118 = V_121 ;
else
V_97 -> V_118 = V_122 ;
V_103 &= ~ V_123 ;
V_103 |= ( V_97 -> V_118 << V_119 ) ;
}
V_6 -> V_70 = F_22 ( V_6 ) ;
if ( ! V_6 -> V_70 && ! V_97 -> V_124 ) {
int V_125 = V_6 -> V_9 / V_6 -> V_40 ;
V_100 = V_6 -> V_41 / 2 ;
V_100 = ( V_125 > V_100 ) ? V_100 : V_125 ;
V_99 |= V_86 | V_79 |
V_81 | V_80 ;
V_6 -> V_90 = F_32 ;
}
if ( F_13 ( V_6 , V_15 ) != V_103 || V_71 || V_101 || V_99 ) {
F_28 ( V_6 , 0 ) ;
if ( F_13 ( V_6 , V_15 ) != V_103 )
F_18 ( V_6 , V_15 , V_103 ) ;
F_39 ( V_6 , V_101 ? V_101 : V_97 -> V_101 ) ;
F_25 ( V_6 , V_72 , 1 ) ;
F_33 ( V_6 , 0xff ) ;
if ( V_99 )
F_34 ( V_6 , V_99 ) ;
if ( V_100 )
F_18 ( V_6 , V_20 , V_100 ) ;
F_28 ( V_6 , 1 ) ;
if ( V_71 )
V_6 -> V_69 = V_97 ;
}
if ( V_6 -> V_70 )
V_6 -> V_65 -> V_126 ( V_6 , V_71 ) ;
if ( V_97 -> V_124 )
F_36 ( V_6 ) ;
return;
V_105:
F_23 ( V_6 ) ;
}
static int F_40 ( struct V_127 * V_13 ,
struct V_50 * V_51 )
{
struct V_5 * V_6 = F_41 ( V_13 ) ;
V_6 -> V_52 = V_51 ;
V_6 -> V_52 -> V_73 = V_128 ;
V_6 -> V_55 = F_21 ( V_6 -> V_52 -> V_58 . V_57 ,
struct V_53 ,
V_56 ) ;
V_6 -> V_63 = F_42 ( V_6 -> V_52 -> V_72 ) ;
F_30 ( & V_6 -> V_75 ) ;
return 0 ;
}
static int F_43 ( struct V_95 * V_72 )
{
struct V_129 * V_130 = NULL ;
struct V_96 * V_97 ;
int V_10 ;
V_97 = F_42 ( V_72 ) ;
if ( ! V_97 ) {
V_97 = F_2 ( sizeof( struct V_96 ) , V_12 ) ;
if ( ! V_97 )
return - V_31 ;
F_44 ( V_72 , V_97 ) ;
}
V_130 = V_72 -> V_131 ;
if ( V_130 ) {
if ( V_130 -> V_109 )
V_97 -> V_109 = V_130 -> V_109 ;
V_97 -> V_124 = V_130 -> V_124 ;
V_97 -> type = V_130 -> type ;
V_97 -> V_132 = 0 ;
V_97 -> V_133 = 0 ;
V_97 -> V_64 = V_130 -> V_64 ;
}
if ( V_72 -> V_114 == 8 ) {
V_97 -> V_40 = 1 ;
V_97 -> V_108 = 1 ;
} else if ( V_72 -> V_114 == 16 ) {
V_97 -> V_40 = 2 ;
V_97 -> V_108 = 2 ;
}
V_97 -> V_114 = V_72 -> V_114 ;
if ( ! V_72 -> V_134 ) {
F_29 ( & V_72 -> V_14 , L_22 ) ;
return - V_135 ;
}
V_97 -> V_118 = 0 ;
V_97 -> V_103 = ( V_97 -> V_114 - 1 )
| ( V_97 -> type << V_115 )
| ( V_72 -> V_116 << V_117 )
| ( V_97 -> V_118 << V_119 ) ;
if ( V_72 -> V_116 & V_136 )
V_97 -> V_103 |= 1 << V_137 ;
if ( F_45 ( V_72 -> V_138 ) ) {
V_10 = F_46 ( V_72 -> V_138 ,
! ( V_72 -> V_116 & V_139 ) ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_47 ( struct V_95 * V_72 )
{
struct V_96 * V_97 = F_42 ( V_72 ) ;
F_6 ( V_97 ) ;
F_44 ( V_72 , NULL ) ;
}
static void F_48 ( struct V_140 * V_14 , struct V_5 * V_6 )
{
F_28 ( V_6 , 0 ) ;
F_33 ( V_6 , 0xff ) ;
F_28 ( V_6 , 1 ) ;
if ( ! V_6 -> V_41 ) {
T_5 V_141 ;
for ( V_141 = 1 ; V_141 < 256 ; V_141 ++ ) {
F_18 ( V_6 , V_20 , V_141 ) ;
if ( V_141 != F_13 ( V_6 , V_20 ) )
break;
}
F_18 ( V_6 , V_20 , 0 ) ;
V_6 -> V_41 = ( V_141 == 1 ) ? 0 : V_141 ;
F_49 ( V_14 , L_23 , V_6 -> V_41 ) ;
}
}
int F_50 ( struct V_140 * V_14 , struct V_5 * V_6 )
{
struct V_127 * V_13 ;
int V_10 ;
F_51 ( V_6 == NULL ) ;
V_13 = F_52 ( V_14 , 0 ) ;
if ( ! V_13 )
return - V_31 ;
V_6 -> V_13 = V_13 ;
V_6 -> type = V_142 ;
V_6 -> V_69 = NULL ;
V_6 -> V_62 = 0 ;
V_6 -> V_143 = ( V_144 ) ( V_6 -> V_145 + 0x60 ) ;
snprintf ( V_6 -> V_146 , sizeof( V_6 -> V_146 ) , L_24 , V_6 -> V_147 ) ;
V_10 = F_53 ( V_14 , V_6 -> V_87 , F_35 , V_148 ,
V_6 -> V_146 , V_6 ) ;
if ( V_10 < 0 ) {
F_29 ( & V_13 -> V_14 , L_25 ) ;
goto V_149;
}
V_13 -> V_150 = V_151 | V_152 | V_136 ;
V_13 -> V_153 = F_54 ( 8 ) | F_54 ( 16 ) ;
V_13 -> V_147 = V_6 -> V_147 ;
V_13 -> V_154 = V_6 -> V_155 ;
V_13 -> V_156 = F_43 ;
V_13 -> V_157 = F_47 ;
V_13 -> V_158 = F_40 ;
V_13 -> V_134 = V_6 -> V_113 ;
V_13 -> V_14 . V_159 = V_14 -> V_159 ;
F_48 ( V_14 , V_6 ) ;
if ( V_6 -> V_65 && V_6 -> V_65 -> V_160 ) {
V_10 = V_6 -> V_65 -> V_160 ( V_6 ) ;
if ( V_10 ) {
F_55 ( V_14 , L_26 ) ;
V_6 -> V_62 = 0 ;
}
}
F_56 ( & V_6 -> V_75 , V_75 , ( unsigned long ) V_6 ) ;
F_57 ( V_13 , V_6 ) ;
V_10 = F_58 ( V_14 , V_13 ) ;
if ( V_10 ) {
F_29 ( & V_13 -> V_14 , L_27 ) ;
goto V_161;
}
F_7 ( V_6 ) ;
return 0 ;
V_161:
if ( V_6 -> V_65 && V_6 -> V_65 -> V_162 )
V_6 -> V_65 -> V_162 ( V_6 ) ;
F_28 ( V_6 , 0 ) ;
V_149:
F_59 ( V_13 ) ;
return V_10 ;
}
void F_60 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_10 ( V_6 ) ;
if ( V_6 -> V_65 && V_6 -> V_65 -> V_162 )
V_6 -> V_65 -> V_162 ( V_6 ) ;
F_28 ( V_6 , 0 ) ;
F_39 ( V_6 , 0 ) ;
}
int F_61 ( struct V_5 * V_6 )
{
int V_10 = 0 ;
V_10 = F_62 ( V_6 -> V_13 ) ;
if ( V_10 )
return V_10 ;
F_28 ( V_6 , 0 ) ;
F_39 ( V_6 , 0 ) ;
return V_10 ;
}
int F_63 ( struct V_5 * V_6 )
{
int V_10 ;
F_48 ( & V_6 -> V_13 -> V_14 , V_6 ) ;
V_10 = F_64 ( V_6 -> V_13 ) ;
if ( V_10 )
F_29 ( & V_6 -> V_13 -> V_14 , L_28 , V_10 ) ;
return V_10 ;
}
