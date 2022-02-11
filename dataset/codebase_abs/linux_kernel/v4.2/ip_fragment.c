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
static bool F_18 ( V_13 V_23 )
{
return V_23 == V_29 ||
F_19 ( V_23 , V_30 ,
V_31 ) ||
F_19 ( V_23 , V_32 ,
V_33 ) ;
}
static void F_20 ( unsigned long V_21 )
{
struct V_16 * V_19 ;
struct V_3 * V_3 ;
V_19 = F_8 ( (struct V_14 * ) V_21 , struct V_16 , V_15 ) ;
V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_21 ( & V_19 -> V_15 . V_34 ) ;
if ( V_19 -> V_15 . V_35 & V_36 )
goto V_37;
F_16 ( V_19 ) ;
F_22 ( V_3 , V_38 ) ;
if ( ! F_23 ( & V_19 -> V_15 ) ) {
struct V_39 * V_40 = V_19 -> V_15 . V_41 ;
const struct V_42 * V_22 ;
int V_43 ;
F_22 ( V_3 , V_44 ) ;
if ( ! ( V_19 -> V_15 . V_35 & V_45 ) || ! V_19 -> V_15 . V_41 )
goto V_37;
F_24 () ;
V_40 -> V_46 = F_25 ( V_3 , V_19 -> V_47 ) ;
if ( ! V_40 -> V_46 )
goto V_48;
V_22 = F_26 ( V_40 ) ;
V_43 = F_27 ( V_40 , V_22 -> V_8 , V_22 -> V_7 ,
V_22 -> V_1 , V_40 -> V_46 ) ;
if ( V_43 )
goto V_48;
if ( F_18 ( V_19 -> V_23 ) &&
( F_28 ( V_40 ) -> V_49 != V_50 ) )
goto V_48;
F_29 ( V_40 , V_51 , V_52 , 0 ) ;
V_48:
F_30 () ;
}
V_37:
F_31 ( & V_19 -> V_15 . V_34 ) ;
F_14 ( V_19 ) ;
}
static struct V_16 * F_32 ( struct V_3 * V_3 , struct V_42 * V_22 , V_13 V_23 )
{
struct V_14 * V_15 ;
struct V_20 V_21 ;
unsigned int V_53 ;
V_21 . V_22 = V_22 ;
V_21 . V_23 = V_23 ;
V_53 = F_4 ( V_22 -> V_6 , V_22 -> V_7 , V_22 -> V_8 , V_22 -> V_17 ) ;
V_15 = F_33 ( & V_3 -> V_4 . V_5 , & V_10 , & V_21 , V_53 ) ;
if ( F_34 ( V_15 ) ) {
F_35 ( V_15 , F_36 () ) ;
return NULL ;
}
return F_8 ( V_15 , struct V_16 , V_15 ) ;
}
static int F_37 ( struct V_16 * V_19 )
{
struct V_54 * V_26 = V_19 -> V_26 ;
unsigned int V_55 = V_27 ;
unsigned int V_56 , V_57 ;
int V_58 ;
if ( ! V_26 || ! V_55 )
return 0 ;
V_56 = V_19 -> V_59 ;
V_57 = F_38 ( & V_26 -> V_59 ) ;
V_19 -> V_59 = V_57 ;
V_58 = V_19 -> V_15 . V_41 && ( V_57 - V_56 ) > V_55 ;
if ( V_58 ) {
struct V_3 * V_3 ;
V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
F_22 ( V_3 , V_38 ) ;
}
return V_58 ;
}
static int F_39 ( struct V_16 * V_19 )
{
struct V_39 * V_60 ;
unsigned int V_61 = 0 ;
if ( ! F_40 ( & V_19 -> V_15 . V_62 , V_63 + V_19 -> V_15 . V_3 -> V_64 ) ) {
F_41 ( & V_19 -> V_15 . V_65 ) ;
return - V_66 ;
}
V_60 = V_19 -> V_15 . V_41 ;
do {
struct V_39 * V_67 = V_60 -> V_68 ;
V_61 += V_60 -> V_69 ;
F_42 ( V_60 ) ;
V_60 = V_67 ;
} while ( V_60 );
F_43 ( V_19 -> V_15 . V_3 , V_61 ) ;
V_19 -> V_15 . V_35 = 0 ;
V_19 -> V_15 . V_70 = 0 ;
V_19 -> V_15 . V_71 = 0 ;
V_19 -> V_15 . V_41 = NULL ;
V_19 -> V_15 . V_72 = NULL ;
V_19 -> V_47 = 0 ;
V_19 -> V_25 = 0 ;
return 0 ;
}
static int F_44 ( struct V_16 * V_19 , struct V_39 * V_73 )
{
struct V_39 * V_74 , * V_68 ;
struct V_75 * V_46 ;
unsigned int V_76 ;
int V_35 , V_77 ;
int V_78 , V_57 ;
int V_43 = - V_79 ;
T_1 V_25 ;
if ( V_19 -> V_15 . V_35 & V_36 )
goto V_43;
if ( ! ( F_45 ( V_73 ) -> V_35 & V_80 ) &&
F_46 ( F_37 ( V_19 ) ) &&
F_46 ( V_43 = F_39 ( V_19 ) ) ) {
F_16 ( V_19 ) ;
goto V_43;
}
V_25 = F_1 ( F_26 ( V_73 ) -> V_1 ) ;
V_77 = F_47 ( F_26 ( V_73 ) -> V_81 ) ;
V_35 = V_77 & ~ V_82 ;
V_77 &= V_82 ;
V_77 <<= 3 ;
V_78 = F_48 ( V_73 ) ;
V_57 = V_77 + V_73 -> V_70 - F_49 ( V_73 ) - V_78 ;
V_43 = - V_83 ;
if ( ( V_35 & V_84 ) == 0 ) {
if ( V_57 < V_19 -> V_15 . V_70 ||
( ( V_19 -> V_15 . V_35 & V_85 ) && V_57 != V_19 -> V_15 . V_70 ) )
goto V_43;
V_19 -> V_15 . V_35 |= V_85 ;
V_19 -> V_15 . V_70 = V_57 ;
} else {
if ( V_57 & 7 ) {
V_57 &= ~ 7 ;
if ( V_73 -> V_86 != V_87 )
V_73 -> V_86 = V_88 ;
}
if ( V_57 > V_19 -> V_15 . V_70 ) {
if ( V_19 -> V_15 . V_35 & V_85 )
goto V_43;
V_19 -> V_15 . V_70 = V_57 ;
}
}
if ( V_57 == V_77 )
goto V_43;
V_43 = - V_89 ;
if ( ! F_50 ( V_73 , F_49 ( V_73 ) + V_78 ) )
goto V_43;
V_43 = F_51 ( V_73 , V_57 - V_77 ) ;
if ( V_43 )
goto V_43;
V_74 = V_19 -> V_15 . V_72 ;
if ( ! V_74 || F_52 ( V_74 ) -> V_77 < V_77 ) {
V_68 = NULL ;
goto V_90;
}
V_74 = NULL ;
for ( V_68 = V_19 -> V_15 . V_41 ; V_68 != NULL ; V_68 = V_68 -> V_68 ) {
if ( F_52 ( V_68 ) -> V_77 >= V_77 )
break;
V_74 = V_68 ;
}
V_90:
if ( V_74 ) {
int V_91 = ( F_52 ( V_74 ) -> V_77 + V_74 -> V_70 ) - V_77 ;
if ( V_91 > 0 ) {
V_77 += V_91 ;
V_43 = - V_83 ;
if ( V_57 <= V_77 )
goto V_43;
V_43 = - V_89 ;
if ( ! F_50 ( V_73 , V_91 ) )
goto V_43;
if ( V_73 -> V_86 != V_87 )
V_73 -> V_86 = V_88 ;
}
}
V_43 = - V_89 ;
while ( V_68 && F_52 ( V_68 ) -> V_77 < V_57 ) {
int V_91 = V_57 - F_52 ( V_68 ) -> V_77 ;
if ( V_91 < V_68 -> V_70 ) {
if ( ! F_50 ( V_68 , V_91 ) )
goto V_43;
F_52 ( V_68 ) -> V_77 += V_91 ;
V_19 -> V_15 . V_71 -= V_91 ;
if ( V_68 -> V_86 != V_87 )
V_68 -> V_86 = V_88 ;
break;
} else {
struct V_39 * V_92 = V_68 ;
V_68 = V_68 -> V_68 ;
if ( V_74 )
V_74 -> V_68 = V_68 ;
else
V_19 -> V_15 . V_41 = V_68 ;
V_19 -> V_15 . V_71 -= V_92 -> V_70 ;
F_43 ( V_19 -> V_15 . V_3 , V_92 -> V_69 ) ;
F_42 ( V_92 ) ;
}
}
F_52 ( V_73 ) -> V_77 = V_77 ;
V_73 -> V_68 = V_68 ;
if ( ! V_68 )
V_19 -> V_15 . V_72 = V_73 ;
if ( V_74 )
V_74 -> V_68 = V_73 ;
else
V_19 -> V_15 . V_41 = V_73 ;
V_46 = V_73 -> V_46 ;
if ( V_46 ) {
V_19 -> V_47 = V_46 -> V_93 ;
V_73 -> V_46 = NULL ;
}
V_19 -> V_15 . V_94 = V_73 -> V_95 ;
V_19 -> V_15 . V_71 += V_73 -> V_70 ;
V_19 -> V_25 |= V_25 ;
F_53 ( V_19 -> V_15 . V_3 , V_73 -> V_69 ) ;
if ( V_77 == 0 )
V_19 -> V_15 . V_35 |= V_45 ;
V_76 = V_73 -> V_70 + V_78 ;
if ( V_76 > V_19 -> V_15 . V_96 )
V_19 -> V_15 . V_96 = V_76 ;
if ( F_26 ( V_73 ) -> V_81 & F_54 ( V_97 ) &&
V_76 > V_19 -> V_98 )
V_19 -> V_98 = V_76 ;
if ( V_19 -> V_15 . V_35 == ( V_45 | V_85 ) &&
V_19 -> V_15 . V_71 == V_19 -> V_15 . V_70 ) {
unsigned long V_99 = V_73 -> V_100 ;
V_73 -> V_100 = 0UL ;
V_43 = F_55 ( V_19 , V_74 , V_46 ) ;
V_73 -> V_100 = V_99 ;
return V_43 ;
}
F_56 ( V_73 ) ;
return - V_101 ;
V_43:
F_42 ( V_73 ) ;
return V_43 ;
}
static int F_55 ( struct V_16 * V_19 , struct V_39 * V_74 ,
struct V_75 * V_46 )
{
struct V_3 * V_3 = F_8 ( V_19 -> V_15 . V_3 , struct V_3 , V_4 . V_5 ) ;
struct V_42 * V_22 ;
struct V_39 * V_60 , * V_40 = V_19 -> V_15 . V_41 ;
int V_70 ;
int V_102 ;
int V_43 ;
int V_61 ;
T_1 V_25 ;
F_16 ( V_19 ) ;
V_25 = V_103 [ V_19 -> V_25 ] ;
if ( F_46 ( V_25 == 0xff ) ) {
V_43 = - V_83 ;
goto V_104;
}
if ( V_74 ) {
V_40 = V_74 -> V_68 ;
V_60 = F_57 ( V_40 , V_105 ) ;
if ( ! V_60 )
goto V_106;
V_60 -> V_68 = V_40 -> V_68 ;
if ( ! V_60 -> V_68 )
V_19 -> V_15 . V_72 = V_60 ;
V_74 -> V_68 = V_60 ;
F_58 ( V_40 , V_19 -> V_15 . V_41 ) ;
V_40 -> V_68 = V_19 -> V_15 . V_41 -> V_68 ;
F_59 ( V_19 -> V_15 . V_41 ) ;
V_19 -> V_15 . V_41 = V_40 ;
}
F_60 ( ! V_40 ) ;
F_60 ( F_52 ( V_40 ) -> V_77 != 0 ) ;
V_102 = F_48 ( V_40 ) ;
V_70 = V_102 + V_19 -> V_15 . V_70 ;
V_43 = - V_107 ;
if ( V_70 > 65535 )
goto V_108;
if ( F_61 ( V_40 , V_105 ) )
goto V_106;
if ( F_62 ( V_40 ) ) {
struct V_39 * V_109 ;
int V_91 , V_110 = 0 ;
V_109 = F_63 ( 0 , V_105 ) ;
if ( ! V_109 )
goto V_106;
V_109 -> V_68 = V_40 -> V_68 ;
V_40 -> V_68 = V_109 ;
F_64 ( V_109 ) -> V_111 = F_64 ( V_40 ) -> V_111 ;
F_65 ( V_40 ) ;
for ( V_91 = 0 ; V_91 < F_64 ( V_40 ) -> V_112 ; V_91 ++ )
V_110 += F_66 ( & F_64 ( V_40 ) -> V_5 [ V_91 ] ) ;
V_109 -> V_70 = V_109 -> V_113 = V_40 -> V_113 - V_110 ;
V_40 -> V_113 -= V_109 -> V_70 ;
V_40 -> V_70 -= V_109 -> V_70 ;
V_109 -> V_114 = 0 ;
V_109 -> V_86 = V_40 -> V_86 ;
F_53 ( V_19 -> V_15 . V_3 , V_109 -> V_69 ) ;
}
F_67 ( V_40 , V_40 -> V_115 - F_68 ( V_40 ) ) ;
V_61 = V_40 -> V_69 ;
for ( V_60 = V_40 -> V_68 ; V_60 ; ) {
bool V_116 ;
int V_117 ;
struct V_39 * V_68 = V_60 -> V_68 ;
V_61 += V_60 -> V_69 ;
if ( V_40 -> V_86 != V_60 -> V_86 )
V_40 -> V_86 = V_88 ;
else if ( V_40 -> V_86 == V_118 )
V_40 -> V_114 = F_69 ( V_40 -> V_114 , V_60 -> V_114 ) ;
if ( F_70 ( V_40 , V_60 , & V_116 , & V_117 ) ) {
F_71 ( V_60 , V_116 ) ;
} else {
if ( ! F_64 ( V_40 ) -> V_111 )
F_64 ( V_40 ) -> V_111 = V_60 ;
V_40 -> V_113 += V_60 -> V_70 ;
V_40 -> V_70 += V_60 -> V_70 ;
V_40 -> V_69 += V_60 -> V_69 ;
}
V_60 = V_68 ;
}
F_43 ( V_19 -> V_15 . V_3 , V_61 ) ;
V_40 -> V_68 = NULL ;
V_40 -> V_46 = V_46 ;
V_40 -> V_95 = V_19 -> V_15 . V_94 ;
F_45 ( V_40 ) -> V_119 = V_55 ( V_19 -> V_98 , V_19 -> V_15 . V_96 ) ;
V_22 = F_26 ( V_40 ) ;
V_22 -> V_120 = F_54 ( V_70 ) ;
V_22 -> V_1 |= V_25 ;
if ( V_19 -> V_98 == V_19 -> V_15 . V_96 ) {
F_45 ( V_40 ) -> V_35 |= V_121 ;
V_22 -> V_81 = F_54 ( V_97 ) ;
} else {
V_22 -> V_81 = 0 ;
}
F_72 ( V_22 ) ;
F_22 ( V_3 , V_122 ) ;
V_19 -> V_15 . V_41 = NULL ;
V_19 -> V_15 . V_72 = NULL ;
return 0 ;
V_106:
F_73 ( L_1 , V_19 ) ;
V_43 = - V_89 ;
goto V_104;
V_108:
F_74 ( L_2 , & V_19 -> V_7 ) ;
V_104:
F_22 ( V_3 , V_38 ) ;
return V_43 ;
}
int F_75 ( struct V_39 * V_73 , V_13 V_23 )
{
struct V_16 * V_19 ;
struct V_3 * V_3 ;
V_3 = V_73 -> V_46 ? F_76 ( V_73 -> V_46 ) : F_76 ( F_77 ( V_73 ) -> V_46 ) ;
F_22 ( V_3 , V_123 ) ;
V_19 = F_32 ( V_3 , F_26 ( V_73 ) , V_23 ) ;
if ( V_19 ) {
int V_124 ;
F_21 ( & V_19 -> V_15 . V_34 ) ;
V_124 = F_44 ( V_19 , V_73 ) ;
F_31 ( & V_19 -> V_15 . V_34 ) ;
F_14 ( V_19 ) ;
return V_124 ;
}
F_22 ( V_3 , V_38 ) ;
F_42 ( V_73 ) ;
return - V_89 ;
}
struct V_39 * F_78 ( struct V_39 * V_73 , V_13 V_23 )
{
struct V_42 V_22 ;
int V_125 ;
V_13 V_70 ;
if ( V_73 -> V_17 != F_54 ( V_126 ) )
return V_73 ;
V_125 = F_49 ( V_73 ) ;
if ( F_79 ( V_73 , V_125 , & V_22 , sizeof( V_22 ) ) < 0 )
return V_73 ;
if ( V_22 . V_78 < 5 || V_22 . V_127 != 4 )
return V_73 ;
V_70 = F_47 ( V_22 . V_120 ) ;
if ( V_73 -> V_70 < V_125 + V_70 || V_70 < ( V_22 . V_78 * 4 ) )
return V_73 ;
if ( F_80 ( & V_22 ) ) {
V_73 = F_81 ( V_73 , V_105 ) ;
if ( V_73 ) {
if ( ! F_82 ( V_73 , V_125 + V_22 . V_78 * 4 ) )
return V_73 ;
if ( F_51 ( V_73 , V_125 + V_70 ) )
return V_73 ;
memset ( F_45 ( V_73 ) , 0 , sizeof( struct V_128 ) ) ;
if ( F_75 ( V_73 , V_23 ) )
return NULL ;
F_83 ( V_73 ) ;
}
}
return V_73 ;
}
static int T_4 F_84 ( struct V_3 * V_3 )
{
struct V_129 * V_130 ;
struct V_131 * V_132 ;
V_130 = V_133 ;
if ( ! F_85 ( V_3 , & V_134 ) ) {
V_130 = F_86 ( V_130 , sizeof( V_133 ) , V_135 ) ;
if ( ! V_130 )
goto V_136;
V_130 [ 0 ] . V_115 = & V_3 -> V_4 . V_5 . V_137 ;
V_130 [ 0 ] . V_138 = & V_3 -> V_4 . V_5 . V_139 ;
V_130 [ 0 ] . V_140 = & V_134 . V_4 . V_5 . V_137 ;
V_130 [ 1 ] . V_115 = & V_3 -> V_4 . V_5 . V_139 ;
V_130 [ 1 ] . V_140 = & V_3 -> V_4 . V_5 . V_137 ;
V_130 [ 2 ] . V_115 = & V_3 -> V_4 . V_5 . V_64 ;
if ( V_3 -> V_141 != & V_142 )
V_130 [ 0 ] . V_143 = NULL ;
}
V_132 = F_87 ( V_3 , L_3 , V_130 ) ;
if ( ! V_132 )
goto V_144;
V_3 -> V_4 . V_145 = V_132 ;
return 0 ;
V_144:
if ( ! F_85 ( V_3 , & V_134 ) )
F_88 ( V_130 ) ;
V_136:
return - V_89 ;
}
static void T_5 F_89 ( struct V_3 * V_3 )
{
struct V_129 * V_130 ;
V_130 = V_3 -> V_4 . V_145 -> V_146 ;
F_90 ( V_3 -> V_4 . V_145 ) ;
F_88 ( V_130 ) ;
}
static void T_6 F_91 ( void )
{
F_87 ( & V_134 , L_3 , V_147 ) ;
}
static int F_84 ( struct V_3 * V_3 )
{
return 0 ;
}
static void F_89 ( struct V_3 * V_3 )
{
}
static void T_6 F_91 ( void )
{
}
static int T_4 F_92 ( struct V_3 * V_3 )
{
V_3 -> V_4 . V_5 . V_137 = 4 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_139 = 3 * 1024 * 1024 ;
V_3 -> V_4 . V_5 . V_64 = V_148 ;
F_93 ( & V_3 -> V_4 . V_5 ) ;
return F_84 ( V_3 ) ;
}
static void T_5 F_94 ( struct V_3 * V_3 )
{
F_89 ( V_3 ) ;
F_95 ( & V_3 -> V_4 . V_5 , & V_10 ) ;
}
void T_6 F_96 ( void )
{
F_91 () ;
F_97 ( & V_149 ) ;
V_10 . V_150 = F_7 ;
V_10 . V_151 = F_10 ;
V_10 . V_152 = F_12 ;
V_10 . V_153 = NULL ;
V_10 . V_154 = sizeof( struct V_16 ) ;
V_10 . V_155 = F_9 ;
V_10 . V_156 = F_20 ;
V_10 . V_157 = V_158 ;
if ( F_98 ( & V_10 ) )
F_99 ( L_4 ) ;
}
