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
static void F_8 ( unsigned V_7 , struct V_14 * V_15 )
{
struct V_3 * V_4 = F_9 ( V_7 ) ;
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
F_13 ( V_19 , F_8 ) ;
F_14 ( V_19 , V_4 ) ;
for ( V_20 = 0 ; V_20 < V_4 -> V_22 ; V_20 ++ ) {
F_15 ( V_4 -> V_8 + V_20 ,
V_4 -> V_21 , V_23 ) ;
F_16 ( V_4 -> V_8 + V_20 , V_24 ) ;
F_17 ( V_4 -> V_8 + V_20 , V_4 ) ;
}
}
static int T_3 F_18 ( struct V_3 * * V_25 , int V_26 ,
struct V_27 * V_28 )
{
int V_20 , V_19 , V_8 , V_29 = 0 , V_22 = 0 ;
struct V_30 * V_31 ;
void T_2 * V_11 ;
V_11 = F_19 ( V_28 , 0 ) ;
if ( ! V_11 ) {
F_20 ( L_1 , V_32 ) ;
return - V_33 ;
}
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ )
V_22 += V_25 [ V_20 ] -> V_22 ;
V_8 = F_21 ( - 1 , 0 , V_22 , 0 ) ;
if ( F_22 ( V_8 ) ) {
F_20 ( L_2 , V_32 ) ;
goto V_34;
}
V_31 = F_23 ( V_28 , V_22 , V_8 , 0 ,
& V_35 , NULL ) ;
if ( F_24 ( ! V_31 ) ) {
F_25 ( L_3 , V_32 ) ;
goto V_36;
}
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ ) {
V_25 [ V_20 ] -> V_11 = V_11 ;
V_25 [ V_20 ] -> V_8 = F_26 ( V_31 ,
V_29 ) ;
V_19 = F_27 ( V_28 , V_20 ) ;
F_12 ( V_25 [ V_20 ] , V_19 ) ;
V_29 += V_25 [ V_20 ] -> V_22 ;
}
return 0 ;
V_36:
F_28 ( V_8 , V_22 ) ;
V_34:
F_29 ( V_11 ) ;
return - V_33 ;
}
static int T_3 F_30 ( struct V_27 * V_28 ,
struct V_27 * V_37 )
{
return F_18 ( V_38 ,
F_31 ( V_38 ) , V_28 ) ;
}
static int T_3 F_32 ( struct V_27 * V_28 ,
struct V_27 * V_37 )
{
return F_18 ( V_39 ,
F_31 ( V_39 ) , V_28 ) ;
}
static int T_3 F_33 ( struct V_27 * V_28 ,
struct V_27 * V_37 )
{
return F_18 ( V_40 ,
F_31 ( V_40 ) , V_28 ) ;
}
