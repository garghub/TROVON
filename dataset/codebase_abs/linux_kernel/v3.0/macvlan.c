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
V_5 -> V_21 ( V_5 -> V_62 , V_15 ) ;
return V_63 ;
}
}
V_61:
V_15 -> V_58 = V_58 ;
F_26 ( V_15 , V_5 -> V_62 ) ;
return F_27 ( V_15 ) ;
}
T_3 F_28 ( struct V_14 * V_15 ,
struct V_19 * V_8 )
{
unsigned int V_39 = V_15 -> V_39 ;
int V_43 ;
const struct V_1 * V_5 = F_25 ( V_8 ) ;
V_43 = F_24 ( V_15 , V_8 ) ;
if ( F_29 ( V_43 == V_63 || V_43 == V_64 ) ) {
struct V_65 * V_66 ;
V_66 = F_30 ( V_5 -> V_66 ) ;
F_31 ( & V_66 -> V_67 ) ;
V_66 -> V_68 ++ ;
V_66 -> V_69 += V_39 ;
F_32 ( & V_66 -> V_67 ) ;
} else {
F_33 ( V_5 -> V_66 -> V_70 ) ;
}
return V_43 ;
}
static int F_34 ( struct V_14 * V_15 , struct V_19 * V_8 ,
unsigned short type , const void * V_71 ,
const void * V_72 , unsigned V_39 )
{
const struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
return F_35 ( V_15 , V_62 , type , V_71 ,
V_72 ? : V_8 -> V_9 , V_39 ) ;
}
static int F_36 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
int V_33 ;
if ( V_5 -> V_3 -> V_49 ) {
F_37 ( V_62 , 1 ) ;
goto V_73;
}
V_33 = - V_74 ;
if ( F_10 ( V_5 -> V_3 , V_8 -> V_9 ) )
goto V_55;
V_33 = F_38 ( V_62 , V_8 -> V_9 ) ;
if ( V_33 < 0 )
goto V_55;
if ( V_8 -> V_52 & V_75 ) {
V_33 = F_39 ( V_62 , 1 ) ;
if ( V_33 < 0 )
goto V_76;
}
V_73:
F_4 ( V_5 ) ;
return 0 ;
V_76:
F_40 ( V_62 , V_8 -> V_9 ) ;
V_55:
return V_33 ;
}
static int F_41 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
if ( V_5 -> V_3 -> V_49 ) {
F_37 ( V_62 , - 1 ) ;
goto V_77;
}
F_42 ( V_62 , V_8 ) ;
if ( V_8 -> V_52 & V_75 )
F_39 ( V_62 , - 1 ) ;
F_40 ( V_62 , V_8 -> V_9 ) ;
V_77:
F_6 ( V_5 , ! V_8 -> V_78 ) ;
return 0 ;
}
static int F_43 ( struct V_19 * V_8 , void * V_79 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
struct V_80 * V_4 = V_79 ;
int V_33 ;
if ( ! F_44 ( V_4 -> V_81 ) )
return - V_82 ;
if ( ! ( V_8 -> V_52 & V_53 ) ) {
memcpy ( V_8 -> V_9 , V_4 -> V_81 , V_13 ) ;
} else {
if ( F_10 ( V_5 -> V_3 , V_4 -> V_81 ) )
return - V_74 ;
V_33 = F_38 ( V_62 , V_4 -> V_81 ) ;
if ( V_33 )
return V_33 ;
F_40 ( V_62 , V_8 -> V_9 ) ;
F_9 ( V_5 , V_4 -> V_81 ) ;
}
return 0 ;
}
static void F_45 ( struct V_19 * V_8 , int V_83 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_19 * V_62 = V_5 -> V_62 ;
if ( V_83 & V_75 )
F_39 ( V_62 , V_8 -> V_52 & V_75 ? 1 : - 1 ) ;
}
static void F_46 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
F_47 ( V_5 -> V_62 , V_8 ) ;
}
static int F_48 ( struct V_19 * V_8 , int V_84 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
if ( V_84 < 68 || V_5 -> V_62 -> V_85 < V_84 )
return - V_86 ;
V_8 -> V_85 = V_84 ;
return 0 ;
}
static void F_49 ( struct V_19 * V_8 ,
struct V_87 * V_88 ,
void * V_89 )
{
F_50 ( & V_88 -> V_90 ,
& V_91 ) ;
}
static void F_51 ( struct V_19 * V_8 )
{
F_50 ( & V_8 -> V_92 ,
& V_93 ) ;
F_52 ( V_8 , F_49 , NULL ) ;
}
static int F_53 ( struct V_19 * V_8 )
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
F_51 ( V_8 ) ;
V_5 -> V_66 = F_54 ( struct V_65 ) ;
if ( ! V_5 -> V_66 )
return - V_103 ;
return 0 ;
}
static void F_55 ( struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
F_56 ( V_5 -> V_66 ) ;
V_3 -> V_104 -= 1 ;
if ( ! V_3 -> V_104 )
F_57 ( V_3 -> V_8 ) ;
}
static struct V_105 * F_58 ( struct V_19 * V_8 ,
struct V_105 * V_106 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
if ( V_5 -> V_66 ) {
struct V_65 * V_79 ;
T_4 V_107 , V_108 , V_109 , V_68 , V_69 ;
T_5 V_110 = 0 , V_70 = 0 ;
unsigned int V_111 ;
int V_32 ;
F_59 (i) {
V_79 = F_60 ( V_5 -> V_66 , V_32 ) ;
do {
V_111 = F_61 ( & V_79 -> V_67 ) ;
V_107 = V_79 -> V_107 ;
V_108 = V_79 -> V_108 ;
V_109 = V_79 -> V_109 ;
V_68 = V_79 -> V_68 ;
V_69 = V_79 -> V_69 ;
} while ( F_62 ( & V_79 -> V_67 , V_111 ) );
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
static void F_63 ( struct V_19 * V_8 ,
struct V_114 * V_115 )
{
snprintf ( V_115 -> V_116 , 32 , L_1 ) ;
snprintf ( V_115 -> V_117 , 32 , L_2 ) ;
}
static int F_64 ( struct V_19 * V_8 ,
struct V_118 * V_119 )
{
const struct V_1 * V_5 = F_25 ( V_8 ) ;
return F_65 ( V_5 -> V_62 , V_119 ) ;
}
void F_66 ( struct V_19 * V_8 )
{
F_67 ( V_8 ) ;
V_8 -> V_120 &= ~ V_121 ;
V_8 -> V_122 = & V_123 ;
V_8 -> V_124 = V_125 ;
V_8 -> V_126 = & V_127 ,
V_8 -> V_128 = & V_129 ;
}
static void F_68 ( struct V_19 * V_8 )
{
F_66 ( V_8 ) ;
V_8 -> V_130 = 0 ;
}
static int F_69 ( struct V_19 * V_8 )
{
struct V_2 * V_3 ;
unsigned int V_32 ;
int V_33 ;
if ( V_8 -> type != V_131 || V_8 -> V_52 & V_132 )
return - V_86 ;
V_3 = F_70 ( sizeof( * V_3 ) , V_133 ) ;
if ( V_3 == NULL )
return - V_103 ;
V_3 -> V_49 = false ;
V_3 -> V_8 = V_8 ;
F_71 ( & V_3 -> V_50 ) ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ )
F_72 ( & V_3 -> V_11 [ V_32 ] ) ;
V_33 = F_73 ( V_8 , F_17 , V_3 ) ;
if ( V_33 )
F_74 ( V_3 ) ;
else
V_8 -> V_120 |= V_134 ;
return V_33 ;
}
static void F_57 ( struct V_19 * V_8 )
{
struct V_2 * V_3 = F_75 ( V_8 ) ;
V_8 -> V_120 &= ~ V_134 ;
F_76 ( V_8 ) ;
F_77 ( V_3 , V_135 ) ;
}
static int F_78 ( struct V_136 * V_137 [] , struct V_136 * V_59 [] )
{
if ( V_137 [ V_138 ] ) {
if ( F_79 ( V_137 [ V_138 ] ) != V_13 )
return - V_86 ;
if ( ! F_44 ( F_80 ( V_137 [ V_138 ] ) ) )
return - V_82 ;
}
if ( V_59 && V_59 [ V_139 ] ) {
switch ( F_81 ( V_59 [ V_139 ] ) ) {
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
int F_82 ( struct V_140 * V_141 , struct V_19 * V_8 ,
struct V_136 * V_137 [] , struct V_136 * V_59 [] ,
int (* V_27)( struct V_14 * V_15 ) ,
int (* V_21)( struct V_19 * V_8 ,
struct V_14 * V_15 ) )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
struct V_2 * V_3 ;
struct V_19 * V_62 ;
int V_33 ;
if ( ! V_137 [ V_142 ] )
return - V_86 ;
V_62 = F_83 ( V_141 , F_81 ( V_137 [ V_142 ] ) ) ;
if ( V_62 == NULL )
return - V_143 ;
if ( V_62 -> V_144 == V_8 -> V_144 ) {
struct V_1 * V_145 = F_25 ( V_62 ) ;
V_62 = V_145 -> V_62 ;
}
if ( ! V_137 [ V_146 ] )
V_8 -> V_85 = V_62 -> V_85 ;
else if ( V_8 -> V_85 > V_62 -> V_85 )
return - V_86 ;
if ( ! V_137 [ V_138 ] )
F_84 ( V_8 -> V_9 ) ;
if ( ! F_85 ( V_62 ) ) {
V_33 = F_69 ( V_62 ) ;
if ( V_33 < 0 )
return V_33 ;
}
V_3 = F_75 ( V_62 ) ;
if ( V_3 -> V_49 )
return - V_86 ;
V_5 -> V_62 = V_62 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_27 = V_27 ;
V_5 -> V_21 = V_21 ;
V_5 -> V_30 = V_46 ;
if ( V_59 && V_59 [ V_139 ] )
V_5 -> V_30 = F_81 ( V_59 [ V_139 ] ) ;
if ( V_5 -> V_30 == V_47 ) {
if ( V_3 -> V_104 )
return - V_86 ;
V_3 -> V_49 = true ;
memcpy ( V_8 -> V_9 , V_62 -> V_9 , V_13 ) ;
}
V_3 -> V_104 += 1 ;
V_33 = F_86 ( V_8 ) ;
if ( V_33 < 0 )
goto V_147;
F_87 ( & V_5 -> V_51 , & V_3 -> V_50 ) ;
F_88 ( V_62 , V_8 ) ;
return 0 ;
V_147:
V_3 -> V_104 -= 1 ;
if ( ! V_3 -> V_104 )
F_57 ( V_62 ) ;
return V_33 ;
}
static int F_89 ( struct V_140 * V_141 , struct V_19 * V_8 ,
struct V_136 * V_137 [] , struct V_136 * V_59 [] )
{
return F_82 ( V_141 , V_8 , V_137 , V_59 ,
V_148 ,
V_149 ) ;
}
void F_90 ( struct V_19 * V_8 , struct V_150 * V_151 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
F_91 ( & V_5 -> V_51 ) ;
F_92 ( V_8 , V_151 ) ;
}
static int F_93 ( struct V_19 * V_8 ,
struct V_136 * V_137 [] , struct V_136 * V_59 [] )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
if ( V_59 && V_59 [ V_139 ] )
V_5 -> V_30 = F_81 ( V_59 [ V_139 ] ) ;
return 0 ;
}
static T_6 F_94 ( const struct V_19 * V_8 )
{
return F_95 ( 4 ) ;
}
static int F_96 ( struct V_14 * V_15 ,
const struct V_19 * V_8 )
{
struct V_1 * V_5 = F_25 ( V_8 ) ;
F_97 ( V_15 , V_139 , V_5 -> V_30 ) ;
return 0 ;
V_152:
return - V_153 ;
}
int F_98 ( struct V_144 * V_154 )
{
V_154 -> V_155 = sizeof( struct V_1 ) ;
V_154 -> V_156 = F_78 ;
V_154 -> V_157 = V_158 ;
V_154 -> V_159 = V_160 ;
V_154 -> V_161 = F_93 ;
V_154 -> V_162 = F_94 ;
V_154 -> V_163 = F_96 ;
return F_99 ( V_154 ) ;
}
static int F_100 ( struct V_164 * V_165 ,
unsigned long V_166 , void * V_167 )
{
struct V_19 * V_8 = V_167 ;
struct V_1 * V_5 , * V_168 ;
struct V_2 * V_3 ;
F_101 ( V_169 ) ;
if ( ! F_85 ( V_8 ) )
return V_170 ;
V_3 = F_75 ( V_8 ) ;
switch ( V_166 ) {
case V_171 :
F_102 (vlan, &port->vlans, list)
F_88 ( V_5 -> V_62 ,
V_5 -> V_8 ) ;
break;
case V_172 :
F_102 (vlan, &port->vlans, list) {
V_5 -> V_8 -> V_96 = V_8 -> V_96 & V_97 ;
V_5 -> V_8 -> V_99 = V_8 -> V_99 ;
F_103 ( V_5 -> V_8 ) ;
}
break;
case V_173 :
if ( V_8 -> V_174 != V_175 )
break;
F_104 (vlan, next, &port->vlans, list)
V_5 -> V_8 -> V_144 -> V_176 ( V_5 -> V_8 , & V_169 ) ;
F_105 ( & V_169 ) ;
F_91 ( & V_169 ) ;
break;
case V_177 :
return V_178 ;
}
return V_170 ;
}
static int T_7 F_106 ( void )
{
int V_33 ;
F_107 ( & V_179 ) ;
V_33 = F_98 ( & V_180 ) ;
if ( V_33 < 0 )
goto V_181;
return 0 ;
V_181:
F_108 ( & V_179 ) ;
return V_33 ;
}
static void T_8 F_109 ( void )
{
F_110 ( & V_180 ) ;
F_108 ( & V_179 ) ;
}
