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
V_7 = V_6 ? & ( F_6 ( V_6 ) . V_4 ) : NULL ;
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
if ( ( V_3 -> V_11 == V_12 ) && F_13 ( V_3 -> V_13 ) )
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
return V_14 ;
return V_5 -> V_15 . V_16 ;
}
static inline int F_18 ( struct V_2 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
if ( V_5 == NULL )
return 0 ;
return F_19 ( V_5 ) . V_17 ? 1 : 0 ;
}
static inline void F_20 ( struct V_2 * V_2 )
{
F_21 ( & ( F_6 ( V_2 -> V_3 ) . V_18 ) ) ;
}
static inline void F_22 ( struct V_2 * V_2 )
{
F_23 ( & ( F_6 ( V_2 -> V_3 ) . V_18 ) ) ;
}
static T_2 F_24 ( struct V_2 * V_2 )
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
F_25 ( L_1 ,
V_2 -> V_28 , V_19 ) ;
return V_19 ;
}
static T_3 F_26 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_29 ;
if ( V_3 -> V_11 != V_12 )
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
static inline void F_27 ( struct V_3 * V_3 )
{
F_28 ( & ( F_6 ( V_3 ) . V_18 ) ) ;
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
F_32 ( & ( V_45 -> V_8 ) , & ( V_2 -> V_49 ) ) &&
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
! F_32 ( & V_45 -> V_49 , & V_61 -> system ) ||
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
! F_32 ( & V_74 -> system , & V_75 -> system ) ||
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
! F_32 ( & ( V_45 -> V_8 ) , & ( V_2 -> V_49 ) ) ||
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
static int F_38 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_29 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_79 ;
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
static void F_39 ( struct V_4 * V_4 , int V_82 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
if ( V_82 )
V_2 -> V_58 |= V_83 ;
else
V_2 -> V_58 &= ~ V_83 ;
}
}
static T_1 F_40 ( struct V_4 * V_4 )
{
T_1 V_84 = 0 ;
if ( V_4 -> V_85 ) {
switch ( F_24 ( V_4 -> V_79 ) ) {
case V_86 :
V_84 = V_4 -> V_85 ;
break;
case V_21 :
V_84 = V_4 -> V_85 * 10 ;
break;
case V_23 :
V_84 = V_4 -> V_85 * 100 ;
break;
case V_25 :
V_84 = V_4 -> V_85 * 1000 ;
break;
case V_27 :
V_84 = V_4 -> V_85 * 10000 ;
break;
default:
V_84 = 0 ;
}
}
return V_84 ;
}
static struct V_4 * F_41 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
F_42 (bond, slave, iter)
if ( F_6 ( V_3 ) . V_4 . V_89 )
return & ( F_6 ( V_3 ) . V_4 ) ;
return NULL ;
}
static inline void F_43 ( struct V_2 * V_2 )
{
struct V_45 * V_45 = & V_2 -> V_45 ;
const struct V_60 * V_61 = & V_2 -> V_62 ;
V_45 -> V_51 = F_44 ( V_2 -> V_51 ) ;
V_45 -> V_49 = V_2 -> V_49 ;
V_45 -> V_68 = F_44 ( V_2 -> V_53 ) ;
V_45 -> V_48 = F_44 ( V_2 -> V_48 ) ;
V_45 -> V_64 = F_44 ( V_2 -> V_28 ) ;
V_45 -> V_57 = V_2 -> V_56 ;
V_45 -> V_50 = F_44 ( V_61 -> V_66 ) ;
V_45 -> V_8 = V_61 -> system ;
V_45 -> V_52 = F_44 ( V_61 -> V_67 ) ;
V_45 -> V_47 = F_44 ( V_61 -> V_65 ) ;
V_45 -> V_46 = F_44 ( V_61 -> V_63 ) ;
V_45 -> V_54 = V_61 -> V_69 ;
}
static int F_45 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_90 * V_91 ;
struct V_92 * V_92 ;
int V_93 = sizeof( struct V_92 ) ;
V_91 = F_46 ( V_93 ) ;
if ( ! V_91 )
return - V_94 ;
V_91 -> V_13 = V_3 -> V_13 ;
F_47 ( V_91 ) ;
V_91 -> V_95 = V_91 -> V_96 + V_97 ;
V_91 -> V_98 = V_99 ;
V_91 -> V_100 = V_101 ;
V_92 = (struct V_92 * ) F_48 ( V_91 , V_93 ) ;
memcpy ( V_92 -> V_102 . V_103 , V_104 , V_105 ) ;
memcpy ( V_92 -> V_102 . V_106 , V_3 -> V_107 , V_105 ) ;
V_92 -> V_102 . V_108 = V_99 ;
V_92 -> V_45 = V_2 -> V_45 ;
F_49 ( V_91 ) ;
return 0 ;
}
static int F_50 ( struct V_2 * V_2 , struct V_109 * V_110 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_90 * V_91 ;
struct V_111 * V_112 ;
int V_93 = sizeof( struct V_111 ) ;
V_91 = F_46 ( V_93 + 16 ) ;
if ( ! V_91 )
return - V_94 ;
F_51 ( V_91 , 16 ) ;
V_91 -> V_13 = V_3 -> V_13 ;
F_47 ( V_91 ) ;
V_91 -> V_95 = V_91 -> V_96 + V_97 ;
V_91 -> V_98 = V_99 ;
V_112 = (struct V_111 * ) F_48 ( V_91 , V_93 ) ;
memcpy ( V_112 -> V_102 . V_103 , V_104 , V_105 ) ;
memcpy ( V_112 -> V_102 . V_106 , V_3 -> V_107 , V_105 ) ;
V_112 -> V_102 . V_108 = V_99 ;
V_112 -> V_110 = * V_110 ;
F_49 ( V_91 ) ;
return 0 ;
}
static void F_52 ( struct V_2 * V_2 )
{
T_4 V_113 ;
V_113 = V_2 -> V_114 ;
if ( V_2 -> V_58 & V_115 ) {
V_2 -> V_114 = V_116 ;
} else {
switch ( V_2 -> V_114 ) {
case V_116 :
if ( ( V_2 -> V_58 & V_73 )
|| ( V_2 -> V_58 & V_117 ) )
V_2 -> V_114 = V_118 ;
break;
case V_118 :
if ( ! ( V_2 -> V_58 & V_73 ) ) {
V_2 -> V_58 &= ~ V_81 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
V_2 -> V_114 = V_116 ;
break;
}
if ( V_2 -> V_119
&& ! ( -- V_2 -> V_119 ) )
V_2 -> V_58 |= V_81 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_58 & V_83 )
&& ! V_2 -> V_119 )
V_2 -> V_114 = V_120 ;
break;
case V_120 :
if ( ( V_2 -> V_58 & V_73 ) &&
( V_2 -> V_62 . V_69 & V_71 ) &&
! F_18 ( V_2 ) ) {
V_2 -> V_114 = V_121 ;
} else if ( ! ( V_2 -> V_58 & V_73 ) ||
( V_2 -> V_58 & V_117 ) ) {
V_2 -> V_58 &= ~ V_81 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
V_2 -> V_114 = V_116 ;
}
break;
case V_121 :
if ( ! ( V_2 -> V_58 & V_73 ) ||
( V_2 -> V_58 & V_117 ) ||
! ( V_2 -> V_62 . V_69 & V_71 ) ) {
V_2 -> V_114 = V_120 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_89 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_114 != V_113 ) {
F_25 ( L_4 ,
V_2 -> V_28 , V_113 ,
V_2 -> V_114 ) ;
switch ( V_2 -> V_114 ) {
case V_116 :
V_2 -> V_56 &= ~ V_71 ;
F_53 ( V_2 ) ;
V_2 -> V_56 &= ~ V_122 ;
V_2 -> V_56 &= ~ V_123 ;
V_2 -> V_78 = true ;
break;
case V_118 :
V_2 -> V_119 = F_29 ( V_43 , 0 ) ;
break;
case V_120 :
V_2 -> V_56 |= V_71 ;
V_2 -> V_56 &= ~ V_122 ;
V_2 -> V_56 &= ~ V_123 ;
F_53 ( V_2 ) ;
V_2 -> V_78 = true ;
break;
case V_121 :
V_2 -> V_56 |= V_122 ;
V_2 -> V_56 |= V_123 ;
F_54 ( V_2 ) ;
V_2 -> V_78 = true ;
break;
default:
break;
}
}
}
static void F_55 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
T_5 V_113 ;
V_113 = V_2 -> V_124 ;
if ( V_2 -> V_58 & V_115 )
V_2 -> V_124 = V_125 ;
else if ( ! ( V_2 -> V_58 & V_115 )
&& ! V_2 -> V_126 && ! ( V_2 -> V_58 & V_127 ) )
V_2 -> V_124 = V_128 ;
else if ( V_45 && ( ( V_2 -> V_124 == V_129 ) ||
( V_2 -> V_124 == V_130 ) ||
( V_2 -> V_124 == V_131 ) ) ) {
V_2 -> V_132 = 0 ;
V_2 -> V_124 = V_131 ;
} else {
if ( V_2 -> V_132 &&
! ( -- V_2 -> V_132 ) ) {
switch ( V_2 -> V_124 ) {
case V_129 :
V_2 -> V_124 = V_130 ;
break;
case V_131 :
V_2 -> V_124 = V_129 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_124 ) {
case V_128 :
if ( V_2 -> V_58 & V_127 )
V_2 -> V_124 = V_125 ;
else if ( V_2 -> V_126
&& ( V_2 -> V_58
& V_133 ) )
V_2 -> V_124 = V_129 ;
else if ( V_2 -> V_126
&& ( ( V_2 -> V_58
& V_133 ) == 0 ) )
V_2 -> V_124 = V_134 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_124 != V_113 ) || ( V_45 ) ) {
F_25 ( L_5 ,
V_2 -> V_28 , V_113 ,
V_2 -> V_124 ) ;
switch ( V_2 -> V_124 ) {
case V_125 :
if ( ! ( V_2 -> V_53 & V_135 ) )
V_2 -> V_58 &= ~ V_133 ;
else
V_2 -> V_58 |= V_133 ;
V_2 -> V_58 &= ~ V_73 ;
F_34 ( V_2 ) ;
V_2 -> V_56 &= ~ V_136 ;
V_2 -> V_58 &= ~ V_127 ;
V_2 -> V_124 = V_128 ;
case V_128 :
V_2 -> V_58 &= ~ V_59 ;
break;
case V_134 :
V_2 -> V_58 &= ~ V_73 ;
F_34 ( V_2 ) ;
V_2 -> V_62 . V_69 &= ~ V_55 ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_56 &= ~ V_136 ;
break;
case V_129 :
V_2 -> V_62 . V_69 &= ~ V_71 ;
V_2 -> V_58 &= ~ V_59 ;
V_2 -> V_62 . V_69 |= V_76 ;
V_2 -> V_132 = F_29 ( V_35 , ( T_2 ) ( V_137 ) ) ;
V_2 -> V_56 |= V_136 ;
break;
case V_130 :
F_36 ( V_2 ) ;
F_34 ( V_2 ) ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_56 &= ~ V_136 ;
break;
case V_131 :
if ( F_32 ( & ( V_45 -> V_49 ) ,
& ( V_2 -> V_49 ) ) ) {
F_56 ( L_6 ,
V_2 -> V_3 -> V_5 -> V_13 -> V_138 ,
V_2 -> V_3 -> V_13 -> V_138 ) ;
return;
}
F_35 ( V_45 , V_2 ) ;
F_37 ( V_45 , V_2 ) ;
F_33 ( V_45 , V_2 ) ;
V_2 -> V_132 = F_29 ( V_35 , ( T_2 ) ( V_2 -> V_56 & V_77 ) ) ;
V_2 -> V_56 &= ~ V_136 ;
break;
default:
break;
}
}
}
static void F_57 ( struct V_2 * V_2 )
{
if ( V_2 -> V_139 && ! ( -- V_2 -> V_139 ) ) {
if ( V_2 -> V_78 && ( V_2 -> V_58 & V_133 ) ) {
F_43 ( V_2 ) ;
if ( F_45 ( V_2 ) >= 0 ) {
F_25 ( L_7 ,
V_2 -> V_28 ) ;
V_2 -> V_78 = false ;
}
}
V_2 -> V_139 = V_37 / V_140 ;
}
}
static void F_58 ( struct V_2 * V_2 )
{
T_6 V_113 ;
V_113 = V_2 -> V_141 ;
if ( ( ( V_2 -> V_58 & V_115 ) || ! ( V_2 -> V_58 & V_133 ) || ! V_2 -> V_126 ) ||
( ! ( V_2 -> V_56 & V_76 ) && ! ( V_2 -> V_62 . V_69 & V_76 ) )
) {
V_2 -> V_141 = V_142 ;
}
else if ( V_2 -> V_143 ) {
if ( ! ( -- V_2 -> V_143 ) ) {
V_2 -> V_141 = V_144 ;
} else {
switch ( V_2 -> V_141 ) {
case V_145 :
if ( ! ( V_2 -> V_62 . V_69
& V_77 ) )
V_2 -> V_141 = V_146 ;
break;
case V_146 :
if ( ( V_2 -> V_62 . V_69 & V_77 ) ) {
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
if ( ! ( V_2 -> V_62 . V_69 &
V_77 ) )
V_2 -> V_141 = V_146 ;
else
V_2 -> V_141 = V_145 ;
break;
default:
break;
}
}
if ( V_2 -> V_141 != V_113 ) {
F_25 ( L_8 ,
V_2 -> V_28 , V_113 ,
V_2 -> V_141 ) ;
switch ( V_2 -> V_141 ) {
case V_142 :
V_2 -> V_143 = 0 ;
break;
case V_145 :
V_2 -> V_143 = F_29 ( V_41 , ( T_2 ) ( V_147 ) ) - 1 ;
break;
case V_146 :
V_2 -> V_143 = F_29 ( V_41 , ( T_2 ) ( V_148 ) ) - 1 ;
break;
case V_144 :
V_2 -> V_78 = true ;
break;
default:
break;
}
}
}
static void F_59 ( struct V_2 * V_2 )
{
struct V_4 * V_4 , * V_149 = NULL , * V_150 ;
struct V_2 * V_151 = NULL , * V_152 ;
struct V_87 * V_88 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_153 = 0 ;
if ( V_2 -> V_58 & V_73 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_150 = V_2 -> V_4 ;
for ( V_152 = V_150 -> V_79 ; V_152 ;
V_151 = V_152 ,
V_152 = V_152 -> V_80 ) {
if ( V_152 == V_2 ) {
V_150 -> V_85 -- ;
if ( ! V_151 ) {
V_150 -> V_79 =
V_2 -> V_80 ;
} else {
V_151 -> V_80 =
V_2 -> V_80 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_80 = NULL ;
V_2 -> V_154 = 0 ;
F_25 ( L_9 ,
V_2 -> V_28 ,
V_150 -> V_155 ) ;
if ( ! V_150 -> V_79 )
F_60 ( V_150 ) ;
break;
}
}
if ( ! V_152 ) {
F_61 ( L_10 ,
V_2 -> V_3 -> V_5 -> V_13 -> V_138 ,
V_2 -> V_28 ,
V_2 -> V_3 -> V_13 -> V_138 ,
V_2 -> V_4 -> V_155 ) ;
}
}
F_62 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) . V_4 ) ;
if ( ! V_4 -> V_79 ) {
if ( ! V_149 )
V_149 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_156 == V_2 -> V_53 ) &&
F_32 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_62 . system ) ) &&
( V_4 -> V_50 == V_2 -> V_62 . V_66 ) &&
( V_4 -> V_157 == V_2 -> V_62 . V_67 )
) &&
( ( ! F_32 ( & ( V_2 -> V_62 . system ) , & ( V_158 ) ) &&
! V_4 -> V_159 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_154 =
V_2 -> V_4 -> V_155 ;
V_2 -> V_80 = V_4 -> V_79 ;
V_2 -> V_4 -> V_85 ++ ;
V_4 -> V_79 = V_2 ;
F_25 ( L_11 ,
V_2 -> V_28 ,
V_2 -> V_4 -> V_155 ) ;
V_2 -> V_58 |= V_73 ;
V_153 = 1 ;
break;
}
}
if ( ! V_153 ) {
if ( V_149 ) {
V_2 -> V_4 = V_149 ;
V_2 -> V_154 =
V_2 -> V_4 -> V_155 ;
if ( V_2 -> V_53 & V_135 )
V_2 -> V_4 -> V_159 = false ;
else
V_2 -> V_4 -> V_159 = true ;
V_2 -> V_4 -> V_160 = V_2 -> V_161 ;
V_2 -> V_4 -> V_156 = V_2 -> V_53 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_62 . system ;
V_2 -> V_4 -> V_50 =
V_2 -> V_62 . V_66 ;
V_2 -> V_4 -> V_157 = V_2 -> V_62 . V_67 ;
V_2 -> V_4 -> V_162 = 1 ;
V_2 -> V_4 -> V_163 = 1 ;
V_2 -> V_4 -> V_79 = V_2 ;
V_2 -> V_4 -> V_85 ++ ;
V_2 -> V_58 |= V_73 ;
F_25 ( L_12 ,
V_2 -> V_28 ,
V_2 -> V_4 -> V_155 ) ;
} else {
F_56 ( L_13 ,
V_2 -> V_3 -> V_5 -> V_13 -> V_138 ,
V_2 -> V_28 , V_2 -> V_3 -> V_13 -> V_138 ) ;
}
}
F_39 ( V_2 -> V_4 ,
F_38 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_63 ( V_4 ) ;
}
static struct V_4 * F_64 ( struct V_4 * V_164 ,
struct V_4 * V_165 )
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
switch ( F_17 ( V_165 -> V_79 ) ) {
case V_166 :
if ( V_165 -> V_85 > V_164 -> V_85 )
return V_165 ;
if ( V_165 -> V_85 < V_164 -> V_85 )
return V_164 ;
case V_14 :
case V_167 :
if ( F_40 ( V_165 ) > F_40 ( V_164 ) )
return V_165 ;
break;
default:
F_61 ( L_14 ,
V_165 -> V_3 -> V_5 -> V_13 -> V_138 ,
F_17 ( V_165 -> V_79 ) ) ;
break;
}
return V_164 ;
}
static int F_65 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_79 ;
if ( ! V_2 )
return 0 ;
return F_66 ( V_2 -> V_3 -> V_13 ) &&
F_67 ( V_2 -> V_3 -> V_13 ) ;
}
static void F_63 ( struct V_4 * V_7 )
{
struct V_4 * V_164 , * V_168 , * V_169 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_169 = V_7 ;
V_168 = F_41 ( V_7 ) ;
V_164 = ( V_168 && F_65 ( V_168 ) ) ? V_168 : NULL ;
F_42 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) . V_4 ) ;
V_7 -> V_89 = 0 ;
if ( V_7 -> V_85 && F_65 ( V_7 ) )
V_164 = F_64 ( V_164 , V_7 ) ;
}
if ( V_164 &&
F_17 ( V_164 -> V_79 ) == V_14 ) {
if ( V_168 && V_168 -> V_79 &&
V_168 -> V_79 -> V_126 &&
( F_8 ( V_168 ) ||
( ! F_8 ( V_168 ) &&
! F_8 ( V_164 ) ) ) ) {
if ( ! ( ! V_168 -> V_156 &&
V_164 -> V_156 ) ) {
V_164 = NULL ;
V_168 -> V_89 = 1 ;
}
}
}
if ( V_164 && ( V_164 == V_168 ) ) {
V_164 = NULL ;
V_168 -> V_89 = 1 ;
}
if ( V_164 ) {
F_25 ( L_15 ,
V_164 -> V_155 , V_164 -> V_85 ,
V_164 -> V_156 ,
V_164 -> V_157 ,
V_164 -> V_159 , V_164 -> V_89 ) ;
F_25 ( L_16 ,
V_164 -> V_79 , V_164 -> V_3 ,
V_164 -> V_3 ? V_164 -> V_3 -> V_13 -> V_138 : L_17 ) ;
F_42 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) . V_4 ) ;
F_25 ( L_18 ,
V_7 -> V_155 , V_7 -> V_85 ,
V_7 -> V_156 ,
V_7 -> V_157 ,
V_7 -> V_159 , V_7 -> V_89 ) ;
}
if ( V_164 -> V_159 ) {
F_61 ( L_19 ,
V_164 -> V_3 ?
V_164 -> V_3 -> V_5 -> V_13 -> V_138 : L_17 ) ;
}
V_164 -> V_89 = 1 ;
F_25 ( L_20 ,
V_164 -> V_155 ) ;
F_25 ( L_18 ,
V_164 -> V_155 , V_164 -> V_85 ,
V_164 -> V_156 ,
V_164 -> V_157 ,
V_164 -> V_159 , V_164 -> V_89 ) ;
if ( V_168 ) {
for ( V_2 = V_168 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
F_10 ( V_2 ) ;
}
}
}
V_168 = F_41 ( V_169 ) ;
if ( V_168 ) {
if ( ! F_8 ( V_168 ) ) {
for ( V_2 = V_168 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
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
V_4 -> V_159 = false ;
V_4 -> V_160 = 0 ;
V_4 -> V_156 = 0 ;
V_4 -> V_8 = V_158 ;
V_4 -> V_50 = 0 ;
V_4 -> V_157 = 0 ;
V_4 -> V_162 = 0 ;
V_4 -> V_163 = 0 ;
V_4 -> V_79 = NULL ;
V_4 -> V_89 = 0 ;
V_4 -> V_85 = 0 ;
F_25 ( L_21 ,
V_4 -> V_155 ) ;
}
}
static void F_69 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_60 ( V_4 ) ;
V_4 -> V_170 = V_158 ;
V_4 -> V_155 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_70 ( struct V_2 * V_2 , int V_171 )
{
static const struct V_60 V_172 = {
. V_66 = 0xffff ,
. V_67 = 1 ,
. V_63 = 1 ,
. V_65 = 0xff ,
. V_69 = 1 ,
} ;
static const struct V_45 V_45 = {
. V_173 = 0x01 ,
. V_174 = 0x01 ,
. V_175 = 0x01 ,
. V_176 = 0x14 ,
. V_177 = 0x02 ,
. V_178 = 0x14 ,
. V_179 = 0x03 ,
. V_180 = 0x10 ,
. V_181 = F_44 ( V_182 ) ,
} ;
if ( V_2 ) {
V_2 -> V_28 = 1 ;
V_2 -> V_48 = 0xff ;
V_2 -> V_49 = V_158 ;
V_2 -> V_51 = 0xffff ;
V_2 -> V_154 = 0 ;
V_2 -> V_78 = false ;
V_2 -> V_161 = 1 ;
V_2 -> V_53 = 1 ;
V_2 -> V_183 = V_55 |
V_76 ;
V_2 -> V_56 = V_55 |
V_76 ;
if ( V_171 )
V_2 -> V_56 |= V_77 ;
memcpy ( & V_2 -> V_72 , & V_172 , sizeof( V_172 ) ) ;
memcpy ( & V_2 -> V_62 , & V_172 , sizeof( V_172 ) ) ;
V_2 -> V_126 = true ;
V_2 -> V_58 = 0x3 ;
V_2 -> V_124 = 0 ;
V_2 -> V_132 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_143 = 0 ;
V_2 -> V_114 = 0 ;
V_2 -> V_119 = 0 ;
V_2 -> V_184 = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_80 = NULL ;
V_2 -> V_185 = 0 ;
memcpy ( & V_2 -> V_45 , & V_45 , sizeof( V_45 ) ) ;
}
}
static void F_54 ( struct V_2 * V_2 )
{
if ( V_2 -> V_4 -> V_89 ) {
F_25 ( L_22 ,
V_2 -> V_28 ,
V_2 -> V_4 -> V_155 ) ;
F_12 ( V_2 ) ;
}
}
static void F_53 ( struct V_2 * V_2 )
{
if ( V_2 -> V_4 &&
! F_32 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_158 ) ) ) {
F_25 ( L_23 ,
V_2 -> V_28 ,
V_2 -> V_4 -> V_155 ) ;
F_10 ( V_2 ) ;
}
}
static void F_71 ( struct V_109 * V_186 ,
struct V_2 * V_2 )
{
struct V_109 V_110 ;
memcpy ( & V_110 , V_186 , sizeof( struct V_109 ) ) ;
V_110 . V_187 = V_188 ;
if ( F_50 ( V_2 , & V_110 ) >= 0 ) {
F_25 ( L_24 ,
V_2 -> V_28 ) ;
}
}
static void F_72 ( struct V_109 * V_110 ,
struct V_2 * V_2 )
{
V_110 = NULL ;
V_2 = NULL ;
}
void F_73 ( struct V_1 * V_5 , int V_189 )
{
F_19 ( V_5 ) . V_17 = V_189 ;
}
void F_74 ( struct V_1 * V_5 , T_2 V_190 )
{
if ( ! F_32 ( & ( F_19 ( V_5 ) . system . V_191 ) ,
V_5 -> V_13 -> V_192 ) ) {
F_19 ( V_5 ) . V_155 = 0 ;
F_19 ( V_5 ) . system . V_193 = 0xFFFF ;
F_19 ( V_5 ) . system . V_191 = * ( (struct V_194 * ) V_5 -> V_13 -> V_192 ) ;
V_37 = V_190 ;
F_73 ( V_5 ,
V_195 *
V_37 ) ;
}
}
void F_75 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) . V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
F_70 ( V_2 , V_5 -> V_15 . V_171 ) ;
F_27 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = F_6 ( V_3 ) . V_196 ;
V_2 -> V_161 = 0 ;
V_2 -> V_161 |= F_26 ( V_2 ) ;
V_2 -> V_161 |= ( F_24 ( V_2 ) << 1 ) ;
V_2 -> V_53 = V_2 -> V_161 ;
if ( ! ( V_2 -> V_53 & V_135 ) )
V_2 -> V_58 &= ~ V_133 ;
V_2 -> V_49 = F_19 ( V_5 ) . system . V_191 ;
V_2 -> V_139 = V_37 / V_140 ;
V_2 -> V_4 = NULL ;
V_2 -> V_80 = NULL ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) . V_4 ) ;
F_69 ( V_4 ) ;
V_4 -> V_170 = * ( (struct V_194 * ) V_5 -> V_13 -> V_192 ) ;
V_4 -> V_155 = ++ F_19 ( V_5 ) . V_155 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_89 = 0 ;
V_4 -> V_85 = 0 ;
}
}
void F_76 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_197 , * V_198 ;
struct V_4 * V_4 , * V_199 , * V_150 ;
int V_200 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_201 ;
struct V_87 * V_88 ;
V_4 = & ( F_6 ( V_3 ) . V_4 ) ;
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_25 ,
V_3 -> V_5 -> V_13 -> V_138 , V_3 -> V_13 -> V_138 ) ;
return;
}
F_25 ( L_26 ,
V_4 -> V_155 ) ;
V_2 -> V_56 &= ~ V_55 ;
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
if ( V_4 -> V_79 ) {
if ( ( V_4 -> V_79 != V_2 ) ||
( V_4 -> V_79 -> V_80 ) ) {
F_62 (bond, slave_iter, iter) {
V_199 = & ( F_6 ( V_201 ) . V_4 ) ;
if ( ! V_199 -> V_79 ||
( ( V_199 -> V_79 == V_2 ) &&
! V_199 -> V_79 -> V_80 ) )
break;
}
if ( ! V_201 )
V_199 = NULL ;
if ( ( V_199 ) && ( ( ! V_199 -> V_79 ) || ( ( V_199 -> V_79 == V_2 ) && ! V_199 -> V_79 -> V_80 ) ) ) {
F_25 ( L_27 ,
V_4 -> V_155 ,
V_199 -> V_155 ) ;
if ( ( V_199 -> V_79 == V_2 ) &&
V_199 -> V_89 ) {
F_77 ( L_28 ,
V_4 -> V_3 -> V_5 -> V_13 -> V_138 ) ;
V_200 = 1 ;
}
V_199 -> V_159 = V_4 -> V_159 ;
V_199 -> V_160 = V_4 -> V_160 ;
V_199 -> V_156 = V_4 -> V_156 ;
V_199 -> V_8 = V_4 -> V_8 ;
V_199 -> V_50 = V_4 -> V_50 ;
V_199 -> V_157 = V_4 -> V_157 ;
V_199 -> V_162 = V_4 -> V_162 ;
V_199 -> V_163 = V_4 -> V_163 ;
V_199 -> V_79 = V_4 -> V_79 ;
V_199 -> V_89 = V_4 -> V_89 ;
V_199 -> V_85 = V_4 -> V_85 ;
for ( V_198 = V_4 -> V_79 ; V_198 ;
V_198 = V_198 -> V_80 ) {
V_198 -> V_4 = V_199 ;
V_198 -> V_154 = V_199 -> V_155 ;
}
F_60 ( V_4 ) ;
if ( V_200 )
F_63 ( F_3 ( V_2 ) ) ;
} else {
F_61 ( L_29 ,
V_3 -> V_5 -> V_13 -> V_138 ) ;
}
} else {
V_200 = V_4 -> V_89 ;
F_60 ( V_4 ) ;
if ( V_200 ) {
F_77 ( L_28 ,
V_3 -> V_5 -> V_13 -> V_138 ) ;
V_150 = F_3 ( V_2 ) ;
if ( V_150 )
F_63 ( V_150 ) ;
}
}
}
F_25 ( L_30 , V_2 -> V_28 ) ;
F_62 (bond, slave_iter, iter) {
V_150 = & ( F_6 ( V_201 ) . V_4 ) ;
V_197 = NULL ;
for ( V_198 = V_150 -> V_79 ; V_198 ;
V_197 = V_198 ,
V_198 = V_198 -> V_80 ) {
if ( V_198 == V_2 ) {
if ( V_197 )
V_197 -> V_80 = V_198 -> V_80 ;
else
V_150 -> V_79 = V_198 -> V_80 ;
V_150 -> V_85 -- ;
if ( V_150 -> V_85 == 0 ) {
V_200 = V_150 -> V_89 ;
F_60 ( V_150 ) ;
if ( V_200 ) {
F_77 ( L_28 ,
V_3 -> V_5 -> V_13 -> V_138 ) ;
F_63 ( F_3 ( V_2 ) ) ;
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
struct V_1 * V_5 = F_79 ( V_203 , struct V_1 ,
V_204 . V_203 ) ;
struct V_4 * V_4 ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_205 = V_10 ;
F_80 ( & V_5 -> V_206 ) ;
F_4 () ;
if ( ! F_81 ( V_5 ) )
goto V_207;
if ( F_19 ( V_5 ) . V_17 &&
! ( -- F_19 ( V_5 ) . V_17 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) . V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_61 ( L_31 ,
V_5 -> V_13 -> V_138 ) ;
goto V_207;
}
V_4 = F_3 ( V_2 ) ;
F_63 ( V_4 ) ;
}
F_68 ( V_5 ) ;
}
F_42 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_32 ,
V_5 -> V_13 -> V_138 ) ;
goto V_207;
}
F_20 ( V_2 ) ;
F_55 ( NULL , V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_52 ( V_2 ) ;
F_57 ( V_2 ) ;
if ( V_2 -> V_58 & V_115 )
V_2 -> V_58 &= ~ V_115 ;
F_22 ( V_2 ) ;
}
V_207:
F_42 (bond, slave, iter) {
if ( V_3 -> V_208 ) {
V_205 = V_209 ;
break;
}
}
F_7 () ;
F_82 ( & V_5 -> V_206 ) ;
if ( V_205 && F_83 () ) {
F_84 ( V_5 ) ;
F_85 () ;
}
F_86 ( V_5 -> V_210 , & V_5 -> V_204 , V_211 ) ;
}
static int F_87 ( struct V_45 * V_45 , struct V_3 * V_3 ,
T_2 V_93 )
{
struct V_2 * V_2 ;
int V_212 = V_213 ;
if ( V_93 >= sizeof( struct V_45 ) ) {
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_33 ,
V_3 -> V_13 -> V_138 , V_3 -> V_5 -> V_13 -> V_138 ) ;
return V_212 ;
}
switch ( V_45 -> V_173 ) {
case V_214 :
V_212 = V_215 ;
F_25 ( L_34 ,
V_2 -> V_28 ) ;
F_20 ( V_2 ) ;
F_55 ( V_45 , V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_216 :
V_212 = V_215 ;
switch ( ( (struct V_109 * ) V_45 ) -> V_187 ) {
case V_217 :
F_25 ( L_35 ,
V_2 -> V_28 ) ;
F_71 ( (struct V_109 * ) V_45 , V_2 ) ;
break;
case V_188 :
F_25 ( L_36 ,
V_2 -> V_28 ) ;
F_72 ( (struct V_109 * ) V_45 , V_2 ) ;
break;
default:
F_25 ( L_37 ,
V_2 -> V_28 ) ;
}
}
}
return V_212 ;
}
void F_88 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_38 ,
V_3 -> V_5 -> V_13 -> V_138 , V_3 -> V_13 -> V_138 ) ;
return;
}
F_20 ( V_2 ) ;
V_2 -> V_161 &= ~ V_218 ;
V_2 -> V_53 = V_2 -> V_161 |=
( F_24 ( V_2 ) << 1 ) ;
F_25 ( L_39 , V_2 -> V_28 ) ;
V_2 -> V_58 |= V_115 ;
F_22 ( V_2 ) ;
}
void F_89 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_40 ,
V_3 -> V_5 -> V_13 -> V_138 , V_3 -> V_13 -> V_138 ) ;
return;
}
F_20 ( V_2 ) ;
V_2 -> V_161 &= ~ V_135 ;
V_2 -> V_53 = V_2 -> V_161 |=
F_26 ( V_2 ) ;
F_25 ( L_41 , V_2 -> V_28 ) ;
V_2 -> V_58 |= V_115 ;
F_22 ( V_2 ) ;
}
void F_90 ( struct V_3 * V_3 , char V_11 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_61 ( L_42 ,
V_3 -> V_5 -> V_13 -> V_138 , V_3 -> V_13 -> V_138 ) ;
return;
}
F_20 ( V_2 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_126 = true ;
V_2 -> V_161 &= ~ V_135 ;
V_2 -> V_53 = V_2 -> V_161 |=
F_26 ( V_2 ) ;
V_2 -> V_161 &= ~ V_218 ;
V_2 -> V_53 = V_2 -> V_161 |=
( F_24 ( V_2 ) << 1 ) ;
} else {
V_2 -> V_126 = false ;
V_2 -> V_161 &= ~ V_135 ;
V_2 -> V_53 = ( V_2 -> V_161 &=
~ V_218 ) ;
}
F_25 ( L_43 ,
V_2 -> V_28 ,
( V_11 == V_12 ) ? L_44 : L_45 ) ;
V_2 -> V_58 |= V_115 ;
F_22 ( V_2 ) ;
}
int F_68 ( struct V_1 * V_5 )
{
struct V_4 * V_168 ;
struct V_3 * V_6 ;
int V_212 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_212 = 0 ;
goto V_219;
}
V_168 = F_41 ( & ( F_6 ( V_6 ) . V_4 ) ) ;
if ( V_168 ) {
if ( V_168 -> V_85 < V_5 -> V_15 . V_220 ) {
if ( F_67 ( V_5 -> V_13 ) ) {
F_91 ( V_5 -> V_13 ) ;
goto V_219;
}
} else if ( ! F_67 ( V_5 -> V_13 ) ) {
F_92 ( V_5 -> V_13 ) ;
goto V_219;
}
} else if ( F_67 ( V_5 -> V_13 ) ) {
F_91 ( V_5 -> V_13 ) ;
}
V_219:
F_7 () ;
return V_212 ;
}
int F_93 ( struct V_1 * V_5 ,
struct V_221 * V_221 )
{
struct V_4 * V_4 = NULL ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_42 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_89 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( V_4 ) {
V_221 -> V_222 = V_4 -> V_155 ;
V_221 -> V_223 = V_4 -> V_85 ;
V_221 -> V_68 = V_4 -> V_156 ;
V_221 -> V_52 = V_4 -> V_157 ;
memcpy ( V_221 -> V_8 ,
V_4 -> V_8 . V_9 , V_105 ) ;
return 0 ;
}
return - 1 ;
}
int F_94 ( struct V_1 * V_5 , struct V_221 * V_221 )
{
int V_212 ;
F_4 () ;
V_212 = F_93 ( V_5 , V_221 ) ;
F_7 () ;
return V_212 ;
}
int F_95 ( struct V_90 * V_91 , struct V_224 * V_13 )
{
struct V_1 * V_5 = F_96 ( V_13 ) ;
struct V_3 * V_3 , * V_225 ;
struct V_4 * V_7 ;
struct V_221 V_221 ;
struct V_87 * V_88 ;
int V_226 ;
int V_227 ;
int V_228 ;
if ( F_93 ( V_5 , & V_221 ) ) {
F_25 ( L_46 ,
V_13 -> V_138 ) ;
goto V_229;
}
V_226 = V_221 . V_223 ;
V_228 = V_221 . V_222 ;
if ( V_226 == 0 ) {
F_25 ( L_47 , V_13 -> V_138 ) ;
goto V_229;
}
V_227 = F_97 ( V_5 , V_91 , V_226 ) ;
V_225 = NULL ;
F_42 (bond, slave, iter) {
V_7 = F_6 ( V_3 ) . V_2 . V_4 ;
if ( ! V_7 || V_7 -> V_155 != V_228 )
continue;
if ( V_227 >= 0 ) {
if ( ! V_225 && F_98 ( V_3 ) )
V_225 = V_3 ;
V_227 -- ;
continue;
}
if ( F_98 ( V_3 ) ) {
F_99 ( V_5 , V_91 , V_3 -> V_13 ) ;
goto V_219;
}
}
if ( V_227 >= 0 ) {
F_56 ( L_48 ,
V_13 -> V_138 , V_228 ) ;
goto V_229;
}
if ( V_225 )
F_99 ( V_5 , V_91 , V_225 -> V_13 ) ;
else
goto V_229;
V_219:
return V_230 ;
V_229:
F_100 ( V_91 ) ;
goto V_219;
}
int F_101 ( const struct V_90 * V_91 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
int V_212 = V_213 ;
struct V_45 * V_45 , V_231 ;
if ( V_91 -> V_98 != V_99 )
return V_212 ;
V_45 = F_102 ( V_91 , 0 , sizeof( V_231 ) , & V_231 ) ;
if ( ! V_45 )
return V_212 ;
F_80 ( & V_5 -> V_206 ) ;
V_212 = F_87 ( V_45 , V_3 , V_91 -> V_232 ) ;
F_82 ( & V_5 -> V_206 ) ;
return V_212 ;
}
void F_103 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
int V_171 ;
V_171 = V_5 -> V_15 . V_171 ;
F_62 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) . V_2 ) ;
F_20 ( V_2 ) ;
if ( V_171 )
V_2 -> V_56 |= V_77 ;
else
V_2 -> V_56 &= ~ V_77 ;
F_22 ( V_2 ) ;
}
}
