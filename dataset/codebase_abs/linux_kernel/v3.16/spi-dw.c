static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 ;
char * V_7 ;
T_5 V_8 = 0 ;
T_1 V_9 ;
V_6 = V_1 -> V_10 ;
V_7 = F_2 ( V_11 , V_12 ) ;
if ( ! V_7 )
return 0 ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_1 ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_2 ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_3 , F_3 ( V_6 , V_13 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_4 , F_3 ( V_6 , V_14 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_5 , F_3 ( V_6 , V_15 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_6 , F_3 ( V_6 , V_16 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_7 , F_3 ( V_6 , V_17 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_8 , F_3 ( V_6 , V_18 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_9 , F_3 ( V_6 , V_19 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_10 , F_3 ( V_6 , V_20 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_11 , F_3 ( V_6 , V_21 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_12 , F_3 ( V_6 , V_22 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_13 , F_3 ( V_6 , V_23 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_14 , F_3 ( V_6 , V_24 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_15 , F_3 ( V_6 , V_25 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_16 , F_3 ( V_6 , V_26 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_17 , F_3 ( V_6 , V_27 ) ) ;
V_8 += snprintf ( V_7 + V_8 , V_11 - V_8 ,
L_2 ) ;
V_9 = F_4 ( V_2 , V_3 , V_4 , V_7 , V_8 ) ;
F_5 ( V_7 ) ;
return V_9 ;
}
static int F_6 ( struct V_5 * V_6 )
{
V_6 -> V_28 = F_7 ( L_18 , NULL ) ;
if ( ! V_6 -> V_28 )
return - V_29 ;
F_8 ( L_19 , V_30 | V_31 ,
V_6 -> V_28 , ( void * ) V_6 , & V_32 ) ;
return 0 ;
}
static void F_9 ( struct V_5 * V_6 )
{
if ( V_6 -> V_28 )
F_10 ( V_6 -> V_28 ) ;
}
static inline int F_6 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline void F_9 ( struct V_5 * V_6 )
{
}
static inline T_5 F_11 ( struct V_5 * V_6 )
{
T_5 V_33 , V_34 , V_35 ;
V_33 = ( V_6 -> V_36 - V_6 -> V_37 ) / V_6 -> V_38 ;
V_34 = V_6 -> V_39 - F_12 ( V_6 , V_20 ) ;
V_35 = ( ( V_6 -> V_40 - V_6 -> V_41 ) - ( V_6 -> V_36 - V_6 -> V_37 ) )
/ V_6 -> V_38 ;
return F_13 ( V_33 , V_34 , ( T_5 ) ( V_6 -> V_39 - V_35 ) ) ;
}
static inline T_5 F_14 ( struct V_5 * V_6 )
{
T_5 V_42 = ( V_6 -> V_40 - V_6 -> V_41 ) / V_6 -> V_38 ;
return F_15 ( V_42 , ( T_5 ) F_12 ( V_6 , V_21 ) ) ;
}
static void F_16 ( struct V_5 * V_6 )
{
T_5 V_43 = F_11 ( V_6 ) ;
T_6 V_44 = 0 ;
while ( V_43 -- ) {
if ( V_6 -> V_36 - V_6 -> V_8 ) {
if ( V_6 -> V_38 == 1 )
V_44 = * ( V_45 * ) ( V_6 -> V_37 ) ;
else
V_44 = * ( T_6 * ) ( V_6 -> V_37 ) ;
}
F_17 ( V_6 , V_46 , V_44 ) ;
V_6 -> V_37 += V_6 -> V_38 ;
}
}
static void F_18 ( struct V_5 * V_6 )
{
T_5 V_43 = F_14 ( V_6 ) ;
T_6 V_47 ;
while ( V_43 -- ) {
V_47 = F_12 ( V_6 , V_46 ) ;
if ( V_6 -> V_40 - V_6 -> V_8 ) {
if ( V_6 -> V_38 == 1 )
* ( V_45 * ) ( V_6 -> V_41 ) = V_47 ;
else
* ( T_6 * ) ( V_6 -> V_41 ) = V_47 ;
}
V_6 -> V_41 += V_6 -> V_38 ;
}
}
static void * F_19 ( struct V_5 * V_6 )
{
struct V_48 * V_49 = V_6 -> V_50 ;
struct V_51 * V_52 = V_6 -> V_53 ;
if ( V_52 -> V_54 . V_55 != & V_49 -> V_56 ) {
V_6 -> V_53 =
F_20 ( V_52 -> V_54 . V_55 ,
struct V_51 ,
V_54 ) ;
return V_57 ;
} else
return V_58 ;
}
static int F_21 ( struct V_5 * V_6 )
{
if ( ! V_6 -> V_50 -> V_59
|| ! V_6 -> V_60
|| ! V_6 -> V_61 -> V_62
|| ! V_6 -> V_63 )
return 0 ;
if ( V_6 -> V_53 -> V_64 )
V_6 -> V_64 = V_6 -> V_53 -> V_64 ;
if ( V_6 -> V_53 -> V_65 )
V_6 -> V_65 = V_6 -> V_53 -> V_65 ;
return 1 ;
}
static void F_22 ( struct V_5 * V_6 )
{
struct V_51 * V_66 ;
struct V_48 * V_49 ;
V_49 = V_6 -> V_50 ;
V_6 -> V_50 = NULL ;
V_6 -> V_53 = NULL ;
V_6 -> V_67 = V_6 -> V_61 ;
V_6 -> V_61 = NULL ;
V_6 -> V_68 = 0 ;
V_66 = F_23 ( & V_49 -> V_56 , struct V_51 ,
V_54 ) ;
if ( ! V_66 -> V_69 )
F_24 ( V_6 , V_6 -> V_50 -> V_70 , 0 ) ;
F_25 ( V_6 -> V_71 ) ;
}
static void F_26 ( struct V_5 * V_6 , const char * V_49 )
{
F_27 ( V_6 , 0 ) ;
F_28 ( & V_6 -> V_71 -> V_72 , L_20 , V_49 ) ;
V_6 -> V_50 -> V_73 = V_74 ;
F_29 ( & V_6 -> V_75 ) ;
}
void F_30 ( struct V_5 * V_6 )
{
V_6 -> V_50 -> V_76 += V_6 -> V_8 ;
V_6 -> V_50 -> V_73 = F_19 ( V_6 ) ;
if ( V_6 -> V_50 -> V_73 == V_58 ) {
V_6 -> V_50 -> V_77 = 0 ;
F_22 ( V_6 ) ;
} else
F_29 ( & V_6 -> V_75 ) ;
}
static T_7 F_31 ( struct V_5 * V_6 )
{
T_6 V_78 = F_12 ( V_6 , V_24 ) ;
if ( V_78 & ( V_79 | V_80 | V_81 ) ) {
F_12 ( V_6 , V_82 ) ;
F_12 ( V_6 , V_83 ) ;
F_12 ( V_6 , V_84 ) ;
F_26 ( V_6 , L_21 ) ;
return V_85 ;
}
F_18 ( V_6 ) ;
if ( V_6 -> V_40 == V_6 -> V_41 ) {
F_32 ( V_6 , V_86 ) ;
F_30 ( V_6 ) ;
return V_85 ;
}
if ( V_78 & V_86 ) {
F_32 ( V_6 , V_86 ) ;
F_16 ( V_6 ) ;
F_33 ( V_6 , V_86 ) ;
}
return V_85 ;
}
static T_7 F_34 ( int V_87 , void * V_88 )
{
struct V_5 * V_6 = V_88 ;
T_6 V_78 = F_12 ( V_6 , V_24 ) & 0x3f ;
if ( ! V_78 )
return V_89 ;
if ( ! V_6 -> V_50 ) {
F_32 ( V_6 , V_86 ) ;
return V_85 ;
}
return V_6 -> V_90 ( V_6 ) ;
}
static void F_35 ( struct V_5 * V_6 )
{
do {
F_16 ( V_6 ) ;
F_18 ( V_6 ) ;
F_36 () ;
} while ( V_6 -> V_40 > V_6 -> V_41 );
F_30 ( V_6 ) ;
}
static void V_75 ( unsigned long V_91 )
{
struct V_5 * V_6 = (struct V_5 * ) V_91 ;
struct V_48 * V_92 = NULL ;
struct V_51 * V_93 = NULL ;
struct V_51 * V_94 = NULL ;
struct V_95 * V_70 = NULL ;
struct V_96 * V_97 = NULL ;
V_45 V_98 = 0 ;
V_45 V_99 = 0 ;
V_45 V_69 = 0 ;
T_6 V_100 = 0 ;
T_6 V_101 = 0 ;
T_5 V_102 = 0 ;
T_5 V_103 = 0 ;
V_92 = V_6 -> V_50 ;
V_93 = V_6 -> V_53 ;
V_97 = V_6 -> V_61 ;
V_70 = V_92 -> V_70 ;
if ( F_37 ( ! V_97 -> V_101 ) )
V_97 -> V_101 = V_6 -> V_104 / V_97 -> V_105 ;
if ( V_92 -> V_73 == V_74 ) {
V_92 -> V_77 = - V_106 ;
goto V_107;
}
if ( V_92 -> V_73 == V_58 ) {
V_92 -> V_77 = 0 ;
goto V_107;
}
if ( V_92 -> V_73 == V_57 ) {
V_94 = F_20 ( V_93 -> V_54 . V_108 ,
struct V_51 ,
V_54 ) ;
if ( V_94 -> V_109 )
F_38 ( V_94 -> V_109 ) ;
}
V_6 -> V_38 = V_97 -> V_38 ;
V_6 -> V_110 = V_97 -> V_110 ;
V_6 -> V_111 = V_97 -> V_111 ;
V_6 -> V_65 = V_93 -> V_65 ;
V_6 -> V_64 = V_93 -> V_64 ;
V_6 -> V_37 = ( void * ) V_93 -> V_112 ;
V_6 -> V_36 = V_6 -> V_37 + V_93 -> V_8 ;
V_6 -> V_41 = V_93 -> V_113 ;
V_6 -> V_40 = V_6 -> V_41 + V_93 -> V_8 ;
V_6 -> V_8 = V_6 -> V_53 -> V_8 ;
if ( V_97 != V_6 -> V_67 )
V_69 = 1 ;
V_103 = V_97 -> V_103 ;
if ( V_93 -> V_105 ) {
V_102 = V_97 -> V_105 ;
if ( V_93 -> V_105 != V_102 ) {
V_102 = V_93 -> V_105 ;
V_101 = V_6 -> V_104 / V_102 ;
V_101 = ( V_101 + 1 ) & 0xfffe ;
V_97 -> V_105 = V_102 ;
V_97 -> V_101 = V_101 ;
}
}
if ( V_93 -> V_114 ) {
V_98 = V_93 -> V_114 ;
V_6 -> V_38 = V_6 -> V_110 = V_98 >> 3 ;
V_103 = ( V_98 - 1 )
| ( V_97 -> type << V_115 )
| ( V_70 -> V_116 << V_117 )
| ( V_97 -> V_118 << V_119 ) ;
}
V_92 -> V_73 = V_57 ;
if ( V_6 -> V_111 ) {
if ( V_6 -> V_41 && V_6 -> V_37 )
V_97 -> V_118 = V_120 ;
else if ( V_6 -> V_41 )
V_97 -> V_118 = V_121 ;
else
V_97 -> V_118 = V_122 ;
V_103 &= ~ V_123 ;
V_103 |= ( V_97 -> V_118 << V_119 ) ;
}
V_6 -> V_68 = F_21 ( V_6 ) ;
if ( ! V_6 -> V_68 && ! V_97 -> V_124 ) {
int V_125 = V_6 -> V_8 / V_6 -> V_38 ;
V_100 = V_6 -> V_39 / 2 ;
V_100 = ( V_125 > V_100 ) ? V_100 : V_125 ;
V_99 |= V_86 | V_79 | V_81 | V_80 ;
V_6 -> V_90 = F_31 ;
}
if ( F_12 ( V_6 , V_13 ) != V_103 || V_69 || V_101 || V_99 ) {
F_27 ( V_6 , 0 ) ;
if ( F_12 ( V_6 , V_13 ) != V_103 )
F_17 ( V_6 , V_13 , V_103 ) ;
F_39 ( V_6 , V_101 ? V_101 : V_97 -> V_101 ) ;
F_24 ( V_6 , V_70 , 1 ) ;
F_32 ( V_6 , 0xff ) ;
if ( V_99 )
F_33 ( V_6 , V_99 ) ;
if ( V_100 )
F_17 ( V_6 , V_18 , V_100 ) ;
F_27 ( V_6 , 1 ) ;
if ( V_69 )
V_6 -> V_67 = V_97 ;
}
if ( V_6 -> V_68 )
V_6 -> V_63 -> V_126 ( V_6 , V_69 ) ;
if ( V_97 -> V_124 )
F_35 ( V_6 ) ;
return;
V_107:
F_22 ( V_6 ) ;
return;
}
static int F_40 ( struct V_127 * V_71 ,
struct V_48 * V_49 )
{
struct V_5 * V_6 = F_41 ( V_71 ) ;
V_6 -> V_50 = V_49 ;
V_6 -> V_50 -> V_73 = V_128 ;
V_6 -> V_53 = F_20 ( V_6 -> V_50 -> V_56 . V_55 ,
struct V_51 ,
V_54 ) ;
V_6 -> V_61 = F_42 ( V_6 -> V_50 -> V_70 ) ;
F_29 ( & V_6 -> V_75 ) ;
return 0 ;
}
static int F_43 ( struct V_95 * V_70 )
{
struct V_129 * V_130 = NULL ;
struct V_96 * V_97 ;
int V_9 ;
V_97 = F_42 ( V_70 ) ;
if ( ! V_97 ) {
V_97 = F_44 ( & V_70 -> V_72 , sizeof( struct V_96 ) ,
V_12 ) ;
if ( ! V_97 )
return - V_29 ;
F_45 ( V_70 , V_97 ) ;
}
V_130 = V_70 -> V_131 ;
if ( V_130 ) {
if ( V_130 -> V_111 )
V_97 -> V_111 = V_130 -> V_111 ;
V_97 -> V_124 = V_130 -> V_124 ;
V_97 -> type = V_130 -> type ;
V_97 -> V_132 = 0 ;
V_97 -> V_133 = 0 ;
V_97 -> V_62 = V_130 -> V_62 ;
}
if ( V_70 -> V_114 == 8 ) {
V_97 -> V_38 = 1 ;
V_97 -> V_110 = 1 ;
} else if ( V_70 -> V_114 == 16 ) {
V_97 -> V_38 = 2 ;
V_97 -> V_110 = 2 ;
}
V_97 -> V_114 = V_70 -> V_114 ;
if ( ! V_70 -> V_134 ) {
F_28 ( & V_70 -> V_72 , L_22 ) ;
return - V_135 ;
}
V_97 -> V_105 = V_70 -> V_134 ;
V_97 -> V_118 = 0 ;
V_97 -> V_103 = ( V_97 -> V_114 - 1 )
| ( V_97 -> type << V_115 )
| ( V_70 -> V_116 << V_117 )
| ( V_97 -> V_118 << V_119 ) ;
if ( F_46 ( V_70 -> V_136 ) ) {
V_9 = F_47 ( V_70 -> V_136 ,
! ( V_70 -> V_116 & V_137 ) ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static void F_48 ( struct V_5 * V_6 )
{
F_27 ( V_6 , 0 ) ;
F_32 ( V_6 , 0xff ) ;
F_27 ( V_6 , 1 ) ;
if ( ! V_6 -> V_39 ) {
T_5 V_138 ;
for ( V_138 = 2 ; V_138 <= 257 ; V_138 ++ ) {
F_17 ( V_6 , V_18 , V_138 ) ;
if ( V_138 != F_12 ( V_6 , V_18 ) )
break;
}
V_6 -> V_39 = ( V_138 == 257 ) ? 0 : V_138 ;
F_17 ( V_6 , V_18 , 0 ) ;
}
}
int F_49 ( struct V_139 * V_72 , struct V_5 * V_6 )
{
struct V_127 * V_71 ;
int V_9 ;
F_50 ( V_6 == NULL ) ;
V_71 = F_51 ( V_72 , 0 ) ;
if ( ! V_71 )
return - V_29 ;
V_6 -> V_71 = V_71 ;
V_6 -> type = V_140 ;
V_6 -> V_67 = NULL ;
V_6 -> V_60 = 0 ;
V_6 -> V_141 = ( V_142 ) ( V_6 -> V_143 + 0x60 ) ;
snprintf ( V_6 -> V_144 , sizeof( V_6 -> V_144 ) , L_23 ,
V_6 -> V_145 ) ;
V_9 = F_52 ( V_72 , V_6 -> V_87 , F_34 , V_146 ,
V_6 -> V_144 , V_6 ) ;
if ( V_9 < 0 ) {
F_28 ( & V_71 -> V_72 , L_24 ) ;
goto V_147;
}
V_71 -> V_148 = V_149 | V_150 ;
V_71 -> V_151 = F_53 ( 8 ) | F_53 ( 16 ) ;
V_71 -> V_145 = V_6 -> V_145 ;
V_71 -> V_152 = V_6 -> V_153 ;
V_71 -> V_154 = F_43 ;
V_71 -> V_155 = F_40 ;
V_71 -> V_134 = V_6 -> V_104 ;
F_48 ( V_6 ) ;
if ( V_6 -> V_63 && V_6 -> V_63 -> V_156 ) {
V_9 = V_6 -> V_63 -> V_156 ( V_6 ) ;
if ( V_9 ) {
F_54 ( & V_71 -> V_72 , L_25 ) ;
V_6 -> V_60 = 0 ;
}
}
F_55 ( & V_6 -> V_75 , V_75 , ( unsigned long ) V_6 ) ;
F_56 ( V_71 , V_6 ) ;
V_9 = F_57 ( V_72 , V_71 ) ;
if ( V_9 ) {
F_28 ( & V_71 -> V_72 , L_26 ) ;
goto V_157;
}
F_6 ( V_6 ) ;
return 0 ;
V_157:
if ( V_6 -> V_63 && V_6 -> V_63 -> V_158 )
V_6 -> V_63 -> V_158 ( V_6 ) ;
F_27 ( V_6 , 0 ) ;
V_147:
F_58 ( V_71 ) ;
return V_9 ;
}
void F_59 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return;
F_9 ( V_6 ) ;
if ( V_6 -> V_63 && V_6 -> V_63 -> V_158 )
V_6 -> V_63 -> V_158 ( V_6 ) ;
F_27 ( V_6 , 0 ) ;
F_39 ( V_6 , 0 ) ;
}
int F_60 ( struct V_5 * V_6 )
{
int V_9 = 0 ;
V_9 = F_61 ( V_6 -> V_71 ) ;
if ( V_9 )
return V_9 ;
F_27 ( V_6 , 0 ) ;
F_39 ( V_6 , 0 ) ;
return V_9 ;
}
int F_62 ( struct V_5 * V_6 )
{
int V_9 ;
F_48 ( V_6 ) ;
V_9 = F_63 ( V_6 -> V_71 ) ;
if ( V_9 )
F_28 ( & V_6 -> V_71 -> V_72 , L_27 , V_9 ) ;
return V_9 ;
}
