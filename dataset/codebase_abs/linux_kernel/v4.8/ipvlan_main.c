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
static int F_19 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
const struct V_3 * V_32 = V_2 -> V_32 ;
struct V_7 * V_8 = V_2 -> V_8 ;
V_4 -> V_33 = ( V_4 -> V_33 & ~ V_34 ) |
( V_32 -> V_33 & V_34 ) ;
V_4 -> V_35 = V_32 -> V_35 & V_36 ;
V_4 -> V_35 |= V_37 ;
V_4 -> V_38 = V_32 -> V_38 ;
V_4 -> V_39 = V_32 -> V_39 ;
V_4 -> V_40 = V_32 -> V_40 ;
F_21 ( V_4 ) ;
V_2 -> V_41 = F_22 ( struct V_42 ) ;
if ( ! V_2 -> V_41 )
return - V_21 ;
V_8 -> V_43 += 1 ;
return 0 ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
F_24 ( V_2 -> V_41 ) ;
V_8 -> V_43 -= 1 ;
if ( ! V_8 -> V_43 )
F_14 ( V_8 -> V_4 ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_32 = V_2 -> V_32 ;
struct V_44 * V_45 ;
if ( V_2 -> V_8 -> V_10 == V_11 )
V_4 -> V_12 |= V_13 ;
else
V_4 -> V_12 &= ~ V_13 ;
F_3 (addr, &ipvlan->addrs, anode)
F_26 ( V_2 , V_45 ) ;
return F_27 ( V_32 , V_32 -> V_46 ) ;
}
static int F_28 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_32 = V_2 -> V_32 ;
struct V_44 * V_45 ;
F_29 ( V_32 , V_4 ) ;
F_30 ( V_32 , V_4 ) ;
F_31 ( V_32 , V_32 -> V_46 ) ;
F_3 (addr, &ipvlan->addrs, anode)
F_32 ( V_45 ) ;
return 0 ;
}
static T_2 F_33 ( struct V_47 * V_48 ,
struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
int V_49 = V_48 -> V_50 ;
int V_51 ;
V_51 = F_34 ( V_48 , V_4 ) ;
if ( F_35 ( V_51 == V_52 || V_51 == V_53 ) ) {
struct V_42 * V_54 ;
V_54 = F_36 ( V_2 -> V_41 ) ;
F_37 ( & V_54 -> V_55 ) ;
V_54 -> V_56 ++ ;
V_54 -> V_57 += V_49 ;
F_38 ( & V_54 -> V_55 ) ;
} else {
F_39 ( V_2 -> V_41 -> V_58 ) ;
}
return V_51 ;
}
static T_3 F_40 ( struct V_3 * V_4 ,
T_3 V_35 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
return V_35 & ( V_2 -> V_59 | ~ V_36 ) ;
}
static void F_41 ( struct V_3 * V_4 , int V_60 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_32 = V_2 -> V_32 ;
if ( V_60 & V_61 )
F_42 ( V_32 , V_4 -> V_12 & V_61 ? 1 : - 1 ) ;
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( V_4 -> V_12 & ( V_62 | V_61 ) ) {
F_44 ( V_2 -> V_63 , V_64 ) ;
} else {
struct V_65 * V_66 ;
F_45 ( V_67 , V_64 ) ;
F_46 ( V_67 , V_64 ) ;
F_47 (ha, dev)
F_48 ( F_49 ( V_66 -> V_45 ) , V_67 ) ;
F_48 ( F_49 ( V_4 -> V_68 ) , V_67 ) ;
F_50 ( V_2 -> V_63 , V_67 ,
V_64 ) ;
}
F_51 ( V_2 -> V_32 , V_4 ) ;
F_52 ( V_2 -> V_32 , V_4 ) ;
}
static struct V_69 * F_53 ( struct V_3 * V_4 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( V_2 -> V_41 ) {
struct V_42 * V_54 ;
T_4 V_71 , V_72 , V_73 , V_56 , V_57 ;
T_5 V_74 = 0 , V_58 = 0 ;
T_5 V_75 ;
int V_15 ;
F_54 (idx) {
V_54 = F_55 ( V_2 -> V_41 , V_15 ) ;
do {
V_75 = F_56 ( & V_54 -> V_55 ) ;
V_71 = V_54 -> V_71 ;
V_72 = V_54 -> V_72 ;
V_73 = V_54 -> V_73 ;
V_56 = V_54 -> V_56 ;
V_57 = V_54 -> V_57 ;
} while ( F_57 ( & V_54 -> V_55 ,
V_75 ) );
V_70 -> V_76 += V_71 ;
V_70 -> V_72 += V_72 ;
V_70 -> V_77 += V_73 ;
V_70 -> V_78 += V_56 ;
V_70 -> V_57 += V_57 ;
V_74 += V_54 -> V_74 ;
V_58 += V_54 -> V_58 ;
}
V_70 -> V_79 = V_74 ;
V_70 -> V_80 = V_74 ;
V_70 -> V_81 = V_58 ;
}
return V_70 ;
}
static int F_58 ( struct V_3 * V_4 , T_6 V_82 , T_1 V_83 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_32 = V_2 -> V_32 ;
return F_59 ( V_32 , V_82 , V_83 ) ;
}
static int F_60 ( struct V_3 * V_4 , T_6 V_82 ,
T_1 V_83 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_32 = V_2 -> V_32 ;
F_61 ( V_32 , V_82 , V_83 ) ;
return 0 ;
}
static int F_62 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
return V_2 -> V_32 -> V_84 ;
}
static int F_63 ( struct V_47 * V_48 , struct V_3 * V_4 ,
unsigned short type , const void * V_85 ,
const void * V_86 , unsigned V_50 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_3 * V_32 = V_2 -> V_32 ;
return F_64 ( V_48 , V_32 , type , V_85 ,
V_86 ? : V_4 -> V_46 , V_50 ) ;
}
static int F_65 ( struct V_3 * V_4 ,
struct V_87 * V_88 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
return F_66 ( V_2 -> V_32 , V_88 ) ;
}
static void F_67 ( struct V_3 * V_4 ,
struct V_89 * V_90 )
{
F_68 ( V_90 -> V_91 , V_92 , sizeof( V_90 -> V_91 ) ) ;
F_68 ( V_90 -> V_93 , V_94 , sizeof( V_90 -> V_93 ) ) ;
}
static T_5 F_69 ( struct V_3 * V_4 )
{
const struct V_1 * V_2 = F_20 ( V_4 ) ;
return V_2 -> V_95 ;
}
static void F_70 ( struct V_3 * V_4 , T_5 V_96 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
V_2 -> V_95 = V_96 ;
}
static int F_71 ( struct V_3 * V_4 ,
struct V_97 * V_98 [] , struct V_97 * V_99 [] )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = F_15 ( V_2 -> V_32 ) ;
if ( V_99 && V_99 [ V_100 ] ) {
T_1 V_101 = F_72 ( V_99 [ V_100 ] ) ;
F_2 ( V_8 , V_101 ) ;
}
return 0 ;
}
static T_7 F_73 ( const struct V_3 * V_4 )
{
return ( 0
+ F_74 ( 2 )
) ;
}
static int F_75 ( struct V_97 * V_98 [] , struct V_97 * V_99 [] )
{
if ( V_99 && V_99 [ V_100 ] ) {
T_1 V_10 = F_72 ( V_99 [ V_100 ] ) ;
if ( V_10 < V_102 || V_10 >= V_103 )
return - V_18 ;
}
return 0 ;
}
static int F_76 ( struct V_47 * V_48 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 = F_15 ( V_2 -> V_32 ) ;
int V_51 = - V_18 ;
if ( ! V_8 )
goto V_14;
V_51 = - V_104 ;
if ( F_77 ( V_48 , V_100 , V_8 -> V_10 ) )
goto V_14;
return 0 ;
V_14:
return V_51 ;
}
static int F_78 ( struct V_105 * V_106 , struct V_3 * V_4 ,
struct V_97 * V_98 [] , struct V_97 * V_99 [] )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_3 * V_32 ;
int V_14 ;
T_1 V_10 = V_11 ;
if ( ! V_98 [ V_107 ] )
return - V_18 ;
V_32 = F_79 ( V_106 , F_80 ( V_98 [ V_107 ] ) ) ;
if ( ! V_32 )
return - V_108 ;
if ( F_81 ( V_32 ) ) {
struct V_1 * V_109 = F_20 ( V_32 ) ;
V_32 = V_109 -> V_32 ;
} else if ( ! F_82 ( V_32 ) ) {
V_14 = F_4 ( V_32 ) ;
if ( V_14 < 0 )
return V_14 ;
}
if ( V_99 && V_99 [ V_100 ] )
V_10 = F_72 ( V_99 [ V_100 ] ) ;
V_8 = F_15 ( V_32 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_59 = V_36 ;
F_1 ( V_2 , V_32 ) ;
F_8 ( & V_2 -> V_110 ) ;
memcpy ( V_4 -> V_46 , V_32 -> V_46 , V_111 ) ;
V_4 -> V_29 |= V_112 ;
V_14 = F_83 ( V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_84 ( V_32 , V_4 ) ;
if ( V_14 ) {
F_85 ( V_4 ) ;
return V_14 ;
}
F_86 ( & V_2 -> V_113 , & V_8 -> V_22 ) ;
F_2 ( V_8 , V_10 ) ;
F_87 ( V_32 , V_4 ) ;
return 0 ;
}
static void F_88 ( struct V_3 * V_4 , struct V_114 * V_115 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_44 * V_45 , * V_116 ;
F_89 (addr, next, &ipvlan->addrs, anode) {
F_32 ( V_45 ) ;
F_90 ( & V_45 -> V_117 ) ;
F_13 ( V_45 , V_31 ) ;
}
F_91 ( & V_2 -> V_113 ) ;
F_92 ( V_4 , V_115 ) ;
F_93 ( V_2 -> V_32 , V_4 ) ;
}
static void F_94 ( struct V_3 * V_4 )
{
F_95 ( V_4 ) ;
V_4 -> V_29 &= ~ ( V_118 | V_119 ) ;
V_4 -> V_29 |= V_120 | V_121 ;
V_4 -> V_122 = & V_123 ;
V_4 -> V_124 = V_125 ;
V_4 -> V_126 = & V_127 ;
V_4 -> V_128 = & V_129 ;
}
static int F_96 ( struct V_130 * V_131 )
{
return F_97 ( V_131 ) ;
}
static int F_98 ( struct V_132 * V_133 ,
unsigned long V_134 , void * V_135 )
{
struct V_3 * V_4 = F_99 ( V_135 ) ;
struct V_1 * V_2 , * V_116 ;
struct V_7 * V_8 ;
F_100 ( V_136 ) ;
if ( ! F_82 ( V_4 ) )
return V_137 ;
V_8 = F_15 ( V_4 ) ;
switch ( V_134 ) {
case V_138 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_87 ( V_2 -> V_32 ,
V_2 -> V_4 ) ;
break;
case V_139 :
if ( V_4 -> V_140 != V_141 )
break;
F_89 (ipvlan, next, &port->ipvlans,
pnode)
V_2 -> V_4 -> V_130 -> V_142 ( V_2 -> V_4 ,
& V_136 ) ;
F_101 ( & V_136 ) ;
break;
case V_143 :
F_3 (ipvlan, &port->ipvlans, pnode) {
V_2 -> V_4 -> V_35 = V_4 -> V_35 & V_36 ;
V_2 -> V_4 -> V_38 = V_4 -> V_38 ;
V_2 -> V_4 -> V_39 = V_4 -> V_39 ;
F_102 ( V_2 -> V_4 ) ;
}
break;
case V_144 :
F_3 (ipvlan, &port->ipvlans, pnode)
F_1 ( V_2 , V_4 ) ;
break;
case V_145 :
return V_146 ;
}
return V_137 ;
}
static int F_103 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_44 * V_45 ;
if ( F_104 ( V_2 -> V_8 , V_148 , true ) ) {
F_105 ( V_2 , V_149 , V_2 -> V_4 ,
L_3 ,
V_148 , V_2 -> V_4 -> V_150 ) ;
return - V_18 ;
}
V_45 = F_7 ( sizeof( struct V_44 ) , V_151 ) ;
if ( ! V_45 )
return - V_21 ;
V_45 -> V_152 = V_2 ;
memcpy ( & V_45 -> V_153 , V_148 , sizeof( struct V_147 ) ) ;
V_45 -> V_154 = V_155 ;
F_106 ( & V_45 -> V_117 , & V_2 -> V_110 ) ;
if ( F_107 ( V_2 -> V_4 ) )
F_26 ( V_2 , V_45 ) ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 , struct V_147 * V_148 )
{
struct V_44 * V_45 ;
V_45 = F_109 ( V_2 , V_148 , true ) ;
if ( ! V_45 )
return;
F_32 ( V_45 ) ;
F_90 ( & V_45 -> V_117 ) ;
F_13 ( V_45 , V_31 ) ;
return;
}
static int F_110 ( struct V_132 * V_133 ,
unsigned long V_134 , void * V_135 )
{
struct V_156 * V_157 = (struct V_156 * ) V_135 ;
struct V_3 * V_4 = (struct V_3 * ) V_157 -> V_158 -> V_4 ;
struct V_1 * V_2 = F_20 ( V_4 ) ;
if ( F_111 () )
return V_137 ;
if ( ! F_81 ( V_4 ) )
return V_137 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_137 ;
switch ( V_134 ) {
case V_159 :
if ( F_103 ( V_2 , & V_157 -> V_45 ) )
return V_146 ;
break;
case V_160 :
F_108 ( V_2 , & V_157 -> V_45 ) ;
break;
}
return V_161 ;
}
static int F_112 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
struct V_44 * V_45 ;
if ( F_104 ( V_2 -> V_8 , V_163 , false ) ) {
F_105 ( V_2 , V_149 , V_2 -> V_4 ,
L_4 ,
V_163 , V_2 -> V_4 -> V_150 ) ;
return - V_18 ;
}
V_45 = F_7 ( sizeof( struct V_44 ) , V_20 ) ;
if ( ! V_45 )
return - V_21 ;
V_45 -> V_152 = V_2 ;
memcpy ( & V_45 -> V_164 , V_163 , sizeof( struct V_162 ) ) ;
V_45 -> V_154 = V_165 ;
F_106 ( & V_45 -> V_117 , & V_2 -> V_110 ) ;
if ( F_107 ( V_2 -> V_4 ) )
F_26 ( V_2 , V_45 ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
struct V_44 * V_45 ;
V_45 = F_109 ( V_2 , V_163 , false ) ;
if ( ! V_45 )
return;
F_32 ( V_45 ) ;
F_90 ( & V_45 -> V_117 ) ;
F_13 ( V_45 , V_31 ) ;
return;
}
static int F_114 ( struct V_132 * V_133 ,
unsigned long V_134 , void * V_135 )
{
struct V_166 * V_167 = (struct V_166 * ) V_135 ;
struct V_3 * V_4 = (struct V_3 * ) V_167 -> V_168 -> V_4 ;
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_162 V_163 ;
if ( ! F_81 ( V_4 ) )
return V_137 ;
if ( ! V_2 || ! V_2 -> V_8 )
return V_137 ;
switch ( V_134 ) {
case V_159 :
V_163 . V_169 = V_167 -> V_170 ;
if ( F_112 ( V_2 , & V_163 ) )
return V_146 ;
break;
case V_160 :
V_163 . V_169 = V_167 -> V_170 ;
F_113 ( V_2 , & V_163 ) ;
break;
}
return V_161 ;
}
static int T_8 F_115 ( void )
{
int V_14 ;
F_116 () ;
F_117 ( & V_171 ) ;
F_118 ( & V_172 ) ;
F_119 ( & V_173 ) ;
V_14 = F_96 ( & V_174 ) ;
if ( V_14 < 0 )
goto error;
return 0 ;
error:
F_120 ( & V_173 ) ;
F_121 ( & V_172 ) ;
F_122 ( & V_171 ) ;
return V_14 ;
}
static void T_9 F_123 ( void )
{
F_124 ( & V_174 ) ;
F_122 ( & V_171 ) ;
F_120 ( & V_173 ) ;
F_121 ( & V_172 ) ;
}
