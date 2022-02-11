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
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_17 ;
int V_18 , V_19 ;
unsigned char V_20 , V_21 , V_8 ;
int V_22 ;
V_18 = F_4 ( V_6 -> V_23 ) ;
V_19 = F_5 ( V_6 -> V_23 ) ;
if ( V_19 != V_15 -> V_24 || V_18 != V_15 -> V_25 ) {
F_6 ( ( V_18 << 4 ) | V_19 , V_2 -> V_9 + V_26 ) ;
F_7 ( 50 ) ;
}
V_8 = F_2 ( V_2 -> V_9 + V_27 ) ;
for ( V_17 = 0 ; V_17 < V_6 -> V_17 ; V_17 ++ ) {
V_22 = F_8 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_22 )
return V_22 ;
V_20 = F_2 ( V_2 -> V_9 + V_28 ) ;
V_21 = F_2 ( V_2 -> V_9 + V_27 ) ;
V_13 [ V_17 ] = ( V_20 << 8 ) | V_21 ;
}
return V_17 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
V_13 [ 1 ] = ( F_2 ( V_2 -> V_9 + V_10 ) & ( 0x1f ) ) ;
return V_6 -> V_17 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_29 ;
unsigned int V_30 ;
unsigned int V_31 ;
V_29 = F_11 ( V_4 , V_13 ) ;
if ( V_29 ) {
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ ) {
if ( ( V_29 >> V_30 ) & 0x01 ) {
V_31 = ( V_4 -> V_32 >> V_30 ) & 0x01 ;
F_6 ( ( V_31 << 3 ) | V_30 ,
V_2 -> V_9 + V_33 ) ;
}
}
}
V_13 [ 1 ] = V_4 -> V_32 ;
return V_6 -> V_17 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_22 ;
V_22 = F_13 ( V_2 , V_35 -> V_36 [ 0 ] , V_37 ) ;
if ( V_22 )
return V_22 ;
V_15 = F_14 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_38 ;
V_15 -> V_39 = V_35 -> V_36 [ 1 ] ;
V_15 -> V_40 = V_35 -> V_36 [ 2 ] ;
V_15 -> V_24 = - 1 ;
V_15 -> V_25 = - 1 ;
V_22 = F_15 ( V_2 , 3 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_41 [ 0 ] ;
V_4 -> type = V_42 ;
if ( V_15 -> V_40 ) {
V_4 -> V_43 = V_44 | V_45 | V_46 ;
V_4 -> V_47 = 8 ;
} else {
V_4 -> V_43 = V_44 | V_45 ;
V_4 -> V_47 = 16 ;
}
if ( V_15 -> V_39 )
V_4 -> V_48 = & V_49 ;
else
V_4 -> V_48 = & V_50 ;
V_4 -> V_51 = 0xfff ;
V_4 -> V_52 = 4 ;
V_4 -> V_53 = F_3 ;
V_4 = & V_2 -> V_41 [ 1 ] ;
V_4 -> type = V_54 ;
V_4 -> V_43 = V_44 ;
V_4 -> V_47 = 5 ;
V_4 -> V_51 = 1 ;
V_4 -> V_48 = & V_55 ;
V_4 -> V_56 = F_9 ;
V_4 = & V_2 -> V_41 [ 2 ] ;
V_4 -> type = V_57 ;
V_4 -> V_43 = V_58 ;
V_4 -> V_47 = 8 ;
V_4 -> V_51 = 1 ;
V_4 -> V_48 = & V_55 ;
V_4 -> V_56 = F_10 ;
return 0 ;
}
