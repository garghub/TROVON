static int F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 ,
int V_5 )
{
static const char V_6 [] = L_1 ;
static const char V_7 [] = L_2 ;
char V_8 [ 128 ] ;
const char * V_9 , * V_10 = NULL ;
if ( V_4 & V_11 )
V_9 = L_3 ;
else
V_9 = L_4 ;
if ( F_2 ( V_1 , V_9 , 6 ) < 6 ) goto V_12;
if ( V_5 )
{
if ( V_5 > 128 ) V_5 = 128 ;
memset ( V_8 , ' ' , V_5 ) ;
if ( F_2 ( V_1 , V_8 , V_5 ) < V_5 ) goto V_12;
}
V_9 = V_8 ;
if ( ( V_3 & V_13 ) == V_13 )
sprintf ( V_8 , L_5 , V_2 ) ;
else if ( ( V_3 & V_14 ) == V_14 )
sprintf ( V_8 , L_6 , V_2 ) ;
else if ( ( V_3 & V_15 ) == V_15 )
sprintf ( V_8 , L_7 , V_2 ) ;
else if ( ( V_2 == V_16 ) )
V_9 = L_8 ;
else if ( V_2 == V_17 )
V_9 = L_9 ;
else if ( V_2 == V_18 )
V_9 = L_10 ;
else if ( V_2 == V_19 )
V_9 = L_11 ;
else if ( V_2 == V_20 )
V_9 = L_12 ;
else if ( V_2 == V_21 )
V_9 = L_13 ;
else if ( V_2 == V_22 )
V_9 = L_14 ;
else if ( V_2 == V_23 )
V_9 = L_15 ;
else if ( V_2 == V_24 )
V_9 = L_16 ;
else if ( V_2 == V_25 )
V_9 = L_17 ;
else if ( V_2 == V_26 )
V_9 = L_18 ;
else if ( V_2 == V_27 )
V_9 = L_19 ;
else if ( V_2 == V_28 )
V_9 = L_20 ;
else if ( V_2 == V_29 )
V_9 = L_21 ;
else if ( V_2 == V_30 )
V_9 = L_22 ;
else if ( V_2 == V_31 )
V_9 = L_23 ;
else if ( V_2 == V_32 )
V_9 = L_24 ;
else if ( V_2 == V_33 )
V_9 = L_25 ;
else if ( V_2 == V_34 )
V_9 = L_26 ;
else if ( V_2 == V_35 )
V_9 = L_27 ;
else if ( V_2 == V_36 )
V_9 = L_28 ;
else if ( V_2 == V_37 )
V_9 = L_29 ;
else
V_10 = L_30 ;
if ( V_10 != NULL )
{
if ( F_3 ( V_1 , V_7 , V_2 , V_10 ) <= 0 ) goto V_12;
}
else
{
if ( F_3 ( V_1 , V_6 , V_9 ) <= 0 ) goto V_12;
}
return ( 1 ) ;
V_12:
return ( 0 ) ;
}
int F_4 ( T_1 * V_1 , unsigned char * V_38 , long V_39 , int V_5 )
{
return ( F_5 ( V_1 , & V_38 , V_39 , 0 , 0 , V_5 ) ) ;
}
static int F_5 ( T_1 * V_1 , unsigned char * * V_38 , long V_40 , int V_41 ,
int V_42 , int V_5 )
{
unsigned char * V_9 , * V_43 , * V_44 , * V_45 , * V_46 ;
long V_39 ;
int V_2 , V_3 , V_47 = 0 ;
int V_48 , V_49 , V_50 , V_51 ;
T_2 * V_52 = NULL ;
T_3 * V_53 = NULL ;
V_9 = * V_38 ;
V_44 = V_9 + V_40 ;
V_45 = V_9 - 1 ;
while ( ( V_9 < V_44 ) && ( V_45 < V_9 ) )
{
V_45 = V_9 ;
V_50 = F_6 ( & V_9 , & V_39 , & V_2 , & V_3 , V_40 ) ;
#ifdef F_7
V_50 = V_50 ;
#endif
if ( V_50 & 0x80 )
{
if ( F_2 ( V_1 , L_31 , 18 ) <= 0 )
goto V_54;
V_47 = 0 ;
goto V_54;
}
V_49 = ( V_9 - V_45 ) ;
V_40 -= V_49 ;
if ( F_3 ( V_1 , L_32 , ( long ) V_41 + ( long ) ( V_45 - * V_38 ) )
<= 0 ) goto V_54;
if ( V_50 != ( V_11 | 1 ) )
{
if ( F_3 ( V_1 , L_33 ,
V_42 , ( long ) V_49 , V_39 ) <= 0 )
goto V_54;
}
else
{
if ( F_3 ( V_1 , L_34 ,
V_42 , ( long ) V_49 ) <= 0 )
goto V_54;
}
if ( ! F_1 ( V_1 , V_2 , V_3 , V_50 , ( V_5 ) ? V_42 : 0 ) )
goto V_54;
if ( V_50 & V_11 )
{
V_43 = V_9 + V_39 ;
if ( F_2 ( V_1 , L_35 , 1 ) <= 0 ) goto V_54;
if ( V_39 > V_40 )
{
F_3 ( V_1 ,
L_36 , V_40 ) ;
V_47 = 0 ;
goto V_54;
}
if ( ( V_50 == 0x21 ) && ( V_39 == 0 ) )
{
for (; ; )
{
V_51 = F_5 ( V_1 , & V_9 , ( long ) ( V_44 - V_9 ) ,
V_41 + ( V_9 - * V_38 ) , V_42 + 1 ,
V_5 ) ;
if ( V_51 == 0 ) { V_47 = 0 ; goto V_54; }
if ( ( V_51 == 2 ) || ( V_9 >= V_44 ) ) break;
}
}
else
while ( V_9 < V_43 )
{
V_51 = F_5 ( V_1 , & V_9 , ( long ) V_39 ,
V_41 + ( V_9 - * V_38 ) , V_42 + 1 ,
V_5 ) ;
if ( V_51 == 0 ) { V_47 = 0 ; goto V_54; }
}
}
else if ( V_3 != 0 )
{
V_9 += V_39 ;
if ( F_2 ( V_1 , L_35 , 1 ) <= 0 ) goto V_54;
}
else
{
V_48 = 0 ;
if ( ( V_2 == V_26 ) ||
( V_2 == V_27 ) ||
( V_2 == V_28 ) ||
( V_2 == V_34 ) ||
( V_2 == V_29 ) ||
( V_2 == V_32 ) )
{
if ( F_2 ( V_1 , L_37 , 1 ) <= 0 ) goto V_54;
if ( ( V_39 > 0 ) &&
F_2 ( V_1 , ( char * ) V_9 , ( int ) V_39 )
!= ( int ) V_39 )
goto V_54;
}
else if ( V_2 == V_23 )
{
V_46 = V_45 ;
if ( F_8 ( & V_52 , & V_46 , V_39 + V_49 ) != NULL )
{
if ( F_2 ( V_1 , L_37 , 1 ) <= 0 ) goto V_54;
F_9 ( V_1 , V_52 ) ;
}
else
{
if ( F_2 ( V_1 , L_38 , 11 ) <= 0 )
goto V_54;
}
}
else if ( V_2 == V_17 )
{
int V_55 ;
V_46 = V_45 ;
V_55 = F_10 ( NULL , & V_46 , V_39 + V_49 ) ;
if ( V_55 < 0 )
{
if ( F_2 ( V_1 , L_39 , 12 ) )
goto V_54;
}
F_3 ( V_1 , L_40 , V_55 ) ;
}
else if ( V_2 == V_37 )
{
}
else if ( V_2 == V_21 )
{
int V_56 , V_57 = 1 ;
V_46 = V_45 ;
V_53 = F_11 ( NULL , & V_46 , V_39 + V_49 ) ;
if ( V_53 != NULL )
{
V_46 = V_53 -> V_58 ;
for ( V_56 = 0 ; V_56 < V_53 -> V_40 ; V_56 ++ )
{
if ( ( ( V_46 [ V_56 ] < ' ' ) &&
( V_46 [ V_56 ] != '\n' ) &&
( V_46 [ V_56 ] != '\r' ) &&
( V_46 [ V_56 ] != '\t' ) ) ||
( V_46 [ V_56 ] > '~' ) )
{
V_57 = 0 ;
break;
}
}
if ( V_57 && ( V_53 -> V_40 > 0 ) )
{
if ( F_2 ( V_1 , L_37 , 1 ) <= 0 )
goto V_54;
if ( F_2 ( V_1 , ( char * ) V_46 ,
V_53 -> V_40 ) <= 0 )
goto V_54;
}
F_12 ( V_53 ) ;
V_53 = NULL ;
}
}
else if ( V_2 == V_18 )
{
T_4 * V_59 ;
int V_56 ;
V_46 = V_45 ;
V_59 = F_13 ( NULL , & V_46 , V_39 + V_49 ) ;
if ( V_59 != NULL )
{
if ( F_2 ( V_1 , L_37 , 1 ) <= 0 ) goto V_54;
if ( V_59 -> type == V_60 )
if ( F_2 ( V_1 , L_41 , 1 ) <= 0 )
goto V_54;
for ( V_56 = 0 ; V_56 < V_59 -> V_40 ; V_56 ++ )
{
if ( F_3 ( V_1 , L_42 ,
V_59 -> V_58 [ V_56 ] ) <= 0 )
goto V_54;
}
if ( V_59 -> V_40 == 0 )
{
if ( F_2 ( V_1 , L_43 , 2 ) <= 0 )
goto V_54;
}
}
else
{
if ( F_2 ( V_1 , L_44 , 11 ) <= 0 )
goto V_54;
}
F_14 ( V_59 ) ;
}
else if ( V_2 == V_19 )
{
T_5 * V_59 ;
int V_56 ;
V_46 = V_45 ;
V_59 = F_15 ( NULL , & V_46 , V_39 + V_49 ) ;
if ( V_59 != NULL )
{
if ( F_2 ( V_1 , L_37 , 1 ) <= 0 ) goto V_54;
if ( V_59 -> type == V_61 )
if ( F_2 ( V_1 , L_41 , 1 ) <= 0 )
goto V_54;
for ( V_56 = 0 ; V_56 < V_59 -> V_40 ; V_56 ++ )
{
if ( F_3 ( V_1 , L_42 ,
V_59 -> V_58 [ V_56 ] ) <= 0 )
goto V_54;
}
if ( V_59 -> V_40 == 0 )
{
if ( F_2 ( V_1 , L_43 , 2 ) <= 0 )
goto V_54;
}
}
else
{
if ( F_2 ( V_1 , L_45 , 11 ) <= 0 )
goto V_54;
}
F_16 ( V_59 ) ;
}
if ( ! V_48 )
{
if ( F_2 ( V_1 , L_35 , 1 ) <= 0 ) goto V_54;
}
V_9 += V_39 ;
if ( ( V_2 == V_16 ) && ( V_3 == 0 ) )
{
V_47 = 2 ;
goto V_54;
}
}
V_40 -= V_39 ;
}
V_47 = 1 ;
V_54:
if ( V_52 != NULL ) F_17 ( V_52 ) ;
if ( V_53 != NULL ) F_12 ( V_53 ) ;
* V_38 = V_9 ;
return ( V_47 ) ;
}
