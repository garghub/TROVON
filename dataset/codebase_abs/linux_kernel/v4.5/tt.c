static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_6 = V_4 -> V_7 . V_8 ;
if ( F_2 ( V_9 , & V_2 -> V_10 ) )
return;
F_3 ( V_2 , L_1 ) ;
F_4 ( V_2 , true ) ;
V_4 -> V_11 = false ;
V_4 -> V_12 = false ;
if ( ! V_2 -> V_13 )
F_5 ( & V_4 -> V_14 ,
F_6 ( V_6 * V_15 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_9 , & V_2 -> V_10 ) )
return;
F_3 ( V_2 , L_2 ) ;
F_4 ( V_2 , false ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_16 )
{
if ( V_2 -> V_13 )
return;
if ( V_2 -> V_17 == V_16 )
return;
V_2 -> V_17 = V_16 ;
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 ;
int V_22 = F_11 ( V_19 ) ;
int V_16 ;
if ( F_12 ( V_22 < sizeof( * V_21 ) ) ) {
F_3 ( V_2 , L_3 ) ;
return - V_23 ;
}
V_21 = ( void * ) V_19 -> V_24 ;
V_16 = F_13 ( V_21 -> V_16 ) ;
if ( F_12 ( V_16 < 0 ) )
V_16 = 0 ;
F_14 ( V_2 , L_4 , V_16 ) ;
return V_16 ;
}
static bool F_15 ( struct V_25 * V_26 ,
struct V_18 * V_19 , void * V_24 )
{
struct V_1 * V_2 =
F_16 ( V_26 , struct V_1 , V_26 ) ;
int * V_16 = V_24 ;
int V_27 ;
V_27 = F_10 ( V_2 , V_19 ) ;
if ( V_27 < 0 )
return true ;
* V_16 = V_27 ;
return true ;
}
void F_17 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_18 * V_19 = F_18 ( V_29 ) ;
int V_16 ;
if ( F_2 ( V_9 , & V_2 -> V_10 ) )
return;
V_16 = F_10 ( V_2 , V_19 ) ;
if ( V_16 < 0 )
return;
F_8 ( V_2 , V_16 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_30 V_31 = {
. V_32 = F_20 ( V_33 ) ,
} ;
struct V_34 V_35 = {
. V_36 = F_20 ( V_37 ) ,
} ;
T_1 V_38 ;
if ( F_21 ( & V_2 -> V_39 -> V_40 , V_41 ) )
V_38 = F_22 ( V_42 ,
V_43 , 0 ) ;
else
V_38 = V_44 ;
if ( ! F_23 ( & V_2 -> V_39 -> V_40 ,
V_45 ) )
return F_24 ( V_2 , V_38 , 0 , sizeof( V_31 ) , & V_31 ) ;
return F_24 ( V_2 , V_38 , 0 , sizeof( V_35 ) , & V_35 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_46 V_47 ;
static T_2 V_48 [] = { F_26 (PHY_OPS_GROUP,
DTS_MEASUREMENT_NOTIF_WIDE) } ;
int V_27 , V_16 ;
if ( ! F_21 ( & V_2 -> V_39 -> V_40 , V_41 ) )
V_48 [ 0 ] = V_49 ;
F_27 ( & V_2 -> V_50 ) ;
F_28 ( & V_2 -> V_26 , & V_47 ,
V_48 , F_29 ( V_48 ) ,
F_15 , & V_16 ) ;
V_27 = F_19 ( V_2 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_5 , V_27 ) ;
F_30 ( & V_2 -> V_26 , & V_47 ) ;
return V_27 ;
}
V_27 = F_31 ( & V_2 -> V_26 , & V_47 ,
V_51 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_6 ) ;
return V_27 ;
}
return V_16 ;
}
static void F_32 ( struct V_52 * V_53 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_1 V_6 ;
T_3 V_16 ;
V_4 = F_16 ( V_53 , struct V_3 , V_14 . V_53 ) ;
V_2 = F_16 ( V_4 , struct V_1 , V_5 ) ;
V_6 = V_4 -> V_7 . V_8 ;
F_33 ( & V_2 -> V_50 ) ;
if ( F_34 ( V_2 ) )
goto V_54;
if ( F_35 ( V_2 , V_55 ) ) {
F_36 ( V_2 ) ;
goto V_54;
}
V_16 = F_25 ( V_2 ) ;
F_37 ( V_2 , V_55 ) ;
F_36 ( V_2 ) ;
if ( V_16 < 0 )
goto V_54;
F_14 ( V_2 , L_7 , V_16 ) ;
if ( V_16 <= V_4 -> V_7 . V_14 ) {
F_38 ( & V_2 -> V_50 ) ;
F_7 ( V_2 ) ;
return;
}
V_54:
F_38 ( & V_2 -> V_50 ) ;
F_5 ( & V_2 -> V_5 . V_14 ,
F_39 ( V_6 * V_15 ) ) ;
}
static void F_40 ( void * V_56 , T_4 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_56 ;
enum V_60 V_61 ;
F_27 ( & V_2 -> V_50 ) ;
if ( V_2 -> V_5 . V_12 )
V_61 = V_62 ;
else
V_61 = V_63 ;
if ( V_59 -> type != V_64 )
return;
F_41 ( V_2 , V_59 , V_65 , V_61 ) ;
}
static void F_42 ( struct V_1 * V_2 , bool V_66 )
{
struct V_67 * V_68 ;
struct V_69 * V_70 ;
int V_71 , V_72 ;
for ( V_71 = 0 ; V_71 < V_73 ; V_71 ++ ) {
V_68 = F_43 ( V_2 -> V_74 [ V_71 ] ,
F_44 ( & V_2 -> V_50 ) ) ;
if ( F_45 ( V_68 ) )
continue;
V_70 = F_46 ( V_68 ) ;
if ( V_66 == V_70 -> V_75 )
continue;
V_72 = F_47 ( V_2 , V_70 , V_66 ) ;
if ( V_72 ) {
F_3 ( V_2 , L_8 ,
V_66 ? L_9 : L_10 ) ;
} else {
F_14 ( V_2 , L_11 ,
V_66 ? L_12 : L_13 ) ;
V_70 -> V_75 = V_66 ;
}
}
}
void F_48 ( struct V_1 * V_2 , T_1 V_76 )
{
struct V_77 V_31 = {
. V_78 = V_79 ,
. V_22 = { sizeof( T_1 ) , } ,
. V_24 = { & V_76 , } ,
} ;
V_76 = F_49 ( V_76 , V_2 -> V_5 . V_80 ) ;
if ( F_50 ( V_2 , & V_31 ) == 0 ) {
F_14 ( V_2 , L_14 ,
V_76 ) ;
V_2 -> V_5 . V_81 = V_76 ;
} else {
F_3 ( V_2 , L_15 ) ;
}
}
void F_9 ( struct V_1 * V_2 )
{
struct V_82 * V_7 = & V_2 -> V_5 . V_7 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_3 V_17 = V_2 -> V_17 ;
bool V_83 = false ;
int V_71 ;
T_1 V_81 ;
F_14 ( V_2 , L_7 , V_2 -> V_17 ) ;
if ( V_7 -> V_84 && V_17 >= V_7 -> V_85 ) {
F_1 ( V_2 ) ;
return;
}
if ( V_7 -> V_84 &&
V_17 <= V_7 -> V_14 ) {
F_7 ( V_2 ) ;
return;
}
if ( V_7 -> V_86 ) {
if ( ! V_4 -> V_12 &&
V_17 >= V_7 -> V_87 ) {
F_14 ( V_2 , L_16 ) ;
V_4 -> V_12 = true ;
F_51 (
V_2 -> V_88 , V_89 ,
F_40 , V_2 ) ;
V_83 = true ;
} else if ( V_4 -> V_12 &&
V_17 <= V_7 -> V_90 ) {
F_14 ( V_2 , L_17 ) ;
V_4 -> V_12 = false ;
F_51 (
V_2 -> V_88 , V_89 ,
F_40 , V_2 ) ;
}
}
if ( V_7 -> V_91 ) {
if ( V_17 >= V_7 -> V_92 ) {
F_42 ( V_2 , true ) ;
V_83 = true ;
} else if ( V_17 <= V_7 -> V_93 ) {
F_42 ( V_2 , false ) ;
}
}
if ( V_7 -> V_94 ) {
V_81 = V_4 -> V_80 ;
for ( V_71 = 0 ; V_71 < V_95 ; V_71 ++ ) {
if ( V_17 < V_7 -> V_81 [ V_71 ] . V_17 )
break;
V_81 = F_49 ( V_4 -> V_80 ,
V_7 -> V_81 [ V_71 ] . V_76 ) ;
}
if ( V_81 != V_4 -> V_80 )
V_83 = true ;
if ( V_4 -> V_81 != V_81 )
F_48 ( V_2 , V_81 ) ;
}
if ( ! V_4 -> V_11 && V_83 ) {
F_52 ( V_2 ,
L_18 ) ;
V_4 -> V_11 = true ;
} else if ( V_4 -> V_11 && ! V_4 -> V_12 &&
V_4 -> V_81 == V_4 -> V_80 &&
V_17 <= V_7 -> V_93 ) {
F_52 ( V_2 ,
L_19 ) ;
V_4 -> V_11 = false ;
}
}
void F_53 ( struct V_1 * V_2 , T_1 V_80 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_14 ( V_2 , L_20 ) ;
if ( V_2 -> V_96 -> V_97 )
V_4 -> V_7 = * V_2 -> V_96 -> V_97 ;
else
V_4 -> V_7 = V_98 ;
V_4 -> V_11 = false ;
V_4 -> V_12 = false ;
V_4 -> V_80 = V_80 ;
F_54 ( & V_4 -> V_14 , F_32 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_56 ( & V_2 -> V_5 . V_14 ) ;
F_14 ( V_2 , L_21 ) ;
}
