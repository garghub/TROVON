static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_4 -> V_5 = V_4 -> V_5 ;
}
static int F_2 ( void )
{
int V_6 = 0 ;
if ( ! V_7 ) {
V_6 = F_3 ( V_8 , F_4 ( V_8 ) ) ;
if ( ! V_6 )
V_7 = 1 ;
} else {
V_7 ++ ;
}
return V_6 ;
}
static void F_5 ( void )
{
F_6 ( ! V_7 ) ;
V_7 -- ;
if ( ! V_7 )
F_7 ( V_8 , F_4 ( V_8 ) ) ;
}
static int F_8 ( struct V_9 * V_10 , T_1 V_11 )
{
struct V_1 * V_2 ;
struct V_3 * V_12 = V_10 -> V_4 ;
int V_6 = 0 ;
F_9 () ;
if ( V_10 -> V_13 != V_11 ) {
if ( V_11 == V_14 ) {
V_6 = F_2 () ;
if ( ! V_6 ) {
V_12 -> V_15 = & V_16 ;
V_12 -> V_17 |= V_18 ;
} else
return V_6 ;
} else if ( V_10 -> V_13 == V_14 ) {
V_12 -> V_17 &= ~ V_18 ;
F_5 () ;
V_12 -> V_15 = NULL ;
}
F_10 (ipvlan, &port->ipvlans, pnode) {
if ( V_11 == V_19 || V_11 == V_14 )
V_2 -> V_4 -> V_20 |= V_21 ;
else
V_2 -> V_4 -> V_20 &= ~ V_21 ;
}
V_10 -> V_13 = V_11 ;
}
return V_6 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_9 * V_10 ;
int V_6 , V_22 ;
if ( V_4 -> type != V_23 || V_4 -> V_20 & V_24 ) {
F_12 ( V_4 , L_1 ) ;
return - V_25 ;
}
if ( F_13 ( V_4 ) ) {
F_12 ( V_4 , L_2 ) ;
return - V_26 ;
}
V_10 = F_14 ( sizeof( struct V_9 ) , V_27 ) ;
if ( ! V_10 )
return - V_28 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_13 = V_19 ;
F_15 ( & V_10 -> V_29 ) ;
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ )
F_16 ( & V_10 -> V_31 [ V_22 ] ) ;
F_17 ( & V_10 -> V_32 ) ;
F_18 ( & V_10 -> V_33 , V_34 ) ;
F_19 ( & V_10 -> V_35 ) ;
V_10 -> V_36 = 1 ;
V_6 = F_20 ( V_4 , V_37 , V_10 ) ;
if ( V_6 )
goto V_6;
V_4 -> V_17 |= V_38 ;
return 0 ;
V_6:
F_21 ( V_10 ) ;
return V_6 ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = F_23 ( V_4 ) ;
struct V_39 * V_40 ;
V_4 -> V_17 &= ~ V_38 ;
if ( V_10 -> V_13 == V_14 ) {
V_4 -> V_17 &= ~ V_18 ;
F_5 () ;
V_4 -> V_15 = NULL ;
}
F_24 ( V_4 ) ;
F_25 ( & V_10 -> V_33 ) ;
while ( ( V_40 = F_26 ( & V_10 -> V_32 ) ) != NULL ) {
if ( V_40 -> V_4 )
F_27 ( V_40 -> V_4 ) ;
F_28 ( V_40 ) ;
}
F_29 ( & V_10 -> V_35 ) ;
F_21 ( V_10 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
const struct V_3 * V_41 = V_2 -> V_41 ;
struct V_9 * V_10 = V_2 -> V_10 ;
V_4 -> V_42 = ( V_4 -> V_42 & ~ V_43 ) |
( V_41 -> V_42 & V_43 ) ;
V_4 -> V_44 = V_41 -> V_44 & V_45 ;
V_4 -> V_44 |= V_46 ;
V_4 -> V_47 = V_41 -> V_47 ;
V_4 -> V_48 = V_41 -> V_48 ;
V_4 -> V_49 = V_41 -> V_49 ;
F_32 ( V_4 ) ;
V_2 -> V_50 = F_33 ( struct V_51 ) ;
if ( ! V_2 -> V_50 )
return - V_28 ;
V_10 -> V_52 += 1 ;
return 0 ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
F_35 ( V_2 -> V_50 ) ;
V_10 -> V_52 -= 1 ;
if ( ! V_10 -> V_52 )
F_22 ( V_10 -> V_4 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_3 * V_41 = V_2 -> V_41 ;
struct V_53 * V_54 ;
if ( V_2 -> V_10 -> V_13 == V_19 ||
V_2 -> V_10 -> V_13 == V_14 )
V_4 -> V_20 |= V_21 ;
else
V_4 -> V_20 &= ~ V_21 ;
F_10 (addr, &ipvlan->addrs, anode)
F_37 ( V_2 , V_54 ) ;
return F_38 ( V_41 , V_41 -> V_55 ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_3 * V_41 = V_2 -> V_41 ;
struct V_53 * V_54 ;
F_40 ( V_41 , V_4 ) ;
F_41 ( V_41 , V_4 ) ;
F_42 ( V_41 , V_41 -> V_55 ) ;
F_10 (addr, &ipvlan->addrs, anode)
F_43 ( V_54 ) ;
return 0 ;
}
static T_2 F_44 ( struct V_39 * V_40 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_31 ( V_4 ) ;
int V_56 = V_40 -> V_57 ;
int V_58 ;
V_58 = F_45 ( V_40 , V_4 ) ;
if ( F_46 ( V_58 == V_59 || V_58 == V_60 ) ) {
struct V_51 * V_61 ;
V_61 = F_47 ( V_2 -> V_50 ) ;
F_48 ( & V_61 -> V_62 ) ;
V_61 -> V_63 ++ ;
V_61 -> V_64 += V_56 ;
F_49 ( & V_61 -> V_62 ) ;
} else {
F_50 ( V_2 -> V_50 -> V_65 ) ;
}
return V_58 ;
}
static T_3 F_51 ( struct V_3 * V_4 ,
T_3 V_44 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
return V_44 & ( V_2 -> V_66 | ~ V_45 ) ;
}
static void F_52 ( struct V_3 * V_4 , int V_67 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_3 * V_41 = V_2 -> V_41 ;
if ( V_67 & V_68 )
F_53 ( V_41 , V_4 -> V_20 & V_68 ? 1 : - 1 ) ;
}
static void F_54 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
if ( V_4 -> V_20 & ( V_69 | V_68 ) ) {
F_55 ( V_2 -> V_70 , V_71 ) ;
} else {
struct V_72 * V_73 ;
F_56 ( V_74 , V_71 ) ;
F_57 ( V_74 , V_71 ) ;
F_58 (ha, dev)
F_59 ( F_60 ( V_73 -> V_54 ) , V_74 ) ;
F_59 ( F_60 ( V_4 -> V_75 ) , V_74 ) ;
F_61 ( V_2 -> V_70 , V_74 ,
V_71 ) ;
}
F_62 ( V_2 -> V_41 , V_4 ) ;
F_63 ( V_2 -> V_41 , V_4 ) ;
}
static void F_64 ( struct V_3 * V_4 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
if ( V_2 -> V_50 ) {
struct V_51 * V_61 ;
T_4 V_78 , V_79 , V_80 , V_63 , V_64 ;
T_5 V_81 = 0 , V_65 = 0 ;
T_5 V_82 ;
int V_22 ;
F_65 (idx) {
V_61 = F_66 ( V_2 -> V_50 , V_22 ) ;
do {
V_82 = F_67 ( & V_61 -> V_62 ) ;
V_78 = V_61 -> V_78 ;
V_79 = V_61 -> V_79 ;
V_80 = V_61 -> V_80 ;
V_63 = V_61 -> V_63 ;
V_64 = V_61 -> V_64 ;
} while ( F_68 ( & V_61 -> V_62 ,
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
}
static int F_69 ( struct V_3 * V_4 , T_6 V_89 , T_1 V_90 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_3 * V_41 = V_2 -> V_41 ;
return F_70 ( V_41 , V_89 , V_90 ) ;
}
static int F_71 ( struct V_3 * V_4 , T_6 V_89 ,
T_1 V_90 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_3 * V_41 = V_2 -> V_41 ;
F_72 ( V_41 , V_89 , V_90 ) ;
return 0 ;
}
static int F_73 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
return V_2 -> V_41 -> V_91 ;
}
static int F_74 ( struct V_39 * V_40 , struct V_3 * V_4 ,
unsigned short type , const void * V_92 ,
const void * V_93 , unsigned V_57 )
{
const struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_3 * V_41 = V_2 -> V_41 ;
return F_75 ( V_40 , V_41 , type , V_92 ,
V_93 ? : V_4 -> V_55 , V_57 ) ;
}
static int F_76 ( struct V_3 * V_4 ,
struct V_94 * V_95 )
{
const struct V_1 * V_2 = F_31 ( V_4 ) ;
return F_77 ( V_2 -> V_41 , V_95 ) ;
}
static void F_78 ( struct V_3 * V_4 ,
struct V_96 * V_97 )
{
F_79 ( V_97 -> V_98 , V_99 , sizeof( V_97 -> V_98 ) ) ;
F_79 ( V_97 -> V_100 , V_101 , sizeof( V_97 -> V_100 ) ) ;
}
static T_5 F_80 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_31 ( V_4 ) ;
return V_2 -> V_102 ;
}
static void F_81 ( struct V_3 * V_4 , T_5 V_103 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
V_2 -> V_102 = V_103 ;
}
static int F_82 ( struct V_3 * V_4 ,
struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_9 * V_10 = F_23 ( V_2 -> V_41 ) ;
int V_6 = 0 ;
if ( V_106 && V_106 [ V_107 ] ) {
T_1 V_108 = F_83 ( V_106 [ V_107 ] ) ;
V_6 = F_8 ( V_10 , V_108 ) ;
}
return V_6 ;
}
static T_7 F_84 ( const struct V_3 * V_4 )
{
return ( 0
+ F_85 ( 2 )
) ;
}
static int F_86 ( struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
if ( V_106 && V_106 [ V_107 ] ) {
T_1 V_13 = F_83 ( V_106 [ V_107 ] ) ;
if ( V_13 < V_109 || V_13 >= V_110 )
return - V_25 ;
}
return 0 ;
}
static int F_87 ( struct V_39 * V_40 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_9 * V_10 = F_23 ( V_2 -> V_41 ) ;
int V_58 = - V_25 ;
if ( ! V_10 )
goto V_6;
V_58 = - V_111 ;
if ( F_88 ( V_40 , V_107 , V_10 -> V_13 ) )
goto V_6;
return 0 ;
V_6:
return V_58 ;
}
int F_89 ( struct V_112 * V_113 , struct V_3 * V_4 ,
struct V_104 * V_105 [] , struct V_104 * V_106 [] )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_9 * V_10 ;
struct V_3 * V_41 ;
int V_6 ;
T_1 V_13 = V_19 ;
bool V_114 = false ;
if ( ! V_105 [ V_115 ] )
return - V_25 ;
V_41 = F_90 ( V_113 , F_91 ( V_105 [ V_115 ] ) ) ;
if ( ! V_41 )
return - V_116 ;
if ( F_92 ( V_41 ) ) {
struct V_1 * V_117 = F_31 ( V_41 ) ;
V_41 = V_117 -> V_41 ;
} else if ( ! F_93 ( V_41 ) ) {
V_6 = F_11 ( V_41 ) ;
if ( V_6 < 0 )
return V_6 ;
V_114 = true ;
}
if ( V_106 && V_106 [ V_107 ] )
V_13 = F_83 ( V_106 [ V_107 ] ) ;
V_10 = F_23 ( V_41 ) ;
V_2 -> V_41 = V_41 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_66 = V_45 ;
F_1 ( V_2 , V_41 ) ;
F_15 ( & V_2 -> V_118 ) ;
if ( V_10 -> V_36 == 0xFFFE )
V_10 -> V_36 = 0x1 ;
V_6 = F_94 ( & V_10 -> V_35 , V_10 -> V_36 , 0xFFFE ,
V_27 ) ;
if ( V_6 < 0 )
V_6 = F_94 ( & V_10 -> V_35 , 0x1 , V_10 -> V_36 ,
V_27 ) ;
if ( V_6 < 0 )
goto V_119;
V_4 -> V_120 = V_6 ;
V_10 -> V_36 = V_6 + 1 ;
memcpy ( V_4 -> V_55 , V_41 -> V_55 , V_121 ) ;
V_4 -> V_17 |= V_122 ;
V_6 = F_95 ( V_4 ) ;
if ( V_6 < 0 )
goto V_123;
V_6 = F_96 ( V_41 , V_4 ) ;
if ( V_6 ) {
goto V_124;
}
V_6 = F_8 ( V_10 , V_13 ) ;
if ( V_6 ) {
goto V_125;
}
F_97 ( & V_2 -> V_126 , & V_10 -> V_29 ) ;
F_98 ( V_41 , V_4 ) ;
return 0 ;
V_125:
F_99 ( V_41 , V_4 ) ;
V_124:
F_100 ( V_4 ) ;
V_123:
F_101 ( & V_10 -> V_35 , V_4 -> V_120 ) ;
V_119:
if ( V_114 )
F_22 ( V_41 ) ;
return V_6 ;
}
void F_102 ( struct V_3 * V_4 , struct V_127 * V_128 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_53 * V_54 , * V_129 ;
F_103 (addr, next, &ipvlan->addrs, anode) {
F_43 ( V_54 ) ;
F_104 ( & V_54 -> V_130 ) ;
F_105 ( V_54 , V_131 ) ;
}
F_101 ( & V_2 -> V_10 -> V_35 , V_4 -> V_120 ) ;
F_106 ( & V_2 -> V_126 ) ;
F_107 ( V_4 , V_128 ) ;
F_99 ( V_2 -> V_41 , V_4 ) ;
}
void F_108 ( struct V_3 * V_4 )
{
F_109 ( V_4 ) ;
V_4 -> V_17 &= ~ ( V_132 | V_133 ) ;
V_4 -> V_17 |= V_134 | V_135 ;
V_4 -> V_136 = & V_137 ;
V_4 -> V_138 = V_139 ;
V_4 -> V_140 = & V_141 ;
V_4 -> V_142 = & V_143 ;
}
int F_110 ( struct V_144 * V_145 )
{
V_145 -> V_146 = F_84 ;
V_145 -> V_147 = V_148 ;
V_145 -> V_149 = F_86 ;
V_145 -> V_150 = F_87 ;
V_145 -> V_151 = F_82 ;
V_145 -> V_152 = V_153 ;
return F_111 ( V_145 ) ;
}
static int F_112 ( struct V_154 * V_155 ,
unsigned long V_156 , void * V_157 )
{
struct V_3 * V_4 = F_113 ( V_157 ) ;
struct V_1 * V_2 , * V_129 ;
struct V_9 * V_10 ;
F_114 ( V_158 ) ;
if ( ! F_93 ( V_4 ) )
return V_159 ;
V_10 = F_23 ( V_4 ) ;
switch ( V_156 ) {
case V_160 :
F_10 (ipvlan, &port->ipvlans, pnode)
F_98 ( V_2 -> V_41 ,
V_2 -> V_4 ) ;
break;
case V_161 :
if ( V_4 -> V_162 != V_163 )
break;
F_103 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_144 -> V_164 ( V_2 -> V_4 ,
& V_158 ) ;
F_115 ( & V_158 ) ;
break;
case V_165 :
F_10 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_44 = V_4 -> V_44 & V_45 ;
V_2 -> V_4 -> V_47 = V_4 -> V_47 ;
V_2 -> V_4 -> V_48 = V_4 -> V_48 ;
F_116 ( V_2 -> V_4 ) ;
}
break;
case V_166 :
F_10 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_167 :
return V_168 ;
}
return V_159 ;
}
static int F_117 ( struct V_1 * V_2 , void * V_169 , bool V_170 )
{
struct V_53 * V_54 ;
V_54 = F_14 ( sizeof( struct V_53 ) , V_171 ) ;
if ( ! V_54 )
return - V_28 ;
V_54 -> V_172 = V_2 ;
if ( V_170 ) {
memcpy ( & V_54 -> V_173 , V_169 , sizeof( struct V_174 ) ) ;
V_54 -> V_175 = V_176 ;
} else {
memcpy ( & V_54 -> V_177 , V_169 , sizeof( struct V_178 ) ) ;
V_54 -> V_175 = V_179 ;
}
F_118 ( & V_54 -> V_130 , & V_2 -> V_118 ) ;
if ( F_119 ( V_2 -> V_4 ) )
F_37 ( V_2 , V_54 ) ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 , void * V_169 , bool V_170 )
{
struct V_53 * V_54 ;
V_54 = F_121 ( V_2 , V_169 , V_170 ) ;
if ( ! V_54 )
return;
F_43 ( V_54 ) ;
F_104 ( & V_54 -> V_130 ) ;
F_105 ( V_54 , V_131 ) ;
return;
}
static int F_122 ( struct V_1 * V_2 , struct V_174 * V_180 )
{
if ( F_123 ( V_2 -> V_10 , V_180 , true ) ) {
F_124 ( V_2 , V_181 , V_2 -> V_4 ,
L_3 ,
V_180 , V_2 -> V_4 -> V_182 ) ;
return - V_25 ;
}
return F_117 ( V_2 , V_180 , true ) ;
}
static void F_125 ( struct V_1 * V_2 , struct V_174 * V_180 )
{
return F_120 ( V_2 , V_180 , true ) ;
}
static int F_126 ( struct V_154 * V_155 ,
unsigned long V_156 , void * V_157 )
{
struct V_183 * V_184 = (struct V_183 * ) V_157 ;
struct V_3 * V_4 = (struct V_3 * ) V_184 -> V_185 -> V_4 ;
struct V_1 * V_2 = F_31 ( V_4 ) ;
if ( F_127 () )
return V_159 ;
if ( ! F_92 ( V_4 ) )
return V_159 ;
if ( ! V_2 || ! V_2 -> V_10 )
return V_159 ;
switch ( V_156 ) {
case V_186 :
if ( F_122 ( V_2 , & V_184 -> V_54 ) )
return V_168 ;
break;
case V_187 :
F_125 ( V_2 , & V_184 -> V_54 ) ;
break;
}
return V_188 ;
}
static int F_128 ( struct V_1 * V_2 , struct V_178 * V_189 )
{
if ( F_123 ( V_2 -> V_10 , V_189 , false ) ) {
F_124 ( V_2 , V_181 , V_2 -> V_4 ,
L_4 ,
V_189 , V_2 -> V_4 -> V_182 ) ;
return - V_25 ;
}
return F_117 ( V_2 , V_189 , false ) ;
}
static void F_129 ( struct V_1 * V_2 , struct V_178 * V_189 )
{
return F_120 ( V_2 , V_189 , false ) ;
}
static int F_130 ( struct V_154 * V_155 ,
unsigned long V_156 , void * V_157 )
{
struct V_190 * V_191 = (struct V_190 * ) V_157 ;
struct V_3 * V_4 = (struct V_3 * ) V_191 -> V_192 -> V_4 ;
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_178 V_189 ;
if ( ! F_92 ( V_4 ) )
return V_159 ;
if ( ! V_2 || ! V_2 -> V_10 )
return V_159 ;
switch ( V_156 ) {
case V_186 :
V_189 . V_193 = V_191 -> V_194 ;
if ( F_128 ( V_2 , & V_189 ) )
return V_168 ;
break;
case V_187 :
V_189 . V_193 = V_191 -> V_194 ;
F_129 ( V_2 , & V_189 ) ;
break;
}
return V_188 ;
}
static int T_8 F_131 ( void )
{
int V_6 ;
F_132 () ;
F_133 ( & V_195 ) ;
F_134 ( & V_196 ) ;
F_135 ( & V_197 ) ;
V_6 = F_110 ( & V_198 ) ;
if ( V_6 < 0 )
goto error;
return 0 ;
error:
F_136 ( & V_197 ) ;
F_137 ( & V_196 ) ;
F_138 ( & V_195 ) ;
return V_6 ;
}
static void T_9 F_139 ( void )
{
F_140 ( & V_198 ) ;
F_138 ( & V_195 ) ;
F_136 ( & V_197 ) ;
F_137 ( & V_196 ) ;
}
