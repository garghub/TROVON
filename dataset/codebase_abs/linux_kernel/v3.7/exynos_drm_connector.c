static inline void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
F_2 ( L_1 , __FILE__ ) ;
V_2 -> clock = V_6 -> V_7 / 1000 ;
V_2 -> V_8 = V_6 -> V_9 ;
V_2 -> V_10 = V_6 -> V_11 ;
V_2 -> V_12 = V_2 -> V_10 + V_6 -> V_13 ;
V_2 -> V_14 = V_2 -> V_12 + V_6 -> V_15 ;
V_2 -> V_16 = V_2 -> V_14 + V_6 -> V_17 ;
V_2 -> V_18 = V_6 -> V_19 ;
V_2 -> V_20 = V_2 -> V_18 + V_6 -> V_21 ;
V_2 -> V_22 = V_2 -> V_20 + V_6 -> V_23 ;
V_2 -> V_24 = V_2 -> V_22 + V_6 -> V_25 ;
V_2 -> V_26 = V_4 -> V_26 ;
V_2 -> V_27 = V_4 -> V_27 ;
if ( V_6 -> V_28 & V_29 )
V_2 -> V_30 |= V_31 ;
if ( V_6 -> V_28 & V_32 )
V_2 -> V_30 |= V_33 ;
}
static inline void
F_3 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_7 = V_2 -> clock * 1000 ;
V_6 -> V_9 = F_4 ( V_2 ) ;
V_6 -> V_11 = V_2 -> V_10 ;
V_6 -> V_13 = V_2 -> V_12 - V_2 -> V_10 ;
V_6 -> V_15 = V_2 -> V_14 - V_2 -> V_12 ;
V_6 -> V_17 = V_2 -> V_16 - V_2 -> V_14 ;
V_6 -> V_19 = V_2 -> V_18 ;
V_6 -> V_21 = V_2 -> V_20 - V_2 -> V_18 ;
V_6 -> V_23 = V_2 -> V_22 - V_2 -> V_20 ;
V_6 -> V_25 = V_2 -> V_24 - V_2 -> V_22 ;
if ( V_2 -> V_30 & V_31 )
V_6 -> V_28 = V_29 ;
else
V_6 -> V_28 = V_34 ;
if ( V_2 -> V_30 & V_33 )
V_6 -> V_28 |= V_32 ;
}
static int F_5 ( struct V_35 * V_36 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_41 * V_42 = V_40 -> V_42 ;
unsigned int V_43 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_42 ) {
F_2 ( L_2 ) ;
return 0 ;
}
if ( V_42 -> V_44 ) {
int V_45 ;
void * V_46 ;
V_46 = F_7 ( V_47 , V_48 ) ;
if ( ! V_46 ) {
F_8 ( L_3 ) ;
return 0 ;
}
V_45 = V_42 -> V_44 ( V_40 -> V_49 , V_36 ,
V_46 , V_47 ) ;
if ( V_45 < 0 ) {
F_8 ( L_4 ) ;
F_9 ( V_46 ) ;
V_46 = NULL ;
return 0 ;
}
F_10 ( V_36 , V_46 ) ;
V_43 = F_11 ( V_36 , V_46 ) ;
F_9 ( V_46 ) ;
} else {
struct V_3 * V_4 ;
struct V_1 * V_2 = F_12 ( V_36 -> V_49 ) ;
if ( ! V_2 ) {
F_8 ( L_5 ) ;
return 0 ;
}
if ( V_42 -> V_50 )
V_4 = V_42 -> V_50 ( V_40 -> V_49 ) ;
else {
F_13 ( V_36 -> V_49 , V_2 ) ;
return 0 ;
}
F_1 ( V_2 , V_4 ) ;
V_36 -> V_51 . V_26 = V_2 -> V_26 ;
V_36 -> V_51 . V_27 = V_2 -> V_27 ;
V_2 -> type = V_52 | V_53 ;
F_14 ( V_2 ) ;
F_15 ( V_36 , V_2 ) ;
V_43 = 1 ;
}
return V_43 ;
}
static int F_16 ( struct V_35 * V_36 ,
struct V_1 * V_2 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_5 V_6 ;
int V_45 = V_54 ;
F_2 ( L_1 , __FILE__ ) ;
F_3 ( & V_6 , V_2 ) ;
if ( V_42 && V_42 -> V_55 )
if ( ! V_42 -> V_55 ( V_40 -> V_49 , ( void * ) & V_6 ) )
V_45 = V_56 ;
return V_45 ;
}
struct V_57 * F_17 ( struct V_35 * V_36 )
{
struct V_58 * V_49 = V_36 -> V_49 ;
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_59 * V_60 ;
struct V_57 * V_61 ;
F_2 ( L_1 , __FILE__ ) ;
V_60 = F_18 ( V_49 , V_38 -> V_62 ,
V_63 ) ;
if ( ! V_60 ) {
F_2 ( L_6 ,
V_38 -> V_62 ) ;
return NULL ;
}
V_61 = F_19 ( V_60 ) ;
return V_61 ;
}
void F_20 ( struct V_35 * V_36 , int V_2 )
{
struct V_57 * V_61 = F_17 ( V_36 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 = F_21 ( V_61 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
V_38 = F_6 ( V_36 ) ;
if ( V_38 -> V_64 == V_2 ) {
F_2 ( L_7 ) ;
return;
}
if ( V_42 && V_42 -> V_65 )
V_42 -> V_65 ( V_40 -> V_49 , V_2 ) ;
V_38 -> V_64 = V_2 ;
}
static void F_22 ( struct V_35 * V_36 ,
int V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
F_23 ( V_36 , V_2 ) ;
F_20 ( V_36 , V_2 ) ;
}
static int F_24 ( struct V_35 * V_36 ,
unsigned int V_66 , unsigned int V_67 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_68 * V_69 = V_40 -> V_69 ;
unsigned int V_70 , V_71 ;
V_70 = V_66 ;
V_71 = V_67 ;
if ( V_69 && V_69 -> V_72 )
V_69 -> V_72 ( V_40 -> V_49 , & V_70 , & V_71 ) ;
return F_25 ( V_36 , V_70 ,
V_71 ) ;
}
static enum V_73
F_26 ( struct V_35 * V_36 , bool V_74 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_41 * V_42 =
V_40 -> V_42 ;
enum V_73 V_75 = V_76 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_42 && V_42 -> V_77 ) {
if ( V_42 -> V_77 ( V_40 -> V_49 ) )
V_75 = V_78 ;
else
V_75 = V_76 ;
}
return V_75 ;
}
static void F_27 ( struct V_35 * V_36 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
F_2 ( L_1 , __FILE__ ) ;
F_28 ( V_36 ) ;
F_29 ( V_36 ) ;
F_9 ( V_38 ) ;
}
struct V_35 * F_30 ( struct V_58 * V_49 ,
struct V_57 * V_61 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 = F_21 ( V_61 ) ;
struct V_35 * V_36 ;
int type ;
int V_79 ;
F_2 ( L_1 , __FILE__ ) ;
V_38 = F_7 ( sizeof( * V_38 ) , V_48 ) ;
if ( ! V_38 ) {
F_8 ( L_8 ) ;
return NULL ;
}
V_36 = & V_38 -> V_35 ;
switch ( V_40 -> V_42 -> type ) {
case V_80 :
type = V_81 ;
V_36 -> V_82 = true ;
V_36 -> V_83 = V_84 ;
break;
case V_85 :
type = V_86 ;
V_36 -> V_83 = V_84 ;
break;
default:
type = V_87 ;
break;
}
F_31 ( V_49 , V_36 , & V_88 , type ) ;
F_32 ( V_36 , & V_89 ) ;
V_79 = F_33 ( V_36 ) ;
if ( V_79 )
goto V_90;
V_38 -> V_62 = V_61 -> V_91 . V_92 ;
V_38 -> V_40 = V_40 ;
V_38 -> V_64 = V_93 ;
V_36 -> V_64 = V_93 ;
V_36 -> V_61 = V_61 ;
V_79 = F_34 ( V_36 , V_61 ) ;
if ( V_79 ) {
F_8 ( L_9 ) ;
goto V_94;
}
F_2 ( L_10 ) ;
return V_36 ;
V_94:
F_28 ( V_36 ) ;
V_90:
F_29 ( V_36 ) ;
F_9 ( V_38 ) ;
return NULL ;
}
