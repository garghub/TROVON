static void * F_1 ( struct V_1 * V_2 )
{
char * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_7 -> V_8 -> V_6 ;
V_3 = ( V_3 - ( char * ) & V_9 ) + ( char * ) V_6 ;
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
return F_3 ( & V_14 , V_10 , V_11 , V_12 , V_13 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
return F_5 ( & V_14 , V_10 , V_11 , V_12 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_5 * V_15 = V_7 -> V_8 -> V_6 ;
int V_16 = F_4 ( V_2 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_15 -> V_17 )
F_7 ( V_15 ) ;
return V_16 ;
}
static int F_8 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
T_2 V_18 = * V_12 ;
int V_19 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
V_19 = F_5 ( & V_14 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && ! V_19 && V_18 == * V_12 )
F_9 ( V_7 -> V_8 -> V_6 ) ;
return V_19 ;
}
static int F_10 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
return F_11 ( & V_14 , V_10 , V_11 ,
V_12 , V_13 ) ;
}
static void F_12 ( int V_20 )
{
if ( ! V_20 )
F_9 ( V_7 -> V_8 -> V_6 ) ;
else {
F_13 ( V_7 -> V_8 -> V_6 ) ;
F_14 ( V_7 -> V_8 -> V_6 ) ;
}
}
static int F_15 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
T_2 V_18 = * V_12 ;
int V_21 ;
int V_19 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
V_21 = * ( ( int * ) ( V_14 . V_4 ) ) ;
V_19 = F_5 ( & V_14 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_10 && ! V_19 && V_18 == * V_12 ) {
int V_22 = * ( ( int * ) ( V_14 . V_4 ) ) ;
if ( V_22 != V_21 )
F_12 ( V_22 ) ;
}
return V_19 ;
}
static int T_4 F_16 ( void )
{
F_17 ( V_23 ) ;
return 0 ;
}
