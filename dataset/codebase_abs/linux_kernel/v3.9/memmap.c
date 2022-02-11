static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void T_1 F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_4 ( F_5 ( V_4 ) ) ) {
if ( F_6 ( V_4 -> V_5 , V_4 -> V_6 ,
V_4 -> type ) ) {
F_7 ( & V_7 ) ;
F_8 ( & V_4 -> V_8 , & V_9 ) ;
F_9 ( & V_7 ) ;
}
return;
}
F_10 ( V_4 ) ;
}
static int F_11 ( T_2 V_5 , T_2 V_6 ,
const char * type ,
struct V_1 * V_4 )
{
F_12 ( V_5 > V_6 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_6 = V_6 - 1 ;
V_4 -> type = type ;
F_13 ( & V_4 -> V_8 ) ;
F_14 ( & V_4 -> V_3 , & V_10 ) ;
F_7 ( & V_11 ) ;
F_15 ( & V_4 -> V_8 , & V_12 ) ;
F_9 ( & V_11 ) ;
return 0 ;
}
static inline void F_16 ( struct V_1 * V_4 )
{
F_17 ( & V_4 -> V_8 ) ;
}
static int F_18 ( struct V_1 * V_4 )
{
static int V_13 ;
static struct V_14 * V_15 ;
if ( ! V_15 ) {
V_15 = F_19 ( L_1 , NULL , V_16 ) ;
if ( ! V_15 )
return - V_17 ;
}
V_4 -> V_3 . V_14 = V_15 ;
if ( F_20 ( & V_4 -> V_3 , NULL , L_2 , V_13 ++ ) )
F_21 ( & V_4 -> V_3 ) ;
return 0 ;
}
static inline void F_22 ( struct V_1 * V_4 )
{
F_21 ( & V_4 -> V_3 ) ;
}
static struct V_1 * T_1
F_23 ( T_2 V_5 , T_2 V_6 , const char * type ,
struct V_18 * V_8 )
{
struct V_1 * V_4 ;
F_24 (entry, list, list)
if ( ( V_4 -> V_5 == V_5 ) && ( V_4 -> V_6 == V_6 ) &&
( ! strcmp ( V_4 -> type , type ) ) ) {
return V_4 ;
}
return NULL ;
}
static struct V_1 * T_1
F_6 ( T_2 V_5 , T_2 V_6 , const char * type )
{
return F_23 ( V_5 , V_6 , type , & V_12 ) ;
}
static struct V_1 * T_1
F_25 ( T_2 V_5 , T_2 V_6 , const char * type )
{
return F_23 ( V_5 , V_6 , type ,
& V_9 ) ;
}
int T_1 F_26 ( T_2 V_5 , T_2 V_6 , const char * type )
{
struct V_1 * V_4 ;
V_4 = F_25 ( V_5 , V_6 , type ) ;
if ( ! V_4 ) {
V_4 = F_27 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_4 )
return - V_17 ;
} else {
F_7 ( & V_7 ) ;
F_17 ( & V_4 -> V_8 ) ;
F_9 ( & V_7 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
F_11 ( V_5 , V_6 , type , V_4 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
int T_3 F_28 ( T_2 V_5 , T_2 V_6 , const char * type )
{
struct V_1 * V_4 ;
V_4 = F_29 ( sizeof( struct V_1 ) ) ;
if ( F_30 ( ! V_4 ) )
return - V_17 ;
return F_11 ( V_5 , V_6 , type , V_4 ) ;
}
int T_1 F_31 ( T_2 V_5 , T_2 V_6 , const char * type )
{
struct V_1 * V_4 ;
F_7 ( & V_11 ) ;
V_4 = F_6 ( V_5 , V_6 - 1 , type ) ;
if ( ! V_4 ) {
F_9 ( & V_11 ) ;
return - V_20 ;
}
F_16 ( V_4 ) ;
F_9 ( & V_11 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
static T_4 F_32 ( struct V_1 * V_4 , char * V_21 )
{
return snprintf ( V_21 , V_22 , L_3 ,
( unsigned long long ) V_4 -> V_5 ) ;
}
static T_4 F_33 ( struct V_1 * V_4 , char * V_21 )
{
return snprintf ( V_21 , V_22 , L_3 ,
( unsigned long long ) V_4 -> V_6 ) ;
}
static T_4 F_34 ( struct V_1 * V_4 , char * V_21 )
{
return snprintf ( V_21 , V_22 , L_4 , V_4 -> type ) ;
}
static inline struct V_23 * F_35 ( struct V_24 * V_25 )
{
return F_2 ( V_25 , struct V_23 , V_25 ) ;
}
static T_4 F_36 ( struct V_2 * V_3 ,
struct V_24 * V_25 , char * V_21 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_23 * V_26 = F_35 ( V_25 ) ;
return V_26 -> V_27 ( V_4 , V_21 ) ;
}
static int T_3 F_37 ( void )
{
struct V_1 * V_4 ;
F_24 (entry, &map_entries, list)
F_18 ( V_4 ) ;
return 0 ;
}
