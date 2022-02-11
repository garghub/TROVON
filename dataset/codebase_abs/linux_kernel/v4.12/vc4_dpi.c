static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 ) ;
}
int F_4 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_9 -> V_13 ;
struct V_14 * V_15 = V_12 -> V_16 -> V_15 ;
struct V_17 * V_18 = F_5 ( V_15 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
int V_21 ;
if ( ! V_20 )
return 0 ;
for ( V_21 = 0 ; V_21 < F_6 ( V_22 ) ; V_21 ++ ) {
F_7 ( V_9 , L_1 ,
V_22 [ V_21 ] . V_23 , V_22 [ V_21 ] . V_24 ,
F_8 ( V_22 [ V_21 ] . V_24 ) ) ;
}
return 0 ;
}
static enum V_25
F_9 ( struct V_6 * V_7 , bool V_26 )
{
struct V_5 * V_27 =
F_3 ( V_7 ) ;
struct V_19 * V_20 = V_27 -> V_20 ;
if ( V_20 -> V_28 )
return V_29 ;
else
return V_30 ;
}
static void F_10 ( struct V_6 * V_7 )
{
F_11 ( V_7 ) ;
F_12 ( V_7 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_5 * V_27 =
F_3 ( V_7 ) ;
struct V_19 * V_20 = V_27 -> V_20 ;
if ( V_20 -> V_28 )
return F_14 ( V_20 -> V_28 ) ;
return 0 ;
}
static struct V_6 * F_15 ( struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_6 * V_7 = NULL ;
struct V_5 * V_31 ;
V_31 = F_16 ( V_15 -> V_15 , sizeof( * V_31 ) ,
V_32 ) ;
if ( ! V_31 )
return F_17 ( - V_33 ) ;
V_7 = & V_31 -> V_4 ;
V_31 -> V_3 = V_20 -> V_3 ;
V_31 -> V_20 = V_20 ;
F_18 ( V_15 , V_7 , & V_34 ,
V_35 ) ;
F_19 ( V_7 , & V_36 ) ;
V_7 -> V_37 = 0 ;
V_7 -> V_38 = 0 ;
V_7 -> V_39 = 0 ;
F_20 ( V_7 , V_20 -> V_3 ) ;
return V_7 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_19 * V_20 = V_40 -> V_20 ;
F_22 ( V_20 -> V_28 ) ;
F_23 ( V_20 -> V_41 ) ;
F_24 ( V_20 -> V_28 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_42 * V_43 = & V_3 -> V_44 -> V_43 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_19 * V_20 = V_40 -> V_20 ;
T_1 V_45 = V_46 | V_47 ;
int V_48 ;
V_48 = F_26 ( V_20 -> V_28 ) ;
if ( V_48 ) {
F_27 ( L_2 ) ;
return;
}
if ( V_20 -> V_7 -> V_49 . V_50 ) {
T_1 V_51 = V_20 -> V_7 -> V_49 . V_52 [ 0 ] ;
switch ( V_51 ) {
case V_53 :
V_45 |= F_28 ( V_54 ,
V_55 ) ;
break;
case V_56 :
V_45 |= F_28 ( V_54 ,
V_55 ) ;
V_45 |= F_28 ( V_57 , V_58 ) ;
break;
case V_59 :
V_45 |= F_28 ( V_60 ,
V_55 ) ;
break;
case V_61 :
V_45 |= F_28 ( V_62 ,
V_55 ) ;
break;
case V_63 :
V_45 |= F_28 ( V_64 ,
V_55 ) ;
break;
default:
F_27 ( L_3 , V_51 ) ;
break;
}
}
if ( V_43 -> V_65 & V_66 )
V_45 |= V_67 ;
else if ( ! ( V_43 -> V_65 & V_68 ) )
V_45 |= V_69 ;
if ( V_43 -> V_65 & V_70 )
V_45 |= V_71 ;
else if ( ! ( V_43 -> V_65 & V_72 ) )
V_45 |= V_73 ;
F_29 ( V_74 , V_45 ) ;
V_48 = F_30 ( V_20 -> V_41 , V_43 -> clock * 1000 ) ;
if ( V_48 )
F_27 ( L_4 , V_48 ) ;
V_48 = F_31 ( V_20 -> V_41 ) ;
if ( V_48 )
F_27 ( L_4 , V_48 ) ;
V_48 = F_32 ( V_20 -> V_28 ) ;
if ( V_48 ) {
F_27 ( L_5 ) ;
F_24 ( V_20 -> V_28 ) ;
return;
}
}
static bool F_33 ( struct V_2 * V_3 ,
const struct V_42 * V_43 ,
struct V_42 * V_75 )
{
if ( V_75 -> V_65 & V_76 )
return false ;
return true ;
}
static struct V_77 * F_34 ( struct V_78 * V_15 )
{
struct V_79 * V_80 ;
struct V_79 * V_81 = V_15 -> V_82 ;
struct V_77 * V_28 ;
V_80 = F_35 ( V_81 , 0 , 0 ) ;
if ( ! V_80 )
return NULL ;
V_28 = F_36 ( V_80 ) ;
F_37 ( V_80 ) ;
return V_28 ;
}
static int F_38 ( struct V_78 * V_15 , struct V_78 * V_83 , void * V_84 )
{
struct V_85 * V_86 = F_39 ( V_15 ) ;
struct V_14 * V_87 = F_40 ( V_83 ) ;
struct V_17 * V_18 = F_5 ( V_87 ) ;
struct V_19 * V_20 ;
struct V_1 * V_1 ;
int V_48 ;
V_20 = F_16 ( V_15 , sizeof( * V_20 ) , V_32 ) ;
if ( ! V_20 )
return - V_33 ;
V_1 = F_16 ( V_15 , sizeof( * V_1 ) ,
V_32 ) ;
if ( ! V_1 )
return - V_33 ;
V_1 -> V_4 . type = V_88 ;
V_1 -> V_20 = V_20 ;
V_20 -> V_3 = & V_1 -> V_4 . V_4 ;
V_20 -> V_86 = V_86 ;
V_20 -> V_89 = F_41 ( V_86 , 0 ) ;
if ( F_42 ( V_20 -> V_89 ) )
return F_43 ( V_20 -> V_89 ) ;
if ( F_8 ( V_90 ) != V_91 ) {
F_44 ( V_15 , L_6 ,
F_8 ( V_90 ) , V_91 ) ;
return - V_92 ;
}
V_20 -> V_93 = F_45 ( V_15 , L_7 ) ;
if ( F_42 ( V_20 -> V_93 ) ) {
V_48 = F_43 ( V_20 -> V_93 ) ;
if ( V_48 != - V_94 )
F_27 ( L_8 , V_48 ) ;
return V_48 ;
}
V_20 -> V_41 = F_45 ( V_15 , L_9 ) ;
if ( F_42 ( V_20 -> V_41 ) ) {
V_48 = F_43 ( V_20 -> V_41 ) ;
if ( V_48 != - V_94 )
F_27 ( L_10 , V_48 ) ;
return V_48 ;
}
V_48 = F_31 ( V_20 -> V_93 ) ;
if ( V_48 )
F_27 ( L_11 , V_48 ) ;
V_20 -> V_28 = F_34 ( V_15 ) ;
F_46 ( V_87 , V_20 -> V_3 , & V_95 ,
V_96 , NULL ) ;
F_47 ( V_20 -> V_3 , & V_97 ) ;
V_20 -> V_7 = F_15 ( V_87 , V_20 ) ;
if ( F_42 ( V_20 -> V_7 ) ) {
V_48 = F_43 ( V_20 -> V_7 ) ;
goto V_98;
}
if ( V_20 -> V_28 )
F_48 ( V_20 -> V_28 , V_20 -> V_7 ) ;
F_49 ( V_15 , V_20 ) ;
V_18 -> V_20 = V_20 ;
return 0 ;
V_98:
F_50 ( V_20 -> V_3 ) ;
F_23 ( V_20 -> V_93 ) ;
return V_48 ;
}
static void F_51 ( struct V_78 * V_15 , struct V_78 * V_83 ,
void * V_84 )
{
struct V_14 * V_87 = F_40 ( V_83 ) ;
struct V_17 * V_18 = F_5 ( V_87 ) ;
struct V_19 * V_20 = F_40 ( V_15 ) ;
if ( V_20 -> V_28 )
F_52 ( V_20 -> V_28 ) ;
F_10 ( V_20 -> V_7 ) ;
F_50 ( V_20 -> V_3 ) ;
F_23 ( V_20 -> V_93 ) ;
V_18 -> V_20 = NULL ;
}
static int F_53 ( struct V_85 * V_86 )
{
return F_54 ( & V_86 -> V_15 , & V_99 ) ;
}
static int F_55 ( struct V_85 * V_86 )
{
F_56 ( & V_86 -> V_15 , & V_99 ) ;
return 0 ;
}
