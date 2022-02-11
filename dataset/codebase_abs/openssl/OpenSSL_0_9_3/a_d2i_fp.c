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
T_3 * V_3 ;
unsigned char * V_8 ;
int V_9 ;
char * V_4 = NULL ;
T_4 V_10 ;
int V_11 = V_12 ;
int V_13 = 0 ;
int V_14 = 0 ;
int V_15 = 0 ;
V_3 = F_10 () ;
if ( V_3 == NULL )
{
F_6 ( V_16 , V_17 ) ;
return ( NULL ) ;
}
F_11 () ;
for (; ; )
{
if ( V_11 >= ( V_15 - V_14 ) )
{
V_11 -= ( V_15 - V_14 ) ;
if ( ! F_12 ( V_3 , V_15 + V_11 ) )
{
F_6 ( V_16 , V_17 ) ;
goto V_18;
}
V_9 = F_13 ( V_1 , & ( V_3 -> V_19 [ V_15 ] ) , V_11 ) ;
if ( ( V_9 < 0 ) && ( ( V_15 - V_14 ) == 0 ) )
{
F_6 ( V_16 , V_20 ) ;
goto V_18;
}
if ( V_9 > 0 )
V_15 += V_9 ;
}
V_8 = ( unsigned char * ) & ( V_3 -> V_19 [ V_14 ] ) ;
V_10 . V_8 = V_8 ;
V_10 . V_21 = F_14 ( & ( V_10 . V_8 ) , & ( V_10 . V_22 ) , & ( V_10 . V_23 ) , & ( V_10 . V_24 ) ,
V_15 - V_14 ) ;
if ( V_10 . V_21 & 0x80 )
{
unsigned long V_25 ;
V_25 = F_15 ( F_16 () ) ;
if ( V_25 != V_26 )
goto V_18;
else
F_17 () ;
}
V_9 = V_10 . V_8 - V_8 ;
V_14 += V_9 ;
if ( V_10 . V_21 & 1 )
{
V_13 ++ ;
V_11 = V_12 ;
}
else if ( V_13 && ( V_10 . V_22 == 0 ) && ( V_10 . V_23 == V_27 ) )
{
V_13 -- ;
if ( V_13 <= 0 )
break;
else
V_11 = V_12 ;
}
else
{
V_11 = ( int ) V_10 . V_22 ;
if ( V_11 > ( V_15 - V_14 ) )
{
V_11 -= ( V_15 - V_14 ) ;
if ( ! F_12 ( V_3 , V_15 + V_11 ) )
{
F_6 ( V_16 , V_17 ) ;
goto V_18;
}
V_9 = F_13 ( V_1 , & ( V_3 -> V_19 [ V_15 ] ) , V_11 ) ;
if ( V_9 <= 0 )
{
F_6 ( V_16 , V_20 ) ;
goto V_18;
}
V_15 += V_9 ;
}
V_14 += ( int ) V_10 . V_22 ;
if ( V_13 <= 0 )
{
break;
}
else
V_11 = V_12 ;
}
}
V_8 = ( unsigned char * ) V_3 -> V_19 ;
V_4 = F_3 ( V_2 , & V_8 , V_14 ) ;
V_18:
if ( V_3 != NULL ) F_18 ( V_3 ) ;
return ( V_4 ) ;
}
