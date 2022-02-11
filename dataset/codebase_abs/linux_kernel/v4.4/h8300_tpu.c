static inline unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) << 16 ;
V_3 |= F_2 ( V_2 -> V_6 + V_5 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned long long * V_7 )
{
unsigned long V_8 , V_9 , V_10 ;
int V_11 , V_12 ;
V_11 = F_4 ( V_2 -> V_4 + V_13 ) & 0x10 ;
do {
V_12 = V_11 ;
V_8 = F_1 ( V_2 ) ;
V_9 = F_1 ( V_2 ) ;
V_10 = F_1 ( V_2 ) ;
V_11 = F_4 ( V_2 -> V_4 + V_13 ) & 0x10 ;
} while ( F_5 ( ( V_11 != V_12 ) || ( V_8 > V_9 && V_8 < V_10 )
|| ( V_9 > V_10 && V_9 < V_8 ) || ( V_10 > V_8 && V_10 < V_9 ) ) );
* V_7 = V_9 ;
return V_11 ;
}
static inline struct V_1 * F_6 ( struct V_14 * V_15 )
{
return F_7 ( V_15 , struct V_1 , V_15 ) ;
}
static T_1 F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
unsigned long V_16 ;
unsigned long long V_17 ;
F_9 ( & V_2 -> V_18 , V_16 ) ;
if ( F_3 ( V_2 , & V_17 ) )
V_17 += 0x100000000 ;
F_10 ( & V_2 -> V_18 , V_16 ) ;
return V_17 ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
F_12 ( V_2 -> V_19 ) ;
F_13 ( 0 , V_2 -> V_4 + V_5 ) ;
F_13 ( 0 , V_2 -> V_6 + V_5 ) ;
F_14 ( 0x0f , V_2 -> V_4 + V_20 ) ;
F_14 ( 0x03 , V_2 -> V_6 + V_20 ) ;
V_2 -> V_19 = true ;
return 0 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
F_12 ( ! V_2 -> V_19 ) ;
F_14 ( 0 , V_2 -> V_4 + V_20 ) ;
F_14 ( 0 , V_2 -> V_6 + V_20 ) ;
V_2 -> V_19 = false ;
}
static int T_2 F_16 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_23 * V_24 [ 2 ] ;
V_2 -> V_22 = V_22 ;
V_24 [ V_25 ] = F_17 ( V_2 -> V_22 , V_26 , V_25 ) ;
V_24 [ V_27 ] = F_17 ( V_2 -> V_22 , V_26 , V_27 ) ;
if ( ! V_24 [ V_25 ] || ! V_24 [ V_27 ] ) {
F_18 ( & V_2 -> V_22 -> V_28 , L_1 ) ;
return - V_29 ;
}
V_2 -> V_30 = F_19 ( & V_2 -> V_22 -> V_28 , L_2 ) ;
if ( F_20 ( V_2 -> V_30 ) ) {
F_18 ( & V_2 -> V_22 -> V_28 , L_3 ) ;
return F_21 ( V_2 -> V_30 ) ;
}
V_2 -> V_4 = V_24 [ V_25 ] -> V_31 ;
V_2 -> V_6 = V_24 [ V_27 ] -> V_31 ;
V_2 -> V_15 . V_32 = V_22 -> V_32 ;
V_2 -> V_15 . V_33 = 200 ;
V_2 -> V_15 . V_34 = F_8 ;
V_2 -> V_15 . V_35 = F_11 ;
V_2 -> V_15 . V_36 = F_15 ;
V_2 -> V_15 . V_37 = F_22 ( sizeof( unsigned long ) * 8 ) ;
V_2 -> V_15 . V_16 = V_38 ;
F_23 ( & V_2 -> V_15 , F_24 ( V_2 -> V_30 ) / 64 ) ;
F_25 ( V_22 , V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_27 ( V_22 ) ;
if ( V_2 ) {
F_28 ( & V_22 -> V_28 , L_4 ) ;
return 0 ;
}
V_2 = F_29 ( & V_22 -> V_28 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
return F_16 ( V_2 , V_22 ) ;
}
static int F_30 ( struct V_21 * V_22 )
{
return - V_41 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_42 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_42 ) ;
}
