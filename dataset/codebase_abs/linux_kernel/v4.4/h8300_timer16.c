static unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 , V_5 ;
int V_6 , V_7 ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_2 -> V_10 ;
do {
V_7 = V_6 ;
V_3 = F_3 ( V_2 -> V_11 + V_12 ) ;
V_4 = F_3 ( V_2 -> V_11 + V_12 ) ;
V_5 = F_3 ( V_2 -> V_11 + V_12 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_2 -> V_10 ;
} while ( F_4 ( ( V_6 != V_7 ) || ( V_3 > V_4 && V_3 < V_5 )
|| ( V_4 > V_5 && V_4 < V_3 ) || ( V_5 > V_3 && V_5 < V_4 ) ) );
V_4 |= 0x10000 ;
return V_4 ;
}
static T_1 F_5 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
F_6 ( F_2 ( V_2 -> V_8 + V_15 ) & ~ V_2 -> V_16 ,
V_2 -> V_8 + V_15 ) ;
V_2 -> V_17 += 0x10000 ;
return V_18 ;
}
static inline struct V_1 * F_7 ( struct V_19 * V_20 )
{
return F_8 ( V_20 , struct V_1 , V_20 ) ;
}
static T_2 F_9 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_20 ) ;
unsigned long V_21 , V_22 ;
unsigned long V_23 ;
F_10 ( & V_2 -> V_24 , V_21 ) ;
V_23 = V_2 -> V_17 ;
V_22 = F_1 ( V_2 ) ;
F_11 ( & V_2 -> V_24 , V_21 ) ;
return V_23 + V_22 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_20 ) ;
F_13 ( V_2 -> V_25 ) ;
V_2 -> V_17 = 0 ;
F_14 ( 0x0000 , V_2 -> V_11 + V_12 ) ;
F_6 ( 0x83 , V_2 -> V_11 + V_26 ) ;
F_6 ( F_2 ( V_2 -> V_8 + V_27 ) | V_2 -> V_28 ,
V_2 -> V_8 + V_27 ) ;
V_2 -> V_25 = true ;
return 0 ;
}
static void F_15 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_20 ) ;
F_13 ( ! V_2 -> V_25 ) ;
F_6 ( F_2 ( V_2 -> V_8 + V_27 ) & ~ V_2 -> V_28 ,
V_2 -> V_8 + V_27 ) ;
V_2 -> V_25 = false ;
}
static int F_16 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_31 * V_32 [ 2 ] ;
int V_33 , V_13 ;
unsigned int V_34 ;
V_2 -> V_30 = V_30 ;
V_32 [ V_35 ] = F_17 ( V_2 -> V_30 ,
V_36 , V_35 ) ;
V_32 [ V_37 ] = F_17 ( V_2 -> V_30 ,
V_36 , V_37 ) ;
if ( ! V_32 [ V_35 ] || ! V_32 [ V_37 ] ) {
F_18 ( & V_2 -> V_30 -> V_38 , L_1 ) ;
return - V_39 ;
}
V_13 = F_19 ( V_2 -> V_30 , 0 ) ;
if ( V_13 < 0 ) {
F_18 ( & V_2 -> V_30 -> V_38 , L_2 ) ;
return V_13 ;
}
V_2 -> V_40 = F_20 ( & V_2 -> V_30 -> V_38 , L_3 ) ;
if ( F_21 ( V_2 -> V_40 ) ) {
F_18 ( & V_2 -> V_30 -> V_38 , L_4 ) ;
return F_22 ( V_2 -> V_40 ) ;
}
F_23 ( V_2 -> V_30 -> V_38 . V_41 , L_5 , & V_34 ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_11 = V_32 [ V_35 ] -> V_42 ;
V_2 -> V_8 = V_32 [ V_37 ] -> V_42 ;
V_2 -> V_28 = 1 << V_34 ;
V_2 -> V_16 = 1 << V_34 ;
V_2 -> V_43 = 1 << ( 4 + V_34 ) ;
V_2 -> V_20 . V_44 = V_30 -> V_44 ;
V_2 -> V_20 . V_45 = 200 ;
V_2 -> V_20 . V_46 = F_9 ;
V_2 -> V_20 . V_47 = F_12 ;
V_2 -> V_20 . V_48 = F_15 ;
V_2 -> V_20 . V_49 = F_24 ( sizeof( unsigned long ) * 8 ) ;
V_2 -> V_20 . V_21 = V_50 ;
V_33 = F_25 ( V_13 , F_5 ,
V_51 , V_30 -> V_44 , V_2 ) ;
if ( V_33 < 0 ) {
F_18 ( & V_2 -> V_30 -> V_38 , L_6 , V_13 ) ;
return V_33 ;
}
F_26 ( & V_2 -> V_20 , F_27 ( V_2 -> V_40 ) / 8 ) ;
return 0 ;
}
static int F_28 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_29 ( V_30 ) ;
if ( V_2 ) {
F_30 ( & V_30 -> V_38 , L_7 ) ;
return 0 ;
}
V_2 = F_31 ( & V_30 -> V_38 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
return F_16 ( V_2 , V_30 ) ;
}
static int F_32 ( struct V_29 * V_30 )
{
return - V_54 ;
}
static int T_3 F_33 ( void )
{
return F_34 ( & V_55 ) ;
}
static void T_4 F_35 ( void )
{
F_36 ( & V_55 ) ;
}
