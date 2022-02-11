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
int V_29 = 0 ;
V_26 = F_10 ( & V_2 -> V_30 , V_18 , V_25 -> V_31 ) ;
if ( ! V_26 )
return - V_32 ;
V_28 = F_11 ( & V_2 -> V_30 , V_26 , V_33 ) ;
F_12 ( & V_2 -> V_30 . V_34 ) ;
if ( V_25 -> V_35 || V_25 -> V_20 != V_28 -> V_20 ) {
V_29 = - V_32 ;
goto V_36;
}
if ( V_25 -> V_37 == V_33 ) {
V_25 -> V_38 = V_39 ;
V_25 -> V_40 = V_41 ;
V_25 -> V_42 = V_39 ;
V_25 -> V_43 = V_41 ;
} else {
V_25 -> V_38 = V_28 -> V_44 ;
V_25 -> V_42 = V_28 -> V_45 ;
if ( V_28 -> V_44 <= V_41 / 2 &&
V_28 -> V_45 <= V_41 / 2 ) {
V_25 -> V_40 = V_28 -> V_44 * 2 ;
V_25 -> V_43 = V_28 -> V_45 * 2 ;
} else {
V_25 -> V_40 = V_28 -> V_44 ;
V_25 -> V_43 = V_28 -> V_45 ;
}
}
V_36:
F_13 ( & V_2 -> V_30 . V_34 ) ;
return V_29 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_17 * V_26 ,
unsigned int V_37 , struct V_27 * V_46 )
{
struct V_27 * V_28 ;
unsigned int V_47 ;
unsigned int V_48 ;
switch ( V_37 ) {
case V_33 :
if ( V_46 -> V_20 != V_22 &&
V_46 -> V_20 != V_23 )
V_46 -> V_20 = V_23 ;
V_46 -> V_44 = F_15 ( V_46 -> V_44 , V_39 , V_41 ) ;
V_46 -> V_45 = F_15 ( V_46 -> V_45 , V_39 , V_41 ) ;
break;
case V_49 :
V_28 = F_11 ( & V_2 -> V_30 , V_26 ,
V_33 ) ;
V_46 -> V_20 = V_28 -> V_20 ;
V_47 = V_28 -> V_44 * V_28 -> V_45 ;
V_48 = F_16 ( V_46 -> V_44 , V_41 )
* F_16 ( V_46 -> V_45 , V_41 ) ;
if ( V_46 -> V_44 <= V_41 / 2 &&
V_46 -> V_45 <= V_41 / 2 &&
V_48 > V_47 * 9 / 4 ) {
V_46 -> V_44 = V_28 -> V_44 * 2 ;
V_46 -> V_45 = V_28 -> V_45 * 2 ;
} else {
V_46 -> V_44 = V_28 -> V_44 ;
V_46 -> V_45 = V_28 -> V_45 ;
}
break;
}
V_46 -> V_50 = V_51 ;
V_46 -> V_52 = V_53 ;
}
static int F_17 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_54 * V_46 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_17 * V_26 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
F_12 ( & V_2 -> V_30 . V_34 ) ;
V_26 = F_10 ( & V_2 -> V_30 , V_18 , V_46 -> V_31 ) ;
if ( ! V_26 ) {
V_29 = - V_32 ;
goto V_36;
}
F_14 ( V_2 , V_26 , V_46 -> V_37 , & V_46 -> V_28 ) ;
V_28 = F_11 ( & V_2 -> V_30 , V_26 , V_46 -> V_37 ) ;
* V_28 = V_46 -> V_28 ;
if ( V_46 -> V_37 == V_33 ) {
V_28 = F_11 ( & V_2 -> V_30 , V_26 ,
V_49 ) ;
* V_28 = V_46 -> V_28 ;
F_14 ( V_2 , V_26 , V_49 , V_28 ) ;
}
V_36:
F_13 ( & V_2 -> V_30 . V_34 ) ;
return V_29 ;
}
static void F_18 ( struct V_55 * V_30 ,
struct V_56 * V_57 ,
struct V_3 * V_4 ,
enum V_58 V_59 )
{
const struct V_60 * V_61 ;
struct V_1 * V_2 = F_9 ( & V_30 -> V_16 ) ;
struct V_27 * V_62 ;
struct V_27 * V_63 ;
T_1 V_64 ;
if ( V_59 != V_65 )
return;
V_62 = F_11 ( & V_2 -> V_30 , V_2 -> V_30 . V_26 ,
V_33 ) ;
V_63 = F_11 ( & V_2 -> V_30 , V_2 -> V_30 . V_26 ,
V_49 ) ;
if ( V_62 -> V_20 == V_22 )
V_64 = V_66 | V_67
| V_68 ;
else
V_64 = V_67 ;
if ( V_62 -> V_44 != V_63 -> V_44 )
V_64 |= V_69 ;
V_61 = & V_70 [ V_2 -> V_13 - 1 ] ;
V_64 |= V_61 -> V_64 ;
F_1 ( V_2 , V_4 , V_71 , V_64 ) ;
F_1 ( V_2 , V_4 , V_72 , V_73 ) ;
F_1 ( V_2 , V_4 , V_74 , V_61 -> V_75 ) ;
}
static unsigned int F_19 ( struct V_55 * V_30 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_9 ( & V_30 -> V_16 ) ;
struct V_27 * V_62 ;
struct V_27 * V_63 ;
V_62 = F_11 ( & V_2 -> V_30 , V_2 -> V_30 . V_26 ,
V_33 ) ;
V_63 = F_11 ( & V_2 -> V_30 , V_2 -> V_30 . V_26 ,
V_49 ) ;
if ( V_62 -> V_44 != V_63 -> V_44 )
return 512 ;
else
return 256 ;
}
static void F_20 ( struct V_55 * V_30 ,
struct V_56 * V_57 ,
struct V_76 * V_77 ,
unsigned int V_78 ,
struct V_79 * V_80 )
{
struct V_1 * V_2 = F_9 ( & V_30 -> V_16 ) ;
struct V_27 * V_62 ;
struct V_27 * V_63 ;
V_62 = F_11 ( & V_2 -> V_30 , V_2 -> V_30 . V_26 ,
V_33 ) ;
V_63 = F_11 ( & V_2 -> V_30 , V_2 -> V_30 . V_26 ,
V_49 ) ;
if ( V_62 -> V_44 != V_63 -> V_44 ) {
V_80 -> V_44 /= 2 ;
V_80 -> V_81 /= 2 ;
}
V_77 -> V_2 = * V_80 ;
}
struct V_1 * F_21 ( struct V_82 * V_83 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_22 ( V_83 -> V_84 , sizeof( * V_2 ) , V_85 ) ;
if ( V_2 == NULL )
return F_23 ( - V_86 ) ;
V_2 -> V_30 . V_87 = & V_88 ;
V_2 -> V_30 . type = V_89 ;
V_29 = F_24 ( V_83 , & V_2 -> V_30 , L_1 , 2 , & V_90 ,
V_91 ) ;
if ( V_29 < 0 )
return F_23 ( V_29 ) ;
F_25 ( & V_2 -> V_10 , 1 ) ;
F_26 ( & V_2 -> V_10 , & V_92 , NULL ) ;
V_2 -> V_13 = 1 ;
V_2 -> V_30 . V_16 . V_93 = & V_2 -> V_10 ;
if ( V_2 -> V_10 . error ) {
F_27 ( V_83 -> V_84 , L_2 ) ;
V_29 = V_2 -> V_10 . error ;
F_28 ( & V_2 -> V_30 ) ;
return F_23 ( V_29 ) ;
}
return V_2 ;
}
