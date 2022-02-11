static void * F_1 ( T_1 V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 -> type , V_4 -> V_7 , V_1 , true ) ;
if ( ! V_6 ) {
F_3 ( L_1 , V_4 -> V_8 ) ;
} else {
F_3 ( L_2 , V_4 -> V_8 , V_6 ) ;
V_6 -> V_4 = V_4 ;
}
return V_6 ;
}
static void F_4 ( void * V_9 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_9 ;
F_3 ( L_3 , V_4 -> V_8 , V_6 ) ;
V_6 -> V_4 = NULL ;
F_5 ( V_6 ) ;
}
int F_6 ( struct V_3 * V_4 , int type ,
int V_7 , int V_10 , bool V_11 , const char * V_8 )
{
F_3 ( L_4 , V_8 ) ;
V_4 -> type = type ;
V_4 -> V_7 = V_7 ;
V_4 -> V_4 = F_7 ( V_10 , F_1 , F_4 , V_4 ) ;
if ( ! V_4 -> V_4 )
return - V_12 ;
V_4 -> V_8 = V_8 ;
return 0 ;
}
void F_8 ( struct V_3 * V_4 )
{
F_3 ( L_5 , V_4 -> V_8 ) ;
F_9 ( V_4 -> V_4 ) ;
}
struct V_5 * F_10 ( struct V_3 * V_4 ,
int V_7 )
{
struct V_5 * V_6 ;
if ( V_7 > V_4 -> V_7 ) {
F_3 ( L_6 ,
V_4 -> V_8 , V_7 , V_4 -> V_7 ) ;
F_11 ( 1 ) ;
return F_2 ( V_4 -> type , V_7 , V_13 , false ) ;
}
V_6 = F_12 ( V_4 -> V_4 , V_13 ) ;
F_3 ( L_7 , V_4 -> V_8 , V_6 ) ;
return V_6 ;
}
void F_13 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
F_3 ( L_8 , V_4 -> V_8 , V_6 ) ;
V_6 -> V_14 . V_15 = V_4 -> V_7 ;
V_6 -> V_16 . V_7 = F_14 ( V_4 -> V_7 ) ;
F_15 ( & V_6 -> V_17 ) ;
F_16 ( V_6 , V_4 -> V_4 ) ;
}
