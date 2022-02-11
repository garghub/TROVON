static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_5 = F_2 ( V_4 ) ;
V_6 = F_3 ( V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
enum V_11 V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = & V_19 ;
struct V_20 * V_21 = F_5 ( V_8 ) ;
struct V_22 * V_23 = & V_18 -> V_24 -> V_23 ;
unsigned int V_25 ;
int V_26 ;
V_14 = F_6 ( V_8 , V_8 -> V_27 [ 0 ] . V_28 ) ;
V_16 = V_14 -> V_16 ;
if ( V_10 -> V_23 != V_16 -> V_23 )
return 0 ;
switch ( V_12 ) {
case V_29 :
if ( V_10 -> V_30 == V_31 ) {
if ( V_6 == V_32 )
V_25 = V_5 * 384 ;
else
V_25 = V_5 * 256 ;
V_26 = F_7 ( V_16 , V_33 ,
V_34 , V_21 -> V_35 ,
V_25 ) ;
if ( V_26 < 0 ) {
F_8 ( V_23 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_9 ( V_16 ,
V_36 , V_25 ,
V_37 ) ;
if ( V_26 < 0 ) {
F_8 ( V_23 , L_2 , V_26 ) ;
return V_26 ;
}
}
break;
case V_31 :
if ( V_10 -> V_30 == V_29 ) {
V_26 = F_9 ( V_16 ,
V_38 , V_21 -> V_35 ,
V_37 ) ;
if ( V_26 < 0 ) {
F_8 ( V_23 ,
L_3 ,
V_26 ) ;
return V_26 ;
}
V_26 = F_7 ( V_16 , V_33 ,
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
static int F_10 ( struct V_7 * V_8 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = & V_19 ;
struct V_20 * V_21 = F_5 ( V_8 ) ;
struct V_22 * V_23 = & V_18 -> V_24 -> V_23 ;
int V_26 ;
V_14 = F_6 ( V_8 , V_8 -> V_27 [ 0 ] . V_28 ) ;
V_16 = V_14 -> V_16 ;
V_26 = F_9 ( V_16 , V_38 ,
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
struct V_17 * V_18 = & V_19 ;
struct V_47 * V_48 ;
struct V_20 * V_21 ;
int V_49 , V_50 ;
int V_26 ;
V_18 -> V_24 = V_24 ;
V_26 = F_12 ( V_42 , L_6 , & V_49 ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_7 ) ;
return V_26 ;
}
V_26 = F_12 ( V_42 , L_8 , & V_50 ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_9 ) ;
return V_26 ;
}
V_49 -- ;
V_50 -- ;
V_26 = F_13 ( V_49 ,
V_51 |
F_14 ( V_50 ) |
F_15 ( V_50 ) |
V_52 |
V_53 ,
F_16 ( V_50 ) ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_10 ) ;
return V_26 ;
}
V_26 = F_13 ( V_50 ,
V_51 ,
F_16 ( V_49 ) ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_11 ) ;
return V_26 ;
}
V_44 = F_17 ( V_24 -> V_23 . V_43 , L_12 , 0 ) ;
V_45 = F_17 ( V_24 -> V_23 . V_43 , L_13 , 0 ) ;
if ( ! V_44 || ! V_45 ) {
F_8 ( & V_24 -> V_23 , L_14 ) ;
V_26 = - V_54 ;
goto V_55;
}
V_46 = F_18 ( V_44 ) ;
if ( ! V_46 ) {
F_8 ( & V_24 -> V_23 , L_15 ) ;
V_26 = - V_54 ;
goto V_55;
}
V_48 = F_19 ( V_45 ) ;
if ( ! V_48 || ! V_48 -> V_23 . V_56 ) {
F_8 ( & V_24 -> V_23 , L_16 ) ;
V_26 = - V_54 ;
goto V_55;
}
V_21 = F_20 ( & V_24 -> V_23 , sizeof( * V_21 ) , V_57 ) ;
if ( ! V_21 ) {
V_26 = - V_58 ;
goto V_55;
}
V_21 -> V_59 = F_21 ( & V_48 -> V_23 , NULL ) ;
if ( F_22 ( V_21 -> V_59 ) ) {
V_26 = F_23 ( V_21 -> V_59 ) ;
F_8 ( & V_48 -> V_23 , L_17 , V_26 ) ;
goto V_55;
}
V_21 -> V_35 = F_24 ( V_21 -> V_59 ) ;
V_26 = F_25 ( V_21 -> V_59 ) ;
if ( V_26 ) {
F_8 ( & V_48 -> V_23 , L_18 , V_26 ) ;
goto V_55;
}
V_21 -> V_60 . V_28 = L_19 ;
V_21 -> V_60 . V_61 = L_19 ;
V_21 -> V_60 . V_62 = L_20 ;
V_21 -> V_60 . V_63 = V_45 ;
V_21 -> V_60 . V_64 = F_26 ( & V_46 -> V_23 ) ;
V_21 -> V_60 . V_65 = V_44 ;
V_21 -> V_60 . V_66 = & V_67 ;
V_21 -> V_60 . V_68 = V_69 | V_70 |
V_71 ;
V_21 -> V_8 . V_23 = & V_24 -> V_23 ;
V_26 = F_27 ( & V_21 -> V_8 , L_21 ) ;
if ( V_26 )
goto V_72;
V_26 = F_28 ( & V_21 -> V_8 , L_22 ) ;
if ( V_26 )
goto V_72;
V_21 -> V_8 . V_73 = 1 ;
V_21 -> V_8 . V_74 = V_75 ;
V_21 -> V_8 . V_27 = & V_21 -> V_60 ;
V_21 -> V_8 . V_76 = V_77 ;
V_21 -> V_8 . V_78 = F_29 ( V_77 ) ;
V_21 -> V_8 . V_79 = F_10 ;
V_21 -> V_8 . V_80 = F_4 ;
F_30 ( V_24 , & V_21 -> V_8 ) ;
F_31 ( & V_21 -> V_8 , V_21 ) ;
V_26 = F_32 ( & V_24 -> V_23 , & V_21 -> V_8 ) ;
if ( V_26 ) {
F_8 ( & V_24 -> V_23 , L_23 , V_26 ) ;
goto V_72;
}
F_33 ( V_44 ) ;
F_33 ( V_45 ) ;
return 0 ;
V_72:
F_34 ( V_21 -> V_59 ) ;
V_55:
F_33 ( V_44 ) ;
F_33 ( V_45 ) ;
return V_26 ;
}
static int F_35 ( struct V_40 * V_24 )
{
struct V_7 * V_8 = F_36 ( V_24 ) ;
struct V_20 * V_21 = F_5 ( V_8 ) ;
if ( ! F_22 ( V_21 -> V_59 ) )
F_34 ( V_21 -> V_59 ) ;
return 0 ;
}
