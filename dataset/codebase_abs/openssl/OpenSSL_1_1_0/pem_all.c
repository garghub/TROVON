static T_1 * F_1 ( T_2 * V_1 , T_1 * * V_2 )
{
T_1 * V_3 ;
if ( ! V_1 )
return NULL ;
V_3 = F_2 ( V_1 ) ;
F_3 ( V_1 ) ;
if ( ! V_3 )
return NULL ;
if ( V_2 ) {
F_4 ( * V_2 ) ;
* V_2 = V_3 ;
}
return V_3 ;
}
T_1 * F_5 ( T_3 * V_4 , T_1 * * V_2 , T_4 * V_5 ,
void * V_6 )
{
T_2 * V_7 ;
V_7 = F_6 ( V_4 , NULL , V_5 , V_6 ) ;
return F_1 ( V_7 , V_2 ) ;
}
T_1 * F_7 ( T_5 * V_8 , T_1 * * V_2 , T_4 * V_5 , void * V_6 )
{
T_2 * V_7 ;
V_7 = F_8 ( V_8 , NULL , V_5 , V_6 ) ;
return F_1 ( V_7 , V_2 ) ;
}
static T_6 * F_9 ( T_2 * V_1 , T_6 * * V_9 )
{
T_6 * V_10 ;
if ( ! V_1 )
return NULL ;
V_10 = F_10 ( V_1 ) ;
F_3 ( V_1 ) ;
if ( ! V_10 )
return NULL ;
if ( V_9 ) {
F_11 ( * V_9 ) ;
* V_9 = V_10 ;
}
return V_10 ;
}
T_6 * F_12 ( T_3 * V_4 , T_6 * * V_9 , T_4 * V_5 ,
void * V_6 )
{
T_2 * V_7 ;
V_7 = F_6 ( V_4 , NULL , V_5 , V_6 ) ;
return F_9 ( V_7 , V_9 ) ;
}
T_6 * F_13 ( T_5 * V_8 , T_6 * * V_9 , T_4 * V_5 , void * V_6 )
{
T_2 * V_7 ;
V_7 = F_8 ( V_8 , NULL , V_5 , V_6 ) ;
return F_9 ( V_7 , V_9 ) ;
}
static T_7 * F_14 ( T_2 * V_1 , T_7 * * V_11 )
{
T_7 * V_10 ;
if ( ! V_1 )
return NULL ;
V_10 = F_15 ( V_1 ) ;
F_3 ( V_1 ) ;
if ( ! V_10 )
return NULL ;
if ( V_11 ) {
F_16 ( * V_11 ) ;
* V_11 = V_10 ;
}
return V_10 ;
}
T_7 * F_17 ( T_3 * V_4 , T_7 * * V_1 , T_4 * V_5 ,
void * V_6 )
{
T_2 * V_7 ;
V_7 = F_6 ( V_4 , NULL , V_5 , V_6 ) ;
return F_14 ( V_7 , V_1 ) ;
}
T_7 * F_18 ( T_5 * V_8 , T_7 * * V_11 , T_4 * V_5 ,
void * V_6 )
{
T_2 * V_7 ;
V_7 = F_8 ( V_8 , NULL , V_5 , V_6 ) ;
return F_14 ( V_7 , V_11 ) ;
}
