static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 -> V_5 = V_4 -> V_5 - V_2 -> V_6 ;
}
static int F_2 ( void )
{
int V_7 = 0 ;
if ( ! V_8 ) {
V_7 = F_3 ( V_9 , F_4 ( V_9 ) ) ;
if ( ! V_7 )
V_8 = 1 ;
} else {
V_8 ++ ;
}
return V_7 ;
}
static void F_5 ( void )
{
F_6 ( ! V_8 ) ;
V_8 -- ;
if ( ! V_8 )
F_7 ( V_9 , F_4 ( V_9 ) ) ;
}
static int F_8 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_1 * V_2 ;
struct V_3 * V_13 = V_11 -> V_4 ;
int V_7 = 0 ;
F_9 () ;
if ( V_11 -> V_14 != V_12 ) {
if ( V_12 == V_15 ) {
V_7 = F_2 () ;
if ( ! V_7 ) {
V_13 -> V_16 = & V_17 ;
V_13 -> V_18 |= V_19 ;
} else
return V_7 ;
} else if ( V_11 -> V_14 == V_15 ) {
V_13 -> V_18 &= ~ V_19 ;
F_5 () ;
V_13 -> V_16 = NULL ;
}
F_10 (ipvlan, &port->ipvlans, pnode) {
if ( V_12 == V_20 || V_12 == V_15 )
V_2 -> V_4 -> V_21 |= V_22 ;
else
V_2 -> V_4 -> V_21 &= ~ V_22 ;
}
V_11 -> V_14 = V_12 ;
}
return V_7 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_10 * V_11 ;
int V_7 , V_23 ;
if ( V_4 -> type != V_24 || V_4 -> V_21 & V_25 ) {
F_12 ( V_4 , L_1 ) ;
return - V_26 ;
}
if ( F_13 ( V_4 ) ) {
F_12 ( V_4 , L_2 ) ;
return - V_27 ;
}
V_11 = F_14 ( sizeof( struct V_10 ) , V_28 ) ;
if ( ! V_11 )
return - V_29 ;
V_11 -> V_4 = V_4 ;
V_11 -> V_14 = V_20 ;
F_15 ( & V_11 -> V_30 ) ;
for ( V_23 = 0 ; V_23 < V_31 ; V_23 ++ )
F_16 ( & V_11 -> V_32 [ V_23 ] ) ;
F_17 ( & V_11 -> V_33 ) ;
F_18 ( & V_11 -> V_34 , V_35 ) ;
V_7 = F_19 ( V_4 , V_36 , V_11 ) ;
if ( V_7 )
goto V_7;
V_4 -> V_18 |= V_37 ;
return 0 ;
V_7:
F_20 ( V_11 , V_38 ) ;
return V_7 ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_22 ( V_4 ) ;
V_4 -> V_18 &= ~ V_37 ;
if ( V_11 -> V_14 == V_15 ) {
V_4 -> V_18 &= ~ V_19 ;
F_5 () ;
V_4 -> V_16 = NULL ;
}
F_23 ( V_4 ) ;
F_24 ( & V_11 -> V_34 ) ;
F_25 ( & V_11 -> V_33 ) ;
F_20 ( V_11 , V_38 ) ;
}
static int F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
const struct V_3 * V_39 = V_2 -> V_39 ;
struct V_10 * V_11 = V_2 -> V_11 ;
V_4 -> V_40 = ( V_4 -> V_40 & ~ V_41 ) |
( V_39 -> V_40 & V_41 ) ;
V_4 -> V_42 = V_39 -> V_42 & V_43 ;
V_4 -> V_42 |= V_44 ;
V_4 -> V_45 = V_39 -> V_45 ;
V_4 -> V_46 = V_39 -> V_46 ;
V_4 -> V_47 = V_39 -> V_47 ;
F_28 ( V_4 ) ;
V_2 -> V_48 = F_29 ( struct V_49 ) ;
if ( ! V_2 -> V_48 )
return - V_29 ;
V_11 -> V_50 += 1 ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_10 * V_11 = V_2 -> V_11 ;
F_31 ( V_2 -> V_48 ) ;
V_11 -> V_50 -= 1 ;
if ( ! V_11 -> V_50 )
F_21 ( V_11 -> V_4 ) ;
}
static int F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
struct V_51 * V_52 ;
if ( V_2 -> V_11 -> V_14 == V_20 ||
V_2 -> V_11 -> V_14 == V_15 )
V_4 -> V_21 |= V_22 ;
else
V_4 -> V_21 &= ~ V_22 ;
F_10 (addr, &ipvlan->addrs, anode)
F_33 ( V_2 , V_52 ) ;
return F_34 ( V_39 , V_39 -> V_53 ) ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
struct V_51 * V_52 ;
F_36 ( V_39 , V_4 ) ;
F_37 ( V_39 , V_4 ) ;
F_38 ( V_39 , V_39 -> V_53 ) ;
F_10 (addr, &ipvlan->addrs, anode)
F_39 ( V_52 ) ;
return 0 ;
}
static T_2 F_40 ( struct V_54 * V_55 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_27 ( V_4 ) ;
int V_56 = V_55 -> V_57 ;
int V_58 ;
V_58 = F_41 ( V_55 , V_4 ) ;
if ( F_42 ( V_58 == V_59 || V_58 == V_60 ) ) {
struct V_49 * V_61 ;
V_61 = F_43 ( V_2 -> V_48 ) ;
F_44 ( & V_61 -> V_62 ) ;
V_61 -> V_63 ++ ;
V_61 -> V_64 += V_56 ;
F_45 ( & V_61 -> V_62 ) ;
} else {
F_46 ( V_2 -> V_48 -> V_65 ) ;
}
return V_58 ;
}
static T_3 F_47 ( struct V_3 * V_4 ,
T_3 V_42 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
return V_42 & ( V_2 -> V_66 | ~ V_43 ) ;
}
static void F_48 ( struct V_3 * V_4 , int V_67 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
if ( V_67 & V_68 )
F_49 ( V_39 , V_4 -> V_21 & V_68 ? 1 : - 1 ) ;
}
static void F_50 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
if ( V_4 -> V_21 & ( V_69 | V_68 ) ) {
F_51 ( V_2 -> V_70 , V_71 ) ;
} else {
struct V_72 * V_73 ;
F_52 ( V_74 , V_71 ) ;
F_53 ( V_74 , V_71 ) ;
F_54 (ha, dev)
F_55 ( F_56 ( V_73 -> V_52 ) , V_74 ) ;
F_55 ( F_56 ( V_4 -> V_75 ) , V_74 ) ;
F_57 ( V_2 -> V_70 , V_74 ,
V_71 ) ;
}
F_58 ( V_2 -> V_39 , V_4 ) ;
F_59 ( V_2 -> V_39 , V_4 ) ;
}
static struct V_76 * F_60 ( struct V_3 * V_4 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
if ( V_2 -> V_48 ) {
struct V_49 * V_61 ;
T_4 V_78 , V_79 , V_80 , V_63 , V_64 ;
T_5 V_81 = 0 , V_65 = 0 ;
T_5 V_82 ;
int V_23 ;
F_61 (idx) {
V_61 = F_62 ( V_2 -> V_48 , V_23 ) ;
do {
V_82 = F_63 ( & V_61 -> V_62 ) ;
V_78 = V_61 -> V_78 ;
V_79 = V_61 -> V_79 ;
V_80 = V_61 -> V_80 ;
V_63 = V_61 -> V_63 ;
V_64 = V_61 -> V_64 ;
} while ( F_64 ( & V_61 -> V_62 ,
V_82 ) );
V_77 -> V_83 += V_78 ;
V_77 -> V_79 += V_79 ;
V_77 -> V_84 += V_80 ;
V_77 -> V_85 += V_63 ;
V_77 -> V_64 += V_64 ;
V_81 += V_61 -> V_81 ;
V_65 += V_61 -> V_65 ;
}
V_77 -> V_86 = V_81 ;
V_77 -> V_87 = V_81 ;
V_77 -> V_88 = V_65 ;
}
return V_77 ;
}
static int F_65 ( struct V_3 * V_4 , T_6 V_89 , T_1 V_90 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
return F_66 ( V_39 , V_89 , V_90 ) ;
}
static int F_67 ( struct V_3 * V_4 , T_6 V_89 ,
T_1 V_90 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
F_68 ( V_39 , V_89 , V_90 ) ;
return 0 ;
}
static int F_69 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
return V_2 -> V_39 -> V_91 ;
}
static int F_70 ( struct V_54 * V_55 , struct V_3 * V_4 ,
unsigned short type , const void * V_92 ,
const void * V_93 , unsigned V_57 )
{
const struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
return F_71 ( V_55 , V_39 , type , V_92 ,
V_93 ? : V_4 -> V_53 , V_57 ) ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_94 * V_95 )
{
const struct V_1 * V_2 = F_27 ( V_4 ) ;
return F_73 ( V_2 -> V_39 , V_95 ) ;
}
static void F_74 ( struct V_3 * V_4 ,
struct V_96 * V_97 )
{
F_75 ( V_97 -> V_98 , V_99 , sizeof( V_97 -> V_98 ) ) ;
F_75 ( V_97 -> V_100 , V_101 , sizeof( V_97 -> V_100 ) ) ;
}
static T_5 F_76 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_27 ( V_4 ) ;
return V_2 -> V_102 ;
}
static void F_77 ( struct V_3 * V_4 , T_5 V_103 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
V_2 -> V_102 = V_103 ;
}
static int F_78 ( struct V_3 * V_4 ,
struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_10 * V_11 = F_22 ( V_2 -> V_39 ) ;
int V_7 = 0 ;
if ( V_106 && V_106 [ V_107 ] ) {
T_1 V_108 = F_79 ( V_106 [ V_107 ] ) ;
V_7 = F_8 ( V_11 , V_108 ) ;
}
return V_7 ;
}
static T_7 F_80 ( const struct V_3 * V_4 )
{
return ( 0
+ F_81 ( 2 )
) ;
}
static int F_82 ( struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
if ( V_106 && V_106 [ V_107 ] ) {
T_1 V_14 = F_79 ( V_106 [ V_107 ] ) ;
if ( V_14 < V_109 || V_14 >= V_110 )
return - V_26 ;
}
return 0 ;
}
static int F_83 ( struct V_54 * V_55 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_10 * V_11 = F_22 ( V_2 -> V_39 ) ;
int V_58 = - V_26 ;
if ( ! V_11 )
goto V_7;
V_58 = - V_111 ;
if ( F_84 ( V_55 , V_107 , V_11 -> V_14 ) )
goto V_7;
return 0 ;
V_7:
return V_58 ;
}
static int F_85 ( struct V_112 * V_113 , struct V_3 * V_4 ,
struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_10 * V_11 ;
struct V_3 * V_39 ;
int V_7 ;
T_1 V_14 = V_20 ;
bool V_114 = false ;
if ( ! V_105 [ V_115 ] )
return - V_26 ;
V_39 = F_86 ( V_113 , F_87 ( V_105 [ V_115 ] ) ) ;
if ( ! V_39 )
return - V_116 ;
if ( F_88 ( V_39 ) ) {
struct V_1 * V_117 = F_27 ( V_39 ) ;
V_39 = V_117 -> V_39 ;
} else if ( ! F_89 ( V_39 ) ) {
V_7 = F_11 ( V_39 ) ;
if ( V_7 < 0 )
return V_7 ;
V_114 = true ;
}
if ( V_106 && V_106 [ V_107 ] )
V_14 = F_79 ( V_106 [ V_107 ] ) ;
V_11 = F_22 ( V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_66 = V_43 ;
F_1 ( V_2 , V_39 ) ;
F_15 ( & V_2 -> V_118 ) ;
memcpy ( V_4 -> V_53 , V_39 -> V_53 , V_119 ) ;
V_4 -> V_18 |= V_120 ;
V_7 = F_90 ( V_4 ) ;
if ( V_7 < 0 )
goto V_121;
V_7 = F_91 ( V_39 , V_4 ) ;
if ( V_7 ) {
goto V_122;
}
V_7 = F_8 ( V_11 , V_14 ) ;
if ( V_7 ) {
goto V_123;
}
F_92 ( & V_2 -> V_124 , & V_11 -> V_30 ) ;
F_93 ( V_39 , V_4 ) ;
return 0 ;
V_123:
F_94 ( V_39 , V_4 ) ;
V_122:
F_95 ( V_4 ) ;
V_121:
if ( V_114 )
F_21 ( V_39 ) ;
return V_7 ;
}
static void F_96 ( struct V_3 * V_4 , struct V_125 * V_126 )
{
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_51 * V_52 , * V_127 ;
F_97 (addr, next, &ipvlan->addrs, anode) {
F_39 ( V_52 ) ;
F_98 ( & V_52 -> V_128 ) ;
F_20 ( V_52 , V_38 ) ;
}
F_99 ( & V_2 -> V_124 ) ;
F_100 ( V_4 , V_126 ) ;
F_94 ( V_2 -> V_39 , V_4 ) ;
}
static void F_101 ( struct V_3 * V_4 )
{
F_102 ( V_4 ) ;
V_4 -> V_18 &= ~ ( V_129 | V_130 ) ;
V_4 -> V_18 |= V_131 | V_132 ;
V_4 -> V_133 = & V_134 ;
V_4 -> V_135 = V_136 ;
V_4 -> V_137 = & V_138 ;
V_4 -> V_139 = & V_140 ;
}
static int F_103 ( struct V_141 * V_142 )
{
return F_104 ( V_142 ) ;
}
static int F_105 ( struct V_143 * V_144 ,
unsigned long V_145 , void * V_146 )
{
struct V_3 * V_4 = F_106 ( V_146 ) ;
struct V_1 * V_2 , * V_127 ;
struct V_10 * V_11 ;
F_107 ( V_147 ) ;
if ( ! F_89 ( V_4 ) )
return V_148 ;
V_11 = F_22 ( V_4 ) ;
switch ( V_145 ) {
case V_149 :
F_10 (ipvlan, &port->ipvlans, pnode)
F_93 ( V_2 -> V_39 ,
V_2 -> V_4 ) ;
break;
case V_150 :
if ( V_4 -> V_151 != V_152 )
break;
F_97 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_141 -> V_153 ( V_2 -> V_4 ,
& V_147 ) ;
F_108 ( & V_147 ) ;
break;
case V_154 :
F_10 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_42 = V_4 -> V_42 & V_43 ;
V_2 -> V_4 -> V_45 = V_4 -> V_45 ;
V_2 -> V_4 -> V_46 = V_4 -> V_46 ;
F_109 ( V_2 -> V_4 ) ;
}
break;
case V_155 :
F_10 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_156 :
return V_157 ;
}
return V_148 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
struct V_51 * V_52 ;
if ( F_111 ( V_2 -> V_11 , V_159 , true ) ) {
F_112 ( V_2 , V_160 , V_2 -> V_4 ,
L_3 ,
V_159 , V_2 -> V_4 -> V_161 ) ;
return - V_26 ;
}
V_52 = F_14 ( sizeof( struct V_51 ) , V_162 ) ;
if ( ! V_52 )
return - V_29 ;
V_52 -> V_163 = V_2 ;
memcpy ( & V_52 -> V_164 , V_159 , sizeof( struct V_158 ) ) ;
V_52 -> V_165 = V_166 ;
F_113 ( & V_52 -> V_128 , & V_2 -> V_118 ) ;
if ( F_114 ( V_2 -> V_4 ) )
F_33 ( V_2 , V_52 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 , struct V_158 * V_159 )
{
struct V_51 * V_52 ;
V_52 = F_116 ( V_2 , V_159 , true ) ;
if ( ! V_52 )
return;
F_39 ( V_52 ) ;
F_98 ( & V_52 -> V_128 ) ;
F_20 ( V_52 , V_38 ) ;
return;
}
static int F_117 ( struct V_143 * V_144 ,
unsigned long V_145 , void * V_146 )
{
struct V_167 * V_168 = (struct V_167 * ) V_146 ;
struct V_3 * V_4 = (struct V_3 * ) V_168 -> V_169 -> V_4 ;
struct V_1 * V_2 = F_27 ( V_4 ) ;
if ( F_118 () )
return V_148 ;
if ( ! F_88 ( V_4 ) )
return V_148 ;
if ( ! V_2 || ! V_2 -> V_11 )
return V_148 ;
switch ( V_145 ) {
case V_170 :
if ( F_110 ( V_2 , & V_168 -> V_52 ) )
return V_157 ;
break;
case V_171 :
F_115 ( V_2 , & V_168 -> V_52 ) ;
break;
}
return V_172 ;
}
static int F_119 ( struct V_1 * V_2 , struct V_173 * V_174 )
{
struct V_51 * V_52 ;
if ( F_111 ( V_2 -> V_11 , V_174 , false ) ) {
F_112 ( V_2 , V_160 , V_2 -> V_4 ,
L_4 ,
V_174 , V_2 -> V_4 -> V_161 ) ;
return - V_26 ;
}
V_52 = F_14 ( sizeof( struct V_51 ) , V_28 ) ;
if ( ! V_52 )
return - V_29 ;
V_52 -> V_163 = V_2 ;
memcpy ( & V_52 -> V_175 , V_174 , sizeof( struct V_173 ) ) ;
V_52 -> V_165 = V_176 ;
F_113 ( & V_52 -> V_128 , & V_2 -> V_118 ) ;
if ( F_114 ( V_2 -> V_4 ) )
F_33 ( V_2 , V_52 ) ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 , struct V_173 * V_174 )
{
struct V_51 * V_52 ;
V_52 = F_116 ( V_2 , V_174 , false ) ;
if ( ! V_52 )
return;
F_39 ( V_52 ) ;
F_98 ( & V_52 -> V_128 ) ;
F_20 ( V_52 , V_38 ) ;
return;
}
static int F_121 ( struct V_143 * V_144 ,
unsigned long V_145 , void * V_146 )
{
struct V_177 * V_178 = (struct V_177 * ) V_146 ;
struct V_3 * V_4 = (struct V_3 * ) V_178 -> V_179 -> V_4 ;
struct V_1 * V_2 = F_27 ( V_4 ) ;
struct V_173 V_174 ;
if ( ! F_88 ( V_4 ) )
return V_148 ;
if ( ! V_2 || ! V_2 -> V_11 )
return V_148 ;
switch ( V_145 ) {
case V_170 :
V_174 . V_180 = V_178 -> V_181 ;
if ( F_119 ( V_2 , & V_174 ) )
return V_157 ;
break;
case V_171 :
V_174 . V_180 = V_178 -> V_181 ;
F_120 ( V_2 , & V_174 ) ;
break;
}
return V_172 ;
}
static int T_8 F_122 ( void )
{
int V_7 ;
F_123 () ;
F_124 ( & V_182 ) ;
F_125 ( & V_183 ) ;
F_126 ( & V_184 ) ;
V_7 = F_103 ( & V_185 ) ;
if ( V_7 < 0 )
goto error;
return 0 ;
error:
F_127 ( & V_184 ) ;
F_128 ( & V_183 ) ;
F_129 ( & V_182 ) ;
return V_7 ;
}
static void T_9 F_130 ( void )
{
F_131 ( & V_185 ) ;
F_129 ( & V_182 ) ;
F_127 ( & V_184 ) ;
F_128 ( & V_183 ) ;
}
