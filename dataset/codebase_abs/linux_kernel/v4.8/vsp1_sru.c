static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_4 ( V_8 -> V_9 , struct V_1 , V_10 ) ;
switch ( V_8 -> V_11 ) {
case V_12 :
V_2 -> V_13 = V_8 -> V_14 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
static const unsigned int V_21 [] = {
V_22 ,
V_23 ,
} ;
return F_6 ( V_16 , V_18 , V_20 , V_21 ,
F_7 ( V_21 ) ) ;
}
static int F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_17 * V_26 ;
struct V_27 * V_28 ;
V_26 = F_10 ( & V_2 -> V_29 , V_18 , V_25 -> V_30 ) ;
if ( ! V_26 )
return - V_31 ;
V_28 = F_11 ( & V_2 -> V_29 , V_26 , V_32 ) ;
if ( V_25 -> V_33 || V_25 -> V_20 != V_28 -> V_20 )
return - V_31 ;
if ( V_25 -> V_34 == V_32 ) {
V_25 -> V_35 = V_36 ;
V_25 -> V_37 = V_38 ;
V_25 -> V_39 = V_36 ;
V_25 -> V_40 = V_38 ;
} else {
V_25 -> V_35 = V_28 -> V_41 ;
V_25 -> V_39 = V_28 -> V_42 ;
if ( V_28 -> V_41 <= V_38 / 2 &&
V_28 -> V_42 <= V_38 / 2 ) {
V_25 -> V_37 = V_28 -> V_41 * 2 ;
V_25 -> V_40 = V_28 -> V_42 * 2 ;
} else {
V_25 -> V_37 = V_28 -> V_41 ;
V_25 -> V_40 = V_28 -> V_42 ;
}
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_17 * V_26 ,
unsigned int V_34 , struct V_27 * V_43 )
{
struct V_27 * V_28 ;
unsigned int V_44 ;
unsigned int V_45 ;
switch ( V_34 ) {
case V_32 :
if ( V_43 -> V_20 != V_22 &&
V_43 -> V_20 != V_23 )
V_43 -> V_20 = V_23 ;
V_43 -> V_41 = F_13 ( V_43 -> V_41 , V_36 , V_38 ) ;
V_43 -> V_42 = F_13 ( V_43 -> V_42 , V_36 , V_38 ) ;
break;
case V_46 :
V_28 = F_11 ( & V_2 -> V_29 , V_26 ,
V_32 ) ;
V_43 -> V_20 = V_28 -> V_20 ;
V_44 = V_28 -> V_41 * V_28 -> V_42 ;
V_45 = F_14 ( V_43 -> V_41 , V_38 )
* F_14 ( V_43 -> V_42 , V_38 ) ;
if ( V_43 -> V_41 <= V_38 / 2 &&
V_43 -> V_42 <= V_38 / 2 &&
V_45 > V_44 * 9 / 4 ) {
V_43 -> V_41 = V_28 -> V_41 * 2 ;
V_43 -> V_42 = V_28 -> V_42 * 2 ;
} else {
V_43 -> V_41 = V_28 -> V_41 ;
V_43 -> V_42 = V_28 -> V_42 ;
}
break;
}
V_43 -> V_47 = V_48 ;
V_43 -> V_49 = V_50 ;
}
static int F_15 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_51 * V_43 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_17 * V_26 ;
struct V_27 * V_28 ;
V_26 = F_10 ( & V_2 -> V_29 , V_18 , V_43 -> V_30 ) ;
if ( ! V_26 )
return - V_31 ;
F_12 ( V_2 , V_26 , V_43 -> V_34 , & V_43 -> V_28 ) ;
V_28 = F_11 ( & V_2 -> V_29 , V_26 , V_43 -> V_34 ) ;
* V_28 = V_43 -> V_28 ;
if ( V_43 -> V_34 == V_32 ) {
V_28 = F_11 ( & V_2 -> V_29 , V_26 ,
V_46 ) ;
* V_28 = V_43 -> V_28 ;
F_12 ( V_2 , V_26 , V_46 , V_28 ) ;
}
return 0 ;
}
static void F_16 ( struct V_52 * V_29 ,
struct V_53 * V_54 ,
struct V_3 * V_4 , bool V_55 )
{
const struct V_56 * V_57 ;
struct V_1 * V_2 = F_9 ( & V_29 -> V_16 ) ;
struct V_27 * V_58 ;
struct V_27 * V_59 ;
T_1 V_60 ;
if ( ! V_55 )
return;
V_58 = F_11 ( & V_2 -> V_29 , V_2 -> V_29 . V_26 ,
V_32 ) ;
V_59 = F_11 ( & V_2 -> V_29 , V_2 -> V_29 . V_26 ,
V_46 ) ;
if ( V_58 -> V_20 == V_22 )
V_60 = V_61 | V_62
| V_63 ;
else
V_60 = V_62 ;
if ( V_58 -> V_41 != V_59 -> V_41 )
V_60 |= V_64 ;
V_57 = & V_65 [ V_2 -> V_13 - 1 ] ;
V_60 |= V_57 -> V_60 ;
F_1 ( V_2 , V_4 , V_66 , V_60 ) ;
F_1 ( V_2 , V_4 , V_67 , V_68 ) ;
F_1 ( V_2 , V_4 , V_69 , V_57 -> V_70 ) ;
}
struct V_1 * F_17 ( struct V_71 * V_72 )
{
struct V_1 * V_2 ;
int V_73 ;
V_2 = F_18 ( V_72 -> V_74 , sizeof( * V_2 ) , V_75 ) ;
if ( V_2 == NULL )
return F_19 ( - V_76 ) ;
V_2 -> V_29 . V_77 = & V_78 ;
V_2 -> V_29 . type = V_79 ;
V_73 = F_20 ( V_72 , & V_2 -> V_29 , L_1 , 2 , & V_80 ,
V_81 ) ;
if ( V_73 < 0 )
return F_19 ( V_73 ) ;
F_21 ( & V_2 -> V_10 , 1 ) ;
F_22 ( & V_2 -> V_10 , & V_82 , NULL ) ;
V_2 -> V_13 = 1 ;
V_2 -> V_29 . V_16 . V_83 = & V_2 -> V_10 ;
if ( V_2 -> V_10 . error ) {
F_23 ( V_72 -> V_74 , L_2 ) ;
V_73 = V_2 -> V_10 . error ;
F_24 ( & V_2 -> V_29 ) ;
return F_19 ( V_73 ) ;
}
return V_2 ;
}
