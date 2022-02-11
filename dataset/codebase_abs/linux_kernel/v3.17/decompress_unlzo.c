STATIC inline long T_1 F_1 ( T_2 * V_1 , long * V_2 , long V_3 )
{
int V_4 ;
T_2 * V_5 = V_1 ;
T_2 * V_6 = V_1 + V_3 ;
T_2 V_7 = 0 ;
T_3 V_8 ;
if ( V_3 < V_9 )
return 0 ;
for ( V_4 = 0 ; V_4 < 9 ; V_4 ++ ) {
if ( * V_5 ++ != V_10 [ V_4 ] )
return 0 ;
}
V_8 = F_2 ( V_5 ) ;
V_5 += 7 ;
if ( V_8 >= 0x0940 )
V_7 = * V_5 ++ ;
if ( F_3 ( V_5 ) & V_11 )
V_5 += 8 ;
else
V_5 += 4 ;
if ( V_6 - V_5 < 8 + 1 + 4 )
return 0 ;
V_5 += 8 ;
if ( V_8 >= 0x0940 )
V_5 += 4 ;
V_4 = * V_5 ++ ;
if ( V_6 - V_5 < V_4 + 4 )
return 0 ;
V_5 += V_4 + 4 ;
* V_2 = V_5 - V_1 ;
return 1 ;
}
STATIC int T_1 F_4 ( T_2 * V_1 , long V_3 ,
long (* F_5)( void * , unsigned long ) ,
long (* F_6)( void * , unsigned long ) ,
T_2 * V_12 , long * V_13 ,
void (* error) ( char * V_14 ) )
{
T_2 V_15 = 0 ;
long V_2 = 0 ;
T_4 V_16 , V_17 ;
T_5 V_18 ;
T_2 * V_19 , * V_20 , * V_21 ;
int V_22 = - 1 ;
if ( V_12 ) {
V_21 = V_12 ;
} else if ( ! F_6 ) {
error ( L_1 ) ;
goto exit;
} else {
V_21 = malloc ( V_23 ) ;
if ( ! V_21 ) {
error ( L_2 ) ;
goto exit;
}
}
if ( V_1 && F_5 ) {
error ( L_3 ) ;
goto V_24;
} else if ( V_1 ) {
V_19 = V_1 ;
} else if ( ! F_5 ) {
error ( L_4 ) ;
goto V_24;
} else {
V_19 = malloc ( F_7 ( V_23 ) ) ;
if ( ! V_19 ) {
error ( L_5 ) ;
goto V_24;
}
}
V_20 = V_19 ;
if ( V_13 )
* V_13 = 0 ;
if ( F_5 ) {
V_19 += V_25 ;
V_3 = F_5 ( V_19 , V_25 ) ;
}
if ( ! F_1 ( V_19 , & V_2 , V_3 ) ) {
error ( L_6 ) ;
goto V_26;
}
V_19 += V_2 ;
V_3 -= V_2 ;
if ( F_5 ) {
memcpy ( V_20 , V_19 , V_3 ) ;
V_19 = V_20 ;
}
if ( V_13 )
* V_13 = V_2 ;
for (; ; ) {
if ( F_5 && V_3 < 4 ) {
V_2 = F_5 ( V_19 + V_3 , 4 - V_3 ) ;
if ( V_2 > 0 )
V_3 += V_2 ;
}
if ( V_3 < 4 ) {
error ( L_7 ) ;
goto V_26;
}
V_17 = F_3 ( V_19 ) ;
V_19 += 4 ;
V_3 -= 4 ;
if ( V_17 == 0 ) {
if ( V_13 )
* V_13 += 4 ;
break;
}
if ( V_17 > V_23 ) {
error ( L_8 ) ;
goto V_26;
}
if ( F_5 && V_3 < 8 ) {
V_2 = F_5 ( V_19 + V_3 , 8 - V_3 ) ;
if ( V_2 > 0 )
V_3 += V_2 ;
}
if ( V_3 < 8 ) {
error ( L_7 ) ;
goto V_26;
}
V_16 = F_3 ( V_19 ) ;
V_19 += 8 ;
V_3 -= 8 ;
if ( V_16 <= 0 || V_16 > V_17 ) {
error ( L_7 ) ;
goto V_26;
}
if ( F_5 && V_3 < V_16 ) {
V_2 = F_5 ( V_19 + V_3 , V_16 - V_3 ) ;
if ( V_2 > 0 )
V_3 += V_2 ;
}
if ( V_3 < V_16 ) {
error ( L_7 ) ;
goto V_26;
}
V_18 = V_17 ;
if ( F_8 ( V_17 == V_16 ) )
memcpy ( V_21 , V_19 , V_16 ) ;
else {
V_15 = F_9 ( ( T_2 * ) V_19 , V_16 ,
V_21 , & V_18 ) ;
if ( V_15 != V_27 || V_17 != V_18 ) {
error ( L_9 ) ;
goto V_26;
}
}
if ( F_6 && F_6 ( V_21 , V_17 ) != V_17 )
goto V_26;
if ( V_12 )
V_21 += V_17 ;
if ( V_13 )
* V_13 += V_16 + 12 ;
V_19 += V_16 ;
V_3 -= V_16 ;
if ( F_5 ) {
if ( V_3 > 0 )
for ( V_2 = 0 ; V_2 < V_3 ; ++ V_2 )
V_20 [ V_2 ] = V_19 [ V_2 ] ;
V_19 = V_20 ;
}
}
V_22 = 0 ;
V_26:
if ( ! V_1 )
free ( V_20 ) ;
V_24:
if ( ! V_12 )
free ( V_21 ) ;
exit:
return V_22 ;
}
