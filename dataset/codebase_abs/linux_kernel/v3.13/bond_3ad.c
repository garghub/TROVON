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
if ( V_5 == NULL )
return NULL ;
V_6 = F_4 ( V_5 ) ;
return V_6 ? & ( F_5 ( V_6 ) . V_4 ) : NULL ;
}
static inline int F_6 ( struct V_4 * V_7 )
{
return ! F_7 ( V_7 -> V_8 . V_9 ) ;
}
static inline void F_8 ( struct V_2 * V_2 )
{
F_9 ( V_2 -> V_3 ) ;
}
static inline void F_10 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
if ( ( V_3 -> V_10 == V_11 ) && F_11 ( V_3 -> V_12 ) )
F_12 ( V_3 ) ;
}
static inline int F_13 ( struct V_2 * V_2 )
{
return F_14 ( V_2 -> V_3 ) ;
}
static inline T_1 F_15 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
if ( V_5 == NULL )
return V_13 ;
return V_5 -> V_14 . V_15 ;
}
static inline int F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
if ( V_5 == NULL )
return 0 ;
return F_17 ( V_5 ) . V_16 ? 1 : 0 ;
}
static inline void F_18 ( struct V_2 * V_2 )
{
F_19 ( & ( F_5 ( V_2 -> V_3 ) . V_17 ) ) ;
}
static inline void F_20 ( struct V_2 * V_2 )
{
F_21 ( & ( F_5 ( V_2 -> V_3 ) . V_17 ) ) ;
}
static T_2 F_22 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_2 V_18 ;
if ( V_3 -> V_10 != V_11 )
V_18 = 0 ;
else {
switch ( V_3 -> V_18 ) {
case V_19 :
V_18 = V_20 ;
break;
case V_21 :
V_18 = V_22 ;
break;
case V_23 :
V_18 = V_24 ;
break;
case V_25 :
V_18 = V_26 ;
break;
default:
V_18 = 0 ;
break;
}
}
F_23 ( L_1 ,
V_2 -> V_27 , V_18 ) ;
return V_18 ;
}
static T_3 F_24 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_28 ;
if ( V_3 -> V_10 != V_11 )
V_28 = 0x0 ;
else {
switch ( V_3 -> V_29 ) {
case V_30 :
V_28 = 0x1 ;
F_23 ( L_2 ,
V_2 -> V_27 ) ;
break;
case V_31 :
default:
V_28 = 0x0 ;
F_23 ( L_3 ,
V_2 -> V_27 ) ;
break;
}
}
return V_28 ;
}
static inline void F_25 ( struct V_3 * V_3 )
{
F_26 ( & ( F_5 ( V_3 ) . V_17 ) ) ;
}
static T_2 F_27 ( T_2 V_32 , T_2 V_33 )
{
T_2 V_28 = 0 ;
switch ( V_32 ) {
case V_34 :
if ( V_33 )
V_28 = ( V_35 * V_36 ) ;
else
V_28 = ( V_37 * V_36 ) ;
break;
case V_38 :
V_28 = ( V_39 * V_36 ) ;
break;
case V_40 :
V_28 = ( V_33 * V_36 ) ;
break;
case V_41 :
V_28 = ( V_39 * V_36 ) ;
break;
case V_42 :
V_28 = ( V_43 * V_36 ) ;
break;
}
return V_28 ;
}
static void F_28 ( struct V_44 * V_44 , struct V_2 * V_2 )
{
if ( ( ( F_29 ( V_44 -> V_45 ) == V_2 -> V_27 ) &&
( F_29 ( V_44 -> V_46 ) == V_2 -> V_47 ) &&
! F_30 ( & ( V_44 -> V_8 ) , & ( V_2 -> V_48 ) ) &&
( F_29 ( V_44 -> V_49 ) == V_2 -> V_50 ) &&
( F_29 ( V_44 -> V_51 ) == V_2 -> V_52 ) &&
( ( V_44 -> V_53 & V_54 ) == ( V_2 -> V_55 & V_54 ) ) ) ||
( ( V_44 -> V_56 & V_54 ) == 0 )
) {
V_2 -> V_57 |= V_58 ;
} else {
V_2 -> V_57 &= ~ V_58 ;
}
}
static void F_31 ( struct V_44 * V_44 , struct V_2 * V_2 )
{
if ( V_44 && V_2 ) {
struct V_59 * V_60 = & V_2 -> V_61 ;
F_28 ( V_44 , V_2 ) ;
V_60 -> V_62 = F_29 ( V_44 -> V_63 ) ;
V_60 -> V_64 = F_29 ( V_44 -> V_47 ) ;
V_60 -> system = V_44 -> V_48 ;
V_60 -> V_65 = F_29 ( V_44 -> V_50 ) ;
V_60 -> V_66 = F_29 ( V_44 -> V_67 ) ;
V_60 -> V_68 = V_44 -> V_56 ;
V_2 -> V_55 &= ~ V_69 ;
if ( ( V_2 -> V_57 & V_58 )
&& ( V_44 -> V_56 & V_70 ) )
V_60 -> V_68 |= V_70 ;
else
V_60 -> V_68 &= ~ V_70 ;
}
}
static void F_32 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_61 , & V_2 -> V_71 ,
sizeof( struct V_59 ) ) ;
V_2 -> V_55 |= V_69 ;
}
}
static void F_33 ( struct V_44 * V_44 , struct V_2 * V_2 )
{
if ( V_44 && V_2 ) {
const struct V_59 * V_60 = & V_2 -> V_61 ;
if ( F_29 ( V_44 -> V_63 ) != V_60 -> V_62 ||
F_29 ( V_44 -> V_47 ) != V_60 -> V_64 ||
F_30 ( & V_44 -> V_48 , & V_60 -> system ) ||
F_29 ( V_44 -> V_50 ) != V_60 -> V_65 ||
F_29 ( V_44 -> V_67 ) != V_60 -> V_66 ||
( V_44 -> V_56 & V_54 ) != ( V_60 -> V_68 & V_54 ) ) {
V_2 -> V_57 &= ~ V_72 ;
}
}
}
static void F_34 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_59 * V_73 = & V_2 -> V_71 ;
const struct V_59 * V_74 = & V_2 -> V_61 ;
if ( V_73 -> V_62 != V_74 -> V_62 ||
V_73 -> V_64 != V_74 -> V_64 ||
F_30 ( & V_73 -> system , & V_74 -> system ) ||
V_73 -> V_65 != V_74 -> V_65 ||
V_73 -> V_66 != V_74 -> V_66 ||
( V_73 -> V_68 & V_54 )
!= ( V_74 -> V_68 & V_54 ) ) {
V_2 -> V_57 &= ~ V_72 ;
}
}
}
static void F_35 ( struct V_44 * V_44 , struct V_2 * V_2 )
{
if ( V_44 && V_2 ) {
if ( ( F_29 ( V_44 -> V_45 ) != V_2 -> V_27 ) ||
( F_29 ( V_44 -> V_46 ) != V_2 -> V_47 ) ||
F_30 ( & ( V_44 -> V_8 ) , & ( V_2 -> V_48 ) ) ||
( F_29 ( V_44 -> V_49 ) != V_2 -> V_50 ) ||
( F_29 ( V_44 -> V_51 ) != V_2 -> V_52 ) ||
( ( V_44 -> V_53 & V_75 ) != ( V_2 -> V_55 & V_75 ) ) ||
( ( V_44 -> V_53 & V_76 ) != ( V_2 -> V_55 & V_76 ) ) ||
( ( V_44 -> V_53 & V_70 ) != ( V_2 -> V_55 & V_70 ) ) ||
( ( V_44 -> V_53 & V_54 ) != ( V_2 -> V_55 & V_54 ) )
) {
V_2 -> V_77 = true ;
}
}
}
static void F_36 ( struct V_2 * V_2 )
{
V_2 = NULL ;
}
static void F_37 ( struct V_2 * V_2 )
{
V_2 = NULL ;
}
static int F_38 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_28 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_78 ;
V_2 ;
V_2 = V_2 -> V_79 ) {
if ( ! ( V_2 -> V_57 & V_80 ) ) {
V_28 = 0 ;
break;
}
}
}
return V_28 ;
}
static void F_39 ( struct V_4 * V_4 , int V_81 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_78 ; V_2 ;
V_2 = V_2 -> V_79 ) {
if ( V_81 )
V_2 -> V_57 |= V_82 ;
else
V_2 -> V_57 &= ~ V_82 ;
}
}
static T_1 F_40 ( struct V_4 * V_4 )
{
T_1 V_83 = 0 ;
if ( V_4 -> V_84 ) {
switch ( F_22 ( V_4 -> V_78 ) ) {
case V_85 :
V_83 = V_4 -> V_84 ;
break;
case V_20 :
V_83 = V_4 -> V_84 * 10 ;
break;
case V_22 :
V_83 = V_4 -> V_84 * 100 ;
break;
case V_24 :
V_83 = V_4 -> V_84 * 1000 ;
break;
case V_26 :
V_83 = V_4 -> V_84 * 10000 ;
break;
default:
V_83 = 0 ;
}
}
return V_83 ;
}
static struct V_4 * F_41 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_86 * V_87 ;
struct V_3 * V_3 ;
F_42 (bond, slave, iter)
if ( F_5 ( V_3 ) . V_4 . V_88 )
return & ( F_5 ( V_3 ) . V_4 ) ;
return NULL ;
}
static inline void F_43 ( struct V_2 * V_2 )
{
struct V_44 * V_44 = & V_2 -> V_44 ;
const struct V_59 * V_60 = & V_2 -> V_61 ;
V_44 -> V_50 = F_44 ( V_2 -> V_50 ) ;
V_44 -> V_48 = V_2 -> V_48 ;
V_44 -> V_67 = F_44 ( V_2 -> V_52 ) ;
V_44 -> V_47 = F_44 ( V_2 -> V_47 ) ;
V_44 -> V_63 = F_44 ( V_2 -> V_27 ) ;
V_44 -> V_56 = V_2 -> V_55 ;
V_44 -> V_49 = F_44 ( V_60 -> V_65 ) ;
V_44 -> V_8 = V_60 -> system ;
V_44 -> V_51 = F_44 ( V_60 -> V_66 ) ;
V_44 -> V_46 = F_44 ( V_60 -> V_64 ) ;
V_44 -> V_45 = F_44 ( V_60 -> V_62 ) ;
V_44 -> V_53 = V_60 -> V_68 ;
}
static int F_45 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_89 * V_90 ;
struct V_91 * V_91 ;
int V_92 = sizeof( struct V_91 ) ;
V_90 = F_46 ( V_92 ) ;
if ( ! V_90 )
return - V_93 ;
V_90 -> V_12 = V_3 -> V_12 ;
F_47 ( V_90 ) ;
V_90 -> V_94 = V_90 -> V_95 + V_96 ;
V_90 -> V_97 = V_98 ;
V_90 -> V_99 = V_100 ;
V_91 = (struct V_91 * ) F_48 ( V_90 , V_92 ) ;
memcpy ( V_91 -> V_101 . V_102 , V_103 , V_104 ) ;
memcpy ( V_91 -> V_101 . V_105 , V_3 -> V_106 , V_104 ) ;
V_91 -> V_101 . V_107 = V_98 ;
V_91 -> V_44 = V_2 -> V_44 ;
F_49 ( V_90 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_2 , struct V_108 * V_109 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_89 * V_90 ;
struct V_110 * V_111 ;
int V_92 = sizeof( struct V_110 ) ;
V_90 = F_46 ( V_92 + 16 ) ;
if ( ! V_90 )
return - V_93 ;
F_51 ( V_90 , 16 ) ;
V_90 -> V_12 = V_3 -> V_12 ;
F_47 ( V_90 ) ;
V_90 -> V_94 = V_90 -> V_95 + V_96 ;
V_90 -> V_97 = V_98 ;
V_111 = (struct V_110 * ) F_48 ( V_90 , V_92 ) ;
memcpy ( V_111 -> V_101 . V_102 , V_103 , V_104 ) ;
memcpy ( V_111 -> V_101 . V_105 , V_3 -> V_106 , V_104 ) ;
V_111 -> V_101 . V_107 = V_98 ;
V_111 -> V_109 = * V_109 ;
F_49 ( V_90 ) ;
return 0 ;
}
static void F_52 ( struct V_2 * V_2 )
{
T_4 V_112 ;
V_112 = V_2 -> V_113 ;
if ( V_2 -> V_57 & V_114 ) {
V_2 -> V_113 = V_115 ;
} else {
switch ( V_2 -> V_113 ) {
case V_115 :
if ( ( V_2 -> V_57 & V_72 )
|| ( V_2 -> V_57 & V_116 ) )
V_2 -> V_113 = V_117 ;
break;
case V_117 :
if ( ! ( V_2 -> V_57 & V_72 ) ) {
V_2 -> V_57 &= ~ V_80 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
V_2 -> V_113 = V_115 ;
break;
}
if ( V_2 -> V_118
&& ! ( -- V_2 -> V_118 ) )
V_2 -> V_57 |= V_80 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_57 & V_82 )
&& ! V_2 -> V_118 )
V_2 -> V_113 = V_119 ;
break;
case V_119 :
if ( ( V_2 -> V_57 & V_72 ) && ( V_2 -> V_61 . V_68 & V_70 ) && ! F_16 ( V_2 ) ) {
V_2 -> V_113 = V_120 ;
} else if ( ! ( V_2 -> V_57 & V_72 ) || ( V_2 -> V_57 & V_116 ) ) {
V_2 -> V_57 &= ~ V_80 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
V_2 -> V_113 = V_115 ;
}
break;
case V_120 :
if ( ! ( V_2 -> V_57 & V_72 ) || ( V_2 -> V_57 & V_116 ) ||
! ( V_2 -> V_61 . V_68 & V_70 )
) {
V_2 -> V_113 = V_119 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_88 &&
! F_13 ( V_2 ) ) {
F_10 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_113 != V_112 ) {
F_23 ( L_4 ,
V_2 -> V_27 , V_112 ,
V_2 -> V_113 ) ;
switch ( V_2 -> V_113 ) {
case V_115 :
F_37 ( V_2 ) ;
V_2 -> V_55 &= ~ V_70 ;
F_53 ( V_2 ) ;
V_2 -> V_55 &= ~ V_121 ;
V_2 -> V_55 &= ~ V_122 ;
V_2 -> V_77 = true ;
break;
case V_117 :
V_2 -> V_118 = F_27 ( V_42 , 0 ) ;
break;
case V_119 :
F_36 ( V_2 ) ;
V_2 -> V_55 |= V_70 ;
V_2 -> V_55 &= ~ V_121 ;
V_2 -> V_55 &= ~ V_122 ;
F_53 ( V_2 ) ;
V_2 -> V_77 = true ;
break;
case V_120 :
V_2 -> V_55 |= V_121 ;
V_2 -> V_55 |= V_122 ;
F_54 ( V_2 ) ;
V_2 -> V_77 = true ;
break;
default:
break;
}
}
}
static void F_55 ( struct V_44 * V_44 , struct V_2 * V_2 )
{
T_5 V_112 ;
V_112 = V_2 -> V_123 ;
if ( V_2 -> V_57 & V_114 )
V_2 -> V_123 = V_124 ;
else if ( ! ( V_2 -> V_57 & V_114 )
&& ! V_2 -> V_125 && ! ( V_2 -> V_57 & V_126 ) )
V_2 -> V_123 = V_127 ;
else if ( V_44 && ( ( V_2 -> V_123 == V_128 ) || ( V_2 -> V_123 == V_129 ) || ( V_2 -> V_123 == V_130 ) ) ) {
V_2 -> V_131 = 0 ;
V_2 -> V_123 = V_130 ;
} else {
if ( V_2 -> V_131 && ! ( -- V_2 -> V_131 ) ) {
switch ( V_2 -> V_123 ) {
case V_128 :
V_2 -> V_123 = V_129 ;
break;
case V_130 :
V_2 -> V_123 = V_128 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_123 ) {
case V_127 :
if ( V_2 -> V_57 & V_126 )
V_2 -> V_123 = V_124 ;
else if ( V_2 -> V_125
&& ( V_2 -> V_57
& V_132 ) )
V_2 -> V_123 = V_128 ;
else if ( V_2 -> V_125
&& ( ( V_2 -> V_57
& V_132 ) == 0 ) )
V_2 -> V_123 = V_133 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_123 != V_112 ) || ( V_44 ) ) {
F_23 ( L_5 ,
V_2 -> V_27 , V_112 ,
V_2 -> V_123 ) ;
switch ( V_2 -> V_123 ) {
case V_124 :
if ( ! ( V_2 -> V_52 & V_134 ) )
V_2 -> V_57 &= ~ V_132 ;
else
V_2 -> V_57 |= V_132 ;
V_2 -> V_57 &= ~ V_72 ;
F_32 ( V_2 ) ;
V_2 -> V_55 &= ~ V_135 ;
V_2 -> V_57 &= ~ V_126 ;
V_2 -> V_123 = V_127 ;
case V_127 :
V_2 -> V_57 &= ~ V_58 ;
break;
case V_133 :
V_2 -> V_57 &= ~ V_72 ;
F_32 ( V_2 ) ;
V_2 -> V_61 . V_68 &= ~ V_54 ;
V_2 -> V_57 |= V_58 ;
V_2 -> V_55 &= ~ V_135 ;
break;
case V_128 :
V_2 -> V_61 . V_68 &= ~ V_70 ;
V_2 -> V_57 &= ~ V_58 ;
V_2 -> V_61 . V_68 |=
V_75 ;
V_2 -> V_131 = F_27 ( V_34 , ( T_2 ) ( V_136 ) ) ;
V_2 -> V_55 |= V_135 ;
break;
case V_129 :
F_34 ( V_2 ) ;
F_32 ( V_2 ) ;
V_2 -> V_57 |= V_58 ;
V_2 -> V_55 &= ~ V_135 ;
break;
case V_130 :
if ( ! F_30 ( & ( V_44 -> V_48 ) , & ( V_2 -> V_48 ) ) ) {
F_56 ( L_6
L_7 ,
V_2 -> V_3 -> V_5 -> V_12 -> V_137 , V_2 -> V_3 -> V_12 -> V_137 ) ;
return;
}
F_33 ( V_44 , V_2 ) ;
F_35 ( V_44 , V_2 ) ;
F_31 ( V_44 , V_2 ) ;
V_2 -> V_131 = F_27 ( V_34 , ( T_2 ) ( V_2 -> V_55 & V_76 ) ) ;
V_2 -> V_55 &= ~ V_135 ;
break;
default:
break;
}
}
}
static void F_57 ( struct V_2 * V_2 )
{
if ( V_2 -> V_138 && ! ( -- V_2 -> V_138 ) ) {
if ( V_2 -> V_77 && ( V_2 -> V_57 & V_132 ) ) {
F_43 ( V_2 ) ;
if ( F_45 ( V_2 ) >= 0 ) {
F_23 ( L_8 ,
V_2 -> V_27 ) ;
V_2 -> V_77 = false ;
}
}
V_2 -> V_138 =
V_36 / V_139 ;
}
}
static void F_58 ( struct V_2 * V_2 )
{
T_6 V_112 ;
V_112 = V_2 -> V_140 ;
if ( ( ( V_2 -> V_57 & V_114 ) || ! ( V_2 -> V_57 & V_132 ) || ! V_2 -> V_125 ) ||
( ! ( V_2 -> V_55 & V_75 ) && ! ( V_2 -> V_61 . V_68 & V_75 ) )
) {
V_2 -> V_140 = V_141 ;
}
else if ( V_2 -> V_142 ) {
if ( ! ( -- V_2 -> V_142 ) ) {
V_2 -> V_140 = V_143 ;
} else {
switch ( V_2 -> V_140 ) {
case V_144 :
if ( ! ( V_2 -> V_61 . V_68
& V_76 ) )
V_2 -> V_140 = V_145 ;
break;
case V_145 :
if ( ( V_2 -> V_61 . V_68 & V_76 ) ) {
V_2 -> V_142 = 0 ;
V_2 -> V_140 = V_143 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_140 ) {
case V_141 :
V_2 -> V_140 = V_144 ;
break;
case V_143 :
if ( ! ( V_2 -> V_61 . V_68
& V_76 ) )
V_2 -> V_140 = V_145 ;
else
V_2 -> V_140 = V_144 ;
break;
default:
break;
}
}
if ( V_2 -> V_140 != V_112 ) {
F_23 ( L_9 ,
V_2 -> V_27 , V_112 ,
V_2 -> V_140 ) ;
switch ( V_2 -> V_140 ) {
case V_141 :
V_2 -> V_142 = 0 ;
break;
case V_144 :
V_2 -> V_142 = F_27 ( V_40 , ( T_2 ) ( V_146 ) ) - 1 ;
break;
case V_145 :
V_2 -> V_142 = F_27 ( V_40 , ( T_2 ) ( V_147 ) ) - 1 ;
break;
case V_143 :
V_2 -> V_77 = true ;
break;
default:
break;
}
}
}
static void F_59 ( struct V_2 * V_2 )
{
struct V_4 * V_4 , * V_148 = NULL , * V_149 ;
struct V_2 * V_150 = NULL , * V_151 ;
struct V_86 * V_87 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_152 = 0 ;
if ( V_2 -> V_57 & V_72 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_149 = V_2 -> V_4 ;
for ( V_151 = V_149 -> V_78 ; V_151 ;
V_150 = V_151 ,
V_151 = V_151 -> V_79 ) {
if ( V_151 == V_2 ) {
V_149 -> V_84 -- ;
if ( ! V_150 ) {
V_149 -> V_78 =
V_2 -> V_79 ;
} else {
V_150 -> V_79 =
V_2 -> V_79 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_79 = NULL ;
V_2 -> V_153 = 0 ;
F_23 ( L_10 ,
V_2 -> V_27 ,
V_149 -> V_154 ) ;
if ( ! V_149 -> V_78 )
F_60 ( V_149 ) ;
break;
}
}
if ( ! V_151 ) {
F_61 ( L_11 ,
V_2 -> V_3 -> V_5 -> V_12 -> V_137 ,
V_2 -> V_27 ,
V_2 -> V_3 -> V_12 -> V_137 ,
V_2 -> V_4 -> V_154 ) ;
}
}
F_42 (bond, slave, iter) {
V_4 = & ( F_5 ( V_3 ) . V_4 ) ;
if ( ! V_4 -> V_78 ) {
if ( ! V_148 )
V_148 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_155 == V_2 -> V_52 ) &&
! F_30 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_61 . system ) ) &&
( V_4 -> V_49 == V_2 -> V_61 . V_65 ) &&
( V_4 -> V_156 == V_2 -> V_61 . V_66 )
) &&
( ( F_30 ( & ( V_2 -> V_61 . system ) , & ( V_157 ) ) &&
! V_4 -> V_158 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_153 =
V_2 -> V_4 -> V_154 ;
V_2 -> V_79 = V_4 -> V_78 ;
V_2 -> V_4 -> V_84 ++ ;
V_4 -> V_78 = V_2 ;
F_23 ( L_12 ,
V_2 -> V_27 ,
V_2 -> V_4 -> V_154 ) ;
V_2 -> V_57 |= V_72 ;
V_152 = 1 ;
break;
}
}
if ( ! V_152 ) {
if ( V_148 ) {
V_2 -> V_4 = V_148 ;
V_2 -> V_153 =
V_2 -> V_4 -> V_154 ;
if ( V_2 -> V_52 & V_134 )
V_2 -> V_4 -> V_158 = false ;
else
V_2 -> V_4 -> V_158 = true ;
V_2 -> V_4 -> V_159 = V_2 -> V_160 ;
V_2 -> V_4 -> V_155 = V_2 -> V_52 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_61 . system ;
V_2 -> V_4 -> V_49 =
V_2 -> V_61 . V_65 ;
V_2 -> V_4 -> V_156 = V_2 -> V_61 . V_66 ;
V_2 -> V_4 -> V_161 = 1 ;
V_2 -> V_4 -> V_162 = 1 ;
V_2 -> V_4 -> V_78 = V_2 ;
V_2 -> V_4 -> V_84 ++ ;
V_2 -> V_57 |= V_72 ;
F_23 ( L_13 ,
V_2 -> V_27 ,
V_2 -> V_4 -> V_154 ) ;
} else {
F_56 ( L_14 ,
V_2 -> V_3 -> V_5 -> V_12 -> V_137 ,
V_2 -> V_27 , V_2 -> V_3 -> V_12 -> V_137 ) ;
}
}
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_62 ( V_4 ) ;
}
static struct V_4 * F_63 ( struct V_4 * V_163 ,
struct V_4 * V_164 )
{
if ( ! V_163 )
return V_164 ;
if ( ! V_164 -> V_158 && V_163 -> V_158 )
return V_164 ;
if ( V_164 -> V_158 && ! V_163 -> V_158 )
return V_163 ;
if ( F_6 ( V_164 ) && ! F_6 ( V_163 ) )
return V_164 ;
if ( ! F_6 ( V_164 ) && F_6 ( V_163 ) )
return V_163 ;
switch ( F_15 ( V_164 -> V_78 ) ) {
case V_165 :
if ( V_164 -> V_84 > V_163 -> V_84 )
return V_164 ;
if ( V_164 -> V_84 < V_163 -> V_84 )
return V_163 ;
case V_13 :
case V_166 :
if ( F_40 ( V_164 ) > F_40 ( V_163 ) )
return V_164 ;
break;
default:
F_61 ( L_15 ,
V_164 -> V_3 -> V_5 -> V_12 -> V_137 ,
F_15 ( V_164 -> V_78 ) ) ;
break;
}
return V_163 ;
}
static int F_64 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_78 ;
if ( ! V_2 )
return 0 ;
return ( F_65 ( V_2 -> V_3 -> V_12 ) &&
F_66 ( V_2 -> V_3 -> V_12 ) ) ;
}
static void F_62 ( struct V_4 * V_7 )
{
struct V_4 * V_163 , * V_167 , * V_168 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_86 * V_87 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
V_168 = V_7 ;
V_167 = F_41 ( V_7 ) ;
V_163 = ( V_167 && F_64 ( V_167 ) ) ? V_167 : NULL ;
F_42 (bond, slave, iter) {
V_7 = & ( F_5 ( V_3 ) . V_4 ) ;
V_7 -> V_88 = 0 ;
if ( V_7 -> V_84 && F_64 ( V_7 ) )
V_163 = F_63 ( V_163 , V_7 ) ;
}
if ( V_163 &&
F_15 ( V_163 -> V_78 ) == V_13 ) {
if ( V_167 && V_167 -> V_78 &&
V_167 -> V_78 -> V_125 &&
( F_6 ( V_167 ) ||
( ! F_6 ( V_167 ) && ! F_6 ( V_163 ) ) ) ) {
if ( ! ( ! V_167 -> V_155 &&
V_163 -> V_155 ) ) {
V_163 = NULL ;
V_167 -> V_88 = 1 ;
}
}
}
if ( V_163 && ( V_163 == V_167 ) ) {
V_163 = NULL ;
V_167 -> V_88 = 1 ;
}
if ( V_163 ) {
F_23 ( L_16 ,
V_163 -> V_154 , V_163 -> V_84 ,
V_163 -> V_155 ,
V_163 -> V_156 ,
V_163 -> V_158 , V_163 -> V_88 ) ;
F_23 ( L_17 ,
V_163 -> V_78 , V_163 -> V_3 ,
V_163 -> V_3 ? V_163 -> V_3 -> V_12 -> V_137 : L_18 ) ;
F_42 (bond, slave, iter) {
V_7 = & ( F_5 ( V_3 ) . V_4 ) ;
F_23 ( L_19 ,
V_7 -> V_154 , V_7 -> V_84 ,
V_7 -> V_155 ,
V_7 -> V_156 ,
V_7 -> V_158 , V_7 -> V_88 ) ;
}
if ( V_163 -> V_158 ) {
F_61 ( L_20 ,
V_163 -> V_3 ? V_163 -> V_3 -> V_5 -> V_12 -> V_137 : L_18 ) ;
}
V_163 -> V_88 = 1 ;
F_23 ( L_21 ,
V_163 -> V_154 ) ;
F_23 ( L_19 ,
V_163 -> V_154 , V_163 -> V_84 ,
V_163 -> V_155 ,
V_163 -> V_156 ,
V_163 -> V_158 , V_163 -> V_88 ) ;
if ( V_167 ) {
for ( V_2 = V_167 -> V_78 ; V_2 ;
V_2 = V_2 -> V_79 ) {
F_8 ( V_2 ) ;
}
}
}
V_167 = F_41 ( V_168 ) ;
if ( V_167 ) {
if ( ! F_6 ( V_167 ) ) {
for ( V_2 = V_167 -> V_78 ; V_2 ;
V_2 = V_2 -> V_79 ) {
F_10 ( V_2 ) ;
}
}
}
F_67 ( V_5 ) ;
}
static void F_60 ( struct V_4 * V_4 )
{
if ( V_4 ) {
V_4 -> V_158 = false ;
V_4 -> V_159 = 0 ;
V_4 -> V_155 = 0 ;
V_4 -> V_8 = V_157 ;
V_4 -> V_49 = 0 ;
V_4 -> V_156 = 0 ;
V_4 -> V_161 = 0 ;
V_4 -> V_162 = 0 ;
V_4 -> V_78 = NULL ;
V_4 -> V_88 = 0 ;
V_4 -> V_84 = 0 ;
F_23 ( L_22 ,
V_4 -> V_154 ) ;
}
}
static void F_68 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_60 ( V_4 ) ;
V_4 -> V_169 = V_157 ;
V_4 -> V_154 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_69 ( struct V_2 * V_2 , int V_170 )
{
static const struct V_59 V_171 = {
. V_65 = 0xffff ,
. V_66 = 1 ,
. V_62 = 1 ,
. V_64 = 0xff ,
. V_68 = 1 ,
} ;
static const struct V_44 V_44 = {
. V_172 = 0x01 ,
. V_173 = 0x01 ,
. V_174 = 0x01 ,
. V_175 = 0x14 ,
. V_176 = 0x02 ,
. V_177 = 0x14 ,
. V_178 = 0x03 ,
. V_179 = 0x10 ,
. V_180 = F_44 ( V_181 ) ,
} ;
if ( V_2 ) {
V_2 -> V_27 = 1 ;
V_2 -> V_47 = 0xff ;
V_2 -> V_48 = V_157 ;
V_2 -> V_50 = 0xffff ;
V_2 -> V_153 = 0 ;
V_2 -> V_77 = false ;
V_2 -> V_160 = 1 ;
V_2 -> V_52 = 1 ;
V_2 -> V_182 = V_54 | V_75 ;
V_2 -> V_55 = V_54 | V_75 ;
if ( V_170 )
V_2 -> V_55 |= V_76 ;
memcpy ( & V_2 -> V_71 , & V_171 , sizeof( V_171 ) ) ;
memcpy ( & V_2 -> V_61 , & V_171 , sizeof( V_171 ) ) ;
V_2 -> V_125 = true ;
V_2 -> V_57 = 0x3 ;
V_2 -> V_123 = 0 ;
V_2 -> V_131 = 0 ;
V_2 -> V_140 = 0 ;
V_2 -> V_142 = 0 ;
V_2 -> V_113 = 0 ;
V_2 -> V_118 = 0 ;
V_2 -> V_183 = 0 ;
V_2 -> V_138 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_79 = NULL ;
V_2 -> V_184 = 0 ;
memcpy ( & V_2 -> V_44 , & V_44 , sizeof( V_44 ) ) ;
}
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_4 -> V_88 ) {
F_23 ( L_23 ,
V_2 -> V_27 ,
V_2 -> V_4 -> V_154 ) ;
F_10 ( V_2 ) ;
}
}
static void F_53 ( struct V_2 * V_2 )
{
if ( V_2 -> V_4 && F_30 ( & ( V_2 -> V_4 -> V_8 ) , & ( V_157 ) ) ) {
F_23 ( L_24 ,
V_2 -> V_27 ,
V_2 -> V_4 -> V_154 ) ;
F_8 ( V_2 ) ;
}
}
static void F_70 ( struct V_108 * V_185 ,
struct V_2 * V_2 )
{
struct V_108 V_109 ;
memcpy ( & V_109 , V_185 , sizeof( struct V_108 ) ) ;
V_109 . V_186 = V_187 ;
if ( F_50 ( V_2 , & V_109 ) >= 0 ) {
F_23 ( L_25 ,
V_2 -> V_27 ) ;
}
}
static void F_71 ( struct V_108 * V_109 ,
struct V_2 * V_2 )
{
V_109 = NULL ;
V_2 = NULL ;
}
void F_72 ( struct V_1 * V_5 , int V_188 )
{
F_17 ( V_5 ) . V_16 = V_188 ;
}
void F_73 ( struct V_1 * V_5 , T_2 V_189 )
{
if ( F_30 ( & ( F_17 ( V_5 ) . system . V_190 ) ,
V_5 -> V_12 -> V_191 ) ) {
V_154 = 0 ;
F_17 ( V_5 ) . system . V_192 = 0xFFFF ;
F_17 ( V_5 ) . system . V_190 = * ( (struct V_193 * ) V_5 -> V_12 -> V_191 ) ;
V_36 = V_189 ;
F_72 ( V_5 ,
V_194 *
V_36 ) ;
}
}
int F_74 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( V_5 == NULL ) {
F_56 ( L_26 ,
V_3 -> V_5 -> V_12 -> V_137 , V_3 -> V_12 -> V_137 ) ;
return - 1 ;
}
if ( F_5 ( V_3 ) . V_2 . V_3 != V_3 ) {
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
F_69 ( V_2 , V_5 -> V_14 . V_170 ) ;
F_25 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_27 = F_5 ( V_3 ) . V_195 ;
V_2 -> V_160 = 0 ;
V_2 -> V_160 |= F_24 ( V_2 ) ;
V_2 -> V_160 |= ( F_22 ( V_2 ) << 1 ) ;
V_2 -> V_52 = V_2 -> V_160 ;
if ( ! ( V_2 -> V_52 & V_134 ) )
V_2 -> V_57 &= ~ V_132 ;
V_2 -> V_48 = F_17 ( V_5 ) . system . V_190 ;
V_2 -> V_138 = V_36 / V_139 ;
V_2 -> V_4 = NULL ;
V_2 -> V_79 = NULL ;
F_8 ( V_2 ) ;
V_4 = & ( F_5 ( V_3 ) . V_4 ) ;
F_68 ( V_4 ) ;
V_4 -> V_169 = * ( (struct V_193 * ) V_5 -> V_12 -> V_191 ) ;
V_4 -> V_154 = ( ++ V_154 ) ;
V_4 -> V_3 = V_3 ;
V_4 -> V_88 = 0 ;
V_4 -> V_84 = 0 ;
}
return 0 ;
}
void F_75 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_196 , * V_197 ;
struct V_4 * V_4 , * V_198 , * V_149 ;
int V_199 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_200 ;
struct V_86 * V_87 ;
V_4 = & ( F_5 ( V_3 ) . V_4 ) ;
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_27 ,
V_3 -> V_5 -> V_12 -> V_137 , V_3 -> V_12 -> V_137 ) ;
return;
}
F_23 ( L_28 ,
V_4 -> V_154 ) ;
V_2 -> V_55 &= ~ V_54 ;
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
if ( V_4 -> V_78 ) {
if ( ( V_4 -> V_78 != V_2 ) || ( V_4 -> V_78 -> V_79 ) ) {
F_42 (bond, slave_iter, iter) {
V_198 = & ( F_5 ( V_200 ) . V_4 ) ;
if ( ! V_198 -> V_78
|| ( ( V_198 -> V_78 == V_2 )
&& ! V_198 -> V_78 -> V_79 ) )
break;
}
if ( ! V_200 )
V_198 = NULL ;
if ( ( V_198 ) && ( ( ! V_198 -> V_78 ) || ( ( V_198 -> V_78 == V_2 ) && ! V_198 -> V_78 -> V_79 ) ) ) {
F_23 ( L_29 ,
V_4 -> V_154 ,
V_198 -> V_154 ) ;
if ( ( V_198 -> V_78 == V_2 ) && V_198 -> V_88 ) {
F_76 ( L_30 ,
V_4 -> V_3 -> V_5 -> V_12 -> V_137 ) ;
V_199 = 1 ;
}
V_198 -> V_158 = V_4 -> V_158 ;
V_198 -> V_159 = V_4 -> V_159 ;
V_198 -> V_155 = V_4 -> V_155 ;
V_198 -> V_8 = V_4 -> V_8 ;
V_198 -> V_49 = V_4 -> V_49 ;
V_198 -> V_156 = V_4 -> V_156 ;
V_198 -> V_161 = V_4 -> V_161 ;
V_198 -> V_162 = V_4 -> V_162 ;
V_198 -> V_78 = V_4 -> V_78 ;
V_198 -> V_88 = V_4 -> V_88 ;
V_198 -> V_84 = V_4 -> V_84 ;
for ( V_197 = V_4 -> V_78 ; V_197 ;
V_197 = V_197 -> V_79 ) {
V_197 -> V_4 = V_198 ;
V_197 -> V_153 = V_198 -> V_154 ;
}
F_60 ( V_4 ) ;
if ( V_199 )
F_62 ( F_3 ( V_2 ) ) ;
} else {
F_61 ( L_31 ,
V_3 -> V_5 -> V_12 -> V_137 ) ;
}
} else {
V_199 = V_4 -> V_88 ;
F_60 ( V_4 ) ;
if ( V_199 ) {
F_76 ( L_30 ,
V_3 -> V_5 -> V_12 -> V_137 ) ;
V_149 = F_3 ( V_2 ) ;
if ( V_149 )
F_62 ( V_149 ) ;
}
}
}
F_23 ( L_32 , V_2 -> V_27 ) ;
F_42 (bond, slave_iter, iter) {
V_149 = & ( F_5 ( V_200 ) . V_4 ) ;
V_196 = NULL ;
for ( V_197 = V_149 -> V_78 ; V_197 ;
V_196 = V_197 ,
V_197 = V_197 -> V_79 ) {
if ( V_197 == V_2 ) {
if ( V_196 )
V_196 -> V_79 = V_197 -> V_79 ;
else
V_149 -> V_78 = V_197 -> V_79 ;
V_149 -> V_84 -- ;
if ( V_149 -> V_84 == 0 ) {
V_199 = V_149 -> V_88 ;
F_60 ( V_149 ) ;
if ( V_199 ) {
F_76 ( L_30 ,
V_3 -> V_5 -> V_12 -> V_137 ) ;
F_62 ( F_3 ( V_2 ) ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
}
void F_77 ( struct V_201 * V_202 )
{
struct V_1 * V_5 = F_78 ( V_202 , struct V_1 ,
V_203 . V_202 ) ;
struct V_4 * V_4 ;
struct V_86 * V_87 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_79 ( & V_5 -> V_204 ) ;
if ( ! F_80 ( V_5 ) )
goto V_205;
if ( F_17 ( V_5 ) . V_16 && ! ( -- F_17 ( V_5 ) . V_16 ) ) {
V_3 = F_4 ( V_5 ) ;
V_2 = V_3 ? & ( F_5 ( V_3 ) . V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_61 ( L_33 ,
V_5 -> V_12 -> V_137 ) ;
goto V_205;
}
V_4 = F_3 ( V_2 ) ;
F_62 ( V_4 ) ;
}
F_67 ( V_5 ) ;
}
F_42 (bond, slave, iter) {
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_34 ,
V_5 -> V_12 -> V_137 ) ;
goto V_205;
}
F_18 ( V_2 ) ;
F_55 ( NULL , V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_52 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> V_57 & V_114 )
V_2 -> V_57 &= ~ V_114 ;
F_20 ( V_2 ) ;
}
V_205:
F_81 ( V_5 -> V_206 , & V_5 -> V_203 , V_207 ) ;
F_82 ( & V_5 -> V_204 ) ;
}
static int F_83 ( struct V_44 * V_44 , struct V_3 * V_3 , T_2 V_92 )
{
struct V_2 * V_2 ;
int V_208 = V_209 ;
if ( V_92 >= sizeof( struct V_44 ) ) {
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_35 ,
V_3 -> V_12 -> V_137 , V_3 -> V_5 -> V_12 -> V_137 ) ;
return V_208 ;
}
switch ( V_44 -> V_172 ) {
case V_210 :
V_208 = V_211 ;
F_23 ( L_36 ,
V_2 -> V_27 ) ;
F_18 ( V_2 ) ;
F_55 ( V_44 , V_2 ) ;
F_20 ( V_2 ) ;
break;
case V_212 :
V_208 = V_211 ;
switch ( ( (struct V_108 * ) V_44 ) -> V_186 ) {
case V_213 :
F_23 ( L_37 ,
V_2 -> V_27 ) ;
F_70 ( (struct V_108 * ) V_44 , V_2 ) ;
break;
case V_187 :
F_23 ( L_38 ,
V_2 -> V_27 ) ;
F_71 ( (struct V_108 * ) V_44 , V_2 ) ;
break;
default:
F_23 ( L_39 ,
V_2 -> V_27 ) ;
}
}
}
return V_208 ;
}
void F_84 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_40 ,
V_3 -> V_5 -> V_12 -> V_137 , V_3 -> V_12 -> V_137 ) ;
return;
}
F_18 ( V_2 ) ;
V_2 -> V_160 &= ~ V_214 ;
V_2 -> V_52 = V_2 -> V_160 |=
( F_22 ( V_2 ) << 1 ) ;
F_23 ( L_41 , V_2 -> V_27 ) ;
V_2 -> V_57 |= V_114 ;
F_20 ( V_2 ) ;
}
void F_85 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_42 ,
V_3 -> V_5 -> V_12 -> V_137 , V_3 -> V_12 -> V_137 ) ;
return;
}
F_18 ( V_2 ) ;
V_2 -> V_160 &= ~ V_134 ;
V_2 -> V_52 = V_2 -> V_160 |=
F_24 ( V_2 ) ;
F_23 ( L_43 , V_2 -> V_27 ) ;
V_2 -> V_57 |= V_114 ;
F_20 ( V_2 ) ;
}
void F_86 ( struct V_3 * V_3 , char V_10 )
{
struct V_2 * V_2 ;
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_44 ,
V_3 -> V_5 -> V_12 -> V_137 , V_3 -> V_12 -> V_137 ) ;
return;
}
F_18 ( V_2 ) ;
if ( V_10 == V_11 ) {
V_2 -> V_125 = true ;
V_2 -> V_160 &= ~ V_134 ;
V_2 -> V_52 = V_2 -> V_160 |=
F_24 ( V_2 ) ;
V_2 -> V_160 &= ~ V_214 ;
V_2 -> V_52 = V_2 -> V_160 |=
( F_22 ( V_2 ) << 1 ) ;
} else {
V_2 -> V_125 = false ;
V_2 -> V_160 &= ~ V_134 ;
V_2 -> V_52 = ( V_2 -> V_160 &=
~ V_214 ) ;
}
F_23 ( L_45 ,
V_2 -> V_27 ,
( V_10 == V_11 ) ? L_46 : L_47 ) ;
V_2 -> V_57 |= V_114 ;
F_20 ( V_2 ) ;
}
int F_67 ( struct V_1 * V_5 )
{
struct V_4 * V_167 ;
struct V_3 * V_6 ;
V_6 = F_4 ( V_5 ) ;
if ( ! V_6 )
return 0 ;
V_167 = F_41 ( & ( F_5 ( V_6 ) . V_4 ) ) ;
if ( V_167 ) {
if ( V_167 -> V_84 < V_5 -> V_14 . V_215 ) {
if ( F_66 ( V_5 -> V_12 ) ) {
F_87 ( V_5 -> V_12 ) ;
return 1 ;
}
} else if ( ! F_66 ( V_5 -> V_12 ) ) {
F_88 ( V_5 -> V_12 ) ;
return 1 ;
}
return 0 ;
}
if ( F_66 ( V_5 -> V_12 ) ) {
F_87 ( V_5 -> V_12 ) ;
return 1 ;
}
return 0 ;
}
int F_89 ( struct V_1 * V_5 ,
struct V_216 * V_216 )
{
struct V_4 * V_4 = NULL ;
struct V_86 * V_87 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_90 (bond, slave, iter) {
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_88 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( V_4 ) {
V_216 -> V_217 = V_4 -> V_154 ;
V_216 -> V_218 = V_4 -> V_84 ;
V_216 -> V_67 = V_4 -> V_155 ;
V_216 -> V_51 = V_4 -> V_156 ;
memcpy ( V_216 -> V_8 , V_4 -> V_8 . V_9 , V_104 ) ;
return 0 ;
}
return - 1 ;
}
int F_91 ( struct V_1 * V_5 , struct V_216 * V_216 )
{
int V_208 ;
F_92 () ;
V_208 = F_89 ( V_5 , V_216 ) ;
F_93 () ;
return V_208 ;
}
int F_94 ( struct V_89 * V_90 , struct V_219 * V_12 )
{
struct V_1 * V_5 = F_95 ( V_12 ) ;
struct V_3 * V_3 , * V_220 ;
struct V_4 * V_7 ;
struct V_216 V_216 ;
struct V_86 * V_87 ;
int V_221 ;
int V_222 ;
int V_223 = 1 ;
int V_224 ;
if ( F_89 ( V_5 , & V_216 ) ) {
F_23 ( L_48 ,
V_12 -> V_137 ) ;
goto V_225;
}
V_221 = V_216 . V_218 ;
V_224 = V_216 . V_217 ;
if ( V_221 == 0 ) {
F_23 ( L_49 , V_12 -> V_137 ) ;
goto V_225;
}
V_222 = F_96 ( V_5 , V_90 , V_221 ) ;
V_220 = NULL ;
F_90 (bond, slave, iter) {
V_7 = F_5 ( V_3 ) . V_2 . V_4 ;
if ( ! V_7 || V_7 -> V_154 != V_224 )
continue;
if ( V_222 >= 0 ) {
if ( ! V_220 && F_97 ( V_3 ) )
V_220 = V_3 ;
V_222 -- ;
continue;
}
if ( F_97 ( V_3 ) ) {
V_223 = F_98 ( V_5 , V_90 , V_3 -> V_12 ) ;
goto V_225;
}
}
if ( V_222 >= 0 ) {
F_56 ( L_50 ,
V_12 -> V_137 , V_224 ) ;
goto V_225;
}
if ( V_220 )
V_223 = F_98 ( V_5 , V_90 , V_220 -> V_12 ) ;
V_225:
if ( V_223 ) {
F_99 ( V_90 ) ;
}
return V_226 ;
}
int F_100 ( const struct V_89 * V_90 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
int V_208 = V_209 ;
struct V_44 * V_44 , V_227 ;
if ( V_90 -> V_97 != V_98 )
return V_208 ;
V_44 = F_101 ( V_90 , 0 , sizeof( V_227 ) , & V_227 ) ;
if ( ! V_44 )
return V_208 ;
F_79 ( & V_5 -> V_204 ) ;
V_208 = F_83 ( V_44 , V_3 , V_90 -> V_228 ) ;
F_82 ( & V_5 -> V_204 ) ;
return V_208 ;
}
void F_102 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_86 * V_87 ;
struct V_3 * V_3 ;
int V_170 ;
V_170 = V_5 -> V_14 . V_170 ;
F_42 (bond, slave, iter) {
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
F_18 ( V_2 ) ;
if ( V_170 )
V_2 -> V_55 |= V_76 ;
else
V_2 -> V_55 &= ~ V_76 ;
F_20 ( V_2 ) ;
}
}
