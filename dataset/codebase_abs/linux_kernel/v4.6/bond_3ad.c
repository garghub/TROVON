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
default:
V_17 = 0 ;
break;
}
}
F_21 ( V_3 -> V_5 -> V_36 , L_1 ,
V_2 -> V_37 , V_17 ) ;
return V_17 ;
}
static T_3 F_22 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_38 = 0x0 ;
if ( V_3 -> V_11 == V_12 ) {
switch ( V_3 -> V_39 ) {
case V_40 :
V_38 = 0x1 ;
F_21 ( V_3 -> V_5 -> V_36 , L_2 ,
V_2 -> V_37 ) ;
break;
case V_41 :
default:
V_38 = 0x0 ;
F_21 ( V_3 -> V_5 -> V_36 , L_3 ,
V_2 -> V_37 ) ;
break;
}
}
return V_38 ;
}
static void F_23 ( struct V_2 * V_2 )
{
const struct V_1 * V_5 = F_2 ( V_2 -> V_3 ) ;
V_2 -> V_42 = F_19 ( V_5 ) . system . V_43 ;
V_2 -> V_44 = F_19 ( V_5 ) . system . V_45 ;
}
static T_2 F_24 ( T_2 V_46 , T_2 V_47 )
{
T_2 V_38 = 0 ;
switch ( V_46 ) {
case V_48 :
if ( V_47 )
V_38 = ( V_49 * V_50 ) ;
else
V_38 = ( V_51 * V_50 ) ;
break;
case V_52 :
V_38 = ( V_53 * V_50 ) ;
break;
case V_54 :
V_38 = ( V_47 * V_50 ) ;
break;
case V_55 :
V_38 = ( V_53 * V_50 ) ;
break;
case V_56 :
V_38 = ( V_57 * V_50 ) ;
break;
}
return V_38 ;
}
static void F_25 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
if ( ( ( F_26 ( V_58 -> V_59 ) == V_2 -> V_37 ) &&
( F_26 ( V_58 -> V_60 ) == V_2 -> V_61 ) &&
F_27 ( & ( V_58 -> V_8 ) , & ( V_2 -> V_42 ) ) &&
( F_26 ( V_58 -> V_62 ) == V_2 -> V_44 ) &&
( F_26 ( V_58 -> V_63 ) == V_2 -> V_64 ) &&
( ( V_58 -> V_65 & V_66 ) == ( V_2 -> V_67 & V_66 ) ) ) ||
( ( V_58 -> V_68 & V_66 ) == 0 )
) {
V_2 -> V_69 |= V_70 ;
} else {
V_2 -> V_69 &= ~ V_70 ;
}
}
static void F_28 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
if ( V_58 && V_2 ) {
struct V_71 * V_72 = & V_2 -> V_73 ;
F_25 ( V_58 , V_2 ) ;
V_72 -> V_74 = F_26 ( V_58 -> V_75 ) ;
V_72 -> V_76 = F_26 ( V_58 -> V_61 ) ;
V_72 -> system = V_58 -> V_42 ;
V_72 -> V_77 = F_26 ( V_58 -> V_44 ) ;
V_72 -> V_78 = F_26 ( V_58 -> V_79 ) ;
V_72 -> V_80 = V_58 -> V_68 ;
V_2 -> V_67 &= ~ V_81 ;
if ( ( V_2 -> V_69 & V_70 ) &&
( V_58 -> V_68 & V_82 ) ) {
V_72 -> V_80 |= V_82 ;
F_29 ( L_4 , V_2 -> V_3 -> V_36 -> V_83 ) ;
} else {
V_72 -> V_80 &= ~ V_82 ;
F_29 ( L_5 , V_2 -> V_3 -> V_36 -> V_83 ) ;
}
}
}
static void F_30 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_73 , & V_2 -> V_84 ,
sizeof( struct V_71 ) ) ;
V_2 -> V_67 |= V_81 ;
}
}
static void F_31 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
if ( V_58 && V_2 ) {
const struct V_71 * V_72 = & V_2 -> V_73 ;
if ( F_26 ( V_58 -> V_75 ) != V_72 -> V_74 ||
F_26 ( V_58 -> V_61 ) != V_72 -> V_76 ||
! F_27 ( & V_58 -> V_42 , & V_72 -> system ) ||
F_26 ( V_58 -> V_44 ) != V_72 -> V_77 ||
F_26 ( V_58 -> V_79 ) != V_72 -> V_78 ||
( V_58 -> V_68 & V_66 ) != ( V_72 -> V_80 & V_66 ) ) {
V_2 -> V_69 &= ~ V_85 ;
}
}
}
static void F_32 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_71 * V_86 = & V_2 -> V_84 ;
const struct V_71 * V_87 = & V_2 -> V_73 ;
if ( V_86 -> V_74 != V_87 -> V_74 ||
V_86 -> V_76 != V_87 -> V_76 ||
! F_27 ( & V_86 -> system , & V_87 -> system ) ||
V_86 -> V_77 != V_87 -> V_77 ||
V_86 -> V_78 != V_87 -> V_78 ||
( V_86 -> V_80 & V_66 )
!= ( V_87 -> V_80 & V_66 ) ) {
V_2 -> V_69 &= ~ V_85 ;
}
}
}
static void F_33 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
if ( V_58 && V_2 ) {
if ( ( F_26 ( V_58 -> V_59 ) != V_2 -> V_37 ) ||
( F_26 ( V_58 -> V_60 ) != V_2 -> V_61 ) ||
! F_27 ( & ( V_58 -> V_8 ) , & ( V_2 -> V_42 ) ) ||
( F_26 ( V_58 -> V_62 ) != V_2 -> V_44 ) ||
( F_26 ( V_58 -> V_63 ) != V_2 -> V_64 ) ||
( ( V_58 -> V_65 & V_88 ) != ( V_2 -> V_67 & V_88 ) ) ||
( ( V_58 -> V_65 & V_89 ) != ( V_2 -> V_67 & V_89 ) ) ||
( ( V_58 -> V_65 & V_82 ) != ( V_2 -> V_67 & V_82 ) ) ||
( ( V_58 -> V_65 & V_66 ) != ( V_2 -> V_67 & V_66 ) )
) {
V_2 -> V_90 = true ;
}
}
}
static int F_34 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_38 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_91 ;
V_2 ;
V_2 = V_2 -> V_92 ) {
if ( ! ( V_2 -> V_69 & V_93 ) ) {
V_38 = 0 ;
break;
}
}
}
return V_38 ;
}
static void F_35 ( struct V_4 * V_4 , int V_94 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_91 ; V_2 ;
V_2 = V_2 -> V_92 ) {
if ( V_94 )
V_2 -> V_69 |= V_95 ;
else
V_2 -> V_69 &= ~ V_95 ;
}
}
static T_1 F_36 ( struct V_4 * V_4 )
{
T_1 V_96 = 0 ;
if ( V_4 -> V_97 ) {
switch ( F_20 ( V_4 -> V_91 ) ) {
case V_98 :
V_96 = V_4 -> V_97 ;
break;
case V_19 :
V_96 = V_4 -> V_97 * 10 ;
break;
case V_21 :
V_96 = V_4 -> V_97 * 100 ;
break;
case V_23 :
V_96 = V_4 -> V_97 * 1000 ;
break;
case V_25 :
V_96 = V_4 -> V_97 * 2500 ;
break;
case V_27 :
V_96 = V_4 -> V_97 * 10000 ;
break;
case V_29 :
V_96 = V_4 -> V_97 * 20000 ;
break;
case V_31 :
V_96 = V_4 -> V_97 * 40000 ;
break;
case V_33 :
V_96 = V_4 -> V_97 * 56000 ;
break;
case V_35 :
V_96 = V_4 -> V_97 * 100000 ;
break;
default:
V_96 = 0 ;
}
}
return V_96 ;
}
static struct V_4 * F_37 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_99 * V_100 ;
struct V_3 * V_3 ;
F_38 (bond, slave, iter)
if ( F_6 ( V_3 ) -> V_4 . V_101 )
return & ( F_6 ( V_3 ) -> V_4 ) ;
return NULL ;
}
static inline void F_39 ( struct V_2 * V_2 )
{
struct V_58 * V_58 = & V_2 -> V_58 ;
const struct V_71 * V_72 = & V_2 -> V_73 ;
V_58 -> V_44 = F_40 ( V_2 -> V_44 ) ;
V_58 -> V_42 = V_2 -> V_42 ;
V_58 -> V_79 = F_40 ( V_2 -> V_64 ) ;
V_58 -> V_61 = F_40 ( V_2 -> V_61 ) ;
V_58 -> V_75 = F_40 ( V_2 -> V_37 ) ;
V_58 -> V_68 = V_2 -> V_67 ;
F_29 ( L_6 ,
V_2 -> V_3 -> V_36 -> V_83 , V_2 -> V_67 ) ;
V_58 -> V_62 = F_40 ( V_72 -> V_77 ) ;
V_58 -> V_8 = V_72 -> system ;
V_58 -> V_63 = F_40 ( V_72 -> V_78 ) ;
V_58 -> V_60 = F_40 ( V_72 -> V_76 ) ;
V_58 -> V_59 = F_40 ( V_72 -> V_74 ) ;
V_58 -> V_65 = V_72 -> V_80 ;
}
static int F_41 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_102 * V_103 ;
struct V_104 * V_104 ;
int V_105 = sizeof( struct V_104 ) ;
V_103 = F_42 ( V_105 ) ;
if ( ! V_103 )
return - V_106 ;
V_103 -> V_36 = V_3 -> V_36 ;
F_43 ( V_103 ) ;
V_103 -> V_107 = V_103 -> V_108 + V_109 ;
V_103 -> V_110 = V_111 ;
V_103 -> V_112 = V_113 ;
V_104 = (struct V_104 * ) F_44 ( V_103 , V_105 ) ;
F_45 ( V_104 -> V_114 . V_115 , V_116 ) ;
F_45 ( V_104 -> V_114 . V_117 , V_3 -> V_118 ) ;
V_104 -> V_114 . V_119 = V_111 ;
V_104 -> V_58 = V_2 -> V_58 ;
F_46 ( V_103 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_2 , struct V_120 * V_121 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_102 * V_103 ;
struct V_122 * V_123 ;
int V_105 = sizeof( struct V_122 ) ;
V_103 = F_42 ( V_105 + 16 ) ;
if ( ! V_103 )
return - V_106 ;
F_48 ( V_103 , 16 ) ;
V_103 -> V_36 = V_3 -> V_36 ;
F_43 ( V_103 ) ;
V_103 -> V_107 = V_103 -> V_108 + V_109 ;
V_103 -> V_110 = V_111 ;
V_123 = (struct V_122 * ) F_44 ( V_103 , V_105 ) ;
F_45 ( V_123 -> V_114 . V_115 , V_116 ) ;
F_45 ( V_123 -> V_114 . V_117 , V_3 -> V_118 ) ;
V_123 -> V_114 . V_119 = V_111 ;
V_123 -> V_121 = * V_121 ;
F_46 ( V_103 ) ;
return 0 ;
}
static void F_49 ( struct V_2 * V_2 , bool * V_124 )
{
T_4 V_125 ;
V_125 = V_2 -> V_126 ;
if ( V_2 -> V_69 & V_127 ) {
V_2 -> V_126 = V_128 ;
} else {
switch ( V_2 -> V_126 ) {
case V_128 :
if ( ( V_2 -> V_69 & V_85 )
|| ( V_2 -> V_69 & V_129 ) )
V_2 -> V_126 = V_130 ;
break;
case V_130 :
if ( ! ( V_2 -> V_69 & V_85 ) ) {
V_2 -> V_69 &= ~ V_93 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
V_2 -> V_126 = V_128 ;
break;
}
if ( V_2 -> V_131
&& ! ( -- V_2 -> V_131 ) )
V_2 -> V_69 |= V_93 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_69 & V_95 )
&& ! V_2 -> V_131 )
V_2 -> V_126 = V_132 ;
break;
case V_132 :
if ( ( V_2 -> V_69 & V_85 ) &&
( V_2 -> V_73 . V_80 & V_82 ) &&
! F_18 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_101 )
V_2 -> V_126 =
V_133 ;
} else if ( ! ( V_2 -> V_69 & V_85 ) ||
( V_2 -> V_69 & V_129 ) ) {
V_2 -> V_69 &= ~ V_93 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
V_2 -> V_126 = V_128 ;
} else if ( V_2 -> V_4 -> V_101 ) {
V_2 -> V_67 |=
V_82 ;
}
break;
case V_133 :
if ( ! ( V_2 -> V_69 & V_85 ) ||
( V_2 -> V_69 & V_129 ) ||
! ( V_2 -> V_73 . V_80 & V_82 ) ||
! ( V_2 -> V_67 & V_82 ) ) {
V_2 -> V_126 = V_132 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_101 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_126 != V_125 ) {
F_29 ( L_7 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_83 ,
V_125 ,
V_2 -> V_126 ) ;
switch ( V_2 -> V_126 ) {
case V_128 :
V_2 -> V_67 &= ~ V_82 ;
F_50 ( V_2 ,
V_124 ) ;
V_2 -> V_67 &= ~ V_134 ;
V_2 -> V_67 &= ~ V_135 ;
V_2 -> V_90 = true ;
break;
case V_130 :
V_2 -> V_131 = F_24 ( V_56 , 0 ) ;
break;
case V_132 :
if ( V_2 -> V_4 -> V_101 )
V_2 -> V_67 |=
V_82 ;
else
V_2 -> V_67 &=
~ V_82 ;
V_2 -> V_67 &= ~ V_134 ;
V_2 -> V_67 &= ~ V_135 ;
F_50 ( V_2 ,
V_124 ) ;
V_2 -> V_90 = true ;
break;
case V_133 :
V_2 -> V_67 |= V_134 ;
V_2 -> V_67 |= V_135 ;
V_2 -> V_67 |= V_82 ;
F_51 ( V_2 ,
V_124 ) ;
V_2 -> V_90 = true ;
break;
default:
break;
}
}
}
static void F_52 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
T_5 V_125 ;
V_125 = V_2 -> V_136 ;
if ( V_2 -> V_69 & V_127 ) {
V_2 -> V_136 = V_137 ;
V_2 -> V_69 |= V_138 ;
} else if ( ! ( V_2 -> V_69 & V_127 )
&& ! V_2 -> V_139 && ! ( V_2 -> V_69 & V_140 ) )
V_2 -> V_136 = V_141 ;
else if ( V_58 && ( ( V_2 -> V_136 == V_142 ) ||
( V_2 -> V_136 == V_143 ) ||
( V_2 -> V_136 == V_144 ) ) ) {
if ( V_2 -> V_136 != V_144 )
V_2 -> V_69 |= V_138 ;
V_2 -> V_145 = 0 ;
V_2 -> V_136 = V_144 ;
} else {
if ( V_2 -> V_145 &&
! ( -- V_2 -> V_145 ) ) {
switch ( V_2 -> V_136 ) {
case V_142 :
V_2 -> V_136 = V_143 ;
break;
case V_144 :
V_2 -> V_136 = V_142 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_136 ) {
case V_141 :
if ( V_2 -> V_69 & V_140 )
V_2 -> V_136 = V_137 ;
else if ( V_2 -> V_139
&& ( V_2 -> V_69
& V_146 ) )
V_2 -> V_136 = V_142 ;
else if ( V_2 -> V_139
&& ( ( V_2 -> V_69
& V_146 ) == 0 ) )
V_2 -> V_136 = V_147 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_136 != V_125 ) || ( V_58 ) ) {
F_29 ( L_8 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_83 ,
V_125 ,
V_2 -> V_136 ) ;
switch ( V_2 -> V_136 ) {
case V_137 :
if ( ! ( V_2 -> V_64 & V_148 ) )
V_2 -> V_69 &= ~ V_146 ;
else
V_2 -> V_69 |= V_146 ;
V_2 -> V_69 &= ~ V_85 ;
F_30 ( V_2 ) ;
V_2 -> V_67 &= ~ V_149 ;
V_2 -> V_69 &= ~ V_140 ;
V_2 -> V_136 = V_141 ;
case V_141 :
V_2 -> V_69 &= ~ V_70 ;
break;
case V_147 :
V_2 -> V_69 &= ~ V_85 ;
F_30 ( V_2 ) ;
V_2 -> V_73 . V_80 &= ~ V_66 ;
V_2 -> V_69 |= V_70 ;
V_2 -> V_67 &= ~ V_149 ;
break;
case V_142 :
V_2 -> V_73 . V_80 &= ~ V_82 ;
V_2 -> V_69 &= ~ V_70 ;
V_2 -> V_73 . V_80 |= V_89 ;
V_2 -> V_73 . V_80 |= V_88 ;
V_2 -> V_145 = F_24 ( V_48 , ( T_2 ) ( V_150 ) ) ;
V_2 -> V_67 |= V_149 ;
V_2 -> V_69 |= V_138 ;
break;
case V_143 :
F_32 ( V_2 ) ;
F_30 ( V_2 ) ;
V_2 -> V_69 |= V_70 ;
V_2 -> V_67 &= ~ V_149 ;
break;
case V_144 :
if ( F_27 ( & ( V_58 -> V_42 ) ,
& ( V_2 -> V_42 ) ) ) {
F_53 ( V_2 -> V_3 -> V_5 -> V_36 , L_9
L_10 ,
V_2 -> V_3 -> V_36 -> V_83 ) ;
return;
}
F_31 ( V_58 , V_2 ) ;
F_33 ( V_58 , V_2 ) ;
F_28 ( V_58 , V_2 ) ;
V_2 -> V_145 = F_24 ( V_48 , ( T_2 ) ( V_2 -> V_67 & V_89 ) ) ;
V_2 -> V_67 &= ~ V_149 ;
break;
default:
break;
}
}
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_69 & V_138 ) {
V_2 -> V_69 &= ~ V_138 ;
V_2 -> V_151 = V_152 ;
V_2 -> V_153 = V_152 ;
V_2 -> V_154 =
F_24 ( V_52 , 0 ) ;
V_2 -> V_155 =
F_24 ( V_55 , 0 ) ;
return;
}
if ( V_2 -> V_154 &&
! ( -- V_2 -> V_154 ) &&
V_2 -> V_151 == V_152 ) {
if ( V_2 -> V_67 & V_82 ) {
V_2 -> V_151 = V_156 ;
} else {
V_2 -> V_157 ++ ;
V_2 -> V_151 = V_158 ;
}
}
if ( V_2 -> V_155 &&
! ( -- V_2 -> V_155 ) &&
V_2 -> V_153 == V_152 ) {
if ( V_2 -> V_73 . V_80 & V_82 ) {
V_2 -> V_153 = V_156 ;
} else {
V_2 -> V_159 ++ ;
V_2 -> V_153 = V_158 ;
}
}
}
static void F_55 ( struct V_2 * V_2 )
{
if ( V_2 -> V_160 && ! ( -- V_2 -> V_160 ) ) {
if ( V_2 -> V_90 && ( V_2 -> V_69 & V_146 ) ) {
F_39 ( V_2 ) ;
if ( F_41 ( V_2 ) >= 0 ) {
F_29 ( L_11 ,
V_2 -> V_37 ) ;
V_2 -> V_90 = false ;
}
}
V_2 -> V_160 = V_50 / V_161 ;
}
}
static void F_56 ( struct V_2 * V_2 )
{
T_6 V_125 ;
V_125 = V_2 -> V_162 ;
if ( ( ( V_2 -> V_69 & V_127 ) || ! ( V_2 -> V_69 & V_146 ) || ! V_2 -> V_139 ) ||
( ! ( V_2 -> V_67 & V_88 ) && ! ( V_2 -> V_73 . V_80 & V_88 ) )
) {
V_2 -> V_162 = V_163 ;
}
else if ( V_2 -> V_164 ) {
if ( ! ( -- V_2 -> V_164 ) ) {
V_2 -> V_162 = V_165 ;
} else {
switch ( V_2 -> V_162 ) {
case V_166 :
if ( ! ( V_2 -> V_73 . V_80
& V_89 ) )
V_2 -> V_162 = V_167 ;
break;
case V_167 :
if ( ( V_2 -> V_73 . V_80 & V_89 ) ) {
V_2 -> V_164 = 0 ;
V_2 -> V_162 = V_165 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_162 ) {
case V_163 :
V_2 -> V_162 = V_166 ;
break;
case V_165 :
if ( ! ( V_2 -> V_73 . V_80 &
V_89 ) )
V_2 -> V_162 = V_167 ;
else
V_2 -> V_162 = V_166 ;
break;
default:
break;
}
}
if ( V_2 -> V_162 != V_125 ) {
F_29 ( L_12 ,
V_2 -> V_37 , V_125 ,
V_2 -> V_162 ) ;
switch ( V_2 -> V_162 ) {
case V_163 :
V_2 -> V_164 = 0 ;
break;
case V_166 :
V_2 -> V_164 = F_24 ( V_54 , ( T_2 ) ( V_168 ) ) - 1 ;
break;
case V_167 :
V_2 -> V_164 = F_24 ( V_54 , ( T_2 ) ( V_169 ) ) - 1 ;
break;
case V_165 :
V_2 -> V_90 = true ;
break;
default:
break;
}
}
}
static void F_57 ( struct V_2 * V_2 , bool * V_124 )
{
struct V_4 * V_4 , * V_170 = NULL , * V_171 ;
struct V_2 * V_172 = NULL , * V_173 ;
struct V_99 * V_100 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_174 = 0 ;
if ( V_2 -> V_69 & V_85 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_171 = V_2 -> V_4 ;
for ( V_173 = V_171 -> V_91 ; V_173 ;
V_172 = V_173 ,
V_173 = V_173 -> V_92 ) {
if ( V_173 == V_2 ) {
V_171 -> V_97 -- ;
if ( ! V_172 ) {
V_171 -> V_91 =
V_2 -> V_92 ;
} else {
V_172 -> V_92 =
V_2 -> V_92 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_92 = NULL ;
V_2 -> V_175 = 0 ;
F_21 ( V_5 -> V_36 , L_13 ,
V_2 -> V_37 ,
V_171 -> V_176 ) ;
if ( ! V_171 -> V_91 )
F_58 ( V_171 ) ;
break;
}
}
if ( ! V_173 ) {
F_59 ( L_14 ,
V_2 -> V_3 -> V_5 -> V_36 -> V_83 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_83 ,
V_2 -> V_4 -> V_176 ) ;
}
}
F_60 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_91 ) {
if ( ! V_170 )
V_170 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_177 == V_2 -> V_64 ) &&
F_27 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_73 . system ) ) &&
( V_4 -> V_62 == V_2 -> V_73 . V_77 ) &&
( V_4 -> V_178 == V_2 -> V_73 . V_78 )
) &&
( ( ! F_27 ( & ( V_2 -> V_73 . system ) , & ( V_179 ) ) &&
! V_4 -> V_180 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_175 =
V_2 -> V_4 -> V_176 ;
V_2 -> V_92 = V_4 -> V_91 ;
V_2 -> V_4 -> V_97 ++ ;
V_4 -> V_91 = V_2 ;
F_21 ( V_5 -> V_36 , L_15 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_176 ) ;
V_2 -> V_69 |= V_85 ;
V_174 = 1 ;
break;
}
}
if ( ! V_174 ) {
if ( V_170 ) {
V_2 -> V_4 = V_170 ;
V_2 -> V_175 =
V_2 -> V_4 -> V_176 ;
if ( V_2 -> V_64 & V_148 )
V_2 -> V_4 -> V_180 = false ;
else
V_2 -> V_4 -> V_180 = true ;
V_2 -> V_4 -> V_181 =
V_2 -> V_182 ;
V_2 -> V_4 -> V_177 =
V_2 -> V_64 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_73 . system ;
V_2 -> V_4 -> V_62 =
V_2 -> V_73 . V_77 ;
V_2 -> V_4 -> V_178 = V_2 -> V_73 . V_78 ;
V_2 -> V_4 -> V_183 = 1 ;
V_2 -> V_4 -> V_184 = 1 ;
V_2 -> V_4 -> V_91 = V_2 ;
V_2 -> V_4 -> V_97 ++ ;
V_2 -> V_69 |= V_85 ;
F_21 ( V_5 -> V_36 , L_16 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_176 ) ;
} else {
F_53 ( V_5 -> V_36 , L_17 ,
V_2 -> V_37 , V_2 -> V_3 -> V_36 -> V_83 ) ;
}
}
F_35 ( V_2 -> V_4 ,
F_34 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_61 ( V_4 , V_124 ) ;
if ( ! V_2 -> V_4 -> V_101 )
V_2 -> V_67 &= ~ V_82 ;
}
static struct V_4 * F_62 ( struct V_4 * V_185 ,
struct V_4 * V_186 )
{
if ( ! V_185 )
return V_186 ;
if ( ! V_186 -> V_180 && V_185 -> V_180 )
return V_186 ;
if ( V_186 -> V_180 && ! V_185 -> V_180 )
return V_185 ;
if ( F_8 ( V_186 ) && ! F_8 ( V_185 ) )
return V_186 ;
if ( ! F_8 ( V_186 ) && F_8 ( V_185 ) )
return V_185 ;
switch ( F_17 ( V_186 -> V_91 ) ) {
case V_187 :
if ( V_186 -> V_97 > V_185 -> V_97 )
return V_186 ;
if ( V_186 -> V_97 < V_185 -> V_97 )
return V_185 ;
case V_13 :
case V_188 :
if ( F_36 ( V_186 ) > F_36 ( V_185 ) )
return V_186 ;
break;
default:
F_59 ( L_18 ,
V_186 -> V_3 -> V_5 -> V_36 -> V_83 ,
F_17 ( V_186 -> V_91 ) ) ;
break;
}
return V_185 ;
}
static int F_63 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_91 ;
if ( ! V_2 )
return 0 ;
return F_64 ( V_2 -> V_3 -> V_36 ) &&
F_65 ( V_2 -> V_3 -> V_36 ) ;
}
static void F_61 ( struct V_4 * V_7 ,
bool * V_124 )
{
struct V_4 * V_185 , * V_189 , * V_190 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_99 * V_100 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_190 = V_7 ;
V_189 = F_37 ( V_7 ) ;
V_185 = ( V_189 && F_63 ( V_189 ) ) ? V_189 : NULL ;
F_38 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_101 = 0 ;
if ( V_7 -> V_97 && F_63 ( V_7 ) )
V_185 = F_62 ( V_185 , V_7 ) ;
}
if ( V_185 &&
F_17 ( V_185 -> V_91 ) == V_13 ) {
if ( V_189 && V_189 -> V_91 &&
V_189 -> V_91 -> V_139 &&
( F_8 ( V_189 ) ||
( ! F_8 ( V_189 ) &&
! F_8 ( V_185 ) ) ) ) {
if ( ! ( ! V_189 -> V_177 &&
V_185 -> V_177 ) ) {
V_185 = NULL ;
V_189 -> V_101 = 1 ;
}
}
}
if ( V_185 && ( V_185 == V_189 ) ) {
V_185 = NULL ;
V_189 -> V_101 = 1 ;
}
if ( V_185 ) {
F_21 ( V_5 -> V_36 , L_19 ,
V_185 -> V_176 , V_185 -> V_97 ,
V_185 -> V_177 ,
V_185 -> V_178 ,
V_185 -> V_180 , V_185 -> V_101 ) ;
F_21 ( V_5 -> V_36 , L_20 ,
V_185 -> V_91 , V_185 -> V_3 ,
V_185 -> V_3 ? V_185 -> V_3 -> V_36 -> V_83 : L_21 ) ;
F_38 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_21 ( V_5 -> V_36 , L_22 ,
V_7 -> V_176 , V_7 -> V_97 ,
V_7 -> V_177 ,
V_7 -> V_178 ,
V_7 -> V_180 , V_7 -> V_101 ) ;
}
if ( V_185 -> V_180 ) {
F_59 ( L_23 ,
V_185 -> V_3 ?
V_185 -> V_3 -> V_5 -> V_36 -> V_83 : L_21 ) ;
}
V_185 -> V_101 = 1 ;
F_21 ( V_5 -> V_36 , L_24 ,
V_185 -> V_176 ) ;
F_21 ( V_5 -> V_36 , L_22 ,
V_185 -> V_176 , V_185 -> V_97 ,
V_185 -> V_177 ,
V_185 -> V_178 ,
V_185 -> V_180 , V_185 -> V_101 ) ;
if ( V_189 ) {
for ( V_2 = V_189 -> V_91 ; V_2 ;
V_2 = V_2 -> V_92 ) {
F_10 ( V_2 ) ;
}
}
* V_124 = true ;
}
V_189 = F_37 ( V_190 ) ;
if ( V_189 ) {
if ( ! F_8 ( V_189 ) ) {
for ( V_2 = V_189 -> V_91 ; V_2 ;
V_2 = V_2 -> V_92 ) {
F_12 ( V_2 ) ;
}
}
}
F_7 () ;
F_66 ( V_5 ) ;
}
static void F_58 ( struct V_4 * V_4 )
{
if ( V_4 ) {
V_4 -> V_180 = false ;
V_4 -> V_181 = 0 ;
V_4 -> V_177 = 0 ;
V_4 -> V_8 = V_179 ;
V_4 -> V_62 = 0 ;
V_4 -> V_178 = 0 ;
V_4 -> V_183 = 0 ;
V_4 -> V_184 = 0 ;
V_4 -> V_91 = NULL ;
V_4 -> V_101 = 0 ;
V_4 -> V_97 = 0 ;
F_29 ( L_25 ,
V_4 -> V_176 ) ;
}
}
static void F_67 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_58 ( V_4 ) ;
V_4 -> V_191 = V_179 ;
V_4 -> V_176 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_68 ( struct V_2 * V_2 , int V_192 )
{
static const struct V_71 V_193 = {
. V_77 = 0xffff ,
. V_78 = 1 ,
. V_74 = 1 ,
. V_76 = 0xff ,
. V_80 = 1 ,
} ;
static const struct V_58 V_58 = {
. V_194 = 0x01 ,
. V_195 = 0x01 ,
. V_196 = 0x01 ,
. V_197 = 0x14 ,
. V_198 = 0x02 ,
. V_199 = 0x14 ,
. V_200 = 0x03 ,
. V_201 = 0x10 ,
. V_202 = F_40 ( V_203 ) ,
} ;
if ( V_2 ) {
V_2 -> V_61 = 0xff ;
V_2 -> V_175 = 0 ;
V_2 -> V_90 = false ;
V_2 -> V_204 = V_66 |
V_88 ;
V_2 -> V_67 = V_66 |
V_88 ;
if ( V_192 )
V_2 -> V_67 |= V_89 ;
memcpy ( & V_2 -> V_84 , & V_193 , sizeof( V_193 ) ) ;
memcpy ( & V_2 -> V_73 , & V_193 , sizeof( V_193 ) ) ;
V_2 -> V_139 = true ;
V_2 -> V_69 = V_127 | V_146 ;
V_2 -> V_136 = 0 ;
V_2 -> V_145 = 0 ;
V_2 -> V_162 = 0 ;
V_2 -> V_164 = 0 ;
V_2 -> V_126 = 0 ;
V_2 -> V_131 = 0 ;
V_2 -> V_205 = 0 ;
V_2 -> V_4 = NULL ;
V_2 -> V_92 = NULL ;
V_2 -> V_206 = 0 ;
V_2 -> V_154 = 0 ;
V_2 -> V_151 = 0 ;
V_2 -> V_157 = 0 ;
V_2 -> V_155 = 0 ;
V_2 -> V_153 = 0 ;
V_2 -> V_159 = 0 ;
memcpy ( & V_2 -> V_58 , & V_58 , sizeof( V_58 ) ) ;
}
}
static void F_51 ( struct V_2 * V_2 ,
bool * V_124 )
{
if ( V_2 -> V_4 -> V_101 ) {
F_29 ( L_26 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_176 ) ;
F_12 ( V_2 ) ;
* V_124 = true ;
}
}
static void F_50 ( struct V_2 * V_2 ,
bool * V_124 )
{
if ( V_2 -> V_4 &&
! F_27 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_179 ) ) ) {
F_29 ( L_27 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_176 ) ;
F_10 ( V_2 ) ;
* V_124 = true ;
}
}
static void F_69 ( struct V_120 * V_207 ,
struct V_2 * V_2 )
{
struct V_120 V_121 ;
memcpy ( & V_121 , V_207 , sizeof( struct V_120 ) ) ;
V_121 . V_208 = V_209 ;
if ( F_47 ( V_2 , & V_121 ) >= 0 ) {
F_29 ( L_28 ,
V_2 -> V_37 ) ;
}
}
static void F_70 ( struct V_120 * V_121 ,
struct V_2 * V_2 )
{
}
void F_71 ( struct V_1 * V_5 , int V_210 )
{
F_19 ( V_5 ) . V_16 = V_210 ;
}
void F_72 ( struct V_1 * V_5 , T_2 V_211 )
{
if ( ! F_27 ( & ( F_19 ( V_5 ) . system . V_43 ) ,
V_5 -> V_36 -> V_212 ) ) {
F_19 ( V_5 ) . V_176 = 0 ;
F_19 ( V_5 ) . system . V_45 =
V_5 -> V_14 . V_213 ;
if ( F_9 ( V_5 -> V_14 . V_214 ) )
F_19 ( V_5 ) . system . V_43 =
* ( (struct V_215 * ) V_5 -> V_36 -> V_212 ) ;
else
F_19 ( V_5 ) . system . V_43 =
* ( (struct V_215 * ) V_5 -> V_14 . V_214 ) ;
V_50 = V_211 ;
F_71 ( V_5 ,
V_216 *
V_50 ) ;
}
}
void F_73 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) -> V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_68 ( V_2 , V_5 -> V_14 . V_192 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_37 = F_6 ( V_3 ) -> V_217 ;
V_2 -> V_182 = V_5 -> V_14 . V_218 << 6 ;
F_74 ( V_2 , false ) ;
F_23 ( V_2 ) ;
V_2 -> V_160 = V_50 / V_161 ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_67 ( V_4 ) ;
V_4 -> V_191 = * ( (struct V_215 * ) V_5 -> V_36 -> V_212 ) ;
V_4 -> V_176 = ++ F_19 ( V_5 ) . V_176 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_101 = 0 ;
V_4 -> V_97 = 0 ;
}
}
void F_75 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_219 , * V_220 ;
struct V_4 * V_4 , * V_221 , * V_171 ;
int V_222 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_223 ;
struct V_99 * V_100 ;
bool V_224 ;
F_76 ( & V_5 -> V_225 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_77 ( V_5 -> V_36 , L_29 ,
V_3 -> V_36 -> V_83 ) ;
goto V_226;
}
F_21 ( V_5 -> V_36 , L_30 ,
V_4 -> V_176 ) ;
V_2 -> V_67 &= ~ V_66 ;
F_39 ( V_2 ) ;
F_41 ( V_2 ) ;
if ( V_4 -> V_91 ) {
if ( ( V_4 -> V_91 != V_2 ) ||
( V_4 -> V_91 -> V_92 ) ) {
F_60 (bond, slave_iter, iter) {
V_221 = & ( F_6 ( V_223 ) -> V_4 ) ;
if ( ! V_221 -> V_91 ||
( ( V_221 -> V_91 == V_2 ) &&
! V_221 -> V_91 -> V_92 ) )
break;
}
if ( ! V_223 )
V_221 = NULL ;
if ( ( V_221 ) && ( ( ! V_221 -> V_91 ) || ( ( V_221 -> V_91 == V_2 ) && ! V_221 -> V_91 -> V_92 ) ) ) {
F_21 ( V_5 -> V_36 , L_31 ,
V_4 -> V_176 ,
V_221 -> V_176 ) ;
if ( ( V_221 -> V_91 == V_2 ) &&
V_221 -> V_101 ) {
F_78 ( V_5 -> V_36 , L_32 ) ;
V_222 = 1 ;
}
V_221 -> V_180 = V_4 -> V_180 ;
V_221 -> V_181 = V_4 -> V_181 ;
V_221 -> V_177 = V_4 -> V_177 ;
V_221 -> V_8 = V_4 -> V_8 ;
V_221 -> V_62 = V_4 -> V_62 ;
V_221 -> V_178 = V_4 -> V_178 ;
V_221 -> V_183 = V_4 -> V_183 ;
V_221 -> V_184 = V_4 -> V_184 ;
V_221 -> V_91 = V_4 -> V_91 ;
V_221 -> V_101 = V_4 -> V_101 ;
V_221 -> V_97 = V_4 -> V_97 ;
for ( V_220 = V_4 -> V_91 ; V_220 ;
V_220 = V_220 -> V_92 ) {
V_220 -> V_4 = V_221 ;
V_220 -> V_175 = V_221 -> V_176 ;
}
F_58 ( V_4 ) ;
if ( V_222 )
F_61 ( F_3 ( V_2 ) ,
& V_224 ) ;
} else {
F_77 ( V_5 -> V_36 , L_33 ) ;
}
} else {
V_222 = V_4 -> V_101 ;
F_58 ( V_4 ) ;
if ( V_222 ) {
F_78 ( V_5 -> V_36 , L_32 ) ;
V_171 = F_3 ( V_2 ) ;
if ( V_171 )
F_61 ( V_171 ,
& V_224 ) ;
}
}
}
F_21 ( V_5 -> V_36 , L_34 , V_2 -> V_37 ) ;
F_60 (bond, slave_iter, iter) {
V_171 = & ( F_6 ( V_223 ) -> V_4 ) ;
V_219 = NULL ;
for ( V_220 = V_171 -> V_91 ; V_220 ;
V_219 = V_220 ,
V_220 = V_220 -> V_92 ) {
if ( V_220 == V_2 ) {
if ( V_219 )
V_219 -> V_92 = V_220 -> V_92 ;
else
V_171 -> V_91 = V_220 -> V_92 ;
V_171 -> V_97 -- ;
if ( V_171 -> V_97 == 0 ) {
V_222 = V_171 -> V_101 ;
F_58 ( V_171 ) ;
if ( V_222 ) {
F_78 ( V_5 -> V_36 , L_32 ) ;
F_61 ( F_3 ( V_2 ) ,
& V_224 ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
V_226:
F_79 ( & V_5 -> V_225 ) ;
}
void F_80 ( struct V_1 * V_5 )
{
struct V_99 * V_100 ;
struct V_3 * V_3 ;
F_81 () ;
F_19 ( V_5 ) . system . V_45 = V_5 -> V_14 . V_213 ;
if ( F_9 ( V_5 -> V_14 . V_214 ) )
F_19 ( V_5 ) . system . V_43 =
* ( (struct V_215 * ) V_5 -> V_36 -> V_212 ) ;
else
F_19 ( V_5 ) . system . V_43 =
* ( (struct V_215 * ) V_5 -> V_14 . V_214 ) ;
F_76 ( & V_5 -> V_225 ) ;
F_60 (bond, slave, iter) {
struct V_2 * V_2 = & ( F_6 ( V_3 ) ) -> V_2 ;
F_23 ( V_2 ) ;
V_2 -> V_90 = true ;
}
F_79 ( & V_5 -> V_225 ) ;
}
void F_82 ( struct V_227 * V_228 )
{
struct V_1 * V_5 = F_83 ( V_228 , struct V_1 ,
V_229 . V_228 ) ;
struct V_4 * V_4 ;
struct V_99 * V_100 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_230 = V_10 ;
bool V_124 = false ;
F_76 ( & V_5 -> V_225 ) ;
F_4 () ;
if ( ! F_84 ( V_5 ) )
goto V_231;
if ( F_19 ( V_5 ) . V_16 &&
! ( -- F_19 ( V_5 ) . V_16 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) -> V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_59 ( L_35 ,
V_5 -> V_36 -> V_83 ) ;
goto V_231;
}
V_4 = F_3 ( V_2 ) ;
F_61 ( V_4 , & V_124 ) ;
}
F_66 ( V_5 ) ;
}
F_38 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_59 ( L_36 ,
V_5 -> V_36 -> V_83 ) ;
goto V_231;
}
F_52 ( NULL , V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 , & V_124 ) ;
F_49 ( V_2 , & V_124 ) ;
F_55 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_69 & V_127 )
V_2 -> V_69 &= ~ V_127 ;
}
V_231:
F_38 (bond, slave, iter) {
if ( V_3 -> V_232 ) {
V_230 = V_233 ;
break;
}
}
F_7 () ;
F_79 ( & V_5 -> V_225 ) ;
if ( V_124 )
F_85 ( V_5 , 0 ) ;
if ( V_230 && F_86 () ) {
F_87 ( V_5 ) ;
F_88 () ;
}
F_89 ( V_5 -> V_234 , & V_5 -> V_229 , V_235 ) ;
}
static int F_90 ( struct V_58 * V_58 , struct V_3 * V_3 ,
T_2 V_105 )
{
struct V_2 * V_2 ;
int V_236 = V_237 ;
if ( V_105 >= sizeof( struct V_58 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_59 ( L_37 ,
V_3 -> V_36 -> V_83 , V_3 -> V_5 -> V_36 -> V_83 ) ;
return V_236 ;
}
switch ( V_58 -> V_194 ) {
case V_238 :
V_236 = V_239 ;
F_21 ( V_3 -> V_5 -> V_36 ,
L_38 ,
V_2 -> V_37 ,
V_3 -> V_36 -> V_83 ) ;
F_91 ( & V_3 -> V_5 -> V_225 ) ;
F_52 ( V_58 , V_2 ) ;
F_92 ( & V_3 -> V_5 -> V_225 ) ;
break;
case V_240 :
V_236 = V_239 ;
switch ( ( (struct V_120 * ) V_58 ) -> V_208 ) {
case V_241 :
F_21 ( V_3 -> V_5 -> V_36 , L_39 ,
V_2 -> V_37 ) ;
F_69 ( (struct V_120 * ) V_58 , V_2 ) ;
break;
case V_209 :
F_21 ( V_3 -> V_5 -> V_36 , L_40 ,
V_2 -> V_37 ) ;
F_70 ( (struct V_120 * ) V_58 , V_2 ) ;
break;
default:
F_21 ( V_3 -> V_5 -> V_36 , L_41 ,
V_2 -> V_37 ) ;
}
}
}
return V_236 ;
}
static void F_74 ( struct V_2 * V_2 , bool V_242 )
{
T_3 V_39 = 0 ;
T_2 V_243 = 0 , V_17 = 0 ;
T_2 V_244 = V_2 -> V_64 ;
V_2 -> V_182 &= ~ ( V_245 | V_148 ) ;
if ( ! V_242 ) {
V_17 = F_20 ( V_2 ) ;
V_243 = ( V_244 & V_245 ) >> 1 ;
V_39 = F_22 ( V_2 ) ;
V_2 -> V_182 |= ( V_17 << 1 ) | V_39 ;
}
V_2 -> V_64 = V_2 -> V_182 ;
if ( V_244 != V_2 -> V_64 ) {
if ( V_39 )
V_2 -> V_69 |= V_146 ;
else
V_2 -> V_69 &= ~ V_146 ;
if ( ! V_242 ) {
if ( ! V_17 ) {
F_53 ( V_2 -> V_3 -> V_36 ,
L_42 ,
V_2 -> V_3 -> V_36 -> V_83 ) ;
} else if ( V_39 && V_243 != V_17 ) {
V_2 -> V_69 |= V_127 ;
}
}
}
}
void F_93 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_77 ( V_3 -> V_5 -> V_36 ,
L_43 ,
V_3 -> V_36 -> V_83 ) ;
return;
}
F_76 ( & V_3 -> V_5 -> V_225 ) ;
F_74 ( V_2 , false ) ;
F_21 ( V_3 -> V_5 -> V_36 , L_44 ,
V_2 -> V_37 , V_3 -> V_36 -> V_83 ) ;
F_79 ( & V_3 -> V_5 -> V_225 ) ;
}
void F_94 ( struct V_3 * V_3 , char V_11 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_77 ( V_3 -> V_5 -> V_36 , L_45 ,
V_3 -> V_36 -> V_83 ) ;
return;
}
F_76 ( & V_3 -> V_5 -> V_225 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_139 = true ;
F_74 ( V_2 , false ) ;
} else {
V_2 -> V_139 = false ;
F_74 ( V_2 , true ) ;
}
F_21 ( V_3 -> V_5 -> V_36 , L_46 ,
V_2 -> V_37 ,
V_11 == V_12 ? L_47 : L_48 ) ;
F_79 ( & V_3 -> V_5 -> V_225 ) ;
F_95 ( V_3 -> V_5 , NULL ) ;
}
int F_66 ( struct V_1 * V_5 )
{
struct V_4 * V_189 ;
struct V_3 * V_6 ;
int V_236 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_236 = 0 ;
goto V_226;
}
V_189 = F_37 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_189 ) {
if ( V_189 -> V_97 < V_5 -> V_14 . V_246 ) {
if ( F_65 ( V_5 -> V_36 ) ) {
F_96 ( V_5 -> V_36 ) ;
goto V_226;
}
} else if ( ! F_65 ( V_5 -> V_36 ) ) {
F_97 ( V_5 -> V_36 ) ;
goto V_226;
}
} else if ( F_65 ( V_5 -> V_36 ) ) {
F_96 ( V_5 -> V_36 ) ;
}
V_226:
F_7 () ;
return V_236 ;
}
int F_98 ( struct V_1 * V_5 ,
struct V_247 * V_247 )
{
struct V_4 * V_4 = NULL ;
struct V_99 * V_100 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_38 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_101 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( ! V_4 )
return - 1 ;
V_247 -> V_248 = V_4 -> V_176 ;
V_247 -> V_249 = V_4 -> V_97 ;
V_247 -> V_79 = V_4 -> V_177 ;
V_247 -> V_63 = V_4 -> V_178 ;
F_45 ( V_247 -> V_8 ,
V_4 -> V_8 . V_9 ) ;
return 0 ;
}
int F_99 ( struct V_1 * V_5 , struct V_247 * V_247 )
{
int V_236 ;
F_4 () ;
V_236 = F_98 ( V_5 , V_247 ) ;
F_7 () ;
return V_236 ;
}
int F_100 ( const struct V_102 * V_103 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
struct V_58 * V_58 , V_250 ;
if ( V_103 -> V_110 != V_111 )
return V_237 ;
if ( ! F_27 ( F_101 ( V_103 ) -> V_115 , V_116 ) )
return V_237 ;
V_58 = F_102 ( V_103 , 0 , sizeof( V_250 ) , & V_250 ) ;
if ( ! V_58 )
return V_237 ;
return F_90 ( V_58 , V_3 , V_103 -> V_251 ) ;
}
void F_103 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_99 * V_100 ;
struct V_3 * V_3 ;
int V_192 ;
V_192 = V_5 -> V_14 . V_192 ;
F_76 ( & V_5 -> V_225 ) ;
F_60 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_192 )
V_2 -> V_67 |= V_89 ;
else
V_2 -> V_67 &= ~ V_89 ;
}
F_79 ( & V_5 -> V_225 ) ;
}
