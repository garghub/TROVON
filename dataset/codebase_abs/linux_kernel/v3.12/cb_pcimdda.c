static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = V_2 -> V_14 + F_3 ( V_11 ) ;
unsigned int V_15 = 0 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ ) {
V_15 = V_7 [ V_16 ] ;
F_4 ( V_15 & 0x00ff , V_13 ) ;
F_4 ( ( V_15 >> 8 ) & 0x00ff , V_13 + 1 ) ;
}
V_9 -> V_18 [ V_11 ] = V_15 ;
return V_6 -> V_17 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = V_2 -> V_14 + F_3 ( V_11 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ ) {
F_6 ( V_13 ) ;
V_7 [ V_16 ] = V_9 -> V_18 [ V_11 ] ;
}
return V_6 -> V_17 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_22 ;
V_9 = F_9 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_23 ;
V_22 = F_10 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_14 = F_11 ( V_21 , 3 ) ;
V_22 = F_12 ( V_2 , 2 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_24 [ 0 ] ;
V_4 -> type = V_25 ;
V_4 -> V_26 = V_27 | V_28 ;
V_4 -> V_29 = 6 ;
V_4 -> V_30 = 0xffff ;
V_4 -> V_31 = & V_32 ;
V_4 -> V_33 = F_1 ;
V_4 -> V_34 = F_5 ;
V_4 = & V_2 -> V_24 [ 1 ] ;
V_22 = F_13 ( V_2 , V_4 , NULL ,
V_2 -> V_14 + V_35 ) ;
if ( V_22 )
return V_22 ;
F_14 ( V_2 -> V_36 , L_1 , V_2 -> V_37 ) ;
return 1 ;
}
static int F_15 ( struct V_20 * V_2 ,
const struct V_38 * V_39 )
{
return F_16 ( V_2 , & V_40 ,
V_39 -> V_41 ) ;
}
