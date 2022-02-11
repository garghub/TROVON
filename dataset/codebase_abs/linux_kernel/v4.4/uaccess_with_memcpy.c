static int
F_1 ( const void T_1 * V_1 , T_2 * * V_2 , T_3 * * V_3 )
{
unsigned long V_4 = ( unsigned long ) V_1 ;
T_4 * V_5 ;
T_5 * V_6 ;
T_2 * V_7 ;
T_6 * V_8 ;
T_3 * V_9 ;
V_5 = F_2 ( V_10 -> V_11 , V_4 ) ;
if ( F_3 ( F_4 ( * V_5 ) || F_5 ( * V_5 ) ) )
return 0 ;
V_8 = F_6 ( V_5 , V_4 ) ;
if ( F_3 ( F_7 ( * V_8 ) || F_8 ( * V_8 ) ) )
return 0 ;
V_6 = F_9 ( V_8 , V_4 ) ;
if ( F_3 ( F_10 ( * V_6 ) ) )
return 0 ;
if ( F_3 ( F_11 ( * V_6 ) ) ) {
V_9 = & V_10 -> V_11 -> V_12 ;
F_12 ( V_9 ) ;
if ( F_3 ( ! F_11 ( * V_6 )
|| F_13 ( * V_6 )
|| F_14 ( * V_6 ) ) ) {
F_15 ( V_9 ) ;
return 0 ;
}
* V_2 = NULL ;
* V_3 = V_9 ;
return 1 ;
}
if ( F_3 ( F_16 ( * V_6 ) ) )
return 0 ;
V_7 = F_17 ( V_10 -> V_11 , V_6 , V_4 , & V_9 ) ;
if ( F_3 ( ! F_18 ( * V_7 ) || ! F_19 ( * V_7 ) ||
! F_20 ( * V_7 ) || ! F_21 ( * V_7 ) ) ) {
F_22 ( V_7 , V_9 ) ;
return 0 ;
}
* V_2 = V_7 ;
* V_3 = V_9 ;
return 1 ;
}
static unsigned long T_7
F_23 ( void T_1 * V_13 , const void * V_14 , unsigned long V_15 )
{
unsigned long V_16 ;
int V_17 ;
if ( F_3 ( F_24 ( F_25 () , V_18 ) ) ) {
memcpy ( ( void * ) V_13 , V_14 , V_15 ) ;
return 0 ;
}
V_17 = F_26 () ;
if ( ! V_17 )
F_27 ( & V_10 -> V_11 -> V_19 ) ;
while ( V_15 ) {
T_2 * V_7 ;
T_3 * V_9 ;
int V_20 ;
while ( ! F_1 ( V_13 , & V_7 , & V_9 ) ) {
if ( ! V_17 )
F_28 ( & V_10 -> V_11 -> V_19 ) ;
if ( F_29 ( 0 , ( char T_1 * ) V_13 ) )
goto V_21;
if ( ! V_17 )
F_27 ( & V_10 -> V_11 -> V_19 ) ;
}
V_20 = ( ~ ( unsigned long ) V_13 & ~ V_22 ) + 1 ;
if ( V_20 > V_15 )
V_20 = V_15 ;
V_16 = F_30 () ;
memcpy ( ( void * ) V_13 , V_14 , V_20 ) ;
F_31 ( V_16 ) ;
V_13 += V_20 ;
V_14 += V_20 ;
V_15 -= V_20 ;
if ( V_7 )
F_22 ( V_7 , V_9 ) ;
else
F_15 ( V_9 ) ;
}
if ( ! V_17 )
F_28 ( & V_10 -> V_11 -> V_19 ) ;
V_21:
return V_15 ;
}
unsigned long
F_32 ( void T_1 * V_13 , const void * V_14 , unsigned long V_15 )
{
if ( V_15 < 64 ) {
unsigned long V_16 = F_30 () ;
V_15 = F_33 ( V_13 , V_14 , V_15 ) ;
F_31 ( V_16 ) ;
} else {
V_15 = F_23 ( V_13 , V_14 , V_15 ) ;
}
return V_15 ;
}
static unsigned long T_7
F_34 ( void T_1 * V_4 , unsigned long V_15 )
{
unsigned long V_16 ;
if ( F_3 ( F_24 ( F_25 () , V_18 ) ) ) {
memset ( ( void * ) V_4 , 0 , V_15 ) ;
return 0 ;
}
F_27 ( & V_10 -> V_11 -> V_19 ) ;
while ( V_15 ) {
T_2 * V_7 ;
T_3 * V_9 ;
int V_20 ;
while ( ! F_1 ( V_4 , & V_7 , & V_9 ) ) {
F_28 ( & V_10 -> V_11 -> V_19 ) ;
if ( F_29 ( 0 , ( char T_1 * ) V_4 ) )
goto V_21;
F_27 ( & V_10 -> V_11 -> V_19 ) ;
}
V_20 = ( ~ ( unsigned long ) V_4 & ~ V_22 ) + 1 ;
if ( V_20 > V_15 )
V_20 = V_15 ;
V_16 = F_30 () ;
memset ( ( void * ) V_4 , 0 , V_20 ) ;
F_31 ( V_16 ) ;
V_4 += V_20 ;
V_15 -= V_20 ;
if ( V_7 )
F_22 ( V_7 , V_9 ) ;
else
F_15 ( V_9 ) ;
}
F_28 ( & V_10 -> V_11 -> V_19 ) ;
V_21:
return V_15 ;
}
unsigned long F_35 ( void T_1 * V_4 , unsigned long V_15 )
{
if ( V_15 < 64 ) {
unsigned long V_16 = F_30 () ;
V_15 = F_36 ( V_4 , V_15 ) ;
F_31 ( V_16 ) ;
} else {
V_15 = F_34 ( V_4 , V_15 ) ;
}
return V_15 ;
}
