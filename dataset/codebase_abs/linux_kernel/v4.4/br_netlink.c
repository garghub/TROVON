static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 ;
T_2 V_6 = 0 , V_7 = 0 , V_8 = 0 ;
T_2 V_9 , V_10 ;
int V_11 = 0 ;
if ( ! ( V_3 & V_12 ) )
return 0 ;
V_10 = F_2 ( V_2 ) ;
F_3 (v, &vg->vlan_list, vlist) {
V_9 = 0 ;
if ( ! F_4 ( V_5 ) )
continue;
if ( V_5 -> V_13 == V_10 )
V_9 |= V_14 ;
if ( V_5 -> V_9 & V_15 )
V_9 |= V_15 ;
if ( V_6 == 0 ) {
goto V_16;
} else if ( ( V_5 -> V_13 - V_7 ) == 1 &&
V_9 == V_8 ) {
V_7 = V_5 -> V_13 ;
continue;
} else {
if ( ( V_7 - V_6 ) > 0 )
V_11 += 2 ;
else
V_11 += 1 ;
}
V_16:
V_6 = V_5 -> V_13 ;
V_7 = V_5 -> V_13 ;
V_8 = V_9 ;
}
if ( V_6 != 0 ) {
if ( ( V_7 - V_6 ) > 0 )
V_11 += 2 ;
else
V_11 += 1 ;
}
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_11 ;
if ( ! V_2 )
return 0 ;
if ( V_3 & V_17 )
return V_2 -> V_11 ;
F_6 () ;
V_11 = F_1 ( V_2 , V_3 ) ;
F_7 () ;
return V_11 ;
}
static T_3 F_8 ( const struct V_18 * V_19 ,
T_1 V_3 )
{
struct V_1 * V_2 = NULL ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 ;
F_6 () ;
if ( F_9 ( V_19 ) ) {
V_21 = F_10 ( V_19 ) ;
V_2 = F_11 ( V_21 ) ;
} else if ( V_19 -> V_25 & V_26 ) {
V_23 = F_12 ( V_19 ) ;
V_2 = F_13 ( V_23 ) ;
}
V_24 = F_5 ( V_2 , V_3 ) ;
F_7 () ;
return V_24 * F_14 ( sizeof( struct V_27 ) ) ;
}
static inline T_3 F_15 ( void )
{
return F_14 ( 1 )
+ F_14 ( 2 )
+ F_14 ( 4 )
+ F_14 ( 1 )
+ F_14 ( 1 )
+ F_14 ( 1 )
+ F_14 ( 1 )
+ F_14 ( 1 )
+ F_14 ( 1 )
+ F_14 ( 1 )
+ F_14 ( 1 )
+ F_14 ( sizeof( struct V_28 ) )
+ F_14 ( sizeof( struct V_28 ) )
+ F_14 ( sizeof( T_2 ) )
+ F_14 ( sizeof( T_2 ) )
+ F_14 ( sizeof( T_2 ) )
+ F_14 ( sizeof( T_2 ) )
+ F_14 ( sizeof( V_29 ) )
+ F_14 ( sizeof( V_29 ) )
+ F_14 ( sizeof( V_30 ) )
+ F_14 ( sizeof( V_30 ) )
+ F_14 ( sizeof( V_30 ) )
#ifdef F_16
+ F_14 ( sizeof( V_29 ) )
#endif
+ 0 ;
}
static inline T_3 F_17 ( struct V_18 * V_19 , T_1 V_3 )
{
return F_18 ( sizeof( struct V_31 ) )
+ F_14 ( V_32 )
+ F_14 ( V_33 )
+ F_14 ( 4 )
+ F_14 ( 4 )
+ F_14 ( 4 )
+ F_14 ( 1 )
+ F_14 ( F_15 () )
+ F_14 ( F_8 ( V_19 ,
V_3 ) ) ;
}
static int F_19 ( struct V_34 * V_35 ,
const struct V_20 * V_21 )
{
V_29 V_36 = ! ! ( V_21 -> V_9 & V_37 ) ;
V_30 V_38 ;
if ( F_20 ( V_35 , V_39 , V_21 -> V_40 ) ||
F_21 ( V_35 , V_41 , V_21 -> V_42 ) ||
F_22 ( V_35 , V_43 , V_21 -> V_44 ) ||
F_20 ( V_35 , V_45 , V_36 ) ||
F_20 ( V_35 , V_46 , ! ! ( V_21 -> V_9 & V_47 ) ) ||
F_20 ( V_35 , V_48 , ! ! ( V_21 -> V_9 & V_49 ) ) ||
F_20 ( V_35 , V_50 , ! ! ( V_21 -> V_9 & V_51 ) ) ||
F_20 ( V_35 , V_52 , ! ! ( V_21 -> V_9 & V_53 ) ) ||
F_20 ( V_35 , V_54 , ! ! ( V_21 -> V_9 & V_55 ) ) ||
F_20 ( V_35 , V_56 , ! ! ( V_21 -> V_9 & V_57 ) ) ||
F_20 ( V_35 , V_58 ,
! ! ( V_21 -> V_9 & V_59 ) ) ||
F_23 ( V_35 , V_60 , sizeof( struct V_28 ) ,
& V_21 -> V_61 ) ||
F_23 ( V_35 , V_62 , sizeof( struct V_28 ) ,
& V_21 -> V_63 ) ||
F_21 ( V_35 , V_64 , V_21 -> V_65 ) ||
F_21 ( V_35 , V_66 , V_21 -> V_67 ) ||
F_21 ( V_35 , V_68 , V_21 -> V_69 ) ||
F_21 ( V_35 , V_70 , V_21 -> V_71 ) ||
F_20 ( V_35 , V_72 ,
V_21 -> V_73 ) ||
F_20 ( V_35 , V_74 , V_21 -> V_75 ) )
return - V_76 ;
V_38 = F_24 ( & V_21 -> V_77 ) ;
if ( F_25 ( V_35 , V_78 , V_38 ) )
return - V_76 ;
V_38 = F_24 ( & V_21 -> V_79 ) ;
if ( F_25 ( V_35 , V_80 , V_38 ) )
return - V_76 ;
V_38 = F_24 ( & V_21 -> V_81 ) ;
if ( F_25 ( V_35 , V_82 , V_38 ) )
return - V_76 ;
#ifdef F_16
if ( F_20 ( V_35 , V_83 ,
V_21 -> V_84 ) )
return - V_76 ;
#endif
return 0 ;
}
static int F_26 ( struct V_34 * V_35 , T_2 V_85 ,
T_2 V_86 , T_2 V_9 )
{
struct V_27 V_87 ;
if ( ( V_86 - V_85 ) > 0 ) {
V_87 . V_13 = V_85 ;
V_87 . V_9 = V_9 | V_88 ;
if ( F_23 ( V_35 , V_89 ,
sizeof( V_87 ) , & V_87 ) )
goto V_90;
V_87 . V_13 = V_86 ;
V_87 . V_9 = V_9 | V_91 ;
if ( F_23 ( V_35 , V_89 ,
sizeof( V_87 ) , & V_87 ) )
goto V_90;
} else {
V_87 . V_13 = V_85 ;
V_87 . V_9 = V_9 ;
if ( F_23 ( V_35 , V_89 ,
sizeof( V_87 ) , & V_87 ) )
goto V_90;
}
return 0 ;
V_90:
return - V_76 ;
}
static int F_27 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_6 = 0 , V_7 = 0 , V_8 = 0 ;
T_2 V_9 , V_10 ;
int V_92 = 0 ;
V_10 = F_2 ( V_2 ) ;
F_3 (v, &vg->vlan_list, vlist) {
V_9 = 0 ;
if ( ! F_4 ( V_5 ) )
continue;
if ( V_5 -> V_13 == V_10 )
V_9 |= V_14 ;
if ( V_5 -> V_9 & V_15 )
V_9 |= V_15 ;
if ( V_6 == 0 ) {
goto V_16;
} else if ( ( V_5 -> V_13 - V_7 ) == 1 &&
V_9 == V_8 ) {
V_7 = V_5 -> V_13 ;
continue;
} else {
V_92 = F_26 ( V_35 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_92 )
return V_92 ;
}
V_16:
V_6 = V_5 -> V_13 ;
V_7 = V_5 -> V_13 ;
V_8 = V_9 ;
}
if ( V_6 != 0 ) {
V_92 = F_26 ( V_35 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_92 )
return V_92 ;
}
return 0 ;
}
static int F_28 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_27 V_87 ;
struct V_4 * V_5 ;
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_3 (v, &vg->vlan_list, vlist) {
if ( ! F_4 ( V_5 ) )
continue;
V_87 . V_13 = V_5 -> V_13 ;
V_87 . V_9 = 0 ;
if ( V_5 -> V_13 == V_10 )
V_87 . V_9 |= V_14 ;
if ( V_5 -> V_9 & V_15 )
V_87 . V_9 |= V_15 ;
if ( F_23 ( V_35 , V_89 ,
sizeof( V_87 ) , & V_87 ) )
goto V_90;
}
return 0 ;
V_90:
return - V_76 ;
}
static int F_29 ( struct V_34 * V_35 ,
struct V_20 * V_93 ,
T_1 V_94 , T_1 V_95 , int V_96 , unsigned int V_9 ,
T_1 V_3 , const struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_31 * V_97 ;
struct V_98 * V_99 ;
V_29 V_100 = F_30 ( V_19 ) ? V_19 -> V_100 : V_101 ;
if ( V_93 )
V_23 = V_93 -> V_23 ;
else
V_23 = F_12 ( V_19 ) ;
F_31 ( V_23 , L_1 ,
V_96 , V_19 -> V_102 , V_23 -> V_19 -> V_102 ) ;
V_99 = F_32 ( V_35 , V_94 , V_95 , V_96 , sizeof( * V_97 ) , V_9 ) ;
if ( V_99 == NULL )
return - V_76 ;
V_97 = F_33 ( V_99 ) ;
V_97 -> V_103 = V_104 ;
V_97 -> V_105 = 0 ;
V_97 -> V_106 = V_19 -> type ;
V_97 -> V_107 = V_19 -> V_108 ;
V_97 -> V_109 = F_34 ( V_19 ) ;
V_97 -> V_110 = 0 ;
if ( F_35 ( V_35 , V_111 , V_19 -> V_102 ) ||
F_22 ( V_35 , V_112 , V_23 -> V_19 -> V_108 ) ||
F_22 ( V_35 , V_113 , V_19 -> V_114 ) ||
F_20 ( V_35 , V_115 , V_100 ) ||
( V_19 -> V_116 &&
F_23 ( V_35 , V_117 , V_19 -> V_116 , V_19 -> V_118 ) ) ||
( V_19 -> V_108 != F_36 ( V_19 ) &&
F_22 ( V_35 , V_119 , F_36 ( V_19 ) ) ) )
goto V_90;
if ( V_96 == V_120 && V_93 ) {
struct V_121 * V_122
= F_37 ( V_35 , V_123 | V_124 ) ;
if ( V_122 == NULL || F_19 ( V_35 , V_93 ) < 0 )
goto V_90;
F_38 ( V_35 , V_122 ) ;
}
if ( ( V_3 & V_17 ) ||
( V_3 & V_12 ) ) {
struct V_1 * V_2 ;
struct V_121 * V_125 ;
int V_92 ;
F_6 () ;
if ( V_93 )
V_2 = F_11 ( V_93 ) ;
else
V_2 = F_13 ( V_23 ) ;
if ( ! V_2 || ! V_2 -> V_11 ) {
F_7 () ;
goto V_126;
}
V_125 = F_37 ( V_35 , V_127 ) ;
if ( ! V_125 ) {
F_7 () ;
goto V_90;
}
if ( V_3 & V_12 )
V_92 = F_27 ( V_35 , V_2 ) ;
else
V_92 = F_28 ( V_35 , V_2 ) ;
F_7 () ;
if ( V_92 )
goto V_90;
F_38 ( V_35 , V_125 ) ;
}
V_126:
F_39 ( V_35 , V_99 ) ;
return 0 ;
V_90:
F_40 ( V_35 , V_99 ) ;
return - V_76 ;
}
void F_41 ( int V_96 , struct V_20 * V_93 )
{
struct V_128 * V_128 ;
struct V_34 * V_35 ;
int V_92 = - V_129 ;
T_1 V_130 = V_12 ;
if ( ! V_93 )
return;
V_128 = F_42 ( V_93 -> V_19 ) ;
F_31 ( V_93 -> V_23 , L_2 ,
( unsigned int ) V_93 -> V_71 , V_93 -> V_19 -> V_102 , V_96 ) ;
V_35 = F_43 ( F_17 ( V_93 -> V_19 , V_130 ) , V_131 ) ;
if ( V_35 == NULL )
goto V_132;
V_92 = F_29 ( V_35 , V_93 , 0 , 0 , V_96 , 0 , V_130 , V_93 -> V_19 ) ;
if ( V_92 < 0 ) {
F_44 ( V_92 == - V_76 ) ;
F_45 ( V_35 ) ;
goto V_132;
}
F_46 ( V_35 , V_128 , 0 , V_133 , NULL , V_131 ) ;
return;
V_132:
F_47 ( V_128 , V_133 , V_92 ) ;
}
int F_48 ( struct V_34 * V_35 , T_1 V_94 , T_1 V_95 ,
struct V_18 * V_19 , T_1 V_3 , int V_134 )
{
struct V_20 * V_93 = F_49 ( V_19 ) ;
if ( ! V_93 && ! ( V_3 & V_17 ) &&
! ( V_3 & V_12 ) )
return 0 ;
return F_29 ( V_35 , V_93 , V_94 , V_95 , V_120 , V_134 ,
V_3 , V_19 ) ;
}
static int F_50 ( struct V_22 * V_23 , struct V_20 * V_21 ,
int V_135 , struct V_27 * V_87 )
{
int V_92 = 0 ;
switch ( V_135 ) {
case V_136 :
if ( V_21 ) {
V_92 = F_51 ( V_21 , V_87 -> V_13 , V_87 -> V_9 ) ;
if ( V_92 )
break;
} else {
V_87 -> V_9 |= V_137 ;
V_92 = F_52 ( V_23 , V_87 -> V_13 , V_87 -> V_9 ) ;
}
break;
case V_138 :
if ( V_21 ) {
F_53 ( V_21 , V_87 -> V_13 ) ;
if ( V_87 -> V_9 & V_139 )
F_54 ( V_21 -> V_23 , V_87 -> V_13 ) ;
} else {
F_54 ( V_23 , V_87 -> V_13 ) ;
}
break;
}
return V_92 ;
}
static int F_55 ( struct V_22 * V_23 ,
struct V_20 * V_21 ,
struct V_121 * V_140 ,
int V_135 )
{
struct V_27 * V_141 = NULL ;
struct V_27 * V_87 = NULL ;
struct V_121 * V_142 ;
int V_92 = 0 ;
int V_143 ;
F_56 (attr, af_spec, rem) {
if ( F_57 ( V_142 ) != V_89 )
continue;
if ( F_58 ( V_142 ) != sizeof( struct V_27 ) )
return - V_144 ;
V_87 = F_59 ( V_142 ) ;
if ( ! V_87 -> V_13 || V_87 -> V_13 >= V_145 )
return - V_144 ;
if ( V_87 -> V_9 & V_88 ) {
if ( V_141 )
return - V_144 ;
V_141 = V_87 ;
if ( V_141 -> V_9 & V_14 )
return - V_144 ;
continue;
}
if ( V_141 ) {
struct V_27 V_146 ;
int V_5 ;
if ( ! ( V_87 -> V_9 & V_91 ) )
return - V_144 ;
if ( V_87 -> V_13 <= V_141 -> V_13 )
return - V_144 ;
memcpy ( & V_146 , V_141 ,
sizeof( struct V_27 ) ) ;
for ( V_5 = V_141 -> V_13 ; V_5 <= V_87 -> V_13 ; V_5 ++ ) {
V_146 . V_13 = V_5 ;
V_92 = F_50 ( V_23 , V_21 , V_135 , & V_146 ) ;
if ( V_92 )
break;
}
V_141 = NULL ;
} else {
V_92 = F_50 ( V_23 , V_21 , V_135 , V_87 ) ;
}
if ( V_92 )
break;
}
return V_92 ;
}
static int F_60 ( struct V_20 * V_21 , V_29 V_40 )
{
if ( V_40 > V_147 )
return - V_144 ;
if ( V_21 -> V_23 -> V_148 == V_149 )
return - V_150 ;
if ( ! F_30 ( V_21 -> V_19 ) ||
( ! F_61 ( V_21 -> V_19 ) && V_40 != V_151 ) )
return - V_152 ;
F_62 ( V_21 , V_40 ) ;
F_63 ( V_21 ) ;
F_64 ( V_21 -> V_23 ) ;
return 0 ;
}
static void F_65 ( struct V_20 * V_21 , struct V_121 * V_153 [] ,
int V_154 , unsigned long V_155 )
{
if ( V_153 [ V_154 ] ) {
V_29 V_156 = F_66 ( V_153 [ V_154 ] ) ;
if ( V_156 )
V_21 -> V_9 |= V_155 ;
else
V_21 -> V_9 &= ~ V_155 ;
}
}
static int F_67 ( struct V_20 * V_21 , struct V_121 * V_153 [] )
{
int V_92 ;
unsigned long V_157 = V_21 -> V_9 ;
F_65 ( V_21 , V_153 , V_45 , V_37 ) ;
F_65 ( V_21 , V_153 , V_46 , V_47 ) ;
F_65 ( V_21 , V_153 , V_50 , V_51 ) ;
F_65 ( V_21 , V_153 , V_48 , V_49 ) ;
F_65 ( V_21 , V_153 , V_52 , V_53 ) ;
F_65 ( V_21 , V_153 , V_54 , V_55 ) ;
F_65 ( V_21 , V_153 , V_56 , V_57 ) ;
F_65 ( V_21 , V_153 , V_58 , V_59 ) ;
if ( V_153 [ V_43 ] ) {
V_92 = F_68 ( V_21 , F_69 ( V_153 [ V_43 ] ) ) ;
if ( V_92 )
return V_92 ;
}
if ( V_153 [ V_41 ] ) {
V_92 = F_70 ( V_21 , F_71 ( V_153 [ V_41 ] ) ) ;
if ( V_92 )
return V_92 ;
}
if ( V_153 [ V_39 ] ) {
V_92 = F_60 ( V_21 , F_66 ( V_153 [ V_39 ] ) ) ;
if ( V_92 )
return V_92 ;
}
if ( V_153 [ V_158 ] )
F_72 ( V_21 -> V_23 , V_21 , 0 , 0 ) ;
#ifdef F_16
if ( V_153 [ V_83 ] ) {
V_29 V_159 = F_66 ( V_153 [ V_83 ] ) ;
V_92 = F_73 ( V_21 , V_159 ) ;
if ( V_92 )
return V_92 ;
}
#endif
F_74 ( V_21 , V_157 ^ V_21 -> V_9 ) ;
return 0 ;
}
int F_75 ( struct V_18 * V_19 , struct V_98 * V_99 , T_2 V_9 )
{
struct V_121 * V_160 ;
struct V_121 * V_161 ;
struct V_20 * V_21 ;
struct V_121 * V_153 [ V_162 + 1 ] ;
int V_92 = 0 ;
V_160 = F_76 ( V_99 , sizeof( struct V_31 ) , V_123 ) ;
V_161 = F_76 ( V_99 , sizeof( struct V_31 ) , V_127 ) ;
if ( ! V_160 && ! V_161 )
return 0 ;
V_21 = F_49 ( V_19 ) ;
if ( ! V_21 && ! V_161 )
return - V_144 ;
if ( V_21 && V_160 ) {
if ( V_160 -> F_57 & V_124 ) {
V_92 = F_77 ( V_153 , V_162 ,
V_160 , V_163 ) ;
if ( V_92 )
return V_92 ;
F_78 ( & V_21 -> V_23 -> V_164 ) ;
V_92 = F_67 ( V_21 , V_153 ) ;
F_79 ( & V_21 -> V_23 -> V_164 ) ;
} else {
if ( F_58 ( V_160 ) < sizeof( V_29 ) )
return - V_144 ;
F_78 ( & V_21 -> V_23 -> V_164 ) ;
V_92 = F_60 ( V_21 , F_66 ( V_160 ) ) ;
F_79 ( & V_21 -> V_23 -> V_164 ) ;
}
if ( V_92 )
goto V_165;
}
if ( V_161 ) {
V_92 = F_55 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_161 , V_136 ) ;
}
if ( V_92 == 0 )
F_41 ( V_120 , V_21 ) ;
V_165:
return V_92 ;
}
int F_80 ( struct V_18 * V_19 , struct V_98 * V_99 , T_2 V_9 )
{
struct V_121 * V_161 ;
struct V_20 * V_21 ;
int V_92 = 0 ;
V_161 = F_76 ( V_99 , sizeof( struct V_31 ) , V_127 ) ;
if ( ! V_161 )
return 0 ;
V_21 = F_49 ( V_19 ) ;
if ( ! V_21 && ! ( V_19 -> V_25 & V_26 ) )
return - V_144 ;
V_92 = F_55 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_161 , V_138 ) ;
if ( V_92 == 0 )
F_41 ( V_120 , V_21 ) ;
return V_92 ;
}
static int F_81 ( struct V_121 * V_153 [] , struct V_121 * V_166 [] )
{
if ( V_153 [ V_117 ] ) {
if ( F_58 ( V_153 [ V_117 ] ) != V_167 )
return - V_144 ;
if ( ! F_82 ( F_59 ( V_153 [ V_117 ] ) ) )
return - V_168 ;
}
if ( ! V_166 )
return 0 ;
#ifdef F_83
if ( V_166 [ V_169 ] ) {
switch ( F_84 ( V_166 [ V_169 ] ) ) {
case F_85 ( V_170 ) :
case F_85 ( V_171 ) :
break;
default:
return - V_172 ;
}
}
#endif
return 0 ;
}
static int F_86 ( struct V_128 * V_173 , struct V_18 * V_19 ,
struct V_121 * V_153 [] , struct V_121 * V_166 [] )
{
struct V_22 * V_23 = F_12 ( V_19 ) ;
if ( V_153 [ V_117 ] ) {
F_78 ( & V_23 -> V_164 ) ;
F_87 ( V_23 , F_59 ( V_153 [ V_117 ] ) ) ;
F_79 ( & V_23 -> V_164 ) ;
}
return F_88 ( V_19 ) ;
}
static int F_89 ( struct V_18 * V_174 ,
struct V_18 * V_19 ,
struct V_121 * V_153 [] ,
struct V_121 * V_166 [] )
{
struct V_22 * V_23 = F_12 ( V_174 ) ;
int V_175 ;
if ( ! V_166 )
return 0 ;
F_78 ( & V_23 -> V_164 ) ;
V_175 = F_67 ( F_49 ( V_19 ) , V_166 ) ;
F_79 ( & V_23 -> V_164 ) ;
return V_175 ;
}
static int F_90 ( struct V_34 * V_35 ,
const struct V_18 * V_174 ,
const struct V_18 * V_19 )
{
return F_19 ( V_35 , F_49 ( V_19 ) ) ;
}
static T_3 F_91 ( const struct V_18 * V_174 ,
const struct V_18 * V_19 )
{
return F_15 () ;
}
static int F_92 ( struct V_18 * V_174 , struct V_121 * V_153 [] ,
struct V_121 * V_166 [] )
{
struct V_22 * V_23 = F_12 ( V_174 ) ;
int V_92 ;
if ( ! V_166 )
return 0 ;
if ( V_166 [ V_176 ] ) {
V_92 = F_93 ( V_23 , F_69 ( V_166 [ V_176 ] ) ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_177 ] ) {
V_92 = F_94 ( V_23 , F_69 ( V_166 [ V_177 ] ) ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_178 ] ) {
V_92 = F_95 ( V_23 , F_69 ( V_166 [ V_178 ] ) ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_179 ] ) {
V_92 = F_96 ( V_23 , F_69 ( V_166 [ V_179 ] ) ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_180 ] ) {
T_1 V_148 = F_69 ( V_166 [ V_180 ] ) ;
F_97 ( V_23 , V_148 ) ;
}
if ( V_166 [ V_181 ] ) {
T_1 V_42 = F_71 ( V_166 [ V_181 ] ) ;
F_98 ( V_23 , V_42 ) ;
}
if ( V_166 [ V_182 ] ) {
V_29 V_183 = F_66 ( V_166 [ V_182 ] ) ;
V_92 = F_99 ( V_23 , V_183 ) ;
if ( V_92 )
return V_92 ;
}
#ifdef F_83
if ( V_166 [ V_169 ] ) {
T_4 V_184 = F_84 ( V_166 [ V_169 ] ) ;
V_92 = F_100 ( V_23 , V_184 ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_185 ] ) {
T_5 V_186 = F_71 ( V_166 [ V_185 ] ) ;
V_92 = F_101 ( V_23 , V_186 ) ;
if ( V_92 )
return V_92 ;
}
#endif
if ( V_166 [ V_187 ] ) {
T_2 V_188 = F_71 ( V_166 [ V_187 ] ) ;
if ( V_188 & V_189 )
return - V_144 ;
V_23 -> V_190 = V_188 ;
}
if ( V_166 [ V_191 ] ) {
V_29 V_192 [ V_167 ] ;
if ( F_58 ( V_166 [ V_191 ] ) != V_167 )
return - V_144 ;
memcpy ( V_192 , F_59 ( V_166 [ V_191 ] ) , V_167 ) ;
if ( ! F_102 ( V_192 ) )
return - V_144 ;
if ( V_192 [ 5 ] == 1 ||
V_192 [ 5 ] == 2 ||
V_192 [ 5 ] == 3 )
return - V_144 ;
F_78 ( & V_23 -> V_164 ) ;
memcpy ( V_23 -> V_193 , V_192 , sizeof( V_23 -> V_193 ) ) ;
F_79 ( & V_23 -> V_164 ) ;
V_23 -> V_194 = true ;
F_103 ( V_23 ) ;
}
if ( V_166 [ V_195 ] )
F_104 ( V_23 ) ;
#ifdef F_16
if ( V_166 [ V_196 ] ) {
V_29 V_84 = F_66 ( V_166 [ V_196 ] ) ;
V_92 = F_105 ( V_23 , V_84 ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_197 ] ) {
V_29 V_198 = F_66 ( V_166 [ V_197 ] ) ;
V_92 = F_106 ( V_23 , V_198 ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_199 ] ) {
V_29 V_200 ;
V_200 = F_66 ( V_166 [ V_199 ] ) ;
V_23 -> V_201 = ! ! V_200 ;
}
if ( V_166 [ V_202 ] ) {
V_29 V_203 = F_66 ( V_166 [ V_202 ] ) ;
V_92 = F_107 ( V_23 , V_203 ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_204 ] ) {
T_1 V_200 = F_69 ( V_166 [ V_204 ] ) ;
V_23 -> V_205 = V_200 ;
}
if ( V_166 [ V_206 ] ) {
T_1 V_207 = F_69 ( V_166 [ V_206 ] ) ;
V_92 = F_108 ( V_23 , V_207 ) ;
if ( V_92 )
return V_92 ;
}
if ( V_166 [ V_208 ] ) {
T_1 V_200 = F_69 ( V_166 [ V_208 ] ) ;
V_23 -> V_209 = V_200 ;
}
if ( V_166 [ V_210 ] ) {
T_1 V_200 = F_69 ( V_166 [ V_210 ] ) ;
V_23 -> V_211 = V_200 ;
}
if ( V_166 [ V_212 ] ) {
V_30 V_200 = F_109 ( V_166 [ V_212 ] ) ;
V_23 -> V_213 = F_110 ( V_200 ) ;
}
if ( V_166 [ V_214 ] ) {
V_30 V_200 = F_109 ( V_166 [ V_214 ] ) ;
V_23 -> V_215 = F_110 ( V_200 ) ;
}
if ( V_166 [ V_216 ] ) {
V_30 V_200 = F_109 ( V_166 [ V_216 ] ) ;
V_23 -> V_217 = F_110 ( V_200 ) ;
}
if ( V_166 [ V_218 ] ) {
V_30 V_200 = F_109 ( V_166 [ V_218 ] ) ;
V_23 -> V_219 = F_110 ( V_200 ) ;
}
if ( V_166 [ V_220 ] ) {
V_30 V_200 = F_109 ( V_166 [ V_220 ] ) ;
V_23 -> V_221 = F_110 ( V_200 ) ;
}
if ( V_166 [ V_222 ] ) {
V_30 V_200 = F_109 ( V_166 [ V_222 ] ) ;
V_23 -> V_223 = F_110 ( V_200 ) ;
}
#endif
#if F_111 ( V_224 )
if ( V_166 [ V_225 ] ) {
V_29 V_200 = F_66 ( V_166 [ V_225 ] ) ;
V_23 -> V_226 = V_200 ? true : false ;
}
if ( V_166 [ V_227 ] ) {
V_29 V_200 = F_66 ( V_166 [ V_227 ] ) ;
V_23 -> V_228 = V_200 ? true : false ;
}
if ( V_166 [ V_229 ] ) {
V_29 V_200 = F_66 ( V_166 [ V_229 ] ) ;
V_23 -> V_230 = V_200 ? true : false ;
}
#endif
return 0 ;
}
static T_3 F_112 ( const struct V_18 * V_174 )
{
return F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_2 ) ) +
F_14 ( sizeof( V_29 ) ) +
#ifdef F_83
F_14 ( sizeof( T_4 ) ) +
F_14 ( sizeof( T_2 ) ) +
#endif
F_14 ( sizeof( T_2 ) ) +
F_14 ( sizeof( struct V_28 ) ) +
F_14 ( sizeof( struct V_28 ) ) +
F_14 ( sizeof( T_2 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( V_167 ) +
#ifdef F_16
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( sizeof( V_30 ) ) +
F_14 ( sizeof( V_30 ) ) +
#endif
#if F_111 ( V_224 )
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
#endif
0 ;
}
static int F_113 ( struct V_34 * V_35 , const struct V_18 * V_174 )
{
struct V_22 * V_23 = F_12 ( V_174 ) ;
T_1 V_231 = F_114 ( V_23 -> V_231 ) ;
T_1 V_232 = F_114 ( V_23 -> V_232 ) ;
T_1 V_233 = F_114 ( V_23 -> V_234 ) ;
T_1 V_235 = F_114 ( V_23 -> V_235 ) ;
T_1 V_148 = V_23 -> V_148 ;
T_2 V_42 = ( V_23 -> V_236 . V_237 [ 0 ] << 8 ) | V_23 -> V_236 . V_237 [ 1 ] ;
V_29 V_238 = F_115 ( V_23 ) ;
V_30 V_239 ;
V_239 = F_24 ( & V_23 -> V_240 ) ;
if ( F_25 ( V_35 , V_241 , V_239 ) )
return - V_76 ;
V_239 = F_24 ( & V_23 -> V_242 ) ;
if ( F_25 ( V_35 , V_243 , V_239 ) )
return - V_76 ;
V_239 = F_24 ( & V_23 -> V_244 ) ;
if ( F_25 ( V_35 , V_245 , V_239 ) )
return - V_76 ;
V_239 = F_24 ( & V_23 -> V_246 ) ;
if ( F_25 ( V_35 , V_247 , V_239 ) )
return - V_76 ;
if ( F_22 ( V_35 , V_176 , V_231 ) ||
F_22 ( V_35 , V_177 , V_232 ) ||
F_22 ( V_35 , V_178 , V_233 ) ||
F_22 ( V_35 , V_179 , V_235 ) ||
F_22 ( V_35 , V_180 , V_148 ) ||
F_21 ( V_35 , V_181 , V_42 ) ||
F_20 ( V_35 , V_182 , V_238 ) ||
F_21 ( V_35 , V_187 , V_23 -> V_190 ) ||
F_23 ( V_35 , V_248 , sizeof( struct V_28 ) ,
& V_23 -> V_236 ) ||
F_23 ( V_35 , V_249 , sizeof( struct V_28 ) ,
& V_23 -> V_61 ) ||
F_21 ( V_35 , V_250 , V_23 -> V_251 ) ||
F_22 ( V_35 , V_252 , V_23 -> V_253 ) ||
F_20 ( V_35 , V_254 , V_23 -> V_255 ) ||
F_20 ( V_35 , V_256 ,
V_23 -> V_257 ) ||
F_23 ( V_35 , V_191 , V_167 , V_23 -> V_193 ) )
return - V_76 ;
#ifdef F_83
if ( F_116 ( V_35 , V_169 , V_23 -> V_184 ) ||
F_21 ( V_35 , V_185 , V_23 -> V_258 ) )
return - V_76 ;
#endif
#ifdef F_16
if ( F_20 ( V_35 , V_196 , V_23 -> V_84 ) ||
F_20 ( V_35 , V_197 , ! V_23 -> V_259 ) ||
F_20 ( V_35 , V_199 ,
V_23 -> V_201 ) ||
F_20 ( V_35 , V_202 , V_23 -> V_260 ) ||
F_22 ( V_35 , V_204 ,
V_23 -> V_205 ) ||
F_22 ( V_35 , V_206 , V_23 -> V_207 ) ||
F_22 ( V_35 , V_208 ,
V_23 -> V_209 ) ||
F_22 ( V_35 , V_210 ,
V_23 -> V_211 ) )
return - V_76 ;
V_239 = F_114 ( V_23 -> V_213 ) ;
if ( F_25 ( V_35 , V_212 , V_239 ) )
return - V_76 ;
V_239 = F_114 ( V_23 -> V_215 ) ;
if ( F_25 ( V_35 , V_214 , V_239 ) )
return - V_76 ;
V_239 = F_114 ( V_23 -> V_217 ) ;
if ( F_25 ( V_35 , V_216 , V_239 ) )
return - V_76 ;
V_239 = F_114 ( V_23 -> V_219 ) ;
if ( F_25 ( V_35 , V_218 , V_239 ) )
return - V_76 ;
V_239 = F_114 ( V_23 -> V_221 ) ;
if ( F_25 ( V_35 , V_220 , V_239 ) )
return - V_76 ;
V_239 = F_114 ( V_23 -> V_223 ) ;
if ( F_25 ( V_35 , V_222 , V_239 ) )
return - V_76 ;
#endif
#if F_111 ( V_224 )
if ( F_20 ( V_35 , V_225 ,
V_23 -> V_226 ? 1 : 0 ) ||
F_20 ( V_35 , V_227 ,
V_23 -> V_228 ? 1 : 0 ) ||
F_20 ( V_35 , V_229 ,
V_23 -> V_230 ? 1 : 0 ) )
return - V_76 ;
#endif
return 0 ;
}
int T_6 F_117 ( void )
{
int V_92 ;
F_118 () ;
F_119 ( & V_261 ) ;
V_92 = F_120 ( & V_262 ) ;
if ( V_92 )
goto V_263;
return 0 ;
V_263:
F_121 ( & V_261 ) ;
F_122 () ;
return V_92 ;
}
void F_123 ( void )
{
F_122 () ;
F_121 ( & V_261 ) ;
F_124 ( & V_262 ) ;
}
