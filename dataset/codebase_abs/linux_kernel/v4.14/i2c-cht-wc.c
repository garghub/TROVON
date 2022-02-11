static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 , V_6 ;
F_2 ( & V_4 -> V_7 ) ;
V_5 = F_3 ( V_4 -> V_8 , V_9 , & V_6 ) ;
if ( V_5 ) {
F_4 ( & V_4 -> V_10 . V_11 , L_1 ) ;
F_5 ( & V_4 -> V_7 ) ;
return V_12 ;
}
V_6 &= ~ V_4 -> V_13 ;
V_5 = F_3 ( V_4 -> V_8 , V_14 , & V_4 -> V_15 ) ;
if ( V_5 )
V_4 -> V_16 = true ;
V_5 = F_6 ( V_4 -> V_8 , V_9 , V_6 ) ;
if ( V_5 )
F_4 ( & V_4 -> V_10 . V_11 , L_2 ) ;
if ( V_6 & V_17 ) {
V_4 -> V_16 |= ! ! ( V_6 & V_18 ) ;
V_4 -> V_19 = true ;
}
F_5 ( & V_4 -> V_7 ) ;
if ( V_6 & V_17 )
F_7 ( & V_4 -> V_20 ) ;
if ( V_6 & V_21 ) {
F_8 () ;
F_9 ( V_4 -> V_22 ) ;
F_10 () ;
}
return V_23 ;
}
static T_2 F_11 ( struct V_24 * V_4 )
{
return V_25 ;
}
static int F_12 ( struct V_24 * V_26 , T_3 V_27 ,
unsigned short V_28 , char V_29 ,
T_4 V_30 , int V_31 ,
union V_32 * V_2 )
{
struct V_3 * V_4 = F_13 ( V_26 ) ;
int V_5 ;
F_2 ( & V_4 -> V_7 ) ;
V_4 -> V_16 = false ;
V_4 -> V_19 = false ;
F_5 ( & V_4 -> V_7 ) ;
V_5 = F_6 ( V_4 -> V_8 , V_33 , V_27 ) ;
if ( V_5 )
return V_5 ;
if ( V_29 == V_34 ) {
V_5 = F_6 ( V_4 -> V_8 , V_35 , V_2 -> V_36 ) ;
if ( V_5 )
return V_5 ;
}
V_5 = F_6 ( V_4 -> V_8 , V_37 , V_30 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_4 -> V_8 , V_38 ,
( V_29 == V_34 ) ?
V_39 : V_40 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_14 ( V_4 -> V_20 , V_4 -> V_19 , F_15 ( 30 ) ) ;
if ( V_5 == 0 ) {
F_1 ( 0 , V_4 ) ;
if ( ! V_4 -> V_19 )
return - V_41 ;
}
V_5 = 0 ;
F_2 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_16 )
V_5 = - V_42 ;
else if ( V_29 == V_43 )
V_2 -> V_36 = V_4 -> V_15 ;
F_5 ( & V_4 -> V_7 ) ;
return V_5 ;
}
static void F_16 ( struct V_44 * V_2 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
F_2 ( & V_4 -> V_45 ) ;
}
static void F_18 ( struct V_44 * V_2 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
int V_5 ;
if ( V_4 -> V_13 != V_4 -> V_46 ) {
V_5 = F_6 ( V_4 -> V_8 , V_47 ,
V_4 -> V_13 ) ;
if ( V_5 == 0 )
V_4 -> V_46 = V_4 -> V_13 ;
else
F_4 ( & V_4 -> V_10 . V_11 , L_3 ) ;
}
F_5 ( & V_4 -> V_45 ) ;
}
static void F_19 ( struct V_44 * V_2 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
V_4 -> V_13 &= ~ V_21 ;
}
static void F_20 ( struct V_44 * V_2 )
{
struct V_3 * V_4 = F_17 ( V_2 ) ;
V_4 -> V_13 |= V_21 ;
}
static int F_21 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_22 ( V_49 -> V_11 . V_52 ) ;
struct V_3 * V_4 ;
struct V_53 V_54 = {
. type = L_4 ,
. V_27 = 0x6b ,
. V_55 = V_56 ,
} ;
int V_5 , V_6 , V_57 ;
V_57 = F_23 ( V_49 , 0 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_49 -> V_11 , L_5 ) ;
return - V_58 ;
}
V_4 = F_24 ( & V_49 -> V_11 , sizeof( * V_4 ) , V_59 ) ;
if ( ! V_4 )
return - V_60 ;
F_25 ( & V_4 -> V_20 ) ;
F_26 ( & V_4 -> V_7 ) ;
F_26 ( & V_4 -> V_45 ) ;
V_4 -> V_61 = V_62 ;
V_4 -> V_8 = V_51 -> V_8 ;
V_4 -> V_10 . V_63 = V_64 ;
V_4 -> V_10 . V_65 = V_66 ;
V_4 -> V_10 . V_67 = & V_68 ;
F_27 ( V_4 -> V_10 . V_69 , L_6 ,
sizeof( V_4 -> V_10 . V_69 ) ) ;
V_4 -> V_10 . V_11 . V_52 = & V_49 -> V_11 ;
V_4 -> V_46 = V_4 -> V_13 = ~ V_17 ;
V_5 = F_3 ( V_4 -> V_8 , V_14 , & V_6 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_4 -> V_8 , V_9 , ~ V_4 -> V_13 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_6 ( V_4 -> V_8 , V_47 , V_4 -> V_13 ) ;
if ( V_5 )
return V_5 ;
V_4 -> V_70 = F_28 ( V_49 -> V_11 . V_71 , 1 ,
& V_72 , NULL ) ;
if ( ! V_4 -> V_70 )
return - V_60 ;
V_4 -> V_22 = F_29 ( V_4 -> V_70 , 0 ) ;
if ( ! V_4 -> V_22 ) {
V_5 = - V_60 ;
goto V_73;
}
F_30 ( V_4 -> V_22 , V_4 ) ;
F_31 ( V_4 -> V_22 , & V_4 -> V_61 ,
V_74 ) ;
V_5 = F_32 ( & V_49 -> V_11 , V_57 , NULL ,
F_1 ,
V_75 , L_6 , V_4 ) ;
if ( V_5 )
goto V_73;
F_33 ( & V_4 -> V_10 , V_4 ) ;
V_5 = F_34 ( & V_4 -> V_10 ) ;
if ( V_5 )
goto V_73;
V_54 . V_57 = V_4 -> V_22 ;
V_4 -> V_76 = F_35 ( & V_4 -> V_10 , & V_54 ) ;
if ( ! V_4 -> V_76 ) {
V_5 = - V_60 ;
goto V_77;
}
F_36 ( V_49 , V_4 ) ;
return 0 ;
V_77:
F_37 ( & V_4 -> V_10 ) ;
V_73:
F_38 ( V_4 -> V_70 ) ;
return V_5 ;
}
static int F_39 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_40 ( V_49 ) ;
F_41 ( V_4 -> V_76 ) ;
F_37 ( & V_4 -> V_10 ) ;
F_38 ( V_4 -> V_70 ) ;
return 0 ;
}
