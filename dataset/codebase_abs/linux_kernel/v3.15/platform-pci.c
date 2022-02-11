static unsigned long F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
V_2 = V_3 + V_4 ;
V_4 += V_1 ;
F_2 ( V_4 > V_5 ) ;
return V_2 ;
}
static T_1 F_3 ( struct V_6 * V_7 )
{
T_2 V_8 ;
int V_9 ;
V_9 = V_7 -> V_9 ;
if ( V_9 < 16 )
return V_9 ;
V_8 = V_7 -> V_8 ;
return ( ( T_1 ) 0x01 << 56 ) |
( ( T_1 ) F_4 ( V_7 -> V_10 ) << 32 ) |
( ( T_1 ) V_7 -> V_10 -> V_11 << 16 ) |
( ( T_1 ) ( V_7 -> V_12 & 0xff ) << 8 ) |
( ( T_1 ) ( V_8 - 1 ) & 3 ) ;
}
static T_3 F_5 ( int V_9 , void * V_13 )
{
F_6 () ;
return V_14 ;
}
static int F_7 ( struct V_6 * V_7 )
{
return F_8 ( V_7 -> V_9 , F_5 ,
V_15 | V_16 ,
L_1 , V_7 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
int V_17 ;
if ( V_18 )
return 0 ;
V_17 = F_10 ( V_19 ) ;
if ( V_17 ) {
F_11 ( & V_7 -> V_20 , L_2 ) ;
return V_17 ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
const struct V_21 * V_22 )
{
int V_23 , V_24 ;
long V_25 ;
long V_26 , V_27 ;
unsigned int V_28 ;
unsigned long V_29 ;
if ( ! F_13 () )
return - V_30 ;
V_23 = F_14 ( V_7 ) ;
if ( V_23 )
return V_23 ;
V_25 = F_15 ( V_7 , 0 ) ;
V_26 = F_15 ( V_7 , 1 ) ;
V_27 = F_16 ( V_7 , 1 ) ;
if ( V_26 == 0 || V_25 == 0 ) {
F_11 ( & V_7 -> V_20 , L_3 ) ;
V_24 = - V_31 ;
goto V_32;
}
V_24 = F_17 ( V_7 , 1 , V_33 ) ;
if ( V_24 < 0 )
goto V_32;
V_24 = F_17 ( V_7 , 0 , V_33 ) ;
if ( V_24 < 0 )
goto V_34;
V_3 = V_26 ;
V_5 = V_27 ;
if ( ! V_18 ) {
V_24 = F_7 ( V_7 ) ;
if ( V_24 ) {
F_18 ( & V_7 -> V_20 , L_4 , V_24 ) ;
goto V_35;
}
V_19 = F_3 ( V_7 ) ;
V_24 = F_10 ( V_19 ) ;
if ( V_24 ) {
F_18 ( & V_7 -> V_20 , L_5
L_6 , V_24 ) ;
goto V_35;
}
}
V_28 = F_19 () ;
V_29 = F_1 ( V_36 * V_28 ) ;
V_24 = F_20 ( V_29 ) ;
if ( V_24 )
goto V_35;
V_24 = F_21 () ;
if ( V_24 )
goto V_37;
F_22 ( NULL ) ;
return 0 ;
V_37:
F_23 () ;
V_35:
F_24 ( V_7 , 0 ) ;
V_34:
F_24 ( V_7 , 1 ) ;
V_32:
F_25 ( V_7 ) ;
return V_24 ;
}
static int T_4 F_26 ( void )
{
return F_27 ( & V_38 ) ;
}
