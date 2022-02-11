static unsigned int *
F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return & V_2 -> V_6 ;
case V_7 :
return & V_2 -> V_8 ;
}
return NULL ;
}
static bool
F_2 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return V_2 -> V_9 ;
case V_7 :
return V_2 -> V_10 ;
}
return false ;
}
static void
F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
bool V_11 )
{
switch ( V_4 ) {
case V_5 :
V_2 -> V_9 = V_11 ;
break;
case V_7 :
V_2 -> V_10 = V_11 ;
break;
}
}
static int F_4 ( struct V_12 * V_12 , T_1 V_13 ,
unsigned int V_14 , bool V_15 ,
enum V_3 V_4 )
{
char V_16 [ V_17 ] ;
bool V_18 = false ;
int V_19 ;
if ( V_4 == V_5 )
V_18 = true ;
F_5 ( V_16 , V_13 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
if ( V_19 )
return V_19 ;
F_8 ( V_16 , V_14 , V_15 ,
V_18 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
int F_10 ( struct V_12 * V_12 ,
struct V_1 * V_2 ,
enum V_3 V_4 , T_2 * V_22 )
{
char V_23 [ V_24 ] ;
unsigned int * V_25 ;
bool V_11 ;
int V_19 ;
V_11 = F_2 ( V_2 , V_4 ) ;
if ( ! V_11 )
return - V_26 ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( ! V_25 )
return - V_26 ;
F_11 ( V_23 , * V_25 ,
V_27 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_28 ) , V_23 ) ;
if ( V_19 )
return V_19 ;
* V_22 = F_12 ( V_23 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_12 ,
unsigned int V_14 )
{
char V_23 [ V_24 ] ;
F_11 ( V_23 , V_14 ,
V_29 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_28 ) , V_23 ) ;
}
int F_14 ( struct V_12 * V_12 ,
struct V_1 * V_2 ,
enum V_3 V_4 )
{
unsigned int * V_25 ;
int V_19 ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( ! V_25 )
return - V_26 ;
V_19 = F_15 ( V_12 , V_30 ,
V_25 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_13 ( V_12 , * V_25 ) ;
if ( V_19 )
goto V_31;
V_19 = F_4 ( V_12 , V_2 -> V_13 ,
* V_25 , true , V_4 ) ;
if ( V_19 )
goto V_32;
F_3 ( V_2 , V_4 , true ) ;
return 0 ;
V_32:
V_31:
F_16 ( V_12 , V_30 ,
* V_25 ) ;
return V_19 ;
}
void F_17 ( struct V_12 * V_12 ,
struct V_1 * V_2 ,
enum V_3 V_4 )
{
unsigned int * V_25 ;
if ( ! F_2 ( V_2 , V_4 ) )
return;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( F_18 ( ! V_25 ) )
return;
F_4 ( V_12 , V_2 -> V_13 ,
* V_25 , false , V_4 ) ;
F_16 ( V_12 , V_30 ,
* V_25 ) ;
F_3 ( V_2 , V_4 , false ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_33 * V_33 ;
V_33 = F_20 ( V_12 -> V_20 ) ;
if ( ! F_21 ( V_33 ,
V_34 ) )
return;
F_14 ( V_12 , V_2 , V_5 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
F_17 ( V_12 , V_2 , V_5 ) ;
}
static bool
F_23 ( struct V_35 * V_36 ,
struct V_35 * V_37 )
{
return ! memcmp ( V_36 , V_37 , sizeof( * V_36 ) ) ;
}
static bool
F_24 ( struct V_35 * V_38 )
{
struct V_35 V_39 = { { 0 } } ;
return F_23 ( V_38 , & V_39 ) ;
}
static void
F_25 ( struct V_35 * V_36 ,
struct V_35 * V_37 )
{
memcpy ( V_36 , V_37 , sizeof( * V_36 ) ) ;
}
static void
F_26 ( struct V_35 * V_38 ,
unsigned char V_40 )
{
F_27 ( V_40 , V_38 -> V_41 ) ;
}
static void
F_28 ( struct V_35 * V_38 ,
unsigned char V_40 )
{
F_29 ( V_40 , V_38 -> V_41 ) ;
}
static struct V_42 * F_30 ( struct V_43 * V_44 ,
enum V_45 V_46 )
{
struct V_42 * V_47 ;
int V_19 ;
V_47 = F_31 ( sizeof( * V_47 ) , V_48 ) ;
if ( ! V_47 )
return F_32 ( - V_49 ) ;
V_19 = F_33 ( & V_47 -> V_50 , & V_51 ) ;
if ( V_19 )
goto V_52;
F_34 ( & V_47 -> V_53 ) ;
V_47 -> V_46 = V_46 ;
V_47 -> V_44 = V_44 ;
return V_47 ;
V_52:
F_35 ( V_47 ) ;
return F_32 ( V_19 ) ;
}
static void F_36 ( struct V_42 * V_47 )
{
F_18 ( ! F_37 ( & V_47 -> V_53 ) ) ;
F_18 ( V_47 -> V_54 ) ;
F_38 ( & V_47 -> V_50 ) ;
F_35 ( V_47 ) ;
}
static struct V_55 *
F_39 ( struct V_12 * V_12 )
{
static struct V_55 * V_54 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_12 -> V_57 -> V_58 . V_59 ; V_56 ++ ) {
V_54 = & V_12 -> V_57 -> V_58 . V_60 [ V_56 ] ;
if ( V_54 -> V_61 == 0 )
return V_54 ;
}
return NULL ;
}
static int F_40 ( struct V_12 * V_12 ,
struct V_55 * V_54 )
{
char V_62 [ V_63 ] ;
F_41 ( V_62 , true ,
(enum V_64 ) V_54 -> V_46 ,
V_54 -> V_65 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_66 ) , V_62 ) ;
}
static void F_42 ( struct V_12 * V_12 ,
struct V_55 * V_54 )
{
char V_62 [ V_63 ] ;
F_41 ( V_62 , false ,
(enum V_64 ) V_54 -> V_46 ,
V_54 -> V_65 ) ;
F_9 ( V_12 -> V_20 , F_7 ( V_66 ) , V_62 ) ;
}
static int
F_43 ( struct V_12 * V_12 ,
struct V_35 * V_38 ,
struct V_55 * V_54 )
{
char V_67 [ V_68 ] ;
T_3 V_69 = 0 ;
T_3 V_70 ;
T_3 V_71 = V_72 ;
F_44 (prefix, prefix_usage)
V_69 = V_70 ;
F_45 ( V_67 , V_69 , V_54 -> V_65 ) ;
F_44 (prefix, prefix_usage) {
if ( V_70 == 0 )
continue;
F_46 ( V_67 , V_70 , V_71 ,
V_72 ) ;
V_71 = V_70 ;
}
return F_9 ( V_12 -> V_20 , F_7 ( V_73 ) , V_67 ) ;
}
static struct V_55 *
F_47 ( struct V_12 * V_12 ,
struct V_35 * V_38 ,
enum V_45 V_46 )
{
struct V_55 * V_54 ;
int V_19 ;
V_54 = F_39 ( V_12 ) ;
if ( ! V_54 )
return F_32 ( - V_74 ) ;
V_54 -> V_46 = V_46 ;
V_19 = F_40 ( V_12 , V_54 ) ;
if ( V_19 )
return F_32 ( V_19 ) ;
V_19 = F_43 ( V_12 , V_38 ,
V_54 ) ;
if ( V_19 )
goto V_75;
memcpy ( & V_54 -> V_38 , V_38 ,
sizeof( V_54 -> V_38 ) ) ;
return V_54 ;
V_75:
F_42 ( V_12 , V_54 ) ;
return F_32 ( V_19 ) ;
}
static void F_48 ( struct V_12 * V_12 ,
struct V_55 * V_54 )
{
F_42 ( V_12 , V_54 ) ;
}
static struct V_55 *
F_49 ( struct V_12 * V_12 ,
struct V_35 * V_38 ,
enum V_45 V_46 )
{
struct V_55 * V_54 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_12 -> V_57 -> V_58 . V_59 ; V_56 ++ ) {
V_54 = & V_12 -> V_57 -> V_58 . V_60 [ V_56 ] ;
if ( V_54 -> V_61 != 0 &&
V_54 -> V_46 == V_46 &&
F_23 ( & V_54 -> V_38 ,
V_38 ) )
return V_54 ;
}
return F_47 ( V_12 , V_38 , V_46 ) ;
}
static void F_50 ( struct V_55 * V_54 )
{
V_54 -> V_61 ++ ;
}
static void F_51 ( struct V_12 * V_12 ,
struct V_55 * V_54 )
{
if ( -- V_54 -> V_61 == 0 )
F_48 ( V_12 , V_54 ) ;
}
static int F_52 ( struct V_12 * V_12 )
{
struct V_55 * V_54 ;
T_2 V_76 ;
int V_56 ;
if ( ! F_53 ( V_12 -> V_20 , V_77 ) )
return - V_78 ;
V_76 = F_54 ( V_12 -> V_20 , V_77 ) ;
V_12 -> V_57 -> V_58 . V_59 = V_76 - V_79 ;
V_12 -> V_57 -> V_58 . V_60 = F_55 ( V_12 -> V_57 -> V_58 . V_59 ,
sizeof( struct V_55 ) ,
V_48 ) ;
if ( ! V_12 -> V_57 -> V_58 . V_60 )
return - V_49 ;
for ( V_56 = 0 ; V_56 < V_12 -> V_57 -> V_58 . V_59 ; V_56 ++ ) {
V_54 = & V_12 -> V_57 -> V_58 . V_60 [ V_56 ] ;
V_54 -> V_65 = V_56 + V_79 ;
}
return 0 ;
}
static void F_56 ( struct V_12 * V_12 )
{
F_35 ( V_12 -> V_57 -> V_58 . V_60 ) ;
}
static bool F_57 ( const struct V_43 * V_44 )
{
return ! ! V_44 -> V_80 || ! ! V_44 -> V_81 ;
}
static struct V_43 * F_58 ( struct V_12 * V_12 )
{
struct V_43 * V_44 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_82 ) ; V_56 ++ ) {
V_44 = & V_12 -> V_57 -> V_83 [ V_56 ] ;
if ( ! F_57 ( V_44 ) )
return V_44 ;
}
return NULL ;
}
static int F_59 ( struct V_12 * V_12 ,
const struct V_42 * V_47 , T_3 V_84 )
{
char V_85 [ V_86 ] ;
F_60 ( V_85 , V_47 -> V_44 -> V_65 ,
(enum V_64 ) V_47 -> V_46 ,
V_84 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_87 ) , V_85 ) ;
}
static int F_61 ( struct V_12 * V_12 ,
const struct V_42 * V_47 )
{
char V_85 [ V_86 ] ;
F_60 ( V_85 , V_47 -> V_44 -> V_65 ,
(enum V_64 ) V_47 -> V_46 , 0 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_87 ) , V_85 ) ;
}
static T_4 F_62 ( T_4 V_88 )
{
if ( V_88 == V_89 )
V_88 = V_90 ;
return V_88 ;
}
static struct V_43 * F_63 ( struct V_12 * V_12 ,
T_4 V_88 )
{
struct V_43 * V_44 ;
int V_56 ;
V_88 = F_62 ( V_88 ) ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_82 ) ; V_56 ++ ) {
V_44 = & V_12 -> V_57 -> V_83 [ V_56 ] ;
if ( F_57 ( V_44 ) && V_44 -> V_88 == V_88 )
return V_44 ;
}
return NULL ;
}
static struct V_42 * F_64 ( const struct V_43 * V_44 ,
enum V_45 V_46 )
{
switch ( V_46 ) {
case V_91 :
return V_44 -> V_80 ;
case V_92 :
return V_44 -> V_81 ;
}
return NULL ;
}
static struct V_43 * F_65 ( struct V_12 * V_12 ,
T_4 V_88 )
{
struct V_43 * V_44 ;
int V_19 ;
V_44 = F_58 ( V_12 ) ;
if ( ! V_44 )
return F_32 ( - V_74 ) ;
V_44 -> V_80 = F_30 ( V_44 , V_91 ) ;
if ( F_66 ( V_44 -> V_80 ) )
return F_67 ( V_44 -> V_80 ) ;
V_44 -> V_81 = F_30 ( V_44 , V_92 ) ;
if ( F_66 ( V_44 -> V_81 ) ) {
V_19 = F_68 ( V_44 -> V_81 ) ;
goto V_93;
}
V_44 -> V_88 = V_88 ;
return V_44 ;
V_93:
F_36 ( V_44 -> V_80 ) ;
V_44 -> V_80 = NULL ;
return F_32 ( V_19 ) ;
}
static void F_69 ( struct V_43 * V_44 )
{
F_36 ( V_44 -> V_81 ) ;
V_44 -> V_81 = NULL ;
F_36 ( V_44 -> V_80 ) ;
V_44 -> V_80 = NULL ;
}
static struct V_43 * F_70 ( struct V_12 * V_12 , T_4 V_88 )
{
struct V_43 * V_44 ;
V_88 = F_62 ( V_88 ) ;
V_44 = F_63 ( V_12 , V_88 ) ;
if ( ! V_44 )
V_44 = F_65 ( V_12 , V_88 ) ;
return V_44 ;
}
static void F_71 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_94 && F_37 ( & V_44 -> V_80 -> V_53 ) &&
F_37 ( & V_44 -> V_81 -> V_53 ) )
F_69 ( V_44 ) ;
}
static bool
F_72 ( struct V_43 * V_44 ,
enum V_45 V_46 , T_3 V_84 )
{
struct V_42 * V_47 = F_64 ( V_44 , V_46 ) ;
if ( ! F_57 ( V_44 ) )
return false ;
if ( V_47 -> V_54 && V_47 -> V_54 -> V_65 == V_84 )
return true ;
return false ;
}
static int F_73 ( struct V_12 * V_12 ,
struct V_42 * V_47 ,
struct V_55 * V_95 )
{
struct V_55 * V_96 = V_47 -> V_54 ;
int V_19 ;
V_19 = F_59 ( V_12 , V_47 , V_95 -> V_65 ) ;
if ( V_19 )
return V_19 ;
V_47 -> V_54 = V_95 ;
F_50 ( V_95 ) ;
F_51 ( V_12 , V_96 ) ;
return 0 ;
}
static int F_74 ( struct V_12 * V_12 ,
struct V_42 * V_47 ,
struct V_55 * V_95 )
{
struct V_55 * V_96 = V_47 -> V_54 ;
enum V_45 V_46 = V_47 -> V_46 ;
T_3 V_97 , V_98 = V_95 -> V_65 ;
struct V_43 * V_44 ;
int V_56 , V_19 ;
if ( ! V_96 )
goto V_99;
V_97 = V_96 -> V_65 ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_82 ) ; V_56 ++ ) {
V_44 = & V_12 -> V_57 -> V_83 [ V_56 ] ;
if ( ! F_72 ( V_44 , V_46 , V_97 ) )
continue;
V_19 = F_73 ( V_12 ,
F_64 ( V_44 , V_46 ) ,
V_95 ) ;
if ( V_19 )
goto V_100;
}
return 0 ;
V_100:
for ( V_56 -- ; V_56 >= 0 ; V_56 -- ) {
if ( ! F_72 ( V_44 , V_46 , V_98 ) )
continue;
F_73 ( V_12 ,
F_64 ( V_44 , V_46 ) ,
V_96 ) ;
}
return V_19 ;
V_99:
V_19 = F_59 ( V_12 , V_47 , V_95 -> V_65 ) ;
if ( V_19 )
return V_19 ;
V_47 -> V_54 = V_95 ;
F_50 ( V_95 ) ;
return 0 ;
}
static void
F_75 ( struct V_12 * V_12 ,
enum V_45 V_46 ,
struct V_35 * V_101 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_82 ) ; V_56 ++ ) {
struct V_43 * V_44 = & V_12 -> V_57 -> V_83 [ V_56 ] ;
struct V_42 * V_47 = F_64 ( V_44 , V_46 ) ;
unsigned char V_70 ;
if ( ! F_57 ( V_44 ) )
continue;
F_44 (prefix, &fib->prefix_usage)
F_26 ( V_101 , V_70 ) ;
}
}
static int F_76 ( struct V_12 * V_12 )
{
struct V_43 * V_44 ;
T_2 V_102 ;
int V_56 ;
if ( ! F_53 ( V_12 -> V_20 , V_82 ) )
return - V_78 ;
V_102 = F_54 ( V_12 -> V_20 , V_82 ) ;
V_12 -> V_57 -> V_83 = F_55 ( V_102 , sizeof( struct V_43 ) ,
V_48 ) ;
if ( ! V_12 -> V_57 -> V_83 )
return - V_49 ;
for ( V_56 = 0 ; V_56 < V_102 ; V_56 ++ ) {
V_44 = & V_12 -> V_57 -> V_83 [ V_56 ] ;
V_44 -> V_65 = V_56 ;
}
return 0 ;
}
static void F_77 ( struct V_12 * V_12 )
{
F_78 () ;
F_79 ( V_12 ) ;
F_35 ( V_12 -> V_57 -> V_83 ) ;
}
static struct V_103 *
F_80 ( const struct V_103 * V_104 )
{
struct V_105 * V_106 = F_81 ( V_104 ) ;
struct V_107 * V_107 = F_82 ( V_104 ) ;
return F_83 ( V_107 , V_106 -> V_108 . V_109 ) ;
}
static T_4 F_84 ( const struct V_103 * V_104 )
{
struct V_103 * V_110 = F_80 ( V_104 ) ;
if ( V_110 )
return F_85 ( V_110 ) ? : V_90 ;
else
return F_85 ( V_104 ) ? : V_90 ;
}
static struct V_111 *
F_86 ( struct V_12 * V_12 ,
enum V_112 V_113 ,
struct V_103 * V_104 )
{
struct V_114 V_115 ;
const struct V_116 * V_117 ;
struct V_1 * V_2 ;
V_117 = V_12 -> V_57 -> V_118 [ V_113 ] ;
V_115 = (struct V_114 ) {
. V_119 . V_120 = V_104 ,
. V_119 . V_121 = false ,
. V_122 = V_117 -> V_123 ( V_12 , V_104 ) ,
} ;
V_2 = F_87 ( V_12 , & V_115 . V_119 ) ;
if ( F_66 ( V_2 ) )
return F_67 ( V_2 ) ;
return F_88 ( V_2 , struct V_111 , V_119 ) ;
}
static struct V_124 *
F_89 ( struct V_12 * V_12 ,
enum V_112 V_113 ,
struct V_103 * V_104 )
{
struct V_124 * V_125 ;
struct V_124 * V_126 = NULL ;
V_125 = F_31 ( sizeof( * V_125 ) , V_48 ) ;
if ( ! V_125 )
return F_32 ( - V_49 ) ;
V_125 -> V_127 = F_86 ( V_12 , V_113 ,
V_104 ) ;
if ( F_66 ( V_125 -> V_127 ) ) {
V_126 = F_67 ( V_125 -> V_127 ) ;
goto V_128;
}
V_125 -> V_113 = V_113 ;
V_125 -> V_104 = V_104 ;
return V_125 ;
V_128:
F_35 ( V_125 ) ;
return V_126 ;
}
static void
F_90 ( struct V_124 * V_125 )
{
F_18 ( V_125 -> V_61 > 0 ) ;
F_91 ( & V_125 -> V_127 -> V_119 ) ;
F_35 ( V_125 ) ;
}
static T_5
F_92 ( const struct V_103 * V_104 )
{
struct V_105 * V_106 = F_81 ( V_104 ) ;
return V_106 -> V_108 . V_129 . V_130 ;
}
union V_131
F_93 ( enum V_45 V_46 ,
const struct V_103 * V_104 )
{
switch ( V_46 ) {
case V_91 :
return (union V_131 ) {
. V_132 = F_92 ( V_104 ) ,
} ;
case V_92 :
break;
} ;
F_18 ( 1 ) ;
return (union V_131 ) {
. V_132 = 0 ,
} ;
}
T_5 F_94 ( const struct V_103 * V_104 )
{
struct V_105 * V_106 = F_81 ( V_104 ) ;
return V_106 -> V_108 . V_129 . V_133 ;
}
union V_131
F_95 ( enum V_45 V_46 ,
const struct V_103 * V_104 )
{
switch ( V_46 ) {
case V_91 :
return (union V_131 ) {
. V_132 = F_94 ( V_104 ) ,
} ;
case V_92 :
break;
} ;
F_18 ( 1 ) ;
return (union V_131 ) {
. V_132 = 0 ,
} ;
}
static bool F_96 ( const union V_131 * V_134 ,
const union V_131 * V_135 )
{
return ! memcmp ( V_134 , V_135 , sizeof( * V_134 ) ) ;
}
static bool
F_97 ( struct V_12 * V_12 ,
const enum V_45 V_136 ,
union V_131 V_130 ,
T_4 V_137 ,
struct V_124 * V_125 )
{
T_4 V_138 = F_84 ( V_125 -> V_104 ) ;
enum V_112 V_113 = V_125 -> V_113 ;
union V_131 V_139 ;
if ( V_12 -> V_57 -> V_118 [ V_113 ] -> V_136 != V_136 )
return false ;
V_139 = F_93 ( V_136 , V_125 -> V_104 ) ;
return V_138 == V_137 &&
F_96 ( & V_139 , & V_130 ) ;
}
static int
F_98 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
struct V_124 * V_125 )
{
T_4 V_142 ;
int V_19 ;
V_19 = F_99 ( V_12 , 1 , & V_142 ) ;
if ( V_19 )
return V_19 ;
V_125 -> V_143 = V_141 ;
V_141 -> V_144 . V_125 = V_125 ;
V_141 -> V_144 . V_142 = V_142 ;
return 0 ;
}
static void F_100 ( struct V_12 * V_12 ,
struct V_140 * V_141 )
{
V_141 -> V_144 . V_125 -> V_143 = NULL ;
V_141 -> V_144 . V_125 = NULL ;
F_101 ( V_12 , V_141 -> V_144 . V_142 ) ;
}
static void
F_102 ( struct V_12 * V_12 ,
struct V_124 * V_125 )
{
struct V_140 * V_141 = V_125 -> V_143 ;
F_100 ( V_12 , V_141 ) ;
V_141 -> type = V_145 ;
F_103 ( V_12 , V_141 ) ;
}
static void
F_104 ( struct V_12 * V_12 ,
struct V_124 * V_125 ,
struct V_140 * V_143 )
{
if ( F_98 ( V_12 , V_143 ,
V_125 ) )
return;
V_143 -> type = V_146 ;
if ( F_103 ( V_12 , V_143 ) )
F_102 ( V_12 , V_125 ) ;
}
static struct V_140 *
F_105 ( struct V_12 * V_12 ,
struct V_124 * V_125 )
{
static struct V_147 * V_148 ;
const struct V_116 * V_117 ;
struct V_140 * V_141 ;
unsigned char V_149 ;
union V_131 V_130 ;
struct V_42 * V_150 ;
struct V_43 * V_151 ;
const void * V_152 ;
T_6 V_153 ;
T_4 V_137 ;
T_4 V_154 ;
V_117 = V_12 -> V_57 -> V_118 [ V_125 -> V_113 ] ;
V_137 = F_84 ( V_125 -> V_104 ) ;
V_151 = F_63 ( V_12 , V_137 ) ;
if ( ! V_151 )
return NULL ;
V_150 = F_64 ( V_151 , V_117 -> V_136 ) ;
V_130 = F_93 ( V_117 -> V_136 ,
V_125 -> V_104 ) ;
switch ( V_117 -> V_136 ) {
case V_91 :
V_154 = F_106 ( V_130 . V_132 ) ;
V_152 = & V_154 ;
V_153 = 4 ;
V_149 = 32 ;
break;
case V_92 :
F_18 ( 1 ) ;
return NULL ;
}
V_148 = F_107 ( V_150 , V_152 , V_153 ,
V_149 ) ;
if ( ! V_148 || F_37 ( & V_148 -> V_155 ) )
return NULL ;
V_141 = F_108 ( & V_148 -> V_155 ,
struct V_140 , V_156 ) ;
if ( V_141 -> type != V_145 )
return NULL ;
return V_141 ;
}
static struct V_124 *
F_109 ( struct V_12 * V_12 ,
enum V_112 V_113 ,
struct V_103 * V_104 )
{
T_4 V_137 = F_84 ( V_104 ) ;
struct V_157 * V_57 = V_12 -> V_57 ;
struct V_140 * V_143 ;
struct V_124 * V_125 ;
enum V_45 V_136 ;
union V_131 V_130 ;
F_110 (ipip_entry, &mlxsw_sp->router->ipip_list,
ipip_list_node) {
if ( V_125 -> V_104 == V_104 )
goto V_158;
V_136 = V_57 -> V_118 [ V_125 -> V_113 ] -> V_136 ;
V_130 = F_93 ( V_136 , V_104 ) ;
if ( F_97 ( V_12 , V_136 , V_130 ,
V_137 , V_125 ) )
return F_32 ( - V_159 ) ;
}
V_125 = F_89 ( V_12 , V_113 , V_104 ) ;
if ( F_66 ( V_125 ) )
return V_125 ;
V_143 = F_105 ( V_12 , V_125 ) ;
if ( V_143 )
F_104 ( V_12 , V_125 ,
V_143 ) ;
F_111 ( & V_125 -> V_160 ,
& V_12 -> V_57 -> V_161 ) ;
V_158:
++ V_125 -> V_61 ;
return V_125 ;
}
static void
F_112 ( struct V_12 * V_12 ,
struct V_124 * V_125 )
{
if ( -- V_125 -> V_61 == 0 ) {
F_113 ( & V_125 -> V_160 ) ;
if ( V_125 -> V_143 )
F_102 ( V_12 , V_125 ) ;
F_90 ( V_125 ) ;
}
}
static bool
F_114 ( struct V_12 * V_12 ,
const struct V_103 * V_162 ,
enum V_45 V_136 ,
union V_131 V_163 ,
struct V_124 * V_125 )
{
T_4 V_137 = F_85 ( V_162 ) ? : V_90 ;
enum V_112 V_113 = V_125 -> V_113 ;
struct V_103 * V_164 ;
if ( V_12 -> V_57 -> V_118 [ V_113 ] -> V_136 != V_136 )
return false ;
V_164 = F_80 ( V_125 -> V_104 ) ;
return F_97 ( V_12 , V_136 , V_163 ,
V_137 , V_125 ) &&
( ! V_164 || V_164 == V_162 ) ;
}
static struct V_124 *
F_115 ( struct V_12 * V_12 ,
const struct V_103 * V_162 ,
enum V_45 V_136 ,
union V_131 V_163 )
{
struct V_124 * V_125 ;
F_110 (ipip_entry, &mlxsw_sp->router->ipip_list,
ipip_list_node)
if ( F_114 ( V_12 , V_162 ,
V_136 , V_163 ,
V_125 ) )
return V_125 ;
return NULL ;
}
struct V_165 *
F_116 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
if ( ! V_166 ) {
if ( F_37 ( & V_2 -> V_167 ) )
return NULL ;
else
return F_108 ( & V_2 -> V_167 ,
F_117 ( * V_166 ) ,
V_168 ) ;
}
if ( V_166 -> V_168 . V_169 == & V_2 -> V_167 )
return NULL ;
return F_118 ( V_166 , V_168 ) ;
}
int F_119 ( struct V_165 * V_166 )
{
return V_166 -> V_170 . V_171 -> V_172 -> V_173 ;
}
unsigned char *
F_120 ( struct V_165 * V_166 )
{
return V_166 -> V_174 ;
}
T_4 F_121 ( struct V_165 * V_166 )
{
struct V_175 * V_171 ;
V_171 = V_166 -> V_170 . V_171 ;
return F_122 ( * ( ( T_5 * ) V_171 -> V_176 ) ) ;
}
struct V_177 *
F_123 ( struct V_165 * V_166 )
{
struct V_175 * V_171 ;
V_171 = V_166 -> V_170 . V_171 ;
return (struct V_177 * ) & V_171 -> V_176 ;
}
int F_124 ( struct V_12 * V_12 ,
struct V_165 * V_166 ,
T_2 * V_178 )
{
if ( ! V_166 -> V_179 )
return - V_26 ;
return F_125 ( V_12 , V_166 -> V_14 ,
V_178 , NULL ) ;
}
static struct V_165 *
F_126 ( struct V_12 * V_12 , struct V_175 * V_171 ,
T_1 V_2 )
{
struct V_165 * V_166 ;
V_166 = F_31 ( sizeof( * V_166 ) , V_48 ) ;
if ( ! V_166 )
return NULL ;
V_166 -> V_170 . V_171 = V_171 ;
V_166 -> V_2 = V_2 ;
F_34 ( & V_166 -> V_180 ) ;
return V_166 ;
}
static void F_127 ( struct V_165 * V_166 )
{
F_35 ( V_166 ) ;
}
static int
F_128 ( struct V_12 * V_12 ,
struct V_165 * V_166 )
{
return F_129 ( & V_12 -> V_57 -> V_181 ,
& V_166 -> V_182 ,
V_183 ) ;
}
static void
F_130 ( struct V_12 * V_12 ,
struct V_165 * V_166 )
{
F_131 ( & V_12 -> V_57 -> V_181 ,
& V_166 -> V_182 ,
V_183 ) ;
}
static bool
F_132 ( struct V_12 * V_12 ,
struct V_165 * V_166 )
{
struct V_33 * V_33 ;
const char * V_184 ;
switch ( F_119 ( V_166 ) ) {
case V_185 :
V_184 = V_186 ;
break;
case V_187 :
V_184 = V_188 ;
break;
default:
F_18 ( 1 ) ;
return false ;
}
V_33 = F_20 ( V_12 -> V_20 ) ;
return F_21 ( V_33 , V_184 ) ;
}
static void
F_133 ( struct V_12 * V_12 ,
struct V_165 * V_166 )
{
if ( ! F_132 ( V_12 , V_166 ) )
return;
if ( F_134 ( V_12 , & V_166 -> V_14 ) )
return;
V_166 -> V_179 = true ;
}
static void
F_135 ( struct V_12 * V_12 ,
struct V_165 * V_166 )
{
if ( ! V_166 -> V_179 )
return;
F_136 ( V_12 ,
V_166 -> V_14 ) ;
V_166 -> V_179 = false ;
}
static struct V_165 *
F_137 ( struct V_12 * V_12 , struct V_175 * V_171 )
{
struct V_165 * V_166 ;
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_138 ( V_12 , V_171 -> V_120 ) ;
if ( ! V_2 )
return F_32 ( - V_26 ) ;
V_166 = F_126 ( V_12 , V_171 , V_2 -> V_13 ) ;
if ( ! V_166 )
return F_32 ( - V_49 ) ;
V_19 = F_128 ( V_12 , V_166 ) ;
if ( V_19 )
goto V_189;
F_133 ( V_12 , V_166 ) ;
F_139 ( & V_166 -> V_168 , & V_2 -> V_167 ) ;
return V_166 ;
V_189:
F_127 ( V_166 ) ;
return F_32 ( V_19 ) ;
}
static void
F_140 ( struct V_12 * V_12 ,
struct V_165 * V_166 )
{
F_113 ( & V_166 -> V_168 ) ;
F_135 ( V_12 , V_166 ) ;
F_130 ( V_12 , V_166 ) ;
F_127 ( V_166 ) ;
}
static struct V_165 *
F_141 ( struct V_12 * V_12 , struct V_175 * V_171 )
{
struct V_190 V_170 ;
V_170 . V_171 = V_171 ;
return F_142 ( & V_12 -> V_57 -> V_181 ,
& V_170 , V_183 ) ;
}
static void
F_143 ( struct V_12 * V_12 )
{
unsigned long V_191 ;
#if F_144 ( V_192 )
V_191 = F_145 (unsigned long,
NEIGH_VAR(&arp_tbl.parms, DELAY_PROBE_TIME),
NEIGH_VAR(&nd_tbl.parms, DELAY_PROBE_TIME)) ;
#else
V_191 = F_146 ( & V_193 . V_108 , V_194 ) ;
#endif
V_12 -> V_57 -> V_195 . V_191 = F_147 ( V_191 ) ;
}
static void F_148 ( struct V_12 * V_12 ,
char * V_196 ,
int V_197 )
{
struct V_103 * V_120 ;
struct V_175 * V_171 ;
T_5 V_198 ;
T_4 V_199 ;
T_1 V_2 ;
F_149 ( V_196 , V_197 , & V_2 , & V_199 ) ;
if ( ! V_12 -> V_57 -> V_200 [ V_2 ] ) {
F_150 ( V_12 -> V_201 -> V_120 , L_1 ) ;
return;
}
V_198 = F_151 ( V_199 ) ;
V_120 = V_12 -> V_57 -> V_200 [ V_2 ] -> V_120 ;
V_171 = F_152 ( & V_193 , & V_198 , V_120 ) ;
if ( ! V_171 ) {
F_153 ( V_120 , L_2 ,
& V_199 ) ;
return;
}
F_154 ( V_120 , L_3 , & V_199 ) ;
F_155 ( V_171 , NULL ) ;
F_156 ( V_171 ) ;
}
static void F_157 ( struct V_12 * V_12 ,
char * V_196 ,
int V_202 )
{
struct V_103 * V_120 ;
struct V_175 * V_171 ;
struct V_177 V_199 ;
T_1 V_2 ;
F_158 ( V_196 , V_202 , & V_2 ,
( char * ) & V_199 ) ;
if ( ! V_12 -> V_57 -> V_200 [ V_2 ] ) {
F_150 ( V_12 -> V_201 -> V_120 , L_1 ) ;
return;
}
V_120 = V_12 -> V_57 -> V_200 [ V_2 ] -> V_120 ;
V_171 = F_152 ( & V_203 , & V_199 , V_120 ) ;
if ( ! V_171 ) {
F_153 ( V_120 , L_4 ,
& V_199 ) ;
return;
}
F_154 ( V_120 , L_5 , & V_199 ) ;
F_155 ( V_171 , NULL ) ;
F_156 ( V_171 ) ;
}
static void F_157 ( struct V_12 * V_12 ,
char * V_196 ,
int V_202 )
{
}
static void F_159 ( struct V_12 * V_12 ,
char * V_196 ,
int V_202 )
{
T_3 V_204 ;
int V_56 ;
V_204 = F_160 ( V_196 ,
V_202 ) ;
V_204 ++ ;
for ( V_56 = 0 ; V_56 < V_204 ; V_56 ++ ) {
int V_197 ;
V_197 = V_202 * V_205 + V_56 ;
F_148 ( V_12 , V_196 ,
V_197 ) ;
}
}
static void F_161 ( struct V_12 * V_12 ,
char * V_196 ,
int V_202 )
{
F_157 ( V_12 , V_196 ,
V_202 ) ;
}
static void F_162 ( struct V_12 * V_12 ,
char * V_196 , int V_202 )
{
switch ( F_163 ( V_196 , V_202 ) ) {
case V_206 :
F_159 ( V_12 , V_196 ,
V_202 ) ;
break;
case V_207 :
F_161 ( V_12 , V_196 ,
V_202 ) ;
break;
}
}
static bool F_164 ( char * V_196 )
{
T_3 V_208 , V_209 , V_204 ;
V_208 = F_165 ( V_196 ) ;
V_209 = V_208 - 1 ;
if ( V_208 < V_210 )
return false ;
if ( F_163 ( V_196 , V_209 ) ==
V_207 )
return true ;
V_204 = F_160 ( V_196 ,
V_209 ) ;
if ( ++ V_204 == V_205 )
return true ;
return false ;
}
static int
F_166 ( struct V_12 * V_12 ,
char * V_196 ,
enum V_211 type )
{
int V_56 , V_208 ;
int V_19 ;
F_167 () ;
do {
F_168 ( V_196 , type ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_212 ) ,
V_196 ) ;
if ( V_19 ) {
F_150 ( V_12 -> V_201 -> V_120 , L_6 ) ;
break;
}
V_208 = F_165 ( V_196 ) ;
for ( V_56 = 0 ; V_56 < V_208 ; V_56 ++ )
F_162 ( V_12 , V_196 ,
V_56 ) ;
} while ( F_164 ( V_196 ) );
F_169 () ;
return V_19 ;
}
static int F_170 ( struct V_12 * V_12 )
{
enum V_211 type ;
char * V_196 ;
int V_19 ;
V_196 = F_171 ( V_213 , V_48 ) ;
if ( ! V_196 )
return - V_49 ;
type = V_206 ;
V_19 = F_166 ( V_12 , V_196 , type ) ;
if ( V_19 )
goto V_214;
type = V_207 ;
V_19 = F_166 ( V_12 , V_196 , type ) ;
V_214:
F_35 ( V_196 ) ;
return V_19 ;
}
static void F_172 ( struct V_12 * V_12 )
{
struct V_165 * V_166 ;
F_167 () ;
F_110 (neigh_entry, &mlxsw_sp->router->nexthop_neighs_list,
nexthop_neighs_list_node)
F_155 ( V_166 -> V_170 . V_171 , NULL ) ;
F_169 () ;
}
static void
F_173 ( struct V_12 * V_12 )
{
unsigned long V_191 = V_12 -> V_57 -> V_195 . V_191 ;
F_174 ( & V_12 -> V_57 -> V_195 . V_215 ,
F_175 ( V_191 ) ) ;
}
static void F_176 ( struct V_216 * V_217 )
{
struct V_157 * V_57 ;
int V_19 ;
V_57 = F_88 ( V_217 , struct V_157 ,
V_195 . V_215 . V_217 ) ;
V_19 = F_170 ( V_57 -> V_12 ) ;
if ( V_19 )
F_177 ( V_57 -> V_12 -> V_201 -> V_120 , L_7 ) ;
F_172 ( V_57 -> V_12 ) ;
F_173 ( V_57 -> V_12 ) ;
}
static void F_178 ( struct V_216 * V_217 )
{
struct V_165 * V_166 ;
struct V_157 * V_57 ;
V_57 = F_88 ( V_217 , struct V_157 ,
V_218 . V_217 ) ;
F_167 () ;
F_110 (neigh_entry, &router->nexthop_neighs_list,
nexthop_neighs_list_node)
if ( ! V_166 -> V_219 )
F_155 ( V_166 -> V_170 . V_171 , NULL ) ;
F_169 () ;
F_174 ( & V_57 -> V_218 ,
V_220 ) ;
}
static enum V_221 F_179 ( bool V_222 )
{
return V_222 ? V_223 :
V_224 ;
}
static void
F_180 ( struct V_12 * V_12 ,
struct V_165 * V_166 ,
enum V_221 V_225 )
{
struct V_175 * V_171 = V_166 -> V_170 . V_171 ;
T_4 V_199 = F_122 ( * ( ( T_5 * ) V_171 -> V_176 ) ) ;
char V_226 [ V_227 ] ;
F_181 ( V_226 , V_225 , V_166 -> V_2 , V_166 -> V_174 ,
V_199 ) ;
if ( V_166 -> V_179 )
F_182 ( V_226 ,
V_166 -> V_14 ) ;
F_9 ( V_12 -> V_20 , F_7 ( V_228 ) , V_226 ) ;
}
static void
F_183 ( struct V_12 * V_12 ,
struct V_165 * V_166 ,
enum V_221 V_225 )
{
struct V_175 * V_171 = V_166 -> V_170 . V_171 ;
char V_226 [ V_227 ] ;
const char * V_199 = V_171 -> V_176 ;
F_184 ( V_226 , V_225 , V_166 -> V_2 , V_166 -> V_174 ,
V_199 ) ;
if ( V_166 -> V_179 )
F_182 ( V_226 ,
V_166 -> V_14 ) ;
F_9 ( V_12 -> V_20 , F_7 ( V_228 ) , V_226 ) ;
}
bool F_185 ( struct V_165 * V_166 )
{
struct V_175 * V_171 = V_166 -> V_170 . V_171 ;
if ( F_186 ( (struct V_177 * ) & V_171 -> V_176 ) &
V_229 )
return true ;
return false ;
}
static void
F_187 ( struct V_12 * V_12 ,
struct V_165 * V_166 ,
bool V_222 )
{
if ( ! V_222 && ! V_166 -> V_219 )
return;
V_166 -> V_219 = V_222 ;
if ( V_166 -> V_170 . V_171 -> V_172 -> V_173 == V_185 ) {
F_180 ( V_12 , V_166 ,
F_179 ( V_222 ) ) ;
} else if ( V_166 -> V_170 . V_171 -> V_172 -> V_173 == V_187 ) {
if ( F_185 ( V_166 ) )
return;
F_183 ( V_12 , V_166 ,
F_179 ( V_222 ) ) ;
} else {
F_188 ( 1 ) ;
}
}
void
F_189 ( struct V_12 * V_12 ,
struct V_165 * V_166 ,
bool V_222 )
{
if ( V_222 )
F_133 ( V_12 , V_166 ) ;
else
F_135 ( V_12 , V_166 ) ;
F_187 ( V_12 , V_166 , true ) ;
}
static void F_190 ( struct V_216 * V_217 )
{
struct V_230 * V_231 =
F_88 ( V_217 , struct V_230 , V_217 ) ;
struct V_12 * V_12 = V_231 -> V_12 ;
struct V_165 * V_166 ;
struct V_175 * V_171 = V_231 -> V_171 ;
unsigned char V_174 [ V_232 ] ;
bool V_233 ;
T_3 V_234 , V_235 ;
F_191 ( & V_171 -> V_236 ) ;
memcpy ( V_174 , V_171 -> V_174 , V_232 ) ;
V_234 = V_171 -> V_234 ;
V_235 = V_171 -> V_235 ;
F_192 ( & V_171 -> V_236 ) ;
F_167 () ;
V_233 = V_234 & V_237 && ! V_235 ;
V_166 = F_141 ( V_12 , V_171 ) ;
if ( ! V_233 && ! V_166 )
goto V_214;
if ( ! V_166 ) {
V_166 = F_137 ( V_12 , V_171 ) ;
if ( F_66 ( V_166 ) )
goto V_214;
}
memcpy ( V_166 -> V_174 , V_174 , V_232 ) ;
F_187 ( V_12 , V_166 , V_233 ) ;
F_193 ( V_12 , V_166 , ! V_233 ) ;
if ( ! V_166 -> V_219 && F_37 ( & V_166 -> V_180 ) )
F_140 ( V_12 , V_166 ) ;
V_214:
F_169 () ;
F_156 ( V_171 ) ;
F_35 ( V_231 ) ;
}
int F_194 ( struct V_238 * V_239 ,
unsigned long V_240 , void * V_241 )
{
struct V_230 * V_231 ;
struct V_242 * V_242 ;
struct V_12 * V_12 ;
unsigned long V_191 ;
struct V_243 * V_244 ;
struct V_175 * V_171 ;
switch ( V_240 ) {
case V_245 :
V_244 = V_241 ;
if ( ! V_244 -> V_120 || ( V_244 -> V_172 -> V_173 != V_185 &&
V_244 -> V_172 -> V_173 != V_187 ) )
return V_246 ;
V_242 = F_195 ( V_244 -> V_120 ) ;
if ( ! V_242 )
return V_246 ;
V_12 = V_242 -> V_12 ;
V_191 = F_147 ( F_146 ( V_244 , V_194 ) ) ;
V_12 -> V_57 -> V_195 . V_191 = V_191 ;
F_196 ( V_242 ) ;
break;
case V_247 :
V_171 = V_241 ;
if ( V_171 -> V_172 -> V_173 != V_185 && V_171 -> V_172 -> V_173 != V_187 )
return V_246 ;
V_242 = F_195 ( V_171 -> V_120 ) ;
if ( ! V_242 )
return V_246 ;
V_231 = F_31 ( sizeof( * V_231 ) , V_248 ) ;
if ( ! V_231 ) {
F_196 ( V_242 ) ;
return V_249 ;
}
F_197 ( & V_231 -> V_217 , F_190 ) ;
V_231 -> V_12 = V_242 -> V_12 ;
V_231 -> V_171 = V_171 ;
F_198 ( V_171 ) ;
F_199 ( & V_231 -> V_217 ) ;
F_196 ( V_242 ) ;
break;
}
return V_246 ;
}
static int F_200 ( struct V_12 * V_12 )
{
int V_19 ;
V_19 = F_33 ( & V_12 -> V_57 -> V_181 ,
& V_183 ) ;
if ( V_19 )
return V_19 ;
F_143 ( V_12 ) ;
F_201 ( & V_12 -> V_57 -> V_195 . V_215 ,
F_176 ) ;
F_201 ( & V_12 -> V_57 -> V_218 ,
F_178 ) ;
F_174 ( & V_12 -> V_57 -> V_195 . V_215 , 0 ) ;
F_174 ( & V_12 -> V_57 -> V_218 , 0 ) ;
return 0 ;
}
static void F_202 ( struct V_12 * V_12 )
{
F_203 ( & V_12 -> V_57 -> V_195 . V_215 ) ;
F_203 ( & V_12 -> V_57 -> V_218 ) ;
F_38 ( & V_12 -> V_57 -> V_181 ) ;
}
static void F_204 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
struct V_165 * V_166 , * V_250 ;
F_205 (neigh_entry, tmp, &rif->neigh_list,
rif_list_node) {
F_187 ( V_12 , V_166 , false ) ;
F_140 ( V_12 , V_166 ) ;
}
}
static struct V_251 *
F_206 ( const struct V_252 * V_253 )
{
return V_253 -> V_254 ;
}
static bool
F_207 ( const struct V_252 * V_253 ,
const struct V_177 * V_255 , int V_256 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
const struct V_258 * V_259 ;
V_259 = & V_253 -> V_260 [ V_56 ] ;
if ( V_259 -> V_256 == V_256 &&
F_208 ( V_255 , (struct V_177 * ) V_259 -> V_261 ) )
return true ;
}
return false ;
}
static bool
F_209 ( const struct V_252 * V_253 ,
const struct V_262 * V_263 )
{
struct V_264 * V_264 ;
if ( V_253 -> V_257 != V_263 -> V_265 )
return false ;
F_110 (mlxsw_sp_rt6, &fib6_entry->rt6_list, list) {
struct V_177 * V_255 ;
int V_256 ;
V_256 = V_264 -> V_266 -> V_267 . V_120 -> V_256 ;
V_255 = & V_264 -> V_266 -> V_268 ;
if ( ! F_207 ( V_253 , V_255 , V_256 ) )
return false ;
}
return true ;
}
static int
F_210 ( struct V_269 * V_270 , const void * V_241 )
{
const struct V_271 * V_272 = V_270 -> V_170 ;
const struct V_252 * V_253 = V_241 ;
switch ( V_272 -> V_46 ) {
case V_91 :
return V_272 -> V_273 != F_206 ( V_253 ) ;
case V_92 :
return ! F_209 ( V_253 ,
V_272 -> V_263 ) ;
default:
F_18 ( 1 ) ;
return 1 ;
}
}
static int
F_211 ( const struct V_252 * V_253 )
{
return V_253 -> V_274 -> V_173 ;
}
static T_4 F_212 ( const void * V_275 , T_4 V_276 , T_4 V_277 )
{
const struct V_252 * V_253 = V_275 ;
const struct V_258 * V_259 ;
struct V_251 * V_273 ;
unsigned int V_278 ;
int V_56 ;
switch ( F_211 ( V_253 ) ) {
case V_185 :
V_273 = F_206 ( V_253 ) ;
return F_213 ( & V_273 , sizeof( V_273 ) , V_277 ) ;
case V_187 :
V_278 = V_253 -> V_257 ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
V_278 ^= V_259 -> V_256 ;
}
return F_213 ( & V_278 , sizeof( V_278 ) , V_277 ) ;
default:
F_18 ( 1 ) ;
return 0 ;
}
}
static T_4
F_214 ( struct V_262 * V_263 , T_4 V_277 )
{
unsigned int V_278 = V_263 -> V_265 ;
struct V_264 * V_264 ;
struct V_103 * V_120 ;
F_110 (mlxsw_sp_rt6, &fib6_entry->rt6_list, list) {
V_120 = V_264 -> V_266 -> V_267 . V_120 ;
V_278 ^= V_120 -> V_256 ;
}
return F_213 ( & V_278 , sizeof( V_278 ) , V_277 ) ;
}
static T_4
F_215 ( const void * V_275 , T_4 V_276 , T_4 V_277 )
{
const struct V_271 * V_272 = V_275 ;
switch ( V_272 -> V_46 ) {
case V_91 :
return F_213 ( & V_272 -> V_273 , sizeof( V_272 -> V_273 ) , V_277 ) ;
case V_92 :
return F_214 ( V_272 -> V_263 , V_277 ) ;
default:
F_18 ( 1 ) ;
return 0 ;
}
}
static int F_216 ( struct V_12 * V_12 ,
struct V_252 * V_253 )
{
if ( F_211 ( V_253 ) == V_187 &&
! V_253 -> V_279 )
return 0 ;
return F_129 ( & V_12 -> V_57 -> V_280 ,
& V_253 -> V_182 ,
V_281 ) ;
}
static void F_217 ( struct V_12 * V_12 ,
struct V_252 * V_253 )
{
if ( F_211 ( V_253 ) == V_187 &&
! V_253 -> V_279 )
return;
F_131 ( & V_12 -> V_57 -> V_280 ,
& V_253 -> V_182 ,
V_281 ) ;
}
static struct V_252 *
F_218 ( struct V_12 * V_12 ,
struct V_251 * V_273 )
{
struct V_271 V_272 ;
V_272 . V_46 = V_91 ;
V_272 . V_273 = V_273 ;
return F_142 ( & V_12 -> V_57 -> V_280 ,
& V_272 ,
V_281 ) ;
}
static struct V_252 *
F_219 ( struct V_12 * V_12 ,
struct V_262 * V_263 )
{
struct V_271 V_272 ;
V_272 . V_46 = V_92 ;
V_272 . V_263 = V_263 ;
return F_142 ( & V_12 -> V_57 -> V_280 ,
& V_272 ,
V_281 ) ;
}
static int F_220 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
return F_129 ( & V_12 -> V_57 -> V_282 ,
& V_259 -> V_182 , V_283 ) ;
}
static void F_221 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
F_131 ( & V_12 -> V_57 -> V_282 , & V_259 -> V_182 ,
V_283 ) ;
}
static struct V_258 *
F_222 ( struct V_12 * V_12 ,
struct V_284 V_170 )
{
return F_142 ( & V_12 -> V_57 -> V_282 , & V_170 ,
V_283 ) ;
}
static int F_223 ( struct V_12 * V_12 ,
const struct V_42 * V_47 ,
T_4 V_285 , T_1 V_286 ,
T_4 V_287 ,
T_1 V_288 )
{
char V_289 [ V_290 ] ;
F_224 ( V_289 ,
(enum V_64 ) V_47 -> V_46 ,
V_47 -> V_44 -> V_65 , V_285 , V_286 , V_287 ,
V_288 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_291 ) , V_289 ) ;
}
static int F_225 ( struct V_12 * V_12 ,
struct V_252 * V_253 ,
T_4 V_292 , T_1 V_293 )
{
struct V_140 * V_141 ;
struct V_42 * V_47 = NULL ;
int V_19 ;
F_110 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( V_47 == V_141 -> V_148 -> V_47 )
continue;
V_47 = V_141 -> V_148 -> V_47 ;
V_19 = F_223 ( V_12 , V_47 ,
V_292 ,
V_293 ,
V_253 -> V_285 ,
V_253 -> V_286 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_226 ( struct V_12 * V_12 , T_4 V_285 ,
struct V_258 * V_259 )
{
struct V_165 * V_166 = V_259 -> V_166 ;
char V_294 [ V_295 ] ;
F_227 ( V_294 , V_296 ,
true , V_297 ,
V_285 , V_166 -> V_2 ) ;
F_228 ( V_294 , V_166 -> V_174 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_298 ) , V_294 ) ;
}
static int F_229 ( struct V_12 * V_12 ,
T_4 V_285 ,
struct V_258 * V_259 )
{
const struct V_116 * V_117 ;
V_117 = V_12 -> V_57 -> V_118 [ V_259 -> V_125 -> V_113 ] ;
return V_117 -> V_299 ( V_12 , V_285 , V_259 -> V_125 ) ;
}
static int
F_230 ( struct V_12 * V_12 ,
struct V_252 * V_253 ,
bool V_300 )
{
T_4 V_285 = V_253 -> V_285 ;
struct V_258 * V_259 ;
int V_56 ;
int V_19 ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
if ( ! V_259 -> V_301 ) {
V_259 -> V_302 = 0 ;
continue;
}
if ( V_259 -> V_303 || V_300 ) {
switch ( V_259 -> type ) {
case V_304 :
V_19 = F_226
( V_12 , V_285 , V_259 ) ;
break;
case V_305 :
V_19 = F_229
( V_12 , V_285 , V_259 ) ;
break;
}
if ( V_19 )
return V_19 ;
V_259 -> V_303 = 0 ;
V_259 -> V_302 = 1 ;
}
V_285 ++ ;
}
return 0 ;
}
static int
F_231 ( struct V_12 * V_12 ,
struct V_252 * V_253 )
{
struct V_140 * V_141 ;
int V_19 ;
F_110 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( ! F_232 ( V_141 -> V_148 ,
V_141 ) )
continue;
V_19 = F_103 ( V_12 , V_141 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void
F_233 ( struct V_252 * V_253 )
{
enum V_306 V_225 = V_307 ;
struct V_140 * V_141 ;
F_110 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( ! F_232 ( V_141 -> V_148 ,
V_141 ) )
continue;
F_234 ( V_141 , V_225 , 0 ) ;
}
}
static void
F_235 ( struct V_12 * V_12 ,
struct V_252 * V_253 )
{
struct V_258 * V_259 ;
bool V_308 = false ;
T_4 V_285 ;
T_1 V_286 = 0 ;
bool V_309 ;
T_4 V_292 ;
T_1 V_293 ;
int V_56 ;
int V_19 ;
if ( ! V_253 -> V_279 ) {
F_231 ( V_12 , V_253 ) ;
return;
}
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
if ( V_259 -> V_301 != V_259 -> V_302 ) {
V_308 = true ;
if ( V_259 -> V_301 )
V_259 -> V_303 = 1 ;
}
if ( V_259 -> V_301 )
V_286 ++ ;
}
if ( ! V_308 ) {
V_19 = F_230 ( V_12 , V_253 , false ) ;
if ( V_19 ) {
F_236 ( V_12 -> V_201 -> V_120 , L_8 ) ;
goto V_310;
}
return;
}
if ( ! V_286 )
goto V_310;
V_19 = F_99 ( V_12 , V_286 , & V_285 ) ;
if ( V_19 ) {
F_236 ( V_12 -> V_201 -> V_120 , L_9 ) ;
goto V_310;
}
V_309 = V_253 -> V_311 ;
V_292 = V_253 -> V_285 ;
V_293 = V_253 -> V_286 ;
V_253 -> V_311 = 1 ;
V_253 -> V_285 = V_285 ;
V_253 -> V_286 = V_286 ;
V_19 = F_230 ( V_12 , V_253 , true ) ;
if ( V_19 ) {
F_236 ( V_12 -> V_201 -> V_120 , L_8 ) ;
goto V_310;
}
if ( ! V_309 ) {
V_19 = F_231 ( V_12 , V_253 ) ;
if ( V_19 ) {
F_236 ( V_12 -> V_201 -> V_120 , L_10 ) ;
goto V_310;
}
return;
}
V_19 = F_225 ( V_12 , V_253 ,
V_292 , V_293 ) ;
F_101 ( V_12 , V_292 ) ;
if ( V_19 ) {
F_236 ( V_12 -> V_201 -> V_120 , L_11 ) ;
goto V_310;
}
F_233 ( V_253 ) ;
return;
V_310:
V_309 = V_253 -> V_311 ;
V_253 -> V_311 = 0 ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
V_259 -> V_302 = 0 ;
}
V_19 = F_231 ( V_12 , V_253 ) ;
if ( V_19 )
F_236 ( V_12 -> V_201 -> V_120 , L_12 ) ;
if ( V_309 )
F_101 ( V_12 , V_253 -> V_285 ) ;
}
static void F_237 ( struct V_258 * V_259 ,
bool V_312 )
{
if ( ! V_312 )
V_259 -> V_301 = 1 ;
else if ( V_259 -> V_302 )
V_259 -> V_301 = 0 ;
V_259 -> V_303 = 1 ;
}
static void
F_193 ( struct V_12 * V_12 ,
struct V_165 * V_166 ,
bool V_312 )
{
struct V_258 * V_259 ;
F_110 (nh, &neigh_entry->nexthop_list,
neigh_list_node) {
F_237 ( V_259 , V_312 ) ;
F_235 ( V_12 , V_259 -> V_253 ) ;
}
}
static void F_238 ( struct V_258 * V_259 ,
struct V_1 * V_2 )
{
if ( V_259 -> V_2 )
return;
V_259 -> V_2 = V_2 ;
F_139 ( & V_259 -> V_168 , & V_2 -> V_180 ) ;
}
static void F_239 ( struct V_258 * V_259 )
{
if ( ! V_259 -> V_2 )
return;
F_113 ( & V_259 -> V_168 ) ;
V_259 -> V_2 = NULL ;
}
static int F_240 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
struct V_165 * V_166 ;
struct V_175 * V_171 ;
T_3 V_234 , V_235 ;
int V_19 ;
if ( ! V_259 -> V_253 -> V_279 || V_259 -> V_166 )
return 0 ;
V_171 = F_152 ( V_259 -> V_253 -> V_274 , & V_259 -> V_261 , V_259 -> V_2 -> V_120 ) ;
if ( ! V_171 ) {
V_171 = F_241 ( V_259 -> V_253 -> V_274 , & V_259 -> V_261 ,
V_259 -> V_2 -> V_120 ) ;
if ( F_66 ( V_171 ) )
return F_68 ( V_171 ) ;
F_155 ( V_171 , NULL ) ;
}
V_166 = F_141 ( V_12 , V_171 ) ;
if ( ! V_166 ) {
V_166 = F_137 ( V_12 , V_171 ) ;
if ( F_66 ( V_166 ) ) {
V_19 = - V_26 ;
goto V_313;
}
}
if ( F_37 ( & V_166 -> V_180 ) )
F_111 ( & V_166 -> V_314 ,
& V_12 -> V_57 -> V_315 ) ;
V_259 -> V_166 = V_166 ;
F_111 ( & V_259 -> V_316 , & V_166 -> V_180 ) ;
F_191 ( & V_171 -> V_236 ) ;
V_234 = V_171 -> V_234 ;
V_235 = V_171 -> V_235 ;
F_192 ( & V_171 -> V_236 ) ;
F_237 ( V_259 , ! ( V_234 & V_237 && ! V_235 ) ) ;
return 0 ;
V_313:
F_156 ( V_171 ) ;
return V_19 ;
}
static void F_242 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
struct V_165 * V_166 = V_259 -> V_166 ;
struct V_175 * V_171 ;
if ( ! V_166 )
return;
V_171 = V_166 -> V_170 . V_171 ;
F_237 ( V_259 , true ) ;
F_113 ( & V_259 -> V_316 ) ;
V_259 -> V_166 = NULL ;
if ( F_37 ( & V_166 -> V_180 ) )
F_113 ( & V_166 -> V_314 ) ;
if ( ! V_166 -> V_219 && F_37 ( & V_166 -> V_180 ) )
F_140 ( V_12 , V_166 ) ;
F_156 ( V_171 ) ;
}
static bool F_243 ( const struct V_12 * V_12 ,
const struct V_103 * V_120 ,
enum V_112 * V_317 )
{
struct V_157 * V_57 = V_12 -> V_57 ;
const struct V_116 * V_117 ;
enum V_112 V_113 ;
for ( V_113 = 0 ; V_113 < V_318 ; ++ V_113 ) {
V_117 = V_57 -> V_118 [ V_113 ] ;
if ( V_120 -> type == V_117 -> V_319 ) {
if ( V_317 )
* V_317 = V_113 ;
return true ;
}
}
return false ;
}
static int F_244 ( struct V_12 * V_12 ,
enum V_112 V_113 ,
struct V_258 * V_259 ,
struct V_103 * V_104 )
{
if ( ! V_259 -> V_253 -> V_279 || V_259 -> V_125 )
return 0 ;
V_259 -> V_125 = F_109 ( V_12 , V_113 , V_104 ) ;
if ( F_66 ( V_259 -> V_125 ) )
return F_68 ( V_259 -> V_125 ) ;
F_237 ( V_259 , false ) ;
return 0 ;
}
static void F_245 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
struct V_124 * V_125 = V_259 -> V_125 ;
if ( ! V_125 )
return;
F_237 ( V_259 , true ) ;
F_112 ( V_12 , V_125 ) ;
V_259 -> V_125 = NULL ;
}
static bool F_246 ( const struct V_12 * V_12 ,
const struct V_320 * V_320 ,
enum V_112 * V_321 )
{
struct V_103 * V_120 = V_320 -> V_322 ;
return V_120 &&
V_320 -> V_323 -> V_324 == V_325 &&
F_243 ( V_12 , V_120 , V_321 ) ;
}
static void F_247 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
switch ( V_259 -> type ) {
case V_304 :
F_242 ( V_12 , V_259 ) ;
F_239 ( V_259 ) ;
break;
case V_305 :
F_239 ( V_259 ) ;
F_245 ( V_12 , V_259 ) ;
break;
}
}
static int F_248 ( struct V_12 * V_12 ,
struct V_258 * V_259 ,
struct V_320 * V_320 )
{
struct V_157 * V_57 = V_12 -> V_57 ;
struct V_103 * V_120 = V_320 -> V_322 ;
enum V_112 V_113 ;
struct V_1 * V_2 ;
int V_19 ;
if ( F_246 ( V_12 , V_320 , & V_113 ) &&
V_57 -> V_118 [ V_113 ] -> F_249 ( V_12 , V_120 ,
V_91 ) ) {
V_259 -> type = V_305 ;
V_19 = F_244 ( V_12 , V_113 , V_259 , V_120 ) ;
if ( V_19 )
return V_19 ;
F_238 ( V_259 , & V_259 -> V_125 -> V_127 -> V_119 ) ;
return 0 ;
}
V_259 -> type = V_304 ;
V_2 = F_138 ( V_12 , V_120 ) ;
if ( ! V_2 )
return 0 ;
F_238 ( V_259 , V_2 ) ;
V_19 = F_240 ( V_12 , V_259 ) ;
if ( V_19 )
goto V_326;
return 0 ;
V_326:
F_239 ( V_259 ) ;
return V_19 ;
}
static void F_250 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
F_247 ( V_12 , V_259 ) ;
}
static int F_251 ( struct V_12 * V_12 ,
struct V_252 * V_253 ,
struct V_258 * V_259 ,
struct V_320 * V_320 )
{
struct V_103 * V_120 = V_320 -> V_322 ;
struct V_327 * V_328 ;
int V_19 ;
V_259 -> V_253 = V_253 ;
V_259 -> V_170 . V_320 = V_320 ;
memcpy ( & V_259 -> V_261 , & V_320 -> V_329 , sizeof( V_320 -> V_329 ) ) ;
V_19 = F_220 ( V_12 , V_259 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_120 )
return 0 ;
V_328 = F_252 ( V_120 ) ;
if ( V_328 && F_253 ( V_328 ) &&
V_320 -> V_330 & V_331 )
return 0 ;
V_19 = F_248 ( V_12 , V_259 , V_320 ) ;
if ( V_19 )
goto V_332;
return 0 ;
V_332:
F_221 ( V_12 , V_259 ) ;
return V_19 ;
}
static void F_254 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
F_250 ( V_12 , V_259 ) ;
F_221 ( V_12 , V_259 ) ;
}
static void F_255 ( struct V_12 * V_12 ,
unsigned long V_240 , struct V_320 * V_320 )
{
struct V_284 V_170 ;
struct V_258 * V_259 ;
if ( V_12 -> V_57 -> V_333 )
return;
V_170 . V_320 = V_320 ;
V_259 = F_222 ( V_12 , V_170 ) ;
if ( F_188 ( ! V_259 ) )
return;
switch ( V_240 ) {
case V_334 :
F_248 ( V_12 , V_259 , V_320 ) ;
break;
case V_335 :
F_250 ( V_12 , V_259 ) ;
break;
}
F_235 ( V_12 , V_259 -> V_253 ) ;
}
static void F_256 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
struct V_258 * V_259 , * V_250 ;
F_205 (nh, tmp, &rif->nexthop_list, rif_list_node) {
F_247 ( V_12 , V_259 ) ;
F_235 ( V_12 , V_259 -> V_253 ) ;
}
}
static bool F_257 ( const struct V_12 * V_12 ,
const struct V_251 * V_273 )
{
return V_273 -> V_320 -> V_336 == V_337 ||
F_246 ( V_12 , V_273 -> V_320 , NULL ) ;
}
static struct V_252 *
F_258 ( struct V_12 * V_12 , struct V_251 * V_273 )
{
struct V_252 * V_253 ;
struct V_258 * V_259 ;
struct V_320 * V_320 ;
T_6 V_338 ;
int V_56 ;
int V_19 ;
V_338 = sizeof( * V_253 ) +
V_273 -> V_339 * sizeof( struct V_258 ) ;
V_253 = F_31 ( V_338 , V_48 ) ;
if ( ! V_253 )
return F_32 ( - V_49 ) ;
V_253 -> V_254 = V_273 ;
F_34 ( & V_253 -> V_340 ) ;
V_253 -> V_274 = & V_193 ;
V_253 -> V_279 = F_257 ( V_12 , V_273 ) ;
V_253 -> V_257 = V_273 -> V_339 ;
F_259 ( V_273 ) ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
V_320 = & V_273 -> V_320 [ V_56 ] ;
V_19 = F_251 ( V_12 , V_253 , V_259 , V_320 ) ;
if ( V_19 )
goto V_341;
}
V_19 = F_216 ( V_12 , V_253 ) ;
if ( V_19 )
goto V_342;
F_235 ( V_12 , V_253 ) ;
return V_253 ;
V_342:
V_341:
for ( V_56 -- ; V_56 >= 0 ; V_56 -- ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
F_254 ( V_12 , V_259 ) ;
}
F_260 ( V_273 ) ;
F_35 ( V_253 ) ;
return F_32 ( V_19 ) ;
}
static void
F_261 ( struct V_12 * V_12 ,
struct V_252 * V_253 )
{
struct V_258 * V_259 ;
int V_56 ;
F_217 ( V_12 , V_253 ) ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
F_254 ( V_12 , V_259 ) ;
}
F_235 ( V_12 , V_253 ) ;
F_188 ( V_253 -> V_311 ) ;
F_260 ( F_206 ( V_253 ) ) ;
F_35 ( V_253 ) ;
}
static int F_262 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
struct V_251 * V_273 )
{
struct V_252 * V_253 ;
V_253 = F_218 ( V_12 , V_273 ) ;
if ( ! V_253 ) {
V_253 = F_258 ( V_12 , V_273 ) ;
if ( F_66 ( V_253 ) )
return F_68 ( V_253 ) ;
}
F_111 ( & V_141 -> V_343 , & V_253 -> V_340 ) ;
V_141 -> V_344 = V_253 ;
return 0 ;
}
static void F_263 ( struct V_12 * V_12 ,
struct V_140 * V_141 )
{
struct V_252 * V_253 = V_141 -> V_344 ;
F_113 ( & V_141 -> V_343 ) ;
if ( ! F_37 ( & V_253 -> V_340 ) )
return;
F_261 ( V_12 , V_253 ) ;
}
static bool
F_264 ( const struct V_140 * V_141 )
{
struct V_345 * V_346 ;
V_346 = F_88 ( V_141 , struct V_345 ,
V_119 ) ;
return ! V_346 -> V_347 ;
}
static bool
F_265 ( const struct V_140 * V_141 )
{
struct V_252 * V_344 = V_141 -> V_344 ;
switch ( V_141 -> V_148 -> V_47 -> V_46 ) {
case V_91 :
if ( ! F_264 ( V_141 ) )
return false ;
break;
case V_92 :
break;
}
switch ( V_141 -> type ) {
case V_348 :
return ! ! V_344 -> V_311 ;
case V_349 :
return ! ! V_344 -> V_350 ;
case V_146 :
return true ;
default:
return false ;
}
}
static struct V_258 *
F_266 ( struct V_252 * V_253 ,
const struct V_264 * V_264 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
struct V_258 * V_259 = & V_253 -> V_260 [ V_56 ] ;
struct V_351 * V_266 = V_264 -> V_266 ;
if ( V_259 -> V_2 && V_259 -> V_2 -> V_120 == V_266 -> V_267 . V_120 &&
F_208 ( ( const struct V_177 * ) & V_259 -> V_261 ,
& V_266 -> V_268 ) )
return V_259 ;
continue;
}
return NULL ;
}
static void
F_267 ( struct V_140 * V_141 )
{
struct V_252 * V_253 = V_141 -> V_344 ;
int V_56 ;
if ( V_141 -> type == V_349 ||
V_141 -> type == V_146 ) {
V_253 -> V_260 -> V_170 . V_320 -> V_330 |= V_352 ;
return;
}
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
struct V_258 * V_259 = & V_253 -> V_260 [ V_56 ] ;
if ( V_259 -> V_302 )
V_259 -> V_170 . V_320 -> V_330 |= V_352 ;
else
V_259 -> V_170 . V_320 -> V_330 &= ~ V_352 ;
}
}
static void
F_268 ( struct V_140 * V_141 )
{
struct V_252 * V_253 = V_141 -> V_344 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
struct V_258 * V_259 = & V_253 -> V_260 [ V_56 ] ;
V_259 -> V_170 . V_320 -> V_330 &= ~ V_352 ;
}
}
static void
F_269 ( struct V_140 * V_141 )
{
struct V_262 * V_263 ;
struct V_264 * V_264 ;
V_263 = F_88 ( V_141 , struct V_262 ,
V_119 ) ;
if ( V_141 -> type == V_349 ) {
F_108 ( & V_263 -> V_353 , struct V_264 ,
V_156 ) -> V_266 -> V_354 |= V_352 ;
return;
}
F_110 (mlxsw_sp_rt6, &fib6_entry->rt6_list, list) {
struct V_252 * V_253 = V_141 -> V_344 ;
struct V_258 * V_259 ;
V_259 = F_266 ( V_253 , V_264 ) ;
if ( V_259 && V_259 -> V_302 )
V_264 -> V_266 -> V_354 |= V_352 ;
else
V_264 -> V_266 -> V_354 &= ~ V_352 ;
}
}
static void
F_270 ( struct V_140 * V_141 )
{
struct V_262 * V_263 ;
struct V_264 * V_264 ;
V_263 = F_88 ( V_141 , struct V_262 ,
V_119 ) ;
F_110 (mlxsw_sp_rt6, &fib6_entry->rt6_list, list) {
struct V_351 * V_266 = V_264 -> V_266 ;
V_266 -> V_354 &= ~ V_352 ;
}
}
static void F_271 ( struct V_140 * V_141 )
{
switch ( V_141 -> V_148 -> V_47 -> V_46 ) {
case V_91 :
F_267 ( V_141 ) ;
break;
case V_92 :
F_269 ( V_141 ) ;
break;
}
}
static void
F_272 ( struct V_140 * V_141 )
{
switch ( V_141 -> V_148 -> V_47 -> V_46 ) {
case V_91 :
F_268 ( V_141 ) ;
break;
case V_92 :
F_270 ( V_141 ) ;
break;
}
}
static void
F_234 ( struct V_140 * V_141 ,
enum V_306 V_225 , int V_19 )
{
switch ( V_225 ) {
case V_355 :
return F_272 ( V_141 ) ;
case V_307 :
if ( V_19 )
return;
if ( F_265 ( V_141 ) )
F_271 ( V_141 ) ;
else if ( ! F_265 ( V_141 ) )
F_272 ( V_141 ) ;
return;
default:
return;
}
}
static void
F_273 ( char * V_356 ,
const struct V_140 * V_141 ,
enum V_306 V_225 )
{
struct V_42 * V_47 = V_141 -> V_148 -> V_47 ;
enum V_64 V_46 ;
T_4 * V_357 ;
V_46 = (enum V_64 ) V_47 -> V_46 ;
switch ( V_47 -> V_46 ) {
case V_91 :
V_357 = ( T_4 * ) V_141 -> V_148 -> V_170 . V_358 ;
F_274 ( V_356 , V_46 , V_225 , V_47 -> V_44 -> V_65 ,
V_141 -> V_148 -> V_170 . V_40 ,
* V_357 ) ;
break;
case V_92 :
F_275 ( V_356 , V_46 , V_225 , V_47 -> V_44 -> V_65 ,
V_141 -> V_148 -> V_170 . V_40 ,
V_141 -> V_148 -> V_170 . V_358 ) ;
break;
}
}
static int F_276 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
enum V_306 V_225 )
{
char V_356 [ V_359 ] ;
enum V_360 V_361 ;
T_1 V_362 = 0 ;
T_4 V_363 = 0 ;
T_1 V_286 = 0 ;
if ( F_265 ( V_141 ) ) {
V_361 = V_364 ;
V_363 = V_141 -> V_344 -> V_285 ;
V_286 = V_141 -> V_344 -> V_286 ;
} else {
V_361 = V_365 ;
V_362 = V_366 ;
}
F_273 ( V_356 , V_141 , V_225 ) ;
F_277 ( V_356 , V_361 , V_362 ,
V_363 , V_286 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_367 ) , V_356 ) ;
}
static int F_278 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
enum V_306 V_225 )
{
struct V_1 * V_2 = V_141 -> V_344 -> V_350 ;
enum V_360 V_361 ;
char V_356 [ V_359 ] ;
T_1 V_362 = 0 ;
T_1 V_13 = 0 ;
if ( F_265 ( V_141 ) ) {
V_361 = V_364 ;
V_13 = V_2 -> V_13 ;
} else {
V_361 = V_365 ;
V_362 = V_366 ;
}
F_273 ( V_356 , V_141 , V_225 ) ;
F_279 ( V_356 , V_361 , V_362 ,
V_13 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_367 ) , V_356 ) ;
}
static int F_280 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
enum V_306 V_225 )
{
char V_356 [ V_359 ] ;
F_273 ( V_356 , V_141 , V_225 ) ;
F_281 ( V_356 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_367 ) , V_356 ) ;
}
static int
F_282 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
enum V_306 V_225 )
{
struct V_124 * V_125 = V_141 -> V_144 . V_125 ;
const struct V_116 * V_117 ;
if ( F_18 ( ! V_125 ) )
return - V_26 ;
V_117 = V_12 -> V_57 -> V_118 [ V_125 -> V_113 ] ;
return V_117 -> V_368 ( V_12 , V_125 , V_225 ,
V_141 -> V_144 . V_142 ) ;
}
static int F_283 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
enum V_306 V_225 )
{
switch ( V_141 -> type ) {
case V_348 :
return F_276 ( V_12 , V_141 , V_225 ) ;
case V_349 :
return F_278 ( V_12 , V_141 , V_225 ) ;
case V_145 :
return F_280 ( V_12 , V_141 , V_225 ) ;
case V_146 :
return F_282 ( V_12 ,
V_141 , V_225 ) ;
}
return - V_26 ;
}
static int F_284 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
enum V_306 V_225 )
{
int V_19 = F_283 ( V_12 , V_141 , V_225 ) ;
F_234 ( V_141 , V_225 , V_19 ) ;
return V_19 ;
}
static int F_103 ( struct V_12 * V_12 ,
struct V_140 * V_141 )
{
return F_284 ( V_12 , V_141 ,
V_307 ) ;
}
static int F_285 ( struct V_12 * V_12 ,
struct V_140 * V_141 )
{
return F_284 ( V_12 , V_141 ,
V_355 ) ;
}
static int
F_286 ( struct V_12 * V_12 ,
const struct V_369 * V_370 ,
struct V_140 * V_141 )
{
union V_131 V_199 = { . V_132 = F_151 (fen_info->dst) } ;
struct V_103 * V_120 = V_370 -> V_273 -> V_371 ;
struct V_124 * V_125 ;
struct V_251 * V_273 = V_370 -> V_273 ;
switch ( V_370 -> type ) {
case V_372 :
V_125 = F_115 ( V_12 , V_120 ,
V_91 , V_199 ) ;
if ( V_125 ) {
V_141 -> type = V_146 ;
return F_98 ( V_12 ,
V_141 ,
V_125 ) ;
}
case V_373 :
V_141 -> type = V_145 ;
return 0 ;
case V_374 :
case V_375 :
case V_376 :
V_141 -> type = V_349 ;
return 0 ;
case V_325 :
if ( F_257 ( V_12 , V_273 ) )
V_141 -> type = V_348 ;
else
V_141 -> type = V_349 ;
return 0 ;
default:
return - V_26 ;
}
}
static struct V_345 *
F_287 ( struct V_12 * V_12 ,
struct V_147 * V_148 ,
const struct V_369 * V_370 )
{
struct V_345 * V_346 ;
struct V_140 * V_141 ;
int V_19 ;
V_346 = F_31 ( sizeof( * V_346 ) , V_48 ) ;
if ( ! V_346 )
return F_32 ( - V_49 ) ;
V_141 = & V_346 -> V_119 ;
V_19 = F_286 ( V_12 , V_370 , V_141 ) ;
if ( V_19 )
goto V_377;
V_19 = F_262 ( V_12 , V_141 , V_370 -> V_273 ) ;
if ( V_19 )
goto V_378;
V_346 -> V_379 = V_370 -> V_273 -> V_380 ;
V_346 -> V_88 = V_370 -> V_88 ;
V_346 -> type = V_370 -> type ;
V_346 -> V_347 = V_370 -> V_347 ;
V_141 -> V_148 = V_148 ;
return V_346 ;
V_378:
V_377:
F_35 ( V_346 ) ;
return F_32 ( V_19 ) ;
}
static void F_288 ( struct V_12 * V_12 ,
struct V_345 * V_346 )
{
F_263 ( V_12 , & V_346 -> V_119 ) ;
F_35 ( V_346 ) ;
}
static struct V_345 *
F_289 ( struct V_12 * V_12 ,
const struct V_369 * V_370 )
{
struct V_345 * V_346 ;
struct V_147 * V_148 ;
struct V_42 * V_47 ;
struct V_43 * V_44 ;
V_44 = F_63 ( V_12 , V_370 -> V_88 ) ;
if ( ! V_44 )
return NULL ;
V_47 = F_64 ( V_44 , V_91 ) ;
V_148 = F_107 ( V_47 , & V_370 -> V_267 ,
sizeof( V_370 -> V_267 ) ,
V_370 -> V_381 ) ;
if ( ! V_148 )
return NULL ;
F_110 (fib4_entry, &fib_node->entry_list, common.list) {
if ( V_346 -> V_88 == V_370 -> V_88 &&
V_346 -> V_347 == V_370 -> V_347 &&
V_346 -> type == V_370 -> type &&
F_206 ( V_346 -> V_119 . V_344 ) ==
V_370 -> V_273 ) {
return V_346 ;
}
}
return NULL ;
}
static int F_290 ( struct V_42 * V_47 ,
struct V_147 * V_148 )
{
return F_129 ( & V_47 -> V_50 , & V_148 -> V_182 ,
V_51 ) ;
}
static void F_291 ( struct V_42 * V_47 ,
struct V_147 * V_148 )
{
F_131 ( & V_47 -> V_50 , & V_148 -> V_182 ,
V_51 ) ;
}
static struct V_147 *
F_107 ( struct V_42 * V_47 , const void * V_358 ,
T_6 V_382 , unsigned char V_40 )
{
struct V_383 V_170 ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
memcpy ( V_170 . V_358 , V_358 , V_382 ) ;
V_170 . V_40 = V_40 ;
return F_142 ( & V_47 -> V_50 , & V_170 , V_51 ) ;
}
static struct V_147 *
F_292 ( struct V_42 * V_47 , const void * V_358 ,
T_6 V_382 , unsigned char V_40 )
{
struct V_147 * V_148 ;
V_148 = F_31 ( sizeof( * V_148 ) , V_48 ) ;
if ( ! V_148 )
return NULL ;
F_34 ( & V_148 -> V_155 ) ;
F_139 ( & V_148 -> V_156 , & V_47 -> V_53 ) ;
memcpy ( V_148 -> V_170 . V_358 , V_358 , V_382 ) ;
V_148 -> V_170 . V_40 = V_40 ;
return V_148 ;
}
static void F_293 ( struct V_147 * V_148 )
{
F_113 ( & V_148 -> V_156 ) ;
F_18 ( ! F_37 ( & V_148 -> V_155 ) ) ;
F_35 ( V_148 ) ;
}
static bool
F_232 ( const struct V_147 * V_148 ,
const struct V_140 * V_141 )
{
return F_108 ( & V_148 -> V_155 ,
struct V_140 , V_156 ) == V_141 ;
}
static int F_294 ( struct V_12 * V_12 ,
struct V_42 * V_47 ,
struct V_147 * V_148 )
{
struct V_35 V_101 = { { 0 } } ;
struct V_55 * V_54 ;
int V_19 ;
if ( V_47 -> V_54 )
F_25 ( & V_101 ,
& V_47 -> V_54 -> V_38 ) ;
else
F_75 ( V_12 , V_47 -> V_46 , & V_101 ) ;
F_26 ( & V_101 , V_148 -> V_170 . V_40 ) ;
V_54 = F_49 ( V_12 , & V_101 ,
V_47 -> V_46 ) ;
if ( F_66 ( V_54 ) )
return F_68 ( V_54 ) ;
if ( V_47 -> V_54 && V_47 -> V_54 -> V_65 == V_54 -> V_65 )
return 0 ;
V_19 = F_74 ( V_12 , V_47 , V_54 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static void F_295 ( struct V_12 * V_12 ,
struct V_42 * V_47 )
{
if ( ! F_24 ( & V_47 -> V_38 ) )
return;
F_61 ( V_12 , V_47 ) ;
F_51 ( V_12 , V_47 -> V_54 ) ;
V_47 -> V_54 = NULL ;
}
static void F_296 ( struct V_147 * V_148 )
{
unsigned char V_40 = V_148 -> V_170 . V_40 ;
struct V_42 * V_47 = V_148 -> V_47 ;
if ( V_47 -> V_384 [ V_40 ] ++ == 0 )
F_26 ( & V_47 -> V_38 , V_40 ) ;
}
static void F_297 ( struct V_147 * V_148 )
{
unsigned char V_40 = V_148 -> V_170 . V_40 ;
struct V_42 * V_47 = V_148 -> V_47 ;
if ( -- V_47 -> V_384 [ V_40 ] == 0 )
F_28 ( & V_47 -> V_38 , V_40 ) ;
}
static int F_298 ( struct V_12 * V_12 ,
struct V_147 * V_148 ,
struct V_42 * V_47 )
{
int V_19 ;
V_19 = F_290 ( V_47 , V_148 ) ;
if ( V_19 )
return V_19 ;
V_148 -> V_47 = V_47 ;
V_19 = F_294 ( V_12 , V_47 , V_148 ) ;
if ( V_19 )
goto V_385;
F_296 ( V_148 ) ;
return 0 ;
V_385:
V_148 -> V_47 = NULL ;
F_291 ( V_47 , V_148 ) ;
return V_19 ;
}
static void F_299 ( struct V_12 * V_12 ,
struct V_147 * V_148 )
{
struct V_42 * V_47 = V_148 -> V_47 ;
F_297 ( V_148 ) ;
F_295 ( V_12 , V_47 ) ;
V_148 -> V_47 = NULL ;
F_291 ( V_47 , V_148 ) ;
}
static struct V_147 *
F_300 ( struct V_12 * V_12 , T_4 V_88 , const void * V_358 ,
T_6 V_382 , unsigned char V_40 ,
enum V_45 V_46 )
{
struct V_147 * V_148 ;
struct V_42 * V_47 ;
struct V_43 * V_44 ;
int V_19 ;
V_44 = F_70 ( V_12 , V_88 ) ;
if ( F_66 ( V_44 ) )
return F_67 ( V_44 ) ;
V_47 = F_64 ( V_44 , V_46 ) ;
V_148 = F_107 ( V_47 , V_358 , V_382 , V_40 ) ;
if ( V_148 )
return V_148 ;
V_148 = F_292 ( V_47 , V_358 , V_382 , V_40 ) ;
if ( ! V_148 ) {
V_19 = - V_49 ;
goto V_386;
}
V_19 = F_298 ( V_12 , V_148 , V_47 ) ;
if ( V_19 )
goto V_387;
return V_148 ;
V_387:
F_293 ( V_148 ) ;
V_386:
F_71 ( V_44 ) ;
return F_32 ( V_19 ) ;
}
static void F_301 ( struct V_12 * V_12 ,
struct V_147 * V_148 )
{
struct V_43 * V_44 = V_148 -> V_47 -> V_44 ;
if ( ! F_37 ( & V_148 -> V_155 ) )
return;
F_299 ( V_12 , V_148 ) ;
F_293 ( V_148 ) ;
F_71 ( V_44 ) ;
}
static struct V_345 *
F_302 ( const struct V_147 * V_148 ,
const struct V_345 * V_388 )
{
struct V_345 * V_346 ;
F_110 (fib4_entry, &fib_node->entry_list, common.list) {
if ( V_346 -> V_88 > V_388 -> V_88 )
continue;
if ( V_346 -> V_88 != V_388 -> V_88 )
break;
if ( V_346 -> V_347 > V_388 -> V_347 )
continue;
if ( V_346 -> V_379 >= V_388 -> V_379 ||
V_346 -> V_347 < V_388 -> V_347 )
return V_346 ;
}
return NULL ;
}
static int
F_303 ( struct V_345 * V_346 ,
struct V_345 * V_388 )
{
struct V_147 * V_148 ;
if ( F_18 ( ! V_346 ) )
return - V_26 ;
V_148 = V_346 -> V_119 . V_148 ;
F_304 (fib4_entry, &fib_node->entry_list,
common.list) {
if ( V_346 -> V_88 != V_388 -> V_88 ||
V_346 -> V_347 != V_388 -> V_347 ||
V_346 -> V_379 != V_388 -> V_379 )
break;
}
F_111 ( & V_388 -> V_119 . V_156 , & V_346 -> V_119 . V_156 ) ;
return 0 ;
}
static int
F_305 ( struct V_345 * V_388 ,
bool V_389 , bool V_390 )
{
struct V_147 * V_148 = V_388 -> V_119 . V_148 ;
struct V_345 * V_346 ;
V_346 = F_302 ( V_148 , V_388 ) ;
if ( V_390 )
return F_303 ( V_346 , V_388 ) ;
if ( V_389 && F_18 ( ! V_346 ) )
return - V_26 ;
if ( V_346 ) {
F_111 ( & V_388 -> V_119 . V_156 ,
& V_346 -> V_119 . V_156 ) ;
} else {
struct V_345 * V_391 ;
F_110 (last, &fib_node->entry_list, common.list) {
if ( V_388 -> V_88 > V_391 -> V_88 )
break;
V_346 = V_391 ;
}
if ( V_346 )
F_139 ( & V_388 -> V_119 . V_156 ,
& V_346 -> V_119 . V_156 ) ;
else
F_139 ( & V_388 -> V_119 . V_156 ,
& V_148 -> V_155 ) ;
}
return 0 ;
}
static void
F_306 ( struct V_345 * V_346 )
{
F_113 ( & V_346 -> V_119 . V_156 ) ;
}
static int F_307 ( struct V_12 * V_12 ,
struct V_140 * V_141 )
{
struct V_147 * V_148 = V_141 -> V_148 ;
if ( ! F_232 ( V_148 , V_141 ) )
return 0 ;
if ( ! F_308 ( & V_148 -> V_155 ) ) {
enum V_306 V_225 = V_355 ;
struct V_140 * V_171 = F_118 ( V_141 , V_156 ) ;
F_234 ( V_171 , V_225 , 0 ) ;
}
return F_103 ( V_12 , V_141 ) ;
}
static void F_309 ( struct V_12 * V_12 ,
struct V_140 * V_141 )
{
struct V_147 * V_148 = V_141 -> V_148 ;
if ( ! F_232 ( V_148 , V_141 ) )
return;
if ( ! F_308 ( & V_148 -> V_155 ) ) {
struct V_140 * V_171 = F_118 ( V_141 , V_156 ) ;
enum V_306 V_225 = V_355 ;
F_103 ( V_12 , V_171 ) ;
F_234 ( V_141 , V_225 , 0 ) ;
return;
}
F_285 ( V_12 , V_141 ) ;
}
static int F_310 ( struct V_12 * V_12 ,
struct V_345 * V_346 ,
bool V_389 , bool V_390 )
{
int V_19 ;
V_19 = F_305 ( V_346 , V_389 , V_390 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_307 ( V_12 , & V_346 -> V_119 ) ;
if ( V_19 )
goto V_392;
return 0 ;
V_392:
F_306 ( V_346 ) ;
return V_19 ;
}
static void
F_311 ( struct V_12 * V_12 ,
struct V_345 * V_346 )
{
F_309 ( V_12 , & V_346 -> V_119 ) ;
F_306 ( V_346 ) ;
if ( V_346 -> V_119 . type == V_146 )
F_100 ( V_12 , & V_346 -> V_119 ) ;
}
static void F_312 ( struct V_12 * V_12 ,
struct V_345 * V_346 ,
bool V_389 )
{
struct V_147 * V_148 = V_346 -> V_119 . V_148 ;
struct V_345 * V_393 ;
if ( ! V_389 )
return;
V_393 = F_118 ( V_346 , V_119 . V_156 ) ;
F_311 ( V_12 , V_393 ) ;
F_288 ( V_12 , V_393 ) ;
F_301 ( V_12 , V_148 ) ;
}
static int
F_313 ( struct V_12 * V_12 ,
const struct V_369 * V_370 ,
bool V_389 , bool V_390 )
{
struct V_345 * V_346 ;
struct V_147 * V_148 ;
int V_19 ;
if ( V_12 -> V_57 -> V_333 )
return 0 ;
V_148 = F_300 ( V_12 , V_370 -> V_88 ,
& V_370 -> V_267 , sizeof( V_370 -> V_267 ) ,
V_370 -> V_381 ,
V_91 ) ;
if ( F_66 ( V_148 ) ) {
F_236 ( V_12 -> V_201 -> V_120 , L_13 ) ;
return F_68 ( V_148 ) ;
}
V_346 = F_287 ( V_12 , V_148 , V_370 ) ;
if ( F_66 ( V_346 ) ) {
F_236 ( V_12 -> V_201 -> V_120 , L_14 ) ;
V_19 = F_68 ( V_346 ) ;
goto V_394;
}
V_19 = F_310 ( V_12 , V_346 , V_389 ,
V_390 ) ;
if ( V_19 ) {
F_236 ( V_12 -> V_201 -> V_120 , L_15 ) ;
goto V_395;
}
F_312 ( V_12 , V_346 , V_389 ) ;
return 0 ;
V_395:
F_288 ( V_12 , V_346 ) ;
V_394:
F_301 ( V_12 , V_148 ) ;
return V_19 ;
}
static void F_314 ( struct V_12 * V_12 ,
struct V_369 * V_370 )
{
struct V_345 * V_346 ;
struct V_147 * V_148 ;
if ( V_12 -> V_57 -> V_333 )
return;
V_346 = F_289 ( V_12 , V_370 ) ;
if ( F_18 ( ! V_346 ) )
return;
V_148 = V_346 -> V_119 . V_148 ;
F_311 ( V_12 , V_346 ) ;
F_288 ( V_12 , V_346 ) ;
F_301 ( V_12 , V_148 ) ;
}
static bool F_315 ( const struct V_351 * V_266 )
{
if ( F_186 ( & V_266 -> V_396 . V_358 ) & V_229 )
return true ;
if ( F_186 ( & V_266 -> V_396 . V_358 ) & V_397 )
return true ;
if ( V_266 -> V_398 & V_399 )
return true ;
return false ;
}
static struct V_264 * F_316 ( struct V_351 * V_266 )
{
struct V_264 * V_264 ;
V_264 = F_31 ( sizeof( * V_264 ) , V_48 ) ;
if ( ! V_264 )
return F_32 ( - V_49 ) ;
V_264 -> V_266 = V_266 ;
F_317 ( V_266 ) ;
return V_264 ;
}
static void F_318 ( struct V_351 * V_266 )
{
F_319 ( V_266 ) ;
}
static void F_318 ( struct V_351 * V_266 )
{
}
static void F_320 ( struct V_264 * V_264 )
{
F_318 ( V_264 -> V_266 ) ;
F_35 ( V_264 ) ;
}
static bool F_321 ( const struct V_351 * V_266 )
{
return ( V_266 -> V_398 & ( V_400 | V_401 ) ) == V_400 ;
}
static struct V_351 *
F_322 ( const struct V_262 * V_263 )
{
return F_108 ( & V_263 -> V_353 , struct V_264 ,
V_156 ) -> V_266 ;
}
static struct V_262 *
F_323 ( const struct V_147 * V_148 ,
const struct V_351 * V_402 , bool V_389 )
{
struct V_262 * V_263 ;
if ( ! F_321 ( V_402 ) || V_389 )
return NULL ;
F_110 (fib6_entry, &fib_node->entry_list, common.list) {
struct V_351 * V_266 = F_322 ( V_263 ) ;
if ( V_266 -> V_403 -> V_404 > V_402 -> V_403 -> V_404 )
continue;
if ( V_266 -> V_403 -> V_404 != V_402 -> V_403 -> V_404 )
break;
if ( V_266 -> V_405 < V_402 -> V_405 )
continue;
if ( V_266 -> V_405 == V_402 -> V_405 &&
F_321 ( V_266 ) )
return V_263 ;
if ( V_266 -> V_405 > V_402 -> V_405 )
break;
}
return NULL ;
}
static struct V_264 *
F_324 ( const struct V_262 * V_263 ,
const struct V_351 * V_266 )
{
struct V_264 * V_264 ;
F_110 (mlxsw_sp_rt6, &fib6_entry->rt6_list, list) {
if ( V_264 -> V_266 == V_266 )
return V_264 ;
}
return NULL ;
}
static bool F_325 ( const struct V_12 * V_12 ,
const struct V_351 * V_266 ,
enum V_112 * V_126 )
{
return V_266 -> V_267 . V_120 &&
F_243 ( V_12 , V_266 -> V_267 . V_120 , V_126 ) ;
}
static int F_326 ( struct V_12 * V_12 ,
struct V_252 * V_253 ,
struct V_258 * V_259 ,
const struct V_351 * V_266 )
{
struct V_157 * V_57 = V_12 -> V_57 ;
struct V_103 * V_120 = V_266 -> V_267 . V_120 ;
enum V_112 V_113 ;
struct V_1 * V_2 ;
int V_19 ;
if ( F_325 ( V_12 , V_266 , & V_113 ) &&
V_57 -> V_118 [ V_113 ] -> F_249 ( V_12 , V_120 ,
V_92 ) ) {
V_259 -> type = V_305 ;
V_19 = F_244 ( V_12 , V_113 , V_259 , V_120 ) ;
if ( V_19 )
return V_19 ;
F_238 ( V_259 , & V_259 -> V_125 -> V_127 -> V_119 ) ;
return 0 ;
}
V_259 -> type = V_304 ;
V_2 = F_138 ( V_12 , V_120 ) ;
if ( ! V_2 )
return 0 ;
F_238 ( V_259 , V_2 ) ;
V_19 = F_240 ( V_12 , V_259 ) ;
if ( V_19 )
goto V_332;
return 0 ;
V_332:
F_239 ( V_259 ) ;
return V_19 ;
}
static void F_327 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
F_247 ( V_12 , V_259 ) ;
}
static int F_328 ( struct V_12 * V_12 ,
struct V_252 * V_253 ,
struct V_258 * V_259 ,
const struct V_351 * V_266 )
{
struct V_103 * V_120 = V_266 -> V_267 . V_120 ;
V_259 -> V_253 = V_253 ;
memcpy ( & V_259 -> V_261 , & V_266 -> V_268 , sizeof( V_259 -> V_261 ) ) ;
if ( ! V_120 )
return 0 ;
V_259 -> V_256 = V_120 -> V_256 ;
return F_326 ( V_12 , V_253 , V_259 , V_266 ) ;
}
static void F_329 ( struct V_12 * V_12 ,
struct V_258 * V_259 )
{
F_327 ( V_12 , V_259 ) ;
}
static bool F_330 ( const struct V_12 * V_12 ,
const struct V_351 * V_266 )
{
return V_266 -> V_398 & V_400 ||
F_325 ( V_12 , V_266 , NULL ) ;
}
static struct V_252 *
F_331 ( struct V_12 * V_12 ,
struct V_262 * V_263 )
{
struct V_252 * V_253 ;
struct V_264 * V_264 ;
struct V_258 * V_259 ;
T_6 V_338 ;
int V_56 = 0 ;
int V_19 ;
V_338 = sizeof( * V_253 ) +
V_263 -> V_265 * sizeof( struct V_258 ) ;
V_253 = F_31 ( V_338 , V_48 ) ;
if ( ! V_253 )
return F_32 ( - V_49 ) ;
F_34 ( & V_253 -> V_340 ) ;
#if F_144 ( V_192 )
V_253 -> V_274 = & V_203 ;
#endif
V_264 = F_108 ( & V_263 -> V_353 ,
struct V_264 , V_156 ) ;
V_253 -> V_279 = F_330 ( V_12 , V_264 -> V_266 ) ;
V_253 -> V_257 = V_263 -> V_265 ;
for ( V_56 = 0 ; V_56 < V_253 -> V_257 ; V_56 ++ ) {
struct V_351 * V_266 = V_264 -> V_266 ;
V_259 = & V_253 -> V_260 [ V_56 ] ;
V_19 = F_328 ( V_12 , V_253 , V_259 , V_266 ) ;
if ( V_19 )
goto V_406;
V_264 = F_118 ( V_264 , V_156 ) ;
}
V_19 = F_216 ( V_12 , V_253 ) ;
if ( V_19 )
goto V_342;
F_235 ( V_12 , V_253 ) ;
return V_253 ;
V_342:
V_406:
for ( V_56 -- ; V_56 >= 0 ; V_56 -- ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
F_329 ( V_12 , V_259 ) ;
}
F_35 ( V_253 ) ;
return F_32 ( V_19 ) ;
}
static void
F_332 ( struct V_12 * V_12 ,
struct V_252 * V_253 )
{
struct V_258 * V_259 ;
int V_56 = V_253 -> V_257 ;
F_217 ( V_12 , V_253 ) ;
for ( V_56 -- ; V_56 >= 0 ; V_56 -- ) {
V_259 = & V_253 -> V_260 [ V_56 ] ;
F_329 ( V_12 , V_259 ) ;
}
F_235 ( V_12 , V_253 ) ;
F_18 ( V_253 -> V_311 ) ;
F_35 ( V_253 ) ;
}
static int F_333 ( struct V_12 * V_12 ,
struct V_262 * V_263 )
{
struct V_252 * V_253 ;
V_253 = F_219 ( V_12 , V_263 ) ;
if ( ! V_253 ) {
V_253 = F_331 ( V_12 , V_263 ) ;
if ( F_66 ( V_253 ) )
return F_68 ( V_253 ) ;
}
F_111 ( & V_263 -> V_119 . V_343 ,
& V_253 -> V_340 ) ;
V_263 -> V_119 . V_344 = V_253 ;
return 0 ;
}
static void F_334 ( struct V_12 * V_12 ,
struct V_140 * V_141 )
{
struct V_252 * V_253 = V_141 -> V_344 ;
F_113 ( & V_141 -> V_343 ) ;
if ( ! F_37 ( & V_253 -> V_340 ) )
return;
F_332 ( V_12 , V_253 ) ;
}
static int
F_335 ( struct V_12 * V_12 ,
struct V_262 * V_263 )
{
struct V_252 * V_407 = V_263 -> V_119 . V_344 ;
int V_19 ;
V_263 -> V_119 . V_344 = NULL ;
F_113 ( & V_263 -> V_119 . V_343 ) ;
V_19 = F_333 ( V_12 , V_263 ) ;
if ( V_19 )
goto V_408;
V_19 = F_307 ( V_12 , & V_263 -> V_119 ) ;
if ( V_19 )
goto V_392;
if ( F_37 ( & V_407 -> V_340 ) )
F_332 ( V_12 , V_407 ) ;
return 0 ;
V_392:
F_334 ( V_12 , & V_263 -> V_119 ) ;
V_408:
F_111 ( & V_263 -> V_119 . V_343 ,
& V_407 -> V_340 ) ;
V_263 -> V_119 . V_344 = V_407 ;
return V_19 ;
}
static int
F_336 ( struct V_12 * V_12 ,
struct V_262 * V_263 ,
struct V_351 * V_266 )
{
struct V_264 * V_264 ;
int V_19 ;
V_264 = F_316 ( V_266 ) ;
if ( F_66 ( V_264 ) )
return F_68 ( V_264 ) ;
F_111 ( & V_264 -> V_156 , & V_263 -> V_353 ) ;
V_263 -> V_265 ++ ;
V_19 = F_335 ( V_12 , V_263 ) ;
if ( V_19 )
goto V_409;
return 0 ;
V_409:
V_263 -> V_265 -- ;
F_113 ( & V_264 -> V_156 ) ;
F_320 ( V_264 ) ;
return V_19 ;
}
static void
F_337 ( struct V_12 * V_12 ,
struct V_262 * V_263 ,
struct V_351 * V_266 )
{
struct V_264 * V_264 ;
V_264 = F_324 ( V_263 , V_266 ) ;
if ( F_18 ( ! V_264 ) )
return;
V_263 -> V_265 -- ;
F_113 ( & V_264 -> V_156 ) ;
F_335 ( V_12 , V_263 ) ;
F_320 ( V_264 ) ;
}
static void F_338 ( struct V_12 * V_12 ,
struct V_140 * V_141 ,
const struct V_351 * V_266 )
{
if ( V_266 -> V_398 & ( V_410 | V_411 ) )
V_141 -> type = V_145 ;
else if ( V_266 -> V_398 & V_412 )
V_141 -> type = V_349 ;
else if ( F_330 ( V_12 , V_266 ) )
V_141 -> type = V_348 ;
else
V_141 -> type = V_349 ;
}
static void
F_339 ( struct V_262 * V_263 )
{
struct V_264 * V_264 , * V_250 ;
F_205 (mlxsw_sp_rt6, tmp, &fib6_entry->rt6_list,
list) {
V_263 -> V_265 -- ;
F_113 ( & V_264 -> V_156 ) ;
F_320 ( V_264 ) ;
}
}
static struct V_262 *
F_340 ( struct V_12 * V_12 ,
struct V_147 * V_148 ,
struct V_351 * V_266 )
{
struct V_262 * V_263 ;
struct V_140 * V_141 ;
struct V_264 * V_264 ;
int V_19 ;
V_263 = F_31 ( sizeof( * V_263 ) , V_48 ) ;
if ( ! V_263 )
return F_32 ( - V_49 ) ;
V_141 = & V_263 -> V_119 ;
V_264 = F_316 ( V_266 ) ;
if ( F_66 ( V_264 ) ) {
V_19 = F_68 ( V_264 ) ;
goto V_413;
}
F_338 ( V_12 , V_141 , V_264 -> V_266 ) ;
F_34 ( & V_263 -> V_353 ) ;
F_111 ( & V_264 -> V_156 , & V_263 -> V_353 ) ;
V_263 -> V_265 = 1 ;
V_19 = F_333 ( V_12 , V_263 ) ;
if ( V_19 )
goto V_408;
V_141 -> V_148 = V_148 ;
return V_263 ;
V_408:
F_113 ( & V_264 -> V_156 ) ;
F_320 ( V_264 ) ;
V_413:
F_35 ( V_263 ) ;
return F_32 ( V_19 ) ;
}
static void F_341 ( struct V_12 * V_12 ,
struct V_262 * V_263 )
{
F_334 ( V_12 , & V_263 -> V_119 ) ;
F_339 ( V_263 ) ;
F_18 ( V_263 -> V_265 ) ;
F_35 ( V_263 ) ;
}
static struct V_262 *
F_342 ( const struct V_147 * V_148 ,
const struct V_351 * V_402 , bool V_389 )
{
struct V_262 * V_263 , * V_414 = NULL ;
F_110 (fib6_entry, &fib_node->entry_list, common.list) {
struct V_351 * V_266 = F_322 ( V_263 ) ;
if ( V_266 -> V_403 -> V_404 > V_402 -> V_403 -> V_404 )
continue;
if ( V_266 -> V_403 -> V_404 != V_402 -> V_403 -> V_404 )
break;
if ( V_389 && V_266 -> V_405 == V_402 -> V_405 ) {
if ( F_321 ( V_266 ) ==
F_321 ( V_402 ) )
return V_263 ;
if ( F_321 ( V_402 ) )
V_414 = V_414 ? : V_263 ;
}
if ( V_266 -> V_405 > V_402 -> V_405 )
return V_414 ? : V_263 ;
}
return V_414 ;
}
static int
F_343 ( struct V_262 * V_415 ,
bool V_389 )
{
struct V_147 * V_148 = V_415 -> V_119 . V_148 ;
struct V_351 * V_402 = F_322 ( V_415 ) ;
struct V_262 * V_263 ;
V_263 = F_342 ( V_148 , V_402 , V_389 ) ;
if ( V_389 && F_18 ( ! V_263 ) )
return - V_26 ;
if ( V_263 ) {
F_111 ( & V_415 -> V_119 . V_156 ,
& V_263 -> V_119 . V_156 ) ;
} else {
struct V_262 * V_391 ;
F_110 (last, &fib_node->entry_list, common.list) {
struct V_351 * V_266 = F_322 ( V_391 ) ;
if ( V_402 -> V_403 -> V_404 > V_266 -> V_403 -> V_404 )
break;
V_263 = V_391 ;
}
if ( V_263 )
F_139 ( & V_415 -> V_119 . V_156 ,
& V_263 -> V_119 . V_156 ) ;
else
F_139 ( & V_415 -> V_119 . V_156 ,
& V_148 -> V_155 ) ;
}
return 0 ;
}
static void
F_344 ( struct V_262 * V_263 )
{
F_113 ( & V_263 -> V_119 . V_156 ) ;
}
static int F_345 ( struct V_12 * V_12 ,
struct V_262 * V_263 ,
bool V_389 )
{
int V_19 ;
V_19 = F_343 ( V_263 , V_389 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_307 ( V_12 , & V_263 -> V_119 ) ;
if ( V_19 )
goto V_392;
return 0 ;
V_392:
F_344 ( V_263 ) ;
return V_19 ;
}
static void
F_346 ( struct V_12 * V_12 ,
struct V_262 * V_263 )
{
F_309 ( V_12 , & V_263 -> V_119 ) ;
F_344 ( V_263 ) ;
}
static struct V_262 *
F_347 ( struct V_12 * V_12 ,
const struct V_351 * V_266 )
{
struct V_262 * V_263 ;
struct V_147 * V_148 ;
struct V_42 * V_47 ;
struct V_43 * V_44 ;
V_44 = F_63 ( V_12 , V_266 -> V_403 -> V_404 ) ;
if ( ! V_44 )
return NULL ;
V_47 = F_64 ( V_44 , V_92 ) ;
V_148 = F_107 ( V_47 , & V_266 -> V_396 . V_358 ,
sizeof( V_266 -> V_396 . V_358 ) ,
V_266 -> V_396 . V_416 ) ;
if ( ! V_148 )
return NULL ;
F_110 (fib6_entry, &fib_node->entry_list, common.list) {
struct V_351 * V_417 = F_322 ( V_263 ) ;
if ( V_266 -> V_403 -> V_404 == V_417 -> V_403 -> V_404 &&
V_266 -> V_405 == V_417 -> V_405 &&
F_324 ( V_263 , V_266 ) )
return V_263 ;
}
return NULL ;
}
static void F_348 ( struct V_12 * V_12 ,
struct V_262 * V_263 ,
bool V_389 )
{
struct V_147 * V_148 = V_263 -> V_119 . V_148 ;
struct V_262 * V_393 ;
if ( ! V_389 )
return;
V_393 = F_118 ( V_263 , V_119 . V_156 ) ;
F_346 ( V_12 , V_393 ) ;
F_341 ( V_12 , V_393 ) ;
F_301 ( V_12 , V_148 ) ;
}
static int F_349 ( struct V_12 * V_12 ,
struct V_351 * V_266 , bool V_389 )
{
struct V_262 * V_263 ;
struct V_147 * V_148 ;
int V_19 ;
if ( V_12 -> V_57 -> V_333 )
return 0 ;
if ( V_266 -> V_418 . V_416 )
return - V_26 ;
if ( F_315 ( V_266 ) )
return 0 ;
V_148 = F_300 ( V_12 , V_266 -> V_403 -> V_404 ,
& V_266 -> V_396 . V_358 ,
sizeof( V_266 -> V_396 . V_358 ) ,
V_266 -> V_396 . V_416 ,
V_92 ) ;
if ( F_66 ( V_148 ) )
return F_68 ( V_148 ) ;
V_263 = F_323 ( V_148 , V_266 , V_389 ) ;
if ( V_263 ) {
V_19 = F_336 ( V_12 , V_263 , V_266 ) ;
if ( V_19 )
goto V_419;
return 0 ;
}
V_263 = F_340 ( V_12 , V_148 , V_266 ) ;
if ( F_66 ( V_263 ) ) {
V_19 = F_68 ( V_263 ) ;
goto V_420;
}
V_19 = F_345 ( V_12 , V_263 , V_389 ) ;
if ( V_19 )
goto V_421;
F_348 ( V_12 , V_263 , V_389 ) ;
return 0 ;
V_421:
F_341 ( V_12 , V_263 ) ;
V_420:
V_419:
F_301 ( V_12 , V_148 ) ;
return V_19 ;
}
static void F_350 ( struct V_12 * V_12 ,
struct V_351 * V_266 )
{
struct V_262 * V_263 ;
struct V_147 * V_148 ;
if ( V_12 -> V_57 -> V_333 )
return;
if ( F_315 ( V_266 ) )
return;
V_263 = F_347 ( V_12 , V_266 ) ;
if ( F_18 ( ! V_263 ) )
return;
if ( ! F_308 ( & V_263 -> V_353 ) ) {
F_337 ( V_12 , V_263 , V_266 ) ;
return;
}
V_148 = V_263 -> V_119 . V_148 ;
F_346 ( V_12 , V_263 ) ;
F_341 ( V_12 , V_263 ) ;
F_301 ( V_12 , V_148 ) ;
}
static int F_351 ( struct V_12 * V_12 ,
enum V_64 V_46 ,
T_3 V_84 )
{
char V_62 [ V_63 ] ;
char V_67 [ V_68 ] ;
int V_56 , V_19 ;
F_41 ( V_62 , true , V_46 , V_84 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_66 ) , V_62 ) ;
if ( V_19 )
return V_19 ;
F_45 ( V_67 , 0xff , V_84 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_73 ) , V_67 ) ;
if ( V_19 )
return V_19 ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_82 ) ; V_56 ++ ) {
struct V_43 * V_44 = & V_12 -> V_57 -> V_83 [ V_56 ] ;
char V_85 [ V_86 ] ;
char V_356 [ V_359 ] ;
F_60 ( V_85 , V_44 -> V_65 , V_46 , V_84 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_87 ) ,
V_85 ) ;
if ( V_19 )
return V_19 ;
F_352 ( V_356 , V_46 ,
V_307 , V_44 -> V_65 , 0 ) ;
F_281 ( V_356 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_367 ) ,
V_356 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_353 ( struct V_12 * V_12 )
{
enum V_64 V_46 = V_422 ;
int V_19 ;
V_19 = F_351 ( V_12 , V_46 ,
V_79 ) ;
if ( V_19 )
return V_19 ;
V_46 = V_423 ;
return F_351 ( V_12 , V_46 ,
V_79 + 1 ) ;
}
static void F_354 ( struct V_12 * V_12 ,
struct V_147 * V_148 )
{
struct V_345 * V_346 , * V_250 ;
F_205 (fib4_entry, tmp, &fib_node->entry_list,
common.list) {
bool V_424 = & V_250 -> V_119 . V_156 == & V_148 -> V_155 ;
F_311 ( V_12 , V_346 ) ;
F_288 ( V_12 , V_346 ) ;
F_301 ( V_12 , V_148 ) ;
if ( V_424 )
break;
}
}
static void F_355 ( struct V_12 * V_12 ,
struct V_147 * V_148 )
{
struct V_262 * V_263 , * V_250 ;
F_205 (fib6_entry, tmp, &fib_node->entry_list,
common.list) {
bool V_424 = & V_250 -> V_119 . V_156 == & V_148 -> V_155 ;
F_346 ( V_12 , V_263 ) ;
F_341 ( V_12 , V_263 ) ;
F_301 ( V_12 , V_148 ) ;
if ( V_424 )
break;
}
}
static void F_356 ( struct V_12 * V_12 ,
struct V_147 * V_148 )
{
switch ( V_148 -> V_47 -> V_46 ) {
case V_91 :
F_354 ( V_12 , V_148 ) ;
break;
case V_92 :
F_355 ( V_12 , V_148 ) ;
break;
}
}
static void F_357 ( struct V_12 * V_12 ,
struct V_43 * V_44 ,
enum V_45 V_46 )
{
struct V_42 * V_47 = F_64 ( V_44 , V_46 ) ;
struct V_147 * V_148 , * V_250 ;
F_205 (fib_node, tmp, &fib->node_list, list) {
bool V_424 = & V_250 -> V_156 == & V_47 -> V_53 ;
F_356 ( V_12 , V_148 ) ;
if ( V_424 )
break;
}
}
static void F_79 ( struct V_12 * V_12 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_82 ) ; V_56 ++ ) {
struct V_43 * V_44 = & V_12 -> V_57 -> V_83 [ V_56 ] ;
if ( ! F_57 ( V_44 ) )
continue;
F_357 ( V_12 , V_44 , V_91 ) ;
if ( ! F_57 ( V_44 ) )
continue;
F_357 ( V_12 , V_44 , V_92 ) ;
}
}
static void F_358 ( struct V_12 * V_12 )
{
int V_19 ;
if ( V_12 -> V_57 -> V_333 )
return;
F_236 ( V_12 -> V_201 -> V_120 , L_16 ) ;
F_79 ( V_12 ) ;
V_12 -> V_57 -> V_333 = true ;
V_19 = F_353 ( V_12 ) ;
if ( V_19 )
F_236 ( V_12 -> V_201 -> V_120 , L_17 ) ;
}
static void F_359 ( struct V_216 * V_217 )
{
struct V_425 * V_426 =
F_88 ( V_217 , struct V_425 , V_217 ) ;
struct V_12 * V_12 = V_426 -> V_12 ;
struct V_427 * V_428 ;
bool V_389 , V_390 ;
int V_19 ;
F_167 () ;
switch ( V_426 -> V_240 ) {
case V_429 :
case V_430 :
case V_431 :
V_389 = V_426 -> V_240 == V_429 ;
V_390 = V_426 -> V_240 == V_430 ;
V_19 = F_313 ( V_12 , & V_426 -> V_370 ,
V_389 , V_390 ) ;
if ( V_19 )
F_358 ( V_12 ) ;
F_260 ( V_426 -> V_370 . V_273 ) ;
break;
case V_432 :
F_314 ( V_12 , & V_426 -> V_370 ) ;
F_260 ( V_426 -> V_370 . V_273 ) ;
break;
case V_433 :
case V_434 :
V_428 = V_426 -> V_435 . V_428 ;
if ( ! F_360 ( V_428 ) && ! V_428 -> V_436 )
F_358 ( V_12 ) ;
F_361 ( V_428 ) ;
break;
case V_334 :
case V_335 :
F_255 ( V_12 , V_426 -> V_240 ,
V_426 -> V_437 . V_320 ) ;
F_260 ( V_426 -> V_437 . V_320 -> V_323 ) ;
break;
}
F_169 () ;
F_35 ( V_426 ) ;
}
static void F_362 ( struct V_216 * V_217 )
{
struct V_425 * V_426 =
F_88 ( V_217 , struct V_425 , V_217 ) ;
struct V_12 * V_12 = V_426 -> V_12 ;
struct V_427 * V_428 ;
bool V_389 ;
int V_19 ;
F_167 () ;
switch ( V_426 -> V_240 ) {
case V_429 :
case V_431 :
V_389 = V_426 -> V_240 == V_429 ;
V_19 = F_349 ( V_12 ,
V_426 -> V_438 . V_266 , V_389 ) ;
if ( V_19 )
F_358 ( V_12 ) ;
F_318 ( V_426 -> V_438 . V_266 ) ;
break;
case V_432 :
F_350 ( V_12 , V_426 -> V_438 . V_266 ) ;
F_318 ( V_426 -> V_438 . V_266 ) ;
break;
case V_433 :
case V_434 :
V_428 = V_426 -> V_435 . V_428 ;
if ( ! F_363 ( V_428 ) && ! V_428 -> V_436 )
F_358 ( V_12 ) ;
F_361 ( V_428 ) ;
break;
}
F_169 () ;
F_35 ( V_426 ) ;
}
static void F_364 ( struct V_425 * V_426 ,
struct V_439 * V_440 )
{
switch ( V_426 -> V_240 ) {
case V_429 :
case V_430 :
case V_431 :
case V_432 :
memcpy ( & V_426 -> V_370 , V_440 , sizeof( V_426 -> V_370 ) ) ;
F_259 ( V_426 -> V_370 . V_273 ) ;
break;
case V_433 :
case V_434 :
memcpy ( & V_426 -> V_435 , V_440 , sizeof( V_426 -> V_435 ) ) ;
F_365 ( V_426 -> V_435 . V_428 ) ;
break;
case V_334 :
case V_335 :
memcpy ( & V_426 -> V_437 , V_440 , sizeof( V_426 -> V_437 ) ) ;
F_259 ( V_426 -> V_437 . V_320 -> V_323 ) ;
break;
}
}
static void F_366 ( struct V_425 * V_426 ,
struct V_439 * V_440 )
{
switch ( V_426 -> V_240 ) {
case V_429 :
case V_431 :
case V_432 :
memcpy ( & V_426 -> V_438 , V_440 , sizeof( V_426 -> V_438 ) ) ;
F_317 ( V_426 -> V_438 . V_266 ) ;
break;
case V_433 :
case V_434 :
memcpy ( & V_426 -> V_435 , V_440 , sizeof( V_426 -> V_435 ) ) ;
F_365 ( V_426 -> V_435 . V_428 ) ;
break;
}
}
static int F_367 ( struct V_238 * V_441 ,
unsigned long V_240 , void * V_241 )
{
struct V_425 * V_426 ;
struct V_439 * V_440 = V_241 ;
struct V_157 * V_57 ;
if ( ! F_368 ( V_440 -> V_107 , & V_442 ) ||
( V_440 -> V_173 != V_185 && V_440 -> V_173 != V_187 ) )
return V_246 ;
V_426 = F_31 ( sizeof( * V_426 ) , V_248 ) ;
if ( F_18 ( ! V_426 ) )
return V_249 ;
V_57 = F_88 ( V_441 , struct V_157 , V_443 ) ;
V_426 -> V_12 = V_57 -> V_12 ;
V_426 -> V_240 = V_240 ;
switch ( V_440 -> V_173 ) {
case V_185 :
F_197 ( & V_426 -> V_217 , F_359 ) ;
F_364 ( V_426 , V_440 ) ;
break;
case V_187 :
F_197 ( & V_426 -> V_217 , F_362 ) ;
F_366 ( V_426 , V_440 ) ;
break;
}
F_199 ( & V_426 -> V_217 ) ;
return V_246 ;
}
static struct V_1 *
F_138 ( const struct V_12 * V_12 ,
const struct V_103 * V_120 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_444 ) ; V_56 ++ )
if ( V_12 -> V_57 -> V_200 [ V_56 ] &&
V_12 -> V_57 -> V_200 [ V_56 ] -> V_120 == V_120 )
return V_12 -> V_57 -> V_200 [ V_56 ] ;
return NULL ;
}
static int F_369 ( struct V_12 * V_12 , T_1 V_2 )
{
char V_16 [ V_17 ] ;
int V_19 ;
F_5 ( V_16 , V_2 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
if ( F_188 ( V_19 ) )
return V_19 ;
F_370 ( V_16 , false ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static void F_371 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
F_369 ( V_12 , V_2 -> V_13 ) ;
F_256 ( V_12 , V_2 ) ;
F_204 ( V_12 , V_2 ) ;
}
static bool
F_372 ( struct V_1 * V_2 , struct V_103 * V_120 ,
unsigned long V_240 )
{
struct V_445 * V_445 ;
bool V_446 = true ;
struct V_327 * V_447 ;
switch ( V_240 ) {
case V_448 :
return V_2 == NULL ;
case V_449 :
V_447 = F_252 ( V_120 ) ;
if ( V_447 && V_447 -> V_450 )
V_446 = false ;
V_445 = F_373 ( V_120 ) ;
if ( V_446 && V_445 &&
! F_37 ( & V_445 -> V_451 ) )
V_446 = false ;
if ( V_2 && V_446 &&
! F_374 ( V_2 -> V_120 ) )
return true ;
return false ;
}
return false ;
}
static enum V_452
F_375 ( const struct V_12 * V_12 ,
const struct V_103 * V_120 )
{
enum V_453 type ;
if ( F_243 ( V_12 , V_120 , NULL ) )
return V_454 ;
if ( F_376 ( V_120 ) && F_377 ( F_378 ( V_120 ) ) )
type = V_455 ;
else if ( F_377 ( V_120 ) && F_379 ( V_120 ) )
type = V_455 ;
else if ( F_377 ( V_120 ) )
type = V_456 ;
else
type = V_457 ;
return F_380 ( V_12 , type ) ;
}
static int F_381 ( struct V_12 * V_12 , T_1 * V_458 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_444 ) ; V_56 ++ ) {
if ( ! V_12 -> V_57 -> V_200 [ V_56 ] ) {
* V_458 = V_56 ;
return 0 ;
}
}
return - V_459 ;
}
static struct V_1 * F_382 ( T_6 V_460 , T_1 V_13 ,
T_1 V_461 ,
struct V_103 * V_462 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( V_460 , V_48 ) ;
if ( ! V_2 )
return NULL ;
F_34 ( & V_2 -> V_180 ) ;
F_34 ( & V_2 -> V_167 ) ;
F_383 ( V_2 -> V_358 , V_462 -> V_463 ) ;
V_2 -> V_464 = V_462 -> V_464 ;
V_2 -> V_461 = V_461 ;
V_2 -> V_120 = V_462 ;
V_2 -> V_13 = V_13 ;
return V_2 ;
}
struct V_1 * F_384 ( const struct V_12 * V_12 ,
T_1 V_13 )
{
return V_12 -> V_57 -> V_200 [ V_13 ] ;
}
T_1 F_385 ( const struct V_1 * V_2 )
{
return V_2 -> V_13 ;
}
T_1 F_386 ( const struct V_111 * V_465 )
{
return V_465 -> V_119 . V_13 ;
}
T_1 F_387 ( const struct V_111 * V_465 )
{
return V_465 -> V_466 ;
}
int F_388 ( const struct V_1 * V_2 )
{
return V_2 -> V_120 -> V_256 ;
}
static struct V_1 *
F_87 ( struct V_12 * V_12 ,
const struct V_467 * V_468 )
{
T_4 V_88 = F_85 ( V_468 -> V_120 ) ;
const struct V_469 * V_470 ;
struct V_471 * V_472 = NULL ;
enum V_452 type ;
struct V_1 * V_2 ;
struct V_43 * V_44 ;
T_1 V_13 ;
int V_19 ;
type = F_375 ( V_12 , V_468 -> V_120 ) ;
V_470 = V_12 -> V_57 -> V_473 [ type ] ;
V_44 = F_70 ( V_12 , V_88 ? : V_90 ) ;
if ( F_66 ( V_44 ) )
return F_67 ( V_44 ) ;
V_44 -> V_94 ++ ;
V_19 = F_381 ( V_12 , & V_13 ) ;
if ( V_19 )
goto V_474;
V_2 = F_382 ( V_470 -> V_460 , V_13 , V_44 -> V_65 , V_468 -> V_120 ) ;
if ( ! V_2 ) {
V_19 = - V_49 ;
goto V_475;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_470 = V_470 ;
if ( V_470 -> V_476 ) {
V_472 = V_470 -> V_476 ( V_2 ) ;
if ( F_66 ( V_472 ) ) {
V_19 = F_68 ( V_472 ) ;
goto V_477;
}
V_2 -> V_472 = V_472 ;
}
if ( V_470 -> V_478 )
V_470 -> V_478 ( V_2 , V_468 ) ;
V_19 = V_470 -> V_479 ( V_2 ) ;
if ( V_19 )
goto V_480;
F_19 ( V_2 ) ;
V_12 -> V_57 -> V_200 [ V_13 ] = V_2 ;
return V_2 ;
V_480:
if ( V_472 )
F_389 ( V_472 ) ;
V_477:
F_35 ( V_2 ) ;
V_475:
V_474:
V_44 -> V_94 -- ;
F_71 ( V_44 ) ;
return F_32 ( V_19 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
const struct V_469 * V_470 = V_2 -> V_470 ;
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_471 * V_472 = V_2 -> V_472 ;
struct V_43 * V_44 ;
F_371 ( V_12 , V_2 ) ;
V_44 = & V_12 -> V_57 -> V_83 [ V_2 -> V_461 ] ;
V_12 -> V_57 -> V_200 [ V_2 -> V_13 ] = NULL ;
F_22 ( V_2 ) ;
V_470 -> V_481 ( V_2 ) ;
if ( V_472 )
F_389 ( V_472 ) ;
F_35 ( V_2 ) ;
V_44 -> V_94 -- ;
F_71 ( V_44 ) ;
}
static void
F_390 ( struct V_467 * V_468 ,
struct V_482 * V_482 )
{
struct V_242 * V_242 = V_482 -> V_242 ;
V_468 -> V_483 = V_482 -> V_483 ;
V_468 -> V_121 = V_242 -> V_484 ;
if ( V_468 -> V_121 )
V_468 -> V_485 = V_242 -> V_485 ;
else
V_468 -> V_486 = V_242 -> V_487 ;
}
static int
F_391 ( struct V_482 * V_482 ,
struct V_103 * V_462 )
{
struct V_242 * V_242 = V_482 -> V_242 ;
struct V_12 * V_12 = V_242 -> V_12 ;
T_1 V_483 = V_482 -> V_483 ;
struct V_1 * V_2 ;
struct V_471 * V_472 ;
int V_19 ;
V_2 = F_138 ( V_12 , V_462 ) ;
if ( ! V_2 ) {
struct V_467 V_468 = {
. V_120 = V_462 ,
} ;
F_390 ( & V_468 , V_482 ) ;
V_2 = F_87 ( V_12 , & V_468 ) ;
if ( F_66 ( V_2 ) )
return F_68 ( V_2 ) ;
}
V_472 = V_2 -> V_470 -> V_476 ( V_2 ) ;
V_19 = F_392 ( V_472 , V_242 , V_483 ) ;
if ( V_19 )
goto V_488;
V_19 = F_393 ( V_242 , V_483 , false ) ;
if ( V_19 )
goto V_489;
V_19 = F_394 ( V_242 , V_483 ,
V_490 ) ;
if ( V_19 )
goto V_491;
V_482 -> V_472 = V_472 ;
return 0 ;
V_491:
F_393 ( V_242 , V_483 , true ) ;
V_489:
F_395 ( V_472 , V_242 , V_483 ) ;
V_488:
F_389 ( V_472 ) ;
return V_19 ;
}
void
F_396 ( struct V_482 * V_482 )
{
struct V_242 * V_242 = V_482 -> V_242 ;
struct V_471 * V_472 = V_482 -> V_472 ;
T_1 V_483 = V_482 -> V_483 ;
if ( F_18 ( V_453 ( V_472 ) != V_457 ) )
return;
V_482 -> V_472 = NULL ;
F_394 ( V_242 , V_483 , V_492 ) ;
F_393 ( V_242 , V_483 , true ) ;
F_395 ( V_472 , V_242 , V_483 ) ;
F_389 ( V_472 ) ;
}
static int F_397 ( struct V_103 * V_462 ,
struct V_103 * V_493 ,
unsigned long V_240 , T_1 V_483 )
{
struct V_242 * V_242 = F_81 ( V_493 ) ;
struct V_482 * V_482 ;
V_482 = F_398 ( V_242 , V_483 ) ;
if ( F_18 ( ! V_482 ) )
return - V_26 ;
switch ( V_240 ) {
case V_448 :
return F_391 ( V_482 ,
V_462 ) ;
case V_449 :
F_396 ( V_482 ) ;
break;
}
return 0 ;
}
static int F_399 ( struct V_103 * V_493 ,
unsigned long V_240 )
{
if ( F_400 ( V_493 ) ||
F_401 ( V_493 ) ||
F_402 ( V_493 ) )
return 0 ;
return F_397 ( V_493 , V_493 , V_240 , 1 ) ;
}
static int F_403 ( struct V_103 * V_462 ,
struct V_103 * V_494 ,
unsigned long V_240 , T_1 V_483 )
{
struct V_103 * V_493 ;
struct V_495 * V_496 ;
int V_19 ;
F_404 (lag_dev, port_dev, iter) {
if ( F_405 ( V_493 ) ) {
V_19 = F_397 ( V_462 ,
V_493 ,
V_240 , V_483 ) ;
if ( V_19 )
return V_19 ;
}
}
return 0 ;
}
static int F_406 ( struct V_103 * V_494 ,
unsigned long V_240 )
{
if ( F_400 ( V_494 ) )
return 0 ;
return F_403 ( V_494 , V_494 , V_240 , 1 ) ;
}
static int F_407 ( struct V_103 * V_462 ,
unsigned long V_240 )
{
struct V_12 * V_12 = F_408 ( V_462 ) ;
struct V_467 V_468 = {
. V_120 = V_462 ,
} ;
struct V_1 * V_2 ;
switch ( V_240 ) {
case V_448 :
V_2 = F_87 ( V_12 , & V_468 ) ;
if ( F_66 ( V_2 ) )
return F_68 ( V_2 ) ;
break;
case V_449 :
V_2 = F_138 ( V_12 , V_462 ) ;
F_91 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_409 ( struct V_103 * V_497 ,
unsigned long V_240 )
{
struct V_103 * V_498 = F_378 ( V_497 ) ;
T_1 V_483 = F_410 ( V_497 ) ;
if ( F_400 ( V_497 ) )
return 0 ;
if ( F_405 ( V_498 ) )
return F_397 ( V_497 , V_498 ,
V_240 , V_483 ) ;
else if ( F_411 ( V_498 ) )
return F_403 ( V_497 , V_498 , V_240 ,
V_483 ) ;
else if ( F_377 ( V_498 ) && F_379 ( V_498 ) )
return F_407 ( V_497 , V_240 ) ;
return 0 ;
}
static int F_412 ( struct V_103 * V_120 ,
unsigned long V_240 )
{
if ( F_405 ( V_120 ) )
return F_399 ( V_120 , V_240 ) ;
else if ( F_411 ( V_120 ) )
return F_406 ( V_120 , V_240 ) ;
else if ( F_377 ( V_120 ) )
return F_407 ( V_120 , V_240 ) ;
else if ( F_376 ( V_120 ) )
return F_409 ( V_120 , V_240 ) ;
else
return 0 ;
}
int F_413 ( struct V_238 * V_239 ,
unsigned long V_240 , void * V_241 )
{
struct V_499 * V_500 = (struct V_499 * ) V_241 ;
struct V_103 * V_120 = V_500 -> V_501 -> V_120 ;
struct V_12 * V_12 ;
struct V_1 * V_2 ;
int V_19 = 0 ;
V_12 = F_408 ( V_120 ) ;
if ( ! V_12 )
goto V_214;
V_2 = F_138 ( V_12 , V_120 ) ;
if ( ! F_372 ( V_2 , V_120 , V_240 ) )
goto V_214;
V_19 = F_412 ( V_120 , V_240 ) ;
V_214:
return F_414 ( V_19 ) ;
}
static void F_415 ( struct V_216 * V_217 )
{
struct F_415 * V_502 =
F_88 ( V_217 , struct F_415 , V_217 ) ;
struct V_103 * V_120 = V_502 -> V_120 ;
unsigned long V_240 = V_502 -> V_240 ;
struct V_12 * V_12 ;
struct V_1 * V_2 ;
F_167 () ;
V_12 = F_408 ( V_120 ) ;
if ( ! V_12 )
goto V_214;
V_2 = F_138 ( V_12 , V_120 ) ;
if ( ! F_372 ( V_2 , V_120 , V_240 ) )
goto V_214;
F_412 ( V_120 , V_240 ) ;
V_214:
F_169 () ;
F_416 ( V_120 ) ;
F_35 ( V_502 ) ;
}
int F_417 ( struct V_238 * V_239 ,
unsigned long V_240 , void * V_241 )
{
struct V_503 * V_504 = (struct V_503 * ) V_241 ;
struct F_415 * V_502 ;
struct V_103 * V_120 = V_504 -> V_447 -> V_120 ;
if ( ! F_418 ( V_120 ) )
return V_246 ;
V_502 = F_31 ( sizeof( * V_502 ) , V_248 ) ;
if ( ! V_502 )
return V_249 ;
F_197 ( & V_502 -> V_217 , F_415 ) ;
V_502 -> V_120 = V_120 ;
V_502 -> V_240 = V_240 ;
F_419 ( V_120 ) ;
F_199 ( & V_502 -> V_217 ) ;
return V_246 ;
}
static int F_420 ( struct V_12 * V_12 , T_1 V_13 ,
const char * V_505 , int V_464 )
{
char V_16 [ V_17 ] ;
int V_19 ;
F_5 ( V_16 , V_13 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
if ( V_19 )
return V_19 ;
F_421 ( V_16 , V_464 ) ;
F_422 ( V_16 , V_505 ) ;
F_423 ( V_16 , V_506 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
int F_424 ( struct V_103 * V_120 )
{
struct V_12 * V_12 ;
struct V_1 * V_2 ;
T_1 V_507 ;
int V_19 ;
V_12 = F_408 ( V_120 ) ;
if ( ! V_12 )
return 0 ;
V_2 = F_138 ( V_12 , V_120 ) ;
if ( ! V_2 )
return 0 ;
V_507 = F_425 ( V_2 -> V_472 ) ;
V_19 = F_426 ( V_12 , V_2 -> V_358 , V_507 , false ) ;
if ( V_19 )
return V_19 ;
V_19 = F_420 ( V_12 , V_2 -> V_13 , V_120 -> V_463 ,
V_120 -> V_464 ) ;
if ( V_19 )
goto V_508;
V_19 = F_426 ( V_12 , V_120 -> V_463 , V_507 , true ) ;
if ( V_19 )
goto V_509;
F_383 ( V_2 -> V_358 , V_120 -> V_463 ) ;
V_2 -> V_464 = V_120 -> V_464 ;
F_154 ( V_120 , L_18 , V_2 -> V_13 ) ;
return 0 ;
V_509:
F_420 ( V_12 , V_2 -> V_13 , V_2 -> V_358 , V_2 -> V_464 ) ;
V_508:
F_426 ( V_12 , V_2 -> V_358 , V_507 , true ) ;
return V_19 ;
}
static int F_427 ( struct V_12 * V_12 ,
struct V_103 * V_462 )
{
struct V_1 * V_2 ;
V_2 = F_138 ( V_12 , V_462 ) ;
if ( V_2 )
F_412 ( V_462 , V_449 ) ;
return F_412 ( V_462 , V_448 ) ;
}
static void F_428 ( struct V_12 * V_12 ,
struct V_103 * V_462 )
{
struct V_1 * V_2 ;
V_2 = F_138 ( V_12 , V_462 ) ;
if ( ! V_2 )
return;
F_412 ( V_462 , V_449 ) ;
}
int F_429 ( struct V_103 * V_462 , unsigned long V_240 ,
struct V_510 * V_440 )
{
struct V_12 * V_12 = F_408 ( V_462 ) ;
int V_19 = 0 ;
if ( ! V_12 )
return 0 ;
switch ( V_240 ) {
case V_511 :
return 0 ;
case V_512 :
if ( V_440 -> V_513 )
V_19 = F_427 ( V_12 , V_462 ) ;
else
F_428 ( V_12 , V_462 ) ;
break;
}
return V_19 ;
}
static struct V_514 *
F_430 ( const struct V_1 * V_2 )
{
return F_88 ( V_2 , struct V_514 , V_119 ) ;
}
static void F_431 ( struct V_1 * V_2 ,
const struct V_467 * V_468 )
{
struct V_514 * V_515 ;
V_515 = F_430 ( V_2 ) ;
V_515 -> V_483 = V_468 -> V_483 ;
V_515 -> V_121 = V_468 -> V_121 ;
if ( V_468 -> V_121 )
V_515 -> V_485 = V_468 -> V_485 ;
else
V_515 -> V_486 = V_468 -> V_486 ;
}
static int F_432 ( struct V_1 * V_2 , bool V_15 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_514 * V_515 ;
char V_16 [ V_17 ] ;
V_515 = F_430 ( V_2 ) ;
F_433 ( V_16 , V_15 , V_516 ,
V_2 -> V_13 , V_2 -> V_461 , V_2 -> V_120 -> V_464 ) ;
F_434 ( V_16 , V_2 -> V_120 -> V_463 ) ;
F_435 ( V_16 , V_515 -> V_121 ,
V_515 -> V_121 ? V_515 -> V_485 :
V_515 -> V_486 ,
V_515 -> V_483 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static int F_436 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_432 ( V_2 , true ) ;
if ( V_19 )
return V_19 ;
V_19 = F_426 ( V_2 -> V_12 , V_2 -> V_120 -> V_463 ,
F_425 ( V_2 -> V_472 ) , true ) ;
if ( V_19 )
goto V_509;
F_437 ( V_2 -> V_472 , V_2 ) ;
return 0 ;
V_509:
F_432 ( V_2 , false ) ;
return V_19 ;
}
static void F_438 ( struct V_1 * V_2 )
{
struct V_471 * V_472 = V_2 -> V_472 ;
F_437 ( V_472 , NULL ) ;
F_426 ( V_2 -> V_12 , V_2 -> V_120 -> V_463 ,
F_425 ( V_472 ) , false ) ;
F_432 ( V_2 , false ) ;
}
static struct V_471 *
F_439 ( struct V_1 * V_2 )
{
return F_440 ( V_2 -> V_12 , V_2 -> V_13 ) ;
}
static int F_441 ( struct V_1 * V_2 ,
enum V_517 type ,
T_1 V_518 , bool V_15 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
char V_16 [ V_17 ] ;
F_433 ( V_16 , V_15 , type , V_2 -> V_13 , V_2 -> V_461 ,
V_2 -> V_120 -> V_464 ) ;
F_434 ( V_16 , V_2 -> V_120 -> V_463 ) ;
F_442 ( V_16 , type , V_518 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static T_3 F_443 ( const struct V_12 * V_12 )
{
return F_444 ( V_12 -> V_20 ) + 1 ;
}
static int F_445 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
T_1 V_483 = F_446 ( V_2 -> V_472 ) ;
int V_19 ;
V_19 = F_441 ( V_2 , V_519 , V_483 , true ) ;
if ( V_19 )
return V_19 ;
V_19 = F_447 ( V_2 -> V_472 , V_520 ,
F_443 ( V_12 ) , true ) ;
if ( V_19 )
goto V_521;
V_19 = F_447 ( V_2 -> V_472 , V_522 ,
F_443 ( V_12 ) , true ) ;
if ( V_19 )
goto V_523;
V_19 = F_426 ( V_2 -> V_12 , V_2 -> V_120 -> V_463 ,
F_425 ( V_2 -> V_472 ) , true ) ;
if ( V_19 )
goto V_509;
F_437 ( V_2 -> V_472 , V_2 ) ;
return 0 ;
V_509:
F_447 ( V_2 -> V_472 , V_522 ,
F_443 ( V_12 ) , false ) ;
V_523:
F_447 ( V_2 -> V_472 , V_520 ,
F_443 ( V_12 ) , false ) ;
V_521:
F_441 ( V_2 , V_519 , V_483 , false ) ;
return V_19 ;
}
static void F_448 ( struct V_1 * V_2 )
{
T_1 V_483 = F_446 ( V_2 -> V_472 ) ;
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_471 * V_472 = V_2 -> V_472 ;
F_437 ( V_472 , NULL ) ;
F_426 ( V_2 -> V_12 , V_2 -> V_120 -> V_463 ,
F_425 ( V_472 ) , false ) ;
F_447 ( V_2 -> V_472 , V_522 ,
F_443 ( V_12 ) , false ) ;
F_447 ( V_2 -> V_472 , V_520 ,
F_443 ( V_12 ) , false ) ;
F_441 ( V_2 , V_519 , V_483 , false ) ;
}
static struct V_471 *
F_449 ( struct V_1 * V_2 )
{
T_1 V_483 = F_376 ( V_2 -> V_120 ) ? F_410 ( V_2 -> V_120 ) : 1 ;
return F_450 ( V_2 -> V_12 , V_483 ) ;
}
static int F_451 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
T_1 V_507 = F_425 ( V_2 -> V_472 ) ;
int V_19 ;
V_19 = F_441 ( V_2 , V_524 , V_507 ,
true ) ;
if ( V_19 )
return V_19 ;
V_19 = F_447 ( V_2 -> V_472 , V_520 ,
F_443 ( V_12 ) , true ) ;
if ( V_19 )
goto V_521;
V_19 = F_447 ( V_2 -> V_472 , V_522 ,
F_443 ( V_12 ) , true ) ;
if ( V_19 )
goto V_523;
V_19 = F_426 ( V_2 -> V_12 , V_2 -> V_120 -> V_463 ,
F_425 ( V_2 -> V_472 ) , true ) ;
if ( V_19 )
goto V_509;
F_437 ( V_2 -> V_472 , V_2 ) ;
return 0 ;
V_509:
F_447 ( V_2 -> V_472 , V_522 ,
F_443 ( V_12 ) , false ) ;
V_523:
F_447 ( V_2 -> V_472 , V_520 ,
F_443 ( V_12 ) , false ) ;
V_521:
F_441 ( V_2 , V_524 , V_507 , false ) ;
return V_19 ;
}
static void F_452 ( struct V_1 * V_2 )
{
T_1 V_507 = F_425 ( V_2 -> V_472 ) ;
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_471 * V_472 = V_2 -> V_472 ;
F_437 ( V_472 , NULL ) ;
F_426 ( V_2 -> V_12 , V_2 -> V_120 -> V_463 ,
F_425 ( V_472 ) , false ) ;
F_447 ( V_2 -> V_472 , V_522 ,
F_443 ( V_12 ) , false ) ;
F_447 ( V_2 -> V_472 , V_520 ,
F_443 ( V_12 ) , false ) ;
F_441 ( V_2 , V_524 , V_507 , false ) ;
}
static struct V_471 *
F_453 ( struct V_1 * V_2 )
{
return F_454 ( V_2 -> V_12 , V_2 -> V_120 -> V_256 ) ;
}
static struct V_111 *
F_455 ( struct V_1 * V_2 )
{
return F_88 ( V_2 , struct V_111 , V_119 ) ;
}
static void
F_456 ( struct V_1 * V_2 ,
const struct V_467 * V_468 )
{
struct V_114 * V_525 ;
struct V_111 * V_526 ;
V_525 = F_88 ( V_468 , struct V_114 ,
V_119 ) ;
V_526 = F_455 ( V_2 ) ;
V_526 -> V_122 = V_525 -> V_122 ;
}
static int
F_457 ( struct V_111 * V_465 ,
struct V_43 * V_151 , bool V_15 )
{
struct V_527 V_528 = V_465 -> V_122 ;
struct V_1 * V_2 = & V_465 -> V_119 ;
struct V_12 * V_12 = V_2 -> V_12 ;
char V_16 [ V_17 ] ;
T_4 V_154 ;
switch ( V_528 . V_529 ) {
case V_91 :
V_154 = F_106 ( V_528 . V_130 . V_132 ) ;
F_433 ( V_16 , V_15 , V_530 ,
V_2 -> V_13 , V_2 -> V_461 , V_2 -> V_120 -> V_464 ) ;
F_458 ( V_16 , V_528 . V_531 ,
V_532 ,
V_151 -> V_65 , V_154 , V_528 . V_533 ) ;
break;
case V_92 :
return - V_534 ;
}
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static int
F_459 ( struct V_1 * V_2 )
{
struct V_111 * V_465 = F_455 ( V_2 ) ;
T_4 V_137 = F_84 ( V_2 -> V_120 ) ;
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_43 * V_151 ;
int V_19 ;
V_151 = F_70 ( V_12 , V_137 ) ;
if ( F_66 ( V_151 ) )
return F_68 ( V_151 ) ;
V_19 = F_457 ( V_465 , V_151 , true ) ;
if ( V_19 )
goto V_535;
V_465 -> V_466 = V_151 -> V_65 ;
++ V_151 -> V_94 ;
return 0 ;
V_535:
F_71 ( V_151 ) ;
return V_19 ;
}
static void F_460 ( struct V_1 * V_2 )
{
struct V_111 * V_465 = F_455 ( V_2 ) ;
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_43 * V_151 ;
V_151 = & V_12 -> V_57 -> V_83 [ V_465 -> V_466 ] ;
F_457 ( V_465 , V_151 , false ) ;
-- V_151 -> V_94 ;
F_71 ( V_151 ) ;
}
static int F_461 ( struct V_12 * V_12 )
{
T_2 V_536 = F_54 ( V_12 -> V_20 , V_444 ) ;
V_12 -> V_57 -> V_200 = F_55 ( V_536 ,
sizeof( struct V_1 * ) ,
V_48 ) ;
if ( ! V_12 -> V_57 -> V_200 )
return - V_49 ;
V_12 -> V_57 -> V_473 = V_537 ;
return 0 ;
}
static void F_462 ( struct V_12 * V_12 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_54 ( V_12 -> V_20 , V_444 ) ; V_56 ++ )
F_188 ( V_12 -> V_57 -> V_200 [ V_56 ] ) ;
F_35 ( V_12 -> V_57 -> V_200 ) ;
}
static int
F_463 ( struct V_12 * V_12 )
{
char V_538 [ V_539 ] ;
F_464 ( V_538 , true , 0 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_540 ) , V_538 ) ;
}
static int F_465 ( struct V_12 * V_12 )
{
V_12 -> V_57 -> V_118 = V_541 ;
F_34 ( & V_12 -> V_57 -> V_161 ) ;
return F_463 ( V_12 ) ;
}
static void F_466 ( struct V_12 * V_12 )
{
F_18 ( ! F_37 ( & V_12 -> V_57 -> V_161 ) ) ;
}
static void F_467 ( struct V_238 * V_441 )
{
struct V_157 * V_57 ;
F_78 () ;
V_57 = F_88 ( V_441 , struct V_157 , V_443 ) ;
F_79 ( V_57 -> V_12 ) ;
}
static int F_468 ( struct V_12 * V_12 )
{
char V_542 [ V_543 ] ;
T_2 V_536 ;
int V_19 ;
if ( ! F_53 ( V_12 -> V_20 , V_444 ) )
return - V_78 ;
V_536 = F_54 ( V_12 -> V_20 , V_444 ) ;
F_469 ( V_542 , true , true ) ;
F_470 ( V_542 , V_536 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_544 ) , V_542 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static void F_471 ( struct V_12 * V_12 )
{
char V_542 [ V_543 ] ;
F_469 ( V_542 , false , false ) ;
F_9 ( V_12 -> V_20 , F_7 ( V_544 ) , V_542 ) ;
}
int F_472 ( struct V_12 * V_12 )
{
struct V_157 * V_57 ;
int V_19 ;
V_57 = F_31 ( sizeof( * V_12 -> V_57 ) , V_48 ) ;
if ( ! V_57 )
return - V_49 ;
V_12 -> V_57 = V_57 ;
V_57 -> V_12 = V_12 ;
F_34 ( & V_12 -> V_57 -> V_315 ) ;
V_19 = F_468 ( V_12 ) ;
if ( V_19 )
goto V_545;
V_19 = F_461 ( V_12 ) ;
if ( V_19 )
goto V_546;
V_19 = F_465 ( V_12 ) ;
if ( V_19 )
goto V_547;
V_19 = F_33 ( & V_12 -> V_57 -> V_282 ,
& V_283 ) ;
if ( V_19 )
goto V_548;
V_19 = F_33 ( & V_12 -> V_57 -> V_280 ,
& V_281 ) ;
if ( V_19 )
goto V_549;
V_19 = F_52 ( V_12 ) ;
if ( V_19 )
goto V_550;
V_19 = F_76 ( V_12 ) ;
if ( V_19 )
goto V_551;
V_19 = F_200 ( V_12 ) ;
if ( V_19 )
goto V_326;
V_12 -> V_57 -> V_443 . V_552 = F_367 ;
V_19 = F_473 ( & V_12 -> V_57 -> V_443 ,
F_467 ) ;
if ( V_19 )
goto V_553;
return 0 ;
V_553:
F_202 ( V_12 ) ;
V_326:
F_77 ( V_12 ) ;
V_551:
F_56 ( V_12 ) ;
V_550:
F_38 ( & V_12 -> V_57 -> V_280 ) ;
V_549:
F_38 ( & V_12 -> V_57 -> V_282 ) ;
V_548:
F_466 ( V_12 ) ;
V_547:
F_462 ( V_12 ) ;
V_546:
F_471 ( V_12 ) ;
V_545:
F_35 ( V_12 -> V_57 ) ;
return V_19 ;
}
void F_474 ( struct V_12 * V_12 )
{
F_475 ( & V_12 -> V_57 -> V_443 ) ;
F_202 ( V_12 ) ;
F_77 ( V_12 ) ;
F_56 ( V_12 ) ;
F_38 ( & V_12 -> V_57 -> V_280 ) ;
F_38 ( & V_12 -> V_57 -> V_282 ) ;
F_466 ( V_12 ) ;
F_462 ( V_12 ) ;
F_471 ( V_12 ) ;
F_35 ( V_12 -> V_57 ) ;
}
