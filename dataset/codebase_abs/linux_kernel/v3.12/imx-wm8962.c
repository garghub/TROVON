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
struct V_13 * V_14 = V_8 -> V_15 [ 0 ] . V_14 ;
struct V_16 * V_17 = & V_18 ;
struct V_19 * V_20 = F_5 ( V_17 -> V_21 ) ;
struct V_22 * V_23 = & V_17 -> V_21 -> V_23 ;
unsigned int V_24 ;
int V_25 ;
if ( V_10 -> V_23 != V_14 -> V_23 )
return 0 ;
switch ( V_12 ) {
case V_26 :
if ( V_10 -> V_27 == V_28 ) {
if ( V_6 == V_29 )
V_24 = V_5 * 384 ;
else
V_24 = V_5 * 256 ;
V_25 = F_6 ( V_14 , V_30 ,
V_31 , V_20 -> V_32 ,
V_24 ) ;
if ( V_25 < 0 ) {
F_7 ( V_23 , L_1 , V_25 ) ;
return V_25 ;
}
V_25 = F_8 ( V_14 ,
V_33 , V_24 ,
V_34 ) ;
if ( V_25 < 0 ) {
F_7 ( V_23 , L_2 , V_25 ) ;
return V_25 ;
}
}
break;
case V_28 :
if ( V_10 -> V_27 == V_26 ) {
V_25 = F_8 ( V_14 ,
V_35 , V_20 -> V_32 ,
V_34 ) ;
if ( V_25 < 0 ) {
F_7 ( V_23 ,
L_3 ,
V_25 ) ;
return V_25 ;
}
V_25 = F_6 ( V_14 , V_30 ,
0 , 0 , 0 ) ;
if ( V_25 < 0 ) {
F_7 ( V_23 , L_4 , V_25 ) ;
return V_25 ;
}
}
break;
default:
break;
}
V_10 -> V_27 = V_12 ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = V_8 -> V_15 [ 0 ] . V_14 ;
struct V_16 * V_17 = & V_18 ;
struct V_19 * V_20 = F_5 ( V_17 -> V_21 ) ;
struct V_22 * V_23 = & V_17 -> V_21 -> V_23 ;
int V_25 ;
V_25 = F_8 ( V_14 , V_35 ,
V_20 -> V_32 , V_34 ) ;
if ( V_25 < 0 )
F_7 ( V_23 , L_5 , V_36 ) ;
return V_25 ;
}
static int F_10 ( struct V_37 * V_21 )
{
struct V_38 * V_39 = V_21 -> V_23 . V_40 ;
struct V_38 * V_41 , * V_42 ;
struct V_37 * V_43 ;
struct V_16 * V_17 = & V_18 ;
struct V_44 * V_45 ;
struct V_19 * V_20 ;
int V_46 , V_47 ;
int V_25 ;
V_17 -> V_21 = V_21 ;
V_25 = F_11 ( V_39 , L_6 , & V_46 ) ;
if ( V_25 ) {
F_7 ( & V_21 -> V_23 , L_7 ) ;
return V_25 ;
}
V_25 = F_11 ( V_39 , L_8 , & V_47 ) ;
if ( V_25 ) {
F_7 ( & V_21 -> V_23 , L_9 ) ;
return V_25 ;
}
V_46 -- ;
V_47 -- ;
V_25 = F_12 ( V_46 ,
V_48 |
F_13 ( V_47 ) |
F_14 ( V_47 ) |
V_49 |
V_50 ,
F_15 ( V_47 ) ) ;
if ( V_25 ) {
F_7 ( & V_21 -> V_23 , L_10 ) ;
return V_25 ;
}
F_12 ( V_47 ,
V_48 ,
F_15 ( V_46 ) ) ;
if ( V_25 ) {
F_7 ( & V_21 -> V_23 , L_11 ) ;
return V_25 ;
}
V_41 = F_16 ( V_21 -> V_23 . V_40 , L_12 , 0 ) ;
V_42 = F_16 ( V_21 -> V_23 . V_40 , L_13 , 0 ) ;
if ( ! V_41 || ! V_42 ) {
F_7 ( & V_21 -> V_23 , L_14 ) ;
V_25 = - V_51 ;
goto V_52;
}
V_43 = F_17 ( V_41 ) ;
if ( ! V_43 ) {
F_7 ( & V_21 -> V_23 , L_15 ) ;
V_25 = - V_51 ;
goto V_52;
}
V_45 = F_18 ( V_42 ) ;
if ( ! V_45 || ! V_45 -> V_53 ) {
F_7 ( & V_21 -> V_23 , L_16 ) ;
V_25 = - V_51 ;
goto V_52;
}
V_20 = F_19 ( & V_21 -> V_23 , sizeof( * V_20 ) , V_54 ) ;
if ( ! V_20 ) {
V_25 = - V_55 ;
goto V_52;
}
V_20 -> V_56 = F_20 ( & V_45 -> V_23 , NULL ) ;
if ( F_21 ( V_20 -> V_56 ) ) {
V_25 = F_22 ( V_20 -> V_56 ) ;
F_7 ( & V_45 -> V_23 , L_17 , V_25 ) ;
goto V_52;
}
V_20 -> V_32 = F_23 ( V_20 -> V_56 ) ;
V_25 = F_24 ( V_20 -> V_56 ) ;
if ( V_25 ) {
F_7 ( & V_45 -> V_23 , L_18 , V_25 ) ;
goto V_52;
}
V_20 -> V_57 . V_58 = L_19 ;
V_20 -> V_57 . V_59 = L_19 ;
V_20 -> V_57 . V_60 = L_20 ;
V_20 -> V_57 . V_61 = V_42 ;
V_20 -> V_57 . V_62 = F_25 ( & V_43 -> V_23 ) ;
V_20 -> V_57 . V_63 = V_41 ;
V_20 -> V_57 . V_64 = & V_65 ;
V_20 -> V_57 . V_66 = V_67 | V_68 |
V_69 ;
V_20 -> V_8 . V_23 = & V_21 -> V_23 ;
V_25 = F_26 ( & V_20 -> V_8 , L_21 ) ;
if ( V_25 )
goto V_70;
V_25 = F_27 ( & V_20 -> V_8 , L_22 ) ;
if ( V_25 )
goto V_70;
V_20 -> V_8 . V_71 = 1 ;
V_20 -> V_8 . V_72 = & V_20 -> V_57 ;
V_20 -> V_8 . V_73 = V_74 ;
V_20 -> V_8 . V_75 = F_28 ( V_74 ) ;
V_20 -> V_8 . V_76 = F_9 ;
V_20 -> V_8 . V_77 = F_4 ;
V_25 = F_29 ( & V_20 -> V_8 ) ;
if ( V_25 ) {
F_7 ( & V_21 -> V_23 , L_23 , V_25 ) ;
goto V_70;
}
F_30 ( V_21 , V_20 ) ;
F_31 ( V_41 ) ;
F_31 ( V_42 ) ;
return 0 ;
V_70:
if ( ! F_21 ( V_20 -> V_56 ) )
F_32 ( V_20 -> V_56 ) ;
V_52:
if ( V_41 )
F_31 ( V_41 ) ;
if ( V_42 )
F_31 ( V_42 ) ;
return V_25 ;
}
static int F_33 ( struct V_37 * V_21 )
{
struct V_19 * V_20 = F_5 ( V_21 ) ;
if ( ! F_21 ( V_20 -> V_56 ) )
F_32 ( V_20 -> V_56 ) ;
F_34 ( & V_20 -> V_8 ) ;
return 0 ;
}
