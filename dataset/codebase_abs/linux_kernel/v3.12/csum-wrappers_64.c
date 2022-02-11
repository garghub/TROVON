T_1
F_1 ( const void T_2 * V_1 , void * V_2 ,
int V_3 , T_1 V_4 , int * V_5 )
{
F_2 () ;
* V_5 = 0 ;
if ( ! F_3 ( F_4 ( V_6 , V_1 , V_3 ) ) )
goto V_7;
if ( F_5 ( ( unsigned long ) V_1 & 6 ) ) {
while ( ( ( unsigned long ) V_1 & 6 ) && V_3 >= 2 ) {
T_3 V_8 ;
* V_5 = F_6 ( V_8 , ( const T_3 T_2 * ) V_1 ) ;
if ( * V_5 )
return V_4 ;
* ( T_3 * ) V_2 = V_8 ;
V_4 = ( V_9 T_1 ) F_7 (
( V_9 unsigned ) V_4 , V_8 ) ;
V_1 += 2 ;
V_2 += 2 ;
V_3 -= 2 ;
}
}
F_8 () ;
V_4 = F_9 ( ( V_9 const void * ) V_1 ,
V_2 , V_3 , V_4 , V_5 , NULL ) ;
F_10 () ;
if ( F_5 ( * V_5 ) )
goto V_7;
return V_4 ;
V_7:
* V_5 = - V_10 ;
memset ( V_2 , 0 , V_3 ) ;
return V_4 ;
}
T_1
F_11 ( const void * V_1 , void T_2 * V_2 ,
int V_3 , T_1 V_4 , int * V_5 )
{
T_1 V_11 ;
F_2 () ;
if ( F_5 ( ! F_4 ( V_12 , V_2 , V_3 ) ) ) {
* V_5 = - V_10 ;
return 0 ;
}
if ( F_5 ( ( unsigned long ) V_2 & 6 ) ) {
while ( ( ( unsigned long ) V_2 & 6 ) && V_3 >= 2 ) {
T_3 V_8 = * ( T_3 * ) V_1 ;
V_4 = ( V_9 T_1 ) F_7 (
( V_9 unsigned ) V_4 , V_8 ) ;
* V_5 = F_12 ( V_8 , ( T_3 T_2 * ) V_2 ) ;
if ( * V_5 )
return V_4 ;
V_1 += 2 ;
V_2 += 2 ;
V_3 -= 2 ;
}
}
* V_5 = 0 ;
F_8 () ;
V_11 = F_9 ( V_1 , ( void V_9 * ) V_2 ,
V_3 , V_4 , NULL , V_5 ) ;
F_10 () ;
return V_11 ;
}
T_1
F_13 ( const void * V_1 , void * V_2 , int V_3 , T_1 V_13 )
{
return F_9 ( V_1 , V_2 , V_3 , V_13 , NULL , NULL ) ;
}
T_4 F_14 ( const struct V_14 * V_15 ,
const struct V_14 * V_16 ,
T_5 V_3 , unsigned short V_17 , T_1 V_13 )
{
T_6 V_18 , V_19 ;
V_18 = ( V_9 T_6 ) F_15 ( V_3 ) + ( V_9 T_6 ) F_16 ( V_17 ) +
( V_9 T_6 ) V_13 ;
asm(" addq (%[saddr]),%[sum]\n"
" adcq 8(%[saddr]),%[sum]\n"
" adcq (%[daddr]),%[sum]\n"
" adcq 8(%[daddr]),%[sum]\n"
" adcq $0,%[sum]\n"
: [sum] "=r" (sum64)
: "[sum]" (rest), [saddr] "r" (saddr), [daddr] "r" (daddr));
return F_17 (
( V_9 T_1 ) F_7 ( V_19 & 0xffffffff , V_19 >> 32 ) ) ;
}
