static T_1
F_1 ( T_1 V_1 )
{
if ( V_1 >= '0' && V_1 <= '9' )
return V_1 - '0' ;
if ( V_1 >= 'A' && V_1 <= 'F' )
return ( V_1 - 'A' ) + 10 ;
if ( V_1 >= 'a' && V_1 <= 'f' )
return ( V_1 - 'a' ) + 10 ;
return 0xff ;
}
static int
F_2 ( T_2 * V_2 , char * * V_3 , int V_4 , char V_5 )
{
const int V_6 = V_4 ;
char * V_7 ;
int V_8 ;
V_8 = 0 ;
while ( F_3 ( V_2 , V_4 ) > 0 ) {
T_1 V_9 ;
V_9 = F_4 ( V_2 , V_4 ) ;
if ( ! V_9 )
return - 1 ;
if ( V_9 == V_5 )
break;
if ( V_9 == '%' ) {
V_4 ++ ;
V_9 = F_4 ( V_2 , V_4 ) ;
if ( F_1 ( V_9 ) > 15 )
return - 1 ;
V_4 ++ ;
V_9 = F_4 ( V_2 , V_4 ) ;
if ( F_1 ( V_9 ) > 15 )
return - 1 ;
}
V_8 ++ ;
V_4 ++ ;
}
* V_3 = V_7 = ( char * ) F_5 ( F_6 () , V_8 + 1 ) ;
V_7 [ V_8 ] = '\0' ;
V_8 = 0 ;
V_4 = V_6 ;
while ( F_3 ( V_2 , V_4 ) > 0 ) {
T_1 V_9 ;
V_9 = F_4 ( V_2 , V_4 ) ;
if ( ! V_9 )
return - 1 ;
if ( V_9 == V_5 )
break;
if ( V_9 == '%' ) {
T_1 V_10 , V_11 ;
V_4 ++ ;
V_10 = F_4 ( V_2 , V_4 ) ;
V_4 ++ ;
V_11 = F_4 ( V_2 , V_4 ) ;
V_7 [ V_8 ] = F_1 ( V_10 ) << 4 | F_1 ( V_11 ) ;
} else if ( V_9 == '+' )
V_7 [ V_8 ] = ' ' ;
else
V_7 [ V_8 ] = V_9 ;
V_8 ++ ;
V_4 ++ ;
}
return V_4 ;
}
static void
F_7 ( T_2 * V_2 , T_3 * V_12 , T_4 * V_13 )
{
T_4 * V_14 ;
T_4 * V_15 ;
T_5 * V_16 ;
T_6 V_4 = 0 , V_17 ;
const char * V_18 ;
V_18 = V_12 -> V_19 ;
if ( ! ( V_18 && V_18 [ 0 ] ) ) {
V_18 = ( char * ) ( V_12 -> V_20 ) ;
if ( ! ( V_18 && V_18 [ 0 ] ) ) {
V_18 = NULL ;
}
}
if ( V_18 )
F_8 ( V_12 -> V_21 , V_22 , L_1 , L_2 , V_18 ) ;
V_16 = F_9 ( V_13 , V_23 , V_2 , 0 , - 1 , V_24 ) ;
if ( V_18 )
F_10 ( V_16 , L_3 , V_18 ) ;
V_14 = F_11 ( V_16 , V_25 ) ;
while ( F_3 ( V_2 , V_4 ) > 0 ) {
const int V_26 = V_4 ;
char * V_27 , * V_28 ;
V_16 = F_9 ( V_14 , & V_29 , V_2 , V_4 , 0 , V_24 ) ;
V_15 = F_11 ( V_16 , V_30 ) ;
V_17 = F_2 ( V_2 , & V_27 , V_4 , '=' ) ;
if ( V_17 == - 1 )
break;
F_12 ( V_15 , & V_31 , V_2 , V_4 , V_17 - V_4 , V_27 ) ;
F_10 ( V_15 , L_4 , V_27 ) ;
V_4 = V_17 + 1 ;
V_17 = F_2 ( V_2 , & V_28 , V_4 , '&' ) ;
if ( V_17 == - 1 )
break;
F_12 ( V_15 , & V_32 , V_2 , V_4 , V_17 - V_4 , V_28 ) ;
F_10 ( V_15 , L_5 , V_28 ) ;
V_4 = V_17 + 1 ;
F_13 ( V_16 , V_4 - V_26 ) ;
}
}
void
F_14 ( void )
{
static T_7 * V_33 [] = {
& V_29 ,
& V_31 ,
& V_32 ,
} ;
static T_6 * V_34 [] = {
& V_25 ,
& V_30
} ;
int V_35 ;
V_35 = F_15 ( L_6 , L_7 , L_8 ) ;
V_23 = F_16 ( V_35 ) ;
V_36 = F_17 ( L_8 , F_7 , V_35 ) ;
F_18 ( V_35 , V_33 , F_19 ( V_33 ) ) ;
F_20 ( V_34 , F_19 ( V_34 ) ) ;
}
void
F_21 ( void )
{
F_22 ( L_9 , L_10 , V_36 ) ;
}
