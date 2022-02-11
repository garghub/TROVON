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
int
F_6 ( T_2 * V_16 , struct V_17 * V_17 , struct V_17 * V_18 ,
const struct V_19 * V_19 )
{
int V_20 ;
T_1 V_21 ;
void * V_14 ;
char * V_4 ;
V_20 = F_7 ( V_17 , V_18 , V_19 , & V_4 , & V_14 , & V_21 ) ;
if ( V_20 ) {
if ( V_20 == - V_22 )
return 0 ;
return V_20 ;
}
V_20 = F_8 ( V_16 , V_17 , V_13 ,
V_4 , V_14 , V_21 , 0 ) ;
F_9 ( V_4 ) ;
F_9 ( V_14 ) ;
return V_20 ;
}
