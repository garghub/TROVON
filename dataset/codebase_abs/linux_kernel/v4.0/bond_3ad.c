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
T_3 V_36 ;
if ( V_3 -> V_11 != V_12 ) {
V_36 = 0x0 ;
} else {
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
if ( V_2 -> V_65 & V_123 )
V_2 -> V_132 = V_133 ;
else if ( ! ( V_2 -> V_65 & V_123 )
&& ! V_2 -> V_134 && ! ( V_2 -> V_65 & V_135 ) )
V_2 -> V_132 = V_136 ;
else if ( V_52 && ( ( V_2 -> V_132 == V_137 ) ||
( V_2 -> V_132 == V_138 ) ||
( V_2 -> V_132 == V_139 ) ) ) {
V_2 -> V_140 = 0 ;
V_2 -> V_132 = V_139 ;
} else {
if ( V_2 -> V_140 &&
! ( -- V_2 -> V_140 ) ) {
switch ( V_2 -> V_132 ) {
case V_137 :
V_2 -> V_132 = V_138 ;
break;
case V_139 :
V_2 -> V_132 = V_137 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_132 ) {
case V_136 :
if ( V_2 -> V_65 & V_135 )
V_2 -> V_132 = V_133 ;
else if ( V_2 -> V_134
&& ( V_2 -> V_65
& V_141 ) )
V_2 -> V_132 = V_137 ;
else if ( V_2 -> V_134
&& ( ( V_2 -> V_65
& V_141 ) == 0 ) )
V_2 -> V_132 = V_142 ;
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
if ( ! ( V_2 -> V_60 & V_143 ) )
V_2 -> V_65 &= ~ V_141 ;
else
V_2 -> V_65 |= V_141 ;
V_2 -> V_65 &= ~ V_81 ;
F_29 ( V_2 ) ;
V_2 -> V_63 &= ~ V_144 ;
V_2 -> V_65 &= ~ V_135 ;
V_2 -> V_132 = V_136 ;
case V_136 :
V_2 -> V_65 &= ~ V_66 ;
break;
case V_142 :
V_2 -> V_65 &= ~ V_81 ;
F_29 ( V_2 ) ;
V_2 -> V_69 . V_76 &= ~ V_62 ;
V_2 -> V_65 |= V_66 ;
V_2 -> V_63 &= ~ V_144 ;
break;
case V_137 :
V_2 -> V_69 . V_76 &= ~ V_78 ;
V_2 -> V_65 &= ~ V_66 ;
V_2 -> V_69 . V_76 |= V_84 ;
V_2 -> V_140 = F_23 ( V_42 , ( T_2 ) ( V_145 ) ) ;
V_2 -> V_63 |= V_144 ;
break;
case V_138 :
F_31 ( V_2 ) ;
F_29 ( V_2 ) ;
V_2 -> V_65 |= V_66 ;
V_2 -> V_63 &= ~ V_144 ;
break;
case V_139 :
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
V_2 -> V_140 = F_23 ( V_42 , ( T_2 ) ( V_2 -> V_63 & V_85 ) ) ;
V_2 -> V_63 &= ~ V_144 ;
break;
default:
break;
}
}
}
static void F_53 ( struct V_2 * V_2 )
{
if ( V_2 -> V_146 && ! ( -- V_2 -> V_146 ) ) {
if ( V_2 -> V_86 && ( V_2 -> V_65 & V_141 ) ) {
F_38 ( V_2 ) ;
if ( F_40 ( V_2 ) >= 0 ) {
F_28 ( L_11 ,
V_2 -> V_35 ) ;
V_2 -> V_86 = false ;
}
}
V_2 -> V_146 = V_44 / V_147 ;
}
}
static void F_54 ( struct V_2 * V_2 )
{
T_6 V_121 ;
V_121 = V_2 -> V_148 ;
if ( ( ( V_2 -> V_65 & V_123 ) || ! ( V_2 -> V_65 & V_141 ) || ! V_2 -> V_134 ) ||
( ! ( V_2 -> V_63 & V_84 ) && ! ( V_2 -> V_69 . V_76 & V_84 ) )
) {
V_2 -> V_148 = V_149 ;
}
else if ( V_2 -> V_150 ) {
if ( ! ( -- V_2 -> V_150 ) ) {
V_2 -> V_148 = V_151 ;
} else {
switch ( V_2 -> V_148 ) {
case V_152 :
if ( ! ( V_2 -> V_69 . V_76
& V_85 ) )
V_2 -> V_148 = V_153 ;
break;
case V_153 :
if ( ( V_2 -> V_69 . V_76 & V_85 ) ) {
V_2 -> V_150 = 0 ;
V_2 -> V_148 = V_151 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_148 ) {
case V_149 :
V_2 -> V_148 = V_152 ;
break;
case V_151 :
if ( ! ( V_2 -> V_69 . V_76 &
V_85 ) )
V_2 -> V_148 = V_153 ;
else
V_2 -> V_148 = V_152 ;
break;
default:
break;
}
}
if ( V_2 -> V_148 != V_121 ) {
F_28 ( L_12 ,
V_2 -> V_35 , V_121 ,
V_2 -> V_148 ) ;
switch ( V_2 -> V_148 ) {
case V_149 :
V_2 -> V_150 = 0 ;
break;
case V_152 :
V_2 -> V_150 = F_23 ( V_48 , ( T_2 ) ( V_154 ) ) - 1 ;
break;
case V_153 :
V_2 -> V_150 = F_23 ( V_48 , ( T_2 ) ( V_155 ) ) - 1 ;
break;
case V_151 :
V_2 -> V_86 = true ;
break;
default:
break;
}
}
}
static void F_55 ( struct V_2 * V_2 , bool * V_120 )
{
struct V_4 * V_4 , * V_156 = NULL , * V_157 ;
struct V_2 * V_158 = NULL , * V_159 ;
struct V_95 * V_96 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_160 = 0 ;
if ( V_2 -> V_65 & V_81 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_157 = V_2 -> V_4 ;
for ( V_159 = V_157 -> V_87 ; V_159 ;
V_158 = V_159 ,
V_159 = V_159 -> V_88 ) {
if ( V_159 == V_2 ) {
V_157 -> V_93 -- ;
if ( ! V_158 ) {
V_157 -> V_87 =
V_2 -> V_88 ;
} else {
V_158 -> V_88 =
V_2 -> V_88 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_88 = NULL ;
V_2 -> V_161 = 0 ;
F_21 ( V_5 -> V_34 , L_13 ,
V_2 -> V_35 ,
V_157 -> V_162 ) ;
if ( ! V_157 -> V_87 )
F_56 ( V_157 ) ;
break;
}
}
if ( ! V_159 ) {
F_57 ( L_14 ,
V_2 -> V_3 -> V_5 -> V_34 -> V_79 ,
V_2 -> V_35 ,
V_2 -> V_3 -> V_34 -> V_79 ,
V_2 -> V_4 -> V_162 ) ;
}
}
F_58 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_87 ) {
if ( ! V_156 )
V_156 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_163 == V_2 -> V_60 ) &&
F_26 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_69 . system ) ) &&
( V_4 -> V_57 == V_2 -> V_69 . V_73 ) &&
( V_4 -> V_164 == V_2 -> V_69 . V_74 )
) &&
( ( ! F_26 ( & ( V_2 -> V_69 . system ) , & ( V_165 ) ) &&
! V_4 -> V_166 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_161 =
V_2 -> V_4 -> V_162 ;
V_2 -> V_88 = V_4 -> V_87 ;
V_2 -> V_4 -> V_93 ++ ;
V_4 -> V_87 = V_2 ;
F_21 ( V_5 -> V_34 , L_15 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_162 ) ;
V_2 -> V_65 |= V_81 ;
V_160 = 1 ;
break;
}
}
if ( ! V_160 ) {
if ( V_156 ) {
V_2 -> V_4 = V_156 ;
V_2 -> V_161 =
V_2 -> V_4 -> V_162 ;
if ( V_2 -> V_60 & V_143 )
V_2 -> V_4 -> V_166 = false ;
else
V_2 -> V_4 -> V_166 = true ;
V_2 -> V_4 -> V_167 = V_2 -> V_168 ;
V_2 -> V_4 -> V_163 = V_2 -> V_60 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_69 . system ;
V_2 -> V_4 -> V_57 =
V_2 -> V_69 . V_73 ;
V_2 -> V_4 -> V_164 = V_2 -> V_69 . V_74 ;
V_2 -> V_4 -> V_169 = 1 ;
V_2 -> V_4 -> V_170 = 1 ;
V_2 -> V_4 -> V_87 = V_2 ;
V_2 -> V_4 -> V_93 ++ ;
V_2 -> V_65 |= V_81 ;
F_21 ( V_5 -> V_34 , L_16 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_162 ) ;
} else {
F_52 ( V_5 -> V_34 , L_17 ,
V_2 -> V_35 , V_2 -> V_3 -> V_34 -> V_79 ) ;
}
}
F_34 ( V_2 -> V_4 ,
F_33 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_59 ( V_4 , V_120 ) ;
if ( ! V_2 -> V_4 -> V_97 )
V_2 -> V_63 &= ~ V_78 ;
}
static struct V_4 * F_60 ( struct V_4 * V_171 ,
struct V_4 * V_172 )
{
if ( ! V_171 )
return V_172 ;
if ( ! V_172 -> V_166 && V_171 -> V_166 )
return V_172 ;
if ( V_172 -> V_166 && ! V_171 -> V_166 )
return V_171 ;
if ( F_8 ( V_172 ) && ! F_8 ( V_171 ) )
return V_172 ;
if ( ! F_8 ( V_172 ) && F_8 ( V_171 ) )
return V_171 ;
switch ( F_17 ( V_172 -> V_87 ) ) {
case V_173 :
if ( V_172 -> V_93 > V_171 -> V_93 )
return V_172 ;
if ( V_172 -> V_93 < V_171 -> V_93 )
return V_171 ;
case V_13 :
case V_174 :
if ( F_35 ( V_172 ) > F_35 ( V_171 ) )
return V_172 ;
break;
default:
F_57 ( L_18 ,
V_172 -> V_3 -> V_5 -> V_34 -> V_79 ,
F_17 ( V_172 -> V_87 ) ) ;
break;
}
return V_171 ;
}
static int F_61 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_87 ;
if ( ! V_2 )
return 0 ;
return F_62 ( V_2 -> V_3 -> V_34 ) &&
F_63 ( V_2 -> V_3 -> V_34 ) ;
}
static void F_59 ( struct V_4 * V_7 ,
bool * V_120 )
{
struct V_4 * V_171 , * V_175 , * V_176 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_95 * V_96 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_176 = V_7 ;
V_175 = F_36 ( V_7 ) ;
V_171 = ( V_175 && F_61 ( V_175 ) ) ? V_175 : NULL ;
F_37 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_97 = 0 ;
if ( V_7 -> V_93 && F_61 ( V_7 ) )
V_171 = F_60 ( V_171 , V_7 ) ;
}
if ( V_171 &&
F_17 ( V_171 -> V_87 ) == V_13 ) {
if ( V_175 && V_175 -> V_87 &&
V_175 -> V_87 -> V_134 &&
( F_8 ( V_175 ) ||
( ! F_8 ( V_175 ) &&
! F_8 ( V_171 ) ) ) ) {
if ( ! ( ! V_175 -> V_163 &&
V_171 -> V_163 ) ) {
V_171 = NULL ;
V_175 -> V_97 = 1 ;
}
}
}
if ( V_171 && ( V_171 == V_175 ) ) {
V_171 = NULL ;
V_175 -> V_97 = 1 ;
}
if ( V_171 ) {
F_21 ( V_5 -> V_34 , L_19 ,
V_171 -> V_162 , V_171 -> V_93 ,
V_171 -> V_163 ,
V_171 -> V_164 ,
V_171 -> V_166 , V_171 -> V_97 ) ;
F_21 ( V_5 -> V_34 , L_20 ,
V_171 -> V_87 , V_171 -> V_3 ,
V_171 -> V_3 ? V_171 -> V_3 -> V_34 -> V_79 : L_21 ) ;
F_37 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_21 ( V_5 -> V_34 , L_22 ,
V_7 -> V_162 , V_7 -> V_93 ,
V_7 -> V_163 ,
V_7 -> V_164 ,
V_7 -> V_166 , V_7 -> V_97 ) ;
}
if ( V_171 -> V_166 ) {
F_57 ( L_23 ,
V_171 -> V_3 ?
V_171 -> V_3 -> V_5 -> V_34 -> V_79 : L_21 ) ;
}
V_171 -> V_97 = 1 ;
F_21 ( V_5 -> V_34 , L_24 ,
V_171 -> V_162 ) ;
F_21 ( V_5 -> V_34 , L_22 ,
V_171 -> V_162 , V_171 -> V_93 ,
V_171 -> V_163 ,
V_171 -> V_164 ,
V_171 -> V_166 , V_171 -> V_97 ) ;
if ( V_175 ) {
for ( V_2 = V_175 -> V_87 ; V_2 ;
V_2 = V_2 -> V_88 ) {
F_10 ( V_2 ) ;
}
}
* V_120 = true ;
}
V_175 = F_36 ( V_176 ) ;
if ( V_175 ) {
if ( ! F_8 ( V_175 ) ) {
for ( V_2 = V_175 -> V_87 ; V_2 ;
V_2 = V_2 -> V_88 ) {
F_12 ( V_2 ) ;
}
}
}
F_7 () ;
F_64 ( V_5 ) ;
}
static void F_56 ( struct V_4 * V_4 )
{
if ( V_4 ) {
V_4 -> V_166 = false ;
V_4 -> V_167 = 0 ;
V_4 -> V_163 = 0 ;
V_4 -> V_8 = V_165 ;
V_4 -> V_57 = 0 ;
V_4 -> V_164 = 0 ;
V_4 -> V_169 = 0 ;
V_4 -> V_170 = 0 ;
V_4 -> V_87 = NULL ;
V_4 -> V_97 = 0 ;
V_4 -> V_93 = 0 ;
F_28 ( L_25 ,
V_4 -> V_162 ) ;
}
}
static void F_65 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_56 ( V_4 ) ;
V_4 -> V_177 = V_165 ;
V_4 -> V_162 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_66 ( struct V_2 * V_2 , int V_178 )
{
static const struct V_67 V_179 = {
. V_73 = 0xffff ,
. V_74 = 1 ,
. V_70 = 1 ,
. V_72 = 0xff ,
. V_76 = 1 ,
} ;
static const struct V_52 V_52 = {
. V_180 = 0x01 ,
. V_181 = 0x01 ,
. V_182 = 0x01 ,
. V_183 = 0x14 ,
. V_184 = 0x02 ,
. V_185 = 0x14 ,
. V_186 = 0x03 ,
. V_187 = 0x10 ,
. V_188 = F_39 ( V_189 ) ,
} ;
if ( V_2 ) {
V_2 -> V_35 = 1 ;
V_2 -> V_55 = 0xff ;
V_2 -> V_56 = V_165 ;
V_2 -> V_58 = 0xffff ;
V_2 -> V_161 = 0 ;
V_2 -> V_86 = false ;
V_2 -> V_168 = 1 ;
V_2 -> V_60 = 1 ;
V_2 -> V_190 = V_62 |
V_84 ;
V_2 -> V_63 = V_62 |
V_84 ;
if ( V_178 )
V_2 -> V_63 |= V_85 ;
memcpy ( & V_2 -> V_80 , & V_179 , sizeof( V_179 ) ) ;
memcpy ( & V_2 -> V_69 , & V_179 , sizeof( V_179 ) ) ;
V_2 -> V_134 = true ;
V_2 -> V_65 = 0x3 ;
V_2 -> V_132 = 0 ;
V_2 -> V_140 = 0 ;
V_2 -> V_148 = 0 ;
V_2 -> V_150 = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_127 = 0 ;
V_2 -> V_191 = 0 ;
V_2 -> V_146 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_88 = NULL ;
V_2 -> V_192 = 0 ;
memcpy ( & V_2 -> V_52 , & V_52 , sizeof( V_52 ) ) ;
}
}
static void F_50 ( struct V_2 * V_2 ,
bool * V_120 )
{
if ( V_2 -> V_4 -> V_97 ) {
F_28 ( L_26 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_162 ) ;
F_12 ( V_2 ) ;
* V_120 = true ;
}
}
static void F_49 ( struct V_2 * V_2 ,
bool * V_120 )
{
if ( V_2 -> V_4 &&
! F_26 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_165 ) ) ) {
F_28 ( L_27 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_162 ) ;
F_10 ( V_2 ) ;
* V_120 = true ;
}
}
static void F_67 ( struct V_116 * V_193 ,
struct V_2 * V_2 )
{
struct V_116 V_117 ;
memcpy ( & V_117 , V_193 , sizeof( struct V_116 ) ) ;
V_117 . V_194 = V_195 ;
if ( F_46 ( V_2 , & V_117 ) >= 0 ) {
F_28 ( L_28 ,
V_2 -> V_35 ) ;
}
}
static void F_68 ( struct V_116 * V_117 ,
struct V_2 * V_2 )
{
V_117 = NULL ;
V_2 = NULL ;
}
void F_69 ( struct V_1 * V_5 , int V_196 )
{
F_19 ( V_5 ) . V_16 = V_196 ;
}
void F_70 ( struct V_1 * V_5 , T_2 V_197 )
{
if ( ! F_26 ( & ( F_19 ( V_5 ) . system . V_198 ) ,
V_5 -> V_34 -> V_199 ) ) {
F_19 ( V_5 ) . V_162 = 0 ;
F_19 ( V_5 ) . system . V_200 = 0xFFFF ;
F_19 ( V_5 ) . system . V_198 = * ( (struct V_201 * ) V_5 -> V_34 -> V_199 ) ;
V_44 = V_197 ;
F_69 ( V_5 ,
V_202 *
V_44 ) ;
}
}
void F_71 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) -> V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_66 ( V_2 , V_5 -> V_14 . V_178 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_35 = F_6 ( V_3 ) -> V_203 ;
V_2 -> V_168 = 0 ;
V_2 -> V_168 |= F_22 ( V_2 ) ;
V_2 -> V_168 |= ( F_20 ( V_2 ) << 1 ) ;
V_2 -> V_60 = V_2 -> V_168 ;
if ( ! ( V_2 -> V_60 & V_143 ) )
V_2 -> V_65 &= ~ V_141 ;
V_2 -> V_56 = F_19 ( V_5 ) . system . V_198 ;
V_2 -> V_146 = V_44 / V_147 ;
V_2 -> V_4 = NULL ;
V_2 -> V_88 = NULL ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_65 ( V_4 ) ;
V_4 -> V_177 = * ( (struct V_201 * ) V_5 -> V_34 -> V_199 ) ;
V_4 -> V_162 = ++ F_19 ( V_5 ) . V_162 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_97 = 0 ;
V_4 -> V_93 = 0 ;
}
}
void F_72 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_204 , * V_205 ;
struct V_4 * V_4 , * V_206 , * V_157 ;
int V_207 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_208 ;
struct V_95 * V_96 ;
bool V_209 ;
F_73 ( & V_5 -> V_210 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_74 ( V_5 -> V_34 , L_29 ,
V_3 -> V_34 -> V_79 ) ;
goto V_211;
}
F_21 ( V_5 -> V_34 , L_30 ,
V_4 -> V_162 ) ;
V_2 -> V_63 &= ~ V_62 ;
F_38 ( V_2 ) ;
F_40 ( V_2 ) ;
if ( V_4 -> V_87 ) {
if ( ( V_4 -> V_87 != V_2 ) ||
( V_4 -> V_87 -> V_88 ) ) {
F_58 (bond, slave_iter, iter) {
V_206 = & ( F_6 ( V_208 ) -> V_4 ) ;
if ( ! V_206 -> V_87 ||
( ( V_206 -> V_87 == V_2 ) &&
! V_206 -> V_87 -> V_88 ) )
break;
}
if ( ! V_208 )
V_206 = NULL ;
if ( ( V_206 ) && ( ( ! V_206 -> V_87 ) || ( ( V_206 -> V_87 == V_2 ) && ! V_206 -> V_87 -> V_88 ) ) ) {
F_21 ( V_5 -> V_34 , L_31 ,
V_4 -> V_162 ,
V_206 -> V_162 ) ;
if ( ( V_206 -> V_87 == V_2 ) &&
V_206 -> V_97 ) {
F_75 ( V_5 -> V_34 , L_32 ) ;
V_207 = 1 ;
}
V_206 -> V_166 = V_4 -> V_166 ;
V_206 -> V_167 = V_4 -> V_167 ;
V_206 -> V_163 = V_4 -> V_163 ;
V_206 -> V_8 = V_4 -> V_8 ;
V_206 -> V_57 = V_4 -> V_57 ;
V_206 -> V_164 = V_4 -> V_164 ;
V_206 -> V_169 = V_4 -> V_169 ;
V_206 -> V_170 = V_4 -> V_170 ;
V_206 -> V_87 = V_4 -> V_87 ;
V_206 -> V_97 = V_4 -> V_97 ;
V_206 -> V_93 = V_4 -> V_93 ;
for ( V_205 = V_4 -> V_87 ; V_205 ;
V_205 = V_205 -> V_88 ) {
V_205 -> V_4 = V_206 ;
V_205 -> V_161 = V_206 -> V_162 ;
}
F_56 ( V_4 ) ;
if ( V_207 )
F_59 ( F_3 ( V_2 ) ,
& V_209 ) ;
} else {
F_74 ( V_5 -> V_34 , L_33 ) ;
}
} else {
V_207 = V_4 -> V_97 ;
F_56 ( V_4 ) ;
if ( V_207 ) {
F_75 ( V_5 -> V_34 , L_32 ) ;
V_157 = F_3 ( V_2 ) ;
if ( V_157 )
F_59 ( V_157 ,
& V_209 ) ;
}
}
}
F_21 ( V_5 -> V_34 , L_34 , V_2 -> V_35 ) ;
F_58 (bond, slave_iter, iter) {
V_157 = & ( F_6 ( V_208 ) -> V_4 ) ;
V_204 = NULL ;
for ( V_205 = V_157 -> V_87 ; V_205 ;
V_204 = V_205 ,
V_205 = V_205 -> V_88 ) {
if ( V_205 == V_2 ) {
if ( V_204 )
V_204 -> V_88 = V_205 -> V_88 ;
else
V_157 -> V_87 = V_205 -> V_88 ;
V_157 -> V_93 -- ;
if ( V_157 -> V_93 == 0 ) {
V_207 = V_157 -> V_97 ;
F_56 ( V_157 ) ;
if ( V_207 ) {
F_75 ( V_5 -> V_34 , L_32 ) ;
F_59 ( F_3 ( V_2 ) ,
& V_209 ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
V_211:
F_76 ( & V_5 -> V_210 ) ;
}
void F_77 ( struct V_212 * V_213 )
{
struct V_1 * V_5 = F_78 ( V_213 , struct V_1 ,
V_214 . V_213 ) ;
struct V_4 * V_4 ;
struct V_95 * V_96 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_215 = V_10 ;
bool V_120 = false ;
F_73 ( & V_5 -> V_210 ) ;
F_4 () ;
if ( ! F_79 ( V_5 ) )
goto V_216;
if ( F_19 ( V_5 ) . V_16 &&
! ( -- F_19 ( V_5 ) . V_16 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) -> V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_57 ( L_35 ,
V_5 -> V_34 -> V_79 ) ;
goto V_216;
}
V_4 = F_3 ( V_2 ) ;
F_59 ( V_4 , & V_120 ) ;
}
F_64 ( V_5 ) ;
}
F_37 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_57 ( L_36 ,
V_5 -> V_34 -> V_79 ) ;
goto V_216;
}
F_51 ( NULL , V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 , & V_120 ) ;
F_48 ( V_2 , & V_120 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_65 & V_123 )
V_2 -> V_65 &= ~ V_123 ;
}
V_216:
F_37 (bond, slave, iter) {
if ( V_3 -> V_217 ) {
V_215 = V_218 ;
break;
}
}
F_7 () ;
F_76 ( & V_5 -> V_210 ) ;
if ( V_120 )
F_80 ( V_5 , 0 ) ;
if ( V_215 && F_81 () ) {
F_82 ( V_5 ) ;
F_83 () ;
}
F_84 ( V_5 -> V_219 , & V_5 -> V_214 , V_220 ) ;
}
static int F_85 ( struct V_52 * V_52 , struct V_3 * V_3 ,
T_2 V_101 )
{
struct V_2 * V_2 ;
int V_221 = V_222 ;
if ( V_101 >= sizeof( struct V_52 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_57 ( L_37 ,
V_3 -> V_34 -> V_79 , V_3 -> V_5 -> V_34 -> V_79 ) ;
return V_221 ;
}
switch ( V_52 -> V_180 ) {
case V_223 :
V_221 = V_224 ;
F_21 ( V_3 -> V_5 -> V_34 ,
L_38 ,
V_2 -> V_35 ,
V_3 -> V_34 -> V_79 ) ;
F_86 ( & V_3 -> V_5 -> V_210 ) ;
F_51 ( V_52 , V_2 ) ;
F_87 ( & V_3 -> V_5 -> V_210 ) ;
break;
case V_225 :
V_221 = V_224 ;
switch ( ( (struct V_116 * ) V_52 ) -> V_194 ) {
case V_226 :
F_21 ( V_3 -> V_5 -> V_34 , L_39 ,
V_2 -> V_35 ) ;
F_67 ( (struct V_116 * ) V_52 , V_2 ) ;
break;
case V_195 :
F_21 ( V_3 -> V_5 -> V_34 , L_40 ,
V_2 -> V_35 ) ;
F_68 ( (struct V_116 * ) V_52 , V_2 ) ;
break;
default:
F_21 ( V_3 -> V_5 -> V_34 , L_41 ,
V_2 -> V_35 ) ;
}
}
}
return V_221 ;
}
void F_88 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_74 ( V_3 -> V_5 -> V_34 , L_42 ,
V_3 -> V_34 -> V_79 ) ;
return;
}
F_73 ( & V_3 -> V_5 -> V_210 ) ;
V_2 -> V_168 &= ~ V_227 ;
V_2 -> V_60 = V_2 -> V_168 |=
( F_20 ( V_2 ) << 1 ) ;
F_21 ( V_3 -> V_5 -> V_34 , L_43 , V_2 -> V_35 ) ;
V_2 -> V_65 |= V_123 ;
F_76 ( & V_3 -> V_5 -> V_210 ) ;
}
void F_89 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_74 ( V_3 -> V_5 -> V_34 , L_44 ,
V_3 -> V_34 -> V_79 ) ;
return;
}
F_73 ( & V_3 -> V_5 -> V_210 ) ;
V_2 -> V_168 &= ~ V_143 ;
V_2 -> V_60 = V_2 -> V_168 |=
F_22 ( V_2 ) ;
F_21 ( V_3 -> V_5 -> V_34 , L_45 ,
V_2 -> V_35 , V_3 -> V_34 -> V_79 ) ;
if ( V_2 -> V_60 & V_143 )
V_2 -> V_65 |= V_141 ;
V_2 -> V_65 |= V_123 ;
F_76 ( & V_3 -> V_5 -> V_210 ) ;
}
void F_90 ( struct V_3 * V_3 , char V_11 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_74 ( V_3 -> V_5 -> V_34 , L_46 ,
V_3 -> V_34 -> V_79 ) ;
return;
}
F_73 ( & V_3 -> V_5 -> V_210 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_134 = true ;
V_2 -> V_168 &= ~ V_143 ;
V_2 -> V_60 = V_2 -> V_168 |=
F_22 ( V_2 ) ;
V_2 -> V_168 &= ~ V_227 ;
V_2 -> V_60 = V_2 -> V_168 |=
( F_20 ( V_2 ) << 1 ) ;
} else {
V_2 -> V_134 = false ;
V_2 -> V_168 &= ~ V_143 ;
V_2 -> V_60 = ( V_2 -> V_168 &=
~ V_227 ) ;
}
F_21 ( V_3 -> V_5 -> V_34 , L_47 ,
V_2 -> V_35 ,
V_11 == V_12 ? L_48 : L_49 ) ;
V_2 -> V_65 |= V_123 ;
F_76 ( & V_3 -> V_5 -> V_210 ) ;
F_91 ( V_3 -> V_5 , NULL ) ;
}
int F_64 ( struct V_1 * V_5 )
{
struct V_4 * V_175 ;
struct V_3 * V_6 ;
int V_221 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_221 = 0 ;
goto V_211;
}
V_175 = F_36 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_175 ) {
if ( V_175 -> V_93 < V_5 -> V_14 . V_228 ) {
if ( F_63 ( V_5 -> V_34 ) ) {
F_92 ( V_5 -> V_34 ) ;
goto V_211;
}
} else if ( ! F_63 ( V_5 -> V_34 ) ) {
F_93 ( V_5 -> V_34 ) ;
goto V_211;
}
} else if ( F_63 ( V_5 -> V_34 ) ) {
F_92 ( V_5 -> V_34 ) ;
}
V_211:
F_7 () ;
return V_221 ;
}
int F_94 ( struct V_1 * V_5 ,
struct V_229 * V_229 )
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
V_229 -> V_230 = V_4 -> V_162 ;
V_229 -> V_231 = V_4 -> V_93 ;
V_229 -> V_75 = V_4 -> V_163 ;
V_229 -> V_59 = V_4 -> V_164 ;
F_44 ( V_229 -> V_8 ,
V_4 -> V_8 . V_9 ) ;
return 0 ;
}
int F_95 ( struct V_1 * V_5 , struct V_229 * V_229 )
{
int V_221 ;
F_4 () ;
V_221 = F_94 ( V_5 , V_229 ) ;
F_7 () ;
return V_221 ;
}
int F_96 ( const struct V_98 * V_99 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
struct V_52 * V_52 , V_232 ;
if ( V_99 -> V_106 != V_107 )
return V_222 ;
V_52 = F_97 ( V_99 , 0 , sizeof( V_232 ) , & V_232 ) ;
if ( ! V_52 )
return V_222 ;
return F_85 ( V_52 , V_3 , V_99 -> V_233 ) ;
}
void F_98 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_95 * V_96 ;
struct V_3 * V_3 ;
int V_178 ;
V_178 = V_5 -> V_14 . V_178 ;
F_73 ( & V_5 -> V_210 ) ;
F_58 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_178 )
V_2 -> V_63 |= V_85 ;
else
V_2 -> V_63 &= ~ V_85 ;
}
F_76 ( & V_5 -> V_210 ) ;
}
