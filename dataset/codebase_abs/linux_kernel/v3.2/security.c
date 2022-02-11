int F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 ,
void * V_4 )
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
static int F_5 ( struct V_12 * V_12 , const char * V_6 ,
void * V_13 , T_1 V_14 , int type )
{
if ( ! strcmp ( V_6 , L_1 ) )
return - V_15 ;
return F_6 ( V_12 -> V_16 , V_7 ,
V_6 , V_13 , V_14 ) ;
}
static int F_7 ( struct V_12 * V_12 , const char * V_6 ,
const void * V_13 , T_1 V_14 , int V_17 , int type )
{
if ( ! strcmp ( V_6 , L_1 ) )
return - V_15 ;
return F_2 ( V_12 -> V_16 , V_7 ,
V_6 , V_13 , V_14 , V_17 ) ;
}
static T_1 F_8 ( struct V_12 * V_12 , char * V_18 ,
T_1 V_19 , const char * V_6 , T_1 V_20 , int type )
{
T_1 V_21 = V_22 + V_20 + 1 ;
if ( V_18 && V_21 <= V_19 ) {
strcpy ( V_18 , V_23 ) ;
strcpy ( V_18 + V_22 , V_6 ) ;
}
return V_21 ;
}
