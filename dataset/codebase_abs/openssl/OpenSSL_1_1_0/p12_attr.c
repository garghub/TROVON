int F_1 ( T_1 * V_1 , unsigned char * V_2 ,
int V_3 )
{
if ( F_2 ( & V_1 -> V_4 , V_5 ,
V_6 , V_2 , V_3 ) )
return 1 ;
else
return 0 ;
}
int F_3 ( T_2 * V_7 , int V_8 )
{
unsigned char V_9 = ( unsigned char ) V_8 ;
return F_4 ( V_7 , V_10 ,
V_11 , & V_9 , 1 ) ;
}
int F_5 ( T_1 * V_1 , const char * V_2 ,
int V_3 )
{
if ( F_2 ( & V_1 -> V_4 , V_12 ,
V_13 , ( unsigned char * ) V_2 , V_3 ) )
return 1 ;
else
return 0 ;
}
int F_6 ( T_1 * V_1 , const char * V_2 ,
int V_3 )
{
if ( F_2 ( & V_1 -> V_4 , V_12 ,
V_14 , ( unsigned char * ) V_2 , V_3 ) )
return 1 ;
else
return 0 ;
}
int F_7 ( T_1 * V_1 ,
const unsigned char * V_2 , int V_3 )
{
if ( F_2 ( & V_1 -> V_4 , V_12 ,
V_15 , V_2 , V_3 ) )
return 1 ;
else
return 0 ;
}
int F_8 ( T_1 * V_1 , const char * V_2 , int V_3 )
{
if ( F_2 ( & V_1 -> V_4 , V_16 ,
V_13 , ( unsigned char * ) V_2 , V_3 ) )
return 1 ;
else
return 0 ;
}
char * F_9 ( T_1 * V_1 )
{
const T_3 * V_17 ;
if ( ( V_17 = F_10 ( V_1 , V_12 ) ) == NULL )
return NULL ;
if ( V_17 -> type != V_18 )
return NULL ;
return F_11 ( V_17 -> V_19 . V_20 -> V_21 ,
V_17 -> V_19 . V_20 -> V_22 ) ;
}
