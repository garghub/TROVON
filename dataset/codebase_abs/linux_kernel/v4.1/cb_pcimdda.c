static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned long V_10 = V_2 -> V_11 + F_3 ( V_8 ) ;
unsigned int V_12 = V_4 -> V_13 [ V_8 ] ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_6 -> V_15 ; V_14 ++ ) {
V_12 = V_7 [ V_14 ] ;
F_4 ( V_12 & 0x00ff , V_10 ) ;
F_4 ( ( V_12 >> 8 ) & 0x00ff , V_10 + 1 ) ;
}
V_4 -> V_13 [ V_8 ] = V_12 ;
return V_6 -> V_15 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
F_6 ( V_2 -> V_11 + F_3 ( V_8 ) ) ;
return F_7 ( V_2 , V_4 , V_6 , V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_16 )
{
struct V_17 * V_18 = F_9 ( V_2 ) ;
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_10 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_11 = F_11 ( V_18 , 3 ) ;
V_19 = F_12 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_20 [ 0 ] ;
V_4 -> type = V_21 ;
V_4 -> V_22 = V_23 | V_24 ;
V_4 -> V_25 = 6 ;
V_4 -> V_26 = 0xffff ;
V_4 -> V_27 = & V_28 ;
V_4 -> V_29 = F_1 ;
V_4 -> V_30 = F_5 ;
V_19 = F_13 ( V_4 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_20 [ 1 ] ;
V_19 = F_14 ( V_2 , V_4 , NULL , V_31 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_15 ( struct V_17 * V_2 ,
const struct V_32 * V_33 )
{
return F_16 ( V_2 , & V_34 ,
V_33 -> V_35 ) ;
}
