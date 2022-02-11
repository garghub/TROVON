static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
return V_1 ;
default:
return V_7 ;
}
}
static int F_2 ( struct V_8 * V_9 , const struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_3 ( V_11 -> V_16 ) ;
bool V_17 = F_4 ( V_9 ) ;
struct V_18 * V_19 ;
int V_20 = - 1 ;
F_5 () ;
F_6 (prog, &head->plist, link) {
int V_21 ;
F_7 ( V_9 ) -> V_22 = V_19 -> V_13 . V_23 ;
if ( F_8 ( V_19 -> V_24 ) ) {
V_21 = V_19 -> V_25 ? V_7 : 0 ;
} else if ( V_17 ) {
F_9 ( V_9 , V_9 -> V_26 ) ;
F_10 ( V_9 ) ;
V_21 = F_11 ( V_19 -> V_27 , V_9 ) ;
F_12 ( V_9 , V_9 -> V_26 ) ;
} else {
F_10 ( V_9 ) ;
V_21 = F_11 ( V_19 -> V_27 , V_9 ) ;
}
if ( V_19 -> V_25 ) {
V_13 -> V_28 = 0 ;
V_13 -> V_23 = F_13 ( V_19 -> V_13 . V_23 ) |
F_7 ( V_9 ) -> V_22 ;
V_20 = F_1 ( V_21 ) ;
if ( V_20 == V_7 )
continue;
break;
}
if ( V_21 == 0 )
continue;
if ( V_21 != - 1 ) {
V_13 -> V_28 = 0 ;
V_13 -> V_23 = V_21 ;
} else {
* V_13 = V_19 -> V_13 ;
}
V_20 = F_14 ( V_9 , & V_19 -> V_29 , V_13 ) ;
if ( V_20 < 0 )
continue;
break;
}
F_15 () ;
return V_20 ;
}
static bool F_16 ( const struct V_18 * V_19 )
{
return ! V_19 -> V_30 ;
}
static int F_17 ( struct V_10 * V_11 , struct V_18 * V_19 ,
enum V_31 V_32 )
{
struct V_33 * V_34 = V_11 -> V_35 -> V_36 -> V_34 ;
struct V_37 V_38 = {} ;
int V_39 ;
F_18 ( & V_38 . V_40 , V_11 ) ;
V_38 . V_41 = V_32 ;
V_38 . V_29 = & V_19 -> V_29 ;
V_38 . V_19 = V_19 -> V_27 ;
V_38 . V_42 = V_19 -> V_43 ;
V_38 . V_25 = V_19 -> V_25 ;
V_38 . V_24 = V_19 -> V_24 ;
V_39 = V_34 -> V_44 -> V_45 ( V_34 , V_46 , & V_38 ) ;
if ( ! V_39 && ( V_32 == V_47 || V_32 == V_48 ) )
V_19 -> V_24 |= V_49 ;
return V_39 ;
}
static int F_19 ( struct V_10 * V_11 , struct V_18 * V_19 ,
struct V_18 * V_50 )
{
struct V_33 * V_34 = V_11 -> V_35 -> V_36 -> V_34 ;
struct V_18 * V_51 = V_19 ;
enum V_31 V_32 ;
bool V_52 ;
int V_20 ;
V_52 = F_8 ( V_19 -> V_24 ) ||
( V_50 && F_8 ( V_50 -> V_24 ) ) ;
if ( V_50 && V_50 -> V_53 ) {
if ( F_20 ( V_34 , V_19 -> V_24 ) ) {
V_32 = V_48 ;
} else if ( ! F_8 ( V_19 -> V_24 ) ) {
V_51 = V_50 ;
V_32 = V_54 ;
} else {
return - V_55 ;
}
} else {
if ( ! F_20 ( V_34 , V_19 -> V_24 ) )
return V_52 ? - V_55 : 0 ;
V_32 = V_47 ;
}
V_20 = F_17 ( V_11 , V_51 , V_32 ) ;
if ( V_20 )
return V_52 ? V_20 : 0 ;
V_51 -> V_53 = true ;
if ( V_50 )
V_50 -> V_53 = false ;
return 0 ;
}
static void F_21 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
int V_39 ;
if ( ! V_19 -> V_53 )
return;
V_39 = F_17 ( V_11 , V_19 , V_54 ) ;
if ( V_39 ) {
F_22 ( L_1 , V_39 ) ;
return;
}
V_19 -> V_53 = false ;
}
static void F_23 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
if ( ! V_19 -> V_53 )
return;
F_17 ( V_11 , V_19 , V_56 ) ;
}
static int F_24 ( struct V_10 * V_11 )
{
struct V_14 * V_15 ;
V_15 = F_25 ( sizeof( * V_15 ) , V_57 ) ;
if ( V_15 == NULL )
return - V_58 ;
F_26 ( & V_15 -> V_59 ) ;
F_27 ( V_11 -> V_16 , V_15 ) ;
return 0 ;
}
static void F_28 ( struct V_18 * V_19 )
{
F_29 ( & V_19 -> V_29 ) ;
F_30 ( & V_19 -> V_29 ) ;
if ( F_16 ( V_19 ) )
F_31 ( V_19 -> V_27 ) ;
else
F_32 ( V_19 -> V_27 ) ;
F_33 ( V_19 -> V_43 ) ;
F_33 ( V_19 -> V_30 ) ;
F_33 ( V_19 ) ;
}
static void F_34 ( struct V_60 * V_61 )
{
struct V_18 * V_19 = F_35 ( V_61 , struct V_18 , V_61 ) ;
F_36 () ;
F_28 ( V_19 ) ;
F_37 () ;
}
static void F_38 ( struct V_62 * V_63 )
{
struct V_18 * V_19 = F_35 ( V_63 , struct V_18 , V_63 ) ;
F_39 ( & V_19 -> V_61 , F_34 ) ;
F_40 ( & V_19 -> V_61 ) ;
}
static void F_41 ( struct V_10 * V_11 , struct V_18 * V_19 )
{
F_21 ( V_11 , V_19 ) ;
F_42 ( & V_19 -> V_64 ) ;
F_43 ( V_11 , & V_19 -> V_13 ) ;
if ( F_44 ( & V_19 -> V_29 ) )
F_45 ( & V_19 -> V_63 , F_38 ) ;
else
F_28 ( V_19 ) ;
}
static int F_46 ( struct V_10 * V_11 , void * V_65 , bool * V_66 )
{
struct V_14 * V_15 = F_47 ( V_11 -> V_16 ) ;
F_41 ( V_11 , V_65 ) ;
* V_66 = F_48 ( & V_15 -> V_59 ) ;
return 0 ;
}
static void F_49 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = F_47 ( V_11 -> V_16 ) ;
struct V_18 * V_19 , * V_67 ;
F_50 (prog, tmp, &head->plist, link)
F_41 ( V_11 , V_19 ) ;
F_51 ( V_15 , V_63 ) ;
}
static void * F_52 ( struct V_10 * V_11 , T_1 V_68 )
{
struct V_14 * V_15 = F_47 ( V_11 -> V_16 ) ;
struct V_18 * V_19 ;
F_53 (prog, &head->plist, link) {
if ( V_19 -> V_68 == V_68 )
return V_19 ;
}
return NULL ;
}
static int F_54 ( struct V_69 * * V_70 , struct V_18 * V_19 )
{
struct V_71 * V_30 ;
struct V_72 V_73 ;
struct V_74 * V_75 ;
T_2 V_76 , V_77 ;
int V_20 ;
V_77 = F_55 ( V_70 [ V_78 ] ) ;
if ( V_77 > V_79 || V_77 == 0 )
return - V_55 ;
V_76 = V_77 * sizeof( * V_30 ) ;
if ( V_76 != F_56 ( V_70 [ V_80 ] ) )
return - V_55 ;
V_30 = F_25 ( V_76 , V_57 ) ;
if ( V_30 == NULL )
return - V_81 ;
memcpy ( V_30 , F_57 ( V_70 [ V_80 ] ) , V_76 ) ;
V_73 . V_82 = V_77 ;
V_73 . V_27 = V_30 ;
V_20 = F_58 ( & V_75 , & V_73 ) ;
if ( V_20 < 0 ) {
F_33 ( V_30 ) ;
return V_20 ;
}
V_19 -> V_30 = V_30 ;
V_19 -> V_77 = V_77 ;
V_19 -> V_43 = NULL ;
V_19 -> V_27 = V_75 ;
return 0 ;
}
static int F_59 ( struct V_69 * * V_70 , struct V_18 * V_19 ,
const struct V_10 * V_11 )
{
struct V_74 * V_75 ;
char * V_42 = NULL ;
T_1 V_83 ;
V_83 = F_60 ( V_70 [ V_84 ] ) ;
V_75 = F_61 ( V_83 , V_85 ) ;
if ( F_62 ( V_75 ) )
return F_63 ( V_75 ) ;
if ( V_70 [ V_86 ] ) {
V_42 = F_64 ( V_70 [ V_86 ] , V_57 ) ;
if ( ! V_42 ) {
F_31 ( V_75 ) ;
return - V_81 ;
}
}
V_19 -> V_30 = NULL ;
V_19 -> V_43 = V_42 ;
V_19 -> V_27 = V_75 ;
if ( V_75 -> V_87 && ! ( V_11 -> V_35 -> V_88 & V_89 ) )
F_65 ( F_66 ( V_11 -> V_35 ) ) ;
return 0 ;
}
static int F_67 ( struct V_90 * V_90 , struct V_10 * V_11 ,
struct V_18 * V_19 , unsigned long V_91 ,
struct V_69 * * V_70 , struct V_69 * V_92 , bool V_93 )
{
bool V_94 , V_95 , V_96 = false ;
T_1 V_24 = 0 ;
int V_20 ;
V_94 = V_70 [ V_78 ] && V_70 [ V_80 ] ;
V_95 = V_70 [ V_84 ] ;
if ( ( ! V_94 && ! V_95 ) || ( V_94 && V_95 ) )
return - V_55 ;
V_20 = F_68 ( V_90 , V_11 , V_70 , V_92 , & V_19 -> V_29 , V_93 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_70 [ V_97 ] ) {
T_1 V_98 = F_60 ( V_70 [ V_97 ] ) ;
if ( V_98 & ~ V_99 )
return - V_55 ;
V_96 = V_98 & V_99 ;
}
if ( V_70 [ V_100 ] ) {
V_24 = F_60 ( V_70 [ V_100 ] ) ;
if ( V_24 & ~ V_101 ||
! F_69 ( V_24 ) )
return - V_55 ;
}
V_19 -> V_25 = V_96 ;
V_19 -> V_24 = V_24 ;
V_20 = V_94 ? F_54 ( V_70 , V_19 ) :
F_59 ( V_70 , V_19 , V_11 ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_70 [ V_102 ] ) {
V_19 -> V_13 . V_23 = F_60 ( V_70 [ V_102 ] ) ;
F_70 ( V_11 , & V_19 -> V_13 , V_91 ) ;
}
return 0 ;
}
static T_1 F_71 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
unsigned int V_103 = 0x80000000 ;
T_1 V_68 ;
do {
if ( ++ V_15 -> V_104 == 0x7FFFFFFF )
V_15 -> V_104 = 1 ;
} while ( -- V_103 > 0 && F_52 ( V_11 , V_15 -> V_104 ) );
if ( F_72 ( V_103 == 0 ) ) {
F_22 ( L_2 ) ;
V_68 = 0 ;
} else {
V_68 = V_15 -> V_104 ;
}
return V_68 ;
}
static int F_73 ( struct V_90 * V_90 , struct V_8 * V_105 ,
struct V_10 * V_11 , unsigned long V_91 ,
T_1 V_68 , struct V_69 * * V_106 ,
void * * V_65 , bool V_93 )
{
struct V_14 * V_15 = F_47 ( V_11 -> V_16 ) ;
struct V_18 * V_50 = * V_65 ;
struct V_69 * V_70 [ V_107 + 1 ] ;
struct V_18 * V_19 ;
int V_20 ;
if ( V_106 [ V_108 ] == NULL )
return - V_55 ;
V_20 = F_74 ( V_70 , V_107 , V_106 [ V_108 ] , V_109 ,
NULL ) ;
if ( V_20 < 0 )
return V_20 ;
V_19 = F_25 ( sizeof( * V_19 ) , V_57 ) ;
if ( ! V_19 )
return - V_58 ;
V_20 = F_75 ( & V_19 -> V_29 , V_110 , V_111 ) ;
if ( V_20 < 0 )
goto V_112;
if ( V_50 ) {
if ( V_68 && V_50 -> V_68 != V_68 ) {
V_20 = - V_55 ;
goto V_112;
}
}
if ( V_68 == 0 )
V_19 -> V_68 = F_71 ( V_11 , V_15 ) ;
else
V_19 -> V_68 = V_68 ;
if ( V_19 -> V_68 == 0 ) {
V_20 = - V_55 ;
goto V_112;
}
V_20 = F_67 ( V_90 , V_11 , V_19 , V_91 , V_70 , V_106 [ V_113 ] , V_93 ) ;
if ( V_20 < 0 )
goto V_112;
V_20 = F_19 ( V_11 , V_19 , V_50 ) ;
if ( V_20 ) {
F_28 ( V_19 ) ;
return V_20 ;
}
if ( ! F_76 ( V_19 -> V_24 ) )
V_19 -> V_24 |= V_114 ;
if ( V_50 ) {
F_77 ( & V_50 -> V_64 , & V_19 -> V_64 ) ;
F_43 ( V_11 , & V_50 -> V_13 ) ;
F_44 ( & V_50 -> V_29 ) ;
F_45 ( & V_50 -> V_63 , F_38 ) ;
} else {
F_78 ( & V_19 -> V_64 , & V_15 -> V_59 ) ;
}
* V_65 = V_19 ;
return 0 ;
V_112:
F_29 ( & V_19 -> V_29 ) ;
F_33 ( V_19 ) ;
return V_20 ;
}
static int F_79 ( const struct V_18 * V_19 ,
struct V_8 * V_9 )
{
struct V_69 * V_115 ;
if ( F_80 ( V_9 , V_78 , V_19 -> V_77 ) )
return - V_116 ;
V_115 = F_81 ( V_9 , V_80 , V_19 -> V_77 *
sizeof( struct V_71 ) ) ;
if ( V_115 == NULL )
return - V_116 ;
memcpy ( F_57 ( V_115 ) , V_19 -> V_30 , F_56 ( V_115 ) ) ;
return 0 ;
}
static int F_82 ( const struct V_18 * V_19 ,
struct V_8 * V_9 )
{
struct V_69 * V_115 ;
if ( V_19 -> V_43 &&
F_83 ( V_9 , V_86 , V_19 -> V_43 ) )
return - V_116 ;
if ( F_84 ( V_9 , V_117 , V_19 -> V_27 -> V_118 -> V_119 ) )
return - V_116 ;
V_115 = F_81 ( V_9 , V_120 , sizeof( V_19 -> V_27 -> V_121 ) ) ;
if ( V_115 == NULL )
return - V_116 ;
memcpy ( F_57 ( V_115 ) , V_19 -> V_27 -> V_121 , F_56 ( V_115 ) ) ;
return 0 ;
}
static int F_85 ( struct V_90 * V_90 , struct V_10 * V_11 , void * V_122 ,
struct V_8 * V_9 , struct V_123 * V_124 )
{
struct V_18 * V_19 = V_122 ;
struct V_69 * V_125 ;
T_1 V_98 = 0 ;
int V_20 ;
if ( V_19 == NULL )
return V_9 -> V_82 ;
V_124 -> V_126 = V_19 -> V_68 ;
F_23 ( V_11 , V_19 ) ;
V_125 = F_86 ( V_9 , V_108 ) ;
if ( V_125 == NULL )
goto V_127;
if ( V_19 -> V_13 . V_23 &&
F_84 ( V_9 , V_102 , V_19 -> V_13 . V_23 ) )
goto V_127;
if ( F_16 ( V_19 ) )
V_20 = F_82 ( V_19 , V_9 ) ;
else
V_20 = F_79 ( V_19 , V_9 ) ;
if ( V_20 )
goto V_127;
if ( F_87 ( V_9 , & V_19 -> V_29 ) < 0 )
goto V_127;
if ( V_19 -> V_25 )
V_98 |= V_99 ;
if ( V_98 && F_84 ( V_9 , V_97 , V_98 ) )
goto V_127;
if ( V_19 -> V_24 &&
F_84 ( V_9 , V_100 , V_19 -> V_24 ) )
goto V_127;
F_88 ( V_9 , V_125 ) ;
if ( F_89 ( V_9 , & V_19 -> V_29 ) < 0 )
goto V_127;
return V_9 -> V_82 ;
V_127:
F_90 ( V_9 , V_125 ) ;
return - 1 ;
}
static void F_91 ( void * V_122 , T_1 V_23 , unsigned long V_128 )
{
struct V_18 * V_19 = V_122 ;
if ( V_19 && V_19 -> V_13 . V_23 == V_23 )
V_19 -> V_13 . V_28 = V_128 ;
}
static void F_92 ( struct V_10 * V_11 , struct V_129 * V_65 )
{
struct V_14 * V_15 = F_47 ( V_11 -> V_16 ) ;
struct V_18 * V_19 ;
F_53 (prog, &head->plist, link) {
if ( V_65 -> V_130 < V_65 -> V_131 )
goto V_131;
if ( V_65 -> V_132 ( V_11 , V_19 , V_65 ) < 0 ) {
V_65 -> V_133 = 1 ;
break;
}
V_131:
V_65 -> V_130 ++ ;
}
}
static int T_3 F_93 ( void )
{
return F_94 ( & V_134 ) ;
}
static void T_4 F_95 ( void )
{
F_96 ( & V_134 ) ;
}
