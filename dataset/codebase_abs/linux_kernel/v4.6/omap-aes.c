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
F_54 ( V_2 -> V_91 , V_19 , V_11 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
F_50 ( L_10 , V_2 -> V_88 ) ;
F_18 ( V_2 ) ;
F_56 ( V_2 -> V_32 ) ;
F_56 ( V_2 -> V_30 ) ;
return 0 ;
}
static int F_57 ( struct V_48 * V_49 , int V_88 )
{
int V_92 = 0 ;
if ( ! F_58 ( V_88 , V_93 ) )
return - V_83 ;
while ( V_49 ) {
if ( ! F_58 ( V_49 -> V_3 , 4 ) )
return - 1 ;
if ( ! F_58 ( V_49 -> V_27 , V_93 ) )
return - 1 ;
V_92 += V_49 -> V_27 ;
V_49 = F_59 ( V_49 ) ;
}
if ( V_92 != V_88 )
return - 1 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
void * V_94 , * V_95 ;
int V_96 , V_88 ;
V_88 = F_61 ( V_2 -> V_88 , V_93 ) ;
V_96 = F_62 ( V_88 ) ;
V_94 = ( void * ) F_63 ( V_97 , V_96 ) ;
V_95 = ( void * ) F_63 ( V_97 , V_96 ) ;
if ( ! V_94 || ! V_95 ) {
F_31 ( L_13 ) ;
return - 1 ;
}
V_2 -> V_98 = V_2 -> V_58 ;
F_33 ( V_94 , V_2 -> V_57 , 0 , V_2 -> V_88 , 0 ) ;
F_64 ( & V_2 -> V_99 , 1 ) ;
F_65 ( & V_2 -> V_99 , V_94 , V_88 ) ;
V_2 -> V_57 = & V_2 -> V_99 ;
F_64 ( & V_2 -> V_100 , 1 ) ;
F_65 ( & V_2 -> V_100 , V_95 , V_88 ) ;
V_2 -> V_58 = & V_2 -> V_100 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_90 * V_19 )
{
if ( V_19 )
return F_67 ( V_2 -> V_91 , V_19 ) ;
return 0 ;
}
static int F_68 ( struct V_101 * V_91 ,
struct V_90 * V_19 )
{
struct V_34 * V_14 = F_69 (
F_49 ( V_19 ) ) ;
struct V_1 * V_2 = F_19 ( V_14 ) ;
struct V_102 * V_103 ;
int V_92 ;
if ( ! V_2 )
return - V_104 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_88 = V_19 -> V_51 ;
V_2 -> V_105 = V_19 -> V_51 ;
V_2 -> V_57 = V_19 -> V_106 ;
V_2 -> V_58 = V_19 -> V_107 ;
if ( F_57 ( V_2 -> V_57 , V_2 -> V_88 ) ||
F_57 ( V_2 -> V_58 , V_2 -> V_88 ) ) {
if ( F_60 ( V_2 ) )
F_31 ( L_14 ) ;
V_2 -> V_108 = 1 ;
} else {
V_2 -> V_108 = 0 ;
}
V_92 = F_61 ( V_2 -> V_88 , V_93 ) ;
V_2 -> V_59 = F_70 ( V_2 -> V_57 , V_92 ) ;
V_2 -> V_60 = F_70 ( V_2 -> V_58 , V_92 ) ;
F_71 ( V_2 -> V_59 < 0 || V_2 -> V_60 < 0 ) ;
V_103 = F_72 ( V_19 ) ;
V_14 = F_69 ( F_49 ( V_19 ) ) ;
V_103 -> V_109 &= V_110 ;
V_2 -> V_9 = ( V_2 -> V_9 & ~ V_110 ) | V_103 -> V_109 ;
V_2 -> V_14 = V_14 ;
V_14 -> V_2 = V_2 ;
return F_8 ( V_2 ) ;
}
static int F_73 ( struct V_101 * V_91 ,
struct V_90 * V_19 )
{
struct V_34 * V_14 = F_69 (
F_49 ( V_19 ) ) ;
struct V_1 * V_2 = F_19 ( V_14 ) ;
if ( ! V_2 )
return - V_104 ;
return F_47 ( V_2 ) ;
}
static void F_74 ( unsigned long V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 ;
void * V_94 , * V_95 ;
int V_96 , V_92 ;
F_50 ( L_15 ) ;
if ( ! V_2 -> V_67 ) {
F_41 ( V_2 -> V_43 , V_2 -> V_58 , V_2 -> V_60 ,
V_89 ) ;
F_52 ( V_2 -> V_43 , V_2 -> V_57 , V_2 -> V_59 , V_70 ) ;
F_52 ( V_2 -> V_43 , V_2 -> V_58 , V_2 -> V_60 ,
V_89 ) ;
F_55 ( V_2 ) ;
}
if ( V_2 -> V_108 ) {
V_94 = F_75 ( & V_2 -> V_99 ) ;
V_95 = F_75 ( & V_2 -> V_100 ) ;
F_33 ( V_95 , V_2 -> V_98 , 0 , V_2 -> V_105 , 1 ) ;
V_92 = F_61 ( V_2 -> V_105 , V_93 ) ;
V_96 = F_62 ( V_92 ) ;
F_76 ( ( unsigned long ) V_94 , V_96 ) ;
F_76 ( ( unsigned long ) V_95 , V_96 ) ;
}
F_53 ( V_2 , 0 ) ;
F_50 ( L_16 ) ;
}
static int F_77 ( struct V_90 * V_19 , unsigned long V_109 )
{
struct V_34 * V_14 = F_69 (
F_49 ( V_19 ) ) ;
struct V_102 * V_103 = F_72 ( V_19 ) ;
struct V_1 * V_2 ;
F_50 ( L_17 , V_19 -> V_51 ,
! ! ( V_109 & V_24 ) ,
! ! ( V_109 & V_17 ) ) ;
V_2 = F_19 ( V_14 ) ;
if ( ! V_2 )
return - V_104 ;
V_103 -> V_109 = V_109 ;
return F_66 ( V_2 , V_19 ) ;
}
static int F_78 ( struct V_111 * V_56 , const T_3 * V_16 ,
unsigned int V_15 )
{
struct V_34 * V_14 = F_69 ( V_56 ) ;
if ( V_15 != V_112 && V_15 != V_113 &&
V_15 != V_114 )
return - V_83 ;
F_50 ( L_18 , V_15 ) ;
memcpy ( V_14 -> V_16 , V_16 , V_15 ) ;
V_14 -> V_15 = V_15 ;
return 0 ;
}
static int F_79 ( struct V_90 * V_19 )
{
return F_77 ( V_19 , V_24 ) ;
}
static int F_80 ( struct V_90 * V_19 )
{
return F_77 ( V_19 , 0 ) ;
}
static int F_81 ( struct V_90 * V_19 )
{
return F_77 ( V_19 , V_24 | V_17 ) ;
}
static int F_82 ( struct V_90 * V_19 )
{
return F_77 ( V_19 , V_17 ) ;
}
static int F_83 ( struct V_90 * V_19 )
{
return F_77 ( V_19 , V_24 | V_18 ) ;
}
static int F_84 ( struct V_90 * V_19 )
{
return F_77 ( V_19 , V_18 ) ;
}
static int F_85 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = NULL ;
int V_11 ;
F_20 ( & V_36 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_36 ) ;
V_11 = F_86 ( V_2 -> V_43 ) ;
if ( V_11 < 0 ) {
F_29 ( V_2 -> V_43 , L_19 ,
V_115 , V_11 ) ;
return V_11 ;
}
V_56 -> V_116 . V_117 = sizeof( struct V_102 ) ;
return 0 ;
}
static void F_87 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = NULL ;
F_20 ( & V_36 ) ;
F_21 (dd, &dev_list, list) {
break;
}
F_22 ( & V_36 ) ;
F_88 ( V_2 -> V_43 ) ;
}
static T_4 F_89 ( int V_118 , void * V_119 )
{
struct V_1 * V_2 = V_119 ;
T_1 V_120 , V_13 ;
T_1 * V_106 , * V_107 ;
V_120 = F_1 ( V_2 , F_90 ( V_2 ) ) ;
if ( V_120 & V_121 ) {
F_3 ( V_2 , F_40 ( V_2 ) , 0x0 ) ;
F_71 ( ! V_2 -> V_57 ) ;
F_71 ( F_91 ( V_122 ) > V_2 -> V_57 -> V_27 ) ;
V_106 = F_75 ( V_2 -> V_57 ) + F_91 ( V_122 ) ;
for ( V_13 = 0 ; V_13 < V_123 ; V_13 ++ ) {
F_3 ( V_2 , F_42 ( V_2 , V_13 ) , * V_106 ) ;
F_35 ( & V_2 -> V_68 , 4 ) ;
if ( V_2 -> V_57 -> V_27 == F_91 ( V_122 ) ) {
V_2 -> V_57 = F_59 ( V_2 -> V_57 ) ;
if ( V_2 -> V_57 ) {
F_34 ( & V_2 -> V_68 ,
V_2 -> V_57 ) ;
V_106 = F_75 ( V_2 -> V_57 ) +
F_91 ( V_122 ) ;
}
} else {
V_106 ++ ;
}
}
V_120 &= ~ V_121 ;
F_3 ( V_2 , F_90 ( V_2 ) , V_120 ) ;
F_3 ( V_2 , F_40 ( V_2 ) , 0x4 ) ;
} else if ( V_120 & V_124 ) {
F_3 ( V_2 , F_40 ( V_2 ) , 0x0 ) ;
F_71 ( ! V_2 -> V_58 ) ;
F_71 ( F_91 ( V_52 ) > V_2 -> V_58 -> V_27 ) ;
V_107 = F_75 ( V_2 -> V_58 ) + F_91 ( V_52 ) ;
for ( V_13 = 0 ; V_13 < V_123 ; V_13 ++ ) {
* V_107 = F_1 ( V_2 , F_42 ( V_2 , V_13 ) ) ;
F_35 ( & V_2 -> V_69 , 4 ) ;
if ( V_2 -> V_58 -> V_27 == F_91 ( V_52 ) ) {
V_2 -> V_58 = F_59 ( V_2 -> V_58 ) ;
if ( V_2 -> V_58 ) {
F_34 ( & V_2 -> V_69 ,
V_2 -> V_58 ) ;
V_107 = F_75 ( V_2 -> V_58 ) +
F_91 ( V_52 ) ;
}
} else {
V_107 ++ ;
}
}
V_2 -> V_88 -= F_92 ( V_125 , V_93 , V_2 -> V_88 ) ;
V_120 &= ~ V_124 ;
F_3 ( V_2 , F_90 ( V_2 ) , V_120 ) ;
if ( ! V_2 -> V_88 )
F_24 ( & V_2 -> V_38 ) ;
else
F_3 ( V_2 , F_40 ( V_2 ) , 0x2 ) ;
}
return V_126 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_127 * V_43 , struct V_128 * V_129 )
{
struct V_130 * V_131 = V_43 -> V_132 ;
const struct V_133 * V_134 ;
int V_11 = 0 ;
V_134 = F_94 ( F_95 ( V_135 ) , V_43 ) ;
if ( ! V_134 ) {
F_29 ( V_43 , L_20 ) ;
V_11 = - V_83 ;
goto V_11;
}
V_11 = F_96 ( V_131 , 0 , V_129 ) ;
if ( V_11 < 0 ) {
F_29 ( V_43 , L_21 ) ;
V_11 = - V_83 ;
goto V_11;
}
V_2 -> V_45 = - 1 ;
V_2 -> V_42 = - 1 ;
V_2 -> V_28 = V_134 -> V_37 ;
V_11:
return V_11 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_127 * V_43 , struct V_128 * V_129 )
{
return - V_83 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_136 * V_137 , struct V_128 * V_129 )
{
struct V_127 * V_43 = & V_137 -> V_43 ;
struct V_128 * V_138 ;
int V_11 = 0 ;
V_138 = F_98 ( V_137 , V_139 , 0 ) ;
if ( ! V_138 ) {
F_29 ( V_43 , L_22 ) ;
V_11 = - V_104 ;
goto V_11;
}
memcpy ( V_129 , V_138 , sizeof( * V_129 ) ) ;
V_138 = F_98 ( V_137 , V_140 , 0 ) ;
if ( ! V_138 ) {
F_29 ( V_43 , L_23 ) ;
V_11 = - V_104 ;
goto V_11;
}
V_2 -> V_45 = V_138 -> V_50 ;
V_138 = F_98 ( V_137 , V_140 , 1 ) ;
if ( ! V_138 ) {
F_29 ( V_43 , L_24 ) ;
V_11 = - V_104 ;
goto V_11;
}
V_2 -> V_42 = V_138 -> V_50 ;
V_2 -> V_28 = & V_141 ;
V_11:
return V_11 ;
}
static int F_99 ( struct V_136 * V_137 )
{
struct V_127 * V_43 = & V_137 -> V_43 ;
struct V_1 * V_2 ;
struct V_142 * V_143 ;
struct V_128 V_129 ;
int V_11 = - V_39 , V_13 , V_144 , V_118 = - 1 ;
T_1 V_145 ;
V_2 = F_100 ( V_43 , sizeof( struct V_1 ) , V_146 ) ;
if ( V_2 == NULL ) {
F_29 ( V_43 , L_25 ) ;
goto V_147;
}
V_2 -> V_43 = V_43 ;
F_101 ( V_137 , V_2 ) ;
V_11 = ( V_43 -> V_132 ) ? F_93 ( V_2 , V_43 , & V_129 ) :
F_97 ( V_2 , V_137 , & V_129 ) ;
if ( V_11 )
goto V_148;
V_2 -> V_4 = F_102 ( V_43 , & V_129 ) ;
if ( F_103 ( V_2 -> V_4 ) ) {
V_11 = F_104 ( V_2 -> V_4 ) ;
goto V_148;
}
V_2 -> V_72 = V_129 . V_50 ;
F_105 ( V_43 ) ;
V_11 = F_86 ( V_43 ) ;
if ( V_11 < 0 ) {
F_29 ( V_43 , L_19 ,
V_115 , V_11 ) ;
goto V_148;
}
F_18 ( V_2 ) ;
V_145 = F_1 ( V_2 , F_106 ( V_2 ) ) ;
F_88 ( V_43 ) ;
F_107 ( V_43 , L_26 ,
( V_145 & V_2 -> V_28 -> V_149 ) >> V_2 -> V_28 -> V_150 ,
( V_145 & V_2 -> V_28 -> V_151 ) >> V_2 -> V_28 -> V_152 ) ;
F_108 ( & V_2 -> V_38 , F_74 , ( unsigned long ) V_2 ) ;
V_11 = F_25 ( V_2 ) ;
if ( V_11 && F_90 ( V_2 ) && F_40 ( V_2 ) ) {
V_2 -> V_67 = 1 ;
V_118 = F_109 ( V_137 , 0 ) ;
if ( V_118 < 0 ) {
F_29 ( V_43 , L_27 ) ;
goto V_153;
}
V_11 = F_110 ( V_43 , V_118 , F_89 , 0 ,
F_111 ( V_43 ) , V_2 ) ;
if ( V_11 ) {
F_29 ( V_43 , L_28 ) ;
goto V_153;
}
}
F_112 ( & V_2 -> V_154 ) ;
F_113 ( & V_36 ) ;
F_114 ( & V_2 -> V_154 , & V_155 ) ;
F_115 ( & V_36 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_28 -> V_156 ; V_13 ++ ) {
for ( V_144 = 0 ; V_144 < V_2 -> V_28 -> V_157 [ V_13 ] . V_158 ; V_144 ++ ) {
V_143 = & V_2 -> V_28 -> V_157 [ V_13 ] . V_159 [ V_144 ] ;
F_50 ( L_29 , V_143 -> V_160 ) ;
F_112 ( & V_143 -> V_161 ) ;
V_11 = F_116 ( V_143 ) ;
if ( V_11 )
goto V_162;
V_2 -> V_28 -> V_157 [ V_13 ] . V_163 ++ ;
}
}
V_2 -> V_91 = F_117 ( V_43 , 1 ) ;
if ( ! V_2 -> V_91 )
goto V_162;
V_2 -> V_91 -> V_164 = F_68 ;
V_2 -> V_91 -> V_165 = F_73 ;
V_11 = F_118 ( V_2 -> V_91 ) ;
if ( V_11 )
goto V_166;
return 0 ;
V_166:
F_119 ( V_2 -> V_91 ) ;
V_162:
for ( V_13 = V_2 -> V_28 -> V_156 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_144 = V_2 -> V_28 -> V_157 [ V_13 ] . V_163 - 1 ; V_144 >= 0 ; V_144 -- )
F_120 (
& V_2 -> V_28 -> V_157 [ V_13 ] . V_159 [ V_144 ] ) ;
if ( ! V_2 -> V_67 )
F_32 ( V_2 ) ;
V_153:
F_121 ( & V_2 -> V_38 ) ;
F_122 ( V_43 ) ;
V_148:
V_2 = NULL ;
V_147:
F_29 ( V_43 , L_30 ) ;
return V_11 ;
}
static int F_123 ( struct V_136 * V_137 )
{
struct V_1 * V_2 = F_124 ( V_137 ) ;
int V_13 , V_144 ;
if ( ! V_2 )
return - V_104 ;
F_113 ( & V_36 ) ;
F_125 ( & V_2 -> V_154 ) ;
F_115 ( & V_36 ) ;
for ( V_13 = V_2 -> V_28 -> V_156 - 1 ; V_13 >= 0 ; V_13 -- )
for ( V_144 = V_2 -> V_28 -> V_157 [ V_13 ] . V_163 - 1 ; V_144 >= 0 ; V_144 -- )
F_120 (
& V_2 -> V_28 -> V_157 [ V_13 ] . V_159 [ V_144 ] ) ;
F_119 ( V_2 -> V_91 ) ;
F_121 ( & V_2 -> V_38 ) ;
F_32 ( V_2 ) ;
F_122 ( V_2 -> V_43 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_126 ( struct V_127 * V_43 )
{
F_88 ( V_43 ) ;
return 0 ;
}
static int F_127 ( struct V_127 * V_43 )
{
F_86 ( V_43 ) ;
return 0 ;
}
