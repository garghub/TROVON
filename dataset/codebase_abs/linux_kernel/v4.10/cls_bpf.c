static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
return V_1 ;
default:
return V_6 ;
}
}
static int F_2 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_3 ( V_10 -> V_15 ) ;
bool V_16 = F_4 ( V_8 ) ;
struct V_17 * V_18 ;
int V_19 = - 1 ;
F_5 () ;
F_6 (prog, &head->plist, link) {
int V_20 ;
F_7 ( V_8 ) -> V_21 = V_18 -> V_12 . V_22 ;
if ( F_8 ( V_18 -> V_23 ) ) {
V_20 = V_18 -> V_24 ? V_6 : 0 ;
} else if ( V_16 ) {
F_9 ( V_8 , V_8 -> V_25 ) ;
F_10 ( V_8 ) ;
V_20 = F_11 ( V_18 -> V_26 , V_8 ) ;
F_12 ( V_8 , V_8 -> V_25 ) ;
} else {
F_10 ( V_8 ) ;
V_20 = F_11 ( V_18 -> V_26 , V_8 ) ;
}
if ( V_18 -> V_24 ) {
V_12 -> V_27 = 0 ;
V_12 -> V_22 = F_13 ( V_18 -> V_12 . V_22 ) |
F_7 ( V_8 ) -> V_21 ;
V_19 = F_1 ( V_20 ) ;
if ( V_19 == V_6 )
continue;
break;
}
if ( V_20 == 0 )
continue;
if ( V_20 != - 1 ) {
V_12 -> V_27 = 0 ;
V_12 -> V_22 = V_20 ;
} else {
* V_12 = V_18 -> V_12 ;
}
V_19 = F_14 ( V_8 , & V_18 -> V_28 , V_12 ) ;
if ( V_19 < 0 )
continue;
break;
}
F_15 () ;
return V_19 ;
}
static bool F_16 ( const struct V_17 * V_18 )
{
return ! V_18 -> V_29 ;
}
static int F_17 ( struct V_9 * V_10 , struct V_17 * V_18 ,
enum V_30 V_31 )
{
struct V_32 * V_33 = V_10 -> V_34 -> V_35 -> V_33 ;
struct V_36 V_37 = {} ;
struct V_38 V_39 ;
V_39 . type = V_40 ;
V_39 . V_41 = & V_37 ;
V_37 . V_42 = V_31 ;
V_37 . V_28 = & V_18 -> V_28 ;
V_37 . V_18 = V_18 -> V_26 ;
V_37 . V_43 = V_18 -> V_44 ;
V_37 . V_24 = V_18 -> V_24 ;
V_37 . V_23 = V_18 -> V_23 ;
return V_33 -> V_45 -> V_46 ( V_33 , V_10 -> V_34 -> V_47 ,
V_10 -> V_48 , & V_39 ) ;
}
static int F_18 ( struct V_9 * V_10 , struct V_17 * V_18 ,
struct V_17 * V_49 )
{
struct V_32 * V_33 = V_10 -> V_34 -> V_35 -> V_33 ;
struct V_17 * V_50 = V_18 ;
enum V_30 V_31 ;
bool V_51 ;
int V_19 ;
V_51 = F_8 ( V_18 -> V_23 ) ||
( V_49 && F_8 ( V_49 -> V_23 ) ) ;
if ( V_49 && V_49 -> V_52 ) {
if ( F_19 ( V_33 , V_10 , V_18 -> V_23 ) ) {
V_31 = V_53 ;
} else if ( ! F_8 ( V_18 -> V_23 ) ) {
V_50 = V_49 ;
V_31 = V_54 ;
} else {
return - V_55 ;
}
} else {
if ( ! F_19 ( V_33 , V_10 , V_18 -> V_23 ) )
return V_51 ? - V_55 : 0 ;
V_31 = V_56 ;
}
V_19 = F_17 ( V_10 , V_50 , V_31 ) ;
if ( V_19 )
return V_51 ? V_19 : 0 ;
V_50 -> V_52 = true ;
if ( V_49 )
V_49 -> V_52 = false ;
return 0 ;
}
static void F_20 ( struct V_9 * V_10 ,
struct V_17 * V_18 )
{
int V_57 ;
if ( ! V_18 -> V_52 )
return;
V_57 = F_17 ( V_10 , V_18 , V_54 ) ;
if ( V_57 ) {
F_21 ( L_1 , V_57 ) ;
return;
}
V_18 -> V_52 = false ;
}
static void F_22 ( struct V_9 * V_10 ,
struct V_17 * V_18 )
{
if ( ! V_18 -> V_52 )
return;
F_17 ( V_10 , V_18 , V_58 ) ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_13 * V_14 ;
V_14 = F_24 ( sizeof( * V_14 ) , V_59 ) ;
if ( V_14 == NULL )
return - V_60 ;
F_25 ( & V_14 -> V_61 ) ;
F_26 ( V_10 -> V_15 , V_14 ) ;
return 0 ;
}
static void F_27 ( struct V_17 * V_18 )
{
F_28 ( & V_18 -> V_28 ) ;
if ( F_16 ( V_18 ) )
F_29 ( V_18 -> V_26 ) ;
else
F_30 ( V_18 -> V_26 ) ;
F_31 ( V_18 -> V_44 ) ;
F_31 ( V_18 -> V_29 ) ;
F_31 ( V_18 ) ;
}
static void F_32 ( struct V_62 * V_63 )
{
F_27 ( F_33 ( V_63 , struct V_17 , V_63 ) ) ;
}
static void F_34 ( struct V_9 * V_10 , struct V_17 * V_18 )
{
F_20 ( V_10 , V_18 ) ;
F_35 ( & V_18 -> V_64 ) ;
F_36 ( V_10 , & V_18 -> V_12 ) ;
F_37 ( & V_18 -> V_63 , F_32 ) ;
}
static int F_38 ( struct V_9 * V_10 , unsigned long V_65 )
{
F_34 ( V_10 , (struct V_17 * ) V_65 ) ;
return 0 ;
}
static bool F_39 ( struct V_9 * V_10 , bool V_66 )
{
struct V_13 * V_14 = F_40 ( V_10 -> V_15 ) ;
struct V_17 * V_18 , * V_67 ;
if ( ! V_66 && ! F_41 ( & V_14 -> V_61 ) )
return false ;
F_42 (prog, tmp, &head->plist, link)
F_34 ( V_10 , V_18 ) ;
F_43 ( V_14 , V_63 ) ;
return true ;
}
static unsigned long F_44 ( struct V_9 * V_10 , T_1 V_47 )
{
struct V_13 * V_14 = F_40 ( V_10 -> V_15 ) ;
struct V_17 * V_18 ;
unsigned long V_19 = 0UL ;
F_45 (prog, &head->plist, link) {
if ( V_18 -> V_47 == V_47 ) {
V_19 = ( unsigned long ) V_18 ;
break;
}
}
return V_19 ;
}
static int F_46 ( struct V_68 * * V_69 , struct V_17 * V_18 )
{
struct V_70 * V_29 ;
struct V_71 V_72 ;
struct V_73 * V_74 ;
T_2 V_75 , V_76 ;
int V_19 ;
V_76 = F_47 ( V_69 [ V_77 ] ) ;
if ( V_76 > V_78 || V_76 == 0 )
return - V_55 ;
V_75 = V_76 * sizeof( * V_29 ) ;
if ( V_75 != F_48 ( V_69 [ V_79 ] ) )
return - V_55 ;
V_29 = F_24 ( V_75 , V_59 ) ;
if ( V_29 == NULL )
return - V_80 ;
memcpy ( V_29 , F_49 ( V_69 [ V_79 ] ) , V_75 ) ;
V_72 . V_81 = V_76 ;
V_72 . V_26 = V_29 ;
V_19 = F_50 ( & V_74 , & V_72 ) ;
if ( V_19 < 0 ) {
F_31 ( V_29 ) ;
return V_19 ;
}
V_18 -> V_29 = V_29 ;
V_18 -> V_76 = V_76 ;
V_18 -> V_44 = NULL ;
V_18 -> V_26 = V_74 ;
return 0 ;
}
static int F_51 ( struct V_68 * * V_69 , struct V_17 * V_18 ,
const struct V_9 * V_10 )
{
struct V_73 * V_74 ;
char * V_43 = NULL ;
T_1 V_82 ;
V_82 = F_52 ( V_69 [ V_83 ] ) ;
V_74 = F_53 ( V_82 , V_84 ) ;
if ( F_54 ( V_74 ) )
return F_55 ( V_74 ) ;
if ( V_69 [ V_85 ] ) {
V_43 = F_56 ( V_69 [ V_85 ] , V_59 ) ;
if ( ! V_43 ) {
F_29 ( V_74 ) ;
return - V_80 ;
}
}
V_18 -> V_29 = NULL ;
V_18 -> V_44 = V_43 ;
V_18 -> V_26 = V_74 ;
if ( V_74 -> V_86 && ! ( V_10 -> V_34 -> V_87 & V_88 ) )
F_57 ( F_58 ( V_10 -> V_34 ) ) ;
return 0 ;
}
static int F_59 ( struct V_89 * V_89 , struct V_9 * V_10 ,
struct V_17 * V_18 ,
unsigned long V_90 , struct V_68 * * V_69 ,
struct V_68 * V_91 , bool V_92 )
{
bool V_93 , V_94 , V_95 = false ;
struct V_96 V_28 ;
T_1 V_23 = 0 ;
int V_19 ;
V_93 = V_69 [ V_77 ] && V_69 [ V_79 ] ;
V_94 = V_69 [ V_83 ] ;
if ( ( ! V_93 && ! V_94 ) || ( V_93 && V_94 ) )
return - V_55 ;
V_19 = F_60 ( & V_28 , V_97 , V_98 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_61 ( V_89 , V_10 , V_69 , V_91 , & V_28 , V_92 ) ;
if ( V_19 < 0 )
goto V_99;
if ( V_69 [ V_100 ] ) {
T_1 V_101 = F_52 ( V_69 [ V_100 ] ) ;
if ( V_101 & ~ V_102 ) {
V_19 = - V_55 ;
goto V_99;
}
V_95 = V_101 & V_102 ;
}
if ( V_69 [ V_103 ] ) {
V_23 = F_52 ( V_69 [ V_103 ] ) ;
if ( V_23 & ~ V_104 ||
! F_62 ( V_23 ) ) {
V_19 = - V_55 ;
goto V_99;
}
}
V_18 -> V_24 = V_95 ;
V_18 -> V_23 = V_23 ;
V_19 = V_93 ? F_46 ( V_69 , V_18 ) :
F_51 ( V_69 , V_18 , V_10 ) ;
if ( V_19 < 0 )
goto V_99;
if ( V_69 [ V_105 ] ) {
V_18 -> V_12 . V_22 = F_52 ( V_69 [ V_105 ] ) ;
F_63 ( V_10 , & V_18 -> V_12 , V_90 ) ;
}
F_64 ( V_10 , & V_18 -> V_28 , & V_28 ) ;
return 0 ;
V_99:
F_28 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_65 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
unsigned int V_106 = 0x80000000 ;
T_1 V_47 ;
do {
if ( ++ V_14 -> V_107 == 0x7FFFFFFF )
V_14 -> V_107 = 1 ;
} while ( -- V_106 > 0 && F_44 ( V_10 , V_14 -> V_107 ) );
if ( F_66 ( V_106 == 0 ) ) {
F_21 ( L_2 ) ;
V_47 = 0 ;
} else {
V_47 = V_14 -> V_107 ;
}
return V_47 ;
}
static int F_67 ( struct V_89 * V_89 , struct V_7 * V_108 ,
struct V_9 * V_10 , unsigned long V_90 ,
T_1 V_47 , struct V_68 * * V_109 ,
unsigned long * V_65 , bool V_92 )
{
struct V_13 * V_14 = F_40 ( V_10 -> V_15 ) ;
struct V_17 * V_49 = (struct V_17 * ) * V_65 ;
struct V_68 * V_69 [ V_110 + 1 ] ;
struct V_17 * V_18 ;
int V_19 ;
if ( V_109 [ V_111 ] == NULL )
return - V_55 ;
V_19 = F_68 ( V_69 , V_110 , V_109 [ V_111 ] , V_112 ) ;
if ( V_19 < 0 )
return V_19 ;
V_18 = F_24 ( sizeof( * V_18 ) , V_59 ) ;
if ( ! V_18 )
return - V_60 ;
V_19 = F_60 ( & V_18 -> V_28 , V_97 , V_98 ) ;
if ( V_19 < 0 )
goto V_99;
if ( V_49 ) {
if ( V_47 && V_49 -> V_47 != V_47 ) {
V_19 = - V_55 ;
goto V_99;
}
}
if ( V_47 == 0 )
V_18 -> V_47 = F_65 ( V_10 , V_14 ) ;
else
V_18 -> V_47 = V_47 ;
if ( V_18 -> V_47 == 0 ) {
V_19 = - V_55 ;
goto V_99;
}
V_19 = F_59 ( V_89 , V_10 , V_18 , V_90 , V_69 , V_109 [ V_113 ] ,
V_92 ) ;
if ( V_19 < 0 )
goto V_99;
V_19 = F_18 ( V_10 , V_18 , V_49 ) ;
if ( V_19 ) {
F_27 ( V_18 ) ;
return V_19 ;
}
if ( V_49 ) {
F_69 ( & V_49 -> V_64 , & V_18 -> V_64 ) ;
F_36 ( V_10 , & V_49 -> V_12 ) ;
F_37 ( & V_49 -> V_63 , F_32 ) ;
} else {
F_70 ( & V_18 -> V_64 , & V_14 -> V_61 ) ;
}
* V_65 = ( unsigned long ) V_18 ;
return 0 ;
V_99:
F_28 ( & V_18 -> V_28 ) ;
F_31 ( V_18 ) ;
return V_19 ;
}
static int F_71 ( const struct V_17 * V_18 ,
struct V_7 * V_8 )
{
struct V_68 * V_114 ;
if ( F_72 ( V_8 , V_77 , V_18 -> V_76 ) )
return - V_115 ;
V_114 = F_73 ( V_8 , V_79 , V_18 -> V_76 *
sizeof( struct V_70 ) ) ;
if ( V_114 == NULL )
return - V_115 ;
memcpy ( F_49 ( V_114 ) , V_18 -> V_29 , F_48 ( V_114 ) ) ;
return 0 ;
}
static int F_74 ( const struct V_17 * V_18 ,
struct V_7 * V_8 )
{
struct V_68 * V_114 ;
if ( V_18 -> V_44 &&
F_75 ( V_8 , V_85 , V_18 -> V_44 ) )
return - V_115 ;
V_114 = F_73 ( V_8 , V_116 , sizeof( V_18 -> V_26 -> V_117 ) ) ;
if ( V_114 == NULL )
return - V_115 ;
memcpy ( F_49 ( V_114 ) , V_18 -> V_26 -> V_117 , F_48 ( V_114 ) ) ;
return 0 ;
}
static int F_76 ( struct V_89 * V_89 , struct V_9 * V_10 , unsigned long V_118 ,
struct V_7 * V_8 , struct V_119 * V_120 )
{
struct V_17 * V_18 = (struct V_17 * ) V_118 ;
struct V_68 * V_121 ;
T_1 V_101 = 0 ;
int V_19 ;
if ( V_18 == NULL )
return V_8 -> V_81 ;
V_120 -> V_122 = V_18 -> V_47 ;
F_22 ( V_10 , V_18 ) ;
V_121 = F_77 ( V_8 , V_111 ) ;
if ( V_121 == NULL )
goto V_123;
if ( V_18 -> V_12 . V_22 &&
F_78 ( V_8 , V_105 , V_18 -> V_12 . V_22 ) )
goto V_123;
if ( F_16 ( V_18 ) )
V_19 = F_74 ( V_18 , V_8 ) ;
else
V_19 = F_71 ( V_18 , V_8 ) ;
if ( V_19 )
goto V_123;
if ( F_79 ( V_8 , & V_18 -> V_28 ) < 0 )
goto V_123;
if ( V_18 -> V_24 )
V_101 |= V_102 ;
if ( V_101 && F_78 ( V_8 , V_100 , V_101 ) )
goto V_123;
if ( V_18 -> V_23 &&
F_78 ( V_8 , V_103 , V_18 -> V_23 ) )
goto V_123;
F_80 ( V_8 , V_121 ) ;
if ( F_81 ( V_8 , & V_18 -> V_28 ) < 0 )
goto V_123;
return V_8 -> V_81 ;
V_123:
F_82 ( V_8 , V_121 ) ;
return - 1 ;
}
static void F_83 ( struct V_9 * V_10 , struct V_124 * V_65 )
{
struct V_13 * V_14 = F_40 ( V_10 -> V_15 ) ;
struct V_17 * V_18 ;
F_45 (prog, &head->plist, link) {
if ( V_65 -> V_125 < V_65 -> V_126 )
goto V_126;
if ( V_65 -> V_127 ( V_10 , ( unsigned long ) V_18 , V_65 ) < 0 ) {
V_65 -> V_128 = 1 ;
break;
}
V_126:
V_65 -> V_125 ++ ;
}
}
static int T_3 F_84 ( void )
{
return F_85 ( & V_129 ) ;
}
static void T_4 F_86 ( void )
{
F_87 ( & V_129 ) ;
}
