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
static bool F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 , void * V_16 )
{
struct V_1 * V_2 =
F_9 ( V_13 , struct V_1 , V_13 ) ;
int * V_17 = V_16 ;
struct V_18 * V_19 ;
int V_20 = F_10 ( V_15 ) ;
if ( F_11 ( V_20 != sizeof( * V_19 ) ) ) {
F_3 ( V_2 , L_3 ) ;
return true ;
}
V_19 = ( void * ) V_15 -> V_16 ;
* V_17 = F_12 ( V_19 -> V_17 ) ;
if ( F_11 ( * V_17 < 0 ) )
* V_17 = 0 ;
F_13 ( V_2 , L_4 , * V_17 ) ;
return true ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_21 V_22 = {
. V_23 = F_15 ( V_24 ) ,
} ;
return F_16 ( V_2 , V_25 , 0 ,
sizeof( V_22 ) , & V_22 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_26 V_27 ;
static const T_2 V_28 [] = { V_29 } ;
int V_30 , V_17 ;
F_18 ( & V_2 -> V_31 ) ;
F_19 ( & V_2 -> V_13 , & V_27 ,
V_28 , F_20 ( V_28 ) ,
F_8 , & V_17 ) ;
V_30 = F_14 ( V_2 ) ;
if ( V_30 ) {
F_3 ( V_2 , L_5 , V_30 ) ;
F_21 ( & V_2 -> V_13 , & V_27 ) ;
return V_30 ;
}
V_30 = F_22 ( & V_2 -> V_13 , & V_27 ,
V_32 ) ;
if ( V_30 ) {
F_3 ( V_2 , L_6 ) ;
return V_30 ;
}
return V_17 ;
}
static void F_23 ( struct V_33 * V_34 )
{
struct V_35 * V_36 ;
struct V_1 * V_2 ;
T_1 V_3 ;
T_3 V_17 ;
V_36 = F_9 ( V_34 , struct V_35 , V_10 . V_34 ) ;
V_2 = F_9 ( V_36 , struct V_1 , V_4 ) ;
V_3 = V_36 -> V_5 -> V_6 ;
F_24 ( & V_2 -> V_31 ) ;
if ( F_25 ( V_2 ) )
goto V_37;
if ( F_26 ( V_2 , V_38 ) ) {
F_27 ( V_2 ) ;
goto V_37;
}
V_17 = F_17 ( V_2 ) ;
F_28 ( V_2 , V_38 ) ;
F_27 ( V_2 ) ;
if ( V_17 < 0 )
goto V_37;
F_13 ( V_2 , L_7 , V_17 ) ;
if ( V_17 <= V_36 -> V_5 -> V_10 ) {
F_29 ( & V_2 -> V_31 ) ;
F_7 ( V_2 ) ;
return;
}
V_37:
F_29 ( & V_2 -> V_31 ) ;
F_5 ( & V_2 -> V_4 . V_10 ,
F_30 ( V_3 * V_11 ) ) ;
}
static void F_31 ( void * V_39 , T_2 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = V_39 ;
enum V_43 V_44 ;
F_18 ( & V_2 -> V_31 ) ;
if ( V_2 -> V_4 . V_45 )
V_44 = V_46 ;
else
V_44 = V_47 ;
if ( V_42 -> type != V_48 )
return;
F_32 ( V_2 , V_42 , V_49 , V_44 ) ;
}
static void F_33 ( struct V_1 * V_2 , bool V_50 )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
int V_55 , V_56 ;
for ( V_55 = 0 ; V_55 < V_57 ; V_55 ++ ) {
V_52 = F_34 ( V_2 -> V_58 [ V_55 ] ,
F_35 ( & V_2 -> V_31 ) ) ;
if ( F_36 ( V_52 ) )
continue;
V_54 = F_37 ( V_52 ) ;
if ( V_50 == V_54 -> V_59 )
continue;
V_56 = F_38 ( V_2 , V_54 , V_50 ) ;
if ( V_56 ) {
F_3 ( V_2 , L_8 ,
V_50 ? L_9 : L_10 ) ;
} else {
F_13 ( V_2 , L_11 ,
V_50 ? L_12 : L_13 ) ;
V_54 -> V_59 = V_50 ;
}
}
}
void F_39 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_61 V_22 = {
. V_62 = V_63 ,
. V_20 = { sizeof( T_1 ) , } ,
. V_16 = { & V_60 , } ,
} ;
V_60 = F_40 ( V_60 , V_2 -> V_4 . V_64 ) ;
if ( F_41 ( V_2 , & V_22 ) == 0 ) {
F_13 ( V_2 , L_14 ,
V_60 ) ;
V_2 -> V_4 . V_65 = V_60 ;
} else {
F_3 ( V_2 , L_15 ) ;
}
}
void F_42 ( struct V_1 * V_2 )
{
const struct V_66 * V_5 = V_2 -> V_4 . V_5 ;
struct V_35 * V_36 = & V_2 -> V_4 ;
T_3 V_67 = V_2 -> V_67 ;
bool V_68 = false ;
int V_55 ;
T_1 V_65 ;
F_13 ( V_2 , L_7 , V_2 -> V_67 ) ;
if ( V_5 -> V_69 && V_67 >= V_5 -> V_70 ) {
F_1 ( V_2 ) ;
return;
}
if ( V_5 -> V_69 &&
V_67 <= V_36 -> V_5 -> V_10 ) {
F_7 ( V_2 ) ;
return;
}
if ( V_5 -> V_71 ) {
if ( ! V_36 -> V_45 &&
V_67 >= V_5 -> V_72 ) {
F_13 ( V_2 , L_16 ) ;
V_36 -> V_45 = true ;
F_43 (
V_2 -> V_73 , V_74 ,
F_31 , V_2 ) ;
V_68 = true ;
} else if ( V_36 -> V_45 &&
V_67 <= V_5 -> V_75 ) {
F_13 ( V_2 , L_17 ) ;
V_36 -> V_45 = false ;
F_43 (
V_2 -> V_73 , V_74 ,
F_31 , V_2 ) ;
}
}
if ( V_5 -> V_76 ) {
if ( V_67 >= V_5 -> V_77 ) {
F_33 ( V_2 , true ) ;
V_68 = true ;
} else if ( V_67 <= V_5 -> V_78 ) {
F_33 ( V_2 , false ) ;
}
}
if ( V_5 -> V_79 ) {
V_65 = V_36 -> V_64 ;
for ( V_55 = 0 ; V_55 < V_80 ; V_55 ++ ) {
if ( V_67 < V_5 -> V_65 [ V_55 ] . V_67 )
break;
V_65 = F_40 ( V_36 -> V_64 ,
V_5 -> V_65 [ V_55 ] . V_60 ) ;
}
if ( V_65 != V_36 -> V_64 )
V_68 = true ;
if ( V_36 -> V_65 != V_65 )
F_39 ( V_2 , V_65 ) ;
}
if ( ! V_36 -> V_81 && V_68 ) {
F_44 ( V_2 ,
L_18 ) ;
V_36 -> V_81 = true ;
} else if ( V_36 -> V_81 && ! V_36 -> V_45 &&
V_36 -> V_65 == V_36 -> V_64 &&
V_67 <= V_5 -> V_78 ) {
F_44 ( V_2 ,
L_19 ) ;
V_36 -> V_81 = false ;
}
}
void F_45 ( struct V_1 * V_2 , T_1 V_64 )
{
struct V_35 * V_36 = & V_2 -> V_4 ;
F_13 ( V_2 , L_20 ) ;
if ( V_2 -> V_82 -> V_83 )
V_36 -> V_5 = & V_84 ;
else
V_36 -> V_5 = & V_85 ;
V_36 -> V_81 = false ;
V_36 -> V_64 = V_64 ;
F_46 ( & V_36 -> V_10 , F_23 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_4 . V_10 ) ;
F_13 ( V_2 , L_21 ) ;
}
