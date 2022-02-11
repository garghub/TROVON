static inline void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
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
static int F_2 ( struct V_34 * V_35 )
{
struct V_36 * V_37 =
F_3 ( V_35 ) ;
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_40 * V_41 = V_39 -> V_41 ;
struct V_42 * V_42 = NULL ;
unsigned int V_43 = 0 ;
int V_44 ;
if ( ! V_41 ) {
F_4 ( L_1 ) ;
return 0 ;
}
if ( V_41 -> V_45 ) {
V_42 = V_41 -> V_45 ( V_39 -> V_46 , V_35 ) ;
if ( F_5 ( V_42 ) ) {
V_44 = F_6 ( V_42 ) ;
V_42 = NULL ;
F_7 ( L_2 , V_44 ) ;
goto V_47;
}
V_43 = F_8 ( V_35 , V_42 ) ;
if ( ! V_43 ) {
F_7 ( L_3 , V_43 ) ;
goto V_47;
}
F_9 ( V_35 , V_42 ) ;
} else {
struct V_3 * V_4 ;
struct V_1 * V_2 = F_10 ( V_35 -> V_46 ) ;
if ( ! V_2 ) {
F_7 ( L_4 ) ;
return 0 ;
}
if ( V_41 -> V_48 )
V_4 = V_41 -> V_48 ( V_39 -> V_46 ) ;
else {
F_11 ( V_35 -> V_46 , V_2 ) ;
return 0 ;
}
F_1 ( V_2 , V_4 ) ;
V_35 -> V_49 . V_26 = V_2 -> V_26 ;
V_35 -> V_49 . V_27 = V_2 -> V_27 ;
V_2 -> type = V_50 | V_51 ;
F_12 ( V_2 ) ;
F_13 ( V_35 , V_2 ) ;
V_43 = 1 ;
}
V_47:
F_14 ( V_42 ) ;
return V_43 ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_36 * V_37 =
F_3 ( V_35 ) ;
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_40 * V_41 = V_39 -> V_41 ;
int V_44 = V_52 ;
F_4 ( L_5 , __FILE__ ) ;
if ( V_41 && V_41 -> V_53 )
if ( ! V_41 -> V_53 ( V_39 -> V_46 , V_2 ) )
V_44 = V_54 ;
return V_44 ;
}
struct V_55 * F_16 ( struct V_34 * V_35 )
{
struct V_56 * V_46 = V_35 -> V_46 ;
struct V_36 * V_37 =
F_3 ( V_35 ) ;
struct V_57 * V_58 ;
struct V_55 * V_59 ;
V_58 = F_17 ( V_46 , V_37 -> V_60 ,
V_61 ) ;
if ( ! V_58 ) {
F_4 ( L_6 ,
V_37 -> V_60 ) ;
return NULL ;
}
V_59 = F_18 ( V_58 ) ;
return V_59 ;
}
void F_19 ( struct V_34 * V_35 , int V_2 )
{
struct V_55 * V_59 = F_16 ( V_35 ) ;
struct V_36 * V_37 ;
struct V_38 * V_39 = F_20 ( V_59 ) ;
struct V_40 * V_41 = V_39 -> V_41 ;
V_37 = F_3 ( V_35 ) ;
if ( V_37 -> V_62 == V_2 ) {
F_4 ( L_7 ) ;
return;
}
if ( V_41 && V_41 -> V_63 )
V_41 -> V_63 ( V_39 -> V_46 , V_2 ) ;
V_37 -> V_62 = V_2 ;
}
static void F_21 ( struct V_34 * V_35 ,
int V_2 )
{
F_22 ( V_35 , V_2 ) ;
F_19 ( V_35 , V_2 ) ;
}
static int F_23 ( struct V_34 * V_35 ,
unsigned int V_64 , unsigned int V_65 )
{
struct V_36 * V_37 =
F_3 ( V_35 ) ;
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_66 * V_67 = V_39 -> V_67 ;
unsigned int V_68 , V_69 ;
V_68 = V_64 ;
V_69 = V_65 ;
if ( V_67 && V_67 -> V_70 )
V_67 -> V_70 ( V_39 -> V_46 , & V_68 , & V_69 ) ;
return F_24 ( V_35 , V_68 ,
V_69 ) ;
}
static enum V_71
F_25 ( struct V_34 * V_35 , bool V_72 )
{
struct V_36 * V_37 =
F_3 ( V_35 ) ;
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_40 * V_41 =
V_39 -> V_41 ;
enum V_71 V_73 = V_74 ;
if ( V_41 && V_41 -> V_75 ) {
if ( V_41 -> V_75 ( V_39 -> V_46 ) )
V_73 = V_76 ;
else
V_73 = V_74 ;
}
return V_73 ;
}
static void F_26 ( struct V_34 * V_35 )
{
struct V_36 * V_37 =
F_3 ( V_35 ) ;
F_27 ( V_35 ) ;
F_28 ( V_35 ) ;
F_14 ( V_37 ) ;
}
struct V_34 * F_29 ( struct V_56 * V_46 ,
struct V_55 * V_59 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 = F_20 ( V_59 ) ;
struct V_34 * V_35 ;
int type ;
int V_77 ;
V_37 = F_30 ( sizeof( * V_37 ) , V_78 ) ;
if ( ! V_37 ) {
F_7 ( L_8 ) ;
return NULL ;
}
V_35 = & V_37 -> V_34 ;
switch ( V_39 -> V_41 -> type ) {
case V_79 :
type = V_80 ;
V_35 -> V_81 = true ;
V_35 -> V_82 = V_83 ;
break;
case V_84 :
type = V_85 ;
V_35 -> V_82 = V_83 ;
break;
default:
type = V_86 ;
break;
}
F_31 ( V_46 , V_35 , & V_87 , type ) ;
F_32 ( V_35 , & V_88 ) ;
V_77 = F_33 ( V_35 ) ;
if ( V_77 )
goto V_89;
V_37 -> V_60 = V_59 -> V_90 . V_91 ;
V_37 -> V_39 = V_39 ;
V_37 -> V_62 = V_92 ;
V_35 -> V_62 = V_92 ;
V_35 -> V_59 = V_59 ;
V_77 = F_34 ( V_35 , V_59 ) ;
if ( V_77 ) {
F_7 ( L_9 ) ;
goto V_93;
}
F_4 ( L_10 ) ;
return V_35 ;
V_93:
F_27 ( V_35 ) ;
V_89:
F_28 ( V_35 ) ;
F_14 ( V_37 ) ;
return NULL ;
}
