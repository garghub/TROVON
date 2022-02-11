static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
F_3 ( & V_4 -> V_6 ) ;
V_4 -> V_7 = V_3 ;
return V_4 ;
}
static void F_4 ( struct V_6 * V_6 )
{
struct V_1 * V_4 ;
V_4 = F_5 ( V_6 , struct V_1 , V_6 ) ;
V_4 -> V_7 -> V_8 ( V_4 -> V_9 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_4 ;
struct V_2 * V_12 ;
V_12 = F_5 ( V_11 , struct V_2 , V_13 . V_11 ) ;
F_8 ( & V_12 -> V_14 ) ;
V_4 = V_12 -> V_4 ;
V_12 -> V_4 = NULL ;
F_9 ( & V_12 -> V_14 ) ;
F_10 ( & V_4 -> V_6 , F_4 ) ;
}
static T_1 F_11 ( struct V_15 * V_15 , char T_2 * V_16 ,
T_3 V_17 , T_4 * V_18 )
{
struct V_1 * V_4 ;
struct V_2 * V_12 ;
T_1 V_19 ;
if ( * V_18 != 0 )
return 0 ;
V_12 = F_12 ( V_15 ) -> V_20 ;
F_8 ( & V_12 -> V_14 ) ;
if ( ! V_12 -> V_4 ) {
V_4 = F_1 ( V_12 ) ;
if ( ! V_4 ) {
F_9 ( & V_12 -> V_14 ) ;
return - V_21 ;
}
V_19 = V_12 -> V_22 ( & V_4 -> V_16 , & V_4 -> V_9 ,
& V_4 -> V_17 ) ;
if ( V_19 ) {
F_9 ( & V_12 -> V_14 ) ;
F_6 ( V_4 ) ;
return V_19 ;
}
V_12 -> V_4 = V_4 ;
F_13 ( & V_12 -> V_13 , V_23 ) ;
}
V_4 = V_12 -> V_4 ;
F_14 ( & V_4 -> V_6 ) ;
F_9 ( & V_12 -> V_14 ) ;
V_19 = F_15 ( V_16 , V_17 , V_18 , V_4 -> V_16 , V_4 -> V_17 ) ;
F_10 ( & V_4 -> V_6 , F_4 ) ;
return V_19 ;
}
static long F_16 ( struct V_15 * V_15 , unsigned int V_24 , unsigned long V_25 )
{
struct V_2 * V_12 = F_12 ( V_15 ) -> V_20 ;
long V_19 ;
F_8 ( & V_12 -> V_14 ) ;
if ( V_12 -> V_26 )
V_19 = V_12 -> V_26 ( V_15 , V_24 , V_25 ) ;
else
V_19 = - V_27 ;
F_9 ( & V_12 -> V_14 ) ;
return V_19 ;
}
int F_17 ( struct V_2 * V_12 )
{
V_12 -> V_28 = F_18 ( V_12 -> V_29 , 0400 , V_30 , V_12 ,
& V_31 ) ;
if ( F_19 ( V_12 -> V_28 ) )
return F_20 ( V_12 -> V_28 ) ;
F_21 ( & V_12 -> V_14 ) ;
F_22 ( & V_12 -> V_13 , F_7 ) ;
return 0 ;
}
void F_23 ( struct V_2 * V_12 )
{
F_24 ( V_12 -> V_28 ) ;
}
int F_25 ( void )
{
V_30 = F_26 ( L_1 , NULL ) ;
return F_27 ( V_30 ) ;
}
void F_28 ( void )
{
F_24 ( V_30 ) ;
}
