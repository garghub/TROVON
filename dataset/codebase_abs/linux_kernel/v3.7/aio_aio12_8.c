static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 = F_3 ( V_6 -> V_9 ) ;
unsigned int V_11 ;
unsigned char V_12 ;
int V_13 ;
V_12 = V_14 | V_15 |
F_4 ( V_10 ) | F_5 ( V_8 ) ;
F_6 ( V_2 -> V_16 + V_17 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
int V_18 = 5 ;
F_7 ( V_12 , V_2 -> V_16 + V_19 ) ;
do {
V_11 = F_6 ( V_2 -> V_16 + V_17 ) ;
V_18 -- ;
if ( V_18 == 0 ) {
F_8 ( V_2 -> V_20 , L_1 ) ;
return - V_21 ;
}
} while ( ! ( V_11 & V_22 ) );
V_7 [ V_13 ] = F_9 ( V_2 -> V_16 + V_19 ) & V_4 -> V_23 ;
}
return V_6 -> V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
int V_11 = V_25 -> V_27 [ V_8 ] ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_13 ; V_28 ++ )
V_7 [ V_28 ] = V_11 ;
return V_6 -> V_13 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned long V_29 = V_2 -> V_16 + F_12 ( V_8 ) ;
unsigned int V_11 = 0 ;
int V_28 ;
F_7 ( V_30 , V_2 -> V_16 + V_31 ) ;
for ( V_28 = 0 ; V_28 < V_6 -> V_13 ; V_28 ++ ) {
V_11 = V_7 [ V_28 ] ;
F_13 ( V_11 , V_29 ) ;
}
V_25 -> V_27 [ V_8 ] = V_11 ;
return V_6 -> V_13 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
const struct V_34 * V_35 = F_15 ( V_2 ) ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
int V_16 ;
int V_36 ;
V_2 -> V_37 = V_35 -> V_38 ;
V_16 = V_33 -> V_39 [ 0 ] ;
if ( ! F_16 ( V_16 , 32 , V_2 -> V_37 ) ) {
F_17 ( V_40 L_2 ) ;
return - V_41 ;
}
V_2 -> V_16 = V_16 ;
V_36 = F_18 ( V_2 , sizeof( * V_25 ) ) ;
if ( V_36 )
return V_36 ;
V_25 = V_2 -> V_26 ;
V_36 = F_19 ( V_2 , 4 ) ;
if ( V_36 )
return V_36 ;
V_4 = & V_2 -> V_42 [ 0 ] ;
if ( V_35 -> V_43 ) {
V_4 -> type = V_44 ;
V_4 -> V_45 = V_46 | V_47 | V_48 ;
V_4 -> V_49 = V_35 -> V_43 ;
V_4 -> V_23 = 0x0fff ;
V_4 -> V_50 = & V_51 ;
V_4 -> V_52 = F_1 ;
} else {
V_4 -> type = V_53 ;
}
V_4 = & V_2 -> V_42 [ 1 ] ;
if ( V_35 -> V_54 ) {
V_4 -> type = V_55 ;
V_4 -> V_45 = V_56 | V_47 | V_48 ;
V_4 -> V_49 = 4 ;
V_4 -> V_23 = 0x0fff ;
V_4 -> V_50 = & V_51 ;
V_4 -> V_52 = F_10 ;
V_4 -> V_57 = F_11 ;
} else {
V_4 -> type = V_53 ;
}
V_4 = & V_2 -> V_42 [ 2 ] ;
V_16 = V_2 -> V_16 + V_58 ;
V_36 = F_20 ( V_2 , V_4 , NULL , V_16 ) ;
if ( V_36 )
return V_36 ;
V_4 = & V_2 -> V_42 [ 3 ] ;
V_4 -> type = V_53 ;
F_21 ( V_2 -> V_20 , L_3 ,
V_2 -> V_59 -> V_60 , V_2 -> V_37 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 )
F_23 ( V_2 , & V_2 -> V_42 [ 2 ] ) ;
if ( V_2 -> V_16 )
F_24 ( V_2 -> V_16 , 24 ) ;
}
