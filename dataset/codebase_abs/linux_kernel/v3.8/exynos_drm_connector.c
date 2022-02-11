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
struct V_43 * V_43 = NULL ;
unsigned int V_44 = 0 ;
int V_45 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_42 ) {
F_2 ( L_2 ) ;
return 0 ;
}
if ( V_42 -> V_46 ) {
V_43 = V_42 -> V_46 ( V_40 -> V_47 , V_36 ) ;
if ( F_7 ( V_43 ) ) {
V_45 = F_8 ( V_43 ) ;
V_43 = NULL ;
F_9 ( L_3 , V_45 ) ;
goto V_48;
}
V_44 = F_10 ( V_36 , V_43 ) ;
if ( V_44 < 0 ) {
F_9 ( L_4 , V_44 ) ;
goto V_48;
}
F_11 ( V_36 , V_43 ) ;
} else {
struct V_3 * V_4 ;
struct V_1 * V_2 = F_12 ( V_36 -> V_47 ) ;
if ( ! V_2 ) {
F_9 ( L_5 ) ;
return 0 ;
}
if ( V_42 -> V_49 )
V_4 = V_42 -> V_49 ( V_40 -> V_47 ) ;
else {
F_13 ( V_36 -> V_47 , V_2 ) ;
return 0 ;
}
F_1 ( V_2 , V_4 ) ;
V_36 -> V_50 . V_26 = V_2 -> V_26 ;
V_36 -> V_50 . V_27 = V_2 -> V_27 ;
V_2 -> type = V_51 | V_52 ;
F_14 ( V_2 ) ;
F_15 ( V_36 , V_2 ) ;
V_44 = 1 ;
}
V_48:
F_16 ( V_43 ) ;
return V_44 ;
}
static int F_17 ( struct V_35 * V_36 ,
struct V_1 * V_2 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_5 V_6 ;
int V_45 = V_53 ;
F_2 ( L_1 , __FILE__ ) ;
F_3 ( & V_6 , V_2 ) ;
if ( V_42 && V_42 -> V_54 )
if ( ! V_42 -> V_54 ( V_40 -> V_47 , ( void * ) & V_6 ) )
V_45 = V_55 ;
return V_45 ;
}
struct V_56 * F_18 ( struct V_35 * V_36 )
{
struct V_57 * V_47 = V_36 -> V_47 ;
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_58 * V_59 ;
struct V_56 * V_60 ;
F_2 ( L_1 , __FILE__ ) ;
V_59 = F_19 ( V_47 , V_38 -> V_61 ,
V_62 ) ;
if ( ! V_59 ) {
F_2 ( L_6 ,
V_38 -> V_61 ) ;
return NULL ;
}
V_60 = F_20 ( V_59 ) ;
return V_60 ;
}
void F_21 ( struct V_35 * V_36 , int V_2 )
{
struct V_56 * V_60 = F_18 ( V_36 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 = F_22 ( V_60 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
V_38 = F_6 ( V_36 ) ;
if ( V_38 -> V_63 == V_2 ) {
F_2 ( L_7 ) ;
return;
}
if ( V_42 && V_42 -> V_64 )
V_42 -> V_64 ( V_40 -> V_47 , V_2 ) ;
V_38 -> V_63 = V_2 ;
}
static void F_23 ( struct V_35 * V_36 ,
int V_2 )
{
F_2 ( L_1 , __FILE__ ) ;
F_24 ( V_36 , V_2 ) ;
F_21 ( V_36 , V_2 ) ;
}
static int F_25 ( struct V_35 * V_36 ,
unsigned int V_65 , unsigned int V_66 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_67 * V_68 = V_40 -> V_68 ;
unsigned int V_69 , V_70 ;
V_69 = V_65 ;
V_70 = V_66 ;
if ( V_68 && V_68 -> V_71 )
V_68 -> V_71 ( V_40 -> V_47 , & V_69 , & V_70 ) ;
return F_26 ( V_36 , V_69 ,
V_70 ) ;
}
static enum V_72
F_27 ( struct V_35 * V_36 , bool V_73 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_41 * V_42 =
V_40 -> V_42 ;
enum V_72 V_74 = V_75 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_42 && V_42 -> V_76 ) {
if ( V_42 -> V_76 ( V_40 -> V_47 ) )
V_74 = V_77 ;
else
V_74 = V_75 ;
}
return V_74 ;
}
static void F_28 ( struct V_35 * V_36 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
F_2 ( L_1 , __FILE__ ) ;
F_29 ( V_36 ) ;
F_30 ( V_36 ) ;
F_16 ( V_38 ) ;
}
struct V_35 * F_31 ( struct V_57 * V_47 ,
struct V_56 * V_60 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 = F_22 ( V_60 ) ;
struct V_35 * V_36 ;
int type ;
int V_78 ;
F_2 ( L_1 , __FILE__ ) ;
V_38 = F_32 ( sizeof( * V_38 ) , V_79 ) ;
if ( ! V_38 ) {
F_9 ( L_8 ) ;
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
F_33 ( V_47 , V_36 , & V_88 , type ) ;
F_34 ( V_36 , & V_89 ) ;
V_78 = F_35 ( V_36 ) ;
if ( V_78 )
goto V_90;
V_38 -> V_61 = V_60 -> V_91 . V_92 ;
V_38 -> V_40 = V_40 ;
V_38 -> V_63 = V_93 ;
V_36 -> V_63 = V_93 ;
V_36 -> V_60 = V_60 ;
V_78 = F_36 ( V_36 , V_60 ) ;
if ( V_78 ) {
F_9 ( L_9 ) ;
goto V_94;
}
F_2 ( L_10 ) ;
return V_36 ;
V_94:
F_29 ( V_36 ) ;
V_90:
F_30 ( V_36 ) ;
F_16 ( V_38 ) ;
return NULL ;
}
