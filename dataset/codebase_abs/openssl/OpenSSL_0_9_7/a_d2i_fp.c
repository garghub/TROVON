char * F_1 ( char * (* F_2)() , char * (* F_3)() , T_1 * V_1 ,
unsigned char * * V_2 )
{
T_2 * V_3 ;
char * V_4 ;
if ( ( V_3 = F_4 ( F_5 () ) ) == NULL )
{
F_6 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
F_7 ( V_3 , V_1 , V_7 ) ;
V_4 = F_8 ( F_2 , F_3 , V_3 , V_2 ) ;
F_9 ( V_3 ) ;
return ( V_4 ) ;
}
char * F_8 ( char * (* F_2)() , char * (* F_3)() , T_2 * V_1 ,
unsigned char * * V_2 )
{
T_3 * V_3 = NULL ;
unsigned char * V_8 ;
char * V_4 = NULL ;
int V_9 ;
V_9 = F_10 ( V_1 , & V_3 ) ;
if( V_9 < 0 ) goto V_10;
V_8 = ( unsigned char * ) V_3 -> V_11 ;
V_4 = F_3 ( V_2 , & V_8 , V_9 ) ;
V_10:
if ( V_3 != NULL ) F_11 ( V_3 ) ;
return ( V_4 ) ;
}
void * F_12 ( const T_4 * V_12 , T_2 * V_1 , void * V_2 )
{
T_3 * V_3 = NULL ;
unsigned char * V_8 ;
void * V_4 = NULL ;
int V_9 ;
V_9 = F_10 ( V_1 , & V_3 ) ;
if( V_9 < 0 ) goto V_10;
V_8 = ( unsigned char * ) V_3 -> V_11 ;
V_4 = F_13 ( V_2 , & V_8 , V_9 , V_12 ) ;
V_10:
if ( V_3 != NULL ) F_11 ( V_3 ) ;
return ( V_4 ) ;
}
void * F_14 ( const T_4 * V_12 , T_1 * V_1 , void * V_2 )
{
T_2 * V_3 ;
char * V_4 ;
if ( ( V_3 = F_4 ( F_5 () ) ) == NULL )
{
F_6 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
F_7 ( V_3 , V_1 , V_7 ) ;
V_4 = F_12 ( V_12 , V_3 , V_2 ) ;
F_9 ( V_3 ) ;
return ( V_4 ) ;
}
static int F_10 ( T_2 * V_1 , T_3 * * V_13 )
{
T_3 * V_3 ;
unsigned char * V_8 ;
int V_14 ;
int V_4 = - 1 ;
T_5 V_15 ;
int V_16 = V_17 ;
int V_18 = 0 ;
#if F_15 ( V_19 ) && F_15 ( V_20 )
long V_21 = 0 ;
#else
int V_21 = 0 ;
#endif
int V_9 = 0 ;
V_3 = F_16 () ;
if ( V_3 == NULL )
{
F_6 ( V_22 , V_23 ) ;
return - 1 ;
}
F_17 () ;
for (; ; )
{
if ( V_16 >= ( V_9 - V_21 ) )
{
V_16 -= ( V_9 - V_21 ) ;
if ( ! F_18 ( V_3 , V_9 + V_16 ) )
{
F_6 ( V_22 , V_23 ) ;
goto V_10;
}
V_14 = F_19 ( V_1 , & ( V_3 -> V_11 [ V_9 ] ) , V_16 ) ;
if ( ( V_14 < 0 ) && ( ( V_9 - V_21 ) == 0 ) )
{
F_6 ( V_22 , V_24 ) ;
goto V_10;
}
if ( V_14 > 0 )
V_9 += V_14 ;
}
V_8 = ( unsigned char * ) & ( V_3 -> V_11 [ V_21 ] ) ;
V_15 . V_8 = V_8 ;
V_15 . V_25 = F_20 ( & ( V_15 . V_8 ) , & ( V_15 . V_26 ) , & ( V_15 . V_27 ) , & ( V_15 . V_28 ) ,
V_9 - V_21 ) ;
if ( V_15 . V_25 & 0x80 )
{
unsigned long V_29 ;
V_29 = F_21 ( F_22 () ) ;
if ( V_29 != V_30 )
goto V_10;
else
F_23 () ;
}
V_14 = V_15 . V_8 - V_8 ;
V_21 += V_14 ;
if ( V_15 . V_25 & 1 )
{
V_18 ++ ;
V_16 = V_17 ;
}
else if ( V_18 && ( V_15 . V_26 == 0 ) && ( V_15 . V_27 == V_31 ) )
{
V_18 -- ;
if ( V_18 <= 0 )
break;
else
V_16 = V_17 ;
}
else
{
V_16 = ( int ) V_15 . V_26 ;
if ( V_16 > ( V_9 - V_21 ) )
{
V_16 -= ( V_9 - V_21 ) ;
if ( ! F_18 ( V_3 , V_9 + V_16 ) )
{
F_6 ( V_22 , V_23 ) ;
goto V_10;
}
while ( V_16 > 0 )
{
V_14 = F_19 ( V_1 , & ( V_3 -> V_11 [ V_9 ] ) , V_16 ) ;
if ( V_14 <= 0 )
{
F_6 ( V_22 ,
V_24 ) ;
goto V_10;
}
V_9 += V_14 ;
V_16 -= V_14 ;
}
}
V_21 += ( int ) V_15 . V_26 ;
if ( V_18 <= 0 )
{
break;
}
else
V_16 = V_17 ;
}
}
* V_13 = V_3 ;
return V_21 ;
V_10:
if ( V_3 != NULL ) F_11 ( V_3 ) ;
return ( V_4 ) ;
}
