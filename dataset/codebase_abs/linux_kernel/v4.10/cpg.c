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
static unsigned int F_9 ( const void T_1 * V_7 )
{
return F_2 ( V_7 ) ;
}
static unsigned int F_10 ( const void T_1 * V_7 )
{
return F_3 ( V_7 ) ;
}
static unsigned int F_11 ( const void T_1 * V_7 )
{
return F_4 ( V_7 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
F_5 ( F_1 ( V_1 ) & ~ ( 1 << V_1 -> V_8 ) , V_1 ) ;
if ( V_1 -> V_9 ) {
unsigned int ( * V_10 ) ( const void T_1 * V_7 ) ;
int V_11 ;
void T_1 * V_12 = ( V_13 ) V_1 -> V_9 -
( V_13 ) V_1 -> V_14 + V_1 -> V_4 ;
if ( V_1 -> V_2 & V_3 )
V_10 = F_9 ;
else if ( V_1 -> V_2 & V_5 )
V_10 = F_10 ;
else
V_10 = F_11 ;
for ( V_11 = 1000 ;
( V_10 ( V_12 ) & ( 1 << V_1 -> V_8 ) ) && V_11 ;
V_11 -- )
F_13 () ;
if ( ! V_11 ) {
F_14 ( L_1 ,
V_1 -> V_14 , V_1 -> V_8 ) ;
return - V_15 ;
}
}
return 0 ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_5 ( F_1 ( V_1 ) | ( 1 << V_1 -> V_8 ) , V_1 ) ;
}
int T_2 F_16 ( struct V_1 * V_16 , int V_17 )
{
struct V_1 * V_18 ;
int V_19 = 0 ;
int V_20 ;
for ( V_20 = 0 ; ! V_19 && ( V_20 < V_17 ) ; V_20 ++ ) {
V_18 = V_16 + V_20 ;
V_18 -> V_21 = & V_22 ;
V_19 |= F_17 ( V_18 ) ;
}
return V_19 ;
}
static inline struct V_23 * F_18 ( struct V_1 * V_1 )
{
return V_1 -> V_24 ;
}
static inline struct V_25 * F_19 ( struct V_1 * V_1 )
{
return F_18 ( V_1 ) -> V_26 ;
}
static long F_20 ( struct V_1 * V_1 , unsigned long V_27 )
{
return F_21 ( V_1 , V_1 -> V_28 , V_27 ) ;
}
static unsigned long F_22 ( struct V_1 * V_1 )
{
struct V_25 * V_29 = F_19 ( V_1 ) ;
unsigned int V_30 ;
F_23 ( V_1 , V_1 -> V_28 , V_29 -> V_31 ,
V_29 , V_1 -> V_32 ? & V_1 -> V_32 : NULL ) ;
V_30 = ( F_1 ( V_1 ) >> V_1 -> V_8 ) & V_1 -> V_33 ;
return V_1 -> V_28 [ V_30 ] . V_34 ;
}
static int F_24 ( struct V_1 * V_1 , unsigned long V_27 )
{
struct V_23 * V_35 = F_18 ( V_1 ) ;
unsigned long V_6 ;
int V_30 ;
V_30 = F_25 ( V_1 , V_1 -> V_28 , V_27 ) ;
if ( V_30 < 0 )
return V_30 ;
V_6 = F_1 ( V_1 ) ;
V_6 &= ~ ( V_1 -> V_33 << V_1 -> V_8 ) ;
V_6 |= ( V_30 << V_1 -> V_8 ) ;
F_5 ( V_6 , V_1 ) ;
if ( V_35 -> V_36 )
V_35 -> V_36 ( V_1 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 )
{
if ( V_1 -> V_33 == V_37 ) {
int V_19 = F_24 ( V_1 , V_1 -> V_27 ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_5 ( F_1 ( V_1 ) & ~ V_38 , V_1 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_1 )
{
unsigned int V_39 ;
V_39 = F_1 ( V_1 ) ;
V_39 |= V_38 ;
if ( V_1 -> V_2 & V_40 )
V_39 |= V_1 -> V_33 ;
F_5 ( V_39 , V_1 ) ;
}
static int T_2 F_28 ( struct V_1 * V_1 )
{
T_3 V_39 ;
if ( V_1 -> V_41 )
return 0 ;
if ( ! V_1 -> V_42 || ! V_1 -> V_43 )
return 0 ;
if ( ! V_1 -> V_44 ) {
F_14 ( L_2 ) ;
return - V_45 ;
}
V_39 = ( F_1 ( V_1 ) >> V_1 -> V_46 ) ;
V_39 &= ( 1 << V_1 -> V_44 ) - 1 ;
if ( V_39 >= V_1 -> V_43 ) {
F_14 ( L_3 ) ;
return - V_45 ;
}
F_29 ( V_1 , V_1 -> V_42 [ V_39 ] ) ;
if ( ! V_1 -> V_41 ) {
F_14 ( L_4 ) ;
return - V_45 ;
}
return 0 ;
}
static int T_2 F_30 ( struct V_1 * V_16 , int V_17 ,
struct V_23 * V_29 , struct V_47 * V_21 )
{
struct V_1 * V_18 ;
void * V_28 ;
int V_48 = V_29 -> V_26 -> V_31 ;
int V_49 = sizeof( struct V_50 ) ;
int V_19 = 0 ;
int V_20 ;
V_49 *= ( V_48 + 1 ) ;
V_28 = F_31 ( V_49 * V_17 , V_51 ) ;
if ( ! V_28 ) {
F_14 ( L_5 , V_52 ) ;
return - V_53 ;
}
for ( V_20 = 0 ; ! V_19 && ( V_20 < V_17 ) ; V_20 ++ ) {
V_18 = V_16 + V_20 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_24 = V_29 ;
V_18 -> V_28 = V_28 + ( V_20 * V_49 ) ;
V_18 -> V_28 [ V_48 ] . V_34 = V_54 ;
V_19 = F_17 ( V_18 ) ;
if ( V_19 == 0 )
V_19 = F_28 ( V_18 ) ;
}
return V_19 ;
}
static int F_32 ( struct V_1 * V_1 , struct V_1 * V_41 )
{
struct V_25 * V_29 = F_19 ( V_1 ) ;
T_3 V_6 ;
int V_19 , V_11 ;
if ( ! V_1 -> V_42 || ! V_1 -> V_43 )
return - V_45 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_43 ; V_11 ++ )
if ( V_1 -> V_42 [ V_11 ] == V_41 )
break;
if ( V_11 == V_1 -> V_43 )
return - V_55 ;
V_19 = F_29 ( V_1 , V_41 ) ;
if ( V_19 < 0 )
return V_19 ;
V_6 = F_1 ( V_1 ) &
~ ( ( ( 1 << V_1 -> V_44 ) - 1 ) << V_1 -> V_46 ) ;
F_5 ( V_6 | ( V_11 << V_1 -> V_46 ) , V_1 ) ;
F_23 ( V_1 , V_1 -> V_28 , V_29 -> V_31 ,
V_29 , NULL ) ;
return 0 ;
}
int T_2 F_33 ( struct V_1 * V_16 , int V_17 )
{
return F_30 ( V_16 , V_17 , & V_56 ,
& V_57 ) ;
}
int T_2 F_34 ( struct V_1 * V_16 , int V_17 )
{
return F_30 ( V_16 , V_17 , & V_56 ,
& V_58 ) ;
}
static int F_35 ( struct V_1 * V_1 , struct V_1 * V_41 )
{
struct V_25 * V_29 = F_19 ( V_1 ) ;
T_3 V_6 ;
int V_19 ;
if ( V_41 -> V_2 & V_59 )
V_6 = F_1 ( V_1 ) & ~ ( 1 << 7 ) ;
else
V_6 = F_1 ( V_1 ) | ( 1 << 7 ) ;
V_19 = F_29 ( V_1 , V_41 ) ;
if ( V_19 < 0 )
return V_19 ;
F_5 ( V_6 , V_1 ) ;
F_23 ( V_1 , V_1 -> V_28 , V_29 -> V_31 ,
V_29 , & V_1 -> V_32 ) ;
return 0 ;
}
int T_2 F_36 ( struct V_1 * V_16 , int V_17 ,
struct V_60 * V_29 )
{
return F_30 ( V_16 , V_17 , V_29 , & V_61 ) ;
}
int T_2 F_37 ( struct V_1 * V_16 , int V_17 ,
struct V_60 * V_29 )
{
return F_30 ( V_16 , V_17 , V_29 ,
& V_57 ) ;
}
int T_2 F_38 ( struct V_1 * V_16 , int V_17 ,
struct V_60 * V_29 )
{
return F_30 ( V_16 , V_17 , V_29 ,
& V_62 ) ;
}
static unsigned long F_39 ( struct V_1 * V_1 )
{
T_3 V_6 ;
V_6 = F_40 ( V_1 -> V_63 -> V_64 ) ;
V_6 >>= 16 ;
if ( V_6 < 2 )
return V_1 -> V_41 -> V_27 ;
return V_1 -> V_41 -> V_27 / V_6 ;
}
static long F_41 ( struct V_1 * V_1 , unsigned long V_27 )
{
return F_42 ( V_1 , 1 , 0xffff , V_27 ) ;
}
static void F_43 ( struct V_1 * V_1 )
{
F_44 ( 0 , V_1 -> V_63 -> V_64 ) ;
}
static int F_45 ( struct V_1 * V_1 )
{
T_3 V_6 ;
V_6 = F_40 ( V_1 -> V_63 -> V_64 ) >> 16 ;
if ( V_6 < 2 )
return 0 ;
F_44 ( ( V_6 << 16 ) | 0x3 , V_1 -> V_63 -> V_64 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 , unsigned long V_27 )
{
int V_30 ;
V_30 = ( V_1 -> V_41 -> V_27 / V_27 ) & 0xffff ;
if ( V_30 < 2 )
F_44 ( 0 , V_1 -> V_63 -> V_64 ) ;
else
F_44 ( V_30 << 16 , V_1 -> V_63 -> V_64 ) ;
return 0 ;
}
int T_2 F_47 ( struct V_1 * V_16 , int V_17 )
{
struct V_65 * V_66 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_17 ; V_11 ++ ) {
V_66 = F_31 ( sizeof( struct V_65 ) , V_51 ) ;
if ( ! V_66 ) {
F_14 ( L_5 , V_52 ) ;
return - V_53 ;
}
V_66 -> V_67 = ( V_13 ) V_16 [ V_11 ] . V_14 ;
V_66 -> V_68 = 8 ;
V_16 [ V_11 ] . V_14 = 0 ;
V_16 [ V_11 ] . V_21 = & V_69 ;
V_16 [ V_11 ] . V_63 = V_66 ;
F_17 ( & V_16 [ V_11 ] ) ;
}
return 0 ;
}
