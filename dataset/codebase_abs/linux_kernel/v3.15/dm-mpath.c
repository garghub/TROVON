static struct V_1 * F_1 ( void )
{
struct V_1 * V_1 = F_2 ( sizeof( * V_1 ) , V_2 ) ;
if ( V_1 ) {
V_1 -> V_3 = 1 ;
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
struct V_12 * V_13 = V_10 -> V_14 ;
F_9 (pgpath, tmp, pgpaths, list) {
F_10 ( & V_1 -> V_15 ) ;
if ( V_13 -> V_16 )
F_11 ( F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ) ;
F_13 ( V_10 , V_1 -> V_17 . V_18 ) ;
F_4 ( V_1 ) ;
}
}
static void F_14 ( struct V_5 * V_6 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 = & V_6 -> V_21 ;
if ( V_21 -> type ) {
V_21 -> type -> V_22 ( V_21 ) ;
F_15 ( V_21 -> type ) ;
}
F_8 ( & V_6 -> V_7 , V_10 ) ;
F_5 ( V_6 ) ;
}
static struct V_12 * F_16 ( struct V_9 * V_10 )
{
struct V_12 * V_13 ;
unsigned V_23 = F_17 () ;
V_13 = F_2 ( sizeof( * V_13 ) , V_2 ) ;
if ( V_13 ) {
F_7 ( & V_13 -> V_24 ) ;
F_18 ( & V_13 -> V_25 ) ;
V_13 -> V_26 = 1 ;
V_13 -> V_27 = V_28 ;
F_19 ( & V_13 -> V_29 , V_29 ) ;
F_20 ( & V_13 -> V_30 ) ;
F_21 ( & V_13 -> V_31 ) ;
V_13 -> V_32 = F_22 ( V_23 , V_33 ) ;
if ( ! V_13 -> V_32 ) {
F_5 ( V_13 ) ;
return NULL ;
}
V_13 -> V_10 = V_10 ;
V_10 -> V_14 = V_13 ;
}
return V_13 ;
}
static void F_23 ( struct V_12 * V_13 )
{
struct V_5 * V_6 , * V_11 ;
F_9 (pg, tmp, &m->priority_groups, list) {
F_10 ( & V_6 -> V_15 ) ;
F_14 ( V_6 , V_13 -> V_10 ) ;
}
F_5 ( V_13 -> V_16 ) ;
F_5 ( V_13 -> V_34 ) ;
F_24 ( V_13 -> V_32 ) ;
F_5 ( V_13 ) ;
}
static int F_25 ( struct V_12 * V_13 , union V_35 * V_36 )
{
struct V_37 * V_38 ;
V_38 = F_26 ( V_13 -> V_32 , V_39 ) ;
if ( ! V_38 )
return - V_40 ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_36 -> V_41 = V_38 ;
return 0 ;
}
static void F_27 ( struct V_12 * V_13 , union V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_41 ;
V_36 -> V_41 = NULL ;
F_28 ( V_38 , V_13 -> V_32 ) ;
}
static int F_29 ( struct V_12 * V_13 )
{
struct V_1 * V_1 ;
unsigned long V_42 = 0 ;
if ( V_13 -> V_43 || V_13 -> V_44 )
return 0 ;
V_13 -> V_45 ++ ;
V_13 -> V_46 = 0 ;
if ( ! V_13 -> V_47 )
return 0 ;
if ( V_13 -> V_48 )
V_42 = F_30 ( V_13 -> V_27 != V_28 ?
V_13 -> V_27 : V_49 ) ;
F_31 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_32 ( V_50 , & V_1 -> V_4 ,
V_42 ) )
V_13 -> V_43 ++ ;
}
return V_13 -> V_43 ;
}
static void F_33 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
V_13 -> V_47 = V_1 -> V_6 ;
if ( V_13 -> V_16 ) {
V_13 -> V_46 = 1 ;
V_13 -> V_26 = 1 ;
} else {
V_13 -> V_46 = 0 ;
V_13 -> V_26 = 0 ;
}
V_13 -> V_45 = 0 ;
}
static int F_34 ( struct V_12 * V_13 , struct V_5 * V_6 ,
T_1 V_51 )
{
struct V_52 * V_17 ;
V_17 = V_6 -> V_21 . type -> V_53 ( & V_6 -> V_21 , & V_13 -> V_54 , V_51 ) ;
if ( ! V_17 )
return - V_55 ;
V_13 -> V_56 = F_35 ( V_17 ) ;
if ( V_13 -> V_47 != V_6 )
F_33 ( V_13 , V_13 -> V_56 ) ;
return 0 ;
}
static void F_36 ( struct V_12 * V_13 , T_1 V_51 )
{
struct V_5 * V_6 ;
unsigned V_57 = 1 ;
if ( ! V_13 -> V_58 )
goto V_59;
if ( V_13 -> V_60 ) {
V_6 = V_13 -> V_60 ;
V_13 -> V_60 = NULL ;
if ( ! F_34 ( V_13 , V_6 , V_51 ) )
return;
}
if ( V_13 -> V_47 && ! F_34 ( V_13 , V_13 -> V_47 , V_51 ) )
return;
do {
F_31 (pg, &m->priority_groups, list) {
if ( V_6 -> V_57 == V_57 )
continue;
if ( ! F_34 ( V_13 , V_6 , V_51 ) ) {
if ( ! V_57 )
V_13 -> V_48 = 1 ;
return;
}
}
} while ( V_57 -- );
V_59:
V_13 -> V_56 = NULL ;
V_13 -> V_47 = NULL ;
}
static int F_37 ( struct V_12 * V_13 )
{
return ( V_13 -> V_61 ||
( V_13 -> V_61 != V_13 -> V_62 &&
F_38 ( V_13 -> V_10 ) ) ) ;
}
static int F_39 ( struct V_9 * V_10 , struct V_63 * V_64 ,
union V_35 * V_65 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
int V_66 = V_67 ;
T_1 V_51 = F_40 ( V_64 ) ;
unsigned long V_68 ;
struct V_1 * V_1 ;
struct V_69 * V_19 ;
struct V_37 * V_38 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( ! V_13 -> V_56 ||
( ! V_13 -> V_26 && ( V_13 -> V_54 && -- V_13 -> V_54 == 0 ) ) )
F_36 ( V_13 , V_51 ) ;
V_1 = V_13 -> V_56 ;
if ( ! V_1 ) {
if ( ! F_37 ( V_13 ) )
V_66 = - V_70 ;
goto V_71;
}
if ( ! F_42 ( V_13 ) ) {
F_29 ( V_13 ) ;
goto V_71;
}
if ( F_25 ( V_13 , V_65 ) < 0 )
goto V_71;
V_19 = V_1 -> V_17 . V_18 -> V_19 ;
V_64 -> V_72 = F_12 ( V_19 ) ;
V_64 -> V_73 = V_19 -> V_74 ;
V_64 -> V_75 |= V_76 ;
V_38 = V_65 -> V_41 ;
V_38 -> V_1 = V_1 ;
V_38 -> V_51 = V_51 ;
if ( V_1 -> V_6 -> V_21 . type -> V_77 )
V_1 -> V_6 -> V_21 . type -> V_77 ( & V_1 -> V_6 -> V_21 ,
& V_1 -> V_17 ,
V_51 ) ;
V_66 = V_78 ;
V_71:
F_43 ( & V_13 -> V_25 , V_68 ) ;
return V_66 ;
}
static int V_61 ( struct V_12 * V_13 , unsigned V_61 ,
unsigned V_79 )
{
unsigned long V_68 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( V_79 )
V_13 -> V_62 = V_13 -> V_61 ;
else
V_13 -> V_62 = V_61 ;
V_13 -> V_61 = V_61 ;
F_43 ( & V_13 -> V_25 , V_68 ) ;
if ( ! V_61 )
F_44 ( V_13 -> V_10 -> V_80 ) ;
return 0 ;
}
static void V_29 ( struct V_81 * V_82 )
{
struct V_12 * V_13 =
F_45 ( V_82 , struct V_12 , V_29 ) ;
F_46 ( V_13 -> V_10 -> V_80 ) ;
}
static int F_47 ( struct V_83 * V_84 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_66 ;
struct V_85 * V_86 ;
unsigned V_87 ;
static struct V_88 V_89 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_86 = F_48 ( F_49 ( V_84 ) ) ;
if ( ! V_86 ) {
V_10 -> error = L_2 ;
return - V_90 ;
}
V_66 = F_50 ( V_89 , V_84 , & V_87 , & V_10 -> error ) ;
if ( V_66 ) {
F_15 ( V_86 ) ;
return - V_90 ;
}
V_66 = V_86 -> V_91 ( & V_6 -> V_21 , V_87 , V_84 -> V_92 ) ;
if ( V_66 ) {
F_15 ( V_86 ) ;
V_10 -> error = L_3 ;
return V_66 ;
}
V_6 -> V_21 . type = V_86 ;
F_51 ( V_84 , V_87 ) ;
return 0 ;
}
static struct V_1 * F_52 ( struct V_83 * V_84 , struct V_20 * V_21 ,
struct V_9 * V_10 )
{
int V_66 ;
struct V_1 * V_93 ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_94 * V_72 = NULL ;
const char * V_95 ;
if ( V_84 -> V_96 < 1 ) {
V_10 -> error = L_4 ;
return F_53 ( - V_90 ) ;
}
V_93 = F_1 () ;
if ( ! V_93 )
return F_53 ( - V_40 ) ;
V_66 = F_54 ( V_10 , F_49 ( V_84 ) , F_55 ( V_10 -> V_80 ) ,
& V_93 -> V_17 . V_18 ) ;
if ( V_66 ) {
V_10 -> error = L_5 ;
goto V_97;
}
if ( V_13 -> V_98 || V_13 -> V_16 )
V_72 = F_12 ( V_93 -> V_17 . V_18 -> V_19 ) ;
if ( V_13 -> V_98 ) {
V_95 = F_56 ( V_72 , V_2 ) ;
if ( V_95 ) {
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = V_95 ;
F_5 ( V_13 -> V_34 ) ;
V_13 -> V_34 = NULL ;
}
}
if ( V_13 -> V_16 ) {
V_66 = F_57 ( V_72 , V_13 -> V_16 ) ;
if ( V_66 == - V_99 ) {
F_11 ( V_72 ) ;
V_66 = F_57 ( V_72 , V_13 -> V_16 ) ;
}
if ( V_66 < 0 ) {
V_10 -> error = L_6 ;
F_13 ( V_10 , V_93 -> V_17 . V_18 ) ;
goto V_97;
}
if ( V_13 -> V_34 ) {
V_66 = F_58 ( V_72 , V_13 -> V_34 ) ;
if ( V_66 < 0 ) {
V_10 -> error = L_7
L_8 ;
F_11 ( V_72 ) ;
F_13 ( V_10 , V_93 -> V_17 . V_18 ) ;
goto V_97;
}
}
}
V_66 = V_21 -> type -> V_100 ( V_21 , & V_93 -> V_17 , V_84 -> V_96 , V_84 -> V_92 , & V_10 -> error ) ;
if ( V_66 ) {
F_13 ( V_10 , V_93 -> V_17 . V_18 ) ;
goto V_97;
}
return V_93 ;
V_97:
F_4 ( V_93 ) ;
return F_53 ( V_66 ) ;
}
static struct V_5 * F_59 ( struct V_83 * V_84 ,
struct V_12 * V_13 )
{
static struct V_88 V_89 [] = {
{ 1 , 1024 , L_9 } ,
{ 0 , 1024 , L_10 }
} ;
int V_66 ;
unsigned V_101 , V_102 , V_103 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_13 -> V_10 ;
if ( V_84 -> V_96 < 2 ) {
V_84 -> V_96 = 0 ;
V_10 -> error = L_11 ;
return F_53 ( - V_90 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_12 ;
return F_53 ( - V_40 ) ;
}
V_6 -> V_13 = V_13 ;
V_66 = F_47 ( V_84 , V_6 , V_10 ) ;
if ( V_66 )
goto V_97;
V_66 = F_60 ( V_89 , V_84 , & V_6 -> V_104 , & V_10 -> error ) ;
if ( V_66 )
goto V_97;
V_66 = F_60 ( V_89 + 1 , V_84 , & V_102 , & V_10 -> error ) ;
if ( V_66 )
goto V_97;
V_103 = 1 + V_102 ;
for ( V_101 = 0 ; V_101 < V_6 -> V_104 ; V_101 ++ ) {
struct V_1 * V_1 ;
struct V_83 V_105 ;
if ( V_84 -> V_96 < V_103 ) {
V_10 -> error = L_13 ;
V_66 = - V_90 ;
goto V_97;
}
V_105 . V_96 = V_103 ;
V_105 . V_92 = V_84 -> V_92 ;
V_1 = F_52 ( & V_105 , & V_6 -> V_21 , V_10 ) ;
if ( F_61 ( V_1 ) ) {
V_66 = F_62 ( V_1 ) ;
goto V_97;
}
V_1 -> V_6 = V_6 ;
F_63 ( & V_1 -> V_15 , & V_6 -> V_7 ) ;
F_51 ( V_84 , V_103 ) ;
}
return V_6 ;
V_97:
F_14 ( V_6 , V_10 ) ;
return F_53 ( V_66 ) ;
}
static int F_64 ( struct V_83 * V_84 , struct V_12 * V_13 )
{
unsigned V_106 ;
int V_107 ;
struct V_9 * V_10 = V_13 -> V_10 ;
static struct V_88 V_89 [] = {
{ 0 , 1024 , L_14 } ,
} ;
if ( F_50 ( V_89 , V_84 , & V_106 , & V_10 -> error ) )
return - V_90 ;
if ( ! V_106 )
return 0 ;
V_13 -> V_16 = F_65 ( F_49 ( V_84 ) , V_2 ) ;
if ( ! F_66 ( F_67 ( V_13 -> V_16 ) ,
L_15 , V_13 -> V_16 ) ) {
V_10 -> error = L_16 ;
V_107 = - V_90 ;
goto V_108;
}
if ( V_106 > 1 ) {
char * V_93 ;
int V_101 , V_109 , V_110 = 4 ;
for ( V_101 = 0 ; V_101 <= V_106 - 2 ; V_101 ++ )
V_110 += strlen ( V_84 -> V_92 [ V_101 ] ) + 1 ;
V_93 = V_13 -> V_34 = F_2 ( V_110 , V_2 ) ;
if ( ! V_93 ) {
V_10 -> error = L_17 ;
V_107 = - V_40 ;
goto V_108;
}
V_109 = sprintf ( V_93 , L_18 , V_106 - 1 ) ;
for ( V_101 = 0 , V_93 += V_109 + 1 ; V_101 <= V_106 - 2 ; V_101 ++ , V_93 += V_109 + 1 )
V_109 = sprintf ( V_93 , L_19 , V_84 -> V_92 [ V_101 ] ) ;
}
F_51 ( V_84 , V_106 - 1 ) ;
return 0 ;
V_108:
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = NULL ;
return V_107 ;
}
static int F_68 ( struct V_83 * V_84 , struct V_12 * V_13 )
{
int V_66 ;
unsigned V_96 ;
struct V_9 * V_10 = V_13 -> V_10 ;
const char * V_111 ;
static struct V_88 V_89 [] = {
{ 0 , 6 , L_20 } ,
{ 1 , 50 , L_21 } ,
{ 0 , 60000 , L_22 } ,
} ;
V_66 = F_50 ( V_89 , V_84 , & V_96 , & V_10 -> error ) ;
if ( V_66 )
return - V_90 ;
if ( ! V_96 )
return 0 ;
do {
V_111 = F_49 ( V_84 ) ;
V_96 -- ;
if ( ! strcasecmp ( V_111 , L_23 ) ) {
V_66 = V_61 ( V_13 , 1 , 0 ) ;
continue;
}
if ( ! strcasecmp ( V_111 , L_24 ) ) {
V_13 -> V_98 = 1 ;
continue;
}
if ( ! strcasecmp ( V_111 , L_25 ) &&
( V_96 >= 1 ) ) {
V_66 = F_60 ( V_89 + 1 , V_84 , & V_13 -> V_112 , & V_10 -> error ) ;
V_96 -- ;
continue;
}
if ( ! strcasecmp ( V_111 , L_26 ) &&
( V_96 >= 1 ) ) {
V_66 = F_60 ( V_89 + 2 , V_84 , & V_13 -> V_27 , & V_10 -> error ) ;
V_96 -- ;
continue;
}
V_10 -> error = L_27 ;
V_66 = - V_90 ;
} while ( V_96 && ! V_66 );
return V_66 ;
}
static int F_69 ( struct V_9 * V_10 , unsigned int V_96 ,
char * * V_92 )
{
static struct V_88 V_89 [] = {
{ 0 , 1024 , L_28 } ,
{ 0 , 1024 , L_29 } ,
} ;
int V_66 ;
struct V_12 * V_13 ;
struct V_83 V_84 ;
unsigned V_113 = 0 ;
unsigned V_114 ;
V_84 . V_96 = V_96 ;
V_84 . V_92 = V_92 ;
V_13 = F_16 ( V_10 ) ;
if ( ! V_13 ) {
V_10 -> error = L_30 ;
return - V_90 ;
}
V_66 = F_68 ( & V_84 , V_13 ) ;
if ( V_66 )
goto V_97;
V_66 = F_64 ( & V_84 , V_13 ) ;
if ( V_66 )
goto V_97;
V_66 = F_60 ( V_89 , & V_84 , & V_13 -> V_115 , & V_10 -> error ) ;
if ( V_66 )
goto V_97;
V_66 = F_60 ( V_89 + 1 , & V_84 , & V_114 , & V_10 -> error ) ;
if ( V_66 )
goto V_97;
if ( ( ! V_13 -> V_115 && V_114 ) ||
( V_13 -> V_115 && ! V_114 ) ) {
V_10 -> error = L_31 ;
V_66 = - V_90 ;
goto V_97;
}
while ( V_84 . V_96 ) {
struct V_5 * V_6 ;
V_6 = F_59 ( & V_84 , V_13 ) ;
if ( F_61 ( V_6 ) ) {
V_66 = F_62 ( V_6 ) ;
goto V_97;
}
V_13 -> V_58 += V_6 -> V_104 ;
F_63 ( & V_6 -> V_15 , & V_13 -> V_24 ) ;
V_113 ++ ;
V_6 -> V_116 = V_113 ;
if ( ! -- V_114 )
V_13 -> V_60 = V_6 ;
}
if ( V_113 != V_13 -> V_115 ) {
V_10 -> error = L_32 ;
V_66 = - V_90 ;
goto V_97;
}
V_10 -> V_117 = 1 ;
V_10 -> V_118 = 1 ;
V_10 -> V_119 = 1 ;
return 0 ;
V_97:
F_23 ( V_13 ) ;
return V_66 ;
}
static void F_70 ( struct V_12 * V_13 )
{
F_71 ( V_120 , V_121 ) ;
unsigned long V_68 ;
F_72 ( & V_13 -> V_30 , & V_120 ) ;
while ( 1 ) {
F_73 ( V_122 ) ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( ! V_13 -> V_43 ) {
F_43 ( & V_13 -> V_25 , V_68 ) ;
break;
}
F_43 ( & V_13 -> V_25 , V_68 ) ;
F_74 () ;
}
F_73 ( V_123 ) ;
F_75 ( & V_13 -> V_30 , & V_120 ) ;
}
static void F_76 ( struct V_12 * V_13 )
{
unsigned long V_68 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
V_13 -> V_44 = 1 ;
F_43 ( & V_13 -> V_25 , V_68 ) ;
F_77 ( V_50 ) ;
F_70 ( V_13 ) ;
F_77 ( V_124 ) ;
F_78 ( & V_13 -> V_29 ) ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
V_13 -> V_44 = 0 ;
F_43 ( & V_13 -> V_25 , V_68 ) ;
}
static void F_79 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_76 ( V_13 ) ;
F_23 ( V_13 ) ;
}
static int F_80 ( struct V_1 * V_1 )
{
unsigned long V_68 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( ! V_1 -> V_3 )
goto V_125;
F_81 ( L_33 , V_1 -> V_17 . V_18 -> V_126 ) ;
V_1 -> V_6 -> V_21 . type -> F_80 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
V_1 -> V_3 = 0 ;
V_1 -> V_127 ++ ;
V_13 -> V_58 -- ;
if ( V_1 == V_13 -> V_56 )
V_13 -> V_56 = NULL ;
F_82 ( V_128 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_126 , V_13 -> V_58 ) ;
F_83 ( & V_13 -> V_29 ) ;
V_125:
F_43 ( & V_13 -> V_25 , V_68 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_1 )
{
int V_66 = 0 , V_129 = 0 ;
unsigned long V_68 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( V_1 -> V_3 )
goto V_125;
if ( ! V_1 -> V_6 -> V_21 . type -> F_84 ) {
F_81 ( L_34 ,
V_1 -> V_6 -> V_21 . type -> V_126 ) ;
V_66 = - V_90 ;
goto V_125;
}
V_66 = V_1 -> V_6 -> V_21 . type -> F_84 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
if ( V_66 )
goto V_125;
V_1 -> V_3 = 1 ;
if ( ! V_13 -> V_58 ++ ) {
V_13 -> V_56 = NULL ;
V_129 = 1 ;
} else if ( V_13 -> V_16 && ( V_13 -> V_47 == V_1 -> V_6 ) ) {
if ( F_85 ( V_50 , & V_1 -> V_4 . V_82 ) )
V_13 -> V_43 ++ ;
}
F_82 ( V_130 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_126 , V_13 -> V_58 ) ;
F_83 ( & V_13 -> V_29 ) ;
V_125:
F_43 ( & V_13 -> V_25 , V_68 ) ;
if ( V_129 )
F_44 ( V_13 -> V_10 -> V_80 ) ;
return V_66 ;
}
static int F_86 ( struct V_12 * V_13 , struct V_131 * V_18 ,
T_2 V_132 )
{
int V_66 = - V_90 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_31 (pg, &m->priority_groups, list) {
F_31 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_17 . V_18 == V_18 )
V_66 = V_132 ( V_1 ) ;
}
}
return V_66 ;
}
static void F_87 ( struct V_12 * V_13 , struct V_5 * V_6 ,
int V_57 )
{
unsigned long V_68 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
V_6 -> V_57 = V_57 ;
V_13 -> V_56 = NULL ;
V_13 -> V_47 = NULL ;
F_43 ( & V_13 -> V_25 , V_68 ) ;
F_83 ( & V_13 -> V_29 ) ;
}
static int F_88 ( struct V_12 * V_13 , const char * V_133 )
{
struct V_5 * V_6 ;
unsigned V_134 ;
unsigned long V_68 ;
char V_135 ;
if ( ! V_133 || ( sscanf ( V_133 , L_35 , & V_134 , & V_135 ) != 1 ) || ! V_134 ||
( V_134 > V_13 -> V_115 ) ) {
F_81 ( L_36 ) ;
return - V_90 ;
}
F_41 ( & V_13 -> V_25 , V_68 ) ;
F_31 (pg, &m->priority_groups, list) {
V_6 -> V_57 = 0 ;
if ( -- V_134 )
continue;
V_13 -> V_56 = NULL ;
V_13 -> V_47 = NULL ;
V_13 -> V_60 = V_6 ;
}
F_43 ( & V_13 -> V_25 , V_68 ) ;
F_83 ( & V_13 -> V_29 ) ;
return 0 ;
}
static int F_89 ( struct V_12 * V_13 , const char * V_133 , int V_57 )
{
struct V_5 * V_6 ;
unsigned V_134 ;
char V_135 ;
if ( ! V_133 || ( sscanf ( V_133 , L_35 , & V_134 , & V_135 ) != 1 ) || ! V_134 ||
( V_134 > V_13 -> V_115 ) ) {
F_81 ( L_37 ) ;
return - V_90 ;
}
F_31 (pg, &m->priority_groups, list) {
if ( ! -- V_134 )
break;
}
F_87 ( V_13 , V_6 , V_57 ) ;
return 0 ;
}
static int F_90 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
unsigned long V_68 ;
int V_136 = 0 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( V_13 -> V_45 <= V_13 -> V_112 && ! V_13 -> V_44 )
V_13 -> V_46 = 1 ;
else
V_136 = 1 ;
F_43 ( & V_13 -> V_25 , V_68 ) ;
return V_136 ;
}
static void F_91 ( void * V_137 , int V_138 )
{
struct V_1 * V_1 = V_137 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned long V_68 ;
unsigned V_139 = 0 ;
switch ( V_138 ) {
case V_140 :
break;
case V_141 :
if ( ! V_13 -> V_16 ) {
V_138 = 0 ;
break;
}
F_92 ( L_38
L_39 , V_13 -> V_16 , V_138 ) ;
F_80 ( V_1 ) ;
break;
case V_142 :
F_87 ( V_13 , V_6 , 1 ) ;
break;
case V_143 :
V_139 = 1 ;
case V_144 :
case V_145 :
if ( F_90 ( V_13 , V_1 ) )
F_80 ( V_1 ) ;
V_138 = 0 ;
break;
default:
F_80 ( V_1 ) ;
}
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( V_138 ) {
if ( V_1 == V_13 -> V_56 ) {
F_92 ( L_40 , V_138 ) ;
V_13 -> V_56 = NULL ;
V_13 -> V_47 = NULL ;
}
} else if ( ! V_13 -> V_46 )
V_6 -> V_57 = 0 ;
if ( -- V_13 -> V_43 )
goto V_125;
if ( V_13 -> V_46 ) {
V_13 -> V_48 = V_139 ;
if ( F_29 ( V_13 ) )
goto V_125;
}
V_13 -> V_26 = 0 ;
F_93 ( & V_13 -> V_30 ) ;
V_125:
F_43 ( & V_13 -> V_25 , V_68 ) ;
}
static void V_4 ( struct V_81 * V_82 )
{
struct V_1 * V_1 =
F_45 ( V_82 , struct V_1 , V_4 . V_82 ) ;
if ( V_1 -> V_3 )
F_94 ( F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ,
F_91 , V_1 ) ;
else
F_91 ( V_1 , V_146 ) ;
}
static int F_95 ( int error )
{
switch ( error ) {
case - V_147 :
case - V_148 :
case - V_149 :
case - V_150 :
case - V_151 :
return 1 ;
}
return 0 ;
}
static int F_96 ( struct V_12 * V_13 , struct V_63 * V_64 ,
int error , struct V_37 * V_38 )
{
int V_66 = V_152 ;
unsigned long V_68 ;
if ( ! error && ! V_64 -> V_138 )
return 0 ;
if ( F_95 ( error ) ) {
if ( ( V_64 -> V_75 & V_153 ) &&
! V_64 -> V_72 -> V_154 . V_155 ) {
struct V_156 * V_154 ;
V_154 = F_97 ( F_98 ( V_13 -> V_10 -> V_80 ) ) ;
V_154 -> V_155 = 0 ;
}
return error ;
}
if ( V_38 -> V_1 )
F_80 ( V_38 -> V_1 ) ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( ! V_13 -> V_58 ) {
if ( ! V_13 -> V_61 ) {
if ( ! F_37 ( V_13 ) )
V_66 = - V_70 ;
} else {
if ( error == - V_157 )
V_66 = error ;
}
}
F_43 ( & V_13 -> V_25 , V_68 ) ;
return V_66 ;
}
static int F_99 ( struct V_9 * V_10 , struct V_63 * V_64 ,
int error , union V_35 * V_65 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_37 * V_38 = V_65 -> V_41 ;
struct V_1 * V_1 ;
struct V_20 * V_21 ;
int V_66 ;
F_100 ( ! V_38 ) ;
V_66 = F_96 ( V_13 , V_64 , error , V_38 ) ;
V_1 = V_38 -> V_1 ;
if ( V_1 ) {
V_21 = & V_1 -> V_6 -> V_21 ;
if ( V_21 -> type -> V_158 )
V_21 -> type -> V_158 ( V_21 , & V_1 -> V_17 , V_38 -> V_51 ) ;
}
F_27 ( V_13 , V_65 ) ;
return V_66 ;
}
static void F_101 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
V_61 ( V_13 , 0 , 1 ) ;
}
static void F_102 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_103 ( & V_13 -> V_31 ) ;
F_76 ( V_13 ) ;
F_104 ( & V_13 -> V_31 ) ;
}
static void F_105 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
unsigned long V_68 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
V_13 -> V_61 = V_13 -> V_62 ;
F_43 ( & V_13 -> V_25 , V_68 ) ;
}
static void F_106 ( struct V_9 * V_10 , T_3 type ,
unsigned V_159 , char * V_160 , unsigned V_161 )
{
int V_162 = 0 ;
unsigned long V_68 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_93 ;
unsigned V_116 ;
char V_163 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( type == V_164 )
F_107 ( L_41 , V_13 -> V_26 , V_13 -> V_45 ) ;
else {
F_107 ( L_42 , V_13 -> V_61 +
( V_13 -> V_112 > 0 ) * 2 +
( V_13 -> V_27 != V_28 ) * 2 +
V_13 -> V_98 ) ;
if ( V_13 -> V_61 )
F_107 ( L_43 ) ;
if ( V_13 -> V_112 )
F_107 ( L_44 , V_13 -> V_112 ) ;
if ( V_13 -> V_27 != V_28 )
F_107 ( L_45 , V_13 -> V_27 ) ;
if ( V_13 -> V_98 )
F_107 ( L_46 ) ;
}
if ( ! V_13 -> V_16 || type == V_164 )
F_107 ( L_47 ) ;
else
F_107 ( L_48 , V_13 -> V_16 ) ;
F_107 ( L_42 , V_13 -> V_115 ) ;
if ( V_13 -> V_60 )
V_116 = V_13 -> V_60 -> V_116 ;
else if ( V_13 -> V_47 )
V_116 = V_13 -> V_47 -> V_116 ;
else
V_116 = ( V_13 -> V_115 ? 1 : 0 ) ;
F_107 ( L_42 , V_116 ) ;
switch ( type ) {
case V_164 :
F_31 (pg, &m->priority_groups, list) {
if ( V_6 -> V_57 )
V_163 = 'D' ;
else if ( V_6 == V_13 -> V_47 )
V_163 = 'A' ;
else
V_163 = 'E' ;
F_107 ( L_49 , V_163 ) ;
if ( V_6 -> V_21 . type -> V_165 )
V_162 += V_6 -> V_21 . type -> V_165 ( & V_6 -> V_21 , NULL , type ,
V_160 + V_162 ,
V_161 - V_162 ) ;
else
F_107 ( L_47 ) ;
F_107 ( L_50 , V_6 -> V_104 ,
V_6 -> V_21 . type -> V_166 ) ;
F_31 (p, &pg->pgpaths, list) {
F_107 ( L_51 , V_93 -> V_17 . V_18 -> V_126 ,
V_93 -> V_3 ? L_52 : L_53 ,
V_93 -> V_127 ) ;
if ( V_6 -> V_21 . type -> V_165 )
V_162 += V_6 -> V_21 . type -> V_165 ( & V_6 -> V_21 ,
& V_93 -> V_17 , type , V_160 + V_162 ,
V_161 - V_162 ) ;
}
}
break;
case V_167 :
F_31 (pg, &m->priority_groups, list) {
F_107 ( L_54 , V_6 -> V_21 . type -> V_126 ) ;
if ( V_6 -> V_21 . type -> V_165 )
V_162 += V_6 -> V_21 . type -> V_165 ( & V_6 -> V_21 , NULL , type ,
V_160 + V_162 ,
V_161 - V_162 ) ;
else
F_107 ( L_47 ) ;
F_107 ( L_50 , V_6 -> V_104 ,
V_6 -> V_21 . type -> V_168 ) ;
F_31 (p, &pg->pgpaths, list) {
F_107 ( L_54 , V_93 -> V_17 . V_18 -> V_126 ) ;
if ( V_6 -> V_21 . type -> V_165 )
V_162 += V_6 -> V_21 . type -> V_165 ( & V_6 -> V_21 ,
& V_93 -> V_17 , type , V_160 + V_162 ,
V_161 - V_162 ) ;
}
}
break;
}
F_43 ( & V_13 -> V_25 , V_68 ) ;
}
static int F_108 ( struct V_9 * V_10 , unsigned V_96 , char * * V_92 )
{
int V_66 = - V_90 ;
struct V_131 * V_18 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
T_2 V_132 ;
F_103 ( & V_13 -> V_31 ) ;
if ( F_109 ( V_10 ) ) {
V_66 = - V_99 ;
goto V_125;
}
if ( V_96 == 1 ) {
if ( ! strcasecmp ( V_92 [ 0 ] , L_23 ) ) {
V_66 = V_61 ( V_13 , 1 , 0 ) ;
goto V_125;
} else if ( ! strcasecmp ( V_92 [ 0 ] , L_55 ) ) {
V_66 = V_61 ( V_13 , 0 , 0 ) ;
goto V_125;
}
}
if ( V_96 != 2 ) {
F_81 ( L_56 , V_96 ) ;
goto V_125;
}
if ( ! strcasecmp ( V_92 [ 0 ] , L_57 ) ) {
V_66 = F_89 ( V_13 , V_92 [ 1 ] , 1 ) ;
goto V_125;
} else if ( ! strcasecmp ( V_92 [ 0 ] , L_58 ) ) {
V_66 = F_89 ( V_13 , V_92 [ 1 ] , 0 ) ;
goto V_125;
} else if ( ! strcasecmp ( V_92 [ 0 ] , L_59 ) ) {
V_66 = F_88 ( V_13 , V_92 [ 1 ] ) ;
goto V_125;
} else if ( ! strcasecmp ( V_92 [ 0 ] , L_60 ) )
V_132 = F_84 ;
else if ( ! strcasecmp ( V_92 [ 0 ] , L_61 ) )
V_132 = F_80 ;
else {
F_81 ( L_62 , V_92 [ 0 ] ) ;
goto V_125;
}
V_66 = F_54 ( V_10 , V_92 [ 1 ] , F_55 ( V_10 -> V_80 ) , & V_18 ) ;
if ( V_66 ) {
F_81 ( L_63 ,
V_92 [ 1 ] ) ;
goto V_125;
}
V_66 = F_86 ( V_13 , V_18 , V_132 ) ;
F_13 ( V_10 , V_18 ) ;
V_125:
F_104 ( & V_13 -> V_31 ) ;
return V_66 ;
}
static int F_110 ( struct V_9 * V_10 , unsigned int V_169 ,
unsigned long V_170 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_1 * V_1 ;
struct V_69 * V_19 ;
T_4 V_171 ;
unsigned long V_68 ;
int V_66 ;
V_19 = NULL ;
V_171 = 0 ;
V_66 = 0 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( ! V_13 -> V_56 )
F_36 ( V_13 , 0 ) ;
V_1 = V_13 -> V_56 ;
if ( V_1 ) {
V_19 = V_1 -> V_17 . V_18 -> V_19 ;
V_171 = V_1 -> V_17 . V_18 -> V_171 ;
}
if ( ( V_1 && V_13 -> V_26 ) || ( ! V_1 && V_13 -> V_61 ) )
V_66 = - V_172 ;
else if ( ! V_19 )
V_66 = - V_70 ;
F_43 ( & V_13 -> V_25 , V_68 ) ;
if ( ! V_19 || V_10 -> V_110 != F_111 ( V_19 -> V_173 ) >> V_174 ) {
int V_175 = F_112 ( NULL , V_169 ) ;
if ( V_175 )
V_66 = V_175 ;
}
if ( V_66 == - V_172 && ! F_113 ( V_121 ) ) {
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( ! V_13 -> V_47 ) {
F_36 ( V_13 , 0 ) ;
}
if ( V_13 -> V_46 )
F_29 ( V_13 ) ;
F_43 ( & V_13 -> V_25 , V_68 ) ;
F_44 ( V_13 -> V_10 -> V_80 ) ;
}
return V_66 ? : F_114 ( V_19 , V_171 , V_169 , V_170 ) ;
}
static int F_115 ( struct V_9 * V_10 ,
T_5 V_176 , void * V_137 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_93 ;
int V_107 = 0 ;
F_31 (pg, &m->priority_groups, list) {
F_31 (p, &pg->pgpaths, list) {
V_107 = V_176 ( V_10 , V_93 -> V_17 . V_18 , V_10 -> V_177 , V_10 -> V_110 , V_137 ) ;
if ( V_107 )
goto V_125;
}
}
V_125:
return V_107 ;
}
static int F_116 ( struct V_1 * V_1 )
{
struct V_94 * V_72 = F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ;
return F_117 ( V_72 ) ;
}
static int F_118 ( struct V_9 * V_10 )
{
int V_178 = 0 , V_179 = 0 ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_68 ;
F_41 ( & V_13 -> V_25 , V_68 ) ;
if ( ! F_42 ( V_13 ) ) {
V_178 = 1 ;
goto V_125;
}
if ( F_119 ( ! V_13 -> V_56 && V_13 -> V_60 ) )
V_6 = V_13 -> V_60 ;
else if ( F_120 ( V_13 -> V_47 ) )
V_6 = V_13 -> V_47 ;
else
goto V_125;
V_178 = 1 ;
F_31 (pgpath, &pg->pgpaths, list)
if ( V_1 -> V_3 ) {
V_179 = 1 ;
if ( ! F_116 ( V_1 ) ) {
V_178 = 0 ;
break;
}
}
if ( ! V_179 )
V_178 = 0 ;
V_125:
F_43 ( & V_13 -> V_25 , V_68 ) ;
return V_178 ;
}
static int T_6 F_121 ( void )
{
int V_66 ;
V_33 = F_122 ( V_37 , 0 ) ;
if ( ! V_33 )
return - V_40 ;
V_66 = F_123 ( & V_180 ) ;
if ( V_66 < 0 ) {
F_92 ( L_64 , V_66 ) ;
F_124 ( V_33 ) ;
return - V_90 ;
}
V_124 = F_125 ( L_65 , V_181 , 0 ) ;
if ( ! V_124 ) {
F_92 ( L_66 ) ;
F_126 ( & V_180 ) ;
F_124 ( V_33 ) ;
return - V_40 ;
}
V_50 = F_127 ( L_67 ,
V_181 ) ;
if ( ! V_50 ) {
F_92 ( L_68 ) ;
F_128 ( V_124 ) ;
F_126 ( & V_180 ) ;
F_124 ( V_33 ) ;
return - V_40 ;
}
F_129 ( L_69 ,
V_180 . V_182 [ 0 ] , V_180 . V_182 [ 1 ] ,
V_180 . V_182 [ 2 ] ) ;
return V_66 ;
}
static void T_7 F_130 ( void )
{
F_128 ( V_50 ) ;
F_128 ( V_124 ) ;
F_126 ( & V_180 ) ;
F_124 ( V_33 ) ;
}
