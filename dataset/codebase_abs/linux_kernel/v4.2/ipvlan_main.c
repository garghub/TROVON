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
F_21 ( V_4 ) ;
V_2 -> V_47 = F_25 ( struct V_48 ) ;
if ( ! V_2 -> V_47 )
return - V_21 ;
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_27 ( V_2 -> V_47 ) ;
V_8 -> V_49 -= 1 ;
if ( ! V_8 -> V_49 )
F_14 ( V_8 -> V_4 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
struct V_50 * V_51 ;
if ( V_2 -> V_8 -> V_10 == V_11 )
V_4 -> V_12 |= V_13 ;
else
V_4 -> V_12 &= ~ V_13 ;
F_3 (addr, &ipvlan->addrs, anode)
F_29 ( V_2 , V_51 ) ;
return F_30 ( V_39 , V_39 -> V_52 ) ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
struct V_50 * V_51 ;
F_32 ( V_39 , V_4 ) ;
F_33 ( V_39 , V_4 ) ;
F_34 ( V_39 , V_39 -> V_52 ) ;
F_3 (addr, &ipvlan->addrs, anode)
F_35 ( V_51 ) ;
return 0 ;
}
static T_2 F_36 ( struct V_53 * V_54 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_24 ( V_4 ) ;
int V_55 = V_54 -> V_56 ;
int V_57 ;
V_57 = F_37 ( V_54 , V_4 ) ;
if ( F_38 ( V_57 == V_58 || V_57 == V_59 ) ) {
struct V_48 * V_60 ;
V_60 = F_39 ( V_2 -> V_47 ) ;
F_40 ( & V_60 -> V_61 ) ;
V_60 -> V_62 ++ ;
V_60 -> V_63 += V_55 ;
F_41 ( & V_60 -> V_61 ) ;
} else {
F_42 ( V_2 -> V_47 -> V_64 ) ;
}
return V_57 ;
}
static T_3 F_43 ( struct V_3 * V_4 ,
T_3 V_42 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
return V_42 & ( V_2 -> V_65 | ~ V_43 ) ;
}
static void F_44 ( struct V_3 * V_4 , int V_66 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
if ( V_66 & V_67 )
F_45 ( V_39 , V_4 -> V_12 & V_67 ? 1 : - 1 ) ;
}
static void F_46 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
if ( V_4 -> V_12 & ( V_68 | V_67 ) ) {
F_47 ( V_2 -> V_69 , V_70 ) ;
} else {
struct V_71 * V_72 ;
F_48 ( V_73 , V_70 ) ;
F_49 ( V_73 , V_70 ) ;
F_50 (ha, dev)
F_51 ( F_52 ( V_72 -> V_51 ) , V_73 ) ;
F_51 ( F_52 ( V_4 -> V_74 ) , V_73 ) ;
F_53 ( V_2 -> V_69 , V_73 ,
V_70 ) ;
}
F_54 ( V_2 -> V_39 , V_4 ) ;
F_55 ( V_2 -> V_39 , V_4 ) ;
}
static struct V_75 * F_56 ( struct V_3 * V_4 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
if ( V_2 -> V_47 ) {
struct V_48 * V_60 ;
T_4 V_77 , V_78 , V_79 , V_62 , V_63 ;
T_1 V_80 = 0 , V_64 = 0 ;
T_1 V_81 ;
int V_15 ;
F_57 (idx) {
V_60 = F_58 ( V_2 -> V_47 , V_15 ) ;
do {
V_81 = F_59 ( & V_60 -> V_61 ) ;
V_77 = V_60 -> V_77 ;
V_78 = V_60 -> V_78 ;
V_79 = V_60 -> V_79 ;
V_62 = V_60 -> V_62 ;
V_63 = V_60 -> V_63 ;
} while ( F_60 ( & V_60 -> V_61 ,
V_81 ) );
V_76 -> V_82 += V_77 ;
V_76 -> V_78 += V_78 ;
V_76 -> V_83 += V_79 ;
V_76 -> V_84 += V_62 ;
V_76 -> V_63 += V_63 ;
V_80 += V_60 -> V_80 ;
V_64 += V_60 -> V_64 ;
}
V_76 -> V_85 = V_80 ;
V_76 -> V_86 = V_80 ;
V_76 -> V_87 = V_64 ;
}
return V_76 ;
}
static int F_61 ( struct V_3 * V_4 , T_5 V_88 , T_6 V_89 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
return F_62 ( V_39 , V_88 , V_89 ) ;
}
static int F_63 ( struct V_3 * V_4 , T_5 V_88 ,
T_6 V_89 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
F_64 ( V_39 , V_88 , V_89 ) ;
return 0 ;
}
static int F_65 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
return V_2 -> V_39 -> V_90 ;
}
static int F_66 ( struct V_53 * V_54 , struct V_3 * V_4 ,
unsigned short type , const void * V_91 ,
const void * V_92 , unsigned V_56 )
{
const struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
return F_67 ( V_54 , V_39 , type , V_91 ,
V_92 ? : V_4 -> V_52 , V_56 ) ;
}
static int F_68 ( struct V_3 * V_4 ,
struct V_93 * V_94 )
{
const struct V_1 * V_2 = F_24 ( V_4 ) ;
return F_69 ( V_2 -> V_39 , V_94 ) ;
}
static void F_70 ( struct V_3 * V_4 ,
struct V_95 * V_96 )
{
F_71 ( V_96 -> V_97 , V_98 , sizeof( V_96 -> V_97 ) ) ;
F_71 ( V_96 -> V_99 , V_100 , sizeof( V_96 -> V_99 ) ) ;
}
static T_1 F_72 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_24 ( V_4 ) ;
return V_2 -> V_101 ;
}
static void F_73 ( struct V_3 * V_4 , T_1 V_102 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
V_2 -> V_101 = V_102 ;
}
static int F_74 ( struct V_3 * V_4 ,
struct V_103 * V_104 [] , struct V_103 * V_105 [] )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_7 * V_8 = F_15 ( V_2 -> V_39 ) ;
if ( V_105 && V_105 [ V_106 ] ) {
T_6 V_107 = F_75 ( V_105 [ V_106 ] ) ;
F_2 ( V_8 , V_107 ) ;
}
return 0 ;
}
static T_7 F_76 ( const struct V_3 * V_4 )
{
return ( 0
+ F_77 ( 2 )
) ;
}
static int F_78 ( struct V_103 * V_104 [] , struct V_103 * V_105 [] )
{
if ( V_105 && V_105 [ V_106 ] ) {
T_6 V_10 = F_75 ( V_105 [ V_106 ] ) ;
if ( V_10 < V_108 || V_10 >= V_109 )
return - V_18 ;
}
return 0 ;
}
static int F_79 ( struct V_53 * V_54 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_7 * V_8 = F_15 ( V_2 -> V_39 ) ;
int V_57 = - V_18 ;
if ( ! V_8 )
goto V_14;
V_57 = - V_110 ;
if ( F_80 ( V_54 , V_106 , V_8 -> V_10 ) )
goto V_14;
return 0 ;
V_14:
return V_57 ;
}
static int F_81 ( struct V_111 * V_112 , struct V_3 * V_4 ,
struct V_103 * V_104 [] , struct V_103 * V_105 [] )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_3 * V_39 ;
int V_14 ;
if ( ! V_104 [ V_113 ] )
return - V_18 ;
V_39 = F_82 ( V_112 , F_83 ( V_104 [ V_113 ] ) ) ;
if ( ! V_39 )
return - V_114 ;
if ( F_84 ( V_39 ) ) {
struct V_1 * V_115 = F_24 ( V_39 ) ;
V_39 = V_115 -> V_39 ;
} else if ( ! F_85 ( V_39 ) ) {
V_14 = F_4 ( V_39 ) ;
if ( V_14 < 0 )
return V_14 ;
}
V_8 = F_15 ( V_39 ) ;
if ( V_105 && V_105 [ V_106 ] )
V_8 -> V_10 = F_75 ( V_105 [ V_106 ] ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_65 = V_43 ;
F_8 ( & V_2 -> V_116 ) ;
memcpy ( V_4 -> V_52 , V_39 -> V_52 , V_117 ) ;
V_4 -> V_29 |= V_118 ;
V_8 -> V_49 += 1 ;
V_14 = F_86 ( V_4 ) ;
if ( V_14 < 0 )
goto V_119;
V_14 = F_87 ( V_39 , V_4 ) ;
if ( V_14 )
goto V_119;
F_88 ( & V_2 -> V_120 , & V_8 -> V_22 ) ;
F_89 ( V_39 , V_4 ) ;
return 0 ;
V_119:
V_8 -> V_49 -= 1 ;
if ( ! V_8 -> V_49 )
F_14 ( V_39 ) ;
return V_14 ;
}
static void F_90 ( struct V_3 * V_4 , struct V_121 * V_122 )
{
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_50 * V_51 , * V_123 ;
F_91 (addr, next, &ipvlan->addrs, anode) {
F_35 ( V_51 ) ;
F_92 ( & V_51 -> V_124 ) ;
F_13 ( V_51 , V_31 ) ;
}
F_93 ( & V_2 -> V_120 ) ;
F_94 ( V_4 , V_122 ) ;
F_95 ( V_2 -> V_39 , V_4 ) ;
}
static void F_96 ( struct V_3 * V_4 )
{
F_97 ( V_4 ) ;
V_4 -> V_29 &= ~ ( V_125 | V_126 ) ;
V_4 -> V_29 |= V_127 ;
V_4 -> V_128 = & V_129 ;
V_4 -> V_130 = V_131 ;
V_4 -> V_132 = & V_133 ;
V_4 -> V_134 = & V_135 ;
V_4 -> V_136 = 0 ;
}
static int F_98 ( struct V_137 * V_138 )
{
return F_99 ( V_138 ) ;
}
static int F_100 ( struct V_139 * V_140 ,
unsigned long V_141 , void * V_142 )
{
struct V_3 * V_4 = F_101 ( V_142 ) ;
struct V_1 * V_2 , * V_123 ;
struct V_7 * V_8 ;
F_102 ( V_143 ) ;
if ( ! F_85 ( V_4 ) )
return V_144 ;
V_8 = F_15 ( V_4 ) ;
switch ( V_141 ) {
case V_145 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_89 ( V_2 -> V_39 ,
V_2 -> V_4 ) ;
break;
case V_146 :
if ( V_4 -> V_147 != V_148 )
break;
F_91 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_137 -> V_149 ( V_2 -> V_4 ,
& V_143 ) ;
F_103 ( & V_143 ) ;
break;
case V_150 :
F_3 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_42 = V_4 -> V_42 & V_43 ;
V_2 -> V_4 -> V_45 = V_4 -> V_45 ;
F_104 ( V_2 -> V_4 ) ;
}
break;
case V_151 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_152 :
return V_153 ;
}
return V_144 ;
}
static int F_105 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
struct V_50 * V_51 ;
if ( F_106 ( V_2 -> V_8 , V_155 , true ) ) {
F_107 ( V_2 , V_156 , V_2 -> V_4 ,
L_3 ,
V_155 , V_2 -> V_4 -> V_157 ) ;
return - V_18 ;
}
V_51 = F_7 ( sizeof( struct V_50 ) , V_158 ) ;
if ( ! V_51 )
return - V_21 ;
V_51 -> V_159 = V_2 ;
memcpy ( & V_51 -> V_160 , V_155 , sizeof( struct V_154 ) ) ;
V_51 -> V_161 = V_162 ;
F_108 ( & V_51 -> V_124 , & V_2 -> V_116 ) ;
if ( F_109 ( V_2 -> V_4 ) )
F_29 ( V_2 , V_51 ) ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
struct V_50 * V_51 ;
V_51 = F_111 ( V_2 , V_155 , true ) ;
if ( ! V_51 )
return;
F_35 ( V_51 ) ;
F_92 ( & V_51 -> V_124 ) ;
F_13 ( V_51 , V_31 ) ;
return;
}
static int F_112 ( struct V_139 * V_140 ,
unsigned long V_141 , void * V_142 )
{
struct V_163 * V_164 = (struct V_163 * ) V_142 ;
struct V_3 * V_4 = (struct V_3 * ) V_164 -> V_165 -> V_4 ;
struct V_1 * V_2 = F_24 ( V_4 ) ;
if ( F_113 () )
return V_144 ;
if ( ! F_84 ( V_4 ) )
return V_144 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_144 ;
switch ( V_141 ) {
case V_166 :
if ( F_105 ( V_2 , & V_164 -> V_51 ) )
return V_153 ;
break;
case V_167 :
F_110 ( V_2 , & V_164 -> V_51 ) ;
break;
}
return V_168 ;
}
static int F_114 ( struct V_1 * V_2 , struct V_169 * V_170 )
{
struct V_50 * V_51 ;
if ( F_106 ( V_2 -> V_8 , V_170 , false ) ) {
F_107 ( V_2 , V_156 , V_2 -> V_4 ,
L_4 ,
V_170 , V_2 -> V_4 -> V_157 ) ;
return - V_18 ;
}
V_51 = F_7 ( sizeof( struct V_50 ) , V_20 ) ;
if ( ! V_51 )
return - V_21 ;
V_51 -> V_159 = V_2 ;
memcpy ( & V_51 -> V_171 , V_170 , sizeof( struct V_169 ) ) ;
V_51 -> V_161 = V_172 ;
F_108 ( & V_51 -> V_124 , & V_2 -> V_116 ) ;
if ( F_109 ( V_2 -> V_4 ) )
F_29 ( V_2 , V_51 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 , struct V_169 * V_170 )
{
struct V_50 * V_51 ;
V_51 = F_111 ( V_2 , V_170 , false ) ;
if ( ! V_51 )
return;
F_35 ( V_51 ) ;
F_92 ( & V_51 -> V_124 ) ;
F_13 ( V_51 , V_31 ) ;
return;
}
static int F_116 ( struct V_139 * V_140 ,
unsigned long V_141 , void * V_142 )
{
struct V_173 * V_174 = (struct V_173 * ) V_142 ;
struct V_3 * V_4 = (struct V_3 * ) V_174 -> V_175 -> V_4 ;
struct V_1 * V_2 = F_24 ( V_4 ) ;
struct V_169 V_170 ;
if ( ! F_84 ( V_4 ) )
return V_144 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_144 ;
switch ( V_141 ) {
case V_166 :
V_170 . V_176 = V_174 -> V_177 ;
if ( F_114 ( V_2 , & V_170 ) )
return V_153 ;
break;
case V_167 :
V_170 . V_176 = V_174 -> V_177 ;
F_115 ( V_2 , & V_170 ) ;
break;
}
return V_168 ;
}
static int T_8 F_117 ( void )
{
int V_14 ;
F_118 () ;
F_119 ( & V_178 ) ;
F_120 ( & V_179 ) ;
F_121 ( & V_180 ) ;
V_14 = F_98 ( & V_181 ) ;
if ( V_14 < 0 )
goto error;
return 0 ;
error:
F_122 ( & V_180 ) ;
F_123 ( & V_179 ) ;
F_124 ( & V_178 ) ;
return V_14 ;
}
static void T_9 F_125 ( void )
{
F_126 ( & V_181 ) ;
F_124 ( & V_178 ) ;
F_122 ( & V_180 ) ;
F_123 ( & V_179 ) ;
}
