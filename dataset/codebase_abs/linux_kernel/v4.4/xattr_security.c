static T_1
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_3 , char * V_4 , T_1 V_5 ,
const char * V_6 , T_1 V_7 )
{
const T_1 V_8 = sizeof( V_9 ) - 1 ;
const T_1 V_10 = V_8 + V_7 + 1 ;
if ( V_4 && V_10 <= V_5 ) {
memcpy ( V_4 , V_9 , V_8 ) ;
memcpy ( V_4 + V_8 , V_6 , V_7 ) ;
V_4 [ V_8 + V_7 ] = '\0' ;
}
return V_10 ;
}
static int
F_2 ( const struct V_1 * V_2 ,
struct V_3 * V_3 , const char * V_6 ,
void * V_11 , T_1 V_12 )
{
if ( strcmp ( V_6 , L_1 ) == 0 )
return - V_13 ;
return F_3 ( F_4 ( V_3 ) , V_14 ,
V_6 , V_11 , V_12 ) ;
}
static int
F_5 ( const struct V_1 * V_2 ,
struct V_3 * V_3 , const char * V_6 ,
const void * V_15 , T_1 V_12 , int V_16 )
{
if ( strcmp ( V_6 , L_1 ) == 0 )
return - V_13 ;
return F_6 ( F_4 ( V_3 ) , V_14 ,
V_6 , V_15 , V_12 , V_16 ) ;
}
static int
F_7 ( struct V_17 * V_17 , const struct V_18 * V_19 ,
void * V_20 )
{
const struct V_18 * V_18 ;
T_2 * V_21 = V_20 ;
int V_22 = 0 ;
for ( V_18 = V_19 ; V_18 -> V_6 != NULL ; V_18 ++ ) {
V_22 = F_8 ( V_21 , V_17 ,
V_14 ,
V_18 -> V_6 , V_18 -> V_15 ,
V_18 -> V_23 , 0 ) ;
if ( V_22 < 0 )
break;
}
return V_22 ;
}
int
F_9 ( T_2 * V_21 , struct V_17 * V_17 , struct V_17 * V_24 ,
const struct V_25 * V_25 )
{
return F_10 ( V_17 , V_24 , V_25 ,
& F_7 , V_21 ) ;
}
