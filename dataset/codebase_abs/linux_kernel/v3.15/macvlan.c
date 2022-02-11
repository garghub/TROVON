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
return F_17 ( V_15 ) ;
}
static T_1 F_18 ( const struct V_5 * V_8 )
{
return ( T_1 ) ( ( ( unsigned long ) V_8 ) >> V_24 ) ;
}
static unsigned int F_19 ( const struct V_5 * V_8 ,
const unsigned char * V_7 )
{
T_1 V_25 = F_20 ( V_7 + 2 ) ;
V_25 ^= F_18 ( V_8 ) ;
return F_21 ( V_25 , V_26 ) ;
}
static void F_22 ( struct V_14 * V_15 ,
const struct V_1 * V_6 ,
struct V_2 * V_27 ,
enum V_28 V_29 )
{
const struct V_16 * V_17 = F_23 ( V_15 ) ;
const struct V_5 * V_8 ;
struct V_14 * V_30 ;
unsigned int V_31 ;
int V_32 ;
unsigned int V_33 ;
if ( V_15 -> V_34 == F_24 ( V_35 ) )
return;
for ( V_31 = 0 ; V_31 < V_36 ; V_31 ++ ) {
F_6 (vlan, &port->vlan_hash[i], hlist) {
if ( V_8 -> V_3 == V_27 || ! ( V_8 -> V_29 & V_29 ) )
continue;
V_33 = F_19 ( V_8 , V_17 -> V_19 ) ;
if ( ! F_25 ( V_33 , V_8 -> V_37 ) )
continue;
V_32 = V_38 ;
V_30 = F_26 ( V_15 , V_39 ) ;
if ( F_27 ( V_30 ) )
V_32 = F_15 (
V_30 , V_8 , V_17 ,
V_29 == V_40 ) ;
F_28 ( V_8 , V_15 -> V_41 + V_42 ,
V_32 == V_43 , 1 ) ;
}
}
}
static T_2 F_29 ( struct V_14 * * V_44 )
{
struct V_1 * V_6 ;
struct V_14 * V_15 = * V_44 ;
const struct V_16 * V_17 = F_23 ( V_15 ) ;
const struct V_5 * V_8 ;
const struct V_5 * V_27 ;
struct V_2 * V_3 ;
unsigned int V_41 = 0 ;
int V_45 = V_38 ;
V_6 = F_1 ( V_15 -> V_3 ) ;
if ( F_30 ( V_17 -> V_19 ) ) {
V_15 = F_31 ( V_15 , V_46 ) ;
if ( ! V_15 )
return V_47 ;
V_17 = F_23 ( V_15 ) ;
V_27 = F_5 ( V_6 , V_17 -> V_48 ) ;
if ( ! V_27 )
F_22 ( V_15 , V_6 , NULL ,
V_49 |
V_50 |
V_51 |
V_40 ) ;
else if ( V_27 -> V_29 == V_50 )
F_22 ( V_15 , V_6 , V_27 -> V_3 ,
V_50 |
V_40 ) ;
else if ( V_27 -> V_29 == V_40 )
F_22 ( V_15 , V_6 , V_27 -> V_3 ,
V_50 ) ;
else {
V_8 = V_27 ;
V_45 = F_15 ( V_15 , V_8 , V_17 , 0 ) ;
goto V_52;
}
return V_53 ;
}
if ( V_6 -> V_54 )
V_8 = F_32 ( & V_6 -> V_55 ,
struct V_5 , V_56 ) ;
else
V_8 = F_5 ( V_6 , V_17 -> V_19 ) ;
if ( V_8 == NULL )
return V_53 ;
V_3 = V_8 -> V_3 ;
if ( F_33 ( ! ( V_3 -> V_57 & V_58 ) ) ) {
F_34 ( V_15 ) ;
return V_47 ;
}
V_41 = V_15 -> V_41 + V_42 ;
V_15 = F_35 ( V_15 , V_39 ) ;
if ( ! V_15 )
goto V_52;
V_15 -> V_3 = V_3 ;
V_15 -> V_21 = V_59 ;
V_45 = F_17 ( V_15 ) ;
V_52:
F_28 ( V_8 , V_41 , V_45 == V_43 , 0 ) ;
return V_47 ;
}
static int F_36 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
const struct V_5 * V_8 = F_37 ( V_3 ) ;
const struct V_1 * V_6 = V_8 -> V_6 ;
const struct V_5 * V_60 ;
if ( V_8 -> V_29 == V_40 ) {
const struct V_16 * V_17 = ( void * ) V_15 -> V_61 ;
if ( F_30 ( V_17 -> V_19 ) ) {
F_22 ( V_15 , V_6 , V_3 , V_40 ) ;
goto V_62;
}
V_60 = F_5 ( V_6 , V_17 -> V_19 ) ;
if ( V_60 && V_60 -> V_29 == V_40 ) {
F_16 ( V_8 -> V_63 , V_15 ) ;
return V_64 ;
}
}
V_62:
V_15 -> V_3 = V_8 -> V_63 ;
return F_38 ( V_15 ) ;
}
static T_3 F_39 ( struct V_14 * V_15 ,
struct V_2 * V_3 )
{
unsigned int V_41 = V_15 -> V_41 ;
int V_45 ;
const struct V_5 * V_8 = F_37 ( V_3 ) ;
if ( V_8 -> V_65 ) {
V_15 -> V_3 = V_8 -> V_63 ;
V_45 = F_40 ( V_15 , V_8 -> V_65 ) ;
} else {
V_45 = F_36 ( V_15 , V_3 ) ;
}
if ( F_27 ( V_45 == V_64 || V_45 == V_66 ) ) {
struct V_67 * V_68 ;
V_68 = F_41 ( V_8 -> V_68 ) ;
F_42 ( & V_68 -> V_69 ) ;
V_68 -> V_70 ++ ;
V_68 -> V_71 += V_41 ;
F_43 ( & V_68 -> V_69 ) ;
} else {
F_44 ( V_8 -> V_68 -> V_72 ) ;
}
return V_45 ;
}
static int F_45 ( struct V_14 * V_15 , struct V_2 * V_3 ,
unsigned short type , const void * V_73 ,
const void * V_74 , unsigned V_41 )
{
const struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_2 * V_63 = V_8 -> V_63 ;
return F_46 ( V_15 , V_63 , type , V_73 ,
V_74 ? : V_3 -> V_9 , V_41 ) ;
}
static int F_47 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_2 * V_63 = V_8 -> V_63 ;
int V_32 ;
if ( V_8 -> V_6 -> V_54 ) {
if ( ! ( V_8 -> V_57 & V_75 ) ) {
V_32 = F_48 ( V_63 , 1 ) ;
if ( V_32 < 0 )
goto V_52;
}
goto V_76;
}
if ( V_63 -> V_77 & V_78 &&
V_3 -> V_79 == & V_80 ) {
V_8 -> V_65 =
V_63 -> V_81 -> V_82 ( V_63 , V_3 ) ;
if ( F_49 ( V_8 -> V_65 ) ) {
V_8 -> V_65 = NULL ;
} else
return 0 ;
}
V_32 = - V_83 ;
if ( F_14 ( V_8 -> V_6 , V_3 -> V_9 ) )
goto V_52;
V_32 = F_50 ( V_63 , V_3 -> V_9 ) ;
if ( V_32 < 0 )
goto V_52;
if ( V_3 -> V_57 & V_84 ) {
V_32 = F_51 ( V_63 , 1 ) ;
if ( V_32 < 0 )
goto V_85;
}
V_76:
F_8 ( V_8 ) ;
return 0 ;
V_85:
F_52 ( V_63 , V_3 -> V_9 ) ;
V_52:
if ( V_8 -> V_65 ) {
V_63 -> V_81 -> V_86 ( V_63 ,
V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
}
return V_32 ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_2 * V_63 = V_8 -> V_63 ;
if ( V_8 -> V_65 ) {
V_63 -> V_81 -> V_86 ( V_63 ,
V_8 -> V_65 ) ;
V_8 -> V_65 = NULL ;
return 0 ;
}
F_54 ( V_63 , V_3 ) ;
F_55 ( V_63 , V_3 ) ;
if ( V_8 -> V_6 -> V_54 ) {
if ( ! ( V_8 -> V_57 & V_75 ) )
F_48 ( V_63 , - 1 ) ;
goto V_87;
}
if ( V_3 -> V_57 & V_84 )
F_51 ( V_63 , - 1 ) ;
F_52 ( V_63 , V_3 -> V_9 ) ;
V_87:
F_10 ( V_8 , ! V_3 -> V_88 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , void * V_89 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_2 * V_63 = V_8 -> V_63 ;
struct V_90 * V_7 = V_89 ;
int V_32 ;
if ( ! F_57 ( V_7 -> V_91 ) )
return - V_92 ;
if ( ! ( V_3 -> V_57 & V_58 ) ) {
memcpy ( V_3 -> V_9 , V_7 -> V_91 , V_13 ) ;
} else {
if ( F_14 ( V_8 -> V_6 , V_7 -> V_91 ) )
return - V_83 ;
V_32 = F_50 ( V_63 , V_7 -> V_91 ) ;
if ( V_32 )
return V_32 ;
F_52 ( V_63 , V_3 -> V_9 ) ;
F_13 ( V_8 , V_7 -> V_91 ) ;
}
return 0 ;
}
static void F_58 ( struct V_2 * V_3 , int V_93 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_2 * V_63 = V_8 -> V_63 ;
if ( V_3 -> V_57 & V_58 ) {
if ( V_93 & V_84 )
F_51 ( V_63 , V_3 -> V_57 & V_84 ? 1 : - 1 ) ;
}
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
if ( V_3 -> V_57 & ( V_94 | V_84 ) ) {
F_60 ( V_8 -> V_37 , V_95 ) ;
} else {
struct V_96 * V_97 ;
F_61 ( V_98 , V_95 ) ;
F_62 ( V_98 , V_95 ) ;
F_63 (ha, dev) {
F_64 ( F_19 ( V_8 , V_97 -> V_7 ) , V_98 ) ;
}
F_64 ( F_19 ( V_8 , V_3 -> V_20 ) , V_98 ) ;
F_65 ( V_8 -> V_37 , V_98 , V_95 ) ;
}
F_66 ( V_8 -> V_63 , V_3 ) ;
F_67 ( V_8 -> V_63 , V_3 ) ;
}
static int F_68 ( struct V_2 * V_3 , int V_99 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
if ( V_99 < 68 || V_8 -> V_63 -> V_100 < V_99 )
return - V_101 ;
V_3 -> V_100 = V_99 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
return ( (struct V_5 * ) F_37 ( V_3 ) ) -> V_102 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_103 * V_104 ,
void * V_105 )
{
F_71 ( & V_104 -> V_106 ,
& V_107 ) ;
}
static void F_72 ( struct V_2 * V_3 )
{
F_73 ( & V_3 -> V_108 ,
& V_109 ,
F_69 ( V_3 ) ) ;
F_74 ( V_3 , F_70 , NULL ) ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
const struct V_2 * V_63 = V_8 -> V_63 ;
V_3 -> V_110 = ( V_3 -> V_110 & ~ V_111 ) |
( V_63 -> V_110 & V_111 ) ;
V_3 -> V_77 = V_63 -> V_77 & V_112 ;
V_3 -> V_77 |= V_113 ;
V_3 -> V_114 = V_63 -> V_114 ;
V_3 -> V_115 = V_63 -> V_116 ;
V_3 -> V_117 = V_63 -> V_117 ;
F_72 ( V_3 ) ;
V_8 -> V_68 = F_76 ( struct V_67 ) ;
if ( ! V_8 -> V_68 )
return - V_118 ;
return 0 ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_1 * V_6 = V_8 -> V_6 ;
F_78 ( V_8 -> V_68 ) ;
V_6 -> V_119 -= 1 ;
if ( ! V_6 -> V_119 )
F_79 ( V_6 -> V_3 ) ;
}
static struct V_120 * F_80 ( struct V_2 * V_3 ,
struct V_120 * V_121 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
if ( V_8 -> V_68 ) {
struct V_67 * V_89 ;
T_4 V_122 , V_123 , V_124 , V_70 , V_71 ;
T_1 V_125 = 0 , V_72 = 0 ;
unsigned int V_126 ;
int V_31 ;
F_81 (i) {
V_89 = F_82 ( V_8 -> V_68 , V_31 ) ;
do {
V_126 = F_83 ( & V_89 -> V_69 ) ;
V_122 = V_89 -> V_122 ;
V_123 = V_89 -> V_123 ;
V_124 = V_89 -> V_124 ;
V_70 = V_89 -> V_70 ;
V_71 = V_89 -> V_71 ;
} while ( F_84 ( & V_89 -> V_69 , V_126 ) );
V_121 -> V_122 += V_122 ;
V_121 -> V_123 += V_123 ;
V_121 -> V_127 += V_124 ;
V_121 -> V_70 += V_70 ;
V_121 -> V_71 += V_71 ;
V_125 += V_89 -> V_125 ;
V_72 += V_89 -> V_72 ;
}
V_121 -> V_125 = V_125 ;
V_121 -> V_128 = V_125 ;
V_121 -> V_72 = V_72 ;
}
return V_121 ;
}
static int F_85 ( struct V_2 * V_3 ,
T_5 V_129 , T_6 V_130 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_2 * V_63 = V_8 -> V_63 ;
return F_86 ( V_63 , V_129 , V_130 ) ;
}
static int F_87 ( struct V_2 * V_3 ,
T_5 V_129 , T_6 V_130 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_2 * V_63 = V_8 -> V_63 ;
F_88 ( V_63 , V_129 , V_130 ) ;
return 0 ;
}
static int F_89 ( struct V_131 * V_132 , struct V_133 * V_134 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 ,
T_6 V_57 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
int V_32 = - V_101 ;
if ( ! V_8 -> V_6 -> V_54 )
return - V_135 ;
if ( V_57 & V_136 )
return - V_135 ;
if ( F_90 ( V_7 ) )
V_32 = F_91 ( V_3 , V_7 ) ;
else if ( F_30 ( V_7 ) )
V_32 = F_92 ( V_3 , V_7 ) ;
return V_32 ;
}
static int F_93 ( struct V_131 * V_132 , struct V_133 * V_134 [] ,
struct V_2 * V_3 ,
const unsigned char * V_7 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
int V_32 = - V_101 ;
if ( ! V_8 -> V_6 -> V_54 )
return - V_135 ;
if ( F_90 ( V_7 ) )
V_32 = F_52 ( V_3 , V_7 ) ;
else if ( F_30 ( V_7 ) )
V_32 = F_94 ( V_3 , V_7 ) ;
return V_32 ;
}
static void F_95 ( struct V_2 * V_3 ,
struct V_137 * V_138 )
{
F_96 ( V_138 -> V_139 , L_1 , sizeof( V_138 -> V_139 ) ) ;
F_96 ( V_138 -> V_140 , L_2 , sizeof( V_138 -> V_140 ) ) ;
}
static int F_97 ( struct V_2 * V_3 ,
struct V_141 * V_142 )
{
const struct V_5 * V_8 = F_37 ( V_3 ) ;
return F_98 ( V_8 -> V_63 , V_142 ) ;
}
static T_7 F_99 ( struct V_2 * V_3 ,
T_7 V_77 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
T_7 V_143 ;
V_77 |= V_144 ;
V_77 &= ( V_8 -> V_145 | ~ V_112 ) ;
V_143 = V_77 ;
V_77 = F_100 ( V_8 -> V_63 -> V_77 ,
V_77 ,
V_143 ) ;
V_77 |= V_113 ;
return V_77 ;
}
void F_101 ( struct V_2 * V_3 )
{
F_102 ( V_3 ) ;
V_3 -> V_146 &= ~ ( V_147 | V_148 ) ;
V_3 -> V_146 |= V_149 ;
V_3 -> V_81 = & V_150 ;
V_3 -> V_151 = V_152 ;
V_3 -> V_153 = & V_154 ;
V_3 -> V_155 = & V_156 ;
}
static void F_103 ( struct V_2 * V_3 )
{
F_101 ( V_3 ) ;
V_3 -> V_157 = 0 ;
}
static int F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_6 ;
unsigned int V_31 ;
int V_32 ;
if ( V_3 -> type != V_158 || V_3 -> V_57 & V_159 )
return - V_101 ;
V_6 = F_105 ( sizeof( * V_6 ) , V_160 ) ;
if ( V_6 == NULL )
return - V_118 ;
V_6 -> V_54 = false ;
V_6 -> V_3 = V_3 ;
F_106 ( & V_6 -> V_55 ) ;
for ( V_31 = 0 ; V_31 < V_36 ; V_31 ++ )
F_107 ( & V_6 -> V_11 [ V_31 ] ) ;
V_32 = F_108 ( V_3 , F_29 , V_6 ) ;
if ( V_32 )
F_109 ( V_6 ) ;
else
V_3 -> V_146 |= V_161 ;
return V_32 ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_3 ( V_3 ) ;
V_3 -> V_146 &= ~ V_161 ;
F_110 ( V_3 ) ;
F_111 ( V_6 , V_162 ) ;
}
static int F_112 ( struct V_133 * V_134 [] , struct V_133 * V_61 [] )
{
if ( V_134 [ V_163 ] ) {
if ( F_113 ( V_134 [ V_163 ] ) != V_13 )
return - V_101 ;
if ( ! F_57 ( F_114 ( V_134 [ V_163 ] ) ) )
return - V_92 ;
}
if ( V_61 && V_61 [ V_164 ] &&
F_115 ( V_61 [ V_164 ] ) & ~ V_75 )
return - V_101 ;
if ( V_61 && V_61 [ V_165 ] ) {
switch ( F_116 ( V_61 [ V_165 ] ) ) {
case V_49 :
case V_50 :
case V_40 :
case V_51 :
break;
default:
return - V_101 ;
}
}
return 0 ;
}
int F_117 ( struct V_166 * V_167 , struct V_2 * V_3 ,
struct V_133 * V_134 [] , struct V_133 * V_61 [] )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
struct V_1 * V_6 ;
struct V_2 * V_63 ;
int V_32 ;
if ( ! V_134 [ V_168 ] )
return - V_101 ;
V_63 = F_118 ( V_167 , F_116 ( V_134 [ V_168 ] ) ) ;
if ( V_63 == NULL )
return - V_169 ;
if ( F_119 ( V_63 ) )
V_63 = F_120 ( V_63 ) ;
if ( ! V_134 [ V_170 ] )
V_3 -> V_100 = V_63 -> V_100 ;
else if ( V_3 -> V_100 > V_63 -> V_100 )
return - V_101 ;
if ( ! V_134 [ V_163 ] )
F_121 ( V_3 ) ;
if ( ! F_122 ( V_63 ) ) {
V_32 = F_104 ( V_63 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_6 = F_3 ( V_63 ) ;
if ( V_6 -> V_54 )
return - V_101 ;
V_8 -> V_63 = V_63 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_145 = V_112 ;
V_8 -> V_102 = F_123 ( V_63 , F_119 ) + 1 ;
V_8 -> V_29 = V_50 ;
if ( V_61 && V_61 [ V_165 ] )
V_8 -> V_29 = F_116 ( V_61 [ V_165 ] ) ;
if ( V_61 && V_61 [ V_164 ] )
V_8 -> V_57 = F_115 ( V_61 [ V_164 ] ) ;
if ( V_8 -> V_29 == V_51 ) {
if ( V_6 -> V_119 )
return - V_101 ;
V_6 -> V_54 = true ;
F_124 ( V_3 , V_63 ) ;
}
V_6 -> V_119 += 1 ;
V_32 = F_125 ( V_3 ) ;
if ( V_32 < 0 )
goto V_171;
V_3 -> V_146 |= V_172 ;
V_32 = F_126 ( V_63 , V_3 ) ;
if ( V_32 )
goto V_173;
F_127 ( & V_8 -> V_56 , & V_6 -> V_55 ) ;
F_128 ( V_63 , V_3 ) ;
return 0 ;
V_173:
F_129 ( V_3 ) ;
V_171:
V_6 -> V_119 -= 1 ;
if ( ! V_6 -> V_119 )
F_79 ( V_63 ) ;
return V_32 ;
}
static int F_130 ( struct V_166 * V_167 , struct V_2 * V_3 ,
struct V_133 * V_134 [] , struct V_133 * V_61 [] )
{
return F_117 ( V_167 , V_3 , V_134 , V_61 ) ;
}
void F_131 ( struct V_2 * V_3 , struct V_174 * V_175 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
F_132 ( & V_8 -> V_56 ) ;
F_133 ( V_3 , V_175 ) ;
F_134 ( V_8 -> V_63 , V_3 ) ;
}
static int F_135 ( struct V_2 * V_3 ,
struct V_133 * V_134 [] , struct V_133 * V_61 [] )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
enum V_28 V_29 ;
bool V_176 = false ;
if ( V_61 && V_61 [ V_165 ] ) {
V_176 = true ;
V_29 = F_116 ( V_61 [ V_165 ] ) ;
if ( ( V_29 == V_51 ) !=
( V_8 -> V_29 == V_51 ) )
return - V_101 ;
}
if ( V_61 && V_61 [ V_164 ] ) {
T_8 V_57 = F_115 ( V_61 [ V_164 ] ) ;
bool V_177 = ( V_57 ^ V_8 -> V_57 ) & V_75 ;
if ( V_8 -> V_6 -> V_54 && V_177 ) {
int V_32 ;
if ( V_57 & V_75 )
V_32 = F_48 ( V_8 -> V_63 , - 1 ) ;
else
V_32 = F_48 ( V_8 -> V_63 , 1 ) ;
if ( V_32 < 0 )
return V_32 ;
}
V_8 -> V_57 = V_57 ;
}
if ( V_176 )
V_8 -> V_29 = V_29 ;
return 0 ;
}
static T_9 F_136 ( const struct V_2 * V_3 )
{
return ( 0
+ F_137 ( 4 )
+ F_137 ( 2 )
) ;
}
static int F_138 ( struct V_14 * V_15 ,
const struct V_2 * V_3 )
{
struct V_5 * V_8 = F_37 ( V_3 ) ;
if ( F_139 ( V_15 , V_165 , V_8 -> V_29 ) )
goto V_178;
if ( F_140 ( V_15 , V_164 , V_8 -> V_57 ) )
goto V_178;
return 0 ;
V_178:
return - V_179 ;
}
int F_141 ( struct V_79 * V_180 )
{
V_180 -> V_181 = sizeof( struct V_5 ) ;
V_180 -> V_182 = F_112 ;
V_180 -> V_183 = V_184 ;
V_180 -> V_185 = V_186 ;
V_180 -> V_187 = F_135 ;
V_180 -> V_188 = F_136 ;
V_180 -> V_189 = F_138 ;
return F_142 ( V_180 ) ;
}
static int F_143 ( struct V_190 * V_191 ,
unsigned long V_192 , void * V_193 )
{
struct V_2 * V_3 = F_144 ( V_193 ) ;
struct V_5 * V_8 , * V_194 ;
struct V_1 * V_6 ;
F_145 ( V_195 ) ;
if ( ! F_122 ( V_3 ) )
return V_196 ;
V_6 = F_3 ( V_3 ) ;
switch ( V_192 ) {
case V_197 :
F_146 (vlan, &port->vlans, list)
F_128 ( V_8 -> V_63 ,
V_8 -> V_3 ) ;
break;
case V_198 :
F_146 (vlan, &port->vlans, list) {
V_8 -> V_3 -> V_114 = V_3 -> V_114 ;
F_147 ( V_8 -> V_3 ) ;
}
break;
case V_199 :
if ( V_3 -> V_200 != V_201 )
break;
F_148 (vlan, next, &port->vlans, list)
V_8 -> V_3 -> V_79 -> V_202 ( V_8 -> V_3 , & V_195 ) ;
F_149 ( & V_195 ) ;
F_150 ( & V_195 ) ;
break;
case V_203 :
return V_204 ;
}
return V_196 ;
}
static int T_10 F_151 ( void )
{
int V_32 ;
F_152 ( & V_205 ) ;
V_32 = F_141 ( & V_80 ) ;
if ( V_32 < 0 )
goto V_206;
return 0 ;
V_206:
F_153 ( & V_205 ) ;
return V_32 ;
}
static void T_11 F_154 ( void )
{
F_155 ( & V_80 ) ;
F_153 ( & V_205 ) ;
}
