static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
}
static int F_4 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_1 * V_2 , * V_7 ;
F_5 ( V_8 ) ;
F_6 ( & V_6 -> V_9 ) ;
if ( F_7 ( & V_6 -> V_8 ) ) {
F_8 ( & V_6 -> V_9 ) ;
return 1 ;
}
F_9 ( & V_8 , & V_6 -> V_8 , V_6 -> V_8 . V_10 ) ;
V_6 -> V_11 = 0 ;
F_8 ( & V_6 -> V_9 ) ;
F_10 (gc_rq, tgc_rq, &w_list, list) {
F_11 ( V_4 , V_2 -> V_3 , V_2 -> V_12 ,
V_2 -> V_13 , V_2 -> V_14 ,
V_2 -> line , V_15 ) ;
F_12 ( & V_2 -> V_16 ) ;
F_13 ( & V_2 -> line -> V_17 , V_18 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static void F_14 ( struct V_5 * V_6 )
{
F_15 ( V_6 -> V_19 ) ;
}
static int F_16 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_20 * V_21 = V_4 -> V_21 ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_24 * line = V_2 -> line ;
void * V_3 ;
unsigned int V_14 ;
int V_25 = 0 ;
V_3 = F_17 ( V_2 -> V_13 * V_23 -> V_26 ) ;
if ( ! V_3 ) {
V_25 = - V_27 ;
goto V_28;
}
if ( F_18 ( V_4 , V_2 -> V_12 , V_3 , V_2 -> V_13 ,
& V_14 , line ) ) {
V_25 = - V_29 ;
goto V_30;
}
if ( ! V_14 )
goto V_31;
V_2 -> V_3 = V_3 ;
V_2 -> V_14 = V_14 ;
V_32:
F_6 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_11 >= V_33 ) {
F_8 ( & V_6 -> V_9 ) ;
F_14 ( & V_4 -> V_6 ) ;
F_19 ( 128 , 256 ) ;
goto V_32;
}
V_6 -> V_11 ++ ;
F_20 ( & V_2 -> V_16 , & V_6 -> V_8 ) ;
F_8 ( & V_6 -> V_9 ) ;
F_14 ( & V_4 -> V_6 ) ;
return 0 ;
V_31:
F_3 ( V_2 ) ;
V_30:
F_2 ( V_3 ) ;
V_28:
F_13 ( & line -> V_17 , V_18 ) ;
return V_25 ;
}
static void F_21 ( struct V_4 * V_4 , struct V_24 * line )
{
struct V_34 * V_35 = & V_4 -> V_35 ;
struct V_36 * V_37 ;
F_6 ( & line -> V_38 ) ;
F_22 ( line -> V_39 != V_40 ) ;
line -> V_39 = V_41 ;
V_37 = F_23 ( V_4 , line ) ;
F_8 ( & line -> V_38 ) ;
if ( V_37 ) {
F_6 ( & V_35 -> V_42 ) ;
F_20 ( & line -> V_16 , V_37 ) ;
F_8 ( & V_35 -> V_42 ) ;
}
}
static void F_24 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = F_25 ( V_44 ,
struct V_45 , V_47 ) ;
struct V_4 * V_4 = V_46 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_24 * line = V_46 -> line ;
struct V_1 * V_2 = V_46 -> V_48 ;
F_26 ( & V_6 -> V_49 ) ;
if ( F_16 ( V_4 , V_2 ) ) {
F_27 ( L_1 ,
line -> V_50 , * line -> V_51 ,
V_2 -> V_13 ) ;
}
F_28 ( V_46 , V_4 -> V_52 ) ;
}
static void F_29 ( struct V_43 * V_44 )
{
struct V_45 * V_53 = F_25 ( V_44 , struct V_45 ,
V_47 ) ;
struct V_4 * V_4 = V_53 -> V_4 ;
struct V_24 * line = V_53 -> line ;
struct V_34 * V_35 = & V_4 -> V_35 ;
struct V_54 * V_55 = & V_4 -> V_55 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_56 * V_57 ;
struct V_45 * V_46 ;
struct V_1 * V_2 ;
T_1 * V_12 ;
int V_58 , V_13 , V_59 ;
int V_25 ;
V_57 = F_30 ( V_55 -> V_60 [ 0 ] , V_35 -> V_61 ,
V_62 ) ;
if ( ! V_57 ) {
F_27 ( L_2 ) ;
return;
}
V_25 = F_31 ( V_4 , line , V_57 ) ;
if ( V_25 ) {
F_27 ( L_3 , line -> V_50 , V_25 ) ;
goto V_63;
}
V_12 = F_32 ( V_4 , V_57 ) ;
if ( ! V_12 ) {
F_27 ( L_4 , line -> V_50 ) ;
goto V_63;
}
V_58 = F_33 ( line ) ;
if ( V_58 < 0 ) {
F_27 ( L_5 , line -> V_50 ) ;
goto V_63;
}
V_59 = - 1 ;
V_64:
V_2 = F_34 ( sizeof( struct V_1 ) , V_62 ) ;
if ( ! V_2 )
goto V_63;
V_13 = 0 ;
do {
V_59 = F_35 ( line -> V_65 , V_55 -> V_66 ,
V_59 + 1 ) ;
if ( V_59 > line -> V_67 )
break;
V_2 -> V_12 [ V_13 ++ ] = F_36 ( V_12 [ V_59 ] ) ;
} while ( V_13 < V_4 -> V_68 );
if ( F_37 ( ! V_13 ) ) {
F_3 ( V_2 ) ;
goto V_28;
}
V_2 -> V_13 = V_13 ;
V_2 -> line = line ;
V_46 = F_38 ( V_4 -> V_52 , V_62 ) ;
if ( ! V_46 )
goto V_69;
V_46 -> V_4 = V_4 ;
V_46 -> line = line ;
V_46 -> V_48 = V_2 ;
F_39 ( & V_6 -> V_49 ) ;
F_40 ( & line -> V_17 ) ;
F_41 ( & V_46 -> V_47 , F_24 ) ;
F_42 ( V_6 -> V_70 , & V_46 -> V_47 ) ;
V_58 -= V_13 ;
if ( V_58 > 0 )
goto V_64;
V_28:
F_43 ( V_57 , V_35 -> V_61 ) ;
F_28 ( V_53 , V_4 -> V_52 ) ;
F_13 ( & line -> V_17 , V_18 ) ;
F_44 ( & V_6 -> V_71 ) ;
return;
V_69:
F_3 ( V_2 ) ;
V_63:
F_43 ( V_57 , V_35 -> V_61 ) ;
F_21 ( V_4 , line ) ;
F_13 ( & line -> V_17 , V_18 ) ;
F_28 ( V_53 , V_4 -> V_52 ) ;
F_44 ( & V_6 -> V_71 ) ;
F_27 ( L_6 , line -> V_50 ) ;
}
static int F_45 ( struct V_4 * V_4 , struct V_24 * line )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_45 * V_53 ;
F_46 ( L_7 , line -> V_50 ) ;
V_53 = F_38 ( V_4 -> V_52 , V_62 ) ;
if ( ! V_53 )
return - V_27 ;
V_53 -> V_4 = V_4 ;
V_53 -> line = line ;
F_41 ( & V_53 -> V_47 , F_29 ) ;
F_42 ( V_6 -> V_72 , & V_53 -> V_47 ) ;
return 0 ;
}
static int F_47 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_24 * line ;
F_6 ( & V_6 -> V_73 ) ;
if ( F_7 ( & V_6 -> V_74 ) ) {
F_8 ( & V_6 -> V_73 ) ;
return 1 ;
}
line = F_48 ( & V_6 -> V_74 , struct V_24 , V_16 ) ;
F_12 ( & line -> V_16 ) ;
F_8 ( & V_6 -> V_73 ) ;
F_49 ( V_4 ) ;
if ( F_45 ( V_4 , line ) )
F_27 ( L_8 , line -> V_50 ) ;
return 0 ;
}
static void F_50 ( struct V_5 * V_6 )
{
F_15 ( V_6 -> V_75 ) ;
}
static struct V_24 * F_51 ( struct V_4 * V_4 ,
struct V_36 * V_76 )
{
struct V_24 * line , * V_77 ;
int V_78 , V_79 ;
V_77 = F_48 ( V_76 , struct V_24 , V_16 ) ;
F_52 (line, group_list, list) {
V_78 = F_53 ( * line -> V_51 ) ;
V_79 = F_53 ( * V_77 -> V_51 ) ;
if ( V_78 < V_79 )
V_77 = line ;
}
return V_77 ;
}
static bool F_54 ( struct V_5 * V_6 , struct V_80 * V_81 )
{
unsigned int V_82 , V_83 ;
V_83 = F_55 ( V_81 ) ;
V_82 = F_56 ( V_81 ) ;
return ( ( V_6 -> V_84 ) && ( V_83 > V_82 ) ) ;
}
static void F_57 ( struct V_4 * V_4 )
{
struct V_34 * V_35 = & V_4 -> V_35 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_24 * line ;
struct V_36 * V_76 ;
bool V_85 ;
int V_71 , V_86 = 0 , V_87 = 0 ;
do {
F_6 ( & V_35 -> V_42 ) ;
if ( F_7 ( & V_35 -> V_88 ) ) {
F_8 ( & V_35 -> V_42 ) ;
break;
}
line = F_48 ( & V_35 -> V_88 ,
struct V_24 , V_16 ) ;
F_6 ( & line -> V_38 ) ;
F_22 ( line -> V_39 != V_41 ) ;
line -> V_39 = V_40 ;
F_8 ( & line -> V_38 ) ;
F_12 ( & line -> V_16 ) ;
F_8 ( & V_35 -> V_42 ) ;
F_13 ( & line -> V_17 , V_18 ) ;
} while ( 1 );
V_85 = F_54 ( & V_4 -> V_6 , & V_4 -> V_81 ) ;
if ( ! V_85 || ( F_58 ( & V_6 -> V_71 ) >= V_89 ) )
return;
V_90:
V_76 = V_35 -> V_91 [ V_86 ++ ] ;
do {
F_6 ( & V_35 -> V_42 ) ;
if ( F_7 ( V_76 ) ) {
F_8 ( & V_35 -> V_42 ) ;
break;
}
line = F_51 ( V_4 , V_76 ) ;
F_6 ( & line -> V_38 ) ;
F_22 ( line -> V_39 != V_41 ) ;
line -> V_39 = V_40 ;
F_8 ( & line -> V_38 ) ;
F_12 ( & line -> V_16 ) ;
F_8 ( & V_35 -> V_42 ) ;
F_6 ( & V_6 -> V_73 ) ;
F_20 ( & line -> V_16 , & V_6 -> V_74 ) ;
F_8 ( & V_6 -> V_73 ) ;
V_71 = F_59 ( & V_6 -> V_71 ) ;
F_50 ( V_6 ) ;
V_87 = 1 ;
V_85 = F_54 ( & V_4 -> V_6 , & V_4 -> V_81 ) ;
if ( ! V_85 || V_71 >= V_89 )
break;
} while ( 1 );
if ( ! V_87 && V_4 -> V_81 . V_92 > V_86 &&
V_86 < V_93 )
goto V_90;
}
void F_49 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
F_15 ( V_6 -> V_94 ) ;
F_14 ( V_6 ) ;
F_50 ( V_6 ) ;
F_60 ( & V_6 -> V_95 , V_96 + F_61 ( V_97 ) ) ;
}
static void F_62 ( unsigned long V_3 )
{
struct V_4 * V_4 = (struct V_4 * ) V_3 ;
F_49 ( V_4 ) ;
}
static int F_63 ( void * V_3 )
{
struct V_4 * V_4 = V_3 ;
while ( ! F_64 () ) {
F_57 ( V_4 ) ;
F_65 ( V_98 ) ;
F_66 () ;
}
return 0 ;
}
static int F_67 ( void * V_3 )
{
struct V_4 * V_4 = V_3 ;
while ( ! F_64 () ) {
if ( ! F_4 ( V_4 ) )
continue;
F_65 ( V_98 ) ;
F_66 () ;
}
return 0 ;
}
static int F_68 ( void * V_3 )
{
struct V_4 * V_4 = V_3 ;
while ( ! F_64 () ) {
if ( ! F_47 ( V_4 ) )
continue;
F_65 ( V_98 ) ;
F_66 () ;
}
return 0 ;
}
static void F_69 ( struct V_4 * V_4 )
{
V_4 -> V_6 . V_84 = 1 ;
F_46 ( L_9 ) ;
}
void F_70 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_6 -> V_99 && ! V_6 -> V_84 )
F_69 ( V_4 ) ;
F_49 ( V_4 ) ;
}
static void F_71 ( struct V_4 * V_4 , int V_100 )
{
V_4 -> V_6 . V_84 = 0 ;
F_46 ( L_10 ) ;
}
void F_72 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_6 -> V_84 && ! V_6 -> V_101 )
F_71 ( V_4 , 0 ) ;
}
void F_73 ( struct V_4 * V_4 , int * V_99 ,
int * V_84 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
F_6 ( & V_6 -> V_38 ) ;
* V_99 = V_6 -> V_99 ;
* V_84 = V_6 -> V_84 ;
F_8 ( & V_6 -> V_38 ) ;
}
int F_74 ( struct V_4 * V_4 , int V_102 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_102 < 0 || V_102 > 1 )
return - V_103 ;
F_6 ( & V_6 -> V_38 ) ;
V_6 -> V_101 = V_102 ;
if ( V_102 )
V_6 -> V_99 = 1 ;
else
V_6 -> V_99 = 0 ;
F_8 ( & V_6 -> V_38 ) ;
F_70 ( V_4 ) ;
return 0 ;
}
int F_75 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_25 ;
V_6 -> V_94 = F_76 ( F_63 , V_4 , L_11 ) ;
if ( F_77 ( V_6 -> V_94 ) ) {
F_27 ( L_12 ) ;
return F_78 ( V_6 -> V_94 ) ;
}
V_6 -> V_19 = F_76 ( F_67 , V_4 ,
L_13 ) ;
if ( F_77 ( V_6 -> V_19 ) ) {
F_27 ( L_14 ) ;
V_25 = F_78 ( V_6 -> V_19 ) ;
goto V_104;
}
V_6 -> V_75 = F_76 ( F_68 , V_4 ,
L_15 ) ;
if ( F_77 ( V_6 -> V_75 ) ) {
F_27 ( L_16 ) ;
V_25 = F_78 ( V_6 -> V_75 ) ;
goto V_105;
}
F_79 ( & V_6 -> V_95 , F_62 , ( unsigned long ) V_4 ) ;
F_60 ( & V_6 -> V_95 , V_96 + F_61 ( V_97 ) ) ;
V_6 -> V_84 = 0 ;
V_6 -> V_101 = 0 ;
V_6 -> V_99 = 1 ;
V_6 -> V_11 = 0 ;
F_80 ( & V_6 -> V_71 , 0 ) ;
V_6 -> V_70 = F_81 ( L_17 ,
V_106 | V_107 , V_108 ) ;
if ( ! V_6 -> V_70 ) {
F_27 ( L_18 ) ;
V_25 = - V_27 ;
goto V_109;
}
V_6 -> V_72 = F_81 ( L_19 ,
V_106 | V_107 , 1 ) ;
if ( ! V_6 -> V_72 ) {
F_27 ( L_20 ) ;
V_25 = - V_27 ;
goto V_110;
}
F_82 ( & V_6 -> V_38 ) ;
F_82 ( & V_6 -> V_9 ) ;
F_82 ( & V_6 -> V_73 ) ;
F_83 ( & V_6 -> V_49 , 128 ) ;
F_84 ( & V_6 -> V_8 ) ;
F_84 ( & V_6 -> V_74 ) ;
return 0 ;
V_110:
F_85 ( V_6 -> V_70 ) ;
V_109:
F_86 ( V_6 -> V_75 ) ;
V_105:
F_86 ( V_6 -> V_19 ) ;
V_104:
F_86 ( V_6 -> V_94 ) ;
return V_25 ;
}
void F_87 ( struct V_4 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
F_88 ( V_6 -> V_72 ) ;
F_88 ( V_6 -> V_70 ) ;
F_89 ( & V_6 -> V_95 ) ;
F_71 ( V_4 , 1 ) ;
if ( V_6 -> V_94 )
F_86 ( V_6 -> V_94 ) ;
if ( V_6 -> V_72 )
F_85 ( V_6 -> V_72 ) ;
if ( V_6 -> V_70 )
F_85 ( V_6 -> V_70 ) ;
if ( V_6 -> V_19 )
F_86 ( V_6 -> V_19 ) ;
if ( V_6 -> V_75 )
F_86 ( V_6 -> V_75 ) ;
}
