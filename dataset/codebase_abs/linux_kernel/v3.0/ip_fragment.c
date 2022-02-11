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
if ( V_22 -> V_26 == V_50 &&
F_32 ( V_44 ) -> V_51 != V_52 )
goto V_49;
F_33 ( V_44 , V_53 , V_54 , 0 ) ;
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
unsigned int V_55 ;
V_24 . V_25 = V_25 ;
V_24 . V_26 = V_26 ;
F_37 ( & V_14 . V_37 ) ;
V_55 = F_5 ( V_25 -> V_8 , V_25 -> V_9 , V_25 -> V_10 , V_25 -> V_20 ) ;
V_18 = F_38 ( & V_3 -> V_4 . V_5 , & V_14 , & V_24 , V_55 ) ;
if ( V_18 == NULL )
goto V_56;
return F_8 ( V_18 , struct V_19 , V_18 ) ;
V_56:
F_39 ( V_57 L_1 ) ;
return NULL ;
}
static inline int F_40 ( struct V_19 * V_22 )
{
struct V_58 * V_33 = V_22 -> V_33 ;
unsigned int V_59 = V_34 ;
unsigned int V_60 , V_61 ;
int V_62 ;
if ( ! V_33 || ! V_59 )
return 0 ;
V_60 = V_22 -> V_63 ;
V_61 = F_41 ( & V_33 -> V_63 ) ;
V_22 -> V_63 = V_61 ;
V_62 = V_22 -> V_18 . V_43 && ( V_61 - V_60 ) > V_59 ;
if ( V_62 ) {
struct V_3 * V_3 ;
V_3 = F_8 ( V_22 -> V_18 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_26 ( V_3 , V_36 ) ;
}
return V_62 ;
}
static int F_42 ( struct V_19 * V_22 )
{
struct V_29 * V_64 ;
if ( ! F_43 ( & V_22 -> V_18 . V_65 , V_66 + V_22 -> V_18 . V_3 -> V_67 ) ) {
F_44 ( & V_22 -> V_18 . V_68 ) ;
return - V_69 ;
}
V_64 = V_22 -> V_18 . V_43 ;
do {
struct V_29 * V_70 = V_64 -> V_71 ;
F_10 ( V_22 -> V_18 . V_3 , V_64 ) ;
V_64 = V_70 ;
} while ( V_64 );
V_22 -> V_18 . V_38 = 0 ;
V_22 -> V_18 . V_72 = 0 ;
V_22 -> V_18 . V_73 = 0 ;
V_22 -> V_18 . V_43 = NULL ;
V_22 -> V_18 . V_74 = NULL ;
V_22 -> V_48 = 0 ;
V_22 -> V_32 = 0 ;
return 0 ;
}
static int F_45 ( struct V_19 * V_22 , struct V_29 * V_30 )
{
struct V_29 * V_75 , * V_71 ;
struct V_76 * V_47 ;
int V_77 , V_78 ;
int V_79 , V_61 ;
int V_46 = - V_80 ;
T_1 V_32 ;
if ( V_22 -> V_18 . V_38 & V_39 )
goto V_46;
if ( ! ( F_46 ( V_30 ) -> V_77 & V_81 ) &&
F_47 ( F_40 ( V_22 ) ) &&
F_47 ( V_46 = F_42 ( V_22 ) ) ) {
F_19 ( V_22 ) ;
goto V_46;
}
V_32 = F_1 ( F_30 ( V_30 ) -> V_1 ) ;
V_78 = F_48 ( F_30 ( V_30 ) -> V_82 ) ;
V_77 = V_78 & ~ V_83 ;
V_78 &= V_83 ;
V_78 <<= 3 ;
V_79 = F_49 ( V_30 ) ;
V_61 = V_78 + V_30 -> V_72 - V_79 ;
V_46 = - V_84 ;
if ( ( V_77 & V_85 ) == 0 ) {
if ( V_61 < V_22 -> V_18 . V_72 ||
( ( V_22 -> V_18 . V_38 & V_86 ) && V_61 != V_22 -> V_18 . V_72 ) )
goto V_46;
V_22 -> V_18 . V_38 |= V_86 ;
V_22 -> V_18 . V_72 = V_61 ;
} else {
if ( V_61 & 7 ) {
V_61 &= ~ 7 ;
if ( V_30 -> V_87 != V_88 )
V_30 -> V_87 = V_89 ;
}
if ( V_61 > V_22 -> V_18 . V_72 ) {
if ( V_22 -> V_18 . V_38 & V_86 )
goto V_46;
V_22 -> V_18 . V_72 = V_61 ;
}
}
if ( V_61 == V_78 )
goto V_46;
V_46 = - V_90 ;
if ( F_50 ( V_30 , V_79 ) == NULL )
goto V_46;
V_46 = F_51 ( V_30 , V_61 - V_78 ) ;
if ( V_46 )
goto V_46;
V_75 = V_22 -> V_18 . V_74 ;
if ( ! V_75 || F_52 ( V_75 ) -> V_78 < V_78 ) {
V_71 = NULL ;
goto V_91;
}
V_75 = NULL ;
for ( V_71 = V_22 -> V_18 . V_43 ; V_71 != NULL ; V_71 = V_71 -> V_71 ) {
if ( F_52 ( V_71 ) -> V_78 >= V_78 )
break;
V_75 = V_71 ;
}
V_91:
if ( V_75 ) {
int V_92 = ( F_52 ( V_75 ) -> V_78 + V_75 -> V_72 ) - V_78 ;
if ( V_92 > 0 ) {
V_78 += V_92 ;
V_46 = - V_84 ;
if ( V_61 <= V_78 )
goto V_46;
V_46 = - V_90 ;
if ( ! F_50 ( V_30 , V_92 ) )
goto V_46;
if ( V_30 -> V_87 != V_88 )
V_30 -> V_87 = V_89 ;
}
}
V_46 = - V_90 ;
while ( V_71 && F_52 ( V_71 ) -> V_78 < V_61 ) {
int V_92 = V_61 - F_52 ( V_71 ) -> V_78 ;
if ( V_92 < V_71 -> V_72 ) {
if ( ! F_50 ( V_71 , V_92 ) )
goto V_46;
F_52 ( V_71 ) -> V_78 += V_92 ;
V_22 -> V_18 . V_73 -= V_92 ;
if ( V_71 -> V_87 != V_88 )
V_71 -> V_87 = V_89 ;
break;
} else {
struct V_29 * V_93 = V_71 ;
V_71 = V_71 -> V_71 ;
if ( V_75 )
V_75 -> V_71 = V_71 ;
else
V_22 -> V_18 . V_43 = V_71 ;
V_22 -> V_18 . V_73 -= V_93 -> V_72 ;
F_10 ( V_22 -> V_18 . V_3 , V_93 ) ;
}
}
F_52 ( V_30 ) -> V_78 = V_78 ;
V_30 -> V_71 = V_71 ;
if ( ! V_71 )
V_22 -> V_18 . V_74 = V_30 ;
if ( V_75 )
V_75 -> V_71 = V_30 ;
else
V_22 -> V_18 . V_43 = V_30 ;
V_47 = V_30 -> V_47 ;
if ( V_47 ) {
V_22 -> V_48 = V_47 -> V_94 ;
V_30 -> V_47 = NULL ;
}
V_22 -> V_18 . V_95 = V_30 -> V_96 ;
V_22 -> V_18 . V_73 += V_30 -> V_72 ;
V_22 -> V_32 |= V_32 ;
F_53 ( V_30 -> V_31 , & V_22 -> V_18 . V_3 -> V_7 ) ;
if ( V_78 == 0 )
V_22 -> V_18 . V_38 |= V_42 ;
if ( V_22 -> V_18 . V_38 == ( V_42 | V_86 ) &&
V_22 -> V_18 . V_73 == V_22 -> V_18 . V_72 )
return F_54 ( V_22 , V_75 , V_47 ) ;
F_55 ( & V_14 . V_37 ) ;
F_56 ( & V_22 -> V_18 . V_97 , & V_22 -> V_18 . V_3 -> V_97 ) ;
F_57 ( & V_14 . V_37 ) ;
return - V_98 ;
V_46:
F_12 ( V_30 ) ;
return V_46 ;
}
static int F_54 ( struct V_19 * V_22 , struct V_29 * V_75 ,
struct V_76 * V_47 )
{
struct V_3 * V_3 = F_8 ( V_22 -> V_18 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_45 * V_25 ;
struct V_29 * V_64 , * V_44 = V_22 -> V_18 . V_43 ;
int V_72 ;
int V_99 ;
int V_46 ;
T_1 V_32 ;
F_19 ( V_22 ) ;
V_32 = V_100 [ V_22 -> V_32 ] ;
if ( F_47 ( V_32 == 0xff ) ) {
V_46 = - V_84 ;
goto V_101;
}
if ( V_75 ) {
V_44 = V_75 -> V_71 ;
V_64 = F_58 ( V_44 , V_102 ) ;
if ( ! V_64 )
goto V_56;
V_64 -> V_71 = V_44 -> V_71 ;
if ( ! V_64 -> V_71 )
V_22 -> V_18 . V_74 = V_64 ;
V_75 -> V_71 = V_64 ;
F_59 ( V_44 , V_22 -> V_18 . V_43 ) ;
V_44 -> V_71 = V_22 -> V_18 . V_43 -> V_71 ;
F_12 ( V_22 -> V_18 . V_43 ) ;
V_22 -> V_18 . V_43 = V_44 ;
}
F_60 ( V_44 == NULL ) ;
F_60 ( F_52 ( V_44 ) -> V_78 != 0 ) ;
V_99 = F_49 ( V_44 ) ;
V_72 = V_99 + V_22 -> V_18 . V_72 ;
V_46 = - V_103 ;
if ( V_72 > 65535 )
goto V_104;
if ( F_61 ( V_44 ) && F_62 ( V_44 , 0 , 0 , V_102 ) )
goto V_56;
if ( F_63 ( V_44 ) ) {
struct V_29 * V_105 ;
int V_92 , V_106 = 0 ;
if ( ( V_105 = F_64 ( 0 , V_102 ) ) == NULL )
goto V_56;
V_105 -> V_71 = V_44 -> V_71 ;
V_44 -> V_71 = V_105 ;
F_65 ( V_105 ) -> V_107 = F_65 ( V_44 ) -> V_107 ;
F_66 ( V_44 ) ;
for ( V_92 = 0 ; V_92 < F_65 ( V_44 ) -> V_108 ; V_92 ++ )
V_106 += F_65 ( V_44 ) -> V_5 [ V_92 ] . V_109 ;
V_105 -> V_72 = V_105 -> V_110 = V_44 -> V_110 - V_106 ;
V_44 -> V_110 -= V_105 -> V_72 ;
V_44 -> V_72 -= V_105 -> V_72 ;
V_105 -> V_111 = 0 ;
V_105 -> V_87 = V_44 -> V_87 ;
F_53 ( V_105 -> V_31 , & V_22 -> V_18 . V_3 -> V_7 ) ;
}
F_65 ( V_44 ) -> V_107 = V_44 -> V_71 ;
F_67 ( V_44 , V_44 -> V_112 - F_68 ( V_44 ) ) ;
for ( V_64 = V_44 -> V_71 ; V_64 ; V_64 = V_64 -> V_71 ) {
V_44 -> V_110 += V_64 -> V_72 ;
V_44 -> V_72 += V_64 -> V_72 ;
if ( V_44 -> V_87 != V_64 -> V_87 )
V_44 -> V_87 = V_89 ;
else if ( V_44 -> V_87 == V_113 )
V_44 -> V_111 = F_69 ( V_44 -> V_111 , V_64 -> V_111 ) ;
V_44 -> V_31 += V_64 -> V_31 ;
}
F_11 ( V_44 -> V_31 , & V_22 -> V_18 . V_3 -> V_7 ) ;
V_44 -> V_71 = NULL ;
V_44 -> V_47 = V_47 ;
V_44 -> V_96 = V_22 -> V_18 . V_95 ;
V_25 = F_30 ( V_44 ) ;
V_25 -> V_82 = 0 ;
V_25 -> V_114 = F_70 ( V_72 ) ;
V_25 -> V_1 |= V_32 ;
F_26 ( V_3 , V_115 ) ;
V_22 -> V_18 . V_43 = NULL ;
V_22 -> V_18 . V_74 = NULL ;
return 0 ;
V_56:
F_39 ( V_57 L_2
L_3 , V_22 ) ;
V_46 = - V_90 ;
goto V_101;
V_104:
if ( F_71 () )
F_72 ( V_116 L_4 ,
& V_22 -> V_9 ) ;
V_101:
F_26 ( V_3 , V_36 ) ;
return V_46 ;
}
int F_73 ( struct V_29 * V_30 , V_13 V_26 )
{
struct V_19 * V_22 ;
struct V_3 * V_3 ;
V_3 = V_30 -> V_47 ? F_74 ( V_30 -> V_47 ) : F_74 ( F_75 ( V_30 ) -> V_47 ) ;
F_26 ( V_3 , V_117 ) ;
if ( F_4 ( & V_3 -> V_4 . V_5 . V_7 ) > V_3 -> V_4 . V_5 . V_118 )
F_21 ( V_3 ) ;
if ( ( V_22 = F_36 ( V_3 , F_30 ( V_30 ) , V_26 ) ) != NULL ) {
int V_119 ;
F_25 ( & V_22 -> V_18 . V_37 ) ;
V_119 = F_45 ( V_22 , V_30 ) ;
F_35 ( & V_22 -> V_18 . V_37 ) ;
F_17 ( V_22 ) ;
return V_119 ;
}
F_26 ( V_3 , V_36 ) ;
F_12 ( V_30 ) ;
return - V_90 ;
}
static int T_5 F_76 ( struct V_3 * V_3 )
{
struct V_120 * V_121 ;
struct V_122 * V_123 ;
V_121 = V_124 ;
if ( ! F_77 ( V_3 , & V_125 ) ) {
V_121 = F_78 ( V_121 , sizeof( V_124 ) , V_126 ) ;
if ( V_121 == NULL )
goto V_127;
V_121 [ 0 ] . V_112 = & V_3 -> V_4 . V_5 . V_118 ;
V_121 [ 1 ] . V_112 = & V_3 -> V_4 . V_5 . V_128 ;
V_121 [ 2 ] . V_112 = & V_3 -> V_4 . V_5 . V_67 ;
}
V_123 = F_79 ( V_3 , V_129 , V_121 ) ;
if ( V_123 == NULL )
goto V_130;
V_3 -> V_4 . V_131 = V_123 ;
return 0 ;
V_130:
if ( ! F_77 ( V_3 , & V_125 ) )
F_80 ( V_121 ) ;
V_127:
return - V_90 ;
}
static void T_6 F_81 ( struct V_3 * V_3 )
{
struct V_120 * V_121 ;
V_121 = V_3 -> V_4 . V_131 -> V_132 ;
F_82 ( V_3 -> V_4 . V_131 ) ;
F_80 ( V_121 ) ;
}
static void F_83 ( void )
{
F_84 ( V_129 , V_133 ) ;
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
V_3 -> V_4 . V_5 . V_118 = 256 * 1024 ;
V_3 -> V_4 . V_5 . V_128 = 192 * 1024 ;
V_3 -> V_4 . V_5 . V_67 = V_134 ;
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
F_90 ( & V_135 ) ;
V_14 . V_136 = F_7 ;
V_14 . V_137 = F_13 ;
V_14 . V_138 = F_15 ;
V_14 . V_139 = NULL ;
V_14 . V_140 = sizeof( struct V_19 ) ;
V_14 . V_141 = F_9 ;
V_14 . V_142 = F_24 ;
V_14 . V_143 = 10 * 60 * V_144 ;
F_91 ( & V_14 ) ;
}
