void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( & F_3 ( V_2 ) -> V_6 . V_7 ,
V_3 & ( V_2 -> V_8 . V_9 - 1 ) ) ;
if ( ! V_5 ) {
F_4 ( V_2 , L_1 , V_3 ) ;
return;
}
++ V_5 -> V_10 ;
V_5 -> V_11 ( V_5 ) ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 , int V_12 )
{
struct V_13 * V_6 = & F_3 ( V_2 ) -> V_6 ;
struct V_4 * V_5 ;
F_6 ( & V_6 -> V_14 ) ;
V_5 = F_2 ( & V_6 -> V_7 , V_3 & ( V_2 -> V_8 . V_9 - 1 ) ) ;
if ( V_5 )
F_7 ( & V_5 -> V_15 ) ;
F_8 ( & V_6 -> V_14 ) ;
if ( ! V_5 ) {
F_4 ( V_2 , L_2 , V_3 ) ;
return;
}
V_5 -> V_16 ( V_5 , V_12 ) ;
if ( F_9 ( & V_5 -> V_15 ) )
F_10 ( & V_5 -> free ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_17 * V_18 ,
int V_19 )
{
return F_12 ( V_2 , V_18 -> V_20 , V_19 , 0 , V_21 ,
V_22 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_17 * V_18 ,
int V_19 , T_1 V_23 )
{
return F_12 ( V_2 , V_18 -> V_20 , V_19 , V_23 , V_24 ,
V_22 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_17 * V_18 ,
int V_19 )
{
return F_15 ( V_2 , 0 , V_18 ? V_18 -> V_20 : 0 , V_19 ,
V_18 ? 0 : 1 , V_25 ,
V_22 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_4 * V_5 ,
T_2 V_26 , T_2 V_27 )
{
struct V_17 * V_18 ;
struct V_28 * V_29 ;
int V_30 ;
V_18 = F_17 ( V_2 ) ;
if ( F_18 ( V_18 ) )
return F_19 ( V_18 ) ;
V_29 = V_18 -> V_31 ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
V_29 -> V_32 = F_20 ( V_26 ) ;
V_29 -> V_33 = F_20 ( V_27 ) ;
V_30 = F_13 ( V_2 , V_18 , V_5 -> V_3 , 1 ) ;
F_21 ( V_2 , V_18 ) ;
return V_30 ;
}
int F_22 ( struct V_1 * V_2 , struct V_4 * V_5 ,
int V_34 , struct V_35 * V_36 )
{
struct V_17 * V_18 ;
struct V_28 * V_29 ;
T_3 V_37 ;
int V_30 ;
V_18 = F_17 ( V_2 ) ;
if ( F_18 ( V_18 ) )
return F_19 ( V_18 ) ;
V_29 = V_18 -> V_31 ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
V_29 -> V_38 = F_23 ( F_24 ( V_34 ) << 24 ) ;
V_29 -> V_39 = V_36 -> V_40 - 12 ;
V_37 = F_25 ( V_2 , V_36 ) ;
V_29 -> V_41 = V_37 >> 32 ;
V_29 -> V_42 = F_23 ( V_37 & 0xffffffff ) ;
V_30 = F_13 ( V_2 , V_18 , V_5 -> V_3 , 0 ) ;
F_21 ( V_2 , V_18 ) ;
return V_30 ;
}
int F_26 ( struct V_1 * V_2 , int V_43 , struct V_35 * V_36 ,
struct V_44 * V_45 , T_3 V_46 , struct V_4 * V_5 ,
unsigned V_47 , int V_48 )
{
struct F_3 * V_49 = F_3 ( V_2 ) ;
struct V_13 * V_6 = & V_49 -> V_6 ;
struct V_17 * V_18 ;
struct V_28 * V_29 ;
T_3 V_37 ;
int V_30 ;
if ( V_47 > V_2 -> V_8 . V_50 + V_2 -> V_8 . V_51 )
return - V_52 ;
V_5 -> V_47 = V_47 ;
V_5 -> V_3 = F_27 ( & V_6 -> V_53 ) ;
if ( V_5 -> V_3 == - 1 )
return - V_54 ;
V_30 = F_28 ( V_2 , & V_6 -> V_55 , V_5 -> V_3 ) ;
if ( V_30 )
goto V_56;
V_30 = F_28 ( V_2 , & V_6 -> V_57 , V_5 -> V_3 ) ;
if ( V_30 )
goto V_58;
F_29 ( & V_6 -> V_14 ) ;
V_30 = F_30 ( & V_6 -> V_7 , V_5 -> V_3 , V_5 ) ;
F_31 ( & V_6 -> V_14 ) ;
if ( V_30 )
goto V_59;
V_18 = F_17 ( V_2 ) ;
if ( F_18 ( V_18 ) ) {
V_30 = F_19 ( V_18 ) ;
goto V_60;
}
V_29 = V_18 -> V_31 ;
memset ( V_29 , 0 , sizeof *V_29 ) ;
V_29 -> V_61 = F_23 ( ! ! V_48 << 18 ) ;
V_29 -> V_38 = F_23 ( ( F_24 ( V_43 ) << 24 ) | V_45 -> V_62 ) ;
V_29 -> V_63 = V_49 -> V_64 . V_65 [ V_47 ] . V_66 ;
V_29 -> V_39 = V_36 -> V_40 - V_67 ;
V_37 = F_25 ( V_2 , V_36 ) ;
V_29 -> V_41 = V_37 >> 32 ;
V_29 -> V_42 = F_23 ( V_37 & 0xffffffff ) ;
V_29 -> V_68 = F_32 ( V_46 ) ;
V_30 = F_11 ( V_2 , V_18 , V_5 -> V_3 ) ;
F_21 ( V_2 , V_18 ) ;
if ( V_30 )
goto V_60;
V_5 -> V_69 = 0 ;
V_5 -> V_10 = 1 ;
V_5 -> V_45 = V_45 ;
F_33 ( & V_5 -> V_15 , 1 ) ;
F_34 ( & V_5 -> free ) ;
return 0 ;
V_60:
F_29 ( & V_6 -> V_14 ) ;
F_35 ( & V_6 -> V_7 , V_5 -> V_3 ) ;
F_31 ( & V_6 -> V_14 ) ;
V_59:
F_36 ( V_2 , & V_6 -> V_57 , V_5 -> V_3 ) ;
V_58:
F_36 ( V_2 , & V_6 -> V_55 , V_5 -> V_3 ) ;
V_56:
F_37 ( & V_6 -> V_53 , V_5 -> V_3 ) ;
return V_30 ;
}
void F_38 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct F_3 * V_49 = F_3 ( V_2 ) ;
struct V_13 * V_6 = & V_49 -> V_6 ;
int V_30 ;
V_30 = F_14 ( V_2 , NULL , V_5 -> V_3 ) ;
if ( V_30 )
F_4 ( V_2 , L_3 , V_30 , V_5 -> V_3 ) ;
F_39 ( V_49 -> V_64 . V_65 [ V_5 -> V_47 ] . V_70 ) ;
F_29 ( & V_6 -> V_14 ) ;
F_35 ( & V_6 -> V_7 , V_5 -> V_3 ) ;
F_31 ( & V_6 -> V_14 ) ;
if ( F_9 ( & V_5 -> V_15 ) )
F_10 ( & V_5 -> free ) ;
F_40 ( & V_5 -> free ) ;
F_36 ( V_2 , & V_6 -> V_55 , V_5 -> V_3 ) ;
F_37 ( & V_6 -> V_53 , V_5 -> V_3 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_13 * V_6 = & F_3 ( V_2 ) -> V_6 ;
int V_30 ;
F_42 ( & V_6 -> V_14 ) ;
F_43 ( & V_6 -> V_7 , V_71 ) ;
V_30 = F_44 ( & V_6 -> V_53 , V_2 -> V_8 . V_9 ,
V_2 -> V_8 . V_9 - 1 , V_2 -> V_8 . V_72 , 0 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
F_46 ( & F_3 ( V_2 ) -> V_6 . V_53 ) ;
}
