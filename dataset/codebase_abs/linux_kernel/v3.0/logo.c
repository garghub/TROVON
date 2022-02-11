static void F_1 ( void * V_1 , unsigned short V_2 , unsigned V_3 )
{
unsigned short * V_4 = V_1 ;
V_3 >>= 1 ;
while ( V_3 -- )
* V_4 ++ = V_2 ;
}
int F_2 ( char * V_5 )
{
struct V_6 * V_7 ;
int V_8 , V_9 = 0 ;
unsigned V_3 , V_10 ;
unsigned short * V_11 , * V_12 , * V_4 ;
V_7 = V_13 [ 0 ] ;
if ( ! V_7 ) {
F_3 ( V_14 L_1 ,
V_15 ) ;
return - V_16 ;
}
V_8 = F_4 ( V_5 , V_17 , 0 ) ;
if ( V_8 < 0 ) {
F_3 ( V_14 L_2 ,
V_15 , V_5 ) ;
return - V_18 ;
}
V_3 = ( unsigned ) F_5 ( V_8 , ( V_19 ) 0 , 2 ) ;
if ( V_3 == 0 ) {
F_6 ( V_8 ) ;
V_9 = - V_20 ;
goto V_21;
}
F_5 ( V_8 , ( V_19 ) 0 , 0 ) ;
V_11 = F_7 ( V_3 , V_22 ) ;
if ( ! V_11 ) {
F_3 ( V_14 L_3 , V_15 ) ;
V_9 = - V_23 ;
goto V_21;
}
if ( ( unsigned ) F_8 ( V_8 , ( char * ) V_11 , V_3 ) != V_3 ) {
V_9 = - V_20 ;
goto V_24;
}
V_10 = F_9 ( V_7 ) * F_10 ( V_7 ) ;
V_4 = V_11 ;
V_12 = ( unsigned short * ) ( V_7 -> V_25 ) ;
while ( V_3 > 3 ) {
unsigned V_26 = V_4 [ 0 ] ;
if ( V_26 > V_10 )
break;
F_1 ( V_12 , V_4 [ 1 ] , V_26 << 1 ) ;
V_12 += V_26 ;
V_10 -= V_26 ;
V_4 += 2 ;
V_3 -= 4 ;
}
V_24:
F_11 ( V_11 ) ;
V_21:
F_6 ( V_8 ) ;
return V_9 ;
}
