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
static void F_9 ( struct V_19 * V_20 )
{
F_10 ( V_25 , V_26 | V_27 ) ;
F_10 ( V_28 , V_29 ) ;
}
static void F_11 ( struct V_19 * V_20 )
{
F_10 ( V_25 , V_26 ) ;
F_10 ( V_28 , V_29 ) ;
}
static void F_12 ( struct V_19 * V_20 )
{
F_10 ( V_25 , V_30 ) ;
F_10 ( V_28 , V_29 ) ;
}
static void F_13 ( struct V_19 * V_20 )
{
F_10 ( V_25 , V_30 ) ;
F_10 ( V_28 ,
V_29 | V_31 ) ;
F_10 ( V_32 , 0x223b ) ;
F_10 ( V_33 , 0x61d1 ) ;
}
static enum V_34
F_14 ( struct V_6 * V_7 , bool V_35 )
{
return V_36 ;
}
static void F_15 ( struct V_6 * V_7 )
{
F_16 ( V_7 ) ;
F_17 ( V_7 ) ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_37 * V_38 = V_7 -> V_38 ;
struct V_39 * V_40 ;
V_40 = F_19 ( V_7 -> V_15 ,
V_41 [ V_38 -> V_42 . V_40 ] . V_40 ) ;
if ( ! V_40 ) {
F_20 ( L_2 ) ;
return - V_43 ;
}
F_21 ( V_7 , V_40 ) ;
return 1 ;
}
static struct V_6 * F_22 ( struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_6 * V_7 = NULL ;
struct V_5 * V_44 ;
V_44 = F_23 ( V_15 -> V_15 , sizeof( * V_44 ) ,
V_45 ) ;
if ( ! V_44 )
return F_24 ( - V_43 ) ;
V_7 = & V_44 -> V_4 ;
V_7 -> V_46 = true ;
V_44 -> V_3 = V_20 -> V_3 ;
V_44 -> V_20 = V_20 ;
F_25 ( V_15 , V_7 , & V_47 ,
V_48 ) ;
F_26 ( V_7 , & V_49 ) ;
F_27 ( & V_7 -> V_4 ,
V_15 -> V_50 . V_51 ,
V_52 ) ;
V_20 -> V_53 = & V_41 [ V_52 ] ;
F_28 ( V_7 , V_20 -> V_3 ) ;
return V_7 ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_19 * V_20 = V_1 -> V_20 ;
int V_54 ;
F_10 ( V_55 , 0 ) ;
F_10 ( V_56 ,
V_57 |
V_58 |
V_59 |
V_60 ) ;
F_30 ( V_20 -> clock ) ;
V_54 = F_31 ( & V_20 -> V_61 -> V_15 ) ;
if ( V_54 < 0 ) {
F_20 ( L_3 , V_54 ) ;
return;
}
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_19 * V_20 = V_1 -> V_20 ;
int V_54 ;
V_54 = F_33 ( & V_20 -> V_61 -> V_15 ) ;
if ( V_54 < 0 ) {
F_20 ( L_4 , V_54 ) ;
return;
}
V_54 = F_34 ( V_20 -> clock , 108000000 ) ;
if ( V_54 ) {
F_20 ( L_5 , V_54 ) ;
return;
}
V_54 = F_35 ( V_20 -> clock ) ;
if ( V_54 ) {
F_20 ( L_6 , V_54 ) ;
return;
}
F_10 ( V_62 , 1 ) ;
F_10 ( V_63 , 1 ) ;
F_10 ( V_64 , 0 ) ;
F_10 ( V_65 , 0x28 ) ;
F_10 ( V_66 , 0xac ) ;
F_10 ( V_67 , 0xec ) ;
F_10 ( V_68 ,
V_69 | V_70 ) ;
F_10 ( V_71 , V_72 ) ;
F_10 ( V_73 ,
F_36 ( 0xc ) |
F_37 ( 0xc ) |
F_38 ( 0x46 ) ) ;
F_10 ( V_74 , 0 ) ;
V_20 -> V_53 -> V_75 ( V_20 ) ;
F_10 ( V_56 ,
V_76 | V_77 ) ;
F_10 ( V_55 , V_78 ) ;
}
static bool F_39 ( struct V_2 * V_3 ,
const struct V_39 * V_40 ,
struct V_39 * V_79 )
{
return true ;
}
static void F_40 ( struct V_2 * V_3 ,
struct V_80 * V_81 ,
struct V_37 * V_82 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_19 * V_20 = V_1 -> V_20 ;
V_20 -> V_53 = & V_41 [ V_82 -> V_42 . V_40 ] ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_80 * V_81 ,
struct V_37 * V_82 )
{
const struct V_83 * V_84 ;
V_84 = & V_41 [ V_82 -> V_42 . V_40 ] ;
if ( V_82 -> V_85 &&
! F_42 ( V_84 -> V_40 , & V_81 -> V_79 ) )
return - V_86 ;
return 0 ;
}
static int F_43 ( struct V_87 * V_15 , struct V_87 * V_88 , void * V_89 )
{
struct V_90 * V_61 = F_44 ( V_15 ) ;
struct V_14 * V_91 = F_45 ( V_88 ) ;
struct V_17 * V_18 = F_5 ( V_91 ) ;
struct V_19 * V_20 ;
struct V_1 * V_1 ;
int V_54 ;
V_54 = F_46 ( V_91 , F_6 ( V_92 ) ,
V_92 ) ;
if ( V_54 )
return V_54 ;
V_20 = F_23 ( V_15 , sizeof( * V_20 ) , V_45 ) ;
if ( ! V_20 )
return - V_43 ;
V_1 = F_23 ( V_15 , sizeof( * V_1 ) ,
V_45 ) ;
if ( ! V_1 )
return - V_43 ;
V_1 -> V_4 . type = V_93 ;
V_1 -> V_20 = V_20 ;
V_20 -> V_3 = & V_1 -> V_4 . V_4 ;
V_20 -> V_61 = V_61 ;
V_20 -> V_94 = F_47 ( V_61 , 0 ) ;
if ( F_48 ( V_20 -> V_94 ) )
return F_49 ( V_20 -> V_94 ) ;
V_20 -> clock = F_50 ( V_15 , NULL ) ;
if ( F_48 ( V_20 -> clock ) ) {
V_54 = F_49 ( V_20 -> clock ) ;
if ( V_54 != - V_95 )
F_20 ( L_7 , V_54 ) ;
return V_54 ;
}
F_51 ( V_15 ) ;
F_52 ( V_91 , V_20 -> V_3 , & V_96 ,
V_97 , NULL ) ;
F_53 ( V_20 -> V_3 , & V_98 ) ;
V_20 -> V_7 = F_22 ( V_91 , V_20 ) ;
if ( F_48 ( V_20 -> V_7 ) ) {
V_54 = F_49 ( V_20 -> V_7 ) ;
goto V_99;
}
F_54 ( V_15 , V_20 ) ;
V_18 -> V_20 = V_20 ;
return 0 ;
V_99:
F_55 ( V_20 -> V_3 ) ;
F_56 ( V_15 ) ;
return V_54 ;
}
static void F_57 ( struct V_87 * V_15 , struct V_87 * V_88 ,
void * V_89 )
{
struct V_14 * V_91 = F_45 ( V_88 ) ;
struct V_17 * V_18 = F_5 ( V_91 ) ;
struct V_19 * V_20 = F_45 ( V_15 ) ;
F_15 ( V_20 -> V_7 ) ;
F_55 ( V_20 -> V_3 ) ;
F_56 ( V_15 ) ;
V_18 -> V_20 = NULL ;
}
static int F_58 ( struct V_90 * V_61 )
{
return F_59 ( & V_61 -> V_15 , & V_100 ) ;
}
static int F_60 ( struct V_90 * V_61 )
{
F_61 ( & V_61 -> V_15 , & V_100 ) ;
return 0 ;
}
