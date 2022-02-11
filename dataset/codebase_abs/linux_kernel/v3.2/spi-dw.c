static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
V_2 -> V_3 = V_1 -> V_4 ;
return 0 ;
}
static T_1 F_2 ( struct V_2 * V_2 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_8 * V_9 ;
char * V_10 ;
T_5 V_11 = 0 ;
T_1 V_12 ;
V_9 = V_2 -> V_3 ;
V_10 = F_3 ( V_13 , V_14 ) ;
if ( ! V_10 )
return 0 ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_1 ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_2 ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_3 , F_4 ( V_9 , V_15 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_4 , F_4 ( V_9 , V_16 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_5 , F_4 ( V_9 , V_17 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_6 , F_4 ( V_9 , V_18 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_7 , F_4 ( V_9 , V_19 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_8 , F_4 ( V_9 , V_20 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_9 , F_4 ( V_9 , V_21 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_10 , F_4 ( V_9 , V_22 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_11 , F_4 ( V_9 , V_23 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_12 , F_4 ( V_9 , V_24 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_13 , F_4 ( V_9 , V_25 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_14 , F_4 ( V_9 , V_26 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_15 , F_4 ( V_9 , V_27 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_16 , F_4 ( V_9 , V_28 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_17 , F_4 ( V_9 , V_29 ) ) ;
V_11 += snprintf ( V_10 + V_11 , V_13 - V_11 ,
L_2 ) ;
V_12 = F_5 ( V_5 , V_6 , V_7 , V_10 , V_11 ) ;
F_6 ( V_10 ) ;
return V_12 ;
}
static int F_7 ( struct V_8 * V_9 )
{
V_9 -> V_30 = F_8 ( L_18 , NULL ) ;
if ( ! V_9 -> V_30 )
return - V_31 ;
F_9 ( L_19 , V_32 | V_33 ,
V_9 -> V_30 , ( void * ) V_9 , & V_34 ) ;
return 0 ;
}
static void F_10 ( struct V_8 * V_9 )
{
if ( V_9 -> V_30 )
F_11 ( V_9 -> V_30 ) ;
}
static inline int F_7 ( struct V_8 * V_9 )
{
return 0 ;
}
static inline void F_10 ( struct V_8 * V_9 )
{
}
static inline T_5 F_12 ( struct V_8 * V_9 )
{
T_5 V_35 , V_36 , V_37 ;
V_35 = ( V_9 -> V_38 - V_9 -> V_39 ) / V_9 -> V_40 ;
V_36 = V_9 -> V_41 - F_13 ( V_9 , V_22 ) ;
V_37 = ( ( V_9 -> V_42 - V_9 -> V_43 ) - ( V_9 -> V_38 - V_9 -> V_39 ) )
/ V_9 -> V_40 ;
return F_14 ( V_35 , V_36 , ( T_5 ) ( V_9 -> V_41 - V_37 ) ) ;
}
static inline T_5 F_15 ( struct V_8 * V_9 )
{
T_5 V_44 = ( V_9 -> V_42 - V_9 -> V_43 ) / V_9 -> V_40 ;
return F_16 ( V_44 , ( T_5 ) F_13 ( V_9 , V_23 ) ) ;
}
static void F_17 ( struct V_8 * V_9 )
{
T_5 V_45 = F_12 ( V_9 ) ;
T_6 V_46 = 0 ;
while ( V_45 -- ) {
if ( V_9 -> V_38 - V_9 -> V_11 ) {
if ( V_9 -> V_40 == 1 )
V_46 = * ( V_47 * ) ( V_9 -> V_39 ) ;
else
V_46 = * ( T_6 * ) ( V_9 -> V_39 ) ;
}
F_18 ( V_9 , V_48 , V_46 ) ;
V_9 -> V_39 += V_9 -> V_40 ;
}
}
static void F_19 ( struct V_8 * V_9 )
{
T_5 V_45 = F_15 ( V_9 ) ;
T_6 V_49 ;
while ( V_45 -- ) {
V_49 = F_13 ( V_9 , V_48 ) ;
if ( V_9 -> V_42 - V_9 -> V_11 ) {
if ( V_9 -> V_40 == 1 )
* ( V_47 * ) ( V_9 -> V_43 ) = V_49 ;
else
* ( T_6 * ) ( V_9 -> V_43 ) = V_49 ;
}
V_9 -> V_43 += V_9 -> V_40 ;
}
}
static void * F_20 ( struct V_8 * V_9 )
{
struct V_50 * V_51 = V_9 -> V_52 ;
struct V_53 * V_54 = V_9 -> V_55 ;
if ( V_54 -> V_56 . V_57 != & V_51 -> V_58 ) {
V_9 -> V_55 =
F_21 ( V_54 -> V_56 . V_57 ,
struct V_53 ,
V_56 ) ;
return V_59 ;
} else
return V_60 ;
}
static int F_22 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_52 -> V_61
|| ! V_9 -> V_62
|| ! V_9 -> V_63 -> V_64
|| ! V_9 -> V_65 )
return 0 ;
if ( V_9 -> V_55 -> V_66 )
V_9 -> V_66 = V_9 -> V_55 -> V_66 ;
if ( V_9 -> V_55 -> V_67 )
V_9 -> V_67 = V_9 -> V_55 -> V_67 ;
return 1 ;
}
static void F_23 ( struct V_8 * V_9 )
{
struct V_53 * V_68 ;
unsigned long V_69 ;
struct V_50 * V_51 ;
F_24 ( & V_9 -> V_70 , V_69 ) ;
V_51 = V_9 -> V_52 ;
V_9 -> V_52 = NULL ;
V_9 -> V_55 = NULL ;
V_9 -> V_71 = V_9 -> V_63 ;
V_9 -> V_63 = NULL ;
V_9 -> V_72 = 0 ;
F_25 ( V_9 -> V_73 , & V_9 -> V_74 ) ;
F_26 ( & V_9 -> V_70 , V_69 ) ;
V_68 = F_21 ( V_51 -> V_58 . V_75 ,
struct V_53 ,
V_56 ) ;
if ( ! V_68 -> V_76 && V_9 -> V_77 )
V_9 -> V_77 ( V_78 ) ;
V_51 -> V_79 = NULL ;
if ( V_51 -> V_80 )
V_51 -> V_80 ( V_51 -> V_81 ) ;
}
static void F_27 ( struct V_8 * V_9 , const char * V_51 )
{
F_28 ( V_9 , 0 ) ;
F_29 ( & V_9 -> V_82 -> V_83 , L_20 , V_51 ) ;
V_9 -> V_52 -> V_79 = V_84 ;
F_30 ( & V_9 -> V_85 ) ;
}
void F_31 ( struct V_8 * V_9 )
{
V_9 -> V_52 -> V_86 += V_9 -> V_11 ;
V_9 -> V_52 -> V_79 = F_20 ( V_9 ) ;
if ( V_9 -> V_52 -> V_79 == V_60 ) {
V_9 -> V_52 -> V_87 = 0 ;
F_23 ( V_9 ) ;
} else
F_30 ( & V_9 -> V_85 ) ;
}
static T_7 F_32 ( struct V_8 * V_9 )
{
T_6 V_88 = F_13 ( V_9 , V_26 ) ;
if ( V_88 & ( V_89 | V_90 | V_91 ) ) {
F_13 ( V_9 , V_92 ) ;
F_13 ( V_9 , V_93 ) ;
F_13 ( V_9 , V_94 ) ;
F_27 ( V_9 , L_21 ) ;
return V_95 ;
}
F_19 ( V_9 ) ;
if ( V_9 -> V_42 == V_9 -> V_43 ) {
F_33 ( V_9 , V_96 ) ;
F_31 ( V_9 ) ;
return V_95 ;
}
if ( V_88 & V_96 ) {
F_33 ( V_9 , V_96 ) ;
F_17 ( V_9 ) ;
F_34 ( V_9 , V_96 ) ;
}
return V_95 ;
}
static T_7 F_35 ( int V_97 , void * V_98 )
{
struct V_8 * V_9 = V_98 ;
T_6 V_88 = F_13 ( V_9 , V_26 ) & 0x3f ;
if ( ! V_88 )
return V_99 ;
if ( ! V_9 -> V_52 ) {
F_33 ( V_9 , V_96 ) ;
return V_95 ;
}
return V_9 -> V_100 ( V_9 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
do {
F_17 ( V_9 ) ;
F_19 ( V_9 ) ;
F_37 () ;
} while ( V_9 -> V_42 > V_9 -> V_43 );
F_31 ( V_9 ) ;
}
static void V_85 ( unsigned long V_101 )
{
struct V_8 * V_9 = (struct V_8 * ) V_101 ;
struct V_50 * V_102 = NULL ;
struct V_53 * V_103 = NULL ;
struct V_53 * V_104 = NULL ;
struct V_105 * V_106 = NULL ;
struct V_107 * V_108 = NULL ;
V_47 V_109 = 0 ;
V_47 V_110 = 0 ;
V_47 V_76 = 0 ;
T_6 V_111 = 0 ;
T_6 V_112 = 0 ;
T_5 V_113 = 0 ;
T_5 V_114 = 0 ;
V_102 = V_9 -> V_52 ;
V_103 = V_9 -> V_55 ;
V_108 = V_9 -> V_63 ;
V_106 = V_102 -> V_106 ;
if ( F_38 ( ! V_108 -> V_112 ) )
V_108 -> V_112 = V_9 -> V_115 / V_108 -> V_116 ;
if ( V_102 -> V_79 == V_84 ) {
V_102 -> V_87 = - V_117 ;
goto V_118;
}
if ( V_102 -> V_79 == V_60 ) {
V_102 -> V_87 = 0 ;
goto V_118;
}
if ( V_102 -> V_79 == V_59 ) {
V_104 = F_21 ( V_103 -> V_56 . V_75 ,
struct V_53 ,
V_56 ) ;
if ( V_104 -> V_119 )
F_39 ( V_104 -> V_119 ) ;
}
V_9 -> V_40 = V_108 -> V_40 ;
V_9 -> V_120 = V_108 -> V_120 ;
V_9 -> V_77 = V_108 -> V_77 ;
V_9 -> V_67 = V_103 -> V_67 ;
V_9 -> V_66 = V_103 -> V_66 ;
V_9 -> V_39 = ( void * ) V_103 -> V_121 ;
V_9 -> V_38 = V_9 -> V_39 + V_103 -> V_11 ;
V_9 -> V_43 = V_103 -> V_122 ;
V_9 -> V_42 = V_9 -> V_43 + V_103 -> V_11 ;
V_9 -> V_76 = V_103 -> V_76 ;
V_9 -> V_11 = V_9 -> V_55 -> V_11 ;
if ( V_108 != V_9 -> V_71 )
V_76 = 1 ;
V_114 = V_108 -> V_114 ;
if ( V_103 -> V_116 ) {
V_113 = V_108 -> V_116 ;
if ( V_103 -> V_116 != V_113 ) {
V_113 = V_103 -> V_116 ;
if ( V_113 > V_9 -> V_115 ) {
F_40 ( V_123 L_22
L_23 , V_113 ) ;
V_102 -> V_87 = - V_117 ;
goto V_118;
}
V_112 = V_9 -> V_115 / V_113 ;
V_112 = ( V_112 + 1 ) & 0xfffe ;
V_108 -> V_116 = V_113 ;
V_108 -> V_112 = V_112 ;
}
}
if ( V_103 -> V_124 ) {
V_109 = V_103 -> V_124 ;
switch ( V_109 ) {
case 8 :
case 16 :
V_9 -> V_40 = V_9 -> V_120 = V_109 >> 3 ;
break;
default:
F_40 ( V_123 L_24
L_25 , V_109 ) ;
V_102 -> V_87 = - V_117 ;
goto V_118;
}
V_114 = ( V_109 - 1 )
| ( V_108 -> type << V_125 )
| ( V_106 -> V_126 << V_127 )
| ( V_108 -> V_128 << V_129 ) ;
}
V_102 -> V_79 = V_59 ;
if ( V_9 -> V_77 ) {
if ( V_9 -> V_43 && V_9 -> V_39 )
V_108 -> V_128 = V_130 ;
else if ( V_9 -> V_43 )
V_108 -> V_128 = V_131 ;
else
V_108 -> V_128 = V_132 ;
V_114 &= ~ V_133 ;
V_114 |= ( V_108 -> V_128 << V_129 ) ;
}
V_9 -> V_72 = F_22 ( V_9 ) ;
if ( ! V_9 -> V_72 && ! V_108 -> V_134 ) {
int V_135 = V_9 -> V_11 / V_9 -> V_40 ;
V_111 = V_9 -> V_41 / 2 ;
V_111 = ( V_135 > V_111 ) ? V_111 : V_135 ;
V_110 |= V_96 | V_89 | V_91 | V_90 ;
V_9 -> V_100 = F_32 ;
}
if ( F_13 ( V_9 , V_15 ) != V_114 || V_76 || V_112 || V_110 ) {
F_28 ( V_9 , 0 ) ;
if ( F_13 ( V_9 , V_15 ) != V_114 )
F_18 ( V_9 , V_15 , V_114 ) ;
F_41 ( V_9 , V_112 ? V_112 : V_108 -> V_112 ) ;
F_42 ( V_9 , V_106 -> V_136 ) ;
F_33 ( V_9 , 0xff ) ;
if ( V_110 )
F_34 ( V_9 , V_110 ) ;
if ( V_111 )
F_18 ( V_9 , V_20 , V_111 ) ;
F_28 ( V_9 , 1 ) ;
if ( V_76 )
V_9 -> V_71 = V_108 ;
}
if ( V_9 -> V_72 )
V_9 -> V_65 -> V_137 ( V_9 , V_76 ) ;
if ( V_108 -> V_134 )
F_36 ( V_9 ) ;
return;
V_118:
F_23 ( V_9 ) ;
return;
}
static void V_74 ( struct V_138 * V_139 )
{
struct V_8 * V_9 =
F_43 ( V_139 , struct V_8 , V_74 ) ;
unsigned long V_69 ;
F_24 ( & V_9 -> V_70 , V_69 ) ;
if ( F_44 ( & V_9 -> V_140 ) || V_9 -> V_141 == V_142 ) {
V_9 -> V_143 = 0 ;
F_26 ( & V_9 -> V_70 , V_69 ) ;
return;
}
if ( V_9 -> V_52 ) {
F_26 ( & V_9 -> V_70 , V_69 ) ;
return;
}
V_9 -> V_52 = F_21 ( V_9 -> V_140 . V_57 , struct V_50 , V_140 ) ;
F_45 ( & V_9 -> V_52 -> V_140 ) ;
V_9 -> V_52 -> V_79 = V_144 ;
V_9 -> V_55 = F_21 ( V_9 -> V_52 -> V_58 . V_57 ,
struct V_53 ,
V_56 ) ;
V_9 -> V_63 = F_46 ( V_9 -> V_52 -> V_106 ) ;
F_30 ( & V_9 -> V_85 ) ;
V_9 -> V_143 = 1 ;
F_26 ( & V_9 -> V_70 , V_69 ) ;
}
static int F_47 ( struct V_105 * V_106 , struct V_50 * V_51 )
{
struct V_8 * V_9 = F_48 ( V_106 -> V_82 ) ;
unsigned long V_69 ;
F_24 ( & V_9 -> V_70 , V_69 ) ;
if ( V_9 -> V_141 == V_142 ) {
F_26 ( & V_9 -> V_70 , V_69 ) ;
return - V_145 ;
}
V_51 -> V_86 = 0 ;
V_51 -> V_87 = - V_146 ;
V_51 -> V_79 = V_144 ;
F_49 ( & V_51 -> V_140 , & V_9 -> V_140 ) ;
if ( V_9 -> V_141 == V_147 && ! V_9 -> V_143 ) {
if ( V_9 -> V_55 || V_9 -> V_52 )
F_25 ( V_9 -> V_73 ,
& V_9 -> V_74 ) ;
else {
F_26 ( & V_9 -> V_70 , V_69 ) ;
V_74 ( & V_9 -> V_74 ) ;
return 0 ;
}
}
F_26 ( & V_9 -> V_70 , V_69 ) ;
return 0 ;
}
static int F_50 ( struct V_105 * V_106 )
{
struct V_148 * V_149 = NULL ;
struct V_107 * V_108 ;
if ( V_106 -> V_124 != 8 && V_106 -> V_124 != 16 )
return - V_150 ;
V_108 = F_46 ( V_106 ) ;
if ( ! V_108 ) {
V_108 = F_3 ( sizeof( struct V_107 ) , V_14 ) ;
if ( ! V_108 )
return - V_31 ;
}
V_149 = V_106 -> V_151 ;
if ( V_149 ) {
if ( V_149 -> V_77 )
V_108 -> V_77 = V_149 -> V_77 ;
V_108 -> V_134 = V_149 -> V_134 ;
V_108 -> type = V_149 -> type ;
V_108 -> V_152 = 0 ;
V_108 -> V_153 = 0 ;
V_108 -> V_64 = V_149 -> V_64 ;
}
if ( V_106 -> V_124 <= 8 ) {
V_108 -> V_40 = 1 ;
V_108 -> V_120 = 1 ;
} else if ( V_106 -> V_124 <= 16 ) {
V_108 -> V_40 = 2 ;
V_108 -> V_120 = 2 ;
} else {
F_29 ( & V_106 -> V_83 , L_26 ) ;
return - V_150 ;
}
V_108 -> V_124 = V_106 -> V_124 ;
if ( ! V_106 -> V_154 ) {
F_29 ( & V_106 -> V_83 , L_27 ) ;
return - V_150 ;
}
V_108 -> V_116 = V_106 -> V_154 ;
V_108 -> V_128 = 0 ;
V_108 -> V_114 = ( V_108 -> V_124 - 1 )
| ( V_108 -> type << V_125 )
| ( V_106 -> V_126 << V_127 )
| ( V_108 -> V_128 << V_129 ) ;
F_51 ( V_106 , V_108 ) ;
return 0 ;
}
static void F_52 ( struct V_105 * V_106 )
{
struct V_107 * V_108 = F_46 ( V_106 ) ;
F_6 ( V_108 ) ;
}
static int T_8 F_53 ( struct V_8 * V_9 )
{
F_54 ( & V_9 -> V_140 ) ;
F_55 ( & V_9 -> V_70 ) ;
V_9 -> V_141 = V_142 ;
V_9 -> V_143 = 0 ;
F_56 ( & V_9 -> V_85 ,
V_85 , ( unsigned long ) V_9 ) ;
F_57 ( & V_9 -> V_74 , V_74 ) ;
V_9 -> V_73 = F_58 (
F_59 ( V_9 -> V_82 -> V_83 . V_155 ) ) ;
if ( V_9 -> V_73 == NULL )
return - V_156 ;
return 0 ;
}
static int F_60 ( struct V_8 * V_9 )
{
unsigned long V_69 ;
F_24 ( & V_9 -> V_70 , V_69 ) ;
if ( V_9 -> V_141 == V_147 || V_9 -> V_143 ) {
F_26 ( & V_9 -> V_70 , V_69 ) ;
return - V_156 ;
}
V_9 -> V_141 = V_147 ;
V_9 -> V_52 = NULL ;
V_9 -> V_55 = NULL ;
V_9 -> V_63 = NULL ;
V_9 -> V_71 = NULL ;
F_26 ( & V_9 -> V_70 , V_69 ) ;
F_25 ( V_9 -> V_73 , & V_9 -> V_74 ) ;
return 0 ;
}
static int F_61 ( struct V_8 * V_9 )
{
unsigned long V_69 ;
unsigned V_157 = 50 ;
int V_87 = 0 ;
F_24 ( & V_9 -> V_70 , V_69 ) ;
V_9 -> V_141 = V_142 ;
while ( ( ! F_44 ( & V_9 -> V_140 ) || V_9 -> V_143 ) && V_157 -- ) {
F_26 ( & V_9 -> V_70 , V_69 ) ;
F_62 ( 10 ) ;
F_24 ( & V_9 -> V_70 , V_69 ) ;
}
if ( ! F_44 ( & V_9 -> V_140 ) || V_9 -> V_143 )
V_87 = - V_156 ;
F_26 ( & V_9 -> V_70 , V_69 ) ;
return V_87 ;
}
static int F_63 ( struct V_8 * V_9 )
{
int V_87 ;
V_87 = F_61 ( V_9 ) ;
if ( V_87 != 0 )
return V_87 ;
F_64 ( V_9 -> V_73 ) ;
return 0 ;
}
static void F_65 ( struct V_8 * V_9 )
{
F_28 ( V_9 , 0 ) ;
F_33 ( V_9 , 0xff ) ;
F_28 ( V_9 , 1 ) ;
if ( ! V_9 -> V_41 ) {
T_5 V_158 ;
for ( V_158 = 2 ; V_158 <= 257 ; V_158 ++ ) {
F_18 ( V_9 , V_20 , V_158 ) ;
if ( V_158 != F_13 ( V_9 , V_20 ) )
break;
}
V_9 -> V_41 = ( V_158 == 257 ) ? 0 : V_158 ;
F_18 ( V_9 , V_20 , 0 ) ;
}
}
int T_8 F_66 ( struct V_8 * V_9 )
{
struct V_159 * V_82 ;
int V_12 ;
F_67 ( V_9 == NULL ) ;
V_82 = F_68 ( V_9 -> V_160 , 0 ) ;
if ( ! V_82 ) {
V_12 = - V_31 ;
goto exit;
}
V_9 -> V_82 = V_82 ;
V_9 -> type = V_161 ;
V_9 -> V_71 = NULL ;
V_9 -> V_62 = 0 ;
V_9 -> V_162 = ( V_163 ) ( V_9 -> V_164 + 0x60 ) ;
snprintf ( V_9 -> V_165 , sizeof( V_9 -> V_165 ) , L_28 ,
V_9 -> V_166 ) ;
V_12 = F_69 ( V_9 -> V_97 , F_35 , V_167 ,
V_9 -> V_165 , V_9 ) ;
if ( V_12 < 0 ) {
F_29 ( & V_82 -> V_83 , L_29 ) ;
goto V_168;
}
V_82 -> V_169 = V_170 | V_171 ;
V_82 -> V_166 = V_9 -> V_166 ;
V_82 -> V_172 = V_9 -> V_173 ;
V_82 -> V_174 = F_52 ;
V_82 -> V_175 = F_50 ;
V_82 -> V_103 = F_47 ;
F_65 ( V_9 ) ;
if ( V_9 -> V_65 && V_9 -> V_65 -> V_176 ) {
V_12 = V_9 -> V_65 -> V_176 ( V_9 ) ;
if ( V_12 ) {
F_70 ( & V_82 -> V_83 , L_30 ) ;
V_9 -> V_62 = 0 ;
}
}
V_12 = F_53 ( V_9 ) ;
if ( V_12 ) {
F_29 ( & V_82 -> V_83 , L_31 ) ;
goto V_177;
}
V_12 = F_60 ( V_9 ) ;
if ( V_12 ) {
F_29 ( & V_82 -> V_83 , L_32 ) ;
goto V_177;
}
F_71 ( V_82 , V_9 ) ;
V_12 = F_72 ( V_82 ) ;
if ( V_12 ) {
F_29 ( & V_82 -> V_83 , L_33 ) ;
goto V_178;
}
F_7 ( V_9 ) ;
return 0 ;
V_178:
F_63 ( V_9 ) ;
if ( V_9 -> V_65 && V_9 -> V_65 -> V_179 )
V_9 -> V_65 -> V_179 ( V_9 ) ;
V_177:
F_28 ( V_9 , 0 ) ;
F_73 ( V_9 -> V_97 , V_9 ) ;
V_168:
F_74 ( V_82 ) ;
exit:
return V_12 ;
}
void T_9 F_75 ( struct V_8 * V_9 )
{
int V_87 = 0 ;
if ( ! V_9 )
return;
F_10 ( V_9 ) ;
V_87 = F_63 ( V_9 ) ;
if ( V_87 != 0 )
F_29 ( & V_9 -> V_82 -> V_83 , L_34
L_35 ) ;
if ( V_9 -> V_65 && V_9 -> V_65 -> V_179 )
V_9 -> V_65 -> V_179 ( V_9 ) ;
F_28 ( V_9 , 0 ) ;
F_41 ( V_9 , 0 ) ;
F_73 ( V_9 -> V_97 , V_9 ) ;
F_76 ( V_9 -> V_82 ) ;
}
int F_77 ( struct V_8 * V_9 )
{
int V_12 = 0 ;
V_12 = F_61 ( V_9 ) ;
if ( V_12 )
return V_12 ;
F_28 ( V_9 , 0 ) ;
F_41 ( V_9 , 0 ) ;
return V_12 ;
}
int F_78 ( struct V_8 * V_9 )
{
int V_12 ;
F_65 ( V_9 ) ;
V_12 = F_60 ( V_9 ) ;
if ( V_12 )
F_29 ( & V_9 -> V_82 -> V_83 , L_36 , V_12 ) ;
return V_12 ;
}
