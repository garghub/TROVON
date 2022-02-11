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
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
return F_5 ( & V_13 , V_9 , V_10 , V_11 , V_12 ) ;
}
static int F_6 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct V_4 * V_14 = V_6 -> V_7 -> V_5 ;
int V_15 = F_4 ( V_1 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_14 -> V_16 )
F_7 ( V_14 ) ;
return V_15 ;
}
static int F_8 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
T_3 V_17 = * V_11 ;
int V_18 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
V_18 = F_3 ( & V_13 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_9 && ! V_18 && V_17 == * V_11 )
F_9 ( V_6 -> V_7 -> V_5 ) ;
return V_18 ;
}
static int F_10 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
return F_11 ( & V_13 , V_9 , V_10 ,
V_11 , V_12 ) ;
}
static void F_12 ( int V_19 )
{
if ( ! V_19 )
F_9 ( V_6 -> V_7 -> V_5 ) ;
else {
F_13 ( V_6 -> V_7 -> V_5 ) ;
F_14 ( V_6 -> V_7 -> V_5 ) ;
}
}
static int F_15 ( T_1 * V_1 , int V_9 ,
void T_2 * V_10 , T_3 * V_11 , T_4 * V_12 )
{
struct T_1 V_13 ;
T_3 V_17 = * V_11 ;
int V_20 ;
int V_18 ;
memcpy ( & V_13 , V_1 , sizeof( V_13 ) ) ;
V_13 . V_3 = F_1 ( V_1 ) ;
V_20 = * ( ( int * ) ( V_13 . V_3 ) ) ;
V_18 = F_5 ( & V_13 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_9 && ! V_18 && V_17 == * V_11 ) {
int V_21 = * ( ( int * ) ( V_13 . V_3 ) ) ;
if ( V_21 != V_20 )
F_12 ( V_21 ) ;
}
return V_18 ;
}
static int T_5 F_16 ( void )
{
F_17 ( V_22 ) ;
return 0 ;
}
