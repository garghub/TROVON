static int F_1 ( struct V_1 * V_2 , const void * V_3 ,
T_1 V_4 )
{
void * V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 ) {
V_5 = F_3 ( V_4 + V_6 ) ;
if ( ! V_5 )
return - V_7 ;
memcpy ( V_5 , V_3 , V_4 ) ;
F_4 ( V_2 , V_5 + V_4 , V_6 ) ;
F_5 ( V_2 -> V_8 , V_5 , V_4 + V_6 , V_9 ) ;
}
return 0 ;
}
static int F_6 ( struct V_10 * V_11 ,
const struct V_12 * V_13 ,
void * V_3 )
{
F_7 ( V_14 , L_1 , V_11 -> V_15 ) ;
return F_1 ( V_11 -> V_16 -> V_17 , V_3 ,
V_13 -> V_18 ) ;
}
void F_8 ( void )
{
V_19 = F_9 ( V_20 , NULL ) ;
if ( F_10 ( V_19 ) )
V_19 = NULL ;
}
void F_11 ( void )
{
if ( ! V_19 )
return;
F_12 ( V_19 ) ;
V_19 = NULL ;
}
int F_13 ( struct V_21 * V_16 )
{
struct V_22 * V_8 = V_16 -> V_17 -> V_8 ;
if ( ! V_19 )
return - V_23 ;
V_16 -> V_24 = F_9 ( F_14 ( V_8 ) , V_19 ) ;
if ( F_10 ( V_16 -> V_24 ) )
return F_15 ( V_16 -> V_24 ) ;
return F_16 ( V_16 , V_25 ,
F_6 ) ;
}
void F_17 ( struct V_21 * V_16 )
{
F_18 ( V_16 , V_25 ) ;
if ( ! F_19 ( V_16 -> V_24 ) )
F_12 ( V_16 -> V_24 ) ;
}
struct V_26 * F_20 ( struct V_21 * V_16 )
{
return V_16 -> V_24 ;
}
int F_21 ( struct V_21 * V_16 , const char * V_27 ,
int (* F_22)( struct V_28 * V_29 , void * V_3 ) )
{
struct V_26 * V_30 ;
V_30 = F_23 ( V_16 -> V_17 -> V_8 , V_27 ,
V_16 -> V_24 , F_22 ) ;
return F_24 ( V_30 ) ;
}
