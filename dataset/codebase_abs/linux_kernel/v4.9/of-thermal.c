static int F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_7 -> V_8 )
return - V_9 ;
return V_5 -> V_7 -> V_8 ( V_5 -> V_10 , V_3 ) ;
}
static int F_2 ( struct V_1 * V_2 ,
int V_11 , int V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_7 || ! V_5 -> V_7 -> V_13 )
return - V_9 ;
return V_5 -> V_7 -> V_13 ( V_5 -> V_10 , V_11 , V_12 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || F_4 ( V_5 ) )
return - V_14 ;
return V_5 -> V_15 ;
}
bool F_5 ( struct V_1 * V_2 , int V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || V_16 >= V_5 -> V_15 || V_16 < 0 )
return false ;
return true ;
}
const struct V_17 *
F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return NULL ;
return V_5 -> V_18 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return V_5 -> V_7 -> V_19 ( V_5 -> V_10 , V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_16 ,
enum V_20 * V_21 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_7 -> V_22 )
return - V_9 ;
return V_5 -> V_7 -> V_22 ( V_5 -> V_10 , V_16 , V_21 ) ;
}
static int F_9 ( struct V_1 * V_23 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_23 -> V_6 ;
int V_26 ;
if ( ! V_5 || F_4 ( V_5 ) )
return - V_14 ;
for ( V_26 = 0 ; V_26 < V_5 -> V_27 ; V_26 ++ ) {
struct V_28 * V_29 = V_5 -> V_30 + V_26 ;
if ( V_29 -> V_31 == V_25 -> V_32 ) {
int V_33 ;
V_33 = F_10 ( V_23 ,
V_29 -> V_34 , V_25 ,
V_29 -> V_35 ,
V_29 -> V_36 ,
V_29 -> V_37 ) ;
if ( V_33 )
return V_33 ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_23 ,
struct V_24 * V_25 )
{
struct V_4 * V_5 = V_23 -> V_6 ;
int V_26 ;
if ( ! V_5 || F_4 ( V_5 ) )
return - V_14 ;
for ( V_26 = 0 ; V_26 < V_5 -> V_27 ; V_26 ++ ) {
struct V_28 * V_29 = V_5 -> V_30 + V_26 ;
if ( V_29 -> V_31 == V_25 -> V_32 ) {
int V_33 ;
V_33 = F_12 ( V_23 ,
V_29 -> V_34 , V_25 ) ;
if ( V_33 )
return V_33 ;
}
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_38 * V_39 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_39 = V_5 -> V_39 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_38 V_39 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_15 ( & V_2 -> V_40 ) ;
if ( V_39 == V_41 )
V_2 -> V_42 = V_5 -> V_42 ;
else
V_2 -> V_42 = 0 ;
F_16 ( & V_2 -> V_40 ) ;
V_5 -> V_39 = V_39 ;
F_17 ( V_2 , V_43 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_16 ,
enum V_44 * type )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_16 >= V_5 -> V_15 || V_16 < 0 )
return - V_45 ;
* type = V_5 -> V_18 [ V_16 ] . type ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_16 ,
int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_16 >= V_5 -> V_15 || V_16 < 0 )
return - V_45 ;
* V_3 = V_5 -> V_18 [ V_16 ] . V_46 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_16 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_16 >= V_5 -> V_15 || V_16 < 0 )
return - V_45 ;
if ( V_5 -> V_7 -> V_47 ) {
int V_33 ;
V_33 = V_5 -> V_7 -> V_47 ( V_5 -> V_10 , V_16 , V_3 ) ;
if ( V_33 )
return V_33 ;
}
V_5 -> V_18 [ V_16 ] . V_46 = V_3 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_16 ,
int * V_48 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_16 >= V_5 -> V_15 || V_16 < 0 )
return - V_45 ;
* V_48 = V_5 -> V_18 [ V_16 ] . V_49 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_16 ,
int V_48 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_16 >= V_5 -> V_15 || V_16 < 0 )
return - V_45 ;
V_5 -> V_18 [ V_16 ] . V_49 = V_48 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_5 -> V_15 ; V_26 ++ )
if ( V_5 -> V_18 [ V_26 ] . type == V_50 ) {
* V_3 = V_5 -> V_18 [ V_26 ] . V_46 ;
return 0 ;
}
return - V_9 ;
}
static struct V_1 *
F_24 ( struct V_51 * V_52 ,
struct V_51 * V_53 , void * V_5 ,
const struct V_54 * V_7 )
{
struct V_1 * V_55 ;
struct V_4 * V_2 ;
V_55 = F_25 ( V_52 -> V_56 ) ;
if ( F_4 ( V_55 ) )
return F_26 ( - V_57 ) ;
V_2 = V_55 -> V_6 ;
if ( ! V_7 )
return F_26 ( - V_9 ) ;
F_15 ( & V_55 -> V_40 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = V_5 ;
V_55 -> V_7 -> V_8 = F_1 ;
V_55 -> V_7 -> V_22 = F_8 ;
if ( V_7 -> V_13 )
V_55 -> V_7 -> V_13 = F_2 ;
if ( V_7 -> V_19 )
V_55 -> V_7 -> V_19 = F_7 ;
F_16 ( & V_55 -> V_40 ) ;
return V_55 ;
}
struct V_1 *
F_27 ( struct V_58 * V_59 , int V_60 , void * V_5 ,
const struct V_54 * V_7 )
{
struct V_51 * V_32 , * V_61 , * V_62 ;
struct V_1 * V_55 = F_26 ( - V_14 ) ;
V_32 = F_28 ( NULL , L_1 ) ;
if ( ! V_32 )
return F_26 ( - V_14 ) ;
if ( ! V_59 || ! V_59 -> V_63 ) {
F_29 ( V_32 ) ;
return F_26 ( - V_9 ) ;
}
V_62 = F_30 ( V_59 -> V_63 ) ;
F_31 (np, child) {
struct V_64 V_65 ;
int V_33 , V_66 ;
V_33 = F_32 ( V_61 , L_2 ,
L_3 ,
0 , & V_65 ) ;
if ( V_33 )
continue;
if ( V_65 . V_67 >= 1 ) {
V_66 = V_65 . args [ 0 ] ;
F_33 ( V_65 . V_67 > 1 ,
L_4 ,
V_65 . V_32 -> V_56 , V_65 . V_67 ) ;
} else {
V_66 = 0 ;
}
if ( V_65 . V_32 == V_62 && V_66 == V_60 ) {
V_55 = F_24 ( V_61 , V_62 ,
V_5 , V_7 ) ;
if ( ! F_4 ( V_55 ) )
V_55 -> V_7 -> V_68 ( V_55 , V_41 ) ;
F_29 ( V_65 . V_32 ) ;
F_29 ( V_61 ) ;
goto exit;
}
F_29 ( V_65 . V_32 ) ;
}
exit:
F_29 ( V_62 ) ;
F_29 ( V_32 ) ;
return V_55 ;
}
void F_34 ( struct V_58 * V_59 ,
struct V_1 * V_55 )
{
struct V_4 * V_2 ;
if ( ! V_59 || ! V_55 || ! V_55 -> V_6 )
return;
V_2 = V_55 -> V_6 ;
if ( ! V_2 )
return;
F_15 ( & V_55 -> V_40 ) ;
V_55 -> V_7 -> V_8 = NULL ;
V_55 -> V_7 -> V_22 = NULL ;
V_55 -> V_7 -> V_19 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_10 = NULL ;
F_16 ( & V_55 -> V_40 ) ;
}
static void F_35 ( struct V_58 * V_59 , void * V_69 )
{
F_34 ( V_59 ,
* (struct V_1 * * ) V_69 ) ;
}
static int F_36 ( struct V_58 * V_59 , void * V_69 ,
void * V_5 )
{
struct V_1 * * V_70 = V_69 ;
if ( F_37 ( ! V_70 || ! * V_70 ) )
return 0 ;
return * V_70 == V_5 ;
}
struct V_1 * F_38 (
struct V_58 * V_59 , int V_60 ,
void * V_5 , const struct V_54 * V_7 )
{
struct V_1 * * V_71 , * V_55 ;
V_71 = F_39 ( F_35 , sizeof( * V_71 ) ,
V_72 ) ;
if ( ! V_71 )
return F_26 ( - V_73 ) ;
V_55 = F_27 ( V_59 , V_60 , V_5 , V_7 ) ;
if ( F_4 ( V_55 ) ) {
F_40 ( V_71 ) ;
return V_55 ;
}
* V_71 = V_55 ;
F_41 ( V_59 , V_71 ) ;
return V_55 ;
}
void F_42 ( struct V_58 * V_59 ,
struct V_1 * V_55 )
{
F_37 ( F_43 ( V_59 , F_35 ,
F_36 , V_55 ) ) ;
}
static int F_44 ( struct V_51 * V_32 ,
struct V_28 * V_74 ,
struct V_17 * V_18 ,
int V_15 )
{
struct V_64 V_75 ;
struct V_51 * V_16 ;
int V_33 , V_26 ;
T_1 V_76 ;
V_74 -> V_37 = V_77 ;
V_33 = F_45 ( V_32 , L_5 , & V_76 ) ;
if ( V_33 == 0 )
V_74 -> V_37 = V_76 ;
V_16 = F_46 ( V_32 , L_6 , 0 ) ;
if ( ! V_16 ) {
F_47 ( L_7 ) ;
return - V_14 ;
}
for ( V_26 = 0 ; V_26 < V_15 ; V_26 ++ )
if ( V_16 == V_18 [ V_26 ] . V_32 ) {
V_74 -> V_34 = V_26 ;
break;
}
if ( V_26 == V_15 ) {
V_33 = - V_14 ;
goto V_78;
}
V_33 = F_32 ( V_32 , L_8 , L_9 ,
0 , & V_75 ) ;
if ( V_33 < 0 ) {
F_47 ( L_10 ) ;
goto V_78;
}
V_74 -> V_31 = V_75 . V_32 ;
if ( V_75 . V_67 >= 2 ) {
V_74 -> V_36 = V_75 . args [ 0 ] ;
V_74 -> V_35 = V_75 . args [ 1 ] ;
} else {
F_47 ( L_11 ) ;
}
V_78:
F_29 ( V_16 ) ;
return V_33 ;
}
static int F_48 ( struct V_51 * V_32 ,
enum V_44 * type )
{
const char * V_79 ;
int V_80 , V_26 ;
V_80 = F_49 ( V_32 , L_12 , & V_79 ) ;
if ( V_80 < 0 )
return V_80 ;
for ( V_26 = 0 ; V_26 < F_50 ( V_81 ) ; V_26 ++ )
if ( ! strcasecmp ( V_79 , V_81 [ V_26 ] ) ) {
* type = V_26 ;
return 0 ;
}
return - V_14 ;
}
static int F_51 ( struct V_51 * V_32 ,
struct V_17 * V_16 )
{
int V_76 ;
int V_33 ;
V_33 = F_45 ( V_32 , L_13 , & V_76 ) ;
if ( V_33 < 0 ) {
F_47 ( L_14 ) ;
return V_33 ;
}
V_16 -> V_46 = V_76 ;
V_33 = F_45 ( V_32 , L_15 , & V_76 ) ;
if ( V_33 < 0 ) {
F_47 ( L_16 ) ;
return V_33 ;
}
V_16 -> V_49 = V_76 ;
V_33 = F_48 ( V_32 , & V_16 -> type ) ;
if ( V_33 < 0 ) {
F_47 ( L_17 ) ;
return V_33 ;
}
V_16 -> V_32 = V_32 ;
F_30 ( V_32 ) ;
return 0 ;
}
static struct V_4
T_2 * F_52 ( struct V_51 * V_32 )
{
struct V_51 * V_61 = NULL , * V_82 ;
struct V_4 * V_2 ;
int V_33 , V_26 ;
T_1 V_76 , V_83 [ 2 ] ;
if ( ! V_32 ) {
F_47 ( L_18 ) ;
return F_26 ( - V_9 ) ;
}
V_2 = F_53 ( sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 )
return F_26 ( - V_73 ) ;
V_33 = F_45 ( V_32 , L_19 , & V_76 ) ;
if ( V_33 < 0 ) {
F_47 ( L_20 ) ;
goto V_84;
}
V_2 -> V_85 = V_76 ;
V_33 = F_45 ( V_32 , L_21 , & V_76 ) ;
if ( V_33 < 0 ) {
F_47 ( L_22 ) ;
goto V_84;
}
V_2 -> V_42 = V_76 ;
V_33 = F_54 ( V_32 , L_23 , V_83 , 2 ) ;
if ( V_33 == 0 ) {
V_2 -> V_86 = V_83 [ 0 ] ;
V_2 -> V_87 = V_83 [ 1 ] ;
} else {
V_2 -> V_86 = 1 ;
V_2 -> V_87 = 0 ;
}
V_61 = F_55 ( V_32 , L_24 ) ;
if ( ! V_61 )
goto V_88;
V_2 -> V_15 = F_56 ( V_61 ) ;
if ( V_2 -> V_15 == 0 )
goto V_88;
V_2 -> V_18 = F_53 ( V_2 -> V_15 * sizeof( * V_2 -> V_18 ) , V_72 ) ;
if ( ! V_2 -> V_18 ) {
V_33 = - V_73 ;
goto V_84;
}
V_26 = 0 ;
F_57 (child, gchild) {
V_33 = F_51 ( V_82 , & V_2 -> V_18 [ V_26 ++ ] ) ;
if ( V_33 )
goto V_89;
}
F_29 ( V_61 ) ;
V_61 = F_55 ( V_32 , L_25 ) ;
if ( ! V_61 )
goto V_88;
V_2 -> V_27 = F_56 ( V_61 ) ;
if ( V_2 -> V_27 == 0 )
goto V_88;
V_2 -> V_30 = F_53 ( V_2 -> V_27 * sizeof( * V_2 -> V_30 ) , V_72 ) ;
if ( ! V_2 -> V_30 ) {
V_33 = - V_73 ;
goto V_89;
}
V_26 = 0 ;
F_57 (child, gchild) {
V_33 = F_44 ( V_82 , & V_2 -> V_30 [ V_26 ++ ] ,
V_2 -> V_18 , V_2 -> V_15 ) ;
if ( V_33 )
goto V_90;
}
V_88:
F_29 ( V_61 ) ;
V_2 -> V_39 = V_91 ;
return V_2 ;
V_90:
for ( V_26 = V_26 - 1 ; V_26 >= 0 ; V_26 -- )
F_29 ( V_2 -> V_30 [ V_26 ] . V_31 ) ;
F_58 ( V_2 -> V_30 ) ;
V_89:
for ( V_26 = 0 ; V_26 < V_2 -> V_15 ; V_26 ++ )
F_29 ( V_2 -> V_18 [ V_26 ] . V_32 ) ;
F_58 ( V_2 -> V_18 ) ;
F_29 ( V_82 ) ;
V_84:
F_58 ( V_2 ) ;
F_29 ( V_61 ) ;
return F_26 ( V_33 ) ;
}
static inline void F_59 ( struct V_4 * V_2 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_27 ; V_26 ++ )
F_29 ( V_2 -> V_30 [ V_26 ] . V_31 ) ;
F_58 ( V_2 -> V_30 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_15 ; V_26 ++ )
F_29 ( V_2 -> V_18 [ V_26 ] . V_32 ) ;
F_58 ( V_2 -> V_18 ) ;
F_58 ( V_2 ) ;
}
int T_2 F_60 ( void )
{
struct V_51 * V_32 , * V_61 ;
struct V_4 * V_2 ;
struct V_92 * V_7 ;
V_32 = F_28 ( NULL , L_1 ) ;
if ( ! V_32 ) {
F_61 ( L_26 ) ;
return 0 ;
}
F_31 (np, child) {
struct V_1 * V_52 ;
struct V_93 * V_94 ;
int V_26 , V_95 = 0 ;
T_1 V_76 ;
V_2 = F_52 ( V_61 ) ;
if ( F_4 ( V_2 ) ) {
F_47 ( L_27 ,
V_61 -> V_56 ,
F_62 ( V_2 ) ) ;
continue;
}
V_7 = F_63 ( & V_96 , sizeof( * V_7 ) , V_72 ) ;
if ( ! V_7 )
goto V_97;
V_94 = F_53 ( sizeof( * V_94 ) , V_72 ) ;
if ( ! V_94 ) {
F_58 ( V_7 ) ;
goto V_97;
}
V_94 -> V_98 = true ;
if ( ! F_45 ( V_61 , L_28 , & V_76 ) )
V_94 -> V_99 = V_76 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_15 ; V_26 ++ )
V_95 |= 1 << V_26 ;
V_94 -> V_86 = V_2 -> V_86 ;
V_94 -> V_87 = V_2 -> V_87 ;
V_52 = F_64 ( V_61 -> V_56 , V_2 -> V_15 ,
V_95 , V_2 ,
V_7 , V_94 ,
V_2 -> V_85 ,
V_2 -> V_42 ) ;
if ( F_4 ( V_52 ) ) {
F_47 ( L_29 , V_61 -> V_56 ,
F_62 ( V_52 ) ) ;
F_58 ( V_94 ) ;
F_58 ( V_7 ) ;
F_59 ( V_2 ) ;
}
}
F_29 ( V_32 ) ;
return 0 ;
V_97:
F_29 ( V_61 ) ;
F_29 ( V_32 ) ;
F_59 ( V_2 ) ;
F_65 () ;
return - V_73 ;
}
void F_65 ( void )
{
struct V_51 * V_32 , * V_61 ;
V_32 = F_28 ( NULL , L_1 ) ;
if ( ! V_32 ) {
F_61 ( L_26 ) ;
return;
}
F_31 (np, child) {
struct V_1 * V_52 ;
V_52 = F_25 ( V_61 -> V_56 ) ;
if ( F_4 ( V_52 ) )
continue;
F_66 ( V_52 ) ;
F_58 ( V_52 -> V_94 ) ;
F_58 ( V_52 -> V_7 ) ;
F_59 ( V_52 -> V_6 ) ;
}
F_29 ( V_32 ) ;
}
