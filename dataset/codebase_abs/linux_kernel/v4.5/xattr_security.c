static int
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_3 , const char * V_4 ,
void * V_5 , T_1 V_6 )
{
return F_2 ( F_3 ( V_3 ) , V_7 ,
V_4 , V_5 , V_6 ) ;
}
static int
F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_3 , const char * V_4 ,
const void * V_8 , T_1 V_6 , int V_9 )
{
return F_5 ( F_3 ( V_3 ) , V_7 ,
V_4 , V_8 , V_6 , V_9 ) ;
}
static int
F_6 ( struct V_10 * V_10 , const struct V_11 * V_12 ,
void * V_13 )
{
const struct V_11 * V_11 ;
T_2 * V_14 = V_13 ;
int V_15 = 0 ;
for ( V_11 = V_12 ; V_11 -> V_4 != NULL ; V_11 ++ ) {
V_15 = F_7 ( V_14 , V_10 ,
V_7 ,
V_11 -> V_4 , V_11 -> V_8 ,
V_11 -> V_16 , 0 ) ;
if ( V_15 < 0 )
break;
}
return V_15 ;
}
int
F_8 ( T_2 * V_14 , struct V_10 * V_10 , struct V_10 * V_17 ,
const struct V_18 * V_18 )
{
return F_9 ( V_10 , V_17 , V_18 ,
& F_6 , V_14 ) ;
}
