static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 )
{
T_3 * V_4 = ( T_3 * ) * V_2 ;
switch( V_1 ) {
case V_5 :
V_4 -> V_6 = 0 ;
V_4 -> V_7 = NULL ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = - 1 ;
V_4 -> V_10 = NULL ;
V_4 -> V_11 = NULL ;
V_4 -> V_12 = NULL ;
F_2 ( V_13 , V_4 , & V_4 -> V_14 ) ;
break;
case V_15 :
if ( V_4 -> V_7 != NULL ) F_3 ( V_4 -> V_7 ) ;
V_4 -> V_7 = F_4 ( V_4 -> V_16 -> V_17 , NULL , 0 ) ;
break;
case V_18 :
F_5 ( V_13 , V_4 , & V_4 -> V_14 ) ;
F_6 ( V_4 -> V_12 ) ;
F_7 ( V_4 -> V_10 ) ;
F_8 ( V_4 -> V_11 ) ;
F_9 ( V_4 -> V_19 ) ;
if ( V_4 -> V_7 != NULL ) F_3 ( V_4 -> V_7 ) ;
break;
}
return 1 ;
}
T_4 * F_10 ( void )
{
return ( & V_20 ) ;
}
int F_11 ( long V_21 , void * V_22 , T_5 * V_23 ,
T_6 * V_24 , T_7 * V_25 )
{
return F_12 ( V_13 , V_21 , V_22 ,
V_23 , V_24 , V_25 ) ;
}
int F_13 ( T_3 * V_26 , int V_27 , void * V_28 )
{
return ( F_14 ( & V_26 -> V_14 , V_27 , V_28 ) ) ;
}
void * F_15 ( T_3 * V_26 , int V_27 )
{
return ( F_16 ( & V_26 -> V_14 , V_27 ) ) ;
}
T_3 * F_17 ( T_3 * * V_29 , const unsigned char * * V_30 , long V_31 )
{
const unsigned char * V_32 ;
T_3 * V_4 ;
V_32 = * V_30 ;
V_4 = F_18 ( V_29 , V_30 , V_31 ) ;
if( ! V_4 ) return NULL ;
V_31 -= * V_30 - V_32 ;
if( ! V_31 ) return V_4 ;
if( ! F_19 ( & V_4 -> V_12 , V_30 , V_31 ) ) goto V_33;
return V_4 ;
V_33:
F_20 ( V_4 ) ;
return NULL ;
}
int F_21 ( T_3 * V_29 , unsigned char * * V_30 )
{
int V_31 ;
V_31 = F_22 ( V_29 , V_30 ) ;
if( V_29 ) V_31 += F_23 ( V_29 -> V_12 , V_30 ) ;
return V_31 ;
}
