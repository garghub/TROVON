static inline int F_1 ( void * V_1 )
{
return ( (struct V_2 * ) V_1 ) -> V_3 ;
}
static inline int F_2 ( void * V_1 )
{
return ( (struct V_2 * ) V_1 ) -> V_4 ;
}
static void F_3 ( void * V_1 , int V_5 )
{
int V_6 = 5000 ;
if ( V_5 ) {
F_4 ( F_1 ( V_1 ) , V_7 ) ;
while( ! F_5 ( F_1 ( V_1 ) ) && V_6 -- ) ;
} else {
F_4 ( F_1 ( V_1 ) , V_8 ) ;
}
}
static void F_6 ( void * V_1 , int V_5 )
{
if ( V_5 ) {
F_4 ( F_2 ( V_1 ) , V_7 ) ;
} else {
F_4 ( F_2 ( V_1 ) , V_8 ) ;
}
}
static int F_7 ( void * V_1 )
{
return F_5 ( F_1 ( V_1 ) ) ;
}
static int F_8 ( void * V_1 )
{
return F_5 ( F_2 ( V_1 ) ) ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_10 ( V_10 ) ;
F_11 ( V_10 , NULL ) ;
F_12 ( & V_12 -> V_13 ) ;
F_13 ( V_12 ) ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 )
{
int V_14 ;
struct V_2 * V_15 = V_10 -> V_16 . V_17 ;
struct V_11 * V_12 =
F_15 ( sizeof( struct V_11 ) , V_18 ) ;
if ( ! V_12 )
return - V_19 ;
V_12 -> V_20 = V_15 ;
V_12 -> V_21 . V_1 = V_15 ;
V_12 -> V_21 . V_22 = F_6 ;
V_12 -> V_21 . V_23 = F_3 ;
V_12 -> V_21 . V_24 = F_8 ;
V_12 -> V_21 . V_25 = F_7 ;
V_12 -> V_21 . V_26 = 6 ;
V_12 -> V_21 . V_27 = V_28 ;
F_16 ( V_12 -> V_13 . V_29 , V_10 -> V_16 . V_30 -> V_29 ,
sizeof( V_12 -> V_13 . V_29 ) ) ;
V_12 -> V_13 . V_21 = & V_12 -> V_21 ,
V_12 -> V_13 . V_16 . V_31 = & V_10 -> V_16 ;
F_4 ( V_15 -> V_4 , V_7 ) ;
F_4 ( V_15 -> V_3 , V_7 ) ;
F_17 ( V_15 -> V_3 , 0 ) ;
F_17 ( V_15 -> V_4 , 0 ) ;
if ( ( V_14 = F_18 ( & V_12 -> V_13 ) ) != 0 ) {
F_19 ( & V_10 -> V_16 , L_1 , V_14 ) ;
F_13 ( V_12 ) ;
return V_14 ;
}
F_11 ( V_10 , V_12 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_32 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_32 ) ;
}
