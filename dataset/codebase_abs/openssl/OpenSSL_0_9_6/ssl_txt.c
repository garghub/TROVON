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
char * V_10 ;
if ( V_2 == NULL ) goto V_11;
if ( F_8 ( V_8 , L_1 ) <= 0 ) goto V_11;
if ( V_2 -> V_12 == V_13 )
V_10 = L_2 ;
else if ( V_2 -> V_12 == V_14 )
V_10 = L_3 ;
else if ( V_2 -> V_12 == V_15 )
V_10 = L_4 ;
else
V_10 = L_5 ;
if ( F_9 ( V_8 , L_6 , V_10 ) <= 0 ) goto V_11;
if ( V_2 -> V_16 == NULL )
{
if ( ( ( V_2 -> V_17 ) & 0xff000000 ) == 0x02000000 )
{
if ( F_9 ( V_8 , L_7 , V_2 -> V_17 & 0xffffff ) <= 0 )
goto V_11;
}
else
{
if ( F_9 ( V_8 , L_8 , V_2 -> V_17 & 0xffff ) <= 0 )
goto V_11;
}
}
else
{
if ( F_9 ( V_8 , L_9 , ( ( V_2 -> V_16 == NULL ) ? L_5 : V_2 -> V_16 -> V_18 ) ) <= 0 )
goto V_11;
}
if ( F_8 ( V_8 , L_10 ) <= 0 ) goto V_11;
for ( V_9 = 0 ; V_9 < V_2 -> V_19 ; V_9 ++ )
{
if ( F_9 ( V_8 , L_11 , V_2 -> V_20 [ V_9 ] ) <= 0 ) goto V_11;
}
if ( F_8 ( V_8 , L_12 ) <= 0 ) goto V_11;
for ( V_9 = 0 ; V_9 < V_2 -> V_21 ; V_9 ++ )
{
if ( F_9 ( V_8 , L_11 , V_2 -> V_22 [ V_9 ] ) <= 0 )
goto V_11;
}
if ( F_8 ( V_8 , L_13 ) <= 0 ) goto V_11;
for ( V_9 = 0 ; V_9 < ( unsigned int ) V_2 -> V_23 ; V_9 ++ )
{
if ( F_9 ( V_8 , L_11 , V_2 -> V_24 [ V_9 ] ) <= 0 ) goto V_11;
}
if ( F_8 ( V_8 , L_14 ) <= 0 ) goto V_11;
if ( V_2 -> V_25 == 0 )
{
if ( F_8 ( V_8 , L_15 ) <= 0 ) goto V_11;
}
else
for ( V_9 = 0 ; V_9 < V_2 -> V_25 ; V_9 ++ )
{
if ( F_9 ( V_8 , L_11 , V_2 -> V_26 [ V_9 ] ) <= 0 ) goto V_11;
}
if ( V_2 -> V_27 != 0 )
{
T_4 * V_28 ;
F_10 ( V_2 , NULL , NULL , & V_28 ) ;
if ( V_28 == NULL )
{
if ( F_9 ( V_8 , L_16 , V_2 -> V_27 ) <= 0 ) goto V_11;
}
else
{
if ( F_9 ( V_8 , L_17 , V_28 -> V_29 , V_28 -> V_30 -> V_18 ) <= 0 ) goto V_11;
}
}
if ( V_2 -> time != 0L )
{
if ( F_9 ( V_8 , L_18 , V_2 -> time ) <= 0 ) goto V_11;
}
if ( V_2 -> V_31 != 0L )
{
if ( F_9 ( V_8 , L_19 , V_2 -> V_31 ) <= 0 ) goto V_11;
}
if ( F_8 ( V_8 , L_20 ) <= 0 ) goto V_11;
if ( F_8 ( V_8 , L_21 ) <= 0 ) goto V_11;
if ( F_9 ( V_8 , L_22 , V_2 -> V_32 ,
F_11 ( V_2 -> V_32 ) ) <= 0 ) goto V_11;
return ( 1 ) ;
V_11:
return ( 0 ) ;
}
