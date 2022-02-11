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
if ( V_64 )
return V_64 ;
V_2 -> V_92 . V_66 = F_27 ( V_38 ) -> V_73 ;
V_81 . V_86 = F_39 ( V_38 ) -> V_87 ;
#endif
} else {
F_41 ( V_38 ) ;
return - V_93 ;
}
V_2 -> V_92 . V_94 = V_95 ;
F_42 ( V_38 ) ;
V_38 -> V_96 = 1 ;
* F_35 ( V_38 ) = V_81 ;
return 0 ;
}
static struct V_97 *
F_43 ( struct V_79 * V_79 , const struct V_34 * V_35 ,
T_1 V_66 , const struct V_37 * V_38 )
{
struct V_98 V_99 ;
if ( ! F_44 ( V_38 , F_45 ( V_38 ) , V_66 , V_79 , & V_99 ) )
return NULL ;
return F_46 ( V_79 , V_35 , & V_99 ) ;
}
static enum V_9
F_47 ( const struct V_100 * V_101 )
{
const struct V_22 * V_23 = F_48 ( V_101 ) ;
if ( F_49 ( V_101 ) == V_102 )
return V_13 ;
if ( F_32 ( V_103 , & V_23 -> V_46 ) )
return V_16 ;
if ( F_32 ( V_104 , & V_23 -> V_46 ) )
return V_18 ;
return V_20 ;
}
static struct V_22 *
F_50 ( struct V_79 * V_79 , const struct V_34 * V_35 ,
T_2 V_105 , struct V_37 * V_38 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_98 V_99 ;
struct V_100 * V_101 ;
struct V_22 * V_23 ;
unsigned int V_110 ;
T_2 V_111 ;
V_107 = F_51 ( V_105 ) ;
if ( V_107 -> V_112 ( V_38 , F_45 ( V_38 ) , & V_110 ,
& V_111 ) <= 0 ) {
F_30 ( L_3 ) ;
return NULL ;
}
V_109 = F_52 ( V_105 , V_111 ) ;
if ( ! F_53 ( V_38 , F_45 ( V_38 ) , V_110 , V_105 ,
V_111 , V_79 , & V_99 , V_107 , V_109 ) ) {
F_30 ( L_4 ) ;
return NULL ;
}
V_101 = F_54 ( V_79 , V_35 , & V_99 ) ;
if ( ! V_101 )
return NULL ;
V_23 = F_48 ( V_101 ) ;
V_38 -> V_113 = & V_23 -> V_114 ;
V_38 -> V_115 = F_47 ( V_101 ) ;
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
V_23 = F_50 ( V_79 , & V_40 -> V_35 , V_40 -> V_116 , V_38 ) ;
if ( ! V_23 )
return false ;
if ( ! F_56 ( V_79 , F_57 ( & V_23 -> V_117 ) ) )
return false ;
if ( ! F_58 ( V_40 -> V_23 , F_12 ( V_23 ) ) )
return false ;
if ( V_40 -> V_68 ) {
struct V_69 * V_70 ;
V_70 = F_59 ( V_23 , V_118 ) ;
if ( V_70 && F_60 ( V_70 -> V_68 ) != V_40 -> V_68 )
return false ;
}
return true ;
}
static int F_61 ( struct V_37 * V_38 , struct V_22 * V_23 ,
enum V_9 V_10 ,
const struct V_119 * V_120 ,
enum V_121 V_122 )
{
int V_123 , V_124 , V_64 = V_72 ;
V_124 = F_45 ( V_38 ) ;
F_62 ( V_38 , V_124 ) ;
if ( V_122 == V_125 )
V_123 = V_126 ;
else
V_123 = V_127 ;
switch ( V_10 ) {
case V_18 :
case V_14 :
if ( F_5 ( V_128 ) &&
V_38 -> V_129 == F_29 ( V_4 ) &&
F_63 ( V_38 ) -> V_129 == V_130 ) {
if ( ! F_64 ( V_38 , V_23 , V_10 ,
V_123 ) )
V_64 = V_77 ;
goto V_131;
} else if ( F_5 ( V_132 ) &&
V_38 -> V_129 == F_29 ( V_6 ) ) {
T_5 V_74 ;
T_2 V_73 = F_27 ( V_38 ) -> V_73 ;
int V_133 = F_28 ( V_38 ,
sizeof( struct V_76 ) ,
& V_73 , & V_74 ) ;
if ( V_133 >= 0 && V_73 == V_134 ) {
if ( ! F_65 ( V_38 , V_23 ,
V_10 ,
V_123 ,
V_133 ) )
V_64 = V_77 ;
goto V_131;
}
}
case V_20 :
if ( ! F_66 ( V_23 , V_122 ) ) {
V_64 = ( V_120 && V_120 -> V_135 & V_136 )
? F_67 ( V_23 , V_120 , V_122 )
: F_68 ( V_23 , V_123 ) ;
if ( V_64 != V_72 )
goto V_131;
}
break;
case V_16 :
case V_13 :
break;
default:
V_64 = V_77 ;
goto V_131;
}
V_64 = F_69 ( V_23 , V_10 , V_123 , V_38 ) ;
V_131:
F_70 ( V_38 , V_124 ) ;
return V_64 ;
}
static void F_71 ( struct V_1 * V_2 ,
const struct V_37 * V_38 ,
enum V_121 V_122 )
{
if ( V_122 == V_125 ) {
T_5 V_137 ;
V_2 -> V_23 . V_33 |= V_48 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) )
V_2 -> V_138 . V_139 . V_137 = F_63 ( V_38 ) -> V_140 ;
else if ( V_2 -> V_3 . type == F_29 ( V_6 ) )
memcpy ( & V_2 -> V_141 . V_139 . V_137 , & F_27 ( V_38 ) -> V_140 ,
sizeof( V_2 -> V_141 . V_139 . V_137 ) ) ;
else
return;
if ( V_2 -> V_92 . V_66 == V_142 )
V_137 = F_72 ( V_38 ) -> V_143 ;
else if ( V_2 -> V_92 . V_66 == V_144 )
V_137 = F_73 ( V_38 ) -> V_143 ;
else if ( V_2 -> V_92 . V_66 == V_145 )
V_137 = F_74 ( V_38 ) -> V_143 ;
else
return;
V_2 -> V_146 . V_137 = V_137 ;
} else {
T_5 V_147 ;
V_2 -> V_23 . V_33 |= V_50 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) )
V_2 -> V_138 . V_139 . V_147 = F_63 ( V_38 ) -> V_148 ;
else if ( V_2 -> V_3 . type == F_29 ( V_6 ) )
memcpy ( & V_2 -> V_141 . V_139 . V_147 , & F_27 ( V_38 ) -> V_148 ,
sizeof( V_2 -> V_141 . V_139 . V_147 ) ) ;
else
return;
if ( V_2 -> V_92 . V_66 == V_142 )
V_147 = F_72 ( V_38 ) -> V_149 ;
else if ( V_2 -> V_92 . V_66 == V_144 )
V_147 = F_73 ( V_38 ) -> V_149 ;
else if ( V_2 -> V_92 . V_66 == V_145 )
V_147 = F_74 ( V_38 ) -> V_149 ;
else
return;
V_2 -> V_146 . V_147 = V_147 ;
}
}
static int F_75 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
enum V_121 V_122 ;
int V_64 ;
if ( F_76 ( V_23 ) ) {
return V_72 ;
}
if ( ! F_11 ( V_23 ) && ! F_77 ( V_23 ) )
return V_72 ;
if ( V_40 -> V_150 & V_151 && V_10 != V_20 &&
V_23 -> V_46 & V_152 &&
( V_10 != V_18 || V_40 -> V_153 ) ) {
if ( F_78 ( V_10 ) == V_102 )
V_122 = V_23 -> V_46 & V_47
? V_154 : V_125 ;
else
V_122 = V_23 -> V_46 & V_47
? V_125 : V_154 ;
} else if ( V_40 -> V_150 & V_155 ) {
V_122 = V_125 ;
} else if ( V_40 -> V_150 & V_156 ) {
V_122 = V_154 ;
} else {
return V_72 ;
}
V_64 = F_61 ( V_38 , V_23 , V_10 , & V_40 -> V_120 , V_122 ) ;
if ( V_64 == V_72 )
F_71 ( V_2 , V_38 , V_122 ) ;
return V_64 ;
}
static int F_75 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 , struct V_22 * V_23 ,
enum V_9 V_10 )
{
return V_72 ;
}
static int F_79 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
bool V_157 = F_55 ( V_79 , V_2 , V_40 , V_38 ) ;
enum V_9 V_10 ;
struct V_22 * V_23 ;
if ( ! V_157 ) {
struct V_22 * V_158 = V_40 -> V_23 ;
int V_64 ;
if ( V_158 ) {
if ( V_38 -> V_113 )
F_80 ( V_38 -> V_113 ) ;
F_81 ( & V_158 -> V_114 ) ;
V_38 -> V_113 = & V_158 -> V_114 ;
V_38 -> V_115 = V_20 ;
}
do {
V_64 = F_82 ( V_79 , V_40 -> V_116 ,
V_159 , V_38 ) ;
} while ( V_64 == V_160 );
if ( V_64 != V_72 )
return - V_161 ;
V_2 -> V_23 . V_33 = 0 ;
F_9 ( V_38 , V_40 , V_2 , true , true ) ;
}
V_23 = F_10 ( V_38 , & V_10 ) ;
if ( V_23 ) {
if ( V_40 -> V_150 && ! ( V_2 -> V_23 . V_33 & V_45 ) &&
( F_11 ( V_23 ) || V_40 -> V_153 ) &&
F_75 ( V_79 , V_2 , V_40 , V_38 , V_23 , V_10 ) != V_72 ) {
return - V_162 ;
}
if ( ! F_11 ( V_23 ) && V_40 -> V_153 &&
V_40 -> V_68 && ! F_24 ( V_23 ) ) {
int V_64 = F_83 ( V_23 , V_40 -> V_23 ,
V_163 ) ;
if ( V_64 )
return V_64 ;
}
if ( ( F_11 ( V_23 ) ? ! V_157 : V_40 -> V_153 ) &&
F_23 ( V_38 , V_40 -> V_116 ) != V_72 ) {
return - V_162 ;
}
}
return 0 ;
}
static int F_84 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
struct V_97 * exp ;
exp = F_43 ( V_79 , & V_40 -> V_35 , V_40 -> V_116 , V_38 ) ;
if ( exp ) {
T_2 V_33 ;
V_33 = V_12 | V_21 | V_19 ;
F_8 ( V_2 , V_33 , & V_40 -> V_35 , exp -> V_44 ) ;
} else {
struct V_22 * V_23 ;
int V_64 ;
V_64 = F_79 ( V_79 , V_2 , V_40 , V_38 ) ;
if ( V_64 )
return V_64 ;
V_23 = (struct V_22 * ) V_38 -> V_113 ;
if ( V_23 )
F_85 ( V_23 ) ;
}
return 0 ;
}
static bool F_86 ( const struct V_26 * V_27 )
{
T_4 V_164 ;
for ( V_164 = 0 ; V_164 < sizeof( * V_27 ) ; V_164 ++ )
if ( V_27 -> V_165 [ V_164 ] )
return true ;
return false ;
}
static int F_87 ( struct V_79 * V_79 , struct V_1 * V_2 ,
const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
int V_64 ;
V_64 = F_79 ( V_79 , V_2 , V_40 , V_38 ) ;
if ( V_64 )
return V_64 ;
if ( V_40 -> V_25 . V_60 ) {
V_64 = F_18 ( V_38 , V_2 , V_40 -> V_25 . V_166 ,
V_40 -> V_25 . V_60 ) ;
if ( V_64 )
return V_64 ;
}
if ( F_86 ( & V_40 -> V_27 . V_60 ) ) {
V_64 = F_20 ( V_38 , V_2 , & V_40 -> V_27 . V_166 ,
& V_40 -> V_27 . V_60 ) ;
if ( V_64 )
return V_64 ;
}
if ( F_88 ( V_38 ) != V_72 )
return - V_162 ;
return 0 ;
}
int F_89 ( struct V_79 * V_79 , struct V_37 * V_38 ,
struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
int V_167 ;
int V_64 ;
V_167 = F_45 ( V_38 ) ;
F_62 ( V_38 , V_167 ) ;
if ( V_2 -> V_92 . V_94 != V_95 ) {
V_64 = F_34 ( V_79 , V_2 , V_40 -> V_35 . V_36 , V_38 ) ;
if ( V_64 )
return V_64 ;
}
if ( V_40 -> V_153 )
V_64 = F_87 ( V_79 , V_2 , V_40 , V_38 ) ;
else
V_64 = F_84 ( V_79 , V_2 , V_40 , V_38 ) ;
F_70 ( V_38 , V_167 ) ;
if ( V_64 )
F_41 ( V_38 ) ;
return V_64 ;
}
static int F_90 ( struct V_39 * V_40 , const char * V_168 ,
const struct V_1 * V_2 , bool log )
{
struct V_67 * V_68 ;
struct V_69 * V_70 ;
V_68 = F_91 ( V_168 , V_40 -> V_116 ,
V_2 -> V_92 . V_66 ) ;
if ( ! V_68 ) {
F_92 ( log , L_5 , V_168 ) ;
return - V_162 ;
}
V_70 = F_93 ( V_40 -> V_23 , V_68 , V_169 ) ;
if ( ! V_70 ) {
F_94 ( V_68 -> V_170 ) ;
return - V_171 ;
}
F_95 ( V_70 -> V_68 , V_68 ) ;
V_40 -> V_68 = V_68 ;
return 0 ;
}
static int F_96 ( const struct V_172 * V_173 ,
struct V_39 * V_40 , bool log )
{
struct V_172 * V_174 ;
int V_175 ;
bool V_176 = false ;
bool V_177 = false ;
bool V_178 = ( V_40 -> V_116 == V_7 ) ;
F_97 (a, attr, rem) {
static const int V_179 [ V_180 + 1 ] [ 2 ] = {
[ V_181 ] = { 0 , 0 } ,
[ V_182 ] = { 0 , 0 } ,
[ V_183 ] = { sizeof( struct V_184 ) ,
sizeof(struct V_185 ) } ,
[ V_186 ] = { sizeof( struct V_184 ) ,
sizeof(struct V_185 ) } ,
[ V_187 ] = { sizeof( T_1 ) , sizeof( T_1 ) } ,
[ V_188 ] = { sizeof( T_1 ) , sizeof( T_1 ) } ,
[ V_189 ] = { 0 , 0 } ,
[ V_190 ] = { 0 , 0 } ,
[ V_191 ] = { 0 , 0 } ,
} ;
int type = F_98 ( V_174 ) ;
if ( type > V_180 ) {
F_92 ( log ,
L_6 ,
type , V_180 ) ;
return - V_162 ;
}
if ( F_99 ( V_174 ) != V_179 [ type ] [ V_178 ] ) {
F_92 ( log ,
L_7 ,
type , F_99 ( V_174 ) ,
V_179 [ type ] [ V_178 ] ) ;
return - V_162 ;
}
switch ( type ) {
case V_181 :
case V_182 :
if ( V_40 -> V_150 ) {
F_92 ( log ,
L_8
) ;
return - V_192 ;
}
V_40 -> V_150 |= V_151 ;
V_40 -> V_150 |= ( ( type == V_181 )
? V_155 : V_156 ) ;
break;
case V_183 :
F_100 ( & V_40 -> V_120 . V_193 , V_174 ,
sizeof( V_40 -> V_120 . V_193 ) ) ;
V_40 -> V_120 . V_135 |= V_136 ;
break;
case V_186 :
V_176 = true ;
F_100 ( & V_40 -> V_120 . V_194 , V_174 ,
sizeof( V_40 -> V_120 . V_194 ) ) ;
V_40 -> V_120 . V_135 |= V_136 ;
break;
case V_187 :
V_40 -> V_120 . V_195 . V_196 = F_29 ( F_101 ( V_174 ) ) ;
V_40 -> V_120 . V_135 |= V_197 ;
break;
case V_188 :
V_177 = true ;
V_40 -> V_120 . V_198 . V_196 = F_29 ( F_101 ( V_174 ) ) ;
V_40 -> V_120 . V_135 |= V_197 ;
break;
case V_189 :
V_40 -> V_120 . V_135 |= V_199 ;
break;
case V_190 :
V_40 -> V_120 . V_135 |= V_200 ;
break;
case V_191 :
V_40 -> V_120 . V_135 |= V_201 ;
break;
default:
F_92 ( log , L_9 , type ) ;
return - V_162 ;
}
}
if ( V_175 > 0 ) {
F_92 ( log , L_10 , V_175 ) ;
return - V_162 ;
}
if ( ! V_40 -> V_150 ) {
if ( V_40 -> V_120 . V_135 ) {
F_92 ( log ,
L_11
) ;
return - V_162 ;
}
V_40 -> V_150 = V_151 ;
} else if ( ! V_40 -> V_153 ) {
F_92 ( log ,
L_12
) ;
return - V_162 ;
}
if ( V_40 -> V_120 . V_135 & V_136 && ! V_176 ) {
memcpy ( & V_40 -> V_120 . V_194 , & V_40 -> V_120 . V_193 ,
sizeof( V_40 -> V_120 . V_194 ) ) ;
}
if ( V_40 -> V_120 . V_135 & V_197 &&
! V_177 ) {
V_40 -> V_120 . V_198 . V_196 = V_40 -> V_120 . V_195 . V_196 ;
}
return 0 ;
}
static int F_102 ( const struct V_172 * V_173 , struct V_39 * V_40 ,
const char * * V_68 , bool log )
{
struct V_172 * V_174 ;
int V_175 ;
F_97 (a, attr, rem) {
int type = F_98 ( V_174 ) ;
int V_202 = V_203 [ type ] . V_202 ;
int V_204 = V_203 [ type ] . V_204 ;
if ( type > V_205 ) {
F_92 ( log ,
L_13 ,
type , V_205 ) ;
return - V_162 ;
}
if ( F_99 ( V_174 ) < V_204 || F_99 ( V_174 ) > V_202 ) {
F_92 ( log ,
L_14 ,
type , F_99 ( V_174 ) , V_202 ) ;
return - V_162 ;
}
switch ( type ) {
case V_206 :
V_40 -> V_153 = true ;
break;
#ifdef V_54
case V_207 :
V_40 -> V_35 . V_36 = F_101 ( V_174 ) ;
break;
#endif
#ifdef V_24
case V_208 : {
struct V_209 * V_25 = F_103 ( V_174 ) ;
if ( ! V_25 -> V_60 ) {
F_92 ( log , L_15 ) ;
return - V_162 ;
}
V_40 -> V_25 = * V_25 ;
break;
}
#endif
#ifdef V_57
case V_210 : {
struct V_211 * V_27 = F_103 ( V_174 ) ;
if ( ! F_86 ( & V_27 -> V_60 ) ) {
F_92 ( log , L_16 ) ;
return - V_162 ;
}
V_40 -> V_27 = * V_27 ;
break;
}
#endif
case V_212 :
* V_68 = F_103 ( V_174 ) ;
if ( ! memchr ( * V_68 , '\0' , F_99 ( V_174 ) ) ) {
F_92 ( log , L_17 ) ;
return - V_162 ;
}
break;
#ifdef F_104
case V_213 : {
int V_64 = F_96 ( V_174 , V_40 , log ) ;
if ( V_64 )
return V_64 ;
break;
}
#endif
default:
F_92 ( log , L_18 ,
type ) ;
return - V_162 ;
}
}
#ifdef V_24
if ( ! V_40 -> V_153 && V_40 -> V_25 . V_60 ) {
F_92 ( log ,
L_19 ) ;
return - V_162 ;
}
#endif
#ifdef V_57
if ( ! V_40 -> V_153 && F_86 ( & V_40 -> V_27 . V_60 ) ) {
F_92 ( log ,
L_20 ) ;
return - V_162 ;
}
#endif
if ( V_175 > 0 ) {
F_92 ( log , L_21 , V_175 ) ;
return - V_162 ;
}
return 0 ;
}
bool F_105 ( struct V_79 * V_79 , enum V_214 V_173 )
{
if ( V_173 == V_52 )
return true ;
if ( F_5 ( V_54 ) &&
V_173 == V_55 )
return true ;
if ( F_5 ( V_24 ) &&
V_173 == V_56 )
return true ;
if ( F_5 ( V_57 ) &&
V_173 == V_58 ) {
struct V_215 * V_215 = F_106 ( V_79 , V_216 ) ;
return V_215 -> V_217 ;
}
return false ;
}
int F_107 ( struct V_79 * V_79 , const struct V_172 * V_173 ,
const struct V_1 * V_2 ,
struct V_218 * * V_219 , bool log )
{
struct V_39 V_220 ;
const char * V_68 = NULL ;
T_1 V_116 ;
int V_64 ;
V_116 = F_1 ( V_2 ) ;
if ( V_116 == V_8 ) {
F_92 ( log , L_22 ) ;
return - V_162 ;
}
memset ( & V_220 , 0 , sizeof( V_220 ) ) ;
V_220 . V_116 = V_116 ;
F_108 ( & V_220 . V_35 , V_221 ,
V_222 , 0 ) ;
V_64 = F_102 ( V_173 , & V_220 , & V_68 , log ) ;
if ( V_64 )
return V_64 ;
V_220 . V_23 = F_109 ( V_79 , & V_220 . V_35 , V_169 ) ;
if ( ! V_220 . V_23 ) {
F_92 ( log , L_23 ) ;
return - V_171 ;
}
F_110 ( V_223 , & V_220 . V_23 -> V_46 ) ;
F_81 ( & V_220 . V_23 -> V_114 ) ;
if ( V_68 ) {
V_64 = F_90 ( & V_220 , V_68 , V_2 , log ) ;
if ( V_64 )
goto V_224;
}
V_64 = F_111 ( V_219 , V_225 , & V_220 ,
sizeof( V_220 ) , log ) ;
if ( V_64 )
goto V_224;
return 0 ;
V_224:
F_112 ( & V_220 ) ;
return V_64 ;
}
static bool F_113 ( const struct V_39 * V_40 ,
struct V_37 * V_38 )
{
struct V_172 * V_226 ;
V_226 = F_114 ( V_38 , V_213 ) ;
if ( ! V_226 )
return false ;
if ( V_40 -> V_150 & V_155 ) {
if ( F_115 ( V_38 , V_181 ) )
return false ;
} else if ( V_40 -> V_150 & V_156 ) {
if ( F_115 ( V_38 , V_182 ) )
return false ;
} else {
goto V_227;
}
if ( V_40 -> V_120 . V_135 & V_136 ) {
if ( F_5 ( V_128 ) &&
V_40 -> V_116 == V_5 ) {
if ( F_116 ( V_38 , V_183 ,
V_40 -> V_120 . V_193 . V_92 ) ||
( V_40 -> V_120 . V_194 . V_92
!= V_40 -> V_120 . V_193 . V_92 &&
( F_116 ( V_38 , V_186 ,
V_40 -> V_120 . V_194 . V_92 ) ) ) )
return false ;
} else if ( F_5 ( V_132 ) &&
V_40 -> V_116 == V_7 ) {
if ( F_117 ( V_38 , V_183 ,
& V_40 -> V_120 . V_193 . V_228 ) ||
( memcmp ( & V_40 -> V_120 . V_194 . V_228 ,
& V_40 -> V_120 . V_193 . V_228 ,
sizeof( V_40 -> V_120 . V_194 . V_228 ) ) &&
( F_117 ( V_38 , V_186 ,
& V_40 -> V_120 . V_194 . V_228 ) ) ) )
return false ;
} else {
return false ;
}
}
if ( V_40 -> V_120 . V_135 & V_197 &&
( F_16 ( V_38 , V_187 ,
F_2 ( V_40 -> V_120 . V_195 . V_196 ) ) ||
( V_40 -> V_120 . V_198 . V_196 != V_40 -> V_120 . V_195 . V_196 &&
F_16 ( V_38 , V_188 ,
F_2 ( V_40 -> V_120 . V_198 . V_196 ) ) ) ) )
return false ;
if ( V_40 -> V_120 . V_135 & V_199 &&
F_115 ( V_38 , V_189 ) )
return false ;
if ( V_40 -> V_120 . V_135 & V_200 &&
F_115 ( V_38 , V_190 ) )
return false ;
if ( V_40 -> V_120 . V_135 & V_201 &&
F_115 ( V_38 , V_191 ) )
return false ;
V_227:
F_118 ( V_38 , V_226 ) ;
return true ;
}
int F_119 ( const struct V_39 * V_220 ,
struct V_37 * V_38 )
{
struct V_172 * V_226 ;
V_226 = F_114 ( V_38 , V_225 ) ;
if ( ! V_226 )
return - V_53 ;
if ( V_220 -> V_153 && F_115 ( V_38 , V_206 ) )
return - V_53 ;
if ( F_5 ( V_54 ) &&
F_16 ( V_38 , V_207 , V_220 -> V_35 . V_36 ) )
return - V_53 ;
if ( F_5 ( V_24 ) && V_220 -> V_25 . V_60 &&
F_17 ( V_38 , V_208 , sizeof( V_220 -> V_25 ) ,
& V_220 -> V_25 ) )
return - V_53 ;
if ( F_5 ( V_57 ) &&
F_86 ( & V_220 -> V_27 . V_60 ) &&
F_17 ( V_38 , V_210 , sizeof( V_220 -> V_27 ) ,
& V_220 -> V_27 ) )
return - V_53 ;
if ( V_220 -> V_68 ) {
if ( F_120 ( V_38 , V_212 ,
V_220 -> V_68 -> V_168 ) )
return - V_53 ;
}
#ifdef F_104
if ( V_220 -> V_150 && ! F_113 ( V_220 , V_38 ) )
return - V_53 ;
#endif
F_118 ( V_38 , V_226 ) ;
return 0 ;
}
void F_121 ( const struct V_172 * V_174 )
{
struct V_39 * V_220 = F_103 ( V_174 ) ;
F_112 ( V_220 ) ;
}
static void F_112 ( struct V_39 * V_220 )
{
if ( V_220 -> V_68 )
F_94 ( V_220 -> V_68 -> V_170 ) ;
if ( V_220 -> V_23 )
F_122 ( V_220 -> V_23 ) ;
}
void F_123 ( struct V_79 * V_79 )
{
unsigned int V_229 = sizeof( struct V_26 ) * V_230 ;
struct V_215 * V_215 = F_106 ( V_79 , V_216 ) ;
if ( F_124 ( V_79 , V_229 - 1 ) ) {
V_215 -> V_217 = false ;
F_92 ( true , L_24 ) ;
} else {
V_215 -> V_217 = true ;
}
}
void F_125 ( struct V_79 * V_79 )
{
struct V_215 * V_215 = F_106 ( V_79 , V_216 ) ;
if ( V_215 -> V_217 )
F_126 ( V_79 ) ;
}
