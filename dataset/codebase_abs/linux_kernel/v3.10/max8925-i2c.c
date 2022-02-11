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
static int F_14 ( struct V_17 * V_18 , struct V_19 * V_20 ,
struct V_21 * V_22 )
{
int V_6 ;
V_6 = F_15 ( V_18 , L_1 , & V_22 -> V_23 ) ;
if ( V_6 ) {
F_16 ( V_20 , L_2 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_25 ,
const struct V_26 * V_27 )
{
struct V_21 * V_22 = V_25 -> V_20 . V_28 ;
static struct V_9 * V_10 ;
struct V_17 * V_29 = V_25 -> V_20 . V_30 ;
if ( V_29 && ! V_22 ) {
V_22 = F_18 ( & V_25 -> V_20 ,
sizeof( struct V_21 ) ,
V_31 ) ;
if ( ! V_22 )
return - V_32 ;
if ( F_14 ( V_29 , & V_25 -> V_20 , V_22 ) )
return - V_24 ;
} else if ( ! V_22 ) {
F_19 ( L_3 , V_33 ) ;
return - V_24 ;
}
V_10 = F_20 ( sizeof( struct V_9 ) , V_31 ) ;
if ( V_10 == NULL )
return - V_32 ;
V_10 -> V_2 = V_25 ;
V_10 -> V_20 = & V_25 -> V_20 ;
F_21 ( V_25 , V_10 ) ;
F_22 ( V_10 -> V_20 , V_10 ) ;
F_23 ( & V_10 -> V_12 ) ;
V_10 -> V_34 = F_24 ( V_10 -> V_2 -> V_35 , V_36 ) ;
F_21 ( V_10 -> V_34 , V_10 ) ;
V_10 -> V_37 = F_24 ( V_10 -> V_2 -> V_35 , V_38 ) ;
F_21 ( V_10 -> V_37 , V_10 ) ;
F_25 ( & V_25 -> V_20 , 1 ) ;
F_26 ( V_10 , V_22 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_25 )
{
struct V_9 * V_10 = F_7 ( V_25 ) ;
F_28 ( V_10 ) ;
F_29 ( V_10 -> V_37 ) ;
F_29 ( V_10 -> V_34 ) ;
F_30 ( V_10 ) ;
return 0 ;
}
static int F_31 ( struct V_19 * V_20 )
{
struct V_1 * V_25 = F_32 ( V_20 , struct V_1 , V_20 ) ;
struct V_9 * V_10 = F_7 ( V_25 ) ;
if ( F_33 ( V_20 ) && V_10 -> V_39 )
F_34 ( V_10 -> V_40 ) ;
return 0 ;
}
static int F_35 ( struct V_19 * V_20 )
{
struct V_1 * V_25 = F_32 ( V_20 , struct V_1 , V_20 ) ;
struct V_9 * V_10 = F_7 ( V_25 ) ;
if ( F_33 ( V_20 ) && V_10 -> V_39 )
F_36 ( V_10 -> V_40 ) ;
return 0 ;
}
static int T_1 F_37 ( void )
{
int V_6 ;
V_6 = F_38 ( & V_41 ) ;
if ( V_6 != 0 )
F_39 ( L_4 , V_6 ) ;
return V_6 ;
}
static void T_2 F_40 ( void )
{
F_41 ( & V_41 ) ;
}
