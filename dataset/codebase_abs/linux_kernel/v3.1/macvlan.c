static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const unsigned char * V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
F_2 (vlan, n, &port->vlan_hash[addr[5]], hlist) {
if ( ! F_3 ( V_5 -> V_8 -> V_9 , V_4 ) )
return V_5 ;
}
return NULL ;
}
static void F_4 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
const unsigned char * V_4 = V_5 -> V_8 -> V_9 ;
F_5 ( & V_5 -> V_10 , & V_3 -> V_11 [ V_4 [ 5 ] ] ) ;
}
static void F_6 ( struct V_1 * V_5 , bool V_12 )
{
F_7 ( & V_5 -> V_10 ) ;
if ( V_12 )
F_8 () ;
}
static void F_9 ( struct V_1 * V_5 ,
const unsigned char * V_4 )
{
F_6 ( V_5 , true ) ;
memcpy ( V_5 -> V_8 -> V_9 , V_4 , V_13 ) ;
F_4 ( V_5 ) ;
}
static int F_10 ( const struct V_2 * V_3 ,
const unsigned char * V_4 )
{
if ( ! F_3 ( V_3 -> V_8 -> V_9 , V_4 ) )
return 1 ;
if ( F_1 ( V_3 , V_4 ) )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
const struct V_1 * V_5 ,
const struct V_16 * V_17 , bool V_18 )
{
struct V_19 * V_8 = V_5 -> V_8 ;
if ( ! V_15 )
return V_20 ;
if ( V_18 )
return V_5 -> V_21 ( V_8 , V_15 ) ;
V_15 -> V_8 = V_8 ;
if ( ! F_3 ( V_17 -> V_22 ,
V_8 -> V_23 ) )
V_15 -> V_24 = V_25 ;
else
V_15 -> V_24 = V_26 ;
return V_5 -> V_27 ( V_15 ) ;
}
static void F_12 ( struct V_14 * V_15 ,
const struct V_2 * V_3 ,
struct V_19 * V_28 ,
enum V_29 V_30 )
{
const struct V_16 * V_17 = F_13 ( V_15 ) ;
const struct V_1 * V_5 ;
struct V_6 * V_7 ;
struct V_14 * V_31 ;
unsigned int V_32 ;
int V_33 ;
if ( V_15 -> V_34 == F_14 ( V_35 ) )
return;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ ) {
F_2 (vlan, n, &port->vlan_hash[i], hlist) {
if ( V_5 -> V_8 == V_28 || ! ( V_5 -> V_30 & V_30 ) )
continue;
V_31 = F_15 ( V_15 , V_37 ) ;
V_33 = F_11 ( V_31 , V_5 , V_17 ,
V_30 == V_38 ) ;
F_16 ( V_5 , V_15 -> V_39 + V_40 ,
V_33 == V_41 , 1 ) ;
}
}
}
static T_1 F_17 ( struct V_14 * * V_42 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 = * V_42 ;
const struct V_16 * V_17 = F_13 ( V_15 ) ;
const struct V_1 * V_5 ;
const struct V_1 * V_28 ;
struct V_19 * V_8 ;
unsigned int V_39 = 0 ;
int V_43 = V_20 ;
V_3 = F_18 ( V_15 -> V_8 ) ;
if ( F_19 ( V_17 -> V_22 ) ) {
V_28 = F_1 ( V_3 , V_17 -> V_44 ) ;
if ( ! V_28 )
F_12 ( V_15 , V_3 , NULL ,
V_45 |
V_46 |
V_47 |
V_38 ) ;
else if ( V_28 -> V_30 == V_46 )
F_12 ( V_15 , V_3 , V_28 -> V_8 ,
V_46 |
V_38 ) ;
else if ( V_28 -> V_30 == V_38 )
F_12 ( V_15 , V_3 , V_28 -> V_8 ,
V_46 ) ;
return V_48 ;
}
if ( V_3 -> V_49 )
V_5 = F_20 ( & V_3 -> V_50 , struct V_1 , V_51 ) ;
else
V_5 = F_1 ( V_3 , V_17 -> V_22 ) ;
if ( V_5 == NULL )
return V_48 ;
V_8 = V_5 -> V_8 ;
if ( F_21 ( ! ( V_8 -> V_52 & V_53 ) ) ) {
F_22 ( V_15 ) ;
return V_54 ;
}
V_39 = V_15 -> V_39 + V_40 ;
V_15 = F_23 ( V_15 , V_37 ) ;
if ( ! V_15 )
goto V_55;
V_15 -> V_8 = V_8 ;
V_15 -> V_24 = V_56 ;
V_43 = V_5 -> V_27 ( V_15 ) ;
V_55:
F_16 ( V_5 , V_39 , V_43 == V_41 , 0 ) ;
return V_54 ;
}
static int F_24 ( struct V_14 * V_15 , struct V_19 * V_8 )
{
const struct V_1 * V_5 = F_25 ( V_8 ) ;
const struct V_2 * V_3 = V_5 -> V_3 ;
const struct V_1 * V_57 ;
T_2 V_58 = V_15 -> V_58 ;
if ( V_5 -> V_30 == V_38 ) {
const struct V_16 * V_17 = ( void * ) V_15 -> V_59 ;
V_15 -> V_58 = V_60 ;
if ( F_19 ( V_17 -> V_22 ) ) {
F_12 ( V_15 , V_3 , V_8 , V_38 ) ;
goto V_61;
}
V_57 = F_1 ( V_3 , V_17 -> V_22 ) ;
if ( V_57 && V_57 -> V_30 == V_38 ) {
F_26 ( V_5 -> V_62 , V_15 ) ;
return V_63 ;
}
}
V_61:
V_15 -> V_58 = V_58 ;
F_27 ( V_15 , V_5 -> V_62 ) ;
return F_28 ( V_15 ) ;
}
T_3 F_29 ( struct V_14 * V_15 ,
struct V_19 * V_8 )
{
unsigned int V_39 = V_15 -> V_39 ;
int V_43 ;
const struct V_1 * V_5 = F_25 ( V_8 ) ;
V_43 = F_24 ( V_15 , V_8 ) ;
if ( F_30 ( V_43 == V_63 || V_43 == V_64 ) ) {
struct V_65 * V_66 ;
V_66 = F_31 ( V_5 -> V_66 ) ;
F_32 ( & V_66 -> V_67 ) ;
V_66 -> V_68 ++ ;
V_66 -> V_69 += V_39 ;
F_33 ( & V_66 -> V_67 ) ;
} else {
F_34 ( V_5 -> V_66 -> V_70 ) ;
}
return V_43 ;
}
static int F_35 ( struct V_14 * V_15 , struct V_19 * V_8 ,
unsigned short type , const void * V_71 ,
const void * V_72 , unsigned V_39 )
{
const struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
return F_36 ( V_15 , V_62 , type , V_71 ,
V_72 ? : V_8 -> V_9 , V_39 ) ;
}
static int F_37 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
int V_33 ;
if ( V_5 -> V_3 -> V_49 ) {
F_38 ( V_62 , 1 ) ;
goto V_73;
}
V_33 = - V_74 ;
if ( F_10 ( V_5 -> V_3 , V_8 -> V_9 ) )
goto V_55;
V_33 = F_39 ( V_62 , V_8 -> V_9 ) ;
if ( V_33 < 0 )
goto V_55;
if ( V_8 -> V_52 & V_75 ) {
V_33 = F_40 ( V_62 , 1 ) ;
if ( V_33 < 0 )
goto V_76;
}
V_73:
F_4 ( V_5 ) ;
return 0 ;
V_76:
F_41 ( V_62 , V_8 -> V_9 ) ;
V_55:
return V_33 ;
}
static int F_42 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
if ( V_5 -> V_3 -> V_49 ) {
F_38 ( V_62 , - 1 ) ;
goto V_77;
}
F_43 ( V_62 , V_8 ) ;
if ( V_8 -> V_52 & V_75 )
F_40 ( V_62 , - 1 ) ;
F_41 ( V_62 , V_8 -> V_9 ) ;
V_77:
F_6 ( V_5 , ! V_8 -> V_78 ) ;
return 0 ;
}
static int F_44 ( struct V_19 * V_8 , void * V_79 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
struct V_80 * V_4 = V_79 ;
int V_33 ;
if ( ! F_45 ( V_4 -> V_81 ) )
return - V_82 ;
if ( ! ( V_8 -> V_52 & V_53 ) ) {
memcpy ( V_8 -> V_9 , V_4 -> V_81 , V_13 ) ;
} else {
if ( F_10 ( V_5 -> V_3 , V_4 -> V_81 ) )
return - V_74 ;
V_33 = F_39 ( V_62 , V_4 -> V_81 ) ;
if ( V_33 )
return V_33 ;
F_41 ( V_62 , V_8 -> V_9 ) ;
F_9 ( V_5 , V_4 -> V_81 ) ;
}
return 0 ;
}
static void F_46 ( struct V_19 * V_8 , int V_83 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
if ( V_83 & V_75 )
F_40 ( V_62 , V_8 -> V_52 & V_75 ? 1 : - 1 ) ;
}
static void F_47 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
F_48 ( V_5 -> V_62 , V_8 ) ;
}
static int F_49 ( struct V_19 * V_8 , int V_84 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
if ( V_84 < 68 || V_5 -> V_62 -> V_85 < V_84 )
return - V_86 ;
V_8 -> V_85 = V_84 ;
return 0 ;
}
static void F_50 ( struct V_19 * V_8 ,
struct V_87 * V_88 ,
void * V_89 )
{
F_51 ( & V_88 -> V_90 ,
& V_91 ) ;
}
static void F_52 ( struct V_19 * V_8 )
{
F_51 ( & V_8 -> V_92 ,
& V_93 ) ;
F_53 ( V_8 , F_50 , NULL ) ;
}
static int F_54 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
const struct V_19 * V_62 = V_5 -> V_62 ;
V_8 -> V_94 = ( V_8 -> V_94 & ~ V_95 ) |
( V_62 -> V_94 & V_95 ) ;
V_8 -> V_96 = V_62 -> V_96 & V_97 ;
V_8 -> V_96 |= V_98 ;
V_8 -> V_99 = V_62 -> V_99 ;
V_8 -> V_100 = V_62 -> V_101 ;
V_8 -> V_102 = V_62 -> V_102 ;
F_52 ( V_8 ) ;
V_5 -> V_66 = F_55 ( struct V_65 ) ;
if ( ! V_5 -> V_66 )
return - V_103 ;
return 0 ;
}
static void F_56 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
F_57 ( V_5 -> V_66 ) ;
V_3 -> V_104 -= 1 ;
if ( ! V_3 -> V_104 )
F_58 ( V_3 -> V_8 ) ;
}
static struct V_105 * F_59 ( struct V_19 * V_8 ,
struct V_105 * V_106 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
if ( V_5 -> V_66 ) {
struct V_65 * V_79 ;
T_4 V_107 , V_108 , V_109 , V_68 , V_69 ;
T_5 V_110 = 0 , V_70 = 0 ;
unsigned int V_111 ;
int V_32 ;
F_60 (i) {
V_79 = F_61 ( V_5 -> V_66 , V_32 ) ;
do {
V_111 = F_62 ( & V_79 -> V_67 ) ;
V_107 = V_79 -> V_107 ;
V_108 = V_79 -> V_108 ;
V_109 = V_79 -> V_109 ;
V_68 = V_79 -> V_68 ;
V_69 = V_79 -> V_69 ;
} while ( F_63 ( & V_79 -> V_67 , V_111 ) );
V_106 -> V_107 += V_107 ;
V_106 -> V_108 += V_108 ;
V_106 -> V_112 += V_109 ;
V_106 -> V_68 += V_68 ;
V_106 -> V_69 += V_69 ;
V_110 += V_79 -> V_110 ;
V_70 += V_79 -> V_70 ;
}
V_106 -> V_110 = V_110 ;
V_106 -> V_113 = V_110 ;
V_106 -> V_70 = V_70 ;
}
return V_106 ;
}
static void F_64 ( struct V_19 * V_8 ,
unsigned short V_114 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
const struct V_115 * V_116 = V_62 -> V_117 ;
if ( V_116 -> V_118 )
V_116 -> V_118 ( V_62 , V_114 ) ;
}
static void F_65 ( struct V_19 * V_8 ,
unsigned short V_114 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
const struct V_115 * V_116 = V_62 -> V_117 ;
if ( V_116 -> V_119 )
V_116 -> V_119 ( V_62 , V_114 ) ;
}
static void F_66 ( struct V_19 * V_8 ,
struct V_120 * V_121 )
{
snprintf ( V_121 -> V_122 , 32 , L_1 ) ;
snprintf ( V_121 -> V_123 , 32 , L_2 ) ;
}
static int F_67 ( struct V_19 * V_8 ,
struct V_124 * V_125 )
{
const struct V_1 * V_5 = F_25 ( V_8 ) ;
return F_68 ( V_5 -> V_62 , V_125 ) ;
}
void F_69 ( struct V_19 * V_8 )
{
F_70 ( V_8 ) ;
V_8 -> V_126 &= ~ ( V_127 | V_128 ) ;
V_8 -> V_117 = & V_129 ;
V_8 -> V_130 = V_131 ;
V_8 -> V_132 = & V_133 ,
V_8 -> V_134 = & V_135 ;
}
static void F_71 ( struct V_19 * V_8 )
{
F_69 ( V_8 ) ;
V_8 -> V_136 = 0 ;
}
static int F_72 ( struct V_19 * V_8 )
{
struct V_2 * V_3 ;
unsigned int V_32 ;
int V_33 ;
if ( V_8 -> type != V_137 || V_8 -> V_52 & V_138 )
return - V_86 ;
V_3 = F_73 ( sizeof( * V_3 ) , V_139 ) ;
if ( V_3 == NULL )
return - V_103 ;
V_3 -> V_49 = false ;
V_3 -> V_8 = V_8 ;
F_74 ( & V_3 -> V_50 ) ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ )
F_75 ( & V_3 -> V_11 [ V_32 ] ) ;
V_33 = F_76 ( V_8 , F_17 , V_3 ) ;
if ( V_33 )
F_77 ( V_3 ) ;
else
V_8 -> V_126 |= V_140 ;
return V_33 ;
}
static void F_58 ( struct V_19 * V_8 )
{
struct V_2 * V_3 = F_78 ( V_8 ) ;
V_8 -> V_126 &= ~ V_140 ;
F_79 ( V_8 ) ;
F_80 ( V_3 , V_141 ) ;
}
static int F_81 ( struct V_142 * V_143 [] , struct V_142 * V_59 [] )
{
if ( V_143 [ V_144 ] ) {
if ( F_82 ( V_143 [ V_144 ] ) != V_13 )
return - V_86 ;
if ( ! F_45 ( F_83 ( V_143 [ V_144 ] ) ) )
return - V_82 ;
}
if ( V_59 && V_59 [ V_145 ] ) {
switch ( F_84 ( V_59 [ V_145 ] ) ) {
case V_45 :
case V_46 :
case V_38 :
case V_47 :
break;
default:
return - V_86 ;
}
}
return 0 ;
}
int F_85 ( struct V_146 * V_147 , struct V_19 * V_8 ,
struct V_142 * V_143 [] , struct V_142 * V_59 [] ,
int (* V_27)( struct V_14 * V_15 ) ,
int (* V_21)( struct V_19 * V_8 ,
struct V_14 * V_15 ) )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_2 * V_3 ;
struct V_19 * V_62 ;
int V_33 ;
if ( ! V_143 [ V_148 ] )
return - V_86 ;
V_62 = F_86 ( V_147 , F_84 ( V_143 [ V_148 ] ) ) ;
if ( V_62 == NULL )
return - V_149 ;
if ( V_62 -> V_150 == V_8 -> V_150 ) {
struct V_1 * V_151 = F_25 ( V_62 ) ;
V_62 = V_151 -> V_62 ;
}
if ( ! V_143 [ V_152 ] )
V_8 -> V_85 = V_62 -> V_85 ;
else if ( V_8 -> V_85 > V_62 -> V_85 )
return - V_86 ;
if ( ! V_143 [ V_144 ] )
F_87 ( V_8 -> V_9 ) ;
if ( ! F_88 ( V_62 ) ) {
V_33 = F_72 ( V_62 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_3 = F_78 ( V_62 ) ;
if ( V_3 -> V_49 )
return - V_86 ;
V_5 -> V_62 = V_62 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_30 = V_46 ;
if ( V_59 && V_59 [ V_145 ] )
V_5 -> V_30 = F_84 ( V_59 [ V_145 ] ) ;
if ( V_5 -> V_30 == V_47 ) {
if ( V_3 -> V_104 )
return - V_86 ;
V_3 -> V_49 = true ;
memcpy ( V_8 -> V_9 , V_62 -> V_9 , V_13 ) ;
}
V_3 -> V_104 += 1 ;
V_33 = F_89 ( V_8 ) ;
if ( V_33 < 0 )
goto V_153;
F_90 ( & V_5 -> V_51 , & V_3 -> V_50 ) ;
F_91 ( V_62 , V_8 ) ;
return 0 ;
V_153:
V_3 -> V_104 -= 1 ;
if ( ! V_3 -> V_104 )
F_58 ( V_62 ) ;
return V_33 ;
}
static int F_92 ( struct V_146 * V_147 , struct V_19 * V_8 ,
struct V_142 * V_143 [] , struct V_142 * V_59 [] )
{
return F_85 ( V_147 , V_8 , V_143 , V_59 ,
V_154 ,
F_26 ) ;
}
void F_93 ( struct V_19 * V_8 , struct V_155 * V_156 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
F_94 ( & V_5 -> V_51 ) ;
F_95 ( V_8 , V_156 ) ;
}
static int F_96 ( struct V_19 * V_8 ,
struct V_142 * V_143 [] , struct V_142 * V_59 [] )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
if ( V_59 && V_59 [ V_145 ] )
V_5 -> V_30 = F_84 ( V_59 [ V_145 ] ) ;
return 0 ;
}
static T_6 F_97 ( const struct V_19 * V_8 )
{
return F_98 ( 4 ) ;
}
static int F_99 ( struct V_14 * V_15 ,
const struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
F_100 ( V_15 , V_145 , V_5 -> V_30 ) ;
return 0 ;
V_157:
return - V_158 ;
}
int F_101 ( struct V_150 * V_116 )
{
V_116 -> V_159 = sizeof( struct V_1 ) ;
V_116 -> V_160 = F_81 ;
V_116 -> V_161 = V_162 ;
V_116 -> V_163 = V_164 ;
V_116 -> V_165 = F_96 ;
V_116 -> V_166 = F_97 ;
V_116 -> V_167 = F_99 ;
return F_102 ( V_116 ) ;
}
static int F_103 ( struct V_168 * V_169 ,
unsigned long V_170 , void * V_171 )
{
struct V_19 * V_8 = V_171 ;
struct V_1 * V_5 , * V_172 ;
struct V_2 * V_3 ;
F_104 ( V_173 ) ;
if ( ! F_88 ( V_8 ) )
return V_174 ;
V_3 = F_78 ( V_8 ) ;
switch ( V_170 ) {
case V_175 :
F_105 (vlan, &port->vlans, list)
F_91 ( V_5 -> V_62 ,
V_5 -> V_8 ) ;
break;
case V_176 :
F_105 (vlan, &port->vlans, list) {
V_5 -> V_8 -> V_96 = V_8 -> V_96 & V_97 ;
V_5 -> V_8 -> V_99 = V_8 -> V_99 ;
F_106 ( V_5 -> V_8 ) ;
}
break;
case V_177 :
if ( V_8 -> V_178 != V_179 )
break;
F_107 (vlan, next, &port->vlans, list)
V_5 -> V_8 -> V_150 -> V_180 ( V_5 -> V_8 , & V_173 ) ;
F_108 ( & V_173 ) ;
F_94 ( & V_173 ) ;
break;
case V_181 :
return V_182 ;
}
return V_174 ;
}
static int T_7 F_109 ( void )
{
int V_33 ;
F_110 ( & V_183 ) ;
V_33 = F_101 ( & V_184 ) ;
if ( V_33 < 0 )
goto V_185;
return 0 ;
V_185:
F_111 ( & V_183 ) ;
return V_33 ;
}
static void T_8 F_112 ( void )
{
F_113 ( & V_184 ) ;
F_111 ( & V_183 ) ;
}
