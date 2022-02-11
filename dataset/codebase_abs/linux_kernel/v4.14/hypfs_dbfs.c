static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = V_3 ;
return V_4 ;
}
static void F_3 ( struct V_1 * V_4 )
{
V_4 -> V_6 -> V_7 ( V_4 -> V_8 ) ;
F_4 ( V_4 ) ;
}
static T_1 F_5 ( struct V_9 * V_9 , char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
struct V_1 * V_4 ;
struct V_2 * V_13 ;
T_1 V_14 ;
if ( * V_12 != 0 )
return 0 ;
V_13 = F_6 ( V_9 ) -> V_15 ;
F_7 ( & V_13 -> V_16 ) ;
V_4 = F_1 ( V_13 ) ;
if ( ! V_4 ) {
F_8 ( & V_13 -> V_16 ) ;
return - V_17 ;
}
V_14 = V_13 -> V_18 ( & V_4 -> V_10 , & V_4 -> V_8 , & V_4 -> V_11 ) ;
if ( V_14 ) {
F_8 ( & V_13 -> V_16 ) ;
F_4 ( V_4 ) ;
return V_14 ;
}
F_8 ( & V_13 -> V_16 ) ;
V_14 = F_9 ( V_10 , V_11 , V_12 , V_4 -> V_10 , V_4 -> V_11 ) ;
F_3 ( V_4 ) ;
return V_14 ;
}
static long F_10 ( struct V_9 * V_9 , unsigned int V_19 , unsigned long V_20 )
{
struct V_2 * V_13 = F_6 ( V_9 ) -> V_15 ;
long V_14 ;
F_7 ( & V_13 -> V_16 ) ;
if ( V_13 -> V_21 )
V_14 = V_13 -> V_21 ( V_9 , V_19 , V_20 ) ;
else
V_14 = - V_22 ;
F_8 ( & V_13 -> V_16 ) ;
return V_14 ;
}
int F_11 ( struct V_2 * V_13 )
{
V_13 -> V_23 = F_12 ( V_13 -> V_24 , 0400 , V_25 , V_13 ,
& V_26 ) ;
if ( F_13 ( V_13 -> V_23 ) )
return F_14 ( V_13 -> V_23 ) ;
F_15 ( & V_13 -> V_16 ) ;
return 0 ;
}
void F_16 ( struct V_2 * V_13 )
{
F_17 ( V_13 -> V_23 ) ;
}
int F_18 ( void )
{
V_25 = F_19 ( L_1 , NULL ) ;
return F_20 ( V_25 ) ;
}
void F_21 ( void )
{
F_17 ( V_25 ) ;
}
