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
unsigned V_20 = F_15 () ;
V_19 = F_2 ( sizeof( * V_19 ) , V_2 ) ;
if ( V_19 ) {
F_7 ( & V_19 -> V_21 ) ;
F_16 ( & V_19 -> V_22 ) ;
V_19 -> V_23 = 1 ;
V_19 -> V_24 = V_25 ;
F_17 ( & V_19 -> V_26 , V_26 ) ;
F_18 ( & V_19 -> V_27 ) ;
F_19 ( & V_19 -> V_28 ) ;
V_19 -> V_29 = F_20 ( V_20 , V_30 ) ;
if ( ! V_19 -> V_29 ) {
F_5 ( V_19 ) ;
return NULL ;
}
V_19 -> V_10 = V_10 ;
V_10 -> V_31 = V_19 ;
}
return V_19 ;
}
static void F_21 ( struct V_18 * V_19 )
{
struct V_5 * V_6 , * V_11 ;
F_9 (pg, tmp, &m->priority_groups, list) {
F_10 ( & V_6 -> V_12 ) ;
F_12 ( V_6 , V_19 -> V_10 ) ;
}
F_5 ( V_19 -> V_32 ) ;
F_5 ( V_19 -> V_33 ) ;
F_22 ( V_19 -> V_29 ) ;
F_5 ( V_19 ) ;
}
static int F_23 ( struct V_18 * V_19 , union V_34 * V_35 )
{
struct V_36 * V_37 ;
V_37 = F_24 ( V_19 -> V_29 , V_38 ) ;
if ( ! V_37 )
return - V_39 ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_35 -> V_40 = V_37 ;
return 0 ;
}
static void F_25 ( struct V_18 * V_19 , union V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_40 ;
V_35 -> V_40 = NULL ;
F_26 ( V_37 , V_19 -> V_29 ) ;
}
static int F_27 ( struct V_18 * V_19 )
{
struct V_1 * V_1 ;
unsigned long V_41 = 0 ;
if ( V_19 -> V_42 || V_19 -> V_43 )
return 0 ;
V_19 -> V_44 ++ ;
V_19 -> V_45 = 0 ;
if ( ! V_19 -> V_46 )
return 0 ;
if ( V_19 -> V_47 )
V_41 = F_28 ( V_19 -> V_24 != V_25 ?
V_19 -> V_24 : V_48 ) ;
F_29 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_30 ( V_49 , & V_1 -> V_4 ,
V_41 ) )
V_19 -> V_42 ++ ;
}
return V_19 -> V_42 ;
}
static void F_31 ( struct V_18 * V_19 , struct V_1 * V_1 )
{
V_19 -> V_46 = V_1 -> V_6 ;
if ( V_19 -> V_32 ) {
V_19 -> V_45 = 1 ;
V_19 -> V_23 = 1 ;
} else {
V_19 -> V_45 = 0 ;
V_19 -> V_23 = 0 ;
}
V_19 -> V_44 = 0 ;
}
static int F_32 ( struct V_18 * V_19 , struct V_5 * V_6 ,
T_1 V_50 )
{
struct V_51 * V_13 ;
V_13 = V_6 -> V_16 . type -> V_52 ( & V_6 -> V_16 , & V_19 -> V_53 , V_50 ) ;
if ( ! V_13 )
return - V_54 ;
V_19 -> V_55 = F_33 ( V_13 ) ;
if ( V_19 -> V_46 != V_6 )
F_31 ( V_19 , V_19 -> V_55 ) ;
return 0 ;
}
static void F_34 ( struct V_18 * V_19 , T_1 V_50 )
{
struct V_5 * V_6 ;
unsigned V_56 = 1 ;
if ( ! V_19 -> V_57 ) {
V_19 -> V_23 = 0 ;
goto V_58;
}
if ( V_19 -> V_59 ) {
V_6 = V_19 -> V_59 ;
V_19 -> V_59 = NULL ;
if ( ! F_32 ( V_19 , V_6 , V_50 ) )
return;
}
if ( V_19 -> V_46 && ! F_32 ( V_19 , V_19 -> V_46 , V_50 ) )
return;
do {
F_29 (pg, &m->priority_groups, list) {
if ( V_6 -> V_56 == V_56 )
continue;
if ( ! F_32 ( V_19 , V_6 , V_50 ) ) {
if ( ! V_56 )
V_19 -> V_47 = 1 ;
return;
}
}
} while ( V_56 -- );
V_58:
V_19 -> V_55 = NULL ;
V_19 -> V_46 = NULL ;
}
static int F_35 ( struct V_18 * V_19 )
{
return ( V_19 -> V_60 ||
( V_19 -> V_60 != V_19 -> V_61 &&
F_36 ( V_19 -> V_10 ) ) ) ;
}
static int F_37 ( struct V_9 * V_10 , struct V_62 * V_63 ,
union V_34 * V_64 ,
struct V_62 * V_65 , struct V_62 * * V_66 )
{
struct V_18 * V_19 = (struct V_18 * ) V_10 -> V_31 ;
int V_67 = V_68 ;
T_1 V_50 = V_63 ? F_38 ( V_63 ) : F_38 ( V_65 ) ;
struct V_1 * V_1 ;
struct V_69 * V_70 ;
struct V_36 * V_37 ;
F_39 ( & V_19 -> V_22 ) ;
if ( ! V_19 -> V_55 ||
( ! V_19 -> V_23 && ( V_19 -> V_53 && -- V_19 -> V_53 == 0 ) ) )
F_34 ( V_19 , V_50 ) ;
V_1 = V_19 -> V_55 ;
if ( ! V_1 ) {
if ( ! F_35 ( V_19 ) )
V_67 = - V_71 ;
goto V_72;
} else if ( V_19 -> V_23 || V_19 -> V_45 ) {
F_27 ( V_19 ) ;
goto V_72;
}
if ( F_23 ( V_19 , V_64 ) < 0 )
goto V_72;
V_37 = V_64 -> V_40 ;
V_37 -> V_1 = V_1 ;
V_37 -> V_50 = V_50 ;
V_70 = V_1 -> V_13 . V_14 -> V_70 ;
F_40 ( & V_19 -> V_22 ) ;
if ( V_63 ) {
V_63 -> V_73 = F_41 ( V_70 ) ;
V_63 -> V_74 = V_70 -> V_75 ;
V_63 -> V_76 |= V_77 ;
} else {
* V_66 = F_42 ( F_41 ( V_70 ) ,
F_43 ( V_65 ) , V_38 ) ;
if ( F_44 ( * V_66 ) ) {
F_25 ( V_19 , V_64 ) ;
return V_67 ;
}
( * V_66 ) -> V_78 = ( * V_66 ) -> V_79 = NULL ;
( * V_66 ) -> V_74 = V_70 -> V_75 ;
( * V_66 ) -> V_76 |= V_77 ;
}
if ( V_1 -> V_6 -> V_16 . type -> V_80 )
V_1 -> V_6 -> V_16 . type -> V_80 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_50 ) ;
return V_81 ;
V_72:
F_40 ( & V_19 -> V_22 ) ;
return V_67 ;
}
static int F_45 ( struct V_9 * V_10 , struct V_62 * V_63 ,
union V_34 * V_64 )
{
return F_37 ( V_10 , V_63 , V_64 , NULL , NULL ) ;
}
static int F_46 ( struct V_9 * V_10 , struct V_62 * V_65 ,
union V_34 * V_64 ,
struct V_62 * * V_63 )
{
return F_37 ( V_10 , NULL , V_64 , V_65 , V_63 ) ;
}
static void F_47 ( struct V_62 * V_63 )
{
F_48 ( V_63 ) ;
}
static int V_60 ( struct V_18 * V_19 , unsigned V_60 ,
unsigned V_82 )
{
unsigned long V_83 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( V_82 )
V_19 -> V_61 = V_19 -> V_60 ;
else
V_19 -> V_61 = V_60 ;
V_19 -> V_60 = V_60 ;
F_50 ( & V_19 -> V_22 , V_83 ) ;
if ( ! V_60 )
F_51 ( V_19 -> V_10 -> V_84 ) ;
return 0 ;
}
static void V_26 ( struct V_85 * V_86 )
{
struct V_18 * V_19 =
F_52 ( V_86 , struct V_18 , V_26 ) ;
F_53 ( V_19 -> V_10 -> V_84 ) ;
}
static int F_54 ( struct V_87 * V_88 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_67 ;
struct V_89 * V_90 ;
unsigned V_91 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_90 = F_55 ( F_56 ( V_88 ) ) ;
if ( ! V_90 ) {
V_10 -> error = L_2 ;
return - V_94 ;
}
V_67 = F_57 ( V_93 , V_88 , & V_91 , & V_10 -> error ) ;
if ( V_67 ) {
F_13 ( V_90 ) ;
return - V_94 ;
}
V_67 = V_90 -> V_95 ( & V_6 -> V_16 , V_91 , V_88 -> V_96 ) ;
if ( V_67 ) {
F_13 ( V_90 ) ;
V_10 -> error = L_3 ;
return V_67 ;
}
V_6 -> V_16 . type = V_90 ;
F_58 ( V_88 , V_91 ) ;
return 0 ;
}
static struct V_1 * F_59 ( struct V_87 * V_88 , struct V_15 * V_16 ,
struct V_9 * V_10 )
{
int V_67 ;
struct V_1 * V_97 ;
struct V_18 * V_19 = V_10 -> V_31 ;
struct V_98 * V_73 = NULL ;
const char * V_99 ;
if ( V_88 -> V_100 < 1 ) {
V_10 -> error = L_4 ;
return F_60 ( - V_94 ) ;
}
V_97 = F_1 () ;
if ( ! V_97 )
return F_60 ( - V_39 ) ;
V_67 = F_61 ( V_10 , F_56 ( V_88 ) , F_62 ( V_10 -> V_84 ) ,
& V_97 -> V_13 . V_14 ) ;
if ( V_67 ) {
V_10 -> error = L_5 ;
goto V_101;
}
if ( V_19 -> V_102 || V_19 -> V_32 )
V_73 = F_41 ( V_97 -> V_13 . V_14 -> V_70 ) ;
if ( V_19 -> V_102 ) {
V_103:
V_99 = F_63 ( V_73 , V_2 ) ;
if ( V_99 ) {
F_5 ( V_19 -> V_32 ) ;
V_19 -> V_32 = V_99 ;
F_5 ( V_19 -> V_33 ) ;
V_19 -> V_33 = NULL ;
}
}
if ( V_19 -> V_32 ) {
V_67 = F_64 ( V_73 , V_19 -> V_32 ) ;
if ( V_67 == - V_104 ) {
char V_105 [ V_106 ] ;
F_65 ( V_107 L_6 ,
F_66 ( V_97 -> V_13 . V_14 -> V_70 , V_105 ) ) ;
goto V_103;
}
if ( V_67 < 0 ) {
V_10 -> error = L_7 ;
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_101;
}
if ( V_19 -> V_33 ) {
V_67 = F_67 ( V_73 , V_19 -> V_33 ) ;
if ( V_67 < 0 ) {
V_10 -> error = L_8
L_9 ;
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_101;
}
}
}
V_67 = V_16 -> type -> V_108 ( V_16 , & V_97 -> V_13 , V_88 -> V_100 , V_88 -> V_96 , & V_10 -> error ) ;
if ( V_67 ) {
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_101;
}
return V_97 ;
V_101:
F_4 ( V_97 ) ;
return F_60 ( V_67 ) ;
}
static struct V_5 * F_68 ( struct V_87 * V_88 ,
struct V_18 * V_19 )
{
static struct V_92 V_93 [] = {
{ 1 , 1024 , L_10 } ,
{ 0 , 1024 , L_11 }
} ;
int V_67 ;
unsigned V_109 , V_110 , V_111 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_19 -> V_10 ;
if ( V_88 -> V_100 < 2 ) {
V_88 -> V_100 = 0 ;
V_10 -> error = L_12 ;
return F_60 ( - V_94 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_13 ;
return F_60 ( - V_39 ) ;
}
V_6 -> V_19 = V_19 ;
V_67 = F_54 ( V_88 , V_6 , V_10 ) ;
if ( V_67 )
goto V_101;
V_67 = F_69 ( V_93 , V_88 , & V_6 -> V_112 , & V_10 -> error ) ;
if ( V_67 )
goto V_101;
V_67 = F_69 ( V_93 + 1 , V_88 , & V_110 , & V_10 -> error ) ;
if ( V_67 )
goto V_101;
V_111 = 1 + V_110 ;
for ( V_109 = 0 ; V_109 < V_6 -> V_112 ; V_109 ++ ) {
struct V_1 * V_1 ;
struct V_87 V_113 ;
if ( V_88 -> V_100 < V_111 ) {
V_10 -> error = L_14 ;
V_67 = - V_94 ;
goto V_101;
}
V_113 . V_100 = V_111 ;
V_113 . V_96 = V_88 -> V_96 ;
V_1 = F_59 ( & V_113 , & V_6 -> V_16 , V_10 ) ;
if ( F_44 ( V_1 ) ) {
V_67 = F_70 ( V_1 ) ;
goto V_101;
}
V_1 -> V_6 = V_6 ;
F_71 ( & V_1 -> V_12 , & V_6 -> V_7 ) ;
F_58 ( V_88 , V_111 ) ;
}
return V_6 ;
V_101:
F_12 ( V_6 , V_10 ) ;
return F_60 ( V_67 ) ;
}
static int F_72 ( struct V_87 * V_88 , struct V_18 * V_19 )
{
unsigned V_114 ;
int V_115 ;
struct V_9 * V_10 = V_19 -> V_10 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_15 } ,
} ;
if ( F_57 ( V_93 , V_88 , & V_114 , & V_10 -> error ) )
return - V_94 ;
if ( ! V_114 )
return 0 ;
V_19 -> V_32 = F_73 ( F_56 ( V_88 ) , V_2 ) ;
if ( V_114 > 1 ) {
char * V_97 ;
int V_109 , V_116 , V_117 = 4 ;
for ( V_109 = 0 ; V_109 <= V_114 - 2 ; V_109 ++ )
V_117 += strlen ( V_88 -> V_96 [ V_109 ] ) + 1 ;
V_97 = V_19 -> V_33 = F_2 ( V_117 , V_2 ) ;
if ( ! V_97 ) {
V_10 -> error = L_16 ;
V_115 = - V_39 ;
goto V_118;
}
V_116 = sprintf ( V_97 , L_17 , V_114 - 1 ) ;
for ( V_109 = 0 , V_97 += V_116 + 1 ; V_109 <= V_114 - 2 ; V_109 ++ , V_97 += V_116 + 1 )
V_116 = sprintf ( V_97 , L_18 , V_88 -> V_96 [ V_109 ] ) ;
}
F_58 ( V_88 , V_114 - 1 ) ;
return 0 ;
V_118:
F_5 ( V_19 -> V_32 ) ;
V_19 -> V_32 = NULL ;
return V_115 ;
}
static int F_74 ( struct V_87 * V_88 , struct V_18 * V_19 )
{
int V_67 ;
unsigned V_100 ;
struct V_9 * V_10 = V_19 -> V_10 ;
const char * V_119 ;
static struct V_92 V_93 [] = {
{ 0 , 6 , L_19 } ,
{ 1 , 50 , L_20 } ,
{ 0 , 60000 , L_21 } ,
} ;
V_67 = F_57 ( V_93 , V_88 , & V_100 , & V_10 -> error ) ;
if ( V_67 )
return - V_94 ;
if ( ! V_100 )
return 0 ;
do {
V_119 = F_56 ( V_88 ) ;
V_100 -- ;
if ( ! strcasecmp ( V_119 , L_22 ) ) {
V_67 = V_60 ( V_19 , 1 , 0 ) ;
continue;
}
if ( ! strcasecmp ( V_119 , L_23 ) ) {
V_19 -> V_102 = 1 ;
continue;
}
if ( ! strcasecmp ( V_119 , L_24 ) &&
( V_100 >= 1 ) ) {
V_67 = F_69 ( V_93 + 1 , V_88 , & V_19 -> V_120 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
if ( ! strcasecmp ( V_119 , L_25 ) &&
( V_100 >= 1 ) ) {
V_67 = F_69 ( V_93 + 2 , V_88 , & V_19 -> V_24 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
V_10 -> error = L_26 ;
V_67 = - V_94 ;
} while ( V_100 && ! V_67 );
return V_67 ;
}
static int F_75 ( struct V_9 * V_10 , unsigned int V_100 ,
char * * V_96 )
{
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_27 } ,
{ 0 , 1024 , L_28 } ,
} ;
int V_67 ;
struct V_18 * V_19 ;
struct V_87 V_88 ;
unsigned V_121 = 0 ;
unsigned V_122 ;
V_88 . V_100 = V_100 ;
V_88 . V_96 = V_96 ;
V_19 = F_14 ( V_10 ) ;
if ( ! V_19 ) {
V_10 -> error = L_29 ;
return - V_94 ;
}
V_67 = F_74 ( & V_88 , V_19 ) ;
if ( V_67 )
goto V_101;
V_67 = F_72 ( & V_88 , V_19 ) ;
if ( V_67 )
goto V_101;
V_67 = F_69 ( V_93 , & V_88 , & V_19 -> V_123 , & V_10 -> error ) ;
if ( V_67 )
goto V_101;
V_67 = F_69 ( V_93 + 1 , & V_88 , & V_122 , & V_10 -> error ) ;
if ( V_67 )
goto V_101;
if ( ( ! V_19 -> V_123 && V_122 ) ||
( V_19 -> V_123 && ! V_122 ) ) {
V_10 -> error = L_30 ;
V_67 = - V_94 ;
goto V_101;
}
while ( V_88 . V_100 ) {
struct V_5 * V_6 ;
V_6 = F_68 ( & V_88 , V_19 ) ;
if ( F_44 ( V_6 ) ) {
V_67 = F_70 ( V_6 ) ;
goto V_101;
}
V_19 -> V_57 += V_6 -> V_112 ;
F_71 ( & V_6 -> V_12 , & V_19 -> V_21 ) ;
V_121 ++ ;
V_6 -> V_124 = V_121 ;
if ( ! -- V_122 )
V_19 -> V_59 = V_6 ;
}
if ( V_121 != V_19 -> V_123 ) {
V_10 -> error = L_31 ;
V_67 = - V_94 ;
goto V_101;
}
V_10 -> V_125 = 1 ;
V_10 -> V_126 = 1 ;
V_10 -> V_127 = 1 ;
return 0 ;
V_101:
F_21 ( V_19 ) ;
return V_67 ;
}
static void F_76 ( struct V_18 * V_19 )
{
F_77 ( V_128 , V_129 ) ;
unsigned long V_83 ;
F_78 ( & V_19 -> V_27 , & V_128 ) ;
while ( 1 ) {
F_79 ( V_130 ) ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( ! V_19 -> V_42 ) {
F_50 ( & V_19 -> V_22 , V_83 ) ;
break;
}
F_50 ( & V_19 -> V_22 , V_83 ) ;
F_80 () ;
}
F_79 ( V_131 ) ;
F_81 ( & V_19 -> V_27 , & V_128 ) ;
}
static void F_82 ( struct V_18 * V_19 )
{
unsigned long V_83 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
V_19 -> V_43 = 1 ;
F_50 ( & V_19 -> V_22 , V_83 ) ;
F_83 ( V_49 ) ;
F_76 ( V_19 ) ;
F_83 ( V_132 ) ;
F_84 ( & V_19 -> V_26 ) ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
V_19 -> V_43 = 0 ;
F_50 ( & V_19 -> V_22 , V_83 ) ;
}
static void F_85 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_31 ;
F_82 ( V_19 ) ;
F_21 ( V_19 ) ;
}
static int F_86 ( struct V_1 * V_1 )
{
unsigned long V_83 ;
struct V_18 * V_19 = V_1 -> V_6 -> V_19 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( ! V_1 -> V_3 )
goto V_133;
F_87 ( L_32 , V_1 -> V_13 . V_14 -> V_134 ) ;
V_1 -> V_6 -> V_16 . type -> F_86 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
V_1 -> V_3 = 0 ;
V_1 -> V_135 ++ ;
V_19 -> V_57 -- ;
if ( V_1 == V_19 -> V_55 )
V_19 -> V_55 = NULL ;
F_88 ( V_136 , V_19 -> V_10 ,
V_1 -> V_13 . V_14 -> V_134 , V_19 -> V_57 ) ;
F_89 ( & V_19 -> V_26 ) ;
V_133:
F_50 ( & V_19 -> V_22 , V_83 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_1 )
{
int V_67 = 0 , V_137 = 0 ;
unsigned long V_83 ;
struct V_18 * V_19 = V_1 -> V_6 -> V_19 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( V_1 -> V_3 )
goto V_133;
if ( ! V_1 -> V_6 -> V_16 . type -> F_90 ) {
F_87 ( L_33 ,
V_1 -> V_6 -> V_16 . type -> V_134 ) ;
V_67 = - V_94 ;
goto V_133;
}
V_67 = V_1 -> V_6 -> V_16 . type -> F_90 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
if ( V_67 )
goto V_133;
V_1 -> V_3 = 1 ;
if ( ! V_19 -> V_57 ++ ) {
V_19 -> V_55 = NULL ;
V_137 = 1 ;
} else if ( V_19 -> V_32 && ( V_19 -> V_46 == V_1 -> V_6 ) ) {
if ( F_91 ( V_49 , & V_1 -> V_4 . V_86 ) )
V_19 -> V_42 ++ ;
}
F_88 ( V_138 , V_19 -> V_10 ,
V_1 -> V_13 . V_14 -> V_134 , V_19 -> V_57 ) ;
F_89 ( & V_19 -> V_26 ) ;
V_133:
F_50 ( & V_19 -> V_22 , V_83 ) ;
if ( V_137 )
F_51 ( V_19 -> V_10 -> V_84 ) ;
return V_67 ;
}
static int F_92 ( struct V_18 * V_19 , struct V_139 * V_14 ,
T_2 V_140 )
{
int V_67 = - V_94 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_29 (pg, &m->priority_groups, list) {
F_29 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_13 . V_14 == V_14 )
V_67 = V_140 ( V_1 ) ;
}
}
return V_67 ;
}
static void F_93 ( struct V_18 * V_19 , struct V_5 * V_6 ,
int V_56 )
{
unsigned long V_83 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
V_6 -> V_56 = V_56 ;
V_19 -> V_55 = NULL ;
V_19 -> V_46 = NULL ;
F_50 ( & V_19 -> V_22 , V_83 ) ;
F_89 ( & V_19 -> V_26 ) ;
}
static int F_94 ( struct V_18 * V_19 , const char * V_141 )
{
struct V_5 * V_6 ;
unsigned V_142 ;
unsigned long V_83 ;
char V_143 ;
if ( ! V_141 || ( sscanf ( V_141 , L_34 , & V_142 , & V_143 ) != 1 ) || ! V_142 ||
( V_142 > V_19 -> V_123 ) ) {
F_87 ( L_35 ) ;
return - V_94 ;
}
F_49 ( & V_19 -> V_22 , V_83 ) ;
F_29 (pg, &m->priority_groups, list) {
V_6 -> V_56 = 0 ;
if ( -- V_142 )
continue;
V_19 -> V_55 = NULL ;
V_19 -> V_46 = NULL ;
V_19 -> V_59 = V_6 ;
}
F_50 ( & V_19 -> V_22 , V_83 ) ;
F_89 ( & V_19 -> V_26 ) ;
return 0 ;
}
static int F_95 ( struct V_18 * V_19 , const char * V_141 , int V_56 )
{
struct V_5 * V_6 ;
unsigned V_142 ;
char V_143 ;
if ( ! V_141 || ( sscanf ( V_141 , L_34 , & V_142 , & V_143 ) != 1 ) || ! V_142 ||
( V_142 > V_19 -> V_123 ) ) {
F_87 ( L_36 ) ;
return - V_94 ;
}
F_29 (pg, &m->priority_groups, list) {
if ( ! -- V_142 )
break;
}
F_93 ( V_19 , V_6 , V_56 ) ;
return 0 ;
}
static int F_96 ( struct V_18 * V_19 , struct V_1 * V_1 )
{
unsigned long V_83 ;
int V_144 = 0 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( V_19 -> V_44 <= V_19 -> V_120 && ! V_19 -> V_43 )
V_19 -> V_45 = 1 ;
else
V_144 = 1 ;
F_50 ( & V_19 -> V_22 , V_83 ) ;
return V_144 ;
}
static void F_97 ( void * V_145 , int V_146 )
{
struct V_1 * V_1 = V_145 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_18 * V_19 = V_6 -> V_19 ;
unsigned long V_83 ;
unsigned V_147 = 0 ;
switch ( V_146 ) {
case V_148 :
break;
case V_149 :
if ( ! V_19 -> V_32 ) {
V_146 = 0 ;
break;
}
F_98 ( L_37
L_38 , V_19 -> V_32 , V_146 ) ;
F_86 ( V_1 ) ;
break;
case V_150 :
F_93 ( V_19 , V_6 , 1 ) ;
break;
case V_151 :
V_147 = 1 ;
case V_152 :
case V_153 :
if ( F_96 ( V_19 , V_1 ) )
F_86 ( V_1 ) ;
V_146 = 0 ;
break;
default:
F_86 ( V_1 ) ;
}
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( V_146 ) {
if ( V_1 == V_19 -> V_55 ) {
F_98 ( L_39 , V_146 ) ;
V_19 -> V_55 = NULL ;
V_19 -> V_46 = NULL ;
}
} else if ( ! V_19 -> V_45 )
V_6 -> V_56 = 0 ;
if ( -- V_19 -> V_42 )
goto V_133;
if ( V_19 -> V_45 ) {
V_19 -> V_47 = V_147 ;
if ( F_27 ( V_19 ) )
goto V_133;
}
V_19 -> V_23 = 0 ;
F_99 ( & V_19 -> V_27 ) ;
V_133:
F_50 ( & V_19 -> V_22 , V_83 ) ;
}
static void V_4 ( struct V_85 * V_86 )
{
struct V_1 * V_1 =
F_52 ( V_86 , struct V_1 , V_4 . V_86 ) ;
if ( V_1 -> V_3 )
F_100 ( F_41 ( V_1 -> V_13 . V_14 -> V_70 ) ,
F_97 , V_1 ) ;
else
F_97 ( V_1 , V_154 ) ;
}
static int F_101 ( int error )
{
switch ( error ) {
case - V_155 :
case - V_156 :
case - V_157 :
case - V_158 :
case - V_159 :
return 1 ;
}
return 0 ;
}
static int F_102 ( struct V_18 * V_19 , struct V_62 * V_63 ,
int error , struct V_36 * V_37 )
{
int V_67 = V_160 ;
unsigned long V_83 ;
if ( ! error && ! V_63 -> V_146 )
return 0 ;
if ( F_101 ( error ) )
return error ;
if ( V_37 -> V_1 )
F_86 ( V_37 -> V_1 ) ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( ! V_19 -> V_57 ) {
if ( ! V_19 -> V_60 ) {
if ( ! F_35 ( V_19 ) )
V_67 = - V_71 ;
} else {
if ( error == - V_161 )
V_67 = error ;
}
}
F_50 ( & V_19 -> V_22 , V_83 ) ;
return V_67 ;
}
static int F_103 ( struct V_9 * V_10 , struct V_62 * V_63 ,
int error , union V_34 * V_64 )
{
struct V_18 * V_19 = V_10 -> V_31 ;
struct V_36 * V_37 = V_64 -> V_40 ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_67 ;
F_104 ( ! V_37 ) ;
V_67 = F_102 ( V_19 , V_63 , error , V_37 ) ;
V_1 = V_37 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_162 )
V_16 -> type -> V_162 ( V_16 , & V_1 -> V_13 , V_37 -> V_50 ) ;
}
F_25 ( V_19 , V_64 ) ;
return V_67 ;
}
static void F_105 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = (struct V_18 * ) V_10 -> V_31 ;
V_60 ( V_19 , 0 , 1 ) ;
}
static void F_106 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = V_10 -> V_31 ;
F_107 ( & V_19 -> V_28 ) ;
F_82 ( V_19 ) ;
F_108 ( & V_19 -> V_28 ) ;
}
static void F_109 ( struct V_9 * V_10 )
{
struct V_18 * V_19 = (struct V_18 * ) V_10 -> V_31 ;
unsigned long V_83 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
V_19 -> V_60 = V_19 -> V_61 ;
F_50 ( & V_19 -> V_22 , V_83 ) ;
}
static void F_110 ( struct V_9 * V_10 , T_3 type ,
unsigned V_163 , char * V_164 , unsigned V_165 )
{
int V_166 = 0 ;
unsigned long V_83 ;
struct V_18 * V_19 = (struct V_18 * ) V_10 -> V_31 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
unsigned V_124 ;
char V_167 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( type == V_168 )
F_111 ( L_40 , V_19 -> V_23 , V_19 -> V_44 ) ;
else {
F_111 ( L_41 , V_19 -> V_60 +
( V_19 -> V_120 > 0 ) * 2 +
( V_19 -> V_24 != V_25 ) * 2 +
V_19 -> V_102 ) ;
if ( V_19 -> V_60 )
F_111 ( L_42 ) ;
if ( V_19 -> V_120 )
F_111 ( L_43 , V_19 -> V_120 ) ;
if ( V_19 -> V_24 != V_25 )
F_111 ( L_44 , V_19 -> V_24 ) ;
if ( V_19 -> V_102 )
F_111 ( L_45 ) ;
}
if ( ! V_19 -> V_32 || type == V_168 )
F_111 ( L_46 ) ;
else
F_111 ( L_47 , V_19 -> V_32 ) ;
F_111 ( L_41 , V_19 -> V_123 ) ;
if ( V_19 -> V_59 )
V_124 = V_19 -> V_59 -> V_124 ;
else if ( V_19 -> V_46 )
V_124 = V_19 -> V_46 -> V_124 ;
else
V_124 = ( V_19 -> V_123 ? 1 : 0 ) ;
F_111 ( L_41 , V_124 ) ;
switch ( type ) {
case V_168 :
F_29 (pg, &m->priority_groups, list) {
if ( V_6 -> V_56 )
V_167 = 'D' ;
else if ( V_6 == V_19 -> V_46 )
V_167 = 'A' ;
else
V_167 = 'E' ;
F_111 ( L_48 , V_167 ) ;
if ( V_6 -> V_16 . type -> V_169 )
V_166 += V_6 -> V_16 . type -> V_169 ( & V_6 -> V_16 , NULL , type ,
V_164 + V_166 ,
V_165 - V_166 ) ;
else
F_111 ( L_46 ) ;
F_111 ( L_49 , V_6 -> V_112 ,
V_6 -> V_16 . type -> V_170 ) ;
F_29 (p, &pg->pgpaths, list) {
F_111 ( L_50 , V_97 -> V_13 . V_14 -> V_134 ,
V_97 -> V_3 ? L_51 : L_52 ,
V_97 -> V_135 ) ;
if ( V_6 -> V_16 . type -> V_169 )
V_166 += V_6 -> V_16 . type -> V_169 ( & V_6 -> V_16 ,
& V_97 -> V_13 , type , V_164 + V_166 ,
V_165 - V_166 ) ;
}
}
break;
case V_171 :
F_29 (pg, &m->priority_groups, list) {
F_111 ( L_53 , V_6 -> V_16 . type -> V_134 ) ;
if ( V_6 -> V_16 . type -> V_169 )
V_166 += V_6 -> V_16 . type -> V_169 ( & V_6 -> V_16 , NULL , type ,
V_164 + V_166 ,
V_165 - V_166 ) ;
else
F_111 ( L_46 ) ;
F_111 ( L_49 , V_6 -> V_112 ,
V_6 -> V_16 . type -> V_172 ) ;
F_29 (p, &pg->pgpaths, list) {
F_111 ( L_53 , V_97 -> V_13 . V_14 -> V_134 ) ;
if ( V_6 -> V_16 . type -> V_169 )
V_166 += V_6 -> V_16 . type -> V_169 ( & V_6 -> V_16 ,
& V_97 -> V_13 , type , V_164 + V_166 ,
V_165 - V_166 ) ;
}
}
break;
}
F_50 ( & V_19 -> V_22 , V_83 ) ;
}
static int F_112 ( struct V_9 * V_10 , unsigned V_100 , char * * V_96 )
{
int V_67 = - V_94 ;
struct V_139 * V_14 ;
struct V_18 * V_19 = (struct V_18 * ) V_10 -> V_31 ;
T_2 V_140 ;
F_107 ( & V_19 -> V_28 ) ;
if ( F_113 ( V_10 ) ) {
V_67 = - V_104 ;
goto V_133;
}
if ( V_100 == 1 ) {
if ( ! strcasecmp ( V_96 [ 0 ] , L_22 ) ) {
V_67 = V_60 ( V_19 , 1 , 0 ) ;
goto V_133;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_54 ) ) {
V_67 = V_60 ( V_19 , 0 , 0 ) ;
goto V_133;
}
}
if ( V_100 != 2 ) {
F_87 ( L_55 , V_100 ) ;
goto V_133;
}
if ( ! strcasecmp ( V_96 [ 0 ] , L_56 ) ) {
V_67 = F_95 ( V_19 , V_96 [ 1 ] , 1 ) ;
goto V_133;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_57 ) ) {
V_67 = F_95 ( V_19 , V_96 [ 1 ] , 0 ) ;
goto V_133;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_58 ) ) {
V_67 = F_94 ( V_19 , V_96 [ 1 ] ) ;
goto V_133;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_59 ) )
V_140 = F_90 ;
else if ( ! strcasecmp ( V_96 [ 0 ] , L_60 ) )
V_140 = F_86 ;
else {
F_87 ( L_61 , V_96 [ 0 ] ) ;
goto V_133;
}
V_67 = F_61 ( V_10 , V_96 [ 1 ] , F_62 ( V_10 -> V_84 ) , & V_14 ) ;
if ( V_67 ) {
F_87 ( L_62 ,
V_96 [ 1 ] ) ;
goto V_133;
}
V_67 = F_92 ( V_19 , V_14 , V_140 ) ;
F_11 ( V_10 , V_14 ) ;
V_133:
F_108 ( & V_19 -> V_28 ) ;
return V_67 ;
}
static int F_114 ( struct V_9 * V_10 ,
struct V_69 * * V_70 , T_4 * V_173 )
{
struct V_18 * V_19 = V_10 -> V_31 ;
unsigned long V_83 ;
int V_67 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( ! V_19 -> V_55 )
F_34 ( V_19 , 0 ) ;
if ( V_19 -> V_55 ) {
if ( ! V_19 -> V_23 ) {
* V_70 = V_19 -> V_55 -> V_13 . V_14 -> V_70 ;
* V_173 = V_19 -> V_55 -> V_13 . V_14 -> V_173 ;
V_67 = 0 ;
} else {
V_67 = - V_174 ;
}
} else {
if ( V_19 -> V_60 )
V_67 = - V_174 ;
else
V_67 = - V_71 ;
}
F_50 ( & V_19 -> V_22 , V_83 ) ;
if ( V_67 == - V_174 ) {
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( ! V_19 -> V_46 ) {
F_34 ( V_19 , 0 ) ;
}
if ( V_19 -> V_45 )
F_27 ( V_19 ) ;
F_50 ( & V_19 -> V_22 , V_83 ) ;
F_51 ( V_19 -> V_10 -> V_84 ) ;
}
if ( ! V_67 && V_10 -> V_117 != F_115 ( ( * V_70 ) -> V_175 ) >> V_176 )
return 1 ;
return V_67 ;
}
static int F_116 ( struct V_9 * V_10 ,
T_5 V_177 , void * V_145 )
{
struct V_18 * V_19 = V_10 -> V_31 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
int V_115 = 0 ;
F_29 (pg, &m->priority_groups, list) {
F_29 (p, &pg->pgpaths, list) {
V_115 = V_177 ( V_10 , V_97 -> V_13 . V_14 , V_10 -> V_178 , V_10 -> V_117 , V_145 ) ;
if ( V_115 )
goto V_133;
}
}
V_133:
return V_115 ;
}
static int F_117 ( struct V_1 * V_1 )
{
struct V_98 * V_73 = F_41 ( V_1 -> V_13 . V_14 -> V_70 ) ;
return F_118 ( V_73 ) ;
}
static int F_119 ( struct V_9 * V_10 )
{
int V_179 = 0 , V_180 = 0 ;
struct V_18 * V_19 = V_10 -> V_31 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_83 ;
F_49 ( & V_19 -> V_22 , V_83 ) ;
if ( V_19 -> V_42 ||
( ! V_19 -> V_57 && V_19 -> V_60 ) ) {
V_179 = 1 ;
goto V_133;
}
if ( F_120 ( ! V_19 -> V_55 && V_19 -> V_59 ) )
V_6 = V_19 -> V_59 ;
else if ( F_121 ( V_19 -> V_46 ) )
V_6 = V_19 -> V_46 ;
else
goto V_133;
V_179 = 1 ;
F_29 (pgpath, &pg->pgpaths, list)
if ( V_1 -> V_3 ) {
V_180 = 1 ;
if ( ! F_117 ( V_1 ) ) {
V_179 = 0 ;
break;
}
}
if ( ! V_180 )
V_179 = 0 ;
V_133:
F_50 ( & V_19 -> V_22 , V_83 ) ;
return V_179 ;
}
static int T_6 F_122 ( void )
{
int V_67 ;
V_30 = F_123 ( V_36 , 0 ) ;
if ( ! V_30 )
return - V_39 ;
V_67 = F_124 ( & V_181 ) ;
if ( V_67 < 0 ) {
F_98 ( L_63 , V_67 ) ;
V_67 = - V_94 ;
goto V_182;
}
V_132 = F_125 ( L_64 , V_183 , 0 ) ;
if ( ! V_132 ) {
F_98 ( L_65 ) ;
V_67 = - V_39 ;
goto V_184;
}
V_49 = F_126 ( L_66 ,
V_183 ) ;
if ( ! V_49 ) {
F_98 ( L_67 ) ;
V_67 = - V_39 ;
goto V_185;
}
F_127 ( L_68 ,
V_181 . V_186 [ 0 ] , V_181 . V_186 [ 1 ] ,
V_181 . V_186 [ 2 ] ) ;
return 0 ;
V_185:
F_128 ( V_132 ) ;
V_184:
F_129 ( & V_181 ) ;
V_182:
F_130 ( V_30 ) ;
return V_67 ;
}
static void T_7 F_131 ( void )
{
F_128 ( V_49 ) ;
F_128 ( V_132 ) ;
F_129 ( & V_181 ) ;
F_130 ( V_30 ) ;
}
