static int F_1 ( void * V_1 , unsigned int V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
int V_7 , V_8 ;
T_2 * V_9 = V_3 ;
V_8 = F_2 ( V_6 -> V_10 ) ;
if ( V_8 )
return V_8 ;
for ( V_7 = V_2 ; V_7 < V_2 + V_4 ; V_7 ++ ) {
int V_11 = V_7 >> 5 ;
int V_12 = V_7 & 0x1f ;
* V_9 ++ = F_3 ( V_6 -> V_13 + F_4 ( V_11 ) + V_12 * 4 ) ;
}
F_5 ( V_6 -> V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 )
{
const struct V_16 * V_17 ;
struct V_18 * V_19 = & V_15 -> V_19 ;
struct V_20 * V_21 ;
struct V_5 * V_6 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
const struct V_26 * V_27 = NULL ;
V_6 = F_7 ( V_19 , sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return - V_29 ;
V_21 = F_8 ( V_15 , V_30 , 0 ) ;
V_6 -> V_13 = F_9 ( V_19 , V_21 ) ;
if ( F_10 ( V_6 -> V_13 ) )
return F_11 ( V_6 -> V_13 ) ;
V_17 = F_12 ( V_31 , V_19 ) ;
if ( ! V_17 )
return - V_32 ;
V_27 = V_17 -> V_33 ;
V_6 -> V_10 = F_13 ( & V_15 -> V_19 , NULL ) ;
if ( F_10 ( V_6 -> V_10 ) )
return F_11 ( V_6 -> V_10 ) ;
V_25 = & V_6 -> V_23 ;
V_25 -> V_34 = L_1 ,
V_25 -> V_35 = true ,
V_25 -> V_36 = 1 ,
V_25 -> V_37 = 1 ,
V_25 -> V_38 = V_39 ,
V_25 -> V_40 = F_1 ,
V_25 -> V_19 = V_19 ;
V_25 -> V_41 = V_27 -> V_42 ;
V_25 -> V_43 = V_6 ;
V_23 = F_14 ( V_25 ) ;
if ( F_10 ( V_23 ) )
return F_11 ( V_23 ) ;
F_15 ( V_15 , V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 )
{
struct V_22 * V_23 = F_17 ( V_15 ) ;
return F_18 ( V_23 ) ;
}
