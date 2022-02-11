static inline T_1 F_1 ( T_1 V_1 )
{
return 1 << ( V_1 & V_2 ) ;
}
int F_2 ( struct V_3 * V_3 )
{
return V_3 -> V_4 . V_5 . V_6 ;
}
int F_3 ( struct V_3 * V_3 )
{
return F_4 ( & V_3 -> V_4 . V_5 . V_7 ) ;
}
static unsigned int F_5 ( T_2 V_8 , T_3 V_9 , T_3 V_10 , T_1 V_11 )
{
return F_6 ( ( V_12 V_13 ) V_8 << 16 | V_11 ,
( V_12 V_13 ) V_9 , ( V_12 V_13 ) V_10 ,
V_14 . V_15 ) & ( V_16 - 1 ) ;
}
static unsigned int F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_19 ;
V_19 = F_8 ( V_18 , struct V_19 , V_18 ) ;
return F_5 ( V_19 -> V_8 , V_19 -> V_9 , V_19 -> V_10 , V_19 -> V_20 ) ;
}
static bool F_9 ( struct V_17 * V_18 , void * V_21 )
{
struct V_19 * V_22 ;
struct V_23 * V_24 = V_21 ;
V_22 = F_8 ( V_18 , struct V_19 , V_18 ) ;
return V_22 -> V_8 == V_24 -> V_25 -> V_8 &&
V_22 -> V_9 == V_24 -> V_25 -> V_9 &&
V_22 -> V_10 == V_24 -> V_25 -> V_10 &&
V_22 -> V_20 == V_24 -> V_25 -> V_20 &&
V_22 -> V_26 == V_24 -> V_26 ;
}
static void F_10 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
F_11 ( V_30 -> V_31 , & V_28 -> V_7 ) ;
F_12 ( V_30 ) ;
}
static void F_13 ( struct V_17 * V_18 , void * V_21 )
{
struct V_19 * V_22 = F_8 ( V_18 , struct V_19 , V_18 ) ;
struct V_32 * V_4 = F_8 ( V_18 -> V_3 , struct V_32 ,
V_5 ) ;
struct V_3 * V_3 = F_8 ( V_4 , struct V_3 , V_4 ) ;
struct V_23 * V_24 = V_21 ;
V_22 -> V_20 = V_24 -> V_25 -> V_20 ;
V_22 -> V_8 = V_24 -> V_25 -> V_8 ;
V_22 -> V_33 = F_1 ( V_24 -> V_25 -> V_1 ) ;
V_22 -> V_9 = V_24 -> V_25 -> V_9 ;
V_22 -> V_10 = V_24 -> V_25 -> V_10 ;
V_22 -> V_26 = V_24 -> V_26 ;
V_22 -> V_34 = V_35 ?
F_14 ( V_3 -> V_4 . V_36 , V_24 -> V_25 -> V_9 , 1 ) : NULL ;
}
static T_4 void F_15 ( struct V_17 * V_18 )
{
struct V_19 * V_22 ;
V_22 = F_8 ( V_18 , struct V_19 , V_18 ) ;
if ( V_22 -> V_34 )
F_16 ( V_22 -> V_34 ) ;
}
static T_4 void F_17 ( struct V_19 * V_19 )
{
F_18 ( & V_19 -> V_18 , & V_14 ) ;
}
static void F_19 ( struct V_19 * V_19 )
{
F_20 ( & V_19 -> V_18 , & V_14 ) ;
}
static void F_21 ( struct V_3 * V_3 )
{
int V_37 ;
V_37 = F_22 ( & V_3 -> V_4 . V_5 , & V_14 , false ) ;
if ( V_37 )
F_23 ( V_3 , V_38 , V_37 ) ;
}
static void F_24 ( unsigned long V_24 )
{
struct V_19 * V_22 ;
struct V_3 * V_3 ;
V_22 = F_8 ( (struct V_17 * ) V_24 , struct V_19 , V_18 ) ;
V_3 = F_8 ( V_22 -> V_18 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_25 ( & V_22 -> V_18 . V_39 ) ;
if ( V_22 -> V_18 . V_40 & V_41 )
goto V_42;
F_19 ( V_22 ) ;
F_26 ( V_3 , V_43 ) ;
F_26 ( V_3 , V_38 ) ;
if ( ( V_22 -> V_18 . V_40 & V_44 ) && V_22 -> V_18 . V_45 != NULL ) {
struct V_29 * V_46 = V_22 -> V_18 . V_45 ;
const struct V_47 * V_25 ;
int V_48 ;
F_27 () ;
V_46 -> V_49 = F_28 ( V_3 , V_22 -> V_50 ) ;
if ( ! V_46 -> V_49 )
goto V_51;
F_29 ( V_46 ) ;
V_25 = F_30 ( V_46 ) ;
V_48 = F_31 ( V_46 , V_25 -> V_10 , V_25 -> V_9 ,
V_25 -> V_1 , V_46 -> V_49 ) ;
if ( V_48 )
goto V_51;
if ( V_22 -> V_26 == V_52 ||
( V_22 -> V_26 == V_53 &&
F_32 ( V_46 ) -> V_54 != V_55 ) )
goto V_51;
F_33 ( V_46 , V_56 , V_57 , 0 ) ;
V_51:
F_34 () ;
}
V_42:
F_35 ( & V_22 -> V_18 . V_39 ) ;
F_17 ( V_22 ) ;
}
static inline struct V_19 * F_36 ( struct V_3 * V_3 , struct V_47 * V_25 , V_13 V_26 )
{
struct V_17 * V_18 ;
struct V_23 V_24 ;
unsigned int V_58 ;
V_24 . V_25 = V_25 ;
V_24 . V_26 = V_26 ;
F_37 ( & V_14 . V_39 ) ;
V_58 = F_5 ( V_25 -> V_8 , V_25 -> V_9 , V_25 -> V_10 , V_25 -> V_20 ) ;
V_18 = F_38 ( & V_3 -> V_4 . V_5 , & V_14 , & V_24 , V_58 ) ;
if ( V_18 == NULL )
goto V_59;
return F_8 ( V_18 , struct V_19 , V_18 ) ;
V_59:
F_39 (KERN_ERR pr_fmt(L_1)) ;
return NULL ;
}
static inline int F_40 ( struct V_19 * V_22 )
{
struct V_60 * V_34 = V_22 -> V_34 ;
unsigned int V_61 = V_35 ;
unsigned int V_62 , V_63 ;
int V_64 ;
if ( ! V_34 || ! V_61 )
return 0 ;
V_62 = V_22 -> V_65 ;
V_63 = F_41 ( & V_34 -> V_65 ) ;
V_22 -> V_65 = V_63 ;
V_64 = V_22 -> V_18 . V_45 && ( V_63 - V_62 ) > V_61 ;
if ( V_64 ) {
struct V_3 * V_3 ;
V_3 = F_8 ( V_22 -> V_18 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_26 ( V_3 , V_38 ) ;
}
return V_64 ;
}
static int F_42 ( struct V_19 * V_22 )
{
struct V_29 * V_66 ;
if ( ! F_43 ( & V_22 -> V_18 . V_67 , V_68 + V_22 -> V_18 . V_3 -> V_69 ) ) {
F_44 ( & V_22 -> V_18 . V_70 ) ;
return - V_71 ;
}
V_66 = V_22 -> V_18 . V_45 ;
do {
struct V_29 * V_72 = V_66 -> V_73 ;
F_10 ( V_22 -> V_18 . V_3 , V_66 ) ;
V_66 = V_72 ;
} while ( V_66 );
V_22 -> V_18 . V_40 = 0 ;
V_22 -> V_18 . V_74 = 0 ;
V_22 -> V_18 . V_75 = 0 ;
V_22 -> V_18 . V_45 = NULL ;
V_22 -> V_18 . V_76 = NULL ;
V_22 -> V_50 = 0 ;
V_22 -> V_33 = 0 ;
return 0 ;
}
static int F_45 ( struct V_19 * V_22 , struct V_29 * V_30 )
{
struct V_29 * V_77 , * V_73 ;
struct V_78 * V_49 ;
int V_79 , V_80 ;
int V_81 , V_63 ;
int V_48 = - V_82 ;
T_1 V_33 ;
if ( V_22 -> V_18 . V_40 & V_41 )
goto V_48;
if ( ! ( F_46 ( V_30 ) -> V_79 & V_83 ) &&
F_47 ( F_40 ( V_22 ) ) &&
F_47 ( V_48 = F_42 ( V_22 ) ) ) {
F_19 ( V_22 ) ;
goto V_48;
}
V_33 = F_1 ( F_30 ( V_30 ) -> V_1 ) ;
V_80 = F_48 ( F_30 ( V_30 ) -> V_84 ) ;
V_79 = V_80 & ~ V_85 ;
V_80 &= V_85 ;
V_80 <<= 3 ;
V_81 = F_49 ( V_30 ) ;
V_63 = V_80 + V_30 -> V_74 - V_81 ;
V_48 = - V_86 ;
if ( ( V_79 & V_87 ) == 0 ) {
if ( V_63 < V_22 -> V_18 . V_74 ||
( ( V_22 -> V_18 . V_40 & V_88 ) && V_63 != V_22 -> V_18 . V_74 ) )
goto V_48;
V_22 -> V_18 . V_40 |= V_88 ;
V_22 -> V_18 . V_74 = V_63 ;
} else {
if ( V_63 & 7 ) {
V_63 &= ~ 7 ;
if ( V_30 -> V_89 != V_90 )
V_30 -> V_89 = V_91 ;
}
if ( V_63 > V_22 -> V_18 . V_74 ) {
if ( V_22 -> V_18 . V_40 & V_88 )
goto V_48;
V_22 -> V_18 . V_74 = V_63 ;
}
}
if ( V_63 == V_80 )
goto V_48;
V_48 = - V_92 ;
if ( F_50 ( V_30 , V_81 ) == NULL )
goto V_48;
V_48 = F_51 ( V_30 , V_63 - V_80 ) ;
if ( V_48 )
goto V_48;
V_77 = V_22 -> V_18 . V_76 ;
if ( ! V_77 || F_52 ( V_77 ) -> V_80 < V_80 ) {
V_73 = NULL ;
goto V_93;
}
V_77 = NULL ;
for ( V_73 = V_22 -> V_18 . V_45 ; V_73 != NULL ; V_73 = V_73 -> V_73 ) {
if ( F_52 ( V_73 ) -> V_80 >= V_80 )
break;
V_77 = V_73 ;
}
V_93:
if ( V_77 ) {
int V_94 = ( F_52 ( V_77 ) -> V_80 + V_77 -> V_74 ) - V_80 ;
if ( V_94 > 0 ) {
V_80 += V_94 ;
V_48 = - V_86 ;
if ( V_63 <= V_80 )
goto V_48;
V_48 = - V_92 ;
if ( ! F_50 ( V_30 , V_94 ) )
goto V_48;
if ( V_30 -> V_89 != V_90 )
V_30 -> V_89 = V_91 ;
}
}
V_48 = - V_92 ;
while ( V_73 && F_52 ( V_73 ) -> V_80 < V_63 ) {
int V_94 = V_63 - F_52 ( V_73 ) -> V_80 ;
if ( V_94 < V_73 -> V_74 ) {
if ( ! F_50 ( V_73 , V_94 ) )
goto V_48;
F_52 ( V_73 ) -> V_80 += V_94 ;
V_22 -> V_18 . V_75 -= V_94 ;
if ( V_73 -> V_89 != V_90 )
V_73 -> V_89 = V_91 ;
break;
} else {
struct V_29 * V_95 = V_73 ;
V_73 = V_73 -> V_73 ;
if ( V_77 )
V_77 -> V_73 = V_73 ;
else
V_22 -> V_18 . V_45 = V_73 ;
V_22 -> V_18 . V_75 -= V_95 -> V_74 ;
F_10 ( V_22 -> V_18 . V_3 , V_95 ) ;
}
}
F_52 ( V_30 ) -> V_80 = V_80 ;
V_30 -> V_73 = V_73 ;
if ( ! V_73 )
V_22 -> V_18 . V_76 = V_30 ;
if ( V_77 )
V_77 -> V_73 = V_30 ;
else
V_22 -> V_18 . V_45 = V_30 ;
V_49 = V_30 -> V_49 ;
if ( V_49 ) {
V_22 -> V_50 = V_49 -> V_96 ;
V_30 -> V_49 = NULL ;
}
V_22 -> V_18 . V_97 = V_30 -> V_98 ;
V_22 -> V_18 . V_75 += V_30 -> V_74 ;
V_22 -> V_33 |= V_33 ;
F_53 ( V_30 -> V_31 , & V_22 -> V_18 . V_3 -> V_7 ) ;
if ( V_80 == 0 )
V_22 -> V_18 . V_40 |= V_44 ;
if ( F_30 ( V_30 ) -> V_84 & F_54 ( V_99 ) &&
V_30 -> V_74 + V_81 > V_22 -> V_18 . V_100 )
V_22 -> V_18 . V_100 = V_30 -> V_74 + V_81 ;
if ( V_22 -> V_18 . V_40 == ( V_44 | V_88 ) &&
V_22 -> V_18 . V_75 == V_22 -> V_18 . V_74 )
return F_55 ( V_22 , V_77 , V_49 ) ;
F_56 ( & V_14 . V_39 ) ;
F_57 ( & V_22 -> V_18 . V_101 , & V_22 -> V_18 . V_3 -> V_101 ) ;
F_58 ( & V_14 . V_39 ) ;
return - V_102 ;
V_48:
F_12 ( V_30 ) ;
return V_48 ;
}
static int F_55 ( struct V_19 * V_22 , struct V_29 * V_77 ,
struct V_78 * V_49 )
{
struct V_3 * V_3 = F_8 ( V_22 -> V_18 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_47 * V_25 ;
struct V_29 * V_66 , * V_46 = V_22 -> V_18 . V_45 ;
int V_74 ;
int V_103 ;
int V_48 ;
int V_104 ;
T_1 V_33 ;
F_19 ( V_22 ) ;
V_33 = V_105 [ V_22 -> V_33 ] ;
if ( F_47 ( V_33 == 0xff ) ) {
V_48 = - V_86 ;
goto V_106;
}
if ( V_77 ) {
V_46 = V_77 -> V_73 ;
V_66 = F_59 ( V_46 , V_107 ) ;
if ( ! V_66 )
goto V_59;
V_66 -> V_73 = V_46 -> V_73 ;
if ( ! V_66 -> V_73 )
V_22 -> V_18 . V_76 = V_66 ;
V_77 -> V_73 = V_66 ;
F_60 ( V_46 , V_22 -> V_18 . V_45 ) ;
V_46 -> V_73 = V_22 -> V_18 . V_45 -> V_73 ;
F_61 ( V_22 -> V_18 . V_45 ) ;
V_22 -> V_18 . V_45 = V_46 ;
}
F_62 ( V_46 == NULL ) ;
F_62 ( F_52 ( V_46 ) -> V_80 != 0 ) ;
V_103 = F_49 ( V_46 ) ;
V_74 = V_103 + V_22 -> V_18 . V_74 ;
V_48 = - V_108 ;
if ( V_74 > 65535 )
goto V_109;
if ( F_63 ( V_46 ) && F_64 ( V_46 , 0 , 0 , V_107 ) )
goto V_59;
if ( F_65 ( V_46 ) ) {
struct V_29 * V_110 ;
int V_94 , V_111 = 0 ;
if ( ( V_110 = F_66 ( 0 , V_107 ) ) == NULL )
goto V_59;
V_110 -> V_73 = V_46 -> V_73 ;
V_46 -> V_73 = V_110 ;
F_67 ( V_110 ) -> V_112 = F_67 ( V_46 ) -> V_112 ;
F_68 ( V_46 ) ;
for ( V_94 = 0 ; V_94 < F_67 ( V_46 ) -> V_113 ; V_94 ++ )
V_111 += F_69 ( & F_67 ( V_46 ) -> V_5 [ V_94 ] ) ;
V_110 -> V_74 = V_110 -> V_114 = V_46 -> V_114 - V_111 ;
V_46 -> V_114 -= V_110 -> V_74 ;
V_46 -> V_74 -= V_110 -> V_74 ;
V_110 -> V_115 = 0 ;
V_110 -> V_89 = V_46 -> V_89 ;
F_53 ( V_110 -> V_31 , & V_22 -> V_18 . V_3 -> V_7 ) ;
}
F_70 ( V_46 , V_46 -> V_116 - F_71 ( V_46 ) ) ;
V_104 = V_46 -> V_31 ;
for ( V_66 = V_46 -> V_73 ; V_66 ; ) {
bool V_117 ;
int V_118 ;
struct V_29 * V_73 = V_66 -> V_73 ;
V_104 += V_66 -> V_31 ;
if ( V_46 -> V_89 != V_66 -> V_89 )
V_46 -> V_89 = V_91 ;
else if ( V_46 -> V_89 == V_119 )
V_46 -> V_115 = F_72 ( V_46 -> V_115 , V_66 -> V_115 ) ;
if ( F_73 ( V_46 , V_66 , & V_117 , & V_118 ) ) {
F_74 ( V_66 , V_117 ) ;
} else {
if ( ! F_67 ( V_46 ) -> V_112 )
F_67 ( V_46 ) -> V_112 = V_66 ;
V_46 -> V_114 += V_66 -> V_74 ;
V_46 -> V_74 += V_66 -> V_74 ;
V_46 -> V_31 += V_66 -> V_31 ;
}
V_66 = V_73 ;
}
F_11 ( V_104 , & V_22 -> V_18 . V_3 -> V_7 ) ;
V_46 -> V_73 = NULL ;
V_46 -> V_49 = V_49 ;
V_46 -> V_98 = V_22 -> V_18 . V_97 ;
F_46 ( V_46 ) -> V_120 = V_22 -> V_18 . V_100 ;
V_25 = F_30 ( V_46 ) ;
V_25 -> V_84 = V_22 -> V_18 . V_100 ? F_54 ( V_99 ) : 0 ;
V_25 -> V_121 = F_54 ( V_74 ) ;
V_25 -> V_1 |= V_33 ;
F_26 ( V_3 , V_122 ) ;
V_22 -> V_18 . V_45 = NULL ;
V_22 -> V_18 . V_76 = NULL ;
return 0 ;
V_59:
F_39 (KERN_ERR pr_fmt(L_2),
qp) ;
V_48 = - V_92 ;
goto V_106;
V_109:
F_75 ( L_3 , & V_22 -> V_9 ) ;
V_106:
F_26 ( V_3 , V_38 ) ;
return V_48 ;
}
int F_76 ( struct V_29 * V_30 , V_13 V_26 )
{
struct V_19 * V_22 ;
struct V_3 * V_3 ;
V_3 = V_30 -> V_49 ? F_77 ( V_30 -> V_49 ) : F_77 ( F_78 ( V_30 ) -> V_49 ) ;
F_26 ( V_3 , V_123 ) ;
F_21 ( V_3 ) ;
if ( ( V_22 = F_36 ( V_3 , F_30 ( V_30 ) , V_26 ) ) != NULL ) {
int V_124 ;
F_25 ( & V_22 -> V_18 . V_39 ) ;
V_124 = F_45 ( V_22 , V_30 ) ;
F_35 ( & V_22 -> V_18 . V_39 ) ;
F_17 ( V_22 ) ;
return V_124 ;
}
F_26 ( V_3 , V_38 ) ;
F_12 ( V_30 ) ;
return - V_92 ;
}
struct V_29 * F_79 ( struct V_29 * V_30 , V_13 V_26 )
{
struct V_47 V_25 ;
V_13 V_74 ;
if ( V_30 -> V_20 != F_54 ( V_125 ) )
return V_30 ;
if ( ! F_80 ( V_30 , 0 , & V_25 , sizeof( V_25 ) ) )
return V_30 ;
if ( V_25 . V_81 < 5 || V_25 . V_126 != 4 )
return V_30 ;
V_74 = F_48 ( V_25 . V_121 ) ;
if ( V_30 -> V_74 < V_74 || V_74 < ( V_25 . V_81 * 4 ) )
return V_30 ;
if ( F_81 ( & V_25 ) ) {
V_30 = F_82 ( V_30 , V_107 ) ;
if ( V_30 ) {
if ( ! F_83 ( V_30 , V_25 . V_81 * 4 ) )
return V_30 ;
if ( F_51 ( V_30 , V_74 ) )
return V_30 ;
memset ( F_46 ( V_30 ) , 0 , sizeof( struct V_127 ) ) ;
if ( F_76 ( V_30 , V_26 ) )
return NULL ;
V_30 -> V_128 = 0 ;
}
}
return V_30 ;
}
static int T_5 F_84 ( struct V_3 * V_3 )
{
struct V_129 * V_130 ;
struct V_131 * V_132 ;
V_130 = V_133 ;
if ( ! F_85 ( V_3 , & V_134 ) ) {
V_130 = F_86 ( V_130 , sizeof( V_133 ) , V_135 ) ;
if ( V_130 == NULL )
goto V_136;
V_130 [ 0 ] . V_116 = & V_3 -> V_4 . V_5 . V_137 ;
V_130 [ 1 ] . V_116 = & V_3 -> V_4 . V_5 . V_138 ;
V_130 [ 2 ] . V_116 = & V_3 -> V_4 . V_5 . V_69 ;
if ( V_3 -> V_139 != & V_140 )
V_130 [ 0 ] . V_141 = NULL ;
}
V_132 = F_87 ( V_3 , L_4 , V_130 ) ;
if ( V_132 == NULL )
goto V_142;
V_3 -> V_4 . V_143 = V_132 ;
return 0 ;
V_142:
if ( ! F_85 ( V_3 , & V_134 ) )
F_88 ( V_130 ) ;
V_136:
return - V_92 ;
}
static void T_6 F_89 ( struct V_3 * V_3 )
{
struct V_129 * V_130 ;
V_130 = V_3 -> V_4 . V_143 -> V_144 ;
F_90 ( V_3 -> V_4 . V_143 ) ;
F_88 ( V_130 ) ;
}
static void F_91 ( void )
{
F_87 ( & V_134 , L_4 , V_145 ) ;
}
static inline int F_84 ( struct V_3 * V_3 )
{
return 0 ;
}
static inline void F_89 ( struct V_3 * V_3 )
{
}
static inline void F_91 ( void )
{
}
static int T_5 F_92 ( struct V_3 * V_3 )
{
V_3 -> V_4 . V_5 . V_137 = 256 * 1024 ;
V_3 -> V_4 . V_5 . V_138 = 192 * 1024 ;
V_3 -> V_4 . V_5 . V_69 = V_146 ;
F_93 ( & V_3 -> V_4 . V_5 ) ;
return F_84 ( V_3 ) ;
}
static void T_6 F_94 ( struct V_3 * V_3 )
{
F_89 ( V_3 ) ;
F_95 ( & V_3 -> V_4 . V_5 , & V_14 ) ;
}
void T_7 F_96 ( void )
{
F_91 () ;
F_97 ( & V_147 ) ;
V_14 . V_148 = F_7 ;
V_14 . V_149 = F_13 ;
V_14 . V_150 = F_15 ;
V_14 . V_151 = NULL ;
V_14 . V_152 = sizeof( struct V_19 ) ;
V_14 . V_153 = F_9 ;
V_14 . V_154 = F_24 ;
V_14 . V_155 = 10 * 60 * V_156 ;
F_98 ( & V_14 ) ;
}
