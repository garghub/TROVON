static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline struct V_6 * F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 -> V_7 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_6 * V_10 = F_5 ( V_2 ) ;
int V_11 , V_12 = 10 ;
unsigned int V_13 ;
F_9 ( L_1 ) ;
F_1 ( V_2 , V_14 , 0x8d ) ;
F_1 ( V_2 , V_15 , 0x10 ) ;
F_1 ( V_2 , V_16 , 0x1a ) ;
F_10 ( 10 ) ;
F_1 ( V_2 , V_14 , 0x0d ) ;
V_13 = F_11 ( V_10 , V_17 ) ;
V_13 |= V_18 ;
F_12 ( V_10 , V_17 , V_13 ) ;
V_13 &= ~ V_18 ;
F_10 ( 10 ) ;
F_12 ( V_10 , V_17 , V_13 ) ;
F_12 ( V_10 , V_19 , 0x3f ) ;
V_13 = F_11 ( V_10 , V_17 ) ;
V_13 |= V_20 ;
F_12 ( V_10 , V_17 , V_13 ) ;
F_13 () ;
F_10 ( 10 ) ;
V_13 = F_3 ( V_2 , V_21 ) ;
V_13 |= V_22 ;
V_13 &= ~ V_23 ;
F_1 ( V_2 , V_21 , V_13 ) ;
F_12 ( V_10 , V_19 , 0x80 ) ;
V_11 = 1000 ;
while ( -- V_12 > 0 ) {
V_13 = F_3 ( V_2 , V_24 ) ;
if ( V_13 & V_25 )
break;
F_10 ( 1 ) ;
if ( -- V_11 > 0 )
continue;
F_1 ( V_2 , V_14 , 0x8d ) ;
F_10 ( 10 ) ;
F_1 ( V_2 , V_14 , 0x0d ) ;
F_10 ( 350 ) ;
V_11 = 1000 ;
}
return 0 ;
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_6 * V_10 = F_5 ( V_2 ) ;
unsigned int V_13 ;
F_9 ( L_1 ) ;
V_13 = F_11 ( V_10 , V_17 ) ;
V_13 &= ~ V_20 ;
F_12 ( V_10 , V_17 , V_13 ) ;
V_13 = F_3 ( V_2 , V_21 ) ;
V_13 |= V_18 ;
V_13 &= ~ V_20 ;
F_1 ( V_2 , V_21 , V_13 ) ;
F_13 () ;
}
static const struct V_26 * F_15 ( unsigned long V_27 )
{
int V_28 ;
for ( V_28 = 1 ; V_28 < F_16 ( V_29 ) ; V_28 ++ )
if ( V_27 > V_29 [ V_28 ] . V_27 )
return & V_29 [ V_28 - 1 ] ;
return & V_29 [ V_28 - 1 ] ;
}
static unsigned long F_17 ( struct V_8 * V_9 ,
unsigned long V_30 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
return V_2 -> V_31 ;
}
static long F_18 ( struct V_8 * V_9 , unsigned long V_27 ,
unsigned long * V_30 )
{
const struct V_26 * V_26 = F_15 ( V_27 ) ;
return V_26 -> V_27 ;
}
static int F_19 ( struct V_8 * V_9 , unsigned long V_27 ,
unsigned long V_30 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
const struct V_26 * V_26 = F_15 ( V_27 ) ;
int V_28 ;
F_9 ( L_2 , V_27 ) ;
for ( V_28 = 0 ; V_28 < V_26 -> V_32 ; V_28 ++ )
F_1 ( V_2 , V_26 -> V_33 [ V_28 ] . V_3 , V_26 -> V_33 [ V_28 ] . V_13 ) ;
V_2 -> V_31 = V_27 ;
return 0 ;
}
int F_20 ( struct V_34 * V_7 )
{
struct V_35 * V_36 = & V_7 -> V_36 ;
struct V_1 * V_2 ;
struct V_37 * V_37 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < ( F_16 ( V_29 ) - 1 ) ; V_28 ++ )
if ( F_21 ( V_29 [ V_28 ] . V_27 < V_29 [ V_28 + 1 ] . V_27 ) )
return - V_38 ;
V_2 = F_22 ( V_36 , sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_2 -> V_5 = F_23 ( V_7 , L_3 , L_4 ) ;
if ( F_24 ( V_2 -> V_5 ) ) {
F_25 ( V_36 , L_5 ) ;
return - V_40 ;
}
V_2 -> V_7 = V_7 ;
V_2 -> V_8 . V_41 = & V_42 ;
V_37 = F_26 ( V_36 , & V_2 -> V_8 ) ;
if ( F_24 ( V_37 ) ) {
F_25 ( V_36 , L_6 ) ;
return - V_38 ;
}
return 0 ;
}
