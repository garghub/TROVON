static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 ) ;
return F_3 ( V_9 -> V_10 , V_4 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_11 * V_12 )
{
struct V_8 * V_9 = F_2 ( V_6 ) ;
struct V_13 V_14 = { 0 } ;
struct V_15 * V_16 = V_6 -> V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
unsigned int V_21 ;
unsigned long V_22 ;
struct V_1 * V_23 ;
T_1 V_24 ;
int V_25 ;
V_21 = F_5 ( V_12 -> V_26 , 8 ) ;
V_14 . V_27 = V_12 -> V_28 ;
V_14 . V_29 = V_12 -> V_30 ;
V_14 . V_31 [ 0 ] = V_12 -> V_28 * V_21 ;
V_14 . V_32 = F_6 ( V_12 -> V_26 ,
V_12 -> V_33 ) ;
V_24 = V_14 . V_31 [ 0 ] * V_14 . V_29 ;
V_18 = F_7 ( V_16 , V_24 , true ) ;
if ( F_8 ( V_18 ) )
return - V_34 ;
V_9 -> V_10 = & V_18 -> V_35 ;
V_23 = F_9 ( V_6 ) ;
if ( F_8 ( V_23 ) ) {
F_10 ( V_16 -> V_16 , L_1 ) ;
V_25 = F_11 ( V_23 ) ;
goto V_36;
}
V_6 -> V_20 = F_12 ( V_16 , & V_14 ,
V_9 -> V_10 ) ;
if ( F_8 ( V_6 -> V_20 ) ) {
F_10 ( V_16 -> V_16 , L_2 ) ;
V_25 = F_11 ( V_6 -> V_20 ) ;
goto V_37;
}
V_23 -> V_7 = V_6 ;
V_23 -> V_38 = V_39 ;
V_23 -> V_40 = & V_41 ;
V_20 = V_6 -> V_20 ;
F_13 ( V_23 , V_20 -> V_31 [ 0 ] , V_20 -> V_42 -> V_43 ) ;
F_14 ( V_23 , V_6 , V_12 -> V_44 , V_12 -> V_45 ) ;
V_22 = V_23 -> V_46 . V_47 * V_21 ;
V_22 += V_23 -> V_46 . V_48 * V_20 -> V_31 [ 0 ] ;
V_16 -> V_49 . V_50 = 0 ;
V_23 -> V_51 = V_18 -> V_52 + V_22 ;
V_23 -> V_53 = V_18 -> V_35 . V_24 ;
V_23 -> V_54 . V_55 = V_18 -> V_35 . V_24 ;
F_15 ( L_3 ,
V_20 -> V_27 , V_20 -> V_29 , V_20 -> V_42 -> V_43 ,
V_18 -> V_52 ,
V_22 , V_24 ) ;
V_23 -> V_56 = true ;
return 0 ;
V_37:
F_16 ( V_6 ) ;
V_36:
F_17 ( & V_18 -> V_35 ) ;
return V_25 ;
}
int F_18 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = V_16 -> V_57 ;
struct V_5 * V_6 ;
int V_25 ;
if ( ! V_16 -> V_49 . V_58 || ! V_16 -> V_49 . V_59 )
return - V_60 ;
V_6 = & V_9 -> V_61 ;
F_19 ( V_16 , V_6 , & V_62 ) ;
V_25 = F_20 ( V_16 , V_6 , V_63 ) ;
if ( V_25 < 0 ) {
F_10 ( V_16 -> V_16 , L_4 ,
V_25 ) ;
return V_25 ;
}
V_25 = F_21 ( V_6 ) ;
if ( V_25 < 0 ) {
F_10 ( V_16 -> V_16 , L_5 , V_25 ) ;
goto V_64;
}
V_25 = F_22 ( V_6 , V_65 ) ;
if ( V_25 < 0 ) {
F_10 ( V_16 -> V_16 , L_6 ,
V_25 ) ;
goto V_64;
}
return 0 ;
V_64:
F_23 ( V_6 ) ;
return V_25 ;
}
void F_24 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = V_16 -> V_57 ;
struct V_5 * V_6 ;
V_6 = & V_9 -> V_61 ;
F_25 ( V_6 ) ;
F_16 ( V_6 ) ;
if ( V_6 -> V_20 )
F_26 ( V_6 -> V_20 ) ;
F_23 ( V_6 ) ;
}
