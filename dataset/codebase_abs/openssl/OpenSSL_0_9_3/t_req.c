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
unsigned long V_9 ;
int V_10 , V_11 ;
char * V_12 ;
const char * V_13 ;
T_4 * V_14 ;
T_5 * V_15 ;
F_8 ( V_16 ) * V_17 ;
char V_18 [ 128 ] ;
V_14 = V_2 -> V_19 ;
sprintf ( V_18 , L_1 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
sprintf ( V_18 , L_2 , L_3 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
V_13 = ( V_14 -> V_21 -> type == V_22 ) ? L_4 : L_3 ;
V_9 = 0 ;
for ( V_10 = 0 ; V_10 < V_14 -> V_21 -> V_23 ; V_10 ++ )
{ V_9 <<= 8 ; V_9 += V_14 -> V_21 -> V_24 [ V_10 ] ; }
sprintf ( V_18 , L_5 , L_3 , V_13 , V_9 , V_13 , V_9 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
sprintf ( V_18 , L_6 , L_3 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
F_10 ( V_8 , V_14 -> V_25 , 16 ) ;
sprintf ( V_18 , L_7 , L_3 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
V_10 = F_11 ( V_14 -> V_26 -> V_27 -> V_28 ) ;
sprintf ( V_18 , L_8 , L_3 ,
( V_10 == V_29 ) ? L_9 : F_12 ( V_10 ) ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
V_15 = F_13 ( V_2 ) ;
#ifndef F_14
if ( V_15 -> type == V_30 )
{
F_15 ( V_8 , L_10 , L_3 ,
F_16 ( V_15 -> V_15 . V_31 -> V_11 ) ) ;
F_17 ( V_8 , V_15 -> V_15 . V_31 , 16 ) ;
}
else
#endif
#ifndef F_18
if ( V_15 -> type == V_32 )
{
F_15 ( V_8 , L_11 , L_3 ) ;
F_19 ( V_8 , V_15 -> V_15 . V_33 , 16 ) ;
}
else
#endif
F_15 ( V_8 , L_12 , L_3 ) ;
F_20 ( V_15 ) ;
sprintf ( V_18 , L_13 , L_3 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
V_17 = V_2 -> V_19 -> V_34 ;
if ( ( V_17 == NULL ) || ( F_21 ( V_17 ) == 0 ) )
{
if ( ! V_2 -> V_19 -> V_35 )
{
sprintf ( V_18 , L_14 , L_3 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
}
}
else
{
for ( V_10 = 0 ; V_10 < F_21 ( V_17 ) ; V_10 ++ )
{
T_6 * V_36 ;
V_16 * V_37 ;
T_7 * V_38 = NULL ;
T_6 * V_39 ;
int V_40 , type = 0 , V_41 = 1 , V_42 = 0 ;
V_37 = F_22 ( V_17 , V_10 ) ;
sprintf ( V_18 , L_15 , L_3 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
if ( ( V_40 = F_23 ( V_8 , V_37 -> V_43 ) ) > 0 )
{
if ( V_37 -> V_44 )
{
V_42 = 0 ;
V_41 = F_24 ( V_37 -> V_45 . V_44 ) ;
V_46:
V_36 = F_25 ( V_37 -> V_45 . V_44 , V_42 ) ;
type = V_36 -> type ;
V_38 = V_36 -> V_45 . V_47 ;
}
else
{
V_39 = V_37 -> V_45 . V_48 ;
type = V_39 -> type ;
V_38 = V_39 -> V_45 . V_49 ;
}
}
for ( V_40 = 25 - V_40 ; V_40 > 0 ; V_40 -- )
if ( F_26 ( V_8 , L_16 , 1 ) != 1 ) goto V_20;
if ( F_9 ( V_8 , L_17 ) <= 0 ) goto V_20;
if ( ( type == V_50 ) ||
( type == V_51 ) ||
( type == V_52 ) )
{
if ( F_26 ( V_8 , ( char * ) V_38 -> V_24 , V_38 -> V_23 )
!= V_38 -> V_23 )
goto V_20;
F_9 ( V_8 , L_18 ) ;
}
else
{
F_9 ( V_8 , L_19 ) ;
}
if ( ++ V_42 < V_41 ) goto V_46;
}
}
V_10 = F_11 ( V_2 -> V_53 -> V_28 ) ;
sprintf ( V_18 , L_20 , L_3 ,
( V_10 == V_29 ) ? L_9 : F_12 ( V_10 ) ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
V_11 = V_2 -> V_54 -> V_23 ;
V_12 = ( char * ) V_2 -> V_54 -> V_24 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
{
if ( ( V_10 % 18 ) == 0 )
{
sprintf ( V_18 , L_21 , L_3 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
}
sprintf ( V_18 , L_22 , ( unsigned char ) V_12 [ V_10 ] , ( ( V_10 + 1 ) == V_11 ) ? L_3 : L_17 ) ;
if ( F_9 ( V_8 , V_18 ) <= 0 ) goto V_20;
}
if ( F_9 ( V_8 , L_18 ) <= 0 ) goto V_20;
return ( 1 ) ;
V_20:
F_4 ( V_55 , V_6 ) ;
return ( 0 ) ;
}
