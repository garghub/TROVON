static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_8 ;
unsigned int V_9 , V_10 ;
char V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = V_2 -> V_13 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_3 ( V_11 , V_13 + 2 ) ;
F_3 ( 0 , V_13 + 3 ) ;
F_4 ( 30 ) ;
V_9 = F_5 ( V_13 + 2 ) ;
V_10 = F_5 ( V_13 + 3 ) & 0xf ;
V_7 [ V_8 ] = V_9 + ( V_10 << 8 ) ;
}
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_8 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = V_2 -> V_13 ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ ) {
F_3 ( V_7 [ V_8 ] & 0x0ff , V_13 + 4 + 2 * V_11 ) ;
F_3 ( ( V_7 [ V_8 ] & 0xf00 ) >> 8 , V_13 + 4 + 2 * V_11 ) ;
F_5 ( V_13 + 4 + 2 * V_11 ) ;
V_15 -> V_17 [ V_11 ] = V_7 [ V_8 ] ;
}
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_8 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_8 ; V_8 ++ )
V_7 [ V_8 ] = V_15 -> V_17 [ V_11 ] ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_20 ;
V_20 = F_9 ( V_2 , V_19 -> V_21 [ 0 ] , V_22 ) ;
if ( V_20 )
return V_20 ;
V_15 = F_10 ( sizeof( * V_15 ) , V_23 ) ;
if ( ! V_15 )
return - V_24 ;
V_2 -> V_16 = V_15 ;
V_20 = F_11 ( V_2 , 2 ) ;
if ( V_20 )
return V_20 ;
V_4 = & V_2 -> V_25 [ 0 ] ;
V_4 -> type = V_26 ;
V_4 -> V_27 = V_28 | V_29 ;
V_4 -> V_30 = 16 ;
V_4 -> V_31 = 0x0fff ;
V_4 -> V_32 = & V_33 ;
V_4 -> V_34 = F_1 ;
V_4 = & V_2 -> V_25 [ 1 ] ;
V_4 -> type = V_35 ;
V_4 -> V_27 = V_36 ;
V_4 -> V_30 = 2 ;
V_4 -> V_31 = 0x0fff ;
V_4 -> V_32 = & V_33 ;
V_4 -> V_37 = F_6 ;
V_4 -> V_34 = F_7 ;
return 1 ;
}
