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
struct V_20 * V_21 = NULL ;
struct V_22 * V_23 ;
int V_24 ;
T_3 V_25 = 0 ;
F_6 () ;
if ( F_9 ( V_19 ) ) {
V_21 = F_10 ( V_19 ) ;
V_2 = F_11 ( V_21 ) ;
} else if ( V_19 -> V_26 & V_27 ) {
V_23 = F_12 ( V_19 ) ;
V_2 = F_13 ( V_23 ) ;
}
V_24 = F_5 ( V_2 , V_3 ) ;
F_7 () ;
if ( V_21 && ( V_21 -> V_9 & V_28 ) )
V_25 += F_14 ( V_2 ) ;
V_25 += V_24 * F_15 ( sizeof( struct V_29 ) ) ;
return V_25 ;
}
static inline T_3 F_16 ( void )
{
return F_15 ( 1 )
+ F_15 ( 2 )
+ F_15 ( 4 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( 1 )
+ F_15 ( sizeof( struct V_30 ) )
+ F_15 ( sizeof( struct V_30 ) )
+ F_15 ( sizeof( T_2 ) )
+ F_15 ( sizeof( T_2 ) )
+ F_15 ( sizeof( T_2 ) )
+ F_15 ( sizeof( T_2 ) )
+ F_15 ( sizeof( V_31 ) )
+ F_15 ( sizeof( V_31 ) )
+ F_17 ( sizeof( V_32 ) )
+ F_17 ( sizeof( V_32 ) )
+ F_17 ( sizeof( V_32 ) )
#ifdef F_18
+ F_15 ( sizeof( V_31 ) )
#endif
+ 0 ;
}
static inline T_3 F_19 ( struct V_18 * V_19 , T_1 V_3 )
{
return F_20 ( sizeof( struct V_33 ) )
+ F_15 ( V_34 )
+ F_15 ( V_35 )
+ F_15 ( 4 )
+ F_15 ( 4 )
+ F_15 ( 4 )
+ F_15 ( 1 )
+ F_15 ( F_16 () )
+ F_15 ( F_8 ( V_19 ,
V_3 ) ) ;
}
static int F_21 ( struct V_36 * V_37 ,
const struct V_20 * V_21 )
{
V_31 V_38 = ! ! ( V_21 -> V_9 & V_39 ) ;
V_32 V_40 ;
if ( F_22 ( V_37 , V_41 , V_21 -> V_42 ) ||
F_23 ( V_37 , V_43 , V_21 -> V_44 ) ||
F_24 ( V_37 , V_45 , V_21 -> V_46 ) ||
F_22 ( V_37 , V_47 , V_38 ) ||
F_22 ( V_37 , V_48 , ! ! ( V_21 -> V_9 & V_49 ) ) ||
F_22 ( V_37 , V_50 ,
! ! ( V_21 -> V_9 & V_51 ) ) ||
F_22 ( V_37 , V_52 ,
! ! ( V_21 -> V_9 & V_53 ) ) ||
F_22 ( V_37 , V_54 ,
! ! ( V_21 -> V_9 & V_55 ) ) ||
F_22 ( V_37 , V_56 , ! ! ( V_21 -> V_9 & V_57 ) ) ||
F_22 ( V_37 , V_58 ,
! ! ( V_21 -> V_9 & V_59 ) ) ||
F_22 ( V_37 , V_60 ,
! ! ( V_21 -> V_9 & V_61 ) ) ||
F_22 ( V_37 , V_62 , ! ! ( V_21 -> V_9 & V_63 ) ) ||
F_22 ( V_37 , V_64 ,
! ! ( V_21 -> V_9 & V_65 ) ) ||
F_25 ( V_37 , V_66 , sizeof( struct V_30 ) ,
& V_21 -> V_67 ) ||
F_25 ( V_37 , V_68 , sizeof( struct V_30 ) ,
& V_21 -> V_69 ) ||
F_23 ( V_37 , V_70 , V_21 -> V_71 ) ||
F_23 ( V_37 , V_72 , V_21 -> V_73 ) ||
F_23 ( V_37 , V_74 , V_21 -> V_75 ) ||
F_23 ( V_37 , V_76 , V_21 -> V_77 ) ||
F_22 ( V_37 , V_78 ,
V_21 -> V_79 ) ||
F_22 ( V_37 , V_80 , V_21 -> V_81 ) ||
F_22 ( V_37 , V_82 , ! ! ( V_21 -> V_9 &
V_28 ) ) )
return - V_83 ;
V_40 = F_26 ( & V_21 -> V_84 ) ;
if ( F_27 ( V_37 , V_85 , V_40 ,
V_86 ) )
return - V_83 ;
V_40 = F_26 ( & V_21 -> V_87 ) ;
if ( F_27 ( V_37 , V_88 , V_40 ,
V_86 ) )
return - V_83 ;
V_40 = F_26 ( & V_21 -> V_89 ) ;
if ( F_27 ( V_37 , V_90 , V_40 ,
V_86 ) )
return - V_83 ;
#ifdef F_18
if ( F_22 ( V_37 , V_91 ,
V_21 -> V_92 ) )
return - V_83 ;
#endif
return 0 ;
}
static int F_28 ( struct V_36 * V_37 , T_2 V_93 ,
T_2 V_94 , T_2 V_9 )
{
struct V_29 V_95 ;
if ( ( V_94 - V_93 ) > 0 ) {
V_95 . V_13 = V_93 ;
V_95 . V_9 = V_9 | V_96 ;
if ( F_25 ( V_37 , V_97 ,
sizeof( V_95 ) , & V_95 ) )
goto V_98;
V_95 . V_13 = V_94 ;
V_95 . V_9 = V_9 | V_99 ;
if ( F_25 ( V_37 , V_97 ,
sizeof( V_95 ) , & V_95 ) )
goto V_98;
} else {
V_95 . V_13 = V_93 ;
V_95 . V_9 = V_9 ;
if ( F_25 ( V_37 , V_97 ,
sizeof( V_95 ) , & V_95 ) )
goto V_98;
}
return 0 ;
V_98:
return - V_83 ;
}
static int F_29 ( struct V_36 * V_37 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_6 = 0 , V_7 = 0 , V_8 = 0 ;
T_2 V_9 , V_10 ;
int V_100 = 0 ;
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
V_100 = F_28 ( V_37 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_100 )
return V_100 ;
}
V_16:
V_6 = V_5 -> V_13 ;
V_7 = V_5 -> V_13 ;
V_8 = V_9 ;
}
if ( V_6 != 0 ) {
V_100 = F_28 ( V_37 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_100 )
return V_100 ;
}
return 0 ;
}
static int F_30 ( struct V_36 * V_37 ,
struct V_1 * V_2 )
{
struct V_29 V_95 ;
struct V_4 * V_5 ;
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_3 (v, &vg->vlan_list, vlist) {
if ( ! F_4 ( V_5 ) )
continue;
V_95 . V_13 = V_5 -> V_13 ;
V_95 . V_9 = 0 ;
if ( V_5 -> V_13 == V_10 )
V_95 . V_9 |= V_14 ;
if ( V_5 -> V_9 & V_15 )
V_95 . V_9 |= V_15 ;
if ( F_25 ( V_37 , V_97 ,
sizeof( V_95 ) , & V_95 ) )
goto V_98;
}
return 0 ;
V_98:
return - V_83 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_20 * V_101 ,
T_1 V_102 , T_1 V_103 , int V_104 , unsigned int V_9 ,
T_1 V_3 , const struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_33 * V_105 ;
struct V_106 * V_107 ;
V_31 V_108 = F_32 ( V_19 ) ? V_19 -> V_108 : V_109 ;
if ( V_101 )
V_23 = V_101 -> V_23 ;
else
V_23 = F_12 ( V_19 ) ;
F_33 ( V_23 , L_1 ,
V_104 , V_19 -> V_110 , V_23 -> V_19 -> V_110 ) ;
V_107 = F_34 ( V_37 , V_102 , V_103 , V_104 , sizeof( * V_105 ) , V_9 ) ;
if ( V_107 == NULL )
return - V_83 ;
V_105 = F_35 ( V_107 ) ;
V_105 -> V_111 = V_112 ;
V_105 -> V_113 = 0 ;
V_105 -> V_114 = V_19 -> type ;
V_105 -> V_115 = V_19 -> V_116 ;
V_105 -> V_117 = F_36 ( V_19 ) ;
V_105 -> V_118 = 0 ;
if ( F_37 ( V_37 , V_119 , V_19 -> V_110 ) ||
F_24 ( V_37 , V_120 , V_23 -> V_19 -> V_116 ) ||
F_24 ( V_37 , V_121 , V_19 -> V_122 ) ||
F_22 ( V_37 , V_123 , V_108 ) ||
( V_19 -> V_124 &&
F_25 ( V_37 , V_125 , V_19 -> V_124 , V_19 -> V_126 ) ) ||
( V_19 -> V_116 != F_38 ( V_19 ) &&
F_24 ( V_37 , V_127 , F_38 ( V_19 ) ) ) )
goto V_98;
if ( V_104 == V_128 && V_101 ) {
struct V_129 * V_130
= F_39 ( V_37 , V_131 | V_132 ) ;
if ( V_130 == NULL || F_21 ( V_37 , V_101 ) < 0 )
goto V_98;
F_40 ( V_37 , V_130 ) ;
}
if ( ( V_3 & V_17 ) ||
( V_3 & V_12 ) ) {
struct V_1 * V_2 ;
struct V_129 * V_133 ;
int V_100 ;
F_6 () ;
if ( V_101 )
V_2 = F_11 ( V_101 ) ;
else
V_2 = F_13 ( V_23 ) ;
if ( ! V_2 || ! V_2 -> V_11 ) {
F_7 () ;
goto V_134;
}
V_133 = F_39 ( V_37 , V_135 ) ;
if ( ! V_133 ) {
F_7 () ;
goto V_98;
}
if ( V_3 & V_12 )
V_100 = F_29 ( V_37 , V_2 ) ;
else
V_100 = F_30 ( V_37 , V_2 ) ;
if ( V_101 && ( V_101 -> V_9 & V_28 ) )
V_100 = F_41 ( V_37 , V_2 ) ;
F_7 () ;
if ( V_100 )
goto V_98;
F_40 ( V_37 , V_133 ) ;
}
V_134:
F_42 ( V_37 , V_107 ) ;
return 0 ;
V_98:
F_43 ( V_37 , V_107 ) ;
return - V_83 ;
}
void F_44 ( int V_104 , struct V_20 * V_101 )
{
struct V_136 * V_136 ;
struct V_36 * V_37 ;
int V_100 = - V_137 ;
T_1 V_138 = V_12 ;
if ( ! V_101 )
return;
V_136 = F_45 ( V_101 -> V_19 ) ;
F_33 ( V_101 -> V_23 , L_2 ,
( unsigned int ) V_101 -> V_77 , V_101 -> V_19 -> V_110 , V_104 ) ;
V_37 = F_46 ( F_19 ( V_101 -> V_19 , V_138 ) , V_139 ) ;
if ( V_37 == NULL )
goto V_140;
V_100 = F_31 ( V_37 , V_101 , 0 , 0 , V_104 , 0 , V_138 , V_101 -> V_19 ) ;
if ( V_100 < 0 ) {
F_47 ( V_100 == - V_83 ) ;
F_48 ( V_37 ) ;
goto V_140;
}
F_49 ( V_37 , V_136 , 0 , V_141 , NULL , V_139 ) ;
return;
V_140:
F_50 ( V_136 , V_141 , V_100 ) ;
}
int F_51 ( struct V_36 * V_37 , T_1 V_102 , T_1 V_103 ,
struct V_18 * V_19 , T_1 V_3 , int V_142 )
{
struct V_20 * V_101 = F_52 ( V_19 ) ;
if ( ! V_101 && ! ( V_3 & V_17 ) &&
! ( V_3 & V_12 ) )
return 0 ;
return F_31 ( V_37 , V_101 , V_102 , V_103 , V_128 , V_142 ,
V_3 , V_19 ) ;
}
static int F_53 ( struct V_22 * V_23 , struct V_20 * V_21 ,
int V_143 , struct V_29 * V_95 )
{
int V_100 = 0 ;
switch ( V_143 ) {
case V_144 :
if ( V_21 ) {
V_100 = F_54 ( V_21 , V_95 -> V_13 , V_95 -> V_9 ) ;
if ( V_100 )
break;
} else {
V_95 -> V_9 |= V_145 ;
V_100 = F_55 ( V_23 , V_95 -> V_13 , V_95 -> V_9 ) ;
}
break;
case V_146 :
if ( V_21 ) {
F_56 ( V_21 , V_95 -> V_13 ) ;
if ( V_95 -> V_9 & V_147 )
F_57 ( V_21 -> V_23 , V_95 -> V_13 ) ;
} else {
F_57 ( V_23 , V_95 -> V_13 ) ;
}
break;
}
return V_100 ;
}
static int F_58 ( struct V_22 * V_23 ,
struct V_20 * V_21 , int V_143 ,
struct V_29 * V_148 ,
struct V_29 * * V_149 )
{
if ( ! V_148 -> V_13 || V_148 -> V_13 >= V_150 )
return - V_151 ;
if ( V_148 -> V_9 & V_96 ) {
if ( * V_149 )
return - V_151 ;
* V_149 = V_148 ;
if ( ( * V_149 ) -> V_9 & V_14 )
return - V_151 ;
return 0 ;
}
if ( * V_149 ) {
struct V_29 V_152 ;
int V_5 , V_100 ;
if ( ! ( V_148 -> V_9 & V_99 ) )
return - V_151 ;
if ( V_148 -> V_13 <= ( * V_149 ) -> V_13 )
return - V_151 ;
memcpy ( & V_152 , * V_149 ,
sizeof( struct V_29 ) ) ;
for ( V_5 = ( * V_149 ) -> V_13 ; V_5 <= V_148 -> V_13 ; V_5 ++ ) {
V_152 . V_13 = V_5 ;
V_100 = F_53 ( V_23 , V_21 , V_143 , & V_152 ) ;
if ( V_100 )
break;
}
* V_149 = NULL ;
return 0 ;
}
return F_53 ( V_23 , V_21 , V_143 , V_148 ) ;
}
static int F_59 ( struct V_22 * V_23 ,
struct V_20 * V_21 ,
struct V_129 * V_153 ,
int V_143 )
{
struct V_29 * V_148 = NULL ;
struct V_29 * V_149 = NULL ;
struct V_129 * V_154 ;
struct V_155 V_156 = {} ;
struct V_155 V_157 = {} ;
int V_100 = 0 , V_158 ;
F_60 (attr, af_spec, rem) {
V_100 = 0 ;
switch ( F_61 ( V_154 ) ) {
case V_159 :
if ( ! ( V_21 -> V_9 & V_28 ) )
return - V_151 ;
V_100 = F_62 ( V_154 , & V_157 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_63 ( V_23 , V_21 , V_143 ,
& V_157 ,
& V_156 ) ;
if ( V_100 )
return V_100 ;
break;
case V_97 :
if ( F_64 ( V_154 ) != sizeof( struct V_29 ) )
return - V_151 ;
V_148 = F_65 ( V_154 ) ;
V_100 = F_58 ( V_23 , V_21 , V_143 , V_148 ,
& V_149 ) ;
if ( V_100 )
return V_100 ;
break;
}
}
return V_100 ;
}
static int F_66 ( struct V_20 * V_21 , V_31 V_42 )
{
if ( V_42 > V_160 )
return - V_151 ;
if ( V_21 -> V_23 -> V_161 == V_162 )
return - V_163 ;
if ( ! F_32 ( V_21 -> V_19 ) ||
( ! F_67 ( V_21 -> V_19 ) && V_42 != V_164 ) )
return - V_165 ;
F_68 ( V_21 , V_42 ) ;
F_69 ( V_21 -> V_23 ) ;
return 0 ;
}
static void F_70 ( struct V_20 * V_21 , struct V_129 * V_166 [] ,
int V_167 , unsigned long V_168 )
{
if ( V_166 [ V_167 ] ) {
V_31 V_169 = F_71 ( V_166 [ V_167 ] ) ;
if ( V_169 )
V_21 -> V_9 |= V_168 ;
else
V_21 -> V_9 &= ~ V_168 ;
}
}
static int F_72 ( struct V_20 * V_21 , struct V_129 * V_166 [] )
{
unsigned long V_170 = V_21 -> V_9 ;
bool V_171 = false ;
int V_100 ;
F_70 ( V_21 , V_166 , V_47 , V_39 ) ;
F_70 ( V_21 , V_166 , V_48 , V_49 ) ;
F_70 ( V_21 , V_166 , V_52 , V_53 ) ;
F_70 ( V_21 , V_166 , V_50 , V_51 ) ;
F_70 ( V_21 , V_166 , V_56 , V_57 ) ;
F_70 ( V_21 , V_166 , V_58 , V_59 ) ;
F_70 ( V_21 , V_166 , V_60 , V_61 ) ;
F_70 ( V_21 , V_166 , V_54 , V_55 ) ;
F_70 ( V_21 , V_166 , V_62 , V_63 ) ;
F_70 ( V_21 , V_166 , V_64 , V_65 ) ;
V_171 = ( V_21 -> V_9 & V_28 ) ? true : false ;
F_70 ( V_21 , V_166 , V_82 , V_28 ) ;
if ( V_171 && ! ( V_21 -> V_9 & V_28 ) )
F_73 ( V_21 ) ;
if ( V_166 [ V_45 ] ) {
V_100 = F_74 ( V_21 , F_75 ( V_166 [ V_45 ] ) ) ;
if ( V_100 )
return V_100 ;
}
if ( V_166 [ V_43 ] ) {
V_100 = F_76 ( V_21 , F_77 ( V_166 [ V_43 ] ) ) ;
if ( V_100 )
return V_100 ;
}
if ( V_166 [ V_41 ] ) {
V_100 = F_66 ( V_21 , F_71 ( V_166 [ V_41 ] ) ) ;
if ( V_100 )
return V_100 ;
}
if ( V_166 [ V_172 ] )
F_78 ( V_21 -> V_23 , V_21 , 0 , 0 ) ;
#ifdef F_18
if ( V_166 [ V_91 ] ) {
V_31 V_173 = F_71 ( V_166 [ V_91 ] ) ;
V_100 = F_79 ( V_21 , V_173 ) ;
if ( V_100 )
return V_100 ;
}
#endif
F_80 ( V_21 , V_170 ^ V_21 -> V_9 ) ;
return 0 ;
}
int F_81 ( struct V_18 * V_19 , struct V_106 * V_107 , T_2 V_9 )
{
struct V_129 * V_174 ;
struct V_129 * V_175 ;
struct V_20 * V_21 ;
struct V_129 * V_166 [ V_176 + 1 ] ;
int V_100 = 0 ;
V_174 = F_82 ( V_107 , sizeof( struct V_33 ) , V_131 ) ;
V_175 = F_82 ( V_107 , sizeof( struct V_33 ) , V_135 ) ;
if ( ! V_174 && ! V_175 )
return 0 ;
V_21 = F_52 ( V_19 ) ;
if ( ! V_21 && ! V_175 )
return - V_151 ;
if ( V_21 && V_174 ) {
if ( V_174 -> F_61 & V_132 ) {
V_100 = F_83 ( V_166 , V_176 ,
V_174 , V_177 ) ;
if ( V_100 )
return V_100 ;
F_84 ( & V_21 -> V_23 -> V_178 ) ;
V_100 = F_72 ( V_21 , V_166 ) ;
F_85 ( & V_21 -> V_23 -> V_178 ) ;
} else {
if ( F_64 ( V_174 ) < sizeof( V_31 ) )
return - V_151 ;
F_84 ( & V_21 -> V_23 -> V_178 ) ;
V_100 = F_66 ( V_21 , F_71 ( V_174 ) ) ;
F_85 ( & V_21 -> V_23 -> V_178 ) ;
}
if ( V_100 )
goto V_179;
}
if ( V_175 ) {
V_100 = F_59 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_175 , V_144 ) ;
}
if ( V_100 == 0 )
F_44 ( V_128 , V_21 ) ;
V_179:
return V_100 ;
}
int F_86 ( struct V_18 * V_19 , struct V_106 * V_107 , T_2 V_9 )
{
struct V_129 * V_175 ;
struct V_20 * V_21 ;
int V_100 = 0 ;
V_175 = F_82 ( V_107 , sizeof( struct V_33 ) , V_135 ) ;
if ( ! V_175 )
return 0 ;
V_21 = F_52 ( V_19 ) ;
if ( ! V_21 && ! ( V_19 -> V_26 & V_27 ) )
return - V_151 ;
V_100 = F_59 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_175 , V_146 ) ;
if ( V_100 == 0 )
F_44 ( V_128 , V_21 ) ;
return V_100 ;
}
static int F_87 ( struct V_129 * V_166 [] , struct V_129 * V_180 [] )
{
if ( V_166 [ V_125 ] ) {
if ( F_64 ( V_166 [ V_125 ] ) != V_181 )
return - V_151 ;
if ( ! F_88 ( F_65 ( V_166 [ V_125 ] ) ) )
return - V_182 ;
}
if ( ! V_180 )
return 0 ;
#ifdef F_89
if ( V_180 [ V_183 ] ) {
switch ( F_90 ( V_180 [ V_183 ] ) ) {
case F_91 ( V_184 ) :
case F_91 ( V_185 ) :
break;
default:
return - V_186 ;
}
}
#endif
return 0 ;
}
static int F_92 ( struct V_18 * V_187 ,
struct V_18 * V_19 ,
struct V_129 * V_166 [] ,
struct V_129 * V_180 [] )
{
struct V_22 * V_23 = F_12 ( V_187 ) ;
int V_188 ;
if ( ! V_180 )
return 0 ;
F_84 ( & V_23 -> V_178 ) ;
V_188 = F_72 ( F_52 ( V_19 ) , V_180 ) ;
F_85 ( & V_23 -> V_178 ) ;
return V_188 ;
}
static int F_93 ( struct V_36 * V_37 ,
const struct V_18 * V_187 ,
const struct V_18 * V_19 )
{
return F_21 ( V_37 , F_52 ( V_19 ) ) ;
}
static T_3 F_94 ( const struct V_18 * V_187 ,
const struct V_18 * V_19 )
{
return F_16 () ;
}
static int F_95 ( struct V_18 * V_187 , struct V_129 * V_166 [] ,
struct V_129 * V_180 [] )
{
struct V_22 * V_23 = F_12 ( V_187 ) ;
int V_100 ;
if ( ! V_180 )
return 0 ;
if ( V_180 [ V_189 ] ) {
V_100 = F_96 ( V_23 , F_75 ( V_180 [ V_189 ] ) ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_190 ] ) {
V_100 = F_97 ( V_23 , F_75 ( V_180 [ V_190 ] ) ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_191 ] ) {
V_100 = F_98 ( V_23 , F_75 ( V_180 [ V_191 ] ) ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_192 ] ) {
V_100 = F_99 ( V_23 , F_75 ( V_180 [ V_192 ] ) ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_193 ] ) {
T_1 V_161 = F_75 ( V_180 [ V_193 ] ) ;
F_100 ( V_23 , V_161 ) ;
}
if ( V_180 [ V_194 ] ) {
T_1 V_44 = F_77 ( V_180 [ V_194 ] ) ;
F_101 ( V_23 , V_44 ) ;
}
if ( V_180 [ V_195 ] ) {
V_31 V_196 = F_71 ( V_180 [ V_195 ] ) ;
V_100 = F_102 ( V_23 , V_196 ) ;
if ( V_100 )
return V_100 ;
}
#ifdef F_89
if ( V_180 [ V_183 ] ) {
T_4 V_197 = F_90 ( V_180 [ V_183 ] ) ;
V_100 = F_103 ( V_23 , V_197 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_198 ] ) {
T_5 V_199 = F_77 ( V_180 [ V_198 ] ) ;
V_100 = F_104 ( V_23 , V_199 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_200 ] ) {
T_6 V_201 = F_71 ( V_180 [ V_200 ] ) ;
V_100 = F_105 ( V_23 , V_201 ) ;
if ( V_100 )
return V_100 ;
}
#endif
if ( V_180 [ V_202 ] ) {
T_2 V_203 = F_77 ( V_180 [ V_202 ] ) ;
if ( V_203 & V_204 )
return - V_151 ;
V_23 -> V_205 = V_203 ;
}
if ( V_180 [ V_206 ] ) {
V_31 V_207 [ V_181 ] ;
if ( F_64 ( V_180 [ V_206 ] ) != V_181 )
return - V_151 ;
memcpy ( V_207 , F_65 ( V_180 [ V_206 ] ) , V_181 ) ;
if ( ! F_106 ( V_207 ) )
return - V_151 ;
if ( V_207 [ 5 ] == 1 ||
V_207 [ 5 ] == 2 ||
V_207 [ 5 ] == 3 )
return - V_151 ;
F_84 ( & V_23 -> V_178 ) ;
memcpy ( V_23 -> V_208 , V_207 , sizeof( V_23 -> V_208 ) ) ;
F_85 ( & V_23 -> V_178 ) ;
V_23 -> V_209 = true ;
F_107 ( V_23 ) ;
}
if ( V_180 [ V_210 ] )
F_108 ( V_23 ) ;
#ifdef F_18
if ( V_180 [ V_211 ] ) {
V_31 V_92 = F_71 ( V_180 [ V_211 ] ) ;
V_100 = F_109 ( V_23 , V_92 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_212 ] ) {
V_31 V_213 = F_71 ( V_180 [ V_212 ] ) ;
V_100 = F_110 ( V_23 , V_213 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_214 ] ) {
V_31 V_215 ;
V_215 = F_71 ( V_180 [ V_214 ] ) ;
V_23 -> V_216 = ! ! V_215 ;
}
if ( V_180 [ V_217 ] ) {
V_31 V_218 = F_71 ( V_180 [ V_217 ] ) ;
V_100 = F_111 ( V_23 , V_218 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_219 ] ) {
T_1 V_215 = F_75 ( V_180 [ V_219 ] ) ;
V_23 -> V_220 = V_215 ;
}
if ( V_180 [ V_221 ] ) {
T_1 V_222 = F_75 ( V_180 [ V_221 ] ) ;
V_100 = F_112 ( V_23 , V_222 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_180 [ V_223 ] ) {
T_1 V_215 = F_75 ( V_180 [ V_223 ] ) ;
V_23 -> V_224 = V_215 ;
}
if ( V_180 [ V_225 ] ) {
T_1 V_215 = F_75 ( V_180 [ V_225 ] ) ;
V_23 -> V_226 = V_215 ;
}
if ( V_180 [ V_227 ] ) {
V_32 V_215 = F_113 ( V_180 [ V_227 ] ) ;
V_23 -> V_228 = F_114 ( V_215 ) ;
}
if ( V_180 [ V_229 ] ) {
V_32 V_215 = F_113 ( V_180 [ V_229 ] ) ;
V_23 -> V_230 = F_114 ( V_215 ) ;
}
if ( V_180 [ V_231 ] ) {
V_32 V_215 = F_113 ( V_180 [ V_231 ] ) ;
V_23 -> V_232 = F_114 ( V_215 ) ;
}
if ( V_180 [ V_233 ] ) {
V_32 V_215 = F_113 ( V_180 [ V_233 ] ) ;
V_23 -> V_234 = F_114 ( V_215 ) ;
}
if ( V_180 [ V_235 ] ) {
V_32 V_215 = F_113 ( V_180 [ V_235 ] ) ;
V_23 -> V_236 = F_114 ( V_215 ) ;
}
if ( V_180 [ V_237 ] ) {
V_32 V_215 = F_113 ( V_180 [ V_237 ] ) ;
V_23 -> V_238 = F_114 ( V_215 ) ;
}
if ( V_180 [ V_239 ] ) {
T_6 V_240 ;
V_240 = F_71 ( V_180 [ V_239 ] ) ;
V_23 -> V_241 = ! ! V_240 ;
}
if ( V_180 [ V_242 ] ) {
T_6 V_243 ;
V_243 = F_71 ( V_180 [ V_242 ] ) ;
V_100 = F_115 ( V_23 , V_243 ) ;
if ( V_100 )
return V_100 ;
}
#if F_116 ( V_244 )
if ( V_180 [ V_245 ] ) {
T_6 V_246 ;
V_246 = F_71 ( V_180 [ V_245 ] ) ;
V_100 = F_117 ( V_23 , V_246 ) ;
if ( V_100 )
return V_100 ;
}
#endif
#endif
#if F_116 ( V_247 )
if ( V_180 [ V_248 ] ) {
V_31 V_215 = F_71 ( V_180 [ V_248 ] ) ;
V_23 -> V_249 = V_215 ? true : false ;
}
if ( V_180 [ V_250 ] ) {
V_31 V_215 = F_71 ( V_180 [ V_250 ] ) ;
V_23 -> V_251 = V_215 ? true : false ;
}
if ( V_180 [ V_252 ] ) {
V_31 V_215 = F_71 ( V_180 [ V_252 ] ) ;
V_23 -> V_253 = V_215 ? true : false ;
}
#endif
return 0 ;
}
static int F_118 ( struct V_136 * V_254 , struct V_18 * V_19 ,
struct V_129 * V_166 [] , struct V_129 * V_180 [] )
{
struct V_22 * V_23 = F_12 ( V_19 ) ;
int V_100 ;
if ( V_166 [ V_125 ] ) {
F_84 ( & V_23 -> V_178 ) ;
F_119 ( V_23 , F_65 ( V_166 [ V_125 ] ) ) ;
F_85 ( & V_23 -> V_178 ) ;
}
V_100 = F_120 ( V_19 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_95 ( V_19 , V_166 , V_180 ) ;
if ( V_100 )
F_121 ( V_19 ) ;
return V_100 ;
}
static T_3 F_122 ( const struct V_18 * V_187 )
{
return F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_2 ) ) +
F_15 ( sizeof( V_31 ) ) +
#ifdef F_89
F_15 ( sizeof( T_4 ) ) +
F_15 ( sizeof( T_2 ) ) +
F_15 ( sizeof( V_31 ) ) +
#endif
F_15 ( sizeof( T_2 ) ) +
F_15 ( sizeof( struct V_30 ) ) +
F_15 ( sizeof( struct V_30 ) ) +
F_15 ( sizeof( T_2 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_15 ( V_181 ) +
#ifdef F_18
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_17 ( sizeof( V_32 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
#endif
#if F_116 ( V_247 )
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
#endif
0 ;
}
static int F_123 ( struct V_36 * V_37 , const struct V_18 * V_187 )
{
struct V_22 * V_23 = F_12 ( V_187 ) ;
T_1 V_255 = F_124 ( V_23 -> V_255 ) ;
T_1 V_256 = F_124 ( V_23 -> V_256 ) ;
T_1 V_257 = F_124 ( V_23 -> V_258 ) ;
T_1 V_259 = F_124 ( V_23 -> V_259 ) ;
T_1 V_161 = V_23 -> V_161 ;
T_2 V_44 = ( V_23 -> V_260 . V_261 [ 0 ] << 8 ) | V_23 -> V_260 . V_261 [ 1 ] ;
V_31 V_262 = F_125 ( V_23 ) ;
V_32 V_263 ;
V_263 = F_26 ( & V_23 -> V_264 ) ;
if ( F_27 ( V_37 , V_265 , V_263 , V_266 ) )
return - V_83 ;
V_263 = F_26 ( & V_23 -> V_267 ) ;
if ( F_27 ( V_37 , V_268 , V_263 , V_266 ) )
return - V_83 ;
V_263 = F_26 ( & V_23 -> V_269 ) ;
if ( F_27 ( V_37 , V_270 , V_263 ,
V_266 ) )
return - V_83 ;
V_263 = F_26 ( & V_23 -> V_271 . V_272 ) ;
if ( F_27 ( V_37 , V_273 , V_263 , V_266 ) )
return - V_83 ;
if ( F_24 ( V_37 , V_189 , V_255 ) ||
F_24 ( V_37 , V_190 , V_256 ) ||
F_24 ( V_37 , V_191 , V_257 ) ||
F_24 ( V_37 , V_192 , V_259 ) ||
F_24 ( V_37 , V_193 , V_161 ) ||
F_23 ( V_37 , V_194 , V_44 ) ||
F_22 ( V_37 , V_195 , V_262 ) ||
F_23 ( V_37 , V_202 , V_23 -> V_205 ) ||
F_25 ( V_37 , V_274 , sizeof( struct V_30 ) ,
& V_23 -> V_260 ) ||
F_25 ( V_37 , V_275 , sizeof( struct V_30 ) ,
& V_23 -> V_67 ) ||
F_23 ( V_37 , V_276 , V_23 -> V_277 ) ||
F_24 ( V_37 , V_278 , V_23 -> V_279 ) ||
F_22 ( V_37 , V_280 , V_23 -> V_281 ) ||
F_22 ( V_37 , V_282 ,
V_23 -> V_283 ) ||
F_25 ( V_37 , V_206 , V_181 , V_23 -> V_208 ) )
return - V_83 ;
#ifdef F_89
if ( F_126 ( V_37 , V_183 , V_23 -> V_197 ) ||
F_23 ( V_37 , V_198 , V_23 -> V_284 ) ||
F_22 ( V_37 , V_200 , V_23 -> V_285 ) )
return - V_83 ;
#endif
#ifdef F_18
if ( F_22 ( V_37 , V_211 , V_23 -> V_92 ) ||
F_22 ( V_37 , V_212 , ! V_23 -> V_286 ) ||
F_22 ( V_37 , V_214 ,
V_23 -> V_216 ) ||
F_22 ( V_37 , V_217 , V_23 -> V_287 ) ||
F_22 ( V_37 , V_239 ,
V_23 -> V_241 ) ||
F_24 ( V_37 , V_219 ,
V_23 -> V_220 ) ||
F_24 ( V_37 , V_221 , V_23 -> V_222 ) ||
F_24 ( V_37 , V_223 ,
V_23 -> V_224 ) ||
F_24 ( V_37 , V_225 ,
V_23 -> V_226 ) ||
F_22 ( V_37 , V_242 ,
V_23 -> V_288 ) )
return - V_83 ;
#if F_116 ( V_244 )
if ( F_22 ( V_37 , V_245 ,
V_23 -> V_289 ) )
return - V_83 ;
#endif
V_263 = F_124 ( V_23 -> V_228 ) ;
if ( F_27 ( V_37 , V_227 , V_263 ,
V_266 ) )
return - V_83 ;
V_263 = F_124 ( V_23 -> V_230 ) ;
if ( F_27 ( V_37 , V_229 , V_263 ,
V_266 ) )
return - V_83 ;
V_263 = F_124 ( V_23 -> V_232 ) ;
if ( F_27 ( V_37 , V_231 , V_263 ,
V_266 ) )
return - V_83 ;
V_263 = F_124 ( V_23 -> V_234 ) ;
if ( F_27 ( V_37 , V_233 , V_263 ,
V_266 ) )
return - V_83 ;
V_263 = F_124 ( V_23 -> V_236 ) ;
if ( F_27 ( V_37 , V_235 , V_263 ,
V_266 ) )
return - V_83 ;
V_263 = F_124 ( V_23 -> V_238 ) ;
if ( F_27 ( V_37 , V_237 , V_263 ,
V_266 ) )
return - V_83 ;
#endif
#if F_116 ( V_247 )
if ( F_22 ( V_37 , V_248 ,
V_23 -> V_249 ? 1 : 0 ) ||
F_22 ( V_37 , V_250 ,
V_23 -> V_251 ? 1 : 0 ) ||
F_22 ( V_37 , V_252 ,
V_23 -> V_253 ? 1 : 0 ) )
return - V_83 ;
#endif
return 0 ;
}
static T_3 F_127 ( const struct V_18 * V_19 , int V_154 )
{
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
int V_290 = 0 ;
switch ( V_154 ) {
case V_291 :
V_23 = F_12 ( V_19 ) ;
V_2 = F_128 ( V_23 ) ;
break;
case V_292 :
V_21 = F_52 ( V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = V_21 -> V_23 ;
V_2 = F_129 ( V_21 ) ;
break;
default:
return 0 ;
}
if ( V_2 ) {
F_130 (v, &vg->vlan_list, vlist)
V_290 ++ ;
}
return V_290 * F_15 ( sizeof( struct V_293 ) ) +
F_15 ( sizeof( struct V_294 ) ) +
F_15 ( 0 ) ;
}
static int F_131 ( struct V_36 * V_37 ,
const struct V_18 * V_19 ,
int * V_295 , int V_154 )
{
struct V_129 * T_7 V_296 ;
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
struct V_129 * V_130 ;
int V_297 = 0 ;
switch ( V_154 ) {
case V_291 :
V_23 = F_12 ( V_19 ) ;
V_2 = F_128 ( V_23 ) ;
break;
case V_292 :
V_21 = F_52 ( V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = V_21 -> V_23 ;
V_2 = F_129 ( V_21 ) ;
break;
default:
return - V_151 ;
}
V_130 = F_39 ( V_37 , V_298 ) ;
if ( ! V_130 )
return - V_83 ;
if ( V_2 ) {
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_130 (v, &vg->vlan_list, vlist) {
struct V_293 V_299 ;
struct V_300 V_301 ;
if ( ++ V_297 < * V_295 )
continue;
memset ( & V_299 , 0 , sizeof( V_299 ) ) ;
V_299 . V_13 = V_5 -> V_13 ;
V_299 . V_9 = V_5 -> V_9 ;
if ( V_5 -> V_13 == V_10 )
V_299 . V_9 |= V_14 ;
F_132 ( V_5 , & V_301 ) ;
V_299 . V_302 = V_301 . V_302 ;
V_299 . V_303 = V_301 . V_303 ;
V_299 . V_304 = V_301 . V_304 ;
V_299 . V_305 = V_301 . V_305 ;
if ( F_25 ( V_37 , V_306 , sizeof( V_299 ) , & V_299 ) )
goto V_98;
}
}
#ifdef F_18
if ( ++ V_297 >= * V_295 ) {
T_7 = F_133 ( V_37 , V_307 ,
sizeof( struct V_294 ) ,
V_308 ) ;
if ( ! T_7 )
goto V_98;
F_134 ( V_23 , V_21 , F_65 ( T_7 ) ) ;
}
#endif
F_40 ( V_37 , V_130 ) ;
* V_295 = 0 ;
return 0 ;
V_98:
F_40 ( V_37 , V_130 ) ;
* V_295 = V_297 ;
return - V_83 ;
}
int T_8 F_135 ( void )
{
int V_100 ;
F_136 () ;
F_137 ( & V_309 ) ;
V_100 = F_138 ( & V_310 ) ;
if ( V_100 )
goto V_311;
return 0 ;
V_311:
F_139 ( & V_309 ) ;
F_140 () ;
return V_100 ;
}
void F_141 ( void )
{
F_140 () ;
F_139 ( & V_309 ) ;
F_142 ( & V_310 ) ;
}
