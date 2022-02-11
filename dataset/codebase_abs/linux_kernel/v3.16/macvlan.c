static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static struct V_1 * F_3 ( const struct V_2 * V_3 )
{
return F_4 ( V_3 -> V_4 ) ;
}
static struct V_5 * F_5 ( const struct V_1 * V_6 ,
const unsigned char * V_7 )
{
struct V_5 * V_8 ;
F_6 (vlan, &port->vlan_hash[addr[5]], hlist) {
if ( F_7 ( V_8 -> V_3 -> V_9 , V_7 ) )
return V_8 ;
}
return NULL ;
}
static void F_8 ( struct V_5 * V_8 )
{
struct V_1 * V_6 = V_8 -> V_6 ;
const unsigned char * V_7 = V_8 -> V_3 -> V_9 ;
F_9 ( & V_8 -> V_10 , & V_6 -> V_11 [ V_7 [ 5 ] ] ) ;
}
static void F_10 ( struct V_5 * V_8 , bool V_12 )
{
F_11 ( & V_8 -> V_10 ) ;
if ( V_12 )
F_12 () ;
}
static void F_13 ( struct V_5 * V_8 ,
const unsigned char * V_7 )
{
F_10 ( V_8 , true ) ;
memcpy ( V_8 -> V_3 -> V_9 , V_7 , V_13 ) ;
F_8 ( V_8 ) ;
}
static int F_14 ( const struct V_1 * V_6 ,
const unsigned char * V_7 )
{
if ( F_7 ( V_6 -> V_3 -> V_9 , V_7 ) )
return 1 ;
if ( F_5 ( V_6 , V_7 ) )
return 1 ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 ,
const struct V_5 * V_8 ,
const struct V_16 * V_17 , bool V_18 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
if ( V_18 )
return F_16 ( V_3 , V_15 ) ;
V_15 -> V_3 = V_3 ;
if ( F_7 ( V_17 -> V_19 , V_3 -> V_20 ) )
V_15 -> V_21 = V_22 ;
else
V_15 -> V_21 = V_23 ;
return 0 ;
}
static T_1 F_17 ( const struct V_5 * V_8 )
{
return ( T_1 ) ( ( ( unsigned long ) V_8 ) >> V_24 ) ;
}
static unsigned int F_18 ( const struct V_5 * V_8 ,
const unsigned char * V_7 )
{
T_1 V_25 = F_19 ( V_7 + 2 ) ;
V_25 ^= F_17 ( V_8 ) ;
return F_20 ( V_25 , V_26 ) ;
}
static void F_21 ( struct V_14 * V_15 ,
const struct V_1 * V_6 ,
struct V_2 * V_27 ,
enum V_28 V_29 )
{
const struct V_16 * V_17 = F_22 ( V_15 ) ;
const struct V_5 * V_8 ;
struct V_14 * V_30 ;
unsigned int V_31 ;
int V_32 ;
unsigned int V_33 ;
if ( V_15 -> V_34 == F_23 ( V_35 ) )
return;
for ( V_31 = 0 ; V_31 < V_36 ; V_31 ++ ) {
F_6 (vlan, &port->vlan_hash[i], hlist) {
if ( V_8 -> V_3 == V_27 || ! ( V_8 -> V_29 & V_29 ) )
continue;
V_33 = F_18 ( V_8 , V_17 -> V_19 ) ;
if ( ! F_24 ( V_33 , V_8 -> V_37 ) )
continue;
V_32 = V_38 ;
V_30 = F_25 ( V_15 , V_39 ) ;
if ( F_26 ( V_30 ) )
V_32 = F_15 (
V_30 , V_8 , V_17 ,
V_29 == V_40 ) ? :
F_27 ( V_30 ) ;
F_28 ( V_8 , V_15 -> V_41 + V_42 ,
V_32 == V_43 , 1 ) ;
}
}
}
static void F_29 ( struct V_44 * V_45 )
{
struct V_1 * V_6 = F_30 ( V_45 , struct V_1 ,
V_46 ) ;
struct V_14 * V_15 ;
struct V_47 V_48 ;
F_31 ( & V_48 ) ;
F_32 ( & V_6 -> V_49 . V_50 ) ;
F_33 ( & V_6 -> V_49 , & V_48 ) ;
F_34 ( & V_6 -> V_49 . V_50 ) ;
while ( ( V_15 = F_35 ( & V_48 ) ) ) {
const struct V_5 * V_27 = F_36 ( V_15 ) -> V_27 ;
F_37 () ;
if ( ! V_27 )
F_21 ( V_15 , V_6 , NULL ,
V_51 |
V_52 |
V_53 |
V_40 ) ;
else if ( V_27 -> V_29 == V_52 )
F_21 ( V_15 , V_6 , V_27 -> V_3 ,
V_52 |
V_40 ) ;
else
F_21 ( V_15 , V_6 , V_27 -> V_3 ,
V_52 ) ;
F_38 () ;
F_39 ( V_15 ) ;
}
}
static void F_40 ( struct V_1 * V_6 ,
struct V_14 * V_15 )
{
struct V_14 * V_30 ;
int V_32 = - V_54 ;
V_30 = F_25 ( V_15 , V_39 ) ;
if ( ! V_30 )
goto V_32;
F_41 ( & V_6 -> V_49 . V_50 ) ;
if ( F_42 ( & V_6 -> V_49 ) < V_15 -> V_3 -> V_55 ) {
F_43 ( & V_6 -> V_49 , V_30 ) ;
V_32 = 0 ;
}
F_44 ( & V_6 -> V_49 . V_50 ) ;
if ( V_32 )
goto V_56;
F_45 ( & V_6 -> V_46 ) ;
return;
V_56:
F_39 ( V_30 ) ;
V_32:
F_46 ( & V_15 -> V_3 -> V_57 ) ;
}
static T_2 F_47 ( struct V_14 * * V_58 )
{
struct V_1 * V_6 ;
struct V_14 * V_15 = * V_58 ;
const struct V_16 * V_17 = F_22 ( V_15 ) ;
const struct V_5 * V_8 ;
const struct V_5 * V_27 ;
struct V_2 * V_3 ;
unsigned int V_41 = 0 ;
int V_59 = V_38 ;
V_6 = F_1 ( V_15 -> V_3 ) ;
if ( F_48 ( V_17 -> V_19 ) ) {
V_15 = F_49 ( V_15 , V_60 ) ;
if ( ! V_15 )
return V_61 ;
V_17 = F_22 ( V_15 ) ;
V_27 = F_5 ( V_6 , V_17 -> V_62 ) ;
if ( V_27 && V_27 -> V_29 != V_52 &&
V_27 -> V_29 != V_40 ) {
V_8 = V_27 ;
V_59 = F_15 ( V_15 , V_8 , V_17 , 0 ) ? :
F_50 ( V_15 ) ;
goto V_63;
}
F_36 ( V_15 ) -> V_27 = V_27 ;
F_40 ( V_6 , V_15 ) ;
return V_64 ;
}
if ( V_6 -> V_65 )
V_8 = F_51 ( & V_6 -> V_66 ,
struct V_5 , V_48 ) ;
else
V_8 = F_5 ( V_6 , V_17 -> V_19 ) ;
if ( V_8 == NULL )
return V_64 ;
V_3 = V_8 -> V_3 ;
if ( F_52 ( ! ( V_3 -> V_67 & V_68 ) ) ) {
F_39 ( V_15 ) ;
return V_61 ;
}
V_41 = V_15 -> V_41 + V_42 ;
V_15 = F_53 ( V_15 , V_39 ) ;
if ( ! V_15 )
goto V_63;
V_15 -> V_3 = V_3 ;
V_15 -> V_21 = V_69 ;
V_59 = F_50 ( V_15 ) ;
V_63:
F_28 ( V_8 , V_41 , V_59 == V_43 , 0 ) ;
return V_61 ;
}
static int F_54 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
const struct V_5 * V_8 = F_55 ( V_3 ) ;
const struct V_1 * V_6 = V_8 -> V_6 ;
const struct V_5 * V_70 ;
if ( V_8 -> V_29 == V_40 ) {
const struct V_16 * V_17 = ( void * ) V_15 -> V_71 ;
if ( F_48 ( V_17 -> V_19 ) ) {
F_21 ( V_15 , V_6 , V_3 , V_40 ) ;
goto V_72;
}
V_70 = F_5 ( V_6 , V_17 -> V_19 ) ;
if ( V_70 && V_70 -> V_29 == V_40 ) {
F_56 ( V_8 -> V_73 , V_15 ) ;
return V_74 ;
}
}
V_72:
V_15 -> V_3 = V_8 -> V_73 ;
return F_57 ( V_15 ) ;
}
static inline T_3 F_58 ( struct V_5 * V_8 , struct V_14 * V_15 )
{
#ifdef F_59
if ( V_8 -> V_75 )
F_60 ( V_8 -> V_75 , V_15 ) ;
#else
F_61 () ;
#endif
return V_76 ;
}
static T_3 F_62 ( struct V_14 * V_15 ,
struct V_2 * V_3 )
{
unsigned int V_41 = V_15 -> V_41 ;
int V_59 ;
struct V_5 * V_8 = F_55 ( V_3 ) ;
if ( F_52 ( F_63 ( V_3 ) ) )
return F_58 ( V_8 , V_15 ) ;
if ( V_8 -> V_77 ) {
V_15 -> V_3 = V_8 -> V_73 ;
V_59 = F_64 ( V_15 , V_8 -> V_77 ) ;
} else {
V_59 = F_54 ( V_15 , V_3 ) ;
}
if ( F_26 ( V_59 == V_74 || V_59 == V_78 ) ) {
struct V_79 * V_80 ;
V_80 = F_65 ( V_8 -> V_80 ) ;
F_66 ( & V_80 -> V_81 ) ;
V_80 -> V_82 ++ ;
V_80 -> V_83 += V_41 ;
F_67 ( & V_80 -> V_81 ) ;
} else {
F_68 ( V_8 -> V_80 -> V_84 ) ;
}
return V_59 ;
}
static int F_69 ( struct V_14 * V_15 , struct V_2 * V_3 ,
unsigned short type , const void * V_85 ,
const void * V_86 , unsigned V_41 )
{
const struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
return F_70 ( V_15 , V_73 , type , V_85 ,
V_86 ? : V_3 -> V_9 , V_41 ) ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
int V_32 ;
if ( V_8 -> V_6 -> V_65 ) {
if ( ! ( V_8 -> V_67 & V_87 ) ) {
V_32 = F_72 ( V_73 , 1 ) ;
if ( V_32 < 0 )
goto V_63;
}
goto V_88;
}
if ( V_73 -> V_89 & V_90 &&
V_3 -> V_91 == & V_92 ) {
V_8 -> V_77 =
V_73 -> V_93 -> V_94 ( V_73 , V_3 ) ;
if ( F_73 ( V_8 -> V_77 ) ) {
V_8 -> V_77 = NULL ;
} else
return 0 ;
}
V_32 = - V_95 ;
if ( F_14 ( V_8 -> V_6 , V_3 -> V_9 ) )
goto V_63;
V_32 = F_74 ( V_73 , V_3 -> V_9 ) ;
if ( V_32 < 0 )
goto V_63;
if ( V_3 -> V_67 & V_96 ) {
V_32 = F_75 ( V_73 , 1 ) ;
if ( V_32 < 0 )
goto V_97;
}
V_88:
F_8 ( V_8 ) ;
return 0 ;
V_97:
F_76 ( V_73 , V_3 -> V_9 ) ;
V_63:
if ( V_8 -> V_77 ) {
V_73 -> V_93 -> V_98 ( V_73 ,
V_8 -> V_77 ) ;
V_8 -> V_77 = NULL ;
}
return V_32 ;
}
static int F_77 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
if ( V_8 -> V_77 ) {
V_73 -> V_93 -> V_98 ( V_73 ,
V_8 -> V_77 ) ;
V_8 -> V_77 = NULL ;
return 0 ;
}
F_78 ( V_73 , V_3 ) ;
F_79 ( V_73 , V_3 ) ;
if ( V_8 -> V_6 -> V_65 ) {
if ( ! ( V_8 -> V_67 & V_87 ) )
F_72 ( V_73 , - 1 ) ;
goto V_99;
}
if ( V_3 -> V_67 & V_96 )
F_75 ( V_73 , - 1 ) ;
F_76 ( V_73 , V_3 -> V_9 ) ;
V_99:
F_10 ( V_8 , ! V_3 -> V_100 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 , unsigned char * V_7 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
int V_32 ;
if ( ! ( V_3 -> V_67 & V_68 ) ) {
F_81 ( V_3 -> V_9 , V_7 ) ;
} else {
if ( F_14 ( V_8 -> V_6 , V_7 ) )
return - V_95 ;
if ( ! V_8 -> V_6 -> V_65 ) {
V_32 = F_74 ( V_73 , V_7 ) ;
if ( V_32 )
return V_32 ;
F_76 ( V_73 , V_3 -> V_9 ) ;
}
F_13 ( V_8 , V_7 ) ;
}
return 0 ;
}
static int F_82 ( struct V_2 * V_3 , void * V_101 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_102 * V_7 = V_101 ;
if ( ! F_83 ( V_7 -> V_103 ) )
return - V_104 ;
if ( V_8 -> V_29 == V_53 ) {
F_84 ( V_8 -> V_73 , V_7 ) ;
return 0 ;
}
return F_80 ( V_3 , V_7 -> V_103 ) ;
}
static void F_85 ( struct V_2 * V_3 , int V_105 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
if ( V_3 -> V_67 & V_68 ) {
if ( V_105 & V_96 )
F_75 ( V_73 , V_3 -> V_67 & V_96 ? 1 : - 1 ) ;
}
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
if ( V_3 -> V_67 & ( V_106 | V_96 ) ) {
F_87 ( V_8 -> V_37 , V_107 ) ;
} else {
struct V_108 * V_109 ;
F_88 ( V_110 , V_107 ) ;
F_89 ( V_110 , V_107 ) ;
F_90 (ha, dev) {
F_91 ( F_18 ( V_8 , V_109 -> V_7 ) , V_110 ) ;
}
F_91 ( F_18 ( V_8 , V_3 -> V_20 ) , V_110 ) ;
F_92 ( V_8 -> V_37 , V_110 , V_107 ) ;
}
F_93 ( V_8 -> V_73 , V_3 ) ;
F_94 ( V_8 -> V_73 , V_3 ) ;
}
static int F_95 ( struct V_2 * V_3 , int V_111 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
if ( V_111 < 68 || V_8 -> V_73 -> V_112 < V_111 )
return - V_113 ;
V_3 -> V_112 = V_111 ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 )
{
return ( (struct V_5 * ) F_55 ( V_3 ) ) -> V_114 ;
}
static void F_97 ( struct V_2 * V_3 ,
struct V_115 * V_116 ,
void * V_117 )
{
F_98 ( & V_116 -> V_118 ,
& V_119 ) ;
}
static void F_99 ( struct V_2 * V_3 )
{
F_100 ( & V_3 -> V_120 ,
& V_121 ,
F_96 ( V_3 ) ) ;
F_101 ( V_3 , F_97 , NULL ) ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
const struct V_2 * V_73 = V_8 -> V_73 ;
V_3 -> V_122 = ( V_3 -> V_122 & ~ V_123 ) |
( V_73 -> V_122 & V_123 ) ;
V_3 -> V_89 = V_73 -> V_89 & V_124 ;
V_3 -> V_89 |= V_125 ;
V_3 -> V_126 = V_73 -> V_126 ;
V_3 -> V_127 = V_73 -> V_128 ;
V_3 -> V_129 = V_73 -> V_129 ;
F_99 ( V_3 ) ;
V_8 -> V_80 = F_103 ( struct V_79 ) ;
if ( ! V_8 -> V_80 )
return - V_54 ;
return 0 ;
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_1 * V_6 = V_8 -> V_6 ;
F_105 ( V_8 -> V_80 ) ;
if ( F_106 ( V_6 ) )
F_107 ( V_6 -> V_3 ) ;
}
static struct V_130 * F_108 ( struct V_2 * V_3 ,
struct V_130 * V_131 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
if ( V_8 -> V_80 ) {
struct V_79 * V_101 ;
T_4 V_132 , V_133 , V_134 , V_82 , V_83 ;
T_1 V_135 = 0 , V_84 = 0 ;
unsigned int V_136 ;
int V_31 ;
F_109 (i) {
V_101 = F_110 ( V_8 -> V_80 , V_31 ) ;
do {
V_136 = F_111 ( & V_101 -> V_81 ) ;
V_132 = V_101 -> V_132 ;
V_133 = V_101 -> V_133 ;
V_134 = V_101 -> V_134 ;
V_82 = V_101 -> V_82 ;
V_83 = V_101 -> V_83 ;
} while ( F_112 ( & V_101 -> V_81 , V_136 ) );
V_131 -> V_132 += V_132 ;
V_131 -> V_133 += V_133 ;
V_131 -> V_137 += V_134 ;
V_131 -> V_82 += V_82 ;
V_131 -> V_83 += V_83 ;
V_135 += V_101 -> V_135 ;
V_84 += V_101 -> V_84 ;
}
V_131 -> V_135 = V_135 ;
V_131 -> V_57 = V_135 ;
V_131 -> V_84 = V_84 ;
}
return V_131 ;
}
static int F_113 ( struct V_2 * V_3 ,
T_5 V_138 , T_6 V_139 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
return F_114 ( V_73 , V_138 , V_139 ) ;
}
static int F_115 ( struct V_2 * V_3 ,
T_5 V_138 , T_6 V_139 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
F_116 ( V_73 , V_138 , V_139 ) ;
return 0 ;
}
static int F_117 ( struct V_140 * V_141 , struct V_142 * V_143 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 ,
T_6 V_67 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
int V_32 = - V_113 ;
if ( ! V_8 -> V_6 -> V_65 )
return - V_144 ;
if ( V_67 & V_145 )
return - V_144 ;
if ( F_118 ( V_7 ) )
V_32 = F_119 ( V_3 , V_7 ) ;
else if ( F_48 ( V_7 ) )
V_32 = F_120 ( V_3 , V_7 ) ;
return V_32 ;
}
static int F_121 ( struct V_140 * V_141 , struct V_142 * V_143 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
int V_32 = - V_113 ;
if ( ! V_8 -> V_6 -> V_65 )
return - V_144 ;
if ( F_118 ( V_7 ) )
V_32 = F_76 ( V_3 , V_7 ) ;
else if ( F_48 ( V_7 ) )
V_32 = F_122 ( V_3 , V_7 ) ;
return V_32 ;
}
static void F_123 ( struct V_2 * V_3 ,
struct V_146 * V_147 )
{
F_124 ( V_147 -> V_148 , L_1 , sizeof( V_147 -> V_148 ) ) ;
F_124 ( V_147 -> V_149 , L_2 , sizeof( V_147 -> V_149 ) ) ;
}
static int F_125 ( struct V_2 * V_3 ,
struct V_150 * V_151 )
{
const struct V_5 * V_8 = F_55 ( V_3 ) ;
return F_126 ( V_8 -> V_73 , V_151 ) ;
}
static T_7 F_127 ( struct V_2 * V_3 ,
T_7 V_89 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
T_7 V_152 ;
V_89 |= V_153 ;
V_89 &= ( V_8 -> V_154 | ~ V_124 ) ;
V_152 = V_89 ;
V_89 = F_128 ( V_8 -> V_73 -> V_89 ,
V_89 ,
V_152 ) ;
V_89 |= V_125 ;
return V_89 ;
}
static void F_129 ( struct V_2 * V_3 )
{
return;
}
static int F_130 ( struct V_2 * V_3 , struct V_155 * V_156 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_157 = V_8 -> V_73 ;
struct V_75 * V_75 ;
int V_32 = 0 ;
V_75 = F_131 ( sizeof( * V_75 ) , V_158 ) ;
V_32 = - V_54 ;
if ( ! V_75 )
goto V_63;
V_32 = F_132 ( V_75 , V_157 ) ;
if ( V_32 ) {
F_133 ( V_75 ) ;
goto V_63;
}
V_8 -> V_75 = V_75 ;
V_63:
return V_32 ;
}
static void F_134 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_75 * V_75 = V_8 -> V_75 ;
if ( ! V_75 )
return;
V_8 -> V_75 = NULL ;
F_135 ( V_75 ) ;
}
void F_136 ( struct V_2 * V_3 )
{
F_137 ( V_3 ) ;
V_3 -> V_159 &= ~ ( V_160 | V_161 ) ;
V_3 -> V_159 |= V_162 ;
V_3 -> V_93 = & V_163 ;
V_3 -> V_164 = V_165 ;
V_3 -> V_166 = & V_167 ;
V_3 -> V_168 = & V_169 ;
}
static void F_138 ( struct V_2 * V_3 )
{
F_136 ( V_3 ) ;
V_3 -> V_55 = 0 ;
}
static int F_139 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
unsigned int V_31 ;
int V_32 ;
if ( V_3 -> type != V_170 || V_3 -> V_67 & V_171 )
return - V_113 ;
V_6 = F_131 ( sizeof( * V_6 ) , V_158 ) ;
if ( V_6 == NULL )
return - V_54 ;
V_6 -> V_65 = false ;
V_6 -> V_3 = V_3 ;
F_140 ( & V_6 -> V_66 ) ;
for ( V_31 = 0 ; V_31 < V_36 ; V_31 ++ )
F_141 ( & V_6 -> V_11 [ V_31 ] ) ;
F_31 ( & V_6 -> V_49 ) ;
F_142 ( & V_6 -> V_46 , F_29 ) ;
V_32 = F_143 ( V_3 , F_47 , V_6 ) ;
if ( V_32 )
F_133 ( V_6 ) ;
else
V_3 -> V_159 |= V_172 ;
return V_32 ;
}
static void F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_3 ( V_3 ) ;
F_144 ( & V_6 -> V_46 ) ;
V_3 -> V_159 &= ~ V_172 ;
F_145 ( V_3 ) ;
F_146 ( V_6 , V_173 ) ;
}
static int F_147 ( struct V_142 * V_143 [] , struct V_142 * V_71 [] )
{
if ( V_143 [ V_174 ] ) {
if ( F_148 ( V_143 [ V_174 ] ) != V_13 )
return - V_113 ;
if ( ! F_83 ( F_149 ( V_143 [ V_174 ] ) ) )
return - V_104 ;
}
if ( V_71 && V_71 [ V_175 ] &&
F_150 ( V_71 [ V_175 ] ) & ~ V_87 )
return - V_113 ;
if ( V_71 && V_71 [ V_176 ] ) {
switch ( F_151 ( V_71 [ V_176 ] ) ) {
case V_51 :
case V_52 :
case V_40 :
case V_53 :
break;
default:
return - V_113 ;
}
}
return 0 ;
}
int F_152 ( struct V_177 * V_178 , struct V_2 * V_3 ,
struct V_142 * V_143 [] , struct V_142 * V_71 [] )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_2 * V_73 ;
int V_32 ;
if ( ! V_143 [ V_179 ] )
return - V_113 ;
V_73 = F_153 ( V_178 , F_151 ( V_143 [ V_179 ] ) ) ;
if ( V_73 == NULL )
return - V_180 ;
if ( F_154 ( V_73 ) )
V_73 = F_155 ( V_73 ) ;
if ( ! V_143 [ V_181 ] )
V_3 -> V_112 = V_73 -> V_112 ;
else if ( V_3 -> V_112 > V_73 -> V_112 )
return - V_113 ;
if ( ! V_143 [ V_174 ] )
F_156 ( V_3 ) ;
if ( ! F_157 ( V_73 ) ) {
V_32 = F_139 ( V_73 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_6 = F_3 ( V_73 ) ;
if ( V_6 -> V_65 )
return - V_113 ;
V_8 -> V_73 = V_73 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_154 = V_124 ;
V_8 -> V_114 = F_158 ( V_73 , F_154 ) + 1 ;
V_8 -> V_29 = V_52 ;
if ( V_71 && V_71 [ V_176 ] )
V_8 -> V_29 = F_151 ( V_71 [ V_176 ] ) ;
if ( V_71 && V_71 [ V_175 ] )
V_8 -> V_67 = F_150 ( V_71 [ V_175 ] ) ;
if ( V_8 -> V_29 == V_53 ) {
if ( ! F_106 ( V_6 ) )
return - V_113 ;
V_6 -> V_65 = true ;
F_159 ( V_3 , V_73 ) ;
}
V_32 = F_160 ( V_3 ) ;
if ( V_32 < 0 )
goto V_182;
V_3 -> V_159 |= V_183 ;
V_32 = F_161 ( V_73 , V_3 ) ;
if ( V_32 )
goto V_184;
F_162 ( & V_8 -> V_48 , & V_6 -> V_66 ) ;
F_163 ( V_73 , V_3 ) ;
return 0 ;
V_184:
F_164 ( V_3 ) ;
V_182:
if ( F_106 ( V_6 ) )
F_107 ( V_73 ) ;
return V_32 ;
}
static int F_165 ( struct V_177 * V_178 , struct V_2 * V_3 ,
struct V_142 * V_143 [] , struct V_142 * V_71 [] )
{
return F_152 ( V_178 , V_3 , V_143 , V_71 ) ;
}
void F_166 ( struct V_2 * V_3 , struct V_185 * V_186 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
F_167 ( & V_8 -> V_48 ) ;
F_168 ( V_3 , V_186 ) ;
F_169 ( V_8 -> V_73 , V_3 ) ;
}
static int F_170 ( struct V_2 * V_3 ,
struct V_142 * V_143 [] , struct V_142 * V_71 [] )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
enum V_28 V_29 ;
bool V_187 = false ;
if ( V_71 && V_71 [ V_176 ] ) {
V_187 = true ;
V_29 = F_151 ( V_71 [ V_176 ] ) ;
if ( ( V_29 == V_53 ) !=
( V_8 -> V_29 == V_53 ) )
return - V_113 ;
}
if ( V_71 && V_71 [ V_175 ] ) {
T_8 V_67 = F_150 ( V_71 [ V_175 ] ) ;
bool V_188 = ( V_67 ^ V_8 -> V_67 ) & V_87 ;
if ( V_8 -> V_6 -> V_65 && V_188 ) {
int V_32 ;
if ( V_67 & V_87 )
V_32 = F_72 ( V_8 -> V_73 , - 1 ) ;
else
V_32 = F_72 ( V_8 -> V_73 , 1 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_8 -> V_67 = V_67 ;
}
if ( V_187 )
V_8 -> V_29 = V_29 ;
return 0 ;
}
static T_9 F_171 ( const struct V_2 * V_3 )
{
return ( 0
+ F_172 ( 4 )
+ F_172 ( 2 )
) ;
}
static int F_173 ( struct V_14 * V_15 ,
const struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
if ( F_174 ( V_15 , V_176 , V_8 -> V_29 ) )
goto V_189;
if ( F_175 ( V_15 , V_175 , V_8 -> V_67 ) )
goto V_189;
return 0 ;
V_189:
return - V_190 ;
}
int F_176 ( struct V_91 * V_191 )
{
V_191 -> V_192 = sizeof( struct V_5 ) ;
V_191 -> V_193 = F_147 ;
V_191 -> V_194 = V_195 ;
V_191 -> V_196 = V_197 ;
V_191 -> V_198 = F_170 ;
V_191 -> V_199 = F_171 ;
V_191 -> V_200 = F_173 ;
return F_177 ( V_191 ) ;
}
static int F_178 ( struct V_201 * V_202 ,
unsigned long V_203 , void * V_204 )
{
struct V_2 * V_3 = F_179 ( V_204 ) ;
struct V_5 * V_8 , * V_205 ;
struct V_1 * V_6 ;
F_180 ( V_206 ) ;
if ( ! F_157 ( V_3 ) )
return V_207 ;
V_6 = F_3 ( V_3 ) ;
switch ( V_203 ) {
case V_208 :
F_181 (vlan, &port->vlans, list)
F_163 ( V_8 -> V_73 ,
V_8 -> V_3 ) ;
break;
case V_209 :
F_181 (vlan, &port->vlans, list) {
V_8 -> V_3 -> V_126 = V_3 -> V_126 ;
F_182 ( V_8 -> V_3 ) ;
}
break;
case V_210 :
F_181 (vlan, &port->vlans, list) {
if ( V_8 -> V_3 -> V_112 <= V_3 -> V_112 )
continue;
F_183 ( V_8 -> V_3 , V_3 -> V_112 ) ;
}
break;
case V_211 :
if ( ! V_6 -> V_65 )
return V_207 ;
V_8 = F_184 ( & V_6 -> V_66 ,
struct V_5 ,
V_48 ) ;
if ( F_80 ( V_8 -> V_3 , V_3 -> V_9 ) )
return V_212 ;
break;
case V_213 :
if ( V_3 -> V_214 != V_215 )
break;
F_185 (vlan, next, &port->vlans, list)
V_8 -> V_3 -> V_91 -> V_216 ( V_8 -> V_3 , & V_206 ) ;
F_186 ( & V_206 ) ;
break;
case V_217 :
return V_212 ;
case V_218 :
case V_219 :
case V_220 :
F_181 (vlan, &port->vlans, list)
F_187 ( V_203 , V_8 -> V_3 ) ;
}
return V_207 ;
}
static int T_10 F_188 ( void )
{
int V_32 ;
F_189 ( & V_221 ) ;
V_32 = F_176 ( & V_92 ) ;
if ( V_32 < 0 )
goto V_222;
return 0 ;
V_222:
F_190 ( & V_221 ) ;
return V_32 ;
}
static void T_11 F_191 ( void )
{
F_192 ( & V_92 ) ;
F_190 ( & V_221 ) ;
}
