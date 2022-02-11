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
if ( F_42 ( & V_6 -> V_49 ) < V_55 ) {
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
V_3 -> V_126 = V_73 -> V_126 & V_124 ;
V_3 -> V_127 = V_73 -> V_127 ;
V_3 -> V_128 = V_73 -> V_129 ;
V_3 -> V_130 = V_73 -> V_130 ;
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
V_6 -> V_131 -= 1 ;
if ( ! V_6 -> V_131 )
F_106 ( V_6 -> V_3 ) ;
}
static struct V_132 * F_107 ( struct V_2 * V_3 ,
struct V_132 * V_133 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
if ( V_8 -> V_80 ) {
struct V_79 * V_101 ;
T_4 V_134 , V_135 , V_136 , V_82 , V_83 ;
T_1 V_137 = 0 , V_84 = 0 ;
unsigned int V_138 ;
int V_31 ;
F_108 (i) {
V_101 = F_109 ( V_8 -> V_80 , V_31 ) ;
do {
V_138 = F_110 ( & V_101 -> V_81 ) ;
V_134 = V_101 -> V_134 ;
V_135 = V_101 -> V_135 ;
V_136 = V_101 -> V_136 ;
V_82 = V_101 -> V_82 ;
V_83 = V_101 -> V_83 ;
} while ( F_111 ( & V_101 -> V_81 , V_138 ) );
V_133 -> V_134 += V_134 ;
V_133 -> V_135 += V_135 ;
V_133 -> V_139 += V_136 ;
V_133 -> V_82 += V_82 ;
V_133 -> V_83 += V_83 ;
V_137 += V_101 -> V_137 ;
V_84 += V_101 -> V_84 ;
}
V_133 -> V_137 = V_137 ;
V_133 -> V_57 = V_137 ;
V_133 -> V_84 = V_84 ;
}
return V_133 ;
}
static int F_112 ( struct V_2 * V_3 ,
T_5 V_140 , T_6 V_141 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
return F_113 ( V_73 , V_140 , V_141 ) ;
}
static int F_114 ( struct V_2 * V_3 ,
T_5 V_140 , T_6 V_141 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_73 = V_8 -> V_73 ;
F_115 ( V_73 , V_140 , V_141 ) ;
return 0 ;
}
static int F_116 ( struct V_142 * V_143 , struct V_144 * V_145 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 ,
T_6 V_67 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
int V_32 = - V_113 ;
if ( ! V_8 -> V_6 -> V_65 && F_117 ( V_7 ) )
return - V_146 ;
if ( V_67 & V_147 )
return - V_146 ;
if ( F_117 ( V_7 ) )
V_32 = F_118 ( V_3 , V_7 ) ;
else if ( F_48 ( V_7 ) )
V_32 = F_119 ( V_3 , V_7 ) ;
return V_32 ;
}
static int F_120 ( struct V_142 * V_143 , struct V_144 * V_145 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
int V_32 = - V_113 ;
if ( ! V_8 -> V_6 -> V_65 && F_117 ( V_7 ) )
return - V_146 ;
if ( F_117 ( V_7 ) )
V_32 = F_76 ( V_3 , V_7 ) ;
else if ( F_48 ( V_7 ) )
V_32 = F_121 ( V_3 , V_7 ) ;
return V_32 ;
}
static void F_122 ( struct V_2 * V_3 ,
struct V_148 * V_149 )
{
F_123 ( V_149 -> V_150 , L_1 , sizeof( V_149 -> V_150 ) ) ;
F_123 ( V_149 -> V_151 , L_2 , sizeof( V_149 -> V_151 ) ) ;
}
static int F_124 ( struct V_2 * V_3 ,
struct V_152 * V_153 )
{
const struct V_5 * V_8 = F_55 ( V_3 ) ;
return F_125 ( V_8 -> V_73 , V_153 ) ;
}
static T_7 F_126 ( struct V_2 * V_3 ,
T_7 V_89 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
T_7 V_154 ;
V_89 |= V_155 ;
V_89 &= ( V_8 -> V_156 | ~ V_124 ) ;
V_154 = V_89 ;
V_89 = F_127 ( V_8 -> V_73 -> V_89 ,
V_89 ,
V_154 ) ;
V_89 |= V_125 ;
V_89 &= ~ V_157 ;
return V_89 ;
}
static void F_128 ( struct V_2 * V_3 )
{
return;
}
static int F_129 ( struct V_2 * V_3 , struct V_158 * V_159 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_2 * V_160 = V_8 -> V_73 ;
struct V_75 * V_75 ;
int V_32 = 0 ;
V_75 = F_130 ( sizeof( * V_75 ) , V_161 ) ;
V_32 = - V_54 ;
if ( ! V_75 )
goto V_63;
V_32 = F_131 ( V_75 , V_160 ) ;
if ( V_32 ) {
F_132 ( V_75 ) ;
goto V_63;
}
V_8 -> V_75 = V_75 ;
V_63:
return V_32 ;
}
static void F_133 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_75 * V_75 = V_8 -> V_75 ;
if ( ! V_75 )
return;
V_8 -> V_75 = NULL ;
F_134 ( V_75 ) ;
}
void F_135 ( struct V_2 * V_3 )
{
F_136 ( V_3 ) ;
V_3 -> V_162 &= ~ ( V_163 | V_164 ) ;
V_3 -> V_162 |= V_165 ;
V_3 -> V_93 = & V_166 ;
V_3 -> V_167 = V_168 ;
V_3 -> V_169 = & V_170 ;
V_3 -> V_171 = & V_172 ;
}
static void F_137 ( struct V_2 * V_3 )
{
F_135 ( V_3 ) ;
V_3 -> V_173 = 0 ;
}
static int F_138 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
unsigned int V_31 ;
int V_32 ;
if ( V_3 -> type != V_174 || V_3 -> V_67 & V_175 )
return - V_113 ;
V_6 = F_130 ( sizeof( * V_6 ) , V_161 ) ;
if ( V_6 == NULL )
return - V_54 ;
V_6 -> V_65 = false ;
V_6 -> V_3 = V_3 ;
F_139 ( & V_6 -> V_66 ) ;
for ( V_31 = 0 ; V_31 < V_36 ; V_31 ++ )
F_140 ( & V_6 -> V_11 [ V_31 ] ) ;
F_31 ( & V_6 -> V_49 ) ;
F_141 ( & V_6 -> V_46 , F_29 ) ;
V_32 = F_142 ( V_3 , F_47 , V_6 ) ;
if ( V_32 )
F_132 ( V_6 ) ;
else
V_3 -> V_162 |= V_176 ;
return V_32 ;
}
static void F_106 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_3 ( V_3 ) ;
F_143 ( & V_6 -> V_46 ) ;
V_3 -> V_162 &= ~ V_176 ;
F_144 ( V_3 ) ;
F_145 ( V_6 , V_177 ) ;
}
static int F_146 ( struct V_144 * V_145 [] , struct V_144 * V_71 [] )
{
if ( V_145 [ V_178 ] ) {
if ( F_147 ( V_145 [ V_178 ] ) != V_13 )
return - V_113 ;
if ( ! F_83 ( F_148 ( V_145 [ V_178 ] ) ) )
return - V_104 ;
}
if ( V_71 && V_71 [ V_179 ] &&
F_149 ( V_71 [ V_179 ] ) & ~ V_87 )
return - V_113 ;
if ( V_71 && V_71 [ V_180 ] ) {
switch ( F_150 ( V_71 [ V_180 ] ) ) {
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
int F_151 ( struct V_181 * V_182 , struct V_2 * V_3 ,
struct V_144 * V_145 [] , struct V_144 * V_71 [] )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_2 * V_73 ;
int V_32 ;
if ( ! V_145 [ V_183 ] )
return - V_113 ;
V_73 = F_152 ( V_182 , F_150 ( V_145 [ V_183 ] ) ) ;
if ( V_73 == NULL )
return - V_184 ;
if ( F_153 ( V_73 ) )
V_73 = F_154 ( V_73 ) ;
if ( ! V_145 [ V_185 ] )
V_3 -> V_112 = V_73 -> V_112 ;
else if ( V_3 -> V_112 > V_73 -> V_112 )
return - V_113 ;
if ( ! V_145 [ V_178 ] )
F_155 ( V_3 ) ;
if ( ! F_156 ( V_73 ) ) {
V_32 = F_138 ( V_73 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_6 = F_3 ( V_73 ) ;
if ( V_6 -> V_65 )
return - V_113 ;
V_8 -> V_73 = V_73 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_156 = V_124 ;
V_8 -> V_114 = F_157 ( V_73 , F_153 ) + 1 ;
V_8 -> V_29 = V_52 ;
if ( V_71 && V_71 [ V_180 ] )
V_8 -> V_29 = F_150 ( V_71 [ V_180 ] ) ;
if ( V_71 && V_71 [ V_179 ] )
V_8 -> V_67 = F_149 ( V_71 [ V_179 ] ) ;
if ( V_8 -> V_29 == V_53 ) {
if ( V_6 -> V_131 )
return - V_113 ;
V_6 -> V_65 = true ;
F_158 ( V_3 , V_73 ) ;
}
V_6 -> V_131 += 1 ;
V_32 = F_159 ( V_3 ) ;
if ( V_32 < 0 )
goto V_186;
V_3 -> V_162 |= V_187 ;
V_32 = F_160 ( V_73 , V_3 ) ;
if ( V_32 )
goto V_188;
F_161 ( & V_8 -> V_48 , & V_6 -> V_66 ) ;
F_162 ( V_73 , V_3 ) ;
return 0 ;
V_188:
F_163 ( V_3 ) ;
V_186:
V_6 -> V_131 -= 1 ;
if ( ! V_6 -> V_131 )
F_106 ( V_73 ) ;
return V_32 ;
}
static int F_164 ( struct V_181 * V_182 , struct V_2 * V_3 ,
struct V_144 * V_145 [] , struct V_144 * V_71 [] )
{
return F_151 ( V_182 , V_3 , V_145 , V_71 ) ;
}
void F_165 ( struct V_2 * V_3 , struct V_189 * V_190 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
F_166 ( & V_8 -> V_48 ) ;
F_167 ( V_3 , V_190 ) ;
F_168 ( V_8 -> V_73 , V_3 ) ;
}
static int F_169 ( struct V_2 * V_3 ,
struct V_144 * V_145 [] , struct V_144 * V_71 [] )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
enum V_28 V_29 ;
bool V_191 = false ;
if ( V_71 && V_71 [ V_180 ] ) {
V_191 = true ;
V_29 = F_150 ( V_71 [ V_180 ] ) ;
if ( ( V_29 == V_53 ) !=
( V_8 -> V_29 == V_53 ) )
return - V_113 ;
}
if ( V_71 && V_71 [ V_179 ] ) {
T_8 V_67 = F_149 ( V_71 [ V_179 ] ) ;
bool V_192 = ( V_67 ^ V_8 -> V_67 ) & V_87 ;
if ( V_8 -> V_6 -> V_65 && V_192 ) {
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
if ( V_191 )
V_8 -> V_29 = V_29 ;
return 0 ;
}
static T_9 F_170 ( const struct V_2 * V_3 )
{
return ( 0
+ F_171 ( 4 )
+ F_171 ( 2 )
) ;
}
static int F_172 ( struct V_14 * V_15 ,
const struct V_2 * V_3 )
{
struct V_5 * V_8 = F_55 ( V_3 ) ;
if ( F_173 ( V_15 , V_180 , V_8 -> V_29 ) )
goto V_193;
if ( F_174 ( V_15 , V_179 , V_8 -> V_67 ) )
goto V_193;
return 0 ;
V_193:
return - V_194 ;
}
int F_175 ( struct V_91 * V_195 )
{
V_195 -> V_196 = sizeof( struct V_5 ) ;
V_195 -> V_197 = F_146 ;
V_195 -> V_198 = V_199 ;
V_195 -> V_200 = V_201 ;
V_195 -> V_202 = F_169 ;
V_195 -> V_203 = F_170 ;
V_195 -> V_204 = F_172 ;
return F_176 ( V_195 ) ;
}
static int F_177 ( struct V_205 * V_206 ,
unsigned long V_207 , void * V_208 )
{
struct V_2 * V_3 = F_178 ( V_208 ) ;
struct V_5 * V_8 , * V_209 ;
struct V_1 * V_6 ;
F_179 ( V_210 ) ;
if ( ! F_156 ( V_3 ) )
return V_211 ;
V_6 = F_3 ( V_3 ) ;
switch ( V_207 ) {
case V_212 :
F_180 (vlan, &port->vlans, list)
F_162 ( V_8 -> V_73 ,
V_8 -> V_3 ) ;
break;
case V_213 :
F_180 (vlan, &port->vlans, list) {
V_8 -> V_3 -> V_127 = V_3 -> V_127 ;
F_181 ( V_8 -> V_3 ) ;
}
break;
case V_214 :
F_180 (vlan, &port->vlans, list) {
if ( V_8 -> V_3 -> V_112 <= V_3 -> V_112 )
continue;
F_182 ( V_8 -> V_3 , V_3 -> V_112 ) ;
}
break;
case V_215 :
if ( ! V_6 -> V_65 )
return V_211 ;
V_8 = F_183 ( & V_6 -> V_66 ,
struct V_5 ,
V_48 ) ;
if ( F_80 ( V_8 -> V_3 , V_3 -> V_9 ) )
return V_216 ;
break;
case V_217 :
if ( V_3 -> V_218 != V_219 )
break;
F_184 (vlan, next, &port->vlans, list)
V_8 -> V_3 -> V_91 -> V_220 ( V_8 -> V_3 , & V_210 ) ;
F_185 ( & V_210 ) ;
break;
case V_221 :
return V_216 ;
case V_222 :
case V_223 :
case V_224 :
F_180 (vlan, &port->vlans, list)
F_186 ( V_207 , V_8 -> V_3 ) ;
}
return V_211 ;
}
static int T_10 F_187 ( void )
{
int V_32 ;
F_188 ( & V_225 ) ;
V_32 = F_175 ( & V_92 ) ;
if ( V_32 < 0 )
goto V_226;
return 0 ;
V_226:
F_189 ( & V_225 ) ;
return V_32 ;
}
static void T_11 F_190 ( void )
{
F_191 ( & V_92 ) ;
F_189 ( & V_225 ) ;
}
