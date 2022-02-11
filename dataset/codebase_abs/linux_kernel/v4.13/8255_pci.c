static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_2 , 0 ) ;
if ( ! V_3 )
return - V_5 ;
V_4 = F_3 ( V_2 , 1 ) ;
F_4 ( V_4 | V_6 , V_3 + V_7 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 ,
unsigned long V_10 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
const struct V_11 * V_12 = NULL ;
struct V_13 * V_14 ;
int V_15 ;
int V_16 ;
if ( V_10 < F_8 ( V_17 ) )
V_12 = & V_17 [ V_10 ] ;
if ( ! V_12 )
return - V_18 ;
V_9 -> V_19 = V_12 ;
V_9 -> V_20 = V_12 -> V_21 ;
V_15 = F_9 ( V_9 ) ;
if ( V_15 )
return V_15 ;
if ( V_12 -> V_22 ) {
V_15 = F_1 ( V_2 ) ;
if ( V_15 )
return V_15 ;
}
if ( ( F_10 ( V_2 , V_12 -> V_23 ) & V_24 ) ) {
V_9 -> V_25 = F_2 ( V_2 , V_12 -> V_23 ) ;
if ( ! V_9 -> V_25 )
return - V_5 ;
} else {
V_9 -> V_26 = F_3 ( V_2 , V_12 -> V_23 ) ;
}
V_15 = F_11 ( V_9 , V_12 -> V_27 ) ;
if ( V_15 )
return V_15 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_27 ; V_16 ++ ) {
V_14 = & V_9 -> V_28 [ V_16 ] ;
if ( V_9 -> V_25 )
V_15 = F_12 ( V_9 , V_14 , NULL , V_16 * V_29 ) ;
else
V_15 = F_13 ( V_9 , V_14 , NULL , V_16 * V_29 ) ;
if ( V_15 )
return V_15 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_9 ,
const struct V_30 * V_31 )
{
return F_15 ( V_9 , & V_32 , V_31 -> V_33 ) ;
}
