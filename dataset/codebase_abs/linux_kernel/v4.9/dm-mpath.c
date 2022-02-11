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
if ( F_61 ( V_19 ) )
return V_85 ;
return - V_86 ;
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
V_78 -> V_87 = F_65 ( V_84 ) ;
V_78 -> V_88 = V_84 -> V_89 ;
V_78 -> V_90 |= V_91 ;
} else {
* V_81 = F_66 ( F_65 ( V_84 ) ,
F_67 ( V_80 ) , V_92 ) ;
if ( F_68 ( * V_81 ) ) {
F_32 ( V_19 , V_79 ) ;
return V_65 ;
}
( * V_81 ) -> V_54 = ( * V_81 ) -> V_93 = NULL ;
( * V_81 ) -> V_88 = V_84 -> V_89 ;
( * V_81 ) -> V_90 |= V_91 ;
}
if ( V_1 -> V_6 -> V_16 . type -> V_94 )
V_1 -> V_6 -> V_16 . type -> V_94 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_66 ) ;
return V_95 ;
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
T_1 V_66 = V_54 -> V_96 . V_97 ;
struct V_1 * V_1 ;
unsigned long V_23 ;
bool V_98 ;
V_1 = F_56 ( V_19 -> V_70 ) ;
V_98 = F_42 ( V_22 , & V_19 -> V_23 ) ;
if ( ! V_1 || ! V_98 )
V_1 = F_57 ( V_19 , V_66 ) ;
if ( ( V_1 && V_98 ) ||
( ! V_1 && F_42 ( V_75 , & V_19 -> V_23 ) ) ) {
F_49 ( & V_19 -> V_21 , V_23 ) ;
F_74 ( & V_19 -> V_99 , V_54 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
if ( V_98 || F_42 ( V_60 , & V_19 -> V_23 ) )
F_48 ( V_19 ) ;
else if ( ! V_98 )
F_75 ( V_100 , & V_19 -> V_43 ) ;
return V_101 ;
}
if ( ! V_1 ) {
if ( ! F_62 ( V_19 ) )
return - V_86 ;
return V_82 ;
}
V_51 -> V_1 = V_1 ;
V_51 -> V_66 = V_66 ;
V_54 -> V_102 = 0 ;
V_54 -> V_103 = V_1 -> V_13 . V_14 -> V_84 ;
V_54 -> V_104 |= V_91 ;
if ( V_1 -> V_6 -> V_16 . type -> V_94 )
V_1 -> V_6 -> V_16 . type -> V_94 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_66 ) ;
return V_95 ;
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
if ( V_19 -> V_33 == V_37 )
F_78 ( F_23 ( V_19 -> V_10 -> V_36 ) ) ;
else if ( V_19 -> V_33 == V_42 )
F_75 ( V_100 , & V_19 -> V_43 ) ;
}
static void V_43 ( struct V_105 * V_106 )
{
int V_65 ;
unsigned long V_23 ;
struct V_54 * V_54 ;
struct V_107 V_108 ;
struct V_109 V_110 ;
struct V_18 * V_19 =
F_79 ( V_106 , struct V_18 , V_43 ) ;
F_80 ( & V_108 ) ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( F_81 ( & V_19 -> V_99 ) ) {
F_50 ( & V_19 -> V_21 , V_23 ) ;
return;
}
F_82 ( & V_108 , & V_19 -> V_99 ) ;
F_80 ( & V_19 -> V_99 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
F_83 ( & V_110 ) ;
while ( ( V_54 = F_84 ( & V_108 ) ) ) {
V_65 = F_73 ( V_19 , V_54 , F_35 ( V_54 ) ) ;
if ( V_65 < 0 || V_65 == V_82 ) {
V_54 -> V_102 = V_65 ;
F_85 ( V_54 ) ;
} else if ( V_65 == V_95 )
F_86 ( V_54 ) ;
}
F_87 ( & V_110 ) ;
}
static int F_88 ( struct V_18 * V_19 , bool F_88 ,
bool V_111 )
{
unsigned long V_23 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( V_111 ) {
if ( F_42 ( V_75 , & V_19 -> V_23 ) )
F_16 ( V_76 , & V_19 -> V_23 ) ;
else
F_44 ( V_76 , & V_19 -> V_23 ) ;
} else {
if ( F_88 )
F_16 ( V_76 , & V_19 -> V_23 ) ;
else
F_44 ( V_76 , & V_19 -> V_23 ) ;
}
if ( F_88 )
F_16 ( V_75 , & V_19 -> V_23 ) ;
else
F_44 ( V_75 , & V_19 -> V_23 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
if ( ! F_88 ) {
F_89 ( V_19 -> V_10 -> V_36 ) ;
F_77 ( V_19 ) ;
}
return 0 ;
}
static void V_29 ( struct V_105 * V_106 )
{
struct V_18 * V_19 =
F_79 ( V_106 , struct V_18 , V_29 ) ;
F_90 ( V_19 -> V_10 -> V_36 ) ;
}
static int F_91 ( struct V_112 * V_113 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_65 ;
struct V_114 * V_115 ;
unsigned V_116 ;
static struct V_117 V_118 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_115 = F_92 ( F_93 ( V_113 ) ) ;
if ( ! V_115 ) {
V_10 -> error = L_2 ;
return - V_119 ;
}
V_65 = F_94 ( V_118 , V_113 , & V_116 , & V_10 -> error ) ;
if ( V_65 ) {
F_13 ( V_115 ) ;
return - V_119 ;
}
V_65 = V_115 -> V_120 ( & V_6 -> V_16 , V_116 , V_113 -> V_121 ) ;
if ( V_65 ) {
F_13 ( V_115 ) ;
V_10 -> error = L_3 ;
return V_65 ;
}
V_6 -> V_16 . type = V_115 ;
F_95 ( V_113 , V_116 ) ;
return 0 ;
}
static struct V_1 * F_96 ( struct V_112 * V_113 , struct V_15 * V_16 ,
struct V_9 * V_10 )
{
int V_65 ;
struct V_1 * V_122 ;
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_123 * V_87 = NULL ;
const char * V_124 ;
if ( V_113 -> V_125 < 1 ) {
V_10 -> error = L_4 ;
return F_53 ( - V_119 ) ;
}
V_122 = F_1 () ;
if ( ! V_122 )
return F_53 ( - V_41 ) ;
V_65 = F_97 ( V_10 , F_93 ( V_113 ) , F_98 ( V_10 -> V_36 ) ,
& V_122 -> V_13 . V_14 ) ;
if ( V_65 ) {
V_10 -> error = L_5 ;
goto V_126;
}
if ( F_42 ( V_44 , & V_19 -> V_23 ) || V_19 -> V_45 )
V_87 = F_65 ( V_122 -> V_13 . V_14 -> V_84 ) ;
if ( F_42 ( V_44 , & V_19 -> V_23 ) ) {
V_127:
V_124 = F_99 ( V_87 , V_2 ) ;
if ( V_124 ) {
F_5 ( V_19 -> V_45 ) ;
V_19 -> V_45 = V_124 ;
F_5 ( V_19 -> V_46 ) ;
V_19 -> V_46 = NULL ;
}
}
if ( V_19 -> V_45 ) {
V_65 = F_100 ( V_87 , V_19 -> V_45 ) ;
if ( V_65 == - V_128 ) {
char V_129 [ V_130 ] ;
F_101 ( V_131 L_6 ,
F_102 ( V_122 -> V_13 . V_14 -> V_84 , V_129 ) ) ;
goto V_127;
}
if ( V_65 < 0 ) {
V_10 -> error = L_7 ;
F_11 ( V_10 , V_122 -> V_13 . V_14 ) ;
goto V_126;
}
if ( V_19 -> V_46 ) {
V_65 = F_103 ( V_87 , V_19 -> V_46 ) ;
if ( V_65 < 0 ) {
V_10 -> error = L_8
L_9 ;
F_11 ( V_10 , V_122 -> V_13 . V_14 ) ;
goto V_126;
}
}
}
V_65 = V_16 -> type -> V_132 ( V_16 , & V_122 -> V_13 , V_113 -> V_125 , V_113 -> V_121 , & V_10 -> error ) ;
if ( V_65 ) {
F_11 ( V_10 , V_122 -> V_13 . V_14 ) ;
goto V_126;
}
return V_122 ;
V_126:
F_4 ( V_122 ) ;
return F_53 ( V_65 ) ;
}
static struct V_5 * F_104 ( struct V_112 * V_113 ,
struct V_18 * V_19 )
{
static struct V_117 V_118 [] = {
{ 1 , 1024 , L_10 } ,
{ 0 , 1024 , L_11 }
} ;
int V_65 ;
unsigned V_133 , V_134 , V_135 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_19 -> V_10 ;
if ( V_113 -> V_125 < 2 ) {
V_113 -> V_125 = 0 ;
V_10 -> error = L_12 ;
return F_53 ( - V_119 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_13 ;
return F_53 ( - V_41 ) ;
}
V_6 -> V_19 = V_19 ;
V_65 = F_91 ( V_113 , V_6 , V_10 ) ;
if ( V_65 )
goto V_126;
V_65 = F_105 ( V_118 , V_113 , & V_6 -> V_136 , & V_10 -> error ) ;
if ( V_65 )
goto V_126;
V_65 = F_105 ( V_118 + 1 , V_113 , & V_134 , & V_10 -> error ) ;
if ( V_65 )
goto V_126;
V_135 = 1 + V_134 ;
for ( V_133 = 0 ; V_133 < V_6 -> V_136 ; V_133 ++ ) {
struct V_1 * V_1 ;
struct V_112 V_137 ;
if ( V_113 -> V_125 < V_135 ) {
V_10 -> error = L_14 ;
V_65 = - V_119 ;
goto V_126;
}
V_137 . V_125 = V_135 ;
V_137 . V_121 = V_113 -> V_121 ;
V_1 = F_96 ( & V_137 , & V_6 -> V_16 , V_10 ) ;
if ( F_68 ( V_1 ) ) {
V_65 = F_106 ( V_1 ) ;
goto V_126;
}
V_1 -> V_6 = V_6 ;
F_107 ( & V_1 -> V_12 , & V_6 -> V_7 ) ;
F_95 ( V_113 , V_135 ) ;
}
return V_6 ;
V_126:
F_12 ( V_6 , V_10 ) ;
return F_53 ( V_65 ) ;
}
static int F_108 ( struct V_112 * V_113 , struct V_18 * V_19 )
{
unsigned V_138 ;
int V_139 ;
struct V_9 * V_10 = V_19 -> V_10 ;
static struct V_117 V_118 [] = {
{ 0 , 1024 , L_15 } ,
} ;
if ( F_94 ( V_118 , V_113 , & V_138 , & V_10 -> error ) )
return - V_119 ;
if ( ! V_138 )
return 0 ;
if ( V_19 -> V_33 == V_42 ) {
F_95 ( V_113 , V_138 ) ;
F_109 ( L_16 ) ;
return 0 ;
}
V_19 -> V_45 = F_110 ( F_93 ( V_113 ) , V_2 ) ;
if ( V_138 > 1 ) {
char * V_122 ;
int V_133 , V_140 , V_141 = 4 ;
for ( V_133 = 0 ; V_133 <= V_138 - 2 ; V_133 ++ )
V_141 += strlen ( V_113 -> V_121 [ V_133 ] ) + 1 ;
V_122 = V_19 -> V_46 = F_2 ( V_141 , V_2 ) ;
if ( ! V_122 ) {
V_10 -> error = L_17 ;
V_139 = - V_41 ;
goto V_142;
}
V_140 = sprintf ( V_122 , L_18 , V_138 - 1 ) ;
for ( V_133 = 0 , V_122 += V_140 + 1 ; V_133 <= V_138 - 2 ; V_133 ++ , V_122 += V_140 + 1 )
V_140 = sprintf ( V_122 , L_19 , V_113 -> V_121 [ V_133 ] ) ;
}
F_95 ( V_113 , V_138 - 1 ) ;
return 0 ;
V_142:
F_5 ( V_19 -> V_45 ) ;
V_19 -> V_45 = NULL ;
return V_139 ;
}
static int F_111 ( struct V_112 * V_113 , struct V_18 * V_19 )
{
int V_65 ;
unsigned V_125 ;
struct V_9 * V_10 = V_19 -> V_10 ;
const char * V_143 ;
static struct V_117 V_118 [] = {
{ 0 , 8 , L_20 } ,
{ 1 , 50 , L_21 } ,
{ 0 , 60000 , L_22 } ,
} ;
V_65 = F_94 ( V_118 , V_113 , & V_125 , & V_10 -> error ) ;
if ( V_65 )
return - V_119 ;
if ( ! V_125 )
return 0 ;
do {
V_143 = F_93 ( V_113 ) ;
V_125 -- ;
if ( ! strcasecmp ( V_143 , L_23 ) ) {
V_65 = F_88 ( V_19 , true , false ) ;
continue;
}
if ( ! strcasecmp ( V_143 , L_24 ) ) {
F_16 ( V_44 , & V_19 -> V_23 ) ;
continue;
}
if ( ! strcasecmp ( V_143 , L_25 ) &&
( V_125 >= 1 ) ) {
V_65 = F_105 ( V_118 + 1 , V_113 , & V_19 -> V_144 , & V_10 -> error ) ;
V_125 -- ;
continue;
}
if ( ! strcasecmp ( V_143 , L_26 ) &&
( V_125 >= 1 ) ) {
V_65 = F_105 ( V_118 + 2 , V_113 , & V_19 -> V_27 , & V_10 -> error ) ;
V_125 -- ;
continue;
}
if ( ! strcasecmp ( V_143 , L_27 ) &&
( V_125 >= 1 ) ) {
const char * V_145 = F_93 ( V_113 ) ;
if ( ! strcasecmp ( V_145 , L_28 ) )
V_19 -> V_33 = V_42 ;
else if ( ! strcasecmp ( V_145 , L_29 ) )
V_19 -> V_33 = V_38 ;
else if ( ! strcasecmp ( V_145 , L_30 ) )
V_19 -> V_33 = V_37 ;
else {
V_10 -> error = L_31 ;
V_65 = - V_119 ;
}
V_125 -- ;
continue;
}
V_10 -> error = L_32 ;
V_65 = - V_119 ;
} while ( V_125 && ! V_65 );
return V_65 ;
}
static int F_112 ( struct V_9 * V_10 , unsigned V_125 , char * * V_121 )
{
static struct V_117 V_118 [] = {
{ 0 , 1024 , L_33 } ,
{ 0 , 1024 , L_34 } ,
} ;
int V_65 ;
struct V_18 * V_19 ;
struct V_112 V_113 ;
unsigned V_146 = 0 ;
unsigned V_147 ;
V_113 . V_125 = V_125 ;
V_113 . V_121 = V_121 ;
V_19 = F_14 ( V_10 ) ;
if ( ! V_19 ) {
V_10 -> error = L_35 ;
return - V_119 ;
}
V_65 = F_111 ( & V_113 , V_19 ) ;
if ( V_65 )
goto V_126;
V_65 = F_21 ( V_10 , V_19 ) ;
if ( V_65 )
goto V_126;
V_65 = F_108 ( & V_113 , V_19 ) ;
if ( V_65 )
goto V_126;
V_65 = F_105 ( V_118 , & V_113 , & V_19 -> V_148 , & V_10 -> error ) ;
if ( V_65 )
goto V_126;
V_65 = F_105 ( V_118 + 1 , & V_113 , & V_147 , & V_10 -> error ) ;
if ( V_65 )
goto V_126;
if ( ( ! V_19 -> V_148 && V_147 ) ||
( V_19 -> V_148 && ! V_147 ) ) {
V_10 -> error = L_36 ;
V_65 = - V_119 ;
goto V_126;
}
while ( V_113 . V_125 ) {
struct V_5 * V_6 ;
unsigned V_24 = F_41 ( & V_19 -> V_24 ) ;
V_6 = F_104 ( & V_113 , V_19 ) ;
if ( F_68 ( V_6 ) ) {
V_65 = F_106 ( V_6 ) ;
goto V_126;
}
V_24 += V_6 -> V_136 ;
F_17 ( & V_19 -> V_24 , V_24 ) ;
F_107 ( & V_6 -> V_12 , & V_19 -> V_20 ) ;
V_146 ++ ;
V_6 -> V_149 = V_146 ;
if ( ! -- V_147 )
V_19 -> V_73 = V_6 ;
}
if ( V_146 != V_19 -> V_148 ) {
V_10 -> error = L_37 ;
V_65 = - V_119 ;
goto V_126;
}
V_10 -> V_150 = 1 ;
V_10 -> V_151 = 1 ;
V_10 -> V_152 = 1 ;
if ( V_19 -> V_33 == V_42 )
V_10 -> V_153 = F_34 () ;
else if ( V_19 -> V_33 == V_37 )
V_10 -> V_153 = sizeof( struct V_47 ) ;
return 0 ;
V_126:
F_27 ( V_19 ) ;
return V_65 ;
}
static void F_113 ( struct V_18 * V_19 )
{
F_114 ( V_154 ) ;
while ( 1 ) {
F_115 ( & V_19 -> V_30 , & V_154 , V_155 ) ;
if ( ! F_41 ( & V_19 -> V_25 ) )
break;
F_116 () ;
}
F_117 ( & V_19 -> V_30 , & V_154 ) ;
}
static void F_118 ( struct V_18 * V_19 )
{
F_16 ( V_59 , & V_19 -> V_23 ) ;
F_119 () ;
F_120 ( V_64 ) ;
F_113 ( V_19 ) ;
F_120 ( V_100 ) ;
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
goto V_156;
F_124 ( L_38 , V_1 -> V_13 . V_14 -> V_157 ) ;
V_1 -> V_6 -> V_16 . type -> F_123 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
V_1 -> V_3 = false ;
V_1 -> V_158 ++ ;
F_125 ( & V_19 -> V_24 ) ;
if ( V_1 == V_19 -> V_70 )
V_19 -> V_70 = NULL ;
F_126 ( V_159 , V_19 -> V_10 ,
V_1 -> V_13 . V_14 -> V_157 , F_41 ( & V_19 -> V_24 ) ) ;
F_127 ( & V_19 -> V_29 ) ;
V_156:
F_50 ( & V_19 -> V_21 , V_23 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_1 )
{
int V_65 = 0 , V_160 = 0 ;
unsigned long V_23 ;
struct V_18 * V_19 = V_1 -> V_6 -> V_19 ;
unsigned V_24 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( V_1 -> V_3 )
goto V_156;
F_124 ( L_39 , V_1 -> V_13 . V_14 -> V_157 ) ;
V_65 = V_1 -> V_6 -> V_16 . type -> F_128 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
if ( V_65 )
goto V_156;
V_1 -> V_3 = true ;
V_24 = F_129 ( & V_19 -> V_24 ) ;
if ( V_24 == 1 ) {
V_19 -> V_70 = NULL ;
V_160 = 1 ;
} else if ( V_19 -> V_45 && ( V_19 -> V_61 == V_1 -> V_6 ) ) {
if ( F_75 ( V_64 , & V_1 -> V_4 . V_106 ) )
F_43 ( & V_19 -> V_25 ) ;
}
F_126 ( V_161 , V_19 -> V_10 ,
V_1 -> V_13 . V_14 -> V_157 , V_24 ) ;
F_127 ( & V_19 -> V_29 ) ;
V_156:
F_50 ( & V_19 -> V_21 , V_23 ) ;
if ( V_160 ) {
F_89 ( V_19 -> V_10 -> V_36 ) ;
F_77 ( V_19 ) ;
}
return V_65 ;
}
static int F_130 ( struct V_18 * V_19 , struct V_162 * V_14 ,
T_2 V_163 )
{
int V_65 = - V_119 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_46 (pg, &m->priority_groups, list) {
F_46 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_13 . V_14 == V_14 )
V_65 = V_163 ( V_1 ) ;
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
static int F_132 ( struct V_18 * V_19 , const char * V_164 )
{
struct V_5 * V_6 ;
unsigned V_165 ;
unsigned long V_23 ;
char V_166 ;
if ( ! V_164 || ( sscanf ( V_164 , L_40 , & V_165 , & V_166 ) != 1 ) || ! V_165 ||
( V_165 > V_19 -> V_148 ) ) {
F_124 ( L_41 ) ;
return - V_119 ;
}
F_49 ( & V_19 -> V_21 , V_23 ) ;
F_46 (pg, &m->priority_groups, list) {
V_6 -> V_71 = false ;
if ( -- V_165 )
continue;
V_19 -> V_70 = NULL ;
V_19 -> V_61 = NULL ;
V_19 -> V_73 = V_6 ;
}
F_50 ( & V_19 -> V_21 , V_23 ) ;
F_127 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_133 ( struct V_18 * V_19 , const char * V_164 , bool V_71 )
{
struct V_5 * V_6 ;
unsigned V_165 ;
char V_166 ;
if ( ! V_164 || ( sscanf ( V_164 , L_40 , & V_165 , & V_166 ) != 1 ) || ! V_165 ||
( V_165 > V_19 -> V_148 ) ) {
F_124 ( L_42 ) ;
return - V_119 ;
}
F_46 (pg, &m->priority_groups, list) {
if ( ! -- V_165 )
break;
}
F_131 ( V_19 , V_6 , V_71 ) ;
return 0 ;
}
static bool F_134 ( struct V_18 * V_19 , struct V_1 * V_1 )
{
unsigned long V_23 ;
bool V_167 = false ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( F_41 ( & V_19 -> V_26 ) <= V_19 -> V_144 &&
! F_42 ( V_59 , & V_19 -> V_23 ) )
F_16 ( V_60 , & V_19 -> V_23 ) ;
else
V_167 = true ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
return V_167 ;
}
static void F_135 ( void * V_168 , int V_169 )
{
struct V_1 * V_1 = V_168 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
unsigned long V_23 ;
bool V_170 = false ;
switch ( V_169 ) {
case V_171 :
break;
case V_172 :
if ( ! V_19 -> V_45 ) {
V_169 = 0 ;
break;
}
F_109 ( L_43
L_44 , V_19 -> V_45 , V_169 ) ;
F_123 ( V_1 ) ;
break;
case V_173 :
F_131 ( V_19 , V_6 , true ) ;
break;
case V_174 :
V_170 = 1 ;
case V_175 :
case V_176 :
if ( F_134 ( V_19 , V_1 ) )
F_123 ( V_1 ) ;
V_169 = 0 ;
break;
case V_177 :
default:
F_123 ( V_1 ) ;
}
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( V_169 ) {
if ( V_1 == V_19 -> V_70 ) {
F_109 ( L_45 , V_169 ) ;
V_19 -> V_70 = NULL ;
V_19 -> V_61 = NULL ;
}
} else if ( ! F_42 ( V_60 , & V_19 -> V_23 ) )
V_6 -> V_71 = false ;
if ( F_136 ( & V_19 -> V_25 ) > 0 )
goto V_156;
if ( F_42 ( V_60 , & V_19 -> V_23 ) ) {
if ( V_170 )
F_16 ( V_62 , & V_19 -> V_23 ) ;
else
F_44 ( V_62 , & V_19 -> V_23 ) ;
if ( F_40 ( V_19 ) )
goto V_156;
}
F_44 ( V_22 , & V_19 -> V_23 ) ;
F_77 ( V_19 ) ;
F_137 ( & V_19 -> V_30 ) ;
V_156:
F_50 ( & V_19 -> V_21 , V_23 ) ;
}
static void V_4 ( struct V_105 * V_106 )
{
struct V_1 * V_1 =
F_79 ( V_106 , struct V_1 , V_4 . V_106 ) ;
struct V_123 * V_87 = F_65 ( V_1 -> V_13 . V_14 -> V_84 ) ;
if ( V_1 -> V_3 && ! F_138 ( V_87 ) )
F_139 ( V_87 , F_135 , V_1 ) ;
else
F_135 ( V_1 , V_177 ) ;
}
static int F_140 ( int error )
{
switch ( error ) {
case - V_178 :
case - V_179 :
case - V_180 :
case - V_181 :
case - V_182 :
case - V_183 :
return 1 ;
}
return 0 ;
}
static int F_141 ( struct V_18 * V_19 , struct V_77 * V_78 ,
int error , struct V_47 * V_51 )
{
int V_65 = V_184 ;
if ( ! error && ! V_78 -> V_169 )
return 0 ;
if ( F_140 ( error ) )
return error ;
if ( V_51 -> V_1 )
F_123 ( V_51 -> V_1 ) ;
if ( ! F_41 ( & V_19 -> V_24 ) ) {
if ( ! F_42 ( V_75 , & V_19 -> V_23 ) ) {
if ( ! F_61 ( V_19 ) )
V_65 = - V_86 ;
}
}
return V_65 ;
}
static int F_142 ( struct V_9 * V_10 , struct V_77 * V_78 ,
int error , union V_48 * V_79 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_47 * V_51 = F_29 ( V_79 ) ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_65 ;
F_143 ( ! V_51 ) ;
V_65 = F_141 ( V_19 , V_78 , error , V_51 ) ;
V_1 = V_51 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_185 )
V_16 -> type -> V_185 ( V_16 , & V_1 -> V_13 , V_51 -> V_66 ) ;
}
F_32 ( V_19 , V_79 ) ;
return V_65 ;
}
static int F_144 ( struct V_18 * V_19 , struct V_54 * V_78 ,
int error , struct V_47 * V_51 )
{
unsigned long V_23 ;
if ( ! error )
return 0 ;
if ( F_140 ( error ) )
return error ;
if ( V_51 -> V_1 )
F_123 ( V_51 -> V_1 ) ;
if ( ! F_41 ( & V_19 -> V_24 ) ) {
if ( ! F_42 ( V_75 , & V_19 -> V_23 ) ) {
if ( ! F_62 ( V_19 ) )
return - V_86 ;
return V_184 ;
}
}
F_145 ( F_37 ( V_78 ) , V_78 ) ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
F_74 ( & V_19 -> V_99 , V_78 ) ;
F_50 ( & V_19 -> V_21 , V_23 ) ;
if ( ! F_42 ( V_22 , & V_19 -> V_23 ) )
F_75 ( V_100 , & V_19 -> V_43 ) ;
return V_186 ;
}
static int F_146 ( struct V_9 * V_10 , struct V_54 * V_78 , int error )
{
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_47 * V_51 = F_35 ( V_78 ) ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_65 ;
F_143 ( ! V_51 ) ;
V_65 = F_144 ( V_19 , V_78 , error , V_51 ) ;
V_1 = V_51 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_185 )
V_16 -> type -> V_185 ( V_16 , & V_1 -> V_13 , V_51 -> V_66 ) ;
}
return V_65 ;
}
static void F_147 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
F_88 ( V_19 , false , true ) ;
}
static void F_148 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
F_149 ( & V_19 -> V_31 ) ;
F_118 ( V_19 ) ;
F_150 ( & V_19 -> V_31 ) ;
}
static void F_151 ( struct V_9 * V_10 )
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
static void F_152 ( struct V_9 * V_10 , T_3 type ,
unsigned V_187 , char * V_188 , unsigned V_189 )
{
int V_190 = 0 ;
unsigned long V_23 ;
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_5 * V_6 ;
struct V_1 * V_122 ;
unsigned V_149 ;
char V_191 ;
F_49 ( & V_19 -> V_21 , V_23 ) ;
if ( type == V_192 )
F_153 ( L_46 , F_42 ( V_22 , & V_19 -> V_23 ) ,
F_41 ( & V_19 -> V_26 ) ) ;
else {
F_153 ( L_47 , F_42 ( V_75 , & V_19 -> V_23 ) +
( V_19 -> V_144 > 0 ) * 2 +
( V_19 -> V_27 != V_28 ) * 2 +
F_42 ( V_44 , & V_19 -> V_23 ) +
( V_19 -> V_33 != V_38 ) * 2 ) ;
if ( F_42 ( V_75 , & V_19 -> V_23 ) )
F_153 ( L_48 ) ;
if ( V_19 -> V_144 )
F_153 ( L_49 , V_19 -> V_144 ) ;
if ( V_19 -> V_27 != V_28 )
F_153 ( L_50 , V_19 -> V_27 ) ;
if ( F_42 ( V_44 , & V_19 -> V_23 ) )
F_153 ( L_51 ) ;
if ( V_19 -> V_33 != V_38 ) {
switch( V_19 -> V_33 ) {
case V_42 :
F_153 ( L_52 ) ;
break;
case V_37 :
F_153 ( L_53 ) ;
break;
}
}
}
if ( ! V_19 -> V_45 || type == V_192 )
F_153 ( L_54 ) ;
else
F_153 ( L_55 , V_19 -> V_45 ) ;
F_153 ( L_47 , V_19 -> V_148 ) ;
if ( V_19 -> V_73 )
V_149 = V_19 -> V_73 -> V_149 ;
else if ( V_19 -> V_61 )
V_149 = V_19 -> V_61 -> V_149 ;
else
V_149 = ( V_19 -> V_148 ? 1 : 0 ) ;
F_153 ( L_47 , V_149 ) ;
switch ( type ) {
case V_192 :
F_46 (pg, &m->priority_groups, list) {
if ( V_6 -> V_71 )
V_191 = 'D' ;
else if ( V_6 == V_19 -> V_61 )
V_191 = 'A' ;
else
V_191 = 'E' ;
F_153 ( L_56 , V_191 ) ;
if ( V_6 -> V_16 . type -> V_193 )
V_190 += V_6 -> V_16 . type -> V_193 ( & V_6 -> V_16 , NULL , type ,
V_188 + V_190 ,
V_189 - V_190 ) ;
else
F_153 ( L_54 ) ;
F_153 ( L_57 , V_6 -> V_136 ,
V_6 -> V_16 . type -> V_194 ) ;
F_46 (p, &pg->pgpaths, list) {
F_153 ( L_58 , V_122 -> V_13 . V_14 -> V_157 ,
V_122 -> V_3 ? L_59 : L_60 ,
V_122 -> V_158 ) ;
if ( V_6 -> V_16 . type -> V_193 )
V_190 += V_6 -> V_16 . type -> V_193 ( & V_6 -> V_16 ,
& V_122 -> V_13 , type , V_188 + V_190 ,
V_189 - V_190 ) ;
}
}
break;
case V_195 :
F_46 (pg, &m->priority_groups, list) {
F_153 ( L_61 , V_6 -> V_16 . type -> V_157 ) ;
if ( V_6 -> V_16 . type -> V_193 )
V_190 += V_6 -> V_16 . type -> V_193 ( & V_6 -> V_16 , NULL , type ,
V_188 + V_190 ,
V_189 - V_190 ) ;
else
F_153 ( L_54 ) ;
F_153 ( L_57 , V_6 -> V_136 ,
V_6 -> V_16 . type -> V_196 ) ;
F_46 (p, &pg->pgpaths, list) {
F_153 ( L_61 , V_122 -> V_13 . V_14 -> V_157 ) ;
if ( V_6 -> V_16 . type -> V_193 )
V_190 += V_6 -> V_16 . type -> V_193 ( & V_6 -> V_16 ,
& V_122 -> V_13 , type , V_188 + V_190 ,
V_189 - V_190 ) ;
}
}
break;
}
F_50 ( & V_19 -> V_21 , V_23 ) ;
}
static int F_154 ( struct V_9 * V_10 , unsigned V_125 , char * * V_121 )
{
int V_65 = - V_119 ;
struct V_162 * V_14 ;
struct V_18 * V_19 = V_10 -> V_35 ;
T_2 V_163 ;
F_149 ( & V_19 -> V_31 ) ;
if ( F_155 ( V_10 ) ) {
V_65 = - V_128 ;
goto V_156;
}
if ( V_125 == 1 ) {
if ( ! strcasecmp ( V_121 [ 0 ] , L_23 ) ) {
V_65 = F_88 ( V_19 , true , false ) ;
goto V_156;
} else if ( ! strcasecmp ( V_121 [ 0 ] , L_62 ) ) {
V_65 = F_88 ( V_19 , false , false ) ;
goto V_156;
}
}
if ( V_125 != 2 ) {
F_124 ( L_63 , V_125 ) ;
goto V_156;
}
if ( ! strcasecmp ( V_121 [ 0 ] , L_64 ) ) {
V_65 = F_133 ( V_19 , V_121 [ 1 ] , true ) ;
goto V_156;
} else if ( ! strcasecmp ( V_121 [ 0 ] , L_65 ) ) {
V_65 = F_133 ( V_19 , V_121 [ 1 ] , false ) ;
goto V_156;
} else if ( ! strcasecmp ( V_121 [ 0 ] , L_66 ) ) {
V_65 = F_132 ( V_19 , V_121 [ 1 ] ) ;
goto V_156;
} else if ( ! strcasecmp ( V_121 [ 0 ] , L_67 ) )
V_163 = F_128 ;
else if ( ! strcasecmp ( V_121 [ 0 ] , L_68 ) )
V_163 = F_123 ;
else {
F_124 ( L_69 , V_121 [ 0 ] ) ;
goto V_156;
}
V_65 = F_97 ( V_10 , V_121 [ 1 ] , F_98 ( V_10 -> V_36 ) , & V_14 ) ;
if ( V_65 ) {
F_124 ( L_70 ,
V_121 [ 1 ] ) ;
goto V_156;
}
V_65 = F_130 ( V_19 , V_14 , V_163 ) ;
F_11 ( V_10 , V_14 ) ;
V_156:
F_150 ( & V_19 -> V_31 ) ;
return V_65 ;
}
static int F_156 ( struct V_9 * V_10 ,
struct V_83 * * V_84 , T_4 * V_197 )
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
* V_197 = V_70 -> V_13 . V_14 -> V_197 ;
V_65 = 0 ;
} else {
V_65 = - V_198 ;
}
} else {
if ( F_42 ( V_75 , & V_19 -> V_23 ) )
V_65 = - V_198 ;
else
V_65 = - V_86 ;
}
if ( V_65 == - V_198 ) {
if ( ! F_56 ( V_19 -> V_61 ) ) {
( void ) F_57 ( V_19 , 0 ) ;
}
if ( F_42 ( V_60 , & V_19 -> V_23 ) )
F_48 ( V_19 ) ;
F_89 ( V_19 -> V_10 -> V_36 ) ;
F_77 ( V_19 ) ;
}
if ( ! V_65 && V_10 -> V_141 != F_157 ( ( * V_84 ) -> V_199 ) >> V_200 )
return 1 ;
return V_65 ;
}
static int F_158 ( struct V_9 * V_10 ,
T_5 V_201 , void * V_168 )
{
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_5 * V_6 ;
struct V_1 * V_122 ;
int V_139 = 0 ;
F_46 (pg, &m->priority_groups, list) {
F_46 (p, &pg->pgpaths, list) {
V_139 = V_201 ( V_10 , V_122 -> V_13 . V_14 , V_10 -> V_202 , V_10 -> V_141 , V_168 ) ;
if ( V_139 )
goto V_156;
}
}
V_156:
return V_139 ;
}
static int F_159 ( struct V_1 * V_1 )
{
struct V_123 * V_87 = F_65 ( V_1 -> V_13 . V_14 -> V_84 ) ;
return F_160 ( V_87 ) ;
}
static int F_161 ( struct V_9 * V_10 )
{
bool V_203 = false , V_204 = false ;
struct V_18 * V_19 = V_10 -> V_35 ;
struct V_5 * V_6 , * V_73 ;
struct V_1 * V_1 ;
if ( F_41 ( & V_19 -> V_25 ) )
return true ;
if ( ! F_41 ( & V_19 -> V_24 ) && F_42 ( V_75 , & V_19 -> V_23 ) )
return ( V_19 -> V_33 != V_37 ) ;
V_6 = F_56 ( V_19 -> V_61 ) ;
V_73 = F_56 ( V_19 -> V_73 ) ;
if ( F_55 ( ! F_56 ( V_19 -> V_70 ) && V_73 ) )
V_6 = V_73 ;
if ( ! V_6 ) {
return V_203 ;
}
V_203 = true ;
F_46 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_3 ) {
V_204 = true ;
if ( ! F_159 ( V_1 ) ) {
V_203 = false ;
break;
}
}
}
if ( ! V_204 ) {
V_203 = false ;
}
return V_203 ;
}
static int T_6 F_162 ( void )
{
int V_65 ;
V_40 = F_163 ( V_47 , 0 ) ;
if ( ! V_40 )
return - V_41 ;
V_65 = F_164 ( & V_205 ) ;
if ( V_65 < 0 ) {
F_109 ( L_71 , V_65 ) ;
V_65 = - V_119 ;
goto V_206;
}
V_100 = F_165 ( L_72 , V_207 , 0 ) ;
if ( ! V_100 ) {
F_109 ( L_73 ) ;
V_65 = - V_41 ;
goto V_208;
}
V_64 = F_166 ( L_74 ,
V_207 ) ;
if ( ! V_64 ) {
F_109 ( L_75 ) ;
V_65 = - V_41 ;
goto V_209;
}
return 0 ;
V_209:
F_167 ( V_100 ) ;
V_208:
F_168 ( & V_205 ) ;
V_206:
F_169 ( V_40 ) ;
return V_65 ;
}
static void T_7 F_170 ( void )
{
F_167 ( V_64 ) ;
F_167 ( V_100 ) ;
F_168 ( & V_205 ) ;
F_169 ( V_40 ) ;
}
