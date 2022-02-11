static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 -> V_5 = V_4 -> V_5 - V_2 -> V_6 ;
}
static void F_2 ( struct V_7 * V_8 , T_1 V_9 )
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
F_10 ( & V_8 -> V_25 ) ;
F_11 ( & V_8 -> V_26 , V_27 ) ;
V_14 = F_12 ( V_4 , V_28 , V_8 ) ;
if ( V_14 )
goto V_14;
V_4 -> V_29 |= V_30 ;
return 0 ;
V_14:
F_13 ( V_8 , V_31 ) ;
return V_14 ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_15 ( V_4 ) ;
V_4 -> V_29 &= ~ V_30 ;
F_16 ( V_4 ) ;
F_17 ( & V_8 -> V_26 ) ;
F_18 ( & V_8 -> V_25 ) ;
F_13 ( V_8 , V_31 ) ;
}
static void F_19 ( struct V_3 * V_4 ,
struct V_32 * V_33 ,
void * V_34 )
{
F_20 ( & V_33 -> V_35 , & V_36 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_20 ( & V_4 -> V_37 , & V_38 ) ;
F_22 ( V_4 , F_19 , NULL ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
const struct V_3 * V_39 = V_2 -> V_39 ;
V_4 -> V_40 = ( V_4 -> V_40 & ~ V_41 ) |
( V_39 -> V_40 & V_41 ) ;
V_4 -> V_42 = V_39 -> V_42 & V_43 ;
V_4 -> V_42 |= V_44 ;
V_4 -> V_45 = V_39 -> V_45 ;
V_4 -> V_46 = V_39 -> V_46 ;
V_4 -> V_47 = V_39 -> V_47 ;
F_21 ( V_4 ) ;
V_2 -> V_48 = F_25 ( struct V_49 ) ;
if ( ! V_2 -> V_48 )
return - V_21 ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_27 ( V_2 -> V_48 ) ;
V_8 -> V_50 -= 1 ;
if ( ! V_8 -> V_50 )
F_14 ( V_8 -> V_4 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
struct V_51 * V_52 ;
if ( V_2 -> V_8 -> V_10 == V_11 )
V_4 -> V_12 |= V_13 ;
else
V_4 -> V_12 &= ~ V_13 ;
F_3 (addr, &ipvlan->addrs, anode)
F_29 ( V_2 , V_52 ) ;
return F_30 ( V_39 , V_39 -> V_53 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
struct V_51 * V_52 ;
F_32 ( V_39 , V_4 ) ;
F_33 ( V_39 , V_4 ) ;
F_34 ( V_39 , V_39 -> V_53 ) ;
F_3 (addr, &ipvlan->addrs, anode)
F_35 ( V_52 ) ;
return 0 ;
}
static T_2 F_36 ( struct V_54 * V_55 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_24 ( V_4 ) ;
int V_56 = V_55 -> V_57 ;
int V_58 ;
V_58 = F_37 ( V_55 , V_4 ) ;
if ( F_38 ( V_58 == V_59 || V_58 == V_60 ) ) {
struct V_49 * V_61 ;
V_61 = F_39 ( V_2 -> V_48 ) ;
F_40 ( & V_61 -> V_62 ) ;
V_61 -> V_63 ++ ;
V_61 -> V_64 += V_56 ;
F_41 ( & V_61 -> V_62 ) ;
} else {
F_42 ( V_2 -> V_48 -> V_65 ) ;
}
return V_58 ;
}
static T_3 F_43 ( struct V_3 * V_4 ,
T_3 V_42 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
return V_42 & ( V_2 -> V_66 | ~ V_43 ) ;
}
static void F_44 ( struct V_3 * V_4 , int V_67 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
if ( V_67 & V_68 )
F_45 ( V_39 , V_4 -> V_12 & V_68 ? 1 : - 1 ) ;
}
static void F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
if ( V_4 -> V_12 & ( V_69 | V_68 ) ) {
F_47 ( V_2 -> V_70 , V_71 ) ;
} else {
struct V_72 * V_73 ;
F_48 ( V_74 , V_71 ) ;
F_49 ( V_74 , V_71 ) ;
F_50 (ha, dev)
F_51 ( F_52 ( V_73 -> V_52 ) , V_74 ) ;
F_51 ( F_52 ( V_4 -> V_75 ) , V_74 ) ;
F_53 ( V_2 -> V_70 , V_74 ,
V_71 ) ;
}
F_54 ( V_2 -> V_39 , V_4 ) ;
F_55 ( V_2 -> V_39 , V_4 ) ;
}
static struct V_76 * F_56 ( struct V_3 * V_4 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
if ( V_2 -> V_48 ) {
struct V_49 * V_61 ;
T_4 V_78 , V_79 , V_80 , V_63 , V_64 ;
T_5 V_81 = 0 , V_65 = 0 ;
T_5 V_82 ;
int V_15 ;
F_57 (idx) {
V_61 = F_58 ( V_2 -> V_48 , V_15 ) ;
do {
V_82 = F_59 ( & V_61 -> V_62 ) ;
V_78 = V_61 -> V_78 ;
V_79 = V_61 -> V_79 ;
V_80 = V_61 -> V_80 ;
V_63 = V_61 -> V_63 ;
V_64 = V_61 -> V_64 ;
} while ( F_60 ( & V_61 -> V_62 ,
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
static int F_61 ( struct V_3 * V_4 , T_6 V_89 , T_1 V_90 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
return F_62 ( V_39 , V_89 , V_90 ) ;
}
static int F_63 ( struct V_3 * V_4 , T_6 V_89 ,
T_1 V_90 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
F_64 ( V_39 , V_89 , V_90 ) ;
return 0 ;
}
static int F_65 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
return V_2 -> V_39 -> V_91 ;
}
static int F_66 ( struct V_54 * V_55 , struct V_3 * V_4 ,
unsigned short type , const void * V_92 ,
const void * V_93 , unsigned V_57 )
{
const struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
return F_67 ( V_55 , V_39 , type , V_92 ,
V_93 ? : V_4 -> V_53 , V_57 ) ;
}
static int F_68 ( struct V_3 * V_4 ,
struct V_94 * V_95 )
{
const struct V_1 * V_2 = F_24 ( V_4 ) ;
return F_69 ( V_2 -> V_39 , V_95 ) ;
}
static void F_70 ( struct V_3 * V_4 ,
struct V_96 * V_97 )
{
F_71 ( V_97 -> V_98 , V_99 , sizeof( V_97 -> V_98 ) ) ;
F_71 ( V_97 -> V_100 , V_101 , sizeof( V_97 -> V_100 ) ) ;
}
static T_5 F_72 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_24 ( V_4 ) ;
return V_2 -> V_102 ;
}
static void F_73 ( struct V_3 * V_4 , T_5 V_103 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
V_2 -> V_102 = V_103 ;
}
static int F_74 ( struct V_3 * V_4 ,
struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_7 * V_8 = F_15 ( V_2 -> V_39 ) ;
if ( V_106 && V_106 [ V_107 ] ) {
T_1 V_108 = F_75 ( V_106 [ V_107 ] ) ;
F_2 ( V_8 , V_108 ) ;
}
return 0 ;
}
static T_7 F_76 ( const struct V_3 * V_4 )
{
return ( 0
+ F_77 ( 2 )
) ;
}
static int F_78 ( struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
if ( V_106 && V_106 [ V_107 ] ) {
T_1 V_10 = F_75 ( V_106 [ V_107 ] ) ;
if ( V_10 < V_109 || V_10 >= V_110 )
return - V_18 ;
}
return 0 ;
}
static int F_79 ( struct V_54 * V_55 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_7 * V_8 = F_15 ( V_2 -> V_39 ) ;
int V_58 = - V_18 ;
if ( ! V_8 )
goto V_14;
V_58 = - V_111 ;
if ( F_80 ( V_55 , V_107 , V_8 -> V_10 ) )
goto V_14;
return 0 ;
V_14:
return V_58 ;
}
static int F_81 ( struct V_112 * V_113 , struct V_3 * V_4 ,
struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_3 * V_39 ;
int V_14 ;
T_1 V_10 = V_11 ;
if ( ! V_105 [ V_114 ] )
return - V_18 ;
V_39 = F_82 ( V_113 , F_83 ( V_105 [ V_114 ] ) ) ;
if ( ! V_39 )
return - V_115 ;
if ( F_84 ( V_39 ) ) {
struct V_1 * V_116 = F_24 ( V_39 ) ;
V_39 = V_116 -> V_39 ;
} else if ( ! F_85 ( V_39 ) ) {
V_14 = F_4 ( V_39 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_106 && V_106 [ V_107 ] )
V_10 = F_75 ( V_106 [ V_107 ] ) ;
V_8 = F_15 ( V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_66 = V_43 ;
F_1 ( V_2 , V_39 ) ;
F_8 ( & V_2 -> V_117 ) ;
memcpy ( V_4 -> V_53 , V_39 -> V_53 , V_118 ) ;
V_4 -> V_29 |= V_119 ;
V_8 -> V_50 += 1 ;
V_14 = F_86 ( V_4 ) ;
if ( V_14 < 0 )
goto V_120;
V_14 = F_87 ( V_39 , V_4 ) ;
if ( V_14 )
goto V_120;
F_88 ( & V_2 -> V_121 , & V_8 -> V_22 ) ;
F_2 ( V_8 , V_10 ) ;
F_89 ( V_39 , V_4 ) ;
return 0 ;
V_120:
V_8 -> V_50 -= 1 ;
if ( ! V_8 -> V_50 )
F_14 ( V_39 ) ;
return V_14 ;
}
static void F_90 ( struct V_3 * V_4 , struct V_122 * V_123 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_51 * V_52 , * V_124 ;
F_91 (addr, next, &ipvlan->addrs, anode) {
F_35 ( V_52 ) ;
F_92 ( & V_52 -> V_125 ) ;
F_13 ( V_52 , V_31 ) ;
}
F_93 ( & V_2 -> V_121 ) ;
F_94 ( V_4 , V_123 ) ;
F_95 ( V_2 -> V_39 , V_4 ) ;
}
static void F_96 ( struct V_3 * V_4 )
{
F_97 ( V_4 ) ;
V_4 -> V_29 &= ~ ( V_126 | V_127 ) ;
V_4 -> V_29 |= V_128 | V_129 ;
V_4 -> V_130 = & V_131 ;
V_4 -> V_132 = V_133 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_136 = & V_137 ;
}
static int F_98 ( struct V_138 * V_139 )
{
return F_99 ( V_139 ) ;
}
static int F_100 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
struct V_3 * V_4 = F_101 ( V_143 ) ;
struct V_1 * V_2 , * V_124 ;
struct V_7 * V_8 ;
F_102 ( V_144 ) ;
if ( ! F_85 ( V_4 ) )
return V_145 ;
V_8 = F_15 ( V_4 ) ;
switch ( V_142 ) {
case V_146 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_89 ( V_2 -> V_39 ,
V_2 -> V_4 ) ;
break;
case V_147 :
if ( V_4 -> V_148 != V_149 )
break;
F_91 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_138 -> V_150 ( V_2 -> V_4 ,
& V_144 ) ;
F_103 ( & V_144 ) ;
break;
case V_151 :
F_3 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_42 = V_4 -> V_42 & V_43 ;
V_2 -> V_4 -> V_45 = V_4 -> V_45 ;
V_2 -> V_4 -> V_46 = V_4 -> V_46 ;
F_104 ( V_2 -> V_4 ) ;
}
break;
case V_152 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_153 :
return V_154 ;
}
return V_145 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_155 * V_156 )
{
struct V_51 * V_52 ;
if ( F_106 ( V_2 -> V_8 , V_156 , true ) ) {
F_107 ( V_2 , V_157 , V_2 -> V_4 ,
L_3 ,
V_156 , V_2 -> V_4 -> V_158 ) ;
return - V_18 ;
}
V_52 = F_7 ( sizeof( struct V_51 ) , V_159 ) ;
if ( ! V_52 )
return - V_21 ;
V_52 -> V_160 = V_2 ;
memcpy ( & V_52 -> V_161 , V_156 , sizeof( struct V_155 ) ) ;
V_52 -> V_162 = V_163 ;
F_108 ( & V_52 -> V_125 , & V_2 -> V_117 ) ;
if ( F_109 ( V_2 -> V_4 ) )
F_29 ( V_2 , V_52 ) ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 , struct V_155 * V_156 )
{
struct V_51 * V_52 ;
V_52 = F_111 ( V_2 , V_156 , true ) ;
if ( ! V_52 )
return;
F_35 ( V_52 ) ;
F_92 ( & V_52 -> V_125 ) ;
F_13 ( V_52 , V_31 ) ;
return;
}
static int F_112 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
struct V_164 * V_165 = (struct V_164 * ) V_143 ;
struct V_3 * V_4 = (struct V_3 * ) V_165 -> V_166 -> V_4 ;
struct V_1 * V_2 = F_24 ( V_4 ) ;
if ( F_113 () )
return V_145 ;
if ( ! F_84 ( V_4 ) )
return V_145 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_145 ;
switch ( V_142 ) {
case V_167 :
if ( F_105 ( V_2 , & V_165 -> V_52 ) )
return V_154 ;
break;
case V_168 :
F_110 ( V_2 , & V_165 -> V_52 ) ;
break;
}
return V_169 ;
}
static int F_114 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
struct V_51 * V_52 ;
if ( F_106 ( V_2 -> V_8 , V_171 , false ) ) {
F_107 ( V_2 , V_157 , V_2 -> V_4 ,
L_4 ,
V_171 , V_2 -> V_4 -> V_158 ) ;
return - V_18 ;
}
V_52 = F_7 ( sizeof( struct V_51 ) , V_20 ) ;
if ( ! V_52 )
return - V_21 ;
V_52 -> V_160 = V_2 ;
memcpy ( & V_52 -> V_172 , V_171 , sizeof( struct V_170 ) ) ;
V_52 -> V_162 = V_173 ;
F_108 ( & V_52 -> V_125 , & V_2 -> V_117 ) ;
if ( F_109 ( V_2 -> V_4 ) )
F_29 ( V_2 , V_52 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
struct V_51 * V_52 ;
V_52 = F_111 ( V_2 , V_171 , false ) ;
if ( ! V_52 )
return;
F_35 ( V_52 ) ;
F_92 ( & V_52 -> V_125 ) ;
F_13 ( V_52 , V_31 ) ;
return;
}
static int F_116 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
struct V_174 * V_175 = (struct V_174 * ) V_143 ;
struct V_3 * V_4 = (struct V_3 * ) V_175 -> V_176 -> V_4 ;
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_170 V_171 ;
if ( ! F_84 ( V_4 ) )
return V_145 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_145 ;
switch ( V_142 ) {
case V_167 :
V_171 . V_177 = V_175 -> V_178 ;
if ( F_114 ( V_2 , & V_171 ) )
return V_154 ;
break;
case V_168 :
V_171 . V_177 = V_175 -> V_178 ;
F_115 ( V_2 , & V_171 ) ;
break;
}
return V_169 ;
}
static int T_8 F_117 ( void )
{
int V_14 ;
F_118 () ;
F_119 ( & V_179 ) ;
F_120 ( & V_180 ) ;
F_121 ( & V_181 ) ;
V_14 = F_98 ( & V_182 ) ;
if ( V_14 < 0 )
goto error;
return 0 ;
error:
F_122 ( & V_181 ) ;
F_123 ( & V_180 ) ;
F_124 ( & V_179 ) ;
return V_14 ;
}
static void T_9 F_125 ( void )
{
F_126 ( & V_182 ) ;
F_124 ( & V_179 ) ;
F_122 ( & V_181 ) ;
F_123 ( & V_180 ) ;
}
