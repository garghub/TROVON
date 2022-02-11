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
static void F_23 ( struct V_2 * V_2 )
{
const struct V_1 * V_5 = F_2 ( V_2 -> V_3 ) ;
V_2 -> V_42 = F_19 ( V_5 ) . system . V_43 ;
V_2 -> V_44 = F_19 ( V_5 ) . system . V_45 ;
}
static T_2 F_24 ( T_2 V_46 , T_2 V_47 )
{
T_2 V_38 = 0 ;
switch ( V_46 ) {
case V_48 :
if ( V_47 )
V_38 = ( V_49 * V_50 ) ;
else
V_38 = ( V_51 * V_50 ) ;
break;
case V_52 :
V_38 = ( V_53 * V_50 ) ;
break;
case V_54 :
V_38 = ( V_47 * V_50 ) ;
break;
case V_55 :
V_38 = ( V_53 * V_50 ) ;
break;
case V_56 :
V_38 = ( V_57 * V_50 ) ;
break;
}
return V_38 ;
}
static void F_25 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
if ( ( ( F_26 ( V_58 -> V_59 ) == V_2 -> V_37 ) &&
( F_26 ( V_58 -> V_60 ) == V_2 -> V_61 ) &&
F_27 ( & ( V_58 -> V_8 ) , & ( V_2 -> V_42 ) ) &&
( F_26 ( V_58 -> V_62 ) == V_2 -> V_44 ) &&
( F_26 ( V_58 -> V_63 ) == V_2 -> V_64 ) &&
( ( V_58 -> V_65 & V_66 ) == ( V_2 -> V_67 & V_66 ) ) ) ||
( ( V_58 -> V_68 & V_66 ) == 0 )
) {
V_2 -> V_69 |= V_70 ;
} else {
V_2 -> V_69 &= ~ V_70 ;
}
}
static void F_28 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
if ( V_58 && V_2 ) {
struct V_71 * V_72 = & V_2 -> V_73 ;
F_25 ( V_58 , V_2 ) ;
V_72 -> V_74 = F_26 ( V_58 -> V_75 ) ;
V_72 -> V_76 = F_26 ( V_58 -> V_61 ) ;
V_72 -> system = V_58 -> V_42 ;
V_72 -> V_77 = F_26 ( V_58 -> V_44 ) ;
V_72 -> V_78 = F_26 ( V_58 -> V_79 ) ;
V_72 -> V_80 = V_58 -> V_68 ;
V_2 -> V_67 &= ~ V_81 ;
if ( ( V_2 -> V_69 & V_70 ) &&
( V_58 -> V_68 & V_82 ) ) {
V_72 -> V_80 |= V_82 ;
F_29 ( L_4 , V_2 -> V_3 -> V_36 -> V_83 ) ;
} else {
V_72 -> V_80 &= ~ V_82 ;
F_29 ( L_5 , V_2 -> V_3 -> V_36 -> V_83 ) ;
}
}
}
static void F_30 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_73 , & V_2 -> V_84 ,
sizeof( struct V_71 ) ) ;
V_2 -> V_67 |= V_81 ;
}
}
static void F_31 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
if ( V_58 && V_2 ) {
const struct V_71 * V_72 = & V_2 -> V_73 ;
if ( F_26 ( V_58 -> V_75 ) != V_72 -> V_74 ||
F_26 ( V_58 -> V_61 ) != V_72 -> V_76 ||
! F_27 ( & V_58 -> V_42 , & V_72 -> system ) ||
F_26 ( V_58 -> V_44 ) != V_72 -> V_77 ||
F_26 ( V_58 -> V_79 ) != V_72 -> V_78 ||
( V_58 -> V_68 & V_66 ) != ( V_72 -> V_80 & V_66 ) ) {
V_2 -> V_69 &= ~ V_85 ;
}
}
}
static void F_32 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_71 * V_86 = & V_2 -> V_84 ;
const struct V_71 * V_87 = & V_2 -> V_73 ;
if ( V_86 -> V_74 != V_87 -> V_74 ||
V_86 -> V_76 != V_87 -> V_76 ||
! F_27 ( & V_86 -> system , & V_87 -> system ) ||
V_86 -> V_77 != V_87 -> V_77 ||
V_86 -> V_78 != V_87 -> V_78 ||
( V_86 -> V_80 & V_66 )
!= ( V_87 -> V_80 & V_66 ) ) {
V_2 -> V_69 &= ~ V_85 ;
}
}
}
static void F_33 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
if ( V_58 && V_2 ) {
if ( ( F_26 ( V_58 -> V_59 ) != V_2 -> V_37 ) ||
( F_26 ( V_58 -> V_60 ) != V_2 -> V_61 ) ||
! F_27 ( & ( V_58 -> V_8 ) , & ( V_2 -> V_42 ) ) ||
( F_26 ( V_58 -> V_62 ) != V_2 -> V_44 ) ||
( F_26 ( V_58 -> V_63 ) != V_2 -> V_64 ) ||
( ( V_58 -> V_65 & V_88 ) != ( V_2 -> V_67 & V_88 ) ) ||
( ( V_58 -> V_65 & V_89 ) != ( V_2 -> V_67 & V_89 ) ) ||
( ( V_58 -> V_65 & V_82 ) != ( V_2 -> V_67 & V_82 ) ) ||
( ( V_58 -> V_65 & V_66 ) != ( V_2 -> V_67 & V_66 ) )
) {
V_2 -> V_90 = true ;
}
}
}
static int F_34 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_38 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_91 ;
V_2 ;
V_2 = V_2 -> V_92 ) {
if ( ! ( V_2 -> V_69 & V_93 ) ) {
V_38 = 0 ;
break;
}
}
}
return V_38 ;
}
static void F_35 ( struct V_4 * V_4 , int V_94 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_91 ; V_2 ;
V_2 = V_2 -> V_92 ) {
if ( V_94 )
V_2 -> V_69 |= V_95 ;
else
V_2 -> V_69 &= ~ V_95 ;
}
}
static int F_36 ( struct V_4 * V_7 )
{
struct V_2 * V_2 ;
int V_96 = 0 ;
for ( V_2 = V_7 -> V_91 ; V_2 ;
V_2 = V_2 -> V_92 ) {
if ( V_2 -> V_97 )
V_96 ++ ;
}
return V_96 ;
}
static T_1 F_37 ( struct V_4 * V_4 )
{
int V_98 = F_36 ( V_4 ) ;
T_1 V_99 = 0 ;
if ( V_98 ) {
switch ( F_20 ( V_4 -> V_91 ) ) {
case V_100 :
V_99 = V_98 ;
break;
case V_19 :
V_99 = V_98 * 10 ;
break;
case V_21 :
V_99 = V_98 * 100 ;
break;
case V_23 :
V_99 = V_98 * 1000 ;
break;
case V_25 :
V_99 = V_98 * 2500 ;
break;
case V_27 :
V_99 = V_98 * 10000 ;
break;
case V_29 :
V_99 = V_98 * 20000 ;
break;
case V_31 :
V_99 = V_98 * 40000 ;
break;
case V_33 :
V_99 = V_98 * 56000 ;
break;
case V_35 :
V_99 = V_98 * 100000 ;
break;
default:
V_99 = 0 ;
}
}
return V_99 ;
}
static struct V_4 * F_38 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_101 * V_102 ;
struct V_3 * V_3 ;
F_39 (bond, slave, iter)
if ( F_6 ( V_3 ) -> V_4 . V_103 )
return & ( F_6 ( V_3 ) -> V_4 ) ;
return NULL ;
}
static inline void F_40 ( struct V_2 * V_2 )
{
struct V_58 * V_58 = & V_2 -> V_58 ;
const struct V_71 * V_72 = & V_2 -> V_73 ;
V_58 -> V_44 = F_41 ( V_2 -> V_44 ) ;
V_58 -> V_42 = V_2 -> V_42 ;
V_58 -> V_79 = F_41 ( V_2 -> V_64 ) ;
V_58 -> V_61 = F_41 ( V_2 -> V_61 ) ;
V_58 -> V_75 = F_41 ( V_2 -> V_37 ) ;
V_58 -> V_68 = V_2 -> V_67 ;
F_29 ( L_6 ,
V_2 -> V_3 -> V_36 -> V_83 , V_2 -> V_67 ) ;
V_58 -> V_62 = F_41 ( V_72 -> V_77 ) ;
V_58 -> V_8 = V_72 -> system ;
V_58 -> V_63 = F_41 ( V_72 -> V_78 ) ;
V_58 -> V_60 = F_41 ( V_72 -> V_76 ) ;
V_58 -> V_59 = F_41 ( V_72 -> V_74 ) ;
V_58 -> V_65 = V_72 -> V_80 ;
}
static int F_42 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_104 * V_105 ;
struct V_106 * V_106 ;
int V_107 = sizeof( struct V_106 ) ;
V_105 = F_43 ( V_107 ) ;
if ( ! V_105 )
return - V_108 ;
V_105 -> V_36 = V_3 -> V_36 ;
F_44 ( V_105 ) ;
V_105 -> V_109 = V_105 -> V_110 + V_111 ;
V_105 -> V_112 = V_113 ;
V_105 -> V_114 = V_115 ;
V_106 = (struct V_106 * ) F_45 ( V_105 , V_107 ) ;
F_46 ( V_106 -> V_116 . V_117 , V_118 ) ;
F_46 ( V_106 -> V_116 . V_119 , V_3 -> V_120 ) ;
V_106 -> V_116 . V_121 = V_113 ;
V_106 -> V_58 = V_2 -> V_58 ;
F_47 ( V_105 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , struct V_122 * V_123 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_104 * V_105 ;
struct V_124 * V_125 ;
int V_107 = sizeof( struct V_124 ) ;
V_105 = F_43 ( V_107 + 16 ) ;
if ( ! V_105 )
return - V_108 ;
F_49 ( V_105 , 16 ) ;
V_105 -> V_36 = V_3 -> V_36 ;
F_44 ( V_105 ) ;
V_105 -> V_109 = V_105 -> V_110 + V_111 ;
V_105 -> V_112 = V_113 ;
V_125 = (struct V_124 * ) F_45 ( V_105 , V_107 ) ;
F_46 ( V_125 -> V_116 . V_117 , V_118 ) ;
F_46 ( V_125 -> V_116 . V_119 , V_3 -> V_120 ) ;
V_125 -> V_116 . V_121 = V_113 ;
V_125 -> V_123 = * V_123 ;
F_47 ( V_105 ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_2 , bool * V_126 )
{
T_4 V_127 ;
V_127 = V_2 -> V_128 ;
if ( V_2 -> V_69 & V_129 ) {
V_2 -> V_128 = V_130 ;
} else {
switch ( V_2 -> V_128 ) {
case V_130 :
if ( ( V_2 -> V_69 & V_85 )
|| ( V_2 -> V_69 & V_131 ) )
V_2 -> V_128 = V_132 ;
break;
case V_132 :
if ( ! ( V_2 -> V_69 & V_85 ) ) {
V_2 -> V_69 &= ~ V_93 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
V_2 -> V_128 = V_130 ;
break;
}
if ( V_2 -> V_133
&& ! ( -- V_2 -> V_133 ) )
V_2 -> V_69 |= V_93 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_69 & V_95 )
&& ! V_2 -> V_133 )
V_2 -> V_128 = V_134 ;
break;
case V_134 :
if ( ( V_2 -> V_69 & V_85 ) &&
( V_2 -> V_73 . V_80 & V_82 ) &&
! F_18 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_103 )
V_2 -> V_128 =
V_135 ;
} else if ( ! ( V_2 -> V_69 & V_85 ) ||
( V_2 -> V_69 & V_131 ) ) {
V_2 -> V_69 &= ~ V_93 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
V_2 -> V_128 = V_130 ;
} else if ( V_2 -> V_4 -> V_103 ) {
V_2 -> V_67 |=
V_82 ;
}
break;
case V_135 :
if ( ! ( V_2 -> V_69 & V_85 ) ||
( V_2 -> V_69 & V_131 ) ||
! ( V_2 -> V_73 . V_80 & V_82 ) ||
! ( V_2 -> V_67 & V_82 ) ) {
V_2 -> V_128 = V_134 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_103 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_128 != V_127 ) {
F_29 ( L_7 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_83 ,
V_127 ,
V_2 -> V_128 ) ;
switch ( V_2 -> V_128 ) {
case V_130 :
V_2 -> V_67 &= ~ V_82 ;
F_51 ( V_2 ,
V_126 ) ;
V_2 -> V_67 &= ~ V_136 ;
V_2 -> V_67 &= ~ V_137 ;
V_2 -> V_90 = true ;
break;
case V_132 :
V_2 -> V_133 = F_24 ( V_56 , 0 ) ;
break;
case V_134 :
if ( V_2 -> V_4 -> V_103 )
V_2 -> V_67 |=
V_82 ;
else
V_2 -> V_67 &=
~ V_82 ;
V_2 -> V_67 &= ~ V_136 ;
V_2 -> V_67 &= ~ V_137 ;
F_51 ( V_2 ,
V_126 ) ;
V_2 -> V_90 = true ;
break;
case V_135 :
V_2 -> V_67 |= V_136 ;
V_2 -> V_67 |= V_137 ;
V_2 -> V_67 |= V_82 ;
F_52 ( V_2 ,
V_126 ) ;
V_2 -> V_90 = true ;
break;
default:
break;
}
}
}
static void F_53 ( struct V_58 * V_58 , struct V_2 * V_2 )
{
T_5 V_127 ;
V_127 = V_2 -> V_138 ;
if ( V_2 -> V_69 & V_129 ) {
V_2 -> V_138 = V_139 ;
V_2 -> V_69 |= V_140 ;
} else if ( ! ( V_2 -> V_69 & V_129 )
&& ! V_2 -> V_97 && ! ( V_2 -> V_69 & V_141 ) )
V_2 -> V_138 = V_142 ;
else if ( V_58 && ( ( V_2 -> V_138 == V_143 ) ||
( V_2 -> V_138 == V_144 ) ||
( V_2 -> V_138 == V_145 ) ) ) {
if ( V_2 -> V_138 != V_145 )
V_2 -> V_69 |= V_140 ;
V_2 -> V_146 = 0 ;
V_2 -> V_138 = V_145 ;
} else {
if ( V_2 -> V_146 &&
! ( -- V_2 -> V_146 ) ) {
switch ( V_2 -> V_138 ) {
case V_143 :
V_2 -> V_138 = V_144 ;
break;
case V_145 :
V_2 -> V_138 = V_143 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_138 ) {
case V_142 :
if ( V_2 -> V_69 & V_141 )
V_2 -> V_138 = V_139 ;
else if ( V_2 -> V_97
&& ( V_2 -> V_69
& V_147 ) )
V_2 -> V_138 = V_143 ;
else if ( V_2 -> V_97
&& ( ( V_2 -> V_69
& V_147 ) == 0 ) )
V_2 -> V_138 = V_148 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_138 != V_127 ) || ( V_58 ) ) {
F_29 ( L_8 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_83 ,
V_127 ,
V_2 -> V_138 ) ;
switch ( V_2 -> V_138 ) {
case V_139 :
if ( ! ( V_2 -> V_64 & V_149 ) )
V_2 -> V_69 &= ~ V_147 ;
else
V_2 -> V_69 |= V_147 ;
V_2 -> V_69 &= ~ V_85 ;
F_30 ( V_2 ) ;
V_2 -> V_67 &= ~ V_150 ;
V_2 -> V_69 &= ~ V_141 ;
V_2 -> V_138 = V_142 ;
case V_142 :
V_2 -> V_69 &= ~ V_70 ;
break;
case V_148 :
V_2 -> V_69 &= ~ V_85 ;
F_30 ( V_2 ) ;
V_2 -> V_73 . V_80 &= ~ V_66 ;
V_2 -> V_69 |= V_70 ;
V_2 -> V_67 &= ~ V_150 ;
break;
case V_143 :
V_2 -> V_73 . V_80 &= ~ V_82 ;
V_2 -> V_69 &= ~ V_70 ;
V_2 -> V_73 . V_80 |= V_89 ;
V_2 -> V_73 . V_80 |= V_88 ;
V_2 -> V_146 = F_24 ( V_48 , ( T_2 ) ( V_151 ) ) ;
V_2 -> V_67 |= V_150 ;
V_2 -> V_69 |= V_140 ;
break;
case V_144 :
F_32 ( V_2 ) ;
F_30 ( V_2 ) ;
V_2 -> V_69 |= V_70 ;
V_2 -> V_67 &= ~ V_150 ;
break;
case V_145 :
if ( F_27 ( & ( V_58 -> V_42 ) ,
& ( V_2 -> V_42 ) ) ) {
F_54 ( V_2 -> V_3 -> V_5 -> V_36 , L_9
L_10 ,
V_2 -> V_3 -> V_36 -> V_83 ) ;
return;
}
F_31 ( V_58 , V_2 ) ;
F_33 ( V_58 , V_2 ) ;
F_28 ( V_58 , V_2 ) ;
V_2 -> V_146 = F_24 ( V_48 , ( T_2 ) ( V_2 -> V_67 & V_89 ) ) ;
V_2 -> V_67 &= ~ V_150 ;
break;
default:
break;
}
}
}
static void F_55 ( struct V_2 * V_2 )
{
if ( V_2 -> V_69 & V_140 ) {
V_2 -> V_69 &= ~ V_140 ;
V_2 -> V_152 = V_153 ;
V_2 -> V_154 = V_153 ;
V_2 -> V_155 =
F_24 ( V_52 , 0 ) ;
V_2 -> V_156 =
F_24 ( V_55 , 0 ) ;
return;
}
if ( V_2 -> V_155 &&
! ( -- V_2 -> V_155 ) &&
V_2 -> V_152 == V_153 ) {
if ( V_2 -> V_67 & V_82 ) {
V_2 -> V_152 = V_157 ;
} else {
V_2 -> V_158 ++ ;
V_2 -> V_152 = V_159 ;
}
}
if ( V_2 -> V_156 &&
! ( -- V_2 -> V_156 ) &&
V_2 -> V_154 == V_153 ) {
if ( V_2 -> V_73 . V_80 & V_82 ) {
V_2 -> V_154 = V_157 ;
} else {
V_2 -> V_160 ++ ;
V_2 -> V_154 = V_159 ;
}
}
}
static void F_56 ( struct V_2 * V_2 )
{
if ( V_2 -> V_161 && ! ( -- V_2 -> V_161 ) ) {
if ( V_2 -> V_90 && ( V_2 -> V_69 & V_147 ) ) {
F_40 ( V_2 ) ;
if ( F_42 ( V_2 ) >= 0 ) {
F_29 ( L_11 ,
V_2 -> V_37 ) ;
V_2 -> V_90 = false ;
}
}
V_2 -> V_161 = V_50 / V_162 ;
}
}
static void F_57 ( struct V_2 * V_2 )
{
T_6 V_127 ;
V_127 = V_2 -> V_163 ;
if ( ( ( V_2 -> V_69 & V_129 ) || ! ( V_2 -> V_69 & V_147 ) || ! V_2 -> V_97 ) ||
( ! ( V_2 -> V_67 & V_88 ) && ! ( V_2 -> V_73 . V_80 & V_88 ) )
) {
V_2 -> V_163 = V_164 ;
}
else if ( V_2 -> V_165 ) {
if ( ! ( -- V_2 -> V_165 ) ) {
V_2 -> V_163 = V_166 ;
} else {
switch ( V_2 -> V_163 ) {
case V_167 :
if ( ! ( V_2 -> V_73 . V_80
& V_89 ) )
V_2 -> V_163 = V_168 ;
break;
case V_168 :
if ( ( V_2 -> V_73 . V_80 & V_89 ) ) {
V_2 -> V_165 = 0 ;
V_2 -> V_163 = V_166 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_163 ) {
case V_164 :
V_2 -> V_163 = V_167 ;
break;
case V_166 :
if ( ! ( V_2 -> V_73 . V_80 &
V_89 ) )
V_2 -> V_163 = V_168 ;
else
V_2 -> V_163 = V_167 ;
break;
default:
break;
}
}
if ( V_2 -> V_163 != V_127 ) {
F_29 ( L_12 ,
V_2 -> V_37 , V_127 ,
V_2 -> V_163 ) ;
switch ( V_2 -> V_163 ) {
case V_164 :
V_2 -> V_165 = 0 ;
break;
case V_167 :
V_2 -> V_165 = F_24 ( V_54 , ( T_2 ) ( V_169 ) ) - 1 ;
break;
case V_168 :
V_2 -> V_165 = F_24 ( V_54 , ( T_2 ) ( V_170 ) ) - 1 ;
break;
case V_166 :
V_2 -> V_90 = true ;
break;
default:
break;
}
}
}
static void F_58 ( struct V_2 * V_2 , bool * V_126 )
{
struct V_4 * V_4 , * V_171 = NULL , * V_172 ;
struct V_2 * V_173 = NULL , * V_174 ;
struct V_101 * V_102 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_175 = 0 ;
if ( V_2 -> V_69 & V_85 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_172 = V_2 -> V_4 ;
for ( V_174 = V_172 -> V_91 ; V_174 ;
V_173 = V_174 ,
V_174 = V_174 -> V_92 ) {
if ( V_174 == V_2 ) {
V_172 -> V_176 -- ;
if ( ! V_173 ) {
V_172 -> V_91 =
V_2 -> V_92 ;
} else {
V_173 -> V_92 =
V_2 -> V_92 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_92 = NULL ;
V_2 -> V_177 = 0 ;
F_21 ( V_5 -> V_36 , L_13 ,
V_2 -> V_37 ,
V_172 -> V_178 ) ;
if ( ! V_172 -> V_91 )
F_59 ( V_172 ) ;
break;
}
}
if ( ! V_174 ) {
F_60 ( L_14 ,
V_2 -> V_3 -> V_5 -> V_36 -> V_83 ,
V_2 -> V_37 ,
V_2 -> V_3 -> V_36 -> V_83 ,
V_2 -> V_4 -> V_178 ) ;
}
}
F_61 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_91 ) {
if ( ! V_171 )
V_171 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_179 == V_2 -> V_64 ) &&
F_27 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_73 . system ) ) &&
( V_4 -> V_62 == V_2 -> V_73 . V_77 ) &&
( V_4 -> V_180 == V_2 -> V_73 . V_78 )
) &&
( ( ! F_27 ( & ( V_2 -> V_73 . system ) , & ( V_181 ) ) &&
! V_4 -> V_182 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_177 =
V_2 -> V_4 -> V_178 ;
V_2 -> V_92 = V_4 -> V_91 ;
V_2 -> V_4 -> V_176 ++ ;
V_4 -> V_91 = V_2 ;
F_21 ( V_5 -> V_36 , L_15 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_178 ) ;
V_2 -> V_69 |= V_85 ;
V_175 = 1 ;
break;
}
}
if ( ! V_175 ) {
if ( V_171 ) {
V_2 -> V_4 = V_171 ;
V_2 -> V_177 =
V_2 -> V_4 -> V_178 ;
if ( V_2 -> V_64 & V_149 )
V_2 -> V_4 -> V_182 = false ;
else
V_2 -> V_4 -> V_182 = true ;
V_2 -> V_4 -> V_183 =
V_2 -> V_184 ;
V_2 -> V_4 -> V_179 =
V_2 -> V_64 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_73 . system ;
V_2 -> V_4 -> V_62 =
V_2 -> V_73 . V_77 ;
V_2 -> V_4 -> V_180 = V_2 -> V_73 . V_78 ;
V_2 -> V_4 -> V_185 = 1 ;
V_2 -> V_4 -> V_186 = 1 ;
V_2 -> V_4 -> V_91 = V_2 ;
V_2 -> V_4 -> V_176 ++ ;
V_2 -> V_69 |= V_85 ;
F_21 ( V_5 -> V_36 , L_16 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_178 ) ;
} else {
F_54 ( V_5 -> V_36 , L_17 ,
V_2 -> V_37 , V_2 -> V_3 -> V_36 -> V_83 ) ;
}
}
F_35 ( V_2 -> V_4 ,
F_34 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_62 ( V_4 , V_126 ) ;
if ( ! V_2 -> V_4 -> V_103 )
V_2 -> V_67 &= ~ V_82 ;
}
static struct V_4 * F_63 ( struct V_4 * V_187 ,
struct V_4 * V_188 )
{
if ( ! V_187 )
return V_188 ;
if ( ! V_188 -> V_182 && V_187 -> V_182 )
return V_188 ;
if ( V_188 -> V_182 && ! V_187 -> V_182 )
return V_187 ;
if ( F_8 ( V_188 ) && ! F_8 ( V_187 ) )
return V_188 ;
if ( ! F_8 ( V_188 ) && F_8 ( V_187 ) )
return V_187 ;
switch ( F_17 ( V_188 -> V_91 ) ) {
case V_189 :
if ( F_36 ( V_188 ) > F_36 ( V_187 ) )
return V_188 ;
if ( F_36 ( V_188 ) < F_36 ( V_187 ) )
return V_187 ;
case V_13 :
case V_190 :
if ( F_37 ( V_188 ) > F_37 ( V_187 ) )
return V_188 ;
break;
default:
F_60 ( L_18 ,
V_188 -> V_3 -> V_5 -> V_36 -> V_83 ,
F_17 ( V_188 -> V_91 ) ) ;
break;
}
return V_187 ;
}
static int F_64 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_91 ;
if ( ! V_2 )
return 0 ;
for ( V_2 = V_7 -> V_91 ; V_2 ;
V_2 = V_2 -> V_92 ) {
if ( F_65 ( V_2 -> V_3 -> V_36 ) &&
F_66 ( V_2 -> V_3 -> V_36 ) )
return 1 ;
}
return 0 ;
}
static void F_62 ( struct V_4 * V_7 ,
bool * V_126 )
{
struct V_4 * V_187 , * V_96 , * V_191 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_101 * V_102 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_191 = V_7 ;
V_96 = F_38 ( V_7 ) ;
V_187 = ( V_96 && F_64 ( V_96 ) ) ? V_96 : NULL ;
F_39 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_103 = 0 ;
if ( F_36 ( V_7 ) && F_64 ( V_7 ) )
V_187 = F_63 ( V_187 , V_7 ) ;
}
if ( V_187 &&
F_17 ( V_187 -> V_91 ) == V_13 ) {
if ( V_96 && V_96 -> V_91 &&
F_36 ( V_96 ) &&
( F_8 ( V_96 ) ||
( ! F_8 ( V_96 ) &&
! F_8 ( V_187 ) ) ) ) {
if ( ! ( ! V_96 -> V_179 &&
V_187 -> V_179 ) ) {
V_187 = NULL ;
V_96 -> V_103 = 1 ;
}
}
}
if ( V_187 && ( V_187 == V_96 ) ) {
V_187 = NULL ;
V_96 -> V_103 = 1 ;
}
if ( V_187 ) {
F_21 ( V_5 -> V_36 , L_19 ,
V_187 -> V_178 , V_187 -> V_176 ,
V_187 -> V_179 ,
V_187 -> V_180 ,
V_187 -> V_182 , V_187 -> V_103 ) ;
F_21 ( V_5 -> V_36 , L_20 ,
V_187 -> V_91 , V_187 -> V_3 ,
V_187 -> V_3 ? V_187 -> V_3 -> V_36 -> V_83 : L_21 ) ;
F_39 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_21 ( V_5 -> V_36 , L_22 ,
V_7 -> V_178 , V_7 -> V_176 ,
V_7 -> V_179 ,
V_7 -> V_180 ,
V_7 -> V_182 , V_7 -> V_103 ) ;
}
if ( V_187 -> V_182 ) {
F_60 ( L_23 ,
V_187 -> V_3 ?
V_187 -> V_3 -> V_5 -> V_36 -> V_83 : L_21 ) ;
}
V_187 -> V_103 = 1 ;
F_21 ( V_5 -> V_36 , L_24 ,
V_187 -> V_178 ) ;
F_21 ( V_5 -> V_36 , L_22 ,
V_187 -> V_178 , V_187 -> V_176 ,
V_187 -> V_179 ,
V_187 -> V_180 ,
V_187 -> V_182 , V_187 -> V_103 ) ;
if ( V_96 ) {
for ( V_2 = V_96 -> V_91 ; V_2 ;
V_2 = V_2 -> V_92 ) {
F_10 ( V_2 ) ;
}
}
* V_126 = true ;
}
V_96 = F_38 ( V_191 ) ;
if ( V_96 ) {
if ( ! F_8 ( V_96 ) ) {
for ( V_2 = V_96 -> V_91 ; V_2 ;
V_2 = V_2 -> V_92 ) {
F_12 ( V_2 ) ;
}
}
}
F_7 () ;
F_67 ( V_5 ) ;
}
static void F_59 ( struct V_4 * V_4 )
{
if ( V_4 ) {
V_4 -> V_182 = false ;
V_4 -> V_183 = 0 ;
V_4 -> V_179 = 0 ;
F_68 ( V_4 -> V_8 . V_9 ) ;
V_4 -> V_62 = 0 ;
V_4 -> V_180 = 0 ;
V_4 -> V_185 = 0 ;
V_4 -> V_186 = 0 ;
V_4 -> V_91 = NULL ;
V_4 -> V_103 = 0 ;
V_4 -> V_176 = 0 ;
F_29 ( L_25 ,
V_4 -> V_178 ) ;
}
}
static void F_69 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_59 ( V_4 ) ;
F_68 ( V_4 -> V_192 . V_9 ) ;
V_4 -> V_178 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_70 ( struct V_2 * V_2 , int V_193 )
{
static const struct V_71 V_194 = {
. V_77 = 0xffff ,
. V_78 = 1 ,
. V_74 = 1 ,
. V_76 = 0xff ,
. V_80 = 1 ,
} ;
static const struct V_58 V_58 = {
. V_195 = 0x01 ,
. V_196 = 0x01 ,
. V_197 = 0x01 ,
. V_198 = 0x14 ,
. V_199 = 0x02 ,
. V_200 = 0x14 ,
. V_201 = 0x03 ,
. V_202 = 0x10 ,
. V_203 = F_41 ( V_204 ) ,
} ;
if ( V_2 ) {
V_2 -> V_61 = 0xff ;
V_2 -> V_177 = 0 ;
V_2 -> V_90 = false ;
V_2 -> V_205 = V_66 |
V_88 ;
V_2 -> V_67 = V_66 |
V_88 ;
if ( V_193 )
V_2 -> V_67 |= V_89 ;
memcpy ( & V_2 -> V_84 , & V_194 , sizeof( V_194 ) ) ;
memcpy ( & V_2 -> V_73 , & V_194 , sizeof( V_194 ) ) ;
V_2 -> V_97 = true ;
V_2 -> V_69 = V_129 | V_147 ;
V_2 -> V_138 = 0 ;
V_2 -> V_146 = 0 ;
V_2 -> V_163 = 0 ;
V_2 -> V_165 = 0 ;
V_2 -> V_128 = 0 ;
V_2 -> V_133 = 0 ;
V_2 -> V_206 = 0 ;
V_2 -> V_4 = NULL ;
V_2 -> V_92 = NULL ;
V_2 -> V_207 = 0 ;
V_2 -> V_155 = 0 ;
V_2 -> V_152 = 0 ;
V_2 -> V_158 = 0 ;
V_2 -> V_156 = 0 ;
V_2 -> V_154 = 0 ;
V_2 -> V_160 = 0 ;
memcpy ( & V_2 -> V_58 , & V_58 , sizeof( V_58 ) ) ;
}
}
static void F_52 ( struct V_2 * V_2 ,
bool * V_126 )
{
if ( V_2 -> V_4 -> V_103 ) {
F_29 ( L_26 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_178 ) ;
F_12 ( V_2 ) ;
* V_126 = true ;
}
}
static void F_51 ( struct V_2 * V_2 ,
bool * V_126 )
{
if ( V_2 -> V_4 &&
! F_27 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_181 ) ) ) {
F_29 ( L_27 ,
V_2 -> V_37 ,
V_2 -> V_4 -> V_178 ) ;
F_10 ( V_2 ) ;
* V_126 = true ;
}
}
static void F_71 ( struct V_122 * V_208 ,
struct V_2 * V_2 )
{
struct V_122 V_123 ;
memcpy ( & V_123 , V_208 , sizeof( struct V_122 ) ) ;
V_123 . V_209 = V_210 ;
if ( F_48 ( V_2 , & V_123 ) >= 0 ) {
F_29 ( L_28 ,
V_2 -> V_37 ) ;
}
}
static void F_72 ( struct V_122 * V_123 ,
struct V_2 * V_2 )
{
}
void F_73 ( struct V_1 * V_5 , int V_211 )
{
F_19 ( V_5 ) . V_16 = V_211 ;
}
void F_74 ( struct V_1 * V_5 , T_2 V_212 )
{
if ( ! F_27 ( & ( F_19 ( V_5 ) . system . V_43 ) ,
V_5 -> V_36 -> V_213 ) ) {
F_19 ( V_5 ) . V_178 = 0 ;
F_19 ( V_5 ) . system . V_45 =
V_5 -> V_14 . V_214 ;
if ( F_9 ( V_5 -> V_14 . V_215 ) )
F_19 ( V_5 ) . system . V_43 =
* ( (struct V_216 * ) V_5 -> V_36 -> V_213 ) ;
else
F_19 ( V_5 ) . system . V_43 =
* ( (struct V_216 * ) V_5 -> V_14 . V_215 ) ;
V_50 = V_212 ;
F_73 ( V_5 ,
V_217 *
V_50 ) ;
}
}
void F_75 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) -> V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_70 ( V_2 , V_5 -> V_14 . V_193 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_37 = F_6 ( V_3 ) -> V_218 ;
V_2 -> V_184 = V_5 -> V_14 . V_219 << 6 ;
F_76 ( V_2 , false ) ;
F_23 ( V_2 ) ;
V_2 -> V_161 = V_50 / V_162 ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_69 ( V_4 ) ;
V_4 -> V_192 = * ( (struct V_216 * ) V_5 -> V_36 -> V_213 ) ;
V_4 -> V_178 = ++ F_19 ( V_5 ) . V_178 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_103 = 0 ;
V_4 -> V_176 = 0 ;
}
}
void F_77 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_220 , * V_221 ;
struct V_4 * V_4 , * V_222 , * V_172 ;
int V_223 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_224 ;
struct V_101 * V_102 ;
bool V_225 ;
F_78 ( & V_5 -> V_226 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_5 -> V_36 , L_29 ,
V_3 -> V_36 -> V_83 ) ;
goto V_227;
}
F_21 ( V_5 -> V_36 , L_30 ,
V_4 -> V_178 ) ;
V_2 -> V_67 &= ~ V_66 ;
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( V_4 -> V_91 ) {
if ( ( V_4 -> V_91 != V_2 ) ||
( V_4 -> V_91 -> V_92 ) ) {
F_61 (bond, slave_iter, iter) {
V_222 = & ( F_6 ( V_224 ) -> V_4 ) ;
if ( ! V_222 -> V_91 ||
( ( V_222 -> V_91 == V_2 ) &&
! V_222 -> V_91 -> V_92 ) )
break;
}
if ( ! V_224 )
V_222 = NULL ;
if ( ( V_222 ) && ( ( ! V_222 -> V_91 ) || ( ( V_222 -> V_91 == V_2 ) && ! V_222 -> V_91 -> V_92 ) ) ) {
F_21 ( V_5 -> V_36 , L_31 ,
V_4 -> V_178 ,
V_222 -> V_178 ) ;
if ( ( V_222 -> V_91 == V_2 ) &&
V_222 -> V_103 ) {
F_80 ( V_5 -> V_36 , L_32 ) ;
V_223 = 1 ;
}
V_222 -> V_182 = V_4 -> V_182 ;
V_222 -> V_183 = V_4 -> V_183 ;
V_222 -> V_179 = V_4 -> V_179 ;
V_222 -> V_8 = V_4 -> V_8 ;
V_222 -> V_62 = V_4 -> V_62 ;
V_222 -> V_180 = V_4 -> V_180 ;
V_222 -> V_185 = V_4 -> V_185 ;
V_222 -> V_186 = V_4 -> V_186 ;
V_222 -> V_91 = V_4 -> V_91 ;
V_222 -> V_103 = V_4 -> V_103 ;
V_222 -> V_176 = V_4 -> V_176 ;
for ( V_221 = V_4 -> V_91 ; V_221 ;
V_221 = V_221 -> V_92 ) {
V_221 -> V_4 = V_222 ;
V_221 -> V_177 = V_222 -> V_178 ;
}
F_59 ( V_4 ) ;
if ( V_223 )
F_62 ( F_3 ( V_2 ) ,
& V_225 ) ;
} else {
F_79 ( V_5 -> V_36 , L_33 ) ;
}
} else {
V_223 = V_4 -> V_103 ;
F_59 ( V_4 ) ;
if ( V_223 ) {
F_80 ( V_5 -> V_36 , L_32 ) ;
V_172 = F_3 ( V_2 ) ;
if ( V_172 )
F_62 ( V_172 ,
& V_225 ) ;
}
}
}
F_21 ( V_5 -> V_36 , L_34 , V_2 -> V_37 ) ;
F_61 (bond, slave_iter, iter) {
V_172 = & ( F_6 ( V_224 ) -> V_4 ) ;
V_220 = NULL ;
for ( V_221 = V_172 -> V_91 ; V_221 ;
V_220 = V_221 ,
V_221 = V_221 -> V_92 ) {
if ( V_221 == V_2 ) {
if ( V_220 )
V_220 -> V_92 = V_221 -> V_92 ;
else
V_172 -> V_91 = V_221 -> V_92 ;
V_172 -> V_176 -- ;
if ( F_36 ( V_172 ) == 0 ) {
V_223 = V_172 -> V_103 ;
F_59 ( V_172 ) ;
if ( V_223 ) {
F_80 ( V_5 -> V_36 , L_32 ) ;
F_62 ( F_3 ( V_2 ) ,
& V_225 ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
V_227:
F_81 ( & V_5 -> V_226 ) ;
}
void F_82 ( struct V_1 * V_5 )
{
struct V_101 * V_102 ;
struct V_3 * V_3 ;
F_83 () ;
F_19 ( V_5 ) . system . V_45 = V_5 -> V_14 . V_214 ;
if ( F_9 ( V_5 -> V_14 . V_215 ) )
F_19 ( V_5 ) . system . V_43 =
* ( (struct V_216 * ) V_5 -> V_36 -> V_213 ) ;
else
F_19 ( V_5 ) . system . V_43 =
* ( (struct V_216 * ) V_5 -> V_14 . V_215 ) ;
F_78 ( & V_5 -> V_226 ) ;
F_61 (bond, slave, iter) {
struct V_2 * V_2 = & ( F_6 ( V_3 ) ) -> V_2 ;
F_23 ( V_2 ) ;
V_2 -> V_90 = true ;
}
F_81 ( & V_5 -> V_226 ) ;
}
void F_84 ( struct V_228 * V_229 )
{
struct V_1 * V_5 = F_85 ( V_229 , struct V_1 ,
V_230 . V_229 ) ;
struct V_4 * V_4 ;
struct V_101 * V_102 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_231 = V_10 ;
bool V_126 = false ;
F_78 ( & V_5 -> V_226 ) ;
F_4 () ;
if ( ! F_86 ( V_5 ) )
goto V_232;
if ( F_19 ( V_5 ) . V_16 &&
! ( -- F_19 ( V_5 ) . V_16 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) -> V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_60 ( L_35 ,
V_5 -> V_36 -> V_83 ) ;
goto V_232;
}
V_4 = F_3 ( V_2 ) ;
F_62 ( V_4 , & V_126 ) ;
}
F_67 ( V_5 ) ;
}
F_39 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_60 ( L_36 ,
V_5 -> V_36 -> V_83 ) ;
goto V_232;
}
F_53 ( NULL , V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 , & V_126 ) ;
F_50 ( V_2 , & V_126 ) ;
F_56 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( V_2 -> V_69 & V_129 )
V_2 -> V_69 &= ~ V_129 ;
}
V_232:
F_39 (bond, slave, iter) {
if ( V_3 -> V_233 ) {
V_231 = V_234 ;
break;
}
}
F_7 () ;
F_81 ( & V_5 -> V_226 ) ;
if ( V_126 )
F_87 ( V_5 , 0 ) ;
if ( V_231 && F_88 () ) {
F_89 ( V_5 ) ;
F_90 () ;
}
F_91 ( V_5 -> V_235 , & V_5 -> V_230 , V_236 ) ;
}
static int F_92 ( struct V_58 * V_58 , struct V_3 * V_3 ,
T_2 V_107 )
{
struct V_2 * V_2 ;
int V_237 = V_238 ;
if ( V_107 >= sizeof( struct V_58 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_60 ( L_37 ,
V_3 -> V_36 -> V_83 , V_3 -> V_5 -> V_36 -> V_83 ) ;
return V_237 ;
}
switch ( V_58 -> V_195 ) {
case V_239 :
V_237 = V_240 ;
F_21 ( V_3 -> V_5 -> V_36 ,
L_38 ,
V_2 -> V_37 ,
V_3 -> V_36 -> V_83 ) ;
F_93 ( & V_3 -> V_5 -> V_226 ) ;
F_53 ( V_58 , V_2 ) ;
F_94 ( & V_3 -> V_5 -> V_226 ) ;
break;
case V_241 :
V_237 = V_240 ;
switch ( ( (struct V_122 * ) V_58 ) -> V_209 ) {
case V_242 :
F_21 ( V_3 -> V_5 -> V_36 , L_39 ,
V_2 -> V_37 ) ;
F_71 ( (struct V_122 * ) V_58 , V_2 ) ;
break;
case V_210 :
F_21 ( V_3 -> V_5 -> V_36 , L_40 ,
V_2 -> V_37 ) ;
F_72 ( (struct V_122 * ) V_58 , V_2 ) ;
break;
default:
F_21 ( V_3 -> V_5 -> V_36 , L_41 ,
V_2 -> V_37 ) ;
}
}
}
return V_237 ;
}
static void F_76 ( struct V_2 * V_2 , bool V_243 )
{
T_3 V_39 = 0 ;
T_2 V_244 = 0 , V_17 = 0 ;
T_2 V_245 = V_2 -> V_64 ;
V_2 -> V_184 &= ~ ( V_246 | V_149 ) ;
if ( ! V_243 ) {
V_17 = F_20 ( V_2 ) ;
V_244 = ( V_245 & V_246 ) >> 1 ;
V_39 = F_22 ( V_2 ) ;
V_2 -> V_184 |= ( V_17 << 1 ) | V_39 ;
}
V_2 -> V_64 = V_2 -> V_184 ;
if ( V_245 != V_2 -> V_64 ) {
if ( V_39 )
V_2 -> V_69 |= V_147 ;
else
V_2 -> V_69 &= ~ V_147 ;
if ( ! V_243 ) {
if ( ! V_17 ) {
F_54 ( V_2 -> V_3 -> V_36 ,
L_42 ,
V_2 -> V_3 -> V_36 -> V_83 ) ;
} else if ( V_39 && V_244 != V_17 ) {
V_2 -> V_69 |= V_129 ;
}
}
}
}
void F_95 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_3 -> V_5 -> V_36 ,
L_43 ,
V_3 -> V_36 -> V_83 ) ;
return;
}
F_78 ( & V_3 -> V_5 -> V_226 ) ;
F_76 ( V_2 , false ) ;
F_21 ( V_3 -> V_5 -> V_36 , L_44 ,
V_2 -> V_37 , V_3 -> V_36 -> V_83 ) ;
F_81 ( & V_3 -> V_5 -> V_226 ) ;
}
void F_96 ( struct V_3 * V_3 , char V_11 )
{
struct V_4 * V_7 ;
struct V_2 * V_2 ;
bool V_247 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_3 -> V_5 -> V_36 , L_45 ,
V_3 -> V_36 -> V_83 ) ;
return;
}
F_78 ( & V_3 -> V_5 -> V_226 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_97 = true ;
F_76 ( V_2 , false ) ;
} else {
V_2 -> V_97 = false ;
F_76 ( V_2 , true ) ;
}
V_7 = F_3 ( V_2 ) ;
F_62 ( V_7 , & V_247 ) ;
F_21 ( V_3 -> V_5 -> V_36 , L_46 ,
V_2 -> V_37 ,
V_11 == V_12 ? L_47 : L_48 ) ;
F_81 ( & V_3 -> V_5 -> V_226 ) ;
F_97 ( V_3 -> V_5 , NULL ) ;
}
int F_67 ( struct V_1 * V_5 )
{
struct V_4 * V_96 ;
struct V_3 * V_6 ;
int V_237 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_237 = 0 ;
goto V_227;
}
V_96 = F_38 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_96 ) {
if ( F_36 ( V_96 ) < V_5 -> V_14 . V_248 ) {
if ( F_66 ( V_5 -> V_36 ) ) {
F_98 ( V_5 -> V_36 ) ;
goto V_227;
}
} else if ( ! F_66 ( V_5 -> V_36 ) ) {
F_99 ( V_5 -> V_36 ) ;
goto V_227;
}
} else if ( F_66 ( V_5 -> V_36 ) ) {
F_98 ( V_5 -> V_36 ) ;
}
V_227:
F_7 () ;
return V_237 ;
}
int F_100 ( struct V_1 * V_5 ,
struct V_249 * V_249 )
{
struct V_4 * V_4 = NULL ;
struct V_101 * V_102 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_39 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_103 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( ! V_4 )
return - 1 ;
V_249 -> V_250 = V_4 -> V_178 ;
V_249 -> V_251 = V_4 -> V_176 ;
V_249 -> V_79 = V_4 -> V_179 ;
V_249 -> V_63 = V_4 -> V_180 ;
F_46 ( V_249 -> V_8 ,
V_4 -> V_8 . V_9 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_5 , struct V_249 * V_249 )
{
int V_237 ;
F_4 () ;
V_237 = F_100 ( V_5 , V_249 ) ;
F_7 () ;
return V_237 ;
}
int F_102 ( const struct V_104 * V_105 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
struct V_58 * V_58 , V_252 ;
if ( V_105 -> V_112 != V_113 )
return V_238 ;
if ( ! F_27 ( F_103 ( V_105 ) -> V_117 , V_118 ) )
return V_238 ;
V_58 = F_104 ( V_105 , 0 , sizeof( V_252 ) , & V_252 ) ;
if ( ! V_58 )
return V_238 ;
return F_92 ( V_58 , V_3 , V_105 -> V_253 ) ;
}
void F_105 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_101 * V_102 ;
struct V_3 * V_3 ;
int V_193 ;
V_193 = V_5 -> V_14 . V_193 ;
F_78 ( & V_5 -> V_226 ) ;
F_61 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_193 )
V_2 -> V_67 |= V_89 ;
else
V_2 -> V_67 &= ~ V_89 ;
}
F_81 ( & V_5 -> V_226 ) ;
}
