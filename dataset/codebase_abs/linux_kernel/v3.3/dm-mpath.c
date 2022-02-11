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
V_13 = F_2 ( sizeof( * V_13 ) , V_2 ) ;
if ( V_13 ) {
F_7 ( & V_13 -> V_23 ) ;
F_7 ( & V_13 -> V_24 ) ;
F_17 ( & V_13 -> V_25 ) ;
V_13 -> V_26 = 1 ;
V_13 -> V_27 = V_28 ;
F_18 ( & V_13 -> V_29 , V_29 ) ;
F_18 ( & V_13 -> V_30 , V_30 ) ;
F_19 ( & V_13 -> V_31 ) ;
F_20 ( & V_13 -> V_32 ) ;
V_13 -> V_33 = F_21 ( V_34 , V_35 ) ;
if ( ! V_13 -> V_33 ) {
F_5 ( V_13 ) ;
return NULL ;
}
V_13 -> V_10 = V_10 ;
V_10 -> V_14 = V_13 ;
}
return V_13 ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_5 * V_6 , * V_11 ;
F_9 (pg, tmp, &m->priority_groups, list) {
F_10 ( & V_6 -> V_15 ) ;
F_14 ( V_6 , V_13 -> V_10 ) ;
}
F_5 ( V_13 -> V_16 ) ;
F_5 ( V_13 -> V_36 ) ;
F_23 ( V_13 -> V_33 ) ;
F_5 ( V_13 ) ;
}
static void F_24 ( struct V_12 * V_13 )
{
struct V_1 * V_1 ;
unsigned long V_37 = 0 ;
V_13 -> V_38 ++ ;
V_13 -> V_39 = 0 ;
if ( V_13 -> V_40 )
V_37 = F_25 ( V_13 -> V_27 != V_28 ?
V_13 -> V_27 : V_41 ) ;
F_26 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_27 ( V_42 , & V_1 -> V_4 ,
V_37 ) )
V_13 -> V_43 ++ ;
}
}
static void F_28 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
V_13 -> V_44 = V_1 -> V_6 ;
if ( V_13 -> V_16 ) {
V_13 -> V_39 = 1 ;
V_13 -> V_26 = 1 ;
} else {
V_13 -> V_39 = 0 ;
V_13 -> V_26 = 0 ;
}
V_13 -> V_38 = 0 ;
}
static int F_29 ( struct V_12 * V_13 , struct V_5 * V_6 ,
T_1 V_45 )
{
struct V_46 * V_17 ;
V_17 = V_6 -> V_21 . type -> V_47 ( & V_6 -> V_21 , & V_13 -> V_48 , V_45 ) ;
if ( ! V_17 )
return - V_49 ;
V_13 -> V_50 = F_30 ( V_17 ) ;
if ( V_13 -> V_44 != V_6 )
F_28 ( V_13 , V_13 -> V_50 ) ;
return 0 ;
}
static void F_31 ( struct V_12 * V_13 , T_1 V_45 )
{
struct V_5 * V_6 ;
unsigned V_51 = 1 ;
if ( ! V_13 -> V_52 )
goto V_53;
if ( V_13 -> V_54 ) {
V_6 = V_13 -> V_54 ;
V_13 -> V_54 = NULL ;
if ( ! F_29 ( V_13 , V_6 , V_45 ) )
return;
}
if ( V_13 -> V_44 && ! F_29 ( V_13 , V_13 -> V_44 , V_45 ) )
return;
do {
F_26 (pg, &m->priority_groups, list) {
if ( V_6 -> V_51 == V_51 )
continue;
if ( ! F_29 ( V_13 , V_6 , V_45 ) )
return;
}
} while ( V_51 -- );
V_53:
V_13 -> V_50 = NULL ;
V_13 -> V_44 = NULL ;
}
static int F_32 ( struct V_12 * V_13 )
{
return ( V_13 -> V_55 != V_13 -> V_56 &&
F_33 ( V_13 -> V_10 ) ) ;
}
static int F_34 ( struct V_12 * V_13 , struct V_57 * V_58 ,
struct V_59 * V_60 , unsigned V_61 )
{
int V_62 = V_63 ;
T_1 V_45 = F_35 ( V_58 ) ;
unsigned long V_64 ;
struct V_1 * V_1 ;
struct V_65 * V_19 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_13 -> V_50 ||
( ! V_13 -> V_26 && ( V_13 -> V_48 && -- V_13 -> V_48 == 0 ) ) )
F_31 ( V_13 , V_45 ) ;
V_1 = V_13 -> V_50 ;
if ( V_61 )
V_13 -> V_66 -- ;
if ( ( V_1 && V_13 -> V_26 ) ||
( ! V_1 && V_13 -> V_55 ) ) {
F_37 ( & V_58 -> V_67 , & V_13 -> V_24 ) ;
V_13 -> V_66 ++ ;
if ( ( V_13 -> V_39 && ! V_13 -> V_43 ) ||
! V_13 -> V_26 )
F_38 ( V_68 , & V_13 -> V_29 ) ;
V_1 = NULL ;
V_62 = V_69 ;
} else if ( V_1 ) {
V_19 = V_1 -> V_17 . V_18 -> V_19 ;
V_58 -> V_70 = F_12 ( V_19 ) ;
V_58 -> V_71 = V_19 -> V_72 ;
} else if ( F_32 ( V_13 ) )
V_62 = V_73 ;
else
V_62 = - V_74 ;
V_60 -> V_1 = V_1 ;
V_60 -> V_45 = V_45 ;
if ( V_62 == V_63 && V_1 -> V_6 -> V_21 . type -> V_75 )
V_1 -> V_6 -> V_21 . type -> V_75 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ,
V_45 ) ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_62 ;
}
static int V_55 ( struct V_12 * V_13 , unsigned V_55 ,
unsigned V_76 )
{
unsigned long V_64 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( V_76 )
V_13 -> V_56 = V_13 -> V_55 ;
else
V_13 -> V_56 = V_55 ;
V_13 -> V_55 = V_55 ;
if ( ! V_13 -> V_55 && V_13 -> V_66 )
F_38 ( V_68 , & V_13 -> V_29 ) ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
return 0 ;
}
static void F_40 ( struct V_12 * V_13 )
{
int V_62 ;
unsigned long V_64 ;
struct V_59 * V_60 ;
union V_77 * V_78 ;
struct V_57 * V_58 , * V_79 ;
F_41 ( V_80 ) ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
F_42 ( & V_13 -> V_24 , & V_80 ) ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
F_9 (clone, n, &cl, queuelist) {
F_43 ( & V_58 -> V_67 ) ;
V_78 = F_44 ( V_58 ) ;
V_60 = V_78 -> V_81 ;
V_62 = F_34 ( V_13 , V_58 , V_60 , 1 ) ;
if ( V_62 < 0 ) {
F_45 ( V_60 , V_13 -> V_33 ) ;
F_46 ( V_58 , V_62 ) ;
} else if ( V_62 == V_63 )
F_47 ( V_58 ) ;
else if ( V_62 == V_73 ) {
F_45 ( V_60 , V_13 -> V_33 ) ;
F_48 ( V_58 ) ;
}
}
}
static void V_29 ( struct V_82 * V_83 )
{
struct V_12 * V_13 =
F_49 ( V_83 , struct V_12 , V_29 ) ;
struct V_1 * V_1 = NULL ;
unsigned V_84 = 1 ;
unsigned long V_64 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_13 -> V_66 )
goto V_85;
if ( ! V_13 -> V_50 )
F_31 ( V_13 , 0 ) ;
V_1 = V_13 -> V_50 ;
if ( ( V_1 && ! V_13 -> V_26 ) ||
( ! V_1 && ! V_13 -> V_55 ) )
V_84 = 0 ;
if ( V_13 -> V_39 && ! V_13 -> V_43 && V_1 )
F_24 ( V_13 ) ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_84 )
F_40 ( V_13 ) ;
}
static void V_30 ( struct V_82 * V_83 )
{
struct V_12 * V_13 =
F_49 ( V_83 , struct V_12 , V_30 ) ;
F_50 ( V_13 -> V_10 -> V_86 ) ;
}
static int F_51 ( struct V_87 * V_88 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_62 ;
struct V_89 * V_90 ;
unsigned V_91 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_90 = F_52 ( F_53 ( V_88 ) ) ;
if ( ! V_90 ) {
V_10 -> error = L_2 ;
return - V_94 ;
}
V_62 = F_54 ( V_93 , V_88 , & V_91 , & V_10 -> error ) ;
if ( V_62 ) {
F_15 ( V_90 ) ;
return - V_94 ;
}
V_62 = V_90 -> V_95 ( & V_6 -> V_21 , V_91 , V_88 -> V_96 ) ;
if ( V_62 ) {
F_15 ( V_90 ) ;
V_10 -> error = L_3 ;
return V_62 ;
}
V_6 -> V_21 . type = V_90 ;
F_55 ( V_88 , V_91 ) ;
return 0 ;
}
static struct V_1 * F_56 ( struct V_87 * V_88 , struct V_20 * V_21 ,
struct V_9 * V_10 )
{
int V_62 ;
struct V_1 * V_97 ;
struct V_12 * V_13 = V_10 -> V_14 ;
if ( V_88 -> V_98 < 1 ) {
V_10 -> error = L_4 ;
return F_57 ( - V_94 ) ;
}
V_97 = F_1 () ;
if ( ! V_97 )
return F_57 ( - V_99 ) ;
V_62 = F_58 ( V_10 , F_53 ( V_88 ) , F_59 ( V_10 -> V_86 ) ,
& V_97 -> V_17 . V_18 ) ;
if ( V_62 ) {
V_10 -> error = L_5 ;
goto V_100;
}
if ( V_13 -> V_16 ) {
struct V_101 * V_70 = F_12 ( V_97 -> V_17 . V_18 -> V_19 ) ;
V_62 = F_60 ( V_70 , V_13 -> V_16 ) ;
if ( V_62 == - V_102 ) {
F_11 ( V_70 ) ;
V_62 = F_60 ( V_70 , V_13 -> V_16 ) ;
}
if ( V_62 < 0 ) {
V_10 -> error = L_6 ;
F_13 ( V_10 , V_97 -> V_17 . V_18 ) ;
goto V_100;
}
if ( V_13 -> V_36 ) {
V_62 = F_61 ( V_70 , V_13 -> V_36 ) ;
if ( V_62 < 0 ) {
V_10 -> error = L_7
L_8 ;
F_11 ( V_70 ) ;
F_13 ( V_10 , V_97 -> V_17 . V_18 ) ;
goto V_100;
}
}
}
V_62 = V_21 -> type -> V_103 ( V_21 , & V_97 -> V_17 , V_88 -> V_98 , V_88 -> V_96 , & V_10 -> error ) ;
if ( V_62 ) {
F_13 ( V_10 , V_97 -> V_17 . V_18 ) ;
goto V_100;
}
return V_97 ;
V_100:
F_4 ( V_97 ) ;
return F_57 ( V_62 ) ;
}
static struct V_5 * F_62 ( struct V_87 * V_88 ,
struct V_12 * V_13 )
{
static struct V_92 V_93 [] = {
{ 1 , 1024 , L_9 } ,
{ 0 , 1024 , L_10 }
} ;
int V_62 ;
unsigned V_104 , V_105 , V_106 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_13 -> V_10 ;
if ( V_88 -> V_98 < 2 ) {
V_88 -> V_98 = 0 ;
V_10 -> error = L_11 ;
return F_57 ( - V_94 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_12 ;
return F_57 ( - V_99 ) ;
}
V_6 -> V_13 = V_13 ;
V_62 = F_51 ( V_88 , V_6 , V_10 ) ;
if ( V_62 )
goto V_100;
V_62 = F_63 ( V_93 , V_88 , & V_6 -> V_107 , & V_10 -> error ) ;
if ( V_62 )
goto V_100;
V_62 = F_63 ( V_93 + 1 , V_88 , & V_105 , & V_10 -> error ) ;
if ( V_62 )
goto V_100;
V_106 = 1 + V_105 ;
for ( V_104 = 0 ; V_104 < V_6 -> V_107 ; V_104 ++ ) {
struct V_1 * V_1 ;
struct V_87 V_108 ;
if ( V_88 -> V_98 < V_106 ) {
V_10 -> error = L_13 ;
V_62 = - V_94 ;
goto V_100;
}
V_108 . V_98 = V_106 ;
V_108 . V_96 = V_88 -> V_96 ;
V_1 = F_56 ( & V_108 , & V_6 -> V_21 , V_10 ) ;
if ( F_64 ( V_1 ) ) {
V_62 = F_65 ( V_1 ) ;
goto V_100;
}
V_1 -> V_6 = V_6 ;
F_37 ( & V_1 -> V_15 , & V_6 -> V_7 ) ;
F_55 ( V_88 , V_106 ) ;
}
return V_6 ;
V_100:
F_14 ( V_6 , V_10 ) ;
return F_57 ( V_62 ) ;
}
static int F_66 ( struct V_87 * V_88 , struct V_12 * V_13 )
{
unsigned V_109 ;
int V_110 ;
struct V_9 * V_10 = V_13 -> V_10 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_14 } ,
} ;
if ( F_54 ( V_93 , V_88 , & V_109 , & V_10 -> error ) )
return - V_94 ;
if ( ! V_109 )
return 0 ;
V_13 -> V_16 = F_67 ( F_53 ( V_88 ) , V_2 ) ;
F_68 ( L_15 , V_13 -> V_16 ) ;
if ( F_69 ( V_13 -> V_16 ) == 0 ) {
V_10 -> error = L_16 ;
V_110 = - V_94 ;
goto V_111;
}
if ( V_109 > 1 ) {
char * V_97 ;
int V_104 , V_112 , V_113 = 4 ;
for ( V_104 = 0 ; V_104 <= V_109 - 2 ; V_104 ++ )
V_113 += strlen ( V_88 -> V_96 [ V_104 ] ) + 1 ;
V_97 = V_13 -> V_36 = F_2 ( V_113 , V_2 ) ;
if ( ! V_97 ) {
V_10 -> error = L_17 ;
V_110 = - V_99 ;
goto V_111;
}
V_112 = sprintf ( V_97 , L_18 , V_109 - 1 ) ;
for ( V_104 = 0 , V_97 += V_112 + 1 ; V_104 <= V_109 - 2 ; V_104 ++ , V_97 += V_112 + 1 )
V_112 = sprintf ( V_97 , L_19 , V_88 -> V_96 [ V_104 ] ) ;
}
F_55 ( V_88 , V_109 - 1 ) ;
return 0 ;
V_111:
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = NULL ;
return V_110 ;
}
static int F_70 ( struct V_87 * V_88 , struct V_12 * V_13 )
{
int V_62 ;
unsigned V_98 ;
struct V_9 * V_10 = V_13 -> V_10 ;
const char * V_114 ;
static struct V_92 V_93 [] = {
{ 0 , 5 , L_20 } ,
{ 1 , 50 , L_21 } ,
{ 0 , 60000 , L_22 } ,
} ;
V_62 = F_54 ( V_93 , V_88 , & V_98 , & V_10 -> error ) ;
if ( V_62 )
return - V_94 ;
if ( ! V_98 )
return 0 ;
do {
V_114 = F_53 ( V_88 ) ;
V_98 -- ;
if ( ! strcasecmp ( V_114 , L_23 ) ) {
V_62 = V_55 ( V_13 , 1 , 0 ) ;
continue;
}
if ( ! strcasecmp ( V_114 , L_24 ) &&
( V_98 >= 1 ) ) {
V_62 = F_63 ( V_93 + 1 , V_88 , & V_13 -> V_115 , & V_10 -> error ) ;
V_98 -- ;
continue;
}
if ( ! strcasecmp ( V_114 , L_25 ) &&
( V_98 >= 1 ) ) {
V_62 = F_63 ( V_93 + 2 , V_88 , & V_13 -> V_27 , & V_10 -> error ) ;
V_98 -- ;
continue;
}
V_10 -> error = L_26 ;
V_62 = - V_94 ;
} while ( V_98 && ! V_62 );
return V_62 ;
}
static int F_71 ( struct V_9 * V_10 , unsigned int V_98 ,
char * * V_96 )
{
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_27 } ,
{ 0 , 1024 , L_28 } ,
} ;
int V_62 ;
struct V_12 * V_13 ;
struct V_87 V_88 ;
unsigned V_116 = 0 ;
unsigned V_117 ;
V_88 . V_98 = V_98 ;
V_88 . V_96 = V_96 ;
V_13 = F_16 ( V_10 ) ;
if ( ! V_13 ) {
V_10 -> error = L_29 ;
return - V_94 ;
}
V_62 = F_70 ( & V_88 , V_13 ) ;
if ( V_62 )
goto V_100;
V_62 = F_66 ( & V_88 , V_13 ) ;
if ( V_62 )
goto V_100;
V_62 = F_63 ( V_93 , & V_88 , & V_13 -> V_118 , & V_10 -> error ) ;
if ( V_62 )
goto V_100;
V_62 = F_63 ( V_93 + 1 , & V_88 , & V_117 , & V_10 -> error ) ;
if ( V_62 )
goto V_100;
if ( ( ! V_13 -> V_118 && V_117 ) ||
( V_13 -> V_118 && ! V_117 ) ) {
V_10 -> error = L_30 ;
V_62 = - V_94 ;
goto V_100;
}
while ( V_88 . V_98 ) {
struct V_5 * V_6 ;
V_6 = F_62 ( & V_88 , V_13 ) ;
if ( F_64 ( V_6 ) ) {
V_62 = F_65 ( V_6 ) ;
goto V_100;
}
V_13 -> V_52 += V_6 -> V_107 ;
F_37 ( & V_6 -> V_15 , & V_13 -> V_23 ) ;
V_116 ++ ;
V_6 -> V_119 = V_116 ;
if ( ! -- V_117 )
V_13 -> V_54 = V_6 ;
}
if ( V_116 != V_13 -> V_118 ) {
V_10 -> error = L_31 ;
V_62 = - V_94 ;
goto V_100;
}
V_10 -> V_120 = 1 ;
V_10 -> V_121 = 1 ;
return 0 ;
V_100:
F_22 ( V_13 ) ;
return V_62 ;
}
static void F_72 ( struct V_12 * V_13 )
{
F_73 ( V_122 , V_123 ) ;
unsigned long V_64 ;
F_74 ( & V_13 -> V_31 , & V_122 ) ;
while ( 1 ) {
F_75 ( V_124 ) ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_13 -> V_43 ) {
F_39 ( & V_13 -> V_25 , V_64 ) ;
break;
}
F_39 ( & V_13 -> V_25 , V_64 ) ;
F_76 () ;
}
F_75 ( V_125 ) ;
F_77 ( & V_13 -> V_31 , & V_122 ) ;
}
static void F_78 ( struct V_12 * V_13 )
{
F_79 ( V_42 ) ;
F_72 ( V_13 ) ;
F_79 ( V_68 ) ;
F_80 ( & V_13 -> V_30 ) ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_78 ( V_13 ) ;
F_22 ( V_13 ) ;
}
static int F_82 ( struct V_9 * V_10 , struct V_57 * V_58 ,
union V_77 * V_126 )
{
int V_62 ;
struct V_59 * V_60 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
V_60 = F_83 ( V_13 -> V_33 , V_127 ) ;
if ( ! V_60 )
return V_73 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_126 -> V_81 = V_60 ;
V_58 -> V_128 |= V_129 ;
V_62 = F_34 ( V_13 , V_58 , V_60 , 0 ) ;
if ( V_62 < 0 || V_62 == V_73 )
F_45 ( V_60 , V_13 -> V_33 ) ;
return V_62 ;
}
static int F_84 ( struct V_1 * V_1 )
{
unsigned long V_64 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_1 -> V_3 )
goto V_85;
F_85 ( L_32 , V_1 -> V_17 . V_18 -> V_130 ) ;
V_1 -> V_6 -> V_21 . type -> F_84 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
V_1 -> V_3 = 0 ;
V_1 -> V_131 ++ ;
V_13 -> V_52 -- ;
if ( V_1 == V_13 -> V_50 )
V_13 -> V_50 = NULL ;
F_86 ( V_132 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_130 , V_13 -> V_52 ) ;
F_87 ( & V_13 -> V_30 ) ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_1 )
{
int V_62 = 0 ;
unsigned long V_64 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( V_1 -> V_3 )
goto V_85;
if ( ! V_1 -> V_6 -> V_21 . type -> F_88 ) {
F_85 ( L_33 ,
V_1 -> V_6 -> V_21 . type -> V_130 ) ;
V_62 = - V_94 ;
goto V_85;
}
V_62 = V_1 -> V_6 -> V_21 . type -> F_88 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
if ( V_62 )
goto V_85;
V_1 -> V_3 = 1 ;
if ( ! V_13 -> V_52 ++ && V_13 -> V_66 ) {
V_13 -> V_50 = NULL ;
F_38 ( V_68 , & V_13 -> V_29 ) ;
} else if ( V_13 -> V_16 && ( V_13 -> V_44 == V_1 -> V_6 ) ) {
if ( F_38 ( V_42 , & V_1 -> V_4 . V_83 ) )
V_13 -> V_43 ++ ;
}
F_86 ( V_133 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_130 , V_13 -> V_52 ) ;
F_87 ( & V_13 -> V_30 ) ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_62 ;
}
static int F_89 ( struct V_12 * V_13 , struct V_134 * V_18 ,
T_2 V_135 )
{
int V_62 = - V_94 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_26 (pg, &m->priority_groups, list) {
F_26 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_17 . V_18 == V_18 )
V_62 = V_135 ( V_1 ) ;
}
}
return V_62 ;
}
static void F_90 ( struct V_12 * V_13 , struct V_5 * V_6 ,
int V_51 )
{
unsigned long V_64 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
V_6 -> V_51 = V_51 ;
V_13 -> V_50 = NULL ;
V_13 -> V_44 = NULL ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
F_87 ( & V_13 -> V_30 ) ;
}
static int F_91 ( struct V_12 * V_13 , const char * V_136 )
{
struct V_5 * V_6 ;
unsigned V_137 ;
unsigned long V_64 ;
if ( ! V_136 || ( sscanf ( V_136 , L_34 , & V_137 ) != 1 ) || ! V_137 ||
( V_137 > V_13 -> V_118 ) ) {
F_85 ( L_35 ) ;
return - V_94 ;
}
F_36 ( & V_13 -> V_25 , V_64 ) ;
F_26 (pg, &m->priority_groups, list) {
V_6 -> V_51 = 0 ;
if ( -- V_137 )
continue;
V_13 -> V_50 = NULL ;
V_13 -> V_44 = NULL ;
V_13 -> V_54 = V_6 ;
}
F_39 ( & V_13 -> V_25 , V_64 ) ;
F_87 ( & V_13 -> V_30 ) ;
return 0 ;
}
static int F_92 ( struct V_12 * V_13 , const char * V_136 , int V_51 )
{
struct V_5 * V_6 ;
unsigned V_137 ;
if ( ! V_136 || ( sscanf ( V_136 , L_34 , & V_137 ) != 1 ) || ! V_137 ||
( V_137 > V_13 -> V_118 ) ) {
F_85 ( L_36 ) ;
return - V_94 ;
}
F_26 (pg, &m->priority_groups, list) {
if ( ! -- V_137 )
break;
}
F_90 ( V_13 , V_6 , V_51 ) ;
return 0 ;
}
static int F_93 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
unsigned long V_64 ;
int V_138 = 0 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( V_13 -> V_38 <= V_13 -> V_115 )
V_13 -> V_39 = 1 ;
else
V_138 = 1 ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_138 ;
}
static void F_94 ( void * V_139 , int V_140 )
{
struct V_1 * V_1 = V_139 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned long V_64 ;
unsigned V_141 = 0 ;
switch ( V_140 ) {
case V_142 :
break;
case V_143 :
if ( ! V_13 -> V_16 ) {
V_140 = 0 ;
break;
}
F_95 ( L_37
L_38 , V_13 -> V_16 , V_140 ) ;
F_84 ( V_1 ) ;
break;
case V_144 :
F_90 ( V_13 , V_6 , 1 ) ;
break;
case V_145 :
V_141 = 1 ;
case V_146 :
case V_147 :
if ( F_93 ( V_13 , V_1 ) )
F_84 ( V_1 ) ;
V_140 = 0 ;
break;
default:
F_84 ( V_1 ) ;
}
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( V_140 ) {
if ( V_1 == V_13 -> V_50 ) {
F_95 ( L_39 , V_140 ) ;
V_13 -> V_50 = NULL ;
V_13 -> V_44 = NULL ;
}
} else if ( ! V_13 -> V_39 )
V_6 -> V_51 = 0 ;
if ( -- V_13 -> V_43 )
goto V_85;
if ( ! V_13 -> V_39 )
V_13 -> V_26 = 0 ;
V_13 -> V_40 = V_141 ;
F_38 ( V_68 , & V_13 -> V_29 ) ;
F_96 ( & V_13 -> V_31 ) ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
}
static void V_4 ( struct V_82 * V_83 )
{
struct V_1 * V_1 =
F_49 ( V_83 , struct V_1 , V_4 . V_83 ) ;
F_97 ( F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ,
F_94 , V_1 ) ;
}
static int F_98 ( struct V_12 * V_13 , struct V_57 * V_58 ,
int error , struct V_59 * V_60 )
{
int V_62 = V_148 ;
unsigned long V_64 ;
if ( ! error && ! V_58 -> V_140 )
return 0 ;
if ( error == - V_149 || error == - V_150 || error == - V_151 )
return error ;
if ( V_60 -> V_1 )
F_84 ( V_60 -> V_1 ) ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_13 -> V_52 ) {
if ( ! V_13 -> V_55 ) {
if ( ! F_32 ( V_13 ) )
V_62 = - V_74 ;
} else {
if ( error == - V_152 )
V_62 = error ;
}
}
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_62 ;
}
static int F_99 ( struct V_9 * V_10 , struct V_57 * V_58 ,
int error , union V_77 * V_126 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_59 * V_60 = V_126 -> V_81 ;
struct V_1 * V_1 = V_60 -> V_1 ;
struct V_20 * V_21 ;
int V_62 ;
V_62 = F_98 ( V_13 , V_58 , error , V_60 ) ;
if ( V_1 ) {
V_21 = & V_1 -> V_6 -> V_21 ;
if ( V_21 -> type -> V_153 )
V_21 -> type -> V_153 ( V_21 , & V_1 -> V_17 , V_60 -> V_45 ) ;
}
F_45 ( V_60 , V_13 -> V_33 ) ;
return V_62 ;
}
static void F_100 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
V_55 ( V_13 , 0 , 1 ) ;
}
static void F_101 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_102 ( & V_13 -> V_32 ) ;
F_78 ( V_13 ) ;
F_103 ( & V_13 -> V_32 ) ;
}
static void F_104 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
unsigned long V_64 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
V_13 -> V_55 = V_13 -> V_56 ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
}
static int F_105 ( struct V_9 * V_10 , T_3 type ,
char * V_154 , unsigned int V_155 )
{
int V_156 = 0 ;
unsigned long V_64 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
unsigned V_119 ;
char V_157 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( type == V_158 )
F_106 ( L_40 , V_13 -> V_66 , V_13 -> V_38 ) ;
else {
F_106 ( L_41 , V_13 -> V_55 +
( V_13 -> V_115 > 0 ) * 2 +
( V_13 -> V_27 != V_28 ) * 2 ) ;
if ( V_13 -> V_55 )
F_106 ( L_42 ) ;
if ( V_13 -> V_115 )
F_106 ( L_43 , V_13 -> V_115 ) ;
if ( V_13 -> V_27 != V_28 )
F_106 ( L_44 , V_13 -> V_27 ) ;
}
if ( ! V_13 -> V_16 || type == V_158 )
F_106 ( L_45 ) ;
else
F_106 ( L_46 , V_13 -> V_16 ) ;
F_106 ( L_41 , V_13 -> V_118 ) ;
if ( V_13 -> V_54 )
V_119 = V_13 -> V_54 -> V_119 ;
else if ( V_13 -> V_44 )
V_119 = V_13 -> V_44 -> V_119 ;
else
V_119 = ( V_13 -> V_118 ? 1 : 0 ) ;
F_106 ( L_41 , V_119 ) ;
switch ( type ) {
case V_158 :
F_26 (pg, &m->priority_groups, list) {
if ( V_6 -> V_51 )
V_157 = 'D' ;
else if ( V_6 == V_13 -> V_44 )
V_157 = 'A' ;
else
V_157 = 'E' ;
F_106 ( L_47 , V_157 ) ;
if ( V_6 -> V_21 . type -> V_159 )
V_156 += V_6 -> V_21 . type -> V_159 ( & V_6 -> V_21 , NULL , type ,
V_154 + V_156 ,
V_155 - V_156 ) ;
else
F_106 ( L_45 ) ;
F_106 ( L_48 , V_6 -> V_107 ,
V_6 -> V_21 . type -> V_160 ) ;
F_26 (p, &pg->pgpaths, list) {
F_106 ( L_49 , V_97 -> V_17 . V_18 -> V_130 ,
V_97 -> V_3 ? L_50 : L_51 ,
V_97 -> V_131 ) ;
if ( V_6 -> V_21 . type -> V_159 )
V_156 += V_6 -> V_21 . type -> V_159 ( & V_6 -> V_21 ,
& V_97 -> V_17 , type , V_154 + V_156 ,
V_155 - V_156 ) ;
}
}
break;
case V_161 :
F_26 (pg, &m->priority_groups, list) {
F_106 ( L_52 , V_6 -> V_21 . type -> V_130 ) ;
if ( V_6 -> V_21 . type -> V_159 )
V_156 += V_6 -> V_21 . type -> V_159 ( & V_6 -> V_21 , NULL , type ,
V_154 + V_156 ,
V_155 - V_156 ) ;
else
F_106 ( L_45 ) ;
F_106 ( L_48 , V_6 -> V_107 ,
V_6 -> V_21 . type -> V_162 ) ;
F_26 (p, &pg->pgpaths, list) {
F_106 ( L_52 , V_97 -> V_17 . V_18 -> V_130 ) ;
if ( V_6 -> V_21 . type -> V_159 )
V_156 += V_6 -> V_21 . type -> V_159 ( & V_6 -> V_21 ,
& V_97 -> V_17 , type , V_154 + V_156 ,
V_155 - V_156 ) ;
}
}
break;
}
F_39 ( & V_13 -> V_25 , V_64 ) ;
return 0 ;
}
static int F_107 ( struct V_9 * V_10 , unsigned V_98 , char * * V_96 )
{
int V_62 = - V_94 ;
struct V_134 * V_18 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
T_2 V_135 ;
F_102 ( & V_13 -> V_32 ) ;
if ( F_108 ( V_10 ) ) {
V_62 = - V_102 ;
goto V_85;
}
if ( V_98 == 1 ) {
if ( ! strcasecmp ( V_96 [ 0 ] , L_23 ) ) {
V_62 = V_55 ( V_13 , 1 , 0 ) ;
goto V_85;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_53 ) ) {
V_62 = V_55 ( V_13 , 0 , 0 ) ;
goto V_85;
}
}
if ( V_98 != 2 ) {
F_85 ( L_54 ) ;
goto V_85;
}
if ( ! strcasecmp ( V_96 [ 0 ] , L_55 ) ) {
V_62 = F_92 ( V_13 , V_96 [ 1 ] , 1 ) ;
goto V_85;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_56 ) ) {
V_62 = F_92 ( V_13 , V_96 [ 1 ] , 0 ) ;
goto V_85;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_57 ) ) {
V_62 = F_91 ( V_13 , V_96 [ 1 ] ) ;
goto V_85;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_58 ) )
V_135 = F_88 ;
else if ( ! strcasecmp ( V_96 [ 0 ] , L_59 ) )
V_135 = F_84 ;
else {
F_85 ( L_54 ) ;
goto V_85;
}
V_62 = F_58 ( V_10 , V_96 [ 1 ] , F_59 ( V_10 -> V_86 ) , & V_18 ) ;
if ( V_62 ) {
F_85 ( L_60 ,
V_96 [ 1 ] ) ;
goto V_85;
}
V_62 = F_89 ( V_13 , V_18 , V_135 ) ;
F_13 ( V_10 , V_18 ) ;
V_85:
F_103 ( & V_13 -> V_32 ) ;
return V_62 ;
}
static int F_109 ( struct V_9 * V_10 , unsigned int V_163 ,
unsigned long V_164 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
struct V_65 * V_19 = NULL ;
T_4 V_165 = 0 ;
unsigned long V_64 ;
int V_62 = 0 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_13 -> V_50 )
F_31 ( V_13 , 0 ) ;
if ( V_13 -> V_50 ) {
V_19 = V_13 -> V_50 -> V_17 . V_18 -> V_19 ;
V_165 = V_13 -> V_50 -> V_17 . V_18 -> V_165 ;
}
if ( V_13 -> V_26 )
V_62 = - V_166 ;
else if ( ! V_19 )
V_62 = - V_74 ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_62 && V_10 -> V_113 != F_110 ( V_19 -> V_167 ) >> V_168 )
V_62 = F_111 ( NULL , V_163 ) ;
return V_62 ? : F_112 ( V_19 , V_165 , V_163 , V_164 ) ;
}
static int F_113 ( struct V_9 * V_10 ,
T_5 V_169 , void * V_139 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
int V_110 = 0 ;
F_26 (pg, &m->priority_groups, list) {
F_26 (p, &pg->pgpaths, list) {
V_110 = V_169 ( V_10 , V_97 -> V_17 . V_18 , V_10 -> V_170 , V_10 -> V_113 , V_139 ) ;
if ( V_110 )
goto V_85;
}
}
V_85:
return V_110 ;
}
static int F_114 ( struct V_1 * V_1 )
{
struct V_101 * V_70 = F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ;
return F_115 ( V_70 ) ;
}
static int F_116 ( struct V_9 * V_10 )
{
int V_171 = 0 , V_172 = 0 ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_64 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( F_117 ( ! V_13 -> V_50 && V_13 -> V_54 ) )
V_6 = V_13 -> V_54 ;
else if ( F_118 ( V_13 -> V_44 ) )
V_6 = V_13 -> V_44 ;
else
goto V_85;
V_171 = 1 ;
F_26 (pgpath, &pg->pgpaths, list)
if ( V_1 -> V_3 ) {
V_172 = 1 ;
if ( ! F_114 ( V_1 ) ) {
V_171 = 0 ;
break;
}
}
if ( ! V_172 )
V_171 = 0 ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_171 ;
}
static int T_6 F_119 ( void )
{
int V_62 ;
V_35 = F_120 ( V_59 , 0 ) ;
if ( ! V_35 )
return - V_99 ;
V_62 = F_121 ( & V_173 ) ;
if ( V_62 < 0 ) {
F_95 ( L_61 , V_62 ) ;
F_122 ( V_35 ) ;
return - V_94 ;
}
V_68 = F_123 ( L_62 , V_174 , 0 ) ;
if ( ! V_68 ) {
F_95 ( L_63 ) ;
F_124 ( & V_173 ) ;
F_122 ( V_35 ) ;
return - V_99 ;
}
V_42 = F_125 ( L_64 ,
V_174 ) ;
if ( ! V_42 ) {
F_95 ( L_65 ) ;
F_126 ( V_68 ) ;
F_124 ( & V_173 ) ;
F_122 ( V_35 ) ;
return - V_99 ;
}
F_127 ( L_66 ,
V_173 . V_175 [ 0 ] , V_173 . V_175 [ 1 ] ,
V_173 . V_175 [ 2 ] ) ;
return V_62 ;
}
static void T_7 F_128 ( void )
{
F_126 ( V_42 ) ;
F_126 ( V_68 ) ;
F_124 ( & V_173 ) ;
F_122 ( V_35 ) ;
}
