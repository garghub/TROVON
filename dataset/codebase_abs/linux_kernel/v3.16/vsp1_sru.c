static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_2 -> V_4 . V_5 , V_3 , V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_6 ( V_8 -> V_9 , struct V_1 , V_10 ) ;
switch ( V_8 -> V_11 ) {
case V_12 :
V_2 -> V_13 = V_8 -> V_14 ;
break;
}
return 0 ;
}
static int F_7 ( struct V_15 * V_16 , int V_17 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
const struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_20 * V_22 ;
bool V_23 ;
T_1 V_24 ;
if ( ! V_17 )
return 0 ;
V_21 = & V_2 -> V_4 . V_25 [ V_26 ] ;
V_22 = & V_2 -> V_4 . V_25 [ V_27 ] ;
V_23 = V_21 -> V_28 != V_22 -> V_28 ;
V_19 = & V_29 [ V_2 -> V_13 ] ;
if ( V_21 -> V_30 == V_31 )
V_24 = V_32 | V_33
| V_34 ;
else
V_24 = V_33 ;
F_3 ( V_2 , V_35 , V_19 -> V_24 | V_24 |
( V_23 ? V_36 : 0 ) ) ;
F_3 ( V_2 , V_37 , V_38 ) ;
F_3 ( V_2 , V_39 , V_19 -> V_40 ) ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 ,
struct V_41 * V_42 ,
struct V_43 * V_30 )
{
static const unsigned int V_44 [] = {
V_31 ,
V_45 ,
} ;
struct V_20 * V_46 ;
if ( V_30 -> V_47 == V_26 ) {
if ( V_30 -> V_48 >= F_10 ( V_44 ) )
return - V_49 ;
V_30 -> V_30 = V_44 [ V_30 -> V_48 ] ;
} else {
if ( V_30 -> V_48 )
return - V_49 ;
V_46 = F_11 ( V_42 , V_26 ) ;
V_30 -> V_30 = V_46 -> V_30 ;
}
return 0 ;
}
static int F_12 ( struct V_15 * V_16 ,
struct V_41 * V_42 ,
struct V_50 * V_51 )
{
struct V_20 * V_46 ;
V_46 = F_11 ( V_42 , V_26 ) ;
if ( V_51 -> V_48 || V_51 -> V_30 != V_46 -> V_30 )
return - V_49 ;
if ( V_51 -> V_47 == V_26 ) {
V_51 -> V_52 = V_53 ;
V_51 -> V_54 = V_55 ;
V_51 -> V_56 = V_53 ;
V_51 -> V_57 = V_55 ;
} else {
V_51 -> V_52 = V_46 -> V_28 ;
V_51 -> V_56 = V_46 -> V_58 ;
if ( V_46 -> V_28 <= V_55 / 2 &&
V_46 -> V_58 <= V_55 / 2 ) {
V_51 -> V_54 = V_46 -> V_28 * 2 ;
V_51 -> V_57 = V_46 -> V_58 * 2 ;
} else {
V_51 -> V_54 = V_46 -> V_28 ;
V_51 -> V_57 = V_46 -> V_58 ;
}
}
return 0 ;
}
static int F_13 ( struct V_15 * V_16 , struct V_41 * V_42 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
V_60 -> V_46 = * F_14 ( & V_2 -> V_4 , V_42 , V_60 -> V_47 ,
V_60 -> V_61 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_41 * V_42 ,
unsigned int V_47 , struct V_20 * V_60 ,
enum V_62 V_61 )
{
struct V_20 * V_46 ;
unsigned int V_63 ;
unsigned int V_64 ;
switch ( V_47 ) {
case V_26 :
if ( V_60 -> V_30 != V_31 &&
V_60 -> V_30 != V_45 )
V_60 -> V_30 = V_45 ;
V_60 -> V_28 = F_16 ( V_60 -> V_28 , V_53 , V_55 ) ;
V_60 -> V_58 = F_16 ( V_60 -> V_58 , V_53 , V_55 ) ;
break;
case V_27 :
V_46 = F_14 ( & V_2 -> V_4 , V_42 ,
V_26 , V_61 ) ;
V_60 -> V_30 = V_46 -> V_30 ;
V_63 = V_46 -> V_28 * V_46 -> V_58 ;
V_64 = F_17 ( V_60 -> V_28 , V_55 )
* F_17 ( V_60 -> V_58 , V_55 ) ;
if ( V_60 -> V_28 <= V_55 / 2 &&
V_60 -> V_58 <= V_55 / 2 &&
V_64 > V_63 * 9 / 4 ) {
V_60 -> V_28 = V_46 -> V_28 * 2 ;
V_60 -> V_58 = V_46 -> V_58 * 2 ;
} else {
V_60 -> V_28 = V_46 -> V_28 ;
V_60 -> V_58 = V_46 -> V_58 ;
}
break;
}
V_60 -> V_65 = V_66 ;
V_60 -> V_67 = V_68 ;
}
static int F_18 ( struct V_15 * V_16 , struct V_41 * V_42 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_8 ( V_16 ) ;
struct V_20 * V_46 ;
F_15 ( V_2 , V_42 , V_60 -> V_47 , & V_60 -> V_46 , V_60 -> V_61 ) ;
V_46 = F_14 ( & V_2 -> V_4 , V_42 , V_60 -> V_47 ,
V_60 -> V_61 ) ;
* V_46 = V_60 -> V_46 ;
if ( V_60 -> V_47 == V_26 ) {
V_46 = F_14 ( & V_2 -> V_4 , V_42 ,
V_27 , V_60 -> V_61 ) ;
* V_46 = V_60 -> V_46 ;
F_15 ( V_2 , V_42 , V_27 , V_46 , V_60 -> V_61 ) ;
}
return 0 ;
}
struct V_1 * F_19 ( struct V_69 * V_5 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_70 ;
V_2 = F_20 ( V_5 -> V_71 , sizeof( * V_2 ) , V_72 ) ;
if ( V_2 == NULL )
return F_21 ( - V_73 ) ;
V_2 -> V_4 . type = V_74 ;
V_70 = F_22 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_70 < 0 )
return F_21 ( V_70 ) ;
V_16 = & V_2 -> V_4 . V_16 ;
F_23 ( V_16 , & V_75 ) ;
V_16 -> V_4 . V_76 = & V_77 ;
V_16 -> V_78 = & V_79 ;
snprintf ( V_16 -> V_80 , sizeof( V_16 -> V_80 ) , L_1 ,
F_24 ( V_5 -> V_71 ) ) ;
F_25 ( V_16 , V_2 ) ;
V_16 -> V_81 |= V_82 ;
F_26 ( V_16 , NULL ) ;
F_27 ( & V_2 -> V_10 , 1 ) ;
F_28 ( & V_2 -> V_10 , & V_83 , NULL ) ;
F_29 ( & V_2 -> V_10 ) ;
V_2 -> V_4 . V_16 . V_84 = & V_2 -> V_10 ;
return V_2 ;
}
