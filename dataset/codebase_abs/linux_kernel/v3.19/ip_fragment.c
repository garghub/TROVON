static T_1 F_1 ( T_1 V_1 )
{
return 1 << ( V_1 & V_2 ) ;
}
int F_2 ( struct V_3 * V_3 )
{
return F_3 ( & V_3 -> V_4 . V_5 ) ;
}
static unsigned int F_4 ( T_2 V_6 , T_3 V_7 , T_3 V_8 , T_1 V_9 )
{
F_5 ( & V_10 . V_11 , sizeof( V_10 . V_11 ) ) ;
return F_6 ( ( V_12 V_13 ) V_6 << 16 | V_9 ,
( V_12 V_13 ) V_7 , ( V_12 V_13 ) V_8 ,
V_10 . V_11 ) ;
}
static unsigned int F_7 ( const struct V_14 * V_15 )
{
const struct V_16 * V_16 ;
V_16 = F_8 ( V_15 , struct V_16 , V_15 ) ;
return F_4 ( V_16 -> V_6 , V_16 -> V_7 , V_16 -> V_8 , V_16 -> V_17 ) ;
}
static bool F_9 ( const struct V_14 * V_15 , const void * V_18 )
{
const struct V_16 * V_19 ;
const struct V_20 * V_21 = V_18 ;
V_19 = F_8 ( V_15 , struct V_16 , V_15 ) ;
return V_19 -> V_6 == V_21 -> V_22 -> V_6 &&
V_19 -> V_7 == V_21 -> V_22 -> V_7 &&
V_19 -> V_8 == V_21 -> V_22 -> V_8 &&
V_19 -> V_17 == V_21 -> V_22 -> V_17 &&
V_19 -> V_23 == V_21 -> V_23 ;
}
static void F_10 ( struct V_14 * V_15 , const void * V_18 )
{
struct V_16 * V_19 = F_8 ( V_15 , struct V_16 , V_15 ) ;
struct V_24 * V_4 = F_8 ( V_15 -> V_3 , struct V_24 ,
V_5 ) ;
struct V_3 * V_3 = F_8 ( V_4 , struct V_3 , V_4 ) ;
const struct V_20 * V_21 = V_18 ;
V_19 -> V_17 = V_21 -> V_22 -> V_17 ;
V_19 -> V_6 = V_21 -> V_22 -> V_6 ;
V_19 -> V_25 = F_1 ( V_21 -> V_22 -> V_1 ) ;
V_19 -> V_7 = V_21 -> V_22 -> V_7 ;
V_19 -> V_8 = V_21 -> V_22 -> V_8 ;
V_19 -> V_23 = V_21 -> V_23 ;
V_19 -> V_26 = V_27 ?
F_11 ( V_3 -> V_4 . V_28 , V_21 -> V_22 -> V_7 , 1 ) : NULL ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_19 ;
V_19 = F_8 ( V_15 , struct V_16 , V_15 ) ;
if ( V_19 -> V_26 )
F_13 ( V_19 -> V_26 ) ;
}
static void F_14 ( struct V_16 * V_16 )
{
F_15 ( & V_16 -> V_15 , & V_10 ) ;
}
static void F_16 ( struct V_16 * V_16 )
{
F_17 ( & V_16 -> V_15 , & V_10 ) ;
}
static void F_18 ( unsigned long V_21 )
{
struct V_16 * V_19 ;
struct V_3 * V_3 ;
V_19 = F_8 ( (struct V_14 * ) V_21 , struct V_16 , V_15 ) ;
V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_19 ( & V_19 -> V_15 . V_29 ) ;
if ( V_19 -> V_15 . V_30 & V_31 )
goto V_32;
F_16 ( V_19 ) ;
F_20 ( V_3 , V_33 ) ;
if ( ! ( V_19 -> V_15 . V_30 & V_34 ) ) {
struct V_35 * V_36 = V_19 -> V_15 . V_37 ;
const struct V_38 * V_22 ;
int V_39 ;
F_20 ( V_3 , V_40 ) ;
if ( ! ( V_19 -> V_15 . V_30 & V_41 ) || ! V_19 -> V_15 . V_37 )
goto V_32;
F_21 () ;
V_36 -> V_42 = F_22 ( V_3 , V_19 -> V_43 ) ;
if ( ! V_36 -> V_42 )
goto V_44;
V_22 = F_23 ( V_36 ) ;
V_39 = F_24 ( V_36 , V_22 -> V_8 , V_22 -> V_7 ,
V_22 -> V_1 , V_36 -> V_42 ) ;
if ( V_39 )
goto V_44;
if ( V_19 -> V_23 == V_45 ||
( ( V_19 -> V_23 >= V_46 ) &&
( V_19 -> V_23 <= V_47 ) &&
( F_25 ( V_36 ) -> V_48 != V_49 ) ) )
goto V_44;
F_26 ( V_36 , V_50 , V_51 , 0 ) ;
V_44:
F_27 () ;
}
V_32:
F_28 ( & V_19 -> V_15 . V_29 ) ;
F_14 ( V_19 ) ;
}
static struct V_16 * F_29 ( struct V_3 * V_3 , struct V_38 * V_22 , V_13 V_23 )
{
struct V_14 * V_15 ;
struct V_20 V_21 ;
unsigned int V_52 ;
V_21 . V_22 = V_22 ;
V_21 . V_23 = V_23 ;
V_52 = F_4 ( V_22 -> V_6 , V_22 -> V_7 , V_22 -> V_8 , V_22 -> V_17 ) ;
V_15 = F_30 ( & V_3 -> V_4 . V_5 , & V_10 , & V_21 , V_52 ) ;
if ( F_31 ( V_15 ) ) {
F_32 ( V_15 , F_33 () ) ;
return NULL ;
}
return F_8 ( V_15 , struct V_16 , V_15 ) ;
}
static int F_34 ( struct V_16 * V_19 )
{
struct V_53 * V_26 = V_19 -> V_26 ;
unsigned int V_54 = V_27 ;
unsigned int V_55 , V_56 ;
int V_57 ;
if ( ! V_26 || ! V_54 )
return 0 ;
V_55 = V_19 -> V_58 ;
V_56 = F_35 ( & V_26 -> V_58 ) ;
V_19 -> V_58 = V_56 ;
V_57 = V_19 -> V_15 . V_37 && ( V_56 - V_55 ) > V_54 ;
if ( V_57 ) {
struct V_3 * V_3 ;
V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_20 ( V_3 , V_33 ) ;
}
return V_57 ;
}
static int F_36 ( struct V_16 * V_19 )
{
struct V_35 * V_59 ;
unsigned int V_60 = 0 ;
if ( ! F_37 ( & V_19 -> V_15 . V_61 , V_62 + V_19 -> V_15 . V_3 -> V_63 ) ) {
F_38 ( & V_19 -> V_15 . V_64 ) ;
return - V_65 ;
}
V_59 = V_19 -> V_15 . V_37 ;
do {
struct V_35 * V_66 = V_59 -> V_67 ;
V_60 += V_59 -> V_68 ;
F_39 ( V_59 ) ;
V_59 = V_66 ;
} while ( V_59 );
F_40 ( & V_19 -> V_15 , V_60 ) ;
V_19 -> V_15 . V_30 = 0 ;
V_19 -> V_15 . V_69 = 0 ;
V_19 -> V_15 . V_70 = 0 ;
V_19 -> V_15 . V_37 = NULL ;
V_19 -> V_15 . V_71 = NULL ;
V_19 -> V_43 = 0 ;
V_19 -> V_25 = 0 ;
return 0 ;
}
static int F_41 ( struct V_16 * V_19 , struct V_35 * V_72 )
{
struct V_35 * V_73 , * V_67 ;
struct V_74 * V_42 ;
int V_30 , V_75 ;
int V_76 , V_56 ;
int V_39 = - V_77 ;
T_1 V_25 ;
if ( V_19 -> V_15 . V_30 & V_31 )
goto V_39;
if ( ! ( F_42 ( V_72 ) -> V_30 & V_78 ) &&
F_43 ( F_34 ( V_19 ) ) &&
F_43 ( V_39 = F_36 ( V_19 ) ) ) {
F_16 ( V_19 ) ;
goto V_39;
}
V_25 = F_1 ( F_23 ( V_72 ) -> V_1 ) ;
V_75 = F_44 ( F_23 ( V_72 ) -> V_79 ) ;
V_30 = V_75 & ~ V_80 ;
V_75 &= V_80 ;
V_75 <<= 3 ;
V_76 = F_45 ( V_72 ) ;
V_56 = V_75 + V_72 -> V_69 - V_76 ;
V_39 = - V_81 ;
if ( ( V_30 & V_82 ) == 0 ) {
if ( V_56 < V_19 -> V_15 . V_69 ||
( ( V_19 -> V_15 . V_30 & V_83 ) && V_56 != V_19 -> V_15 . V_69 ) )
goto V_39;
V_19 -> V_15 . V_30 |= V_83 ;
V_19 -> V_15 . V_69 = V_56 ;
} else {
if ( V_56 & 7 ) {
V_56 &= ~ 7 ;
if ( V_72 -> V_84 != V_85 )
V_72 -> V_84 = V_86 ;
}
if ( V_56 > V_19 -> V_15 . V_69 ) {
if ( V_19 -> V_15 . V_30 & V_83 )
goto V_39;
V_19 -> V_15 . V_69 = V_56 ;
}
}
if ( V_56 == V_75 )
goto V_39;
V_39 = - V_87 ;
if ( F_46 ( V_72 , V_76 ) == NULL )
goto V_39;
V_39 = F_47 ( V_72 , V_56 - V_75 ) ;
if ( V_39 )
goto V_39;
V_73 = V_19 -> V_15 . V_71 ;
if ( ! V_73 || F_48 ( V_73 ) -> V_75 < V_75 ) {
V_67 = NULL ;
goto V_88;
}
V_73 = NULL ;
for ( V_67 = V_19 -> V_15 . V_37 ; V_67 != NULL ; V_67 = V_67 -> V_67 ) {
if ( F_48 ( V_67 ) -> V_75 >= V_75 )
break;
V_73 = V_67 ;
}
V_88:
if ( V_73 ) {
int V_89 = ( F_48 ( V_73 ) -> V_75 + V_73 -> V_69 ) - V_75 ;
if ( V_89 > 0 ) {
V_75 += V_89 ;
V_39 = - V_81 ;
if ( V_56 <= V_75 )
goto V_39;
V_39 = - V_87 ;
if ( ! F_46 ( V_72 , V_89 ) )
goto V_39;
if ( V_72 -> V_84 != V_85 )
V_72 -> V_84 = V_86 ;
}
}
V_39 = - V_87 ;
while ( V_67 && F_48 ( V_67 ) -> V_75 < V_56 ) {
int V_89 = V_56 - F_48 ( V_67 ) -> V_75 ;
if ( V_89 < V_67 -> V_69 ) {
if ( ! F_46 ( V_67 , V_89 ) )
goto V_39;
F_48 ( V_67 ) -> V_75 += V_89 ;
V_19 -> V_15 . V_70 -= V_89 ;
if ( V_67 -> V_84 != V_85 )
V_67 -> V_84 = V_86 ;
break;
} else {
struct V_35 * V_90 = V_67 ;
V_67 = V_67 -> V_67 ;
if ( V_73 )
V_73 -> V_67 = V_67 ;
else
V_19 -> V_15 . V_37 = V_67 ;
V_19 -> V_15 . V_70 -= V_90 -> V_69 ;
F_40 ( & V_19 -> V_15 , V_90 -> V_68 ) ;
F_39 ( V_90 ) ;
}
}
F_48 ( V_72 ) -> V_75 = V_75 ;
V_72 -> V_67 = V_67 ;
if ( ! V_67 )
V_19 -> V_15 . V_71 = V_72 ;
if ( V_73 )
V_73 -> V_67 = V_72 ;
else
V_19 -> V_15 . V_37 = V_72 ;
V_42 = V_72 -> V_42 ;
if ( V_42 ) {
V_19 -> V_43 = V_42 -> V_91 ;
V_72 -> V_42 = NULL ;
}
V_19 -> V_15 . V_92 = V_72 -> V_93 ;
V_19 -> V_15 . V_70 += V_72 -> V_69 ;
V_19 -> V_25 |= V_25 ;
F_49 ( & V_19 -> V_15 , V_72 -> V_68 ) ;
if ( V_75 == 0 )
V_19 -> V_15 . V_30 |= V_41 ;
if ( F_23 ( V_72 ) -> V_79 & F_50 ( V_94 ) &&
V_72 -> V_69 + V_76 > V_19 -> V_15 . V_95 )
V_19 -> V_15 . V_95 = V_72 -> V_69 + V_76 ;
if ( V_19 -> V_15 . V_30 == ( V_41 | V_83 ) &&
V_19 -> V_15 . V_70 == V_19 -> V_15 . V_69 ) {
unsigned long V_96 = V_72 -> V_97 ;
V_72 -> V_97 = 0UL ;
V_39 = F_51 ( V_19 , V_73 , V_42 ) ;
V_72 -> V_97 = V_96 ;
return V_39 ;
}
F_52 ( V_72 ) ;
return - V_98 ;
V_39:
F_39 ( V_72 ) ;
return V_39 ;
}
static int F_51 ( struct V_16 * V_19 , struct V_35 * V_73 ,
struct V_74 * V_42 )
{
struct V_3 * V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_38 * V_22 ;
struct V_35 * V_59 , * V_36 = V_19 -> V_15 . V_37 ;
int V_69 ;
int V_99 ;
int V_39 ;
int V_60 ;
T_1 V_25 ;
F_16 ( V_19 ) ;
V_25 = V_100 [ V_19 -> V_25 ] ;
if ( F_43 ( V_25 == 0xff ) ) {
V_39 = - V_81 ;
goto V_101;
}
if ( V_73 ) {
V_36 = V_73 -> V_67 ;
V_59 = F_53 ( V_36 , V_102 ) ;
if ( ! V_59 )
goto V_103;
V_59 -> V_67 = V_36 -> V_67 ;
if ( ! V_59 -> V_67 )
V_19 -> V_15 . V_71 = V_59 ;
V_73 -> V_67 = V_59 ;
F_54 ( V_36 , V_19 -> V_15 . V_37 ) ;
V_36 -> V_67 = V_19 -> V_15 . V_37 -> V_67 ;
F_55 ( V_19 -> V_15 . V_37 ) ;
V_19 -> V_15 . V_37 = V_36 ;
}
F_56 ( V_36 == NULL ) ;
F_56 ( F_48 ( V_36 ) -> V_75 != 0 ) ;
V_99 = F_45 ( V_36 ) ;
V_69 = V_99 + V_19 -> V_15 . V_69 ;
V_39 = - V_104 ;
if ( V_69 > 65535 )
goto V_105;
if ( F_57 ( V_36 , V_102 ) )
goto V_103;
if ( F_58 ( V_36 ) ) {
struct V_35 * V_106 ;
int V_89 , V_107 = 0 ;
if ( ( V_106 = F_59 ( 0 , V_102 ) ) == NULL )
goto V_103;
V_106 -> V_67 = V_36 -> V_67 ;
V_36 -> V_67 = V_106 ;
F_60 ( V_106 ) -> V_108 = F_60 ( V_36 ) -> V_108 ;
F_61 ( V_36 ) ;
for ( V_89 = 0 ; V_89 < F_60 ( V_36 ) -> V_109 ; V_89 ++ )
V_107 += F_62 ( & F_60 ( V_36 ) -> V_5 [ V_89 ] ) ;
V_106 -> V_69 = V_106 -> V_110 = V_36 -> V_110 - V_107 ;
V_36 -> V_110 -= V_106 -> V_69 ;
V_36 -> V_69 -= V_106 -> V_69 ;
V_106 -> V_111 = 0 ;
V_106 -> V_84 = V_36 -> V_84 ;
F_49 ( & V_19 -> V_15 , V_106 -> V_68 ) ;
}
F_63 ( V_36 , V_36 -> V_112 - F_64 ( V_36 ) ) ;
V_60 = V_36 -> V_68 ;
for ( V_59 = V_36 -> V_67 ; V_59 ; ) {
bool V_113 ;
int V_114 ;
struct V_35 * V_67 = V_59 -> V_67 ;
V_60 += V_59 -> V_68 ;
if ( V_36 -> V_84 != V_59 -> V_84 )
V_36 -> V_84 = V_86 ;
else if ( V_36 -> V_84 == V_115 )
V_36 -> V_111 = F_65 ( V_36 -> V_111 , V_59 -> V_111 ) ;
if ( F_66 ( V_36 , V_59 , & V_113 , & V_114 ) ) {
F_67 ( V_59 , V_113 ) ;
} else {
if ( ! F_60 ( V_36 ) -> V_108 )
F_60 ( V_36 ) -> V_108 = V_59 ;
V_36 -> V_110 += V_59 -> V_69 ;
V_36 -> V_69 += V_59 -> V_69 ;
V_36 -> V_68 += V_59 -> V_68 ;
}
V_59 = V_67 ;
}
F_40 ( & V_19 -> V_15 , V_60 ) ;
V_36 -> V_67 = NULL ;
V_36 -> V_42 = V_42 ;
V_36 -> V_93 = V_19 -> V_15 . V_92 ;
F_42 ( V_36 ) -> V_116 = V_19 -> V_15 . V_95 ;
V_22 = F_23 ( V_36 ) ;
V_22 -> V_79 = V_19 -> V_15 . V_95 ? F_50 ( V_94 ) : 0 ;
V_22 -> V_117 = F_50 ( V_69 ) ;
V_22 -> V_1 |= V_25 ;
F_20 ( V_3 , V_118 ) ;
V_19 -> V_15 . V_37 = NULL ;
V_19 -> V_15 . V_71 = NULL ;
return 0 ;
V_103:
F_68 ( L_1 , V_19 ) ;
V_39 = - V_87 ;
goto V_101;
V_105:
F_69 ( L_2 , & V_19 -> V_7 ) ;
V_101:
F_20 ( V_3 , V_33 ) ;
return V_39 ;
}
int F_70 ( struct V_35 * V_72 , V_13 V_23 )
{
struct V_16 * V_19 ;
struct V_3 * V_3 ;
V_3 = V_72 -> V_42 ? F_71 ( V_72 -> V_42 ) : F_71 ( F_72 ( V_72 ) -> V_42 ) ;
F_20 ( V_3 , V_119 ) ;
if ( ( V_19 = F_29 ( V_3 , F_23 ( V_72 ) , V_23 ) ) != NULL ) {
int V_120 ;
F_19 ( & V_19 -> V_15 . V_29 ) ;
V_120 = F_41 ( V_19 , V_72 ) ;
F_28 ( & V_19 -> V_15 . V_29 ) ;
F_14 ( V_19 ) ;
return V_120 ;
}
F_20 ( V_3 , V_33 ) ;
F_39 ( V_72 ) ;
return - V_87 ;
}
struct V_35 * F_73 ( struct V_35 * V_72 , V_13 V_23 )
{
struct V_38 V_22 ;
V_13 V_69 ;
if ( V_72 -> V_17 != F_50 ( V_121 ) )
return V_72 ;
if ( ! F_74 ( V_72 , 0 , & V_22 , sizeof( V_22 ) ) )
return V_72 ;
if ( V_22 . V_76 < 5 || V_22 . V_122 != 4 )
return V_72 ;
V_69 = F_44 ( V_22 . V_117 ) ;
if ( V_72 -> V_69 < V_69 || V_69 < ( V_22 . V_76 * 4 ) )
return V_72 ;
if ( F_75 ( & V_22 ) ) {
V_72 = F_76 ( V_72 , V_102 ) ;
if ( V_72 ) {
if ( ! F_77 ( V_72 , V_22 . V_76 * 4 ) )
return V_72 ;
if ( F_47 ( V_72 , V_69 ) )
return V_72 ;
memset ( F_42 ( V_72 ) , 0 , sizeof( struct V_123 ) ) ;
if ( F_70 ( V_72 , V_23 ) )
return NULL ;
F_78 ( V_72 ) ;
}
}
return V_72 ;
}
static int T_4 F_79 ( struct V_3 * V_3 )
{
struct V_124 * V_125 ;
struct V_126 * V_127 ;
V_125 = V_128 ;
if ( ! F_80 ( V_3 , & V_129 ) ) {
V_125 = F_81 ( V_125 , sizeof( V_128 ) , V_130 ) ;
if ( V_125 == NULL )
goto V_131;
V_125 [ 0 ] . V_112 = & V_3 -> V_4 . V_5 . V_132 ;
V_125 [ 0 ] . V_133 = & V_3 -> V_4 . V_5 . V_134 ;
V_125 [ 0 ] . V_135 = & V_129 . V_4 . V_5 . V_132 ;
V_125 [ 1 ] . V_112 = & V_3 -> V_4 . V_5 . V_134 ;
V_125 [ 1 ] . V_135 = & V_3 -> V_4 . V_5 . V_132 ;
V_125 [ 2 ] . V_112 = & V_3 -> V_4 . V_5 . V_63 ;
if ( V_3 -> V_136 != & V_137 )
V_125 [ 0 ] . V_138 = NULL ;
}
V_127 = F_82 ( V_3 , L_3 , V_125 ) ;
if ( V_127 == NULL )
goto V_139;
V_3 -> V_4 . V_140 = V_127 ;
return 0 ;
V_139:
if ( ! F_80 ( V_3 , & V_129 ) )
F_83 ( V_125 ) ;
V_131:
return - V_87 ;
}
static void T_5 F_84 ( struct V_3 * V_3 )
{
struct V_124 * V_125 ;
V_125 = V_3 -> V_4 . V_140 -> V_141 ;
F_85 ( V_3 -> V_4 . V_140 ) ;
F_83 ( V_125 ) ;
}
static void T_6 F_86 ( void )
{
F_82 ( & V_129 , L_3 , V_142 ) ;
}
static int F_79 ( struct V_3 * V_3 )
{
return 0 ;
}
static void F_84 ( struct V_3 * V_3 )
{
}
static void T_6 F_86 ( void )
{
}
static int T_4 F_87 ( struct V_3 * V_3 )
{
V_3 -> V_4 . V_5 . V_132 = 4 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_134 = 3 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_63 = V_143 ;
F_88 ( & V_3 -> V_4 . V_5 ) ;
return F_79 ( V_3 ) ;
}
static void T_5 F_89 ( struct V_3 * V_3 )
{
F_84 ( V_3 ) ;
F_90 ( & V_3 -> V_4 . V_5 , & V_10 ) ;
}
void T_6 F_91 ( void )
{
F_86 () ;
F_92 ( & V_144 ) ;
V_10 . V_145 = F_7 ;
V_10 . V_146 = F_10 ;
V_10 . V_147 = F_12 ;
V_10 . V_148 = NULL ;
V_10 . V_149 = sizeof( struct V_16 ) ;
V_10 . V_150 = F_9 ;
V_10 . V_151 = F_18 ;
V_10 . V_152 = V_153 ;
if ( F_93 ( & V_10 ) )
F_94 ( L_4 ) ;
}
