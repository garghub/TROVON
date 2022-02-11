static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = 0 ;
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_6 = V_7 ;
V_2 -> V_3 . V_8 = V_9 ;
V_2 -> V_3 . V_10 = & V_11 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned long V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_3 ( sizeof( struct V_13 ) , V_16 ) ;
if ( ! V_14 ) {
F_4 ( L_1 ) ;
return - V_17 ;
}
V_2 -> V_18 = ( void * ) V_14 ;
V_14 -> V_19 = V_2 ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
V_15 = F_7 ( V_2 -> V_2 , V_2 ) ;
if ( V_15 )
return V_15 ;
F_8 ( V_2 ) ;
#ifdef F_9
F_10 ( V_2 , 32 ,
V_2 -> V_3 . V_20 ,
V_2 -> V_3 . V_21 ) ;
#endif
return 0 ;
}
static struct V_22 * F_11 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
int V_12 )
{
V_12 |= V_25 ;
return F_12 ( V_2 , V_24 , V_12 ) ;
}
static int F_13 ( struct V_26 * V_2 , void * V_27 )
{
return V_2 -> V_28 == V_27 ;
}
static int F_14 ( struct V_26 * V_2 )
{
return F_15 ( & V_29 , F_16 ( V_2 ) ) ;
}
static void F_17 ( struct V_26 * V_2 )
{
F_18 ( F_19 ( V_2 ) ) ;
}
static int F_20 ( struct V_30 * V_31 )
{
struct V_26 * V_2 = & V_31 -> V_2 ;
struct V_32 * V_33 = V_2 -> V_34 -> V_28 ;
struct V_32 * V_35 ;
struct V_36 * V_37 = NULL ;
F_21 ( V_2 , F_22 ( 32 ) ) ;
V_35 = F_23 ( V_33 , NULL ) ;
while ( V_35 ) {
F_24 ( V_2 , & V_37 , F_13 , V_35 ) ;
F_25 ( V_35 ) ;
V_35 = F_23 ( V_33 , V_35 ) ;
}
return F_26 ( V_2 , & V_38 , V_37 ) ;
}
static int F_27 ( struct V_30 * V_31 )
{
F_28 ( & V_31 -> V_2 , & V_38 ) ;
return 0 ;
}
static int F_29 ( struct V_30 * V_31 )
{
struct V_26 * V_2 = & V_31 -> V_2 ;
struct V_32 * V_33 = V_2 -> V_28 ;
struct V_30 * V_39 ;
F_30 ( V_33 , NULL , NULL , V_2 ) ;
F_31 ( & V_40 ) ;
V_39 = F_32 ( V_2 ,
V_41 L_2 , - 1 ,
NULL , 0 , NULL , 0 ) ;
if ( F_33 ( V_39 ) )
return F_34 ( V_39 ) ;
F_35 ( V_31 , V_39 ) ;
return 0 ;
}
static int F_36 ( struct V_30 * V_31 )
{
struct V_30 * V_39 = F_37 ( V_31 ) ;
F_38 ( & V_31 -> V_2 ) ;
F_39 ( V_39 ) ;
F_40 ( & V_40 ) ;
return 0 ;
}
