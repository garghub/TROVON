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
static T_2 F_23 ( T_2 V_42 , T_2 V_43 )
{
T_2 V_38 = 0 ;
switch ( V_42 ) {
case V_44 :
if ( V_43 )
V_38 = ( V_45 * V_46 ) ;
else
V_38 = ( V_47 * V_46 ) ;
break;
case V_48 :
V_38 = ( V_49 * V_46 ) ;
break;
case V_50 :
V_38 = ( V_43 * V_46 ) ;
break;
case V_51 :
V_38 = ( V_49 * V_46 ) ;
break;
case V_52 :
V_38 = ( V_53 * V_46 ) ;
break;
}
return V_38 ;
}
static void F_24 ( struct V_54 * V_54 , struct V_2 * V_2 )
{
if ( ( ( F_25 ( V_54 -> V_55 ) == V_2 -> V_37 ) &&
( F_25 ( V_54 -> V_56 ) == V_2 -> V_57 ) &&
F_26 ( & ( V_54 -> V_8 ) , & ( V_2 -> V_58 ) ) &&
( F_25 ( V_54 -> V_59 ) == V_2 -> V_60 ) &&
( F_25 ( V_54 -> V_61 ) == V_2 -> V_62 ) &&
( ( V_54 -> V_63 & V_64 ) == ( V_2 -> V_65 & V_64 ) ) ) ||
( ( V_54 -> V_66 & V_64 ) == 0 )
) {
V_2 -> V_67 |= V_68 ;
} else {
V_2 -> V_67 &= ~ V_68 ;
}
}
static void F_27 ( struct V_54 * V_54 , struct V_2 * V_2 )
{
if ( V_54 && V_2 ) {
struct V_69 * V_70 = & V_2 -> V_71 ;
F_24 ( V_54 , V_2 ) ;
V_70 -> V_72 = F_25 ( V_54 -> V_73 ) ;
V_70 -> V_74 = F_25 ( V_54 -> V_57 ) ;
V_70 -> system = V_54 -> V_58 ;
V_70 -> V_75 = F_25 ( V_54 -> V_60 ) ;
V_70 -> V_76 = F_25 ( V_54 -> V_77 ) ;
V_70 -> V_78 = V_54 -> V_66 ;
V_2 -> V_65 &= ~ V_79 ;
if ( ( V_2 -> V_67 & V_68 ) &&
( V_54 -> V_66 & V_80 ) ) {
V_70 -> V_78 |= V_80 ;
F_28 ( L_4 , V_2 -> V_3 -> V_36 -> V_81 ) ;
} else {
V_70 -> V_78 &= ~ V_80 ;
F_28 ( L_5 , V_2 -> V_3 -> V_36 -> V_81 ) ;
}
}
}
static void F_29 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_71 , & V_2 -> V_82 ,
sizeof( struct V_69 ) ) ;
V_2 -> V_65 |= V_79 ;
}
}
static void F_30 ( struct V_54 * V_54 , struct V_2 * V_2 )
{
if ( V_54 && V_2 ) {
const struct V_69 * V_70 = & V_2 -> V_71 ;
if ( F_25 ( V_54 -> V_73 ) != V_70 -> V_72 ||
F_25 ( V_54 -> V_57 ) != V_70 -> V_74 ||
! F_26 ( & V_54 -> V_58 , & V_70 -> system ) ||
F_25 ( V_54 -> V_60 ) != V_70 -> V_75 ||
F_25 ( V_54 -> V_77 ) != V_70 -> V_76 ||
( V_54 -> V_66 & V_64 ) != ( V_70 -> V_78 & V_64 ) ) {
V_2 -> V_67 &= ~ V_83 ;
}
}
}
static void F_31 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_69 * V_84 = & V_2 -> V_82 ;
const struct V_69 * V_85 = & V_2 -> V_71 ;
if ( V_84 -> V_72 != V_85 -> V_72 ||
V_84 -> V_74 != V_85 -> V_74 ||
! F_26 ( & V_84 -> system , & V_85 -> system ) ||
V_84 -> V_75 != V_85 -> V_75 ||
V_84 -> V_76 != V_85 -> V_76 ||
( V_84 -> V_78 & V_64 )
!= ( V_85 -> V_78 & V_64 ) ) {
V_2 -> V_67 &= ~ V_83 ;
}
}
}
static void F_32 ( struct V_54 * V_54 , struct V_2 * V_2 )
{
if ( V_54 && V_2 ) {
if ( ( F_25 ( V_54 -> V_55 ) != V_2 -> V_37 ) ||
( F_25 ( V_54 -> V_56 ) != V_2 -> V_57 ) ||
! F_26 ( & ( V_54 -> V_8 ) , & ( V_2 -> V_58 ) ) ||
( F_25 ( V_54 -> V_59 ) != V_2 -> V_60 ) ||
( F_25 ( V_54 -> V_61 ) != V_2 -> V_62 ) ||
( ( V_54 -> V_63 & V_86 ) != ( V_2 -> V_65 & V_86 ) ) ||
( ( V_54 -> V_63 & V_87 ) != ( V_2 -> V_65 & V_87 ) ) ||
( ( V_54 -> V_63 & V_80 ) != ( V_2 -> V_65 & V_80 ) ) ||
( ( V_54 -> V_63 & V_64 ) != ( V_2 -> V_65 & V_64 ) )
) {
V_2 -> V_88 = true ;
}
}
}
static int F_33 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_38 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_89 ;
V_2 ;
V_2 = V_2 -> V_90 ) {
if ( ! ( V_2 -> V_67 & V_91 ) ) {
V_38 = 0 ;
break;
}
}
}
return V_38 ;
}
static void F_34 ( struct V_4 * V_4 , int V_92 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_89 ; V_2 ;
V_2 = V_2 -> V_90 ) {
if ( V_92 )
V_2 -> V_67 |= V_93 ;
else
V_2 -> V_67 &= ~ V_93 ;
}
}
static T_1 F_35 ( struct V_4 * V_4 )
{
T_1 V_94 = 0 ;
if ( V_4 -> V_95 ) {
switch ( F_20 ( V_4 -> V_89 ) ) {
case V_96 :
V_94 = V_4 -> V_95 ;
break;
case V_19 :
V_94 = V_4 -> V_95 * 10 ;
break;
case V_21 :
V_94 = V_4 -> V_95 * 100 ;
break;
case V_23 :
V_94 = V_4 -> V_95 * 1000 ;
break;
case V_25 :
V_94 = V_4 -> V_95 * 2500 ;
break;
case V_27 :
V_94 = V_4 -> V_95 * 10000 ;
break;
case V_29 :
V_94 = V_4 -> V_95 * 20000 ;
break;
case V_31 :
V_94 = V_4 -> V_95 * 40000 ;
break;
case V_33 :
V_94 = V_4 -> V_95 * 56000 ;
break;
case V_35 :
V_94 = V_4 -> V_95 * 100000 ;
break;
default:
V_94 = 0 ;
}
}
return V_94 ;
}
static struct V_4 * F_36 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_97 * V_98 ;
struct V_3 * V_3 ;
F_37 (bond, slave, iter)
if ( F_6 ( V_3 ) -> V_4 . V_99 )
return & ( F_6 ( V_3 ) -> V_4 ) ;
return NULL ;
}
static inline void F_38 ( struct V_2 * V_2 )
{
struct V_54 * V_54 = & V_2 -> V_54 ;
const struct V_69 * V_70 = & V_2 -> V_71 ;
V_54 -> V_60 = F_39 ( V_2 -> V_60 ) ;
V_54 -> V_58 = V_2 -> V_58 ;
V_54 -> V_77 = F_39 ( V_2 -> V_62 ) ;
V_54 -> V_57 = F_39 ( V_2 -> V_57 ) ;
V_54 -> V_73 = F_39 ( V_2 -> V_37 ) ;
V_54 -> V_66 = V_2 -> V_65 ;
F_28 ( L_6 ,
V_2 -> V_3 -> V_36 -> V_81 , V_2 -> V_65 ) ;
V_54 -> V_59 = F_39 ( V_70 -> V_75 ) ;
V_54 -> V_8 = V_70 -> system ;
V_54 -> V_61 = F_39 ( V_70 -> V_76 ) ;
V_54 -> V_56 = F_39 ( V_70 -> V_74 ) ;
V_54 -> V_55 = F_39 ( V_70 -> V_72 ) ;
V_54 -> V_63 = V_70 -> V_78 ;
}
static int F_40 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_100 * V_101 ;
struct V_102 * V_102 ;
int V_103 = sizeof( struct V_102 ) ;
V_101 = F_41 ( V_103 ) ;
if ( ! V_101 )
return - V_104 ;
V_101 -> V_36 = V_3 -> V_36 ;
F_42 ( V_101 ) ;
V_101 -> V_105 = V_101 -> V_106 + V_107 ;
V_101 -> V_108 = V_109 ;
V_101 -> V_110 = V_111 ;
V_102 = (struct V_102 * ) F_43 ( V_101 , V_103 ) ;
F_44 ( V_102 -> V_112 . V_113 , V_114 ) ;
F_44 ( V_102 -> V_112 . V_115 , V_3 -> V_116 ) ;
V_102 -> V_112 . V_117 = V_109 ;
V_102 -> V_54 = V_2 -> V_54 ;
F_45 ( V_101 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_2 , struct V_118 * V_119 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_100 * V_101 ;
struct V_120 * V_121 ;
int V_103 = sizeof( struct V_120 ) ;
V_101 = F_41 ( V_103 + 16 ) ;
if ( ! V_101 )
return - V_104 ;
F_47 ( V_101 , 16 ) ;
V_101 -> V_36 = V_3 -> V_36 ;
F_42 ( V_101 ) ;
V_101 -> V_105 = V_101 -> V_106 + V_107 ;
V_101 -> V_108 = V_109 ;
V_121 = (struct V_120 * ) F_43 ( V_101 , V_103 ) ;
F_44 ( V_121 -> V_112 . V_113 , V_114 ) ;
F_44 ( V_121 -> V_112 . V_115 , V_3 -> V_116 ) ;
V_121 -> V_112 . V_117 = V_109 ;
V_121 -> V_119 = * V_119 ;
F_45 ( V_101 ) ;
return 0 ;
}
static void F_48 ( struct V_2 * V_2 , bool * V_122 )
{
T_4 V_123 ;
V_123 = V_2 -> V_124 ;
if ( V_2 -> V_67 & V_125 ) {
V_2 -> V_124 = V_126 ;
} else {
switch ( V_2 -> V_124 ) {
case V_126 :
if ( ( V_2 -> V_67 & V_83 )
|| ( V_2 -> V_67 & V_127 ) )
V_2 -> V_124 = V_128 ;
break;
case V_128 :
if ( ! ( V_2 -> V_67 & V_83 ) ) {
V_2 -> V_67 &= ~ V_91 ;
F_34 ( V_2 -> V_4 , F_33 ( V_2 -> V_4 ) ) ;
V_2 -> V_124 = V_126 ;
break;
}
if ( V_2 -> V_129
&& ! ( -- V_2 -> V_129 ) )
V_2 -> V_67 |= V_91 ;
F_34 ( V_2 -> V_4 , F_33 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_67 & V_93 )
&& ! V_2 -> V_129 )
V_2 -> V_124 = V_130 ;
break;
case V_130 :
if ( ( V_2 -> V_67 & V_83 ) &&
( V_2 -> V_71 . V_78 & V_80 ) &&
! F_18 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_99 )
V_2 -> V_124 =
V_131 ;
} else if ( ! ( V_2 -> V_67 & V_83 ) ||
( V_2 -> V_67 & V_127 ) ) {
V_2 -> V_67 &= ~ V_91 ;
F_34 ( V_2 -> V_4 , F_33 ( V_2 -> V_4 ) ) ;
V_2 -> V_124 = V_126 ;
} else if ( V_2 -> V_4 -> V_99 ) {
V_2 -> V_65 |=
V_80 ;
}
break;
case V_131 :
if ( ! ( V_2 -> V_67 & V_83 ) ||
( V_2 -> V_67 & V_127 ) ||
! ( V_2 -> V_71 . V_78 & V_80 ) ||
! ( V_2 -> V_65 & V_80 ) ) {
V_2 -> V_124 = V_130 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_99 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_124 != V_123 ) {
F_28 ( L_7 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_81 ,
V_123 ,
V_2 -> V_124 ) ;
switch ( V_2 -> V_124 ) {
case V_126 :
V_2 -> V_65 &= ~ V_80 ;
F_49 ( V_2 ,
V_122 ) ;
V_2 -> V_65 &= ~ V_132 ;
V_2 -> V_65 &= ~ V_133 ;
V_2 -> V_88 = true ;
break;
case V_128 :
V_2 -> V_129 = F_23 ( V_52 , 0 ) ;
break;
case V_130 :
if ( V_2 -> V_4 -> V_99 )
V_2 -> V_65 |=
V_80 ;
else
V_2 -> V_65 &=
~ V_80 ;
V_2 -> V_65 &= ~ V_132 ;
V_2 -> V_65 &= ~ V_133 ;
F_49 ( V_2 ,
V_122 ) ;
V_2 -> V_88 = true ;
break;
case V_131 :
V_2 -> V_65 |= V_132 ;
V_2 -> V_65 |= V_133 ;
V_2 -> V_65 |= V_80 ;
F_50 ( V_2 ,
V_122 ) ;
V_2 -> V_88 = true ;
break;
default:
break;
}
}
}
static void F_51 ( struct V_54 * V_54 , struct V_2 * V_2 )
{
T_5 V_123 ;
V_123 = V_2 -> V_134 ;
if ( V_2 -> V_67 & V_125 ) {
V_2 -> V_134 = V_135 ;
V_2 -> V_67 |= V_136 ;
} else if ( ! ( V_2 -> V_67 & V_125 )
&& ! V_2 -> V_137 && ! ( V_2 -> V_67 & V_138 ) )
V_2 -> V_134 = V_139 ;
else if ( V_54 && ( ( V_2 -> V_134 == V_140 ) ||
( V_2 -> V_134 == V_141 ) ||
( V_2 -> V_134 == V_142 ) ) ) {
if ( V_2 -> V_134 != V_142 )
V_2 -> V_67 |= V_136 ;
V_2 -> V_143 = 0 ;
V_2 -> V_134 = V_142 ;
} else {
if ( V_2 -> V_143 &&
! ( -- V_2 -> V_143 ) ) {
switch ( V_2 -> V_134 ) {
case V_140 :
V_2 -> V_134 = V_141 ;
break;
case V_142 :
V_2 -> V_134 = V_140 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_134 ) {
case V_139 :
if ( V_2 -> V_67 & V_138 )
V_2 -> V_134 = V_135 ;
else if ( V_2 -> V_137
&& ( V_2 -> V_67
& V_144 ) )
V_2 -> V_134 = V_140 ;
else if ( V_2 -> V_137
&& ( ( V_2 -> V_67
& V_144 ) == 0 ) )
V_2 -> V_134 = V_145 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_134 != V_123 ) || ( V_54 ) ) {
F_28 ( L_8 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_81 ,
V_123 ,
V_2 -> V_134 ) ;
switch ( V_2 -> V_134 ) {
case V_135 :
if ( ! ( V_2 -> V_62 & V_146 ) )
V_2 -> V_67 &= ~ V_144 ;
else
V_2 -> V_67 |= V_144 ;
V_2 -> V_67 &= ~ V_83 ;
F_29 ( V_2 ) ;
V_2 -> V_65 &= ~ V_147 ;
V_2 -> V_67 &= ~ V_138 ;
V_2 -> V_134 = V_139 ;
case V_139 :
V_2 -> V_67 &= ~ V_68 ;
break;
case V_145 :
V_2 -> V_67 &= ~ V_83 ;
F_29 ( V_2 ) ;
V_2 -> V_71 . V_78 &= ~ V_64 ;
V_2 -> V_67 |= V_68 ;
V_2 -> V_65 &= ~ V_147 ;
break;
case V_140 :
V_2 -> V_71 . V_78 &= ~ V_80 ;
V_2 -> V_67 &= ~ V_68 ;
V_2 -> V_71 . V_78 |= V_87 ;
V_2 -> V_71 . V_78 |= V_86 ;
V_2 -> V_143 = F_23 ( V_44 , ( T_2 ) ( V_148 ) ) ;
V_2 -> V_65 |= V_147 ;
V_2 -> V_67 |= V_136 ;
break;
case V_141 :
F_31 ( V_2 ) ;
F_29 ( V_2 ) ;
V_2 -> V_67 |= V_68 ;
V_2 -> V_65 &= ~ V_147 ;
break;
case V_142 :
if ( F_26 ( & ( V_54 -> V_58 ) ,
& ( V_2 -> V_58 ) ) ) {
F_52 ( V_2 -> V_3 -> V_5 -> V_36 , L_9
L_10 ,
V_2 -> V_3 -> V_36 -> V_81 ) ;
return;
}
F_30 ( V_54 , V_2 ) ;
F_32 ( V_54 , V_2 ) ;
F_27 ( V_54 , V_2 ) ;
V_2 -> V_143 = F_23 ( V_44 , ( T_2 ) ( V_2 -> V_65 & V_87 ) ) ;
V_2 -> V_65 &= ~ V_147 ;
break;
default:
break;
}
}
}
static void F_53 ( struct V_2 * V_2 )
{
if ( V_2 -> V_67 & V_136 ) {
V_2 -> V_67 &= ~ V_136 ;
V_2 -> V_149 = V_150 ;
V_2 -> V_151 = V_150 ;
V_2 -> V_152 =
F_23 ( V_48 , 0 ) ;
V_2 -> V_153 =
F_23 ( V_51 , 0 ) ;
return;
}
if ( V_2 -> V_152 &&
! ( -- V_2 -> V_152 ) &&
V_2 -> V_149 == V_150 ) {
if ( V_2 -> V_65 & V_80 ) {
V_2 -> V_149 = V_154 ;
} else {
V_2 -> V_155 ++ ;
V_2 -> V_149 = V_156 ;
}
}
if ( V_2 -> V_153 &&
! ( -- V_2 -> V_153 ) &&
V_2 -> V_151 == V_150 ) {
if ( V_2 -> V_71 . V_78 & V_80 ) {
V_2 -> V_151 = V_154 ;
} else {
V_2 -> V_157 ++ ;
V_2 -> V_151 = V_156 ;
}
}
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_158 && ! ( -- V_2 -> V_158 ) ) {
if ( V_2 -> V_88 && ( V_2 -> V_67 & V_144 ) ) {
F_38 ( V_2 ) ;
if ( F_40 ( V_2 ) >= 0 ) {
F_28 ( L_11 ,
V_2 -> V_37 ) ;
V_2 -> V_88 = false ;
}
}
V_2 -> V_158 = V_46 / V_159 ;
}
}
static void F_55 ( struct V_2 * V_2 )
{
T_6 V_123 ;
V_123 = V_2 -> V_160 ;
if ( ( ( V_2 -> V_67 & V_125 ) || ! ( V_2 -> V_67 & V_144 ) || ! V_2 -> V_137 ) ||
( ! ( V_2 -> V_65 & V_86 ) && ! ( V_2 -> V_71 . V_78 & V_86 ) )
) {
V_2 -> V_160 = V_161 ;
}
else if ( V_2 -> V_162 ) {
if ( ! ( -- V_2 -> V_162 ) ) {
V_2 -> V_160 = V_163 ;
} else {
switch ( V_2 -> V_160 ) {
case V_164 :
if ( ! ( V_2 -> V_71 . V_78
& V_87 ) )
V_2 -> V_160 = V_165 ;
break;
case V_165 :
if ( ( V_2 -> V_71 . V_78 & V_87 ) ) {
V_2 -> V_162 = 0 ;
V_2 -> V_160 = V_163 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_160 ) {
case V_161 :
V_2 -> V_160 = V_164 ;
break;
case V_163 :
if ( ! ( V_2 -> V_71 . V_78 &
V_87 ) )
V_2 -> V_160 = V_165 ;
else
V_2 -> V_160 = V_164 ;
break;
default:
break;
}
}
if ( V_2 -> V_160 != V_123 ) {
F_28 ( L_12 ,
V_2 -> V_37 , V_123 ,
V_2 -> V_160 ) ;
switch ( V_2 -> V_160 ) {
case V_161 :
V_2 -> V_162 = 0 ;
break;
case V_164 :
V_2 -> V_162 = F_23 ( V_50 , ( T_2 ) ( V_166 ) ) - 1 ;
break;
case V_165 :
V_2 -> V_162 = F_23 ( V_50 , ( T_2 ) ( V_167 ) ) - 1 ;
break;
case V_163 :
V_2 -> V_88 = true ;
break;
default:
break;
}
}
}
static void F_56 ( struct V_2 * V_2 , bool * V_122 )
{
struct V_4 * V_4 , * V_168 = NULL , * V_169 ;
struct V_2 * V_170 = NULL , * V_171 ;
struct V_97 * V_98 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_172 = 0 ;
if ( V_2 -> V_67 & V_83 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_169 = V_2 -> V_4 ;
for ( V_171 = V_169 -> V_89 ; V_171 ;
V_170 = V_171 ,
V_171 = V_171 -> V_90 ) {
if ( V_171 == V_2 ) {
V_169 -> V_95 -- ;
if ( ! V_170 ) {
V_169 -> V_89 =
V_2 -> V_90 ;
} else {
V_170 -> V_90 =
V_2 -> V_90 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_90 = NULL ;
V_2 -> V_173 = 0 ;
F_21 ( V_5 -> V_36 , L_13 ,
V_2 -> V_37 ,
V_169 -> V_174 ) ;
if ( ! V_169 -> V_89 )
F_57 ( V_169 ) ;
break;
}
}
if ( ! V_171 ) {
F_58 ( L_14 ,
V_2 -> V_3 -> V_5 -> V_36 -> V_81 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_81 ,
V_2 -> V_4 -> V_174 ) ;
}
}
F_59 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_89 ) {
if ( ! V_168 )
V_168 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_175 == V_2 -> V_62 ) &&
F_26 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_71 . system ) ) &&
( V_4 -> V_59 == V_2 -> V_71 . V_75 ) &&
( V_4 -> V_176 == V_2 -> V_71 . V_76 )
) &&
( ( ! F_26 ( & ( V_2 -> V_71 . system ) , & ( V_177 ) ) &&
! V_4 -> V_178 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_173 =
V_2 -> V_4 -> V_174 ;
V_2 -> V_90 = V_4 -> V_89 ;
V_2 -> V_4 -> V_95 ++ ;
V_4 -> V_89 = V_2 ;
F_21 ( V_5 -> V_36 , L_15 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_174 ) ;
V_2 -> V_67 |= V_83 ;
V_172 = 1 ;
break;
}
}
if ( ! V_172 ) {
if ( V_168 ) {
V_2 -> V_4 = V_168 ;
V_2 -> V_173 =
V_2 -> V_4 -> V_174 ;
if ( V_2 -> V_62 & V_146 )
V_2 -> V_4 -> V_178 = false ;
else
V_2 -> V_4 -> V_178 = true ;
V_2 -> V_4 -> V_179 =
V_2 -> V_180 ;
V_2 -> V_4 -> V_175 =
V_2 -> V_62 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_71 . system ;
V_2 -> V_4 -> V_59 =
V_2 -> V_71 . V_75 ;
V_2 -> V_4 -> V_176 = V_2 -> V_71 . V_76 ;
V_2 -> V_4 -> V_181 = 1 ;
V_2 -> V_4 -> V_182 = 1 ;
V_2 -> V_4 -> V_89 = V_2 ;
V_2 -> V_4 -> V_95 ++ ;
V_2 -> V_67 |= V_83 ;
F_21 ( V_5 -> V_36 , L_16 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_174 ) ;
} else {
F_52 ( V_5 -> V_36 , L_17 ,
V_2 -> V_37 , V_2 -> V_3 -> V_36 -> V_81 ) ;
}
}
F_34 ( V_2 -> V_4 ,
F_33 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_60 ( V_4 , V_122 ) ;
if ( ! V_2 -> V_4 -> V_99 )
V_2 -> V_65 &= ~ V_80 ;
}
static struct V_4 * F_61 ( struct V_4 * V_183 ,
struct V_4 * V_184 )
{
if ( ! V_183 )
return V_184 ;
if ( ! V_184 -> V_178 && V_183 -> V_178 )
return V_184 ;
if ( V_184 -> V_178 && ! V_183 -> V_178 )
return V_183 ;
if ( F_8 ( V_184 ) && ! F_8 ( V_183 ) )
return V_184 ;
if ( ! F_8 ( V_184 ) && F_8 ( V_183 ) )
return V_183 ;
switch ( F_17 ( V_184 -> V_89 ) ) {
case V_185 :
if ( V_184 -> V_95 > V_183 -> V_95 )
return V_184 ;
if ( V_184 -> V_95 < V_183 -> V_95 )
return V_183 ;
case V_13 :
case V_186 :
if ( F_35 ( V_184 ) > F_35 ( V_183 ) )
return V_184 ;
break;
default:
F_58 ( L_18 ,
V_184 -> V_3 -> V_5 -> V_36 -> V_81 ,
F_17 ( V_184 -> V_89 ) ) ;
break;
}
return V_183 ;
}
static int F_62 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_89 ;
if ( ! V_2 )
return 0 ;
return F_63 ( V_2 -> V_3 -> V_36 ) &&
F_64 ( V_2 -> V_3 -> V_36 ) ;
}
static void F_60 ( struct V_4 * V_7 ,
bool * V_122 )
{
struct V_4 * V_183 , * V_187 , * V_188 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_97 * V_98 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_188 = V_7 ;
V_187 = F_36 ( V_7 ) ;
V_183 = ( V_187 && F_62 ( V_187 ) ) ? V_187 : NULL ;
F_37 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_99 = 0 ;
if ( V_7 -> V_95 && F_62 ( V_7 ) )
V_183 = F_61 ( V_183 , V_7 ) ;
}
if ( V_183 &&
F_17 ( V_183 -> V_89 ) == V_13 ) {
if ( V_187 && V_187 -> V_89 &&
V_187 -> V_89 -> V_137 &&
( F_8 ( V_187 ) ||
( ! F_8 ( V_187 ) &&
! F_8 ( V_183 ) ) ) ) {
if ( ! ( ! V_187 -> V_175 &&
V_183 -> V_175 ) ) {
V_183 = NULL ;
V_187 -> V_99 = 1 ;
}
}
}
if ( V_183 && ( V_183 == V_187 ) ) {
V_183 = NULL ;
V_187 -> V_99 = 1 ;
}
if ( V_183 ) {
F_21 ( V_5 -> V_36 , L_19 ,
V_183 -> V_174 , V_183 -> V_95 ,
V_183 -> V_175 ,
V_183 -> V_176 ,
V_183 -> V_178 , V_183 -> V_99 ) ;
F_21 ( V_5 -> V_36 , L_20 ,
V_183 -> V_89 , V_183 -> V_3 ,
V_183 -> V_3 ? V_183 -> V_3 -> V_36 -> V_81 : L_21 ) ;
F_37 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_21 ( V_5 -> V_36 , L_22 ,
V_7 -> V_174 , V_7 -> V_95 ,
V_7 -> V_175 ,
V_7 -> V_176 ,
V_7 -> V_178 , V_7 -> V_99 ) ;
}
if ( V_183 -> V_178 ) {
F_58 ( L_23 ,
V_183 -> V_3 ?
V_183 -> V_3 -> V_5 -> V_36 -> V_81 : L_21 ) ;
}
V_183 -> V_99 = 1 ;
F_21 ( V_5 -> V_36 , L_24 ,
V_183 -> V_174 ) ;
F_21 ( V_5 -> V_36 , L_22 ,
V_183 -> V_174 , V_183 -> V_95 ,
V_183 -> V_175 ,
V_183 -> V_176 ,
V_183 -> V_178 , V_183 -> V_99 ) ;
if ( V_187 ) {
for ( V_2 = V_187 -> V_89 ; V_2 ;
V_2 = V_2 -> V_90 ) {
F_10 ( V_2 ) ;
}
}
* V_122 = true ;
}
V_187 = F_36 ( V_188 ) ;
if ( V_187 ) {
if ( ! F_8 ( V_187 ) ) {
for ( V_2 = V_187 -> V_89 ; V_2 ;
V_2 = V_2 -> V_90 ) {
F_12 ( V_2 ) ;
}
}
}
F_7 () ;
F_65 ( V_5 ) ;
}
static void F_57 ( struct V_4 * V_4 )
{
if ( V_4 ) {
V_4 -> V_178 = false ;
V_4 -> V_179 = 0 ;
V_4 -> V_175 = 0 ;
V_4 -> V_8 = V_177 ;
V_4 -> V_59 = 0 ;
V_4 -> V_176 = 0 ;
V_4 -> V_181 = 0 ;
V_4 -> V_182 = 0 ;
V_4 -> V_89 = NULL ;
V_4 -> V_99 = 0 ;
V_4 -> V_95 = 0 ;
F_28 ( L_25 ,
V_4 -> V_174 ) ;
}
}
static void F_66 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_57 ( V_4 ) ;
V_4 -> V_189 = V_177 ;
V_4 -> V_174 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_67 ( struct V_2 * V_2 , int V_190 )
{
static const struct V_69 V_191 = {
. V_75 = 0xffff ,
. V_76 = 1 ,
. V_72 = 1 ,
. V_74 = 0xff ,
. V_78 = 1 ,
} ;
static const struct V_54 V_54 = {
. V_192 = 0x01 ,
. V_193 = 0x01 ,
. V_194 = 0x01 ,
. V_195 = 0x14 ,
. V_196 = 0x02 ,
. V_197 = 0x14 ,
. V_198 = 0x03 ,
. V_199 = 0x10 ,
. V_200 = F_39 ( V_201 ) ,
} ;
if ( V_2 ) {
V_2 -> V_57 = 0xff ;
V_2 -> V_173 = 0 ;
V_2 -> V_88 = false ;
V_2 -> V_202 = V_64 |
V_86 ;
V_2 -> V_65 = V_64 |
V_86 ;
if ( V_190 )
V_2 -> V_65 |= V_87 ;
memcpy ( & V_2 -> V_82 , & V_191 , sizeof( V_191 ) ) ;
memcpy ( & V_2 -> V_71 , & V_191 , sizeof( V_191 ) ) ;
V_2 -> V_137 = true ;
V_2 -> V_67 = V_125 | V_144 ;
V_2 -> V_134 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_160 = 0 ;
V_2 -> V_162 = 0 ;
V_2 -> V_124 = 0 ;
V_2 -> V_129 = 0 ;
V_2 -> V_203 = 0 ;
V_2 -> V_4 = NULL ;
V_2 -> V_90 = NULL ;
V_2 -> V_204 = 0 ;
V_2 -> V_152 = 0 ;
V_2 -> V_149 = 0 ;
V_2 -> V_155 = 0 ;
V_2 -> V_153 = 0 ;
V_2 -> V_151 = 0 ;
V_2 -> V_157 = 0 ;
memcpy ( & V_2 -> V_54 , & V_54 , sizeof( V_54 ) ) ;
}
}
static void F_50 ( struct V_2 * V_2 ,
bool * V_122 )
{
if ( V_2 -> V_4 -> V_99 ) {
F_28 ( L_26 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_174 ) ;
F_12 ( V_2 ) ;
* V_122 = true ;
}
}
static void F_49 ( struct V_2 * V_2 ,
bool * V_122 )
{
if ( V_2 -> V_4 &&
! F_26 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_177 ) ) ) {
F_28 ( L_27 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_174 ) ;
F_10 ( V_2 ) ;
* V_122 = true ;
}
}
static void F_68 ( struct V_118 * V_205 ,
struct V_2 * V_2 )
{
struct V_118 V_119 ;
memcpy ( & V_119 , V_205 , sizeof( struct V_118 ) ) ;
V_119 . V_206 = V_207 ;
if ( F_46 ( V_2 , & V_119 ) >= 0 ) {
F_28 ( L_28 ,
V_2 -> V_37 ) ;
}
}
static void F_69 ( struct V_118 * V_119 ,
struct V_2 * V_2 )
{
}
void F_70 ( struct V_1 * V_5 , int V_208 )
{
F_19 ( V_5 ) . V_16 = V_208 ;
}
void F_71 ( struct V_1 * V_5 , T_2 V_209 )
{
if ( ! F_26 ( & ( F_19 ( V_5 ) . system . V_210 ) ,
V_5 -> V_36 -> V_211 ) ) {
F_19 ( V_5 ) . V_174 = 0 ;
F_19 ( V_5 ) . system . V_212 =
V_5 -> V_14 . V_213 ;
if ( F_9 ( V_5 -> V_14 . V_214 ) )
F_19 ( V_5 ) . system . V_210 =
* ( (struct V_215 * ) V_5 -> V_36 -> V_211 ) ;
else
F_19 ( V_5 ) . system . V_210 =
* ( (struct V_215 * ) V_5 -> V_14 . V_214 ) ;
V_46 = V_209 ;
F_70 ( V_5 ,
V_216 *
V_46 ) ;
}
}
void F_72 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) -> V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_67 ( V_2 , V_5 -> V_14 . V_190 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_37 = F_6 ( V_3 ) -> V_217 ;
V_2 -> V_180 = V_5 -> V_14 . V_218 << 6 ;
F_73 ( V_2 , false ) ;
V_2 -> V_58 = F_19 ( V_5 ) . system . V_210 ;
V_2 -> V_60 =
F_19 ( V_5 ) . system . V_212 ;
V_2 -> V_158 = V_46 / V_159 ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_66 ( V_4 ) ;
V_4 -> V_189 = * ( (struct V_215 * ) V_5 -> V_36 -> V_211 ) ;
V_4 -> V_174 = ++ F_19 ( V_5 ) . V_174 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_99 = 0 ;
V_4 -> V_95 = 0 ;
}
}
void F_74 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_219 , * V_220 ;
struct V_4 * V_4 , * V_221 , * V_169 ;
int V_222 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_223 ;
struct V_97 * V_98 ;
bool V_224 ;
F_75 ( & V_5 -> V_225 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_76 ( V_5 -> V_36 , L_29 ,
V_3 -> V_36 -> V_81 ) ;
goto V_226;
}
F_21 ( V_5 -> V_36 , L_30 ,
V_4 -> V_174 ) ;
V_2 -> V_65 &= ~ V_64 ;
F_38 ( V_2 ) ;
F_40 ( V_2 ) ;
if ( V_4 -> V_89 ) {
if ( ( V_4 -> V_89 != V_2 ) ||
( V_4 -> V_89 -> V_90 ) ) {
F_59 (bond, slave_iter, iter) {
V_221 = & ( F_6 ( V_223 ) -> V_4 ) ;
if ( ! V_221 -> V_89 ||
( ( V_221 -> V_89 == V_2 ) &&
! V_221 -> V_89 -> V_90 ) )
break;
}
if ( ! V_223 )
V_221 = NULL ;
if ( ( V_221 ) && ( ( ! V_221 -> V_89 ) || ( ( V_221 -> V_89 == V_2 ) && ! V_221 -> V_89 -> V_90 ) ) ) {
F_21 ( V_5 -> V_36 , L_31 ,
V_4 -> V_174 ,
V_221 -> V_174 ) ;
if ( ( V_221 -> V_89 == V_2 ) &&
V_221 -> V_99 ) {
F_77 ( V_5 -> V_36 , L_32 ) ;
V_222 = 1 ;
}
V_221 -> V_178 = V_4 -> V_178 ;
V_221 -> V_179 = V_4 -> V_179 ;
V_221 -> V_175 = V_4 -> V_175 ;
V_221 -> V_8 = V_4 -> V_8 ;
V_221 -> V_59 = V_4 -> V_59 ;
V_221 -> V_176 = V_4 -> V_176 ;
V_221 -> V_181 = V_4 -> V_181 ;
V_221 -> V_182 = V_4 -> V_182 ;
V_221 -> V_89 = V_4 -> V_89 ;
V_221 -> V_99 = V_4 -> V_99 ;
V_221 -> V_95 = V_4 -> V_95 ;
for ( V_220 = V_4 -> V_89 ; V_220 ;
V_220 = V_220 -> V_90 ) {
V_220 -> V_4 = V_221 ;
V_220 -> V_173 = V_221 -> V_174 ;
}
F_57 ( V_4 ) ;
if ( V_222 )
F_60 ( F_3 ( V_2 ) ,
& V_224 ) ;
} else {
F_76 ( V_5 -> V_36 , L_33 ) ;
}
} else {
V_222 = V_4 -> V_99 ;
F_57 ( V_4 ) ;
if ( V_222 ) {
F_77 ( V_5 -> V_36 , L_32 ) ;
V_169 = F_3 ( V_2 ) ;
if ( V_169 )
F_60 ( V_169 ,
& V_224 ) ;
}
}
}
F_21 ( V_5 -> V_36 , L_34 , V_2 -> V_37 ) ;
F_59 (bond, slave_iter, iter) {
V_169 = & ( F_6 ( V_223 ) -> V_4 ) ;
V_219 = NULL ;
for ( V_220 = V_169 -> V_89 ; V_220 ;
V_219 = V_220 ,
V_220 = V_220 -> V_90 ) {
if ( V_220 == V_2 ) {
if ( V_219 )
V_219 -> V_90 = V_220 -> V_90 ;
else
V_169 -> V_89 = V_220 -> V_90 ;
V_169 -> V_95 -- ;
if ( V_169 -> V_95 == 0 ) {
V_222 = V_169 -> V_99 ;
F_57 ( V_169 ) ;
if ( V_222 ) {
F_77 ( V_5 -> V_36 , L_32 ) ;
F_60 ( F_3 ( V_2 ) ,
& V_224 ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
V_226:
F_78 ( & V_5 -> V_225 ) ;
}
void F_79 ( struct V_227 * V_228 )
{
struct V_1 * V_5 = F_80 ( V_228 , struct V_1 ,
V_229 . V_228 ) ;
struct V_4 * V_4 ;
struct V_97 * V_98 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_230 = V_10 ;
bool V_122 = false ;
F_75 ( & V_5 -> V_225 ) ;
F_4 () ;
if ( ! F_81 ( V_5 ) )
goto V_231;
if ( F_19 ( V_5 ) . V_16 &&
! ( -- F_19 ( V_5 ) . V_16 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) -> V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_58 ( L_35 ,
V_5 -> V_36 -> V_81 ) ;
goto V_231;
}
V_4 = F_3 ( V_2 ) ;
F_60 ( V_4 , & V_122 ) ;
}
F_65 ( V_5 ) ;
}
F_37 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_58 ( L_36 ,
V_5 -> V_36 -> V_81 ) ;
goto V_231;
}
F_51 ( NULL , V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 , & V_122 ) ;
F_48 ( V_2 , & V_122 ) ;
F_54 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_67 & V_125 )
V_2 -> V_67 &= ~ V_125 ;
}
V_231:
F_37 (bond, slave, iter) {
if ( V_3 -> V_232 ) {
V_230 = V_233 ;
break;
}
}
F_7 () ;
F_78 ( & V_5 -> V_225 ) ;
if ( V_122 )
F_82 ( V_5 , 0 ) ;
if ( V_230 && F_83 () ) {
F_84 ( V_5 ) ;
F_85 () ;
}
F_86 ( V_5 -> V_234 , & V_5 -> V_229 , V_235 ) ;
}
static int F_87 ( struct V_54 * V_54 , struct V_3 * V_3 ,
T_2 V_103 )
{
struct V_2 * V_2 ;
int V_236 = V_237 ;
if ( V_103 >= sizeof( struct V_54 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_58 ( L_37 ,
V_3 -> V_36 -> V_81 , V_3 -> V_5 -> V_36 -> V_81 ) ;
return V_236 ;
}
switch ( V_54 -> V_192 ) {
case V_238 :
V_236 = V_239 ;
F_21 ( V_3 -> V_5 -> V_36 ,
L_38 ,
V_2 -> V_37 ,
V_3 -> V_36 -> V_81 ) ;
F_88 ( & V_3 -> V_5 -> V_225 ) ;
F_51 ( V_54 , V_2 ) ;
F_89 ( & V_3 -> V_5 -> V_225 ) ;
break;
case V_240 :
V_236 = V_239 ;
switch ( ( (struct V_118 * ) V_54 ) -> V_206 ) {
case V_241 :
F_21 ( V_3 -> V_5 -> V_36 , L_39 ,
V_2 -> V_37 ) ;
F_68 ( (struct V_118 * ) V_54 , V_2 ) ;
break;
case V_207 :
F_21 ( V_3 -> V_5 -> V_36 , L_40 ,
V_2 -> V_37 ) ;
F_69 ( (struct V_118 * ) V_54 , V_2 ) ;
break;
default:
F_21 ( V_3 -> V_5 -> V_36 , L_41 ,
V_2 -> V_37 ) ;
}
}
}
return V_236 ;
}
static void F_73 ( struct V_2 * V_2 , bool V_242 )
{
T_3 V_39 = 0 ;
T_2 V_243 = 0 , V_17 = 0 ;
T_2 V_244 = V_2 -> V_62 ;
V_2 -> V_180 &= ~ ( V_245 | V_146 ) ;
if ( ! V_242 ) {
V_17 = F_20 ( V_2 ) ;
V_243 = ( V_244 & V_245 ) >> 1 ;
V_39 = F_22 ( V_2 ) ;
V_2 -> V_180 |= ( V_17 << 1 ) | V_39 ;
}
V_2 -> V_62 = V_2 -> V_180 ;
if ( V_244 != V_2 -> V_62 ) {
if ( V_39 )
V_2 -> V_67 |= V_144 ;
else
V_2 -> V_67 &= ~ V_144 ;
if ( ! V_242 ) {
if ( ! V_17 ) {
F_52 ( V_2 -> V_3 -> V_36 ,
L_42 ,
V_2 -> V_3 -> V_36 -> V_81 ) ;
} else if ( V_39 && V_243 != V_17 ) {
V_2 -> V_67 |= V_125 ;
}
}
}
}
void F_90 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_76 ( V_3 -> V_5 -> V_36 ,
L_43 ,
V_3 -> V_36 -> V_81 ) ;
return;
}
F_75 ( & V_3 -> V_5 -> V_225 ) ;
F_73 ( V_2 , false ) ;
F_21 ( V_3 -> V_5 -> V_36 , L_44 ,
V_2 -> V_37 , V_3 -> V_36 -> V_81 ) ;
F_78 ( & V_3 -> V_5 -> V_225 ) ;
}
void F_91 ( struct V_3 * V_3 , char V_11 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_76 ( V_3 -> V_5 -> V_36 , L_45 ,
V_3 -> V_36 -> V_81 ) ;
return;
}
F_75 ( & V_3 -> V_5 -> V_225 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_137 = true ;
F_73 ( V_2 , false ) ;
} else {
V_2 -> V_137 = false ;
F_73 ( V_2 , true ) ;
}
F_21 ( V_3 -> V_5 -> V_36 , L_46 ,
V_2 -> V_37 ,
V_11 == V_12 ? L_47 : L_48 ) ;
F_78 ( & V_3 -> V_5 -> V_225 ) ;
F_92 ( V_3 -> V_5 , NULL ) ;
}
int F_65 ( struct V_1 * V_5 )
{
struct V_4 * V_187 ;
struct V_3 * V_6 ;
int V_236 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_236 = 0 ;
goto V_226;
}
V_187 = F_36 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_187 ) {
if ( V_187 -> V_95 < V_5 -> V_14 . V_246 ) {
if ( F_64 ( V_5 -> V_36 ) ) {
F_93 ( V_5 -> V_36 ) ;
goto V_226;
}
} else if ( ! F_64 ( V_5 -> V_36 ) ) {
F_94 ( V_5 -> V_36 ) ;
goto V_226;
}
} else if ( F_64 ( V_5 -> V_36 ) ) {
F_93 ( V_5 -> V_36 ) ;
}
V_226:
F_7 () ;
return V_236 ;
}
int F_95 ( struct V_1 * V_5 ,
struct V_247 * V_247 )
{
struct V_4 * V_4 = NULL ;
struct V_97 * V_98 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_37 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_99 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( ! V_4 )
return - 1 ;
V_247 -> V_248 = V_4 -> V_174 ;
V_247 -> V_249 = V_4 -> V_95 ;
V_247 -> V_77 = V_4 -> V_175 ;
V_247 -> V_61 = V_4 -> V_176 ;
F_44 ( V_247 -> V_8 ,
V_4 -> V_8 . V_9 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_5 , struct V_247 * V_247 )
{
int V_236 ;
F_4 () ;
V_236 = F_95 ( V_5 , V_247 ) ;
F_7 () ;
return V_236 ;
}
int F_97 ( const struct V_100 * V_101 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
struct V_54 * V_54 , V_250 ;
if ( V_101 -> V_108 != V_109 )
return V_237 ;
if ( ! F_26 ( F_98 ( V_101 ) -> V_113 , V_114 ) )
return V_237 ;
V_54 = F_99 ( V_101 , 0 , sizeof( V_250 ) , & V_250 ) ;
if ( ! V_54 )
return V_237 ;
return F_87 ( V_54 , V_3 , V_101 -> V_251 ) ;
}
void F_100 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_97 * V_98 ;
struct V_3 * V_3 ;
int V_190 ;
V_190 = V_5 -> V_14 . V_190 ;
F_75 ( & V_5 -> V_225 ) ;
F_59 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_190 )
V_2 -> V_65 |= V_87 ;
else
V_2 -> V_65 &= ~ V_87 ;
}
F_78 ( & V_5 -> V_225 ) ;
}
