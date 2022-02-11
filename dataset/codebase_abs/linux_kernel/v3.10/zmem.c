void exit ( void )
{
for (; ; ) ;
}
void * F_1 ( unsigned V_1 )
{
void * V_2 = V_3 ;
V_1 = ( V_1 + 7 ) & - 8 ;
V_3 += V_1 ;
if ( V_3 > V_4 ) {
exit () ;
}
return V_2 ;
}
void F_2 ( void * V_5 , int V_6 , unsigned char * V_7 , int * V_8 )
{
T_1 V_9 ;
int V_10 , V_11 , V_12 ;
V_11 = 10 ;
V_12 = V_7 [ 3 ] ;
if ( V_7 [ 2 ] != V_13 || ( V_12 & V_14 ) != 0 ) {
exit () ;
}
if ( ( V_12 & V_15 ) != 0 )
V_11 = 12 + V_7 [ 10 ] + ( V_7 [ 11 ] << 8 ) ;
if ( ( V_12 & V_16 ) != 0 )
while ( V_7 [ V_11 ++ ] != 0 )
;
if ( ( V_12 & V_17 ) != 0 )
while ( V_7 [ V_11 ++ ] != 0 )
;
if ( ( V_12 & V_18 ) != 0 )
V_11 += 2 ;
if ( V_11 >= * V_8 ) {
exit () ;
}
V_9 . V_19 = F_1 ( F_3 () ) ;
V_10 = F_4 ( & V_9 , - V_20 ) ;
if ( V_10 != V_21 ) {
exit () ;
}
V_9 . V_22 = V_7 + V_11 ;
V_9 . V_23 = * V_8 - V_11 ;
V_9 . V_24 = V_5 ;
V_9 . V_25 = V_6 ;
V_10 = F_5 ( & V_9 , V_26 ) ;
if ( V_10 != V_21 && V_10 != V_27 ) {
exit () ;
}
* V_8 = V_9 . V_24 - ( unsigned char * ) V_5 ;
F_6 ( & V_9 ) ;
}
