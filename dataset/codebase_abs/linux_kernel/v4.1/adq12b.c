static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned char V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 & V_11 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_19 = F_5 ( V_6 -> V_18 ) ;
unsigned int V_20 ;
int V_21 ;
int V_22 ;
V_20 = F_6 ( V_19 ) | F_7 ( V_17 ) ;
if ( V_20 != V_15 -> V_23 ) {
F_8 ( V_20 , V_2 -> V_9 + V_24 ) ;
V_15 -> V_23 = V_20 ;
F_9 ( 50 ) ;
}
V_20 = F_2 ( V_2 -> V_9 + V_25 ) ;
for ( V_22 = 0 ; V_22 < V_6 -> V_26 ; V_22 ++ ) {
V_21 = F_10 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_21 )
return V_21 ;
V_20 = F_2 ( V_2 -> V_9 + V_27 ) << 8 ;
V_20 |= F_2 ( V_2 -> V_9 + V_25 ) ;
V_13 [ V_22 ] = V_20 ;
}
return V_6 -> V_26 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
V_13 [ 1 ] = ( F_2 ( V_2 -> V_9 + V_10 ) & V_28 ) ;
return V_6 -> V_26 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_29 ;
unsigned int V_17 ;
unsigned int V_20 ;
V_29 = F_13 ( V_4 , V_13 ) ;
if ( V_29 ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( ( V_29 >> V_17 ) & 0x01 ) {
V_20 = ( V_4 -> V_30 >> V_17 ) & 0x01 ;
F_8 ( ( V_20 << 3 ) | V_17 ,
V_2 -> V_9 + V_31 ) ;
}
}
}
V_13 [ 1 ] = V_4 -> V_30 ;
return V_6 -> V_26 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_21 ;
V_21 = F_15 ( V_2 , V_33 -> V_34 [ 0 ] , 0x10 ) ;
if ( V_21 )
return V_21 ;
V_15 = F_16 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_35 ;
V_15 -> V_23 = - 1 ;
V_21 = F_17 ( V_2 , 3 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_36 [ 0 ] ;
V_4 -> type = V_37 ;
if ( V_33 -> V_34 [ 2 ] ) {
V_4 -> V_38 = V_39 | V_40 ;
V_4 -> V_41 = 8 ;
} else {
V_4 -> V_38 = V_39 | V_42 ;
V_4 -> V_41 = 16 ;
}
V_4 -> V_43 = 0xfff ;
V_4 -> V_44 = V_33 -> V_34 [ 1 ] ? & V_45
: & V_46 ;
V_4 -> V_47 = F_3 ;
V_4 = & V_2 -> V_36 [ 1 ] ;
V_4 -> type = V_48 ;
V_4 -> V_38 = V_39 ;
V_4 -> V_41 = 5 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = & V_49 ;
V_4 -> V_50 = F_11 ;
V_4 = & V_2 -> V_36 [ 2 ] ;
V_4 -> type = V_51 ;
V_4 -> V_38 = V_52 ;
V_4 -> V_41 = 8 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = & V_49 ;
V_4 -> V_50 = F_12 ;
return 0 ;
}
