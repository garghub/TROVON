static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static unsigned int F_3 ( unsigned int V_4 )
{
switch ( V_4 ) {
case V_5 : return 3 ;
case V_6 : return 4 ;
default: return 0 ;
}
}
static int F_4 ( struct V_2 * V_3 , const void * V_7 ,
unsigned int V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_10 V_11 ;
unsigned int V_12 ;
if ( F_5 ( V_7 , V_8 , & V_11 ) < 0 )
return - V_13 ;
V_12 = F_3 ( V_11 . V_4 ) ;
if ( ! V_12 )
return - V_13 ;
V_9 -> V_4 = V_11 . V_4 ;
V_9 -> V_12 = V_12 ;
if ( F_6 ( V_9 -> V_4 , V_9 -> V_12 ,
( const V_14 * ) V_11 . V_15 , V_11 . V_16 ) < 0 )
return - V_13 ;
memcpy ( V_9 -> V_17 , V_11 . V_15 , V_11 . V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
int V_20 = 0 ;
struct V_2 * V_3 = F_8 ( V_19 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_1 V_21 , V_22 ;
void * V_7 ;
V_22 = V_9 -> V_12 << V_23 ;
if ( V_19 -> V_24 ) {
V_21 = F_9 ( V_19 -> V_24 , 1 , V_9 -> V_25 ,
2 * V_22 ) ;
if ( V_21 != 2 * V_22 )
return - V_13 ;
V_20 = F_10 ( V_9 -> V_4 , V_9 -> V_12 ,
( const V_14 * ) V_9 -> V_17 , V_22 ,
( const V_14 * ) V_9 -> V_25 , 2 * V_22 ,
( V_14 * ) V_9 -> V_26 , V_22 ) ;
V_7 = V_9 -> V_26 ;
} else {
V_20 = F_11 ( V_9 -> V_4 , V_9 -> V_12 ,
( const V_14 * ) V_9 -> V_17 , V_22 ,
( V_14 * ) V_9 -> V_25 ,
sizeof( V_9 -> V_25 ) ) ;
V_7 = V_9 -> V_25 ;
V_22 *= 2 ;
}
if ( V_20 < 0 )
return V_20 ;
V_21 = F_12 ( V_19 -> V_27 , 1 , V_7 , V_22 ) ;
if ( V_21 != V_22 )
return - V_13 ;
return V_20 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_22 = V_9 -> V_12 << V_23 ;
return 2 * V_22 ;
}
static void F_14 ( struct V_2 * V_3 )
{
return;
}
static int F_15 ( void )
{
return F_16 ( & V_10 ) ;
}
static void F_17 ( void )
{
F_18 ( & V_10 ) ;
}
