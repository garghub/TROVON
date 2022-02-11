static int F_1 ( T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 )
{
int V_5 = 0 ;
if ( ! F_2 ( V_1 , V_2 ) )
return 0 ;
if ( ! F_3 ( V_1 ) && ! F_4 ( V_1 , 1 ) )
return 0 ;
for(; ; )
{
V_5 ++ ;
F_5 ( V_4 , 0 , V_5 ) ;
if ( F_6 ( V_1 , 27 , V_3 , 1 , V_4 ) )
break;
if ( ! F_4 ( V_1 , 2 ) )
return 0 ;
}
F_5 ( V_4 , 2 , V_5 ) ;
return 1 ;
}
int F_7 ( T_1 * V_6 , T_1 * V_7 , T_1 * V_8 ,
const T_1 * V_9 , const T_1 * V_10 , const T_1 * V_11 ,
const T_1 * V_12 , T_2 * V_3 , T_3 * V_4 )
{
int V_13 = 0 ;
T_1 * V_14 , * V_15 , * V_16 ;
if ( ! F_3 ( V_12 ) )
return 0 ;
F_8 ( V_3 ) ;
if ( ! V_7 )
V_7 = F_9 ( V_3 ) ;
if ( ! V_8 )
V_8 = F_9 ( V_3 ) ;
V_14 = F_9 ( V_3 ) ;
V_15 = F_9 ( V_3 ) ;
V_16 = F_9 ( V_3 ) ;
if ( ! F_1 ( V_7 , V_10 , V_3 , V_4 ) )
goto V_17;
if ( ! F_1 ( V_8 , V_11 , V_3 , V_4 ) )
goto V_17;
if ( ! F_10 ( V_15 , V_7 , V_8 , V_3 ) )
goto V_17;
if ( ! F_11 ( V_6 , V_8 , V_7 , V_3 ) )
goto V_17;
if ( ! F_10 ( V_6 , V_6 , V_8 , V_3 ) )
goto V_17;
if ( ! F_11 ( V_14 , V_7 , V_8 , V_3 ) )
goto V_17;
if ( ! F_10 ( V_14 , V_14 , V_7 , V_3 ) )
goto V_17;
if ( ! F_12 ( V_6 , V_6 , V_14 ) )
goto V_17;
if ( V_6 -> V_18 && ! F_13 ( V_6 , V_6 , V_15 ) )
goto V_17;
if ( ! F_14 ( V_6 , V_6 , V_9 , V_15 , V_3 ) )
goto V_17;
if ( ! F_13 ( V_6 , V_6 , V_9 ) )
goto V_17;
for (; ; )
{
int V_5 = 1 ;
F_5 ( V_4 , 0 , V_5 ++ ) ;
if ( ! F_2 ( V_16 , V_6 ) )
goto V_17;
if ( ! F_15 ( V_16 , 1 ) )
goto V_17;
if ( ! F_16 ( V_14 , V_16 , V_12 , V_3 ) )
goto V_17;
if ( F_17 ( V_14 )
&& F_6 ( V_6 , 50 , V_3 , 1 , V_4 ) )
break;
if ( ! F_13 ( V_6 , V_6 , V_15 ) )
goto V_17;
}
F_5 ( V_4 , 3 , 0 ) ;
V_13 = 1 ;
V_17:
F_18 ( V_3 ) ;
return V_13 ;
}
int F_19 ( T_1 * V_9 , T_1 * V_19 , int V_20 , T_2 * V_3 )
{
T_1 * V_14 ;
int V_5 ;
if ( ( V_20 < 1024 ) || ( V_20 & 0xff ) )
return 0 ;
V_20 >>= 1 ;
if ( ! F_20 ( V_9 , V_20 , 1 , 0 ) )
return 0 ;
F_8 ( V_3 ) ;
V_14 = F_9 ( V_3 ) ;
for ( V_5 = 0 ; V_5 < 1000 ; V_5 ++ )
{
if ( ! F_20 ( V_19 , V_20 , 1 , 0 ) )
return 0 ;
F_12 ( V_14 , V_9 , V_19 ) ;
if ( F_21 ( V_14 ) > ( V_20 - 100 ) )
break;
}
F_18 ( V_3 ) ;
if ( V_5 < 1000 )
return 1 ;
return 0 ;
}
int F_22 ( T_1 * V_6 , T_1 * V_7 , T_1 * V_8 ,
T_1 * V_10 , T_1 * V_11 ,
const T_1 * V_9 ,
const T_1 * V_12 , T_2 * V_3 ,
T_3 * V_4 )
{
int V_13 = 0 ;
F_8 ( V_3 ) ;
if ( ! V_10 )
V_10 = F_9 ( V_3 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_3 ) ;
if ( ! F_20 ( V_10 , 101 , 0 , 0 ) )
goto error;
if ( ! F_20 ( V_11 , 101 , 0 , 0 ) )
goto error;
if ( ! F_7 ( V_6 , V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_3 , V_4 ) )
goto error;
V_13 = 1 ;
error:
F_18 ( V_3 ) ;
return V_13 ;
}
