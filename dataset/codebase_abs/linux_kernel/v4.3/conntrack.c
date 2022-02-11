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
case V_15 :
V_11 |= V_16 ;
break;
default:
break;
}
switch ( V_10 ) {
case V_17 :
case V_13 :
V_11 |= V_18 ;
break;
case V_19 :
case V_14 :
V_11 |= V_20 ;
break;
case V_21 :
case V_15 :
V_11 |= V_22 ;
break;
default:
break;
}
return V_11 ;
}
static T_3 F_4 ( const struct V_23 * V_24 )
{
#if F_5 ( V_25 )
return V_24 ? V_24 -> V_26 : 0 ;
#else
return 0 ;
#endif
}
static void F_6 ( const struct V_23 * V_24 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = V_24 ? F_7 ( V_24 ) : NULL ;
if ( V_30 ) {
T_4 V_31 = V_30 -> V_32 * sizeof( long ) ;
if ( V_31 > V_33 )
V_31 = V_33 ;
else if ( V_31 < V_33 )
memset ( V_28 , 0 , V_33 ) ;
memcpy ( V_28 , V_30 -> V_34 , V_31 ) ;
} else {
memset ( V_28 , 0 , V_33 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , T_2 V_35 ,
const struct V_36 * V_37 ,
const struct V_23 * V_24 )
{
V_2 -> V_24 . V_35 = V_35 ;
V_2 -> V_24 . V_37 = V_37 -> V_38 ;
V_2 -> V_24 . V_26 = F_4 ( V_24 ) ;
F_6 ( V_24 , & V_2 -> V_24 . V_28 ) ;
}
static void F_9 ( const struct V_39 * V_40 ,
struct V_1 * V_2 , bool V_41 )
{
const struct V_36 * V_37 = & V_42 ;
enum V_9 V_10 ;
struct V_23 * V_24 ;
T_2 V_35 = 0 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( V_24 ) {
V_35 = F_3 ( V_10 ) ;
if ( ! F_11 ( V_24 ) )
V_35 |= V_22 ;
if ( V_24 -> V_43 )
V_35 |= V_20 ;
V_37 = F_12 ( V_24 ) ;
} else if ( V_41 ) {
V_35 = V_12 | V_44 ;
}
F_8 ( V_2 , V_35 , V_37 , V_24 ) ;
}
void F_13 ( const struct V_39 * V_40 , struct V_1 * V_2 )
{
F_9 ( V_40 , V_2 , false ) ;
}
int F_14 ( const struct V_1 * V_2 , struct V_39 * V_40 )
{
if ( F_15 ( V_40 , V_45 , V_2 -> V_24 . V_35 ) )
return - V_46 ;
if ( F_5 ( V_47 ) &&
F_16 ( V_40 , V_48 , V_2 -> V_24 . V_37 ) )
return - V_46 ;
if ( F_5 ( V_25 ) &&
F_15 ( V_40 , V_49 , V_2 -> V_24 . V_26 ) )
return - V_46 ;
if ( F_5 ( V_50 ) &&
F_17 ( V_40 , V_51 , sizeof( V_2 -> V_24 . V_28 ) ,
& V_2 -> V_24 . V_28 ) )
return - V_46 ;
return 0 ;
}
static int F_18 ( struct V_39 * V_40 , struct V_1 * V_2 ,
T_3 V_52 , T_3 V_53 )
{
#if F_5 ( V_25 )
enum V_9 V_10 ;
struct V_23 * V_24 ;
T_3 V_54 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( ! V_24 )
return 0 ;
V_54 = V_52 | ( V_24 -> V_26 & ~ ( V_53 ) ) ;
if ( V_24 -> V_26 != V_54 ) {
V_24 -> V_26 = V_54 ;
F_19 ( V_55 , V_24 ) ;
V_2 -> V_24 . V_26 = V_54 ;
}
return 0 ;
#else
return - V_56 ;
#endif
}
static int F_20 ( struct V_39 * V_40 , struct V_1 * V_2 ,
const struct V_27 * V_28 ,
const struct V_27 * V_53 )
{
enum V_9 V_10 ;
struct V_29 * V_30 ;
struct V_23 * V_24 ;
int V_57 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( ! V_24 )
return 0 ;
V_30 = F_7 ( V_24 ) ;
if ( ! V_30 ) {
F_21 ( V_24 ) ;
V_30 = F_7 ( V_24 ) ;
}
if ( ! V_30 || V_30 -> V_32 * sizeof( long ) < V_33 )
return - V_58 ;
V_57 = F_22 ( V_24 , ( T_3 * ) V_28 , ( T_3 * ) V_53 ,
V_33 / sizeof( T_3 ) ) ;
if ( V_57 )
return V_57 ;
F_6 ( V_24 , & V_2 -> V_24 . V_28 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_40 , T_1 V_59 )
{
const struct V_60 * V_61 ;
const struct V_62 * V_63 ;
enum V_9 V_10 ;
unsigned int V_64 ;
struct V_23 * V_24 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( ! V_24 || V_10 == V_14 )
return V_65 ;
V_63 = F_24 ( V_24 ) ;
if ( ! V_63 )
return V_65 ;
V_61 = F_25 ( V_63 -> V_61 ) ;
if ( ! V_61 )
return V_65 ;
switch ( V_59 ) {
case V_5 :
V_64 = F_26 ( V_40 ) ;
break;
case V_7 : {
T_2 V_66 = F_27 ( V_40 ) -> V_66 ;
T_5 V_67 ;
int V_68 ;
V_68 = F_28 ( V_40 , sizeof( struct V_69 ) , & V_66 ,
& V_67 ) ;
if ( V_68 < 0 || ( V_67 & F_29 ( ~ 0x7 ) ) != 0 ) {
F_30 ( L_1 ) ;
return V_65 ;
}
V_64 = V_68 ;
break;
}
default:
F_31 ( 1 , L_2 ) ;
return V_70 ;
}
return V_61 -> V_63 ( V_40 , V_64 , V_24 , V_10 ) ;
}
static int F_32 ( struct V_71 * V_71 , struct V_1 * V_2 ,
T_1 V_37 , struct V_39 * V_40 )
{
struct V_72 V_73 = * F_33 ( V_40 ) ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) ) {
enum V_74 V_75 = V_76 + V_37 ;
int V_57 ;
memset ( F_34 ( V_40 ) , 0 , sizeof( struct V_77 ) ) ;
V_57 = F_35 ( V_40 , V_75 ) ;
if ( V_57 )
return V_57 ;
V_73 . V_78 = F_34 ( V_40 ) -> V_79 ;
#if F_5 ( V_80 )
} else if ( V_2 -> V_3 . type == F_29 ( V_6 ) ) {
enum V_81 V_75 = V_82 + V_37 ;
struct V_39 * V_83 ;
memset ( F_36 ( V_40 ) , 0 , sizeof( struct V_84 ) ) ;
V_83 = F_37 ( V_40 , V_75 ) ;
if ( ! V_83 )
return - V_85 ;
if ( V_40 == V_83 ) {
F_38 ( V_40 ) ;
return - V_86 ;
}
F_39 ( V_40 ) ;
F_40 ( V_83 ) ;
V_2 -> V_87 . V_59 = F_27 ( V_83 ) -> V_66 ;
F_41 ( V_40 , V_83 ) ;
V_40 -> V_88 = V_83 -> V_88 ;
F_42 ( V_83 ) ;
V_73 . V_78 = F_36 ( V_40 ) -> V_79 ;
#endif
} else {
F_38 ( V_40 ) ;
return - V_89 ;
}
V_2 -> V_87 . V_90 = V_91 ;
F_43 ( V_40 ) ;
V_40 -> V_92 = 1 ;
* F_33 ( V_40 ) = V_73 ;
return 0 ;
}
static struct V_93 *
F_44 ( struct V_71 * V_71 , const struct V_36 * V_37 ,
T_1 V_59 , const struct V_39 * V_40 )
{
struct V_94 V_95 ;
if ( ! F_45 ( V_40 , F_46 ( V_40 ) , V_59 , & V_95 ) )
return NULL ;
return F_47 ( V_71 , V_37 , & V_95 ) ;
}
static bool F_48 ( const struct V_71 * V_71 , const struct V_39 * V_40 ,
const struct V_96 * V_97 )
{
enum V_9 V_10 ;
struct V_23 * V_24 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( ! V_24 )
return false ;
if ( ! F_49 ( V_71 , F_50 ( & V_24 -> V_98 ) ) )
return false ;
if ( ! F_51 ( V_97 -> V_24 , F_12 ( V_24 ) ) )
return false ;
if ( V_97 -> V_61 ) {
struct V_62 * V_63 ;
V_63 = F_52 ( V_24 , V_99 ) ;
if ( V_63 && F_53 ( V_63 -> V_61 ) != V_97 -> V_61 )
return false ;
}
return true ;
}
static int F_54 ( struct V_71 * V_71 , struct V_1 * V_2 ,
const struct V_96 * V_97 ,
struct V_39 * V_40 )
{
if ( ! F_48 ( V_71 , V_40 , V_97 ) ) {
struct V_23 * V_100 = V_97 -> V_24 ;
if ( V_100 ) {
if ( V_40 -> V_101 )
F_55 ( V_40 -> V_101 ) ;
F_56 ( & V_100 -> V_102 ) ;
V_40 -> V_101 = & V_100 -> V_102 ;
V_40 -> V_103 = V_21 ;
}
if ( F_57 ( V_71 , V_97 -> V_104 , V_105 ,
V_40 ) != V_65 )
return - V_106 ;
if ( F_23 ( V_40 , V_97 -> V_104 ) != V_65 ) {
F_31 ( 1 , L_3 ) ;
return - V_86 ;
}
}
F_9 ( V_40 , V_2 , true ) ;
return 0 ;
}
static int F_58 ( struct V_71 * V_71 , struct V_1 * V_2 ,
const struct V_96 * V_97 ,
struct V_39 * V_40 )
{
struct V_93 * exp ;
exp = F_44 ( V_71 , & V_97 -> V_37 , V_97 -> V_104 , V_40 ) ;
if ( exp ) {
T_2 V_35 ;
V_35 = V_12 | V_22 | V_20 ;
F_8 ( V_2 , V_35 , & V_97 -> V_37 , exp -> V_43 ) ;
} else {
int V_57 ;
V_57 = F_54 ( V_71 , V_2 , V_97 , V_40 ) ;
if ( V_57 )
return V_57 ;
}
return 0 ;
}
static int F_59 ( struct V_71 * V_71 , struct V_1 * V_2 ,
const struct V_96 * V_97 ,
struct V_39 * V_40 )
{
T_2 V_35 ;
int V_57 ;
V_35 = V_2 -> V_24 . V_35 ;
if ( V_2 -> V_24 . V_37 == V_97 -> V_37 . V_38 &&
( ( V_35 & V_12 ) && ! ( V_35 & V_22 ) ) ) {
return 0 ;
}
V_57 = F_54 ( V_71 , V_2 , V_97 , V_40 ) ;
if ( V_57 )
return V_57 ;
if ( F_60 ( V_40 ) != V_65 )
return - V_86 ;
return 0 ;
}
static bool F_61 ( const struct V_27 * V_28 )
{
T_4 V_107 ;
for ( V_107 = 0 ; V_107 < sizeof( * V_28 ) ; V_107 ++ )
if ( V_28 -> V_108 [ V_107 ] )
return true ;
return false ;
}
int F_62 ( struct V_71 * V_71 , struct V_39 * V_40 ,
struct V_1 * V_2 ,
const struct V_96 * V_97 )
{
int V_109 ;
int V_57 ;
V_109 = F_46 ( V_40 ) ;
F_63 ( V_40 , V_109 ) ;
if ( V_2 -> V_87 . V_90 != V_91 ) {
V_57 = F_32 ( V_71 , V_2 , V_97 -> V_37 . V_38 , V_40 ) ;
if ( V_57 )
return V_57 ;
}
if ( V_97 -> V_110 )
V_57 = F_59 ( V_71 , V_2 , V_97 , V_40 ) ;
else
V_57 = F_58 ( V_71 , V_2 , V_97 , V_40 ) ;
if ( V_57 )
goto V_57;
if ( V_97 -> V_26 . V_53 ) {
V_57 = F_18 ( V_40 , V_2 , V_97 -> V_26 . V_111 ,
V_97 -> V_26 . V_53 ) ;
if ( V_57 )
goto V_57;
}
if ( F_61 ( & V_97 -> V_28 . V_53 ) )
V_57 = F_20 ( V_40 , V_2 , & V_97 -> V_28 . V_111 ,
& V_97 -> V_28 . V_53 ) ;
V_57:
F_64 ( V_40 , V_109 ) ;
if ( V_57 )
F_38 ( V_40 ) ;
return V_57 ;
}
static int F_65 ( struct V_96 * V_97 , const char * V_112 ,
const struct V_1 * V_2 , bool log )
{
struct V_60 * V_61 ;
struct V_62 * V_63 ;
V_61 = F_66 ( V_112 , V_97 -> V_104 ,
V_2 -> V_87 . V_59 ) ;
if ( ! V_61 ) {
F_67 ( log , L_4 , V_112 ) ;
return - V_86 ;
}
V_63 = F_68 ( V_97 -> V_24 , V_61 , V_113 ) ;
if ( ! V_63 ) {
F_69 ( V_61 -> V_114 ) ;
return - V_115 ;
}
F_70 ( V_63 -> V_61 , V_61 ) ;
V_97 -> V_61 = V_61 ;
return 0 ;
}
static int F_71 ( const struct V_116 * V_117 , struct V_96 * V_97 ,
const char * * V_61 , bool log )
{
struct V_116 * V_118 ;
int V_119 ;
F_72 (a, attr, rem) {
int type = F_73 ( V_118 ) ;
int V_120 = V_121 [ type ] . V_120 ;
int V_122 = V_121 [ type ] . V_122 ;
if ( type > V_123 ) {
F_67 ( log ,
L_5 ,
type , V_123 ) ;
return - V_86 ;
}
if ( F_74 ( V_118 ) < V_122 || F_74 ( V_118 ) > V_120 ) {
F_67 ( log ,
L_6 ,
type , F_74 ( V_118 ) , V_120 ) ;
return - V_86 ;
}
switch ( type ) {
case V_124 :
V_97 -> V_110 = true ;
break;
#ifdef V_47
case V_125 :
V_97 -> V_37 . V_38 = F_75 ( V_118 ) ;
break;
#endif
#ifdef V_25
case V_126 : {
struct V_127 * V_26 = F_76 ( V_118 ) ;
if ( ! V_26 -> V_53 ) {
F_67 ( log , L_7 ) ;
return - V_86 ;
}
V_97 -> V_26 = * V_26 ;
break;
}
#endif
#ifdef V_50
case V_128 : {
struct V_129 * V_28 = F_76 ( V_118 ) ;
if ( ! F_61 ( & V_28 -> V_53 ) ) {
F_67 ( log , L_8 ) ;
return - V_86 ;
}
V_97 -> V_28 = * V_28 ;
break;
}
#endif
case V_130 :
* V_61 = F_76 ( V_118 ) ;
if ( ! memchr ( * V_61 , '\0' , F_74 ( V_118 ) ) ) {
F_67 ( log , L_9 ) ;
return - V_86 ;
}
break;
default:
F_67 ( log , L_10 ,
type ) ;
return - V_86 ;
}
}
if ( V_119 > 0 ) {
F_67 ( log , L_11 , V_119 ) ;
return - V_86 ;
}
return 0 ;
}
bool F_77 ( struct V_71 * V_71 , enum V_131 V_117 )
{
if ( V_117 == V_45 )
return true ;
if ( F_5 ( V_47 ) &&
V_117 == V_48 )
return true ;
if ( F_5 ( V_25 ) &&
V_117 == V_49 )
return true ;
if ( F_5 ( V_50 ) &&
V_117 == V_51 ) {
struct V_132 * V_132 = F_78 ( V_71 , V_133 ) ;
return V_132 -> V_134 ;
}
return false ;
}
int F_79 ( struct V_71 * V_71 , const struct V_116 * V_117 ,
const struct V_1 * V_2 ,
struct V_135 * * V_136 , bool log )
{
struct V_96 V_137 ;
const char * V_61 = NULL ;
T_1 V_104 ;
int V_57 ;
V_104 = F_1 ( V_2 ) ;
if ( V_104 == V_8 ) {
F_67 ( log , L_12 ) ;
return - V_86 ;
}
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_137 . V_104 = V_104 ;
F_80 ( & V_137 . V_37 , V_138 ,
V_139 , 0 ) ;
V_57 = F_71 ( V_117 , & V_137 , & V_61 , log ) ;
if ( V_57 )
return V_57 ;
V_137 . V_24 = F_81 ( V_71 , & V_137 . V_37 , V_113 ) ;
if ( ! V_137 . V_24 ) {
F_67 ( log , L_13 ) ;
return - V_115 ;
}
if ( V_61 ) {
V_57 = F_65 ( & V_137 , V_61 , V_2 , log ) ;
if ( V_57 )
goto V_140;
}
V_57 = F_82 ( V_136 , V_141 , & V_137 ,
sizeof( V_137 ) , log ) ;
if ( V_57 )
goto V_140;
F_83 ( V_142 , & V_137 . V_24 -> V_143 ) ;
F_56 ( & V_137 . V_24 -> V_102 ) ;
return 0 ;
V_140:
F_84 ( V_137 . V_24 ) ;
return V_57 ;
}
int F_85 ( const struct V_96 * V_137 ,
struct V_39 * V_40 )
{
struct V_116 * V_144 ;
V_144 = F_86 ( V_40 , V_141 ) ;
if ( ! V_144 )
return - V_46 ;
if ( V_137 -> V_110 && F_87 ( V_40 , V_124 ) )
return - V_46 ;
if ( F_5 ( V_47 ) &&
F_16 ( V_40 , V_125 , V_137 -> V_37 . V_38 ) )
return - V_46 ;
if ( F_5 ( V_25 ) && V_137 -> V_26 . V_53 &&
F_17 ( V_40 , V_126 , sizeof( V_137 -> V_26 ) ,
& V_137 -> V_26 ) )
return - V_46 ;
if ( F_5 ( V_50 ) &&
F_61 ( & V_137 -> V_28 . V_53 ) &&
F_17 ( V_40 , V_128 , sizeof( V_137 -> V_28 ) ,
& V_137 -> V_28 ) )
return - V_46 ;
if ( V_137 -> V_61 ) {
if ( F_88 ( V_40 , V_130 ,
V_137 -> V_61 -> V_112 ) )
return - V_46 ;
}
F_89 ( V_40 , V_144 ) ;
return 0 ;
}
void F_90 ( const struct V_116 * V_118 )
{
struct V_96 * V_137 = F_76 ( V_118 ) ;
if ( V_137 -> V_61 )
F_69 ( V_137 -> V_61 -> V_114 ) ;
if ( V_137 -> V_24 )
F_91 ( V_137 -> V_24 ) ;
}
void F_92 ( struct V_71 * V_71 )
{
unsigned int V_145 = sizeof( struct V_27 ) * V_146 ;
struct V_132 * V_132 = F_78 ( V_71 , V_133 ) ;
if ( F_93 ( V_71 , V_145 ) ) {
V_132 -> V_134 = false ;
F_67 ( true , L_14 ) ;
} else {
V_132 -> V_134 = true ;
}
}
void F_94 ( struct V_71 * V_71 )
{
struct V_132 * V_132 = F_78 ( V_71 , V_133 ) ;
if ( V_132 -> V_134 )
F_95 ( V_71 ) ;
}
