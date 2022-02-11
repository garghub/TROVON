static void T_1 F_1 ( void T_2 * V_1 )
{
T_3 V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= V_4 ;
F_3 ( V_2 , V_1 + V_3 ) ;
}
static int F_4 ( struct V_5 * V_6 , void * V_7 , T_4 V_8 ,
bool V_9 )
{
void T_2 * V_10 = ( void T_2 * ) V_6 -> V_11 ;
T_3 V_12 = V_8 / sizeof( T_3 ) ;
T_3 V_13 , V_14 ;
while ( ( F_5 ( V_10 + V_15 ) >> 24 ) == 0 ) {
if ( ! V_9 )
return 0 ;
F_6 () ;
}
V_13 = F_2 ( V_10 + V_15 ) >> 24 ;
if ( V_13 > V_12 )
V_13 = V_12 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
( ( T_3 * ) V_7 ) [ V_14 ] = F_2 ( V_10 + V_16 ) ;
return V_13 * sizeof( T_3 ) ;
}
static int F_7 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
void (* F_8)( void T_2 * V_1 );
const struct V_24 * V_25 ;
void T_2 * V_10 ;
int V_26 ;
V_10 = F_9 ( V_22 , 0 ) ;
if ( ! V_10 ) {
F_10 ( V_20 , L_1 ) ;
return - V_27 ;
}
V_28 . V_11 = ( unsigned long ) V_10 ;
V_25 = F_11 ( V_29 , V_22 ) ;
if ( ! V_25 ) {
F_12 ( V_10 ) ;
return - V_30 ;
}
F_8 = V_25 -> V_31 ;
if ( F_8 )
F_8 ( V_10 ) ;
F_13 ( V_32 , V_10 + V_15 ) ;
F_13 ( V_33 , V_10 + V_34 ) ;
V_26 = F_14 ( & V_28 ) ;
if ( V_26 ) {
F_10 ( V_20 , L_2 ) ;
F_12 ( V_10 ) ;
} else
F_15 ( V_20 , L_3 ) ;
return V_26 ;
}
static int F_16 ( struct V_17 * V_18 )
{
void T_2 * V_10 = ( void T_2 * ) V_28 . V_11 ;
F_13 ( 0 , V_10 + V_34 ) ;
F_17 ( & V_28 ) ;
F_12 ( V_10 ) ;
return 0 ;
}
