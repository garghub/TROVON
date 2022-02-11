int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
unsigned int V_3 , T_2 * V_4 )
{
unsigned char V_5 [ V_6 ] ;
unsigned int V_7 ;
int V_8 = - 1 , V_9 = 0 , V_10 ;
T_1 V_11 ;
T_3 * V_12 = NULL ;
F_2 ( & V_11 ) ;
if ( ! F_3 ( & V_11 , V_1 ) )
goto V_13;
if ( ! F_4 ( & V_11 , & ( V_5 [ 0 ] ) , & V_7 ) )
goto V_13;
F_5 ( & V_11 ) ;
if ( V_1 -> V_14 -> V_15 & V_16 )
{
V_8 = - 1 ;
V_12 = F_6 ( V_4 , NULL ) ;
if ( ! V_12 )
goto V_13;
if ( F_7 ( V_12 ) <= 0 )
goto V_13;
if ( F_8 ( V_12 , V_1 -> V_14 ) <= 0 )
goto V_13;
V_8 = F_9 ( V_12 , V_2 , V_3 , V_5 , V_7 ) ;
V_13:
F_10 ( V_12 ) ;
return V_8 ;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
{
V_10 = V_1 -> V_14 -> V_17 [ V_8 ] ;
if ( V_10 == 0 ) break;
if ( V_4 -> type == V_10 )
{
V_9 = 1 ;
break;
}
}
if ( ! V_9 )
{
F_11 ( V_18 , V_19 ) ;
return ( - 1 ) ;
}
if ( V_1 -> V_14 -> V_20 == NULL )
{
F_11 ( V_18 , V_21 ) ;
return ( 0 ) ;
}
return ( V_1 -> V_14 -> V_20 ( V_1 -> V_14 -> type , V_5 , V_7 ,
V_2 , V_3 , V_4 -> V_4 . V_22 ) ) ;
}
