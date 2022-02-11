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
default:
V_17 = 0 ;
break;
}
}
F_21 ( V_3 -> V_5 -> V_34 , L_1 ,
V_2 -> V_35 , V_17 ) ;
return V_17 ;
}
static T_3 F_22 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_36 = 0x0 ;
if ( V_3 -> V_11 == V_12 ) {
switch ( V_3 -> V_37 ) {
case V_38 :
V_36 = 0x1 ;
F_21 ( V_3 -> V_5 -> V_34 , L_2 ,
V_2 -> V_35 ) ;
break;
case V_39 :
default:
V_36 = 0x0 ;
F_21 ( V_3 -> V_5 -> V_34 , L_3 ,
V_2 -> V_35 ) ;
break;
}
}
return V_36 ;
}
static T_2 F_23 ( T_2 V_40 , T_2 V_41 )
{
T_2 V_36 = 0 ;
switch ( V_40 ) {
case V_42 :
if ( V_41 )
V_36 = ( V_43 * V_44 ) ;
else
V_36 = ( V_45 * V_44 ) ;
break;
case V_46 :
V_36 = ( V_47 * V_44 ) ;
break;
case V_48 :
V_36 = ( V_41 * V_44 ) ;
break;
case V_49 :
V_36 = ( V_47 * V_44 ) ;
break;
case V_50 :
V_36 = ( V_51 * V_44 ) ;
break;
}
return V_36 ;
}
static void F_24 ( struct V_52 * V_52 , struct V_2 * V_2 )
{
if ( ( ( F_25 ( V_52 -> V_53 ) == V_2 -> V_35 ) &&
( F_25 ( V_52 -> V_54 ) == V_2 -> V_55 ) &&
F_26 ( & ( V_52 -> V_8 ) , & ( V_2 -> V_56 ) ) &&
( F_25 ( V_52 -> V_57 ) == V_2 -> V_58 ) &&
( F_25 ( V_52 -> V_59 ) == V_2 -> V_60 ) &&
( ( V_52 -> V_61 & V_62 ) == ( V_2 -> V_63 & V_62 ) ) ) ||
( ( V_52 -> V_64 & V_62 ) == 0 )
) {
V_2 -> V_65 |= V_66 ;
} else {
V_2 -> V_65 &= ~ V_66 ;
}
}
static void F_27 ( struct V_52 * V_52 , struct V_2 * V_2 )
{
if ( V_52 && V_2 ) {
struct V_67 * V_68 = & V_2 -> V_69 ;
F_24 ( V_52 , V_2 ) ;
V_68 -> V_70 = F_25 ( V_52 -> V_71 ) ;
V_68 -> V_72 = F_25 ( V_52 -> V_55 ) ;
V_68 -> system = V_52 -> V_56 ;
V_68 -> V_73 = F_25 ( V_52 -> V_58 ) ;
V_68 -> V_74 = F_25 ( V_52 -> V_75 ) ;
V_68 -> V_76 = V_52 -> V_64 ;
V_2 -> V_63 &= ~ V_77 ;
if ( ( V_2 -> V_65 & V_66 ) &&
( V_52 -> V_64 & V_78 ) ) {
V_68 -> V_76 |= V_78 ;
F_28 ( L_4 , V_2 -> V_3 -> V_34 -> V_79 ) ;
} else {
V_68 -> V_76 &= ~ V_78 ;
F_28 ( L_5 , V_2 -> V_3 -> V_34 -> V_79 ) ;
}
}
}
static void F_29 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_69 , & V_2 -> V_80 ,
sizeof( struct V_67 ) ) ;
V_2 -> V_63 |= V_77 ;
}
}
static void F_30 ( struct V_52 * V_52 , struct V_2 * V_2 )
{
if ( V_52 && V_2 ) {
const struct V_67 * V_68 = & V_2 -> V_69 ;
if ( F_25 ( V_52 -> V_71 ) != V_68 -> V_70 ||
F_25 ( V_52 -> V_55 ) != V_68 -> V_72 ||
! F_26 ( & V_52 -> V_56 , & V_68 -> system ) ||
F_25 ( V_52 -> V_58 ) != V_68 -> V_73 ||
F_25 ( V_52 -> V_75 ) != V_68 -> V_74 ||
( V_52 -> V_64 & V_62 ) != ( V_68 -> V_76 & V_62 ) ) {
V_2 -> V_65 &= ~ V_81 ;
}
}
}
static void F_31 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_67 * V_82 = & V_2 -> V_80 ;
const struct V_67 * V_83 = & V_2 -> V_69 ;
if ( V_82 -> V_70 != V_83 -> V_70 ||
V_82 -> V_72 != V_83 -> V_72 ||
! F_26 ( & V_82 -> system , & V_83 -> system ) ||
V_82 -> V_73 != V_83 -> V_73 ||
V_82 -> V_74 != V_83 -> V_74 ||
( V_82 -> V_76 & V_62 )
!= ( V_83 -> V_76 & V_62 ) ) {
V_2 -> V_65 &= ~ V_81 ;
}
}
}
static void F_32 ( struct V_52 * V_52 , struct V_2 * V_2 )
{
if ( V_52 && V_2 ) {
if ( ( F_25 ( V_52 -> V_53 ) != V_2 -> V_35 ) ||
( F_25 ( V_52 -> V_54 ) != V_2 -> V_55 ) ||
! F_26 ( & ( V_52 -> V_8 ) , & ( V_2 -> V_56 ) ) ||
( F_25 ( V_52 -> V_57 ) != V_2 -> V_58 ) ||
( F_25 ( V_52 -> V_59 ) != V_2 -> V_60 ) ||
( ( V_52 -> V_61 & V_84 ) != ( V_2 -> V_63 & V_84 ) ) ||
( ( V_52 -> V_61 & V_85 ) != ( V_2 -> V_63 & V_85 ) ) ||
( ( V_52 -> V_61 & V_78 ) != ( V_2 -> V_63 & V_78 ) ) ||
( ( V_52 -> V_61 & V_62 ) != ( V_2 -> V_63 & V_62 ) )
) {
V_2 -> V_86 = true ;
}
}
}
static int F_33 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_36 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_87 ;
V_2 ;
V_2 = V_2 -> V_88 ) {
if ( ! ( V_2 -> V_65 & V_89 ) ) {
V_36 = 0 ;
break;
}
}
}
return V_36 ;
}
static void F_34 ( struct V_4 * V_4 , int V_90 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_87 ; V_2 ;
V_2 = V_2 -> V_88 ) {
if ( V_90 )
V_2 -> V_65 |= V_91 ;
else
V_2 -> V_65 &= ~ V_91 ;
}
}
static T_1 F_35 ( struct V_4 * V_4 )
{
T_1 V_92 = 0 ;
if ( V_4 -> V_93 ) {
switch ( F_20 ( V_4 -> V_87 ) ) {
case V_94 :
V_92 = V_4 -> V_93 ;
break;
case V_19 :
V_92 = V_4 -> V_93 * 10 ;
break;
case V_21 :
V_92 = V_4 -> V_93 * 100 ;
break;
case V_23 :
V_92 = V_4 -> V_93 * 1000 ;
break;
case V_25 :
V_92 = V_4 -> V_93 * 2500 ;
break;
case V_27 :
V_92 = V_4 -> V_93 * 10000 ;
break;
case V_29 :
V_92 = V_4 -> V_93 * 20000 ;
break;
case V_31 :
V_92 = V_4 -> V_93 * 40000 ;
break;
case V_33 :
V_92 = V_4 -> V_93 * 56000 ;
break;
default:
V_92 = 0 ;
}
}
return V_92 ;
}
static struct V_4 * F_36 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_95 * V_96 ;
struct V_3 * V_3 ;
F_37 (bond, slave, iter)
if ( F_6 ( V_3 ) -> V_4 . V_97 )
return & ( F_6 ( V_3 ) -> V_4 ) ;
return NULL ;
}
static inline void F_38 ( struct V_2 * V_2 )
{
struct V_52 * V_52 = & V_2 -> V_52 ;
const struct V_67 * V_68 = & V_2 -> V_69 ;
V_52 -> V_58 = F_39 ( V_2 -> V_58 ) ;
V_52 -> V_56 = V_2 -> V_56 ;
V_52 -> V_75 = F_39 ( V_2 -> V_60 ) ;
V_52 -> V_55 = F_39 ( V_2 -> V_55 ) ;
V_52 -> V_71 = F_39 ( V_2 -> V_35 ) ;
V_52 -> V_64 = V_2 -> V_63 ;
F_28 ( L_6 ,
V_2 -> V_3 -> V_34 -> V_79 , V_2 -> V_63 ) ;
V_52 -> V_57 = F_39 ( V_68 -> V_73 ) ;
V_52 -> V_8 = V_68 -> system ;
V_52 -> V_59 = F_39 ( V_68 -> V_74 ) ;
V_52 -> V_54 = F_39 ( V_68 -> V_72 ) ;
V_52 -> V_53 = F_39 ( V_68 -> V_70 ) ;
V_52 -> V_61 = V_68 -> V_76 ;
}
static int F_40 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_98 * V_99 ;
struct V_100 * V_100 ;
int V_101 = sizeof( struct V_100 ) ;
V_99 = F_41 ( V_101 ) ;
if ( ! V_99 )
return - V_102 ;
V_99 -> V_34 = V_3 -> V_34 ;
F_42 ( V_99 ) ;
V_99 -> V_103 = V_99 -> V_104 + V_105 ;
V_99 -> V_106 = V_107 ;
V_99 -> V_108 = V_109 ;
V_100 = (struct V_100 * ) F_43 ( V_99 , V_101 ) ;
F_44 ( V_100 -> V_110 . V_111 , V_112 ) ;
F_44 ( V_100 -> V_110 . V_113 , V_3 -> V_114 ) ;
V_100 -> V_110 . V_115 = V_107 ;
V_100 -> V_52 = V_2 -> V_52 ;
F_45 ( V_99 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_2 , struct V_116 * V_117 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_98 * V_99 ;
struct V_118 * V_119 ;
int V_101 = sizeof( struct V_118 ) ;
V_99 = F_41 ( V_101 + 16 ) ;
if ( ! V_99 )
return - V_102 ;
F_47 ( V_99 , 16 ) ;
V_99 -> V_34 = V_3 -> V_34 ;
F_42 ( V_99 ) ;
V_99 -> V_103 = V_99 -> V_104 + V_105 ;
V_99 -> V_106 = V_107 ;
V_119 = (struct V_118 * ) F_43 ( V_99 , V_101 ) ;
F_44 ( V_119 -> V_110 . V_111 , V_112 ) ;
F_44 ( V_119 -> V_110 . V_113 , V_3 -> V_114 ) ;
V_119 -> V_110 . V_115 = V_107 ;
V_119 -> V_117 = * V_117 ;
F_45 ( V_99 ) ;
return 0 ;
}
static void F_48 ( struct V_2 * V_2 , bool * V_120 )
{
T_4 V_121 ;
V_121 = V_2 -> V_122 ;
if ( V_2 -> V_65 & V_123 ) {
V_2 -> V_122 = V_124 ;
} else {
switch ( V_2 -> V_122 ) {
case V_124 :
if ( ( V_2 -> V_65 & V_81 )
|| ( V_2 -> V_65 & V_125 ) )
V_2 -> V_122 = V_126 ;
break;
case V_126 :
if ( ! ( V_2 -> V_65 & V_81 ) ) {
V_2 -> V_65 &= ~ V_89 ;
F_34 ( V_2 -> V_4 , F_33 ( V_2 -> V_4 ) ) ;
V_2 -> V_122 = V_124 ;
break;
}
if ( V_2 -> V_127
&& ! ( -- V_2 -> V_127 ) )
V_2 -> V_65 |= V_89 ;
F_34 ( V_2 -> V_4 , F_33 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_65 & V_91 )
&& ! V_2 -> V_127 )
V_2 -> V_122 = V_128 ;
break;
case V_128 :
if ( ( V_2 -> V_65 & V_81 ) &&
( V_2 -> V_69 . V_76 & V_78 ) &&
! F_18 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_97 )
V_2 -> V_122 =
V_129 ;
} else if ( ! ( V_2 -> V_65 & V_81 ) ||
( V_2 -> V_65 & V_125 ) ) {
V_2 -> V_65 &= ~ V_89 ;
F_34 ( V_2 -> V_4 , F_33 ( V_2 -> V_4 ) ) ;
V_2 -> V_122 = V_124 ;
} else if ( V_2 -> V_4 -> V_97 ) {
V_2 -> V_63 |=
V_78 ;
}
break;
case V_129 :
if ( ! ( V_2 -> V_65 & V_81 ) ||
( V_2 -> V_65 & V_125 ) ||
! ( V_2 -> V_69 . V_76 & V_78 ) ||
! ( V_2 -> V_63 & V_78 ) ) {
V_2 -> V_122 = V_128 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_97 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_122 != V_121 ) {
F_28 ( L_7 ,
V_2 -> V_35 ,
V_2 -> V_3 -> V_34 -> V_79 ,
V_121 ,
V_2 -> V_122 ) ;
switch ( V_2 -> V_122 ) {
case V_124 :
V_2 -> V_63 &= ~ V_78 ;
F_49 ( V_2 ,
V_120 ) ;
V_2 -> V_63 &= ~ V_130 ;
V_2 -> V_63 &= ~ V_131 ;
V_2 -> V_86 = true ;
break;
case V_126 :
V_2 -> V_127 = F_23 ( V_50 , 0 ) ;
break;
case V_128 :
if ( V_2 -> V_4 -> V_97 )
V_2 -> V_63 |=
V_78 ;
else
V_2 -> V_63 &=
~ V_78 ;
V_2 -> V_63 &= ~ V_130 ;
V_2 -> V_63 &= ~ V_131 ;
F_49 ( V_2 ,
V_120 ) ;
V_2 -> V_86 = true ;
break;
case V_129 :
V_2 -> V_63 |= V_130 ;
V_2 -> V_63 |= V_131 ;
V_2 -> V_63 |= V_78 ;
F_50 ( V_2 ,
V_120 ) ;
V_2 -> V_86 = true ;
break;
default:
break;
}
}
}
static void F_51 ( struct V_52 * V_52 , struct V_2 * V_2 )
{
T_5 V_121 ;
V_121 = V_2 -> V_132 ;
if ( V_2 -> V_65 & V_123 ) {
V_2 -> V_132 = V_133 ;
V_2 -> V_65 |= V_134 ;
} else if ( ! ( V_2 -> V_65 & V_123 )
&& ! V_2 -> V_135 && ! ( V_2 -> V_65 & V_136 ) )
V_2 -> V_132 = V_137 ;
else if ( V_52 && ( ( V_2 -> V_132 == V_138 ) ||
( V_2 -> V_132 == V_139 ) ||
( V_2 -> V_132 == V_140 ) ) ) {
if ( V_2 -> V_132 != V_140 )
V_2 -> V_65 |= V_134 ;
V_2 -> V_141 = 0 ;
V_2 -> V_132 = V_140 ;
} else {
if ( V_2 -> V_141 &&
! ( -- V_2 -> V_141 ) ) {
switch ( V_2 -> V_132 ) {
case V_138 :
V_2 -> V_132 = V_139 ;
break;
case V_140 :
V_2 -> V_132 = V_138 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_132 ) {
case V_137 :
if ( V_2 -> V_65 & V_136 )
V_2 -> V_132 = V_133 ;
else if ( V_2 -> V_135
&& ( V_2 -> V_65
& V_142 ) )
V_2 -> V_132 = V_138 ;
else if ( V_2 -> V_135
&& ( ( V_2 -> V_65
& V_142 ) == 0 ) )
V_2 -> V_132 = V_143 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_132 != V_121 ) || ( V_52 ) ) {
F_28 ( L_8 ,
V_2 -> V_35 ,
V_2 -> V_3 -> V_34 -> V_79 ,
V_121 ,
V_2 -> V_132 ) ;
switch ( V_2 -> V_132 ) {
case V_133 :
if ( ! ( V_2 -> V_60 & V_144 ) )
V_2 -> V_65 &= ~ V_142 ;
else
V_2 -> V_65 |= V_142 ;
V_2 -> V_65 &= ~ V_81 ;
F_29 ( V_2 ) ;
V_2 -> V_63 &= ~ V_145 ;
V_2 -> V_65 &= ~ V_136 ;
V_2 -> V_132 = V_137 ;
case V_137 :
V_2 -> V_65 &= ~ V_66 ;
break;
case V_143 :
V_2 -> V_65 &= ~ V_81 ;
F_29 ( V_2 ) ;
V_2 -> V_69 . V_76 &= ~ V_62 ;
V_2 -> V_65 |= V_66 ;
V_2 -> V_63 &= ~ V_145 ;
break;
case V_138 :
V_2 -> V_69 . V_76 &= ~ V_78 ;
V_2 -> V_65 &= ~ V_66 ;
V_2 -> V_69 . V_76 |= V_85 ;
V_2 -> V_69 . V_76 |= V_84 ;
V_2 -> V_141 = F_23 ( V_42 , ( T_2 ) ( V_146 ) ) ;
V_2 -> V_63 |= V_145 ;
V_2 -> V_65 |= V_134 ;
break;
case V_139 :
F_31 ( V_2 ) ;
F_29 ( V_2 ) ;
V_2 -> V_65 |= V_66 ;
V_2 -> V_63 &= ~ V_145 ;
break;
case V_140 :
if ( F_26 ( & ( V_52 -> V_56 ) ,
& ( V_2 -> V_56 ) ) ) {
F_52 ( V_2 -> V_3 -> V_5 -> V_34 , L_9
L_10 ,
V_2 -> V_3 -> V_34 -> V_79 ) ;
return;
}
F_30 ( V_52 , V_2 ) ;
F_32 ( V_52 , V_2 ) ;
F_27 ( V_52 , V_2 ) ;
V_2 -> V_141 = F_23 ( V_42 , ( T_2 ) ( V_2 -> V_63 & V_85 ) ) ;
V_2 -> V_63 &= ~ V_145 ;
break;
default:
break;
}
}
}
static void F_53 ( struct V_2 * V_2 )
{
if ( V_2 -> V_65 & V_134 ) {
V_2 -> V_65 &= ~ V_134 ;
V_2 -> V_147 = V_148 ;
V_2 -> V_149 = V_148 ;
V_2 -> V_150 =
F_23 ( V_46 , 0 ) ;
V_2 -> V_151 =
F_23 ( V_49 , 0 ) ;
return;
}
if ( V_2 -> V_150 &&
! ( -- V_2 -> V_150 ) &&
V_2 -> V_147 == V_148 ) {
if ( V_2 -> V_63 & V_78 ) {
V_2 -> V_147 = V_152 ;
} else {
V_2 -> V_153 ++ ;
V_2 -> V_147 = V_154 ;
}
}
if ( V_2 -> V_151 &&
! ( -- V_2 -> V_151 ) &&
V_2 -> V_149 == V_148 ) {
if ( V_2 -> V_69 . V_76 & V_78 ) {
V_2 -> V_149 = V_152 ;
} else {
V_2 -> V_155 ++ ;
V_2 -> V_149 = V_154 ;
}
}
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_156 && ! ( -- V_2 -> V_156 ) ) {
if ( V_2 -> V_86 && ( V_2 -> V_65 & V_142 ) ) {
F_38 ( V_2 ) ;
if ( F_40 ( V_2 ) >= 0 ) {
F_28 ( L_11 ,
V_2 -> V_35 ) ;
V_2 -> V_86 = false ;
}
}
V_2 -> V_156 = V_44 / V_157 ;
}
}
static void F_55 ( struct V_2 * V_2 )
{
T_6 V_121 ;
V_121 = V_2 -> V_158 ;
if ( ( ( V_2 -> V_65 & V_123 ) || ! ( V_2 -> V_65 & V_142 ) || ! V_2 -> V_135 ) ||
( ! ( V_2 -> V_63 & V_84 ) && ! ( V_2 -> V_69 . V_76 & V_84 ) )
) {
V_2 -> V_158 = V_159 ;
}
else if ( V_2 -> V_160 ) {
if ( ! ( -- V_2 -> V_160 ) ) {
V_2 -> V_158 = V_161 ;
} else {
switch ( V_2 -> V_158 ) {
case V_162 :
if ( ! ( V_2 -> V_69 . V_76
& V_85 ) )
V_2 -> V_158 = V_163 ;
break;
case V_163 :
if ( ( V_2 -> V_69 . V_76 & V_85 ) ) {
V_2 -> V_160 = 0 ;
V_2 -> V_158 = V_161 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_158 ) {
case V_159 :
V_2 -> V_158 = V_162 ;
break;
case V_161 :
if ( ! ( V_2 -> V_69 . V_76 &
V_85 ) )
V_2 -> V_158 = V_163 ;
else
V_2 -> V_158 = V_162 ;
break;
default:
break;
}
}
if ( V_2 -> V_158 != V_121 ) {
F_28 ( L_12 ,
V_2 -> V_35 , V_121 ,
V_2 -> V_158 ) ;
switch ( V_2 -> V_158 ) {
case V_159 :
V_2 -> V_160 = 0 ;
break;
case V_162 :
V_2 -> V_160 = F_23 ( V_48 , ( T_2 ) ( V_164 ) ) - 1 ;
break;
case V_163 :
V_2 -> V_160 = F_23 ( V_48 , ( T_2 ) ( V_165 ) ) - 1 ;
break;
case V_161 :
V_2 -> V_86 = true ;
break;
default:
break;
}
}
}
static void F_56 ( struct V_2 * V_2 , bool * V_120 )
{
struct V_4 * V_4 , * V_166 = NULL , * V_167 ;
struct V_2 * V_168 = NULL , * V_169 ;
struct V_95 * V_96 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_170 = 0 ;
if ( V_2 -> V_65 & V_81 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_167 = V_2 -> V_4 ;
for ( V_169 = V_167 -> V_87 ; V_169 ;
V_168 = V_169 ,
V_169 = V_169 -> V_88 ) {
if ( V_169 == V_2 ) {
V_167 -> V_93 -- ;
if ( ! V_168 ) {
V_167 -> V_87 =
V_2 -> V_88 ;
} else {
V_168 -> V_88 =
V_2 -> V_88 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_88 = NULL ;
V_2 -> V_171 = 0 ;
F_21 ( V_5 -> V_34 , L_13 ,
V_2 -> V_35 ,
V_167 -> V_172 ) ;
if ( ! V_167 -> V_87 )
F_57 ( V_167 ) ;
break;
}
}
if ( ! V_169 ) {
F_58 ( L_14 ,
V_2 -> V_3 -> V_5 -> V_34 -> V_79 ,
V_2 -> V_35 ,
V_2 -> V_3 -> V_34 -> V_79 ,
V_2 -> V_4 -> V_172 ) ;
}
}
F_59 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_87 ) {
if ( ! V_166 )
V_166 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_173 == V_2 -> V_60 ) &&
F_26 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_69 . system ) ) &&
( V_4 -> V_57 == V_2 -> V_69 . V_73 ) &&
( V_4 -> V_174 == V_2 -> V_69 . V_74 )
) &&
( ( ! F_26 ( & ( V_2 -> V_69 . system ) , & ( V_175 ) ) &&
! V_4 -> V_176 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_171 =
V_2 -> V_4 -> V_172 ;
V_2 -> V_88 = V_4 -> V_87 ;
V_2 -> V_4 -> V_93 ++ ;
V_4 -> V_87 = V_2 ;
F_21 ( V_5 -> V_34 , L_15 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_172 ) ;
V_2 -> V_65 |= V_81 ;
V_170 = 1 ;
break;
}
}
if ( ! V_170 ) {
if ( V_166 ) {
V_2 -> V_4 = V_166 ;
V_2 -> V_171 =
V_2 -> V_4 -> V_172 ;
if ( V_2 -> V_60 & V_144 )
V_2 -> V_4 -> V_176 = false ;
else
V_2 -> V_4 -> V_176 = true ;
V_2 -> V_4 -> V_177 =
V_2 -> V_178 ;
V_2 -> V_4 -> V_173 =
V_2 -> V_60 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_69 . system ;
V_2 -> V_4 -> V_57 =
V_2 -> V_69 . V_73 ;
V_2 -> V_4 -> V_174 = V_2 -> V_69 . V_74 ;
V_2 -> V_4 -> V_179 = 1 ;
V_2 -> V_4 -> V_180 = 1 ;
V_2 -> V_4 -> V_87 = V_2 ;
V_2 -> V_4 -> V_93 ++ ;
V_2 -> V_65 |= V_81 ;
F_21 ( V_5 -> V_34 , L_16 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_172 ) ;
} else {
F_52 ( V_5 -> V_34 , L_17 ,
V_2 -> V_35 , V_2 -> V_3 -> V_34 -> V_79 ) ;
}
}
F_34 ( V_2 -> V_4 ,
F_33 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_60 ( V_4 , V_120 ) ;
if ( ! V_2 -> V_4 -> V_97 )
V_2 -> V_63 &= ~ V_78 ;
}
static struct V_4 * F_61 ( struct V_4 * V_181 ,
struct V_4 * V_182 )
{
if ( ! V_181 )
return V_182 ;
if ( ! V_182 -> V_176 && V_181 -> V_176 )
return V_182 ;
if ( V_182 -> V_176 && ! V_181 -> V_176 )
return V_181 ;
if ( F_8 ( V_182 ) && ! F_8 ( V_181 ) )
return V_182 ;
if ( ! F_8 ( V_182 ) && F_8 ( V_181 ) )
return V_181 ;
switch ( F_17 ( V_182 -> V_87 ) ) {
case V_183 :
if ( V_182 -> V_93 > V_181 -> V_93 )
return V_182 ;
if ( V_182 -> V_93 < V_181 -> V_93 )
return V_181 ;
case V_13 :
case V_184 :
if ( F_35 ( V_182 ) > F_35 ( V_181 ) )
return V_182 ;
break;
default:
F_58 ( L_18 ,
V_182 -> V_3 -> V_5 -> V_34 -> V_79 ,
F_17 ( V_182 -> V_87 ) ) ;
break;
}
return V_181 ;
}
static int F_62 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_87 ;
if ( ! V_2 )
return 0 ;
return F_63 ( V_2 -> V_3 -> V_34 ) &&
F_64 ( V_2 -> V_3 -> V_34 ) ;
}
static void F_60 ( struct V_4 * V_7 ,
bool * V_120 )
{
struct V_4 * V_181 , * V_185 , * V_186 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_95 * V_96 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_186 = V_7 ;
V_185 = F_36 ( V_7 ) ;
V_181 = ( V_185 && F_62 ( V_185 ) ) ? V_185 : NULL ;
F_37 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_97 = 0 ;
if ( V_7 -> V_93 && F_62 ( V_7 ) )
V_181 = F_61 ( V_181 , V_7 ) ;
}
if ( V_181 &&
F_17 ( V_181 -> V_87 ) == V_13 ) {
if ( V_185 && V_185 -> V_87 &&
V_185 -> V_87 -> V_135 &&
( F_8 ( V_185 ) ||
( ! F_8 ( V_185 ) &&
! F_8 ( V_181 ) ) ) ) {
if ( ! ( ! V_185 -> V_173 &&
V_181 -> V_173 ) ) {
V_181 = NULL ;
V_185 -> V_97 = 1 ;
}
}
}
if ( V_181 && ( V_181 == V_185 ) ) {
V_181 = NULL ;
V_185 -> V_97 = 1 ;
}
if ( V_181 ) {
F_21 ( V_5 -> V_34 , L_19 ,
V_181 -> V_172 , V_181 -> V_93 ,
V_181 -> V_173 ,
V_181 -> V_174 ,
V_181 -> V_176 , V_181 -> V_97 ) ;
F_21 ( V_5 -> V_34 , L_20 ,
V_181 -> V_87 , V_181 -> V_3 ,
V_181 -> V_3 ? V_181 -> V_3 -> V_34 -> V_79 : L_21 ) ;
F_37 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_21 ( V_5 -> V_34 , L_22 ,
V_7 -> V_172 , V_7 -> V_93 ,
V_7 -> V_173 ,
V_7 -> V_174 ,
V_7 -> V_176 , V_7 -> V_97 ) ;
}
if ( V_181 -> V_176 ) {
F_58 ( L_23 ,
V_181 -> V_3 ?
V_181 -> V_3 -> V_5 -> V_34 -> V_79 : L_21 ) ;
}
V_181 -> V_97 = 1 ;
F_21 ( V_5 -> V_34 , L_24 ,
V_181 -> V_172 ) ;
F_21 ( V_5 -> V_34 , L_22 ,
V_181 -> V_172 , V_181 -> V_93 ,
V_181 -> V_173 ,
V_181 -> V_174 ,
V_181 -> V_176 , V_181 -> V_97 ) ;
if ( V_185 ) {
for ( V_2 = V_185 -> V_87 ; V_2 ;
V_2 = V_2 -> V_88 ) {
F_10 ( V_2 ) ;
}
}
* V_120 = true ;
}
V_185 = F_36 ( V_186 ) ;
if ( V_185 ) {
if ( ! F_8 ( V_185 ) ) {
for ( V_2 = V_185 -> V_87 ; V_2 ;
V_2 = V_2 -> V_88 ) {
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
V_4 -> V_176 = false ;
V_4 -> V_177 = 0 ;
V_4 -> V_173 = 0 ;
V_4 -> V_8 = V_175 ;
V_4 -> V_57 = 0 ;
V_4 -> V_174 = 0 ;
V_4 -> V_179 = 0 ;
V_4 -> V_180 = 0 ;
V_4 -> V_87 = NULL ;
V_4 -> V_97 = 0 ;
V_4 -> V_93 = 0 ;
F_28 ( L_25 ,
V_4 -> V_172 ) ;
}
}
static void F_66 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_57 ( V_4 ) ;
V_4 -> V_187 = V_175 ;
V_4 -> V_172 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_67 ( struct V_2 * V_2 , int V_188 )
{
static const struct V_67 V_189 = {
. V_73 = 0xffff ,
. V_74 = 1 ,
. V_70 = 1 ,
. V_72 = 0xff ,
. V_76 = 1 ,
} ;
static const struct V_52 V_52 = {
. V_190 = 0x01 ,
. V_191 = 0x01 ,
. V_192 = 0x01 ,
. V_193 = 0x14 ,
. V_194 = 0x02 ,
. V_195 = 0x14 ,
. V_196 = 0x03 ,
. V_197 = 0x10 ,
. V_198 = F_39 ( V_199 ) ,
} ;
if ( V_2 ) {
V_2 -> V_55 = 0xff ;
V_2 -> V_171 = 0 ;
V_2 -> V_86 = false ;
V_2 -> V_200 = V_62 |
V_84 ;
V_2 -> V_63 = V_62 |
V_84 ;
if ( V_188 )
V_2 -> V_63 |= V_85 ;
memcpy ( & V_2 -> V_80 , & V_189 , sizeof( V_189 ) ) ;
memcpy ( & V_2 -> V_69 , & V_189 , sizeof( V_189 ) ) ;
V_2 -> V_135 = true ;
V_2 -> V_65 = V_123 | V_142 ;
V_2 -> V_132 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_158 = 0 ;
V_2 -> V_160 = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_127 = 0 ;
V_2 -> V_201 = 0 ;
V_2 -> V_4 = NULL ;
V_2 -> V_88 = NULL ;
V_2 -> V_202 = 0 ;
V_2 -> V_150 = 0 ;
V_2 -> V_147 = 0 ;
V_2 -> V_153 = 0 ;
V_2 -> V_151 = 0 ;
V_2 -> V_149 = 0 ;
V_2 -> V_155 = 0 ;
memcpy ( & V_2 -> V_52 , & V_52 , sizeof( V_52 ) ) ;
}
}
static void F_50 ( struct V_2 * V_2 ,
bool * V_120 )
{
if ( V_2 -> V_4 -> V_97 ) {
F_28 ( L_26 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_172 ) ;
F_12 ( V_2 ) ;
* V_120 = true ;
}
}
static void F_49 ( struct V_2 * V_2 ,
bool * V_120 )
{
if ( V_2 -> V_4 &&
! F_26 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_175 ) ) ) {
F_28 ( L_27 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_172 ) ;
F_10 ( V_2 ) ;
* V_120 = true ;
}
}
static void F_68 ( struct V_116 * V_203 ,
struct V_2 * V_2 )
{
struct V_116 V_117 ;
memcpy ( & V_117 , V_203 , sizeof( struct V_116 ) ) ;
V_117 . V_204 = V_205 ;
if ( F_46 ( V_2 , & V_117 ) >= 0 ) {
F_28 ( L_28 ,
V_2 -> V_35 ) ;
}
}
static void F_69 ( struct V_116 * V_117 ,
struct V_2 * V_2 )
{
}
void F_70 ( struct V_1 * V_5 , int V_206 )
{
F_19 ( V_5 ) . V_16 = V_206 ;
}
void F_71 ( struct V_1 * V_5 , T_2 V_207 )
{
if ( ! F_26 ( & ( F_19 ( V_5 ) . system . V_208 ) ,
V_5 -> V_34 -> V_209 ) ) {
F_19 ( V_5 ) . V_172 = 0 ;
F_19 ( V_5 ) . system . V_210 =
V_5 -> V_14 . V_211 ;
if ( F_9 ( V_5 -> V_14 . V_212 ) )
F_19 ( V_5 ) . system . V_208 =
* ( (struct V_213 * ) V_5 -> V_34 -> V_209 ) ;
else
F_19 ( V_5 ) . system . V_208 =
* ( (struct V_213 * ) V_5 -> V_14 . V_212 ) ;
V_44 = V_207 ;
F_70 ( V_5 ,
V_214 *
V_44 ) ;
}
}
void F_72 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) -> V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_67 ( V_2 , V_5 -> V_14 . V_188 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_35 = F_6 ( V_3 ) -> V_215 ;
V_2 -> V_178 = V_5 -> V_14 . V_216 << 6 ;
F_73 ( V_2 , false ) ;
V_2 -> V_56 = F_19 ( V_5 ) . system . V_208 ;
V_2 -> V_58 =
F_19 ( V_5 ) . system . V_210 ;
V_2 -> V_156 = V_44 / V_157 ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_66 ( V_4 ) ;
V_4 -> V_187 = * ( (struct V_213 * ) V_5 -> V_34 -> V_209 ) ;
V_4 -> V_172 = ++ F_19 ( V_5 ) . V_172 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_97 = 0 ;
V_4 -> V_93 = 0 ;
}
}
void F_74 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_217 , * V_218 ;
struct V_4 * V_4 , * V_219 , * V_167 ;
int V_220 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_221 ;
struct V_95 * V_96 ;
bool V_222 ;
F_75 ( & V_5 -> V_223 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_76 ( V_5 -> V_34 , L_29 ,
V_3 -> V_34 -> V_79 ) ;
goto V_224;
}
F_21 ( V_5 -> V_34 , L_30 ,
V_4 -> V_172 ) ;
V_2 -> V_63 &= ~ V_62 ;
F_38 ( V_2 ) ;
F_40 ( V_2 ) ;
if ( V_4 -> V_87 ) {
if ( ( V_4 -> V_87 != V_2 ) ||
( V_4 -> V_87 -> V_88 ) ) {
F_59 (bond, slave_iter, iter) {
V_219 = & ( F_6 ( V_221 ) -> V_4 ) ;
if ( ! V_219 -> V_87 ||
( ( V_219 -> V_87 == V_2 ) &&
! V_219 -> V_87 -> V_88 ) )
break;
}
if ( ! V_221 )
V_219 = NULL ;
if ( ( V_219 ) && ( ( ! V_219 -> V_87 ) || ( ( V_219 -> V_87 == V_2 ) && ! V_219 -> V_87 -> V_88 ) ) ) {
F_21 ( V_5 -> V_34 , L_31 ,
V_4 -> V_172 ,
V_219 -> V_172 ) ;
if ( ( V_219 -> V_87 == V_2 ) &&
V_219 -> V_97 ) {
F_77 ( V_5 -> V_34 , L_32 ) ;
V_220 = 1 ;
}
V_219 -> V_176 = V_4 -> V_176 ;
V_219 -> V_177 = V_4 -> V_177 ;
V_219 -> V_173 = V_4 -> V_173 ;
V_219 -> V_8 = V_4 -> V_8 ;
V_219 -> V_57 = V_4 -> V_57 ;
V_219 -> V_174 = V_4 -> V_174 ;
V_219 -> V_179 = V_4 -> V_179 ;
V_219 -> V_180 = V_4 -> V_180 ;
V_219 -> V_87 = V_4 -> V_87 ;
V_219 -> V_97 = V_4 -> V_97 ;
V_219 -> V_93 = V_4 -> V_93 ;
for ( V_218 = V_4 -> V_87 ; V_218 ;
V_218 = V_218 -> V_88 ) {
V_218 -> V_4 = V_219 ;
V_218 -> V_171 = V_219 -> V_172 ;
}
F_57 ( V_4 ) ;
if ( V_220 )
F_60 ( F_3 ( V_2 ) ,
& V_222 ) ;
} else {
F_76 ( V_5 -> V_34 , L_33 ) ;
}
} else {
V_220 = V_4 -> V_97 ;
F_57 ( V_4 ) ;
if ( V_220 ) {
F_77 ( V_5 -> V_34 , L_32 ) ;
V_167 = F_3 ( V_2 ) ;
if ( V_167 )
F_60 ( V_167 ,
& V_222 ) ;
}
}
}
F_21 ( V_5 -> V_34 , L_34 , V_2 -> V_35 ) ;
F_59 (bond, slave_iter, iter) {
V_167 = & ( F_6 ( V_221 ) -> V_4 ) ;
V_217 = NULL ;
for ( V_218 = V_167 -> V_87 ; V_218 ;
V_217 = V_218 ,
V_218 = V_218 -> V_88 ) {
if ( V_218 == V_2 ) {
if ( V_217 )
V_217 -> V_88 = V_218 -> V_88 ;
else
V_167 -> V_87 = V_218 -> V_88 ;
V_167 -> V_93 -- ;
if ( V_167 -> V_93 == 0 ) {
V_220 = V_167 -> V_97 ;
F_57 ( V_167 ) ;
if ( V_220 ) {
F_77 ( V_5 -> V_34 , L_32 ) ;
F_60 ( F_3 ( V_2 ) ,
& V_222 ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
V_224:
F_78 ( & V_5 -> V_223 ) ;
}
void F_79 ( struct V_225 * V_226 )
{
struct V_1 * V_5 = F_80 ( V_226 , struct V_1 ,
V_227 . V_226 ) ;
struct V_4 * V_4 ;
struct V_95 * V_96 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_228 = V_10 ;
bool V_120 = false ;
F_75 ( & V_5 -> V_223 ) ;
F_4 () ;
if ( ! F_81 ( V_5 ) )
goto V_229;
if ( F_19 ( V_5 ) . V_16 &&
! ( -- F_19 ( V_5 ) . V_16 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) -> V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_58 ( L_35 ,
V_5 -> V_34 -> V_79 ) ;
goto V_229;
}
V_4 = F_3 ( V_2 ) ;
F_60 ( V_4 , & V_120 ) ;
}
F_65 ( V_5 ) ;
}
F_37 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_58 ( L_36 ,
V_5 -> V_34 -> V_79 ) ;
goto V_229;
}
F_51 ( NULL , V_2 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 , & V_120 ) ;
F_48 ( V_2 , & V_120 ) ;
F_54 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_65 & V_123 )
V_2 -> V_65 &= ~ V_123 ;
}
V_229:
F_37 (bond, slave, iter) {
if ( V_3 -> V_230 ) {
V_228 = V_231 ;
break;
}
}
F_7 () ;
F_78 ( & V_5 -> V_223 ) ;
if ( V_120 )
F_82 ( V_5 , 0 ) ;
if ( V_228 && F_83 () ) {
F_84 ( V_5 ) ;
F_85 () ;
}
F_86 ( V_5 -> V_232 , & V_5 -> V_227 , V_233 ) ;
}
static int F_87 ( struct V_52 * V_52 , struct V_3 * V_3 ,
T_2 V_101 )
{
struct V_2 * V_2 ;
int V_234 = V_235 ;
if ( V_101 >= sizeof( struct V_52 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_58 ( L_37 ,
V_3 -> V_34 -> V_79 , V_3 -> V_5 -> V_34 -> V_79 ) ;
return V_234 ;
}
switch ( V_52 -> V_190 ) {
case V_236 :
V_234 = V_237 ;
F_21 ( V_3 -> V_5 -> V_34 ,
L_38 ,
V_2 -> V_35 ,
V_3 -> V_34 -> V_79 ) ;
F_88 ( & V_3 -> V_5 -> V_223 ) ;
F_51 ( V_52 , V_2 ) ;
F_89 ( & V_3 -> V_5 -> V_223 ) ;
break;
case V_238 :
V_234 = V_237 ;
switch ( ( (struct V_116 * ) V_52 ) -> V_204 ) {
case V_239 :
F_21 ( V_3 -> V_5 -> V_34 , L_39 ,
V_2 -> V_35 ) ;
F_68 ( (struct V_116 * ) V_52 , V_2 ) ;
break;
case V_205 :
F_21 ( V_3 -> V_5 -> V_34 , L_40 ,
V_2 -> V_35 ) ;
F_69 ( (struct V_116 * ) V_52 , V_2 ) ;
break;
default:
F_21 ( V_3 -> V_5 -> V_34 , L_41 ,
V_2 -> V_35 ) ;
}
}
}
return V_234 ;
}
static void F_73 ( struct V_2 * V_2 , bool V_240 )
{
T_3 V_37 = 0 ;
T_2 V_241 = 0 , V_17 = 0 ;
T_2 V_242 = V_2 -> V_60 ;
V_2 -> V_178 &= ~ ( V_243 | V_144 ) ;
if ( ! V_240 ) {
V_17 = F_20 ( V_2 ) ;
V_241 = ( V_242 & V_243 ) >> 1 ;
V_37 = F_22 ( V_2 ) ;
V_2 -> V_178 |= ( V_17 << 1 ) | V_37 ;
}
V_2 -> V_60 = V_2 -> V_178 ;
if ( V_242 != V_2 -> V_60 ) {
if ( V_37 )
V_2 -> V_65 |= V_142 ;
else
V_2 -> V_65 &= ~ V_142 ;
if ( ! V_240 ) {
if ( ! V_17 ) {
F_52 ( V_2 -> V_3 -> V_34 ,
L_42 ,
V_2 -> V_3 -> V_34 -> V_79 ) ;
} else if ( V_37 && V_241 != V_17 ) {
V_2 -> V_65 |= V_123 ;
}
}
}
}
void F_90 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_76 ( V_3 -> V_5 -> V_34 ,
L_43 ,
V_3 -> V_34 -> V_79 ) ;
return;
}
F_75 ( & V_3 -> V_5 -> V_223 ) ;
F_73 ( V_2 , false ) ;
F_21 ( V_3 -> V_5 -> V_34 , L_44 ,
V_2 -> V_35 , V_3 -> V_34 -> V_79 ) ;
F_78 ( & V_3 -> V_5 -> V_223 ) ;
}
void F_91 ( struct V_3 * V_3 , char V_11 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_76 ( V_3 -> V_5 -> V_34 , L_45 ,
V_3 -> V_34 -> V_79 ) ;
return;
}
F_75 ( & V_3 -> V_5 -> V_223 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_135 = true ;
F_73 ( V_2 , false ) ;
} else {
V_2 -> V_135 = false ;
F_73 ( V_2 , true ) ;
}
F_21 ( V_3 -> V_5 -> V_34 , L_46 ,
V_2 -> V_35 ,
V_11 == V_12 ? L_47 : L_48 ) ;
F_78 ( & V_3 -> V_5 -> V_223 ) ;
F_92 ( V_3 -> V_5 , NULL ) ;
}
int F_65 ( struct V_1 * V_5 )
{
struct V_4 * V_185 ;
struct V_3 * V_6 ;
int V_234 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_234 = 0 ;
goto V_224;
}
V_185 = F_36 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_185 ) {
if ( V_185 -> V_93 < V_5 -> V_14 . V_244 ) {
if ( F_64 ( V_5 -> V_34 ) ) {
F_93 ( V_5 -> V_34 ) ;
goto V_224;
}
} else if ( ! F_64 ( V_5 -> V_34 ) ) {
F_94 ( V_5 -> V_34 ) ;
goto V_224;
}
} else if ( F_64 ( V_5 -> V_34 ) ) {
F_93 ( V_5 -> V_34 ) ;
}
V_224:
F_7 () ;
return V_234 ;
}
int F_95 ( struct V_1 * V_5 ,
struct V_245 * V_245 )
{
struct V_4 * V_4 = NULL ;
struct V_95 * V_96 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_37 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_97 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( ! V_4 )
return - 1 ;
V_245 -> V_246 = V_4 -> V_172 ;
V_245 -> V_247 = V_4 -> V_93 ;
V_245 -> V_75 = V_4 -> V_173 ;
V_245 -> V_59 = V_4 -> V_174 ;
F_44 ( V_245 -> V_8 ,
V_4 -> V_8 . V_9 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_5 , struct V_245 * V_245 )
{
int V_234 ;
F_4 () ;
V_234 = F_95 ( V_5 , V_245 ) ;
F_7 () ;
return V_234 ;
}
int F_97 ( const struct V_98 * V_99 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
struct V_52 * V_52 , V_248 ;
if ( V_99 -> V_106 != V_107 )
return V_235 ;
if ( ! F_26 ( F_98 ( V_99 ) -> V_111 , V_112 ) )
return V_235 ;
V_52 = F_99 ( V_99 , 0 , sizeof( V_248 ) , & V_248 ) ;
if ( ! V_52 )
return V_235 ;
return F_87 ( V_52 , V_3 , V_99 -> V_249 ) ;
}
void F_100 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_95 * V_96 ;
struct V_3 * V_3 ;
int V_188 ;
V_188 = V_5 -> V_14 . V_188 ;
F_75 ( & V_5 -> V_223 ) ;
F_59 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_188 )
V_2 -> V_63 |= V_85 ;
else
V_2 -> V_63 &= ~ V_85 ;
}
F_78 ( & V_5 -> V_223 ) ;
}
