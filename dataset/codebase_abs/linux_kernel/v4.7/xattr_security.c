static int
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_5 ,
const char * V_6 , void * V_7 , T_1 V_8 )
{
return F_2 ( V_5 , V_9 ,
V_6 , V_7 , V_8 ) ;
}
static int
F_3 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_5 ,
const char * V_6 , const void * V_10 ,
T_1 V_8 , int V_11 )
{
return F_4 ( V_5 , V_9 ,
V_6 , V_10 , V_8 , V_11 ) ;
}
static int
F_5 ( struct V_5 * V_5 , const struct V_12 * V_13 ,
void * V_14 )
{
const struct V_12 * V_12 ;
T_2 * V_15 = V_14 ;
int V_16 = 0 ;
for ( V_12 = V_13 ; V_12 -> V_6 != NULL ; V_12 ++ ) {
V_16 = F_6 ( V_15 , V_5 ,
V_9 ,
V_12 -> V_6 , V_12 -> V_10 ,
V_12 -> V_17 , 0 ) ;
if ( V_16 < 0 )
break;
}
return V_16 ;
}
int
F_7 ( T_2 * V_15 , struct V_5 * V_5 , struct V_5 * V_18 ,
const struct V_19 * V_19 )
{
return F_8 ( V_5 , V_18 , V_19 ,
& F_5 , V_15 ) ;
}
