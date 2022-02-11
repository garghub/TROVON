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
static inline struct V_15 * F_13 ( struct V_1 * V_1 )
{
return V_1 -> V_16 ;
}
static inline struct V_17 * F_14 ( struct V_1 * V_1 )
{
return F_13 ( V_1 ) -> V_18 ;
}
static long F_15 ( struct V_1 * V_1 , unsigned long V_19 )
{
return F_16 ( V_1 , V_1 -> V_20 , V_19 ) ;
}
static unsigned long F_17 ( struct V_1 * V_1 )
{
struct V_17 * V_21 = F_14 ( V_1 ) ;
unsigned int V_22 ;
F_18 ( V_1 , V_1 -> V_20 , V_21 -> V_23 ,
V_21 , V_1 -> V_24 ? & V_1 -> V_24 : NULL ) ;
V_22 = ( F_1 ( V_1 ) >> V_1 -> V_7 ) & V_1 -> V_25 ;
return V_1 -> V_20 [ V_22 ] . V_26 ;
}
static int F_19 ( struct V_1 * V_1 , unsigned long V_19 )
{
struct V_15 * V_27 = F_13 ( V_1 ) ;
unsigned long V_6 ;
int V_22 ;
V_22 = F_20 ( V_1 , V_1 -> V_20 , V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
V_6 = F_1 ( V_1 ) ;
V_6 &= ~ ( V_1 -> V_25 << V_1 -> V_7 ) ;
V_6 |= ( V_22 << V_1 -> V_7 ) ;
F_5 ( V_6 , V_1 ) ;
if ( V_27 -> V_28 )
V_27 -> V_28 ( V_1 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
if ( V_1 -> V_25 == V_29 ) {
int V_11 = F_19 ( V_1 , V_1 -> V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
}
F_5 ( F_1 ( V_1 ) & ~ V_30 , V_1 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_1 )
{
unsigned int V_31 ;
V_31 = F_1 ( V_1 ) ;
V_31 |= V_30 ;
if ( V_1 -> V_2 & V_32 )
V_31 |= V_1 -> V_25 ;
F_5 ( V_31 , V_1 ) ;
}
static int T_1 F_23 ( struct V_1 * V_1 )
{
T_2 V_31 ;
if ( V_1 -> V_33 )
return 0 ;
if ( ! V_1 -> V_34 || ! V_1 -> V_35 )
return 0 ;
if ( ! V_1 -> V_36 ) {
F_24 ( L_1 ) ;
return - V_37 ;
}
V_31 = ( F_1 ( V_1 ) >> V_1 -> V_38 ) ;
V_31 &= ( 1 << V_1 -> V_36 ) - 1 ;
if ( V_31 >= V_1 -> V_35 ) {
F_24 ( L_2 ) ;
return - V_37 ;
}
F_25 ( V_1 , V_1 -> V_34 [ V_31 ] ) ;
if ( ! V_1 -> V_33 ) {
F_24 ( L_3 ) ;
return - V_37 ;
}
return 0 ;
}
static int T_1 F_26 ( struct V_1 * V_8 , int V_9 ,
struct V_15 * V_21 , struct V_39 * V_13 )
{
struct V_1 * V_10 ;
void * V_20 ;
int V_40 = V_21 -> V_18 -> V_23 ;
int V_41 = sizeof( struct V_42 ) ;
int V_11 = 0 ;
int V_12 ;
V_41 *= ( V_40 + 1 ) ;
V_20 = F_27 ( V_41 * V_9 , V_43 ) ;
if ( ! V_20 ) {
F_24 ( L_4 , V_44 ) ;
return - V_45 ;
}
for ( V_12 = 0 ; ! V_11 && ( V_12 < V_9 ) ; V_12 ++ ) {
V_10 = V_8 + V_12 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_16 = V_21 ;
V_10 -> V_20 = V_20 + ( V_12 * V_41 ) ;
V_10 -> V_20 [ V_40 ] . V_26 = V_46 ;
V_11 = F_12 ( V_10 ) ;
if ( V_11 == 0 )
V_11 = F_23 ( V_10 ) ;
}
return V_11 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_1 * V_33 )
{
struct V_17 * V_21 = F_14 ( V_1 ) ;
T_2 V_6 ;
int V_11 , V_47 ;
if ( ! V_1 -> V_34 || ! V_1 -> V_35 )
return - V_37 ;
for ( V_47 = 0 ; V_47 < V_1 -> V_35 ; V_47 ++ )
if ( V_1 -> V_34 [ V_47 ] == V_33 )
break;
if ( V_47 == V_1 -> V_35 )
return - V_48 ;
V_11 = F_25 ( V_1 , V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
V_6 = F_1 ( V_1 ) &
~ ( ( ( 1 << V_1 -> V_36 ) - 1 ) << V_1 -> V_38 ) ;
F_5 ( V_6 | ( V_47 << V_1 -> V_38 ) , V_1 ) ;
F_18 ( V_1 , V_1 -> V_20 , V_21 -> V_23 ,
V_21 , NULL ) ;
return 0 ;
}
int T_1 F_29 ( struct V_1 * V_8 , int V_9 )
{
return F_26 ( V_8 , V_9 , & V_49 ,
& V_50 ) ;
}
int T_1 F_30 ( struct V_1 * V_8 , int V_9 )
{
return F_26 ( V_8 , V_9 , & V_49 ,
& V_51 ) ;
}
static int F_31 ( struct V_1 * V_1 , struct V_1 * V_33 )
{
struct V_17 * V_21 = F_14 ( V_1 ) ;
T_2 V_6 ;
int V_11 ;
if ( V_33 -> V_2 & V_52 )
V_6 = F_1 ( V_1 ) & ~ ( 1 << 7 ) ;
else
V_6 = F_1 ( V_1 ) | ( 1 << 7 ) ;
V_11 = F_25 ( V_1 , V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
F_5 ( V_6 , V_1 ) ;
F_18 ( V_1 , V_1 -> V_20 , V_21 -> V_23 ,
V_21 , & V_1 -> V_24 ) ;
return 0 ;
}
int T_1 F_32 ( struct V_1 * V_8 , int V_9 ,
struct V_53 * V_21 )
{
return F_26 ( V_8 , V_9 , V_21 , & V_54 ) ;
}
int T_1 F_33 ( struct V_1 * V_8 , int V_9 ,
struct V_53 * V_21 )
{
return F_26 ( V_8 , V_9 , V_21 ,
& V_50 ) ;
}
int T_1 F_34 ( struct V_1 * V_8 , int V_9 ,
struct V_53 * V_21 )
{
return F_26 ( V_8 , V_9 , V_21 ,
& V_55 ) ;
}
static unsigned long F_35 ( struct V_1 * V_1 )
{
T_2 V_6 ;
V_6 = F_36 ( V_1 -> V_56 -> V_57 ) ;
V_6 >>= 16 ;
if ( V_6 < 2 )
return V_1 -> V_33 -> V_19 ;
return V_1 -> V_33 -> V_19 / V_6 ;
}
static long F_37 ( struct V_1 * V_1 , unsigned long V_19 )
{
return F_38 ( V_1 , 1 , 0xffff , V_19 ) ;
}
static void F_39 ( struct V_1 * V_1 )
{
F_40 ( 0 , V_1 -> V_56 -> V_57 ) ;
}
static int F_41 ( struct V_1 * V_1 )
{
T_2 V_6 ;
V_6 = F_36 ( V_1 -> V_56 -> V_57 ) >> 16 ;
if ( V_6 < 2 )
return 0 ;
F_40 ( ( V_6 << 16 ) | 0x3 , V_1 -> V_56 -> V_57 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_1 , unsigned long V_19 )
{
int V_22 ;
V_22 = ( V_1 -> V_33 -> V_19 / V_19 ) & 0xffff ;
if ( V_22 < 2 )
F_40 ( 0 , V_1 -> V_56 -> V_57 ) ;
else
F_40 ( V_22 << 16 , V_1 -> V_56 -> V_57 ) ;
return 0 ;
}
int T_1 F_43 ( struct V_1 * V_8 , int V_9 )
{
struct V_58 * V_59 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_9 ; V_47 ++ ) {
V_59 = F_27 ( sizeof( struct V_58 ) , V_43 ) ;
if ( ! V_59 ) {
F_24 ( L_4 , V_44 ) ;
return - V_45 ;
}
V_59 -> V_60 = ( V_61 ) V_8 [ V_47 ] . V_62 ;
V_59 -> V_63 = 8 ;
V_8 [ V_47 ] . V_62 = 0 ;
V_8 [ V_47 ] . V_13 = & V_64 ;
V_8 [ V_47 ] . V_56 = V_59 ;
F_12 ( & V_8 [ V_47 ] ) ;
}
return 0 ;
}
