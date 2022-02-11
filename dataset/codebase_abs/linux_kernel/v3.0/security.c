int F_1 ( struct V_1 * V_1 , struct V_1 * V_2 ,
const struct V_3 * V_3 )
{
int V_4 ;
T_1 V_5 ;
void * V_6 ;
char * V_7 ;
V_4 = F_2 ( V_1 , V_2 , V_3 , & V_7 , & V_6 , & V_5 ) ;
if ( V_4 ) {
if ( V_4 == - V_8 )
return 0 ;
return V_4 ;
}
V_4 = F_3 ( V_1 , V_9 , V_7 , V_6 , V_5 , 0 ) ;
F_4 ( V_7 ) ;
F_4 ( V_6 ) ;
return V_4 ;
}
static int F_5 ( struct V_10 * V_10 , const char * V_7 ,
void * V_11 , T_1 V_12 , int type )
{
if ( ! strcmp ( V_7 , L_1 ) )
return - V_13 ;
return F_6 ( V_10 -> V_14 , V_9 ,
V_7 , V_11 , V_12 ) ;
}
static int F_7 ( struct V_10 * V_10 , const char * V_7 ,
const void * V_11 , T_1 V_12 , int V_15 , int type )
{
if ( ! strcmp ( V_7 , L_1 ) )
return - V_13 ;
return F_3 ( V_10 -> V_14 , V_9 ,
V_7 , V_11 , V_12 , V_15 ) ;
}
static T_1 F_8 ( struct V_10 * V_10 , char * V_16 ,
T_1 V_17 , const char * V_7 , T_1 V_18 , int type )
{
T_1 V_19 = V_20 + V_18 + 1 ;
if ( V_16 && V_19 <= V_17 ) {
strcpy ( V_16 , V_21 ) ;
strcpy ( V_16 + V_20 , V_7 ) ;
}
return V_19 ;
}
