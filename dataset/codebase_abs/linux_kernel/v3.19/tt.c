static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 . V_5 -> V_6 ;
if ( F_2 ( V_7 , & V_2 -> V_8 ) )
return;
F_3 ( V_2 , L_1 ) ;
F_4 ( V_2 , true ) ;
if ( ! V_2 -> V_9 )
F_5 ( & V_2 -> V_4 . V_10 ,
F_6 ( V_3 * V_11 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_7 , & V_2 -> V_8 ) )
return;
F_3 ( V_2 , L_2 ) ;
F_4 ( V_2 , false ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_12 )
{
if ( V_2 -> V_9 )
return;
if ( V_2 -> V_13 == V_12 )
return;
V_2 -> V_13 = V_12 ;
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int V_18 = F_11 ( V_15 ) ;
int V_12 ;
if ( F_12 ( V_18 != sizeof( * V_17 ) ) ) {
F_3 ( V_2 , L_3 ) ;
return - V_19 ;
}
V_17 = ( void * ) V_15 -> V_20 ;
V_12 = F_13 ( V_17 -> V_12 ) ;
if ( F_12 ( V_12 < 0 ) )
V_12 = 0 ;
F_14 ( V_2 , L_4 , V_12 ) ;
return V_12 ;
}
static bool F_15 ( struct V_21 * V_22 ,
struct V_14 * V_15 , void * V_20 )
{
struct V_1 * V_2 =
F_16 ( V_22 , struct V_1 , V_22 ) ;
int * V_12 = V_20 ;
int V_23 ;
V_23 = F_10 ( V_2 , V_15 ) ;
if ( V_23 < 0 )
return true ;
* V_12 = V_23 ;
return true ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_14 * V_15 = F_18 ( V_25 ) ;
int V_12 ;
if ( F_2 ( V_7 , & V_2 -> V_8 ) )
return 0 ;
V_12 = F_10 ( V_2 , V_15 ) ;
if ( V_12 < 0 )
return 0 ;
F_8 ( V_2 , V_12 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_28 V_27 = {
. V_29 = F_20 ( V_30 ) ,
} ;
return F_21 ( V_2 , V_31 , 0 ,
sizeof( V_27 ) , & V_27 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_32 V_33 ;
static const T_2 V_34 [] = { V_35 } ;
int V_23 , V_12 ;
F_23 ( & V_2 -> V_36 ) ;
F_24 ( & V_2 -> V_22 , & V_33 ,
V_34 , F_25 ( V_34 ) ,
F_15 , & V_12 ) ;
V_23 = F_19 ( V_2 ) ;
if ( V_23 ) {
F_3 ( V_2 , L_5 , V_23 ) ;
F_26 ( & V_2 -> V_22 , & V_33 ) ;
return V_23 ;
}
V_23 = F_27 ( & V_2 -> V_22 , & V_33 ,
V_37 ) ;
if ( V_23 ) {
F_3 ( V_2 , L_6 ) ;
return V_23 ;
}
return V_12 ;
}
static void F_28 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_1 * V_2 ;
T_1 V_3 ;
T_3 V_12 ;
V_41 = F_16 ( V_39 , struct V_40 , V_10 . V_39 ) ;
V_2 = F_16 ( V_41 , struct V_1 , V_4 ) ;
V_3 = V_41 -> V_5 -> V_6 ;
F_29 ( & V_2 -> V_36 ) ;
if ( F_30 ( V_2 ) )
goto V_42;
if ( F_31 ( V_2 , V_43 ) ) {
F_32 ( V_2 ) ;
goto V_42;
}
V_12 = F_22 ( V_2 ) ;
F_33 ( V_2 , V_43 ) ;
F_32 ( V_2 ) ;
if ( V_12 < 0 )
goto V_42;
F_14 ( V_2 , L_7 , V_12 ) ;
if ( V_12 <= V_41 -> V_5 -> V_10 ) {
F_34 ( & V_2 -> V_36 ) ;
F_7 ( V_2 ) ;
return;
}
V_42:
F_34 ( & V_2 -> V_36 ) ;
F_5 ( & V_2 -> V_4 . V_10 ,
F_35 ( V_3 * V_11 ) ) ;
}
static void F_36 ( void * V_44 , T_2 * V_45 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = V_44 ;
enum V_48 V_49 ;
F_23 ( & V_2 -> V_36 ) ;
if ( V_2 -> V_4 . V_50 )
V_49 = V_51 ;
else
V_49 = V_52 ;
if ( V_47 -> type != V_53 )
return;
F_37 ( V_2 , V_47 , V_54 , V_49 ) ;
}
static void F_38 ( struct V_1 * V_2 , bool V_55 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_60 , V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; V_60 ++ ) {
V_57 = F_39 ( V_2 -> V_63 [ V_60 ] ,
F_40 ( & V_2 -> V_36 ) ) ;
if ( F_41 ( V_57 ) )
continue;
V_59 = F_42 ( V_57 ) ;
if ( V_55 == V_59 -> V_64 )
continue;
V_61 = F_43 ( V_2 , V_59 , V_55 ) ;
if ( V_61 ) {
F_3 ( V_2 , L_8 ,
V_55 ? L_9 : L_10 ) ;
} else {
F_14 ( V_2 , L_11 ,
V_55 ? L_12 : L_13 ) ;
V_59 -> V_64 = V_55 ;
}
}
}
void F_44 ( struct V_1 * V_2 , T_1 V_65 )
{
struct V_66 V_27 = {
. V_67 = V_68 ,
. V_18 = { sizeof( T_1 ) , } ,
. V_20 = { & V_65 , } ,
} ;
V_65 = F_45 ( V_65 , V_2 -> V_4 . V_69 ) ;
if ( F_46 ( V_2 , & V_27 ) == 0 ) {
F_14 ( V_2 , L_14 ,
V_65 ) ;
V_2 -> V_4 . V_70 = V_65 ;
} else {
F_3 ( V_2 , L_15 ) ;
}
}
void F_9 ( struct V_1 * V_2 )
{
const struct V_71 * V_5 = V_2 -> V_4 . V_5 ;
struct V_40 * V_41 = & V_2 -> V_4 ;
T_3 V_13 = V_2 -> V_13 ;
bool V_72 = false ;
int V_60 ;
T_1 V_70 ;
F_14 ( V_2 , L_7 , V_2 -> V_13 ) ;
if ( V_5 -> V_73 && V_13 >= V_5 -> V_74 ) {
F_1 ( V_2 ) ;
return;
}
if ( V_5 -> V_73 &&
V_13 <= V_41 -> V_5 -> V_10 ) {
F_7 ( V_2 ) ;
return;
}
if ( V_5 -> V_75 ) {
if ( ! V_41 -> V_50 &&
V_13 >= V_5 -> V_76 ) {
F_14 ( V_2 , L_16 ) ;
V_41 -> V_50 = true ;
F_47 (
V_2 -> V_77 , V_78 ,
F_36 , V_2 ) ;
V_72 = true ;
} else if ( V_41 -> V_50 &&
V_13 <= V_5 -> V_79 ) {
F_14 ( V_2 , L_17 ) ;
V_41 -> V_50 = false ;
F_47 (
V_2 -> V_77 , V_78 ,
F_36 , V_2 ) ;
}
}
if ( V_5 -> V_80 ) {
if ( V_13 >= V_5 -> V_81 ) {
F_38 ( V_2 , true ) ;
V_72 = true ;
} else if ( V_13 <= V_5 -> V_82 ) {
F_38 ( V_2 , false ) ;
}
}
if ( V_5 -> V_83 ) {
V_70 = V_41 -> V_69 ;
for ( V_60 = 0 ; V_60 < V_84 ; V_60 ++ ) {
if ( V_13 < V_5 -> V_70 [ V_60 ] . V_13 )
break;
V_70 = F_45 ( V_41 -> V_69 ,
V_5 -> V_70 [ V_60 ] . V_65 ) ;
}
if ( V_70 != V_41 -> V_69 )
V_72 = true ;
if ( V_41 -> V_70 != V_70 )
F_44 ( V_2 , V_70 ) ;
}
if ( ! V_41 -> V_85 && V_72 ) {
F_48 ( V_2 ,
L_18 ) ;
V_41 -> V_85 = true ;
} else if ( V_41 -> V_85 && ! V_41 -> V_50 &&
V_41 -> V_70 == V_41 -> V_69 &&
V_13 <= V_5 -> V_82 ) {
F_48 ( V_2 ,
L_19 ) ;
V_41 -> V_85 = false ;
}
}
void F_49 ( struct V_1 * V_2 , T_1 V_69 )
{
struct V_40 * V_41 = & V_2 -> V_4 ;
F_14 ( V_2 , L_20 ) ;
if ( V_2 -> V_86 -> V_87 )
V_41 -> V_5 = & V_88 ;
else
V_41 -> V_5 = & V_89 ;
V_41 -> V_85 = false ;
V_41 -> V_69 = V_69 ;
F_50 ( & V_41 -> V_10 , F_28 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_4 . V_10 ) ;
F_14 ( V_2 , L_21 ) ;
}
