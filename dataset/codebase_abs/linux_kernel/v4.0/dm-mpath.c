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
if ( ! V_13 -> V_58 ) {
V_13 -> V_26 = 0 ;
goto V_59;
}
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
union V_35 * V_65 ,
struct V_63 * V_66 , struct V_63 * * V_67 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
int V_68 = V_69 ;
T_1 V_51 = V_64 ? F_40 ( V_64 ) : F_40 ( V_66 ) ;
struct V_1 * V_1 ;
struct V_70 * V_19 ;
struct V_37 * V_38 ;
F_41 ( & V_13 -> V_25 ) ;
if ( ! V_13 -> V_56 ||
( ! V_13 -> V_26 && ( V_13 -> V_54 && -- V_13 -> V_54 == 0 ) ) )
F_36 ( V_13 , V_51 ) ;
V_1 = V_13 -> V_56 ;
if ( ! V_1 ) {
if ( ! F_37 ( V_13 ) )
V_68 = - V_71 ;
goto V_72;
} else if ( V_13 -> V_26 || V_13 -> V_46 ) {
F_29 ( V_13 ) ;
goto V_72;
}
if ( F_25 ( V_13 , V_65 ) < 0 )
goto V_72;
V_38 = V_65 -> V_41 ;
V_38 -> V_1 = V_1 ;
V_38 -> V_51 = V_51 ;
V_19 = V_1 -> V_17 . V_18 -> V_19 ;
F_42 ( & V_13 -> V_25 ) ;
if ( V_64 ) {
V_64 -> V_73 = F_12 ( V_19 ) ;
V_64 -> V_74 = V_19 -> V_75 ;
V_64 -> V_76 |= V_77 ;
} else {
* V_67 = F_43 ( F_12 ( V_19 ) ,
F_44 ( V_66 ) , V_2 ) ;
if ( F_45 ( * V_67 ) )
return V_68 ;
( * V_67 ) -> V_78 = ( * V_67 ) -> V_79 = NULL ;
( * V_67 ) -> V_74 = V_19 -> V_75 ;
( * V_67 ) -> V_76 |= V_77 ;
}
if ( V_1 -> V_6 -> V_21 . type -> V_80 )
V_1 -> V_6 -> V_21 . type -> V_80 ( & V_1 -> V_6 -> V_21 ,
& V_1 -> V_17 ,
V_51 ) ;
return V_81 ;
V_72:
F_42 ( & V_13 -> V_25 ) ;
return V_68 ;
}
static int F_46 ( struct V_9 * V_10 , struct V_63 * V_64 ,
union V_35 * V_65 )
{
return F_39 ( V_10 , V_64 , V_65 , NULL , NULL ) ;
}
static int F_47 ( struct V_9 * V_10 , struct V_63 * V_66 ,
union V_35 * V_65 ,
struct V_63 * * V_64 )
{
return F_39 ( V_10 , NULL , V_65 , V_66 , V_64 ) ;
}
static void F_48 ( struct V_63 * V_64 )
{
F_49 ( V_64 ) ;
}
static int V_61 ( struct V_12 * V_13 , unsigned V_61 ,
unsigned V_82 )
{
unsigned long V_83 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( V_82 )
V_13 -> V_62 = V_13 -> V_61 ;
else
V_13 -> V_62 = V_61 ;
V_13 -> V_61 = V_61 ;
F_51 ( & V_13 -> V_25 , V_83 ) ;
if ( ! V_61 )
F_52 ( V_13 -> V_10 -> V_84 ) ;
return 0 ;
}
static void V_29 ( struct V_85 * V_86 )
{
struct V_12 * V_13 =
F_53 ( V_86 , struct V_12 , V_29 ) ;
F_54 ( V_13 -> V_10 -> V_84 ) ;
}
static int F_55 ( struct V_87 * V_88 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_68 ;
struct V_89 * V_90 ;
unsigned V_91 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_90 = F_56 ( F_57 ( V_88 ) ) ;
if ( ! V_90 ) {
V_10 -> error = L_2 ;
return - V_94 ;
}
V_68 = F_58 ( V_93 , V_88 , & V_91 , & V_10 -> error ) ;
if ( V_68 ) {
F_15 ( V_90 ) ;
return - V_94 ;
}
V_68 = V_90 -> V_95 ( & V_6 -> V_21 , V_91 , V_88 -> V_96 ) ;
if ( V_68 ) {
F_15 ( V_90 ) ;
V_10 -> error = L_3 ;
return V_68 ;
}
V_6 -> V_21 . type = V_90 ;
F_59 ( V_88 , V_91 ) ;
return 0 ;
}
static struct V_1 * F_60 ( struct V_87 * V_88 , struct V_20 * V_21 ,
struct V_9 * V_10 )
{
int V_68 ;
struct V_1 * V_97 ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_98 * V_73 = NULL ;
const char * V_99 ;
if ( V_88 -> V_100 < 1 ) {
V_10 -> error = L_4 ;
return F_61 ( - V_94 ) ;
}
V_97 = F_1 () ;
if ( ! V_97 )
return F_61 ( - V_40 ) ;
V_68 = F_62 ( V_10 , F_57 ( V_88 ) , F_63 ( V_10 -> V_84 ) ,
& V_97 -> V_17 . V_18 ) ;
if ( V_68 ) {
V_10 -> error = L_5 ;
goto V_101;
}
if ( V_13 -> V_102 || V_13 -> V_16 )
V_73 = F_12 ( V_97 -> V_17 . V_18 -> V_19 ) ;
if ( V_13 -> V_102 ) {
V_99 = F_64 ( V_73 , V_2 ) ;
if ( V_99 ) {
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = V_99 ;
F_5 ( V_13 -> V_34 ) ;
V_13 -> V_34 = NULL ;
}
}
if ( V_13 -> V_16 ) {
V_68 = F_65 ( V_73 , V_13 -> V_16 ) ;
if ( V_68 == - V_103 ) {
F_11 ( V_73 ) ;
V_68 = F_65 ( V_73 , V_13 -> V_16 ) ;
}
if ( V_68 < 0 ) {
V_10 -> error = L_6 ;
F_13 ( V_10 , V_97 -> V_17 . V_18 ) ;
goto V_101;
}
if ( V_13 -> V_34 ) {
V_68 = F_66 ( V_73 , V_13 -> V_34 ) ;
if ( V_68 < 0 ) {
V_10 -> error = L_7
L_8 ;
F_11 ( V_73 ) ;
F_13 ( V_10 , V_97 -> V_17 . V_18 ) ;
goto V_101;
}
}
}
V_68 = V_21 -> type -> V_104 ( V_21 , & V_97 -> V_17 , V_88 -> V_100 , V_88 -> V_96 , & V_10 -> error ) ;
if ( V_68 ) {
F_13 ( V_10 , V_97 -> V_17 . V_18 ) ;
goto V_101;
}
return V_97 ;
V_101:
F_4 ( V_97 ) ;
return F_61 ( V_68 ) ;
}
static struct V_5 * F_67 ( struct V_87 * V_88 ,
struct V_12 * V_13 )
{
static struct V_92 V_93 [] = {
{ 1 , 1024 , L_9 } ,
{ 0 , 1024 , L_10 }
} ;
int V_68 ;
unsigned V_105 , V_106 , V_107 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_13 -> V_10 ;
if ( V_88 -> V_100 < 2 ) {
V_88 -> V_100 = 0 ;
V_10 -> error = L_11 ;
return F_61 ( - V_94 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_12 ;
return F_61 ( - V_40 ) ;
}
V_6 -> V_13 = V_13 ;
V_68 = F_55 ( V_88 , V_6 , V_10 ) ;
if ( V_68 )
goto V_101;
V_68 = F_68 ( V_93 , V_88 , & V_6 -> V_108 , & V_10 -> error ) ;
if ( V_68 )
goto V_101;
V_68 = F_68 ( V_93 + 1 , V_88 , & V_106 , & V_10 -> error ) ;
if ( V_68 )
goto V_101;
V_107 = 1 + V_106 ;
for ( V_105 = 0 ; V_105 < V_6 -> V_108 ; V_105 ++ ) {
struct V_1 * V_1 ;
struct V_87 V_109 ;
if ( V_88 -> V_100 < V_107 ) {
V_10 -> error = L_13 ;
V_68 = - V_94 ;
goto V_101;
}
V_109 . V_100 = V_107 ;
V_109 . V_96 = V_88 -> V_96 ;
V_1 = F_60 ( & V_109 , & V_6 -> V_21 , V_10 ) ;
if ( F_45 ( V_1 ) ) {
V_68 = F_69 ( V_1 ) ;
goto V_101;
}
V_1 -> V_6 = V_6 ;
F_70 ( & V_1 -> V_15 , & V_6 -> V_7 ) ;
F_59 ( V_88 , V_107 ) ;
}
return V_6 ;
V_101:
F_14 ( V_6 , V_10 ) ;
return F_61 ( V_68 ) ;
}
static int F_71 ( struct V_87 * V_88 , struct V_12 * V_13 )
{
unsigned V_110 ;
int V_111 ;
struct V_9 * V_10 = V_13 -> V_10 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_14 } ,
} ;
if ( F_58 ( V_93 , V_88 , & V_110 , & V_10 -> error ) )
return - V_94 ;
if ( ! V_110 )
return 0 ;
V_13 -> V_16 = F_72 ( F_57 ( V_88 ) , V_2 ) ;
if ( ! F_73 ( F_74 ( V_13 -> V_16 ) ,
L_15 , V_13 -> V_16 ) ) {
V_10 -> error = L_16 ;
V_111 = - V_94 ;
goto V_112;
}
if ( V_110 > 1 ) {
char * V_97 ;
int V_105 , V_113 , V_114 = 4 ;
for ( V_105 = 0 ; V_105 <= V_110 - 2 ; V_105 ++ )
V_114 += strlen ( V_88 -> V_96 [ V_105 ] ) + 1 ;
V_97 = V_13 -> V_34 = F_2 ( V_114 , V_2 ) ;
if ( ! V_97 ) {
V_10 -> error = L_17 ;
V_111 = - V_40 ;
goto V_112;
}
V_113 = sprintf ( V_97 , L_18 , V_110 - 1 ) ;
for ( V_105 = 0 , V_97 += V_113 + 1 ; V_105 <= V_110 - 2 ; V_105 ++ , V_97 += V_113 + 1 )
V_113 = sprintf ( V_97 , L_19 , V_88 -> V_96 [ V_105 ] ) ;
}
F_59 ( V_88 , V_110 - 1 ) ;
return 0 ;
V_112:
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = NULL ;
return V_111 ;
}
static int F_75 ( struct V_87 * V_88 , struct V_12 * V_13 )
{
int V_68 ;
unsigned V_100 ;
struct V_9 * V_10 = V_13 -> V_10 ;
const char * V_115 ;
static struct V_92 V_93 [] = {
{ 0 , 6 , L_20 } ,
{ 1 , 50 , L_21 } ,
{ 0 , 60000 , L_22 } ,
} ;
V_68 = F_58 ( V_93 , V_88 , & V_100 , & V_10 -> error ) ;
if ( V_68 )
return - V_94 ;
if ( ! V_100 )
return 0 ;
do {
V_115 = F_57 ( V_88 ) ;
V_100 -- ;
if ( ! strcasecmp ( V_115 , L_23 ) ) {
V_68 = V_61 ( V_13 , 1 , 0 ) ;
continue;
}
if ( ! strcasecmp ( V_115 , L_24 ) ) {
V_13 -> V_102 = 1 ;
continue;
}
if ( ! strcasecmp ( V_115 , L_25 ) &&
( V_100 >= 1 ) ) {
V_68 = F_68 ( V_93 + 1 , V_88 , & V_13 -> V_116 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
if ( ! strcasecmp ( V_115 , L_26 ) &&
( V_100 >= 1 ) ) {
V_68 = F_68 ( V_93 + 2 , V_88 , & V_13 -> V_27 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
V_10 -> error = L_27 ;
V_68 = - V_94 ;
} while ( V_100 && ! V_68 );
return V_68 ;
}
static int F_76 ( struct V_9 * V_10 , unsigned int V_100 ,
char * * V_96 )
{
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_28 } ,
{ 0 , 1024 , L_29 } ,
} ;
int V_68 ;
struct V_12 * V_13 ;
struct V_87 V_88 ;
unsigned V_117 = 0 ;
unsigned V_118 ;
V_88 . V_100 = V_100 ;
V_88 . V_96 = V_96 ;
V_13 = F_16 ( V_10 ) ;
if ( ! V_13 ) {
V_10 -> error = L_30 ;
return - V_94 ;
}
V_68 = F_75 ( & V_88 , V_13 ) ;
if ( V_68 )
goto V_101;
V_68 = F_71 ( & V_88 , V_13 ) ;
if ( V_68 )
goto V_101;
V_68 = F_68 ( V_93 , & V_88 , & V_13 -> V_119 , & V_10 -> error ) ;
if ( V_68 )
goto V_101;
V_68 = F_68 ( V_93 + 1 , & V_88 , & V_118 , & V_10 -> error ) ;
if ( V_68 )
goto V_101;
if ( ( ! V_13 -> V_119 && V_118 ) ||
( V_13 -> V_119 && ! V_118 ) ) {
V_10 -> error = L_31 ;
V_68 = - V_94 ;
goto V_101;
}
while ( V_88 . V_100 ) {
struct V_5 * V_6 ;
V_6 = F_67 ( & V_88 , V_13 ) ;
if ( F_45 ( V_6 ) ) {
V_68 = F_69 ( V_6 ) ;
goto V_101;
}
V_13 -> V_58 += V_6 -> V_108 ;
F_70 ( & V_6 -> V_15 , & V_13 -> V_24 ) ;
V_117 ++ ;
V_6 -> V_120 = V_117 ;
if ( ! -- V_118 )
V_13 -> V_60 = V_6 ;
}
if ( V_117 != V_13 -> V_119 ) {
V_10 -> error = L_32 ;
V_68 = - V_94 ;
goto V_101;
}
V_10 -> V_121 = 1 ;
V_10 -> V_122 = 1 ;
V_10 -> V_123 = 1 ;
return 0 ;
V_101:
F_23 ( V_13 ) ;
return V_68 ;
}
static void F_77 ( struct V_12 * V_13 )
{
F_78 ( V_124 , V_125 ) ;
unsigned long V_83 ;
F_79 ( & V_13 -> V_30 , & V_124 ) ;
while ( 1 ) {
F_80 ( V_126 ) ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( ! V_13 -> V_43 ) {
F_51 ( & V_13 -> V_25 , V_83 ) ;
break;
}
F_51 ( & V_13 -> V_25 , V_83 ) ;
F_81 () ;
}
F_80 ( V_127 ) ;
F_82 ( & V_13 -> V_30 , & V_124 ) ;
}
static void F_83 ( struct V_12 * V_13 )
{
unsigned long V_83 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
V_13 -> V_44 = 1 ;
F_51 ( & V_13 -> V_25 , V_83 ) ;
F_84 ( V_50 ) ;
F_77 ( V_13 ) ;
F_84 ( V_128 ) ;
F_85 ( & V_13 -> V_29 ) ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
V_13 -> V_44 = 0 ;
F_51 ( & V_13 -> V_25 , V_83 ) ;
}
static void F_86 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_83 ( V_13 ) ;
F_23 ( V_13 ) ;
}
static int F_87 ( struct V_1 * V_1 )
{
unsigned long V_83 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( ! V_1 -> V_3 )
goto V_129;
F_88 ( L_33 , V_1 -> V_17 . V_18 -> V_130 ) ;
V_1 -> V_6 -> V_21 . type -> F_87 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
V_1 -> V_3 = 0 ;
V_1 -> V_131 ++ ;
V_13 -> V_58 -- ;
if ( V_1 == V_13 -> V_56 )
V_13 -> V_56 = NULL ;
F_89 ( V_132 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_130 , V_13 -> V_58 ) ;
F_90 ( & V_13 -> V_29 ) ;
V_129:
F_51 ( & V_13 -> V_25 , V_83 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_1 )
{
int V_68 = 0 , V_133 = 0 ;
unsigned long V_83 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( V_1 -> V_3 )
goto V_129;
if ( ! V_1 -> V_6 -> V_21 . type -> F_91 ) {
F_88 ( L_34 ,
V_1 -> V_6 -> V_21 . type -> V_130 ) ;
V_68 = - V_94 ;
goto V_129;
}
V_68 = V_1 -> V_6 -> V_21 . type -> F_91 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
if ( V_68 )
goto V_129;
V_1 -> V_3 = 1 ;
if ( ! V_13 -> V_58 ++ ) {
V_13 -> V_56 = NULL ;
V_133 = 1 ;
} else if ( V_13 -> V_16 && ( V_13 -> V_47 == V_1 -> V_6 ) ) {
if ( F_92 ( V_50 , & V_1 -> V_4 . V_86 ) )
V_13 -> V_43 ++ ;
}
F_89 ( V_134 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_130 , V_13 -> V_58 ) ;
F_90 ( & V_13 -> V_29 ) ;
V_129:
F_51 ( & V_13 -> V_25 , V_83 ) ;
if ( V_133 )
F_52 ( V_13 -> V_10 -> V_84 ) ;
return V_68 ;
}
static int F_93 ( struct V_12 * V_13 , struct V_135 * V_18 ,
T_2 V_136 )
{
int V_68 = - V_94 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_31 (pg, &m->priority_groups, list) {
F_31 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_17 . V_18 == V_18 )
V_68 = V_136 ( V_1 ) ;
}
}
return V_68 ;
}
static void F_94 ( struct V_12 * V_13 , struct V_5 * V_6 ,
int V_57 )
{
unsigned long V_83 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
V_6 -> V_57 = V_57 ;
V_13 -> V_56 = NULL ;
V_13 -> V_47 = NULL ;
F_51 ( & V_13 -> V_25 , V_83 ) ;
F_90 ( & V_13 -> V_29 ) ;
}
static int F_95 ( struct V_12 * V_13 , const char * V_137 )
{
struct V_5 * V_6 ;
unsigned V_138 ;
unsigned long V_83 ;
char V_139 ;
if ( ! V_137 || ( sscanf ( V_137 , L_35 , & V_138 , & V_139 ) != 1 ) || ! V_138 ||
( V_138 > V_13 -> V_119 ) ) {
F_88 ( L_36 ) ;
return - V_94 ;
}
F_50 ( & V_13 -> V_25 , V_83 ) ;
F_31 (pg, &m->priority_groups, list) {
V_6 -> V_57 = 0 ;
if ( -- V_138 )
continue;
V_13 -> V_56 = NULL ;
V_13 -> V_47 = NULL ;
V_13 -> V_60 = V_6 ;
}
F_51 ( & V_13 -> V_25 , V_83 ) ;
F_90 ( & V_13 -> V_29 ) ;
return 0 ;
}
static int F_96 ( struct V_12 * V_13 , const char * V_137 , int V_57 )
{
struct V_5 * V_6 ;
unsigned V_138 ;
char V_139 ;
if ( ! V_137 || ( sscanf ( V_137 , L_35 , & V_138 , & V_139 ) != 1 ) || ! V_138 ||
( V_138 > V_13 -> V_119 ) ) {
F_88 ( L_37 ) ;
return - V_94 ;
}
F_31 (pg, &m->priority_groups, list) {
if ( ! -- V_138 )
break;
}
F_94 ( V_13 , V_6 , V_57 ) ;
return 0 ;
}
static int F_97 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
unsigned long V_83 ;
int V_140 = 0 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( V_13 -> V_45 <= V_13 -> V_116 && ! V_13 -> V_44 )
V_13 -> V_46 = 1 ;
else
V_140 = 1 ;
F_51 ( & V_13 -> V_25 , V_83 ) ;
return V_140 ;
}
static void F_98 ( void * V_141 , int V_142 )
{
struct V_1 * V_1 = V_141 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned long V_83 ;
unsigned V_143 = 0 ;
switch ( V_142 ) {
case V_144 :
break;
case V_145 :
if ( ! V_13 -> V_16 ) {
V_142 = 0 ;
break;
}
F_99 ( L_38
L_39 , V_13 -> V_16 , V_142 ) ;
F_87 ( V_1 ) ;
break;
case V_146 :
F_94 ( V_13 , V_6 , 1 ) ;
break;
case V_147 :
V_143 = 1 ;
case V_148 :
case V_149 :
if ( F_97 ( V_13 , V_1 ) )
F_87 ( V_1 ) ;
V_142 = 0 ;
break;
default:
F_87 ( V_1 ) ;
}
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( V_142 ) {
if ( V_1 == V_13 -> V_56 ) {
F_99 ( L_40 , V_142 ) ;
V_13 -> V_56 = NULL ;
V_13 -> V_47 = NULL ;
}
} else if ( ! V_13 -> V_46 )
V_6 -> V_57 = 0 ;
if ( -- V_13 -> V_43 )
goto V_129;
if ( V_13 -> V_46 ) {
V_13 -> V_48 = V_143 ;
if ( F_29 ( V_13 ) )
goto V_129;
}
V_13 -> V_26 = 0 ;
F_100 ( & V_13 -> V_30 ) ;
V_129:
F_51 ( & V_13 -> V_25 , V_83 ) ;
}
static void V_4 ( struct V_85 * V_86 )
{
struct V_1 * V_1 =
F_53 ( V_86 , struct V_1 , V_4 . V_86 ) ;
if ( V_1 -> V_3 )
F_101 ( F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ,
F_98 , V_1 ) ;
else
F_98 ( V_1 , V_150 ) ;
}
static int F_102 ( int error )
{
switch ( error ) {
case - V_151 :
case - V_152 :
case - V_153 :
case - V_154 :
case - V_155 :
return 1 ;
}
return 0 ;
}
static int F_103 ( struct V_12 * V_13 , struct V_63 * V_64 ,
int error , struct V_37 * V_38 )
{
int V_68 = V_156 ;
unsigned long V_83 ;
if ( ! error && ! V_64 -> V_142 )
return 0 ;
if ( F_102 ( error ) )
return error ;
if ( V_38 -> V_1 )
F_87 ( V_38 -> V_1 ) ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( ! V_13 -> V_58 ) {
if ( ! V_13 -> V_61 ) {
if ( ! F_37 ( V_13 ) )
V_68 = - V_71 ;
} else {
if ( error == - V_157 )
V_68 = error ;
}
}
F_51 ( & V_13 -> V_25 , V_83 ) ;
return V_68 ;
}
static int F_104 ( struct V_9 * V_10 , struct V_63 * V_64 ,
int error , union V_35 * V_65 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_37 * V_38 = V_65 -> V_41 ;
struct V_1 * V_1 ;
struct V_20 * V_21 ;
int V_68 ;
F_105 ( ! V_38 ) ;
V_68 = F_103 ( V_13 , V_64 , error , V_38 ) ;
V_1 = V_38 -> V_1 ;
if ( V_1 ) {
V_21 = & V_1 -> V_6 -> V_21 ;
if ( V_21 -> type -> V_158 )
V_21 -> type -> V_158 ( V_21 , & V_1 -> V_17 , V_38 -> V_51 ) ;
}
F_27 ( V_13 , V_65 ) ;
return V_68 ;
}
static void F_106 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
V_61 ( V_13 , 0 , 1 ) ;
}
static void F_107 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_108 ( & V_13 -> V_31 ) ;
F_83 ( V_13 ) ;
F_109 ( & V_13 -> V_31 ) ;
}
static void F_110 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
unsigned long V_83 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
V_13 -> V_61 = V_13 -> V_62 ;
F_51 ( & V_13 -> V_25 , V_83 ) ;
}
static void F_111 ( struct V_9 * V_10 , T_3 type ,
unsigned V_159 , char * V_160 , unsigned V_161 )
{
int V_162 = 0 ;
unsigned long V_83 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
unsigned V_120 ;
char V_163 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( type == V_164 )
F_112 ( L_41 , V_13 -> V_26 , V_13 -> V_45 ) ;
else {
F_112 ( L_42 , V_13 -> V_61 +
( V_13 -> V_116 > 0 ) * 2 +
( V_13 -> V_27 != V_28 ) * 2 +
V_13 -> V_102 ) ;
if ( V_13 -> V_61 )
F_112 ( L_43 ) ;
if ( V_13 -> V_116 )
F_112 ( L_44 , V_13 -> V_116 ) ;
if ( V_13 -> V_27 != V_28 )
F_112 ( L_45 , V_13 -> V_27 ) ;
if ( V_13 -> V_102 )
F_112 ( L_46 ) ;
}
if ( ! V_13 -> V_16 || type == V_164 )
F_112 ( L_47 ) ;
else
F_112 ( L_48 , V_13 -> V_16 ) ;
F_112 ( L_42 , V_13 -> V_119 ) ;
if ( V_13 -> V_60 )
V_120 = V_13 -> V_60 -> V_120 ;
else if ( V_13 -> V_47 )
V_120 = V_13 -> V_47 -> V_120 ;
else
V_120 = ( V_13 -> V_119 ? 1 : 0 ) ;
F_112 ( L_42 , V_120 ) ;
switch ( type ) {
case V_164 :
F_31 (pg, &m->priority_groups, list) {
if ( V_6 -> V_57 )
V_163 = 'D' ;
else if ( V_6 == V_13 -> V_47 )
V_163 = 'A' ;
else
V_163 = 'E' ;
F_112 ( L_49 , V_163 ) ;
if ( V_6 -> V_21 . type -> V_165 )
V_162 += V_6 -> V_21 . type -> V_165 ( & V_6 -> V_21 , NULL , type ,
V_160 + V_162 ,
V_161 - V_162 ) ;
else
F_112 ( L_47 ) ;
F_112 ( L_50 , V_6 -> V_108 ,
V_6 -> V_21 . type -> V_166 ) ;
F_31 (p, &pg->pgpaths, list) {
F_112 ( L_51 , V_97 -> V_17 . V_18 -> V_130 ,
V_97 -> V_3 ? L_52 : L_53 ,
V_97 -> V_131 ) ;
if ( V_6 -> V_21 . type -> V_165 )
V_162 += V_6 -> V_21 . type -> V_165 ( & V_6 -> V_21 ,
& V_97 -> V_17 , type , V_160 + V_162 ,
V_161 - V_162 ) ;
}
}
break;
case V_167 :
F_31 (pg, &m->priority_groups, list) {
F_112 ( L_54 , V_6 -> V_21 . type -> V_130 ) ;
if ( V_6 -> V_21 . type -> V_165 )
V_162 += V_6 -> V_21 . type -> V_165 ( & V_6 -> V_21 , NULL , type ,
V_160 + V_162 ,
V_161 - V_162 ) ;
else
F_112 ( L_47 ) ;
F_112 ( L_50 , V_6 -> V_108 ,
V_6 -> V_21 . type -> V_168 ) ;
F_31 (p, &pg->pgpaths, list) {
F_112 ( L_54 , V_97 -> V_17 . V_18 -> V_130 ) ;
if ( V_6 -> V_21 . type -> V_165 )
V_162 += V_6 -> V_21 . type -> V_165 ( & V_6 -> V_21 ,
& V_97 -> V_17 , type , V_160 + V_162 ,
V_161 - V_162 ) ;
}
}
break;
}
F_51 ( & V_13 -> V_25 , V_83 ) ;
}
static int F_113 ( struct V_9 * V_10 , unsigned V_100 , char * * V_96 )
{
int V_68 = - V_94 ;
struct V_135 * V_18 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
T_2 V_136 ;
F_108 ( & V_13 -> V_31 ) ;
if ( F_114 ( V_10 ) ) {
V_68 = - V_103 ;
goto V_129;
}
if ( V_100 == 1 ) {
if ( ! strcasecmp ( V_96 [ 0 ] , L_23 ) ) {
V_68 = V_61 ( V_13 , 1 , 0 ) ;
goto V_129;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_55 ) ) {
V_68 = V_61 ( V_13 , 0 , 0 ) ;
goto V_129;
}
}
if ( V_100 != 2 ) {
F_88 ( L_56 , V_100 ) ;
goto V_129;
}
if ( ! strcasecmp ( V_96 [ 0 ] , L_57 ) ) {
V_68 = F_96 ( V_13 , V_96 [ 1 ] , 1 ) ;
goto V_129;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_58 ) ) {
V_68 = F_96 ( V_13 , V_96 [ 1 ] , 0 ) ;
goto V_129;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_59 ) ) {
V_68 = F_95 ( V_13 , V_96 [ 1 ] ) ;
goto V_129;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_60 ) )
V_136 = F_91 ;
else if ( ! strcasecmp ( V_96 [ 0 ] , L_61 ) )
V_136 = F_87 ;
else {
F_88 ( L_62 , V_96 [ 0 ] ) ;
goto V_129;
}
V_68 = F_62 ( V_10 , V_96 [ 1 ] , F_63 ( V_10 -> V_84 ) , & V_18 ) ;
if ( V_68 ) {
F_88 ( L_63 ,
V_96 [ 1 ] ) ;
goto V_129;
}
V_68 = F_93 ( V_13 , V_18 , V_136 ) ;
F_13 ( V_10 , V_18 ) ;
V_129:
F_109 ( & V_13 -> V_31 ) ;
return V_68 ;
}
static int F_115 ( struct V_9 * V_10 , unsigned int V_169 ,
unsigned long V_170 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_1 * V_1 ;
struct V_70 * V_19 ;
T_4 V_171 ;
unsigned long V_83 ;
int V_68 ;
V_19 = NULL ;
V_171 = 0 ;
V_68 = 0 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( ! V_13 -> V_56 )
F_36 ( V_13 , 0 ) ;
V_1 = V_13 -> V_56 ;
if ( V_1 ) {
V_19 = V_1 -> V_17 . V_18 -> V_19 ;
V_171 = V_1 -> V_17 . V_18 -> V_171 ;
}
if ( ( V_1 && V_13 -> V_26 ) || ( ! V_1 && V_13 -> V_61 ) )
V_68 = - V_172 ;
else if ( ! V_19 )
V_68 = - V_71 ;
F_51 ( & V_13 -> V_25 , V_83 ) ;
if ( ! V_19 || V_10 -> V_114 != F_116 ( V_19 -> V_173 ) >> V_174 ) {
int V_175 = F_117 ( NULL , V_169 ) ;
if ( V_175 )
V_68 = V_175 ;
}
if ( V_68 == - V_172 && ! F_118 ( V_125 ) ) {
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( ! V_13 -> V_47 ) {
F_36 ( V_13 , 0 ) ;
}
if ( V_13 -> V_46 )
F_29 ( V_13 ) ;
F_51 ( & V_13 -> V_25 , V_83 ) ;
F_52 ( V_13 -> V_10 -> V_84 ) ;
}
return V_68 ? : F_119 ( V_19 , V_171 , V_169 , V_170 ) ;
}
static int F_120 ( struct V_9 * V_10 ,
T_5 V_176 , void * V_141 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
int V_111 = 0 ;
F_31 (pg, &m->priority_groups, list) {
F_31 (p, &pg->pgpaths, list) {
V_111 = V_176 ( V_10 , V_97 -> V_17 . V_18 , V_10 -> V_177 , V_10 -> V_114 , V_141 ) ;
if ( V_111 )
goto V_129;
}
}
V_129:
return V_111 ;
}
static int F_121 ( struct V_1 * V_1 )
{
struct V_98 * V_73 = F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ;
return F_122 ( V_73 ) ;
}
static int F_123 ( struct V_9 * V_10 )
{
int V_178 = 0 , V_179 = 0 ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_83 ;
F_50 ( & V_13 -> V_25 , V_83 ) ;
if ( V_13 -> V_43 ||
( ! V_13 -> V_58 && V_13 -> V_61 ) ) {
V_178 = 1 ;
goto V_129;
}
if ( F_124 ( ! V_13 -> V_56 && V_13 -> V_60 ) )
V_6 = V_13 -> V_60 ;
else if ( F_125 ( V_13 -> V_47 ) )
V_6 = V_13 -> V_47 ;
else
goto V_129;
V_178 = 1 ;
F_31 (pgpath, &pg->pgpaths, list)
if ( V_1 -> V_3 ) {
V_179 = 1 ;
if ( ! F_121 ( V_1 ) ) {
V_178 = 0 ;
break;
}
}
if ( ! V_179 )
V_178 = 0 ;
V_129:
F_51 ( & V_13 -> V_25 , V_83 ) ;
return V_178 ;
}
static int T_6 F_126 ( void )
{
int V_68 ;
V_33 = F_127 ( V_37 , 0 ) ;
if ( ! V_33 )
return - V_40 ;
V_68 = F_128 ( & V_180 ) ;
if ( V_68 < 0 ) {
F_99 ( L_64 , V_68 ) ;
V_68 = - V_94 ;
goto V_181;
}
V_128 = F_129 ( L_65 , V_182 , 0 ) ;
if ( ! V_128 ) {
F_99 ( L_66 ) ;
V_68 = - V_40 ;
goto V_183;
}
V_50 = F_130 ( L_67 ,
V_182 ) ;
if ( ! V_50 ) {
F_99 ( L_68 ) ;
V_68 = - V_40 ;
goto V_184;
}
F_131 ( L_69 ,
V_180 . V_185 [ 0 ] , V_180 . V_185 [ 1 ] ,
V_180 . V_185 [ 2 ] ) ;
return 0 ;
V_184:
F_132 ( V_128 ) ;
V_183:
F_133 ( & V_180 ) ;
V_181:
F_134 ( V_33 ) ;
return V_68 ;
}
static void T_7 F_135 ( void )
{
F_132 ( V_50 ) ;
F_132 ( V_128 ) ;
F_133 ( & V_180 ) ;
F_134 ( V_33 ) ;
}
