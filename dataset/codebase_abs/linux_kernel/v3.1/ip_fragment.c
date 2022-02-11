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
static int F_9 ( struct V_17 * V_18 , void * V_21 )
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
struct V_23 * V_24 = V_21 ;
V_22 -> V_20 = V_24 -> V_25 -> V_20 ;
V_22 -> V_8 = V_24 -> V_25 -> V_8 ;
V_22 -> V_32 = F_1 ( V_24 -> V_25 -> V_1 ) ;
V_22 -> V_9 = V_24 -> V_25 -> V_9 ;
V_22 -> V_10 = V_24 -> V_25 -> V_10 ;
V_22 -> V_26 = V_24 -> V_26 ;
V_22 -> V_33 = V_34 ?
F_14 ( V_24 -> V_25 -> V_9 , 1 ) : NULL ;
}
static T_4 void F_15 ( struct V_17 * V_18 )
{
struct V_19 * V_22 ;
V_22 = F_8 ( V_18 , struct V_19 , V_18 ) ;
if ( V_22 -> V_33 )
F_16 ( V_22 -> V_33 ) ;
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
int V_35 ;
V_35 = F_22 ( & V_3 -> V_4 . V_5 , & V_14 ) ;
if ( V_35 )
F_23 ( V_3 , V_36 , V_35 ) ;
}
static void F_24 ( unsigned long V_24 )
{
struct V_19 * V_22 ;
struct V_3 * V_3 ;
V_22 = F_8 ( (struct V_17 * ) V_24 , struct V_19 , V_18 ) ;
V_3 = F_8 ( V_22 -> V_18 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_25 ( & V_22 -> V_18 . V_37 ) ;
if ( V_22 -> V_18 . V_38 & V_39 )
goto V_40;
F_19 ( V_22 ) ;
F_26 ( V_3 , V_41 ) ;
F_26 ( V_3 , V_36 ) ;
if ( ( V_22 -> V_18 . V_38 & V_42 ) && V_22 -> V_18 . V_43 != NULL ) {
struct V_29 * V_44 = V_22 -> V_18 . V_43 ;
const struct V_45 * V_25 ;
int V_46 ;
F_27 () ;
V_44 -> V_47 = F_28 ( V_3 , V_22 -> V_48 ) ;
if ( ! V_44 -> V_47 )
goto V_49;
F_29 ( V_44 ) ;
V_25 = F_30 ( V_44 ) ;
V_46 = F_31 ( V_44 , V_25 -> V_10 , V_25 -> V_9 ,
V_25 -> V_1 , V_44 -> V_47 ) ;
if ( V_46 )
goto V_49;
if ( V_22 -> V_26 == V_50 ||
( V_22 -> V_26 == V_51 &&
F_32 ( V_44 ) -> V_52 != V_53 ) )
goto V_49;
F_33 ( V_44 , V_54 , V_55 , 0 ) ;
V_49:
F_34 () ;
}
V_40:
F_35 ( & V_22 -> V_18 . V_37 ) ;
F_17 ( V_22 ) ;
}
static inline struct V_19 * F_36 ( struct V_3 * V_3 , struct V_45 * V_25 , V_13 V_26 )
{
struct V_17 * V_18 ;
struct V_23 V_24 ;
unsigned int V_56 ;
V_24 . V_25 = V_25 ;
V_24 . V_26 = V_26 ;
F_37 ( & V_14 . V_37 ) ;
V_56 = F_5 ( V_25 -> V_8 , V_25 -> V_9 , V_25 -> V_10 , V_25 -> V_20 ) ;
V_18 = F_38 ( & V_3 -> V_4 . V_5 , & V_14 , & V_24 , V_56 ) ;
if ( V_18 == NULL )
goto V_57;
return F_8 ( V_18 , struct V_19 , V_18 ) ;
V_57:
F_39 ( V_58 L_1 ) ;
return NULL ;
}
static inline int F_40 ( struct V_19 * V_22 )
{
struct V_59 * V_33 = V_22 -> V_33 ;
unsigned int V_60 = V_34 ;
unsigned int V_61 , V_62 ;
int V_63 ;
if ( ! V_33 || ! V_60 )
return 0 ;
V_61 = V_22 -> V_64 ;
V_62 = F_41 ( & V_33 -> V_64 ) ;
V_22 -> V_64 = V_62 ;
V_63 = V_22 -> V_18 . V_43 && ( V_62 - V_61 ) > V_60 ;
if ( V_63 ) {
struct V_3 * V_3 ;
V_3 = F_8 ( V_22 -> V_18 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_26 ( V_3 , V_36 ) ;
}
return V_63 ;
}
static int F_42 ( struct V_19 * V_22 )
{
struct V_29 * V_65 ;
if ( ! F_43 ( & V_22 -> V_18 . V_66 , V_67 + V_22 -> V_18 . V_3 -> V_68 ) ) {
F_44 ( & V_22 -> V_18 . V_69 ) ;
return - V_70 ;
}
V_65 = V_22 -> V_18 . V_43 ;
do {
struct V_29 * V_71 = V_65 -> V_72 ;
F_10 ( V_22 -> V_18 . V_3 , V_65 ) ;
V_65 = V_71 ;
} while ( V_65 );
V_22 -> V_18 . V_38 = 0 ;
V_22 -> V_18 . V_73 = 0 ;
V_22 -> V_18 . V_74 = 0 ;
V_22 -> V_18 . V_43 = NULL ;
V_22 -> V_18 . V_75 = NULL ;
V_22 -> V_48 = 0 ;
V_22 -> V_32 = 0 ;
return 0 ;
}
static int F_45 ( struct V_19 * V_22 , struct V_29 * V_30 )
{
struct V_29 * V_76 , * V_72 ;
struct V_77 * V_47 ;
int V_78 , V_79 ;
int V_80 , V_62 ;
int V_46 = - V_81 ;
T_1 V_32 ;
if ( V_22 -> V_18 . V_38 & V_39 )
goto V_46;
if ( ! ( F_46 ( V_30 ) -> V_78 & V_82 ) &&
F_47 ( F_40 ( V_22 ) ) &&
F_47 ( V_46 = F_42 ( V_22 ) ) ) {
F_19 ( V_22 ) ;
goto V_46;
}
V_32 = F_1 ( F_30 ( V_30 ) -> V_1 ) ;
V_79 = F_48 ( F_30 ( V_30 ) -> V_83 ) ;
V_78 = V_79 & ~ V_84 ;
V_79 &= V_84 ;
V_79 <<= 3 ;
V_80 = F_49 ( V_30 ) ;
V_62 = V_79 + V_30 -> V_73 - V_80 ;
V_46 = - V_85 ;
if ( ( V_78 & V_86 ) == 0 ) {
if ( V_62 < V_22 -> V_18 . V_73 ||
( ( V_22 -> V_18 . V_38 & V_87 ) && V_62 != V_22 -> V_18 . V_73 ) )
goto V_46;
V_22 -> V_18 . V_38 |= V_87 ;
V_22 -> V_18 . V_73 = V_62 ;
} else {
if ( V_62 & 7 ) {
V_62 &= ~ 7 ;
if ( V_30 -> V_88 != V_89 )
V_30 -> V_88 = V_90 ;
}
if ( V_62 > V_22 -> V_18 . V_73 ) {
if ( V_22 -> V_18 . V_38 & V_87 )
goto V_46;
V_22 -> V_18 . V_73 = V_62 ;
}
}
if ( V_62 == V_79 )
goto V_46;
V_46 = - V_91 ;
if ( F_50 ( V_30 , V_80 ) == NULL )
goto V_46;
V_46 = F_51 ( V_30 , V_62 - V_79 ) ;
if ( V_46 )
goto V_46;
V_76 = V_22 -> V_18 . V_75 ;
if ( ! V_76 || F_52 ( V_76 ) -> V_79 < V_79 ) {
V_72 = NULL ;
goto V_92;
}
V_76 = NULL ;
for ( V_72 = V_22 -> V_18 . V_43 ; V_72 != NULL ; V_72 = V_72 -> V_72 ) {
if ( F_52 ( V_72 ) -> V_79 >= V_79 )
break;
V_76 = V_72 ;
}
V_92:
if ( V_76 ) {
int V_93 = ( F_52 ( V_76 ) -> V_79 + V_76 -> V_73 ) - V_79 ;
if ( V_93 > 0 ) {
V_79 += V_93 ;
V_46 = - V_85 ;
if ( V_62 <= V_79 )
goto V_46;
V_46 = - V_91 ;
if ( ! F_50 ( V_30 , V_93 ) )
goto V_46;
if ( V_30 -> V_88 != V_89 )
V_30 -> V_88 = V_90 ;
}
}
V_46 = - V_91 ;
while ( V_72 && F_52 ( V_72 ) -> V_79 < V_62 ) {
int V_93 = V_62 - F_52 ( V_72 ) -> V_79 ;
if ( V_93 < V_72 -> V_73 ) {
if ( ! F_50 ( V_72 , V_93 ) )
goto V_46;
F_52 ( V_72 ) -> V_79 += V_93 ;
V_22 -> V_18 . V_74 -= V_93 ;
if ( V_72 -> V_88 != V_89 )
V_72 -> V_88 = V_90 ;
break;
} else {
struct V_29 * V_94 = V_72 ;
V_72 = V_72 -> V_72 ;
if ( V_76 )
V_76 -> V_72 = V_72 ;
else
V_22 -> V_18 . V_43 = V_72 ;
V_22 -> V_18 . V_74 -= V_94 -> V_73 ;
F_10 ( V_22 -> V_18 . V_3 , V_94 ) ;
}
}
F_52 ( V_30 ) -> V_79 = V_79 ;
V_30 -> V_72 = V_72 ;
if ( ! V_72 )
V_22 -> V_18 . V_75 = V_30 ;
if ( V_76 )
V_76 -> V_72 = V_30 ;
else
V_22 -> V_18 . V_43 = V_30 ;
V_47 = V_30 -> V_47 ;
if ( V_47 ) {
V_22 -> V_48 = V_47 -> V_95 ;
V_30 -> V_47 = NULL ;
}
V_22 -> V_18 . V_96 = V_30 -> V_97 ;
V_22 -> V_18 . V_74 += V_30 -> V_73 ;
V_22 -> V_32 |= V_32 ;
F_53 ( V_30 -> V_31 , & V_22 -> V_18 . V_3 -> V_7 ) ;
if ( V_79 == 0 )
V_22 -> V_18 . V_38 |= V_42 ;
if ( V_22 -> V_18 . V_38 == ( V_42 | V_87 ) &&
V_22 -> V_18 . V_74 == V_22 -> V_18 . V_73 )
return F_54 ( V_22 , V_76 , V_47 ) ;
F_55 ( & V_14 . V_37 ) ;
F_56 ( & V_22 -> V_18 . V_98 , & V_22 -> V_18 . V_3 -> V_98 ) ;
F_57 ( & V_14 . V_37 ) ;
return - V_99 ;
V_46:
F_12 ( V_30 ) ;
return V_46 ;
}
static int F_54 ( struct V_19 * V_22 , struct V_29 * V_76 ,
struct V_77 * V_47 )
{
struct V_3 * V_3 = F_8 ( V_22 -> V_18 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_45 * V_25 ;
struct V_29 * V_65 , * V_44 = V_22 -> V_18 . V_43 ;
int V_73 ;
int V_100 ;
int V_46 ;
T_1 V_32 ;
F_19 ( V_22 ) ;
V_32 = V_101 [ V_22 -> V_32 ] ;
if ( F_47 ( V_32 == 0xff ) ) {
V_46 = - V_85 ;
goto V_102;
}
if ( V_76 ) {
V_44 = V_76 -> V_72 ;
V_65 = F_58 ( V_44 , V_103 ) ;
if ( ! V_65 )
goto V_57;
V_65 -> V_72 = V_44 -> V_72 ;
if ( ! V_65 -> V_72 )
V_22 -> V_18 . V_75 = V_65 ;
V_76 -> V_72 = V_65 ;
F_59 ( V_44 , V_22 -> V_18 . V_43 ) ;
V_44 -> V_72 = V_22 -> V_18 . V_43 -> V_72 ;
F_12 ( V_22 -> V_18 . V_43 ) ;
V_22 -> V_18 . V_43 = V_44 ;
}
F_60 ( V_44 == NULL ) ;
F_60 ( F_52 ( V_44 ) -> V_79 != 0 ) ;
V_100 = F_49 ( V_44 ) ;
V_73 = V_100 + V_22 -> V_18 . V_73 ;
V_46 = - V_104 ;
if ( V_73 > 65535 )
goto V_105;
if ( F_61 ( V_44 ) && F_62 ( V_44 , 0 , 0 , V_103 ) )
goto V_57;
if ( F_63 ( V_44 ) ) {
struct V_29 * V_106 ;
int V_93 , V_107 = 0 ;
if ( ( V_106 = F_64 ( 0 , V_103 ) ) == NULL )
goto V_57;
V_106 -> V_72 = V_44 -> V_72 ;
V_44 -> V_72 = V_106 ;
F_65 ( V_106 ) -> V_108 = F_65 ( V_44 ) -> V_108 ;
F_66 ( V_44 ) ;
for ( V_93 = 0 ; V_93 < F_65 ( V_44 ) -> V_109 ; V_93 ++ )
V_107 += F_65 ( V_44 ) -> V_5 [ V_93 ] . V_110 ;
V_106 -> V_73 = V_106 -> V_111 = V_44 -> V_111 - V_107 ;
V_44 -> V_111 -= V_106 -> V_73 ;
V_44 -> V_73 -= V_106 -> V_73 ;
V_106 -> V_112 = 0 ;
V_106 -> V_88 = V_44 -> V_88 ;
F_53 ( V_106 -> V_31 , & V_22 -> V_18 . V_3 -> V_7 ) ;
}
F_65 ( V_44 ) -> V_108 = V_44 -> V_72 ;
F_67 ( V_44 , V_44 -> V_113 - F_68 ( V_44 ) ) ;
for ( V_65 = V_44 -> V_72 ; V_65 ; V_65 = V_65 -> V_72 ) {
V_44 -> V_111 += V_65 -> V_73 ;
V_44 -> V_73 += V_65 -> V_73 ;
if ( V_44 -> V_88 != V_65 -> V_88 )
V_44 -> V_88 = V_90 ;
else if ( V_44 -> V_88 == V_114 )
V_44 -> V_112 = F_69 ( V_44 -> V_112 , V_65 -> V_112 ) ;
V_44 -> V_31 += V_65 -> V_31 ;
}
F_11 ( V_44 -> V_31 , & V_22 -> V_18 . V_3 -> V_7 ) ;
V_44 -> V_72 = NULL ;
V_44 -> V_47 = V_47 ;
V_44 -> V_97 = V_22 -> V_18 . V_96 ;
V_25 = F_30 ( V_44 ) ;
V_25 -> V_83 = 0 ;
V_25 -> V_115 = F_70 ( V_73 ) ;
V_25 -> V_1 |= V_32 ;
F_26 ( V_3 , V_116 ) ;
V_22 -> V_18 . V_43 = NULL ;
V_22 -> V_18 . V_75 = NULL ;
return 0 ;
V_57:
F_39 ( V_58 L_2
L_3 , V_22 ) ;
V_46 = - V_91 ;
goto V_102;
V_105:
if ( F_71 () )
F_72 ( V_117 L_4 ,
& V_22 -> V_9 ) ;
V_102:
F_26 ( V_3 , V_36 ) ;
return V_46 ;
}
int F_73 ( struct V_29 * V_30 , V_13 V_26 )
{
struct V_19 * V_22 ;
struct V_3 * V_3 ;
V_3 = V_30 -> V_47 ? F_74 ( V_30 -> V_47 ) : F_74 ( F_75 ( V_30 ) -> V_47 ) ;
F_26 ( V_3 , V_118 ) ;
if ( F_4 ( & V_3 -> V_4 . V_5 . V_7 ) > V_3 -> V_4 . V_5 . V_119 )
F_21 ( V_3 ) ;
if ( ( V_22 = F_36 ( V_3 , F_30 ( V_30 ) , V_26 ) ) != NULL ) {
int V_120 ;
F_25 ( & V_22 -> V_18 . V_37 ) ;
V_120 = F_45 ( V_22 , V_30 ) ;
F_35 ( & V_22 -> V_18 . V_37 ) ;
F_17 ( V_22 ) ;
return V_120 ;
}
F_26 ( V_3 , V_36 ) ;
F_12 ( V_30 ) ;
return - V_91 ;
}
static int T_5 F_76 ( struct V_3 * V_3 )
{
struct V_121 * V_122 ;
struct V_123 * V_124 ;
V_122 = V_125 ;
if ( ! F_77 ( V_3 , & V_126 ) ) {
V_122 = F_78 ( V_122 , sizeof( V_125 ) , V_127 ) ;
if ( V_122 == NULL )
goto V_128;
V_122 [ 0 ] . V_113 = & V_3 -> V_4 . V_5 . V_119 ;
V_122 [ 1 ] . V_113 = & V_3 -> V_4 . V_5 . V_129 ;
V_122 [ 2 ] . V_113 = & V_3 -> V_4 . V_5 . V_68 ;
}
V_124 = F_79 ( V_3 , V_130 , V_122 ) ;
if ( V_124 == NULL )
goto V_131;
V_3 -> V_4 . V_132 = V_124 ;
return 0 ;
V_131:
if ( ! F_77 ( V_3 , & V_126 ) )
F_80 ( V_122 ) ;
V_128:
return - V_91 ;
}
static void T_6 F_81 ( struct V_3 * V_3 )
{
struct V_121 * V_122 ;
V_122 = V_3 -> V_4 . V_132 -> V_133 ;
F_82 ( V_3 -> V_4 . V_132 ) ;
F_80 ( V_122 ) ;
}
static void F_83 ( void )
{
F_84 ( V_130 , V_134 ) ;
}
static inline int F_76 ( struct V_3 * V_3 )
{
return 0 ;
}
static inline void F_81 ( struct V_3 * V_3 )
{
}
static inline void F_83 ( void )
{
}
static int T_5 F_85 ( struct V_3 * V_3 )
{
V_3 -> V_4 . V_5 . V_119 = 256 * 1024 ;
V_3 -> V_4 . V_5 . V_129 = 192 * 1024 ;
V_3 -> V_4 . V_5 . V_68 = V_135 ;
F_86 ( & V_3 -> V_4 . V_5 ) ;
return F_76 ( V_3 ) ;
}
static void T_6 F_87 ( struct V_3 * V_3 )
{
F_81 ( V_3 ) ;
F_88 ( & V_3 -> V_4 . V_5 , & V_14 ) ;
}
void T_7 F_89 ( void )
{
F_83 () ;
F_90 ( & V_136 ) ;
V_14 . V_137 = F_7 ;
V_14 . V_138 = F_13 ;
V_14 . V_139 = F_15 ;
V_14 . V_140 = NULL ;
V_14 . V_141 = sizeof( struct V_19 ) ;
V_14 . V_142 = F_9 ;
V_14 . V_143 = F_24 ;
V_14 . V_144 = 10 * 60 * V_145 ;
F_91 ( & V_14 ) ;
}
