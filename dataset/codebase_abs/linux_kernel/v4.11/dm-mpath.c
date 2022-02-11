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
V_19 -> V_32 = V_33 ;
V_19 -> V_10 = V_10 ;
V_10 -> V_34 = V_19 ;
}
return V_19 ;
}
static int F_21 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
if ( V_19 -> V_32 == V_33 ) {
if ( F_22 ( F_23 ( V_10 -> V_35 ) ) )
V_19 -> V_32 = V_36 ;
else
V_19 -> V_32 = V_37 ;
} else if ( V_19 -> V_32 == V_38 ) {
F_18 ( & V_19 -> V_39 , V_39 ) ;
F_16 ( V_40 , & V_19 -> V_23 ) ;
}
F_24 ( V_10 -> V_35 , V_19 -> V_32 ) ;
return 0 ;
}
static void F_25 ( struct V_18 * V_19 )
{
struct V_5 * V_6 , * V_11 ;
F_9 (pg, tmp, &m->priority_groups, list) {
F_10 ( & V_6 -> V_12 ) ;
F_12 ( V_6 , V_19 -> V_10 ) ;
}
F_5 ( V_19 -> V_41 ) ;
F_5 ( V_19 -> V_42 ) ;
F_5 ( V_19 ) ;
}
static struct V_43 * F_26 ( union V_44 * V_45 )
{
return V_45 -> V_46 ;
}
static T_1 F_27 ( void )
{
return sizeof( struct V_43 ) + sizeof( struct V_47 ) ;
}
static struct V_43 * F_28 ( struct V_48 * V_48 )
{
return F_29 ( V_48 , F_27 () ) ;
}
static struct V_47 * F_30 ( struct V_48 * V_48 )
{
struct V_43 * V_49 = F_28 ( V_48 ) ;
void * V_50 = V_49 + 1 ;
return V_50 ;
}
static void F_31 ( struct V_48 * V_48 , struct V_43 * * V_51 ,
struct V_47 * * V_52 )
{
struct V_43 * V_49 = F_28 ( V_48 ) ;
struct V_47 * V_50 = F_30 ( V_48 ) ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_32 ( V_50 , V_48 ) ;
if ( V_51 )
* V_51 = V_49 ;
if ( V_52 )
* V_52 = V_50 ;
}
static int F_33 ( struct V_18 * V_19 )
{
struct V_1 * V_1 ;
unsigned long V_53 = 0 ;
if ( F_34 ( & V_19 -> V_25 ) || F_35 ( V_54 , & V_19 -> V_23 ) )
return 0 ;
F_36 ( & V_19 -> V_26 ) ;
F_37 ( V_55 , & V_19 -> V_23 ) ;
if ( ! V_19 -> V_56 )
return 0 ;
if ( F_35 ( V_57 , & V_19 -> V_23 ) )
V_53 = F_38 ( V_19 -> V_27 != V_28 ?
V_19 -> V_27 : V_58 ) ;
F_39 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_40 ( V_59 , & V_1 -> V_4 ,
V_53 ) )
F_36 ( & V_19 -> V_25 ) ;
}
return F_34 ( & V_19 -> V_25 ) ;
}
static void F_41 ( struct V_18 * V_19 )
{
unsigned long V_23 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
F_33 ( V_19 ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
}
static void F_44 ( struct V_18 * V_19 , struct V_5 * V_6 )
{
V_19 -> V_56 = V_6 ;
if ( V_19 -> V_41 ) {
F_16 ( V_55 , & V_19 -> V_23 ) ;
F_16 ( V_22 , & V_19 -> V_23 ) ;
} else {
F_37 ( V_55 , & V_19 -> V_23 ) ;
F_37 ( V_22 , & V_19 -> V_23 ) ;
}
F_17 ( & V_19 -> V_26 , 0 ) ;
}
static struct V_1 * F_45 ( struct V_18 * V_19 ,
struct V_5 * V_6 ,
T_1 V_60 )
{
unsigned long V_23 ;
struct V_61 * V_13 ;
struct V_1 * V_1 ;
V_13 = V_6 -> V_16 . type -> V_62 ( & V_6 -> V_16 , V_60 ) ;
if ( ! V_13 )
return F_46 ( - V_63 ) ;
V_1 = F_47 ( V_13 ) ;
if ( F_48 ( F_49 ( V_19 -> V_56 ) != V_6 ) ) {
F_42 ( & V_19 -> V_21 , V_23 ) ;
V_19 -> V_64 = V_1 ;
F_44 ( V_19 , V_6 ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
}
return V_1 ;
}
static struct V_1 * F_50 ( struct V_18 * V_19 , T_1 V_60 )
{
unsigned long V_23 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned V_65 = 1 ;
if ( ! F_34 ( & V_19 -> V_24 ) ) {
F_37 ( V_22 , & V_19 -> V_23 ) ;
goto V_66;
}
if ( F_49 ( V_19 -> V_67 ) ) {
F_42 ( & V_19 -> V_21 , V_23 ) ;
V_6 = V_19 -> V_67 ;
if ( ! V_6 ) {
F_43 ( & V_19 -> V_21 , V_23 ) ;
goto V_68;
}
V_19 -> V_67 = NULL ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
V_1 = F_45 ( V_19 , V_6 , V_60 ) ;
if ( ! F_51 ( V_1 ) )
return V_1 ;
}
V_68:
V_6 = F_49 ( V_19 -> V_56 ) ;
if ( V_6 ) {
V_1 = F_45 ( V_19 , V_6 , V_60 ) ;
if ( ! F_51 ( V_1 ) )
return V_1 ;
}
do {
F_39 (pg, &m->priority_groups, list) {
if ( V_6 -> V_65 == ! ! V_65 )
continue;
V_1 = F_45 ( V_19 , V_6 , V_60 ) ;
if ( ! F_51 ( V_1 ) ) {
if ( ! V_65 )
F_16 ( V_57 , & V_19 -> V_23 ) ;
return V_1 ;
}
}
} while ( V_65 -- );
V_66:
F_42 ( & V_19 -> V_21 , V_23 ) ;
V_19 -> V_64 = NULL ;
V_19 -> V_56 = NULL ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
return NULL ;
}
static bool F_52 ( struct V_18 * V_19 )
{
return ( ( F_35 ( V_69 , & V_19 -> V_23 ) !=
F_35 ( V_70 , & V_19 -> V_23 ) ) &&
F_53 ( V_19 -> V_10 ) ) ;
}
static bool F_54 ( struct V_18 * V_19 )
{
bool V_71 ;
unsigned long V_23 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
V_71 = ( F_35 ( V_69 , & V_19 -> V_23 ) ||
F_52 ( V_19 ) ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
return V_71 ;
}
static bool F_55 ( struct V_18 * V_19 )
{
bool V_71 ;
unsigned long V_23 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
V_71 = F_52 ( V_19 ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
return V_71 ;
}
static int F_56 ( struct V_9 * V_10 , struct V_72 * V_73 ,
union V_44 * V_74 ,
struct V_72 * * V_75 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
int V_71 = V_76 ;
T_1 V_60 = F_57 ( V_73 ) ;
struct V_1 * V_1 ;
struct V_77 * V_78 ;
struct V_43 * V_49 = F_26 ( V_74 ) ;
struct V_72 * V_79 ;
V_1 = F_49 ( V_19 -> V_64 ) ;
if ( ! V_1 || ! F_35 ( V_22 , & V_19 -> V_23 ) )
V_1 = F_50 ( V_19 , V_60 ) ;
if ( ! V_1 ) {
if ( F_54 ( V_19 ) )
return V_80 ;
return - V_81 ;
} else if ( F_35 ( V_22 , & V_19 -> V_23 ) ||
F_35 ( V_55 , & V_19 -> V_23 ) ) {
F_41 ( V_19 ) ;
return V_71 ;
}
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
V_49 -> V_1 = V_1 ;
V_49 -> V_60 = V_60 ;
V_78 = V_1 -> V_13 . V_14 -> V_78 ;
V_79 = F_58 ( F_59 ( V_78 ) ,
V_73 -> V_82 | V_83 ,
V_84 ) ;
if ( F_60 ( V_79 ) ) {
return V_71 ;
}
V_79 -> V_48 = V_79 -> V_85 = NULL ;
V_79 -> V_86 = V_78 -> V_87 ;
V_79 -> V_82 |= V_88 ;
* V_75 = V_79 ;
if ( V_1 -> V_6 -> V_16 . type -> V_89 )
V_1 -> V_6 -> V_16 . type -> V_89 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_60 ) ;
return V_90 ;
}
static void F_61 ( struct V_72 * V_79 )
{
F_62 ( V_79 ) ;
}
static int F_63 ( struct V_18 * V_19 , struct V_48 * V_48 , struct V_43 * V_49 )
{
T_1 V_60 = V_48 -> V_91 . V_92 ;
struct V_1 * V_1 ;
unsigned long V_23 ;
bool V_93 ;
V_1 = F_49 ( V_19 -> V_64 ) ;
V_93 = F_35 ( V_22 , & V_19 -> V_23 ) ;
if ( ! V_1 || ! V_93 )
V_1 = F_50 ( V_19 , V_60 ) ;
if ( ( V_1 && V_93 ) ||
( ! V_1 && F_35 ( V_69 , & V_19 -> V_23 ) ) ) {
F_42 ( & V_19 -> V_21 , V_23 ) ;
F_64 ( & V_19 -> V_94 , V_48 ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
if ( V_93 || F_35 ( V_55 , & V_19 -> V_23 ) )
F_41 ( V_19 ) ;
else if ( ! V_93 )
F_65 ( V_95 , & V_19 -> V_39 ) ;
return V_96 ;
}
if ( ! V_1 ) {
if ( ! F_55 ( V_19 ) )
return - V_81 ;
return V_76 ;
}
V_49 -> V_1 = V_1 ;
V_49 -> V_60 = V_60 ;
V_48 -> V_97 = 0 ;
V_48 -> V_98 = V_1 -> V_13 . V_14 -> V_78 ;
V_48 -> V_99 |= V_88 ;
if ( V_1 -> V_6 -> V_16 . type -> V_89 )
V_1 -> V_6 -> V_16 . type -> V_89 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_60 ) ;
return V_90 ;
}
static int F_66 ( struct V_9 * V_10 , struct V_48 * V_48 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
struct V_43 * V_49 = NULL ;
F_31 ( V_48 , & V_49 , NULL ) ;
return F_63 ( V_19 , V_48 , V_49 ) ;
}
static void F_67 ( struct V_18 * V_19 )
{
if ( V_19 -> V_32 == V_36 )
F_68 ( F_23 ( V_19 -> V_10 -> V_35 ) ) ;
else if ( V_19 -> V_32 == V_38 )
F_65 ( V_95 , & V_19 -> V_39 ) ;
}
static void V_39 ( struct V_100 * V_101 )
{
int V_71 ;
unsigned long V_23 ;
struct V_48 * V_48 ;
struct V_102 V_103 ;
struct V_104 V_105 ;
struct V_18 * V_19 =
F_69 ( V_101 , struct V_18 , V_39 ) ;
F_70 ( & V_103 ) ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
if ( F_71 ( & V_19 -> V_94 ) ) {
F_43 ( & V_19 -> V_21 , V_23 ) ;
return;
}
F_72 ( & V_103 , & V_19 -> V_94 ) ;
F_70 ( & V_19 -> V_94 ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
F_73 ( & V_105 ) ;
while ( ( V_48 = F_74 ( & V_103 ) ) ) {
V_71 = F_63 ( V_19 , V_48 , F_28 ( V_48 ) ) ;
if ( V_71 < 0 || V_71 == V_76 ) {
V_48 -> V_97 = V_71 ;
F_75 ( V_48 ) ;
} else if ( V_71 == V_90 )
F_76 ( V_48 ) ;
}
F_77 ( & V_105 ) ;
}
static int F_78 ( struct V_18 * V_19 , bool F_78 ,
bool V_106 )
{
unsigned long V_23 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
if ( V_106 ) {
if ( F_35 ( V_69 , & V_19 -> V_23 ) )
F_16 ( V_70 , & V_19 -> V_23 ) ;
else
F_37 ( V_70 , & V_19 -> V_23 ) ;
} else {
if ( F_78 )
F_16 ( V_70 , & V_19 -> V_23 ) ;
else
F_37 ( V_70 , & V_19 -> V_23 ) ;
}
if ( F_78 )
F_16 ( V_69 , & V_19 -> V_23 ) ;
else
F_37 ( V_69 , & V_19 -> V_23 ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
if ( ! F_78 ) {
F_79 ( V_19 -> V_10 -> V_35 ) ;
F_67 ( V_19 ) ;
}
return 0 ;
}
static void V_29 ( struct V_100 * V_101 )
{
struct V_18 * V_19 =
F_69 ( V_101 , struct V_18 , V_29 ) ;
F_80 ( V_19 -> V_10 -> V_35 ) ;
}
static int F_81 ( struct V_107 * V_108 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_71 ;
struct V_109 * V_110 ;
unsigned V_111 ;
static struct V_112 V_113 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_110 = F_82 ( F_83 ( V_108 ) ) ;
if ( ! V_110 ) {
V_10 -> error = L_2 ;
return - V_114 ;
}
V_71 = F_84 ( V_113 , V_108 , & V_111 , & V_10 -> error ) ;
if ( V_71 ) {
F_13 ( V_110 ) ;
return - V_114 ;
}
V_71 = V_110 -> V_115 ( & V_6 -> V_16 , V_111 , V_108 -> V_116 ) ;
if ( V_71 ) {
F_13 ( V_110 ) ;
V_10 -> error = L_3 ;
return V_71 ;
}
V_6 -> V_16 . type = V_110 ;
F_85 ( V_108 , V_111 ) ;
return 0 ;
}
static struct V_1 * F_86 ( struct V_107 * V_108 , struct V_15 * V_16 ,
struct V_9 * V_10 )
{
int V_71 ;
struct V_1 * V_117 ;
struct V_18 * V_19 = V_10 -> V_34 ;
struct V_118 * V_119 = NULL ;
const char * V_120 ;
if ( V_108 -> V_121 < 1 ) {
V_10 -> error = L_4 ;
return F_46 ( - V_114 ) ;
}
V_117 = F_1 () ;
if ( ! V_117 )
return F_46 ( - V_122 ) ;
V_71 = F_87 ( V_10 , F_83 ( V_108 ) , F_88 ( V_10 -> V_35 ) ,
& V_117 -> V_13 . V_14 ) ;
if ( V_71 ) {
V_10 -> error = L_5 ;
goto V_123;
}
if ( F_35 ( V_40 , & V_19 -> V_23 ) || V_19 -> V_41 )
V_119 = F_59 ( V_117 -> V_13 . V_14 -> V_78 ) ;
if ( F_35 ( V_40 , & V_19 -> V_23 ) ) {
V_124:
V_120 = F_89 ( V_119 , V_2 ) ;
if ( V_120 ) {
if ( V_19 -> V_41 && strcmp ( V_120 , V_19 -> V_41 ) ) {
F_5 ( V_19 -> V_42 ) ;
V_19 -> V_42 = NULL ;
}
F_5 ( V_19 -> V_41 ) ;
V_19 -> V_41 = V_120 ;
}
}
if ( V_19 -> V_41 ) {
V_71 = F_90 ( V_119 , V_19 -> V_41 ) ;
if ( V_71 == - V_125 ) {
char V_126 [ V_127 ] ;
F_91 ( V_128 L_6 ,
F_92 ( V_117 -> V_13 . V_14 -> V_78 , V_126 ) ) ;
goto V_124;
}
if ( V_71 < 0 ) {
V_10 -> error = L_7 ;
F_11 ( V_10 , V_117 -> V_13 . V_14 ) ;
goto V_123;
}
if ( V_19 -> V_42 ) {
V_71 = F_93 ( V_119 , V_19 -> V_42 ) ;
if ( V_71 < 0 ) {
V_10 -> error = L_8
L_9 ;
F_11 ( V_10 , V_117 -> V_13 . V_14 ) ;
goto V_123;
}
}
}
V_71 = V_16 -> type -> V_129 ( V_16 , & V_117 -> V_13 , V_108 -> V_121 , V_108 -> V_116 , & V_10 -> error ) ;
if ( V_71 ) {
F_11 ( V_10 , V_117 -> V_13 . V_14 ) ;
goto V_123;
}
return V_117 ;
V_123:
F_4 ( V_117 ) ;
return F_46 ( V_71 ) ;
}
static struct V_5 * F_94 ( struct V_107 * V_108 ,
struct V_18 * V_19 )
{
static struct V_112 V_113 [] = {
{ 1 , 1024 , L_10 } ,
{ 0 , 1024 , L_11 }
} ;
int V_71 ;
unsigned V_130 , V_131 , V_132 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_19 -> V_10 ;
if ( V_108 -> V_121 < 2 ) {
V_108 -> V_121 = 0 ;
V_10 -> error = L_12 ;
return F_46 ( - V_114 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_13 ;
return F_46 ( - V_122 ) ;
}
V_6 -> V_19 = V_19 ;
V_71 = F_81 ( V_108 , V_6 , V_10 ) ;
if ( V_71 )
goto V_123;
V_71 = F_95 ( V_113 , V_108 , & V_6 -> V_133 , & V_10 -> error ) ;
if ( V_71 )
goto V_123;
V_71 = F_95 ( V_113 + 1 , V_108 , & V_131 , & V_10 -> error ) ;
if ( V_71 )
goto V_123;
V_132 = 1 + V_131 ;
for ( V_130 = 0 ; V_130 < V_6 -> V_133 ; V_130 ++ ) {
struct V_1 * V_1 ;
struct V_107 V_134 ;
if ( V_108 -> V_121 < V_132 ) {
V_10 -> error = L_14 ;
V_71 = - V_114 ;
goto V_123;
}
V_134 . V_121 = V_132 ;
V_134 . V_116 = V_108 -> V_116 ;
V_1 = F_86 ( & V_134 , & V_6 -> V_16 , V_10 ) ;
if ( F_60 ( V_1 ) ) {
V_71 = F_96 ( V_1 ) ;
goto V_123;
}
V_1 -> V_6 = V_6 ;
F_97 ( & V_1 -> V_12 , & V_6 -> V_7 ) ;
F_85 ( V_108 , V_132 ) ;
}
return V_6 ;
V_123:
F_12 ( V_6 , V_10 ) ;
return F_46 ( V_71 ) ;
}
static int F_98 ( struct V_107 * V_108 , struct V_18 * V_19 )
{
unsigned V_135 ;
int V_136 ;
struct V_9 * V_10 = V_19 -> V_10 ;
static struct V_112 V_113 [] = {
{ 0 , 1024 , L_15 } ,
} ;
if ( F_84 ( V_113 , V_108 , & V_135 , & V_10 -> error ) )
return - V_114 ;
if ( ! V_135 )
return 0 ;
if ( V_19 -> V_32 == V_38 ) {
F_85 ( V_108 , V_135 ) ;
F_99 ( L_16 ) ;
return 0 ;
}
V_19 -> V_41 = F_100 ( F_83 ( V_108 ) , V_2 ) ;
if ( ! V_19 -> V_41 )
return - V_114 ;
if ( V_135 > 1 ) {
char * V_117 ;
int V_130 , V_137 , V_138 = 4 ;
for ( V_130 = 0 ; V_130 <= V_135 - 2 ; V_130 ++ )
V_138 += strlen ( V_108 -> V_116 [ V_130 ] ) + 1 ;
V_117 = V_19 -> V_42 = F_2 ( V_138 , V_2 ) ;
if ( ! V_117 ) {
V_10 -> error = L_17 ;
V_136 = - V_122 ;
goto V_139;
}
V_137 = sprintf ( V_117 , L_18 , V_135 - 1 ) ;
for ( V_130 = 0 , V_117 += V_137 + 1 ; V_130 <= V_135 - 2 ; V_130 ++ , V_117 += V_137 + 1 )
V_137 = sprintf ( V_117 , L_19 , V_108 -> V_116 [ V_130 ] ) ;
}
F_85 ( V_108 , V_135 - 1 ) ;
return 0 ;
V_139:
F_5 ( V_19 -> V_41 ) ;
V_19 -> V_41 = NULL ;
return V_136 ;
}
static int F_101 ( struct V_107 * V_108 , struct V_18 * V_19 )
{
int V_71 ;
unsigned V_121 ;
struct V_9 * V_10 = V_19 -> V_10 ;
const char * V_140 ;
static struct V_112 V_113 [] = {
{ 0 , 8 , L_20 } ,
{ 1 , 50 , L_21 } ,
{ 0 , 60000 , L_22 } ,
} ;
V_71 = F_84 ( V_113 , V_108 , & V_121 , & V_10 -> error ) ;
if ( V_71 )
return - V_114 ;
if ( ! V_121 )
return 0 ;
do {
V_140 = F_83 ( V_108 ) ;
V_121 -- ;
if ( ! strcasecmp ( V_140 , L_23 ) ) {
V_71 = F_78 ( V_19 , true , false ) ;
continue;
}
if ( ! strcasecmp ( V_140 , L_24 ) ) {
F_16 ( V_40 , & V_19 -> V_23 ) ;
continue;
}
if ( ! strcasecmp ( V_140 , L_25 ) &&
( V_121 >= 1 ) ) {
V_71 = F_95 ( V_113 + 1 , V_108 , & V_19 -> V_141 , & V_10 -> error ) ;
V_121 -- ;
continue;
}
if ( ! strcasecmp ( V_140 , L_26 ) &&
( V_121 >= 1 ) ) {
V_71 = F_95 ( V_113 + 2 , V_108 , & V_19 -> V_27 , & V_10 -> error ) ;
V_121 -- ;
continue;
}
if ( ! strcasecmp ( V_140 , L_27 ) &&
( V_121 >= 1 ) ) {
const char * V_142 = F_83 ( V_108 ) ;
if ( ! strcasecmp ( V_142 , L_28 ) )
V_19 -> V_32 = V_38 ;
else if ( ! strcasecmp ( V_142 , L_29 ) )
V_19 -> V_32 = V_37 ;
else if ( ! strcasecmp ( V_142 , L_30 ) )
V_19 -> V_32 = V_36 ;
else {
V_10 -> error = L_31 ;
V_71 = - V_114 ;
}
V_121 -- ;
continue;
}
V_10 -> error = L_32 ;
V_71 = - V_114 ;
} while ( V_121 && ! V_71 );
return V_71 ;
}
static int F_102 ( struct V_9 * V_10 , unsigned V_121 , char * * V_116 )
{
static struct V_112 V_113 [] = {
{ 0 , 1024 , L_33 } ,
{ 0 , 1024 , L_34 } ,
} ;
int V_71 ;
struct V_18 * V_19 ;
struct V_107 V_108 ;
unsigned V_143 = 0 ;
unsigned V_144 ;
V_108 . V_121 = V_121 ;
V_108 . V_116 = V_116 ;
V_19 = F_14 ( V_10 ) ;
if ( ! V_19 ) {
V_10 -> error = L_35 ;
return - V_114 ;
}
V_71 = F_101 ( & V_108 , V_19 ) ;
if ( V_71 )
goto V_123;
V_71 = F_21 ( V_10 , V_19 ) ;
if ( V_71 )
goto V_123;
V_71 = F_98 ( & V_108 , V_19 ) ;
if ( V_71 )
goto V_123;
V_71 = F_95 ( V_113 , & V_108 , & V_19 -> V_145 , & V_10 -> error ) ;
if ( V_71 )
goto V_123;
V_71 = F_95 ( V_113 + 1 , & V_108 , & V_144 , & V_10 -> error ) ;
if ( V_71 )
goto V_123;
if ( ( ! V_19 -> V_145 && V_144 ) ||
( V_19 -> V_145 && ! V_144 ) ) {
V_10 -> error = L_36 ;
V_71 = - V_114 ;
goto V_123;
}
while ( V_108 . V_121 ) {
struct V_5 * V_6 ;
unsigned V_24 = F_34 ( & V_19 -> V_24 ) ;
V_6 = F_94 ( & V_108 , V_19 ) ;
if ( F_60 ( V_6 ) ) {
V_71 = F_96 ( V_6 ) ;
goto V_123;
}
V_24 += V_6 -> V_133 ;
F_17 ( & V_19 -> V_24 , V_24 ) ;
F_97 ( & V_6 -> V_12 , & V_19 -> V_20 ) ;
V_143 ++ ;
V_6 -> V_146 = V_143 ;
if ( ! -- V_144 )
V_19 -> V_67 = V_6 ;
}
if ( V_143 != V_19 -> V_145 ) {
V_10 -> error = L_37 ;
V_71 = - V_114 ;
goto V_123;
}
V_10 -> V_147 = 1 ;
V_10 -> V_148 = 1 ;
V_10 -> V_149 = 1 ;
if ( V_19 -> V_32 == V_38 )
V_10 -> V_150 = F_27 () ;
else
V_10 -> V_150 = sizeof( struct V_43 ) ;
return 0 ;
V_123:
F_25 ( V_19 ) ;
return V_71 ;
}
static void F_103 ( struct V_18 * V_19 )
{
F_104 ( V_151 ) ;
while ( 1 ) {
F_105 ( & V_19 -> V_30 , & V_151 , V_152 ) ;
if ( ! F_34 ( & V_19 -> V_25 ) )
break;
F_106 () ;
}
F_107 ( & V_19 -> V_30 , & V_151 ) ;
}
static void F_108 ( struct V_18 * V_19 )
{
F_16 ( V_54 , & V_19 -> V_23 ) ;
F_109 () ;
F_110 ( V_59 ) ;
F_103 ( V_19 ) ;
F_110 ( V_95 ) ;
F_111 ( & V_19 -> V_29 ) ;
F_37 ( V_54 , & V_19 -> V_23 ) ;
F_109 () ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
F_108 ( V_19 ) ;
F_25 ( V_19 ) ;
}
static int F_113 ( struct V_1 * V_1 )
{
unsigned long V_23 ;
struct V_18 * V_19 = V_1 -> V_6 -> V_19 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
if ( ! V_1 -> V_3 )
goto V_153;
F_114 ( L_38 , V_1 -> V_13 . V_14 -> V_154 ) ;
V_1 -> V_6 -> V_16 . type -> F_113 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
V_1 -> V_3 = false ;
V_1 -> V_155 ++ ;
F_115 ( & V_19 -> V_24 ) ;
if ( V_1 == V_19 -> V_64 )
V_19 -> V_64 = NULL ;
F_116 ( V_156 , V_19 -> V_10 ,
V_1 -> V_13 . V_14 -> V_154 , F_34 ( & V_19 -> V_24 ) ) ;
F_117 ( & V_19 -> V_29 ) ;
V_153:
F_43 ( & V_19 -> V_21 , V_23 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_1 )
{
int V_71 = 0 , V_157 = 0 ;
unsigned long V_23 ;
struct V_18 * V_19 = V_1 -> V_6 -> V_19 ;
unsigned V_24 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
if ( V_1 -> V_3 )
goto V_153;
F_114 ( L_39 , V_1 -> V_13 . V_14 -> V_154 ) ;
V_71 = V_1 -> V_6 -> V_16 . type -> F_118 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
if ( V_71 )
goto V_153;
V_1 -> V_3 = true ;
V_24 = F_119 ( & V_19 -> V_24 ) ;
if ( V_24 == 1 ) {
V_19 -> V_64 = NULL ;
V_157 = 1 ;
} else if ( V_19 -> V_41 && ( V_19 -> V_56 == V_1 -> V_6 ) ) {
if ( F_65 ( V_59 , & V_1 -> V_4 . V_101 ) )
F_36 ( & V_19 -> V_25 ) ;
}
F_116 ( V_158 , V_19 -> V_10 ,
V_1 -> V_13 . V_14 -> V_154 , V_24 ) ;
F_117 ( & V_19 -> V_29 ) ;
V_153:
F_43 ( & V_19 -> V_21 , V_23 ) ;
if ( V_157 ) {
F_79 ( V_19 -> V_10 -> V_35 ) ;
F_67 ( V_19 ) ;
}
return V_71 ;
}
static int F_120 ( struct V_18 * V_19 , struct V_159 * V_14 ,
T_2 V_160 )
{
int V_71 = - V_114 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_39 (pg, &m->priority_groups, list) {
F_39 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_13 . V_14 == V_14 )
V_71 = V_160 ( V_1 ) ;
}
}
return V_71 ;
}
static void F_121 ( struct V_18 * V_19 , struct V_5 * V_6 ,
bool V_65 )
{
unsigned long V_23 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
V_6 -> V_65 = V_65 ;
V_19 -> V_64 = NULL ;
V_19 -> V_56 = NULL ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
F_117 ( & V_19 -> V_29 ) ;
}
static int F_122 ( struct V_18 * V_19 , const char * V_161 )
{
struct V_5 * V_6 ;
unsigned V_162 ;
unsigned long V_23 ;
char V_163 ;
if ( ! V_161 || ( sscanf ( V_161 , L_40 , & V_162 , & V_163 ) != 1 ) || ! V_162 ||
! V_19 -> V_145 || ( V_162 > V_19 -> V_145 ) ) {
F_114 ( L_41 ) ;
return - V_114 ;
}
F_42 ( & V_19 -> V_21 , V_23 ) ;
F_39 (pg, &m->priority_groups, list) {
V_6 -> V_65 = false ;
if ( -- V_162 )
continue;
V_19 -> V_64 = NULL ;
V_19 -> V_56 = NULL ;
V_19 -> V_67 = V_6 ;
}
F_43 ( & V_19 -> V_21 , V_23 ) ;
F_117 ( & V_19 -> V_29 ) ;
return 0 ;
}
static int F_123 ( struct V_18 * V_19 , const char * V_161 , bool V_65 )
{
struct V_5 * V_6 ;
unsigned V_162 ;
char V_163 ;
if ( ! V_161 || ( sscanf ( V_161 , L_40 , & V_162 , & V_163 ) != 1 ) || ! V_162 ||
! V_19 -> V_145 || ( V_162 > V_19 -> V_145 ) ) {
F_114 ( L_42 ) ;
return - V_114 ;
}
F_39 (pg, &m->priority_groups, list) {
if ( ! -- V_162 )
break;
}
F_121 ( V_19 , V_6 , V_65 ) ;
return 0 ;
}
static bool F_124 ( struct V_18 * V_19 , struct V_1 * V_1 )
{
unsigned long V_23 ;
bool V_164 = false ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
if ( F_34 ( & V_19 -> V_26 ) <= V_19 -> V_141 &&
! F_35 ( V_54 , & V_19 -> V_23 ) )
F_16 ( V_55 , & V_19 -> V_23 ) ;
else
V_164 = true ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
return V_164 ;
}
static void F_125 ( void * V_165 , int V_166 )
{
struct V_1 * V_1 = V_165 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
unsigned long V_23 ;
bool V_167 = false ;
switch ( V_166 ) {
case V_168 :
break;
case V_169 :
if ( ! V_19 -> V_41 ) {
V_166 = 0 ;
break;
}
F_99 ( L_43
L_44 , V_19 -> V_41 , V_166 ) ;
F_113 ( V_1 ) ;
break;
case V_170 :
F_121 ( V_19 , V_6 , true ) ;
break;
case V_171 :
V_167 = 1 ;
case V_172 :
case V_173 :
if ( F_124 ( V_19 , V_1 ) )
F_113 ( V_1 ) ;
V_166 = 0 ;
break;
case V_174 :
default:
F_113 ( V_1 ) ;
}
F_42 ( & V_19 -> V_21 , V_23 ) ;
if ( V_166 ) {
if ( V_1 == V_19 -> V_64 ) {
F_99 ( L_45 , V_166 ) ;
V_19 -> V_64 = NULL ;
V_19 -> V_56 = NULL ;
}
} else if ( ! F_35 ( V_55 , & V_19 -> V_23 ) )
V_6 -> V_65 = false ;
if ( F_126 ( & V_19 -> V_25 ) > 0 )
goto V_153;
if ( F_35 ( V_55 , & V_19 -> V_23 ) ) {
if ( V_167 )
F_16 ( V_57 , & V_19 -> V_23 ) ;
else
F_37 ( V_57 , & V_19 -> V_23 ) ;
if ( F_33 ( V_19 ) )
goto V_153;
}
F_37 ( V_22 , & V_19 -> V_23 ) ;
F_67 ( V_19 ) ;
F_127 ( & V_19 -> V_30 ) ;
V_153:
F_43 ( & V_19 -> V_21 , V_23 ) ;
}
static void V_4 ( struct V_100 * V_101 )
{
struct V_1 * V_1 =
F_69 ( V_101 , struct V_1 , V_4 . V_101 ) ;
struct V_118 * V_119 = F_59 ( V_1 -> V_13 . V_14 -> V_78 ) ;
if ( V_1 -> V_3 && ! F_128 ( V_119 ) )
F_129 ( V_119 , F_125 , V_1 ) ;
else
F_125 ( V_1 , V_174 ) ;
}
static int F_130 ( int error )
{
switch ( error ) {
case - V_175 :
case - V_176 :
case - V_177 :
case - V_178 :
case - V_179 :
case - V_180 :
return 1 ;
}
return 0 ;
}
static int F_131 ( struct V_18 * V_19 , struct V_72 * V_79 ,
int error , struct V_43 * V_49 )
{
int V_71 = V_181 ;
if ( ! error && ! V_79 -> V_166 )
return 0 ;
if ( F_130 ( error ) )
return error ;
if ( V_49 -> V_1 )
F_113 ( V_49 -> V_1 ) ;
if ( ! F_34 ( & V_19 -> V_24 ) ) {
if ( ! F_35 ( V_69 , & V_19 -> V_23 ) ) {
if ( ! F_54 ( V_19 ) )
V_71 = - V_81 ;
}
}
return V_71 ;
}
static int F_132 ( struct V_9 * V_10 , struct V_72 * V_79 ,
int error , union V_44 * V_74 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
struct V_43 * V_49 = F_26 ( V_74 ) ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_71 ;
F_133 ( ! V_49 ) ;
V_71 = F_131 ( V_19 , V_79 , error , V_49 ) ;
V_1 = V_49 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_182 )
V_16 -> type -> V_182 ( V_16 , & V_1 -> V_13 , V_49 -> V_60 ) ;
}
return V_71 ;
}
static int F_134 ( struct V_18 * V_19 , struct V_48 * V_79 ,
int error , struct V_43 * V_49 )
{
unsigned long V_23 ;
if ( ! error )
return 0 ;
if ( F_130 ( error ) )
return error ;
if ( V_49 -> V_1 )
F_113 ( V_49 -> V_1 ) ;
if ( ! F_34 ( & V_19 -> V_24 ) ) {
if ( ! F_35 ( V_69 , & V_19 -> V_23 ) ) {
if ( ! F_55 ( V_19 ) )
return - V_81 ;
return V_181 ;
}
}
F_135 ( F_30 ( V_79 ) , V_79 ) ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
F_64 ( & V_19 -> V_94 , V_79 ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
if ( ! F_35 ( V_22 , & V_19 -> V_23 ) )
F_65 ( V_95 , & V_19 -> V_39 ) ;
return V_183 ;
}
static int F_136 ( struct V_9 * V_10 , struct V_48 * V_79 , int error )
{
struct V_18 * V_19 = V_10 -> V_34 ;
struct V_43 * V_49 = F_28 ( V_79 ) ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_71 ;
F_133 ( ! V_49 ) ;
V_71 = F_134 ( V_19 , V_79 , error , V_49 ) ;
V_1 = V_49 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_182 )
V_16 -> type -> V_182 ( V_16 , & V_1 -> V_13 , V_49 -> V_60 ) ;
}
return V_71 ;
}
static void F_137 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
F_78 ( V_19 , false , true ) ;
}
static void F_138 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
F_139 ( & V_19 -> V_31 ) ;
F_108 ( V_19 ) ;
F_140 ( & V_19 -> V_31 ) ;
}
static void F_141 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
unsigned long V_23 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
if ( F_35 ( V_70 , & V_19 -> V_23 ) )
F_16 ( V_69 , & V_19 -> V_23 ) ;
else
F_37 ( V_69 , & V_19 -> V_23 ) ;
F_43 ( & V_19 -> V_21 , V_23 ) ;
}
static void F_142 ( struct V_9 * V_10 , T_3 type ,
unsigned V_184 , char * V_185 , unsigned V_186 )
{
int V_187 = 0 ;
unsigned long V_23 ;
struct V_18 * V_19 = V_10 -> V_34 ;
struct V_5 * V_6 ;
struct V_1 * V_117 ;
unsigned V_146 ;
char V_188 ;
F_42 ( & V_19 -> V_21 , V_23 ) ;
if ( type == V_189 )
F_143 ( L_46 , F_35 ( V_22 , & V_19 -> V_23 ) ,
F_34 ( & V_19 -> V_26 ) ) ;
else {
F_143 ( L_47 , F_35 ( V_69 , & V_19 -> V_23 ) +
( V_19 -> V_141 > 0 ) * 2 +
( V_19 -> V_27 != V_28 ) * 2 +
F_35 ( V_40 , & V_19 -> V_23 ) +
( V_19 -> V_32 != V_37 ) * 2 ) ;
if ( F_35 ( V_69 , & V_19 -> V_23 ) )
F_143 ( L_48 ) ;
if ( V_19 -> V_141 )
F_143 ( L_49 , V_19 -> V_141 ) ;
if ( V_19 -> V_27 != V_28 )
F_143 ( L_50 , V_19 -> V_27 ) ;
if ( F_35 ( V_40 , & V_19 -> V_23 ) )
F_143 ( L_51 ) ;
if ( V_19 -> V_32 != V_37 ) {
switch( V_19 -> V_32 ) {
case V_38 :
F_143 ( L_52 ) ;
break;
case V_36 :
F_143 ( L_53 ) ;
break;
}
}
}
if ( ! V_19 -> V_41 || type == V_189 )
F_143 ( L_54 ) ;
else
F_143 ( L_55 , V_19 -> V_41 ) ;
F_143 ( L_47 , V_19 -> V_145 ) ;
if ( V_19 -> V_67 )
V_146 = V_19 -> V_67 -> V_146 ;
else if ( V_19 -> V_56 )
V_146 = V_19 -> V_56 -> V_146 ;
else
V_146 = ( V_19 -> V_145 ? 1 : 0 ) ;
F_143 ( L_47 , V_146 ) ;
switch ( type ) {
case V_189 :
F_39 (pg, &m->priority_groups, list) {
if ( V_6 -> V_65 )
V_188 = 'D' ;
else if ( V_6 == V_19 -> V_56 )
V_188 = 'A' ;
else
V_188 = 'E' ;
F_143 ( L_56 , V_188 ) ;
if ( V_6 -> V_16 . type -> V_190 )
V_187 += V_6 -> V_16 . type -> V_190 ( & V_6 -> V_16 , NULL , type ,
V_185 + V_187 ,
V_186 - V_187 ) ;
else
F_143 ( L_54 ) ;
F_143 ( L_57 , V_6 -> V_133 ,
V_6 -> V_16 . type -> V_191 ) ;
F_39 (p, &pg->pgpaths, list) {
F_143 ( L_58 , V_117 -> V_13 . V_14 -> V_154 ,
V_117 -> V_3 ? L_59 : L_60 ,
V_117 -> V_155 ) ;
if ( V_6 -> V_16 . type -> V_190 )
V_187 += V_6 -> V_16 . type -> V_190 ( & V_6 -> V_16 ,
& V_117 -> V_13 , type , V_185 + V_187 ,
V_186 - V_187 ) ;
}
}
break;
case V_192 :
F_39 (pg, &m->priority_groups, list) {
F_143 ( L_61 , V_6 -> V_16 . type -> V_154 ) ;
if ( V_6 -> V_16 . type -> V_190 )
V_187 += V_6 -> V_16 . type -> V_190 ( & V_6 -> V_16 , NULL , type ,
V_185 + V_187 ,
V_186 - V_187 ) ;
else
F_143 ( L_54 ) ;
F_143 ( L_57 , V_6 -> V_133 ,
V_6 -> V_16 . type -> V_193 ) ;
F_39 (p, &pg->pgpaths, list) {
F_143 ( L_61 , V_117 -> V_13 . V_14 -> V_154 ) ;
if ( V_6 -> V_16 . type -> V_190 )
V_187 += V_6 -> V_16 . type -> V_190 ( & V_6 -> V_16 ,
& V_117 -> V_13 , type , V_185 + V_187 ,
V_186 - V_187 ) ;
}
}
break;
}
F_43 ( & V_19 -> V_21 , V_23 ) ;
}
static int F_144 ( struct V_9 * V_10 , unsigned V_121 , char * * V_116 )
{
int V_71 = - V_114 ;
struct V_159 * V_14 ;
struct V_18 * V_19 = V_10 -> V_34 ;
T_2 V_160 ;
F_139 ( & V_19 -> V_31 ) ;
if ( F_145 ( V_10 ) ) {
V_71 = - V_125 ;
goto V_153;
}
if ( V_121 == 1 ) {
if ( ! strcasecmp ( V_116 [ 0 ] , L_23 ) ) {
V_71 = F_78 ( V_19 , true , false ) ;
goto V_153;
} else if ( ! strcasecmp ( V_116 [ 0 ] , L_62 ) ) {
V_71 = F_78 ( V_19 , false , false ) ;
goto V_153;
}
}
if ( V_121 != 2 ) {
F_114 ( L_63 , V_121 ) ;
goto V_153;
}
if ( ! strcasecmp ( V_116 [ 0 ] , L_64 ) ) {
V_71 = F_123 ( V_19 , V_116 [ 1 ] , true ) ;
goto V_153;
} else if ( ! strcasecmp ( V_116 [ 0 ] , L_65 ) ) {
V_71 = F_123 ( V_19 , V_116 [ 1 ] , false ) ;
goto V_153;
} else if ( ! strcasecmp ( V_116 [ 0 ] , L_66 ) ) {
V_71 = F_122 ( V_19 , V_116 [ 1 ] ) ;
goto V_153;
} else if ( ! strcasecmp ( V_116 [ 0 ] , L_67 ) )
V_160 = F_118 ;
else if ( ! strcasecmp ( V_116 [ 0 ] , L_68 ) )
V_160 = F_113 ;
else {
F_114 ( L_69 , V_116 [ 0 ] ) ;
goto V_153;
}
V_71 = F_87 ( V_10 , V_116 [ 1 ] , F_88 ( V_10 -> V_35 ) , & V_14 ) ;
if ( V_71 ) {
F_114 ( L_70 ,
V_116 [ 1 ] ) ;
goto V_153;
}
V_71 = F_120 ( V_19 , V_14 , V_160 ) ;
F_11 ( V_10 , V_14 ) ;
V_153:
F_140 ( & V_19 -> V_31 ) ;
return V_71 ;
}
static int F_146 ( struct V_9 * V_10 ,
struct V_77 * * V_78 , T_4 * V_194 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
struct V_1 * V_64 ;
int V_71 ;
V_64 = F_49 ( V_19 -> V_64 ) ;
if ( ! V_64 )
V_64 = F_50 ( V_19 , 0 ) ;
if ( V_64 ) {
if ( ! F_35 ( V_22 , & V_19 -> V_23 ) ) {
* V_78 = V_64 -> V_13 . V_14 -> V_78 ;
* V_194 = V_64 -> V_13 . V_14 -> V_194 ;
V_71 = 0 ;
} else {
V_71 = - V_195 ;
}
} else {
if ( F_35 ( V_69 , & V_19 -> V_23 ) )
V_71 = - V_195 ;
else
V_71 = - V_81 ;
}
if ( V_71 == - V_195 ) {
if ( ! F_49 ( V_19 -> V_56 ) ) {
( void ) F_50 ( V_19 , 0 ) ;
}
if ( F_35 ( V_55 , & V_19 -> V_23 ) )
F_41 ( V_19 ) ;
F_79 ( V_19 -> V_10 -> V_35 ) ;
F_67 ( V_19 ) ;
}
if ( ! V_71 && V_10 -> V_138 != F_147 ( ( * V_78 ) -> V_196 ) >> V_197 )
return 1 ;
return V_71 ;
}
static int F_148 ( struct V_9 * V_10 ,
T_5 V_198 , void * V_165 )
{
struct V_18 * V_19 = V_10 -> V_34 ;
struct V_5 * V_6 ;
struct V_1 * V_117 ;
int V_136 = 0 ;
F_39 (pg, &m->priority_groups, list) {
F_39 (p, &pg->pgpaths, list) {
V_136 = V_198 ( V_10 , V_117 -> V_13 . V_14 , V_10 -> V_199 , V_10 -> V_138 , V_165 ) ;
if ( V_136 )
goto V_153;
}
}
V_153:
return V_136 ;
}
static int F_149 ( struct V_1 * V_1 )
{
struct V_118 * V_119 = F_59 ( V_1 -> V_13 . V_14 -> V_78 ) ;
return F_150 ( V_119 ) ;
}
static int F_151 ( struct V_9 * V_10 )
{
bool V_200 = false , V_201 = false ;
struct V_18 * V_19 = V_10 -> V_34 ;
struct V_5 * V_6 , * V_67 ;
struct V_1 * V_1 ;
if ( F_34 ( & V_19 -> V_25 ) )
return true ;
if ( ! F_34 ( & V_19 -> V_24 ) && F_35 ( V_69 , & V_19 -> V_23 ) )
return ( V_19 -> V_32 != V_36 ) ;
V_6 = F_49 ( V_19 -> V_56 ) ;
V_67 = F_49 ( V_19 -> V_67 ) ;
if ( F_48 ( ! F_49 ( V_19 -> V_64 ) && V_67 ) )
V_6 = V_67 ;
if ( ! V_6 ) {
return V_200 ;
}
V_200 = true ;
F_39 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_3 ) {
V_201 = true ;
if ( ! F_149 ( V_1 ) ) {
V_200 = false ;
break;
}
}
}
if ( ! V_201 ) {
V_200 = false ;
}
return V_200 ;
}
static int T_6 F_152 ( void )
{
int V_71 ;
V_71 = F_153 ( & V_202 ) ;
if ( V_71 < 0 ) {
F_99 ( L_71 , V_71 ) ;
V_71 = - V_114 ;
goto V_203;
}
V_95 = F_154 ( L_72 , V_204 , 0 ) ;
if ( ! V_95 ) {
F_99 ( L_73 ) ;
V_71 = - V_122 ;
goto V_205;
}
V_59 = F_155 ( L_74 ,
V_204 ) ;
if ( ! V_59 ) {
F_99 ( L_75 ) ;
V_71 = - V_122 ;
goto V_206;
}
return 0 ;
V_206:
F_156 ( V_95 ) ;
V_205:
F_157 ( & V_202 ) ;
V_203:
return V_71 ;
}
static void T_7 F_158 ( void )
{
F_156 ( V_59 ) ;
F_156 ( V_95 ) ;
F_157 ( & V_202 ) ;
}
