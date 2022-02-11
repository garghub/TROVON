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
static void F_12 ( struct V_35 * V_36 , bool V_37 )
{
struct V_5 * V_6 = F_13 ( V_36 -> V_13 ) ;
struct V_38 * V_39 = F_14 ( V_36 ) ;
if ( V_39 && V_39 -> V_40 )
V_39 -> V_40 ( ! V_37 ) ;
if ( ! V_37 )
F_15 ( V_6 , V_18 , F_16 ( V_36 -> V_41 ) ) ;
}
static inline T_5 F_17 ( struct V_5 * V_6 )
{
T_5 V_42 , V_43 , V_44 ;
V_42 = ( V_6 -> V_45 - V_6 -> V_46 ) / V_6 -> V_47 ;
V_43 = V_6 -> V_48 - F_4 ( V_6 , V_22 ) ;
V_44 = ( ( V_6 -> V_49 - V_6 -> V_50 ) - ( V_6 -> V_45 - V_6 -> V_46 ) )
/ V_6 -> V_47 ;
return F_18 ( V_42 , V_43 , ( T_5 ) ( V_6 -> V_48 - V_44 ) ) ;
}
static inline T_5 F_19 ( struct V_5 * V_6 )
{
T_5 V_51 = ( V_6 -> V_49 - V_6 -> V_50 ) / V_6 -> V_47 ;
return F_20 ( T_5 , V_51 , F_4 ( V_6 , V_23 ) ) ;
}
static void F_21 ( struct V_5 * V_6 )
{
T_5 V_52 = F_17 ( V_6 ) ;
T_6 V_53 = 0 ;
while ( V_52 -- ) {
if ( V_6 -> V_45 - V_6 -> V_9 ) {
if ( V_6 -> V_47 == 1 )
V_53 = * ( V_54 * ) ( V_6 -> V_46 ) ;
else
V_53 = * ( T_6 * ) ( V_6 -> V_46 ) ;
}
F_22 ( V_6 , V_55 , V_53 ) ;
V_6 -> V_46 += V_6 -> V_47 ;
}
}
static void F_23 ( struct V_5 * V_6 )
{
T_5 V_52 = F_19 ( V_6 ) ;
T_6 V_56 ;
while ( V_52 -- ) {
V_56 = F_24 ( V_6 , V_55 ) ;
if ( V_6 -> V_49 - V_6 -> V_9 ) {
if ( V_6 -> V_47 == 1 )
* ( V_54 * ) ( V_6 -> V_50 ) = V_56 ;
else
* ( T_6 * ) ( V_6 -> V_50 ) = V_56 ;
}
V_6 -> V_50 += V_6 -> V_47 ;
}
}
static void F_25 ( struct V_5 * V_6 , const char * V_57 )
{
F_26 ( V_6 ) ;
F_27 ( & V_6 -> V_13 -> V_14 , L_20 , V_57 ) ;
V_6 -> V_13 -> V_58 -> V_59 = - V_60 ;
F_28 ( V_6 -> V_13 ) ;
}
static T_7 F_29 ( struct V_5 * V_6 )
{
T_6 V_61 = F_4 ( V_6 , V_26 ) ;
if ( V_61 & ( V_62 | V_63 | V_64 ) ) {
F_4 ( V_6 , V_65 ) ;
F_25 ( V_6 , L_21 ) ;
return V_66 ;
}
F_23 ( V_6 ) ;
if ( V_6 -> V_49 == V_6 -> V_50 ) {
F_30 ( V_6 , V_67 ) ;
F_28 ( V_6 -> V_13 ) ;
return V_66 ;
}
if ( V_61 & V_67 ) {
F_30 ( V_6 , V_67 ) ;
F_21 ( V_6 ) ;
F_31 ( V_6 , V_67 ) ;
}
return V_66 ;
}
static T_7 F_32 ( int V_68 , void * V_69 )
{
struct V_70 * V_13 = V_69 ;
struct V_5 * V_6 = F_13 ( V_13 ) ;
T_6 V_61 = F_4 ( V_6 , V_26 ) & 0x3f ;
if ( ! V_61 )
return V_71 ;
if ( ! V_13 -> V_58 ) {
F_30 ( V_6 , V_67 ) ;
return V_66 ;
}
return V_6 -> V_72 ( V_6 ) ;
}
static int F_33 ( struct V_5 * V_6 )
{
do {
F_21 ( V_6 ) ;
F_23 ( V_6 ) ;
F_34 () ;
} while ( V_6 -> V_49 > V_6 -> V_50 );
return 0 ;
}
static int F_35 ( struct V_70 * V_13 ,
struct V_35 * V_36 , struct V_73 * V_74 )
{
struct V_5 * V_6 = F_13 ( V_13 ) ;
struct V_38 * V_39 = F_14 ( V_36 ) ;
V_54 V_75 = 0 ;
T_6 V_76 = 0 ;
T_6 V_77 ;
T_5 V_78 ;
int V_10 ;
V_6 -> V_79 = 0 ;
V_6 -> V_46 = ( void * ) V_74 -> V_80 ;
V_6 -> V_45 = V_6 -> V_46 + V_74 -> V_9 ;
V_6 -> V_50 = V_74 -> V_81 ;
V_6 -> V_49 = V_6 -> V_50 + V_74 -> V_9 ;
V_6 -> V_9 = V_74 -> V_9 ;
F_36 ( V_6 , 0 ) ;
if ( V_74 -> V_82 != V_39 -> V_82 ) {
V_77 = ( V_6 -> V_83 / V_74 -> V_82 + 1 ) & 0xfffe ;
V_39 -> V_82 = V_74 -> V_82 ;
V_39 -> V_77 = V_77 ;
F_37 ( V_6 , V_39 -> V_77 ) ;
}
if ( V_74 -> V_84 == 8 ) {
V_6 -> V_47 = 1 ;
V_6 -> V_85 = 1 ;
} else if ( V_74 -> V_84 == 16 ) {
V_6 -> V_47 = 2 ;
V_6 -> V_85 = 2 ;
} else {
return - V_86 ;
}
V_78 = ( V_74 -> V_84 - 1 )
| ( V_39 -> type << V_87 )
| ( V_36 -> V_88 << V_89 )
| ( V_39 -> V_90 << V_91 ) ;
if ( V_39 -> V_40 ) {
if ( V_6 -> V_50 && V_6 -> V_46 )
V_39 -> V_90 = V_92 ;
else if ( V_6 -> V_50 )
V_39 -> V_90 = V_93 ;
else
V_39 -> V_90 = V_94 ;
V_78 &= ~ V_95 ;
V_78 |= ( V_39 -> V_90 << V_91 ) ;
}
F_15 ( V_6 , V_15 , V_78 ) ;
if ( V_13 -> V_96 && V_13 -> V_96 ( V_13 , V_36 , V_74 ) )
V_6 -> V_79 = V_13 -> V_97 ;
F_30 ( V_6 , 0xff ) ;
if ( V_6 -> V_79 ) {
V_10 = V_6 -> V_98 -> V_99 ( V_6 , V_74 ) ;
if ( V_10 < 0 ) {
F_36 ( V_6 , 1 ) ;
return V_10 ;
}
} else if ( ! V_39 -> V_100 ) {
V_76 = F_20 ( T_6 , V_6 -> V_48 / 2 , V_6 -> V_9 / V_6 -> V_47 ) ;
F_15 ( V_6 , V_20 , V_76 ) ;
V_75 |= V_67 | V_62 |
V_64 | V_63 ;
F_31 ( V_6 , V_75 ) ;
V_6 -> V_72 = F_29 ;
}
F_36 ( V_6 , 1 ) ;
if ( V_6 -> V_79 ) {
V_10 = V_6 -> V_98 -> V_101 ( V_6 , V_74 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( V_39 -> V_100 )
return F_33 ( V_6 ) ;
return 1 ;
}
static void F_38 ( struct V_70 * V_13 ,
struct V_102 * V_57 )
{
struct V_5 * V_6 = F_13 ( V_13 ) ;
if ( V_6 -> V_79 )
V_6 -> V_98 -> V_103 ( V_6 ) ;
F_26 ( V_6 ) ;
}
static int F_39 ( struct V_35 * V_36 )
{
struct V_104 * V_105 = NULL ;
struct V_38 * V_39 ;
int V_10 ;
V_39 = F_14 ( V_36 ) ;
if ( ! V_39 ) {
V_39 = F_2 ( sizeof( struct V_38 ) , V_12 ) ;
if ( ! V_39 )
return - V_31 ;
F_40 ( V_36 , V_39 ) ;
}
V_105 = V_36 -> V_106 ;
if ( V_105 ) {
if ( V_105 -> V_40 )
V_39 -> V_40 = V_105 -> V_40 ;
V_39 -> V_100 = V_105 -> V_100 ;
V_39 -> type = V_105 -> type ;
}
V_39 -> V_90 = 0 ;
if ( F_41 ( V_36 -> V_107 ) ) {
V_10 = F_42 ( V_36 -> V_107 ,
! ( V_36 -> V_88 & V_108 ) ) ;
if ( V_10 )
return V_10 ;
}
return 0 ;
}
static void F_43 ( struct V_35 * V_36 )
{
struct V_38 * V_39 = F_14 ( V_36 ) ;
F_6 ( V_39 ) ;
F_40 ( V_36 , NULL ) ;
}
static void F_44 ( struct V_109 * V_14 , struct V_5 * V_6 )
{
F_26 ( V_6 ) ;
if ( ! V_6 -> V_48 ) {
T_5 V_110 ;
for ( V_110 = 1 ; V_110 < 256 ; V_110 ++ ) {
F_15 ( V_6 , V_20 , V_110 ) ;
if ( V_110 != F_4 ( V_6 , V_20 ) )
break;
}
F_15 ( V_6 , V_20 , 0 ) ;
V_6 -> V_48 = ( V_110 == 1 ) ? 0 : V_110 ;
F_45 ( V_14 , L_22 , V_6 -> V_48 ) ;
}
}
int F_46 ( struct V_109 * V_14 , struct V_5 * V_6 )
{
struct V_70 * V_13 ;
int V_10 ;
F_47 ( V_6 == NULL ) ;
V_13 = F_48 ( V_14 , 0 ) ;
if ( ! V_13 )
return - V_31 ;
V_6 -> V_13 = V_13 ;
V_6 -> type = V_111 ;
V_6 -> V_112 = 0 ;
V_6 -> V_113 = ( V_114 ) ( V_6 -> V_115 + V_55 ) ;
snprintf ( V_6 -> V_116 , sizeof( V_6 -> V_116 ) , L_23 , V_6 -> V_117 ) ;
V_10 = F_49 ( V_6 -> V_68 , F_32 , V_118 , V_6 -> V_116 , V_13 ) ;
if ( V_10 < 0 ) {
F_27 ( V_14 , L_24 ) ;
goto V_119;
}
V_13 -> V_120 = V_121 | V_122 | V_123 ;
V_13 -> V_124 = F_50 ( 8 ) | F_50 ( 16 ) ;
V_13 -> V_117 = V_6 -> V_117 ;
V_13 -> V_125 = V_6 -> V_126 ;
V_13 -> V_127 = F_39 ;
V_13 -> V_128 = F_43 ;
V_13 -> V_129 = F_12 ;
V_13 -> V_130 = F_35 ;
V_13 -> V_131 = F_38 ;
V_13 -> V_132 = V_6 -> V_83 ;
V_13 -> V_14 . V_133 = V_14 -> V_133 ;
F_44 ( V_14 , V_6 ) ;
if ( V_6 -> V_98 && V_6 -> V_98 -> V_134 ) {
V_10 = V_6 -> V_98 -> V_134 ( V_6 ) ;
if ( V_10 ) {
F_51 ( V_14 , L_25 ) ;
V_6 -> V_112 = 0 ;
} else {
V_13 -> V_96 = V_6 -> V_98 -> V_96 ;
}
}
F_52 ( V_13 , V_6 ) ;
V_10 = F_53 ( V_14 , V_13 ) ;
if ( V_10 ) {
F_27 ( & V_13 -> V_14 , L_26 ) ;
goto V_135;
}
F_7 ( V_6 ) ;
return 0 ;
V_135:
if ( V_6 -> V_98 && V_6 -> V_98 -> V_136 )
V_6 -> V_98 -> V_136 ( V_6 ) ;
F_36 ( V_6 , 0 ) ;
F_54 ( V_6 -> V_68 , V_13 ) ;
V_119:
F_55 ( V_13 ) ;
return V_10 ;
}
void F_56 ( struct V_5 * V_6 )
{
F_10 ( V_6 ) ;
if ( V_6 -> V_98 && V_6 -> V_98 -> V_136 )
V_6 -> V_98 -> V_136 ( V_6 ) ;
F_57 ( V_6 ) ;
F_54 ( V_6 -> V_68 , V_6 -> V_13 ) ;
}
int F_58 ( struct V_5 * V_6 )
{
int V_10 ;
V_10 = F_59 ( V_6 -> V_13 ) ;
if ( V_10 )
return V_10 ;
F_57 ( V_6 ) ;
return 0 ;
}
int F_60 ( struct V_5 * V_6 )
{
int V_10 ;
F_44 ( & V_6 -> V_13 -> V_14 , V_6 ) ;
V_10 = F_61 ( V_6 -> V_13 ) ;
if ( V_10 )
F_27 ( & V_6 -> V_13 -> V_14 , L_27 , V_10 ) ;
return V_10 ;
}
