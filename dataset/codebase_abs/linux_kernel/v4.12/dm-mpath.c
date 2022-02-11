static struct V_1 * F_1 ( void )
{
struct V_1 * V_1 = F_2 ( sizeof( * V_1 ) , V_2 ) ;
if ( V_1 ) {
V_1 -> V_3 = true ;
F_3 ( & V_1 -> V_4 , V_5 ) ;
}
return V_1 ;
}
static void F_4 ( struct V_1 * V_1 )
{
F_5 ( V_1 ) ;
}
static struct V_6 * F_6 ( void )
{
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_2 ) ;
if ( V_7 )
F_7 ( & V_7 -> V_8 ) ;
return V_7 ;
}
static void F_8 ( struct V_9 * V_8 , struct V_10 * V_11 )
{
struct V_1 * V_1 , * V_12 ;
F_9 (pgpath, tmp, pgpaths, list) {
F_10 ( & V_1 -> V_13 ) ;
F_11 ( V_11 , V_1 -> V_14 . V_15 ) ;
F_4 ( V_1 ) ;
}
}
static void F_12 ( struct V_6 * V_7 ,
struct V_10 * V_11 )
{
struct V_16 * V_17 = & V_7 -> V_17 ;
if ( V_17 -> type ) {
V_17 -> type -> V_18 ( V_17 ) ;
F_13 ( V_17 -> type ) ;
}
F_8 ( & V_7 -> V_8 , V_11 ) ;
F_5 ( V_7 ) ;
}
static struct V_19 * F_14 ( struct V_10 * V_11 )
{
struct V_19 * V_20 ;
V_20 = F_2 ( sizeof( * V_20 ) , V_2 ) ;
if ( V_20 ) {
F_7 ( & V_20 -> V_21 ) ;
F_15 ( & V_20 -> V_22 ) ;
F_16 ( V_23 , & V_20 -> V_24 ) ;
F_17 ( & V_20 -> V_25 , 0 ) ;
F_17 ( & V_20 -> V_26 , 0 ) ;
F_17 ( & V_20 -> V_27 , 0 ) ;
V_20 -> V_28 = V_29 ;
F_18 ( & V_20 -> V_30 , V_30 ) ;
F_19 ( & V_20 -> V_31 ) ;
F_20 ( & V_20 -> V_32 ) ;
V_20 -> V_33 = V_34 ;
V_20 -> V_11 = V_11 ;
V_11 -> V_35 = V_20 ;
}
return V_20 ;
}
static int F_21 ( struct V_10 * V_11 , struct V_19 * V_20 )
{
if ( V_20 -> V_33 == V_34 ) {
if ( F_22 ( F_23 ( V_11 -> V_36 ) ) )
V_20 -> V_33 = V_37 ;
else
V_20 -> V_33 = V_38 ;
} else if ( V_20 -> V_33 == V_39 ) {
F_18 ( & V_20 -> V_40 , V_40 ) ;
F_16 ( V_41 , & V_20 -> V_24 ) ;
}
F_24 ( V_11 -> V_36 , V_20 -> V_33 ) ;
return 0 ;
}
static void F_25 ( struct V_19 * V_20 )
{
struct V_6 * V_7 , * V_12 ;
F_9 (pg, tmp, &m->priority_groups, list) {
F_10 ( & V_7 -> V_13 ) ;
F_12 ( V_7 , V_20 -> V_11 ) ;
}
F_5 ( V_20 -> V_42 ) ;
F_5 ( V_20 -> V_43 ) ;
F_5 ( V_20 ) ;
}
static struct V_44 * F_26 ( union V_45 * V_46 )
{
return V_46 -> V_47 ;
}
static T_1 F_27 ( void )
{
return sizeof( struct V_44 ) + sizeof( struct V_48 ) ;
}
static struct V_44 * F_28 ( struct V_49 * V_49 )
{
return F_29 ( V_49 , F_27 () ) ;
}
static struct V_48 * F_30 ( struct V_49 * V_49 )
{
struct V_44 * V_50 = F_28 ( V_49 ) ;
void * V_51 = V_50 + 1 ;
return V_51 ;
}
static void F_31 ( struct V_49 * V_49 , struct V_44 * * V_52 ,
struct V_48 * * V_53 )
{
struct V_44 * V_50 = F_28 ( V_49 ) ;
struct V_48 * V_51 = F_30 ( V_49 ) ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
F_32 ( V_51 , V_49 ) ;
if ( V_52 )
* V_52 = V_50 ;
if ( V_53 )
* V_53 = V_51 ;
}
static int F_33 ( struct V_19 * V_20 )
{
struct V_1 * V_1 ;
unsigned long V_54 = 0 ;
F_34 ( & V_20 -> V_22 ) ;
if ( F_35 ( & V_20 -> V_26 ) || F_36 ( V_55 , & V_20 -> V_24 ) )
return 0 ;
F_37 ( & V_20 -> V_27 ) ;
F_38 ( V_56 , & V_20 -> V_24 ) ;
if ( ! V_20 -> V_57 )
return 0 ;
if ( F_36 ( V_58 , & V_20 -> V_24 ) )
V_54 = F_39 ( V_20 -> V_28 != V_29 ?
V_20 -> V_28 : V_59 ) ;
F_40 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_41 ( V_60 , & V_1 -> V_4 ,
V_54 ) )
F_37 ( & V_20 -> V_26 ) ;
}
return F_35 ( & V_20 -> V_26 ) ;
}
static int F_42 ( struct V_19 * V_20 )
{
int V_61 ;
unsigned long V_24 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
V_61 = F_33 ( V_20 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
return V_61 ;
}
static void F_45 ( struct V_19 * V_20 , struct V_6 * V_7 )
{
V_20 -> V_57 = V_7 ;
if ( V_20 -> V_42 ) {
F_16 ( V_56 , & V_20 -> V_24 ) ;
F_16 ( V_23 , & V_20 -> V_24 ) ;
} else {
F_38 ( V_56 , & V_20 -> V_24 ) ;
F_38 ( V_23 , & V_20 -> V_24 ) ;
}
F_17 ( & V_20 -> V_27 , 0 ) ;
}
static struct V_1 * F_46 ( struct V_19 * V_20 ,
struct V_6 * V_7 ,
T_1 V_62 )
{
unsigned long V_24 ;
struct V_63 * V_14 ;
struct V_1 * V_1 ;
V_14 = V_7 -> V_17 . type -> V_64 ( & V_7 -> V_17 , V_62 ) ;
if ( ! V_14 )
return F_47 ( - V_65 ) ;
V_1 = F_48 ( V_14 ) ;
if ( F_49 ( F_50 ( V_20 -> V_57 ) != V_7 ) ) {
F_43 ( & V_20 -> V_22 , V_24 ) ;
V_20 -> V_66 = V_1 ;
F_45 ( V_20 , V_7 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
}
return V_1 ;
}
static struct V_1 * F_51 ( struct V_19 * V_20 , T_1 V_62 )
{
unsigned long V_24 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
unsigned V_67 = 1 ;
if ( ! F_35 ( & V_20 -> V_25 ) ) {
F_38 ( V_23 , & V_20 -> V_24 ) ;
goto V_68;
}
if ( F_50 ( V_20 -> V_69 ) ) {
F_43 ( & V_20 -> V_22 , V_24 ) ;
V_7 = V_20 -> V_69 ;
if ( ! V_7 ) {
F_44 ( & V_20 -> V_22 , V_24 ) ;
goto V_70;
}
V_20 -> V_69 = NULL ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
V_1 = F_46 ( V_20 , V_7 , V_62 ) ;
if ( ! F_52 ( V_1 ) )
return V_1 ;
}
V_70:
V_7 = F_50 ( V_20 -> V_57 ) ;
if ( V_7 ) {
V_1 = F_46 ( V_20 , V_7 , V_62 ) ;
if ( ! F_52 ( V_1 ) )
return V_1 ;
}
do {
F_40 (pg, &m->priority_groups, list) {
if ( V_7 -> V_67 == ! ! V_67 )
continue;
V_1 = F_46 ( V_20 , V_7 , V_62 ) ;
if ( ! F_52 ( V_1 ) ) {
if ( ! V_67 )
F_16 ( V_58 , & V_20 -> V_24 ) ;
return V_1 ;
}
}
} while ( V_67 -- );
V_68:
F_43 ( & V_20 -> V_22 , V_24 ) ;
V_20 -> V_66 = NULL ;
V_20 -> V_57 = NULL ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
return NULL ;
}
static int F_53 ( struct V_10 * V_11 , struct V_71 * V_72 ,
union V_45 * V_73 ,
struct V_71 * * V_74 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
T_1 V_62 = F_54 ( V_72 ) ;
struct V_1 * V_1 ;
struct V_75 * V_76 ;
struct V_44 * V_50 = F_26 ( V_73 ) ;
struct V_77 * V_78 ;
struct V_71 * V_79 ;
V_1 = F_50 ( V_20 -> V_66 ) ;
if ( ! V_1 || ! F_36 ( V_23 , & V_20 -> V_24 ) )
V_1 = F_51 ( V_20 , V_62 ) ;
if ( ! V_1 ) {
if ( F_36 ( V_80 , & V_20 -> V_24 ) )
return V_81 ;
F_55 ( V_20 ) ;
return V_82 ;
} else if ( F_36 ( V_23 , & V_20 -> V_24 ) ||
F_36 ( V_56 , & V_20 -> V_24 ) ) {
if ( F_42 ( V_20 ) )
return V_81 ;
return V_83 ;
}
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_1 = V_1 ;
V_50 -> V_62 = V_62 ;
V_76 = V_1 -> V_14 . V_15 -> V_76 ;
V_78 = F_56 ( V_76 ) ;
V_79 = F_57 ( V_78 , V_72 -> V_84 | V_85 , V_86 ) ;
if ( F_58 ( V_79 ) ) {
bool V_87 = F_59 ( V_78 ) ;
F_60 ( L_1 ,
F_61 ( V_79 ) , V_87 ? L_2 : L_3 ) ;
if ( V_87 ) {
F_37 ( & V_20 -> V_26 ) ;
F_62 ( V_1 ) ;
return V_83 ;
}
return V_81 ;
}
V_79 -> V_49 = V_79 -> V_88 = NULL ;
V_79 -> V_89 = V_76 -> V_90 ;
V_79 -> V_84 |= V_91 ;
* V_74 = V_79 ;
if ( V_1 -> V_7 -> V_17 . type -> V_92 )
V_1 -> V_7 -> V_17 . type -> V_92 ( & V_1 -> V_7 -> V_17 ,
& V_1 -> V_14 ,
V_62 ) ;
return V_93 ;
}
static void F_63 ( struct V_71 * V_79 )
{
F_64 ( V_79 ) ;
}
static int F_65 ( struct V_19 * V_20 , struct V_49 * V_49 , struct V_44 * V_50 )
{
T_1 V_62 = V_49 -> V_94 . V_95 ;
struct V_1 * V_1 ;
unsigned long V_24 ;
bool V_96 ;
V_1 = F_50 ( V_20 -> V_66 ) ;
V_96 = F_36 ( V_23 , & V_20 -> V_24 ) ;
if ( ! V_1 || ! V_96 )
V_1 = F_51 ( V_20 , V_62 ) ;
if ( ( V_1 && V_96 ) ||
( ! V_1 && F_36 ( V_80 , & V_20 -> V_24 ) ) ) {
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_66 ( & V_20 -> V_97 , V_49 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
if ( V_96 || F_36 ( V_56 , & V_20 -> V_24 ) )
F_42 ( V_20 ) ;
else if ( ! V_96 )
F_67 ( V_98 , & V_20 -> V_40 ) ;
return V_99 ;
}
if ( ! V_1 ) {
if ( F_36 ( V_80 , & V_20 -> V_24 ) )
return V_83 ;
F_55 ( V_20 ) ;
return - V_100 ;
}
V_50 -> V_1 = V_1 ;
V_50 -> V_62 = V_62 ;
V_49 -> V_101 = 0 ;
V_49 -> V_102 = V_1 -> V_14 . V_15 -> V_76 ;
V_49 -> V_103 |= V_91 ;
if ( V_1 -> V_7 -> V_17 . type -> V_92 )
V_1 -> V_7 -> V_17 . type -> V_92 ( & V_1 -> V_7 -> V_17 ,
& V_1 -> V_14 ,
V_62 ) ;
return V_93 ;
}
static int F_68 ( struct V_10 * V_11 , struct V_49 * V_49 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_44 * V_50 = NULL ;
F_31 ( V_49 , & V_50 , NULL ) ;
return F_65 ( V_20 , V_49 , V_50 ) ;
}
static void F_69 ( struct V_19 * V_20 )
{
if ( V_20 -> V_33 == V_37 )
F_70 ( F_23 ( V_20 -> V_11 -> V_36 ) ) ;
else if ( V_20 -> V_33 == V_39 )
F_67 ( V_98 , & V_20 -> V_40 ) ;
}
static void V_40 ( struct V_104 * V_105 )
{
int V_106 ;
unsigned long V_24 ;
struct V_49 * V_49 ;
struct V_107 V_108 ;
struct V_109 V_110 ;
struct V_19 * V_20 =
F_71 ( V_105 , struct V_19 , V_40 ) ;
F_72 ( & V_108 ) ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( F_73 ( & V_20 -> V_97 ) ) {
F_44 ( & V_20 -> V_22 , V_24 ) ;
return;
}
F_74 ( & V_108 , & V_20 -> V_97 ) ;
F_72 ( & V_20 -> V_97 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
F_75 ( & V_110 ) ;
while ( ( V_49 = F_76 ( & V_108 ) ) ) {
V_106 = F_65 ( V_20 , V_49 , F_28 ( V_49 ) ) ;
if ( V_106 < 0 || V_106 == V_83 ) {
V_49 -> V_101 = V_106 ;
F_77 ( V_49 ) ;
} else if ( V_106 == V_93 )
F_78 ( V_49 ) ;
}
F_79 ( & V_110 ) ;
}
static void F_80 ( bool V_111 , long V_112 , unsigned long * V_113 )
{
if ( V_111 )
F_16 ( V_112 , V_113 ) ;
else
F_38 ( V_112 , V_113 ) ;
}
static int F_81 ( struct V_19 * V_20 , bool F_81 ,
bool V_114 )
{
unsigned long V_24 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_80 ( ( V_114 && F_36 ( V_80 , & V_20 -> V_24 ) ) ||
( ! V_114 && F_81 ) ,
V_115 , & V_20 -> V_24 ) ;
F_80 ( F_81 || F_82 ( V_20 -> V_11 ) ,
V_80 , & V_20 -> V_24 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
if ( ! F_81 ) {
F_83 ( V_20 -> V_11 -> V_36 ) ;
F_69 ( V_20 ) ;
}
return 0 ;
}
static void V_30 ( struct V_104 * V_105 )
{
struct V_19 * V_20 =
F_71 ( V_105 , struct V_19 , V_30 ) ;
F_84 ( V_20 -> V_11 -> V_36 ) ;
}
static int F_85 ( struct V_116 * V_117 , struct V_6 * V_7 ,
struct V_10 * V_11 )
{
int V_106 ;
struct V_118 * V_119 ;
unsigned V_120 ;
static struct V_121 V_122 [] = {
{ 0 , 1024 , L_4 } ,
} ;
V_119 = F_86 ( F_87 ( V_117 ) ) ;
if ( ! V_119 ) {
V_11 -> error = L_5 ;
return - V_123 ;
}
V_106 = F_88 ( V_122 , V_117 , & V_120 , & V_11 -> error ) ;
if ( V_106 ) {
F_13 ( V_119 ) ;
return - V_123 ;
}
V_106 = V_119 -> V_124 ( & V_7 -> V_17 , V_120 , V_117 -> V_125 ) ;
if ( V_106 ) {
F_13 ( V_119 ) ;
V_11 -> error = L_6 ;
return V_106 ;
}
V_7 -> V_17 . type = V_119 ;
F_89 ( V_117 , V_120 ) ;
return 0 ;
}
static struct V_1 * F_90 ( struct V_116 * V_117 , struct V_16 * V_17 ,
struct V_10 * V_11 )
{
int V_106 ;
struct V_1 * V_126 ;
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_77 * V_78 = NULL ;
const char * V_127 ;
if ( V_117 -> V_128 < 1 ) {
V_11 -> error = L_7 ;
return F_47 ( - V_123 ) ;
}
V_126 = F_1 () ;
if ( ! V_126 )
return F_47 ( - V_129 ) ;
V_106 = F_91 ( V_11 , F_87 ( V_117 ) , F_92 ( V_11 -> V_36 ) ,
& V_126 -> V_14 . V_15 ) ;
if ( V_106 ) {
V_11 -> error = L_8 ;
goto V_130;
}
if ( F_36 ( V_41 , & V_20 -> V_24 ) || V_20 -> V_42 )
V_78 = F_56 ( V_126 -> V_14 . V_15 -> V_76 ) ;
if ( F_36 ( V_41 , & V_20 -> V_24 ) ) {
V_131:
V_127 = F_93 ( V_78 , V_2 ) ;
if ( V_127 ) {
if ( V_20 -> V_42 && strcmp ( V_127 , V_20 -> V_42 ) ) {
F_5 ( V_20 -> V_43 ) ;
V_20 -> V_43 = NULL ;
}
F_5 ( V_20 -> V_42 ) ;
V_20 -> V_42 = V_127 ;
}
}
if ( V_20 -> V_42 ) {
V_106 = F_94 ( V_78 , V_20 -> V_42 ) ;
if ( V_106 == - V_132 ) {
char V_133 [ V_134 ] ;
F_95 ( V_135 L_9 ,
F_96 ( V_126 -> V_14 . V_15 -> V_76 , V_133 ) ) ;
goto V_131;
}
if ( V_106 < 0 ) {
V_11 -> error = L_10 ;
F_11 ( V_11 , V_126 -> V_14 . V_15 ) ;
goto V_130;
}
if ( V_20 -> V_43 ) {
V_106 = F_97 ( V_78 , V_20 -> V_43 ) ;
if ( V_106 < 0 ) {
V_11 -> error = L_11
L_12 ;
F_11 ( V_11 , V_126 -> V_14 . V_15 ) ;
goto V_130;
}
}
}
V_106 = V_17 -> type -> V_136 ( V_17 , & V_126 -> V_14 , V_117 -> V_128 , V_117 -> V_125 , & V_11 -> error ) ;
if ( V_106 ) {
F_11 ( V_11 , V_126 -> V_14 . V_15 ) ;
goto V_130;
}
return V_126 ;
V_130:
F_4 ( V_126 ) ;
return F_47 ( V_106 ) ;
}
static struct V_6 * F_98 ( struct V_116 * V_117 ,
struct V_19 * V_20 )
{
static struct V_121 V_122 [] = {
{ 1 , 1024 , L_13 } ,
{ 0 , 1024 , L_14 }
} ;
int V_106 ;
unsigned V_137 , V_138 , V_139 ;
struct V_6 * V_7 ;
struct V_10 * V_11 = V_20 -> V_11 ;
if ( V_117 -> V_128 < 2 ) {
V_117 -> V_128 = 0 ;
V_11 -> error = L_15 ;
return F_47 ( - V_123 ) ;
}
V_7 = F_6 () ;
if ( ! V_7 ) {
V_11 -> error = L_16 ;
return F_47 ( - V_129 ) ;
}
V_7 -> V_20 = V_20 ;
V_106 = F_85 ( V_117 , V_7 , V_11 ) ;
if ( V_106 )
goto V_130;
V_106 = F_99 ( V_122 , V_117 , & V_7 -> V_140 , & V_11 -> error ) ;
if ( V_106 )
goto V_130;
V_106 = F_99 ( V_122 + 1 , V_117 , & V_138 , & V_11 -> error ) ;
if ( V_106 )
goto V_130;
V_139 = 1 + V_138 ;
for ( V_137 = 0 ; V_137 < V_7 -> V_140 ; V_137 ++ ) {
struct V_1 * V_1 ;
struct V_116 V_141 ;
if ( V_117 -> V_128 < V_139 ) {
V_11 -> error = L_17 ;
V_106 = - V_123 ;
goto V_130;
}
V_141 . V_128 = V_139 ;
V_141 . V_125 = V_117 -> V_125 ;
V_1 = F_90 ( & V_141 , & V_7 -> V_17 , V_11 ) ;
if ( F_58 ( V_1 ) ) {
V_106 = F_61 ( V_1 ) ;
goto V_130;
}
V_1 -> V_7 = V_7 ;
F_100 ( & V_1 -> V_13 , & V_7 -> V_8 ) ;
F_89 ( V_117 , V_139 ) ;
}
return V_7 ;
V_130:
F_12 ( V_7 , V_11 ) ;
return F_47 ( V_106 ) ;
}
static int F_101 ( struct V_116 * V_117 , struct V_19 * V_20 )
{
unsigned V_142 ;
int V_61 ;
struct V_10 * V_11 = V_20 -> V_11 ;
static struct V_121 V_122 [] = {
{ 0 , 1024 , L_18 } ,
} ;
if ( F_88 ( V_122 , V_117 , & V_142 , & V_11 -> error ) )
return - V_123 ;
if ( ! V_142 )
return 0 ;
if ( V_20 -> V_33 == V_39 ) {
F_89 ( V_117 , V_142 ) ;
F_102 ( L_19 ) ;
return 0 ;
}
V_20 -> V_42 = F_103 ( F_87 ( V_117 ) , V_2 ) ;
if ( ! V_20 -> V_42 )
return - V_123 ;
if ( V_142 > 1 ) {
char * V_126 ;
int V_137 , V_143 , V_144 = 4 ;
for ( V_137 = 0 ; V_137 <= V_142 - 2 ; V_137 ++ )
V_144 += strlen ( V_117 -> V_125 [ V_137 ] ) + 1 ;
V_126 = V_20 -> V_43 = F_2 ( V_144 , V_2 ) ;
if ( ! V_126 ) {
V_11 -> error = L_20 ;
V_61 = - V_129 ;
goto V_145;
}
V_143 = sprintf ( V_126 , L_21 , V_142 - 1 ) ;
for ( V_137 = 0 , V_126 += V_143 + 1 ; V_137 <= V_142 - 2 ; V_137 ++ , V_126 += V_143 + 1 )
V_143 = sprintf ( V_126 , L_22 , V_117 -> V_125 [ V_137 ] ) ;
}
F_89 ( V_117 , V_142 - 1 ) ;
return 0 ;
V_145:
F_5 ( V_20 -> V_42 ) ;
V_20 -> V_42 = NULL ;
return V_61 ;
}
static int F_104 ( struct V_116 * V_117 , struct V_19 * V_20 )
{
int V_106 ;
unsigned V_128 ;
struct V_10 * V_11 = V_20 -> V_11 ;
const char * V_146 ;
static struct V_121 V_122 [] = {
{ 0 , 8 , L_23 } ,
{ 1 , 50 , L_24 } ,
{ 0 , 60000 , L_25 } ,
} ;
V_106 = F_88 ( V_122 , V_117 , & V_128 , & V_11 -> error ) ;
if ( V_106 )
return - V_123 ;
if ( ! V_128 )
return 0 ;
do {
V_146 = F_87 ( V_117 ) ;
V_128 -- ;
if ( ! strcasecmp ( V_146 , L_26 ) ) {
V_106 = F_81 ( V_20 , true , false ) ;
continue;
}
if ( ! strcasecmp ( V_146 , L_27 ) ) {
F_16 ( V_41 , & V_20 -> V_24 ) ;
continue;
}
if ( ! strcasecmp ( V_146 , L_28 ) &&
( V_128 >= 1 ) ) {
V_106 = F_99 ( V_122 + 1 , V_117 , & V_20 -> V_147 , & V_11 -> error ) ;
V_128 -- ;
continue;
}
if ( ! strcasecmp ( V_146 , L_29 ) &&
( V_128 >= 1 ) ) {
V_106 = F_99 ( V_122 + 2 , V_117 , & V_20 -> V_28 , & V_11 -> error ) ;
V_128 -- ;
continue;
}
if ( ! strcasecmp ( V_146 , L_30 ) &&
( V_128 >= 1 ) ) {
const char * V_148 = F_87 ( V_117 ) ;
if ( ! strcasecmp ( V_148 , L_31 ) )
V_20 -> V_33 = V_39 ;
else if ( ! strcasecmp ( V_148 , L_32 ) )
V_20 -> V_33 = V_38 ;
else if ( ! strcasecmp ( V_148 , L_33 ) )
V_20 -> V_33 = V_37 ;
else {
V_11 -> error = L_34 ;
V_106 = - V_123 ;
}
V_128 -- ;
continue;
}
V_11 -> error = L_35 ;
V_106 = - V_123 ;
} while ( V_128 && ! V_106 );
return V_106 ;
}
static int F_105 ( struct V_10 * V_11 , unsigned V_128 , char * * V_125 )
{
static struct V_121 V_122 [] = {
{ 0 , 1024 , L_36 } ,
{ 0 , 1024 , L_37 } ,
} ;
int V_106 ;
struct V_19 * V_20 ;
struct V_116 V_117 ;
unsigned V_149 = 0 ;
unsigned V_150 ;
V_117 . V_128 = V_128 ;
V_117 . V_125 = V_125 ;
V_20 = F_14 ( V_11 ) ;
if ( ! V_20 ) {
V_11 -> error = L_38 ;
return - V_123 ;
}
V_106 = F_104 ( & V_117 , V_20 ) ;
if ( V_106 )
goto V_130;
V_106 = F_21 ( V_11 , V_20 ) ;
if ( V_106 )
goto V_130;
V_106 = F_101 ( & V_117 , V_20 ) ;
if ( V_106 )
goto V_130;
V_106 = F_99 ( V_122 , & V_117 , & V_20 -> V_151 , & V_11 -> error ) ;
if ( V_106 )
goto V_130;
V_106 = F_99 ( V_122 + 1 , & V_117 , & V_150 , & V_11 -> error ) ;
if ( V_106 )
goto V_130;
if ( ( ! V_20 -> V_151 && V_150 ) ||
( V_20 -> V_151 && ! V_150 ) ) {
V_11 -> error = L_39 ;
V_106 = - V_123 ;
goto V_130;
}
while ( V_117 . V_128 ) {
struct V_6 * V_7 ;
unsigned V_25 = F_35 ( & V_20 -> V_25 ) ;
V_7 = F_98 ( & V_117 , V_20 ) ;
if ( F_58 ( V_7 ) ) {
V_106 = F_61 ( V_7 ) ;
goto V_130;
}
V_25 += V_7 -> V_140 ;
F_17 ( & V_20 -> V_25 , V_25 ) ;
F_100 ( & V_7 -> V_13 , & V_20 -> V_21 ) ;
V_149 ++ ;
V_7 -> V_152 = V_149 ;
if ( ! -- V_150 )
V_20 -> V_69 = V_7 ;
}
if ( V_149 != V_20 -> V_151 ) {
V_11 -> error = L_40 ;
V_106 = - V_123 ;
goto V_130;
}
V_11 -> V_153 = 1 ;
V_11 -> V_154 = 1 ;
V_11 -> V_155 = 1 ;
V_11 -> V_156 = 1 ;
if ( V_20 -> V_33 == V_39 )
V_11 -> V_157 = F_27 () ;
else
V_11 -> V_157 = sizeof( struct V_44 ) ;
return 0 ;
V_130:
F_25 ( V_20 ) ;
return V_106 ;
}
static void F_106 ( struct V_19 * V_20 )
{
F_107 ( V_158 ) ;
while ( 1 ) {
F_108 ( & V_20 -> V_31 , & V_158 , V_159 ) ;
if ( ! F_35 ( & V_20 -> V_26 ) )
break;
F_109 () ;
}
F_110 ( & V_20 -> V_31 , & V_158 ) ;
}
static void F_111 ( struct V_19 * V_20 )
{
F_16 ( V_55 , & V_20 -> V_24 ) ;
F_112 () ;
F_113 ( V_60 ) ;
F_106 ( V_20 ) ;
F_113 ( V_98 ) ;
F_114 ( & V_20 -> V_30 ) ;
F_38 ( V_55 , & V_20 -> V_24 ) ;
F_112 () ;
}
static void F_115 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
F_111 ( V_20 ) ;
F_25 ( V_20 ) ;
}
static int F_116 ( struct V_1 * V_1 )
{
unsigned long V_24 ;
struct V_19 * V_20 = V_1 -> V_7 -> V_20 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( ! V_1 -> V_3 )
goto V_160;
F_117 ( L_41 , V_1 -> V_14 . V_15 -> V_161 ) ;
V_1 -> V_7 -> V_17 . type -> F_116 ( & V_1 -> V_7 -> V_17 , & V_1 -> V_14 ) ;
V_1 -> V_3 = false ;
V_1 -> V_162 ++ ;
F_118 ( & V_20 -> V_25 ) ;
if ( V_1 == V_20 -> V_66 )
V_20 -> V_66 = NULL ;
F_119 ( V_163 , V_20 -> V_11 ,
V_1 -> V_14 . V_15 -> V_161 , F_35 ( & V_20 -> V_25 ) ) ;
F_120 ( & V_20 -> V_30 ) ;
V_160:
F_44 ( & V_20 -> V_22 , V_24 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_1 )
{
int V_106 = 0 , V_164 = 0 ;
unsigned long V_24 ;
struct V_19 * V_20 = V_1 -> V_7 -> V_20 ;
unsigned V_25 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( V_1 -> V_3 )
goto V_160;
F_117 ( L_42 , V_1 -> V_14 . V_15 -> V_161 ) ;
V_106 = V_1 -> V_7 -> V_17 . type -> F_121 ( & V_1 -> V_7 -> V_17 , & V_1 -> V_14 ) ;
if ( V_106 )
goto V_160;
V_1 -> V_3 = true ;
V_25 = F_122 ( & V_20 -> V_25 ) ;
if ( V_25 == 1 ) {
V_20 -> V_66 = NULL ;
V_164 = 1 ;
} else if ( V_20 -> V_42 && ( V_20 -> V_57 == V_1 -> V_7 ) ) {
if ( F_67 ( V_60 , & V_1 -> V_4 . V_105 ) )
F_37 ( & V_20 -> V_26 ) ;
}
F_119 ( V_165 , V_20 -> V_11 ,
V_1 -> V_14 . V_15 -> V_161 , V_25 ) ;
F_120 ( & V_20 -> V_30 ) ;
V_160:
F_44 ( & V_20 -> V_22 , V_24 ) ;
if ( V_164 ) {
F_83 ( V_20 -> V_11 -> V_36 ) ;
F_69 ( V_20 ) ;
}
return V_106 ;
}
static int F_123 ( struct V_19 * V_20 , struct V_166 * V_15 ,
T_2 V_167 )
{
int V_106 = - V_123 ;
struct V_1 * V_1 ;
struct V_6 * V_7 ;
F_40 (pg, &m->priority_groups, list) {
F_40 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_14 . V_15 == V_15 )
V_106 = V_167 ( V_1 ) ;
}
}
return V_106 ;
}
static void F_124 ( struct V_19 * V_20 , struct V_6 * V_7 ,
bool V_67 )
{
unsigned long V_24 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
V_7 -> V_67 = V_67 ;
V_20 -> V_66 = NULL ;
V_20 -> V_57 = NULL ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
F_120 ( & V_20 -> V_30 ) ;
}
static int F_125 ( struct V_19 * V_20 , const char * V_168 )
{
struct V_6 * V_7 ;
unsigned V_169 ;
unsigned long V_24 ;
char V_170 ;
if ( ! V_168 || ( sscanf ( V_168 , L_43 , & V_169 , & V_170 ) != 1 ) || ! V_169 ||
! V_20 -> V_151 || ( V_169 > V_20 -> V_151 ) ) {
F_117 ( L_44 ) ;
return - V_123 ;
}
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_40 (pg, &m->priority_groups, list) {
V_7 -> V_67 = false ;
if ( -- V_169 )
continue;
V_20 -> V_66 = NULL ;
V_20 -> V_57 = NULL ;
V_20 -> V_69 = V_7 ;
}
F_44 ( & V_20 -> V_22 , V_24 ) ;
F_120 ( & V_20 -> V_30 ) ;
return 0 ;
}
static int F_126 ( struct V_19 * V_20 , const char * V_168 , bool V_67 )
{
struct V_6 * V_7 ;
unsigned V_169 ;
char V_170 ;
if ( ! V_168 || ( sscanf ( V_168 , L_43 , & V_169 , & V_170 ) != 1 ) || ! V_169 ||
! V_20 -> V_151 || ( V_169 > V_20 -> V_151 ) ) {
F_117 ( L_45 ) ;
return - V_123 ;
}
F_40 (pg, &m->priority_groups, list) {
if ( ! -- V_169 )
break;
}
F_124 ( V_20 , V_7 , V_67 ) ;
return 0 ;
}
static bool F_127 ( struct V_19 * V_20 , struct V_1 * V_1 )
{
unsigned long V_24 ;
bool V_171 = false ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( F_35 ( & V_20 -> V_27 ) <= V_20 -> V_147 &&
! F_36 ( V_55 , & V_20 -> V_24 ) )
F_16 ( V_56 , & V_20 -> V_24 ) ;
else
V_171 = true ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
return V_171 ;
}
static void F_128 ( void * V_172 , int V_173 )
{
struct V_1 * V_1 = V_172 ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_19 * V_20 = V_7 -> V_20 ;
unsigned long V_24 ;
bool V_174 = false ;
switch ( V_173 ) {
case V_175 :
break;
case V_176 :
if ( ! V_20 -> V_42 ) {
V_173 = 0 ;
break;
}
F_102 ( L_46
L_47 , V_20 -> V_42 , V_173 ) ;
F_116 ( V_1 ) ;
break;
case V_177 :
F_124 ( V_20 , V_7 , true ) ;
break;
case V_178 :
V_174 = 1 ;
case V_179 :
case V_180 :
if ( F_127 ( V_20 , V_1 ) )
F_116 ( V_1 ) ;
V_173 = 0 ;
break;
case V_181 :
default:
F_116 ( V_1 ) ;
}
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( V_173 ) {
if ( V_1 == V_20 -> V_66 ) {
F_102 ( L_48 , V_173 ) ;
V_20 -> V_66 = NULL ;
V_20 -> V_57 = NULL ;
}
} else if ( ! F_36 ( V_56 , & V_20 -> V_24 ) )
V_7 -> V_67 = false ;
if ( F_129 ( & V_20 -> V_26 ) > 0 )
goto V_160;
if ( F_36 ( V_56 , & V_20 -> V_24 ) ) {
if ( V_174 )
F_16 ( V_58 , & V_20 -> V_24 ) ;
else
F_38 ( V_58 , & V_20 -> V_24 ) ;
if ( F_33 ( V_20 ) )
goto V_160;
}
F_38 ( V_23 , & V_20 -> V_24 ) ;
F_69 ( V_20 ) ;
F_130 ( & V_20 -> V_31 ) ;
V_160:
F_44 ( & V_20 -> V_22 , V_24 ) ;
}
static void F_62 ( struct V_1 * V_1 )
{
struct V_77 * V_78 = F_56 ( V_1 -> V_14 . V_15 -> V_76 ) ;
if ( V_1 -> V_3 && ! F_59 ( V_78 ) )
F_131 ( V_78 , F_128 , V_1 ) ;
else
F_128 ( V_1 , V_181 ) ;
}
static void V_5 ( struct V_104 * V_105 )
{
struct V_1 * V_1 =
F_71 ( V_105 , struct V_1 , V_4 . V_105 ) ;
F_62 ( V_1 ) ;
}
static int F_132 ( int error )
{
switch ( error ) {
case - V_182 :
case - V_183 :
case - V_184 :
case - V_185 :
case - V_186 :
case - V_187 :
return 1 ;
}
return 0 ;
}
static int F_133 ( struct V_10 * V_11 , struct V_71 * V_79 ,
int error , union V_45 * V_73 )
{
struct V_44 * V_50 = F_26 ( V_73 ) ;
struct V_1 * V_1 = V_50 -> V_1 ;
int V_106 = V_188 ;
if ( error && ! F_132 ( error ) ) {
struct V_19 * V_20 = V_11 -> V_35 ;
V_106 = V_189 ;
if ( V_1 )
F_116 ( V_1 ) ;
if ( F_35 ( & V_20 -> V_25 ) == 0 &&
! F_36 ( V_80 , & V_20 -> V_24 ) ) {
if ( error == - V_100 )
F_55 ( V_20 ) ;
V_106 = V_188 ;
}
}
if ( V_1 ) {
struct V_16 * V_17 = & V_1 -> V_7 -> V_17 ;
if ( V_17 -> type -> V_190 )
V_17 -> type -> V_190 ( V_17 , & V_1 -> V_14 , V_50 -> V_62 ) ;
}
return V_106 ;
}
static int F_134 ( struct V_19 * V_20 , struct V_49 * V_79 ,
int error , struct V_44 * V_50 )
{
unsigned long V_24 ;
if ( ! error )
return 0 ;
if ( F_132 ( error ) )
return error ;
if ( V_50 -> V_1 )
F_116 ( V_50 -> V_1 ) ;
if ( F_35 ( & V_20 -> V_25 ) == 0 &&
! F_36 ( V_80 , & V_20 -> V_24 ) ) {
F_55 ( V_20 ) ;
return - V_100 ;
}
F_135 ( F_30 ( V_79 ) , V_79 ) ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_66 ( & V_20 -> V_97 , V_79 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
if ( ! F_36 ( V_23 , & V_20 -> V_24 ) )
F_67 ( V_98 , & V_20 -> V_40 ) ;
return V_191 ;
}
static int F_136 ( struct V_10 * V_11 , struct V_49 * V_79 , int error )
{
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_44 * V_50 = F_28 ( V_79 ) ;
struct V_1 * V_1 ;
struct V_16 * V_17 ;
int V_106 ;
F_137 ( ! V_50 ) ;
V_106 = F_134 ( V_20 , V_79 , error , V_50 ) ;
V_1 = V_50 -> V_1 ;
if ( V_1 ) {
V_17 = & V_1 -> V_7 -> V_17 ;
if ( V_17 -> type -> V_190 )
V_17 -> type -> V_190 ( V_17 , & V_1 -> V_14 , V_50 -> V_62 ) ;
}
return V_106 ;
}
static void F_138 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
F_81 ( V_20 , false , true ) ;
}
static void F_139 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
F_140 ( & V_20 -> V_32 ) ;
F_111 ( V_20 ) ;
F_141 ( & V_20 -> V_32 ) ;
}
static void F_142 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
unsigned long V_24 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_80 ( F_36 ( V_115 , & V_20 -> V_24 ) ,
V_80 , & V_20 -> V_24 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
}
static void F_143 ( struct V_10 * V_11 , T_3 type ,
unsigned V_192 , char * V_193 , unsigned V_194 )
{
int V_195 = 0 ;
unsigned long V_24 ;
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_6 * V_7 ;
struct V_1 * V_126 ;
unsigned V_152 ;
char V_196 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( type == V_197 )
F_144 ( L_49 , F_36 ( V_23 , & V_20 -> V_24 ) ,
F_35 ( & V_20 -> V_27 ) ) ;
else {
F_144 ( L_50 , F_36 ( V_80 , & V_20 -> V_24 ) +
( V_20 -> V_147 > 0 ) * 2 +
( V_20 -> V_28 != V_29 ) * 2 +
F_36 ( V_41 , & V_20 -> V_24 ) +
( V_20 -> V_33 != V_38 ) * 2 ) ;
if ( F_36 ( V_80 , & V_20 -> V_24 ) )
F_144 ( L_51 ) ;
if ( V_20 -> V_147 )
F_144 ( L_52 , V_20 -> V_147 ) ;
if ( V_20 -> V_28 != V_29 )
F_144 ( L_53 , V_20 -> V_28 ) ;
if ( F_36 ( V_41 , & V_20 -> V_24 ) )
F_144 ( L_54 ) ;
if ( V_20 -> V_33 != V_38 ) {
switch( V_20 -> V_33 ) {
case V_39 :
F_144 ( L_55 ) ;
break;
case V_37 :
F_144 ( L_56 ) ;
break;
default:
F_145 ( true ) ;
break;
}
}
}
if ( ! V_20 -> V_42 || type == V_197 )
F_144 ( L_57 ) ;
else
F_144 ( L_58 , V_20 -> V_42 ) ;
F_144 ( L_50 , V_20 -> V_151 ) ;
if ( V_20 -> V_69 )
V_152 = V_20 -> V_69 -> V_152 ;
else if ( V_20 -> V_57 )
V_152 = V_20 -> V_57 -> V_152 ;
else
V_152 = ( V_20 -> V_151 ? 1 : 0 ) ;
F_144 ( L_50 , V_152 ) ;
switch ( type ) {
case V_197 :
F_40 (pg, &m->priority_groups, list) {
if ( V_7 -> V_67 )
V_196 = 'D' ;
else if ( V_7 == V_20 -> V_57 )
V_196 = 'A' ;
else
V_196 = 'E' ;
F_144 ( L_59 , V_196 ) ;
if ( V_7 -> V_17 . type -> V_198 )
V_195 += V_7 -> V_17 . type -> V_198 ( & V_7 -> V_17 , NULL , type ,
V_193 + V_195 ,
V_194 - V_195 ) ;
else
F_144 ( L_57 ) ;
F_144 ( L_60 , V_7 -> V_140 ,
V_7 -> V_17 . type -> V_199 ) ;
F_40 (p, &pg->pgpaths, list) {
F_144 ( L_61 , V_126 -> V_14 . V_15 -> V_161 ,
V_126 -> V_3 ? L_62 : L_63 ,
V_126 -> V_162 ) ;
if ( V_7 -> V_17 . type -> V_198 )
V_195 += V_7 -> V_17 . type -> V_198 ( & V_7 -> V_17 ,
& V_126 -> V_14 , type , V_193 + V_195 ,
V_194 - V_195 ) ;
}
}
break;
case V_200 :
F_40 (pg, &m->priority_groups, list) {
F_144 ( L_64 , V_7 -> V_17 . type -> V_161 ) ;
if ( V_7 -> V_17 . type -> V_198 )
V_195 += V_7 -> V_17 . type -> V_198 ( & V_7 -> V_17 , NULL , type ,
V_193 + V_195 ,
V_194 - V_195 ) ;
else
F_144 ( L_57 ) ;
F_144 ( L_60 , V_7 -> V_140 ,
V_7 -> V_17 . type -> V_201 ) ;
F_40 (p, &pg->pgpaths, list) {
F_144 ( L_64 , V_126 -> V_14 . V_15 -> V_161 ) ;
if ( V_7 -> V_17 . type -> V_198 )
V_195 += V_7 -> V_17 . type -> V_198 ( & V_7 -> V_17 ,
& V_126 -> V_14 , type , V_193 + V_195 ,
V_194 - V_195 ) ;
}
}
break;
}
F_44 ( & V_20 -> V_22 , V_24 ) ;
}
static int F_146 ( struct V_10 * V_11 , unsigned V_128 , char * * V_125 )
{
int V_106 = - V_123 ;
struct V_166 * V_15 ;
struct V_19 * V_20 = V_11 -> V_35 ;
T_2 V_167 ;
F_140 ( & V_20 -> V_32 ) ;
if ( F_147 ( V_11 ) ) {
V_106 = - V_132 ;
goto V_160;
}
if ( V_128 == 1 ) {
if ( ! strcasecmp ( V_125 [ 0 ] , L_26 ) ) {
V_106 = F_81 ( V_20 , true , false ) ;
goto V_160;
} else if ( ! strcasecmp ( V_125 [ 0 ] , L_65 ) ) {
V_106 = F_81 ( V_20 , false , false ) ;
goto V_160;
}
}
if ( V_128 != 2 ) {
F_117 ( L_66 , V_128 ) ;
goto V_160;
}
if ( ! strcasecmp ( V_125 [ 0 ] , L_67 ) ) {
V_106 = F_126 ( V_20 , V_125 [ 1 ] , true ) ;
goto V_160;
} else if ( ! strcasecmp ( V_125 [ 0 ] , L_68 ) ) {
V_106 = F_126 ( V_20 , V_125 [ 1 ] , false ) ;
goto V_160;
} else if ( ! strcasecmp ( V_125 [ 0 ] , L_69 ) ) {
V_106 = F_125 ( V_20 , V_125 [ 1 ] ) ;
goto V_160;
} else if ( ! strcasecmp ( V_125 [ 0 ] , L_70 ) )
V_167 = F_121 ;
else if ( ! strcasecmp ( V_125 [ 0 ] , L_71 ) )
V_167 = F_116 ;
else {
F_117 ( L_72 , V_125 [ 0 ] ) ;
goto V_160;
}
V_106 = F_91 ( V_11 , V_125 [ 1 ] , F_92 ( V_11 -> V_36 ) , & V_15 ) ;
if ( V_106 ) {
F_117 ( L_73 ,
V_125 [ 1 ] ) ;
goto V_160;
}
V_106 = F_123 ( V_20 , V_15 , V_167 ) ;
F_11 ( V_11 , V_15 ) ;
V_160:
F_141 ( & V_20 -> V_32 ) ;
return V_106 ;
}
static int F_148 ( struct V_10 * V_11 ,
struct V_75 * * V_76 , T_4 * V_202 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_1 * V_66 ;
int V_106 ;
V_66 = F_50 ( V_20 -> V_66 ) ;
if ( ! V_66 )
V_66 = F_51 ( V_20 , 0 ) ;
if ( V_66 ) {
if ( ! F_36 ( V_23 , & V_20 -> V_24 ) ) {
* V_76 = V_66 -> V_14 . V_15 -> V_76 ;
* V_202 = V_66 -> V_14 . V_15 -> V_202 ;
V_106 = 0 ;
} else {
V_106 = - V_203 ;
}
} else {
if ( F_36 ( V_80 , & V_20 -> V_24 ) )
V_106 = - V_203 ;
else
V_106 = - V_100 ;
}
if ( V_106 == - V_203 ) {
if ( ! F_50 ( V_20 -> V_57 ) ) {
( void ) F_51 ( V_20 , 0 ) ;
}
if ( F_36 ( V_56 , & V_20 -> V_24 ) )
F_42 ( V_20 ) ;
F_83 ( V_20 -> V_11 -> V_36 ) ;
F_69 ( V_20 ) ;
}
if ( ! V_106 && V_11 -> V_144 != F_149 ( ( * V_76 ) -> V_204 ) >> V_205 )
return 1 ;
return V_106 ;
}
static int F_150 ( struct V_10 * V_11 ,
T_5 V_206 , void * V_172 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_6 * V_7 ;
struct V_1 * V_126 ;
int V_61 = 0 ;
F_40 (pg, &m->priority_groups, list) {
F_40 (p, &pg->pgpaths, list) {
V_61 = V_206 ( V_11 , V_126 -> V_14 . V_15 , V_11 -> V_207 , V_11 -> V_144 , V_172 ) ;
if ( V_61 )
goto V_160;
}
}
V_160:
return V_61 ;
}
static int F_151 ( struct V_1 * V_1 )
{
struct V_77 * V_78 = F_56 ( V_1 -> V_14 . V_15 -> V_76 ) ;
return F_152 ( V_78 ) ;
}
static int F_153 ( struct V_10 * V_11 )
{
bool V_208 = false , V_209 = false ;
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_6 * V_7 , * V_69 ;
struct V_1 * V_1 ;
if ( F_35 ( & V_20 -> V_26 ) )
return true ;
if ( ! F_35 ( & V_20 -> V_25 ) && F_36 ( V_80 , & V_20 -> V_24 ) )
return ( V_20 -> V_33 != V_37 ) ;
V_7 = F_50 ( V_20 -> V_57 ) ;
V_69 = F_50 ( V_20 -> V_69 ) ;
if ( F_49 ( ! F_50 ( V_20 -> V_66 ) && V_69 ) )
V_7 = V_69 ;
if ( ! V_7 ) {
return V_208 ;
}
V_208 = true ;
F_40 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_3 ) {
V_209 = true ;
if ( ! F_151 ( V_1 ) ) {
V_208 = false ;
break;
}
}
}
if ( ! V_209 ) {
V_208 = false ;
}
return V_208 ;
}
static int T_6 F_154 ( void )
{
int V_106 ;
V_106 = F_155 ( & V_210 ) ;
if ( V_106 < 0 ) {
F_102 ( L_74 , V_106 ) ;
V_106 = - V_123 ;
goto V_211;
}
V_98 = F_156 ( L_75 , V_212 , 0 ) ;
if ( ! V_98 ) {
F_102 ( L_76 ) ;
V_106 = - V_129 ;
goto V_213;
}
V_60 = F_157 ( L_77 ,
V_212 ) ;
if ( ! V_60 ) {
F_102 ( L_78 ) ;
V_106 = - V_129 ;
goto V_214;
}
return 0 ;
V_214:
F_158 ( V_98 ) ;
V_213:
F_159 ( & V_210 ) ;
V_211:
return V_106 ;
}
static void T_7 F_160 ( void )
{
F_158 ( V_60 ) ;
F_158 ( V_98 ) ;
F_159 ( & V_210 ) ;
}
