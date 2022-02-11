static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
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
unsigned long V_3 )
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
V_31 -> V_38 ) ;
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
enum V_39 * V_40 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_40 = V_5 -> V_40 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_39 V_40 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_14 ( & V_2 -> V_41 ) ;
if ( V_40 == V_42 )
V_2 -> V_43 = V_5 -> V_43 ;
else
V_2 -> V_43 = 0 ;
F_15 ( & V_2 -> V_41 ) ;
V_5 -> V_40 = V_40 ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_13 ,
enum V_44 * type )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_45 ;
* type = V_5 -> V_15 [ V_13 ] . type ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_13 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_45 ;
* V_3 = V_5 -> V_15 [ V_13 ] . V_46 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_13 ,
unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_45 ;
V_5 -> V_15 [ V_13 ] . V_46 = V_3 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_13 ,
unsigned long * V_47 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_45 ;
* V_47 = V_5 -> V_15 [ V_13 ] . V_48 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_13 ,
unsigned long V_47 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_13 >= V_5 -> V_12 || V_13 < 0 )
return - V_45 ;
V_5 -> V_15 [ V_13 ] . V_48 = V_47 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_5 -> V_12 ; V_28 ++ )
if ( V_5 -> V_15 [ V_28 ] . type == V_49 ) {
* V_3 = V_5 -> V_15 [ V_28 ] . V_46 ;
return 0 ;
}
return - V_9 ;
}
static struct V_1 *
F_23 ( struct V_50 * V_51 ,
struct V_50 * V_52 , void * V_5 ,
const struct V_53 * V_7 )
{
struct V_1 * V_54 ;
struct V_4 * V_2 ;
V_54 = F_24 ( V_51 -> V_55 ) ;
if ( F_3 ( V_54 ) )
return F_25 ( - V_56 ) ;
V_2 = V_54 -> V_6 ;
if ( ! V_7 )
return F_25 ( - V_9 ) ;
F_14 ( & V_54 -> V_41 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = V_5 ;
V_54 -> V_7 -> V_8 = F_1 ;
V_54 -> V_7 -> V_21 = F_7 ;
V_54 -> V_7 -> V_16 = F_6 ;
F_15 ( & V_54 -> V_41 ) ;
return V_54 ;
}
struct V_1 *
F_26 ( struct V_57 * V_58 , int V_59 , void * V_5 ,
const struct V_53 * V_7 )
{
struct V_50 * V_34 , * V_60 , * V_61 ;
struct V_1 * V_54 = F_25 ( - V_11 ) ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 )
return F_25 ( - V_11 ) ;
if ( ! V_58 || ! V_58 -> V_62 ) {
F_28 ( V_34 ) ;
return F_25 ( - V_9 ) ;
}
V_61 = F_29 ( V_58 -> V_62 ) ;
F_30 (np, child) {
struct V_63 V_64 ;
int V_35 , V_65 ;
if ( ! F_31 ( V_60 ) )
continue;
V_35 = F_32 ( V_60 , L_2 ,
L_3 ,
0 , & V_64 ) ;
if ( V_35 )
continue;
if ( V_64 . V_66 >= 1 ) {
V_65 = V_64 . args [ 0 ] ;
F_33 ( V_64 . V_66 > 1 ,
L_4 ,
V_64 . V_34 -> V_55 , V_64 . V_66 ) ;
} else {
V_65 = 0 ;
}
if ( V_64 . V_34 == V_61 && V_65 == V_59 ) {
V_54 = F_23 ( V_60 , V_61 ,
V_5 , V_7 ) ;
if ( ! F_3 ( V_54 ) )
V_54 -> V_7 -> V_67 ( V_54 , V_42 ) ;
F_28 ( V_64 . V_34 ) ;
F_28 ( V_60 ) ;
goto exit;
}
F_28 ( V_64 . V_34 ) ;
}
exit:
F_28 ( V_61 ) ;
F_28 ( V_34 ) ;
return V_54 ;
}
void F_34 ( struct V_57 * V_58 ,
struct V_1 * V_54 )
{
struct V_4 * V_2 ;
if ( ! V_58 || ! V_54 || ! V_54 -> V_6 )
return;
V_2 = V_54 -> V_6 ;
if ( ! V_2 )
return;
F_14 ( & V_54 -> V_41 ) ;
V_54 -> V_7 -> V_8 = NULL ;
V_54 -> V_7 -> V_21 = NULL ;
V_54 -> V_7 -> V_16 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_10 = NULL ;
F_15 ( & V_54 -> V_41 ) ;
}
static int F_35 ( struct V_50 * V_34 ,
struct V_30 * V_68 ,
struct V_14 * V_15 ,
int V_12 )
{
struct V_63 V_69 ;
struct V_50 * V_13 ;
int V_35 , V_28 ;
T_1 V_70 ;
V_68 -> V_71 = 0 ;
V_35 = F_36 ( V_34 , L_5 , & V_70 ) ;
if ( V_35 == 0 )
V_68 -> V_71 = V_70 ;
V_13 = F_37 ( V_34 , L_6 , 0 ) ;
if ( ! V_13 ) {
F_38 ( L_7 ) ;
return - V_11 ;
}
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
if ( V_13 == V_15 [ V_28 ] . V_34 ) {
V_68 -> V_36 = V_28 ;
break;
}
if ( V_28 == V_12 ) {
V_35 = - V_11 ;
goto V_72;
}
V_35 = F_32 ( V_34 , L_8 , L_9 ,
0 , & V_69 ) ;
if ( V_35 < 0 ) {
F_38 ( L_10 ) ;
goto V_72;
}
V_68 -> V_33 = V_69 . V_34 ;
if ( V_69 . V_66 >= 2 ) {
V_68 -> V_38 = V_69 . args [ 0 ] ;
V_68 -> V_37 = V_69 . args [ 1 ] ;
} else {
F_38 ( L_11 ) ;
}
V_72:
F_28 ( V_13 ) ;
return V_35 ;
}
static int F_39 ( struct V_50 * V_34 ,
enum V_44 * type )
{
const char * V_73 ;
int V_74 , V_28 ;
V_74 = F_40 ( V_34 , L_12 , & V_73 ) ;
if ( V_74 < 0 )
return V_74 ;
for ( V_28 = 0 ; V_28 < F_41 ( V_75 ) ; V_28 ++ )
if ( ! strcasecmp ( V_73 , V_75 [ V_28 ] ) ) {
* type = V_28 ;
return 0 ;
}
return - V_11 ;
}
static int F_42 ( struct V_50 * V_34 ,
struct V_14 * V_13 )
{
int V_70 ;
int V_35 ;
V_35 = F_36 ( V_34 , L_13 , & V_70 ) ;
if ( V_35 < 0 ) {
F_38 ( L_14 ) ;
return V_35 ;
}
V_13 -> V_46 = V_70 ;
V_35 = F_36 ( V_34 , L_15 , & V_70 ) ;
if ( V_35 < 0 ) {
F_38 ( L_16 ) ;
return V_35 ;
}
V_13 -> V_48 = V_70 ;
V_35 = F_39 ( V_34 , & V_13 -> type ) ;
if ( V_35 < 0 ) {
F_38 ( L_17 ) ;
return V_35 ;
}
V_13 -> V_34 = V_34 ;
F_29 ( V_34 ) ;
return 0 ;
}
static struct V_4 *
F_43 ( struct V_50 * V_34 )
{
struct V_50 * V_60 = NULL , * V_76 ;
struct V_4 * V_2 ;
int V_35 , V_28 ;
T_1 V_70 ;
if ( ! V_34 ) {
F_38 ( L_18 ) ;
return F_25 ( - V_9 ) ;
}
V_2 = F_44 ( sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return F_25 ( - V_78 ) ;
V_35 = F_36 ( V_34 , L_19 , & V_70 ) ;
if ( V_35 < 0 ) {
F_38 ( L_20 ) ;
goto V_79;
}
V_2 -> V_80 = V_70 ;
V_35 = F_36 ( V_34 , L_21 , & V_70 ) ;
if ( V_35 < 0 ) {
F_38 ( L_22 ) ;
goto V_79;
}
V_2 -> V_43 = V_70 ;
V_60 = F_45 ( V_34 , L_23 ) ;
if ( ! V_60 )
goto V_81;
V_2 -> V_12 = F_46 ( V_60 ) ;
if ( V_2 -> V_12 == 0 )
goto V_81;
V_2 -> V_15 = F_44 ( V_2 -> V_12 * sizeof( * V_2 -> V_15 ) , V_77 ) ;
if ( ! V_2 -> V_15 ) {
V_35 = - V_78 ;
goto V_79;
}
V_28 = 0 ;
F_30 (child, gchild) {
V_35 = F_42 ( V_76 , & V_2 -> V_15 [ V_28 ++ ] ) ;
if ( V_35 )
goto V_82;
}
F_28 ( V_60 ) ;
V_60 = F_45 ( V_34 , L_24 ) ;
if ( ! V_60 )
goto V_81;
V_2 -> V_29 = F_46 ( V_60 ) ;
if ( V_2 -> V_29 == 0 )
goto V_81;
V_2 -> V_32 = F_44 ( V_2 -> V_29 * sizeof( * V_2 -> V_32 ) , V_77 ) ;
if ( ! V_2 -> V_32 ) {
V_35 = - V_78 ;
goto V_82;
}
V_28 = 0 ;
F_30 (child, gchild) {
V_35 = F_35 ( V_76 , & V_2 -> V_32 [ V_28 ++ ] ,
V_2 -> V_15 , V_2 -> V_12 ) ;
if ( V_35 )
goto V_83;
}
V_81:
F_28 ( V_60 ) ;
V_2 -> V_40 = V_84 ;
return V_2 ;
V_83:
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ )
F_28 ( V_2 -> V_32 [ V_28 ] . V_33 ) ;
F_47 ( V_2 -> V_32 ) ;
V_82:
for ( V_28 = 0 ; V_28 < V_2 -> V_12 ; V_28 ++ )
F_28 ( V_2 -> V_15 [ V_28 ] . V_34 ) ;
F_47 ( V_2 -> V_15 ) ;
F_28 ( V_76 ) ;
V_79:
F_47 ( V_2 ) ;
F_28 ( V_60 ) ;
return F_25 ( V_35 ) ;
}
static inline void F_48 ( struct V_4 * V_2 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ )
F_28 ( V_2 -> V_32 [ V_28 ] . V_33 ) ;
F_47 ( V_2 -> V_32 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_12 ; V_28 ++ )
F_28 ( V_2 -> V_15 [ V_28 ] . V_34 ) ;
F_47 ( V_2 -> V_15 ) ;
F_47 ( V_2 ) ;
}
int T_2 F_49 ( void )
{
struct V_50 * V_34 , * V_60 ;
struct V_4 * V_2 ;
struct V_85 * V_7 ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 ) {
F_50 ( L_25 ) ;
return 0 ;
}
F_30 (np, child) {
struct V_1 * V_51 ;
struct V_86 * V_87 ;
if ( ! F_31 ( V_60 ) )
continue;
V_2 = F_43 ( V_60 ) ;
if ( F_3 ( V_2 ) ) {
F_38 ( L_26 ,
V_60 -> V_55 ,
F_51 ( V_2 ) ) ;
continue;
}
V_7 = F_52 ( & V_88 , sizeof( * V_7 ) , V_77 ) ;
if ( ! V_7 )
goto V_89;
V_87 = F_44 ( sizeof( * V_87 ) , V_77 ) ;
if ( ! V_87 ) {
F_47 ( V_7 ) ;
goto V_89;
}
V_87 -> V_90 = true ;
V_51 = F_53 ( V_60 -> V_55 , V_2 -> V_12 ,
0 , V_2 ,
V_7 , V_87 ,
V_2 -> V_80 ,
V_2 -> V_43 ) ;
if ( F_3 ( V_51 ) ) {
F_38 ( L_27 , V_60 -> V_55 ,
F_51 ( V_51 ) ) ;
F_47 ( V_87 ) ;
F_47 ( V_7 ) ;
F_48 ( V_2 ) ;
}
}
F_28 ( V_34 ) ;
return 0 ;
V_89:
F_28 ( V_60 ) ;
F_28 ( V_34 ) ;
F_48 ( V_2 ) ;
F_54 () ;
return - V_78 ;
}
void F_54 ( void )
{
struct V_50 * V_34 , * V_60 ;
V_34 = F_27 ( NULL , L_1 ) ;
if ( ! V_34 ) {
F_38 ( L_25 ) ;
return;
}
F_30 (np, child) {
struct V_1 * V_51 ;
if ( ! F_31 ( V_60 ) )
continue;
V_51 = F_24 ( V_60 -> V_55 ) ;
if ( F_3 ( V_51 ) )
continue;
F_55 ( V_51 ) ;
F_47 ( V_51 -> V_87 ) ;
F_47 ( V_51 -> V_7 ) ;
F_48 ( V_51 -> V_6 ) ;
}
F_28 ( V_34 ) ;
}
