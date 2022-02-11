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
V_15 = F_20 ( V_15 , V_44 ) ;
if ( ! V_15 )
return V_45 ;
V_17 = F_13 ( V_15 ) ;
V_28 = F_1 ( V_3 , V_17 -> V_46 ) ;
if ( ! V_28 )
F_12 ( V_15 , V_3 , NULL ,
V_47 |
V_48 |
V_49 |
V_38 ) ;
else if ( V_28 -> V_30 == V_48 )
F_12 ( V_15 , V_3 , V_28 -> V_8 ,
V_48 |
V_38 ) ;
else if ( V_28 -> V_30 == V_38 )
F_12 ( V_15 , V_3 , V_28 -> V_8 ,
V_48 ) ;
else {
V_5 = V_28 ;
V_43 = F_11 ( V_15 , V_5 , V_17 , 0 ) ;
goto V_50;
}
return V_51 ;
}
if ( V_3 -> V_52 )
V_5 = F_21 ( & V_3 -> V_53 , struct V_1 , V_54 ) ;
else
V_5 = F_1 ( V_3 , V_17 -> V_22 ) ;
if ( V_5 == NULL )
return V_51 ;
V_8 = V_5 -> V_8 ;
if ( F_22 ( ! ( V_8 -> V_55 & V_56 ) ) ) {
F_23 ( V_15 ) ;
return V_45 ;
}
V_39 = V_15 -> V_39 + V_40 ;
V_15 = F_24 ( V_15 , V_37 ) ;
if ( ! V_15 )
goto V_50;
V_15 -> V_8 = V_8 ;
V_15 -> V_24 = V_57 ;
V_43 = V_5 -> V_27 ( V_15 ) ;
V_50:
F_16 ( V_5 , V_39 , V_43 == V_41 , 0 ) ;
return V_45 ;
}
static int F_25 ( struct V_14 * V_15 , struct V_19 * V_8 )
{
const struct V_1 * V_5 = F_26 ( V_8 ) ;
const struct V_2 * V_3 = V_5 -> V_3 ;
const struct V_1 * V_58 ;
T_2 V_59 = V_15 -> V_59 ;
if ( V_5 -> V_30 == V_38 ) {
const struct V_16 * V_17 = ( void * ) V_15 -> V_60 ;
V_15 -> V_59 = V_61 ;
if ( F_19 ( V_17 -> V_22 ) ) {
F_12 ( V_15 , V_3 , V_8 , V_38 ) ;
goto V_62;
}
V_58 = F_1 ( V_3 , V_17 -> V_22 ) ;
if ( V_58 && V_58 -> V_30 == V_38 ) {
F_27 ( V_5 -> V_63 , V_15 ) ;
return V_64 ;
}
}
V_62:
V_15 -> V_59 = V_59 ;
F_28 ( V_15 , V_5 -> V_63 ) ;
return F_29 ( V_15 ) ;
}
T_3 F_30 ( struct V_14 * V_15 ,
struct V_19 * V_8 )
{
unsigned int V_39 = V_15 -> V_39 ;
int V_43 ;
const struct V_1 * V_5 = F_26 ( V_8 ) ;
V_43 = F_25 ( V_15 , V_8 ) ;
if ( F_31 ( V_43 == V_64 || V_43 == V_65 ) ) {
struct V_66 * V_67 ;
V_67 = F_32 ( V_5 -> V_67 ) ;
F_33 ( & V_67 -> V_68 ) ;
V_67 -> V_69 ++ ;
V_67 -> V_70 += V_39 ;
F_34 ( & V_67 -> V_68 ) ;
} else {
F_35 ( V_5 -> V_67 -> V_71 ) ;
}
return V_43 ;
}
static int F_36 ( struct V_14 * V_15 , struct V_19 * V_8 ,
unsigned short type , const void * V_72 ,
const void * V_73 , unsigned V_39 )
{
const struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
return F_37 ( V_15 , V_63 , type , V_72 ,
V_73 ? : V_8 -> V_9 , V_39 ) ;
}
static int F_38 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
int V_33 ;
if ( V_5 -> V_3 -> V_52 ) {
F_39 ( V_63 , 1 ) ;
goto V_74;
}
V_33 = - V_75 ;
if ( F_10 ( V_5 -> V_3 , V_8 -> V_9 ) )
goto V_50;
V_33 = F_40 ( V_63 , V_8 -> V_9 ) ;
if ( V_33 < 0 )
goto V_50;
if ( V_8 -> V_55 & V_76 ) {
V_33 = F_41 ( V_63 , 1 ) ;
if ( V_33 < 0 )
goto V_77;
}
V_74:
F_4 ( V_5 ) ;
return 0 ;
V_77:
F_42 ( V_63 , V_8 -> V_9 ) ;
V_50:
return V_33 ;
}
static int F_43 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
if ( V_5 -> V_3 -> V_52 ) {
F_39 ( V_63 , - 1 ) ;
goto V_78;
}
F_44 ( V_63 , V_8 ) ;
if ( V_8 -> V_55 & V_76 )
F_41 ( V_63 , - 1 ) ;
F_42 ( V_63 , V_8 -> V_9 ) ;
V_78:
F_6 ( V_5 , ! V_8 -> V_79 ) ;
return 0 ;
}
static int F_45 ( struct V_19 * V_8 , void * V_80 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
struct V_81 * V_4 = V_80 ;
int V_33 ;
if ( ! F_46 ( V_4 -> V_82 ) )
return - V_83 ;
if ( ! ( V_8 -> V_55 & V_56 ) ) {
memcpy ( V_8 -> V_9 , V_4 -> V_82 , V_13 ) ;
} else {
if ( F_10 ( V_5 -> V_3 , V_4 -> V_82 ) )
return - V_75 ;
V_33 = F_40 ( V_63 , V_4 -> V_82 ) ;
if ( V_33 )
return V_33 ;
F_42 ( V_63 , V_8 -> V_9 ) ;
F_9 ( V_5 , V_4 -> V_82 ) ;
}
return 0 ;
}
static void F_47 ( struct V_19 * V_8 , int V_84 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
if ( V_84 & V_76 )
F_41 ( V_63 , V_8 -> V_55 & V_76 ? 1 : - 1 ) ;
}
static void F_48 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
F_49 ( V_5 -> V_63 , V_8 ) ;
}
static int F_50 ( struct V_19 * V_8 , int V_85 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
if ( V_85 < 68 || V_5 -> V_63 -> V_86 < V_85 )
return - V_87 ;
V_8 -> V_86 = V_85 ;
return 0 ;
}
static void F_51 ( struct V_19 * V_8 ,
struct V_88 * V_89 ,
void * V_90 )
{
F_52 ( & V_89 -> V_91 ,
& V_92 ) ;
}
static void F_53 ( struct V_19 * V_8 )
{
F_52 ( & V_8 -> V_93 ,
& V_94 ) ;
F_54 ( V_8 , F_51 , NULL ) ;
}
static int F_55 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
const struct V_19 * V_63 = V_5 -> V_63 ;
V_8 -> V_95 = ( V_8 -> V_95 & ~ V_96 ) |
( V_63 -> V_95 & V_96 ) ;
V_8 -> V_97 = V_63 -> V_97 & V_98 ;
V_8 -> V_97 |= V_99 ;
V_8 -> V_100 = V_63 -> V_100 ;
V_8 -> V_101 = V_63 -> V_102 ;
V_8 -> V_103 = V_63 -> V_103 ;
F_53 ( V_8 ) ;
V_5 -> V_67 = F_56 ( struct V_66 ) ;
if ( ! V_5 -> V_67 )
return - V_104 ;
return 0 ;
}
static void F_57 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
F_58 ( V_5 -> V_67 ) ;
V_3 -> V_105 -= 1 ;
if ( ! V_3 -> V_105 )
F_59 ( V_3 -> V_8 ) ;
}
static struct V_106 * F_60 ( struct V_19 * V_8 ,
struct V_106 * V_107 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
if ( V_5 -> V_67 ) {
struct V_66 * V_80 ;
T_4 V_108 , V_109 , V_110 , V_69 , V_70 ;
T_5 V_111 = 0 , V_71 = 0 ;
unsigned int V_112 ;
int V_32 ;
F_61 (i) {
V_80 = F_62 ( V_5 -> V_67 , V_32 ) ;
do {
V_112 = F_63 ( & V_80 -> V_68 ) ;
V_108 = V_80 -> V_108 ;
V_109 = V_80 -> V_109 ;
V_110 = V_80 -> V_110 ;
V_69 = V_80 -> V_69 ;
V_70 = V_80 -> V_70 ;
} while ( F_64 ( & V_80 -> V_68 , V_112 ) );
V_107 -> V_108 += V_108 ;
V_107 -> V_109 += V_109 ;
V_107 -> V_113 += V_110 ;
V_107 -> V_69 += V_69 ;
V_107 -> V_70 += V_70 ;
V_111 += V_80 -> V_111 ;
V_71 += V_80 -> V_71 ;
}
V_107 -> V_111 = V_111 ;
V_107 -> V_114 = V_111 ;
V_107 -> V_71 = V_71 ;
}
return V_107 ;
}
static int F_65 ( struct V_19 * V_8 ,
unsigned short V_115 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
return F_66 ( V_63 , V_115 ) ;
}
static int F_67 ( struct V_19 * V_8 ,
unsigned short V_115 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
F_68 ( V_63 , V_115 ) ;
return 0 ;
}
static void F_69 ( struct V_19 * V_8 ,
struct V_116 * V_117 )
{
snprintf ( V_117 -> V_118 , 32 , L_1 ) ;
snprintf ( V_117 -> V_119 , 32 , L_2 ) ;
}
static int F_70 ( struct V_19 * V_8 ,
struct V_120 * V_121 )
{
const struct V_1 * V_5 = F_26 ( V_8 ) ;
return F_71 ( V_5 -> V_63 , V_121 ) ;
}
void F_72 ( struct V_19 * V_8 )
{
F_73 ( V_8 ) ;
V_8 -> V_122 &= ~ ( V_123 | V_124 ) ;
V_8 -> V_125 = & V_126 ;
V_8 -> V_127 = V_128 ;
V_8 -> V_129 = & V_130 ,
V_8 -> V_131 = & V_132 ;
}
static void F_74 ( struct V_19 * V_8 )
{
F_72 ( V_8 ) ;
V_8 -> V_133 = 0 ;
}
static int F_75 ( struct V_19 * V_8 )
{
struct V_2 * V_3 ;
unsigned int V_32 ;
int V_33 ;
if ( V_8 -> type != V_134 || V_8 -> V_55 & V_135 )
return - V_87 ;
V_3 = F_76 ( sizeof( * V_3 ) , V_136 ) ;
if ( V_3 == NULL )
return - V_104 ;
V_3 -> V_52 = false ;
V_3 -> V_8 = V_8 ;
F_77 ( & V_3 -> V_53 ) ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ )
F_78 ( & V_3 -> V_11 [ V_32 ] ) ;
V_33 = F_79 ( V_8 , F_17 , V_3 ) ;
if ( V_33 )
F_80 ( V_3 ) ;
else
V_8 -> V_122 |= V_137 ;
return V_33 ;
}
static void F_59 ( struct V_19 * V_8 )
{
struct V_2 * V_3 = F_81 ( V_8 ) ;
V_8 -> V_122 &= ~ V_137 ;
F_82 ( V_8 ) ;
F_83 ( V_3 , V_138 ) ;
}
static int F_84 ( struct V_139 * V_140 [] , struct V_139 * V_60 [] )
{
if ( V_140 [ V_141 ] ) {
if ( F_85 ( V_140 [ V_141 ] ) != V_13 )
return - V_87 ;
if ( ! F_46 ( F_86 ( V_140 [ V_141 ] ) ) )
return - V_83 ;
}
if ( V_60 && V_60 [ V_142 ] ) {
switch ( F_87 ( V_60 [ V_142 ] ) ) {
case V_47 :
case V_48 :
case V_38 :
case V_49 :
break;
default:
return - V_87 ;
}
}
return 0 ;
}
int F_88 ( struct V_143 * V_144 , struct V_19 * V_8 ,
struct V_139 * V_140 [] , struct V_139 * V_60 [] ,
int (* V_27)( struct V_14 * V_15 ) ,
int (* V_21)( struct V_19 * V_8 ,
struct V_14 * V_15 ) )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_2 * V_3 ;
struct V_19 * V_63 ;
int V_33 ;
if ( ! V_140 [ V_145 ] )
return - V_87 ;
V_63 = F_89 ( V_144 , F_87 ( V_140 [ V_145 ] ) ) ;
if ( V_63 == NULL )
return - V_146 ;
if ( V_63 -> V_147 == V_8 -> V_147 ) {
struct V_1 * V_148 = F_26 ( V_63 ) ;
V_63 = V_148 -> V_63 ;
}
if ( ! V_140 [ V_149 ] )
V_8 -> V_86 = V_63 -> V_86 ;
else if ( V_8 -> V_86 > V_63 -> V_86 )
return - V_87 ;
if ( ! V_140 [ V_141 ] )
F_90 ( V_8 -> V_9 ) ;
if ( ! F_91 ( V_63 ) ) {
V_33 = F_75 ( V_63 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_3 = F_81 ( V_63 ) ;
if ( V_3 -> V_52 )
return - V_87 ;
V_5 -> V_63 = V_63 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_30 = V_48 ;
if ( V_60 && V_60 [ V_142 ] )
V_5 -> V_30 = F_87 ( V_60 [ V_142 ] ) ;
if ( V_5 -> V_30 == V_49 ) {
if ( V_3 -> V_105 )
return - V_87 ;
V_3 -> V_52 = true ;
memcpy ( V_8 -> V_9 , V_63 -> V_9 , V_13 ) ;
}
V_3 -> V_105 += 1 ;
V_33 = F_92 ( V_8 ) ;
if ( V_33 < 0 )
goto V_150;
F_93 ( & V_5 -> V_54 , & V_3 -> V_53 ) ;
F_94 ( V_63 , V_8 ) ;
return 0 ;
V_150:
V_3 -> V_105 -= 1 ;
if ( ! V_3 -> V_105 )
F_59 ( V_63 ) ;
return V_33 ;
}
static int F_95 ( struct V_143 * V_144 , struct V_19 * V_8 ,
struct V_139 * V_140 [] , struct V_139 * V_60 [] )
{
return F_88 ( V_144 , V_8 , V_140 , V_60 ,
V_151 ,
F_27 ) ;
}
void F_96 ( struct V_19 * V_8 , struct V_152 * V_153 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
F_97 ( & V_5 -> V_54 ) ;
F_98 ( V_8 , V_153 ) ;
}
static int F_99 ( struct V_19 * V_8 ,
struct V_139 * V_140 [] , struct V_139 * V_60 [] )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
if ( V_60 && V_60 [ V_142 ] )
V_5 -> V_30 = F_87 ( V_60 [ V_142 ] ) ;
return 0 ;
}
static T_6 F_100 ( const struct V_19 * V_8 )
{
return F_101 ( 4 ) ;
}
static int F_102 ( struct V_14 * V_15 ,
const struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
F_103 ( V_15 , V_142 , V_5 -> V_30 ) ;
return 0 ;
V_154:
return - V_155 ;
}
int F_104 ( struct V_147 * V_156 )
{
V_156 -> V_157 = sizeof( struct V_1 ) ;
V_156 -> V_158 = F_84 ;
V_156 -> V_159 = V_160 ;
V_156 -> V_161 = V_162 ;
V_156 -> V_163 = F_99 ;
V_156 -> V_164 = F_100 ;
V_156 -> V_165 = F_102 ;
return F_105 ( V_156 ) ;
}
static int F_106 ( struct V_166 * V_167 ,
unsigned long V_168 , void * V_169 )
{
struct V_19 * V_8 = V_169 ;
struct V_1 * V_5 , * V_170 ;
struct V_2 * V_3 ;
F_107 ( V_171 ) ;
if ( ! F_91 ( V_8 ) )
return V_172 ;
V_3 = F_81 ( V_8 ) ;
switch ( V_168 ) {
case V_173 :
F_108 (vlan, &port->vlans, list)
F_94 ( V_5 -> V_63 ,
V_5 -> V_8 ) ;
break;
case V_174 :
F_108 (vlan, &port->vlans, list) {
V_5 -> V_8 -> V_97 = V_8 -> V_97 & V_98 ;
V_5 -> V_8 -> V_100 = V_8 -> V_100 ;
F_109 ( V_5 -> V_8 ) ;
}
break;
case V_175 :
if ( V_8 -> V_176 != V_177 )
break;
F_110 (vlan, next, &port->vlans, list)
V_5 -> V_8 -> V_147 -> V_178 ( V_5 -> V_8 , & V_171 ) ;
F_111 ( & V_171 ) ;
F_97 ( & V_171 ) ;
break;
case V_179 :
return V_180 ;
}
return V_172 ;
}
static int T_7 F_112 ( void )
{
int V_33 ;
F_113 ( & V_181 ) ;
V_33 = F_104 ( & V_182 ) ;
if ( V_33 < 0 )
goto V_183;
return 0 ;
V_183:
F_114 ( & V_181 ) ;
return V_33 ;
}
static void T_8 F_115 ( void )
{
F_116 ( & V_182 ) ;
F_114 ( & V_181 ) ;
}
