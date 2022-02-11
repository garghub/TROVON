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
F_8 ( V_9 , L_1 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_9 ( struct V_8 * V_9 , unsigned V_16 , unsigned V_3 ,
unsigned V_17 )
{
int V_18 ;
unsigned V_19 ;
V_18 = F_5 ( V_9 ) ;
if ( V_18 < 0 )
return V_18 ;
V_19 = V_16 ;
V_19 |= F_4 ( V_3 ) ;
V_19 |= F_1 ( V_17 ) ;
F_10 ( V_19 , V_9 -> V_12 + V_20 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 , struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_17 )
{
struct V_25 * V_26 = V_9 -> V_27 ;
int V_3 = F_12 ( V_24 -> V_28 ) ;
int V_18 ;
int V_11 ;
F_10 ( 0 , V_9 -> V_12 + V_13 ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_29 ; ++ V_11 ) {
V_18 = F_9 ( V_9 , V_30 , V_3 , V_17 [ V_11 ] ) ;
if ( V_18 < 0 )
return V_18 ;
V_26 -> V_31 [ V_3 ] = V_17 [ V_11 ] ;
}
return V_24 -> V_29 ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_17 )
{
struct V_25 * V_26 = V_9 -> V_27 ;
int V_3 = F_12 ( V_24 -> V_28 ) ;
int V_11 ;
if ( V_26 -> V_31 [ V_3 ] < 0 ) {
F_8 ( V_9 ,
L_2 ) ;
return - V_15 ;
}
for ( V_11 = 0 ; V_11 < V_24 -> V_29 ; V_11 ++ )
V_17 [ V_11 ] = V_26 -> V_31 [ V_3 ] ;
return V_24 -> V_29 ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_17 )
{
struct V_25 * V_26 = V_9 -> V_27 ;
int V_3 = F_12 ( V_24 -> V_28 ) ;
int V_18 ;
int V_11 ;
F_10 ( 0 , V_9 -> V_12 + V_13 ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_29 ; ++ V_11 ) {
V_18 = F_9 ( V_9 , V_32 , V_3 , V_17 [ V_11 ] ) ;
if ( V_18 < 0 )
return V_18 ;
V_26 -> V_33 [ V_3 ] = V_17 [ V_11 ] ;
}
return V_24 -> V_29 ;
}
static int F_15 ( struct V_8 * V_9 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_17 )
{
struct V_25 * V_26 = V_9 -> V_27 ;
unsigned int V_3 = F_12 ( V_24 -> V_28 ) ;
int V_11 ;
if ( V_26 -> V_33 [ V_3 ] < 0 ) {
F_8 ( V_9 ,
L_2 ) ;
return - V_15 ;
}
for ( V_11 = 0 ; V_11 < V_24 -> V_29 ; V_11 ++ )
V_17 [ V_11 ] = V_26 -> V_33 [ V_3 ] ;
return V_24 -> V_29 ;
}
static int F_16 ( struct V_8 * V_9 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_17 )
{
struct V_25 * V_26 = V_9 -> V_27 ;
int V_3 = F_12 ( V_24 -> V_28 ) ;
int V_18 ;
int V_11 ;
F_10 ( 0 , V_9 -> V_12 + V_13 ) ;
for ( V_11 = 0 ; V_11 < V_24 -> V_29 ; ++ V_11 ) {
V_18 = F_9 ( V_9 , V_34 , V_3 , V_17 [ V_11 ] ) ;
if ( V_18 < 0 )
return V_18 ;
V_26 -> V_35 [ V_3 ] = V_17 [ V_11 ] ;
}
return V_24 -> V_29 ;
}
static int F_17 ( struct V_8 * V_9 ,
struct V_21 * V_22 , struct V_23 * V_24 ,
unsigned int * V_17 )
{
struct V_25 * V_26 = V_9 -> V_27 ;
unsigned int V_3 = F_12 ( V_24 -> V_28 ) ;
int V_11 ;
if ( V_26 -> V_35 [ V_3 ] < 0 ) {
F_8 ( V_9 ,
L_2 ) ;
return - V_15 ;
}
for ( V_11 = 0 ; V_11 < V_24 -> V_29 ; V_11 ++ )
V_17 [ V_11 ] = V_26 -> V_35 [ V_3 ] ;
return V_24 -> V_29 ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_21 * V_22 ;
int V_36 ;
V_36 = F_19 ( V_9 , 3 ) ;
if ( V_36 )
return V_36 ;
V_22 = & V_9 -> V_37 [ 0 ] ;
V_22 -> type = V_38 ;
V_22 -> V_39 = V_40 | V_41 | V_42 ;
V_22 -> V_43 = V_44 ;
V_22 -> V_45 = 0x3fff ;
V_22 -> V_46 = V_47 ;
V_22 -> V_48 = F_13 ;
V_22 -> V_49 = F_11 ;
V_22 = & V_9 -> V_37 [ 1 ] ;
V_22 -> type = V_50 ;
V_22 -> V_39 = V_40 | V_41 | V_51 ;
V_22 -> V_43 = V_44 ;
V_22 -> V_48 = F_15 ;
V_22 -> V_49 = F_14 ;
V_22 -> V_45 = 0x3fff ;
V_22 = & V_9 -> V_37 [ 2 ] ;
V_22 -> type = V_50 ;
V_22 -> V_39 = V_40 | V_41 | V_51 ;
V_22 -> V_43 = V_44 ;
V_22 -> V_48 = F_17 ;
V_22 -> V_49 = F_16 ;
V_22 -> V_45 = 0x3fff ;
return 0 ;
}
static int F_20 ( struct V_8 * V_9 ,
unsigned long V_52 )
{
struct V_53 * V_54 = F_21 ( V_9 ) ;
struct V_25 * V_26 ;
int V_11 ;
int V_18 ;
unsigned int V_55 ;
V_26 = F_22 ( sizeof( * V_26 ) , V_56 ) ;
if ( ! V_26 )
return - V_57 ;
V_9 -> V_27 = V_26 ;
for ( V_11 = 0 ; V_11 < V_44 ; ++ V_11 ) {
V_26 -> V_31 [ V_11 ] = - 1 ;
V_26 -> V_33 [ V_11 ] = - 1 ;
V_26 -> V_35 [ V_11 ] = - 1 ;
}
V_18 = F_23 ( V_9 ) ;
if ( V_18 )
return V_18 ;
V_9 -> V_12 = F_24 ( V_54 , 2 ) ;
V_55 = F_6 ( V_9 -> V_12 + V_58 ) & V_59 ;
F_25 ( V_9 -> V_60 , L_3 , V_55 ) ;
V_18 = F_18 ( V_9 ) ;
if ( V_18 < 0 )
return V_18 ;
F_25 ( V_9 -> V_60 , L_4 ,
V_9 -> V_61 , F_26 ( V_54 ) , V_55 ) ;
return 0 ;
}
static int F_27 ( struct V_53 * V_9 ,
const struct V_62 * V_63 )
{
return F_28 ( V_9 , & V_64 ,
V_63 -> V_65 ) ;
}
