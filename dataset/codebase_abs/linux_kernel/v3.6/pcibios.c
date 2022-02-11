T_1 F_1 ( void * V_1 , const struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 = V_3 -> V_6 ;
if ( ( V_3 -> V_7 & V_8 ) && ( V_6 & 0x300 ) )
V_6 = ( V_6 + 0x3ff ) & ~ 0x3ff ;
V_6 = ( V_6 + V_5 - 1 ) & ~ ( V_5 - 1 ) ;
return V_6 ;
}
int F_2 ( struct V_9 * V_10 , int V_11 )
{
struct V_2 * V_12 ;
T_2 V_13 , V_14 ;
int V_15 ;
F_3 ( V_10 , V_16 , & V_13 ) ;
V_14 = V_13 ;
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ ) {
if ( ! ( V_11 & ( 1 << V_15 ) ) )
continue;
V_12 = V_10 -> V_2 + V_15 ;
if ( ! V_12 -> V_6 && V_12 -> V_17 ) {
F_4 ( V_18 L_1 ,
F_5 ( V_10 ) ) ;
return - V_19 ;
}
if ( V_12 -> V_7 & V_8 )
V_14 |= V_20 ;
if ( V_12 -> V_7 & V_21 )
V_14 |= V_22 ;
}
if ( ( V_10 -> V_23 >> 16 ) == V_24 )
V_14 |= V_20 | V_22 ;
if ( V_14 != V_13 ) {
F_6 ( L_2 ,
F_5 ( V_10 ) , V_13 , V_14 ) ;
F_7 ( V_10 , V_16 , V_14 ) ;
}
return 0 ;
}
void F_8 ( struct V_9 * V_10 , int V_25 )
{
F_9 ( V_10 , V_26 , V_25 ) ;
}
void T_3 F_10 ( struct V_27 * V_28 )
{
struct V_9 * V_10 ;
F_11 (dev, &bus->devices, bus_list) {
F_9 ( V_10 , V_29 , 8 ) ;
F_9 ( V_10 , V_30 , 32 ) ;
}
}
char T_3 * F_12 ( char * V_31 )
{
return V_31 ;
}
