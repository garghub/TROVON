static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_6 -> V_10 ) ;
V_9 -> V_11 = F_3 ( V_4 ) ;
V_9 -> V_12 = F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_13 * V_10 ,
struct V_14 * V_15 ,
enum V_16 V_17 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
struct V_20 * V_21 = F_2 ( V_10 ) ;
struct V_22 * V_23 = & V_9 -> V_24 -> V_23 ;
unsigned int V_25 ;
int V_26 ;
V_6 = F_6 ( V_10 , V_10 -> V_27 [ 0 ] . V_28 ) ;
V_19 = V_6 -> V_19 ;
if ( V_15 -> V_23 != V_19 -> V_23 )
return 0 ;
switch ( V_17 ) {
case V_29 :
if ( V_15 -> V_30 == V_31 ) {
if ( V_9 -> V_12 == V_32 )
V_25 = V_9 -> V_11 * 384 ;
else
V_25 = V_9 -> V_11 * 256 ;
V_26 = F_7 ( V_19 , V_33 ,
V_34 , V_21 -> V_35 ,
V_25 ) ;
if ( V_26 < 0 ) {
F_8 ( V_23 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_9 ( V_19 ,
V_36 , V_25 ,
V_37 ) ;
if ( V_26 < 0 ) {
F_8 ( V_23 , L_2 , V_26 ) ;
return V_26 ;
}
}
break;
case V_31 :
if ( V_15 -> V_30 == V_29 ) {
V_26 = F_9 ( V_19 ,
V_38 , V_21 -> V_35 ,
V_37 ) ;
if ( V_26 < 0 ) {
F_8 ( V_23 ,
L_3 ,
V_26 ) ;
return V_26 ;
}
V_26 = F_7 ( V_19 , V_33 ,
0 , 0 , 0 ) ;
if ( V_26 < 0 ) {
F_8 ( V_23 , L_4 , V_26 ) ;
return V_26 ;
}
}
break;
default:
break;
}
return 0 ;
}
static int F_10 ( struct V_13 * V_10 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 ;
struct V_8 * V_9 = F_2 ( V_10 ) ;
struct V_20 * V_21 = F_2 ( V_10 ) ;
struct V_22 * V_23 = & V_9 -> V_24 -> V_23 ;
int V_26 ;
V_6 = F_6 ( V_10 , V_10 -> V_27 [ 0 ] . V_28 ) ;
V_19 = V_6 -> V_19 ;
V_26 = F_9 ( V_19 , V_38 ,
V_21 -> V_35 , V_37 ) ;
if ( V_26 < 0 )
F_8 ( V_23 , L_5 , V_39 ) ;
return V_26 ;
}
static int F_11 ( struct V_40 * V_24 )
{
struct V_41 * V_42 = V_24 -> V_23 . V_43 ;
struct V_41 * V_44 , * V_45 ;
struct V_40 * V_46 ;
struct V_47 * V_48 ;
struct V_20 * V_21 ;
struct V_8 * V_9 ;
struct V_49 * V_50 ;
int V_51 , V_52 ;
int V_26 ;
V_9 = F_12 ( & V_24 -> V_23 , sizeof( * V_9 ) , V_53 ) ;
if ( ! V_9 )
return - V_54 ;
V_9 -> V_24 = V_24 ;
V_9 -> V_11 = 44100 ;
V_9 -> V_12 = V_55 ;
V_26 = F_13 ( V_42 , L_6 , & V_51 ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_7 ) ;
return V_26 ;
}
V_26 = F_13 ( V_42 , L_8 , & V_52 ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_9 ) ;
return V_26 ;
}
V_51 -- ;
V_52 -- ;
V_26 = F_14 ( V_51 ,
V_56 |
F_15 ( V_52 ) |
F_16 ( V_52 ) |
V_57 |
V_58 ,
F_17 ( V_52 ) ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_10 ) ;
return V_26 ;
}
V_26 = F_14 ( V_52 ,
V_56 ,
F_17 ( V_51 ) ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_11 ) ;
return V_26 ;
}
V_44 = F_18 ( V_24 -> V_23 . V_43 , L_12 , 0 ) ;
V_45 = F_18 ( V_24 -> V_23 . V_43 , L_13 , 0 ) ;
if ( ! V_44 || ! V_45 ) {
F_8 ( & V_24 -> V_23 , L_14 ) ;
V_26 = - V_59 ;
goto V_60;
}
V_46 = F_19 ( V_44 ) ;
if ( ! V_46 ) {
F_8 ( & V_24 -> V_23 , L_15 ) ;
V_26 = - V_59 ;
goto V_60;
}
V_48 = F_20 ( V_45 ) ;
if ( ! V_48 || ! V_48 -> V_23 . V_61 ) {
F_8 ( & V_24 -> V_23 , L_16 ) ;
V_26 = - V_59 ;
goto V_60;
}
V_21 = F_12 ( & V_24 -> V_23 , sizeof( * V_21 ) , V_53 ) ;
if ( ! V_21 ) {
V_26 = - V_54 ;
goto V_60;
}
V_50 = F_21 ( & V_48 -> V_23 , NULL ) ;
if ( F_22 ( V_50 ) ) {
V_26 = F_23 ( V_50 ) ;
F_8 ( & V_48 -> V_23 , L_17 , V_26 ) ;
goto V_60;
}
V_21 -> V_35 = F_24 ( V_50 ) ;
F_25 ( V_50 ) ;
V_21 -> V_62 . V_28 = L_18 ;
V_21 -> V_62 . V_63 = L_18 ;
V_21 -> V_62 . V_64 = L_19 ;
V_21 -> V_62 . V_65 = V_45 ;
V_21 -> V_62 . V_66 = F_26 ( & V_46 -> V_23 ) ;
V_21 -> V_62 . V_67 = V_44 ;
V_21 -> V_62 . V_68 = & V_69 ;
V_21 -> V_62 . V_70 = V_71 | V_72 |
V_73 ;
V_21 -> V_10 . V_23 = & V_24 -> V_23 ;
V_26 = F_27 ( & V_21 -> V_10 , L_20 ) ;
if ( V_26 )
goto V_60;
V_26 = F_28 ( & V_21 -> V_10 , L_21 ) ;
if ( V_26 )
goto V_60;
V_21 -> V_10 . V_74 = 1 ;
V_21 -> V_10 . V_75 = V_76 ;
V_21 -> V_10 . V_27 = & V_21 -> V_62 ;
V_21 -> V_10 . V_77 = V_78 ;
V_21 -> V_10 . V_79 = F_29 ( V_78 ) ;
V_21 -> V_10 . V_80 = F_10 ;
V_21 -> V_10 . V_81 = F_5 ;
F_30 ( V_24 , & V_21 -> V_10 ) ;
F_31 ( & V_21 -> V_10 , V_21 ) ;
V_26 = F_32 ( & V_24 -> V_23 , & V_21 -> V_10 ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_22 , V_26 ) ;
goto V_60;
}
V_60:
F_33 ( V_44 ) ;
F_33 ( V_45 ) ;
return V_26 ;
}
