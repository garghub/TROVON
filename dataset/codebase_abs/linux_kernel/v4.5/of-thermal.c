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
V_5 -> V_15 [ V_13 ] . V_47 = V_3 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_13 ,
int * V_48 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_46 ;
* V_48 = V_5 -> V_15 [ V_13 ] . V_49 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_13 ,
int V_48 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_46 ;
V_5 -> V_15 [ V_13 ] . V_49 = V_48 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_12 ; V_28 ++ )
if ( V_5 -> V_15 [ V_28 ] . type == V_50 ) {
* V_3 = V_5 -> V_15 [ V_28 ] . V_47 ;
return 0 ;
}
return - V_9 ;
}
static struct V_1 *
F_23 ( struct V_51 * V_52 ,
struct V_51 * V_53 , void * V_5 ,
const struct V_54 * V_7 )
{
struct V_1 * V_55 ;
struct V_4 * V_2 ;
V_55 = F_24 ( V_52 -> V_56 ) ;
if ( F_3 ( V_55 ) )
return F_25 ( - V_57 ) ;
V_2 = V_55 -> V_6 ;
if ( ! V_7 )
return F_25 ( - V_9 ) ;
F_14 ( & V_55 -> V_42 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = V_5 ;
V_55 -> V_7 -> V_8 = F_1 ;
V_55 -> V_7 -> V_21 = F_7 ;
V_55 -> V_7 -> V_16 = F_6 ;
F_15 ( & V_55 -> V_42 ) ;
return V_55 ;
}
struct V_1 *
F_26 ( struct V_58 * V_59 , int V_60 , void * V_5 ,
const struct V_54 * V_7 )
{
struct V_51 * V_34 , * V_61 , * V_62 ;
struct V_1 * V_55 = F_25 ( - V_11 ) ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 )
return F_25 ( - V_11 ) ;
if ( ! V_59 || ! V_59 -> V_63 ) {
F_28 ( V_34 ) ;
return F_25 ( - V_9 ) ;
}
V_62 = F_29 ( V_59 -> V_63 ) ;
F_30 (np, child) {
struct V_64 V_65 ;
int V_35 , V_66 ;
V_35 = F_31 ( V_61 , L_2 ,
L_3 ,
0 , & V_65 ) ;
if ( V_35 )
continue;
if ( V_65 . V_67 >= 1 ) {
V_66 = V_65 . args [ 0 ] ;
F_32 ( V_65 . V_67 > 1 ,
L_4 ,
V_65 . V_34 -> V_56 , V_65 . V_67 ) ;
} else {
V_66 = 0 ;
}
if ( V_65 . V_34 == V_62 && V_66 == V_60 ) {
V_55 = F_23 ( V_61 , V_62 ,
V_5 , V_7 ) ;
if ( ! F_3 ( V_55 ) )
V_55 -> V_7 -> V_68 ( V_55 , V_43 ) ;
F_28 ( V_65 . V_34 ) ;
F_28 ( V_61 ) ;
goto exit;
}
F_28 ( V_65 . V_34 ) ;
}
exit:
F_28 ( V_62 ) ;
F_28 ( V_34 ) ;
return V_55 ;
}
void F_33 ( struct V_58 * V_59 ,
struct V_1 * V_55 )
{
struct V_4 * V_2 ;
if ( ! V_59 || ! V_55 || ! V_55 -> V_6 )
return;
V_2 = V_55 -> V_6 ;
if ( ! V_2 )
return;
F_14 ( & V_55 -> V_42 ) ;
V_55 -> V_7 -> V_8 = NULL ;
V_55 -> V_7 -> V_21 = NULL ;
V_55 -> V_7 -> V_16 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_10 = NULL ;
F_15 ( & V_55 -> V_42 ) ;
}
static int F_34 ( struct V_51 * V_34 ,
struct V_30 * V_69 ,
struct V_14 * V_15 ,
int V_12 )
{
struct V_64 V_70 ;
struct V_51 * V_13 ;
int V_35 , V_28 ;
T_1 V_71 ;
V_69 -> V_39 = V_72 ;
V_35 = F_35 ( V_34 , L_5 , & V_71 ) ;
if ( V_35 == 0 )
V_69 -> V_39 = V_71 ;
V_13 = F_36 ( V_34 , L_6 , 0 ) ;
if ( ! V_13 ) {
F_37 ( L_7 ) ;
return - V_11 ;
}
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
if ( V_13 == V_15 [ V_28 ] . V_34 ) {
V_69 -> V_36 = V_28 ;
break;
}
if ( V_28 == V_12 ) {
V_35 = - V_11 ;
goto V_73;
}
V_35 = F_31 ( V_34 , L_8 , L_9 ,
0 , & V_70 ) ;
if ( V_35 < 0 ) {
F_37 ( L_10 ) ;
goto V_73;
}
V_69 -> V_33 = V_70 . V_34 ;
if ( V_70 . V_67 >= 2 ) {
V_69 -> V_38 = V_70 . args [ 0 ] ;
V_69 -> V_37 = V_70 . args [ 1 ] ;
} else {
F_37 ( L_11 ) ;
}
V_73:
F_28 ( V_13 ) ;
return V_35 ;
}
static int F_38 ( struct V_51 * V_34 ,
enum V_45 * type )
{
const char * V_74 ;
int V_75 , V_28 ;
V_75 = F_39 ( V_34 , L_12 , & V_74 ) ;
if ( V_75 < 0 )
return V_75 ;
for ( V_28 = 0 ; V_28 < F_40 ( V_76 ) ; V_28 ++ )
if ( ! strcasecmp ( V_74 , V_76 [ V_28 ] ) ) {
* type = V_28 ;
return 0 ;
}
return - V_11 ;
}
static int F_41 ( struct V_51 * V_34 ,
struct V_14 * V_13 )
{
int V_71 ;
int V_35 ;
V_35 = F_35 ( V_34 , L_13 , & V_71 ) ;
if ( V_35 < 0 ) {
F_37 ( L_14 ) ;
return V_35 ;
}
V_13 -> V_47 = V_71 ;
V_35 = F_35 ( V_34 , L_15 , & V_71 ) ;
if ( V_35 < 0 ) {
F_37 ( L_16 ) ;
return V_35 ;
}
V_13 -> V_49 = V_71 ;
V_35 = F_38 ( V_34 , & V_13 -> type ) ;
if ( V_35 < 0 ) {
F_37 ( L_17 ) ;
return V_35 ;
}
V_13 -> V_34 = V_34 ;
F_29 ( V_34 ) ;
return 0 ;
}
static struct V_4 *
F_42 ( struct V_51 * V_34 )
{
struct V_51 * V_61 = NULL , * V_77 ;
struct V_4 * V_2 ;
int V_35 , V_28 ;
T_1 V_71 , V_78 [ 2 ] ;
if ( ! V_34 ) {
F_37 ( L_18 ) ;
return F_25 ( - V_9 ) ;
}
V_2 = F_43 ( sizeof( * V_2 ) , V_79 ) ;
if ( ! V_2 )
return F_25 ( - V_80 ) ;
V_35 = F_35 ( V_34 , L_19 , & V_71 ) ;
if ( V_35 < 0 ) {
F_37 ( L_20 ) ;
goto V_81;
}
V_2 -> V_82 = V_71 ;
V_35 = F_35 ( V_34 , L_21 , & V_71 ) ;
if ( V_35 < 0 ) {
F_37 ( L_22 ) ;
goto V_81;
}
V_2 -> V_44 = V_71 ;
V_35 = F_44 ( V_34 , L_23 , V_78 , 2 ) ;
if ( V_35 == 0 ) {
V_2 -> V_83 = V_78 [ 0 ] ;
V_2 -> V_84 = V_78 [ 1 ] ;
} else {
V_2 -> V_83 = 1 ;
V_2 -> V_84 = 0 ;
}
V_61 = F_45 ( V_34 , L_24 ) ;
if ( ! V_61 )
goto V_85;
V_2 -> V_12 = F_46 ( V_61 ) ;
if ( V_2 -> V_12 == 0 )
goto V_85;
V_2 -> V_15 = F_43 ( V_2 -> V_12 * sizeof( * V_2 -> V_15 ) , V_79 ) ;
if ( ! V_2 -> V_15 ) {
V_35 = - V_80 ;
goto V_81;
}
V_28 = 0 ;
F_47 (child, gchild) {
V_35 = F_41 ( V_77 , & V_2 -> V_15 [ V_28 ++ ] ) ;
if ( V_35 )
goto V_86;
}
F_28 ( V_61 ) ;
V_61 = F_45 ( V_34 , L_25 ) ;
if ( ! V_61 )
goto V_85;
V_2 -> V_29 = F_46 ( V_61 ) ;
if ( V_2 -> V_29 == 0 )
goto V_85;
V_2 -> V_32 = F_43 ( V_2 -> V_29 * sizeof( * V_2 -> V_32 ) , V_79 ) ;
if ( ! V_2 -> V_32 ) {
V_35 = - V_80 ;
goto V_86;
}
V_28 = 0 ;
F_47 (child, gchild) {
V_35 = F_34 ( V_77 , & V_2 -> V_32 [ V_28 ++ ] ,
V_2 -> V_15 , V_2 -> V_12 ) ;
if ( V_35 )
goto V_87;
}
V_85:
F_28 ( V_61 ) ;
V_2 -> V_41 = V_88 ;
return V_2 ;
V_87:
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ )
F_28 ( V_2 -> V_32 [ V_28 ] . V_33 ) ;
F_48 ( V_2 -> V_32 ) ;
V_86:
for ( V_28 = 0 ; V_28 < V_2 -> V_12 ; V_28 ++ )
F_28 ( V_2 -> V_15 [ V_28 ] . V_34 ) ;
F_48 ( V_2 -> V_15 ) ;
F_28 ( V_77 ) ;
V_81:
F_48 ( V_2 ) ;
F_28 ( V_61 ) ;
return F_25 ( V_35 ) ;
}
static inline void F_49 ( struct V_4 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ )
F_28 ( V_2 -> V_32 [ V_28 ] . V_33 ) ;
F_48 ( V_2 -> V_32 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_12 ; V_28 ++ )
F_28 ( V_2 -> V_15 [ V_28 ] . V_34 ) ;
F_48 ( V_2 -> V_15 ) ;
F_48 ( V_2 ) ;
}
int T_2 F_50 ( void )
{
struct V_51 * V_34 , * V_61 ;
struct V_4 * V_2 ;
struct V_89 * V_7 ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 ) {
F_51 ( L_26 ) ;
return 0 ;
}
F_30 (np, child) {
struct V_1 * V_52 ;
struct V_90 * V_91 ;
int V_28 , V_92 = 0 ;
T_1 V_71 ;
V_2 = F_42 ( V_61 ) ;
if ( F_3 ( V_2 ) ) {
F_37 ( L_27 ,
V_61 -> V_56 ,
F_52 ( V_2 ) ) ;
continue;
}
V_7 = F_53 ( & V_93 , sizeof( * V_7 ) , V_79 ) ;
if ( ! V_7 )
goto V_94;
V_91 = F_43 ( sizeof( * V_91 ) , V_79 ) ;
if ( ! V_91 ) {
F_48 ( V_7 ) ;
goto V_94;
}
V_91 -> V_95 = true ;
if ( ! F_35 ( V_61 , L_28 , & V_71 ) )
V_91 -> V_96 = V_71 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_12 ; V_28 ++ )
V_92 |= 1 << V_28 ;
V_91 -> V_83 = V_2 -> V_83 ;
V_91 -> V_84 = V_2 -> V_84 ;
V_52 = F_54 ( V_61 -> V_56 , V_2 -> V_12 ,
V_92 , V_2 ,
V_7 , V_91 ,
V_2 -> V_82 ,
V_2 -> V_44 ) ;
if ( F_3 ( V_52 ) ) {
F_37 ( L_29 , V_61 -> V_56 ,
F_52 ( V_52 ) ) ;
F_48 ( V_91 ) ;
F_48 ( V_7 ) ;
F_49 ( V_2 ) ;
}
}
F_28 ( V_34 ) ;
return 0 ;
V_94:
F_28 ( V_61 ) ;
F_28 ( V_34 ) ;
F_49 ( V_2 ) ;
F_55 () ;
return - V_80 ;
}
void F_55 ( void )
{
struct V_51 * V_34 , * V_61 ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 ) {
F_51 ( L_26 ) ;
return;
}
F_30 (np, child) {
struct V_1 * V_52 ;
V_52 = F_24 ( V_61 -> V_56 ) ;
if ( F_3 ( V_52 ) )
continue;
F_56 ( V_52 ) ;
F_48 ( V_52 -> V_91 ) ;
F_48 ( V_52 -> V_7 ) ;
F_49 ( V_52 -> V_6 ) ;
}
F_28 ( V_34 ) ;
}
