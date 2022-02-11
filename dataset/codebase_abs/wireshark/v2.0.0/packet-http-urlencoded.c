static int
F_1 ( T_1 * V_1 , char * * V_2 , int V_3 , char V_4 )
{
const int V_5 = V_3 ;
char * V_6 ;
int V_7 ;
V_7 = 0 ;
while ( F_2 ( V_1 , V_3 ) > 0 ) {
T_2 V_8 ;
V_8 = F_3 ( V_1 , V_3 ) ;
if ( ! V_8 )
return - 1 ;
if ( V_8 == V_4 )
break;
if ( V_8 == '%' ) {
V_3 ++ ;
V_8 = F_3 ( V_1 , V_3 ) ;
if ( F_4 ( V_8 ) == - 1 )
return - 1 ;
V_3 ++ ;
V_8 = F_3 ( V_1 , V_3 ) ;
if ( F_4 ( V_8 ) == - 1 )
return - 1 ;
}
V_7 ++ ;
V_3 ++ ;
}
* V_2 = V_6 = ( char * ) F_5 ( F_6 () , V_7 + 1 ) ;
V_6 [ V_7 ] = '\0' ;
V_7 = 0 ;
V_3 = V_5 ;
while ( F_2 ( V_1 , V_3 ) > 0 ) {
T_2 V_8 ;
V_8 = F_3 ( V_1 , V_3 ) ;
if ( ! V_8 )
return - 1 ;
if ( V_8 == V_4 )
break;
if ( V_8 == '%' ) {
T_2 V_9 , V_10 ;
V_3 ++ ;
V_9 = F_3 ( V_1 , V_3 ) ;
V_3 ++ ;
V_10 = F_3 ( V_1 , V_3 ) ;
V_6 [ V_7 ] = F_4 ( V_9 ) << 4 | F_4 ( V_10 ) ;
} else if ( V_8 == '+' )
V_6 [ V_7 ] = ' ' ;
else
V_6 [ V_7 ] = V_8 ;
V_7 ++ ;
V_3 ++ ;
}
return V_3 ;
}
static int
F_7 ( T_1 * V_1 , T_3 * V_11 , T_4 * V_12 , void * V_13 )
{
T_4 * V_14 ;
T_4 * V_15 ;
T_5 * V_16 ;
T_6 V_3 = 0 , V_17 ;
const char * V_18 ;
V_18 = V_11 -> V_19 ;
if ( ! ( V_18 && V_18 [ 0 ] ) ) {
V_18 = ( char * ) V_13 ;
if ( ! ( V_18 && V_18 [ 0 ] ) ) {
V_18 = NULL ;
}
}
if ( V_18 )
F_8 ( V_11 -> V_20 , V_21 , L_1 , L_2 , V_18 ) ;
V_16 = F_9 ( V_12 , V_22 , V_1 , 0 , - 1 , V_23 ) ;
if ( V_18 )
F_10 ( V_16 , L_3 , V_18 ) ;
V_14 = F_11 ( V_16 , V_24 ) ;
while ( F_2 ( V_1 , V_3 ) > 0 ) {
const int V_25 = V_3 ;
char * V_26 , * V_27 ;
V_16 = F_9 ( V_14 , & V_28 , V_1 , V_3 , 0 , V_23 ) ;
V_15 = F_11 ( V_16 , V_29 ) ;
V_17 = F_1 ( V_1 , & V_26 , V_3 , '=' ) ;
if ( V_17 == - 1 )
break;
F_12 ( V_15 , & V_30 , V_1 , V_3 , V_17 - V_3 , V_26 ) ;
F_10 ( V_15 , L_4 , V_26 ) ;
V_3 = V_17 + 1 ;
V_17 = F_1 ( V_1 , & V_27 , V_3 , '&' ) ;
if ( V_17 == - 1 )
break;
F_12 ( V_15 , & V_31 , V_1 , V_3 , V_17 - V_3 , V_27 ) ;
F_10 ( V_15 , L_5 , V_27 ) ;
V_3 = V_17 + 1 ;
F_13 ( V_16 , V_3 - V_25 ) ;
}
return F_14 ( V_1 ) ;
}
void
F_15 ( void )
{
#ifndef F_16
static T_7 * V_32 [] = {
& V_28 ,
& V_30 ,
& V_31 ,
} ;
#endif
static T_6 * V_33 [] = {
& V_24 ,
& V_29
} ;
int V_34 ;
V_34 = F_17 ( L_6 , L_7 , L_8 ) ;
V_22 = F_18 ( V_34 ) ;
V_35 = F_19 ( L_8 , F_7 , V_34 ) ;
F_20 ( V_34 , V_32 , F_21 ( V_32 ) ) ;
F_22 ( V_33 , F_21 ( V_33 ) ) ;
}
void
F_23 ( void )
{
F_24 ( L_9 , L_10 , V_35 ) ;
}
