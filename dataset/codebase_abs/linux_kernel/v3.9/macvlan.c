static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const unsigned char * V_4 )
{
struct V_1 * V_5 ;
F_2 (vlan, &port->vlan_hash[addr[5]], hlist) {
if ( F_3 ( V_5 -> V_6 -> V_7 , V_4 ) )
return V_5 ;
}
return NULL ;
}
static void F_4 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
const unsigned char * V_4 = V_5 -> V_6 -> V_7 ;
F_5 ( & V_5 -> V_8 , & V_3 -> V_9 [ V_4 [ 5 ] ] ) ;
}
static void F_6 ( struct V_1 * V_5 , bool V_10 )
{
F_7 ( & V_5 -> V_8 ) ;
if ( V_10 )
F_8 () ;
}
static void F_9 ( struct V_1 * V_5 ,
const unsigned char * V_4 )
{
F_6 ( V_5 , true ) ;
memcpy ( V_5 -> V_6 -> V_7 , V_4 , V_11 ) ;
F_4 ( V_5 ) ;
}
static int F_10 ( const struct V_2 * V_3 ,
const unsigned char * V_4 )
{
if ( F_3 ( V_3 -> V_6 -> V_7 , V_4 ) )
return 1 ;
if ( F_1 ( V_3 , V_4 ) )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_12 * V_13 ,
const struct V_1 * V_5 ,
const struct V_14 * V_15 , bool V_16 )
{
struct V_17 * V_6 = V_5 -> V_6 ;
if ( ! V_13 )
return V_18 ;
if ( V_16 )
return V_5 -> V_19 ( V_6 , V_13 ) ;
V_13 -> V_6 = V_6 ;
if ( F_3 ( V_15 -> V_20 , V_6 -> V_21 ) )
V_13 -> V_22 = V_23 ;
else
V_13 -> V_22 = V_24 ;
return V_5 -> V_25 ( V_13 ) ;
}
static T_1 F_12 ( const struct V_1 * V_5 )
{
return ( T_1 ) ( ( ( unsigned long ) V_5 ) >> V_26 ) ;
}
static unsigned int F_13 ( const struct V_1 * V_5 ,
const unsigned char * V_4 )
{
T_1 V_27 = F_14 ( V_4 + 2 ) ;
V_27 ^= F_12 ( V_5 ) ;
return F_15 ( V_27 , V_28 ) ;
}
static void F_16 ( struct V_12 * V_13 ,
const struct V_2 * V_3 ,
struct V_17 * V_29 ,
enum V_30 V_31 )
{
const struct V_14 * V_15 = F_17 ( V_13 ) ;
const struct V_1 * V_5 ;
struct V_12 * V_32 ;
unsigned int V_33 ;
int V_34 ;
unsigned int V_35 ;
if ( V_13 -> V_36 == F_18 ( V_37 ) )
return;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 ++ ) {
F_2 (vlan, &port->vlan_hash[i], hlist) {
if ( V_5 -> V_6 == V_29 || ! ( V_5 -> V_31 & V_31 ) )
continue;
V_35 = F_13 ( V_5 , V_15 -> V_20 ) ;
if ( ! F_19 ( V_35 , V_5 -> V_39 ) )
continue;
V_32 = F_20 ( V_13 , V_40 ) ;
V_34 = F_11 ( V_32 , V_5 , V_15 ,
V_31 == V_41 ) ;
F_21 ( V_5 , V_13 -> V_42 + V_43 ,
V_34 == V_44 , 1 ) ;
}
}
}
static T_2 F_22 ( struct V_12 * * V_45 )
{
struct V_2 * V_3 ;
struct V_12 * V_13 = * V_45 ;
const struct V_14 * V_15 = F_17 ( V_13 ) ;
const struct V_1 * V_5 ;
const struct V_1 * V_29 ;
struct V_17 * V_6 ;
unsigned int V_42 = 0 ;
int V_46 = V_18 ;
V_3 = F_23 ( V_13 -> V_6 ) ;
if ( F_24 ( V_15 -> V_20 ) ) {
V_13 = F_25 ( V_13 , V_47 ) ;
if ( ! V_13 )
return V_48 ;
V_15 = F_17 ( V_13 ) ;
V_29 = F_1 ( V_3 , V_15 -> V_49 ) ;
if ( ! V_29 )
F_16 ( V_13 , V_3 , NULL ,
V_50 |
V_51 |
V_52 |
V_41 ) ;
else if ( V_29 -> V_31 == V_51 )
F_16 ( V_13 , V_3 , V_29 -> V_6 ,
V_51 |
V_41 ) ;
else if ( V_29 -> V_31 == V_41 )
F_16 ( V_13 , V_3 , V_29 -> V_6 ,
V_51 ) ;
else {
V_5 = V_29 ;
V_46 = F_11 ( V_13 , V_5 , V_15 , 0 ) ;
goto V_53;
}
return V_54 ;
}
if ( V_3 -> V_55 )
V_5 = F_26 ( & V_3 -> V_56 , struct V_1 , V_57 ) ;
else
V_5 = F_1 ( V_3 , V_15 -> V_20 ) ;
if ( V_5 == NULL )
return V_54 ;
V_6 = V_5 -> V_6 ;
if ( F_27 ( ! ( V_6 -> V_58 & V_59 ) ) ) {
F_28 ( V_13 ) ;
return V_48 ;
}
V_42 = V_13 -> V_42 + V_43 ;
V_13 = F_29 ( V_13 , V_40 ) ;
if ( ! V_13 )
goto V_53;
V_13 -> V_6 = V_6 ;
V_13 -> V_22 = V_60 ;
V_46 = V_5 -> V_25 ( V_13 ) ;
V_53:
F_21 ( V_5 , V_42 , V_46 == V_44 , 0 ) ;
return V_48 ;
}
static int F_30 ( struct V_12 * V_13 , struct V_17 * V_6 )
{
const struct V_1 * V_5 = F_31 ( V_6 ) ;
const struct V_2 * V_3 = V_5 -> V_3 ;
const struct V_1 * V_61 ;
T_3 V_62 = V_13 -> V_62 ;
if ( V_5 -> V_31 == V_41 ) {
const struct V_14 * V_15 = ( void * ) V_13 -> V_63 ;
V_13 -> V_62 = V_64 ;
if ( F_24 ( V_15 -> V_20 ) ) {
F_16 ( V_13 , V_3 , V_6 , V_41 ) ;
goto V_65;
}
V_61 = F_1 ( V_3 , V_15 -> V_20 ) ;
if ( V_61 && V_61 -> V_31 == V_41 ) {
F_32 ( V_5 -> V_66 , V_13 ) ;
return V_67 ;
}
}
V_65:
V_13 -> V_62 = V_62 ;
V_13 -> V_6 = V_5 -> V_66 ;
return F_33 ( V_13 ) ;
}
T_4 F_34 ( struct V_12 * V_13 ,
struct V_17 * V_6 )
{
unsigned int V_42 = V_13 -> V_42 ;
int V_46 ;
const struct V_1 * V_5 = F_31 ( V_6 ) ;
V_46 = F_30 ( V_13 , V_6 ) ;
if ( F_35 ( V_46 == V_67 || V_46 == V_68 ) ) {
struct V_69 * V_70 ;
V_70 = F_36 ( V_5 -> V_70 ) ;
F_37 ( & V_70 -> V_71 ) ;
V_70 -> V_72 ++ ;
V_70 -> V_73 += V_42 ;
F_38 ( & V_70 -> V_71 ) ;
} else {
F_39 ( V_5 -> V_70 -> V_74 ) ;
}
return V_46 ;
}
static int F_40 ( struct V_12 * V_13 , struct V_17 * V_6 ,
unsigned short type , const void * V_75 ,
const void * V_76 , unsigned V_42 )
{
const struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_17 * V_66 = V_5 -> V_66 ;
return F_41 ( V_13 , V_66 , type , V_75 ,
V_76 ? : V_6 -> V_7 , V_42 ) ;
}
static int F_42 ( struct V_17 * V_6 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_17 * V_66 = V_5 -> V_66 ;
int V_34 ;
if ( V_5 -> V_3 -> V_55 ) {
if ( ! ( V_5 -> V_58 & V_77 ) )
F_43 ( V_66 , 1 ) ;
goto V_78;
}
V_34 = - V_79 ;
if ( F_10 ( V_5 -> V_3 , V_6 -> V_7 ) )
goto V_53;
V_34 = F_44 ( V_66 , V_6 -> V_7 ) ;
if ( V_34 < 0 )
goto V_53;
if ( V_6 -> V_58 & V_80 ) {
V_34 = F_45 ( V_66 , 1 ) ;
if ( V_34 < 0 )
goto V_81;
}
V_78:
F_4 ( V_5 ) ;
return 0 ;
V_81:
F_46 ( V_66 , V_6 -> V_7 ) ;
V_53:
return V_34 ;
}
static int F_47 ( struct V_17 * V_6 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_17 * V_66 = V_5 -> V_66 ;
F_48 ( V_66 , V_6 ) ;
F_49 ( V_66 , V_6 ) ;
if ( V_5 -> V_3 -> V_55 ) {
if ( ! ( V_5 -> V_58 & V_77 ) )
F_43 ( V_66 , - 1 ) ;
goto V_82;
}
if ( V_6 -> V_58 & V_80 )
F_45 ( V_66 , - 1 ) ;
F_46 ( V_66 , V_6 -> V_7 ) ;
V_82:
F_6 ( V_5 , ! V_6 -> V_83 ) ;
return 0 ;
}
static int F_50 ( struct V_17 * V_6 , void * V_84 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_17 * V_66 = V_5 -> V_66 ;
struct V_85 * V_4 = V_84 ;
int V_34 ;
if ( ! F_51 ( V_4 -> V_86 ) )
return - V_87 ;
if ( ! ( V_6 -> V_58 & V_59 ) ) {
memcpy ( V_6 -> V_7 , V_4 -> V_86 , V_11 ) ;
} else {
if ( F_10 ( V_5 -> V_3 , V_4 -> V_86 ) )
return - V_79 ;
V_34 = F_44 ( V_66 , V_4 -> V_86 ) ;
if ( V_34 )
return V_34 ;
F_46 ( V_66 , V_6 -> V_7 ) ;
F_9 ( V_5 , V_4 -> V_86 ) ;
}
return 0 ;
}
static void F_52 ( struct V_17 * V_6 , int V_88 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_17 * V_66 = V_5 -> V_66 ;
if ( V_88 & V_80 )
F_45 ( V_66 , V_6 -> V_58 & V_80 ? 1 : - 1 ) ;
}
static void F_53 ( struct V_17 * V_6 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
if ( V_6 -> V_58 & ( V_89 | V_80 ) ) {
F_54 ( V_5 -> V_39 , V_90 ) ;
} else {
struct V_91 * V_92 ;
F_55 ( V_93 , V_90 ) ;
F_56 ( V_93 , V_90 ) ;
F_57 (ha, dev) {
F_58 ( F_13 ( V_5 , V_92 -> V_4 ) , V_93 ) ;
}
F_58 ( F_13 ( V_5 , V_6 -> V_21 ) , V_93 ) ;
F_59 ( V_5 -> V_39 , V_93 , V_90 ) ;
}
F_60 ( V_5 -> V_66 , V_6 ) ;
F_61 ( V_5 -> V_66 , V_6 ) ;
}
static int F_62 ( struct V_17 * V_6 , int V_94 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
if ( V_94 < 68 || V_5 -> V_66 -> V_95 < V_94 )
return - V_96 ;
V_6 -> V_95 = V_94 ;
return 0 ;
}
static void F_63 ( struct V_17 * V_6 ,
struct V_97 * V_98 ,
void * V_99 )
{
F_64 ( & V_98 -> V_100 ,
& V_101 ) ;
}
static void F_65 ( struct V_17 * V_6 )
{
F_64 ( & V_6 -> V_102 ,
& V_103 ) ;
F_66 ( V_6 , F_63 , NULL ) ;
}
static int F_67 ( struct V_17 * V_6 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
const struct V_17 * V_66 = V_5 -> V_66 ;
V_6 -> V_104 = ( V_6 -> V_104 & ~ V_105 ) |
( V_66 -> V_104 & V_105 ) ;
V_6 -> V_106 = V_66 -> V_106 & V_107 ;
V_6 -> V_106 |= V_108 ;
V_6 -> V_109 = V_66 -> V_109 ;
V_6 -> V_110 = V_66 -> V_111 ;
V_6 -> V_112 = V_66 -> V_112 ;
F_65 ( V_6 ) ;
V_5 -> V_70 = F_68 ( struct V_69 ) ;
if ( ! V_5 -> V_70 )
return - V_113 ;
return 0 ;
}
static void F_69 ( struct V_17 * V_6 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
F_70 ( V_5 -> V_70 ) ;
V_3 -> V_114 -= 1 ;
if ( ! V_3 -> V_114 )
F_71 ( V_3 -> V_6 ) ;
}
static struct V_115 * F_72 ( struct V_17 * V_6 ,
struct V_115 * V_116 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
if ( V_5 -> V_70 ) {
struct V_69 * V_84 ;
T_5 V_117 , V_118 , V_119 , V_72 , V_73 ;
T_1 V_120 = 0 , V_74 = 0 ;
unsigned int V_121 ;
int V_33 ;
F_73 (i) {
V_84 = F_74 ( V_5 -> V_70 , V_33 ) ;
do {
V_121 = F_75 ( & V_84 -> V_71 ) ;
V_117 = V_84 -> V_117 ;
V_118 = V_84 -> V_118 ;
V_119 = V_84 -> V_119 ;
V_72 = V_84 -> V_72 ;
V_73 = V_84 -> V_73 ;
} while ( F_76 ( & V_84 -> V_71 , V_121 ) );
V_116 -> V_117 += V_117 ;
V_116 -> V_118 += V_118 ;
V_116 -> V_122 += V_119 ;
V_116 -> V_72 += V_72 ;
V_116 -> V_73 += V_73 ;
V_120 += V_84 -> V_120 ;
V_74 += V_84 -> V_74 ;
}
V_116 -> V_120 = V_120 ;
V_116 -> V_123 = V_120 ;
V_116 -> V_74 = V_74 ;
}
return V_116 ;
}
static int F_77 ( struct V_17 * V_6 ,
unsigned short V_124 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_17 * V_66 = V_5 -> V_66 ;
return F_78 ( V_66 , V_124 ) ;
}
static int F_79 ( struct V_17 * V_6 ,
unsigned short V_124 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_17 * V_66 = V_5 -> V_66 ;
F_80 ( V_66 , V_124 ) ;
return 0 ;
}
static int F_81 ( struct V_125 * V_126 , struct V_127 * V_128 [] ,
struct V_17 * V_6 ,
const unsigned char * V_4 ,
T_6 V_58 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
int V_34 = - V_96 ;
if ( ! V_5 -> V_3 -> V_55 )
return - V_129 ;
if ( F_82 ( V_4 ) )
V_34 = F_83 ( V_6 , V_4 ) ;
else if ( F_24 ( V_4 ) )
V_34 = F_84 ( V_6 , V_4 ) ;
return V_34 ;
}
static int F_85 ( struct V_125 * V_126 , struct V_127 * V_128 [] ,
struct V_17 * V_6 ,
const unsigned char * V_4 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
int V_34 = - V_96 ;
if ( ! V_5 -> V_3 -> V_55 )
return - V_129 ;
if ( F_82 ( V_4 ) )
V_34 = F_46 ( V_6 , V_4 ) ;
else if ( F_24 ( V_4 ) )
V_34 = F_86 ( V_6 , V_4 ) ;
return V_34 ;
}
static void F_87 ( struct V_17 * V_6 ,
struct V_130 * V_131 )
{
F_88 ( V_131 -> V_132 , L_1 , sizeof( V_131 -> V_132 ) ) ;
F_88 ( V_131 -> V_133 , L_2 , sizeof( V_131 -> V_133 ) ) ;
}
static int F_89 ( struct V_17 * V_6 ,
struct V_134 * V_135 )
{
const struct V_1 * V_5 = F_31 ( V_6 ) ;
return F_90 ( V_5 -> V_66 , V_135 ) ;
}
void F_91 ( struct V_17 * V_6 )
{
F_92 ( V_6 ) ;
V_6 -> V_136 &= ~ ( V_137 | V_138 ) ;
V_6 -> V_136 |= V_139 ;
V_6 -> V_140 = & V_141 ;
V_6 -> V_142 = V_143 ;
V_6 -> V_144 = & V_145 ,
V_6 -> V_146 = & V_147 ;
}
static void F_93 ( struct V_17 * V_6 )
{
F_91 ( V_6 ) ;
V_6 -> V_148 = 0 ;
}
static int F_94 ( struct V_17 * V_6 )
{
struct V_2 * V_3 ;
unsigned int V_33 ;
int V_34 ;
if ( V_6 -> type != V_149 || V_6 -> V_58 & V_150 )
return - V_96 ;
V_3 = F_95 ( sizeof( * V_3 ) , V_151 ) ;
if ( V_3 == NULL )
return - V_113 ;
V_3 -> V_55 = false ;
V_3 -> V_6 = V_6 ;
F_96 ( & V_3 -> V_56 ) ;
for ( V_33 = 0 ; V_33 < V_38 ; V_33 ++ )
F_97 ( & V_3 -> V_9 [ V_33 ] ) ;
V_34 = F_98 ( V_6 , F_22 , V_3 ) ;
if ( V_34 )
F_99 ( V_3 ) ;
else
V_6 -> V_136 |= V_152 ;
return V_34 ;
}
static void F_71 ( struct V_17 * V_6 )
{
struct V_2 * V_3 = F_100 ( V_6 ) ;
V_6 -> V_136 &= ~ V_152 ;
F_101 ( V_6 ) ;
F_102 ( V_3 , V_153 ) ;
}
static int F_103 ( struct V_127 * V_128 [] , struct V_127 * V_63 [] )
{
if ( V_128 [ V_154 ] ) {
if ( F_104 ( V_128 [ V_154 ] ) != V_11 )
return - V_96 ;
if ( ! F_51 ( F_105 ( V_128 [ V_154 ] ) ) )
return - V_87 ;
}
if ( V_63 && V_63 [ V_155 ] ) {
switch ( F_106 ( V_63 [ V_155 ] ) ) {
case V_50 :
case V_51 :
case V_41 :
case V_52 :
break;
default:
return - V_96 ;
}
}
return 0 ;
}
int F_107 ( struct V_156 * V_157 , struct V_17 * V_6 ,
struct V_127 * V_128 [] , struct V_127 * V_63 [] ,
int (* V_25)( struct V_12 * V_13 ) ,
int (* V_19)( struct V_17 * V_6 ,
struct V_12 * V_13 ) )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
struct V_2 * V_3 ;
struct V_17 * V_66 ;
int V_34 ;
if ( ! V_128 [ V_158 ] )
return - V_96 ;
V_66 = F_108 ( V_157 , F_106 ( V_128 [ V_158 ] ) ) ;
if ( V_66 == NULL )
return - V_159 ;
if ( V_66 -> V_160 == V_6 -> V_160 ) {
struct V_1 * V_161 = F_31 ( V_66 ) ;
V_66 = V_161 -> V_66 ;
}
if ( ! V_128 [ V_162 ] )
V_6 -> V_95 = V_66 -> V_95 ;
else if ( V_6 -> V_95 > V_66 -> V_95 )
return - V_96 ;
if ( ! V_128 [ V_154 ] )
F_109 ( V_6 ) ;
if ( ! F_110 ( V_66 ) ) {
V_34 = F_94 ( V_66 ) ;
if ( V_34 < 0 )
return V_34 ;
}
V_3 = F_100 ( V_66 ) ;
if ( V_3 -> V_55 )
return - V_96 ;
V_5 -> V_66 = V_66 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_19 = V_19 ;
V_5 -> V_31 = V_51 ;
if ( V_63 && V_63 [ V_155 ] )
V_5 -> V_31 = F_106 ( V_63 [ V_155 ] ) ;
if ( V_63 && V_63 [ V_163 ] )
V_5 -> V_58 = F_111 ( V_63 [ V_163 ] ) ;
if ( V_5 -> V_31 == V_52 ) {
if ( V_3 -> V_114 )
return - V_96 ;
V_3 -> V_55 = true ;
memcpy ( V_6 -> V_7 , V_66 -> V_7 , V_11 ) ;
}
V_34 = F_112 ( V_66 , V_6 ) ;
if ( V_34 )
goto V_164;
V_3 -> V_114 += 1 ;
V_34 = F_113 ( V_6 ) ;
if ( V_34 < 0 )
goto V_165;
F_114 ( & V_5 -> V_57 , & V_3 -> V_56 ) ;
F_115 ( V_66 , V_6 ) ;
return 0 ;
V_165:
F_116 ( V_66 , V_6 ) ;
V_164:
V_3 -> V_114 -= 1 ;
if ( ! V_3 -> V_114 )
F_71 ( V_66 ) ;
return V_34 ;
}
static int F_117 ( struct V_156 * V_157 , struct V_17 * V_6 ,
struct V_127 * V_128 [] , struct V_127 * V_63 [] )
{
return F_107 ( V_157 , V_6 , V_128 , V_63 ,
V_166 ,
F_32 ) ;
}
void F_118 ( struct V_17 * V_6 , struct V_167 * V_168 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
F_119 ( & V_5 -> V_57 ) ;
F_120 ( V_6 , V_168 ) ;
F_116 ( V_5 -> V_66 , V_6 ) ;
}
static int F_121 ( struct V_17 * V_6 ,
struct V_127 * V_128 [] , struct V_127 * V_63 [] )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
if ( V_63 && V_63 [ V_155 ] )
V_5 -> V_31 = F_106 ( V_63 [ V_155 ] ) ;
if ( V_63 && V_63 [ V_163 ] ) {
T_7 V_58 = F_111 ( V_63 [ V_163 ] ) ;
bool V_169 = ( V_58 ^ V_5 -> V_58 ) & V_77 ;
if ( V_169 && ( V_58 & V_77 ) )
F_43 ( V_5 -> V_66 , - 1 ) ;
else if ( V_169 && ! ( V_58 & V_77 ) )
F_43 ( V_5 -> V_66 , 1 ) ;
V_5 -> V_58 = V_58 ;
}
return 0 ;
}
static T_8 F_122 ( const struct V_17 * V_6 )
{
return ( 0
+ F_123 ( 4 )
+ F_123 ( 2 )
) ;
}
static int F_124 ( struct V_12 * V_13 ,
const struct V_17 * V_6 )
{
struct V_1 * V_5 = F_31 ( V_6 ) ;
if ( F_125 ( V_13 , V_155 , V_5 -> V_31 ) )
goto V_170;
if ( F_126 ( V_13 , V_163 , V_5 -> V_58 ) )
goto V_170;
return 0 ;
V_170:
return - V_171 ;
}
int F_127 ( struct V_160 * V_172 )
{
V_172 -> V_173 = sizeof( struct V_1 ) ;
V_172 -> V_174 = F_103 ;
V_172 -> V_175 = V_176 ;
V_172 -> V_177 = V_178 ;
V_172 -> V_179 = F_121 ;
V_172 -> V_180 = F_122 ;
V_172 -> V_181 = F_124 ;
return F_128 ( V_172 ) ;
}
static int F_129 ( struct V_182 * V_183 ,
unsigned long V_184 , void * V_185 )
{
struct V_17 * V_6 = V_185 ;
struct V_1 * V_5 , * V_186 ;
struct V_2 * V_3 ;
F_130 ( V_187 ) ;
if ( ! F_110 ( V_6 ) )
return V_188 ;
V_3 = F_100 ( V_6 ) ;
switch ( V_184 ) {
case V_189 :
F_131 (vlan, &port->vlans, list)
F_115 ( V_5 -> V_66 ,
V_5 -> V_6 ) ;
break;
case V_190 :
F_131 (vlan, &port->vlans, list) {
V_5 -> V_6 -> V_106 = V_6 -> V_106 & V_107 ;
V_5 -> V_6 -> V_109 = V_6 -> V_109 ;
F_132 ( V_5 -> V_6 ) ;
}
break;
case V_191 :
if ( V_6 -> V_192 != V_193 )
break;
F_133 (vlan, next, &port->vlans, list)
V_5 -> V_6 -> V_160 -> V_194 ( V_5 -> V_6 , & V_187 ) ;
F_134 ( & V_187 ) ;
F_119 ( & V_187 ) ;
break;
case V_195 :
return V_196 ;
}
return V_188 ;
}
static int T_9 F_135 ( void )
{
int V_34 ;
F_136 ( & V_197 ) ;
V_34 = F_127 ( & V_198 ) ;
if ( V_34 < 0 )
goto V_199;
return 0 ;
V_199:
F_137 ( & V_197 ) ;
return V_34 ;
}
static void T_10 F_138 ( void )
{
F_139 ( & V_198 ) ;
F_137 ( & V_197 ) ;
}
