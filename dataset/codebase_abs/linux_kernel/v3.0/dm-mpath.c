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
static int F_51 ( struct V_87 * V_87 , char * V_88 , unsigned * V_89 , char * * error )
{
if ( ! V_88 ||
( sscanf ( V_88 , L_1 , V_89 ) != 1 ) ||
( * V_89 < V_87 -> V_90 ) ||
( * V_89 > V_87 -> V_91 ) ) {
* error = V_87 -> error ;
return - V_92 ;
}
return 0 ;
}
static char * F_52 ( struct V_93 * V_94 )
{
char * V_62 ;
if ( V_94 -> V_95 ) {
V_94 -> V_95 -- ;
V_62 = * V_94 -> V_96 ;
V_94 -> V_96 ++ ;
return V_62 ;
}
return NULL ;
}
static void F_53 ( struct V_93 * V_94 , unsigned V_79 )
{
F_54 ( V_94 -> V_95 < V_79 ) ;
V_94 -> V_95 -= V_79 ;
V_94 -> V_96 += V_79 ;
}
static int F_55 ( struct V_93 * V_94 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_62 ;
struct V_97 * V_98 ;
unsigned V_99 ;
static struct V_87 V_100 [] = {
{ 0 , 1024 , L_2 } ,
} ;
V_98 = F_56 ( F_52 ( V_94 ) ) ;
if ( ! V_98 ) {
V_10 -> error = L_3 ;
return - V_92 ;
}
V_62 = F_51 ( V_100 , F_52 ( V_94 ) , & V_99 , & V_10 -> error ) ;
if ( V_62 ) {
F_15 ( V_98 ) ;
return - V_92 ;
}
if ( V_99 > V_94 -> V_95 ) {
F_15 ( V_98 ) ;
V_10 -> error = L_4 ;
return - V_92 ;
}
V_62 = V_98 -> V_101 ( & V_6 -> V_21 , V_99 , V_94 -> V_96 ) ;
if ( V_62 ) {
F_15 ( V_98 ) ;
V_10 -> error = L_5 ;
return V_62 ;
}
V_6 -> V_21 . type = V_98 ;
F_53 ( V_94 , V_99 ) ;
return 0 ;
}
static struct V_1 * F_57 ( struct V_93 * V_94 , struct V_20 * V_21 ,
struct V_9 * V_10 )
{
int V_62 ;
struct V_1 * V_102 ;
struct V_12 * V_13 = V_10 -> V_14 ;
if ( V_94 -> V_95 < 1 ) {
V_10 -> error = L_6 ;
return F_58 ( - V_92 ) ;
}
V_102 = F_1 () ;
if ( ! V_102 )
return F_58 ( - V_103 ) ;
V_62 = F_59 ( V_10 , F_52 ( V_94 ) , F_60 ( V_10 -> V_86 ) ,
& V_102 -> V_17 . V_18 ) ;
if ( V_62 ) {
V_10 -> error = L_7 ;
goto V_104;
}
if ( V_13 -> V_16 ) {
struct V_105 * V_70 = F_12 ( V_102 -> V_17 . V_18 -> V_19 ) ;
V_62 = F_61 ( V_70 , V_13 -> V_16 ) ;
if ( V_62 == - V_106 ) {
F_11 ( V_70 ) ;
V_62 = F_61 ( V_70 , V_13 -> V_16 ) ;
}
if ( V_62 < 0 ) {
V_10 -> error = L_8 ;
F_13 ( V_10 , V_102 -> V_17 . V_18 ) ;
goto V_104;
}
if ( V_13 -> V_36 ) {
V_62 = F_62 ( V_70 , V_13 -> V_36 ) ;
if ( V_62 < 0 ) {
V_10 -> error = L_9
L_10 ;
F_11 ( V_70 ) ;
F_13 ( V_10 , V_102 -> V_17 . V_18 ) ;
goto V_104;
}
}
}
V_62 = V_21 -> type -> V_107 ( V_21 , & V_102 -> V_17 , V_94 -> V_95 , V_94 -> V_96 , & V_10 -> error ) ;
if ( V_62 ) {
F_13 ( V_10 , V_102 -> V_17 . V_18 ) ;
goto V_104;
}
return V_102 ;
V_104:
F_4 ( V_102 ) ;
return F_58 ( V_62 ) ;
}
static struct V_5 * F_63 ( struct V_93 * V_94 ,
struct V_12 * V_13 )
{
static struct V_87 V_100 [] = {
{ 1 , 1024 , L_11 } ,
{ 0 , 1024 , L_12 }
} ;
int V_62 ;
unsigned V_108 , V_109 , V_110 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_13 -> V_10 ;
if ( V_94 -> V_95 < 2 ) {
V_94 -> V_95 = 0 ;
V_10 -> error = L_13 ;
return F_58 ( - V_92 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_14 ;
return F_58 ( - V_103 ) ;
}
V_6 -> V_13 = V_13 ;
V_62 = F_55 ( V_94 , V_6 , V_10 ) ;
if ( V_62 )
goto V_104;
V_62 = F_51 ( V_100 , F_52 ( V_94 ) , & V_6 -> V_111 , & V_10 -> error ) ;
if ( V_62 )
goto V_104;
V_62 = F_51 ( V_100 + 1 , F_52 ( V_94 ) , & V_109 , & V_10 -> error ) ;
if ( V_62 )
goto V_104;
V_110 = 1 + V_109 ;
for ( V_108 = 0 ; V_108 < V_6 -> V_111 ; V_108 ++ ) {
struct V_1 * V_1 ;
struct V_93 V_112 ;
if ( V_94 -> V_95 < V_110 ) {
V_10 -> error = L_15 ;
V_62 = - V_92 ;
goto V_104;
}
V_112 . V_95 = V_110 ;
V_112 . V_96 = V_94 -> V_96 ;
V_1 = F_57 ( & V_112 , & V_6 -> V_21 , V_10 ) ;
if ( F_64 ( V_1 ) ) {
V_62 = F_65 ( V_1 ) ;
goto V_104;
}
V_1 -> V_6 = V_6 ;
F_37 ( & V_1 -> V_15 , & V_6 -> V_7 ) ;
F_53 ( V_94 , V_110 ) ;
}
return V_6 ;
V_104:
F_14 ( V_6 , V_10 ) ;
return F_58 ( V_62 ) ;
}
static int F_66 ( struct V_93 * V_94 , struct V_12 * V_13 )
{
unsigned V_113 ;
int V_114 ;
struct V_9 * V_10 = V_13 -> V_10 ;
static struct V_87 V_100 [] = {
{ 0 , 1024 , L_16 } ,
} ;
if ( F_51 ( V_100 , F_52 ( V_94 ) , & V_113 , & V_10 -> error ) )
return - V_92 ;
if ( ! V_113 )
return 0 ;
if ( V_113 > V_94 -> V_95 ) {
V_10 -> error = L_17 ;
return - V_92 ;
}
V_13 -> V_16 = F_67 ( F_52 ( V_94 ) , V_2 ) ;
F_68 ( L_18 , V_13 -> V_16 ) ;
if ( F_69 ( V_13 -> V_16 ) == 0 ) {
V_10 -> error = L_19 ;
V_114 = - V_92 ;
goto V_115;
}
if ( V_113 > 1 ) {
char * V_102 ;
int V_108 , V_116 , V_117 = 4 ;
for ( V_108 = 0 ; V_108 <= V_113 - 2 ; V_108 ++ )
V_117 += strlen ( V_94 -> V_96 [ V_108 ] ) + 1 ;
V_102 = V_13 -> V_36 = F_2 ( V_117 , V_2 ) ;
if ( ! V_102 ) {
V_10 -> error = L_20 ;
V_114 = - V_103 ;
goto V_115;
}
V_116 = sprintf ( V_102 , L_21 , V_113 - 1 ) ;
for ( V_108 = 0 , V_102 += V_116 + 1 ; V_108 <= V_113 - 2 ; V_108 ++ , V_102 += V_116 + 1 )
V_116 = sprintf ( V_102 , L_22 , V_94 -> V_96 [ V_108 ] ) ;
}
F_53 ( V_94 , V_113 - 1 ) ;
return 0 ;
V_115:
F_5 ( V_13 -> V_16 ) ;
V_13 -> V_16 = NULL ;
return V_114 ;
}
static int F_70 ( struct V_93 * V_94 , struct V_12 * V_13 )
{
int V_62 ;
unsigned V_95 ;
struct V_9 * V_10 = V_13 -> V_10 ;
const char * V_118 ;
static struct V_87 V_100 [] = {
{ 0 , 5 , L_23 } ,
{ 1 , 50 , L_24 } ,
{ 0 , 60000 , L_25 } ,
} ;
V_62 = F_51 ( V_100 , F_52 ( V_94 ) , & V_95 , & V_10 -> error ) ;
if ( V_62 )
return - V_92 ;
if ( ! V_95 )
return 0 ;
do {
V_118 = F_52 ( V_94 ) ;
V_95 -- ;
if ( ! F_71 ( V_118 , F_72 ( L_26 ) ) ) {
V_62 = V_55 ( V_13 , 1 , 0 ) ;
continue;
}
if ( ! F_71 ( V_118 , F_72 ( L_27 ) ) &&
( V_95 >= 1 ) ) {
V_62 = F_51 ( V_100 + 1 , F_52 ( V_94 ) ,
& V_13 -> V_119 , & V_10 -> error ) ;
V_95 -- ;
continue;
}
if ( ! F_71 ( V_118 , F_72 ( L_28 ) ) &&
( V_95 >= 1 ) ) {
V_62 = F_51 ( V_100 + 2 , F_52 ( V_94 ) ,
& V_13 -> V_27 , & V_10 -> error ) ;
V_95 -- ;
continue;
}
V_10 -> error = L_29 ;
V_62 = - V_92 ;
} while ( V_95 && ! V_62 );
return V_62 ;
}
static int F_73 ( struct V_9 * V_10 , unsigned int V_95 ,
char * * V_96 )
{
static struct V_87 V_100 [] = {
{ 0 , 1024 , L_30 } ,
{ 0 , 1024 , L_31 } ,
} ;
int V_62 ;
struct V_12 * V_13 ;
struct V_93 V_94 ;
unsigned V_120 = 0 ;
unsigned V_121 ;
V_94 . V_95 = V_95 ;
V_94 . V_96 = V_96 ;
V_13 = F_16 ( V_10 ) ;
if ( ! V_13 ) {
V_10 -> error = L_32 ;
return - V_92 ;
}
V_62 = F_70 ( & V_94 , V_13 ) ;
if ( V_62 )
goto V_104;
V_62 = F_66 ( & V_94 , V_13 ) ;
if ( V_62 )
goto V_104;
V_62 = F_51 ( V_100 , F_52 ( & V_94 ) , & V_13 -> V_122 , & V_10 -> error ) ;
if ( V_62 )
goto V_104;
V_62 = F_51 ( V_100 + 1 , F_52 ( & V_94 ) , & V_121 , & V_10 -> error ) ;
if ( V_62 )
goto V_104;
if ( ( ! V_13 -> V_122 && V_121 ) ||
( V_13 -> V_122 && ! V_121 ) ) {
V_10 -> error = L_33 ;
V_62 = - V_92 ;
goto V_104;
}
while ( V_94 . V_95 ) {
struct V_5 * V_6 ;
V_6 = F_63 ( & V_94 , V_13 ) ;
if ( F_64 ( V_6 ) ) {
V_62 = F_65 ( V_6 ) ;
goto V_104;
}
V_13 -> V_52 += V_6 -> V_111 ;
F_37 ( & V_6 -> V_15 , & V_13 -> V_23 ) ;
V_120 ++ ;
V_6 -> V_123 = V_120 ;
if ( ! -- V_121 )
V_13 -> V_54 = V_6 ;
}
if ( V_120 != V_13 -> V_122 ) {
V_10 -> error = L_34 ;
V_62 = - V_92 ;
goto V_104;
}
V_10 -> V_124 = 1 ;
V_10 -> V_125 = 1 ;
return 0 ;
V_104:
F_22 ( V_13 ) ;
return V_62 ;
}
static void F_74 ( struct V_12 * V_13 )
{
F_75 ( V_126 , V_127 ) ;
unsigned long V_64 ;
F_76 ( & V_13 -> V_31 , & V_126 ) ;
while ( 1 ) {
F_77 ( V_128 ) ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_13 -> V_43 ) {
F_39 ( & V_13 -> V_25 , V_64 ) ;
break;
}
F_39 ( & V_13 -> V_25 , V_64 ) ;
F_78 () ;
}
F_77 ( V_129 ) ;
F_79 ( & V_13 -> V_31 , & V_126 ) ;
}
static void F_80 ( struct V_12 * V_13 )
{
F_81 ( V_42 ) ;
F_74 ( V_13 ) ;
F_81 ( V_68 ) ;
F_82 ( & V_13 -> V_30 ) ;
}
static void F_83 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_80 ( V_13 ) ;
F_22 ( V_13 ) ;
}
static int F_84 ( struct V_9 * V_10 , struct V_57 * V_58 ,
union V_77 * V_130 )
{
int V_62 ;
struct V_59 * V_60 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
V_60 = F_85 ( V_13 -> V_33 , V_131 ) ;
if ( ! V_60 )
return V_73 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_130 -> V_81 = V_60 ;
V_58 -> V_132 |= V_133 ;
V_62 = F_34 ( V_13 , V_58 , V_60 , 0 ) ;
if ( V_62 < 0 || V_62 == V_73 )
F_45 ( V_60 , V_13 -> V_33 ) ;
return V_62 ;
}
static int F_86 ( struct V_1 * V_1 )
{
unsigned long V_64 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_1 -> V_3 )
goto V_85;
F_87 ( L_35 , V_1 -> V_17 . V_18 -> V_134 ) ;
V_1 -> V_6 -> V_21 . type -> F_86 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
V_1 -> V_3 = 0 ;
V_1 -> V_135 ++ ;
V_13 -> V_52 -- ;
if ( V_1 == V_13 -> V_50 )
V_13 -> V_50 = NULL ;
F_88 ( V_136 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_134 , V_13 -> V_52 ) ;
F_89 ( & V_13 -> V_30 ) ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_1 )
{
int V_62 = 0 ;
unsigned long V_64 ;
struct V_12 * V_13 = V_1 -> V_6 -> V_13 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( V_1 -> V_3 )
goto V_85;
if ( ! V_1 -> V_6 -> V_21 . type -> F_90 ) {
F_87 ( L_36 ,
V_1 -> V_6 -> V_21 . type -> V_134 ) ;
V_62 = - V_92 ;
goto V_85;
}
V_62 = V_1 -> V_6 -> V_21 . type -> F_90 ( & V_1 -> V_6 -> V_21 , & V_1 -> V_17 ) ;
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
F_88 ( V_137 , V_13 -> V_10 ,
V_1 -> V_17 . V_18 -> V_134 , V_13 -> V_52 ) ;
F_89 ( & V_13 -> V_30 ) ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_62 ;
}
static int F_91 ( struct V_12 * V_13 , struct V_138 * V_18 ,
T_2 V_139 )
{
int V_62 = - V_92 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_26 (pg, &m->priority_groups, list) {
F_26 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_17 . V_18 == V_18 )
V_62 = V_139 ( V_1 ) ;
}
}
return V_62 ;
}
static void F_92 ( struct V_12 * V_13 , struct V_5 * V_6 ,
int V_51 )
{
unsigned long V_64 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
V_6 -> V_51 = V_51 ;
V_13 -> V_50 = NULL ;
V_13 -> V_44 = NULL ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
F_89 ( & V_13 -> V_30 ) ;
}
static int F_93 ( struct V_12 * V_13 , const char * V_140 )
{
struct V_5 * V_6 ;
unsigned V_141 ;
unsigned long V_64 ;
if ( ! V_140 || ( sscanf ( V_140 , L_1 , & V_141 ) != 1 ) || ! V_141 ||
( V_141 > V_13 -> V_122 ) ) {
F_87 ( L_37 ) ;
return - V_92 ;
}
F_36 ( & V_13 -> V_25 , V_64 ) ;
F_26 (pg, &m->priority_groups, list) {
V_6 -> V_51 = 0 ;
if ( -- V_141 )
continue;
V_13 -> V_50 = NULL ;
V_13 -> V_44 = NULL ;
V_13 -> V_54 = V_6 ;
}
F_39 ( & V_13 -> V_25 , V_64 ) ;
F_89 ( & V_13 -> V_30 ) ;
return 0 ;
}
static int F_94 ( struct V_12 * V_13 , const char * V_140 , int V_51 )
{
struct V_5 * V_6 ;
unsigned V_141 ;
if ( ! V_140 || ( sscanf ( V_140 , L_1 , & V_141 ) != 1 ) || ! V_141 ||
( V_141 > V_13 -> V_122 ) ) {
F_87 ( L_38 ) ;
return - V_92 ;
}
F_26 (pg, &m->priority_groups, list) {
if ( ! -- V_141 )
break;
}
F_92 ( V_13 , V_6 , V_51 ) ;
return 0 ;
}
static int F_95 ( struct V_12 * V_13 , struct V_1 * V_1 )
{
unsigned long V_64 ;
int V_142 = 0 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( V_13 -> V_38 <= V_13 -> V_119 )
V_13 -> V_39 = 1 ;
else
V_142 = 1 ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_142 ;
}
static void F_96 ( void * V_143 , int V_144 )
{
struct V_1 * V_1 = V_143 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_12 * V_13 = V_6 -> V_13 ;
unsigned long V_64 ;
unsigned V_145 = 0 ;
switch ( V_144 ) {
case V_146 :
break;
case V_147 :
if ( ! V_13 -> V_16 ) {
V_144 = 0 ;
break;
}
F_97 ( L_39
L_40 , V_13 -> V_16 , V_144 ) ;
F_86 ( V_1 ) ;
break;
case V_148 :
F_92 ( V_13 , V_6 , 1 ) ;
break;
case V_149 :
V_145 = 1 ;
case V_150 :
case V_151 :
if ( F_95 ( V_13 , V_1 ) )
F_86 ( V_1 ) ;
V_144 = 0 ;
break;
default:
F_86 ( V_1 ) ;
}
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( V_144 ) {
if ( V_1 == V_13 -> V_50 ) {
F_97 ( L_41 , V_144 ) ;
V_13 -> V_50 = NULL ;
V_13 -> V_44 = NULL ;
}
} else if ( ! V_13 -> V_39 )
V_6 -> V_51 = 0 ;
if ( -- V_13 -> V_43 )
goto V_85;
if ( ! V_13 -> V_39 )
V_13 -> V_26 = 0 ;
V_13 -> V_40 = V_145 ;
F_38 ( V_68 , & V_13 -> V_29 ) ;
F_98 ( & V_13 -> V_31 ) ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
}
static void V_4 ( struct V_82 * V_83 )
{
struct V_1 * V_1 =
F_49 ( V_83 , struct V_1 , V_4 . V_83 ) ;
F_99 ( F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ,
F_96 , V_1 ) ;
}
static int F_100 ( struct V_12 * V_13 , struct V_57 * V_58 ,
int error , struct V_59 * V_60 )
{
int V_62 = V_152 ;
unsigned long V_64 ;
if ( ! error && ! V_58 -> V_144 )
return 0 ;
if ( error == - V_153 || error == - V_154 || error == - V_155 )
return error ;
if ( V_60 -> V_1 )
F_86 ( V_60 -> V_1 ) ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_13 -> V_52 ) {
if ( ! V_13 -> V_55 ) {
if ( ! F_32 ( V_13 ) )
V_62 = - V_74 ;
} else {
if ( error == - V_156 )
V_62 = error ;
}
}
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_62 ;
}
static int F_101 ( struct V_9 * V_10 , struct V_57 * V_58 ,
int error , union V_77 * V_130 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_59 * V_60 = V_130 -> V_81 ;
struct V_1 * V_1 = V_60 -> V_1 ;
struct V_20 * V_21 ;
int V_62 ;
V_62 = F_100 ( V_13 , V_58 , error , V_60 ) ;
if ( V_1 ) {
V_21 = & V_1 -> V_6 -> V_21 ;
if ( V_21 -> type -> V_157 )
V_21 -> type -> V_157 ( V_21 , & V_1 -> V_17 , V_60 -> V_45 ) ;
}
F_45 ( V_60 , V_13 -> V_33 ) ;
return V_62 ;
}
static void F_102 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
V_55 ( V_13 , 0 , 1 ) ;
}
static void F_103 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
F_104 ( & V_13 -> V_32 ) ;
F_80 ( V_13 ) ;
F_105 ( & V_13 -> V_32 ) ;
}
static void F_106 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
unsigned long V_64 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
V_13 -> V_55 = V_13 -> V_56 ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
}
static int F_107 ( struct V_9 * V_10 , T_3 type ,
char * V_158 , unsigned int V_159 )
{
int V_160 = 0 ;
unsigned long V_64 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_102 ;
unsigned V_123 ;
char V_161 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( type == V_162 )
F_108 ( L_42 , V_13 -> V_66 , V_13 -> V_38 ) ;
else {
F_108 ( L_43 , V_13 -> V_55 +
( V_13 -> V_119 > 0 ) * 2 +
( V_13 -> V_27 != V_28 ) * 2 ) ;
if ( V_13 -> V_55 )
F_108 ( L_44 ) ;
if ( V_13 -> V_119 )
F_108 ( L_45 , V_13 -> V_119 ) ;
if ( V_13 -> V_27 != V_28 )
F_108 ( L_46 , V_13 -> V_27 ) ;
}
if ( ! V_13 -> V_16 || type == V_162 )
F_108 ( L_47 ) ;
else
F_108 ( L_48 , V_13 -> V_16 ) ;
F_108 ( L_43 , V_13 -> V_122 ) ;
if ( V_13 -> V_54 )
V_123 = V_13 -> V_54 -> V_123 ;
else if ( V_13 -> V_44 )
V_123 = V_13 -> V_44 -> V_123 ;
else
V_123 = ( V_13 -> V_122 ? 1 : 0 ) ;
F_108 ( L_43 , V_123 ) ;
switch ( type ) {
case V_162 :
F_26 (pg, &m->priority_groups, list) {
if ( V_6 -> V_51 )
V_161 = 'D' ;
else if ( V_6 == V_13 -> V_44 )
V_161 = 'A' ;
else
V_161 = 'E' ;
F_108 ( L_49 , V_161 ) ;
if ( V_6 -> V_21 . type -> V_163 )
V_160 += V_6 -> V_21 . type -> V_163 ( & V_6 -> V_21 , NULL , type ,
V_158 + V_160 ,
V_159 - V_160 ) ;
else
F_108 ( L_47 ) ;
F_108 ( L_50 , V_6 -> V_111 ,
V_6 -> V_21 . type -> V_164 ) ;
F_26 (p, &pg->pgpaths, list) {
F_108 ( L_51 , V_102 -> V_17 . V_18 -> V_134 ,
V_102 -> V_3 ? L_52 : L_53 ,
V_102 -> V_135 ) ;
if ( V_6 -> V_21 . type -> V_163 )
V_160 += V_6 -> V_21 . type -> V_163 ( & V_6 -> V_21 ,
& V_102 -> V_17 , type , V_158 + V_160 ,
V_159 - V_160 ) ;
}
}
break;
case V_165 :
F_26 (pg, &m->priority_groups, list) {
F_108 ( L_54 , V_6 -> V_21 . type -> V_134 ) ;
if ( V_6 -> V_21 . type -> V_163 )
V_160 += V_6 -> V_21 . type -> V_163 ( & V_6 -> V_21 , NULL , type ,
V_158 + V_160 ,
V_159 - V_160 ) ;
else
F_108 ( L_47 ) ;
F_108 ( L_50 , V_6 -> V_111 ,
V_6 -> V_21 . type -> V_166 ) ;
F_26 (p, &pg->pgpaths, list) {
F_108 ( L_54 , V_102 -> V_17 . V_18 -> V_134 ) ;
if ( V_6 -> V_21 . type -> V_163 )
V_160 += V_6 -> V_21 . type -> V_163 ( & V_6 -> V_21 ,
& V_102 -> V_17 , type , V_158 + V_160 ,
V_159 - V_160 ) ;
}
}
break;
}
F_39 ( & V_13 -> V_25 , V_64 ) ;
return 0 ;
}
static int F_109 ( struct V_9 * V_10 , unsigned V_95 , char * * V_96 )
{
int V_62 = - V_92 ;
struct V_138 * V_18 ;
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
T_2 V_139 ;
F_104 ( & V_13 -> V_32 ) ;
if ( F_110 ( V_10 ) ) {
V_62 = - V_106 ;
goto V_85;
}
if ( V_95 == 1 ) {
if ( ! F_71 ( V_96 [ 0 ] , F_72 ( L_26 ) ) ) {
V_62 = V_55 ( V_13 , 1 , 0 ) ;
goto V_85;
} else if ( ! F_71 ( V_96 [ 0 ] , F_72 ( L_55 ) ) ) {
V_62 = V_55 ( V_13 , 0 , 0 ) ;
goto V_85;
}
}
if ( V_95 != 2 ) {
F_87 ( L_56 ) ;
goto V_85;
}
if ( ! F_71 ( V_96 [ 0 ] , F_72 ( L_57 ) ) ) {
V_62 = F_94 ( V_13 , V_96 [ 1 ] , 1 ) ;
goto V_85;
} else if ( ! F_71 ( V_96 [ 0 ] , F_72 ( L_58 ) ) ) {
V_62 = F_94 ( V_13 , V_96 [ 1 ] , 0 ) ;
goto V_85;
} else if ( ! F_71 ( V_96 [ 0 ] , F_72 ( L_59 ) ) ) {
V_62 = F_93 ( V_13 , V_96 [ 1 ] ) ;
goto V_85;
} else if ( ! F_71 ( V_96 [ 0 ] , F_72 ( L_60 ) ) )
V_139 = F_90 ;
else if ( ! F_71 ( V_96 [ 0 ] , F_72 ( L_61 ) ) )
V_139 = F_86 ;
else {
F_87 ( L_56 ) ;
goto V_85;
}
V_62 = F_59 ( V_10 , V_96 [ 1 ] , F_60 ( V_10 -> V_86 ) , & V_18 ) ;
if ( V_62 ) {
F_87 ( L_62 ,
V_96 [ 1 ] ) ;
goto V_85;
}
V_62 = F_91 ( V_13 , V_18 , V_139 ) ;
F_13 ( V_10 , V_18 ) ;
V_85:
F_105 ( & V_13 -> V_32 ) ;
return V_62 ;
}
static int F_111 ( struct V_9 * V_10 , unsigned int V_167 ,
unsigned long V_168 )
{
struct V_12 * V_13 = (struct V_12 * ) V_10 -> V_14 ;
struct V_65 * V_19 = NULL ;
T_4 V_169 = 0 ;
unsigned long V_64 ;
int V_62 = 0 ;
F_36 ( & V_13 -> V_25 , V_64 ) ;
if ( ! V_13 -> V_50 )
F_31 ( V_13 , 0 ) ;
if ( V_13 -> V_50 ) {
V_19 = V_13 -> V_50 -> V_17 . V_18 -> V_19 ;
V_169 = V_13 -> V_50 -> V_17 . V_18 -> V_169 ;
}
if ( V_13 -> V_26 )
V_62 = - V_170 ;
else if ( ! V_19 )
V_62 = - V_74 ;
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_62 ? : F_112 ( V_19 , V_169 , V_167 , V_168 ) ;
}
static int F_113 ( struct V_9 * V_10 ,
T_5 V_171 , void * V_143 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_5 * V_6 ;
struct V_1 * V_102 ;
int V_114 = 0 ;
F_26 (pg, &m->priority_groups, list) {
F_26 (p, &pg->pgpaths, list) {
V_114 = V_171 ( V_10 , V_102 -> V_17 . V_18 , V_10 -> V_172 , V_10 -> V_117 , V_143 ) ;
if ( V_114 )
goto V_85;
}
}
V_85:
return V_114 ;
}
static int F_114 ( struct V_1 * V_1 )
{
struct V_105 * V_70 = F_12 ( V_1 -> V_17 . V_18 -> V_19 ) ;
return F_115 ( V_70 ) ;
}
static int F_116 ( struct V_9 * V_10 )
{
int V_173 = 0 , V_174 = 0 ;
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
V_173 = 1 ;
F_26 (pgpath, &pg->pgpaths, list)
if ( V_1 -> V_3 ) {
V_174 = 1 ;
if ( ! F_114 ( V_1 ) ) {
V_173 = 0 ;
break;
}
}
if ( ! V_174 )
V_173 = 0 ;
V_85:
F_39 ( & V_13 -> V_25 , V_64 ) ;
return V_173 ;
}
static int T_6 F_119 ( void )
{
int V_62 ;
V_35 = F_120 ( V_59 , 0 ) ;
if ( ! V_35 )
return - V_103 ;
V_62 = F_121 ( & V_175 ) ;
if ( V_62 < 0 ) {
F_97 ( L_63 , V_62 ) ;
F_122 ( V_35 ) ;
return - V_92 ;
}
V_68 = F_123 ( L_64 , V_176 , 0 ) ;
if ( ! V_68 ) {
F_97 ( L_65 ) ;
F_124 ( & V_175 ) ;
F_122 ( V_35 ) ;
return - V_103 ;
}
V_42 = F_125 ( L_66 ,
V_176 ) ;
if ( ! V_42 ) {
F_97 ( L_67 ) ;
F_126 ( V_68 ) ;
F_124 ( & V_175 ) ;
F_122 ( V_35 ) ;
return - V_103 ;
}
F_127 ( L_68 ,
V_175 . V_177 [ 0 ] , V_175 . V_177 [ 1 ] ,
V_175 . V_177 [ 2 ] ) ;
return V_62 ;
}
static void T_7 F_128 ( void )
{
F_126 ( V_42 ) ;
F_126 ( V_68 ) ;
F_124 ( & V_175 ) ;
F_122 ( V_35 ) ;
}
