static int
F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
void T_1 * V_7 = V_5 -> V_8 ;
T_2 V_9 ;
if ( V_3 )
V_7 += V_10 ;
else
V_7 += V_11 ;
V_9 = F_3 ( V_7 ) ;
V_9 |= V_12 ;
F_4 ( V_9 , V_7 ) ;
F_5 ( 12 ) ;
V_9 &= ~ V_12 ;
F_4 ( V_9 , V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_16 * V_17 = V_14 -> V_17 -> V_18 ;
struct V_4 * V_19 = F_7 ( V_17 ) ;
int V_20 ;
switch ( V_15 ) {
case V_21 :
F_8 ( V_17 , L_1 ) ;
F_9 ( V_14 ) ;
if ( V_19 -> V_22 ) {
T_2 V_9 = F_3 ( V_19 -> V_8 + V_10 ) ;
V_9 |= V_23 ;
F_10 ( V_9 , V_19 -> V_8 + V_10 ) ;
}
V_20 = F_11 ( V_14 -> V_24 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_12 ( V_14 -> V_24 ) ;
if ( V_20 ) {
F_13 ( V_14 -> V_24 ) ;
return V_20 ;
}
F_14 ( V_14 , V_25 , 0xffffffff , 0x8 ) ;
F_14 ( V_14 , V_26 ,
V_27 , 0 ) ;
if ( ! V_19 -> V_28 )
F_14 ( V_14 , V_29 ,
V_30 , 0 ) ;
if ( ! F_15 ( V_14 -> V_31 -> V_32 . V_33 ) ) {
F_14 ( V_14 , V_29 ,
V_34 ,
V_34 ) ;
F_16 ( V_14 , V_35 , V_36 ,
V_36 ) ;
}
break;
case V_37 :
F_8 ( V_17 , L_2 ) ;
F_17 ( V_14 -> V_24 ) ;
F_13 ( V_14 -> V_24 ) ;
break;
default:
F_8 ( V_17 , L_3 ) ;
break;
}
return 0 ;
}
static int F_18 ( struct V_4 * V_14 ,
struct V_38 * V_39 )
{
struct V_40 * V_40 ;
struct V_16 * V_17 = & V_39 -> V_17 ;
struct V_41 args ;
T_2 V_9 ;
int V_20 ;
V_20 = F_19 ( V_17 -> V_42 , L_4 , 2 , 0 ,
& args ) ;
if ( V_20 )
return 0 ;
V_40 = F_20 ( args . V_43 ) ;
F_21 ( args . V_43 ) ;
if ( F_15 ( V_40 ) )
return F_22 ( V_40 ) ;
V_20 = F_23 ( V_40 , args . args [ 0 ] , args . args [ 1 ] ) ;
if ( V_20 )
return V_20 ;
V_14 -> V_22 = ! ! args . args [ 1 ] ;
if ( V_14 -> V_22 ) {
V_9 = F_3 ( V_14 -> V_8 + V_10 ) ;
V_9 |= V_23 ;
F_10 ( V_9 , V_14 -> V_8 + V_10 ) ;
}
return 0 ;
}
static int F_24 ( struct V_38 * V_39 )
{
struct V_4 * V_14 ;
struct V_38 * V_44 ;
struct V_45 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_20 ;
struct V_50 * V_51 , * V_52 ;
F_8 ( & V_39 -> V_17 , L_5 ) ;
V_14 = F_25 ( & V_39 -> V_17 , sizeof( * V_14 ) , V_53 ) ;
if ( ! V_14 )
return - V_54 ;
F_26 ( V_39 , V_14 ) ;
V_14 -> V_55 . V_56 = L_6 ;
V_14 -> V_55 . V_57 = V_58 ;
V_14 -> V_55 . V_59 = V_60 | V_61 |
V_62 |
V_63 ;
V_14 -> V_55 . V_64 = F_6 ;
V_47 = F_27 ( & V_39 -> V_17 , L_7 ) ;
if ( F_15 ( V_47 ) )
return F_22 ( V_47 ) ;
V_14 -> V_65 = V_45 = F_28 ( & V_39 -> V_17 , L_7 ) ;
if ( F_15 ( V_45 ) )
return F_22 ( V_45 ) ;
V_14 -> V_66 = V_45 = F_28 ( & V_39 -> V_17 , L_8 ) ;
if ( F_15 ( V_45 ) )
return F_22 ( V_45 ) ;
V_14 -> V_67 = V_45 = F_28 ( & V_39 -> V_17 , L_9 ) ;
if ( F_15 ( V_45 ) ) {
if ( F_22 ( V_45 ) == - V_68 )
return - V_68 ;
V_14 -> V_67 = NULL ;
}
V_49 = F_29 ( V_39 , V_69 , 1 ) ;
V_14 -> V_8 = F_30 ( & V_39 -> V_17 , V_49 ) ;
if ( F_15 ( V_14 -> V_8 ) )
return F_22 ( V_14 -> V_8 ) ;
V_14 -> V_6 . V_70 = V_71 ;
V_14 -> V_6 . V_72 = & V_73 ;
V_14 -> V_6 . V_42 = V_39 -> V_17 . V_42 ;
V_14 -> V_6 . V_74 = 2 ;
V_20 = F_31 ( & V_14 -> V_6 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_32 ( V_14 -> V_67 ) ;
if ( V_20 )
goto V_75;
F_33 ( V_47 ) ;
F_34 ( 10000 , 12000 ) ;
F_35 ( V_47 ) ;
F_36 ( V_14 -> V_67 ) ;
V_20 = F_32 ( V_14 -> V_65 ) ;
if ( V_20 )
goto V_75;
V_20 = F_32 ( V_14 -> V_66 ) ;
if ( V_20 )
goto V_76;
V_20 = F_18 ( V_14 , V_39 ) ;
if ( V_20 )
goto V_77;
V_51 = F_37 ( V_39 -> V_17 . V_42 , L_10 ) ;
if ( V_51 ) {
V_52 = F_38 ( V_51 , NULL ) ;
V_14 -> V_28 = F_39 ( V_52 , L_11 ) ;
F_21 ( V_52 ) ;
}
F_21 ( V_51 ) ;
V_44 = F_40 ( & V_39 -> V_17 , V_39 -> V_48 ,
V_39 -> V_78 , & V_14 -> V_55 ) ;
if ( F_15 ( V_44 ) ) {
V_20 = F_22 ( V_44 ) ;
if ( V_20 != - V_68 )
F_41 ( & V_39 -> V_17 , L_12 ) ;
goto V_77;
}
V_14 -> V_14 = V_44 ;
F_42 ( & V_39 -> V_17 ) ;
F_43 ( & V_39 -> V_17 ) ;
F_44 ( & V_39 -> V_17 ) ;
return 0 ;
V_77:
F_36 ( V_14 -> V_66 ) ;
V_76:
F_36 ( V_14 -> V_65 ) ;
V_75:
F_45 ( & V_14 -> V_6 ) ;
return V_20 ;
}
static int F_46 ( struct V_38 * V_39 )
{
struct V_4 * V_14 = F_47 ( V_39 ) ;
F_48 ( & V_39 -> V_17 ) ;
F_49 ( V_14 -> V_14 ) ;
F_36 ( V_14 -> V_66 ) ;
F_36 ( V_14 -> V_65 ) ;
F_45 ( & V_14 -> V_6 ) ;
return 0 ;
}
