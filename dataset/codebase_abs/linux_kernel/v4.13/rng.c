static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 )
{
int V_5 , V_6 ;
T_1 V_7 , V_8 , V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = V_2 -> V_12 ;
F_2 ( V_2 ) ;
F_3 ( V_11 , V_13 , V_14 , 1 ) ;
F_4 ( V_11 , V_13 , V_15 ) ;
F_3 ( V_11 , V_16 , V_17 , 0 ) ;
for ( V_5 = 0 , V_6 = 0 ; V_5 < V_4 ; V_5 ++ ) {
V_7 = F_5 ( V_11 , V_18 ) & 0xffff ;
V_8 = F_5 ( V_11 , V_18 ) & 0xffff ;
if ( V_7 && V_8 && V_9 != V_7 && V_7 != V_8 && V_7 != 0xffff &&
V_8 != 0xffff )
V_3 [ V_6 ++ ] = ( V_7 << 16 ) | V_8 ;
V_9 = V_8 ;
}
F_6 ( V_2 ) ;
V_2 -> V_9 = V_9 ;
return V_6 << 2 ;
}
static T_1 F_7 ( T_1 V_19 )
{
T_1 V_20 ;
if ( V_19 < 100 )
V_20 = 10 ;
else if ( V_19 < 105 )
V_20 = 1000 ;
else
V_20 = 10000 ;
return V_20 ;
}
static int F_8 ( void * V_21 )
{
int V_22 ;
struct V_1 * V_2 = V_21 ;
T_1 * V_23 ;
T_1 V_20 , V_19 = 0 ;
V_23 = F_9 ( V_24 , sizeof( T_1 ) , V_25 ) ;
if ( ! V_23 )
goto V_26;
while ( ! F_10 () ) {
V_22 = F_1 ( V_2 , V_23 ,
V_24 ) ;
if ( F_11 ( ! V_22 ) ) {
V_20 = F_7 ( ++ V_19 ) ;
F_12 ( V_27 ,
F_10 () ,
F_13 ( V_20 ) ) ;
continue;
}
V_19 = 0 ;
F_14 ( ( void * ) V_23 , V_22 ,
F_15 ( V_22 ) ) ;
}
F_16 ( V_23 ) ;
V_26:
V_2 -> V_28 = NULL ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_2 -> V_28 )
return;
if ( ! F_18 ( V_11 ) )
return;
V_2 -> V_28 = F_19 ( F_8 , V_2 , L_1 ) ;
if ( F_20 ( V_2 -> V_28 ) )
V_2 -> V_28 = NULL ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 ) {
F_22 ( V_2 -> V_28 ) ;
V_2 -> V_28 = NULL ;
}
}
