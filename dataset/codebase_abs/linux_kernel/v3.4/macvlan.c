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
V_15 -> V_8 = V_5 -> V_63 ;
return F_28 ( V_15 ) ;
}
T_3 F_29 ( struct V_14 * V_15 ,
struct V_19 * V_8 )
{
unsigned int V_39 = V_15 -> V_39 ;
int V_43 ;
const struct V_1 * V_5 = F_26 ( V_8 ) ;
V_43 = F_25 ( V_15 , V_8 ) ;
if ( F_30 ( V_43 == V_64 || V_43 == V_65 ) ) {
struct V_66 * V_67 ;
V_67 = F_31 ( V_5 -> V_67 ) ;
F_32 ( & V_67 -> V_68 ) ;
V_67 -> V_69 ++ ;
V_67 -> V_70 += V_39 ;
F_33 ( & V_67 -> V_68 ) ;
} else {
F_34 ( V_5 -> V_67 -> V_71 ) ;
}
return V_43 ;
}
static int F_35 ( struct V_14 * V_15 , struct V_19 * V_8 ,
unsigned short type , const void * V_72 ,
const void * V_73 , unsigned V_39 )
{
const struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
return F_36 ( V_15 , V_63 , type , V_72 ,
V_73 ? : V_8 -> V_9 , V_39 ) ;
}
static int F_37 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
int V_33 ;
if ( V_5 -> V_3 -> V_52 ) {
F_38 ( V_63 , 1 ) ;
goto V_74;
}
V_33 = - V_75 ;
if ( F_10 ( V_5 -> V_3 , V_8 -> V_9 ) )
goto V_50;
V_33 = F_39 ( V_63 , V_8 -> V_9 ) ;
if ( V_33 < 0 )
goto V_50;
if ( V_8 -> V_55 & V_76 ) {
V_33 = F_40 ( V_63 , 1 ) ;
if ( V_33 < 0 )
goto V_77;
}
V_74:
F_4 ( V_5 ) ;
return 0 ;
V_77:
F_41 ( V_63 , V_8 -> V_9 ) ;
V_50:
return V_33 ;
}
static int F_42 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
if ( V_5 -> V_3 -> V_52 ) {
F_38 ( V_63 , - 1 ) ;
goto V_78;
}
F_43 ( V_63 , V_8 ) ;
if ( V_8 -> V_55 & V_76 )
F_40 ( V_63 , - 1 ) ;
F_41 ( V_63 , V_8 -> V_9 ) ;
V_78:
F_6 ( V_5 , ! V_8 -> V_79 ) ;
return 0 ;
}
static int F_44 ( struct V_19 * V_8 , void * V_80 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
struct V_81 * V_4 = V_80 ;
int V_33 ;
if ( ! F_45 ( V_4 -> V_82 ) )
return - V_83 ;
if ( ! ( V_8 -> V_55 & V_56 ) ) {
V_8 -> V_84 &= ~ V_85 ;
memcpy ( V_8 -> V_9 , V_4 -> V_82 , V_13 ) ;
} else {
if ( F_10 ( V_5 -> V_3 , V_4 -> V_82 ) )
return - V_75 ;
V_33 = F_39 ( V_63 , V_4 -> V_82 ) ;
if ( V_33 )
return V_33 ;
F_41 ( V_63 , V_8 -> V_9 ) ;
F_9 ( V_5 , V_4 -> V_82 ) ;
}
return 0 ;
}
static void F_46 ( struct V_19 * V_8 , int V_86 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
if ( V_86 & V_76 )
F_40 ( V_63 , V_8 -> V_55 & V_76 ? 1 : - 1 ) ;
}
static void F_47 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
F_48 ( V_5 -> V_63 , V_8 ) ;
}
static int F_49 ( struct V_19 * V_8 , int V_87 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
if ( V_87 < 68 || V_5 -> V_63 -> V_88 < V_87 )
return - V_89 ;
V_8 -> V_88 = V_87 ;
return 0 ;
}
static void F_50 ( struct V_19 * V_8 ,
struct V_90 * V_91 ,
void * V_92 )
{
F_51 ( & V_91 -> V_93 ,
& V_94 ) ;
}
static void F_52 ( struct V_19 * V_8 )
{
F_51 ( & V_8 -> V_95 ,
& V_96 ) ;
F_53 ( V_8 , F_50 , NULL ) ;
}
static int F_54 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
const struct V_19 * V_63 = V_5 -> V_63 ;
V_8 -> V_97 = ( V_8 -> V_97 & ~ V_98 ) |
( V_63 -> V_97 & V_98 ) ;
V_8 -> V_99 = V_63 -> V_99 & V_100 ;
V_8 -> V_99 |= V_101 ;
V_8 -> V_102 = V_63 -> V_102 ;
V_8 -> V_103 = V_63 -> V_104 ;
V_8 -> V_105 = V_63 -> V_105 ;
F_52 ( V_8 ) ;
V_5 -> V_67 = F_55 ( struct V_66 ) ;
if ( ! V_5 -> V_67 )
return - V_106 ;
return 0 ;
}
static void F_56 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
F_57 ( V_5 -> V_67 ) ;
V_3 -> V_107 -= 1 ;
if ( ! V_3 -> V_107 )
F_58 ( V_3 -> V_8 ) ;
}
static struct V_108 * F_59 ( struct V_19 * V_8 ,
struct V_108 * V_109 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
if ( V_5 -> V_67 ) {
struct V_66 * V_80 ;
T_4 V_110 , V_111 , V_112 , V_69 , V_70 ;
T_5 V_113 = 0 , V_71 = 0 ;
unsigned int V_114 ;
int V_32 ;
F_60 (i) {
V_80 = F_61 ( V_5 -> V_67 , V_32 ) ;
do {
V_114 = F_62 ( & V_80 -> V_68 ) ;
V_110 = V_80 -> V_110 ;
V_111 = V_80 -> V_111 ;
V_112 = V_80 -> V_112 ;
V_69 = V_80 -> V_69 ;
V_70 = V_80 -> V_70 ;
} while ( F_63 ( & V_80 -> V_68 , V_114 ) );
V_109 -> V_110 += V_110 ;
V_109 -> V_111 += V_111 ;
V_109 -> V_115 += V_112 ;
V_109 -> V_69 += V_69 ;
V_109 -> V_70 += V_70 ;
V_113 += V_80 -> V_113 ;
V_71 += V_80 -> V_71 ;
}
V_109 -> V_113 = V_113 ;
V_109 -> V_116 = V_113 ;
V_109 -> V_71 = V_71 ;
}
return V_109 ;
}
static int F_64 ( struct V_19 * V_8 ,
unsigned short V_117 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
return F_65 ( V_63 , V_117 ) ;
}
static int F_66 ( struct V_19 * V_8 ,
unsigned short V_117 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_19 * V_63 = V_5 -> V_63 ;
F_67 ( V_63 , V_117 ) ;
return 0 ;
}
static void F_68 ( struct V_19 * V_8 ,
struct V_118 * V_119 )
{
snprintf ( V_119 -> V_120 , 32 , L_1 ) ;
snprintf ( V_119 -> V_121 , 32 , L_2 ) ;
}
static int F_69 ( struct V_19 * V_8 ,
struct V_122 * V_123 )
{
const struct V_1 * V_5 = F_26 ( V_8 ) ;
return F_70 ( V_5 -> V_63 , V_123 ) ;
}
void F_71 ( struct V_19 * V_8 )
{
F_72 ( V_8 ) ;
V_8 -> V_124 &= ~ ( V_125 | V_126 ) ;
V_8 -> V_127 = & V_128 ;
V_8 -> V_129 = V_130 ;
V_8 -> V_131 = & V_132 ,
V_8 -> V_133 = & V_134 ;
}
static void F_73 ( struct V_19 * V_8 )
{
F_71 ( V_8 ) ;
V_8 -> V_135 = 0 ;
}
static int F_74 ( struct V_19 * V_8 )
{
struct V_2 * V_3 ;
unsigned int V_32 ;
int V_33 ;
if ( V_8 -> type != V_136 || V_8 -> V_55 & V_137 )
return - V_89 ;
V_3 = F_75 ( sizeof( * V_3 ) , V_138 ) ;
if ( V_3 == NULL )
return - V_106 ;
V_3 -> V_52 = false ;
V_3 -> V_8 = V_8 ;
F_76 ( & V_3 -> V_53 ) ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ )
F_77 ( & V_3 -> V_11 [ V_32 ] ) ;
V_33 = F_78 ( V_8 , F_17 , V_3 ) ;
if ( V_33 )
F_79 ( V_3 ) ;
else
V_8 -> V_124 |= V_139 ;
return V_33 ;
}
static void F_58 ( struct V_19 * V_8 )
{
struct V_2 * V_3 = F_80 ( V_8 ) ;
V_8 -> V_124 &= ~ V_139 ;
F_81 ( V_8 ) ;
F_82 ( V_3 , V_140 ) ;
}
static int F_83 ( struct V_141 * V_142 [] , struct V_141 * V_60 [] )
{
if ( V_142 [ V_143 ] ) {
if ( F_84 ( V_142 [ V_143 ] ) != V_13 )
return - V_89 ;
if ( ! F_45 ( F_85 ( V_142 [ V_143 ] ) ) )
return - V_83 ;
}
if ( V_60 && V_60 [ V_144 ] ) {
switch ( F_86 ( V_60 [ V_144 ] ) ) {
case V_47 :
case V_48 :
case V_38 :
case V_49 :
break;
default:
return - V_89 ;
}
}
return 0 ;
}
int F_87 ( struct V_145 * V_146 , struct V_19 * V_8 ,
struct V_141 * V_142 [] , struct V_141 * V_60 [] ,
int (* V_27)( struct V_14 * V_15 ) ,
int (* V_21)( struct V_19 * V_8 ,
struct V_14 * V_15 ) )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
struct V_2 * V_3 ;
struct V_19 * V_63 ;
int V_33 ;
if ( ! V_142 [ V_147 ] )
return - V_89 ;
V_63 = F_88 ( V_146 , F_86 ( V_142 [ V_147 ] ) ) ;
if ( V_63 == NULL )
return - V_148 ;
if ( V_63 -> V_149 == V_8 -> V_149 ) {
struct V_1 * V_150 = F_26 ( V_63 ) ;
V_63 = V_150 -> V_63 ;
}
if ( ! V_142 [ V_151 ] )
V_8 -> V_88 = V_63 -> V_88 ;
else if ( V_8 -> V_88 > V_63 -> V_88 )
return - V_89 ;
if ( ! V_142 [ V_143 ] )
F_89 ( V_8 ) ;
if ( ! F_90 ( V_63 ) ) {
V_33 = F_74 ( V_63 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_3 = F_80 ( V_63 ) ;
if ( V_3 -> V_52 )
return - V_89 ;
V_5 -> V_63 = V_63 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_30 = V_48 ;
if ( V_60 && V_60 [ V_144 ] )
V_5 -> V_30 = F_86 ( V_60 [ V_144 ] ) ;
if ( V_5 -> V_30 == V_49 ) {
if ( V_3 -> V_107 )
return - V_89 ;
V_3 -> V_52 = true ;
memcpy ( V_8 -> V_9 , V_63 -> V_9 , V_13 ) ;
}
V_3 -> V_107 += 1 ;
V_33 = F_91 ( V_8 ) ;
if ( V_33 < 0 )
goto V_152;
F_92 ( & V_5 -> V_54 , & V_3 -> V_53 ) ;
F_93 ( V_63 , V_8 ) ;
return 0 ;
V_152:
V_3 -> V_107 -= 1 ;
if ( ! V_3 -> V_107 )
F_58 ( V_63 ) ;
return V_33 ;
}
static int F_94 ( struct V_145 * V_146 , struct V_19 * V_8 ,
struct V_141 * V_142 [] , struct V_141 * V_60 [] )
{
return F_87 ( V_146 , V_8 , V_142 , V_60 ,
V_153 ,
F_27 ) ;
}
void F_95 ( struct V_19 * V_8 , struct V_154 * V_155 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
F_96 ( & V_5 -> V_54 ) ;
F_97 ( V_8 , V_155 ) ;
}
static int F_98 ( struct V_19 * V_8 ,
struct V_141 * V_142 [] , struct V_141 * V_60 [] )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
if ( V_60 && V_60 [ V_144 ] )
V_5 -> V_30 = F_86 ( V_60 [ V_144 ] ) ;
return 0 ;
}
static T_6 F_99 ( const struct V_19 * V_8 )
{
return F_100 ( 4 ) ;
}
static int F_101 ( struct V_14 * V_15 ,
const struct V_19 * V_8 )
{
struct V_1 * V_5 = F_26 ( V_8 ) ;
F_102 ( V_15 , V_144 , V_5 -> V_30 ) ;
return 0 ;
V_156:
return - V_157 ;
}
int F_103 ( struct V_149 * V_158 )
{
V_158 -> V_159 = sizeof( struct V_1 ) ;
V_158 -> V_160 = F_83 ;
V_158 -> V_161 = V_162 ;
V_158 -> V_163 = V_164 ;
V_158 -> V_165 = F_98 ;
V_158 -> V_166 = F_99 ;
V_158 -> V_167 = F_101 ;
return F_104 ( V_158 ) ;
}
static int F_105 ( struct V_168 * V_169 ,
unsigned long V_170 , void * V_171 )
{
struct V_19 * V_8 = V_171 ;
struct V_1 * V_5 , * V_172 ;
struct V_2 * V_3 ;
F_106 ( V_173 ) ;
if ( ! F_90 ( V_8 ) )
return V_174 ;
V_3 = F_80 ( V_8 ) ;
switch ( V_170 ) {
case V_175 :
F_107 (vlan, &port->vlans, list)
F_93 ( V_5 -> V_63 ,
V_5 -> V_8 ) ;
break;
case V_176 :
F_107 (vlan, &port->vlans, list) {
V_5 -> V_8 -> V_99 = V_8 -> V_99 & V_100 ;
V_5 -> V_8 -> V_102 = V_8 -> V_102 ;
F_108 ( V_5 -> V_8 ) ;
}
break;
case V_177 :
if ( V_8 -> V_178 != V_179 )
break;
F_109 (vlan, next, &port->vlans, list)
V_5 -> V_8 -> V_149 -> V_180 ( V_5 -> V_8 , & V_173 ) ;
F_110 ( & V_173 ) ;
F_96 ( & V_173 ) ;
break;
case V_181 :
return V_182 ;
}
return V_174 ;
}
static int T_7 F_111 ( void )
{
int V_33 ;
F_112 ( & V_183 ) ;
V_33 = F_103 ( & V_184 ) ;
if ( V_33 < 0 )
goto V_185;
return 0 ;
V_185:
F_113 ( & V_183 ) ;
return V_33 ;
}
static void T_8 F_114 ( void )
{
F_115 ( & V_184 ) ;
F_113 ( & V_183 ) ;
}
