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
static int F_86 ( struct V_18 * V_176 ,
struct V_18 * V_19 ,
struct V_124 * V_156 [] ,
struct V_124 * V_169 [] )
{
struct V_22 * V_23 = F_12 ( V_176 ) ;
int V_177 ;
if ( ! V_169 )
return 0 ;
F_78 ( & V_23 -> V_167 ) ;
V_177 = F_67 ( F_50 ( V_19 ) , V_169 ) ;
F_79 ( & V_23 -> V_167 ) ;
return V_177 ;
}
static int F_87 ( struct V_34 * V_35 ,
const struct V_18 * V_176 ,
const struct V_18 * V_19 )
{
return F_20 ( V_35 , F_50 ( V_19 ) ) ;
}
static T_3 F_88 ( const struct V_18 * V_176 ,
const struct V_18 * V_19 )
{
return F_15 () ;
}
static int F_89 ( struct V_18 * V_176 , struct V_124 * V_156 [] ,
struct V_124 * V_169 [] )
{
struct V_22 * V_23 = F_12 ( V_176 ) ;
int V_95 ;
if ( ! V_169 )
return 0 ;
if ( V_169 [ V_178 ] ) {
V_95 = F_90 ( V_23 , F_69 ( V_169 [ V_178 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_179 ] ) {
V_95 = F_91 ( V_23 , F_69 ( V_169 [ V_179 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_180 ] ) {
V_95 = F_92 ( V_23 , F_69 ( V_169 [ V_180 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_181 ] ) {
V_95 = F_93 ( V_23 , F_69 ( V_169 [ V_181 ] ) ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_182 ] ) {
T_1 V_151 = F_69 ( V_169 [ V_182 ] ) ;
F_94 ( V_23 , V_151 ) ;
}
if ( V_169 [ V_183 ] ) {
T_1 V_42 = F_71 ( V_169 [ V_183 ] ) ;
F_95 ( V_23 , V_42 ) ;
}
if ( V_169 [ V_184 ] ) {
V_29 V_185 = F_66 ( V_169 [ V_184 ] ) ;
V_95 = F_96 ( V_23 , V_185 ) ;
if ( V_95 )
return V_95 ;
}
#ifdef F_83
if ( V_169 [ V_172 ] ) {
T_4 V_186 = F_84 ( V_169 [ V_172 ] ) ;
V_95 = F_97 ( V_23 , V_186 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_187 ] ) {
T_5 V_188 = F_71 ( V_169 [ V_187 ] ) ;
V_95 = F_98 ( V_23 , V_188 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_189 ] ) {
T_6 V_190 = F_66 ( V_169 [ V_189 ] ) ;
V_95 = F_99 ( V_23 , V_190 ) ;
if ( V_95 )
return V_95 ;
}
#endif
if ( V_169 [ V_191 ] ) {
T_2 V_192 = F_71 ( V_169 [ V_191 ] ) ;
if ( V_192 & V_193 )
return - V_147 ;
V_23 -> V_194 = V_192 ;
}
if ( V_169 [ V_195 ] ) {
V_29 V_196 [ V_170 ] ;
if ( F_59 ( V_169 [ V_195 ] ) != V_170 )
return - V_147 ;
memcpy ( V_196 , F_60 ( V_169 [ V_195 ] ) , V_170 ) ;
if ( ! F_100 ( V_196 ) )
return - V_147 ;
if ( V_196 [ 5 ] == 1 ||
V_196 [ 5 ] == 2 ||
V_196 [ 5 ] == 3 )
return - V_147 ;
F_78 ( & V_23 -> V_167 ) ;
memcpy ( V_23 -> V_197 , V_196 , sizeof( V_23 -> V_197 ) ) ;
F_79 ( & V_23 -> V_167 ) ;
V_23 -> V_198 = true ;
F_101 ( V_23 ) ;
}
if ( V_169 [ V_199 ] )
F_102 ( V_23 ) ;
#ifdef F_17
if ( V_169 [ V_200 ] ) {
V_29 V_87 = F_66 ( V_169 [ V_200 ] ) ;
V_95 = F_103 ( V_23 , V_87 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_201 ] ) {
V_29 V_202 = F_66 ( V_169 [ V_201 ] ) ;
V_95 = F_104 ( V_23 , V_202 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_203 ] ) {
V_29 V_204 ;
V_204 = F_66 ( V_169 [ V_203 ] ) ;
V_23 -> V_205 = ! ! V_204 ;
}
if ( V_169 [ V_206 ] ) {
V_29 V_207 = F_66 ( V_169 [ V_206 ] ) ;
V_95 = F_105 ( V_23 , V_207 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_208 ] ) {
T_1 V_204 = F_69 ( V_169 [ V_208 ] ) ;
V_23 -> V_209 = V_204 ;
}
if ( V_169 [ V_210 ] ) {
T_1 V_211 = F_69 ( V_169 [ V_210 ] ) ;
V_95 = F_106 ( V_23 , V_211 ) ;
if ( V_95 )
return V_95 ;
}
if ( V_169 [ V_212 ] ) {
T_1 V_204 = F_69 ( V_169 [ V_212 ] ) ;
V_23 -> V_213 = V_204 ;
}
if ( V_169 [ V_214 ] ) {
T_1 V_204 = F_69 ( V_169 [ V_214 ] ) ;
V_23 -> V_215 = V_204 ;
}
if ( V_169 [ V_216 ] ) {
V_30 V_204 = F_107 ( V_169 [ V_216 ] ) ;
V_23 -> V_217 = F_108 ( V_204 ) ;
}
if ( V_169 [ V_218 ] ) {
V_30 V_204 = F_107 ( V_169 [ V_218 ] ) ;
V_23 -> V_219 = F_108 ( V_204 ) ;
}
if ( V_169 [ V_220 ] ) {
V_30 V_204 = F_107 ( V_169 [ V_220 ] ) ;
V_23 -> V_221 = F_108 ( V_204 ) ;
}
if ( V_169 [ V_222 ] ) {
V_30 V_204 = F_107 ( V_169 [ V_222 ] ) ;
V_23 -> V_223 = F_108 ( V_204 ) ;
}
if ( V_169 [ V_224 ] ) {
V_30 V_204 = F_107 ( V_169 [ V_224 ] ) ;
V_23 -> V_225 = F_108 ( V_204 ) ;
}
if ( V_169 [ V_226 ] ) {
V_30 V_204 = F_107 ( V_169 [ V_226 ] ) ;
V_23 -> V_227 = F_108 ( V_204 ) ;
}
if ( V_169 [ V_228 ] ) {
T_6 V_229 ;
V_229 = F_66 ( V_169 [ V_228 ] ) ;
V_23 -> V_230 = ! ! V_229 ;
}
if ( V_169 [ V_231 ] ) {
T_6 V_232 ;
V_232 = F_66 ( V_169 [ V_231 ] ) ;
V_95 = F_109 ( V_23 , V_232 ) ;
if ( V_95 )
return V_95 ;
}
#if F_110 ( V_233 )
if ( V_169 [ V_234 ] ) {
T_6 V_235 ;
V_235 = F_66 ( V_169 [ V_234 ] ) ;
V_95 = F_111 ( V_23 , V_235 ) ;
if ( V_95 )
return V_95 ;
}
#endif
#endif
#if F_110 ( V_236 )
if ( V_169 [ V_237 ] ) {
V_29 V_204 = F_66 ( V_169 [ V_237 ] ) ;
V_23 -> V_238 = V_204 ? true : false ;
}
if ( V_169 [ V_239 ] ) {
V_29 V_204 = F_66 ( V_169 [ V_239 ] ) ;
V_23 -> V_240 = V_204 ? true : false ;
}
if ( V_169 [ V_241 ] ) {
V_29 V_204 = F_66 ( V_169 [ V_241 ] ) ;
V_23 -> V_242 = V_204 ? true : false ;
}
#endif
return 0 ;
}
static int F_112 ( struct V_131 * V_243 , struct V_18 * V_19 ,
struct V_124 * V_156 [] , struct V_124 * V_169 [] )
{
struct V_22 * V_23 = F_12 ( V_19 ) ;
int V_95 ;
if ( V_156 [ V_120 ] ) {
F_78 ( & V_23 -> V_167 ) ;
F_113 ( V_23 , F_60 ( V_156 [ V_120 ] ) ) ;
F_79 ( & V_23 -> V_167 ) ;
}
V_95 = F_89 ( V_19 , V_156 , V_169 ) ;
if ( V_95 )
return V_95 ;
return F_114 ( V_19 ) ;
}
static T_3 F_115 ( const struct V_18 * V_176 )
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
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
#endif
#if F_110 ( V_236 )
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
F_14 ( sizeof( V_29 ) ) +
#endif
0 ;
}
static int F_116 ( struct V_34 * V_35 , const struct V_18 * V_176 )
{
struct V_22 * V_23 = F_12 ( V_176 ) ;
T_1 V_244 = F_117 ( V_23 -> V_244 ) ;
T_1 V_245 = F_117 ( V_23 -> V_245 ) ;
T_1 V_246 = F_117 ( V_23 -> V_247 ) ;
T_1 V_248 = F_117 ( V_23 -> V_248 ) ;
T_1 V_151 = V_23 -> V_151 ;
T_2 V_42 = ( V_23 -> V_249 . V_250 [ 0 ] << 8 ) | V_23 -> V_249 . V_250 [ 1 ] ;
V_29 V_251 = F_118 ( V_23 ) ;
V_30 V_252 ;
V_252 = F_25 ( & V_23 -> V_253 ) ;
if ( F_26 ( V_35 , V_254 , V_252 , V_255 ) )
return - V_78 ;
V_252 = F_25 ( & V_23 -> V_256 ) ;
if ( F_26 ( V_35 , V_257 , V_252 , V_255 ) )
return - V_78 ;
V_252 = F_25 ( & V_23 -> V_258 ) ;
if ( F_26 ( V_35 , V_259 , V_252 ,
V_255 ) )
return - V_78 ;
V_252 = F_25 ( & V_23 -> V_260 ) ;
if ( F_26 ( V_35 , V_261 , V_252 , V_255 ) )
return - V_78 ;
if ( F_23 ( V_35 , V_178 , V_244 ) ||
F_23 ( V_35 , V_179 , V_245 ) ||
F_23 ( V_35 , V_180 , V_246 ) ||
F_23 ( V_35 , V_181 , V_248 ) ||
F_23 ( V_35 , V_182 , V_151 ) ||
F_22 ( V_35 , V_183 , V_42 ) ||
F_21 ( V_35 , V_184 , V_251 ) ||
F_22 ( V_35 , V_191 , V_23 -> V_194 ) ||
F_24 ( V_35 , V_262 , sizeof( struct V_28 ) ,
& V_23 -> V_249 ) ||
F_24 ( V_35 , V_263 , sizeof( struct V_28 ) ,
& V_23 -> V_63 ) ||
F_22 ( V_35 , V_264 , V_23 -> V_265 ) ||
F_23 ( V_35 , V_266 , V_23 -> V_267 ) ||
F_21 ( V_35 , V_268 , V_23 -> V_269 ) ||
F_21 ( V_35 , V_270 ,
V_23 -> V_271 ) ||
F_24 ( V_35 , V_195 , V_170 , V_23 -> V_197 ) )
return - V_78 ;
#ifdef F_83
if ( F_119 ( V_35 , V_172 , V_23 -> V_186 ) ||
F_22 ( V_35 , V_187 , V_23 -> V_272 ) ||
F_21 ( V_35 , V_189 , V_23 -> V_273 ) )
return - V_78 ;
#endif
#ifdef F_17
if ( F_21 ( V_35 , V_200 , V_23 -> V_87 ) ||
F_21 ( V_35 , V_201 , ! V_23 -> V_274 ) ||
F_21 ( V_35 , V_203 ,
V_23 -> V_205 ) ||
F_21 ( V_35 , V_206 , V_23 -> V_275 ) ||
F_21 ( V_35 , V_228 ,
V_23 -> V_230 ) ||
F_23 ( V_35 , V_208 ,
V_23 -> V_209 ) ||
F_23 ( V_35 , V_210 , V_23 -> V_211 ) ||
F_23 ( V_35 , V_212 ,
V_23 -> V_213 ) ||
F_23 ( V_35 , V_214 ,
V_23 -> V_215 ) ||
F_21 ( V_35 , V_231 ,
V_23 -> V_276 ) )
return - V_78 ;
#if F_110 ( V_233 )
if ( F_21 ( V_35 , V_234 ,
V_23 -> V_277 ) )
return - V_78 ;
#endif
V_252 = F_117 ( V_23 -> V_217 ) ;
if ( F_26 ( V_35 , V_216 , V_252 ,
V_255 ) )
return - V_78 ;
V_252 = F_117 ( V_23 -> V_219 ) ;
if ( F_26 ( V_35 , V_218 , V_252 ,
V_255 ) )
return - V_78 ;
V_252 = F_117 ( V_23 -> V_221 ) ;
if ( F_26 ( V_35 , V_220 , V_252 ,
V_255 ) )
return - V_78 ;
V_252 = F_117 ( V_23 -> V_223 ) ;
if ( F_26 ( V_35 , V_222 , V_252 ,
V_255 ) )
return - V_78 ;
V_252 = F_117 ( V_23 -> V_225 ) ;
if ( F_26 ( V_35 , V_224 , V_252 ,
V_255 ) )
return - V_78 ;
V_252 = F_117 ( V_23 -> V_227 ) ;
if ( F_26 ( V_35 , V_226 , V_252 ,
V_255 ) )
return - V_78 ;
#endif
#if F_110 ( V_236 )
if ( F_21 ( V_35 , V_237 ,
V_23 -> V_238 ? 1 : 0 ) ||
F_21 ( V_35 , V_239 ,
V_23 -> V_240 ? 1 : 0 ) ||
F_21 ( V_35 , V_241 ,
V_23 -> V_242 ? 1 : 0 ) )
return - V_78 ;
#endif
return 0 ;
}
static T_3 F_120 ( const struct V_18 * V_19 , int V_145 )
{
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
int V_278 = 0 ;
switch ( V_145 ) {
case V_279 :
V_23 = F_12 ( V_19 ) ;
V_2 = F_121 ( V_23 ) ;
break;
case V_280 :
V_21 = F_50 ( V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = V_21 -> V_23 ;
V_2 = F_122 ( V_21 ) ;
break;
default:
return 0 ;
}
if ( V_2 ) {
F_123 (v, &vg->vlan_list, vlist)
V_278 ++ ;
}
return V_278 * F_14 ( sizeof( struct V_281 ) ) +
F_14 ( sizeof( struct V_282 ) ) +
F_14 ( 0 ) ;
}
static int F_124 ( struct V_34 * V_35 ,
const struct V_18 * V_19 ,
int * V_283 , int V_145 )
{
struct V_124 * T_7 V_284 ;
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
struct V_124 * V_125 ;
int V_285 = 0 ;
switch ( V_145 ) {
case V_279 :
V_23 = F_12 ( V_19 ) ;
V_2 = F_121 ( V_23 ) ;
break;
case V_280 :
V_21 = F_50 ( V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = V_21 -> V_23 ;
V_2 = F_122 ( V_21 ) ;
break;
default:
return - V_147 ;
}
V_125 = F_38 ( V_35 , V_286 ) ;
if ( ! V_125 )
return - V_78 ;
if ( V_2 ) {
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_123 (v, &vg->vlan_list, vlist) {
struct V_281 V_287 ;
struct V_288 V_289 ;
if ( ++ V_285 < * V_283 )
continue;
memset ( & V_287 , 0 , sizeof( V_287 ) ) ;
V_287 . V_13 = V_5 -> V_13 ;
V_287 . V_9 = V_5 -> V_9 ;
if ( V_5 -> V_13 == V_10 )
V_287 . V_9 |= V_14 ;
F_125 ( V_5 , & V_289 ) ;
V_287 . V_290 = V_289 . V_290 ;
V_287 . V_291 = V_289 . V_291 ;
V_287 . V_292 = V_289 . V_292 ;
V_287 . V_293 = V_289 . V_293 ;
if ( F_24 ( V_35 , V_294 , sizeof( V_287 ) , & V_287 ) )
goto V_93;
}
}
#ifdef F_17
if ( ++ V_285 >= * V_283 ) {
T_7 = F_126 ( V_35 , V_295 ,
sizeof( struct V_282 ) ,
V_296 ) ;
if ( ! T_7 )
goto V_93;
F_127 ( V_23 , V_21 , F_60 ( T_7 ) ) ;
}
#endif
F_39 ( V_35 , V_125 ) ;
* V_283 = 0 ;
return 0 ;
V_93:
F_39 ( V_35 , V_125 ) ;
* V_283 = V_285 ;
return - V_78 ;
}
int T_8 F_128 ( void )
{
int V_95 ;
F_129 () ;
F_130 ( & V_297 ) ;
V_95 = F_131 ( & V_298 ) ;
if ( V_95 )
goto V_299;
return 0 ;
V_299:
F_132 ( & V_297 ) ;
F_133 () ;
return V_95 ;
}
void F_134 ( void )
{
F_133 () ;
F_132 ( & V_297 ) ;
F_135 ( & V_298 ) ;
}
