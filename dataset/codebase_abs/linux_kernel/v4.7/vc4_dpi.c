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
static struct V_2 *
F_17 ( struct V_6 * V_7 )
{
struct V_5 * V_31 =
F_3 ( V_7 ) ;
return V_31 -> V_3 ;
}
static struct V_6 * F_18 ( struct V_20 * V_21 ,
struct V_8 * V_9 )
{
struct V_6 * V_7 = NULL ;
struct V_5 * V_31 ;
int V_32 = 0 ;
V_31 = F_19 ( V_21 -> V_21 , sizeof( * V_31 ) ,
V_33 ) ;
if ( ! V_31 ) {
V_32 = - V_34 ;
goto V_35;
}
V_7 = & V_31 -> V_4 ;
V_31 -> V_3 = V_9 -> V_3 ;
V_31 -> V_9 = V_9 ;
F_20 ( V_21 , V_7 , & V_36 ,
V_37 ) ;
F_21 ( V_7 , & V_38 ) ;
V_7 -> V_39 = 0 ;
V_7 -> V_40 = 0 ;
V_7 -> V_41 = 0 ;
F_22 ( V_7 , V_9 -> V_3 ) ;
return V_7 ;
V_35:
if ( V_7 )
F_12 ( V_7 ) ;
return F_23 ( V_32 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_42 -> V_9 ;
F_25 ( V_9 -> V_28 ) ;
F_26 ( V_9 -> V_43 ) ;
F_27 ( V_9 -> V_28 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = & V_3 -> V_46 -> V_45 ;
struct V_1 * V_42 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_42 -> V_9 ;
T_1 V_47 = V_48 | V_49 ;
int V_32 ;
V_32 = F_29 ( V_9 -> V_28 ) ;
if ( V_32 ) {
F_30 ( L_3 ) ;
return;
}
if ( V_9 -> V_7 -> V_50 . V_51 ) {
T_1 V_52 = V_9 -> V_7 -> V_50 . V_53 [ 0 ] ;
switch ( V_52 ) {
case V_54 :
V_47 |= F_31 ( V_55 ,
V_56 ) ;
break;
case V_57 :
V_47 |= F_31 ( V_55 ,
V_56 ) ;
V_47 |= F_31 ( V_58 , V_59 ) ;
break;
case V_60 :
V_47 |= F_31 ( V_61 ,
V_56 ) ;
break;
case V_62 :
V_47 |= F_31 ( V_63 ,
V_56 ) ;
break;
case V_64 :
V_47 |= F_31 ( V_65 ,
V_56 ) ;
break;
default:
F_30 ( L_4 , V_52 ) ;
break;
}
}
if ( V_45 -> V_66 & V_67 )
V_47 |= V_68 ;
else if ( ! ( V_45 -> V_66 & V_69 ) )
V_47 |= V_70 ;
if ( V_45 -> V_66 & V_71 )
V_47 |= V_72 ;
else if ( ! ( V_45 -> V_66 & V_73 ) )
V_47 |= V_74 ;
F_32 ( V_75 , V_47 ) ;
V_32 = F_33 ( V_9 -> V_43 , V_45 -> clock * 1000 ) ;
if ( V_32 )
F_30 ( L_5 , V_32 ) ;
V_32 = F_34 ( V_9 -> V_43 ) ;
if ( V_32 )
F_30 ( L_5 , V_32 ) ;
V_32 = F_35 ( V_9 -> V_28 ) ;
if ( V_32 ) {
F_30 ( L_6 ) ;
F_27 ( V_9 -> V_28 ) ;
return;
}
}
static struct V_76 * F_36 ( struct V_77 * V_21 )
{
struct V_78 * V_79 , * V_80 ;
struct V_78 * V_81 = V_21 -> V_82 ;
struct V_76 * V_28 ;
V_79 = F_37 ( V_81 , NULL ) ;
if ( ! V_79 ) {
F_38 ( V_21 , L_7 ) ;
return NULL ;
}
V_80 = F_39 ( V_79 ) ;
F_40 ( V_79 ) ;
if ( ! V_80 ) {
F_38 ( V_21 , L_8 ) ;
return NULL ;
}
V_28 = F_41 ( V_80 ) ;
F_40 ( V_80 ) ;
return V_28 ;
}
static int F_42 ( struct V_77 * V_21 , struct V_77 * V_83 , void * V_84 )
{
struct V_85 * V_86 = F_43 ( V_21 ) ;
struct V_20 * V_87 = F_44 ( V_83 ) ;
struct V_23 * V_24 = F_9 ( V_87 ) ;
struct V_8 * V_9 ;
struct V_1 * V_1 ;
int V_32 ;
V_9 = F_19 ( V_21 , sizeof( * V_9 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
V_1 = F_19 ( V_21 , sizeof( * V_1 ) ,
V_33 ) ;
if ( ! V_1 )
return - V_34 ;
V_1 -> V_4 . type = V_88 ;
V_1 -> V_9 = V_9 ;
V_9 -> V_3 = & V_1 -> V_4 . V_4 ;
V_9 -> V_86 = V_86 ;
V_9 -> V_89 = F_45 ( V_86 , 0 ) ;
if ( F_46 ( V_9 -> V_89 ) )
return F_47 ( V_9 -> V_89 ) ;
F_4 ( V_9 ) ;
if ( F_7 ( V_90 ) != V_91 ) {
F_38 ( V_21 , L_9 ,
F_7 ( V_90 ) , V_91 ) ;
return - V_92 ;
}
V_9 -> V_93 = F_48 ( V_21 , L_10 ) ;
if ( F_46 ( V_9 -> V_93 ) ) {
V_32 = F_47 ( V_9 -> V_93 ) ;
if ( V_32 != - V_94 )
F_30 ( L_11 , V_32 ) ;
return V_32 ;
}
V_9 -> V_43 = F_48 ( V_21 , L_12 ) ;
if ( F_46 ( V_9 -> V_43 ) ) {
V_32 = F_47 ( V_9 -> V_43 ) ;
if ( V_32 != - V_94 )
F_30 ( L_13 , V_32 ) ;
return V_32 ;
}
V_32 = F_34 ( V_9 -> V_93 ) ;
if ( V_32 )
F_30 ( L_14 , V_32 ) ;
V_9 -> V_28 = F_36 ( V_21 ) ;
F_49 ( V_87 , V_9 -> V_3 , & V_95 ,
V_96 , NULL ) ;
F_50 ( V_9 -> V_3 , & V_97 ) ;
V_9 -> V_7 = F_18 ( V_87 , V_9 ) ;
if ( F_46 ( V_9 -> V_7 ) ) {
V_32 = F_47 ( V_9 -> V_7 ) ;
goto V_98;
}
if ( V_9 -> V_28 )
F_51 ( V_9 -> V_28 , V_9 -> V_7 ) ;
F_52 ( V_21 , V_9 ) ;
V_24 -> V_9 = V_9 ;
return 0 ;
V_98:
F_53 ( V_9 -> V_3 ) ;
F_26 ( V_9 -> V_93 ) ;
return V_32 ;
}
static void F_54 ( struct V_77 * V_21 , struct V_77 * V_83 ,
void * V_84 )
{
struct V_20 * V_87 = F_44 ( V_83 ) ;
struct V_23 * V_24 = F_9 ( V_87 ) ;
struct V_8 * V_9 = F_44 ( V_21 ) ;
if ( V_9 -> V_28 )
F_55 ( V_9 -> V_28 ) ;
F_12 ( V_9 -> V_7 ) ;
F_53 ( V_9 -> V_3 ) ;
F_26 ( V_9 -> V_93 ) ;
V_24 -> V_9 = NULL ;
}
static int F_56 ( struct V_85 * V_86 )
{
return F_57 ( & V_86 -> V_21 , & V_99 ) ;
}
static int F_58 ( struct V_85 * V_86 )
{
F_59 ( & V_86 -> V_21 , & V_99 ) ;
return 0 ;
}
