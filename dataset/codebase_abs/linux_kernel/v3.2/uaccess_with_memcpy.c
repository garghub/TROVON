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
if ( F_3 ( F_10 ( * V_6 ) || F_11 ( * V_6 ) ) )
return 0 ;
V_7 = F_12 ( V_10 -> V_11 , V_6 , V_4 , & V_9 ) ;
if ( F_3 ( ! F_13 ( * V_7 ) || ! F_14 ( * V_7 ) ||
! F_15 ( * V_7 ) || ! F_16 ( * V_7 ) ) ) {
F_17 ( V_7 , V_9 ) ;
return 0 ;
}
* V_2 = V_7 ;
* V_3 = V_9 ;
return 1 ;
}
static unsigned long T_7
F_18 ( void T_1 * V_12 , const void * V_13 , unsigned long V_14 )
{
int V_15 ;
if ( F_3 ( F_19 ( F_20 () , V_16 ) ) ) {
memcpy ( ( void * ) V_12 , V_13 , V_14 ) ;
return 0 ;
}
V_15 = F_21 () ;
if ( ! V_15 )
F_22 ( & V_10 -> V_11 -> V_17 ) ;
while ( V_14 ) {
T_2 * V_7 ;
T_3 * V_9 ;
int V_18 ;
while ( ! F_1 ( V_12 , & V_7 , & V_9 ) ) {
if ( ! V_15 )
F_23 ( & V_10 -> V_11 -> V_17 ) ;
if ( F_24 ( 0 , ( char T_1 * ) V_12 ) )
goto V_19;
if ( ! V_15 )
F_22 ( & V_10 -> V_11 -> V_17 ) ;
}
V_18 = ( ~ ( unsigned long ) V_12 & ~ V_20 ) + 1 ;
if ( V_18 > V_14 )
V_18 = V_14 ;
memcpy ( ( void * ) V_12 , V_13 , V_18 ) ;
V_12 += V_18 ;
V_13 += V_18 ;
V_14 -= V_18 ;
F_17 ( V_7 , V_9 ) ;
}
if ( ! V_15 )
F_23 ( & V_10 -> V_11 -> V_17 ) ;
V_19:
return V_14 ;
}
unsigned long
F_25 ( void T_1 * V_12 , const void * V_13 , unsigned long V_14 )
{
if ( V_14 < 64 )
return F_26 ( V_12 , V_13 , V_14 ) ;
return F_18 ( V_12 , V_13 , V_14 ) ;
}
static unsigned long T_7
F_27 ( void T_1 * V_4 , unsigned long V_14 )
{
if ( F_3 ( F_19 ( F_20 () , V_16 ) ) ) {
memset ( ( void * ) V_4 , 0 , V_14 ) ;
return 0 ;
}
F_22 ( & V_10 -> V_11 -> V_17 ) ;
while ( V_14 ) {
T_2 * V_7 ;
T_3 * V_9 ;
int V_18 ;
while ( ! F_1 ( V_4 , & V_7 , & V_9 ) ) {
F_23 ( & V_10 -> V_11 -> V_17 ) ;
if ( F_24 ( 0 , ( char T_1 * ) V_4 ) )
goto V_19;
F_22 ( & V_10 -> V_11 -> V_17 ) ;
}
V_18 = ( ~ ( unsigned long ) V_4 & ~ V_20 ) + 1 ;
if ( V_18 > V_14 )
V_18 = V_14 ;
memset ( ( void * ) V_4 , 0 , V_18 ) ;
V_4 += V_18 ;
V_14 -= V_18 ;
F_17 ( V_7 , V_9 ) ;
}
F_23 ( & V_10 -> V_11 -> V_17 ) ;
V_19:
return V_14 ;
}
unsigned long F_28 ( void T_1 * V_4 , unsigned long V_14 )
{
if ( V_14 < 64 )
return F_29 ( V_4 , V_14 ) ;
return F_27 ( V_4 , V_14 ) ;
}
