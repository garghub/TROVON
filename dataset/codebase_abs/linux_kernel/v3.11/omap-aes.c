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
static int F_7 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_9 & V_10 ) ) {
V_2 -> V_9 |= V_10 ;
V_2 -> V_11 = 0 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
int V_13 , V_11 ;
T_1 V_7 , V_6 = 0 ;
V_11 = F_7 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_12 = V_2 -> V_14 -> V_15 / sizeof( T_1 ) ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
F_3 ( V_2 , F_9 ( V_2 , V_13 ) ,
F_10 ( V_2 -> V_14 -> V_16 [ V_13 ] ) ) ;
}
if ( ( V_2 -> V_9 & ( V_17 | V_18 ) ) && V_2 -> V_19 -> V_20 )
F_6 ( V_2 , F_11 ( V_2 , 0 ) , V_2 -> V_19 -> V_20 , 4 ) ;
V_7 = F_12 ( ( ( V_2 -> V_14 -> V_15 >> 3 ) - 1 ) , 4 , 3 ) ;
if ( V_2 -> V_9 & V_17 )
V_7 |= V_21 ;
if ( V_2 -> V_9 & V_18 ) {
V_7 |= V_22 | V_23 ;
V_6 = V_22 | V_24 ;
}
if ( V_2 -> V_9 & V_25 )
V_7 |= V_26 ;
V_6 |= V_21 | V_26 |
V_27 ;
F_5 ( V_2 , F_13 ( V_2 ) , V_7 , V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_28 )
{
T_1 V_6 , V_7 ;
V_7 = V_2 -> V_29 -> V_30 ;
if ( V_2 -> V_31 != NULL )
V_7 |= V_2 -> V_29 -> V_32 ;
if ( V_2 -> V_33 != NULL )
V_7 |= V_2 -> V_29 -> V_34 ;
V_6 = V_2 -> V_29 -> V_32 | V_2 -> V_29 -> V_34 |
V_2 -> V_29 -> V_30 ;
F_5 ( V_2 , F_15 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_28 )
{
F_3 ( V_2 , F_17 ( 0 ) , V_28 ) ;
F_3 ( V_2 , F_17 ( 1 ) , 0 ) ;
F_14 ( V_2 , V_28 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_29 -> V_32 | V_2 -> V_29 -> V_34 |
V_2 -> V_29 -> V_30 ;
F_5 ( V_2 , F_15 ( V_2 ) , 0 , V_6 ) ;
}
static struct V_1 * F_19 ( struct V_35 * V_14 )
{
struct V_1 * V_2 = NULL , * V_36 ;
F_20 ( & V_37 ) ;
if ( ! V_14 -> V_2 ) {
F_21 (tmp, &dev_list, list) {
V_2 = V_36 ;
break;
}
V_14 -> V_2 = V_2 ;
} else {
V_2 = V_14 -> V_2 ;
}
F_22 ( & V_37 ) ;
return V_2 ;
}
static void F_23 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
F_24 ( & V_2 -> V_39 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_11 = - V_40 ;
T_2 V_6 ;
V_2 -> V_31 = NULL ;
V_2 -> V_33 = NULL ;
V_2 -> V_41 = ( void * ) F_26 ( V_42 , V_43 ) ;
V_2 -> V_44 = ( void * ) F_26 ( V_42 , V_43 ) ;
V_2 -> V_45 = V_46 << V_43 ;
V_2 -> V_45 &= ~ ( V_47 - 1 ) ;
if ( ! V_2 -> V_41 || ! V_2 -> V_44 ) {
F_27 ( V_2 -> V_48 , L_1 ) ;
goto V_49;
}
V_2 -> V_50 = F_28 ( V_2 -> V_48 , V_2 -> V_41 , V_2 -> V_45 ,
V_51 ) ;
if ( F_29 ( V_2 -> V_48 , V_2 -> V_50 ) ) {
F_27 ( V_2 -> V_48 , L_2 , V_2 -> V_45 ) ;
V_11 = - V_52 ;
goto V_53;
}
V_2 -> V_54 = F_28 ( V_2 -> V_48 , V_2 -> V_44 , V_2 -> V_45 ,
V_55 ) ;
if ( F_29 ( V_2 -> V_48 , V_2 -> V_54 ) ) {
F_27 ( V_2 -> V_48 , L_2 , V_2 -> V_45 ) ;
V_11 = - V_52 ;
goto V_56;
}
F_30 ( V_6 ) ;
F_31 ( V_57 , V_6 ) ;
V_2 -> V_33 = F_32 ( V_6 ,
V_58 ,
& V_2 -> V_59 ,
V_2 -> V_48 , L_3 ) ;
if ( ! V_2 -> V_33 ) {
F_27 ( V_2 -> V_48 , L_4 ) ;
goto V_60;
}
V_2 -> V_31 = F_32 ( V_6 ,
V_58 ,
& V_2 -> V_61 ,
V_2 -> V_48 , L_5 ) ;
if ( ! V_2 -> V_31 ) {
F_27 ( V_2 -> V_48 , L_6 ) ;
goto V_62;
}
return 0 ;
V_62:
F_33 ( V_2 -> V_33 ) ;
V_60:
F_34 ( V_2 -> V_48 , V_2 -> V_54 , V_2 -> V_45 ,
V_55 ) ;
V_56:
F_34 ( V_2 -> V_48 , V_2 -> V_50 , V_2 -> V_45 , V_51 ) ;
V_53:
F_35 ( ( unsigned long ) V_2 -> V_44 , V_43 ) ;
F_35 ( ( unsigned long ) V_2 -> V_41 , V_43 ) ;
V_49:
if ( V_11 )
F_36 ( L_7 , V_11 ) ;
return V_11 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_31 ) ;
F_33 ( V_2 -> V_33 ) ;
F_34 ( V_2 -> V_48 , V_2 -> V_54 , V_2 -> V_45 ,
V_55 ) ;
F_34 ( V_2 -> V_48 , V_2 -> V_50 , V_2 -> V_45 , V_51 ) ;
F_35 ( ( unsigned long ) V_2 -> V_44 , V_43 ) ;
F_35 ( ( unsigned long ) V_2 -> V_41 , V_43 ) ;
}
static void F_38 ( void * V_63 , struct V_64 * V_65 ,
unsigned int V_66 , unsigned int V_67 , int V_68 )
{
struct V_69 V_70 ;
if ( ! V_67 )
return;
F_39 ( & V_70 , V_65 ) ;
F_40 ( & V_70 , V_66 ) ;
F_41 ( V_63 , & V_70 , V_67 , V_68 ) ;
F_42 ( & V_70 , V_68 , 0 ) ;
}
static int F_43 ( struct V_64 * * V_65 , T_3 * V_3 , void * V_63 ,
T_3 V_45 , T_3 V_71 , int V_68 )
{
unsigned int V_8 , V_72 = 0 ;
while ( V_45 && V_71 ) {
V_8 = F_44 ( ( * V_65 ) -> V_28 - * V_3 , V_71 ) ;
V_8 = F_44 ( V_8 , V_45 ) ;
if ( ! V_8 )
return V_72 ;
F_38 ( V_63 + V_72 , * V_65 , * V_3 , V_8 , V_68 ) ;
V_72 += V_8 ;
V_45 -= V_8 ;
* V_3 += V_8 ;
V_71 -= V_8 ;
if ( * V_3 == ( * V_65 ) -> V_28 ) {
* V_65 = F_45 ( * V_65 ) ;
if ( * V_65 )
* V_3 = 0 ;
else
V_71 = 0 ;
}
}
return V_72 ;
}
static int F_46 ( struct V_73 * V_74 ,
struct V_64 * V_75 , struct V_64 * V_76 )
{
struct V_35 * V_14 = F_47 ( V_74 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_77 * V_78 , * V_79 ;
struct V_80 V_81 ;
T_4 V_50 = F_48 ( V_75 ) ;
int V_82 , V_28 = F_49 ( V_75 ) ;
F_50 ( L_8 , V_28 ) ;
V_2 -> V_83 = V_28 ;
if ( ! ( V_2 -> V_9 & V_84 ) )
F_51 ( V_2 -> V_48 , V_50 , V_28 ,
V_51 ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_85 = V_2 -> V_86 + F_52 ( V_2 , 0 ) ;
V_81 . V_87 = V_2 -> V_86 + F_52 ( V_2 , 0 ) ;
V_81 . V_88 = V_89 ;
V_81 . V_90 = V_89 ;
V_81 . V_91 = V_92 ;
V_81 . V_93 = V_92 ;
V_82 = F_53 ( V_2 -> V_33 , & V_81 ) ;
if ( V_82 ) {
F_27 ( V_2 -> V_48 , L_9 ,
V_82 ) ;
return V_82 ;
}
V_78 = F_54 ( V_2 -> V_33 , V_75 , 1 ,
V_94 ,
V_95 | V_96 ) ;
if ( ! V_78 ) {
F_27 ( V_2 -> V_48 , L_10 ) ;
return - V_52 ;
}
V_78 -> V_97 = V_2 ;
V_82 = F_53 ( V_2 -> V_31 , & V_81 ) ;
if ( V_82 ) {
F_27 ( V_2 -> V_48 , L_11 ,
V_82 ) ;
return V_82 ;
}
V_79 = F_54 ( V_2 -> V_31 , V_76 , 1 ,
V_98 ,
V_95 | V_96 ) ;
if ( ! V_79 ) {
F_27 ( V_2 -> V_48 , L_12 ) ;
return - V_52 ;
}
V_79 -> V_99 = F_23 ;
V_79 -> V_97 = V_2 ;
F_55 ( V_78 ) ;
F_55 ( V_79 ) ;
F_56 ( V_2 -> V_33 ) ;
F_56 ( V_2 -> V_31 ) ;
V_2 -> V_29 -> V_100 ( V_2 , V_28 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = F_58 (
F_59 ( V_2 -> V_19 ) ) ;
int V_11 , V_101 = 0 , V_102 , V_68 ;
T_3 V_8 ;
T_4 V_103 , V_104 ;
struct V_64 * V_75 , * V_76 ;
int V_105 ;
F_50 ( L_13 , V_2 -> V_71 ) ;
if ( F_60 ( V_2 -> V_75 ) && F_60 ( V_2 -> V_76 ) ) {
V_102 = F_61 ( ( T_1 ) V_2 -> V_75 -> V_3 , sizeof( T_1 ) ) ;
V_68 = F_61 ( ( T_1 ) V_2 -> V_76 -> V_3 , sizeof( T_1 ) ) ;
V_101 = V_102 && V_68 ;
}
if ( V_101 ) {
V_8 = F_44 ( V_2 -> V_71 , F_49 ( V_2 -> V_75 ) ) ;
V_8 = F_44 ( V_8 , F_49 ( V_2 -> V_76 ) ) ;
if ( V_8 != V_2 -> V_71 ) {
F_36 ( L_14 ) ;
return - V_52 ;
}
F_50 ( L_15 ) ;
V_11 = F_62 ( V_2 -> V_48 , V_2 -> V_75 , 1 , V_51 ) ;
if ( ! V_11 ) {
F_27 ( V_2 -> V_48 , L_16 ) ;
return - V_52 ;
}
V_11 = F_62 ( V_2 -> V_48 , V_2 -> V_76 , 1 , V_55 ) ;
if ( ! V_11 ) {
F_27 ( V_2 -> V_48 , L_16 ) ;
F_63 ( V_2 -> V_48 , V_2 -> V_75 , 1 , V_51 ) ;
return - V_52 ;
}
V_103 = F_48 ( V_2 -> V_75 ) ;
V_104 = F_48 ( V_2 -> V_76 ) ;
V_75 = V_2 -> V_75 ;
V_76 = V_2 -> V_76 ;
V_2 -> V_9 |= V_84 ;
} else {
V_8 = F_43 ( & V_2 -> V_75 , & V_2 -> V_106 , V_2 -> V_41 ,
V_2 -> V_45 , V_2 -> V_71 , 0 ) ;
V_105 = F_64 ( V_8 , V_107 ) * V_107 ;
F_65 ( & V_2 -> V_108 , 1 ) ;
V_2 -> V_108 . V_3 = V_2 -> V_106 ;
F_49 ( & V_2 -> V_108 ) = V_105 ;
F_48 ( & V_2 -> V_108 ) = V_2 -> V_50 ;
F_65 ( & V_2 -> V_109 , 1 ) ;
V_2 -> V_109 . V_3 = V_2 -> V_110 ;
F_49 ( & V_2 -> V_109 ) = V_105 ;
F_48 ( & V_2 -> V_109 ) = V_2 -> V_54 ;
V_75 = & V_2 -> V_108 ;
V_76 = & V_2 -> V_109 ;
V_103 = V_2 -> V_50 ;
V_104 = V_2 -> V_54 ;
V_2 -> V_9 &= ~ V_84 ;
}
V_2 -> V_71 -= V_8 ;
V_11 = F_46 ( V_74 , V_75 , V_76 ) ;
if ( V_11 ) {
F_63 ( V_2 -> V_48 , V_2 -> V_75 , 1 , V_51 ) ;
F_63 ( V_2 -> V_48 , V_2 -> V_76 , 1 , V_51 ) ;
}
return V_11 ;
}
static void F_66 ( struct V_1 * V_2 , int V_11 )
{
struct V_111 * V_19 = V_2 -> V_19 ;
F_50 ( L_17 , V_11 ) ;
V_2 -> V_9 &= ~ V_112 ;
V_19 -> V_113 . V_114 ( & V_19 -> V_113 , V_11 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
T_3 V_8 ;
F_50 ( L_13 , V_2 -> V_71 ) ;
F_18 ( V_2 ) ;
F_68 ( V_2 -> V_33 ) ;
F_68 ( V_2 -> V_31 ) ;
if ( V_2 -> V_9 & V_84 ) {
F_63 ( V_2 -> V_48 , V_2 -> V_76 , 1 , V_55 ) ;
F_63 ( V_2 -> V_48 , V_2 -> V_75 , 1 , V_51 ) ;
} else {
F_51 ( V_2 -> V_48 , V_2 -> V_54 ,
V_2 -> V_83 , V_55 ) ;
V_8 = F_43 ( & V_2 -> V_76 , & V_2 -> V_110 , V_2 -> V_44 ,
V_2 -> V_45 , V_2 -> V_83 , 1 ) ;
if ( V_8 != V_2 -> V_83 ) {
V_11 = - V_52 ;
F_36 ( L_18 , V_8 ) ;
}
}
return V_11 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_111 * V_19 )
{
struct V_115 * V_116 , * V_117 ;
struct V_35 * V_14 ;
struct V_118 * V_119 ;
unsigned long V_9 ;
int V_11 , V_82 = 0 ;
F_70 ( & V_2 -> V_120 , V_9 ) ;
if ( V_19 )
V_82 = F_71 ( & V_2 -> V_121 , V_19 ) ;
if ( V_2 -> V_9 & V_112 ) {
F_72 ( & V_2 -> V_120 , V_9 ) ;
return V_82 ;
}
V_117 = F_73 ( & V_2 -> V_121 ) ;
V_116 = F_74 ( & V_2 -> V_121 ) ;
if ( V_116 )
V_2 -> V_9 |= V_112 ;
F_72 ( & V_2 -> V_120 , V_9 ) ;
if ( ! V_116 )
return V_82 ;
if ( V_117 )
V_117 -> V_114 ( V_117 , - V_122 ) ;
V_19 = F_75 ( V_116 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_71 = V_19 -> V_67 ;
V_2 -> V_106 = 0 ;
V_2 -> V_75 = V_19 -> V_123 ;
V_2 -> V_110 = 0 ;
V_2 -> V_76 = V_19 -> V_124 ;
V_119 = F_76 ( V_19 ) ;
V_14 = F_77 ( F_59 ( V_19 ) ) ;
V_119 -> V_125 &= V_126 ;
V_2 -> V_9 = ( V_2 -> V_9 & ~ V_126 ) | V_119 -> V_125 ;
V_2 -> V_14 = V_14 ;
V_14 -> V_2 = V_2 ;
V_11 = F_8 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_57 ( V_2 ) ;
if ( V_11 ) {
F_66 ( V_2 , V_11 ) ;
F_24 ( & V_2 -> V_127 ) ;
}
return V_82 ;
}
static void F_78 ( unsigned long V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
int V_11 ;
F_50 ( L_19 ) ;
V_11 = F_67 ( V_2 ) ;
V_11 = V_2 -> V_11 ? : V_11 ;
if ( V_2 -> V_71 && ! V_11 ) {
V_11 = F_57 ( V_2 ) ;
if ( ! V_11 )
return;
}
F_66 ( V_2 , V_11 ) ;
F_69 ( V_2 , NULL ) ;
F_50 ( L_20 ) ;
}
static void F_79 ( unsigned long V_38 )
{
struct V_1 * V_2 = (struct V_1 * ) V_38 ;
F_69 ( V_2 , NULL ) ;
}
static int F_80 ( struct V_111 * V_19 , unsigned long V_125 )
{
struct V_35 * V_14 = F_77 (
F_59 ( V_19 ) ) ;
struct V_118 * V_119 = F_76 ( V_19 ) ;
struct V_1 * V_2 ;
F_50 ( L_21 , V_19 -> V_67 ,
! ! ( V_125 & V_25 ) ,
! ! ( V_125 & V_17 ) ) ;
if ( ! F_61 ( V_19 -> V_67 , V_47 ) ) {
F_36 ( L_22 ) ;
return - V_52 ;
}
V_2 = F_19 ( V_14 ) ;
if ( ! V_2 )
return - V_128 ;
V_119 -> V_125 = V_125 ;
return F_69 ( V_2 , V_19 ) ;
}
static int F_81 ( struct V_129 * V_74 , const T_5 * V_16 ,
unsigned int V_15 )
{
struct V_35 * V_14 = F_77 ( V_74 ) ;
if ( V_15 != V_130 && V_15 != V_131 &&
V_15 != V_132 )
return - V_52 ;
F_50 ( L_23 , V_15 ) ;
memcpy ( V_14 -> V_16 , V_16 , V_15 ) ;
V_14 -> V_15 = V_15 ;
return 0 ;
}
static int F_82 ( struct V_111 * V_19 )
{
return F_80 ( V_19 , V_25 ) ;
}
static int F_83 ( struct V_111 * V_19 )
{
return F_80 ( V_19 , 0 ) ;
}
static int F_84 ( struct V_111 * V_19 )
{
return F_80 ( V_19 , V_25 | V_17 ) ;
}
static int F_85 ( struct V_111 * V_19 )
{
return F_80 ( V_19 , V_17 ) ;
}
static int F_86 ( struct V_111 * V_19 )
{
return F_80 ( V_19 , V_25 | V_18 ) ;
}
static int F_87 ( struct V_111 * V_19 )
{
return F_80 ( V_19 , V_18 ) ;
}
static int F_88 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_37 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_37 ) ;
F_89 ( V_2 -> V_48 ) ;
V_74 -> V_133 . V_134 = sizeof( struct V_118 ) ;
return 0 ;
}
static void F_90 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_37 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_37 ) ;
F_91 ( V_2 -> V_48 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_135 * V_48 , struct V_136 * V_137 )
{
struct V_138 * V_139 = V_48 -> V_140 ;
const struct V_141 * V_142 ;
int V_11 = 0 ;
V_142 = F_93 ( F_94 ( V_143 ) , V_48 ) ;
if ( ! V_142 ) {
F_27 ( V_48 , L_24 ) ;
V_11 = - V_52 ;
goto V_11;
}
V_11 = F_95 ( V_139 , 0 , V_137 ) ;
if ( V_11 < 0 ) {
F_27 ( V_48 , L_25 ) ;
V_11 = - V_52 ;
goto V_11;
}
V_2 -> V_61 = - 1 ;
V_2 -> V_59 = - 1 ;
V_2 -> V_29 = V_142 -> V_38 ;
V_11:
return V_11 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_135 * V_48 , struct V_136 * V_137 )
{
return - V_52 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_144 * V_145 , struct V_136 * V_137 )
{
struct V_135 * V_48 = & V_145 -> V_48 ;
struct V_136 * V_146 ;
int V_11 = 0 ;
V_146 = F_97 ( V_145 , V_147 , 0 ) ;
if ( ! V_146 ) {
F_27 ( V_48 , L_26 ) ;
V_11 = - V_128 ;
goto V_11;
}
memcpy ( V_137 , V_146 , sizeof( * V_137 ) ) ;
V_146 = F_97 ( V_145 , V_148 , 0 ) ;
if ( ! V_146 ) {
F_27 ( V_48 , L_27 ) ;
V_11 = - V_128 ;
goto V_11;
}
V_2 -> V_61 = V_146 -> V_66 ;
V_146 = F_97 ( V_145 , V_148 , 1 ) ;
if ( ! V_146 ) {
F_27 ( V_48 , L_28 ) ;
V_11 = - V_128 ;
goto V_11;
}
V_2 -> V_59 = V_146 -> V_66 ;
V_2 -> V_29 = & V_149 ;
V_11:
return V_11 ;
}
static int F_98 ( struct V_144 * V_145 )
{
struct V_135 * V_48 = & V_145 -> V_48 ;
struct V_1 * V_2 ;
struct V_150 * V_151 ;
struct V_136 V_137 ;
int V_11 = - V_40 , V_13 , V_152 ;
T_1 V_153 ;
V_2 = F_99 ( sizeof( struct V_1 ) , V_42 ) ;
if ( V_2 == NULL ) {
F_27 ( V_48 , L_29 ) ;
goto V_154;
}
V_2 -> V_48 = V_48 ;
F_100 ( V_145 , V_2 ) ;
F_101 ( & V_2 -> V_120 ) ;
F_102 ( & V_2 -> V_121 , V_155 ) ;
V_11 = ( V_48 -> V_140 ) ? F_92 ( V_2 , V_48 , & V_137 ) :
F_96 ( V_2 , V_145 , & V_137 ) ;
if ( V_11 )
goto V_156;
V_2 -> V_4 = F_103 ( V_48 , & V_137 ) ;
if ( F_104 ( V_2 -> V_4 ) ) {
V_11 = F_105 ( V_2 -> V_4 ) ;
goto V_156;
}
V_2 -> V_86 = V_137 . V_66 ;
F_106 ( V_48 ) ;
F_89 ( V_48 ) ;
F_18 ( V_2 ) ;
V_153 = F_1 ( V_2 , F_107 ( V_2 ) ) ;
F_91 ( V_48 ) ;
F_108 ( V_48 , L_30 ,
( V_153 & V_2 -> V_29 -> V_157 ) >> V_2 -> V_29 -> V_158 ,
( V_153 & V_2 -> V_29 -> V_159 ) >> V_2 -> V_29 -> V_160 ) ;
F_109 ( & V_2 -> V_39 , F_78 , ( unsigned long ) V_2 ) ;
F_109 ( & V_2 -> V_127 , F_79 , ( unsigned long ) V_2 ) ;
V_11 = F_25 ( V_2 ) ;
if ( V_11 )
goto V_161;
F_110 ( & V_2 -> V_162 ) ;
F_111 ( & V_37 ) ;
F_112 ( & V_2 -> V_162 , & V_163 ) ;
F_113 ( & V_37 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_29 -> V_164 ; V_13 ++ ) {
for ( V_152 = 0 ; V_152 < V_2 -> V_29 -> V_165 [ V_13 ] . V_166 ; V_152 ++ ) {
V_151 = & V_2 -> V_29 -> V_165 [ V_13 ] . V_167 [ V_152 ] ;
F_50 ( L_31 , V_151 -> V_168 ) ;
F_110 ( & V_151 -> V_169 ) ;
V_11 = F_114 ( V_151 ) ;
if ( V_11 )
goto V_170;
V_2 -> V_29 -> V_165 [ V_13 ] . V_171 ++ ;
}
}
return 0 ;
V_170:
for ( V_13 = V_2 -> V_29 -> V_164 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_152 = V_2 -> V_29 -> V_165 [ V_13 ] . V_171 - 1 ; V_152 >= 0 ; V_152 -- )
F_115 (
& V_2 -> V_29 -> V_165 [ V_13 ] . V_167 [ V_152 ] ) ;
F_37 ( V_2 ) ;
V_161:
F_116 ( & V_2 -> V_39 ) ;
F_116 ( & V_2 -> V_127 ) ;
F_117 ( V_48 ) ;
V_156:
F_118 ( V_2 ) ;
V_2 = NULL ;
V_154:
F_27 ( V_48 , L_32 ) ;
return V_11 ;
}
static int F_119 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = F_120 ( V_145 ) ;
int V_13 , V_152 ;
if ( ! V_2 )
return - V_128 ;
F_111 ( & V_37 ) ;
F_121 ( & V_2 -> V_162 ) ;
F_113 ( & V_37 ) ;
for ( V_13 = V_2 -> V_29 -> V_164 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_152 = V_2 -> V_29 -> V_165 [ V_13 ] . V_171 - 1 ; V_152 >= 0 ; V_152 -- )
F_115 (
& V_2 -> V_29 -> V_165 [ V_13 ] . V_167 [ V_152 ] ) ;
F_116 ( & V_2 -> V_39 ) ;
F_116 ( & V_2 -> V_127 ) ;
F_37 ( V_2 ) ;
F_117 ( V_2 -> V_48 ) ;
F_118 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_122 ( struct V_135 * V_48 )
{
F_91 ( V_48 ) ;
return 0 ;
}
static int F_123 ( struct V_135 * V_48 )
{
F_89 ( V_48 ) ;
return 0 ;
}
