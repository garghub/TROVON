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
int V_40 ;
V_39 . type = V_41 ;
V_39 . V_42 = & V_37 ;
V_37 . V_43 = V_31 ;
V_37 . V_28 = & V_18 -> V_28 ;
V_37 . V_18 = V_18 -> V_26 ;
V_37 . V_44 = V_18 -> V_45 ;
V_37 . V_24 = V_18 -> V_24 ;
V_37 . V_23 = V_18 -> V_23 ;
V_40 = V_33 -> V_46 -> V_47 ( V_33 , V_10 -> V_34 -> V_48 ,
V_10 -> V_49 , & V_39 ) ;
if ( ! V_40 && ( V_31 == V_50 || V_31 == V_51 ) )
V_18 -> V_23 |= V_52 ;
return V_40 ;
}
static int F_18 ( struct V_9 * V_10 , struct V_17 * V_18 ,
struct V_17 * V_53 )
{
struct V_32 * V_33 = V_10 -> V_34 -> V_35 -> V_33 ;
struct V_17 * V_54 = V_18 ;
enum V_30 V_31 ;
bool V_55 ;
int V_19 ;
V_55 = F_8 ( V_18 -> V_23 ) ||
( V_53 && F_8 ( V_53 -> V_23 ) ) ;
if ( V_53 && V_53 -> V_56 ) {
if ( F_19 ( V_33 , V_10 , V_18 -> V_23 ) ) {
V_31 = V_51 ;
} else if ( ! F_8 ( V_18 -> V_23 ) ) {
V_54 = V_53 ;
V_31 = V_57 ;
} else {
return - V_58 ;
}
} else {
if ( ! F_19 ( V_33 , V_10 , V_18 -> V_23 ) )
return V_55 ? - V_58 : 0 ;
V_31 = V_50 ;
}
V_19 = F_17 ( V_10 , V_54 , V_31 ) ;
if ( V_19 )
return V_55 ? V_19 : 0 ;
V_54 -> V_56 = true ;
if ( V_53 )
V_53 -> V_56 = false ;
return 0 ;
}
static void F_20 ( struct V_9 * V_10 ,
struct V_17 * V_18 )
{
int V_40 ;
if ( ! V_18 -> V_56 )
return;
V_40 = F_17 ( V_10 , V_18 , V_57 ) ;
if ( V_40 ) {
F_21 ( L_1 , V_40 ) ;
return;
}
V_18 -> V_56 = false ;
}
static void F_22 ( struct V_9 * V_10 ,
struct V_17 * V_18 )
{
if ( ! V_18 -> V_56 )
return;
F_17 ( V_10 , V_18 , V_59 ) ;
}
static int F_23 ( struct V_9 * V_10 )
{
struct V_13 * V_14 ;
V_14 = F_24 ( sizeof( * V_14 ) , V_60 ) ;
if ( V_14 == NULL )
return - V_61 ;
F_25 ( & V_14 -> V_62 ) ;
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
F_31 ( V_18 -> V_45 ) ;
F_31 ( V_18 -> V_29 ) ;
F_31 ( V_18 ) ;
}
static void F_32 ( struct V_63 * V_64 )
{
F_27 ( F_33 ( V_64 , struct V_17 , V_64 ) ) ;
}
static void F_34 ( struct V_9 * V_10 , struct V_17 * V_18 )
{
F_20 ( V_10 , V_18 ) ;
F_35 ( & V_18 -> V_65 ) ;
F_36 ( V_10 , & V_18 -> V_12 ) ;
F_37 ( & V_18 -> V_64 , F_32 ) ;
}
static int F_38 ( struct V_9 * V_10 , unsigned long V_66 , bool * V_67 )
{
struct V_13 * V_14 = F_39 ( V_10 -> V_15 ) ;
F_34 ( V_10 , (struct V_17 * ) V_66 ) ;
* V_67 = F_40 ( & V_14 -> V_62 ) ;
return 0 ;
}
static void F_41 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_39 ( V_10 -> V_15 ) ;
struct V_17 * V_18 , * V_68 ;
F_42 (prog, tmp, &head->plist, link)
F_34 ( V_10 , V_18 ) ;
F_43 ( V_14 , V_64 ) ;
}
static unsigned long F_44 ( struct V_9 * V_10 , T_1 V_48 )
{
struct V_13 * V_14 = F_39 ( V_10 -> V_15 ) ;
struct V_17 * V_18 ;
unsigned long V_19 = 0UL ;
F_45 (prog, &head->plist, link) {
if ( V_18 -> V_48 == V_48 ) {
V_19 = ( unsigned long ) V_18 ;
break;
}
}
return V_19 ;
}
static int F_46 ( struct V_69 * * V_70 , struct V_17 * V_18 )
{
struct V_71 * V_29 ;
struct V_72 V_73 ;
struct V_74 * V_75 ;
T_2 V_76 , V_77 ;
int V_19 ;
V_77 = F_47 ( V_70 [ V_78 ] ) ;
if ( V_77 > V_79 || V_77 == 0 )
return - V_58 ;
V_76 = V_77 * sizeof( * V_29 ) ;
if ( V_76 != F_48 ( V_70 [ V_80 ] ) )
return - V_58 ;
V_29 = F_24 ( V_76 , V_60 ) ;
if ( V_29 == NULL )
return - V_81 ;
memcpy ( V_29 , F_49 ( V_70 [ V_80 ] ) , V_76 ) ;
V_73 . V_82 = V_77 ;
V_73 . V_26 = V_29 ;
V_19 = F_50 ( & V_75 , & V_73 ) ;
if ( V_19 < 0 ) {
F_31 ( V_29 ) ;
return V_19 ;
}
V_18 -> V_29 = V_29 ;
V_18 -> V_77 = V_77 ;
V_18 -> V_45 = NULL ;
V_18 -> V_26 = V_75 ;
return 0 ;
}
static int F_51 ( struct V_69 * * V_70 , struct V_17 * V_18 ,
const struct V_9 * V_10 )
{
struct V_74 * V_75 ;
char * V_44 = NULL ;
T_1 V_83 ;
V_83 = F_52 ( V_70 [ V_84 ] ) ;
V_75 = F_53 ( V_83 , V_85 ) ;
if ( F_54 ( V_75 ) )
return F_55 ( V_75 ) ;
if ( V_70 [ V_86 ] ) {
V_44 = F_56 ( V_70 [ V_86 ] , V_60 ) ;
if ( ! V_44 ) {
F_29 ( V_75 ) ;
return - V_81 ;
}
}
V_18 -> V_29 = NULL ;
V_18 -> V_45 = V_44 ;
V_18 -> V_26 = V_75 ;
if ( V_75 -> V_87 && ! ( V_10 -> V_34 -> V_88 & V_89 ) )
F_57 ( F_58 ( V_10 -> V_34 ) ) ;
return 0 ;
}
static int F_59 ( struct V_90 * V_90 , struct V_9 * V_10 ,
struct V_17 * V_18 ,
unsigned long V_91 , struct V_69 * * V_70 ,
struct V_69 * V_92 , bool V_93 )
{
bool V_94 , V_95 , V_96 = false ;
struct V_97 V_28 ;
T_1 V_23 = 0 ;
int V_19 ;
V_94 = V_70 [ V_78 ] && V_70 [ V_80 ] ;
V_95 = V_70 [ V_84 ] ;
if ( ( ! V_94 && ! V_95 ) || ( V_94 && V_95 ) )
return - V_58 ;
V_19 = F_60 ( & V_28 , V_98 , V_99 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_61 ( V_90 , V_10 , V_70 , V_92 , & V_28 , V_93 ) ;
if ( V_19 < 0 )
goto V_100;
if ( V_70 [ V_101 ] ) {
T_1 V_102 = F_52 ( V_70 [ V_101 ] ) ;
if ( V_102 & ~ V_103 ) {
V_19 = - V_58 ;
goto V_100;
}
V_96 = V_102 & V_103 ;
}
if ( V_70 [ V_104 ] ) {
V_23 = F_52 ( V_70 [ V_104 ] ) ;
if ( V_23 & ~ V_105 ||
! F_62 ( V_23 ) ) {
V_19 = - V_58 ;
goto V_100;
}
}
V_18 -> V_24 = V_96 ;
V_18 -> V_23 = V_23 ;
V_19 = V_94 ? F_46 ( V_70 , V_18 ) :
F_51 ( V_70 , V_18 , V_10 ) ;
if ( V_19 < 0 )
goto V_100;
if ( V_70 [ V_106 ] ) {
V_18 -> V_12 . V_22 = F_52 ( V_70 [ V_106 ] ) ;
F_63 ( V_10 , & V_18 -> V_12 , V_91 ) ;
}
F_64 ( V_10 , & V_18 -> V_28 , & V_28 ) ;
return 0 ;
V_100:
F_28 ( & V_28 ) ;
return V_19 ;
}
static T_1 F_65 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
unsigned int V_107 = 0x80000000 ;
T_1 V_48 ;
do {
if ( ++ V_14 -> V_108 == 0x7FFFFFFF )
V_14 -> V_108 = 1 ;
} while ( -- V_107 > 0 && F_44 ( V_10 , V_14 -> V_108 ) );
if ( F_66 ( V_107 == 0 ) ) {
F_21 ( L_2 ) ;
V_48 = 0 ;
} else {
V_48 = V_14 -> V_108 ;
}
return V_48 ;
}
static int F_67 ( struct V_90 * V_90 , struct V_7 * V_109 ,
struct V_9 * V_10 , unsigned long V_91 ,
T_1 V_48 , struct V_69 * * V_110 ,
unsigned long * V_66 , bool V_93 )
{
struct V_13 * V_14 = F_39 ( V_10 -> V_15 ) ;
struct V_17 * V_53 = (struct V_17 * ) * V_66 ;
struct V_69 * V_70 [ V_111 + 1 ] ;
struct V_17 * V_18 ;
int V_19 ;
if ( V_110 [ V_112 ] == NULL )
return - V_58 ;
V_19 = F_68 ( V_70 , V_111 , V_110 [ V_112 ] , V_113 ,
NULL ) ;
if ( V_19 < 0 )
return V_19 ;
V_18 = F_24 ( sizeof( * V_18 ) , V_60 ) ;
if ( ! V_18 )
return - V_61 ;
V_19 = F_60 ( & V_18 -> V_28 , V_98 , V_99 ) ;
if ( V_19 < 0 )
goto V_100;
if ( V_53 ) {
if ( V_48 && V_53 -> V_48 != V_48 ) {
V_19 = - V_58 ;
goto V_100;
}
}
if ( V_48 == 0 )
V_18 -> V_48 = F_65 ( V_10 , V_14 ) ;
else
V_18 -> V_48 = V_48 ;
if ( V_18 -> V_48 == 0 ) {
V_19 = - V_58 ;
goto V_100;
}
V_19 = F_59 ( V_90 , V_10 , V_18 , V_91 , V_70 , V_110 [ V_114 ] ,
V_93 ) ;
if ( V_19 < 0 )
goto V_100;
V_19 = F_18 ( V_10 , V_18 , V_53 ) ;
if ( V_19 ) {
F_27 ( V_18 ) ;
return V_19 ;
}
if ( ! F_69 ( V_18 -> V_23 ) )
V_18 -> V_23 |= V_115 ;
if ( V_53 ) {
F_70 ( & V_53 -> V_65 , & V_18 -> V_65 ) ;
F_36 ( V_10 , & V_53 -> V_12 ) ;
F_37 ( & V_53 -> V_64 , F_32 ) ;
} else {
F_71 ( & V_18 -> V_65 , & V_14 -> V_62 ) ;
}
* V_66 = ( unsigned long ) V_18 ;
return 0 ;
V_100:
F_28 ( & V_18 -> V_28 ) ;
F_31 ( V_18 ) ;
return V_19 ;
}
static int F_72 ( const struct V_17 * V_18 ,
struct V_7 * V_8 )
{
struct V_69 * V_116 ;
if ( F_73 ( V_8 , V_78 , V_18 -> V_77 ) )
return - V_117 ;
V_116 = F_74 ( V_8 , V_80 , V_18 -> V_77 *
sizeof( struct V_71 ) ) ;
if ( V_116 == NULL )
return - V_117 ;
memcpy ( F_49 ( V_116 ) , V_18 -> V_29 , F_48 ( V_116 ) ) ;
return 0 ;
}
static int F_75 ( const struct V_17 * V_18 ,
struct V_7 * V_8 )
{
struct V_69 * V_116 ;
if ( V_18 -> V_45 &&
F_76 ( V_8 , V_86 , V_18 -> V_45 ) )
return - V_117 ;
V_116 = F_74 ( V_8 , V_118 , sizeof( V_18 -> V_26 -> V_119 ) ) ;
if ( V_116 == NULL )
return - V_117 ;
memcpy ( F_49 ( V_116 ) , V_18 -> V_26 -> V_119 , F_48 ( V_116 ) ) ;
return 0 ;
}
static int F_77 ( struct V_90 * V_90 , struct V_9 * V_10 , unsigned long V_120 ,
struct V_7 * V_8 , struct V_121 * V_122 )
{
struct V_17 * V_18 = (struct V_17 * ) V_120 ;
struct V_69 * V_123 ;
T_1 V_102 = 0 ;
int V_19 ;
if ( V_18 == NULL )
return V_8 -> V_82 ;
V_122 -> V_124 = V_18 -> V_48 ;
F_22 ( V_10 , V_18 ) ;
V_123 = F_78 ( V_8 , V_112 ) ;
if ( V_123 == NULL )
goto V_125;
if ( V_18 -> V_12 . V_22 &&
F_79 ( V_8 , V_106 , V_18 -> V_12 . V_22 ) )
goto V_125;
if ( F_16 ( V_18 ) )
V_19 = F_75 ( V_18 , V_8 ) ;
else
V_19 = F_72 ( V_18 , V_8 ) ;
if ( V_19 )
goto V_125;
if ( F_80 ( V_8 , & V_18 -> V_28 ) < 0 )
goto V_125;
if ( V_18 -> V_24 )
V_102 |= V_103 ;
if ( V_102 && F_79 ( V_8 , V_101 , V_102 ) )
goto V_125;
if ( V_18 -> V_23 &&
F_79 ( V_8 , V_104 , V_18 -> V_23 ) )
goto V_125;
F_81 ( V_8 , V_123 ) ;
if ( F_82 ( V_8 , & V_18 -> V_28 ) < 0 )
goto V_125;
return V_8 -> V_82 ;
V_125:
F_83 ( V_8 , V_123 ) ;
return - 1 ;
}
static void F_84 ( struct V_9 * V_10 , struct V_126 * V_66 )
{
struct V_13 * V_14 = F_39 ( V_10 -> V_15 ) ;
struct V_17 * V_18 ;
F_45 (prog, &head->plist, link) {
if ( V_66 -> V_127 < V_66 -> V_128 )
goto V_128;
if ( V_66 -> V_129 ( V_10 , ( unsigned long ) V_18 , V_66 ) < 0 ) {
V_66 -> V_130 = 1 ;
break;
}
V_128:
V_66 -> V_127 ++ ;
}
}
static int T_3 F_85 ( void )
{
return F_86 ( & V_131 ) ;
}
static void T_4 F_87 ( void )
{
F_88 ( & V_131 ) ;
}
