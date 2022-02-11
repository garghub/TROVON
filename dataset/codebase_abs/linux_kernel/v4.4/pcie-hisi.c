static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static int F_5 ( struct V_6 * V_7 , int V_8 , int V_9 ,
T_1 * V_3 )
{
T_1 V_4 ;
T_1 V_10 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
void * V_11 = & V_10 ;
V_11 += ( V_8 & 0x3 ) ;
V_4 = V_8 & ~ 0x3 ;
V_10 = F_3 ( V_2 , V_4 ) ;
if ( V_9 == 1 )
* V_3 = * ( V_12 V_13 * ) V_11 ;
else if ( V_9 == 2 )
* V_3 = * ( V_14 V_13 * ) V_11 ;
else if ( V_9 == 4 )
* V_3 = V_10 ;
else
return V_15 ;
return V_16 ;
}
static int F_7 ( struct V_6 * V_7 , int V_8 , int V_9 ,
T_1 V_3 )
{
T_1 V_10 ;
T_1 V_4 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
void * V_11 = & V_10 ;
V_11 += ( V_8 & 0x3 ) ;
V_4 = V_8 & ~ 0x3 ;
if ( V_9 == 4 )
F_1 ( V_2 , V_3 , V_4 ) ;
else if ( V_9 == 2 ) {
V_10 = F_3 ( V_2 , V_4 ) ;
* ( V_14 V_13 * ) V_11 = V_3 ;
F_1 ( V_2 , V_10 , V_4 ) ;
} else if ( V_9 == 1 ) {
V_10 = F_3 ( V_2 , V_4 ) ;
* ( V_12 V_13 * ) V_11 = V_3 ;
F_1 ( V_2 , V_10 , V_4 ) ;
} else
return V_15 ;
return V_16 ;
}
static int F_8 ( struct V_6 * V_7 )
{
T_1 V_3 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
F_9 ( V_1 -> V_17 , V_18 +
0x100 * V_1 -> V_19 , & V_3 ) ;
return ( ( V_3 & V_20 ) == V_21 ) ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_22 * V_23 )
{
int V_24 ;
T_1 V_19 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( F_11 ( V_23 -> V_25 . V_26 , L_1 , & V_19 ) ) {
F_12 ( & V_23 -> V_25 , L_2 ) ;
return - V_27 ;
}
if ( V_19 > 3 ) {
F_12 ( & V_23 -> V_25 , L_3 , V_19 ) ;
return - V_27 ;
}
V_1 -> V_19 = V_19 ;
V_7 -> V_28 = & V_29 ;
V_24 = F_13 ( V_7 ) ;
if ( V_24 ) {
F_12 ( & V_23 -> V_25 , L_4 ) ;
return V_24 ;
}
return 0 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_1 * V_1 ;
struct V_6 * V_7 ;
struct V_30 * V_4 ;
int V_24 ;
V_1 = F_15 ( & V_23 -> V_25 , sizeof( * V_1 ) , V_31 ) ;
if ( ! V_1 )
return - V_32 ;
V_7 = & V_1 -> V_7 ;
V_7 -> V_25 = & V_23 -> V_25 ;
V_1 -> V_17 =
F_16 ( L_5 ) ;
if ( F_17 ( V_1 -> V_17 ) ) {
F_12 ( V_7 -> V_25 , L_6 ) ;
return F_18 ( V_1 -> V_17 ) ;
}
V_4 = F_19 ( V_23 , V_33 , L_7 ) ;
V_1 -> V_5 = F_20 ( & V_23 -> V_25 , V_4 ) ;
if ( F_17 ( V_1 -> V_5 ) ) {
F_12 ( V_7 -> V_25 , L_8 ) ;
return F_18 ( V_1 -> V_5 ) ;
}
V_1 -> V_7 . V_34 = V_1 -> V_5 ;
V_24 = F_10 ( V_7 , V_23 ) ;
if ( V_24 )
return V_24 ;
F_21 ( V_23 , V_1 ) ;
F_22 ( V_7 -> V_25 , L_9 ) ;
return 0 ;
}
