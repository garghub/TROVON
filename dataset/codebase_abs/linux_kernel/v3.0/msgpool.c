static void * F_1 ( T_1 V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
void * V_5 ;
V_5 = F_2 ( 0 , V_4 -> V_6 , V_1 ) ;
if ( ! V_5 )
F_3 ( L_1 , V_4 -> V_7 ) ;
return V_5 ;
}
static void F_4 ( void * V_8 , void * V_2 )
{
F_5 ( V_8 ) ;
}
int F_6 ( struct V_3 * V_4 ,
int V_6 , int V_9 , bool V_10 , const char * V_7 )
{
V_4 -> V_6 = V_6 ;
V_4 -> V_4 = F_7 ( V_9 , F_1 , F_4 , V_4 ) ;
if ( ! V_4 -> V_4 )
return - V_11 ;
V_4 -> V_7 = V_7 ;
return 0 ;
}
void F_8 ( struct V_3 * V_4 )
{
F_9 ( V_4 -> V_4 ) ;
}
struct V_12 * F_10 ( struct V_3 * V_4 ,
int V_6 )
{
if ( V_6 > V_4 -> V_6 ) {
F_3 ( L_2 ,
V_4 -> V_7 , V_6 , V_4 -> V_6 ) ;
F_11 ( 1 ) ;
return F_2 ( 0 , V_6 , V_13 ) ;
}
return F_12 ( V_4 -> V_4 , V_13 ) ;
}
void F_13 ( struct V_3 * V_4 , struct V_12 * V_14 )
{
V_14 -> V_15 . V_16 = V_4 -> V_6 ;
V_14 -> V_17 . V_6 = F_14 ( V_4 -> V_6 ) ;
F_15 ( & V_14 -> V_18 ) ;
}
