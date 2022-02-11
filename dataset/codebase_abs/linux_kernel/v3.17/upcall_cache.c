static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 , void * args )
{
struct V_1 * V_5 ;
F_2 ( V_5 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return NULL ;
F_3 ( V_5 ) ;
F_4 ( & V_5 -> V_6 ) ;
V_5 -> V_7 = V_4 ;
F_5 ( & V_5 -> V_8 , 0 ) ;
F_6 ( & V_5 -> V_9 ) ;
if ( V_3 -> V_10 -> V_11 )
V_3 -> V_10 -> V_11 ( V_5 , args ) ;
return V_5 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( V_3 -> V_10 -> F_7 )
V_3 -> V_10 -> F_7 ( V_3 , V_5 ) ;
F_8 ( & V_5 -> V_6 ) ;
F_9 ( V_12 , L_1 ,
V_5 , V_5 -> V_7 ) ;
F_10 ( V_5 , sizeof( * V_5 ) ) ;
}
static inline int F_11 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
T_1 V_4 , void * args )
{
if ( V_5 -> V_7 != V_4 )
return - 1 ;
if ( V_3 -> V_10 -> F_11 )
return V_3 -> V_10 -> F_11 ( V_3 , V_5 , V_4 , args ) ;
return 0 ;
}
static inline int F_12 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
T_1 V_4 , void * args )
{
if ( V_5 -> V_7 != V_4 )
return - 1 ;
if ( V_3 -> V_10 -> F_12 )
return V_3 -> V_10 -> F_12 ( V_3 , V_5 , V_4 , args ) ;
return 0 ;
}
static inline void F_13 ( struct V_1 * V_5 )
{
F_14 ( & V_5 -> V_8 ) ;
}
static inline void F_15 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( F_16 ( & V_5 -> V_8 ) &&
( F_17 ( V_5 ) || F_18 ( V_5 ) ) ) {
F_7 ( V_3 , V_5 ) ;
}
}
static int F_19 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( F_20 ( V_5 ) &&
F_21 ( F_22 () , V_5 -> V_13 ) )
return 0 ;
if ( F_23 ( V_5 ) ) {
if ( V_5 -> V_14 == 0 ||
F_21 ( F_22 () , V_5 -> V_14 ) )
return 0 ;
F_24 ( V_5 ) ;
F_25 ( & V_5 -> V_9 ) ;
} else if ( ! F_17 ( V_5 ) ) {
F_24 ( V_5 ) ;
}
F_26 ( & V_5 -> V_6 ) ;
if ( ! F_27 ( & V_5 -> V_8 ) )
F_7 ( V_3 , V_5 ) ;
return 1 ;
}
static inline int F_28 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
F_29 ( V_3 -> V_10 -> V_15 ) ;
return V_3 -> V_10 -> V_15 ( V_3 , V_5 ) ;
}
struct V_1 * F_30 ( struct V_2 * V_3 ,
T_1 V_4 , void * args )
{
struct V_1 * V_5 = NULL , * V_16 = NULL , * V_17 ;
struct V_18 * V_19 ;
T_2 V_20 ;
int V_21 , V_22 ;
F_29 ( V_3 ) ;
V_19 = & V_3 -> V_23 [ F_31 ( V_4 ) ] ;
V_24:
V_22 = 0 ;
F_32 ( & V_3 -> V_25 ) ;
F_33 (entry, next, head, ue_hash) {
if ( F_19 ( V_3 , V_5 ) )
continue;
if ( F_11 ( V_3 , V_5 , V_4 , args ) == 0 ) {
V_22 = 1 ;
break;
}
}
if ( ! V_22 ) {
if ( ! V_16 ) {
F_34 ( & V_3 -> V_25 ) ;
V_16 = F_1 ( V_3 , V_4 , args ) ;
if ( ! V_16 ) {
F_35 ( L_2 ) ;
return F_36 ( - V_26 ) ;
}
goto V_24;
} else {
F_37 ( & V_16 -> V_6 , V_19 ) ;
V_5 = V_16 ;
}
} else {
if ( V_16 ) {
F_7 ( V_3 , V_16 ) ;
V_16 = NULL ;
}
F_38 ( & V_5 -> V_6 , V_19 ) ;
}
F_13 ( V_5 ) ;
if ( F_39 ( V_5 ) ) {
F_40 ( V_5 ) ;
F_41 ( V_5 ) ;
F_34 ( & V_3 -> V_25 ) ;
V_21 = F_28 ( V_3 , V_5 ) ;
F_32 ( & V_3 -> V_25 ) ;
V_5 -> V_14 =
F_42 ( V_3 -> V_27 ) ;
if ( V_21 < 0 ) {
F_43 ( V_5 ) ;
F_44 ( V_5 ) ;
F_25 ( & V_5 -> V_9 ) ;
if ( F_45 ( V_21 == - V_28 ) ) {
F_15 ( V_3 , V_5 ) ;
GOTO ( V_29 , V_5 = F_36 ( V_21 ) ) ;
}
}
}
if ( F_23 ( V_5 ) ) {
long V_30 = ( V_5 == V_16 ) ?
F_46 ( V_3 -> V_27 ) :
V_31 ;
long V_32 ;
F_47 ( & V_20 , V_33 ) ;
F_48 ( & V_5 -> V_9 , & V_20 ) ;
F_49 ( V_34 ) ;
F_34 ( & V_3 -> V_25 ) ;
V_32 = F_50 ( V_30 ) ;
F_32 ( & V_3 -> V_25 ) ;
F_51 ( & V_5 -> V_9 , & V_20 ) ;
if ( F_23 ( V_5 ) ) {
V_21 = V_32 > 0 ? - V_35 : - V_36 ;
F_35 ( L_3 ,
V_5 -> V_7 , V_21 ) ;
F_15 ( V_3 , V_5 ) ;
GOTO ( V_29 , V_5 = F_36 ( V_21 ) ) ;
}
}
if ( F_17 ( V_5 ) ) {
F_15 ( V_3 , V_5 ) ;
GOTO ( V_29 , V_5 = F_36 ( - V_37 ) ) ;
}
if ( F_19 ( V_3 , V_5 ) ) {
if ( V_5 != V_16 ) {
F_15 ( V_3 , V_5 ) ;
F_34 ( & V_3 -> V_25 ) ;
V_16 = NULL ;
goto V_24;
}
}
V_29:
F_34 ( & V_3 -> V_25 ) ;
return V_5 ;
}
void F_52 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( ! V_5 ) {
return;
}
F_29 ( F_27 ( & V_5 -> V_8 ) > 0 ) ;
F_32 ( & V_3 -> V_25 ) ;
F_15 ( V_3 , V_5 ) ;
F_34 ( & V_3 -> V_25 ) ;
}
int F_53 ( struct V_2 * V_3 , T_3 V_38 , T_1 V_4 ,
void * args )
{
struct V_1 * V_5 = NULL ;
struct V_18 * V_19 ;
int V_22 = 0 , V_21 = 0 ;
F_29 ( V_3 ) ;
V_19 = & V_3 -> V_23 [ F_31 ( V_4 ) ] ;
F_32 ( & V_3 -> V_25 ) ;
F_54 (entry, head, ue_hash) {
if ( F_12 ( V_3 , V_5 , V_4 , args ) == 0 ) {
V_22 = 1 ;
F_13 ( V_5 ) ;
break;
}
}
if ( ! V_22 ) {
F_9 ( V_12 , L_4 ,
V_3 -> V_39 , V_4 ) ;
F_34 ( & V_3 -> V_25 ) ;
return - V_40 ;
}
if ( V_38 ) {
F_9 ( V_12 , L_5 ,
V_3 -> V_39 , V_5 -> V_7 , V_38 ) ;
GOTO ( V_29 , V_21 = - V_40 ) ;
}
if ( ! F_23 ( V_5 ) ) {
F_9 ( V_41 , L_6 ,
V_3 -> V_39 , V_5 , V_5 -> V_7 ) ;
GOTO ( V_29 , V_21 = 0 ) ;
}
if ( F_17 ( V_5 ) || F_18 ( V_5 ) ) {
F_35 ( L_7 ,
V_3 -> V_39 , V_5 , V_5 -> V_7 ) ;
GOTO ( V_29 , V_21 = - V_40 ) ;
}
F_34 ( & V_3 -> V_25 ) ;
if ( V_3 -> V_10 -> V_42 )
V_21 = V_3 -> V_10 -> V_42 ( V_3 , V_5 , args ) ;
F_32 ( & V_3 -> V_25 ) ;
if ( V_21 )
GOTO ( V_29 , V_21 ) ;
V_5 -> V_13 = F_42 ( V_3 -> V_43 ) ;
F_55 ( V_5 ) ;
F_9 ( V_12 , L_8 ,
V_3 -> V_39 , V_5 , V_5 -> V_7 ) ;
V_29:
if ( V_21 ) {
F_44 ( V_5 ) ;
F_26 ( & V_5 -> V_6 ) ;
}
F_43 ( V_5 ) ;
F_34 ( & V_3 -> V_25 ) ;
F_25 ( & V_5 -> V_9 ) ;
F_15 ( V_3 , V_5 ) ;
return V_21 ;
}
static void F_56 ( struct V_2 * V_3 , int V_44 )
{
struct V_1 * V_5 , * V_17 ;
int V_45 ;
F_32 ( & V_3 -> V_25 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
F_33 (entry, next,
&cache->uc_hashtable[i], ue_hash) {
if ( ! V_44 && F_27 ( & V_5 -> V_8 ) ) {
F_24 ( V_5 ) ;
continue;
}
F_29 ( ! F_27 ( & V_5 -> V_8 ) ) ;
F_7 ( V_3 , V_5 ) ;
}
}
F_34 ( & V_3 -> V_25 ) ;
}
void F_57 ( struct V_2 * V_3 )
{
F_56 ( V_3 , 0 ) ;
}
void F_58 ( struct V_2 * V_3 )
{
F_56 ( V_3 , 1 ) ;
}
void F_59 ( struct V_2 * V_3 , T_1 V_4 , void * args )
{
struct V_18 * V_19 ;
struct V_1 * V_5 ;
int V_22 = 0 ;
V_19 = & V_3 -> V_23 [ F_31 ( V_4 ) ] ;
F_32 ( & V_3 -> V_25 ) ;
F_54 (entry, head, ue_hash) {
if ( F_11 ( V_3 , V_5 , V_4 , args ) == 0 ) {
V_22 = 1 ;
break;
}
}
if ( V_22 ) {
F_60 ( L_9 ,
V_3 -> V_39 , V_5 , V_5 -> V_7 ,
F_27 ( & V_5 -> V_8 ) , V_5 -> V_47 ,
F_61 () , V_5 -> V_14 ,
V_5 -> V_13 ) ;
F_24 ( V_5 ) ;
if ( ! F_27 ( & V_5 -> V_8 ) )
F_7 ( V_3 , V_5 ) ;
}
F_34 ( & V_3 -> V_25 ) ;
}
struct V_2 * F_62 ( const char * V_48 , const char * V_49 ,
struct V_50 * V_51 )
{
struct V_2 * V_3 ;
int V_45 ;
F_2 ( V_3 , sizeof( * V_3 ) ) ;
if ( ! V_3 )
return F_36 ( - V_26 ) ;
F_63 ( & V_3 -> V_25 ) ;
F_64 ( & V_3 -> V_52 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ )
F_4 ( & V_3 -> V_23 [ V_45 ] ) ;
strncpy ( V_3 -> V_39 , V_48 , sizeof( V_3 -> V_39 ) - 1 ) ;
strncpy ( V_3 -> V_53 , V_49 , sizeof( V_3 -> V_53 ) - 1 ) ;
V_3 -> V_43 = 20 * 60 ;
V_3 -> V_27 = 30 ;
V_3 -> V_10 = V_51 ;
return V_3 ;
}
void F_65 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_58 ( V_3 ) ;
F_10 ( V_3 , sizeof( * V_3 ) ) ;
}
