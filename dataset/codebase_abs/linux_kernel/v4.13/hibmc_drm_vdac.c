static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , 800 , 600 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_5 ;
}
static struct V_6 *
F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_7 , V_2 -> V_8 [ 0 ] ) ;
}
static struct V_1 *
F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_7 = V_10 -> V_7 ;
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_7 ( V_7 -> V_7 , sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 ) {
F_8 ( L_1 ) ;
return F_9 ( - V_14 ) ;
}
V_12 = F_10 ( V_7 , V_2 ,
& V_15 ,
V_16 ) ;
if ( V_12 ) {
F_8 ( L_2 , V_12 ) ;
return F_9 ( V_12 ) ;
}
F_11 ( V_2 ,
& V_17 ) ;
return V_2 ;
}
static void F_12 ( struct V_6 * V_18 ,
struct V_3 * V_4 ,
struct V_3 * V_19 )
{
T_1 V_20 ;
struct V_11 * V_7 = V_18 -> V_7 ;
struct V_9 * V_10 = V_7 -> V_21 ;
V_20 = F_13 ( V_10 -> V_22 + V_23 ) ;
V_20 |= F_14 ( 1 ) ;
V_20 |= F_15 ( 1 ) ;
V_20 |= F_16 ( 1 ) ;
V_20 |= F_17 ( 1 ) ;
F_18 ( V_20 , V_10 -> V_22 + V_23 ) ;
}
int F_19 ( struct V_9 * V_10 )
{
struct V_11 * V_7 = V_10 -> V_7 ;
struct V_6 * V_18 ;
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_6 ( V_10 ) ;
if ( F_20 ( V_2 ) ) {
F_8 ( L_3 ,
F_21 ( V_2 ) ) ;
return F_21 ( V_2 ) ;
}
V_18 = F_7 ( V_7 -> V_7 , sizeof( * V_18 ) , V_13 ) ;
if ( ! V_18 ) {
F_8 ( L_4 ) ;
return - V_14 ;
}
V_18 -> V_24 = 0x1 ;
V_12 = F_22 ( V_7 , V_18 , & V_25 ,
V_26 , NULL ) ;
if ( V_12 ) {
F_8 ( L_5 , V_12 ) ;
return V_12 ;
}
F_23 ( V_18 , & V_27 ) ;
F_24 ( V_2 , V_18 ) ;
return 0 ;
}
