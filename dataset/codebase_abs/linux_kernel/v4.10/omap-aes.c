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
static int F_10 ( struct V_1 * V_2 )
{
unsigned int V_13 ;
int V_14 , V_9 ;
T_1 V_7 ;
V_9 = F_7 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_13 = V_2 -> V_15 -> V_16 / sizeof( T_1 ) ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
F_3 ( V_2 , F_11 ( V_2 , V_14 ) ,
F_12 ( V_2 -> V_15 -> V_17 [ V_14 ] ) ) ;
}
if ( ( V_2 -> V_10 & ( V_18 | V_19 ) ) && V_2 -> V_20 -> V_21 )
F_6 ( V_2 , F_13 ( V_2 , 0 ) , V_2 -> V_20 -> V_21 , 4 ) ;
V_7 = F_14 ( ( ( V_2 -> V_15 -> V_16 >> 3 ) - 1 ) , 4 , 3 ) ;
if ( V_2 -> V_10 & V_18 )
V_7 |= V_22 ;
if ( V_2 -> V_10 & V_19 )
V_7 |= V_23 | V_24 ;
if ( V_2 -> V_10 & V_25 )
V_7 |= V_26 ;
F_5 ( V_2 , F_15 ( V_2 ) , V_7 , V_27 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , int V_28 )
{
T_1 V_6 , V_7 ;
V_7 = V_2 -> V_29 -> V_30 ;
if ( V_2 -> V_31 != NULL )
V_7 |= V_2 -> V_29 -> V_32 ;
if ( V_2 -> V_33 != NULL )
V_7 |= V_2 -> V_29 -> V_34 ;
V_6 = V_2 -> V_29 -> V_32 | V_2 -> V_29 -> V_34 |
V_2 -> V_29 -> V_30 ;
F_5 ( V_2 , F_17 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_28 )
{
F_3 ( V_2 , F_19 ( 0 ) , V_28 ) ;
F_3 ( V_2 , F_19 ( 1 ) , 0 ) ;
F_16 ( V_2 , V_28 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_29 -> V_32 | V_2 -> V_29 -> V_34 |
V_2 -> V_29 -> V_30 ;
F_5 ( V_2 , F_17 ( V_2 ) , 0 , V_6 ) ;
}
static struct V_1 * F_21 ( struct V_35 * V_15 )
{
struct V_1 * V_2 ;
F_22 ( & V_36 ) ;
V_2 = F_23 ( & V_37 , struct V_1 , V_38 ) ;
F_24 ( & V_2 -> V_38 , & V_37 ) ;
V_15 -> V_2 = V_2 ;
F_25 ( & V_36 ) ;
return V_2 ;
}
static void F_26 ( void * V_39 )
{
struct V_1 * V_2 = V_39 ;
F_27 ( & V_2 -> V_40 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_9 ;
V_2 -> V_31 = NULL ;
V_2 -> V_33 = NULL ;
V_2 -> V_33 = F_29 ( V_2 -> V_12 , L_2 ) ;
if ( F_30 ( V_2 -> V_33 ) ) {
F_9 ( V_2 -> V_12 , L_3 ) ;
return F_31 ( V_2 -> V_33 ) ;
}
V_2 -> V_31 = F_29 ( V_2 -> V_12 , L_4 ) ;
if ( F_30 ( V_2 -> V_31 ) ) {
F_9 ( V_2 -> V_12 , L_5 ) ;
V_9 = F_31 ( V_2 -> V_31 ) ;
goto V_41;
}
return 0 ;
V_41:
F_32 ( V_2 -> V_33 ) ;
return V_9 ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 )
return;
F_32 ( V_2 -> V_31 ) ;
F_32 ( V_2 -> V_33 ) ;
}
static void F_34 ( void * V_43 , struct V_44 * V_45 ,
unsigned int V_46 , unsigned int V_47 , int V_48 )
{
struct V_49 V_50 ;
if ( ! V_47 )
return;
F_35 ( & V_50 , V_45 ) ;
F_36 ( & V_50 , V_46 ) ;
F_37 ( V_43 , & V_50 , V_47 , V_48 ) ;
F_38 ( & V_50 , V_48 , 0 ) ;
}
static int F_39 ( struct V_51 * V_52 ,
struct V_44 * V_53 , struct V_44 * V_54 ,
int V_55 , int V_56 )
{
struct V_35 * V_15 = F_40 ( V_52 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_57 * V_58 , * V_59 ;
struct V_60 V_61 ;
int V_62 ;
if ( V_2 -> V_42 ) {
F_35 ( & V_2 -> V_63 , V_2 -> V_53 ) ;
F_35 ( & V_2 -> V_64 , V_2 -> V_54 ) ;
F_3 ( V_2 , F_41 ( V_2 ) , 0x2 ) ;
return 0 ;
}
F_42 ( V_2 -> V_12 , V_2 -> V_53 , V_55 , V_65 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_2 -> V_67 + F_43 ( V_2 , 0 ) ;
V_61 . V_68 = V_2 -> V_67 + F_43 ( V_2 , 0 ) ;
V_61 . V_69 = V_70 ;
V_61 . V_71 = V_70 ;
V_61 . V_72 = V_73 ;
V_61 . V_74 = V_73 ;
V_62 = F_44 ( V_2 -> V_33 , & V_61 ) ;
if ( V_62 ) {
F_9 ( V_2 -> V_12 , L_6 ,
V_62 ) ;
return V_62 ;
}
V_58 = F_45 ( V_2 -> V_33 , V_53 , V_55 ,
V_75 ,
V_76 | V_77 ) ;
if ( ! V_58 ) {
F_9 ( V_2 -> V_12 , L_7 ) ;
return - V_78 ;
}
V_58 -> V_79 = V_2 ;
V_62 = F_44 ( V_2 -> V_31 , & V_61 ) ;
if ( V_62 ) {
F_9 ( V_2 -> V_12 , L_8 ,
V_62 ) ;
return V_62 ;
}
V_59 = F_45 ( V_2 -> V_31 , V_54 , V_56 ,
V_80 ,
V_76 | V_77 ) ;
if ( ! V_59 ) {
F_9 ( V_2 -> V_12 , L_9 ) ;
return - V_78 ;
}
V_59 -> V_81 = F_26 ;
V_59 -> V_79 = V_2 ;
F_46 ( V_58 ) ;
F_46 ( V_59 ) ;
F_47 ( V_2 -> V_33 ) ;
F_47 ( V_2 -> V_31 ) ;
V_2 -> V_29 -> V_82 ( V_2 , V_2 -> V_83 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_49 (
F_50 ( V_2 -> V_20 ) ) ;
int V_9 ;
F_51 ( L_10 , V_2 -> V_83 ) ;
if ( ! V_2 -> V_42 ) {
V_9 = F_52 ( V_2 -> V_12 , V_2 -> V_53 , V_2 -> V_55 ,
V_65 ) ;
if ( ! V_9 ) {
F_9 ( V_2 -> V_12 , L_11 ) ;
return - V_78 ;
}
V_9 = F_52 ( V_2 -> V_12 , V_2 -> V_54 , V_2 -> V_56 ,
V_84 ) ;
if ( ! V_9 ) {
F_9 ( V_2 -> V_12 , L_11 ) ;
return - V_78 ;
}
}
V_9 = F_39 ( V_52 , V_2 -> V_53 , V_2 -> V_54 , V_2 -> V_55 ,
V_2 -> V_56 ) ;
if ( V_9 && ! V_2 -> V_42 ) {
F_53 ( V_2 -> V_12 , V_2 -> V_53 , V_2 -> V_55 , V_65 ) ;
F_53 ( V_2 -> V_12 , V_2 -> V_54 , V_2 -> V_56 ,
V_84 ) ;
}
return V_9 ;
}
static void F_54 ( struct V_1 * V_2 , int V_9 )
{
struct V_85 * V_20 = V_2 -> V_20 ;
F_51 ( L_12 , V_9 ) ;
F_55 ( V_2 -> V_86 , V_20 , V_9 ) ;
F_56 ( V_2 -> V_12 ) ;
F_57 ( V_2 -> V_12 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
F_51 ( L_10 , V_2 -> V_83 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_44 * V_45 , int V_83 )
{
int V_87 = 0 ;
if ( ! F_60 ( V_83 , V_88 ) )
return - V_78 ;
while ( V_45 ) {
if ( ! F_60 ( V_45 -> V_3 , 4 ) )
return - 1 ;
if ( ! F_60 ( V_45 -> V_28 , V_88 ) )
return - 1 ;
V_87 += V_45 -> V_28 ;
V_45 = F_61 ( V_45 ) ;
}
if ( V_87 != V_83 )
return - 1 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
void * V_89 , * V_90 ;
int V_91 , V_83 ;
V_83 = F_63 ( V_2 -> V_83 , V_88 ) ;
V_91 = F_64 ( V_83 ) ;
V_89 = ( void * ) F_65 ( V_92 , V_91 ) ;
V_90 = ( void * ) F_65 ( V_92 , V_91 ) ;
if ( ! V_89 || ! V_90 ) {
F_66 ( L_13 ) ;
return - 1 ;
}
V_2 -> V_93 = V_2 -> V_54 ;
F_34 ( V_89 , V_2 -> V_53 , 0 , V_2 -> V_83 , 0 ) ;
F_67 ( & V_2 -> V_94 , 1 ) ;
F_68 ( & V_2 -> V_94 , V_89 , V_83 ) ;
V_2 -> V_53 = & V_2 -> V_94 ;
V_2 -> V_55 = 1 ;
F_67 ( & V_2 -> V_95 , 1 ) ;
F_68 ( & V_2 -> V_95 , V_90 , V_83 ) ;
V_2 -> V_54 = & V_2 -> V_95 ;
V_2 -> V_56 = 1 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_85 * V_20 )
{
if ( V_20 )
return F_70 ( V_2 -> V_86 , V_20 ) ;
return 0 ;
}
static int F_71 ( struct V_96 * V_86 ,
struct V_85 * V_20 )
{
struct V_35 * V_15 = F_72 (
F_50 ( V_20 ) ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_97 * V_98 ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_83 = V_20 -> V_47 ;
V_2 -> V_100 = V_20 -> V_47 ;
V_2 -> V_53 = V_20 -> V_101 ;
V_2 -> V_54 = V_20 -> V_102 ;
V_2 -> V_55 = F_73 ( V_2 -> V_53 , V_2 -> V_83 ) ;
if ( V_2 -> V_55 < 0 )
return V_2 -> V_55 ;
V_2 -> V_56 = F_73 ( V_2 -> V_54 , V_2 -> V_83 ) ;
if ( V_2 -> V_56 < 0 )
return V_2 -> V_56 ;
if ( F_59 ( V_2 -> V_53 , V_2 -> V_83 ) ||
F_59 ( V_2 -> V_54 , V_2 -> V_83 ) ) {
if ( F_62 ( V_2 ) )
F_66 ( L_14 ) ;
V_2 -> V_103 = 1 ;
} else {
V_2 -> V_103 = 0 ;
}
V_98 = F_74 ( V_20 ) ;
V_15 = F_72 ( F_50 ( V_20 ) ) ;
V_98 -> V_104 &= V_105 ;
V_2 -> V_10 = ( V_2 -> V_10 & ~ V_105 ) | V_98 -> V_104 ;
V_2 -> V_15 = V_15 ;
V_15 -> V_2 = V_2 ;
return F_10 ( V_2 ) ;
}
static int F_75 ( struct V_96 * V_86 ,
struct V_85 * V_20 )
{
struct V_35 * V_15 = F_72 (
F_50 ( V_20 ) ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( ! V_2 )
return - V_99 ;
return F_48 ( V_2 ) ;
}
static void F_76 ( unsigned long V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_39 ;
void * V_89 , * V_90 ;
int V_91 , V_87 ;
F_51 ( L_15 ) ;
if ( ! V_2 -> V_42 ) {
F_42 ( V_2 -> V_12 , V_2 -> V_54 , V_2 -> V_56 ,
V_84 ) ;
F_53 ( V_2 -> V_12 , V_2 -> V_53 , V_2 -> V_55 , V_65 ) ;
F_53 ( V_2 -> V_12 , V_2 -> V_54 , V_2 -> V_56 ,
V_84 ) ;
F_58 ( V_2 ) ;
}
if ( V_2 -> V_103 ) {
V_89 = F_77 ( & V_2 -> V_94 ) ;
V_90 = F_77 ( & V_2 -> V_95 ) ;
F_34 ( V_90 , V_2 -> V_93 , 0 , V_2 -> V_100 , 1 ) ;
V_87 = F_63 ( V_2 -> V_100 , V_88 ) ;
V_91 = F_64 ( V_87 ) ;
F_78 ( ( unsigned long ) V_89 , V_91 ) ;
F_78 ( ( unsigned long ) V_90 , V_91 ) ;
}
F_54 ( V_2 , 0 ) ;
F_51 ( L_16 ) ;
}
static int F_79 ( struct V_85 * V_20 , unsigned long V_104 )
{
struct V_35 * V_15 = F_72 (
F_50 ( V_20 ) ) ;
struct V_97 * V_98 = F_74 ( V_20 ) ;
struct V_1 * V_2 ;
int V_62 ;
F_51 ( L_17 , V_20 -> V_47 ,
! ! ( V_104 & V_25 ) ,
! ! ( V_104 & V_18 ) ) ;
if ( V_20 -> V_47 < 200 ) {
F_80 ( V_106 , V_15 -> V_107 ) ;
F_81 ( V_106 , V_15 -> V_107 ) ;
F_82 ( V_106 , V_20 -> V_108 . V_10 , NULL ,
NULL ) ;
F_83 ( V_106 , V_20 -> V_101 , V_20 -> V_102 ,
V_20 -> V_47 , V_20 -> V_21 ) ;
if ( V_104 & V_25 )
V_62 = F_84 ( V_106 ) ;
else
V_62 = F_85 ( V_106 ) ;
F_86 ( V_106 ) ;
return V_62 ;
}
V_2 = F_21 ( V_15 ) ;
if ( ! V_2 )
return - V_99 ;
V_98 -> V_104 = V_104 ;
return F_69 ( V_2 , V_20 ) ;
}
static int F_87 ( struct V_109 * V_52 , const T_2 * V_17 ,
unsigned int V_16 )
{
struct V_35 * V_15 = F_72 ( V_52 ) ;
int V_62 ;
if ( V_16 != V_110 && V_16 != V_111 &&
V_16 != V_112 )
return - V_78 ;
F_51 ( L_18 , V_16 ) ;
memcpy ( V_15 -> V_17 , V_17 , V_16 ) ;
V_15 -> V_16 = V_16 ;
F_88 ( V_15 -> V_107 , V_113 ) ;
F_89 ( V_15 -> V_107 , V_52 -> V_108 . V_114 &
V_113 ) ;
V_62 = F_90 ( V_15 -> V_107 , V_17 , V_16 ) ;
if ( ! V_62 )
return 0 ;
return 0 ;
}
static int F_91 ( struct V_85 * V_20 )
{
return F_79 ( V_20 , V_25 ) ;
}
static int F_92 ( struct V_85 * V_20 )
{
return F_79 ( V_20 , 0 ) ;
}
static int F_93 ( struct V_85 * V_20 )
{
return F_79 ( V_20 , V_25 | V_18 ) ;
}
static int F_94 ( struct V_85 * V_20 )
{
return F_79 ( V_20 , V_18 ) ;
}
static int F_95 ( struct V_85 * V_20 )
{
return F_79 ( V_20 , V_25 | V_19 ) ;
}
static int F_96 ( struct V_85 * V_20 )
{
return F_79 ( V_20 , V_19 ) ;
}
static int F_97 ( struct V_51 * V_52 )
{
const char * V_115 = F_98 ( V_52 ) ;
const T_1 V_10 = V_116 | V_117 ;
struct V_35 * V_15 = F_40 ( V_52 ) ;
struct V_118 * V_119 ;
V_119 = F_99 ( V_115 , 0 , V_10 ) ;
if ( F_30 ( V_119 ) )
return F_31 ( V_119 ) ;
V_15 -> V_107 = V_119 ;
V_52 -> V_120 . V_121 = sizeof( struct V_97 ) ;
return 0 ;
}
static void F_100 ( struct V_51 * V_52 )
{
struct V_35 * V_15 = F_40 ( V_52 ) ;
if ( V_15 -> V_107 )
F_101 ( V_15 -> V_107 ) ;
V_15 -> V_107 = NULL ;
}
static T_3 F_102 ( int V_122 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
T_1 V_124 , V_14 ;
T_1 * V_101 , * V_102 ;
V_124 = F_1 ( V_2 , F_103 ( V_2 ) ) ;
if ( V_124 & V_125 ) {
F_3 ( V_2 , F_41 ( V_2 ) , 0x0 ) ;
F_104 ( ! V_2 -> V_53 ) ;
F_104 ( F_105 ( V_126 ) > V_2 -> V_53 -> V_28 ) ;
V_101 = F_77 ( V_2 -> V_53 ) + F_105 ( V_126 ) ;
for ( V_14 = 0 ; V_14 < V_127 ; V_14 ++ ) {
F_3 ( V_2 , F_43 ( V_2 , V_14 ) , * V_101 ) ;
F_36 ( & V_2 -> V_63 , 4 ) ;
if ( V_2 -> V_53 -> V_28 == F_105 ( V_126 ) ) {
V_2 -> V_53 = F_61 ( V_2 -> V_53 ) ;
if ( V_2 -> V_53 ) {
F_35 ( & V_2 -> V_63 ,
V_2 -> V_53 ) ;
V_101 = F_77 ( V_2 -> V_53 ) +
F_105 ( V_126 ) ;
}
} else {
V_101 ++ ;
}
}
V_124 &= ~ V_125 ;
F_3 ( V_2 , F_103 ( V_2 ) , V_124 ) ;
F_3 ( V_2 , F_41 ( V_2 ) , 0x4 ) ;
} else if ( V_124 & V_128 ) {
F_3 ( V_2 , F_41 ( V_2 ) , 0x0 ) ;
F_104 ( ! V_2 -> V_54 ) ;
F_104 ( F_105 ( V_48 ) > V_2 -> V_54 -> V_28 ) ;
V_102 = F_77 ( V_2 -> V_54 ) + F_105 ( V_48 ) ;
for ( V_14 = 0 ; V_14 < V_127 ; V_14 ++ ) {
* V_102 = F_1 ( V_2 , F_43 ( V_2 , V_14 ) ) ;
F_36 ( & V_2 -> V_64 , 4 ) ;
if ( V_2 -> V_54 -> V_28 == F_105 ( V_48 ) ) {
V_2 -> V_54 = F_61 ( V_2 -> V_54 ) ;
if ( V_2 -> V_54 ) {
F_35 ( & V_2 -> V_64 ,
V_2 -> V_54 ) ;
V_102 = F_77 ( V_2 -> V_54 ) +
F_105 ( V_48 ) ;
}
} else {
V_102 ++ ;
}
}
V_2 -> V_83 -= F_106 ( V_129 , V_88 , V_2 -> V_83 ) ;
V_124 &= ~ V_128 ;
F_3 ( V_2 , F_103 ( V_2 ) , V_124 ) ;
if ( ! V_2 -> V_83 )
F_27 ( & V_2 -> V_40 ) ;
else
F_3 ( V_2 , F_41 ( V_2 ) , 0x2 ) ;
}
return V_130 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_131 * V_12 , struct V_132 * V_133 )
{
struct V_134 * V_135 = V_12 -> V_136 ;
const struct V_137 * V_138 ;
int V_9 = 0 ;
V_138 = F_108 ( F_109 ( V_139 ) , V_12 ) ;
if ( ! V_138 ) {
F_9 ( V_12 , L_19 ) ;
V_9 = - V_78 ;
goto V_9;
}
V_9 = F_110 ( V_135 , 0 , V_133 ) ;
if ( V_9 < 0 ) {
F_9 ( V_12 , L_20 ) ;
V_9 = - V_78 ;
goto V_9;
}
V_2 -> V_29 = V_138 -> V_39 ;
V_9:
return V_9 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_131 * V_12 , struct V_132 * V_133 )
{
return - V_78 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_140 * V_141 , struct V_132 * V_133 )
{
struct V_131 * V_12 = & V_141 -> V_12 ;
struct V_132 * V_142 ;
int V_9 = 0 ;
V_142 = F_112 ( V_141 , V_143 , 0 ) ;
if ( ! V_142 ) {
F_9 ( V_12 , L_21 ) ;
V_9 = - V_99 ;
goto V_9;
}
memcpy ( V_133 , V_142 , sizeof( * V_133 ) ) ;
V_2 -> V_29 = & V_144 ;
V_9:
return V_9 ;
}
static int F_113 ( struct V_140 * V_141 )
{
struct V_131 * V_12 = & V_141 -> V_12 ;
struct V_1 * V_2 ;
struct V_145 * V_146 ;
struct V_132 V_133 ;
int V_9 = - V_147 , V_14 , V_148 , V_122 = - 1 ;
T_1 V_149 ;
V_2 = F_114 ( V_12 , sizeof( struct V_1 ) , V_150 ) ;
if ( V_2 == NULL ) {
F_9 ( V_12 , L_22 ) ;
goto V_151;
}
V_2 -> V_12 = V_12 ;
F_115 ( V_141 , V_2 ) ;
V_9 = ( V_12 -> V_136 ) ? F_107 ( V_2 , V_12 , & V_133 ) :
F_111 ( V_2 , V_141 , & V_133 ) ;
if ( V_9 )
goto V_152;
V_2 -> V_4 = F_116 ( V_12 , & V_133 ) ;
if ( F_30 ( V_2 -> V_4 ) ) {
V_9 = F_31 ( V_2 -> V_4 ) ;
goto V_152;
}
V_2 -> V_67 = V_133 . V_46 ;
F_117 ( V_12 ) ;
F_118 ( V_12 , V_153 ) ;
F_119 ( V_12 ) ;
V_9 = F_8 ( V_12 ) ;
if ( V_9 < 0 ) {
F_9 ( V_12 , L_23 ,
V_154 , V_9 ) ;
goto V_152;
}
F_20 ( V_2 ) ;
V_149 = F_1 ( V_2 , F_120 ( V_2 ) ) ;
F_121 ( V_12 ) ;
F_122 ( V_12 , L_24 ,
( V_149 & V_2 -> V_29 -> V_155 ) >> V_2 -> V_29 -> V_156 ,
( V_149 & V_2 -> V_29 -> V_157 ) >> V_2 -> V_29 -> V_158 ) ;
F_123 ( & V_2 -> V_40 , F_76 , ( unsigned long ) V_2 ) ;
V_9 = F_28 ( V_2 ) ;
if ( V_9 == - V_159 ) {
goto V_160;
} else if ( V_9 && F_103 ( V_2 ) && F_41 ( V_2 ) ) {
V_2 -> V_42 = 1 ;
V_122 = F_124 ( V_141 , 0 ) ;
if ( V_122 < 0 ) {
F_9 ( V_12 , L_25 ) ;
goto V_160;
}
V_9 = F_125 ( V_12 , V_122 , F_102 , 0 ,
F_126 ( V_12 ) , V_2 ) ;
if ( V_9 ) {
F_9 ( V_12 , L_26 ) ;
goto V_160;
}
}
F_127 ( & V_2 -> V_38 ) ;
F_128 ( & V_36 ) ;
F_129 ( & V_2 -> V_38 , & V_37 ) ;
F_130 ( & V_36 ) ;
V_2 -> V_86 = F_131 ( V_12 , 1 ) ;
if ( ! V_2 -> V_86 ) {
V_9 = - V_147 ;
goto V_161;
}
V_2 -> V_86 -> V_162 = F_71 ;
V_2 -> V_86 -> V_163 = F_75 ;
V_9 = F_132 ( V_2 -> V_86 ) ;
if ( V_9 )
goto V_161;
for ( V_14 = 0 ; V_14 < V_2 -> V_29 -> V_164 ; V_14 ++ ) {
if ( ! V_2 -> V_29 -> V_165 [ V_14 ] . V_166 ) {
for ( V_148 = 0 ; V_148 < V_2 -> V_29 -> V_165 [ V_14 ] . V_167 ; V_148 ++ ) {
V_146 = & V_2 -> V_29 -> V_165 [ V_14 ] . V_168 [ V_148 ] ;
F_51 ( L_27 , V_146 -> V_169 ) ;
F_127 ( & V_146 -> V_170 ) ;
V_9 = F_133 ( V_146 ) ;
if ( V_9 )
goto V_171;
V_2 -> V_29 -> V_165 [ V_14 ] . V_166 ++ ;
}
}
}
return 0 ;
V_171:
for ( V_14 = V_2 -> V_29 -> V_164 - 1 ; V_14 >= 0 ; V_14 -- )
for ( V_148 = V_2 -> V_29 -> V_165 [ V_14 ] . V_166 - 1 ; V_148 >= 0 ; V_148 -- )
F_134 (
& V_2 -> V_29 -> V_165 [ V_14 ] . V_168 [ V_148 ] ) ;
V_161:
if ( V_2 -> V_86 )
F_135 ( V_2 -> V_86 ) ;
F_33 ( V_2 ) ;
V_160:
F_136 ( & V_2 -> V_40 ) ;
F_137 ( V_12 ) ;
V_152:
V_2 = NULL ;
V_151:
F_9 ( V_12 , L_28 ) ;
return V_9 ;
}
static int F_138 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_139 ( V_141 ) ;
int V_14 , V_148 ;
if ( ! V_2 )
return - V_99 ;
F_128 ( & V_36 ) ;
F_140 ( & V_2 -> V_38 ) ;
F_130 ( & V_36 ) ;
for ( V_14 = V_2 -> V_29 -> V_164 - 1 ; V_14 >= 0 ; V_14 -- )
for ( V_148 = V_2 -> V_29 -> V_165 [ V_14 ] . V_166 - 1 ; V_148 >= 0 ; V_148 -- )
F_134 (
& V_2 -> V_29 -> V_165 [ V_14 ] . V_168 [ V_148 ] ) ;
F_135 ( V_2 -> V_86 ) ;
F_136 ( & V_2 -> V_40 ) ;
F_33 ( V_2 ) ;
F_137 ( V_2 -> V_12 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_141 ( struct V_131 * V_12 )
{
F_121 ( V_12 ) ;
return 0 ;
}
static int F_142 ( struct V_131 * V_12 )
{
F_8 ( V_12 ) ;
return 0 ;
}
