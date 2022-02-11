int F_1 ( T_1 * V_1 , const void * V_2 , int V_3 ,
const T_2 * V_4 , T_3 * V_5 )
{
int V_6 , V_7 , V_8 = 0 ;
unsigned char V_9 [ V_10 ] ;
if ( V_4 != NULL )
{
V_8 = 1 ;
V_1 -> V_4 = V_4 ;
}
else
V_4 = V_1 -> V_4 ;
if ( V_2 != NULL )
{
V_8 = 1 ;
V_7 = F_2 ( V_4 ) ;
F_3 ( V_7 <= ( int ) sizeof( V_1 -> V_2 ) ) ;
if ( V_7 < V_3 )
{
if ( ! F_4 ( & V_1 -> V_11 , V_4 , V_5 ) )
goto V_12;
if ( ! F_5 ( & V_1 -> V_11 , V_2 , V_3 ) )
goto V_12;
if ( ! F_6 ( & ( V_1 -> V_11 ) , V_1 -> V_2 ,
& V_1 -> V_13 ) )
goto V_12;
}
else
{
F_3 ( V_3 >= 0 && V_3 <= ( int ) sizeof( V_1 -> V_2 ) ) ;
memcpy ( V_1 -> V_2 , V_2 , V_3 ) ;
V_1 -> V_13 = V_3 ;
}
if( V_1 -> V_13 != V_10 )
memset ( & V_1 -> V_2 [ V_1 -> V_13 ] , 0 ,
V_10 - V_1 -> V_13 ) ;
}
if ( V_8 )
{
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x36 ^ V_1 -> V_2 [ V_6 ] ;
if ( ! F_4 ( & V_1 -> V_14 , V_4 , V_5 ) )
goto V_12;
if ( ! F_5 ( & V_1 -> V_14 , V_9 , F_2 ( V_4 ) ) )
goto V_12;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x5c ^ V_1 -> V_2 [ V_6 ] ;
if ( ! F_4 ( & V_1 -> V_15 , V_4 , V_5 ) )
goto V_12;
if ( ! F_5 ( & V_1 -> V_15 , V_9 , F_2 ( V_4 ) ) )
goto V_12;
}
if ( ! F_7 ( & V_1 -> V_11 , & V_1 -> V_14 ) )
goto V_12;
return 1 ;
V_12:
return 0 ;
}
int F_8 ( T_1 * V_1 , const void * V_2 , int V_3 , const T_2 * V_4 )
{
if( V_2 && V_4 )
F_9 ( V_1 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 , NULL ) ;
}
int F_10 ( T_1 * V_1 , const unsigned char * V_16 , T_4 V_3 )
{
return F_5 ( & V_1 -> V_11 , V_16 , V_3 ) ;
}
int F_11 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_3 )
{
int V_7 ;
unsigned int V_6 ;
unsigned char V_17 [ V_18 ] ;
V_7 = F_2 ( V_1 -> V_4 ) ;
if ( ! F_6 ( & V_1 -> V_11 , V_17 , & V_6 ) )
goto V_12;
if ( ! F_7 ( & V_1 -> V_11 , & V_1 -> V_15 ) )
goto V_12;
if ( ! F_5 ( & V_1 -> V_11 , V_17 , V_6 ) )
goto V_12;
if ( ! F_6 ( & V_1 -> V_11 , V_4 , V_3 ) )
goto V_12;
return 1 ;
V_12:
return 0 ;
}
void F_9 ( T_1 * V_1 )
{
F_12 ( & V_1 -> V_14 ) ;
F_12 ( & V_1 -> V_15 ) ;
F_12 ( & V_1 -> V_11 ) ;
}
int F_13 ( T_1 * V_19 , T_1 * V_20 )
{
if ( ! F_14 ( & V_19 -> V_14 , & V_20 -> V_14 ) )
goto V_12;
if ( ! F_14 ( & V_19 -> V_15 , & V_20 -> V_15 ) )
goto V_12;
if ( ! F_14 ( & V_19 -> V_11 , & V_20 -> V_11 ) )
goto V_12;
memcpy ( V_19 -> V_2 , V_20 -> V_2 , V_10 ) ;
V_19 -> V_13 = V_20 -> V_13 ;
V_19 -> V_4 = V_20 -> V_4 ;
return 1 ;
V_12:
return 0 ;
}
void F_15 ( T_1 * V_1 )
{
F_16 ( & V_1 -> V_14 ) ;
F_16 ( & V_1 -> V_15 ) ;
F_16 ( & V_1 -> V_11 ) ;
memset ( V_1 , 0 , sizeof *V_1 ) ;
}
unsigned char * F_17 ( const T_2 * V_21 , const void * V_2 , int V_22 ,
const unsigned char * V_23 , T_4 V_24 , unsigned char * V_4 ,
unsigned int * V_25 )
{
T_1 V_26 ;
static unsigned char V_27 [ V_18 ] ;
if ( V_4 == NULL ) V_4 = V_27 ;
F_9 ( & V_26 ) ;
if ( ! F_8 ( & V_26 , V_2 , V_22 , V_21 ) )
goto V_12;
if ( ! F_10 ( & V_26 , V_23 , V_24 ) )
goto V_12;
if ( ! F_11 ( & V_26 , V_4 , V_25 ) )
goto V_12;
F_15 ( & V_26 ) ;
return V_4 ;
V_12:
return NULL ;
}
void F_18 ( T_1 * V_1 , unsigned long V_28 )
{
F_19 ( & V_1 -> V_14 , V_28 ) ;
F_19 ( & V_1 -> V_15 , V_28 ) ;
F_19 ( & V_1 -> V_11 , V_28 ) ;
}
