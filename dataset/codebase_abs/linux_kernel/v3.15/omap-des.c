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
F_8 ( V_2 -> V_9 ) ;
if ( ! ( V_2 -> V_10 & V_11 ) ) {
V_2 -> V_10 |= V_11 ;
V_2 -> V_12 = 0 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned int V_13 ;
int V_14 , V_12 ;
T_1 V_7 = 0 , V_6 = 0 ;
V_12 = F_7 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_13 = V_2 -> V_15 -> V_16 / sizeof( T_1 ) ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
F_3 ( V_2 , F_10 ( V_2 , V_14 ) ,
F_11 ( V_2 -> V_15 -> V_17 [ V_14 ] ) ) ;
}
if ( ( V_2 -> V_10 & V_18 ) && V_2 -> V_19 -> V_20 )
F_6 ( V_2 , F_12 ( V_2 , 0 ) , V_2 -> V_19 -> V_20 , 2 ) ;
if ( V_2 -> V_10 & V_18 )
V_7 |= V_21 ;
if ( V_2 -> V_10 & V_22 )
V_7 |= V_23 ;
if ( V_13 == 6 )
V_7 |= V_24 ;
V_6 |= V_21 | V_23 | V_24 ;
F_5 ( V_2 , F_13 ( V_2 ) , V_7 , V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_6 , V_7 ;
F_3 ( V_2 , F_15 ( 0 ) , V_25 ) ;
V_7 = V_2 -> V_26 -> V_27 ;
if ( V_2 -> V_28 != NULL )
V_7 |= V_2 -> V_26 -> V_29 ;
if ( V_2 -> V_30 != NULL )
V_7 |= V_2 -> V_26 -> V_31 ;
V_6 = V_2 -> V_26 -> V_29 | V_2 -> V_26 -> V_31 |
V_2 -> V_26 -> V_27 ;
F_5 ( V_2 , F_16 ( V_2 ) , V_7 , V_6 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = V_2 -> V_26 -> V_29 | V_2 -> V_26 -> V_31 |
V_2 -> V_26 -> V_27 ;
F_5 ( V_2 , F_16 ( V_2 ) , 0 , V_6 ) ;
}
static struct V_1 * F_18 ( struct V_32 * V_15 )
{
struct V_1 * V_2 = NULL , * V_33 ;
F_19 ( & V_34 ) ;
if ( ! V_15 -> V_2 ) {
F_20 (tmp, &dev_list, list) {
V_2 = V_33 ;
break;
}
V_15 -> V_2 = V_2 ;
} else {
V_2 = V_15 -> V_2 ;
}
F_21 ( & V_34 ) ;
return V_2 ;
}
static void F_22 ( void * V_35 )
{
struct V_1 * V_2 = V_35 ;
F_23 ( & V_2 -> V_36 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_12 = - V_37 ;
T_2 V_6 ;
V_2 -> V_28 = NULL ;
V_2 -> V_30 = NULL ;
F_25 ( V_6 ) ;
F_26 ( V_38 , V_6 ) ;
V_2 -> V_30 = F_27 ( V_6 ,
V_39 ,
& V_2 -> V_40 ,
V_2 -> V_9 , L_1 ) ;
if ( ! V_2 -> V_30 ) {
F_28 ( V_2 -> V_9 , L_2 ) ;
goto V_41;
}
V_2 -> V_28 = F_27 ( V_6 ,
V_39 ,
& V_2 -> V_42 ,
V_2 -> V_9 , L_3 ) ;
if ( ! V_2 -> V_28 ) {
F_28 ( V_2 -> V_9 , L_4 ) ;
goto V_43;
}
return 0 ;
V_43:
F_29 ( V_2 -> V_30 ) ;
V_41:
if ( V_12 )
F_30 ( L_5 , V_12 ) ;
return V_12 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_28 ) ;
F_29 ( V_2 -> V_30 ) ;
}
static void F_32 ( void * V_44 , struct V_45 * V_46 ,
unsigned int V_47 , unsigned int V_48 , int V_49 )
{
struct V_50 V_51 ;
if ( ! V_48 )
return;
F_33 ( & V_51 , V_46 ) ;
F_34 ( & V_51 , V_47 ) ;
F_35 ( V_44 , & V_51 , V_48 , V_49 ) ;
F_36 ( & V_51 , V_49 , 0 ) ;
}
static int F_37 ( struct V_52 * V_53 ,
struct V_45 * V_54 , struct V_45 * V_55 ,
int V_56 , int V_57 )
{
struct V_32 * V_15 = F_38 ( V_53 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_58 * V_59 , * V_60 ;
struct V_61 V_62 ;
int V_63 ;
if ( V_2 -> V_64 ) {
F_33 ( & V_2 -> V_65 , V_2 -> V_54 ) ;
F_33 ( & V_2 -> V_66 , V_2 -> V_55 ) ;
F_3 ( V_2 , F_39 ( V_2 ) , 0x2 ) ;
return 0 ;
}
F_40 ( V_2 -> V_9 , V_2 -> V_54 , V_56 , V_67 ) ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_68 = V_2 -> V_69 + F_41 ( V_2 , 0 ) ;
V_62 . V_70 = V_2 -> V_69 + F_41 ( V_2 , 0 ) ;
V_62 . V_71 = V_72 ;
V_62 . V_73 = V_72 ;
V_62 . V_74 = V_75 ;
V_62 . V_76 = V_75 ;
V_63 = F_42 ( V_2 -> V_30 , & V_62 ) ;
if ( V_63 ) {
F_28 ( V_2 -> V_9 , L_6 ,
V_63 ) ;
return V_63 ;
}
V_59 = F_43 ( V_2 -> V_30 , V_54 , V_56 ,
V_77 ,
V_78 | V_79 ) ;
if ( ! V_59 ) {
F_28 ( V_2 -> V_9 , L_7 ) ;
return - V_80 ;
}
V_59 -> V_81 = V_2 ;
V_63 = F_42 ( V_2 -> V_28 , & V_62 ) ;
if ( V_63 ) {
F_28 ( V_2 -> V_9 , L_8 ,
V_63 ) ;
return V_63 ;
}
V_60 = F_43 ( V_2 -> V_28 , V_55 , V_57 ,
V_82 ,
V_78 | V_79 ) ;
if ( ! V_60 ) {
F_28 ( V_2 -> V_9 , L_9 ) ;
return - V_80 ;
}
V_60 -> V_83 = F_22 ;
V_60 -> V_81 = V_2 ;
F_44 ( V_59 ) ;
F_44 ( V_60 ) ;
F_45 ( V_2 -> V_30 ) ;
F_45 ( V_2 -> V_28 ) ;
V_2 -> V_26 -> V_84 ( V_2 , V_2 -> V_85 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = F_47 (
F_48 ( V_2 -> V_19 ) ) ;
int V_12 ;
F_49 ( L_10 , V_2 -> V_85 ) ;
if ( ! V_2 -> V_64 ) {
V_12 = F_50 ( V_2 -> V_9 , V_2 -> V_54 , V_2 -> V_56 ,
V_67 ) ;
if ( ! V_12 ) {
F_28 ( V_2 -> V_9 , L_11 ) ;
return - V_80 ;
}
V_12 = F_50 ( V_2 -> V_9 , V_2 -> V_55 , V_2 -> V_57 ,
V_86 ) ;
if ( ! V_12 ) {
F_28 ( V_2 -> V_9 , L_11 ) ;
return - V_80 ;
}
}
V_12 = F_37 ( V_53 , V_2 -> V_54 , V_2 -> V_55 , V_2 -> V_56 ,
V_2 -> V_57 ) ;
if ( V_12 && ! V_2 -> V_64 ) {
F_51 ( V_2 -> V_9 , V_2 -> V_54 , V_2 -> V_56 , V_67 ) ;
F_51 ( V_2 -> V_9 , V_2 -> V_55 , V_2 -> V_57 ,
V_86 ) ;
}
return V_12 ;
}
static void F_52 ( struct V_1 * V_2 , int V_12 )
{
struct V_87 * V_19 = V_2 -> V_19 ;
F_49 ( L_12 , V_12 ) ;
F_53 ( V_2 -> V_9 ) ;
V_2 -> V_10 &= ~ V_88 ;
V_19 -> V_89 . V_90 ( & V_19 -> V_89 , V_12 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_12 = 0 ;
F_49 ( L_10 , V_2 -> V_85 ) ;
F_17 ( V_2 ) ;
F_55 ( V_2 -> V_30 ) ;
F_55 ( V_2 -> V_28 ) ;
F_51 ( V_2 -> V_9 , V_2 -> V_54 , V_2 -> V_56 , V_67 ) ;
F_51 ( V_2 -> V_9 , V_2 -> V_55 , V_2 -> V_57 , V_86 ) ;
return V_12 ;
}
static int F_56 ( struct V_45 * V_46 )
{
while ( V_46 ) {
if ( ! F_57 ( V_46 -> V_3 , 4 ) )
return - 1 ;
if ( ! F_57 ( V_46 -> V_25 , V_91 ) )
return - 1 ;
V_46 = F_58 ( V_46 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
void * V_92 , * V_93 ;
int V_94 ;
V_94 = V_2 -> V_85 >> V_95 ;
if ( V_2 -> V_85 & ( V_96 - 1 ) )
V_94 ++ ;
F_60 ( ! V_94 ) ;
V_92 = ( void * ) F_61 ( V_97 , V_94 ) ;
V_93 = ( void * ) F_61 ( V_97 , V_94 ) ;
if ( ! V_92 || ! V_93 ) {
F_30 ( L_13 ) ;
return - 1 ;
}
V_2 -> V_98 = V_2 -> V_55 ;
F_32 ( V_92 , V_2 -> V_54 , 0 , V_2 -> V_85 , 0 ) ;
F_62 ( & V_2 -> V_99 , 1 ) ;
F_63 ( & V_2 -> V_99 , V_92 , V_2 -> V_85 ) ;
V_2 -> V_54 = & V_2 -> V_99 ;
F_62 ( & V_2 -> V_100 , 1 ) ;
F_63 ( & V_2 -> V_100 , V_93 , V_2 -> V_85 ) ;
V_2 -> V_55 = & V_2 -> V_100 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_87 * V_19 )
{
struct V_101 * V_102 , * V_103 ;
struct V_32 * V_15 ;
struct V_104 * V_105 ;
unsigned long V_10 ;
int V_12 , V_63 = 0 ;
F_65 ( & V_2 -> V_106 , V_10 ) ;
if ( V_19 )
V_63 = F_66 ( & V_2 -> V_107 , V_19 ) ;
if ( V_2 -> V_10 & V_88 ) {
F_67 ( & V_2 -> V_106 , V_10 ) ;
return V_63 ;
}
V_103 = F_68 ( & V_2 -> V_107 ) ;
V_102 = F_69 ( & V_2 -> V_107 ) ;
if ( V_102 )
V_2 -> V_10 |= V_88 ;
F_67 ( & V_2 -> V_106 , V_10 ) ;
if ( ! V_102 )
return V_63 ;
if ( V_103 )
V_103 -> V_90 ( V_103 , - V_108 ) ;
V_19 = F_70 ( V_102 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_85 = V_19 -> V_48 ;
V_2 -> V_109 = V_19 -> V_48 ;
V_2 -> V_54 = V_19 -> V_110 ;
V_2 -> V_55 = V_19 -> V_111 ;
if ( F_56 ( V_2 -> V_54 ) ||
F_56 ( V_2 -> V_55 ) ) {
if ( F_59 ( V_2 ) )
F_30 ( L_14 ) ;
V_2 -> V_112 = 1 ;
} else {
V_2 -> V_112 = 0 ;
}
V_2 -> V_56 = F_71 ( V_2 -> V_54 , V_2 -> V_85 ) ;
V_2 -> V_57 = F_71 ( V_2 -> V_55 , V_2 -> V_85 ) ;
F_60 ( V_2 -> V_56 < 0 || V_2 -> V_57 < 0 ) ;
V_105 = F_72 ( V_19 ) ;
V_15 = F_73 ( F_48 ( V_19 ) ) ;
V_105 -> V_113 &= V_114 ;
V_2 -> V_10 = ( V_2 -> V_10 & ~ V_114 ) | V_105 -> V_113 ;
V_2 -> V_15 = V_15 ;
V_15 -> V_2 = V_2 ;
V_12 = F_9 ( V_2 ) ;
if ( ! V_12 )
V_12 = F_46 ( V_2 ) ;
if ( V_12 ) {
F_52 ( V_2 , V_12 ) ;
F_23 ( & V_2 -> V_115 ) ;
}
return V_63 ;
}
static void F_74 ( unsigned long V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
void * V_92 , * V_93 ;
int V_94 ;
F_49 ( L_15 ) ;
if ( ! V_2 -> V_64 ) {
F_40 ( V_2 -> V_9 , V_2 -> V_55 , V_2 -> V_57 ,
V_86 ) ;
F_51 ( V_2 -> V_9 , V_2 -> V_54 , V_2 -> V_56 , V_67 ) ;
F_51 ( V_2 -> V_9 , V_2 -> V_55 , V_2 -> V_57 ,
V_86 ) ;
F_54 ( V_2 ) ;
}
if ( V_2 -> V_112 ) {
V_92 = F_75 ( & V_2 -> V_99 ) ;
V_93 = F_75 ( & V_2 -> V_100 ) ;
F_32 ( V_93 , V_2 -> V_98 , 0 , V_2 -> V_109 , 1 ) ;
V_94 = F_76 ( V_2 -> V_109 ) ;
F_77 ( ( unsigned long ) V_92 , V_94 ) ;
F_77 ( ( unsigned long ) V_93 , V_94 ) ;
}
F_52 ( V_2 , 0 ) ;
F_64 ( V_2 , NULL ) ;
F_49 ( L_16 ) ;
}
static void F_78 ( unsigned long V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
F_64 ( V_2 , NULL ) ;
}
static int F_79 ( struct V_87 * V_19 , unsigned long V_113 )
{
struct V_32 * V_15 = F_73 (
F_48 ( V_19 ) ) ;
struct V_104 * V_105 = F_72 ( V_19 ) ;
struct V_1 * V_2 ;
F_49 ( L_17 , V_19 -> V_48 ,
! ! ( V_113 & V_22 ) ,
! ! ( V_113 & V_18 ) ) ;
if ( ! F_57 ( V_19 -> V_48 , V_91 ) ) {
F_30 ( L_18 ) ;
return - V_80 ;
}
V_2 = F_18 ( V_15 ) ;
if ( ! V_2 )
return - V_116 ;
V_105 -> V_113 = V_113 ;
return F_64 ( V_2 , V_19 ) ;
}
static int F_80 ( struct V_117 * V_53 , const T_3 * V_17 ,
unsigned int V_16 )
{
struct V_32 * V_15 = F_73 ( V_53 ) ;
if ( V_16 != V_118 && V_16 != ( 3 * V_118 ) )
return - V_80 ;
F_49 ( L_19 , V_16 ) ;
memcpy ( V_15 -> V_17 , V_17 , V_16 ) ;
V_15 -> V_16 = V_16 ;
return 0 ;
}
static int F_81 ( struct V_87 * V_19 )
{
return F_79 ( V_19 , V_22 ) ;
}
static int F_82 ( struct V_87 * V_19 )
{
return F_79 ( V_19 , 0 ) ;
}
static int F_83 ( struct V_87 * V_19 )
{
return F_79 ( V_19 , V_22 | V_18 ) ;
}
static int F_84 ( struct V_87 * V_19 )
{
return F_79 ( V_19 , V_18 ) ;
}
static int F_85 ( struct V_52 * V_53 )
{
F_49 ( L_20 ) ;
V_53 -> V_119 . V_120 = sizeof( struct V_104 ) ;
return 0 ;
}
static void F_86 ( struct V_52 * V_53 )
{
F_49 ( L_20 ) ;
}
static T_4 F_87 ( int V_121 , void * V_122 )
{
struct V_1 * V_2 = V_122 ;
T_1 V_123 , V_14 ;
T_1 * V_110 , * V_111 ;
V_123 = F_1 ( V_2 , F_88 ( V_2 ) ) ;
if ( V_123 & V_124 ) {
F_3 ( V_2 , F_39 ( V_2 ) , 0x0 ) ;
F_60 ( ! V_2 -> V_54 ) ;
F_60 ( F_89 ( V_125 ) > V_2 -> V_54 -> V_25 ) ;
V_110 = F_75 ( V_2 -> V_54 ) + F_89 ( V_125 ) ;
for ( V_14 = 0 ; V_14 < V_126 ; V_14 ++ ) {
F_3 ( V_2 , F_41 ( V_2 , V_14 ) , * V_110 ) ;
F_34 ( & V_2 -> V_65 , 4 ) ;
if ( V_2 -> V_54 -> V_25 == F_89 ( V_125 ) ) {
V_2 -> V_54 = F_90 ( V_2 -> V_54 ) ;
if ( V_2 -> V_54 ) {
F_33 ( & V_2 -> V_65 ,
V_2 -> V_54 ) ;
V_110 = F_75 ( V_2 -> V_54 ) +
F_89 ( V_125 ) ;
}
} else {
V_110 ++ ;
}
}
V_123 &= ~ V_124 ;
F_3 ( V_2 , F_88 ( V_2 ) , V_123 ) ;
F_3 ( V_2 , F_39 ( V_2 ) , 0x4 ) ;
} else if ( V_123 & V_127 ) {
F_3 ( V_2 , F_39 ( V_2 ) , 0x0 ) ;
F_60 ( ! V_2 -> V_55 ) ;
F_60 ( F_89 ( V_49 ) > V_2 -> V_55 -> V_25 ) ;
V_111 = F_75 ( V_2 -> V_55 ) + F_89 ( V_49 ) ;
for ( V_14 = 0 ; V_14 < V_126 ; V_14 ++ ) {
* V_111 = F_1 ( V_2 , F_41 ( V_2 , V_14 ) ) ;
F_34 ( & V_2 -> V_66 , 4 ) ;
if ( V_2 -> V_55 -> V_25 == F_89 ( V_49 ) ) {
V_2 -> V_55 = F_90 ( V_2 -> V_55 ) ;
if ( V_2 -> V_55 ) {
F_33 ( & V_2 -> V_66 ,
V_2 -> V_55 ) ;
V_111 = F_75 ( V_2 -> V_55 ) +
F_89 ( V_49 ) ;
}
} else {
V_111 ++ ;
}
}
V_2 -> V_85 -= V_91 ;
F_60 ( V_2 -> V_85 < 0 ) ;
V_123 &= ~ V_127 ;
F_3 ( V_2 , F_88 ( V_2 ) , V_123 ) ;
if ( ! V_2 -> V_85 )
F_23 ( & V_2 -> V_36 ) ;
else
F_3 ( V_2 , F_39 ( V_2 ) , 0x2 ) ;
}
return V_128 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
const struct V_131 * V_132 ;
V_132 = F_92 ( F_93 ( V_133 ) , & V_130 -> V_9 ) ;
if ( ! V_132 ) {
F_28 ( & V_130 -> V_9 , L_21 ) ;
return - V_80 ;
}
V_2 -> V_42 = - 1 ;
V_2 -> V_40 = - 1 ;
V_2 -> V_26 = V_132 -> V_35 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_134 * V_9 )
{
return - V_80 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_134 * V_9 = & V_130 -> V_9 ;
struct V_135 * V_136 ;
int V_12 = 0 ;
V_136 = F_95 ( V_130 , V_137 , 0 ) ;
if ( ! V_136 ) {
F_28 ( V_9 , L_22 ) ;
V_12 = - V_116 ;
goto V_12;
}
V_2 -> V_42 = V_136 -> V_47 ;
V_136 = F_95 ( V_130 , V_137 , 1 ) ;
if ( ! V_136 ) {
F_28 ( V_9 , L_23 ) ;
V_12 = - V_116 ;
goto V_12;
}
V_2 -> V_40 = V_136 -> V_47 ;
V_2 -> V_26 = V_130 -> V_9 . V_138 ;
V_12:
return V_12 ;
}
static int F_96 ( struct V_129 * V_130 )
{
struct V_134 * V_9 = & V_130 -> V_9 ;
struct V_1 * V_2 ;
struct V_139 * V_140 ;
struct V_135 * V_141 ;
int V_12 = - V_37 , V_14 , V_142 , V_121 = - 1 ;
T_1 V_143 ;
V_2 = F_97 ( V_9 , sizeof( struct V_1 ) , V_144 ) ;
if ( V_2 == NULL ) {
F_28 ( V_9 , L_24 ) ;
goto V_145;
}
V_2 -> V_9 = V_9 ;
F_98 ( V_130 , V_2 ) ;
F_99 ( & V_2 -> V_106 ) ;
F_100 ( & V_2 -> V_107 , V_146 ) ;
V_141 = F_95 ( V_130 , V_147 , 0 ) ;
if ( ! V_141 ) {
F_28 ( V_9 , L_25 ) ;
goto V_148;
}
V_12 = ( V_9 -> V_149 ) ? F_91 ( V_2 , V_130 ) :
F_94 ( V_2 , V_130 ) ;
if ( V_12 )
goto V_148;
V_2 -> V_4 = F_101 ( V_9 , V_141 ) ;
if ( ! V_2 -> V_4 ) {
F_28 ( V_9 , L_26 ) ;
V_12 = - V_37 ;
goto V_148;
}
V_2 -> V_69 = V_141 -> V_47 ;
F_102 ( V_9 ) ;
F_8 ( V_9 ) ;
F_17 ( V_2 ) ;
V_143 = F_1 ( V_2 , F_103 ( V_2 ) ) ;
F_104 ( V_9 ) ;
F_105 ( V_9 , L_27 ,
( V_143 & V_2 -> V_26 -> V_150 ) >> V_2 -> V_26 -> V_151 ,
( V_143 & V_2 -> V_26 -> V_152 ) >> V_2 -> V_26 -> V_153 ) ;
F_106 ( & V_2 -> V_36 , F_74 , ( unsigned long ) V_2 ) ;
F_106 ( & V_2 -> V_115 , F_78 , ( unsigned long ) V_2 ) ;
V_12 = F_24 ( V_2 ) ;
if ( V_12 && F_88 ( V_2 ) && F_39 ( V_2 ) ) {
V_2 -> V_64 = 1 ;
V_121 = F_107 ( V_130 , 0 ) ;
if ( V_121 < 0 ) {
F_28 ( V_9 , L_28 ) ;
goto V_154;
}
V_12 = F_108 ( V_9 , V_121 , F_87 , 0 ,
F_109 ( V_9 ) , V_2 ) ;
if ( V_12 ) {
F_28 ( V_9 , L_29 ) ;
goto V_154;
}
}
F_110 ( & V_2 -> V_155 ) ;
F_111 ( & V_34 ) ;
F_112 ( & V_2 -> V_155 , & V_156 ) ;
F_113 ( & V_34 ) ;
for ( V_14 = 0 ; V_14 < V_2 -> V_26 -> V_157 ; V_14 ++ ) {
for ( V_142 = 0 ; V_142 < V_2 -> V_26 -> V_158 [ V_14 ] . V_159 ; V_142 ++ ) {
V_140 = & V_2 -> V_26 -> V_158 [ V_14 ] . V_160 [ V_142 ] ;
F_49 ( L_30 , V_140 -> V_161 ) ;
F_110 ( & V_140 -> V_162 ) ;
V_12 = F_114 ( V_140 ) ;
if ( V_12 )
goto V_163;
V_2 -> V_26 -> V_158 [ V_14 ] . V_164 ++ ;
}
}
return 0 ;
V_163:
for ( V_14 = V_2 -> V_26 -> V_157 - 1 ; V_14 >= 0 ; V_14 -- )
for ( V_142 = V_2 -> V_26 -> V_158 [ V_14 ] . V_164 - 1 ; V_142 >= 0 ; V_142 -- )
F_115 (
& V_2 -> V_26 -> V_158 [ V_14 ] . V_160 [ V_142 ] ) ;
if ( ! V_2 -> V_64 )
F_31 ( V_2 ) ;
V_154:
F_116 ( & V_2 -> V_36 ) ;
F_116 ( & V_2 -> V_115 ) ;
F_117 ( V_9 ) ;
V_148:
V_2 = NULL ;
V_145:
F_28 ( V_9 , L_31 ) ;
return V_12 ;
}
static int F_118 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_119 ( V_130 ) ;
int V_14 , V_142 ;
if ( ! V_2 )
return - V_116 ;
F_111 ( & V_34 ) ;
F_120 ( & V_2 -> V_155 ) ;
F_113 ( & V_34 ) ;
for ( V_14 = V_2 -> V_26 -> V_157 - 1 ; V_14 >= 0 ; V_14 -- )
for ( V_142 = V_2 -> V_26 -> V_158 [ V_14 ] . V_164 - 1 ; V_142 >= 0 ; V_142 -- )
F_115 (
& V_2 -> V_26 -> V_158 [ V_14 ] . V_160 [ V_142 ] ) ;
F_116 ( & V_2 -> V_36 ) ;
F_116 ( & V_2 -> V_115 ) ;
F_31 ( V_2 ) ;
F_117 ( V_2 -> V_9 ) ;
V_2 = NULL ;
return 0 ;
}
static int F_121 ( struct V_134 * V_9 )
{
F_104 ( V_9 ) ;
return 0 ;
}
static int F_122 ( struct V_134 * V_9 )
{
F_8 ( V_9 ) ;
return 0 ;
}
