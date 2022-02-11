int F_1 ( char * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
if ( V_9 )
return - V_10 ;
V_8 = F_2 ( V_11 , V_1 , V_3 , sizeof( struct V_9 ) ,
& V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_9 = V_7 -> V_12 ;
V_9 -> V_7 = V_7 ;
V_7 -> V_5 = V_5 ;
F_3 ( V_7 -> V_13 , L_1 , sizeof( V_7 -> V_13 ) ) ;
F_3 ( V_7 -> V_14 , V_1 , sizeof( V_7 -> V_14 ) ) ;
F_3 ( V_7 -> V_15 , V_1 , sizeof( V_7 -> V_15 ) ) ;
F_3 ( V_7 -> V_16 , V_1 , sizeof( V_7 -> V_16 ) ) ;
V_8 = F_4 ( V_9 -> V_7 ) ;
if ( V_8 < 0 ) {
F_5 ( V_17 L_2 ) ;
F_6 ( V_9 -> V_7 ) ;
V_9 = NULL ;
return V_8 ;
}
return 0 ;
}
struct V_6 * F_7 ( void )
{
if ( V_9 )
return V_9 -> V_7 ;
return NULL ;
}
void F_8 ( void )
{
if ( V_9 ) {
F_6 ( V_9 -> V_7 ) ;
V_9 = NULL ;
}
}
int F_9 ( T_1 type ,
void * V_18 , struct V_19 * V_20 )
{
struct V_6 * V_21 = F_7 () ;
int V_8 ;
if ( ! V_21 ) return - V_22 ;
V_8 = F_10 ( V_21 , type , V_18 , V_20 ) ;
if ( V_8 ) {
F_5 ( V_17 L_3 , V_8 ) ;
return V_8 ;
}
V_8 = F_11 ( V_21 , V_18 ) ;
if ( V_8 ) {
F_5 ( V_17 L_4
L_5 , V_8 ) ;
F_5 ( V_17 L_6
L_7 ) ;
F_12 ( V_21 , V_18 ) ;
}
return V_8 ;
}
int F_13 ( struct V_23 * V_24 )
{
int V_8 ;
if ( ! V_9 ) return - V_25 ;
V_8 = F_14 ( V_9 -> V_7 , V_24 ) ;
if ( V_8 )
F_5 ( V_17 L_8 ,
V_8 ) ;
return V_8 ;
}
