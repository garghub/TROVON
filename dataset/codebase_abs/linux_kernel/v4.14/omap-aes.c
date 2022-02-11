inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_1 ( V_2 , V_3 ) ;
V_7 &= ~ V_6 ;
V_7 |= V_5 ;
F_3 ( V_2 , V_3 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_5 , int V_8 )
{
for (; V_8 -- ; V_5 ++ , V_3 += 4 )
F_3 ( V_2 , V_3 , * V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_9 ;
if ( ! ( V_2 -> V_10 & V_11 ) ) {
V_2 -> V_10 |= V_11 ;
V_2 -> V_9 = 0 ;
}
V_9 = F_8 ( V_2 -> V_12 ) ;
if ( V_9 < 0 ) {
F_9 ( V_2 -> V_12 , L_1 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_10 &= ~ ( V_13 << V_14 ) ;
V_2 -> V_10 &= ~ ( V_13 << V_15 ) ;
V_2 -> V_10 &= ~ ( V_13 << V_16 ) ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
unsigned int V_19 ;
int V_20 , V_9 ;
T_1 V_7 ;
V_9 = F_7 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_19 = V_2 -> V_21 -> V_22 / sizeof( T_1 ) ;
if ( V_2 -> V_10 & V_23 )
for ( V_20 = 0 ; V_20 < 0x40 ; V_20 = V_20 + 4 )
F_3 ( V_2 , V_20 , 0x0 ) ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
F_3 ( V_2 , F_12 ( V_2 , V_20 ) ,
F_13 ( V_2 -> V_21 -> V_24 [ V_20 ] ) ) ;
}
if ( ( V_2 -> V_10 & ( V_25 | V_26 ) ) && V_2 -> V_27 -> V_28 )
F_6 ( V_2 , F_14 ( V_2 , 0 ) , V_2 -> V_27 -> V_28 , 4 ) ;
if ( ( V_2 -> V_10 & ( V_23 ) ) && V_2 -> V_29 -> V_30 ) {
V_18 = F_15 ( V_2 -> V_29 ) ;
F_6 ( V_2 , F_14 ( V_2 , 0 ) , ( T_1 * ) V_18 -> V_30 , 4 ) ;
}
V_7 = F_16 ( ( ( V_2 -> V_21 -> V_22 >> 3 ) - 1 ) , 4 , 3 ) ;
if ( V_2 -> V_10 & V_25 )
V_7 |= V_31 ;
if ( V_2 -> V_10 & ( V_26 | V_23 ) )
V_7 |= V_32 | V_33 ;
if ( V_2 -> V_10 & V_23 )
V_7 |= V_34 ;
if ( V_2 -> V_10 & V_35 )
V_7 |= V_36 ;
F_5 ( V_2 , F_17 ( V_2 ) , V_7 , V_37 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_38 )
{
T_1 V_6 , V_7 ;
V_7 = V_2 -> V_39 -> V_40 ;
if ( V_2 -> V_41 != NULL )
V_7 |= V_2 -> V_39 -> V_42 ;
if ( V_2 -> V_43 != NULL )
V_7 |= V_2 -> V_39 -> V_44 ;
V_6 = V_2 -> V_39 -> V_42 | V_2 -> V_39 -> V_44 |
V_2 -> V_39 -> V_40 ;
F_5 ( V_2 , F_19 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_38 )
{
F_3 ( V_2 , F_21 ( 0 ) , V_38 ) ;
F_3 ( V_2 , F_21 ( 1 ) , 0 ) ;
if ( V_2 -> V_10 & V_23 )
F_3 ( V_2 , V_45 , V_2 -> V_46 ) ;
F_18 ( V_2 , V_38 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_39 -> V_42 | V_2 -> V_39 -> V_44 |
V_2 -> V_39 -> V_40 ;
F_5 ( V_2 , F_19 ( V_2 ) , 0 , V_6 ) ;
}
struct V_1 * F_23 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
F_24 ( & V_47 ) ;
V_2 = F_25 ( & V_48 , struct V_1 , V_49 ) ;
F_26 ( & V_2 -> V_49 , & V_48 ) ;
V_18 -> V_2 = V_2 ;
F_27 ( & V_47 ) ;
return V_2 ;
}
static void F_28 ( void * V_50 )
{
struct V_1 * V_2 = V_50 ;
F_29 ( & V_2 -> V_51 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_9 ;
V_2 -> V_41 = NULL ;
V_2 -> V_43 = NULL ;
V_2 -> V_43 = F_31 ( V_2 -> V_12 , L_2 ) ;
if ( F_32 ( V_2 -> V_43 ) ) {
F_9 ( V_2 -> V_12 , L_3 ) ;
return F_33 ( V_2 -> V_43 ) ;
}
V_2 -> V_41 = F_31 ( V_2 -> V_12 , L_4 ) ;
if ( F_32 ( V_2 -> V_41 ) ) {
F_9 ( V_2 -> V_12 , L_5 ) ;
V_9 = F_33 ( V_2 -> V_41 ) ;
goto V_52;
}
return 0 ;
V_52:
F_34 ( V_2 -> V_43 ) ;
return V_9 ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 )
return;
F_34 ( V_2 -> V_41 ) ;
F_34 ( V_2 -> V_43 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_54 * V_56 ,
int V_57 , int V_58 )
{
struct V_59 * V_60 , * V_61 ;
struct V_62 V_63 ;
int V_64 ;
if ( V_2 -> V_53 ) {
F_37 ( & V_2 -> V_65 , V_2 -> V_55 ) ;
F_37 ( & V_2 -> V_66 , V_2 -> V_56 ) ;
F_3 ( V_2 , F_38 ( V_2 ) , 0x2 ) ;
return 0 ;
}
F_39 ( V_2 -> V_12 , V_2 -> V_55 , V_57 , V_67 ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_68 = V_2 -> V_69 + F_40 ( V_2 , 0 ) ;
V_63 . V_70 = V_2 -> V_69 + F_40 ( V_2 , 0 ) ;
V_63 . V_71 = V_72 ;
V_63 . V_73 = V_72 ;
V_63 . V_74 = V_75 ;
V_63 . V_76 = V_75 ;
V_64 = F_41 ( V_2 -> V_43 , & V_63 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_12 , L_6 ,
V_64 ) ;
return V_64 ;
}
V_60 = F_42 ( V_2 -> V_43 , V_55 , V_57 ,
V_77 ,
V_78 | V_79 ) ;
if ( ! V_60 ) {
F_9 ( V_2 -> V_12 , L_7 ) ;
return - V_80 ;
}
V_60 -> V_81 = V_2 ;
V_64 = F_41 ( V_2 -> V_41 , & V_63 ) ;
if ( V_64 ) {
F_9 ( V_2 -> V_12 , L_8 ,
V_64 ) ;
return V_64 ;
}
V_61 = F_42 ( V_2 -> V_41 , V_56 , V_58 ,
V_82 ,
V_78 | V_79 ) ;
if ( ! V_61 ) {
F_9 ( V_2 -> V_12 , L_9 ) ;
return - V_80 ;
}
if ( V_2 -> V_10 & V_23 )
V_61 -> V_83 = V_84 ;
else
V_61 -> V_83 = F_28 ;
V_61 -> V_81 = V_2 ;
F_43 ( V_60 ) ;
F_43 ( V_61 ) ;
F_44 ( V_2 -> V_43 ) ;
F_44 ( V_2 -> V_41 ) ;
V_2 -> V_39 -> V_85 ( V_2 , V_2 -> V_86 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_9 ;
F_46 ( L_10 , V_2 -> V_86 ) ;
if ( ! V_2 -> V_53 ) {
V_9 = F_47 ( V_2 -> V_12 , V_2 -> V_55 , V_2 -> V_57 ,
V_67 ) ;
if ( ! V_9 ) {
F_9 ( V_2 -> V_12 , L_11 ) ;
return - V_80 ;
}
V_9 = F_47 ( V_2 -> V_12 , V_2 -> V_56 , V_2 -> V_58 ,
V_87 ) ;
if ( ! V_9 ) {
F_9 ( V_2 -> V_12 , L_11 ) ;
return - V_80 ;
}
}
V_9 = F_36 ( V_2 , V_2 -> V_55 , V_2 -> V_56 , V_2 -> V_57 ,
V_2 -> V_58 ) ;
if ( V_9 && ! V_2 -> V_53 ) {
F_48 ( V_2 -> V_12 , V_2 -> V_55 , V_2 -> V_57 , V_67 ) ;
F_48 ( V_2 -> V_12 , V_2 -> V_56 , V_2 -> V_58 ,
V_87 ) ;
}
return V_9 ;
}
static void F_49 ( struct V_1 * V_2 , int V_9 )
{
struct V_88 * V_27 = V_2 -> V_27 ;
F_46 ( L_12 , V_9 ) ;
F_50 ( V_2 -> V_89 , V_27 , V_9 ) ;
F_51 ( V_2 -> V_12 ) ;
F_52 ( V_2 -> V_12 ) ;
}
int F_53 ( struct V_1 * V_2 )
{
F_46 ( L_10 , V_2 -> V_86 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_88 * V_27 )
{
if ( V_27 )
return F_55 ( V_2 -> V_89 , V_27 ) ;
return 0 ;
}
static int F_56 ( struct V_90 * V_89 ,
struct V_88 * V_27 )
{
struct V_91 * V_21 = F_57 (
F_58 ( V_27 ) ) ;
struct V_17 * V_18 = F_59 ( V_27 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_64 ;
T_2 V_10 ;
if ( ! V_2 )
return - V_92 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_86 = V_27 -> V_93 ;
V_2 -> V_94 = V_27 -> V_93 ;
V_2 -> V_55 = V_27 -> V_95 ;
V_2 -> V_56 = V_27 -> V_96 ;
V_2 -> V_97 = V_27 -> V_96 ;
V_10 = V_98 ;
if ( V_27 -> V_95 == V_27 -> V_96 )
V_10 |= V_99 ;
V_64 = F_60 ( & V_2 -> V_55 , V_2 -> V_86 , V_100 ,
V_2 -> V_101 , V_10 ,
V_14 , & V_2 -> V_10 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_60 ( & V_2 -> V_56 , V_2 -> V_86 , V_100 ,
& V_2 -> V_102 , 0 ,
V_15 , & V_2 -> V_10 ) ;
if ( V_64 )
return V_64 ;
V_2 -> V_57 = F_61 ( V_2 -> V_55 , V_2 -> V_86 ) ;
if ( V_2 -> V_57 < 0 )
return V_2 -> V_57 ;
V_2 -> V_58 = F_61 ( V_2 -> V_56 , V_2 -> V_86 ) ;
if ( V_2 -> V_58 < 0 )
return V_2 -> V_58 ;
V_18 -> V_103 &= V_104 ;
V_2 -> V_10 = ( V_2 -> V_10 & ~ V_104 ) | V_18 -> V_103 ;
V_2 -> V_21 = V_21 ;
V_18 -> V_2 = V_2 ;
return F_11 ( V_2 ) ;
}
static int F_62 ( struct V_90 * V_89 ,
struct V_88 * V_27 )
{
struct V_17 * V_18 = F_59 ( V_27 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
if ( ! V_2 )
return - V_92 ;
return F_45 ( V_2 ) ;
}
static void F_63 ( unsigned long V_50 )
{
struct V_1 * V_2 = (struct V_1 * ) V_50 ;
F_46 ( L_13 ) ;
if ( ! V_2 -> V_53 ) {
F_39 ( V_2 -> V_12 , V_2 -> V_56 , V_2 -> V_58 ,
V_87 ) ;
F_48 ( V_2 -> V_12 , V_2 -> V_55 , V_2 -> V_57 , V_67 ) ;
F_48 ( V_2 -> V_12 , V_2 -> V_56 , V_2 -> V_58 ,
V_87 ) ;
F_53 ( V_2 ) ;
}
F_64 ( V_2 -> V_101 , NULL , 0 , V_2 -> V_94 ,
V_14 , V_2 -> V_10 ) ;
F_64 ( & V_2 -> V_102 , V_2 -> V_97 , 0 , V_2 -> V_94 ,
V_15 , V_2 -> V_10 ) ;
F_49 ( V_2 , 0 ) ;
F_46 ( L_14 ) ;
}
static int F_65 ( struct V_88 * V_27 , unsigned long V_103 )
{
struct V_91 * V_21 = F_57 (
F_58 ( V_27 ) ) ;
struct V_17 * V_18 = F_59 ( V_27 ) ;
struct V_1 * V_2 ;
int V_64 ;
F_46 ( L_15 , V_27 -> V_93 ,
! ! ( V_103 & V_35 ) ,
! ! ( V_103 & V_25 ) ) ;
if ( V_27 -> V_93 < 200 ) {
F_66 ( V_105 , V_21 -> V_106 ) ;
F_67 ( V_105 , V_21 -> V_106 ) ;
F_68 ( V_105 , V_27 -> V_107 . V_10 , NULL ,
NULL ) ;
F_69 ( V_105 , V_27 -> V_95 , V_27 -> V_96 ,
V_27 -> V_93 , V_27 -> V_28 ) ;
if ( V_103 & V_35 )
V_64 = F_70 ( V_105 ) ;
else
V_64 = F_71 ( V_105 ) ;
F_72 ( V_105 ) ;
return V_64 ;
}
V_2 = F_23 ( V_18 ) ;
if ( ! V_2 )
return - V_92 ;
V_18 -> V_103 = V_103 ;
return F_54 ( V_2 , V_27 ) ;
}
static int F_73 ( struct V_108 * V_109 , const T_3 * V_24 ,
unsigned int V_22 )
{
struct V_91 * V_21 = F_57 ( V_109 ) ;
int V_64 ;
if ( V_22 != V_110 && V_22 != V_111 &&
V_22 != V_112 )
return - V_80 ;
F_46 ( L_16 , V_22 ) ;
memcpy ( V_21 -> V_24 , V_24 , V_22 ) ;
V_21 -> V_22 = V_22 ;
F_74 ( V_21 -> V_106 , V_113 ) ;
F_75 ( V_21 -> V_106 , V_109 -> V_107 . V_114 &
V_113 ) ;
V_64 = F_76 ( V_21 -> V_106 , V_24 , V_22 ) ;
if ( ! V_64 )
return 0 ;
return 0 ;
}
static int F_77 ( struct V_88 * V_27 )
{
return F_65 ( V_27 , V_35 ) ;
}
static int F_78 ( struct V_88 * V_27 )
{
return F_65 ( V_27 , 0 ) ;
}
static int F_79 ( struct V_88 * V_27 )
{
return F_65 ( V_27 , V_35 | V_25 ) ;
}
static int F_80 ( struct V_88 * V_27 )
{
return F_65 ( V_27 , V_25 ) ;
}
static int F_81 ( struct V_88 * V_27 )
{
return F_65 ( V_27 , V_35 | V_26 ) ;
}
static int F_82 ( struct V_88 * V_27 )
{
return F_65 ( V_27 , V_26 ) ;
}
static int F_83 ( struct V_115 * V_109 )
{
const char * V_116 = F_84 ( V_109 ) ;
const T_1 V_10 = V_117 | V_118 ;
struct V_91 * V_21 = F_85 ( V_109 ) ;
struct V_119 * V_120 ;
V_120 = F_86 ( V_116 , 0 , V_10 ) ;
if ( F_32 ( V_120 ) )
return F_33 ( V_120 ) ;
V_21 -> V_106 = V_120 ;
V_109 -> V_121 . V_122 = sizeof( struct V_17 ) ;
return 0 ;
}
static int F_87 ( struct V_123 * V_109 )
{
struct V_1 * V_2 = NULL ;
struct V_91 * V_21 = F_88 ( V_109 ) ;
int V_9 ;
F_24 ( & V_47 ) ;
F_89 (dd, &dev_list, list) {
break;
}
F_27 ( & V_47 ) ;
V_9 = F_8 ( V_2 -> V_12 ) ;
if ( V_9 < 0 ) {
F_9 ( V_2 -> V_12 , L_17 ,
V_124 , V_9 ) ;
return V_9 ;
}
V_109 -> V_122 = sizeof( struct V_17 ) ;
V_21 -> V_125 = F_86 ( L_18 , 0 , 0 ) ;
if ( F_32 ( V_21 -> V_125 ) ) {
F_90 ( L_19 ) ;
return F_33 ( V_21 -> V_125 ) ;
}
return 0 ;
}
static void F_91 ( struct V_115 * V_109 )
{
struct V_91 * V_21 = F_85 ( V_109 ) ;
if ( V_21 -> V_106 )
F_92 ( V_21 -> V_106 ) ;
V_21 -> V_106 = NULL ;
}
static void F_93 ( struct V_123 * V_109 )
{
struct V_91 * V_21 = F_88 ( V_109 ) ;
F_91 ( F_94 ( V_109 ) ) ;
if ( V_21 -> V_125 )
F_92 ( V_21 -> V_125 ) ;
}
static T_4 F_95 ( int V_126 , void * V_127 )
{
struct V_1 * V_2 = V_127 ;
T_1 V_128 , V_20 ;
T_1 * V_95 , * V_96 ;
V_128 = F_1 ( V_2 , F_96 ( V_2 ) ) ;
if ( V_128 & V_129 ) {
F_3 ( V_2 , F_38 ( V_2 ) , 0x0 ) ;
F_97 ( ! V_2 -> V_55 ) ;
F_97 ( F_98 ( V_130 ) > V_2 -> V_55 -> V_38 ) ;
V_95 = F_99 ( V_2 -> V_55 ) + F_98 ( V_130 ) ;
for ( V_20 = 0 ; V_20 < V_131 ; V_20 ++ ) {
F_3 ( V_2 , F_40 ( V_2 , V_20 ) , * V_95 ) ;
F_100 ( & V_2 -> V_65 , 4 ) ;
if ( V_2 -> V_55 -> V_38 == F_98 ( V_130 ) ) {
V_2 -> V_55 = F_101 ( V_2 -> V_55 ) ;
if ( V_2 -> V_55 ) {
F_37 ( & V_2 -> V_65 ,
V_2 -> V_55 ) ;
V_95 = F_99 ( V_2 -> V_55 ) +
F_98 ( V_130 ) ;
}
} else {
V_95 ++ ;
}
}
V_128 &= ~ V_129 ;
F_3 ( V_2 , F_96 ( V_2 ) , V_128 ) ;
F_3 ( V_2 , F_38 ( V_2 ) , 0x4 ) ;
} else if ( V_128 & V_132 ) {
F_3 ( V_2 , F_38 ( V_2 ) , 0x0 ) ;
F_97 ( ! V_2 -> V_56 ) ;
F_97 ( F_98 ( V_133 ) > V_2 -> V_56 -> V_38 ) ;
V_96 = F_99 ( V_2 -> V_56 ) + F_98 ( V_133 ) ;
for ( V_20 = 0 ; V_20 < V_131 ; V_20 ++ ) {
* V_96 = F_1 ( V_2 , F_40 ( V_2 , V_20 ) ) ;
F_100 ( & V_2 -> V_66 , 4 ) ;
if ( V_2 -> V_56 -> V_38 == F_98 ( V_133 ) ) {
V_2 -> V_56 = F_101 ( V_2 -> V_56 ) ;
if ( V_2 -> V_56 ) {
F_37 ( & V_2 -> V_66 ,
V_2 -> V_56 ) ;
V_96 = F_99 ( V_2 -> V_56 ) +
F_98 ( V_133 ) ;
}
} else {
V_96 ++ ;
}
}
V_2 -> V_86 -= F_102 ( V_134 , V_100 , V_2 -> V_86 ) ;
V_128 &= ~ V_132 ;
F_3 ( V_2 , F_96 ( V_2 ) , V_128 ) ;
if ( ! V_2 -> V_86 )
F_29 ( & V_2 -> V_51 ) ;
else
F_3 ( V_2 , F_38 ( V_2 ) , 0x2 ) ;
}
return V_135 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_136 * V_12 , struct V_137 * V_138 )
{
struct V_139 * V_140 = V_12 -> V_141 ;
const struct V_142 * V_143 ;
int V_9 = 0 ;
V_143 = F_104 ( F_105 ( V_144 ) , V_12 ) ;
if ( ! V_143 ) {
F_9 ( V_12 , L_20 ) ;
V_9 = - V_80 ;
goto V_9;
}
V_9 = F_106 ( V_140 , 0 , V_138 ) ;
if ( V_9 < 0 ) {
F_9 ( V_12 , L_21 ) ;
V_9 = - V_80 ;
goto V_9;
}
V_2 -> V_39 = V_143 -> V_50 ;
V_9:
return V_9 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_136 * V_12 , struct V_137 * V_138 )
{
return - V_80 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_145 * V_146 , struct V_137 * V_138 )
{
struct V_136 * V_12 = & V_146 -> V_12 ;
struct V_137 * V_147 ;
int V_9 = 0 ;
V_147 = F_108 ( V_146 , V_148 , 0 ) ;
if ( ! V_147 ) {
F_9 ( V_12 , L_22 ) ;
V_9 = - V_92 ;
goto V_9;
}
memcpy ( V_138 , V_147 , sizeof( * V_138 ) ) ;
V_2 -> V_39 = & V_149 ;
V_9:
return V_9 ;
}
static int F_109 ( struct V_145 * V_146 )
{
struct V_136 * V_12 = & V_146 -> V_12 ;
struct V_1 * V_2 ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
struct V_137 V_138 ;
int V_9 = - V_154 , V_20 , V_155 , V_126 = - 1 ;
T_1 V_156 ;
V_2 = F_110 ( V_12 , sizeof( struct V_1 ) , V_157 ) ;
if ( V_2 == NULL ) {
F_9 ( V_12 , L_23 ) ;
goto V_158;
}
V_2 -> V_12 = V_12 ;
F_111 ( V_146 , V_2 ) ;
F_112 ( & V_2 -> V_159 , V_160 ) ;
V_9 = ( V_12 -> V_141 ) ? F_103 ( V_2 , V_12 , & V_138 ) :
F_107 ( V_2 , V_146 , & V_138 ) ;
if ( V_9 )
goto V_161;
V_2 -> V_4 = F_113 ( V_12 , & V_138 ) ;
if ( F_32 ( V_2 -> V_4 ) ) {
V_9 = F_33 ( V_2 -> V_4 ) ;
goto V_161;
}
V_2 -> V_69 = V_138 . V_162 ;
F_114 ( V_12 ) ;
F_115 ( V_12 , V_163 ) ;
F_116 ( V_12 ) ;
V_9 = F_8 ( V_12 ) ;
if ( V_9 < 0 ) {
F_9 ( V_12 , L_17 ,
V_124 , V_9 ) ;
goto V_161;
}
F_22 ( V_2 ) ;
V_156 = F_1 ( V_2 , F_117 ( V_2 ) ) ;
F_118 ( V_12 ) ;
F_119 ( V_12 , L_24 ,
( V_156 & V_2 -> V_39 -> V_164 ) >> V_2 -> V_39 -> V_165 ,
( V_156 & V_2 -> V_39 -> V_166 ) >> V_2 -> V_39 -> V_167 ) ;
F_120 ( & V_2 -> V_51 , F_63 , ( unsigned long ) V_2 ) ;
V_9 = F_30 ( V_2 ) ;
if ( V_9 == - V_168 ) {
goto V_169;
} else if ( V_9 && F_96 ( V_2 ) && F_38 ( V_2 ) ) {
V_2 -> V_53 = 1 ;
V_126 = F_121 ( V_146 , 0 ) ;
if ( V_126 < 0 ) {
F_9 ( V_12 , L_25 ) ;
V_9 = V_126 ;
goto V_169;
}
V_9 = F_122 ( V_12 , V_126 , F_95 , 0 ,
F_123 ( V_12 ) , V_2 ) ;
if ( V_9 ) {
F_9 ( V_12 , L_26 ) ;
goto V_169;
}
}
F_124 ( & V_2 -> V_170 ) ;
F_125 ( & V_2 -> V_49 ) ;
F_126 ( & V_47 ) ;
F_127 ( & V_2 -> V_49 , & V_48 ) ;
F_128 ( & V_47 ) ;
V_2 -> V_89 = F_129 ( V_12 , 1 ) ;
if ( ! V_2 -> V_89 ) {
V_9 = - V_154 ;
goto V_171;
}
V_2 -> V_89 -> V_172 = F_56 ;
V_2 -> V_89 -> V_173 = F_62 ;
V_9 = F_130 ( V_2 -> V_89 ) ;
if ( V_9 )
goto V_171;
for ( V_20 = 0 ; V_20 < V_2 -> V_39 -> V_174 ; V_20 ++ ) {
if ( ! V_2 -> V_39 -> V_175 [ V_20 ] . V_176 ) {
for ( V_155 = 0 ; V_155 < V_2 -> V_39 -> V_175 [ V_20 ] . V_177 ; V_155 ++ ) {
V_151 = & V_2 -> V_39 -> V_175 [ V_20 ] . V_178 [ V_155 ] ;
F_46 ( L_27 , V_151 -> V_179 ) ;
F_125 ( & V_151 -> V_180 ) ;
V_9 = F_131 ( V_151 ) ;
if ( V_9 )
goto V_181;
V_2 -> V_39 -> V_175 [ V_20 ] . V_176 ++ ;
}
}
}
if ( V_2 -> V_39 -> V_182 &&
! V_2 -> V_39 -> V_182 -> V_176 ) {
for ( V_20 = 0 ; V_20 < V_2 -> V_39 -> V_182 -> V_177 ; V_20 ++ ) {
V_153 = & V_2 -> V_39 -> V_182 -> V_178 [ V_20 ] ;
V_151 = & V_153 -> V_107 ;
F_46 ( L_27 , V_151 -> V_179 ) ;
F_125 ( & V_151 -> V_180 ) ;
V_9 = F_132 ( V_153 ) ;
if ( V_9 )
goto V_183;
V_2 -> V_39 -> V_182 -> V_176 ++ ;
}
}
return 0 ;
V_183:
for ( V_20 = V_2 -> V_39 -> V_182 -> V_176 - 1 ; V_20 >= 0 ; V_20 -- ) {
V_153 = & V_2 -> V_39 -> V_182 -> V_178 [ V_20 ] ;
F_133 ( V_153 ) ;
}
V_181:
for ( V_20 = V_2 -> V_39 -> V_174 - 1 ; V_20 >= 0 ; V_20 -- )
for ( V_155 = V_2 -> V_39 -> V_175 [ V_20 ] . V_176 - 1 ; V_155 >= 0 ; V_155 -- )
F_134 (
& V_2 -> V_39 -> V_175 [ V_20 ] . V_178 [ V_155 ] ) ;
V_171:
if ( V_2 -> V_89 )
F_135 ( V_2 -> V_89 ) ;
F_35 ( V_2 ) ;
V_169:
F_136 ( & V_2 -> V_51 ) ;
F_137 ( V_12 ) ;
V_161:
V_2 = NULL ;
V_158:
F_9 ( V_12 , L_28 ) ;
return V_9 ;
}
static int F_138 ( struct V_145 * V_146 )
{
struct V_1 * V_2 = F_139 ( V_146 ) ;
struct V_152 * V_153 ;
int V_20 , V_155 ;
if ( ! V_2 )
return - V_92 ;
F_126 ( & V_47 ) ;
F_140 ( & V_2 -> V_49 ) ;
F_128 ( & V_47 ) ;
for ( V_20 = V_2 -> V_39 -> V_174 - 1 ; V_20 >= 0 ; V_20 -- )
for ( V_155 = V_2 -> V_39 -> V_175 [ V_20 ] . V_176 - 1 ; V_155 >= 0 ; V_155 -- )
F_134 (
& V_2 -> V_39 -> V_175 [ V_20 ] . V_178 [ V_155 ] ) ;
for ( V_20 = V_2 -> V_39 -> V_182 -> V_177 - 1 ; V_20 >= 0 ; V_20 -- ) {
V_153 = & V_2 -> V_39 -> V_182 -> V_178 [ V_20 ] ;
F_133 ( V_153 ) ;
}
F_135 ( V_2 -> V_89 ) ;
F_136 ( & V_2 -> V_51 ) ;
F_35 ( V_2 ) ;
F_137 ( V_2 -> V_12 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_141 ( struct V_136 * V_12 )
{
F_118 ( V_12 ) ;
return 0 ;
}
static int F_142 ( struct V_136 * V_12 )
{
F_8 ( V_12 ) ;
return 0 ;
}
