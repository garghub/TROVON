static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
int V_13 , V_14 ;
unsigned char V_15 , V_16 , V_17 ;
V_13 = F_2 ( V_6 -> V_18 ) ;
V_14 = F_3 ( V_6 -> V_18 ) ;
if ( V_14 != V_9 -> V_19 || V_13 != V_9 -> V_20 ) {
F_4 ( ( V_13 << 4 ) | V_14 , V_2 -> V_21 + V_22 ) ;
F_5 ( 50 ) ;
}
V_17 = F_6 ( V_2 -> V_21 + V_23 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_11 ; V_11 ++ ) {
V_12 = 0 ;
do {
V_17 = F_6 ( V_2 -> V_21 + V_24 ) ;
V_17 = V_17 & V_25 ;
} while ( V_17 == 0 && ++ V_12 < V_26 );
V_15 = F_6 ( V_2 -> V_21 + V_27 ) ;
V_16 = F_6 ( V_2 -> V_21 + V_23 ) ;
V_7 [ V_11 ] = ( V_15 << 8 ) | V_16 ;
}
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = ( F_6 ( V_2 -> V_21 + V_24 ) & ( 0x1f ) ) ;
return V_6 -> V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_28 ;
unsigned int V_29 ;
unsigned int V_30 ;
V_28 = F_9 ( V_4 , V_7 ) ;
if ( V_28 ) {
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
if ( ( V_28 >> V_29 ) & 0x01 ) {
V_30 = ( V_4 -> V_31 >> V_29 ) & 0x01 ;
F_4 ( ( V_30 << 3 ) | V_29 ,
V_2 -> V_21 + V_32 ) ;
}
}
}
V_7 [ 1 ] = V_4 -> V_31 ;
return V_6 -> V_11 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_35 ;
V_35 = F_11 ( V_2 , V_34 -> V_36 [ 0 ] , V_37 ) ;
if ( V_35 )
return V_35 ;
V_9 = F_12 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_38 ;
V_9 -> V_39 = V_34 -> V_36 [ 1 ] ;
V_9 -> V_40 = V_34 -> V_36 [ 2 ] ;
V_9 -> V_19 = - 1 ;
V_9 -> V_20 = - 1 ;
V_35 = F_13 ( V_2 , 3 ) ;
if ( V_35 )
return V_35 ;
V_4 = & V_2 -> V_41 [ 0 ] ;
V_4 -> type = V_42 ;
if ( V_9 -> V_40 ) {
V_4 -> V_43 = V_44 | V_45 | V_46 ;
V_4 -> V_47 = 8 ;
} else {
V_4 -> V_43 = V_44 | V_45 ;
V_4 -> V_47 = 16 ;
}
if ( V_9 -> V_39 )
V_4 -> V_48 = & V_49 ;
else
V_4 -> V_48 = & V_50 ;
V_4 -> V_51 = 0xfff ;
V_4 -> V_52 = 4 ;
V_4 -> V_53 = F_1 ;
V_4 = & V_2 -> V_41 [ 1 ] ;
V_4 -> type = V_54 ;
V_4 -> V_43 = V_44 ;
V_4 -> V_47 = 5 ;
V_4 -> V_51 = 1 ;
V_4 -> V_48 = & V_55 ;
V_4 -> V_56 = F_7 ;
V_4 = & V_2 -> V_41 [ 2 ] ;
V_4 -> type = V_57 ;
V_4 -> V_43 = V_58 ;
V_4 -> V_47 = 8 ;
V_4 -> V_51 = 1 ;
V_4 -> V_48 = & V_55 ;
V_4 -> V_56 = F_8 ;
return 0 ;
}
