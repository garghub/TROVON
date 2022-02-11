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
return F_18 ( V_4 ) . V_16 ;
}
static inline int F_19 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
if ( V_4 == NULL )
return 0 ;
return F_18 ( V_4 ) . V_17 ? 1 : 0 ;
}
static inline void F_20 ( struct V_2 * V_2 )
{
F_21 ( & ( F_4 ( V_2 -> V_3 ) . V_18 ) ) ;
}
static inline void F_22 ( struct V_2 * V_2 )
{
F_23 ( & ( F_4 ( V_2 -> V_3 ) . V_18 ) ) ;
}
static T_2 F_24 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_2 V_19 ;
if ( V_3 -> V_12 != V_13 )
V_19 = 0 ;
else {
switch ( V_3 -> V_19 ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
V_19 = V_25 ;
break;
case V_26 :
V_19 = V_27 ;
break;
default:
V_19 = 0 ;
break;
}
}
F_25 ( L_1 ,
V_2 -> V_28 , V_19 ) ;
return V_19 ;
}
static T_3 F_26 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_29 ;
if ( V_3 -> V_12 != V_13 )
V_29 = 0x0 ;
else {
switch ( V_3 -> V_30 ) {
case V_31 :
V_29 = 0x1 ;
F_25 ( L_2 ,
V_2 -> V_28 ) ;
break;
case V_32 :
default:
V_29 = 0x0 ;
F_25 ( L_3 ,
V_2 -> V_28 ) ;
break;
}
}
return V_29 ;
}
static inline void F_27 ( struct V_2 * V_2 )
{
F_28 ( & ( F_4 ( V_2 -> V_3 ) . V_18 ) ) ;
}
static T_2 F_29 ( T_2 V_33 , T_2 V_34 )
{
T_2 V_29 = 0 ;
switch ( V_33 ) {
case V_35 :
if ( V_34 )
V_29 = ( V_36 * V_37 ) ;
else
V_29 = ( V_38 * V_37 ) ;
break;
case V_39 :
V_29 = ( V_40 * V_37 ) ;
break;
case V_41 :
V_29 = ( V_34 * V_37 ) ;
break;
case V_42 :
V_29 = ( V_40 * V_37 ) ;
break;
case V_43 :
V_29 = ( V_44 * V_37 ) ;
break;
}
return V_29 ;
}
static void F_30 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
if ( ( ( F_31 ( V_45 -> V_46 ) == V_2 -> V_28 ) &&
( F_31 ( V_45 -> V_47 ) == V_2 -> V_48 ) &&
! F_32 ( & ( V_45 -> V_10 ) , & ( V_2 -> V_49 ) ) &&
( F_31 ( V_45 -> V_50 ) == V_2 -> V_51 ) &&
( F_31 ( V_45 -> V_52 ) == V_2 -> V_53 ) &&
( ( V_45 -> V_54 & V_55 ) == ( V_2 -> V_56 & V_55 ) ) ) ||
( ( V_45 -> V_57 & V_55 ) == 0 )
) {
V_2 -> V_58 |= V_59 ;
} else {
V_2 -> V_58 &= ~ V_59 ;
}
}
static void F_33 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
if ( V_45 && V_2 ) {
struct V_60 * V_61 = & V_2 -> V_62 ;
F_30 ( V_45 , V_2 ) ;
V_61 -> V_63 = F_31 ( V_45 -> V_64 ) ;
V_61 -> V_65 = F_31 ( V_45 -> V_48 ) ;
V_61 -> system = V_45 -> V_49 ;
V_61 -> V_66 = F_31 ( V_45 -> V_51 ) ;
V_61 -> V_67 = F_31 ( V_45 -> V_68 ) ;
V_61 -> V_69 = V_45 -> V_57 ;
V_2 -> V_56 &= ~ V_70 ;
if ( ( V_2 -> V_58 & V_59 )
&& ( V_45 -> V_57 & V_71 ) )
V_61 -> V_69 |= V_71 ;
else
V_61 -> V_69 &= ~ V_71 ;
}
}
static void F_34 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_62 , & V_2 -> V_72 ,
sizeof( struct V_60 ) ) ;
V_2 -> V_56 |= V_70 ;
}
}
static void F_35 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
if ( V_45 && V_2 ) {
const struct V_60 * V_61 = & V_2 -> V_62 ;
if ( F_31 ( V_45 -> V_64 ) != V_61 -> V_63 ||
F_31 ( V_45 -> V_48 ) != V_61 -> V_65 ||
F_32 ( & V_45 -> V_49 , & V_61 -> system ) ||
F_31 ( V_45 -> V_51 ) != V_61 -> V_66 ||
F_31 ( V_45 -> V_68 ) != V_61 -> V_67 ||
( V_45 -> V_57 & V_55 ) != ( V_61 -> V_69 & V_55 ) ) {
V_2 -> V_58 &= ~ V_73 ;
}
}
}
static void F_36 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_60 * V_74 = & V_2 -> V_72 ;
const struct V_60 * V_75 = & V_2 -> V_62 ;
if ( V_74 -> V_63 != V_75 -> V_63 ||
V_74 -> V_65 != V_75 -> V_65 ||
F_32 ( & V_74 -> system , & V_75 -> system ) ||
V_74 -> V_66 != V_75 -> V_66 ||
V_74 -> V_67 != V_75 -> V_67 ||
( V_74 -> V_69 & V_55 )
!= ( V_75 -> V_69 & V_55 ) ) {
V_2 -> V_58 &= ~ V_73 ;
}
}
}
static void F_37 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
if ( V_45 && V_2 ) {
if ( ( F_31 ( V_45 -> V_46 ) != V_2 -> V_28 ) ||
( F_31 ( V_45 -> V_47 ) != V_2 -> V_48 ) ||
F_32 ( & ( V_45 -> V_10 ) , & ( V_2 -> V_49 ) ) ||
( F_31 ( V_45 -> V_50 ) != V_2 -> V_51 ) ||
( F_31 ( V_45 -> V_52 ) != V_2 -> V_53 ) ||
( ( V_45 -> V_54 & V_76 ) != ( V_2 -> V_56 & V_76 ) ) ||
( ( V_45 -> V_54 & V_77 ) != ( V_2 -> V_56 & V_77 ) ) ||
( ( V_45 -> V_54 & V_71 ) != ( V_2 -> V_56 & V_71 ) ) ||
( ( V_45 -> V_54 & V_55 ) != ( V_2 -> V_56 & V_55 ) )
) {
V_2 -> V_78 = true ;
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
int V_29 = 1 ;
if ( V_8 ) {
for ( V_2 = V_8 -> V_79 ;
V_2 ;
V_2 = V_2 -> V_80 ) {
if ( ! ( V_2 -> V_58 & V_81 ) ) {
V_29 = 0 ;
break;
}
}
}
return V_29 ;
}
static void F_41 ( struct V_8 * V_8 , int V_82 )
{
struct V_2 * V_2 ;
for ( V_2 = V_8 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
if ( V_82 )
V_2 -> V_58 |= V_83 ;
else
V_2 -> V_58 &= ~ V_83 ;
}
}
static T_1 F_42 ( struct V_8 * V_8 )
{
T_1 V_84 = 0 ;
if ( V_8 -> V_85 ) {
switch ( F_24 ( V_8 -> V_79 ) ) {
case V_86 :
V_84 = V_8 -> V_85 ;
break;
case V_21 :
V_84 = V_8 -> V_85 * 10 ;
break;
case V_23 :
V_84 = V_8 -> V_85 * 100 ;
break;
case V_25 :
V_84 = V_8 -> V_85 * 1000 ;
break;
case V_27 :
V_84 = V_8 -> V_85 * 10000 ;
break;
default:
V_84 = 0 ;
}
}
return V_84 ;
}
static struct V_8 * F_43 ( struct V_8 * V_8 )
{
struct V_8 * V_29 = NULL ;
for (; V_8 ; V_8 = F_7 ( V_8 ) ) {
if ( V_8 -> V_87 ) {
V_29 = V_8 ;
break;
}
}
return V_29 ;
}
static inline void F_44 ( struct V_2 * V_2 )
{
struct V_45 * V_45 = & V_2 -> V_45 ;
const struct V_60 * V_61 = & V_2 -> V_62 ;
V_45 -> V_51 = F_45 ( V_2 -> V_51 ) ;
V_45 -> V_49 = V_2 -> V_49 ;
V_45 -> V_68 = F_45 ( V_2 -> V_53 ) ;
V_45 -> V_48 = F_45 ( V_2 -> V_48 ) ;
V_45 -> V_64 = F_45 ( V_2 -> V_28 ) ;
V_45 -> V_57 = V_2 -> V_56 ;
V_45 -> V_50 = F_45 ( V_61 -> V_66 ) ;
V_45 -> V_10 = V_61 -> system ;
V_45 -> V_52 = F_45 ( V_61 -> V_67 ) ;
V_45 -> V_47 = F_45 ( V_61 -> V_65 ) ;
V_45 -> V_46 = F_45 ( V_61 -> V_63 ) ;
V_45 -> V_54 = V_61 -> V_69 ;
}
static int F_46 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_88 * V_89 ;
struct V_90 * V_90 ;
int V_91 = sizeof( struct V_90 ) ;
V_89 = F_47 ( V_91 ) ;
if ( ! V_89 )
return - V_92 ;
V_89 -> V_14 = V_3 -> V_14 ;
F_48 ( V_89 ) ;
V_89 -> V_93 = V_89 -> V_94 + V_95 ;
V_89 -> V_96 = V_97 ;
V_89 -> V_98 = V_99 ;
V_90 = (struct V_90 * ) F_49 ( V_89 , V_91 ) ;
memcpy ( V_90 -> V_100 . V_101 , V_102 , V_103 ) ;
memcpy ( V_90 -> V_100 . V_104 , V_3 -> V_105 , V_103 ) ;
V_90 -> V_100 . V_106 = V_97 ;
V_90 -> V_45 = V_2 -> V_45 ;
F_50 ( V_89 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_2 , struct V_107 * V_108 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_88 * V_89 ;
struct V_109 * V_110 ;
int V_91 = sizeof( struct V_109 ) ;
V_89 = F_47 ( V_91 + 16 ) ;
if ( ! V_89 )
return - V_92 ;
F_52 ( V_89 , 16 ) ;
V_89 -> V_14 = V_3 -> V_14 ;
F_48 ( V_89 ) ;
V_89 -> V_93 = V_89 -> V_94 + V_95 ;
V_89 -> V_96 = V_97 ;
V_110 = (struct V_109 * ) F_49 ( V_89 , V_91 ) ;
memcpy ( V_110 -> V_100 . V_101 , V_102 , V_103 ) ;
memcpy ( V_110 -> V_100 . V_104 , V_3 -> V_105 , V_103 ) ;
V_110 -> V_100 . V_106 = V_97 ;
V_110 -> V_108 = * V_108 ;
F_50 ( V_89 ) ;
return 0 ;
}
static void F_53 ( struct V_2 * V_2 )
{
T_4 V_111 ;
V_111 = V_2 -> V_112 ;
if ( V_2 -> V_58 & V_113 ) {
V_2 -> V_112 = V_114 ;
} else {
switch ( V_2 -> V_112 ) {
case V_114 :
if ( ( V_2 -> V_58 & V_73 )
|| ( V_2 -> V_58 & V_115 ) )
V_2 -> V_112 = V_116 ;
break;
case V_116 :
if ( ! ( V_2 -> V_58 & V_73 ) ) {
V_2 -> V_58 &= ~ V_81 ;
F_41 ( V_2 -> V_8 , F_40 ( V_2 -> V_8 ) ) ;
V_2 -> V_112 = V_114 ;
break;
}
if ( V_2 -> V_117
&& ! ( -- V_2 -> V_117 ) )
V_2 -> V_58 |= V_81 ;
F_41 ( V_2 -> V_8 , F_40 ( V_2 -> V_8 ) ) ;
if ( ( V_2 -> V_58 & V_83 )
&& ! V_2 -> V_117 )
V_2 -> V_112 = V_118 ;
break;
case V_118 :
if ( ( V_2 -> V_58 & V_73 ) && ( V_2 -> V_62 . V_69 & V_71 ) && ! F_19 ( V_2 ) ) {
V_2 -> V_112 = V_119 ;
} else if ( ! ( V_2 -> V_58 & V_73 ) || ( V_2 -> V_58 & V_115 ) ) {
V_2 -> V_58 &= ~ V_81 ;
F_41 ( V_2 -> V_8 , F_40 ( V_2 -> V_8 ) ) ;
V_2 -> V_112 = V_114 ;
}
break;
case V_119 :
if ( ! ( V_2 -> V_58 & V_73 ) || ( V_2 -> V_58 & V_115 ) ||
! ( V_2 -> V_62 . V_69 & V_71 )
) {
V_2 -> V_112 = V_118 ;
} else {
if ( V_2 -> V_8 &&
V_2 -> V_8 -> V_87 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_112 != V_111 ) {
F_25 ( L_4 ,
V_2 -> V_28 , V_111 ,
V_2 -> V_112 ) ;
switch ( V_2 -> V_112 ) {
case V_114 :
F_39 ( V_2 ) ;
V_2 -> V_56 &= ~ V_71 ;
F_54 ( V_2 ) ;
V_2 -> V_56 &= ~ V_120 ;
V_2 -> V_56 &= ~ V_121 ;
V_2 -> V_78 = true ;
break;
case V_116 :
V_2 -> V_117 = F_29 ( V_43 , 0 ) ;
break;
case V_118 :
F_38 ( V_2 ) ;
V_2 -> V_56 |= V_71 ;
V_2 -> V_56 &= ~ V_120 ;
V_2 -> V_56 &= ~ V_121 ;
F_54 ( V_2 ) ;
V_2 -> V_78 = true ;
break;
case V_119 :
V_2 -> V_56 |= V_120 ;
V_2 -> V_56 |= V_121 ;
F_55 ( V_2 ) ;
V_2 -> V_78 = true ;
break;
default:
break;
}
}
}
static void F_56 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
T_5 V_111 ;
V_111 = V_2 -> V_122 ;
if ( V_2 -> V_58 & V_113 )
V_2 -> V_122 = V_123 ;
else if ( ! ( V_2 -> V_58 & V_113 )
&& ! V_2 -> V_124 && ! ( V_2 -> V_58 & V_125 ) )
V_2 -> V_122 = V_126 ;
else if ( V_45 && ( ( V_2 -> V_122 == V_127 ) || ( V_2 -> V_122 == V_128 ) || ( V_2 -> V_122 == V_129 ) ) ) {
V_2 -> V_130 = 0 ;
V_2 -> V_122 = V_129 ;
} else {
if ( V_2 -> V_130 && ! ( -- V_2 -> V_130 ) ) {
switch ( V_2 -> V_122 ) {
case V_127 :
V_2 -> V_122 = V_128 ;
break;
case V_129 :
V_2 -> V_122 = V_127 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_122 ) {
case V_126 :
if ( V_2 -> V_58 & V_125 )
V_2 -> V_122 = V_123 ;
else if ( V_2 -> V_124
&& ( V_2 -> V_58
& V_131 ) )
V_2 -> V_122 = V_127 ;
else if ( V_2 -> V_124
&& ( ( V_2 -> V_58
& V_131 ) == 0 ) )
V_2 -> V_122 = V_132 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_122 != V_111 ) || ( V_45 ) ) {
F_25 ( L_5 ,
V_2 -> V_28 , V_111 ,
V_2 -> V_122 ) ;
switch ( V_2 -> V_122 ) {
case V_123 :
if ( ! ( V_2 -> V_53 & V_133 ) )
V_2 -> V_58 &= ~ V_131 ;
else
V_2 -> V_58 |= V_131 ;
V_2 -> V_58 &= ~ V_73 ;
F_34 ( V_2 ) ;
V_2 -> V_56 &= ~ V_134 ;
V_2 -> V_58 &= ~ V_125 ;
V_2 -> V_122 = V_126 ;
case V_126 :
V_2 -> V_58 &= ~ V_59 ;
break;
case V_132 :
V_2 -> V_58 &= ~ V_73 ;
F_34 ( V_2 ) ;
V_2 -> V_62 . V_69 &= ~ V_55 ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_56 &= ~ V_134 ;
break;
case V_127 :
V_2 -> V_62 . V_69 &= ~ V_71 ;
V_2 -> V_58 &= ~ V_59 ;
V_2 -> V_62 . V_69 |=
V_76 ;
V_2 -> V_130 = F_29 ( V_35 , ( T_2 ) ( V_135 ) ) ;
V_2 -> V_56 |= V_134 ;
break;
case V_128 :
F_36 ( V_2 ) ;
F_34 ( V_2 ) ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_56 &= ~ V_134 ;
break;
case V_129 :
if ( ! F_32 ( & ( V_45 -> V_49 ) , & ( V_2 -> V_49 ) ) ) {
F_57 ( L_6
L_7 ,
V_2 -> V_3 -> V_14 -> V_136 -> V_137 , V_2 -> V_3 -> V_14 -> V_137 ) ;
return;
}
F_35 ( V_45 , V_2 ) ;
F_37 ( V_45 , V_2 ) ;
F_33 ( V_45 , V_2 ) ;
V_2 -> V_130 = F_29 ( V_35 , ( T_2 ) ( V_2 -> V_56 & V_77 ) ) ;
V_2 -> V_56 &= ~ V_134 ;
if ( V_2 -> V_8
&& V_2 -> V_8 -> V_87
&& ! F_15 ( V_2 ) )
F_12 ( V_2 ) ;
break;
default:
break;
}
}
}
static void F_58 ( struct V_2 * V_2 )
{
if ( V_2 -> V_138 && ! ( -- V_2 -> V_138 ) ) {
if ( V_2 -> V_78 && ( V_2 -> V_58 & V_131 ) ) {
F_44 ( V_2 ) ;
if ( F_46 ( V_2 ) >= 0 ) {
F_25 ( L_8 ,
V_2 -> V_28 ) ;
V_2 -> V_78 = false ;
}
}
V_2 -> V_138 =
V_37 / V_139 ;
}
}
static void F_59 ( struct V_2 * V_2 )
{
T_6 V_111 ;
V_111 = V_2 -> V_140 ;
if ( ( ( V_2 -> V_58 & V_113 ) || ! ( V_2 -> V_58 & V_131 ) || ! V_2 -> V_124 ) ||
( ! ( V_2 -> V_56 & V_76 ) && ! ( V_2 -> V_62 . V_69 & V_76 ) )
) {
V_2 -> V_140 = V_141 ;
}
else if ( V_2 -> V_142 ) {
if ( ! ( -- V_2 -> V_142 ) ) {
V_2 -> V_140 = V_143 ;
} else {
switch ( V_2 -> V_140 ) {
case V_144 :
if ( ! ( V_2 -> V_62 . V_69
& V_77 ) )
V_2 -> V_140 = V_145 ;
break;
case V_145 :
if ( ( V_2 -> V_62 . V_69 & V_77 ) ) {
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
if ( ! ( V_2 -> V_62 . V_69
& V_77 ) )
V_2 -> V_140 = V_145 ;
else
V_2 -> V_140 = V_144 ;
break;
default:
break;
}
}
if ( V_2 -> V_140 != V_111 ) {
F_25 ( L_9 ,
V_2 -> V_28 , V_111 ,
V_2 -> V_140 ) ;
switch ( V_2 -> V_140 ) {
case V_141 :
V_2 -> V_142 = 0 ;
break;
case V_144 :
V_2 -> V_142 = F_29 ( V_41 , ( T_2 ) ( V_146 ) ) - 1 ;
break;
case V_145 :
V_2 -> V_142 = F_29 ( V_41 , ( T_2 ) ( V_147 ) ) - 1 ;
break;
case V_143 :
V_2 -> V_78 = true ;
break;
default:
break;
}
}
}
static void F_60 ( struct V_2 * V_2 )
{
struct V_8 * V_8 , * V_148 = NULL , * V_149 ;
struct V_2 * V_150 = NULL , * V_151 ;
int V_152 = 0 ;
if ( V_2 -> V_58 & V_73 )
return;
if ( V_2 -> V_8 ) {
V_149 = V_2 -> V_8 ;
for ( V_151 = V_149 -> V_79 ; V_151 ;
V_150 = V_151 ,
V_151 = V_151 -> V_80 ) {
if ( V_151 == V_2 ) {
V_149 -> V_85 -- ;
if ( ! V_150 ) {
V_149 -> V_79 =
V_2 -> V_80 ;
} else {
V_150 -> V_80 =
V_2 -> V_80 ;
}
V_2 -> V_8 = NULL ;
V_2 -> V_80 = NULL ;
V_2 -> V_153 = 0 ;
F_25 ( L_10 ,
V_2 -> V_28 ,
V_149 -> V_154 ) ;
if ( ! V_149 -> V_79 )
F_61 ( V_149 ) ;
break;
}
}
if ( ! V_151 ) {
F_62 ( L_11 ,
V_2 -> V_3 -> V_14 -> V_136 -> V_137 ,
V_2 -> V_28 ,
V_2 -> V_3 -> V_14 -> V_137 ,
V_2 -> V_8 -> V_154 ) ;
}
}
for ( V_8 = F_6 ( V_2 ) ; V_8 ;
V_8 = F_7 ( V_8 ) ) {
if ( ! V_8 -> V_79 ) {
if ( ! V_148 )
V_148 = V_8 ;
continue;
}
if ( ( ( V_8 -> V_155 == V_2 -> V_53 ) &&
! F_32 ( & ( V_8 -> V_10 ) , & ( V_2 -> V_62 . system ) ) &&
( V_8 -> V_50 == V_2 -> V_62 . V_66 ) &&
( V_8 -> V_156 == V_2 -> V_62 . V_67 )
) &&
( ( F_32 ( & ( V_2 -> V_62 . system ) , & ( V_157 ) ) &&
! V_8 -> V_158 )
)
) {
V_2 -> V_8 = V_8 ;
V_2 -> V_153 =
V_2 -> V_8 -> V_154 ;
V_2 -> V_80 = V_8 -> V_79 ;
V_2 -> V_8 -> V_85 ++ ;
V_8 -> V_79 = V_2 ;
F_25 ( L_12 ,
V_2 -> V_28 ,
V_2 -> V_8 -> V_154 ) ;
V_2 -> V_58 |= V_73 ;
V_152 = 1 ;
break;
}
}
if ( ! V_152 ) {
if ( V_148 ) {
V_2 -> V_8 = V_148 ;
V_2 -> V_153 =
V_2 -> V_8 -> V_154 ;
if ( V_2 -> V_53 & V_133 )
V_2 -> V_8 -> V_158 = false ;
else
V_2 -> V_8 -> V_158 = true ;
V_2 -> V_8 -> V_159 = V_2 -> V_160 ;
V_2 -> V_8 -> V_155 = V_2 -> V_53 ;
V_2 -> V_8 -> V_10 =
V_2 -> V_62 . system ;
V_2 -> V_8 -> V_50 =
V_2 -> V_62 . V_66 ;
V_2 -> V_8 -> V_156 = V_2 -> V_62 . V_67 ;
V_2 -> V_8 -> V_161 = 1 ;
V_2 -> V_8 -> V_162 = 1 ;
V_2 -> V_8 -> V_79 = V_2 ;
V_2 -> V_8 -> V_85 ++ ;
V_2 -> V_58 |= V_73 ;
F_25 ( L_13 ,
V_2 -> V_28 ,
V_2 -> V_8 -> V_154 ) ;
} else {
F_57 ( L_14 ,
V_2 -> V_3 -> V_14 -> V_136 -> V_137 ,
V_2 -> V_28 , V_2 -> V_3 -> V_14 -> V_137 ) ;
}
}
F_41 ( V_2 -> V_8 , F_40 ( V_2 -> V_8 ) ) ;
V_8 = F_6 ( V_2 ) ;
F_63 ( V_8 ) ;
}
static struct V_8 * F_64 ( struct V_8 * V_163 ,
struct V_8 * V_164 )
{
if ( ! V_163 )
return V_164 ;
if ( ! V_164 -> V_158 && V_163 -> V_158 )
return V_164 ;
if ( V_164 -> V_158 && ! V_163 -> V_158 )
return V_163 ;
if ( F_8 ( V_164 ) && ! F_8 ( V_163 ) )
return V_164 ;
if ( ! F_8 ( V_164 ) && F_8 ( V_163 ) )
return V_163 ;
switch ( F_17 ( V_164 -> V_79 ) ) {
case V_165 :
if ( V_164 -> V_85 > V_163 -> V_85 )
return V_164 ;
if ( V_164 -> V_85 < V_163 -> V_85 )
return V_163 ;
case V_15 :
case V_166 :
if ( F_42 ( V_164 ) > F_42 ( V_163 ) )
return V_164 ;
break;
default:
F_62 ( L_15 ,
V_164 -> V_3 -> V_14 -> V_136 -> V_137 ,
F_17 ( V_164 -> V_79 ) ) ;
break;
}
return V_163 ;
}
static int F_65 ( const struct V_8 * V_9 )
{
struct V_2 * V_2 = V_9 -> V_79 ;
if ( ! V_2 )
return 0 ;
return ( F_66 ( V_2 -> V_3 -> V_14 ) &&
F_67 ( V_2 -> V_3 -> V_14 ) ) ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_8 * V_163 , * V_167 , * V_168 ;
struct V_2 * V_2 ;
V_168 = V_9 ;
V_167 = F_43 ( V_9 ) ;
V_163 = ( V_167 && F_65 ( V_167 ) ) ? V_167 : NULL ;
do {
V_9 -> V_87 = 0 ;
if ( V_9 -> V_85 && F_65 ( V_9 ) )
V_163 = F_64 ( V_163 , V_9 ) ;
} while ( ( V_9 = F_7 ( V_9 ) ) );
if ( V_163 &&
F_17 ( V_163 -> V_79 ) == V_15 ) {
if ( V_167 && V_167 -> V_79 &&
V_167 -> V_79 -> V_124 &&
( F_8 ( V_167 ) ||
( ! F_8 ( V_167 ) && ! F_8 ( V_163 ) ) ) ) {
if ( ! ( ! V_167 -> V_155 &&
V_163 -> V_155 ) ) {
V_163 = NULL ;
V_167 -> V_87 = 1 ;
}
}
}
if ( V_163 && ( V_163 == V_167 ) ) {
V_163 = NULL ;
V_167 -> V_87 = 1 ;
}
if ( V_163 ) {
F_25 ( L_16 ,
V_163 -> V_154 , V_163 -> V_85 ,
V_163 -> V_155 ,
V_163 -> V_156 ,
V_163 -> V_158 , V_163 -> V_87 ) ;
F_25 ( L_17 ,
V_163 -> V_79 , V_163 -> V_3 ,
V_163 -> V_3 ? V_163 -> V_3 -> V_14 -> V_137 : L_18 ) ;
for ( V_9 = F_6 ( V_163 -> V_79 ) ; V_9 ;
V_9 = F_7 ( V_9 ) ) {
F_25 ( L_19 ,
V_9 -> V_154 , V_9 -> V_85 ,
V_9 -> V_155 ,
V_9 -> V_156 ,
V_9 -> V_158 , V_9 -> V_87 ) ;
}
if ( V_163 -> V_158 ) {
F_62 ( L_20 ,
V_163 -> V_3 ? V_163 -> V_3 -> V_14 -> V_136 -> V_137 : L_18 ) ;
}
V_163 -> V_87 = 1 ;
F_25 ( L_21 ,
V_163 -> V_154 ) ;
F_25 ( L_19 ,
V_163 -> V_154 , V_163 -> V_85 ,
V_163 -> V_155 ,
V_163 -> V_156 ,
V_163 -> V_158 , V_163 -> V_87 ) ;
if ( V_167 ) {
for ( V_2 = V_167 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
F_10 ( V_2 ) ;
}
}
}
V_167 = F_43 ( V_168 ) ;
if ( V_167 ) {
if ( ! F_8 ( V_167 ) ) {
for ( V_2 = V_167 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
F_12 ( V_2 ) ;
}
}
}
if ( V_168 -> V_3 ) {
struct V_1 * V_4 ;
V_4 = F_2 ( V_168 -> V_3 ) ;
if ( V_4 )
F_68 ( V_4 ) ;
}
}
static void F_61 ( struct V_8 * V_8 )
{
if ( V_8 ) {
V_8 -> V_158 = false ;
V_8 -> V_159 = 0 ;
V_8 -> V_155 = 0 ;
V_8 -> V_10 = V_157 ;
V_8 -> V_50 = 0 ;
V_8 -> V_156 = 0 ;
V_8 -> V_161 = 0 ;
V_8 -> V_162 = 0 ;
V_8 -> V_79 = NULL ;
V_8 -> V_87 = 0 ;
V_8 -> V_85 = 0 ;
F_25 ( L_22 ,
V_8 -> V_154 ) ;
}
}
static void F_69 ( struct V_8 * V_8 )
{
if ( V_8 ) {
F_61 ( V_8 ) ;
V_8 -> V_169 = V_157 ;
V_8 -> V_154 = 0 ;
V_8 -> V_3 = NULL ;
}
}
static void F_70 ( struct V_2 * V_2 , int V_170 )
{
static const struct V_60 V_171 = {
. V_66 = 0xffff ,
. V_67 = 1 ,
. V_63 = 1 ,
. V_65 = 0xff ,
. V_69 = 1 ,
} ;
static const struct V_45 V_45 = {
. V_172 = 0x01 ,
. V_173 = 0x01 ,
. V_174 = 0x01 ,
. V_175 = 0x14 ,
. V_176 = 0x02 ,
. V_177 = 0x14 ,
. V_178 = 0x03 ,
. V_179 = 0x10 ,
. V_180 = F_45 ( V_181 ) ,
} ;
if ( V_2 ) {
V_2 -> V_28 = 1 ;
V_2 -> V_48 = 0xff ;
V_2 -> V_49 = V_157 ;
V_2 -> V_51 = 0xffff ;
V_2 -> V_153 = 0 ;
V_2 -> V_78 = false ;
V_2 -> V_160 = 1 ;
V_2 -> V_53 = 1 ;
V_2 -> V_182 = V_55 | V_76 ;
V_2 -> V_56 = V_55 | V_76 ;
if ( V_170 )
V_2 -> V_56 |= V_77 ;
memcpy ( & V_2 -> V_72 , & V_171 , sizeof( V_171 ) ) ;
memcpy ( & V_2 -> V_62 , & V_171 , sizeof( V_171 ) ) ;
V_2 -> V_124 = true ;
V_2 -> V_58 = 0x3 ;
V_2 -> V_122 = 0 ;
V_2 -> V_130 = 0 ;
V_2 -> V_140 = 0 ;
V_2 -> V_142 = 0 ;
V_2 -> V_112 = 0 ;
V_2 -> V_117 = 0 ;
V_2 -> V_183 = 0 ;
V_2 -> V_138 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_8 = NULL ;
V_2 -> V_80 = NULL ;
V_2 -> V_184 = 0 ;
memcpy ( & V_2 -> V_45 , & V_45 , sizeof( V_45 ) ) ;
}
}
static void F_55 ( struct V_2 * V_2 )
{
if ( V_2 -> V_8 -> V_87 ) {
F_25 ( L_23 ,
V_2 -> V_28 ,
V_2 -> V_8 -> V_154 ) ;
F_12 ( V_2 ) ;
}
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_8 && F_32 ( & ( V_2 -> V_8 -> V_10 ) , & ( V_157 ) ) ) {
F_25 ( L_24 ,
V_2 -> V_28 ,
V_2 -> V_8 -> V_154 ) ;
F_10 ( V_2 ) ;
}
}
static void F_71 ( struct V_107 * V_185 ,
struct V_2 * V_2 )
{
struct V_107 V_108 ;
memcpy ( & V_108 , V_185 , sizeof( struct V_107 ) ) ;
V_108 . V_186 = V_187 ;
if ( F_51 ( V_2 , & V_108 ) >= 0 ) {
F_25 ( L_25 ,
V_2 -> V_28 ) ;
}
}
static void F_72 ( struct V_107 * V_108 ,
struct V_2 * V_2 )
{
V_108 = NULL ;
V_2 = NULL ;
}
void F_73 ( struct V_1 * V_4 , int V_188 )
{
F_18 ( V_4 ) . V_17 = V_188 ;
F_18 ( V_4 ) . V_16 = V_4 -> V_189 . V_190 ;
}
void F_74 ( struct V_1 * V_4 , T_2 V_191 , int V_170 )
{
if ( F_32 ( & ( F_18 ( V_4 ) . system . V_192 ) ,
V_4 -> V_14 -> V_193 ) ) {
V_154 = 0 ;
F_18 ( V_4 ) . V_170 = V_170 ;
F_18 ( V_4 ) . system . V_194 = 0xFFFF ;
F_18 ( V_4 ) . system . V_192 = * ( (struct V_195 * ) V_4 -> V_14 -> V_193 ) ;
V_37 = V_191 ;
F_73 ( V_4 ,
V_196 *
V_37 ) ;
}
}
int F_75 ( struct V_3 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_8 * V_8 ;
if ( V_4 == NULL ) {
F_57 ( L_26 ,
V_3 -> V_14 -> V_136 -> V_137 , V_3 -> V_14 -> V_137 ) ;
return - 1 ;
}
if ( F_4 ( V_3 ) . V_2 . V_3 != V_3 ) {
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
F_70 ( V_2 , F_18 ( V_4 ) . V_170 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = F_4 ( V_3 ) . V_197 ;
V_2 -> V_160 = 0 ;
V_2 -> V_160 |= F_26 ( V_2 ) ;
V_2 -> V_160 |= ( F_24 ( V_2 ) << 1 ) ;
V_2 -> V_53 = V_2 -> V_160 ;
if ( ! ( V_2 -> V_53 & V_133 ) )
V_2 -> V_58 &= ~ V_131 ;
V_2 -> V_49 = F_18 ( V_4 ) . system . V_192 ;
V_2 -> V_138 = V_37 / V_139 ;
V_2 -> V_8 = NULL ;
V_2 -> V_80 = NULL ;
F_10 ( V_2 ) ;
F_27 ( V_2 ) ;
V_8 = & ( F_4 ( V_3 ) . V_8 ) ;
F_69 ( V_8 ) ;
V_8 -> V_169 = * ( (struct V_195 * ) V_4 -> V_14 -> V_193 ) ;
V_8 -> V_154 = ( ++ V_154 ) ;
V_8 -> V_3 = V_3 ;
V_8 -> V_87 = 0 ;
V_8 -> V_85 = 0 ;
}
return 0 ;
}
void F_76 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_198 , * V_199 ;
struct V_8 * V_8 , * V_200 , * V_149 ;
int V_201 = 0 ;
V_8 = & ( F_4 ( V_3 ) . V_8 ) ;
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_27 ,
V_3 -> V_14 -> V_136 -> V_137 , V_3 -> V_14 -> V_137 ) ;
return;
}
F_25 ( L_28 ,
V_8 -> V_154 ) ;
V_2 -> V_56 &= ~ V_55 ;
F_44 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( V_8 -> V_79 ) {
if ( ( V_8 -> V_79 != V_2 ) || ( V_8 -> V_79 -> V_80 ) ) {
V_200 = F_6 ( V_2 ) ;
for (; V_200 ; V_200 = F_7 ( V_200 ) ) {
if ( ! V_200 -> V_79
|| ( ( V_200 -> V_79 == V_2 )
&& ! V_200 -> V_79 -> V_80 ) )
break;
}
if ( ( V_200 ) && ( ( ! V_200 -> V_79 ) || ( ( V_200 -> V_79 == V_2 ) && ! V_200 -> V_79 -> V_80 ) ) ) {
F_25 ( L_29 ,
V_8 -> V_154 ,
V_200 -> V_154 ) ;
if ( ( V_200 -> V_79 == V_2 ) && V_200 -> V_87 ) {
F_77 ( L_30 ,
V_8 -> V_3 -> V_14 -> V_136 -> V_137 ) ;
V_201 = 1 ;
}
V_200 -> V_158 = V_8 -> V_158 ;
V_200 -> V_159 = V_8 -> V_159 ;
V_200 -> V_155 = V_8 -> V_155 ;
V_200 -> V_10 = V_8 -> V_10 ;
V_200 -> V_50 = V_8 -> V_50 ;
V_200 -> V_156 = V_8 -> V_156 ;
V_200 -> V_161 = V_8 -> V_161 ;
V_200 -> V_162 = V_8 -> V_162 ;
V_200 -> V_79 = V_8 -> V_79 ;
V_200 -> V_87 = V_8 -> V_87 ;
V_200 -> V_85 = V_8 -> V_85 ;
for ( V_199 = V_8 -> V_79 ; V_199 ;
V_199 = V_199 -> V_80 ) {
V_199 -> V_8 = V_200 ;
V_199 -> V_153 = V_200 -> V_154 ;
}
F_61 ( V_8 ) ;
if ( V_201 )
F_63 ( F_6 ( V_2 ) ) ;
} else {
F_62 ( L_31 ,
V_3 -> V_14 -> V_136 -> V_137 ) ;
}
} else {
V_201 = V_8 -> V_87 ;
F_61 ( V_8 ) ;
if ( V_201 ) {
F_77 ( L_30 ,
V_3 -> V_14 -> V_136 -> V_137 ) ;
F_63 ( F_6 ( V_2 ) ) ;
}
}
}
F_25 ( L_32 , V_2 -> V_28 ) ;
V_149 = F_6 ( V_2 ) ;
for (; V_149 ; V_149 = F_7 ( V_149 ) ) {
V_198 = NULL ;
for ( V_199 = V_149 -> V_79 ; V_199 ;
V_198 = V_199 ,
V_199 = V_199 -> V_80 ) {
if ( V_199 == V_2 ) {
if ( V_198 )
V_198 -> V_80 = V_199 -> V_80 ;
else
V_149 -> V_79 = V_199 -> V_80 ;
V_149 -> V_85 -- ;
if ( V_149 -> V_85 == 0 ) {
V_201 = V_149 -> V_87 ;
F_61 ( V_149 ) ;
if ( V_201 ) {
F_77 ( L_30 ,
V_3 -> V_14 -> V_136 -> V_137 ) ;
F_63 ( F_6 ( V_2 ) ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
}
void F_78 ( struct V_202 * V_203 )
{
struct V_1 * V_4 = F_79 ( V_203 , struct V_1 ,
V_204 . V_203 ) ;
struct V_2 * V_2 ;
struct V_8 * V_8 ;
F_80 ( & V_4 -> V_205 ) ;
if ( V_4 -> V_206 )
goto V_207;
if ( V_4 -> V_5 == 0 )
goto V_208;
if ( F_18 ( V_4 ) . V_17 && ! ( -- F_18 ( V_4 ) . V_17 ) ) {
if ( ( V_2 = F_3 ( V_4 ) ) ) {
if ( ! V_2 -> V_3 ) {
F_62 ( L_33 ,
V_4 -> V_14 -> V_137 ) ;
goto V_208;
}
V_8 = F_6 ( V_2 ) ;
F_63 ( V_8 ) ;
}
F_68 ( V_4 ) ;
}
for ( V_2 = F_3 ( V_4 ) ; V_2 ; V_2 = F_5 ( V_2 ) ) {
if ( ! V_2 -> V_3 ) {
F_62 ( L_34 ,
V_4 -> V_14 -> V_137 ) ;
goto V_208;
}
F_20 ( V_2 ) ;
F_56 ( NULL , V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
F_53 ( V_2 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_58 & V_113 )
V_2 -> V_58 &= ~ V_113 ;
F_22 ( V_2 ) ;
}
V_208:
F_81 ( V_4 -> V_209 , & V_4 -> V_204 , V_210 ) ;
V_207:
F_82 ( & V_4 -> V_205 ) ;
}
static void F_83 ( struct V_45 * V_45 , struct V_3 * V_3 , T_2 V_91 )
{
struct V_2 * V_2 ;
if ( V_91 >= sizeof( struct V_45 ) ) {
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_35 ,
V_3 -> V_14 -> V_137 , V_3 -> V_14 -> V_136 -> V_137 ) ;
return;
}
switch ( V_45 -> V_172 ) {
case V_211 :
F_25 ( L_36 ,
V_2 -> V_28 ) ;
F_20 ( V_2 ) ;
F_56 ( V_45 , V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_212 :
switch ( ( (struct V_107 * ) V_45 ) -> V_186 ) {
case V_213 :
F_25 ( L_37 ,
V_2 -> V_28 ) ;
F_71 ( (struct V_107 * ) V_45 , V_2 ) ;
break;
case V_187 :
F_25 ( L_38 ,
V_2 -> V_28 ) ;
F_72 ( (struct V_107 * ) V_45 , V_2 ) ;
break;
default:
F_25 ( L_39 ,
V_2 -> V_28 ) ;
}
}
}
}
void F_84 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_40 ,
V_3 -> V_14 -> V_136 -> V_137 , V_3 -> V_14 -> V_137 ) ;
return;
}
V_2 -> V_160 &= ~ V_214 ;
V_2 -> V_53 = V_2 -> V_160 |=
( F_24 ( V_2 ) << 1 ) ;
F_25 ( L_41 , V_2 -> V_28 ) ;
V_2 -> V_58 |= V_113 ;
}
void F_85 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_42 ,
V_3 -> V_14 -> V_136 -> V_137 , V_3 -> V_14 -> V_137 ) ;
return;
}
V_2 -> V_160 &= ~ V_133 ;
V_2 -> V_53 = V_2 -> V_160 |=
F_26 ( V_2 ) ;
F_25 ( L_43 , V_2 -> V_28 ) ;
V_2 -> V_58 |= V_113 ;
}
void F_86 ( struct V_3 * V_3 , char V_12 )
{
struct V_2 * V_2 ;
V_2 = & ( F_4 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_62 ( L_44 ,
V_3 -> V_14 -> V_136 -> V_137 , V_3 -> V_14 -> V_137 ) ;
return;
}
if ( V_12 == V_13 ) {
V_2 -> V_124 = true ;
V_2 -> V_160 &= ~ V_133 ;
V_2 -> V_53 = V_2 -> V_160 |=
F_26 ( V_2 ) ;
V_2 -> V_160 &= ~ V_214 ;
V_2 -> V_53 = V_2 -> V_160 |=
( F_24 ( V_2 ) << 1 ) ;
} else {
V_2 -> V_124 = false ;
V_2 -> V_160 &= ~ V_133 ;
V_2 -> V_53 = ( V_2 -> V_160 &=
~ V_214 ) ;
}
V_2 -> V_58 |= V_113 ;
}
int F_68 ( struct V_1 * V_4 )
{
if ( F_43 ( & ( F_4 ( V_4 -> V_6 ) . V_8 ) ) ) {
if ( ! F_67 ( V_4 -> V_14 ) ) {
F_87 ( V_4 -> V_14 ) ;
return 1 ;
}
return 0 ;
}
if ( F_67 ( V_4 -> V_14 ) ) {
F_88 ( V_4 -> V_14 ) ;
return 1 ;
}
return 0 ;
}
int F_89 ( struct V_1 * V_4 , struct V_215 * V_215 )
{
struct V_8 * V_8 = NULL ;
struct V_2 * V_2 ;
for ( V_2 = F_3 ( V_4 ) ; V_2 ; V_2 = F_5 ( V_2 ) ) {
if ( V_2 -> V_8 && V_2 -> V_8 -> V_87 ) {
V_8 = V_2 -> V_8 ;
break;
}
}
if ( V_8 ) {
V_215 -> V_216 = V_8 -> V_154 ;
V_215 -> V_217 = V_8 -> V_85 ;
V_215 -> V_68 = V_8 -> V_155 ;
V_215 -> V_52 = V_8 -> V_156 ;
memcpy ( V_215 -> V_10 , V_8 -> V_10 . V_11 , V_103 ) ;
return 0 ;
}
return - 1 ;
}
int F_90 ( struct V_88 * V_89 , struct V_218 * V_14 )
{
struct V_3 * V_3 , * V_219 ;
struct V_1 * V_4 = F_91 ( V_14 ) ;
int V_220 ;
int V_221 ;
int V_222 ;
int V_223 ;
struct V_215 V_215 ;
int V_224 = 1 ;
if ( F_89 ( V_4 , & V_215 ) ) {
F_25 ( L_45 ,
V_14 -> V_137 ) ;
goto V_207;
}
V_221 = V_215 . V_217 ;
V_222 = V_215 . V_216 ;
if ( V_221 == 0 ) {
F_25 ( L_46 , V_14 -> V_137 ) ;
goto V_207;
}
V_220 = V_4 -> V_225 ( V_89 , V_221 ) ;
F_92 (bond, slave, i) {
struct V_8 * V_9 = F_4 ( V_3 ) . V_2 . V_8 ;
if ( V_9 && ( V_9 -> V_154 == V_222 ) ) {
V_220 -- ;
if ( V_220 < 0 )
break;
}
}
if ( V_220 >= 0 ) {
F_57 ( L_47 ,
V_14 -> V_137 , V_222 ) ;
goto V_207;
}
V_219 = V_3 ;
F_93 (bond, slave, i, start_at) {
int V_226 = 0 ;
struct V_8 * V_9 = F_4 ( V_3 ) . V_2 . V_8 ;
if ( V_9 )
V_226 = V_9 -> V_154 ;
if ( F_94 ( V_3 ) && V_9 && ( V_226 == V_222 ) ) {
V_224 = F_95 ( V_4 , V_89 , V_3 -> V_14 ) ;
break;
}
}
V_207:
if ( V_224 ) {
F_96 ( V_89 ) ;
}
return V_227 ;
}
void F_97 ( struct V_88 * V_89 , struct V_1 * V_4 ,
struct V_3 * V_3 )
{
if ( V_89 -> V_96 != V_97 )
return;
if ( ! F_98 ( V_89 , sizeof( struct V_45 ) ) )
return;
F_80 ( & V_4 -> V_205 ) ;
F_83 ( (struct V_45 * ) V_89 -> V_228 , V_3 , V_89 -> V_229 ) ;
F_82 ( & V_4 -> V_205 ) ;
}
