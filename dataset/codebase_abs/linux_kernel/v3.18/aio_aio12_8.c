static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 & V_11 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
unsigned int V_16 = F_5 ( V_6 -> V_15 ) ;
unsigned char V_17 ;
int V_18 ;
int V_19 ;
V_17 = V_20 | V_21 |
F_6 ( V_16 ) | F_7 ( V_14 ) ;
F_2 ( V_2 -> V_9 + V_10 ) ;
for ( V_19 = 0 ; V_19 < V_6 -> V_19 ; V_19 ++ ) {
F_8 ( V_17 , V_2 -> V_9 + V_22 ) ;
V_18 = F_9 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_18 )
return V_18 ;
V_13 [ V_19 ] = F_10 ( V_2 -> V_9 + V_22 ) & V_4 -> V_23 ;
}
return V_6 -> V_19 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
unsigned int V_24 = V_4 -> V_25 [ V_14 ] ;
int V_26 ;
F_8 ( V_27 , V_2 -> V_9 + V_28 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_19 ; V_26 ++ ) {
V_24 = V_13 [ V_26 ] ;
F_12 ( V_24 , V_2 -> V_9 + F_13 ( V_14 ) ) ;
}
V_4 -> V_25 [ V_14 ] = V_24 ;
return V_6 -> V_19 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
const struct V_31 * V_32 = V_2 -> V_33 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_15 ( V_2 , V_30 -> V_34 [ 0 ] , 32 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_16 ( V_2 , 4 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_35 [ 0 ] ;
if ( V_32 -> V_36 ) {
V_4 -> type = V_37 ;
V_4 -> V_38 = V_39 | V_40 | V_41 ;
V_4 -> V_42 = V_32 -> V_36 ;
V_4 -> V_23 = 0x0fff ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_45 = F_3 ;
} else {
V_4 -> type = V_46 ;
}
V_4 = & V_2 -> V_35 [ 1 ] ;
if ( V_32 -> V_47 ) {
V_4 -> type = V_48 ;
V_4 -> V_38 = V_49 | V_40 | V_41 ;
V_4 -> V_42 = 4 ;
V_4 -> V_23 = 0x0fff ;
V_4 -> V_43 = & V_44 ;
V_4 -> V_50 = F_11 ;
V_4 -> V_45 = V_51 ;
V_18 = F_17 ( V_4 ) ;
if ( V_18 )
return V_18 ;
} else {
V_4 -> type = V_46 ;
}
V_4 = & V_2 -> V_35 [ 2 ] ;
V_18 = F_18 ( V_2 , V_4 , NULL , V_52 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_35 [ 3 ] ;
V_4 -> type = V_46 ;
return 0 ;
}
