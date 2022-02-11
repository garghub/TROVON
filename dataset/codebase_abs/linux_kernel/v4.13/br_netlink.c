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
F_22 ( V_37 , V_62 ,
! ! ( V_21 -> V_9 & V_63 ) ) ||
F_22 ( V_37 , V_64 , ! ! ( V_21 -> V_9 & V_65 ) ) ||
F_22 ( V_37 , V_66 ,
! ! ( V_21 -> V_9 & V_67 ) ) ||
F_25 ( V_37 , V_68 , sizeof( struct V_30 ) ,
& V_21 -> V_69 ) ||
F_25 ( V_37 , V_70 , sizeof( struct V_30 ) ,
& V_21 -> V_71 ) ||
F_23 ( V_37 , V_72 , V_21 -> V_73 ) ||
F_23 ( V_37 , V_74 , V_21 -> V_75 ) ||
F_23 ( V_37 , V_76 , V_21 -> V_77 ) ||
F_23 ( V_37 , V_78 , V_21 -> V_79 ) ||
F_22 ( V_37 , V_80 ,
V_21 -> V_81 ) ||
F_22 ( V_37 , V_82 , V_21 -> V_83 ) ||
F_22 ( V_37 , V_84 , ! ! ( V_21 -> V_9 &
V_28 ) ) )
return - V_85 ;
V_40 = F_26 ( & V_21 -> V_86 ) ;
if ( F_27 ( V_37 , V_87 , V_40 ,
V_88 ) )
return - V_85 ;
V_40 = F_26 ( & V_21 -> V_89 ) ;
if ( F_27 ( V_37 , V_90 , V_40 ,
V_88 ) )
return - V_85 ;
V_40 = F_26 ( & V_21 -> V_91 ) ;
if ( F_27 ( V_37 , V_92 , V_40 ,
V_88 ) )
return - V_85 ;
#ifdef F_18
if ( F_22 ( V_37 , V_93 ,
V_21 -> V_94 ) )
return - V_85 ;
#endif
return 0 ;
}
static int F_28 ( struct V_36 * V_37 , T_2 V_95 ,
T_2 V_96 , T_2 V_9 )
{
struct V_29 V_97 ;
if ( ( V_96 - V_95 ) > 0 ) {
V_97 . V_13 = V_95 ;
V_97 . V_9 = V_9 | V_98 ;
if ( F_25 ( V_37 , V_99 ,
sizeof( V_97 ) , & V_97 ) )
goto V_100;
V_97 . V_13 = V_96 ;
V_97 . V_9 = V_9 | V_101 ;
if ( F_25 ( V_37 , V_99 ,
sizeof( V_97 ) , & V_97 ) )
goto V_100;
} else {
V_97 . V_13 = V_95 ;
V_97 . V_9 = V_9 ;
if ( F_25 ( V_37 , V_99 ,
sizeof( V_97 ) , & V_97 ) )
goto V_100;
}
return 0 ;
V_100:
return - V_85 ;
}
static int F_29 ( struct V_36 * V_37 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 ;
T_2 V_6 = 0 , V_7 = 0 , V_8 = 0 ;
T_2 V_9 , V_10 ;
int V_102 = 0 ;
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
V_102 = F_28 ( V_37 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_102 )
return V_102 ;
}
V_16:
V_6 = V_5 -> V_13 ;
V_7 = V_5 -> V_13 ;
V_8 = V_9 ;
}
if ( V_6 != 0 ) {
V_102 = F_28 ( V_37 , V_6 ,
V_7 ,
V_8 ) ;
if ( V_102 )
return V_102 ;
}
return 0 ;
}
static int F_30 ( struct V_36 * V_37 ,
struct V_1 * V_2 )
{
struct V_29 V_97 ;
struct V_4 * V_5 ;
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_3 (v, &vg->vlan_list, vlist) {
if ( ! F_4 ( V_5 ) )
continue;
V_97 . V_13 = V_5 -> V_13 ;
V_97 . V_9 = 0 ;
if ( V_5 -> V_13 == V_10 )
V_97 . V_9 |= V_14 ;
if ( V_5 -> V_9 & V_15 )
V_97 . V_9 |= V_15 ;
if ( F_25 ( V_37 , V_99 ,
sizeof( V_97 ) , & V_97 ) )
goto V_100;
}
return 0 ;
V_100:
return - V_85 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_20 * V_103 ,
T_1 V_104 , T_1 V_105 , int V_106 , unsigned int V_9 ,
T_1 V_3 , const struct V_18 * V_19 )
{
struct V_22 * V_23 ;
struct V_33 * V_107 ;
struct V_108 * V_109 ;
V_31 V_110 = F_32 ( V_19 ) ? V_19 -> V_110 : V_111 ;
if ( V_103 )
V_23 = V_103 -> V_23 ;
else
V_23 = F_12 ( V_19 ) ;
F_33 ( V_23 , L_1 ,
V_106 , V_19 -> V_112 , V_23 -> V_19 -> V_112 ) ;
V_109 = F_34 ( V_37 , V_104 , V_105 , V_106 , sizeof( * V_107 ) , V_9 ) ;
if ( V_109 == NULL )
return - V_85 ;
V_107 = F_35 ( V_109 ) ;
V_107 -> V_113 = V_114 ;
V_107 -> V_115 = 0 ;
V_107 -> V_116 = V_19 -> type ;
V_107 -> V_117 = V_19 -> V_118 ;
V_107 -> V_119 = F_36 ( V_19 ) ;
V_107 -> V_120 = 0 ;
if ( F_37 ( V_37 , V_121 , V_19 -> V_112 ) ||
F_24 ( V_37 , V_122 , V_23 -> V_19 -> V_118 ) ||
F_24 ( V_37 , V_123 , V_19 -> V_124 ) ||
F_22 ( V_37 , V_125 , V_110 ) ||
( V_19 -> V_126 &&
F_25 ( V_37 , V_127 , V_19 -> V_126 , V_19 -> V_128 ) ) ||
( V_19 -> V_118 != F_38 ( V_19 ) &&
F_24 ( V_37 , V_129 , F_38 ( V_19 ) ) ) )
goto V_100;
if ( V_106 == V_130 && V_103 ) {
struct V_131 * V_132
= F_39 ( V_37 , V_133 | V_134 ) ;
if ( V_132 == NULL || F_21 ( V_37 , V_103 ) < 0 )
goto V_100;
F_40 ( V_37 , V_132 ) ;
}
if ( ( V_3 & V_17 ) ||
( V_3 & V_12 ) ) {
struct V_1 * V_2 ;
struct V_131 * V_135 ;
int V_102 ;
F_6 () ;
if ( V_103 )
V_2 = F_11 ( V_103 ) ;
else
V_2 = F_13 ( V_23 ) ;
if ( ! V_2 || ! V_2 -> V_11 ) {
F_7 () ;
goto V_136;
}
V_135 = F_39 ( V_37 , V_137 ) ;
if ( ! V_135 ) {
F_7 () ;
goto V_100;
}
if ( V_3 & V_12 )
V_102 = F_29 ( V_37 , V_2 ) ;
else
V_102 = F_30 ( V_37 , V_2 ) ;
if ( V_103 && ( V_103 -> V_9 & V_28 ) )
V_102 = F_41 ( V_37 , V_2 ) ;
F_7 () ;
if ( V_102 )
goto V_100;
F_40 ( V_37 , V_135 ) ;
}
V_136:
F_42 ( V_37 , V_109 ) ;
return 0 ;
V_100:
F_43 ( V_37 , V_109 ) ;
return - V_85 ;
}
void F_44 ( int V_106 , struct V_20 * V_103 )
{
struct V_138 * V_138 ;
struct V_36 * V_37 ;
int V_102 = - V_139 ;
T_1 V_140 = V_12 ;
if ( ! V_103 )
return;
V_138 = F_45 ( V_103 -> V_19 ) ;
F_33 ( V_103 -> V_23 , L_2 ,
( unsigned int ) V_103 -> V_79 , V_103 -> V_19 -> V_112 , V_106 ) ;
V_37 = F_46 ( F_19 ( V_103 -> V_19 , V_140 ) , V_141 ) ;
if ( V_37 == NULL )
goto V_142;
V_102 = F_31 ( V_37 , V_103 , 0 , 0 , V_106 , 0 , V_140 , V_103 -> V_19 ) ;
if ( V_102 < 0 ) {
F_47 ( V_102 == - V_85 ) ;
F_48 ( V_37 ) ;
goto V_142;
}
F_49 ( V_37 , V_138 , 0 , V_143 , NULL , V_141 ) ;
return;
V_142:
F_50 ( V_138 , V_143 , V_102 ) ;
}
int F_51 ( struct V_36 * V_37 , T_1 V_104 , T_1 V_105 ,
struct V_18 * V_19 , T_1 V_3 , int V_144 )
{
struct V_20 * V_103 = F_52 ( V_19 ) ;
if ( ! V_103 && ! ( V_3 & V_17 ) &&
! ( V_3 & V_12 ) )
return 0 ;
return F_31 ( V_37 , V_103 , V_104 , V_105 , V_130 , V_144 ,
V_3 , V_19 ) ;
}
static int F_53 ( struct V_22 * V_23 , struct V_20 * V_21 ,
int V_145 , struct V_29 * V_97 )
{
int V_102 = 0 ;
switch ( V_145 ) {
case V_146 :
if ( V_21 ) {
V_102 = F_54 ( V_21 , V_97 -> V_13 , V_97 -> V_9 ) ;
if ( V_102 )
break;
} else {
V_97 -> V_9 |= V_147 ;
V_102 = F_55 ( V_23 , V_97 -> V_13 , V_97 -> V_9 ) ;
}
break;
case V_148 :
if ( V_21 ) {
F_56 ( V_21 , V_97 -> V_13 ) ;
if ( V_97 -> V_9 & V_149 )
F_57 ( V_21 -> V_23 , V_97 -> V_13 ) ;
} else {
F_57 ( V_23 , V_97 -> V_13 ) ;
}
break;
}
return V_102 ;
}
static int F_58 ( struct V_22 * V_23 ,
struct V_20 * V_21 , int V_145 ,
struct V_29 * V_150 ,
struct V_29 * * V_151 )
{
if ( ! V_150 -> V_13 || V_150 -> V_13 >= V_152 )
return - V_153 ;
if ( V_150 -> V_9 & V_98 ) {
if ( * V_151 )
return - V_153 ;
* V_151 = V_150 ;
if ( ( * V_151 ) -> V_9 & V_14 )
return - V_153 ;
return 0 ;
}
if ( * V_151 ) {
struct V_29 V_154 ;
int V_5 , V_102 ;
if ( ! ( V_150 -> V_9 & V_101 ) )
return - V_153 ;
if ( V_150 -> V_13 <= ( * V_151 ) -> V_13 )
return - V_153 ;
memcpy ( & V_154 , * V_151 ,
sizeof( struct V_29 ) ) ;
for ( V_5 = ( * V_151 ) -> V_13 ; V_5 <= V_150 -> V_13 ; V_5 ++ ) {
V_154 . V_13 = V_5 ;
V_102 = F_53 ( V_23 , V_21 , V_145 , & V_154 ) ;
if ( V_102 )
break;
}
* V_151 = NULL ;
return 0 ;
}
return F_53 ( V_23 , V_21 , V_145 , V_150 ) ;
}
static int F_59 ( struct V_22 * V_23 ,
struct V_20 * V_21 ,
struct V_131 * V_155 ,
int V_145 )
{
struct V_29 * V_150 = NULL ;
struct V_29 * V_151 = NULL ;
struct V_131 * V_156 ;
struct V_157 V_158 = {} ;
struct V_157 V_159 = {} ;
int V_102 = 0 , V_160 ;
F_60 (attr, af_spec, rem) {
V_102 = 0 ;
switch ( F_61 ( V_156 ) ) {
case V_161 :
if ( ! V_21 || ! ( V_21 -> V_9 & V_28 ) )
return - V_153 ;
V_102 = F_62 ( V_156 , & V_159 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_63 ( V_23 , V_21 , V_145 ,
& V_159 ,
& V_158 ) ;
if ( V_102 )
return V_102 ;
break;
case V_99 :
if ( F_64 ( V_156 ) != sizeof( struct V_29 ) )
return - V_153 ;
V_150 = F_65 ( V_156 ) ;
V_102 = F_58 ( V_23 , V_21 , V_145 , V_150 ,
& V_151 ) ;
if ( V_102 )
return V_102 ;
break;
}
}
return V_102 ;
}
static int F_66 ( struct V_20 * V_21 , V_31 V_42 )
{
if ( V_42 > V_162 )
return - V_153 ;
if ( V_21 -> V_23 -> V_163 == V_164 )
return - V_165 ;
if ( ! F_32 ( V_21 -> V_19 ) ||
( ! F_67 ( V_21 -> V_19 ) && V_42 != V_166 ) )
return - V_167 ;
F_68 ( V_21 , V_42 ) ;
F_69 ( V_21 -> V_23 ) ;
return 0 ;
}
static int F_70 ( struct V_20 * V_21 , struct V_131 * V_168 [] ,
int V_169 , unsigned long V_170 )
{
unsigned long V_9 ;
int V_102 ;
if ( ! V_168 [ V_169 ] )
return 0 ;
if ( F_71 ( V_168 [ V_169 ] ) )
V_9 = V_21 -> V_9 | V_170 ;
else
V_9 = V_21 -> V_9 & ~ V_170 ;
V_102 = F_72 ( V_21 , V_9 , V_170 ) ;
if ( V_102 )
return V_102 ;
V_21 -> V_9 = V_9 ;
return 0 ;
}
static int F_73 ( struct V_20 * V_21 , struct V_131 * V_168 [] )
{
unsigned long V_171 = V_21 -> V_9 ;
bool V_172 = false ;
int V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_47 , V_39 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_48 , V_49 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_52 , V_53 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_50 , V_51 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_56 , V_57 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_58 , V_59 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_60 , V_61 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_54 , V_55 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_62 , V_63 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_64 , V_65 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_70 ( V_21 , V_168 , V_66 , V_67 ) ;
if ( V_102 )
return V_102 ;
V_172 = ( V_21 -> V_9 & V_28 ) ? true : false ;
V_102 = F_70 ( V_21 , V_168 , V_84 , V_28 ) ;
if ( V_102 )
return V_102 ;
if ( V_172 && ! ( V_21 -> V_9 & V_28 ) )
F_74 ( V_21 ) ;
if ( V_168 [ V_45 ] ) {
V_102 = F_75 ( V_21 , F_76 ( V_168 [ V_45 ] ) ) ;
if ( V_102 )
return V_102 ;
}
if ( V_168 [ V_43 ] ) {
V_102 = F_77 ( V_21 , F_78 ( V_168 [ V_43 ] ) ) ;
if ( V_102 )
return V_102 ;
}
if ( V_168 [ V_41 ] ) {
V_102 = F_66 ( V_21 , F_71 ( V_168 [ V_41 ] ) ) ;
if ( V_102 )
return V_102 ;
}
if ( V_168 [ V_173 ] )
F_79 ( V_21 -> V_23 , V_21 , 0 , 0 ) ;
#ifdef F_18
if ( V_168 [ V_93 ] ) {
V_31 V_174 = F_71 ( V_168 [ V_93 ] ) ;
V_102 = F_80 ( V_21 , V_174 ) ;
if ( V_102 )
return V_102 ;
}
#endif
F_81 ( V_21 , V_171 ^ V_21 -> V_9 ) ;
return 0 ;
}
int F_82 ( struct V_18 * V_19 , struct V_108 * V_109 , T_2 V_9 )
{
struct V_131 * V_175 ;
struct V_131 * V_176 ;
struct V_20 * V_21 ;
struct V_131 * V_168 [ V_177 + 1 ] ;
int V_102 = 0 ;
V_175 = F_83 ( V_109 , sizeof( struct V_33 ) , V_133 ) ;
V_176 = F_83 ( V_109 , sizeof( struct V_33 ) , V_137 ) ;
if ( ! V_175 && ! V_176 )
return 0 ;
V_21 = F_52 ( V_19 ) ;
if ( ! V_21 && ! V_176 )
return - V_153 ;
if ( V_21 && V_175 ) {
if ( V_175 -> F_61 & V_134 ) {
V_102 = F_84 ( V_168 , V_177 , V_175 ,
V_178 , NULL ) ;
if ( V_102 )
return V_102 ;
F_85 ( & V_21 -> V_23 -> V_179 ) ;
V_102 = F_73 ( V_21 , V_168 ) ;
F_86 ( & V_21 -> V_23 -> V_179 ) ;
} else {
if ( F_64 ( V_175 ) < sizeof( V_31 ) )
return - V_153 ;
F_85 ( & V_21 -> V_23 -> V_179 ) ;
V_102 = F_66 ( V_21 , F_71 ( V_175 ) ) ;
F_86 ( & V_21 -> V_23 -> V_179 ) ;
}
if ( V_102 )
goto V_180;
}
if ( V_176 ) {
V_102 = F_59 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_176 , V_146 ) ;
}
if ( V_102 == 0 )
F_44 ( V_130 , V_21 ) ;
V_180:
return V_102 ;
}
int F_87 ( struct V_18 * V_19 , struct V_108 * V_109 , T_2 V_9 )
{
struct V_131 * V_176 ;
struct V_20 * V_21 ;
int V_102 = 0 ;
V_176 = F_83 ( V_109 , sizeof( struct V_33 ) , V_137 ) ;
if ( ! V_176 )
return 0 ;
V_21 = F_52 ( V_19 ) ;
if ( ! V_21 && ! ( V_19 -> V_26 & V_27 ) )
return - V_153 ;
V_102 = F_59 ( (struct V_22 * ) F_12 ( V_19 ) , V_21 ,
V_176 , V_148 ) ;
if ( V_102 == 0 )
F_44 ( V_130 , V_21 ) ;
return V_102 ;
}
static int F_88 ( struct V_131 * V_168 [] , struct V_131 * V_181 [] ,
struct V_182 * V_183 )
{
if ( V_168 [ V_127 ] ) {
if ( F_64 ( V_168 [ V_127 ] ) != V_184 )
return - V_153 ;
if ( ! F_89 ( F_65 ( V_168 [ V_127 ] ) ) )
return - V_185 ;
}
if ( ! V_181 )
return 0 ;
#ifdef F_90
if ( V_181 [ V_186 ] ) {
switch ( F_91 ( V_181 [ V_186 ] ) ) {
case F_92 ( V_187 ) :
case F_92 ( V_188 ) :
break;
default:
return - V_189 ;
}
}
if ( V_181 [ V_190 ] ) {
T_4 V_191 = F_78 ( V_181 [ V_190 ] ) ;
if ( V_191 >= V_152 )
return - V_153 ;
}
#endif
return 0 ;
}
static int F_93 ( struct V_18 * V_192 ,
struct V_18 * V_19 ,
struct V_131 * V_168 [] ,
struct V_131 * V_181 [] ,
struct V_182 * V_183 )
{
struct V_22 * V_23 = F_12 ( V_192 ) ;
int V_193 ;
if ( ! V_181 )
return 0 ;
F_85 ( & V_23 -> V_179 ) ;
V_193 = F_73 ( F_52 ( V_19 ) , V_181 ) ;
F_86 ( & V_23 -> V_179 ) ;
return V_193 ;
}
static int F_94 ( struct V_36 * V_37 ,
const struct V_18 * V_192 ,
const struct V_18 * V_19 )
{
return F_21 ( V_37 , F_52 ( V_19 ) ) ;
}
static T_3 F_95 ( const struct V_18 * V_192 ,
const struct V_18 * V_19 )
{
return F_16 () ;
}
static int F_96 ( struct V_18 * V_192 , struct V_131 * V_168 [] ,
struct V_131 * V_181 [] ,
struct V_182 * V_183 )
{
struct V_22 * V_23 = F_12 ( V_192 ) ;
int V_102 ;
if ( ! V_181 )
return 0 ;
if ( V_181 [ V_194 ] ) {
V_102 = F_97 ( V_23 , F_76 ( V_181 [ V_194 ] ) ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_195 ] ) {
V_102 = F_98 ( V_23 , F_76 ( V_181 [ V_195 ] ) ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_196 ] ) {
V_102 = F_99 ( V_23 , F_76 ( V_181 [ V_196 ] ) ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_197 ] ) {
V_102 = F_100 ( V_23 , F_76 ( V_181 [ V_197 ] ) ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_198 ] ) {
T_1 V_163 = F_76 ( V_181 [ V_198 ] ) ;
F_101 ( V_23 , V_163 ) ;
}
if ( V_181 [ V_199 ] ) {
T_1 V_44 = F_78 ( V_181 [ V_199 ] ) ;
F_102 ( V_23 , V_44 ) ;
}
if ( V_181 [ V_200 ] ) {
V_31 V_201 = F_71 ( V_181 [ V_200 ] ) ;
V_102 = F_103 ( V_23 , V_201 ) ;
if ( V_102 )
return V_102 ;
}
#ifdef F_90
if ( V_181 [ V_186 ] ) {
T_5 V_202 = F_91 ( V_181 [ V_186 ] ) ;
V_102 = F_104 ( V_23 , V_202 ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_190 ] ) {
T_4 V_191 = F_78 ( V_181 [ V_190 ] ) ;
V_102 = F_105 ( V_23 , V_191 ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_203 ] ) {
T_6 V_204 = F_71 ( V_181 [ V_203 ] ) ;
V_102 = F_106 ( V_23 , V_204 ) ;
if ( V_102 )
return V_102 ;
}
#endif
if ( V_181 [ V_205 ] ) {
T_2 V_206 = F_78 ( V_181 [ V_205 ] ) ;
if ( V_206 & V_207 )
return - V_153 ;
V_23 -> V_208 = V_206 ;
}
if ( V_181 [ V_209 ] ) {
V_31 V_210 [ V_184 ] ;
if ( F_64 ( V_181 [ V_209 ] ) != V_184 )
return - V_153 ;
memcpy ( V_210 , F_65 ( V_181 [ V_209 ] ) , V_184 ) ;
if ( ! F_107 ( V_210 ) )
return - V_153 ;
if ( V_210 [ 5 ] == 1 ||
V_210 [ 5 ] == 2 ||
V_210 [ 5 ] == 3 )
return - V_153 ;
F_85 ( & V_23 -> V_179 ) ;
memcpy ( V_23 -> V_211 , V_210 , sizeof( V_23 -> V_211 ) ) ;
F_86 ( & V_23 -> V_179 ) ;
V_23 -> V_212 = true ;
F_108 ( V_23 ) ;
}
if ( V_181 [ V_213 ] )
F_109 ( V_23 ) ;
#ifdef F_18
if ( V_181 [ V_214 ] ) {
V_31 V_94 = F_71 ( V_181 [ V_214 ] ) ;
V_102 = F_110 ( V_23 , V_94 ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_215 ] ) {
V_31 V_216 = F_71 ( V_181 [ V_215 ] ) ;
V_102 = F_111 ( V_23 , V_216 ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_217 ] ) {
V_31 V_218 ;
V_218 = F_71 ( V_181 [ V_217 ] ) ;
V_23 -> V_219 = ! ! V_218 ;
}
if ( V_181 [ V_220 ] ) {
V_31 V_221 = F_71 ( V_181 [ V_220 ] ) ;
V_102 = F_112 ( V_23 , V_221 ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_222 ] ) {
T_1 V_218 = F_76 ( V_181 [ V_222 ] ) ;
V_23 -> V_223 = V_218 ;
}
if ( V_181 [ V_224 ] ) {
T_1 V_225 = F_76 ( V_181 [ V_224 ] ) ;
V_102 = F_113 ( V_23 , V_225 ) ;
if ( V_102 )
return V_102 ;
}
if ( V_181 [ V_226 ] ) {
T_1 V_218 = F_76 ( V_181 [ V_226 ] ) ;
V_23 -> V_227 = V_218 ;
}
if ( V_181 [ V_228 ] ) {
T_1 V_218 = F_76 ( V_181 [ V_228 ] ) ;
V_23 -> V_229 = V_218 ;
}
if ( V_181 [ V_230 ] ) {
V_32 V_218 = F_114 ( V_181 [ V_230 ] ) ;
V_23 -> V_231 = F_115 ( V_218 ) ;
}
if ( V_181 [ V_232 ] ) {
V_32 V_218 = F_114 ( V_181 [ V_232 ] ) ;
V_23 -> V_233 = F_115 ( V_218 ) ;
}
if ( V_181 [ V_234 ] ) {
V_32 V_218 = F_114 ( V_181 [ V_234 ] ) ;
V_23 -> V_235 = F_115 ( V_218 ) ;
}
if ( V_181 [ V_236 ] ) {
V_32 V_218 = F_114 ( V_181 [ V_236 ] ) ;
V_23 -> V_237 = F_115 ( V_218 ) ;
}
if ( V_181 [ V_238 ] ) {
V_32 V_218 = F_114 ( V_181 [ V_238 ] ) ;
V_23 -> V_239 = F_115 ( V_218 ) ;
}
if ( V_181 [ V_240 ] ) {
V_32 V_218 = F_114 ( V_181 [ V_240 ] ) ;
V_23 -> V_241 = F_115 ( V_218 ) ;
}
if ( V_181 [ V_242 ] ) {
T_6 V_243 ;
V_243 = F_71 ( V_181 [ V_242 ] ) ;
V_23 -> V_244 = ! ! V_243 ;
}
if ( V_181 [ V_245 ] ) {
T_6 V_246 ;
V_246 = F_71 ( V_181 [ V_245 ] ) ;
V_102 = F_116 ( V_23 , V_246 ) ;
if ( V_102 )
return V_102 ;
}
#if F_117 ( V_247 )
if ( V_181 [ V_248 ] ) {
T_6 V_249 ;
V_249 = F_71 ( V_181 [ V_248 ] ) ;
V_102 = F_118 ( V_23 , V_249 ) ;
if ( V_102 )
return V_102 ;
}
#endif
#endif
#if F_117 ( V_250 )
if ( V_181 [ V_251 ] ) {
V_31 V_218 = F_71 ( V_181 [ V_251 ] ) ;
V_23 -> V_252 = V_218 ? true : false ;
}
if ( V_181 [ V_253 ] ) {
V_31 V_218 = F_71 ( V_181 [ V_253 ] ) ;
V_23 -> V_254 = V_218 ? true : false ;
}
if ( V_181 [ V_255 ] ) {
V_31 V_218 = F_71 ( V_181 [ V_255 ] ) ;
V_23 -> V_256 = V_218 ? true : false ;
}
#endif
return 0 ;
}
static int F_119 ( struct V_138 * V_257 , struct V_18 * V_19 ,
struct V_131 * V_168 [] , struct V_131 * V_181 [] ,
struct V_182 * V_183 )
{
struct V_22 * V_23 = F_12 ( V_19 ) ;
int V_102 ;
if ( V_168 [ V_127 ] ) {
F_85 ( & V_23 -> V_179 ) ;
F_120 ( V_23 , F_65 ( V_168 [ V_127 ] ) ) ;
F_86 ( & V_23 -> V_179 ) ;
}
V_102 = F_121 ( V_19 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_96 ( V_19 , V_168 , V_181 , V_183 ) ;
if ( V_102 )
F_122 ( V_19 ) ;
return V_102 ;
}
static T_3 F_123 ( const struct V_18 * V_192 )
{
return F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_1 ) ) +
F_15 ( sizeof( T_2 ) ) +
F_15 ( sizeof( V_31 ) ) +
#ifdef F_90
F_15 ( sizeof( T_5 ) ) +
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
F_15 ( V_184 ) +
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
#if F_117 ( V_250 )
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
F_15 ( sizeof( V_31 ) ) +
#endif
0 ;
}
static int F_124 ( struct V_36 * V_37 , const struct V_18 * V_192 )
{
struct V_22 * V_23 = F_12 ( V_192 ) ;
T_1 V_258 = F_125 ( V_23 -> V_258 ) ;
T_1 V_259 = F_125 ( V_23 -> V_259 ) ;
T_1 V_260 = F_125 ( V_23 -> V_261 ) ;
T_1 V_262 = F_125 ( V_23 -> V_262 ) ;
T_1 V_163 = V_23 -> V_163 ;
T_2 V_44 = ( V_23 -> V_263 . V_264 [ 0 ] << 8 ) | V_23 -> V_263 . V_264 [ 1 ] ;
V_31 V_265 = F_126 ( V_23 -> V_19 ) ;
V_32 V_266 ;
V_266 = F_26 ( & V_23 -> V_267 ) ;
if ( F_27 ( V_37 , V_268 , V_266 , V_269 ) )
return - V_85 ;
V_266 = F_26 ( & V_23 -> V_270 ) ;
if ( F_27 ( V_37 , V_271 , V_266 , V_269 ) )
return - V_85 ;
V_266 = F_26 ( & V_23 -> V_272 ) ;
if ( F_27 ( V_37 , V_273 , V_266 ,
V_269 ) )
return - V_85 ;
V_266 = F_26 ( & V_23 -> V_274 . V_275 ) ;
if ( F_27 ( V_37 , V_276 , V_266 , V_269 ) )
return - V_85 ;
if ( F_24 ( V_37 , V_194 , V_258 ) ||
F_24 ( V_37 , V_195 , V_259 ) ||
F_24 ( V_37 , V_196 , V_260 ) ||
F_24 ( V_37 , V_197 , V_262 ) ||
F_24 ( V_37 , V_198 , V_163 ) ||
F_23 ( V_37 , V_199 , V_44 ) ||
F_22 ( V_37 , V_200 , V_265 ) ||
F_23 ( V_37 , V_205 , V_23 -> V_208 ) ||
F_25 ( V_37 , V_277 , sizeof( struct V_30 ) ,
& V_23 -> V_263 ) ||
F_25 ( V_37 , V_278 , sizeof( struct V_30 ) ,
& V_23 -> V_69 ) ||
F_23 ( V_37 , V_279 , V_23 -> V_280 ) ||
F_24 ( V_37 , V_281 , V_23 -> V_282 ) ||
F_22 ( V_37 , V_283 , V_23 -> V_284 ) ||
F_22 ( V_37 , V_285 ,
V_23 -> V_286 ) ||
F_25 ( V_37 , V_209 , V_184 , V_23 -> V_211 ) )
return - V_85 ;
#ifdef F_90
if ( F_127 ( V_37 , V_186 , V_23 -> V_202 ) ||
F_23 ( V_37 , V_190 , V_23 -> V_287 ) ||
F_22 ( V_37 , V_203 , V_23 -> V_288 ) )
return - V_85 ;
#endif
#ifdef F_18
if ( F_22 ( V_37 , V_214 , V_23 -> V_94 ) ||
F_22 ( V_37 , V_215 , ! V_23 -> V_289 ) ||
F_22 ( V_37 , V_217 ,
V_23 -> V_219 ) ||
F_22 ( V_37 , V_220 , V_23 -> V_290 ) ||
F_22 ( V_37 , V_242 ,
V_23 -> V_244 ) ||
F_24 ( V_37 , V_222 ,
V_23 -> V_223 ) ||
F_24 ( V_37 , V_224 , V_23 -> V_225 ) ||
F_24 ( V_37 , V_226 ,
V_23 -> V_227 ) ||
F_24 ( V_37 , V_228 ,
V_23 -> V_229 ) ||
F_22 ( V_37 , V_245 ,
V_23 -> V_291 ) )
return - V_85 ;
#if F_117 ( V_247 )
if ( F_22 ( V_37 , V_248 ,
V_23 -> V_292 ) )
return - V_85 ;
#endif
V_266 = F_125 ( V_23 -> V_231 ) ;
if ( F_27 ( V_37 , V_230 , V_266 ,
V_269 ) )
return - V_85 ;
V_266 = F_125 ( V_23 -> V_233 ) ;
if ( F_27 ( V_37 , V_232 , V_266 ,
V_269 ) )
return - V_85 ;
V_266 = F_125 ( V_23 -> V_235 ) ;
if ( F_27 ( V_37 , V_234 , V_266 ,
V_269 ) )
return - V_85 ;
V_266 = F_125 ( V_23 -> V_237 ) ;
if ( F_27 ( V_37 , V_236 , V_266 ,
V_269 ) )
return - V_85 ;
V_266 = F_125 ( V_23 -> V_239 ) ;
if ( F_27 ( V_37 , V_238 , V_266 ,
V_269 ) )
return - V_85 ;
V_266 = F_125 ( V_23 -> V_241 ) ;
if ( F_27 ( V_37 , V_240 , V_266 ,
V_269 ) )
return - V_85 ;
#endif
#if F_117 ( V_250 )
if ( F_22 ( V_37 , V_251 ,
V_23 -> V_252 ? 1 : 0 ) ||
F_22 ( V_37 , V_253 ,
V_23 -> V_254 ? 1 : 0 ) ||
F_22 ( V_37 , V_255 ,
V_23 -> V_256 ? 1 : 0 ) )
return - V_85 ;
#endif
return 0 ;
}
static T_3 F_128 ( const struct V_18 * V_19 , int V_156 )
{
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
int V_293 = 0 ;
switch ( V_156 ) {
case V_294 :
V_23 = F_12 ( V_19 ) ;
V_2 = F_129 ( V_23 ) ;
break;
case V_295 :
V_21 = F_52 ( V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = V_21 -> V_23 ;
V_2 = F_130 ( V_21 ) ;
break;
default:
return 0 ;
}
if ( V_2 ) {
F_131 (v, &vg->vlan_list, vlist)
V_293 ++ ;
}
return V_293 * F_15 ( sizeof( struct V_296 ) ) +
F_15 ( sizeof( struct V_297 ) ) +
F_15 ( 0 ) ;
}
static int F_132 ( struct V_36 * V_37 ,
const struct V_18 * V_19 ,
int * V_298 , int V_156 )
{
struct V_131 * T_7 V_299 ;
struct V_20 * V_21 = NULL ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
struct V_131 * V_132 ;
int V_300 = 0 ;
switch ( V_156 ) {
case V_294 :
V_23 = F_12 ( V_19 ) ;
V_2 = F_129 ( V_23 ) ;
break;
case V_295 :
V_21 = F_52 ( V_19 ) ;
if ( ! V_21 )
return 0 ;
V_23 = V_21 -> V_23 ;
V_2 = F_130 ( V_21 ) ;
break;
default:
return - V_153 ;
}
V_132 = F_39 ( V_37 , V_301 ) ;
if ( ! V_132 )
return - V_85 ;
if ( V_2 ) {
T_2 V_10 ;
V_10 = F_2 ( V_2 ) ;
F_131 (v, &vg->vlan_list, vlist) {
struct V_296 V_302 ;
struct V_303 V_304 ;
if ( ++ V_300 < * V_298 )
continue;
memset ( & V_302 , 0 , sizeof( V_302 ) ) ;
V_302 . V_13 = V_5 -> V_13 ;
V_302 . V_9 = V_5 -> V_9 ;
if ( V_5 -> V_13 == V_10 )
V_302 . V_9 |= V_14 ;
F_133 ( V_5 , & V_304 ) ;
V_302 . V_305 = V_304 . V_305 ;
V_302 . V_306 = V_304 . V_306 ;
V_302 . V_307 = V_304 . V_307 ;
V_302 . V_308 = V_304 . V_308 ;
if ( F_25 ( V_37 , V_309 , sizeof( V_302 ) , & V_302 ) )
goto V_100;
}
}
#ifdef F_18
if ( ++ V_300 >= * V_298 ) {
T_7 = F_134 ( V_37 , V_310 ,
sizeof( struct V_297 ) ,
V_311 ) ;
if ( ! T_7 )
goto V_100;
F_135 ( V_23 , V_21 , F_65 ( T_7 ) ) ;
}
#endif
F_40 ( V_37 , V_132 ) ;
* V_298 = 0 ;
return 0 ;
V_100:
F_40 ( V_37 , V_132 ) ;
* V_298 = V_300 ;
return - V_85 ;
}
int T_8 F_136 ( void )
{
int V_102 ;
F_137 () ;
F_138 ( & V_312 ) ;
V_102 = F_139 ( & V_313 ) ;
if ( V_102 )
goto V_314;
return 0 ;
V_314:
F_140 ( & V_312 ) ;
F_141 () ;
return V_102 ;
}
void F_142 ( void )
{
F_141 () ;
F_140 ( & V_312 ) ;
F_143 ( & V_313 ) ;
}
