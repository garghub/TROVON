static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
int V_17 ;
bool V_18 = false ;
V_6 -> V_19 = F_3 ( F_4 ( V_10 -> V_20 ,
V_10 -> V_21 ) ) ;
V_6 -> V_22 = F_3 ( V_23 ) ;
if ( ( ! V_4 -> V_24 . V_25 ) ||
( V_26 . V_27 == V_28 ) )
return;
V_6 -> V_29 |= F_5 ( V_30 ) ;
V_15 = V_8 -> V_31 . V_32 ? : 1 ;
F_6 () ;
V_12 = F_7 ( V_4 -> V_12 ) ;
F_8 ( ! V_12 ) ;
if ( V_12 ) {
V_14 = V_12 -> V_33 . V_14 ;
V_18 = V_14 -> V_29 & V_34 ;
}
F_9 () ;
if ( ! V_18 && ( V_15 <= 10 ) &&
( V_26 . V_27 == V_35 ) ) {
V_6 -> V_29 |= F_5 ( V_36 ) ;
V_6 -> V_37 = 2 ;
}
V_16 = V_15 * V_4 -> V_24 . V_38 ;
V_17 = F_10 ( int , 3 * V_16 ,
V_39 * V_40 ) ;
V_17 = F_11 ( V_17 , V_39 ) ;
V_6 -> V_41 = F_5 ( V_17 ) ;
if ( V_26 . V_27 == V_35 ) {
V_6 -> V_42 = F_3 ( 10 ) ;
V_6 -> V_43 = F_3 ( 10 ) ;
} else {
V_6 -> V_42 = F_3 ( 50 ) ;
V_6 -> V_43 = F_3 ( 50 ) ;
}
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = {} ;
if ( ! V_44 . V_45 ) {
F_13 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_4 -> type != V_46 || V_4 -> V_47 )
return 0 ;
F_1 ( V_2 , V_4 , & V_6 ) ;
F_13 ( V_2 ,
L_2 ,
V_6 . V_19 , V_26 . V_27 ,
F_14 ( V_6 . V_29 ) ) ;
if ( V_6 . V_29 & F_5 ( V_30 ) ) {
F_13 ( V_2 , L_3 ,
F_14 ( V_6 . V_41 ) ) ;
F_13 ( V_2 , L_4 ,
F_15 ( V_6 . V_42 ) ) ;
F_13 ( V_2 , L_5 ,
F_15 ( V_6 . V_43 ) ) ;
F_13 ( V_2 , L_6 ,
F_15 ( V_6 . V_48 ) ) ;
F_13 ( V_2 , L_5 ,
F_15 ( V_6 . V_49 ) ) ;
F_13 ( V_2 , L_7 ,
V_6 . V_50 ) ;
F_13 ( V_2 , L_8 , V_6 . V_37 ) ;
}
return F_16 ( V_2 , V_51 , V_52 ,
sizeof( V_6 ) , & V_6 ) ;
}
int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = {} ;
struct V_9 * V_10 = F_2 ( V_4 ) ;
if ( ! V_44 . V_45 ) {
F_13 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_4 -> type != V_46 || V_4 -> V_47 )
return 0 ;
V_6 . V_19 = F_3 ( F_4 ( V_10 -> V_20 ,
V_10 -> V_21 ) ) ;
V_6 . V_22 = F_3 ( V_23 ) ;
F_13 ( V_2 ,
L_2 ,
V_6 . V_19 , V_26 . V_27 ,
F_14 ( V_6 . V_29 ) ) ;
return F_16 ( V_2 , V_51 , V_53 ,
sizeof( V_6 ) , & V_6 ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_1 ( V_2 , V_4 , V_6 ) ;
}
