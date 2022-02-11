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
static int T_1 F_17 ( struct V_1 * V_4 , int V_5 ,
struct V_28 * V_9 )
{
struct V_1 * V_6 ;
void * V_12 ;
int V_29 = V_15 . V_17 ;
int V_30 = sizeof( struct V_31 ) ;
int V_7 = 0 ;
int V_8 ;
V_30 *= ( V_29 + 1 ) ;
V_12 = F_18 ( V_30 * V_5 , V_32 ) ;
if ( ! V_12 ) {
F_19 ( L_1 ) ;
return - V_33 ;
}
for ( V_8 = 0 ; ! V_7 && ( V_8 < V_5 ) ; V_8 ++ ) {
V_6 = V_4 + V_8 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_12 = V_12 + ( V_8 * V_30 ) ;
V_6 -> V_12 [ V_29 ] . V_18 = V_34 ;
V_7 = F_6 ( V_6 ) ;
}
return V_7 ;
}
int T_1 F_20 ( struct V_1 * V_4 , int V_5 )
{
return F_17 ( V_4 , V_5 , & V_35 ) ;
}
int T_1 F_21 ( struct V_1 * V_4 , int V_5 )
{
return F_17 ( V_4 , V_5 ,
& V_36 ) ;
}
static unsigned long F_22 ( struct V_1 * V_1 )
{
struct V_37 * V_38 = V_1 -> V_39 ;
struct V_13 * V_14 = V_38 -> V_40 ;
unsigned int V_16 ;
F_10 ( V_1 , V_1 -> V_12 , V_14 -> V_17 ,
V_14 , & V_1 -> V_41 ) ;
V_16 = ( F_3 ( V_1 -> V_2 ) >> V_1 -> V_3 ) & 0x000f ;
return V_1 -> V_12 [ V_16 ] . V_18 ;
}
static int F_23 ( struct V_1 * V_1 , struct V_1 * V_19 )
{
struct V_37 * V_38 = V_1 -> V_39 ;
struct V_13 * V_14 = V_38 -> V_40 ;
T_2 V_20 ;
int V_7 ;
if ( V_19 -> V_42 & V_43 )
V_20 = F_3 ( V_1 -> V_2 ) & ~ ( 1 << 7 ) ;
else
V_20 = F_3 ( V_1 -> V_2 ) | ( 1 << 7 ) ;
V_7 = F_12 ( V_1 , V_19 ) ;
if ( V_7 < 0 )
return V_7 ;
F_2 ( V_20 , V_1 -> V_2 ) ;
F_10 ( V_1 , V_1 -> V_12 , V_14 -> V_17 ,
V_14 , & V_1 -> V_41 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , unsigned long V_11 )
{
struct V_37 * V_38 = V_1 -> V_39 ;
unsigned long V_20 ;
int V_16 = F_14 ( V_1 , V_1 -> V_12 , V_11 ) ;
if ( V_16 < 0 )
return V_16 ;
V_20 = F_3 ( V_1 -> V_2 ) ;
V_20 &= ~ ( 0xf << V_1 -> V_3 ) ;
V_20 |= ( V_16 << V_1 -> V_3 ) ;
F_2 ( V_20 , V_1 -> V_2 ) ;
if ( V_38 -> V_44 )
V_38 -> V_44 ( V_1 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 -> V_2 ) & ~ ( 1 << 8 ) , V_1 -> V_2 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( V_1 -> V_2 ) | ( 1 << 8 ) , V_1 -> V_2 ) ;
}
static int T_1 F_27 ( struct V_1 * V_4 , int V_5 ,
struct V_37 * V_14 , struct V_28 * V_9 )
{
struct V_1 * V_6 ;
void * V_12 ;
int V_29 = V_14 -> V_40 -> V_17 ;
int V_30 = sizeof( struct V_31 ) ;
int V_7 = 0 ;
int V_8 ;
V_30 *= ( V_29 + 1 ) ;
V_12 = F_18 ( V_30 * V_5 , V_32 ) ;
if ( ! V_12 ) {
F_19 ( L_2 ) ;
return - V_33 ;
}
for ( V_8 = 0 ; ! V_7 && ( V_8 < V_5 ) ; V_8 ++ ) {
V_6 = V_4 + V_8 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_39 = V_14 ;
V_6 -> V_12 = V_12 + ( V_8 * V_30 ) ;
V_6 -> V_12 [ V_29 ] . V_18 = V_34 ;
V_7 = F_6 ( V_6 ) ;
}
return V_7 ;
}
int T_1 F_28 ( struct V_1 * V_4 , int V_5 ,
struct V_37 * V_14 )
{
return F_27 ( V_4 , V_5 , V_14 , & V_45 ) ;
}
int T_1 F_29 ( struct V_1 * V_4 , int V_5 ,
struct V_37 * V_14 )
{
return F_27 ( V_4 , V_5 , V_14 ,
& V_46 ) ;
}
int T_1 F_30 ( struct V_1 * V_4 , int V_5 ,
struct V_37 * V_14 )
{
return F_27 ( V_4 , V_5 , V_14 ,
& V_47 ) ;
}
