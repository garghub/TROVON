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
F_8 ( V_18 ) * V_19 ;
char V_20 [ 128 ] ;
V_14 = V_2 -> V_21 ;
sprintf ( V_20 , L_1 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
sprintf ( V_20 , L_2 , L_3 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
V_13 = ( V_14 -> V_23 -> type == V_24 ) ? L_4 : L_3 ;
V_9 = 0 ;
for ( V_10 = 0 ; V_10 < V_14 -> V_23 -> V_25 ; V_10 ++ )
{ V_9 <<= 8 ; V_9 += V_14 -> V_23 -> V_26 [ V_10 ] ; }
sprintf ( V_20 , L_5 , L_3 , V_13 , V_9 , V_13 , V_9 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
sprintf ( V_20 , L_6 , L_3 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
F_10 ( V_8 , V_14 -> V_27 , 16 ) ;
sprintf ( V_20 , L_7 , L_3 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
V_10 = F_11 ( V_14 -> V_28 -> V_29 -> V_30 ) ;
sprintf ( V_20 , L_8 , L_3 ,
( V_10 == V_31 ) ? L_9 : F_12 ( V_10 ) ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
V_15 = F_13 ( V_2 ) ;
#ifndef F_14
if ( V_15 -> type == V_32 )
{
F_15 ( V_8 , L_10 , L_3 ,
F_16 ( V_15 -> V_15 . V_33 -> V_11 ) ) ;
F_17 ( V_8 , V_15 -> V_15 . V_33 , 16 ) ;
}
else
#endif
#ifndef F_18
if ( V_15 -> type == V_34 )
{
F_15 ( V_8 , L_11 , L_3 ) ;
F_19 ( V_8 , V_15 -> V_15 . V_35 , 16 ) ;
}
else
#endif
F_15 ( V_8 , L_12 , L_3 ) ;
F_20 ( V_15 ) ;
sprintf ( V_20 , L_13 , L_3 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
V_17 = V_2 -> V_21 -> V_36 ;
if ( ( V_17 == NULL ) || ( F_21 ( V_17 ) == 0 ) )
{
if ( ! V_2 -> V_21 -> V_37 )
{
sprintf ( V_20 , L_14 , L_3 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
}
}
else
{
for ( V_10 = 0 ; V_10 < F_21 ( V_17 ) ; V_10 ++ )
{
T_6 * V_38 ;
V_16 * V_39 ;
T_7 * V_40 = NULL ;
T_6 * V_41 ;
int V_42 , type = 0 , V_43 = 1 , V_44 = 0 ;
V_39 = F_22 ( V_17 , V_10 ) ;
if( F_23 ( F_11 ( V_39 -> V_45 ) ) )
continue;
sprintf ( V_20 , L_15 , L_3 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
if ( ( V_42 = F_24 ( V_8 , V_39 -> V_45 ) ) > 0 )
{
if ( V_39 -> V_46 )
{
V_44 = 0 ;
V_43 = F_25 ( V_39 -> V_47 . V_46 ) ;
V_48:
V_38 = F_26 ( V_39 -> V_47 . V_46 , V_44 ) ;
type = V_38 -> type ;
V_40 = V_38 -> V_47 . V_49 ;
}
else
{
V_41 = V_39 -> V_47 . V_50 ;
type = V_41 -> type ;
V_40 = V_41 -> V_47 . V_51 ;
}
}
for ( V_42 = 25 - V_42 ; V_42 > 0 ; V_42 -- )
if ( F_27 ( V_8 , L_16 , 1 ) != 1 ) goto V_22;
if ( F_9 ( V_8 , L_17 ) <= 0 ) goto V_22;
if ( ( type == V_52 ) ||
( type == V_53 ) ||
( type == V_54 ) )
{
if ( F_27 ( V_8 , ( char * ) V_40 -> V_26 , V_40 -> V_25 )
!= V_40 -> V_25 )
goto V_22;
F_9 ( V_8 , L_18 ) ;
}
else
{
F_9 ( V_8 , L_19 ) ;
}
if ( ++ V_44 < V_43 ) goto V_48;
}
}
V_19 = F_28 ( V_2 ) ;
if( V_19 ) {
F_15 ( V_8 , L_20 , L_3 ) ;
for ( V_10 = 0 ; V_10 < F_29 ( V_19 ) ; V_10 ++ ) {
T_8 * V_55 ;
V_18 * V_56 ;
int V_42 ;
V_56 = F_30 ( V_19 , V_10 ) ;
if ( F_15 ( V_8 , L_15 , L_3 ) <= 0 ) goto V_22;
V_55 = F_31 ( V_56 ) ;
F_24 ( V_8 , V_55 ) ;
V_42 = F_32 ( V_56 ) ;
if ( F_15 ( V_8 , L_21 , V_42 ? L_22 : L_3 , L_3 ) <= 0 )
goto V_22;
if( ! F_33 ( V_8 , V_56 , 0 , 16 ) ) {
F_15 ( V_8 , L_23 , L_3 ) ;
F_34 ( V_8 , V_56 -> V_47 ) ;
}
if ( F_27 ( V_8 , L_18 , 1 ) <= 0 ) goto V_22;
}
F_35 ( V_19 , V_57 ) ;
}
V_10 = F_11 ( V_2 -> V_58 -> V_30 ) ;
sprintf ( V_20 , L_24 , L_3 ,
( V_10 == V_31 ) ? L_9 : F_12 ( V_10 ) ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
V_11 = V_2 -> V_59 -> V_25 ;
V_12 = ( char * ) V_2 -> V_59 -> V_26 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
{
if ( ( V_10 % 18 ) == 0 )
{
sprintf ( V_20 , L_25 , L_3 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
}
sprintf ( V_20 , L_26 , ( unsigned char ) V_12 [ V_10 ] , ( ( V_10 + 1 ) == V_11 ) ? L_3 : L_17 ) ;
if ( F_9 ( V_8 , V_20 ) <= 0 ) goto V_22;
}
if ( F_9 ( V_8 , L_18 ) <= 0 ) goto V_22;
return ( 1 ) ;
V_22:
F_4 ( V_60 , V_6 ) ;
return ( 0 ) ;
}
