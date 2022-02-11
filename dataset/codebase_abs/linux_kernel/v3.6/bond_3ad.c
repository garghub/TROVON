static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
if ( V_2 -> V_3 == NULL )
return NULL ;
return F_2 ( V_2 -> V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_1 * V_4 )
{
if ( V_4 -> V_5 == 0 )
return NULL ;
return & ( F_4 ( V_4 -> V_6 ) . V_2 ) ;
}
static inline struct V_2 * F_5 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( ( V_4 == NULL ) || ( V_3 -> V_7 == V_4 -> V_6 ) )
return NULL ;
return & ( F_4 ( V_3 -> V_7 ) . V_2 ) ;
}
static inline struct V_8 * F_6 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
if ( ( V_4 == NULL ) || ( V_4 -> V_5 == 0 ) )
return NULL ;
return & ( F_4 ( V_4 -> V_6 ) . V_8 ) ;
}
static inline struct V_8 * F_7 ( struct V_8 * V_8 )
{
struct V_3 * V_3 = V_8 -> V_3 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( ( V_4 == NULL ) || ( V_3 -> V_7 == V_4 -> V_6 ) )
return NULL ;
return & ( F_4 ( V_3 -> V_7 ) . V_8 ) ;
}
static inline int F_8 ( struct V_8 * V_9 )
{
return ! F_9 ( V_9 -> V_10 . V_11 ) ;
}
static inline void F_10 ( struct V_2 * V_2 )
{
F_11 ( V_2 -> V_3 ) ;
}
static inline void F_12 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
if ( ( V_3 -> V_12 == V_13 ) && F_13 ( V_3 -> V_14 ) )
F_14 ( V_3 ) ;
}
static inline int F_15 ( struct V_2 * V_2 )
{
return F_16 ( V_2 -> V_3 ) ;
}
static inline T_1 F_17 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
if ( V_4 == NULL )
return V_15 ;
return V_4 -> V_16 . V_17 ;
}
static inline int F_18 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
if ( V_4 == NULL )
return 0 ;
return F_19 ( V_4 ) . V_18 ? 1 : 0 ;
}
static inline void F_20 ( struct V_2 * V_2 )
{
F_21 ( & ( F_4 ( V_2 -> V_3 ) . V_19 ) ) ;
}
static inline void F_22 ( struct V_2 * V_2 )
{
F_23 ( & ( F_4 ( V_2 -> V_3 ) . V_19 ) ) ;
}
static T_2 F_24 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_2 V_20 ;
if ( V_3 -> V_12 != V_13 )
V_20 = 0 ;
else {
switch ( V_3 -> V_20 ) {
case V_21 :
V_20 = V_22 ;
break;
case V_23 :
V_20 = V_24 ;
break;
case V_25 :
V_20 = V_26 ;
break;
case V_27 :
V_20 = V_28 ;
break;
default:
V_20 = 0 ;
break;
}
}
F_25 ( L_1 ,
V_2 -> V_29 , V_20 ) ;
return V_20 ;
}
static T_3 F_26 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_30 ;
if ( V_3 -> V_12 != V_13 )
V_30 = 0x0 ;
else {
switch ( V_3 -> V_31 ) {
case V_32 :
V_30 = 0x1 ;
F_25 ( L_2 ,
V_2 -> V_29 ) ;
break;
case V_33 :
default:
V_30 = 0x0 ;
F_25 ( L_3 ,
V_2 -> V_29 ) ;
break;
}
}
return V_30 ;
}
static inline void F_27 ( struct V_2 * V_2 )
{
F_28 ( & ( F_4 ( V_2 -> V_3 ) . V_19 ) ) ;
}
static T_2 F_29 ( T_2 V_34 , T_2 V_35 )
{
T_2 V_30 = 0 ;
switch ( V_34 ) {
case V_36 :
if ( V_35 )
V_30 = ( V_37 * V_38 ) ;
else
V_30 = ( V_39 * V_38 ) ;
break;
case V_40 :
V_30 = ( V_41 * V_38 ) ;
break;
case V_42 :
V_30 = ( V_35 * V_38 ) ;
break;
case V_43 :
V_30 = ( V_41 * V_38 ) ;
break;
case V_44 :
V_30 = ( V_45 * V_38 ) ;
break;
}
return V_30 ;
}
static void F_30 ( struct V_46 * V_46 , struct V_2 * V_2 )
{
if ( ( ( F_31 ( V_46 -> V_47 ) == V_2 -> V_29 ) &&
( F_31 ( V_46 -> V_48 ) == V_2 -> V_49 ) &&
! F_32 ( & ( V_46 -> V_10 ) , & ( V_2 -> V_50 ) ) &&
( F_31 ( V_46 -> V_51 ) == V_2 -> V_52 ) &&
( F_31 ( V_46 -> V_53 ) == V_2 -> V_54 ) &&
( ( V_46 -> V_55 & V_56 ) == ( V_2 -> V_57 & V_56 ) ) ) ||
( ( V_46 -> V_58 & V_56 ) == 0 )
) {
V_2 -> V_59 |= V_60 ;
} else {
V_2 -> V_59 &= ~ V_60 ;
}
}
static void F_33 ( struct V_46 * V_46 , struct V_2 * V_2 )
{
if ( V_46 && V_2 ) {
struct V_61 * V_62 = & V_2 -> V_63 ;
F_30 ( V_46 , V_2 ) ;
V_62 -> V_64 = F_31 ( V_46 -> V_65 ) ;
V_62 -> V_66 = F_31 ( V_46 -> V_49 ) ;
V_62 -> system = V_46 -> V_50 ;
V_62 -> V_67 = F_31 ( V_46 -> V_52 ) ;
V_62 -> V_68 = F_31 ( V_46 -> V_69 ) ;
V_62 -> V_70 = V_46 -> V_58 ;
V_2 -> V_57 &= ~ V_71 ;
if ( ( V_2 -> V_59 & V_60 )
&& ( V_46 -> V_58 & V_72 ) )
V_62 -> V_70 |= V_72 ;
else
V_62 -> V_70 &= ~ V_72 ;
}
}
static void F_34 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_63 , & V_2 -> V_73 ,
sizeof( struct V_61 ) ) ;
V_2 -> V_57 |= V_71 ;
}
}
static void F_35 ( struct V_46 * V_46 , struct V_2 * V_2 )
{
if ( V_46 && V_2 ) {
const struct V_61 * V_62 = & V_2 -> V_63 ;
if ( F_31 ( V_46 -> V_65 ) != V_62 -> V_64 ||
F_31 ( V_46 -> V_49 ) != V_62 -> V_66 ||
F_32 ( & V_46 -> V_50 , & V_62 -> system ) ||
F_31 ( V_46 -> V_52 ) != V_62 -> V_67 ||
F_31 ( V_46 -> V_69 ) != V_62 -> V_68 ||
( V_46 -> V_58 & V_56 ) != ( V_62 -> V_70 & V_56 ) ) {
V_2 -> V_59 &= ~ V_74 ;
}
}
}
static void F_36 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_61 * V_75 = & V_2 -> V_73 ;
const struct V_61 * V_76 = & V_2 -> V_63 ;
if ( V_75 -> V_64 != V_76 -> V_64 ||
V_75 -> V_66 != V_76 -> V_66 ||
F_32 ( & V_75 -> system , & V_76 -> system ) ||
V_75 -> V_67 != V_76 -> V_67 ||
V_75 -> V_68 != V_76 -> V_68 ||
( V_75 -> V_70 & V_56 )
!= ( V_76 -> V_70 & V_56 ) ) {
V_2 -> V_59 &= ~ V_74 ;
}
}
}
static void F_37 ( struct V_46 * V_46 , struct V_2 * V_2 )
{
if ( V_46 && V_2 ) {
if ( ( F_31 ( V_46 -> V_47 ) != V_2 -> V_29 ) ||
( F_31 ( V_46 -> V_48 ) != V_2 -> V_49 ) ||
F_32 ( & ( V_46 -> V_10 ) , & ( V_2 -> V_50 ) ) ||
( F_31 ( V_46 -> V_51 ) != V_2 -> V_52 ) ||
( F_31 ( V_46 -> V_53 ) != V_2 -> V_54 ) ||
( ( V_46 -> V_55 & V_77 ) != ( V_2 -> V_57 & V_77 ) ) ||
( ( V_46 -> V_55 & V_78 ) != ( V_2 -> V_57 & V_78 ) ) ||
( ( V_46 -> V_55 & V_72 ) != ( V_2 -> V_57 & V_72 ) ) ||
( ( V_46 -> V_55 & V_56 ) != ( V_2 -> V_57 & V_56 ) )
) {
V_2 -> V_79 = true ;
}
}
}
static void F_38 ( struct V_2 * V_2 )
{
V_2 = NULL ;
}
static void F_39 ( struct V_2 * V_2 )
{
V_2 = NULL ;
}
static int F_40 ( struct V_8 * V_8 )
{
struct V_2 * V_2 ;
int V_30 = 1 ;
if ( V_8 ) {
for ( V_2 = V_8 -> V_80 ;
V_2 ;
V_2 = V_2 -> V_81 ) {
if ( ! ( V_2 -> V_59 & V_82 ) ) {
V_30 = 0 ;
break;
}
}
}
return V_30 ;
}
static void F_41 ( struct V_8 * V_8 , int V_83 )
{
struct V_2 * V_2 ;
for ( V_2 = V_8 -> V_80 ; V_2 ;
V_2 = V_2 -> V_81 ) {
if ( V_83 )
V_2 -> V_59 |= V_84 ;
else
V_2 -> V_59 &= ~ V_84 ;
}
}
static T_1 F_42 ( struct V_8 * V_8 )
{
T_1 V_85 = 0 ;
if ( V_8 -> V_86 ) {
switch ( F_24 ( V_8 -> V_80 ) ) {
case V_87 :
V_85 = V_8 -> V_86 ;
break;
case V_22 :
V_85 = V_8 -> V_86 * 10 ;
break;
case V_24 :
V_85 = V_8 -> V_86 * 100 ;
break;
case V_26 :
V_85 = V_8 -> V_86 * 1000 ;
break;
case V_28 :
V_85 = V_8 -> V_86 * 10000 ;
break;
default:
V_85 = 0 ;
}
}
return V_85 ;
}
static struct V_8 * F_43 ( struct V_8 * V_8 )
{
struct V_8 * V_30 = NULL ;
for (; V_8 ; V_8 = F_7 ( V_8 ) ) {
if ( V_8 -> V_88 ) {
V_30 = V_8 ;
break;
}
}
return V_30 ;
}
static inline void F_44 ( struct V_2 * V_2 )
{
struct V_46 * V_46 = & V_2 -> V_46 ;
const struct V_61 * V_62 = & V_2 -> V_63 ;
V_46 -> V_52 = F_45 ( V_2 -> V_52 ) ;
V_46 -> V_50 = V_2 -> V_50 ;
V_46 -> V_69 = F_45 ( V_2 -> V_54 ) ;
V_46 -> V_49 = F_45 ( V_2 -> V_49 ) ;
V_46 -> V_65 = F_45 ( V_2 -> V_29 ) ;
V_46 -> V_58 = V_2 -> V_57 ;
V_46 -> V_51 = F_45 ( V_62 -> V_67 ) ;
V_46 -> V_10 = V_62 -> system ;
V_46 -> V_53 = F_45 ( V_62 -> V_68 ) ;
V_46 -> V_48 = F_45 ( V_62 -> V_66 ) ;
V_46 -> V_47 = F_45 ( V_62 -> V_64 ) ;
V_46 -> V_55 = V_62 -> V_70 ;
}
static int F_46 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_89 * V_90 ;
struct V_91 * V_91 ;
int V_92 = sizeof( struct V_91 ) ;
V_90 = F_47 ( V_92 ) ;
if ( ! V_90 )
return - V_93 ;
V_90 -> V_14 = V_3 -> V_14 ;
F_48 ( V_90 ) ;
V_90 -> V_94 = V_90 -> V_95 + V_96 ;
V_90 -> V_97 = V_98 ;
V_90 -> V_99 = V_100 ;
V_91 = (struct V_91 * ) F_49 ( V_90 , V_92 ) ;
memcpy ( V_91 -> V_101 . V_102 , V_103 , V_104 ) ;
memcpy ( V_91 -> V_101 . V_105 , V_3 -> V_106 , V_104 ) ;
V_91 -> V_101 . V_107 = V_98 ;
V_91 -> V_46 = V_2 -> V_46 ;
F_50 ( V_90 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_2 , struct V_108 * V_109 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_89 * V_90 ;
struct V_110 * V_111 ;
int V_92 = sizeof( struct V_110 ) ;
V_90 = F_47 ( V_92 + 16 ) ;
if ( ! V_90 )
return - V_93 ;
F_52 ( V_90 , 16 ) ;
V_90 -> V_14 = V_3 -> V_14 ;
F_48 ( V_90 ) ;
V_90 -> V_94 = V_90 -> V_95 + V_96 ;
V_90 -> V_97 = V_98 ;
V_111 = (struct V_110 * ) F_49 ( V_90 , V_92 ) ;
memcpy ( V_111 -> V_101 . V_102 , V_103 , V_104 ) ;
memcpy ( V_111 -> V_101 . V_105 , V_3 -> V_106 , V_104 ) ;
V_111 -> V_101 . V_107 = V_98 ;
V_111 -> V_109 = * V_109 ;
F_50 ( V_90 ) ;
return 0 ;
}
static void F_53 ( struct V_2 * V_2 )
{
T_4 V_112 ;
V_112 = V_2 -> V_113 ;
if ( V_2 -> V_59 & V_114 ) {
V_2 -> V_113 = V_115 ;
} else {
switch ( V_2 -> V_113 ) {
case V_115 :
if ( ( V_2 -> V_59 & V_74 )
|| ( V_2 -> V_59 & V_116 ) )
V_2 -> V_113 = V_117 ;
break;
case V_117 :
if ( ! ( V_2 -> V_59 & V_74 ) ) {
V_2 -> V_59 &= ~ V_82 ;
F_41 ( V_2 -> V_8 , F_40 ( V_2 -> V_8 ) ) ;
V_2 -> V_113 = V_115 ;
break;
}
if ( V_2 -> V_118
&& ! ( -- V_2 -> V_118 ) )
V_2 -> V_59 |= V_82 ;
F_41 ( V_2 -> V_8 , F_40 ( V_2 -> V_8 ) ) ;
if ( ( V_2 -> V_59 & V_84 )
&& ! V_2 -> V_118 )
V_2 -> V_113 = V_119 ;
break;
case V_119 :
if ( ( V_2 -> V_59 & V_74 ) && ( V_2 -> V_63 . V_70 & V_72 ) && ! F_18 ( V_2 ) ) {
V_2 -> V_113 = V_120 ;
} else if ( ! ( V_2 -> V_59 & V_74 ) || ( V_2 -> V_59 & V_116 ) ) {
V_2 -> V_59 &= ~ V_82 ;
F_41 ( V_2 -> V_8 , F_40 ( V_2 -> V_8 ) ) ;
V_2 -> V_113 = V_115 ;
}
break;
case V_120 :
if ( ! ( V_2 -> V_59 & V_74 ) || ( V_2 -> V_59 & V_116 ) ||
! ( V_2 -> V_63 . V_70 & V_72 )
) {
V_2 -> V_113 = V_119 ;
} else {
if ( V_2 -> V_8 &&
V_2 -> V_8 -> V_88 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_113 != V_112 ) {
F_25 ( L_4 ,
V_2 -> V_29 , V_112 ,
V_2 -> V_113 ) ;
switch ( V_2 -> V_113 ) {
case V_115 :
F_39 ( V_2 ) ;
V_2 -> V_57 &= ~ V_72 ;
F_54 ( V_2 ) ;
V_2 -> V_57 &= ~ V_121 ;
V_2 -> V_57 &= ~ V_122 ;
V_2 -> V_79 = true ;
break;
case V_117 :
V_2 -> V_118 = F_29 ( V_44 , 0 ) ;
break;
case V_119 :
F_38 ( V_2 ) ;
V_2 -> V_57 |= V_72 ;
V_2 -> V_57 &= ~ V_121 ;
V_2 -> V_57 &= ~ V_122 ;
F_54 ( V_2 ) ;
V_2 -> V_79 = true ;
break;
case V_120 :
V_2 -> V_57 |= V_121 ;
V_2 -> V_57 |= V_122 ;
F_55 ( V_2 ) ;
V_2 -> V_79 = true ;
break;
default:
break;
}
}
}
static void F_56 ( struct V_46 * V_46 , struct V_2 * V_2 )
{
T_5 V_112 ;
V_112 = V_2 -> V_123 ;
if ( V_2 -> V_59 & V_114 )
V_2 -> V_123 = V_124 ;
else if ( ! ( V_2 -> V_59 & V_114 )
&& ! V_2 -> V_125 && ! ( V_2 -> V_59 & V_126 ) )
V_2 -> V_123 = V_127 ;
else if ( V_46 && ( ( V_2 -> V_123 == V_128 ) || ( V_2 -> V_123 == V_129 ) || ( V_2 -> V_123 == V_130 ) ) ) {
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
if ( V_2 -> V_59 & V_126 )
V_2 -> V_123 = V_124 ;
else if ( V_2 -> V_125
&& ( V_2 -> V_59
& V_132 ) )
V_2 -> V_123 = V_128 ;
else if ( V_2 -> V_125
&& ( ( V_2 -> V_59
& V_132 ) == 0 ) )
V_2 -> V_123 = V_133 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_123 != V_112 ) || ( V_46 ) ) {
F_25 ( L_5 ,
V_2 -> V_29 , V_112 ,
V_2 -> V_123 ) ;
switch ( V_2 -> V_123 ) {
case V_124 :
if ( ! ( V_2 -> V_54 & V_134 ) )
V_2 -> V_59 &= ~ V_132 ;
else
V_2 -> V_59 |= V_132 ;
V_2 -> V_59 &= ~ V_74 ;
F_34 ( V_2 ) ;
V_2 -> V_57 &= ~ V_135 ;
V_2 -> V_59 &= ~ V_126 ;
V_2 -> V_123 = V_127 ;
case V_127 :
V_2 -> V_59 &= ~ V_60 ;
break;
case V_133 :
V_2 -> V_59 &= ~ V_74 ;
F_34 ( V_2 ) ;
V_2 -> V_63 . V_70 &= ~ V_56 ;
V_2 -> V_59 |= V_60 ;
V_2 -> V_57 &= ~ V_135 ;
break;
case V_128 :
V_2 -> V_63 . V_70 &= ~ V_72 ;
V_2 -> V_59 &= ~ V_60 ;
V_2 -> V_63 . V_70 |=
V_77 ;
V_2 -> V_131 = F_29 ( V_36 , ( T_2 ) ( V_136 ) ) ;
V_2 -> V_57 |= V_135 ;
break;
case V_129 :
F_36 ( V_2 ) ;
F_34 ( V_2 ) ;
V_2 -> V_59 |= V_60 ;
V_2 -> V_57 &= ~ V_135 ;
break;
case V_130 :
if ( ! F_32 ( & ( V_46 -> V_50 ) , & ( V_2 -> V_50 ) ) ) {
F_57 ( L_6
L_7 ,
V_2 -> V_3 -> V_14 -> V_137 -> V_138 , V_2 -> V_3 -> V_14 -> V_138 ) ;
return;
}
F_35 ( V_46 , V_2 ) ;
F_37 ( V_46 , V_2 ) ;
F_33 ( V_46 , V_2 ) ;
V_2 -> V_131 = F_29 ( V_36 , ( T_2 ) ( V_2 -> V_57 & V_78 ) ) ;
V_2 -> V_57 &= ~ V_135 ;
break;
default:
break;
}
}
}
static void F_58 ( struct V_2 * V_2 )
{
if ( V_2 -> V_139 && ! ( -- V_2 -> V_139 ) ) {
if ( V_2 -> V_79 && ( V_2 -> V_59 & V_132 ) ) {
F_44 ( V_2 ) ;
if ( F_46 ( V_2 ) >= 0 ) {
F_25 ( L_8 ,
V_2 -> V_29 ) ;
V_2 -> V_79 = false ;
}
}
V_2 -> V_139 =
V_38 / V_140 ;
}
}
static void F_59 ( struct V_2 * V_2 )
{
T_6 V_112 ;
V_112 = V_2 -> V_141 ;
if ( ( ( V_2 -> V_59 & V_114 ) || ! ( V_2 -> V_59 & V_132 ) || ! V_2 -> V_125 ) ||
( ! ( V_2 -> V_57 & V_77 ) && ! ( V_2 -> V_63 . V_70 & V_77 ) )
) {
V_2 -> V_141 = V_142 ;
}
else if ( V_2 -> V_143 ) {
if ( ! ( -- V_2 -> V_143 ) ) {
V_2 -> V_141 = V_144 ;
} else {
switch ( V_2 -> V_141 ) {
case V_145 :
if ( ! ( V_2 -> V_63 . V_70
& V_78 ) )
V_2 -> V_141 = V_146 ;
break;
case V_146 :
if ( ( V_2 -> V_63 . V_70 & V_78 ) ) {
V_2 -> V_143 = 0 ;
V_2 -> V_141 = V_144 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_141 ) {
case V_142 :
V_2 -> V_141 = V_145 ;
break;
case V_144 :
if ( ! ( V_2 -> V_63 . V_70
& V_78 ) )
V_2 -> V_141 = V_146 ;
else
V_2 -> V_141 = V_145 ;
break;
default:
break;
}
}
if ( V_2 -> V_141 != V_112 ) {
F_25 ( L_9 ,
V_2 -> V_29 , V_112 ,
V_2 -> V_141 ) ;
switch ( V_2 -> V_141 ) {
case V_142 :
V_2 -> V_143 = 0 ;
break;
case V_145 :
V_2 -> V_143 = F_29 ( V_42 , ( T_2 ) ( V_147 ) ) - 1 ;
break;
case V_146 :
V_2 -> V_143 = F_29 ( V_42 , ( T_2 ) ( V_148 ) ) - 1 ;
break;
case V_144 :
V_2 -> V_79 = true ;
break;
default:
break;
}
}
}
static void F_60 ( struct V_2 * V_2 )
{
struct V_8 * V_8 , * V_149 = NULL , * V_150 ;
struct V_2 * V_151 = NULL , * V_152 ;
int V_153 = 0 ;
if ( V_2 -> V_59 & V_74 )
return;
if ( V_2 -> V_8 ) {
V_150 = V_2 -> V_8 ;
for ( V_152 = V_150 -> V_80 ; V_152 ;
V_151 = V_152 ,
V_152 = V_152 -> V_81 ) {
if ( V_152 == V_2 ) {
V_150 -> V_86 -- ;
if ( ! V_151 ) {
V_150 -> V_80 =
V_2 -> V_81 ;
} else {
V_151 -> V_81 =
V_2 -> V_81 ;
}
V_2 -> V_8 = NULL ;
V_2 -> V_81 = NULL ;
V_2 -> V_154 = 0 ;
F_25 ( L_10 ,
V_2 -> V_29 ,
V_150 -> V_155 ) ;
if ( ! V_150 -> V_80 )
F_61 ( V_150 ) ;
break;
}
}
if ( ! V_152 ) {
F_62 ( L_11 ,
V_2 -> V_3 -> V_14 -> V_137 -> V_138 ,
V_2 -> V_29 ,
V_2 -> V_3 -> V_14 -> V_138 ,
V_2 -> V_8 -> V_155 ) ;
}
}
for ( V_8 = F_6 ( V_2 ) ; V_8 ;
V_8 = F_7 ( V_8 ) ) {
if ( ! V_8 -> V_80 ) {
if ( ! V_149 )
V_149 = V_8 ;
continue;
}
if ( ( ( V_8 -> V_156 == V_2 -> V_54 ) &&
! F_32 ( & ( V_8 -> V_10 ) , & ( V_2 -> V_63 . system ) ) &&
( V_8 -> V_51 == V_2 -> V_63 . V_67 ) &&
( V_8 -> V_157 == V_2 -> V_63 . V_68 )
) &&
( ( F_32 ( & ( V_2 -> V_63 . system ) , & ( V_158 ) ) &&
! V_8 -> V_159 )
)
) {
V_2 -> V_8 = V_8 ;
V_2 -> V_154 =
V_2 -> V_8 -> V_155 ;
V_2 -> V_81 = V_8 -> V_80 ;
V_2 -> V_8 -> V_86 ++ ;
V_8 -> V_80 = V_2 ;
F_25 ( L_12 ,
V_2 -> V_29 ,
V_2 -> V_8 -> V_155 ) ;
V_2 -> V_59 |= V_74 ;
V_153 = 1 ;
break;
}
}
if ( ! V_153 ) {
if ( V_149 ) {
V_2 -> V_8 = V_149 ;
V_2 -> V_154 =
V_2 -> V_8 -> V_155 ;
if ( V_2 -> V_54 & V_134 )
V_2 -> V_8 -> V_159 = false ;
else
V_2 -> V_8 -> V_159 = true ;
V_2 -> V_8 -> V_160 = V_2 -> V_161 ;
V_2 -> V_8 -> V_156 = V_2 -> V_54 ;
V_2 -> V_8 -> V_10 =
V_2 -> V_63 . system ;
V_2 -> V_8 -> V_51 =
V_2 -> V_63 . V_67 ;
V_2 -> V_8 -> V_157 = V_2 -> V_63 . V_68 ;
V_2 -> V_8 -> V_162 = 1 ;
V_2 -> V_8 -> V_163 = 1 ;
V_2 -> V_8 -> V_80 = V_2 ;
V_2 -> V_8 -> V_86 ++ ;
V_2 -> V_59 |= V_74 ;
F_25 ( L_13 ,
V_2 -> V_29 ,
V_2 -> V_8 -> V_155 ) ;
} else {
F_57 ( L_14 ,
V_2 -> V_3 -> V_14 -> V_137 -> V_138 ,
V_2 -> V_29 , V_2 -> V_3 -> V_14 -> V_138 ) ;
}
}
F_41 ( V_2 -> V_8 , F_40 ( V_2 -> V_8 ) ) ;
V_8 = F_6 ( V_2 ) ;
F_63 ( V_8 ) ;
}
static struct V_8 * F_64 ( struct V_8 * V_164 ,
struct V_8 * V_165 )
{
if ( ! V_164 )
return V_165 ;
if ( ! V_165 -> V_159 && V_164 -> V_159 )
return V_165 ;
if ( V_165 -> V_159 && ! V_164 -> V_159 )
return V_164 ;
if ( F_8 ( V_165 ) && ! F_8 ( V_164 ) )
return V_165 ;
if ( ! F_8 ( V_165 ) && F_8 ( V_164 ) )
return V_164 ;
switch ( F_17 ( V_165 -> V_80 ) ) {
case V_166 :
if ( V_165 -> V_86 > V_164 -> V_86 )
return V_165 ;
if ( V_165 -> V_86 < V_164 -> V_86 )
return V_164 ;
case V_15 :
case V_167 :
if ( F_42 ( V_165 ) > F_42 ( V_164 ) )
return V_165 ;
break;
default:
F_62 ( L_15 ,
V_165 -> V_3 -> V_14 -> V_137 -> V_138 ,
F_17 ( V_165 -> V_80 ) ) ;
break;
}
return V_164 ;
}
static int F_65 ( const struct V_8 * V_9 )
{
struct V_2 * V_2 = V_9 -> V_80 ;
if ( ! V_2 )
return 0 ;
return ( F_66 ( V_2 -> V_3 -> V_14 ) &&
F_67 ( V_2 -> V_3 -> V_14 ) ) ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_8 * V_164 , * V_168 , * V_169 ;
struct V_2 * V_2 ;
V_169 = V_9 ;
V_168 = F_43 ( V_9 ) ;
V_164 = ( V_168 && F_65 ( V_168 ) ) ? V_168 : NULL ;
do {
V_9 -> V_88 = 0 ;
if ( V_9 -> V_86 && F_65 ( V_9 ) )
V_164 = F_64 ( V_164 , V_9 ) ;
} while ( ( V_9 = F_7 ( V_9 ) ) );
if ( V_164 &&
F_17 ( V_164 -> V_80 ) == V_15 ) {
if ( V_168 && V_168 -> V_80 &&
V_168 -> V_80 -> V_125 &&
( F_8 ( V_168 ) ||
( ! F_8 ( V_168 ) && ! F_8 ( V_164 ) ) ) ) {
if ( ! ( ! V_168 -> V_156 &&
V_164 -> V_156 ) ) {
V_164 = NULL ;
V_168 -> V_88 = 1 ;
}
}
}
if ( V_164 && ( V_164 == V_168 ) ) {
V_164 = NULL ;
V_168 -> V_88 = 1 ;
}
if ( V_164 ) {
F_25 ( L_16 ,
V_164 -> V_155 , V_164 -> V_86 ,
V_164 -> V_156 ,
V_164 -> V_157 ,
V_164 -> V_159 , V_164 -> V_88 ) ;
F_25 ( L_17 ,
V_164 -> V_80 , V_164 -> V_3 ,
V_164 -> V_3 ? V_164 -> V_3 -> V_14 -> V_138 : L_18 ) ;
for ( V_9 = F_6 ( V_164 -> V_80 ) ; V_9 ;
V_9 = F_7 ( V_9 ) ) {
F_25 ( L_19 ,
V_9 -> V_155 , V_9 -> V_86 ,
V_9 -> V_156 ,
V_9 -> V_157 ,
V_9 -> V_159 , V_9 -> V_88 ) ;
}
if ( V_164 -> V_159 ) {
F_62 ( L_20 ,
V_164 -> V_3 ? V_164 -> V_3 -> V_14 -> V_137 -> V_138 : L_18 ) ;
}
V_164 -> V_88 = 1 ;
F_25 ( L_21 ,
V_164 -> V_155 ) ;
F_25 ( L_19 ,
V_164 -> V_155 , V_164 -> V_86 ,
V_164 -> V_156 ,
V_164 -> V_157 ,
V_164 -> V_159 , V_164 -> V_88 ) ;
if ( V_168 ) {
for ( V_2 = V_168 -> V_80 ; V_2 ;
V_2 = V_2 -> V_81 ) {
F_10 ( V_2 ) ;
}
}
}
V_168 = F_43 ( V_169 ) ;
if ( V_168 ) {
if ( ! F_8 ( V_168 ) ) {
for ( V_2 = V_168 -> V_80 ; V_2 ;
V_2 = V_2 -> V_81 ) {
F_12 ( V_2 ) ;
}
}
}
if ( V_169 -> V_3 ) {
struct V_1 * V_4 ;
V_4 = F_2 ( V_169 -> V_3 ) ;
if ( V_4 )
F_68 ( V_4 ) ;
}
}
static void F_61 ( struct V_8 * V_8 )
{
if ( V_8 ) {
V_8 -> V_159 = false ;
V_8 -> V_160 = 0 ;
V_8 -> V_156 = 0 ;
V_8 -> V_10 = V_158 ;
V_8 -> V_51 = 0 ;
V_8 -> V_157 = 0 ;
V_8 -> V_162 = 0 ;
V_8 -> V_163 = 0 ;
V_8 -> V_80 = NULL ;
V_8 -> V_88 = 0 ;
V_8 -> V_86 = 0 ;
F_25 ( L_22 ,
V_8 -> V_155 ) ;
}
}
static void F_69 ( struct V_8 * V_8 )
{
if ( V_8 ) {
F_61 ( V_8 ) ;
V_8 -> V_170 = V_158 ;
V_8 -> V_155 = 0 ;
V_8 -> V_3 = NULL ;
}
}
static void F_70 ( struct V_2 * V_2 , int V_171 )
{
static const struct V_61 V_172 = {
. V_67 = 0xffff ,
. V_68 = 1 ,
. V_64 = 1 ,
. V_66 = 0xff ,
. V_70 = 1 ,
} ;
static const struct V_46 V_46 = {
. V_173 = 0x01 ,
. V_174 = 0x01 ,
. V_175 = 0x01 ,
. V_176 = 0x14 ,
. V_177 = 0x02 ,
. V_178 = 0x14 ,
. V_179 = 0x03 ,
. V_180 = 0x10 ,
. V_181 = F_45 ( V_182 ) ,
} ;
if ( V_2 ) {
V_2 -> V_29 = 1 ;
V_2 -> V_49 = 0xff ;
V_2 -> V_50 = V_158 ;
V_2 -> V_52 = 0xffff ;
V_2 -> V_154 = 0 ;
V_2 -> V_79 = false ;
V_2 -> V_161 = 1 ;
V_2 -> V_54 = 1 ;
V_2 -> V_183 = V_56 | V_77 ;
V_2 -> V_57 = V_56 | V_77 ;
if ( V_171 )
V_2 -> V_57 |= V_78 ;
memcpy ( & V_2 -> V_73 , & V_172 , sizeof( V_172 ) ) ;
memcpy ( & V_2 -> V_63 , & V_172 , sizeof( V_172 ) ) ;
V_2 -> V_125 = true ;
V_2 -> V_59 = 0x3 ;
V_2 -> V_123 = 0 ;
V_2 -> V_131 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_113 = 0 ;
V_2 -> V_118 = 0 ;
V_2 -> V_184 = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_8 = NULL ;
V_2 -> V_81 = NULL ;
V_2 -> V_185 = 0 ;
memcpy ( & V_2 -> V_46 , & V_46 , sizeof( V_46 ) ) ;
}
}
static void F_55 ( struct V_2 * V_2 )
{
if ( V_2 -> V_8 -> V_88 ) {
F_25 ( L_23 ,
V_2 -> V_29 ,
V_2 -> V_8 -> V_155 ) ;
F_12 ( V_2 ) ;
}
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_8 && F_32 ( & ( V_2 -> V_8 -> V_10 ) , & ( V_158 ) ) ) {
F_25 ( L_24 ,
V_2 -> V_29 ,
V_2 -> V_8 -> V_155 ) ;
F_10 ( V_2 ) ;
}
}
static void F_71 ( struct V_108 * V_186 ,
struct V_2 * V_2 )
{
struct V_108 V_109 ;
memcpy ( & V_109 , V_186 , sizeof( struct V_108 ) ) ;
V_109 . V_187 = V_188 ;
if ( F_51 ( V_2 , & V_109 ) >= 0 ) {
F_25 ( L_25 ,
V_2 -> V_29 ) ;
}
}
static void F_72 ( struct V_108 * V_109 ,
struct V_2 * V_2 )
{
V_109 = NULL ;
V_2 = NULL ;
}
void F_73 ( struct V_1 * V_4 , int V_189 )
{
F_19 ( V_4 ) . V_18 = V_189 ;
}
void F_74 ( struct V_1 * V_4 , T_2 V_190 )
{
if ( F_32 ( & ( F_19 ( V_4 ) . system . V_191 ) ,
V_4 -> V_14 -> V_192 ) ) {
V_155 = 0 ;
F_19 ( V_4 ) . system . V_193 = 0xFFFF ;
F_19 ( V_4 ) . system . V_191 = * ( (struct V_194 * ) V_4 -> V_14 -> V_192 ) ;
V_38 = V_190 ;
F_73 ( V_4 ,
V_195 *
V_38 ) ;
}
}
int F_75 ( struct V_3 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_8 * V_8 ;
if ( V_4 == NULL ) {
F_57 ( L_26 ,
V_3 -> V_14 -> V_137 -> V_138 , V_3 -> V_14 -> V_138 ) ;
return - 1 ;
}
if ( F_4 ( V_3 ) . V_2 . V_3 != V_3 ) {
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
F_70 ( V_2 , V_4 -> V_16 . V_171 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_29 = F_4 ( V_3 ) . V_196 ;
V_2 -> V_161 = 0 ;
V_2 -> V_161 |= F_26 ( V_2 ) ;
V_2 -> V_161 |= ( F_24 ( V_2 ) << 1 ) ;
V_2 -> V_54 = V_2 -> V_161 ;
if ( ! ( V_2 -> V_54 & V_134 ) )
V_2 -> V_59 &= ~ V_132 ;
V_2 -> V_50 = F_19 ( V_4 ) . system . V_191 ;
V_2 -> V_139 = V_38 / V_140 ;
V_2 -> V_8 = NULL ;
V_2 -> V_81 = NULL ;
F_10 ( V_2 ) ;
F_27 ( V_2 ) ;
V_8 = & ( F_4 ( V_3 ) . V_8 ) ;
F_69 ( V_8 ) ;
V_8 -> V_170 = * ( (struct V_194 * ) V_4 -> V_14 -> V_192 ) ;
V_8 -> V_155 = ( ++ V_155 ) ;
V_8 -> V_3 = V_3 ;
V_8 -> V_88 = 0 ;
V_8 -> V_86 = 0 ;
}
return 0 ;
}
void F_76 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_197 , * V_198 ;
struct V_8 * V_8 , * V_199 , * V_150 ;
int V_200 = 0 ;
V_8 = & ( F_4 ( V_3 ) . V_8 ) ;
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_27 ,
V_3 -> V_14 -> V_137 -> V_138 , V_3 -> V_14 -> V_138 ) ;
return;
}
F_25 ( L_28 ,
V_8 -> V_155 ) ;
V_2 -> V_57 &= ~ V_56 ;
F_44 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( V_8 -> V_80 ) {
if ( ( V_8 -> V_80 != V_2 ) || ( V_8 -> V_80 -> V_81 ) ) {
V_199 = F_6 ( V_2 ) ;
for (; V_199 ; V_199 = F_7 ( V_199 ) ) {
if ( ! V_199 -> V_80
|| ( ( V_199 -> V_80 == V_2 )
&& ! V_199 -> V_80 -> V_81 ) )
break;
}
if ( ( V_199 ) && ( ( ! V_199 -> V_80 ) || ( ( V_199 -> V_80 == V_2 ) && ! V_199 -> V_80 -> V_81 ) ) ) {
F_25 ( L_29 ,
V_8 -> V_155 ,
V_199 -> V_155 ) ;
if ( ( V_199 -> V_80 == V_2 ) && V_199 -> V_88 ) {
F_77 ( L_30 ,
V_8 -> V_3 -> V_14 -> V_137 -> V_138 ) ;
V_200 = 1 ;
}
V_199 -> V_159 = V_8 -> V_159 ;
V_199 -> V_160 = V_8 -> V_160 ;
V_199 -> V_156 = V_8 -> V_156 ;
V_199 -> V_10 = V_8 -> V_10 ;
V_199 -> V_51 = V_8 -> V_51 ;
V_199 -> V_157 = V_8 -> V_157 ;
V_199 -> V_162 = V_8 -> V_162 ;
V_199 -> V_163 = V_8 -> V_163 ;
V_199 -> V_80 = V_8 -> V_80 ;
V_199 -> V_88 = V_8 -> V_88 ;
V_199 -> V_86 = V_8 -> V_86 ;
for ( V_198 = V_8 -> V_80 ; V_198 ;
V_198 = V_198 -> V_81 ) {
V_198 -> V_8 = V_199 ;
V_198 -> V_154 = V_199 -> V_155 ;
}
F_61 ( V_8 ) ;
if ( V_200 )
F_63 ( F_6 ( V_2 ) ) ;
} else {
F_62 ( L_31 ,
V_3 -> V_14 -> V_137 -> V_138 ) ;
}
} else {
V_200 = V_8 -> V_88 ;
F_61 ( V_8 ) ;
if ( V_200 ) {
F_77 ( L_30 ,
V_3 -> V_14 -> V_137 -> V_138 ) ;
F_63 ( F_6 ( V_2 ) ) ;
}
}
}
F_25 ( L_32 , V_2 -> V_29 ) ;
V_150 = F_6 ( V_2 ) ;
for (; V_150 ; V_150 = F_7 ( V_150 ) ) {
V_197 = NULL ;
for ( V_198 = V_150 -> V_80 ; V_198 ;
V_197 = V_198 ,
V_198 = V_198 -> V_81 ) {
if ( V_198 == V_2 ) {
if ( V_197 )
V_197 -> V_81 = V_198 -> V_81 ;
else
V_150 -> V_80 = V_198 -> V_81 ;
V_150 -> V_86 -- ;
if ( V_150 -> V_86 == 0 ) {
V_200 = V_150 -> V_88 ;
F_61 ( V_150 ) ;
if ( V_200 ) {
F_77 ( L_30 ,
V_3 -> V_14 -> V_137 -> V_138 ) ;
F_63 ( F_6 ( V_2 ) ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
}
void F_78 ( struct V_201 * V_202 )
{
struct V_1 * V_4 = F_79 ( V_202 , struct V_1 ,
V_203 . V_202 ) ;
struct V_2 * V_2 ;
struct V_8 * V_8 ;
F_80 ( & V_4 -> V_204 ) ;
if ( V_4 -> V_5 == 0 )
goto V_205;
if ( F_19 ( V_4 ) . V_18 && ! ( -- F_19 ( V_4 ) . V_18 ) ) {
if ( ( V_2 = F_3 ( V_4 ) ) ) {
if ( ! V_2 -> V_3 ) {
F_62 ( L_33 ,
V_4 -> V_14 -> V_138 ) ;
goto V_205;
}
V_8 = F_6 ( V_2 ) ;
F_63 ( V_8 ) ;
}
F_68 ( V_4 ) ;
}
for ( V_2 = F_3 ( V_4 ) ; V_2 ; V_2 = F_5 ( V_2 ) ) {
if ( ! V_2 -> V_3 ) {
F_62 ( L_34 ,
V_4 -> V_14 -> V_138 ) ;
goto V_205;
}
F_20 ( V_2 ) ;
F_56 ( NULL , V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_53 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_59 & V_114 )
V_2 -> V_59 &= ~ V_114 ;
F_22 ( V_2 ) ;
}
V_205:
F_81 ( V_4 -> V_206 , & V_4 -> V_203 , V_207 ) ;
F_82 ( & V_4 -> V_204 ) ;
}
static int F_83 ( struct V_46 * V_46 , struct V_3 * V_3 , T_2 V_92 )
{
struct V_2 * V_2 ;
int V_208 = V_209 ;
if ( V_92 >= sizeof( struct V_46 ) ) {
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_35 ,
V_3 -> V_14 -> V_138 , V_3 -> V_14 -> V_137 -> V_138 ) ;
return V_208 ;
}
switch ( V_46 -> V_173 ) {
case V_210 :
V_208 = V_211 ;
F_25 ( L_36 ,
V_2 -> V_29 ) ;
F_20 ( V_2 ) ;
F_56 ( V_46 , V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_212 :
V_208 = V_211 ;
switch ( ( (struct V_108 * ) V_46 ) -> V_187 ) {
case V_213 :
F_25 ( L_37 ,
V_2 -> V_29 ) ;
F_71 ( (struct V_108 * ) V_46 , V_2 ) ;
break;
case V_188 :
F_25 ( L_38 ,
V_2 -> V_29 ) ;
F_72 ( (struct V_108 * ) V_46 , V_2 ) ;
break;
default:
F_25 ( L_39 ,
V_2 -> V_29 ) ;
}
}
}
return V_208 ;
}
void F_84 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_40 ,
V_3 -> V_14 -> V_137 -> V_138 , V_3 -> V_14 -> V_138 ) ;
return;
}
V_2 -> V_161 &= ~ V_214 ;
V_2 -> V_54 = V_2 -> V_161 |=
( F_24 ( V_2 ) << 1 ) ;
F_25 ( L_41 , V_2 -> V_29 ) ;
V_2 -> V_59 |= V_114 ;
}
void F_85 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_42 ,
V_3 -> V_14 -> V_137 -> V_138 , V_3 -> V_14 -> V_138 ) ;
return;
}
V_2 -> V_161 &= ~ V_134 ;
V_2 -> V_54 = V_2 -> V_161 |=
F_26 ( V_2 ) ;
F_25 ( L_43 , V_2 -> V_29 ) ;
V_2 -> V_59 |= V_114 ;
}
void F_86 ( struct V_3 * V_3 , char V_12 )
{
struct V_2 * V_2 ;
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_44 ,
V_3 -> V_14 -> V_137 -> V_138 , V_3 -> V_14 -> V_138 ) ;
return;
}
if ( V_12 == V_13 ) {
V_2 -> V_125 = true ;
V_2 -> V_161 &= ~ V_134 ;
V_2 -> V_54 = V_2 -> V_161 |=
F_26 ( V_2 ) ;
V_2 -> V_161 &= ~ V_214 ;
V_2 -> V_54 = V_2 -> V_161 |=
( F_24 ( V_2 ) << 1 ) ;
} else {
V_2 -> V_125 = false ;
V_2 -> V_161 &= ~ V_134 ;
V_2 -> V_54 = ( V_2 -> V_161 &=
~ V_214 ) ;
}
V_2 -> V_59 |= V_114 ;
}
int F_68 ( struct V_1 * V_4 )
{
struct V_8 * V_168 ;
V_168 = F_43 ( & ( F_4 ( V_4 -> V_6 ) . V_8 ) ) ;
if ( V_168 ) {
if ( V_168 -> V_86 < V_4 -> V_16 . V_215 ) {
if ( F_67 ( V_4 -> V_14 ) ) {
F_87 ( V_4 -> V_14 ) ;
return 1 ;
}
} else if ( ! F_67 ( V_4 -> V_14 ) ) {
F_88 ( V_4 -> V_14 ) ;
return 1 ;
}
return 0 ;
}
if ( F_67 ( V_4 -> V_14 ) ) {
F_87 ( V_4 -> V_14 ) ;
return 1 ;
}
return 0 ;
}
int F_89 ( struct V_1 * V_4 , struct V_216 * V_216 )
{
struct V_8 * V_8 = NULL ;
struct V_2 * V_2 ;
for ( V_2 = F_3 ( V_4 ) ; V_2 ; V_2 = F_5 ( V_2 ) ) {
if ( V_2 -> V_8 && V_2 -> V_8 -> V_88 ) {
V_8 = V_2 -> V_8 ;
break;
}
}
if ( V_8 ) {
V_216 -> V_217 = V_8 -> V_155 ;
V_216 -> V_218 = V_8 -> V_86 ;
V_216 -> V_69 = V_8 -> V_156 ;
V_216 -> V_53 = V_8 -> V_157 ;
memcpy ( V_216 -> V_10 , V_8 -> V_10 . V_11 , V_104 ) ;
return 0 ;
}
return - 1 ;
}
int F_90 ( struct V_89 * V_90 , struct V_219 * V_14 )
{
struct V_3 * V_3 , * V_220 ;
struct V_1 * V_4 = F_91 ( V_14 ) ;
int V_221 ;
int V_222 ;
int V_223 ;
int V_224 ;
struct V_216 V_216 ;
int V_225 = 1 ;
if ( F_89 ( V_4 , & V_216 ) ) {
F_25 ( L_45 ,
V_14 -> V_138 ) ;
goto V_226;
}
V_222 = V_216 . V_218 ;
V_223 = V_216 . V_217 ;
if ( V_222 == 0 ) {
F_25 ( L_46 , V_14 -> V_138 ) ;
goto V_226;
}
V_221 = V_4 -> V_227 ( V_90 , V_222 ) ;
F_92 (bond, slave, i) {
struct V_8 * V_9 = F_4 ( V_3 ) . V_2 . V_8 ;
if ( V_9 && ( V_9 -> V_155 == V_223 ) ) {
V_221 -- ;
if ( V_221 < 0 )
break;
}
}
if ( V_221 >= 0 ) {
F_57 ( L_47 ,
V_14 -> V_138 , V_223 ) ;
goto V_226;
}
V_220 = V_3 ;
F_93 (bond, slave, i, start_at) {
int V_228 = 0 ;
struct V_8 * V_9 = F_4 ( V_3 ) . V_2 . V_8 ;
if ( V_9 )
V_228 = V_9 -> V_155 ;
if ( F_94 ( V_3 ) && V_9 && ( V_228 == V_223 ) ) {
V_225 = F_95 ( V_4 , V_90 , V_3 -> V_14 ) ;
break;
}
}
V_226:
if ( V_225 ) {
F_96 ( V_90 ) ;
}
return V_229 ;
}
int F_97 ( const struct V_89 * V_90 , struct V_1 * V_4 ,
struct V_3 * V_3 )
{
int V_208 = V_209 ;
struct V_46 * V_46 , V_230 ;
if ( V_90 -> V_97 != V_98 )
return V_208 ;
V_46 = F_98 ( V_90 , 0 , sizeof( V_230 ) , & V_230 ) ;
if ( ! V_46 )
return V_208 ;
F_80 ( & V_4 -> V_204 ) ;
V_208 = F_83 ( V_46 , V_3 , V_90 -> V_231 ) ;
F_82 ( & V_4 -> V_204 ) ;
return V_208 ;
}
void F_99 ( struct V_1 * V_4 )
{
int V_224 ;
struct V_3 * V_3 ;
struct V_2 * V_2 = NULL ;
int V_171 ;
F_80 ( & V_4 -> V_204 ) ;
V_171 = V_4 -> V_16 . V_171 ;
F_92 (bond, slave, i) {
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
F_20 ( V_2 ) ;
if ( V_171 )
V_2 -> V_57 |= V_78 ;
else
V_2 -> V_57 &= ~ V_78 ;
F_22 ( V_2 ) ;
}
F_82 ( & V_4 -> V_204 ) ;
}
