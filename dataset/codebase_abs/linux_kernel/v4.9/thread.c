int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
T_1 V_3 = V_1 -> V_4 ;
if ( V_3 == V_1 -> V_5 || V_3 == - 1 ) {
V_1 -> V_6 = F_2 ( V_2 ) ;
} else {
struct V_1 * V_7 = F_3 ( V_2 , V_3 , V_3 ) ;
if ( V_7 ) {
V_1 -> V_6 = F_4 ( V_7 -> V_6 ) ;
F_5 ( V_7 ) ;
}
}
return V_1 -> V_6 ? 0 : - 1 ;
}
struct V_1 * F_6 ( T_1 V_3 , T_1 V_5 )
{
char * V_8 ;
struct V_9 * V_9 ;
struct V_1 * V_1 = F_7 ( sizeof( * V_1 ) ) ;
if ( V_1 != NULL ) {
V_1 -> V_4 = V_3 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_10 = - 1 ;
V_1 -> V_11 = - 1 ;
F_8 ( & V_1 -> V_12 ) ;
V_8 = malloc ( 32 ) ;
if ( ! V_8 )
goto V_13;
snprintf ( V_8 , 32 , L_1 , V_5 ) ;
V_9 = F_9 ( V_8 , 0 , false ) ;
free ( V_8 ) ;
if ( ! V_9 )
goto V_13;
F_10 ( & V_9 -> V_14 , & V_1 -> V_12 ) ;
F_11 ( & V_1 -> V_15 , 1 ) ;
F_12 ( & V_1 -> V_16 ) ;
}
return V_1 ;
V_13:
free ( V_1 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_17 ;
F_14 ( ! F_15 ( & V_1 -> V_16 ) ) ;
F_16 ( V_1 ) ;
if ( V_1 -> V_6 ) {
F_17 ( V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
}
F_18 (comm, tmp, &thread->comm_list, list) {
F_19 ( & V_9 -> V_14 ) ;
F_20 ( V_9 ) ;
}
F_21 ( V_1 ) ;
free ( V_1 ) ;
}
struct V_1 * F_22 ( struct V_1 * V_1 )
{
if ( V_1 )
F_23 ( & V_1 -> V_15 ) ;
return V_1 ;
}
void F_5 ( struct V_1 * V_1 )
{
if ( V_1 && F_24 ( & V_1 -> V_15 ) ) {
F_25 ( & V_1 -> V_18 ) ;
F_13 ( V_1 ) ;
}
}
struct V_9 * F_26 ( const struct V_1 * V_1 )
{
if ( F_27 ( & V_1 -> V_12 ) )
return NULL ;
return F_28 ( & V_1 -> V_12 , struct V_9 , V_14 ) ;
}
struct V_9 * F_29 ( const struct V_1 * V_1 )
{
struct V_9 * V_9 , * V_19 = NULL ;
F_30 (comm, &thread->comm_list, list) {
if ( V_9 -> V_20 )
return V_9 ;
V_19 = V_9 ;
}
return V_19 ;
}
int F_31 ( struct V_1 * V_1 , const char * V_21 , T_2 V_22 ,
bool V_20 )
{
struct V_9 * V_23 , * V_24 = F_26 ( V_1 ) ;
if ( ! V_1 -> V_25 ) {
int V_26 = F_32 ( V_24 , V_21 , V_22 , V_20 ) ;
if ( V_26 )
return V_26 ;
} else {
V_23 = F_9 ( V_21 , V_22 , V_20 ) ;
if ( ! V_23 )
return - V_27 ;
F_10 ( & V_23 -> V_14 , & V_1 -> V_12 ) ;
if ( V_20 )
F_33 ( V_1 ) ;
}
V_1 -> V_25 = true ;
return 0 ;
}
int F_34 ( struct V_1 * V_1 )
{
char V_28 [ 64 ] ;
char * V_9 = NULL ;
T_3 V_29 ;
int V_26 = - 1 ;
if ( ! ( snprintf ( V_28 , sizeof( V_28 ) , L_2 ,
V_1 -> V_4 , V_1 -> V_5 ) >= ( int ) sizeof( V_28 ) ) &&
F_35 ( V_28 , & V_9 , & V_29 ) == 0 ) {
V_9 [ V_29 - 1 ] = '\0' ;
V_26 = F_36 ( V_1 , V_9 , 0 ) ;
}
return V_26 ;
}
const char * F_37 ( const struct V_1 * V_1 )
{
const struct V_9 * V_9 = F_26 ( V_1 ) ;
if ( ! V_9 )
return NULL ;
return F_38 ( V_9 ) ;
}
int F_39 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_30 ) {
const char * V_9 = F_37 ( V_1 ) ;
if ( ! V_9 )
return 0 ;
V_1 -> V_30 = strlen ( V_9 ) ;
}
return V_1 -> V_30 ;
}
T_3 F_40 ( struct V_1 * V_1 , T_4 * V_31 )
{
return fprintf ( V_31 , L_3 , V_1 -> V_5 , F_37 ( V_1 ) ) +
F_41 ( V_1 -> V_6 , V_31 ) ;
}
int F_42 ( struct V_1 * V_1 , struct V_32 * V_32 )
{
int V_33 ;
V_33 = F_43 ( V_1 , V_32 , NULL ) ;
if ( V_33 )
return V_33 ;
F_44 ( V_1 -> V_6 , V_32 , V_34 ) ;
F_45 ( V_1 -> V_6 , V_32 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 )
{
bool V_35 = false ;
int V_36 , V_26 = 0 ;
for ( V_36 = 0 ; V_36 < V_37 ; ++ V_36 ) {
struct V_38 * V_38 = & V_1 -> V_6 -> V_38 [ V_36 ] ;
struct V_32 * V_32 ;
F_47 ( & V_38 -> V_39 ) ;
for ( V_32 = F_48 ( V_38 ) ; V_32 ; V_32 = F_49 ( V_32 ) ) {
V_26 = F_43 ( V_1 , V_32 , & V_35 ) ;
if ( V_26 || V_35 )
break;
}
F_50 ( & V_38 -> V_39 ) ;
}
return V_26 ;
}
static int F_51 ( struct V_1 * V_1 )
{
int V_26 = 0 ;
if ( V_40 . V_41 )
V_26 = F_46 ( V_1 ) ;
return V_26 ;
}
static int F_52 ( struct V_1 * V_1 ,
struct V_1 * V_42 )
{
int V_36 ;
if ( V_1 -> V_4 == V_42 -> V_4 )
return F_51 ( V_1 ) ;
if ( V_1 -> V_6 == V_42 -> V_6 ) {
F_53 ( L_4 ,
V_1 -> V_4 , V_1 -> V_5 , V_42 -> V_4 , V_42 -> V_5 ) ;
return 0 ;
}
for ( V_36 = 0 ; V_36 < V_37 ; ++ V_36 )
if ( F_54 ( V_1 , V_42 -> V_6 , V_36 ) < 0 )
return - V_27 ;
return 0 ;
}
int F_55 ( struct V_1 * V_1 , struct V_1 * V_42 , T_2 V_22 )
{
if ( V_42 -> V_25 ) {
const char * V_9 = F_37 ( V_42 ) ;
int V_26 ;
if ( ! V_9 )
return - V_27 ;
V_26 = F_36 ( V_1 , V_9 , V_22 ) ;
if ( V_26 )
return V_26 ;
}
V_1 -> V_10 = V_42 -> V_5 ;
return F_52 ( V_1 , V_42 ) ;
}
void F_56 ( struct V_1 * V_1 ,
enum V_43 type , T_2 V_44 ,
struct V_45 * V_46 )
{
T_3 V_36 ;
const T_5 V_47 [] = {
V_48 ,
V_49 ,
V_50 ,
V_51
} ;
for ( V_36 = 0 ; V_36 < F_57 ( V_47 ) ; V_36 ++ ) {
F_58 ( V_1 , V_47 [ V_36 ] , type , V_44 , V_46 ) ;
if ( V_46 -> V_32 )
break;
}
}
struct V_1 * F_59 ( struct V_2 * V_2 , struct V_1 * V_1 )
{
if ( V_1 -> V_4 == V_1 -> V_5 )
return F_22 ( V_1 ) ;
if ( V_1 -> V_4 == - 1 )
return NULL ;
return F_60 ( V_2 , V_1 -> V_4 , V_1 -> V_4 ) ;
}
