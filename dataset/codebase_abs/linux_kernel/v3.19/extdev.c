static T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 V_7 , V_8 , V_9 , V_10 ;
T_1 V_11 , V_12 = 0 ;
V_11 = F_2 ( V_2 , & V_7 , & V_8 , & V_9 , & V_10 ) ;
if ( ! V_11 || ( V_7 != 0x30 && V_7 != 0x40 ) )
return 0x0000 ;
V_12 = F_3 ( V_2 , V_11 + 18 ) ;
if ( ! V_12 )
return 0x0000 ;
* V_3 = F_4 ( V_2 , V_12 + 0 ) ;
* V_4 = F_4 ( V_2 , V_12 + 1 ) ;
* V_6 = F_4 ( V_2 , V_12 + 2 ) ;
* V_5 = F_4 ( V_2 , V_12 + 3 ) ;
return V_12 + * V_4 ;
}
static T_1
F_5 ( struct V_1 * V_2 , int V_13 , T_2 * V_3 , T_2 * V_5 )
{
T_2 V_4 , V_6 ;
T_1 V_12 = F_1 ( V_2 , V_3 , & V_4 , V_5 , & V_6 ) ;
if ( V_12 && V_13 < V_6 )
return V_12 + V_13 * * V_5 ;
return 0x0000 ;
}
static void
F_6 ( struct V_1 * V_2 , T_1 V_14 ,
struct V_15 * V_16 )
{
V_16 -> type = F_4 ( V_2 , V_14 + 0 ) ;
V_16 -> V_17 = F_4 ( V_2 , V_14 + 1 ) ;
V_16 -> V_18 = ( F_4 ( V_2 , V_14 + 2 ) >> 4 ) & 1 ;
}
int
F_7 ( struct V_1 * V_2 , int V_13 ,
struct V_15 * V_19 )
{
T_2 V_3 , V_5 ;
T_1 V_16 ;
if ( ! ( V_16 = F_5 ( V_2 , V_13 , & V_3 , & V_5 ) ) )
return - V_20 ;
F_6 ( V_2 , V_16 , V_19 ) ;
return 0 ;
}
int
F_8 ( struct V_1 * V_2 , enum V_21 type ,
struct V_15 * V_19 )
{
T_2 V_3 , V_5 , V_22 ;
T_1 V_16 ;
V_22 = 0 ;
while ( ( V_16 = F_5 ( V_2 , V_22 ++ , & V_3 , & V_5 ) ) ) {
F_6 ( V_2 , V_16 , V_19 ) ;
if ( V_19 -> type == type )
return 0 ;
}
return - V_20 ;
}
