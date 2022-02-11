static T_1
F_1 ( struct V_1 * V_1 , char * V_2 , T_1 V_3 ,
const char * V_4 , T_1 V_5 , int type )
{
const T_1 V_6 = sizeof( V_7 ) - 1 ;
const T_1 V_8 = V_6 + V_5 + 1 ;
if ( V_2 && V_8 <= V_3 ) {
memcpy ( V_2 , V_7 , V_6 ) ;
memcpy ( V_2 + V_6 , V_4 , V_5 ) ;
V_2 [ V_6 + V_5 ] = '\0' ;
}
return V_8 ;
}
static int
F_2 ( struct V_1 * V_1 , const char * V_4 ,
void * V_9 , T_1 V_10 , int type )
{
if ( strcmp ( V_4 , L_1 ) == 0 )
return - V_11 ;
return F_3 ( V_1 -> V_12 , V_13 ,
V_4 , V_9 , V_10 ) ;
}
static int
F_4 ( struct V_1 * V_1 , const char * V_4 ,
const void * V_14 , T_1 V_10 , int V_15 , int type )
{
if ( strcmp ( V_4 , L_1 ) == 0 )
return - V_11 ;
return F_5 ( V_1 -> V_12 , V_13 ,
V_4 , V_14 , V_10 , V_15 ) ;
}
static int
F_6 ( struct V_16 * V_16 , const struct V_17 * V_18 ,
void * V_19 )
{
const struct V_17 * V_17 ;
T_2 * V_20 = V_19 ;
int V_21 = 0 ;
for ( V_17 = V_18 ; V_17 -> V_4 != NULL ; V_17 ++ ) {
V_21 = F_7 ( V_20 , V_16 ,
V_13 ,
V_17 -> V_4 , V_17 -> V_14 ,
V_17 -> V_22 , 0 ) ;
if ( V_21 < 0 )
break;
}
return V_21 ;
}
int
F_8 ( T_2 * V_20 , struct V_16 * V_16 , struct V_16 * V_23 ,
const struct V_24 * V_24 )
{
return F_9 ( V_16 , V_23 , V_24 ,
& F_6 , V_20 ) ;
}
