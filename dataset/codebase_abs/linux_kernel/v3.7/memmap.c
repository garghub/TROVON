static int F_1 ( T_1 V_1 , T_1 V_2 ,
const char * type ,
struct V_3 * V_4 )
{
F_2 ( V_1 > V_2 ) ;
V_4 -> V_1 = V_1 ;
V_4 -> V_2 = V_2 - 1 ;
V_4 -> type = type ;
F_3 ( & V_4 -> V_5 ) ;
F_4 ( & V_4 -> V_6 , & V_7 ) ;
F_5 ( & V_4 -> V_5 , & V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 )
{
static int V_9 ;
static struct V_10 * V_11 ;
if ( ! V_11 ) {
V_11 = F_7 ( L_1 , NULL , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
}
V_4 -> V_6 . V_10 = V_11 ;
if ( F_8 ( & V_4 -> V_6 , NULL , L_2 , V_9 ++ ) )
F_9 ( & V_4 -> V_6 ) ;
return 0 ;
}
int T_2 F_10 ( T_1 V_1 , T_1 V_2 , const char * type )
{
struct V_3 * V_4 ;
V_4 = F_11 ( sizeof( struct V_3 ) , V_14 ) ;
if ( ! V_4 )
return - V_13 ;
F_1 ( V_1 , V_2 , type , V_4 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
int T_3 F_12 ( T_1 V_1 , T_1 V_2 , const char * type )
{
struct V_3 * V_4 ;
V_4 = F_13 ( sizeof( struct V_3 ) ) ;
if ( F_14 ( ! V_4 ) )
return - V_13 ;
return F_1 ( V_1 , V_2 , type , V_4 ) ;
}
static T_4 F_15 ( struct V_3 * V_4 , char * V_15 )
{
return snprintf ( V_15 , V_16 , L_3 ,
( unsigned long long ) V_4 -> V_1 ) ;
}
static T_4 F_16 ( struct V_3 * V_4 , char * V_15 )
{
return snprintf ( V_15 , V_16 , L_3 ,
( unsigned long long ) V_4 -> V_2 ) ;
}
static T_4 F_17 ( struct V_3 * V_4 , char * V_15 )
{
return snprintf ( V_15 , V_16 , L_4 , V_4 -> type ) ;
}
static T_4 F_18 ( struct V_17 * V_6 ,
struct V_18 * V_19 , char * V_15 )
{
struct V_3 * V_4 = F_19 ( V_6 ) ;
struct V_20 * V_21 = F_20 ( V_19 ) ;
return V_21 -> V_22 ( V_4 , V_15 ) ;
}
static int T_3 F_21 ( void )
{
struct V_3 * V_4 ;
F_22 (entry, &map_entries, list)
F_6 ( V_4 ) ;
return 0 ;
}
