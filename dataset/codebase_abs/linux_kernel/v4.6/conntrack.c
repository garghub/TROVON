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
T_4 V_30 = V_29 -> V_31 * sizeof( long ) ;
if ( V_30 > V_32 )
V_30 = V_32 ;
else if ( V_30 < V_32 )
memset ( V_27 , 0 , V_32 ) ;
memcpy ( V_27 , V_29 -> V_33 , V_30 ) ;
} else {
memset ( V_27 , 0 , V_32 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , T_2 V_34 ,
const struct V_35 * V_36 ,
const struct V_22 * V_23 )
{
V_2 -> V_23 . V_34 = V_34 ;
V_2 -> V_23 . V_36 = V_36 -> V_37 ;
V_2 -> V_23 . V_25 = F_4 ( V_23 ) ;
F_6 ( V_23 , & V_2 -> V_23 . V_27 ) ;
}
static void F_9 ( const struct V_38 * V_39 ,
const struct V_40 * V_41 ,
struct V_1 * V_2 , bool V_42 ,
bool V_43 )
{
const struct V_35 * V_36 = & V_44 ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
T_2 V_34 = 0 ;
V_23 = F_10 ( V_39 , & V_10 ) ;
if ( V_23 ) {
V_34 = F_3 ( V_10 ) ;
if ( ! F_11 ( V_23 ) )
V_34 |= V_21 ;
if ( V_23 -> V_45 )
V_34 |= V_19 ;
if ( V_43 ) {
V_34 |= V_2 -> V_23 . V_34 & V_46 ;
} else {
if ( V_23 -> V_47 & V_48 )
V_34 |= V_49 ;
if ( V_23 -> V_47 & V_50 )
V_34 |= V_51 ;
}
V_36 = F_12 ( V_23 ) ;
} else if ( V_42 ) {
V_34 = V_12 | V_52 ;
if ( V_41 )
V_36 = & V_41 -> V_36 ;
}
F_8 ( V_2 , V_34 , V_36 , V_23 ) ;
}
void F_13 ( const struct V_38 * V_39 , struct V_1 * V_2 )
{
F_9 ( V_39 , NULL , V_2 , false , false ) ;
}
int F_14 ( const struct V_1 * V_2 , struct V_38 * V_39 )
{
if ( F_15 ( V_39 , V_53 , V_2 -> V_23 . V_34 ) )
return - V_54 ;
if ( F_5 ( V_55 ) &&
F_16 ( V_39 , V_56 , V_2 -> V_23 . V_36 ) )
return - V_54 ;
if ( F_5 ( V_24 ) &&
F_15 ( V_39 , V_57 , V_2 -> V_23 . V_25 ) )
return - V_54 ;
if ( F_5 ( V_58 ) &&
F_17 ( V_39 , V_59 , sizeof( V_2 -> V_23 . V_27 ) ,
& V_2 -> V_23 . V_27 ) )
return - V_54 ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 , struct V_1 * V_2 ,
T_3 V_60 , T_3 V_61 )
{
#if F_5 ( V_24 )
enum V_9 V_10 ;
struct V_22 * V_23 ;
T_3 V_62 ;
V_23 = F_10 ( V_39 , & V_10 ) ;
if ( ! V_23 )
return 0 ;
V_62 = V_60 | ( V_23 -> V_25 & ~ ( V_61 ) ) ;
if ( V_23 -> V_25 != V_62 ) {
V_23 -> V_25 = V_62 ;
F_19 ( V_63 , V_23 ) ;
V_2 -> V_23 . V_25 = V_62 ;
}
return 0 ;
#else
return - V_64 ;
#endif
}
static int F_20 ( struct V_38 * V_39 , struct V_1 * V_2 ,
const struct V_26 * V_27 ,
const struct V_26 * V_61 )
{
enum V_9 V_10 ;
struct V_28 * V_29 ;
struct V_22 * V_23 ;
int V_65 ;
V_23 = F_10 ( V_39 , & V_10 ) ;
if ( ! V_23 )
return 0 ;
V_29 = F_7 ( V_23 ) ;
if ( ! V_29 ) {
F_21 ( V_23 ) ;
V_29 = F_7 ( V_23 ) ;
}
if ( ! V_29 || V_29 -> V_31 * sizeof( long ) < V_32 )
return - V_66 ;
V_65 = F_22 ( V_23 , ( T_3 * ) V_27 , ( T_3 * ) V_61 ,
V_32 / sizeof( T_3 ) ) ;
if ( V_65 )
return V_65 ;
F_6 ( V_23 , & V_2 -> V_23 . V_27 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_39 , T_1 V_67 )
{
const struct V_68 * V_69 ;
const struct V_70 * V_71 ;
enum V_9 V_10 ;
unsigned int V_72 ;
struct V_22 * V_23 ;
int V_65 ;
V_23 = F_10 ( V_39 , & V_10 ) ;
if ( ! V_23 || V_10 == V_14 )
return V_73 ;
V_71 = F_24 ( V_23 ) ;
if ( ! V_71 )
return V_73 ;
V_69 = F_25 ( V_71 -> V_69 ) ;
if ( ! V_69 )
return V_73 ;
switch ( V_67 ) {
case V_5 :
V_72 = F_26 ( V_39 ) ;
break;
case V_7 : {
T_2 V_74 = F_27 ( V_39 ) -> V_74 ;
T_5 V_75 ;
int V_76 ;
V_76 = F_28 ( V_39 , sizeof( struct V_77 ) , & V_74 ,
& V_75 ) ;
if ( V_76 < 0 || ( V_75 & F_29 ( ~ 0x7 ) ) != 0 ) {
F_30 ( L_1 ) ;
return V_73 ;
}
V_72 = V_76 ;
break;
}
default:
F_31 ( 1 , L_2 ) ;
return V_78 ;
}
V_65 = V_69 -> V_71 ( V_39 , V_72 , V_23 , V_10 ) ;
if ( V_65 != V_73 )
return V_65 ;
if ( F_32 ( V_79 , & V_23 -> V_47 ) &&
! F_33 ( V_39 , V_23 , V_10 , V_72 ) )
return V_78 ;
return V_73 ;
}
static int F_34 ( struct V_80 * V_80 , struct V_1 * V_2 ,
T_1 V_36 , struct V_38 * V_39 )
{
struct V_81 V_82 = * F_35 ( V_39 ) ;
int V_65 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) ) {
enum V_83 V_84 = V_85 + V_36 ;
memset ( F_36 ( V_39 ) , 0 , sizeof( struct V_86 ) ) ;
V_65 = F_37 ( V_80 , V_39 , V_84 ) ;
if ( V_65 )
return V_65 ;
V_82 . V_87 = F_36 ( V_39 ) -> V_88 ;
#if F_5 ( V_89 )
} else if ( V_2 -> V_3 . type == F_29 ( V_6 ) ) {
enum V_90 V_84 = V_91 + V_36 ;
F_38 ( V_39 ) ;
memset ( F_39 ( V_39 ) , 0 , sizeof( struct V_92 ) ) ;
V_65 = F_40 ( V_80 , V_39 , V_84 ) ;
if ( V_65 )
return V_65 ;
V_2 -> V_93 . V_67 = F_27 ( V_39 ) -> V_74 ;
V_82 . V_87 = F_39 ( V_39 ) -> V_88 ;
#endif
} else {
F_41 ( V_39 ) ;
return - V_94 ;
}
V_2 -> V_93 . V_95 = V_96 ;
F_42 ( V_39 ) ;
V_39 -> V_97 = 1 ;
* F_35 ( V_39 ) = V_82 ;
return 0 ;
}
static struct V_98 *
F_43 ( struct V_80 * V_80 , const struct V_35 * V_36 ,
T_1 V_67 , const struct V_38 * V_39 )
{
struct V_99 V_100 ;
if ( ! F_44 ( V_39 , F_45 ( V_39 ) , V_67 , V_80 , & V_100 ) )
return NULL ;
return F_46 ( V_80 , V_36 , & V_100 ) ;
}
static enum V_9
F_47 ( const struct V_101 * V_102 )
{
const struct V_22 * V_23 = F_48 ( V_102 ) ;
if ( F_49 ( V_102 ) == V_103 )
return V_13 ;
if ( F_32 ( V_104 , & V_23 -> V_47 ) )
return V_16 ;
if ( F_32 ( V_105 , & V_23 -> V_47 ) )
return V_18 ;
return V_20 ;
}
static struct V_22 *
F_50 ( struct V_80 * V_80 , const struct V_35 * V_36 ,
T_2 V_106 , struct V_38 * V_39 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_99 V_100 ;
struct V_101 * V_102 ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
unsigned int V_111 ;
T_2 V_112 ;
V_108 = F_51 ( V_106 ) ;
if ( ! V_108 ) {
F_30 ( L_3 ) ;
return NULL ;
}
if ( V_108 -> V_113 ( V_39 , F_45 ( V_39 ) , & V_111 ,
& V_112 ) <= 0 ) {
F_30 ( L_4 ) ;
return NULL ;
}
V_110 = F_52 ( V_106 , V_112 ) ;
if ( ! V_110 ) {
F_30 ( L_5 ) ;
return NULL ;
}
if ( ! F_53 ( V_39 , F_45 ( V_39 ) , V_111 , V_106 ,
V_112 , V_80 , & V_100 , V_108 , V_110 ) ) {
F_30 ( L_6 ) ;
return NULL ;
}
V_102 = F_54 ( V_80 , V_36 , & V_100 ) ;
if ( ! V_102 )
return NULL ;
V_23 = F_48 ( V_102 ) ;
V_10 = F_47 ( V_102 ) ;
if ( V_10 == V_20 ) {
F_31 ( 1 , L_7 , V_23 ) ;
}
V_39 -> V_114 = & V_23 -> V_115 ;
V_39 -> V_116 = V_10 ;
return V_23 ;
}
static bool F_55 ( struct V_80 * V_80 ,
const struct V_1 * V_2 ,
const struct V_40 * V_41 ,
struct V_38 * V_39 )
{
enum V_9 V_10 ;
struct V_22 * V_23 ;
V_23 = F_10 ( V_39 , & V_10 ) ;
if ( ! V_23 && V_2 -> V_23 . V_34 & V_12 &&
! ( V_2 -> V_23 . V_34 & V_52 ) &&
V_2 -> V_23 . V_36 == V_41 -> V_36 . V_37 )
V_23 = F_50 ( V_80 , & V_41 -> V_36 , V_41 -> V_117 , V_39 ) ;
if ( ! V_23 )
return false ;
if ( ! F_56 ( V_80 , F_57 ( & V_23 -> V_118 ) ) )
return false ;
if ( ! F_58 ( V_41 -> V_23 , F_12 ( V_23 ) ) )
return false ;
if ( V_41 -> V_69 ) {
struct V_70 * V_71 ;
V_71 = F_59 ( V_23 , V_119 ) ;
if ( V_71 && F_60 ( V_71 -> V_69 ) != V_41 -> V_69 )
return false ;
}
return true ;
}
static int F_61 ( struct V_38 * V_39 , struct V_22 * V_23 ,
enum V_9 V_10 ,
const struct V_120 * V_121 ,
enum V_122 V_123 )
{
int V_124 , V_125 , V_65 = V_73 ;
V_125 = F_45 ( V_39 ) ;
F_62 ( V_39 , V_125 ) ;
if ( V_123 == V_126 )
V_124 = V_127 ;
else
V_124 = V_128 ;
switch ( V_10 ) {
case V_18 :
case V_14 :
if ( F_5 ( V_129 ) &&
V_39 -> V_130 == F_29 ( V_4 ) &&
F_63 ( V_39 ) -> V_130 == V_131 ) {
if ( ! F_64 ( V_39 , V_23 , V_10 ,
V_124 ) )
V_65 = V_78 ;
goto V_132;
} else if ( F_5 ( V_133 ) &&
V_39 -> V_130 == F_29 ( V_6 ) ) {
T_5 V_75 ;
T_2 V_74 = F_27 ( V_39 ) -> V_74 ;
int V_134 = F_28 ( V_39 ,
sizeof( struct V_77 ) ,
& V_74 , & V_75 ) ;
if ( V_134 >= 0 && V_74 == V_135 ) {
if ( ! F_65 ( V_39 , V_23 ,
V_10 ,
V_124 ,
V_134 ) )
V_65 = V_78 ;
goto V_132;
}
}
case V_20 :
if ( ! F_66 ( V_23 , V_123 ) ) {
V_65 = ( V_121 && V_121 -> V_136 & V_137 )
? F_67 ( V_23 , V_121 , V_123 )
: F_68 ( V_23 , V_124 ) ;
if ( V_65 != V_73 )
goto V_132;
}
break;
case V_16 :
case V_13 :
break;
default:
V_65 = V_78 ;
goto V_132;
}
V_65 = F_69 ( V_23 , V_10 , V_124 , V_39 ) ;
V_132:
F_70 ( V_39 , V_125 ) ;
return V_65 ;
}
static void F_71 ( struct V_1 * V_2 ,
const struct V_38 * V_39 ,
enum V_122 V_123 )
{
if ( V_123 == V_126 ) {
T_5 V_138 ;
V_2 -> V_23 . V_34 |= V_49 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) )
V_2 -> V_139 . V_140 . V_138 = F_63 ( V_39 ) -> V_141 ;
else if ( V_2 -> V_3 . type == F_29 ( V_6 ) )
memcpy ( & V_2 -> V_142 . V_140 . V_138 , & F_27 ( V_39 ) -> V_141 ,
sizeof( V_2 -> V_142 . V_140 . V_138 ) ) ;
else
return;
if ( V_2 -> V_93 . V_67 == V_143 )
V_138 = F_72 ( V_39 ) -> V_144 ;
else if ( V_2 -> V_93 . V_67 == V_145 )
V_138 = F_73 ( V_39 ) -> V_144 ;
else if ( V_2 -> V_93 . V_67 == V_146 )
V_138 = F_74 ( V_39 ) -> V_144 ;
else
return;
V_2 -> V_147 . V_138 = V_138 ;
} else {
T_5 V_148 ;
V_2 -> V_23 . V_34 |= V_51 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) )
V_2 -> V_139 . V_140 . V_148 = F_63 ( V_39 ) -> V_149 ;
else if ( V_2 -> V_3 . type == F_29 ( V_6 ) )
memcpy ( & V_2 -> V_142 . V_140 . V_148 , & F_27 ( V_39 ) -> V_149 ,
sizeof( V_2 -> V_142 . V_140 . V_148 ) ) ;
else
return;
if ( V_2 -> V_93 . V_67 == V_143 )
V_148 = F_72 ( V_39 ) -> V_150 ;
else if ( V_2 -> V_93 . V_67 == V_145 )
V_148 = F_73 ( V_39 ) -> V_150 ;
else if ( V_2 -> V_93 . V_67 == V_146 )
V_148 = F_74 ( V_39 ) -> V_150 ;
else
return;
V_2 -> V_147 . V_148 = V_148 ;
}
}
static int F_75 ( struct V_80 * V_80 , struct V_1 * V_2 ,
const struct V_40 * V_41 ,
struct V_38 * V_39 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
enum V_122 V_123 ;
int V_65 ;
if ( F_76 ( V_23 ) ) {
return V_73 ;
}
if ( ! F_11 ( V_23 ) && ! F_77 ( V_23 ) )
return V_73 ;
if ( V_41 -> V_151 & V_152 && V_10 != V_20 &&
V_23 -> V_47 & V_153 &&
( V_10 != V_18 || V_41 -> V_154 ) ) {
if ( F_78 ( V_10 ) == V_103 )
V_123 = V_23 -> V_47 & V_48
? V_155 : V_126 ;
else
V_123 = V_23 -> V_47 & V_48
? V_126 : V_155 ;
} else if ( V_41 -> V_151 & V_156 ) {
V_123 = V_126 ;
} else if ( V_41 -> V_151 & V_157 ) {
V_123 = V_155 ;
} else {
return V_73 ;
}
V_65 = F_61 ( V_39 , V_23 , V_10 , & V_41 -> V_121 , V_123 ) ;
if ( V_65 == V_73 )
F_71 ( V_2 , V_39 , V_123 ) ;
return V_65 ;
}
static int F_75 ( struct V_80 * V_80 , struct V_1 * V_2 ,
const struct V_40 * V_41 ,
struct V_38 * V_39 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
return V_73 ;
}
static int F_79 ( struct V_80 * V_80 , struct V_1 * V_2 ,
const struct V_40 * V_41 ,
struct V_38 * V_39 )
{
bool V_158 = F_55 ( V_80 , V_2 , V_41 , V_39 ) ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
if ( ! V_158 ) {
struct V_22 * V_159 = V_41 -> V_23 ;
int V_65 ;
if ( V_159 ) {
if ( V_39 -> V_114 )
F_80 ( V_39 -> V_114 ) ;
F_81 ( & V_159 -> V_115 ) ;
V_39 -> V_114 = & V_159 -> V_115 ;
V_39 -> V_116 = V_20 ;
}
do {
V_65 = F_82 ( V_80 , V_41 -> V_117 ,
V_160 , V_39 ) ;
} while ( V_65 == V_161 );
if ( V_65 != V_73 )
return - V_162 ;
V_2 -> V_23 . V_34 = 0 ;
F_9 ( V_39 , V_41 , V_2 , true , true ) ;
}
V_23 = F_10 ( V_39 , & V_10 ) ;
if ( V_23 ) {
if ( V_41 -> V_151 && ! ( V_2 -> V_23 . V_34 & V_46 ) &&
( F_11 ( V_23 ) || V_41 -> V_154 ) &&
F_75 ( V_80 , V_2 , V_41 , V_39 , V_23 , V_10 ) != V_73 ) {
return - V_163 ;
}
if ( ! F_11 ( V_23 ) && V_41 -> V_154 &&
V_41 -> V_69 && ! F_24 ( V_23 ) ) {
int V_65 = F_83 ( V_23 , V_41 -> V_23 ,
V_164 ) ;
if ( V_65 )
return V_65 ;
}
if ( ( F_11 ( V_23 ) ? ! V_158 : V_41 -> V_154 ) &&
F_23 ( V_39 , V_41 -> V_117 ) != V_73 ) {
return - V_163 ;
}
}
return 0 ;
}
static int F_84 ( struct V_80 * V_80 , struct V_1 * V_2 ,
const struct V_40 * V_41 ,
struct V_38 * V_39 )
{
struct V_98 * exp ;
exp = F_43 ( V_80 , & V_41 -> V_36 , V_41 -> V_117 , V_39 ) ;
if ( exp ) {
T_2 V_34 ;
V_34 = V_12 | V_21 | V_19 ;
F_8 ( V_2 , V_34 , & V_41 -> V_36 , exp -> V_45 ) ;
} else
return F_79 ( V_80 , V_2 , V_41 , V_39 ) ;
return 0 ;
}
static int F_85 ( struct V_80 * V_80 , struct V_1 * V_2 ,
const struct V_40 * V_41 ,
struct V_38 * V_39 )
{
int V_65 ;
V_65 = F_79 ( V_80 , V_2 , V_41 , V_39 ) ;
if ( V_65 )
return V_65 ;
if ( F_86 ( V_39 ) != V_73 )
return - V_163 ;
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
int F_88 ( struct V_80 * V_80 , struct V_38 * V_39 ,
struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
int V_167 ;
int V_65 ;
V_167 = F_45 ( V_39 ) ;
F_62 ( V_39 , V_167 ) ;
if ( V_2 -> V_93 . V_95 != V_96 ) {
V_65 = F_34 ( V_80 , V_2 , V_41 -> V_36 . V_37 , V_39 ) ;
if ( V_65 )
return V_65 ;
}
if ( V_41 -> V_154 )
V_65 = F_85 ( V_80 , V_2 , V_41 , V_39 ) ;
else
V_65 = F_84 ( V_80 , V_2 , V_41 , V_39 ) ;
if ( V_65 )
goto V_65;
if ( V_41 -> V_25 . V_61 ) {
V_65 = F_18 ( V_39 , V_2 , V_41 -> V_25 . V_168 ,
V_41 -> V_25 . V_61 ) ;
if ( V_65 )
goto V_65;
}
if ( F_87 ( & V_41 -> V_27 . V_61 ) )
V_65 = F_20 ( V_39 , V_2 , & V_41 -> V_27 . V_168 ,
& V_41 -> V_27 . V_61 ) ;
V_65:
F_70 ( V_39 , V_167 ) ;
if ( V_65 )
F_41 ( V_39 ) ;
return V_65 ;
}
static int F_89 ( struct V_40 * V_41 , const char * V_169 ,
const struct V_1 * V_2 , bool log )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
V_69 = F_90 ( V_169 , V_41 -> V_117 ,
V_2 -> V_93 . V_67 ) ;
if ( ! V_69 ) {
F_91 ( log , L_8 , V_169 ) ;
return - V_163 ;
}
V_71 = F_92 ( V_41 -> V_23 , V_69 , V_170 ) ;
if ( ! V_71 ) {
F_93 ( V_69 -> V_171 ) ;
return - V_172 ;
}
F_94 ( V_71 -> V_69 , V_69 ) ;
V_41 -> V_69 = V_69 ;
return 0 ;
}
static int F_95 ( const struct V_173 * V_174 ,
struct V_40 * V_41 , bool log )
{
struct V_173 * V_175 ;
int V_176 ;
bool V_177 = false ;
bool V_178 = false ;
bool V_179 = ( V_41 -> V_117 == V_7 ) ;
F_96 (a, attr, rem) {
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
int type = F_97 ( V_175 ) ;
if ( type > V_181 ) {
F_91 ( log ,
L_9 ,
type , V_181 ) ;
return - V_163 ;
}
if ( F_98 ( V_175 ) != V_180 [ type ] [ V_179 ] ) {
F_91 ( log ,
L_10 ,
type , F_98 ( V_175 ) ,
V_180 [ type ] [ V_179 ] ) ;
return - V_163 ;
}
switch ( type ) {
case V_182 :
case V_183 :
if ( V_41 -> V_151 ) {
F_91 ( log ,
L_11
) ;
return - V_193 ;
}
V_41 -> V_151 |= V_152 ;
V_41 -> V_151 |= ( ( type == V_182 )
? V_156 : V_157 ) ;
break;
case V_184 :
F_99 ( & V_41 -> V_121 . V_194 , V_175 ,
sizeof( V_41 -> V_121 . V_194 ) ) ;
V_41 -> V_121 . V_136 |= V_137 ;
break;
case V_187 :
V_177 = true ;
F_99 ( & V_41 -> V_121 . V_195 , V_175 ,
sizeof( V_41 -> V_121 . V_195 ) ) ;
V_41 -> V_121 . V_136 |= V_137 ;
break;
case V_188 :
V_41 -> V_121 . V_196 . V_197 = F_29 ( F_100 ( V_175 ) ) ;
V_41 -> V_121 . V_136 |= V_198 ;
break;
case V_189 :
V_178 = true ;
V_41 -> V_121 . V_199 . V_197 = F_29 ( F_100 ( V_175 ) ) ;
V_41 -> V_121 . V_136 |= V_198 ;
break;
case V_190 :
V_41 -> V_121 . V_136 |= V_200 ;
break;
case V_191 :
V_41 -> V_121 . V_136 |= V_201 ;
break;
case V_192 :
V_41 -> V_121 . V_136 |= V_202 ;
break;
default:
F_91 ( log , L_12 , type ) ;
return - V_163 ;
}
}
if ( V_176 > 0 ) {
F_91 ( log , L_13 , V_176 ) ;
return - V_163 ;
}
if ( ! V_41 -> V_151 ) {
if ( V_41 -> V_121 . V_136 ) {
F_91 ( log ,
L_14
) ;
return - V_163 ;
}
V_41 -> V_151 = V_152 ;
} else if ( ! V_41 -> V_154 ) {
F_91 ( log ,
L_15
) ;
return - V_163 ;
}
if ( V_41 -> V_121 . V_136 & V_137 && ! V_177 ) {
memcpy ( & V_41 -> V_121 . V_195 , & V_41 -> V_121 . V_194 ,
sizeof( V_41 -> V_121 . V_195 ) ) ;
}
if ( V_41 -> V_121 . V_136 & V_198 &&
! V_178 ) {
V_41 -> V_121 . V_199 . V_197 = V_41 -> V_121 . V_196 . V_197 ;
}
return 0 ;
}
static int F_101 ( const struct V_173 * V_174 , struct V_40 * V_41 ,
const char * * V_69 , bool log )
{
struct V_173 * V_175 ;
int V_176 ;
F_96 (a, attr, rem) {
int type = F_97 ( V_175 ) ;
int V_203 = V_204 [ type ] . V_203 ;
int V_205 = V_204 [ type ] . V_205 ;
if ( type > V_206 ) {
F_91 ( log ,
L_16 ,
type , V_206 ) ;
return - V_163 ;
}
if ( F_98 ( V_175 ) < V_205 || F_98 ( V_175 ) > V_203 ) {
F_91 ( log ,
L_17 ,
type , F_98 ( V_175 ) , V_203 ) ;
return - V_163 ;
}
switch ( type ) {
case V_207 :
V_41 -> V_154 = true ;
break;
#ifdef V_55
case V_208 :
V_41 -> V_36 . V_37 = F_100 ( V_175 ) ;
break;
#endif
#ifdef V_24
case V_209 : {
struct V_210 * V_25 = F_102 ( V_175 ) ;
if ( ! V_25 -> V_61 ) {
F_91 ( log , L_18 ) ;
return - V_163 ;
}
V_41 -> V_25 = * V_25 ;
break;
}
#endif
#ifdef V_58
case V_211 : {
struct V_212 * V_27 = F_102 ( V_175 ) ;
if ( ! F_87 ( & V_27 -> V_61 ) ) {
F_91 ( log , L_19 ) ;
return - V_163 ;
}
V_41 -> V_27 = * V_27 ;
break;
}
#endif
case V_213 :
* V_69 = F_102 ( V_175 ) ;
if ( ! memchr ( * V_69 , '\0' , F_98 ( V_175 ) ) ) {
F_91 ( log , L_20 ) ;
return - V_163 ;
}
break;
#ifdef F_103
case V_214 : {
int V_65 = F_95 ( V_175 , V_41 , log ) ;
if ( V_65 )
return V_65 ;
break;
}
#endif
default:
F_91 ( log , L_21 ,
type ) ;
return - V_163 ;
}
}
if ( V_176 > 0 ) {
F_91 ( log , L_22 , V_176 ) ;
return - V_163 ;
}
return 0 ;
}
bool F_104 ( struct V_80 * V_80 , enum V_215 V_174 )
{
if ( V_174 == V_53 )
return true ;
if ( F_5 ( V_55 ) &&
V_174 == V_56 )
return true ;
if ( F_5 ( V_24 ) &&
V_174 == V_57 )
return true ;
if ( F_5 ( V_58 ) &&
V_174 == V_59 ) {
struct V_216 * V_216 = F_105 ( V_80 , V_217 ) ;
return V_216 -> V_218 ;
}
return false ;
}
int F_106 ( struct V_80 * V_80 , const struct V_173 * V_174 ,
const struct V_1 * V_2 ,
struct V_219 * * V_220 , bool log )
{
struct V_40 V_221 ;
const char * V_69 = NULL ;
T_1 V_117 ;
int V_65 ;
V_117 = F_1 ( V_2 ) ;
if ( V_117 == V_8 ) {
F_91 ( log , L_23 ) ;
return - V_163 ;
}
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_221 . V_117 = V_117 ;
F_107 ( & V_221 . V_36 , V_222 ,
V_223 , 0 ) ;
V_65 = F_101 ( V_174 , & V_221 , & V_69 , log ) ;
if ( V_65 )
return V_65 ;
V_221 . V_23 = F_108 ( V_80 , & V_221 . V_36 , V_170 ) ;
if ( ! V_221 . V_23 ) {
F_91 ( log , L_24 ) ;
return - V_172 ;
}
F_109 ( V_224 , & V_221 . V_23 -> V_47 ) ;
F_81 ( & V_221 . V_23 -> V_115 ) ;
if ( V_69 ) {
V_65 = F_89 ( & V_221 , V_69 , V_2 , log ) ;
if ( V_65 )
goto V_225;
}
V_65 = F_110 ( V_220 , V_226 , & V_221 ,
sizeof( V_221 ) , log ) ;
if ( V_65 )
goto V_225;
return 0 ;
V_225:
F_111 ( & V_221 ) ;
return V_65 ;
}
static bool F_112 ( const struct V_40 * V_41 ,
struct V_38 * V_39 )
{
struct V_173 * V_227 ;
V_227 = F_113 ( V_39 , V_214 ) ;
if ( ! V_227 )
return false ;
if ( V_41 -> V_151 & V_156 ) {
if ( F_114 ( V_39 , V_182 ) )
return false ;
} else if ( V_41 -> V_151 & V_157 ) {
if ( F_114 ( V_39 , V_183 ) )
return false ;
} else {
goto V_228;
}
if ( V_41 -> V_121 . V_136 & V_137 ) {
if ( F_5 ( V_129 ) &&
V_41 -> V_117 == V_5 ) {
if ( F_115 ( V_39 , V_184 ,
V_41 -> V_121 . V_194 . V_93 ) ||
( V_41 -> V_121 . V_195 . V_93
!= V_41 -> V_121 . V_194 . V_93 &&
( F_115 ( V_39 , V_187 ,
V_41 -> V_121 . V_195 . V_93 ) ) ) )
return false ;
} else if ( F_5 ( V_133 ) &&
V_41 -> V_117 == V_7 ) {
if ( F_116 ( V_39 , V_184 ,
& V_41 -> V_121 . V_194 . V_229 ) ||
( memcmp ( & V_41 -> V_121 . V_195 . V_229 ,
& V_41 -> V_121 . V_194 . V_229 ,
sizeof( V_41 -> V_121 . V_195 . V_229 ) ) &&
( F_116 ( V_39 , V_187 ,
& V_41 -> V_121 . V_195 . V_229 ) ) ) )
return false ;
} else {
return false ;
}
}
if ( V_41 -> V_121 . V_136 & V_198 &&
( F_16 ( V_39 , V_188 ,
F_2 ( V_41 -> V_121 . V_196 . V_197 ) ) ||
( V_41 -> V_121 . V_199 . V_197 != V_41 -> V_121 . V_196 . V_197 &&
F_16 ( V_39 , V_189 ,
F_2 ( V_41 -> V_121 . V_199 . V_197 ) ) ) ) )
return false ;
if ( V_41 -> V_121 . V_136 & V_200 &&
F_114 ( V_39 , V_190 ) )
return false ;
if ( V_41 -> V_121 . V_136 & V_201 &&
F_114 ( V_39 , V_191 ) )
return false ;
if ( V_41 -> V_121 . V_136 & V_202 &&
F_114 ( V_39 , V_192 ) )
return false ;
V_228:
F_117 ( V_39 , V_227 ) ;
return true ;
}
int F_118 ( const struct V_40 * V_221 ,
struct V_38 * V_39 )
{
struct V_173 * V_227 ;
V_227 = F_113 ( V_39 , V_226 ) ;
if ( ! V_227 )
return - V_54 ;
if ( V_221 -> V_154 && F_114 ( V_39 , V_207 ) )
return - V_54 ;
if ( F_5 ( V_55 ) &&
F_16 ( V_39 , V_208 , V_221 -> V_36 . V_37 ) )
return - V_54 ;
if ( F_5 ( V_24 ) && V_221 -> V_25 . V_61 &&
F_17 ( V_39 , V_209 , sizeof( V_221 -> V_25 ) ,
& V_221 -> V_25 ) )
return - V_54 ;
if ( F_5 ( V_58 ) &&
F_87 ( & V_221 -> V_27 . V_61 ) &&
F_17 ( V_39 , V_211 , sizeof( V_221 -> V_27 ) ,
& V_221 -> V_27 ) )
return - V_54 ;
if ( V_221 -> V_69 ) {
if ( F_119 ( V_39 , V_213 ,
V_221 -> V_69 -> V_169 ) )
return - V_54 ;
}
#ifdef F_103
if ( V_221 -> V_151 && ! F_112 ( V_221 , V_39 ) )
return - V_54 ;
#endif
F_117 ( V_39 , V_227 ) ;
return 0 ;
}
void F_120 ( const struct V_173 * V_175 )
{
struct V_40 * V_221 = F_102 ( V_175 ) ;
F_111 ( V_221 ) ;
}
static void F_111 ( struct V_40 * V_221 )
{
if ( V_221 -> V_69 )
F_93 ( V_221 -> V_69 -> V_171 ) ;
if ( V_221 -> V_23 )
F_121 ( V_221 -> V_23 ) ;
}
void F_122 ( struct V_80 * V_80 )
{
unsigned int V_230 = sizeof( struct V_26 ) * V_231 ;
struct V_216 * V_216 = F_105 ( V_80 , V_217 ) ;
if ( F_123 ( V_80 , V_230 ) ) {
V_216 -> V_218 = false ;
F_91 ( true , L_25 ) ;
} else {
V_216 -> V_218 = true ;
}
}
void F_124 ( struct V_80 * V_80 )
{
struct V_216 * V_216 = F_105 ( V_80 , V_217 ) ;
if ( V_216 -> V_218 )
F_125 ( V_80 ) ;
}
