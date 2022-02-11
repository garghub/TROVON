static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 ,
L_1 ,
V_5 . V_6 ,
F_3 ( V_4 -> V_7 ) ) ;
F_2 ( V_2 , L_2 , V_4 -> V_8 ) ;
if ( V_4 -> V_7 & F_4 ( V_9 ) ) {
F_2 ( V_2 , L_3 ,
F_5 ( V_4 -> V_10 ) ) ;
F_2 ( V_2 , L_4 ,
F_5 ( V_4 -> V_11 ) ) ;
F_2 ( V_2 , L_5 ,
V_4 -> V_12 ) ;
}
}
void F_6 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 , V_22 ;
int V_23 ;
bool V_24 = false ;
V_4 -> V_8 = V_25 ;
if ( V_5 . V_6 == V_26 )
return;
V_4 -> V_7 |= F_4 ( V_27 ) ;
if ( ! V_14 -> V_28 . V_29 )
return;
V_4 -> V_7 |= F_4 ( V_9 ) ;
V_21 = V_16 -> V_30 . V_31 ? : 1 ;
F_7 () ;
V_18 = F_8 ( V_14 -> V_18 ) ;
F_9 ( ! V_18 ) ;
if ( V_18 ) {
V_20 = V_18 -> V_32 . V_20 ;
V_24 = V_20 -> V_7 & V_33 ;
}
F_10 () ;
if ( ! V_24 && ( V_21 <= 10 ) &&
( V_5 . V_6 == V_34 ) )
V_4 -> V_7 |= F_4 ( V_35 ) ;
V_22 = V_21 * V_14 -> V_28 . V_36 ;
V_23 = F_11 ( int , 3 * V_22 ,
V_37 * V_4 -> V_8 ) ;
V_23 = F_12 ( V_23 , V_37 ) ;
V_4 -> V_8 = V_23 ;
V_4 -> V_10 = F_13 ( 100 * V_38 ) ;
V_4 -> V_11 = F_13 ( 100 * V_38 ) ;
}
int F_14 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_3 V_4 = {} ;
if ( V_14 -> type != V_39 || V_14 -> V_40 )
return 0 ;
F_6 ( V_2 , V_14 , & V_4 ) ;
F_1 ( V_2 , & V_4 ) ;
return F_15 ( V_2 , V_41 , V_42 ,
sizeof( V_4 ) , & V_4 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_3 V_4 = {} ;
if ( V_14 -> type != V_39 || V_14 -> V_40 )
return 0 ;
if ( V_5 . V_6 != V_26 )
V_4 . V_7 |= F_4 ( V_27 ) ;
F_1 ( V_2 , & V_4 ) ;
return F_15 ( V_2 , V_41 , V_43 ,
sizeof( V_4 ) , & V_4 ) ;
}
