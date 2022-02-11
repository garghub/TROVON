static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , bool assert )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_5 ) ;
unsigned long V_6 ;
const struct V_7 * V_5 ;
T_1 V_8 ;
if ( V_3 >= F_3 ( V_9 ) )
return - V_10 ;
V_5 = & V_9 [ V_3 ] ;
F_4 ( & V_11 , V_6 ) ;
V_8 = F_5 ( V_4 -> V_12 + V_5 -> V_13 ) ;
if ( assert )
V_8 |= F_6 ( V_5 -> V_14 ) ;
else
V_8 &= ~ F_6 ( V_5 -> V_14 ) ;
F_7 ( V_8 , V_4 -> V_12 + V_5 -> V_13 ) ;
F_8 ( & V_11 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , true ) ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , false ) ;
}
static int F_11 ( struct V_15 * V_16 )
{
int V_17 , V_18 , V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = & V_16 -> V_25 ;
if ( ! V_26 )
return - V_27 ;
for ( V_19 = 0 ; V_19 < F_3 ( V_28 ) ; V_19 ++ )
V_28 [ V_19 ] -> V_12 = V_26 ;
for ( V_19 = 0 ; V_19 < F_3 ( V_29 ) ; V_19 ++ )
V_29 [ V_19 ] -> V_12 = V_26 ;
V_30 . V_12 = V_26 ;
for ( V_19 = 0 ; V_19 < F_3 ( V_31 ) ; V_19 ++ )
V_31 [ V_19 ] -> V_13 = V_26 +
( T_1 ) V_31 [ V_19 ] -> V_13 ;
for ( V_19 = 0 ; V_19 < F_3 ( V_32 ) ; V_19 ++ )
V_32 [ V_19 ] -> V_13 = V_26 +
( T_1 ) V_32 [ V_19 ] -> V_13 ;
for ( V_19 = 0 ; V_19 < F_3 ( V_33 ) ; V_19 ++ )
V_33 [ V_19 ] -> V_13 = V_26 +
( T_1 ) V_33 [ V_19 ] -> V_13 ;
for ( V_18 = V_34 ; V_18 < V_35 ; V_18 ++ ) {
if ( ! V_36 . V_37 [ V_18 ] )
continue;
V_17 = F_12 ( V_25 , V_36 . V_37 [ V_18 ] ) ;
if ( V_17 )
return V_17 ;
}
V_21 = F_13 ( & V_30 . V_38 ) ;
V_23 = V_21 -> V_22 ;
V_17 = F_14 ( V_23 , & V_30 . V_39 ) ;
if ( V_17 ) {
F_15 ( L_1 ,
V_40 ) ;
return V_17 ;
}
return F_16 ( V_25 -> V_41 , V_42 ,
& V_36 ) ;
}
static void T_2 F_17 ( struct V_43 * V_44 )
{
struct V_4 * V_45 ;
int V_17 ;
V_26 = F_18 ( V_44 , 1 ) ;
if ( ! V_26 ) {
F_15 ( L_2 , V_40 ) ;
return;
}
V_45 = F_19 ( sizeof( * V_45 ) , V_46 ) ;
if ( ! V_45 )
return;
V_45 -> V_12 = V_26 ;
V_45 -> V_5 . V_47 = & V_48 ;
V_45 -> V_5 . V_49 = F_3 ( V_9 ) ;
V_45 -> V_5 . V_41 = V_44 ;
V_17 = F_20 ( & V_45 -> V_5 ) ;
if ( V_17 ) {
F_15 ( L_3 ,
V_40 , V_17 ) ;
return;
}
}
