int F_1 ( const T_1 * V_1 )
{
return F_2 ( V_1 -> V_2 ) ;
}
int F_3 ( const T_1 * V_1 , int V_3 , int V_4 )
{
return F_4 ( V_1 -> V_2 , V_3 , V_4 ) ;
}
int F_5 ( const T_1 * V_1 , const T_2 * V_5 ,
int V_4 )
{
return F_6 ( V_1 -> V_2 , V_5 , V_4 ) ;
}
T_3 * F_7 ( const T_1 * V_1 , int V_6 )
{
return F_8 ( V_1 -> V_2 , V_6 ) ;
}
T_3 * F_9 ( T_1 * V_1 , int V_6 )
{
return F_10 ( V_1 -> V_2 , V_6 ) ;
}
int F_11 ( T_1 * V_1 , T_3 * V_7 )
{
if ( F_12 ( & V_1 -> V_2 , V_7 ) )
return 1 ;
return 0 ;
}
int F_13 ( T_1 * V_1 ,
const T_2 * V_5 , int type ,
const void * V_8 , int V_9 )
{
if ( F_14 ( & V_1 -> V_2 , V_5 , type , V_8 , V_9 ) )
return 1 ;
return 0 ;
}
int F_15 ( T_1 * V_1 ,
int V_3 , int type , const void * V_8 , int V_9 )
{
if ( F_16 ( & V_1 -> V_2 , V_3 , type , V_8 , V_9 ) )
return 1 ;
return 0 ;
}
int F_17 ( T_1 * V_1 ,
const char * V_10 , int type ,
const void * V_8 , int V_9 )
{
if ( F_18 ( & V_1 -> V_2 , V_10 , type , V_8 , V_9 ) )
return 1 ;
return 0 ;
}
void * F_19 ( T_1 * V_1 , const T_2 * V_11 ,
int V_4 , int type )
{
return F_20 ( V_1 -> V_2 , V_11 , V_4 , type ) ;
}
int F_21 ( const T_1 * V_1 )
{
return F_2 ( V_1 -> V_12 ) ;
}
int F_22 ( const T_1 * V_1 , int V_3 ,
int V_4 )
{
return F_4 ( V_1 -> V_12 , V_3 , V_4 ) ;
}
int F_23 ( const T_1 * V_1 ,
const T_2 * V_5 , int V_4 )
{
return F_6 ( V_1 -> V_12 , V_5 , V_4 ) ;
}
T_3 * F_24 ( const T_1 * V_1 , int V_6 )
{
return F_8 ( V_1 -> V_12 , V_6 ) ;
}
T_3 * F_25 ( T_1 * V_1 , int V_6 )
{
return F_10 ( V_1 -> V_12 , V_6 ) ;
}
int F_26 ( T_1 * V_1 , T_3 * V_7 )
{
if ( F_12 ( & V_1 -> V_12 , V_7 ) )
return 1 ;
return 0 ;
}
int F_27 ( T_1 * V_1 ,
const T_2 * V_5 , int type ,
const void * V_8 , int V_9 )
{
if ( F_14 ( & V_1 -> V_12 , V_5 , type , V_8 , V_9 ) )
return 1 ;
return 0 ;
}
int F_28 ( T_1 * V_1 ,
int V_3 , int type ,
const void * V_8 , int V_9 )
{
if ( F_16 ( & V_1 -> V_12 , V_3 , type , V_8 , V_9 ) )
return 1 ;
return 0 ;
}
int F_29 ( T_1 * V_1 ,
const char * V_10 , int type ,
const void * V_8 , int V_9 )
{
if ( F_18 ( & V_1 -> V_12 , V_10 ,
type , V_8 , V_9 ) )
return 1 ;
return 0 ;
}
void * F_30 ( T_1 * V_1 , T_2 * V_11 ,
int V_4 , int type )
{
return F_20 ( V_1 -> V_12 , V_11 , V_4 , type ) ;
}
