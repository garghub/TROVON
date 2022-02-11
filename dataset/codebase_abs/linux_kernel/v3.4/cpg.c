static int F_1 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 -> V_2 ) & ~ ( 1 << V_1 -> V_3 ) ,
V_1 -> V_2 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 -> V_2 ) | ( 1 << V_1 -> V_3 ) ,
V_1 -> V_2 ) ;
}
int T_1 F_5 ( struct V_1 * V_4 , int V_5 )
{
struct V_1 * V_6 ;
int V_7 = 0 ;
int V_8 ;
for ( V_8 = 0 ; ! V_7 && ( V_8 < V_5 ) ; V_8 ++ ) {
V_6 = V_4 + V_8 ;
V_6 -> V_9 = & V_10 ;
V_7 |= F_6 ( V_6 ) ;
}
return V_7 ;
}
static long F_7 ( struct V_1 * V_1 , unsigned long V_11 )
{
return F_8 ( V_1 , V_1 -> V_12 , V_11 ) ;
}
static unsigned long F_9 ( struct V_1 * V_1 )
{
struct V_13 * V_14 = & V_15 ;
unsigned int V_16 ;
F_10 ( V_1 , V_1 -> V_12 , V_14 -> V_17 ,
V_14 , NULL ) ;
V_16 = F_3 ( V_1 -> V_2 ) & 0x003f ;
return V_1 -> V_12 [ V_16 ] . V_18 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_1 * V_19 )
{
struct V_13 * V_14 = & V_15 ;
T_2 V_20 ;
int V_7 , V_21 ;
if ( ! V_1 -> V_22 || ! V_1 -> V_23 )
return - V_24 ;
for ( V_21 = 0 ; V_21 < V_1 -> V_23 ; V_21 ++ )
if ( V_1 -> V_22 [ V_21 ] == V_19 )
break;
if ( V_21 == V_1 -> V_23 )
return - V_25 ;
V_7 = F_12 ( V_1 , V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
V_20 = F_3 ( V_1 -> V_2 ) &
~ ( ( ( 1 << V_1 -> V_26 ) - 1 ) << V_1 -> V_27 ) ;
F_2 ( V_20 | ( V_21 << V_1 -> V_27 ) , V_1 -> V_2 ) ;
F_10 ( V_1 , V_1 -> V_12 , V_14 -> V_17 ,
V_14 , NULL ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , unsigned long V_11 )
{
unsigned long V_20 ;
int V_16 ;
V_16 = F_14 ( V_1 , V_1 -> V_12 , V_11 ) ;
if ( V_16 < 0 )
return V_16 ;
V_20 = F_3 ( V_1 -> V_2 ) ;
V_20 &= ~ 0x3f ;
V_20 |= V_16 ;
F_2 ( V_20 , V_1 -> V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
unsigned long V_20 ;
int V_7 ;
V_7 = F_13 ( V_1 , V_1 -> V_11 ) ;
if ( V_7 == 0 ) {
V_20 = F_3 ( V_1 -> V_2 ) ;
V_20 &= ~ 0x100 ;
F_2 ( V_20 , V_1 -> V_2 ) ;
}
return V_7 ;
}
static void F_16 ( struct V_1 * V_1 )
{
unsigned long V_20 ;
V_20 = F_3 ( V_1 -> V_2 ) ;
V_20 |= 0x100 ;
V_20 |= 0x3f ;
F_2 ( V_20 , V_1 -> V_2 ) ;
}
static int T_1 F_17 ( struct V_1 * V_1 )
{
T_2 V_28 ;
if ( V_1 -> V_19 )
return 0 ;
if ( ! V_1 -> V_22 || ! V_1 -> V_23 )
return 0 ;
if ( ! V_1 -> V_26 ) {
F_18 ( L_1 ) ;
return - V_24 ;
}
V_28 = ( F_3 ( V_1 -> V_2 ) >> V_1 -> V_27 ) ;
V_28 &= ( 1 << V_1 -> V_26 ) - 1 ;
if ( V_28 >= V_1 -> V_23 ) {
F_18 ( L_2 ) ;
return - V_24 ;
}
F_12 ( V_1 , V_1 -> V_22 [ V_28 ] ) ;
if ( ! V_1 -> V_19 ) {
F_18 ( L_3 ) ;
return - V_24 ;
}
return 0 ;
}
static int T_1 F_19 ( struct V_1 * V_4 , int V_5 ,
struct V_29 * V_9 )
{
struct V_1 * V_6 ;
void * V_12 ;
int V_30 = V_15 . V_17 ;
int V_31 = sizeof( struct V_32 ) ;
int V_7 = 0 ;
int V_8 ;
V_31 *= ( V_30 + 1 ) ;
V_12 = F_20 ( V_31 * V_5 , V_33 ) ;
if ( ! V_12 ) {
F_18 ( L_4 ) ;
return - V_34 ;
}
for ( V_8 = 0 ; ! V_7 && ( V_8 < V_5 ) ; V_8 ++ ) {
V_6 = V_4 + V_8 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_12 = V_12 + ( V_8 * V_31 ) ;
V_6 -> V_12 [ V_30 ] . V_18 = V_35 ;
V_7 = F_6 ( V_6 ) ;
if ( V_7 < 0 )
break;
V_7 = F_17 ( V_6 ) ;
}
return V_7 ;
}
int T_1 F_21 ( struct V_1 * V_4 , int V_5 )
{
return F_19 ( V_4 , V_5 , & V_36 ) ;
}
int T_1 F_22 ( struct V_1 * V_4 , int V_5 )
{
return F_19 ( V_4 , V_5 ,
& V_37 ) ;
}
static unsigned long F_23 ( struct V_1 * V_1 )
{
struct V_38 * V_39 = V_1 -> V_40 ;
struct V_13 * V_14 = V_39 -> V_41 ;
unsigned int V_16 ;
F_10 ( V_1 , V_1 -> V_12 , V_14 -> V_17 ,
V_14 , & V_1 -> V_42 ) ;
V_16 = ( F_3 ( V_1 -> V_2 ) >> V_1 -> V_3 ) & 0x000f ;
return V_1 -> V_12 [ V_16 ] . V_18 ;
}
static int F_24 ( struct V_1 * V_1 , struct V_1 * V_19 )
{
struct V_38 * V_39 = V_1 -> V_40 ;
struct V_13 * V_14 = V_39 -> V_41 ;
T_2 V_20 ;
int V_7 ;
if ( V_19 -> V_43 & V_44 )
V_20 = F_3 ( V_1 -> V_2 ) & ~ ( 1 << 7 ) ;
else
V_20 = F_3 ( V_1 -> V_2 ) | ( 1 << 7 ) ;
V_7 = F_12 ( V_1 , V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
F_2 ( V_20 , V_1 -> V_2 ) ;
F_10 ( V_1 , V_1 -> V_12 , V_14 -> V_17 ,
V_14 , & V_1 -> V_42 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 , unsigned long V_11 )
{
struct V_38 * V_39 = V_1 -> V_40 ;
unsigned long V_20 ;
int V_16 = F_14 ( V_1 , V_1 -> V_12 , V_11 ) ;
if ( V_16 < 0 )
return V_16 ;
V_20 = F_3 ( V_1 -> V_2 ) ;
V_20 &= ~ ( 0xf << V_1 -> V_3 ) ;
V_20 |= ( V_16 << V_1 -> V_3 ) ;
F_2 ( V_20 , V_1 -> V_2 ) ;
if ( V_39 -> V_45 )
V_39 -> V_45 ( V_1 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 -> V_2 ) & ~ ( 1 << 8 ) , V_1 -> V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 -> V_2 ) | ( 1 << 8 ) , V_1 -> V_2 ) ;
}
static int T_1 F_28 ( struct V_1 * V_4 , int V_5 ,
struct V_38 * V_14 , struct V_29 * V_9 )
{
struct V_1 * V_6 ;
void * V_12 ;
int V_30 = V_14 -> V_41 -> V_17 ;
int V_31 = sizeof( struct V_32 ) ;
int V_7 = 0 ;
int V_8 ;
V_31 *= ( V_30 + 1 ) ;
V_12 = F_20 ( V_31 * V_5 , V_33 ) ;
if ( ! V_12 ) {
F_18 ( L_5 ) ;
return - V_34 ;
}
for ( V_8 = 0 ; ! V_7 && ( V_8 < V_5 ) ; V_8 ++ ) {
V_6 = V_4 + V_8 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_40 = V_14 ;
V_6 -> V_12 = V_12 + ( V_8 * V_31 ) ;
V_6 -> V_12 [ V_30 ] . V_18 = V_35 ;
V_7 = F_6 ( V_6 ) ;
}
return V_7 ;
}
int T_1 F_29 ( struct V_1 * V_4 , int V_5 ,
struct V_38 * V_14 )
{
return F_28 ( V_4 , V_5 , V_14 , & V_46 ) ;
}
int T_1 F_30 ( struct V_1 * V_4 , int V_5 ,
struct V_38 * V_14 )
{
return F_28 ( V_4 , V_5 , V_14 ,
& V_47 ) ;
}
int T_1 F_31 ( struct V_1 * V_4 , int V_5 ,
struct V_38 * V_14 )
{
return F_28 ( V_4 , V_5 , V_14 ,
& V_48 ) ;
}
