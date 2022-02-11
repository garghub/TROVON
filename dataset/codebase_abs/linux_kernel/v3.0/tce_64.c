static inline void F_1 ( void * V_1 )
{
if ( V_2 )
F_2 ( V_1 ) ;
else
F_3 () ;
}
void F_4 ( struct V_3 * V_4 , unsigned long V_5 ,
unsigned int V_6 , unsigned long V_7 , int V_8 )
{
T_1 * V_9 ;
T_1 V_10 ;
T_1 V_11 ;
V_10 = ( 1 << V_12 ) ;
if ( V_8 != V_13 )
V_10 |= ( 1 << V_14 ) ;
V_9 = ( ( T_1 * ) V_4 -> V_15 ) + V_5 ;
while ( V_6 -- ) {
V_11 = ( F_5 ( ( void * ) V_7 ) ) >> V_16 ;
V_10 &= ~ V_17 ;
V_10 |= ( V_11 << V_18 ) ;
* V_9 = F_6 ( V_10 ) ;
F_1 ( V_9 ) ;
V_7 += V_19 ;
V_9 ++ ;
}
}
void F_7 ( struct V_3 * V_4 , long V_5 , unsigned int V_6 )
{
T_1 * V_9 ;
V_9 = ( ( T_1 * ) V_4 -> V_15 ) + V_5 ;
while ( V_6 -- ) {
* V_9 = F_6 ( 0 ) ;
F_1 ( V_9 ) ;
V_9 ++ ;
}
}
static inline unsigned int F_8 ( unsigned char V_20 )
{
return ( 1 << V_20 ) << 13 ;
}
static int F_9 ( struct V_21 * V_22 , struct V_3 * V_4 )
{
unsigned int V_23 ;
unsigned long V_24 ;
int V_25 ;
V_4 -> V_26 = V_22 -> V_27 -> V_28 ;
V_4 -> V_29 = F_8 ( V_30 ) ;
V_23 = V_4 -> V_29 / V_31 ;
V_24 = F_10 ( V_32 , F_11 ( V_23 ) ) ;
if ( ! V_24 ) {
F_12 ( V_33 L_1 ) ;
V_25 = - V_34 ;
goto V_35;
}
V_4 -> V_36 = ( unsigned long * ) V_24 ;
memset ( V_4 -> V_36 , 0 , V_23 ) ;
V_4 -> V_37 = 0 ;
F_13 ( & V_4 -> V_38 ) ;
return 0 ;
V_35:
return V_25 ;
}
int T_2 F_14 ( struct V_21 * V_22 , void T_3 * V_39 )
{
struct V_3 * V_4 ;
int V_25 ;
if ( F_15 ( V_22 -> V_27 ) ) {
F_12 ( V_33 L_2 ,
V_22 , F_15 ( V_22 -> V_27 ) ) ;
F_16 () ;
}
V_4 = F_17 ( sizeof( struct V_3 ) , V_32 ) ;
if ( ! V_4 ) {
F_12 ( V_33 L_3 ) ;
V_25 = - V_34 ;
goto V_35;
}
V_25 = F_9 ( V_22 , V_4 ) ;
if ( V_25 )
goto V_40;
V_4 -> V_39 = V_39 ;
F_18 ( V_22 -> V_27 , V_4 ) ;
return 0 ;
V_40:
F_19 ( V_4 ) ;
V_35:
return V_25 ;
}
void * T_2 F_20 ( void )
{
unsigned int V_20 ;
V_20 = F_8 ( V_30 ) ;
V_20 *= V_41 ;
return F_21 ( V_20 , V_20 , 0 ) ;
}
void T_2 F_22 ( void * V_4 )
{
unsigned int V_20 ;
if ( ! V_4 )
return;
V_20 = F_8 ( V_30 ) ;
V_20 *= V_41 ;
F_23 ( F_24 ( V_4 ) , V_20 ) ;
}
