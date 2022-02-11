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
if ( ( V_2 -> V_65 & V_66 )
&& ( V_52 -> V_64 & V_78 ) )
V_68 -> V_76 |= V_78 ;
else
V_68 -> V_76 &= ~ V_78 ;
}
}
static void F_28 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_69 , & V_2 -> V_79 ,
sizeof( struct V_67 ) ) ;
V_2 -> V_63 |= V_77 ;
}
}
static void F_29 ( struct V_52 * V_52 , struct V_2 * V_2 )
{
if ( V_52 && V_2 ) {
const struct V_67 * V_68 = & V_2 -> V_69 ;
if ( F_25 ( V_52 -> V_71 ) != V_68 -> V_70 ||
F_25 ( V_52 -> V_55 ) != V_68 -> V_72 ||
! F_26 ( & V_52 -> V_56 , & V_68 -> system ) ||
F_25 ( V_52 -> V_58 ) != V_68 -> V_73 ||
F_25 ( V_52 -> V_75 ) != V_68 -> V_74 ||
( V_52 -> V_64 & V_62 ) != ( V_68 -> V_76 & V_62 ) ) {
V_2 -> V_65 &= ~ V_80 ;
}
}
}
static void F_30 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_67 * V_81 = & V_2 -> V_79 ;
const struct V_67 * V_82 = & V_2 -> V_69 ;
if ( V_81 -> V_70 != V_82 -> V_70 ||
V_81 -> V_72 != V_82 -> V_72 ||
! F_26 ( & V_81 -> system , & V_82 -> system ) ||
V_81 -> V_73 != V_82 -> V_73 ||
V_81 -> V_74 != V_82 -> V_74 ||
( V_81 -> V_76 & V_62 )
!= ( V_82 -> V_76 & V_62 ) ) {
V_2 -> V_65 &= ~ V_80 ;
}
}
}
static void F_31 ( struct V_52 * V_52 , struct V_2 * V_2 )
{
if ( V_52 && V_2 ) {
if ( ( F_25 ( V_52 -> V_53 ) != V_2 -> V_35 ) ||
( F_25 ( V_52 -> V_54 ) != V_2 -> V_55 ) ||
! F_26 ( & ( V_52 -> V_8 ) , & ( V_2 -> V_56 ) ) ||
( F_25 ( V_52 -> V_57 ) != V_2 -> V_58 ) ||
( F_25 ( V_52 -> V_59 ) != V_2 -> V_60 ) ||
( ( V_52 -> V_61 & V_83 ) != ( V_2 -> V_63 & V_83 ) ) ||
( ( V_52 -> V_61 & V_84 ) != ( V_2 -> V_63 & V_84 ) ) ||
( ( V_52 -> V_61 & V_78 ) != ( V_2 -> V_63 & V_78 ) ) ||
( ( V_52 -> V_61 & V_62 ) != ( V_2 -> V_63 & V_62 ) )
) {
V_2 -> V_85 = true ;
}
}
}
static int F_32 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_36 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_86 ;
V_2 ;
V_2 = V_2 -> V_87 ) {
if ( ! ( V_2 -> V_65 & V_88 ) ) {
V_36 = 0 ;
break;
}
}
}
return V_36 ;
}
static void F_33 ( struct V_4 * V_4 , int V_89 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_86 ; V_2 ;
V_2 = V_2 -> V_87 ) {
if ( V_89 )
V_2 -> V_65 |= V_90 ;
else
V_2 -> V_65 &= ~ V_90 ;
}
}
static T_1 F_34 ( struct V_4 * V_4 )
{
T_1 V_91 = 0 ;
if ( V_4 -> V_92 ) {
switch ( F_20 ( V_4 -> V_86 ) ) {
case V_93 :
V_91 = V_4 -> V_92 ;
break;
case V_19 :
V_91 = V_4 -> V_92 * 10 ;
break;
case V_21 :
V_91 = V_4 -> V_92 * 100 ;
break;
case V_23 :
V_91 = V_4 -> V_92 * 1000 ;
break;
case V_25 :
V_91 = V_4 -> V_92 * 2500 ;
break;
case V_27 :
V_91 = V_4 -> V_92 * 10000 ;
break;
case V_29 :
V_91 = V_4 -> V_92 * 20000 ;
break;
case V_31 :
V_91 = V_4 -> V_92 * 40000 ;
break;
case V_33 :
V_91 = V_4 -> V_92 * 56000 ;
break;
default:
V_91 = 0 ;
}
}
return V_91 ;
}
static struct V_4 * F_35 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_94 * V_95 ;
struct V_3 * V_3 ;
F_36 (bond, slave, iter)
if ( F_6 ( V_3 ) -> V_4 . V_96 )
return & ( F_6 ( V_3 ) -> V_4 ) ;
return NULL ;
}
static inline void F_37 ( struct V_2 * V_2 )
{
struct V_52 * V_52 = & V_2 -> V_52 ;
const struct V_67 * V_68 = & V_2 -> V_69 ;
V_52 -> V_58 = F_38 ( V_2 -> V_58 ) ;
V_52 -> V_56 = V_2 -> V_56 ;
V_52 -> V_75 = F_38 ( V_2 -> V_60 ) ;
V_52 -> V_55 = F_38 ( V_2 -> V_55 ) ;
V_52 -> V_71 = F_38 ( V_2 -> V_35 ) ;
V_52 -> V_64 = V_2 -> V_63 ;
V_52 -> V_57 = F_38 ( V_68 -> V_73 ) ;
V_52 -> V_8 = V_68 -> system ;
V_52 -> V_59 = F_38 ( V_68 -> V_74 ) ;
V_52 -> V_54 = F_38 ( V_68 -> V_72 ) ;
V_52 -> V_53 = F_38 ( V_68 -> V_70 ) ;
V_52 -> V_61 = V_68 -> V_76 ;
}
static int F_39 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_97 * V_98 ;
struct V_99 * V_99 ;
int V_100 = sizeof( struct V_99 ) ;
V_98 = F_40 ( V_100 ) ;
if ( ! V_98 )
return - V_101 ;
V_98 -> V_34 = V_3 -> V_34 ;
F_41 ( V_98 ) ;
V_98 -> V_102 = V_98 -> V_103 + V_104 ;
V_98 -> V_105 = V_106 ;
V_98 -> V_107 = V_108 ;
V_99 = (struct V_99 * ) F_42 ( V_98 , V_100 ) ;
F_43 ( V_99 -> V_109 . V_110 , V_111 ) ;
F_43 ( V_99 -> V_109 . V_112 , V_3 -> V_113 ) ;
V_99 -> V_109 . V_114 = V_106 ;
V_99 -> V_52 = V_2 -> V_52 ;
F_44 ( V_98 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_2 , struct V_115 * V_116 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_97 * V_98 ;
struct V_117 * V_118 ;
int V_100 = sizeof( struct V_117 ) ;
V_98 = F_40 ( V_100 + 16 ) ;
if ( ! V_98 )
return - V_101 ;
F_46 ( V_98 , 16 ) ;
V_98 -> V_34 = V_3 -> V_34 ;
F_41 ( V_98 ) ;
V_98 -> V_102 = V_98 -> V_103 + V_104 ;
V_98 -> V_105 = V_106 ;
V_118 = (struct V_117 * ) F_42 ( V_98 , V_100 ) ;
F_43 ( V_118 -> V_109 . V_110 , V_111 ) ;
F_43 ( V_118 -> V_109 . V_112 , V_3 -> V_113 ) ;
V_118 -> V_109 . V_114 = V_106 ;
V_118 -> V_116 = * V_116 ;
F_44 ( V_98 ) ;
return 0 ;
}
static void F_47 ( struct V_2 * V_2 , bool * V_119 )
{
T_4 V_120 ;
V_120 = V_2 -> V_121 ;
if ( V_2 -> V_65 & V_122 ) {
V_2 -> V_121 = V_123 ;
} else {
switch ( V_2 -> V_121 ) {
case V_123 :
if ( ( V_2 -> V_65 & V_80 )
|| ( V_2 -> V_65 & V_124 ) )
V_2 -> V_121 = V_125 ;
break;
case V_125 :
if ( ! ( V_2 -> V_65 & V_80 ) ) {
V_2 -> V_65 &= ~ V_88 ;
F_33 ( V_2 -> V_4 , F_32 ( V_2 -> V_4 ) ) ;
V_2 -> V_121 = V_123 ;
break;
}
if ( V_2 -> V_126
&& ! ( -- V_2 -> V_126 ) )
V_2 -> V_65 |= V_88 ;
F_33 ( V_2 -> V_4 , F_32 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_65 & V_90 )
&& ! V_2 -> V_126 )
V_2 -> V_121 = V_127 ;
break;
case V_127 :
if ( ( V_2 -> V_65 & V_80 ) &&
( V_2 -> V_69 . V_76 & V_78 ) &&
! F_18 ( V_2 ) ) {
V_2 -> V_121 = V_128 ;
} else if ( ! ( V_2 -> V_65 & V_80 ) ||
( V_2 -> V_65 & V_124 ) ) {
V_2 -> V_65 &= ~ V_88 ;
F_33 ( V_2 -> V_4 , F_32 ( V_2 -> V_4 ) ) ;
V_2 -> V_121 = V_123 ;
}
break;
case V_128 :
if ( ! ( V_2 -> V_65 & V_80 ) ||
( V_2 -> V_65 & V_124 ) ||
! ( V_2 -> V_69 . V_76 & V_78 ) ) {
V_2 -> V_121 = V_127 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_96 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_121 != V_120 ) {
F_48 ( L_4 ,
V_2 -> V_35 , V_120 ,
V_2 -> V_121 ) ;
switch ( V_2 -> V_121 ) {
case V_123 :
V_2 -> V_63 &= ~ V_78 ;
F_49 ( V_2 ,
V_119 ) ;
V_2 -> V_63 &= ~ V_129 ;
V_2 -> V_63 &= ~ V_130 ;
V_2 -> V_85 = true ;
break;
case V_125 :
V_2 -> V_126 = F_23 ( V_50 , 0 ) ;
break;
case V_127 :
V_2 -> V_63 |= V_78 ;
V_2 -> V_63 &= ~ V_129 ;
V_2 -> V_63 &= ~ V_130 ;
F_49 ( V_2 ,
V_119 ) ;
V_2 -> V_85 = true ;
break;
case V_128 :
V_2 -> V_63 |= V_129 ;
V_2 -> V_63 |= V_130 ;
F_50 ( V_2 ,
V_119 ) ;
V_2 -> V_85 = true ;
break;
default:
break;
}
}
}
static void F_51 ( struct V_52 * V_52 , struct V_2 * V_2 )
{
T_5 V_120 ;
V_120 = V_2 -> V_131 ;
if ( V_2 -> V_65 & V_122 )
V_2 -> V_131 = V_132 ;
else if ( ! ( V_2 -> V_65 & V_122 )
&& ! V_2 -> V_133 && ! ( V_2 -> V_65 & V_134 ) )
V_2 -> V_131 = V_135 ;
else if ( V_52 && ( ( V_2 -> V_131 == V_136 ) ||
( V_2 -> V_131 == V_137 ) ||
( V_2 -> V_131 == V_138 ) ) ) {
V_2 -> V_139 = 0 ;
V_2 -> V_131 = V_138 ;
} else {
if ( V_2 -> V_139 &&
! ( -- V_2 -> V_139 ) ) {
switch ( V_2 -> V_131 ) {
case V_136 :
V_2 -> V_131 = V_137 ;
break;
case V_138 :
V_2 -> V_131 = V_136 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_131 ) {
case V_135 :
if ( V_2 -> V_65 & V_134 )
V_2 -> V_131 = V_132 ;
else if ( V_2 -> V_133
&& ( V_2 -> V_65
& V_140 ) )
V_2 -> V_131 = V_136 ;
else if ( V_2 -> V_133
&& ( ( V_2 -> V_65
& V_140 ) == 0 ) )
V_2 -> V_131 = V_141 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_131 != V_120 ) || ( V_52 ) ) {
F_48 ( L_5 ,
V_2 -> V_35 , V_120 ,
V_2 -> V_131 ) ;
switch ( V_2 -> V_131 ) {
case V_132 :
if ( ! ( V_2 -> V_60 & V_142 ) )
V_2 -> V_65 &= ~ V_140 ;
else
V_2 -> V_65 |= V_140 ;
V_2 -> V_65 &= ~ V_80 ;
F_28 ( V_2 ) ;
V_2 -> V_63 &= ~ V_143 ;
V_2 -> V_65 &= ~ V_134 ;
V_2 -> V_131 = V_135 ;
case V_135 :
V_2 -> V_65 &= ~ V_66 ;
break;
case V_141 :
V_2 -> V_65 &= ~ V_80 ;
F_28 ( V_2 ) ;
V_2 -> V_69 . V_76 &= ~ V_62 ;
V_2 -> V_65 |= V_66 ;
V_2 -> V_63 &= ~ V_143 ;
break;
case V_136 :
V_2 -> V_69 . V_76 &= ~ V_78 ;
V_2 -> V_65 &= ~ V_66 ;
V_2 -> V_69 . V_76 |= V_83 ;
V_2 -> V_139 = F_23 ( V_42 , ( T_2 ) ( V_144 ) ) ;
V_2 -> V_63 |= V_143 ;
break;
case V_137 :
F_30 ( V_2 ) ;
F_28 ( V_2 ) ;
V_2 -> V_65 |= V_66 ;
V_2 -> V_63 &= ~ V_143 ;
break;
case V_138 :
if ( F_26 ( & ( V_52 -> V_56 ) ,
& ( V_2 -> V_56 ) ) ) {
F_52 ( V_2 -> V_3 -> V_5 -> V_34 , L_6
L_7 ,
V_2 -> V_3 -> V_34 -> V_145 ) ;
return;
}
F_29 ( V_52 , V_2 ) ;
F_31 ( V_52 , V_2 ) ;
F_27 ( V_52 , V_2 ) ;
V_2 -> V_139 = F_23 ( V_42 , ( T_2 ) ( V_2 -> V_63 & V_84 ) ) ;
V_2 -> V_63 &= ~ V_143 ;
break;
default:
break;
}
}
}
static void F_53 ( struct V_2 * V_2 )
{
if ( V_2 -> V_146 && ! ( -- V_2 -> V_146 ) ) {
if ( V_2 -> V_85 && ( V_2 -> V_65 & V_140 ) ) {
F_37 ( V_2 ) ;
if ( F_39 ( V_2 ) >= 0 ) {
F_48 ( L_8 ,
V_2 -> V_35 ) ;
V_2 -> V_85 = false ;
}
}
V_2 -> V_146 = V_44 / V_147 ;
}
}
static void F_54 ( struct V_2 * V_2 )
{
T_6 V_120 ;
V_120 = V_2 -> V_148 ;
if ( ( ( V_2 -> V_65 & V_122 ) || ! ( V_2 -> V_65 & V_140 ) || ! V_2 -> V_133 ) ||
( ! ( V_2 -> V_63 & V_83 ) && ! ( V_2 -> V_69 . V_76 & V_83 ) )
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
& V_84 ) )
V_2 -> V_148 = V_153 ;
break;
case V_153 :
if ( ( V_2 -> V_69 . V_76 & V_84 ) ) {
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
V_84 ) )
V_2 -> V_148 = V_153 ;
else
V_2 -> V_148 = V_152 ;
break;
default:
break;
}
}
if ( V_2 -> V_148 != V_120 ) {
F_48 ( L_9 ,
V_2 -> V_35 , V_120 ,
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
V_2 -> V_85 = true ;
break;
default:
break;
}
}
}
static void F_55 ( struct V_2 * V_2 , bool * V_119 )
{
struct V_4 * V_4 , * V_156 = NULL , * V_157 ;
struct V_2 * V_158 = NULL , * V_159 ;
struct V_94 * V_95 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_160 = 0 ;
if ( V_2 -> V_65 & V_80 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_157 = V_2 -> V_4 ;
for ( V_159 = V_157 -> V_86 ; V_159 ;
V_158 = V_159 ,
V_159 = V_159 -> V_87 ) {
if ( V_159 == V_2 ) {
V_157 -> V_92 -- ;
if ( ! V_158 ) {
V_157 -> V_86 =
V_2 -> V_87 ;
} else {
V_158 -> V_87 =
V_2 -> V_87 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_87 = NULL ;
V_2 -> V_161 = 0 ;
F_21 ( V_5 -> V_34 , L_10 ,
V_2 -> V_35 ,
V_157 -> V_162 ) ;
if ( ! V_157 -> V_86 )
F_56 ( V_157 ) ;
break;
}
}
if ( ! V_159 ) {
F_57 ( L_11 ,
V_2 -> V_3 -> V_5 -> V_34 -> V_145 ,
V_2 -> V_35 ,
V_2 -> V_3 -> V_34 -> V_145 ,
V_2 -> V_4 -> V_162 ) ;
}
}
F_58 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_86 ) {
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
V_2 -> V_87 = V_4 -> V_86 ;
V_2 -> V_4 -> V_92 ++ ;
V_4 -> V_86 = V_2 ;
F_21 ( V_5 -> V_34 , L_12 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_162 ) ;
V_2 -> V_65 |= V_80 ;
V_160 = 1 ;
break;
}
}
if ( ! V_160 ) {
if ( V_156 ) {
V_2 -> V_4 = V_156 ;
V_2 -> V_161 =
V_2 -> V_4 -> V_162 ;
if ( V_2 -> V_60 & V_142 )
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
V_2 -> V_4 -> V_86 = V_2 ;
V_2 -> V_4 -> V_92 ++ ;
V_2 -> V_65 |= V_80 ;
F_21 ( V_5 -> V_34 , L_13 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_162 ) ;
} else {
F_52 ( V_5 -> V_34 , L_14 ,
V_2 -> V_35 , V_2 -> V_3 -> V_34 -> V_145 ) ;
}
}
F_33 ( V_2 -> V_4 ,
F_32 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_59 ( V_4 , V_119 ) ;
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
switch ( F_17 ( V_172 -> V_86 ) ) {
case V_173 :
if ( V_172 -> V_92 > V_171 -> V_92 )
return V_172 ;
if ( V_172 -> V_92 < V_171 -> V_92 )
return V_171 ;
case V_13 :
case V_174 :
if ( F_34 ( V_172 ) > F_34 ( V_171 ) )
return V_172 ;
break;
default:
F_57 ( L_15 ,
V_172 -> V_3 -> V_5 -> V_34 -> V_145 ,
F_17 ( V_172 -> V_86 ) ) ;
break;
}
return V_171 ;
}
static int F_61 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_86 ;
if ( ! V_2 )
return 0 ;
return F_62 ( V_2 -> V_3 -> V_34 ) &&
F_63 ( V_2 -> V_3 -> V_34 ) ;
}
static void F_59 ( struct V_4 * V_7 ,
bool * V_119 )
{
struct V_4 * V_171 , * V_175 , * V_176 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_94 * V_95 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_176 = V_7 ;
V_175 = F_35 ( V_7 ) ;
V_171 = ( V_175 && F_61 ( V_175 ) ) ? V_175 : NULL ;
F_36 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_96 = 0 ;
if ( V_7 -> V_92 && F_61 ( V_7 ) )
V_171 = F_60 ( V_171 , V_7 ) ;
}
if ( V_171 &&
F_17 ( V_171 -> V_86 ) == V_13 ) {
if ( V_175 && V_175 -> V_86 &&
V_175 -> V_86 -> V_133 &&
( F_8 ( V_175 ) ||
( ! F_8 ( V_175 ) &&
! F_8 ( V_171 ) ) ) ) {
if ( ! ( ! V_175 -> V_163 &&
V_171 -> V_163 ) ) {
V_171 = NULL ;
V_175 -> V_96 = 1 ;
}
}
}
if ( V_171 && ( V_171 == V_175 ) ) {
V_171 = NULL ;
V_175 -> V_96 = 1 ;
}
if ( V_171 ) {
F_21 ( V_5 -> V_34 , L_16 ,
V_171 -> V_162 , V_171 -> V_92 ,
V_171 -> V_163 ,
V_171 -> V_164 ,
V_171 -> V_166 , V_171 -> V_96 ) ;
F_21 ( V_5 -> V_34 , L_17 ,
V_171 -> V_86 , V_171 -> V_3 ,
V_171 -> V_3 ? V_171 -> V_3 -> V_34 -> V_145 : L_18 ) ;
F_36 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_21 ( V_5 -> V_34 , L_19 ,
V_7 -> V_162 , V_7 -> V_92 ,
V_7 -> V_163 ,
V_7 -> V_164 ,
V_7 -> V_166 , V_7 -> V_96 ) ;
}
if ( V_171 -> V_166 ) {
F_57 ( L_20 ,
V_171 -> V_3 ?
V_171 -> V_3 -> V_5 -> V_34 -> V_145 : L_18 ) ;
}
V_171 -> V_96 = 1 ;
F_21 ( V_5 -> V_34 , L_21 ,
V_171 -> V_162 ) ;
F_21 ( V_5 -> V_34 , L_19 ,
V_171 -> V_162 , V_171 -> V_92 ,
V_171 -> V_163 ,
V_171 -> V_164 ,
V_171 -> V_166 , V_171 -> V_96 ) ;
if ( V_175 ) {
for ( V_2 = V_175 -> V_86 ; V_2 ;
V_2 = V_2 -> V_87 ) {
F_10 ( V_2 ) ;
}
}
* V_119 = true ;
}
V_175 = F_35 ( V_176 ) ;
if ( V_175 ) {
if ( ! F_8 ( V_175 ) ) {
for ( V_2 = V_175 -> V_86 ; V_2 ;
V_2 = V_2 -> V_87 ) {
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
V_4 -> V_86 = NULL ;
V_4 -> V_96 = 0 ;
V_4 -> V_92 = 0 ;
F_48 ( L_22 ,
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
. V_188 = F_38 ( V_189 ) ,
} ;
if ( V_2 ) {
V_2 -> V_35 = 1 ;
V_2 -> V_55 = 0xff ;
V_2 -> V_56 = V_165 ;
V_2 -> V_58 = 0xffff ;
V_2 -> V_161 = 0 ;
V_2 -> V_85 = false ;
V_2 -> V_168 = 1 ;
V_2 -> V_60 = 1 ;
V_2 -> V_190 = V_62 |
V_83 ;
V_2 -> V_63 = V_62 |
V_83 ;
if ( V_178 )
V_2 -> V_63 |= V_84 ;
memcpy ( & V_2 -> V_79 , & V_179 , sizeof( V_179 ) ) ;
memcpy ( & V_2 -> V_69 , & V_179 , sizeof( V_179 ) ) ;
V_2 -> V_133 = true ;
V_2 -> V_65 = 0x3 ;
V_2 -> V_131 = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_148 = 0 ;
V_2 -> V_150 = 0 ;
V_2 -> V_121 = 0 ;
V_2 -> V_126 = 0 ;
V_2 -> V_191 = 0 ;
V_2 -> V_146 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_87 = NULL ;
V_2 -> V_192 = 0 ;
memcpy ( & V_2 -> V_52 , & V_52 , sizeof( V_52 ) ) ;
}
}
static void F_50 ( struct V_2 * V_2 ,
bool * V_119 )
{
if ( V_2 -> V_4 -> V_96 ) {
F_48 ( L_23 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_162 ) ;
F_12 ( V_2 ) ;
* V_119 = true ;
}
}
static void F_49 ( struct V_2 * V_2 ,
bool * V_119 )
{
if ( V_2 -> V_4 &&
! F_26 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_165 ) ) ) {
F_48 ( L_24 ,
V_2 -> V_35 ,
V_2 -> V_4 -> V_162 ) ;
F_10 ( V_2 ) ;
* V_119 = true ;
}
}
static void F_67 ( struct V_115 * V_193 ,
struct V_2 * V_2 )
{
struct V_115 V_116 ;
memcpy ( & V_116 , V_193 , sizeof( struct V_115 ) ) ;
V_116 . V_194 = V_195 ;
if ( F_45 ( V_2 , & V_116 ) >= 0 ) {
F_48 ( L_25 ,
V_2 -> V_35 ) ;
}
}
static void F_68 ( struct V_115 * V_116 ,
struct V_2 * V_2 )
{
V_116 = NULL ;
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
if ( ! ( V_2 -> V_60 & V_142 ) )
V_2 -> V_65 &= ~ V_140 ;
V_2 -> V_56 = F_19 ( V_5 ) . system . V_198 ;
V_2 -> V_146 = V_44 / V_147 ;
V_2 -> V_4 = NULL ;
V_2 -> V_87 = NULL ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_65 ( V_4 ) ;
V_4 -> V_177 = * ( (struct V_201 * ) V_5 -> V_34 -> V_199 ) ;
V_4 -> V_162 = ++ F_19 ( V_5 ) . V_162 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_96 = 0 ;
V_4 -> V_92 = 0 ;
}
}
void F_72 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_204 , * V_205 ;
struct V_4 * V_4 , * V_206 , * V_157 ;
int V_207 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_208 ;
struct V_94 * V_95 ;
bool V_209 ;
F_73 ( & V_5 -> V_210 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_74 ( V_5 -> V_34 , L_26 ,
V_3 -> V_34 -> V_145 ) ;
goto V_211;
}
F_21 ( V_5 -> V_34 , L_27 ,
V_4 -> V_162 ) ;
V_2 -> V_63 &= ~ V_62 ;
F_37 ( V_2 ) ;
F_39 ( V_2 ) ;
if ( V_4 -> V_86 ) {
if ( ( V_4 -> V_86 != V_2 ) ||
( V_4 -> V_86 -> V_87 ) ) {
F_58 (bond, slave_iter, iter) {
V_206 = & ( F_6 ( V_208 ) -> V_4 ) ;
if ( ! V_206 -> V_86 ||
( ( V_206 -> V_86 == V_2 ) &&
! V_206 -> V_86 -> V_87 ) )
break;
}
if ( ! V_208 )
V_206 = NULL ;
if ( ( V_206 ) && ( ( ! V_206 -> V_86 ) || ( ( V_206 -> V_86 == V_2 ) && ! V_206 -> V_86 -> V_87 ) ) ) {
F_21 ( V_5 -> V_34 , L_28 ,
V_4 -> V_162 ,
V_206 -> V_162 ) ;
if ( ( V_206 -> V_86 == V_2 ) &&
V_206 -> V_96 ) {
F_75 ( V_5 -> V_34 , L_29 ) ;
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
V_206 -> V_86 = V_4 -> V_86 ;
V_206 -> V_96 = V_4 -> V_96 ;
V_206 -> V_92 = V_4 -> V_92 ;
for ( V_205 = V_4 -> V_86 ; V_205 ;
V_205 = V_205 -> V_87 ) {
V_205 -> V_4 = V_206 ;
V_205 -> V_161 = V_206 -> V_162 ;
}
F_56 ( V_4 ) ;
if ( V_207 )
F_59 ( F_3 ( V_2 ) ,
& V_209 ) ;
} else {
F_74 ( V_5 -> V_34 , L_30 ) ;
}
} else {
V_207 = V_4 -> V_96 ;
F_56 ( V_4 ) ;
if ( V_207 ) {
F_75 ( V_5 -> V_34 , L_29 ) ;
V_157 = F_3 ( V_2 ) ;
if ( V_157 )
F_59 ( V_157 ,
& V_209 ) ;
}
}
}
F_21 ( V_5 -> V_34 , L_31 , V_2 -> V_35 ) ;
F_58 (bond, slave_iter, iter) {
V_157 = & ( F_6 ( V_208 ) -> V_4 ) ;
V_204 = NULL ;
for ( V_205 = V_157 -> V_86 ; V_205 ;
V_204 = V_205 ,
V_205 = V_205 -> V_87 ) {
if ( V_205 == V_2 ) {
if ( V_204 )
V_204 -> V_87 = V_205 -> V_87 ;
else
V_157 -> V_86 = V_205 -> V_87 ;
V_157 -> V_92 -- ;
if ( V_157 -> V_92 == 0 ) {
V_207 = V_157 -> V_96 ;
F_56 ( V_157 ) ;
if ( V_207 ) {
F_75 ( V_5 -> V_34 , L_29 ) ;
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
struct V_94 * V_95 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_215 = V_10 ;
bool V_119 = false ;
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
F_57 ( L_32 ,
V_5 -> V_34 -> V_145 ) ;
goto V_216;
}
V_4 = F_3 ( V_2 ) ;
F_59 ( V_4 , & V_119 ) ;
}
F_64 ( V_5 ) ;
}
F_36 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_57 ( L_33 ,
V_5 -> V_34 -> V_145 ) ;
goto V_216;
}
F_51 ( NULL , V_2 ) ;
F_54 ( V_2 ) ;
F_55 ( V_2 , & V_119 ) ;
F_47 ( V_2 , & V_119 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_65 & V_122 )
V_2 -> V_65 &= ~ V_122 ;
}
V_216:
F_36 (bond, slave, iter) {
if ( V_3 -> V_217 ) {
V_215 = V_218 ;
break;
}
}
F_7 () ;
F_76 ( & V_5 -> V_210 ) ;
if ( V_119 )
F_80 ( V_5 , 0 ) ;
if ( V_215 && F_81 () ) {
F_82 ( V_5 ) ;
F_83 () ;
}
F_84 ( V_5 -> V_219 , & V_5 -> V_214 , V_220 ) ;
}
static int F_85 ( struct V_52 * V_52 , struct V_3 * V_3 ,
T_2 V_100 )
{
struct V_2 * V_2 ;
int V_221 = V_222 ;
if ( V_100 >= sizeof( struct V_52 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_57 ( L_34 ,
V_3 -> V_34 -> V_145 , V_3 -> V_5 -> V_34 -> V_145 ) ;
return V_221 ;
}
switch ( V_52 -> V_180 ) {
case V_223 :
V_221 = V_224 ;
F_21 ( V_3 -> V_5 -> V_34 , L_35 ,
V_2 -> V_35 ) ;
F_86 ( & V_3 -> V_5 -> V_210 ) ;
F_51 ( V_52 , V_2 ) ;
F_87 ( & V_3 -> V_5 -> V_210 ) ;
break;
case V_225 :
V_221 = V_224 ;
switch ( ( (struct V_115 * ) V_52 ) -> V_194 ) {
case V_226 :
F_21 ( V_3 -> V_5 -> V_34 , L_36 ,
V_2 -> V_35 ) ;
F_67 ( (struct V_115 * ) V_52 , V_2 ) ;
break;
case V_195 :
F_21 ( V_3 -> V_5 -> V_34 , L_37 ,
V_2 -> V_35 ) ;
F_68 ( (struct V_115 * ) V_52 , V_2 ) ;
break;
default:
F_21 ( V_3 -> V_5 -> V_34 , L_38 ,
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
F_74 ( V_3 -> V_5 -> V_34 , L_39 ,
V_3 -> V_34 -> V_145 ) ;
return;
}
F_73 ( & V_3 -> V_5 -> V_210 ) ;
V_2 -> V_168 &= ~ V_227 ;
V_2 -> V_60 = V_2 -> V_168 |=
( F_20 ( V_2 ) << 1 ) ;
F_21 ( V_3 -> V_5 -> V_34 , L_40 , V_2 -> V_35 ) ;
V_2 -> V_65 |= V_122 ;
F_76 ( & V_3 -> V_5 -> V_210 ) ;
}
void F_89 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_74 ( V_3 -> V_5 -> V_34 , L_41 ,
V_3 -> V_34 -> V_145 ) ;
return;
}
F_73 ( & V_3 -> V_5 -> V_210 ) ;
V_2 -> V_168 &= ~ V_142 ;
V_2 -> V_60 = V_2 -> V_168 |=
F_22 ( V_2 ) ;
F_21 ( V_3 -> V_5 -> V_34 , L_42 , V_2 -> V_35 ) ;
V_2 -> V_65 |= V_122 ;
F_76 ( & V_3 -> V_5 -> V_210 ) ;
}
void F_90 ( struct V_3 * V_3 , char V_11 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_74 ( V_3 -> V_5 -> V_34 , L_43 ,
V_3 -> V_34 -> V_145 ) ;
return;
}
F_73 ( & V_3 -> V_5 -> V_210 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_133 = true ;
V_2 -> V_168 &= ~ V_142 ;
V_2 -> V_60 = V_2 -> V_168 |=
F_22 ( V_2 ) ;
V_2 -> V_168 &= ~ V_227 ;
V_2 -> V_60 = V_2 -> V_168 |=
( F_20 ( V_2 ) << 1 ) ;
} else {
V_2 -> V_133 = false ;
V_2 -> V_168 &= ~ V_142 ;
V_2 -> V_60 = ( V_2 -> V_168 &=
~ V_227 ) ;
}
F_21 ( V_3 -> V_5 -> V_34 , L_44 ,
V_2 -> V_35 ,
V_11 == V_12 ? L_45 : L_46 ) ;
V_2 -> V_65 |= V_122 ;
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
V_175 = F_35 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_175 ) {
if ( V_175 -> V_92 < V_5 -> V_14 . V_228 ) {
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
struct V_94 * V_95 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_36 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_96 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( ! V_4 )
return - 1 ;
V_229 -> V_230 = V_4 -> V_162 ;
V_229 -> V_231 = V_4 -> V_92 ;
V_229 -> V_75 = V_4 -> V_163 ;
V_229 -> V_59 = V_4 -> V_164 ;
F_43 ( V_229 -> V_8 ,
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
int F_96 ( const struct V_97 * V_98 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
struct V_52 * V_52 , V_232 ;
if ( V_98 -> V_105 != V_106 )
return V_222 ;
V_52 = F_97 ( V_98 , 0 , sizeof( V_232 ) , & V_232 ) ;
if ( ! V_52 )
return V_222 ;
return F_85 ( V_52 , V_3 , V_98 -> V_233 ) ;
}
void F_98 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_94 * V_95 ;
struct V_3 * V_3 ;
int V_178 ;
V_178 = V_5 -> V_14 . V_178 ;
F_73 ( & V_5 -> V_210 ) ;
F_58 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_178 )
V_2 -> V_63 |= V_84 ;
else
V_2 -> V_63 &= ~ V_84 ;
}
F_76 ( & V_5 -> V_210 ) ;
}
