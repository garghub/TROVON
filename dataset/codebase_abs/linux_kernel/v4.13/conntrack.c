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
static
struct V_22 * F_65 ( struct V_114 * V_114 ,
const struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 ,
bool * V_149 )
{
struct V_22 * V_23 = NULL ;
* V_149 = ( V_2 -> V_11 & V_12 ) &&
! ( V_2 -> V_11 & V_74 ) &&
( V_2 -> V_47 == V_64 -> V_46 . V_48 ) ;
if ( * V_149 || ( ! V_2 -> V_11 && V_64 -> V_150 ) ) {
V_23 = F_59 ( V_114 , & V_64 -> V_46 , V_64 -> V_151 , V_62 ,
! ! ( V_2 -> V_11 &
V_68 ) ) ;
}
return V_23 ;
}
static bool F_66 ( struct V_114 * V_114 ,
const struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
enum V_9 V_10 ;
struct V_22 * V_23 ;
bool V_149 = true ;
V_23 = F_14 ( V_62 , & V_10 ) ;
if ( ! V_23 )
V_23 = F_65 ( V_114 , V_2 , V_64 , V_62 , & V_149 ) ;
if ( V_23 )
F_14 ( V_62 , & V_10 ) ;
else
return false ;
if ( ! F_67 ( V_114 , F_68 ( & V_23 -> V_152 ) ) )
return false ;
if ( ! F_69 ( V_64 -> V_23 , F_16 ( V_23 ) ) )
return false ;
if ( V_64 -> V_103 ) {
struct V_104 * V_105 ;
V_105 = F_70 ( V_23 , V_153 ) ;
if ( V_105 && F_71 ( V_105 -> V_103 ) != V_64 -> V_103 )
return false ;
}
if ( V_64 -> V_150 && F_72 ( V_10 ) != V_51 ) {
if ( F_15 ( V_23 ) )
F_55 ( V_23 , 0 , 0 ) ;
F_56 ( & V_23 -> V_135 ) ;
F_64 ( V_62 , NULL , 0 ) ;
return false ;
}
return V_149 ;
}
static int F_73 ( struct V_61 * V_62 , struct V_22 * V_23 ,
enum V_9 V_10 ,
const struct V_154 * V_155 ,
enum V_156 V_157 )
{
int V_158 , V_159 , V_100 = V_107 ;
V_159 = F_51 ( V_62 ) ;
F_74 ( V_62 , V_159 ) ;
if ( V_157 == V_160 )
V_158 = V_161 ;
else
V_158 = V_162 ;
switch ( V_10 ) {
case V_18 :
case V_14 :
if ( F_5 ( V_163 ) &&
V_62 -> V_164 == F_9 ( V_4 ) &&
F_75 ( V_62 ) -> V_164 == V_57 ) {
if ( ! F_76 ( V_62 , V_23 , V_10 ,
V_158 ) )
V_100 = V_112 ;
goto V_165;
} else if ( F_5 ( V_166 ) &&
V_62 -> V_164 == F_9 ( V_6 ) ) {
T_4 V_109 ;
T_2 V_108 = F_35 ( V_62 ) -> V_108 ;
int V_167 = F_36 ( V_62 ,
sizeof( struct V_111 ) ,
& V_108 , & V_109 ) ;
if ( V_167 >= 0 && V_108 == V_168 ) {
if ( ! F_77 ( V_62 , V_23 ,
V_10 ,
V_158 ,
V_167 ) )
V_100 = V_112 ;
goto V_165;
}
}
case V_20 :
if ( ! F_78 ( V_23 , V_157 ) ) {
V_100 = ( V_155 && V_155 -> V_169 & V_170 )
? F_79 ( V_23 , V_155 , V_157 )
: F_80 ( V_23 , V_158 ) ;
if ( V_100 != V_107 )
goto V_165;
}
break;
case V_16 :
case V_13 :
break;
default:
V_100 = V_112 ;
goto V_165;
}
V_100 = F_81 ( V_23 , V_10 , V_158 , V_62 ) ;
V_165:
F_82 ( V_62 , V_159 ) ;
F_83 ( V_62 , V_62 -> V_171 , V_159 ) ;
return V_100 ;
}
static void F_84 ( struct V_1 * V_2 ,
const struct V_61 * V_62 ,
enum V_156 V_157 )
{
if ( V_157 == V_160 ) {
T_4 V_39 ;
V_2 -> V_11 |= V_71 ;
if ( V_2 -> V_3 . type == F_9 ( V_4 ) )
V_2 -> V_53 . V_172 . V_39 = F_75 ( V_62 ) -> V_173 ;
else if ( V_2 -> V_3 . type == F_9 ( V_6 ) )
memcpy ( & V_2 -> V_58 . V_172 . V_39 , & F_35 ( V_62 ) -> V_173 ,
sizeof( V_2 -> V_58 . V_172 . V_39 ) ) ;
else
return;
if ( V_2 -> V_56 . V_101 == V_174 )
V_39 = F_85 ( V_62 ) -> V_175 ;
else if ( V_2 -> V_56 . V_101 == V_176 )
V_39 = F_86 ( V_62 ) -> V_175 ;
else if ( V_2 -> V_56 . V_101 == V_177 )
V_39 = F_87 ( V_62 ) -> V_175 ;
else
return;
V_2 -> V_178 . V_39 = V_39 ;
} else {
T_4 V_36 ;
V_2 -> V_11 |= V_73 ;
if ( V_2 -> V_3 . type == F_9 ( V_4 ) )
V_2 -> V_53 . V_172 . V_36 = F_75 ( V_62 ) -> V_179 ;
else if ( V_2 -> V_3 . type == F_9 ( V_6 ) )
memcpy ( & V_2 -> V_58 . V_172 . V_36 , & F_35 ( V_62 ) -> V_179 ,
sizeof( V_2 -> V_58 . V_172 . V_36 ) ) ;
else
return;
if ( V_2 -> V_56 . V_101 == V_174 )
V_36 = F_85 ( V_62 ) -> V_180 ;
else if ( V_2 -> V_56 . V_101 == V_176 )
V_36 = F_86 ( V_62 ) -> V_180 ;
else if ( V_2 -> V_56 . V_101 == V_177 )
V_36 = F_87 ( V_62 ) -> V_180 ;
else
return;
V_2 -> V_178 . V_36 = V_36 ;
}
}
static int F_88 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
enum V_156 V_157 ;
int V_100 ;
if ( ! F_15 ( V_23 ) && ! F_89 ( V_23 ) )
return V_107 ;
if ( V_64 -> V_181 & V_182 && V_10 != V_20 &&
V_23 -> V_69 & V_183 &&
( V_10 != V_18 || V_64 -> V_184 ) ) {
if ( F_72 ( V_10 ) == V_136 )
V_157 = V_23 -> V_69 & V_70
? V_185 : V_160 ;
else
V_157 = V_23 -> V_69 & V_70
? V_160 : V_185 ;
} else if ( V_64 -> V_181 & V_186 ) {
V_157 = V_160 ;
} else if ( V_64 -> V_181 & V_187 ) {
V_157 = V_185 ;
} else {
return V_107 ;
}
V_100 = F_73 ( V_62 , V_23 , V_10 , & V_64 -> V_155 , V_157 ) ;
if ( V_100 == V_107 )
F_84 ( V_2 , V_62 , V_157 ) ;
return V_100 ;
}
static int F_88 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
return V_107 ;
}
static int F_90 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
bool V_188 = F_66 ( V_114 , V_2 , V_64 , V_62 ) ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
if ( ! V_188 ) {
struct V_22 * V_189 = V_64 -> V_23 ;
int V_100 ;
if ( V_189 ) {
if ( F_91 ( V_62 ) )
F_56 ( F_91 ( V_62 ) ) ;
F_92 ( & V_189 -> V_135 ) ;
F_64 ( V_62 , V_189 , V_20 ) ;
}
V_100 = F_93 ( V_114 , V_64 -> V_151 ,
V_190 , V_62 ) ;
if ( V_100 != V_107 )
return - V_191 ;
V_2 -> V_11 = 0 ;
F_13 ( V_62 , V_64 , V_2 , true , true ) ;
}
V_23 = F_14 ( V_62 , & V_10 ) ;
if ( V_23 ) {
if ( V_64 -> V_181 && ! ( V_2 -> V_11 & V_68 ) &&
( F_15 ( V_23 ) || V_64 -> V_184 ) &&
F_88 ( V_114 , V_2 , V_64 , V_62 , V_23 , V_10 ) != V_107 ) {
return - V_192 ;
}
if ( ! F_15 ( V_23 ) && V_64 -> V_184 &&
V_64 -> V_103 && ! F_32 ( V_23 ) ) {
int V_100 = F_94 ( V_23 , V_64 -> V_23 ,
V_193 ) ;
if ( V_100 )
return V_100 ;
}
if ( ( F_15 ( V_23 ) ? ! V_188 : V_64 -> V_184 ) &&
F_31 ( V_62 , V_64 -> V_151 ) != V_107 ) {
return - V_192 ;
}
}
return 0 ;
}
static int F_95 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
struct V_132 * exp ;
exp = F_49 ( V_114 , & V_64 -> V_46 , V_64 -> V_151 , V_62 ) ;
if ( exp ) {
T_2 V_44 ;
V_44 = V_12 | V_21 | V_19 ;
F_10 ( V_2 , V_44 , & V_64 -> V_46 , exp -> V_49 ) ;
} else {
struct V_22 * V_23 ;
int V_100 ;
V_100 = F_90 ( V_114 , V_2 , V_64 , V_62 ) ;
if ( V_100 )
return V_100 ;
V_23 = (struct V_22 * ) F_91 ( V_62 ) ;
if ( V_23 )
F_96 ( V_23 ) ;
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
static int F_97 ( struct V_114 * V_114 , struct V_1 * V_2 ,
const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
enum V_9 V_10 ;
struct V_22 * V_23 ;
int V_100 ;
V_100 = F_90 ( V_114 , V_2 , V_64 , V_62 ) ;
if ( V_100 )
return V_100 ;
V_23 = F_14 ( V_62 , & V_10 ) ;
if ( ! V_23 )
return 0 ;
if ( V_64 -> V_194 ) {
struct V_195 * V_196 = F_98 ( V_23 ) ;
if ( V_196 )
V_196 -> V_197 = V_64 -> V_198 ;
}
if ( V_64 -> V_25 . V_89 ) {
V_100 = F_23 ( V_23 , V_2 , V_64 -> V_25 . V_199 ,
V_64 -> V_25 . V_89 ) ;
if ( V_100 )
return V_100 ;
}
if ( ! F_15 ( V_23 ) ) {
V_100 = F_27 ( V_23 , V_2 , & V_64 -> V_27 . V_199 ,
& V_64 -> V_27 . V_89 ) ;
if ( V_100 )
return V_100 ;
} else if ( F_28 ( & V_64 -> V_27 . V_89 ) ) {
V_100 = F_29 ( V_23 , V_2 , & V_64 -> V_27 . V_199 ,
& V_64 -> V_27 . V_89 ) ;
if ( V_100 )
return V_100 ;
}
if ( F_99 ( V_62 ) != V_107 )
return - V_192 ;
return 0 ;
}
int F_100 ( struct V_114 * V_114 , struct V_61 * V_62 ,
struct V_1 * V_2 ,
const struct V_63 * V_64 )
{
int V_200 ;
int V_100 ;
V_200 = F_51 ( V_62 ) ;
F_74 ( V_62 , V_200 ) ;
if ( V_2 -> V_56 . V_129 != V_130 ) {
V_100 = F_41 ( V_114 , V_2 , V_64 -> V_46 . V_48 , V_62 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_64 -> V_184 )
V_100 = F_97 ( V_114 , V_2 , V_64 , V_62 ) ;
else
V_100 = F_95 ( V_114 , V_2 , V_64 , V_62 ) ;
F_82 ( V_62 , V_200 ) ;
F_83 ( V_62 , V_62 -> V_171 , V_200 ) ;
if ( V_100 )
F_47 ( V_62 ) ;
return V_100 ;
}
static int F_101 ( struct V_63 * V_64 , const char * V_201 ,
const struct V_1 * V_2 , bool log )
{
struct V_102 * V_103 ;
struct V_104 * V_105 ;
V_103 = F_102 ( V_201 , V_64 -> V_151 ,
V_2 -> V_56 . V_101 ) ;
if ( ! V_103 ) {
F_103 ( log , L_6 , V_201 ) ;
return - V_192 ;
}
V_105 = F_104 ( V_64 -> V_23 , V_103 , V_202 ) ;
if ( ! V_105 ) {
F_105 ( V_103 ) ;
return - V_203 ;
}
F_106 ( V_105 -> V_103 , V_103 ) ;
V_64 -> V_103 = V_103 ;
return 0 ;
}
static int F_107 ( const struct V_204 * V_205 ,
struct V_63 * V_64 , bool log )
{
struct V_204 * V_206 ;
int V_207 ;
bool V_208 = false ;
bool V_209 = false ;
bool V_210 = ( V_64 -> V_151 == V_7 ) ;
F_108 (a, attr, rem) {
static const int V_211 [ V_212 + 1 ] [ 2 ] = {
[ V_213 ] = { 0 , 0 } ,
[ V_214 ] = { 0 , 0 } ,
[ V_215 ] = { sizeof( struct V_216 ) ,
sizeof(struct V_217 ) } ,
[ V_218 ] = { sizeof( struct V_216 ) ,
sizeof(struct V_217 ) } ,
[ V_219 ] = { sizeof( T_1 ) , sizeof( T_1 ) } ,
[ V_220 ] = { sizeof( T_1 ) , sizeof( T_1 ) } ,
[ V_221 ] = { 0 , 0 } ,
[ V_222 ] = { 0 , 0 } ,
[ V_223 ] = { 0 , 0 } ,
} ;
int type = F_109 ( V_206 ) ;
if ( type > V_212 ) {
F_103 ( log ,
L_7 ,
type , V_212 ) ;
return - V_192 ;
}
if ( F_110 ( V_206 ) != V_211 [ type ] [ V_210 ] ) {
F_103 ( log ,
L_8 ,
type , F_110 ( V_206 ) ,
V_211 [ type ] [ V_210 ] ) ;
return - V_192 ;
}
switch ( type ) {
case V_213 :
case V_214 :
if ( V_64 -> V_181 ) {
F_103 ( log ,
L_9
) ;
return - V_224 ;
}
V_64 -> V_181 |= V_182 ;
V_64 -> V_181 |= ( ( type == V_213 )
? V_186 : V_187 ) ;
break;
case V_215 :
F_111 ( & V_64 -> V_155 . V_225 , V_206 ,
sizeof( V_64 -> V_155 . V_225 ) ) ;
V_64 -> V_155 . V_169 |= V_170 ;
break;
case V_218 :
V_208 = true ;
F_111 ( & V_64 -> V_155 . V_226 , V_206 ,
sizeof( V_64 -> V_155 . V_226 ) ) ;
V_64 -> V_155 . V_169 |= V_170 ;
break;
case V_219 :
V_64 -> V_155 . V_227 . V_43 = F_9 ( F_112 ( V_206 ) ) ;
V_64 -> V_155 . V_169 |= V_228 ;
break;
case V_220 :
V_209 = true ;
V_64 -> V_155 . V_229 . V_43 = F_9 ( F_112 ( V_206 ) ) ;
V_64 -> V_155 . V_169 |= V_228 ;
break;
case V_221 :
V_64 -> V_155 . V_169 |= V_230 ;
break;
case V_222 :
V_64 -> V_155 . V_169 |= V_231 ;
break;
case V_223 :
V_64 -> V_155 . V_169 |= V_232 ;
break;
default:
F_103 ( log , L_10 , type ) ;
return - V_192 ;
}
}
if ( V_207 > 0 ) {
F_103 ( log , L_11 , V_207 ) ;
return - V_192 ;
}
if ( ! V_64 -> V_181 ) {
if ( V_64 -> V_155 . V_169 ) {
F_103 ( log ,
L_12
) ;
return - V_192 ;
}
V_64 -> V_181 = V_182 ;
} else if ( ! V_64 -> V_184 ) {
F_103 ( log ,
L_13
) ;
return - V_192 ;
}
if ( V_64 -> V_155 . V_169 & V_170 && ! V_208 ) {
memcpy ( & V_64 -> V_155 . V_226 , & V_64 -> V_155 . V_225 ,
sizeof( V_64 -> V_155 . V_226 ) ) ;
}
if ( V_64 -> V_155 . V_169 & V_228 &&
! V_209 ) {
V_64 -> V_155 . V_229 . V_43 = V_64 -> V_155 . V_227 . V_43 ;
}
return 0 ;
}
static int F_113 ( const struct V_204 * V_205 , struct V_63 * V_64 ,
const char * * V_103 , bool log )
{
struct V_204 * V_206 ;
int V_207 ;
F_108 (a, attr, rem) {
int type = F_109 ( V_206 ) ;
int V_233 ;
int V_234 ;
if ( type > V_235 ) {
F_103 ( log ,
L_14 ,
type , V_235 ) ;
return - V_192 ;
}
V_233 = V_236 [ type ] . V_233 ;
V_234 = V_236 [ type ] . V_234 ;
if ( F_110 ( V_206 ) < V_234 || F_110 ( V_206 ) > V_233 ) {
F_103 ( log ,
L_15 ,
type , F_110 ( V_206 ) , V_233 ) ;
return - V_192 ;
}
switch ( type ) {
case V_237 :
V_64 -> V_150 = true ;
case V_238 :
V_64 -> V_184 = true ;
break;
#ifdef V_79
case V_239 :
V_64 -> V_46 . V_48 = F_112 ( V_206 ) ;
break;
#endif
#ifdef V_24
case V_240 : {
struct V_241 * V_25 = F_114 ( V_206 ) ;
if ( ! V_25 -> V_89 ) {
F_103 ( log , L_16 ) ;
return - V_192 ;
}
V_64 -> V_25 = * V_25 ;
break;
}
#endif
#ifdef V_82
case V_242 : {
struct V_243 * V_27 = F_114 ( V_206 ) ;
if ( ! F_28 ( & V_27 -> V_89 ) ) {
F_103 ( log , L_17 ) ;
return - V_192 ;
}
V_64 -> V_27 = * V_27 ;
break;
}
#endif
case V_244 :
* V_103 = F_114 ( V_206 ) ;
if ( ! memchr ( * V_103 , '\0' , F_110 ( V_206 ) ) ) {
F_103 ( log , L_18 ) ;
return - V_192 ;
}
break;
#ifdef F_115
case V_245 : {
int V_100 = F_107 ( V_206 , V_64 , log ) ;
if ( V_100 )
return V_100 ;
break;
}
#endif
case V_246 :
V_64 -> V_194 = true ;
V_64 -> V_198 = F_116 ( V_206 ) ;
break;
default:
F_103 ( log , L_19 ,
type ) ;
return - V_192 ;
}
}
#ifdef V_24
if ( ! V_64 -> V_184 && V_64 -> V_25 . V_89 ) {
F_103 ( log ,
L_20 ) ;
return - V_192 ;
}
#endif
#ifdef V_82
if ( ! V_64 -> V_184 && F_28 ( & V_64 -> V_27 . V_89 ) ) {
F_103 ( log ,
L_21 ) ;
return - V_192 ;
}
#endif
if ( V_207 > 0 ) {
F_103 ( log , L_22 , V_207 ) ;
return - V_192 ;
}
return 0 ;
}
bool F_117 ( struct V_114 * V_114 , enum V_247 V_205 )
{
if ( V_205 == V_77 )
return true ;
if ( F_5 ( V_79 ) &&
V_205 == V_80 )
return true ;
if ( F_5 ( V_24 ) &&
V_205 == V_81 )
return true ;
if ( F_5 ( V_82 ) &&
V_205 == V_83 ) {
struct V_248 * V_248 = F_118 ( V_114 , V_249 ) ;
return V_248 -> V_250 ;
}
return false ;
}
int F_119 ( struct V_114 * V_114 , const struct V_204 * V_205 ,
const struct V_1 * V_2 ,
struct V_251 * * V_252 , bool log )
{
struct V_63 V_253 ;
const char * V_103 = NULL ;
T_1 V_151 ;
int V_100 ;
V_151 = F_1 ( V_2 ) ;
if ( V_151 == V_8 ) {
F_103 ( log , L_23 ) ;
return - V_192 ;
}
memset ( & V_253 , 0 , sizeof( V_253 ) ) ;
V_253 . V_151 = V_151 ;
F_120 ( & V_253 . V_46 , V_254 ,
V_255 , 0 ) ;
V_100 = F_113 ( V_205 , & V_253 , & V_103 , log ) ;
if ( V_100 )
return V_100 ;
V_253 . V_23 = F_121 ( V_114 , & V_253 . V_46 , V_202 ) ;
if ( ! V_253 . V_23 ) {
F_103 ( log , L_24 ) ;
return - V_203 ;
}
F_122 ( V_256 , & V_253 . V_23 -> V_69 ) ;
F_92 ( & V_253 . V_23 -> V_135 ) ;
if ( V_103 ) {
V_100 = F_101 ( & V_253 , V_103 , V_2 , log ) ;
if ( V_100 )
goto V_257;
}
V_100 = F_123 ( V_252 , V_258 , & V_253 ,
sizeof( V_253 ) , log ) ;
if ( V_100 )
goto V_257;
return 0 ;
V_257:
F_124 ( & V_253 ) ;
return V_100 ;
}
static bool F_125 ( const struct V_63 * V_64 ,
struct V_61 * V_62 )
{
struct V_204 * V_259 ;
V_259 = F_126 ( V_62 , V_245 ) ;
if ( ! V_259 )
return false ;
if ( V_64 -> V_181 & V_186 ) {
if ( F_127 ( V_62 , V_213 ) )
return false ;
} else if ( V_64 -> V_181 & V_187 ) {
if ( F_127 ( V_62 , V_214 ) )
return false ;
} else {
goto V_260;
}
if ( V_64 -> V_155 . V_169 & V_170 ) {
if ( F_5 ( V_163 ) &&
V_64 -> V_151 == V_5 ) {
if ( F_128 ( V_62 , V_215 ,
V_64 -> V_155 . V_225 . V_56 ) ||
( V_64 -> V_155 . V_226 . V_56
!= V_64 -> V_155 . V_225 . V_56 &&
( F_128 ( V_62 , V_218 ,
V_64 -> V_155 . V_226 . V_56 ) ) ) )
return false ;
} else if ( F_5 ( V_166 ) &&
V_64 -> V_151 == V_7 ) {
if ( F_129 ( V_62 , V_215 ,
& V_64 -> V_155 . V_225 . V_59 ) ||
( memcmp ( & V_64 -> V_155 . V_226 . V_59 ,
& V_64 -> V_155 . V_225 . V_59 ,
sizeof( V_64 -> V_155 . V_226 . V_59 ) ) &&
( F_129 ( V_62 , V_218 ,
& V_64 -> V_155 . V_226 . V_59 ) ) ) )
return false ;
} else {
return false ;
}
}
if ( V_64 -> V_155 . V_169 & V_228 &&
( F_20 ( V_62 , V_219 ,
F_2 ( V_64 -> V_155 . V_227 . V_43 ) ) ||
( V_64 -> V_155 . V_229 . V_43 != V_64 -> V_155 . V_227 . V_43 &&
F_20 ( V_62 , V_220 ,
F_2 ( V_64 -> V_155 . V_229 . V_43 ) ) ) ) )
return false ;
if ( V_64 -> V_155 . V_169 & V_230 &&
F_127 ( V_62 , V_221 ) )
return false ;
if ( V_64 -> V_155 . V_169 & V_231 &&
F_127 ( V_62 , V_222 ) )
return false ;
if ( V_64 -> V_155 . V_169 & V_232 &&
F_127 ( V_62 , V_223 ) )
return false ;
V_260:
F_130 ( V_62 , V_259 ) ;
return true ;
}
int F_131 ( const struct V_63 * V_253 ,
struct V_61 * V_62 )
{
struct V_204 * V_259 ;
V_259 = F_126 ( V_62 , V_258 ) ;
if ( ! V_259 )
return - V_78 ;
if ( V_253 -> V_184 && F_127 ( V_62 , V_253 -> V_150
? V_237
: V_238 ) )
return - V_78 ;
if ( F_5 ( V_79 ) &&
F_20 ( V_62 , V_239 , V_253 -> V_46 . V_48 ) )
return - V_78 ;
if ( F_5 ( V_24 ) && V_253 -> V_25 . V_89 &&
F_21 ( V_62 , V_240 , sizeof( V_253 -> V_25 ) ,
& V_253 -> V_25 ) )
return - V_78 ;
if ( F_5 ( V_82 ) &&
F_28 ( & V_253 -> V_27 . V_89 ) &&
F_21 ( V_62 , V_242 , sizeof( V_253 -> V_27 ) ,
& V_253 -> V_27 ) )
return - V_78 ;
if ( V_253 -> V_103 ) {
if ( F_132 ( V_62 , V_244 ,
V_253 -> V_103 -> V_201 ) )
return - V_78 ;
}
if ( V_253 -> V_194 &&
F_19 ( V_62 , V_246 , V_253 -> V_198 ) )
return - V_78 ;
#ifdef F_115
if ( V_253 -> V_181 && ! F_125 ( V_253 , V_62 ) )
return - V_78 ;
#endif
F_130 ( V_62 , V_259 ) ;
return 0 ;
}
void F_133 ( const struct V_204 * V_206 )
{
struct V_63 * V_253 = F_114 ( V_206 ) ;
F_124 ( V_253 ) ;
}
static void F_124 ( struct V_63 * V_253 )
{
if ( V_253 -> V_103 )
F_105 ( V_253 -> V_103 ) ;
if ( V_253 -> V_23 )
F_134 ( V_253 -> V_23 ) ;
}
void F_135 ( struct V_114 * V_114 )
{
unsigned int V_261 = sizeof( struct V_26 ) * V_262 ;
struct V_248 * V_248 = F_118 ( V_114 , V_249 ) ;
if ( F_136 ( V_114 , V_261 - 1 ) ) {
V_248 -> V_250 = false ;
F_103 ( true , L_25 ) ;
} else {
V_248 -> V_250 = true ;
}
}
void F_137 ( struct V_114 * V_114 )
{
struct V_248 * V_248 = F_118 ( V_114 , V_249 ) ;
if ( V_248 -> V_250 )
F_138 ( V_114 ) ;
}
