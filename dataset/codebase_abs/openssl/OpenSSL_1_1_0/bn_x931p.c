static int F_1 ( T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 )
{
int V_5 = 0 , V_6 ;
if ( ! F_2 ( V_1 , V_2 ) )
return 0 ;
if ( ! F_3 ( V_1 ) && ! F_4 ( V_1 , 1 ) )
return 0 ;
for (; ; ) {
V_5 ++ ;
F_5 ( V_4 , 0 , V_5 ) ;
V_6 = F_6 ( V_1 , 27 , V_3 , 1 , V_4 ) ;
if ( V_6 < 0 )
return 0 ;
if ( V_6 )
break;
if ( ! F_4 ( V_1 , 2 ) )
return 0 ;
}
F_5 ( V_4 , 2 , V_5 ) ;
return 1 ;
}
int F_7 ( T_1 * V_7 , T_1 * V_8 , T_1 * V_9 ,
const T_1 * V_10 , const T_1 * V_11 ,
const T_1 * V_12 , const T_1 * V_13 , T_2 * V_3 ,
T_3 * V_4 )
{
int V_14 = 0 ;
T_1 * V_15 , * V_16 , * V_17 ;
if ( ! F_3 ( V_13 ) )
return 0 ;
F_8 ( V_3 ) ;
if ( ! V_8 )
V_8 = F_9 ( V_3 ) ;
if ( ! V_9 )
V_9 = F_9 ( V_3 ) ;
V_15 = F_9 ( V_3 ) ;
V_16 = F_9 ( V_3 ) ;
V_17 = F_9 ( V_3 ) ;
if ( V_17 == NULL )
goto V_18;
if ( ! F_1 ( V_8 , V_11 , V_3 , V_4 ) )
goto V_18;
if ( ! F_1 ( V_9 , V_12 , V_3 , V_4 ) )
goto V_18;
if ( ! F_10 ( V_16 , V_8 , V_9 , V_3 ) )
goto V_18;
if ( ! F_11 ( V_7 , V_9 , V_8 , V_3 ) )
goto V_18;
if ( ! F_10 ( V_7 , V_7 , V_9 , V_3 ) )
goto V_18;
if ( ! F_11 ( V_15 , V_8 , V_9 , V_3 ) )
goto V_18;
if ( ! F_10 ( V_15 , V_15 , V_8 , V_3 ) )
goto V_18;
if ( ! F_12 ( V_7 , V_7 , V_15 ) )
goto V_18;
if ( V_7 -> V_19 && ! F_13 ( V_7 , V_7 , V_16 ) )
goto V_18;
if ( ! F_14 ( V_7 , V_7 , V_10 , V_16 , V_3 ) )
goto V_18;
if ( ! F_13 ( V_7 , V_7 , V_10 ) )
goto V_18;
for (; ; ) {
int V_5 = 1 ;
F_5 ( V_4 , 0 , V_5 ++ ) ;
if ( ! F_2 ( V_17 , V_7 ) )
goto V_18;
if ( ! F_15 ( V_17 , 1 ) )
goto V_18;
if ( ! F_16 ( V_15 , V_17 , V_13 , V_3 ) )
goto V_18;
if ( F_17 ( V_15 ) ) {
int V_20 = F_6 ( V_7 , 50 , V_3 , 1 , V_4 ) ;
if ( V_20 < 0 )
goto V_18;
if ( V_20 )
break;
}
if ( ! F_13 ( V_7 , V_7 , V_16 ) )
goto V_18;
}
F_5 ( V_4 , 3 , 0 ) ;
V_14 = 1 ;
V_18:
F_18 ( V_3 ) ;
return V_14 ;
}
int F_19 ( T_1 * V_10 , T_1 * V_21 , int V_22 , T_2 * V_3 )
{
T_1 * V_15 ;
int V_5 ;
if ( ( V_22 < 1024 ) || ( V_22 & 0xff ) )
return 0 ;
V_22 >>= 1 ;
if ( ! F_20 ( V_10 , V_22 , V_23 , V_24 ) )
goto V_18;
F_8 ( V_3 ) ;
V_15 = F_9 ( V_3 ) ;
for ( V_5 = 0 ; V_5 < 1000 ; V_5 ++ ) {
if ( ! F_20 ( V_21 , V_22 , V_23 , V_24 ) )
goto V_18;
F_12 ( V_15 , V_10 , V_21 ) ;
if ( F_21 ( V_15 ) > ( V_22 - 100 ) )
break;
}
F_18 ( V_3 ) ;
if ( V_5 < 1000 )
return 1 ;
return 0 ;
V_18:
F_18 ( V_3 ) ;
return 0 ;
}
int F_22 ( T_1 * V_7 , T_1 * V_8 , T_1 * V_9 ,
T_1 * V_11 , T_1 * V_12 ,
const T_1 * V_10 ,
const T_1 * V_13 , T_2 * V_3 , T_3 * V_4 )
{
int V_14 = 0 ;
F_8 ( V_3 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_3 ) ;
if ( ! V_12 )
V_12 = F_9 ( V_3 ) ;
if ( ! F_20 ( V_11 , 101 , V_25 , V_24 ) )
goto error;
if ( ! F_20 ( V_12 , 101 , V_25 , V_24 ) )
goto error;
if ( ! F_7 ( V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 , V_3 , V_4 ) )
goto error;
V_14 = 1 ;
error:
F_18 ( V_3 ) ;
return V_14 ;
}
