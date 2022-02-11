static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void T_1 F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_4 ( F_5 ( V_4 ) ) ) {
F_6 ( & V_5 ) ;
F_7 ( & V_4 -> V_6 , & V_7 ) ;
F_8 ( & V_5 ) ;
return;
}
F_9 ( V_4 ) ;
}
static int F_10 ( T_2 V_8 , T_2 V_9 ,
const char * type ,
struct V_1 * V_4 )
{
F_11 ( V_8 > V_9 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 - 1 ;
V_4 -> type = type ;
F_12 ( & V_4 -> V_6 ) ;
F_13 ( & V_4 -> V_3 , & V_10 ) ;
F_6 ( & V_11 ) ;
F_14 ( & V_4 -> V_6 , & V_12 ) ;
F_8 ( & V_11 ) ;
return 0 ;
}
static inline void F_15 ( struct V_1 * V_4 )
{
F_16 ( & V_4 -> V_6 ) ;
}
static int F_17 ( struct V_1 * V_4 )
{
static int V_13 ;
static struct V_14 * V_15 ;
if ( ! V_15 ) {
V_15 = F_18 ( L_1 , NULL , V_16 ) ;
if ( ! V_15 )
return - V_17 ;
}
V_4 -> V_3 . V_14 = V_15 ;
if ( F_19 ( & V_4 -> V_3 , NULL , L_2 , V_13 ++ ) )
F_20 ( & V_4 -> V_3 ) ;
return 0 ;
}
static inline void F_21 ( struct V_1 * V_4 )
{
F_20 ( & V_4 -> V_3 ) ;
}
static struct V_1 * T_1
F_22 ( T_2 V_8 , T_2 V_9 , const char * type ,
struct V_18 * V_6 )
{
struct V_1 * V_4 ;
F_23 (entry, list, list)
if ( ( V_4 -> V_8 == V_8 ) && ( V_4 -> V_9 == V_9 ) &&
( ! strcmp ( V_4 -> type , type ) ) ) {
return V_4 ;
}
return NULL ;
}
static struct V_1 * T_1
F_24 ( T_2 V_8 , T_2 V_9 , const char * type )
{
return F_22 ( V_8 , V_9 , type , & V_12 ) ;
}
static struct V_1 * T_1
F_25 ( T_2 V_8 , T_2 V_9 , const char * type )
{
return F_22 ( V_8 , V_9 , type ,
& V_7 ) ;
}
int T_1 F_26 ( T_2 V_8 , T_2 V_9 , const char * type )
{
struct V_1 * V_4 ;
V_4 = F_25 ( V_8 , V_9 , type ) ;
if ( ! V_4 ) {
V_4 = F_27 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_4 )
return - V_17 ;
} else {
F_6 ( & V_5 ) ;
F_16 ( & V_4 -> V_6 ) ;
F_8 ( & V_5 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
F_10 ( V_8 , V_9 , type , V_4 ) ;
F_17 ( V_4 ) ;
return 0 ;
}
int T_3 F_28 ( T_2 V_8 , T_2 V_9 , const char * type )
{
struct V_1 * V_4 ;
V_4 = F_29 ( sizeof( struct V_1 ) ) ;
if ( F_30 ( ! V_4 ) )
return - V_17 ;
return F_10 ( V_8 , V_9 , type , V_4 ) ;
}
int T_1 F_31 ( T_2 V_8 , T_2 V_9 , const char * type )
{
struct V_1 * V_4 ;
F_6 ( & V_11 ) ;
V_4 = F_24 ( V_8 , V_9 - 1 , type ) ;
if ( ! V_4 ) {
F_8 ( & V_11 ) ;
return - V_20 ;
}
F_15 ( V_4 ) ;
F_8 ( & V_11 ) ;
F_21 ( V_4 ) ;
return 0 ;
}
static T_4 F_32 ( struct V_1 * V_4 , char * V_21 )
{
return snprintf ( V_21 , V_22 , L_3 ,
( unsigned long long ) V_4 -> V_8 ) ;
}
static T_4 F_33 ( struct V_1 * V_4 , char * V_21 )
{
return snprintf ( V_21 , V_22 , L_3 ,
( unsigned long long ) V_4 -> V_9 ) ;
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
F_23 (entry, &map_entries, list)
F_17 ( V_4 ) ;
return 0 ;
}
