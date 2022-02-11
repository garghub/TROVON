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
if ( V_29 ) {
T_4 V_30 = sizeof( V_29 -> V_31 ) ;
if ( V_30 > V_32 )
V_30 = V_32 ;
else if ( V_30 < V_32 )
memset ( V_27 , 0 , V_32 ) ;
memcpy ( V_27 , V_29 -> V_31 , V_30 ) ;
} else {
memset ( V_27 , 0 , V_32 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , T_2 V_33 ,
const struct V_34 * V_35 ,
const struct V_22 * V_23 )
{
V_2 -> V_23 . V_33 = V_33 ;
V_2 -> V_23 . V_35 = V_35 -> V_36 ;
V_2 -> V_23 . V_25 = F_4 ( V_23 ) ;
F_6 ( V_23 , & V_2 -> V_23 . V_27 ) ;
}
static void F_9 ( const struct V_37 * V_38 ,
const struct V_39 * V_40 ,
struct V_1 * V_2 , bool V_41 ,
bool V_42 )
{
const struct V_34 * V_35 = & V_43 ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
T_2 V_33 = 0 ;
V_23 = F_10 ( V_38 , & V_10 ) ;
if ( V_23 ) {
V_33 = F_3 ( V_10 ) ;
if ( ! F_11 ( V_23 ) )
V_33 |= V_21 ;
if ( V_23 -> V_44 )
V_33 |= V_19 ;
if ( V_42 ) {
V_33 |= V_2 -> V_23 . V_33 & V_45 ;
} else {
if ( V_23 -> V_46 & V_47 )
V_33 |= V_48 ;
if ( V_23 -> V_46 & V_49 )
V_33 |= V_50 ;
}
V_35 = F_12 ( V_23 ) ;
} else if ( V_41 ) {
V_33 = V_12 | V_51 ;
if ( V_40 )
V_35 = & V_40 -> V_35 ;
}
F_8 ( V_2 , V_33 , V_35 , V_23 ) ;
}
void F_13 ( const struct V_37 * V_38 , struct V_1 * V_2 )
{
F_9 ( V_38 , NULL , V_2 , false , false ) ;
}
int F_14 ( const struct V_1 * V_2 , struct V_37 * V_38 )
{
if ( F_15 ( V_38 , V_52 , V_2 -> V_23 . V_33 ) )
return - V_53 ;
if ( F_5 ( V_54 ) &&
F_16 ( V_38 , V_55 , V_2 -> V_23 . V_35 ) )
return - V_53 ;
if ( F_5 ( V_24 ) &&
F_15 ( V_38 , V_56 , V_2 -> V_23 . V_25 ) )
return - V_53 ;
if ( F_5 ( V_57 ) &&
F_17 ( V_38 , V_58 , sizeof( V_2 -> V_23 . V_27 ) ,
& V_2 -> V_23 . V_27 ) )
return - V_53 ;
return 0 ;
}
static int F_18 ( struct V_37 * V_38 , struct V_1 * V_2 ,
T_3 V_59 , T_3 V_60 )
{
#if F_5 ( V_24 )
enum V_9 V_10 ;
struct V_22 * V_23 ;
T_3 V_61 ;
V_23 = F_10 ( V_38 , & V_10 ) ;
if ( ! V_23 )
return 0 ;
V_61 = V_59 | ( V_23 -> V_25 & ~ ( V_60 ) ) ;
if ( V_23 -> V_25 != V_61 ) {
V_23 -> V_25 = V_61 ;
F_19 ( V_62 , V_23 ) ;
V_2 -> V_23 . V_25 = V_61 ;
}
return 0 ;
#else
return - V_63 ;
#endif
}
static int F_20 ( struct V_37 * V_38 , struct V_1 * V_2 ,
const struct V_26 * V_27 ,
const struct V_26 * V_60 )
{
enum V_9 V_10 ;
struct V_28 * V_29 ;
struct V_22 * V_23 ;
int V_64 ;
V_23 = F_10 ( V_38 , & V_10 ) ;
if ( ! V_23 )
return 0 ;
V_29 = F_7 ( V_23 ) ;
if ( ! V_29 ) {
F_21 ( V_23 ) ;
V_29 = F_7 ( V_23 ) ;
}
if ( ! V_29 || sizeof( V_29 -> V_31 ) < V_32 )
return - V_65 ;
V_64 = F_22 ( V_23 , ( T_3 * ) V_27 , ( T_3 * ) V_60 ,
V_32 / sizeof( T_3 ) ) ;
if ( V_64 )
return V_64 ;
F_6 ( V_23 , & V_2 -> V_23 . V_27 ) ;
return 0 ;
}
static int F_23 ( struct V_37 * V_38 , T_1 V_66 )
{
const struct V_67 * V_68 ;
const struct V_69 * V_70 ;
enum V_9 V_10 ;
unsigned int V_71 ;
struct V_22 * V_23 ;
int V_64 ;
V_23 = F_10 ( V_38 , & V_10 ) ;
if ( ! V_23 || V_10 == V_14 )
return V_72 ;
V_70 = F_24 ( V_23 ) ;
if ( ! V_70 )
return V_72 ;
V_68 = F_25 ( V_70 -> V_68 ) ;
if ( ! V_68 )
return V_72 ;
switch ( V_66 ) {
case V_5 :
V_71 = F_26 ( V_38 ) ;
break;
case V_7 : {
T_2 V_73 = F_27 ( V_38 ) -> V_73 ;
T_5 V_74 ;
int V_75 ;
V_75 = F_28 ( V_38 , sizeof( struct V_76 ) , & V_73 ,
& V_74 ) ;
if ( V_75 < 0 || ( V_74 & F_29 ( ~ 0x7 ) ) != 0 ) {
F_30 ( L_1 ) ;
return V_72 ;
}
V_71 = V_75 ;
break;
}
default:
F_31 ( 1 , L_2 ) ;
return V_77 ;
}
V_64 = V_68 -> V_70 ( V_38 , V_71 , V_23 , V_10 ) ;
if ( V_64 != V_72 )
return V_64 ;
if ( F_32 ( V_78 , & V_23 -> V_46 ) &&
! F_33 ( V_38 , V_23 , V_10 , V_71 ) )
return V_77 ;
return V_72 ;
}
static int F_34 ( struct V_79 * V_79 , struct V_1 * V_2 ,
T_1 V_35 , struct V_37 * V_38 )
{
struct V_80 V_81 = * F_35 ( V_38 ) ;
int V_64 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) ) {
enum V_82 V_83 = V_84 + V_35 ;
memset ( F_36 ( V_38 ) , 0 , sizeof( struct V_85 ) ) ;
V_64 = F_37 ( V_79 , V_38 , V_83 ) ;
if ( V_64 )
return V_64 ;
V_81 . V_86 = F_36 ( V_38 ) -> V_87 ;
#if F_5 ( V_88 )
} else if ( V_2 -> V_3 . type == F_29 ( V_6 ) ) {
enum V_89 V_83 = V_90 + V_35 ;
F_38 ( V_38 ) ;
memset ( F_39 ( V_38 ) , 0 , sizeof( struct V_91 ) ) ;
V_64 = F_40 ( V_79 , V_38 , V_83 ) ;
if ( V_64 ) {
if ( V_64 != - V_92 )
F_41 ( V_38 ) ;
return V_64 ;
}
V_2 -> V_93 . V_66 = F_27 ( V_38 ) -> V_73 ;
V_81 . V_86 = F_39 ( V_38 ) -> V_87 ;
#endif
} else {
F_41 ( V_38 ) ;
return - V_94 ;
}
V_2 -> V_93 . V_95 = V_96 ;
F_42 ( V_38 ) ;
V_38 -> V_97 = 1 ;
* F_35 ( V_38 ) = V_81 ;
return 0 ;
}
static struct V_98 *
F_43 ( struct V_79 * V_79 , const struct V_34 * V_35 ,
T_1 V_66 , const struct V_37 * V_38 )
{
struct V_99 V_100 ;
if ( ! F_44 ( V_38 , F_45 ( V_38 ) , V_66 , V_79 , & V_100 ) )
return NULL ;
return F_46 ( V_79 , V_35 , & V_100 ) ;
}
static enum V_9
F_47 ( const struct V_101 * V_102 )
{
const struct V_22 * V_23 = F_48 ( V_102 ) ;
if ( F_49 ( V_102 ) == V_103 )
return V_13 ;
if ( F_32 ( V_104 , & V_23 -> V_46 ) )
return V_16 ;
if ( F_32 ( V_105 , & V_23 -> V_46 ) )
return V_18 ;
return V_20 ;
}
static struct V_22 *
F_50 ( struct V_79 * V_79 , const struct V_34 * V_35 ,
T_2 V_106 , struct V_37 * V_38 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_99 V_100 ;
struct V_101 * V_102 ;
struct V_22 * V_23 ;
unsigned int V_111 ;
T_2 V_112 ;
V_108 = F_51 ( V_106 ) ;
if ( V_108 -> V_113 ( V_38 , F_45 ( V_38 ) , & V_111 ,
& V_112 ) <= 0 ) {
F_30 ( L_3 ) ;
return NULL ;
}
V_110 = F_52 ( V_106 , V_112 ) ;
if ( ! F_53 ( V_38 , F_45 ( V_38 ) , V_111 , V_106 ,
V_112 , V_79 , & V_100 , V_108 , V_110 ) ) {
F_30 ( L_4 ) ;
return NULL ;
}
V_102 = F_54 ( V_79 , V_35 , & V_100 ) ;
if ( ! V_102 )
return NULL ;
V_23 = F_48 ( V_102 ) ;
V_38 -> V_114 = & V_23 -> V_115 ;
V_38 -> V_116 = F_47 ( V_102 ) ;
return V_23 ;
}
static bool F_55 ( struct V_79 * V_79 ,
const struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
enum V_9 V_10 ;
struct V_22 * V_23 ;
V_23 = F_10 ( V_38 , & V_10 ) ;
if ( ! V_23 && V_2 -> V_23 . V_33 & V_12 &&
! ( V_2 -> V_23 . V_33 & V_51 ) &&
V_2 -> V_23 . V_35 == V_40 -> V_35 . V_36 )
V_23 = F_50 ( V_79 , & V_40 -> V_35 , V_40 -> V_117 , V_38 ) ;
if ( ! V_23 )
return false ;
if ( ! F_56 ( V_79 , F_57 ( & V_23 -> V_118 ) ) )
return false ;
if ( ! F_58 ( V_40 -> V_23 , F_12 ( V_23 ) ) )
return false ;
if ( V_40 -> V_68 ) {
struct V_69 * V_70 ;
V_70 = F_59 ( V_23 , V_119 ) ;
if ( V_70 && F_60 ( V_70 -> V_68 ) != V_40 -> V_68 )
return false ;
}
return true ;
}
static int F_61 ( struct V_37 * V_38 , struct V_22 * V_23 ,
enum V_9 V_10 ,
const struct V_120 * V_121 ,
enum V_122 V_123 )
{
int V_124 , V_125 , V_64 = V_72 ;
V_125 = F_45 ( V_38 ) ;
F_62 ( V_38 , V_125 ) ;
if ( V_123 == V_126 )
V_124 = V_127 ;
else
V_124 = V_128 ;
switch ( V_10 ) {
case V_18 :
case V_14 :
if ( F_5 ( V_129 ) &&
V_38 -> V_130 == F_29 ( V_4 ) &&
F_63 ( V_38 ) -> V_130 == V_131 ) {
if ( ! F_64 ( V_38 , V_23 , V_10 ,
V_124 ) )
V_64 = V_77 ;
goto V_132;
} else if ( F_5 ( V_133 ) &&
V_38 -> V_130 == F_29 ( V_6 ) ) {
T_5 V_74 ;
T_2 V_73 = F_27 ( V_38 ) -> V_73 ;
int V_134 = F_28 ( V_38 ,
sizeof( struct V_76 ) ,
& V_73 , & V_74 ) ;
if ( V_134 >= 0 && V_73 == V_135 ) {
if ( ! F_65 ( V_38 , V_23 ,
V_10 ,
V_124 ,
V_134 ) )
V_64 = V_77 ;
goto V_132;
}
}
case V_20 :
if ( ! F_66 ( V_23 , V_123 ) ) {
V_64 = ( V_121 && V_121 -> V_136 & V_137 )
? F_67 ( V_23 , V_121 , V_123 )
: F_68 ( V_23 , V_124 ) ;
if ( V_64 != V_72 )
goto V_132;
}
break;
case V_16 :
case V_13 :
break;
default:
V_64 = V_77 ;
goto V_132;
}
V_64 = F_69 ( V_23 , V_10 , V_124 , V_38 ) ;
V_132:
F_70 ( V_38 , V_125 ) ;
F_71 ( V_38 , V_38 -> V_138 , V_125 ) ;
return V_64 ;
}
static void F_72 ( struct V_1 * V_2 ,
const struct V_37 * V_38 ,
enum V_122 V_123 )
{
if ( V_123 == V_126 ) {
T_5 V_139 ;
V_2 -> V_23 . V_33 |= V_48 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) )
V_2 -> V_140 . V_141 . V_139 = F_63 ( V_38 ) -> V_142 ;
else if ( V_2 -> V_3 . type == F_29 ( V_6 ) )
memcpy ( & V_2 -> V_143 . V_141 . V_139 , & F_27 ( V_38 ) -> V_142 ,
sizeof( V_2 -> V_143 . V_141 . V_139 ) ) ;
else
return;
if ( V_2 -> V_93 . V_66 == V_144 )
V_139 = F_73 ( V_38 ) -> V_145 ;
else if ( V_2 -> V_93 . V_66 == V_146 )
V_139 = F_74 ( V_38 ) -> V_145 ;
else if ( V_2 -> V_93 . V_66 == V_147 )
V_139 = F_75 ( V_38 ) -> V_145 ;
else
return;
V_2 -> V_148 . V_139 = V_139 ;
} else {
T_5 V_149 ;
V_2 -> V_23 . V_33 |= V_50 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) )
V_2 -> V_140 . V_141 . V_149 = F_63 ( V_38 ) -> V_150 ;
else if ( V_2 -> V_3 . type == F_29 ( V_6 ) )
memcpy ( & V_2 -> V_143 . V_141 . V_149 , & F_27 ( V_38 ) -> V_150 ,
sizeof( V_2 -> V_143 . V_141 . V_149 ) ) ;
else
return;
if ( V_2 -> V_93 . V_66 == V_144 )
V_149 = F_73 ( V_38 ) -> V_151 ;
else if ( V_2 -> V_93 . V_66 == V_146 )
V_149 = F_74 ( V_38 ) -> V_151 ;
else if ( V_2 -> V_93 . V_66 == V_147 )
V_149 = F_75 ( V_38 ) -> V_151 ;
else
return;
V_2 -> V_148 . V_149 = V_149 ;
}
}
static int F_76 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
enum V_122 V_123 ;
int V_64 ;
if ( F_77 ( V_23 ) ) {
return V_72 ;
}
if ( ! F_11 ( V_23 ) && ! F_78 ( V_23 ) )
return V_72 ;
if ( V_40 -> V_152 & V_153 && V_10 != V_20 &&
V_23 -> V_46 & V_154 &&
( V_10 != V_18 || V_40 -> V_155 ) ) {
if ( F_79 ( V_10 ) == V_103 )
V_123 = V_23 -> V_46 & V_47
? V_156 : V_126 ;
else
V_123 = V_23 -> V_46 & V_47
? V_126 : V_156 ;
} else if ( V_40 -> V_152 & V_157 ) {
V_123 = V_126 ;
} else if ( V_40 -> V_152 & V_158 ) {
V_123 = V_156 ;
} else {
return V_72 ;
}
V_64 = F_61 ( V_38 , V_23 , V_10 , & V_40 -> V_121 , V_123 ) ;
if ( V_64 == V_72 )
F_72 ( V_2 , V_38 , V_123 ) ;
return V_64 ;
}
static int F_76 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
return V_72 ;
}
static int F_80 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
bool V_159 = F_55 ( V_79 , V_2 , V_40 , V_38 ) ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
if ( ! V_159 ) {
struct V_22 * V_160 = V_40 -> V_23 ;
int V_64 ;
if ( V_160 ) {
if ( V_38 -> V_114 )
F_81 ( V_38 -> V_114 ) ;
F_82 ( & V_160 -> V_115 ) ;
V_38 -> V_114 = & V_160 -> V_115 ;
V_38 -> V_116 = V_20 ;
}
V_64 = F_83 ( V_79 , V_40 -> V_117 ,
V_161 , V_38 ) ;
if ( V_64 != V_72 )
return - V_162 ;
V_2 -> V_23 . V_33 = 0 ;
F_9 ( V_38 , V_40 , V_2 , true , true ) ;
}
V_23 = F_10 ( V_38 , & V_10 ) ;
if ( V_23 ) {
if ( V_40 -> V_152 && ! ( V_2 -> V_23 . V_33 & V_45 ) &&
( F_11 ( V_23 ) || V_40 -> V_155 ) &&
F_76 ( V_79 , V_2 , V_40 , V_38 , V_23 , V_10 ) != V_72 ) {
return - V_163 ;
}
if ( ! F_11 ( V_23 ) && V_40 -> V_155 &&
V_40 -> V_68 && ! F_24 ( V_23 ) ) {
int V_64 = F_84 ( V_23 , V_40 -> V_23 ,
V_164 ) ;
if ( V_64 )
return V_64 ;
}
if ( ( F_11 ( V_23 ) ? ! V_159 : V_40 -> V_155 ) &&
F_23 ( V_38 , V_40 -> V_117 ) != V_72 ) {
return - V_163 ;
}
}
return 0 ;
}
static int F_85 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
struct V_98 * exp ;
exp = F_43 ( V_79 , & V_40 -> V_35 , V_40 -> V_117 , V_38 ) ;
if ( exp ) {
T_2 V_33 ;
V_33 = V_12 | V_21 | V_19 ;
F_8 ( V_2 , V_33 , & V_40 -> V_35 , exp -> V_44 ) ;
} else {
struct V_22 * V_23 ;
int V_64 ;
V_64 = F_80 ( V_79 , V_2 , V_40 , V_38 ) ;
if ( V_64 )
return V_64 ;
V_23 = (struct V_22 * ) V_38 -> V_114 ;
if ( V_23 )
F_86 ( V_23 ) ;
}
return 0 ;
}
static bool F_87 ( const struct V_26 * V_27 )
{
T_4 V_165 ;
for ( V_165 = 0 ; V_165 < sizeof( * V_27 ) ; V_165 ++ )
if ( V_27 -> V_166 [ V_165 ] )
return true ;
return false ;
}
static int F_88 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
int V_64 ;
V_64 = F_80 ( V_79 , V_2 , V_40 , V_38 ) ;
if ( V_64 )
return V_64 ;
if ( V_40 -> V_25 . V_60 ) {
V_64 = F_18 ( V_38 , V_2 , V_40 -> V_25 . V_167 ,
V_40 -> V_25 . V_60 ) ;
if ( V_64 )
return V_64 ;
}
if ( F_87 ( & V_40 -> V_27 . V_60 ) ) {
V_64 = F_20 ( V_38 , V_2 , & V_40 -> V_27 . V_167 ,
& V_40 -> V_27 . V_60 ) ;
if ( V_64 )
return V_64 ;
}
if ( F_89 ( V_38 ) != V_72 )
return - V_163 ;
return 0 ;
}
int F_90 ( struct V_79 * V_79 , struct V_37 * V_38 ,
struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
int V_168 ;
int V_64 ;
V_168 = F_45 ( V_38 ) ;
F_62 ( V_38 , V_168 ) ;
if ( V_2 -> V_93 . V_95 != V_96 ) {
V_64 = F_34 ( V_79 , V_2 , V_40 -> V_35 . V_36 , V_38 ) ;
if ( V_64 )
return V_64 ;
}
if ( V_40 -> V_155 )
V_64 = F_88 ( V_79 , V_2 , V_40 , V_38 ) ;
else
V_64 = F_85 ( V_79 , V_2 , V_40 , V_38 ) ;
F_70 ( V_38 , V_168 ) ;
F_71 ( V_38 , V_38 -> V_138 , V_168 ) ;
if ( V_64 )
F_41 ( V_38 ) ;
return V_64 ;
}
static int F_91 ( struct V_39 * V_40 , const char * V_169 ,
const struct V_1 * V_2 , bool log )
{
struct V_67 * V_68 ;
struct V_69 * V_70 ;
V_68 = F_92 ( V_169 , V_40 -> V_117 ,
V_2 -> V_93 . V_66 ) ;
if ( ! V_68 ) {
F_93 ( log , L_5 , V_169 ) ;
return - V_163 ;
}
V_70 = F_94 ( V_40 -> V_23 , V_68 , V_170 ) ;
if ( ! V_70 ) {
F_95 ( V_68 -> V_171 ) ;
return - V_172 ;
}
F_96 ( V_70 -> V_68 , V_68 ) ;
V_40 -> V_68 = V_68 ;
return 0 ;
}
static int F_97 ( const struct V_173 * V_174 ,
struct V_39 * V_40 , bool log )
{
struct V_173 * V_175 ;
int V_176 ;
bool V_177 = false ;
bool V_178 = false ;
bool V_179 = ( V_40 -> V_117 == V_7 ) ;
F_98 (a, attr, rem) {
static const int V_180 [ V_181 + 1 ] [ 2 ] = {
[ V_182 ] = { 0 , 0 } ,
[ V_183 ] = { 0 , 0 } ,
[ V_184 ] = { sizeof( struct V_185 ) ,
sizeof(struct V_186 ) } ,
[ V_187 ] = { sizeof( struct V_185 ) ,
sizeof(struct V_186 ) } ,
[ V_188 ] = { sizeof( T_1 ) , sizeof( T_1 ) } ,
[ V_189 ] = { sizeof( T_1 ) , sizeof( T_1 ) } ,
[ V_190 ] = { 0 , 0 } ,
[ V_191 ] = { 0 , 0 } ,
[ V_192 ] = { 0 , 0 } ,
} ;
int type = F_99 ( V_175 ) ;
if ( type > V_181 ) {
F_93 ( log ,
L_6 ,
type , V_181 ) ;
return - V_163 ;
}
if ( F_100 ( V_175 ) != V_180 [ type ] [ V_179 ] ) {
F_93 ( log ,
L_7 ,
type , F_100 ( V_175 ) ,
V_180 [ type ] [ V_179 ] ) ;
return - V_163 ;
}
switch ( type ) {
case V_182 :
case V_183 :
if ( V_40 -> V_152 ) {
F_93 ( log ,
L_8
) ;
return - V_193 ;
}
V_40 -> V_152 |= V_153 ;
V_40 -> V_152 |= ( ( type == V_182 )
? V_157 : V_158 ) ;
break;
case V_184 :
F_101 ( & V_40 -> V_121 . V_194 , V_175 ,
sizeof( V_40 -> V_121 . V_194 ) ) ;
V_40 -> V_121 . V_136 |= V_137 ;
break;
case V_187 :
V_177 = true ;
F_101 ( & V_40 -> V_121 . V_195 , V_175 ,
sizeof( V_40 -> V_121 . V_195 ) ) ;
V_40 -> V_121 . V_136 |= V_137 ;
break;
case V_188 :
V_40 -> V_121 . V_196 . V_197 = F_29 ( F_102 ( V_175 ) ) ;
V_40 -> V_121 . V_136 |= V_198 ;
break;
case V_189 :
V_178 = true ;
V_40 -> V_121 . V_199 . V_197 = F_29 ( F_102 ( V_175 ) ) ;
V_40 -> V_121 . V_136 |= V_198 ;
break;
case V_190 :
V_40 -> V_121 . V_136 |= V_200 ;
break;
case V_191 :
V_40 -> V_121 . V_136 |= V_201 ;
break;
case V_192 :
V_40 -> V_121 . V_136 |= V_202 ;
break;
default:
F_93 ( log , L_9 , type ) ;
return - V_163 ;
}
}
if ( V_176 > 0 ) {
F_93 ( log , L_10 , V_176 ) ;
return - V_163 ;
}
if ( ! V_40 -> V_152 ) {
if ( V_40 -> V_121 . V_136 ) {
F_93 ( log ,
L_11
) ;
return - V_163 ;
}
V_40 -> V_152 = V_153 ;
} else if ( ! V_40 -> V_155 ) {
F_93 ( log ,
L_12
) ;
return - V_163 ;
}
if ( V_40 -> V_121 . V_136 & V_137 && ! V_177 ) {
memcpy ( & V_40 -> V_121 . V_195 , & V_40 -> V_121 . V_194 ,
sizeof( V_40 -> V_121 . V_195 ) ) ;
}
if ( V_40 -> V_121 . V_136 & V_198 &&
! V_178 ) {
V_40 -> V_121 . V_199 . V_197 = V_40 -> V_121 . V_196 . V_197 ;
}
return 0 ;
}
static int F_103 ( const struct V_173 * V_174 , struct V_39 * V_40 ,
const char * * V_68 , bool log )
{
struct V_173 * V_175 ;
int V_176 ;
F_98 (a, attr, rem) {
int type = F_99 ( V_175 ) ;
int V_203 = V_204 [ type ] . V_203 ;
int V_205 = V_204 [ type ] . V_205 ;
if ( type > V_206 ) {
F_93 ( log ,
L_13 ,
type , V_206 ) ;
return - V_163 ;
}
if ( F_100 ( V_175 ) < V_205 || F_100 ( V_175 ) > V_203 ) {
F_93 ( log ,
L_14 ,
type , F_100 ( V_175 ) , V_203 ) ;
return - V_163 ;
}
switch ( type ) {
case V_207 :
V_40 -> V_155 = true ;
break;
#ifdef V_54
case V_208 :
V_40 -> V_35 . V_36 = F_102 ( V_175 ) ;
break;
#endif
#ifdef V_24
case V_209 : {
struct V_210 * V_25 = F_104 ( V_175 ) ;
if ( ! V_25 -> V_60 ) {
F_93 ( log , L_15 ) ;
return - V_163 ;
}
V_40 -> V_25 = * V_25 ;
break;
}
#endif
#ifdef V_57
case V_211 : {
struct V_212 * V_27 = F_104 ( V_175 ) ;
if ( ! F_87 ( & V_27 -> V_60 ) ) {
F_93 ( log , L_16 ) ;
return - V_163 ;
}
V_40 -> V_27 = * V_27 ;
break;
}
#endif
case V_213 :
* V_68 = F_104 ( V_175 ) ;
if ( ! memchr ( * V_68 , '\0' , F_100 ( V_175 ) ) ) {
F_93 ( log , L_17 ) ;
return - V_163 ;
}
break;
#ifdef F_105
case V_214 : {
int V_64 = F_97 ( V_175 , V_40 , log ) ;
if ( V_64 )
return V_64 ;
break;
}
#endif
default:
F_93 ( log , L_18 ,
type ) ;
return - V_163 ;
}
}
#ifdef V_24
if ( ! V_40 -> V_155 && V_40 -> V_25 . V_60 ) {
F_93 ( log ,
L_19 ) ;
return - V_163 ;
}
#endif
#ifdef V_57
if ( ! V_40 -> V_155 && F_87 ( & V_40 -> V_27 . V_60 ) ) {
F_93 ( log ,
L_20 ) ;
return - V_163 ;
}
#endif
if ( V_176 > 0 ) {
F_93 ( log , L_21 , V_176 ) ;
return - V_163 ;
}
return 0 ;
}
bool F_106 ( struct V_79 * V_79 , enum V_215 V_174 )
{
if ( V_174 == V_52 )
return true ;
if ( F_5 ( V_54 ) &&
V_174 == V_55 )
return true ;
if ( F_5 ( V_24 ) &&
V_174 == V_56 )
return true ;
if ( F_5 ( V_57 ) &&
V_174 == V_58 ) {
struct V_216 * V_216 = F_107 ( V_79 , V_217 ) ;
return V_216 -> V_218 ;
}
return false ;
}
int F_108 ( struct V_79 * V_79 , const struct V_173 * V_174 ,
const struct V_1 * V_2 ,
struct V_219 * * V_220 , bool log )
{
struct V_39 V_221 ;
const char * V_68 = NULL ;
T_1 V_117 ;
int V_64 ;
V_117 = F_1 ( V_2 ) ;
if ( V_117 == V_8 ) {
F_93 ( log , L_22 ) ;
return - V_163 ;
}
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_221 . V_117 = V_117 ;
F_109 ( & V_221 . V_35 , V_222 ,
V_223 , 0 ) ;
V_64 = F_103 ( V_174 , & V_221 , & V_68 , log ) ;
if ( V_64 )
return V_64 ;
V_221 . V_23 = F_110 ( V_79 , & V_221 . V_35 , V_170 ) ;
if ( ! V_221 . V_23 ) {
F_93 ( log , L_23 ) ;
return - V_172 ;
}
F_111 ( V_224 , & V_221 . V_23 -> V_46 ) ;
F_82 ( & V_221 . V_23 -> V_115 ) ;
if ( V_68 ) {
V_64 = F_91 ( & V_221 , V_68 , V_2 , log ) ;
if ( V_64 )
goto V_225;
}
V_64 = F_112 ( V_220 , V_226 , & V_221 ,
sizeof( V_221 ) , log ) ;
if ( V_64 )
goto V_225;
return 0 ;
V_225:
F_113 ( & V_221 ) ;
return V_64 ;
}
static bool F_114 ( const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
struct V_173 * V_227 ;
V_227 = F_115 ( V_38 , V_214 ) ;
if ( ! V_227 )
return false ;
if ( V_40 -> V_152 & V_157 ) {
if ( F_116 ( V_38 , V_182 ) )
return false ;
} else if ( V_40 -> V_152 & V_158 ) {
if ( F_116 ( V_38 , V_183 ) )
return false ;
} else {
goto V_228;
}
if ( V_40 -> V_121 . V_136 & V_137 ) {
if ( F_5 ( V_129 ) &&
V_40 -> V_117 == V_5 ) {
if ( F_117 ( V_38 , V_184 ,
V_40 -> V_121 . V_194 . V_93 ) ||
( V_40 -> V_121 . V_195 . V_93
!= V_40 -> V_121 . V_194 . V_93 &&
( F_117 ( V_38 , V_187 ,
V_40 -> V_121 . V_195 . V_93 ) ) ) )
return false ;
} else if ( F_5 ( V_133 ) &&
V_40 -> V_117 == V_7 ) {
if ( F_118 ( V_38 , V_184 ,
& V_40 -> V_121 . V_194 . V_229 ) ||
( memcmp ( & V_40 -> V_121 . V_195 . V_229 ,
& V_40 -> V_121 . V_194 . V_229 ,
sizeof( V_40 -> V_121 . V_195 . V_229 ) ) &&
( F_118 ( V_38 , V_187 ,
& V_40 -> V_121 . V_195 . V_229 ) ) ) )
return false ;
} else {
return false ;
}
}
if ( V_40 -> V_121 . V_136 & V_198 &&
( F_16 ( V_38 , V_188 ,
F_2 ( V_40 -> V_121 . V_196 . V_197 ) ) ||
( V_40 -> V_121 . V_199 . V_197 != V_40 -> V_121 . V_196 . V_197 &&
F_16 ( V_38 , V_189 ,
F_2 ( V_40 -> V_121 . V_199 . V_197 ) ) ) ) )
return false ;
if ( V_40 -> V_121 . V_136 & V_200 &&
F_116 ( V_38 , V_190 ) )
return false ;
if ( V_40 -> V_121 . V_136 & V_201 &&
F_116 ( V_38 , V_191 ) )
return false ;
if ( V_40 -> V_121 . V_136 & V_202 &&
F_116 ( V_38 , V_192 ) )
return false ;
V_228:
F_119 ( V_38 , V_227 ) ;
return true ;
}
int F_120 ( const struct V_39 * V_221 ,
struct V_37 * V_38 )
{
struct V_173 * V_227 ;
V_227 = F_115 ( V_38 , V_226 ) ;
if ( ! V_227 )
return - V_53 ;
if ( V_221 -> V_155 && F_116 ( V_38 , V_207 ) )
return - V_53 ;
if ( F_5 ( V_54 ) &&
F_16 ( V_38 , V_208 , V_221 -> V_35 . V_36 ) )
return - V_53 ;
if ( F_5 ( V_24 ) && V_221 -> V_25 . V_60 &&
F_17 ( V_38 , V_209 , sizeof( V_221 -> V_25 ) ,
& V_221 -> V_25 ) )
return - V_53 ;
if ( F_5 ( V_57 ) &&
F_87 ( & V_221 -> V_27 . V_60 ) &&
F_17 ( V_38 , V_211 , sizeof( V_221 -> V_27 ) ,
& V_221 -> V_27 ) )
return - V_53 ;
if ( V_221 -> V_68 ) {
if ( F_121 ( V_38 , V_213 ,
V_221 -> V_68 -> V_169 ) )
return - V_53 ;
}
#ifdef F_105
if ( V_221 -> V_152 && ! F_114 ( V_221 , V_38 ) )
return - V_53 ;
#endif
F_119 ( V_38 , V_227 ) ;
return 0 ;
}
void F_122 ( const struct V_173 * V_175 )
{
struct V_39 * V_221 = F_104 ( V_175 ) ;
F_113 ( V_221 ) ;
}
static void F_113 ( struct V_39 * V_221 )
{
if ( V_221 -> V_68 )
F_95 ( V_221 -> V_68 -> V_171 ) ;
if ( V_221 -> V_23 )
F_123 ( V_221 -> V_23 ) ;
}
void F_124 ( struct V_79 * V_79 )
{
unsigned int V_230 = sizeof( struct V_26 ) * V_231 ;
struct V_216 * V_216 = F_107 ( V_79 , V_217 ) ;
if ( F_125 ( V_79 , V_230 - 1 ) ) {
V_216 -> V_218 = false ;
F_93 ( true , L_24 ) ;
} else {
V_216 -> V_218 = true ;
}
}
void F_126 ( struct V_79 * V_79 )
{
struct V_216 * V_216 = F_107 ( V_79 , V_217 ) ;
if ( V_216 -> V_218 )
F_127 ( V_79 ) ;
}
