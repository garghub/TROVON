static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
unsigned int V_6 ;
if ( ! ( V_5 & V_7 ) )
return V_3 ;
for ( V_6 = 0 ; V_6 < * V_4 - 4 ; V_6 ++ )
if ( V_3 [ V_6 ] == 0x29 && V_3 [ V_6 + 2 ] == 0x19 ) {
T_1 V_8 ;
V_3 [ V_6 ] = 0x19 ;
V_3 [ V_6 + 2 ] = 0x29 ;
V_8 = V_3 [ V_6 + 3 ] ;
V_3 [ V_6 + 3 ] = V_3 [ V_6 + 1 ] ;
V_3 [ V_6 + 1 ] = V_8 ;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 ,
unsigned long * * V_15 , int * V_16 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ! ( V_5 & V_17 ) )
return 0 ;
if ( V_14 -> type == V_18 && V_14 -> V_19 == V_20 )
F_4 ( V_21 , * V_15 ) ;
if ( V_14 -> V_22 == 0x00090005 )
return - 1 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_11 * V_12 ,
struct V_13 * V_14 , T_2 V_23 )
{
unsigned long V_5 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_24 & V_25 ) || ! V_12 -> V_26 ||
! V_14 -> type || ! ( V_5 & V_17 ) )
return 0 ;
if ( V_14 -> V_22 == 0x00090005 ) {
if ( V_23 )
V_5 |= V_27 ;
else
V_5 &= ~ V_27 ;
F_6 ( V_2 , ( void * ) V_5 ) ;
return 1 ;
}
if ( V_14 -> V_19 == V_20 && ( V_5 & V_27 ) ) {
struct V_28 * V_29 = V_12 -> V_26 -> V_29 ;
F_7 ( V_29 , V_14 -> type , V_21 , V_23 ) ;
return 1 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const struct V_30 * V_31 )
{
unsigned long V_5 = V_31 -> V_32 ;
int V_33 ;
F_6 ( V_2 , ( void * ) V_5 ) ;
V_33 = F_9 ( V_2 ) ;
if ( V_33 ) {
F_10 ( V_2 , L_1 ) ;
goto V_34;
}
V_33 = F_11 ( V_2 , V_35 ) ;
if ( V_33 ) {
F_10 ( V_2 , L_2 ) ;
goto V_34;
}
return 0 ;
V_34:
return V_33 ;
}
static int T_3 F_12 ( void )
{
return F_13 ( & V_36 ) ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_36 ) ;
}
