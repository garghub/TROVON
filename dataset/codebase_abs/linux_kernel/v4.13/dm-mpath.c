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
return V_82 ;
}
V_50 -> V_1 = V_1 ;
V_50 -> V_62 = V_62 ;
V_49 -> V_100 = 0 ;
V_49 -> V_101 = V_1 -> V_14 . V_15 -> V_76 ;
V_49 -> V_102 |= V_91 ;
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
static void V_40 ( struct V_103 * V_104 )
{
int V_105 ;
unsigned long V_24 ;
struct V_49 * V_49 ;
struct V_106 V_107 ;
struct V_108 V_109 ;
struct V_19 * V_20 =
F_71 ( V_104 , struct V_19 , V_40 ) ;
F_72 ( & V_107 ) ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( F_73 ( & V_20 -> V_97 ) ) {
F_44 ( & V_20 -> V_22 , V_24 ) ;
return;
}
F_74 ( & V_107 , & V_20 -> V_97 ) ;
F_72 ( & V_20 -> V_97 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
F_75 ( & V_109 ) ;
while ( ( V_49 = F_76 ( & V_107 ) ) ) {
V_105 = F_65 ( V_20 , V_49 , F_28 ( V_49 ) ) ;
switch ( V_105 ) {
case V_82 :
V_49 -> V_100 = V_110 ;
F_77 ( V_49 ) ;
break;
case V_83 :
V_49 -> V_100 = V_111 ;
F_77 ( V_49 ) ;
break;
case V_93 :
F_78 ( V_49 ) ;
break;
}
}
F_79 ( & V_109 ) ;
}
static void F_80 ( bool V_112 , long V_113 , unsigned long * V_114 )
{
if ( V_112 )
F_16 ( V_113 , V_114 ) ;
else
F_38 ( V_113 , V_114 ) ;
}
static int F_81 ( struct V_19 * V_20 , bool F_81 ,
bool V_115 )
{
unsigned long V_24 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_80 ( ( V_115 && F_36 ( V_80 , & V_20 -> V_24 ) ) ||
( ! V_115 && F_81 ) ,
V_116 , & V_20 -> V_24 ) ;
F_80 ( F_81 || F_82 ( V_20 -> V_11 ) ,
V_80 , & V_20 -> V_24 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
if ( ! F_81 ) {
F_83 ( V_20 -> V_11 -> V_36 ) ;
F_69 ( V_20 ) ;
}
return 0 ;
}
static void V_30 ( struct V_103 * V_104 )
{
struct V_19 * V_20 =
F_71 ( V_104 , struct V_19 , V_30 ) ;
F_84 ( V_20 -> V_11 -> V_36 ) ;
}
static int F_85 ( struct V_117 * V_118 , struct V_6 * V_7 ,
struct V_10 * V_11 )
{
int V_105 ;
struct V_119 * V_120 ;
unsigned V_121 ;
static struct V_122 V_123 [] = {
{ 0 , 1024 , L_4 } ,
} ;
V_120 = F_86 ( F_87 ( V_118 ) ) ;
if ( ! V_120 ) {
V_11 -> error = L_5 ;
return - V_124 ;
}
V_105 = F_88 ( V_123 , V_118 , & V_121 , & V_11 -> error ) ;
if ( V_105 ) {
F_13 ( V_120 ) ;
return - V_124 ;
}
V_105 = V_120 -> V_125 ( & V_7 -> V_17 , V_121 , V_118 -> V_126 ) ;
if ( V_105 ) {
F_13 ( V_120 ) ;
V_11 -> error = L_6 ;
return V_105 ;
}
V_7 -> V_17 . type = V_120 ;
F_89 ( V_118 , V_121 ) ;
return 0 ;
}
static struct V_1 * F_90 ( struct V_117 * V_118 , struct V_16 * V_17 ,
struct V_10 * V_11 )
{
int V_105 ;
struct V_1 * V_127 ;
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_77 * V_78 = NULL ;
const char * V_128 ;
if ( V_118 -> V_129 < 1 ) {
V_11 -> error = L_7 ;
return F_47 ( - V_124 ) ;
}
V_127 = F_1 () ;
if ( ! V_127 )
return F_47 ( - V_130 ) ;
V_105 = F_91 ( V_11 , F_87 ( V_118 ) , F_92 ( V_11 -> V_36 ) ,
& V_127 -> V_14 . V_15 ) ;
if ( V_105 ) {
V_11 -> error = L_8 ;
goto V_131;
}
if ( F_36 ( V_41 , & V_20 -> V_24 ) || V_20 -> V_42 )
V_78 = F_56 ( V_127 -> V_14 . V_15 -> V_76 ) ;
if ( F_36 ( V_41 , & V_20 -> V_24 ) ) {
V_132:
V_128 = F_93 ( V_78 , V_2 ) ;
if ( V_128 ) {
if ( V_20 -> V_42 && strcmp ( V_128 , V_20 -> V_42 ) ) {
F_5 ( V_20 -> V_43 ) ;
V_20 -> V_43 = NULL ;
}
F_5 ( V_20 -> V_42 ) ;
V_20 -> V_42 = V_128 ;
}
}
if ( V_20 -> V_42 ) {
V_105 = F_94 ( V_78 , V_20 -> V_42 ) ;
if ( V_105 == - V_133 ) {
char V_134 [ V_135 ] ;
F_95 ( V_136 L_9 ,
F_96 ( V_127 -> V_14 . V_15 -> V_76 , V_134 ) ) ;
goto V_132;
}
if ( V_105 < 0 ) {
V_11 -> error = L_10 ;
F_11 ( V_11 , V_127 -> V_14 . V_15 ) ;
goto V_131;
}
if ( V_20 -> V_43 ) {
V_105 = F_97 ( V_78 , V_20 -> V_43 ) ;
if ( V_105 < 0 ) {
V_11 -> error = L_11
L_12 ;
F_11 ( V_11 , V_127 -> V_14 . V_15 ) ;
goto V_131;
}
}
}
V_105 = V_17 -> type -> V_137 ( V_17 , & V_127 -> V_14 , V_118 -> V_129 , V_118 -> V_126 , & V_11 -> error ) ;
if ( V_105 ) {
F_11 ( V_11 , V_127 -> V_14 . V_15 ) ;
goto V_131;
}
return V_127 ;
V_131:
F_4 ( V_127 ) ;
return F_47 ( V_105 ) ;
}
static struct V_6 * F_98 ( struct V_117 * V_118 ,
struct V_19 * V_20 )
{
static struct V_122 V_123 [] = {
{ 1 , 1024 , L_13 } ,
{ 0 , 1024 , L_14 }
} ;
int V_105 ;
unsigned V_138 , V_139 , V_140 ;
struct V_6 * V_7 ;
struct V_10 * V_11 = V_20 -> V_11 ;
if ( V_118 -> V_129 < 2 ) {
V_118 -> V_129 = 0 ;
V_11 -> error = L_15 ;
return F_47 ( - V_124 ) ;
}
V_7 = F_6 () ;
if ( ! V_7 ) {
V_11 -> error = L_16 ;
return F_47 ( - V_130 ) ;
}
V_7 -> V_20 = V_20 ;
V_105 = F_85 ( V_118 , V_7 , V_11 ) ;
if ( V_105 )
goto V_131;
V_105 = F_99 ( V_123 , V_118 , & V_7 -> V_141 , & V_11 -> error ) ;
if ( V_105 )
goto V_131;
V_105 = F_99 ( V_123 + 1 , V_118 , & V_139 , & V_11 -> error ) ;
if ( V_105 )
goto V_131;
V_140 = 1 + V_139 ;
for ( V_138 = 0 ; V_138 < V_7 -> V_141 ; V_138 ++ ) {
struct V_1 * V_1 ;
struct V_117 V_142 ;
if ( V_118 -> V_129 < V_140 ) {
V_11 -> error = L_17 ;
V_105 = - V_124 ;
goto V_131;
}
V_142 . V_129 = V_140 ;
V_142 . V_126 = V_118 -> V_126 ;
V_1 = F_90 ( & V_142 , & V_7 -> V_17 , V_11 ) ;
if ( F_58 ( V_1 ) ) {
V_105 = F_61 ( V_1 ) ;
goto V_131;
}
V_1 -> V_7 = V_7 ;
F_100 ( & V_1 -> V_13 , & V_7 -> V_8 ) ;
F_89 ( V_118 , V_140 ) ;
}
return V_7 ;
V_131:
F_12 ( V_7 , V_11 ) ;
return F_47 ( V_105 ) ;
}
static int F_101 ( struct V_117 * V_118 , struct V_19 * V_20 )
{
unsigned V_143 ;
int V_61 ;
struct V_10 * V_11 = V_20 -> V_11 ;
static struct V_122 V_123 [] = {
{ 0 , 1024 , L_18 } ,
} ;
if ( F_88 ( V_123 , V_118 , & V_143 , & V_11 -> error ) )
return - V_124 ;
if ( ! V_143 )
return 0 ;
if ( V_20 -> V_33 == V_39 ) {
F_89 ( V_118 , V_143 ) ;
F_102 ( L_19 ) ;
return 0 ;
}
V_20 -> V_42 = F_103 ( F_87 ( V_118 ) , V_2 ) ;
if ( ! V_20 -> V_42 )
return - V_124 ;
if ( V_143 > 1 ) {
char * V_127 ;
int V_138 , V_144 , V_145 = 4 ;
for ( V_138 = 0 ; V_138 <= V_143 - 2 ; V_138 ++ )
V_145 += strlen ( V_118 -> V_126 [ V_138 ] ) + 1 ;
V_127 = V_20 -> V_43 = F_2 ( V_145 , V_2 ) ;
if ( ! V_127 ) {
V_11 -> error = L_20 ;
V_61 = - V_130 ;
goto V_146;
}
V_144 = sprintf ( V_127 , L_21 , V_143 - 1 ) ;
for ( V_138 = 0 , V_127 += V_144 + 1 ; V_138 <= V_143 - 2 ; V_138 ++ , V_127 += V_144 + 1 )
V_144 = sprintf ( V_127 , L_22 , V_118 -> V_126 [ V_138 ] ) ;
}
F_89 ( V_118 , V_143 - 1 ) ;
return 0 ;
V_146:
F_5 ( V_20 -> V_42 ) ;
V_20 -> V_42 = NULL ;
return V_61 ;
}
static int F_104 ( struct V_117 * V_118 , struct V_19 * V_20 )
{
int V_105 ;
unsigned V_129 ;
struct V_10 * V_11 = V_20 -> V_11 ;
const char * V_147 ;
static struct V_122 V_123 [] = {
{ 0 , 8 , L_23 } ,
{ 1 , 50 , L_24 } ,
{ 0 , 60000 , L_25 } ,
} ;
V_105 = F_88 ( V_123 , V_118 , & V_129 , & V_11 -> error ) ;
if ( V_105 )
return - V_124 ;
if ( ! V_129 )
return 0 ;
do {
V_147 = F_87 ( V_118 ) ;
V_129 -- ;
if ( ! strcasecmp ( V_147 , L_26 ) ) {
V_105 = F_81 ( V_20 , true , false ) ;
continue;
}
if ( ! strcasecmp ( V_147 , L_27 ) ) {
F_16 ( V_41 , & V_20 -> V_24 ) ;
continue;
}
if ( ! strcasecmp ( V_147 , L_28 ) &&
( V_129 >= 1 ) ) {
V_105 = F_99 ( V_123 + 1 , V_118 , & V_20 -> V_148 , & V_11 -> error ) ;
V_129 -- ;
continue;
}
if ( ! strcasecmp ( V_147 , L_29 ) &&
( V_129 >= 1 ) ) {
V_105 = F_99 ( V_123 + 2 , V_118 , & V_20 -> V_28 , & V_11 -> error ) ;
V_129 -- ;
continue;
}
if ( ! strcasecmp ( V_147 , L_30 ) &&
( V_129 >= 1 ) ) {
const char * V_149 = F_87 ( V_118 ) ;
if ( ! strcasecmp ( V_149 , L_31 ) )
V_20 -> V_33 = V_39 ;
else if ( ! strcasecmp ( V_149 , L_32 ) )
V_20 -> V_33 = V_38 ;
else if ( ! strcasecmp ( V_149 , L_33 ) )
V_20 -> V_33 = V_37 ;
else {
V_11 -> error = L_34 ;
V_105 = - V_124 ;
}
V_129 -- ;
continue;
}
V_11 -> error = L_35 ;
V_105 = - V_124 ;
} while ( V_129 && ! V_105 );
return V_105 ;
}
static int F_105 ( struct V_10 * V_11 , unsigned V_129 , char * * V_126 )
{
static struct V_122 V_123 [] = {
{ 0 , 1024 , L_36 } ,
{ 0 , 1024 , L_37 } ,
} ;
int V_105 ;
struct V_19 * V_20 ;
struct V_117 V_118 ;
unsigned V_150 = 0 ;
unsigned V_151 ;
V_118 . V_129 = V_129 ;
V_118 . V_126 = V_126 ;
V_20 = F_14 ( V_11 ) ;
if ( ! V_20 ) {
V_11 -> error = L_38 ;
return - V_124 ;
}
V_105 = F_104 ( & V_118 , V_20 ) ;
if ( V_105 )
goto V_131;
V_105 = F_21 ( V_11 , V_20 ) ;
if ( V_105 )
goto V_131;
V_105 = F_101 ( & V_118 , V_20 ) ;
if ( V_105 )
goto V_131;
V_105 = F_99 ( V_123 , & V_118 , & V_20 -> V_152 , & V_11 -> error ) ;
if ( V_105 )
goto V_131;
V_105 = F_99 ( V_123 + 1 , & V_118 , & V_151 , & V_11 -> error ) ;
if ( V_105 )
goto V_131;
if ( ( ! V_20 -> V_152 && V_151 ) ||
( V_20 -> V_152 && ! V_151 ) ) {
V_11 -> error = L_39 ;
V_105 = - V_124 ;
goto V_131;
}
while ( V_118 . V_129 ) {
struct V_6 * V_7 ;
unsigned V_25 = F_35 ( & V_20 -> V_25 ) ;
V_7 = F_98 ( & V_118 , V_20 ) ;
if ( F_58 ( V_7 ) ) {
V_105 = F_61 ( V_7 ) ;
goto V_131;
}
V_25 += V_7 -> V_141 ;
F_17 ( & V_20 -> V_25 , V_25 ) ;
F_100 ( & V_7 -> V_13 , & V_20 -> V_21 ) ;
V_150 ++ ;
V_7 -> V_153 = V_150 ;
if ( ! -- V_151 )
V_20 -> V_69 = V_7 ;
}
if ( V_150 != V_20 -> V_152 ) {
V_11 -> error = L_40 ;
V_105 = - V_124 ;
goto V_131;
}
V_11 -> V_154 = 1 ;
V_11 -> V_155 = 1 ;
V_11 -> V_156 = 1 ;
V_11 -> V_157 = 1 ;
if ( V_20 -> V_33 == V_39 )
V_11 -> V_158 = F_27 () ;
else
V_11 -> V_158 = sizeof( struct V_44 ) ;
return 0 ;
V_131:
F_25 ( V_20 ) ;
return V_105 ;
}
static void F_106 ( struct V_19 * V_20 )
{
F_107 ( V_159 ) ;
while ( 1 ) {
F_108 ( & V_20 -> V_31 , & V_159 , V_160 ) ;
if ( ! F_35 ( & V_20 -> V_26 ) )
break;
F_109 () ;
}
F_110 ( & V_20 -> V_31 , & V_159 ) ;
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
goto V_161;
F_117 ( L_41 , V_1 -> V_14 . V_15 -> V_162 ) ;
V_1 -> V_7 -> V_17 . type -> F_116 ( & V_1 -> V_7 -> V_17 , & V_1 -> V_14 ) ;
V_1 -> V_3 = false ;
V_1 -> V_163 ++ ;
F_118 ( & V_20 -> V_25 ) ;
if ( V_1 == V_20 -> V_66 )
V_20 -> V_66 = NULL ;
F_119 ( V_164 , V_20 -> V_11 ,
V_1 -> V_14 . V_15 -> V_162 , F_35 ( & V_20 -> V_25 ) ) ;
F_120 ( & V_20 -> V_30 ) ;
V_161:
F_44 ( & V_20 -> V_22 , V_24 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_1 )
{
int V_105 = 0 , V_165 = 0 ;
unsigned long V_24 ;
struct V_19 * V_20 = V_1 -> V_7 -> V_20 ;
unsigned V_25 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( V_1 -> V_3 )
goto V_161;
F_117 ( L_42 , V_1 -> V_14 . V_15 -> V_162 ) ;
V_105 = V_1 -> V_7 -> V_17 . type -> F_121 ( & V_1 -> V_7 -> V_17 , & V_1 -> V_14 ) ;
if ( V_105 )
goto V_161;
V_1 -> V_3 = true ;
V_25 = F_122 ( & V_20 -> V_25 ) ;
if ( V_25 == 1 ) {
V_20 -> V_66 = NULL ;
V_165 = 1 ;
} else if ( V_20 -> V_42 && ( V_20 -> V_57 == V_1 -> V_7 ) ) {
if ( F_67 ( V_60 , & V_1 -> V_4 . V_104 ) )
F_37 ( & V_20 -> V_26 ) ;
}
F_119 ( V_166 , V_20 -> V_11 ,
V_1 -> V_14 . V_15 -> V_162 , V_25 ) ;
F_120 ( & V_20 -> V_30 ) ;
V_161:
F_44 ( & V_20 -> V_22 , V_24 ) ;
if ( V_165 ) {
F_83 ( V_20 -> V_11 -> V_36 ) ;
F_69 ( V_20 ) ;
}
return V_105 ;
}
static int F_123 ( struct V_19 * V_20 , struct V_167 * V_15 ,
T_2 V_168 )
{
int V_105 = - V_124 ;
struct V_1 * V_1 ;
struct V_6 * V_7 ;
F_40 (pg, &m->priority_groups, list) {
F_40 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_14 . V_15 == V_15 )
V_105 = V_168 ( V_1 ) ;
}
}
return V_105 ;
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
static int F_125 ( struct V_19 * V_20 , const char * V_169 )
{
struct V_6 * V_7 ;
unsigned V_170 ;
unsigned long V_24 ;
char V_171 ;
if ( ! V_169 || ( sscanf ( V_169 , L_43 , & V_170 , & V_171 ) != 1 ) || ! V_170 ||
! V_20 -> V_152 || ( V_170 > V_20 -> V_152 ) ) {
F_117 ( L_44 ) ;
return - V_124 ;
}
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_40 (pg, &m->priority_groups, list) {
V_7 -> V_67 = false ;
if ( -- V_170 )
continue;
V_20 -> V_66 = NULL ;
V_20 -> V_57 = NULL ;
V_20 -> V_69 = V_7 ;
}
F_44 ( & V_20 -> V_22 , V_24 ) ;
F_120 ( & V_20 -> V_30 ) ;
return 0 ;
}
static int F_126 ( struct V_19 * V_20 , const char * V_169 , bool V_67 )
{
struct V_6 * V_7 ;
unsigned V_170 ;
char V_171 ;
if ( ! V_169 || ( sscanf ( V_169 , L_43 , & V_170 , & V_171 ) != 1 ) || ! V_170 ||
! V_20 -> V_152 || ( V_170 > V_20 -> V_152 ) ) {
F_117 ( L_45 ) ;
return - V_124 ;
}
F_40 (pg, &m->priority_groups, list) {
if ( ! -- V_170 )
break;
}
F_124 ( V_20 , V_7 , V_67 ) ;
return 0 ;
}
static bool F_127 ( struct V_19 * V_20 , struct V_1 * V_1 )
{
unsigned long V_24 ;
bool V_172 = false ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( F_35 ( & V_20 -> V_27 ) <= V_20 -> V_148 &&
! F_36 ( V_55 , & V_20 -> V_24 ) )
F_16 ( V_56 , & V_20 -> V_24 ) ;
else
V_172 = true ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
return V_172 ;
}
static void F_128 ( void * V_173 , int V_174 )
{
struct V_1 * V_1 = V_173 ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_19 * V_20 = V_7 -> V_20 ;
unsigned long V_24 ;
bool V_175 = false ;
switch ( V_174 ) {
case V_176 :
break;
case V_177 :
if ( ! V_20 -> V_42 ) {
V_174 = 0 ;
break;
}
F_102 ( L_46
L_47 , V_20 -> V_42 , V_174 ) ;
F_116 ( V_1 ) ;
break;
case V_178 :
F_124 ( V_20 , V_7 , true ) ;
break;
case V_179 :
V_175 = 1 ;
case V_180 :
case V_181 :
if ( F_127 ( V_20 , V_1 ) )
F_116 ( V_1 ) ;
V_174 = 0 ;
break;
case V_182 :
default:
F_116 ( V_1 ) ;
}
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( V_174 ) {
if ( V_1 == V_20 -> V_66 ) {
F_102 ( L_48 , V_174 ) ;
V_20 -> V_66 = NULL ;
V_20 -> V_57 = NULL ;
}
} else if ( ! F_36 ( V_56 , & V_20 -> V_24 ) )
V_7 -> V_67 = false ;
if ( F_129 ( & V_20 -> V_26 ) > 0 )
goto V_161;
if ( F_36 ( V_56 , & V_20 -> V_24 ) ) {
if ( V_175 )
F_16 ( V_58 , & V_20 -> V_24 ) ;
else
F_38 ( V_58 , & V_20 -> V_24 ) ;
if ( F_33 ( V_20 ) )
goto V_161;
}
F_38 ( V_23 , & V_20 -> V_24 ) ;
F_69 ( V_20 ) ;
F_130 ( & V_20 -> V_31 ) ;
V_161:
F_44 ( & V_20 -> V_22 , V_24 ) ;
}
static void F_62 ( struct V_1 * V_1 )
{
struct V_77 * V_78 = F_56 ( V_1 -> V_14 . V_15 -> V_76 ) ;
if ( V_1 -> V_3 && ! F_59 ( V_78 ) )
F_131 ( V_78 , F_128 , V_1 ) ;
else
F_128 ( V_1 , V_182 ) ;
}
static void V_5 ( struct V_103 * V_104 )
{
struct V_1 * V_1 =
F_71 ( V_104 , struct V_1 , V_4 . V_104 ) ;
F_62 ( V_1 ) ;
}
static int F_132 ( T_3 error )
{
switch ( error ) {
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
return 1 ;
}
return 0 ;
}
static int F_133 ( struct V_10 * V_11 , struct V_71 * V_79 ,
T_3 error , union V_45 * V_73 )
{
struct V_44 * V_50 = F_26 ( V_73 ) ;
struct V_1 * V_1 = V_50 -> V_1 ;
int V_105 = V_188 ;
if ( error && ! F_132 ( error ) ) {
struct V_19 * V_20 = V_11 -> V_35 ;
V_105 = V_189 ;
if ( V_1 )
F_116 ( V_1 ) ;
if ( F_35 ( & V_20 -> V_25 ) == 0 &&
! F_36 ( V_80 , & V_20 -> V_24 ) ) {
if ( error == V_110 )
F_55 ( V_20 ) ;
V_105 = V_188 ;
}
}
if ( V_1 ) {
struct V_16 * V_17 = & V_1 -> V_7 -> V_17 ;
if ( V_17 -> type -> V_190 )
V_17 -> type -> V_190 ( V_17 , & V_1 -> V_14 , V_50 -> V_62 ) ;
}
return V_105 ;
}
static int F_134 ( struct V_10 * V_11 , struct V_49 * V_79 ,
T_3 * error )
{
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_44 * V_50 = F_28 ( V_79 ) ;
struct V_1 * V_1 = V_50 -> V_1 ;
unsigned long V_24 ;
int V_105 = V_188 ;
if ( ! * error || F_132 ( * error ) )
goto V_191;
if ( V_1 )
F_116 ( V_1 ) ;
if ( F_35 ( & V_20 -> V_25 ) == 0 &&
! F_36 ( V_80 , & V_20 -> V_24 ) ) {
F_55 ( V_20 ) ;
* error = V_110 ;
goto V_191;
}
F_135 ( F_30 ( V_79 ) , V_79 ) ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_66 ( & V_20 -> V_97 , V_79 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
if ( ! F_36 ( V_23 , & V_20 -> V_24 ) )
F_67 ( V_98 , & V_20 -> V_40 ) ;
V_105 = V_192 ;
V_191:
if ( V_1 ) {
struct V_16 * V_17 = & V_1 -> V_7 -> V_17 ;
if ( V_17 -> type -> V_190 )
V_17 -> type -> V_190 ( V_17 , & V_1 -> V_14 , V_50 -> V_62 ) ;
}
return V_105 ;
}
static void F_136 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
F_81 ( V_20 , false , true ) ;
}
static void F_137 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
F_138 ( & V_20 -> V_32 ) ;
F_111 ( V_20 ) ;
F_139 ( & V_20 -> V_32 ) ;
}
static void F_140 ( struct V_10 * V_11 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
unsigned long V_24 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
F_80 ( F_36 ( V_116 , & V_20 -> V_24 ) ,
V_80 , & V_20 -> V_24 ) ;
F_44 ( & V_20 -> V_22 , V_24 ) ;
}
static void F_141 ( struct V_10 * V_11 , T_4 type ,
unsigned V_193 , char * V_194 , unsigned V_195 )
{
int V_196 = 0 ;
unsigned long V_24 ;
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_6 * V_7 ;
struct V_1 * V_127 ;
unsigned V_153 ;
char V_197 ;
F_43 ( & V_20 -> V_22 , V_24 ) ;
if ( type == V_198 )
F_142 ( L_49 , F_36 ( V_23 , & V_20 -> V_24 ) ,
F_35 ( & V_20 -> V_27 ) ) ;
else {
F_142 ( L_50 , F_36 ( V_80 , & V_20 -> V_24 ) +
( V_20 -> V_148 > 0 ) * 2 +
( V_20 -> V_28 != V_29 ) * 2 +
F_36 ( V_41 , & V_20 -> V_24 ) +
( V_20 -> V_33 != V_38 ) * 2 ) ;
if ( F_36 ( V_80 , & V_20 -> V_24 ) )
F_142 ( L_51 ) ;
if ( V_20 -> V_148 )
F_142 ( L_52 , V_20 -> V_148 ) ;
if ( V_20 -> V_28 != V_29 )
F_142 ( L_53 , V_20 -> V_28 ) ;
if ( F_36 ( V_41 , & V_20 -> V_24 ) )
F_142 ( L_54 ) ;
if ( V_20 -> V_33 != V_38 ) {
switch( V_20 -> V_33 ) {
case V_39 :
F_142 ( L_55 ) ;
break;
case V_37 :
F_142 ( L_56 ) ;
break;
default:
F_143 ( true ) ;
break;
}
}
}
if ( ! V_20 -> V_42 || type == V_198 )
F_142 ( L_57 ) ;
else
F_142 ( L_58 , V_20 -> V_42 ) ;
F_142 ( L_50 , V_20 -> V_152 ) ;
if ( V_20 -> V_69 )
V_153 = V_20 -> V_69 -> V_153 ;
else if ( V_20 -> V_57 )
V_153 = V_20 -> V_57 -> V_153 ;
else
V_153 = ( V_20 -> V_152 ? 1 : 0 ) ;
F_142 ( L_50 , V_153 ) ;
switch ( type ) {
case V_198 :
F_40 (pg, &m->priority_groups, list) {
if ( V_7 -> V_67 )
V_197 = 'D' ;
else if ( V_7 == V_20 -> V_57 )
V_197 = 'A' ;
else
V_197 = 'E' ;
F_142 ( L_59 , V_197 ) ;
if ( V_7 -> V_17 . type -> V_199 )
V_196 += V_7 -> V_17 . type -> V_199 ( & V_7 -> V_17 , NULL , type ,
V_194 + V_196 ,
V_195 - V_196 ) ;
else
F_142 ( L_57 ) ;
F_142 ( L_60 , V_7 -> V_141 ,
V_7 -> V_17 . type -> V_200 ) ;
F_40 (p, &pg->pgpaths, list) {
F_142 ( L_61 , V_127 -> V_14 . V_15 -> V_162 ,
V_127 -> V_3 ? L_62 : L_63 ,
V_127 -> V_163 ) ;
if ( V_7 -> V_17 . type -> V_199 )
V_196 += V_7 -> V_17 . type -> V_199 ( & V_7 -> V_17 ,
& V_127 -> V_14 , type , V_194 + V_196 ,
V_195 - V_196 ) ;
}
}
break;
case V_201 :
F_40 (pg, &m->priority_groups, list) {
F_142 ( L_64 , V_7 -> V_17 . type -> V_162 ) ;
if ( V_7 -> V_17 . type -> V_199 )
V_196 += V_7 -> V_17 . type -> V_199 ( & V_7 -> V_17 , NULL , type ,
V_194 + V_196 ,
V_195 - V_196 ) ;
else
F_142 ( L_57 ) ;
F_142 ( L_60 , V_7 -> V_141 ,
V_7 -> V_17 . type -> V_202 ) ;
F_40 (p, &pg->pgpaths, list) {
F_142 ( L_64 , V_127 -> V_14 . V_15 -> V_162 ) ;
if ( V_7 -> V_17 . type -> V_199 )
V_196 += V_7 -> V_17 . type -> V_199 ( & V_7 -> V_17 ,
& V_127 -> V_14 , type , V_194 + V_196 ,
V_195 - V_196 ) ;
}
}
break;
}
F_44 ( & V_20 -> V_22 , V_24 ) ;
}
static int F_144 ( struct V_10 * V_11 , unsigned V_129 , char * * V_126 )
{
int V_105 = - V_124 ;
struct V_167 * V_15 ;
struct V_19 * V_20 = V_11 -> V_35 ;
T_2 V_168 ;
F_138 ( & V_20 -> V_32 ) ;
if ( F_145 ( V_11 ) ) {
V_105 = - V_133 ;
goto V_161;
}
if ( V_129 == 1 ) {
if ( ! strcasecmp ( V_126 [ 0 ] , L_26 ) ) {
V_105 = F_81 ( V_20 , true , false ) ;
goto V_161;
} else if ( ! strcasecmp ( V_126 [ 0 ] , L_65 ) ) {
V_105 = F_81 ( V_20 , false , false ) ;
goto V_161;
}
}
if ( V_129 != 2 ) {
F_117 ( L_66 , V_129 ) ;
goto V_161;
}
if ( ! strcasecmp ( V_126 [ 0 ] , L_67 ) ) {
V_105 = F_126 ( V_20 , V_126 [ 1 ] , true ) ;
goto V_161;
} else if ( ! strcasecmp ( V_126 [ 0 ] , L_68 ) ) {
V_105 = F_126 ( V_20 , V_126 [ 1 ] , false ) ;
goto V_161;
} else if ( ! strcasecmp ( V_126 [ 0 ] , L_69 ) ) {
V_105 = F_125 ( V_20 , V_126 [ 1 ] ) ;
goto V_161;
} else if ( ! strcasecmp ( V_126 [ 0 ] , L_70 ) )
V_168 = F_121 ;
else if ( ! strcasecmp ( V_126 [ 0 ] , L_71 ) )
V_168 = F_116 ;
else {
F_117 ( L_72 , V_126 [ 0 ] ) ;
goto V_161;
}
V_105 = F_91 ( V_11 , V_126 [ 1 ] , F_92 ( V_11 -> V_36 ) , & V_15 ) ;
if ( V_105 ) {
F_117 ( L_73 ,
V_126 [ 1 ] ) ;
goto V_161;
}
V_105 = F_123 ( V_20 , V_15 , V_168 ) ;
F_11 ( V_11 , V_15 ) ;
V_161:
F_139 ( & V_20 -> V_32 ) ;
return V_105 ;
}
static int F_146 ( struct V_10 * V_11 ,
struct V_75 * * V_76 , T_5 * V_203 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_1 * V_66 ;
int V_105 ;
V_66 = F_50 ( V_20 -> V_66 ) ;
if ( ! V_66 )
V_66 = F_51 ( V_20 , 0 ) ;
if ( V_66 ) {
if ( ! F_36 ( V_23 , & V_20 -> V_24 ) ) {
* V_76 = V_66 -> V_14 . V_15 -> V_76 ;
* V_203 = V_66 -> V_14 . V_15 -> V_203 ;
V_105 = 0 ;
} else {
V_105 = - V_204 ;
}
} else {
if ( F_36 ( V_80 , & V_20 -> V_24 ) )
V_105 = - V_204 ;
else
V_105 = - V_205 ;
}
if ( V_105 == - V_204 ) {
if ( ! F_50 ( V_20 -> V_57 ) ) {
( void ) F_51 ( V_20 , 0 ) ;
}
if ( F_36 ( V_56 , & V_20 -> V_24 ) )
F_42 ( V_20 ) ;
F_83 ( V_20 -> V_11 -> V_36 ) ;
F_69 ( V_20 ) ;
}
if ( ! V_105 && V_11 -> V_145 != F_147 ( ( * V_76 ) -> V_206 ) >> V_207 )
return 1 ;
return V_105 ;
}
static int F_148 ( struct V_10 * V_11 ,
T_6 V_208 , void * V_173 )
{
struct V_19 * V_20 = V_11 -> V_35 ;
struct V_6 * V_7 ;
struct V_1 * V_127 ;
int V_61 = 0 ;
F_40 (pg, &m->priority_groups, list) {
F_40 (p, &pg->pgpaths, list) {
V_61 = V_208 ( V_11 , V_127 -> V_14 . V_15 , V_11 -> V_209 , V_11 -> V_145 , V_173 ) ;
if ( V_61 )
goto V_161;
}
}
V_161:
return V_61 ;
}
static int F_149 ( struct V_1 * V_1 )
{
struct V_77 * V_78 = F_56 ( V_1 -> V_14 . V_15 -> V_76 ) ;
return F_150 ( V_78 ) ;
}
static int F_151 ( struct V_10 * V_11 )
{
bool V_210 = false , V_211 = false ;
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
return V_210 ;
}
V_210 = true ;
F_40 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_3 ) {
V_211 = true ;
if ( ! F_149 ( V_1 ) ) {
V_210 = false ;
break;
}
}
}
if ( ! V_211 ) {
V_210 = false ;
}
return V_210 ;
}
static int T_7 F_152 ( void )
{
int V_105 ;
V_105 = F_153 ( & V_212 ) ;
if ( V_105 < 0 ) {
F_102 ( L_74 , V_105 ) ;
V_105 = - V_124 ;
goto V_213;
}
V_98 = F_154 ( L_75 , V_214 , 0 ) ;
if ( ! V_98 ) {
F_102 ( L_76 ) ;
V_105 = - V_130 ;
goto V_215;
}
V_60 = F_155 ( L_77 ,
V_214 ) ;
if ( ! V_60 ) {
F_102 ( L_78 ) ;
V_105 = - V_130 ;
goto V_216;
}
return 0 ;
V_216:
F_156 ( V_98 ) ;
V_215:
F_157 ( & V_212 ) ;
V_213:
return V_105 ;
}
static void T_8 F_158 ( void )
{
F_156 ( V_60 ) ;
F_156 ( V_98 ) ;
F_157 ( & V_212 ) ;
}
