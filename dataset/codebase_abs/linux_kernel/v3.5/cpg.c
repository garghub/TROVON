static unsigned int F_1 ( struct V_1 * V_1 )
{
if ( V_1 -> V_2 & V_3 )
return F_2 ( V_1 -> V_4 ) ;
else if ( V_1 -> V_2 & V_5 )
return F_3 ( V_1 -> V_4 ) ;
return F_4 ( V_1 -> V_4 ) ;
}
static void F_5 ( int V_6 , struct V_1 * V_1 )
{
if ( V_1 -> V_2 & V_3 )
F_6 ( V_6 , V_1 -> V_4 ) ;
else if ( V_1 -> V_2 & V_5 )
F_7 ( V_6 , V_1 -> V_4 ) ;
else
F_8 ( V_6 , V_1 -> V_4 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
F_5 ( F_1 ( V_1 ) & ~ ( 1 << V_1 -> V_7 ) , V_1 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_5 ( F_1 ( V_1 ) | ( 1 << V_1 -> V_7 ) , V_1 ) ;
}
int T_1 F_11 ( struct V_1 * V_8 , int V_9 )
{
struct V_1 * V_10 ;
int V_11 = 0 ;
int V_12 ;
for ( V_12 = 0 ; ! V_11 && ( V_12 < V_9 ) ; V_12 ++ ) {
V_10 = V_8 + V_12 ;
V_10 -> V_13 = & V_14 ;
V_11 |= F_12 ( V_10 ) ;
}
return V_11 ;
}
static long F_13 ( struct V_1 * V_1 , unsigned long V_15 )
{
return F_14 ( V_1 , V_1 -> V_16 , V_15 ) ;
}
static unsigned long F_15 ( struct V_1 * V_1 )
{
struct V_17 * V_18 = & V_19 ;
unsigned int V_20 ;
F_16 ( V_1 , V_1 -> V_16 , V_18 -> V_21 ,
V_18 , NULL ) ;
V_20 = F_1 ( V_1 ) & 0x003f ;
return V_1 -> V_16 [ V_20 ] . V_22 ;
}
static int F_17 ( struct V_1 * V_1 , struct V_1 * V_23 )
{
struct V_17 * V_18 = & V_19 ;
T_2 V_6 ;
int V_11 , V_24 ;
if ( ! V_1 -> V_25 || ! V_1 -> V_26 )
return - V_27 ;
for ( V_24 = 0 ; V_24 < V_1 -> V_26 ; V_24 ++ )
if ( V_1 -> V_25 [ V_24 ] == V_23 )
break;
if ( V_24 == V_1 -> V_26 )
return - V_28 ;
V_11 = F_18 ( V_1 , V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 = F_1 ( V_1 ) &
~ ( ( ( 1 << V_1 -> V_29 ) - 1 ) << V_1 -> V_30 ) ;
F_5 ( V_6 | ( V_24 << V_1 -> V_30 ) , V_1 ) ;
F_16 ( V_1 , V_1 -> V_16 , V_18 -> V_21 ,
V_18 , NULL ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 , unsigned long V_15 )
{
unsigned long V_6 ;
int V_20 ;
V_20 = F_20 ( V_1 , V_1 -> V_16 , V_15 ) ;
if ( V_20 < 0 )
return V_20 ;
V_6 = F_1 ( V_1 ) ;
V_6 &= ~ 0x3f ;
V_6 |= V_20 ;
F_5 ( V_6 , V_1 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
unsigned long V_6 ;
int V_11 ;
V_11 = F_19 ( V_1 , V_1 -> V_15 ) ;
if ( V_11 == 0 ) {
V_6 = F_1 ( V_1 ) ;
V_6 &= ~ 0x100 ;
F_5 ( V_6 , V_1 ) ;
}
return V_11 ;
}
static void F_22 ( struct V_1 * V_1 )
{
unsigned long V_6 ;
V_6 = F_1 ( V_1 ) ;
V_6 |= 0x100 ;
V_6 |= 0x3f ;
F_5 ( V_6 , V_1 ) ;
}
static int T_1 F_23 ( struct V_1 * V_1 )
{
T_2 V_31 ;
if ( V_1 -> V_23 )
return 0 ;
if ( ! V_1 -> V_25 || ! V_1 -> V_26 )
return 0 ;
if ( ! V_1 -> V_29 ) {
F_24 ( L_1 ) ;
return - V_27 ;
}
V_31 = ( F_1 ( V_1 ) >> V_1 -> V_30 ) ;
V_31 &= ( 1 << V_1 -> V_29 ) - 1 ;
if ( V_31 >= V_1 -> V_26 ) {
F_24 ( L_2 ) ;
return - V_27 ;
}
F_18 ( V_1 , V_1 -> V_25 [ V_31 ] ) ;
if ( ! V_1 -> V_23 ) {
F_24 ( L_3 ) ;
return - V_27 ;
}
return 0 ;
}
static int T_1 F_25 ( struct V_1 * V_8 , int V_9 ,
struct V_32 * V_13 )
{
struct V_1 * V_10 ;
void * V_16 ;
int V_33 = V_19 . V_21 ;
int V_34 = sizeof( struct V_35 ) ;
int V_11 = 0 ;
int V_12 ;
V_34 *= ( V_33 + 1 ) ;
V_16 = F_26 ( V_34 * V_9 , V_36 ) ;
if ( ! V_16 ) {
F_24 ( L_4 ) ;
return - V_37 ;
}
for ( V_12 = 0 ; ! V_11 && ( V_12 < V_9 ) ; V_12 ++ ) {
V_10 = V_8 + V_12 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_16 = V_16 + ( V_12 * V_34 ) ;
V_10 -> V_16 [ V_33 ] . V_22 = V_38 ;
V_11 = F_12 ( V_10 ) ;
if ( V_11 < 0 )
break;
V_11 = F_23 ( V_10 ) ;
}
return V_11 ;
}
int T_1 F_27 ( struct V_1 * V_8 , int V_9 )
{
return F_25 ( V_8 , V_9 , & V_39 ) ;
}
int T_1 F_28 ( struct V_1 * V_8 , int V_9 )
{
return F_25 ( V_8 , V_9 ,
& V_40 ) ;
}
static unsigned long F_29 ( struct V_1 * V_1 )
{
struct V_41 * V_42 = V_1 -> V_43 ;
struct V_17 * V_18 = V_42 -> V_44 ;
unsigned int V_20 ;
F_16 ( V_1 , V_1 -> V_16 , V_18 -> V_21 ,
V_18 , & V_1 -> V_45 ) ;
V_20 = ( F_1 ( V_1 ) >> V_1 -> V_7 ) & 0x000f ;
return V_1 -> V_16 [ V_20 ] . V_22 ;
}
static int F_30 ( struct V_1 * V_1 , struct V_1 * V_23 )
{
struct V_41 * V_42 = V_1 -> V_43 ;
struct V_17 * V_18 = V_42 -> V_44 ;
T_2 V_6 ;
int V_11 ;
if ( V_23 -> V_2 & V_46 )
V_6 = F_1 ( V_1 ) & ~ ( 1 << 7 ) ;
else
V_6 = F_1 ( V_1 ) | ( 1 << 7 ) ;
V_11 = F_18 ( V_1 , V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
F_5 ( V_6 , V_1 ) ;
F_16 ( V_1 , V_1 -> V_16 , V_18 -> V_21 ,
V_18 , & V_1 -> V_45 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , unsigned long V_15 )
{
struct V_41 * V_42 = V_1 -> V_43 ;
unsigned long V_6 ;
int V_20 = F_20 ( V_1 , V_1 -> V_16 , V_15 ) ;
if ( V_20 < 0 )
return V_20 ;
V_6 = F_1 ( V_1 ) ;
V_6 &= ~ ( 0xf << V_1 -> V_7 ) ;
V_6 |= ( V_20 << V_1 -> V_7 ) ;
F_5 ( V_6 , V_1 ) ;
if ( V_42 -> V_47 )
V_42 -> V_47 ( V_1 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 )
{
F_5 ( F_1 ( V_1 ) & ~ ( 1 << 8 ) , V_1 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_1 )
{
F_5 ( F_1 ( V_1 ) | ( 1 << 8 ) , V_1 ) ;
}
static int T_1 F_34 ( struct V_1 * V_8 , int V_9 ,
struct V_41 * V_18 , struct V_32 * V_13 )
{
struct V_1 * V_10 ;
void * V_16 ;
int V_33 = V_18 -> V_44 -> V_21 ;
int V_34 = sizeof( struct V_35 ) ;
int V_11 = 0 ;
int V_12 ;
V_34 *= ( V_33 + 1 ) ;
V_16 = F_26 ( V_34 * V_9 , V_36 ) ;
if ( ! V_16 ) {
F_24 ( L_5 ) ;
return - V_37 ;
}
for ( V_12 = 0 ; ! V_11 && ( V_12 < V_9 ) ; V_12 ++ ) {
V_10 = V_8 + V_12 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_43 = V_18 ;
V_10 -> V_16 = V_16 + ( V_12 * V_34 ) ;
V_10 -> V_16 [ V_33 ] . V_22 = V_38 ;
V_11 = F_12 ( V_10 ) ;
}
return V_11 ;
}
int T_1 F_35 ( struct V_1 * V_8 , int V_9 ,
struct V_41 * V_18 )
{
return F_34 ( V_8 , V_9 , V_18 , & V_48 ) ;
}
int T_1 F_36 ( struct V_1 * V_8 , int V_9 ,
struct V_41 * V_18 )
{
return F_34 ( V_8 , V_9 , V_18 ,
& V_49 ) ;
}
int T_1 F_37 ( struct V_1 * V_8 , int V_9 ,
struct V_41 * V_18 )
{
return F_34 ( V_8 , V_9 , V_18 ,
& V_50 ) ;
}
