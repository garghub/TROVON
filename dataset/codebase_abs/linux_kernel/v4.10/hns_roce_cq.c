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
F_22 ( & V_37 -> V_47 , V_2 -> V_19 , V_61 ) ;
return V_40 ;
}
static int F_23 ( struct V_9 * V_18 ,
struct V_24 * V_25 ,
unsigned long V_26 )
{
return F_6 ( V_18 , 0 , V_25 ? V_25 -> V_27 : 0 , V_26 ,
V_25 ? 0 : 1 , V_62 ,
V_29 ) ;
}
void F_24 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_36 * V_37 = & V_10 -> V_37 ;
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
int V_40 ;
V_40 = F_23 ( V_10 , NULL , V_2 -> V_19 ) ;
if ( V_40 )
F_4 ( V_18 , L_8 , V_40 ,
V_2 -> V_19 ) ;
F_25 ( V_10 -> V_63 . V_64 [ V_2 -> V_35 ] . V_65 ) ;
if ( F_26 ( & V_2 -> V_60 ) )
F_27 ( & V_2 -> free ) ;
F_28 ( & V_2 -> free ) ;
F_11 ( & V_37 -> V_51 ) ;
F_20 ( & V_37 -> V_52 , V_2 -> V_19 ) ;
F_13 ( & V_37 -> V_51 ) ;
F_21 ( V_10 , & V_37 -> V_49 , V_2 -> V_19 ) ;
F_22 ( & V_37 -> V_47 , V_2 -> V_19 , V_61 ) ;
}
static int F_29 ( struct V_9 * V_10 ,
struct V_66 * V_67 ,
struct V_68 * V_57 ,
struct V_69 * * V_70 , T_2 V_71 , int V_72 )
{
int V_40 ;
* V_70 = F_30 ( V_67 , V_71 , V_72 * V_10 -> V_45 . V_73 ,
V_74 , 1 ) ;
if ( F_15 ( * V_70 ) )
return F_16 ( * V_70 ) ;
V_40 = F_31 ( V_10 , F_32 ( * V_70 ) ,
F_33 ( ( unsigned int ) ( * V_70 ) -> V_75 ) ,
& V_57 -> V_32 ) ;
if ( V_40 )
goto V_76;
V_40 = F_34 ( V_10 , & V_57 -> V_32 , * V_70 ) ;
if ( V_40 )
goto V_77;
return 0 ;
V_77:
F_35 ( V_10 , & V_57 -> V_32 ) ;
V_76:
F_36 ( * V_70 ) ;
return V_40 ;
}
static int F_37 ( struct V_9 * V_10 ,
struct V_68 * V_57 , T_3 V_30 )
{
int V_40 ;
V_40 = F_38 ( V_10 , V_30 * V_10 -> V_45 . V_73 ,
V_78 * 2 , & V_57 -> V_79 ) ;
if ( V_40 )
goto V_80;
V_40 = F_31 ( V_10 , V_57 -> V_79 . V_81 ,
V_57 -> V_79 . V_82 , & V_57 -> V_32 ) ;
if ( V_40 )
goto V_76;
V_40 = F_39 ( V_10 , & V_57 -> V_32 , & V_57 -> V_79 ) ;
if ( V_40 )
goto V_77;
return 0 ;
V_77:
F_35 ( V_10 , & V_57 -> V_32 ) ;
V_76:
F_40 ( V_10 , V_30 * V_10 -> V_45 . V_73 ,
& V_57 -> V_79 ) ;
V_80:
return V_40 ;
}
static void F_41 ( struct V_9 * V_10 ,
struct V_68 * V_57 , int V_72 )
{
F_40 ( V_10 , ( V_72 + 1 ) * V_10 -> V_45 . V_73 ,
& V_57 -> V_79 ) ;
}
struct V_3 * F_42 ( struct V_83 * V_84 ,
const struct V_85 * V_86 ,
struct V_66 * V_67 ,
struct V_87 * V_88 )
{
struct V_9 * V_10 = F_3 ( V_84 ) ;
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
struct F_42 V_89 ;
struct V_1 * V_2 = NULL ;
struct V_33 * V_59 = NULL ;
int V_35 = V_86 -> V_90 ;
int V_91 = V_86 -> V_72 ;
int V_40 = 0 ;
if ( V_91 < 1 || V_91 > V_10 -> V_45 . V_92 ) {
F_4 ( V_18 , L_9 ,
V_91 , V_10 -> V_45 . V_92 ) ;
return F_43 ( - V_44 ) ;
}
V_2 = F_44 ( sizeof( * V_2 ) , V_93 ) ;
if ( ! V_2 )
return F_43 ( - V_48 ) ;
if ( V_91 < V_94 )
V_91 = V_94 ;
V_91 = F_45 ( ( unsigned int ) V_91 ) ;
V_2 -> V_3 . V_72 = V_91 - 1 ;
F_46 ( & V_2 -> V_51 ) ;
if ( V_67 ) {
if ( F_47 ( & V_89 , V_88 , sizeof( V_89 ) ) ) {
F_4 ( V_18 , L_10 ) ;
V_40 = - V_95 ;
goto V_96;
}
V_40 = F_29 ( V_10 , V_67 , & V_2 -> V_79 ,
& V_2 -> V_70 , V_89 . V_71 ,
V_91 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_11 ) ;
goto V_96;
}
V_59 = & F_48 ( V_67 ) -> V_59 ;
} else {
V_40 = F_37 ( V_10 , & V_2 -> V_79 ,
V_91 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_12 ) ;
goto V_96;
}
V_59 = & V_10 -> V_97 ;
V_2 -> V_98 = V_10 -> V_99 + V_100 +
0x1000 * V_59 -> V_101 ;
}
V_40 = F_7 ( V_10 , V_91 , & V_2 -> V_79 . V_32 , V_59 ,
V_2 , V_35 ) ;
if ( V_40 ) {
F_4 ( V_18 , L_13 ) ;
goto V_77;
}
if ( ! V_67 )
* V_2 -> V_102 = 0 ;
V_2 -> V_103 = F_1 ;
V_2 -> V_12 = F_2 ;
V_2 -> V_104 = V_91 ;
if ( V_67 ) {
if ( F_49 ( V_88 , & V_2 -> V_19 , sizeof( T_2 ) ) ) {
V_40 = - V_95 ;
goto V_105;
}
}
return & V_2 -> V_3 ;
V_105:
F_24 ( V_10 , V_2 ) ;
V_77:
F_35 ( V_10 , & V_2 -> V_79 . V_32 ) ;
if ( V_67 )
F_36 ( V_2 -> V_70 ) ;
else
F_41 ( V_10 , & V_2 -> V_79 ,
V_2 -> V_3 . V_72 ) ;
V_96:
F_50 ( V_2 ) ;
return F_43 ( V_40 ) ;
}
int F_51 ( struct V_3 * V_3 )
{
struct V_9 * V_10 = F_3 ( V_3 -> V_13 ) ;
struct V_1 * V_2 = F_52 ( V_3 ) ;
int V_40 = 0 ;
if ( V_10 -> V_55 -> V_106 ) {
V_40 = V_10 -> V_55 -> V_106 ( V_3 ) ;
} else {
F_24 ( V_10 , V_2 ) ;
F_35 ( V_10 , & V_2 -> V_79 . V_32 ) ;
if ( V_3 -> V_107 )
F_36 ( V_2 -> V_70 ) ;
else
F_41 ( V_10 , & V_2 -> V_79 ,
V_3 -> V_72 ) ;
F_50 ( V_2 ) ;
}
return V_40 ;
}
void F_53 ( struct V_9 * V_10 , T_3 V_19 )
{
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
struct V_1 * V_23 ;
V_23 = F_54 ( & V_10 -> V_37 . V_52 ,
V_19 & ( V_10 -> V_45 . V_108 - 1 ) ) ;
if ( ! V_23 ) {
F_55 ( V_18 , L_14 , V_19 ) ;
return;
}
V_23 -> V_103 ( V_23 ) ;
}
void F_56 ( struct V_9 * V_10 , T_3 V_19 , int V_8 )
{
struct V_36 * V_37 = & V_10 -> V_37 ;
struct V_13 * V_18 = & V_10 -> V_17 -> V_18 ;
struct V_1 * V_23 ;
V_23 = F_54 ( & V_37 -> V_52 ,
V_19 & ( V_10 -> V_45 . V_108 - 1 ) ) ;
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
F_59 ( & V_37 -> V_52 , V_109 ) ;
return F_60 ( & V_37 -> V_47 , V_10 -> V_45 . V_108 ,
V_10 -> V_45 . V_108 - 1 ,
V_10 -> V_45 . V_110 , 0 ) ;
}
void F_61 ( struct V_9 * V_10 )
{
F_62 ( & V_10 -> V_37 . V_47 ) ;
}
