static const void * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const struct V_5 * V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_8 ) ; V_7 ++ ) {
V_6 = & V_8 [ V_7 ] ;
if ( V_6 -> V_9 == V_4 -> V_10 )
return V_6 ;
}
return NULL ;
}
static int F_3 ( struct V_3 * V_11 , void * V_12 )
{
int V_13 , V_14 ;
V_11 -> V_15 [ 0 ] -> V_16 &= ~ V_17 ;
V_11 -> V_15 [ 0 ] -> V_16 |= V_18 ;
for ( V_13 = 0x000 ; V_13 < 0x400 ; V_13 += 0x20 ) {
V_11 -> V_15 [ 0 ] -> V_19 = V_13 ;
V_14 = F_4 ( V_11 ) ;
if ( ! V_14 )
return 0 ;
}
return - V_20 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_21 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
static const struct V_5 * V_6 ;
struct V_22 * V_23 ;
int V_14 ;
V_6 = F_1 ( V_2 , V_4 ) ;
if ( ! V_6 )
return - V_20 ;
V_2 -> V_24 = V_6 ;
V_2 -> V_25 = V_6 -> V_26 ;
V_4 -> V_27 |= V_28 | V_29 ;
V_14 = F_7 ( V_2 , F_3 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_30 = V_4 -> V_15 [ 0 ] -> V_19 ;
V_4 -> V_31 = V_2 ;
V_14 = F_8 ( V_4 , V_32 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_33 = V_4 -> V_33 ;
V_14 = F_9 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_23 = V_2 -> V_34 ;
return F_10 ( V_2 , 0 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
return F_15 ( V_4 , & V_35 ) ;
}
