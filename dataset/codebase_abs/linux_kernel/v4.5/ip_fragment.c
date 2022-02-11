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
V_19 -> V_23 == V_21 -> V_23 &&
V_19 -> V_24 == V_21 -> V_24 ;
}
static void F_10 ( struct V_14 * V_15 , const void * V_18 )
{
struct V_16 * V_19 = F_8 ( V_15 , struct V_16 , V_15 ) ;
struct V_25 * V_4 = F_8 ( V_15 -> V_3 , struct V_25 ,
V_5 ) ;
struct V_3 * V_3 = F_8 ( V_4 , struct V_3 , V_4 ) ;
const struct V_20 * V_21 = V_18 ;
V_19 -> V_17 = V_21 -> V_22 -> V_17 ;
V_19 -> V_6 = V_21 -> V_22 -> V_6 ;
V_19 -> V_26 = F_1 ( V_21 -> V_22 -> V_1 ) ;
V_19 -> V_7 = V_21 -> V_22 -> V_7 ;
V_19 -> V_8 = V_21 -> V_22 -> V_8 ;
V_19 -> V_24 = V_21 -> V_24 ;
V_19 -> V_23 = V_21 -> V_23 ;
V_19 -> V_27 = V_28 ?
F_11 ( V_3 -> V_4 . V_29 , V_21 -> V_22 -> V_7 , V_21 -> V_24 , 1 ) :
NULL ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_16 * V_19 ;
V_19 = F_8 ( V_15 , struct V_16 , V_15 ) ;
if ( V_19 -> V_27 )
F_13 ( V_19 -> V_27 ) ;
}
static void F_14 ( struct V_16 * V_16 )
{
F_15 ( & V_16 -> V_15 , & V_10 ) ;
}
static void F_16 ( struct V_16 * V_16 )
{
F_17 ( & V_16 -> V_15 , & V_10 ) ;
}
static bool F_18 ( V_13 V_23 )
{
return V_23 == V_30 ||
F_19 ( V_23 , V_31 ,
V_32 ) ||
F_19 ( V_23 , V_33 ,
V_34 ) ;
}
static void F_20 ( unsigned long V_21 )
{
struct V_16 * V_19 ;
struct V_3 * V_3 ;
V_19 = F_8 ( (struct V_14 * ) V_21 , struct V_16 , V_15 ) ;
V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_21 ( & V_19 -> V_15 . V_35 ) ;
if ( V_19 -> V_15 . V_36 & V_37 )
goto V_38;
F_16 ( V_19 ) ;
F_22 ( V_3 , V_39 ) ;
if ( ! F_23 ( & V_19 -> V_15 ) ) {
struct V_40 * V_41 = V_19 -> V_15 . V_42 ;
const struct V_43 * V_22 ;
int V_44 ;
F_22 ( V_3 , V_45 ) ;
if ( ! ( V_19 -> V_15 . V_36 & V_46 ) || ! V_19 -> V_15 . V_42 )
goto V_38;
F_24 () ;
V_41 -> V_47 = F_25 ( V_3 , V_19 -> V_48 ) ;
if ( ! V_41 -> V_47 )
goto V_49;
V_22 = F_26 ( V_41 ) ;
V_44 = F_27 ( V_41 , V_22 -> V_8 , V_22 -> V_7 ,
V_22 -> V_1 , V_41 -> V_47 ) ;
if ( V_44 )
goto V_49;
if ( F_18 ( V_19 -> V_23 ) &&
( F_28 ( V_41 ) -> V_50 != V_51 ) )
goto V_49;
F_29 ( V_41 , V_52 , V_53 , 0 ) ;
V_49:
F_30 () ;
}
V_38:
F_31 ( & V_19 -> V_15 . V_35 ) ;
F_14 ( V_19 ) ;
}
static struct V_16 * F_32 ( struct V_3 * V_3 , struct V_43 * V_22 ,
V_13 V_23 , int V_24 )
{
struct V_14 * V_15 ;
struct V_20 V_21 ;
unsigned int V_54 ;
V_21 . V_22 = V_22 ;
V_21 . V_23 = V_23 ;
V_21 . V_24 = V_24 ;
V_54 = F_4 ( V_22 -> V_6 , V_22 -> V_7 , V_22 -> V_8 , V_22 -> V_17 ) ;
V_15 = F_33 ( & V_3 -> V_4 . V_5 , & V_10 , & V_21 , V_54 ) ;
if ( F_34 ( V_15 ) ) {
F_35 ( V_15 , F_36 () ) ;
return NULL ;
}
return F_8 ( V_15 , struct V_16 , V_15 ) ;
}
static int F_37 ( struct V_16 * V_19 )
{
struct V_55 * V_27 = V_19 -> V_27 ;
unsigned int V_56 = V_28 ;
unsigned int V_57 , V_58 ;
int V_59 ;
if ( ! V_27 || ! V_56 )
return 0 ;
V_57 = V_19 -> V_60 ;
V_58 = F_38 ( & V_27 -> V_60 ) ;
V_19 -> V_60 = V_58 ;
V_59 = V_19 -> V_15 . V_42 && ( V_58 - V_57 ) > V_56 ;
if ( V_59 ) {
struct V_3 * V_3 ;
V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_22 ( V_3 , V_39 ) ;
}
return V_59 ;
}
static int F_39 ( struct V_16 * V_19 )
{
struct V_40 * V_61 ;
unsigned int V_62 = 0 ;
if ( ! F_40 ( & V_19 -> V_15 . V_63 , V_64 + V_19 -> V_15 . V_3 -> V_65 ) ) {
F_41 ( & V_19 -> V_15 . V_66 ) ;
return - V_67 ;
}
V_61 = V_19 -> V_15 . V_42 ;
do {
struct V_40 * V_68 = V_61 -> V_69 ;
V_62 += V_61 -> V_70 ;
F_42 ( V_61 ) ;
V_61 = V_68 ;
} while ( V_61 );
F_43 ( V_19 -> V_15 . V_3 , V_62 ) ;
V_19 -> V_15 . V_36 = 0 ;
V_19 -> V_15 . V_71 = 0 ;
V_19 -> V_15 . V_72 = 0 ;
V_19 -> V_15 . V_42 = NULL ;
V_19 -> V_15 . V_73 = NULL ;
V_19 -> V_48 = 0 ;
V_19 -> V_26 = 0 ;
return 0 ;
}
static int F_44 ( struct V_16 * V_19 , struct V_40 * V_74 )
{
struct V_40 * V_75 , * V_69 ;
struct V_76 * V_47 ;
unsigned int V_77 ;
int V_36 , V_78 ;
int V_79 , V_58 ;
int V_44 = - V_80 ;
T_1 V_26 ;
if ( V_19 -> V_15 . V_36 & V_37 )
goto V_44;
if ( ! ( F_45 ( V_74 ) -> V_36 & V_81 ) &&
F_46 ( F_37 ( V_19 ) ) &&
F_46 ( V_44 = F_39 ( V_19 ) ) ) {
F_16 ( V_19 ) ;
goto V_44;
}
V_26 = F_1 ( F_26 ( V_74 ) -> V_1 ) ;
V_78 = F_47 ( F_26 ( V_74 ) -> V_82 ) ;
V_36 = V_78 & ~ V_83 ;
V_78 &= V_83 ;
V_78 <<= 3 ;
V_79 = F_48 ( V_74 ) ;
V_58 = V_78 + V_74 -> V_71 - F_49 ( V_74 ) - V_79 ;
V_44 = - V_84 ;
if ( ( V_36 & V_85 ) == 0 ) {
if ( V_58 < V_19 -> V_15 . V_71 ||
( ( V_19 -> V_15 . V_36 & V_86 ) && V_58 != V_19 -> V_15 . V_71 ) )
goto V_44;
V_19 -> V_15 . V_36 |= V_86 ;
V_19 -> V_15 . V_71 = V_58 ;
} else {
if ( V_58 & 7 ) {
V_58 &= ~ 7 ;
if ( V_74 -> V_87 != V_88 )
V_74 -> V_87 = V_89 ;
}
if ( V_58 > V_19 -> V_15 . V_71 ) {
if ( V_19 -> V_15 . V_36 & V_86 )
goto V_44;
V_19 -> V_15 . V_71 = V_58 ;
}
}
if ( V_58 == V_78 )
goto V_44;
V_44 = - V_90 ;
if ( ! F_50 ( V_74 , F_49 ( V_74 ) + V_79 ) )
goto V_44;
V_44 = F_51 ( V_74 , V_58 - V_78 ) ;
if ( V_44 )
goto V_44;
V_75 = V_19 -> V_15 . V_73 ;
if ( ! V_75 || F_52 ( V_75 ) -> V_78 < V_78 ) {
V_69 = NULL ;
goto V_91;
}
V_75 = NULL ;
for ( V_69 = V_19 -> V_15 . V_42 ; V_69 != NULL ; V_69 = V_69 -> V_69 ) {
if ( F_52 ( V_69 ) -> V_78 >= V_78 )
break;
V_75 = V_69 ;
}
V_91:
if ( V_75 ) {
int V_92 = ( F_52 ( V_75 ) -> V_78 + V_75 -> V_71 ) - V_78 ;
if ( V_92 > 0 ) {
V_78 += V_92 ;
V_44 = - V_84 ;
if ( V_58 <= V_78 )
goto V_44;
V_44 = - V_90 ;
if ( ! F_50 ( V_74 , V_92 ) )
goto V_44;
if ( V_74 -> V_87 != V_88 )
V_74 -> V_87 = V_89 ;
}
}
V_44 = - V_90 ;
while ( V_69 && F_52 ( V_69 ) -> V_78 < V_58 ) {
int V_92 = V_58 - F_52 ( V_69 ) -> V_78 ;
if ( V_92 < V_69 -> V_71 ) {
if ( ! F_50 ( V_69 , V_92 ) )
goto V_44;
F_52 ( V_69 ) -> V_78 += V_92 ;
V_19 -> V_15 . V_72 -= V_92 ;
if ( V_69 -> V_87 != V_88 )
V_69 -> V_87 = V_89 ;
break;
} else {
struct V_40 * V_93 = V_69 ;
V_69 = V_69 -> V_69 ;
if ( V_75 )
V_75 -> V_69 = V_69 ;
else
V_19 -> V_15 . V_42 = V_69 ;
V_19 -> V_15 . V_72 -= V_93 -> V_71 ;
F_43 ( V_19 -> V_15 . V_3 , V_93 -> V_70 ) ;
F_42 ( V_93 ) ;
}
}
F_52 ( V_74 ) -> V_78 = V_78 ;
V_74 -> V_69 = V_69 ;
if ( ! V_69 )
V_19 -> V_15 . V_73 = V_74 ;
if ( V_75 )
V_75 -> V_69 = V_74 ;
else
V_19 -> V_15 . V_42 = V_74 ;
V_47 = V_74 -> V_47 ;
if ( V_47 ) {
V_19 -> V_48 = V_47 -> V_94 ;
V_74 -> V_47 = NULL ;
}
V_19 -> V_15 . V_95 = V_74 -> V_96 ;
V_19 -> V_15 . V_72 += V_74 -> V_71 ;
V_19 -> V_26 |= V_26 ;
F_53 ( V_19 -> V_15 . V_3 , V_74 -> V_70 ) ;
if ( V_78 == 0 )
V_19 -> V_15 . V_36 |= V_46 ;
V_77 = V_74 -> V_71 + V_79 ;
if ( V_77 > V_19 -> V_15 . V_97 )
V_19 -> V_15 . V_97 = V_77 ;
if ( F_26 ( V_74 ) -> V_82 & F_54 ( V_98 ) &&
V_77 > V_19 -> V_99 )
V_19 -> V_99 = V_77 ;
if ( V_19 -> V_15 . V_36 == ( V_46 | V_86 ) &&
V_19 -> V_15 . V_72 == V_19 -> V_15 . V_71 ) {
unsigned long V_100 = V_74 -> V_101 ;
V_74 -> V_101 = 0UL ;
V_44 = F_55 ( V_19 , V_75 , V_47 ) ;
V_74 -> V_101 = V_100 ;
return V_44 ;
}
F_56 ( V_74 ) ;
return - V_102 ;
V_44:
F_42 ( V_74 ) ;
return V_44 ;
}
static int F_55 ( struct V_16 * V_19 , struct V_40 * V_75 ,
struct V_76 * V_47 )
{
struct V_3 * V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_43 * V_22 ;
struct V_40 * V_61 , * V_41 = V_19 -> V_15 . V_42 ;
int V_71 ;
int V_103 ;
int V_44 ;
T_1 V_26 ;
F_16 ( V_19 ) ;
V_26 = V_104 [ V_19 -> V_26 ] ;
if ( F_46 ( V_26 == 0xff ) ) {
V_44 = - V_84 ;
goto V_105;
}
if ( V_75 ) {
V_41 = V_75 -> V_69 ;
V_61 = F_57 ( V_41 , V_106 ) ;
if ( ! V_61 )
goto V_107;
V_61 -> V_69 = V_41 -> V_69 ;
if ( ! V_61 -> V_69 )
V_19 -> V_15 . V_73 = V_61 ;
V_75 -> V_69 = V_61 ;
F_58 ( V_41 , V_19 -> V_15 . V_42 ) ;
V_41 -> V_69 = V_19 -> V_15 . V_42 -> V_69 ;
F_59 ( V_19 -> V_15 . V_42 ) ;
V_19 -> V_15 . V_42 = V_41 ;
}
F_60 ( ! V_41 ) ;
F_60 ( F_52 ( V_41 ) -> V_78 != 0 ) ;
V_103 = F_48 ( V_41 ) ;
V_71 = V_103 + V_19 -> V_15 . V_71 ;
V_44 = - V_108 ;
if ( V_71 > 65535 )
goto V_109;
if ( F_61 ( V_41 , V_106 ) )
goto V_107;
if ( F_62 ( V_41 ) ) {
struct V_40 * V_110 ;
int V_92 , V_111 = 0 ;
V_110 = F_63 ( 0 , V_106 ) ;
if ( ! V_110 )
goto V_107;
V_110 -> V_69 = V_41 -> V_69 ;
V_41 -> V_69 = V_110 ;
F_64 ( V_110 ) -> V_112 = F_64 ( V_41 ) -> V_112 ;
F_65 ( V_41 ) ;
for ( V_92 = 0 ; V_92 < F_64 ( V_41 ) -> V_113 ; V_92 ++ )
V_111 += F_66 ( & F_64 ( V_41 ) -> V_5 [ V_92 ] ) ;
V_110 -> V_71 = V_110 -> V_114 = V_41 -> V_114 - V_111 ;
V_41 -> V_114 -= V_110 -> V_71 ;
V_41 -> V_71 -= V_110 -> V_71 ;
V_110 -> V_115 = 0 ;
V_110 -> V_87 = V_41 -> V_87 ;
F_53 ( V_19 -> V_15 . V_3 , V_110 -> V_70 ) ;
}
F_64 ( V_41 ) -> V_112 = V_41 -> V_69 ;
F_67 ( V_41 , V_41 -> V_116 - F_68 ( V_41 ) ) ;
for ( V_61 = V_41 -> V_69 ; V_61 ; V_61 = V_61 -> V_69 ) {
V_41 -> V_114 += V_61 -> V_71 ;
V_41 -> V_71 += V_61 -> V_71 ;
if ( V_41 -> V_87 != V_61 -> V_87 )
V_41 -> V_87 = V_89 ;
else if ( V_41 -> V_87 == V_117 )
V_41 -> V_115 = F_69 ( V_41 -> V_115 , V_61 -> V_115 ) ;
V_41 -> V_70 += V_61 -> V_70 ;
}
F_43 ( V_19 -> V_15 . V_3 , V_41 -> V_70 ) ;
V_41 -> V_69 = NULL ;
V_41 -> V_47 = V_47 ;
V_41 -> V_96 = V_19 -> V_15 . V_95 ;
F_45 ( V_41 ) -> V_118 = V_56 ( V_19 -> V_99 , V_19 -> V_15 . V_97 ) ;
V_22 = F_26 ( V_41 ) ;
V_22 -> V_119 = F_54 ( V_71 ) ;
V_22 -> V_1 |= V_26 ;
if ( V_19 -> V_99 == V_19 -> V_15 . V_97 ) {
F_45 ( V_41 ) -> V_36 |= V_120 ;
V_22 -> V_82 = F_54 ( V_98 ) ;
} else {
V_22 -> V_82 = 0 ;
}
F_70 ( V_22 ) ;
F_22 ( V_3 , V_121 ) ;
V_19 -> V_15 . V_42 = NULL ;
V_19 -> V_15 . V_73 = NULL ;
return 0 ;
V_107:
F_71 ( L_1 , V_19 ) ;
V_44 = - V_90 ;
goto V_105;
V_109:
F_72 ( L_2 , & V_19 -> V_7 ) ;
V_105:
F_22 ( V_3 , V_39 ) ;
return V_44 ;
}
int F_73 ( struct V_3 * V_3 , struct V_40 * V_74 , V_13 V_23 )
{
struct V_76 * V_47 = V_74 -> V_47 ? : F_74 ( V_74 ) -> V_47 ;
int V_24 = F_75 ( V_47 ) ;
struct V_16 * V_19 ;
F_22 ( V_3 , V_122 ) ;
F_76 ( V_74 ) ;
V_19 = F_32 ( V_3 , F_26 ( V_74 ) , V_23 , V_24 ) ;
if ( V_19 ) {
int V_123 ;
F_21 ( & V_19 -> V_15 . V_35 ) ;
V_123 = F_44 ( V_19 , V_74 ) ;
F_31 ( & V_19 -> V_15 . V_35 ) ;
F_14 ( V_19 ) ;
return V_123 ;
}
F_22 ( V_3 , V_39 ) ;
F_42 ( V_74 ) ;
return - V_90 ;
}
struct V_40 * F_77 ( struct V_3 * V_3 , struct V_40 * V_74 , V_13 V_23 )
{
struct V_43 V_22 ;
int V_124 ;
V_13 V_71 ;
if ( V_74 -> V_17 != F_54 ( V_125 ) )
return V_74 ;
V_124 = F_49 ( V_74 ) ;
if ( F_78 ( V_74 , V_124 , & V_22 , sizeof( V_22 ) ) < 0 )
return V_74 ;
if ( V_22 . V_79 < 5 || V_22 . V_126 != 4 )
return V_74 ;
V_71 = F_47 ( V_22 . V_119 ) ;
if ( V_74 -> V_71 < V_124 + V_71 || V_71 < ( V_22 . V_79 * 4 ) )
return V_74 ;
if ( F_79 ( & V_22 ) ) {
V_74 = F_80 ( V_74 , V_106 ) ;
if ( V_74 ) {
if ( ! F_81 ( V_74 , V_124 + V_22 . V_79 * 4 ) )
return V_74 ;
if ( F_51 ( V_74 , V_124 + V_71 ) )
return V_74 ;
memset ( F_45 ( V_74 ) , 0 , sizeof( struct V_127 ) ) ;
if ( F_73 ( V_3 , V_74 , V_23 ) )
return NULL ;
F_82 ( V_74 ) ;
}
}
return V_74 ;
}
static int T_4 F_83 ( struct V_3 * V_3 )
{
struct V_128 * V_129 ;
struct V_130 * V_131 ;
V_129 = V_132 ;
if ( ! F_84 ( V_3 , & V_133 ) ) {
V_129 = F_85 ( V_129 , sizeof( V_132 ) , V_134 ) ;
if ( ! V_129 )
goto V_135;
V_129 [ 0 ] . V_116 = & V_3 -> V_4 . V_5 . V_136 ;
V_129 [ 0 ] . V_137 = & V_3 -> V_4 . V_5 . V_138 ;
V_129 [ 0 ] . V_139 = & V_133 . V_4 . V_5 . V_136 ;
V_129 [ 1 ] . V_116 = & V_3 -> V_4 . V_5 . V_138 ;
V_129 [ 1 ] . V_139 = & V_3 -> V_4 . V_5 . V_136 ;
V_129 [ 2 ] . V_116 = & V_3 -> V_4 . V_5 . V_65 ;
if ( V_3 -> V_140 != & V_141 )
V_129 [ 0 ] . V_142 = NULL ;
}
V_131 = F_86 ( V_3 , L_3 , V_129 ) ;
if ( ! V_131 )
goto V_143;
V_3 -> V_4 . V_144 = V_131 ;
return 0 ;
V_143:
if ( ! F_84 ( V_3 , & V_133 ) )
F_87 ( V_129 ) ;
V_135:
return - V_90 ;
}
static void T_5 F_88 ( struct V_3 * V_3 )
{
struct V_128 * V_129 ;
V_129 = V_3 -> V_4 . V_144 -> V_145 ;
F_89 ( V_3 -> V_4 . V_144 ) ;
F_87 ( V_129 ) ;
}
static void T_6 F_90 ( void )
{
F_86 ( & V_133 , L_3 , V_146 ) ;
}
static int F_83 ( struct V_3 * V_3 )
{
return 0 ;
}
static void F_88 ( struct V_3 * V_3 )
{
}
static void T_6 F_90 ( void )
{
}
static int T_4 F_91 ( struct V_3 * V_3 )
{
int V_147 ;
V_3 -> V_4 . V_5 . V_136 = 4 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_138 = 3 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_65 = V_148 ;
V_147 = F_92 ( & V_3 -> V_4 . V_5 ) ;
if ( V_147 )
return V_147 ;
V_147 = F_83 ( V_3 ) ;
if ( V_147 )
F_93 ( & V_3 -> V_4 . V_5 ) ;
return V_147 ;
}
static void T_5 F_94 ( struct V_3 * V_3 )
{
F_88 ( V_3 ) ;
F_95 ( & V_3 -> V_4 . V_5 , & V_10 ) ;
}
void T_6 F_96 ( void )
{
F_90 () ;
F_97 ( & V_149 ) ;
V_10 . V_150 = F_7 ;
V_10 . V_151 = F_10 ;
V_10 . V_152 = F_12 ;
V_10 . V_153 = sizeof( struct V_16 ) ;
V_10 . V_154 = F_9 ;
V_10 . V_155 = F_20 ;
V_10 . V_156 = V_157 ;
if ( F_98 ( & V_10 ) )
F_99 ( L_4 ) ;
}
