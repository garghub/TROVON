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
static inline void F_20 ( struct V_2 * V_2 )
{
F_21 ( & ( F_6 ( V_2 -> V_3 ) -> V_17 ) ) ;
}
static inline void F_22 ( struct V_2 * V_2 )
{
F_23 ( & ( F_6 ( V_2 -> V_3 ) -> V_17 ) ) ;
}
static T_2 F_24 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_2 V_18 ;
if ( V_3 -> V_11 != V_12 )
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
F_25 ( V_3 -> V_5 -> V_27 , L_1 ,
V_2 -> V_28 , V_18 ) ;
return V_18 ;
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
F_25 ( V_3 -> V_5 -> V_27 , L_2 ,
V_2 -> V_28 ) ;
break;
case V_32 :
default:
V_29 = 0x0 ;
F_25 ( V_3 -> V_5 -> V_27 , L_3 ,
V_2 -> V_28 ) ;
break;
}
}
return V_29 ;
}
static inline void F_27 ( struct V_3 * V_3 )
{
F_28 ( & ( F_6 ( V_3 ) -> V_17 ) ) ;
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
case V_20 :
V_84 = V_4 -> V_85 * 10 ;
break;
case V_22 :
V_84 = V_4 -> V_85 * 100 ;
break;
case V_24 :
V_84 = V_4 -> V_85 * 1000 ;
break;
case V_26 :
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
if ( F_6 ( V_3 ) -> V_4 . V_89 )
return & ( F_6 ( V_3 ) -> V_4 ) ;
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
V_91 -> V_27 = V_3 -> V_27 ;
F_47 ( V_91 ) ;
V_91 -> V_95 = V_91 -> V_96 + V_97 ;
V_91 -> V_98 = V_99 ;
V_91 -> V_100 = V_101 ;
V_92 = (struct V_92 * ) F_48 ( V_91 , V_93 ) ;
F_49 ( V_92 -> V_102 . V_103 , V_104 ) ;
F_49 ( V_92 -> V_102 . V_105 , V_3 -> V_106 ) ;
V_92 -> V_102 . V_107 = V_99 ;
V_92 -> V_45 = V_2 -> V_45 ;
F_50 ( V_91 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_2 , struct V_108 * V_109 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_90 * V_91 ;
struct V_110 * V_111 ;
int V_93 = sizeof( struct V_110 ) ;
V_91 = F_46 ( V_93 + 16 ) ;
if ( ! V_91 )
return - V_94 ;
F_52 ( V_91 , 16 ) ;
V_91 -> V_27 = V_3 -> V_27 ;
F_47 ( V_91 ) ;
V_91 -> V_95 = V_91 -> V_96 + V_97 ;
V_91 -> V_98 = V_99 ;
V_111 = (struct V_110 * ) F_48 ( V_91 , V_93 ) ;
F_49 ( V_111 -> V_102 . V_103 , V_104 ) ;
F_49 ( V_111 -> V_102 . V_105 , V_3 -> V_106 ) ;
V_111 -> V_102 . V_107 = V_99 ;
V_111 -> V_109 = * V_109 ;
F_50 ( V_91 ) ;
return 0 ;
}
static void F_53 ( struct V_2 * V_2 )
{
T_4 V_112 ;
V_112 = V_2 -> V_113 ;
if ( V_2 -> V_58 & V_114 ) {
V_2 -> V_113 = V_115 ;
} else {
switch ( V_2 -> V_113 ) {
case V_115 :
if ( ( V_2 -> V_58 & V_73 )
|| ( V_2 -> V_58 & V_116 ) )
V_2 -> V_113 = V_117 ;
break;
case V_117 :
if ( ! ( V_2 -> V_58 & V_73 ) ) {
V_2 -> V_58 &= ~ V_81 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
V_2 -> V_113 = V_115 ;
break;
}
if ( V_2 -> V_118
&& ! ( -- V_2 -> V_118 ) )
V_2 -> V_58 |= V_81 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_58 & V_83 )
&& ! V_2 -> V_118 )
V_2 -> V_113 = V_119 ;
break;
case V_119 :
if ( ( V_2 -> V_58 & V_73 ) &&
( V_2 -> V_62 . V_69 & V_71 ) &&
! F_18 ( V_2 ) ) {
V_2 -> V_113 = V_120 ;
} else if ( ! ( V_2 -> V_58 & V_73 ) ||
( V_2 -> V_58 & V_116 ) ) {
V_2 -> V_58 &= ~ V_81 ;
F_39 ( V_2 -> V_4 , F_38 ( V_2 -> V_4 ) ) ;
V_2 -> V_113 = V_115 ;
}
break;
case V_120 :
if ( ! ( V_2 -> V_58 & V_73 ) ||
( V_2 -> V_58 & V_116 ) ||
! ( V_2 -> V_62 . V_69 & V_71 ) ) {
V_2 -> V_113 = V_119 ;
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
if ( V_2 -> V_113 != V_112 ) {
F_54 ( L_4 ,
V_2 -> V_28 , V_112 ,
V_2 -> V_113 ) ;
switch ( V_2 -> V_113 ) {
case V_115 :
V_2 -> V_56 &= ~ V_71 ;
F_55 ( V_2 ) ;
V_2 -> V_56 &= ~ V_121 ;
V_2 -> V_56 &= ~ V_122 ;
V_2 -> V_78 = true ;
break;
case V_117 :
V_2 -> V_118 = F_29 ( V_43 , 0 ) ;
break;
case V_119 :
V_2 -> V_56 |= V_71 ;
V_2 -> V_56 &= ~ V_121 ;
V_2 -> V_56 &= ~ V_122 ;
F_55 ( V_2 ) ;
V_2 -> V_78 = true ;
break;
case V_120 :
V_2 -> V_56 |= V_121 ;
V_2 -> V_56 |= V_122 ;
F_56 ( V_2 ) ;
V_2 -> V_78 = true ;
break;
default:
break;
}
}
}
static void F_57 ( struct V_45 * V_45 , struct V_2 * V_2 )
{
T_5 V_112 ;
V_112 = V_2 -> V_123 ;
if ( V_2 -> V_58 & V_114 )
V_2 -> V_123 = V_124 ;
else if ( ! ( V_2 -> V_58 & V_114 )
&& ! V_2 -> V_125 && ! ( V_2 -> V_58 & V_126 ) )
V_2 -> V_123 = V_127 ;
else if ( V_45 && ( ( V_2 -> V_123 == V_128 ) ||
( V_2 -> V_123 == V_129 ) ||
( V_2 -> V_123 == V_130 ) ) ) {
V_2 -> V_131 = 0 ;
V_2 -> V_123 = V_130 ;
} else {
if ( V_2 -> V_131 &&
! ( -- V_2 -> V_131 ) ) {
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
if ( V_2 -> V_58 & V_126 )
V_2 -> V_123 = V_124 ;
else if ( V_2 -> V_125
&& ( V_2 -> V_58
& V_132 ) )
V_2 -> V_123 = V_128 ;
else if ( V_2 -> V_125
&& ( ( V_2 -> V_58
& V_132 ) == 0 ) )
V_2 -> V_123 = V_133 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_123 != V_112 ) || ( V_45 ) ) {
F_54 ( L_5 ,
V_2 -> V_28 , V_112 ,
V_2 -> V_123 ) ;
switch ( V_2 -> V_123 ) {
case V_124 :
if ( ! ( V_2 -> V_53 & V_134 ) )
V_2 -> V_58 &= ~ V_132 ;
else
V_2 -> V_58 |= V_132 ;
V_2 -> V_58 &= ~ V_73 ;
F_34 ( V_2 ) ;
V_2 -> V_56 &= ~ V_135 ;
V_2 -> V_58 &= ~ V_126 ;
V_2 -> V_123 = V_127 ;
case V_127 :
V_2 -> V_58 &= ~ V_59 ;
break;
case V_133 :
V_2 -> V_58 &= ~ V_73 ;
F_34 ( V_2 ) ;
V_2 -> V_62 . V_69 &= ~ V_55 ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_56 &= ~ V_135 ;
break;
case V_128 :
V_2 -> V_62 . V_69 &= ~ V_71 ;
V_2 -> V_58 &= ~ V_59 ;
V_2 -> V_62 . V_69 |= V_76 ;
V_2 -> V_131 = F_29 ( V_35 , ( T_2 ) ( V_136 ) ) ;
V_2 -> V_56 |= V_135 ;
break;
case V_129 :
F_36 ( V_2 ) ;
F_34 ( V_2 ) ;
V_2 -> V_58 |= V_59 ;
V_2 -> V_56 &= ~ V_135 ;
break;
case V_130 :
if ( F_32 ( & ( V_45 -> V_49 ) ,
& ( V_2 -> V_49 ) ) ) {
F_58 ( V_2 -> V_3 -> V_5 -> V_27 , L_6
L_7 ,
V_2 -> V_3 -> V_27 -> V_137 ) ;
return;
}
F_35 ( V_45 , V_2 ) ;
F_37 ( V_45 , V_2 ) ;
F_33 ( V_45 , V_2 ) ;
V_2 -> V_131 = F_29 ( V_35 , ( T_2 ) ( V_2 -> V_56 & V_77 ) ) ;
V_2 -> V_56 &= ~ V_135 ;
break;
default:
break;
}
}
}
static void F_59 ( struct V_2 * V_2 )
{
if ( V_2 -> V_138 && ! ( -- V_2 -> V_138 ) ) {
if ( V_2 -> V_78 && ( V_2 -> V_58 & V_132 ) ) {
F_43 ( V_2 ) ;
if ( F_45 ( V_2 ) >= 0 ) {
F_54 ( L_8 ,
V_2 -> V_28 ) ;
V_2 -> V_78 = false ;
}
}
V_2 -> V_138 = V_37 / V_139 ;
}
}
static void F_60 ( struct V_2 * V_2 )
{
T_6 V_112 ;
V_112 = V_2 -> V_140 ;
if ( ( ( V_2 -> V_58 & V_114 ) || ! ( V_2 -> V_58 & V_132 ) || ! V_2 -> V_125 ) ||
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
if ( ! ( V_2 -> V_62 . V_69 &
V_77 ) )
V_2 -> V_140 = V_145 ;
else
V_2 -> V_140 = V_144 ;
break;
default:
break;
}
}
if ( V_2 -> V_140 != V_112 ) {
F_54 ( L_9 ,
V_2 -> V_28 , V_112 ,
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
static void F_61 ( struct V_2 * V_2 )
{
struct V_4 * V_4 , * V_148 = NULL , * V_149 ;
struct V_2 * V_150 = NULL , * V_151 ;
struct V_87 * V_88 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_152 = 0 ;
if ( V_2 -> V_58 & V_73 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_149 = V_2 -> V_4 ;
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
V_2 -> V_4 = NULL ;
V_2 -> V_80 = NULL ;
V_2 -> V_153 = 0 ;
F_25 ( V_5 -> V_27 , L_10 ,
V_2 -> V_28 ,
V_149 -> V_154 ) ;
if ( ! V_149 -> V_79 )
F_62 ( V_149 ) ;
break;
}
}
if ( ! V_151 ) {
F_63 ( L_11 ,
V_2 -> V_3 -> V_5 -> V_27 -> V_137 ,
V_2 -> V_28 ,
V_2 -> V_3 -> V_27 -> V_137 ,
V_2 -> V_4 -> V_154 ) ;
}
}
F_64 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_79 ) {
if ( ! V_148 )
V_148 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_155 == V_2 -> V_53 ) &&
F_32 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_62 . system ) ) &&
( V_4 -> V_50 == V_2 -> V_62 . V_66 ) &&
( V_4 -> V_156 == V_2 -> V_62 . V_67 )
) &&
( ( ! F_32 ( & ( V_2 -> V_62 . system ) , & ( V_157 ) ) &&
! V_4 -> V_158 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_153 =
V_2 -> V_4 -> V_154 ;
V_2 -> V_80 = V_4 -> V_79 ;
V_2 -> V_4 -> V_85 ++ ;
V_4 -> V_79 = V_2 ;
F_25 ( V_5 -> V_27 , L_12 ,
V_2 -> V_28 ,
V_2 -> V_4 -> V_154 ) ;
V_2 -> V_58 |= V_73 ;
V_152 = 1 ;
break;
}
}
if ( ! V_152 ) {
if ( V_148 ) {
V_2 -> V_4 = V_148 ;
V_2 -> V_153 =
V_2 -> V_4 -> V_154 ;
if ( V_2 -> V_53 & V_134 )
V_2 -> V_4 -> V_158 = false ;
else
V_2 -> V_4 -> V_158 = true ;
V_2 -> V_4 -> V_159 = V_2 -> V_160 ;
V_2 -> V_4 -> V_155 = V_2 -> V_53 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_62 . system ;
V_2 -> V_4 -> V_50 =
V_2 -> V_62 . V_66 ;
V_2 -> V_4 -> V_156 = V_2 -> V_62 . V_67 ;
V_2 -> V_4 -> V_161 = 1 ;
V_2 -> V_4 -> V_162 = 1 ;
V_2 -> V_4 -> V_79 = V_2 ;
V_2 -> V_4 -> V_85 ++ ;
V_2 -> V_58 |= V_73 ;
F_25 ( V_5 -> V_27 , L_13 ,
V_2 -> V_28 ,
V_2 -> V_4 -> V_154 ) ;
} else {
F_58 ( V_5 -> V_27 , L_14 ,
V_2 -> V_28 , V_2 -> V_3 -> V_27 -> V_137 ) ;
}
}
F_39 ( V_2 -> V_4 ,
F_38 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_65 ( V_4 ) ;
}
static struct V_4 * F_66 ( struct V_4 * V_163 ,
struct V_4 * V_164 )
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
case V_13 :
case V_166 :
if ( F_40 ( V_164 ) > F_40 ( V_163 ) )
return V_164 ;
break;
default:
F_63 ( L_15 ,
V_164 -> V_3 -> V_5 -> V_27 -> V_137 ,
F_17 ( V_164 -> V_79 ) ) ;
break;
}
return V_163 ;
}
static int F_67 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_79 ;
if ( ! V_2 )
return 0 ;
return F_68 ( V_2 -> V_3 -> V_27 ) &&
F_69 ( V_2 -> V_3 -> V_27 ) ;
}
static void F_65 ( struct V_4 * V_7 )
{
struct V_4 * V_163 , * V_167 , * V_168 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_168 = V_7 ;
V_167 = F_41 ( V_7 ) ;
V_163 = ( V_167 && F_67 ( V_167 ) ) ? V_167 : NULL ;
F_42 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_89 = 0 ;
if ( V_7 -> V_85 && F_67 ( V_7 ) )
V_163 = F_66 ( V_163 , V_7 ) ;
}
if ( V_163 &&
F_17 ( V_163 -> V_79 ) == V_13 ) {
if ( V_167 && V_167 -> V_79 &&
V_167 -> V_79 -> V_125 &&
( F_8 ( V_167 ) ||
( ! F_8 ( V_167 ) &&
! F_8 ( V_163 ) ) ) ) {
if ( ! ( ! V_167 -> V_155 &&
V_163 -> V_155 ) ) {
V_163 = NULL ;
V_167 -> V_89 = 1 ;
}
}
}
if ( V_163 && ( V_163 == V_167 ) ) {
V_163 = NULL ;
V_167 -> V_89 = 1 ;
}
if ( V_163 ) {
F_25 ( V_5 -> V_27 , L_16 ,
V_163 -> V_154 , V_163 -> V_85 ,
V_163 -> V_155 ,
V_163 -> V_156 ,
V_163 -> V_158 , V_163 -> V_89 ) ;
F_25 ( V_5 -> V_27 , L_17 ,
V_163 -> V_79 , V_163 -> V_3 ,
V_163 -> V_3 ? V_163 -> V_3 -> V_27 -> V_137 : L_18 ) ;
F_42 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_25 ( V_5 -> V_27 , L_19 ,
V_7 -> V_154 , V_7 -> V_85 ,
V_7 -> V_155 ,
V_7 -> V_156 ,
V_7 -> V_158 , V_7 -> V_89 ) ;
}
if ( V_163 -> V_158 ) {
F_63 ( L_20 ,
V_163 -> V_3 ?
V_163 -> V_3 -> V_5 -> V_27 -> V_137 : L_18 ) ;
}
V_163 -> V_89 = 1 ;
F_25 ( V_5 -> V_27 , L_21 ,
V_163 -> V_154 ) ;
F_25 ( V_5 -> V_27 , L_19 ,
V_163 -> V_154 , V_163 -> V_85 ,
V_163 -> V_155 ,
V_163 -> V_156 ,
V_163 -> V_158 , V_163 -> V_89 ) ;
if ( V_167 ) {
for ( V_2 = V_167 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
F_10 ( V_2 ) ;
}
}
}
V_167 = F_41 ( V_168 ) ;
if ( V_167 ) {
if ( ! F_8 ( V_167 ) ) {
for ( V_2 = V_167 -> V_79 ; V_2 ;
V_2 = V_2 -> V_80 ) {
F_12 ( V_2 ) ;
}
}
}
F_7 () ;
F_70 ( V_5 ) ;
}
static void F_62 ( struct V_4 * V_4 )
{
if ( V_4 ) {
V_4 -> V_158 = false ;
V_4 -> V_159 = 0 ;
V_4 -> V_155 = 0 ;
V_4 -> V_8 = V_157 ;
V_4 -> V_50 = 0 ;
V_4 -> V_156 = 0 ;
V_4 -> V_161 = 0 ;
V_4 -> V_162 = 0 ;
V_4 -> V_79 = NULL ;
V_4 -> V_89 = 0 ;
V_4 -> V_85 = 0 ;
F_54 ( L_22 ,
V_4 -> V_154 ) ;
}
}
static void F_71 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_62 ( V_4 ) ;
V_4 -> V_169 = V_157 ;
V_4 -> V_154 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_72 ( struct V_2 * V_2 , int V_170 )
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
. V_180 = F_44 ( V_181 ) ,
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
V_2 -> V_182 = V_55 |
V_76 ;
V_2 -> V_56 = V_55 |
V_76 ;
if ( V_170 )
V_2 -> V_56 |= V_77 ;
memcpy ( & V_2 -> V_72 , & V_171 , sizeof( V_171 ) ) ;
memcpy ( & V_2 -> V_62 , & V_171 , sizeof( V_171 ) ) ;
V_2 -> V_125 = true ;
V_2 -> V_58 = 0x3 ;
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
V_2 -> V_80 = NULL ;
V_2 -> V_184 = 0 ;
memcpy ( & V_2 -> V_45 , & V_45 , sizeof( V_45 ) ) ;
}
}
static void F_56 ( struct V_2 * V_2 )
{
if ( V_2 -> V_4 -> V_89 ) {
F_54 ( L_23 ,
V_2 -> V_28 ,
V_2 -> V_4 -> V_154 ) ;
F_12 ( V_2 ) ;
}
}
static void F_55 ( struct V_2 * V_2 )
{
if ( V_2 -> V_4 &&
! F_32 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_157 ) ) ) {
F_54 ( L_24 ,
V_2 -> V_28 ,
V_2 -> V_4 -> V_154 ) ;
F_10 ( V_2 ) ;
}
}
static void F_73 ( struct V_108 * V_185 ,
struct V_2 * V_2 )
{
struct V_108 V_109 ;
memcpy ( & V_109 , V_185 , sizeof( struct V_108 ) ) ;
V_109 . V_186 = V_187 ;
if ( F_51 ( V_2 , & V_109 ) >= 0 ) {
F_54 ( L_25 ,
V_2 -> V_28 ) ;
}
}
static void F_74 ( struct V_108 * V_109 ,
struct V_2 * V_2 )
{
V_109 = NULL ;
V_2 = NULL ;
}
void F_75 ( struct V_1 * V_5 , int V_188 )
{
F_19 ( V_5 ) . V_16 = V_188 ;
}
void F_76 ( struct V_1 * V_5 , T_2 V_189 )
{
if ( ! F_32 ( & ( F_19 ( V_5 ) . system . V_190 ) ,
V_5 -> V_27 -> V_191 ) ) {
F_19 ( V_5 ) . V_154 = 0 ;
F_19 ( V_5 ) . system . V_192 = 0xFFFF ;
F_19 ( V_5 ) . system . V_190 = * ( (struct V_193 * ) V_5 -> V_27 -> V_191 ) ;
V_37 = V_189 ;
F_75 ( V_5 ,
V_194 *
V_37 ) ;
}
}
void F_77 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) -> V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_72 ( V_2 , V_5 -> V_14 . V_170 ) ;
F_27 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_28 = F_6 ( V_3 ) -> V_195 ;
V_2 -> V_160 = 0 ;
V_2 -> V_160 |= F_26 ( V_2 ) ;
V_2 -> V_160 |= ( F_24 ( V_2 ) << 1 ) ;
V_2 -> V_53 = V_2 -> V_160 ;
if ( ! ( V_2 -> V_53 & V_134 ) )
V_2 -> V_58 &= ~ V_132 ;
V_2 -> V_49 = F_19 ( V_5 ) . system . V_190 ;
V_2 -> V_138 = V_37 / V_139 ;
V_2 -> V_4 = NULL ;
V_2 -> V_80 = NULL ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_71 ( V_4 ) ;
V_4 -> V_169 = * ( (struct V_193 * ) V_5 -> V_27 -> V_191 ) ;
V_4 -> V_154 = ++ F_19 ( V_5 ) . V_154 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_89 = 0 ;
V_4 -> V_85 = 0 ;
}
}
void F_78 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_196 , * V_197 ;
struct V_4 * V_4 , * V_198 , * V_149 ;
int V_199 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_200 ;
struct V_87 * V_88 ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_5 -> V_27 , L_26 ,
V_3 -> V_27 -> V_137 ) ;
return;
}
F_25 ( V_5 -> V_27 , L_27 ,
V_4 -> V_154 ) ;
V_2 -> V_56 &= ~ V_55 ;
F_43 ( V_2 ) ;
F_45 ( V_2 ) ;
if ( V_4 -> V_79 ) {
if ( ( V_4 -> V_79 != V_2 ) ||
( V_4 -> V_79 -> V_80 ) ) {
F_64 (bond, slave_iter, iter) {
V_198 = & ( F_6 ( V_200 ) -> V_4 ) ;
if ( ! V_198 -> V_79 ||
( ( V_198 -> V_79 == V_2 ) &&
! V_198 -> V_79 -> V_80 ) )
break;
}
if ( ! V_200 )
V_198 = NULL ;
if ( ( V_198 ) && ( ( ! V_198 -> V_79 ) || ( ( V_198 -> V_79 == V_2 ) && ! V_198 -> V_79 -> V_80 ) ) ) {
F_25 ( V_5 -> V_27 , L_28 ,
V_4 -> V_154 ,
V_198 -> V_154 ) ;
if ( ( V_198 -> V_79 == V_2 ) &&
V_198 -> V_89 ) {
F_80 ( V_5 -> V_27 , L_29 ) ;
V_199 = 1 ;
}
V_198 -> V_158 = V_4 -> V_158 ;
V_198 -> V_159 = V_4 -> V_159 ;
V_198 -> V_155 = V_4 -> V_155 ;
V_198 -> V_8 = V_4 -> V_8 ;
V_198 -> V_50 = V_4 -> V_50 ;
V_198 -> V_156 = V_4 -> V_156 ;
V_198 -> V_161 = V_4 -> V_161 ;
V_198 -> V_162 = V_4 -> V_162 ;
V_198 -> V_79 = V_4 -> V_79 ;
V_198 -> V_89 = V_4 -> V_89 ;
V_198 -> V_85 = V_4 -> V_85 ;
for ( V_197 = V_4 -> V_79 ; V_197 ;
V_197 = V_197 -> V_80 ) {
V_197 -> V_4 = V_198 ;
V_197 -> V_153 = V_198 -> V_154 ;
}
F_62 ( V_4 ) ;
if ( V_199 )
F_65 ( F_3 ( V_2 ) ) ;
} else {
F_79 ( V_5 -> V_27 , L_30 ) ;
}
} else {
V_199 = V_4 -> V_89 ;
F_62 ( V_4 ) ;
if ( V_199 ) {
F_80 ( V_5 -> V_27 , L_29 ) ;
V_149 = F_3 ( V_2 ) ;
if ( V_149 )
F_65 ( V_149 ) ;
}
}
}
F_25 ( V_5 -> V_27 , L_31 , V_2 -> V_28 ) ;
F_64 (bond, slave_iter, iter) {
V_149 = & ( F_6 ( V_200 ) -> V_4 ) ;
V_196 = NULL ;
for ( V_197 = V_149 -> V_79 ; V_197 ;
V_196 = V_197 ,
V_197 = V_197 -> V_80 ) {
if ( V_197 == V_2 ) {
if ( V_196 )
V_196 -> V_80 = V_197 -> V_80 ;
else
V_149 -> V_79 = V_197 -> V_80 ;
V_149 -> V_85 -- ;
if ( V_149 -> V_85 == 0 ) {
V_199 = V_149 -> V_89 ;
F_62 ( V_149 ) ;
if ( V_199 ) {
F_80 ( V_5 -> V_27 , L_29 ) ;
F_65 ( F_3 ( V_2 ) ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
}
void F_81 ( struct V_201 * V_202 )
{
struct V_1 * V_5 = F_82 ( V_202 , struct V_1 ,
V_203 . V_202 ) ;
struct V_4 * V_4 ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_204 = V_10 ;
F_83 ( & V_5 -> V_205 ) ;
F_4 () ;
if ( ! F_84 ( V_5 ) )
goto V_206;
if ( F_19 ( V_5 ) . V_16 &&
! ( -- F_19 ( V_5 ) . V_16 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) -> V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_63 ( L_32 ,
V_5 -> V_27 -> V_137 ) ;
goto V_206;
}
V_4 = F_3 ( V_2 ) ;
F_65 ( V_4 ) ;
}
F_70 ( V_5 ) ;
}
F_42 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_63 ( L_33 ,
V_5 -> V_27 -> V_137 ) ;
goto V_206;
}
F_20 ( V_2 ) ;
F_57 ( NULL , V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
F_53 ( V_2 ) ;
F_59 ( V_2 ) ;
if ( V_2 -> V_58 & V_114 )
V_2 -> V_58 &= ~ V_114 ;
F_22 ( V_2 ) ;
}
V_206:
F_42 (bond, slave, iter) {
if ( V_3 -> V_207 ) {
V_204 = V_208 ;
break;
}
}
F_7 () ;
F_85 ( & V_5 -> V_205 ) ;
if ( V_204 && F_86 () ) {
F_87 ( V_5 ) ;
F_88 () ;
}
F_89 ( V_5 -> V_209 , & V_5 -> V_203 , V_210 ) ;
}
static int F_90 ( struct V_45 * V_45 , struct V_3 * V_3 ,
T_2 V_93 )
{
struct V_2 * V_2 ;
int V_211 = V_212 ;
if ( V_93 >= sizeof( struct V_45 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_63 ( L_34 ,
V_3 -> V_27 -> V_137 , V_3 -> V_5 -> V_27 -> V_137 ) ;
return V_211 ;
}
switch ( V_45 -> V_172 ) {
case V_213 :
V_211 = V_214 ;
F_25 ( V_3 -> V_5 -> V_27 , L_35 ,
V_2 -> V_28 ) ;
F_20 ( V_2 ) ;
F_57 ( V_45 , V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_215 :
V_211 = V_214 ;
switch ( ( (struct V_108 * ) V_45 ) -> V_186 ) {
case V_216 :
F_25 ( V_3 -> V_5 -> V_27 , L_36 ,
V_2 -> V_28 ) ;
F_73 ( (struct V_108 * ) V_45 , V_2 ) ;
break;
case V_187 :
F_25 ( V_3 -> V_5 -> V_27 , L_37 ,
V_2 -> V_28 ) ;
F_74 ( (struct V_108 * ) V_45 , V_2 ) ;
break;
default:
F_25 ( V_3 -> V_5 -> V_27 , L_38 ,
V_2 -> V_28 ) ;
}
}
}
return V_211 ;
}
void F_91 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_3 -> V_5 -> V_27 , L_39 ,
V_3 -> V_27 -> V_137 ) ;
return;
}
F_20 ( V_2 ) ;
V_2 -> V_160 &= ~ V_217 ;
V_2 -> V_53 = V_2 -> V_160 |=
( F_24 ( V_2 ) << 1 ) ;
F_25 ( V_3 -> V_5 -> V_27 , L_40 , V_2 -> V_28 ) ;
V_2 -> V_58 |= V_114 ;
F_22 ( V_2 ) ;
}
void F_92 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_3 -> V_5 -> V_27 , L_41 ,
V_3 -> V_27 -> V_137 ) ;
return;
}
F_20 ( V_2 ) ;
V_2 -> V_160 &= ~ V_134 ;
V_2 -> V_53 = V_2 -> V_160 |=
F_26 ( V_2 ) ;
F_25 ( V_3 -> V_5 -> V_27 , L_42 , V_2 -> V_28 ) ;
V_2 -> V_58 |= V_114 ;
F_22 ( V_2 ) ;
}
void F_93 ( struct V_3 * V_3 , char V_11 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_3 -> V_5 -> V_27 , L_43 ,
V_3 -> V_27 -> V_137 ) ;
return;
}
F_20 ( V_2 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_125 = true ;
V_2 -> V_160 &= ~ V_134 ;
V_2 -> V_53 = V_2 -> V_160 |=
F_26 ( V_2 ) ;
V_2 -> V_160 &= ~ V_217 ;
V_2 -> V_53 = V_2 -> V_160 |=
( F_24 ( V_2 ) << 1 ) ;
} else {
V_2 -> V_125 = false ;
V_2 -> V_160 &= ~ V_134 ;
V_2 -> V_53 = ( V_2 -> V_160 &=
~ V_217 ) ;
}
F_25 ( V_3 -> V_5 -> V_27 , L_44 ,
V_2 -> V_28 ,
V_11 == V_12 ? L_45 : L_46 ) ;
V_2 -> V_58 |= V_114 ;
F_22 ( V_2 ) ;
}
int F_70 ( struct V_1 * V_5 )
{
struct V_4 * V_167 ;
struct V_3 * V_6 ;
int V_211 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_211 = 0 ;
goto V_218;
}
V_167 = F_41 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_167 ) {
if ( V_167 -> V_85 < V_5 -> V_14 . V_219 ) {
if ( F_69 ( V_5 -> V_27 ) ) {
F_94 ( V_5 -> V_27 ) ;
goto V_218;
}
} else if ( ! F_69 ( V_5 -> V_27 ) ) {
F_95 ( V_5 -> V_27 ) ;
goto V_218;
}
} else if ( F_69 ( V_5 -> V_27 ) ) {
F_94 ( V_5 -> V_27 ) ;
}
V_218:
F_7 () ;
return V_211 ;
}
int F_96 ( struct V_1 * V_5 ,
struct V_220 * V_220 )
{
struct V_4 * V_4 = NULL ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_42 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_89 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( ! V_4 )
return - 1 ;
V_220 -> V_221 = V_4 -> V_154 ;
V_220 -> V_222 = V_4 -> V_85 ;
V_220 -> V_68 = V_4 -> V_155 ;
V_220 -> V_52 = V_4 -> V_156 ;
F_49 ( V_220 -> V_8 ,
V_4 -> V_8 . V_9 ) ;
return 0 ;
}
int F_97 ( struct V_1 * V_5 , struct V_220 * V_220 )
{
int V_211 ;
F_4 () ;
V_211 = F_96 ( V_5 , V_220 ) ;
F_7 () ;
return V_211 ;
}
int F_98 ( struct V_90 * V_91 , struct V_223 * V_27 )
{
struct V_1 * V_5 = F_99 ( V_27 ) ;
struct V_3 * V_3 , * V_224 ;
struct V_4 * V_7 ;
struct V_220 V_220 ;
struct V_87 * V_88 ;
int V_225 ;
int V_226 ;
int V_227 ;
if ( F_96 ( V_5 , & V_220 ) ) {
F_25 ( V_27 , L_47 ) ;
goto V_228;
}
V_225 = V_220 . V_222 ;
V_227 = V_220 . V_221 ;
if ( V_225 == 0 ) {
F_25 ( V_27 , L_48 ) ;
goto V_228;
}
V_226 = F_100 ( V_5 , V_91 ) % V_225 ;
V_224 = NULL ;
F_42 (bond, slave, iter) {
V_7 = F_6 ( V_3 ) -> V_2 . V_4 ;
if ( ! V_7 || V_7 -> V_154 != V_227 )
continue;
if ( V_226 >= 0 ) {
if ( ! V_224 && F_101 ( V_3 ) )
V_224 = V_3 ;
V_226 -- ;
continue;
}
if ( F_101 ( V_3 ) ) {
F_102 ( V_5 , V_91 , V_3 -> V_27 ) ;
goto V_218;
}
}
if ( V_226 >= 0 ) {
F_58 ( V_27 , L_49 ,
V_227 ) ;
goto V_228;
}
if ( V_224 )
F_102 ( V_5 , V_91 , V_224 -> V_27 ) ;
else
goto V_228;
V_218:
return V_229 ;
V_228:
F_103 ( V_91 ) ;
goto V_218;
}
int F_104 ( const struct V_90 * V_91 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
int V_211 = V_212 ;
struct V_45 * V_45 , V_230 ;
if ( V_91 -> V_98 != V_99 )
return V_211 ;
V_45 = F_105 ( V_91 , 0 , sizeof( V_230 ) , & V_230 ) ;
if ( ! V_45 )
return V_211 ;
F_83 ( & V_5 -> V_205 ) ;
V_211 = F_90 ( V_45 , V_3 , V_91 -> V_231 ) ;
F_85 ( & V_5 -> V_205 ) ;
return V_211 ;
}
void F_106 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_87 * V_88 ;
struct V_3 * V_3 ;
int V_170 ;
V_170 = V_5 -> V_14 . V_170 ;
F_64 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_20 ( V_2 ) ;
if ( V_170 )
V_2 -> V_56 |= V_77 ;
else
V_2 -> V_56 &= ~ V_77 ;
F_22 ( V_2 ) ;
}
}
