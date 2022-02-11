static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_3 ;
V_4 -> V_5 ( V_4 , V_4 -> V_6 ) ;
}
static void F_2 ( struct V_1 * V_2 ,
enum V_7 V_8 )
{
struct V_9 * V_10 ;
struct V_11 V_12 ;
struct V_3 * V_4 ;
V_4 = & V_2 -> V_3 ;
V_10 = F_3 ( V_4 -> V_13 ) ;
if ( V_8 != V_14 &&
V_8 != V_15 &&
V_8 != V_16 ) {
F_4 ( & V_10 -> V_17 -> V_18 ,
L_1 ,
V_8 , V_2 -> V_19 ) ;
return;
}
if ( V_4 -> V_20 ) {
V_12 . V_13 = V_4 -> V_13 ;
V_12 . V_12 = V_21 ;
V_12 . V_22 . V_23 = V_4 ;
V_4 -> V_20 ( & V_12 , V_4 -> V_6 ) ;
}
}
static int F_5 ( struct V_9 * V_18 ,
struct V_24 * V_25 ,
unsigned long V_26 )
{
return F_6 ( V_18 , V_25 -> V_27 , 0 , V_26 , 0 ,
V_28 , V_29 ) ;
}
static int F_7 ( struct V_9 * V_10 , int V_30 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
struct V_1 * V_2 , int V_35 )
{
struct V_24 * V_25 = NULL ;
struct V_36 * V_37 = NULL ;
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
T_1 V_38 ;
T_2 * V_39 = NULL ;
int V_40 = 0 ;
V_37 = & V_10 -> V_37 ;
V_39 = F_8 ( & V_10 -> V_41 . V_42 ,
V_32 -> V_43 , & V_38 ) ;
if ( ! V_39 ) {
F_4 ( V_18 , L_2 ) ;
return - V_44 ;
}
if ( V_35 >= V_10 -> V_45 . V_46 ) {
F_4 ( V_18 , L_3 ) ;
return - V_44 ;
}
V_2 -> V_35 = V_35 ;
V_40 = F_9 ( & V_37 -> V_47 , & V_2 -> V_19 ) ;
if ( V_40 == - 1 ) {
F_4 ( V_18 , L_4 ) ;
return - V_48 ;
}
V_40 = F_10 ( V_10 , & V_37 -> V_49 , V_2 -> V_19 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_5 ) ;
goto V_50;
}
F_11 ( & V_37 -> V_51 ) ;
V_40 = F_12 ( & V_37 -> V_52 , V_2 -> V_19 , V_2 ) ;
F_13 ( & V_37 -> V_51 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_6 ) ;
goto V_53;
}
V_25 = F_14 ( V_10 ) ;
if ( F_15 ( V_25 ) ) {
V_40 = F_16 ( V_25 ) ;
goto V_54;
}
V_10 -> V_55 -> V_56 ( V_10 , V_2 , V_25 -> V_57 , V_39 , V_38 ,
V_30 , V_35 ) ;
V_40 = F_5 ( V_10 , V_25 , V_2 -> V_19 ) ;
F_17 ( V_10 , V_25 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_7 ) ;
goto V_54;
}
V_2 -> V_58 = 0 ;
V_2 -> V_59 = V_34 ;
F_18 ( & V_2 -> V_60 , 1 ) ;
F_19 ( & V_2 -> free ) ;
return 0 ;
V_54:
F_11 ( & V_37 -> V_51 ) ;
F_20 ( & V_37 -> V_52 , V_2 -> V_19 ) ;
F_13 ( & V_37 -> V_51 ) ;
V_53:
F_21 ( V_10 , & V_37 -> V_49 , V_2 -> V_19 ) ;
V_50:
F_22 ( & V_37 -> V_47 , V_2 -> V_19 ) ;
return V_40 ;
}
static int F_23 ( struct V_9 * V_18 ,
struct V_24 * V_25 ,
unsigned long V_26 )
{
return F_6 ( V_18 , 0 , V_25 ? V_25 -> V_27 : 0 , V_26 ,
V_25 ? 0 : 1 , V_61 ,
V_29 ) ;
}
static void F_24 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_10 -> V_37 ;
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
int V_40 ;
V_40 = F_23 ( V_10 , NULL , V_2 -> V_19 ) ;
if ( V_40 )
F_4 ( V_18 , L_8 , V_40 ,
V_2 -> V_19 ) ;
F_25 ( V_10 -> V_62 . V_63 [ V_2 -> V_35 ] . V_64 ) ;
if ( F_26 ( & V_2 -> V_60 ) )
F_27 ( & V_2 -> free ) ;
F_28 ( & V_2 -> free ) ;
F_11 ( & V_37 -> V_51 ) ;
F_20 ( & V_37 -> V_52 , V_2 -> V_19 ) ;
F_13 ( & V_37 -> V_51 ) ;
F_21 ( V_10 , & V_37 -> V_49 , V_2 -> V_19 ) ;
F_22 ( & V_37 -> V_47 , V_2 -> V_19 ) ;
}
static int F_29 ( struct V_9 * V_10 ,
struct V_65 * V_66 ,
struct V_67 * V_57 ,
struct V_68 * * V_69 , T_2 V_70 , int V_71 )
{
int V_40 ;
* V_69 = F_30 ( V_66 , V_70 , V_71 * V_10 -> V_45 . V_72 ,
V_73 , 1 ) ;
if ( F_15 ( * V_69 ) )
return F_16 ( * V_69 ) ;
V_40 = F_31 ( V_10 , F_32 ( * V_69 ) ,
F_33 ( ( unsigned int ) ( * V_69 ) -> V_74 ) ,
& V_57 -> V_32 ) ;
if ( V_40 )
goto V_75;
V_40 = F_34 ( V_10 , & V_57 -> V_32 , * V_69 ) ;
if ( V_40 )
goto V_76;
return 0 ;
V_76:
F_35 ( V_10 , & V_57 -> V_32 ) ;
V_75:
F_36 ( * V_69 ) ;
return V_40 ;
}
static int F_37 ( struct V_9 * V_10 ,
struct V_67 * V_57 , T_3 V_30 )
{
int V_40 ;
V_40 = F_38 ( V_10 , V_30 * V_10 -> V_45 . V_72 ,
V_77 * 2 , & V_57 -> V_78 ) ;
if ( V_40 )
goto V_79;
V_40 = F_31 ( V_10 , V_57 -> V_78 . V_80 ,
V_57 -> V_78 . V_81 , & V_57 -> V_32 ) ;
if ( V_40 )
goto V_75;
V_40 = F_39 ( V_10 , & V_57 -> V_32 , & V_57 -> V_78 ) ;
if ( V_40 )
goto V_76;
return 0 ;
V_76:
F_35 ( V_10 , & V_57 -> V_32 ) ;
V_75:
F_40 ( V_10 , V_30 * V_10 -> V_45 . V_72 ,
& V_57 -> V_78 ) ;
V_79:
return V_40 ;
}
static void F_41 ( struct V_9 * V_10 ,
struct V_67 * V_57 , int V_71 )
{
F_40 ( V_10 , ( V_71 + 1 ) * V_10 -> V_45 . V_72 ,
& V_57 -> V_78 ) ;
}
struct V_3 * F_42 ( struct V_82 * V_83 ,
const struct V_84 * V_85 ,
struct V_65 * V_66 ,
struct V_86 * V_87 )
{
struct V_9 * V_10 = F_3 ( V_83 ) ;
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
struct F_42 V_88 ;
struct V_1 * V_2 = NULL ;
struct V_33 * V_59 = NULL ;
int V_35 = V_85 -> V_89 ;
int V_90 = V_85 -> V_71 ;
int V_40 = 0 ;
if ( V_90 < 1 || V_90 > V_10 -> V_45 . V_91 ) {
F_4 ( V_18 , L_9 ,
V_90 , V_10 -> V_45 . V_91 ) ;
return F_43 ( - V_44 ) ;
}
V_2 = F_44 ( sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return F_43 ( - V_48 ) ;
if ( V_90 < V_93 )
V_90 = V_93 ;
V_90 = F_45 ( ( unsigned int ) V_90 ) ;
V_2 -> V_3 . V_71 = V_90 - 1 ;
F_46 ( & V_2 -> V_51 ) ;
if ( V_66 ) {
if ( F_47 ( & V_88 , V_87 , sizeof( V_88 ) ) ) {
F_4 ( V_18 , L_10 ) ;
V_40 = - V_94 ;
goto V_95;
}
V_40 = F_29 ( V_10 , V_66 , & V_2 -> V_78 ,
& V_2 -> V_69 , V_88 . V_70 ,
V_90 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_11 ) ;
goto V_95;
}
V_59 = & F_48 ( V_66 ) -> V_59 ;
} else {
V_40 = F_37 ( V_10 , & V_2 -> V_78 ,
V_90 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_12 ) ;
goto V_95;
}
V_59 = & V_10 -> V_96 ;
V_2 -> V_97 = V_10 -> V_98 + V_99 +
0x1000 * V_59 -> V_100 ;
}
V_40 = F_7 ( V_10 , V_90 , & V_2 -> V_78 . V_32 , V_59 ,
V_2 , V_35 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_13 ) ;
goto V_76;
}
V_2 -> V_101 = F_1 ;
V_2 -> V_12 = F_2 ;
V_2 -> V_102 = V_90 ;
if ( V_66 ) {
if ( F_49 ( V_87 , & V_2 -> V_19 , sizeof( T_2 ) ) ) {
V_40 = - V_94 ;
goto V_103;
}
}
return & V_2 -> V_3 ;
V_103:
F_24 ( V_10 , V_2 ) ;
V_76:
F_35 ( V_10 , & V_2 -> V_78 . V_32 ) ;
if ( V_66 )
F_36 ( V_2 -> V_69 ) ;
else
F_41 ( V_10 , & V_2 -> V_78 ,
V_2 -> V_3 . V_71 ) ;
V_95:
F_50 ( V_2 ) ;
return F_43 ( V_40 ) ;
}
int F_51 ( struct V_3 * V_3 )
{
struct V_9 * V_10 = F_3 ( V_3 -> V_13 ) ;
struct V_1 * V_2 = F_52 ( V_3 ) ;
F_24 ( V_10 , V_2 ) ;
F_35 ( V_10 , & V_2 -> V_78 . V_32 ) ;
if ( V_3 -> V_104 )
F_36 ( V_2 -> V_69 ) ;
else
F_41 ( V_10 , & V_2 -> V_78 , V_3 -> V_71 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
void F_53 ( struct V_9 * V_10 , T_3 V_19 )
{
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
struct V_1 * V_23 ;
V_23 = F_54 ( & V_10 -> V_37 . V_52 ,
V_19 & ( V_10 -> V_45 . V_105 - 1 ) ) ;
if ( ! V_23 ) {
F_55 ( V_18 , L_14 , V_19 ) ;
return;
}
V_23 -> V_101 ( V_23 ) ;
}
void F_56 ( struct V_9 * V_10 , T_3 V_19 , int V_8 )
{
struct V_36 * V_37 = & V_10 -> V_37 ;
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
struct V_1 * V_23 ;
V_23 = F_54 ( & V_37 -> V_52 ,
V_19 & ( V_10 -> V_45 . V_105 - 1 ) ) ;
if ( V_23 )
F_57 ( & V_23 -> V_60 ) ;
if ( ! V_23 ) {
F_55 ( V_18 , L_15 , V_19 ) ;
return;
}
V_23 -> V_12 ( V_23 , (enum V_7 ) V_8 ) ;
if ( F_26 ( & V_23 -> V_60 ) )
F_27 ( & V_23 -> free ) ;
}
int F_58 ( struct V_9 * V_10 )
{
struct V_36 * V_37 = & V_10 -> V_37 ;
F_46 ( & V_37 -> V_51 ) ;
F_59 ( & V_37 -> V_52 , V_106 ) ;
return F_60 ( & V_37 -> V_47 , V_10 -> V_45 . V_105 ,
V_10 -> V_45 . V_105 - 1 ,
V_10 -> V_45 . V_107 , 0 ) ;
}
void F_61 ( struct V_9 * V_10 )
{
F_62 ( & V_10 -> V_37 . V_47 ) ;
}
