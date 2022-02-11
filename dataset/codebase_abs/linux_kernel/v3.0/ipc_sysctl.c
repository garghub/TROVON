static void * F_1 ( T_1 * V_1 )
{
char * V_2 = V_1 -> V_3 ;
struct V_4 * V_5 = V_6 -> V_7 -> V_5 ;
V_2 = ( V_2 - ( char * ) & V_8 ) + ( char * ) V_5 ;
return V_2 ;
}
static int F_2 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
return F_3 ( & V_13 , V_9 , V_10 , V_11 , V_12 ) ;
}
static int F_4 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
T_3 V_14 = * V_11 ;
int V_15 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
V_15 = F_3 ( & V_13 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_9 && ! V_15 && V_14 == * V_11 )
F_5 ( V_6 -> V_7 -> V_5 ) ;
return V_15 ;
}
static int F_6 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
return F_7 ( & V_13 , V_9 , V_10 ,
V_11 , V_12 ) ;
}
static void F_8 ( int V_16 )
{
if ( ! V_16 )
F_5 ( V_6 -> V_7 -> V_5 ) ;
else {
F_9 ( V_6 -> V_7 -> V_5 ) ;
F_10 ( V_6 -> V_7 -> V_5 ) ;
}
}
static int F_11 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
T_3 V_14 = * V_11 ;
int V_17 ;
int V_15 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
V_17 = * ( ( int * ) ( V_13 . V_3 ) ) ;
V_15 = F_12 ( & V_13 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_9 && ! V_15 && V_14 == * V_11 ) {
int V_18 = * ( ( int * ) ( V_13 . V_3 ) ) ;
if ( V_18 != V_17 )
F_8 ( V_18 ) ;
}
return V_15 ;
}
static int T_5 F_13 ( void )
{
F_14 ( V_19 ) ;
return 0 ;
}
