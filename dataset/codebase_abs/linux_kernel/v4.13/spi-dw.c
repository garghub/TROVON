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
char V_30 [ 32 ] ;
snprintf ( V_30 , 32 , L_18 , V_6 -> V_13 -> V_31 ) ;
V_6 -> V_32 = F_8 ( V_30 , NULL ) ;
if ( ! V_6 -> V_32 )
return - V_33 ;
F_9 ( L_19 , V_34 | V_35 ,
V_6 -> V_32 , ( void * ) V_6 , & V_36 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_6 )
{
F_11 ( V_6 -> V_32 ) ;
}
static inline int F_7 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline void F_10 ( struct V_5 * V_6 )
{
}
static void F_12 ( struct V_37 * V_38 , bool V_39 )
{
struct V_5 * V_6 = F_13 ( V_38 -> V_13 ) ;
struct V_40 * V_41 = F_14 ( V_38 ) ;
if ( V_41 && V_41 -> V_42 )
V_41 -> V_42 ( ! V_39 ) ;
if ( ! V_39 )
F_15 ( V_6 , V_18 , F_16 ( V_38 -> V_43 ) ) ;
}
static inline T_5 F_17 ( struct V_5 * V_6 )
{
T_5 V_44 , V_45 , V_46 ;
V_44 = ( V_6 -> V_47 - V_6 -> V_48 ) / V_6 -> V_49 ;
V_45 = V_6 -> V_50 - F_4 ( V_6 , V_22 ) ;
V_46 = ( ( V_6 -> V_51 - V_6 -> V_52 ) - ( V_6 -> V_47 - V_6 -> V_48 ) )
/ V_6 -> V_49 ;
return F_18 ( V_44 , V_45 , ( T_5 ) ( V_6 -> V_50 - V_46 ) ) ;
}
static inline T_5 F_19 ( struct V_5 * V_6 )
{
T_5 V_53 = ( V_6 -> V_51 - V_6 -> V_52 ) / V_6 -> V_49 ;
return F_20 ( T_5 , V_53 , F_4 ( V_6 , V_23 ) ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
T_5 V_54 = F_17 ( V_6 ) ;
T_6 V_55 = 0 ;
while ( V_54 -- ) {
if ( V_6 -> V_47 - V_6 -> V_9 ) {
if ( V_6 -> V_49 == 1 )
V_55 = * ( V_56 * ) ( V_6 -> V_48 ) ;
else
V_55 = * ( T_6 * ) ( V_6 -> V_48 ) ;
}
F_22 ( V_6 , V_57 , V_55 ) ;
V_6 -> V_48 += V_6 -> V_49 ;
}
}
static void F_23 ( struct V_5 * V_6 )
{
T_5 V_54 = F_19 ( V_6 ) ;
T_6 V_58 ;
while ( V_54 -- ) {
V_58 = F_24 ( V_6 , V_57 ) ;
if ( V_6 -> V_51 - V_6 -> V_9 ) {
if ( V_6 -> V_49 == 1 )
* ( V_56 * ) ( V_6 -> V_52 ) = V_58 ;
else
* ( T_6 * ) ( V_6 -> V_52 ) = V_58 ;
}
V_6 -> V_52 += V_6 -> V_49 ;
}
}
static void F_25 ( struct V_5 * V_6 , const char * V_59 )
{
F_26 ( V_6 ) ;
F_27 ( & V_6 -> V_13 -> V_14 , L_20 , V_59 ) ;
V_6 -> V_13 -> V_60 -> V_61 = - V_62 ;
F_28 ( V_6 -> V_13 ) ;
}
static T_7 F_29 ( struct V_5 * V_6 )
{
T_6 V_63 = F_4 ( V_6 , V_26 ) ;
if ( V_63 & ( V_64 | V_65 | V_66 ) ) {
F_4 ( V_6 , V_67 ) ;
F_25 ( V_6 , L_21 ) ;
return V_68 ;
}
F_23 ( V_6 ) ;
if ( V_6 -> V_51 == V_6 -> V_52 ) {
F_30 ( V_6 , V_69 ) ;
F_28 ( V_6 -> V_13 ) ;
return V_68 ;
}
if ( V_63 & V_69 ) {
F_30 ( V_6 , V_69 ) ;
F_21 ( V_6 ) ;
F_31 ( V_6 , V_69 ) ;
}
return V_68 ;
}
static T_7 F_32 ( int V_70 , void * V_71 )
{
struct V_72 * V_13 = V_71 ;
struct V_5 * V_6 = F_13 ( V_13 ) ;
T_6 V_63 = F_4 ( V_6 , V_26 ) & 0x3f ;
if ( ! V_63 )
return V_73 ;
if ( ! V_13 -> V_60 ) {
F_30 ( V_6 , V_69 ) ;
return V_68 ;
}
return V_6 -> V_74 ( V_6 ) ;
}
static int F_33 ( struct V_5 * V_6 )
{
do {
F_21 ( V_6 ) ;
F_23 ( V_6 ) ;
F_34 () ;
} while ( V_6 -> V_51 > V_6 -> V_52 );
return 0 ;
}
static int F_35 ( struct V_72 * V_13 ,
struct V_37 * V_38 , struct V_75 * V_76 )
{
struct V_5 * V_6 = F_13 ( V_13 ) ;
struct V_40 * V_41 = F_14 ( V_38 ) ;
V_56 V_77 = 0 ;
T_6 V_78 = 0 ;
T_5 V_79 ;
int V_10 ;
V_6 -> V_80 = 0 ;
V_6 -> V_48 = ( void * ) V_76 -> V_81 ;
V_6 -> V_47 = V_6 -> V_48 + V_76 -> V_9 ;
V_6 -> V_52 = V_76 -> V_82 ;
V_6 -> V_51 = V_6 -> V_52 + V_76 -> V_9 ;
V_6 -> V_9 = V_76 -> V_9 ;
F_36 ( V_6 , 0 ) ;
if ( V_76 -> V_83 != V_6 -> V_84 ) {
if ( V_76 -> V_83 != V_41 -> V_83 ) {
V_41 -> V_85 = ( F_37 ( V_6 -> V_86 , V_76 -> V_83 ) + 1 ) & 0xfffe ;
V_41 -> V_83 = V_76 -> V_83 ;
}
V_6 -> V_84 = V_76 -> V_83 ;
F_38 ( V_6 , V_41 -> V_85 ) ;
}
if ( V_76 -> V_87 == 8 ) {
V_6 -> V_49 = 1 ;
V_6 -> V_88 = 1 ;
} else if ( V_76 -> V_87 == 16 ) {
V_6 -> V_49 = 2 ;
V_6 -> V_88 = 2 ;
} else {
return - V_89 ;
}
V_79 = ( V_76 -> V_87 - 1 )
| ( V_41 -> type << V_90 )
| ( V_38 -> V_91 << V_92 )
| ( V_41 -> V_93 << V_94 ) ;
if ( V_41 -> V_42 ) {
if ( V_6 -> V_52 && V_6 -> V_48 )
V_41 -> V_93 = V_95 ;
else if ( V_6 -> V_52 )
V_41 -> V_93 = V_96 ;
else
V_41 -> V_93 = V_97 ;
V_79 &= ~ V_98 ;
V_79 |= ( V_41 -> V_93 << V_94 ) ;
}
F_15 ( V_6 , V_15 , V_79 ) ;
if ( V_13 -> V_99 && V_13 -> V_99 ( V_13 , V_38 , V_76 ) )
V_6 -> V_80 = V_13 -> V_100 ;
F_30 ( V_6 , 0xff ) ;
if ( V_6 -> V_80 ) {
V_10 = V_6 -> V_101 -> V_102 ( V_6 , V_76 ) ;
if ( V_10 < 0 ) {
F_36 ( V_6 , 1 ) ;
return V_10 ;
}
} else if ( ! V_41 -> V_103 ) {
V_78 = F_20 ( T_6 , V_6 -> V_50 / 2 , V_6 -> V_9 / V_6 -> V_49 ) ;
F_15 ( V_6 , V_20 , V_78 ) ;
V_77 |= V_69 | V_64 |
V_66 | V_65 ;
F_31 ( V_6 , V_77 ) ;
V_6 -> V_74 = F_29 ;
}
F_36 ( V_6 , 1 ) ;
if ( V_6 -> V_80 ) {
V_10 = V_6 -> V_101 -> V_104 ( V_6 , V_76 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_41 -> V_103 )
return F_33 ( V_6 ) ;
return 1 ;
}
static void F_39 ( struct V_72 * V_13 ,
struct V_105 * V_59 )
{
struct V_5 * V_6 = F_13 ( V_13 ) ;
if ( V_6 -> V_80 )
V_6 -> V_101 -> V_106 ( V_6 ) ;
F_26 ( V_6 ) ;
}
static int F_40 ( struct V_37 * V_38 )
{
struct V_107 * V_108 = NULL ;
struct V_40 * V_41 ;
int V_10 ;
V_41 = F_14 ( V_38 ) ;
if ( ! V_41 ) {
V_41 = F_2 ( sizeof( struct V_40 ) , V_12 ) ;
if ( ! V_41 )
return - V_33 ;
F_41 ( V_38 , V_41 ) ;
}
V_108 = V_38 -> V_109 ;
if ( V_108 ) {
if ( V_108 -> V_42 )
V_41 -> V_42 = V_108 -> V_42 ;
V_41 -> V_103 = V_108 -> V_103 ;
V_41 -> type = V_108 -> type ;
}
V_41 -> V_93 = V_95 ;
if ( F_42 ( V_38 -> V_110 ) ) {
V_10 = F_43 ( V_38 -> V_110 ,
! ( V_38 -> V_91 & V_111 ) ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_44 ( struct V_37 * V_38 )
{
struct V_40 * V_41 = F_14 ( V_38 ) ;
F_6 ( V_41 ) ;
F_41 ( V_38 , NULL ) ;
}
static void F_45 ( struct V_112 * V_14 , struct V_5 * V_6 )
{
F_26 ( V_6 ) ;
if ( ! V_6 -> V_50 ) {
T_5 V_113 ;
for ( V_113 = 1 ; V_113 < 256 ; V_113 ++ ) {
F_15 ( V_6 , V_20 , V_113 ) ;
if ( V_113 != F_4 ( V_6 , V_20 ) )
break;
}
F_15 ( V_6 , V_20 , 0 ) ;
V_6 -> V_50 = ( V_113 == 1 ) ? 0 : V_113 ;
F_46 ( V_14 , L_22 , V_6 -> V_50 ) ;
}
}
int F_47 ( struct V_112 * V_14 , struct V_5 * V_6 )
{
struct V_72 * V_13 ;
int V_10 ;
F_48 ( V_6 == NULL ) ;
V_13 = F_49 ( V_14 , 0 ) ;
if ( ! V_13 )
return - V_33 ;
V_6 -> V_13 = V_13 ;
V_6 -> type = V_114 ;
V_6 -> V_115 = 0 ;
V_6 -> V_116 = ( V_117 ) ( V_6 -> V_118 + V_57 ) ;
V_10 = F_50 ( V_6 -> V_70 , F_32 , V_119 , F_3 ( V_14 ) ,
V_13 ) ;
if ( V_10 < 0 ) {
F_27 ( V_14 , L_23 ) ;
goto V_120;
}
V_13 -> V_121 = V_122 | V_123 | V_124 ;
V_13 -> V_125 = F_51 ( 8 ) | F_51 ( 16 ) ;
V_13 -> V_31 = V_6 -> V_31 ;
V_13 -> V_126 = V_6 -> V_127 ;
V_13 -> V_128 = F_40 ;
V_13 -> V_129 = F_44 ;
V_13 -> V_130 = F_12 ;
V_13 -> V_131 = F_35 ;
V_13 -> V_132 = F_39 ;
V_13 -> V_133 = V_6 -> V_86 ;
V_13 -> V_14 . V_134 = V_14 -> V_134 ;
V_13 -> V_135 = V_136 ;
F_45 ( V_14 , V_6 ) ;
if ( V_6 -> V_101 && V_6 -> V_101 -> V_137 ) {
V_10 = V_6 -> V_101 -> V_137 ( V_6 ) ;
if ( V_10 ) {
F_52 ( V_14 , L_24 ) ;
V_6 -> V_115 = 0 ;
} else {
V_13 -> V_99 = V_6 -> V_101 -> V_99 ;
}
}
F_53 ( V_13 , V_6 ) ;
V_10 = F_54 ( V_14 , V_13 ) ;
if ( V_10 ) {
F_27 ( & V_13 -> V_14 , L_25 ) ;
goto V_138;
}
F_7 ( V_6 ) ;
return 0 ;
V_138:
if ( V_6 -> V_101 && V_6 -> V_101 -> V_139 )
V_6 -> V_101 -> V_139 ( V_6 ) ;
F_36 ( V_6 , 0 ) ;
F_55 ( V_6 -> V_70 , V_13 ) ;
V_120:
F_56 ( V_13 ) ;
return V_10 ;
}
void F_57 ( struct V_5 * V_6 )
{
F_10 ( V_6 ) ;
if ( V_6 -> V_101 && V_6 -> V_101 -> V_139 )
V_6 -> V_101 -> V_139 ( V_6 ) ;
F_58 ( V_6 ) ;
F_55 ( V_6 -> V_70 , V_6 -> V_13 ) ;
}
int F_59 ( struct V_5 * V_6 )
{
int V_10 ;
V_10 = F_60 ( V_6 -> V_13 ) ;
if ( V_10 )
return V_10 ;
F_58 ( V_6 ) ;
return 0 ;
}
int F_61 ( struct V_5 * V_6 )
{
int V_10 ;
F_45 ( & V_6 -> V_13 -> V_14 , V_6 ) ;
V_10 = F_62 ( V_6 -> V_13 ) ;
if ( V_10 )
F_27 ( & V_6 -> V_13 -> V_14 , L_26 , V_10 ) ;
return V_10 ;
}
