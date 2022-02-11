static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 ,
V_5 ) ;
T_1 V_6 , V_7 = 0 ;
F_3 ( V_4 -> V_8 , struct V_9 ,
V_6 , & V_6 ) ;
if ( V_6 & V_10 ) {
F_4 ( V_4 ) ;
F_5 ( V_4 -> V_11 ) ;
V_7 |= V_10 ;
}
F_6 ( V_4 -> V_8 , struct V_9 ,
V_7 , & V_7 ) ;
}
static void F_7 ( struct V_12 * V_13 ,
void (* F_8)( struct V_1 * V_2 ) )
{
F_9 ( & V_13 -> V_14 ) ;
F_10 ( & V_13 -> V_15 ) ;
F_11 ( & V_13 -> V_16 , F_8 ) ;
}
int F_12 ( struct V_17 * V_18 , unsigned long V_19 )
{
static T_2 * V_20 [] = {
V_21 , V_22
} ;
static const char * V_23 [] = { L_1 , L_2 } ;
struct V_3 * V_4 ;
struct V_24 * V_25 [ 2 ] ;
T_1 V_26 ;
int V_27 ;
if ( ! F_13 ( V_18 -> V_28 , V_29 ) )
return - V_30 ;
V_4 = F_14 ( sizeof( struct V_3 ) , V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_11 = V_18 ;
V_18 -> V_33 = V_4 ;
V_4 -> V_8 = V_18 -> V_28 ;
V_4 -> V_18 = V_18 -> V_18 ;
F_9 ( & V_4 -> V_34 ) ;
F_9 ( & V_4 -> V_35 ) ;
F_15 ( & V_4 -> V_36 ) ;
F_9 ( & V_4 -> V_37 ) ;
F_15 ( & V_4 -> V_38 ) ;
F_10 ( & V_4 -> V_39 ) ;
F_7 ( & V_4 -> V_40 , V_41 ) ;
F_7 ( & V_4 -> V_42 , V_43 ) ;
F_9 ( & V_4 -> V_44 . V_45 ) ;
F_16 ( & V_4 -> V_44 . V_46 ) ;
F_11 ( & V_4 -> V_5 ,
F_1 ) ;
V_27 = V_4 -> V_8 -> V_47 -> V_48 ( V_4 -> V_8 , 2 , V_25 ,
V_20 , V_23 ) ;
if ( V_27 ) {
F_17 ( L_3 ) ;
goto V_49;
}
V_4 -> V_40 . V_50 = V_25 [ 0 ] ;
V_4 -> V_42 . V_50 = V_25 [ 1 ] ;
V_27 = F_18 ( V_4 ) ;
if ( V_27 ) {
F_17 ( L_4 ) ;
goto V_51;
}
V_27 = F_19 ( V_4 ) ;
if ( V_27 ) {
F_17 ( L_5 , V_27 ) ;
goto V_52;
}
F_3 ( V_4 -> V_8 , struct V_9 ,
V_26 , & V_26 ) ;
V_4 -> V_26 = F_20 ( V_53 , V_26 ,
V_54 ) ;
if ( ! V_4 -> V_26 ) {
F_17 ( L_6 ) ;
V_27 = - V_55 ;
goto V_56;
}
V_27 = F_21 ( V_4 ) ;
if ( V_27 )
goto V_57;
F_22 ( V_4 -> V_8 ) ;
V_4 -> V_58 = true ;
F_4 ( V_4 ) ;
F_23 ( V_4 -> V_39 , ! V_4 -> V_59 ,
5 * V_60 ) ;
if ( V_61 )
F_24 ( V_4 ) ;
return 0 ;
V_57:
V_56:
F_25 ( V_4 ) ;
V_52:
F_26 ( V_4 ) ;
V_51:
V_4 -> V_8 -> V_47 -> V_62 ( V_4 -> V_8 ) ;
V_49:
F_27 ( V_4 ) ;
return V_27 ;
}
int F_28 ( struct V_17 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_33 ;
V_4 -> V_58 = false ;
F_29 ( & V_4 -> V_40 . V_16 ) ;
F_29 ( & V_4 -> V_42 . V_16 ) ;
F_29 ( & V_4 -> V_5 ) ;
V_4 -> V_8 -> V_47 -> V_62 ( V_4 -> V_8 ) ;
F_30 ( V_4 ) ;
F_25 ( V_4 ) ;
F_26 ( V_4 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
