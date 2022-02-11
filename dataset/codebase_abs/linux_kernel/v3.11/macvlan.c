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
if ( ! V_15 )
return V_19 ;
if ( V_18 )
return V_8 -> V_20 ( V_3 , V_15 ) ;
V_15 -> V_3 = V_3 ;
if ( F_7 ( V_17 -> V_21 , V_3 -> V_22 ) )
V_15 -> V_23 = V_24 ;
else
V_15 -> V_23 = V_25 ;
return V_8 -> V_26 ( V_15 ) ;
}
static T_1 F_16 ( const struct V_5 * V_8 )
{
return ( T_1 ) ( ( ( unsigned long ) V_8 ) >> V_27 ) ;
}
static unsigned int F_17 ( const struct V_5 * V_8 ,
const unsigned char * V_7 )
{
T_1 V_28 = F_18 ( V_7 + 2 ) ;
V_28 ^= F_16 ( V_8 ) ;
return F_19 ( V_28 , V_29 ) ;
}
static void F_20 ( struct V_14 * V_15 ,
const struct V_1 * V_6 ,
struct V_2 * V_30 ,
enum V_31 V_32 )
{
const struct V_16 * V_17 = F_21 ( V_15 ) ;
const struct V_5 * V_8 ;
struct V_14 * V_33 ;
unsigned int V_34 ;
int V_35 ;
unsigned int V_36 ;
if ( V_15 -> V_37 == F_22 ( V_38 ) )
return;
for ( V_34 = 0 ; V_34 < V_39 ; V_34 ++ ) {
F_6 (vlan, &port->vlan_hash[i], hlist) {
if ( V_8 -> V_3 == V_30 || ! ( V_8 -> V_32 & V_32 ) )
continue;
V_36 = F_17 ( V_8 , V_17 -> V_21 ) ;
if ( ! F_23 ( V_36 , V_8 -> V_40 ) )
continue;
V_33 = F_24 ( V_15 , V_41 ) ;
V_35 = F_15 ( V_33 , V_8 , V_17 ,
V_32 == V_42 ) ;
F_25 ( V_8 , V_15 -> V_43 + V_44 ,
V_35 == V_45 , 1 ) ;
}
}
}
static T_2 F_26 ( struct V_14 * * V_46 )
{
struct V_1 * V_6 ;
struct V_14 * V_15 = * V_46 ;
const struct V_16 * V_17 = F_21 ( V_15 ) ;
const struct V_5 * V_8 ;
const struct V_5 * V_30 ;
struct V_2 * V_3 ;
unsigned int V_43 = 0 ;
int V_47 = V_19 ;
V_6 = F_1 ( V_15 -> V_3 ) ;
if ( F_27 ( V_17 -> V_21 ) ) {
V_15 = F_28 ( V_15 , V_48 ) ;
if ( ! V_15 )
return V_49 ;
V_17 = F_21 ( V_15 ) ;
V_30 = F_5 ( V_6 , V_17 -> V_50 ) ;
if ( ! V_30 )
F_20 ( V_15 , V_6 , NULL ,
V_51 |
V_52 |
V_53 |
V_42 ) ;
else if ( V_30 -> V_32 == V_52 )
F_20 ( V_15 , V_6 , V_30 -> V_3 ,
V_52 |
V_42 ) ;
else if ( V_30 -> V_32 == V_42 )
F_20 ( V_15 , V_6 , V_30 -> V_3 ,
V_52 ) ;
else {
V_8 = V_30 ;
V_47 = F_15 ( V_15 , V_8 , V_17 , 0 ) ;
goto V_54;
}
return V_55 ;
}
if ( V_6 -> V_56 )
V_8 = F_29 ( & V_6 -> V_57 ,
struct V_5 , V_58 ) ;
else
V_8 = F_5 ( V_6 , V_17 -> V_21 ) ;
if ( V_8 == NULL )
return V_55 ;
V_3 = V_8 -> V_3 ;
if ( F_30 ( ! ( V_3 -> V_59 & V_60 ) ) ) {
F_31 ( V_15 ) ;
return V_49 ;
}
V_43 = V_15 -> V_43 + V_44 ;
V_15 = F_32 ( V_15 , V_41 ) ;
if ( ! V_15 )
goto V_54;
V_15 -> V_3 = V_3 ;
V_15 -> V_23 = V_61 ;
V_47 = V_8 -> V_26 ( V_15 ) ;
V_54:
F_25 ( V_8 , V_43 , V_47 == V_45 , 0 ) ;
return V_49 ;
}
static int F_33 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
const struct V_5 * V_8 = F_34 ( V_3 ) ;
const struct V_1 * V_6 = V_8 -> V_6 ;
const struct V_5 * V_62 ;
T_3 V_63 = V_15 -> V_63 ;
if ( V_8 -> V_32 == V_42 ) {
const struct V_16 * V_17 = ( void * ) V_15 -> V_64 ;
V_15 -> V_63 = V_65 ;
if ( F_27 ( V_17 -> V_21 ) ) {
F_20 ( V_15 , V_6 , V_3 , V_42 ) ;
goto V_66;
}
V_62 = F_5 ( V_6 , V_17 -> V_21 ) ;
if ( V_62 && V_62 -> V_32 == V_42 ) {
F_35 ( V_8 -> V_67 , V_15 ) ;
return V_68 ;
}
}
V_66:
V_15 -> V_63 = V_63 ;
V_15 -> V_3 = V_8 -> V_67 ;
return F_36 ( V_15 ) ;
}
T_4 F_37 ( struct V_14 * V_15 ,
struct V_2 * V_3 )
{
unsigned int V_43 = V_15 -> V_43 ;
int V_47 ;
const struct V_5 * V_8 = F_34 ( V_3 ) ;
V_47 = F_33 ( V_15 , V_3 ) ;
if ( F_38 ( V_47 == V_68 || V_47 == V_69 ) ) {
struct V_70 * V_71 ;
V_71 = F_39 ( V_8 -> V_71 ) ;
F_40 ( & V_71 -> V_72 ) ;
V_71 -> V_73 ++ ;
V_71 -> V_74 += V_43 ;
F_41 ( & V_71 -> V_72 ) ;
} else {
F_42 ( V_8 -> V_71 -> V_75 ) ;
}
return V_47 ;
}
static int F_43 ( struct V_14 * V_15 , struct V_2 * V_3 ,
unsigned short type , const void * V_76 ,
const void * V_77 , unsigned V_43 )
{
const struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
return F_44 ( V_15 , V_67 , type , V_76 ,
V_77 ? : V_3 -> V_9 , V_43 ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
int V_35 ;
if ( V_8 -> V_6 -> V_56 ) {
if ( ! ( V_8 -> V_59 & V_78 ) ) {
V_35 = F_46 ( V_67 , 1 ) ;
if ( V_35 < 0 )
goto V_54;
}
goto V_79;
}
V_35 = - V_80 ;
if ( F_14 ( V_8 -> V_6 , V_3 -> V_9 ) )
goto V_54;
V_35 = F_47 ( V_67 , V_3 -> V_9 ) ;
if ( V_35 < 0 )
goto V_54;
if ( V_3 -> V_59 & V_81 ) {
V_35 = F_48 ( V_67 , 1 ) ;
if ( V_35 < 0 )
goto V_82;
}
V_79:
F_8 ( V_8 ) ;
return 0 ;
V_82:
F_49 ( V_67 , V_3 -> V_9 ) ;
V_54:
return V_35 ;
}
static int F_50 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
F_51 ( V_67 , V_3 ) ;
F_52 ( V_67 , V_3 ) ;
if ( V_8 -> V_6 -> V_56 ) {
if ( ! ( V_8 -> V_59 & V_78 ) )
F_46 ( V_67 , - 1 ) ;
goto V_83;
}
if ( V_3 -> V_59 & V_81 )
F_48 ( V_67 , - 1 ) ;
F_49 ( V_67 , V_3 -> V_9 ) ;
V_83:
F_10 ( V_8 , ! V_3 -> V_84 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 , void * V_85 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
struct V_86 * V_7 = V_85 ;
int V_35 ;
if ( ! F_54 ( V_7 -> V_87 ) )
return - V_88 ;
if ( ! ( V_3 -> V_59 & V_60 ) ) {
memcpy ( V_3 -> V_9 , V_7 -> V_87 , V_13 ) ;
} else {
if ( F_14 ( V_8 -> V_6 , V_7 -> V_87 ) )
return - V_80 ;
V_35 = F_47 ( V_67 , V_7 -> V_87 ) ;
if ( V_35 )
return V_35 ;
F_49 ( V_67 , V_3 -> V_9 ) ;
F_13 ( V_8 , V_7 -> V_87 ) ;
}
return 0 ;
}
static void F_55 ( struct V_2 * V_3 , int V_89 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
if ( V_89 & V_81 )
F_48 ( V_67 , V_3 -> V_59 & V_81 ? 1 : - 1 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
if ( V_3 -> V_59 & ( V_90 | V_81 ) ) {
F_57 ( V_8 -> V_40 , V_91 ) ;
} else {
struct V_92 * V_93 ;
F_58 ( V_94 , V_91 ) ;
F_59 ( V_94 , V_91 ) ;
F_60 (ha, dev) {
F_61 ( F_17 ( V_8 , V_93 -> V_7 ) , V_94 ) ;
}
F_61 ( F_17 ( V_8 , V_3 -> V_22 ) , V_94 ) ;
F_62 ( V_8 -> V_40 , V_94 , V_91 ) ;
}
F_63 ( V_8 -> V_67 , V_3 ) ;
F_64 ( V_8 -> V_67 , V_3 ) ;
}
static int F_65 ( struct V_2 * V_3 , int V_95 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
if ( V_95 < 68 || V_8 -> V_67 -> V_96 < V_95 )
return - V_97 ;
V_3 -> V_96 = V_95 ;
return 0 ;
}
static void F_66 ( struct V_2 * V_3 ,
struct V_98 * V_99 ,
void * V_100 )
{
F_67 ( & V_99 -> V_101 ,
& V_102 ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
F_67 ( & V_3 -> V_103 ,
& V_104 ) ;
F_69 ( V_3 , F_66 , NULL ) ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
const struct V_2 * V_67 = V_8 -> V_67 ;
V_3 -> V_105 = ( V_3 -> V_105 & ~ V_106 ) |
( V_67 -> V_105 & V_106 ) ;
V_3 -> V_107 = V_67 -> V_107 & V_108 ;
V_3 -> V_107 |= V_109 ;
V_3 -> V_110 = V_67 -> V_110 ;
V_3 -> V_111 = V_67 -> V_112 ;
V_3 -> V_113 = V_67 -> V_113 ;
F_68 ( V_3 ) ;
V_8 -> V_71 = F_71 ( struct V_70 ) ;
if ( ! V_8 -> V_71 )
return - V_114 ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_1 * V_6 = V_8 -> V_6 ;
F_73 ( V_8 -> V_71 ) ;
V_6 -> V_115 -= 1 ;
if ( ! V_6 -> V_115 )
F_74 ( V_6 -> V_3 ) ;
}
static struct V_116 * F_75 ( struct V_2 * V_3 ,
struct V_116 * V_117 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
if ( V_8 -> V_71 ) {
struct V_70 * V_85 ;
T_5 V_118 , V_119 , V_120 , V_73 , V_74 ;
T_1 V_121 = 0 , V_75 = 0 ;
unsigned int V_122 ;
int V_34 ;
F_76 (i) {
V_85 = F_77 ( V_8 -> V_71 , V_34 ) ;
do {
V_122 = F_78 ( & V_85 -> V_72 ) ;
V_118 = V_85 -> V_118 ;
V_119 = V_85 -> V_119 ;
V_120 = V_85 -> V_120 ;
V_73 = V_85 -> V_73 ;
V_74 = V_85 -> V_74 ;
} while ( F_79 ( & V_85 -> V_72 , V_122 ) );
V_117 -> V_118 += V_118 ;
V_117 -> V_119 += V_119 ;
V_117 -> V_123 += V_120 ;
V_117 -> V_73 += V_73 ;
V_117 -> V_74 += V_74 ;
V_121 += V_85 -> V_121 ;
V_75 += V_85 -> V_75 ;
}
V_117 -> V_121 = V_121 ;
V_117 -> V_124 = V_121 ;
V_117 -> V_75 = V_75 ;
}
return V_117 ;
}
static int F_80 ( struct V_2 * V_3 ,
T_6 V_125 , T_7 V_126 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
return F_81 ( V_67 , V_125 , V_126 ) ;
}
static int F_82 ( struct V_2 * V_3 ,
T_6 V_125 , T_7 V_126 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_2 * V_67 = V_8 -> V_67 ;
F_83 ( V_67 , V_125 , V_126 ) ;
return 0 ;
}
static int F_84 ( struct V_127 * V_128 , struct V_129 * V_130 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 ,
T_7 V_59 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
int V_35 = - V_97 ;
if ( ! V_8 -> V_6 -> V_56 )
return - V_131 ;
if ( F_85 ( V_7 ) )
V_35 = F_86 ( V_3 , V_7 ) ;
else if ( F_27 ( V_7 ) )
V_35 = F_87 ( V_3 , V_7 ) ;
return V_35 ;
}
static int F_88 ( struct V_127 * V_128 , struct V_129 * V_130 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
int V_35 = - V_97 ;
if ( ! V_8 -> V_6 -> V_56 )
return - V_131 ;
if ( F_85 ( V_7 ) )
V_35 = F_49 ( V_3 , V_7 ) ;
else if ( F_27 ( V_7 ) )
V_35 = F_89 ( V_3 , V_7 ) ;
return V_35 ;
}
static void F_90 ( struct V_2 * V_3 ,
struct V_132 * V_133 )
{
F_91 ( V_133 -> V_134 , L_1 , sizeof( V_133 -> V_134 ) ) ;
F_91 ( V_133 -> V_135 , L_2 , sizeof( V_133 -> V_135 ) ) ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_136 * V_137 )
{
const struct V_5 * V_8 = F_34 ( V_3 ) ;
return F_93 ( V_8 -> V_67 , V_137 ) ;
}
static T_8 F_94 ( struct V_2 * V_3 ,
T_8 V_107 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
return V_107 & ( V_8 -> V_138 | ~ V_108 ) ;
}
void F_95 ( struct V_2 * V_3 )
{
F_96 ( V_3 ) ;
V_3 -> V_139 &= ~ ( V_140 | V_141 ) ;
V_3 -> V_139 |= V_142 ;
V_3 -> V_143 = & V_144 ;
V_3 -> V_145 = V_146 ;
V_3 -> V_147 = & V_148 ,
V_3 -> V_149 = & V_150 ;
}
static void F_97 ( struct V_2 * V_3 )
{
F_95 ( V_3 ) ;
V_3 -> V_151 = 0 ;
}
static int F_98 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
unsigned int V_34 ;
int V_35 ;
if ( V_3 -> type != V_152 || V_3 -> V_59 & V_153 )
return - V_97 ;
V_6 = F_99 ( sizeof( * V_6 ) , V_154 ) ;
if ( V_6 == NULL )
return - V_114 ;
V_6 -> V_56 = false ;
V_6 -> V_3 = V_3 ;
F_100 ( & V_6 -> V_57 ) ;
for ( V_34 = 0 ; V_34 < V_39 ; V_34 ++ )
F_101 ( & V_6 -> V_11 [ V_34 ] ) ;
V_35 = F_102 ( V_3 , F_26 , V_6 ) ;
if ( V_35 )
F_103 ( V_6 ) ;
else
V_3 -> V_139 |= V_155 ;
return V_35 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_3 ( V_3 ) ;
V_3 -> V_139 &= ~ V_155 ;
F_104 ( V_3 ) ;
F_105 ( V_6 , V_156 ) ;
}
static int F_106 ( struct V_129 * V_130 [] , struct V_129 * V_64 [] )
{
if ( V_130 [ V_157 ] ) {
if ( F_107 ( V_130 [ V_157 ] ) != V_13 )
return - V_97 ;
if ( ! F_54 ( F_108 ( V_130 [ V_157 ] ) ) )
return - V_88 ;
}
if ( V_64 && V_64 [ V_158 ] &&
F_109 ( V_64 [ V_158 ] ) & ~ V_78 )
return - V_97 ;
if ( V_64 && V_64 [ V_159 ] ) {
switch ( F_110 ( V_64 [ V_159 ] ) ) {
case V_51 :
case V_52 :
case V_42 :
case V_53 :
break;
default:
return - V_97 ;
}
}
return 0 ;
}
int F_111 ( struct V_160 * V_161 , struct V_2 * V_3 ,
struct V_129 * V_130 [] , struct V_129 * V_64 [] ,
int (* V_26)( struct V_14 * V_15 ) ,
int (* V_20)( struct V_2 * V_3 ,
struct V_14 * V_15 ) )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_2 * V_67 ;
int V_35 ;
if ( ! V_130 [ V_162 ] )
return - V_97 ;
V_67 = F_112 ( V_161 , F_110 ( V_130 [ V_162 ] ) ) ;
if ( V_67 == NULL )
return - V_163 ;
if ( V_67 -> V_164 == V_3 -> V_164 ) {
struct V_5 * V_165 = F_34 ( V_67 ) ;
V_67 = V_165 -> V_67 ;
}
if ( ! V_130 [ V_166 ] )
V_3 -> V_96 = V_67 -> V_96 ;
else if ( V_3 -> V_96 > V_67 -> V_96 )
return - V_97 ;
if ( ! V_130 [ V_157 ] )
F_113 ( V_3 ) ;
if ( ! F_114 ( V_67 ) ) {
V_35 = F_98 ( V_67 ) ;
if ( V_35 < 0 )
return V_35 ;
}
V_6 = F_3 ( V_67 ) ;
if ( V_6 -> V_56 )
return - V_97 ;
V_8 -> V_67 = V_67 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_26 = V_26 ;
V_8 -> V_20 = V_20 ;
V_8 -> V_138 = V_108 ;
V_8 -> V_32 = V_52 ;
if ( V_64 && V_64 [ V_159 ] )
V_8 -> V_32 = F_110 ( V_64 [ V_159 ] ) ;
if ( V_64 && V_64 [ V_158 ] )
V_8 -> V_59 = F_109 ( V_64 [ V_158 ] ) ;
if ( V_8 -> V_32 == V_53 ) {
if ( V_6 -> V_115 )
return - V_97 ;
V_6 -> V_56 = true ;
memcpy ( V_3 -> V_9 , V_67 -> V_9 , V_13 ) ;
}
V_35 = F_115 ( V_67 , V_3 ) ;
if ( V_35 )
goto V_167;
V_6 -> V_115 += 1 ;
V_35 = F_116 ( V_3 ) ;
if ( V_35 < 0 )
goto V_168;
F_117 ( & V_8 -> V_58 , & V_6 -> V_57 ) ;
F_118 ( V_67 , V_3 ) ;
return 0 ;
V_168:
F_119 ( V_67 , V_3 ) ;
V_167:
V_6 -> V_115 -= 1 ;
if ( ! V_6 -> V_115 )
F_74 ( V_67 ) ;
return V_35 ;
}
static int F_120 ( struct V_160 * V_161 , struct V_2 * V_3 ,
struct V_129 * V_130 [] , struct V_129 * V_64 [] )
{
return F_111 ( V_161 , V_3 , V_130 , V_64 ,
V_169 ,
F_35 ) ;
}
void F_121 ( struct V_2 * V_3 , struct V_170 * V_171 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
F_122 ( & V_8 -> V_58 ) ;
F_123 ( V_3 , V_171 ) ;
F_119 ( V_8 -> V_67 , V_3 ) ;
}
static int F_124 ( struct V_2 * V_3 ,
struct V_129 * V_130 [] , struct V_129 * V_64 [] )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
enum V_31 V_32 ;
bool V_172 = false ;
if ( V_64 && V_64 [ V_159 ] ) {
V_172 = true ;
V_32 = F_110 ( V_64 [ V_159 ] ) ;
if ( ( V_32 == V_53 ) !=
( V_8 -> V_32 == V_53 ) )
return - V_97 ;
}
if ( V_64 && V_64 [ V_158 ] ) {
T_9 V_59 = F_109 ( V_64 [ V_158 ] ) ;
bool V_173 = ( V_59 ^ V_8 -> V_59 ) & V_78 ;
if ( V_8 -> V_6 -> V_56 && V_173 ) {
int V_35 ;
if ( V_59 & V_78 )
V_35 = F_46 ( V_8 -> V_67 , - 1 ) ;
else
V_35 = F_46 ( V_8 -> V_67 , 1 ) ;
if ( V_35 < 0 )
return V_35 ;
}
V_8 -> V_59 = V_59 ;
}
if ( V_172 )
V_8 -> V_32 = V_32 ;
return 0 ;
}
static T_10 F_125 ( const struct V_2 * V_3 )
{
return ( 0
+ F_126 ( 4 )
+ F_126 ( 2 )
) ;
}
static int F_127 ( struct V_14 * V_15 ,
const struct V_2 * V_3 )
{
struct V_5 * V_8 = F_34 ( V_3 ) ;
if ( F_128 ( V_15 , V_159 , V_8 -> V_32 ) )
goto V_174;
if ( F_129 ( V_15 , V_158 , V_8 -> V_59 ) )
goto V_174;
return 0 ;
V_174:
return - V_175 ;
}
int F_130 ( struct V_164 * V_176 )
{
V_176 -> V_177 = sizeof( struct V_5 ) ;
V_176 -> V_178 = F_106 ;
V_176 -> V_179 = V_180 ;
V_176 -> V_181 = V_182 ;
V_176 -> V_183 = F_124 ;
V_176 -> V_184 = F_125 ;
V_176 -> V_185 = F_127 ;
return F_131 ( V_176 ) ;
}
static int F_132 ( struct V_186 * V_187 ,
unsigned long V_188 , void * V_189 )
{
struct V_2 * V_3 = F_133 ( V_189 ) ;
struct V_5 * V_8 , * V_190 ;
struct V_1 * V_6 ;
F_134 ( V_191 ) ;
if ( ! F_114 ( V_3 ) )
return V_192 ;
V_6 = F_3 ( V_3 ) ;
switch ( V_188 ) {
case V_193 :
F_135 (vlan, &port->vlans, list)
F_118 ( V_8 -> V_67 ,
V_8 -> V_3 ) ;
break;
case V_194 :
F_135 (vlan, &port->vlans, list) {
V_8 -> V_3 -> V_107 = V_3 -> V_107 & V_108 ;
V_8 -> V_3 -> V_110 = V_3 -> V_110 ;
F_136 ( V_8 -> V_3 ) ;
}
break;
case V_195 :
if ( V_3 -> V_196 != V_197 )
break;
F_137 (vlan, next, &port->vlans, list)
V_8 -> V_3 -> V_164 -> V_198 ( V_8 -> V_3 , & V_191 ) ;
F_138 ( & V_191 ) ;
F_139 ( & V_191 ) ;
break;
case V_199 :
return V_200 ;
}
return V_192 ;
}
static int T_11 F_140 ( void )
{
int V_35 ;
F_141 ( & V_201 ) ;
V_35 = F_130 ( & V_202 ) ;
if ( V_35 < 0 )
goto V_203;
return 0 ;
V_203:
F_142 ( & V_201 ) ;
return V_35 ;
}
static void T_12 F_143 ( void )
{
F_144 ( & V_202 ) ;
F_142 ( & V_201 ) ;
}
