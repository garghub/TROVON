static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , void * V_5 )
{
int V_6 ;
if ( V_4 > 1 )
V_6 = F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
else {
V_6 = F_3 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
* ( unsigned char * ) V_5 = ( unsigned char ) V_6 ;
}
return V_6 ;
}
static inline int F_4 ( struct V_1 * V_2 ,
int V_3 , int V_4 , void * V_7 )
{
unsigned char V_8 [ V_4 + 1 ] ;
int V_6 ;
V_8 [ 0 ] = ( unsigned char ) V_3 ;
memcpy ( & V_8 [ 1 ] , V_7 , V_4 ) ;
V_6 = F_5 ( V_2 , V_8 , V_4 + 1 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
unsigned char V_11 = 0 ;
int V_6 ;
F_8 ( & V_10 -> V_12 ) ;
V_6 = F_1 ( V_2 , V_3 , 1 , & V_11 ) ;
F_9 ( & V_10 -> V_12 ) ;
if ( V_6 < 0 )
return V_6 ;
else
return ( int ) V_11 ;
}
int F_10 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_11 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
int V_6 ;
F_8 ( & V_10 -> V_12 ) ;
V_6 = F_4 ( V_2 , V_3 , 1 , & V_11 ) ;
F_9 ( & V_10 -> V_12 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_2 , int V_3 ,
int V_13 , unsigned char * V_8 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
int V_6 ;
F_8 ( & V_10 -> V_12 ) ;
V_6 = F_1 ( V_2 , V_3 , V_13 , V_8 ) ;
F_9 ( & V_10 -> V_12 ) ;
return V_6 ;
}
int F_12 ( struct V_1 * V_2 , int V_3 ,
int V_13 , unsigned char * V_8 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
int V_6 ;
F_8 ( & V_10 -> V_12 ) ;
V_6 = F_4 ( V_2 , V_3 , V_13 , V_8 ) ;
F_9 ( & V_10 -> V_12 ) ;
return V_6 ;
}
int F_13 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_14 , unsigned char V_11 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
unsigned char V_15 ;
int V_6 ;
F_8 ( & V_10 -> V_12 ) ;
V_6 = F_1 ( V_2 , V_3 , 1 , & V_15 ) ;
if ( V_6 < 0 )
goto V_16;
V_15 &= ~ V_14 ;
V_15 |= V_11 ;
V_6 = F_4 ( V_2 , V_3 , 1 , & V_15 ) ;
V_16:
F_9 ( & V_10 -> V_12 ) ;
return V_6 ;
}
static int T_1 F_14 ( struct V_1 * V_17 ,
const struct V_18 * V_19 )
{
struct V_20 * V_21 = V_17 -> V_22 . V_23 ;
static struct V_9 * V_10 ;
if ( ! V_21 ) {
F_15 ( L_1 , V_24 ) ;
return - V_25 ;
}
V_10 = F_16 ( sizeof( struct V_9 ) , V_26 ) ;
if ( V_10 == NULL )
return - V_27 ;
V_10 -> V_2 = V_17 ;
V_10 -> V_22 = & V_17 -> V_22 ;
F_17 ( V_17 , V_10 ) ;
F_18 ( V_10 -> V_22 , V_10 ) ;
F_19 ( & V_10 -> V_12 ) ;
V_10 -> V_28 = F_20 ( V_10 -> V_2 -> V_29 , V_30 ) ;
F_17 ( V_10 -> V_28 , V_10 ) ;
V_10 -> V_31 = F_20 ( V_10 -> V_2 -> V_29 , V_32 ) ;
F_17 ( V_10 -> V_31 , V_10 ) ;
F_21 ( V_10 , V_21 ) ;
return 0 ;
}
static int T_2 F_22 ( struct V_1 * V_17 )
{
struct V_9 * V_10 = F_7 ( V_17 ) ;
F_23 ( V_10 ) ;
F_24 ( V_10 -> V_31 ) ;
F_24 ( V_10 -> V_28 ) ;
F_25 ( V_10 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
int V_6 ;
V_6 = F_27 ( & V_33 ) ;
if ( V_6 != 0 )
F_28 ( L_2 , V_6 ) ;
return V_6 ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_33 ) ;
}
