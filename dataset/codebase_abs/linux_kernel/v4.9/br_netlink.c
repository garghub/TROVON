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
F_21 ( V_35 , V_48 ,
! ! ( V_21 -> V_9 & V_49 ) ) ||
F_21 ( V_35 , V_50 ,
! ! ( V_21 -> V_9 & V_51 ) ) ||
F_21 ( V_35 , V_52 , ! ! ( V_21 -> V_9 & V_53 ) ) ||
F_21 ( V_35 , V_54 ,
! ! ( V_21 -> V_9 & V_55 ) ) ||
F_21 ( V_35 , V_56 ,
! ! ( V_21 -> V_9 & V_57 ) ) ||
F_21 ( V_35 , V_58 , ! ! ( V_21 -> V_9 & V_59 ) ) ||
F_21 ( V_35 , V_60 ,
! ! ( V_21 -> V_9 & V_61 ) ) ||
F_24 ( V_35 , V_62 , sizeof( struct V_28 ) ,
& V_21 -> V_63 ) ||
F_24 ( V_35 , V_64 , sizeof( struct V_28 ) ,
& V_21 -> V_65 ) ||
F_22 ( V_35 , V_66 , V_21 -> V_67 ) ||
F_22 ( V_35 , V_68 , V_21 -> V_69 ) ||
F_22 ( V_35 , V_70 , V_21 -> V_71 ) ||
F_22 ( V_35 , V_72 , V_21 -> V_73 ) ||
F_21 ( V_35 , V_74 ,
V_21 -> V_75 ) ||
F_21 ( V_35 , V_76 , V_21 -> V_77 ) )
return - V_78 ;
V_38 = F_25 ( & V_21 -> V_79 ) ;
if ( F_26 ( V_35 , V_80 , V_38 ,
V_81 ) )
return - V_78 ;
V_38 = F_25 ( & V_21 -> V_82 ) ;
if ( F_26 ( V_35 , V_83 , V_38 ,
V_81 ) )
return - V_78 ;
V_38 = F_25 ( & V_21 -> V_84 ) ;
if ( F_26 ( V_35 , V_85 , V_38 ,
V_81 ) )
return - V_78 ;
#ifdef F_17
if ( F_21 ( V_35 , V_86 ,
V_21 -> V_87 ) )
return - V_78 ;
#endif
return 0 ;
}
static int F_27 ( struct V_34 * V_35 , T_2 V_88 ,
T_2 V_89 , T_2 V_9 )
{
struct V_27 V_90 ;
if ( ( V_89 - V_88 ) > 0 ) {
V_90 . V_13 = V_88 ;
V_90 . V_9 = V_9 | V_91 ;
if ( F_24 ( V_35 , V_92 ,
sizeof( V_90 ) , & V_90 ) )
goto V_93;
V_90 . V_13 = V_89 ;
V_90 . V_9 = V_9 | V_94 ;
if ( F_24 ( V_35 , V_92 ,
sizeof( V_90 ) , & V_90 ) )
goto V_93;
} else {
V_90 . V_13 = V_88 ;
V_90 . V_9 = V_9 ;
if ( F_24 ( V_35 , V_92 ,
sizeof( V_90 ) , & V_90 ) )
goto V_93;
}
return 0 ;
V_93:
return - V_78 ;
}
static int F_28 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_6 = 0 , V_7 = 0 , V_8 = 0 ;
T_2 V_9 , V_10 ;
int V_95 = 0 ;
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
V_95 = F_27 ( V_35 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_95 )
return V_95 ;
}
V_16:
V_6 = V_5 -> V_13 ;
V_7 = V_5 -> V_13 ;
V_8 = V_9 ;
}
if ( V_6 != 0 ) {
V_95 = F_27 ( V_35 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_95 )
return V_95 ;
}
return 0 ;
}
static int F_29 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_27 V_90 ;
struct V_4 * V_5 ;
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_3 (v, &vg->vlan_list, vlist) {
if ( ! F_4 ( V_5 ) )
continue;
V_90 . V_13 = V_5 -> V_13 ;
V_90 . V_9 = 0 ;
if ( V_5 -> V_13 == V_10 )
V_90 . V_9 |= V_14 ;
if ( V_5 -> V_9 & V_15 )
V_90 . V_9 |= V_15 ;
if ( F_24 ( V_35 , V_92 ,
sizeof( V_90 ) , & V_90 ) )
goto V_93;
}
return 0 ;
V_93:
return - V_78 ;
}
static int F_30 ( struct V_34 * V_35 ,
struct V_20 * V_96 ,
T_1 V_97 , T_1 V_98 , int V_99 , unsigned int V_9 ,
T_1 V_3 , const struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_31 * V_100 ;
struct V_101 * V_102 ;
V_29 V_103 = F_31 ( V_19 ) ? V_19 -> V_103 : V_104 ;
if ( V_96 )
V_23 = V_96 -> V_23 ;
else
V_23 = F_12 ( V_19 ) ;
F_32 ( V_23 , L_1 ,
V_99 , V_19 -> V_105 , V_23 -> V_19 -> V_105 ) ;
V_102 = F_33 ( V_35 , V_97 , V_98 , V_99 , sizeof( * V_100 ) , V_9 ) ;
if ( V_102 == NULL )
return - V_78 ;
V_100 = F_34 ( V_102 ) ;
V_100 -> V_106 = V_107 ;
V_100 -> V_108 = 0 ;
V_100 -> V_109 = V_19 -> type ;
V_100 -> V_110 = V_19 -> V_111 ;
V_100 -> V_112 = F_35 ( V_19 ) ;
V_100 -> V_113 = 0 ;
if ( F_36 ( V_35 , V_114 , V_19 -> V_105 ) ||
F_23 ( V_35 , V_115 , V_23 -> V_19 -> V_111 ) ||
F_23 ( V_35 , V_116 , V_19 -> V_117 ) ||
F_21 ( V_35 , V_118 , V_103 ) ||
( V_19 -> V_119 &&
F_24 ( V_35 , V_120 , V_19 -> V_119 , V_19 -> V_121 ) ) ||
( V_19 -> V_111 != F_37 ( V_19 ) &&
F_23 ( V_35 , V_122 , F_37 ( V_19 ) ) ) )
goto V_93;
if ( V_99 == V_123 && V_96 ) {
struct V_124 * V_125
= F_38 ( V_35 , V_126 | V_127 ) ;
if ( V_125 == NULL || F_20 ( V_35 , V_96 ) < 0 )
goto V_93;
F_39 ( V_35 , V_125 ) ;
}
if ( ( V_3 & V_17 ) ||
( V_3 & V_12 ) ) {
struct V_1 * V_2 ;
struct V_124 * V_128 ;
int V_95 ;
F_6 () ;
if ( V_96 )
V_2 = F_11 ( V_96 ) ;
else
V_2 = F_13 ( V_23 ) ;
if ( ! V_2 || ! V_2 -> V_11 ) {
F_7 () ;
goto V_129;
}
V_128 = F_38 ( V_35 , V_130 ) ;
if ( ! V_128 ) {
F_7 () ;
goto V_93;
}
if ( V_3 & V_12 )
V_95 = F_28 ( V_35 , V_2 ) ;
else
V_95 = F_29 ( V_35 , V_2 ) ;
F_7 () ;
if ( V_95 )
goto V_93;
F_39 ( V_35 , V_128 ) ;
}
V_129:
F_40 ( V_35 , V_102 ) ;
return 0 ;
V_93:
F_41 ( V_35 , V_102 ) ;
return - V_78 ;
}
void F_42 ( int V_99 , struct V_20 * V_96 )
{
struct V_131 * V_131 ;
struct V_34 * V_35 ;
int V_95 = - V_132 ;
T_1 V_133 = V_12 ;
if ( ! V_96 )
return;
V_131 = F_43 ( V_96 -> V_19 ) ;
F_32 ( V_96 -> V_23 , L_2 ,
( unsigned int ) V_96 -> V_73 , V_96 -> V_19 -> V_105 , V_99 ) ;
V_35 = F_44 ( F_18 ( V_96 -> V_19 , V_133 ) , V_134 ) ;
if ( V_35 == NULL )
goto V_135;
V_95 = F_30 ( V_35 , V_96 , 0 , 0 , V_99 , 0 , V_133 , V_96 -> V_19 ) ;
if ( V_95 < 0 ) {
F_45 ( V_95 == - V_78 ) ;
F_46 ( V_35 ) ;
goto V_135;
}
F_47 ( V_35 , V_131 , 0 , V_136 , NULL , V_134 ) ;
return;
V_135:
F_48 ( V_131 , V_136 , V_95 ) ;
}
int F_49 ( struct V_34 * V_35 , T_1 V_97 , T_1 V_98 ,
struct V_18 * V_19 , T_1 V_3 , int V_137 )
{
struct V_20 * V_96 = F_50 ( V_19 ) ;
if ( ! V_96 && ! ( V_3 & V_17 ) &&
! ( V_3 & V_12 ) )
return 0 ;
return F_30 ( V_35 , V_96 , V_97 , V_98 , V_123 , V_137 ,
V_3 , V_19 ) ;
}
static int F_51 ( struct V_22 * V_23 , struct V_20 * V_21 ,
int V_138 , struct V_27 * V_90 )
{
int V_95 = 0 ;
switch ( V_138 ) {
case V_139 :
if ( V_21 ) {
V_95 = F_52 ( V_21 , V_90 -> V_13 , V_90 -> V_9 ) ;
if ( V_95 )
break;
} else {
V_90 -> V_9 |= V_140 ;
V_95 = F_53 ( V_23 , V_90 -> V_13 , V_90 -> V_9 ) ;
}
break;
case V_141 :
if ( V_21 ) {
F_54 ( V_21 , V_90 -> V_13 ) ;
if ( V_90 -> V_9 & V_142 )
F_55 ( V_21 -> V_23 , V_90 -> V_13 ) ;
} else {
F_55 ( V_23 , V_90 -> V_13 ) ;
}
break;
}
return V_95 ;
}
static int F_56 ( struct V_22 * V_23 ,
struct V_20 * V_21 ,
struct V_124 * V_143 ,
int V_138 )
{
struct V_27 * V_144 = NULL ;
struct V_27 * V_90 = NULL ;
struct V_124 * V_145 ;
int V_95 = 0 ;
int V_146 ;
F_57 (attr, af_spec, rem) {
if ( F_58 ( V_145 ) != V_92 )
continue;
if ( F_59 ( V_145 ) != sizeof( struct V_27 ) )
return - V_147 ;
V_90 = F_60 ( V_145 ) ;
if ( ! V_90 -> V_13 || V_90 -> V_13 >= V_148 )
return - V_147 ;
if ( V_90 -> V_9 & V_91 ) {
if ( V_144 )
return - V_147 ;
V_144 = V_90 ;
if ( V_144 -> V_9 & V_14 )
return - V_147 ;
continue;
}
if ( V_144 ) {
struct V_27 V_149 ;
int V_5 ;
if ( ! ( V_90 -> V_9 & V_94 ) )
return - V_147 ;
if ( V_90 -> V_13 <= V_144 -> V_13 )
return - V_147 ;
memcpy ( & V_149 , V_144 ,
sizeof( struct V_27 ) ) ;
for ( V_5 = V_144 -> V_13 ; V_5 <= V_90 -> V_13 ; V_5 ++ ) {
V_149 . V_13 = V_5 ;
V_95 = F_51 ( V_23 , V_21 , V_138 , & V_149 ) ;
if ( V_95 )
break;
}
V_144 = NULL ;
} else {
V_95 = F_51 ( V_23 , V_21 , V_138 , V_90 ) ;
}
if ( V_95 )
break;
}
return V_95 ;
}
static int F_61 ( struct V_20 * V_21 , V_29 V_40 )
{
if ( V_40 > V_150 )
return - V_147 ;
if ( V_21 -> V_23 -> V_151 == V_152 )
return - V_153 ;
if ( ! F_31 ( V_21 -> V_19 ) ||
( ! F_62 ( V_21 -> V_19 ) && V_40 != V_154 ) )
return - V_155 ;
F_63 ( V_21 , V_40 ) ;
F_64 ( V_21 -> V_23 ) ;
return 0 ;
}
static void F_65 ( struct V_20 * V_21 , struct V_124 * V_156 [] ,
int V_157 , unsigned long V_158 )
{
if ( V_156 [ V_157 ] ) {
V_29 V_159 = F_66 ( V_156 [ V_157 ] ) ;
if ( V_159 )
V_21 -> V_9 |= V_158 ;
else
V_21 -> V_9 &= ~ V_158 ;
}
}
static int F_67 ( struct V_20 * V_21 , struct V_124 * V_156 [] )
{
int V_95 ;
unsigned long V_160 = V_21 -> V_9 ;
F_65 ( V_21 , V_156 , V_45 , V_37 ) ;
F_65 ( V_21 , V_156 , V_46 , V_47 ) ;
F_65 ( V_21 , V_156 , V_50 , V_51 ) ;
F_65 ( V_21 , V_156 , V_48 , V_49 ) ;
F_65 ( V_21 , V_156 , V_52 , V_53 ) ;
F_65 ( V_21 , V_156 , V_54 , V_55 ) ;
F_65 ( V_21 , V_156 , V_56 , V_57 ) ;
F_65 ( V_21 , V_156 , V_58 , V_59 ) ;
F_65 ( V_21 , V_156 , V_60 , V_61 ) ;
if ( V_156 [ V_43 ] ) {
V_95 = F_68 ( V_21 , F_69 ( V_156 [ V_43 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_156 [ V_41 ] ) {
V_95 = F_70 ( V_21 , F_71 ( V_156 [ V_41 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_156 [ V_39 ] ) {
V_95 = F_61 ( V_21 , F_66 ( V_156 [ V_39 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_156 [ V_161 ] )
F_72 ( V_21 -> V_23 , V_21 , 0 , 0 ) ;
#ifdef F_17
if ( V_156 [ V_86 ] ) {
V_29 V_162 = F_66 ( V_156 [ V_86 ] ) ;
V_95 = F_73 ( V_21 , V_162 ) ;
if ( V_95 )
return V_95 ;
}
#endif
F_74 ( V_21 , V_160 ^ V_21 -> V_9 ) ;
return 0 ;
}
int F_75 ( struct V_18 * V_19 , struct V_101 * V_102 , T_2 V_9 )
{
struct V_124 * V_163 ;
struct V_124 * V_164 ;
struct V_20 * V_21 ;
struct V_124 * V_156 [ V_165 + 1 ] ;
int V_95 = 0 ;
V_163 = F_76 ( V_102 , sizeof( struct V_31 ) , V_126 ) ;
V_164 = F_76 ( V_102 , sizeof( struct V_31 ) , V_130 ) ;
if ( ! V_163 && ! V_164 )
return 0 ;
V_21 = F_50 ( V_19 ) ;
if ( ! V_21 && ! V_164 )
return - V_147 ;
if ( V_21 && V_163 ) {
if ( V_163 -> F_58 & V_127 ) {
V_95 = F_77 ( V_156 , V_165 ,
V_163 , V_166 ) ;
if ( V_95 )
return V_95 ;
F_78 ( & V_21 -> V_23 -> V_167 ) ;
V_95 = F_67 ( V_21 , V_156 ) ;
F_79 ( & V_21 -> V_23 -> V_167 ) ;
} else {
if ( F_59 ( V_163 ) < sizeof( V_29 ) )
return - V_147 ;
F_78 ( & V_21 -> V_23 -> V_167 ) ;
V_95 = F_61 ( V_21 , F_66 ( V_163 ) ) ;
F_79 ( & V_21 -> V_23 -> V_167 ) ;
}
if ( V_95 )
goto V_168;
}
if ( V_164 ) {
V_95 = F_56 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_164 , V_139 ) ;
}
if ( V_95 == 0 )
F_42 ( V_123 , V_21 ) ;
V_168:
return V_95 ;
}
int F_80 ( struct V_18 * V_19 , struct V_101 * V_102 , T_2 V_9 )
{
struct V_124 * V_164 ;
struct V_20 * V_21 ;
int V_95 = 0 ;
V_164 = F_76 ( V_102 , sizeof( struct V_31 ) , V_130 ) ;
if ( ! V_164 )
return 0 ;
V_21 = F_50 ( V_19 ) ;
if ( ! V_21 && ! ( V_19 -> V_25 & V_26 ) )
return - V_147 ;
V_95 = F_56 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_164 , V_141 ) ;
if ( V_95 == 0 )
F_42 ( V_123 , V_21 ) ;
return V_95 ;
}
static int F_81 ( struct V_124 * V_156 [] , struct V_124 * V_169 [] )
{
if ( V_156 [ V_120 ] ) {
if ( F_59 ( V_156 [ V_120 ] ) != V_170 )
return - V_147 ;
if ( ! F_82 ( F_60 ( V_156 [ V_120 ] ) ) )
return - V_171 ;
}
if ( ! V_169 )
return 0 ;
#ifdef F_83
if ( V_169 [ V_172 ] ) {
switch ( F_84 ( V_169 [ V_172 ] ) ) {
case F_85 ( V_173 ) :
case F_85 ( V_174 ) :
break;
default:
return - V_175 ;
}
}
#endif
return 0 ;
}
static int F_86 ( struct V_131 * V_176 , struct V_18 * V_19 ,
struct V_124 * V_156 [] , struct V_124 * V_169 [] )
{
struct V_22 * V_23 = F_12 ( V_19 ) ;
if ( V_156 [ V_120 ] ) {
F_78 ( & V_23 -> V_167 ) ;
F_87 ( V_23 , F_60 ( V_156 [ V_120 ] ) ) ;
F_79 ( & V_23 -> V_167 ) ;
}
return F_88 ( V_19 ) ;
}
static int F_89 ( struct V_18 * V_177 ,
struct V_18 * V_19 ,
struct V_124 * V_156 [] ,
struct V_124 * V_169 [] )
{
struct V_22 * V_23 = F_12 ( V_177 ) ;
int V_178 ;
if ( ! V_169 )
return 0 ;
F_78 ( & V_23 -> V_167 ) ;
V_178 = F_67 ( F_50 ( V_19 ) , V_169 ) ;
F_79 ( & V_23 -> V_167 ) ;
return V_178 ;
}
static int F_90 ( struct V_34 * V_35 ,
const struct V_18 * V_177 ,
const struct V_18 * V_19 )
{
return F_20 ( V_35 , F_50 ( V_19 ) ) ;
}
static T_3 F_91 ( const struct V_18 * V_177 ,
const struct V_18 * V_19 )
{
return F_15 () ;
}
static int F_92 ( struct V_18 * V_177 , struct V_124 * V_156 [] ,
struct V_124 * V_169 [] )
{
struct V_22 * V_23 = F_12 ( V_177 ) ;
int V_95 ;
if ( ! V_169 )
return 0 ;
if ( V_169 [ V_179 ] ) {
V_95 = F_93 ( V_23 , F_69 ( V_169 [ V_179 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_180 ] ) {
V_95 = F_94 ( V_23 , F_69 ( V_169 [ V_180 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_181 ] ) {
V_95 = F_95 ( V_23 , F_69 ( V_169 [ V_181 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_182 ] ) {
V_95 = F_96 ( V_23 , F_69 ( V_169 [ V_182 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_183 ] ) {
T_1 V_151 = F_69 ( V_169 [ V_183 ] ) ;
F_97 ( V_23 , V_151 ) ;
}
if ( V_169 [ V_184 ] ) {
T_1 V_42 = F_71 ( V_169 [ V_184 ] ) ;
F_98 ( V_23 , V_42 ) ;
}
if ( V_169 [ V_185 ] ) {
V_29 V_186 = F_66 ( V_169 [ V_185 ] ) ;
V_95 = F_99 ( V_23 , V_186 ) ;
if ( V_95 )
return V_95 ;
}
#ifdef F_83
if ( V_169 [ V_172 ] ) {
T_4 V_187 = F_84 ( V_169 [ V_172 ] ) ;
V_95 = F_100 ( V_23 , V_187 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_188 ] ) {
T_5 V_189 = F_71 ( V_169 [ V_188 ] ) ;
V_95 = F_101 ( V_23 , V_189 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_190 ] ) {
T_6 V_191 = F_66 ( V_169 [ V_190 ] ) ;
V_95 = F_102 ( V_23 , V_191 ) ;
if ( V_95 )
return V_95 ;
}
#endif
if ( V_169 [ V_192 ] ) {
T_2 V_193 = F_71 ( V_169 [ V_192 ] ) ;
if ( V_193 & V_194 )
return - V_147 ;
V_23 -> V_195 = V_193 ;
}
if ( V_169 [ V_196 ] ) {
V_29 V_197 [ V_170 ] ;
if ( F_59 ( V_169 [ V_196 ] ) != V_170 )
return - V_147 ;
memcpy ( V_197 , F_60 ( V_169 [ V_196 ] ) , V_170 ) ;
if ( ! F_103 ( V_197 ) )
return - V_147 ;
if ( V_197 [ 5 ] == 1 ||
V_197 [ 5 ] == 2 ||
V_197 [ 5 ] == 3 )
return - V_147 ;
F_78 ( & V_23 -> V_167 ) ;
memcpy ( V_23 -> V_198 , V_197 , sizeof( V_23 -> V_198 ) ) ;
F_79 ( & V_23 -> V_167 ) ;
V_23 -> V_199 = true ;
F_104 ( V_23 ) ;
}
if ( V_169 [ V_200 ] )
F_105 ( V_23 ) ;
#ifdef F_17
if ( V_169 [ V_201 ] ) {
V_29 V_87 = F_66 ( V_169 [ V_201 ] ) ;
V_95 = F_106 ( V_23 , V_87 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_202 ] ) {
V_29 V_203 = F_66 ( V_169 [ V_202 ] ) ;
V_95 = F_107 ( V_23 , V_203 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_204 ] ) {
V_29 V_205 ;
V_205 = F_66 ( V_169 [ V_204 ] ) ;
V_23 -> V_206 = ! ! V_205 ;
}
if ( V_169 [ V_207 ] ) {
V_29 V_208 = F_66 ( V_169 [ V_207 ] ) ;
V_95 = F_108 ( V_23 , V_208 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_209 ] ) {
T_1 V_205 = F_69 ( V_169 [ V_209 ] ) ;
V_23 -> V_210 = V_205 ;
}
if ( V_169 [ V_211 ] ) {
T_1 V_212 = F_69 ( V_169 [ V_211 ] ) ;
V_95 = F_109 ( V_23 , V_212 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_213 ] ) {
T_1 V_205 = F_69 ( V_169 [ V_213 ] ) ;
V_23 -> V_214 = V_205 ;
}
if ( V_169 [ V_215 ] ) {
T_1 V_205 = F_69 ( V_169 [ V_215 ] ) ;
V_23 -> V_216 = V_205 ;
}
if ( V_169 [ V_217 ] ) {
V_30 V_205 = F_110 ( V_169 [ V_217 ] ) ;
V_23 -> V_218 = F_111 ( V_205 ) ;
}
if ( V_169 [ V_219 ] ) {
V_30 V_205 = F_110 ( V_169 [ V_219 ] ) ;
V_23 -> V_220 = F_111 ( V_205 ) ;
}
if ( V_169 [ V_221 ] ) {
V_30 V_205 = F_110 ( V_169 [ V_221 ] ) ;
V_23 -> V_222 = F_111 ( V_205 ) ;
}
if ( V_169 [ V_223 ] ) {
V_30 V_205 = F_110 ( V_169 [ V_223 ] ) ;
V_23 -> V_224 = F_111 ( V_205 ) ;
}
if ( V_169 [ V_225 ] ) {
V_30 V_205 = F_110 ( V_169 [ V_225 ] ) ;
V_23 -> V_226 = F_111 ( V_205 ) ;
}
if ( V_169 [ V_227 ] ) {
V_30 V_205 = F_110 ( V_169 [ V_227 ] ) ;
V_23 -> V_228 = F_111 ( V_205 ) ;
}
if ( V_169 [ V_229 ] ) {
T_6 V_230 ;
V_230 = F_66 ( V_169 [ V_229 ] ) ;
V_23 -> V_231 = ! ! V_230 ;
}
#endif
#if F_112 ( V_232 )
if ( V_169 [ V_233 ] ) {
V_29 V_205 = F_66 ( V_169 [ V_233 ] ) ;
V_23 -> V_234 = V_205 ? true : false ;
}
if ( V_169 [ V_235 ] ) {
V_29 V_205 = F_66 ( V_169 [ V_235 ] ) ;
V_23 -> V_236 = V_205 ? true : false ;
}
if ( V_169 [ V_237 ] ) {
V_29 V_205 = F_66 ( V_169 [ V_237 ] ) ;
V_23 -> V_238 = V_205 ? true : false ;
}
#endif
return 0 ;
}
static T_3 F_113 ( const struct V_18 * V_177 )
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
F_14 ( V_170 ) +
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
#if F_112 ( V_232 )
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
#endif
0 ;
}
static int F_114 ( struct V_34 * V_35 , const struct V_18 * V_177 )
{
struct V_22 * V_23 = F_12 ( V_177 ) ;
T_1 V_239 = F_115 ( V_23 -> V_239 ) ;
T_1 V_240 = F_115 ( V_23 -> V_240 ) ;
T_1 V_241 = F_115 ( V_23 -> V_242 ) ;
T_1 V_243 = F_115 ( V_23 -> V_243 ) ;
T_1 V_151 = V_23 -> V_151 ;
T_2 V_42 = ( V_23 -> V_244 . V_245 [ 0 ] << 8 ) | V_23 -> V_244 . V_245 [ 1 ] ;
V_29 V_246 = F_116 ( V_23 ) ;
V_30 V_247 ;
V_247 = F_25 ( & V_23 -> V_248 ) ;
if ( F_26 ( V_35 , V_249 , V_247 , V_250 ) )
return - V_78 ;
V_247 = F_25 ( & V_23 -> V_251 ) ;
if ( F_26 ( V_35 , V_252 , V_247 , V_250 ) )
return - V_78 ;
V_247 = F_25 ( & V_23 -> V_253 ) ;
if ( F_26 ( V_35 , V_254 , V_247 ,
V_250 ) )
return - V_78 ;
V_247 = F_25 ( & V_23 -> V_255 ) ;
if ( F_26 ( V_35 , V_256 , V_247 , V_250 ) )
return - V_78 ;
if ( F_23 ( V_35 , V_179 , V_239 ) ||
F_23 ( V_35 , V_180 , V_240 ) ||
F_23 ( V_35 , V_181 , V_241 ) ||
F_23 ( V_35 , V_182 , V_243 ) ||
F_23 ( V_35 , V_183 , V_151 ) ||
F_22 ( V_35 , V_184 , V_42 ) ||
F_21 ( V_35 , V_185 , V_246 ) ||
F_22 ( V_35 , V_192 , V_23 -> V_195 ) ||
F_24 ( V_35 , V_257 , sizeof( struct V_28 ) ,
& V_23 -> V_244 ) ||
F_24 ( V_35 , V_258 , sizeof( struct V_28 ) ,
& V_23 -> V_63 ) ||
F_22 ( V_35 , V_259 , V_23 -> V_260 ) ||
F_23 ( V_35 , V_261 , V_23 -> V_262 ) ||
F_21 ( V_35 , V_263 , V_23 -> V_264 ) ||
F_21 ( V_35 , V_265 ,
V_23 -> V_266 ) ||
F_24 ( V_35 , V_196 , V_170 , V_23 -> V_198 ) )
return - V_78 ;
#ifdef F_83
if ( F_117 ( V_35 , V_172 , V_23 -> V_187 ) ||
F_22 ( V_35 , V_188 , V_23 -> V_267 ) ||
F_21 ( V_35 , V_190 , V_23 -> V_268 ) )
return - V_78 ;
#endif
#ifdef F_17
if ( F_21 ( V_35 , V_201 , V_23 -> V_87 ) ||
F_21 ( V_35 , V_202 , ! V_23 -> V_269 ) ||
F_21 ( V_35 , V_204 ,
V_23 -> V_206 ) ||
F_21 ( V_35 , V_207 , V_23 -> V_270 ) ||
F_21 ( V_35 , V_229 ,
V_23 -> V_231 ) ||
F_23 ( V_35 , V_209 ,
V_23 -> V_210 ) ||
F_23 ( V_35 , V_211 , V_23 -> V_212 ) ||
F_23 ( V_35 , V_213 ,
V_23 -> V_214 ) ||
F_23 ( V_35 , V_215 ,
V_23 -> V_216 ) )
return - V_78 ;
V_247 = F_115 ( V_23 -> V_218 ) ;
if ( F_26 ( V_35 , V_217 , V_247 ,
V_250 ) )
return - V_78 ;
V_247 = F_115 ( V_23 -> V_220 ) ;
if ( F_26 ( V_35 , V_219 , V_247 ,
V_250 ) )
return - V_78 ;
V_247 = F_115 ( V_23 -> V_222 ) ;
if ( F_26 ( V_35 , V_221 , V_247 ,
V_250 ) )
return - V_78 ;
V_247 = F_115 ( V_23 -> V_224 ) ;
if ( F_26 ( V_35 , V_223 , V_247 ,
V_250 ) )
return - V_78 ;
V_247 = F_115 ( V_23 -> V_226 ) ;
if ( F_26 ( V_35 , V_225 , V_247 ,
V_250 ) )
return - V_78 ;
V_247 = F_115 ( V_23 -> V_228 ) ;
if ( F_26 ( V_35 , V_227 , V_247 ,
V_250 ) )
return - V_78 ;
#endif
#if F_112 ( V_232 )
if ( F_21 ( V_35 , V_233 ,
V_23 -> V_234 ? 1 : 0 ) ||
F_21 ( V_35 , V_235 ,
V_23 -> V_236 ? 1 : 0 ) ||
F_21 ( V_35 , V_237 ,
V_23 -> V_238 ? 1 : 0 ) )
return - V_78 ;
#endif
return 0 ;
}
static T_3 F_118 ( const struct V_18 * V_19 , int V_145 )
{
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
int V_271 = 0 ;
switch ( V_145 ) {
case V_272 :
V_23 = F_12 ( V_19 ) ;
V_2 = F_119 ( V_23 ) ;
break;
case V_273 :
V_21 = F_50 ( V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = V_21 -> V_23 ;
V_2 = F_120 ( V_21 ) ;
break;
default:
return 0 ;
}
if ( V_2 ) {
F_121 (v, &vg->vlan_list, vlist)
V_271 ++ ;
}
return V_271 * F_14 ( sizeof( struct V_274 ) ) +
F_14 ( sizeof( struct V_275 ) ) +
F_14 ( 0 ) ;
}
static int F_122 ( struct V_34 * V_35 ,
const struct V_18 * V_19 ,
int * V_276 , int V_145 )
{
struct V_124 * T_7 V_277 ;
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
struct V_124 * V_125 ;
int V_278 = 0 ;
switch ( V_145 ) {
case V_272 :
V_23 = F_12 ( V_19 ) ;
V_2 = F_119 ( V_23 ) ;
break;
case V_273 :
V_21 = F_50 ( V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = V_21 -> V_23 ;
V_2 = F_120 ( V_21 ) ;
break;
default:
return - V_147 ;
}
V_125 = F_38 ( V_35 , V_279 ) ;
if ( ! V_125 )
return - V_78 ;
if ( V_2 ) {
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_121 (v, &vg->vlan_list, vlist) {
struct V_274 V_280 ;
struct V_281 V_282 ;
if ( ++ V_278 < * V_276 )
continue;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
V_280 . V_13 = V_5 -> V_13 ;
V_280 . V_9 = V_5 -> V_9 ;
if ( V_5 -> V_13 == V_10 )
V_280 . V_9 |= V_14 ;
F_123 ( V_5 , & V_282 ) ;
V_280 . V_283 = V_282 . V_283 ;
V_280 . V_284 = V_282 . V_284 ;
V_280 . V_285 = V_282 . V_285 ;
V_280 . V_286 = V_282 . V_286 ;
if ( F_24 ( V_35 , V_287 , sizeof( V_280 ) , & V_280 ) )
goto V_93;
}
}
#ifdef F_17
if ( ++ V_278 >= * V_276 ) {
T_7 = F_124 ( V_35 , V_288 ,
sizeof( struct V_275 ) ,
V_289 ) ;
if ( ! T_7 )
goto V_93;
F_125 ( V_23 , V_21 , F_60 ( T_7 ) ) ;
}
#endif
F_39 ( V_35 , V_125 ) ;
* V_276 = 0 ;
return 0 ;
V_93:
F_39 ( V_35 , V_125 ) ;
* V_276 = V_278 ;
return - V_78 ;
}
int T_8 F_126 ( void )
{
int V_95 ;
F_127 () ;
F_128 ( & V_290 ) ;
V_95 = F_129 ( & V_291 ) ;
if ( V_95 )
goto V_292;
return 0 ;
V_292:
F_130 ( & V_290 ) ;
F_131 () ;
return V_95 ;
}
void F_132 ( void )
{
F_131 () ;
F_130 ( & V_290 ) ;
F_133 ( & V_291 ) ;
}
