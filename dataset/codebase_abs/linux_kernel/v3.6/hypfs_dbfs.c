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
V_12 = V_15 -> V_20 . V_21 -> V_22 -> V_23 ;
F_8 ( & V_12 -> V_14 ) ;
if ( ! V_12 -> V_4 ) {
V_4 = F_1 ( V_12 ) ;
if ( ! V_4 ) {
F_9 ( & V_12 -> V_14 ) ;
return - V_24 ;
}
V_19 = V_12 -> V_25 ( & V_4 -> V_16 , & V_4 -> V_9 ,
& V_4 -> V_17 ) ;
if ( V_19 ) {
F_9 ( & V_12 -> V_14 ) ;
F_6 ( V_4 ) ;
return V_19 ;
}
V_12 -> V_4 = V_4 ;
F_12 ( & V_12 -> V_13 , V_26 ) ;
}
V_4 = V_12 -> V_4 ;
F_13 ( & V_4 -> V_6 ) ;
F_9 ( & V_12 -> V_14 ) ;
V_19 = F_14 ( V_16 , V_17 , V_18 , V_4 -> V_16 , V_4 -> V_17 ) ;
F_10 ( & V_4 -> V_6 , F_4 ) ;
return V_19 ;
}
int F_15 ( struct V_2 * V_12 )
{
V_12 -> V_21 = F_16 ( V_12 -> V_27 , 0400 , V_28 , V_12 ,
& V_29 ) ;
if ( F_17 ( V_12 -> V_21 ) )
return F_18 ( V_12 -> V_21 ) ;
F_19 ( & V_12 -> V_14 ) ;
F_20 ( & V_12 -> V_13 , F_7 ) ;
return 0 ;
}
void F_21 ( struct V_2 * V_12 )
{
F_22 ( V_12 -> V_21 ) ;
}
int F_23 ( void )
{
V_28 = F_24 ( L_1 , NULL ) ;
if ( F_17 ( V_28 ) )
return F_18 ( V_28 ) ;
return 0 ;
}
void F_25 ( void )
{
F_22 ( V_28 ) ;
}
