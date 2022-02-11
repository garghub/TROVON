void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 -> V_5 = V_4 -> V_5 - V_2 -> V_6 ;
}
void F_2 ( struct V_7 * V_8 , T_1 V_9 )
{
struct V_1 * V_2 ;
if ( V_8 -> V_10 != V_9 ) {
F_3 (ipvlan, &port->ipvlans, pnode) {
if ( V_9 == V_11 )
V_2 -> V_4 -> V_12 |= V_13 ;
else
V_2 -> V_4 -> V_12 &= ~ V_13 ;
}
V_8 -> V_10 = V_9 ;
}
}
static int F_4 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
int V_14 , V_15 ;
if ( V_4 -> type != V_16 || V_4 -> V_12 & V_17 ) {
F_5 ( V_4 , L_1 ) ;
return - V_18 ;
}
if ( F_6 ( V_4 ) ) {
F_5 ( V_4 , L_2 ) ;
return - V_19 ;
}
V_8 = F_7 ( sizeof( struct V_7 ) , V_20 ) ;
if ( ! V_8 )
return - V_21 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_10 = V_11 ;
F_8 ( & V_8 -> V_22 ) ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ )
F_9 ( & V_8 -> V_24 [ V_15 ] ) ;
V_14 = F_10 ( V_4 , V_25 , V_8 ) ;
if ( V_14 )
goto V_14;
V_4 -> V_26 |= V_27 ;
return 0 ;
V_14:
F_11 ( V_8 , V_28 ) ;
return V_14 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_13 ( V_4 ) ;
V_4 -> V_26 &= ~ V_27 ;
F_14 ( V_4 ) ;
F_11 ( V_8 , V_28 ) ;
}
static void F_15 ( struct V_3 * V_4 ,
struct V_29 * V_30 ,
void * V_31 )
{
F_16 ( & V_30 -> V_32 , & V_33 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
F_16 ( & V_4 -> V_34 , & V_35 ) ;
F_18 ( V_4 , F_15 , NULL ) ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
const struct V_3 * V_36 = V_2 -> V_36 ;
V_4 -> V_37 = ( V_4 -> V_37 & ~ V_38 ) |
( V_36 -> V_37 & V_38 ) ;
V_4 -> V_39 = V_36 -> V_39 & V_40 ;
V_4 -> V_39 |= V_41 ;
V_4 -> V_42 = V_36 -> V_42 ;
V_4 -> V_43 = V_36 -> V_44 ;
V_4 -> V_45 = V_36 -> V_45 ;
F_17 ( V_4 ) ;
V_2 -> V_46 = F_21 ( struct V_47 ) ;
if ( ! V_2 -> V_46 )
return - V_21 ;
return 0 ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_23 ( V_2 -> V_46 ) ;
V_8 -> V_48 -= 1 ;
if ( ! V_8 -> V_48 )
F_12 ( V_8 -> V_4 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
struct V_49 * V_50 ;
if ( V_2 -> V_8 -> V_10 == V_11 )
V_4 -> V_12 |= V_13 ;
else
V_4 -> V_12 &= ~ V_13 ;
if ( V_2 -> V_51 > 0 || V_2 -> V_52 > 0 ) {
F_3 (addr, &ipvlan->addrs, anode)
F_25 ( V_2 , V_50 ) ;
}
return F_26 ( V_36 , V_36 -> V_53 ) ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
struct V_49 * V_50 ;
F_28 ( V_36 , V_4 ) ;
F_29 ( V_36 , V_4 ) ;
F_30 ( V_36 , V_36 -> V_53 ) ;
if ( V_2 -> V_51 > 0 || V_2 -> V_52 > 0 ) {
F_3 (addr, &ipvlan->addrs, anode)
F_31 ( V_50 , ! V_4 -> V_54 ) ;
}
return 0 ;
}
static T_2 F_32 ( struct V_55 * V_56 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
int V_57 = V_56 -> V_58 ;
int V_59 ;
V_59 = F_33 ( V_56 , V_4 ) ;
if ( F_34 ( V_59 == V_60 || V_59 == V_61 ) ) {
struct V_47 * V_62 ;
V_62 = F_35 ( V_2 -> V_46 ) ;
F_36 ( & V_62 -> V_63 ) ;
V_62 -> V_64 ++ ;
V_62 -> V_65 += V_57 ;
F_37 ( & V_62 -> V_63 ) ;
} else {
F_38 ( V_2 -> V_46 -> V_66 ) ;
}
return V_59 ;
}
static T_3 F_39 ( struct V_3 * V_4 ,
T_3 V_39 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
return V_39 & ( V_2 -> V_67 | ~ V_40 ) ;
}
static void F_40 ( struct V_3 * V_4 , int V_68 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
if ( V_68 & V_69 )
F_41 ( V_36 , V_4 -> V_12 & V_69 ? 1 : - 1 ) ;
}
static void F_42 ( struct V_1 * V_2 , bool V_70 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_71 = F_43 ( V_4 -> V_72 ) ;
if ( V_70 && ! F_44 ( V_71 , V_2 -> V_73 ) )
F_45 ( V_71 , V_2 -> V_73 ) ;
else if ( ! V_70 && F_44 ( V_71 , V_2 -> V_73 ) )
F_46 ( V_71 , V_2 -> V_73 ) ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( V_4 -> V_12 & ( V_74 | V_69 ) ) {
F_48 ( V_2 -> V_73 , V_75 ) ;
} else {
struct V_76 * V_77 ;
F_49 ( V_78 , V_75 ) ;
F_50 ( V_78 , V_75 ) ;
F_51 (ha, dev)
F_45 ( F_43 ( V_77 -> V_50 ) , V_78 ) ;
F_52 ( V_2 -> V_73 , V_78 ,
V_75 ) ;
}
F_53 ( V_2 -> V_36 , V_4 ) ;
F_54 ( V_2 -> V_36 , V_4 ) ;
}
static struct V_79 * F_55 ( struct V_3 * V_4 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( V_2 -> V_46 ) {
struct V_47 * V_62 ;
T_4 V_81 , V_82 , V_83 , V_64 , V_65 ;
T_1 V_84 = 0 , V_66 = 0 ;
T_1 V_85 ;
int V_15 ;
F_56 (idx) {
V_62 = F_57 ( V_2 -> V_46 , V_15 ) ;
do {
V_85 = F_58 ( & V_62 -> V_63 ) ;
V_81 = V_62 -> V_81 ;
V_82 = V_62 -> V_82 ;
V_83 = V_62 -> V_83 ;
V_64 = V_62 -> V_64 ;
V_65 = V_62 -> V_65 ;
} while ( F_59 ( & V_62 -> V_63 ,
V_85 ) );
V_80 -> V_86 += V_81 ;
V_80 -> V_82 += V_82 ;
V_80 -> V_87 += V_83 ;
V_80 -> V_88 += V_64 ;
V_80 -> V_65 += V_65 ;
V_84 += V_62 -> V_84 ;
V_66 += V_62 -> V_66 ;
}
V_80 -> V_89 = V_84 ;
V_80 -> V_90 = V_84 ;
V_80 -> V_91 = V_66 ;
}
return V_80 ;
}
static int F_60 ( struct V_3 * V_4 , T_5 V_92 , T_6 V_93 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
return F_61 ( V_36 , V_92 , V_93 ) ;
}
static int F_62 ( struct V_3 * V_4 , T_5 V_92 ,
T_6 V_93 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
F_63 ( V_36 , V_92 , V_93 ) ;
return 0 ;
}
static int F_64 ( struct V_55 * V_56 , struct V_3 * V_4 ,
unsigned short type , const void * V_94 ,
const void * V_95 , unsigned V_58 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
return F_65 ( V_56 , V_36 , type , V_94 ,
V_95 ? : V_4 -> V_53 , V_58 ) ;
}
static int F_66 ( struct V_3 * V_4 ,
struct V_96 * V_97 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
return F_67 ( V_2 -> V_36 , V_97 ) ;
}
static void F_68 ( struct V_3 * V_4 ,
struct V_98 * V_99 )
{
F_69 ( V_99 -> V_100 , V_101 , sizeof( V_99 -> V_100 ) ) ;
F_69 ( V_99 -> V_102 , V_103 , sizeof( V_99 -> V_102 ) ) ;
}
static T_1 F_70 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
return V_2 -> V_104 ;
}
static void F_71 ( struct V_3 * V_4 , T_1 V_105 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
V_2 -> V_104 = V_105 ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_106 * V_107 [] , struct V_106 * V_108 [] )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = F_13 ( V_2 -> V_36 ) ;
if ( V_108 && V_108 [ V_109 ] ) {
T_6 V_110 = F_73 ( V_108 [ V_109 ] ) ;
F_2 ( V_8 , V_110 ) ;
}
return 0 ;
}
static T_7 F_74 ( const struct V_3 * V_4 )
{
return ( 0
+ F_75 ( 2 )
) ;
}
static int F_76 ( struct V_106 * V_107 [] , struct V_106 * V_108 [] )
{
if ( V_108 && V_108 [ V_109 ] ) {
T_6 V_10 = F_73 ( V_108 [ V_109 ] ) ;
if ( V_10 < V_111 || V_10 >= V_112 )
return - V_18 ;
}
return 0 ;
}
static int F_77 ( struct V_55 * V_56 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = F_13 ( V_2 -> V_36 ) ;
int V_59 = - V_18 ;
if ( ! V_8 )
goto V_14;
V_59 = - V_113 ;
if ( F_78 ( V_56 , V_109 , V_8 -> V_10 ) )
goto V_14;
return 0 ;
V_14:
return V_59 ;
}
static int F_79 ( struct V_114 * V_115 , struct V_3 * V_4 ,
struct V_106 * V_107 [] , struct V_106 * V_108 [] )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_3 * V_36 ;
int V_14 ;
if ( ! V_107 [ V_116 ] )
return - V_18 ;
V_36 = F_80 ( V_115 , F_81 ( V_107 [ V_116 ] ) ) ;
if ( ! V_36 )
return - V_117 ;
if ( F_82 ( V_36 ) ) {
struct V_1 * V_118 = F_20 ( V_36 ) ;
V_36 = V_118 -> V_36 ;
} else if ( ! F_83 ( V_36 ) ) {
V_14 = F_4 ( V_36 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_8 = F_13 ( V_36 ) ;
if ( V_108 && V_108 [ V_109 ] )
V_8 -> V_10 = F_73 ( V_108 [ V_109 ] ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_67 = V_40 ;
F_8 ( & V_2 -> V_119 ) ;
V_2 -> V_52 = 0 ;
V_2 -> V_51 = 0 ;
memcpy ( V_4 -> V_53 , V_36 -> V_53 , V_120 ) ;
V_4 -> V_26 |= V_121 ;
V_8 -> V_48 += 1 ;
V_14 = F_84 ( V_4 ) ;
if ( V_14 < 0 )
goto V_122;
V_14 = F_85 ( V_36 , V_4 ) ;
if ( V_14 )
goto V_122;
F_86 ( & V_2 -> V_123 , & V_8 -> V_22 ) ;
F_87 ( V_36 , V_4 ) ;
return 0 ;
V_122:
V_8 -> V_48 -= 1 ;
if ( ! V_8 -> V_48 )
F_12 ( V_36 ) ;
return V_14 ;
}
static void F_88 ( struct V_3 * V_4 , struct V_124 * V_125 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_49 * V_50 , * V_126 ;
if ( V_2 -> V_51 > 0 || V_2 -> V_52 > 0 ) {
F_89 (addr, next, &ipvlan->addrs, anode) {
F_31 ( V_50 , ! V_4 -> V_54 ) ;
F_90 ( & V_50 -> V_127 ) ;
}
}
F_91 ( & V_2 -> V_123 ) ;
F_92 ( V_4 , V_125 ) ;
F_93 ( V_2 -> V_36 , V_4 ) ;
}
static void F_94 ( struct V_3 * V_4 )
{
F_95 ( V_4 ) ;
V_4 -> V_26 &= ~ ( V_128 | V_129 ) ;
V_4 -> V_26 |= V_130 ;
V_4 -> V_131 = & V_132 ;
V_4 -> V_133 = V_134 ;
V_4 -> V_135 = & V_136 ;
V_4 -> V_137 = & V_138 ;
V_4 -> V_139 = 0 ;
}
static int F_96 ( struct V_140 * V_141 )
{
return F_97 ( V_141 ) ;
}
static int F_98 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
struct V_3 * V_4 = F_99 ( V_145 ) ;
struct V_1 * V_2 , * V_126 ;
struct V_7 * V_8 ;
F_100 ( V_146 ) ;
if ( ! F_83 ( V_4 ) )
return V_147 ;
V_8 = F_13 ( V_4 ) ;
switch ( V_144 ) {
case V_148 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_87 ( V_2 -> V_36 ,
V_2 -> V_4 ) ;
break;
case V_149 :
if ( V_4 -> V_150 != V_151 )
break;
F_89 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_140 -> V_152 ( V_2 -> V_4 ,
& V_146 ) ;
F_101 ( & V_146 ) ;
break;
case V_153 :
F_3 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_39 = V_4 -> V_39 & V_40 ;
V_2 -> V_4 -> V_42 = V_4 -> V_42 ;
F_102 ( V_2 -> V_4 ) ;
}
break;
case V_154 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_155 :
return V_156 ;
}
return V_147 ;
}
static int F_103 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
struct V_49 * V_50 ;
if ( F_104 ( V_2 -> V_8 , V_158 , true ) ) {
F_105 ( V_2 , V_159 , V_2 -> V_4 ,
L_3 ,
V_158 , V_2 -> V_4 -> V_160 ) ;
return - V_18 ;
}
V_50 = F_7 ( sizeof( struct V_49 ) , V_161 ) ;
if ( ! V_50 )
return - V_21 ;
V_50 -> V_162 = V_2 ;
memcpy ( & V_50 -> V_163 , V_158 , sizeof( struct V_157 ) ) ;
V_50 -> V_164 = V_165 ;
F_106 ( & V_50 -> V_127 , & V_2 -> V_119 ) ;
V_2 -> V_51 ++ ;
if ( F_107 ( V_2 -> V_4 ) )
F_25 ( V_2 , V_50 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
struct V_49 * V_50 ;
V_50 = F_109 ( V_2 , V_158 , true ) ;
if ( ! V_50 )
return;
F_31 ( V_50 , true ) ;
F_90 ( & V_50 -> V_127 ) ;
V_2 -> V_51 -- ;
F_110 ( V_2 -> V_51 < 0 ) ;
F_11 ( V_50 , V_28 ) ;
return;
}
static int F_111 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
struct V_166 * V_167 = (struct V_166 * ) V_145 ;
struct V_3 * V_4 = (struct V_3 * ) V_167 -> V_168 -> V_4 ;
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( ! F_82 ( V_4 ) )
return V_147 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_147 ;
switch ( V_144 ) {
case V_169 :
if ( F_103 ( V_2 , & V_167 -> V_50 ) )
return V_156 ;
break;
case V_170 :
F_108 ( V_2 , & V_167 -> V_50 ) ;
break;
}
return V_171 ;
}
static int F_112 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
struct V_49 * V_50 ;
if ( F_104 ( V_2 -> V_8 , V_173 , false ) ) {
F_105 ( V_2 , V_159 , V_2 -> V_4 ,
L_4 ,
V_173 , V_2 -> V_4 -> V_160 ) ;
return - V_18 ;
}
V_50 = F_7 ( sizeof( struct V_49 ) , V_20 ) ;
if ( ! V_50 )
return - V_21 ;
V_50 -> V_162 = V_2 ;
memcpy ( & V_50 -> V_174 , V_173 , sizeof( struct V_172 ) ) ;
V_50 -> V_164 = V_175 ;
F_106 ( & V_50 -> V_127 , & V_2 -> V_119 ) ;
V_2 -> V_52 ++ ;
if ( F_107 ( V_2 -> V_4 ) )
F_25 ( V_2 , V_50 ) ;
F_42 ( V_2 , true ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
struct V_49 * V_50 ;
V_50 = F_109 ( V_2 , V_173 , false ) ;
if ( ! V_50 )
return;
F_31 ( V_50 , true ) ;
F_90 ( & V_50 -> V_127 ) ;
V_2 -> V_52 -- ;
F_110 ( V_2 -> V_52 < 0 ) ;
if ( ! V_2 -> V_52 )
F_42 ( V_2 , false ) ;
F_11 ( V_50 , V_28 ) ;
return;
}
static int F_114 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
struct V_176 * V_177 = (struct V_176 * ) V_145 ;
struct V_3 * V_4 = (struct V_3 * ) V_177 -> V_178 -> V_4 ;
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_172 V_173 ;
if ( ! F_82 ( V_4 ) )
return V_147 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_147 ;
switch ( V_144 ) {
case V_169 :
V_173 . V_179 = V_177 -> V_180 ;
if ( F_112 ( V_2 , & V_173 ) )
return V_156 ;
break;
case V_170 :
V_173 . V_179 = V_177 -> V_180 ;
F_113 ( V_2 , & V_173 ) ;
break;
}
return V_171 ;
}
static int T_8 F_115 ( void )
{
int V_14 ;
F_116 () ;
F_117 ( & V_181 ) ;
F_118 ( & V_182 ) ;
F_119 ( & V_183 ) ;
V_14 = F_96 ( & V_184 ) ;
if ( V_14 < 0 )
goto error;
return 0 ;
error:
F_120 ( & V_183 ) ;
F_121 ( & V_182 ) ;
F_122 ( & V_181 ) ;
return V_14 ;
}
static void T_9 F_123 ( void )
{
F_124 ( & V_184 ) ;
F_122 ( & V_181 ) ;
F_120 ( & V_183 ) ;
F_121 ( & V_182 ) ;
}
