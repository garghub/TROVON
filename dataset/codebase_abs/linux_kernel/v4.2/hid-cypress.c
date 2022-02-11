static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
unsigned int V_6 ;
if ( ! ( V_5 & V_7 ) )
return V_3 ;
for ( V_6 = 0 ; V_6 < * V_4 - 4 ; V_6 ++ )
if ( V_3 [ V_6 ] == 0x29 && V_3 [ V_6 + 2 ] == 0x19 ) {
V_3 [ V_6 ] = 0x19 ;
V_3 [ V_6 + 2 ] = 0x29 ;
F_3 ( V_3 [ V_6 + 3 ] , V_3 [ V_6 + 1 ] ) ;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_10 * V_11 , struct V_12 * V_13 ,
unsigned long * * V_14 , int * V_15 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ! ( V_5 & V_16 ) )
return 0 ;
if ( V_13 -> type == V_17 && V_13 -> V_18 == V_19 )
F_5 ( V_20 , * V_14 ) ;
if ( V_13 -> V_21 == 0x00090005 )
return - 1 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_12 * V_13 , T_2 V_22 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_23 & V_24 ) || ! V_11 -> V_25 ||
! V_13 -> type || ! ( V_5 & V_16 ) )
return 0 ;
if ( V_13 -> V_21 == 0x00090005 ) {
if ( V_22 )
V_5 |= V_26 ;
else
V_5 &= ~ V_26 ;
F_7 ( V_2 , ( void * ) V_5 ) ;
return 1 ;
}
if ( V_13 -> V_18 == V_19 && ( V_5 & V_26 ) ) {
struct V_27 * V_28 = V_11 -> V_25 -> V_28 ;
F_8 ( V_28 , V_13 -> type , V_20 , V_22 ) ;
return 1 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , const struct V_29 * V_30 )
{
unsigned long V_5 = V_30 -> V_31 ;
int V_32 ;
F_7 ( V_2 , ( void * ) V_5 ) ;
V_32 = F_10 ( V_2 ) ;
if ( V_32 ) {
F_11 ( V_2 , L_1 ) ;
goto V_33;
}
V_32 = F_12 ( V_2 , V_34 ) ;
if ( V_32 ) {
F_11 ( V_2 , L_2 ) ;
goto V_33;
}
return 0 ;
V_33:
return V_32 ;
}
