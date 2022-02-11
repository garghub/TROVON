static inline int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , bool V_5 )
{
unsigned int V_6 , V_7 , V_8 ;
V_8 = V_5 ? V_4 -> V_9 : V_4 -> V_10 ;
V_7 = F_2 ( V_4 -> V_11 , V_4 -> V_12 ) ;
V_6 = ( V_8 << V_4 -> V_12 ) | ( V_7 << V_13 ) ;
return F_3 ( V_2 -> V_14 , V_4 -> V_15 , V_6 ) ;
}
static inline bool F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_16 ;
unsigned int V_8 , V_17 ;
unsigned int V_7 = F_2 ( V_4 -> V_11 , V_4 -> V_12 ) ;
V_16 = F_5 ( V_2 -> V_14 , V_4 -> V_15 , & V_17 ) ;
if ( V_16 )
return false ;
V_8 = ( V_17 & V_7 ) >> V_4 -> V_12 ;
return V_8 == V_4 -> V_9 ;
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_7 ( V_19 , struct V_1 , V_20 ) ;
int V_16 ;
if ( ! F_4 ( V_2 , & V_2 -> V_21 -> V_22 ) ) {
V_16 = F_1 ( V_2 , & V_2 -> V_21 -> V_22 , true ) ;
if ( V_16 )
return V_16 ;
F_8 ( 1 ) ;
}
return 0 ;
}
static void F_9 ( struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_7 ( V_19 , struct V_1 , V_20 ) ;
F_1 ( V_2 , & V_2 -> V_21 -> V_22 , false ) ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_7 ( V_19 , struct V_1 , V_20 ) ;
return F_4 ( V_2 , & V_2 -> V_21 -> V_22 ) ;
}
static unsigned long
F_11 ( struct V_18 * V_19 ,
unsigned long V_23 )
{
return 480000000 ;
}
static void F_12 ( void * V_24 )
{
struct V_1 * V_2 = V_24 ;
F_13 ( V_2 -> V_25 -> V_26 ) ;
F_14 ( V_2 -> V_27 ) ;
}
static int
F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_25 -> V_26 ;
struct V_30 V_31 ;
const char * V_32 ;
int V_16 ;
V_31 . V_33 = 0 ;
V_31 . V_34 = L_1 ;
V_31 . V_35 = & V_36 ;
F_16 ( V_29 , L_2 , & V_31 . V_34 ) ;
if ( V_2 -> V_37 ) {
V_32 = F_17 ( V_2 -> V_37 ) ;
V_31 . V_38 = & V_32 ;
V_31 . V_39 = 1 ;
} else {
V_31 . V_38 = NULL ;
V_31 . V_39 = 0 ;
}
V_2 -> V_20 . V_31 = & V_31 ;
V_2 -> V_27 = F_18 ( V_2 -> V_25 , & V_2 -> V_20 ) ;
if ( F_19 ( V_2 -> V_27 ) ) {
V_16 = F_20 ( V_2 -> V_27 ) ;
goto V_40;
}
V_16 = F_21 ( V_29 , V_41 , V_2 -> V_27 ) ;
if ( V_16 < 0 )
goto V_42;
V_16 = F_22 ( V_2 -> V_25 , F_12 ,
V_2 ) ;
if ( V_16 < 0 )
goto V_43;
return 0 ;
V_43:
F_13 ( V_29 ) ;
V_42:
F_14 ( V_2 -> V_27 ) ;
V_40:
return V_16 ;
}
static int F_23 ( struct V_44 * V_44 )
{
struct V_45 * V_46 = F_24 ( V_44 ) ;
struct V_1 * V_2 = F_25 ( V_44 -> V_25 . V_47 ) ;
int V_16 ;
if ( V_46 -> V_48 == V_49 ) {
F_26 ( & V_46 -> V_50 ) ;
V_16 = F_1 ( V_2 , & V_46 -> V_51 -> V_52 , true ) ;
if ( V_16 ) {
F_27 ( & V_46 -> V_50 ) ;
return V_16 ;
}
V_16 = F_1 ( V_2 , & V_46 -> V_51 -> V_53 , true ) ;
if ( V_16 ) {
F_27 ( & V_46 -> V_50 ) ;
return V_16 ;
}
F_27 ( & V_46 -> V_50 ) ;
F_28 ( & V_46 -> V_54 , V_55 ) ;
}
return 0 ;
}
static int F_29 ( struct V_44 * V_44 )
{
struct V_45 * V_46 = F_24 ( V_44 ) ;
struct V_1 * V_2 = F_25 ( V_44 -> V_25 . V_47 ) ;
int V_16 ;
F_30 ( & V_46 -> V_44 -> V_25 , L_3 ) ;
if ( ! V_46 -> V_56 )
return 0 ;
V_16 = F_31 ( V_2 -> V_27 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , & V_46 -> V_51 -> V_57 , false ) ;
if ( V_16 )
return V_16 ;
V_46 -> V_56 = false ;
return 0 ;
}
static int F_32 ( struct V_44 * V_44 )
{
struct V_45 * V_46 = F_24 ( V_44 ) ;
struct V_1 * V_2 = F_25 ( V_44 -> V_25 . V_47 ) ;
int V_16 ;
F_30 ( & V_46 -> V_44 -> V_25 , L_4 ) ;
if ( V_46 -> V_56 )
return 0 ;
V_16 = F_1 ( V_2 , & V_46 -> V_51 -> V_57 , true ) ;
if ( V_16 )
return V_16 ;
V_46 -> V_56 = true ;
F_33 ( V_2 -> V_27 ) ;
return 0 ;
}
static int F_34 ( struct V_44 * V_44 )
{
struct V_45 * V_46 = F_24 ( V_44 ) ;
if ( V_46 -> V_48 == V_49 )
F_35 ( & V_46 -> V_54 ) ;
return 0 ;
}
static void F_36 ( struct V_58 * V_59 )
{
struct V_45 * V_46 =
F_7 ( V_59 , struct V_45 , V_54 . V_59 ) ;
struct V_1 * V_2 = F_25 ( V_46 -> V_44 -> V_25 . V_47 ) ;
unsigned int V_60 = V_46 -> V_51 -> V_61 . V_11 -
V_46 -> V_51 -> V_61 . V_12 + 1 ;
unsigned int V_62 , V_63 , V_64 ;
unsigned int V_65 , V_66 ;
int V_16 ;
F_26 ( & V_46 -> V_50 ) ;
V_16 = F_5 ( V_2 -> V_14 , V_46 -> V_51 -> V_67 . V_15 , & V_62 ) ;
if ( V_16 < 0 )
goto V_68;
V_16 = F_5 ( V_2 -> V_14 , V_46 -> V_51 -> V_61 . V_15 ,
& V_63 ) ;
if ( V_16 < 0 )
goto V_68;
V_66 = F_2 ( V_46 -> V_51 -> V_61 . V_11 ,
V_46 -> V_51 -> V_61 . V_12 ) ;
V_65 = F_2 ( V_46 -> V_51 -> V_67 . V_11 ,
V_46 -> V_51 -> V_67 . V_12 ) ;
V_64 = ( ( V_63 & V_66 ) >> V_46 -> V_51 -> V_61 . V_12 ) |
( ( ( V_62 & V_65 ) >> V_46 -> V_51 -> V_67 . V_12 ) << V_60 ) ;
switch ( V_64 ) {
case V_69 :
F_30 ( & V_46 -> V_44 -> V_25 , L_5 ) ;
break;
case V_70 :
if ( ! V_46 -> V_56 ) {
F_30 ( & V_46 -> V_44 -> V_25 , L_6 ) ;
break;
}
case V_71 :
if ( V_46 -> V_56 ) {
F_30 ( & V_46 -> V_44 -> V_25 , L_7 ) ;
F_29 ( V_46 -> V_44 ) ;
V_46 -> V_56 = false ;
} else {
F_30 ( & V_46 -> V_44 -> V_25 , L_6 ) ;
}
break;
case V_72 :
if ( ! V_46 -> V_56 ) {
F_30 ( & V_46 -> V_44 -> V_25 , L_8 ) ;
F_32 ( V_46 -> V_44 ) ;
V_46 -> V_56 = true ;
}
F_1 ( V_2 , & V_46 -> V_51 -> V_52 , true ) ;
F_1 ( V_2 , & V_46 -> V_51 -> V_53 , true ) ;
F_27 ( & V_46 -> V_50 ) ;
return;
default:
F_30 ( & V_46 -> V_44 -> V_25 , L_9 ) ;
break;
}
V_68:
F_27 ( & V_46 -> V_50 ) ;
F_28 ( & V_46 -> V_54 , V_55 ) ;
}
static T_1 F_37 ( int V_73 , void * V_24 )
{
struct V_45 * V_46 = V_24 ;
struct V_1 * V_2 = F_25 ( V_46 -> V_44 -> V_25 . V_47 ) ;
if ( ! F_4 ( V_2 , & V_46 -> V_51 -> V_74 ) )
return V_75 ;
F_26 ( & V_46 -> V_50 ) ;
F_1 ( V_2 , & V_46 -> V_51 -> V_53 , false ) ;
F_1 ( V_2 , & V_46 -> V_51 -> V_52 , true ) ;
F_27 ( & V_46 -> V_50 ) ;
if ( V_46 -> V_56 && V_46 -> V_48 == V_49 )
F_36 ( & V_46 -> V_54 . V_59 ) ;
return V_76 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_28 * V_77 )
{
int V_16 ;
V_46 -> V_48 = V_49 ;
V_46 -> V_51 = & V_2 -> V_21 -> V_78 [ V_49 ] ;
V_46 -> V_56 = true ;
F_39 ( & V_46 -> V_50 ) ;
F_40 ( & V_46 -> V_54 , F_36 ) ;
V_46 -> V_79 = F_41 ( V_77 , L_10 ) ;
if ( V_46 -> V_79 < 0 ) {
F_42 ( V_2 -> V_25 , L_11 ) ;
return V_46 -> V_79 ;
}
V_16 = F_43 ( V_2 -> V_25 , V_46 -> V_79 , NULL ,
F_37 ,
V_80 ,
L_12 , V_46 ) ;
if ( V_16 ) {
F_42 ( V_2 -> V_25 , L_13 ) ;
return V_16 ;
}
return 0 ;
}
static int F_44 ( struct V_81 * V_82 )
{
struct V_83 * V_25 = & V_82 -> V_25 ;
struct V_28 * V_84 = V_25 -> V_26 ;
struct V_28 * V_77 ;
struct V_85 * V_86 ;
struct V_1 * V_2 ;
const struct V_87 * V_88 ;
const struct V_89 * V_90 ;
unsigned int V_4 ;
int V_91 , V_16 ;
V_2 = F_45 ( V_25 , sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return - V_93 ;
V_90 = F_46 ( V_25 -> V_94 -> V_95 , V_25 ) ;
if ( ! V_90 || ! V_90 -> V_24 ) {
F_42 ( V_25 , L_14 ) ;
return - V_96 ;
}
if ( ! V_25 -> V_47 || ! V_25 -> V_47 -> V_26 )
return - V_96 ;
V_2 -> V_14 = F_47 ( V_25 -> V_47 -> V_26 ) ;
if ( F_19 ( V_2 -> V_14 ) )
return F_20 ( V_2 -> V_14 ) ;
if ( F_48 ( V_84 , L_15 , & V_4 ) ) {
F_42 ( V_25 , L_16 ,
V_84 -> V_34 ) ;
return - V_96 ;
}
V_2 -> V_25 = V_25 ;
V_88 = V_90 -> V_24 ;
F_49 ( V_82 , V_2 ) ;
V_91 = 0 ;
while ( V_88 [ V_91 ] . V_4 ) {
if ( V_88 [ V_91 ] . V_4 == V_4 ) {
V_2 -> V_21 = & V_88 [ V_91 ] ;
break;
}
++ V_91 ;
}
if ( ! V_2 -> V_21 ) {
F_42 ( V_25 , L_17 ,
V_84 -> V_34 ) ;
return - V_96 ;
}
V_2 -> V_37 = F_50 ( V_84 , L_18 ) ;
if ( ! F_19 ( V_2 -> V_37 ) ) {
F_31 ( V_2 -> V_37 ) ;
} else {
F_51 ( & V_82 -> V_25 , L_19 ) ;
V_2 -> V_37 = NULL ;
}
V_16 = F_15 ( V_2 ) ;
if ( V_16 ) {
F_42 ( V_25 , L_20 ) ;
goto V_97;
}
V_91 = 0 ;
F_52 (np, child_np) {
struct V_45 * V_46 = & V_2 -> V_98 [ V_91 ] ;
struct V_44 * V_44 ;
if ( F_53 ( V_77 -> V_34 , L_21 ) )
goto V_99;
V_44 = F_54 ( V_25 , V_77 , & V_100 ) ;
if ( F_19 ( V_44 ) ) {
F_42 ( V_25 , L_22 ) ;
V_16 = F_20 ( V_44 ) ;
goto V_101;
}
V_46 -> V_44 = V_44 ;
F_55 ( V_46 -> V_44 , V_46 ) ;
V_16 = F_38 ( V_2 , V_46 , V_77 ) ;
if ( V_16 )
goto V_101;
V_99:
if ( ++ V_91 >= V_2 -> V_21 -> V_102 )
break;
}
V_86 = F_56 ( V_25 , V_103 ) ;
return F_57 ( V_86 ) ;
V_101:
F_58 ( V_77 ) ;
V_97:
if ( V_2 -> V_37 ) {
F_33 ( V_2 -> V_37 ) ;
F_59 ( V_2 -> V_37 ) ;
}
return V_16 ;
}
