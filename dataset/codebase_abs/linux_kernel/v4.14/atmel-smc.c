void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
static int F_2 ( unsigned int V_3 ,
unsigned int V_4 ,
unsigned int V_5 ,
unsigned int V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_3 ( V_4 - 1 , 0 ) ;
unsigned int V_9 = F_3 ( V_5 - 1 , 0 ) ;
unsigned int V_10 , V_11 ;
int V_12 = 0 ;
V_10 = V_3 / V_6 ;
V_11 = V_3 % V_6 ;
if ( V_11 > V_8 ) {
V_11 = 0 ;
V_10 ++ ;
}
if ( V_10 > V_9 ) {
V_10 = V_9 ;
V_11 = V_8 ;
V_12 = - V_13 ;
}
* V_7 = ( V_10 << V_4 ) | V_11 ;
return V_12 ;
}
int F_4 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_3 )
{
unsigned int V_15 ;
int V_12 ;
if ( V_14 != V_16 &&
V_14 != V_17 &&
V_14 != V_18 &&
V_14 != V_19 &&
V_14 != V_20 )
return - V_21 ;
V_12 = F_2 ( V_3 , 3 , 1 , 64 , & V_15 ) ;
V_2 -> V_22 &= ~ F_3 ( V_14 + 3 , V_14 ) ;
V_2 -> V_22 |= V_15 << V_14 ;
return V_12 ;
}
int F_5 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_3 )
{
unsigned int V_15 ;
int V_12 ;
if ( V_14 != V_23 && V_14 != V_24 &&
V_14 != V_25 && V_14 != V_26 )
return - V_21 ;
V_12 = F_2 ( V_3 , 5 , 1 , 128 , & V_15 ) ;
V_2 -> V_27 &= ~ F_3 ( V_14 + 7 , V_14 ) ;
V_2 -> V_27 |= V_15 << V_14 ;
return V_12 ;
}
int F_6 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_3 )
{
unsigned int V_15 ;
int V_12 ;
if ( V_14 != V_23 && V_14 != V_24 &&
V_14 != V_25 && V_14 != V_26 )
return - V_21 ;
V_12 = F_2 ( V_3 , 6 , 1 , 256 , & V_15 ) ;
V_2 -> V_28 &= ~ F_3 ( V_14 + 7 , V_14 ) ;
V_2 -> V_28 |= V_15 << V_14 ;
return V_12 ;
}
int F_7 ( struct V_1 * V_2 ,
unsigned int V_14 , unsigned int V_3 )
{
unsigned int V_15 ;
int V_12 ;
if ( V_14 != V_23 && V_14 != V_25 )
return - V_21 ;
V_12 = F_2 ( V_3 , 7 , 2 , 256 , & V_15 ) ;
V_2 -> V_29 &= ~ F_3 ( V_14 + 15 , V_14 ) ;
V_2 -> V_29 |= V_15 << V_14 ;
return V_12 ;
}
void F_8 ( struct V_30 * V_30 , int V_31 ,
const struct V_1 * V_2 )
{
F_9 ( V_30 , F_10 ( V_31 ) , V_2 -> V_27 ) ;
F_9 ( V_30 , F_11 ( V_31 ) , V_2 -> V_28 ) ;
F_9 ( V_30 , F_12 ( V_31 ) , V_2 -> V_29 ) ;
F_9 ( V_30 , F_13 ( V_31 ) , V_2 -> V_32 ) ;
}
void F_14 ( struct V_30 * V_30 ,
const struct V_33 * V_34 ,
int V_31 , const struct V_1 * V_2 )
{
F_9 ( V_30 , F_15 ( V_34 , V_31 ) , V_2 -> V_27 ) ;
F_9 ( V_30 , F_16 ( V_34 , V_31 ) , V_2 -> V_28 ) ;
F_9 ( V_30 , F_17 ( V_34 , V_31 ) , V_2 -> V_29 ) ;
F_9 ( V_30 , F_18 ( V_34 , V_31 ) , V_2 -> V_22 ) ;
F_9 ( V_30 , F_19 ( V_34 , V_31 ) , V_2 -> V_32 ) ;
}
void F_20 ( struct V_30 * V_30 , int V_31 ,
struct V_1 * V_2 )
{
F_21 ( V_30 , F_10 ( V_31 ) , & V_2 -> V_27 ) ;
F_21 ( V_30 , F_11 ( V_31 ) , & V_2 -> V_28 ) ;
F_21 ( V_30 , F_12 ( V_31 ) , & V_2 -> V_29 ) ;
F_21 ( V_30 , F_13 ( V_31 ) , & V_2 -> V_32 ) ;
}
void F_22 ( struct V_30 * V_30 ,
const struct V_33 * V_34 ,
int V_31 , struct V_1 * V_2 )
{
F_21 ( V_30 , F_15 ( V_34 , V_31 ) , & V_2 -> V_27 ) ;
F_21 ( V_30 , F_16 ( V_34 , V_31 ) , & V_2 -> V_28 ) ;
F_21 ( V_30 , F_17 ( V_34 , V_31 ) , & V_2 -> V_29 ) ;
F_21 ( V_30 , F_18 ( V_34 , V_31 ) , & V_2 -> V_22 ) ;
F_21 ( V_30 , F_19 ( V_34 , V_31 ) , & V_2 -> V_32 ) ;
}
const struct V_33 *
F_23 ( struct V_35 * V_36 )
{
const struct V_37 * V_38 ;
V_38 = F_24 ( V_39 , V_36 ) ;
return V_38 ? V_38 -> V_40 : F_25 ( - V_21 ) ;
}
