static void F_1 ( void )
{
F_2 () ;
}
static void F_3 ( void )
{
F_4 () ;
}
static T_1 F_5 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
const struct V_5 * V_6 = F_6 ( V_4 ) ;
V_6 -> V_7 ( V_1 , V_2 ) ;
return F_7 ( 1 ) ;
}
static const void * F_8 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
const struct V_5 * V_6 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_9 ( V_11 ) ; V_10 ++ ) {
V_6 = & V_11 [ V_10 ] ;
if ( V_6 -> V_12 == V_9 -> V_13 &&
V_6 -> V_14 == V_9 -> V_15 )
return V_6 ;
}
return NULL ;
}
static int F_10 ( struct V_3 * V_4 ,
unsigned long V_16 )
{
struct V_8 * V_9 = F_11 ( V_4 ) ;
const struct V_5 * V_6 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 ;
V_6 = F_8 ( V_4 , V_9 ) ;
if ( ! V_6 )
return - V_22 ;
V_4 -> V_23 = V_6 ;
V_4 -> V_24 = V_6 -> V_25 ;
V_18 = F_12 ( sizeof( * V_18 ) , V_26 ) ;
if ( ! V_18 )
return - V_27 ;
V_4 -> V_28 = V_18 ;
V_21 = F_13 ( V_9 , V_4 -> V_24 ) ;
if ( V_21 )
return V_21 ;
if ( V_6 -> V_29 )
V_4 -> V_30 = F_14 ( V_9 , 1 ) ;
else
V_4 -> V_30 = F_14 ( V_9 , 0 ) ;
V_18 -> V_30 = V_4 -> V_30 ;
V_18 -> V_31 = F_14 ( V_9 , 0 ) ;
V_18 -> V_32 = F_14 ( V_9 , 2 ) ;
V_18 -> V_33 = F_14 ( V_9 , 3 ) ;
if ( V_9 -> V_1 > 0 ) {
V_21 = F_15 ( V_9 -> V_1 , F_5 , V_34 ,
V_4 -> V_24 , V_4 ) ;
if ( V_21 == 0 )
V_4 -> V_1 = V_9 -> V_1 ;
}
F_16 ( V_4 ) ;
V_18 -> V_35 . V_36 = F_14 ( V_9 , 2 ) ;
F_17 ( V_4 ) ;
return 0 ;
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_11 ( V_4 ) ;
if ( V_4 -> V_30 )
F_17 ( V_4 ) ;
if ( V_4 -> V_1 )
F_19 ( V_4 -> V_1 , V_4 ) ;
if ( V_9 ) {
if ( V_4 -> V_30 )
F_20 ( V_9 ) ;
}
}
static int F_21 ( struct V_8 * V_4 ,
const struct V_37 * V_38 )
{
return F_22 ( V_4 , & V_39 ) ;
}
static void F_23 ( struct V_8 * V_4 )
{
F_24 ( V_4 ) ;
}
