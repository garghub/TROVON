static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
T_1 * V_8 = ( T_1 * ) V_4 ;
int V_9 ;
unsigned long V_10 = 1 << 23 | V_2 << 15 | * V_8 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
T_2 V_15 ;
V_15 = V_10 ;
V_12 . V_15 = & V_15 ;
V_12 . V_16 = NULL ;
V_12 . V_17 = sizeof( unsigned long ) ;
V_12 . V_18 = 24 ;
F_2 ( & V_14 ) ;
F_3 ( & V_12 , & V_14 ) ;
V_9 = F_4 ( V_6 , & V_14 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_1 , T_1 V_2 ,
int V_3 , void * V_19 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
unsigned long V_10 = 0 << 23 | V_2 << 15 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
int V_9 ;
T_1 * V_8 = ( T_1 * ) V_19 ;
T_2 V_15 , V_16 ;
V_15 = V_10 ;
V_16 = 0 ;
V_12 . V_15 = & V_15 ;
V_12 . V_16 = & V_16 ;
V_12 . V_17 = sizeof( unsigned long ) ;
V_12 . V_18 = 24 ;
F_2 ( & V_14 ) ;
F_3 ( & V_12 , & V_14 ) ;
if ( V_6 == NULL )
return 0 ;
V_9 = F_4 ( V_6 , & V_14 ) ;
if ( V_9 == 0 )
* V_8 = ( T_1 ) ( V_16 & 0xFF ) ;
return V_9 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_1 ;
V_1 = F_7 ( & V_6 -> V_20 ,
sizeof( struct V_1 ) , V_21 ) ;
if ( V_1 == NULL )
return - V_22 ;
V_1 -> V_20 = & V_6 -> V_20 ;
V_1 -> V_7 = V_6 ;
V_1 -> V_23 = F_5 ;
V_1 -> V_24 = F_1 ;
F_8 ( V_6 , V_1 ) ;
return F_9 ( V_1 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_11 ( V_6 ) ;
F_12 ( V_1 ) ;
return 0 ;
}
static int T_3 F_13 ( void )
{
int V_9 ;
V_9 = F_14 ( & V_25 ) ;
if ( V_9 != 0 )
F_15 ( L_1 , V_9 ) ;
return 0 ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_25 ) ;
}
