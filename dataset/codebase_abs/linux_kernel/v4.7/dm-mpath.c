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
static struct V_18 * F_14 ( struct V_9 * V_10 , bool V_19 )
{
struct V_18 * V_20 ;
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
V_20 -> V_33 = NULL ;
if ( ! V_19 ) {
unsigned V_34 = F_21 () ;
V_20 -> V_33 = F_22 ( V_34 , V_35 ) ;
if ( ! V_20 -> V_33 ) {
F_5 ( V_20 ) ;
return NULL ;
}
}
V_20 -> V_10 = V_10 ;
V_10 -> V_36 = V_20 ;
}
return V_20 ;
}
static void F_23 ( struct V_18 * V_20 )
{
struct V_5 * V_6 , * V_11 ;
F_9 (pg, tmp, &m->priority_groups, list) {
F_10 ( & V_6 -> V_12 ) ;
F_12 ( V_6 , V_20 -> V_10 ) ;
}
F_5 ( V_20 -> V_37 ) ;
F_5 ( V_20 -> V_38 ) ;
F_24 ( V_20 -> V_33 ) ;
F_5 ( V_20 ) ;
}
static struct V_39 * F_25 ( union V_40 * V_41 )
{
return V_41 -> V_42 ;
}
static struct V_39 * F_26 ( struct V_18 * V_20 , union V_40 * V_41 )
{
struct V_39 * V_43 ;
if ( ! V_20 -> V_33 ) {
V_43 = F_25 ( V_41 ) ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
return V_43 ;
}
V_43 = F_27 ( V_20 -> V_33 , V_44 ) ;
if ( ! V_43 )
return NULL ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_41 -> V_42 = V_43 ;
return V_43 ;
}
static void F_28 ( struct V_18 * V_20 , union V_40 * V_41 )
{
if ( V_20 -> V_33 ) {
struct V_39 * V_43 = V_41 -> V_42 ;
V_41 -> V_42 = NULL ;
F_29 ( V_43 , V_20 -> V_33 ) ;
}
}
static int F_30 ( struct V_18 * V_20 )
{
struct V_1 * V_1 ;
unsigned long V_45 = 0 ;
if ( F_31 ( & V_20 -> V_26 ) || F_32 ( V_46 , & V_20 -> V_24 ) )
return 0 ;
F_33 ( & V_20 -> V_27 ) ;
F_34 ( V_47 , & V_20 -> V_24 ) ;
if ( ! V_20 -> V_48 )
return 0 ;
if ( F_32 ( V_49 , & V_20 -> V_24 ) )
V_45 = F_35 ( V_20 -> V_28 != V_29 ?
V_20 -> V_28 : V_50 ) ;
F_36 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_37 ( V_51 , & V_1 -> V_4 ,
V_45 ) )
F_33 ( & V_20 -> V_26 ) ;
}
return F_31 ( & V_20 -> V_26 ) ;
}
static int F_38 ( struct V_18 * V_20 )
{
int V_52 ;
unsigned long V_24 ;
F_39 ( & V_20 -> V_22 , V_24 ) ;
V_52 = F_30 ( V_20 ) ;
F_40 ( & V_20 -> V_22 , V_24 ) ;
return V_52 ;
}
static void F_41 ( struct V_18 * V_20 , struct V_5 * V_6 )
{
V_20 -> V_48 = V_6 ;
if ( V_20 -> V_37 ) {
F_16 ( V_47 , & V_20 -> V_24 ) ;
F_16 ( V_23 , & V_20 -> V_24 ) ;
} else {
F_34 ( V_47 , & V_20 -> V_24 ) ;
F_34 ( V_23 , & V_20 -> V_24 ) ;
}
F_17 ( & V_20 -> V_27 , 0 ) ;
}
static struct V_1 * F_42 ( struct V_18 * V_20 ,
struct V_5 * V_6 ,
T_1 V_53 )
{
unsigned long V_24 ;
struct V_54 * V_13 ;
struct V_1 * V_1 ;
V_13 = V_6 -> V_16 . type -> V_55 ( & V_6 -> V_16 , V_53 ) ;
if ( ! V_13 )
return F_43 ( - V_56 ) ;
V_1 = F_44 ( V_13 ) ;
if ( F_45 ( F_46 ( V_20 -> V_48 ) != V_6 ) ) {
F_39 ( & V_20 -> V_22 , V_24 ) ;
V_20 -> V_57 = V_1 ;
F_41 ( V_20 , V_6 ) ;
F_40 ( & V_20 -> V_22 , V_24 ) ;
}
return V_1 ;
}
static struct V_1 * F_47 ( struct V_18 * V_20 , T_1 V_53 )
{
unsigned long V_24 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
bool V_58 = true ;
if ( ! F_31 ( & V_20 -> V_25 ) ) {
F_34 ( V_23 , & V_20 -> V_24 ) ;
goto V_59;
}
if ( F_46 ( V_20 -> V_60 ) ) {
F_39 ( & V_20 -> V_22 , V_24 ) ;
V_6 = V_20 -> V_60 ;
if ( ! V_6 ) {
F_40 ( & V_20 -> V_22 , V_24 ) ;
goto V_61;
}
V_20 -> V_60 = NULL ;
F_40 ( & V_20 -> V_22 , V_24 ) ;
V_1 = F_42 ( V_20 , V_6 , V_53 ) ;
if ( ! F_48 ( V_1 ) )
return V_1 ;
}
V_61:
V_6 = F_46 ( V_20 -> V_48 ) ;
if ( V_6 ) {
V_1 = F_42 ( V_20 , V_6 , V_53 ) ;
if ( ! F_48 ( V_1 ) )
return V_1 ;
}
do {
F_36 (pg, &m->priority_groups, list) {
if ( V_6 -> V_58 == V_58 )
continue;
V_1 = F_42 ( V_20 , V_6 , V_53 ) ;
if ( ! F_48 ( V_1 ) ) {
if ( ! V_58 )
F_16 ( V_49 , & V_20 -> V_24 ) ;
return V_1 ;
}
}
} while ( V_58 -- );
V_59:
F_39 ( & V_20 -> V_22 , V_24 ) ;
V_20 -> V_57 = NULL ;
V_20 -> V_48 = NULL ;
F_40 ( & V_20 -> V_22 , V_24 ) ;
return NULL ;
}
static int F_49 ( struct V_18 * V_20 )
{
return ( F_32 ( V_62 , & V_20 -> V_24 ) ||
( ( F_32 ( V_62 , & V_20 -> V_24 ) !=
F_32 ( V_63 , & V_20 -> V_24 ) ) &&
F_50 ( V_20 -> V_10 ) ) ) ;
}
static int F_51 ( struct V_9 * V_10 , struct V_64 * V_65 ,
union V_40 * V_66 ,
struct V_64 * V_67 , struct V_64 * * V_68 )
{
struct V_18 * V_20 = V_10 -> V_36 ;
int V_52 = V_69 ;
T_1 V_53 = V_65 ? F_52 ( V_65 ) : F_52 ( V_67 ) ;
struct V_1 * V_1 ;
struct V_70 * V_71 ;
struct V_39 * V_43 ;
V_1 = F_46 ( V_20 -> V_57 ) ;
if ( ! V_1 || ! F_32 ( V_23 , & V_20 -> V_24 ) )
V_1 = F_47 ( V_20 , V_53 ) ;
if ( ! V_1 ) {
if ( ! F_49 ( V_20 ) )
V_52 = - V_72 ;
return V_52 ;
} else if ( F_32 ( V_23 , & V_20 -> V_24 ) ||
F_32 ( V_47 , & V_20 -> V_24 ) ) {
F_38 ( V_20 ) ;
return V_52 ;
}
V_43 = F_26 ( V_20 , V_66 ) ;
if ( ! V_43 )
return V_52 ;
V_43 -> V_1 = V_1 ;
V_43 -> V_53 = V_53 ;
V_71 = V_1 -> V_13 . V_14 -> V_71 ;
if ( V_65 ) {
V_65 -> V_73 = F_53 ( V_71 ) ;
V_65 -> V_74 = V_71 -> V_75 ;
V_65 -> V_76 |= V_77 ;
} else {
* V_68 = F_54 ( F_53 ( V_71 ) ,
F_55 ( V_67 ) , V_78 ) ;
if ( F_56 ( * V_68 ) ) {
F_28 ( V_20 , V_66 ) ;
return V_52 ;
}
( * V_68 ) -> V_79 = ( * V_68 ) -> V_80 = NULL ;
( * V_68 ) -> V_74 = V_71 -> V_75 ;
( * V_68 ) -> V_76 |= V_77 ;
}
if ( V_1 -> V_6 -> V_16 . type -> V_81 )
V_1 -> V_6 -> V_16 . type -> V_81 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_53 ) ;
return V_82 ;
}
static int F_57 ( struct V_9 * V_10 , struct V_64 * V_65 ,
union V_40 * V_66 )
{
return F_51 ( V_10 , V_65 , V_66 , NULL , NULL ) ;
}
static int F_58 ( struct V_9 * V_10 , struct V_64 * V_67 ,
union V_40 * V_66 ,
struct V_64 * * V_65 )
{
return F_51 ( V_10 , NULL , V_66 , V_67 , V_65 ) ;
}
static void F_59 ( struct V_64 * V_65 )
{
F_60 ( V_65 ) ;
}
static int F_61 ( struct V_18 * V_20 , bool F_61 ,
bool V_83 )
{
unsigned long V_24 ;
F_39 ( & V_20 -> V_22 , V_24 ) ;
if ( V_83 ) {
if ( F_32 ( V_62 , & V_20 -> V_24 ) )
F_16 ( V_63 , & V_20 -> V_24 ) ;
else
F_34 ( V_63 , & V_20 -> V_24 ) ;
} else {
if ( F_61 )
F_16 ( V_63 , & V_20 -> V_24 ) ;
else
F_34 ( V_63 , & V_20 -> V_24 ) ;
}
if ( F_61 )
F_16 ( V_62 , & V_20 -> V_24 ) ;
else
F_34 ( V_62 , & V_20 -> V_24 ) ;
F_40 ( & V_20 -> V_22 , V_24 ) ;
if ( ! F_61 )
F_62 ( V_20 -> V_10 -> V_84 ) ;
return 0 ;
}
static void V_30 ( struct V_85 * V_86 )
{
struct V_18 * V_20 =
F_63 ( V_86 , struct V_18 , V_30 ) ;
F_64 ( V_20 -> V_10 -> V_84 ) ;
}
static int F_65 ( struct V_87 * V_88 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_52 ;
struct V_89 * V_90 ;
unsigned V_91 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_1 } ,
} ;
V_90 = F_66 ( F_67 ( V_88 ) ) ;
if ( ! V_90 ) {
V_10 -> error = L_2 ;
return - V_94 ;
}
V_52 = F_68 ( V_93 , V_88 , & V_91 , & V_10 -> error ) ;
if ( V_52 ) {
F_13 ( V_90 ) ;
return - V_94 ;
}
V_52 = V_90 -> V_95 ( & V_6 -> V_16 , V_91 , V_88 -> V_96 ) ;
if ( V_52 ) {
F_13 ( V_90 ) ;
V_10 -> error = L_3 ;
return V_52 ;
}
V_6 -> V_16 . type = V_90 ;
F_69 ( V_88 , V_91 ) ;
return 0 ;
}
static struct V_1 * F_70 ( struct V_87 * V_88 , struct V_15 * V_16 ,
struct V_9 * V_10 )
{
int V_52 ;
struct V_1 * V_97 ;
struct V_18 * V_20 = V_10 -> V_36 ;
struct V_98 * V_73 = NULL ;
const char * V_99 ;
if ( V_88 -> V_100 < 1 ) {
V_10 -> error = L_4 ;
return F_43 ( - V_94 ) ;
}
V_97 = F_1 () ;
if ( ! V_97 )
return F_43 ( - V_101 ) ;
V_52 = F_71 ( V_10 , F_67 ( V_88 ) , F_72 ( V_10 -> V_84 ) ,
& V_97 -> V_13 . V_14 ) ;
if ( V_52 ) {
V_10 -> error = L_5 ;
goto V_102;
}
if ( F_32 ( V_103 , & V_20 -> V_24 ) || V_20 -> V_37 )
V_73 = F_53 ( V_97 -> V_13 . V_14 -> V_71 ) ;
if ( F_32 ( V_103 , & V_20 -> V_24 ) ) {
V_104:
V_99 = F_73 ( V_73 , V_2 ) ;
if ( V_99 ) {
F_5 ( V_20 -> V_37 ) ;
V_20 -> V_37 = V_99 ;
F_5 ( V_20 -> V_38 ) ;
V_20 -> V_38 = NULL ;
}
}
if ( V_20 -> V_37 ) {
V_52 = F_74 ( V_73 , V_20 -> V_37 ) ;
if ( V_52 == - V_105 ) {
char V_106 [ V_107 ] ;
F_75 ( V_108 L_6 ,
F_76 ( V_97 -> V_13 . V_14 -> V_71 , V_106 ) ) ;
goto V_104;
}
if ( V_52 < 0 ) {
V_10 -> error = L_7 ;
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_102;
}
if ( V_20 -> V_38 ) {
V_52 = F_77 ( V_73 , V_20 -> V_38 ) ;
if ( V_52 < 0 ) {
V_10 -> error = L_8
L_9 ;
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_102;
}
}
}
V_52 = V_16 -> type -> V_109 ( V_16 , & V_97 -> V_13 , V_88 -> V_100 , V_88 -> V_96 , & V_10 -> error ) ;
if ( V_52 ) {
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_102;
}
return V_97 ;
V_102:
F_4 ( V_97 ) ;
return F_43 ( V_52 ) ;
}
static struct V_5 * F_78 ( struct V_87 * V_88 ,
struct V_18 * V_20 )
{
static struct V_92 V_93 [] = {
{ 1 , 1024 , L_10 } ,
{ 0 , 1024 , L_11 }
} ;
int V_52 ;
unsigned V_110 , V_111 , V_112 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_88 -> V_100 < 2 ) {
V_88 -> V_100 = 0 ;
V_10 -> error = L_12 ;
return F_43 ( - V_94 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_13 ;
return F_43 ( - V_101 ) ;
}
V_6 -> V_20 = V_20 ;
V_52 = F_65 ( V_88 , V_6 , V_10 ) ;
if ( V_52 )
goto V_102;
V_52 = F_79 ( V_93 , V_88 , & V_6 -> V_113 , & V_10 -> error ) ;
if ( V_52 )
goto V_102;
V_52 = F_79 ( V_93 + 1 , V_88 , & V_111 , & V_10 -> error ) ;
if ( V_52 )
goto V_102;
V_112 = 1 + V_111 ;
for ( V_110 = 0 ; V_110 < V_6 -> V_113 ; V_110 ++ ) {
struct V_1 * V_1 ;
struct V_87 V_114 ;
if ( V_88 -> V_100 < V_112 ) {
V_10 -> error = L_14 ;
V_52 = - V_94 ;
goto V_102;
}
V_114 . V_100 = V_112 ;
V_114 . V_96 = V_88 -> V_96 ;
V_1 = F_70 ( & V_114 , & V_6 -> V_16 , V_10 ) ;
if ( F_56 ( V_1 ) ) {
V_52 = F_80 ( V_1 ) ;
goto V_102;
}
V_1 -> V_6 = V_6 ;
F_81 ( & V_1 -> V_12 , & V_6 -> V_7 ) ;
F_69 ( V_88 , V_112 ) ;
}
return V_6 ;
V_102:
F_12 ( V_6 , V_10 ) ;
return F_43 ( V_52 ) ;
}
static int F_82 ( struct V_87 * V_88 , struct V_18 * V_20 )
{
unsigned V_115 ;
int V_116 ;
struct V_9 * V_10 = V_20 -> V_10 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_15 } ,
} ;
if ( F_68 ( V_93 , V_88 , & V_115 , & V_10 -> error ) )
return - V_94 ;
if ( ! V_115 )
return 0 ;
V_20 -> V_37 = F_83 ( F_67 ( V_88 ) , V_2 ) ;
if ( V_115 > 1 ) {
char * V_97 ;
int V_110 , V_117 , V_118 = 4 ;
for ( V_110 = 0 ; V_110 <= V_115 - 2 ; V_110 ++ )
V_118 += strlen ( V_88 -> V_96 [ V_110 ] ) + 1 ;
V_97 = V_20 -> V_38 = F_2 ( V_118 , V_2 ) ;
if ( ! V_97 ) {
V_10 -> error = L_16 ;
V_116 = - V_101 ;
goto V_119;
}
V_117 = sprintf ( V_97 , L_17 , V_115 - 1 ) ;
for ( V_110 = 0 , V_97 += V_117 + 1 ; V_110 <= V_115 - 2 ; V_110 ++ , V_97 += V_117 + 1 )
V_117 = sprintf ( V_97 , L_18 , V_88 -> V_96 [ V_110 ] ) ;
}
F_69 ( V_88 , V_115 - 1 ) ;
return 0 ;
V_119:
F_5 ( V_20 -> V_37 ) ;
V_20 -> V_37 = NULL ;
return V_116 ;
}
static int F_84 ( struct V_87 * V_88 , struct V_18 * V_20 )
{
int V_52 ;
unsigned V_100 ;
struct V_9 * V_10 = V_20 -> V_10 ;
const char * V_120 ;
static struct V_92 V_93 [] = {
{ 0 , 6 , L_19 } ,
{ 1 , 50 , L_20 } ,
{ 0 , 60000 , L_21 } ,
} ;
V_52 = F_68 ( V_93 , V_88 , & V_100 , & V_10 -> error ) ;
if ( V_52 )
return - V_94 ;
if ( ! V_100 )
return 0 ;
do {
V_120 = F_67 ( V_88 ) ;
V_100 -- ;
if ( ! strcasecmp ( V_120 , L_22 ) ) {
V_52 = F_61 ( V_20 , true , false ) ;
continue;
}
if ( ! strcasecmp ( V_120 , L_23 ) ) {
F_16 ( V_103 , & V_20 -> V_24 ) ;
continue;
}
if ( ! strcasecmp ( V_120 , L_24 ) &&
( V_100 >= 1 ) ) {
V_52 = F_79 ( V_93 + 1 , V_88 , & V_20 -> V_121 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
if ( ! strcasecmp ( V_120 , L_25 ) &&
( V_100 >= 1 ) ) {
V_52 = F_79 ( V_93 + 2 , V_88 , & V_20 -> V_28 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
V_10 -> error = L_26 ;
V_52 = - V_94 ;
} while ( V_100 && ! V_52 );
return V_52 ;
}
static int F_85 ( struct V_9 * V_10 , unsigned int V_100 ,
char * * V_96 )
{
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_27 } ,
{ 0 , 1024 , L_28 } ,
} ;
int V_52 ;
struct V_18 * V_20 ;
struct V_87 V_88 ;
unsigned V_122 = 0 ;
unsigned V_123 ;
bool V_19 = F_86 ( F_87 ( V_10 -> V_84 ) ) ;
V_88 . V_100 = V_100 ;
V_88 . V_96 = V_96 ;
V_20 = F_14 ( V_10 , V_19 ) ;
if ( ! V_20 ) {
V_10 -> error = L_29 ;
return - V_94 ;
}
V_52 = F_84 ( & V_88 , V_20 ) ;
if ( V_52 )
goto V_102;
V_52 = F_82 ( & V_88 , V_20 ) ;
if ( V_52 )
goto V_102;
V_52 = F_79 ( V_93 , & V_88 , & V_20 -> V_124 , & V_10 -> error ) ;
if ( V_52 )
goto V_102;
V_52 = F_79 ( V_93 + 1 , & V_88 , & V_123 , & V_10 -> error ) ;
if ( V_52 )
goto V_102;
if ( ( ! V_20 -> V_124 && V_123 ) ||
( V_20 -> V_124 && ! V_123 ) ) {
V_10 -> error = L_30 ;
V_52 = - V_94 ;
goto V_102;
}
while ( V_88 . V_100 ) {
struct V_5 * V_6 ;
unsigned V_25 = F_31 ( & V_20 -> V_25 ) ;
V_6 = F_78 ( & V_88 , V_20 ) ;
if ( F_56 ( V_6 ) ) {
V_52 = F_80 ( V_6 ) ;
goto V_102;
}
V_25 += V_6 -> V_113 ;
F_17 ( & V_20 -> V_25 , V_25 ) ;
F_81 ( & V_6 -> V_12 , & V_20 -> V_21 ) ;
V_122 ++ ;
V_6 -> V_125 = V_122 ;
if ( ! -- V_123 )
V_20 -> V_60 = V_6 ;
}
if ( V_122 != V_20 -> V_124 ) {
V_10 -> error = L_31 ;
V_52 = - V_94 ;
goto V_102;
}
V_10 -> V_126 = 1 ;
V_10 -> V_127 = 1 ;
V_10 -> V_128 = 1 ;
if ( V_19 )
V_10 -> V_129 = sizeof( struct V_39 ) ;
return 0 ;
V_102:
F_23 ( V_20 ) ;
return V_52 ;
}
static void F_88 ( struct V_18 * V_20 )
{
F_89 ( V_130 , V_131 ) ;
F_90 ( & V_20 -> V_31 , & V_130 ) ;
while ( 1 ) {
F_91 ( V_132 ) ;
if ( ! F_31 ( & V_20 -> V_26 ) )
break;
F_92 () ;
}
F_91 ( V_133 ) ;
F_93 ( & V_20 -> V_31 , & V_130 ) ;
}
static void F_94 ( struct V_18 * V_20 )
{
F_16 ( V_46 , & V_20 -> V_24 ) ;
F_95 () ;
F_96 ( V_51 ) ;
F_88 ( V_20 ) ;
F_96 ( V_134 ) ;
F_97 ( & V_20 -> V_30 ) ;
F_34 ( V_46 , & V_20 -> V_24 ) ;
F_95 () ;
}
static void F_98 ( struct V_9 * V_10 )
{
struct V_18 * V_20 = V_10 -> V_36 ;
F_94 ( V_20 ) ;
F_23 ( V_20 ) ;
}
static int F_99 ( struct V_1 * V_1 )
{
unsigned long V_24 ;
struct V_18 * V_20 = V_1 -> V_6 -> V_20 ;
F_39 ( & V_20 -> V_22 , V_24 ) ;
if ( ! V_1 -> V_3 )
goto V_135;
F_100 ( L_32 , V_1 -> V_13 . V_14 -> V_136 ) ;
V_1 -> V_6 -> V_16 . type -> F_99 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
V_1 -> V_3 = false ;
V_1 -> V_137 ++ ;
F_101 ( & V_20 -> V_25 ) ;
if ( V_1 == V_20 -> V_57 )
V_20 -> V_57 = NULL ;
F_102 ( V_138 , V_20 -> V_10 ,
V_1 -> V_13 . V_14 -> V_136 , F_31 ( & V_20 -> V_25 ) ) ;
F_103 ( & V_20 -> V_30 ) ;
V_135:
F_40 ( & V_20 -> V_22 , V_24 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_1 )
{
int V_52 = 0 , V_139 = 0 ;
unsigned long V_24 ;
struct V_18 * V_20 = V_1 -> V_6 -> V_20 ;
unsigned V_25 ;
F_39 ( & V_20 -> V_22 , V_24 ) ;
if ( V_1 -> V_3 )
goto V_135;
F_100 ( L_33 , V_1 -> V_13 . V_14 -> V_136 ) ;
V_52 = V_1 -> V_6 -> V_16 . type -> F_104 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
if ( V_52 )
goto V_135;
V_1 -> V_3 = true ;
V_25 = F_105 ( & V_20 -> V_25 ) ;
if ( V_25 == 1 ) {
V_20 -> V_57 = NULL ;
V_139 = 1 ;
} else if ( V_20 -> V_37 && ( V_20 -> V_48 == V_1 -> V_6 ) ) {
if ( F_106 ( V_51 , & V_1 -> V_4 . V_86 ) )
F_33 ( & V_20 -> V_26 ) ;
}
F_102 ( V_140 , V_20 -> V_10 ,
V_1 -> V_13 . V_14 -> V_136 , V_25 ) ;
F_103 ( & V_20 -> V_30 ) ;
V_135:
F_40 ( & V_20 -> V_22 , V_24 ) ;
if ( V_139 )
F_62 ( V_20 -> V_10 -> V_84 ) ;
return V_52 ;
}
static int F_107 ( struct V_18 * V_20 , struct V_141 * V_14 ,
T_2 V_142 )
{
int V_52 = - V_94 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_36 (pg, &m->priority_groups, list) {
F_36 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_13 . V_14 == V_14 )
V_52 = V_142 ( V_1 ) ;
}
}
return V_52 ;
}
static void F_108 ( struct V_18 * V_20 , struct V_5 * V_6 ,
bool V_58 )
{
unsigned long V_24 ;
F_39 ( & V_20 -> V_22 , V_24 ) ;
V_6 -> V_58 = V_58 ;
V_20 -> V_57 = NULL ;
V_20 -> V_48 = NULL ;
F_40 ( & V_20 -> V_22 , V_24 ) ;
F_103 ( & V_20 -> V_30 ) ;
}
static int F_109 ( struct V_18 * V_20 , const char * V_143 )
{
struct V_5 * V_6 ;
unsigned V_144 ;
unsigned long V_24 ;
char V_145 ;
if ( ! V_143 || ( sscanf ( V_143 , L_34 , & V_144 , & V_145 ) != 1 ) || ! V_144 ||
( V_144 > V_20 -> V_124 ) ) {
F_100 ( L_35 ) ;
return - V_94 ;
}
F_39 ( & V_20 -> V_22 , V_24 ) ;
F_36 (pg, &m->priority_groups, list) {
V_6 -> V_58 = false ;
if ( -- V_144 )
continue;
V_20 -> V_57 = NULL ;
V_20 -> V_48 = NULL ;
V_20 -> V_60 = V_6 ;
}
F_40 ( & V_20 -> V_22 , V_24 ) ;
F_103 ( & V_20 -> V_30 ) ;
return 0 ;
}
static int F_110 ( struct V_18 * V_20 , const char * V_143 , bool V_58 )
{
struct V_5 * V_6 ;
unsigned V_144 ;
char V_145 ;
if ( ! V_143 || ( sscanf ( V_143 , L_34 , & V_144 , & V_145 ) != 1 ) || ! V_144 ||
( V_144 > V_20 -> V_124 ) ) {
F_100 ( L_36 ) ;
return - V_94 ;
}
F_36 (pg, &m->priority_groups, list) {
if ( ! -- V_144 )
break;
}
F_108 ( V_20 , V_6 , V_58 ) ;
return 0 ;
}
static bool F_111 ( struct V_18 * V_20 , struct V_1 * V_1 )
{
unsigned long V_24 ;
bool V_146 = false ;
F_39 ( & V_20 -> V_22 , V_24 ) ;
if ( F_31 ( & V_20 -> V_27 ) <= V_20 -> V_121 &&
! F_32 ( V_46 , & V_20 -> V_24 ) )
F_16 ( V_47 , & V_20 -> V_24 ) ;
else
V_146 = true ;
F_40 ( & V_20 -> V_22 , V_24 ) ;
return V_146 ;
}
static void F_112 ( void * V_147 , int V_148 )
{
struct V_1 * V_1 = V_147 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_18 * V_20 = V_6 -> V_20 ;
unsigned long V_24 ;
bool V_149 = false ;
switch ( V_148 ) {
case V_150 :
break;
case V_151 :
if ( ! V_20 -> V_37 ) {
V_148 = 0 ;
break;
}
F_113 ( L_37
L_38 , V_20 -> V_37 , V_148 ) ;
F_99 ( V_1 ) ;
break;
case V_152 :
F_108 ( V_20 , V_6 , true ) ;
break;
case V_153 :
V_149 = 1 ;
case V_154 :
case V_155 :
if ( F_111 ( V_20 , V_1 ) )
F_99 ( V_1 ) ;
V_148 = 0 ;
break;
case V_156 :
default:
F_99 ( V_1 ) ;
}
F_39 ( & V_20 -> V_22 , V_24 ) ;
if ( V_148 ) {
if ( V_1 == V_20 -> V_57 ) {
F_113 ( L_39 , V_148 ) ;
V_20 -> V_57 = NULL ;
V_20 -> V_48 = NULL ;
}
} else if ( ! F_32 ( V_47 , & V_20 -> V_24 ) )
V_6 -> V_58 = false ;
if ( F_114 ( & V_20 -> V_26 ) > 0 )
goto V_135;
if ( F_32 ( V_47 , & V_20 -> V_24 ) ) {
if ( V_149 )
F_16 ( V_49 , & V_20 -> V_24 ) ;
else
F_34 ( V_49 , & V_20 -> V_24 ) ;
if ( F_30 ( V_20 ) )
goto V_135;
}
F_34 ( V_23 , & V_20 -> V_24 ) ;
F_115 ( & V_20 -> V_31 ) ;
V_135:
F_40 ( & V_20 -> V_22 , V_24 ) ;
}
static void V_4 ( struct V_85 * V_86 )
{
struct V_1 * V_1 =
F_63 ( V_86 , struct V_1 , V_4 . V_86 ) ;
if ( V_1 -> V_3 )
F_116 ( F_53 ( V_1 -> V_13 . V_14 -> V_71 ) ,
F_112 , V_1 ) ;
else
F_112 ( V_1 , V_156 ) ;
}
static int F_117 ( int error )
{
switch ( error ) {
case - V_157 :
case - V_158 :
case - V_159 :
case - V_160 :
case - V_161 :
return 1 ;
}
return 0 ;
}
static int F_118 ( struct V_18 * V_20 , struct V_64 * V_65 ,
int error , struct V_39 * V_43 )
{
int V_52 = V_162 ;
if ( ! error && ! V_65 -> V_148 )
return 0 ;
if ( F_117 ( error ) )
return error ;
if ( V_43 -> V_1 )
F_99 ( V_43 -> V_1 ) ;
if ( ! F_31 ( & V_20 -> V_25 ) ) {
if ( ! F_32 ( V_62 , & V_20 -> V_24 ) ) {
if ( ! F_49 ( V_20 ) )
V_52 = - V_72 ;
} else {
if ( error == - V_163 )
V_52 = error ;
}
}
return V_52 ;
}
static int F_119 ( struct V_9 * V_10 , struct V_64 * V_65 ,
int error , union V_40 * V_66 )
{
struct V_18 * V_20 = V_10 -> V_36 ;
struct V_39 * V_43 = F_25 ( V_66 ) ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_52 ;
F_120 ( ! V_43 ) ;
V_52 = F_118 ( V_20 , V_65 , error , V_43 ) ;
V_1 = V_43 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_164 )
V_16 -> type -> V_164 ( V_16 , & V_1 -> V_13 , V_43 -> V_53 ) ;
}
F_28 ( V_20 , V_66 ) ;
return V_52 ;
}
static void F_121 ( struct V_9 * V_10 )
{
struct V_18 * V_20 = V_10 -> V_36 ;
F_61 ( V_20 , false , true ) ;
}
static void F_122 ( struct V_9 * V_10 )
{
struct V_18 * V_20 = V_10 -> V_36 ;
F_123 ( & V_20 -> V_32 ) ;
F_94 ( V_20 ) ;
F_124 ( & V_20 -> V_32 ) ;
}
static void F_125 ( struct V_9 * V_10 )
{
struct V_18 * V_20 = V_10 -> V_36 ;
if ( F_32 ( V_63 , & V_20 -> V_24 ) )
F_16 ( V_62 , & V_20 -> V_24 ) ;
else
F_34 ( V_62 , & V_20 -> V_24 ) ;
F_95 () ;
}
static void F_126 ( struct V_9 * V_10 , T_3 type ,
unsigned V_165 , char * V_166 , unsigned V_167 )
{
int V_168 = 0 ;
unsigned long V_24 ;
struct V_18 * V_20 = V_10 -> V_36 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
unsigned V_125 ;
char V_169 ;
F_39 ( & V_20 -> V_22 , V_24 ) ;
if ( type == V_170 )
F_127 ( L_40 , F_32 ( V_23 , & V_20 -> V_24 ) ,
F_31 ( & V_20 -> V_27 ) ) ;
else {
F_127 ( L_41 , F_32 ( V_62 , & V_20 -> V_24 ) +
( V_20 -> V_121 > 0 ) * 2 +
( V_20 -> V_28 != V_29 ) * 2 +
F_32 ( V_103 , & V_20 -> V_24 ) ) ;
if ( F_32 ( V_62 , & V_20 -> V_24 ) )
F_127 ( L_42 ) ;
if ( V_20 -> V_121 )
F_127 ( L_43 , V_20 -> V_121 ) ;
if ( V_20 -> V_28 != V_29 )
F_127 ( L_44 , V_20 -> V_28 ) ;
if ( F_32 ( V_103 , & V_20 -> V_24 ) )
F_127 ( L_45 ) ;
}
if ( ! V_20 -> V_37 || type == V_170 )
F_127 ( L_46 ) ;
else
F_127 ( L_47 , V_20 -> V_37 ) ;
F_127 ( L_41 , V_20 -> V_124 ) ;
if ( V_20 -> V_60 )
V_125 = V_20 -> V_60 -> V_125 ;
else if ( V_20 -> V_48 )
V_125 = V_20 -> V_48 -> V_125 ;
else
V_125 = ( V_20 -> V_124 ? 1 : 0 ) ;
F_127 ( L_41 , V_125 ) ;
switch ( type ) {
case V_170 :
F_36 (pg, &m->priority_groups, list) {
if ( V_6 -> V_58 )
V_169 = 'D' ;
else if ( V_6 == V_20 -> V_48 )
V_169 = 'A' ;
else
V_169 = 'E' ;
F_127 ( L_48 , V_169 ) ;
if ( V_6 -> V_16 . type -> V_171 )
V_168 += V_6 -> V_16 . type -> V_171 ( & V_6 -> V_16 , NULL , type ,
V_166 + V_168 ,
V_167 - V_168 ) ;
else
F_127 ( L_46 ) ;
F_127 ( L_49 , V_6 -> V_113 ,
V_6 -> V_16 . type -> V_172 ) ;
F_36 (p, &pg->pgpaths, list) {
F_127 ( L_50 , V_97 -> V_13 . V_14 -> V_136 ,
V_97 -> V_3 ? L_51 : L_52 ,
V_97 -> V_137 ) ;
if ( V_6 -> V_16 . type -> V_171 )
V_168 += V_6 -> V_16 . type -> V_171 ( & V_6 -> V_16 ,
& V_97 -> V_13 , type , V_166 + V_168 ,
V_167 - V_168 ) ;
}
}
break;
case V_173 :
F_36 (pg, &m->priority_groups, list) {
F_127 ( L_53 , V_6 -> V_16 . type -> V_136 ) ;
if ( V_6 -> V_16 . type -> V_171 )
V_168 += V_6 -> V_16 . type -> V_171 ( & V_6 -> V_16 , NULL , type ,
V_166 + V_168 ,
V_167 - V_168 ) ;
else
F_127 ( L_46 ) ;
F_127 ( L_49 , V_6 -> V_113 ,
V_6 -> V_16 . type -> V_174 ) ;
F_36 (p, &pg->pgpaths, list) {
F_127 ( L_53 , V_97 -> V_13 . V_14 -> V_136 ) ;
if ( V_6 -> V_16 . type -> V_171 )
V_168 += V_6 -> V_16 . type -> V_171 ( & V_6 -> V_16 ,
& V_97 -> V_13 , type , V_166 + V_168 ,
V_167 - V_168 ) ;
}
}
break;
}
F_40 ( & V_20 -> V_22 , V_24 ) ;
}
static int F_128 ( struct V_9 * V_10 , unsigned V_100 , char * * V_96 )
{
int V_52 = - V_94 ;
struct V_141 * V_14 ;
struct V_18 * V_20 = V_10 -> V_36 ;
T_2 V_142 ;
F_123 ( & V_20 -> V_32 ) ;
if ( F_129 ( V_10 ) ) {
V_52 = - V_105 ;
goto V_135;
}
if ( V_100 == 1 ) {
if ( ! strcasecmp ( V_96 [ 0 ] , L_22 ) ) {
V_52 = F_61 ( V_20 , true , false ) ;
goto V_135;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_54 ) ) {
V_52 = F_61 ( V_20 , false , false ) ;
goto V_135;
}
}
if ( V_100 != 2 ) {
F_100 ( L_55 , V_100 ) ;
goto V_135;
}
if ( ! strcasecmp ( V_96 [ 0 ] , L_56 ) ) {
V_52 = F_110 ( V_20 , V_96 [ 1 ] , true ) ;
goto V_135;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_57 ) ) {
V_52 = F_110 ( V_20 , V_96 [ 1 ] , false ) ;
goto V_135;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_58 ) ) {
V_52 = F_109 ( V_20 , V_96 [ 1 ] ) ;
goto V_135;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_59 ) )
V_142 = F_104 ;
else if ( ! strcasecmp ( V_96 [ 0 ] , L_60 ) )
V_142 = F_99 ;
else {
F_100 ( L_61 , V_96 [ 0 ] ) ;
goto V_135;
}
V_52 = F_71 ( V_10 , V_96 [ 1 ] , F_72 ( V_10 -> V_84 ) , & V_14 ) ;
if ( V_52 ) {
F_100 ( L_62 ,
V_96 [ 1 ] ) ;
goto V_135;
}
V_52 = F_107 ( V_20 , V_14 , V_142 ) ;
F_11 ( V_10 , V_14 ) ;
V_135:
F_124 ( & V_20 -> V_32 ) ;
return V_52 ;
}
static int F_130 ( struct V_9 * V_10 ,
struct V_70 * * V_71 , T_4 * V_175 )
{
struct V_18 * V_20 = V_10 -> V_36 ;
struct V_1 * V_57 ;
int V_52 ;
V_57 = F_46 ( V_20 -> V_57 ) ;
if ( ! V_57 )
V_57 = F_47 ( V_20 , 0 ) ;
if ( V_57 ) {
if ( ! F_32 ( V_23 , & V_20 -> V_24 ) ) {
* V_71 = V_57 -> V_13 . V_14 -> V_71 ;
* V_175 = V_57 -> V_13 . V_14 -> V_175 ;
V_52 = 0 ;
} else {
V_52 = - V_176 ;
}
} else {
if ( F_32 ( V_62 , & V_20 -> V_24 ) )
V_52 = - V_176 ;
else
V_52 = - V_72 ;
}
if ( V_52 == - V_176 ) {
if ( ! F_46 ( V_20 -> V_48 ) ) {
( void ) F_47 ( V_20 , 0 ) ;
}
if ( F_32 ( V_47 , & V_20 -> V_24 ) )
F_38 ( V_20 ) ;
F_62 ( V_20 -> V_10 -> V_84 ) ;
}
if ( ! V_52 && V_10 -> V_118 != F_131 ( ( * V_71 ) -> V_177 ) >> V_178 )
return 1 ;
return V_52 ;
}
static int F_132 ( struct V_9 * V_10 ,
T_5 V_179 , void * V_147 )
{
struct V_18 * V_20 = V_10 -> V_36 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
int V_116 = 0 ;
F_36 (pg, &m->priority_groups, list) {
F_36 (p, &pg->pgpaths, list) {
V_116 = V_179 ( V_10 , V_97 -> V_13 . V_14 , V_10 -> V_180 , V_10 -> V_118 , V_147 ) ;
if ( V_116 )
goto V_135;
}
}
V_135:
return V_116 ;
}
static int F_133 ( struct V_1 * V_1 )
{
struct V_98 * V_73 = F_53 ( V_1 -> V_13 . V_14 -> V_71 ) ;
return F_134 ( V_73 ) ;
}
static int F_135 ( struct V_9 * V_10 )
{
bool V_181 = false , V_182 = false ;
struct V_18 * V_20 = V_10 -> V_36 ;
struct V_5 * V_6 , * V_60 ;
struct V_1 * V_1 ;
if ( F_31 ( & V_20 -> V_26 ) ||
( ! F_31 ( & V_20 -> V_25 ) && F_32 ( V_62 , & V_20 -> V_24 ) ) )
return true ;
V_6 = F_46 ( V_20 -> V_48 ) ;
V_60 = F_46 ( V_20 -> V_60 ) ;
if ( F_45 ( ! F_46 ( V_20 -> V_57 ) && V_60 ) )
V_6 = V_60 ;
if ( ! V_6 ) {
return V_181 ;
}
V_181 = true ;
F_36 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_3 ) {
V_182 = true ;
if ( ! F_133 ( V_1 ) ) {
V_181 = false ;
break;
}
}
}
if ( ! V_182 ) {
V_181 = false ;
}
return V_181 ;
}
static int T_6 F_136 ( void )
{
int V_52 ;
V_35 = F_137 ( V_39 , 0 ) ;
if ( ! V_35 )
return - V_101 ;
V_52 = F_138 ( & V_183 ) ;
if ( V_52 < 0 ) {
F_113 ( L_63 , V_52 ) ;
V_52 = - V_94 ;
goto V_184;
}
V_134 = F_139 ( L_64 , V_185 , 0 ) ;
if ( ! V_134 ) {
F_113 ( L_65 ) ;
V_52 = - V_101 ;
goto V_186;
}
V_51 = F_140 ( L_66 ,
V_185 ) ;
if ( ! V_51 ) {
F_113 ( L_67 ) ;
V_52 = - V_101 ;
goto V_187;
}
F_141 ( L_68 ,
V_183 . V_188 [ 0 ] , V_183 . V_188 [ 1 ] ,
V_183 . V_188 [ 2 ] ) ;
return 0 ;
V_187:
F_142 ( V_134 ) ;
V_186:
F_143 ( & V_183 ) ;
V_184:
F_144 ( V_35 ) ;
return V_52 ;
}
static void T_7 F_145 ( void )
{
F_142 ( V_51 ) ;
F_142 ( V_134 ) ;
F_143 ( & V_183 ) ;
F_144 ( V_35 ) ;
}
