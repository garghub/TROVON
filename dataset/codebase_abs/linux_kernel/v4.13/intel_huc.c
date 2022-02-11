static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 = 0 ;
T_1 V_10 ;
int V_11 ;
V_11 = F_2 ( V_4 -> V_12 , false ) ;
if ( V_11 ) {
F_3 ( L_1 , V_11 ) ;
return V_11 ;
}
V_8 = F_4 ( V_4 -> V_12 , NULL , 0 , 0 ,
V_13 | V_14 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( L_2 , ( int ) F_6 ( V_8 ) ) ;
return F_6 ( V_8 ) ;
}
F_7 ( V_2 , V_15 ) ;
V_9 = F_8 ( V_8 ) + V_4 -> V_16 ;
F_9 ( V_17 , F_10 ( V_9 ) ) ;
F_9 ( V_18 , F_11 ( V_9 ) & 0xFFFF ) ;
F_9 ( V_19 , 0 ) ;
F_9 ( V_20 , V_21 ) ;
V_10 = V_4 -> V_22 + V_4 -> V_23 ;
F_9 ( V_24 , V_10 ) ;
F_9 ( V_25 , F_12 ( V_26 | V_27 ) ) ;
V_11 = F_13 ( ( F_14 ( V_25 ) & V_27 ) == 0 , 100 ) ;
F_3 ( L_3 , V_11 ) ;
F_9 ( V_25 , F_15 ( V_26 ) ) ;
F_16 ( V_2 , V_15 ) ;
F_17 ( V_8 ) ;
return V_11 ;
}
void F_18 ( struct V_28 * V_5 )
{
struct V_1 * V_2 = F_19 ( V_5 ) ;
V_5 -> V_6 . V_29 = NULL ;
V_5 -> V_6 . V_30 = V_31 ;
V_5 -> V_6 . V_32 = V_31 ;
V_5 -> V_6 . type = V_33 ;
if ( V_34 . V_35 ) {
V_5 -> V_6 . V_29 = V_34 . V_35 ;
V_5 -> V_6 . V_36 = 0 ;
V_5 -> V_6 . V_37 = 0 ;
} else if ( F_20 ( V_2 ) ) {
V_5 -> V_6 . V_29 = V_38 ;
V_5 -> V_6 . V_36 = V_39 ;
V_5 -> V_6 . V_37 = V_40 ;
} else if ( F_21 ( V_2 ) ) {
V_5 -> V_6 . V_29 = V_41 ;
V_5 -> V_6 . V_36 = V_42 ;
V_5 -> V_6 . V_37 = V_43 ;
} else if ( F_22 ( V_2 ) || F_23 ( V_2 ) ) {
V_5 -> V_6 . V_29 = V_44 ;
V_5 -> V_6 . V_36 = V_45 ;
V_5 -> V_6 . V_37 = V_46 ;
} else if ( F_24 ( V_2 ) ) {
V_5 -> V_6 . V_29 = V_47 ;
V_5 -> V_6 . V_36 = V_48 ;
V_5 -> V_6 . V_37 = V_49 ;
} else {
F_25 ( L_4 ) ;
return;
}
}
void F_26 ( struct V_28 * V_5 )
{
struct V_1 * V_2 = F_19 ( V_5 ) ;
int V_50 ;
F_3 ( L_5 ,
V_5 -> V_6 . V_29 ,
F_27 ( V_5 -> V_6 . V_30 ) ,
F_27 ( V_5 -> V_6 . V_32 ) ) ;
if ( V_5 -> V_6 . V_30 != V_51 )
return;
V_5 -> V_6 . V_32 = V_52 ;
V_50 = F_1 ( V_2 ) ;
V_5 -> V_6 . V_32 = V_50 ?
V_53 : V_51 ;
F_3 ( L_5 ,
V_5 -> V_6 . V_29 ,
F_27 ( V_5 -> V_6 . V_30 ) ,
F_27 ( V_5 -> V_6 . V_32 ) ) ;
if ( V_5 -> V_6 . V_32 != V_51 )
F_25 ( L_6 , V_50 ) ;
return;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = & V_2 -> V_55 ;
struct V_28 * V_5 = & V_2 -> V_5 ;
struct V_7 * V_8 ;
int V_11 ;
T_1 V_56 [ 2 ] ;
if ( V_5 -> V_6 . V_32 != V_51 )
return;
V_8 = F_4 ( V_5 -> V_6 . V_12 , NULL , 0 , 0 ,
V_13 | V_14 ) ;
if ( F_5 ( V_8 ) ) {
F_25 ( L_7 ,
( int ) F_6 ( V_8 ) ) ;
return;
}
V_56 [ 0 ] = V_57 ;
V_56 [ 1 ] = F_8 ( V_8 ) + V_5 -> V_6 . V_58 ;
V_11 = F_29 ( V_55 , V_56 , F_30 ( V_56 ) ) ;
if ( V_11 ) {
F_25 ( L_8 , V_11 ) ;
goto V_59;
}
V_11 = F_31 ( V_2 ,
V_60 ,
V_61 ,
V_61 ,
50 ) ;
if ( V_11 ) {
F_25 ( L_9 , V_11 ) ;
goto V_59;
}
V_59:
F_17 ( V_8 ) ;
}
