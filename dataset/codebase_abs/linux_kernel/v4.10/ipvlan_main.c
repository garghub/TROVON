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
V_6 = F_19 ( V_4 , V_35 , V_10 ) ;
if ( V_6 )
goto V_6;
V_4 -> V_17 |= V_36 ;
return 0 ;
V_6:
F_20 ( V_10 ) ;
return V_6 ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = F_22 ( V_4 ) ;
struct V_37 * V_38 ;
V_4 -> V_17 &= ~ V_36 ;
if ( V_10 -> V_13 == V_14 ) {
V_4 -> V_17 &= ~ V_18 ;
F_5 () ;
V_4 -> V_15 = NULL ;
}
F_23 ( V_4 ) ;
F_24 ( & V_10 -> V_33 ) ;
while ( ( V_38 = F_25 ( & V_10 -> V_32 ) ) != NULL ) {
if ( V_38 -> V_4 )
F_26 ( V_38 -> V_4 ) ;
F_27 ( V_38 ) ;
}
F_20 ( V_10 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
const struct V_3 * V_39 = V_2 -> V_39 ;
struct V_9 * V_10 = V_2 -> V_10 ;
V_4 -> V_40 = ( V_4 -> V_40 & ~ V_41 ) |
( V_39 -> V_40 & V_41 ) ;
V_4 -> V_42 = V_39 -> V_42 & V_43 ;
V_4 -> V_42 |= V_44 ;
V_4 -> V_45 = V_39 -> V_45 ;
V_4 -> V_46 = V_39 -> V_46 ;
V_4 -> V_47 = V_39 -> V_47 ;
F_30 ( V_4 ) ;
V_2 -> V_48 = F_31 ( struct V_49 ) ;
if ( ! V_2 -> V_48 )
return - V_28 ;
V_10 -> V_50 += 1 ;
return 0 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
F_33 ( V_2 -> V_48 ) ;
V_10 -> V_50 -= 1 ;
if ( ! V_10 -> V_50 )
F_21 ( V_10 -> V_4 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
struct V_51 * V_52 ;
if ( V_2 -> V_10 -> V_13 == V_19 ||
V_2 -> V_10 -> V_13 == V_14 )
V_4 -> V_20 |= V_21 ;
else
V_4 -> V_20 &= ~ V_21 ;
F_10 (addr, &ipvlan->addrs, anode)
F_35 ( V_2 , V_52 ) ;
return F_36 ( V_39 , V_39 -> V_53 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
struct V_51 * V_52 ;
F_38 ( V_39 , V_4 ) ;
F_39 ( V_39 , V_4 ) ;
F_40 ( V_39 , V_39 -> V_53 ) ;
F_10 (addr, &ipvlan->addrs, anode)
F_41 ( V_52 ) ;
return 0 ;
}
static T_2 F_42 ( struct V_37 * V_38 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_29 ( V_4 ) ;
int V_54 = V_38 -> V_55 ;
int V_56 ;
V_56 = F_43 ( V_38 , V_4 ) ;
if ( F_44 ( V_56 == V_57 || V_56 == V_58 ) ) {
struct V_49 * V_59 ;
V_59 = F_45 ( V_2 -> V_48 ) ;
F_46 ( & V_59 -> V_60 ) ;
V_59 -> V_61 ++ ;
V_59 -> V_62 += V_54 ;
F_47 ( & V_59 -> V_60 ) ;
} else {
F_48 ( V_2 -> V_48 -> V_63 ) ;
}
return V_56 ;
}
static T_3 F_49 ( struct V_3 * V_4 ,
T_3 V_42 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
return V_42 & ( V_2 -> V_64 | ~ V_43 ) ;
}
static void F_50 ( struct V_3 * V_4 , int V_65 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
if ( V_65 & V_66 )
F_51 ( V_39 , V_4 -> V_20 & V_66 ? 1 : - 1 ) ;
}
static void F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
if ( V_4 -> V_20 & ( V_67 | V_66 ) ) {
F_53 ( V_2 -> V_68 , V_69 ) ;
} else {
struct V_70 * V_71 ;
F_54 ( V_72 , V_69 ) ;
F_55 ( V_72 , V_69 ) ;
F_56 (ha, dev)
F_57 ( F_58 ( V_71 -> V_52 ) , V_72 ) ;
F_57 ( F_58 ( V_4 -> V_73 ) , V_72 ) ;
F_59 ( V_2 -> V_68 , V_72 ,
V_69 ) ;
}
F_60 ( V_2 -> V_39 , V_4 ) ;
F_61 ( V_2 -> V_39 , V_4 ) ;
}
static struct V_74 * F_62 ( struct V_3 * V_4 ,
struct V_74 * V_75 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
if ( V_2 -> V_48 ) {
struct V_49 * V_59 ;
T_4 V_76 , V_77 , V_78 , V_61 , V_62 ;
T_5 V_79 = 0 , V_63 = 0 ;
T_5 V_80 ;
int V_22 ;
F_63 (idx) {
V_59 = F_64 ( V_2 -> V_48 , V_22 ) ;
do {
V_80 = F_65 ( & V_59 -> V_60 ) ;
V_76 = V_59 -> V_76 ;
V_77 = V_59 -> V_77 ;
V_78 = V_59 -> V_78 ;
V_61 = V_59 -> V_61 ;
V_62 = V_59 -> V_62 ;
} while ( F_66 ( & V_59 -> V_60 ,
V_80 ) );
V_75 -> V_81 += V_76 ;
V_75 -> V_77 += V_77 ;
V_75 -> V_82 += V_78 ;
V_75 -> V_83 += V_61 ;
V_75 -> V_62 += V_62 ;
V_79 += V_59 -> V_79 ;
V_63 += V_59 -> V_63 ;
}
V_75 -> V_84 = V_79 ;
V_75 -> V_85 = V_79 ;
V_75 -> V_86 = V_63 ;
}
return V_75 ;
}
static int F_67 ( struct V_3 * V_4 , T_6 V_87 , T_1 V_88 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
return F_68 ( V_39 , V_87 , V_88 ) ;
}
static int F_69 ( struct V_3 * V_4 , T_6 V_87 ,
T_1 V_88 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
F_70 ( V_39 , V_87 , V_88 ) ;
return 0 ;
}
static int F_71 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
return V_2 -> V_39 -> V_89 ;
}
static int F_72 ( struct V_37 * V_38 , struct V_3 * V_4 ,
unsigned short type , const void * V_90 ,
const void * V_91 , unsigned V_55 )
{
const struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_3 * V_39 = V_2 -> V_39 ;
return F_73 ( V_38 , V_39 , type , V_90 ,
V_91 ? : V_4 -> V_53 , V_55 ) ;
}
static int F_74 ( struct V_3 * V_4 ,
struct V_92 * V_93 )
{
const struct V_1 * V_2 = F_29 ( V_4 ) ;
return F_75 ( V_2 -> V_39 , V_93 ) ;
}
static void F_76 ( struct V_3 * V_4 ,
struct V_94 * V_95 )
{
F_77 ( V_95 -> V_96 , V_97 , sizeof( V_95 -> V_96 ) ) ;
F_77 ( V_95 -> V_98 , V_99 , sizeof( V_95 -> V_98 ) ) ;
}
static T_5 F_78 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_29 ( V_4 ) ;
return V_2 -> V_100 ;
}
static void F_79 ( struct V_3 * V_4 , T_5 V_101 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
V_2 -> V_100 = V_101 ;
}
static int F_80 ( struct V_3 * V_4 ,
struct V_102 * V_103 [] , struct V_102 * V_104 [] )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_9 * V_10 = F_22 ( V_2 -> V_39 ) ;
int V_6 = 0 ;
if ( V_104 && V_104 [ V_105 ] ) {
T_1 V_106 = F_81 ( V_104 [ V_105 ] ) ;
V_6 = F_8 ( V_10 , V_106 ) ;
}
return V_6 ;
}
static T_7 F_82 ( const struct V_3 * V_4 )
{
return ( 0
+ F_83 ( 2 )
) ;
}
static int F_84 ( struct V_102 * V_103 [] , struct V_102 * V_104 [] )
{
if ( V_104 && V_104 [ V_105 ] ) {
T_1 V_13 = F_81 ( V_104 [ V_105 ] ) ;
if ( V_13 < V_107 || V_13 >= V_108 )
return - V_25 ;
}
return 0 ;
}
static int F_85 ( struct V_37 * V_38 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_9 * V_10 = F_22 ( V_2 -> V_39 ) ;
int V_56 = - V_25 ;
if ( ! V_10 )
goto V_6;
V_56 = - V_109 ;
if ( F_86 ( V_38 , V_105 , V_10 -> V_13 ) )
goto V_6;
return 0 ;
V_6:
return V_56 ;
}
static int F_87 ( struct V_110 * V_111 , struct V_3 * V_4 ,
struct V_102 * V_103 [] , struct V_102 * V_104 [] )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_9 * V_10 ;
struct V_3 * V_39 ;
int V_6 ;
T_1 V_13 = V_19 ;
bool V_112 = false ;
if ( ! V_103 [ V_113 ] )
return - V_25 ;
V_39 = F_88 ( V_111 , F_89 ( V_103 [ V_113 ] ) ) ;
if ( ! V_39 )
return - V_114 ;
if ( F_90 ( V_39 ) ) {
struct V_1 * V_115 = F_29 ( V_39 ) ;
V_39 = V_115 -> V_39 ;
} else if ( ! F_91 ( V_39 ) ) {
V_6 = F_11 ( V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
V_112 = true ;
}
if ( V_104 && V_104 [ V_105 ] )
V_13 = F_81 ( V_104 [ V_105 ] ) ;
V_10 = F_22 ( V_39 ) ;
V_2 -> V_39 = V_39 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_64 = V_43 ;
F_1 ( V_2 , V_39 ) ;
F_15 ( & V_2 -> V_116 ) ;
memcpy ( V_4 -> V_53 , V_39 -> V_53 , V_117 ) ;
V_4 -> V_17 |= V_118 ;
V_6 = F_92 ( V_4 ) ;
if ( V_6 < 0 )
goto V_119;
V_6 = F_93 ( V_39 , V_4 ) ;
if ( V_6 ) {
goto V_120;
}
V_6 = F_8 ( V_10 , V_13 ) ;
if ( V_6 ) {
goto V_121;
}
F_94 ( & V_2 -> V_122 , & V_10 -> V_29 ) ;
F_95 ( V_39 , V_4 ) ;
return 0 ;
V_121:
F_96 ( V_39 , V_4 ) ;
V_120:
F_97 ( V_4 ) ;
V_119:
if ( V_112 )
F_21 ( V_39 ) ;
return V_6 ;
}
static void F_98 ( struct V_3 * V_4 , struct V_123 * V_124 )
{
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_51 * V_52 , * V_125 ;
F_99 (addr, next, &ipvlan->addrs, anode) {
F_41 ( V_52 ) ;
F_100 ( & V_52 -> V_126 ) ;
F_101 ( V_52 , V_127 ) ;
}
F_102 ( & V_2 -> V_122 ) ;
F_103 ( V_4 , V_124 ) ;
F_96 ( V_2 -> V_39 , V_4 ) ;
}
static void F_104 ( struct V_3 * V_4 )
{
F_105 ( V_4 ) ;
V_4 -> V_17 &= ~ ( V_128 | V_129 ) ;
V_4 -> V_17 |= V_130 | V_131 ;
V_4 -> V_132 = & V_133 ;
V_4 -> V_134 = V_135 ;
V_4 -> V_136 = & V_137 ;
V_4 -> V_138 = & V_139 ;
}
static int F_106 ( struct V_140 * V_141 )
{
return F_107 ( V_141 ) ;
}
static int F_108 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
struct V_3 * V_4 = F_109 ( V_145 ) ;
struct V_1 * V_2 , * V_125 ;
struct V_9 * V_10 ;
F_110 ( V_146 ) ;
if ( ! F_91 ( V_4 ) )
return V_147 ;
V_10 = F_22 ( V_4 ) ;
switch ( V_144 ) {
case V_148 :
F_10 (ipvlan, &port->ipvlans, pnode)
F_95 ( V_2 -> V_39 ,
V_2 -> V_4 ) ;
break;
case V_149 :
if ( V_4 -> V_150 != V_151 )
break;
F_99 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_140 -> V_152 ( V_2 -> V_4 ,
& V_146 ) ;
F_111 ( & V_146 ) ;
break;
case V_153 :
F_10 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_42 = V_4 -> V_42 & V_43 ;
V_2 -> V_4 -> V_45 = V_4 -> V_45 ;
V_2 -> V_4 -> V_46 = V_4 -> V_46 ;
F_112 ( V_2 -> V_4 ) ;
}
break;
case V_154 :
F_10 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_155 :
return V_156 ;
}
return V_147 ;
}
static int F_113 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
struct V_51 * V_52 ;
if ( F_114 ( V_2 -> V_10 , V_158 , true ) ) {
F_115 ( V_2 , V_159 , V_2 -> V_4 ,
L_3 ,
V_158 , V_2 -> V_4 -> V_160 ) ;
return - V_25 ;
}
V_52 = F_14 ( sizeof( struct V_51 ) , V_161 ) ;
if ( ! V_52 )
return - V_28 ;
V_52 -> V_162 = V_2 ;
memcpy ( & V_52 -> V_163 , V_158 , sizeof( struct V_157 ) ) ;
V_52 -> V_164 = V_165 ;
F_116 ( & V_52 -> V_126 , & V_2 -> V_116 ) ;
if ( F_117 ( V_2 -> V_4 ) )
F_35 ( V_2 , V_52 ) ;
return 0 ;
}
static void F_118 ( struct V_1 * V_2 , struct V_157 * V_158 )
{
struct V_51 * V_52 ;
V_52 = F_119 ( V_2 , V_158 , true ) ;
if ( ! V_52 )
return;
F_41 ( V_52 ) ;
F_100 ( & V_52 -> V_126 ) ;
F_101 ( V_52 , V_127 ) ;
return;
}
static int F_120 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
struct V_166 * V_167 = (struct V_166 * ) V_145 ;
struct V_3 * V_4 = (struct V_3 * ) V_167 -> V_168 -> V_4 ;
struct V_1 * V_2 = F_29 ( V_4 ) ;
if ( F_121 () )
return V_147 ;
if ( ! F_90 ( V_4 ) )
return V_147 ;
if ( ! V_2 || ! V_2 -> V_10 )
return V_147 ;
switch ( V_144 ) {
case V_169 :
if ( F_113 ( V_2 , & V_167 -> V_52 ) )
return V_156 ;
break;
case V_170 :
F_118 ( V_2 , & V_167 -> V_52 ) ;
break;
}
return V_171 ;
}
static int F_122 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
struct V_51 * V_52 ;
if ( F_114 ( V_2 -> V_10 , V_173 , false ) ) {
F_115 ( V_2 , V_159 , V_2 -> V_4 ,
L_4 ,
V_173 , V_2 -> V_4 -> V_160 ) ;
return - V_25 ;
}
V_52 = F_14 ( sizeof( struct V_51 ) , V_27 ) ;
if ( ! V_52 )
return - V_28 ;
V_52 -> V_162 = V_2 ;
memcpy ( & V_52 -> V_174 , V_173 , sizeof( struct V_172 ) ) ;
V_52 -> V_164 = V_175 ;
F_116 ( & V_52 -> V_126 , & V_2 -> V_116 ) ;
if ( F_117 ( V_2 -> V_4 ) )
F_35 ( V_2 , V_52 ) ;
return 0 ;
}
static void F_123 ( struct V_1 * V_2 , struct V_172 * V_173 )
{
struct V_51 * V_52 ;
V_52 = F_119 ( V_2 , V_173 , false ) ;
if ( ! V_52 )
return;
F_41 ( V_52 ) ;
F_100 ( & V_52 -> V_126 ) ;
F_101 ( V_52 , V_127 ) ;
return;
}
static int F_124 ( struct V_142 * V_143 ,
unsigned long V_144 , void * V_145 )
{
struct V_176 * V_177 = (struct V_176 * ) V_145 ;
struct V_3 * V_4 = (struct V_3 * ) V_177 -> V_178 -> V_4 ;
struct V_1 * V_2 = F_29 ( V_4 ) ;
struct V_172 V_173 ;
if ( ! F_90 ( V_4 ) )
return V_147 ;
if ( ! V_2 || ! V_2 -> V_10 )
return V_147 ;
switch ( V_144 ) {
case V_169 :
V_173 . V_179 = V_177 -> V_180 ;
if ( F_122 ( V_2 , & V_173 ) )
return V_156 ;
break;
case V_170 :
V_173 . V_179 = V_177 -> V_180 ;
F_123 ( V_2 , & V_173 ) ;
break;
}
return V_171 ;
}
static int T_8 F_125 ( void )
{
int V_6 ;
F_126 () ;
F_127 ( & V_181 ) ;
F_128 ( & V_182 ) ;
F_129 ( & V_183 ) ;
V_6 = F_106 ( & V_184 ) ;
if ( V_6 < 0 )
goto error;
return 0 ;
error:
F_130 ( & V_183 ) ;
F_131 ( & V_182 ) ;
F_132 ( & V_181 ) ;
return V_6 ;
}
static void T_9 F_133 ( void )
{
F_134 ( & V_184 ) ;
F_132 ( & V_181 ) ;
F_130 ( & V_183 ) ;
F_131 ( & V_182 ) ;
}
