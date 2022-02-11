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
static int F_24 ( struct V_12 * V_13 , union V_37 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_25 ( V_13 -> V_33 , V_41 ) ;
if ( ! V_40 )
return - V_42 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_38 -> V_43 = V_40 ;
return 0 ;
}
static void F_26 ( struct V_12 * V_13 , union V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_43 ;
V_38 -> V_43 = NULL ;
F_27 ( V_40 , V_13 -> V_33 ) ;
}
static void F_28 ( struct V_12 * V_13 )
{
struct V_1 * V_1 ;
unsigned long V_44 = 0 ;
V_13 -> V_45 ++ ;
V_13 -> V_46 = 0 ;
if ( V_13 -> V_47 )
V_44 = F_29 ( V_13 -> V_27 != V_28 ?
V_13 -> V_27 : V_48 ) ;
F_30 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_31 ( V_49 , & V_1 -> V_4 ,
V_44 ) )
V_13 -> V_50 ++ ;
}
}
static void F_32 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
V_13 -> V_51 = V_1 -> V_6 ;
if ( V_13 -> V_16 ) {
V_13 -> V_46 = 1 ;
V_13 -> V_26 = 1 ;
} else {
V_13 -> V_46 = 0 ;
V_13 -> V_26 = 0 ;
}
V_13 -> V_45 = 0 ;
}
static int F_33 ( struct V_12 * V_13 , struct V_5 * V_6 ,
T_1 V_52 )
{
struct V_53 * V_17 ;
V_17 = V_6 -> V_21 . type -> V_54 ( & V_6 -> V_21 , & V_13 -> V_55 , V_52 ) ;
if ( ! V_17 )
return - V_56 ;
V_13 -> V_57 = F_34 ( V_17 ) ;
if ( V_13 -> V_51 != V_6 )
F_32 ( V_13 , V_13 -> V_57 ) ;
return 0 ;
}
static void F_35 ( struct V_12 * V_13 , T_1 V_52 )
{
struct V_5 * V_6 ;
unsigned V_58 = 1 ;
if ( ! V_13 -> V_59 )
goto V_60;
if ( V_13 -> V_61 ) {
V_6 = V_13 -> V_61 ;
V_13 -> V_61 = NULL ;
if ( ! F_33 ( V_13 , V_6 , V_52 ) )
return;
}
if ( V_13 -> V_51 && ! F_33 ( V_13 , V_13 -> V_51 , V_52 ) )
return;
do {
F_30 (pg, &m->priority_groups, list) {
if ( V_6 -> V_58 == V_58 )
continue;
if ( ! F_33 ( V_13 , V_6 , V_52 ) ) {
if ( ! V_58 )
V_13 -> V_47 = 1 ;
return;
}
}
} while ( V_58 -- );
V_60:
V_13 -> V_57 = NULL ;
V_13 -> V_51 = NULL ;
}
static int F_36 ( struct V_12 * V_13 )
{
return ( V_13 -> V_62 != V_13 -> V_63 &&
F_37 ( V_13 -> V_10 ) ) ;
}
static int F_38 ( struct V_12 * V_13 , struct V_64 * V_65 ,
union V_37 * V_66 , unsigned V_67 )
{
int V_68 = V_69 ;
T_1 V_52 = F_39 ( V_65 ) ;
unsigned long V_70 ;
struct V_1 * V_1 ;
struct V_71 * V_19 ;
struct V_39 * V_40 = V_66 -> V_43 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_13 -> V_57 ||
( ! V_13 -> V_26 && ( V_13 -> V_55 && -- V_13 -> V_55 == 0 ) ) )
F_35 ( V_13 , V_52 ) ;
V_1 = V_13 -> V_57 ;
if ( V_67 )
V_13 -> V_72 -- ;
if ( ( V_1 && V_13 -> V_26 ) ||
( ! V_1 && V_13 -> V_62 ) ) {
F_41 ( & V_65 -> V_73 , & V_13 -> V_24 ) ;
V_13 -> V_72 ++ ;
if ( ( V_13 -> V_46 && ! V_13 -> V_50 ) ||
! V_13 -> V_26 )
F_42 ( V_74 , & V_13 -> V_29 ) ;
V_1 = NULL ;
V_68 = V_75 ;
} else if ( V_1 ) {
V_19 = V_1 -> V_17 . V_18 -> V_19 ;
V_65 -> V_76 = F_12 ( V_19 ) ;
V_65 -> V_77 = V_19 -> V_78 ;
} else if ( F_36 ( V_13 ) )
V_68 = V_79 ;
else
V_68 = - V_80 ;
V_40 -> V_1 = V_1 ;
V_40 -> V_52 = V_52 ;
if ( V_68 == V_69 && V_1 -> V_6 -> V_21 . type -> V_81 )
V_1 -> V_6 -> V_21 . type -> V_81 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ,
V_52 ) ;
F_43 ( & V_13 -> V_25 , V_70 ) ;
return V_68 ;
}
static int V_62 ( struct V_12 * V_13 , unsigned V_62 ,
unsigned V_82 )
{
unsigned long V_70 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( V_82 )
V_13 -> V_63 = V_13 -> V_62 ;
else
V_13 -> V_63 = V_62 ;
V_13 -> V_62 = V_62 ;
if ( ! V_13 -> V_62 && V_13 -> V_72 )
F_42 ( V_74 , & V_13 -> V_29 ) ;
F_43 ( & V_13 -> V_25 , V_70 ) ;
return 0 ;
}
static void F_44 ( struct V_12 * V_13 )
{
int V_68 ;
unsigned long V_70 ;
union V_37 * V_38 ;
struct V_64 * V_65 , * V_83 ;
F_45 ( V_84 ) ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
F_46 ( & V_13 -> V_24 , & V_84 ) ;
F_43 ( & V_13 -> V_25 , V_70 ) ;
F_9 (clone, n, &cl, queuelist) {
F_47 ( & V_65 -> V_73 ) ;
V_38 = F_48 ( V_65 ) ;
V_68 = F_38 ( V_13 , V_65 , V_38 , 1 ) ;
if ( V_68 < 0 ) {
F_26 ( V_13 , V_38 ) ;
F_49 ( V_65 , V_68 ) ;
} else if ( V_68 == V_69 )
F_50 ( V_65 ) ;
else if ( V_68 == V_79 ) {
F_26 ( V_13 , V_38 ) ;
F_51 ( V_65 ) ;
}
}
}
static void V_29 ( struct V_85 * V_86 )
{
struct V_12 * V_13 =
F_52 ( V_86 , struct V_12 , V_29 ) ;
struct V_1 * V_1 = NULL ;
unsigned V_87 = 1 ;
unsigned long V_70 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_13 -> V_57 )
F_35 ( V_13 , 0 ) ;
V_1 = V_13 -> V_57 ;
if ( ( V_1 && ! V_13 -> V_26 ) ||
( ! V_1 && ! V_13 -> V_62 ) )
V_87 = 0 ;
if ( V_13 -> V_46 && ! V_13 -> V_50 && V_1 )
F_28 ( V_13 ) ;
F_43 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_87 )
F_44 ( V_13 ) ;
}
static void V_30 ( struct V_85 * V_86 )
{
struct V_12 * V_13 =
F_52 ( V_86 , struct V_12 , V_30 ) ;
F_53 ( V_13 -> V_10 -> V_88 ) ;
}
static int F_54 ( struct V_89 * V_90 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_68 ;
struct V_91 * V_92 ;
unsigned V_93 ;
static struct V_94 V_95 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_92 = F_55 ( F_56 ( V_90 ) ) ;
if ( ! V_92 ) {
V_10 -> error = L_2 ;
return - V_96 ;
}
V_68 = F_57 ( V_95 , V_90 , & V_93 , & V_10 -> error ) ;
if ( V_68 ) {
F_15 ( V_92 ) ;
return - V_96 ;
}
V_68 = V_92 -> V_97 ( & V_6 -> V_21 , V_93 , V_90 -> V_98 ) ;
if ( V_68 ) {
F_15 ( V_92 ) ;
V_10 -> error = L_3 ;
return V_68 ;
}
V_6 -> V_21 . type = V_92 ;
F_58 ( V_90 , V_93 ) ;
return 0 ;
}
static struct V_1 * F_59 ( struct V_89 * V_90 , struct V_20 * V_21 ,
struct V_9 * V_10 )
{
int V_68 ;
struct V_1 * V_99 ;
struct V_12 * V_13 = V_10 -> V_14 ;
if ( V_90 -> V_100 < 1 ) {
V_10 -> error = L_4 ;
return F_60 ( - V_96 ) ;
}
V_99 = F_1 () ;
if ( ! V_99 )
return F_60 ( - V_42 ) ;
V_68 = F_61 ( V_10 , F_56 ( V_90 ) , F_62 ( V_10 -> V_88 ) ,
& V_99 -> V_17 . V_18 ) ;
if ( V_68 ) {
V_10 -> error = L_5 ;
goto V_101;
}
if ( V_13 -> V_16 ) {
struct V_102 * V_76 = F_12 ( V_99 -> V_17 . V_18 -> V_19 ) ;
V_68 = F_63 ( V_76 , V_13 -> V_16 ) ;
if ( V_68 == - V_103 ) {
F_11 ( V_76 ) ;
V_68 = F_63 ( V_76 , V_13 -> V_16 ) ;
}
if ( V_68 < 0 ) {
V_10 -> error = L_6 ;
F_13 ( V_10 , V_99 -> V_17 . V_18 ) ;
goto V_101;
}
if ( V_13 -> V_36 ) {
V_68 = F_64 ( V_76 , V_13 -> V_36 ) ;
if ( V_68 < 0 ) {
V_10 -> error = L_7
L_8 ;
F_11 ( V_76 ) ;
F_13 ( V_10 , V_99 -> V_17 . V_18 ) ;
goto V_101;
}
}
}
V_68 = V_21 -> type -> V_104 ( V_21 , & V_99 -> V_17 , V_90 -> V_100 , V_90 -> V_98 , & V_10 -> error ) ;
if ( V_68 ) {
F_13 ( V_10 , V_99 -> V_17 . V_18 ) ;
goto V_101;
}
return V_99 ;
V_101:
F_4 ( V_99 ) ;
return F_60 ( V_68 ) ;
}
static struct V_5 * F_65 ( struct V_89 * V_90 ,
struct V_12 * V_13 )
{
static struct V_94 V_95 [] = {
{ 1 , 1024 , L_9 } ,
{ 0 , 1024 , L_10 }
} ;
int V_68 ;
unsigned V_105 , V_106 , V_107 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_13 -> V_10 ;
if ( V_90 -> V_100 < 2 ) {
V_90 -> V_100 = 0 ;
V_10 -> error = L_11 ;
return F_60 ( - V_96 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_12 ;
return F_60 ( - V_42 ) ;
}
V_6 -> V_13 = V_13 ;
V_68 = F_54 ( V_90 , V_6 , V_10 ) ;
if ( V_68 )
goto V_101;
V_68 = F_66 ( V_95 , V_90 , & V_6 -> V_108 , & V_10 -> error ) ;
if ( V_68 )
goto V_101;
V_68 = F_66 ( V_95 + 1 , V_90 , & V_106 , & V_10 -> error ) ;
if ( V_68 )
goto V_101;
V_107 = 1 + V_106 ;
for ( V_105 = 0 ; V_105 < V_6 -> V_108 ; V_105 ++ ) {
struct V_1 * V_1 ;
struct V_89 V_109 ;
if ( V_90 -> V_100 < V_107 ) {
V_10 -> error = L_13 ;
V_68 = - V_96 ;
goto V_101;
}
V_109 . V_100 = V_107 ;
V_109 . V_98 = V_90 -> V_98 ;
V_1 = F_59 ( & V_109 , & V_6 -> V_21 , V_10 ) ;
if ( F_67 ( V_1 ) ) {
V_68 = F_68 ( V_1 ) ;
goto V_101;
}
V_1 -> V_6 = V_6 ;
F_41 ( & V_1 -> V_15 , & V_6 -> V_7 ) ;
F_58 ( V_90 , V_107 ) ;
}
return V_6 ;
V_101:
F_14 ( V_6 , V_10 ) ;
return F_60 ( V_68 ) ;
}
static int F_69 ( struct V_89 * V_90 , struct V_12 * V_13 )
{
unsigned V_110 ;
int V_111 ;
struct V_9 * V_10 = V_13 -> V_10 ;
static struct V_94 V_95 [] = {
{ 0 , 1024 , L_14 } ,
} ;
if ( F_57 ( V_95 , V_90 , & V_110 , & V_10 -> error ) )
return - V_96 ;
if ( ! V_110 )
return 0 ;
V_13 -> V_16 = F_70 ( F_56 ( V_90 ) , V_2 ) ;
if ( ! F_71 ( F_72 ( V_13 -> V_16 ) ,
L_15 , V_13 -> V_16 ) ) {
V_10 -> error = L_16 ;
V_111 = - V_96 ;
goto V_112;
}
if ( V_110 > 1 ) {
char * V_99 ;
int V_105 , V_113 , V_114 = 4 ;
for ( V_105 = 0 ; V_105 <= V_110 - 2 ; V_105 ++ )
V_114 += strlen ( V_90 -> V_98 [ V_105 ] ) + 1 ;
V_99 = V_13 -> V_36 = F_2 ( V_114 , V_2 ) ;
if ( ! V_99 ) {
V_10 -> error = L_17 ;
V_111 = - V_42 ;
goto V_112;
}
V_113 = sprintf ( V_99 , L_18 , V_110 - 1 ) ;
for ( V_105 = 0 , V_99 += V_113 + 1 ; V_105 <= V_110 - 2 ; V_105 ++ , V_99 += V_113 + 1 )
V_113 = sprintf ( V_99 , L_19 , V_90 -> V_98 [ V_105 ] ) ;
}
F_58 ( V_90 , V_110 - 1 ) ;
return 0 ;
V_112:
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = NULL ;
return V_111 ;
}
static int F_73 ( struct V_89 * V_90 , struct V_12 * V_13 )
{
int V_68 ;
unsigned V_100 ;
struct V_9 * V_10 = V_13 -> V_10 ;
const char * V_115 ;
static struct V_94 V_95 [] = {
{ 0 , 5 , L_20 } ,
{ 1 , 50 , L_21 } ,
{ 0 , 60000 , L_22 } ,
} ;
V_68 = F_57 ( V_95 , V_90 , & V_100 , & V_10 -> error ) ;
if ( V_68 )
return - V_96 ;
if ( ! V_100 )
return 0 ;
do {
V_115 = F_56 ( V_90 ) ;
V_100 -- ;
if ( ! strcasecmp ( V_115 , L_23 ) ) {
V_68 = V_62 ( V_13 , 1 , 0 ) ;
continue;
}
if ( ! strcasecmp ( V_115 , L_24 ) &&
( V_100 >= 1 ) ) {
V_68 = F_66 ( V_95 + 1 , V_90 , & V_13 -> V_116 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
if ( ! strcasecmp ( V_115 , L_25 ) &&
( V_100 >= 1 ) ) {
V_68 = F_66 ( V_95 + 2 , V_90 , & V_13 -> V_27 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
V_10 -> error = L_26 ;
V_68 = - V_96 ;
} while ( V_100 && ! V_68 );
return V_68 ;
}
static int F_74 ( struct V_9 * V_10 , unsigned int V_100 ,
char * * V_98 )
{
static struct V_94 V_95 [] = {
{ 0 , 1024 , L_27 } ,
{ 0 , 1024 , L_28 } ,
} ;
int V_68 ;
struct V_12 * V_13 ;
struct V_89 V_90 ;
unsigned V_117 = 0 ;
unsigned V_118 ;
V_90 . V_100 = V_100 ;
V_90 . V_98 = V_98 ;
V_13 = F_16 ( V_10 ) ;
if ( ! V_13 ) {
V_10 -> error = L_29 ;
return - V_96 ;
}
V_68 = F_73 ( & V_90 , V_13 ) ;
if ( V_68 )
goto V_101;
V_68 = F_69 ( & V_90 , V_13 ) ;
if ( V_68 )
goto V_101;
V_68 = F_66 ( V_95 , & V_90 , & V_13 -> V_119 , & V_10 -> error ) ;
if ( V_68 )
goto V_101;
V_68 = F_66 ( V_95 + 1 , & V_90 , & V_118 , & V_10 -> error ) ;
if ( V_68 )
goto V_101;
if ( ( ! V_13 -> V_119 && V_118 ) ||
( V_13 -> V_119 && ! V_118 ) ) {
V_10 -> error = L_30 ;
V_68 = - V_96 ;
goto V_101;
}
while ( V_90 . V_100 ) {
struct V_5 * V_6 ;
V_6 = F_65 ( & V_90 , V_13 ) ;
if ( F_67 ( V_6 ) ) {
V_68 = F_68 ( V_6 ) ;
goto V_101;
}
V_13 -> V_59 += V_6 -> V_108 ;
F_41 ( & V_6 -> V_15 , & V_13 -> V_23 ) ;
V_117 ++ ;
V_6 -> V_120 = V_117 ;
if ( ! -- V_118 )
V_13 -> V_61 = V_6 ;
}
if ( V_117 != V_13 -> V_119 ) {
V_10 -> error = L_31 ;
V_68 = - V_96 ;
goto V_101;
}
V_10 -> V_121 = 1 ;
V_10 -> V_122 = 1 ;
return 0 ;
V_101:
F_22 ( V_13 ) ;
return V_68 ;
}
static void F_75 ( struct V_12 * V_13 )
{
F_76 ( V_123 , V_124 ) ;
unsigned long V_70 ;
F_77 ( & V_13 -> V_31 , & V_123 ) ;
while ( 1 ) {
F_78 ( V_125 ) ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_13 -> V_50 ) {
F_43 ( & V_13 -> V_25 , V_70 ) ;
break;
}
F_43 ( & V_13 -> V_25 , V_70 ) ;
F_79 () ;
}
F_78 ( V_126 ) ;
F_80 ( & V_13 -> V_31 , & V_123 ) ;
}
static void F_81 ( struct V_12 * V_13 )
{
F_82 ( V_49 ) ;
F_75 ( V_13 ) ;
F_82 ( V_74 ) ;
F_83 ( & V_13 -> V_30 ) ;
}
static void F_84 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_81 ( V_13 ) ;
F_22 ( V_13 ) ;
}
static int F_85 ( struct V_9 * V_10 , struct V_64 * V_65 ,
union V_37 * V_66 )
{
int V_68 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
if ( F_24 ( V_13 , V_66 ) < 0 )
return V_79 ;
V_65 -> V_127 |= V_128 ;
V_68 = F_38 ( V_13 , V_65 , V_66 , 0 ) ;
if ( V_68 < 0 || V_68 == V_79 )
F_26 ( V_13 , V_66 ) ;
return V_68 ;
}
static int F_86 ( struct V_1 * V_1 )
{
unsigned long V_70 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_1 -> V_3 )
goto V_129;
F_87 ( L_32 , V_1 -> V_17 . V_18 -> V_130 ) ;
V_1 -> V_6 -> V_21 . type -> F_86 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
V_1 -> V_3 = 0 ;
V_1 -> V_131 ++ ;
V_13 -> V_59 -- ;
if ( V_1 == V_13 -> V_57 )
V_13 -> V_57 = NULL ;
F_88 ( V_132 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_130 , V_13 -> V_59 ) ;
F_89 ( & V_13 -> V_30 ) ;
V_129:
F_43 ( & V_13 -> V_25 , V_70 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_1 )
{
int V_68 = 0 ;
unsigned long V_70 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( V_1 -> V_3 )
goto V_129;
if ( ! V_1 -> V_6 -> V_21 . type -> F_90 ) {
F_87 ( L_33 ,
V_1 -> V_6 -> V_21 . type -> V_130 ) ;
V_68 = - V_96 ;
goto V_129;
}
V_68 = V_1 -> V_6 -> V_21 . type -> F_90 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
if ( V_68 )
goto V_129;
V_1 -> V_3 = 1 ;
if ( ! V_13 -> V_59 ++ && V_13 -> V_72 ) {
V_13 -> V_57 = NULL ;
F_42 ( V_74 , & V_13 -> V_29 ) ;
} else if ( V_13 -> V_16 && ( V_13 -> V_51 == V_1 -> V_6 ) ) {
if ( F_42 ( V_49 , & V_1 -> V_4 . V_86 ) )
V_13 -> V_50 ++ ;
}
F_88 ( V_133 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_130 , V_13 -> V_59 ) ;
F_89 ( & V_13 -> V_30 ) ;
V_129:
F_43 ( & V_13 -> V_25 , V_70 ) ;
return V_68 ;
}
static int F_91 ( struct V_12 * V_13 , struct V_134 * V_18 ,
T_2 V_135 )
{
int V_68 = - V_96 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_30 (pg, &m->priority_groups, list) {
F_30 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_17 . V_18 == V_18 )
V_68 = V_135 ( V_1 ) ;
}
}
return V_68 ;
}
static void F_92 ( struct V_12 * V_13 , struct V_5 * V_6 ,
int V_58 )
{
unsigned long V_70 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
V_6 -> V_58 = V_58 ;
V_13 -> V_57 = NULL ;
V_13 -> V_51 = NULL ;
F_43 ( & V_13 -> V_25 , V_70 ) ;
F_89 ( & V_13 -> V_30 ) ;
}
static int F_93 ( struct V_12 * V_13 , const char * V_136 )
{
struct V_5 * V_6 ;
unsigned V_137 ;
unsigned long V_70 ;
char V_138 ;
if ( ! V_136 || ( sscanf ( V_136 , L_34 , & V_137 , & V_138 ) != 1 ) || ! V_137 ||
( V_137 > V_13 -> V_119 ) ) {
F_87 ( L_35 ) ;
return - V_96 ;
}
F_40 ( & V_13 -> V_25 , V_70 ) ;
F_30 (pg, &m->priority_groups, list) {
V_6 -> V_58 = 0 ;
if ( -- V_137 )
continue;
V_13 -> V_57 = NULL ;
V_13 -> V_51 = NULL ;
V_13 -> V_61 = V_6 ;
}
F_43 ( & V_13 -> V_25 , V_70 ) ;
F_89 ( & V_13 -> V_30 ) ;
return 0 ;
}
static int F_94 ( struct V_12 * V_13 , const char * V_136 , int V_58 )
{
struct V_5 * V_6 ;
unsigned V_137 ;
char V_138 ;
if ( ! V_136 || ( sscanf ( V_136 , L_34 , & V_137 , & V_138 ) != 1 ) || ! V_137 ||
( V_137 > V_13 -> V_119 ) ) {
F_87 ( L_36 ) ;
return - V_96 ;
}
F_30 (pg, &m->priority_groups, list) {
if ( ! -- V_137 )
break;
}
F_92 ( V_13 , V_6 , V_58 ) ;
return 0 ;
}
static int F_95 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
unsigned long V_70 ;
int V_139 = 0 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( V_13 -> V_45 <= V_13 -> V_116 )
V_13 -> V_46 = 1 ;
else
V_139 = 1 ;
F_43 ( & V_13 -> V_25 , V_70 ) ;
return V_139 ;
}
static void F_96 ( void * V_140 , int V_141 )
{
struct V_1 * V_1 = V_140 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned long V_70 ;
unsigned V_142 = 0 ;
switch ( V_141 ) {
case V_143 :
break;
case V_144 :
if ( ! V_13 -> V_16 ) {
V_141 = 0 ;
break;
}
F_97 ( L_37
L_38 , V_13 -> V_16 , V_141 ) ;
F_86 ( V_1 ) ;
break;
case V_145 :
F_92 ( V_13 , V_6 , 1 ) ;
break;
case V_146 :
V_142 = 1 ;
case V_147 :
case V_148 :
if ( F_95 ( V_13 , V_1 ) )
F_86 ( V_1 ) ;
V_141 = 0 ;
break;
default:
F_86 ( V_1 ) ;
}
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( V_141 ) {
if ( V_1 == V_13 -> V_57 ) {
F_97 ( L_39 , V_141 ) ;
V_13 -> V_57 = NULL ;
V_13 -> V_51 = NULL ;
}
} else if ( ! V_13 -> V_46 )
V_6 -> V_58 = 0 ;
if ( -- V_13 -> V_50 )
goto V_129;
if ( ! V_13 -> V_46 )
V_13 -> V_26 = 0 ;
V_13 -> V_47 = V_142 ;
F_42 ( V_74 , & V_13 -> V_29 ) ;
F_98 ( & V_13 -> V_31 ) ;
V_129:
F_43 ( & V_13 -> V_25 , V_70 ) ;
}
static void V_4 ( struct V_85 * V_86 )
{
struct V_1 * V_1 =
F_52 ( V_86 , struct V_1 , V_4 . V_86 ) ;
F_99 ( F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ,
F_96 , V_1 ) ;
}
static int F_100 ( struct V_12 * V_13 , struct V_64 * V_65 ,
int error , struct V_39 * V_40 )
{
int V_68 = V_149 ;
unsigned long V_70 ;
if ( ! error && ! V_65 -> V_141 )
return 0 ;
if ( error == - V_150 || error == - V_151 || error == - V_152 )
return error ;
if ( V_40 -> V_1 )
F_86 ( V_40 -> V_1 ) ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_13 -> V_59 ) {
if ( ! V_13 -> V_62 ) {
if ( ! F_36 ( V_13 ) )
V_68 = - V_80 ;
} else {
if ( error == - V_153 )
V_68 = error ;
}
}
F_43 ( & V_13 -> V_25 , V_70 ) ;
return V_68 ;
}
static int F_101 ( struct V_9 * V_10 , struct V_64 * V_65 ,
int error , union V_37 * V_66 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_39 * V_40 = V_66 -> V_43 ;
struct V_1 * V_1 = V_40 -> V_1 ;
struct V_20 * V_21 ;
int V_68 ;
F_102 ( ! V_40 ) ;
V_68 = F_100 ( V_13 , V_65 , error , V_40 ) ;
if ( V_1 ) {
V_21 = & V_1 -> V_6 -> V_21 ;
if ( V_21 -> type -> V_154 )
V_21 -> type -> V_154 ( V_21 , & V_1 -> V_17 , V_40 -> V_52 ) ;
}
F_26 ( V_13 , V_66 ) ;
return V_68 ;
}
static void F_103 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
V_62 ( V_13 , 0 , 1 ) ;
}
static void F_104 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_105 ( & V_13 -> V_32 ) ;
F_81 ( V_13 ) ;
F_106 ( & V_13 -> V_32 ) ;
}
static void F_107 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
unsigned long V_70 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
V_13 -> V_62 = V_13 -> V_63 ;
F_43 ( & V_13 -> V_25 , V_70 ) ;
}
static int F_108 ( struct V_9 * V_10 , T_3 type ,
char * V_155 , unsigned int V_156 )
{
int V_157 = 0 ;
unsigned long V_70 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_99 ;
unsigned V_120 ;
char V_158 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( type == V_159 )
F_109 ( L_40 , V_13 -> V_72 , V_13 -> V_45 ) ;
else {
F_109 ( L_41 , V_13 -> V_62 +
( V_13 -> V_116 > 0 ) * 2 +
( V_13 -> V_27 != V_28 ) * 2 ) ;
if ( V_13 -> V_62 )
F_109 ( L_42 ) ;
if ( V_13 -> V_116 )
F_109 ( L_43 , V_13 -> V_116 ) ;
if ( V_13 -> V_27 != V_28 )
F_109 ( L_44 , V_13 -> V_27 ) ;
}
if ( ! V_13 -> V_16 || type == V_159 )
F_109 ( L_45 ) ;
else
F_109 ( L_46 , V_13 -> V_16 ) ;
F_109 ( L_41 , V_13 -> V_119 ) ;
if ( V_13 -> V_61 )
V_120 = V_13 -> V_61 -> V_120 ;
else if ( V_13 -> V_51 )
V_120 = V_13 -> V_51 -> V_120 ;
else
V_120 = ( V_13 -> V_119 ? 1 : 0 ) ;
F_109 ( L_41 , V_120 ) ;
switch ( type ) {
case V_159 :
F_30 (pg, &m->priority_groups, list) {
if ( V_6 -> V_58 )
V_158 = 'D' ;
else if ( V_6 == V_13 -> V_51 )
V_158 = 'A' ;
else
V_158 = 'E' ;
F_109 ( L_47 , V_158 ) ;
if ( V_6 -> V_21 . type -> V_160 )
V_157 += V_6 -> V_21 . type -> V_160 ( & V_6 -> V_21 , NULL , type ,
V_155 + V_157 ,
V_156 - V_157 ) ;
else
F_109 ( L_45 ) ;
F_109 ( L_48 , V_6 -> V_108 ,
V_6 -> V_21 . type -> V_161 ) ;
F_30 (p, &pg->pgpaths, list) {
F_109 ( L_49 , V_99 -> V_17 . V_18 -> V_130 ,
V_99 -> V_3 ? L_50 : L_51 ,
V_99 -> V_131 ) ;
if ( V_6 -> V_21 . type -> V_160 )
V_157 += V_6 -> V_21 . type -> V_160 ( & V_6 -> V_21 ,
& V_99 -> V_17 , type , V_155 + V_157 ,
V_156 - V_157 ) ;
}
}
break;
case V_162 :
F_30 (pg, &m->priority_groups, list) {
F_109 ( L_52 , V_6 -> V_21 . type -> V_130 ) ;
if ( V_6 -> V_21 . type -> V_160 )
V_157 += V_6 -> V_21 . type -> V_160 ( & V_6 -> V_21 , NULL , type ,
V_155 + V_157 ,
V_156 - V_157 ) ;
else
F_109 ( L_45 ) ;
F_109 ( L_48 , V_6 -> V_108 ,
V_6 -> V_21 . type -> V_163 ) ;
F_30 (p, &pg->pgpaths, list) {
F_109 ( L_52 , V_99 -> V_17 . V_18 -> V_130 ) ;
if ( V_6 -> V_21 . type -> V_160 )
V_157 += V_6 -> V_21 . type -> V_160 ( & V_6 -> V_21 ,
& V_99 -> V_17 , type , V_155 + V_157 ,
V_156 - V_157 ) ;
}
}
break;
}
F_43 ( & V_13 -> V_25 , V_70 ) ;
return 0 ;
}
static int F_110 ( struct V_9 * V_10 , unsigned V_100 , char * * V_98 )
{
int V_68 = - V_96 ;
struct V_134 * V_18 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
T_2 V_135 ;
F_105 ( & V_13 -> V_32 ) ;
if ( F_111 ( V_10 ) ) {
V_68 = - V_103 ;
goto V_129;
}
if ( V_100 == 1 ) {
if ( ! strcasecmp ( V_98 [ 0 ] , L_23 ) ) {
V_68 = V_62 ( V_13 , 1 , 0 ) ;
goto V_129;
} else if ( ! strcasecmp ( V_98 [ 0 ] , L_53 ) ) {
V_68 = V_62 ( V_13 , 0 , 0 ) ;
goto V_129;
}
}
if ( V_100 != 2 ) {
F_87 ( L_54 ) ;
goto V_129;
}
if ( ! strcasecmp ( V_98 [ 0 ] , L_55 ) ) {
V_68 = F_94 ( V_13 , V_98 [ 1 ] , 1 ) ;
goto V_129;
} else if ( ! strcasecmp ( V_98 [ 0 ] , L_56 ) ) {
V_68 = F_94 ( V_13 , V_98 [ 1 ] , 0 ) ;
goto V_129;
} else if ( ! strcasecmp ( V_98 [ 0 ] , L_57 ) ) {
V_68 = F_93 ( V_13 , V_98 [ 1 ] ) ;
goto V_129;
} else if ( ! strcasecmp ( V_98 [ 0 ] , L_58 ) )
V_135 = F_90 ;
else if ( ! strcasecmp ( V_98 [ 0 ] , L_59 ) )
V_135 = F_86 ;
else {
F_87 ( L_54 ) ;
goto V_129;
}
V_68 = F_61 ( V_10 , V_98 [ 1 ] , F_62 ( V_10 -> V_88 ) , & V_18 ) ;
if ( V_68 ) {
F_87 ( L_60 ,
V_98 [ 1 ] ) ;
goto V_129;
}
V_68 = F_91 ( V_13 , V_18 , V_135 ) ;
F_13 ( V_10 , V_18 ) ;
V_129:
F_106 ( & V_13 -> V_32 ) ;
return V_68 ;
}
static int F_112 ( struct V_9 * V_10 , unsigned int V_164 ,
unsigned long V_165 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_71 * V_19 ;
T_4 V_166 ;
unsigned long V_70 ;
int V_68 ;
V_167:
V_19 = NULL ;
V_166 = 0 ;
V_68 = 0 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_13 -> V_57 )
F_35 ( V_13 , 0 ) ;
if ( V_13 -> V_57 ) {
V_19 = V_13 -> V_57 -> V_17 . V_18 -> V_19 ;
V_166 = V_13 -> V_57 -> V_17 . V_18 -> V_166 ;
}
if ( V_13 -> V_26 )
V_68 = - V_168 ;
else if ( ! V_19 )
V_68 = - V_80 ;
F_43 ( & V_13 -> V_25 , V_70 ) ;
if ( ! V_68 && V_10 -> V_114 != F_113 ( V_19 -> V_169 ) >> V_170 )
V_68 = F_114 ( NULL , V_164 ) ;
if ( V_68 == - V_168 && ! F_115 ( V_124 ) ) {
F_42 ( V_74 , & V_13 -> V_29 ) ;
F_116 ( 10 ) ;
goto V_167;
}
return V_68 ? : F_117 ( V_19 , V_166 , V_164 , V_165 ) ;
}
static int F_118 ( struct V_9 * V_10 ,
T_5 V_171 , void * V_140 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_99 ;
int V_111 = 0 ;
F_30 (pg, &m->priority_groups, list) {
F_30 (p, &pg->pgpaths, list) {
V_111 = V_171 ( V_10 , V_99 -> V_17 . V_18 , V_10 -> V_172 , V_10 -> V_114 , V_140 ) ;
if ( V_111 )
goto V_129;
}
}
V_129:
return V_111 ;
}
static int F_119 ( struct V_1 * V_1 )
{
struct V_102 * V_76 = F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ;
return F_120 ( V_76 ) ;
}
static int F_121 ( struct V_9 * V_10 )
{
int V_173 = 0 , V_174 = 0 ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_70 ;
F_40 ( & V_13 -> V_25 , V_70 ) ;
if ( F_122 ( ! V_13 -> V_57 && V_13 -> V_61 ) )
V_6 = V_13 -> V_61 ;
else if ( F_123 ( V_13 -> V_51 ) )
V_6 = V_13 -> V_51 ;
else
goto V_129;
V_173 = 1 ;
F_30 (pgpath, &pg->pgpaths, list)
if ( V_1 -> V_3 ) {
V_174 = 1 ;
if ( ! F_119 ( V_1 ) ) {
V_173 = 0 ;
break;
}
}
if ( ! V_174 )
V_173 = 0 ;
V_129:
F_43 ( & V_13 -> V_25 , V_70 ) ;
return V_173 ;
}
static int T_6 F_124 ( void )
{
int V_68 ;
V_35 = F_125 ( V_39 , 0 ) ;
if ( ! V_35 )
return - V_42 ;
V_68 = F_126 ( & V_175 ) ;
if ( V_68 < 0 ) {
F_97 ( L_61 , V_68 ) ;
F_127 ( V_35 ) ;
return - V_96 ;
}
V_74 = F_128 ( L_62 , V_176 , 0 ) ;
if ( ! V_74 ) {
F_97 ( L_63 ) ;
F_129 ( & V_175 ) ;
F_127 ( V_35 ) ;
return - V_42 ;
}
V_49 = F_130 ( L_64 ,
V_176 ) ;
if ( ! V_49 ) {
F_97 ( L_65 ) ;
F_131 ( V_74 ) ;
F_129 ( & V_175 ) ;
F_127 ( V_35 ) ;
return - V_42 ;
}
F_132 ( L_66 ,
V_175 . V_177 [ 0 ] , V_175 . V_177 [ 1 ] ,
V_175 . V_177 [ 2 ] ) ;
return V_68 ;
}
static void T_7 F_133 ( void )
{
F_131 ( V_49 ) ;
F_131 ( V_74 ) ;
F_129 ( & V_175 ) ;
F_127 ( V_35 ) ;
}
