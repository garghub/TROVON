static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 -> V_7 )
return - V_8 ;
return V_5 -> V_7 ( V_5 -> V_9 , V_3 ) ;
}
static int F_2 ( struct V_1 * V_2 , int V_10 ,
enum V_11 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
long V_13 ;
int V_14 ;
if ( ! V_5 -> V_15 )
return - V_8 ;
V_14 = V_5 -> V_15 ( V_5 -> V_9 , & V_13 ) ;
if ( V_14 )
return V_14 ;
if ( V_13 > 0 )
* V_12 = V_16 ;
else if ( V_13 < 0 )
* V_12 = V_17 ;
else
* V_12 = V_18 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_4 * V_5 = V_19 -> V_6 ;
int V_22 ;
if ( ! V_5 || F_4 ( V_5 ) )
return - V_23 ;
for ( V_22 = 0 ; V_22 < V_5 -> V_24 ; V_22 ++ ) {
struct V_25 * V_26 = V_5 -> V_27 + V_22 ;
if ( V_26 -> V_28 == V_21 -> V_29 ) {
int V_30 ;
V_30 = F_5 ( V_19 ,
V_26 -> V_31 , V_21 ,
V_26 -> V_32 ,
V_26 -> V_33 ) ;
if ( V_30 )
return V_30 ;
}
}
return 0 ;
}
static int F_6 ( struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_4 * V_5 = V_19 -> V_6 ;
int V_22 ;
if ( ! V_5 || F_4 ( V_5 ) )
return - V_23 ;
for ( V_22 = 0 ; V_22 < V_5 -> V_24 ; V_22 ++ ) {
struct V_25 * V_26 = V_5 -> V_27 + V_22 ;
if ( V_26 -> V_28 == V_21 -> V_29 ) {
int V_30 ;
V_30 = F_7 ( V_19 ,
V_26 -> V_31 , V_21 ) ;
if ( V_30 )
return V_30 ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
enum V_34 * V_35 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
* V_35 = V_5 -> V_35 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_10 ( & V_2 -> V_36 ) ;
if ( V_35 == V_37 )
V_2 -> V_38 = V_5 -> V_38 ;
else
V_2 -> V_38 = 0 ;
F_11 ( & V_2 -> V_36 ) ;
V_5 -> V_35 = V_35 ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_10 ,
enum V_39 * type )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_10 >= V_5 -> V_40 || V_10 < 0 )
return - V_41 ;
* type = V_5 -> V_42 [ V_10 ] . type ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_10 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_10 >= V_5 -> V_40 || V_10 < 0 )
return - V_41 ;
* V_3 = V_5 -> V_42 [ V_10 ] . V_43 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_10 ,
unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_10 >= V_5 -> V_40 || V_10 < 0 )
return - V_41 ;
V_5 -> V_42 [ V_10 ] . V_43 = V_3 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_10 ,
unsigned long * V_44 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_10 >= V_5 -> V_40 || V_10 < 0 )
return - V_41 ;
* V_44 = V_5 -> V_42 [ V_10 ] . V_45 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_10 ,
unsigned long V_44 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_10 >= V_5 -> V_40 || V_10 < 0 )
return - V_41 ;
V_5 -> V_42 [ V_10 ] . V_45 = V_44 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_5 -> V_40 ; V_22 ++ )
if ( V_5 -> V_42 [ V_22 ] . type == V_46 ) {
* V_3 = V_5 -> V_42 [ V_22 ] . V_43 ;
return 0 ;
}
return - V_8 ;
}
static struct V_1 *
F_19 ( struct V_47 * V_48 ,
struct V_47 * V_49 , void * V_5 ,
int (* V_7)( void * , long * ) ,
int (* V_15)( void * , long * ) )
{
struct V_1 * V_50 ;
struct V_4 * V_2 ;
V_50 = F_20 ( V_48 -> V_51 ) ;
if ( F_4 ( V_50 ) )
return F_21 ( - V_52 ) ;
V_2 = V_50 -> V_6 ;
F_10 ( & V_50 -> V_36 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_9 = V_5 ;
V_50 -> V_53 -> V_7 = F_1 ;
V_50 -> V_53 -> V_15 = F_2 ;
F_11 ( & V_50 -> V_36 ) ;
return V_50 ;
}
struct V_1 *
F_22 ( struct V_54 * V_55 , int V_56 ,
void * V_5 , int (* V_7)( void * , long * ) ,
int (* V_15)( void * , long * ) )
{
struct V_47 * V_29 , * V_57 , * V_58 ;
struct V_1 * V_50 = F_21 ( - V_23 ) ;
V_29 = F_23 ( NULL , L_1 ) ;
if ( ! V_29 )
return F_21 ( - V_23 ) ;
if ( ! V_55 || ! V_55 -> V_59 ) {
F_24 ( V_29 ) ;
return F_21 ( - V_8 ) ;
}
V_58 = F_25 ( V_55 -> V_59 ) ;
F_26 (np, child) {
struct V_60 V_61 ;
int V_30 , V_62 ;
if ( ! F_27 ( V_57 ) )
continue;
V_30 = F_28 ( V_57 , L_2 ,
L_3 ,
0 , & V_61 ) ;
if ( V_30 )
continue;
if ( V_61 . V_63 >= 1 ) {
V_62 = V_61 . args [ 0 ] ;
F_29 ( V_61 . V_63 > 1 ,
L_4 ,
V_61 . V_29 -> V_51 , V_61 . V_63 ) ;
} else {
V_62 = 0 ;
}
if ( V_61 . V_29 == V_58 && V_62 == V_56 ) {
V_50 = F_19 ( V_57 , V_58 ,
V_5 ,
V_7 ,
V_15 ) ;
F_24 ( V_61 . V_29 ) ;
F_24 ( V_57 ) ;
goto exit;
}
F_24 ( V_61 . V_29 ) ;
}
exit:
F_24 ( V_58 ) ;
F_24 ( V_29 ) ;
return V_50 ;
}
void F_30 ( struct V_54 * V_55 ,
struct V_1 * V_50 )
{
struct V_4 * V_2 ;
if ( ! V_55 || ! V_50 || ! V_50 -> V_6 )
return;
V_2 = V_50 -> V_6 ;
if ( ! V_2 )
return;
F_10 ( & V_50 -> V_36 ) ;
V_50 -> V_53 -> V_7 = NULL ;
V_50 -> V_53 -> V_15 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_9 = NULL ;
F_11 ( & V_50 -> V_36 ) ;
}
static int F_31 ( struct V_47 * V_29 ,
struct V_25 * V_64 ,
struct V_65 * V_42 ,
int V_40 )
{
struct V_60 V_66 ;
struct V_47 * V_10 ;
int V_30 , V_22 ;
T_1 V_67 ;
V_64 -> V_68 = 0 ;
V_30 = F_32 ( V_29 , L_5 , & V_67 ) ;
if ( V_30 == 0 )
V_64 -> V_68 = V_67 ;
V_10 = F_33 ( V_29 , L_6 , 0 ) ;
if ( ! V_10 ) {
F_34 ( L_7 ) ;
return - V_23 ;
}
for ( V_22 = 0 ; V_22 < V_40 ; V_22 ++ )
if ( V_10 == V_42 [ V_22 ] . V_29 ) {
V_64 -> V_31 = V_22 ;
break;
}
if ( V_22 == V_40 ) {
V_30 = - V_23 ;
goto V_69;
}
V_30 = F_28 ( V_29 , L_8 , L_9 ,
0 , & V_66 ) ;
if ( V_30 < 0 ) {
F_34 ( L_10 ) ;
goto V_69;
}
V_64 -> V_28 = V_66 . V_29 ;
if ( V_66 . V_63 >= 2 ) {
V_64 -> V_33 = V_66 . args [ 0 ] ;
V_64 -> V_32 = V_66 . args [ 1 ] ;
} else {
F_34 ( L_11 ) ;
}
V_69:
F_24 ( V_10 ) ;
return V_30 ;
}
static int F_35 ( struct V_47 * V_29 ,
enum V_39 * type )
{
const char * V_70 ;
int V_71 , V_22 ;
V_71 = F_36 ( V_29 , L_12 , & V_70 ) ;
if ( V_71 < 0 )
return V_71 ;
for ( V_22 = 0 ; V_22 < F_37 ( V_72 ) ; V_22 ++ )
if ( ! strcasecmp ( V_70 , V_72 [ V_22 ] ) ) {
* type = V_22 ;
return 0 ;
}
return - V_23 ;
}
static int F_38 ( struct V_47 * V_29 ,
struct V_65 * V_10 )
{
int V_67 ;
int V_30 ;
V_30 = F_32 ( V_29 , L_13 , & V_67 ) ;
if ( V_30 < 0 ) {
F_34 ( L_14 ) ;
return V_30 ;
}
V_10 -> V_43 = V_67 ;
V_30 = F_32 ( V_29 , L_15 , & V_67 ) ;
if ( V_30 < 0 ) {
F_34 ( L_16 ) ;
return V_30 ;
}
V_10 -> V_45 = V_67 ;
V_30 = F_35 ( V_29 , & V_10 -> type ) ;
if ( V_30 < 0 ) {
F_34 ( L_17 ) ;
return V_30 ;
}
V_10 -> V_29 = V_29 ;
F_25 ( V_29 ) ;
return 0 ;
}
static struct V_4 *
F_39 ( struct V_47 * V_29 )
{
struct V_47 * V_57 = NULL , * V_73 ;
struct V_4 * V_2 ;
int V_30 , V_22 ;
T_1 V_67 ;
if ( ! V_29 ) {
F_34 ( L_18 ) ;
return F_21 ( - V_8 ) ;
}
V_2 = F_40 ( sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return F_21 ( - V_75 ) ;
V_30 = F_32 ( V_29 , L_19 , & V_67 ) ;
if ( V_30 < 0 ) {
F_34 ( L_20 ) ;
goto V_76;
}
V_2 -> V_77 = V_67 ;
V_30 = F_32 ( V_29 , L_21 , & V_67 ) ;
if ( V_30 < 0 ) {
F_34 ( L_22 ) ;
goto V_76;
}
V_2 -> V_38 = V_67 ;
V_57 = F_41 ( V_29 , L_23 ) ;
if ( ! V_57 )
goto V_78;
V_2 -> V_40 = F_42 ( V_57 ) ;
if ( V_2 -> V_40 == 0 )
goto V_78;
V_2 -> V_42 = F_40 ( V_2 -> V_40 * sizeof( * V_2 -> V_42 ) , V_74 ) ;
if ( ! V_2 -> V_42 ) {
V_30 = - V_75 ;
goto V_76;
}
V_22 = 0 ;
F_26 (child, gchild) {
V_30 = F_38 ( V_73 , & V_2 -> V_42 [ V_22 ++ ] ) ;
if ( V_30 )
goto V_79;
}
F_24 ( V_57 ) ;
V_57 = F_41 ( V_29 , L_24 ) ;
if ( ! V_57 )
goto V_78;
V_2 -> V_24 = F_42 ( V_57 ) ;
if ( V_2 -> V_24 == 0 )
goto V_78;
V_2 -> V_27 = F_40 ( V_2 -> V_24 * sizeof( * V_2 -> V_27 ) , V_74 ) ;
if ( ! V_2 -> V_27 ) {
V_30 = - V_75 ;
goto V_79;
}
V_22 = 0 ;
F_26 (child, gchild) {
V_30 = F_31 ( V_73 , & V_2 -> V_27 [ V_22 ++ ] ,
V_2 -> V_42 , V_2 -> V_40 ) ;
if ( V_30 )
goto V_80;
}
V_78:
F_24 ( V_57 ) ;
V_2 -> V_35 = V_81 ;
return V_2 ;
V_80:
for ( V_22 = 0 ; V_22 < V_2 -> V_24 ; V_22 ++ )
F_24 ( V_2 -> V_27 [ V_22 ] . V_28 ) ;
F_43 ( V_2 -> V_27 ) ;
V_79:
for ( V_22 = 0 ; V_22 < V_2 -> V_40 ; V_22 ++ )
F_24 ( V_2 -> V_42 [ V_22 ] . V_29 ) ;
F_43 ( V_2 -> V_42 ) ;
F_24 ( V_73 ) ;
V_76:
F_43 ( V_2 ) ;
F_24 ( V_57 ) ;
return F_21 ( V_30 ) ;
}
static inline void F_44 ( struct V_4 * V_2 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_24 ; V_22 ++ )
F_24 ( V_2 -> V_27 [ V_22 ] . V_28 ) ;
F_43 ( V_2 -> V_27 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_40 ; V_22 ++ )
F_24 ( V_2 -> V_42 [ V_22 ] . V_29 ) ;
F_43 ( V_2 -> V_42 ) ;
F_43 ( V_2 ) ;
}
int T_2 F_45 ( void )
{
struct V_47 * V_29 , * V_57 ;
struct V_4 * V_2 ;
struct V_82 * V_53 ;
V_29 = F_23 ( NULL , L_1 ) ;
if ( ! V_29 ) {
F_46 ( L_25 ) ;
return 0 ;
}
F_26 (np, child) {
struct V_1 * V_48 ;
struct V_83 * V_84 ;
if ( ! F_27 ( V_57 ) )
continue;
V_2 = F_39 ( V_57 ) ;
if ( F_4 ( V_2 ) ) {
F_34 ( L_26 ,
V_57 -> V_51 ,
F_47 ( V_2 ) ) ;
continue;
}
V_53 = F_48 ( & V_85 , sizeof( * V_53 ) , V_74 ) ;
if ( ! V_53 )
goto V_86;
V_84 = F_40 ( sizeof( * V_84 ) , V_74 ) ;
if ( ! V_84 ) {
F_43 ( V_53 ) ;
goto V_86;
}
V_84 -> V_87 = true ;
V_48 = F_49 ( V_57 -> V_51 , V_2 -> V_40 ,
0 , V_2 ,
V_53 , V_84 ,
V_2 -> V_77 ,
V_2 -> V_38 ) ;
if ( F_4 ( V_48 ) ) {
F_34 ( L_27 , V_57 -> V_51 ,
F_47 ( V_48 ) ) ;
F_43 ( V_84 ) ;
F_43 ( V_53 ) ;
F_44 ( V_2 ) ;
}
}
F_24 ( V_29 ) ;
return 0 ;
V_86:
F_24 ( V_57 ) ;
F_24 ( V_29 ) ;
F_44 ( V_2 ) ;
F_50 () ;
return - V_75 ;
}
void F_50 ( void )
{
struct V_47 * V_29 , * V_57 ;
V_29 = F_23 ( NULL , L_1 ) ;
if ( ! V_29 ) {
F_34 ( L_25 ) ;
return;
}
F_26 (np, child) {
struct V_1 * V_48 ;
if ( ! F_27 ( V_57 ) )
continue;
V_48 = F_20 ( V_57 -> V_51 ) ;
if ( F_4 ( V_48 ) )
continue;
F_51 ( V_48 ) ;
F_43 ( V_48 -> V_84 ) ;
F_43 ( V_48 -> V_53 ) ;
F_44 ( V_48 -> V_6 ) ;
}
F_24 ( V_29 ) ;
}
