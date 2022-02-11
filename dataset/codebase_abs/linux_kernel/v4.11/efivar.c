static int F_1 ( const char * V_1 , unsigned long * V_2 ,
void * * V_3 )
{
T_1 V_4 ;
T_2 * V_5 ;
T_3 V_6 ;
unsigned long V_7 ;
void * V_8 ;
void * V_9 ;
int V_10 ;
int V_11 ;
* V_2 = 0 ;
* V_3 = NULL ;
if ( ! F_2 ( V_12 ) )
return - V_13 ;
V_5 = F_3 ( strlen ( V_1 ) + 1 , sizeof( T_2 ) , V_14 ) ;
V_8 = F_4 ( V_15 , V_14 ) ;
if ( ! V_5 || ! V_8 ) {
V_11 = - V_16 ;
goto V_17;
}
V_7 = V_15 ;
for ( V_10 = 0 ; V_1 [ V_10 ] ; V_10 ++ )
V_5 [ V_10 ] = V_1 [ V_10 ] ;
V_6 = V_18 ;
V_4 = V_19 . V_20 (
V_5 ,
& V_6 ,
NULL ,
& V_7 ,
V_8 ) ;
V_11 = V_4 == V_21 ? 0 :
V_4 == V_22 ? - V_23 :
- V_24 ;
if ( V_11 )
goto V_17;
V_9 = F_5 ( V_8 , V_7 , V_14 ) ;
if ( ! V_9 ) {
V_11 = - V_16 ;
goto V_17;
}
* V_2 = V_7 ;
* V_3 = V_9 ;
V_17:
F_6 ( V_5 ) ;
F_6 ( V_8 ) ;
return V_11 ;
}
int F_7 ( struct V_25 * V_26 , const char * V_27 ,
unsigned long * V_2 , void * * V_3 )
{
char V_28 [ 64 ] ;
char V_1 [ 64 ] ;
int V_29 ;
int V_10 ;
snprintf ( V_28 , sizeof( V_28 ) , L_1 ,
F_8 ( V_26 -> V_30 -> V_31 ) ,
V_26 -> V_30 -> V_31 -> V_32 ,
F_9 ( V_26 -> V_30 -> V_33 ) ,
F_10 ( V_26 -> V_30 -> V_33 ) ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_2 , V_28 , V_27 ) ;
V_29 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_29 ) {
for ( V_10 = 0 ; V_28 [ V_10 ] ; V_10 ++ )
if ( isalpha ( V_28 [ V_10 ] ) )
V_28 [ V_10 ] = toupper ( V_28 [ V_10 ] ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_2 , V_28 , V_27 ) ;
V_29 = F_1 ( V_1 , V_2 , V_3 ) ;
}
return V_29 ;
}
