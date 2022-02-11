static int F_1 ( T_1 * V_1 , int V_2 , int V_3 , int V_4 ,
int V_5 )
{
static const char V_6 [] = L_1 ;
char V_7 [ 128 ] ;
const char * V_8 ;
if ( V_4 & V_9 )
V_8 = L_2 ;
else
V_8 = L_3 ;
if ( F_2 ( V_1 , V_8 , 6 ) < 6 )
goto V_10;
F_3 ( V_1 , V_5 , 128 ) ;
V_8 = V_7 ;
if ( ( V_3 & V_11 ) == V_11 )
F_4 ( V_7 , sizeof V_7 , L_4 , V_2 ) ;
else if ( ( V_3 & V_12 ) == V_12 )
F_4 ( V_7 , sizeof V_7 , L_5 , V_2 ) ;
else if ( ( V_3 & V_13 ) == V_13 )
F_4 ( V_7 , sizeof V_7 , L_6 , V_2 ) ;
else if ( V_2 > 30 )
F_4 ( V_7 , sizeof V_7 , L_7 , V_2 ) ;
else
V_8 = F_5 ( V_2 ) ;
if ( F_6 ( V_1 , V_6 , V_8 ) <= 0 )
goto V_10;
return ( 1 ) ;
V_10:
return ( 0 ) ;
}
int F_7 ( T_1 * V_1 , const unsigned char * V_14 , long V_15 , int V_5 )
{
return ( F_8 ( V_1 , & V_14 , V_15 , 0 , 0 , V_5 , 0 ) ) ;
}
int F_9 ( T_1 * V_1 , const unsigned char * V_14 , long V_15 , int V_5 ,
int V_16 )
{
return ( F_8 ( V_1 , & V_14 , V_15 , 0 , 0 , V_5 , V_16 ) ) ;
}
static int F_8 ( T_1 * V_1 , const unsigned char * * V_14 , long V_17 ,
int V_18 , int V_19 , int V_5 , int V_16 )
{
const unsigned char * V_8 , * V_20 , * V_21 , * V_22 , * V_23 ;
long V_15 ;
int V_2 , V_3 , V_24 = 0 ;
int V_25 , V_26 , V_27 , V_28 ;
T_2 * V_29 = NULL ;
T_3 * V_30 = NULL ;
int V_31 , V_32 = 0 ;
if ( V_19 > V_33 ) {
F_10 ( V_1 , L_8 ) ;
return 0 ;
}
V_31 = 6 ;
V_8 = * V_14 ;
V_21 = V_8 + V_17 ;
while ( V_17 > 0 ) {
V_22 = V_8 ;
V_27 = F_11 ( & V_8 , & V_15 , & V_2 , & V_3 , V_17 ) ;
if ( V_27 & 0x80 ) {
if ( F_2 ( V_1 , L_9 , 18 ) <= 0 )
goto V_34;
V_24 = 0 ;
goto V_34;
}
V_26 = ( V_8 - V_22 ) ;
V_17 -= V_26 ;
if ( F_6 ( V_1 , L_10 , ( long ) V_18 + ( long ) ( V_22 - * V_14 ) )
<= 0 )
goto V_34;
if ( V_27 != ( V_9 | 1 ) ) {
if ( F_6 ( V_1 , L_11 ,
V_19 , ( long ) V_26 , V_15 ) <= 0 )
goto V_34;
} else {
if ( F_6 ( V_1 , L_12 , V_19 , ( long ) V_26 ) <= 0 )
goto V_34;
}
if ( ! F_1 ( V_1 , V_2 , V_3 , V_27 , ( V_5 ) ? V_19 : 0 ) )
goto V_34;
if ( V_27 & V_9 ) {
const unsigned char * V_35 = V_8 ;
V_20 = V_8 + V_15 ;
if ( F_2 ( V_1 , L_13 , 1 ) <= 0 )
goto V_34;
if ( V_15 > V_17 ) {
F_6 ( V_1 , L_14 , V_17 ) ;
V_24 = 0 ;
goto V_34;
}
if ( ( V_27 == 0x21 ) && ( V_15 == 0 ) ) {
for (; ; ) {
V_28 = F_8 ( V_1 , & V_8 , ( long ) ( V_21 - V_8 ) ,
V_18 + ( V_8 - * V_14 ) , V_19 + 1 ,
V_5 , V_16 ) ;
if ( V_28 == 0 ) {
V_24 = 0 ;
goto V_34;
}
if ( ( V_28 == 2 ) || ( V_8 >= V_21 ) ) {
V_15 = V_8 - V_35 ;
break;
}
}
} else {
long V_36 = V_15 ;
while ( V_8 < V_20 ) {
V_35 = V_8 ;
V_28 = F_8 ( V_1 , & V_8 , V_36 ,
V_18 + ( V_8 - * V_14 ) , V_19 + 1 ,
V_5 , V_16 ) ;
if ( V_28 == 0 ) {
V_24 = 0 ;
goto V_34;
}
V_36 -= V_8 - V_35 ;
}
}
} else if ( V_3 != 0 ) {
V_8 += V_15 ;
if ( F_2 ( V_1 , L_13 , 1 ) <= 0 )
goto V_34;
} else {
V_25 = 0 ;
if ( ( V_2 == V_37 ) ||
( V_2 == V_38 ) ||
( V_2 == V_39 ) ||
( V_2 == V_40 ) ||
( V_2 == V_41 ) ||
( V_2 == V_42 ) ||
( V_2 == V_43 ) || ( V_2 == V_44 ) ) {
if ( F_2 ( V_1 , L_15 , 1 ) <= 0 )
goto V_34;
if ( ( V_15 > 0 ) && F_2 ( V_1 , ( const char * ) V_8 , ( int ) V_15 )
!= ( int ) V_15 )
goto V_34;
} else if ( V_2 == V_45 ) {
V_23 = V_22 ;
if ( F_12 ( & V_29 , & V_23 , V_15 + V_26 ) != NULL ) {
if ( F_2 ( V_1 , L_15 , 1 ) <= 0 )
goto V_34;
F_13 ( V_1 , V_29 ) ;
} else {
if ( F_10 ( V_1 , L_16 ) <= 0 )
goto V_34;
V_32 = 1 ;
}
} else if ( V_2 == V_46 ) {
if ( V_15 != 1 ) {
if ( F_10 ( V_1 , L_17 ) <= 0 )
goto V_34;
V_32 = 1 ;
}
if ( V_15 > 0 )
F_6 ( V_1 , L_18 , V_8 [ 0 ] ) ;
} else if ( V_2 == V_47 ) {
} else if ( V_2 == V_48 ) {
int V_49 , V_50 = 1 ;
V_23 = V_22 ;
V_30 = F_14 ( NULL , & V_23 , V_15 + V_26 ) ;
if ( V_30 != NULL && V_30 -> V_17 > 0 ) {
V_23 = V_30 -> V_51 ;
for ( V_49 = 0 ; V_49 < V_30 -> V_17 ; V_49 ++ ) {
if ( ( ( V_23 [ V_49 ] < ' ' ) &&
( V_23 [ V_49 ] != '\n' ) &&
( V_23 [ V_49 ] != '\r' ) &&
( V_23 [ V_49 ] != '\t' ) ) || ( V_23 [ V_49 ] > '~' ) ) {
V_50 = 0 ;
break;
}
}
if ( V_50 )
{
if ( F_2 ( V_1 , L_15 , 1 ) <= 0 )
goto V_34;
if ( F_2 ( V_1 , ( const char * ) V_23 , V_30 -> V_17 ) <= 0 )
goto V_34;
} else if ( ! V_16 )
{
if ( F_2 ( V_1 , L_19 , 11 ) <= 0 )
goto V_34;
for ( V_49 = 0 ; V_49 < V_30 -> V_17 ; V_49 ++ ) {
if ( F_6 ( V_1 , L_20 , V_23 [ V_49 ] ) <= 0 )
goto V_34;
}
} else
{
if ( ! V_25 ) {
if ( F_2 ( V_1 , L_13 , 1 ) <= 0 )
goto V_34;
}
if ( F_15 ( V_1 ,
( const char * ) V_23 ,
( ( V_16 == - 1 || V_16 >
V_30 ->
V_17 ) ? V_30 -> V_17 : V_16 ) ,
V_31 ) <= 0 )
goto V_34;
V_25 = 1 ;
}
}
F_16 ( V_30 ) ;
V_30 = NULL ;
} else if ( V_2 == V_52 ) {
T_4 * V_53 ;
int V_49 ;
V_23 = V_22 ;
V_53 = F_17 ( NULL , & V_23 , V_15 + V_26 ) ;
if ( V_53 != NULL ) {
if ( F_2 ( V_1 , L_15 , 1 ) <= 0 )
goto V_34;
if ( V_53 -> type == V_54 )
if ( F_2 ( V_1 , L_21 , 1 ) <= 0 )
goto V_34;
for ( V_49 = 0 ; V_49 < V_53 -> V_17 ; V_49 ++ ) {
if ( F_6 ( V_1 , L_20 , V_53 -> V_51 [ V_49 ] ) <= 0 )
goto V_34;
}
if ( V_53 -> V_17 == 0 ) {
if ( F_2 ( V_1 , L_22 , 2 ) <= 0 )
goto V_34;
}
} else {
if ( F_10 ( V_1 , L_23 ) <= 0 )
goto V_34;
V_32 = 1 ;
}
F_18 ( V_53 ) ;
} else if ( V_2 == V_55 ) {
T_5 * V_53 ;
int V_49 ;
V_23 = V_22 ;
V_53 = F_19 ( NULL , & V_23 , V_15 + V_26 ) ;
if ( V_53 != NULL ) {
if ( F_2 ( V_1 , L_15 , 1 ) <= 0 )
goto V_34;
if ( V_53 -> type == V_56 )
if ( F_2 ( V_1 , L_21 , 1 ) <= 0 )
goto V_34;
for ( V_49 = 0 ; V_49 < V_53 -> V_17 ; V_49 ++ ) {
if ( F_6 ( V_1 , L_20 , V_53 -> V_51 [ V_49 ] ) <= 0 )
goto V_34;
}
if ( V_53 -> V_17 == 0 ) {
if ( F_2 ( V_1 , L_22 , 2 ) <= 0 )
goto V_34;
}
} else {
if ( F_10 ( V_1 , L_24 ) <= 0 )
goto V_34;
V_32 = 1 ;
}
F_20 ( V_53 ) ;
} else if ( V_15 > 0 && V_16 ) {
if ( ! V_25 ) {
if ( F_2 ( V_1 , L_13 , 1 ) <= 0 )
goto V_34;
}
if ( F_15 ( V_1 , ( const char * ) V_8 ,
( ( V_16 == - 1 || V_16 > V_15 ) ? V_15 : V_16 ) ,
V_31 ) <= 0 )
goto V_34;
V_25 = 1 ;
}
if ( V_32 ) {
int V_49 ;
const unsigned char * V_36 = V_22 + V_26 ;
if ( F_10 ( V_1 , L_25 ) <= 0 )
goto V_34;
for ( V_49 = 0 ; V_49 < V_15 ; V_49 ++ ) {
if ( F_6 ( V_1 , L_20 , V_36 [ V_49 ] ) <= 0 )
goto V_34;
}
if ( F_10 ( V_1 , L_26 ) <= 0 )
goto V_34;
}
if ( ! V_25 ) {
if ( F_2 ( V_1 , L_13 , 1 ) <= 0 )
goto V_34;
}
V_8 += V_15 ;
if ( ( V_2 == V_57 ) && ( V_3 == 0 ) ) {
V_24 = 2 ;
goto V_34;
}
}
V_17 -= V_15 ;
}
V_24 = 1 ;
V_34:
F_21 ( V_29 ) ;
F_16 ( V_30 ) ;
* V_14 = V_8 ;
return ( V_24 ) ;
}
const char * F_5 ( int V_2 )
{
static const char * const V_58 [] = {
L_27 , L_28 , L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 , L_35 , L_36 ,
L_37 , L_38 , L_39 , L_40 ,
L_41 , L_42 , L_43 , L_44 ,
L_45 , L_46 , L_47 ,
L_48 , L_49 , L_50 , L_51 ,
L_52 , L_53 , L_54 ,
L_55 , L_56 , L_57
} ;
if ( ( V_2 == V_54 ) || ( V_2 == V_56 ) )
V_2 &= ~ 0x100 ;
if ( V_2 < 0 || V_2 > 30 )
return L_58 ;
return V_58 [ V_2 ] ;
}
