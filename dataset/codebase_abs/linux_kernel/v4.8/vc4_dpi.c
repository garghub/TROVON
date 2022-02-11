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
static void F_4 ( struct V_8 * V_9 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_11 ) ; V_10 ++ ) {
F_6 ( L_1 ,
V_11 [ V_10 ] . V_12 , V_11 [ V_10 ] . V_13 ,
F_7 ( V_11 [ V_10 ] . V_12 ) ) ;
}
}
int F_8 ( struct V_14 * V_15 , void * V_16 )
{
struct V_17 * V_18 = (struct V_17 * ) V_15 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_22 -> V_21 ;
struct V_23 * V_24 = F_9 ( V_21 ) ;
struct V_8 * V_9 = V_24 -> V_9 ;
int V_10 ;
if ( ! V_9 )
return 0 ;
for ( V_10 = 0 ; V_10 < F_5 ( V_11 ) ; V_10 ++ ) {
F_10 ( V_15 , L_2 ,
V_11 [ V_10 ] . V_13 , V_11 [ V_10 ] . V_12 ,
F_7 ( V_11 [ V_10 ] . V_12 ) ) ;
}
return 0 ;
}
static enum V_25
F_11 ( struct V_6 * V_7 , bool V_26 )
{
struct V_5 * V_27 =
F_3 ( V_7 ) ;
struct V_8 * V_9 = V_27 -> V_9 ;
if ( V_9 -> V_28 )
return V_29 ;
else
return V_30 ;
}
static void F_12 ( struct V_6 * V_7 )
{
F_13 ( V_7 ) ;
F_14 ( V_7 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_5 * V_27 =
F_3 ( V_7 ) ;
struct V_8 * V_9 = V_27 -> V_9 ;
if ( V_9 -> V_28 )
return F_16 ( V_9 -> V_28 ) ;
return 0 ;
}
static struct V_6 * F_17 ( struct V_20 * V_21 ,
struct V_8 * V_9 )
{
struct V_6 * V_7 = NULL ;
struct V_5 * V_31 ;
V_31 = F_18 ( V_21 -> V_21 , sizeof( * V_31 ) ,
V_32 ) ;
if ( ! V_31 )
return F_19 ( - V_33 ) ;
V_7 = & V_31 -> V_4 ;
V_31 -> V_3 = V_9 -> V_3 ;
V_31 -> V_9 = V_9 ;
F_20 ( V_21 , V_7 , & V_34 ,
V_35 ) ;
F_21 ( V_7 , & V_36 ) ;
V_7 -> V_37 = 0 ;
V_7 -> V_38 = 0 ;
V_7 -> V_39 = 0 ;
F_22 ( V_7 , V_9 -> V_3 ) ;
return V_7 ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_40 -> V_9 ;
F_24 ( V_9 -> V_28 ) ;
F_25 ( V_9 -> V_41 ) ;
F_26 ( V_9 -> V_28 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_42 * V_43 = & V_3 -> V_44 -> V_43 ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_40 -> V_9 ;
T_1 V_45 = V_46 | V_47 ;
int V_48 ;
V_48 = F_28 ( V_9 -> V_28 ) ;
if ( V_48 ) {
F_29 ( L_3 ) ;
return;
}
if ( V_9 -> V_7 -> V_49 . V_50 ) {
T_1 V_51 = V_9 -> V_7 -> V_49 . V_52 [ 0 ] ;
switch ( V_51 ) {
case V_53 :
V_45 |= F_30 ( V_54 ,
V_55 ) ;
break;
case V_56 :
V_45 |= F_30 ( V_54 ,
V_55 ) ;
V_45 |= F_30 ( V_57 , V_58 ) ;
break;
case V_59 :
V_45 |= F_30 ( V_60 ,
V_55 ) ;
break;
case V_61 :
V_45 |= F_30 ( V_62 ,
V_55 ) ;
break;
case V_63 :
V_45 |= F_30 ( V_64 ,
V_55 ) ;
break;
default:
F_29 ( L_4 , V_51 ) ;
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
F_31 ( V_74 , V_45 ) ;
V_48 = F_32 ( V_9 -> V_41 , V_43 -> clock * 1000 ) ;
if ( V_48 )
F_29 ( L_5 , V_48 ) ;
V_48 = F_33 ( V_9 -> V_41 ) ;
if ( V_48 )
F_29 ( L_5 , V_48 ) ;
V_48 = F_34 ( V_9 -> V_28 ) ;
if ( V_48 ) {
F_29 ( L_6 ) ;
F_26 ( V_9 -> V_28 ) ;
return;
}
}
static struct V_75 * F_35 ( struct V_76 * V_21 )
{
struct V_77 * V_78 , * V_79 ;
struct V_77 * V_80 = V_21 -> V_81 ;
struct V_75 * V_28 ;
V_78 = F_36 ( V_80 , NULL ) ;
if ( ! V_78 ) {
F_37 ( V_21 , L_7 ) ;
return NULL ;
}
V_79 = F_38 ( V_78 ) ;
F_39 ( V_78 ) ;
if ( ! V_79 ) {
F_37 ( V_21 , L_8 ) ;
return NULL ;
}
V_28 = F_40 ( V_79 ) ;
F_39 ( V_79 ) ;
return V_28 ;
}
static int F_41 ( struct V_76 * V_21 , struct V_76 * V_82 , void * V_83 )
{
struct V_84 * V_85 = F_42 ( V_21 ) ;
struct V_20 * V_86 = F_43 ( V_82 ) ;
struct V_23 * V_24 = F_9 ( V_86 ) ;
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_48 ;
V_9 = F_18 ( V_21 , sizeof( * V_9 ) , V_32 ) ;
if ( ! V_9 )
return - V_33 ;
V_1 = F_18 ( V_21 , sizeof( * V_1 ) ,
V_32 ) ;
if ( ! V_1 )
return - V_33 ;
V_1 -> V_4 . type = V_87 ;
V_1 -> V_9 = V_9 ;
V_9 -> V_3 = & V_1 -> V_4 . V_4 ;
V_9 -> V_85 = V_85 ;
V_9 -> V_88 = F_44 ( V_85 , 0 ) ;
if ( F_45 ( V_9 -> V_88 ) )
return F_46 ( V_9 -> V_88 ) ;
F_4 ( V_9 ) ;
if ( F_7 ( V_89 ) != V_90 ) {
F_37 ( V_21 , L_9 ,
F_7 ( V_89 ) , V_90 ) ;
return - V_91 ;
}
V_9 -> V_92 = F_47 ( V_21 , L_10 ) ;
if ( F_45 ( V_9 -> V_92 ) ) {
V_48 = F_46 ( V_9 -> V_92 ) ;
if ( V_48 != - V_93 )
F_29 ( L_11 , V_48 ) ;
return V_48 ;
}
V_9 -> V_41 = F_47 ( V_21 , L_12 ) ;
if ( F_45 ( V_9 -> V_41 ) ) {
V_48 = F_46 ( V_9 -> V_41 ) ;
if ( V_48 != - V_93 )
F_29 ( L_13 , V_48 ) ;
return V_48 ;
}
V_48 = F_33 ( V_9 -> V_92 ) ;
if ( V_48 )
F_29 ( L_14 , V_48 ) ;
V_9 -> V_28 = F_35 ( V_21 ) ;
F_48 ( V_86 , V_9 -> V_3 , & V_94 ,
V_95 , NULL ) ;
F_49 ( V_9 -> V_3 , & V_96 ) ;
V_9 -> V_7 = F_17 ( V_86 , V_9 ) ;
if ( F_45 ( V_9 -> V_7 ) ) {
V_48 = F_46 ( V_9 -> V_7 ) ;
goto V_97;
}
if ( V_9 -> V_28 )
F_50 ( V_9 -> V_28 , V_9 -> V_7 ) ;
F_51 ( V_21 , V_9 ) ;
V_24 -> V_9 = V_9 ;
return 0 ;
V_97:
F_52 ( V_9 -> V_3 ) ;
F_25 ( V_9 -> V_92 ) ;
return V_48 ;
}
static void F_53 ( struct V_76 * V_21 , struct V_76 * V_82 ,
void * V_83 )
{
struct V_20 * V_86 = F_43 ( V_82 ) ;
struct V_23 * V_24 = F_9 ( V_86 ) ;
struct V_8 * V_9 = F_43 ( V_21 ) ;
if ( V_9 -> V_28 )
F_54 ( V_9 -> V_28 ) ;
F_12 ( V_9 -> V_7 ) ;
F_52 ( V_9 -> V_3 ) ;
F_25 ( V_9 -> V_92 ) ;
V_24 -> V_9 = NULL ;
}
static int F_55 ( struct V_84 * V_85 )
{
return F_56 ( & V_85 -> V_21 , & V_98 ) ;
}
static int F_57 ( struct V_84 * V_85 )
{
F_58 ( & V_85 -> V_21 , & V_98 ) ;
return 0 ;
}
