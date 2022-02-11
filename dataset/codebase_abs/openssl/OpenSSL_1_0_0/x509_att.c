int F_1 ( T_1 * V_1 , int V_2 , const void * V_3 , int V_4 )
{
T_2 * V_5 ;
T_3 * V_6 = NULL ;
int V_7 = 0 ;
if ( ! V_1 ) return 0 ;
if( V_2 & V_8 ) {
V_6 = F_2 ( NULL , V_3 , V_4 , V_2 ,
F_3 ( V_1 -> V_9 ) ) ;
if( ! V_6 ) {
F_4 ( V_10 , V_11 ) ;
return 0 ;
}
V_7 = V_6 -> type ;
} else if ( V_4 != - 1 ) {
if( ! ( V_6 = F_5 ( V_2 ) ) ) goto V_12;
if( ! F_6 ( V_6 , V_3 , V_4 ) ) goto V_12;
V_7 = V_2 ;
}
if( ! ( V_1 -> V_13 . V_14 = F_7 () ) ) goto V_12;
V_1 -> V_15 = 0 ;
if ( V_2 == 0 )
return 1 ;
if( ! ( V_5 = F_8 () ) ) goto V_12;
if ( ( V_4 == - 1 ) && ! ( V_2 & V_8 ) )
{
if ( ! F_9 ( V_5 , V_2 , V_3 ) )
goto V_12;
}
else
F_10 ( V_5 , V_7 , V_6 ) ;
if( ! F_11 ( V_1 -> V_13 . V_14 , V_5 ) ) goto V_12;
return 1 ;
V_12:
F_4 ( V_10 , V_16 ) ;
return 0 ;
}
int F_12 ( T_1 * V_1 )
{
if( ! V_1 -> V_15 ) return F_13 ( V_1 -> V_13 . V_14 ) ;
if( V_1 -> V_13 . V_15 ) return 1 ;
return 0 ;
}
T_4 * F_14 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return ( NULL ) ;
return ( V_1 -> V_9 ) ;
}
void * F_15 ( T_1 * V_1 , int V_17 ,
int V_18 , void * V_3 )
{
T_2 * V_5 ;
V_5 = F_16 ( V_1 , V_17 ) ;
if( ! V_5 ) return NULL ;
if( V_18 != F_17 ( V_5 ) ) {
F_4 ( V_19 , V_20 ) ;
return NULL ;
}
return V_5 -> V_13 . V_21 ;
}
T_2 * F_16 ( T_1 * V_1 , int V_17 )
{
if ( V_1 == NULL ) return ( NULL ) ;
if( V_17 >= F_12 ( V_1 ) ) return NULL ;
if( ! V_1 -> V_15 ) return F_18 ( V_1 -> V_13 . V_14 , V_17 ) ;
else return V_1 -> V_13 . V_15 ;
}
