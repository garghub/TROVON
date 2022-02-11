static struct V_1 * F_1 ( void )
{
struct V_1 * V_1 = F_2 ( sizeof( * V_1 ) , V_2 ) ;
if ( V_1 ) {
V_1 -> V_3 = true ;
F_3 ( & V_1 -> V_4 , V_4 ) ;
}
return V_1 ;
}
static void F_4 ( struct V_1 * V_1 )
{
F_5 ( V_1 ) ;
}
static struct V_5 * F_6 ( void )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_2 ) ;
if ( V_6 )
F_7 ( & V_6 -> V_7 ) ;
return V_6 ;
}
static void F_8 ( struct V_8 * V_7 , struct V_9 * V_10 )
{
struct V_1 * V_1 , * V_11 ;
F_9 (pgpath, tmp, pgpaths, list) {
F_10 ( & V_1 -> V_12 ) ;
F_11 ( V_10 , V_1 -> V_13 . V_14 ) ;
F_4 ( V_1 ) ;
}
}
static void F_12 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
struct V_15 * V_16 = & V_6 -> V_16 ;
if ( V_16 -> type ) {
V_16 -> type -> V_17 ( V_16 ) ;
F_13 ( V_16 -> type ) ;
}
F_8 ( & V_6 -> V_7 , V_10 ) ;
F_5 ( V_6 ) ;
}
static struct V_18 * F_14 ( struct V_9 * V_10 )
{
struct V_18 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_2 ) ;
if ( V_19 ) {
F_7 ( & V_19 -> V_20 ) ;
F_15 ( & V_19 -> V_21 ) ;
F_16 ( V_22 , & V_19 -> V_23 ) ;
F_17 ( & V_19 -> V_24 , 0 ) ;
F_17 ( & V_19 -> V_25 , 0 ) ;
F_17 ( & V_19 -> V_26 , 0 ) ;
V_19 -> V_27 = V_28 ;
F_18 ( & V_19 -> V_29 , V_29 ) ;
F_19 ( & V_19 -> V_30 ) ;
F_20 ( & V_19 -> V_31 ) ;
V_19 -> V_32 = NULL ;
V_19 -> V_33 = V_34 ;
V_19 -> V_10 = V_10 ;
V_10 -> V_35 = V_19 ;
}
return V_19 ;
}
static int F_21 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
if ( V_19 -> V_33 == V_34 ) {
if ( F_22 ( F_23 ( V_10 -> V_36 ) ) )
V_19 -> V_33 = V_37 ;
else
V_19 -> V_33 = V_38 ;
}
if ( V_19 -> V_33 == V_38 ) {
unsigned V_39 = F_24 () ;
V_19 -> V_32 = F_25 ( V_39 , V_40 ) ;
if ( ! V_19 -> V_32 )
return - V_41 ;
}
else if ( V_19 -> V_33 == V_42 ) {
F_18 ( & V_19 -> V_43 , V_43 ) ;
F_16 ( V_44 , & V_19 -> V_23 ) ;
}
F_26 ( V_10 -> V_36 , V_19 -> V_33 ) ;
return 0 ;
}
static void F_27 ( struct V_18 * V_19 )
{
struct V_5 * V_6 , * V_11 ;
F_9 (pg, tmp, &m->priority_groups, list) {
F_10 ( & V_6 -> V_12 ) ;
F_12 ( V_6 , V_19 -> V_10 ) ;
}
F_5 ( V_19 -> V_45 ) ;
F_5 ( V_19 -> V_46 ) ;
F_28 ( V_19 -> V_32 ) ;
F_5 ( V_19 ) ;
}
static struct V_47 * F_29 ( union V_48 * V_49 )
{
return V_49 -> V_50 ;
}
static struct V_47 * F_30 ( struct V_18 * V_19 , union V_48 * V_49 )
{
struct V_47 * V_51 ;
if ( ! V_19 -> V_32 ) {
V_51 = F_29 ( V_49 ) ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
return V_51 ;
}
V_51 = F_31 ( V_19 -> V_32 , V_52 ) ;
if ( ! V_51 )
return NULL ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_49 -> V_50 = V_51 ;
return V_51 ;
}
static void F_32 ( struct V_18 * V_19 , union V_48 * V_49 )
{
if ( V_19 -> V_32 ) {
struct V_47 * V_51 = V_49 -> V_50 ;
V_49 -> V_50 = NULL ;
F_33 ( V_51 , V_19 -> V_32 ) ;
}
}
static T_1 F_34 ( void )
{
return sizeof( struct V_47 ) + sizeof( struct V_53 ) ;
}
static struct V_47 * F_35 ( struct V_54 * V_54 )
{
return F_36 ( V_54 , F_34 () ) ;
}
static struct V_53 * F_37 ( struct V_54 * V_54 )
{
struct V_47 * V_51 = F_35 ( V_54 ) ;
void * V_55 = V_51 + 1 ;
return V_55 ;
}
static void F_38 ( struct V_54 * V_54 , struct V_47 * * V_56 ,
struct V_53 * * V_57 )
{
struct V_47 * V_51 = F_35 ( V_54 ) ;
struct V_53 * V_55 = F_37 ( V_54 ) ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
F_39 ( V_55 , V_54 ) ;
if ( V_56 )
* V_56 = V_51 ;
if ( V_57 )
* V_57 = V_55 ;
}
static int F_40 ( struct V_18 * V_19 )
{
struct V_1 * V_1 ;
unsigned long V_58 = 0 ;
if ( F_41 ( & V_19 -> V_25 ) || F_42 ( V_59 , & V_19 -> V_23 ) )
return 0 ;
F_43 ( & V_19 -> V_26 ) ;
F_44 ( V_60 , & V_19 -> V_23 ) ;
if ( ! V_19 -> V_61 )
return 0 ;
if ( F_42 ( V_62 , & V_19 -> V_23 ) )
V_58 = F_45 ( V_19 -> V_27 != V_28 ?
V_19 -> V_27 : V_63 ) ;
F_46 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_47 ( V_64 , & V_1 -> V_4 ,
V_58 ) )
F_43 ( & V_19 -> V_25 ) ;
}
return F_41 ( & V_19 -> V_25 ) ;
}
static int F_48 ( struct V_18 * V_19 )
{
int V_65 ;
unsigned long V_23 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
V_65 = F_40 ( V_19 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
return V_65 ;
}
static void F_51 ( struct V_18 * V_19 , struct V_5 * V_6 )
{
V_19 -> V_61 = V_6 ;
if ( V_19 -> V_45 ) {
F_16 ( V_60 , & V_19 -> V_23 ) ;
F_16 ( V_22 , & V_19 -> V_23 ) ;
} else {
F_44 ( V_60 , & V_19 -> V_23 ) ;
F_44 ( V_22 , & V_19 -> V_23 ) ;
}
F_17 ( & V_19 -> V_26 , 0 ) ;
}
static struct V_1 * F_52 ( struct V_18 * V_19 ,
struct V_5 * V_6 ,
T_1 V_66 )
{
unsigned long V_23 ;
struct V_67 * V_13 ;
struct V_1 * V_1 ;
V_13 = V_6 -> V_16 . type -> V_68 ( & V_6 -> V_16 , V_66 ) ;
if ( ! V_13 )
return F_53 ( - V_69 ) ;
V_1 = F_54 ( V_13 ) ;
if ( F_55 ( F_56 ( V_19 -> V_61 ) != V_6 ) ) {
F_49 ( & V_19 -> V_21 , V_23 ) ;
V_19 -> V_70 = V_1 ;
F_51 ( V_19 , V_6 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
}
return V_1 ;
}
static struct V_1 * F_57 ( struct V_18 * V_19 , T_1 V_66 )
{
unsigned long V_23 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
bool V_71 = true ;
if ( ! F_41 ( & V_19 -> V_24 ) ) {
F_44 ( V_22 , & V_19 -> V_23 ) ;
goto V_72;
}
if ( F_56 ( V_19 -> V_73 ) ) {
F_49 ( & V_19 -> V_21 , V_23 ) ;
V_6 = V_19 -> V_73 ;
if ( ! V_6 ) {
F_50 ( & V_19 -> V_21 , V_23 ) ;
goto V_74;
}
V_19 -> V_73 = NULL ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
V_1 = F_52 ( V_19 , V_6 , V_66 ) ;
if ( ! F_58 ( V_1 ) )
return V_1 ;
}
V_74:
V_6 = F_56 ( V_19 -> V_61 ) ;
if ( V_6 ) {
V_1 = F_52 ( V_19 , V_6 , V_66 ) ;
if ( ! F_58 ( V_1 ) )
return V_1 ;
}
do {
F_46 (pg, &m->priority_groups, list) {
if ( V_6 -> V_71 == V_71 )
continue;
V_1 = F_52 ( V_19 , V_6 , V_66 ) ;
if ( ! F_58 ( V_1 ) ) {
if ( ! V_71 )
F_16 ( V_62 , & V_19 -> V_23 ) ;
return V_1 ;
}
}
} while ( V_71 -- );
V_72:
F_49 ( & V_19 -> V_21 , V_23 ) ;
V_19 -> V_70 = NULL ;
V_19 -> V_61 = NULL ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
return NULL ;
}
static bool F_59 ( struct V_18 * V_19 )
{
return ( ( F_42 ( V_75 , & V_19 -> V_23 ) !=
F_42 ( V_76 , & V_19 -> V_23 ) ) &&
F_60 ( V_19 -> V_10 ) ) ;
}
static bool F_61 ( struct V_18 * V_19 )
{
bool V_65 ;
unsigned long V_23 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
V_65 = ( F_42 ( V_75 , & V_19 -> V_23 ) ||
F_59 ( V_19 ) ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
return V_65 ;
}
static bool F_62 ( struct V_18 * V_19 )
{
bool V_65 ;
unsigned long V_23 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
V_65 = F_59 ( V_19 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
return V_65 ;
}
static int F_63 ( struct V_9 * V_10 , struct V_77 * V_78 ,
union V_48 * V_79 ,
struct V_77 * V_80 , struct V_77 * * V_81 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
int V_65 = V_82 ;
T_1 V_66 = V_78 ? F_64 ( V_78 ) : F_64 ( V_80 ) ;
struct V_1 * V_1 ;
struct V_83 * V_84 ;
struct V_47 * V_51 ;
V_1 = F_56 ( V_19 -> V_70 ) ;
if ( ! V_1 || ! F_42 ( V_22 , & V_19 -> V_23 ) )
V_1 = F_57 ( V_19 , V_66 ) ;
if ( ! V_1 ) {
if ( ! F_61 ( V_19 ) )
V_65 = - V_85 ;
return V_65 ;
} else if ( F_42 ( V_22 , & V_19 -> V_23 ) ||
F_42 ( V_60 , & V_19 -> V_23 ) ) {
F_48 ( V_19 ) ;
return V_65 ;
}
V_51 = F_30 ( V_19 , V_79 ) ;
if ( ! V_51 )
return V_65 ;
V_51 -> V_1 = V_1 ;
V_51 -> V_66 = V_66 ;
V_84 = V_1 -> V_13 . V_14 -> V_84 ;
if ( V_78 ) {
V_78 -> V_86 = F_65 ( V_84 ) ;
V_78 -> V_87 = V_84 -> V_88 ;
V_78 -> V_89 |= V_90 ;
} else {
* V_81 = F_66 ( F_65 ( V_84 ) ,
F_67 ( V_80 ) , V_91 ) ;
if ( F_68 ( * V_81 ) ) {
F_32 ( V_19 , V_79 ) ;
return V_65 ;
}
( * V_81 ) -> V_54 = ( * V_81 ) -> V_92 = NULL ;
( * V_81 ) -> V_87 = V_84 -> V_88 ;
( * V_81 ) -> V_89 |= V_90 ;
}
if ( V_1 -> V_6 -> V_16 . type -> V_93 )
V_1 -> V_6 -> V_16 . type -> V_93 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_66 ) ;
return V_94 ;
}
static int F_69 ( struct V_9 * V_10 , struct V_77 * V_78 ,
union V_48 * V_79 )
{
return F_63 ( V_10 , V_78 , V_79 , NULL , NULL ) ;
}
static int F_70 ( struct V_9 * V_10 , struct V_77 * V_80 ,
union V_48 * V_79 ,
struct V_77 * * V_78 )
{
return F_63 ( V_10 , NULL , V_79 , V_80 , V_78 ) ;
}
static void F_71 ( struct V_77 * V_78 )
{
F_72 ( V_78 ) ;
}
static int F_73 ( struct V_18 * V_19 , struct V_54 * V_54 , struct V_47 * V_51 )
{
T_1 V_66 = V_54 -> V_95 . V_96 ;
struct V_1 * V_1 ;
unsigned long V_23 ;
bool V_97 ;
V_1 = F_56 ( V_19 -> V_70 ) ;
V_97 = F_42 ( V_22 , & V_19 -> V_23 ) ;
if ( ! V_1 || ! V_97 )
V_1 = F_57 ( V_19 , V_66 ) ;
if ( ( V_1 && V_97 ) ||
( ! V_1 && F_42 ( V_75 , & V_19 -> V_23 ) ) ) {
F_49 ( & V_19 -> V_21 , V_23 ) ;
F_74 ( & V_19 -> V_98 , V_54 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
if ( V_97 || F_42 ( V_60 , & V_19 -> V_23 ) )
F_48 ( V_19 ) ;
else if ( ! V_97 )
F_75 ( V_99 , & V_19 -> V_43 ) ;
return V_100 ;
}
if ( ! V_1 ) {
if ( ! F_62 ( V_19 ) )
return - V_85 ;
return V_82 ;
}
V_51 -> V_1 = V_1 ;
V_51 -> V_66 = V_66 ;
V_54 -> V_101 = 0 ;
V_54 -> V_102 = V_1 -> V_13 . V_14 -> V_84 ;
V_54 -> V_103 |= V_90 ;
if ( V_1 -> V_6 -> V_16 . type -> V_93 )
V_1 -> V_6 -> V_16 . type -> V_93 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_66 ) ;
return V_94 ;
}
static int F_76 ( struct V_9 * V_10 , struct V_54 * V_54 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_47 * V_51 = NULL ;
F_38 ( V_54 , & V_51 , NULL ) ;
return F_73 ( V_19 , V_54 , V_51 ) ;
}
static void F_77 ( struct V_18 * V_19 )
{
if ( V_19 -> V_33 == V_42 )
F_75 ( V_99 , & V_19 -> V_43 ) ;
}
static void V_43 ( struct V_104 * V_105 )
{
int V_65 ;
unsigned long V_23 ;
struct V_54 * V_54 ;
struct V_106 V_107 ;
struct V_108 V_109 ;
struct V_18 * V_19 =
F_78 ( V_105 , struct V_18 , V_43 ) ;
F_79 ( & V_107 ) ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( F_80 ( & V_19 -> V_98 ) ) {
F_50 ( & V_19 -> V_21 , V_23 ) ;
return;
}
F_81 ( & V_107 , & V_19 -> V_98 ) ;
F_79 ( & V_19 -> V_98 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
F_82 ( & V_109 ) ;
while ( ( V_54 = F_83 ( & V_107 ) ) ) {
V_65 = F_73 ( V_19 , V_54 , F_35 ( V_54 ) ) ;
if ( V_65 < 0 || V_65 == V_82 ) {
V_54 -> V_101 = V_65 ;
F_84 ( V_54 ) ;
} else if ( V_65 == V_94 )
F_85 ( V_54 ) ;
}
F_86 ( & V_109 ) ;
}
static int F_87 ( struct V_18 * V_19 , bool F_87 ,
bool V_110 )
{
unsigned long V_23 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( V_110 ) {
if ( F_42 ( V_75 , & V_19 -> V_23 ) )
F_16 ( V_76 , & V_19 -> V_23 ) ;
else
F_44 ( V_76 , & V_19 -> V_23 ) ;
} else {
if ( F_87 )
F_16 ( V_76 , & V_19 -> V_23 ) ;
else
F_44 ( V_76 , & V_19 -> V_23 ) ;
}
if ( F_87 )
F_16 ( V_75 , & V_19 -> V_23 ) ;
else
F_44 ( V_75 , & V_19 -> V_23 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
if ( ! F_87 ) {
F_88 ( V_19 -> V_10 -> V_36 ) ;
F_77 ( V_19 ) ;
}
return 0 ;
}
static void V_29 ( struct V_104 * V_105 )
{
struct V_18 * V_19 =
F_78 ( V_105 , struct V_18 , V_29 ) ;
F_89 ( V_19 -> V_10 -> V_36 ) ;
}
static int F_90 ( struct V_111 * V_112 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_65 ;
struct V_113 * V_114 ;
unsigned V_115 ;
static struct V_116 V_117 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_114 = F_91 ( F_92 ( V_112 ) ) ;
if ( ! V_114 ) {
V_10 -> error = L_2 ;
return - V_118 ;
}
V_65 = F_93 ( V_117 , V_112 , & V_115 , & V_10 -> error ) ;
if ( V_65 ) {
F_13 ( V_114 ) ;
return - V_118 ;
}
V_65 = V_114 -> V_119 ( & V_6 -> V_16 , V_115 , V_112 -> V_120 ) ;
if ( V_65 ) {
F_13 ( V_114 ) ;
V_10 -> error = L_3 ;
return V_65 ;
}
V_6 -> V_16 . type = V_114 ;
F_94 ( V_112 , V_115 ) ;
return 0 ;
}
static struct V_1 * F_95 ( struct V_111 * V_112 , struct V_15 * V_16 ,
struct V_9 * V_10 )
{
int V_65 ;
struct V_1 * V_121 ;
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_122 * V_86 = NULL ;
const char * V_123 ;
if ( V_112 -> V_124 < 1 ) {
V_10 -> error = L_4 ;
return F_53 ( - V_118 ) ;
}
V_121 = F_1 () ;
if ( ! V_121 )
return F_53 ( - V_41 ) ;
V_65 = F_96 ( V_10 , F_92 ( V_112 ) , F_97 ( V_10 -> V_36 ) ,
& V_121 -> V_13 . V_14 ) ;
if ( V_65 ) {
V_10 -> error = L_5 ;
goto V_125;
}
if ( F_42 ( V_44 , & V_19 -> V_23 ) || V_19 -> V_45 )
V_86 = F_65 ( V_121 -> V_13 . V_14 -> V_84 ) ;
if ( F_42 ( V_44 , & V_19 -> V_23 ) ) {
V_126:
V_123 = F_98 ( V_86 , V_2 ) ;
if ( V_123 ) {
F_5 ( V_19 -> V_45 ) ;
V_19 -> V_45 = V_123 ;
F_5 ( V_19 -> V_46 ) ;
V_19 -> V_46 = NULL ;
}
}
if ( V_19 -> V_45 ) {
V_65 = F_99 ( V_86 , V_19 -> V_45 ) ;
if ( V_65 == - V_127 ) {
char V_128 [ V_129 ] ;
F_100 ( V_130 L_6 ,
F_101 ( V_121 -> V_13 . V_14 -> V_84 , V_128 ) ) ;
goto V_126;
}
if ( V_65 < 0 ) {
V_10 -> error = L_7 ;
F_11 ( V_10 , V_121 -> V_13 . V_14 ) ;
goto V_125;
}
if ( V_19 -> V_46 ) {
V_65 = F_102 ( V_86 , V_19 -> V_46 ) ;
if ( V_65 < 0 ) {
V_10 -> error = L_8
L_9 ;
F_11 ( V_10 , V_121 -> V_13 . V_14 ) ;
goto V_125;
}
}
}
V_65 = V_16 -> type -> V_131 ( V_16 , & V_121 -> V_13 , V_112 -> V_124 , V_112 -> V_120 , & V_10 -> error ) ;
if ( V_65 ) {
F_11 ( V_10 , V_121 -> V_13 . V_14 ) ;
goto V_125;
}
return V_121 ;
V_125:
F_4 ( V_121 ) ;
return F_53 ( V_65 ) ;
}
static struct V_5 * F_103 ( struct V_111 * V_112 ,
struct V_18 * V_19 )
{
static struct V_116 V_117 [] = {
{ 1 , 1024 , L_10 } ,
{ 0 , 1024 , L_11 }
} ;
int V_65 ;
unsigned V_132 , V_133 , V_134 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_19 -> V_10 ;
if ( V_112 -> V_124 < 2 ) {
V_112 -> V_124 = 0 ;
V_10 -> error = L_12 ;
return F_53 ( - V_118 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_13 ;
return F_53 ( - V_41 ) ;
}
V_6 -> V_19 = V_19 ;
V_65 = F_90 ( V_112 , V_6 , V_10 ) ;
if ( V_65 )
goto V_125;
V_65 = F_104 ( V_117 , V_112 , & V_6 -> V_135 , & V_10 -> error ) ;
if ( V_65 )
goto V_125;
V_65 = F_104 ( V_117 + 1 , V_112 , & V_133 , & V_10 -> error ) ;
if ( V_65 )
goto V_125;
V_134 = 1 + V_133 ;
for ( V_132 = 0 ; V_132 < V_6 -> V_135 ; V_132 ++ ) {
struct V_1 * V_1 ;
struct V_111 V_136 ;
if ( V_112 -> V_124 < V_134 ) {
V_10 -> error = L_14 ;
V_65 = - V_118 ;
goto V_125;
}
V_136 . V_124 = V_134 ;
V_136 . V_120 = V_112 -> V_120 ;
V_1 = F_95 ( & V_136 , & V_6 -> V_16 , V_10 ) ;
if ( F_68 ( V_1 ) ) {
V_65 = F_105 ( V_1 ) ;
goto V_125;
}
V_1 -> V_6 = V_6 ;
F_106 ( & V_1 -> V_12 , & V_6 -> V_7 ) ;
F_94 ( V_112 , V_134 ) ;
}
return V_6 ;
V_125:
F_12 ( V_6 , V_10 ) ;
return F_53 ( V_65 ) ;
}
static int F_107 ( struct V_111 * V_112 , struct V_18 * V_19 )
{
unsigned V_137 ;
int V_138 ;
struct V_9 * V_10 = V_19 -> V_10 ;
static struct V_116 V_117 [] = {
{ 0 , 1024 , L_15 } ,
} ;
if ( F_93 ( V_117 , V_112 , & V_137 , & V_10 -> error ) )
return - V_118 ;
if ( ! V_137 )
return 0 ;
if ( V_19 -> V_33 == V_42 ) {
F_94 ( V_112 , V_137 ) ;
F_108 ( L_16 ) ;
return 0 ;
}
V_19 -> V_45 = F_109 ( F_92 ( V_112 ) , V_2 ) ;
if ( V_137 > 1 ) {
char * V_121 ;
int V_132 , V_139 , V_140 = 4 ;
for ( V_132 = 0 ; V_132 <= V_137 - 2 ; V_132 ++ )
V_140 += strlen ( V_112 -> V_120 [ V_132 ] ) + 1 ;
V_121 = V_19 -> V_46 = F_2 ( V_140 , V_2 ) ;
if ( ! V_121 ) {
V_10 -> error = L_17 ;
V_138 = - V_41 ;
goto V_141;
}
V_139 = sprintf ( V_121 , L_18 , V_137 - 1 ) ;
for ( V_132 = 0 , V_121 += V_139 + 1 ; V_132 <= V_137 - 2 ; V_132 ++ , V_121 += V_139 + 1 )
V_139 = sprintf ( V_121 , L_19 , V_112 -> V_120 [ V_132 ] ) ;
}
F_94 ( V_112 , V_137 - 1 ) ;
return 0 ;
V_141:
F_5 ( V_19 -> V_45 ) ;
V_19 -> V_45 = NULL ;
return V_138 ;
}
static int F_110 ( struct V_111 * V_112 , struct V_18 * V_19 )
{
int V_65 ;
unsigned V_124 ;
struct V_9 * V_10 = V_19 -> V_10 ;
const char * V_142 ;
static struct V_116 V_117 [] = {
{ 0 , 8 , L_20 } ,
{ 1 , 50 , L_21 } ,
{ 0 , 60000 , L_22 } ,
} ;
V_65 = F_93 ( V_117 , V_112 , & V_124 , & V_10 -> error ) ;
if ( V_65 )
return - V_118 ;
if ( ! V_124 )
return 0 ;
do {
V_142 = F_92 ( V_112 ) ;
V_124 -- ;
if ( ! strcasecmp ( V_142 , L_23 ) ) {
V_65 = F_87 ( V_19 , true , false ) ;
continue;
}
if ( ! strcasecmp ( V_142 , L_24 ) ) {
F_16 ( V_44 , & V_19 -> V_23 ) ;
continue;
}
if ( ! strcasecmp ( V_142 , L_25 ) &&
( V_124 >= 1 ) ) {
V_65 = F_104 ( V_117 + 1 , V_112 , & V_19 -> V_143 , & V_10 -> error ) ;
V_124 -- ;
continue;
}
if ( ! strcasecmp ( V_142 , L_26 ) &&
( V_124 >= 1 ) ) {
V_65 = F_104 ( V_117 + 2 , V_112 , & V_19 -> V_27 , & V_10 -> error ) ;
V_124 -- ;
continue;
}
if ( ! strcasecmp ( V_142 , L_27 ) &&
( V_124 >= 1 ) ) {
const char * V_144 = F_92 ( V_112 ) ;
if ( ! strcasecmp ( V_144 , L_28 ) )
V_19 -> V_33 = V_42 ;
else if ( ! strcasecmp ( V_144 , L_29 ) )
V_19 -> V_33 = V_38 ;
else if ( ! strcasecmp ( V_144 , L_30 ) )
V_19 -> V_33 = V_37 ;
else {
V_10 -> error = L_31 ;
V_65 = - V_118 ;
}
V_124 -- ;
continue;
}
V_10 -> error = L_32 ;
V_65 = - V_118 ;
} while ( V_124 && ! V_65 );
return V_65 ;
}
static int F_111 ( struct V_9 * V_10 , unsigned V_124 , char * * V_120 )
{
static struct V_116 V_117 [] = {
{ 0 , 1024 , L_33 } ,
{ 0 , 1024 , L_34 } ,
} ;
int V_65 ;
struct V_18 * V_19 ;
struct V_111 V_112 ;
unsigned V_145 = 0 ;
unsigned V_146 ;
V_112 . V_124 = V_124 ;
V_112 . V_120 = V_120 ;
V_19 = F_14 ( V_10 ) ;
if ( ! V_19 ) {
V_10 -> error = L_35 ;
return - V_118 ;
}
V_65 = F_110 ( & V_112 , V_19 ) ;
if ( V_65 )
goto V_125;
V_65 = F_21 ( V_10 , V_19 ) ;
if ( V_65 )
goto V_125;
V_65 = F_107 ( & V_112 , V_19 ) ;
if ( V_65 )
goto V_125;
V_65 = F_104 ( V_117 , & V_112 , & V_19 -> V_147 , & V_10 -> error ) ;
if ( V_65 )
goto V_125;
V_65 = F_104 ( V_117 + 1 , & V_112 , & V_146 , & V_10 -> error ) ;
if ( V_65 )
goto V_125;
if ( ( ! V_19 -> V_147 && V_146 ) ||
( V_19 -> V_147 && ! V_146 ) ) {
V_10 -> error = L_36 ;
V_65 = - V_118 ;
goto V_125;
}
while ( V_112 . V_124 ) {
struct V_5 * V_6 ;
unsigned V_24 = F_41 ( & V_19 -> V_24 ) ;
V_6 = F_103 ( & V_112 , V_19 ) ;
if ( F_68 ( V_6 ) ) {
V_65 = F_105 ( V_6 ) ;
goto V_125;
}
V_24 += V_6 -> V_135 ;
F_17 ( & V_19 -> V_24 , V_24 ) ;
F_106 ( & V_6 -> V_12 , & V_19 -> V_20 ) ;
V_145 ++ ;
V_6 -> V_148 = V_145 ;
if ( ! -- V_146 )
V_19 -> V_73 = V_6 ;
}
if ( V_145 != V_19 -> V_147 ) {
V_10 -> error = L_37 ;
V_65 = - V_118 ;
goto V_125;
}
V_10 -> V_149 = 1 ;
V_10 -> V_150 = 1 ;
V_10 -> V_151 = 1 ;
if ( V_19 -> V_33 == V_42 )
V_10 -> V_152 = F_34 () ;
else if ( V_19 -> V_33 == V_37 )
V_10 -> V_152 = sizeof( struct V_47 ) ;
return 0 ;
V_125:
F_27 ( V_19 ) ;
return V_65 ;
}
static void F_112 ( struct V_18 * V_19 )
{
F_113 ( V_153 , V_154 ) ;
F_114 ( & V_19 -> V_30 , & V_153 ) ;
while ( 1 ) {
F_115 ( V_155 ) ;
if ( ! F_41 ( & V_19 -> V_25 ) )
break;
F_116 () ;
}
F_115 ( V_156 ) ;
F_117 ( & V_19 -> V_30 , & V_153 ) ;
}
static void F_118 ( struct V_18 * V_19 )
{
F_16 ( V_59 , & V_19 -> V_23 ) ;
F_119 () ;
F_120 ( V_64 ) ;
F_112 ( V_19 ) ;
F_120 ( V_99 ) ;
F_121 ( & V_19 -> V_29 ) ;
F_44 ( V_59 , & V_19 -> V_23 ) ;
F_119 () ;
}
static void F_122 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
F_118 ( V_19 ) ;
F_27 ( V_19 ) ;
}
static int F_123 ( struct V_1 * V_1 )
{
unsigned long V_23 ;
struct V_18 * V_19 = V_1 -> V_6 -> V_19 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( ! V_1 -> V_3 )
goto V_157;
F_124 ( L_38 , V_1 -> V_13 . V_14 -> V_158 ) ;
V_1 -> V_6 -> V_16 . type -> F_123 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
V_1 -> V_3 = false ;
V_1 -> V_159 ++ ;
F_125 ( & V_19 -> V_24 ) ;
if ( V_1 == V_19 -> V_70 )
V_19 -> V_70 = NULL ;
F_126 ( V_160 , V_19 -> V_10 ,
V_1 -> V_13 . V_14 -> V_158 , F_41 ( & V_19 -> V_24 ) ) ;
F_127 ( & V_19 -> V_29 ) ;
V_157:
F_50 ( & V_19 -> V_21 , V_23 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_1 )
{
int V_65 = 0 , V_161 = 0 ;
unsigned long V_23 ;
struct V_18 * V_19 = V_1 -> V_6 -> V_19 ;
unsigned V_24 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( V_1 -> V_3 )
goto V_157;
F_124 ( L_39 , V_1 -> V_13 . V_14 -> V_158 ) ;
V_65 = V_1 -> V_6 -> V_16 . type -> F_128 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
if ( V_65 )
goto V_157;
V_1 -> V_3 = true ;
V_24 = F_129 ( & V_19 -> V_24 ) ;
if ( V_24 == 1 ) {
V_19 -> V_70 = NULL ;
V_161 = 1 ;
} else if ( V_19 -> V_45 && ( V_19 -> V_61 == V_1 -> V_6 ) ) {
if ( F_75 ( V_64 , & V_1 -> V_4 . V_105 ) )
F_43 ( & V_19 -> V_25 ) ;
}
F_126 ( V_162 , V_19 -> V_10 ,
V_1 -> V_13 . V_14 -> V_158 , V_24 ) ;
F_127 ( & V_19 -> V_29 ) ;
V_157:
F_50 ( & V_19 -> V_21 , V_23 ) ;
if ( V_161 ) {
F_88 ( V_19 -> V_10 -> V_36 ) ;
F_77 ( V_19 ) ;
}
return V_65 ;
}
static int F_130 ( struct V_18 * V_19 , struct V_163 * V_14 ,
T_2 V_164 )
{
int V_65 = - V_118 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_46 (pg, &m->priority_groups, list) {
F_46 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_13 . V_14 == V_14 )
V_65 = V_164 ( V_1 ) ;
}
}
return V_65 ;
}
static void F_131 ( struct V_18 * V_19 , struct V_5 * V_6 ,
bool V_71 )
{
unsigned long V_23 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
V_6 -> V_71 = V_71 ;
V_19 -> V_70 = NULL ;
V_19 -> V_61 = NULL ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
F_127 ( & V_19 -> V_29 ) ;
}
static int F_132 ( struct V_18 * V_19 , const char * V_165 )
{
struct V_5 * V_6 ;
unsigned V_166 ;
unsigned long V_23 ;
char V_167 ;
if ( ! V_165 || ( sscanf ( V_165 , L_40 , & V_166 , & V_167 ) != 1 ) || ! V_166 ||
( V_166 > V_19 -> V_147 ) ) {
F_124 ( L_41 ) ;
return - V_118 ;
}
F_49 ( & V_19 -> V_21 , V_23 ) ;
F_46 (pg, &m->priority_groups, list) {
V_6 -> V_71 = false ;
if ( -- V_166 )
continue;
V_19 -> V_70 = NULL ;
V_19 -> V_61 = NULL ;
V_19 -> V_73 = V_6 ;
}
F_50 ( & V_19 -> V_21 , V_23 ) ;
F_127 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_133 ( struct V_18 * V_19 , const char * V_165 , bool V_71 )
{
struct V_5 * V_6 ;
unsigned V_166 ;
char V_167 ;
if ( ! V_165 || ( sscanf ( V_165 , L_40 , & V_166 , & V_167 ) != 1 ) || ! V_166 ||
( V_166 > V_19 -> V_147 ) ) {
F_124 ( L_42 ) ;
return - V_118 ;
}
F_46 (pg, &m->priority_groups, list) {
if ( ! -- V_166 )
break;
}
F_131 ( V_19 , V_6 , V_71 ) ;
return 0 ;
}
static bool F_134 ( struct V_18 * V_19 , struct V_1 * V_1 )
{
unsigned long V_23 ;
bool V_168 = false ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( F_41 ( & V_19 -> V_26 ) <= V_19 -> V_143 &&
! F_42 ( V_59 , & V_19 -> V_23 ) )
F_16 ( V_60 , & V_19 -> V_23 ) ;
else
V_168 = true ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
return V_168 ;
}
static void F_135 ( void * V_169 , int V_170 )
{
struct V_1 * V_1 = V_169 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
unsigned long V_23 ;
bool V_171 = false ;
switch ( V_170 ) {
case V_172 :
break;
case V_173 :
if ( ! V_19 -> V_45 ) {
V_170 = 0 ;
break;
}
F_108 ( L_43
L_44 , V_19 -> V_45 , V_170 ) ;
F_123 ( V_1 ) ;
break;
case V_174 :
F_131 ( V_19 , V_6 , true ) ;
break;
case V_175 :
V_171 = 1 ;
case V_176 :
case V_177 :
if ( F_134 ( V_19 , V_1 ) )
F_123 ( V_1 ) ;
V_170 = 0 ;
break;
case V_178 :
default:
F_123 ( V_1 ) ;
}
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( V_170 ) {
if ( V_1 == V_19 -> V_70 ) {
F_108 ( L_45 , V_170 ) ;
V_19 -> V_70 = NULL ;
V_19 -> V_61 = NULL ;
}
} else if ( ! F_42 ( V_60 , & V_19 -> V_23 ) )
V_6 -> V_71 = false ;
if ( F_136 ( & V_19 -> V_25 ) > 0 )
goto V_157;
if ( F_42 ( V_60 , & V_19 -> V_23 ) ) {
if ( V_171 )
F_16 ( V_62 , & V_19 -> V_23 ) ;
else
F_44 ( V_62 , & V_19 -> V_23 ) ;
if ( F_40 ( V_19 ) )
goto V_157;
}
F_44 ( V_22 , & V_19 -> V_23 ) ;
F_77 ( V_19 ) ;
F_137 ( & V_19 -> V_30 ) ;
V_157:
F_50 ( & V_19 -> V_21 , V_23 ) ;
}
static void V_4 ( struct V_104 * V_105 )
{
struct V_1 * V_1 =
F_78 ( V_105 , struct V_1 , V_4 . V_105 ) ;
if ( V_1 -> V_3 )
F_138 ( F_65 ( V_1 -> V_13 . V_14 -> V_84 ) ,
F_135 , V_1 ) ;
else
F_135 ( V_1 , V_178 ) ;
}
static int F_139 ( int error )
{
switch ( error ) {
case - V_179 :
case - V_180 :
case - V_181 :
case - V_182 :
case - V_183 :
return 1 ;
}
return 0 ;
}
static int F_140 ( struct V_18 * V_19 , struct V_77 * V_78 ,
int error , struct V_47 * V_51 )
{
int V_65 = V_184 ;
if ( ! error && ! V_78 -> V_170 )
return 0 ;
if ( F_139 ( error ) )
return error ;
if ( V_51 -> V_1 )
F_123 ( V_51 -> V_1 ) ;
if ( ! F_41 ( & V_19 -> V_24 ) ) {
if ( ! F_42 ( V_75 , & V_19 -> V_23 ) ) {
if ( ! F_61 ( V_19 ) )
V_65 = - V_85 ;
} else {
if ( error == - V_185 )
V_65 = error ;
}
}
return V_65 ;
}
static int F_141 ( struct V_9 * V_10 , struct V_77 * V_78 ,
int error , union V_48 * V_79 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_47 * V_51 = F_29 ( V_79 ) ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_65 ;
F_142 ( ! V_51 ) ;
V_65 = F_140 ( V_19 , V_78 , error , V_51 ) ;
V_1 = V_51 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_186 )
V_16 -> type -> V_186 ( V_16 , & V_1 -> V_13 , V_51 -> V_66 ) ;
}
F_32 ( V_19 , V_79 ) ;
return V_65 ;
}
static int F_143 ( struct V_18 * V_19 , struct V_54 * V_78 ,
int error , struct V_47 * V_51 )
{
unsigned long V_23 ;
if ( ! error )
return 0 ;
if ( F_139 ( error ) )
return error ;
if ( V_51 -> V_1 )
F_123 ( V_51 -> V_1 ) ;
if ( ! F_41 ( & V_19 -> V_24 ) ) {
if ( ! F_42 ( V_75 , & V_19 -> V_23 ) ) {
if ( ! F_62 ( V_19 ) )
return - V_85 ;
return V_184 ;
} else {
if ( error == - V_185 )
return error ;
}
}
F_144 ( F_37 ( V_78 ) , V_78 ) ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
F_74 ( & V_19 -> V_98 , V_78 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
if ( ! F_42 ( V_22 , & V_19 -> V_23 ) )
F_75 ( V_99 , & V_19 -> V_43 ) ;
return V_187 ;
}
static int F_145 ( struct V_9 * V_10 , struct V_54 * V_78 , int error )
{
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_47 * V_51 = F_35 ( V_78 ) ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_65 ;
F_142 ( ! V_51 ) ;
V_65 = F_143 ( V_19 , V_78 , error , V_51 ) ;
V_1 = V_51 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_186 )
V_16 -> type -> V_186 ( V_16 , & V_1 -> V_13 , V_51 -> V_66 ) ;
}
return V_65 ;
}
static void F_146 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
F_87 ( V_19 , false , true ) ;
}
static void F_147 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
F_148 ( & V_19 -> V_31 ) ;
F_118 ( V_19 ) ;
F_149 ( & V_19 -> V_31 ) ;
}
static void F_150 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
unsigned long V_23 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( F_42 ( V_76 , & V_19 -> V_23 ) )
F_16 ( V_75 , & V_19 -> V_23 ) ;
else
F_44 ( V_75 , & V_19 -> V_23 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
}
static void F_151 ( struct V_9 * V_10 , T_3 type ,
unsigned V_188 , char * V_189 , unsigned V_190 )
{
int V_191 = 0 ;
unsigned long V_23 ;
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_5 * V_6 ;
struct V_1 * V_121 ;
unsigned V_148 ;
char V_192 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( type == V_193 )
F_152 ( L_46 , F_42 ( V_22 , & V_19 -> V_23 ) ,
F_41 ( & V_19 -> V_26 ) ) ;
else {
F_152 ( L_47 , F_42 ( V_75 , & V_19 -> V_23 ) +
( V_19 -> V_143 > 0 ) * 2 +
( V_19 -> V_27 != V_28 ) * 2 +
F_42 ( V_44 , & V_19 -> V_23 ) +
( V_19 -> V_33 != V_38 ) * 2 ) ;
if ( F_42 ( V_75 , & V_19 -> V_23 ) )
F_152 ( L_48 ) ;
if ( V_19 -> V_143 )
F_152 ( L_49 , V_19 -> V_143 ) ;
if ( V_19 -> V_27 != V_28 )
F_152 ( L_50 , V_19 -> V_27 ) ;
if ( F_42 ( V_44 , & V_19 -> V_23 ) )
F_152 ( L_51 ) ;
if ( V_19 -> V_33 != V_38 ) {
switch( V_19 -> V_33 ) {
case V_42 :
F_152 ( L_52 ) ;
break;
case V_37 :
F_152 ( L_53 ) ;
break;
}
}
}
if ( ! V_19 -> V_45 || type == V_193 )
F_152 ( L_54 ) ;
else
F_152 ( L_55 , V_19 -> V_45 ) ;
F_152 ( L_47 , V_19 -> V_147 ) ;
if ( V_19 -> V_73 )
V_148 = V_19 -> V_73 -> V_148 ;
else if ( V_19 -> V_61 )
V_148 = V_19 -> V_61 -> V_148 ;
else
V_148 = ( V_19 -> V_147 ? 1 : 0 ) ;
F_152 ( L_47 , V_148 ) ;
switch ( type ) {
case V_193 :
F_46 (pg, &m->priority_groups, list) {
if ( V_6 -> V_71 )
V_192 = 'D' ;
else if ( V_6 == V_19 -> V_61 )
V_192 = 'A' ;
else
V_192 = 'E' ;
F_152 ( L_56 , V_192 ) ;
if ( V_6 -> V_16 . type -> V_194 )
V_191 += V_6 -> V_16 . type -> V_194 ( & V_6 -> V_16 , NULL , type ,
V_189 + V_191 ,
V_190 - V_191 ) ;
else
F_152 ( L_54 ) ;
F_152 ( L_57 , V_6 -> V_135 ,
V_6 -> V_16 . type -> V_195 ) ;
F_46 (p, &pg->pgpaths, list) {
F_152 ( L_58 , V_121 -> V_13 . V_14 -> V_158 ,
V_121 -> V_3 ? L_59 : L_60 ,
V_121 -> V_159 ) ;
if ( V_6 -> V_16 . type -> V_194 )
V_191 += V_6 -> V_16 . type -> V_194 ( & V_6 -> V_16 ,
& V_121 -> V_13 , type , V_189 + V_191 ,
V_190 - V_191 ) ;
}
}
break;
case V_196 :
F_46 (pg, &m->priority_groups, list) {
F_152 ( L_61 , V_6 -> V_16 . type -> V_158 ) ;
if ( V_6 -> V_16 . type -> V_194 )
V_191 += V_6 -> V_16 . type -> V_194 ( & V_6 -> V_16 , NULL , type ,
V_189 + V_191 ,
V_190 - V_191 ) ;
else
F_152 ( L_54 ) ;
F_152 ( L_57 , V_6 -> V_135 ,
V_6 -> V_16 . type -> V_197 ) ;
F_46 (p, &pg->pgpaths, list) {
F_152 ( L_61 , V_121 -> V_13 . V_14 -> V_158 ) ;
if ( V_6 -> V_16 . type -> V_194 )
V_191 += V_6 -> V_16 . type -> V_194 ( & V_6 -> V_16 ,
& V_121 -> V_13 , type , V_189 + V_191 ,
V_190 - V_191 ) ;
}
}
break;
}
F_50 ( & V_19 -> V_21 , V_23 ) ;
}
static int F_153 ( struct V_9 * V_10 , unsigned V_124 , char * * V_120 )
{
int V_65 = - V_118 ;
struct V_163 * V_14 ;
struct V_18 * V_19 = V_10 -> V_35 ;
T_2 V_164 ;
F_148 ( & V_19 -> V_31 ) ;
if ( F_154 ( V_10 ) ) {
V_65 = - V_127 ;
goto V_157;
}
if ( V_124 == 1 ) {
if ( ! strcasecmp ( V_120 [ 0 ] , L_23 ) ) {
V_65 = F_87 ( V_19 , true , false ) ;
goto V_157;
} else if ( ! strcasecmp ( V_120 [ 0 ] , L_62 ) ) {
V_65 = F_87 ( V_19 , false , false ) ;
goto V_157;
}
}
if ( V_124 != 2 ) {
F_124 ( L_63 , V_124 ) ;
goto V_157;
}
if ( ! strcasecmp ( V_120 [ 0 ] , L_64 ) ) {
V_65 = F_133 ( V_19 , V_120 [ 1 ] , true ) ;
goto V_157;
} else if ( ! strcasecmp ( V_120 [ 0 ] , L_65 ) ) {
V_65 = F_133 ( V_19 , V_120 [ 1 ] , false ) ;
goto V_157;
} else if ( ! strcasecmp ( V_120 [ 0 ] , L_66 ) ) {
V_65 = F_132 ( V_19 , V_120 [ 1 ] ) ;
goto V_157;
} else if ( ! strcasecmp ( V_120 [ 0 ] , L_67 ) )
V_164 = F_128 ;
else if ( ! strcasecmp ( V_120 [ 0 ] , L_68 ) )
V_164 = F_123 ;
else {
F_124 ( L_69 , V_120 [ 0 ] ) ;
goto V_157;
}
V_65 = F_96 ( V_10 , V_120 [ 1 ] , F_97 ( V_10 -> V_36 ) , & V_14 ) ;
if ( V_65 ) {
F_124 ( L_70 ,
V_120 [ 1 ] ) ;
goto V_157;
}
V_65 = F_130 ( V_19 , V_14 , V_164 ) ;
F_11 ( V_10 , V_14 ) ;
V_157:
F_149 ( & V_19 -> V_31 ) ;
return V_65 ;
}
static int F_155 ( struct V_9 * V_10 ,
struct V_83 * * V_84 , T_4 * V_198 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_1 * V_70 ;
int V_65 ;
V_70 = F_56 ( V_19 -> V_70 ) ;
if ( ! V_70 )
V_70 = F_57 ( V_19 , 0 ) ;
if ( V_70 ) {
if ( ! F_42 ( V_22 , & V_19 -> V_23 ) ) {
* V_84 = V_70 -> V_13 . V_14 -> V_84 ;
* V_198 = V_70 -> V_13 . V_14 -> V_198 ;
V_65 = 0 ;
} else {
V_65 = - V_199 ;
}
} else {
if ( F_42 ( V_75 , & V_19 -> V_23 ) )
V_65 = - V_199 ;
else
V_65 = - V_85 ;
}
if ( V_65 == - V_199 ) {
if ( ! F_56 ( V_19 -> V_61 ) ) {
( void ) F_57 ( V_19 , 0 ) ;
}
if ( F_42 ( V_60 , & V_19 -> V_23 ) )
F_48 ( V_19 ) ;
F_88 ( V_19 -> V_10 -> V_36 ) ;
F_77 ( V_19 ) ;
}
if ( ! V_65 && V_10 -> V_140 != F_156 ( ( * V_84 ) -> V_200 ) >> V_201 )
return 1 ;
return V_65 ;
}
static int F_157 ( struct V_9 * V_10 ,
T_5 V_202 , void * V_169 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_5 * V_6 ;
struct V_1 * V_121 ;
int V_138 = 0 ;
F_46 (pg, &m->priority_groups, list) {
F_46 (p, &pg->pgpaths, list) {
V_138 = V_202 ( V_10 , V_121 -> V_13 . V_14 , V_10 -> V_203 , V_10 -> V_140 , V_169 ) ;
if ( V_138 )
goto V_157;
}
}
V_157:
return V_138 ;
}
static int F_158 ( struct V_1 * V_1 )
{
struct V_122 * V_86 = F_65 ( V_1 -> V_13 . V_14 -> V_84 ) ;
return F_159 ( V_86 ) ;
}
static int F_160 ( struct V_9 * V_10 )
{
bool V_204 = false , V_205 = false ;
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_5 * V_6 , * V_73 ;
struct V_1 * V_1 ;
if ( F_41 ( & V_19 -> V_25 ) ||
( ! F_41 ( & V_19 -> V_24 ) && F_42 ( V_75 , & V_19 -> V_23 ) ) )
return true ;
V_6 = F_56 ( V_19 -> V_61 ) ;
V_73 = F_56 ( V_19 -> V_73 ) ;
if ( F_55 ( ! F_56 ( V_19 -> V_70 ) && V_73 ) )
V_6 = V_73 ;
if ( ! V_6 ) {
return V_204 ;
}
V_204 = true ;
F_46 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_3 ) {
V_205 = true ;
if ( ! F_158 ( V_1 ) ) {
V_204 = false ;
break;
}
}
}
if ( ! V_205 ) {
V_204 = false ;
}
return V_204 ;
}
static int T_6 F_161 ( void )
{
int V_65 ;
V_40 = F_162 ( V_47 , 0 ) ;
if ( ! V_40 )
return - V_41 ;
V_65 = F_163 ( & V_206 ) ;
if ( V_65 < 0 ) {
F_108 ( L_71 , V_65 ) ;
V_65 = - V_118 ;
goto V_207;
}
V_99 = F_164 ( L_72 , V_208 , 0 ) ;
if ( ! V_99 ) {
F_108 ( L_73 ) ;
V_65 = - V_41 ;
goto V_209;
}
V_64 = F_165 ( L_74 ,
V_208 ) ;
if ( ! V_64 ) {
F_108 ( L_75 ) ;
V_65 = - V_41 ;
goto V_210;
}
return 0 ;
V_210:
F_166 ( V_99 ) ;
V_209:
F_167 ( & V_206 ) ;
V_207:
F_168 ( V_40 ) ;
return V_65 ;
}
static void T_7 F_169 ( void )
{
F_166 ( V_64 ) ;
F_166 ( V_99 ) ;
F_167 ( & V_206 ) ;
F_168 ( V_40 ) ;
}
