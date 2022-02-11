static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_4 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 ) ;
}
static void F_5 ( struct V_2 * V_3 , int V_9 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_5 * V_11 = F_4 ( V_10 -> V_4 . V_8 ) ;
struct V_12 * V_13 ;
if ( V_9 == - 1 && V_11 -> V_14 >= 0 ) {
V_13 = & V_11 -> V_13 [ V_11 -> V_14 ] ;
F_6 ( V_11 -> V_15 , V_13 -> V_16 , false ) ;
}
V_11 -> V_14 = V_9 ;
}
static void F_7 ( struct V_2 * V_3 , int V_17 ,
unsigned int V_7 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_5 * V_11 = F_4 ( V_10 -> V_4 . V_8 ) ;
struct V_12 * V_13 ;
if ( F_8 ( V_11 -> V_14 < 0 ) )
return;
V_13 = & V_11 -> V_13 [ V_11 -> V_14 ] ;
F_6 ( V_11 -> V_15 , V_13 -> V_16 , V_7 & V_18 ) ;
if ( V_17 == V_19 )
return;
if ( V_7 & V_20 )
F_9 ( V_17 , V_13 -> V_21 + V_22 ) ;
else if ( V_7 & V_23 )
F_9 ( V_17 , V_13 -> V_21 + V_24 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
return ! F_11 ( V_10 -> V_25 ) ;
}
static void F_12 ( struct V_2 * V_3 , int V_26 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
V_10 -> V_27 = ( V_26 == V_28 ) ;
}
static int F_13 ( struct V_2 * V_3 , const T_1 * V_29 ,
T_1 * V_30 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_5 * V_11 = F_4 ( V_10 -> V_4 . V_8 ) ;
struct V_31 V_32 ;
if ( V_10 -> V_27 )
return 0 ;
V_32 . V_33 = V_10 -> V_4 . V_34 . V_33 ;
V_32 . V_35 = V_10 -> V_4 . V_34 . V_35 ;
V_32 . V_36 = V_10 -> V_4 . V_34 . V_36 ;
return F_14 ( V_11 -> V_37 , & V_32 , V_29 , V_30 ) ;
}
static int F_15 ( struct V_2 * V_3 , T_1 * V_29 ,
T_1 * V_38 , T_1 * V_39 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_5 * V_11 = F_4 ( V_10 -> V_4 . V_8 ) ;
struct V_31 V_32 ;
V_32 . V_33 = V_10 -> V_4 . V_34 . V_33 ;
V_32 . V_35 = V_10 -> V_4 . V_34 . V_35 ;
V_32 . V_36 = V_10 -> V_4 . V_34 . V_36 ;
return F_16 ( V_11 -> V_37 , & V_32 , V_29 , V_38 ) ;
}
static int F_17 ( struct V_1 * V_10 , struct V_40 * V_15 )
{
struct V_41 * V_4 = & V_10 -> V_4 ;
struct V_2 * V_3 = F_18 ( V_4 ) ;
struct V_5 * V_11 = F_4 ( V_4 -> V_8 ) ;
int V_42 ;
V_4 -> V_34 . V_35 = F_19 ( ( 1 + 8 ) * V_4 -> V_34 . V_33 ) *
( V_4 -> V_34 . V_36 / 8 ) ;
switch ( V_4 -> V_34 . V_26 ) {
case V_43 :
if ( ! V_11 -> V_37 ) {
F_20 ( V_15 , L_1 ) ;
return - V_44 ;
}
V_4 -> V_34 . V_45 = F_12 ;
V_4 -> V_34 . V_46 = F_13 ;
V_4 -> V_34 . V_47 = F_15 ;
case V_48 :
F_21 ( V_15 , L_2 ,
( V_11 -> V_37 ) ? L_3 : L_4 ,
V_4 -> V_34 . V_36 , V_4 -> V_34 . V_33 , V_4 -> V_34 . V_35 ) ;
break;
case V_49 :
F_21 ( V_15 , L_5 ) ;
break;
default:
F_20 ( V_15 , L_6 , V_4 -> V_34 . V_26 ) ;
return - V_50 ;
}
if ( V_4 -> V_34 . V_26 != V_43 )
return 0 ;
V_42 = V_3 -> V_51 / V_4 -> V_34 . V_33 * V_4 -> V_34 . V_35 ;
if ( V_42 > V_3 -> V_52 - 2 ) {
F_20 ( V_15 ,
L_7 ,
V_42 , V_3 -> V_52 - 2 ) ;
return - V_50 ;
}
V_3 -> V_53 = & V_54 ;
return 0 ;
}
static int F_22 ( struct V_55 * V_56 ,
struct V_5 * V_11 ,
struct V_57 * V_58 ,
unsigned int V_9 )
{
struct V_40 * V_15 = & V_56 -> V_15 ;
struct V_1 * V_10 ;
struct V_12 * V_13 ;
struct V_59 * V_60 ;
struct V_41 * V_4 ;
struct V_2 * V_3 ;
const T_2 * V_61 ;
int V_62 = 0 ;
V_13 = & V_11 -> V_13 [ V_9 ] ;
V_61 = F_23 ( V_58 , L_8 , NULL ) ;
if ( ! V_61 )
return - V_50 ;
V_13 -> V_16 = F_24 ( * V_61 ) ;
F_25 ( V_11 -> V_15 , V_13 -> V_16 , V_63 ) ;
V_60 = F_26 ( V_56 , V_64 , V_9 ) ;
V_13 -> V_21 = F_27 ( V_15 , V_60 ) ;
if ( F_28 ( V_13 -> V_21 ) )
return F_29 ( V_13 -> V_21 ) ;
V_10 = F_30 ( V_15 , sizeof( * V_10 ) , V_65 ) ;
if ( ! V_10 )
return - V_66 ;
V_10 -> V_25 = F_31 ( V_15 , L_9 , V_67 ) ;
if ( F_28 ( V_10 -> V_25 ) ) {
V_62 = F_29 ( V_10 -> V_25 ) ;
F_20 ( V_15 , L_10 , V_62 ) ;
return V_62 ;
} else if ( V_10 -> V_25 ) {
V_10 -> V_4 . V_68 = F_10 ;
}
V_10 -> V_69 = F_31 ( V_15 , L_11 , V_70 ) ;
if ( F_28 ( V_10 -> V_69 ) ) {
V_62 = F_29 ( V_10 -> V_69 ) ;
F_20 ( V_15 , L_12 , V_62 ) ;
return V_62 ;
}
V_4 = & V_10 -> V_4 ;
V_3 = F_18 ( V_4 ) ;
V_3 -> V_71 = F_32 ( V_15 , V_65 , L_13 , F_33 ( V_15 ) ,
V_13 -> V_16 ) ;
if ( ! V_3 -> V_71 )
return - V_66 ;
V_3 -> V_15 . V_72 = V_15 ;
V_4 -> V_73 = V_13 -> V_21 + V_74 ;
V_4 -> V_75 = V_13 -> V_21 + V_74 ;
V_4 -> V_76 = V_77 ;
V_4 -> V_78 = V_79 ;
V_4 -> V_80 = F_5 ;
V_4 -> V_81 = F_7 ;
V_4 -> V_34 . V_26 = V_43 ;
V_4 -> V_8 = & V_11 -> V_8 ;
F_34 ( V_4 , V_58 ) ;
V_62 = F_35 ( V_3 , 1 , NULL ) ;
if ( V_62 )
return V_62 ;
V_62 = F_17 ( V_10 , V_15 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_36 ( V_3 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_37 ( V_3 , NULL , 0 ) ;
if ( V_62 ) {
F_38 ( V_3 ) ;
return V_62 ;
}
F_39 ( & V_10 -> V_82 , & V_11 -> V_83 ) ;
return 0 ;
}
static void F_40 ( struct V_5 * V_11 )
{
struct V_1 * V_4 ;
while ( ! F_41 ( & V_11 -> V_83 ) ) {
V_4 = F_42 ( & V_11 -> V_83 , struct V_1 , V_82 ) ;
F_38 ( F_18 ( & V_4 -> V_4 ) ) ;
F_43 ( & V_4 -> V_82 ) ;
}
}
static int F_44 ( struct V_5 * V_11 ,
struct V_55 * V_56 )
{
struct V_40 * V_15 = & V_56 -> V_15 ;
struct V_57 * V_58 ;
int V_84 = 0 ;
int V_62 ;
int V_85 = F_45 ( V_15 -> V_86 ) ;
if ( V_85 > V_11 -> V_87 ) {
F_20 ( V_15 , L_14 , V_85 , V_11 -> V_87 ) ;
return - V_50 ;
}
F_46 (dev->of_node, np) {
V_62 = F_22 ( V_56 , V_11 , V_58 , V_84 ) ;
if ( V_62 ) {
F_40 ( V_11 ) ;
return V_62 ;
}
V_84 ++ ;
}
return 0 ;
}
static int F_47 ( struct V_55 * V_56 )
{
struct V_40 * V_15 = & V_56 -> V_15 ;
unsigned int V_87 ;
struct V_5 * V_11 ;
int V_62 ;
V_87 = F_48 ( V_15 ) ;
if ( V_87 == 0 ) {
F_20 ( V_15 , L_15 ) ;
return - V_44 ;
}
V_11 = F_30 ( V_15 , sizeof( * V_11 ) + ( sizeof( V_11 -> V_13 [ 0 ] ) * V_87 ) , V_65 ) ;
if ( ! V_11 )
return - V_66 ;
V_11 -> V_37 = F_49 ( V_15 -> V_86 ) ;
if ( F_28 ( V_11 -> V_37 ) )
return F_29 ( V_11 -> V_37 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_87 = V_87 ;
F_50 ( & V_11 -> V_8 ) ;
F_51 ( & V_11 -> V_83 ) ;
V_62 = F_44 ( V_11 , V_56 ) ;
if ( V_62 ) {
if ( V_11 -> V_37 )
F_52 ( V_11 -> V_37 ) ;
return V_62 ;
}
F_53 ( V_56 , V_11 ) ;
return 0 ;
}
static int F_54 ( struct V_55 * V_56 )
{
struct V_5 * V_11 = F_55 ( V_56 ) ;
if ( V_11 -> V_37 )
F_52 ( V_11 -> V_37 ) ;
F_40 ( V_11 ) ;
return 0 ;
}
