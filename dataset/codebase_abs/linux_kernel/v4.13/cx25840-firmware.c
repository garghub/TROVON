static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0x800 , 0x00 ) ;
F_2 ( V_2 , 0x801 , 0x00 ) ;
F_2 ( V_2 , 0x803 , 0x0b ) ;
F_2 ( V_2 , 0x000 , 0x20 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0x000 , 0x00 ) ;
F_2 ( V_2 , 0x803 , 0x03 ) ;
}
static const char * F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( F_6 ( V_2 ) ) ;
if ( V_5 [ 0 ] )
return V_5 ;
if ( F_7 ( V_4 ) )
return V_6 ;
if ( F_8 ( V_4 ) )
return V_7 ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , int V_9 )
{
int V_10 = F_10 ( V_2 , 0x801 ) << 8 ;
V_10 |= F_10 ( V_2 , 0x800 ) ;
if ( V_9 != V_10 ) {
F_11 ( V_2 , L_1 ,
F_4 ( V_2 ) ) ;
return - V_11 ;
}
F_12 ( V_2 , L_2 ,
F_4 ( V_2 ) , V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_12 , int V_9 )
{
if ( F_14 ( V_2 , V_12 , V_9 ) < V_9 ) {
F_11 ( V_2 , L_3 ) ;
return - V_13 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( F_6 ( V_2 ) ) ;
const struct V_5 * V_14 = NULL ;
T_1 V_15 [ V_16 ] ;
const T_1 * V_17 ;
const char * V_18 = F_4 ( V_2 ) ;
int V_9 , V_19 ;
int V_20 = V_16 ;
T_2 V_21 = 0 , V_22 = 0 ;
if ( F_7 ( V_4 ) ) {
V_21 = F_10 ( V_2 , 0x160 ) ;
V_22 = F_10 ( V_2 , 0x164 ) ;
}
if ( F_8 ( V_4 ) && V_20 > 16 )
V_20 = 16 ;
if ( F_16 ( & V_14 , V_18 , F_17 ( V_2 ) ) != 0 ) {
F_11 ( V_2 , L_4 , V_18 ) ;
return - V_11 ;
}
F_1 ( V_2 ) ;
V_15 [ 0 ] = 0x08 ;
V_15 [ 1 ] = 0x02 ;
V_9 = V_14 -> V_9 ;
V_17 = V_14 -> V_12 ;
while ( V_9 > 0 ) {
int V_23 = F_18 ( V_20 - 2 , V_9 ) ;
memcpy ( V_15 + 2 , V_17 , V_23 ) ;
V_19 = F_13 ( V_2 , V_15 , V_23 + 2 ) ;
if ( V_19 < 0 ) {
F_19 ( V_14 ) ;
return V_19 ;
}
V_9 -= V_23 ;
V_17 += V_23 ;
}
F_3 ( V_2 ) ;
V_9 = V_14 -> V_9 ;
F_19 ( V_14 ) ;
if ( F_7 ( V_4 ) ) {
F_2 ( V_2 , 0x160 , V_21 ) ;
F_2 ( V_2 , 0x164 , V_22 ) ;
}
return F_9 ( V_2 , V_9 ) ;
}
