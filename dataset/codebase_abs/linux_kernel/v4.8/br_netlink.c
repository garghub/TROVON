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
+ F_16 ( sizeof( V_30 ) )
+ F_16 ( sizeof( V_30 ) )
+ F_16 ( sizeof( V_30 ) )
#ifdef F_17
+ F_14 ( sizeof( V_29 ) )
#endif
+ 0 ;
}
static inline T_3 F_18 ( struct V_18 * V_19 , T_1 V_3 )
{
return F_19 ( sizeof( struct V_31 ) )
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
static int F_20 ( struct V_34 * V_35 ,
const struct V_20 * V_21 )
{
V_29 V_36 = ! ! ( V_21 -> V_9 & V_37 ) ;
V_30 V_38 ;
if ( F_21 ( V_35 , V_39 , V_21 -> V_40 ) ||
F_22 ( V_35 , V_41 , V_21 -> V_42 ) ||
F_23 ( V_35 , V_43 , V_21 -> V_44 ) ||
F_21 ( V_35 , V_45 , V_36 ) ||
F_21 ( V_35 , V_46 , ! ! ( V_21 -> V_9 & V_47 ) ) ||
F_21 ( V_35 , V_48 , ! ! ( V_21 -> V_9 & V_49 ) ) ||
F_21 ( V_35 , V_50 , ! ! ( V_21 -> V_9 & V_51 ) ) ||
F_21 ( V_35 , V_52 , ! ! ( V_21 -> V_9 & V_53 ) ) ||
F_21 ( V_35 , V_54 , ! ! ( V_21 -> V_9 & V_55 ) ) ||
F_21 ( V_35 , V_56 , ! ! ( V_21 -> V_9 & V_57 ) ) ||
F_21 ( V_35 , V_58 ,
! ! ( V_21 -> V_9 & V_59 ) ) ||
F_24 ( V_35 , V_60 , sizeof( struct V_28 ) ,
& V_21 -> V_61 ) ||
F_24 ( V_35 , V_62 , sizeof( struct V_28 ) ,
& V_21 -> V_63 ) ||
F_22 ( V_35 , V_64 , V_21 -> V_65 ) ||
F_22 ( V_35 , V_66 , V_21 -> V_67 ) ||
F_22 ( V_35 , V_68 , V_21 -> V_69 ) ||
F_22 ( V_35 , V_70 , V_21 -> V_71 ) ||
F_21 ( V_35 , V_72 ,
V_21 -> V_73 ) ||
F_21 ( V_35 , V_74 , V_21 -> V_75 ) )
return - V_76 ;
V_38 = F_25 ( & V_21 -> V_77 ) ;
if ( F_26 ( V_35 , V_78 , V_38 ,
V_79 ) )
return - V_76 ;
V_38 = F_25 ( & V_21 -> V_80 ) ;
if ( F_26 ( V_35 , V_81 , V_38 ,
V_79 ) )
return - V_76 ;
V_38 = F_25 ( & V_21 -> V_82 ) ;
if ( F_26 ( V_35 , V_83 , V_38 ,
V_79 ) )
return - V_76 ;
#ifdef F_17
if ( F_21 ( V_35 , V_84 ,
V_21 -> V_85 ) )
return - V_76 ;
#endif
return 0 ;
}
static int F_27 ( struct V_34 * V_35 , T_2 V_86 ,
T_2 V_87 , T_2 V_9 )
{
struct V_27 V_88 ;
if ( ( V_87 - V_86 ) > 0 ) {
V_88 . V_13 = V_86 ;
V_88 . V_9 = V_9 | V_89 ;
if ( F_24 ( V_35 , V_90 ,
sizeof( V_88 ) , & V_88 ) )
goto V_91;
V_88 . V_13 = V_87 ;
V_88 . V_9 = V_9 | V_92 ;
if ( F_24 ( V_35 , V_90 ,
sizeof( V_88 ) , & V_88 ) )
goto V_91;
} else {
V_88 . V_13 = V_86 ;
V_88 . V_9 = V_9 ;
if ( F_24 ( V_35 , V_90 ,
sizeof( V_88 ) , & V_88 ) )
goto V_91;
}
return 0 ;
V_91:
return - V_76 ;
}
static int F_28 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_6 = 0 , V_7 = 0 , V_8 = 0 ;
T_2 V_9 , V_10 ;
int V_93 = 0 ;
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
V_93 = F_27 ( V_35 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_93 )
return V_93 ;
}
V_16:
V_6 = V_5 -> V_13 ;
V_7 = V_5 -> V_13 ;
V_8 = V_9 ;
}
if ( V_6 != 0 ) {
V_93 = F_27 ( V_35 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_93 )
return V_93 ;
}
return 0 ;
}
static int F_29 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_27 V_88 ;
struct V_4 * V_5 ;
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_3 (v, &vg->vlan_list, vlist) {
if ( ! F_4 ( V_5 ) )
continue;
V_88 . V_13 = V_5 -> V_13 ;
V_88 . V_9 = 0 ;
if ( V_5 -> V_13 == V_10 )
V_88 . V_9 |= V_14 ;
if ( V_5 -> V_9 & V_15 )
V_88 . V_9 |= V_15 ;
if ( F_24 ( V_35 , V_90 ,
sizeof( V_88 ) , & V_88 ) )
goto V_91;
}
return 0 ;
V_91:
return - V_76 ;
}
static int F_30 ( struct V_34 * V_35 ,
struct V_20 * V_94 ,
T_1 V_95 , T_1 V_96 , int V_97 , unsigned int V_9 ,
T_1 V_3 , const struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_31 * V_98 ;
struct V_99 * V_100 ;
V_29 V_101 = F_31 ( V_19 ) ? V_19 -> V_101 : V_102 ;
if ( V_94 )
V_23 = V_94 -> V_23 ;
else
V_23 = F_12 ( V_19 ) ;
F_32 ( V_23 , L_1 ,
V_97 , V_19 -> V_103 , V_23 -> V_19 -> V_103 ) ;
V_100 = F_33 ( V_35 , V_95 , V_96 , V_97 , sizeof( * V_98 ) , V_9 ) ;
if ( V_100 == NULL )
return - V_76 ;
V_98 = F_34 ( V_100 ) ;
V_98 -> V_104 = V_105 ;
V_98 -> V_106 = 0 ;
V_98 -> V_107 = V_19 -> type ;
V_98 -> V_108 = V_19 -> V_109 ;
V_98 -> V_110 = F_35 ( V_19 ) ;
V_98 -> V_111 = 0 ;
if ( F_36 ( V_35 , V_112 , V_19 -> V_103 ) ||
F_23 ( V_35 , V_113 , V_23 -> V_19 -> V_109 ) ||
F_23 ( V_35 , V_114 , V_19 -> V_115 ) ||
F_21 ( V_35 , V_116 , V_101 ) ||
( V_19 -> V_117 &&
F_24 ( V_35 , V_118 , V_19 -> V_117 , V_19 -> V_119 ) ) ||
( V_19 -> V_109 != F_37 ( V_19 ) &&
F_23 ( V_35 , V_120 , F_37 ( V_19 ) ) ) )
goto V_91;
if ( V_97 == V_121 && V_94 ) {
struct V_122 * V_123
= F_38 ( V_35 , V_124 | V_125 ) ;
if ( V_123 == NULL || F_20 ( V_35 , V_94 ) < 0 )
goto V_91;
F_39 ( V_35 , V_123 ) ;
}
if ( ( V_3 & V_17 ) ||
( V_3 & V_12 ) ) {
struct V_1 * V_2 ;
struct V_122 * V_126 ;
int V_93 ;
F_6 () ;
if ( V_94 )
V_2 = F_11 ( V_94 ) ;
else
V_2 = F_13 ( V_23 ) ;
if ( ! V_2 || ! V_2 -> V_11 ) {
F_7 () ;
goto V_127;
}
V_126 = F_38 ( V_35 , V_128 ) ;
if ( ! V_126 ) {
F_7 () ;
goto V_91;
}
if ( V_3 & V_12 )
V_93 = F_28 ( V_35 , V_2 ) ;
else
V_93 = F_29 ( V_35 , V_2 ) ;
F_7 () ;
if ( V_93 )
goto V_91;
F_39 ( V_35 , V_126 ) ;
}
V_127:
F_40 ( V_35 , V_100 ) ;
return 0 ;
V_91:
F_41 ( V_35 , V_100 ) ;
return - V_76 ;
}
void F_42 ( int V_97 , struct V_20 * V_94 )
{
struct V_129 * V_129 ;
struct V_34 * V_35 ;
int V_93 = - V_130 ;
T_1 V_131 = V_12 ;
if ( ! V_94 )
return;
V_129 = F_43 ( V_94 -> V_19 ) ;
F_32 ( V_94 -> V_23 , L_2 ,
( unsigned int ) V_94 -> V_71 , V_94 -> V_19 -> V_103 , V_97 ) ;
V_35 = F_44 ( F_18 ( V_94 -> V_19 , V_131 ) , V_132 ) ;
if ( V_35 == NULL )
goto V_133;
V_93 = F_30 ( V_35 , V_94 , 0 , 0 , V_97 , 0 , V_131 , V_94 -> V_19 ) ;
if ( V_93 < 0 ) {
F_45 ( V_93 == - V_76 ) ;
F_46 ( V_35 ) ;
goto V_133;
}
F_47 ( V_35 , V_129 , 0 , V_134 , NULL , V_132 ) ;
return;
V_133:
F_48 ( V_129 , V_134 , V_93 ) ;
}
int F_49 ( struct V_34 * V_35 , T_1 V_95 , T_1 V_96 ,
struct V_18 * V_19 , T_1 V_3 , int V_135 )
{
struct V_20 * V_94 = F_50 ( V_19 ) ;
if ( ! V_94 && ! ( V_3 & V_17 ) &&
! ( V_3 & V_12 ) )
return 0 ;
return F_30 ( V_35 , V_94 , V_95 , V_96 , V_121 , V_135 ,
V_3 , V_19 ) ;
}
static int F_51 ( struct V_22 * V_23 , struct V_20 * V_21 ,
int V_136 , struct V_27 * V_88 )
{
int V_93 = 0 ;
switch ( V_136 ) {
case V_137 :
if ( V_21 ) {
V_93 = F_52 ( V_21 , V_88 -> V_13 , V_88 -> V_9 ) ;
if ( V_93 )
break;
} else {
V_88 -> V_9 |= V_138 ;
V_93 = F_53 ( V_23 , V_88 -> V_13 , V_88 -> V_9 ) ;
}
break;
case V_139 :
if ( V_21 ) {
F_54 ( V_21 , V_88 -> V_13 ) ;
if ( V_88 -> V_9 & V_140 )
F_55 ( V_21 -> V_23 , V_88 -> V_13 ) ;
} else {
F_55 ( V_23 , V_88 -> V_13 ) ;
}
break;
}
return V_93 ;
}
static int F_56 ( struct V_22 * V_23 ,
struct V_20 * V_21 ,
struct V_122 * V_141 ,
int V_136 )
{
struct V_27 * V_142 = NULL ;
struct V_27 * V_88 = NULL ;
struct V_122 * V_143 ;
int V_93 = 0 ;
int V_144 ;
F_57 (attr, af_spec, rem) {
if ( F_58 ( V_143 ) != V_90 )
continue;
if ( F_59 ( V_143 ) != sizeof( struct V_27 ) )
return - V_145 ;
V_88 = F_60 ( V_143 ) ;
if ( ! V_88 -> V_13 || V_88 -> V_13 >= V_146 )
return - V_145 ;
if ( V_88 -> V_9 & V_89 ) {
if ( V_142 )
return - V_145 ;
V_142 = V_88 ;
if ( V_142 -> V_9 & V_14 )
return - V_145 ;
continue;
}
if ( V_142 ) {
struct V_27 V_147 ;
int V_5 ;
if ( ! ( V_88 -> V_9 & V_92 ) )
return - V_145 ;
if ( V_88 -> V_13 <= V_142 -> V_13 )
return - V_145 ;
memcpy ( & V_147 , V_142 ,
sizeof( struct V_27 ) ) ;
for ( V_5 = V_142 -> V_13 ; V_5 <= V_88 -> V_13 ; V_5 ++ ) {
V_147 . V_13 = V_5 ;
V_93 = F_51 ( V_23 , V_21 , V_136 , & V_147 ) ;
if ( V_93 )
break;
}
V_142 = NULL ;
} else {
V_93 = F_51 ( V_23 , V_21 , V_136 , V_88 ) ;
}
if ( V_93 )
break;
}
return V_93 ;
}
static int F_61 ( struct V_20 * V_21 , V_29 V_40 )
{
if ( V_40 > V_148 )
return - V_145 ;
if ( V_21 -> V_23 -> V_149 == V_150 )
return - V_151 ;
if ( ! F_31 ( V_21 -> V_19 ) ||
( ! F_62 ( V_21 -> V_19 ) && V_40 != V_152 ) )
return - V_153 ;
F_63 ( V_21 , V_40 ) ;
F_64 ( V_21 -> V_23 ) ;
return 0 ;
}
static void F_65 ( struct V_20 * V_21 , struct V_122 * V_154 [] ,
int V_155 , unsigned long V_156 )
{
if ( V_154 [ V_155 ] ) {
V_29 V_157 = F_66 ( V_154 [ V_155 ] ) ;
if ( V_157 )
V_21 -> V_9 |= V_156 ;
else
V_21 -> V_9 &= ~ V_156 ;
}
}
static int F_67 ( struct V_20 * V_21 , struct V_122 * V_154 [] )
{
int V_93 ;
unsigned long V_158 = V_21 -> V_9 ;
F_65 ( V_21 , V_154 , V_45 , V_37 ) ;
F_65 ( V_21 , V_154 , V_46 , V_47 ) ;
F_65 ( V_21 , V_154 , V_50 , V_51 ) ;
F_65 ( V_21 , V_154 , V_48 , V_49 ) ;
F_65 ( V_21 , V_154 , V_52 , V_53 ) ;
F_65 ( V_21 , V_154 , V_54 , V_55 ) ;
F_65 ( V_21 , V_154 , V_56 , V_57 ) ;
F_65 ( V_21 , V_154 , V_58 , V_59 ) ;
if ( V_154 [ V_43 ] ) {
V_93 = F_68 ( V_21 , F_69 ( V_154 [ V_43 ] ) ) ;
if ( V_93 )
return V_93 ;
}
if ( V_154 [ V_41 ] ) {
V_93 = F_70 ( V_21 , F_71 ( V_154 [ V_41 ] ) ) ;
if ( V_93 )
return V_93 ;
}
if ( V_154 [ V_39 ] ) {
V_93 = F_61 ( V_21 , F_66 ( V_154 [ V_39 ] ) ) ;
if ( V_93 )
return V_93 ;
}
if ( V_154 [ V_159 ] )
F_72 ( V_21 -> V_23 , V_21 , 0 , 0 ) ;
#ifdef F_17
if ( V_154 [ V_84 ] ) {
V_29 V_160 = F_66 ( V_154 [ V_84 ] ) ;
V_93 = F_73 ( V_21 , V_160 ) ;
if ( V_93 )
return V_93 ;
}
#endif
F_74 ( V_21 , V_158 ^ V_21 -> V_9 ) ;
return 0 ;
}
int F_75 ( struct V_18 * V_19 , struct V_99 * V_100 , T_2 V_9 )
{
struct V_122 * V_161 ;
struct V_122 * V_162 ;
struct V_20 * V_21 ;
struct V_122 * V_154 [ V_163 + 1 ] ;
int V_93 = 0 ;
V_161 = F_76 ( V_100 , sizeof( struct V_31 ) , V_124 ) ;
V_162 = F_76 ( V_100 , sizeof( struct V_31 ) , V_128 ) ;
if ( ! V_161 && ! V_162 )
return 0 ;
V_21 = F_50 ( V_19 ) ;
if ( ! V_21 && ! V_162 )
return - V_145 ;
if ( V_21 && V_161 ) {
if ( V_161 -> F_58 & V_125 ) {
V_93 = F_77 ( V_154 , V_163 ,
V_161 , V_164 ) ;
if ( V_93 )
return V_93 ;
F_78 ( & V_21 -> V_23 -> V_165 ) ;
V_93 = F_67 ( V_21 , V_154 ) ;
F_79 ( & V_21 -> V_23 -> V_165 ) ;
} else {
if ( F_59 ( V_161 ) < sizeof( V_29 ) )
return - V_145 ;
F_78 ( & V_21 -> V_23 -> V_165 ) ;
V_93 = F_61 ( V_21 , F_66 ( V_161 ) ) ;
F_79 ( & V_21 -> V_23 -> V_165 ) ;
}
if ( V_93 )
goto V_166;
}
if ( V_162 ) {
V_93 = F_56 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_162 , V_137 ) ;
}
if ( V_93 == 0 )
F_42 ( V_121 , V_21 ) ;
V_166:
return V_93 ;
}
int F_80 ( struct V_18 * V_19 , struct V_99 * V_100 , T_2 V_9 )
{
struct V_122 * V_162 ;
struct V_20 * V_21 ;
int V_93 = 0 ;
V_162 = F_76 ( V_100 , sizeof( struct V_31 ) , V_128 ) ;
if ( ! V_162 )
return 0 ;
V_21 = F_50 ( V_19 ) ;
if ( ! V_21 && ! ( V_19 -> V_25 & V_26 ) )
return - V_145 ;
V_93 = F_56 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_162 , V_139 ) ;
if ( V_93 == 0 )
F_42 ( V_121 , V_21 ) ;
return V_93 ;
}
static int F_81 ( struct V_122 * V_154 [] , struct V_122 * V_167 [] )
{
if ( V_154 [ V_118 ] ) {
if ( F_59 ( V_154 [ V_118 ] ) != V_168 )
return - V_145 ;
if ( ! F_82 ( F_60 ( V_154 [ V_118 ] ) ) )
return - V_169 ;
}
if ( ! V_167 )
return 0 ;
#ifdef F_83
if ( V_167 [ V_170 ] ) {
switch ( F_84 ( V_167 [ V_170 ] ) ) {
case F_85 ( V_171 ) :
case F_85 ( V_172 ) :
break;
default:
return - V_173 ;
}
}
#endif
return 0 ;
}
static int F_86 ( struct V_129 * V_174 , struct V_18 * V_19 ,
struct V_122 * V_154 [] , struct V_122 * V_167 [] )
{
struct V_22 * V_23 = F_12 ( V_19 ) ;
if ( V_154 [ V_118 ] ) {
F_78 ( & V_23 -> V_165 ) ;
F_87 ( V_23 , F_60 ( V_154 [ V_118 ] ) ) ;
F_79 ( & V_23 -> V_165 ) ;
}
return F_88 ( V_19 ) ;
}
static int F_89 ( struct V_18 * V_175 ,
struct V_18 * V_19 ,
struct V_122 * V_154 [] ,
struct V_122 * V_167 [] )
{
struct V_22 * V_23 = F_12 ( V_175 ) ;
int V_176 ;
if ( ! V_167 )
return 0 ;
F_78 ( & V_23 -> V_165 ) ;
V_176 = F_67 ( F_50 ( V_19 ) , V_167 ) ;
F_79 ( & V_23 -> V_165 ) ;
return V_176 ;
}
static int F_90 ( struct V_34 * V_35 ,
const struct V_18 * V_175 ,
const struct V_18 * V_19 )
{
return F_20 ( V_35 , F_50 ( V_19 ) ) ;
}
static T_3 F_91 ( const struct V_18 * V_175 ,
const struct V_18 * V_19 )
{
return F_15 () ;
}
static int F_92 ( struct V_18 * V_175 , struct V_122 * V_154 [] ,
struct V_122 * V_167 [] )
{
struct V_22 * V_23 = F_12 ( V_175 ) ;
int V_93 ;
if ( ! V_167 )
return 0 ;
if ( V_167 [ V_177 ] ) {
V_93 = F_93 ( V_23 , F_69 ( V_167 [ V_177 ] ) ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_178 ] ) {
V_93 = F_94 ( V_23 , F_69 ( V_167 [ V_178 ] ) ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_179 ] ) {
V_93 = F_95 ( V_23 , F_69 ( V_167 [ V_179 ] ) ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_180 ] ) {
V_93 = F_96 ( V_23 , F_69 ( V_167 [ V_180 ] ) ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_181 ] ) {
T_1 V_149 = F_69 ( V_167 [ V_181 ] ) ;
F_97 ( V_23 , V_149 ) ;
}
if ( V_167 [ V_182 ] ) {
T_1 V_42 = F_71 ( V_167 [ V_182 ] ) ;
F_98 ( V_23 , V_42 ) ;
}
if ( V_167 [ V_183 ] ) {
V_29 V_184 = F_66 ( V_167 [ V_183 ] ) ;
V_93 = F_99 ( V_23 , V_184 ) ;
if ( V_93 )
return V_93 ;
}
#ifdef F_83
if ( V_167 [ V_170 ] ) {
T_4 V_185 = F_84 ( V_167 [ V_170 ] ) ;
V_93 = F_100 ( V_23 , V_185 ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_186 ] ) {
T_5 V_187 = F_71 ( V_167 [ V_186 ] ) ;
V_93 = F_101 ( V_23 , V_187 ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_188 ] ) {
T_6 V_189 = F_66 ( V_167 [ V_188 ] ) ;
V_93 = F_102 ( V_23 , V_189 ) ;
if ( V_93 )
return V_93 ;
}
#endif
if ( V_167 [ V_190 ] ) {
T_2 V_191 = F_71 ( V_167 [ V_190 ] ) ;
if ( V_191 & V_192 )
return - V_145 ;
V_23 -> V_193 = V_191 ;
}
if ( V_167 [ V_194 ] ) {
V_29 V_195 [ V_168 ] ;
if ( F_59 ( V_167 [ V_194 ] ) != V_168 )
return - V_145 ;
memcpy ( V_195 , F_60 ( V_167 [ V_194 ] ) , V_168 ) ;
if ( ! F_103 ( V_195 ) )
return - V_145 ;
if ( V_195 [ 5 ] == 1 ||
V_195 [ 5 ] == 2 ||
V_195 [ 5 ] == 3 )
return - V_145 ;
F_78 ( & V_23 -> V_165 ) ;
memcpy ( V_23 -> V_196 , V_195 , sizeof( V_23 -> V_196 ) ) ;
F_79 ( & V_23 -> V_165 ) ;
V_23 -> V_197 = true ;
F_104 ( V_23 ) ;
}
if ( V_167 [ V_198 ] )
F_105 ( V_23 ) ;
#ifdef F_17
if ( V_167 [ V_199 ] ) {
V_29 V_85 = F_66 ( V_167 [ V_199 ] ) ;
V_93 = F_106 ( V_23 , V_85 ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_200 ] ) {
V_29 V_201 = F_66 ( V_167 [ V_200 ] ) ;
V_93 = F_107 ( V_23 , V_201 ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_202 ] ) {
V_29 V_203 ;
V_203 = F_66 ( V_167 [ V_202 ] ) ;
V_23 -> V_204 = ! ! V_203 ;
}
if ( V_167 [ V_205 ] ) {
V_29 V_206 = F_66 ( V_167 [ V_205 ] ) ;
V_93 = F_108 ( V_23 , V_206 ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_207 ] ) {
T_1 V_203 = F_69 ( V_167 [ V_207 ] ) ;
V_23 -> V_208 = V_203 ;
}
if ( V_167 [ V_209 ] ) {
T_1 V_210 = F_69 ( V_167 [ V_209 ] ) ;
V_93 = F_109 ( V_23 , V_210 ) ;
if ( V_93 )
return V_93 ;
}
if ( V_167 [ V_211 ] ) {
T_1 V_203 = F_69 ( V_167 [ V_211 ] ) ;
V_23 -> V_212 = V_203 ;
}
if ( V_167 [ V_213 ] ) {
T_1 V_203 = F_69 ( V_167 [ V_213 ] ) ;
V_23 -> V_214 = V_203 ;
}
if ( V_167 [ V_215 ] ) {
V_30 V_203 = F_110 ( V_167 [ V_215 ] ) ;
V_23 -> V_216 = F_111 ( V_203 ) ;
}
if ( V_167 [ V_217 ] ) {
V_30 V_203 = F_110 ( V_167 [ V_217 ] ) ;
V_23 -> V_218 = F_111 ( V_203 ) ;
}
if ( V_167 [ V_219 ] ) {
V_30 V_203 = F_110 ( V_167 [ V_219 ] ) ;
V_23 -> V_220 = F_111 ( V_203 ) ;
}
if ( V_167 [ V_221 ] ) {
V_30 V_203 = F_110 ( V_167 [ V_221 ] ) ;
V_23 -> V_222 = F_111 ( V_203 ) ;
}
if ( V_167 [ V_223 ] ) {
V_30 V_203 = F_110 ( V_167 [ V_223 ] ) ;
V_23 -> V_224 = F_111 ( V_203 ) ;
}
if ( V_167 [ V_225 ] ) {
V_30 V_203 = F_110 ( V_167 [ V_225 ] ) ;
V_23 -> V_226 = F_111 ( V_203 ) ;
}
if ( V_167 [ V_227 ] ) {
T_6 V_228 ;
V_228 = F_66 ( V_167 [ V_227 ] ) ;
V_23 -> V_229 = ! ! V_228 ;
}
#endif
#if F_112 ( V_230 )
if ( V_167 [ V_231 ] ) {
V_29 V_203 = F_66 ( V_167 [ V_231 ] ) ;
V_23 -> V_232 = V_203 ? true : false ;
}
if ( V_167 [ V_233 ] ) {
V_29 V_203 = F_66 ( V_167 [ V_233 ] ) ;
V_23 -> V_234 = V_203 ? true : false ;
}
if ( V_167 [ V_235 ] ) {
V_29 V_203 = F_66 ( V_167 [ V_235 ] ) ;
V_23 -> V_236 = V_203 ? true : false ;
}
#endif
return 0 ;
}
static T_3 F_113 ( const struct V_18 * V_175 )
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
F_14 ( sizeof( V_29 ) ) +
#endif
F_14 ( sizeof( T_2 ) ) +
F_14 ( sizeof( struct V_28 ) ) +
F_14 ( sizeof( struct V_28 ) ) +
F_14 ( sizeof( T_2 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_14 ( V_168 ) +
#ifdef F_17
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_14 ( sizeof( T_1 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_16 ( sizeof( V_30 ) ) +
F_16 ( sizeof( V_30 ) ) +
#endif
#if F_112 ( V_230 )
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
#endif
0 ;
}
static int F_114 ( struct V_34 * V_35 , const struct V_18 * V_175 )
{
struct V_22 * V_23 = F_12 ( V_175 ) ;
T_1 V_237 = F_115 ( V_23 -> V_237 ) ;
T_1 V_238 = F_115 ( V_23 -> V_238 ) ;
T_1 V_239 = F_115 ( V_23 -> V_240 ) ;
T_1 V_241 = F_115 ( V_23 -> V_241 ) ;
T_1 V_149 = V_23 -> V_149 ;
T_2 V_42 = ( V_23 -> V_242 . V_243 [ 0 ] << 8 ) | V_23 -> V_242 . V_243 [ 1 ] ;
V_29 V_244 = F_116 ( V_23 ) ;
V_30 V_245 ;
V_245 = F_25 ( & V_23 -> V_246 ) ;
if ( F_26 ( V_35 , V_247 , V_245 , V_248 ) )
return - V_76 ;
V_245 = F_25 ( & V_23 -> V_249 ) ;
if ( F_26 ( V_35 , V_250 , V_245 , V_248 ) )
return - V_76 ;
V_245 = F_25 ( & V_23 -> V_251 ) ;
if ( F_26 ( V_35 , V_252 , V_245 ,
V_248 ) )
return - V_76 ;
V_245 = F_25 ( & V_23 -> V_253 ) ;
if ( F_26 ( V_35 , V_254 , V_245 , V_248 ) )
return - V_76 ;
if ( F_23 ( V_35 , V_177 , V_237 ) ||
F_23 ( V_35 , V_178 , V_238 ) ||
F_23 ( V_35 , V_179 , V_239 ) ||
F_23 ( V_35 , V_180 , V_241 ) ||
F_23 ( V_35 , V_181 , V_149 ) ||
F_22 ( V_35 , V_182 , V_42 ) ||
F_21 ( V_35 , V_183 , V_244 ) ||
F_22 ( V_35 , V_190 , V_23 -> V_193 ) ||
F_24 ( V_35 , V_255 , sizeof( struct V_28 ) ,
& V_23 -> V_242 ) ||
F_24 ( V_35 , V_256 , sizeof( struct V_28 ) ,
& V_23 -> V_61 ) ||
F_22 ( V_35 , V_257 , V_23 -> V_258 ) ||
F_23 ( V_35 , V_259 , V_23 -> V_260 ) ||
F_21 ( V_35 , V_261 , V_23 -> V_262 ) ||
F_21 ( V_35 , V_263 ,
V_23 -> V_264 ) ||
F_24 ( V_35 , V_194 , V_168 , V_23 -> V_196 ) )
return - V_76 ;
#ifdef F_83
if ( F_117 ( V_35 , V_170 , V_23 -> V_185 ) ||
F_22 ( V_35 , V_186 , V_23 -> V_265 ) ||
F_21 ( V_35 , V_188 , V_23 -> V_266 ) )
return - V_76 ;
#endif
#ifdef F_17
if ( F_21 ( V_35 , V_199 , V_23 -> V_85 ) ||
F_21 ( V_35 , V_200 , ! V_23 -> V_267 ) ||
F_21 ( V_35 , V_202 ,
V_23 -> V_204 ) ||
F_21 ( V_35 , V_205 , V_23 -> V_268 ) ||
F_21 ( V_35 , V_227 ,
V_23 -> V_229 ) ||
F_23 ( V_35 , V_207 ,
V_23 -> V_208 ) ||
F_23 ( V_35 , V_209 , V_23 -> V_210 ) ||
F_23 ( V_35 , V_211 ,
V_23 -> V_212 ) ||
F_23 ( V_35 , V_213 ,
V_23 -> V_214 ) )
return - V_76 ;
V_245 = F_115 ( V_23 -> V_216 ) ;
if ( F_26 ( V_35 , V_215 , V_245 ,
V_248 ) )
return - V_76 ;
V_245 = F_115 ( V_23 -> V_218 ) ;
if ( F_26 ( V_35 , V_217 , V_245 ,
V_248 ) )
return - V_76 ;
V_245 = F_115 ( V_23 -> V_220 ) ;
if ( F_26 ( V_35 , V_219 , V_245 ,
V_248 ) )
return - V_76 ;
V_245 = F_115 ( V_23 -> V_222 ) ;
if ( F_26 ( V_35 , V_221 , V_245 ,
V_248 ) )
return - V_76 ;
V_245 = F_115 ( V_23 -> V_224 ) ;
if ( F_26 ( V_35 , V_223 , V_245 ,
V_248 ) )
return - V_76 ;
V_245 = F_115 ( V_23 -> V_226 ) ;
if ( F_26 ( V_35 , V_225 , V_245 ,
V_248 ) )
return - V_76 ;
#endif
#if F_112 ( V_230 )
if ( F_21 ( V_35 , V_231 ,
V_23 -> V_232 ? 1 : 0 ) ||
F_21 ( V_35 , V_233 ,
V_23 -> V_234 ? 1 : 0 ) ||
F_21 ( V_35 , V_235 ,
V_23 -> V_236 ? 1 : 0 ) )
return - V_76 ;
#endif
return 0 ;
}
static T_3 F_118 ( const struct V_18 * V_19 )
{
struct V_22 * V_23 = F_12 ( V_19 ) ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_269 = 0 ;
V_2 = F_119 ( V_23 ) ;
if ( V_2 ) {
F_120 (v, &vg->vlan_list, vlist)
V_269 ++ ;
}
return V_269 * F_14 ( sizeof( struct V_270 ) ) +
F_14 ( sizeof( struct V_271 ) ) +
F_14 ( 0 ) ;
}
static T_3 F_121 ( const struct V_18 * V_19 )
{
return F_14 ( sizeof( struct V_271 ) ) +
F_14 ( 0 ) ;
}
static T_3 F_122 ( const struct V_18 * V_19 , int V_143 )
{
T_3 V_272 = 0 ;
switch ( V_143 ) {
case V_273 :
V_272 = F_118 ( V_19 ) ;
break;
case V_274 :
V_272 = F_121 ( V_19 ) ;
break;
}
return V_272 ;
}
static int F_123 ( struct V_34 * V_35 ,
const struct V_18 * V_19 ,
int * V_275 )
{
struct V_22 * V_23 = F_12 ( V_19 ) ;
struct V_122 * T_7 V_276 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_122 * V_123 ;
int V_277 = 0 ;
V_123 = F_38 ( V_35 , V_278 ) ;
if ( ! V_123 )
return - V_76 ;
V_2 = F_119 ( V_23 ) ;
if ( V_2 ) {
F_120 (v, &vg->vlan_list, vlist) {
struct V_270 V_279 ;
struct V_280 V_281 ;
if ( ++ V_277 < * V_275 )
continue;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_279 . V_13 = V_5 -> V_13 ;
F_124 ( V_5 , & V_281 ) ;
V_279 . V_282 = V_281 . V_282 ;
V_279 . V_283 = V_281 . V_283 ;
V_279 . V_284 = V_281 . V_284 ;
V_279 . V_285 = V_281 . V_285 ;
if ( F_24 ( V_35 , V_286 , sizeof( V_279 ) , & V_279 ) )
goto V_91;
}
}
#ifdef F_17
if ( ++ V_277 >= * V_275 ) {
T_7 = F_125 ( V_35 , V_287 ,
sizeof( struct V_271 ) ,
V_288 ) ;
if ( ! T_7 )
goto V_91;
F_126 ( V_23 , NULL , F_60 ( T_7 ) ) ;
}
#endif
F_39 ( V_35 , V_123 ) ;
* V_275 = 0 ;
return 0 ;
V_91:
F_39 ( V_35 , V_123 ) ;
* V_275 = V_277 ;
return - V_76 ;
}
static int F_127 ( struct V_34 * V_35 ,
const struct V_18 * V_19 ,
int * V_275 )
{
struct V_20 * V_21 = F_50 ( V_19 ) ;
struct V_122 * T_7 V_276 ;
struct V_122 * V_123 ;
if ( ! V_21 )
return 0 ;
V_123 = F_38 ( V_35 , V_278 ) ;
if ( ! V_123 )
return - V_76 ;
#ifdef F_17
T_7 = F_125 ( V_35 , V_287 ,
sizeof( struct V_271 ) ,
V_288 ) ;
if ( ! T_7 ) {
F_39 ( V_35 , V_123 ) ;
return - V_76 ;
}
F_126 ( V_21 -> V_23 , V_21 , F_60 ( T_7 ) ) ;
#endif
F_39 ( V_35 , V_123 ) ;
return 0 ;
}
static int F_128 ( struct V_34 * V_35 , const struct V_18 * V_19 ,
int * V_275 , int V_143 )
{
int V_176 = - V_145 ;
switch ( V_143 ) {
case V_273 :
V_176 = F_123 ( V_35 , V_19 , V_275 ) ;
break;
case V_274 :
V_176 = F_127 ( V_35 , V_19 , V_275 ) ;
break;
}
return V_176 ;
}
int T_8 F_129 ( void )
{
int V_93 ;
F_130 () ;
F_131 ( & V_289 ) ;
V_93 = F_132 ( & V_290 ) ;
if ( V_93 )
goto V_291;
return 0 ;
V_291:
F_133 ( & V_289 ) ;
F_134 () ;
return V_93 ;
}
void F_135 ( void )
{
F_134 () ;
F_133 ( & V_289 ) ;
F_136 ( & V_290 ) ;
}
