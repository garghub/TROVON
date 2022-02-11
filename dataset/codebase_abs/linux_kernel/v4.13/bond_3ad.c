static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
if ( V_2 -> V_3 == NULL )
return NULL ;
return F_2 ( V_2 -> V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
struct V_3 * V_6 ;
struct V_4 * V_7 ;
if ( V_5 == NULL )
return NULL ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
V_7 = V_6 ? & ( F_6 ( V_6 ) -> V_4 ) : NULL ;
F_7 () ;
return V_7 ;
}
static inline int F_8 ( struct V_4 * V_7 )
{
return ! F_9 ( V_7 -> V_8 . V_9 ) ;
}
static inline void F_10 ( struct V_2 * V_2 )
{
F_11 ( V_2 -> V_3 , V_10 ) ;
}
static inline void F_12 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
if ( ( V_3 -> V_11 == V_12 ) && F_13 ( V_3 ) )
F_14 ( V_3 , V_10 ) ;
}
static inline int F_15 ( struct V_2 * V_2 )
{
return F_16 ( V_2 -> V_3 ) ;
}
static inline T_1 F_17 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
if ( V_5 == NULL )
return V_13 ;
return V_5 -> V_14 . V_15 ;
}
static inline int F_18 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
if ( V_5 == NULL )
return 0 ;
return F_19 ( V_5 ) . V_16 ? 1 : 0 ;
}
static T_2 F_20 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_2 V_17 ;
if ( V_3 -> V_11 != V_12 )
V_17 = 0 ;
else {
switch ( V_3 -> V_17 ) {
case V_18 :
V_17 = V_19 ;
break;
case V_20 :
V_17 = V_21 ;
break;
case V_22 :
V_17 = V_23 ;
break;
case V_24 :
V_17 = V_25 ;
break;
case V_26 :
V_17 = V_27 ;
break;
case V_28 :
V_17 = V_29 ;
break;
case V_30 :
V_17 = V_31 ;
break;
case V_32 :
V_17 = V_33 ;
break;
case V_34 :
V_17 = V_35 ;
break;
case V_36 :
V_17 = V_37 ;
break;
case V_38 :
V_17 = V_39 ;
break;
case V_40 :
V_17 = V_41 ;
break;
case V_42 :
V_17 = V_43 ;
break;
default:
if ( V_3 -> V_17 != V_44 )
F_21 ( L_1 ,
V_3 -> V_5 -> V_45 -> V_46 ,
V_3 -> V_17 ,
V_2 -> V_47 ) ;
V_17 = 0 ;
break;
}
}
F_22 ( V_3 -> V_5 -> V_45 , L_2 ,
V_2 -> V_47 , V_17 ) ;
return V_17 ;
}
static T_3 F_23 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_48 = 0x0 ;
if ( V_3 -> V_11 == V_12 ) {
switch ( V_3 -> V_49 ) {
case V_50 :
V_48 = 0x1 ;
F_22 ( V_3 -> V_5 -> V_45 , L_3 ,
V_2 -> V_47 ) ;
break;
case V_51 :
default:
V_48 = 0x0 ;
F_22 ( V_3 -> V_5 -> V_45 , L_4 ,
V_2 -> V_47 ) ;
break;
}
}
return V_48 ;
}
static void F_24 ( struct V_2 * V_2 )
{
const struct V_1 * V_5 = F_2 ( V_2 -> V_3 ) ;
V_2 -> V_52 = F_19 ( V_5 ) . system . V_53 ;
V_2 -> V_54 = F_19 ( V_5 ) . system . V_55 ;
}
static T_2 F_25 ( T_2 V_56 , T_2 V_57 )
{
T_2 V_48 = 0 ;
switch ( V_56 ) {
case V_58 :
if ( V_57 )
V_48 = ( V_59 * V_60 ) ;
else
V_48 = ( V_61 * V_60 ) ;
break;
case V_62 :
V_48 = ( V_63 * V_60 ) ;
break;
case V_64 :
V_48 = ( V_57 * V_60 ) ;
break;
case V_65 :
V_48 = ( V_63 * V_60 ) ;
break;
case V_66 :
V_48 = ( V_67 * V_60 ) ;
break;
}
return V_48 ;
}
static void F_26 ( struct V_68 * V_68 , struct V_2 * V_2 )
{
if ( ( ( F_27 ( V_68 -> V_69 ) == V_2 -> V_47 ) &&
( F_27 ( V_68 -> V_70 ) == V_2 -> V_71 ) &&
F_28 ( & ( V_68 -> V_8 ) , & ( V_2 -> V_52 ) ) &&
( F_27 ( V_68 -> V_72 ) == V_2 -> V_54 ) &&
( F_27 ( V_68 -> V_73 ) == V_2 -> V_74 ) &&
( ( V_68 -> V_75 & V_76 ) == ( V_2 -> V_77 & V_76 ) ) ) ||
( ( V_68 -> V_78 & V_76 ) == 0 )
) {
V_2 -> V_79 |= V_80 ;
} else {
V_2 -> V_79 &= ~ V_80 ;
}
}
static void F_29 ( struct V_68 * V_68 , struct V_2 * V_2 )
{
if ( V_68 && V_2 ) {
struct V_81 * V_82 = & V_2 -> V_83 ;
F_26 ( V_68 , V_2 ) ;
V_82 -> V_84 = F_27 ( V_68 -> V_85 ) ;
V_82 -> V_86 = F_27 ( V_68 -> V_71 ) ;
V_82 -> system = V_68 -> V_52 ;
V_82 -> V_87 = F_27 ( V_68 -> V_54 ) ;
V_82 -> V_88 = F_27 ( V_68 -> V_89 ) ;
V_82 -> V_90 = V_68 -> V_78 ;
V_2 -> V_77 &= ~ V_91 ;
if ( ( V_2 -> V_79 & V_80 ) &&
( V_68 -> V_78 & V_92 ) ) {
V_82 -> V_90 |= V_92 ;
F_30 ( L_5 , V_2 -> V_3 -> V_45 -> V_46 ) ;
} else {
V_82 -> V_90 &= ~ V_92 ;
F_30 ( L_6 , V_2 -> V_3 -> V_45 -> V_46 ) ;
}
}
}
static void F_31 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_83 , & V_2 -> V_93 ,
sizeof( struct V_81 ) ) ;
V_2 -> V_77 |= V_91 ;
}
}
static void F_32 ( struct V_68 * V_68 , struct V_2 * V_2 )
{
if ( V_68 && V_2 ) {
const struct V_81 * V_82 = & V_2 -> V_83 ;
if ( F_27 ( V_68 -> V_85 ) != V_82 -> V_84 ||
F_27 ( V_68 -> V_71 ) != V_82 -> V_86 ||
! F_28 ( & V_68 -> V_52 , & V_82 -> system ) ||
F_27 ( V_68 -> V_54 ) != V_82 -> V_87 ||
F_27 ( V_68 -> V_89 ) != V_82 -> V_88 ||
( V_68 -> V_78 & V_76 ) != ( V_82 -> V_90 & V_76 ) ) {
V_2 -> V_79 &= ~ V_94 ;
}
}
}
static void F_33 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_81 * V_95 = & V_2 -> V_93 ;
const struct V_81 * V_96 = & V_2 -> V_83 ;
if ( V_95 -> V_84 != V_96 -> V_84 ||
V_95 -> V_86 != V_96 -> V_86 ||
! F_28 ( & V_95 -> system , & V_96 -> system ) ||
V_95 -> V_87 != V_96 -> V_87 ||
V_95 -> V_88 != V_96 -> V_88 ||
( V_95 -> V_90 & V_76 )
!= ( V_96 -> V_90 & V_76 ) ) {
V_2 -> V_79 &= ~ V_94 ;
}
}
}
static void F_34 ( struct V_68 * V_68 , struct V_2 * V_2 )
{
if ( V_68 && V_2 ) {
if ( ( F_27 ( V_68 -> V_69 ) != V_2 -> V_47 ) ||
( F_27 ( V_68 -> V_70 ) != V_2 -> V_71 ) ||
! F_28 ( & ( V_68 -> V_8 ) , & ( V_2 -> V_52 ) ) ||
( F_27 ( V_68 -> V_72 ) != V_2 -> V_54 ) ||
( F_27 ( V_68 -> V_73 ) != V_2 -> V_74 ) ||
( ( V_68 -> V_75 & V_97 ) != ( V_2 -> V_77 & V_97 ) ) ||
( ( V_68 -> V_75 & V_98 ) != ( V_2 -> V_77 & V_98 ) ) ||
( ( V_68 -> V_75 & V_92 ) != ( V_2 -> V_77 & V_92 ) ) ||
( ( V_68 -> V_75 & V_76 ) != ( V_2 -> V_77 & V_76 ) )
) {
V_2 -> V_99 = true ;
}
}
}
static int F_35 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_48 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_100 ;
V_2 ;
V_2 = V_2 -> V_101 ) {
if ( ! ( V_2 -> V_79 & V_102 ) ) {
V_48 = 0 ;
break;
}
}
}
return V_48 ;
}
static void F_36 ( struct V_4 * V_4 , int V_103 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_100 ; V_2 ;
V_2 = V_2 -> V_101 ) {
if ( V_103 )
V_2 -> V_79 |= V_104 ;
else
V_2 -> V_79 &= ~ V_104 ;
}
}
static int F_37 ( struct V_4 * V_7 )
{
struct V_2 * V_2 ;
int V_105 = 0 ;
for ( V_2 = V_7 -> V_100 ; V_2 ;
V_2 = V_2 -> V_101 ) {
if ( V_2 -> V_106 )
V_105 ++ ;
}
return V_105 ;
}
static T_1 F_38 ( struct V_4 * V_4 )
{
int V_107 = F_37 ( V_4 ) ;
T_1 V_108 = 0 ;
if ( V_107 ) {
switch ( F_20 ( V_4 -> V_100 ) ) {
case V_109 :
V_108 = V_107 ;
break;
case V_19 :
V_108 = V_107 * 10 ;
break;
case V_21 :
V_108 = V_107 * 100 ;
break;
case V_23 :
V_108 = V_107 * 1000 ;
break;
case V_25 :
V_108 = V_107 * 2500 ;
break;
case V_27 :
V_108 = V_107 * 5000 ;
break;
case V_29 :
V_108 = V_107 * 10000 ;
break;
case V_31 :
V_108 = V_107 * 14000 ;
break;
case V_33 :
V_108 = V_107 * 20000 ;
break;
case V_35 :
V_108 = V_107 * 25000 ;
break;
case V_37 :
V_108 = V_107 * 40000 ;
break;
case V_39 :
V_108 = V_107 * 50000 ;
break;
case V_41 :
V_108 = V_107 * 56000 ;
break;
case V_43 :
V_108 = V_107 * 100000 ;
break;
default:
V_108 = 0 ;
}
}
return V_108 ;
}
static struct V_4 * F_39 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_110 * V_111 ;
struct V_3 * V_3 ;
F_40 (bond, slave, iter)
if ( F_6 ( V_3 ) -> V_4 . V_112 )
return & ( F_6 ( V_3 ) -> V_4 ) ;
return NULL ;
}
static inline void F_41 ( struct V_2 * V_2 )
{
struct V_68 * V_68 = & V_2 -> V_68 ;
const struct V_81 * V_82 = & V_2 -> V_83 ;
V_68 -> V_54 = F_42 ( V_2 -> V_54 ) ;
V_68 -> V_52 = V_2 -> V_52 ;
V_68 -> V_89 = F_42 ( V_2 -> V_74 ) ;
V_68 -> V_71 = F_42 ( V_2 -> V_71 ) ;
V_68 -> V_85 = F_42 ( V_2 -> V_47 ) ;
V_68 -> V_78 = V_2 -> V_77 ;
F_30 ( L_7 ,
V_2 -> V_3 -> V_45 -> V_46 , V_2 -> V_77 ) ;
V_68 -> V_72 = F_42 ( V_82 -> V_87 ) ;
V_68 -> V_8 = V_82 -> system ;
V_68 -> V_73 = F_42 ( V_82 -> V_88 ) ;
V_68 -> V_70 = F_42 ( V_82 -> V_86 ) ;
V_68 -> V_69 = F_42 ( V_82 -> V_84 ) ;
V_68 -> V_75 = V_82 -> V_90 ;
}
static int F_43 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_113 * V_114 ;
struct V_115 * V_115 ;
int V_116 = sizeof( struct V_115 ) ;
V_114 = F_44 ( V_116 ) ;
if ( ! V_114 )
return - V_117 ;
V_114 -> V_45 = V_3 -> V_45 ;
F_45 ( V_114 ) ;
V_114 -> V_118 = V_114 -> V_119 + V_120 ;
V_114 -> V_121 = V_122 ;
V_114 -> V_123 = V_124 ;
V_115 = F_46 ( V_114 , V_116 ) ;
F_47 ( V_115 -> V_125 . V_126 , V_127 ) ;
F_47 ( V_115 -> V_125 . V_128 , V_3 -> V_129 ) ;
V_115 -> V_125 . V_130 = V_122 ;
V_115 -> V_68 = V_2 -> V_68 ;
F_48 ( V_114 ) ;
return 0 ;
}
static int F_49 ( struct V_2 * V_2 , struct V_131 * V_132 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_113 * V_114 ;
struct V_133 * V_134 ;
int V_116 = sizeof( struct V_133 ) ;
V_114 = F_44 ( V_116 + 16 ) ;
if ( ! V_114 )
return - V_117 ;
F_50 ( V_114 , 16 ) ;
V_114 -> V_45 = V_3 -> V_45 ;
F_45 ( V_114 ) ;
V_114 -> V_118 = V_114 -> V_119 + V_120 ;
V_114 -> V_121 = V_122 ;
V_134 = F_46 ( V_114 , V_116 ) ;
F_47 ( V_134 -> V_125 . V_126 , V_127 ) ;
F_47 ( V_134 -> V_125 . V_128 , V_3 -> V_129 ) ;
V_134 -> V_125 . V_130 = V_122 ;
V_134 -> V_132 = * V_132 ;
F_48 ( V_114 ) ;
return 0 ;
}
static void F_51 ( struct V_2 * V_2 , bool * V_135 )
{
T_4 V_136 ;
V_136 = V_2 -> V_137 ;
if ( V_2 -> V_79 & V_138 ) {
V_2 -> V_137 = V_139 ;
} else {
switch ( V_2 -> V_137 ) {
case V_139 :
if ( ( V_2 -> V_79 & V_94 )
|| ( V_2 -> V_79 & V_140 ) )
V_2 -> V_137 = V_141 ;
break;
case V_141 :
if ( ! ( V_2 -> V_79 & V_94 ) ) {
V_2 -> V_79 &= ~ V_102 ;
F_36 ( V_2 -> V_4 , F_35 ( V_2 -> V_4 ) ) ;
V_2 -> V_137 = V_139 ;
break;
}
if ( V_2 -> V_142
&& ! ( -- V_2 -> V_142 ) )
V_2 -> V_79 |= V_102 ;
F_36 ( V_2 -> V_4 , F_35 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_79 & V_104 )
&& ! V_2 -> V_142 )
V_2 -> V_137 = V_143 ;
break;
case V_143 :
if ( ( V_2 -> V_79 & V_94 ) &&
( V_2 -> V_83 . V_90 & V_92 ) &&
! F_18 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_112 )
V_2 -> V_137 =
V_144 ;
} else if ( ! ( V_2 -> V_79 & V_94 ) ||
( V_2 -> V_79 & V_140 ) ) {
V_2 -> V_79 &= ~ V_102 ;
F_36 ( V_2 -> V_4 , F_35 ( V_2 -> V_4 ) ) ;
V_2 -> V_137 = V_139 ;
} else if ( V_2 -> V_4 -> V_112 ) {
V_2 -> V_77 |=
V_92 ;
}
break;
case V_144 :
if ( ! ( V_2 -> V_79 & V_94 ) ||
( V_2 -> V_79 & V_140 ) ||
! ( V_2 -> V_83 . V_90 & V_92 ) ||
! ( V_2 -> V_77 & V_92 ) ) {
V_2 -> V_137 = V_143 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_112 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_137 != V_136 ) {
F_30 ( L_8 ,
V_2 -> V_47 ,
V_2 -> V_3 -> V_45 -> V_46 ,
V_136 ,
V_2 -> V_137 ) ;
switch ( V_2 -> V_137 ) {
case V_139 :
V_2 -> V_77 &= ~ V_92 ;
F_52 ( V_2 ,
V_135 ) ;
V_2 -> V_77 &= ~ V_145 ;
V_2 -> V_77 &= ~ V_146 ;
V_2 -> V_99 = true ;
break;
case V_141 :
V_2 -> V_142 = F_25 ( V_66 , 0 ) ;
break;
case V_143 :
if ( V_2 -> V_4 -> V_112 )
V_2 -> V_77 |=
V_92 ;
else
V_2 -> V_77 &=
~ V_92 ;
V_2 -> V_77 &= ~ V_145 ;
V_2 -> V_77 &= ~ V_146 ;
F_52 ( V_2 ,
V_135 ) ;
V_2 -> V_99 = true ;
break;
case V_144 :
V_2 -> V_77 |= V_145 ;
V_2 -> V_77 |= V_146 ;
V_2 -> V_77 |= V_92 ;
F_53 ( V_2 ,
V_135 ) ;
V_2 -> V_99 = true ;
break;
default:
break;
}
}
}
static void F_54 ( struct V_68 * V_68 , struct V_2 * V_2 )
{
T_5 V_136 ;
V_136 = V_2 -> V_147 ;
if ( V_2 -> V_79 & V_138 ) {
V_2 -> V_147 = V_148 ;
V_2 -> V_79 |= V_149 ;
} else if ( ! ( V_2 -> V_79 & V_138 ) && ! V_2 -> V_106 )
V_2 -> V_147 = V_150 ;
else if ( V_68 && ( ( V_2 -> V_147 == V_151 ) ||
( V_2 -> V_147 == V_152 ) ||
( V_2 -> V_147 == V_153 ) ) ) {
if ( V_2 -> V_147 != V_153 )
V_2 -> V_79 |= V_149 ;
V_2 -> V_154 = 0 ;
V_2 -> V_147 = V_153 ;
} else {
if ( V_2 -> V_154 &&
! ( -- V_2 -> V_154 ) ) {
switch ( V_2 -> V_147 ) {
case V_151 :
V_2 -> V_147 = V_152 ;
break;
case V_153 :
V_2 -> V_147 = V_151 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_147 ) {
case V_150 :
if ( V_2 -> V_106 &&
( V_2 -> V_79 & V_155 ) )
V_2 -> V_147 = V_151 ;
else if ( V_2 -> V_106
&& ( ( V_2 -> V_79
& V_155 ) == 0 ) )
V_2 -> V_147 = V_156 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_147 != V_136 ) || ( V_68 ) ) {
F_30 ( L_9 ,
V_2 -> V_47 ,
V_2 -> V_3 -> V_45 -> V_46 ,
V_136 ,
V_2 -> V_147 ) ;
switch ( V_2 -> V_147 ) {
case V_148 :
if ( ! ( V_2 -> V_74 & V_157 ) )
V_2 -> V_79 &= ~ V_155 ;
else
V_2 -> V_79 |= V_155 ;
V_2 -> V_79 &= ~ V_94 ;
F_31 ( V_2 ) ;
V_2 -> V_77 &= ~ V_158 ;
V_2 -> V_147 = V_150 ;
case V_150 :
V_2 -> V_79 &= ~ V_80 ;
break;
case V_156 :
V_2 -> V_79 &= ~ V_94 ;
F_31 ( V_2 ) ;
V_2 -> V_83 . V_90 &= ~ V_76 ;
V_2 -> V_79 |= V_80 ;
V_2 -> V_77 &= ~ V_158 ;
break;
case V_151 :
V_2 -> V_83 . V_90 &= ~ V_92 ;
V_2 -> V_79 &= ~ V_80 ;
V_2 -> V_83 . V_90 |= V_98 ;
V_2 -> V_83 . V_90 |= V_97 ;
V_2 -> V_154 = F_25 ( V_58 , ( T_2 ) ( V_159 ) ) ;
V_2 -> V_77 |= V_158 ;
V_2 -> V_79 |= V_149 ;
break;
case V_152 :
F_33 ( V_2 ) ;
F_31 ( V_2 ) ;
V_2 -> V_79 |= V_80 ;
V_2 -> V_77 &= ~ V_158 ;
break;
case V_153 :
if ( F_28 ( & ( V_68 -> V_52 ) ,
& ( V_2 -> V_52 ) ) ) {
F_55 ( V_2 -> V_3 -> V_5 -> V_45 , L_10
L_11 ,
V_2 -> V_3 -> V_45 -> V_46 ) ;
return;
}
F_32 ( V_68 , V_2 ) ;
F_34 ( V_68 , V_2 ) ;
F_29 ( V_68 , V_2 ) ;
V_2 -> V_154 = F_25 ( V_58 , ( T_2 ) ( V_2 -> V_77 & V_98 ) ) ;
V_2 -> V_77 &= ~ V_158 ;
break;
default:
break;
}
}
}
static void F_56 ( struct V_2 * V_2 )
{
if ( V_2 -> V_79 & V_149 ) {
V_2 -> V_79 &= ~ V_149 ;
V_2 -> V_160 = V_161 ;
V_2 -> V_162 = V_161 ;
V_2 -> V_163 =
F_25 ( V_62 , 0 ) ;
V_2 -> V_164 =
F_25 ( V_65 , 0 ) ;
return;
}
if ( V_2 -> V_163 &&
! ( -- V_2 -> V_163 ) &&
V_2 -> V_160 == V_161 ) {
if ( V_2 -> V_77 & V_92 ) {
V_2 -> V_160 = V_165 ;
} else {
V_2 -> V_166 ++ ;
V_2 -> V_160 = V_167 ;
}
}
if ( V_2 -> V_164 &&
! ( -- V_2 -> V_164 ) &&
V_2 -> V_162 == V_161 ) {
if ( V_2 -> V_83 . V_90 & V_92 ) {
V_2 -> V_162 = V_165 ;
} else {
V_2 -> V_168 ++ ;
V_2 -> V_162 = V_167 ;
}
}
}
static void F_57 ( struct V_2 * V_2 )
{
if ( V_2 -> V_169 && ! ( -- V_2 -> V_169 ) ) {
if ( V_2 -> V_99 && ( V_2 -> V_79 & V_155 ) ) {
F_41 ( V_2 ) ;
if ( F_43 ( V_2 ) >= 0 ) {
F_30 ( L_12 ,
V_2 -> V_47 ) ;
V_2 -> V_99 = false ;
}
}
V_2 -> V_169 = V_60 / V_170 ;
}
}
static void F_58 ( struct V_2 * V_2 )
{
T_6 V_136 ;
V_136 = V_2 -> V_171 ;
if ( ( ( V_2 -> V_79 & V_138 ) || ! ( V_2 -> V_79 & V_155 ) || ! V_2 -> V_106 ) ||
( ! ( V_2 -> V_77 & V_97 ) && ! ( V_2 -> V_83 . V_90 & V_97 ) )
) {
V_2 -> V_171 = V_172 ;
}
else if ( V_2 -> V_173 ) {
if ( ! ( -- V_2 -> V_173 ) ) {
V_2 -> V_171 = V_174 ;
} else {
switch ( V_2 -> V_171 ) {
case V_175 :
if ( ! ( V_2 -> V_83 . V_90
& V_98 ) )
V_2 -> V_171 = V_176 ;
break;
case V_176 :
if ( ( V_2 -> V_83 . V_90 & V_98 ) ) {
V_2 -> V_173 = 0 ;
V_2 -> V_171 = V_174 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_171 ) {
case V_172 :
V_2 -> V_171 = V_175 ;
break;
case V_174 :
if ( ! ( V_2 -> V_83 . V_90 &
V_98 ) )
V_2 -> V_171 = V_176 ;
else
V_2 -> V_171 = V_175 ;
break;
default:
break;
}
}
if ( V_2 -> V_171 != V_136 ) {
F_30 ( L_13 ,
V_2 -> V_47 , V_136 ,
V_2 -> V_171 ) ;
switch ( V_2 -> V_171 ) {
case V_172 :
V_2 -> V_173 = 0 ;
break;
case V_175 :
V_2 -> V_173 = F_25 ( V_64 , ( T_2 ) ( V_177 ) ) - 1 ;
break;
case V_176 :
V_2 -> V_173 = F_25 ( V_64 , ( T_2 ) ( V_178 ) ) - 1 ;
break;
case V_174 :
V_2 -> V_99 = true ;
break;
default:
break;
}
}
}
static void F_59 ( struct V_2 * V_2 , bool * V_135 )
{
struct V_4 * V_4 , * V_179 = NULL , * V_180 ;
struct V_2 * V_181 = NULL , * V_182 ;
struct V_110 * V_111 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_183 = 0 ;
if ( V_2 -> V_79 & V_94 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_180 = V_2 -> V_4 ;
for ( V_182 = V_180 -> V_100 ; V_182 ;
V_181 = V_182 ,
V_182 = V_182 -> V_101 ) {
if ( V_182 == V_2 ) {
V_180 -> V_184 -- ;
if ( ! V_181 ) {
V_180 -> V_100 =
V_2 -> V_101 ;
} else {
V_181 -> V_101 =
V_2 -> V_101 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_101 = NULL ;
V_2 -> V_185 = 0 ;
F_22 ( V_5 -> V_45 , L_14 ,
V_2 -> V_47 ,
V_180 -> V_186 ) ;
if ( ! V_180 -> V_100 )
F_60 ( V_180 ) ;
break;
}
}
if ( ! V_182 ) {
F_61 ( L_15 ,
V_2 -> V_3 -> V_5 -> V_45 -> V_46 ,
V_2 -> V_47 ,
V_2 -> V_3 -> V_45 -> V_46 ,
V_2 -> V_4 -> V_186 ) ;
}
}
F_62 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_100 ) {
if ( ! V_179 )
V_179 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_187 == V_2 -> V_74 ) &&
F_28 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_83 . system ) ) &&
( V_4 -> V_72 == V_2 -> V_83 . V_87 ) &&
( V_4 -> V_188 == V_2 -> V_83 . V_88 )
) &&
( ( ! F_28 ( & ( V_2 -> V_83 . system ) , & ( V_189 ) ) &&
! V_4 -> V_190 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_185 =
V_2 -> V_4 -> V_186 ;
V_2 -> V_101 = V_4 -> V_100 ;
V_2 -> V_4 -> V_184 ++ ;
V_4 -> V_100 = V_2 ;
F_22 ( V_5 -> V_45 , L_16 ,
V_2 -> V_47 ,
V_2 -> V_4 -> V_186 ) ;
V_2 -> V_79 |= V_94 ;
V_183 = 1 ;
break;
}
}
if ( ! V_183 ) {
if ( V_179 ) {
V_2 -> V_4 = V_179 ;
V_2 -> V_185 =
V_2 -> V_4 -> V_186 ;
if ( V_2 -> V_74 & V_157 )
V_2 -> V_4 -> V_190 = false ;
else
V_2 -> V_4 -> V_190 = true ;
V_2 -> V_4 -> V_191 =
V_2 -> V_192 ;
V_2 -> V_4 -> V_187 =
V_2 -> V_74 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_83 . system ;
V_2 -> V_4 -> V_72 =
V_2 -> V_83 . V_87 ;
V_2 -> V_4 -> V_188 = V_2 -> V_83 . V_88 ;
V_2 -> V_4 -> V_193 = 1 ;
V_2 -> V_4 -> V_194 = 1 ;
V_2 -> V_4 -> V_100 = V_2 ;
V_2 -> V_4 -> V_184 ++ ;
V_2 -> V_79 |= V_94 ;
F_22 ( V_5 -> V_45 , L_17 ,
V_2 -> V_47 ,
V_2 -> V_4 -> V_186 ) ;
} else {
F_55 ( V_5 -> V_45 , L_18 ,
V_2 -> V_47 , V_2 -> V_3 -> V_45 -> V_46 ) ;
}
}
F_36 ( V_2 -> V_4 ,
F_35 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_63 ( V_4 , V_135 ) ;
if ( ! V_2 -> V_4 -> V_112 )
V_2 -> V_77 &= ~ V_92 ;
}
static struct V_4 * F_64 ( struct V_4 * V_195 ,
struct V_4 * V_196 )
{
if ( ! V_195 )
return V_196 ;
if ( ! V_196 -> V_190 && V_195 -> V_190 )
return V_196 ;
if ( V_196 -> V_190 && ! V_195 -> V_190 )
return V_195 ;
if ( F_8 ( V_196 ) && ! F_8 ( V_195 ) )
return V_196 ;
if ( ! F_8 ( V_196 ) && F_8 ( V_195 ) )
return V_195 ;
switch ( F_17 ( V_196 -> V_100 ) ) {
case V_197 :
if ( F_37 ( V_196 ) > F_37 ( V_195 ) )
return V_196 ;
if ( F_37 ( V_196 ) < F_37 ( V_195 ) )
return V_195 ;
case V_13 :
case V_198 :
if ( F_38 ( V_196 ) > F_38 ( V_195 ) )
return V_196 ;
break;
default:
F_61 ( L_19 ,
V_196 -> V_3 -> V_5 -> V_45 -> V_46 ,
F_17 ( V_196 -> V_100 ) ) ;
break;
}
return V_195 ;
}
static int F_65 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_100 ;
if ( ! V_2 )
return 0 ;
for ( V_2 = V_7 -> V_100 ; V_2 ;
V_2 = V_2 -> V_101 ) {
if ( F_66 ( V_2 -> V_3 -> V_45 ) &&
F_67 ( V_2 -> V_3 -> V_45 ) )
return 1 ;
}
return 0 ;
}
static void F_63 ( struct V_4 * V_7 ,
bool * V_135 )
{
struct V_4 * V_195 , * V_105 , * V_199 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_110 * V_111 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_199 = V_7 ;
V_105 = F_39 ( V_7 ) ;
V_195 = ( V_105 && F_65 ( V_105 ) ) ? V_105 : NULL ;
F_40 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_112 = 0 ;
if ( F_37 ( V_7 ) && F_65 ( V_7 ) )
V_195 = F_64 ( V_195 , V_7 ) ;
}
if ( V_195 &&
F_17 ( V_195 -> V_100 ) == V_13 ) {
if ( V_105 && V_105 -> V_100 &&
F_37 ( V_105 ) &&
( F_8 ( V_105 ) ||
( ! F_8 ( V_105 ) &&
! F_8 ( V_195 ) ) ) ) {
if ( ! ( ! V_105 -> V_187 &&
V_195 -> V_187 ) ) {
V_195 = NULL ;
V_105 -> V_112 = 1 ;
}
}
}
if ( V_195 && ( V_195 == V_105 ) ) {
V_195 = NULL ;
V_105 -> V_112 = 1 ;
}
if ( V_195 ) {
F_22 ( V_5 -> V_45 , L_20 ,
V_195 -> V_186 , V_195 -> V_184 ,
V_195 -> V_187 ,
V_195 -> V_188 ,
V_195 -> V_190 , V_195 -> V_112 ) ;
F_22 ( V_5 -> V_45 , L_21 ,
V_195 -> V_100 , V_195 -> V_3 ,
V_195 -> V_3 ? V_195 -> V_3 -> V_45 -> V_46 : L_22 ) ;
F_40 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_22 ( V_5 -> V_45 , L_23 ,
V_7 -> V_186 , V_7 -> V_184 ,
V_7 -> V_187 ,
V_7 -> V_188 ,
V_7 -> V_190 , V_7 -> V_112 ) ;
}
if ( V_195 -> V_190 ) {
F_61 ( L_24 ,
V_195 -> V_3 ?
V_195 -> V_3 -> V_5 -> V_45 -> V_46 : L_22 ) ;
}
V_195 -> V_112 = 1 ;
F_22 ( V_5 -> V_45 , L_25 ,
V_195 -> V_186 ) ;
F_22 ( V_5 -> V_45 , L_23 ,
V_195 -> V_186 , V_195 -> V_184 ,
V_195 -> V_187 ,
V_195 -> V_188 ,
V_195 -> V_190 , V_195 -> V_112 ) ;
if ( V_105 ) {
for ( V_2 = V_105 -> V_100 ; V_2 ;
V_2 = V_2 -> V_101 ) {
F_10 ( V_2 ) ;
}
}
* V_135 = true ;
}
V_105 = F_39 ( V_199 ) ;
if ( V_105 ) {
if ( ! F_8 ( V_105 ) ) {
for ( V_2 = V_105 -> V_100 ; V_2 ;
V_2 = V_2 -> V_101 ) {
F_12 ( V_2 ) ;
}
}
}
F_7 () ;
F_68 ( V_5 ) ;
}
static void F_60 ( struct V_4 * V_4 )
{
if ( V_4 ) {
V_4 -> V_190 = false ;
V_4 -> V_191 = 0 ;
V_4 -> V_187 = 0 ;
F_69 ( V_4 -> V_8 . V_9 ) ;
V_4 -> V_72 = 0 ;
V_4 -> V_188 = 0 ;
V_4 -> V_193 = 0 ;
V_4 -> V_194 = 0 ;
V_4 -> V_100 = NULL ;
V_4 -> V_112 = 0 ;
V_4 -> V_184 = 0 ;
F_30 ( L_26 ,
V_4 -> V_186 ) ;
}
}
static void F_70 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_60 ( V_4 ) ;
F_69 ( V_4 -> V_200 . V_9 ) ;
V_4 -> V_186 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_71 ( struct V_2 * V_2 , int V_201 )
{
static const struct V_81 V_202 = {
. V_87 = 0xffff ,
. V_88 = 1 ,
. V_84 = 1 ,
. V_86 = 0xff ,
. V_90 = 1 ,
} ;
static const struct V_68 V_68 = {
. V_203 = 0x01 ,
. V_204 = 0x01 ,
. V_205 = 0x01 ,
. V_206 = 0x14 ,
. V_207 = 0x02 ,
. V_208 = 0x14 ,
. V_209 = 0x03 ,
. V_210 = 0x10 ,
. V_211 = F_42 ( V_212 ) ,
} ;
if ( V_2 ) {
V_2 -> V_71 = 0xff ;
V_2 -> V_185 = 0 ;
V_2 -> V_99 = false ;
V_2 -> V_213 = V_76 |
V_97 ;
V_2 -> V_77 = V_76 |
V_97 ;
if ( V_201 )
V_2 -> V_77 |= V_98 ;
memcpy ( & V_2 -> V_93 , & V_202 , sizeof( V_202 ) ) ;
memcpy ( & V_2 -> V_83 , & V_202 , sizeof( V_202 ) ) ;
V_2 -> V_106 = true ;
V_2 -> V_79 = V_138 | V_155 ;
V_2 -> V_147 = 0 ;
V_2 -> V_154 = 0 ;
V_2 -> V_171 = 0 ;
V_2 -> V_173 = 0 ;
V_2 -> V_137 = 0 ;
V_2 -> V_142 = 0 ;
V_2 -> V_214 = 0 ;
V_2 -> V_4 = NULL ;
V_2 -> V_101 = NULL ;
V_2 -> V_215 = 0 ;
V_2 -> V_163 = 0 ;
V_2 -> V_160 = 0 ;
V_2 -> V_166 = 0 ;
V_2 -> V_164 = 0 ;
V_2 -> V_162 = 0 ;
V_2 -> V_168 = 0 ;
memcpy ( & V_2 -> V_68 , & V_68 , sizeof( V_68 ) ) ;
}
}
static void F_53 ( struct V_2 * V_2 ,
bool * V_135 )
{
if ( V_2 -> V_4 -> V_112 ) {
F_30 ( L_27 ,
V_2 -> V_47 ,
V_2 -> V_4 -> V_186 ) ;
F_12 ( V_2 ) ;
* V_135 = true ;
}
}
static void F_52 ( struct V_2 * V_2 ,
bool * V_135 )
{
if ( V_2 -> V_4 &&
! F_28 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_189 ) ) ) {
F_30 ( L_28 ,
V_2 -> V_47 ,
V_2 -> V_4 -> V_186 ) ;
F_10 ( V_2 ) ;
* V_135 = true ;
}
}
static void F_72 ( struct V_131 * V_216 ,
struct V_2 * V_2 )
{
struct V_131 V_132 ;
memcpy ( & V_132 , V_216 , sizeof( struct V_131 ) ) ;
V_132 . V_217 = V_218 ;
if ( F_49 ( V_2 , & V_132 ) >= 0 ) {
F_30 ( L_29 ,
V_2 -> V_47 ) ;
}
}
static void F_73 ( struct V_131 * V_132 ,
struct V_2 * V_2 )
{
}
void F_74 ( struct V_1 * V_5 , int V_219 )
{
F_19 ( V_5 ) . V_16 = V_219 ;
}
void F_75 ( struct V_1 * V_5 , T_2 V_220 )
{
if ( ! F_28 ( & ( F_19 ( V_5 ) . system . V_53 ) ,
V_5 -> V_45 -> V_221 ) ) {
F_19 ( V_5 ) . V_186 = 0 ;
F_19 ( V_5 ) . system . V_55 =
V_5 -> V_14 . V_222 ;
if ( F_9 ( V_5 -> V_14 . V_223 ) )
F_19 ( V_5 ) . system . V_53 =
* ( (struct V_224 * ) V_5 -> V_45 -> V_221 ) ;
else
F_19 ( V_5 ) . system . V_53 =
* ( (struct V_224 * ) V_5 -> V_14 . V_223 ) ;
V_60 = V_220 ;
F_74 ( V_5 ,
V_225 *
V_60 ) ;
}
}
void F_76 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) -> V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_71 ( V_2 , V_5 -> V_14 . V_201 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_47 = F_6 ( V_3 ) -> V_226 ;
V_2 -> V_192 = V_5 -> V_14 . V_227 << 6 ;
F_77 ( V_2 , false ) ;
F_24 ( V_2 ) ;
V_2 -> V_169 = V_60 / V_170 ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_70 ( V_4 ) ;
V_4 -> V_200 = * ( (struct V_224 * ) V_5 -> V_45 -> V_221 ) ;
V_4 -> V_186 = ++ F_19 ( V_5 ) . V_186 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_112 = 0 ;
V_4 -> V_184 = 0 ;
}
}
void F_78 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_228 , * V_229 ;
struct V_4 * V_4 , * V_230 , * V_180 ;
int V_231 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_232 ;
struct V_110 * V_111 ;
bool V_233 ;
F_79 ( & V_5 -> V_234 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_80 ( V_5 -> V_45 , L_30 ,
V_3 -> V_45 -> V_46 ) ;
goto V_235;
}
F_22 ( V_5 -> V_45 , L_31 ,
V_4 -> V_186 ) ;
V_2 -> V_77 &= ~ V_76 ;
F_41 ( V_2 ) ;
F_43 ( V_2 ) ;
if ( V_4 -> V_100 ) {
if ( ( V_4 -> V_100 != V_2 ) ||
( V_4 -> V_100 -> V_101 ) ) {
F_62 (bond, slave_iter, iter) {
V_230 = & ( F_6 ( V_232 ) -> V_4 ) ;
if ( ! V_230 -> V_100 ||
( ( V_230 -> V_100 == V_2 ) &&
! V_230 -> V_100 -> V_101 ) )
break;
}
if ( ! V_232 )
V_230 = NULL ;
if ( ( V_230 ) && ( ( ! V_230 -> V_100 ) || ( ( V_230 -> V_100 == V_2 ) && ! V_230 -> V_100 -> V_101 ) ) ) {
F_22 ( V_5 -> V_45 , L_32 ,
V_4 -> V_186 ,
V_230 -> V_186 ) ;
if ( ( V_230 -> V_100 == V_2 ) &&
V_230 -> V_112 ) {
F_81 ( V_5 -> V_45 , L_33 ) ;
V_231 = 1 ;
}
V_230 -> V_190 = V_4 -> V_190 ;
V_230 -> V_191 = V_4 -> V_191 ;
V_230 -> V_187 = V_4 -> V_187 ;
V_230 -> V_8 = V_4 -> V_8 ;
V_230 -> V_72 = V_4 -> V_72 ;
V_230 -> V_188 = V_4 -> V_188 ;
V_230 -> V_193 = V_4 -> V_193 ;
V_230 -> V_194 = V_4 -> V_194 ;
V_230 -> V_100 = V_4 -> V_100 ;
V_230 -> V_112 = V_4 -> V_112 ;
V_230 -> V_184 = V_4 -> V_184 ;
for ( V_229 = V_4 -> V_100 ; V_229 ;
V_229 = V_229 -> V_101 ) {
V_229 -> V_4 = V_230 ;
V_229 -> V_185 = V_230 -> V_186 ;
}
F_60 ( V_4 ) ;
if ( V_231 )
F_63 ( F_3 ( V_2 ) ,
& V_233 ) ;
} else {
F_80 ( V_5 -> V_45 , L_34 ) ;
}
} else {
V_231 = V_4 -> V_112 ;
F_60 ( V_4 ) ;
if ( V_231 ) {
F_81 ( V_5 -> V_45 , L_33 ) ;
V_180 = F_3 ( V_2 ) ;
if ( V_180 )
F_63 ( V_180 ,
& V_233 ) ;
}
}
}
F_22 ( V_5 -> V_45 , L_35 , V_2 -> V_47 ) ;
F_62 (bond, slave_iter, iter) {
V_180 = & ( F_6 ( V_232 ) -> V_4 ) ;
V_228 = NULL ;
for ( V_229 = V_180 -> V_100 ; V_229 ;
V_228 = V_229 ,
V_229 = V_229 -> V_101 ) {
if ( V_229 == V_2 ) {
if ( V_228 )
V_228 -> V_101 = V_229 -> V_101 ;
else
V_180 -> V_100 = V_229 -> V_101 ;
V_180 -> V_184 -- ;
if ( F_37 ( V_180 ) == 0 ) {
V_231 = V_180 -> V_112 ;
F_60 ( V_180 ) ;
if ( V_231 ) {
F_81 ( V_5 -> V_45 , L_33 ) ;
F_63 ( F_3 ( V_2 ) ,
& V_233 ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
V_235:
F_82 ( & V_5 -> V_234 ) ;
}
void F_83 ( struct V_1 * V_5 )
{
struct V_110 * V_111 ;
struct V_3 * V_3 ;
F_84 () ;
F_19 ( V_5 ) . system . V_55 = V_5 -> V_14 . V_222 ;
if ( F_9 ( V_5 -> V_14 . V_223 ) )
F_19 ( V_5 ) . system . V_53 =
* ( (struct V_224 * ) V_5 -> V_45 -> V_221 ) ;
else
F_19 ( V_5 ) . system . V_53 =
* ( (struct V_224 * ) V_5 -> V_14 . V_223 ) ;
F_79 ( & V_5 -> V_234 ) ;
F_62 (bond, slave, iter) {
struct V_2 * V_2 = & ( F_6 ( V_3 ) ) -> V_2 ;
F_24 ( V_2 ) ;
V_2 -> V_99 = true ;
}
F_82 ( & V_5 -> V_234 ) ;
}
void F_85 ( struct V_236 * V_237 )
{
struct V_1 * V_5 = F_86 ( V_237 , struct V_1 ,
V_238 . V_237 ) ;
struct V_4 * V_4 ;
struct V_110 * V_111 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_239 = V_10 ;
bool V_135 = false ;
F_79 ( & V_5 -> V_234 ) ;
F_4 () ;
if ( ! F_87 ( V_5 ) )
goto V_240;
if ( F_19 ( V_5 ) . V_16 &&
! ( -- F_19 ( V_5 ) . V_16 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) -> V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_61 ( L_36 ,
V_5 -> V_45 -> V_46 ) ;
goto V_240;
}
V_4 = F_3 ( V_2 ) ;
F_63 ( V_4 , & V_135 ) ;
}
F_68 ( V_5 ) ;
}
F_40 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_37 ,
V_5 -> V_45 -> V_46 ) ;
goto V_240;
}
F_54 ( NULL , V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 , & V_135 ) ;
F_51 ( V_2 , & V_135 ) ;
F_57 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_79 & V_138 )
V_2 -> V_79 &= ~ V_138 ;
}
V_240:
F_40 (bond, slave, iter) {
if ( V_3 -> V_241 ) {
V_239 = V_242 ;
break;
}
}
F_7 () ;
F_82 ( & V_5 -> V_234 ) ;
if ( V_135 )
F_88 ( V_5 , 0 ) ;
if ( V_239 && F_89 () ) {
F_90 ( V_5 ) ;
F_91 () ;
}
F_92 ( V_5 -> V_243 , & V_5 -> V_238 , V_244 ) ;
}
static int F_93 ( struct V_68 * V_68 , struct V_3 * V_3 ,
T_2 V_116 )
{
struct V_2 * V_2 ;
int V_245 = V_246 ;
if ( V_116 >= sizeof( struct V_68 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_38 ,
V_3 -> V_45 -> V_46 , V_3 -> V_5 -> V_45 -> V_46 ) ;
return V_245 ;
}
switch ( V_68 -> V_203 ) {
case V_247 :
V_245 = V_248 ;
F_22 ( V_3 -> V_5 -> V_45 ,
L_39 ,
V_2 -> V_47 ,
V_3 -> V_45 -> V_46 ) ;
F_94 ( & V_3 -> V_5 -> V_234 ) ;
F_54 ( V_68 , V_2 ) ;
F_95 ( & V_3 -> V_5 -> V_234 ) ;
break;
case V_249 :
V_245 = V_248 ;
switch ( ( (struct V_131 * ) V_68 ) -> V_217 ) {
case V_250 :
F_22 ( V_3 -> V_5 -> V_45 , L_40 ,
V_2 -> V_47 ) ;
F_72 ( (struct V_131 * ) V_68 , V_2 ) ;
break;
case V_218 :
F_22 ( V_3 -> V_5 -> V_45 , L_41 ,
V_2 -> V_47 ) ;
F_73 ( (struct V_131 * ) V_68 , V_2 ) ;
break;
default:
F_22 ( V_3 -> V_5 -> V_45 , L_42 ,
V_2 -> V_47 ) ;
}
}
}
return V_245 ;
}
static void F_77 ( struct V_2 * V_2 , bool V_251 )
{
T_3 V_49 = 0 ;
T_2 V_252 = 0 , V_17 = 0 ;
T_2 V_253 = V_2 -> V_74 ;
V_2 -> V_192 &= ~ ( V_254 | V_157 ) ;
if ( ! V_251 ) {
V_17 = F_20 ( V_2 ) ;
V_252 = ( V_253 & V_254 ) >> 1 ;
V_49 = F_23 ( V_2 ) ;
V_2 -> V_192 |= ( V_17 << 1 ) | V_49 ;
}
V_2 -> V_74 = V_2 -> V_192 ;
if ( V_253 != V_2 -> V_74 ) {
if ( V_49 )
V_2 -> V_79 |= V_155 ;
else
V_2 -> V_79 &= ~ V_155 ;
if ( ! V_251 ) {
if ( ! V_17 ) {
F_55 ( V_2 -> V_3 -> V_45 ,
L_43 ,
V_2 -> V_3 -> V_45 -> V_46 ) ;
} else if ( V_49 && V_252 != V_17 ) {
V_2 -> V_79 |= V_138 ;
}
}
}
}
void F_96 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_80 ( V_3 -> V_5 -> V_45 ,
L_44 ,
V_3 -> V_45 -> V_46 ) ;
return;
}
F_79 ( & V_3 -> V_5 -> V_234 ) ;
F_77 ( V_2 , false ) ;
F_82 ( & V_3 -> V_5 -> V_234 ) ;
F_22 ( V_3 -> V_5 -> V_45 , L_45 ,
V_2 -> V_47 , V_3 -> V_45 -> V_46 ) ;
}
void F_97 ( struct V_3 * V_3 , char V_11 )
{
struct V_4 * V_7 ;
struct V_2 * V_2 ;
bool V_255 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_80 ( V_3 -> V_5 -> V_45 , L_46 ,
V_3 -> V_45 -> V_46 ) ;
return;
}
F_79 ( & V_3 -> V_5 -> V_234 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_106 = true ;
F_77 ( V_2 , false ) ;
} else {
V_2 -> V_106 = false ;
F_77 ( V_2 , true ) ;
}
V_7 = F_3 ( V_2 ) ;
F_63 ( V_7 , & V_255 ) ;
F_82 ( & V_3 -> V_5 -> V_234 ) ;
F_22 ( V_3 -> V_5 -> V_45 , L_47 ,
V_2 -> V_47 ,
V_11 == V_12 ? L_48 : L_49 ) ;
F_98 ( V_3 -> V_5 , NULL ) ;
}
int F_68 ( struct V_1 * V_5 )
{
struct V_4 * V_105 ;
struct V_3 * V_6 ;
int V_245 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_245 = 0 ;
goto V_235;
}
V_105 = F_39 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_105 ) {
if ( F_37 ( V_105 ) < V_5 -> V_14 . V_256 ) {
if ( F_67 ( V_5 -> V_45 ) ) {
F_99 ( V_5 -> V_45 ) ;
goto V_235;
}
} else if ( ! F_67 ( V_5 -> V_45 ) ) {
F_100 ( V_5 -> V_45 ) ;
goto V_235;
}
} else if ( F_67 ( V_5 -> V_45 ) ) {
F_99 ( V_5 -> V_45 ) ;
}
V_235:
F_7 () ;
return V_245 ;
}
int F_101 ( struct V_1 * V_5 ,
struct V_257 * V_257 )
{
struct V_4 * V_4 = NULL ;
struct V_110 * V_111 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_40 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_112 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( ! V_4 )
return - 1 ;
V_257 -> V_258 = V_4 -> V_186 ;
V_257 -> V_259 = F_37 ( V_4 ) ;
V_257 -> V_89 = V_4 -> V_187 ;
V_257 -> V_73 = V_4 -> V_188 ;
F_47 ( V_257 -> V_8 ,
V_4 -> V_8 . V_9 ) ;
return 0 ;
}
int F_102 ( struct V_1 * V_5 , struct V_257 * V_257 )
{
int V_245 ;
F_4 () ;
V_245 = F_101 ( V_5 , V_257 ) ;
F_7 () ;
return V_245 ;
}
int F_103 ( const struct V_113 * V_114 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
struct V_68 * V_68 , V_260 ;
if ( V_114 -> V_121 != V_122 )
return V_246 ;
if ( ! F_28 ( F_104 ( V_114 ) -> V_126 , V_127 ) )
return V_246 ;
V_68 = F_105 ( V_114 , 0 , sizeof( V_260 ) , & V_260 ) ;
if ( ! V_68 )
return V_246 ;
return F_93 ( V_68 , V_3 , V_114 -> V_261 ) ;
}
void F_106 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_110 * V_111 ;
struct V_3 * V_3 ;
int V_201 ;
V_201 = V_5 -> V_14 . V_201 ;
F_79 ( & V_5 -> V_234 ) ;
F_62 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_201 )
V_2 -> V_77 |= V_98 ;
else
V_2 -> V_77 &= ~ V_98 ;
}
F_82 ( & V_5 -> V_234 ) ;
}
