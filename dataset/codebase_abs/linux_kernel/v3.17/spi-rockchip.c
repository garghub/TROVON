static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( ( V_3 ? 1 : 0 ) , V_2 -> V_4 + V_5 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 div )
{
F_2 ( div , V_2 -> V_4 + V_6 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
while ( F_5 ( V_2 -> V_4 + V_7 ) )
F_5 ( V_2 -> V_4 + V_8 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_10 + F_7 ( 5 ) ;
do {
if ( ! ( F_5 ( V_2 -> V_4 + V_11 ) & V_12 ) )
return;
} while ( ! F_8 ( V_10 , V_9 ) );
F_9 ( V_2 -> V_13 , L_1 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
T_2 V_14 ;
for ( V_14 = 2 ; V_14 < 32 ; V_14 ++ ) {
F_2 ( V_14 , V_2 -> V_4 + V_15 ) ;
if ( V_14 != F_5 ( V_2 -> V_4 + V_15 ) )
break;
}
F_2 ( 0 , V_2 -> V_4 + V_15 ) ;
return ( V_14 == 31 ) ? 0 : V_14 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 )
{
T_2 V_16 , V_17 ;
V_16 = ( V_2 -> V_18 - V_2 -> V_19 ) / V_2 -> V_20 ;
V_17 = V_2 -> V_21 - F_5 ( V_2 -> V_4 + V_22 ) ;
return F_12 ( V_16 , V_17 ) ;
}
static inline T_2 F_13 ( struct V_1 * V_2 )
{
T_2 V_23 = ( V_2 -> V_24 - V_2 -> V_25 ) / V_2 -> V_20 ;
T_2 V_26 = ( T_2 ) F_5 ( V_2 -> V_4 + V_7 ) ;
return F_12 ( V_23 , V_26 ) ;
}
static void F_14 ( struct V_27 * V_28 , bool V_3 )
{
T_2 V_29 ;
struct V_1 * V_2 = F_15 ( V_28 -> V_30 ) ;
V_29 = F_5 ( V_2 -> V_4 + V_31 ) & V_32 ;
if ( ! V_3 )
V_29 |= 1 << V_28 -> V_33 ;
else
V_29 &= ~ ( 1 << V_28 -> V_33 ) ;
F_2 ( V_29 , V_2 -> V_4 + V_31 ) ;
}
static int F_16 ( struct V_34 * V_30 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_15 ( V_30 ) ;
struct V_27 * V_28 = V_36 -> V_28 ;
V_2 -> V_37 = V_28 -> V_37 ;
return 0 ;
}
static int F_17 ( struct V_34 * V_30 ,
struct V_35 * V_36 )
{
unsigned long V_38 ;
struct V_1 * V_2 = F_15 ( V_30 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
if ( V_2 -> V_40 ) {
if ( V_2 -> V_41 & V_42 ) {
F_19 ( V_2 -> V_43 . V_44 ) ;
F_4 ( V_2 ) ;
}
if ( V_2 -> V_41 & V_45 )
F_19 ( V_2 -> V_46 . V_44 ) ;
}
F_20 ( & V_2 -> V_39 , V_38 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_47 = F_11 ( V_2 ) ;
T_2 V_48 = 0 ;
while ( V_47 -- ) {
if ( V_2 -> V_20 == 1 )
V_48 = * ( V_49 * ) ( V_2 -> V_19 ) ;
else
V_48 = * ( T_1 * ) ( V_2 -> V_19 ) ;
F_2 ( V_48 , V_2 -> V_4 + V_50 ) ;
V_2 -> V_19 += V_2 -> V_20 ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
T_2 V_47 = F_13 ( V_2 ) ;
T_2 V_51 ;
while ( V_47 -- ) {
V_51 = F_5 ( V_2 -> V_4 + V_8 ) ;
if ( V_2 -> V_20 == 1 )
* ( V_49 * ) ( V_2 -> V_25 ) = ( V_49 ) V_51 ;
else
* ( T_1 * ) ( V_2 -> V_25 ) = ( T_1 ) V_51 ;
V_2 -> V_25 += V_2 -> V_20 ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
do {
if ( V_2 -> V_19 ) {
V_52 = V_2 -> V_18 - V_2 -> V_19 ;
F_21 ( V_2 ) ;
}
if ( V_2 -> V_25 ) {
V_52 = V_2 -> V_24 - V_2 -> V_25 ;
F_22 ( V_2 ) ;
}
F_24 () ;
} while ( V_52 );
if ( V_2 -> V_19 )
F_6 ( V_2 ) ;
return 0 ;
}
static void F_25 ( void * V_53 )
{
unsigned long V_38 ;
struct V_1 * V_2 = V_53 ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
V_2 -> V_41 &= ~ V_42 ;
if ( ! ( V_2 -> V_41 & V_45 ) )
F_26 ( V_2 -> V_30 ) ;
F_20 ( & V_2 -> V_39 , V_38 ) ;
}
static void F_27 ( void * V_53 )
{
unsigned long V_38 ;
struct V_1 * V_2 = V_53 ;
F_6 ( V_2 ) ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
V_2 -> V_41 &= ~ V_45 ;
if ( ! ( V_2 -> V_41 & V_42 ) )
F_26 ( V_2 -> V_30 ) ;
F_20 ( & V_2 -> V_39 , V_38 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
unsigned long V_38 ;
struct V_54 V_55 , V_56 ;
struct V_57 * V_58 , * V_59 ;
F_18 ( & V_2 -> V_39 , V_38 ) ;
V_2 -> V_41 &= ~ V_42 ;
V_2 -> V_41 &= ~ V_45 ;
F_20 ( & V_2 -> V_39 , V_38 ) ;
if ( V_2 -> V_25 ) {
V_55 . V_60 = V_2 -> V_43 . V_60 ;
V_55 . V_61 = V_2 -> V_43 . V_62 ;
V_55 . V_63 = V_2 -> V_20 ;
V_55 . V_64 = V_2 -> V_20 ;
F_29 ( V_2 -> V_43 . V_44 , & V_55 ) ;
V_58 = F_30 (
V_2 -> V_43 . V_44 ,
V_2 -> V_65 . V_66 , V_2 -> V_65 . V_67 ,
V_2 -> V_43 . V_60 , V_68 ) ;
V_58 -> V_69 = F_25 ;
V_58 -> V_70 = V_2 ;
}
if ( V_2 -> V_19 ) {
V_56 . V_60 = V_2 -> V_46 . V_60 ;
V_56 . V_71 = V_2 -> V_46 . V_62 ;
V_56 . V_72 = V_2 -> V_20 ;
V_56 . V_73 = V_2 -> V_20 ;
F_29 ( V_2 -> V_46 . V_44 , & V_56 ) ;
V_59 = F_30 (
V_2 -> V_46 . V_44 ,
V_2 -> V_74 . V_66 , V_2 -> V_74 . V_67 ,
V_2 -> V_46 . V_60 , V_68 ) ;
V_59 -> V_69 = F_27 ;
V_59 -> V_70 = V_2 ;
}
if ( V_2 -> V_25 ) {
F_18 ( & V_2 -> V_39 , V_38 ) ;
V_2 -> V_41 |= V_42 ;
F_20 ( & V_2 -> V_39 , V_38 ) ;
F_31 ( V_58 ) ;
F_32 ( V_2 -> V_43 . V_44 ) ;
}
if ( V_2 -> V_19 ) {
F_18 ( & V_2 -> V_39 , V_38 ) ;
V_2 -> V_41 |= V_45 ;
F_20 ( & V_2 -> V_39 , V_38 ) ;
F_31 ( V_59 ) ;
F_32 ( V_2 -> V_46 . V_44 ) ;
}
return 1 ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_2 div = 0 ;
T_2 V_75 = 0 ;
T_2 V_76 = ( V_77 << V_78 )
| ( V_79 << V_80 ) ;
V_76 |= ( V_2 -> V_20 << V_81 ) ;
V_76 |= ( ( V_2 -> V_37 & 0x3 ) << V_82 ) ;
V_76 |= ( V_2 -> V_83 << V_84 ) ;
V_76 |= ( V_2 -> type << V_85 ) ;
if ( V_2 -> V_40 ) {
if ( V_2 -> V_19 )
V_75 |= V_86 ;
if ( V_2 -> V_25 )
V_75 |= V_87 ;
}
div = F_34 ( T_2 , V_2 -> V_88 / V_2 -> V_89 , 1 ) ;
div = ( div + 1 ) & 0xfffe ;
F_1 ( V_2 , 0 ) ;
F_2 ( V_76 , V_2 -> V_4 + V_90 ) ;
F_2 ( V_2 -> V_91 - 1 , V_2 -> V_4 + V_92 ) ;
F_2 ( V_2 -> V_21 / 2 - 1 , V_2 -> V_4 + V_15 ) ;
F_2 ( V_2 -> V_21 / 2 - 1 , V_2 -> V_4 + V_93 ) ;
F_2 ( 0 , V_2 -> V_4 + V_94 ) ;
F_2 ( 0 , V_2 -> V_4 + V_95 ) ;
F_2 ( V_75 , V_2 -> V_4 + V_96 ) ;
F_3 ( V_2 , div ) ;
F_35 ( V_2 -> V_13 , L_2 , V_76 , div ) ;
F_1 ( V_2 , 1 ) ;
}
static int F_36 (
struct V_34 * V_30 ,
struct V_27 * V_28 ,
struct V_97 * V_98 )
{
int V_99 = 0 ;
struct V_1 * V_2 = F_15 ( V_30 ) ;
F_37 ( F_5 ( V_2 -> V_4 + V_5 ) &&
( F_5 ( V_2 -> V_4 + V_11 ) & V_12 ) ) ;
if ( ! V_98 -> V_100 && ! V_98 -> V_101 ) {
F_38 ( V_2 -> V_13 , L_3 ) ;
return - V_102 ;
}
V_2 -> V_89 = V_98 -> V_103 ;
V_2 -> V_104 = V_98 -> V_105 ;
V_2 -> V_20 = V_2 -> V_104 >> 3 ;
V_2 -> V_19 = V_98 -> V_100 ;
V_2 -> V_18 = V_2 -> V_19 + V_98 -> V_91 ;
V_2 -> V_25 = V_98 -> V_101 ;
V_2 -> V_24 = V_2 -> V_25 + V_98 -> V_91 ;
V_2 -> V_91 = V_98 -> V_91 ;
V_2 -> V_74 = V_98 -> V_74 ;
V_2 -> V_65 = V_98 -> V_65 ;
if ( V_2 -> V_19 && V_2 -> V_25 )
V_2 -> V_83 = V_106 ;
else if ( V_2 -> V_19 )
V_2 -> V_83 = V_107 ;
else if ( V_2 -> V_25 )
V_2 -> V_83 = V_108 ;
if ( V_30 -> V_109 && V_30 -> V_109 ( V_30 , V_28 , V_98 ) )
V_2 -> V_40 = 1 ;
else
V_2 -> V_40 = 0 ;
F_33 ( V_2 ) ;
if ( V_2 -> V_40 )
V_99 = F_28 ( V_2 ) ;
else
V_99 = F_23 ( V_2 ) ;
return V_99 ;
}
static bool F_39 ( struct V_34 * V_30 ,
struct V_27 * V_28 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_15 ( V_30 ) ;
return ( V_98 -> V_91 > V_2 -> V_21 ) ;
}
static int F_40 ( struct V_110 * V_111 )
{
int V_99 = 0 ;
struct V_1 * V_2 ;
struct V_34 * V_30 ;
struct V_112 * V_113 ;
V_30 = F_41 ( & V_111 -> V_13 , sizeof( struct V_1 ) ) ;
if ( ! V_30 )
return - V_114 ;
F_42 ( V_111 , V_30 ) ;
V_2 = F_15 ( V_30 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_113 = F_43 ( V_111 , V_115 , 0 ) ;
V_2 -> V_4 = F_44 ( & V_111 -> V_13 , V_113 ) ;
if ( F_45 ( V_2 -> V_4 ) ) {
V_99 = F_46 ( V_2 -> V_4 ) ;
goto V_116;
}
V_2 -> V_117 = F_47 ( & V_111 -> V_13 , L_4 ) ;
if ( F_45 ( V_2 -> V_117 ) ) {
F_38 ( & V_111 -> V_13 , L_5 ) ;
V_99 = F_46 ( V_2 -> V_117 ) ;
goto V_116;
}
V_2 -> V_118 = F_47 ( & V_111 -> V_13 , L_6 ) ;
if ( F_45 ( V_2 -> V_118 ) ) {
F_38 ( & V_111 -> V_13 , L_7 ) ;
V_99 = F_46 ( V_2 -> V_118 ) ;
goto V_116;
}
V_99 = F_48 ( V_2 -> V_117 ) ;
if ( V_99 ) {
F_38 ( & V_111 -> V_13 , L_8 ) ;
goto V_116;
}
V_99 = F_48 ( V_2 -> V_118 ) ;
if ( V_99 ) {
F_38 ( & V_111 -> V_13 , L_9 ) ;
goto V_119;
}
F_1 ( V_2 , 0 ) ;
V_2 -> type = V_120 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_13 = & V_111 -> V_13 ;
V_2 -> V_88 = F_49 ( V_2 -> V_118 ) ;
V_2 -> V_21 = F_10 ( V_2 ) ;
if ( ! V_2 -> V_21 ) {
F_38 ( & V_111 -> V_13 , L_10 ) ;
V_99 = - V_102 ;
goto V_121;
}
F_50 ( & V_2 -> V_39 ) ;
F_51 ( & V_111 -> V_13 ) ;
F_52 ( & V_111 -> V_13 ) ;
V_30 -> V_122 = true ;
V_30 -> V_123 = V_111 -> V_124 ;
V_30 -> V_125 = V_126 | V_127 | V_128 ;
V_30 -> V_129 = 2 ;
V_30 -> V_13 . V_130 = V_111 -> V_13 . V_130 ;
V_30 -> V_131 = F_53 ( 16 ) | F_53 ( 8 ) ;
V_30 -> V_132 = F_14 ;
V_30 -> V_133 = F_16 ;
V_30 -> V_134 = F_17 ;
V_30 -> V_135 = F_36 ;
V_2 -> V_46 . V_44 = F_54 ( V_2 -> V_13 , L_11 ) ;
if ( ! V_2 -> V_46 . V_44 )
F_9 ( V_2 -> V_13 , L_12 ) ;
V_2 -> V_43 . V_44 = F_54 ( V_2 -> V_13 , L_13 ) ;
if ( ! V_2 -> V_43 . V_44 ) {
if ( V_2 -> V_46 . V_44 ) {
F_55 ( V_2 -> V_46 . V_44 ) ;
V_2 -> V_46 . V_44 = NULL ;
}
F_9 ( V_2 -> V_13 , L_14 ) ;
}
if ( V_2 -> V_46 . V_44 && V_2 -> V_43 . V_44 ) {
V_2 -> V_46 . V_62 = ( V_136 ) ( V_113 -> V_137 + V_50 ) ;
V_2 -> V_43 . V_62 = ( V_136 ) ( V_113 -> V_137 + V_8 ) ;
V_2 -> V_46 . V_60 = V_138 ;
V_2 -> V_43 . V_60 = V_139 ;
V_30 -> V_109 = F_39 ;
V_30 -> V_46 = V_2 -> V_46 . V_44 ;
V_30 -> V_43 = V_2 -> V_43 . V_44 ;
}
V_99 = F_56 ( & V_111 -> V_13 , V_30 ) ;
if ( V_99 ) {
F_38 ( & V_111 -> V_13 , L_15 ) ;
goto V_140;
}
return 0 ;
V_140:
if ( V_2 -> V_46 . V_44 )
F_55 ( V_2 -> V_46 . V_44 ) ;
if ( V_2 -> V_43 . V_44 )
F_55 ( V_2 -> V_43 . V_44 ) ;
V_121:
F_57 ( V_2 -> V_118 ) ;
V_119:
F_57 ( V_2 -> V_117 ) ;
V_116:
F_58 ( V_30 ) ;
return V_99 ;
}
static int F_59 ( struct V_110 * V_111 )
{
struct V_34 * V_30 = F_60 ( F_61 ( V_111 ) ) ;
struct V_1 * V_2 = F_15 ( V_30 ) ;
F_62 ( & V_111 -> V_13 ) ;
F_57 ( V_2 -> V_118 ) ;
F_57 ( V_2 -> V_117 ) ;
if ( V_2 -> V_46 . V_44 )
F_55 ( V_2 -> V_46 . V_44 ) ;
if ( V_2 -> V_43 . V_44 )
F_55 ( V_2 -> V_43 . V_44 ) ;
F_58 ( V_30 ) ;
return 0 ;
}
static int F_63 ( struct V_141 * V_13 )
{
int V_99 = 0 ;
struct V_34 * V_30 = F_64 ( V_13 ) ;
struct V_1 * V_2 = F_15 ( V_30 ) ;
V_99 = F_65 ( V_2 -> V_30 ) ;
if ( V_99 )
return V_99 ;
if ( ! F_66 ( V_13 ) ) {
F_57 ( V_2 -> V_118 ) ;
F_57 ( V_2 -> V_117 ) ;
}
return V_99 ;
}
static int F_67 ( struct V_141 * V_13 )
{
int V_99 = 0 ;
struct V_34 * V_30 = F_64 ( V_13 ) ;
struct V_1 * V_2 = F_15 ( V_30 ) ;
if ( ! F_66 ( V_13 ) ) {
V_99 = F_48 ( V_2 -> V_117 ) ;
if ( V_99 < 0 )
return V_99 ;
V_99 = F_48 ( V_2 -> V_118 ) ;
if ( V_99 < 0 ) {
F_57 ( V_2 -> V_117 ) ;
return V_99 ;
}
}
V_99 = F_68 ( V_2 -> V_30 ) ;
if ( V_99 < 0 ) {
F_57 ( V_2 -> V_118 ) ;
F_57 ( V_2 -> V_117 ) ;
}
return V_99 ;
}
static int F_69 ( struct V_141 * V_13 )
{
struct V_34 * V_30 = F_64 ( V_13 ) ;
struct V_1 * V_2 = F_15 ( V_30 ) ;
F_57 ( V_2 -> V_118 ) ;
F_57 ( V_2 -> V_117 ) ;
return 0 ;
}
static int F_70 ( struct V_141 * V_13 )
{
int V_99 ;
struct V_34 * V_30 = F_64 ( V_13 ) ;
struct V_1 * V_2 = F_15 ( V_30 ) ;
V_99 = F_48 ( V_2 -> V_117 ) ;
if ( V_99 )
return V_99 ;
V_99 = F_48 ( V_2 -> V_118 ) ;
if ( V_99 )
F_57 ( V_2 -> V_117 ) ;
return V_99 ;
}
