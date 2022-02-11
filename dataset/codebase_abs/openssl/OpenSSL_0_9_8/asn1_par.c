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
F_3 ( V_1 , V_5 , 128 ) ;
V_9 = V_8 ;
if ( ( V_3 & V_13 ) == V_13 )
F_4 ( V_8 , sizeof V_8 , L_5 , V_2 ) ;
else if ( ( V_3 & V_14 ) == V_14 )
F_4 ( V_8 , sizeof V_8 , L_6 , V_2 ) ;
else if ( ( V_3 & V_15 ) == V_15 )
F_4 ( V_8 , sizeof V_8 , L_7 , V_2 ) ;
else V_9 = F_5 ( V_2 ) ;
if ( V_10 != NULL )
{
if ( F_6 ( V_1 , V_7 , V_2 , V_10 ) <= 0 ) goto V_12;
}
else
{
if ( F_6 ( V_1 , V_6 , V_9 ) <= 0 ) goto V_12;
}
return ( 1 ) ;
V_12:
return ( 0 ) ;
}
int F_7 ( T_1 * V_1 , const unsigned char * V_16 , long V_17 , int V_5 )
{
return ( F_8 ( V_1 , & V_16 , V_17 , 0 , 0 , V_5 , 0 ) ) ;
}
int F_9 ( T_1 * V_1 , const unsigned char * V_16 , long V_17 , int V_5 , int V_18 )
{
return ( F_8 ( V_1 , & V_16 , V_17 , 0 , 0 , V_5 , V_18 ) ) ;
}
static int F_8 ( T_1 * V_1 , const unsigned char * * V_16 , long V_19 , int V_20 ,
int V_21 , int V_5 , int V_18 )
{
const unsigned char * V_9 , * V_22 , * V_23 , * V_24 , * V_25 ;
long V_17 ;
int V_2 , V_3 , V_26 = 0 ;
int V_27 , V_28 , V_29 , V_30 ;
T_2 * V_31 = NULL ;
T_3 * V_32 = NULL ;
int V_33 ;
#if 0
dump_indent = indent;
#else
V_33 = 6 ;
#endif
V_9 = * V_16 ;
V_23 = V_9 + V_19 ;
V_24 = V_9 - 1 ;
while ( ( V_9 < V_23 ) && ( V_24 < V_9 ) )
{
V_24 = V_9 ;
V_29 = F_10 ( & V_9 , & V_17 , & V_2 , & V_3 , V_19 ) ;
#ifdef F_11
V_29 = V_29 ;
#endif
if ( V_29 & 0x80 )
{
if ( F_2 ( V_1 , L_8 , 18 ) <= 0 )
goto V_34;
V_26 = 0 ;
goto V_34;
}
V_28 = ( V_9 - V_24 ) ;
V_19 -= V_28 ;
if ( F_6 ( V_1 , L_9 , ( long ) V_20 + ( long ) ( V_24 - * V_16 ) )
<= 0 ) goto V_34;
if ( V_29 != ( V_11 | 1 ) )
{
if ( F_6 ( V_1 , L_10 ,
V_21 , ( long ) V_28 , V_17 ) <= 0 )
goto V_34;
}
else
{
if ( F_6 ( V_1 , L_11 ,
V_21 , ( long ) V_28 ) <= 0 )
goto V_34;
}
if ( ! F_1 ( V_1 , V_2 , V_3 , V_29 , ( V_5 ) ? V_21 : 0 ) )
goto V_34;
if ( V_29 & V_11 )
{
V_22 = V_9 + V_17 ;
if ( F_2 ( V_1 , L_12 , 1 ) <= 0 ) goto V_34;
if ( V_17 > V_19 )
{
F_6 ( V_1 ,
L_13 , V_19 ) ;
V_26 = 0 ;
goto V_34;
}
if ( ( V_29 == 0x21 ) && ( V_17 == 0 ) )
{
for (; ; )
{
V_30 = F_8 ( V_1 , & V_9 , ( long ) ( V_23 - V_9 ) ,
V_20 + ( V_9 - * V_16 ) , V_21 + 1 ,
V_5 , V_18 ) ;
if ( V_30 == 0 ) { V_26 = 0 ; goto V_34; }
if ( ( V_30 == 2 ) || ( V_9 >= V_23 ) ) break;
}
}
else
while ( V_9 < V_22 )
{
V_30 = F_8 ( V_1 , & V_9 , ( long ) V_17 ,
V_20 + ( V_9 - * V_16 ) , V_21 + 1 ,
V_5 , V_18 ) ;
if ( V_30 == 0 ) { V_26 = 0 ; goto V_34; }
}
}
else if ( V_3 != 0 )
{
V_9 += V_17 ;
if ( F_2 ( V_1 , L_12 , 1 ) <= 0 ) goto V_34;
}
else
{
V_27 = 0 ;
if ( ( V_2 == V_35 ) ||
( V_2 == V_36 ) ||
( V_2 == V_37 ) ||
( V_2 == V_38 ) ||
( V_2 == V_39 ) ||
( V_2 == V_40 ) )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 ) goto V_34;
if ( ( V_17 > 0 ) &&
F_2 ( V_1 , ( const char * ) V_9 , ( int ) V_17 )
!= ( int ) V_17 )
goto V_34;
}
else if ( V_2 == V_41 )
{
V_25 = V_24 ;
if ( F_12 ( & V_31 , & V_25 , V_17 + V_28 ) != NULL )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 ) goto V_34;
F_13 ( V_1 , V_31 ) ;
}
else
{
if ( F_2 ( V_1 , L_15 , 11 ) <= 0 )
goto V_34;
}
}
else if ( V_2 == V_42 )
{
int V_43 ;
V_25 = V_24 ;
V_43 = F_14 ( NULL , & V_25 , V_17 + V_28 ) ;
if ( V_43 < 0 )
{
if ( F_2 ( V_1 , L_16 , 12 ) )
goto V_34;
}
F_6 ( V_1 , L_17 , V_43 ) ;
}
else if ( V_2 == V_44 )
{
}
else if ( V_2 == V_45 )
{
int V_46 , V_47 = 1 ;
V_25 = V_24 ;
V_32 = F_15 ( NULL , & V_25 , V_17 + V_28 ) ;
if ( V_32 != NULL && V_32 -> V_19 > 0 )
{
V_25 = V_32 -> V_48 ;
for ( V_46 = 0 ; V_46 < V_32 -> V_19 ; V_46 ++ )
{
if ( ( ( V_25 [ V_46 ] < ' ' ) &&
( V_25 [ V_46 ] != '\n' ) &&
( V_25 [ V_46 ] != '\r' ) &&
( V_25 [ V_46 ] != '\t' ) ) ||
( V_25 [ V_46 ] > '~' ) )
{
V_47 = 0 ;
break;
}
}
if ( V_47 )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 )
goto V_34;
if ( F_2 ( V_1 , ( const char * ) V_25 ,
V_32 -> V_19 ) <= 0 )
goto V_34;
}
else if ( ! V_18 )
{
if ( F_2 ( V_1 , L_18 , 11 ) <= 0 )
goto V_34;
for ( V_46 = 0 ; V_46 < V_32 -> V_19 ; V_46 ++ )
{
if ( F_6 ( V_1 , L_19
, V_25 [ V_46 ] ) <= 0 )
goto V_34;
}
}
else
{
if ( ! V_27 )
{
if ( F_2 ( V_1 , L_12 , 1 ) <= 0 )
goto V_34;
}
if ( F_16 ( V_1 ,
( const char * ) V_25 ,
( ( V_18 == - 1 || V_18 >
V_32 -> V_19 ) ? V_32 -> V_19 : V_18 ) ,
V_33 ) <= 0 )
goto V_34;
V_27 = 1 ;
}
}
if ( V_32 != NULL )
{
F_17 ( V_32 ) ;
V_32 = NULL ;
}
}
else if ( V_2 == V_49 )
{
T_4 * V_50 ;
int V_46 ;
V_25 = V_24 ;
V_50 = F_18 ( NULL , & V_25 , V_17 + V_28 ) ;
if ( V_50 != NULL )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 ) goto V_34;
if ( V_50 -> type == V_51 )
if ( F_2 ( V_1 , L_20 , 1 ) <= 0 )
goto V_34;
for ( V_46 = 0 ; V_46 < V_50 -> V_19 ; V_46 ++ )
{
if ( F_6 ( V_1 , L_19 ,
V_50 -> V_48 [ V_46 ] ) <= 0 )
goto V_34;
}
if ( V_50 -> V_19 == 0 )
{
if ( F_2 ( V_1 , L_21 , 2 ) <= 0 )
goto V_34;
}
}
else
{
if ( F_2 ( V_1 , L_22 , 11 ) <= 0 )
goto V_34;
}
F_19 ( V_50 ) ;
}
else if ( V_2 == V_52 )
{
T_5 * V_50 ;
int V_46 ;
V_25 = V_24 ;
V_50 = F_20 ( NULL , & V_25 , V_17 + V_28 ) ;
if ( V_50 != NULL )
{
if ( F_2 ( V_1 , L_14 , 1 ) <= 0 ) goto V_34;
if ( V_50 -> type == V_53 )
if ( F_2 ( V_1 , L_20 , 1 ) <= 0 )
goto V_34;
for ( V_46 = 0 ; V_46 < V_50 -> V_19 ; V_46 ++ )
{
if ( F_6 ( V_1 , L_19 ,
V_50 -> V_48 [ V_46 ] ) <= 0 )
goto V_34;
}
if ( V_50 -> V_19 == 0 )
{
if ( F_2 ( V_1 , L_21 , 2 ) <= 0 )
goto V_34;
}
}
else
{
if ( F_2 ( V_1 , L_23 , 11 ) <= 0 )
goto V_34;
}
F_21 ( V_50 ) ;
}
else if ( V_17 > 0 && V_18 )
{
if ( ! V_27 )
{
if ( F_2 ( V_1 , L_12 , 1 ) <= 0 )
goto V_34;
}
if ( F_16 ( V_1 , ( const char * ) V_9 ,
( ( V_18 == - 1 || V_18 > V_17 ) ? V_17 : V_18 ) ,
V_33 ) <= 0 )
goto V_34;
V_27 = 1 ;
}
if ( ! V_27 )
{
if ( F_2 ( V_1 , L_12 , 1 ) <= 0 ) goto V_34;
}
V_9 += V_17 ;
if ( ( V_2 == V_54 ) && ( V_3 == 0 ) )
{
V_26 = 2 ;
goto V_34;
}
}
V_19 -= V_17 ;
}
V_26 = 1 ;
V_34:
if ( V_31 != NULL ) F_22 ( V_31 ) ;
if ( V_32 != NULL ) F_17 ( V_32 ) ;
* V_16 = V_9 ;
return ( V_26 ) ;
}
const char * F_5 ( int V_2 )
{
const static char * V_55 [] = {
L_24 , L_25 , L_26 , L_27 , L_28 ,
L_29 , L_30 , L_31 , L_32 , L_33 ,
L_34 , L_35 , L_36 , L_37 ,
L_38 , L_39 , L_40 , L_41 ,
L_42 , L_43 , L_44 ,
L_45 , L_46 , L_47 , L_48 ,
L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54
} ;
if( ( V_2 == V_51 ) || ( V_2 == V_53 ) )
V_2 &= ~ 0x100 ;
if( V_2 < 0 || V_2 > 30 ) return L_55 ;
return V_55 [ V_2 ] ;
}
