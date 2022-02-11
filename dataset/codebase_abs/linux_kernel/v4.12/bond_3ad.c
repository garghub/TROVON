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
case V_36 :
V_17 = V_37 ;
break;
case V_38 :
V_17 = V_39 ;
break;
case V_40 :
V_17 = V_41 ;
break;
case V_42 :
V_17 = V_43 ;
break;
default:
V_17 = 0 ;
break;
}
}
F_21 ( V_3 -> V_5 -> V_44 , L_1 ,
V_2 -> V_45 , V_17 ) ;
return V_17 ;
}
static T_3 F_22 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_3 V_46 = 0x0 ;
if ( V_3 -> V_11 == V_12 ) {
switch ( V_3 -> V_47 ) {
case V_48 :
V_46 = 0x1 ;
F_21 ( V_3 -> V_5 -> V_44 , L_2 ,
V_2 -> V_45 ) ;
break;
case V_49 :
default:
V_46 = 0x0 ;
F_21 ( V_3 -> V_5 -> V_44 , L_3 ,
V_2 -> V_45 ) ;
break;
}
}
return V_46 ;
}
static void F_23 ( struct V_2 * V_2 )
{
const struct V_1 * V_5 = F_2 ( V_2 -> V_3 ) ;
V_2 -> V_50 = F_19 ( V_5 ) . system . V_51 ;
V_2 -> V_52 = F_19 ( V_5 ) . system . V_53 ;
}
static T_2 F_24 ( T_2 V_54 , T_2 V_55 )
{
T_2 V_46 = 0 ;
switch ( V_54 ) {
case V_56 :
if ( V_55 )
V_46 = ( V_57 * V_58 ) ;
else
V_46 = ( V_59 * V_58 ) ;
break;
case V_60 :
V_46 = ( V_61 * V_58 ) ;
break;
case V_62 :
V_46 = ( V_55 * V_58 ) ;
break;
case V_63 :
V_46 = ( V_61 * V_58 ) ;
break;
case V_64 :
V_46 = ( V_65 * V_58 ) ;
break;
}
return V_46 ;
}
static void F_25 ( struct V_66 * V_66 , struct V_2 * V_2 )
{
if ( ( ( F_26 ( V_66 -> V_67 ) == V_2 -> V_45 ) &&
( F_26 ( V_66 -> V_68 ) == V_2 -> V_69 ) &&
F_27 ( & ( V_66 -> V_8 ) , & ( V_2 -> V_50 ) ) &&
( F_26 ( V_66 -> V_70 ) == V_2 -> V_52 ) &&
( F_26 ( V_66 -> V_71 ) == V_2 -> V_72 ) &&
( ( V_66 -> V_73 & V_74 ) == ( V_2 -> V_75 & V_74 ) ) ) ||
( ( V_66 -> V_76 & V_74 ) == 0 )
) {
V_2 -> V_77 |= V_78 ;
} else {
V_2 -> V_77 &= ~ V_78 ;
}
}
static void F_28 ( struct V_66 * V_66 , struct V_2 * V_2 )
{
if ( V_66 && V_2 ) {
struct V_79 * V_80 = & V_2 -> V_81 ;
F_25 ( V_66 , V_2 ) ;
V_80 -> V_82 = F_26 ( V_66 -> V_83 ) ;
V_80 -> V_84 = F_26 ( V_66 -> V_69 ) ;
V_80 -> system = V_66 -> V_50 ;
V_80 -> V_85 = F_26 ( V_66 -> V_52 ) ;
V_80 -> V_86 = F_26 ( V_66 -> V_87 ) ;
V_80 -> V_88 = V_66 -> V_76 ;
V_2 -> V_75 &= ~ V_89 ;
if ( ( V_2 -> V_77 & V_78 ) &&
( V_66 -> V_76 & V_90 ) ) {
V_80 -> V_88 |= V_90 ;
F_29 ( L_4 , V_2 -> V_3 -> V_44 -> V_91 ) ;
} else {
V_80 -> V_88 &= ~ V_90 ;
F_29 ( L_5 , V_2 -> V_3 -> V_44 -> V_91 ) ;
}
}
}
static void F_30 ( struct V_2 * V_2 )
{
if ( V_2 ) {
memcpy ( & V_2 -> V_81 , & V_2 -> V_92 ,
sizeof( struct V_79 ) ) ;
V_2 -> V_75 |= V_89 ;
}
}
static void F_31 ( struct V_66 * V_66 , struct V_2 * V_2 )
{
if ( V_66 && V_2 ) {
const struct V_79 * V_80 = & V_2 -> V_81 ;
if ( F_26 ( V_66 -> V_83 ) != V_80 -> V_82 ||
F_26 ( V_66 -> V_69 ) != V_80 -> V_84 ||
! F_27 ( & V_66 -> V_50 , & V_80 -> system ) ||
F_26 ( V_66 -> V_52 ) != V_80 -> V_85 ||
F_26 ( V_66 -> V_87 ) != V_80 -> V_86 ||
( V_66 -> V_76 & V_74 ) != ( V_80 -> V_88 & V_74 ) ) {
V_2 -> V_77 &= ~ V_93 ;
}
}
}
static void F_32 ( struct V_2 * V_2 )
{
if ( V_2 ) {
const struct V_79 * V_94 = & V_2 -> V_92 ;
const struct V_79 * V_95 = & V_2 -> V_81 ;
if ( V_94 -> V_82 != V_95 -> V_82 ||
V_94 -> V_84 != V_95 -> V_84 ||
! F_27 ( & V_94 -> system , & V_95 -> system ) ||
V_94 -> V_85 != V_95 -> V_85 ||
V_94 -> V_86 != V_95 -> V_86 ||
( V_94 -> V_88 & V_74 )
!= ( V_95 -> V_88 & V_74 ) ) {
V_2 -> V_77 &= ~ V_93 ;
}
}
}
static void F_33 ( struct V_66 * V_66 , struct V_2 * V_2 )
{
if ( V_66 && V_2 ) {
if ( ( F_26 ( V_66 -> V_67 ) != V_2 -> V_45 ) ||
( F_26 ( V_66 -> V_68 ) != V_2 -> V_69 ) ||
! F_27 ( & ( V_66 -> V_8 ) , & ( V_2 -> V_50 ) ) ||
( F_26 ( V_66 -> V_70 ) != V_2 -> V_52 ) ||
( F_26 ( V_66 -> V_71 ) != V_2 -> V_72 ) ||
( ( V_66 -> V_73 & V_96 ) != ( V_2 -> V_75 & V_96 ) ) ||
( ( V_66 -> V_73 & V_97 ) != ( V_2 -> V_75 & V_97 ) ) ||
( ( V_66 -> V_73 & V_90 ) != ( V_2 -> V_75 & V_90 ) ) ||
( ( V_66 -> V_73 & V_74 ) != ( V_2 -> V_75 & V_74 ) )
) {
V_2 -> V_98 = true ;
}
}
}
static int F_34 ( struct V_4 * V_4 )
{
struct V_2 * V_2 ;
int V_46 = 1 ;
if ( V_4 ) {
for ( V_2 = V_4 -> V_99 ;
V_2 ;
V_2 = V_2 -> V_100 ) {
if ( ! ( V_2 -> V_77 & V_101 ) ) {
V_46 = 0 ;
break;
}
}
}
return V_46 ;
}
static void F_35 ( struct V_4 * V_4 , int V_102 )
{
struct V_2 * V_2 ;
for ( V_2 = V_4 -> V_99 ; V_2 ;
V_2 = V_2 -> V_100 ) {
if ( V_102 )
V_2 -> V_77 |= V_103 ;
else
V_2 -> V_77 &= ~ V_103 ;
}
}
static int F_36 ( struct V_4 * V_7 )
{
struct V_2 * V_2 ;
int V_104 = 0 ;
for ( V_2 = V_7 -> V_99 ; V_2 ;
V_2 = V_2 -> V_100 ) {
if ( V_2 -> V_105 )
V_104 ++ ;
}
return V_104 ;
}
static T_1 F_37 ( struct V_4 * V_4 )
{
int V_106 = F_36 ( V_4 ) ;
T_1 V_107 = 0 ;
if ( V_106 ) {
switch ( F_20 ( V_4 -> V_99 ) ) {
case V_108 :
V_107 = V_106 ;
break;
case V_19 :
V_107 = V_106 * 10 ;
break;
case V_21 :
V_107 = V_106 * 100 ;
break;
case V_23 :
V_107 = V_106 * 1000 ;
break;
case V_25 :
V_107 = V_106 * 2500 ;
break;
case V_27 :
V_107 = V_106 * 5000 ;
break;
case V_29 :
V_107 = V_106 * 10000 ;
break;
case V_31 :
V_107 = V_106 * 14000 ;
break;
case V_33 :
V_107 = V_106 * 20000 ;
break;
case V_35 :
V_107 = V_106 * 25000 ;
break;
case V_37 :
V_107 = V_106 * 40000 ;
break;
case V_39 :
V_107 = V_106 * 50000 ;
break;
case V_41 :
V_107 = V_106 * 56000 ;
break;
case V_43 :
V_107 = V_106 * 100000 ;
break;
default:
V_107 = 0 ;
}
}
return V_107 ;
}
static struct V_4 * F_38 ( struct V_4 * V_4 )
{
struct V_1 * V_5 = V_4 -> V_3 -> V_5 ;
struct V_109 * V_110 ;
struct V_3 * V_3 ;
F_39 (bond, slave, iter)
if ( F_6 ( V_3 ) -> V_4 . V_111 )
return & ( F_6 ( V_3 ) -> V_4 ) ;
return NULL ;
}
static inline void F_40 ( struct V_2 * V_2 )
{
struct V_66 * V_66 = & V_2 -> V_66 ;
const struct V_79 * V_80 = & V_2 -> V_81 ;
V_66 -> V_52 = F_41 ( V_2 -> V_52 ) ;
V_66 -> V_50 = V_2 -> V_50 ;
V_66 -> V_87 = F_41 ( V_2 -> V_72 ) ;
V_66 -> V_69 = F_41 ( V_2 -> V_69 ) ;
V_66 -> V_83 = F_41 ( V_2 -> V_45 ) ;
V_66 -> V_76 = V_2 -> V_75 ;
F_29 ( L_6 ,
V_2 -> V_3 -> V_44 -> V_91 , V_2 -> V_75 ) ;
V_66 -> V_70 = F_41 ( V_80 -> V_85 ) ;
V_66 -> V_8 = V_80 -> system ;
V_66 -> V_71 = F_41 ( V_80 -> V_86 ) ;
V_66 -> V_68 = F_41 ( V_80 -> V_84 ) ;
V_66 -> V_67 = F_41 ( V_80 -> V_82 ) ;
V_66 -> V_73 = V_80 -> V_88 ;
}
static int F_42 ( struct V_2 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_112 * V_113 ;
struct V_114 * V_114 ;
int V_115 = sizeof( struct V_114 ) ;
V_113 = F_43 ( V_115 ) ;
if ( ! V_113 )
return - V_116 ;
V_113 -> V_44 = V_3 -> V_44 ;
F_44 ( V_113 ) ;
V_113 -> V_117 = V_113 -> V_118 + V_119 ;
V_113 -> V_120 = V_121 ;
V_113 -> V_122 = V_123 ;
V_114 = (struct V_114 * ) F_45 ( V_113 , V_115 ) ;
F_46 ( V_114 -> V_124 . V_125 , V_126 ) ;
F_46 ( V_114 -> V_124 . V_127 , V_3 -> V_128 ) ;
V_114 -> V_124 . V_129 = V_121 ;
V_114 -> V_66 = V_2 -> V_66 ;
F_47 ( V_113 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_2 , struct V_130 * V_131 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_112 * V_113 ;
struct V_132 * V_133 ;
int V_115 = sizeof( struct V_132 ) ;
V_113 = F_43 ( V_115 + 16 ) ;
if ( ! V_113 )
return - V_116 ;
F_49 ( V_113 , 16 ) ;
V_113 -> V_44 = V_3 -> V_44 ;
F_44 ( V_113 ) ;
V_113 -> V_117 = V_113 -> V_118 + V_119 ;
V_113 -> V_120 = V_121 ;
V_133 = (struct V_132 * ) F_45 ( V_113 , V_115 ) ;
F_46 ( V_133 -> V_124 . V_125 , V_126 ) ;
F_46 ( V_133 -> V_124 . V_127 , V_3 -> V_128 ) ;
V_133 -> V_124 . V_129 = V_121 ;
V_133 -> V_131 = * V_131 ;
F_47 ( V_113 ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_2 , bool * V_134 )
{
T_4 V_135 ;
V_135 = V_2 -> V_136 ;
if ( V_2 -> V_77 & V_137 ) {
V_2 -> V_136 = V_138 ;
} else {
switch ( V_2 -> V_136 ) {
case V_138 :
if ( ( V_2 -> V_77 & V_93 )
|| ( V_2 -> V_77 & V_139 ) )
V_2 -> V_136 = V_140 ;
break;
case V_140 :
if ( ! ( V_2 -> V_77 & V_93 ) ) {
V_2 -> V_77 &= ~ V_101 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
V_2 -> V_136 = V_138 ;
break;
}
if ( V_2 -> V_141
&& ! ( -- V_2 -> V_141 ) )
V_2 -> V_77 |= V_101 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
if ( ( V_2 -> V_77 & V_103 )
&& ! V_2 -> V_141 )
V_2 -> V_136 = V_142 ;
break;
case V_142 :
if ( ( V_2 -> V_77 & V_93 ) &&
( V_2 -> V_81 . V_88 & V_90 ) &&
! F_18 ( V_2 ) ) {
if ( V_2 -> V_4 -> V_111 )
V_2 -> V_136 =
V_143 ;
} else if ( ! ( V_2 -> V_77 & V_93 ) ||
( V_2 -> V_77 & V_139 ) ) {
V_2 -> V_77 &= ~ V_101 ;
F_35 ( V_2 -> V_4 , F_34 ( V_2 -> V_4 ) ) ;
V_2 -> V_136 = V_138 ;
} else if ( V_2 -> V_4 -> V_111 ) {
V_2 -> V_75 |=
V_90 ;
}
break;
case V_143 :
if ( ! ( V_2 -> V_77 & V_93 ) ||
( V_2 -> V_77 & V_139 ) ||
! ( V_2 -> V_81 . V_88 & V_90 ) ||
! ( V_2 -> V_75 & V_90 ) ) {
V_2 -> V_136 = V_142 ;
} else {
if ( V_2 -> V_4 &&
V_2 -> V_4 -> V_111 &&
! F_15 ( V_2 ) ) {
F_12 ( V_2 ) ;
}
}
break;
default:
break;
}
}
if ( V_2 -> V_136 != V_135 ) {
F_29 ( L_7 ,
V_2 -> V_45 ,
V_2 -> V_3 -> V_44 -> V_91 ,
V_135 ,
V_2 -> V_136 ) ;
switch ( V_2 -> V_136 ) {
case V_138 :
V_2 -> V_75 &= ~ V_90 ;
F_51 ( V_2 ,
V_134 ) ;
V_2 -> V_75 &= ~ V_144 ;
V_2 -> V_75 &= ~ V_145 ;
V_2 -> V_98 = true ;
break;
case V_140 :
V_2 -> V_141 = F_24 ( V_64 , 0 ) ;
break;
case V_142 :
if ( V_2 -> V_4 -> V_111 )
V_2 -> V_75 |=
V_90 ;
else
V_2 -> V_75 &=
~ V_90 ;
V_2 -> V_75 &= ~ V_144 ;
V_2 -> V_75 &= ~ V_145 ;
F_51 ( V_2 ,
V_134 ) ;
V_2 -> V_98 = true ;
break;
case V_143 :
V_2 -> V_75 |= V_144 ;
V_2 -> V_75 |= V_145 ;
V_2 -> V_75 |= V_90 ;
F_52 ( V_2 ,
V_134 ) ;
V_2 -> V_98 = true ;
break;
default:
break;
}
}
}
static void F_53 ( struct V_66 * V_66 , struct V_2 * V_2 )
{
T_5 V_135 ;
V_135 = V_2 -> V_146 ;
if ( V_2 -> V_77 & V_137 ) {
V_2 -> V_146 = V_147 ;
V_2 -> V_77 |= V_148 ;
} else if ( ! ( V_2 -> V_77 & V_137 ) && ! V_2 -> V_105 )
V_2 -> V_146 = V_149 ;
else if ( V_66 && ( ( V_2 -> V_146 == V_150 ) ||
( V_2 -> V_146 == V_151 ) ||
( V_2 -> V_146 == V_152 ) ) ) {
if ( V_2 -> V_146 != V_152 )
V_2 -> V_77 |= V_148 ;
V_2 -> V_153 = 0 ;
V_2 -> V_146 = V_152 ;
} else {
if ( V_2 -> V_153 &&
! ( -- V_2 -> V_153 ) ) {
switch ( V_2 -> V_146 ) {
case V_150 :
V_2 -> V_146 = V_151 ;
break;
case V_152 :
V_2 -> V_146 = V_150 ;
break;
default:
break;
}
} else {
switch ( V_2 -> V_146 ) {
case V_149 :
if ( V_2 -> V_105 &&
( V_2 -> V_77 & V_154 ) )
V_2 -> V_146 = V_150 ;
else if ( V_2 -> V_105
&& ( ( V_2 -> V_77
& V_154 ) == 0 ) )
V_2 -> V_146 = V_155 ;
break;
default:
break;
}
}
}
if ( ( V_2 -> V_146 != V_135 ) || ( V_66 ) ) {
F_29 ( L_8 ,
V_2 -> V_45 ,
V_2 -> V_3 -> V_44 -> V_91 ,
V_135 ,
V_2 -> V_146 ) ;
switch ( V_2 -> V_146 ) {
case V_147 :
if ( ! ( V_2 -> V_72 & V_156 ) )
V_2 -> V_77 &= ~ V_154 ;
else
V_2 -> V_77 |= V_154 ;
V_2 -> V_77 &= ~ V_93 ;
F_30 ( V_2 ) ;
V_2 -> V_75 &= ~ V_157 ;
V_2 -> V_146 = V_149 ;
case V_149 :
V_2 -> V_77 &= ~ V_78 ;
break;
case V_155 :
V_2 -> V_77 &= ~ V_93 ;
F_30 ( V_2 ) ;
V_2 -> V_81 . V_88 &= ~ V_74 ;
V_2 -> V_77 |= V_78 ;
V_2 -> V_75 &= ~ V_157 ;
break;
case V_150 :
V_2 -> V_81 . V_88 &= ~ V_90 ;
V_2 -> V_77 &= ~ V_78 ;
V_2 -> V_81 . V_88 |= V_97 ;
V_2 -> V_81 . V_88 |= V_96 ;
V_2 -> V_153 = F_24 ( V_56 , ( T_2 ) ( V_158 ) ) ;
V_2 -> V_75 |= V_157 ;
V_2 -> V_77 |= V_148 ;
break;
case V_151 :
F_32 ( V_2 ) ;
F_30 ( V_2 ) ;
V_2 -> V_77 |= V_78 ;
V_2 -> V_75 &= ~ V_157 ;
break;
case V_152 :
if ( F_27 ( & ( V_66 -> V_50 ) ,
& ( V_2 -> V_50 ) ) ) {
F_54 ( V_2 -> V_3 -> V_5 -> V_44 , L_9
L_10 ,
V_2 -> V_3 -> V_44 -> V_91 ) ;
return;
}
F_31 ( V_66 , V_2 ) ;
F_33 ( V_66 , V_2 ) ;
F_28 ( V_66 , V_2 ) ;
V_2 -> V_153 = F_24 ( V_56 , ( T_2 ) ( V_2 -> V_75 & V_97 ) ) ;
V_2 -> V_75 &= ~ V_157 ;
break;
default:
break;
}
}
}
static void F_55 ( struct V_2 * V_2 )
{
if ( V_2 -> V_77 & V_148 ) {
V_2 -> V_77 &= ~ V_148 ;
V_2 -> V_159 = V_160 ;
V_2 -> V_161 = V_160 ;
V_2 -> V_162 =
F_24 ( V_60 , 0 ) ;
V_2 -> V_163 =
F_24 ( V_63 , 0 ) ;
return;
}
if ( V_2 -> V_162 &&
! ( -- V_2 -> V_162 ) &&
V_2 -> V_159 == V_160 ) {
if ( V_2 -> V_75 & V_90 ) {
V_2 -> V_159 = V_164 ;
} else {
V_2 -> V_165 ++ ;
V_2 -> V_159 = V_166 ;
}
}
if ( V_2 -> V_163 &&
! ( -- V_2 -> V_163 ) &&
V_2 -> V_161 == V_160 ) {
if ( V_2 -> V_81 . V_88 & V_90 ) {
V_2 -> V_161 = V_164 ;
} else {
V_2 -> V_167 ++ ;
V_2 -> V_161 = V_166 ;
}
}
}
static void F_56 ( struct V_2 * V_2 )
{
if ( V_2 -> V_168 && ! ( -- V_2 -> V_168 ) ) {
if ( V_2 -> V_98 && ( V_2 -> V_77 & V_154 ) ) {
F_40 ( V_2 ) ;
if ( F_42 ( V_2 ) >= 0 ) {
F_29 ( L_11 ,
V_2 -> V_45 ) ;
V_2 -> V_98 = false ;
}
}
V_2 -> V_168 = V_58 / V_169 ;
}
}
static void F_57 ( struct V_2 * V_2 )
{
T_6 V_135 ;
V_135 = V_2 -> V_170 ;
if ( ( ( V_2 -> V_77 & V_137 ) || ! ( V_2 -> V_77 & V_154 ) || ! V_2 -> V_105 ) ||
( ! ( V_2 -> V_75 & V_96 ) && ! ( V_2 -> V_81 . V_88 & V_96 ) )
) {
V_2 -> V_170 = V_171 ;
}
else if ( V_2 -> V_172 ) {
if ( ! ( -- V_2 -> V_172 ) ) {
V_2 -> V_170 = V_173 ;
} else {
switch ( V_2 -> V_170 ) {
case V_174 :
if ( ! ( V_2 -> V_81 . V_88
& V_97 ) )
V_2 -> V_170 = V_175 ;
break;
case V_175 :
if ( ( V_2 -> V_81 . V_88 & V_97 ) ) {
V_2 -> V_172 = 0 ;
V_2 -> V_170 = V_173 ;
}
break;
default:
break;
}
}
} else {
switch ( V_2 -> V_170 ) {
case V_171 :
V_2 -> V_170 = V_174 ;
break;
case V_173 :
if ( ! ( V_2 -> V_81 . V_88 &
V_97 ) )
V_2 -> V_170 = V_175 ;
else
V_2 -> V_170 = V_174 ;
break;
default:
break;
}
}
if ( V_2 -> V_170 != V_135 ) {
F_29 ( L_12 ,
V_2 -> V_45 , V_135 ,
V_2 -> V_170 ) ;
switch ( V_2 -> V_170 ) {
case V_171 :
V_2 -> V_172 = 0 ;
break;
case V_174 :
V_2 -> V_172 = F_24 ( V_62 , ( T_2 ) ( V_176 ) ) - 1 ;
break;
case V_175 :
V_2 -> V_172 = F_24 ( V_62 , ( T_2 ) ( V_177 ) ) - 1 ;
break;
case V_173 :
V_2 -> V_98 = true ;
break;
default:
break;
}
}
}
static void F_58 ( struct V_2 * V_2 , bool * V_134 )
{
struct V_4 * V_4 , * V_178 = NULL , * V_179 ;
struct V_2 * V_180 = NULL , * V_181 ;
struct V_109 * V_110 ;
struct V_1 * V_5 ;
struct V_3 * V_3 ;
int V_182 = 0 ;
if ( V_2 -> V_77 & V_93 )
return;
V_5 = F_1 ( V_2 ) ;
if ( V_2 -> V_4 ) {
V_179 = V_2 -> V_4 ;
for ( V_181 = V_179 -> V_99 ; V_181 ;
V_180 = V_181 ,
V_181 = V_181 -> V_100 ) {
if ( V_181 == V_2 ) {
V_179 -> V_183 -- ;
if ( ! V_180 ) {
V_179 -> V_99 =
V_2 -> V_100 ;
} else {
V_180 -> V_100 =
V_2 -> V_100 ;
}
V_2 -> V_4 = NULL ;
V_2 -> V_100 = NULL ;
V_2 -> V_184 = 0 ;
F_21 ( V_5 -> V_44 , L_13 ,
V_2 -> V_45 ,
V_179 -> V_185 ) ;
if ( ! V_179 -> V_99 )
F_59 ( V_179 ) ;
break;
}
}
if ( ! V_181 ) {
F_60 ( L_14 ,
V_2 -> V_3 -> V_5 -> V_44 -> V_91 ,
V_2 -> V_45 ,
V_2 -> V_3 -> V_44 -> V_91 ,
V_2 -> V_4 -> V_185 ) ;
}
}
F_61 (bond, slave, iter) {
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
if ( ! V_4 -> V_99 ) {
if ( ! V_178 )
V_178 = V_4 ;
continue;
}
if ( ( ( V_4 -> V_186 == V_2 -> V_72 ) &&
F_27 ( & ( V_4 -> V_8 ) , & ( V_2 -> V_81 . system ) ) &&
( V_4 -> V_70 == V_2 -> V_81 . V_85 ) &&
( V_4 -> V_187 == V_2 -> V_81 . V_86 )
) &&
( ( ! F_27 ( & ( V_2 -> V_81 . system ) , & ( V_188 ) ) &&
! V_4 -> V_189 )
)
) {
V_2 -> V_4 = V_4 ;
V_2 -> V_184 =
V_2 -> V_4 -> V_185 ;
V_2 -> V_100 = V_4 -> V_99 ;
V_2 -> V_4 -> V_183 ++ ;
V_4 -> V_99 = V_2 ;
F_21 ( V_5 -> V_44 , L_15 ,
V_2 -> V_45 ,
V_2 -> V_4 -> V_185 ) ;
V_2 -> V_77 |= V_93 ;
V_182 = 1 ;
break;
}
}
if ( ! V_182 ) {
if ( V_178 ) {
V_2 -> V_4 = V_178 ;
V_2 -> V_184 =
V_2 -> V_4 -> V_185 ;
if ( V_2 -> V_72 & V_156 )
V_2 -> V_4 -> V_189 = false ;
else
V_2 -> V_4 -> V_189 = true ;
V_2 -> V_4 -> V_190 =
V_2 -> V_191 ;
V_2 -> V_4 -> V_186 =
V_2 -> V_72 ;
V_2 -> V_4 -> V_8 =
V_2 -> V_81 . system ;
V_2 -> V_4 -> V_70 =
V_2 -> V_81 . V_85 ;
V_2 -> V_4 -> V_187 = V_2 -> V_81 . V_86 ;
V_2 -> V_4 -> V_192 = 1 ;
V_2 -> V_4 -> V_193 = 1 ;
V_2 -> V_4 -> V_99 = V_2 ;
V_2 -> V_4 -> V_183 ++ ;
V_2 -> V_77 |= V_93 ;
F_21 ( V_5 -> V_44 , L_16 ,
V_2 -> V_45 ,
V_2 -> V_4 -> V_185 ) ;
} else {
F_54 ( V_5 -> V_44 , L_17 ,
V_2 -> V_45 , V_2 -> V_3 -> V_44 -> V_91 ) ;
}
}
F_35 ( V_2 -> V_4 ,
F_34 ( V_2 -> V_4 ) ) ;
V_4 = F_3 ( V_2 ) ;
F_62 ( V_4 , V_134 ) ;
if ( ! V_2 -> V_4 -> V_111 )
V_2 -> V_75 &= ~ V_90 ;
}
static struct V_4 * F_63 ( struct V_4 * V_194 ,
struct V_4 * V_195 )
{
if ( ! V_194 )
return V_195 ;
if ( ! V_195 -> V_189 && V_194 -> V_189 )
return V_195 ;
if ( V_195 -> V_189 && ! V_194 -> V_189 )
return V_194 ;
if ( F_8 ( V_195 ) && ! F_8 ( V_194 ) )
return V_195 ;
if ( ! F_8 ( V_195 ) && F_8 ( V_194 ) )
return V_194 ;
switch ( F_17 ( V_195 -> V_99 ) ) {
case V_196 :
if ( F_36 ( V_195 ) > F_36 ( V_194 ) )
return V_195 ;
if ( F_36 ( V_195 ) < F_36 ( V_194 ) )
return V_194 ;
case V_13 :
case V_197 :
if ( F_37 ( V_195 ) > F_37 ( V_194 ) )
return V_195 ;
break;
default:
F_60 ( L_18 ,
V_195 -> V_3 -> V_5 -> V_44 -> V_91 ,
F_17 ( V_195 -> V_99 ) ) ;
break;
}
return V_194 ;
}
static int F_64 ( const struct V_4 * V_7 )
{
struct V_2 * V_2 = V_7 -> V_99 ;
if ( ! V_2 )
return 0 ;
for ( V_2 = V_7 -> V_99 ; V_2 ;
V_2 = V_2 -> V_100 ) {
if ( F_65 ( V_2 -> V_3 -> V_44 ) &&
F_66 ( V_2 -> V_3 -> V_44 ) )
return 1 ;
}
return 0 ;
}
static void F_62 ( struct V_4 * V_7 ,
bool * V_134 )
{
struct V_4 * V_194 , * V_104 , * V_198 ;
struct V_1 * V_5 = V_7 -> V_3 -> V_5 ;
struct V_109 * V_110 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_4 () ;
V_198 = V_7 ;
V_104 = F_38 ( V_7 ) ;
V_194 = ( V_104 && F_64 ( V_104 ) ) ? V_104 : NULL ;
F_39 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_7 -> V_111 = 0 ;
if ( F_36 ( V_7 ) && F_64 ( V_7 ) )
V_194 = F_63 ( V_194 , V_7 ) ;
}
if ( V_194 &&
F_17 ( V_194 -> V_99 ) == V_13 ) {
if ( V_104 && V_104 -> V_99 &&
F_36 ( V_104 ) &&
( F_8 ( V_104 ) ||
( ! F_8 ( V_104 ) &&
! F_8 ( V_194 ) ) ) ) {
if ( ! ( ! V_104 -> V_186 &&
V_194 -> V_186 ) ) {
V_194 = NULL ;
V_104 -> V_111 = 1 ;
}
}
}
if ( V_194 && ( V_194 == V_104 ) ) {
V_194 = NULL ;
V_104 -> V_111 = 1 ;
}
if ( V_194 ) {
F_21 ( V_5 -> V_44 , L_19 ,
V_194 -> V_185 , V_194 -> V_183 ,
V_194 -> V_186 ,
V_194 -> V_187 ,
V_194 -> V_189 , V_194 -> V_111 ) ;
F_21 ( V_5 -> V_44 , L_20 ,
V_194 -> V_99 , V_194 -> V_3 ,
V_194 -> V_3 ? V_194 -> V_3 -> V_44 -> V_91 : L_21 ) ;
F_39 (bond, slave, iter) {
V_7 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_21 ( V_5 -> V_44 , L_22 ,
V_7 -> V_185 , V_7 -> V_183 ,
V_7 -> V_186 ,
V_7 -> V_187 ,
V_7 -> V_189 , V_7 -> V_111 ) ;
}
if ( V_194 -> V_189 ) {
F_60 ( L_23 ,
V_194 -> V_3 ?
V_194 -> V_3 -> V_5 -> V_44 -> V_91 : L_21 ) ;
}
V_194 -> V_111 = 1 ;
F_21 ( V_5 -> V_44 , L_24 ,
V_194 -> V_185 ) ;
F_21 ( V_5 -> V_44 , L_22 ,
V_194 -> V_185 , V_194 -> V_183 ,
V_194 -> V_186 ,
V_194 -> V_187 ,
V_194 -> V_189 , V_194 -> V_111 ) ;
if ( V_104 ) {
for ( V_2 = V_104 -> V_99 ; V_2 ;
V_2 = V_2 -> V_100 ) {
F_10 ( V_2 ) ;
}
}
* V_134 = true ;
}
V_104 = F_38 ( V_198 ) ;
if ( V_104 ) {
if ( ! F_8 ( V_104 ) ) {
for ( V_2 = V_104 -> V_99 ; V_2 ;
V_2 = V_2 -> V_100 ) {
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
V_4 -> V_189 = false ;
V_4 -> V_190 = 0 ;
V_4 -> V_186 = 0 ;
F_68 ( V_4 -> V_8 . V_9 ) ;
V_4 -> V_70 = 0 ;
V_4 -> V_187 = 0 ;
V_4 -> V_192 = 0 ;
V_4 -> V_193 = 0 ;
V_4 -> V_99 = NULL ;
V_4 -> V_111 = 0 ;
V_4 -> V_183 = 0 ;
F_29 ( L_25 ,
V_4 -> V_185 ) ;
}
}
static void F_69 ( struct V_4 * V_4 )
{
if ( V_4 ) {
F_59 ( V_4 ) ;
F_68 ( V_4 -> V_199 . V_9 ) ;
V_4 -> V_185 = 0 ;
V_4 -> V_3 = NULL ;
}
}
static void F_70 ( struct V_2 * V_2 , int V_200 )
{
static const struct V_79 V_201 = {
. V_85 = 0xffff ,
. V_86 = 1 ,
. V_82 = 1 ,
. V_84 = 0xff ,
. V_88 = 1 ,
} ;
static const struct V_66 V_66 = {
. V_202 = 0x01 ,
. V_203 = 0x01 ,
. V_204 = 0x01 ,
. V_205 = 0x14 ,
. V_206 = 0x02 ,
. V_207 = 0x14 ,
. V_208 = 0x03 ,
. V_209 = 0x10 ,
. V_210 = F_41 ( V_211 ) ,
} ;
if ( V_2 ) {
V_2 -> V_69 = 0xff ;
V_2 -> V_184 = 0 ;
V_2 -> V_98 = false ;
V_2 -> V_212 = V_74 |
V_96 ;
V_2 -> V_75 = V_74 |
V_96 ;
if ( V_200 )
V_2 -> V_75 |= V_97 ;
memcpy ( & V_2 -> V_92 , & V_201 , sizeof( V_201 ) ) ;
memcpy ( & V_2 -> V_81 , & V_201 , sizeof( V_201 ) ) ;
V_2 -> V_105 = true ;
V_2 -> V_77 = V_137 | V_154 ;
V_2 -> V_146 = 0 ;
V_2 -> V_153 = 0 ;
V_2 -> V_170 = 0 ;
V_2 -> V_172 = 0 ;
V_2 -> V_136 = 0 ;
V_2 -> V_141 = 0 ;
V_2 -> V_213 = 0 ;
V_2 -> V_4 = NULL ;
V_2 -> V_100 = NULL ;
V_2 -> V_214 = 0 ;
V_2 -> V_162 = 0 ;
V_2 -> V_159 = 0 ;
V_2 -> V_165 = 0 ;
V_2 -> V_163 = 0 ;
V_2 -> V_161 = 0 ;
V_2 -> V_167 = 0 ;
memcpy ( & V_2 -> V_66 , & V_66 , sizeof( V_66 ) ) ;
}
}
static void F_52 ( struct V_2 * V_2 ,
bool * V_134 )
{
if ( V_2 -> V_4 -> V_111 ) {
F_29 ( L_26 ,
V_2 -> V_45 ,
V_2 -> V_4 -> V_185 ) ;
F_12 ( V_2 ) ;
* V_134 = true ;
}
}
static void F_51 ( struct V_2 * V_2 ,
bool * V_134 )
{
if ( V_2 -> V_4 &&
! F_27 ( & ( V_2 -> V_4 -> V_8 ) ,
& ( V_188 ) ) ) {
F_29 ( L_27 ,
V_2 -> V_45 ,
V_2 -> V_4 -> V_185 ) ;
F_10 ( V_2 ) ;
* V_134 = true ;
}
}
static void F_71 ( struct V_130 * V_215 ,
struct V_2 * V_2 )
{
struct V_130 V_131 ;
memcpy ( & V_131 , V_215 , sizeof( struct V_130 ) ) ;
V_131 . V_216 = V_217 ;
if ( F_48 ( V_2 , & V_131 ) >= 0 ) {
F_29 ( L_28 ,
V_2 -> V_45 ) ;
}
}
static void F_72 ( struct V_130 * V_131 ,
struct V_2 * V_2 )
{
}
void F_73 ( struct V_1 * V_5 , int V_218 )
{
F_19 ( V_5 ) . V_16 = V_218 ;
}
void F_74 ( struct V_1 * V_5 , T_2 V_219 )
{
if ( ! F_27 ( & ( F_19 ( V_5 ) . system . V_51 ) ,
V_5 -> V_44 -> V_220 ) ) {
F_19 ( V_5 ) . V_185 = 0 ;
F_19 ( V_5 ) . system . V_53 =
V_5 -> V_14 . V_221 ;
if ( F_9 ( V_5 -> V_14 . V_222 ) )
F_19 ( V_5 ) . system . V_51 =
* ( (struct V_223 * ) V_5 -> V_44 -> V_220 ) ;
else
F_19 ( V_5 ) . system . V_51 =
* ( (struct V_223 * ) V_5 -> V_14 . V_222 ) ;
V_58 = V_219 ;
F_73 ( V_5 ,
V_224 *
V_58 ) ;
}
}
void F_75 ( struct V_3 * V_3 )
{
struct V_1 * V_5 = F_2 ( V_3 ) ;
struct V_2 * V_2 ;
struct V_4 * V_4 ;
if ( F_6 ( V_3 ) -> V_2 . V_3 != V_3 ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
F_70 ( V_2 , V_5 -> V_14 . V_200 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_45 = F_6 ( V_3 ) -> V_225 ;
V_2 -> V_191 = V_5 -> V_14 . V_226 << 6 ;
F_76 ( V_2 , false ) ;
F_23 ( V_2 ) ;
V_2 -> V_168 = V_58 / V_169 ;
F_10 ( V_2 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
F_69 ( V_4 ) ;
V_4 -> V_199 = * ( (struct V_223 * ) V_5 -> V_44 -> V_220 ) ;
V_4 -> V_185 = ++ F_19 ( V_5 ) . V_185 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_111 = 0 ;
V_4 -> V_183 = 0 ;
}
}
void F_77 ( struct V_3 * V_3 )
{
struct V_2 * V_2 , * V_227 , * V_228 ;
struct V_4 * V_4 , * V_229 , * V_179 ;
int V_230 = 0 ;
struct V_1 * V_5 = V_3 -> V_5 ;
struct V_3 * V_231 ;
struct V_109 * V_110 ;
bool V_232 ;
F_78 ( & V_5 -> V_233 ) ;
V_4 = & ( F_6 ( V_3 ) -> V_4 ) ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_5 -> V_44 , L_29 ,
V_3 -> V_44 -> V_91 ) ;
goto V_234;
}
F_21 ( V_5 -> V_44 , L_30 ,
V_4 -> V_185 ) ;
V_2 -> V_75 &= ~ V_74 ;
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( V_4 -> V_99 ) {
if ( ( V_4 -> V_99 != V_2 ) ||
( V_4 -> V_99 -> V_100 ) ) {
F_61 (bond, slave_iter, iter) {
V_229 = & ( F_6 ( V_231 ) -> V_4 ) ;
if ( ! V_229 -> V_99 ||
( ( V_229 -> V_99 == V_2 ) &&
! V_229 -> V_99 -> V_100 ) )
break;
}
if ( ! V_231 )
V_229 = NULL ;
if ( ( V_229 ) && ( ( ! V_229 -> V_99 ) || ( ( V_229 -> V_99 == V_2 ) && ! V_229 -> V_99 -> V_100 ) ) ) {
F_21 ( V_5 -> V_44 , L_31 ,
V_4 -> V_185 ,
V_229 -> V_185 ) ;
if ( ( V_229 -> V_99 == V_2 ) &&
V_229 -> V_111 ) {
F_80 ( V_5 -> V_44 , L_32 ) ;
V_230 = 1 ;
}
V_229 -> V_189 = V_4 -> V_189 ;
V_229 -> V_190 = V_4 -> V_190 ;
V_229 -> V_186 = V_4 -> V_186 ;
V_229 -> V_8 = V_4 -> V_8 ;
V_229 -> V_70 = V_4 -> V_70 ;
V_229 -> V_187 = V_4 -> V_187 ;
V_229 -> V_192 = V_4 -> V_192 ;
V_229 -> V_193 = V_4 -> V_193 ;
V_229 -> V_99 = V_4 -> V_99 ;
V_229 -> V_111 = V_4 -> V_111 ;
V_229 -> V_183 = V_4 -> V_183 ;
for ( V_228 = V_4 -> V_99 ; V_228 ;
V_228 = V_228 -> V_100 ) {
V_228 -> V_4 = V_229 ;
V_228 -> V_184 = V_229 -> V_185 ;
}
F_59 ( V_4 ) ;
if ( V_230 )
F_62 ( F_3 ( V_2 ) ,
& V_232 ) ;
} else {
F_79 ( V_5 -> V_44 , L_33 ) ;
}
} else {
V_230 = V_4 -> V_111 ;
F_59 ( V_4 ) ;
if ( V_230 ) {
F_80 ( V_5 -> V_44 , L_32 ) ;
V_179 = F_3 ( V_2 ) ;
if ( V_179 )
F_62 ( V_179 ,
& V_232 ) ;
}
}
}
F_21 ( V_5 -> V_44 , L_34 , V_2 -> V_45 ) ;
F_61 (bond, slave_iter, iter) {
V_179 = & ( F_6 ( V_231 ) -> V_4 ) ;
V_227 = NULL ;
for ( V_228 = V_179 -> V_99 ; V_228 ;
V_227 = V_228 ,
V_228 = V_228 -> V_100 ) {
if ( V_228 == V_2 ) {
if ( V_227 )
V_227 -> V_100 = V_228 -> V_100 ;
else
V_179 -> V_99 = V_228 -> V_100 ;
V_179 -> V_183 -- ;
if ( F_36 ( V_179 ) == 0 ) {
V_230 = V_179 -> V_111 ;
F_59 ( V_179 ) ;
if ( V_230 ) {
F_80 ( V_5 -> V_44 , L_32 ) ;
F_62 ( F_3 ( V_2 ) ,
& V_232 ) ;
}
}
break;
}
}
}
V_2 -> V_3 = NULL ;
V_234:
F_81 ( & V_5 -> V_233 ) ;
}
void F_82 ( struct V_1 * V_5 )
{
struct V_109 * V_110 ;
struct V_3 * V_3 ;
F_83 () ;
F_19 ( V_5 ) . system . V_53 = V_5 -> V_14 . V_221 ;
if ( F_9 ( V_5 -> V_14 . V_222 ) )
F_19 ( V_5 ) . system . V_51 =
* ( (struct V_223 * ) V_5 -> V_44 -> V_220 ) ;
else
F_19 ( V_5 ) . system . V_51 =
* ( (struct V_223 * ) V_5 -> V_14 . V_222 ) ;
F_78 ( & V_5 -> V_233 ) ;
F_61 (bond, slave, iter) {
struct V_2 * V_2 = & ( F_6 ( V_3 ) ) -> V_2 ;
F_23 ( V_2 ) ;
V_2 -> V_98 = true ;
}
F_81 ( & V_5 -> V_233 ) ;
}
void F_84 ( struct V_235 * V_236 )
{
struct V_1 * V_5 = F_85 ( V_236 , struct V_1 ,
V_237 . V_236 ) ;
struct V_4 * V_4 ;
struct V_109 * V_110 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
bool V_238 = V_10 ;
bool V_134 = false ;
F_78 ( & V_5 -> V_233 ) ;
F_4 () ;
if ( ! F_86 ( V_5 ) )
goto V_239;
if ( F_19 ( V_5 ) . V_16 &&
! ( -- F_19 ( V_5 ) . V_16 ) ) {
V_3 = F_5 ( V_5 ) ;
V_2 = V_3 ? & ( F_6 ( V_3 ) -> V_2 ) : NULL ;
if ( V_2 ) {
if ( ! V_2 -> V_3 ) {
F_60 ( L_35 ,
V_5 -> V_44 -> V_91 ) ;
goto V_239;
}
V_4 = F_3 ( V_2 ) ;
F_62 ( V_4 , & V_134 ) ;
}
F_67 ( V_5 ) ;
}
F_39 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_60 ( L_36 ,
V_5 -> V_44 -> V_91 ) ;
goto V_239;
}
F_53 ( NULL , V_2 ) ;
F_57 ( V_2 ) ;
F_58 ( V_2 , & V_134 ) ;
F_50 ( V_2 , & V_134 ) ;
F_56 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( V_2 -> V_77 & V_137 )
V_2 -> V_77 &= ~ V_137 ;
}
V_239:
F_39 (bond, slave, iter) {
if ( V_3 -> V_240 ) {
V_238 = V_241 ;
break;
}
}
F_7 () ;
F_81 ( & V_5 -> V_233 ) ;
if ( V_134 )
F_87 ( V_5 , 0 ) ;
if ( V_238 && F_88 () ) {
F_89 ( V_5 ) ;
F_90 () ;
}
F_91 ( V_5 -> V_242 , & V_5 -> V_237 , V_243 ) ;
}
static int F_92 ( struct V_66 * V_66 , struct V_3 * V_3 ,
T_2 V_115 )
{
struct V_2 * V_2 ;
int V_244 = V_245 ;
if ( V_115 >= sizeof( struct V_66 ) ) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_60 ( L_37 ,
V_3 -> V_44 -> V_91 , V_3 -> V_5 -> V_44 -> V_91 ) ;
return V_244 ;
}
switch ( V_66 -> V_202 ) {
case V_246 :
V_244 = V_247 ;
F_21 ( V_3 -> V_5 -> V_44 ,
L_38 ,
V_2 -> V_45 ,
V_3 -> V_44 -> V_91 ) ;
F_93 ( & V_3 -> V_5 -> V_233 ) ;
F_53 ( V_66 , V_2 ) ;
F_94 ( & V_3 -> V_5 -> V_233 ) ;
break;
case V_248 :
V_244 = V_247 ;
switch ( ( (struct V_130 * ) V_66 ) -> V_216 ) {
case V_249 :
F_21 ( V_3 -> V_5 -> V_44 , L_39 ,
V_2 -> V_45 ) ;
F_71 ( (struct V_130 * ) V_66 , V_2 ) ;
break;
case V_217 :
F_21 ( V_3 -> V_5 -> V_44 , L_40 ,
V_2 -> V_45 ) ;
F_72 ( (struct V_130 * ) V_66 , V_2 ) ;
break;
default:
F_21 ( V_3 -> V_5 -> V_44 , L_41 ,
V_2 -> V_45 ) ;
}
}
}
return V_244 ;
}
static void F_76 ( struct V_2 * V_2 , bool V_250 )
{
T_3 V_47 = 0 ;
T_2 V_251 = 0 , V_17 = 0 ;
T_2 V_252 = V_2 -> V_72 ;
V_2 -> V_191 &= ~ ( V_253 | V_156 ) ;
if ( ! V_250 ) {
V_17 = F_20 ( V_2 ) ;
V_251 = ( V_252 & V_253 ) >> 1 ;
V_47 = F_22 ( V_2 ) ;
V_2 -> V_191 |= ( V_17 << 1 ) | V_47 ;
}
V_2 -> V_72 = V_2 -> V_191 ;
if ( V_252 != V_2 -> V_72 ) {
if ( V_47 )
V_2 -> V_77 |= V_154 ;
else
V_2 -> V_77 &= ~ V_154 ;
if ( ! V_250 ) {
if ( ! V_17 ) {
F_54 ( V_2 -> V_3 -> V_44 ,
L_42 ,
V_2 -> V_3 -> V_44 -> V_91 ) ;
} else if ( V_47 && V_251 != V_17 ) {
V_2 -> V_77 |= V_137 ;
}
}
}
}
void F_95 ( struct V_3 * V_3 )
{
struct V_2 * V_2 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_3 -> V_5 -> V_44 ,
L_43 ,
V_3 -> V_44 -> V_91 ) ;
return;
}
F_78 ( & V_3 -> V_5 -> V_233 ) ;
F_76 ( V_2 , false ) ;
F_81 ( & V_3 -> V_5 -> V_233 ) ;
F_21 ( V_3 -> V_5 -> V_44 , L_44 ,
V_2 -> V_45 , V_3 -> V_44 -> V_91 ) ;
}
void F_96 ( struct V_3 * V_3 , char V_11 )
{
struct V_4 * V_7 ;
struct V_2 * V_2 ;
bool V_254 ;
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( ! V_2 -> V_3 ) {
F_79 ( V_3 -> V_5 -> V_44 , L_45 ,
V_3 -> V_44 -> V_91 ) ;
return;
}
F_78 ( & V_3 -> V_5 -> V_233 ) ;
if ( V_11 == V_12 ) {
V_2 -> V_105 = true ;
F_76 ( V_2 , false ) ;
} else {
V_2 -> V_105 = false ;
F_76 ( V_2 , true ) ;
}
V_7 = F_3 ( V_2 ) ;
F_62 ( V_7 , & V_254 ) ;
F_81 ( & V_3 -> V_5 -> V_233 ) ;
F_21 ( V_3 -> V_5 -> V_44 , L_46 ,
V_2 -> V_45 ,
V_11 == V_12 ? L_47 : L_48 ) ;
F_97 ( V_3 -> V_5 , NULL ) ;
}
int F_67 ( struct V_1 * V_5 )
{
struct V_4 * V_104 ;
struct V_3 * V_6 ;
int V_244 = 1 ;
F_4 () ;
V_6 = F_5 ( V_5 ) ;
if ( ! V_6 ) {
V_244 = 0 ;
goto V_234;
}
V_104 = F_38 ( & ( F_6 ( V_6 ) -> V_4 ) ) ;
if ( V_104 ) {
if ( F_36 ( V_104 ) < V_5 -> V_14 . V_255 ) {
if ( F_66 ( V_5 -> V_44 ) ) {
F_98 ( V_5 -> V_44 ) ;
goto V_234;
}
} else if ( ! F_66 ( V_5 -> V_44 ) ) {
F_99 ( V_5 -> V_44 ) ;
goto V_234;
}
} else if ( F_66 ( V_5 -> V_44 ) ) {
F_98 ( V_5 -> V_44 ) ;
}
V_234:
F_7 () ;
return V_244 ;
}
int F_100 ( struct V_1 * V_5 ,
struct V_256 * V_256 )
{
struct V_4 * V_4 = NULL ;
struct V_109 * V_110 ;
struct V_3 * V_3 ;
struct V_2 * V_2 ;
F_39 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 -> V_111 ) {
V_4 = V_2 -> V_4 ;
break;
}
}
if ( ! V_4 )
return - 1 ;
V_256 -> V_257 = V_4 -> V_185 ;
V_256 -> V_258 = F_36 ( V_4 ) ;
V_256 -> V_87 = V_4 -> V_186 ;
V_256 -> V_71 = V_4 -> V_187 ;
F_46 ( V_256 -> V_8 ,
V_4 -> V_8 . V_9 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_5 , struct V_256 * V_256 )
{
int V_244 ;
F_4 () ;
V_244 = F_100 ( V_5 , V_256 ) ;
F_7 () ;
return V_244 ;
}
int F_102 ( const struct V_112 * V_113 , struct V_1 * V_5 ,
struct V_3 * V_3 )
{
struct V_66 * V_66 , V_259 ;
if ( V_113 -> V_120 != V_121 )
return V_245 ;
if ( ! F_27 ( F_103 ( V_113 ) -> V_125 , V_126 ) )
return V_245 ;
V_66 = F_104 ( V_113 , 0 , sizeof( V_259 ) , & V_259 ) ;
if ( ! V_66 )
return V_245 ;
return F_92 ( V_66 , V_3 , V_113 -> V_260 ) ;
}
void F_105 ( struct V_1 * V_5 )
{
struct V_2 * V_2 = NULL ;
struct V_109 * V_110 ;
struct V_3 * V_3 ;
int V_200 ;
V_200 = V_5 -> V_14 . V_200 ;
F_78 ( & V_5 -> V_233 ) ;
F_61 (bond, slave, iter) {
V_2 = & ( F_6 ( V_3 ) -> V_2 ) ;
if ( V_200 )
V_2 -> V_75 |= V_97 ;
else
V_2 -> V_75 &= ~ V_97 ;
}
F_81 ( & V_5 -> V_233 ) ;
}
