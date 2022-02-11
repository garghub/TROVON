static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 -> V_5 = V_4 -> V_5 ;
}
static int F_2 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 , V_9 ) ;
int V_10 = 0 ;
if ( ! V_8 -> V_11 ) {
V_10 = F_4 ( V_6 , V_12 ,
F_5 ( V_12 ) ) ;
if ( ! V_10 )
V_8 -> V_11 = 1 ;
} else {
V_8 -> V_11 ++ ;
}
return V_10 ;
}
static void F_6 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 , V_9 ) ;
if ( F_7 ( ! V_8 -> V_11 ) )
return;
V_8 -> V_11 -- ;
if ( ! V_8 -> V_11 )
F_8 ( V_6 , V_12 ,
F_5 ( V_12 ) ) ;
}
static int F_9 ( struct V_13 * V_14 , T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_3 * V_16 = V_14 -> V_4 ;
int V_10 = 0 ;
F_10 () ;
if ( V_14 -> V_17 != V_15 ) {
if ( V_15 == V_18 ) {
V_10 = F_2 ( F_11 ( & V_14 -> V_19 ) ) ;
if ( ! V_10 ) {
V_16 -> V_20 = & V_21 ;
V_16 -> V_22 |= V_23 ;
} else
return V_10 ;
} else if ( V_14 -> V_17 == V_18 ) {
V_16 -> V_22 &= ~ V_23 ;
F_6 ( F_11 ( & V_14 -> V_19 ) ) ;
V_16 -> V_20 = NULL ;
}
F_12 (ipvlan, &port->ipvlans, pnode) {
if ( V_15 == V_24 || V_15 == V_18 )
V_2 -> V_4 -> V_25 |= V_26 ;
else
V_2 -> V_4 -> V_25 &= ~ V_26 ;
}
V_14 -> V_17 = V_15 ;
}
return V_10 ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_13 * V_14 ;
int V_10 , V_27 ;
if ( V_4 -> type != V_28 || V_4 -> V_25 & V_29 ) {
F_14 ( V_4 , L_1 ) ;
return - V_30 ;
}
if ( F_15 ( V_4 ) ) {
F_14 ( V_4 , L_2 ) ;
return - V_31 ;
}
V_14 = F_16 ( sizeof( struct V_13 ) , V_32 ) ;
if ( ! V_14 )
return - V_33 ;
F_17 ( & V_14 -> V_19 , F_18 ( V_4 ) ) ;
V_14 -> V_4 = V_4 ;
V_14 -> V_17 = V_24 ;
F_19 ( & V_14 -> V_34 ) ;
for ( V_27 = 0 ; V_27 < V_35 ; V_27 ++ )
F_20 ( & V_14 -> V_36 [ V_27 ] ) ;
F_21 ( & V_14 -> V_37 ) ;
F_22 ( & V_14 -> V_38 , V_39 ) ;
F_23 ( & V_14 -> V_40 ) ;
V_14 -> V_41 = 1 ;
V_10 = F_24 ( V_4 , V_42 , V_14 ) ;
if ( V_10 )
goto V_10;
V_4 -> V_22 |= V_43 ;
return 0 ;
V_10:
F_25 ( V_14 ) ;
return V_10 ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_27 ( V_4 ) ;
struct V_44 * V_45 ;
V_4 -> V_22 &= ~ V_43 ;
if ( V_14 -> V_17 == V_18 ) {
V_4 -> V_22 &= ~ V_23 ;
F_6 ( F_18 ( V_4 ) ) ;
V_4 -> V_20 = NULL ;
}
F_28 ( V_4 ) ;
F_29 ( & V_14 -> V_38 ) ;
while ( ( V_45 = F_30 ( & V_14 -> V_37 ) ) != NULL ) {
if ( V_45 -> V_4 )
F_31 ( V_45 -> V_4 ) ;
F_32 ( V_45 ) ;
}
F_33 ( & V_14 -> V_40 ) ;
F_25 ( V_14 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
const struct V_3 * V_46 = V_2 -> V_46 ;
struct V_13 * V_14 = V_2 -> V_14 ;
V_4 -> V_47 = ( V_4 -> V_47 & ~ V_48 ) |
( V_46 -> V_47 & V_48 ) ;
V_4 -> V_49 = V_46 -> V_49 & V_50 ;
V_4 -> V_49 |= V_51 ;
V_4 -> V_52 = V_46 -> V_52 ;
V_4 -> V_53 = V_46 -> V_53 ;
V_4 -> V_54 = V_46 -> V_54 ;
F_36 ( V_4 ) ;
V_2 -> V_55 = F_37 ( struct V_56 ) ;
if ( ! V_2 -> V_55 )
return - V_33 ;
V_14 -> V_57 += 1 ;
return 0 ;
}
static void F_38 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_39 ( V_2 -> V_55 ) ;
V_14 -> V_57 -= 1 ;
if ( ! V_14 -> V_57 )
F_26 ( V_14 -> V_4 ) ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_3 * V_46 = V_2 -> V_46 ;
struct V_58 * V_59 ;
if ( V_2 -> V_14 -> V_17 == V_24 ||
V_2 -> V_14 -> V_17 == V_18 )
V_4 -> V_25 |= V_26 ;
else
V_4 -> V_25 &= ~ V_26 ;
F_12 (addr, &ipvlan->addrs, anode)
F_41 ( V_2 , V_59 ) ;
return F_42 ( V_46 , V_46 -> V_60 ) ;
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_3 * V_46 = V_2 -> V_46 ;
struct V_58 * V_59 ;
F_44 ( V_46 , V_4 ) ;
F_45 ( V_46 , V_4 ) ;
F_46 ( V_46 , V_46 -> V_60 ) ;
F_12 (addr, &ipvlan->addrs, anode)
F_47 ( V_59 ) ;
return 0 ;
}
static T_2 F_48 ( struct V_44 * V_45 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_35 ( V_4 ) ;
int V_61 = V_45 -> V_62 ;
int V_63 ;
V_63 = F_49 ( V_45 , V_4 ) ;
if ( F_50 ( V_63 == V_64 || V_63 == V_65 ) ) {
struct V_56 * V_66 ;
V_66 = F_51 ( V_2 -> V_55 ) ;
F_52 ( & V_66 -> V_67 ) ;
V_66 -> V_68 ++ ;
V_66 -> V_69 += V_61 ;
F_53 ( & V_66 -> V_67 ) ;
} else {
F_54 ( V_2 -> V_55 -> V_70 ) ;
}
return V_63 ;
}
static T_3 F_55 ( struct V_3 * V_4 ,
T_3 V_49 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
return V_49 & ( V_2 -> V_71 | ~ V_50 ) ;
}
static void F_56 ( struct V_3 * V_4 , int V_72 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_3 * V_46 = V_2 -> V_46 ;
if ( V_72 & V_73 )
F_57 ( V_46 , V_4 -> V_25 & V_73 ? 1 : - 1 ) ;
}
static void F_58 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
if ( V_4 -> V_25 & ( V_74 | V_73 ) ) {
F_59 ( V_2 -> V_75 , V_76 ) ;
} else {
struct V_77 * V_78 ;
F_60 ( V_79 , V_76 ) ;
F_61 ( V_79 , V_76 ) ;
F_62 (ha, dev)
F_63 ( F_64 ( V_78 -> V_59 ) , V_79 ) ;
F_63 ( F_64 ( V_4 -> V_80 ) , V_79 ) ;
F_65 ( V_2 -> V_75 , V_79 ,
V_76 ) ;
}
F_66 ( V_2 -> V_46 , V_4 ) ;
F_67 ( V_2 -> V_46 , V_4 ) ;
}
static void F_68 ( struct V_3 * V_4 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
if ( V_2 -> V_55 ) {
struct V_56 * V_66 ;
T_4 V_83 , V_84 , V_85 , V_68 , V_69 ;
T_5 V_86 = 0 , V_70 = 0 ;
T_5 V_87 ;
int V_27 ;
F_69 (idx) {
V_66 = F_70 ( V_2 -> V_55 , V_27 ) ;
do {
V_87 = F_71 ( & V_66 -> V_67 ) ;
V_83 = V_66 -> V_83 ;
V_84 = V_66 -> V_84 ;
V_85 = V_66 -> V_85 ;
V_68 = V_66 -> V_68 ;
V_69 = V_66 -> V_69 ;
} while ( F_72 ( & V_66 -> V_67 ,
V_87 ) );
V_82 -> V_88 += V_83 ;
V_82 -> V_84 += V_84 ;
V_82 -> V_89 += V_85 ;
V_82 -> V_90 += V_68 ;
V_82 -> V_69 += V_69 ;
V_86 += V_66 -> V_86 ;
V_70 += V_66 -> V_70 ;
}
V_82 -> V_91 = V_86 ;
V_82 -> V_92 = V_86 ;
V_82 -> V_93 = V_70 ;
}
}
static int F_73 ( struct V_3 * V_4 , T_6 V_94 , T_1 V_95 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_3 * V_46 = V_2 -> V_46 ;
return F_74 ( V_46 , V_94 , V_95 ) ;
}
static int F_75 ( struct V_3 * V_4 , T_6 V_94 ,
T_1 V_95 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_3 * V_46 = V_2 -> V_46 ;
F_76 ( V_46 , V_94 , V_95 ) ;
return 0 ;
}
static int F_77 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
return V_2 -> V_46 -> V_96 ;
}
static int F_78 ( struct V_44 * V_45 , struct V_3 * V_4 ,
unsigned short type , const void * V_97 ,
const void * V_98 , unsigned V_62 )
{
const struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_3 * V_46 = V_2 -> V_46 ;
return F_79 ( V_45 , V_46 , type , V_97 ,
V_98 ? : V_4 -> V_60 , V_62 ) ;
}
static int F_80 ( struct V_3 * V_4 ,
struct V_99 * V_100 )
{
const struct V_1 * V_2 = F_35 ( V_4 ) ;
return F_81 ( V_2 -> V_46 , V_100 ) ;
}
static void F_82 ( struct V_3 * V_4 ,
struct V_101 * V_102 )
{
F_83 ( V_102 -> V_103 , V_104 , sizeof( V_102 -> V_103 ) ) ;
F_83 ( V_102 -> V_105 , V_106 , sizeof( V_102 -> V_105 ) ) ;
}
static T_5 F_84 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_35 ( V_4 ) ;
return V_2 -> V_107 ;
}
static void F_85 ( struct V_3 * V_4 , T_5 V_108 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
V_2 -> V_107 = V_108 ;
}
static int F_86 ( struct V_3 * V_4 ,
struct V_109 * V_110 [] , struct V_109 * V_111 [] ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_13 * V_14 = F_27 ( V_2 -> V_46 ) ;
int V_10 = 0 ;
if ( V_111 && V_111 [ V_114 ] ) {
T_1 V_115 = F_87 ( V_111 [ V_114 ] ) ;
V_10 = F_9 ( V_14 , V_115 ) ;
}
return V_10 ;
}
static T_7 F_88 ( const struct V_3 * V_4 )
{
return ( 0
+ F_89 ( 2 )
) ;
}
static int F_90 ( struct V_109 * V_110 [] , struct V_109 * V_111 [] ,
struct V_112 * V_113 )
{
if ( V_111 && V_111 [ V_114 ] ) {
T_1 V_17 = F_87 ( V_111 [ V_114 ] ) ;
if ( V_17 < V_116 || V_17 >= V_117 )
return - V_30 ;
}
return 0 ;
}
static int F_91 ( struct V_44 * V_45 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_13 * V_14 = F_27 ( V_2 -> V_46 ) ;
int V_63 = - V_30 ;
if ( ! V_14 )
goto V_10;
V_63 = - V_118 ;
if ( F_92 ( V_45 , V_114 , V_14 -> V_17 ) )
goto V_10;
return 0 ;
V_10:
return V_63 ;
}
int F_93 ( struct V_6 * V_119 , struct V_3 * V_4 ,
struct V_109 * V_110 [] , struct V_109 * V_111 [] ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_13 * V_14 ;
struct V_3 * V_46 ;
int V_10 ;
T_1 V_17 = V_24 ;
bool V_120 = false ;
if ( ! V_110 [ V_121 ] )
return - V_30 ;
V_46 = F_94 ( V_119 , F_95 ( V_110 [ V_121 ] ) ) ;
if ( ! V_46 )
return - V_122 ;
if ( F_96 ( V_46 ) ) {
struct V_1 * V_123 = F_35 ( V_46 ) ;
V_46 = V_123 -> V_46 ;
} else if ( ! F_97 ( V_46 ) ) {
V_10 = F_13 ( V_46 ) ;
if ( V_10 < 0 )
return V_10 ;
V_120 = true ;
}
if ( V_111 && V_111 [ V_114 ] )
V_17 = F_87 ( V_111 [ V_114 ] ) ;
V_14 = F_27 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_71 = V_50 ;
F_1 ( V_2 , V_46 ) ;
F_19 ( & V_2 -> V_124 ) ;
if ( V_14 -> V_41 == 0xFFFE )
V_14 -> V_41 = 0x1 ;
V_10 = F_98 ( & V_14 -> V_40 , V_14 -> V_41 , 0xFFFE ,
V_32 ) ;
if ( V_10 < 0 )
V_10 = F_98 ( & V_14 -> V_40 , 0x1 , V_14 -> V_41 ,
V_32 ) ;
if ( V_10 < 0 )
goto V_125;
V_4 -> V_126 = V_10 ;
V_14 -> V_41 = V_10 + 1 ;
memcpy ( V_4 -> V_60 , V_46 -> V_60 , V_127 ) ;
V_4 -> V_22 |= V_128 ;
V_10 = F_99 ( V_4 ) ;
if ( V_10 < 0 )
goto V_129;
V_10 = F_100 ( V_46 , V_4 ) ;
if ( V_10 ) {
goto V_130;
}
V_10 = F_9 ( V_14 , V_17 ) ;
if ( V_10 ) {
goto V_131;
}
F_101 ( & V_2 -> V_132 , & V_14 -> V_34 ) ;
F_102 ( V_46 , V_4 ) ;
return 0 ;
V_131:
F_103 ( V_46 , V_4 ) ;
V_130:
F_104 ( V_4 ) ;
V_129:
F_105 ( & V_14 -> V_40 , V_4 -> V_126 ) ;
V_125:
if ( V_120 )
F_26 ( V_46 ) ;
return V_10 ;
}
void F_106 ( struct V_3 * V_4 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_58 * V_59 , * V_135 ;
F_107 (addr, next, &ipvlan->addrs, anode) {
F_47 ( V_59 ) ;
F_108 ( & V_59 -> V_136 ) ;
F_109 ( V_59 , V_137 ) ;
}
F_105 ( & V_2 -> V_14 -> V_40 , V_4 -> V_126 ) ;
F_110 ( & V_2 -> V_132 ) ;
F_111 ( V_4 , V_134 ) ;
F_103 ( V_2 -> V_46 , V_4 ) ;
}
void F_112 ( struct V_3 * V_4 )
{
F_113 ( V_4 ) ;
V_4 -> V_22 &= ~ ( V_138 | V_139 ) ;
V_4 -> V_22 |= V_140 | V_141 ;
V_4 -> V_142 = & V_143 ;
V_4 -> V_144 = true ;
V_4 -> V_145 = & V_146 ;
V_4 -> V_147 = & V_148 ;
}
int F_114 ( struct V_149 * V_150 )
{
V_150 -> V_151 = F_88 ;
V_150 -> V_152 = V_153 ;
V_150 -> V_154 = F_90 ;
V_150 -> V_155 = F_91 ;
V_150 -> V_156 = F_86 ;
V_150 -> V_157 = V_158 ;
return F_115 ( V_150 ) ;
}
static int F_116 ( struct V_159 * V_160 ,
unsigned long V_161 , void * V_162 )
{
struct V_3 * V_4 = F_117 ( V_162 ) ;
struct V_1 * V_2 , * V_135 ;
struct V_13 * V_14 ;
F_118 ( V_163 ) ;
if ( ! F_97 ( V_4 ) )
return V_164 ;
V_14 = F_27 ( V_4 ) ;
switch ( V_161 ) {
case V_165 :
F_12 (ipvlan, &port->ipvlans, pnode)
F_102 ( V_2 -> V_46 ,
V_2 -> V_4 ) ;
break;
case V_166 : {
struct V_6 * V_167 , * V_168 = F_18 ( V_4 ) ;
struct V_7 * V_169 ;
V_167 = F_11 ( & V_14 -> V_19 ) ;
if ( F_119 ( V_168 , V_167 ) )
break;
F_17 ( & V_14 -> V_19 , V_168 ) ;
V_169 = F_3 ( V_167 , V_9 ) ;
if ( ! V_169 -> V_11 )
break;
F_2 ( V_168 ) ;
F_6 ( V_167 ) ;
break;
}
case V_170 :
if ( V_4 -> V_171 != V_172 )
break;
F_107 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_149 -> V_173 ( V_2 -> V_4 ,
& V_163 ) ;
F_120 ( & V_163 ) ;
break;
case V_174 :
F_12 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_49 = V_4 -> V_49 & V_50 ;
V_2 -> V_4 -> V_52 = V_4 -> V_52 ;
V_2 -> V_4 -> V_53 = V_4 -> V_53 ;
F_121 ( V_2 -> V_4 ) ;
}
break;
case V_175 :
F_12 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_176 :
return V_177 ;
}
return V_164 ;
}
static int F_122 ( struct V_1 * V_2 , void * V_178 , bool V_179 )
{
struct V_58 * V_59 ;
V_59 = F_16 ( sizeof( struct V_58 ) , V_180 ) ;
if ( ! V_59 )
return - V_33 ;
V_59 -> V_181 = V_2 ;
if ( V_179 ) {
memcpy ( & V_59 -> V_182 , V_178 , sizeof( struct V_183 ) ) ;
V_59 -> V_184 = V_185 ;
} else {
memcpy ( & V_59 -> V_186 , V_178 , sizeof( struct V_187 ) ) ;
V_59 -> V_184 = V_188 ;
}
F_123 ( & V_59 -> V_136 , & V_2 -> V_124 ) ;
if ( F_124 ( V_2 -> V_4 ) )
F_41 ( V_2 , V_59 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 , void * V_178 , bool V_179 )
{
struct V_58 * V_59 ;
V_59 = F_126 ( V_2 , V_178 , V_179 ) ;
if ( ! V_59 )
return;
F_47 ( V_59 ) ;
F_108 ( & V_59 -> V_136 ) ;
F_109 ( V_59 , V_137 ) ;
return;
}
static int F_127 ( struct V_1 * V_2 , struct V_183 * V_189 )
{
if ( F_128 ( V_2 -> V_14 , V_189 , true ) ) {
F_129 ( V_2 , V_190 , V_2 -> V_4 ,
L_3 ,
V_189 , V_2 -> V_4 -> V_191 ) ;
return - V_30 ;
}
return F_122 ( V_2 , V_189 , true ) ;
}
static void F_130 ( struct V_1 * V_2 , struct V_183 * V_189 )
{
return F_125 ( V_2 , V_189 , true ) ;
}
static int F_131 ( struct V_159 * V_160 ,
unsigned long V_161 , void * V_162 )
{
struct V_192 * V_193 = (struct V_192 * ) V_162 ;
struct V_3 * V_4 = (struct V_3 * ) V_193 -> V_194 -> V_4 ;
struct V_1 * V_2 = F_35 ( V_4 ) ;
if ( F_132 () )
return V_164 ;
if ( ! F_96 ( V_4 ) )
return V_164 ;
if ( ! V_2 || ! V_2 -> V_14 )
return V_164 ;
switch ( V_161 ) {
case V_195 :
if ( F_127 ( V_2 , & V_193 -> V_59 ) )
return V_177 ;
break;
case V_196 :
F_130 ( V_2 , & V_193 -> V_59 ) ;
break;
}
return V_197 ;
}
static int F_133 ( struct V_159 * V_160 ,
unsigned long V_161 , void * V_162 )
{
struct V_198 * V_199 = (struct V_198 * ) V_162 ;
struct V_3 * V_4 = (struct V_3 * ) V_199 -> V_200 -> V_4 ;
struct V_1 * V_2 = F_35 ( V_4 ) ;
if ( F_132 () )
return V_164 ;
if ( ! F_96 ( V_4 ) )
return V_164 ;
if ( ! V_2 || ! V_2 -> V_14 )
return V_164 ;
switch ( V_161 ) {
case V_195 :
if ( F_128 ( V_2 -> V_14 , & V_199 -> V_201 , true ) )
return F_134 ( - V_202 ) ;
break;
}
return V_197 ;
}
static int F_135 ( struct V_1 * V_2 , struct V_187 * V_203 )
{
if ( F_128 ( V_2 -> V_14 , V_203 , false ) ) {
F_129 ( V_2 , V_190 , V_2 -> V_4 ,
L_4 ,
V_203 , V_2 -> V_4 -> V_191 ) ;
return - V_30 ;
}
return F_122 ( V_2 , V_203 , false ) ;
}
static void F_136 ( struct V_1 * V_2 , struct V_187 * V_203 )
{
return F_125 ( V_2 , V_203 , false ) ;
}
static int F_137 ( struct V_159 * V_160 ,
unsigned long V_161 , void * V_162 )
{
struct V_204 * V_205 = (struct V_204 * ) V_162 ;
struct V_3 * V_4 = (struct V_3 * ) V_205 -> V_206 -> V_4 ;
struct V_1 * V_2 = F_35 ( V_4 ) ;
struct V_187 V_203 ;
if ( ! F_96 ( V_4 ) )
return V_164 ;
if ( ! V_2 || ! V_2 -> V_14 )
return V_164 ;
switch ( V_161 ) {
case V_195 :
V_203 . V_207 = V_205 -> V_208 ;
if ( F_135 ( V_2 , & V_203 ) )
return V_177 ;
break;
case V_196 :
V_203 . V_207 = V_205 -> V_208 ;
F_136 ( V_2 , & V_203 ) ;
break;
}
return V_197 ;
}
static int F_138 ( struct V_159 * V_160 ,
unsigned long V_161 , void * V_162 )
{
struct V_209 * V_210 = (struct V_209 * ) V_162 ;
struct V_3 * V_4 = (struct V_3 * ) V_210 -> V_211 -> V_4 ;
struct V_1 * V_2 = F_35 ( V_4 ) ;
if ( ! F_96 ( V_4 ) )
return V_164 ;
if ( ! V_2 || ! V_2 -> V_14 )
return V_164 ;
switch ( V_161 ) {
case V_195 :
if ( F_128 ( V_2 -> V_14 , & V_210 -> V_212 , false ) )
return F_134 ( - V_202 ) ;
break;
}
return V_197 ;
}
static void F_139 ( struct V_6 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 , V_9 ) ;
if ( F_140 ( V_8 -> V_11 ) ) {
V_8 -> V_11 = 0 ;
F_8 ( V_6 , V_12 ,
F_5 ( V_12 ) ) ;
}
}
static int T_8 F_141 ( void )
{
int V_10 ;
F_142 () ;
F_143 ( & V_213 ) ;
F_144 ( & V_214 ) ;
F_145 (
& V_215 ) ;
F_146 ( & V_216 ) ;
F_147 ( & V_217 ) ;
V_10 = F_148 ( & V_218 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_114 ( & V_219 ) ;
if ( V_10 < 0 ) {
F_149 ( & V_218 ) ;
goto error;
}
return 0 ;
error:
F_150 ( & V_216 ) ;
F_151 (
& V_217 ) ;
F_152 ( & V_214 ) ;
F_153 (
& V_215 ) ;
F_154 ( & V_213 ) ;
return V_10 ;
}
static void T_9 F_155 ( void )
{
F_156 ( & V_219 ) ;
F_149 ( & V_218 ) ;
F_154 ( & V_213 ) ;
F_150 ( & V_216 ) ;
F_151 (
& V_217 ) ;
F_152 ( & V_214 ) ;
F_153 (
& V_215 ) ;
}
