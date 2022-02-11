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
else V_9 = F_3 ( V_2 ) ;
if ( V_10 != NULL )
{
if ( F_4 ( V_1 , V_7 , V_2 , V_10 ) <= 0 ) goto V_12;
}
else
{
if ( F_4 ( V_1 , V_6 , V_9 ) <= 0 ) goto V_12;
}
return ( 1 ) ;
V_12:
return ( 0 ) ;
}
int F_5 ( T_1 * V_1 , unsigned char * V_16 , long V_17 , int V_5 )
{
return ( F_6 ( V_1 , & V_16 , V_17 , 0 , 0 , V_5 ) ) ;
}
static int F_6 ( T_1 * V_1 , unsigned char * * V_16 , long V_18 , int V_19 ,
int V_20 , int V_5 )
{
unsigned char * V_9 , * V_21 , * V_22 , * V_23 , * V_24 ;
long V_17 ;
int V_2 , V_3 , V_25 = 0 ;
int V_26 , V_27 , V_28 , V_29 ;
T_2 * V_30 = NULL ;
T_3 * V_31 = NULL ;
V_9 = * V_16 ;
V_22 = V_9 + V_18 ;
V_23 = V_9 - 1 ;
while ( ( V_9 < V_22 ) && ( V_23 < V_9 ) )
{
V_23 = V_9 ;
V_28 = F_7 ( & V_9 , & V_17 , & V_2 , & V_3 , V_18 ) ;
#ifdef F_8
V_28 = V_28 ;
#endif
if ( V_28 & 0x80 )
{
if ( F_2 ( V_1 , L_8 , 18 ) <= 0 )
goto V_32;
V_25 = 0 ;
goto V_32;
}
V_27 = ( V_9 - V_23 ) ;
V_18 -= V_27 ;
if ( F_4 ( V_1 , L_9 , ( long ) V_19 + ( long ) ( V_23 - * V_16 ) )
<= 0 ) goto V_32;
if ( V_28 != ( V_11 | 1 ) )
{
if ( F_4 ( V_1 , L_10 ,
V_20 , ( long ) V_27 , V_17 ) <= 0 )
goto V_32;
}
else
{
if ( F_4 ( V_1 , L_11 ,
V_20 , ( long ) V_27 ) <= 0 )
goto V_32;
}
if ( ! F_1 ( V_1 , V_2 , V_3 , V_28 , ( V_5 ) ? V_20 : 0 ) )
goto V_32;
if ( V_28 & V_11 )
{
V_21 = V_9 + V_17 ;
if ( F_2 ( V_1 , L_12 , 1 ) <= 0 ) goto V_32;
if ( V_17 > V_18 )
{
F_4 ( V_1 ,
L_13 , V_18 ) ;
V_25 = 0 ;
goto V_32;
}
if ( ( V_28 == 0x21 ) && ( V_17 == 0 ) )
{
for (; ; )
{
V_29 = F_6 ( V_1 , & V_9 , ( long ) ( V_22 - V_9 ) ,
V_19 + ( V_9 - * V_16 ) , V_20 + 1 ,
V_5 ) ;
if ( V_29 == 0 ) { V_25 = 0 ; goto V_32; }
if ( ( V_29 == 2 ) || ( V_9 >= V_22 ) ) break;
}
}
else
while ( V_9 < V_21 )
{
V_29 = F_6 ( V_1 , & V_9 , ( long ) V_17 ,
V_19 + ( V_9 - * V_16 ) , V_20 + 1 ,
V_5 ) ;
if ( V_29 == 0 ) { V_25 = 0 ; goto V_32; }
}
}
else if ( V_3 != 0 )
{
V_9 += V_17 ;
if ( F_2 ( V_1 , L_12 , 1 ) <= 0 ) goto V_32;
}
else
{
V_26 = 0 ;
if ( ( V_2 == V_33 ) ||
( V_2 == V_34 ) ||
( V_2 == V_35 ) ||
( V_2 == V_36 ) ||
( V_2 == V_37 ) ||
( V_2 == V_38 ) )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 ) goto V_32;
if ( ( V_17 > 0 ) &&
F_2 ( V_1 , ( char * ) V_9 , ( int ) V_17 )
!= ( int ) V_17 )
goto V_32;
}
else if ( V_2 == V_39 )
{
V_24 = V_23 ;
if ( F_9 ( & V_30 , & V_24 , V_17 + V_27 ) != NULL )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 ) goto V_32;
F_10 ( V_1 , V_30 ) ;
}
else
{
if ( F_2 ( V_1 , L_15 , 11 ) <= 0 )
goto V_32;
}
}
else if ( V_2 == V_40 )
{
int V_41 ;
V_24 = V_23 ;
V_41 = F_11 ( NULL , & V_24 , V_17 + V_27 ) ;
if ( V_41 < 0 )
{
if ( F_2 ( V_1 , L_16 , 12 ) )
goto V_32;
}
F_4 ( V_1 , L_17 , V_41 ) ;
}
else if ( V_2 == V_42 )
{
}
else if ( V_2 == V_43 )
{
int V_44 , V_45 = 1 ;
V_24 = V_23 ;
V_31 = F_12 ( NULL , & V_24 , V_17 + V_27 ) ;
if ( V_31 != NULL )
{
V_24 = V_31 -> V_46 ;
for ( V_44 = 0 ; V_44 < V_31 -> V_18 ; V_44 ++ )
{
if ( ( ( V_24 [ V_44 ] < ' ' ) &&
( V_24 [ V_44 ] != '\n' ) &&
( V_24 [ V_44 ] != '\r' ) &&
( V_24 [ V_44 ] != '\t' ) ) ||
( V_24 [ V_44 ] > '~' ) )
{
V_45 = 0 ;
break;
}
}
if ( V_45 && ( V_31 -> V_18 > 0 ) )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 )
goto V_32;
if ( F_2 ( V_1 , ( char * ) V_24 ,
V_31 -> V_18 ) <= 0 )
goto V_32;
}
F_13 ( V_31 ) ;
V_31 = NULL ;
}
}
else if ( V_2 == V_47 )
{
T_4 * V_48 ;
int V_44 ;
V_24 = V_23 ;
V_48 = F_14 ( NULL , & V_24 , V_17 + V_27 ) ;
if ( V_48 != NULL )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 ) goto V_32;
if ( V_48 -> type == V_49 )
if ( F_2 ( V_1 , L_18 , 1 ) <= 0 )
goto V_32;
for ( V_44 = 0 ; V_44 < V_48 -> V_18 ; V_44 ++ )
{
if ( F_4 ( V_1 , L_19 ,
V_48 -> V_46 [ V_44 ] ) <= 0 )
goto V_32;
}
if ( V_48 -> V_18 == 0 )
{
if ( F_2 ( V_1 , L_20 , 2 ) <= 0 )
goto V_32;
}
}
else
{
if ( F_2 ( V_1 , L_21 , 11 ) <= 0 )
goto V_32;
}
F_15 ( V_48 ) ;
}
else if ( V_2 == V_50 )
{
T_5 * V_48 ;
int V_44 ;
V_24 = V_23 ;
V_48 = F_16 ( NULL , & V_24 , V_17 + V_27 ) ;
if ( V_48 != NULL )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 ) goto V_32;
if ( V_48 -> type == V_51 )
if ( F_2 ( V_1 , L_18 , 1 ) <= 0 )
goto V_32;
for ( V_44 = 0 ; V_44 < V_48 -> V_18 ; V_44 ++ )
{
if ( F_4 ( V_1 , L_19 ,
V_48 -> V_46 [ V_44 ] ) <= 0 )
goto V_32;
}
if ( V_48 -> V_18 == 0 )
{
if ( F_2 ( V_1 , L_20 , 2 ) <= 0 )
goto V_32;
}
}
else
{
if ( F_2 ( V_1 , L_22 , 11 ) <= 0 )
goto V_32;
}
F_17 ( V_48 ) ;
}
if ( ! V_26 )
{
if ( F_2 ( V_1 , L_12 , 1 ) <= 0 ) goto V_32;
}
V_9 += V_17 ;
if ( ( V_2 == V_52 ) && ( V_3 == 0 ) )
{
V_25 = 2 ;
goto V_32;
}
}
V_18 -= V_17 ;
}
V_25 = 1 ;
V_32:
if ( V_30 != NULL ) F_18 ( V_30 ) ;
if ( V_31 != NULL ) F_13 ( V_31 ) ;
* V_16 = V_9 ;
return ( V_25 ) ;
}
const char * F_3 ( int V_2 )
{
const static char * V_53 [] = {
L_23 , L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 , L_31 , L_32 ,
L_33 , L_34 , L_35 , L_36 ,
L_37 , L_38 , L_39 , L_40 ,
L_41 , L_42 , L_43 ,
L_44 , L_45 , L_46 , L_47 ,
L_48 , L_49 , L_50 ,
L_51 , L_52 , L_53
} ;
if( ( V_2 == V_49 ) || ( V_2 == V_51 ) )
V_2 &= ~ 0x100 ;
if( V_2 < 0 || V_2 > 30 ) return L_54 ;
return V_53 [ V_2 ] ;
}
