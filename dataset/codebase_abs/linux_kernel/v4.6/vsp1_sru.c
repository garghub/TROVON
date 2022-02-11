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
const struct V_11 * V_12 ;
T_1 V_13 ;
switch ( V_8 -> V_14 ) {
case V_15 :
V_12 = & V_16 [ V_8 -> V_17 - 1 ] ;
V_13 = F_1 ( V_2 , V_18 ) ;
V_13 &= ~ ( V_19 |
V_20 ) ;
V_13 |= V_12 -> V_21 ;
F_3 ( V_2 , V_18 , V_13 ) ;
F_3 ( V_2 , V_22 , V_12 -> V_23 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_24 * V_25 , int V_26 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
struct V_27 * V_28 ;
struct V_27 * V_29 ;
T_1 V_21 ;
int V_30 ;
V_30 = F_9 ( & V_2 -> V_4 , V_26 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! V_26 )
return 0 ;
V_28 = & V_2 -> V_4 . V_31 [ V_32 ] ;
V_29 = & V_2 -> V_4 . V_31 [ V_33 ] ;
if ( V_28 -> V_34 == V_35 )
V_21 = V_36 | V_37
| V_38 ;
else
V_21 = V_37 ;
if ( V_28 -> V_39 != V_29 -> V_39 )
V_21 |= V_40 ;
if ( V_2 -> V_4 . V_5 -> V_41 -> V_42 )
F_10 ( V_2 -> V_10 . V_43 ) ;
V_21 |= F_1 ( V_2 , V_18 )
& ( V_19 | V_20 ) ;
F_3 ( V_2 , V_18 , V_21 ) ;
if ( V_2 -> V_4 . V_5 -> V_41 -> V_42 )
F_11 ( V_2 -> V_10 . V_43 ) ;
F_3 ( V_2 , V_44 , V_45 ) ;
return 0 ;
}
static int F_12 ( struct V_24 * V_25 ,
struct V_46 * V_47 ,
struct V_48 * V_34 )
{
static const unsigned int V_49 [] = {
V_35 ,
V_50 ,
} ;
struct V_1 * V_2 = F_8 ( V_25 ) ;
struct V_27 * V_51 ;
if ( V_34 -> V_52 == V_32 ) {
if ( V_34 -> V_53 >= F_13 ( V_49 ) )
return - V_54 ;
V_34 -> V_34 = V_49 [ V_34 -> V_53 ] ;
} else {
if ( V_34 -> V_53 )
return - V_54 ;
V_51 = F_14 ( & V_2 -> V_4 , V_47 ,
V_32 , V_34 -> V_55 ) ;
V_34 -> V_34 = V_51 -> V_34 ;
}
return 0 ;
}
static int F_15 ( struct V_24 * V_25 ,
struct V_46 * V_47 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
struct V_27 * V_51 ;
V_51 = F_14 ( & V_2 -> V_4 , V_47 ,
V_32 , V_57 -> V_55 ) ;
if ( V_57 -> V_53 || V_57 -> V_34 != V_51 -> V_34 )
return - V_54 ;
if ( V_57 -> V_52 == V_32 ) {
V_57 -> V_58 = V_59 ;
V_57 -> V_60 = V_61 ;
V_57 -> V_62 = V_59 ;
V_57 -> V_63 = V_61 ;
} else {
V_57 -> V_58 = V_51 -> V_39 ;
V_57 -> V_62 = V_51 -> V_64 ;
if ( V_51 -> V_39 <= V_61 / 2 &&
V_51 -> V_64 <= V_61 / 2 ) {
V_57 -> V_60 = V_51 -> V_39 * 2 ;
V_57 -> V_63 = V_51 -> V_64 * 2 ;
} else {
V_57 -> V_60 = V_51 -> V_39 ;
V_57 -> V_63 = V_51 -> V_64 ;
}
}
return 0 ;
}
static int F_16 ( struct V_24 * V_25 , struct V_46 * V_47 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
V_66 -> V_51 = * F_14 ( & V_2 -> V_4 , V_47 , V_66 -> V_52 ,
V_66 -> V_55 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_46 * V_47 ,
unsigned int V_52 , struct V_27 * V_66 ,
enum V_67 V_55 )
{
struct V_27 * V_51 ;
unsigned int V_68 ;
unsigned int V_69 ;
switch ( V_52 ) {
case V_32 :
if ( V_66 -> V_34 != V_35 &&
V_66 -> V_34 != V_50 )
V_66 -> V_34 = V_50 ;
V_66 -> V_39 = F_18 ( V_66 -> V_39 , V_59 , V_61 ) ;
V_66 -> V_64 = F_18 ( V_66 -> V_64 , V_59 , V_61 ) ;
break;
case V_33 :
V_51 = F_14 ( & V_2 -> V_4 , V_47 ,
V_32 , V_55 ) ;
V_66 -> V_34 = V_51 -> V_34 ;
V_68 = V_51 -> V_39 * V_51 -> V_64 ;
V_69 = F_19 ( V_66 -> V_39 , V_61 )
* F_19 ( V_66 -> V_64 , V_61 ) ;
if ( V_66 -> V_39 <= V_61 / 2 &&
V_66 -> V_64 <= V_61 / 2 &&
V_69 > V_68 * 9 / 4 ) {
V_66 -> V_39 = V_51 -> V_39 * 2 ;
V_66 -> V_64 = V_51 -> V_64 * 2 ;
} else {
V_66 -> V_39 = V_51 -> V_39 ;
V_66 -> V_64 = V_51 -> V_64 ;
}
break;
}
V_66 -> V_70 = V_71 ;
V_66 -> V_72 = V_73 ;
}
static int F_20 ( struct V_24 * V_25 , struct V_46 * V_47 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
struct V_27 * V_51 ;
F_17 ( V_2 , V_47 , V_66 -> V_52 , & V_66 -> V_51 , V_66 -> V_55 ) ;
V_51 = F_14 ( & V_2 -> V_4 , V_47 , V_66 -> V_52 ,
V_66 -> V_55 ) ;
* V_51 = V_66 -> V_51 ;
if ( V_66 -> V_52 == V_32 ) {
V_51 = F_14 ( & V_2 -> V_4 , V_47 ,
V_33 , V_66 -> V_55 ) ;
* V_51 = V_66 -> V_51 ;
F_17 ( V_2 , V_47 , V_33 , V_51 , V_66 -> V_55 ) ;
}
return 0 ;
}
struct V_1 * F_21 ( struct V_74 * V_5 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_22 ( V_5 -> V_75 , sizeof( * V_2 ) , V_76 ) ;
if ( V_2 == NULL )
return F_23 ( - V_77 ) ;
V_2 -> V_4 . type = V_78 ;
V_30 = F_24 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_30 < 0 )
return F_23 ( V_30 ) ;
V_25 = & V_2 -> V_4 . V_25 ;
F_25 ( V_25 , & V_79 ) ;
V_25 -> V_4 . V_80 = & V_5 -> V_81 ;
V_25 -> V_82 = & V_83 ;
snprintf ( V_25 -> V_84 , sizeof( V_25 -> V_84 ) , L_1 ,
F_26 ( V_5 -> V_75 ) ) ;
F_27 ( V_25 , V_2 ) ;
V_25 -> V_85 |= V_86 ;
F_28 ( V_25 , NULL ) ;
F_29 ( & V_2 -> V_10 , 1 ) ;
F_30 ( & V_2 -> V_10 , & V_87 , NULL ) ;
V_2 -> V_4 . V_25 . V_88 = & V_2 -> V_10 ;
if ( V_2 -> V_10 . error ) {
F_31 ( V_5 -> V_75 , L_2 ) ;
V_30 = V_2 -> V_10 . error ;
F_32 ( & V_2 -> V_4 ) ;
return F_23 ( V_30 ) ;
}
return V_2 ;
}
