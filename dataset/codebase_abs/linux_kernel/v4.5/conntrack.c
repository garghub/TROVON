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
const struct V_41 * V_42 ,
struct V_1 * V_2 , bool V_43 )
{
const struct V_36 * V_37 = & V_44 ;
enum V_9 V_10 ;
struct V_23 * V_24 ;
T_2 V_35 = 0 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( V_24 ) {
V_35 = F_3 ( V_10 ) ;
if ( ! F_11 ( V_24 ) )
V_35 |= V_22 ;
if ( V_24 -> V_45 )
V_35 |= V_20 ;
V_37 = F_12 ( V_24 ) ;
} else if ( V_43 ) {
V_35 = V_12 | V_46 ;
if ( V_42 )
V_37 = & V_42 -> V_37 ;
}
F_8 ( V_2 , V_35 , V_37 , V_24 ) ;
}
void F_13 ( const struct V_39 * V_40 , struct V_1 * V_2 )
{
F_9 ( V_40 , NULL , V_2 , false ) ;
}
int F_14 ( const struct V_1 * V_2 , struct V_39 * V_40 )
{
if ( F_15 ( V_40 , V_47 , V_2 -> V_24 . V_35 ) )
return - V_48 ;
if ( F_5 ( V_49 ) &&
F_16 ( V_40 , V_50 , V_2 -> V_24 . V_37 ) )
return - V_48 ;
if ( F_5 ( V_25 ) &&
F_15 ( V_40 , V_51 , V_2 -> V_24 . V_26 ) )
return - V_48 ;
if ( F_5 ( V_52 ) &&
F_17 ( V_40 , V_53 , sizeof( V_2 -> V_24 . V_28 ) ,
& V_2 -> V_24 . V_28 ) )
return - V_48 ;
return 0 ;
}
static int F_18 ( struct V_39 * V_40 , struct V_1 * V_2 ,
T_3 V_54 , T_3 V_55 )
{
#if F_5 ( V_25 )
enum V_9 V_10 ;
struct V_23 * V_24 ;
T_3 V_56 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( ! V_24 )
return 0 ;
V_56 = V_54 | ( V_24 -> V_26 & ~ ( V_55 ) ) ;
if ( V_24 -> V_26 != V_56 ) {
V_24 -> V_26 = V_56 ;
F_19 ( V_57 , V_24 ) ;
V_2 -> V_24 . V_26 = V_56 ;
}
return 0 ;
#else
return - V_58 ;
#endif
}
static int F_20 ( struct V_39 * V_40 , struct V_1 * V_2 ,
const struct V_27 * V_28 ,
const struct V_27 * V_55 )
{
enum V_9 V_10 ;
struct V_29 * V_30 ;
struct V_23 * V_24 ;
int V_59 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( ! V_24 )
return 0 ;
V_30 = F_7 ( V_24 ) ;
if ( ! V_30 ) {
F_21 ( V_24 ) ;
V_30 = F_7 ( V_24 ) ;
}
if ( ! V_30 || V_30 -> V_32 * sizeof( long ) < V_33 )
return - V_60 ;
V_59 = F_22 ( V_24 , ( T_3 * ) V_28 , ( T_3 * ) V_55 ,
V_33 / sizeof( T_3 ) ) ;
if ( V_59 )
return V_59 ;
F_6 ( V_24 , & V_2 -> V_24 . V_28 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_40 , T_1 V_61 )
{
const struct V_62 * V_63 ;
const struct V_64 * V_65 ;
enum V_9 V_10 ;
unsigned int V_66 ;
struct V_23 * V_24 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( ! V_24 || V_10 == V_14 )
return V_67 ;
V_65 = F_24 ( V_24 ) ;
if ( ! V_65 )
return V_67 ;
V_63 = F_25 ( V_65 -> V_63 ) ;
if ( ! V_63 )
return V_67 ;
switch ( V_61 ) {
case V_5 :
V_66 = F_26 ( V_40 ) ;
break;
case V_7 : {
T_2 V_68 = F_27 ( V_40 ) -> V_68 ;
T_5 V_69 ;
int V_70 ;
V_70 = F_28 ( V_40 , sizeof( struct V_71 ) , & V_68 ,
& V_69 ) ;
if ( V_70 < 0 || ( V_69 & F_29 ( ~ 0x7 ) ) != 0 ) {
F_30 ( L_1 ) ;
return V_67 ;
}
V_66 = V_70 ;
break;
}
default:
F_31 ( 1 , L_2 ) ;
return V_72 ;
}
return V_63 -> V_65 ( V_40 , V_66 , V_24 , V_10 ) ;
}
static int F_32 ( struct V_73 * V_73 , struct V_1 * V_2 ,
T_1 V_37 , struct V_39 * V_40 )
{
struct V_74 V_75 = * F_33 ( V_40 ) ;
int V_59 ;
if ( V_2 -> V_3 . type == F_29 ( V_4 ) ) {
enum V_76 V_77 = V_78 + V_37 ;
memset ( F_34 ( V_40 ) , 0 , sizeof( struct V_79 ) ) ;
V_59 = F_35 ( V_73 , V_40 , V_77 ) ;
if ( V_59 )
return V_59 ;
V_75 . V_80 = F_34 ( V_40 ) -> V_81 ;
#if F_5 ( V_82 )
} else if ( V_2 -> V_3 . type == F_29 ( V_6 ) ) {
enum V_83 V_77 = V_84 + V_37 ;
memset ( F_36 ( V_40 ) , 0 , sizeof( struct V_85 ) ) ;
V_59 = F_37 ( V_73 , V_40 , V_77 ) ;
if ( V_59 )
return V_59 ;
V_2 -> V_86 . V_61 = F_27 ( V_40 ) -> V_68 ;
V_75 . V_80 = F_36 ( V_40 ) -> V_81 ;
#endif
} else {
F_38 ( V_40 ) ;
return - V_87 ;
}
V_2 -> V_86 . V_88 = V_89 ;
F_39 ( V_40 ) ;
V_40 -> V_90 = 1 ;
* F_33 ( V_40 ) = V_75 ;
return 0 ;
}
static struct V_91 *
F_40 ( struct V_73 * V_73 , const struct V_36 * V_37 ,
T_1 V_61 , const struct V_39 * V_40 )
{
struct V_92 V_93 ;
if ( ! F_41 ( V_40 , F_42 ( V_40 ) , V_61 , V_73 , & V_93 ) )
return NULL ;
return F_43 ( V_73 , V_37 , & V_93 ) ;
}
static bool F_44 ( const struct V_73 * V_73 , const struct V_39 * V_40 ,
const struct V_41 * V_42 )
{
enum V_9 V_10 ;
struct V_23 * V_24 ;
V_24 = F_10 ( V_40 , & V_10 ) ;
if ( ! V_24 )
return false ;
if ( ! F_45 ( V_73 , F_46 ( & V_24 -> V_94 ) ) )
return false ;
if ( ! F_47 ( V_42 -> V_24 , F_12 ( V_24 ) ) )
return false ;
if ( V_42 -> V_63 ) {
struct V_64 * V_65 ;
V_65 = F_48 ( V_24 , V_95 ) ;
if ( V_65 && F_49 ( V_65 -> V_63 ) != V_42 -> V_63 )
return false ;
}
return true ;
}
static int F_50 ( struct V_73 * V_73 , struct V_1 * V_2 ,
const struct V_41 * V_42 ,
struct V_39 * V_40 )
{
if ( ! F_44 ( V_73 , V_40 , V_42 ) ) {
struct V_23 * V_96 = V_42 -> V_24 ;
if ( V_96 ) {
if ( V_40 -> V_97 )
F_51 ( V_40 -> V_97 ) ;
F_52 ( & V_96 -> V_98 ) ;
V_40 -> V_97 = & V_96 -> V_98 ;
V_40 -> V_99 = V_21 ;
}
if ( F_53 ( V_73 , V_42 -> V_100 , V_101 ,
V_40 ) != V_67 )
return - V_102 ;
if ( F_23 ( V_40 , V_42 -> V_100 ) != V_67 ) {
F_31 ( 1 , L_3 ) ;
return - V_103 ;
}
}
F_9 ( V_40 , V_42 , V_2 , true ) ;
return 0 ;
}
static int F_54 ( struct V_73 * V_73 , struct V_1 * V_2 ,
const struct V_41 * V_42 ,
struct V_39 * V_40 )
{
struct V_91 * exp ;
exp = F_40 ( V_73 , & V_42 -> V_37 , V_42 -> V_100 , V_40 ) ;
if ( exp ) {
T_2 V_35 ;
V_35 = V_12 | V_22 | V_20 ;
F_8 ( V_2 , V_35 , & V_42 -> V_37 , exp -> V_45 ) ;
} else {
int V_59 ;
V_59 = F_50 ( V_73 , V_2 , V_42 , V_40 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
static int F_55 ( struct V_73 * V_73 , struct V_1 * V_2 ,
const struct V_41 * V_42 ,
struct V_39 * V_40 )
{
T_2 V_35 ;
int V_59 ;
V_35 = V_2 -> V_24 . V_35 ;
if ( V_2 -> V_24 . V_37 == V_42 -> V_37 . V_38 &&
( ( V_35 & V_12 ) && ! ( V_35 & V_22 ) ) ) {
return 0 ;
}
V_59 = F_50 ( V_73 , V_2 , V_42 , V_40 ) ;
if ( V_59 )
return V_59 ;
if ( F_56 ( V_40 ) != V_67 )
return - V_103 ;
return 0 ;
}
static bool F_57 ( const struct V_27 * V_28 )
{
T_4 V_104 ;
for ( V_104 = 0 ; V_104 < sizeof( * V_28 ) ; V_104 ++ )
if ( V_28 -> V_105 [ V_104 ] )
return true ;
return false ;
}
int F_58 ( struct V_73 * V_73 , struct V_39 * V_40 ,
struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
int V_106 ;
int V_59 ;
V_106 = F_42 ( V_40 ) ;
F_59 ( V_40 , V_106 ) ;
if ( V_2 -> V_86 . V_88 != V_89 ) {
V_59 = F_32 ( V_73 , V_2 , V_42 -> V_37 . V_38 , V_40 ) ;
if ( V_59 )
return V_59 ;
}
if ( V_42 -> V_107 )
V_59 = F_55 ( V_73 , V_2 , V_42 , V_40 ) ;
else
V_59 = F_54 ( V_73 , V_2 , V_42 , V_40 ) ;
if ( V_59 )
goto V_59;
if ( V_42 -> V_26 . V_55 ) {
V_59 = F_18 ( V_40 , V_2 , V_42 -> V_26 . V_108 ,
V_42 -> V_26 . V_55 ) ;
if ( V_59 )
goto V_59;
}
if ( F_57 ( & V_42 -> V_28 . V_55 ) )
V_59 = F_20 ( V_40 , V_2 , & V_42 -> V_28 . V_108 ,
& V_42 -> V_28 . V_55 ) ;
V_59:
F_60 ( V_40 , V_106 ) ;
if ( V_59 )
F_38 ( V_40 ) ;
return V_59 ;
}
static int F_61 ( struct V_41 * V_42 , const char * V_109 ,
const struct V_1 * V_2 , bool log )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
V_63 = F_62 ( V_109 , V_42 -> V_100 ,
V_2 -> V_86 . V_61 ) ;
if ( ! V_63 ) {
F_63 ( log , L_4 , V_109 ) ;
return - V_103 ;
}
V_65 = F_64 ( V_42 -> V_24 , V_63 , V_110 ) ;
if ( ! V_65 ) {
F_65 ( V_63 -> V_111 ) ;
return - V_112 ;
}
F_66 ( V_65 -> V_63 , V_63 ) ;
V_42 -> V_63 = V_63 ;
return 0 ;
}
static int F_67 ( const struct V_113 * V_114 , struct V_41 * V_42 ,
const char * * V_63 , bool log )
{
struct V_113 * V_115 ;
int V_116 ;
F_68 (a, attr, rem) {
int type = F_69 ( V_115 ) ;
int V_117 = V_118 [ type ] . V_117 ;
int V_119 = V_118 [ type ] . V_119 ;
if ( type > V_120 ) {
F_63 ( log ,
L_5 ,
type , V_120 ) ;
return - V_103 ;
}
if ( F_70 ( V_115 ) < V_119 || F_70 ( V_115 ) > V_117 ) {
F_63 ( log ,
L_6 ,
type , F_70 ( V_115 ) , V_117 ) ;
return - V_103 ;
}
switch ( type ) {
case V_121 :
V_42 -> V_107 = true ;
break;
#ifdef V_49
case V_122 :
V_42 -> V_37 . V_38 = F_71 ( V_115 ) ;
break;
#endif
#ifdef V_25
case V_123 : {
struct V_124 * V_26 = F_72 ( V_115 ) ;
if ( ! V_26 -> V_55 ) {
F_63 ( log , L_7 ) ;
return - V_103 ;
}
V_42 -> V_26 = * V_26 ;
break;
}
#endif
#ifdef V_52
case V_125 : {
struct V_126 * V_28 = F_72 ( V_115 ) ;
if ( ! F_57 ( & V_28 -> V_55 ) ) {
F_63 ( log , L_8 ) ;
return - V_103 ;
}
V_42 -> V_28 = * V_28 ;
break;
}
#endif
case V_127 :
* V_63 = F_72 ( V_115 ) ;
if ( ! memchr ( * V_63 , '\0' , F_70 ( V_115 ) ) ) {
F_63 ( log , L_9 ) ;
return - V_103 ;
}
break;
default:
F_63 ( log , L_10 ,
type ) ;
return - V_103 ;
}
}
if ( V_116 > 0 ) {
F_63 ( log , L_11 , V_116 ) ;
return - V_103 ;
}
return 0 ;
}
bool F_73 ( struct V_73 * V_73 , enum V_128 V_114 )
{
if ( V_114 == V_47 )
return true ;
if ( F_5 ( V_49 ) &&
V_114 == V_50 )
return true ;
if ( F_5 ( V_25 ) &&
V_114 == V_51 )
return true ;
if ( F_5 ( V_52 ) &&
V_114 == V_53 ) {
struct V_129 * V_129 = F_74 ( V_73 , V_130 ) ;
return V_129 -> V_131 ;
}
return false ;
}
int F_75 ( struct V_73 * V_73 , const struct V_113 * V_114 ,
const struct V_1 * V_2 ,
struct V_132 * * V_133 , bool log )
{
struct V_41 V_134 ;
const char * V_63 = NULL ;
T_1 V_100 ;
int V_59 ;
V_100 = F_1 ( V_2 ) ;
if ( V_100 == V_8 ) {
F_63 ( log , L_12 ) ;
return - V_103 ;
}
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . V_100 = V_100 ;
F_76 ( & V_134 . V_37 , V_135 ,
V_136 , 0 ) ;
V_59 = F_67 ( V_114 , & V_134 , & V_63 , log ) ;
if ( V_59 )
return V_59 ;
V_134 . V_24 = F_77 ( V_73 , & V_134 . V_37 , V_110 ) ;
if ( ! V_134 . V_24 ) {
F_63 ( log , L_13 ) ;
return - V_112 ;
}
F_78 ( V_137 , & V_134 . V_24 -> V_138 ) ;
F_52 ( & V_134 . V_24 -> V_98 ) ;
if ( V_63 ) {
V_59 = F_61 ( & V_134 , V_63 , V_2 , log ) ;
if ( V_59 )
goto V_139;
}
V_59 = F_79 ( V_133 , V_140 , & V_134 ,
sizeof( V_134 ) , log ) ;
if ( V_59 )
goto V_139;
return 0 ;
V_139:
F_80 ( & V_134 ) ;
return V_59 ;
}
int F_81 ( const struct V_41 * V_134 ,
struct V_39 * V_40 )
{
struct V_113 * V_141 ;
V_141 = F_82 ( V_40 , V_140 ) ;
if ( ! V_141 )
return - V_48 ;
if ( V_134 -> V_107 && F_83 ( V_40 , V_121 ) )
return - V_48 ;
if ( F_5 ( V_49 ) &&
F_16 ( V_40 , V_122 , V_134 -> V_37 . V_38 ) )
return - V_48 ;
if ( F_5 ( V_25 ) && V_134 -> V_26 . V_55 &&
F_17 ( V_40 , V_123 , sizeof( V_134 -> V_26 ) ,
& V_134 -> V_26 ) )
return - V_48 ;
if ( F_5 ( V_52 ) &&
F_57 ( & V_134 -> V_28 . V_55 ) &&
F_17 ( V_40 , V_125 , sizeof( V_134 -> V_28 ) ,
& V_134 -> V_28 ) )
return - V_48 ;
if ( V_134 -> V_63 ) {
if ( F_84 ( V_40 , V_127 ,
V_134 -> V_63 -> V_109 ) )
return - V_48 ;
}
F_85 ( V_40 , V_141 ) ;
return 0 ;
}
void F_86 ( const struct V_113 * V_115 )
{
struct V_41 * V_134 = F_72 ( V_115 ) ;
F_80 ( V_134 ) ;
}
static void F_80 ( struct V_41 * V_134 )
{
if ( V_134 -> V_63 )
F_65 ( V_134 -> V_63 -> V_111 ) ;
if ( V_134 -> V_24 )
F_87 ( V_134 -> V_24 ) ;
}
void F_88 ( struct V_73 * V_73 )
{
unsigned int V_142 = sizeof( struct V_27 ) * V_143 ;
struct V_129 * V_129 = F_74 ( V_73 , V_130 ) ;
if ( F_89 ( V_73 , V_142 ) ) {
V_129 -> V_131 = false ;
F_63 ( true , L_14 ) ;
} else {
V_129 -> V_131 = true ;
}
}
void F_90 ( struct V_73 * V_73 )
{
struct V_129 * V_129 = F_74 ( V_73 , V_130 ) ;
if ( V_129 -> V_131 )
F_91 ( V_73 ) ;
}
