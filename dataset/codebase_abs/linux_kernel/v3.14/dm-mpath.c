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
F_7 ( & V_13 -> V_25 ) ;
F_18 ( & V_13 -> V_26 ) ;
V_13 -> V_27 = 1 ;
V_13 -> V_28 = V_29 ;
F_19 ( & V_13 -> V_30 , V_30 ) ;
F_19 ( & V_13 -> V_31 , V_31 ) ;
F_20 ( & V_13 -> V_32 ) ;
F_21 ( & V_13 -> V_33 ) ;
V_13 -> V_34 = F_22 ( V_23 , V_35 ) ;
if ( ! V_13 -> V_34 ) {
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
F_5 ( V_13 -> V_36 ) ;
F_24 ( V_13 -> V_34 ) ;
F_5 ( V_13 ) ;
}
static int F_25 ( struct V_12 * V_13 , union V_37 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_26 ( V_13 -> V_34 , V_41 ) ;
if ( ! V_40 )
return - V_42 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_38 -> V_43 = V_40 ;
return 0 ;
}
static void F_27 ( struct V_12 * V_13 , union V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_43 ;
V_38 -> V_43 = NULL ;
F_28 ( V_40 , V_13 -> V_34 ) ;
}
static void F_29 ( struct V_12 * V_13 )
{
struct V_1 * V_1 ;
unsigned long V_44 = 0 ;
V_13 -> V_45 ++ ;
V_13 -> V_46 = 0 ;
if ( V_13 -> V_47 )
V_44 = F_30 ( V_13 -> V_28 != V_29 ?
V_13 -> V_28 : V_48 ) ;
F_31 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_32 ( V_49 , & V_1 -> V_4 ,
V_44 ) )
V_13 -> V_50 ++ ;
}
}
static void F_33 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
V_13 -> V_51 = V_1 -> V_6 ;
if ( V_13 -> V_16 ) {
V_13 -> V_46 = 1 ;
V_13 -> V_27 = 1 ;
} else {
V_13 -> V_46 = 0 ;
V_13 -> V_27 = 0 ;
}
V_13 -> V_45 = 0 ;
}
static int F_34 ( struct V_12 * V_13 , struct V_5 * V_6 ,
T_1 V_52 )
{
struct V_53 * V_17 ;
V_17 = V_6 -> V_21 . type -> V_54 ( & V_6 -> V_21 , & V_13 -> V_55 , V_52 ) ;
if ( ! V_17 )
return - V_56 ;
V_13 -> V_57 = F_35 ( V_17 ) ;
if ( V_13 -> V_51 != V_6 )
F_33 ( V_13 , V_13 -> V_57 ) ;
return 0 ;
}
static void F_36 ( struct V_12 * V_13 , T_1 V_52 )
{
struct V_5 * V_6 ;
unsigned V_58 = 1 ;
if ( ! V_13 -> V_59 )
goto V_60;
if ( V_13 -> V_61 ) {
V_6 = V_13 -> V_61 ;
V_13 -> V_61 = NULL ;
if ( ! F_34 ( V_13 , V_6 , V_52 ) )
return;
}
if ( V_13 -> V_51 && ! F_34 ( V_13 , V_13 -> V_51 , V_52 ) )
return;
do {
F_31 (pg, &m->priority_groups, list) {
if ( V_6 -> V_58 == V_58 )
continue;
if ( ! F_34 ( V_13 , V_6 , V_52 ) ) {
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
static int F_37 ( struct V_12 * V_13 )
{
return ( V_13 -> V_62 != V_13 -> V_63 &&
F_38 ( V_13 -> V_10 ) ) ;
}
static int F_39 ( struct V_12 * V_13 , struct V_64 * V_65 ,
union V_37 * V_66 , unsigned V_67 )
{
int V_68 = V_69 ;
T_1 V_52 = F_40 ( V_65 ) ;
unsigned long V_70 ;
struct V_1 * V_1 ;
struct V_71 * V_19 ;
struct V_39 * V_40 = V_66 -> V_43 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( ! V_13 -> V_57 ||
( ! V_13 -> V_27 && ( V_13 -> V_55 && -- V_13 -> V_55 == 0 ) ) )
F_36 ( V_13 , V_52 ) ;
V_1 = V_13 -> V_57 ;
if ( V_67 )
V_13 -> V_72 -- ;
if ( V_13 -> V_46 ) {
if ( ! V_13 -> V_50 )
F_42 ( V_73 , & V_13 -> V_30 ) ;
V_68 = V_74 ;
} else if ( ( V_1 && V_13 -> V_27 ) ||
( ! V_1 && V_13 -> V_62 ) ) {
F_43 ( & V_65 -> V_75 , & V_13 -> V_25 ) ;
V_13 -> V_72 ++ ;
if ( ! V_13 -> V_27 )
F_42 ( V_73 , & V_13 -> V_30 ) ;
V_1 = NULL ;
V_68 = V_76 ;
} else if ( V_1 ) {
V_19 = V_1 -> V_17 . V_18 -> V_19 ;
V_65 -> V_77 = F_12 ( V_19 ) ;
V_65 -> V_78 = V_19 -> V_79 ;
} else if ( F_37 ( V_13 ) )
V_68 = V_74 ;
else
V_68 = - V_80 ;
V_40 -> V_1 = V_1 ;
V_40 -> V_52 = V_52 ;
if ( V_68 == V_69 && V_1 -> V_6 -> V_21 . type -> V_81 )
V_1 -> V_6 -> V_21 . type -> V_81 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ,
V_52 ) ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
return V_68 ;
}
static int V_62 ( struct V_12 * V_13 , unsigned V_62 ,
unsigned V_82 )
{
unsigned long V_70 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( V_82 )
V_13 -> V_63 = V_13 -> V_62 ;
else
V_13 -> V_63 = V_62 ;
V_13 -> V_62 = V_62 ;
if ( ! V_13 -> V_62 && V_13 -> V_72 )
F_42 ( V_73 , & V_13 -> V_30 ) ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
return 0 ;
}
static void F_45 ( struct V_12 * V_13 )
{
int V_68 ;
unsigned long V_70 ;
union V_37 * V_38 ;
struct V_64 * V_65 , * V_83 ;
F_46 ( V_84 ) ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
F_47 ( & V_13 -> V_25 , & V_84 ) ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
F_9 (clone, n, &cl, queuelist) {
F_48 ( & V_65 -> V_75 ) ;
V_38 = F_49 ( V_65 ) ;
V_68 = F_39 ( V_13 , V_65 , V_38 , 1 ) ;
if ( V_68 < 0 ) {
F_27 ( V_13 , V_38 ) ;
F_50 ( V_65 , V_68 ) ;
} else if ( V_68 == V_69 )
F_51 ( V_65 ) ;
else if ( V_68 == V_74 ) {
F_27 ( V_13 , V_38 ) ;
F_52 ( V_65 ) ;
}
}
}
static void V_30 ( struct V_85 * V_86 )
{
struct V_12 * V_13 =
F_53 ( V_86 , struct V_12 , V_30 ) ;
struct V_1 * V_1 = NULL ;
unsigned V_87 = 1 ;
unsigned long V_70 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( ! V_13 -> V_57 )
F_36 ( V_13 , 0 ) ;
V_1 = V_13 -> V_57 ;
if ( ( V_1 && ! V_13 -> V_27 ) ||
( ! V_1 && ! V_13 -> V_62 ) )
V_87 = 0 ;
if ( V_13 -> V_46 && ! V_13 -> V_50 && V_1 &&
! V_13 -> V_88 )
F_29 ( V_13 ) ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
if ( ! V_87 )
F_45 ( V_13 ) ;
}
static void V_31 ( struct V_85 * V_86 )
{
struct V_12 * V_13 =
F_53 ( V_86 , struct V_12 , V_31 ) ;
F_54 ( V_13 -> V_10 -> V_89 ) ;
}
static int F_55 ( struct V_90 * V_91 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_68 ;
struct V_92 * V_93 ;
unsigned V_94 ;
static struct V_95 V_96 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_93 = F_56 ( F_57 ( V_91 ) ) ;
if ( ! V_93 ) {
V_10 -> error = L_2 ;
return - V_97 ;
}
V_68 = F_58 ( V_96 , V_91 , & V_94 , & V_10 -> error ) ;
if ( V_68 ) {
F_15 ( V_93 ) ;
return - V_97 ;
}
V_68 = V_93 -> V_98 ( & V_6 -> V_21 , V_94 , V_91 -> V_99 ) ;
if ( V_68 ) {
F_15 ( V_93 ) ;
V_10 -> error = L_3 ;
return V_68 ;
}
V_6 -> V_21 . type = V_93 ;
F_59 ( V_91 , V_94 ) ;
return 0 ;
}
static struct V_1 * F_60 ( struct V_90 * V_91 , struct V_20 * V_21 ,
struct V_9 * V_10 )
{
int V_68 ;
struct V_1 * V_100 ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_101 * V_77 = NULL ;
const char * V_102 ;
if ( V_91 -> V_103 < 1 ) {
V_10 -> error = L_4 ;
return F_61 ( - V_97 ) ;
}
V_100 = F_1 () ;
if ( ! V_100 )
return F_61 ( - V_42 ) ;
V_68 = F_62 ( V_10 , F_57 ( V_91 ) , F_63 ( V_10 -> V_89 ) ,
& V_100 -> V_17 . V_18 ) ;
if ( V_68 ) {
V_10 -> error = L_5 ;
goto V_104;
}
if ( V_13 -> V_105 || V_13 -> V_16 )
V_77 = F_12 ( V_100 -> V_17 . V_18 -> V_19 ) ;
if ( V_13 -> V_105 ) {
V_102 = F_64 ( V_77 , V_2 ) ;
if ( V_102 ) {
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = V_102 ;
F_5 ( V_13 -> V_36 ) ;
V_13 -> V_36 = NULL ;
}
}
if ( V_13 -> V_16 ) {
V_68 = F_65 ( V_77 , V_13 -> V_16 ) ;
if ( V_68 == - V_106 ) {
F_11 ( V_77 ) ;
V_68 = F_65 ( V_77 , V_13 -> V_16 ) ;
}
if ( V_68 < 0 ) {
V_10 -> error = L_6 ;
F_13 ( V_10 , V_100 -> V_17 . V_18 ) ;
goto V_104;
}
if ( V_13 -> V_36 ) {
V_68 = F_66 ( V_77 , V_13 -> V_36 ) ;
if ( V_68 < 0 ) {
V_10 -> error = L_7
L_8 ;
F_11 ( V_77 ) ;
F_13 ( V_10 , V_100 -> V_17 . V_18 ) ;
goto V_104;
}
}
}
V_68 = V_21 -> type -> V_107 ( V_21 , & V_100 -> V_17 , V_91 -> V_103 , V_91 -> V_99 , & V_10 -> error ) ;
if ( V_68 ) {
F_13 ( V_10 , V_100 -> V_17 . V_18 ) ;
goto V_104;
}
return V_100 ;
V_104:
F_4 ( V_100 ) ;
return F_61 ( V_68 ) ;
}
static struct V_5 * F_67 ( struct V_90 * V_91 ,
struct V_12 * V_13 )
{
static struct V_95 V_96 [] = {
{ 1 , 1024 , L_9 } ,
{ 0 , 1024 , L_10 }
} ;
int V_68 ;
unsigned V_108 , V_109 , V_110 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_13 -> V_10 ;
if ( V_91 -> V_103 < 2 ) {
V_91 -> V_103 = 0 ;
V_10 -> error = L_11 ;
return F_61 ( - V_97 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_12 ;
return F_61 ( - V_42 ) ;
}
V_6 -> V_13 = V_13 ;
V_68 = F_55 ( V_91 , V_6 , V_10 ) ;
if ( V_68 )
goto V_104;
V_68 = F_68 ( V_96 , V_91 , & V_6 -> V_111 , & V_10 -> error ) ;
if ( V_68 )
goto V_104;
V_68 = F_68 ( V_96 + 1 , V_91 , & V_109 , & V_10 -> error ) ;
if ( V_68 )
goto V_104;
V_110 = 1 + V_109 ;
for ( V_108 = 0 ; V_108 < V_6 -> V_111 ; V_108 ++ ) {
struct V_1 * V_1 ;
struct V_90 V_112 ;
if ( V_91 -> V_103 < V_110 ) {
V_10 -> error = L_13 ;
V_68 = - V_97 ;
goto V_104;
}
V_112 . V_103 = V_110 ;
V_112 . V_99 = V_91 -> V_99 ;
V_1 = F_60 ( & V_112 , & V_6 -> V_21 , V_10 ) ;
if ( F_69 ( V_1 ) ) {
V_68 = F_70 ( V_1 ) ;
goto V_104;
}
V_1 -> V_6 = V_6 ;
F_43 ( & V_1 -> V_15 , & V_6 -> V_7 ) ;
F_59 ( V_91 , V_110 ) ;
}
return V_6 ;
V_104:
F_14 ( V_6 , V_10 ) ;
return F_61 ( V_68 ) ;
}
static int F_71 ( struct V_90 * V_91 , struct V_12 * V_13 )
{
unsigned V_113 ;
int V_114 ;
struct V_9 * V_10 = V_13 -> V_10 ;
static struct V_95 V_96 [] = {
{ 0 , 1024 , L_14 } ,
} ;
if ( F_58 ( V_96 , V_91 , & V_113 , & V_10 -> error ) )
return - V_97 ;
if ( ! V_113 )
return 0 ;
V_13 -> V_16 = F_72 ( F_57 ( V_91 ) , V_2 ) ;
if ( ! F_73 ( F_74 ( V_13 -> V_16 ) ,
L_15 , V_13 -> V_16 ) ) {
V_10 -> error = L_16 ;
V_114 = - V_97 ;
goto V_115;
}
if ( V_113 > 1 ) {
char * V_100 ;
int V_108 , V_116 , V_117 = 4 ;
for ( V_108 = 0 ; V_108 <= V_113 - 2 ; V_108 ++ )
V_117 += strlen ( V_91 -> V_99 [ V_108 ] ) + 1 ;
V_100 = V_13 -> V_36 = F_2 ( V_117 , V_2 ) ;
if ( ! V_100 ) {
V_10 -> error = L_17 ;
V_114 = - V_42 ;
goto V_115;
}
V_116 = sprintf ( V_100 , L_18 , V_113 - 1 ) ;
for ( V_108 = 0 , V_100 += V_116 + 1 ; V_108 <= V_113 - 2 ; V_108 ++ , V_100 += V_116 + 1 )
V_116 = sprintf ( V_100 , L_19 , V_91 -> V_99 [ V_108 ] ) ;
}
F_59 ( V_91 , V_113 - 1 ) ;
return 0 ;
V_115:
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = NULL ;
return V_114 ;
}
static int F_75 ( struct V_90 * V_91 , struct V_12 * V_13 )
{
int V_68 ;
unsigned V_103 ;
struct V_9 * V_10 = V_13 -> V_10 ;
const char * V_118 ;
static struct V_95 V_96 [] = {
{ 0 , 6 , L_20 } ,
{ 1 , 50 , L_21 } ,
{ 0 , 60000 , L_22 } ,
} ;
V_68 = F_58 ( V_96 , V_91 , & V_103 , & V_10 -> error ) ;
if ( V_68 )
return - V_97 ;
if ( ! V_103 )
return 0 ;
do {
V_118 = F_57 ( V_91 ) ;
V_103 -- ;
if ( ! strcasecmp ( V_118 , L_23 ) ) {
V_68 = V_62 ( V_13 , 1 , 0 ) ;
continue;
}
if ( ! strcasecmp ( V_118 , L_24 ) ) {
V_13 -> V_105 = 1 ;
continue;
}
if ( ! strcasecmp ( V_118 , L_25 ) &&
( V_103 >= 1 ) ) {
V_68 = F_68 ( V_96 + 1 , V_91 , & V_13 -> V_119 , & V_10 -> error ) ;
V_103 -- ;
continue;
}
if ( ! strcasecmp ( V_118 , L_26 ) &&
( V_103 >= 1 ) ) {
V_68 = F_68 ( V_96 + 2 , V_91 , & V_13 -> V_28 , & V_10 -> error ) ;
V_103 -- ;
continue;
}
V_10 -> error = L_27 ;
V_68 = - V_97 ;
} while ( V_103 && ! V_68 );
return V_68 ;
}
static int F_76 ( struct V_9 * V_10 , unsigned int V_103 ,
char * * V_99 )
{
static struct V_95 V_96 [] = {
{ 0 , 1024 , L_28 } ,
{ 0 , 1024 , L_29 } ,
} ;
int V_68 ;
struct V_12 * V_13 ;
struct V_90 V_91 ;
unsigned V_120 = 0 ;
unsigned V_121 ;
V_91 . V_103 = V_103 ;
V_91 . V_99 = V_99 ;
V_13 = F_16 ( V_10 ) ;
if ( ! V_13 ) {
V_10 -> error = L_30 ;
return - V_97 ;
}
V_68 = F_75 ( & V_91 , V_13 ) ;
if ( V_68 )
goto V_104;
V_68 = F_71 ( & V_91 , V_13 ) ;
if ( V_68 )
goto V_104;
V_68 = F_68 ( V_96 , & V_91 , & V_13 -> V_122 , & V_10 -> error ) ;
if ( V_68 )
goto V_104;
V_68 = F_68 ( V_96 + 1 , & V_91 , & V_121 , & V_10 -> error ) ;
if ( V_68 )
goto V_104;
if ( ( ! V_13 -> V_122 && V_121 ) ||
( V_13 -> V_122 && ! V_121 ) ) {
V_10 -> error = L_31 ;
V_68 = - V_97 ;
goto V_104;
}
while ( V_91 . V_103 ) {
struct V_5 * V_6 ;
V_6 = F_67 ( & V_91 , V_13 ) ;
if ( F_69 ( V_6 ) ) {
V_68 = F_70 ( V_6 ) ;
goto V_104;
}
V_13 -> V_59 += V_6 -> V_111 ;
F_43 ( & V_6 -> V_15 , & V_13 -> V_24 ) ;
V_120 ++ ;
V_6 -> V_123 = V_120 ;
if ( ! -- V_121 )
V_13 -> V_61 = V_6 ;
}
if ( V_120 != V_13 -> V_122 ) {
V_10 -> error = L_32 ;
V_68 = - V_97 ;
goto V_104;
}
V_10 -> V_124 = 1 ;
V_10 -> V_125 = 1 ;
V_10 -> V_126 = 1 ;
return 0 ;
V_104:
F_23 ( V_13 ) ;
return V_68 ;
}
static void F_77 ( struct V_12 * V_13 )
{
F_78 ( V_127 , V_128 ) ;
unsigned long V_70 ;
F_79 ( & V_13 -> V_32 , & V_127 ) ;
while ( 1 ) {
F_80 ( V_129 ) ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( ! V_13 -> V_50 ) {
F_44 ( & V_13 -> V_26 , V_70 ) ;
break;
}
F_44 ( & V_13 -> V_26 , V_70 ) ;
F_81 () ;
}
F_80 ( V_130 ) ;
F_82 ( & V_13 -> V_32 , & V_127 ) ;
}
static void F_83 ( struct V_12 * V_13 )
{
unsigned long V_70 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
V_13 -> V_88 = 1 ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
F_84 ( V_49 ) ;
F_77 ( V_13 ) ;
F_84 ( V_73 ) ;
F_85 ( & V_13 -> V_31 ) ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
V_13 -> V_88 = 0 ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
}
static void F_86 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_83 ( V_13 ) ;
F_23 ( V_13 ) ;
}
static int F_87 ( struct V_9 * V_10 , struct V_64 * V_65 ,
union V_37 * V_66 )
{
int V_68 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
if ( F_25 ( V_13 , V_66 ) < 0 )
return V_74 ;
V_65 -> V_131 |= V_132 ;
V_68 = F_39 ( V_13 , V_65 , V_66 , 0 ) ;
if ( V_68 < 0 || V_68 == V_74 )
F_27 ( V_13 , V_66 ) ;
return V_68 ;
}
static int F_88 ( struct V_1 * V_1 )
{
unsigned long V_70 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( ! V_1 -> V_3 )
goto V_133;
F_89 ( L_33 , V_1 -> V_17 . V_18 -> V_134 ) ;
V_1 -> V_6 -> V_21 . type -> F_88 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
V_1 -> V_3 = 0 ;
V_1 -> V_135 ++ ;
V_13 -> V_59 -- ;
if ( V_1 == V_13 -> V_57 )
V_13 -> V_57 = NULL ;
F_90 ( V_136 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_134 , V_13 -> V_59 ) ;
F_91 ( & V_13 -> V_31 ) ;
V_133:
F_44 ( & V_13 -> V_26 , V_70 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_1 )
{
int V_68 = 0 ;
unsigned long V_70 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( V_1 -> V_3 )
goto V_133;
if ( ! V_1 -> V_6 -> V_21 . type -> F_92 ) {
F_89 ( L_34 ,
V_1 -> V_6 -> V_21 . type -> V_134 ) ;
V_68 = - V_97 ;
goto V_133;
}
V_68 = V_1 -> V_6 -> V_21 . type -> F_92 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
if ( V_68 )
goto V_133;
V_1 -> V_3 = 1 ;
if ( ! V_13 -> V_59 ++ && V_13 -> V_72 ) {
V_13 -> V_57 = NULL ;
F_42 ( V_73 , & V_13 -> V_30 ) ;
} else if ( V_13 -> V_16 && ( V_13 -> V_51 == V_1 -> V_6 ) ) {
if ( F_42 ( V_49 , & V_1 -> V_4 . V_86 ) )
V_13 -> V_50 ++ ;
}
F_90 ( V_137 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_134 , V_13 -> V_59 ) ;
F_91 ( & V_13 -> V_31 ) ;
V_133:
F_44 ( & V_13 -> V_26 , V_70 ) ;
return V_68 ;
}
static int F_93 ( struct V_12 * V_13 , struct V_138 * V_18 ,
T_2 V_139 )
{
int V_68 = - V_97 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_31 (pg, &m->priority_groups, list) {
F_31 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_17 . V_18 == V_18 )
V_68 = V_139 ( V_1 ) ;
}
}
return V_68 ;
}
static void F_94 ( struct V_12 * V_13 , struct V_5 * V_6 ,
int V_58 )
{
unsigned long V_70 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
V_6 -> V_58 = V_58 ;
V_13 -> V_57 = NULL ;
V_13 -> V_51 = NULL ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
F_91 ( & V_13 -> V_31 ) ;
}
static int F_95 ( struct V_12 * V_13 , const char * V_140 )
{
struct V_5 * V_6 ;
unsigned V_141 ;
unsigned long V_70 ;
char V_142 ;
if ( ! V_140 || ( sscanf ( V_140 , L_35 , & V_141 , & V_142 ) != 1 ) || ! V_141 ||
( V_141 > V_13 -> V_122 ) ) {
F_89 ( L_36 ) ;
return - V_97 ;
}
F_41 ( & V_13 -> V_26 , V_70 ) ;
F_31 (pg, &m->priority_groups, list) {
V_6 -> V_58 = 0 ;
if ( -- V_141 )
continue;
V_13 -> V_57 = NULL ;
V_13 -> V_51 = NULL ;
V_13 -> V_61 = V_6 ;
}
F_44 ( & V_13 -> V_26 , V_70 ) ;
F_91 ( & V_13 -> V_31 ) ;
return 0 ;
}
static int F_96 ( struct V_12 * V_13 , const char * V_140 , int V_58 )
{
struct V_5 * V_6 ;
unsigned V_141 ;
char V_142 ;
if ( ! V_140 || ( sscanf ( V_140 , L_35 , & V_141 , & V_142 ) != 1 ) || ! V_141 ||
( V_141 > V_13 -> V_122 ) ) {
F_89 ( L_37 ) ;
return - V_97 ;
}
F_31 (pg, &m->priority_groups, list) {
if ( ! -- V_141 )
break;
}
F_94 ( V_13 , V_6 , V_58 ) ;
return 0 ;
}
static int F_97 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
unsigned long V_70 ;
int V_143 = 0 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( V_13 -> V_45 <= V_13 -> V_119 && ! V_13 -> V_88 )
V_13 -> V_46 = 1 ;
else
V_143 = 1 ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
return V_143 ;
}
static void F_98 ( void * V_144 , int V_145 )
{
struct V_1 * V_1 = V_144 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned long V_70 ;
unsigned V_146 = 0 ;
switch ( V_145 ) {
case V_147 :
break;
case V_148 :
if ( ! V_13 -> V_16 ) {
V_145 = 0 ;
break;
}
F_99 ( L_38
L_39 , V_13 -> V_16 , V_145 ) ;
F_88 ( V_1 ) ;
break;
case V_149 :
F_94 ( V_13 , V_6 , 1 ) ;
break;
case V_150 :
V_146 = 1 ;
case V_151 :
case V_152 :
if ( F_97 ( V_13 , V_1 ) )
F_88 ( V_1 ) ;
V_145 = 0 ;
break;
default:
F_88 ( V_1 ) ;
}
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( V_145 ) {
if ( V_1 == V_13 -> V_57 ) {
F_99 ( L_40 , V_145 ) ;
V_13 -> V_57 = NULL ;
V_13 -> V_51 = NULL ;
}
} else if ( ! V_13 -> V_46 )
V_6 -> V_58 = 0 ;
if ( -- V_13 -> V_50 )
goto V_133;
if ( ! V_13 -> V_46 )
V_13 -> V_27 = 0 ;
V_13 -> V_47 = V_146 ;
F_42 ( V_73 , & V_13 -> V_30 ) ;
F_100 ( & V_13 -> V_32 ) ;
V_133:
F_44 ( & V_13 -> V_26 , V_70 ) ;
}
static void V_4 ( struct V_85 * V_86 )
{
struct V_1 * V_1 =
F_53 ( V_86 , struct V_1 , V_4 . V_86 ) ;
F_101 ( F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ,
F_98 , V_1 ) ;
}
static int F_102 ( int error )
{
switch ( error ) {
case - V_153 :
case - V_154 :
case - V_155 :
case - V_156 :
case - V_157 :
return 1 ;
}
return 0 ;
}
static int F_103 ( struct V_12 * V_13 , struct V_64 * V_65 ,
int error , struct V_39 * V_40 )
{
int V_68 = V_158 ;
unsigned long V_70 ;
if ( ! error && ! V_65 -> V_145 )
return 0 ;
if ( F_102 ( error ) ) {
if ( ( V_65 -> V_131 & V_159 ) &&
! V_65 -> V_77 -> V_160 . V_161 ) {
struct V_162 * V_160 ;
V_160 = F_104 ( F_105 ( V_13 -> V_10 -> V_89 ) ) ;
V_160 -> V_161 = 0 ;
}
return error ;
}
if ( V_40 -> V_1 )
F_88 ( V_40 -> V_1 ) ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( ! V_13 -> V_59 ) {
if ( ! V_13 -> V_62 ) {
if ( ! F_37 ( V_13 ) )
V_68 = - V_80 ;
} else {
if ( error == - V_163 )
V_68 = error ;
}
}
F_44 ( & V_13 -> V_26 , V_70 ) ;
return V_68 ;
}
static int F_106 ( struct V_9 * V_10 , struct V_64 * V_65 ,
int error , union V_37 * V_66 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_39 * V_40 = V_66 -> V_43 ;
struct V_1 * V_1 ;
struct V_20 * V_21 ;
int V_68 ;
F_107 ( ! V_40 ) ;
V_68 = F_103 ( V_13 , V_65 , error , V_40 ) ;
V_1 = V_40 -> V_1 ;
if ( V_1 ) {
V_21 = & V_1 -> V_6 -> V_21 ;
if ( V_21 -> type -> V_164 )
V_21 -> type -> V_164 ( V_21 , & V_1 -> V_17 , V_40 -> V_52 ) ;
}
F_27 ( V_13 , V_66 ) ;
return V_68 ;
}
static void F_108 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
V_62 ( V_13 , 0 , 1 ) ;
}
static void F_109 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_110 ( & V_13 -> V_33 ) ;
F_83 ( V_13 ) ;
F_111 ( & V_13 -> V_33 ) ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
unsigned long V_70 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
V_13 -> V_62 = V_13 -> V_63 ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
}
static void F_113 ( struct V_9 * V_10 , T_3 type ,
unsigned V_165 , char * V_166 , unsigned V_167 )
{
int V_168 = 0 ;
unsigned long V_70 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_100 ;
unsigned V_123 ;
char V_169 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( type == V_170 )
F_114 ( L_41 , V_13 -> V_72 , V_13 -> V_45 ) ;
else {
F_114 ( L_42 , V_13 -> V_62 +
( V_13 -> V_119 > 0 ) * 2 +
( V_13 -> V_28 != V_29 ) * 2 +
V_13 -> V_105 ) ;
if ( V_13 -> V_62 )
F_114 ( L_43 ) ;
if ( V_13 -> V_119 )
F_114 ( L_44 , V_13 -> V_119 ) ;
if ( V_13 -> V_28 != V_29 )
F_114 ( L_45 , V_13 -> V_28 ) ;
if ( V_13 -> V_105 )
F_114 ( L_46 ) ;
}
if ( ! V_13 -> V_16 || type == V_170 )
F_114 ( L_47 ) ;
else
F_114 ( L_48 , V_13 -> V_16 ) ;
F_114 ( L_42 , V_13 -> V_122 ) ;
if ( V_13 -> V_61 )
V_123 = V_13 -> V_61 -> V_123 ;
else if ( V_13 -> V_51 )
V_123 = V_13 -> V_51 -> V_123 ;
else
V_123 = ( V_13 -> V_122 ? 1 : 0 ) ;
F_114 ( L_42 , V_123 ) ;
switch ( type ) {
case V_170 :
F_31 (pg, &m->priority_groups, list) {
if ( V_6 -> V_58 )
V_169 = 'D' ;
else if ( V_6 == V_13 -> V_51 )
V_169 = 'A' ;
else
V_169 = 'E' ;
F_114 ( L_49 , V_169 ) ;
if ( V_6 -> V_21 . type -> V_171 )
V_168 += V_6 -> V_21 . type -> V_171 ( & V_6 -> V_21 , NULL , type ,
V_166 + V_168 ,
V_167 - V_168 ) ;
else
F_114 ( L_47 ) ;
F_114 ( L_50 , V_6 -> V_111 ,
V_6 -> V_21 . type -> V_172 ) ;
F_31 (p, &pg->pgpaths, list) {
F_114 ( L_51 , V_100 -> V_17 . V_18 -> V_134 ,
V_100 -> V_3 ? L_52 : L_53 ,
V_100 -> V_135 ) ;
if ( V_6 -> V_21 . type -> V_171 )
V_168 += V_6 -> V_21 . type -> V_171 ( & V_6 -> V_21 ,
& V_100 -> V_17 , type , V_166 + V_168 ,
V_167 - V_168 ) ;
}
}
break;
case V_173 :
F_31 (pg, &m->priority_groups, list) {
F_114 ( L_54 , V_6 -> V_21 . type -> V_134 ) ;
if ( V_6 -> V_21 . type -> V_171 )
V_168 += V_6 -> V_21 . type -> V_171 ( & V_6 -> V_21 , NULL , type ,
V_166 + V_168 ,
V_167 - V_168 ) ;
else
F_114 ( L_47 ) ;
F_114 ( L_50 , V_6 -> V_111 ,
V_6 -> V_21 . type -> V_174 ) ;
F_31 (p, &pg->pgpaths, list) {
F_114 ( L_54 , V_100 -> V_17 . V_18 -> V_134 ) ;
if ( V_6 -> V_21 . type -> V_171 )
V_168 += V_6 -> V_21 . type -> V_171 ( & V_6 -> V_21 ,
& V_100 -> V_17 , type , V_166 + V_168 ,
V_167 - V_168 ) ;
}
}
break;
}
F_44 ( & V_13 -> V_26 , V_70 ) ;
}
static int F_115 ( struct V_9 * V_10 , unsigned V_103 , char * * V_99 )
{
int V_68 = - V_97 ;
struct V_138 * V_18 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
T_2 V_139 ;
F_110 ( & V_13 -> V_33 ) ;
if ( F_116 ( V_10 ) ) {
V_68 = - V_106 ;
goto V_133;
}
if ( V_103 == 1 ) {
if ( ! strcasecmp ( V_99 [ 0 ] , L_23 ) ) {
V_68 = V_62 ( V_13 , 1 , 0 ) ;
goto V_133;
} else if ( ! strcasecmp ( V_99 [ 0 ] , L_55 ) ) {
V_68 = V_62 ( V_13 , 0 , 0 ) ;
goto V_133;
}
}
if ( V_103 != 2 ) {
F_89 ( L_56 ) ;
goto V_133;
}
if ( ! strcasecmp ( V_99 [ 0 ] , L_57 ) ) {
V_68 = F_96 ( V_13 , V_99 [ 1 ] , 1 ) ;
goto V_133;
} else if ( ! strcasecmp ( V_99 [ 0 ] , L_58 ) ) {
V_68 = F_96 ( V_13 , V_99 [ 1 ] , 0 ) ;
goto V_133;
} else if ( ! strcasecmp ( V_99 [ 0 ] , L_59 ) ) {
V_68 = F_95 ( V_13 , V_99 [ 1 ] ) ;
goto V_133;
} else if ( ! strcasecmp ( V_99 [ 0 ] , L_60 ) )
V_139 = F_92 ;
else if ( ! strcasecmp ( V_99 [ 0 ] , L_61 ) )
V_139 = F_88 ;
else {
F_89 ( L_56 ) ;
goto V_133;
}
V_68 = F_62 ( V_10 , V_99 [ 1 ] , F_63 ( V_10 -> V_89 ) , & V_18 ) ;
if ( V_68 ) {
F_89 ( L_62 ,
V_99 [ 1 ] ) ;
goto V_133;
}
V_68 = F_93 ( V_13 , V_18 , V_139 ) ;
F_13 ( V_10 , V_18 ) ;
V_133:
F_111 ( & V_13 -> V_33 ) ;
return V_68 ;
}
static int F_117 ( struct V_9 * V_10 , unsigned int V_175 ,
unsigned long V_176 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_1 * V_1 ;
struct V_71 * V_19 ;
T_4 V_177 ;
unsigned long V_70 ;
int V_68 ;
V_19 = NULL ;
V_177 = 0 ;
V_68 = 0 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( ! V_13 -> V_57 )
F_36 ( V_13 , 0 ) ;
V_1 = V_13 -> V_57 ;
if ( V_1 ) {
V_19 = V_1 -> V_17 . V_18 -> V_19 ;
V_177 = V_1 -> V_17 . V_18 -> V_177 ;
}
if ( ( V_1 && V_13 -> V_27 ) || ( ! V_1 && V_13 -> V_62 ) )
V_68 = - V_178 ;
else if ( ! V_19 )
V_68 = - V_80 ;
F_44 ( & V_13 -> V_26 , V_70 ) ;
if ( ! V_19 || V_10 -> V_117 != F_118 ( V_19 -> V_179 ) >> V_180 ) {
int V_181 = F_119 ( NULL , V_175 ) ;
if ( V_181 )
V_68 = V_181 ;
}
if ( V_68 == - V_178 && ! F_120 ( V_128 ) )
F_42 ( V_73 , & V_13 -> V_30 ) ;
return V_68 ? : F_121 ( V_19 , V_177 , V_175 , V_176 ) ;
}
static int F_122 ( struct V_9 * V_10 ,
T_5 V_182 , void * V_144 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_100 ;
int V_114 = 0 ;
F_31 (pg, &m->priority_groups, list) {
F_31 (p, &pg->pgpaths, list) {
V_114 = V_182 ( V_10 , V_100 -> V_17 . V_18 , V_10 -> V_183 , V_10 -> V_117 , V_144 ) ;
if ( V_114 )
goto V_133;
}
}
V_133:
return V_114 ;
}
static int F_123 ( struct V_1 * V_1 )
{
struct V_101 * V_77 = F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ;
return F_124 ( V_77 ) ;
}
static int F_125 ( struct V_9 * V_10 )
{
int V_184 = 0 , V_185 = 0 ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_70 ;
F_41 ( & V_13 -> V_26 , V_70 ) ;
if ( V_13 -> V_50 ) {
V_184 = 1 ;
goto V_133;
}
if ( F_126 ( ! V_13 -> V_57 && V_13 -> V_61 ) )
V_6 = V_13 -> V_61 ;
else if ( F_127 ( V_13 -> V_51 ) )
V_6 = V_13 -> V_51 ;
else
goto V_133;
V_184 = 1 ;
F_31 (pgpath, &pg->pgpaths, list)
if ( V_1 -> V_3 ) {
V_185 = 1 ;
if ( ! F_123 ( V_1 ) ) {
V_184 = 0 ;
break;
}
}
if ( ! V_185 )
V_184 = 0 ;
V_133:
F_44 ( & V_13 -> V_26 , V_70 ) ;
return V_184 ;
}
static int T_6 F_128 ( void )
{
int V_68 ;
V_35 = F_129 ( V_39 , 0 ) ;
if ( ! V_35 )
return - V_42 ;
V_68 = F_130 ( & V_186 ) ;
if ( V_68 < 0 ) {
F_99 ( L_63 , V_68 ) ;
F_131 ( V_35 ) ;
return - V_97 ;
}
V_73 = F_132 ( L_64 , V_187 , 0 ) ;
if ( ! V_73 ) {
F_99 ( L_65 ) ;
F_133 ( & V_186 ) ;
F_131 ( V_35 ) ;
return - V_42 ;
}
V_49 = F_134 ( L_66 ,
V_187 ) ;
if ( ! V_49 ) {
F_99 ( L_67 ) ;
F_135 ( V_73 ) ;
F_133 ( & V_186 ) ;
F_131 ( V_35 ) ;
return - V_42 ;
}
F_136 ( L_68 ,
V_186 . V_188 [ 0 ] , V_186 . V_188 [ 1 ] ,
V_186 . V_188 [ 2 ] ) ;
return V_68 ;
}
static void T_7 F_137 ( void )
{
F_135 ( V_49 ) ;
F_135 ( V_73 ) ;
F_133 ( & V_186 ) ;
F_131 ( V_35 ) ;
}
