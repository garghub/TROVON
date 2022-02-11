static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
if ( V_2 -> V_3 == NULL )
return NULL ;
return F_2 ( V_2 -> V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_1 * V_4 )
{
struct V_3 * V_5 = F_4 ( V_4 ) ;
return V_5 ? & ( F_5 ( V_5 ) . V_2 ) : NULL ;
}
static inline struct V_2 * F_6 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_3 * V_3 = V_2 -> V_3 , * V_6 ;
if ( V_4 == NULL )
return NULL ;
V_6 = F_7 ( V_4 , V_3 ) ;
if ( ! V_6 || F_8 ( V_4 , V_6 ) )
return NULL ;
return & ( F_5 ( V_6 ) . V_2 ) ;
}
static inline struct V_7 * F_9 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
struct V_3 * V_5 ;
if ( V_4 == NULL )
return NULL ;
V_5 = F_4 ( V_4 ) ;
return V_5 ? & ( F_5 ( V_5 ) . V_7 ) : NULL ;
}
static inline struct V_7 * F_10 ( struct V_7 * V_7 )
{
struct V_3 * V_3 = V_7 -> V_3 , * V_6 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( V_4 == NULL )
return NULL ;
V_6 = F_7 ( V_4 , V_3 ) ;
if ( ! V_6 || F_8 ( V_4 , V_6 ) )
return NULL ;
return & ( F_5 ( V_6 ) . V_7 ) ;
}
static inline int F_11 ( struct V_7 * V_8 )
{
return ! F_12 ( V_8 -> V_9 . V_10 ) ;
}
static inline void F_13 ( struct V_2 * V_2 )
{
F_14 ( V_2 -> V_3 ) ;
}
static inline void F_15 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
if ( ( V_3 -> V_11 == V_12 ) && F_16 ( V_3 -> V_13 ) )
F_17 ( V_3 ) ;
}
static inline int F_18 ( struct V_2 * V_2 )
{
return F_19 ( V_2 -> V_3 ) ;
}
static inline T_1 F_20 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
if ( V_4 == NULL )
return V_14 ;
return V_4 -> V_15 . V_16 ;
}
static inline int F_21 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = F_1 ( V_2 ) ;
if ( V_4 == NULL )
return 0 ;
return F_22 ( V_4 ) . V_17 ? 1 : 0 ;
}
static inline void F_23 ( struct V_2 * V_2 )
{
F_24 ( & ( F_5 ( V_2 -> V_3 ) . V_18 ) ) ;
}
static inline void F_25 ( struct V_2 * V_2 )
{
F_26 ( & ( F_5 ( V_2 -> V_3 ) . V_18 ) ) ;
}
static T_2 F_27 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_2 V_19 ;
if ( V_3 -> V_11 != V_12 )
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
F_28 ( L_1 ,
V_2 -> V_28 , V_19 ) ;
return V_19 ;
}
static T_3 F_29 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_29 ;
if ( V_3 -> V_11 != V_12 )
V_29 = 0x0 ;
else {
switch ( V_3 -> V_30 ) {
case V_31 :
V_29 = 0x1 ;
F_28 ( L_2 ,
V_2 -> V_28 ) ;
break;
case V_32 :
default:
V_29 = 0x0 ;
F_28 ( L_3 ,
V_2 -> V_28 ) ;
break;
}
}
return V_29 ;
}
static inline void F_30 ( struct V_3 * V_3 )
{
F_31 ( & ( F_5 ( V_3 ) . V_18 ) ) ;
}
static T_2 F_32 ( T_2 V_33 , T_2 V_34 )
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
static void F_33 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
if ( ( ( F_34 ( V_45 -> V_46 ) == V_2 -> V_28 ) &&
( F_34 ( V_45 -> V_47 ) == V_2 -> V_48 ) &&
! F_35 ( & ( V_45 -> V_9 ) , & ( V_2 -> V_49 ) ) &&
( F_34 ( V_45 -> V_50 ) == V_2 -> V_51 ) &&
( F_34 ( V_45 -> V_52 ) == V_2 -> V_53 ) &&
( ( V_45 -> V_54 & V_55 ) == ( V_2 -> V_56 & V_55 ) ) ) ||
( ( V_45 -> V_57 & V_55 ) == 0 )
) {
V_2 -> V_58 |= V_59 ;
} else {
V_2 -> V_58 &= ~ V_59 ;
}
}
static void F_36 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
if ( V_45 && V_2 ) {
struct V_60 * V_61 = & V_2 -> V_62 ;
F_33 ( V_45 , V_2 ) ;
V_61 -> V_63 = F_34 ( V_45 -> V_64 ) ;
V_61 -> V_65 = F_34 ( V_45 -> V_48 ) ;
V_61 -> system = V_45 -> V_49 ;
V_61 -> V_66 = F_34 ( V_45 -> V_51 ) ;
V_61 -> V_67 = F_34 ( V_45 -> V_68 ) ;
V_61 -> V_69 = V_45 -> V_57 ;
V_2 -> V_56 &= ~ V_70 ;
if ( ( V_2 -> V_58 & V_59 )
&& ( V_45 -> V_57 & V_71 ) )
V_61 -> V_69 |= V_71 ;
else
V_61 -> V_69 &= ~ V_71 ;
}
}
static void F_37 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_62 , & V_2 -> V_72 ,
sizeof( struct V_60 ) ) ;
V_2 -> V_56 |= V_70 ;
}
}
static void F_38 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
if ( V_45 && V_2 ) {
const struct V_60 * V_61 = & V_2 -> V_62 ;
if ( F_34 ( V_45 -> V_64 ) != V_61 -> V_63 ||
F_34 ( V_45 -> V_48 ) != V_61 -> V_65 ||
F_35 ( & V_45 -> V_49 , & V_61 -> system ) ||
F_34 ( V_45 -> V_51 ) != V_61 -> V_66 ||
F_34 ( V_45 -> V_68 ) != V_61 -> V_67 ||
( V_45 -> V_57 & V_55 ) != ( V_61 -> V_69 & V_55 ) ) {
V_2 -> V_58 &= ~ V_73 ;
}
}
}
static void F_39 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_60 * V_74 = & V_2 -> V_72 ;
const struct V_60 * V_75 = & V_2 -> V_62 ;
if ( V_74 -> V_63 != V_75 -> V_63 ||
V_74 -> V_65 != V_75 -> V_65 ||
F_35 ( & V_74 -> system , & V_75 -> system ) ||
V_74 -> V_66 != V_75 -> V_66 ||
V_74 -> V_67 != V_75 -> V_67 ||
( V_74 -> V_69 & V_55 )
!= ( V_75 -> V_69 & V_55 ) ) {
V_2 -> V_58 &= ~ V_73 ;
}
}
}
static void F_40 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
if ( V_45 && V_2 ) {
if ( ( F_34 ( V_45 -> V_46 ) != V_2 -> V_28 ) ||
( F_34 ( V_45 -> V_47 ) != V_2 -> V_48 ) ||
F_35 ( & ( V_45 -> V_9 ) , & ( V_2 -> V_49 ) ) ||
( F_34 ( V_45 -> V_50 ) != V_2 -> V_51 ) ||
( F_34 ( V_45 -> V_52 ) != V_2 -> V_53 ) ||
( ( V_45 -> V_54 & V_76 ) != ( V_2 -> V_56 & V_76 ) ) ||
( ( V_45 -> V_54 & V_77 ) != ( V_2 -> V_56 & V_77 ) ) ||
( ( V_45 -> V_54 & V_71 ) != ( V_2 -> V_56 & V_71 ) ) ||
( ( V_45 -> V_54 & V_55 ) != ( V_2 -> V_56 & V_55 ) )
) {
V_2 -> V_78 = true ;
}
}
}
static void F_41 ( struct V_2 * V_2 )
{
V_2 = NULL ;
}
static void F_42 ( struct V_2 * V_2 )
{
V_2 = NULL ;
}
static int F_43 ( struct V_7 * V_7 )
{
struct V_2 * V_2 ;
int V_29 = 1 ;
if ( V_7 ) {
for ( V_2 = V_7 -> V_79 ;
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
static void F_44 ( struct V_7 * V_7 , int V_82 )
{
struct V_2 * V_2 ;
for ( V_2 = V_7 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
if ( V_82 )
V_2 -> V_58 |= V_83 ;
else
V_2 -> V_58 &= ~ V_83 ;
}
}
static T_1 F_45 ( struct V_7 * V_7 )
{
T_1 V_84 = 0 ;
if ( V_7 -> V_85 ) {
switch ( F_27 ( V_7 -> V_79 ) ) {
case V_86 :
V_84 = V_7 -> V_85 ;
break;
case V_21 :
V_84 = V_7 -> V_85 * 10 ;
break;
case V_23 :
V_84 = V_7 -> V_85 * 100 ;
break;
case V_25 :
V_84 = V_7 -> V_85 * 1000 ;
break;
case V_27 :
V_84 = V_7 -> V_85 * 10000 ;
break;
default:
V_84 = 0 ;
}
}
return V_84 ;
}
static struct V_7 * F_46 ( struct V_7 * V_7 )
{
struct V_7 * V_29 = NULL ;
for (; V_7 ; V_7 = F_10 ( V_7 ) ) {
if ( V_7 -> V_87 ) {
V_29 = V_7 ;
break;
}
}
return V_29 ;
}
static inline void F_47 ( struct V_2 * V_2 )
{
struct V_45 * V_45 = & V_2 -> V_45 ;
const struct V_60 * V_61 = & V_2 -> V_62 ;
V_45 -> V_51 = F_48 ( V_2 -> V_51 ) ;
V_45 -> V_49 = V_2 -> V_49 ;
V_45 -> V_68 = F_48 ( V_2 -> V_53 ) ;
V_45 -> V_48 = F_48 ( V_2 -> V_48 ) ;
V_45 -> V_64 = F_48 ( V_2 -> V_28 ) ;
V_45 -> V_57 = V_2 -> V_56 ;
V_45 -> V_50 = F_48 ( V_61 -> V_66 ) ;
V_45 -> V_9 = V_61 -> system ;
V_45 -> V_52 = F_48 ( V_61 -> V_67 ) ;
V_45 -> V_47 = F_48 ( V_61 -> V_65 ) ;
V_45 -> V_46 = F_48 ( V_61 -> V_63 ) ;
V_45 -> V_54 = V_61 -> V_69 ;
}
static int F_49 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_88 * V_89 ;
struct V_90 * V_90 ;
int V_91 = sizeof( struct V_90 ) ;
V_89 = F_50 ( V_91 ) ;
if ( ! V_89 )
return - V_92 ;
V_89 -> V_13 = V_3 -> V_13 ;
F_51 ( V_89 ) ;
V_89 -> V_93 = V_89 -> V_94 + V_95 ;
V_89 -> V_96 = V_97 ;
V_89 -> V_98 = V_99 ;
V_90 = (struct V_90 * ) F_52 ( V_89 , V_91 ) ;
memcpy ( V_90 -> V_100 . V_101 , V_102 , V_103 ) ;
memcpy ( V_90 -> V_100 . V_104 , V_3 -> V_105 , V_103 ) ;
V_90 -> V_100 . V_106 = V_97 ;
V_90 -> V_45 = V_2 -> V_45 ;
F_53 ( V_89 ) ;
return 0 ;
}
static int F_54 ( struct V_2 * V_2 , struct V_107 * V_108 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_88 * V_89 ;
struct V_109 * V_110 ;
int V_91 = sizeof( struct V_109 ) ;
V_89 = F_50 ( V_91 + 16 ) ;
if ( ! V_89 )
return - V_92 ;
F_55 ( V_89 , 16 ) ;
V_89 -> V_13 = V_3 -> V_13 ;
F_51 ( V_89 ) ;
V_89 -> V_93 = V_89 -> V_94 + V_95 ;
V_89 -> V_96 = V_97 ;
V_110 = (struct V_109 * ) F_52 ( V_89 , V_91 ) ;
memcpy ( V_110 -> V_100 . V_101 , V_102 , V_103 ) ;
memcpy ( V_110 -> V_100 . V_104 , V_3 -> V_105 , V_103 ) ;
V_110 -> V_100 . V_106 = V_97 ;
V_110 -> V_108 = * V_108 ;
F_53 ( V_89 ) ;
return 0 ;
}
static void F_56 ( struct V_2 * V_2 )
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
F_44 ( V_2 -> V_7 , F_43 ( V_2 -> V_7 ) ) ;
V_2 -> V_112 = V_114 ;
break;
}
if ( V_2 -> V_117
&& ! ( -- V_2 -> V_117 ) )
V_2 -> V_58 |= V_81 ;
F_44 ( V_2 -> V_7 , F_43 ( V_2 -> V_7 ) ) ;
if ( ( V_2 -> V_58 & V_83 )
&& ! V_2 -> V_117 )
V_2 -> V_112 = V_118 ;
break;
case V_118 :
if ( ( V_2 -> V_58 & V_73 ) && ( V_2 -> V_62 . V_69 & V_71 ) && ! F_21 ( V_2 ) ) {
V_2 -> V_112 = V_119 ;
} else if ( ! ( V_2 -> V_58 & V_73 ) || ( V_2 -> V_58 & V_115 ) ) {
V_2 -> V_58 &= ~ V_81 ;
F_44 ( V_2 -> V_7 , F_43 ( V_2 -> V_7 ) ) ;
V_2 -> V_112 = V_114 ;
}
break;
case V_119 :
if ( ! ( V_2 -> V_58 & V_73 ) || ( V_2 -> V_58 & V_115 ) ||
! ( V_2 -> V_62 . V_69 & V_71 )
) {
V_2 -> V_112 = V_118 ;
} else {
if ( V_2 -> V_7 &&
V_2 -> V_7 -> V_87 &&
! F_18 ( V_2 ) ) {
F_15 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_112 != V_111 ) {
F_28 ( L_4 ,
V_2 -> V_28 , V_111 ,
V_2 -> V_112 ) ;
switch ( V_2 -> V_112 ) {
case V_114 :
F_42 ( V_2 ) ;
V_2 -> V_56 &= ~ V_71 ;
F_57 ( V_2 ) ;
V_2 -> V_56 &= ~ V_120 ;
V_2 -> V_56 &= ~ V_121 ;
V_2 -> V_78 = true ;
break;
case V_116 :
V_2 -> V_117 = F_32 ( V_43 , 0 ) ;
break;
case V_118 :
F_41 ( V_2 ) ;
V_2 -> V_56 |= V_71 ;
V_2 -> V_56 &= ~ V_120 ;
V_2 -> V_56 &= ~ V_121 ;
F_57 ( V_2 ) ;
V_2 -> V_78 = true ;
break;
case V_119 :
V_2 -> V_56 |= V_120 ;
V_2 -> V_56 |= V_121 ;
F_58 ( V_2 ) ;
V_2 -> V_78 = true ;
break;
default:
break;
}
}
}
static void F_59 ( struct V_45 * V_45 , struct V_2 * V_2 )
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
F_28 ( L_5 ,
V_2 -> V_28 , V_111 ,
V_2 -> V_122 ) ;
switch ( V_2 -> V_122 ) {
case V_123 :
if ( ! ( V_2 -> V_53 & V_133 ) )
V_2 -> V_58 &= ~ V_131 ;
else
V_2 -> V_58 |= V_131 ;
V_2 -> V_58 &= ~ V_73 ;
F_37 ( V_2 ) ;
V_2 -> V_56 &= ~ V_134 ;
V_2 -> V_58 &= ~ V_125 ;
V_2 -> V_122 = V_126 ;
case V_126 :
V_2 -> V_58 &= ~ V_59 ;
break;
case V_132 :
V_2 -> V_58 &= ~ V_73 ;
F_37 ( V_2 ) ;
V_2 -> V_62 . V_69 &= ~ V_55 ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_56 &= ~ V_134 ;
break;
case V_127 :
V_2 -> V_62 . V_69 &= ~ V_71 ;
V_2 -> V_58 &= ~ V_59 ;
V_2 -> V_62 . V_69 |=
V_76 ;
V_2 -> V_130 = F_32 ( V_35 , ( T_2 ) ( V_135 ) ) ;
V_2 -> V_56 |= V_134 ;
break;
case V_128 :
F_39 ( V_2 ) ;
F_37 ( V_2 ) ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_56 &= ~ V_134 ;
break;
case V_129 :
if ( ! F_35 ( & ( V_45 -> V_49 ) , & ( V_2 -> V_49 ) ) ) {
F_60 ( L_6
L_7 ,
V_2 -> V_3 -> V_4 -> V_13 -> V_136 , V_2 -> V_3 -> V_13 -> V_136 ) ;
return;
}
F_38 ( V_45 , V_2 ) ;
F_40 ( V_45 , V_2 ) ;
F_36 ( V_45 , V_2 ) ;
V_2 -> V_130 = F_32 ( V_35 , ( T_2 ) ( V_2 -> V_56 & V_77 ) ) ;
V_2 -> V_56 &= ~ V_134 ;
break;
default:
break;
}
}
}
static void F_61 ( struct V_2 * V_2 )
{
if ( V_2 -> V_137 && ! ( -- V_2 -> V_137 ) ) {
if ( V_2 -> V_78 && ( V_2 -> V_58 & V_131 ) ) {
F_47 ( V_2 ) ;
if ( F_49 ( V_2 ) >= 0 ) {
F_28 ( L_8 ,
V_2 -> V_28 ) ;
V_2 -> V_78 = false ;
}
}
V_2 -> V_137 =
V_37 / V_138 ;
}
}
static void F_62 ( struct V_2 * V_2 )
{
T_6 V_111 ;
V_111 = V_2 -> V_139 ;
if ( ( ( V_2 -> V_58 & V_113 ) || ! ( V_2 -> V_58 & V_131 ) || ! V_2 -> V_124 ) ||
( ! ( V_2 -> V_56 & V_76 ) && ! ( V_2 -> V_62 . V_69 & V_76 ) )
) {
V_2 -> V_139 = V_140 ;
}
else if ( V_2 -> V_141 ) {
if ( ! ( -- V_2 -> V_141 ) ) {
V_2 -> V_139 = V_142 ;
} else {
switch ( V_2 -> V_139 ) {
case V_143 :
if ( ! ( V_2 -> V_62 . V_69
& V_77 ) )
V_2 -> V_139 = V_144 ;
break;
case V_144 :
if ( ( V_2 -> V_62 . V_69 & V_77 ) ) {
V_2 -> V_141 = 0 ;
V_2 -> V_139 = V_142 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_139 ) {
case V_140 :
V_2 -> V_139 = V_143 ;
break;
case V_142 :
if ( ! ( V_2 -> V_62 . V_69
& V_77 ) )
V_2 -> V_139 = V_144 ;
else
V_2 -> V_139 = V_143 ;
break;
default:
break;
}
}
if ( V_2 -> V_139 != V_111 ) {
F_28 ( L_9 ,
V_2 -> V_28 , V_111 ,
V_2 -> V_139 ) ;
switch ( V_2 -> V_139 ) {
case V_140 :
V_2 -> V_141 = 0 ;
break;
case V_143 :
V_2 -> V_141 = F_32 ( V_41 , ( T_2 ) ( V_145 ) ) - 1 ;
break;
case V_144 :
V_2 -> V_141 = F_32 ( V_41 , ( T_2 ) ( V_146 ) ) - 1 ;
break;
case V_142 :
V_2 -> V_78 = true ;
break;
default:
break;
}
}
}
static void F_63 ( struct V_2 * V_2 )
{
struct V_7 * V_7 , * V_147 = NULL , * V_148 ;
struct V_2 * V_149 = NULL , * V_150 ;
int V_151 = 0 ;
if ( V_2 -> V_58 & V_73 )
return;
if ( V_2 -> V_7 ) {
V_148 = V_2 -> V_7 ;
for ( V_150 = V_148 -> V_79 ; V_150 ;
V_149 = V_150 ,
V_150 = V_150 -> V_80 ) {
if ( V_150 == V_2 ) {
V_148 -> V_85 -- ;
if ( ! V_149 ) {
V_148 -> V_79 =
V_2 -> V_80 ;
} else {
V_149 -> V_80 =
V_2 -> V_80 ;
}
V_2 -> V_7 = NULL ;
V_2 -> V_80 = NULL ;
V_2 -> V_152 = 0 ;
F_28 ( L_10 ,
V_2 -> V_28 ,
V_148 -> V_153 ) ;
if ( ! V_148 -> V_79 )
F_64 ( V_148 ) ;
break;
}
}
if ( ! V_150 ) {
F_65 ( L_11 ,
V_2 -> V_3 -> V_4 -> V_13 -> V_136 ,
V_2 -> V_28 ,
V_2 -> V_3 -> V_13 -> V_136 ,
V_2 -> V_7 -> V_153 ) ;
}
}
for ( V_7 = F_9 ( V_2 ) ; V_7 ;
V_7 = F_10 ( V_7 ) ) {
if ( ! V_7 -> V_79 ) {
if ( ! V_147 )
V_147 = V_7 ;
continue;
}
if ( ( ( V_7 -> V_154 == V_2 -> V_53 ) &&
! F_35 ( & ( V_7 -> V_9 ) , & ( V_2 -> V_62 . system ) ) &&
( V_7 -> V_50 == V_2 -> V_62 . V_66 ) &&
( V_7 -> V_155 == V_2 -> V_62 . V_67 )
) &&
( ( F_35 ( & ( V_2 -> V_62 . system ) , & ( V_156 ) ) &&
! V_7 -> V_157 )
)
) {
V_2 -> V_7 = V_7 ;
V_2 -> V_152 =
V_2 -> V_7 -> V_153 ;
V_2 -> V_80 = V_7 -> V_79 ;
V_2 -> V_7 -> V_85 ++ ;
V_7 -> V_79 = V_2 ;
F_28 ( L_12 ,
V_2 -> V_28 ,
V_2 -> V_7 -> V_153 ) ;
V_2 -> V_58 |= V_73 ;
V_151 = 1 ;
break;
}
}
if ( ! V_151 ) {
if ( V_147 ) {
V_2 -> V_7 = V_147 ;
V_2 -> V_152 =
V_2 -> V_7 -> V_153 ;
if ( V_2 -> V_53 & V_133 )
V_2 -> V_7 -> V_157 = false ;
else
V_2 -> V_7 -> V_157 = true ;
V_2 -> V_7 -> V_158 = V_2 -> V_159 ;
V_2 -> V_7 -> V_154 = V_2 -> V_53 ;
V_2 -> V_7 -> V_9 =
V_2 -> V_62 . system ;
V_2 -> V_7 -> V_50 =
V_2 -> V_62 . V_66 ;
V_2 -> V_7 -> V_155 = V_2 -> V_62 . V_67 ;
V_2 -> V_7 -> V_160 = 1 ;
V_2 -> V_7 -> V_161 = 1 ;
V_2 -> V_7 -> V_79 = V_2 ;
V_2 -> V_7 -> V_85 ++ ;
V_2 -> V_58 |= V_73 ;
F_28 ( L_13 ,
V_2 -> V_28 ,
V_2 -> V_7 -> V_153 ) ;
} else {
F_60 ( L_14 ,
V_2 -> V_3 -> V_4 -> V_13 -> V_136 ,
V_2 -> V_28 , V_2 -> V_3 -> V_13 -> V_136 ) ;
}
}
F_44 ( V_2 -> V_7 , F_43 ( V_2 -> V_7 ) ) ;
V_7 = F_9 ( V_2 ) ;
F_66 ( V_7 ) ;
}
static struct V_7 * F_67 ( struct V_7 * V_162 ,
struct V_7 * V_163 )
{
if ( ! V_162 )
return V_163 ;
if ( ! V_163 -> V_157 && V_162 -> V_157 )
return V_163 ;
if ( V_163 -> V_157 && ! V_162 -> V_157 )
return V_162 ;
if ( F_11 ( V_163 ) && ! F_11 ( V_162 ) )
return V_163 ;
if ( ! F_11 ( V_163 ) && F_11 ( V_162 ) )
return V_162 ;
switch ( F_20 ( V_163 -> V_79 ) ) {
case V_164 :
if ( V_163 -> V_85 > V_162 -> V_85 )
return V_163 ;
if ( V_163 -> V_85 < V_162 -> V_85 )
return V_162 ;
case V_14 :
case V_165 :
if ( F_45 ( V_163 ) > F_45 ( V_162 ) )
return V_163 ;
break;
default:
F_65 ( L_15 ,
V_163 -> V_3 -> V_4 -> V_13 -> V_136 ,
F_20 ( V_163 -> V_79 ) ) ;
break;
}
return V_162 ;
}
static int F_68 ( const struct V_7 * V_8 )
{
struct V_2 * V_2 = V_8 -> V_79 ;
if ( ! V_2 )
return 0 ;
return ( F_69 ( V_2 -> V_3 -> V_13 ) &&
F_70 ( V_2 -> V_3 -> V_13 ) ) ;
}
static void F_66 ( struct V_7 * V_8 )
{
struct V_7 * V_162 , * V_166 , * V_167 ;
struct V_2 * V_2 ;
V_167 = V_8 ;
V_166 = F_46 ( V_8 ) ;
V_162 = ( V_166 && F_68 ( V_166 ) ) ? V_166 : NULL ;
do {
V_8 -> V_87 = 0 ;
if ( V_8 -> V_85 && F_68 ( V_8 ) )
V_162 = F_67 ( V_162 , V_8 ) ;
} while ( ( V_8 = F_10 ( V_8 ) ) );
if ( V_162 &&
F_20 ( V_162 -> V_79 ) == V_14 ) {
if ( V_166 && V_166 -> V_79 &&
V_166 -> V_79 -> V_124 &&
( F_11 ( V_166 ) ||
( ! F_11 ( V_166 ) && ! F_11 ( V_162 ) ) ) ) {
if ( ! ( ! V_166 -> V_154 &&
V_162 -> V_154 ) ) {
V_162 = NULL ;
V_166 -> V_87 = 1 ;
}
}
}
if ( V_162 && ( V_162 == V_166 ) ) {
V_162 = NULL ;
V_166 -> V_87 = 1 ;
}
if ( V_162 ) {
F_28 ( L_16 ,
V_162 -> V_153 , V_162 -> V_85 ,
V_162 -> V_154 ,
V_162 -> V_155 ,
V_162 -> V_157 , V_162 -> V_87 ) ;
F_28 ( L_17 ,
V_162 -> V_79 , V_162 -> V_3 ,
V_162 -> V_3 ? V_162 -> V_3 -> V_13 -> V_136 : L_18 ) ;
for ( V_8 = F_9 ( V_162 -> V_79 ) ; V_8 ;
V_8 = F_10 ( V_8 ) ) {
F_28 ( L_19 ,
V_8 -> V_153 , V_8 -> V_85 ,
V_8 -> V_154 ,
V_8 -> V_155 ,
V_8 -> V_157 , V_8 -> V_87 ) ;
}
if ( V_162 -> V_157 ) {
F_65 ( L_20 ,
V_162 -> V_3 ? V_162 -> V_3 -> V_4 -> V_13 -> V_136 : L_18 ) ;
}
V_162 -> V_87 = 1 ;
F_28 ( L_21 ,
V_162 -> V_153 ) ;
F_28 ( L_19 ,
V_162 -> V_153 , V_162 -> V_85 ,
V_162 -> V_154 ,
V_162 -> V_155 ,
V_162 -> V_157 , V_162 -> V_87 ) ;
if ( V_166 ) {
for ( V_2 = V_166 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
F_13 ( V_2 ) ;
}
}
}
V_166 = F_46 ( V_167 ) ;
if ( V_166 ) {
if ( ! F_11 ( V_166 ) ) {
for ( V_2 = V_166 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
F_15 ( V_2 ) ;
}
}
}
if ( V_167 -> V_3 ) {
struct V_1 * V_4 ;
V_4 = F_2 ( V_167 -> V_3 ) ;
if ( V_4 )
F_71 ( V_4 ) ;
}
}
static void F_64 ( struct V_7 * V_7 )
{
if ( V_7 ) {
V_7 -> V_157 = false ;
V_7 -> V_158 = 0 ;
V_7 -> V_154 = 0 ;
V_7 -> V_9 = V_156 ;
V_7 -> V_50 = 0 ;
V_7 -> V_155 = 0 ;
V_7 -> V_160 = 0 ;
V_7 -> V_161 = 0 ;
V_7 -> V_79 = NULL ;
V_7 -> V_87 = 0 ;
V_7 -> V_85 = 0 ;
F_28 ( L_22 ,
V_7 -> V_153 ) ;
}
}
static void F_72 ( struct V_7 * V_7 )
{
if ( V_7 ) {
F_64 ( V_7 ) ;
V_7 -> V_168 = V_156 ;
V_7 -> V_153 = 0 ;
V_7 -> V_3 = NULL ;
}
}
static void F_73 ( struct V_2 * V_2 , int V_169 )
{
static const struct V_60 V_170 = {
. V_66 = 0xffff ,
. V_67 = 1 ,
. V_63 = 1 ,
. V_65 = 0xff ,
. V_69 = 1 ,
} ;
static const struct V_45 V_45 = {
. V_171 = 0x01 ,
. V_172 = 0x01 ,
. V_173 = 0x01 ,
. V_174 = 0x14 ,
. V_175 = 0x02 ,
. V_176 = 0x14 ,
. V_177 = 0x03 ,
. V_178 = 0x10 ,
. V_179 = F_48 ( V_180 ) ,
} ;
if ( V_2 ) {
V_2 -> V_28 = 1 ;
V_2 -> V_48 = 0xff ;
V_2 -> V_49 = V_156 ;
V_2 -> V_51 = 0xffff ;
V_2 -> V_152 = 0 ;
V_2 -> V_78 = false ;
V_2 -> V_159 = 1 ;
V_2 -> V_53 = 1 ;
V_2 -> V_181 = V_55 | V_76 ;
V_2 -> V_56 = V_55 | V_76 ;
if ( V_169 )
V_2 -> V_56 |= V_77 ;
memcpy ( & V_2 -> V_72 , & V_170 , sizeof( V_170 ) ) ;
memcpy ( & V_2 -> V_62 , & V_170 , sizeof( V_170 ) ) ;
V_2 -> V_124 = true ;
V_2 -> V_58 = 0x3 ;
V_2 -> V_122 = 0 ;
V_2 -> V_130 = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_112 = 0 ;
V_2 -> V_117 = 0 ;
V_2 -> V_182 = 0 ;
V_2 -> V_137 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_80 = NULL ;
V_2 -> V_183 = 0 ;
memcpy ( & V_2 -> V_45 , & V_45 , sizeof( V_45 ) ) ;
}
}
static void F_58 ( struct V_2 * V_2 )
{
if ( V_2 -> V_7 -> V_87 ) {
F_28 ( L_23 ,
V_2 -> V_28 ,
V_2 -> V_7 -> V_153 ) ;
F_15 ( V_2 ) ;
}
}
static void F_57 ( struct V_2 * V_2 )
{
if ( V_2 -> V_7 && F_35 ( & ( V_2 -> V_7 -> V_9 ) , & ( V_156 ) ) ) {
F_28 ( L_24 ,
V_2 -> V_28 ,
V_2 -> V_7 -> V_153 ) ;
F_13 ( V_2 ) ;
}
}
static void F_74 ( struct V_107 * V_184 ,
struct V_2 * V_2 )
{
struct V_107 V_108 ;
memcpy ( & V_108 , V_184 , sizeof( struct V_107 ) ) ;
V_108 . V_185 = V_186 ;
if ( F_54 ( V_2 , & V_108 ) >= 0 ) {
F_28 ( L_25 ,
V_2 -> V_28 ) ;
}
}
static void F_75 ( struct V_107 * V_108 ,
struct V_2 * V_2 )
{
V_108 = NULL ;
V_2 = NULL ;
}
void F_76 ( struct V_1 * V_4 , int V_187 )
{
F_22 ( V_4 ) . V_17 = V_187 ;
}
void F_77 ( struct V_1 * V_4 , T_2 V_188 )
{
if ( F_35 ( & ( F_22 ( V_4 ) . system . V_189 ) ,
V_4 -> V_13 -> V_190 ) ) {
V_153 = 0 ;
F_22 ( V_4 ) . system . V_191 = 0xFFFF ;
F_22 ( V_4 ) . system . V_189 = * ( (struct V_192 * ) V_4 -> V_13 -> V_190 ) ;
V_37 = V_188 ;
F_76 ( V_4 ,
V_193 *
V_37 ) ;
}
}
int F_78 ( struct V_3 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_7 * V_7 ;
if ( V_4 == NULL ) {
F_60 ( L_26 ,
V_3 -> V_4 -> V_13 -> V_136 , V_3 -> V_13 -> V_136 ) ;
return - 1 ;
}
if ( F_5 ( V_3 ) . V_2 . V_3 != V_3 ) {
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
F_73 ( V_2 , V_4 -> V_15 . V_169 ) ;
F_30 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = F_5 ( V_3 ) . V_194 ;
V_2 -> V_159 = 0 ;
V_2 -> V_159 |= F_29 ( V_2 ) ;
V_2 -> V_159 |= ( F_27 ( V_2 ) << 1 ) ;
V_2 -> V_53 = V_2 -> V_159 ;
if ( ! ( V_2 -> V_53 & V_133 ) )
V_2 -> V_58 &= ~ V_131 ;
V_2 -> V_49 = F_22 ( V_4 ) . system . V_189 ;
V_2 -> V_137 = V_37 / V_138 ;
V_2 -> V_7 = NULL ;
V_2 -> V_80 = NULL ;
F_13 ( V_2 ) ;
V_7 = & ( F_5 ( V_3 ) . V_7 ) ;
F_72 ( V_7 ) ;
V_7 -> V_168 = * ( (struct V_192 * ) V_4 -> V_13 -> V_190 ) ;
V_7 -> V_153 = ( ++ V_153 ) ;
V_7 -> V_3 = V_3 ;
V_7 -> V_87 = 0 ;
V_7 -> V_85 = 0 ;
}
return 0 ;
}
void F_79 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_195 , * V_196 ;
struct V_7 * V_7 , * V_197 , * V_148 ;
int V_198 = 0 ;
V_7 = & ( F_5 ( V_3 ) . V_7 ) ;
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_65 ( L_27 ,
V_3 -> V_4 -> V_13 -> V_136 , V_3 -> V_13 -> V_136 ) ;
return;
}
F_28 ( L_28 ,
V_7 -> V_153 ) ;
V_2 -> V_56 &= ~ V_55 ;
F_47 ( V_2 ) ;
F_49 ( V_2 ) ;
if ( V_7 -> V_79 ) {
if ( ( V_7 -> V_79 != V_2 ) || ( V_7 -> V_79 -> V_80 ) ) {
V_197 = F_9 ( V_2 ) ;
for (; V_197 ; V_197 = F_10 ( V_197 ) ) {
if ( ! V_197 -> V_79
|| ( ( V_197 -> V_79 == V_2 )
&& ! V_197 -> V_79 -> V_80 ) )
break;
}
if ( ( V_197 ) && ( ( ! V_197 -> V_79 ) || ( ( V_197 -> V_79 == V_2 ) && ! V_197 -> V_79 -> V_80 ) ) ) {
F_28 ( L_29 ,
V_7 -> V_153 ,
V_197 -> V_153 ) ;
if ( ( V_197 -> V_79 == V_2 ) && V_197 -> V_87 ) {
F_80 ( L_30 ,
V_7 -> V_3 -> V_4 -> V_13 -> V_136 ) ;
V_198 = 1 ;
}
V_197 -> V_157 = V_7 -> V_157 ;
V_197 -> V_158 = V_7 -> V_158 ;
V_197 -> V_154 = V_7 -> V_154 ;
V_197 -> V_9 = V_7 -> V_9 ;
V_197 -> V_50 = V_7 -> V_50 ;
V_197 -> V_155 = V_7 -> V_155 ;
V_197 -> V_160 = V_7 -> V_160 ;
V_197 -> V_161 = V_7 -> V_161 ;
V_197 -> V_79 = V_7 -> V_79 ;
V_197 -> V_87 = V_7 -> V_87 ;
V_197 -> V_85 = V_7 -> V_85 ;
for ( V_196 = V_7 -> V_79 ; V_196 ;
V_196 = V_196 -> V_80 ) {
V_196 -> V_7 = V_197 ;
V_196 -> V_152 = V_197 -> V_153 ;
}
F_64 ( V_7 ) ;
if ( V_198 )
F_66 ( F_9 ( V_2 ) ) ;
} else {
F_65 ( L_31 ,
V_3 -> V_4 -> V_13 -> V_136 ) ;
}
} else {
V_198 = V_7 -> V_87 ;
F_64 ( V_7 ) ;
if ( V_198 ) {
F_80 ( L_30 ,
V_3 -> V_4 -> V_13 -> V_136 ) ;
F_66 ( F_9 ( V_2 ) ) ;
}
}
}
F_28 ( L_32 , V_2 -> V_28 ) ;
V_148 = F_9 ( V_2 ) ;
for (; V_148 ; V_148 = F_10 ( V_148 ) ) {
V_195 = NULL ;
for ( V_196 = V_148 -> V_79 ; V_196 ;
V_195 = V_196 ,
V_196 = V_196 -> V_80 ) {
if ( V_196 == V_2 ) {
if ( V_195 )
V_195 -> V_80 = V_196 -> V_80 ;
else
V_148 -> V_79 = V_196 -> V_80 ;
V_148 -> V_85 -- ;
if ( V_148 -> V_85 == 0 ) {
V_198 = V_148 -> V_87 ;
F_64 ( V_148 ) ;
if ( V_198 ) {
F_80 ( L_30 ,
V_3 -> V_4 -> V_13 -> V_136 ) ;
F_66 ( F_9 ( V_2 ) ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
}
void F_81 ( struct V_199 * V_200 )
{
struct V_1 * V_4 = F_82 ( V_200 , struct V_1 ,
V_201 . V_200 ) ;
struct V_2 * V_2 ;
struct V_7 * V_7 ;
F_83 ( & V_4 -> V_202 ) ;
if ( F_84 ( & V_4 -> V_203 ) )
goto V_204;
if ( F_22 ( V_4 ) . V_17 && ! ( -- F_22 ( V_4 ) . V_17 ) ) {
if ( ( V_2 = F_3 ( V_4 ) ) ) {
if ( ! V_2 -> V_3 ) {
F_65 ( L_33 ,
V_4 -> V_13 -> V_136 ) ;
goto V_204;
}
V_7 = F_9 ( V_2 ) ;
F_66 ( V_7 ) ;
}
F_71 ( V_4 ) ;
}
for ( V_2 = F_3 ( V_4 ) ; V_2 ; V_2 = F_6 ( V_2 ) ) {
if ( ! V_2 -> V_3 ) {
F_65 ( L_34 ,
V_4 -> V_13 -> V_136 ) ;
goto V_204;
}
F_23 ( V_2 ) ;
F_59 ( NULL , V_2 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_56 ( V_2 ) ;
F_61 ( V_2 ) ;
if ( V_2 -> V_58 & V_113 )
V_2 -> V_58 &= ~ V_113 ;
F_25 ( V_2 ) ;
}
V_204:
F_85 ( V_4 -> V_205 , & V_4 -> V_201 , V_206 ) ;
F_86 ( & V_4 -> V_202 ) ;
}
static int F_87 ( struct V_45 * V_45 , struct V_3 * V_3 , T_2 V_91 )
{
struct V_2 * V_2 ;
int V_207 = V_208 ;
if ( V_91 >= sizeof( struct V_45 ) ) {
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_65 ( L_35 ,
V_3 -> V_13 -> V_136 , V_3 -> V_4 -> V_13 -> V_136 ) ;
return V_207 ;
}
switch ( V_45 -> V_171 ) {
case V_209 :
V_207 = V_210 ;
F_28 ( L_36 ,
V_2 -> V_28 ) ;
F_23 ( V_2 ) ;
F_59 ( V_45 , V_2 ) ;
F_25 ( V_2 ) ;
break;
case V_211 :
V_207 = V_210 ;
switch ( ( (struct V_107 * ) V_45 ) -> V_185 ) {
case V_212 :
F_28 ( L_37 ,
V_2 -> V_28 ) ;
F_74 ( (struct V_107 * ) V_45 , V_2 ) ;
break;
case V_186 :
F_28 ( L_38 ,
V_2 -> V_28 ) ;
F_75 ( (struct V_107 * ) V_45 , V_2 ) ;
break;
default:
F_28 ( L_39 ,
V_2 -> V_28 ) ;
}
}
}
return V_207 ;
}
void F_88 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_65 ( L_40 ,
V_3 -> V_4 -> V_13 -> V_136 , V_3 -> V_13 -> V_136 ) ;
return;
}
V_2 -> V_159 &= ~ V_213 ;
V_2 -> V_53 = V_2 -> V_159 |=
( F_27 ( V_2 ) << 1 ) ;
F_28 ( L_41 , V_2 -> V_28 ) ;
V_2 -> V_58 |= V_113 ;
}
void F_89 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_65 ( L_42 ,
V_3 -> V_4 -> V_13 -> V_136 , V_3 -> V_13 -> V_136 ) ;
return;
}
V_2 -> V_159 &= ~ V_133 ;
V_2 -> V_53 = V_2 -> V_159 |=
F_29 ( V_2 ) ;
F_28 ( L_43 , V_2 -> V_28 ) ;
V_2 -> V_58 |= V_113 ;
}
void F_90 ( struct V_3 * V_3 , char V_11 )
{
struct V_2 * V_2 ;
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_65 ( L_44 ,
V_3 -> V_4 -> V_13 -> V_136 , V_3 -> V_13 -> V_136 ) ;
return;
}
if ( V_11 == V_12 ) {
V_2 -> V_124 = true ;
V_2 -> V_159 &= ~ V_133 ;
V_2 -> V_53 = V_2 -> V_159 |=
F_29 ( V_2 ) ;
V_2 -> V_159 &= ~ V_213 ;
V_2 -> V_53 = V_2 -> V_159 |=
( F_27 ( V_2 ) << 1 ) ;
} else {
V_2 -> V_124 = false ;
V_2 -> V_159 &= ~ V_133 ;
V_2 -> V_53 = ( V_2 -> V_159 &=
~ V_213 ) ;
}
V_2 -> V_58 |= V_113 ;
}
int F_71 ( struct V_1 * V_4 )
{
struct V_7 * V_166 ;
struct V_3 * V_5 ;
V_5 = F_4 ( V_4 ) ;
if ( ! V_5 )
return 0 ;
V_166 = F_46 ( & ( F_5 ( V_5 ) . V_7 ) ) ;
if ( V_166 ) {
if ( V_166 -> V_85 < V_4 -> V_15 . V_214 ) {
if ( F_70 ( V_4 -> V_13 ) ) {
F_91 ( V_4 -> V_13 ) ;
return 1 ;
}
} else if ( ! F_70 ( V_4 -> V_13 ) ) {
F_92 ( V_4 -> V_13 ) ;
return 1 ;
}
return 0 ;
}
if ( F_70 ( V_4 -> V_13 ) ) {
F_91 ( V_4 -> V_13 ) ;
return 1 ;
}
return 0 ;
}
int F_93 ( struct V_1 * V_4 ,
struct V_215 * V_215 )
{
struct V_7 * V_7 = NULL ;
struct V_2 * V_2 ;
for ( V_2 = F_3 ( V_4 ) ; V_2 ; V_2 = F_6 ( V_2 ) ) {
if ( V_2 -> V_7 && V_2 -> V_7 -> V_87 ) {
V_7 = V_2 -> V_7 ;
break;
}
}
if ( V_7 ) {
V_215 -> V_216 = V_7 -> V_153 ;
V_215 -> V_217 = V_7 -> V_85 ;
V_215 -> V_68 = V_7 -> V_154 ;
V_215 -> V_52 = V_7 -> V_155 ;
memcpy ( V_215 -> V_9 , V_7 -> V_9 . V_10 , V_103 ) ;
return 0 ;
}
return - 1 ;
}
int F_94 ( struct V_1 * V_4 , struct V_215 * V_215 )
{
int V_207 ;
F_83 ( & V_4 -> V_202 ) ;
V_207 = F_93 ( V_4 , V_215 ) ;
F_86 ( & V_4 -> V_202 ) ;
return V_207 ;
}
int F_95 ( struct V_88 * V_89 , struct V_218 * V_13 )
{
struct V_3 * V_3 , * V_219 ;
struct V_1 * V_4 = F_96 ( V_13 ) ;
int V_220 ;
int V_221 ;
int V_222 ;
int V_223 ;
struct V_215 V_215 ;
int V_224 = 1 ;
F_83 ( & V_4 -> V_202 ) ;
if ( F_93 ( V_4 , & V_215 ) ) {
F_28 ( L_45 ,
V_13 -> V_136 ) ;
goto V_225;
}
V_221 = V_215 . V_217 ;
V_222 = V_215 . V_216 ;
if ( V_221 == 0 ) {
F_28 ( L_46 , V_13 -> V_136 ) ;
goto V_225;
}
V_220 = V_4 -> V_226 ( V_89 , V_221 ) ;
F_97 (bond, slave) {
struct V_7 * V_8 = F_5 ( V_3 ) . V_2 . V_7 ;
if ( V_8 && ( V_8 -> V_153 == V_222 ) ) {
V_220 -- ;
if ( V_220 < 0 )
break;
}
}
if ( V_220 >= 0 ) {
F_60 ( L_47 ,
V_13 -> V_136 , V_222 ) ;
goto V_225;
}
V_219 = V_3 ;
F_98 (bond, slave, i, start_at) {
int V_227 = 0 ;
struct V_7 * V_8 = F_5 ( V_3 ) . V_2 . V_7 ;
if ( V_8 )
V_227 = V_8 -> V_153 ;
if ( F_99 ( V_3 ) && V_8 && ( V_227 == V_222 ) ) {
V_224 = F_100 ( V_4 , V_89 , V_3 -> V_13 ) ;
break;
}
}
V_225:
F_86 ( & V_4 -> V_202 ) ;
if ( V_224 ) {
F_101 ( V_89 ) ;
}
return V_228 ;
}
int F_102 ( const struct V_88 * V_89 , struct V_1 * V_4 ,
struct V_3 * V_3 )
{
int V_207 = V_208 ;
struct V_45 * V_45 , V_229 ;
if ( V_89 -> V_96 != V_97 )
return V_207 ;
V_45 = F_103 ( V_89 , 0 , sizeof( V_229 ) , & V_229 ) ;
if ( ! V_45 )
return V_207 ;
F_83 ( & V_4 -> V_202 ) ;
V_207 = F_87 ( V_45 , V_3 , V_89 -> V_230 ) ;
F_86 ( & V_4 -> V_202 ) ;
return V_207 ;
}
void F_104 ( struct V_1 * V_4 )
{
struct V_2 * V_2 = NULL ;
struct V_3 * V_3 ;
int V_169 ;
V_169 = V_4 -> V_15 . V_169 ;
F_97 (bond, slave) {
V_2 = & ( F_5 ( V_3 ) . V_2 ) ;
F_23 ( V_2 ) ;
if ( V_169 )
V_2 -> V_56 |= V_77 ;
else
V_2 -> V_56 &= ~ V_77 ;
F_25 ( V_2 ) ;
}
}
