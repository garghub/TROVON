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
if ( F_12 ( V_22 != sizeof( * V_21 ) ) ) {
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
return F_21 ( V_2 , V_34 , 0 ,
sizeof( V_31 ) , & V_31 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_35 V_36 ;
static const T_2 V_37 [] = { V_38 } ;
int V_27 , V_16 ;
F_23 ( & V_2 -> V_39 ) ;
F_24 ( & V_2 -> V_26 , & V_36 ,
V_37 , F_25 ( V_37 ) ,
F_15 , & V_16 ) ;
V_27 = F_19 ( V_2 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_5 , V_27 ) ;
F_26 ( & V_2 -> V_26 , & V_36 ) ;
return V_27 ;
}
V_27 = F_27 ( & V_2 -> V_26 , & V_36 ,
V_40 ) ;
if ( V_27 ) {
F_3 ( V_2 , L_6 ) ;
return V_27 ;
}
return V_16 ;
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_1 V_6 ;
T_3 V_16 ;
V_4 = F_16 ( V_42 , struct V_3 , V_14 . V_42 ) ;
V_2 = F_16 ( V_4 , struct V_1 , V_5 ) ;
V_6 = V_4 -> V_7 . V_8 ;
F_29 ( & V_2 -> V_39 ) ;
if ( F_30 ( V_2 ) )
goto V_43;
if ( F_31 ( V_2 , V_44 ) ) {
F_32 ( V_2 ) ;
goto V_43;
}
V_16 = F_22 ( V_2 ) ;
F_33 ( V_2 , V_44 ) ;
F_32 ( V_2 ) ;
if ( V_16 < 0 )
goto V_43;
F_14 ( V_2 , L_7 , V_16 ) ;
if ( V_16 <= V_4 -> V_7 . V_14 ) {
F_34 ( & V_2 -> V_39 ) ;
F_7 ( V_2 ) ;
return;
}
V_43:
F_34 ( & V_2 -> V_39 ) ;
F_5 ( & V_2 -> V_5 . V_14 ,
F_35 ( V_6 * V_15 ) ) ;
}
static void F_36 ( void * V_45 , T_4 * V_46 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = V_45 ;
enum V_49 V_50 ;
F_23 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_5 . V_12 )
V_50 = V_51 ;
else
V_50 = V_52 ;
if ( V_48 -> type != V_53 )
return;
F_37 ( V_2 , V_48 , V_54 , V_50 ) ;
}
static void F_38 ( struct V_1 * V_2 , bool V_55 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
int V_60 , V_61 ;
for ( V_60 = 0 ; V_60 < V_62 ; V_60 ++ ) {
V_57 = F_39 ( V_2 -> V_63 [ V_60 ] ,
F_40 ( & V_2 -> V_39 ) ) ;
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
struct V_66 V_31 = {
. V_67 = V_68 ,
. V_22 = { sizeof( T_1 ) , } ,
. V_24 = { & V_65 , } ,
} ;
V_65 = F_45 ( V_65 , V_2 -> V_5 . V_69 ) ;
if ( F_46 ( V_2 , & V_31 ) == 0 ) {
F_14 ( V_2 , L_14 ,
V_65 ) ;
V_2 -> V_5 . V_70 = V_65 ;
} else {
F_3 ( V_2 , L_15 ) ;
}
}
void F_9 ( struct V_1 * V_2 )
{
struct V_71 * V_7 = & V_2 -> V_5 . V_7 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_3 V_17 = V_2 -> V_17 ;
bool V_72 = false ;
int V_60 ;
T_1 V_70 ;
F_14 ( V_2 , L_7 , V_2 -> V_17 ) ;
if ( V_7 -> V_73 && V_17 >= V_7 -> V_74 ) {
F_1 ( V_2 ) ;
return;
}
if ( V_7 -> V_73 &&
V_17 <= V_7 -> V_14 ) {
F_7 ( V_2 ) ;
return;
}
if ( V_7 -> V_75 ) {
if ( ! V_4 -> V_12 &&
V_17 >= V_7 -> V_76 ) {
F_14 ( V_2 , L_16 ) ;
V_4 -> V_12 = true ;
F_47 (
V_2 -> V_77 , V_78 ,
F_36 , V_2 ) ;
V_72 = true ;
} else if ( V_4 -> V_12 &&
V_17 <= V_7 -> V_79 ) {
F_14 ( V_2 , L_17 ) ;
V_4 -> V_12 = false ;
F_47 (
V_2 -> V_77 , V_78 ,
F_36 , V_2 ) ;
}
}
if ( V_7 -> V_80 ) {
if ( V_17 >= V_7 -> V_81 ) {
F_38 ( V_2 , true ) ;
V_72 = true ;
} else if ( V_17 <= V_7 -> V_82 ) {
F_38 ( V_2 , false ) ;
}
}
if ( V_7 -> V_83 ) {
V_70 = V_4 -> V_69 ;
for ( V_60 = 0 ; V_60 < V_84 ; V_60 ++ ) {
if ( V_17 < V_7 -> V_70 [ V_60 ] . V_17 )
break;
V_70 = F_45 ( V_4 -> V_69 ,
V_7 -> V_70 [ V_60 ] . V_65 ) ;
}
if ( V_70 != V_4 -> V_69 )
V_72 = true ;
if ( V_4 -> V_70 != V_70 )
F_44 ( V_2 , V_70 ) ;
}
if ( ! V_4 -> V_11 && V_72 ) {
F_48 ( V_2 ,
L_18 ) ;
V_4 -> V_11 = true ;
} else if ( V_4 -> V_11 && ! V_4 -> V_12 &&
V_4 -> V_70 == V_4 -> V_69 &&
V_17 <= V_7 -> V_82 ) {
F_48 ( V_2 ,
L_19 ) ;
V_4 -> V_11 = false ;
}
}
void F_49 ( struct V_1 * V_2 , T_1 V_69 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_14 ( V_2 , L_20 ) ;
if ( V_2 -> V_85 -> V_86 )
V_4 -> V_7 = * V_2 -> V_85 -> V_86 ;
else
V_4 -> V_7 = V_87 ;
V_4 -> V_11 = false ;
V_4 -> V_12 = false ;
V_4 -> V_69 = V_69 ;
F_50 ( & V_4 -> V_14 , F_28 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_5 . V_14 ) ;
F_14 ( V_2 , L_21 ) ;
}
