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
T_1 V_7 ;
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
if ( V_2 -> V_9 & V_18 )
V_7 |= V_22 | V_23 ;
if ( V_2 -> V_9 & V_24 )
V_7 |= V_25 ;
F_5 ( V_2 , F_13 ( V_2 ) , V_7 , V_26 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_27 )
{
T_1 V_6 , V_7 ;
V_7 = V_2 -> V_28 -> V_29 ;
if ( V_2 -> V_30 != NULL )
V_7 |= V_2 -> V_28 -> V_31 ;
if ( V_2 -> V_32 != NULL )
V_7 |= V_2 -> V_28 -> V_33 ;
V_6 = V_2 -> V_28 -> V_31 | V_2 -> V_28 -> V_33 |
V_2 -> V_28 -> V_29 ;
F_5 ( V_2 , F_15 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_27 )
{
F_3 ( V_2 , F_17 ( 0 ) , V_27 ) ;
F_3 ( V_2 , F_17 ( 1 ) , 0 ) ;
F_14 ( V_2 , V_27 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_28 -> V_31 | V_2 -> V_28 -> V_33 |
V_2 -> V_28 -> V_29 ;
F_5 ( V_2 , F_15 ( V_2 ) , 0 , V_6 ) ;
}
static struct V_1 * F_19 ( struct V_34 * V_14 )
{
struct V_1 * V_2 = NULL , * V_35 ;
F_20 ( & V_36 ) ;
if ( ! V_14 -> V_2 ) {
F_21 (tmp, &dev_list, list) {
V_2 = V_35 ;
break;
}
V_14 -> V_2 = V_2 ;
} else {
V_2 = V_14 -> V_2 ;
}
F_22 ( & V_36 ) ;
return V_2 ;
}
static void F_23 ( void * V_37 )
{
struct V_1 * V_2 = V_37 ;
F_24 ( & V_2 -> V_38 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_11 = - V_39 ;
T_2 V_6 ;
V_2 -> V_30 = NULL ;
V_2 -> V_32 = NULL ;
F_26 ( V_6 ) ;
F_27 ( V_40 , V_6 ) ;
V_2 -> V_32 = F_28 ( V_6 ,
V_41 ,
& V_2 -> V_42 ,
V_2 -> V_43 , L_1 ) ;
if ( ! V_2 -> V_32 ) {
F_29 ( V_2 -> V_43 , L_2 ) ;
goto V_44;
}
V_2 -> V_30 = F_28 ( V_6 ,
V_41 ,
& V_2 -> V_45 ,
V_2 -> V_43 , L_3 ) ;
if ( ! V_2 -> V_30 ) {
F_29 ( V_2 -> V_43 , L_4 ) ;
goto V_46;
}
return 0 ;
V_46:
F_30 ( V_2 -> V_32 ) ;
V_44:
if ( V_11 )
F_31 ( L_5 , V_11 ) ;
return V_11 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_30 ) ;
F_30 ( V_2 -> V_32 ) ;
}
static void F_33 ( void * V_47 , struct V_48 * V_49 ,
unsigned int V_50 , unsigned int V_51 , int V_52 )
{
struct V_53 V_54 ;
if ( ! V_51 )
return;
F_34 ( & V_54 , V_49 ) ;
F_35 ( & V_54 , V_50 ) ;
F_36 ( V_47 , & V_54 , V_51 , V_52 ) ;
F_37 ( & V_54 , V_52 , 0 ) ;
}
static int F_38 ( struct V_55 * V_56 ,
struct V_48 * V_57 , struct V_48 * V_58 ,
int V_59 , int V_60 )
{
struct V_34 * V_14 = F_39 ( V_56 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_61 * V_62 , * V_63 ;
struct V_64 V_65 ;
int V_66 ;
if ( V_2 -> V_67 ) {
F_34 ( & V_2 -> V_68 , V_2 -> V_57 ) ;
F_34 ( & V_2 -> V_69 , V_2 -> V_58 ) ;
F_3 ( V_2 , F_40 ( V_2 ) , 0x2 ) ;
return 0 ;
}
F_41 ( V_2 -> V_43 , V_2 -> V_57 , V_59 , V_70 ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_71 = V_2 -> V_72 + F_42 ( V_2 , 0 ) ;
V_65 . V_73 = V_2 -> V_72 + F_42 ( V_2 , 0 ) ;
V_65 . V_74 = V_75 ;
V_65 . V_76 = V_75 ;
V_65 . V_77 = V_78 ;
V_65 . V_79 = V_78 ;
V_66 = F_43 ( V_2 -> V_32 , & V_65 ) ;
if ( V_66 ) {
F_29 ( V_2 -> V_43 , L_6 ,
V_66 ) ;
return V_66 ;
}
V_62 = F_44 ( V_2 -> V_32 , V_57 , V_59 ,
V_80 ,
V_81 | V_82 ) ;
if ( ! V_62 ) {
F_29 ( V_2 -> V_43 , L_7 ) ;
return - V_83 ;
}
V_62 -> V_84 = V_2 ;
V_66 = F_43 ( V_2 -> V_30 , & V_65 ) ;
if ( V_66 ) {
F_29 ( V_2 -> V_43 , L_8 ,
V_66 ) ;
return V_66 ;
}
V_63 = F_44 ( V_2 -> V_30 , V_58 , V_60 ,
V_85 ,
V_81 | V_82 ) ;
if ( ! V_63 ) {
F_29 ( V_2 -> V_43 , L_9 ) ;
return - V_83 ;
}
V_63 -> V_86 = F_23 ;
V_63 -> V_84 = V_2 ;
F_45 ( V_62 ) ;
F_45 ( V_63 ) ;
F_46 ( V_2 -> V_32 ) ;
F_46 ( V_2 -> V_30 ) ;
V_2 -> V_28 -> V_87 ( V_2 , V_2 -> V_88 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = F_48 (
F_49 ( V_2 -> V_19 ) ) ;
int V_11 ;
F_50 ( L_10 , V_2 -> V_88 ) ;
if ( ! V_2 -> V_67 ) {
V_11 = F_51 ( V_2 -> V_43 , V_2 -> V_57 , V_2 -> V_59 ,
V_70 ) ;
if ( ! V_11 ) {
F_29 ( V_2 -> V_43 , L_11 ) ;
return - V_83 ;
}
V_11 = F_51 ( V_2 -> V_43 , V_2 -> V_58 , V_2 -> V_60 ,
V_89 ) ;
if ( ! V_11 ) {
F_29 ( V_2 -> V_43 , L_11 ) ;
return - V_83 ;
}
}
V_11 = F_38 ( V_56 , V_2 -> V_57 , V_2 -> V_58 , V_2 -> V_59 ,
V_2 -> V_60 ) ;
if ( V_11 && ! V_2 -> V_67 ) {
F_52 ( V_2 -> V_43 , V_2 -> V_57 , V_2 -> V_59 , V_70 ) ;
F_52 ( V_2 -> V_43 , V_2 -> V_58 , V_2 -> V_60 ,
V_89 ) ;
}
return V_11 ;
}
static void F_53 ( struct V_1 * V_2 , int V_11 )
{
struct V_90 * V_19 = V_2 -> V_19 ;
F_50 ( L_12 , V_11 ) ;
V_2 -> V_9 &= ~ V_91 ;
V_19 -> V_92 . V_93 ( & V_19 -> V_92 , V_11 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_11 = 0 ;
F_50 ( L_10 , V_2 -> V_88 ) ;
F_18 ( V_2 ) ;
F_55 ( V_2 -> V_32 ) ;
F_55 ( V_2 -> V_30 ) ;
return V_11 ;
}
static int F_56 ( struct V_48 * V_49 , int V_88 )
{
int V_94 = 0 ;
if ( ! F_57 ( V_88 , V_95 ) )
return - V_83 ;
while ( V_49 ) {
if ( ! F_57 ( V_49 -> V_3 , 4 ) )
return - 1 ;
if ( ! F_57 ( V_49 -> V_27 , V_95 ) )
return - 1 ;
V_94 += V_49 -> V_27 ;
V_49 = F_58 ( V_49 ) ;
}
if ( V_94 != V_88 )
return - 1 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
void * V_96 , * V_97 ;
int V_98 , V_88 ;
V_88 = F_60 ( V_2 -> V_88 , V_95 ) ;
V_98 = F_61 ( V_88 ) ;
V_96 = ( void * ) F_62 ( V_99 , V_98 ) ;
V_97 = ( void * ) F_62 ( V_99 , V_98 ) ;
if ( ! V_96 || ! V_97 ) {
F_31 ( L_13 ) ;
return - 1 ;
}
V_2 -> V_100 = V_2 -> V_58 ;
F_33 ( V_96 , V_2 -> V_57 , 0 , V_2 -> V_88 , 0 ) ;
F_63 ( & V_2 -> V_101 , 1 ) ;
F_64 ( & V_2 -> V_101 , V_96 , V_88 ) ;
V_2 -> V_57 = & V_2 -> V_101 ;
F_63 ( & V_2 -> V_102 , 1 ) ;
F_64 ( & V_2 -> V_102 , V_97 , V_88 ) ;
V_2 -> V_58 = & V_2 -> V_102 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_90 * V_19 )
{
struct V_103 * V_104 , * V_105 ;
struct V_34 * V_14 ;
struct V_106 * V_107 ;
unsigned long V_9 ;
int V_11 , V_66 = 0 , V_94 ;
F_66 ( & V_2 -> V_108 , V_9 ) ;
if ( V_19 )
V_66 = F_67 ( & V_2 -> V_109 , V_19 ) ;
if ( V_2 -> V_9 & V_91 ) {
F_68 ( & V_2 -> V_108 , V_9 ) ;
return V_66 ;
}
V_105 = F_69 ( & V_2 -> V_109 ) ;
V_104 = F_70 ( & V_2 -> V_109 ) ;
if ( V_104 )
V_2 -> V_9 |= V_91 ;
F_68 ( & V_2 -> V_108 , V_9 ) ;
if ( ! V_104 )
return V_66 ;
if ( V_105 )
V_105 -> V_93 ( V_105 , - V_110 ) ;
V_19 = F_71 ( V_104 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_88 = V_19 -> V_51 ;
V_2 -> V_111 = V_19 -> V_51 ;
V_2 -> V_57 = V_19 -> V_112 ;
V_2 -> V_58 = V_19 -> V_113 ;
if ( F_56 ( V_2 -> V_57 , V_2 -> V_88 ) ||
F_56 ( V_2 -> V_58 , V_2 -> V_88 ) ) {
if ( F_59 ( V_2 ) )
F_31 ( L_14 ) ;
V_2 -> V_114 = 1 ;
} else {
V_2 -> V_114 = 0 ;
}
V_94 = F_60 ( V_2 -> V_88 , V_95 ) ;
V_2 -> V_59 = F_72 ( V_2 -> V_57 , V_94 ) ;
V_2 -> V_60 = F_72 ( V_2 -> V_58 , V_94 ) ;
F_73 ( V_2 -> V_59 < 0 || V_2 -> V_60 < 0 ) ;
V_107 = F_74 ( V_19 ) ;
V_14 = F_75 ( F_49 ( V_19 ) ) ;
V_107 -> V_115 &= V_116 ;
V_2 -> V_9 = ( V_2 -> V_9 & ~ V_116 ) | V_107 -> V_115 ;
V_2 -> V_14 = V_14 ;
V_14 -> V_2 = V_2 ;
V_11 = F_8 ( V_2 ) ;
if ( ! V_11 )
V_11 = F_47 ( V_2 ) ;
if ( V_11 ) {
F_53 ( V_2 , V_11 ) ;
F_24 ( & V_2 -> V_117 ) ;
}
return V_66 ;
}
static void F_76 ( unsigned long V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
void * V_96 , * V_97 ;
int V_98 , V_94 ;
F_50 ( L_15 ) ;
if ( ! V_2 -> V_67 ) {
F_41 ( V_2 -> V_43 , V_2 -> V_58 , V_2 -> V_60 ,
V_89 ) ;
F_52 ( V_2 -> V_43 , V_2 -> V_57 , V_2 -> V_59 , V_70 ) ;
F_52 ( V_2 -> V_43 , V_2 -> V_58 , V_2 -> V_60 ,
V_89 ) ;
F_54 ( V_2 ) ;
}
if ( V_2 -> V_114 ) {
V_96 = F_77 ( & V_2 -> V_101 ) ;
V_97 = F_77 ( & V_2 -> V_102 ) ;
F_33 ( V_97 , V_2 -> V_100 , 0 , V_2 -> V_111 , 1 ) ;
V_94 = F_60 ( V_2 -> V_111 , V_95 ) ;
V_98 = F_61 ( V_94 ) ;
F_78 ( ( unsigned long ) V_96 , V_98 ) ;
F_78 ( ( unsigned long ) V_97 , V_98 ) ;
}
F_53 ( V_2 , 0 ) ;
F_65 ( V_2 , NULL ) ;
F_50 ( L_16 ) ;
}
static void F_79 ( unsigned long V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
F_65 ( V_2 , NULL ) ;
}
static int F_80 ( struct V_90 * V_19 , unsigned long V_115 )
{
struct V_34 * V_14 = F_75 (
F_49 ( V_19 ) ) ;
struct V_106 * V_107 = F_74 ( V_19 ) ;
struct V_1 * V_2 ;
F_50 ( L_17 , V_19 -> V_51 ,
! ! ( V_115 & V_24 ) ,
! ! ( V_115 & V_17 ) ) ;
V_2 = F_19 ( V_14 ) ;
if ( ! V_2 )
return - V_118 ;
V_107 -> V_115 = V_115 ;
return F_65 ( V_2 , V_19 ) ;
}
static int F_81 ( struct V_119 * V_56 , const T_3 * V_16 ,
unsigned int V_15 )
{
struct V_34 * V_14 = F_75 ( V_56 ) ;
if ( V_15 != V_120 && V_15 != V_121 &&
V_15 != V_122 )
return - V_83 ;
F_50 ( L_18 , V_15 ) ;
memcpy ( V_14 -> V_16 , V_16 , V_15 ) ;
V_14 -> V_15 = V_15 ;
return 0 ;
}
static int F_82 ( struct V_90 * V_19 )
{
return F_80 ( V_19 , V_24 ) ;
}
static int F_83 ( struct V_90 * V_19 )
{
return F_80 ( V_19 , 0 ) ;
}
static int F_84 ( struct V_90 * V_19 )
{
return F_80 ( V_19 , V_24 | V_17 ) ;
}
static int F_85 ( struct V_90 * V_19 )
{
return F_80 ( V_19 , V_17 ) ;
}
static int F_86 ( struct V_90 * V_19 )
{
return F_80 ( V_19 , V_24 | V_18 ) ;
}
static int F_87 ( struct V_90 * V_19 )
{
return F_80 ( V_19 , V_18 ) ;
}
static int F_88 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = NULL ;
int V_11 ;
F_20 ( & V_36 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_36 ) ;
V_11 = F_89 ( V_2 -> V_43 ) ;
if ( V_11 < 0 ) {
F_29 ( V_2 -> V_43 , L_19 ,
V_123 , V_11 ) ;
return V_11 ;
}
V_56 -> V_124 . V_125 = sizeof( struct V_106 ) ;
return 0 ;
}
static void F_90 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_36 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_36 ) ;
F_91 ( V_2 -> V_43 ) ;
}
static T_4 F_92 ( int V_126 , void * V_127 )
{
struct V_1 * V_2 = V_127 ;
T_1 V_128 , V_13 ;
T_1 * V_112 , * V_113 ;
V_128 = F_1 ( V_2 , F_93 ( V_2 ) ) ;
if ( V_128 & V_129 ) {
F_3 ( V_2 , F_40 ( V_2 ) , 0x0 ) ;
F_73 ( ! V_2 -> V_57 ) ;
F_73 ( F_94 ( V_130 ) > V_2 -> V_57 -> V_27 ) ;
V_112 = F_77 ( V_2 -> V_57 ) + F_94 ( V_130 ) ;
for ( V_13 = 0 ; V_13 < V_131 ; V_13 ++ ) {
F_3 ( V_2 , F_42 ( V_2 , V_13 ) , * V_112 ) ;
F_35 ( & V_2 -> V_68 , 4 ) ;
if ( V_2 -> V_57 -> V_27 == F_94 ( V_130 ) ) {
V_2 -> V_57 = F_58 ( V_2 -> V_57 ) ;
if ( V_2 -> V_57 ) {
F_34 ( & V_2 -> V_68 ,
V_2 -> V_57 ) ;
V_112 = F_77 ( V_2 -> V_57 ) +
F_94 ( V_130 ) ;
}
} else {
V_112 ++ ;
}
}
V_128 &= ~ V_129 ;
F_3 ( V_2 , F_93 ( V_2 ) , V_128 ) ;
F_3 ( V_2 , F_40 ( V_2 ) , 0x4 ) ;
} else if ( V_128 & V_132 ) {
F_3 ( V_2 , F_40 ( V_2 ) , 0x0 ) ;
F_73 ( ! V_2 -> V_58 ) ;
F_73 ( F_94 ( V_52 ) > V_2 -> V_58 -> V_27 ) ;
V_113 = F_77 ( V_2 -> V_58 ) + F_94 ( V_52 ) ;
for ( V_13 = 0 ; V_13 < V_131 ; V_13 ++ ) {
* V_113 = F_1 ( V_2 , F_42 ( V_2 , V_13 ) ) ;
F_35 ( & V_2 -> V_69 , 4 ) ;
if ( V_2 -> V_58 -> V_27 == F_94 ( V_52 ) ) {
V_2 -> V_58 = F_58 ( V_2 -> V_58 ) ;
if ( V_2 -> V_58 ) {
F_34 ( & V_2 -> V_69 ,
V_2 -> V_58 ) ;
V_113 = F_77 ( V_2 -> V_58 ) +
F_94 ( V_52 ) ;
}
} else {
V_113 ++ ;
}
}
V_2 -> V_88 -= F_95 ( V_133 , V_95 , V_2 -> V_88 ) ;
V_128 &= ~ V_132 ;
F_3 ( V_2 , F_93 ( V_2 ) , V_128 ) ;
if ( ! V_2 -> V_88 )
F_24 ( & V_2 -> V_38 ) ;
else
F_3 ( V_2 , F_40 ( V_2 ) , 0x2 ) ;
}
return V_134 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_135 * V_43 , struct V_136 * V_137 )
{
struct V_138 * V_139 = V_43 -> V_140 ;
const struct V_141 * V_142 ;
int V_11 = 0 ;
V_142 = F_97 ( F_98 ( V_143 ) , V_43 ) ;
if ( ! V_142 ) {
F_29 ( V_43 , L_20 ) ;
V_11 = - V_83 ;
goto V_11;
}
V_11 = F_99 ( V_139 , 0 , V_137 ) ;
if ( V_11 < 0 ) {
F_29 ( V_43 , L_21 ) ;
V_11 = - V_83 ;
goto V_11;
}
V_2 -> V_45 = - 1 ;
V_2 -> V_42 = - 1 ;
V_2 -> V_28 = V_142 -> V_37 ;
V_11:
return V_11 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_135 * V_43 , struct V_136 * V_137 )
{
return - V_83 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_144 * V_145 , struct V_136 * V_137 )
{
struct V_135 * V_43 = & V_145 -> V_43 ;
struct V_136 * V_146 ;
int V_11 = 0 ;
V_146 = F_101 ( V_145 , V_147 , 0 ) ;
if ( ! V_146 ) {
F_29 ( V_43 , L_22 ) ;
V_11 = - V_118 ;
goto V_11;
}
memcpy ( V_137 , V_146 , sizeof( * V_137 ) ) ;
V_146 = F_101 ( V_145 , V_148 , 0 ) ;
if ( ! V_146 ) {
F_29 ( V_43 , L_23 ) ;
V_11 = - V_118 ;
goto V_11;
}
V_2 -> V_45 = V_146 -> V_50 ;
V_146 = F_101 ( V_145 , V_148 , 1 ) ;
if ( ! V_146 ) {
F_29 ( V_43 , L_24 ) ;
V_11 = - V_118 ;
goto V_11;
}
V_2 -> V_42 = V_146 -> V_50 ;
V_2 -> V_28 = & V_149 ;
V_11:
return V_11 ;
}
static int F_102 ( struct V_144 * V_145 )
{
struct V_135 * V_43 = & V_145 -> V_43 ;
struct V_1 * V_2 ;
struct V_150 * V_151 ;
struct V_136 V_137 ;
int V_11 = - V_39 , V_13 , V_152 , V_126 = - 1 ;
T_1 V_153 ;
V_2 = F_103 ( V_43 , sizeof( struct V_1 ) , V_154 ) ;
if ( V_2 == NULL ) {
F_29 ( V_43 , L_25 ) ;
goto V_155;
}
V_2 -> V_43 = V_43 ;
F_104 ( V_145 , V_2 ) ;
F_105 ( & V_2 -> V_108 ) ;
F_106 ( & V_2 -> V_109 , V_156 ) ;
V_11 = ( V_43 -> V_140 ) ? F_96 ( V_2 , V_43 , & V_137 ) :
F_100 ( V_2 , V_145 , & V_137 ) ;
if ( V_11 )
goto V_157;
V_2 -> V_4 = F_107 ( V_43 , & V_137 ) ;
if ( F_108 ( V_2 -> V_4 ) ) {
V_11 = F_109 ( V_2 -> V_4 ) ;
goto V_157;
}
V_2 -> V_72 = V_137 . V_50 ;
F_110 ( V_43 ) ;
V_11 = F_89 ( V_43 ) ;
if ( V_11 < 0 ) {
F_29 ( V_43 , L_19 ,
V_123 , V_11 ) ;
goto V_157;
}
F_18 ( V_2 ) ;
V_153 = F_1 ( V_2 , F_111 ( V_2 ) ) ;
F_91 ( V_43 ) ;
F_112 ( V_43 , L_26 ,
( V_153 & V_2 -> V_28 -> V_158 ) >> V_2 -> V_28 -> V_159 ,
( V_153 & V_2 -> V_28 -> V_160 ) >> V_2 -> V_28 -> V_161 ) ;
F_113 ( & V_2 -> V_38 , F_76 , ( unsigned long ) V_2 ) ;
F_113 ( & V_2 -> V_117 , F_79 , ( unsigned long ) V_2 ) ;
V_11 = F_25 ( V_2 ) ;
if ( V_11 && F_93 ( V_2 ) && F_40 ( V_2 ) ) {
V_2 -> V_67 = 1 ;
V_126 = F_114 ( V_145 , 0 ) ;
if ( V_126 < 0 ) {
F_29 ( V_43 , L_27 ) ;
goto V_162;
}
V_11 = F_115 ( V_43 , V_126 , F_92 , 0 ,
F_116 ( V_43 ) , V_2 ) ;
if ( V_11 ) {
F_29 ( V_43 , L_28 ) ;
goto V_162;
}
}
F_117 ( & V_2 -> V_163 ) ;
F_118 ( & V_36 ) ;
F_119 ( & V_2 -> V_163 , & V_164 ) ;
F_120 ( & V_36 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_28 -> V_165 ; V_13 ++ ) {
for ( V_152 = 0 ; V_152 < V_2 -> V_28 -> V_166 [ V_13 ] . V_167 ; V_152 ++ ) {
V_151 = & V_2 -> V_28 -> V_166 [ V_13 ] . V_168 [ V_152 ] ;
F_50 ( L_29 , V_151 -> V_169 ) ;
F_117 ( & V_151 -> V_170 ) ;
V_11 = F_121 ( V_151 ) ;
if ( V_11 )
goto V_171;
V_2 -> V_28 -> V_166 [ V_13 ] . V_172 ++ ;
}
}
return 0 ;
V_171:
for ( V_13 = V_2 -> V_28 -> V_165 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_152 = V_2 -> V_28 -> V_166 [ V_13 ] . V_172 - 1 ; V_152 >= 0 ; V_152 -- )
F_122 (
& V_2 -> V_28 -> V_166 [ V_13 ] . V_168 [ V_152 ] ) ;
if ( ! V_2 -> V_67 )
F_32 ( V_2 ) ;
V_162:
F_123 ( & V_2 -> V_38 ) ;
F_123 ( & V_2 -> V_117 ) ;
F_124 ( V_43 ) ;
V_157:
V_2 = NULL ;
V_155:
F_29 ( V_43 , L_30 ) ;
return V_11 ;
}
static int F_125 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = F_126 ( V_145 ) ;
int V_13 , V_152 ;
if ( ! V_2 )
return - V_118 ;
F_118 ( & V_36 ) ;
F_127 ( & V_2 -> V_163 ) ;
F_120 ( & V_36 ) ;
for ( V_13 = V_2 -> V_28 -> V_165 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_152 = V_2 -> V_28 -> V_166 [ V_13 ] . V_172 - 1 ; V_152 >= 0 ; V_152 -- )
F_122 (
& V_2 -> V_28 -> V_166 [ V_13 ] . V_168 [ V_152 ] ) ;
F_123 ( & V_2 -> V_38 ) ;
F_123 ( & V_2 -> V_117 ) ;
F_32 ( V_2 ) ;
F_124 ( V_2 -> V_43 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_128 ( struct V_135 * V_43 )
{
F_91 ( V_43 ) ;
return 0 ;
}
static int F_129 ( struct V_135 * V_43 )
{
F_89 ( V_43 ) ;
return 0 ;
}
