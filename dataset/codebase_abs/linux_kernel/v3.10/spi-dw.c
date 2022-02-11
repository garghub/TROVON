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
unsigned long V_67 ;
struct V_48 * V_49 ;
F_23 ( & V_6 -> V_68 , V_67 ) ;
V_49 = V_6 -> V_50 ;
V_6 -> V_50 = NULL ;
V_6 -> V_53 = NULL ;
V_6 -> V_69 = V_6 -> V_61 ;
V_6 -> V_61 = NULL ;
V_6 -> V_70 = 0 ;
F_24 ( V_6 -> V_71 , & V_6 -> V_72 ) ;
F_25 ( & V_6 -> V_68 , V_67 ) ;
V_66 = F_20 ( V_49 -> V_56 . V_73 ,
struct V_51 ,
V_54 ) ;
if ( ! V_66 -> V_74 && V_6 -> V_75 )
V_6 -> V_75 ( V_76 ) ;
V_49 -> V_77 = NULL ;
if ( V_49 -> V_78 )
V_49 -> V_78 ( V_49 -> V_79 ) ;
}
static void F_26 ( struct V_5 * V_6 , const char * V_49 )
{
F_27 ( V_6 , 0 ) ;
F_28 ( & V_6 -> V_80 -> V_81 , L_20 , V_49 ) ;
V_6 -> V_50 -> V_77 = V_82 ;
F_29 ( & V_6 -> V_83 ) ;
}
void F_30 ( struct V_5 * V_6 )
{
V_6 -> V_50 -> V_84 += V_6 -> V_8 ;
V_6 -> V_50 -> V_77 = F_19 ( V_6 ) ;
if ( V_6 -> V_50 -> V_77 == V_58 ) {
V_6 -> V_50 -> V_85 = 0 ;
F_22 ( V_6 ) ;
} else
F_29 ( & V_6 -> V_83 ) ;
}
static T_7 F_31 ( struct V_5 * V_6 )
{
T_6 V_86 = F_12 ( V_6 , V_24 ) ;
if ( V_86 & ( V_87 | V_88 | V_89 ) ) {
F_12 ( V_6 , V_90 ) ;
F_12 ( V_6 , V_91 ) ;
F_12 ( V_6 , V_92 ) ;
F_26 ( V_6 , L_21 ) ;
return V_93 ;
}
F_18 ( V_6 ) ;
if ( V_6 -> V_40 == V_6 -> V_41 ) {
F_32 ( V_6 , V_94 ) ;
F_30 ( V_6 ) ;
return V_93 ;
}
if ( V_86 & V_94 ) {
F_32 ( V_6 , V_94 ) ;
F_16 ( V_6 ) ;
F_33 ( V_6 , V_94 ) ;
}
return V_93 ;
}
static T_7 F_34 ( int V_95 , void * V_96 )
{
struct V_5 * V_6 = V_96 ;
T_6 V_86 = F_12 ( V_6 , V_24 ) & 0x3f ;
if ( ! V_86 )
return V_97 ;
if ( ! V_6 -> V_50 ) {
F_32 ( V_6 , V_94 ) ;
return V_93 ;
}
return V_6 -> V_98 ( V_6 ) ;
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
static void V_83 ( unsigned long V_99 )
{
struct V_5 * V_6 = (struct V_5 * ) V_99 ;
struct V_48 * V_100 = NULL ;
struct V_51 * V_101 = NULL ;
struct V_51 * V_102 = NULL ;
struct V_103 * V_104 = NULL ;
struct V_105 * V_106 = NULL ;
V_45 V_107 = 0 ;
V_45 V_108 = 0 ;
V_45 V_74 = 0 ;
T_6 V_109 = 0 ;
T_6 V_110 = 0 ;
T_5 V_111 = 0 ;
T_5 V_112 = 0 ;
V_100 = V_6 -> V_50 ;
V_101 = V_6 -> V_53 ;
V_106 = V_6 -> V_61 ;
V_104 = V_100 -> V_104 ;
if ( F_37 ( ! V_106 -> V_110 ) )
V_106 -> V_110 = V_6 -> V_113 / V_106 -> V_114 ;
if ( V_100 -> V_77 == V_82 ) {
V_100 -> V_85 = - V_115 ;
goto V_116;
}
if ( V_100 -> V_77 == V_58 ) {
V_100 -> V_85 = 0 ;
goto V_116;
}
if ( V_100 -> V_77 == V_57 ) {
V_102 = F_20 ( V_101 -> V_54 . V_73 ,
struct V_51 ,
V_54 ) ;
if ( V_102 -> V_117 )
F_38 ( V_102 -> V_117 ) ;
}
V_6 -> V_38 = V_106 -> V_38 ;
V_6 -> V_118 = V_106 -> V_118 ;
V_6 -> V_75 = V_106 -> V_75 ;
V_6 -> V_65 = V_101 -> V_65 ;
V_6 -> V_64 = V_101 -> V_64 ;
V_6 -> V_37 = ( void * ) V_101 -> V_119 ;
V_6 -> V_36 = V_6 -> V_37 + V_101 -> V_8 ;
V_6 -> V_41 = V_101 -> V_120 ;
V_6 -> V_40 = V_6 -> V_41 + V_101 -> V_8 ;
V_6 -> V_74 = V_101 -> V_74 ;
V_6 -> V_8 = V_6 -> V_53 -> V_8 ;
if ( V_106 != V_6 -> V_69 )
V_74 = 1 ;
V_112 = V_106 -> V_112 ;
if ( V_101 -> V_114 ) {
V_111 = V_106 -> V_114 ;
if ( V_101 -> V_114 != V_111 ) {
V_111 = V_101 -> V_114 ;
if ( V_111 > V_6 -> V_113 ) {
F_39 ( V_121 L_22
L_23 , V_111 ) ;
V_100 -> V_85 = - V_115 ;
goto V_116;
}
V_110 = V_6 -> V_113 / V_111 ;
V_110 = ( V_110 + 1 ) & 0xfffe ;
V_106 -> V_114 = V_111 ;
V_106 -> V_110 = V_110 ;
}
}
if ( V_101 -> V_122 ) {
V_107 = V_101 -> V_122 ;
switch ( V_107 ) {
case 8 :
case 16 :
V_6 -> V_38 = V_6 -> V_118 = V_107 >> 3 ;
break;
default:
F_39 ( V_121 L_24
L_25 , V_107 ) ;
V_100 -> V_85 = - V_115 ;
goto V_116;
}
V_112 = ( V_107 - 1 )
| ( V_106 -> type << V_123 )
| ( V_104 -> V_124 << V_125 )
| ( V_106 -> V_126 << V_127 ) ;
}
V_100 -> V_77 = V_57 ;
if ( V_6 -> V_75 ) {
if ( V_6 -> V_41 && V_6 -> V_37 )
V_106 -> V_126 = V_128 ;
else if ( V_6 -> V_41 )
V_106 -> V_126 = V_129 ;
else
V_106 -> V_126 = V_130 ;
V_112 &= ~ V_131 ;
V_112 |= ( V_106 -> V_126 << V_127 ) ;
}
V_6 -> V_70 = F_21 ( V_6 ) ;
if ( ! V_6 -> V_70 && ! V_106 -> V_132 ) {
int V_133 = V_6 -> V_8 / V_6 -> V_38 ;
V_109 = V_6 -> V_39 / 2 ;
V_109 = ( V_133 > V_109 ) ? V_109 : V_133 ;
V_108 |= V_94 | V_87 | V_89 | V_88 ;
V_6 -> V_98 = F_31 ;
}
if ( F_12 ( V_6 , V_13 ) != V_112 || V_74 || V_110 || V_108 ) {
F_27 ( V_6 , 0 ) ;
if ( F_12 ( V_6 , V_13 ) != V_112 )
F_17 ( V_6 , V_13 , V_112 ) ;
F_40 ( V_6 , V_110 ? V_110 : V_106 -> V_110 ) ;
F_41 ( V_6 , V_104 -> V_134 ) ;
F_32 ( V_6 , 0xff ) ;
if ( V_108 )
F_33 ( V_6 , V_108 ) ;
if ( V_109 )
F_17 ( V_6 , V_18 , V_109 ) ;
F_27 ( V_6 , 1 ) ;
if ( V_74 )
V_6 -> V_69 = V_106 ;
}
if ( V_6 -> V_70 )
V_6 -> V_63 -> V_135 ( V_6 , V_74 ) ;
if ( V_106 -> V_132 )
F_35 ( V_6 ) ;
return;
V_116:
F_22 ( V_6 ) ;
return;
}
static void V_72 ( struct V_136 * V_137 )
{
struct V_5 * V_6 =
F_42 ( V_137 , struct V_5 , V_72 ) ;
unsigned long V_67 ;
F_23 ( & V_6 -> V_68 , V_67 ) ;
if ( F_43 ( & V_6 -> V_138 ) || V_6 -> V_139 == V_140 ) {
V_6 -> V_141 = 0 ;
F_25 ( & V_6 -> V_68 , V_67 ) ;
return;
}
if ( V_6 -> V_50 ) {
F_25 ( & V_6 -> V_68 , V_67 ) ;
return;
}
V_6 -> V_50 = F_20 ( V_6 -> V_138 . V_55 , struct V_48 , V_138 ) ;
F_44 ( & V_6 -> V_50 -> V_138 ) ;
V_6 -> V_50 -> V_77 = V_142 ;
V_6 -> V_53 = F_20 ( V_6 -> V_50 -> V_56 . V_55 ,
struct V_51 ,
V_54 ) ;
V_6 -> V_61 = F_45 ( V_6 -> V_50 -> V_104 ) ;
F_29 ( & V_6 -> V_83 ) ;
V_6 -> V_141 = 1 ;
F_25 ( & V_6 -> V_68 , V_67 ) ;
}
static int F_46 ( struct V_103 * V_104 , struct V_48 * V_49 )
{
struct V_5 * V_6 = F_47 ( V_104 -> V_80 ) ;
unsigned long V_67 ;
F_23 ( & V_6 -> V_68 , V_67 ) ;
if ( V_6 -> V_139 == V_140 ) {
F_25 ( & V_6 -> V_68 , V_67 ) ;
return - V_143 ;
}
V_49 -> V_84 = 0 ;
V_49 -> V_85 = - V_144 ;
V_49 -> V_77 = V_142 ;
F_48 ( & V_49 -> V_138 , & V_6 -> V_138 ) ;
if ( V_6 -> V_139 == V_145 && ! V_6 -> V_141 ) {
if ( V_6 -> V_53 || V_6 -> V_50 )
F_24 ( V_6 -> V_71 ,
& V_6 -> V_72 ) ;
else {
F_25 ( & V_6 -> V_68 , V_67 ) ;
V_72 ( & V_6 -> V_72 ) ;
return 0 ;
}
}
F_25 ( & V_6 -> V_68 , V_67 ) ;
return 0 ;
}
static int F_49 ( struct V_103 * V_104 )
{
struct V_146 * V_147 = NULL ;
struct V_105 * V_106 ;
if ( V_104 -> V_122 != 8 && V_104 -> V_122 != 16 )
return - V_148 ;
V_106 = F_45 ( V_104 ) ;
if ( ! V_106 ) {
V_106 = F_2 ( sizeof( struct V_105 ) , V_12 ) ;
if ( ! V_106 )
return - V_29 ;
}
V_147 = V_104 -> V_149 ;
if ( V_147 ) {
if ( V_147 -> V_75 )
V_106 -> V_75 = V_147 -> V_75 ;
V_106 -> V_132 = V_147 -> V_132 ;
V_106 -> type = V_147 -> type ;
V_106 -> V_150 = 0 ;
V_106 -> V_151 = 0 ;
V_106 -> V_62 = V_147 -> V_62 ;
}
if ( V_104 -> V_122 <= 8 ) {
V_106 -> V_38 = 1 ;
V_106 -> V_118 = 1 ;
} else if ( V_104 -> V_122 <= 16 ) {
V_106 -> V_38 = 2 ;
V_106 -> V_118 = 2 ;
} else {
F_28 ( & V_104 -> V_81 , L_26 ) ;
return - V_148 ;
}
V_106 -> V_122 = V_104 -> V_122 ;
if ( ! V_104 -> V_152 ) {
F_28 ( & V_104 -> V_81 , L_27 ) ;
return - V_148 ;
}
V_106 -> V_114 = V_104 -> V_152 ;
V_106 -> V_126 = 0 ;
V_106 -> V_112 = ( V_106 -> V_122 - 1 )
| ( V_106 -> type << V_123 )
| ( V_104 -> V_124 << V_125 )
| ( V_106 -> V_126 << V_127 ) ;
F_50 ( V_104 , V_106 ) ;
return 0 ;
}
static void F_51 ( struct V_103 * V_104 )
{
struct V_105 * V_106 = F_45 ( V_104 ) ;
F_5 ( V_106 ) ;
}
static int F_52 ( struct V_5 * V_6 )
{
F_53 ( & V_6 -> V_138 ) ;
F_54 ( & V_6 -> V_68 ) ;
V_6 -> V_139 = V_140 ;
V_6 -> V_141 = 0 ;
F_55 ( & V_6 -> V_83 ,
V_83 , ( unsigned long ) V_6 ) ;
F_56 ( & V_6 -> V_72 , V_72 ) ;
V_6 -> V_71 = F_57 (
F_58 ( V_6 -> V_80 -> V_81 . V_153 ) ) ;
if ( V_6 -> V_71 == NULL )
return - V_154 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 )
{
unsigned long V_67 ;
F_23 ( & V_6 -> V_68 , V_67 ) ;
if ( V_6 -> V_139 == V_145 || V_6 -> V_141 ) {
F_25 ( & V_6 -> V_68 , V_67 ) ;
return - V_154 ;
}
V_6 -> V_139 = V_145 ;
V_6 -> V_50 = NULL ;
V_6 -> V_53 = NULL ;
V_6 -> V_61 = NULL ;
V_6 -> V_69 = NULL ;
F_25 ( & V_6 -> V_68 , V_67 ) ;
F_24 ( V_6 -> V_71 , & V_6 -> V_72 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
unsigned long V_67 ;
unsigned V_155 = 50 ;
int V_85 = 0 ;
F_23 ( & V_6 -> V_68 , V_67 ) ;
V_6 -> V_139 = V_140 ;
while ( ( ! F_43 ( & V_6 -> V_138 ) || V_6 -> V_141 ) && V_155 -- ) {
F_25 ( & V_6 -> V_68 , V_67 ) ;
F_61 ( 10 ) ;
F_23 ( & V_6 -> V_68 , V_67 ) ;
}
if ( ! F_43 ( & V_6 -> V_138 ) || V_6 -> V_141 )
V_85 = - V_154 ;
F_25 ( & V_6 -> V_68 , V_67 ) ;
return V_85 ;
}
static int F_62 ( struct V_5 * V_6 )
{
int V_85 ;
V_85 = F_60 ( V_6 ) ;
if ( V_85 != 0 )
return V_85 ;
F_63 ( V_6 -> V_71 ) ;
return 0 ;
}
static void F_64 ( struct V_5 * V_6 )
{
F_27 ( V_6 , 0 ) ;
F_32 ( V_6 , 0xff ) ;
F_27 ( V_6 , 1 ) ;
if ( ! V_6 -> V_39 ) {
T_5 V_156 ;
for ( V_156 = 2 ; V_156 <= 257 ; V_156 ++ ) {
F_17 ( V_6 , V_18 , V_156 ) ;
if ( V_156 != F_12 ( V_6 , V_18 ) )
break;
}
V_6 -> V_39 = ( V_156 == 257 ) ? 0 : V_156 ;
F_17 ( V_6 , V_18 , 0 ) ;
}
}
int F_65 ( struct V_5 * V_6 )
{
struct V_157 * V_80 ;
int V_9 ;
F_66 ( V_6 == NULL ) ;
V_80 = F_67 ( V_6 -> V_158 , 0 ) ;
if ( ! V_80 ) {
V_9 = - V_29 ;
goto exit;
}
V_6 -> V_80 = V_80 ;
V_6 -> type = V_159 ;
V_6 -> V_69 = NULL ;
V_6 -> V_60 = 0 ;
V_6 -> V_160 = ( V_161 ) ( V_6 -> V_162 + 0x60 ) ;
snprintf ( V_6 -> V_163 , sizeof( V_6 -> V_163 ) , L_28 ,
V_6 -> V_164 ) ;
V_9 = F_68 ( V_6 -> V_95 , F_34 , V_165 ,
V_6 -> V_163 , V_6 ) ;
if ( V_9 < 0 ) {
F_28 ( & V_80 -> V_81 , L_29 ) ;
goto V_166;
}
V_80 -> V_167 = V_168 | V_169 ;
V_80 -> V_164 = V_6 -> V_164 ;
V_80 -> V_170 = V_6 -> V_171 ;
V_80 -> V_172 = F_51 ;
V_80 -> V_173 = F_49 ;
V_80 -> V_101 = F_46 ;
F_64 ( V_6 ) ;
if ( V_6 -> V_63 && V_6 -> V_63 -> V_174 ) {
V_9 = V_6 -> V_63 -> V_174 ( V_6 ) ;
if ( V_9 ) {
F_69 ( & V_80 -> V_81 , L_30 ) ;
V_6 -> V_60 = 0 ;
}
}
V_9 = F_52 ( V_6 ) ;
if ( V_9 ) {
F_28 ( & V_80 -> V_81 , L_31 ) ;
goto V_175;
}
V_9 = F_59 ( V_6 ) ;
if ( V_9 ) {
F_28 ( & V_80 -> V_81 , L_32 ) ;
goto V_175;
}
F_70 ( V_80 , V_6 ) ;
V_9 = F_71 ( V_80 ) ;
if ( V_9 ) {
F_28 ( & V_80 -> V_81 , L_33 ) ;
goto V_176;
}
F_6 ( V_6 ) ;
return 0 ;
V_176:
F_62 ( V_6 ) ;
if ( V_6 -> V_63 && V_6 -> V_63 -> V_177 )
V_6 -> V_63 -> V_177 ( V_6 ) ;
V_175:
F_27 ( V_6 , 0 ) ;
F_72 ( V_6 -> V_95 , V_6 ) ;
V_166:
F_73 ( V_80 ) ;
exit:
return V_9 ;
}
void F_74 ( struct V_5 * V_6 )
{
int V_85 = 0 ;
if ( ! V_6 )
return;
F_9 ( V_6 ) ;
V_85 = F_62 ( V_6 ) ;
if ( V_85 != 0 )
F_28 ( & V_6 -> V_80 -> V_81 , L_34
L_35 ) ;
if ( V_6 -> V_63 && V_6 -> V_63 -> V_177 )
V_6 -> V_63 -> V_177 ( V_6 ) ;
F_27 ( V_6 , 0 ) ;
F_40 ( V_6 , 0 ) ;
F_72 ( V_6 -> V_95 , V_6 ) ;
F_75 ( V_6 -> V_80 ) ;
}
int F_76 ( struct V_5 * V_6 )
{
int V_9 = 0 ;
V_9 = F_60 ( V_6 ) ;
if ( V_9 )
return V_9 ;
F_27 ( V_6 , 0 ) ;
F_40 ( V_6 , 0 ) ;
return V_9 ;
}
int F_77 ( struct V_5 * V_6 )
{
int V_9 ;
F_64 ( V_6 ) ;
V_9 = F_59 ( V_6 ) ;
if ( V_9 )
F_28 ( & V_6 -> V_80 -> V_81 , L_36 , V_9 ) ;
return V_9 ;
}
