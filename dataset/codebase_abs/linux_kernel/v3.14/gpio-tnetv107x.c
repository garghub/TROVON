static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned V_8 = V_2 -> V_9 + V_3 ;
unsigned long V_10 ;
F_3 ( & V_5 -> V_11 , V_10 ) ;
F_4 ( V_7 -> V_12 , V_8 ) ;
F_5 ( & V_5 -> V_11 , V_10 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned V_8 = V_2 -> V_9 + V_3 ;
unsigned long V_10 ;
F_3 ( & V_5 -> V_11 , V_10 ) ;
F_7 ( V_7 -> V_12 , V_8 ) ;
F_5 ( & V_5 -> V_11 , V_10 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned V_8 = V_2 -> V_9 + V_3 ;
unsigned long V_10 ;
F_3 ( & V_5 -> V_11 , V_10 ) ;
F_4 ( V_7 -> V_13 , V_8 ) ;
F_5 ( & V_5 -> V_11 , V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 , int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned V_8 = V_2 -> V_9 + V_3 ;
unsigned long V_10 ;
F_3 ( & V_5 -> V_11 , V_10 ) ;
if ( V_14 )
F_4 ( V_7 -> V_15 , V_8 ) ;
else
F_7 ( V_7 -> V_15 , V_8 ) ;
F_7 ( V_7 -> V_13 , V_8 ) ;
F_5 ( & V_5 -> V_11 , V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned V_8 = V_2 -> V_9 + V_3 ;
int V_16 ;
V_16 = F_11 ( V_7 -> V_17 , V_8 ) ;
return V_16 ? 1 : 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned V_3 , int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 T_1 * V_7 = V_5 -> V_7 ;
unsigned V_8 = V_2 -> V_9 + V_3 ;
unsigned long V_10 ;
F_3 ( & V_5 -> V_11 , V_10 ) ;
if ( V_14 )
F_4 ( V_7 -> V_15 , V_8 ) ;
else
F_7 ( V_7 -> V_15 , V_8 ) ;
F_5 ( & V_5 -> V_11 , V_10 ) ;
}
static int T_2 F_13 ( void )
{
int V_18 , V_9 ;
unsigned V_19 ;
struct V_20 * V_21 = & V_20 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
if ( V_21 -> V_22 != V_23 )
return 0 ;
V_19 = V_21 -> V_24 ;
if ( V_19 == 0 ) {
F_14 ( L_1 ) ;
return - V_25 ;
}
if ( F_15 ( V_26 < V_19 ) )
V_19 = V_26 ;
V_7 = F_16 ( V_21 -> V_27 , V_28 ) ;
if ( F_15 ( ! V_7 ) )
return - V_25 ;
for ( V_18 = 0 , V_9 = 0 ; V_9 < V_19 ; V_18 ++ , V_9 += 32 ) {
V_5 = & V_29 [ V_18 ] ;
V_5 -> V_2 . V_30 = L_2 ;
V_5 -> V_2 . V_31 = false ;
V_5 -> V_2 . V_9 = V_9 ;
V_5 -> V_2 . V_19 = V_19 - V_9 ;
if ( V_5 -> V_2 . V_19 > 32 )
V_5 -> V_2 . V_19 = 32 ;
V_5 -> V_2 . V_32 = F_1 ;
V_5 -> V_2 . free = F_6 ;
V_5 -> V_2 . V_33 = F_8 ;
V_5 -> V_2 . V_34 = F_10 ;
V_5 -> V_2 . V_35 = F_9 ;
V_5 -> V_2 . V_36 = F_12 ;
F_17 ( & V_5 -> V_11 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_37 = & V_7 -> V_15 [ V_18 ] ;
V_5 -> V_38 = & V_7 -> V_15 [ V_18 ] ;
V_5 -> V_39 = & V_7 -> V_17 [ V_18 ] ;
F_18 ( & V_5 -> V_2 ) ;
}
V_21 -> V_40 = V_29 ;
V_21 -> V_41 = F_19 ( V_19 , 32 ) ;
return 0 ;
}
