int F_1 ( void * V_1 )
{
int V_2 ;
struct V_3 * V_4 = V_1 ;
F_2 ( L_1 , V_5 ) ;
if ( V_4 -> V_6 == 1 )
return 0 ;
V_2 = F_3 ( V_4 -> V_7 ) ;
if ( V_2 < 0 ) {
F_4 ( L_2 ) ;
return V_2 ;
}
V_2 = F_5 ( V_4 -> V_7 , V_8 , V_4 ) ;
if ( V_2 ) {
F_4 ( L_3 ) ;
F_6 ( V_4 -> V_7 ) ;
V_4 -> V_6 = 0 ;
return V_2 ;
}
V_4 -> V_6 = 1 ;
return 0 ;
}
void F_7 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
F_2 ( L_1 , V_5 ) ;
F_6 ( V_4 -> V_7 ) ;
V_4 -> V_6 = 0 ;
}
static int F_8 ( void * V_1 , struct V_9 * V_10 )
{
struct V_3 * V_4 = V_1 ;
int V_2 ;
F_9 ( L_4 , V_10 ) ;
V_2 = F_10 ( V_4 -> V_7 , V_10 -> V_11 , V_10 -> V_12 ) ;
if ( V_2 > 0 )
V_2 = 0 ;
return V_2 ;
}
void V_8 ( struct V_13 * V_7 , T_1 V_14 , void * V_15 )
{
struct V_3 * V_4 = V_15 ;
if ( V_4 -> V_16 != 0 )
return;
if ( V_14 & F_11 ( V_17 ) ) {
struct V_9 * V_10 ;
int V_18 ;
V_10 = F_12 ( V_19 , V_20 ) ;
if ( ! V_10 )
return;
V_18 = F_13 ( V_7 , V_10 -> V_11 , V_19 ) ;
if ( V_18 < V_21 ) {
F_14 ( V_10 ) ;
return;
}
F_15 ( V_10 , V_18 ) ;
F_16 ( V_10 , V_21 ) ;
F_17 ( L_5 , V_10 ) ;
F_18 ( V_4 -> V_22 , V_10 ) ;
}
}
struct V_3 * F_19 ( struct V_13 * V_7 )
{
struct V_3 * V_4 ;
V_4 = F_20 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 = V_7 ;
F_21 ( V_7 , V_4 ) ;
return V_4 ;
}
void F_22 ( struct V_3 * V_4 )
{
F_14 ( V_4 ) ;
}
