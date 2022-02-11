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
F_9 ( V_36 -> V_50 . V_51 ) ;
V_36 -> V_50 . V_51 = V_46 ;
} else {
struct V_1 * V_2 = F_12 ( V_36 -> V_49 ) ;
struct V_3 * V_4 ;
if ( V_42 -> V_52 )
V_4 = V_42 -> V_52 ( V_40 -> V_49 ) ;
else {
F_13 ( V_36 -> V_49 , V_2 ) ;
return 0 ;
}
F_1 ( V_2 , V_4 ) ;
V_36 -> V_50 . V_26 = V_2 -> V_26 ;
V_36 -> V_50 . V_27 = V_2 -> V_27 ;
V_2 -> type = V_53 | V_54 ;
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
int V_45 = V_55 ;
F_2 ( L_1 , __FILE__ ) ;
F_3 ( & V_6 , V_2 ) ;
if ( V_42 && V_42 -> V_56 )
if ( ! V_42 -> V_56 ( V_40 -> V_49 , ( void * ) & V_6 ) )
V_45 = V_57 ;
return V_45 ;
}
static struct V_58 * F_17 (
struct V_35 * V_36 )
{
struct V_59 * V_49 = V_36 -> V_49 ;
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_60 * V_61 ;
struct V_58 * V_62 ;
F_2 ( L_1 , __FILE__ ) ;
V_61 = F_18 ( V_49 , V_38 -> V_63 ,
V_64 ) ;
if ( ! V_61 ) {
F_2 ( L_5 ,
V_38 -> V_63 ) ;
return NULL ;
}
V_62 = F_19 ( V_61 ) ;
return V_62 ;
}
static int F_20 ( struct V_35 * V_36 ,
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
V_68 -> V_71 ( V_40 -> V_49 , & V_69 , & V_70 ) ;
return F_21 ( V_36 , V_69 ,
V_70 ) ;
}
static enum V_72
F_22 ( struct V_35 * V_36 , bool V_73 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_41 * V_42 =
V_40 -> V_42 ;
enum V_72 V_74 = V_75 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_42 && V_42 -> V_76 ) {
if ( V_42 -> V_76 ( V_40 -> V_49 ) )
V_74 = V_77 ;
else
V_74 = V_75 ;
}
return V_74 ;
}
static void F_23 ( struct V_35 * V_36 )
{
struct V_37 * V_38 =
F_6 ( V_36 ) ;
F_2 ( L_1 , __FILE__ ) ;
F_24 ( V_36 ) ;
F_25 ( V_36 ) ;
F_9 ( V_38 ) ;
}
struct V_35 * F_26 ( struct V_59 * V_49 ,
struct V_58 * V_62 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 = F_27 ( V_62 ) ;
struct V_35 * V_36 ;
int type ;
int V_78 ;
F_2 ( L_1 , __FILE__ ) ;
V_38 = F_7 ( sizeof( * V_38 ) , V_48 ) ;
if ( ! V_38 ) {
F_8 ( L_6 ) ;
return NULL ;
}
V_36 = & V_38 -> V_35 ;
switch ( V_40 -> V_42 -> type ) {
case V_79 :
type = V_80 ;
V_36 -> V_81 = true ;
V_36 -> V_82 = V_83 ;
break;
case V_84 :
type = V_85 ;
V_36 -> V_82 = V_83 ;
break;
default:
type = V_86 ;
break;
}
F_28 ( V_49 , V_36 , & V_87 , type ) ;
F_29 ( V_36 , & V_88 ) ;
V_78 = F_30 ( V_36 ) ;
if ( V_78 )
goto V_89;
V_38 -> V_63 = V_62 -> V_90 . V_91 ;
V_38 -> V_40 = V_40 ;
V_36 -> V_62 = V_62 ;
V_78 = F_31 ( V_36 , V_62 ) ;
if ( V_78 ) {
F_8 ( L_7 ) ;
goto V_92;
}
F_2 ( L_8 ) ;
return V_36 ;
V_92:
F_24 ( V_36 ) ;
V_89:
F_25 ( V_36 ) ;
F_9 ( V_38 ) ;
return NULL ;
}
