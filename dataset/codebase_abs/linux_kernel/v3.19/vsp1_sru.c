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
F_10 ( V_2 -> V_10 . V_41 ) ;
V_21 |= F_1 ( V_2 , V_18 )
& ( V_19 | V_20 ) ;
F_11 ( V_2 -> V_10 . V_41 ) ;
F_3 ( V_2 , V_42 , V_43 ) ;
return 0 ;
}
static int F_12 ( struct V_24 * V_25 ,
struct V_44 * V_45 ,
struct V_46 * V_34 )
{
static const unsigned int V_47 [] = {
V_35 ,
V_48 ,
} ;
struct V_27 * V_49 ;
if ( V_34 -> V_50 == V_32 ) {
if ( V_34 -> V_51 >= F_13 ( V_47 ) )
return - V_52 ;
V_34 -> V_34 = V_47 [ V_34 -> V_51 ] ;
} else {
if ( V_34 -> V_51 )
return - V_52 ;
V_49 = F_14 ( V_45 , V_32 ) ;
V_34 -> V_34 = V_49 -> V_34 ;
}
return 0 ;
}
static int F_15 ( struct V_24 * V_25 ,
struct V_44 * V_45 ,
struct V_53 * V_54 )
{
struct V_27 * V_49 ;
V_49 = F_14 ( V_45 , V_32 ) ;
if ( V_54 -> V_51 || V_54 -> V_34 != V_49 -> V_34 )
return - V_52 ;
if ( V_54 -> V_50 == V_32 ) {
V_54 -> V_55 = V_56 ;
V_54 -> V_57 = V_58 ;
V_54 -> V_59 = V_56 ;
V_54 -> V_60 = V_58 ;
} else {
V_54 -> V_55 = V_49 -> V_39 ;
V_54 -> V_59 = V_49 -> V_61 ;
if ( V_49 -> V_39 <= V_58 / 2 &&
V_49 -> V_61 <= V_58 / 2 ) {
V_54 -> V_57 = V_49 -> V_39 * 2 ;
V_54 -> V_60 = V_49 -> V_61 * 2 ;
} else {
V_54 -> V_57 = V_49 -> V_39 ;
V_54 -> V_60 = V_49 -> V_61 ;
}
}
return 0 ;
}
static int F_16 ( struct V_24 * V_25 , struct V_44 * V_45 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
V_63 -> V_49 = * F_17 ( & V_2 -> V_4 , V_45 , V_63 -> V_50 ,
V_63 -> V_64 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_44 * V_45 ,
unsigned int V_50 , struct V_27 * V_63 ,
enum V_65 V_64 )
{
struct V_27 * V_49 ;
unsigned int V_66 ;
unsigned int V_67 ;
switch ( V_50 ) {
case V_32 :
if ( V_63 -> V_34 != V_35 &&
V_63 -> V_34 != V_48 )
V_63 -> V_34 = V_48 ;
V_63 -> V_39 = F_19 ( V_63 -> V_39 , V_56 , V_58 ) ;
V_63 -> V_61 = F_19 ( V_63 -> V_61 , V_56 , V_58 ) ;
break;
case V_33 :
V_49 = F_17 ( & V_2 -> V_4 , V_45 ,
V_32 , V_64 ) ;
V_63 -> V_34 = V_49 -> V_34 ;
V_66 = V_49 -> V_39 * V_49 -> V_61 ;
V_67 = F_20 ( V_63 -> V_39 , V_58 )
* F_20 ( V_63 -> V_61 , V_58 ) ;
if ( V_63 -> V_39 <= V_58 / 2 &&
V_63 -> V_61 <= V_58 / 2 &&
V_67 > V_66 * 9 / 4 ) {
V_63 -> V_39 = V_49 -> V_39 * 2 ;
V_63 -> V_61 = V_49 -> V_61 * 2 ;
} else {
V_63 -> V_39 = V_49 -> V_39 ;
V_63 -> V_61 = V_49 -> V_61 ;
}
break;
}
V_63 -> V_68 = V_69 ;
V_63 -> V_70 = V_71 ;
}
static int F_21 ( struct V_24 * V_25 , struct V_44 * V_45 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_8 ( V_25 ) ;
struct V_27 * V_49 ;
F_18 ( V_2 , V_45 , V_63 -> V_50 , & V_63 -> V_49 , V_63 -> V_64 ) ;
V_49 = F_17 ( & V_2 -> V_4 , V_45 , V_63 -> V_50 ,
V_63 -> V_64 ) ;
* V_49 = V_63 -> V_49 ;
if ( V_63 -> V_50 == V_32 ) {
V_49 = F_17 ( & V_2 -> V_4 , V_45 ,
V_33 , V_63 -> V_64 ) ;
* V_49 = V_63 -> V_49 ;
F_18 ( V_2 , V_45 , V_33 , V_49 , V_63 -> V_64 ) ;
}
return 0 ;
}
struct V_1 * F_22 ( struct V_72 * V_5 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_23 ( V_5 -> V_73 , sizeof( * V_2 ) , V_74 ) ;
if ( V_2 == NULL )
return F_24 ( - V_75 ) ;
V_2 -> V_4 . type = V_76 ;
V_30 = F_25 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_30 < 0 )
return F_24 ( V_30 ) ;
V_25 = & V_2 -> V_4 . V_25 ;
F_26 ( V_25 , & V_77 ) ;
V_25 -> V_4 . V_78 = & V_79 ;
V_25 -> V_80 = & V_81 ;
snprintf ( V_25 -> V_82 , sizeof( V_25 -> V_82 ) , L_1 ,
F_27 ( V_5 -> V_73 ) ) ;
F_28 ( V_25 , V_2 ) ;
V_25 -> V_83 |= V_84 ;
F_29 ( V_25 , NULL ) ;
F_30 ( & V_2 -> V_10 , 1 ) ;
F_31 ( & V_2 -> V_10 , & V_85 , NULL ) ;
V_2 -> V_4 . V_25 . V_86 = & V_2 -> V_10 ;
if ( V_2 -> V_10 . error ) {
F_32 ( V_5 -> V_73 , L_2 ) ;
V_30 = V_2 -> V_10 . error ;
F_33 ( & V_2 -> V_4 ) ;
return F_24 ( V_30 ) ;
}
return V_2 ;
}
