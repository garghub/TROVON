static int F_1 ( struct V_1 * V_2 ,
int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_7 -> V_8 )
return - V_9 ;
return V_5 -> V_7 -> V_8 ( V_5 -> V_10 , V_3 ) ;
}
int F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || F_3 ( V_5 ) )
return - V_11 ;
return V_5 -> V_12 ;
}
bool F_4 ( struct V_1 * V_2 , int V_13 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 || V_13 >= V_5 -> V_12 || V_13 < 0 )
return false ;
return true ;
}
const struct V_14 *
F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return NULL ;
return V_5 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_7 || ! V_5 -> V_7 -> V_16 )
return - V_9 ;
return V_5 -> V_7 -> V_16 ( V_5 -> V_10 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_13 ,
enum V_17 * V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
long V_19 ;
int V_20 ;
if ( ! V_5 -> V_7 -> V_21 )
return - V_9 ;
V_20 = V_5 -> V_7 -> V_21 ( V_5 -> V_10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
if ( V_19 > 0 )
* V_18 = V_22 ;
else if ( V_19 < 0 )
* V_18 = V_23 ;
else
* V_18 = V_24 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = V_25 -> V_6 ;
int V_28 ;
if ( ! V_5 || F_3 ( V_5 ) )
return - V_11 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_29 ; V_28 ++ ) {
struct V_30 * V_31 = V_5 -> V_32 + V_28 ;
if ( V_31 -> V_33 == V_27 -> V_34 ) {
int V_35 ;
V_35 = F_9 ( V_25 ,
V_31 -> V_36 , V_27 ,
V_31 -> V_37 ,
V_31 -> V_38 ,
V_31 -> V_39 ) ;
if ( V_35 )
return V_35 ;
}
}
return 0 ;
}
static int F_10 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = V_25 -> V_6 ;
int V_28 ;
if ( ! V_5 || F_3 ( V_5 ) )
return - V_11 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_29 ; V_28 ++ ) {
struct V_30 * V_31 = V_5 -> V_32 + V_28 ;
if ( V_31 -> V_33 == V_27 -> V_34 ) {
int V_35 ;
V_35 = F_11 ( V_25 ,
V_31 -> V_36 , V_27 ) ;
if ( V_35 )
return V_35 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_40 * V_41 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_41 = V_5 -> V_41 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_40 V_41 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_14 ( & V_2 -> V_42 ) ;
if ( V_41 == V_43 )
V_2 -> V_44 = V_5 -> V_44 ;
else
V_2 -> V_44 = 0 ;
F_15 ( & V_2 -> V_42 ) ;
V_5 -> V_41 = V_41 ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_13 ,
enum V_45 * type )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_46 ;
* type = V_5 -> V_15 [ V_13 ] . type ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_13 ,
int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_46 ;
* V_3 = V_5 -> V_15 [ V_13 ] . V_47 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_13 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_46 ;
if ( V_5 -> V_7 -> V_48 ) {
int V_35 ;
V_35 = V_5 -> V_7 -> V_48 ( V_5 -> V_10 , V_13 , V_3 ) ;
if ( V_35 )
return V_35 ;
}
V_5 -> V_15 [ V_13 ] . V_47 = V_3 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_13 ,
int * V_49 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_46 ;
* V_49 = V_5 -> V_15 [ V_13 ] . V_50 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_13 ,
int V_49 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_46 ;
V_5 -> V_15 [ V_13 ] . V_50 = V_49 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_12 ; V_28 ++ )
if ( V_5 -> V_15 [ V_28 ] . type == V_51 ) {
* V_3 = V_5 -> V_15 [ V_28 ] . V_47 ;
return 0 ;
}
return - V_9 ;
}
static struct V_1 *
F_23 ( struct V_52 * V_53 ,
struct V_52 * V_54 , void * V_5 ,
const struct V_55 * V_7 )
{
struct V_1 * V_56 ;
struct V_4 * V_2 ;
V_56 = F_24 ( V_53 -> V_57 ) ;
if ( F_3 ( V_56 ) )
return F_25 ( - V_58 ) ;
V_2 = V_56 -> V_6 ;
if ( ! V_7 )
return F_25 ( - V_9 ) ;
F_14 ( & V_56 -> V_42 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = V_5 ;
V_56 -> V_7 -> V_8 = F_1 ;
V_56 -> V_7 -> V_21 = F_7 ;
V_56 -> V_7 -> V_16 = F_6 ;
F_15 ( & V_56 -> V_42 ) ;
return V_56 ;
}
struct V_1 *
F_26 ( struct V_59 * V_60 , int V_61 , void * V_5 ,
const struct V_55 * V_7 )
{
struct V_52 * V_34 , * V_62 , * V_63 ;
struct V_1 * V_56 = F_25 ( - V_11 ) ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 )
return F_25 ( - V_11 ) ;
if ( ! V_60 || ! V_60 -> V_64 ) {
F_28 ( V_34 ) ;
return F_25 ( - V_9 ) ;
}
V_63 = F_29 ( V_60 -> V_64 ) ;
F_30 (np, child) {
struct V_65 V_66 ;
int V_35 , V_67 ;
V_35 = F_31 ( V_62 , L_2 ,
L_3 ,
0 , & V_66 ) ;
if ( V_35 )
continue;
if ( V_66 . V_68 >= 1 ) {
V_67 = V_66 . args [ 0 ] ;
F_32 ( V_66 . V_68 > 1 ,
L_4 ,
V_66 . V_34 -> V_57 , V_66 . V_68 ) ;
} else {
V_67 = 0 ;
}
if ( V_66 . V_34 == V_63 && V_67 == V_61 ) {
V_56 = F_23 ( V_62 , V_63 ,
V_5 , V_7 ) ;
if ( ! F_3 ( V_56 ) )
V_56 -> V_7 -> V_69 ( V_56 , V_43 ) ;
F_28 ( V_66 . V_34 ) ;
F_28 ( V_62 ) ;
goto exit;
}
F_28 ( V_66 . V_34 ) ;
}
exit:
F_28 ( V_63 ) ;
F_28 ( V_34 ) ;
return V_56 ;
}
void F_33 ( struct V_59 * V_60 ,
struct V_1 * V_56 )
{
struct V_4 * V_2 ;
if ( ! V_60 || ! V_56 || ! V_56 -> V_6 )
return;
V_2 = V_56 -> V_6 ;
if ( ! V_2 )
return;
F_14 ( & V_56 -> V_42 ) ;
V_56 -> V_7 -> V_8 = NULL ;
V_56 -> V_7 -> V_21 = NULL ;
V_56 -> V_7 -> V_16 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_10 = NULL ;
F_15 ( & V_56 -> V_42 ) ;
}
static void F_34 ( struct V_59 * V_60 , void * V_70 )
{
F_33 ( V_60 ,
* (struct V_1 * * ) V_70 ) ;
}
static int F_35 ( struct V_59 * V_60 , void * V_70 ,
void * V_5 )
{
struct V_1 * * V_20 = V_70 ;
if ( F_36 ( ! V_20 || ! * V_20 ) )
return 0 ;
return * V_20 == V_5 ;
}
struct V_1 * F_37 (
struct V_59 * V_60 , int V_61 ,
void * V_5 , const struct V_55 * V_7 )
{
struct V_1 * * V_71 , * V_56 ;
V_71 = F_38 ( F_34 , sizeof( * V_71 ) ,
V_72 ) ;
if ( ! V_71 )
return F_25 ( - V_73 ) ;
V_56 = F_26 ( V_60 , V_61 , V_5 , V_7 ) ;
if ( F_3 ( V_56 ) ) {
F_39 ( V_71 ) ;
return V_56 ;
}
* V_71 = V_56 ;
F_40 ( V_60 , V_71 ) ;
return V_56 ;
}
void F_41 ( struct V_59 * V_60 ,
struct V_1 * V_56 )
{
F_36 ( F_42 ( V_60 , F_34 ,
F_35 , V_56 ) ) ;
}
static int F_43 ( struct V_52 * V_34 ,
struct V_30 * V_74 ,
struct V_14 * V_15 ,
int V_12 )
{
struct V_65 V_75 ;
struct V_52 * V_13 ;
int V_35 , V_28 ;
T_1 V_76 ;
V_74 -> V_39 = V_77 ;
V_35 = F_44 ( V_34 , L_5 , & V_76 ) ;
if ( V_35 == 0 )
V_74 -> V_39 = V_76 ;
V_13 = F_45 ( V_34 , L_6 , 0 ) ;
if ( ! V_13 ) {
F_46 ( L_7 ) ;
return - V_11 ;
}
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
if ( V_13 == V_15 [ V_28 ] . V_34 ) {
V_74 -> V_36 = V_28 ;
break;
}
if ( V_28 == V_12 ) {
V_35 = - V_11 ;
goto V_78;
}
V_35 = F_31 ( V_34 , L_8 , L_9 ,
0 , & V_75 ) ;
if ( V_35 < 0 ) {
F_46 ( L_10 ) ;
goto V_78;
}
V_74 -> V_33 = V_75 . V_34 ;
if ( V_75 . V_68 >= 2 ) {
V_74 -> V_38 = V_75 . args [ 0 ] ;
V_74 -> V_37 = V_75 . args [ 1 ] ;
} else {
F_46 ( L_11 ) ;
}
V_78:
F_28 ( V_13 ) ;
return V_35 ;
}
static int F_47 ( struct V_52 * V_34 ,
enum V_45 * type )
{
const char * V_79 ;
int V_80 , V_28 ;
V_80 = F_48 ( V_34 , L_12 , & V_79 ) ;
if ( V_80 < 0 )
return V_80 ;
for ( V_28 = 0 ; V_28 < F_49 ( V_81 ) ; V_28 ++ )
if ( ! strcasecmp ( V_79 , V_81 [ V_28 ] ) ) {
* type = V_28 ;
return 0 ;
}
return - V_11 ;
}
static int F_50 ( struct V_52 * V_34 ,
struct V_14 * V_13 )
{
int V_76 ;
int V_35 ;
V_35 = F_44 ( V_34 , L_13 , & V_76 ) ;
if ( V_35 < 0 ) {
F_46 ( L_14 ) ;
return V_35 ;
}
V_13 -> V_47 = V_76 ;
V_35 = F_44 ( V_34 , L_15 , & V_76 ) ;
if ( V_35 < 0 ) {
F_46 ( L_16 ) ;
return V_35 ;
}
V_13 -> V_50 = V_76 ;
V_35 = F_47 ( V_34 , & V_13 -> type ) ;
if ( V_35 < 0 ) {
F_46 ( L_17 ) ;
return V_35 ;
}
V_13 -> V_34 = V_34 ;
F_29 ( V_34 ) ;
return 0 ;
}
static struct V_4
T_2 * F_51 ( struct V_52 * V_34 )
{
struct V_52 * V_62 = NULL , * V_82 ;
struct V_4 * V_2 ;
int V_35 , V_28 ;
T_1 V_76 , V_83 [ 2 ] ;
if ( ! V_34 ) {
F_46 ( L_18 ) ;
return F_25 ( - V_9 ) ;
}
V_2 = F_52 ( sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 )
return F_25 ( - V_73 ) ;
V_35 = F_44 ( V_34 , L_19 , & V_76 ) ;
if ( V_35 < 0 ) {
F_46 ( L_20 ) ;
goto V_84;
}
V_2 -> V_85 = V_76 ;
V_35 = F_44 ( V_34 , L_21 , & V_76 ) ;
if ( V_35 < 0 ) {
F_46 ( L_22 ) ;
goto V_84;
}
V_2 -> V_44 = V_76 ;
V_35 = F_53 ( V_34 , L_23 , V_83 , 2 ) ;
if ( V_35 == 0 ) {
V_2 -> V_86 = V_83 [ 0 ] ;
V_2 -> V_87 = V_83 [ 1 ] ;
} else {
V_2 -> V_86 = 1 ;
V_2 -> V_87 = 0 ;
}
V_62 = F_54 ( V_34 , L_24 ) ;
if ( ! V_62 )
goto V_88;
V_2 -> V_12 = F_55 ( V_62 ) ;
if ( V_2 -> V_12 == 0 )
goto V_88;
V_2 -> V_15 = F_52 ( V_2 -> V_12 * sizeof( * V_2 -> V_15 ) , V_72 ) ;
if ( ! V_2 -> V_15 ) {
V_35 = - V_73 ;
goto V_84;
}
V_28 = 0 ;
F_56 (child, gchild) {
V_35 = F_50 ( V_82 , & V_2 -> V_15 [ V_28 ++ ] ) ;
if ( V_35 )
goto V_89;
}
F_28 ( V_62 ) ;
V_62 = F_54 ( V_34 , L_25 ) ;
if ( ! V_62 )
goto V_88;
V_2 -> V_29 = F_55 ( V_62 ) ;
if ( V_2 -> V_29 == 0 )
goto V_88;
V_2 -> V_32 = F_52 ( V_2 -> V_29 * sizeof( * V_2 -> V_32 ) , V_72 ) ;
if ( ! V_2 -> V_32 ) {
V_35 = - V_73 ;
goto V_89;
}
V_28 = 0 ;
F_56 (child, gchild) {
V_35 = F_43 ( V_82 , & V_2 -> V_32 [ V_28 ++ ] ,
V_2 -> V_15 , V_2 -> V_12 ) ;
if ( V_35 )
goto V_90;
}
V_88:
F_28 ( V_62 ) ;
V_2 -> V_41 = V_91 ;
return V_2 ;
V_90:
for ( V_28 = V_28 - 1 ; V_28 >= 0 ; V_28 -- )
F_28 ( V_2 -> V_32 [ V_28 ] . V_33 ) ;
F_57 ( V_2 -> V_32 ) ;
V_89:
for ( V_28 = 0 ; V_28 < V_2 -> V_12 ; V_28 ++ )
F_28 ( V_2 -> V_15 [ V_28 ] . V_34 ) ;
F_57 ( V_2 -> V_15 ) ;
F_28 ( V_82 ) ;
V_84:
F_57 ( V_2 ) ;
F_28 ( V_62 ) ;
return F_25 ( V_35 ) ;
}
static inline void F_58 ( struct V_4 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ )
F_28 ( V_2 -> V_32 [ V_28 ] . V_33 ) ;
F_57 ( V_2 -> V_32 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_12 ; V_28 ++ )
F_28 ( V_2 -> V_15 [ V_28 ] . V_34 ) ;
F_57 ( V_2 -> V_15 ) ;
F_57 ( V_2 ) ;
}
int T_2 F_59 ( void )
{
struct V_52 * V_34 , * V_62 ;
struct V_4 * V_2 ;
struct V_92 * V_7 ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 ) {
F_60 ( L_26 ) ;
return 0 ;
}
F_30 (np, child) {
struct V_1 * V_53 ;
struct V_93 * V_94 ;
int V_28 , V_95 = 0 ;
T_1 V_76 ;
V_2 = F_51 ( V_62 ) ;
if ( F_3 ( V_2 ) ) {
F_46 ( L_27 ,
V_62 -> V_57 ,
F_61 ( V_2 ) ) ;
continue;
}
V_7 = F_62 ( & V_96 , sizeof( * V_7 ) , V_72 ) ;
if ( ! V_7 )
goto V_97;
V_94 = F_52 ( sizeof( * V_94 ) , V_72 ) ;
if ( ! V_94 ) {
F_57 ( V_7 ) ;
goto V_97;
}
V_94 -> V_98 = true ;
if ( ! F_44 ( V_62 , L_28 , & V_76 ) )
V_94 -> V_99 = V_76 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_12 ; V_28 ++ )
V_95 |= 1 << V_28 ;
V_94 -> V_86 = V_2 -> V_86 ;
V_94 -> V_87 = V_2 -> V_87 ;
V_53 = F_63 ( V_62 -> V_57 , V_2 -> V_12 ,
V_95 , V_2 ,
V_7 , V_94 ,
V_2 -> V_85 ,
V_2 -> V_44 ) ;
if ( F_3 ( V_53 ) ) {
F_46 ( L_29 , V_62 -> V_57 ,
F_61 ( V_53 ) ) ;
F_57 ( V_94 ) ;
F_57 ( V_7 ) ;
F_58 ( V_2 ) ;
}
}
F_28 ( V_34 ) ;
return 0 ;
V_97:
F_28 ( V_62 ) ;
F_28 ( V_34 ) ;
F_58 ( V_2 ) ;
F_64 () ;
return - V_73 ;
}
void F_64 ( void )
{
struct V_52 * V_34 , * V_62 ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 ) {
F_60 ( L_26 ) ;
return;
}
F_30 (np, child) {
struct V_1 * V_53 ;
V_53 = F_24 ( V_62 -> V_57 ) ;
if ( F_3 ( V_53 ) )
continue;
F_65 ( V_53 ) ;
F_57 ( V_53 -> V_94 ) ;
F_57 ( V_53 -> V_7 ) ;
F_58 ( V_53 -> V_6 ) ;
}
F_28 ( V_34 ) ;
}
