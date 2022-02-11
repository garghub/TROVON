static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
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
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
unsigned long V_10 = V_11 + V_12 ;
while ( ! ( F_1 ( V_2 , V_3 ) & V_9 ) ) {
if ( F_8 ( V_10 ) ) {
F_9 ( V_2 -> V_13 , L_1 ) ;
return - V_14 ;
}
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_15 ) ;
if ( ! ( V_2 -> V_16 & V_17 ) ) {
F_5 ( V_2 , V_18 , V_19 ,
V_19 ) ;
__asm__ __volatile__("nop");
__asm__ __volatile__("nop");
if ( F_7 ( V_2 , V_20 ,
V_21 ) )
return - V_14 ;
V_2 -> V_16 |= V_17 ;
V_2 -> V_22 = 0 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
int V_24 , V_22 ;
T_1 V_7 , V_6 ;
V_22 = F_10 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_7 = 0 ;
if ( V_2 -> V_25 >= 0 )
V_7 |= V_26 ;
if ( V_2 -> V_27 >= 0 )
V_7 |= V_28 ;
V_6 = V_28 | V_26 ;
F_5 ( V_2 , V_18 , V_7 , V_6 ) ;
V_23 = V_2 -> V_29 -> V_30 / sizeof( T_1 ) ;
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
F_3 ( V_2 , F_13 ( V_24 ) ,
F_14 ( V_2 -> V_29 -> V_31 [ V_24 ] ) ) ;
}
if ( ( V_2 -> V_16 & V_32 ) && V_2 -> V_33 -> V_34 )
F_6 ( V_2 , F_15 ( 0 ) , V_2 -> V_33 -> V_34 , 4 ) ;
V_7 = F_16 ( ( ( V_2 -> V_29 -> V_30 >> 3 ) - 1 ) , 4 , 3 ) ;
if ( V_2 -> V_16 & V_32 )
V_7 |= V_35 ;
if ( V_2 -> V_16 & V_36 )
V_7 |= V_37 ;
V_6 = V_35 | V_37 |
V_38 ;
F_5 ( V_2 , V_39 , V_7 , V_6 ) ;
F_17 ( V_2 -> V_27 , 0 , V_40 ,
V_2 -> V_41 + V_42 , 0 , 4 ) ;
F_18 ( V_2 -> V_27 , V_43 ) ;
F_19 ( V_2 -> V_27 , V_43 ) ;
F_20 ( V_2 -> V_25 , 0 , V_40 ,
V_2 -> V_41 + V_42 , 0 , 4 ) ;
F_19 ( V_2 -> V_25 , V_43 ) ;
F_18 ( V_2 -> V_25 , V_43 ) ;
return 0 ;
}
static struct V_1 * F_21 ( struct V_44 * V_29 )
{
struct V_1 * V_2 = NULL , * V_45 ;
F_22 ( & V_46 ) ;
if ( ! V_29 -> V_2 ) {
F_23 (tmp, &dev_list, list) {
V_2 = V_45 ;
break;
}
V_29 -> V_2 = V_2 ;
} else {
V_2 = V_29 -> V_2 ;
}
F_24 ( & V_46 ) ;
return V_2 ;
}
static void F_25 ( int V_47 , T_2 V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
if ( V_48 != V_50 ) {
F_26 ( L_2 , V_48 ) ;
V_2 -> V_22 = - V_51 ;
V_2 -> V_16 &= ~ V_17 ;
} else if ( V_47 == V_2 -> V_27 ) {
return;
}
F_27 ( & V_2 -> V_52 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_22 = - V_53 ;
V_2 -> V_25 = - 1 ;
V_2 -> V_27 = - 1 ;
V_2 -> V_54 = ( void * ) F_29 ( V_55 , V_56 ) ;
V_2 -> V_57 = ( void * ) F_29 ( V_55 , V_56 ) ;
V_2 -> V_58 = V_59 << V_56 ;
V_2 -> V_58 &= ~ ( V_60 - 1 ) ;
if ( ! V_2 -> V_54 || ! V_2 -> V_57 ) {
F_9 ( V_2 -> V_13 , L_3 ) ;
goto V_61;
}
V_2 -> V_62 = F_30 ( V_2 -> V_13 , V_2 -> V_54 , V_2 -> V_58 ,
V_63 ) ;
if ( F_31 ( V_2 -> V_13 , V_2 -> V_62 ) ) {
F_9 ( V_2 -> V_13 , L_4 , V_2 -> V_58 ) ;
V_22 = - V_64 ;
goto V_65;
}
V_2 -> V_66 = F_30 ( V_2 -> V_13 , V_2 -> V_57 , V_2 -> V_58 ,
V_67 ) ;
if ( F_31 ( V_2 -> V_13 , V_2 -> V_66 ) ) {
F_9 ( V_2 -> V_13 , L_4 , V_2 -> V_58 ) ;
V_22 = - V_64 ;
goto V_68;
}
V_22 = F_32 ( V_2 -> V_69 , L_5 ,
F_25 , V_2 , & V_2 -> V_27 ) ;
if ( V_22 ) {
F_9 ( V_2 -> V_13 , L_6 ) ;
goto V_70;
}
V_22 = F_32 ( V_2 -> V_71 , L_7 ,
F_25 , V_2 , & V_2 -> V_25 ) ;
if ( V_22 ) {
F_9 ( V_2 -> V_13 , L_6 ) ;
goto V_72;
}
return 0 ;
V_72:
F_33 ( V_2 -> V_27 ) ;
V_70:
F_34 ( V_2 -> V_13 , V_2 -> V_66 , V_2 -> V_58 ,
V_67 ) ;
V_68:
F_34 ( V_2 -> V_13 , V_2 -> V_62 , V_2 -> V_58 , V_63 ) ;
V_65:
F_35 ( ( unsigned long ) V_2 -> V_57 , V_56 ) ;
F_35 ( ( unsigned long ) V_2 -> V_54 , V_56 ) ;
V_61:
if ( V_22 )
F_26 ( L_8 , V_22 ) ;
return V_22 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_25 ) ;
F_33 ( V_2 -> V_27 ) ;
F_34 ( V_2 -> V_13 , V_2 -> V_66 , V_2 -> V_58 ,
V_67 ) ;
F_34 ( V_2 -> V_13 , V_2 -> V_62 , V_2 -> V_58 , V_63 ) ;
F_35 ( ( unsigned long ) V_2 -> V_57 , V_56 ) ;
F_35 ( ( unsigned long ) V_2 -> V_54 , V_56 ) ;
}
static void F_37 ( void * V_73 , struct V_74 * V_75 ,
unsigned int V_76 , unsigned int V_77 , int V_78 )
{
struct V_79 V_80 ;
if ( ! V_77 )
return;
F_38 ( & V_80 , V_75 ) ;
F_39 ( & V_80 , V_76 ) ;
F_40 ( V_73 , & V_80 , V_77 , V_78 ) ;
F_41 ( & V_80 , V_78 , 0 ) ;
}
static int F_42 ( struct V_74 * * V_75 , T_3 * V_3 , void * V_73 ,
T_3 V_58 , T_3 V_81 , int V_78 )
{
unsigned int V_8 , V_82 = 0 ;
while ( V_58 && V_81 ) {
V_8 = F_43 ( ( * V_75 ) -> V_83 - * V_3 , V_81 ) ;
V_8 = F_43 ( V_8 , V_58 ) ;
if ( ! V_8 )
return V_82 ;
F_37 ( V_73 + V_82 , * V_75 , * V_3 , V_8 , V_78 ) ;
V_82 += V_8 ;
V_58 -= V_8 ;
* V_3 += V_8 ;
V_81 -= V_8 ;
if ( * V_3 == ( * V_75 ) -> V_83 ) {
* V_75 = F_44 ( * V_75 ) ;
if ( * V_75 )
* V_3 = 0 ;
else
V_81 = 0 ;
}
}
return V_82 ;
}
static int F_45 ( struct V_84 * V_85 , T_4 V_62 ,
T_4 V_66 , int V_83 )
{
struct V_44 * V_29 = F_46 ( V_85 ) ;
struct V_1 * V_2 = V_29 -> V_2 ;
int V_86 ;
F_47 ( L_9 , V_83 ) ;
V_2 -> V_87 = V_83 ;
if ( ! ( V_2 -> V_16 & V_88 ) )
F_48 ( V_2 -> V_13 , V_62 , V_83 ,
V_63 ) ;
V_86 = F_49 ( V_83 , sizeof( T_1 ) ) ;
F_50 ( V_2 -> V_27 , V_89 ,
V_86 , 1 , V_90 , V_2 -> V_69 ,
V_91 ) ;
F_20 ( V_2 -> V_27 , 0 , V_92 ,
V_62 , 0 , 0 ) ;
F_50 ( V_2 -> V_25 , V_89 ,
V_86 , 1 , V_90 ,
V_2 -> V_71 , V_93 ) ;
F_17 ( V_2 -> V_25 , 0 , V_92 ,
V_66 , 0 , 0 ) ;
F_51 ( V_2 -> V_27 ) ;
F_51 ( V_2 -> V_25 ) ;
F_5 ( V_2 , V_18 , V_94 ,
V_94 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = F_53 (
F_54 ( V_2 -> V_33 ) ) ;
int V_22 , V_95 = 0 , V_96 , V_78 ;
T_3 V_8 ;
T_4 V_97 , V_98 ;
F_47 ( L_10 , V_2 -> V_81 ) ;
if ( F_55 ( V_2 -> V_99 ) && F_55 ( V_2 -> V_100 ) ) {
V_96 = F_56 ( ( T_1 ) V_2 -> V_99 -> V_3 , sizeof( T_1 ) ) ;
V_78 = F_56 ( ( T_1 ) V_2 -> V_100 -> V_3 , sizeof( T_1 ) ) ;
V_95 = V_96 && V_78 ;
}
if ( V_95 ) {
V_8 = F_43 ( V_2 -> V_81 , F_57 ( V_2 -> V_99 ) ) ;
V_8 = F_43 ( V_8 , F_57 ( V_2 -> V_100 ) ) ;
if ( V_8 != V_2 -> V_81 ) {
F_26 ( L_11 ) ;
return - V_64 ;
}
F_47 ( L_12 ) ;
V_22 = F_58 ( V_2 -> V_13 , V_2 -> V_99 , 1 , V_63 ) ;
if ( ! V_22 ) {
F_9 ( V_2 -> V_13 , L_13 ) ;
return - V_64 ;
}
V_22 = F_58 ( V_2 -> V_13 , V_2 -> V_100 , 1 , V_67 ) ;
if ( ! V_22 ) {
F_9 ( V_2 -> V_13 , L_13 ) ;
F_59 ( V_2 -> V_13 , V_2 -> V_99 , 1 , V_63 ) ;
return - V_64 ;
}
V_97 = F_60 ( V_2 -> V_99 ) ;
V_98 = F_60 ( V_2 -> V_100 ) ;
V_2 -> V_16 |= V_88 ;
} else {
V_8 = F_42 ( & V_2 -> V_99 , & V_2 -> V_101 , V_2 -> V_54 ,
V_2 -> V_58 , V_2 -> V_81 , 0 ) ;
V_97 = V_2 -> V_62 ;
V_98 = V_2 -> V_66 ;
V_2 -> V_16 &= ~ V_88 ;
}
V_2 -> V_81 -= V_8 ;
V_22 = F_45 ( V_85 , V_97 , V_98 , V_8 ) ;
if ( V_22 ) {
F_59 ( V_2 -> V_13 , V_2 -> V_99 , 1 , V_63 ) ;
F_59 ( V_2 -> V_13 , V_2 -> V_100 , 1 , V_63 ) ;
}
return V_22 ;
}
static void F_61 ( struct V_1 * V_2 , int V_22 )
{
struct V_102 * V_33 = V_2 -> V_33 ;
F_47 ( L_14 , V_22 ) ;
F_62 ( V_2 -> V_15 ) ;
V_2 -> V_16 &= ~ V_103 ;
V_33 -> V_104 . V_105 ( & V_33 -> V_104 , V_22 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_22 = 0 ;
T_3 V_8 ;
F_47 ( L_10 , V_2 -> V_81 ) ;
F_5 ( V_2 , V_18 , 0 , V_94 ) ;
F_64 ( V_2 -> V_27 ) ;
F_64 ( V_2 -> V_25 ) ;
if ( V_2 -> V_16 & V_88 ) {
F_59 ( V_2 -> V_13 , V_2 -> V_100 , 1 , V_67 ) ;
F_59 ( V_2 -> V_13 , V_2 -> V_99 , 1 , V_63 ) ;
} else {
F_48 ( V_2 -> V_13 , V_2 -> V_66 ,
V_2 -> V_87 , V_67 ) ;
V_8 = F_42 ( & V_2 -> V_100 , & V_2 -> V_106 , V_2 -> V_57 ,
V_2 -> V_58 , V_2 -> V_87 , 1 ) ;
if ( V_8 != V_2 -> V_87 ) {
V_22 = - V_64 ;
F_26 ( L_15 , V_8 ) ;
}
}
return V_22 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_102 * V_33 )
{
struct V_107 * V_108 , * V_109 ;
struct V_44 * V_29 ;
struct V_110 * V_111 ;
unsigned long V_16 ;
int V_22 , V_112 = 0 ;
F_66 ( & V_2 -> V_113 , V_16 ) ;
if ( V_33 )
V_112 = F_67 ( & V_2 -> V_114 , V_33 ) ;
if ( V_2 -> V_16 & V_103 ) {
F_68 ( & V_2 -> V_113 , V_16 ) ;
return V_112 ;
}
V_109 = F_69 ( & V_2 -> V_114 ) ;
V_108 = F_70 ( & V_2 -> V_114 ) ;
if ( V_108 )
V_2 -> V_16 |= V_103 ;
F_68 ( & V_2 -> V_113 , V_16 ) ;
if ( ! V_108 )
return V_112 ;
if ( V_109 )
V_109 -> V_105 ( V_109 , - V_115 ) ;
V_33 = F_71 ( V_108 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_81 = V_33 -> V_77 ;
V_2 -> V_101 = 0 ;
V_2 -> V_99 = V_33 -> V_116 ;
V_2 -> V_106 = 0 ;
V_2 -> V_100 = V_33 -> V_117 ;
V_111 = F_72 ( V_33 ) ;
V_29 = F_73 ( F_54 ( V_33 ) ) ;
V_111 -> V_118 &= V_119 ;
V_2 -> V_16 = ( V_2 -> V_16 & ~ V_119 ) | V_111 -> V_118 ;
V_2 -> V_29 = V_29 ;
V_29 -> V_2 = V_2 ;
V_22 = F_12 ( V_2 ) ;
if ( ! V_22 )
V_22 = F_52 ( V_2 ) ;
if ( V_22 ) {
F_61 ( V_2 , V_22 ) ;
F_27 ( & V_2 -> V_120 ) ;
}
return V_112 ;
}
static void F_74 ( unsigned long V_49 )
{
struct V_1 * V_2 = (struct V_1 * ) V_49 ;
int V_22 ;
F_47 ( L_16 ) ;
V_22 = F_63 ( V_2 ) ;
V_22 = V_2 -> V_22 ? : V_22 ;
if ( V_2 -> V_81 && ! V_22 ) {
V_22 = F_52 ( V_2 ) ;
if ( ! V_22 )
return;
}
F_61 ( V_2 , V_22 ) ;
F_65 ( V_2 , NULL ) ;
F_47 ( L_17 ) ;
}
static void F_75 ( unsigned long V_49 )
{
struct V_1 * V_2 = (struct V_1 * ) V_49 ;
F_65 ( V_2 , NULL ) ;
}
static int F_76 ( struct V_102 * V_33 , unsigned long V_118 )
{
struct V_44 * V_29 = F_73 (
F_54 ( V_33 ) ) ;
struct V_110 * V_111 = F_72 ( V_33 ) ;
struct V_1 * V_2 ;
F_47 ( L_18 , V_33 -> V_77 ,
! ! ( V_118 & V_36 ) ,
! ! ( V_118 & V_32 ) ) ;
if ( ! F_56 ( V_33 -> V_77 , V_60 ) ) {
F_26 ( L_19 ) ;
return - V_64 ;
}
V_2 = F_21 ( V_29 ) ;
if ( ! V_2 )
return - V_121 ;
V_111 -> V_118 = V_118 ;
return F_65 ( V_2 , V_33 ) ;
}
static int F_77 ( struct V_122 * V_85 , const T_5 * V_31 ,
unsigned int V_30 )
{
struct V_44 * V_29 = F_73 ( V_85 ) ;
if ( V_30 != V_123 && V_30 != V_124 &&
V_30 != V_125 )
return - V_64 ;
F_47 ( L_20 , V_30 ) ;
memcpy ( V_29 -> V_31 , V_31 , V_30 ) ;
V_29 -> V_30 = V_30 ;
return 0 ;
}
static int F_78 ( struct V_102 * V_33 )
{
return F_76 ( V_33 , V_36 ) ;
}
static int F_79 ( struct V_102 * V_33 )
{
return F_76 ( V_33 , 0 ) ;
}
static int F_80 ( struct V_102 * V_33 )
{
return F_76 ( V_33 , V_36 | V_32 ) ;
}
static int F_81 ( struct V_102 * V_33 )
{
return F_76 ( V_33 , V_32 ) ;
}
static int F_82 ( struct V_84 * V_85 )
{
F_47 ( L_16 ) ;
V_85 -> V_126 . V_127 = sizeof( struct V_110 ) ;
return 0 ;
}
static void F_83 ( struct V_84 * V_85 )
{
F_47 ( L_16 ) ;
}
static int F_84 ( struct V_128 * V_129 )
{
struct V_130 * V_13 = & V_129 -> V_13 ;
struct V_1 * V_2 ;
struct V_131 * V_132 ;
int V_22 = - V_53 , V_24 , V_133 ;
T_1 V_134 ;
V_2 = F_85 ( sizeof( struct V_1 ) , V_55 ) ;
if ( V_2 == NULL ) {
F_9 ( V_13 , L_21 ) ;
goto V_135;
}
V_2 -> V_13 = V_13 ;
F_86 ( V_129 , V_2 ) ;
F_87 ( & V_2 -> V_113 ) ;
F_88 ( & V_2 -> V_114 , V_136 ) ;
V_132 = F_89 ( V_129 , V_137 , 0 ) ;
if ( ! V_132 ) {
F_9 ( V_13 , L_22 ) ;
V_22 = - V_121 ;
goto V_138;
}
V_2 -> V_41 = V_132 -> V_76 ;
V_132 = F_89 ( V_129 , V_139 , 0 ) ;
if ( ! V_132 )
F_90 ( V_13 , L_23 ) ;
else
V_2 -> V_71 = V_132 -> V_76 ;
V_132 = F_89 ( V_129 , V_139 , 1 ) ;
if ( ! V_132 )
F_90 ( V_13 , L_23 ) ;
else
V_2 -> V_69 = V_132 -> V_76 ;
V_2 -> V_15 = F_91 ( V_13 , L_24 ) ;
if ( F_92 ( V_2 -> V_15 ) ) {
F_9 ( V_13 , L_25 ) ;
V_22 = F_93 ( V_2 -> V_15 ) ;
goto V_138;
}
V_2 -> V_4 = F_94 ( V_2 -> V_41 , V_140 ) ;
if ( ! V_2 -> V_4 ) {
F_9 ( V_13 , L_26 ) ;
V_22 = - V_53 ;
goto V_141;
}
F_11 ( V_2 -> V_15 ) ;
V_134 = F_1 ( V_2 , V_142 ) ;
F_90 ( V_13 , L_27 ,
( V_134 & V_143 ) >> 4 , V_134 & V_144 ) ;
F_62 ( V_2 -> V_15 ) ;
F_95 ( & V_2 -> V_52 , F_74 , ( unsigned long ) V_2 ) ;
F_95 ( & V_2 -> V_120 , F_75 , ( unsigned long ) V_2 ) ;
V_22 = F_28 ( V_2 ) ;
if ( V_22 )
goto V_145;
F_96 ( & V_2 -> V_146 ) ;
F_97 ( & V_46 ) ;
F_98 ( & V_2 -> V_146 , & V_147 ) ;
F_99 ( & V_46 ) ;
for ( V_24 = 0 ; V_24 < F_100 ( V_148 ) ; V_24 ++ ) {
F_47 ( L_28 , V_24 ) ;
V_22 = F_101 ( & V_148 [ V_24 ] ) ;
if ( V_22 )
goto V_149;
}
F_102 ( L_29 ) ;
return 0 ;
V_149:
for ( V_133 = 0 ; V_133 < V_24 ; V_133 ++ )
F_103 ( & V_148 [ V_133 ] ) ;
F_36 ( V_2 ) ;
V_145:
F_104 ( & V_2 -> V_52 ) ;
F_104 ( & V_2 -> V_120 ) ;
F_105 ( V_2 -> V_4 ) ;
V_141:
F_106 ( V_2 -> V_15 ) ;
V_138:
F_107 ( V_2 ) ;
V_2 = NULL ;
V_135:
F_9 ( V_13 , L_30 ) ;
return V_22 ;
}
static int F_108 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_109 ( V_129 ) ;
int V_24 ;
if ( ! V_2 )
return - V_121 ;
F_97 ( & V_46 ) ;
F_110 ( & V_2 -> V_146 ) ;
F_99 ( & V_46 ) ;
for ( V_24 = 0 ; V_24 < F_100 ( V_148 ) ; V_24 ++ )
F_103 ( & V_148 [ V_24 ] ) ;
F_104 ( & V_2 -> V_52 ) ;
F_104 ( & V_2 -> V_120 ) ;
F_36 ( V_2 ) ;
F_105 ( V_2 -> V_4 ) ;
F_106 ( V_2 -> V_15 ) ;
F_107 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
static int T_6 F_111 ( void )
{
F_102 ( L_31 , L_32 ) ;
return F_112 ( & V_150 ) ;
}
static void T_7 F_113 ( void )
{
F_114 ( & V_150 ) ;
}
