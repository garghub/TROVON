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
V_4 -> V_43 = V_36 -> V_43 ;
F_17 ( V_4 ) ;
V_2 -> V_44 = F_21 ( struct V_45 ) ;
if ( ! V_2 -> V_44 )
return - V_21 ;
return 0 ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_23 ( V_2 -> V_44 ) ;
V_8 -> V_46 -= 1 ;
if ( ! V_8 -> V_46 )
F_12 ( V_8 -> V_4 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
struct V_47 * V_48 ;
if ( V_2 -> V_8 -> V_10 == V_11 )
V_4 -> V_12 |= V_13 ;
else
V_4 -> V_12 &= ~ V_13 ;
if ( V_2 -> V_49 > 0 || V_2 -> V_50 > 0 ) {
F_3 (addr, &ipvlan->addrs, anode)
F_25 ( V_2 , V_48 ) ;
}
return F_26 ( V_36 , V_36 -> V_51 ) ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
struct V_47 * V_48 ;
F_28 ( V_36 , V_4 ) ;
F_29 ( V_36 , V_4 ) ;
F_30 ( V_36 , V_36 -> V_51 ) ;
if ( V_2 -> V_49 > 0 || V_2 -> V_50 > 0 ) {
F_3 (addr, &ipvlan->addrs, anode)
F_31 ( V_48 , ! V_4 -> V_52 ) ;
}
return 0 ;
}
static T_2 F_32 ( struct V_53 * V_54 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
int V_55 = V_54 -> V_56 ;
int V_57 ;
V_57 = F_33 ( V_54 , V_4 ) ;
if ( F_34 ( V_57 == V_58 || V_57 == V_59 ) ) {
struct V_45 * V_60 ;
V_60 = F_35 ( V_2 -> V_44 ) ;
F_36 ( & V_60 -> V_61 ) ;
V_60 -> V_62 ++ ;
V_60 -> V_63 += V_55 ;
F_37 ( & V_60 -> V_61 ) ;
} else {
F_38 ( V_2 -> V_44 -> V_64 ) ;
}
return V_57 ;
}
static T_3 F_39 ( struct V_3 * V_4 ,
T_3 V_39 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
return V_39 & ( V_2 -> V_65 | ~ V_40 ) ;
}
static void F_40 ( struct V_3 * V_4 , int V_66 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
if ( V_66 & V_67 )
F_41 ( V_36 , V_4 -> V_12 & V_67 ? 1 : - 1 ) ;
}
static void F_42 ( struct V_1 * V_2 , bool V_68 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_69 = F_43 ( V_4 -> V_70 ) ;
if ( V_68 && ! F_44 ( V_69 , V_2 -> V_71 ) )
F_45 ( V_69 , V_2 -> V_71 ) ;
else if ( ! V_68 && F_44 ( V_69 , V_2 -> V_71 ) )
F_46 ( V_69 , V_2 -> V_71 ) ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( V_4 -> V_12 & ( V_72 | V_67 ) ) {
F_48 ( V_2 -> V_71 , V_73 ) ;
} else {
struct V_74 * V_75 ;
F_49 ( V_76 , V_73 ) ;
F_50 ( V_76 , V_73 ) ;
F_51 (ha, dev)
F_45 ( F_43 ( V_75 -> V_48 ) , V_76 ) ;
F_52 ( V_2 -> V_71 , V_76 ,
V_73 ) ;
}
F_53 ( V_2 -> V_36 , V_4 ) ;
F_54 ( V_2 -> V_36 , V_4 ) ;
}
static struct V_77 * F_55 ( struct V_3 * V_4 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( V_2 -> V_44 ) {
struct V_45 * V_60 ;
T_4 V_79 , V_80 , V_81 , V_62 , V_63 ;
T_1 V_82 = 0 , V_64 = 0 ;
T_1 V_83 ;
int V_15 ;
F_56 (idx) {
V_60 = F_57 ( V_2 -> V_44 , V_15 ) ;
do {
V_83 = F_58 ( & V_60 -> V_61 ) ;
V_79 = V_60 -> V_79 ;
V_80 = V_60 -> V_80 ;
V_81 = V_60 -> V_81 ;
V_62 = V_60 -> V_62 ;
V_63 = V_60 -> V_63 ;
} while ( F_59 ( & V_60 -> V_61 ,
V_83 ) );
V_78 -> V_84 += V_79 ;
V_78 -> V_80 += V_80 ;
V_78 -> V_85 += V_81 ;
V_78 -> V_86 += V_62 ;
V_78 -> V_63 += V_63 ;
V_82 += V_60 -> V_82 ;
V_64 += V_60 -> V_64 ;
}
V_78 -> V_87 = V_82 ;
V_78 -> V_88 = V_82 ;
V_78 -> V_89 = V_64 ;
}
return V_78 ;
}
static int F_60 ( struct V_3 * V_4 , T_5 V_90 , T_6 V_91 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
return F_61 ( V_36 , V_90 , V_91 ) ;
}
static int F_62 ( struct V_3 * V_4 , T_5 V_90 ,
T_6 V_91 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
F_63 ( V_36 , V_90 , V_91 ) ;
return 0 ;
}
static int F_64 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
return V_2 -> V_36 -> V_92 ;
}
static int F_65 ( struct V_53 * V_54 , struct V_3 * V_4 ,
unsigned short type , const void * V_93 ,
const void * V_94 , unsigned V_56 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_36 = V_2 -> V_36 ;
return F_66 ( V_54 , V_36 , type , V_93 ,
V_94 ? : V_4 -> V_51 , V_56 ) ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_95 * V_96 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
return F_68 ( V_2 -> V_36 , V_96 ) ;
}
static void F_69 ( struct V_3 * V_4 ,
struct V_97 * V_98 )
{
F_70 ( V_98 -> V_99 , V_100 , sizeof( V_98 -> V_99 ) ) ;
F_70 ( V_98 -> V_101 , V_102 , sizeof( V_98 -> V_101 ) ) ;
}
static T_1 F_71 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
return V_2 -> V_103 ;
}
static void F_72 ( struct V_3 * V_4 , T_1 V_104 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
V_2 -> V_103 = V_104 ;
}
static int F_73 ( struct V_3 * V_4 ,
struct V_105 * V_106 [] , struct V_105 * V_107 [] )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = F_13 ( V_2 -> V_36 ) ;
if ( V_107 && V_107 [ V_108 ] ) {
T_6 V_109 = F_74 ( V_107 [ V_108 ] ) ;
F_2 ( V_8 , V_109 ) ;
}
return 0 ;
}
static T_7 F_75 ( const struct V_3 * V_4 )
{
return ( 0
+ F_76 ( 2 )
) ;
}
static int F_77 ( struct V_105 * V_106 [] , struct V_105 * V_107 [] )
{
if ( V_107 && V_107 [ V_108 ] ) {
T_6 V_10 = F_74 ( V_107 [ V_108 ] ) ;
if ( V_10 < V_110 || V_10 >= V_111 )
return - V_18 ;
}
return 0 ;
}
static int F_78 ( struct V_53 * V_54 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = F_13 ( V_2 -> V_36 ) ;
int V_57 = - V_18 ;
if ( ! V_8 )
goto V_14;
V_57 = - V_112 ;
if ( F_79 ( V_54 , V_108 , V_8 -> V_10 ) )
goto V_14;
return 0 ;
V_14:
return V_57 ;
}
static int F_80 ( struct V_113 * V_114 , struct V_3 * V_4 ,
struct V_105 * V_106 [] , struct V_105 * V_107 [] )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_3 * V_36 ;
int V_14 ;
if ( ! V_106 [ V_115 ] )
return - V_18 ;
V_36 = F_81 ( V_114 , F_82 ( V_106 [ V_115 ] ) ) ;
if ( ! V_36 )
return - V_116 ;
if ( F_83 ( V_36 ) ) {
struct V_1 * V_117 = F_20 ( V_36 ) ;
V_36 = V_117 -> V_36 ;
} else if ( ! F_84 ( V_36 ) ) {
V_14 = F_4 ( V_36 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_8 = F_13 ( V_36 ) ;
if ( V_107 && V_107 [ V_108 ] )
V_8 -> V_10 = F_74 ( V_107 [ V_108 ] ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_65 = V_40 ;
F_8 ( & V_2 -> V_118 ) ;
V_2 -> V_50 = 0 ;
V_2 -> V_49 = 0 ;
memcpy ( V_4 -> V_51 , V_36 -> V_51 , V_119 ) ;
V_4 -> V_26 |= V_120 ;
V_8 -> V_46 += 1 ;
V_14 = F_85 ( V_4 ) ;
if ( V_14 < 0 )
goto V_121;
V_14 = F_86 ( V_36 , V_4 ) ;
if ( V_14 )
goto V_121;
F_87 ( & V_2 -> V_122 , & V_8 -> V_22 ) ;
F_88 ( V_36 , V_4 ) ;
return 0 ;
V_121:
V_8 -> V_46 -= 1 ;
if ( ! V_8 -> V_46 )
F_12 ( V_36 ) ;
return V_14 ;
}
static void F_89 ( struct V_3 * V_4 , struct V_123 * V_124 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_47 * V_48 , * V_125 ;
if ( V_2 -> V_49 > 0 || V_2 -> V_50 > 0 ) {
F_90 (addr, next, &ipvlan->addrs, anode) {
F_31 ( V_48 , ! V_4 -> V_52 ) ;
F_91 ( & V_48 -> V_126 ) ;
}
}
F_92 ( & V_2 -> V_122 ) ;
F_93 ( V_4 , V_124 ) ;
F_94 ( V_2 -> V_36 , V_4 ) ;
}
static void F_95 ( struct V_3 * V_4 )
{
F_96 ( V_4 ) ;
V_4 -> V_26 &= ~ ( V_127 | V_128 ) ;
V_4 -> V_26 |= V_129 ;
V_4 -> V_130 = & V_131 ;
V_4 -> V_132 = V_133 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_136 = & V_137 ;
V_4 -> V_138 = 0 ;
}
static int F_97 ( struct V_139 * V_140 )
{
return F_98 ( V_140 ) ;
}
static int F_99 ( struct V_141 * V_142 ,
unsigned long V_143 , void * V_144 )
{
struct V_3 * V_4 = F_100 ( V_144 ) ;
struct V_1 * V_2 , * V_125 ;
struct V_7 * V_8 ;
F_101 ( V_145 ) ;
if ( ! F_84 ( V_4 ) )
return V_146 ;
V_8 = F_13 ( V_4 ) ;
switch ( V_143 ) {
case V_147 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_88 ( V_2 -> V_36 ,
V_2 -> V_4 ) ;
break;
case V_148 :
if ( V_4 -> V_149 != V_150 )
break;
F_90 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_139 -> V_151 ( V_2 -> V_4 ,
& V_145 ) ;
F_102 ( & V_145 ) ;
break;
case V_152 :
F_3 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_39 = V_4 -> V_39 & V_40 ;
V_2 -> V_4 -> V_42 = V_4 -> V_42 ;
F_103 ( V_2 -> V_4 ) ;
}
break;
case V_153 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_154 :
return V_155 ;
}
return V_146 ;
}
static int F_104 ( struct V_1 * V_2 , struct V_156 * V_157 )
{
struct V_47 * V_48 ;
if ( F_105 ( V_2 -> V_8 , V_157 , true ) ) {
F_106 ( V_2 , V_158 , V_2 -> V_4 ,
L_3 ,
V_157 , V_2 -> V_4 -> V_159 ) ;
return - V_18 ;
}
V_48 = F_7 ( sizeof( struct V_47 ) , V_160 ) ;
if ( ! V_48 )
return - V_21 ;
V_48 -> V_161 = V_2 ;
memcpy ( & V_48 -> V_162 , V_157 , sizeof( struct V_156 ) ) ;
V_48 -> V_163 = V_164 ;
F_107 ( & V_48 -> V_126 , & V_2 -> V_118 ) ;
V_2 -> V_49 ++ ;
if ( F_108 ( V_2 -> V_4 ) )
F_25 ( V_2 , V_48 ) ;
return 0 ;
}
static void F_109 ( struct V_1 * V_2 , struct V_156 * V_157 )
{
struct V_47 * V_48 ;
V_48 = F_110 ( V_2 , V_157 , true ) ;
if ( ! V_48 )
return;
F_31 ( V_48 , true ) ;
F_91 ( & V_48 -> V_126 ) ;
V_2 -> V_49 -- ;
F_111 ( V_2 -> V_49 < 0 ) ;
F_11 ( V_48 , V_28 ) ;
return;
}
static int F_112 ( struct V_141 * V_142 ,
unsigned long V_143 , void * V_144 )
{
struct V_165 * V_166 = (struct V_165 * ) V_144 ;
struct V_3 * V_4 = (struct V_3 * ) V_166 -> V_167 -> V_4 ;
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( ! F_83 ( V_4 ) )
return V_146 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_146 ;
switch ( V_143 ) {
case V_168 :
if ( F_104 ( V_2 , & V_166 -> V_48 ) )
return V_155 ;
break;
case V_169 :
F_109 ( V_2 , & V_166 -> V_48 ) ;
break;
}
return V_170 ;
}
static int F_113 ( struct V_1 * V_2 , struct V_171 * V_172 )
{
struct V_47 * V_48 ;
if ( F_105 ( V_2 -> V_8 , V_172 , false ) ) {
F_106 ( V_2 , V_158 , V_2 -> V_4 ,
L_4 ,
V_172 , V_2 -> V_4 -> V_159 ) ;
return - V_18 ;
}
V_48 = F_7 ( sizeof( struct V_47 ) , V_20 ) ;
if ( ! V_48 )
return - V_21 ;
V_48 -> V_161 = V_2 ;
memcpy ( & V_48 -> V_173 , V_172 , sizeof( struct V_171 ) ) ;
V_48 -> V_163 = V_174 ;
F_107 ( & V_48 -> V_126 , & V_2 -> V_118 ) ;
V_2 -> V_50 ++ ;
if ( F_108 ( V_2 -> V_4 ) )
F_25 ( V_2 , V_48 ) ;
F_42 ( V_2 , true ) ;
return 0 ;
}
static void F_114 ( struct V_1 * V_2 , struct V_171 * V_172 )
{
struct V_47 * V_48 ;
V_48 = F_110 ( V_2 , V_172 , false ) ;
if ( ! V_48 )
return;
F_31 ( V_48 , true ) ;
F_91 ( & V_48 -> V_126 ) ;
V_2 -> V_50 -- ;
F_111 ( V_2 -> V_50 < 0 ) ;
if ( ! V_2 -> V_50 )
F_42 ( V_2 , false ) ;
F_11 ( V_48 , V_28 ) ;
return;
}
static int F_115 ( struct V_141 * V_142 ,
unsigned long V_143 , void * V_144 )
{
struct V_175 * V_176 = (struct V_175 * ) V_144 ;
struct V_3 * V_4 = (struct V_3 * ) V_176 -> V_177 -> V_4 ;
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_171 V_172 ;
if ( ! F_83 ( V_4 ) )
return V_146 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_146 ;
switch ( V_143 ) {
case V_168 :
V_172 . V_178 = V_176 -> V_179 ;
if ( F_113 ( V_2 , & V_172 ) )
return V_155 ;
break;
case V_169 :
V_172 . V_178 = V_176 -> V_179 ;
F_114 ( V_2 , & V_172 ) ;
break;
}
return V_170 ;
}
static int T_8 F_116 ( void )
{
int V_14 ;
F_117 () ;
F_118 ( & V_180 ) ;
F_119 ( & V_181 ) ;
F_120 ( & V_182 ) ;
V_14 = F_97 ( & V_183 ) ;
if ( V_14 < 0 )
goto error;
return 0 ;
error:
F_121 ( & V_182 ) ;
F_122 ( & V_181 ) ;
F_123 ( & V_180 ) ;
return V_14 ;
}
static void T_9 F_124 ( void )
{
F_125 ( & V_183 ) ;
F_123 ( & V_180 ) ;
F_121 ( & V_182 ) ;
F_122 ( & V_181 ) ;
}
