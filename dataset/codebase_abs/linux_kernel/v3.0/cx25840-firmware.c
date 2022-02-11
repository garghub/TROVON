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
return L_1 ;
if ( F_8 ( V_4 ) )
return L_2 ;
return L_3 ;
}
static int F_9 ( struct V_1 * V_2 , int V_6 )
{
int V_7 = F_10 ( V_2 , 0x801 ) << 8 ;
V_7 |= F_10 ( V_2 , 0x800 ) ;
if ( V_6 != V_7 ) {
F_11 ( V_2 , L_4 ,
F_4 ( V_2 ) ) ;
return - V_8 ;
}
F_12 ( V_2 , L_5 ,
F_4 ( V_2 ) , V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_9 , int V_6 )
{
if ( F_14 ( V_2 , V_9 , V_6 ) < V_6 ) {
F_11 ( V_2 , L_6 ) ;
return - V_10 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( F_6 ( V_2 ) ) ;
const struct V_5 * V_11 = NULL ;
T_1 V_12 [ V_13 ] ;
const T_1 * V_14 ;
const char * V_15 = F_4 ( V_2 ) ;
int V_6 , V_16 ;
int V_17 = V_13 ;
T_2 V_18 = 0 , V_19 = 0 ;
if ( F_7 ( V_4 ) ) {
V_18 = F_10 ( V_2 , 0x160 ) ;
V_19 = F_10 ( V_2 , 0x164 ) ;
}
if ( F_8 ( V_4 ) && V_17 > 16 ) {
F_11 ( V_2 , L_7 ) ;
V_17 = 16 ;
}
if ( F_16 ( & V_11 , V_15 , F_17 ( V_2 ) ) != 0 ) {
F_11 ( V_2 , L_8 , V_15 ) ;
return - V_8 ;
}
F_1 ( V_2 ) ;
V_12 [ 0 ] = 0x08 ;
V_12 [ 1 ] = 0x02 ;
V_6 = V_11 -> V_6 ;
V_14 = V_11 -> V_9 ;
while ( V_6 > 0 ) {
int V_20 = F_18 ( V_17 - 2 , V_6 ) ;
memcpy ( V_12 + 2 , V_14 , V_20 ) ;
V_16 = F_13 ( V_2 , V_12 , V_20 + 2 ) ;
if ( V_16 < 0 ) {
F_19 ( V_11 ) ;
return V_16 ;
}
V_6 -= V_20 ;
V_14 += V_20 ;
}
F_3 ( V_2 ) ;
V_6 = V_11 -> V_6 ;
F_19 ( V_11 ) ;
if ( F_7 ( V_4 ) ) {
F_2 ( V_2 , 0x160 , V_18 ) ;
F_2 ( V_2 , 0x164 , V_19 ) ;
}
return F_9 ( V_2 , V_6 ) ;
}
