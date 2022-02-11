static T_1 F_1 ( const struct V_1 * V_2 )
{
switch ( F_2 ( V_2 -> V_3 . type ) ) {
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
default:
return V_8 ;
}
}
static T_2 F_3 ( enum V_9 V_10 )
{
T_2 V_11 = V_12 ;
switch ( V_10 ) {
case V_13 :
case V_14 :
V_11 |= V_15 ;
break;
default:
break;
}
switch ( V_10 ) {
case V_16 :
case V_13 :
V_11 |= V_17 ;
break;
case V_18 :
case V_14 :
V_11 |= V_19 ;
break;
case V_20 :
V_11 |= V_21 ;
break;
default:
break;
}
return V_11 ;
}
static T_3 F_4 ( const struct V_22 * V_23 )
{
#if F_5 ( V_24 )
return V_23 ? V_23 -> V_25 : 0 ;
#else
return 0 ;
#endif
}
static void F_6 ( const struct V_22 * V_23 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = V_23 ? F_7 ( V_23 ) : NULL ;
if ( V_29 )
memcpy ( V_27 , V_29 -> V_30 , V_31 ) ;
else
memset ( V_27 , 0 , V_31 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_32 * V_33 ,
T_2 V_34 )
{
V_2 -> V_35 = V_33 -> V_36 . V_37 ;
if ( V_33 -> V_36 . V_37 == V_34 ) {
V_2 -> V_23 . V_38 . V_39 = F_9 ( V_33 -> V_36 . V_40 . V_41 . type ) ;
V_2 -> V_23 . V_38 . V_36 = F_9 ( V_33 -> V_36 . V_40 . V_41 . V_42 ) ;
} else {
V_2 -> V_23 . V_38 . V_39 = V_33 -> V_39 . V_40 . V_43 ;
V_2 -> V_23 . V_38 . V_36 = V_33 -> V_36 . V_40 . V_43 ;
}
}
static void F_10 ( struct V_1 * V_2 , T_2 V_44 ,
const struct V_45 * V_46 ,
const struct V_22 * V_23 )
{
V_2 -> V_11 = V_44 ;
V_2 -> V_47 = V_46 -> V_48 ;
V_2 -> V_23 . V_25 = F_4 ( V_23 ) ;
F_6 ( V_23 , & V_2 -> V_23 . V_27 ) ;
if ( V_23 ) {
const struct V_32 * V_33 ;
if ( V_23 -> V_49 )
V_23 = V_23 -> V_49 ;
V_33 = & V_23 -> V_50 [ V_51 ] . V_52 ;
if ( V_2 -> V_3 . type == F_9 ( V_4 ) &&
F_11 ( V_23 ) == V_5 ) {
V_2 -> V_53 . V_54 . V_39 = V_33 -> V_39 . V_55 . V_56 ;
V_2 -> V_53 . V_54 . V_36 = V_33 -> V_36 . V_55 . V_56 ;
F_8 ( V_2 , V_33 , V_57 ) ;
return;
} else if ( V_2 -> V_3 . type == F_9 ( V_6 ) &&
! F_12 ( V_2 ) &&
F_11 ( V_23 ) == V_7 ) {
V_2 -> V_58 . V_54 . V_39 = V_33 -> V_39 . V_55 . V_59 ;
V_2 -> V_58 . V_54 . V_36 = V_33 -> V_36 . V_55 . V_59 ;
F_8 ( V_2 , V_33 , V_60 ) ;
return;
}
}
V_2 -> V_35 = 0 ;
}
static void F_13 ( const struct V_61 * V_62 ,
const struct V_63 * V_64 ,
struct V_1 * V_2 , bool V_65 ,
bool V_66 )
{
const struct V_45 * V_46 = & V_67 ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
T_2 V_44 = 0 ;
V_23 = F_14 ( V_62 , & V_10 ) ;
if ( V_23 ) {
V_44 = F_3 ( V_10 ) ;
if ( ! F_15 ( V_23 ) )
V_44 |= V_21 ;
if ( V_23 -> V_49 )
V_44 |= V_19 ;
if ( V_66 ) {
V_44 |= V_2 -> V_11 & V_68 ;
} else {
if ( V_23 -> V_69 & V_70 )
V_44 |= V_71 ;
if ( V_23 -> V_69 & V_72 )
V_44 |= V_73 ;
}
V_46 = F_16 ( V_23 ) ;
} else if ( V_65 ) {
V_44 = V_12 | V_74 ;
if ( V_64 )
V_46 = & V_64 -> V_46 ;
}
F_10 ( V_2 , V_44 , V_46 , V_23 ) ;
}
void F_17 ( const struct V_61 * V_62 , struct V_1 * V_2 )
{
F_13 ( V_62 , NULL , V_2 , false , false ) ;
}
int F_18 ( const struct V_1 * V_75 ,
const struct V_1 * V_76 , struct V_61 * V_62 )
{
if ( F_19 ( V_62 , V_77 , V_76 -> V_11 ) )
return - V_78 ;
if ( F_5 ( V_79 ) &&
F_20 ( V_62 , V_80 , V_76 -> V_47 ) )
return - V_78 ;
if ( F_5 ( V_24 ) &&
F_19 ( V_62 , V_81 , V_76 -> V_23 . V_25 ) )
return - V_78 ;
if ( F_5 ( V_82 ) &&
F_21 ( V_62 , V_83 , sizeof( V_76 -> V_23 . V_27 ) ,
& V_76 -> V_23 . V_27 ) )
return - V_78 ;
if ( V_75 -> V_35 ) {
if ( V_75 -> V_3 . type == F_9 ( V_4 ) ) {
struct V_84 V_33 = {
V_76 -> V_53 . V_54 . V_39 ,
V_76 -> V_53 . V_54 . V_36 ,
V_76 -> V_23 . V_38 . V_39 ,
V_76 -> V_23 . V_38 . V_36 ,
V_76 -> V_35 ,
} ;
if ( F_21 ( V_62 , V_85 ,
sizeof( V_33 ) , & V_33 ) )
return - V_78 ;
} else if ( V_75 -> V_3 . type == F_9 ( V_6 ) ) {
struct V_86 V_33 = {
F_22 ( V_76 -> V_58 . V_54 . V_39 ) ,
F_22 ( V_76 -> V_58 . V_54 . V_36 ) ,
V_76 -> V_23 . V_38 . V_39 ,
V_76 -> V_23 . V_38 . V_36 ,
V_76 -> V_35 ,
} ;
if ( F_21 ( V_62 , V_87 ,
sizeof( V_33 ) , & V_33 ) )
return - V_78 ;
}
}
return 0 ;
}
static int F_23 ( struct V_22 * V_23 , struct V_1 * V_2 ,
T_3 V_88 , T_3 V_89 )
{
#if F_5 ( V_24 )
T_3 V_90 ;
V_90 = V_88 | ( V_23 -> V_25 & ~ ( V_89 ) ) ;
if ( V_23 -> V_25 != V_90 ) {
V_23 -> V_25 = V_90 ;
if ( F_15 ( V_23 ) )
F_24 ( V_91 , V_23 ) ;
V_2 -> V_23 . V_25 = V_90 ;
}
return 0 ;
#else
return - V_92 ;
#endif
}
static struct V_28 * F_25 ( struct V_22 * V_23 )
{
struct V_28 * V_29 ;
V_29 = F_7 ( V_23 ) ;
if ( ! V_29 ) {
F_26 ( V_23 ) ;
V_29 = F_7 ( V_23 ) ;
}
return V_29 ;
}
static int F_27 ( struct V_22 * V_23 , struct V_1 * V_2 ,
const struct V_26 * V_27 ,
const struct V_26 * V_89 )
{
struct V_28 * V_29 , * V_93 ;
bool V_94 = F_28 ( V_89 ) ;
V_93 = V_23 -> V_49 ? F_7 ( V_23 -> V_49 ) : NULL ;
if ( ! V_93 && ! V_94 )
return 0 ;
V_29 = F_25 ( V_23 ) ;
if ( ! V_29 )
return - V_95 ;
if ( V_93 )
* V_29 = * V_93 ;
if ( V_94 ) {
T_3 * V_36 = ( T_3 * ) V_29 -> V_30 ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
V_36 [ V_96 ] = ( V_36 [ V_96 ] & ~ V_89 -> V_98 [ V_96 ] ) |
( V_27 -> V_98 [ V_96 ]
& V_89 -> V_98 [ V_96 ] ) ;
}
F_24 ( V_99 , V_23 ) ;
memcpy ( & V_2 -> V_23 . V_27 , V_29 -> V_30 , V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_22 * V_23 , struct V_1 * V_2 ,
const struct V_26 * V_27 ,
const struct V_26 * V_89 )
{
struct V_28 * V_29 ;
int V_100 ;
V_29 = F_25 ( V_23 ) ;
if ( ! V_29 )
return - V_95 ;
V_100 = F_30 ( V_23 , V_27 -> V_98 ,
V_89 -> V_98 ,
V_97 ) ;
if ( V_100 )
return V_100 ;
memcpy ( & V_2 -> V_23 . V_27 , V_29 -> V_30 , V_31 ) ;
return 0 ;
}
static int F_31 ( struct V_61 * V_62 , T_1 V_101 )
{
const struct V_102 * V_103 ;
const struct V_104 * V_105 ;
enum V_9 V_10 ;
unsigned int V_106 ;
struct V_22 * V_23 ;
int V_100 ;
V_23 = F_14 ( V_62 , & V_10 ) ;
if ( ! V_23 || V_10 == V_14 )
return V_107 ;
V_105 = F_32 ( V_23 ) ;
if ( ! V_105 )
return V_107 ;
V_103 = F_33 ( V_105 -> V_103 ) ;
if ( ! V_103 )
return V_107 ;
switch ( V_101 ) {
case V_5 :
V_106 = F_34 ( V_62 ) ;
break;
case V_7 : {
T_2 V_108 = F_35 ( V_62 ) -> V_108 ;
T_4 V_109 ;
int V_110 ;
V_110 = F_36 ( V_62 , sizeof( struct V_111 ) , & V_108 ,
& V_109 ) ;
if ( V_110 < 0 || ( V_109 & F_9 ( ~ 0x7 ) ) != 0 ) {
F_37 ( L_1 ) ;
return V_107 ;
}
V_106 = V_110 ;
break;
}
default:
F_38 ( 1 , L_2 ) ;
return V_112 ;
}
V_100 = V_103 -> V_105 ( V_62 , V_106 , V_23 , V_10 ) ;
if ( V_100 != V_107 )
return V_100 ;
if ( F_39 ( V_113 , & V_23 -> V_69 ) &&
! F_40 ( V_62 , V_23 , V_10 , V_106 ) )
return V_112 ;
return V_107 ;
}
static int F_41 ( struct V_114 * V_114 , struct V_1 * V_2 ,
T_1 V_46 , struct V_61 * V_62 )
{
struct V_115 V_116 = * F_42 ( V_62 ) ;
int V_100 ;
if ( V_2 -> V_3 . type == F_9 ( V_4 ) ) {
enum V_117 V_118 = V_119 + V_46 ;
memset ( F_43 ( V_62 ) , 0 , sizeof( struct V_120 ) ) ;
V_100 = F_44 ( V_114 , V_62 , V_118 ) ;
if ( V_100 )
return V_100 ;
V_116 . V_121 = F_43 ( V_62 ) -> V_122 ;
#if F_5 ( V_123 )
} else if ( V_2 -> V_3 . type == F_9 ( V_6 ) ) {
enum V_124 V_118 = V_125 + V_46 ;
memset ( F_45 ( V_62 ) , 0 , sizeof( struct V_126 ) ) ;
V_100 = F_46 ( V_114 , V_62 , V_118 ) ;
if ( V_100 ) {
if ( V_100 != - V_127 )
F_47 ( V_62 ) ;
return V_100 ;
}
V_2 -> V_56 . V_101 = F_35 ( V_62 ) -> V_108 ;
V_116 . V_121 = F_45 ( V_62 ) -> V_122 ;
#endif
} else {
F_47 ( V_62 ) ;
return - V_128 ;
}
V_2 -> V_56 . V_129 = V_130 ;
F_48 ( V_62 ) ;
V_62 -> V_131 = 1 ;
* F_42 ( V_62 ) = V_116 ;
return 0 ;
}
static struct V_132 *
F_49 ( struct V_114 * V_114 , const struct V_45 * V_46 ,
T_1 V_101 , const struct V_61 * V_62 )
{
struct V_32 V_52 ;
struct V_132 * exp ;
if ( ! F_50 ( V_62 , F_51 ( V_62 ) , V_101 , V_114 , & V_52 ) )
return NULL ;
exp = F_52 ( V_114 , V_46 , & V_52 ) ;
if ( exp ) {
struct V_133 * V_134 ;
V_134 = F_53 ( V_114 , V_46 , & V_52 ) ;
if ( V_134 ) {
struct V_22 * V_23 = F_54 ( V_134 ) ;
F_55 ( V_23 , 0 , 0 ) ;
F_56 ( & V_23 -> V_135 ) ;
}
}
return exp ;
}
static enum V_9
F_57 ( const struct V_133 * V_134 )
{
const struct V_22 * V_23 = F_54 ( V_134 ) ;
if ( F_58 ( V_134 ) == V_136 )
return V_13 ;
if ( F_39 ( V_137 , & V_23 -> V_69 ) )
return V_16 ;
if ( F_39 ( V_138 , & V_23 -> V_69 ) )
return V_18 ;
return V_20 ;
}
static struct V_22 *
F_59 ( struct V_114 * V_114 , const struct V_45 * V_46 ,
T_2 V_139 , struct V_61 * V_62 , bool V_140 )
{
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_32 V_52 ;
struct V_133 * V_134 ;
struct V_22 * V_23 ;
unsigned int V_145 ;
T_2 V_37 ;
V_142 = F_60 ( V_139 ) ;
if ( V_142 -> V_146 ( V_62 , F_51 ( V_62 ) , & V_145 ,
& V_37 ) <= 0 ) {
F_37 ( L_3 ) ;
return NULL ;
}
V_144 = F_61 ( V_139 , V_37 ) ;
if ( ! F_62 ( V_62 , F_51 ( V_62 ) , V_145 , V_139 ,
V_37 , V_114 , & V_52 , V_142 , V_144 ) ) {
F_37 ( L_4 ) ;
return NULL ;
}
if ( V_140 ) {
struct V_32 V_147 ;
if ( ! F_63 ( & V_147 , & V_52 , V_142 , V_144 ) ) {
F_37 ( L_5 ) ;
return NULL ;
}
V_52 = V_147 ;
}
V_134 = F_53 ( V_114 , V_46 , & V_52 ) ;
if ( ! V_134 )
return NULL ;
V_23 = F_54 ( V_134 ) ;
if ( V_140 )
V_134 = & V_23 -> V_50 [ ! V_134 -> V_52 . V_36 . V_148 ] ;
F_64 ( V_62 , V_23 , F_57 ( V_134 ) ) ;
return V_23 ;
}
static bool F_65 ( struct V_114 * V_114 ,
const struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
enum V_9 V_10 ;
struct V_22 * V_23 ;
V_23 = F_14 ( V_62 , & V_10 ) ;
if ( ! V_23 && V_2 -> V_11 & V_12 &&
! ( V_2 -> V_11 & V_74 ) &&
V_2 -> V_47 == V_64 -> V_46 . V_48 ) {
V_23 = F_59 ( V_114 , & V_64 -> V_46 , V_64 -> V_149 , V_62 ,
! ! ( V_2 -> V_11
& V_68 ) ) ;
if ( V_23 )
F_14 ( V_62 , & V_10 ) ;
}
if ( ! V_23 )
return false ;
if ( ! F_66 ( V_114 , F_67 ( & V_23 -> V_150 ) ) )
return false ;
if ( ! F_68 ( V_64 -> V_23 , F_16 ( V_23 ) ) )
return false ;
if ( V_64 -> V_103 ) {
struct V_104 * V_105 ;
V_105 = F_69 ( V_23 , V_151 ) ;
if ( V_105 && F_70 ( V_105 -> V_103 ) != V_64 -> V_103 )
return false ;
}
if ( V_64 -> V_152 && F_71 ( V_10 ) != V_51 ) {
if ( F_15 ( V_23 ) )
F_55 ( V_23 , 0 , 0 ) ;
F_56 ( & V_23 -> V_135 ) ;
F_64 ( V_62 , NULL , 0 ) ;
return false ;
}
return true ;
}
static int F_72 ( struct V_61 * V_62 , struct V_22 * V_23 ,
enum V_9 V_10 ,
const struct V_153 * V_154 ,
enum V_155 V_156 )
{
int V_157 , V_158 , V_100 = V_107 ;
V_158 = F_51 ( V_62 ) ;
F_73 ( V_62 , V_158 ) ;
if ( V_156 == V_159 )
V_157 = V_160 ;
else
V_157 = V_161 ;
switch ( V_10 ) {
case V_18 :
case V_14 :
if ( F_5 ( V_162 ) &&
V_62 -> V_163 == F_9 ( V_4 ) &&
F_74 ( V_62 ) -> V_163 == V_57 ) {
if ( ! F_75 ( V_62 , V_23 , V_10 ,
V_157 ) )
V_100 = V_112 ;
goto V_164;
} else if ( F_5 ( V_165 ) &&
V_62 -> V_163 == F_9 ( V_6 ) ) {
T_4 V_109 ;
T_2 V_108 = F_35 ( V_62 ) -> V_108 ;
int V_166 = F_36 ( V_62 ,
sizeof( struct V_111 ) ,
& V_108 , & V_109 ) ;
if ( V_166 >= 0 && V_108 == V_167 ) {
if ( ! F_76 ( V_62 , V_23 ,
V_10 ,
V_157 ,
V_166 ) )
V_100 = V_112 ;
goto V_164;
}
}
case V_20 :
if ( ! F_77 ( V_23 , V_156 ) ) {
V_100 = ( V_154 && V_154 -> V_168 & V_169 )
? F_78 ( V_23 , V_154 , V_156 )
: F_79 ( V_23 , V_157 ) ;
if ( V_100 != V_107 )
goto V_164;
}
break;
case V_16 :
case V_13 :
break;
default:
V_100 = V_112 ;
goto V_164;
}
V_100 = F_80 ( V_23 , V_10 , V_157 , V_62 ) ;
V_164:
F_81 ( V_62 , V_158 ) ;
F_82 ( V_62 , V_62 -> V_170 , V_158 ) ;
return V_100 ;
}
static void F_83 ( struct V_1 * V_2 ,
const struct V_61 * V_62 ,
enum V_155 V_156 )
{
if ( V_156 == V_159 ) {
T_4 V_39 ;
V_2 -> V_11 |= V_71 ;
if ( V_2 -> V_3 . type == F_9 ( V_4 ) )
V_2 -> V_53 . V_171 . V_39 = F_74 ( V_62 ) -> V_172 ;
else if ( V_2 -> V_3 . type == F_9 ( V_6 ) )
memcpy ( & V_2 -> V_58 . V_171 . V_39 , & F_35 ( V_62 ) -> V_172 ,
sizeof( V_2 -> V_58 . V_171 . V_39 ) ) ;
else
return;
if ( V_2 -> V_56 . V_101 == V_173 )
V_39 = F_84 ( V_62 ) -> V_174 ;
else if ( V_2 -> V_56 . V_101 == V_175 )
V_39 = F_85 ( V_62 ) -> V_174 ;
else if ( V_2 -> V_56 . V_101 == V_176 )
V_39 = F_86 ( V_62 ) -> V_174 ;
else
return;
V_2 -> V_177 . V_39 = V_39 ;
} else {
T_4 V_36 ;
V_2 -> V_11 |= V_73 ;
if ( V_2 -> V_3 . type == F_9 ( V_4 ) )
V_2 -> V_53 . V_171 . V_36 = F_74 ( V_62 ) -> V_178 ;
else if ( V_2 -> V_3 . type == F_9 ( V_6 ) )
memcpy ( & V_2 -> V_58 . V_171 . V_36 , & F_35 ( V_62 ) -> V_178 ,
sizeof( V_2 -> V_58 . V_171 . V_36 ) ) ;
else
return;
if ( V_2 -> V_56 . V_101 == V_173 )
V_36 = F_84 ( V_62 ) -> V_179 ;
else if ( V_2 -> V_56 . V_101 == V_175 )
V_36 = F_85 ( V_62 ) -> V_179 ;
else if ( V_2 -> V_56 . V_101 == V_176 )
V_36 = F_86 ( V_62 ) -> V_179 ;
else
return;
V_2 -> V_177 . V_36 = V_36 ;
}
}
static int F_87 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
enum V_155 V_156 ;
int V_100 ;
if ( ! F_15 ( V_23 ) && ! F_88 ( V_23 ) )
return V_107 ;
if ( V_64 -> V_180 & V_181 && V_10 != V_20 &&
V_23 -> V_69 & V_182 &&
( V_10 != V_18 || V_64 -> V_183 ) ) {
if ( F_71 ( V_10 ) == V_136 )
V_156 = V_23 -> V_69 & V_70
? V_184 : V_159 ;
else
V_156 = V_23 -> V_69 & V_70
? V_159 : V_184 ;
} else if ( V_64 -> V_180 & V_185 ) {
V_156 = V_159 ;
} else if ( V_64 -> V_180 & V_186 ) {
V_156 = V_184 ;
} else {
return V_107 ;
}
V_100 = F_72 ( V_62 , V_23 , V_10 , & V_64 -> V_154 , V_156 ) ;
if ( V_100 == V_107 )
F_83 ( V_2 , V_62 , V_156 ) ;
return V_100 ;
}
static int F_87 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
return V_107 ;
}
static int F_89 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
bool V_187 = F_65 ( V_114 , V_2 , V_64 , V_62 ) ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
if ( ! V_187 ) {
struct V_22 * V_188 = V_64 -> V_23 ;
int V_100 ;
if ( V_188 ) {
if ( F_90 ( V_62 ) )
F_56 ( F_90 ( V_62 ) ) ;
F_91 ( & V_188 -> V_135 ) ;
F_64 ( V_62 , V_188 , V_20 ) ;
}
V_100 = F_92 ( V_114 , V_64 -> V_149 ,
V_189 , V_62 ) ;
if ( V_100 != V_107 )
return - V_190 ;
V_2 -> V_11 = 0 ;
F_13 ( V_62 , V_64 , V_2 , true , true ) ;
}
V_23 = F_14 ( V_62 , & V_10 ) ;
if ( V_23 ) {
if ( V_64 -> V_180 && ! ( V_2 -> V_11 & V_68 ) &&
( F_15 ( V_23 ) || V_64 -> V_183 ) &&
F_87 ( V_114 , V_2 , V_64 , V_62 , V_23 , V_10 ) != V_107 ) {
return - V_191 ;
}
if ( ! F_15 ( V_23 ) && V_64 -> V_183 &&
V_64 -> V_103 && ! F_32 ( V_23 ) ) {
int V_100 = F_93 ( V_23 , V_64 -> V_23 ,
V_192 ) ;
if ( V_100 )
return V_100 ;
}
if ( ( F_15 ( V_23 ) ? ! V_187 : V_64 -> V_183 ) &&
F_31 ( V_62 , V_64 -> V_149 ) != V_107 ) {
return - V_191 ;
}
}
return 0 ;
}
static int F_94 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
struct V_132 * exp ;
exp = F_49 ( V_114 , & V_64 -> V_46 , V_64 -> V_149 , V_62 ) ;
if ( exp ) {
T_2 V_44 ;
V_44 = V_12 | V_21 | V_19 ;
F_10 ( V_2 , V_44 , & V_64 -> V_46 , exp -> V_49 ) ;
} else {
struct V_22 * V_23 ;
int V_100 ;
V_100 = F_89 ( V_114 , V_2 , V_64 , V_62 ) ;
if ( V_100 )
return V_100 ;
V_23 = (struct V_22 * ) F_90 ( V_62 ) ;
if ( V_23 )
F_95 ( V_23 ) ;
}
return 0 ;
}
static bool F_28 ( const struct V_26 * V_27 )
{
T_5 V_96 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
if ( V_27 -> V_98 [ V_96 ] )
return true ;
return false ;
}
static int F_96 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
enum V_9 V_10 ;
struct V_22 * V_23 ;
int V_100 ;
V_100 = F_89 ( V_114 , V_2 , V_64 , V_62 ) ;
if ( V_100 )
return V_100 ;
V_23 = F_14 ( V_62 , & V_10 ) ;
if ( ! V_23 )
return 0 ;
if ( V_64 -> V_193 ) {
struct V_194 * V_195 = F_97 ( V_23 ) ;
if ( V_195 )
V_195 -> V_196 = V_64 -> V_197 ;
}
if ( V_64 -> V_25 . V_89 ) {
V_100 = F_23 ( V_23 , V_2 , V_64 -> V_25 . V_198 ,
V_64 -> V_25 . V_89 ) ;
if ( V_100 )
return V_100 ;
}
if ( ! F_15 ( V_23 ) ) {
V_100 = F_27 ( V_23 , V_2 , & V_64 -> V_27 . V_198 ,
& V_64 -> V_27 . V_89 ) ;
if ( V_100 )
return V_100 ;
} else if ( F_28 ( & V_64 -> V_27 . V_89 ) ) {
V_100 = F_29 ( V_23 , V_2 , & V_64 -> V_27 . V_198 ,
& V_64 -> V_27 . V_89 ) ;
if ( V_100 )
return V_100 ;
}
if ( F_98 ( V_62 ) != V_107 )
return - V_191 ;
return 0 ;
}
int F_99 ( struct V_114 * V_114 , struct V_61 * V_62 ,
struct V_1 * V_2 ,
const struct V_63 * V_64 )
{
int V_199 ;
int V_100 ;
V_199 = F_51 ( V_62 ) ;
F_73 ( V_62 , V_199 ) ;
if ( V_2 -> V_56 . V_129 != V_130 ) {
V_100 = F_41 ( V_114 , V_2 , V_64 -> V_46 . V_48 , V_62 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_64 -> V_183 )
V_100 = F_96 ( V_114 , V_2 , V_64 , V_62 ) ;
else
V_100 = F_94 ( V_114 , V_2 , V_64 , V_62 ) ;
F_81 ( V_62 , V_199 ) ;
F_82 ( V_62 , V_62 -> V_170 , V_199 ) ;
if ( V_100 )
F_47 ( V_62 ) ;
return V_100 ;
}
static int F_100 ( struct V_63 * V_64 , const char * V_200 ,
const struct V_1 * V_2 , bool log )
{
struct V_102 * V_103 ;
struct V_104 * V_105 ;
V_103 = F_101 ( V_200 , V_64 -> V_149 ,
V_2 -> V_56 . V_101 ) ;
if ( ! V_103 ) {
F_102 ( log , L_6 , V_200 ) ;
return - V_191 ;
}
V_105 = F_103 ( V_64 -> V_23 , V_103 , V_201 ) ;
if ( ! V_105 ) {
F_104 ( V_103 ) ;
return - V_202 ;
}
F_105 ( V_105 -> V_103 , V_103 ) ;
V_64 -> V_103 = V_103 ;
return 0 ;
}
static int F_106 ( const struct V_203 * V_204 ,
struct V_63 * V_64 , bool log )
{
struct V_203 * V_205 ;
int V_206 ;
bool V_207 = false ;
bool V_208 = false ;
bool V_209 = ( V_64 -> V_149 == V_7 ) ;
F_107 (a, attr, rem) {
static const int V_210 [ V_211 + 1 ] [ 2 ] = {
[ V_212 ] = { 0 , 0 } ,
[ V_213 ] = { 0 , 0 } ,
[ V_214 ] = { sizeof( struct V_215 ) ,
sizeof(struct V_216 ) } ,
[ V_217 ] = { sizeof( struct V_215 ) ,
sizeof(struct V_216 ) } ,
[ V_218 ] = { sizeof( T_1 ) , sizeof( T_1 ) } ,
[ V_219 ] = { sizeof( T_1 ) , sizeof( T_1 ) } ,
[ V_220 ] = { 0 , 0 } ,
[ V_221 ] = { 0 , 0 } ,
[ V_222 ] = { 0 , 0 } ,
} ;
int type = F_108 ( V_205 ) ;
if ( type > V_211 ) {
F_102 ( log ,
L_7 ,
type , V_211 ) ;
return - V_191 ;
}
if ( F_109 ( V_205 ) != V_210 [ type ] [ V_209 ] ) {
F_102 ( log ,
L_8 ,
type , F_109 ( V_205 ) ,
V_210 [ type ] [ V_209 ] ) ;
return - V_191 ;
}
switch ( type ) {
case V_212 :
case V_213 :
if ( V_64 -> V_180 ) {
F_102 ( log ,
L_9
) ;
return - V_223 ;
}
V_64 -> V_180 |= V_181 ;
V_64 -> V_180 |= ( ( type == V_212 )
? V_185 : V_186 ) ;
break;
case V_214 :
F_110 ( & V_64 -> V_154 . V_224 , V_205 ,
sizeof( V_64 -> V_154 . V_224 ) ) ;
V_64 -> V_154 . V_168 |= V_169 ;
break;
case V_217 :
V_207 = true ;
F_110 ( & V_64 -> V_154 . V_225 , V_205 ,
sizeof( V_64 -> V_154 . V_225 ) ) ;
V_64 -> V_154 . V_168 |= V_169 ;
break;
case V_218 :
V_64 -> V_154 . V_226 . V_43 = F_9 ( F_111 ( V_205 ) ) ;
V_64 -> V_154 . V_168 |= V_227 ;
break;
case V_219 :
V_208 = true ;
V_64 -> V_154 . V_228 . V_43 = F_9 ( F_111 ( V_205 ) ) ;
V_64 -> V_154 . V_168 |= V_227 ;
break;
case V_220 :
V_64 -> V_154 . V_168 |= V_229 ;
break;
case V_221 :
V_64 -> V_154 . V_168 |= V_230 ;
break;
case V_222 :
V_64 -> V_154 . V_168 |= V_231 ;
break;
default:
F_102 ( log , L_10 , type ) ;
return - V_191 ;
}
}
if ( V_206 > 0 ) {
F_102 ( log , L_11 , V_206 ) ;
return - V_191 ;
}
if ( ! V_64 -> V_180 ) {
if ( V_64 -> V_154 . V_168 ) {
F_102 ( log ,
L_12
) ;
return - V_191 ;
}
V_64 -> V_180 = V_181 ;
} else if ( ! V_64 -> V_183 ) {
F_102 ( log ,
L_13
) ;
return - V_191 ;
}
if ( V_64 -> V_154 . V_168 & V_169 && ! V_207 ) {
memcpy ( & V_64 -> V_154 . V_225 , & V_64 -> V_154 . V_224 ,
sizeof( V_64 -> V_154 . V_225 ) ) ;
}
if ( V_64 -> V_154 . V_168 & V_227 &&
! V_208 ) {
V_64 -> V_154 . V_228 . V_43 = V_64 -> V_154 . V_226 . V_43 ;
}
return 0 ;
}
static int F_112 ( const struct V_203 * V_204 , struct V_63 * V_64 ,
const char * * V_103 , bool log )
{
struct V_203 * V_205 ;
int V_206 ;
F_107 (a, attr, rem) {
int type = F_108 ( V_205 ) ;
int V_232 = V_233 [ type ] . V_232 ;
int V_234 = V_233 [ type ] . V_234 ;
if ( type > V_235 ) {
F_102 ( log ,
L_14 ,
type , V_235 ) ;
return - V_191 ;
}
if ( F_109 ( V_205 ) < V_234 || F_109 ( V_205 ) > V_232 ) {
F_102 ( log ,
L_15 ,
type , F_109 ( V_205 ) , V_232 ) ;
return - V_191 ;
}
switch ( type ) {
case V_236 :
V_64 -> V_152 = true ;
case V_237 :
V_64 -> V_183 = true ;
break;
#ifdef V_79
case V_238 :
V_64 -> V_46 . V_48 = F_111 ( V_205 ) ;
break;
#endif
#ifdef V_24
case V_239 : {
struct V_240 * V_25 = F_113 ( V_205 ) ;
if ( ! V_25 -> V_89 ) {
F_102 ( log , L_16 ) ;
return - V_191 ;
}
V_64 -> V_25 = * V_25 ;
break;
}
#endif
#ifdef V_82
case V_241 : {
struct V_242 * V_27 = F_113 ( V_205 ) ;
if ( ! F_28 ( & V_27 -> V_89 ) ) {
F_102 ( log , L_17 ) ;
return - V_191 ;
}
V_64 -> V_27 = * V_27 ;
break;
}
#endif
case V_243 :
* V_103 = F_113 ( V_205 ) ;
if ( ! memchr ( * V_103 , '\0' , F_109 ( V_205 ) ) ) {
F_102 ( log , L_18 ) ;
return - V_191 ;
}
break;
#ifdef F_114
case V_244 : {
int V_100 = F_106 ( V_205 , V_64 , log ) ;
if ( V_100 )
return V_100 ;
break;
}
#endif
case V_245 :
V_64 -> V_193 = true ;
V_64 -> V_197 = F_115 ( V_205 ) ;
break;
default:
F_102 ( log , L_19 ,
type ) ;
return - V_191 ;
}
}
#ifdef V_24
if ( ! V_64 -> V_183 && V_64 -> V_25 . V_89 ) {
F_102 ( log ,
L_20 ) ;
return - V_191 ;
}
#endif
#ifdef V_82
if ( ! V_64 -> V_183 && F_28 ( & V_64 -> V_27 . V_89 ) ) {
F_102 ( log ,
L_21 ) ;
return - V_191 ;
}
#endif
if ( V_206 > 0 ) {
F_102 ( log , L_22 , V_206 ) ;
return - V_191 ;
}
return 0 ;
}
bool F_116 ( struct V_114 * V_114 , enum V_246 V_204 )
{
if ( V_204 == V_77 )
return true ;
if ( F_5 ( V_79 ) &&
V_204 == V_80 )
return true ;
if ( F_5 ( V_24 ) &&
V_204 == V_81 )
return true ;
if ( F_5 ( V_82 ) &&
V_204 == V_83 ) {
struct V_247 * V_247 = F_117 ( V_114 , V_248 ) ;
return V_247 -> V_249 ;
}
return false ;
}
int F_118 ( struct V_114 * V_114 , const struct V_203 * V_204 ,
const struct V_1 * V_2 ,
struct V_250 * * V_251 , bool log )
{
struct V_63 V_252 ;
const char * V_103 = NULL ;
T_1 V_149 ;
int V_100 ;
V_149 = F_1 ( V_2 ) ;
if ( V_149 == V_8 ) {
F_102 ( log , L_23 ) ;
return - V_191 ;
}
memset ( & V_252 , 0 , sizeof( V_252 ) ) ;
V_252 . V_149 = V_149 ;
F_119 ( & V_252 . V_46 , V_253 ,
V_254 , 0 ) ;
V_100 = F_112 ( V_204 , & V_252 , & V_103 , log ) ;
if ( V_100 )
return V_100 ;
V_252 . V_23 = F_120 ( V_114 , & V_252 . V_46 , V_201 ) ;
if ( ! V_252 . V_23 ) {
F_102 ( log , L_24 ) ;
return - V_202 ;
}
F_121 ( V_255 , & V_252 . V_23 -> V_69 ) ;
F_91 ( & V_252 . V_23 -> V_135 ) ;
if ( V_103 ) {
V_100 = F_100 ( & V_252 , V_103 , V_2 , log ) ;
if ( V_100 )
goto V_256;
}
V_100 = F_122 ( V_251 , V_257 , & V_252 ,
sizeof( V_252 ) , log ) ;
if ( V_100 )
goto V_256;
return 0 ;
V_256:
F_123 ( & V_252 ) ;
return V_100 ;
}
static bool F_124 ( const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
struct V_203 * V_258 ;
V_258 = F_125 ( V_62 , V_244 ) ;
if ( ! V_258 )
return false ;
if ( V_64 -> V_180 & V_185 ) {
if ( F_126 ( V_62 , V_212 ) )
return false ;
} else if ( V_64 -> V_180 & V_186 ) {
if ( F_126 ( V_62 , V_213 ) )
return false ;
} else {
goto V_259;
}
if ( V_64 -> V_154 . V_168 & V_169 ) {
if ( F_5 ( V_162 ) &&
V_64 -> V_149 == V_5 ) {
if ( F_127 ( V_62 , V_214 ,
V_64 -> V_154 . V_224 . V_56 ) ||
( V_64 -> V_154 . V_225 . V_56
!= V_64 -> V_154 . V_224 . V_56 &&
( F_127 ( V_62 , V_217 ,
V_64 -> V_154 . V_225 . V_56 ) ) ) )
return false ;
} else if ( F_5 ( V_165 ) &&
V_64 -> V_149 == V_7 ) {
if ( F_128 ( V_62 , V_214 ,
& V_64 -> V_154 . V_224 . V_59 ) ||
( memcmp ( & V_64 -> V_154 . V_225 . V_59 ,
& V_64 -> V_154 . V_224 . V_59 ,
sizeof( V_64 -> V_154 . V_225 . V_59 ) ) &&
( F_128 ( V_62 , V_217 ,
& V_64 -> V_154 . V_225 . V_59 ) ) ) )
return false ;
} else {
return false ;
}
}
if ( V_64 -> V_154 . V_168 & V_227 &&
( F_20 ( V_62 , V_218 ,
F_2 ( V_64 -> V_154 . V_226 . V_43 ) ) ||
( V_64 -> V_154 . V_228 . V_43 != V_64 -> V_154 . V_226 . V_43 &&
F_20 ( V_62 , V_219 ,
F_2 ( V_64 -> V_154 . V_228 . V_43 ) ) ) ) )
return false ;
if ( V_64 -> V_154 . V_168 & V_229 &&
F_126 ( V_62 , V_220 ) )
return false ;
if ( V_64 -> V_154 . V_168 & V_230 &&
F_126 ( V_62 , V_221 ) )
return false ;
if ( V_64 -> V_154 . V_168 & V_231 &&
F_126 ( V_62 , V_222 ) )
return false ;
V_259:
F_129 ( V_62 , V_258 ) ;
return true ;
}
int F_130 ( const struct V_63 * V_252 ,
struct V_61 * V_62 )
{
struct V_203 * V_258 ;
V_258 = F_125 ( V_62 , V_257 ) ;
if ( ! V_258 )
return - V_78 ;
if ( V_252 -> V_183 && F_126 ( V_62 , V_252 -> V_152
? V_236
: V_237 ) )
return - V_78 ;
if ( F_5 ( V_79 ) &&
F_20 ( V_62 , V_238 , V_252 -> V_46 . V_48 ) )
return - V_78 ;
if ( F_5 ( V_24 ) && V_252 -> V_25 . V_89 &&
F_21 ( V_62 , V_239 , sizeof( V_252 -> V_25 ) ,
& V_252 -> V_25 ) )
return - V_78 ;
if ( F_5 ( V_82 ) &&
F_28 ( & V_252 -> V_27 . V_89 ) &&
F_21 ( V_62 , V_241 , sizeof( V_252 -> V_27 ) ,
& V_252 -> V_27 ) )
return - V_78 ;
if ( V_252 -> V_103 ) {
if ( F_131 ( V_62 , V_243 ,
V_252 -> V_103 -> V_200 ) )
return - V_78 ;
}
if ( V_252 -> V_193 &&
F_19 ( V_62 , V_245 , V_252 -> V_197 ) )
return - V_78 ;
#ifdef F_114
if ( V_252 -> V_180 && ! F_124 ( V_252 , V_62 ) )
return - V_78 ;
#endif
F_129 ( V_62 , V_258 ) ;
return 0 ;
}
void F_132 ( const struct V_203 * V_205 )
{
struct V_63 * V_252 = F_113 ( V_205 ) ;
F_123 ( V_252 ) ;
}
static void F_123 ( struct V_63 * V_252 )
{
if ( V_252 -> V_103 )
F_104 ( V_252 -> V_103 ) ;
if ( V_252 -> V_23 )
F_133 ( V_252 -> V_23 ) ;
}
void F_134 ( struct V_114 * V_114 )
{
unsigned int V_260 = sizeof( struct V_26 ) * V_261 ;
struct V_247 * V_247 = F_117 ( V_114 , V_248 ) ;
if ( F_135 ( V_114 , V_260 - 1 ) ) {
V_247 -> V_249 = false ;
F_102 ( true , L_25 ) ;
} else {
V_247 -> V_249 = true ;
}
}
void F_136 ( struct V_114 * V_114 )
{
struct V_247 * V_247 = F_117 ( V_114 , V_248 ) ;
if ( V_247 -> V_249 )
F_137 ( V_114 ) ;
}
