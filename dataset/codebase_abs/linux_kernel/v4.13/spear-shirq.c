static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 , V_6 = V_2 -> V_7 - V_4 -> V_8 + V_4 -> V_9 ;
T_1 T_2 * V_10 = V_4 -> V_11 + V_4 -> V_12 ;
F_3 ( & V_13 ) ;
V_5 = F_4 ( V_10 ) & ~ ( 0x1 << V_6 ) ;
F_5 ( V_5 , V_10 ) ;
F_6 ( & V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 , V_6 = V_2 -> V_7 - V_4 -> V_8 + V_4 -> V_9 ;
T_1 T_2 * V_10 = V_4 -> V_11 + V_4 -> V_12 ;
F_3 ( & V_13 ) ;
V_5 = F_4 ( V_10 ) | ( 0x1 << V_6 ) ;
F_5 ( V_5 , V_10 ) ;
F_6 ( & V_13 ) ;
}
static void F_8 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_9 ( V_15 ) ;
T_1 V_16 ;
V_16 = F_4 ( V_4 -> V_11 + V_4 -> V_17 ) & V_4 -> V_18 ;
V_16 >>= V_4 -> V_9 ;
while ( V_16 ) {
int V_7 = F_10 ( V_16 ) ;
V_16 &= ~ ( 0x1 << V_7 ) ;
F_11 ( V_4 -> V_8 + V_7 ) ;
}
}
static void T_3 F_12 ( struct V_3 * V_4 ,
int V_19 )
{
int V_20 ;
if ( ! V_4 -> V_21 )
return;
F_13 ( V_19 , F_8 , V_4 ) ;
for ( V_20 = 0 ; V_20 < V_4 -> V_22 ; V_20 ++ ) {
F_14 ( V_4 -> V_8 + V_20 ,
V_4 -> V_21 , V_23 ) ;
F_15 ( V_4 -> V_8 + V_20 , V_4 ) ;
}
}
static int T_3 F_16 ( struct V_3 * * V_24 , int V_25 ,
struct V_26 * V_27 )
{
int V_20 , V_19 , V_8 , V_28 = 0 , V_22 = 0 ;
struct V_29 * V_30 ;
void T_2 * V_11 ;
V_11 = F_17 ( V_27 , 0 ) ;
if ( ! V_11 ) {
F_18 ( L_1 , V_31 ) ;
return - V_32 ;
}
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ )
V_22 += V_24 [ V_20 ] -> V_22 ;
V_8 = F_19 ( - 1 , 0 , V_22 , 0 ) ;
if ( V_8 < 0 ) {
F_18 ( L_2 , V_31 ) ;
goto V_33;
}
V_30 = F_20 ( V_27 , V_22 , V_8 , 0 ,
& V_34 , NULL ) ;
if ( F_21 ( ! V_30 ) ) {
F_22 ( L_3 , V_31 ) ;
goto V_35;
}
for ( V_20 = 0 ; V_20 < V_25 ; V_20 ++ ) {
V_24 [ V_20 ] -> V_11 = V_11 ;
V_24 [ V_20 ] -> V_8 = F_23 ( V_30 ,
V_28 ) ;
V_19 = F_24 ( V_27 , V_20 ) ;
F_12 ( V_24 [ V_20 ] , V_19 ) ;
V_28 += V_24 [ V_20 ] -> V_22 ;
}
return 0 ;
V_35:
F_25 ( V_8 , V_22 ) ;
V_33:
F_26 ( V_11 ) ;
return - V_32 ;
}
static int T_3 F_27 ( struct V_26 * V_27 ,
struct V_26 * V_36 )
{
return F_16 ( V_37 ,
F_28 ( V_37 ) , V_27 ) ;
}
static int T_3 F_29 ( struct V_26 * V_27 ,
struct V_26 * V_36 )
{
return F_16 ( V_38 ,
F_28 ( V_38 ) , V_27 ) ;
}
static int T_3 F_30 ( struct V_26 * V_27 ,
struct V_26 * V_36 )
{
return F_16 ( V_39 ,
F_28 ( V_39 ) , V_27 ) ;
}
