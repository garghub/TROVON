static int F_1 ( struct V_1 * V_1 ,
const struct V_2 * V_3 , void * V_4 )
{
const struct V_2 * V_2 ;
int V_5 = 0 ;
for ( V_2 = V_3 ; V_2 -> V_6 != NULL ; V_2 ++ ) {
V_5 = F_2 ( V_1 , V_7 ,
V_2 -> V_6 , V_2 -> V_8 ,
V_2 -> V_9 , 0 ) ;
if ( V_5 < 0 )
break;
}
return V_5 ;
}
int F_3 ( struct V_1 * V_1 , struct V_1 * V_10 ,
const struct V_11 * V_11 )
{
return F_4 ( V_1 , V_10 , V_11 ,
& F_1 , NULL ) ;
}
static int F_5 ( const struct V_12 * V_13 ,
struct V_14 * V_14 , const char * V_6 ,
void * V_15 , T_1 V_16 )
{
return F_6 ( F_7 ( V_14 ) , V_7 ,
V_6 , V_15 , V_16 ) ;
}
static int F_8 ( const struct V_12 * V_13 ,
struct V_14 * V_14 , const char * V_6 ,
const void * V_15 , T_1 V_16 , int V_17 )
{
return F_2 ( F_7 ( V_14 ) , V_7 ,
V_6 , V_15 , V_16 , V_17 ) ;
}
