int F_1 ( T_1 * V_1 , const void * V_2 , int V_3 ,
const T_2 * V_4 , T_3 * V_5 )
{
int V_6 , V_7 , V_8 = 0 ;
unsigned char V_9 [ V_10 ] ;
#ifdef F_2
if ( F_3 () )
{
if ( ( V_5 || V_1 -> V_11 . V_12 )
&& ! ( V_1 -> V_11 . V_13 & V_14 ) )
{
F_4 ( V_15 , V_16 ) ;
return 0 ;
}
if ( ! V_5 && ! V_1 -> V_11 . V_12 )
return F_5 ( V_1 , V_2 , V_3 , V_4 , NULL ) ;
}
#endif
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
V_7 = F_6 ( V_4 ) ;
F_7 ( V_7 <= ( int ) sizeof( V_1 -> V_2 ) ) ;
if ( V_7 < V_3 )
{
if ( ! F_8 ( & V_1 -> V_17 , V_4 , V_5 ) )
goto V_18;
if ( ! F_9 ( & V_1 -> V_17 , V_2 , V_3 ) )
goto V_18;
if ( ! F_10 ( & ( V_1 -> V_17 ) , V_1 -> V_2 ,
& V_1 -> V_19 ) )
goto V_18;
}
else
{
F_7 ( V_3 >= 0 && V_3 <= ( int ) sizeof( V_1 -> V_2 ) ) ;
memcpy ( V_1 -> V_2 , V_2 , V_3 ) ;
V_1 -> V_19 = V_3 ;
}
if( V_1 -> V_19 != V_10 )
memset ( & V_1 -> V_2 [ V_1 -> V_19 ] , 0 ,
V_10 - V_1 -> V_19 ) ;
}
if ( V_8 )
{
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x36 ^ V_1 -> V_2 [ V_6 ] ;
if ( ! F_8 ( & V_1 -> V_11 , V_4 , V_5 ) )
goto V_18;
if ( ! F_9 ( & V_1 -> V_11 , V_9 , F_6 ( V_4 ) ) )
goto V_18;
for ( V_6 = 0 ; V_6 < V_10 ; V_6 ++ )
V_9 [ V_6 ] = 0x5c ^ V_1 -> V_2 [ V_6 ] ;
if ( ! F_8 ( & V_1 -> V_20 , V_4 , V_5 ) )
goto V_18;
if ( ! F_9 ( & V_1 -> V_20 , V_9 , F_6 ( V_4 ) ) )
goto V_18;
}
if ( ! F_11 ( & V_1 -> V_17 , & V_1 -> V_11 ) )
goto V_18;
return 1 ;
V_18:
return 0 ;
}
int F_12 ( T_1 * V_1 , const void * V_2 , int V_3 , const T_2 * V_4 )
{
if( V_2 && V_4 )
F_13 ( V_1 ) ;
return F_1 ( V_1 , V_2 , V_3 , V_4 , NULL ) ;
}
int F_14 ( T_1 * V_1 , const unsigned char * V_21 , T_4 V_3 )
{
#ifdef F_2
if ( F_3 () && ! V_1 -> V_11 . V_12 )
return F_15 ( V_1 , V_21 , V_3 ) ;
#endif
return F_9 ( & V_1 -> V_17 , V_21 , V_3 ) ;
}
int F_16 ( T_1 * V_1 , unsigned char * V_4 , unsigned int * V_3 )
{
unsigned int V_6 ;
unsigned char V_22 [ V_23 ] ;
#ifdef F_2
if ( F_3 () && ! V_1 -> V_11 . V_12 )
return F_17 ( V_1 , V_4 , V_3 ) ;
#endif
if ( ! F_10 ( & V_1 -> V_17 , V_22 , & V_6 ) )
goto V_18;
if ( ! F_11 ( & V_1 -> V_17 , & V_1 -> V_20 ) )
goto V_18;
if ( ! F_9 ( & V_1 -> V_17 , V_22 , V_6 ) )
goto V_18;
if ( ! F_10 ( & V_1 -> V_17 , V_4 , V_3 ) )
goto V_18;
return 1 ;
V_18:
return 0 ;
}
void F_13 ( T_1 * V_1 )
{
F_18 ( & V_1 -> V_11 ) ;
F_18 ( & V_1 -> V_20 ) ;
F_18 ( & V_1 -> V_17 ) ;
}
int F_19 ( T_1 * V_24 , T_1 * V_25 )
{
if ( ! F_20 ( & V_24 -> V_11 , & V_25 -> V_11 ) )
goto V_18;
if ( ! F_20 ( & V_24 -> V_20 , & V_25 -> V_20 ) )
goto V_18;
if ( ! F_20 ( & V_24 -> V_17 , & V_25 -> V_17 ) )
goto V_18;
memcpy ( V_24 -> V_2 , V_25 -> V_2 , V_10 ) ;
V_24 -> V_19 = V_25 -> V_19 ;
V_24 -> V_4 = V_25 -> V_4 ;
return 1 ;
V_18:
return 0 ;
}
void F_21 ( T_1 * V_1 )
{
#ifdef F_2
if ( F_3 () && ! V_1 -> V_11 . V_12 )
{
F_22 ( V_1 ) ;
return;
}
#endif
F_23 ( & V_1 -> V_11 ) ;
F_23 ( & V_1 -> V_20 ) ;
F_23 ( & V_1 -> V_17 ) ;
memset ( V_1 , 0 , sizeof *V_1 ) ;
}
unsigned char * F_24 ( const T_2 * V_26 , const void * V_2 , int V_27 ,
const unsigned char * V_28 , T_4 V_29 , unsigned char * V_4 ,
unsigned int * V_30 )
{
T_1 V_31 ;
static unsigned char V_32 [ V_23 ] ;
if ( V_4 == NULL ) V_4 = V_32 ;
F_13 ( & V_31 ) ;
if ( ! F_12 ( & V_31 , V_2 , V_27 , V_26 ) )
goto V_18;
if ( ! F_14 ( & V_31 , V_28 , V_29 ) )
goto V_18;
if ( ! F_16 ( & V_31 , V_4 , V_30 ) )
goto V_18;
F_21 ( & V_31 ) ;
return V_4 ;
V_18:
return NULL ;
}
void F_25 ( T_1 * V_1 , unsigned long V_13 )
{
F_26 ( & V_1 -> V_11 , V_13 ) ;
F_26 ( & V_1 -> V_20 , V_13 ) ;
F_26 ( & V_1 -> V_17 , V_13 ) ;
}
