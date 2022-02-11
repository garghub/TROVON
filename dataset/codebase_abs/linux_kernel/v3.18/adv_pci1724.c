static T_1 F_1 ( T_2 V_1 )
{
return V_1 & V_2 ;
}
static T_1 F_2 ( unsigned V_3 )
{
return ( V_3 << 16 ) & V_4 ;
}
static T_1 F_3 ( unsigned V_5 )
{
return ( 1 << ( 20 + V_5 ) ) & V_6 ;
}
static T_1 F_4 ( unsigned V_7 )
{
return F_2 ( V_7 % 8 ) |
F_3 ( V_7 / 8 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
static const int V_10 = 10000 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; ++ V_11 ) {
if ( ( F_6 ( V_9 -> V_12 + V_13 ) & V_14 ) == 0 )
break;
F_7 ( 1 ) ;
}
if ( V_11 == V_10 ) {
F_8 ( V_9 -> V_15 ,
L_1 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_9 ( struct V_8 * V_9 , unsigned V_17 , unsigned V_3 ,
unsigned V_18 )
{
int V_19 ;
unsigned V_20 ;
V_19 = F_5 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
V_20 = V_17 ;
V_20 |= F_4 ( V_3 ) ;
V_20 |= F_1 ( V_18 ) ;
F_10 ( V_20 , V_9 -> V_12 + V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 , struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_18 )
{
struct V_26 * V_27 = V_9 -> V_28 ;
int V_3 = F_12 ( V_25 -> V_29 ) ;
int V_19 ;
int V_11 ;
F_10 ( 0 , V_9 -> V_12 + V_13 ) ;
for ( V_11 = 0 ; V_11 < V_25 -> V_30 ; ++ V_11 ) {
V_19 = F_9 ( V_9 , V_31 , V_3 , V_18 [ V_11 ] ) ;
if ( V_19 < 0 )
return V_19 ;
V_27 -> V_32 [ V_3 ] = V_18 [ V_11 ] ;
}
return V_25 -> V_30 ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_18 )
{
struct V_26 * V_27 = V_9 -> V_28 ;
int V_3 = F_12 ( V_25 -> V_29 ) ;
int V_11 ;
if ( V_27 -> V_32 [ V_3 ] < 0 ) {
F_8 ( V_9 -> V_15 ,
L_2 ) ;
return - V_16 ;
}
for ( V_11 = 0 ; V_11 < V_25 -> V_30 ; V_11 ++ )
V_18 [ V_11 ] = V_27 -> V_32 [ V_3 ] ;
return V_25 -> V_30 ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_18 )
{
struct V_26 * V_27 = V_9 -> V_28 ;
int V_3 = F_12 ( V_25 -> V_29 ) ;
int V_19 ;
int V_11 ;
F_10 ( 0 , V_9 -> V_12 + V_13 ) ;
for ( V_11 = 0 ; V_11 < V_25 -> V_30 ; ++ V_11 ) {
V_19 = F_9 ( V_9 , V_33 , V_3 , V_18 [ V_11 ] ) ;
if ( V_19 < 0 )
return V_19 ;
V_27 -> V_34 [ V_3 ] = V_18 [ V_11 ] ;
}
return V_25 -> V_30 ;
}
static int F_15 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_18 )
{
struct V_26 * V_27 = V_9 -> V_28 ;
unsigned int V_3 = F_12 ( V_25 -> V_29 ) ;
int V_11 ;
if ( V_27 -> V_34 [ V_3 ] < 0 ) {
F_8 ( V_9 -> V_15 ,
L_2 ) ;
return - V_16 ;
}
for ( V_11 = 0 ; V_11 < V_25 -> V_30 ; V_11 ++ )
V_18 [ V_11 ] = V_27 -> V_34 [ V_3 ] ;
return V_25 -> V_30 ;
}
static int F_16 ( struct V_8 * V_9 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_18 )
{
struct V_26 * V_27 = V_9 -> V_28 ;
int V_3 = F_12 ( V_25 -> V_29 ) ;
int V_19 ;
int V_11 ;
F_10 ( 0 , V_9 -> V_12 + V_13 ) ;
for ( V_11 = 0 ; V_11 < V_25 -> V_30 ; ++ V_11 ) {
V_19 = F_9 ( V_9 , V_35 , V_3 , V_18 [ V_11 ] ) ;
if ( V_19 < 0 )
return V_19 ;
V_27 -> V_36 [ V_3 ] = V_18 [ V_11 ] ;
}
return V_25 -> V_30 ;
}
static int F_17 ( struct V_8 * V_9 ,
struct V_22 * V_23 , struct V_24 * V_25 ,
unsigned int * V_18 )
{
struct V_26 * V_27 = V_9 -> V_28 ;
unsigned int V_3 = F_12 ( V_25 -> V_29 ) ;
int V_11 ;
if ( V_27 -> V_36 [ V_3 ] < 0 ) {
F_8 ( V_9 -> V_15 ,
L_2 ) ;
return - V_16 ;
}
for ( V_11 = 0 ; V_11 < V_25 -> V_30 ; V_11 ++ )
V_18 [ V_11 ] = V_27 -> V_36 [ V_3 ] ;
return V_25 -> V_30 ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_22 * V_23 ;
int V_37 ;
V_37 = F_19 ( V_9 , 3 ) ;
if ( V_37 )
return V_37 ;
V_23 = & V_9 -> V_38 [ 0 ] ;
V_23 -> type = V_39 ;
V_23 -> V_40 = V_41 | V_42 | V_43 ;
V_23 -> V_44 = V_45 ;
V_23 -> V_46 = 0x3fff ;
V_23 -> V_47 = & V_48 ;
V_23 -> V_49 = F_13 ;
V_23 -> V_50 = F_11 ;
V_23 = & V_9 -> V_38 [ 1 ] ;
V_23 -> type = V_51 ;
V_23 -> V_40 = V_41 | V_42 | V_52 ;
V_23 -> V_44 = V_45 ;
V_23 -> V_49 = F_15 ;
V_23 -> V_50 = F_14 ;
V_23 -> V_46 = 0x3fff ;
V_23 = & V_9 -> V_38 [ 2 ] ;
V_23 -> type = V_51 ;
V_23 -> V_40 = V_41 | V_42 | V_52 ;
V_23 -> V_44 = V_45 ;
V_23 -> V_49 = F_17 ;
V_23 -> V_50 = F_16 ;
V_23 -> V_46 = 0x3fff ;
return 0 ;
}
static int F_20 ( struct V_8 * V_9 ,
unsigned long V_53 )
{
struct V_54 * V_55 = F_21 ( V_9 ) ;
struct V_26 * V_27 ;
int V_11 ;
int V_19 ;
unsigned int V_56 ;
V_27 = F_22 ( V_9 , sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_57 ;
for ( V_11 = 0 ; V_11 < V_45 ; ++ V_11 ) {
V_27 -> V_32 [ V_11 ] = - 1 ;
V_27 -> V_34 [ V_11 ] = - 1 ;
V_27 -> V_36 [ V_11 ] = - 1 ;
}
V_19 = F_23 ( V_9 ) ;
if ( V_19 )
return V_19 ;
V_9 -> V_12 = F_24 ( V_55 , 2 ) ;
V_56 = F_6 ( V_9 -> V_12 + V_58 ) & V_59 ;
F_25 ( V_9 -> V_15 , L_3 , V_56 ) ;
V_19 = F_18 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
F_25 ( V_9 -> V_15 , L_4 ,
V_9 -> V_60 , F_26 ( V_55 ) , V_56 ) ;
return 0 ;
}
static int F_27 ( struct V_54 * V_9 ,
const struct V_61 * V_62 )
{
return F_28 ( V_9 , & V_63 ,
V_62 -> V_64 ) ;
}
