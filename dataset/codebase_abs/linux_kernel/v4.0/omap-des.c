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
V_9 = F_8 ( V_2 -> V_10 ) ;
if ( V_9 < 0 ) {
F_9 ( V_2 -> V_10 ) ;
F_10 ( V_2 -> V_10 , L_1 , V_11 , V_9 ) ;
return V_9 ;
}
if ( ! ( V_2 -> V_12 & V_13 ) ) {
V_2 -> V_12 |= V_13 ;
V_2 -> V_9 = 0 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned int V_14 ;
int V_15 , V_9 ;
T_1 V_7 = 0 , V_6 = 0 ;
V_9 = F_7 ( V_2 ) ;
if ( V_9 )
return V_9 ;
V_14 = V_2 -> V_16 -> V_17 / sizeof( T_1 ) ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
F_3 ( V_2 , F_12 ( V_2 , V_15 ) ,
F_13 ( V_2 -> V_16 -> V_18 [ V_15 ] ) ) ;
}
if ( ( V_2 -> V_12 & V_19 ) && V_2 -> V_20 -> V_21 )
F_6 ( V_2 , F_14 ( V_2 , 0 ) , V_2 -> V_20 -> V_21 , 2 ) ;
if ( V_2 -> V_12 & V_19 )
V_7 |= V_22 ;
if ( V_2 -> V_12 & V_23 )
V_7 |= V_24 ;
if ( V_14 == 6 )
V_7 |= V_25 ;
V_6 |= V_22 | V_24 | V_25 ;
F_5 ( V_2 , F_15 ( V_2 ) , V_7 , V_6 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , int V_26 )
{
T_1 V_6 , V_7 ;
F_3 ( V_2 , F_17 ( 0 ) , V_26 ) ;
V_7 = V_2 -> V_27 -> V_28 ;
if ( V_2 -> V_29 != NULL )
V_7 |= V_2 -> V_27 -> V_30 ;
if ( V_2 -> V_31 != NULL )
V_7 |= V_2 -> V_27 -> V_32 ;
V_6 = V_2 -> V_27 -> V_30 | V_2 -> V_27 -> V_32 |
V_2 -> V_27 -> V_28 ;
F_5 ( V_2 , F_18 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_27 -> V_30 | V_2 -> V_27 -> V_32 |
V_2 -> V_27 -> V_28 ;
F_5 ( V_2 , F_18 ( V_2 ) , 0 , V_6 ) ;
}
static struct V_1 * F_20 ( struct V_33 * V_16 )
{
struct V_1 * V_2 = NULL , * V_34 ;
F_21 ( & V_35 ) ;
if ( ! V_16 -> V_2 ) {
F_22 (tmp, &dev_list, list) {
V_2 = V_34 ;
break;
}
V_16 -> V_2 = V_2 ;
} else {
V_2 = V_16 -> V_2 ;
}
F_23 ( & V_35 ) ;
return V_2 ;
}
static void F_24 ( void * V_36 )
{
struct V_1 * V_2 = V_36 ;
F_25 ( & V_2 -> V_37 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_9 = - V_38 ;
T_2 V_6 ;
V_2 -> V_29 = NULL ;
V_2 -> V_31 = NULL ;
F_27 ( V_6 ) ;
F_28 ( V_39 , V_6 ) ;
V_2 -> V_31 = F_29 ( V_6 ,
V_40 ,
& V_2 -> V_41 ,
V_2 -> V_10 , L_2 ) ;
if ( ! V_2 -> V_31 ) {
F_10 ( V_2 -> V_10 , L_3 ) ;
goto V_42;
}
V_2 -> V_29 = F_29 ( V_6 ,
V_40 ,
& V_2 -> V_43 ,
V_2 -> V_10 , L_4 ) ;
if ( ! V_2 -> V_29 ) {
F_10 ( V_2 -> V_10 , L_5 ) ;
goto V_44;
}
return 0 ;
V_44:
F_30 ( V_2 -> V_31 ) ;
V_42:
if ( V_9 )
F_31 ( L_6 , V_9 ) ;
return V_9 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_29 ) ;
F_30 ( V_2 -> V_31 ) ;
}
static void F_33 ( void * V_45 , struct V_46 * V_47 ,
unsigned int V_48 , unsigned int V_49 , int V_50 )
{
struct V_51 V_52 ;
if ( ! V_49 )
return;
F_34 ( & V_52 , V_47 ) ;
F_35 ( & V_52 , V_48 ) ;
F_36 ( V_45 , & V_52 , V_49 , V_50 ) ;
F_37 ( & V_52 , V_50 , 0 ) ;
}
static int F_38 ( struct V_53 * V_54 ,
struct V_46 * V_55 , struct V_46 * V_56 ,
int V_57 , int V_58 )
{
struct V_33 * V_16 = F_39 ( V_54 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_59 * V_60 , * V_61 ;
struct V_62 V_63 ;
int V_64 ;
if ( V_2 -> V_65 ) {
F_34 ( & V_2 -> V_66 , V_2 -> V_55 ) ;
F_34 ( & V_2 -> V_67 , V_2 -> V_56 ) ;
F_3 ( V_2 , F_40 ( V_2 ) , 0x2 ) ;
return 0 ;
}
F_41 ( V_2 -> V_10 , V_2 -> V_55 , V_57 , V_68 ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_69 = V_2 -> V_70 + F_42 ( V_2 , 0 ) ;
V_63 . V_71 = V_2 -> V_70 + F_42 ( V_2 , 0 ) ;
V_63 . V_72 = V_73 ;
V_63 . V_74 = V_73 ;
V_63 . V_75 = V_76 ;
V_63 . V_77 = V_76 ;
V_64 = F_43 ( V_2 -> V_31 , & V_63 ) ;
if ( V_64 ) {
F_10 ( V_2 -> V_10 , L_7 ,
V_64 ) ;
return V_64 ;
}
V_60 = F_44 ( V_2 -> V_31 , V_55 , V_57 ,
V_78 ,
V_79 | V_80 ) ;
if ( ! V_60 ) {
F_10 ( V_2 -> V_10 , L_8 ) ;
return - V_81 ;
}
V_60 -> V_82 = V_2 ;
V_64 = F_43 ( V_2 -> V_29 , & V_63 ) ;
if ( V_64 ) {
F_10 ( V_2 -> V_10 , L_9 ,
V_64 ) ;
return V_64 ;
}
V_61 = F_44 ( V_2 -> V_29 , V_56 , V_58 ,
V_83 ,
V_79 | V_80 ) ;
if ( ! V_61 ) {
F_10 ( V_2 -> V_10 , L_10 ) ;
return - V_81 ;
}
V_61 -> V_84 = F_24 ;
V_61 -> V_82 = V_2 ;
F_45 ( V_60 ) ;
F_45 ( V_61 ) ;
F_46 ( V_2 -> V_31 ) ;
F_46 ( V_2 -> V_29 ) ;
V_2 -> V_27 -> V_85 ( V_2 , V_2 -> V_86 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = F_48 (
F_49 ( V_2 -> V_20 ) ) ;
int V_9 ;
F_50 ( L_11 , V_2 -> V_86 ) ;
if ( ! V_2 -> V_65 ) {
V_9 = F_51 ( V_2 -> V_10 , V_2 -> V_55 , V_2 -> V_57 ,
V_68 ) ;
if ( ! V_9 ) {
F_10 ( V_2 -> V_10 , L_12 ) ;
return - V_81 ;
}
V_9 = F_51 ( V_2 -> V_10 , V_2 -> V_56 , V_2 -> V_58 ,
V_87 ) ;
if ( ! V_9 ) {
F_10 ( V_2 -> V_10 , L_12 ) ;
return - V_81 ;
}
}
V_9 = F_38 ( V_54 , V_2 -> V_55 , V_2 -> V_56 , V_2 -> V_57 ,
V_2 -> V_58 ) ;
if ( V_9 && ! V_2 -> V_65 ) {
F_52 ( V_2 -> V_10 , V_2 -> V_55 , V_2 -> V_57 , V_68 ) ;
F_52 ( V_2 -> V_10 , V_2 -> V_56 , V_2 -> V_58 ,
V_87 ) ;
}
return V_9 ;
}
static void F_53 ( struct V_1 * V_2 , int V_9 )
{
struct V_88 * V_20 = V_2 -> V_20 ;
F_50 ( L_13 , V_9 ) ;
F_54 ( V_2 -> V_10 ) ;
V_2 -> V_12 &= ~ V_89 ;
V_20 -> V_90 . V_91 ( & V_20 -> V_90 , V_9 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
F_50 ( L_11 , V_2 -> V_86 ) ;
F_19 ( V_2 ) ;
F_56 ( V_2 -> V_31 ) ;
F_56 ( V_2 -> V_29 ) ;
F_52 ( V_2 -> V_10 , V_2 -> V_55 , V_2 -> V_57 , V_68 ) ;
F_52 ( V_2 -> V_10 , V_2 -> V_56 , V_2 -> V_58 , V_87 ) ;
return V_9 ;
}
static int F_57 ( struct V_46 * V_47 )
{
while ( V_47 ) {
if ( ! F_58 ( V_47 -> V_3 , 4 ) )
return - 1 ;
if ( ! F_58 ( V_47 -> V_26 , V_92 ) )
return - 1 ;
V_47 = F_59 ( V_47 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
void * V_93 , * V_94 ;
int V_95 ;
V_95 = V_2 -> V_86 >> V_96 ;
if ( V_2 -> V_86 & ( V_97 - 1 ) )
V_95 ++ ;
F_61 ( ! V_95 ) ;
V_93 = ( void * ) F_62 ( V_98 , V_95 ) ;
V_94 = ( void * ) F_62 ( V_98 , V_95 ) ;
if ( ! V_93 || ! V_94 ) {
F_31 ( L_14 ) ;
return - 1 ;
}
V_2 -> V_99 = V_2 -> V_56 ;
F_33 ( V_93 , V_2 -> V_55 , 0 , V_2 -> V_86 , 0 ) ;
F_63 ( & V_2 -> V_100 , 1 ) ;
F_64 ( & V_2 -> V_100 , V_93 , V_2 -> V_86 ) ;
V_2 -> V_55 = & V_2 -> V_100 ;
F_63 ( & V_2 -> V_101 , 1 ) ;
F_64 ( & V_2 -> V_101 , V_94 , V_2 -> V_86 ) ;
V_2 -> V_56 = & V_2 -> V_101 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_88 * V_20 )
{
struct V_102 * V_103 , * V_104 ;
struct V_33 * V_16 ;
struct V_105 * V_106 ;
unsigned long V_12 ;
int V_9 , V_64 = 0 ;
F_66 ( & V_2 -> V_107 , V_12 ) ;
if ( V_20 )
V_64 = F_67 ( & V_2 -> V_108 , V_20 ) ;
if ( V_2 -> V_12 & V_89 ) {
F_68 ( & V_2 -> V_107 , V_12 ) ;
return V_64 ;
}
V_104 = F_69 ( & V_2 -> V_108 ) ;
V_103 = F_70 ( & V_2 -> V_108 ) ;
if ( V_103 )
V_2 -> V_12 |= V_89 ;
F_68 ( & V_2 -> V_107 , V_12 ) ;
if ( ! V_103 )
return V_64 ;
if ( V_104 )
V_104 -> V_91 ( V_104 , - V_109 ) ;
V_20 = F_71 ( V_103 ) ;
V_2 -> V_20 = V_20 ;
V_2 -> V_86 = V_20 -> V_49 ;
V_2 -> V_110 = V_20 -> V_49 ;
V_2 -> V_55 = V_20 -> V_111 ;
V_2 -> V_56 = V_20 -> V_112 ;
if ( F_57 ( V_2 -> V_55 ) ||
F_57 ( V_2 -> V_56 ) ) {
if ( F_60 ( V_2 ) )
F_31 ( L_15 ) ;
V_2 -> V_113 = 1 ;
} else {
V_2 -> V_113 = 0 ;
}
V_2 -> V_57 = F_72 ( V_2 -> V_55 , V_2 -> V_86 ) ;
V_2 -> V_58 = F_72 ( V_2 -> V_56 , V_2 -> V_86 ) ;
F_61 ( V_2 -> V_57 < 0 || V_2 -> V_58 < 0 ) ;
V_106 = F_73 ( V_20 ) ;
V_16 = F_74 ( F_49 ( V_20 ) ) ;
V_106 -> V_114 &= V_115 ;
V_2 -> V_12 = ( V_2 -> V_12 & ~ V_115 ) | V_106 -> V_114 ;
V_2 -> V_16 = V_16 ;
V_16 -> V_2 = V_2 ;
V_9 = F_11 ( V_2 ) ;
if ( ! V_9 )
V_9 = F_47 ( V_2 ) ;
if ( V_9 ) {
F_53 ( V_2 , V_9 ) ;
F_25 ( & V_2 -> V_116 ) ;
}
return V_64 ;
}
static void F_75 ( unsigned long V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
void * V_93 , * V_94 ;
int V_95 ;
F_50 ( L_16 ) ;
if ( ! V_2 -> V_65 ) {
F_41 ( V_2 -> V_10 , V_2 -> V_56 , V_2 -> V_58 ,
V_87 ) ;
F_52 ( V_2 -> V_10 , V_2 -> V_55 , V_2 -> V_57 , V_68 ) ;
F_52 ( V_2 -> V_10 , V_2 -> V_56 , V_2 -> V_58 ,
V_87 ) ;
F_55 ( V_2 ) ;
}
if ( V_2 -> V_113 ) {
V_93 = F_76 ( & V_2 -> V_100 ) ;
V_94 = F_76 ( & V_2 -> V_101 ) ;
F_33 ( V_94 , V_2 -> V_99 , 0 , V_2 -> V_110 , 1 ) ;
V_95 = F_77 ( V_2 -> V_110 ) ;
F_78 ( ( unsigned long ) V_93 , V_95 ) ;
F_78 ( ( unsigned long ) V_94 , V_95 ) ;
}
F_53 ( V_2 , 0 ) ;
F_65 ( V_2 , NULL ) ;
F_50 ( L_17 ) ;
}
static void F_79 ( unsigned long V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
F_65 ( V_2 , NULL ) ;
}
static int F_80 ( struct V_88 * V_20 , unsigned long V_114 )
{
struct V_33 * V_16 = F_74 (
F_49 ( V_20 ) ) ;
struct V_105 * V_106 = F_73 ( V_20 ) ;
struct V_1 * V_2 ;
F_50 ( L_18 , V_20 -> V_49 ,
! ! ( V_114 & V_23 ) ,
! ! ( V_114 & V_19 ) ) ;
if ( ! F_58 ( V_20 -> V_49 , V_92 ) ) {
F_31 ( L_19 ) ;
return - V_81 ;
}
V_2 = F_20 ( V_16 ) ;
if ( ! V_2 )
return - V_117 ;
V_106 -> V_114 = V_114 ;
return F_65 ( V_2 , V_20 ) ;
}
static int F_81 ( struct V_118 * V_54 , const T_3 * V_18 ,
unsigned int V_17 )
{
struct V_33 * V_16 = F_74 ( V_54 ) ;
if ( V_17 != V_119 && V_17 != ( 3 * V_119 ) )
return - V_81 ;
F_50 ( L_20 , V_17 ) ;
memcpy ( V_16 -> V_18 , V_18 , V_17 ) ;
V_16 -> V_17 = V_17 ;
return 0 ;
}
static int F_82 ( struct V_88 * V_20 )
{
return F_80 ( V_20 , V_23 ) ;
}
static int F_83 ( struct V_88 * V_20 )
{
return F_80 ( V_20 , 0 ) ;
}
static int F_84 ( struct V_88 * V_20 )
{
return F_80 ( V_20 , V_23 | V_19 ) ;
}
static int F_85 ( struct V_88 * V_20 )
{
return F_80 ( V_20 , V_19 ) ;
}
static int F_86 ( struct V_53 * V_54 )
{
F_50 ( L_21 ) ;
V_54 -> V_120 . V_121 = sizeof( struct V_105 ) ;
return 0 ;
}
static void F_87 ( struct V_53 * V_54 )
{
F_50 ( L_21 ) ;
}
static T_4 F_88 ( int V_122 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
T_1 V_124 , V_15 ;
T_1 * V_111 , * V_112 ;
V_124 = F_1 ( V_2 , F_89 ( V_2 ) ) ;
if ( V_124 & V_125 ) {
F_3 ( V_2 , F_40 ( V_2 ) , 0x0 ) ;
F_61 ( ! V_2 -> V_55 ) ;
F_61 ( F_90 ( V_126 ) > V_2 -> V_55 -> V_26 ) ;
V_111 = F_76 ( V_2 -> V_55 ) + F_90 ( V_126 ) ;
for ( V_15 = 0 ; V_15 < V_127 ; V_15 ++ ) {
F_3 ( V_2 , F_42 ( V_2 , V_15 ) , * V_111 ) ;
F_35 ( & V_2 -> V_66 , 4 ) ;
if ( V_2 -> V_55 -> V_26 == F_90 ( V_126 ) ) {
V_2 -> V_55 = F_59 ( V_2 -> V_55 ) ;
if ( V_2 -> V_55 ) {
F_34 ( & V_2 -> V_66 ,
V_2 -> V_55 ) ;
V_111 = F_76 ( V_2 -> V_55 ) +
F_90 ( V_126 ) ;
}
} else {
V_111 ++ ;
}
}
V_124 &= ~ V_125 ;
F_3 ( V_2 , F_89 ( V_2 ) , V_124 ) ;
F_3 ( V_2 , F_40 ( V_2 ) , 0x4 ) ;
} else if ( V_124 & V_128 ) {
F_3 ( V_2 , F_40 ( V_2 ) , 0x0 ) ;
F_61 ( ! V_2 -> V_56 ) ;
F_61 ( F_90 ( V_50 ) > V_2 -> V_56 -> V_26 ) ;
V_112 = F_76 ( V_2 -> V_56 ) + F_90 ( V_50 ) ;
for ( V_15 = 0 ; V_15 < V_127 ; V_15 ++ ) {
* V_112 = F_1 ( V_2 , F_42 ( V_2 , V_15 ) ) ;
F_35 ( & V_2 -> V_67 , 4 ) ;
if ( V_2 -> V_56 -> V_26 == F_90 ( V_50 ) ) {
V_2 -> V_56 = F_59 ( V_2 -> V_56 ) ;
if ( V_2 -> V_56 ) {
F_34 ( & V_2 -> V_67 ,
V_2 -> V_56 ) ;
V_112 = F_76 ( V_2 -> V_56 ) +
F_90 ( V_50 ) ;
}
} else {
V_112 ++ ;
}
}
F_61 ( V_2 -> V_86 < V_92 ) ;
V_2 -> V_86 -= V_92 ;
V_124 &= ~ V_128 ;
F_3 ( V_2 , F_89 ( V_2 ) , V_124 ) ;
if ( ! V_2 -> V_86 )
F_25 ( & V_2 -> V_37 ) ;
else
F_3 ( V_2 , F_40 ( V_2 ) , 0x2 ) ;
}
return V_129 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
const struct V_132 * V_133 ;
V_133 = F_92 ( F_93 ( V_134 ) , & V_131 -> V_10 ) ;
if ( ! V_133 ) {
F_10 ( & V_131 -> V_10 , L_22 ) ;
return - V_81 ;
}
V_2 -> V_43 = - 1 ;
V_2 -> V_41 = - 1 ;
V_2 -> V_27 = V_133 -> V_36 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_135 * V_10 )
{
return - V_81 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
struct V_135 * V_10 = & V_131 -> V_10 ;
struct V_136 * V_137 ;
int V_9 = 0 ;
V_137 = F_95 ( V_131 , V_138 , 0 ) ;
if ( ! V_137 ) {
F_10 ( V_10 , L_23 ) ;
V_9 = - V_117 ;
goto V_9;
}
V_2 -> V_43 = V_137 -> V_48 ;
V_137 = F_95 ( V_131 , V_138 , 1 ) ;
if ( ! V_137 ) {
F_10 ( V_10 , L_24 ) ;
V_9 = - V_117 ;
goto V_9;
}
V_2 -> V_41 = V_137 -> V_48 ;
V_2 -> V_27 = V_131 -> V_10 . V_139 ;
V_9:
return V_9 ;
}
static int F_96 ( struct V_130 * V_131 )
{
struct V_135 * V_10 = & V_131 -> V_10 ;
struct V_1 * V_2 ;
struct V_140 * V_141 ;
struct V_136 * V_142 ;
int V_9 = - V_38 , V_15 , V_143 , V_122 = - 1 ;
T_1 V_144 ;
V_2 = F_97 ( V_10 , sizeof( struct V_1 ) , V_145 ) ;
if ( V_2 == NULL ) {
F_10 ( V_10 , L_25 ) ;
goto V_146;
}
V_2 -> V_10 = V_10 ;
F_98 ( V_131 , V_2 ) ;
F_99 ( & V_2 -> V_107 ) ;
F_100 ( & V_2 -> V_108 , V_147 ) ;
V_142 = F_95 ( V_131 , V_148 , 0 ) ;
if ( ! V_142 ) {
F_10 ( V_10 , L_26 ) ;
goto V_149;
}
V_9 = ( V_10 -> V_150 ) ? F_91 ( V_2 , V_131 ) :
F_94 ( V_2 , V_131 ) ;
if ( V_9 )
goto V_149;
V_2 -> V_4 = F_101 ( V_10 , V_142 ) ;
if ( F_102 ( V_2 -> V_4 ) ) {
V_9 = F_103 ( V_2 -> V_4 ) ;
goto V_149;
}
V_2 -> V_70 = V_142 -> V_48 ;
F_104 ( V_10 ) ;
V_9 = F_8 ( V_10 ) ;
if ( V_9 < 0 ) {
F_9 ( V_10 ) ;
F_10 ( V_2 -> V_10 , L_1 , V_11 , V_9 ) ;
goto V_151;
}
F_19 ( V_2 ) ;
V_144 = F_1 ( V_2 , F_105 ( V_2 ) ) ;
F_106 ( V_10 ) ;
F_107 ( V_10 , L_27 ,
( V_144 & V_2 -> V_27 -> V_152 ) >> V_2 -> V_27 -> V_153 ,
( V_144 & V_2 -> V_27 -> V_154 ) >> V_2 -> V_27 -> V_155 ) ;
F_108 ( & V_2 -> V_37 , F_75 , ( unsigned long ) V_2 ) ;
F_108 ( & V_2 -> V_116 , F_79 , ( unsigned long ) V_2 ) ;
V_9 = F_26 ( V_2 ) ;
if ( V_9 && F_89 ( V_2 ) && F_40 ( V_2 ) ) {
V_2 -> V_65 = 1 ;
V_122 = F_109 ( V_131 , 0 ) ;
if ( V_122 < 0 ) {
F_10 ( V_10 , L_28 ) ;
goto V_156;
}
V_9 = F_110 ( V_10 , V_122 , F_88 , 0 ,
F_111 ( V_10 ) , V_2 ) ;
if ( V_9 ) {
F_10 ( V_10 , L_29 ) ;
goto V_156;
}
}
F_112 ( & V_2 -> V_157 ) ;
F_113 ( & V_35 ) ;
F_114 ( & V_2 -> V_157 , & V_158 ) ;
F_115 ( & V_35 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_27 -> V_159 ; V_15 ++ ) {
for ( V_143 = 0 ; V_143 < V_2 -> V_27 -> V_160 [ V_15 ] . V_161 ; V_143 ++ ) {
V_141 = & V_2 -> V_27 -> V_160 [ V_15 ] . V_162 [ V_143 ] ;
F_50 ( L_30 , V_141 -> V_163 ) ;
F_112 ( & V_141 -> V_164 ) ;
V_9 = F_116 ( V_141 ) ;
if ( V_9 )
goto V_165;
V_2 -> V_27 -> V_160 [ V_15 ] . V_166 ++ ;
}
}
return 0 ;
V_165:
for ( V_15 = V_2 -> V_27 -> V_159 - 1 ; V_15 >= 0 ; V_15 -- )
for ( V_143 = V_2 -> V_27 -> V_160 [ V_15 ] . V_166 - 1 ; V_143 >= 0 ; V_143 -- )
F_117 (
& V_2 -> V_27 -> V_160 [ V_15 ] . V_162 [ V_143 ] ) ;
if ( ! V_2 -> V_65 )
F_32 ( V_2 ) ;
V_156:
F_118 ( & V_2 -> V_37 ) ;
F_118 ( & V_2 -> V_116 ) ;
V_151:
F_119 ( V_10 ) ;
V_149:
V_2 = NULL ;
V_146:
F_10 ( V_10 , L_31 ) ;
return V_9 ;
}
static int F_120 ( struct V_130 * V_131 )
{
struct V_1 * V_2 = F_121 ( V_131 ) ;
int V_15 , V_143 ;
if ( ! V_2 )
return - V_117 ;
F_113 ( & V_35 ) ;
F_122 ( & V_2 -> V_157 ) ;
F_115 ( & V_35 ) ;
for ( V_15 = V_2 -> V_27 -> V_159 - 1 ; V_15 >= 0 ; V_15 -- )
for ( V_143 = V_2 -> V_27 -> V_160 [ V_15 ] . V_166 - 1 ; V_143 >= 0 ; V_143 -- )
F_117 (
& V_2 -> V_27 -> V_160 [ V_15 ] . V_162 [ V_143 ] ) ;
F_118 ( & V_2 -> V_37 ) ;
F_118 ( & V_2 -> V_116 ) ;
F_32 ( V_2 ) ;
F_119 ( V_2 -> V_10 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_123 ( struct V_135 * V_10 )
{
F_106 ( V_10 ) ;
return 0 ;
}
static int F_124 ( struct V_135 * V_10 )
{
int V_9 ;
V_9 = F_8 ( V_10 ) ;
if ( V_9 < 0 ) {
F_9 ( V_10 ) ;
F_10 ( V_10 , L_1 , V_11 , V_9 ) ;
return V_9 ;
}
return 0 ;
}
