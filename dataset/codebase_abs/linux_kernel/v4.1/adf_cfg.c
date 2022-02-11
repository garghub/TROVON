static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( & V_7 ) ;
return F_3 ( & V_5 -> V_8 , * V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , void * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 =
F_5 ( V_9 , struct V_12 , V_11 ) ;
F_6 ( V_2 , L_1 , V_13 -> V_14 ) ;
F_7 (list, &sec->param_head) {
struct V_15 * V_16 =
F_5 ( V_11 , struct V_15 , V_11 ) ;
F_6 ( V_2 , L_2 , V_16 -> V_17 , V_16 -> V_18 ) ;
}
return 0 ;
}
static void * F_8 ( struct V_1 * V_2 , void * V_9 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_9 ( V_9 , & V_5 -> V_8 , V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_9 )
{
F_11 ( & V_7 ) ;
}
static int F_12 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
int V_21 = F_13 ( V_20 , & V_22 ) ;
if ( ! V_21 ) {
struct V_1 * V_23 = V_20 -> V_24 ;
V_23 -> V_6 = V_19 -> V_25 ;
}
return V_21 ;
}
int F_14 ( struct V_26 * V_27 )
{
struct V_4 * V_28 ;
V_28 = F_15 ( sizeof( * V_28 ) , V_29 ) ;
if ( ! V_28 )
return - V_30 ;
F_16 ( & V_28 -> V_8 ) ;
F_17 ( & V_28 -> V_31 ) ;
V_27 -> V_32 = V_28 ;
V_28 -> V_33 = F_18 ( L_3 , V_34 ,
V_27 -> V_35 ,
V_28 ,
& V_36 ) ;
if ( ! V_28 -> V_33 ) {
F_19 ( & F_20 ( V_27 ) ,
L_4 ) ;
F_21 ( V_28 ) ;
V_27 -> V_32 = NULL ;
return - V_37 ;
}
return 0 ;
}
void F_22 ( struct V_26 * V_27 )
{
struct V_4 * V_28 = V_27 -> V_32 ;
F_23 ( & V_28 -> V_31 ) ;
F_24 ( & V_28 -> V_8 ) ;
F_25 ( & V_28 -> V_31 ) ;
F_26 ( V_38 , & V_27 -> V_39 ) ;
}
void F_27 ( struct V_26 * V_27 )
{
struct V_4 * V_28 = V_27 -> V_32 ;
F_23 ( & V_28 -> V_31 ) ;
F_24 ( & V_28 -> V_8 ) ;
F_25 ( & V_28 -> V_31 ) ;
F_28 ( V_28 -> V_33 ) ;
F_21 ( V_28 ) ;
V_27 -> V_32 = NULL ;
}
static void F_29 ( struct V_15 * V_40 ,
struct V_12 * V_13 )
{
F_30 ( & V_40 -> V_11 , & V_13 -> V_41 ) ;
}
static void F_31 ( struct V_10 * V_42 )
{
struct V_10 * V_43 , * V_44 ;
F_32 (list_ptr, tmp, head) {
struct V_15 * V_16 =
F_5 ( V_43 , struct V_15 , V_11 ) ;
F_33 ( V_43 ) ;
F_21 ( V_16 ) ;
}
}
static void F_24 ( struct V_10 * V_42 )
{
struct V_12 * V_16 ;
struct V_10 * V_11 , * V_44 ;
F_32 (list, tmp, head) {
V_16 = F_5 ( V_11 , struct V_12 , V_11 ) ;
F_31 ( & V_16 -> V_41 ) ;
F_33 ( V_11 ) ;
F_21 ( V_16 ) ;
}
}
static struct V_15 * F_34 ( struct V_12 * V_45 ,
const char * V_17 )
{
struct V_10 * V_11 ;
F_7 (list, &s->param_head) {
struct V_15 * V_16 =
F_5 ( V_11 , struct V_15 , V_11 ) ;
if ( ! strcmp ( V_16 -> V_17 , V_17 ) )
return V_16 ;
}
return NULL ;
}
static struct V_12 * F_35 ( struct V_26 * V_27 ,
const char * V_46 )
{
struct V_4 * V_32 = V_27 -> V_32 ;
struct V_10 * V_11 ;
F_7 (list, &cfg->sec_list) {
struct V_12 * V_16 =
F_5 ( V_11 , struct V_12 , V_11 ) ;
if ( ! strcmp ( V_16 -> V_14 , V_46 ) )
return V_16 ;
}
return NULL ;
}
static int F_36 ( struct V_26 * V_27 ,
const char * V_46 ,
const char * V_47 ,
char * V_18 )
{
struct V_12 * V_13 = F_35 ( V_27 , V_46 ) ;
struct V_15 * V_48 = NULL ;
if ( V_13 )
V_48 = F_34 ( V_13 , V_47 ) ;
if ( V_48 ) {
memcpy ( V_18 , V_48 -> V_18 , V_49 ) ;
return 0 ;
}
return - 1 ;
}
int F_37 ( struct V_26 * V_27 ,
const char * V_50 ,
const char * V_17 , const void * V_18 ,
enum V_51 type )
{
struct V_4 * V_32 = V_27 -> V_32 ;
struct V_15 * V_52 ;
struct V_12 * V_53 = F_35 ( V_27 ,
V_50 ) ;
if ( ! V_53 )
return - V_37 ;
V_52 = F_15 ( sizeof( * V_52 ) , V_29 ) ;
if ( ! V_52 )
return - V_30 ;
F_16 ( & V_52 -> V_11 ) ;
F_38 ( V_52 -> V_17 , V_17 , sizeof( V_52 -> V_17 ) ) ;
if ( type == V_54 ) {
snprintf ( V_52 -> V_18 , V_49 ,
L_5 , ( * ( ( long * ) V_18 ) ) ) ;
} else if ( type == V_55 ) {
F_38 ( V_52 -> V_18 , ( char * ) V_18 , sizeof( V_52 -> V_18 ) ) ;
} else if ( type == V_56 ) {
snprintf ( V_52 -> V_18 , V_49 ,
L_6 , ( unsigned long ) V_18 ) ;
} else {
F_19 ( & F_20 ( V_27 ) , L_7 ) ;
F_21 ( V_52 ) ;
return - 1 ;
}
V_52 -> type = type ;
F_23 ( & V_32 -> V_31 ) ;
F_29 ( V_52 , V_53 ) ;
F_25 ( & V_32 -> V_31 ) ;
return 0 ;
}
int F_39 ( struct V_26 * V_27 , const char * V_14 )
{
struct V_4 * V_32 = V_27 -> V_32 ;
struct V_12 * V_13 = F_35 ( V_27 , V_14 ) ;
if ( V_13 )
return 0 ;
V_13 = F_15 ( sizeof( * V_13 ) , V_29 ) ;
if ( ! V_13 )
return - V_30 ;
F_38 ( V_13 -> V_14 , V_14 , sizeof( V_13 -> V_14 ) ) ;
F_16 ( & V_13 -> V_41 ) ;
F_23 ( & V_32 -> V_31 ) ;
F_30 ( & V_13 -> V_11 , & V_32 -> V_8 ) ;
F_25 ( & V_32 -> V_31 ) ;
return 0 ;
}
int F_40 ( struct V_26 * V_27 ,
const char * V_53 , const char * V_14 ,
char * V_57 )
{
struct V_4 * V_32 = V_27 -> V_32 ;
int V_21 ;
F_41 ( & V_32 -> V_31 ) ;
V_21 = F_36 ( V_27 , V_53 , V_14 , V_57 ) ;
F_42 ( & V_32 -> V_31 ) ;
return V_21 ;
}
