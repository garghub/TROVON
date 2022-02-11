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
V_23 = F_9 ( 0 , V_16 -> V_16 ) ;
if ( ! V_23 ) {
F_10 ( V_16 -> V_16 , L_1 ) ;
V_25 = - V_34 ;
goto V_36;
}
V_6 -> V_20 = F_11 ( V_16 , & V_14 ,
V_9 -> V_10 ) ;
if ( F_8 ( V_6 -> V_20 ) ) {
F_10 ( V_16 -> V_16 , L_2 ) ;
V_25 = F_12 ( V_6 -> V_20 ) ;
goto V_37;
}
V_6 -> V_38 = V_23 ;
V_23 -> V_7 = V_6 ;
V_23 -> V_39 = V_40 ;
V_23 -> V_41 = & V_42 ;
V_25 = F_13 ( & V_23 -> V_43 , 256 , 0 ) ;
if ( V_25 ) {
F_10 ( V_16 -> V_16 , L_3 ) ;
goto V_44;
}
V_20 = V_6 -> V_20 ;
F_14 ( V_23 , V_20 -> V_31 [ 0 ] , V_20 -> V_45 ) ;
F_15 ( V_23 , V_6 , V_12 -> V_46 , V_12 -> V_47 ) ;
V_22 = V_23 -> V_48 . V_49 * V_21 ;
V_22 += V_23 -> V_48 . V_50 * V_20 -> V_31 [ 0 ] ;
V_16 -> V_51 . V_52 = 0 ;
V_23 -> V_53 = V_18 -> V_54 + V_22 ;
V_23 -> V_55 = V_18 -> V_35 . V_24 ;
V_23 -> V_56 . V_57 = V_18 -> V_35 . V_24 ;
F_16 ( L_4 ,
V_20 -> V_27 , V_20 -> V_29 , V_20 -> V_45 , V_18 -> V_54 ,
V_22 , V_24 ) ;
V_23 -> V_58 = true ;
return 0 ;
V_44:
F_17 ( V_6 -> V_20 ) ;
V_37:
F_18 ( V_23 ) ;
V_36:
F_19 ( & V_18 -> V_35 ) ;
return V_25 ;
}
int F_20 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = V_16 -> V_59 ;
struct V_5 * V_6 ;
unsigned int V_60 ;
int V_25 ;
if ( ! V_16 -> V_51 . V_60 || ! V_16 -> V_51 . V_61 )
return - V_62 ;
V_60 = V_16 -> V_51 . V_60 ;
V_6 = & V_9 -> V_63 ;
F_21 ( V_16 , V_6 , & V_64 ) ;
V_25 = F_22 ( V_16 , V_6 , V_60 , V_65 ) ;
if ( V_25 < 0 ) {
F_10 ( V_16 -> V_16 , L_5 ,
V_25 ) ;
return V_25 ;
}
V_25 = F_23 ( V_6 ) ;
if ( V_25 < 0 ) {
F_10 ( V_16 -> V_16 , L_6 , V_25 ) ;
goto V_66;
}
F_24 ( V_16 ) ;
V_25 = F_25 ( V_6 , V_67 ) ;
if ( V_25 < 0 ) {
F_10 ( V_16 -> V_16 , L_7 ,
V_25 ) ;
goto V_66;
}
return 0 ;
V_66:
F_26 ( V_6 ) ;
return V_25 ;
}
void F_27 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = V_16 -> V_59 ;
struct V_5 * V_6 ;
V_6 = & V_9 -> V_63 ;
if ( V_6 -> V_38 ) {
struct V_1 * V_2 ;
int V_25 ;
V_2 = V_6 -> V_38 ;
V_25 = F_28 ( V_2 ) ;
if ( V_25 < 0 )
F_16 ( L_8 ,
V_25 ) ;
if ( V_2 -> V_43 . V_68 )
F_29 ( & V_2 -> V_43 ) ;
F_18 ( V_2 ) ;
}
if ( V_6 -> V_20 )
F_17 ( V_6 -> V_20 ) ;
F_26 ( V_6 ) ;
}
