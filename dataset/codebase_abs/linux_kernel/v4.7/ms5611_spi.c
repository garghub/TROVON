static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
return F_4 ( V_6 -> V_7 , & V_3 , 1 , NULL , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_8 , T_2 * V_9 )
{
int V_10 ;
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
V_10 = F_6 ( V_6 -> V_7 , V_11 + ( V_8 << 1 ) ) ;
if ( V_10 < 0 )
return V_10 ;
* V_9 = V_10 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_3 * V_12 )
{
int V_10 ;
T_1 V_13 [ 3 ] = { V_14 } ;
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
V_10 = F_4 ( V_6 -> V_7 , V_13 , 1 , V_13 , 3 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_12 = ( V_13 [ 0 ] << 16 ) | ( V_13 [ 1 ] << 8 ) | V_13 [ 2 ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_3 * V_15 , T_3 * V_16 )
{
int V_10 ;
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
const struct V_17 * V_18 = V_6 -> V_19 ;
V_10 = F_4 ( V_6 -> V_7 , & V_18 -> V_3 , 1 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
F_9 ( V_18 -> V_20 , V_18 -> V_20 + ( V_18 -> V_20 / 10UL ) ) ;
V_10 = F_7 ( V_2 , V_15 ) ;
if ( V_10 < 0 )
return V_10 ;
V_18 = V_6 -> V_21 ;
V_10 = F_4 ( V_6 -> V_7 , & V_18 -> V_3 , 1 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
F_9 ( V_18 -> V_20 , V_18 -> V_20 + ( V_18 -> V_20 / 10UL ) ) ;
return F_7 ( V_2 , V_16 ) ;
}
static int F_10 ( struct V_22 * V_23 )
{
int V_10 ;
struct V_5 * V_6 ;
struct V_24 * V_25 ;
V_25 = F_11 ( & V_23 -> V_2 , sizeof( * V_6 ) ) ;
if ( ! V_25 )
return - V_26 ;
F_12 ( V_23 , V_25 ) ;
V_23 -> V_27 = V_28 ;
V_23 -> V_29 = 20000000 ;
V_23 -> V_30 = 8 ;
V_10 = F_13 ( V_23 ) ;
if ( V_10 < 0 )
return V_10 ;
V_6 = F_2 ( V_25 ) ;
V_6 -> V_31 = F_1 ;
V_6 -> V_32 = F_5 ;
V_6 -> V_33 = F_8 ;
V_6 -> V_7 = V_23 ;
return F_14 ( V_25 , & V_23 -> V_2 , F_15 ( V_23 ) -> V_34 ,
F_15 ( V_23 ) -> V_35 ) ;
}
static int F_16 ( struct V_22 * V_23 )
{
return F_17 ( F_18 ( V_23 ) ) ;
}
