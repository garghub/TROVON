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
struct V_5 * V_6 , unsigned int * V_13 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
int V_27 = V_25 -> V_28 [ V_14 ] ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_19 ; V_29 ++ )
V_13 [ V_29 ] = V_27 ;
return V_6 -> V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_13 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
unsigned long V_30 = V_2 -> V_9 + F_13 ( V_14 ) ;
unsigned int V_27 = 0 ;
int V_29 ;
F_8 ( V_31 , V_2 -> V_9 + V_32 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_19 ; V_29 ++ ) {
V_27 = V_13 [ V_29 ] ;
F_14 ( V_27 , V_30 ) ;
}
V_25 -> V_28 [ V_14 ] = V_27 ;
return V_6 -> V_19 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
const struct V_35 * V_36 = F_16 ( V_2 ) ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
int V_18 ;
V_18 = F_17 ( V_2 , V_34 -> V_37 [ 0 ] , 32 ) ;
if ( V_18 )
return V_18 ;
V_25 = F_18 ( V_2 , sizeof( * V_25 ) ) ;
if ( ! V_25 )
return - V_38 ;
V_18 = F_19 ( V_2 , 4 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_39 [ 0 ] ;
if ( V_36 -> V_40 ) {
V_4 -> type = V_41 ;
V_4 -> V_42 = V_43 | V_44 | V_45 ;
V_4 -> V_46 = V_36 -> V_40 ;
V_4 -> V_23 = 0x0fff ;
V_4 -> V_47 = & V_48 ;
V_4 -> V_49 = F_3 ;
} else {
V_4 -> type = V_50 ;
}
V_4 = & V_2 -> V_39 [ 1 ] ;
if ( V_36 -> V_51 ) {
V_4 -> type = V_52 ;
V_4 -> V_42 = V_53 | V_44 | V_45 ;
V_4 -> V_46 = 4 ;
V_4 -> V_23 = 0x0fff ;
V_4 -> V_47 = & V_48 ;
V_4 -> V_49 = F_11 ;
V_4 -> V_54 = F_12 ;
} else {
V_4 -> type = V_50 ;
}
V_4 = & V_2 -> V_39 [ 2 ] ;
V_18 = F_20 ( V_2 , V_4 , NULL ,
V_2 -> V_9 + V_55 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_39 [ 3 ] ;
V_4 -> type = V_50 ;
return 0 ;
}
