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
V_20 -> V_23 = true ;
V_20 -> V_24 = V_25 ;
F_16 ( & V_20 -> V_26 , V_26 ) ;
F_17 ( & V_20 -> V_27 ) ;
F_18 ( & V_20 -> V_28 ) ;
V_20 -> V_29 = NULL ;
if ( ! V_19 ) {
unsigned V_30 = F_19 () ;
V_20 -> V_29 = F_20 ( V_30 , V_31 ) ;
if ( ! V_20 -> V_29 ) {
F_5 ( V_20 ) ;
return NULL ;
}
}
V_20 -> V_10 = V_10 ;
V_10 -> V_32 = V_20 ;
}
return V_20 ;
}
static void F_21 ( struct V_18 * V_20 )
{
struct V_5 * V_6 , * V_11 ;
F_9 (pg, tmp, &m->priority_groups, list) {
F_10 ( & V_6 -> V_12 ) ;
F_12 ( V_6 , V_20 -> V_10 ) ;
}
F_5 ( V_20 -> V_33 ) ;
F_5 ( V_20 -> V_34 ) ;
F_22 ( V_20 -> V_29 ) ;
F_5 ( V_20 ) ;
}
static struct V_35 * F_23 ( union V_36 * V_37 )
{
return V_37 -> V_38 ;
}
static struct V_35 * F_24 ( struct V_18 * V_20 , union V_36 * V_37 )
{
struct V_35 * V_39 ;
if ( ! V_20 -> V_29 ) {
V_39 = F_23 ( V_37 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
return V_39 ;
}
V_39 = F_25 ( V_20 -> V_29 , V_40 ) ;
if ( ! V_39 )
return NULL ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_37 -> V_38 = V_39 ;
return V_39 ;
}
static void F_26 ( struct V_18 * V_20 , union V_36 * V_37 )
{
if ( V_20 -> V_29 ) {
struct V_35 * V_39 = V_37 -> V_38 ;
V_37 -> V_38 = NULL ;
F_27 ( V_39 , V_20 -> V_29 ) ;
}
}
static int F_28 ( struct V_18 * V_20 )
{
struct V_1 * V_1 ;
unsigned long V_41 = 0 ;
if ( V_20 -> V_42 || V_20 -> V_43 )
return 0 ;
V_20 -> V_44 ++ ;
V_20 -> V_45 = false ;
if ( ! V_20 -> V_46 )
return 0 ;
if ( V_20 -> V_47 )
V_41 = F_29 ( V_20 -> V_24 != V_25 ?
V_20 -> V_24 : V_48 ) ;
F_30 (pgpath, &m->current_pg->pgpaths, list) {
if ( ! V_1 -> V_3 )
continue;
if ( F_31 ( V_49 , & V_1 -> V_4 ,
V_41 ) )
V_20 -> V_42 ++ ;
}
return V_20 -> V_42 ;
}
static void F_32 ( struct V_18 * V_20 , struct V_1 * V_1 )
{
V_20 -> V_46 = V_1 -> V_6 ;
if ( V_20 -> V_33 ) {
V_20 -> V_45 = true ;
V_20 -> V_23 = true ;
} else {
V_20 -> V_45 = false ;
V_20 -> V_23 = false ;
}
V_20 -> V_44 = 0 ;
}
static int F_33 ( struct V_18 * V_20 , struct V_5 * V_6 ,
T_1 V_50 )
{
struct V_51 * V_13 ;
V_13 = V_6 -> V_16 . type -> V_52 ( & V_6 -> V_16 , V_50 ) ;
if ( ! V_13 )
return - V_53 ;
V_20 -> V_54 = F_34 ( V_13 ) ;
if ( V_20 -> V_46 != V_6 )
F_32 ( V_20 , V_20 -> V_54 ) ;
return 0 ;
}
static void F_35 ( struct V_18 * V_20 , T_1 V_50 )
{
struct V_5 * V_6 ;
bool V_55 = true ;
if ( ! V_20 -> V_56 ) {
V_20 -> V_23 = false ;
goto V_57;
}
if ( V_20 -> V_58 ) {
V_6 = V_20 -> V_58 ;
V_20 -> V_58 = NULL ;
if ( ! F_33 ( V_20 , V_6 , V_50 ) )
return;
}
if ( V_20 -> V_46 && ! F_33 ( V_20 , V_20 -> V_46 , V_50 ) )
return;
do {
F_30 (pg, &m->priority_groups, list) {
if ( V_6 -> V_55 == V_55 )
continue;
if ( ! F_33 ( V_20 , V_6 , V_50 ) ) {
if ( ! V_55 )
V_20 -> V_47 = true ;
return;
}
}
} while ( V_55 -- );
V_57:
V_20 -> V_54 = NULL ;
V_20 -> V_46 = NULL ;
}
static int F_36 ( struct V_18 * V_20 )
{
return ( V_20 -> V_59 ||
( V_20 -> V_59 != V_20 -> V_60 &&
F_37 ( V_20 -> V_10 ) ) ) ;
}
static int F_38 ( struct V_9 * V_10 , struct V_61 * V_62 ,
union V_36 * V_63 ,
struct V_61 * V_64 , struct V_61 * * V_65 )
{
struct V_18 * V_20 = V_10 -> V_32 ;
int V_66 = V_67 ;
T_1 V_50 = V_62 ? F_39 ( V_62 ) : F_39 ( V_64 ) ;
struct V_1 * V_1 ;
struct V_68 * V_69 ;
struct V_35 * V_39 ;
F_40 ( & V_20 -> V_22 ) ;
if ( ! V_20 -> V_54 || ! V_20 -> V_23 )
F_35 ( V_20 , V_50 ) ;
V_1 = V_20 -> V_54 ;
if ( ! V_1 ) {
if ( ! F_36 ( V_20 ) )
V_66 = - V_70 ;
goto V_71;
} else if ( V_20 -> V_23 || V_20 -> V_45 ) {
F_28 ( V_20 ) ;
goto V_71;
}
V_39 = F_24 ( V_20 , V_63 ) ;
if ( ! V_39 )
goto V_71;
V_39 -> V_1 = V_1 ;
V_39 -> V_50 = V_50 ;
V_69 = V_1 -> V_13 . V_14 -> V_69 ;
F_41 ( & V_20 -> V_22 ) ;
if ( V_62 ) {
V_62 -> V_72 = F_42 ( V_69 ) ;
V_62 -> V_73 = V_69 -> V_74 ;
V_62 -> V_75 |= V_76 ;
} else {
* V_65 = F_43 ( F_42 ( V_69 ) ,
F_44 ( V_64 ) , V_77 ) ;
if ( F_45 ( * V_65 ) ) {
F_26 ( V_20 , V_63 ) ;
return V_66 ;
}
( * V_65 ) -> V_78 = ( * V_65 ) -> V_79 = NULL ;
( * V_65 ) -> V_73 = V_69 -> V_74 ;
( * V_65 ) -> V_75 |= V_76 ;
}
if ( V_1 -> V_6 -> V_16 . type -> V_80 )
V_1 -> V_6 -> V_16 . type -> V_80 ( & V_1 -> V_6 -> V_16 ,
& V_1 -> V_13 ,
V_50 ) ;
return V_81 ;
V_71:
F_41 ( & V_20 -> V_22 ) ;
return V_66 ;
}
static int F_46 ( struct V_9 * V_10 , struct V_61 * V_62 ,
union V_36 * V_63 )
{
return F_38 ( V_10 , V_62 , V_63 , NULL , NULL ) ;
}
static int F_47 ( struct V_9 * V_10 , struct V_61 * V_64 ,
union V_36 * V_63 ,
struct V_61 * * V_62 )
{
return F_38 ( V_10 , NULL , V_63 , V_64 , V_62 ) ;
}
static void F_48 ( struct V_61 * V_62 )
{
F_49 ( V_62 ) ;
}
static int V_59 ( struct V_18 * V_20 , bool V_59 ,
bool V_82 )
{
unsigned long V_83 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( V_82 )
V_20 -> V_60 = V_20 -> V_59 ;
else
V_20 -> V_60 = V_59 ;
V_20 -> V_59 = V_59 ;
F_51 ( & V_20 -> V_22 , V_83 ) ;
if ( ! V_59 )
F_52 ( V_20 -> V_10 -> V_84 ) ;
return 0 ;
}
static void V_26 ( struct V_85 * V_86 )
{
struct V_18 * V_20 =
F_53 ( V_86 , struct V_18 , V_26 ) ;
F_54 ( V_20 -> V_10 -> V_84 ) ;
}
static int F_55 ( struct V_87 * V_88 , struct V_5 * V_6 ,
struct V_9 * V_10 )
{
int V_66 ;
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
V_66 = F_58 ( V_93 , V_88 , & V_91 , & V_10 -> error ) ;
if ( V_66 ) {
F_13 ( V_90 ) ;
return - V_94 ;
}
V_66 = V_90 -> V_95 ( & V_6 -> V_16 , V_91 , V_88 -> V_96 ) ;
if ( V_66 ) {
F_13 ( V_90 ) ;
V_10 -> error = L_3 ;
return V_66 ;
}
V_6 -> V_16 . type = V_90 ;
F_59 ( V_88 , V_91 ) ;
return 0 ;
}
static struct V_1 * F_60 ( struct V_87 * V_88 , struct V_15 * V_16 ,
struct V_9 * V_10 )
{
int V_66 ;
struct V_1 * V_97 ;
struct V_18 * V_20 = V_10 -> V_32 ;
struct V_98 * V_72 = NULL ;
const char * V_99 ;
if ( V_88 -> V_100 < 1 ) {
V_10 -> error = L_4 ;
return F_61 ( - V_94 ) ;
}
V_97 = F_1 () ;
if ( ! V_97 )
return F_61 ( - V_101 ) ;
V_66 = F_62 ( V_10 , F_57 ( V_88 ) , F_63 ( V_10 -> V_84 ) ,
& V_97 -> V_13 . V_14 ) ;
if ( V_66 ) {
V_10 -> error = L_5 ;
goto V_102;
}
if ( V_20 -> V_103 || V_20 -> V_33 )
V_72 = F_42 ( V_97 -> V_13 . V_14 -> V_69 ) ;
if ( V_20 -> V_103 ) {
V_104:
V_99 = F_64 ( V_72 , V_2 ) ;
if ( V_99 ) {
F_5 ( V_20 -> V_33 ) ;
V_20 -> V_33 = V_99 ;
F_5 ( V_20 -> V_34 ) ;
V_20 -> V_34 = NULL ;
}
}
if ( V_20 -> V_33 ) {
V_66 = F_65 ( V_72 , V_20 -> V_33 ) ;
if ( V_66 == - V_105 ) {
char V_106 [ V_107 ] ;
F_66 ( V_108 L_6 ,
F_67 ( V_97 -> V_13 . V_14 -> V_69 , V_106 ) ) ;
goto V_104;
}
if ( V_66 < 0 ) {
V_10 -> error = L_7 ;
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_102;
}
if ( V_20 -> V_34 ) {
V_66 = F_68 ( V_72 , V_20 -> V_34 ) ;
if ( V_66 < 0 ) {
V_10 -> error = L_8
L_9 ;
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_102;
}
}
}
V_66 = V_16 -> type -> V_109 ( V_16 , & V_97 -> V_13 , V_88 -> V_100 , V_88 -> V_96 , & V_10 -> error ) ;
if ( V_66 ) {
F_11 ( V_10 , V_97 -> V_13 . V_14 ) ;
goto V_102;
}
return V_97 ;
V_102:
F_4 ( V_97 ) ;
return F_61 ( V_66 ) ;
}
static struct V_5 * F_69 ( struct V_87 * V_88 ,
struct V_18 * V_20 )
{
static struct V_92 V_93 [] = {
{ 1 , 1024 , L_10 } ,
{ 0 , 1024 , L_11 }
} ;
int V_66 ;
unsigned V_110 , V_111 , V_112 ;
struct V_5 * V_6 ;
struct V_9 * V_10 = V_20 -> V_10 ;
if ( V_88 -> V_100 < 2 ) {
V_88 -> V_100 = 0 ;
V_10 -> error = L_12 ;
return F_61 ( - V_94 ) ;
}
V_6 = F_6 () ;
if ( ! V_6 ) {
V_10 -> error = L_13 ;
return F_61 ( - V_101 ) ;
}
V_6 -> V_20 = V_20 ;
V_66 = F_55 ( V_88 , V_6 , V_10 ) ;
if ( V_66 )
goto V_102;
V_66 = F_70 ( V_93 , V_88 , & V_6 -> V_113 , & V_10 -> error ) ;
if ( V_66 )
goto V_102;
V_66 = F_70 ( V_93 + 1 , V_88 , & V_111 , & V_10 -> error ) ;
if ( V_66 )
goto V_102;
V_112 = 1 + V_111 ;
for ( V_110 = 0 ; V_110 < V_6 -> V_113 ; V_110 ++ ) {
struct V_1 * V_1 ;
struct V_87 V_114 ;
if ( V_88 -> V_100 < V_112 ) {
V_10 -> error = L_14 ;
V_66 = - V_94 ;
goto V_102;
}
V_114 . V_100 = V_112 ;
V_114 . V_96 = V_88 -> V_96 ;
V_1 = F_60 ( & V_114 , & V_6 -> V_16 , V_10 ) ;
if ( F_45 ( V_1 ) ) {
V_66 = F_71 ( V_1 ) ;
goto V_102;
}
V_1 -> V_6 = V_6 ;
F_72 ( & V_1 -> V_12 , & V_6 -> V_7 ) ;
F_59 ( V_88 , V_112 ) ;
}
return V_6 ;
V_102:
F_12 ( V_6 , V_10 ) ;
return F_61 ( V_66 ) ;
}
static int F_73 ( struct V_87 * V_88 , struct V_18 * V_20 )
{
unsigned V_115 ;
int V_116 ;
struct V_9 * V_10 = V_20 -> V_10 ;
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_15 } ,
} ;
if ( F_58 ( V_93 , V_88 , & V_115 , & V_10 -> error ) )
return - V_94 ;
if ( ! V_115 )
return 0 ;
V_20 -> V_33 = F_74 ( F_57 ( V_88 ) , V_2 ) ;
if ( V_115 > 1 ) {
char * V_97 ;
int V_110 , V_117 , V_118 = 4 ;
for ( V_110 = 0 ; V_110 <= V_115 - 2 ; V_110 ++ )
V_118 += strlen ( V_88 -> V_96 [ V_110 ] ) + 1 ;
V_97 = V_20 -> V_34 = F_2 ( V_118 , V_2 ) ;
if ( ! V_97 ) {
V_10 -> error = L_16 ;
V_116 = - V_101 ;
goto V_119;
}
V_117 = sprintf ( V_97 , L_17 , V_115 - 1 ) ;
for ( V_110 = 0 , V_97 += V_117 + 1 ; V_110 <= V_115 - 2 ; V_110 ++ , V_97 += V_117 + 1 )
V_117 = sprintf ( V_97 , L_18 , V_88 -> V_96 [ V_110 ] ) ;
}
F_59 ( V_88 , V_115 - 1 ) ;
return 0 ;
V_119:
F_5 ( V_20 -> V_33 ) ;
V_20 -> V_33 = NULL ;
return V_116 ;
}
static int F_75 ( struct V_87 * V_88 , struct V_18 * V_20 )
{
int V_66 ;
unsigned V_100 ;
struct V_9 * V_10 = V_20 -> V_10 ;
const char * V_120 ;
static struct V_92 V_93 [] = {
{ 0 , 6 , L_19 } ,
{ 1 , 50 , L_20 } ,
{ 0 , 60000 , L_21 } ,
} ;
V_66 = F_58 ( V_93 , V_88 , & V_100 , & V_10 -> error ) ;
if ( V_66 )
return - V_94 ;
if ( ! V_100 )
return 0 ;
do {
V_120 = F_57 ( V_88 ) ;
V_100 -- ;
if ( ! strcasecmp ( V_120 , L_22 ) ) {
V_66 = V_59 ( V_20 , true , false ) ;
continue;
}
if ( ! strcasecmp ( V_120 , L_23 ) ) {
V_20 -> V_103 = true ;
continue;
}
if ( ! strcasecmp ( V_120 , L_24 ) &&
( V_100 >= 1 ) ) {
V_66 = F_70 ( V_93 + 1 , V_88 , & V_20 -> V_121 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
if ( ! strcasecmp ( V_120 , L_25 ) &&
( V_100 >= 1 ) ) {
V_66 = F_70 ( V_93 + 2 , V_88 , & V_20 -> V_24 , & V_10 -> error ) ;
V_100 -- ;
continue;
}
V_10 -> error = L_26 ;
V_66 = - V_94 ;
} while ( V_100 && ! V_66 );
return V_66 ;
}
static int F_76 ( struct V_9 * V_10 , unsigned int V_100 ,
char * * V_96 )
{
static struct V_92 V_93 [] = {
{ 0 , 1024 , L_27 } ,
{ 0 , 1024 , L_28 } ,
} ;
int V_66 ;
struct V_18 * V_20 ;
struct V_87 V_88 ;
unsigned V_122 = 0 ;
unsigned V_123 ;
bool V_19 = F_77 ( F_78 ( V_10 -> V_84 ) ) ;
V_88 . V_100 = V_100 ;
V_88 . V_96 = V_96 ;
V_20 = F_14 ( V_10 , V_19 ) ;
if ( ! V_20 ) {
V_10 -> error = L_29 ;
return - V_94 ;
}
V_66 = F_75 ( & V_88 , V_20 ) ;
if ( V_66 )
goto V_102;
V_66 = F_73 ( & V_88 , V_20 ) ;
if ( V_66 )
goto V_102;
V_66 = F_70 ( V_93 , & V_88 , & V_20 -> V_124 , & V_10 -> error ) ;
if ( V_66 )
goto V_102;
V_66 = F_70 ( V_93 + 1 , & V_88 , & V_123 , & V_10 -> error ) ;
if ( V_66 )
goto V_102;
if ( ( ! V_20 -> V_124 && V_123 ) ||
( V_20 -> V_124 && ! V_123 ) ) {
V_10 -> error = L_30 ;
V_66 = - V_94 ;
goto V_102;
}
while ( V_88 . V_100 ) {
struct V_5 * V_6 ;
V_6 = F_69 ( & V_88 , V_20 ) ;
if ( F_45 ( V_6 ) ) {
V_66 = F_71 ( V_6 ) ;
goto V_102;
}
V_20 -> V_56 += V_6 -> V_113 ;
F_72 ( & V_6 -> V_12 , & V_20 -> V_21 ) ;
V_122 ++ ;
V_6 -> V_125 = V_122 ;
if ( ! -- V_123 )
V_20 -> V_58 = V_6 ;
}
if ( V_122 != V_20 -> V_124 ) {
V_10 -> error = L_31 ;
V_66 = - V_94 ;
goto V_102;
}
V_10 -> V_126 = 1 ;
V_10 -> V_127 = 1 ;
V_10 -> V_128 = 1 ;
if ( V_19 )
V_10 -> V_129 = sizeof( struct V_35 ) ;
return 0 ;
V_102:
F_21 ( V_20 ) ;
return V_66 ;
}
static void F_79 ( struct V_18 * V_20 )
{
F_80 ( V_130 , V_131 ) ;
unsigned long V_83 ;
F_81 ( & V_20 -> V_27 , & V_130 ) ;
while ( 1 ) {
F_82 ( V_132 ) ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( ! V_20 -> V_42 ) {
F_51 ( & V_20 -> V_22 , V_83 ) ;
break;
}
F_51 ( & V_20 -> V_22 , V_83 ) ;
F_83 () ;
}
F_82 ( V_133 ) ;
F_84 ( & V_20 -> V_27 , & V_130 ) ;
}
static void F_85 ( struct V_18 * V_20 )
{
unsigned long V_83 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
V_20 -> V_43 = true ;
F_51 ( & V_20 -> V_22 , V_83 ) ;
F_86 ( V_49 ) ;
F_79 ( V_20 ) ;
F_86 ( V_134 ) ;
F_87 ( & V_20 -> V_26 ) ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
V_20 -> V_43 = false ;
F_51 ( & V_20 -> V_22 , V_83 ) ;
}
static void F_88 ( struct V_9 * V_10 )
{
struct V_18 * V_20 = V_10 -> V_32 ;
F_85 ( V_20 ) ;
F_21 ( V_20 ) ;
}
static int F_89 ( struct V_1 * V_1 )
{
unsigned long V_83 ;
struct V_18 * V_20 = V_1 -> V_6 -> V_20 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( ! V_1 -> V_3 )
goto V_135;
F_90 ( L_32 , V_1 -> V_13 . V_14 -> V_136 ) ;
V_1 -> V_6 -> V_16 . type -> F_89 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
V_1 -> V_3 = false ;
V_1 -> V_137 ++ ;
V_20 -> V_56 -- ;
if ( V_1 == V_20 -> V_54 )
V_20 -> V_54 = NULL ;
F_91 ( V_138 , V_20 -> V_10 ,
V_1 -> V_13 . V_14 -> V_136 , V_20 -> V_56 ) ;
F_92 ( & V_20 -> V_26 ) ;
V_135:
F_51 ( & V_20 -> V_22 , V_83 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_1 )
{
int V_66 = 0 , V_139 = 0 ;
unsigned long V_83 ;
struct V_18 * V_20 = V_1 -> V_6 -> V_20 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( V_1 -> V_3 )
goto V_135;
F_90 ( L_33 , V_1 -> V_13 . V_14 -> V_136 ) ;
V_66 = V_1 -> V_6 -> V_16 . type -> F_93 ( & V_1 -> V_6 -> V_16 , & V_1 -> V_13 ) ;
if ( V_66 )
goto V_135;
V_1 -> V_3 = true ;
if ( ! V_20 -> V_56 ++ ) {
V_20 -> V_54 = NULL ;
V_139 = 1 ;
} else if ( V_20 -> V_33 && ( V_20 -> V_46 == V_1 -> V_6 ) ) {
if ( F_94 ( V_49 , & V_1 -> V_4 . V_86 ) )
V_20 -> V_42 ++ ;
}
F_91 ( V_140 , V_20 -> V_10 ,
V_1 -> V_13 . V_14 -> V_136 , V_20 -> V_56 ) ;
F_92 ( & V_20 -> V_26 ) ;
V_135:
F_51 ( & V_20 -> V_22 , V_83 ) ;
if ( V_139 )
F_52 ( V_20 -> V_10 -> V_84 ) ;
return V_66 ;
}
static int F_95 ( struct V_18 * V_20 , struct V_141 * V_14 ,
T_2 V_142 )
{
int V_66 = - V_94 ;
struct V_1 * V_1 ;
struct V_5 * V_6 ;
F_30 (pg, &m->priority_groups, list) {
F_30 (pgpath, &pg->pgpaths, list) {
if ( V_1 -> V_13 . V_14 == V_14 )
V_66 = V_142 ( V_1 ) ;
}
}
return V_66 ;
}
static void F_96 ( struct V_18 * V_20 , struct V_5 * V_6 ,
bool V_55 )
{
unsigned long V_83 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
V_6 -> V_55 = V_55 ;
V_20 -> V_54 = NULL ;
V_20 -> V_46 = NULL ;
F_51 ( & V_20 -> V_22 , V_83 ) ;
F_92 ( & V_20 -> V_26 ) ;
}
static int F_97 ( struct V_18 * V_20 , const char * V_143 )
{
struct V_5 * V_6 ;
unsigned V_144 ;
unsigned long V_83 ;
char V_145 ;
if ( ! V_143 || ( sscanf ( V_143 , L_34 , & V_144 , & V_145 ) != 1 ) || ! V_144 ||
( V_144 > V_20 -> V_124 ) ) {
F_90 ( L_35 ) ;
return - V_94 ;
}
F_50 ( & V_20 -> V_22 , V_83 ) ;
F_30 (pg, &m->priority_groups, list) {
V_6 -> V_55 = false ;
if ( -- V_144 )
continue;
V_20 -> V_54 = NULL ;
V_20 -> V_46 = NULL ;
V_20 -> V_58 = V_6 ;
}
F_51 ( & V_20 -> V_22 , V_83 ) ;
F_92 ( & V_20 -> V_26 ) ;
return 0 ;
}
static int F_98 ( struct V_18 * V_20 , const char * V_143 , bool V_55 )
{
struct V_5 * V_6 ;
unsigned V_144 ;
char V_145 ;
if ( ! V_143 || ( sscanf ( V_143 , L_34 , & V_144 , & V_145 ) != 1 ) || ! V_144 ||
( V_144 > V_20 -> V_124 ) ) {
F_90 ( L_36 ) ;
return - V_94 ;
}
F_30 (pg, &m->priority_groups, list) {
if ( ! -- V_144 )
break;
}
F_96 ( V_20 , V_6 , V_55 ) ;
return 0 ;
}
static bool F_99 ( struct V_18 * V_20 , struct V_1 * V_1 )
{
unsigned long V_83 ;
bool V_146 = false ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( V_20 -> V_44 <= V_20 -> V_121 && ! V_20 -> V_43 )
V_20 -> V_45 = true ;
else
V_146 = true ;
F_51 ( & V_20 -> V_22 , V_83 ) ;
return V_146 ;
}
static void F_100 ( void * V_147 , int V_148 )
{
struct V_1 * V_1 = V_147 ;
struct V_5 * V_6 = V_1 -> V_6 ;
struct V_18 * V_20 = V_6 -> V_20 ;
unsigned long V_83 ;
bool V_149 = false ;
switch ( V_148 ) {
case V_150 :
break;
case V_151 :
if ( ! V_20 -> V_33 ) {
V_148 = 0 ;
break;
}
F_101 ( L_37
L_38 , V_20 -> V_33 , V_148 ) ;
F_89 ( V_1 ) ;
break;
case V_152 :
F_96 ( V_20 , V_6 , true ) ;
break;
case V_153 :
V_149 = 1 ;
case V_154 :
case V_155 :
if ( F_99 ( V_20 , V_1 ) )
F_89 ( V_1 ) ;
V_148 = 0 ;
break;
case V_156 :
default:
F_89 ( V_1 ) ;
}
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( V_148 ) {
if ( V_1 == V_20 -> V_54 ) {
F_101 ( L_39 , V_148 ) ;
V_20 -> V_54 = NULL ;
V_20 -> V_46 = NULL ;
}
} else if ( ! V_20 -> V_45 )
V_6 -> V_55 = false ;
if ( -- V_20 -> V_42 )
goto V_135;
if ( V_20 -> V_45 ) {
V_20 -> V_47 = V_149 ;
if ( F_28 ( V_20 ) )
goto V_135;
}
V_20 -> V_23 = false ;
F_102 ( & V_20 -> V_27 ) ;
V_135:
F_51 ( & V_20 -> V_22 , V_83 ) ;
}
static void V_4 ( struct V_85 * V_86 )
{
struct V_1 * V_1 =
F_53 ( V_86 , struct V_1 , V_4 . V_86 ) ;
if ( V_1 -> V_3 )
F_103 ( F_42 ( V_1 -> V_13 . V_14 -> V_69 ) ,
F_100 , V_1 ) ;
else
F_100 ( V_1 , V_156 ) ;
}
static int F_104 ( int error )
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
static int F_105 ( struct V_18 * V_20 , struct V_61 * V_62 ,
int error , struct V_35 * V_39 )
{
int V_66 = V_162 ;
unsigned long V_83 ;
if ( ! error && ! V_62 -> V_148 )
return 0 ;
if ( F_104 ( error ) )
return error ;
if ( V_39 -> V_1 )
F_89 ( V_39 -> V_1 ) ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( ! V_20 -> V_56 ) {
if ( ! V_20 -> V_59 ) {
if ( ! F_36 ( V_20 ) )
V_66 = - V_70 ;
} else {
if ( error == - V_163 )
V_66 = error ;
}
}
F_51 ( & V_20 -> V_22 , V_83 ) ;
return V_66 ;
}
static int F_106 ( struct V_9 * V_10 , struct V_61 * V_62 ,
int error , union V_36 * V_63 )
{
struct V_18 * V_20 = V_10 -> V_32 ;
struct V_35 * V_39 = F_23 ( V_63 ) ;
struct V_1 * V_1 ;
struct V_15 * V_16 ;
int V_66 ;
F_107 ( ! V_39 ) ;
V_66 = F_105 ( V_20 , V_62 , error , V_39 ) ;
V_1 = V_39 -> V_1 ;
if ( V_1 ) {
V_16 = & V_1 -> V_6 -> V_16 ;
if ( V_16 -> type -> V_164 )
V_16 -> type -> V_164 ( V_16 , & V_1 -> V_13 , V_39 -> V_50 ) ;
}
F_26 ( V_20 , V_63 ) ;
return V_66 ;
}
static void F_108 ( struct V_9 * V_10 )
{
struct V_18 * V_20 = V_10 -> V_32 ;
V_59 ( V_20 , false , true ) ;
}
static void F_109 ( struct V_9 * V_10 )
{
struct V_18 * V_20 = V_10 -> V_32 ;
F_110 ( & V_20 -> V_28 ) ;
F_85 ( V_20 ) ;
F_111 ( & V_20 -> V_28 ) ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_18 * V_20 = V_10 -> V_32 ;
unsigned long V_83 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
V_20 -> V_59 = V_20 -> V_60 ;
F_51 ( & V_20 -> V_22 , V_83 ) ;
}
static void F_113 ( struct V_9 * V_10 , T_3 type ,
unsigned V_165 , char * V_166 , unsigned V_167 )
{
int V_168 = 0 ;
unsigned long V_83 ;
struct V_18 * V_20 = V_10 -> V_32 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
unsigned V_125 ;
char V_169 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( type == V_170 )
F_114 ( L_40 , V_20 -> V_23 , V_20 -> V_44 ) ;
else {
F_114 ( L_41 , V_20 -> V_59 +
( V_20 -> V_121 > 0 ) * 2 +
( V_20 -> V_24 != V_25 ) * 2 +
V_20 -> V_103 ) ;
if ( V_20 -> V_59 )
F_114 ( L_42 ) ;
if ( V_20 -> V_121 )
F_114 ( L_43 , V_20 -> V_121 ) ;
if ( V_20 -> V_24 != V_25 )
F_114 ( L_44 , V_20 -> V_24 ) ;
if ( V_20 -> V_103 )
F_114 ( L_45 ) ;
}
if ( ! V_20 -> V_33 || type == V_170 )
F_114 ( L_46 ) ;
else
F_114 ( L_47 , V_20 -> V_33 ) ;
F_114 ( L_41 , V_20 -> V_124 ) ;
if ( V_20 -> V_58 )
V_125 = V_20 -> V_58 -> V_125 ;
else if ( V_20 -> V_46 )
V_125 = V_20 -> V_46 -> V_125 ;
else
V_125 = ( V_20 -> V_124 ? 1 : 0 ) ;
F_114 ( L_41 , V_125 ) ;
switch ( type ) {
case V_170 :
F_30 (pg, &m->priority_groups, list) {
if ( V_6 -> V_55 )
V_169 = 'D' ;
else if ( V_6 == V_20 -> V_46 )
V_169 = 'A' ;
else
V_169 = 'E' ;
F_114 ( L_48 , V_169 ) ;
if ( V_6 -> V_16 . type -> V_171 )
V_168 += V_6 -> V_16 . type -> V_171 ( & V_6 -> V_16 , NULL , type ,
V_166 + V_168 ,
V_167 - V_168 ) ;
else
F_114 ( L_46 ) ;
F_114 ( L_49 , V_6 -> V_113 ,
V_6 -> V_16 . type -> V_172 ) ;
F_30 (p, &pg->pgpaths, list) {
F_114 ( L_50 , V_97 -> V_13 . V_14 -> V_136 ,
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
F_30 (pg, &m->priority_groups, list) {
F_114 ( L_53 , V_6 -> V_16 . type -> V_136 ) ;
if ( V_6 -> V_16 . type -> V_171 )
V_168 += V_6 -> V_16 . type -> V_171 ( & V_6 -> V_16 , NULL , type ,
V_166 + V_168 ,
V_167 - V_168 ) ;
else
F_114 ( L_46 ) ;
F_114 ( L_49 , V_6 -> V_113 ,
V_6 -> V_16 . type -> V_174 ) ;
F_30 (p, &pg->pgpaths, list) {
F_114 ( L_53 , V_97 -> V_13 . V_14 -> V_136 ) ;
if ( V_6 -> V_16 . type -> V_171 )
V_168 += V_6 -> V_16 . type -> V_171 ( & V_6 -> V_16 ,
& V_97 -> V_13 , type , V_166 + V_168 ,
V_167 - V_168 ) ;
}
}
break;
}
F_51 ( & V_20 -> V_22 , V_83 ) ;
}
static int F_115 ( struct V_9 * V_10 , unsigned V_100 , char * * V_96 )
{
int V_66 = - V_94 ;
struct V_141 * V_14 ;
struct V_18 * V_20 = V_10 -> V_32 ;
T_2 V_142 ;
F_110 ( & V_20 -> V_28 ) ;
if ( F_116 ( V_10 ) ) {
V_66 = - V_105 ;
goto V_135;
}
if ( V_100 == 1 ) {
if ( ! strcasecmp ( V_96 [ 0 ] , L_22 ) ) {
V_66 = V_59 ( V_20 , true , false ) ;
goto V_135;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_54 ) ) {
V_66 = V_59 ( V_20 , false , false ) ;
goto V_135;
}
}
if ( V_100 != 2 ) {
F_90 ( L_55 , V_100 ) ;
goto V_135;
}
if ( ! strcasecmp ( V_96 [ 0 ] , L_56 ) ) {
V_66 = F_98 ( V_20 , V_96 [ 1 ] , true ) ;
goto V_135;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_57 ) ) {
V_66 = F_98 ( V_20 , V_96 [ 1 ] , false ) ;
goto V_135;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_58 ) ) {
V_66 = F_97 ( V_20 , V_96 [ 1 ] ) ;
goto V_135;
} else if ( ! strcasecmp ( V_96 [ 0 ] , L_59 ) )
V_142 = F_93 ;
else if ( ! strcasecmp ( V_96 [ 0 ] , L_60 ) )
V_142 = F_89 ;
else {
F_90 ( L_61 , V_96 [ 0 ] ) ;
goto V_135;
}
V_66 = F_62 ( V_10 , V_96 [ 1 ] , F_63 ( V_10 -> V_84 ) , & V_14 ) ;
if ( V_66 ) {
F_90 ( L_62 ,
V_96 [ 1 ] ) ;
goto V_135;
}
V_66 = F_95 ( V_20 , V_14 , V_142 ) ;
F_11 ( V_10 , V_14 ) ;
V_135:
F_111 ( & V_20 -> V_28 ) ;
return V_66 ;
}
static int F_117 ( struct V_9 * V_10 ,
struct V_68 * * V_69 , T_4 * V_175 )
{
struct V_18 * V_20 = V_10 -> V_32 ;
unsigned long V_83 ;
int V_66 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( ! V_20 -> V_54 )
F_35 ( V_20 , 0 ) ;
if ( V_20 -> V_54 ) {
if ( ! V_20 -> V_23 ) {
* V_69 = V_20 -> V_54 -> V_13 . V_14 -> V_69 ;
* V_175 = V_20 -> V_54 -> V_13 . V_14 -> V_175 ;
V_66 = 0 ;
} else {
V_66 = - V_176 ;
}
} else {
if ( V_20 -> V_59 )
V_66 = - V_176 ;
else
V_66 = - V_70 ;
}
F_51 ( & V_20 -> V_22 , V_83 ) ;
if ( V_66 == - V_176 ) {
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( ! V_20 -> V_46 ) {
F_35 ( V_20 , 0 ) ;
}
if ( V_20 -> V_45 )
F_28 ( V_20 ) ;
F_51 ( & V_20 -> V_22 , V_83 ) ;
F_52 ( V_20 -> V_10 -> V_84 ) ;
}
if ( ! V_66 && V_10 -> V_118 != F_118 ( ( * V_69 ) -> V_177 ) >> V_178 )
return 1 ;
return V_66 ;
}
static int F_119 ( struct V_9 * V_10 ,
T_5 V_179 , void * V_147 )
{
struct V_18 * V_20 = V_10 -> V_32 ;
struct V_5 * V_6 ;
struct V_1 * V_97 ;
int V_116 = 0 ;
F_30 (pg, &m->priority_groups, list) {
F_30 (p, &pg->pgpaths, list) {
V_116 = V_179 ( V_10 , V_97 -> V_13 . V_14 , V_10 -> V_180 , V_10 -> V_118 , V_147 ) ;
if ( V_116 )
goto V_135;
}
}
V_135:
return V_116 ;
}
static int F_120 ( struct V_1 * V_1 )
{
struct V_98 * V_72 = F_42 ( V_1 -> V_13 . V_14 -> V_69 ) ;
return F_121 ( V_72 ) ;
}
static int F_122 ( struct V_9 * V_10 )
{
bool V_181 = false , V_182 = false ;
struct V_18 * V_20 = V_10 -> V_32 ;
struct V_5 * V_6 ;
struct V_1 * V_1 ;
unsigned long V_83 ;
F_50 ( & V_20 -> V_22 , V_83 ) ;
if ( V_20 -> V_42 ||
( ! V_20 -> V_56 && V_20 -> V_59 ) ) {
V_181 = true ;
goto V_135;
}
if ( F_123 ( ! V_20 -> V_54 && V_20 -> V_58 ) )
V_6 = V_20 -> V_58 ;
else if ( F_124 ( V_20 -> V_46 ) )
V_6 = V_20 -> V_46 ;
else
goto V_135;
V_181 = true ;
F_30 (pgpath, &pg->pgpaths, list)
if ( V_1 -> V_3 ) {
V_182 = true ;
if ( ! F_120 ( V_1 ) ) {
V_181 = false ;
break;
}
}
if ( ! V_182 )
V_181 = false ;
V_135:
F_51 ( & V_20 -> V_22 , V_83 ) ;
return V_181 ;
}
static int T_6 F_125 ( void )
{
int V_66 ;
V_31 = F_126 ( V_35 , 0 ) ;
if ( ! V_31 )
return - V_101 ;
V_66 = F_127 ( & V_183 ) ;
if ( V_66 < 0 ) {
F_101 ( L_63 , V_66 ) ;
V_66 = - V_94 ;
goto V_184;
}
V_134 = F_128 ( L_64 , V_185 , 0 ) ;
if ( ! V_134 ) {
F_101 ( L_65 ) ;
V_66 = - V_101 ;
goto V_186;
}
V_49 = F_129 ( L_66 ,
V_185 ) ;
if ( ! V_49 ) {
F_101 ( L_67 ) ;
V_66 = - V_101 ;
goto V_187;
}
F_130 ( L_68 ,
V_183 . V_188 [ 0 ] , V_183 . V_188 [ 1 ] ,
V_183 . V_188 [ 2 ] ) ;
return 0 ;
V_187:
F_131 ( V_134 ) ;
V_186:
F_132 ( & V_183 ) ;
V_184:
F_133 ( V_31 ) ;
return V_66 ;
}
static void T_7 F_134 ( void )
{
F_131 ( V_49 ) ;
F_131 ( V_134 ) ;
F_132 ( & V_183 ) ;
F_133 ( V_31 ) ;
}
