static bool F_1 ( int V_1 )
{
return V_1 >= V_2 ;
}
static void F_2 ( struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ ) {
if ( ! V_4 -> V_7 [ V_5 ] . V_8 )
continue;
F_3 ( L_1 ,
V_4 -> V_7 [ V_5 ] . V_9 ,
V_4 -> V_7 [ V_5 ] . V_10 / 1024 ,
V_4 -> V_7 [ V_5 ] . V_8 ) ;
}
}
int F_4 ( struct V_11 * V_12 , void * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_12 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_19 -> V_18 ;
struct V_3 * V_4 = F_5 ( V_18 ) ;
int V_5 ;
F_6 ( & V_4 -> V_20 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ ) {
if ( ! V_4 -> V_7 [ V_5 ] . V_8 )
continue;
F_7 ( V_12 , L_1 ,
V_4 -> V_7 [ V_5 ] . V_9 ,
V_4 -> V_7 [ V_5 ] . V_10 / 1024 ,
V_4 -> V_7 [ V_5 ] . V_8 ) ;
}
F_8 ( & V_4 -> V_20 ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_4 , const char * V_9 )
{
int V_5 ;
int V_21 = - 1 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ ) {
if ( ! V_4 -> V_7 [ V_5 ] . V_9 ) {
V_21 = V_5 ;
} else if ( strcmp ( V_4 -> V_7 [ V_5 ] . V_9 , V_9 ) == 0 ) {
F_10 ( V_9 ) ;
return V_5 ;
}
}
if ( V_21 != - 1 ) {
F_11 ( V_4 -> V_7 [ V_21 ] . V_8 != 0 ) ;
V_4 -> V_7 [ V_21 ] . V_9 = V_9 ;
return V_21 ;
} else {
T_1 V_22 = V_4 -> V_6 + 1 ;
struct V_23 * V_24 =
F_12 ( V_4 -> V_7 ,
V_22 * sizeof( * V_24 ) ,
V_25 ) ;
if ( ! V_24 ) {
F_10 ( V_9 ) ;
return - 1 ;
}
V_21 = V_4 -> V_6 ;
V_4 -> V_7 = V_24 ;
V_4 -> V_6 = V_22 ;
V_4 -> V_7 [ V_21 ] . V_9 = V_9 ;
V_4 -> V_7 [ V_21 ] . V_8 = 0 ;
V_4 -> V_7 [ V_21 ] . V_10 = 0 ;
return V_21 ;
}
}
static void F_13 ( struct V_26 * V_27 , int V_1 )
{
struct V_28 * V_29 = F_14 ( V_27 ) ;
struct V_3 * V_4 = F_5 ( V_27 -> V_18 ) ;
F_15 ( & V_4 -> V_20 ) ;
if ( V_1 != - 1 ) {
V_4 -> V_7 [ V_1 ] . V_8 ++ ;
V_4 -> V_7 [ V_1 ] . V_10 += V_27 -> V_30 ;
}
V_4 -> V_7 [ V_29 -> V_1 ] . V_8 -- ;
V_4 -> V_7 [ V_29 -> V_1 ] . V_10 -= V_27 -> V_30 ;
if ( V_4 -> V_7 [ V_29 -> V_1 ] . V_8 == 0 &&
F_1 ( V_29 -> V_1 ) ) {
F_10 ( V_4 -> V_7 [ V_29 -> V_1 ] . V_9 ) ;
V_4 -> V_7 [ V_29 -> V_1 ] . V_9 = NULL ;
}
V_29 -> V_1 = V_1 ;
}
static T_2 F_16 ( T_3 V_30 )
{
return ( V_30 / V_31 ) - 1 ;
}
static void F_17 ( struct V_28 * V_29 )
{
struct V_26 * V_32 = & V_29 -> V_33 . V_33 ;
struct V_3 * V_4 = F_5 ( V_32 -> V_18 ) ;
F_15 ( & V_4 -> V_20 ) ;
F_13 ( V_32 , - 1 ) ;
if ( V_29 -> V_34 ) {
F_10 ( V_29 -> V_34 -> V_35 ) ;
F_10 ( V_29 -> V_34 ) ;
V_29 -> V_34 = NULL ;
}
F_18 ( & V_29 -> V_36 ) ;
F_19 ( V_32 ) ;
}
static void F_20 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_5 ( V_29 -> V_33 . V_33 . V_18 ) ;
F_15 ( & V_4 -> V_20 ) ;
F_21 ( & V_29 -> V_37 ) ;
F_21 ( & V_29 -> V_38 ) ;
}
static struct V_39 * F_22 ( struct V_17 * V_18 ,
T_3 V_30 )
{
struct V_3 * V_4 = F_5 ( V_18 ) ;
T_2 V_40 = F_16 ( V_30 ) ;
if ( V_4 -> V_41 . V_42 <= V_40 ) {
T_2 V_43 = F_23 ( V_4 -> V_41 . V_42 * 2 ,
V_40 + 1 ) ;
struct V_39 * V_44 ;
T_2 V_5 ;
V_44 = F_24 ( V_43 , sizeof( struct V_39 ) ,
V_25 ) ;
if ( ! V_44 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_4 -> V_41 . V_42 ; V_5 ++ ) {
struct V_39 * V_45 =
& V_4 -> V_41 . V_46 [ V_5 ] ;
if ( F_25 ( V_45 ) )
F_26 ( & V_44 [ V_5 ] ) ;
else
F_27 ( V_45 , & V_44 [ V_5 ] ) ;
}
for ( V_5 = V_4 -> V_41 . V_42 ; V_5 < V_43 ; V_5 ++ )
F_26 ( & V_44 [ V_5 ] ) ;
F_10 ( V_4 -> V_41 . V_46 ) ;
V_4 -> V_41 . V_46 = V_44 ;
V_4 -> V_41 . V_42 = V_43 ;
}
return & V_4 -> V_41 . V_46 [ V_40 ] ;
}
static void F_28 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_5 ( V_18 ) ;
F_6 ( & V_4 -> V_20 ) ;
while ( ! F_25 ( & V_4 -> V_41 . V_47 ) ) {
struct V_28 * V_29 = F_29 ( & V_4 -> V_41 . V_47 ,
struct V_28 , V_37 ) ;
F_20 ( V_29 ) ;
F_17 ( V_29 ) ;
}
F_8 ( & V_4 -> V_20 ) ;
}
static struct V_28 * F_30 ( struct V_17 * V_18 ,
T_2 V_30 ,
enum V_48 type )
{
struct V_3 * V_4 = F_5 ( V_18 ) ;
T_2 V_40 = F_16 ( V_30 ) ;
struct V_28 * V_29 = NULL ;
V_30 = F_31 ( V_30 , V_31 ) ;
F_6 ( & V_4 -> V_20 ) ;
if ( V_40 >= V_4 -> V_41 . V_42 )
goto V_49;
if ( F_25 ( & V_4 -> V_41 . V_46 [ V_40 ] ) )
goto V_49;
V_29 = F_32 ( & V_4 -> V_41 . V_46 [ V_40 ] ,
struct V_28 , V_38 ) ;
F_20 ( V_29 ) ;
F_33 ( & V_29 -> V_33 . V_33 . V_50 ) ;
V_49:
if ( V_29 )
F_13 ( & V_29 -> V_33 . V_33 , type ) ;
F_8 ( & V_4 -> V_20 ) ;
return V_29 ;
}
struct V_26 * F_34 ( struct V_17 * V_18 , T_3 V_30 )
{
struct V_3 * V_4 = F_5 ( V_18 ) ;
struct V_28 * V_29 ;
V_29 = F_35 ( sizeof( * V_29 ) , V_25 ) ;
if ( ! V_29 )
return F_36 ( - V_51 ) ;
F_6 ( & V_4 -> V_20 ) ;
V_29 -> V_1 = V_52 ;
V_4 -> V_7 [ V_52 ] . V_8 ++ ;
V_4 -> V_7 [ V_52 ] . V_10 += V_30 ;
F_8 ( & V_4 -> V_20 ) ;
V_29 -> V_53 = & V_29 -> V_36 ;
F_37 ( V_29 -> V_53 ) ;
return & V_29 -> V_33 . V_33 ;
}
struct V_28 * F_38 ( struct V_17 * V_18 , T_3 V_54 ,
bool V_55 , enum V_48 type )
{
T_3 V_30 = F_31 ( V_54 , V_31 ) ;
struct V_3 * V_4 = F_5 ( V_18 ) ;
struct V_56 * V_57 ;
struct V_28 * V_29 ;
if ( V_30 == 0 )
return F_36 ( - V_58 ) ;
V_29 = F_30 ( V_18 , V_30 , type ) ;
if ( V_29 ) {
if ( ! V_55 )
memset ( V_29 -> V_33 . V_59 , 0 , V_29 -> V_33 . V_33 . V_30 ) ;
return V_29 ;
}
V_57 = F_39 ( V_18 , V_30 ) ;
if ( F_40 ( V_57 ) ) {
F_28 ( V_18 ) ;
V_57 = F_39 ( V_18 , V_30 ) ;
if ( F_40 ( V_57 ) ) {
F_41 ( L_2 ) ;
F_2 ( V_4 ) ;
return F_36 ( - V_51 ) ;
}
}
V_29 = F_14 ( & V_57 -> V_33 ) ;
F_6 ( & V_4 -> V_20 ) ;
F_13 ( & V_57 -> V_33 , type ) ;
F_8 ( & V_4 -> V_20 ) ;
return V_29 ;
}
int F_42 ( struct V_60 * V_61 ,
struct V_17 * V_18 ,
struct V_62 * args )
{
int V_63 = F_43 ( args -> V_64 * args -> V_65 , 8 ) ;
struct V_28 * V_29 = NULL ;
int V_66 ;
if ( args -> V_67 < V_63 )
args -> V_67 = V_63 ;
if ( args -> V_30 < args -> V_67 * args -> V_68 )
args -> V_30 = args -> V_67 * args -> V_68 ;
V_29 = F_38 ( V_18 , args -> V_30 , false , V_69 ) ;
if ( F_40 ( V_29 ) )
return F_44 ( V_29 ) ;
V_66 = F_45 ( V_61 , & V_29 -> V_33 . V_33 , & args -> V_70 ) ;
F_46 ( & V_29 -> V_33 . V_33 ) ;
return V_66 ;
}
static void F_47 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_5 ( V_18 ) ;
unsigned long V_71 = V_72 - F_48 ( 1000 ) ;
F_15 ( & V_4 -> V_20 ) ;
while ( ! F_25 ( & V_4 -> V_41 . V_47 ) ) {
struct V_28 * V_29 = F_29 ( & V_4 -> V_41 . V_47 ,
struct V_28 , V_37 ) ;
if ( F_49 ( V_71 , V_29 -> V_73 ) ) {
F_50 ( & V_4 -> V_41 . V_74 ,
F_51 ( V_72 +
F_48 ( 1000 ) ) ) ;
return;
}
F_20 ( V_29 ) ;
F_17 ( V_29 ) ;
}
}
void F_52 ( struct V_26 * V_75 )
{
struct V_17 * V_18 = V_75 -> V_18 ;
struct V_3 * V_4 = F_5 ( V_18 ) ;
struct V_28 * V_29 = F_14 ( V_75 ) ;
struct V_39 * V_76 ;
F_6 ( & V_4 -> V_20 ) ;
if ( V_75 -> V_77 ) {
F_17 ( V_29 ) ;
goto V_49;
}
if ( V_75 -> V_9 ) {
F_17 ( V_29 ) ;
goto V_49;
}
if ( ! V_29 -> V_33 . V_59 ) {
F_17 ( V_29 ) ;
goto V_49;
}
V_76 = F_22 ( V_18 , V_75 -> V_30 ) ;
if ( ! V_76 ) {
F_17 ( V_29 ) ;
goto V_49;
}
if ( V_29 -> V_34 ) {
F_10 ( V_29 -> V_34 -> V_35 ) ;
F_10 ( V_29 -> V_34 ) ;
V_29 -> V_34 = NULL ;
}
V_29 -> V_78 = false ;
V_29 -> V_73 = V_72 ;
F_53 ( & V_29 -> V_38 , V_76 ) ;
F_53 ( & V_29 -> V_37 , & V_4 -> V_41 . V_47 ) ;
F_13 ( & V_29 -> V_33 . V_33 , V_79 ) ;
F_47 ( V_18 ) ;
V_49:
F_8 ( & V_4 -> V_20 ) ;
}
static void F_54 ( struct V_80 * V_81 )
{
struct V_3 * V_4 =
F_55 ( V_81 , struct V_3 , V_41 . V_82 ) ;
struct V_17 * V_18 = V_4 -> V_18 ;
F_6 ( & V_4 -> V_20 ) ;
F_47 ( V_18 ) ;
F_8 ( & V_4 -> V_20 ) ;
}
static void F_56 ( unsigned long V_83 )
{
struct V_17 * V_18 = (struct V_17 * ) V_83 ;
struct V_3 * V_4 = F_5 ( V_18 ) ;
F_57 ( & V_4 -> V_41 . V_82 ) ;
}
struct V_84 * F_58 ( struct V_26 * V_32 )
{
struct V_28 * V_29 = F_14 ( V_32 ) ;
return V_29 -> V_53 ;
}
struct V_85 *
F_59 ( struct V_17 * V_18 , struct V_26 * V_32 , int V_86 )
{
struct V_28 * V_29 = F_14 ( V_32 ) ;
if ( V_29 -> V_34 ) {
F_60 ( L_3 ) ;
return F_36 ( - V_58 ) ;
}
return F_61 ( V_18 , V_32 , V_86 ) ;
}
int F_62 ( struct V_87 * V_88 , struct V_89 * V_90 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_66 ;
V_66 = F_63 ( V_88 , V_90 ) ;
if ( V_66 )
return V_66 ;
V_27 = V_90 -> V_91 ;
V_29 = F_14 ( V_27 ) ;
if ( V_29 -> V_34 && ( V_90 -> V_92 & V_93 ) ) {
F_60 ( L_4 ) ;
return - V_58 ;
}
V_90 -> V_92 &= ~ V_94 ;
V_90 -> V_95 = 0 ;
V_66 = F_64 ( V_29 -> V_33 . V_33 . V_18 -> V_18 , V_90 , V_29 -> V_33 . V_59 ,
V_29 -> V_33 . V_96 , V_90 -> V_97 - V_90 -> V_98 ) ;
if ( V_66 )
F_65 ( V_90 ) ;
return V_66 ;
}
int F_66 ( struct V_26 * V_32 , struct V_89 * V_90 )
{
struct V_28 * V_29 = F_14 ( V_32 ) ;
if ( V_29 -> V_34 && ( V_90 -> V_92 & V_93 ) ) {
F_60 ( L_4 ) ;
return - V_58 ;
}
return F_67 ( V_32 , V_90 ) ;
}
void * F_68 ( struct V_26 * V_32 )
{
struct V_28 * V_29 = F_14 ( V_32 ) ;
if ( V_29 -> V_34 ) {
F_60 ( L_5 ) ;
return F_36 ( - V_58 ) ;
}
return F_69 ( V_32 ) ;
}
struct V_26 *
F_70 ( struct V_17 * V_18 ,
struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_26 * V_32 ;
struct V_28 * V_29 ;
V_32 = F_71 ( V_18 , V_100 , V_102 ) ;
if ( F_40 ( V_32 ) )
return V_32 ;
V_29 = F_14 ( V_32 ) ;
V_29 -> V_53 = V_100 -> V_103 -> V_53 ;
return V_32 ;
}
int F_72 ( struct V_17 * V_18 , void * V_83 ,
struct V_60 * V_61 )
{
struct V_104 * args = V_83 ;
struct V_28 * V_29 = NULL ;
int V_66 ;
V_29 = F_38 ( V_18 , args -> V_30 , false , V_105 ) ;
if ( F_40 ( V_29 ) )
return F_44 ( V_29 ) ;
V_66 = F_45 ( V_61 , & V_29 -> V_33 . V_33 , & args -> V_70 ) ;
F_46 ( & V_29 -> V_33 . V_33 ) ;
return V_66 ;
}
int F_73 ( struct V_17 * V_18 , void * V_83 ,
struct V_60 * V_61 )
{
struct V_106 * args = V_83 ;
struct V_26 * V_27 ;
V_27 = F_74 ( V_61 , args -> V_70 ) ;
if ( ! V_27 ) {
F_60 ( L_6 , args -> V_70 ) ;
return - V_58 ;
}
args -> V_107 = F_75 ( & V_27 -> V_108 ) ;
F_46 ( V_27 ) ;
return 0 ;
}
int
F_76 ( struct V_17 * V_18 , void * V_83 ,
struct V_60 * V_61 )
{
struct V_109 * args = V_83 ;
struct V_28 * V_29 = NULL ;
int V_66 ;
if ( args -> V_30 == 0 )
return - V_58 ;
if ( args -> V_30 % sizeof( V_110 ) != 0 )
return - V_58 ;
if ( args -> V_86 != 0 ) {
F_3 ( L_7 , args -> V_86 ) ;
return - V_58 ;
}
if ( args -> V_111 != 0 ) {
F_3 ( L_8 , args -> V_111 ) ;
return - V_58 ;
}
V_29 = F_38 ( V_18 , args -> V_30 , true , V_112 ) ;
if ( F_40 ( V_29 ) )
return F_44 ( V_29 ) ;
if ( F_77 ( V_29 -> V_33 . V_59 ,
( void V_113 * ) ( V_114 ) args -> V_83 ,
args -> V_30 ) ) {
V_66 = - V_115 ;
goto V_116;
}
memset ( V_29 -> V_33 . V_59 + args -> V_30 , 0 ,
V_29 -> V_33 . V_33 . V_30 - args -> V_30 ) ;
V_29 -> V_34 = F_78 ( & V_29 -> V_33 ) ;
if ( ! V_29 -> V_34 ) {
V_66 = - V_58 ;
goto V_116;
}
V_66 = F_45 ( V_61 , & V_29 -> V_33 . V_33 , & args -> V_70 ) ;
V_116:
F_46 ( & V_29 -> V_33 . V_33 ) ;
return V_66 ;
}
int F_79 ( struct V_17 * V_18 , void * V_83 ,
struct V_60 * V_61 )
{
struct V_117 * args = V_83 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
bool V_78 ;
if ( args -> V_86 != 0 )
return - V_58 ;
switch ( args -> V_118 ) {
case V_119 :
V_78 = false ;
break;
case V_120 :
V_78 = true ;
break;
default:
return - V_58 ;
}
V_27 = F_74 ( V_61 , args -> V_70 ) ;
if ( ! V_27 ) {
F_60 ( L_6 , args -> V_70 ) ;
return - V_121 ;
}
V_29 = F_14 ( V_27 ) ;
V_29 -> V_78 = V_78 ;
F_46 ( V_27 ) ;
return 0 ;
}
int F_80 ( struct V_17 * V_18 , void * V_83 ,
struct V_60 * V_61 )
{
struct V_122 * args = V_83 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
if ( args -> V_86 != 0 || args -> V_118 != 0 )
return - V_58 ;
V_27 = F_74 ( V_61 , args -> V_70 ) ;
if ( ! V_27 ) {
F_60 ( L_6 , args -> V_70 ) ;
return - V_121 ;
}
V_29 = F_14 ( V_27 ) ;
if ( V_29 -> V_78 )
args -> V_118 = V_120 ;
else
args -> V_118 = V_119 ;
F_46 ( V_27 ) ;
return 0 ;
}
int F_81 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_5 ( V_18 ) ;
int V_5 ;
V_4 -> V_7 = F_82 ( V_2 , sizeof( * V_4 -> V_7 ) ,
V_25 ) ;
if ( ! V_4 -> V_7 )
return - V_51 ;
V_4 -> V_6 = V_2 ;
F_83 ( F_84 ( V_123 ) != V_2 ) ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ )
V_4 -> V_7 [ V_5 ] . V_9 = V_123 [ V_5 ] ;
F_85 ( & V_4 -> V_20 ) ;
F_26 ( & V_4 -> V_41 . V_47 ) ;
F_86 ( & V_4 -> V_41 . V_82 , F_54 ) ;
F_87 ( & V_4 -> V_41 . V_74 ,
F_56 ,
( unsigned long ) V_18 ) ;
return 0 ;
}
void F_88 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = F_5 ( V_18 ) ;
int V_5 ;
F_89 ( & V_4 -> V_41 . V_74 ) ;
F_90 ( & V_4 -> V_41 . V_82 ) ;
F_28 ( V_18 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ ) {
if ( V_4 -> V_7 [ V_5 ] . V_8 ) {
F_41 ( L_9
L_10 ,
V_4 -> V_7 [ V_5 ] . V_8 ,
V_4 -> V_7 [ V_5 ] . V_9 ) ;
}
if ( F_1 ( V_5 ) )
F_10 ( V_4 -> V_7 [ V_5 ] . V_9 ) ;
}
F_10 ( V_4 -> V_7 ) ;
}
int F_91 ( struct V_17 * V_18 , void * V_83 ,
struct V_60 * V_61 )
{
struct V_3 * V_4 = F_5 ( V_18 ) ;
struct V_124 * args = V_83 ;
char * V_9 ;
struct V_26 * V_27 ;
int V_66 = 0 , V_1 ;
if ( ! args -> V_125 )
return - V_58 ;
V_9 = F_92 ( F_93 ( args -> V_9 ) , args -> V_125 + 1 ) ;
if ( F_40 ( V_9 ) )
return F_44 ( V_9 ) ;
V_27 = F_74 ( V_61 , args -> V_70 ) ;
if ( ! V_27 ) {
F_41 ( L_6 , args -> V_70 ) ;
F_10 ( V_9 ) ;
return - V_121 ;
}
F_6 ( & V_4 -> V_20 ) ;
V_1 = F_9 ( V_4 , V_9 ) ;
if ( V_1 != - 1 )
F_13 ( V_27 , V_1 ) ;
else
V_66 = - V_51 ;
F_8 ( & V_4 -> V_20 ) ;
F_46 ( V_27 ) ;
return V_66 ;
}
