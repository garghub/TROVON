static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 ) ;
}
static int F_3 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_1 * V_2 , * V_8 ;
F_4 ( V_9 ) ;
F_5 ( & V_7 -> V_10 ) ;
if ( F_6 ( & V_7 -> V_9 ) ) {
F_7 ( & V_7 -> V_10 ) ;
return 1 ;
}
F_8 (gc_rq, tgc_rq, &gc->w_list, list) {
F_9 ( & V_2 -> V_11 , & V_9 ) ;
V_7 -> V_12 -- ;
}
F_7 ( & V_7 -> V_10 ) ;
F_8 (gc_rq, tgc_rq, &w_list, list) {
F_10 ( V_5 , V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_13 , V_2 -> V_14 ,
V_2 -> line , V_15 ) ;
F_11 ( & V_2 -> line -> V_16 , V_17 ) ;
F_12 ( & V_2 -> V_11 ) ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static void F_13 ( struct V_6 * V_7 )
{
F_14 ( V_7 -> V_18 ) ;
}
static int F_15 ( struct V_5 * V_5 , struct V_19 * line ,
T_1 * V_4 , unsigned int V_13 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_1 * V_2 ;
void * V_3 ;
unsigned int V_14 ;
int V_24 = V_25 ;
V_3 = F_16 ( V_13 * V_23 -> V_26 , V_27 ) ;
if ( ! V_3 ) {
V_24 = V_28 ;
goto V_29;
}
if ( F_17 ( V_5 , V_4 , V_3 , V_13 ,
& V_14 , line ) ) {
V_24 = V_28 ;
goto V_30;
}
if ( ! V_14 )
goto V_30;
V_2 = F_16 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_2 ) {
V_24 = V_28 ;
goto V_30;
}
V_2 -> line = line ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_14 = V_14 ;
F_18 ( & line -> V_16 ) ;
V_31:
F_5 ( & V_7 -> V_10 ) ;
if ( V_7 -> V_12 > 256 ) {
F_7 ( & V_7 -> V_10 ) ;
F_19 ( 256 , 1024 ) ;
goto V_31;
}
V_7 -> V_12 ++ ;
F_20 ( & V_2 -> V_11 , & V_7 -> V_9 ) ;
F_7 ( & V_7 -> V_10 ) ;
F_13 ( & V_5 -> V_7 ) ;
return V_25 ;
V_30:
F_2 ( V_3 ) ;
V_29:
F_2 ( V_4 ) ;
return V_24 ;
}
static void F_21 ( struct V_5 * V_5 , struct V_19 * line )
{
struct V_32 * V_33 = & V_5 -> V_33 ;
struct V_34 * V_35 ;
F_5 ( & line -> V_36 ) ;
F_22 ( line -> V_37 != V_38 ) ;
line -> V_37 = V_39 ;
V_35 = F_23 ( V_5 , line ) ;
F_7 ( & line -> V_36 ) ;
if ( V_35 ) {
F_5 ( & V_33 -> V_40 ) ;
F_20 ( & line -> V_11 , V_35 ) ;
F_7 ( & V_33 -> V_40 ) ;
}
}
static void F_24 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_25 ( V_42 , struct V_43 ,
V_45 ) ;
struct V_5 * V_5 = V_44 -> V_5 ;
struct V_32 * V_33 = & V_5 -> V_33 ;
struct V_19 * line = V_44 -> line ;
struct V_46 * V_47 = & V_5 -> V_47 ;
T_2 * V_4 = V_44 -> V_48 ;
T_1 * V_49 ;
int V_50 ;
int V_51 , V_52 ;
int V_53 = 1 ;
F_26 ( L_1 , line -> V_54 ) ;
F_5 ( & line -> V_36 ) ;
V_50 = line -> V_55 ;
if ( ! V_50 ) {
F_7 ( & line -> V_36 ) ;
goto V_56;
}
F_7 ( & line -> V_36 ) ;
if ( V_50 < 0 ) {
F_27 ( L_2 , line -> V_54 ) ;
V_53 = 0 ;
F_21 ( V_5 , line ) ;
goto V_56;
}
V_52 = - 1 ;
V_57:
V_49 = F_28 ( V_5 -> V_58 , sizeof( T_1 ) , V_27 ) ;
if ( ! V_49 ) {
V_53 = 0 ;
F_21 ( V_5 , line ) ;
goto V_56;
}
V_51 = 0 ;
do {
V_52 = F_29 ( line -> V_59 , V_47 -> V_60 ,
V_52 + 1 ) ;
if ( V_52 > line -> V_61 )
break;
V_49 [ V_51 ++ ] = F_30 ( V_4 [ V_52 ] ) ;
} while ( V_51 < V_5 -> V_58 );
if ( F_31 ( ! V_51 ) ) {
F_2 ( V_49 ) ;
goto V_56;
}
if ( F_15 ( V_5 , line , V_49 , V_51 ) ) {
F_27 ( L_3 ,
line -> V_54 , line -> V_55 ,
V_51 , V_51 ) ;
V_53 = 0 ;
F_21 ( V_5 , line ) ;
goto V_56;
}
V_50 -= V_51 ;
if ( V_50 > 0 )
goto V_57;
V_56:
F_32 ( line -> V_62 , V_33 -> V_63 ) ;
F_33 ( V_44 , V_5 -> V_64 ) ;
F_34 ( & V_5 -> V_7 . V_65 ) ;
if ( V_53 )
F_11 ( & line -> V_16 , V_17 ) ;
}
static int F_35 ( struct V_5 * V_5 , struct V_19 * line )
{
struct V_32 * V_33 = & V_5 -> V_33 ;
struct V_46 * V_47 = & V_5 -> V_47 ;
struct V_43 * V_44 ;
T_2 * V_4 ;
int V_24 ;
V_44 = F_36 ( V_5 -> V_64 , V_27 ) ;
line -> V_62 = F_37 ( V_47 -> V_66 , V_33 -> V_63 ,
V_27 ) ;
if ( ! line -> V_62 ) {
F_27 ( L_4 ) ;
goto V_67;
}
V_24 = F_38 ( V_5 , line ) ;
if ( V_24 ) {
F_27 ( L_5 , line -> V_54 , V_24 ) ;
goto V_68;
}
V_4 = F_39 ( V_5 , line -> V_62 ) ;
if ( ! V_4 ) {
F_27 ( L_6 , line -> V_54 ) ;
goto V_68;
}
V_44 -> V_5 = V_5 ;
V_44 -> line = line ;
V_44 -> V_48 = V_4 ;
F_40 ( & V_44 -> V_45 , F_24 ) ;
F_41 ( V_5 -> V_7 . V_69 , & V_44 -> V_45 ) ;
return 0 ;
V_68:
F_32 ( line -> V_62 , V_33 -> V_63 ) ;
V_67:
F_33 ( V_44 , V_5 -> V_64 ) ;
F_21 ( V_5 , line ) ;
return 1 ;
}
static void F_42 ( struct V_5 * V_5 , struct V_34 * V_49 )
{
struct V_19 * line , * V_70 ;
F_8 (line, tline, gc_list, list) {
if ( F_35 ( V_5 , line ) )
F_27 ( L_7 , line -> V_54 ) ;
F_12 ( & line -> V_11 ) ;
}
}
static void F_43 ( struct V_5 * V_5 )
{
struct V_32 * V_33 = & V_5 -> V_33 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_19 * line , * V_70 ;
unsigned int V_71 , V_72 ;
struct V_34 * V_73 ;
int V_74 , V_75 = 0 ;
int V_76 = 0 ;
int V_65 = F_44 ( & V_7 -> V_65 ) ;
F_4 ( V_49 ) ;
F_5 ( & V_33 -> V_40 ) ;
F_8 (line, tline, &l_mg->gc_full_list, list) {
F_5 ( & line -> V_36 ) ;
F_22 ( line -> V_37 != V_39 ) ;
line -> V_37 = V_38 ;
F_7 ( & line -> V_36 ) ;
F_12 ( & line -> V_11 ) ;
F_11 ( & line -> V_16 , V_17 ) ;
}
F_7 ( & V_33 -> V_40 ) ;
V_72 = F_45 ( & V_5 -> V_77 ) ;
V_71 = F_46 ( & V_5 -> V_77 ) ;
V_74 = ( V_72 > V_71 || V_7 -> V_78 ) ;
V_79:
V_73 = V_33 -> V_80 [ V_75 ++ ] ;
F_5 ( & V_33 -> V_40 ) ;
while ( V_74 && ! F_6 ( V_73 ) ) {
if ( ! V_74 || V_65 > V_7 -> V_81 ) {
F_7 ( & V_33 -> V_40 ) ;
F_42 ( V_5 , & V_49 ) ;
return;
}
line = F_47 ( V_73 , struct V_19 , V_11 ) ;
V_71 += F_44 ( & line -> V_82 ) ;
F_5 ( & line -> V_36 ) ;
F_22 ( line -> V_37 != V_39 ) ;
line -> V_37 = V_38 ;
F_9 ( & line -> V_11 , & V_49 ) ;
F_48 ( & V_7 -> V_65 ) ;
V_65 ++ ;
F_7 ( & line -> V_36 ) ;
V_76 = 1 ;
V_74 = ( V_72 > V_71 || V_7 -> V_78 ) ;
}
F_7 ( & V_33 -> V_40 ) ;
F_42 ( V_5 , & V_49 ) ;
if ( ! V_76 && V_5 -> V_77 . V_83 > V_75 &&
V_75 < V_84 )
goto V_79;
}
static void F_49 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
F_14 ( V_7 -> V_85 ) ;
F_13 ( V_7 ) ;
F_50 ( & V_7 -> V_86 , V_87 + F_51 ( V_88 ) ) ;
}
static void F_52 ( unsigned long V_3 )
{
struct V_5 * V_5 = (struct V_5 * ) V_3 ;
F_49 ( V_5 ) ;
}
static int F_53 ( void * V_3 )
{
struct V_5 * V_5 = V_3 ;
while ( ! F_54 () ) {
F_43 ( V_5 ) ;
F_55 ( V_89 ) ;
F_56 () ;
}
return 0 ;
}
static int F_57 ( void * V_3 )
{
struct V_5 * V_5 = V_3 ;
while ( ! F_54 () ) {
if ( ! F_3 ( V_5 ) )
continue;
F_55 ( V_89 ) ;
F_56 () ;
}
return 0 ;
}
static void F_58 ( struct V_5 * V_5 )
{
V_5 -> V_7 . V_90 = 1 ;
F_26 ( L_8 ) ;
}
int F_59 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
int V_24 ;
F_5 ( & V_7 -> V_36 ) ;
V_24 = V_7 -> V_90 ;
F_7 ( & V_7 -> V_36 ) ;
return V_24 ;
}
static void F_60 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
F_61 ( & V_7 -> V_36 ) ;
if ( V_7 -> V_91 && ! V_7 -> V_90 )
F_58 ( V_5 ) ;
}
void F_62 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
F_5 ( & V_7 -> V_36 ) ;
F_60 ( V_5 ) ;
F_7 ( & V_7 -> V_36 ) ;
}
static void F_63 ( struct V_5 * V_5 , int V_92 )
{
F_5 ( & V_5 -> V_7 . V_36 ) ;
V_5 -> V_7 . V_90 = 0 ;
F_7 ( & V_5 -> V_7 . V_36 ) ;
F_26 ( L_9 ) ;
}
void F_64 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
if ( V_7 -> V_90 && ! V_7 -> V_78 )
F_63 ( V_5 , 0 ) ;
}
void F_65 ( struct V_5 * V_5 , int * V_91 ,
int * V_90 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
F_5 ( & V_7 -> V_36 ) ;
* V_91 = V_7 -> V_91 ;
* V_90 = V_7 -> V_90 ;
F_7 ( & V_7 -> V_36 ) ;
}
void F_66 ( struct V_5 * V_5 , int V_93 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
int V_94 = 0 ;
F_5 ( & V_7 -> V_36 ) ;
if ( V_93 ) {
V_7 -> V_91 = 1 ;
V_94 = 64 ;
}
F_67 ( & V_5 -> V_77 , V_94 ) ;
V_7 -> V_78 = V_93 ;
F_60 ( V_5 ) ;
F_7 ( & V_7 -> V_36 ) ;
}
int F_68 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
int V_24 ;
V_7 -> V_85 = F_69 ( F_53 , V_5 , L_10 ) ;
if ( F_70 ( V_7 -> V_85 ) ) {
F_27 ( L_11 ) ;
return F_71 ( V_7 -> V_85 ) ;
}
V_7 -> V_18 = F_69 ( F_57 , V_5 ,
L_12 ) ;
if ( F_70 ( V_7 -> V_18 ) ) {
F_27 ( L_13 ) ;
V_24 = F_71 ( V_7 -> V_18 ) ;
goto V_95;
}
F_72 ( & V_7 -> V_86 , F_52 , ( unsigned long ) V_5 ) ;
F_50 ( & V_7 -> V_86 , V_87 + F_51 ( V_88 ) ) ;
V_7 -> V_90 = 0 ;
V_7 -> V_78 = 0 ;
V_7 -> V_91 = 1 ;
V_7 -> V_81 = 8 ;
V_7 -> V_12 = 0 ;
F_73 ( & V_7 -> V_65 , 0 ) ;
V_7 -> V_69 = F_74 ( L_14 ,
V_96 | V_97 , V_7 -> V_81 ) ;
if ( ! V_7 -> V_69 ) {
F_27 ( L_15 ) ;
V_24 = - V_98 ;
goto V_99;
}
F_75 ( & V_7 -> V_36 ) ;
F_75 ( & V_7 -> V_10 ) ;
F_76 ( & V_7 -> V_9 ) ;
return 0 ;
V_99:
F_77 ( V_7 -> V_18 ) ;
V_95:
F_77 ( V_7 -> V_85 ) ;
return V_24 ;
}
void F_78 ( struct V_5 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
F_79 ( V_7 -> V_69 ) ;
F_80 ( & V_7 -> V_86 ) ;
F_63 ( V_5 , 1 ) ;
if ( V_7 -> V_85 )
F_77 ( V_7 -> V_85 ) ;
if ( V_5 -> V_7 . V_69 )
F_81 ( V_5 -> V_7 . V_69 ) ;
if ( V_7 -> V_18 )
F_77 ( V_7 -> V_18 ) ;
}
