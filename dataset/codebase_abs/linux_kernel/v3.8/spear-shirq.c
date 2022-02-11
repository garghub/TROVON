static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , V_7 = V_2 -> V_8 - V_5 -> V_9 ;
unsigned long V_10 ;
if ( V_5 -> V_11 . V_12 == - 1 )
return;
F_3 ( & V_13 , V_10 ) ;
V_6 = F_4 ( V_5 -> V_14 + V_5 -> V_11 . V_12 ) ;
if ( V_3 ^ V_5 -> V_11 . V_15 )
V_6 &= ~ ( 0x1 << V_5 -> V_16 << V_7 ) ;
else
V_6 |= 0x1 << V_5 -> V_16 << V_7 ;
F_5 ( V_6 , V_5 -> V_14 + V_5 -> V_11 . V_12 ) ;
F_6 ( & V_13 , V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 1 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
}
static void F_9 ( unsigned V_8 , struct V_17 * V_18 )
{
T_1 V_19 , V_20 , V_6 , V_3 , V_21 ;
struct V_22 * V_23 ;
struct V_4 * V_5 = F_10 ( V_8 ) ;
V_23 = F_11 ( V_8 ) ;
V_23 -> V_24 ( & V_18 -> V_1 ) ;
V_3 = ( ( 0x1 << V_5 -> V_25 ) - 1 ) << V_5 -> V_16 ;
while ( ( V_6 = F_4 ( V_5 -> V_14 + V_5 -> V_11 . V_26 ) &
V_3 ) ) {
V_6 >>= V_5 -> V_16 ;
for ( V_19 = 0 , V_20 = 1 ; V_19 < V_5 -> V_25 ; V_19 ++ , V_20 <<= 1 ) {
if ( ! ( V_20 & V_6 ) )
continue;
F_12 ( V_5 -> V_9 + V_19 ) ;
if ( V_5 -> V_11 . V_27 == - 1 )
continue;
V_21 = F_4 ( V_5 -> V_14 + V_5 -> V_11 . V_27 ) ;
if ( V_5 -> V_11 . V_28 )
V_21 &= ~ ( V_20 << V_5 -> V_16 ) ;
else
V_21 |= ( V_20 << V_5 -> V_16 ) ;
F_5 ( V_21 , V_5 -> V_14 + V_5 -> V_11 . V_27 ) ;
}
}
V_23 -> V_29 ( & V_18 -> V_1 ) ;
}
static void T_2 F_13 ( struct V_4 * V_5 )
{
int V_19 ;
if ( V_5 -> V_30 )
return;
F_14 ( V_5 -> V_8 , F_9 ) ;
for ( V_19 = 0 ; V_19 < V_5 -> V_25 ; V_19 ++ ) {
F_15 ( V_5 -> V_9 + V_19 ,
& V_31 , V_32 ) ;
F_16 ( V_5 -> V_9 + V_19 , V_33 ) ;
F_17 ( V_5 -> V_9 + V_19 , V_5 ) ;
}
F_18 ( V_5 -> V_8 , V_5 ) ;
}
static int T_2 F_19 ( struct V_4 * * V_34 , int V_35 ,
struct V_36 * V_37 )
{
int V_19 , V_9 , V_38 = 0 , V_25 = 0 ;
static struct V_39 * V_40 ;
void T_3 * V_14 ;
V_14 = F_20 ( V_37 , 0 ) ;
if ( ! V_14 ) {
F_21 ( L_1 , V_41 ) ;
return - V_42 ;
}
for ( V_19 = 0 ; V_19 < V_35 ; V_19 ++ )
V_25 += V_34 [ V_19 ] -> V_25 ;
V_9 = F_22 ( - 1 , 0 , V_25 , 0 ) ;
if ( F_23 ( V_9 ) ) {
F_21 ( L_2 , V_41 ) ;
goto V_43;
}
V_40 = F_24 ( V_37 , V_25 , V_9 , 0 ,
& V_44 , NULL ) ;
if ( F_25 ( ! V_40 ) ) {
F_26 ( L_3 , V_41 ) ;
goto V_45;
}
for ( V_19 = 0 ; V_19 < V_35 ; V_19 ++ ) {
V_34 [ V_19 ] -> V_14 = V_14 ;
V_34 [ V_19 ] -> V_9 = F_27 ( V_40 ,
V_38 ) ;
V_34 [ V_19 ] -> V_8 = F_28 ( V_37 , V_19 ) ;
F_13 ( V_34 [ V_19 ] ) ;
V_38 += V_34 [ V_19 ] -> V_25 ;
}
return 0 ;
V_45:
F_29 ( V_9 , V_25 ) ;
V_43:
F_30 ( V_14 ) ;
return - V_42 ;
}
int T_2 F_31 ( struct V_36 * V_37 ,
struct V_36 * V_46 )
{
return F_19 ( V_47 ,
F_32 ( V_47 ) , V_37 ) ;
}
int T_2 F_33 ( struct V_36 * V_37 ,
struct V_36 * V_46 )
{
return F_19 ( V_48 ,
F_32 ( V_48 ) , V_37 ) ;
}
int T_2 F_34 ( struct V_36 * V_37 ,
struct V_36 * V_46 )
{
return F_19 ( V_49 ,
F_32 ( V_49 ) , V_37 ) ;
}
