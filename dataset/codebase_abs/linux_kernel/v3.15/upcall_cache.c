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
F_9 ( V_12 , L_1 V_13 L_2 ,
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
F_21 ( F_22 () , V_5 -> V_14 ) )
return 0 ;
if ( F_23 ( V_5 ) ) {
if ( V_5 -> V_15 == 0 ||
F_21 ( F_22 () ,
V_5 -> V_15 ) )
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
F_29 ( V_3 -> V_10 -> V_16 ) ;
return V_3 -> V_10 -> V_16 ( V_3 , V_5 ) ;
}
struct V_1 * F_30 ( struct V_2 * V_3 ,
T_1 V_4 , void * args )
{
struct V_1 * V_5 = NULL , * V_17 = NULL , * V_18 ;
struct V_19 * V_20 ;
T_2 V_21 ;
int V_22 , V_23 ;
F_29 ( V_3 ) ;
V_20 = & V_3 -> V_24 [ F_31 ( V_4 ) ] ;
V_25:
V_23 = 0 ;
F_32 ( & V_3 -> V_26 ) ;
F_33 (entry, next, head, ue_hash) {
if ( F_19 ( V_3 , V_5 ) )
continue;
if ( F_11 ( V_3 , V_5 , V_4 , args ) == 0 ) {
V_23 = 1 ;
break;
}
}
if ( ! V_23 ) {
if ( ! V_17 ) {
F_34 ( & V_3 -> V_26 ) ;
V_17 = F_1 ( V_3 , V_4 , args ) ;
if ( ! V_17 ) {
F_35 ( L_3 ) ;
return F_36 ( - V_27 ) ;
}
goto V_25;
} else {
F_37 ( & V_17 -> V_6 , V_20 ) ;
V_5 = V_17 ;
}
} else {
if ( V_17 ) {
F_7 ( V_3 , V_17 ) ;
V_17 = NULL ;
}
F_38 ( & V_5 -> V_6 , V_20 ) ;
}
F_13 ( V_5 ) ;
if ( F_39 ( V_5 ) ) {
F_40 ( V_5 ) ;
F_41 ( V_5 ) ;
F_34 ( & V_3 -> V_26 ) ;
V_22 = F_28 ( V_3 , V_5 ) ;
F_32 ( & V_3 -> V_26 ) ;
V_5 -> V_15 =
F_42 ( V_3 -> V_28 ) ;
if ( V_22 < 0 ) {
F_43 ( V_5 ) ;
F_44 ( V_5 ) ;
F_25 ( & V_5 -> V_9 ) ;
if ( F_45 ( V_22 == - V_29 ) ) {
F_15 ( V_3 , V_5 ) ;
GOTO ( V_30 , V_5 = F_36 ( V_22 ) ) ;
}
}
}
if ( F_23 ( V_5 ) ) {
long V_31 = ( V_5 == V_17 ) ?
F_46 ( V_3 -> V_28 ) :
V_32 ;
long V_33 ;
F_47 ( & V_21 , V_34 ) ;
F_48 ( & V_5 -> V_9 , & V_21 ) ;
F_49 ( V_35 ) ;
F_34 ( & V_3 -> V_26 ) ;
V_33 = F_50 ( V_31 ) ;
F_32 ( & V_3 -> V_26 ) ;
F_51 ( & V_5 -> V_9 , & V_21 ) ;
if ( F_23 ( V_5 ) ) {
V_22 = V_33 > 0 ? - V_36 : - V_37 ;
F_35 ( L_4 V_13 L_5 ,
V_5 -> V_7 , V_22 ) ;
F_15 ( V_3 , V_5 ) ;
GOTO ( V_30 , V_5 = F_36 ( V_22 ) ) ;
}
}
if ( F_17 ( V_5 ) ) {
F_15 ( V_3 , V_5 ) ;
GOTO ( V_30 , V_5 = F_36 ( - V_38 ) ) ;
}
if ( F_19 ( V_3 , V_5 ) ) {
if ( V_5 != V_17 ) {
F_15 ( V_3 , V_5 ) ;
F_34 ( & V_3 -> V_26 ) ;
V_17 = NULL ;
goto V_25;
}
}
V_30:
F_34 ( & V_3 -> V_26 ) ;
return V_5 ;
}
void F_52 ( struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( ! V_5 ) {
return;
}
F_29 ( F_27 ( & V_5 -> V_8 ) > 0 ) ;
F_32 ( & V_3 -> V_26 ) ;
F_15 ( V_3 , V_5 ) ;
F_34 ( & V_3 -> V_26 ) ;
}
int F_53 ( struct V_2 * V_3 , T_3 V_39 , T_1 V_4 ,
void * args )
{
struct V_1 * V_5 = NULL ;
struct V_19 * V_20 ;
int V_23 = 0 , V_22 = 0 ;
F_29 ( V_3 ) ;
V_20 = & V_3 -> V_24 [ F_31 ( V_4 ) ] ;
F_32 ( & V_3 -> V_26 ) ;
F_54 (entry, head, ue_hash) {
if ( F_12 ( V_3 , V_5 , V_4 , args ) == 0 ) {
V_23 = 1 ;
F_13 ( V_5 ) ;
break;
}
}
if ( ! V_23 ) {
F_9 ( V_12 , L_6 V_13 L_7 ,
V_3 -> V_40 , V_4 ) ;
F_34 ( & V_3 -> V_26 ) ;
return - V_41 ;
}
if ( V_39 ) {
F_9 ( V_12 , L_6 V_13 L_8 ,
V_3 -> V_40 , V_5 -> V_7 , V_39 ) ;
GOTO ( V_30 , V_22 = - V_41 ) ;
}
if ( ! F_23 ( V_5 ) ) {
F_9 ( V_42 , L_9 V_13 L_10 ,
V_3 -> V_40 , V_5 , V_5 -> V_7 ) ;
GOTO ( V_30 , V_22 = 0 ) ;
}
if ( F_17 ( V_5 ) || F_18 ( V_5 ) ) {
F_35 ( L_11 V_13 L_12 ,
V_3 -> V_40 , V_5 , V_5 -> V_7 ) ;
GOTO ( V_30 , V_22 = - V_41 ) ;
}
F_34 ( & V_3 -> V_26 ) ;
if ( V_3 -> V_10 -> V_43 )
V_22 = V_3 -> V_10 -> V_43 ( V_3 , V_5 , args ) ;
F_32 ( & V_3 -> V_26 ) ;
if ( V_22 )
GOTO ( V_30 , V_22 ) ;
V_5 -> V_14 = F_42 ( V_3 -> V_44 ) ;
F_55 ( V_5 ) ;
F_9 ( V_12 , L_13 V_13 L_2 ,
V_3 -> V_40 , V_5 , V_5 -> V_7 ) ;
V_30:
if ( V_22 ) {
F_44 ( V_5 ) ;
F_26 ( & V_5 -> V_6 ) ;
}
F_43 ( V_5 ) ;
F_34 ( & V_3 -> V_26 ) ;
F_25 ( & V_5 -> V_9 ) ;
F_15 ( V_3 , V_5 ) ;
return V_22 ;
}
static void F_56 ( struct V_2 * V_3 , int V_45 )
{
struct V_1 * V_5 , * V_18 ;
int V_46 ;
F_32 ( & V_3 -> V_26 ) ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
F_33 (entry, next,
&cache->uc_hashtable[i], ue_hash) {
if ( ! V_45 && F_27 ( & V_5 -> V_8 ) ) {
F_24 ( V_5 ) ;
continue;
}
F_29 ( ! F_27 ( & V_5 -> V_8 ) ) ;
F_7 ( V_3 , V_5 ) ;
}
}
F_34 ( & V_3 -> V_26 ) ;
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
struct V_19 * V_20 ;
struct V_1 * V_5 ;
int V_23 = 0 ;
V_20 = & V_3 -> V_24 [ F_31 ( V_4 ) ] ;
F_32 ( & V_3 -> V_26 ) ;
F_54 (entry, head, ue_hash) {
if ( F_11 ( V_3 , V_5 , V_4 , args ) == 0 ) {
V_23 = 1 ;
break;
}
}
if ( V_23 ) {
F_60 ( L_14 V_13 L_15
L_16 ,
V_3 -> V_40 , V_5 , V_5 -> V_7 ,
F_27 ( & V_5 -> V_8 ) , V_5 -> V_48 ,
F_61 () , V_5 -> V_15 ,
V_5 -> V_14 ) ;
F_24 ( V_5 ) ;
if ( ! F_27 ( & V_5 -> V_8 ) )
F_7 ( V_3 , V_5 ) ;
}
F_34 ( & V_3 -> V_26 ) ;
}
struct V_2 * F_62 ( const char * V_49 , const char * V_50 ,
struct V_51 * V_52 )
{
struct V_2 * V_3 ;
int V_46 ;
F_2 ( V_3 , sizeof( * V_3 ) ) ;
if ( ! V_3 )
return F_36 ( - V_27 ) ;
F_63 ( & V_3 -> V_26 ) ;
F_64 ( & V_3 -> V_53 ) ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ )
F_4 ( & V_3 -> V_24 [ V_46 ] ) ;
strncpy ( V_3 -> V_40 , V_49 , sizeof( V_3 -> V_40 ) - 1 ) ;
strncpy ( V_3 -> V_54 , V_50 , sizeof( V_3 -> V_54 ) - 1 ) ;
V_3 -> V_44 = 20 * 60 ;
V_3 -> V_28 = 30 ;
V_3 -> V_10 = V_52 ;
return V_3 ;
}
void F_65 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_58 ( V_3 ) ;
F_10 ( V_3 , sizeof( * V_3 ) ) ;
}
