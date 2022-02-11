int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
int V_4 ;
if ( ( V_3 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_5 , V_6 ) ;
return ( 0 ) ;
}
F_5 ( V_3 , V_1 , V_7 ) ;
V_4 = F_6 ( V_3 , V_2 ) ;
F_7 ( V_3 ) ;
return ( V_4 ) ;
}
int F_6 ( T_3 * V_8 , T_2 * V_2 )
{
unsigned int V_9 ;
char V_10 [ 128 ] , * V_11 ;
if ( V_2 == NULL ) goto V_12;
if ( F_8 ( V_8 , L_1 ) <= 0 ) goto V_12;
if ( V_2 -> V_13 == V_14 )
V_11 = L_2 ;
else if ( V_2 -> V_13 == V_15 )
V_11 = L_3 ;
else if ( V_2 -> V_13 == V_16 )
V_11 = L_4 ;
else
V_11 = L_5 ;
sprintf ( V_10 , L_6 , V_11 ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
if ( V_2 -> V_17 == NULL )
{
if ( ( ( V_2 -> V_18 ) & 0xff000000 ) == 0x02000000 )
sprintf ( V_10 , L_7 , V_2 -> V_18 & 0xffffff ) ;
else
sprintf ( V_10 , L_8 , V_2 -> V_18 & 0xffff ) ;
}
else
sprintf ( V_10 , L_9 , ( V_2 -> V_17 == NULL ) ? L_5 : V_2 -> V_17 -> V_19 ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
if ( F_8 ( V_8 , L_10 ) <= 0 ) goto V_12;
for ( V_9 = 0 ; V_9 < V_2 -> V_20 ; V_9 ++ )
{
sprintf ( V_10 , L_11 , V_2 -> V_21 [ V_9 ] ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
}
if ( F_8 ( V_8 , L_12 ) <= 0 ) goto V_12;
for ( V_9 = 0 ; V_9 < V_2 -> V_22 ; V_9 ++ )
{
sprintf ( V_10 , L_11 , V_2 -> V_23 [ V_9 ] ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
}
if ( F_8 ( V_8 , L_13 ) <= 0 ) goto V_12;
for ( V_9 = 0 ; V_9 < ( unsigned int ) V_2 -> V_24 ; V_9 ++ )
{
sprintf ( V_10 , L_11 , V_2 -> V_25 [ V_9 ] ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
}
if ( F_8 ( V_8 , L_14 ) <= 0 ) goto V_12;
if ( V_2 -> V_26 == 0 )
{
if ( F_8 ( V_8 , L_15 ) <= 0 ) goto V_12;
}
else
for ( V_9 = 0 ; V_9 < V_2 -> V_26 ; V_9 ++ )
{
sprintf ( V_10 , L_11 , V_2 -> V_27 [ V_9 ] ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
}
if ( V_2 -> V_28 != 0 )
{
T_4 * V_29 ;
F_9 ( V_2 , NULL , NULL , & V_29 ) ;
if ( V_29 == NULL )
{
sprintf ( V_10 , L_16 , V_2 -> V_28 ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
}
else
{
sprintf ( V_10 , L_17 ,
V_29 -> V_30 , V_29 -> V_31 -> V_19 ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
}
}
if ( V_2 -> time != 0L )
{
sprintf ( V_10 , L_18 , V_2 -> time ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
}
if ( V_2 -> V_32 != 0L )
{
sprintf ( V_10 , L_19 , V_2 -> V_32 ) ;
if ( F_8 ( V_8 , V_10 ) <= 0 ) goto V_12;
}
if ( F_8 ( V_8 , L_20 ) <= 0 ) goto V_12;
return ( 1 ) ;
V_12:
return ( 0 ) ;
}
