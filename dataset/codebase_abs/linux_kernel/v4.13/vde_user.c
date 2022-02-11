static int F_1 ( void * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_1 ;
T_1 * V_5 = NULL ;
int V_6 = - V_7 ;
V_4 -> V_2 = V_2 ;
V_5 = F_2 ( V_4 -> V_8 , V_4 -> V_9 , V_4 -> args ) ;
if ( V_5 == NULL ) {
V_6 = - V_10 ;
F_3 ( V_11 L_1
L_2 , V_10 ) ;
return V_6 ;
}
F_3 ( V_12 L_3 ) ;
V_4 -> V_5 = V_5 ;
return 0 ;
}
static int F_4 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_5 != NULL )
return F_5 ( V_4 -> V_5 ) ;
F_3 ( V_13 L_4 ) ;
return - V_7 ;
}
static void F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_5 != NULL ) {
F_3 ( V_12 L_5 ) ;
F_7 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
F_8 ( V_4 -> args ) ;
V_4 -> args = NULL ;
return;
}
F_3 ( V_13 L_6 ) ;
}
void F_9 ( struct V_3 * V_14 , struct V_15 * V_16 )
{
struct V_17 * args ;
V_14 -> args = F_10 ( sizeof( struct V_17 ) , V_18 ) ;
if ( V_14 -> args == NULL ) {
F_3 ( V_11 L_7
L_8 ) ;
return;
}
args = V_14 -> args ;
args -> V_19 = V_16 -> V_19 ;
args -> V_20 = V_16 -> V_20 ;
args -> V_21 = V_16 -> V_21 ? V_16 -> V_21 : 0700 ;
args -> V_19 ? F_3 ( L_9 , args -> V_19 ) :
F_3 ( L_10 ) ;
}
int F_11 ( void * V_5 , void * V_22 , int V_23 )
{
T_1 * V_24 = V_5 ;
int V_25 ;
if ( V_24 == NULL )
return 0 ;
V_25 = F_12 ( V_24 , V_22 , V_23 , 0 ) ;
if ( V_25 < 0 ) {
if ( V_10 == V_26 )
return 0 ;
return - V_10 ;
}
else if ( V_25 == 0 )
return - V_27 ;
return V_25 ;
}
int F_13 ( void * V_5 , void * V_22 , int V_23 )
{
T_1 * V_24 = V_5 ;
if ( V_24 == NULL )
return 0 ;
return F_14 ( V_24 , V_22 , V_23 , 0 ) ;
}
