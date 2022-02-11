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
struct V_39 V_40 ;
int V_41 ;
V_40 . type = V_42 ;
V_40 . V_43 = & V_38 ;
V_38 . V_44 = V_32 ;
V_38 . V_29 = & V_19 -> V_29 ;
V_38 . V_19 = V_19 -> V_27 ;
V_38 . V_45 = V_19 -> V_46 ;
V_38 . V_25 = V_19 -> V_25 ;
V_38 . V_24 = V_19 -> V_24 ;
V_41 = V_34 -> V_47 -> V_48 ( V_34 , V_11 -> V_35 -> V_49 ,
V_11 -> V_50 -> V_51 ,
V_11 -> V_52 , & V_40 ) ;
if ( ! V_41 && ( V_32 == V_53 || V_32 == V_54 ) )
V_19 -> V_24 |= V_55 ;
return V_41 ;
}
static int F_18 ( struct V_10 * V_11 , struct V_18 * V_19 ,
struct V_18 * V_56 )
{
struct V_33 * V_34 = V_11 -> V_35 -> V_36 -> V_34 ;
struct V_18 * V_57 = V_19 ;
enum V_31 V_32 ;
bool V_58 ;
int V_20 ;
V_58 = F_8 ( V_19 -> V_24 ) ||
( V_56 && F_8 ( V_56 -> V_24 ) ) ;
if ( V_56 && V_56 -> V_59 ) {
if ( F_19 ( V_34 , V_11 , V_19 -> V_24 ) ) {
V_32 = V_54 ;
} else if ( ! F_8 ( V_19 -> V_24 ) ) {
V_57 = V_56 ;
V_32 = V_60 ;
} else {
return - V_61 ;
}
} else {
if ( ! F_19 ( V_34 , V_11 , V_19 -> V_24 ) )
return V_58 ? - V_61 : 0 ;
V_32 = V_53 ;
}
V_20 = F_17 ( V_11 , V_57 , V_32 ) ;
if ( V_20 )
return V_58 ? V_20 : 0 ;
V_57 -> V_59 = true ;
if ( V_56 )
V_56 -> V_59 = false ;
return 0 ;
}
static void F_20 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
int V_41 ;
if ( ! V_19 -> V_59 )
return;
V_41 = F_17 ( V_11 , V_19 , V_60 ) ;
if ( V_41 ) {
F_21 ( L_1 , V_41 ) ;
return;
}
V_19 -> V_59 = false ;
}
static void F_22 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
if ( ! V_19 -> V_59 )
return;
F_17 ( V_11 , V_19 , V_62 ) ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_14 * V_15 ;
V_15 = F_24 ( sizeof( * V_15 ) , V_63 ) ;
if ( V_15 == NULL )
return - V_64 ;
F_25 ( & V_15 -> V_65 ) ;
F_26 ( V_11 -> V_16 , V_15 ) ;
return 0 ;
}
static void F_27 ( struct V_18 * V_19 )
{
F_28 ( & V_19 -> V_29 ) ;
if ( F_16 ( V_19 ) )
F_29 ( V_19 -> V_27 ) ;
else
F_30 ( V_19 -> V_27 ) ;
F_31 ( V_19 -> V_46 ) ;
F_31 ( V_19 -> V_30 ) ;
F_31 ( V_19 ) ;
}
static void F_32 ( struct V_66 * V_67 )
{
F_27 ( F_33 ( V_67 , struct V_18 , V_67 ) ) ;
}
static void F_34 ( struct V_10 * V_11 , struct V_18 * V_19 )
{
F_20 ( V_11 , V_19 ) ;
F_35 ( & V_19 -> V_68 ) ;
F_36 ( V_11 , & V_19 -> V_13 ) ;
F_37 ( & V_19 -> V_67 , F_32 ) ;
}
static int F_38 ( struct V_10 * V_11 , unsigned long V_69 , bool * V_70 )
{
struct V_14 * V_15 = F_39 ( V_11 -> V_16 ) ;
F_34 ( V_11 , (struct V_18 * ) V_69 ) ;
* V_70 = F_40 ( & V_15 -> V_65 ) ;
return 0 ;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = F_39 ( V_11 -> V_16 ) ;
struct V_18 * V_19 , * V_71 ;
F_42 (prog, tmp, &head->plist, link)
F_34 ( V_11 , V_19 ) ;
F_43 ( V_15 , V_67 ) ;
}
static unsigned long F_44 ( struct V_10 * V_11 , T_1 V_49 )
{
struct V_14 * V_15 = F_39 ( V_11 -> V_16 ) ;
struct V_18 * V_19 ;
unsigned long V_20 = 0UL ;
F_45 (prog, &head->plist, link) {
if ( V_19 -> V_49 == V_49 ) {
V_20 = ( unsigned long ) V_19 ;
break;
}
}
return V_20 ;
}
static int F_46 ( struct V_72 * * V_73 , struct V_18 * V_19 )
{
struct V_74 * V_30 ;
struct V_75 V_76 ;
struct V_77 * V_78 ;
T_2 V_79 , V_80 ;
int V_20 ;
V_80 = F_47 ( V_73 [ V_81 ] ) ;
if ( V_80 > V_82 || V_80 == 0 )
return - V_61 ;
V_79 = V_80 * sizeof( * V_30 ) ;
if ( V_79 != F_48 ( V_73 [ V_83 ] ) )
return - V_61 ;
V_30 = F_24 ( V_79 , V_63 ) ;
if ( V_30 == NULL )
return - V_84 ;
memcpy ( V_30 , F_49 ( V_73 [ V_83 ] ) , V_79 ) ;
V_76 . V_85 = V_80 ;
V_76 . V_27 = V_30 ;
V_20 = F_50 ( & V_78 , & V_76 ) ;
if ( V_20 < 0 ) {
F_31 ( V_30 ) ;
return V_20 ;
}
V_19 -> V_30 = V_30 ;
V_19 -> V_80 = V_80 ;
V_19 -> V_46 = NULL ;
V_19 -> V_27 = V_78 ;
return 0 ;
}
static int F_51 ( struct V_72 * * V_73 , struct V_18 * V_19 ,
const struct V_10 * V_11 )
{
struct V_77 * V_78 ;
char * V_45 = NULL ;
T_1 V_86 ;
V_86 = F_52 ( V_73 [ V_87 ] ) ;
V_78 = F_53 ( V_86 , V_88 ) ;
if ( F_54 ( V_78 ) )
return F_55 ( V_78 ) ;
if ( V_73 [ V_89 ] ) {
V_45 = F_56 ( V_73 [ V_89 ] , V_63 ) ;
if ( ! V_45 ) {
F_29 ( V_78 ) ;
return - V_84 ;
}
}
V_19 -> V_30 = NULL ;
V_19 -> V_46 = V_45 ;
V_19 -> V_27 = V_78 ;
if ( V_78 -> V_90 && ! ( V_11 -> V_35 -> V_91 & V_92 ) )
F_57 ( F_58 ( V_11 -> V_35 ) ) ;
return 0 ;
}
static int F_59 ( struct V_93 * V_93 , struct V_10 * V_11 ,
struct V_18 * V_19 ,
unsigned long V_94 , struct V_72 * * V_73 ,
struct V_72 * V_95 , bool V_96 )
{
bool V_97 , V_98 , V_99 = false ;
struct V_100 V_29 ;
T_1 V_24 = 0 ;
int V_20 ;
V_97 = V_73 [ V_81 ] && V_73 [ V_83 ] ;
V_98 = V_73 [ V_87 ] ;
if ( ( ! V_97 && ! V_98 ) || ( V_97 && V_98 ) )
return - V_61 ;
V_20 = F_60 ( & V_29 , V_101 , V_102 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_61 ( V_93 , V_11 , V_73 , V_95 , & V_29 , V_96 ) ;
if ( V_20 < 0 )
goto V_103;
if ( V_73 [ V_104 ] ) {
T_1 V_105 = F_52 ( V_73 [ V_104 ] ) ;
if ( V_105 & ~ V_106 ) {
V_20 = - V_61 ;
goto V_103;
}
V_99 = V_105 & V_106 ;
}
if ( V_73 [ V_107 ] ) {
V_24 = F_52 ( V_73 [ V_107 ] ) ;
if ( V_24 & ~ V_108 ||
! F_62 ( V_24 ) ) {
V_20 = - V_61 ;
goto V_103;
}
}
V_19 -> V_25 = V_99 ;
V_19 -> V_24 = V_24 ;
V_20 = V_97 ? F_46 ( V_73 , V_19 ) :
F_51 ( V_73 , V_19 , V_11 ) ;
if ( V_20 < 0 )
goto V_103;
if ( V_73 [ V_109 ] ) {
V_19 -> V_13 . V_23 = F_52 ( V_73 [ V_109 ] ) ;
F_63 ( V_11 , & V_19 -> V_13 , V_94 ) ;
}
F_64 ( V_11 , & V_19 -> V_29 , & V_29 ) ;
return 0 ;
V_103:
F_28 ( & V_29 ) ;
return V_20 ;
}
static T_1 F_65 ( struct V_10 * V_11 ,
struct V_14 * V_15 )
{
unsigned int V_110 = 0x80000000 ;
T_1 V_49 ;
do {
if ( ++ V_15 -> V_111 == 0x7FFFFFFF )
V_15 -> V_111 = 1 ;
} while ( -- V_110 > 0 && F_44 ( V_11 , V_15 -> V_111 ) );
if ( F_66 ( V_110 == 0 ) ) {
F_21 ( L_2 ) ;
V_49 = 0 ;
} else {
V_49 = V_15 -> V_111 ;
}
return V_49 ;
}
static int F_67 ( struct V_93 * V_93 , struct V_8 * V_112 ,
struct V_10 * V_11 , unsigned long V_94 ,
T_1 V_49 , struct V_72 * * V_113 ,
unsigned long * V_69 , bool V_96 )
{
struct V_14 * V_15 = F_39 ( V_11 -> V_16 ) ;
struct V_18 * V_56 = (struct V_18 * ) * V_69 ;
struct V_72 * V_73 [ V_114 + 1 ] ;
struct V_18 * V_19 ;
int V_20 ;
if ( V_113 [ V_115 ] == NULL )
return - V_61 ;
V_20 = F_68 ( V_73 , V_114 , V_113 [ V_115 ] , V_116 ,
NULL ) ;
if ( V_20 < 0 )
return V_20 ;
V_19 = F_24 ( sizeof( * V_19 ) , V_63 ) ;
if ( ! V_19 )
return - V_64 ;
V_20 = F_60 ( & V_19 -> V_29 , V_101 , V_102 ) ;
if ( V_20 < 0 )
goto V_103;
if ( V_56 ) {
if ( V_49 && V_56 -> V_49 != V_49 ) {
V_20 = - V_61 ;
goto V_103;
}
}
if ( V_49 == 0 )
V_19 -> V_49 = F_65 ( V_11 , V_15 ) ;
else
V_19 -> V_49 = V_49 ;
if ( V_19 -> V_49 == 0 ) {
V_20 = - V_61 ;
goto V_103;
}
V_20 = F_59 ( V_93 , V_11 , V_19 , V_94 , V_73 , V_113 [ V_117 ] ,
V_96 ) ;
if ( V_20 < 0 )
goto V_103;
V_20 = F_18 ( V_11 , V_19 , V_56 ) ;
if ( V_20 ) {
F_27 ( V_19 ) ;
return V_20 ;
}
if ( ! F_69 ( V_19 -> V_24 ) )
V_19 -> V_24 |= V_118 ;
if ( V_56 ) {
F_70 ( & V_56 -> V_68 , & V_19 -> V_68 ) ;
F_36 ( V_11 , & V_56 -> V_13 ) ;
F_37 ( & V_56 -> V_67 , F_32 ) ;
} else {
F_71 ( & V_19 -> V_68 , & V_15 -> V_65 ) ;
}
* V_69 = ( unsigned long ) V_19 ;
return 0 ;
V_103:
F_28 ( & V_19 -> V_29 ) ;
F_31 ( V_19 ) ;
return V_20 ;
}
static int F_72 ( const struct V_18 * V_19 ,
struct V_8 * V_9 )
{
struct V_72 * V_119 ;
if ( F_73 ( V_9 , V_81 , V_19 -> V_80 ) )
return - V_120 ;
V_119 = F_74 ( V_9 , V_83 , V_19 -> V_80 *
sizeof( struct V_74 ) ) ;
if ( V_119 == NULL )
return - V_120 ;
memcpy ( F_49 ( V_119 ) , V_19 -> V_30 , F_48 ( V_119 ) ) ;
return 0 ;
}
static int F_75 ( const struct V_18 * V_19 ,
struct V_8 * V_9 )
{
struct V_72 * V_119 ;
if ( V_19 -> V_46 &&
F_76 ( V_9 , V_89 , V_19 -> V_46 ) )
return - V_120 ;
if ( F_77 ( V_9 , V_121 , V_19 -> V_27 -> V_122 -> V_123 ) )
return - V_120 ;
V_119 = F_74 ( V_9 , V_124 , sizeof( V_19 -> V_27 -> V_125 ) ) ;
if ( V_119 == NULL )
return - V_120 ;
memcpy ( F_49 ( V_119 ) , V_19 -> V_27 -> V_125 , F_48 ( V_119 ) ) ;
return 0 ;
}
static int F_78 ( struct V_93 * V_93 , struct V_10 * V_11 , unsigned long V_126 ,
struct V_8 * V_9 , struct V_127 * V_128 )
{
struct V_18 * V_19 = (struct V_18 * ) V_126 ;
struct V_72 * V_129 ;
T_1 V_105 = 0 ;
int V_20 ;
if ( V_19 == NULL )
return V_9 -> V_85 ;
V_128 -> V_130 = V_19 -> V_49 ;
F_22 ( V_11 , V_19 ) ;
V_129 = F_79 ( V_9 , V_115 ) ;
if ( V_129 == NULL )
goto V_131;
if ( V_19 -> V_13 . V_23 &&
F_77 ( V_9 , V_109 , V_19 -> V_13 . V_23 ) )
goto V_131;
if ( F_16 ( V_19 ) )
V_20 = F_75 ( V_19 , V_9 ) ;
else
V_20 = F_72 ( V_19 , V_9 ) ;
if ( V_20 )
goto V_131;
if ( F_80 ( V_9 , & V_19 -> V_29 ) < 0 )
goto V_131;
if ( V_19 -> V_25 )
V_105 |= V_106 ;
if ( V_105 && F_77 ( V_9 , V_104 , V_105 ) )
goto V_131;
if ( V_19 -> V_24 &&
F_77 ( V_9 , V_107 , V_19 -> V_24 ) )
goto V_131;
F_81 ( V_9 , V_129 ) ;
if ( F_82 ( V_9 , & V_19 -> V_29 ) < 0 )
goto V_131;
return V_9 -> V_85 ;
V_131:
F_83 ( V_9 , V_129 ) ;
return - 1 ;
}
static void F_84 ( struct V_10 * V_11 , struct V_132 * V_69 )
{
struct V_14 * V_15 = F_39 ( V_11 -> V_16 ) ;
struct V_18 * V_19 ;
F_45 (prog, &head->plist, link) {
if ( V_69 -> V_133 < V_69 -> V_134 )
goto V_134;
if ( V_69 -> V_135 ( V_11 , ( unsigned long ) V_19 , V_69 ) < 0 ) {
V_69 -> V_136 = 1 ;
break;
}
V_134:
V_69 -> V_133 ++ ;
}
}
static int T_3 F_85 ( void )
{
return F_86 ( & V_137 ) ;
}
static void T_4 F_87 ( void )
{
F_88 ( & V_137 ) ;
}
