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
return V_8 -> V_19 ( V_3 , V_15 ) ;
V_15 -> V_3 = V_3 ;
if ( F_7 ( V_17 -> V_20 , V_3 -> V_21 ) )
V_15 -> V_22 = V_23 ;
else
V_15 -> V_22 = V_24 ;
return V_8 -> V_25 ( V_15 ) ;
}
static T_1 F_16 ( const struct V_5 * V_8 )
{
return ( T_1 ) ( ( ( unsigned long ) V_8 ) >> V_26 ) ;
}
static unsigned int F_17 ( const struct V_5 * V_8 ,
const unsigned char * V_7 )
{
T_1 V_27 = F_18 ( V_7 + 2 ) ;
V_27 ^= F_16 ( V_8 ) ;
return F_19 ( V_27 , V_28 ) ;
}
static void F_20 ( struct V_14 * V_15 ,
const struct V_1 * V_6 ,
struct V_2 * V_29 ,
enum V_30 V_31 )
{
const struct V_16 * V_17 = F_21 ( V_15 ) ;
const struct V_5 * V_8 ;
struct V_14 * V_32 ;
unsigned int V_33 ;
int V_34 ;
unsigned int V_35 ;
if ( V_15 -> V_36 == F_22 ( V_37 ) )
return;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 ++ ) {
F_6 (vlan, &port->vlan_hash[i], hlist) {
if ( V_8 -> V_3 == V_29 || ! ( V_8 -> V_31 & V_31 ) )
continue;
V_35 = F_17 ( V_8 , V_17 -> V_20 ) ;
if ( ! F_23 ( V_35 , V_8 -> V_39 ) )
continue;
V_34 = V_40 ;
V_32 = F_24 ( V_15 , V_41 ) ;
if ( F_25 ( V_32 ) )
V_34 = F_15 (
V_32 , V_8 , V_17 ,
V_31 == V_42 ) ;
F_26 ( V_8 , V_15 -> V_43 + V_44 ,
V_34 == V_45 , 1 ) ;
}
}
}
static T_2 F_27 ( struct V_14 * * V_46 )
{
struct V_1 * V_6 ;
struct V_14 * V_15 = * V_46 ;
const struct V_16 * V_17 = F_21 ( V_15 ) ;
const struct V_5 * V_8 ;
const struct V_5 * V_29 ;
struct V_2 * V_3 ;
unsigned int V_43 = 0 ;
int V_47 = V_40 ;
V_6 = F_1 ( V_15 -> V_3 ) ;
if ( F_28 ( V_17 -> V_20 ) ) {
V_15 = F_29 ( V_15 , V_48 ) ;
if ( ! V_15 )
return V_49 ;
V_17 = F_21 ( V_15 ) ;
V_29 = F_5 ( V_6 , V_17 -> V_50 ) ;
if ( ! V_29 )
F_20 ( V_15 , V_6 , NULL ,
V_51 |
V_52 |
V_53 |
V_42 ) ;
else if ( V_29 -> V_31 == V_52 )
F_20 ( V_15 , V_6 , V_29 -> V_3 ,
V_52 |
V_42 ) ;
else if ( V_29 -> V_31 == V_42 )
F_20 ( V_15 , V_6 , V_29 -> V_3 ,
V_52 ) ;
else {
V_8 = V_29 ;
V_47 = F_15 ( V_15 , V_8 , V_17 , 0 ) ;
goto V_54;
}
return V_55 ;
}
if ( V_6 -> V_56 )
V_8 = F_30 ( & V_6 -> V_57 ,
struct V_5 , V_58 ) ;
else
V_8 = F_5 ( V_6 , V_17 -> V_20 ) ;
if ( V_8 == NULL )
return V_55 ;
V_3 = V_8 -> V_3 ;
if ( F_31 ( ! ( V_3 -> V_59 & V_60 ) ) ) {
F_32 ( V_15 ) ;
return V_49 ;
}
V_43 = V_15 -> V_43 + V_44 ;
V_15 = F_33 ( V_15 , V_41 ) ;
if ( ! V_15 )
goto V_54;
V_15 -> V_3 = V_3 ;
V_15 -> V_22 = V_61 ;
V_47 = V_8 -> V_25 ( V_15 ) ;
V_54:
F_26 ( V_8 , V_43 , V_47 == V_45 , 0 ) ;
return V_49 ;
}
static int F_34 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
const struct V_5 * V_8 = F_35 ( V_3 ) ;
const struct V_1 * V_6 = V_8 -> V_6 ;
const struct V_5 * V_62 ;
T_3 V_63 = V_15 -> V_63 ;
if ( V_8 -> V_31 == V_42 ) {
const struct V_16 * V_17 = ( void * ) V_15 -> V_64 ;
V_15 -> V_63 = V_65 ;
if ( F_28 ( V_17 -> V_20 ) ) {
F_20 ( V_15 , V_6 , V_3 , V_42 ) ;
goto V_66;
}
V_62 = F_5 ( V_6 , V_17 -> V_20 ) ;
if ( V_62 && V_62 -> V_31 == V_42 ) {
F_36 ( V_8 -> V_67 , V_15 ) ;
return V_68 ;
}
}
V_66:
V_15 -> V_63 = V_63 ;
V_15 -> V_3 = V_8 -> V_67 ;
return F_37 ( V_15 ) ;
}
T_4 F_38 ( struct V_14 * V_15 ,
struct V_2 * V_3 )
{
unsigned int V_43 = V_15 -> V_43 ;
int V_47 ;
const struct V_5 * V_8 = F_35 ( V_3 ) ;
if ( V_8 -> V_69 ) {
V_15 -> V_3 = V_8 -> V_67 ;
V_47 = F_39 ( V_15 , V_8 -> V_69 ) ;
} else {
V_47 = F_34 ( V_15 , V_3 ) ;
}
if ( F_25 ( V_47 == V_68 || V_47 == V_70 ) ) {
struct V_71 * V_72 ;
V_72 = F_40 ( V_8 -> V_72 ) ;
F_41 ( & V_72 -> V_73 ) ;
V_72 -> V_74 ++ ;
V_72 -> V_75 += V_43 ;
F_42 ( & V_72 -> V_73 ) ;
} else {
F_43 ( V_8 -> V_72 -> V_76 ) ;
}
return V_47 ;
}
static int F_44 ( struct V_14 * V_15 , struct V_2 * V_3 ,
unsigned short type , const void * V_77 ,
const void * V_78 , unsigned V_43 )
{
const struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
return F_45 ( V_15 , V_67 , type , V_77 ,
V_78 ? : V_3 -> V_9 , V_43 ) ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
int V_34 ;
if ( V_8 -> V_6 -> V_56 ) {
if ( ! ( V_8 -> V_59 & V_79 ) ) {
V_34 = F_47 ( V_67 , 1 ) ;
if ( V_34 < 0 )
goto V_54;
}
goto V_80;
}
if ( V_67 -> V_81 & V_82 &&
V_3 -> V_83 == & V_84 ) {
V_8 -> V_69 =
V_67 -> V_85 -> V_86 ( V_67 , V_3 ) ;
if ( F_48 ( V_8 -> V_69 ) ) {
V_8 -> V_69 = NULL ;
} else
return 0 ;
}
V_34 = - V_87 ;
if ( F_14 ( V_8 -> V_6 , V_3 -> V_9 ) )
goto V_54;
V_34 = F_49 ( V_67 , V_3 -> V_9 ) ;
if ( V_34 < 0 )
goto V_54;
if ( V_3 -> V_59 & V_88 ) {
V_34 = F_50 ( V_67 , 1 ) ;
if ( V_34 < 0 )
goto V_89;
}
V_80:
F_8 ( V_8 ) ;
return 0 ;
V_89:
F_51 ( V_67 , V_3 -> V_9 ) ;
V_54:
if ( V_8 -> V_69 ) {
V_67 -> V_85 -> V_90 ( V_67 ,
V_8 -> V_69 ) ;
V_8 -> V_69 = NULL ;
}
return V_34 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
if ( V_8 -> V_69 ) {
V_67 -> V_85 -> V_90 ( V_67 ,
V_8 -> V_69 ) ;
V_8 -> V_69 = NULL ;
return 0 ;
}
F_53 ( V_67 , V_3 ) ;
F_54 ( V_67 , V_3 ) ;
if ( V_8 -> V_6 -> V_56 ) {
if ( ! ( V_8 -> V_59 & V_79 ) )
F_47 ( V_67 , - 1 ) ;
goto V_91;
}
if ( V_3 -> V_59 & V_88 )
F_50 ( V_67 , - 1 ) ;
F_51 ( V_67 , V_3 -> V_9 ) ;
V_91:
F_10 ( V_8 , ! V_3 -> V_92 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , void * V_93 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
struct V_94 * V_7 = V_93 ;
int V_34 ;
if ( ! F_56 ( V_7 -> V_95 ) )
return - V_96 ;
if ( ! ( V_3 -> V_59 & V_60 ) ) {
memcpy ( V_3 -> V_9 , V_7 -> V_95 , V_13 ) ;
} else {
if ( F_14 ( V_8 -> V_6 , V_7 -> V_95 ) )
return - V_87 ;
V_34 = F_49 ( V_67 , V_7 -> V_95 ) ;
if ( V_34 )
return V_34 ;
F_51 ( V_67 , V_3 -> V_9 ) ;
F_13 ( V_8 , V_7 -> V_95 ) ;
}
return 0 ;
}
static void F_57 ( struct V_2 * V_3 , int V_97 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
if ( V_97 & V_88 )
F_50 ( V_67 , V_3 -> V_59 & V_88 ? 1 : - 1 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
if ( V_3 -> V_59 & ( V_98 | V_88 ) ) {
F_59 ( V_8 -> V_39 , V_99 ) ;
} else {
struct V_100 * V_101 ;
F_60 ( V_102 , V_99 ) ;
F_61 ( V_102 , V_99 ) ;
F_62 (ha, dev) {
F_63 ( F_17 ( V_8 , V_101 -> V_7 ) , V_102 ) ;
}
F_63 ( F_17 ( V_8 , V_3 -> V_21 ) , V_102 ) ;
F_64 ( V_8 -> V_39 , V_102 , V_99 ) ;
}
F_65 ( V_8 -> V_67 , V_3 ) ;
F_66 ( V_8 -> V_67 , V_3 ) ;
}
static int F_67 ( struct V_2 * V_3 , int V_103 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
if ( V_103 < 68 || V_8 -> V_67 -> V_104 < V_103 )
return - V_105 ;
V_3 -> V_104 = V_103 ;
return 0 ;
}
static void F_68 ( struct V_2 * V_3 ,
struct V_106 * V_107 ,
void * V_108 )
{
F_69 ( & V_107 -> V_109 ,
& V_110 ) ;
}
static void F_70 ( struct V_2 * V_3 )
{
F_69 ( & V_3 -> V_111 ,
& V_112 ) ;
F_71 ( V_3 , F_68 , NULL ) ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
const struct V_2 * V_67 = V_8 -> V_67 ;
int V_33 ;
V_3 -> V_113 = ( V_3 -> V_113 & ~ V_114 ) |
( V_67 -> V_113 & V_114 ) ;
V_3 -> V_81 = V_67 -> V_81 & V_115 ;
V_3 -> V_81 |= V_116 ;
V_3 -> V_117 = V_67 -> V_117 ;
V_3 -> V_118 = V_67 -> V_119 ;
V_3 -> V_120 = V_67 -> V_120 ;
F_70 ( V_3 ) ;
V_8 -> V_72 = F_73 ( struct V_71 ) ;
if ( ! V_8 -> V_72 )
return - V_121 ;
F_74 (i) {
struct V_71 * V_122 ;
V_122 = F_75 ( V_8 -> V_72 , V_33 ) ;
F_76 ( & V_122 -> V_73 ) ;
}
return 0 ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_1 * V_6 = V_8 -> V_6 ;
F_78 ( V_8 -> V_72 ) ;
V_6 -> V_123 -= 1 ;
if ( ! V_6 -> V_123 )
F_79 ( V_6 -> V_3 ) ;
}
static struct V_124 * F_80 ( struct V_2 * V_3 ,
struct V_124 * V_125 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
if ( V_8 -> V_72 ) {
struct V_71 * V_93 ;
T_5 V_126 , V_127 , V_128 , V_74 , V_75 ;
T_1 V_129 = 0 , V_76 = 0 ;
unsigned int V_130 ;
int V_33 ;
F_74 (i) {
V_93 = F_75 ( V_8 -> V_72 , V_33 ) ;
do {
V_130 = F_81 ( & V_93 -> V_73 ) ;
V_126 = V_93 -> V_126 ;
V_127 = V_93 -> V_127 ;
V_128 = V_93 -> V_128 ;
V_74 = V_93 -> V_74 ;
V_75 = V_93 -> V_75 ;
} while ( F_82 ( & V_93 -> V_73 , V_130 ) );
V_125 -> V_126 += V_126 ;
V_125 -> V_127 += V_127 ;
V_125 -> V_131 += V_128 ;
V_125 -> V_74 += V_74 ;
V_125 -> V_75 += V_75 ;
V_129 += V_93 -> V_129 ;
V_76 += V_93 -> V_76 ;
}
V_125 -> V_129 = V_129 ;
V_125 -> V_132 = V_129 ;
V_125 -> V_76 = V_76 ;
}
return V_125 ;
}
static int F_83 ( struct V_2 * V_3 ,
T_6 V_133 , T_7 V_134 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
return F_84 ( V_67 , V_133 , V_134 ) ;
}
static int F_85 ( struct V_2 * V_3 ,
T_6 V_133 , T_7 V_134 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
F_86 ( V_67 , V_133 , V_134 ) ;
return 0 ;
}
static int F_87 ( struct V_135 * V_136 , struct V_137 * V_138 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 ,
T_7 V_59 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
int V_34 = - V_105 ;
if ( ! V_8 -> V_6 -> V_56 )
return - V_139 ;
if ( V_59 & V_140 )
return - V_139 ;
if ( F_88 ( V_7 ) )
V_34 = F_89 ( V_3 , V_7 ) ;
else if ( F_28 ( V_7 ) )
V_34 = F_90 ( V_3 , V_7 ) ;
return V_34 ;
}
static int F_91 ( struct V_135 * V_136 , struct V_137 * V_138 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
int V_34 = - V_105 ;
if ( ! V_8 -> V_6 -> V_56 )
return - V_139 ;
if ( F_88 ( V_7 ) )
V_34 = F_51 ( V_3 , V_7 ) ;
else if ( F_28 ( V_7 ) )
V_34 = F_92 ( V_3 , V_7 ) ;
return V_34 ;
}
static void F_93 ( struct V_2 * V_3 ,
struct V_141 * V_142 )
{
F_94 ( V_142 -> V_143 , L_1 , sizeof( V_142 -> V_143 ) ) ;
F_94 ( V_142 -> V_144 , L_2 , sizeof( V_142 -> V_144 ) ) ;
}
static int F_95 ( struct V_2 * V_3 ,
struct V_145 * V_146 )
{
const struct V_5 * V_8 = F_35 ( V_3 ) ;
return F_96 ( V_8 -> V_67 , V_146 ) ;
}
static T_8 F_97 ( struct V_2 * V_3 ,
T_8 V_81 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
T_8 V_147 ;
V_81 |= V_148 ;
V_81 &= ( V_8 -> V_149 | ~ V_115 ) ;
V_147 = V_81 ;
V_81 = F_98 ( V_8 -> V_67 -> V_81 ,
V_81 ,
V_147 ) ;
V_81 |= V_116 ;
return V_81 ;
}
void F_99 ( struct V_2 * V_3 )
{
F_100 ( V_3 ) ;
V_3 -> V_150 &= ~ ( V_151 | V_152 ) ;
V_3 -> V_150 |= V_153 ;
V_3 -> V_85 = & V_154 ;
V_3 -> V_155 = V_156 ;
V_3 -> V_157 = & V_158 ;
V_3 -> V_159 = & V_160 ;
}
static void F_101 ( struct V_2 * V_3 )
{
F_99 ( V_3 ) ;
V_3 -> V_161 = 0 ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
unsigned int V_33 ;
int V_34 ;
if ( V_3 -> type != V_162 || V_3 -> V_59 & V_163 )
return - V_105 ;
V_6 = F_103 ( sizeof( * V_6 ) , V_164 ) ;
if ( V_6 == NULL )
return - V_121 ;
V_6 -> V_56 = false ;
V_6 -> V_3 = V_3 ;
F_104 ( & V_6 -> V_57 ) ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 ++ )
F_105 ( & V_6 -> V_11 [ V_33 ] ) ;
V_34 = F_106 ( V_3 , F_27 , V_6 ) ;
if ( V_34 )
F_107 ( V_6 ) ;
else
V_3 -> V_150 |= V_165 ;
return V_34 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_3 ( V_3 ) ;
V_3 -> V_150 &= ~ V_165 ;
F_108 ( V_3 ) ;
F_109 ( V_6 , V_166 ) ;
}
static int F_110 ( struct V_137 * V_138 [] , struct V_137 * V_64 [] )
{
if ( V_138 [ V_167 ] ) {
if ( F_111 ( V_138 [ V_167 ] ) != V_13 )
return - V_105 ;
if ( ! F_56 ( F_112 ( V_138 [ V_167 ] ) ) )
return - V_96 ;
}
if ( V_64 && V_64 [ V_168 ] &&
F_113 ( V_64 [ V_168 ] ) & ~ V_79 )
return - V_105 ;
if ( V_64 && V_64 [ V_169 ] ) {
switch ( F_114 ( V_64 [ V_169 ] ) ) {
case V_51 :
case V_52 :
case V_42 :
case V_53 :
break;
default:
return - V_105 ;
}
}
return 0 ;
}
int F_115 ( struct V_170 * V_171 , struct V_2 * V_3 ,
struct V_137 * V_138 [] , struct V_137 * V_64 [] ,
int (* V_25)( struct V_14 * V_15 ) ,
int (* V_19)( struct V_2 * V_3 ,
struct V_14 * V_15 ) )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_2 * V_67 ;
int V_34 ;
if ( ! V_138 [ V_172 ] )
return - V_105 ;
V_67 = F_116 ( V_171 , F_114 ( V_138 [ V_172 ] ) ) ;
if ( V_67 == NULL )
return - V_173 ;
if ( V_67 -> V_83 == V_3 -> V_83 ) {
struct V_5 * V_174 = F_35 ( V_67 ) ;
V_67 = V_174 -> V_67 ;
}
if ( ! V_138 [ V_175 ] )
V_3 -> V_104 = V_67 -> V_104 ;
else if ( V_3 -> V_104 > V_67 -> V_104 )
return - V_105 ;
if ( ! V_138 [ V_167 ] )
F_117 ( V_3 ) ;
if ( ! F_118 ( V_67 ) ) {
V_34 = F_102 ( V_67 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_6 = F_3 ( V_67 ) ;
if ( V_6 -> V_56 )
return - V_105 ;
V_8 -> V_67 = V_67 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_25 = V_25 ;
V_8 -> V_19 = V_19 ;
V_8 -> V_149 = V_115 ;
V_8 -> V_31 = V_52 ;
if ( V_64 && V_64 [ V_169 ] )
V_8 -> V_31 = F_114 ( V_64 [ V_169 ] ) ;
if ( V_64 && V_64 [ V_168 ] )
V_8 -> V_59 = F_113 ( V_64 [ V_168 ] ) ;
if ( V_8 -> V_31 == V_53 ) {
if ( V_6 -> V_123 )
return - V_105 ;
V_6 -> V_56 = true ;
F_119 ( V_3 , V_67 ) ;
}
V_6 -> V_123 += 1 ;
V_34 = F_120 ( V_3 ) ;
if ( V_34 < 0 )
goto V_176;
V_3 -> V_150 |= V_177 ;
V_34 = F_121 ( V_67 , V_3 ) ;
if ( V_34 )
goto V_176;
F_122 ( & V_8 -> V_58 , & V_6 -> V_57 ) ;
F_123 ( V_67 , V_3 ) ;
return 0 ;
V_176:
V_6 -> V_123 -= 1 ;
if ( ! V_6 -> V_123 )
F_79 ( V_67 ) ;
return V_34 ;
}
static int F_124 ( struct V_170 * V_171 , struct V_2 * V_3 ,
struct V_137 * V_138 [] , struct V_137 * V_64 [] )
{
return F_115 ( V_171 , V_3 , V_138 , V_64 ,
V_178 ,
F_36 ) ;
}
void F_125 ( struct V_2 * V_3 , struct V_179 * V_180 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
F_126 ( & V_8 -> V_58 ) ;
F_127 ( V_3 , V_180 ) ;
F_128 ( V_8 -> V_67 , V_3 ) ;
}
static int F_129 ( struct V_2 * V_3 ,
struct V_137 * V_138 [] , struct V_137 * V_64 [] )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
enum V_30 V_31 ;
bool V_181 = false ;
if ( V_64 && V_64 [ V_169 ] ) {
V_181 = true ;
V_31 = F_114 ( V_64 [ V_169 ] ) ;
if ( ( V_31 == V_53 ) !=
( V_8 -> V_31 == V_53 ) )
return - V_105 ;
}
if ( V_64 && V_64 [ V_168 ] ) {
T_9 V_59 = F_113 ( V_64 [ V_168 ] ) ;
bool V_182 = ( V_59 ^ V_8 -> V_59 ) & V_79 ;
if ( V_8 -> V_6 -> V_56 && V_182 ) {
int V_34 ;
if ( V_59 & V_79 )
V_34 = F_47 ( V_8 -> V_67 , - 1 ) ;
else
V_34 = F_47 ( V_8 -> V_67 , 1 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_8 -> V_59 = V_59 ;
}
if ( V_181 )
V_8 -> V_31 = V_31 ;
return 0 ;
}
static T_10 F_130 ( const struct V_2 * V_3 )
{
return ( 0
+ F_131 ( 4 )
+ F_131 ( 2 )
) ;
}
static int F_132 ( struct V_14 * V_15 ,
const struct V_2 * V_3 )
{
struct V_5 * V_8 = F_35 ( V_3 ) ;
if ( F_133 ( V_15 , V_169 , V_8 -> V_31 ) )
goto V_183;
if ( F_134 ( V_15 , V_168 , V_8 -> V_59 ) )
goto V_183;
return 0 ;
V_183:
return - V_184 ;
}
int F_135 ( struct V_83 * V_185 )
{
V_185 -> V_186 = sizeof( struct V_5 ) ;
V_185 -> V_187 = F_110 ;
V_185 -> V_188 = V_189 ;
V_185 -> V_190 = V_191 ;
V_185 -> V_192 = F_129 ;
V_185 -> V_193 = F_130 ;
V_185 -> V_194 = F_132 ;
return F_136 ( V_185 ) ;
}
static int F_137 ( struct V_195 * V_196 ,
unsigned long V_197 , void * V_198 )
{
struct V_2 * V_3 = F_138 ( V_198 ) ;
struct V_5 * V_8 , * V_199 ;
struct V_1 * V_6 ;
F_139 ( V_200 ) ;
if ( ! F_118 ( V_3 ) )
return V_201 ;
V_6 = F_3 ( V_3 ) ;
switch ( V_197 ) {
case V_202 :
F_140 (vlan, &port->vlans, list)
F_123 ( V_8 -> V_67 ,
V_8 -> V_3 ) ;
break;
case V_203 :
F_140 (vlan, &port->vlans, list) {
V_8 -> V_3 -> V_117 = V_3 -> V_117 ;
F_141 ( V_8 -> V_3 ) ;
}
break;
case V_204 :
if ( V_3 -> V_205 != V_206 )
break;
F_142 (vlan, next, &port->vlans, list)
V_8 -> V_3 -> V_83 -> V_207 ( V_8 -> V_3 , & V_200 ) ;
F_143 ( & V_200 ) ;
F_144 ( & V_200 ) ;
break;
case V_208 :
return V_209 ;
}
return V_201 ;
}
static int T_11 F_145 ( void )
{
int V_34 ;
F_146 ( & V_210 ) ;
V_34 = F_135 ( & V_84 ) ;
if ( V_34 < 0 )
goto V_211;
return 0 ;
V_211:
F_147 ( & V_210 ) ;
return V_34 ;
}
static void T_12 F_148 ( void )
{
F_149 ( & V_84 ) ;
F_147 ( & V_210 ) ;
}
