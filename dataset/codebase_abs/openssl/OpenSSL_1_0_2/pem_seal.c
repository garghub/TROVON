int F_1 ( T_1 * V_1 , T_2 * type , T_3 * V_2 ,
unsigned char * * V_3 , int * V_4 , unsigned char * V_5 ,
T_4 * * V_6 , int V_7 )
{
unsigned char V_8 [ V_9 ] ;
int V_10 = - 1 ;
int V_11 , V_12 , V_13 = 0 ;
char * V_14 = NULL ;
for ( V_11 = 0 ; V_11 < V_7 ; V_11 ++ ) {
if ( V_6 [ V_11 ] -> type != V_15 ) {
F_2 ( V_16 , V_17 ) ;
goto V_18;
}
V_12 = F_3 ( V_6 [ V_11 ] -> V_19 . V_20 ) ;
if ( V_12 > V_13 )
V_13 = V_12 ;
}
V_14 = ( char * ) F_4 ( V_13 * 2 ) ;
if ( V_14 == NULL ) {
F_2 ( V_16 , V_21 ) ;
goto V_18;
}
F_5 ( & V_1 -> V_22 ) ;
F_6 ( & V_1 -> V_23 ) ;
if ( ! F_7 ( & V_1 -> V_23 , V_2 ) )
goto V_18;
F_8 ( & V_1 -> V_24 ) ;
V_10 = F_9 ( & V_1 -> V_24 , type , V_3 , V_4 , V_5 , V_6 , V_7 ) ;
if ( V_10 <= 0 )
goto V_18;
for ( V_11 = 0 ; V_11 < V_7 ; V_11 ++ ) {
V_12 = F_10 ( ( unsigned char * ) V_14 , V_3 [ V_11 ] ,
F_3 ( V_6 [ V_11 ] -> V_19 . V_20 ) ) ;
V_4 [ V_11 ] = V_12 ;
memcpy ( V_3 [ V_11 ] , V_14 , V_12 + 1 ) ;
}
V_10 = V_7 ;
V_18:
if ( V_14 != NULL )
F_11 ( V_14 ) ;
F_12 ( V_8 , V_9 ) ;
return ( V_10 ) ;
}
void F_13 ( T_1 * V_1 , unsigned char * V_25 , int * V_26 ,
unsigned char * V_27 , int V_28 )
{
unsigned char V_29 [ 1600 ] ;
int V_11 , V_12 ;
* V_26 = 0 ;
F_14 ( & V_1 -> V_23 , V_27 , V_28 ) ;
for (; ; ) {
if ( V_28 <= 0 )
break;
if ( V_28 > 1200 )
V_11 = 1200 ;
else
V_11 = V_28 ;
F_15 ( & V_1 -> V_24 , V_29 , & V_12 , V_27 , V_11 ) ;
F_16 ( & V_1 -> V_22 , V_25 , & V_12 , V_29 , V_12 ) ;
* V_26 += V_12 ;
V_25 += V_12 ;
V_27 += V_11 ;
V_28 -= V_11 ;
}
}
int F_17 ( T_1 * V_1 , unsigned char * V_30 , int * V_31 ,
unsigned char * V_25 , int * V_26 , T_4 * V_32 )
{
unsigned char * V_14 = NULL ;
int V_10 = 0 , V_12 ;
unsigned int V_11 ;
if ( V_32 -> type != V_15 ) {
F_2 ( V_33 , V_17 ) ;
goto V_18;
}
V_11 = F_3 ( V_32 -> V_19 . V_20 ) ;
if ( V_11 < 100 )
V_11 = 100 ;
V_14 = ( unsigned char * ) F_4 ( V_11 * 2 ) ;
if ( V_14 == NULL ) {
F_2 ( V_33 , V_21 ) ;
goto V_18;
}
if ( ! F_18 ( & V_1 -> V_24 , V_14 , ( int * ) & V_11 ) )
goto V_18;
F_16 ( & V_1 -> V_22 , V_25 , & V_12 , V_14 , V_11 ) ;
* V_26 = V_12 ;
V_25 += V_12 ;
F_19 ( & V_1 -> V_22 , V_25 , & V_12 ) ;
* V_26 += V_12 ;
if ( ! F_20 ( & V_1 -> V_23 , V_14 , & V_11 , V_32 ) )
goto V_18;
* V_31 = F_10 ( V_30 , V_14 , V_11 ) ;
V_10 = 1 ;
V_18:
F_21 ( & V_1 -> V_23 ) ;
F_22 ( & V_1 -> V_24 ) ;
if ( V_14 != NULL )
F_11 ( V_14 ) ;
return ( V_10 ) ;
}
