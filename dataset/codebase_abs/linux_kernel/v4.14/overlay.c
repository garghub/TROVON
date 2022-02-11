int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( & V_3 , V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_8 V_9 ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_12 ; V_10 ++ ) {
struct V_13 * V_14 = & V_5 -> V_15 [ V_10 ] ;
V_9 . V_16 = V_14 -> V_16 ;
V_9 . V_17 = V_14 -> V_17 ;
V_11 = F_6 ( & V_3 ,
V_7 , & V_9 ) ;
if ( V_11 )
return F_7 ( V_11 ) ;
}
return 0 ;
}
static struct V_18 * F_8 ( struct V_4 * V_5 ,
const struct V_18 * V_19 )
{
struct V_13 * V_14 ;
struct V_18 * V_20 ;
const char * V_21 ;
char * V_22 ;
char * V_23 ;
const char * V_24 ;
int V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
if ( ! V_19 -> V_29 )
return NULL ;
V_23 = V_19 -> V_29 ;
V_20 = F_9 ( sizeof( * V_20 ) , V_30 ) ;
if ( ! V_20 )
return NULL ;
for ( V_25 = 0 ; V_25 < V_5 -> V_12 ; V_25 ++ ) {
V_14 = & V_5 -> V_15 [ V_25 ] ;
V_21 = V_14 -> V_17 -> V_31 ;
V_27 = strlen ( V_21 ) ;
if ( ! strncasecmp ( V_23 , V_21 , V_27 ) )
break;
}
if ( V_25 >= V_5 -> V_12 )
goto V_32;
V_24 = V_14 -> V_16 -> V_31 ;
V_28 = strlen ( V_24 ) ;
V_22 = V_23 + V_27 ;
V_26 = strlen ( V_22 ) ;
V_20 -> V_33 = F_10 ( V_19 -> V_33 , V_30 ) ;
V_20 -> V_34 = V_28 + V_26 + 1 ;
V_20 -> V_29 = F_9 ( V_20 -> V_34 , V_30 ) ;
if ( ! V_20 -> V_33 || ! V_20 -> V_29 )
goto V_32;
strcpy ( V_20 -> V_29 , V_24 ) ;
strcpy ( V_20 -> V_29 + V_28 , V_22 ) ;
F_11 ( V_20 , V_35 ) ;
return V_20 ;
V_32:
F_12 ( V_20 -> V_33 ) ;
F_12 ( V_20 -> V_29 ) ;
F_12 ( V_20 ) ;
return NULL ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_36 * V_16 , struct V_18 * V_19 ,
bool V_37 )
{
struct V_18 * V_38 = NULL , * V_39 ;
V_39 = F_14 ( V_16 , V_19 -> V_33 , NULL ) ;
if ( F_15 ( V_19 -> V_33 , L_1 ) == 0 ||
F_15 ( V_19 -> V_33 , L_2 ) == 0 ||
F_15 ( V_19 -> V_33 , L_3 ) == 0 )
return 0 ;
if ( V_37 ) {
if ( V_39 )
return - V_40 ;
V_38 = F_8 ( V_5 , V_19 ) ;
} else {
V_38 = F_16 ( V_19 , V_30 ) ;
}
if ( V_38 == NULL )
return - V_41 ;
if ( V_39 == NULL )
return F_17 ( & V_5 -> V_42 , V_16 , V_38 ) ;
return F_18 ( & V_5 -> V_42 , V_16 , V_38 ) ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_36 * V_16 , struct V_36 * V_43 )
{
const char * V_44 ;
struct V_36 * V_45 ;
int V_11 = 0 ;
V_44 = F_20 ( V_43 -> V_31 ) ;
if ( V_44 == NULL )
return - V_41 ;
F_21 (target, tchild)
if ( ! F_22 ( V_44 , F_20 ( V_45 -> V_31 ) ) )
break;
if ( V_45 != NULL ) {
if ( V_43 -> V_46 )
return - V_40 ;
V_11 = F_23 ( V_5 , V_45 , V_43 , 0 ) ;
F_24 ( V_45 ) ;
} else {
V_45 = F_25 ( V_43 , L_4 , V_16 , V_44 ) ;
if ( ! V_45 )
return - V_41 ;
V_45 -> V_47 = V_16 ;
V_11 = F_26 ( & V_5 -> V_42 , V_45 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_23 ( V_5 , V_45 , V_43 , 0 ) ;
if ( V_11 )
return V_11 ;
}
return V_11 ;
}
static int F_23 ( struct V_4 * V_5 ,
struct V_36 * V_16 , const struct V_36 * V_17 ,
bool V_37 )
{
struct V_36 * V_43 ;
struct V_18 * V_19 ;
int V_11 ;
F_27 (overlay, prop) {
V_11 = F_13 ( V_5 , V_16 , V_19 ,
V_37 ) ;
if ( V_11 ) {
F_28 ( L_5 ,
V_16 , V_19 -> V_33 ) ;
return V_11 ;
}
}
if ( V_37 )
return 0 ;
F_21 (overlay, child) {
V_11 = F_19 ( V_5 , V_16 , V_43 ) ;
if ( V_11 != 0 ) {
F_28 ( L_6 ,
V_16 , V_43 -> V_33 ) ;
F_24 ( V_43 ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_29 ( struct V_4 * V_5 )
{
int V_10 , V_48 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_12 ; V_10 ++ ) {
struct V_13 * V_14 = & V_5 -> V_15 [ V_10 ] ;
V_48 = F_23 ( V_5 , V_14 -> V_16 , V_14 -> V_17 ,
V_14 -> V_37 ) ;
if ( V_48 != 0 ) {
F_28 ( L_7 , V_14 -> V_16 ) ;
return V_48 ;
}
}
return 0 ;
}
static struct V_36 * F_30 ( struct V_36 * V_49 )
{
const char * V_50 ;
T_1 V_51 ;
int V_11 ;
V_11 = F_31 ( V_49 , L_8 , & V_51 ) ;
if ( V_11 == 0 )
return F_32 ( V_51 ) ;
V_11 = F_33 ( V_49 , L_9 , & V_50 ) ;
if ( V_11 == 0 )
return F_34 ( V_50 ) ;
F_28 ( L_10 ,
V_49 , V_49 -> V_33 ) ;
return NULL ;
}
static int F_35 ( struct V_4 * V_5 ,
struct V_36 * V_49 , struct V_13 * V_14 )
{
V_14 -> V_17 = F_36 ( V_49 , L_11 ) ;
if ( V_14 -> V_17 == NULL )
goto V_52;
V_14 -> V_16 = F_30 ( V_49 ) ;
if ( V_14 -> V_16 == NULL )
goto V_52;
return 0 ;
V_52:
F_24 ( V_14 -> V_16 ) ;
F_24 ( V_14 -> V_17 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
return - V_40 ;
}
static int F_37 ( struct V_4 * V_5 ,
struct V_36 * V_53 )
{
struct V_36 * V_54 ;
struct V_13 * V_14 ;
int V_55 , V_48 ;
V_55 = 0 ;
F_21 (tree, node)
V_55 ++ ;
if ( F_36 ( V_53 , L_12 ) )
V_55 ++ ;
V_14 = F_38 ( V_55 , sizeof( * V_14 ) , V_30 ) ;
if ( V_14 == NULL )
return - V_41 ;
V_55 = 0 ;
F_21 (tree, node) {
V_48 = F_35 ( V_5 , V_54 , & V_14 [ V_55 ] ) ;
if ( V_48 == 0 )
V_55 ++ ;
}
V_54 = F_36 ( V_53 , L_12 ) ;
if ( V_54 ) {
V_14 [ V_55 ] . V_17 = V_54 ;
V_14 [ V_55 ] . V_16 = F_34 ( L_13 ) ;
V_14 [ V_55 ] . V_37 = 1 ;
if ( ! V_14 [ V_55 ] . V_16 ) {
F_28 ( L_14 ) ;
return - V_40 ;
}
V_55 ++ ;
}
if ( V_55 == 0 ) {
F_12 ( V_14 ) ;
return - V_56 ;
}
V_5 -> V_12 = V_55 ;
V_5 -> V_15 = V_14 ;
return 0 ;
}
static int F_39 ( struct V_4 * V_5 )
{
struct V_13 * V_14 ;
int V_10 ;
for ( V_10 = V_5 -> V_12 - 1 ; V_10 >= 0 ; V_10 -- ) {
V_14 = & V_5 -> V_15 [ V_10 ] ;
F_24 ( V_14 -> V_16 ) ;
F_24 ( V_14 -> V_17 ) ;
}
F_12 ( V_5 -> V_15 ) ;
return 0 ;
}
int F_40 ( struct V_36 * V_53 )
{
struct V_4 * V_5 ;
int V_48 , V_57 ;
V_5 = F_9 ( sizeof( * V_5 ) , V_30 ) ;
if ( V_5 == NULL )
return - V_41 ;
V_5 -> V_57 = - 1 ;
F_41 ( & V_5 -> V_54 ) ;
F_42 ( & V_5 -> V_42 ) ;
F_43 ( & V_58 ) ;
V_57 = F_44 ( & V_59 , V_5 , 0 , 0 , V_30 ) ;
if ( V_57 < 0 ) {
V_48 = V_57 ;
goto V_60;
}
V_5 -> V_57 = V_57 ;
V_48 = F_37 ( V_5 , V_53 ) ;
if ( V_48 ) {
F_28 ( L_15 ,
V_53 ) ;
goto V_61;
}
V_48 = F_5 ( V_5 , V_62 ) ;
if ( V_48 < 0 ) {
F_28 ( L_16 ,
V_63 , V_48 ) ;
goto V_61;
}
V_48 = F_29 ( V_5 ) ;
if ( V_48 )
goto V_64;
V_48 = F_45 ( & V_5 -> V_42 ) ;
if ( V_48 )
goto V_65;
F_46 ( & V_5 -> V_54 , & V_66 ) ;
F_5 ( V_5 , V_67 ) ;
F_47 ( & V_58 ) ;
return V_57 ;
V_65:
V_64:
F_39 ( V_5 ) ;
V_61:
F_48 ( & V_59 , V_5 -> V_57 ) ;
V_60:
F_49 ( & V_5 -> V_42 ) ;
F_12 ( V_5 ) ;
F_47 ( & V_58 ) ;
return V_48 ;
}
static int F_50 ( struct V_36 * V_53 ,
struct V_36 * V_68 )
{
struct V_36 * V_43 ;
if ( V_53 == V_68 )
return 1 ;
F_21 (tree, child) {
if ( F_50 ( V_43 , V_68 ) ) {
F_24 ( V_43 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_51 ( struct V_4 * V_5 , struct V_36 * V_68 )
{
struct V_4 * V_69 ;
struct V_70 * V_71 ;
F_52 (ovt, &ov_list, node) {
if ( V_69 == V_5 )
break;
F_53 (ce, &ovt->cset.entries, node) {
if ( F_50 ( V_71 -> V_72 , V_68 ) ) {
F_28 ( L_17 ,
V_63 , V_5 -> V_57 , V_69 -> V_57 , V_68 ) ;
return 0 ;
}
}
}
return 1 ;
}
static int F_54 ( struct V_4 * V_5 )
{
struct V_70 * V_71 ;
F_53 (ce, &ov->cset.entries, node) {
if ( ! F_51 ( V_5 , V_71 -> V_72 ) ) {
F_28 ( L_18 , V_5 -> V_57 ) ;
return 0 ;
}
}
return 1 ;
}
int F_55 ( int V_57 )
{
struct V_4 * V_5 ;
int V_48 ;
F_43 ( & V_58 ) ;
V_5 = F_56 ( & V_59 , V_57 ) ;
if ( V_5 == NULL ) {
V_48 = - V_56 ;
F_28 ( L_19 , V_57 ) ;
goto V_73;
}
if ( ! F_54 ( V_5 ) ) {
V_48 = - V_74 ;
goto V_73;
}
F_5 ( V_5 , V_75 ) ;
F_57 ( & V_5 -> V_54 ) ;
F_58 ( & V_5 -> V_42 ) ;
F_5 ( V_5 , V_76 ) ;
F_39 ( V_5 ) ;
F_48 ( & V_59 , V_57 ) ;
F_49 ( & V_5 -> V_42 ) ;
F_12 ( V_5 ) ;
V_48 = 0 ;
V_73:
F_47 ( & V_58 ) ;
return V_48 ;
}
int F_59 ( void )
{
struct V_4 * V_5 , * V_77 ;
F_43 ( & V_58 ) ;
F_60 (ov, ovn, &ov_list, node) {
F_57 ( & V_5 -> V_54 ) ;
F_58 ( & V_5 -> V_42 ) ;
F_39 ( V_5 ) ;
F_48 ( & V_59 , V_5 -> V_57 ) ;
F_12 ( V_5 ) ;
}
F_47 ( & V_58 ) ;
return 0 ;
}
