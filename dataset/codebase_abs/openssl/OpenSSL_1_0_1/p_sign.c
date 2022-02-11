void F_1 ( T_1 * V_1 , T_2 * type )
{
F_2 ( V_1 , type ) ;
}
void F_3 ( T_1 * V_1 , unsigned char * V_2 ,
unsigned int V_3 )
{
F_4 ( V_1 , V_2 , V_3 ) ;
}
int F_5 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_5 ,
T_3 * V_6 )
{
unsigned char V_7 [ V_8 ] ;
unsigned int V_9 ;
int V_10 = 0 , V_11 = 0 , V_12 ;
T_1 V_13 ;
T_4 * V_14 = NULL ;
* V_5 = 0 ;
F_6 ( & V_13 ) ;
if ( ! F_7 ( & V_13 , V_1 ) )
goto V_15;
if ( ! F_8 ( & V_13 , & ( V_7 [ 0 ] ) , & V_9 ) )
goto V_15;
F_9 ( & V_13 ) ;
if ( V_1 -> V_16 -> V_17 & V_18 )
{
T_5 V_19 = ( T_5 ) F_10 ( V_6 ) ;
V_10 = 0 ;
V_14 = F_11 ( V_6 , NULL ) ;
if ( ! V_14 )
goto V_15;
if ( F_12 ( V_14 ) <= 0 )
goto V_15;
if ( F_13 ( V_14 , V_1 -> V_16 ) <= 0 )
goto V_15;
if ( F_14 ( V_14 , V_4 , & V_19 , V_7 , V_9 ) <= 0 )
goto V_15;
* V_5 = V_19 ;
V_10 = 1 ;
V_15:
F_15 ( V_14 ) ;
return V_10 ;
}
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
{
V_12 = V_1 -> V_16 -> V_20 [ V_10 ] ;
if ( V_12 == 0 ) break;
if ( V_6 -> type == V_12 )
{
V_11 = 1 ;
break;
}
}
if ( ! V_11 )
{
F_16 ( V_21 , V_22 ) ;
return ( 0 ) ;
}
if ( V_1 -> V_16 -> V_23 == NULL )
{
F_16 ( V_21 , V_24 ) ;
return ( 0 ) ;
}
return ( V_1 -> V_16 -> V_23 ( V_1 -> V_16 -> type , V_7 , V_9 , V_4 , V_5 ,
V_6 -> V_6 . V_25 ) ) ;
}
