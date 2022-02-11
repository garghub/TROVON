static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
if ( V_6 -> V_2 -> V_9 ) {
V_8 = V_2 -> V_10 [ F_2 ( V_6 -> V_2 -> V_9 ) ] ;
if ( F_3 ( ! V_8 ) )
return;
V_8 -> V_11 = true ;
}
if ( V_4 -> V_9 ) {
V_8 =
V_2 -> V_10 [ F_2 ( V_4 -> V_9 ) ] ;
if ( F_3 ( ! V_8 ) )
return;
V_8 -> V_11 = true ;
}
}
static struct V_12 *
F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_14 -> V_19 ;
struct V_20 * V_21 ;
F_3 ( ! F_5 ( & V_18 -> V_22 ) ) ;
F_6 (connector, &config->connector_list, head) {
if ( V_21 -> V_2 -> V_23 != V_16 )
continue;
return V_21 -> V_2 -> V_9 ;
}
return NULL ;
}
static int
F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_12 * V_24 )
{
struct V_17 * V_18 = & V_2 -> V_14 -> V_19 ;
struct V_7 * V_8 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
int V_27 ;
F_3 ( ! F_5 ( & V_18 -> V_22 ) ) ;
F_8 ( L_1 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ,
V_24 -> V_28 . V_29 ) ;
V_8 = F_9 ( V_2 , V_24 ) ;
if ( F_10 ( V_8 ) )
return F_11 ( V_8 ) ;
V_8 -> V_31 = true ;
F_6 (connector, &config->connector_list, head) {
if ( V_21 -> V_2 -> V_23 != V_16 )
continue;
F_8 ( L_2 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
V_26 = F_12 ( V_2 ,
V_21 ) ;
if ( F_10 ( V_26 ) )
return F_11 ( V_26 ) ;
V_27 = F_13 ( V_26 , NULL ) ;
if ( V_27 )
return V_27 ;
V_26 -> V_23 = NULL ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , int V_32 )
{
struct V_33 * V_34 ;
struct V_15 * V_35 ;
struct V_12 * V_24 ;
struct V_20 * V_21 ;
struct V_25 * V_26 ;
struct V_7 * V_8 ;
int V_36 , V_27 ;
V_21 = V_2 -> V_37 [ V_32 ] ;
V_26 = V_2 -> V_38 [ V_32 ] ;
if ( ! V_21 )
return 0 ;
F_8 ( L_3 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
if ( V_21 -> V_2 -> V_9 != V_26 -> V_9 ) {
if ( V_21 -> V_2 -> V_9 ) {
V_36 = F_2 ( V_21 -> V_2 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_36 ] ;
V_8 -> V_31 = true ;
}
if ( V_26 -> V_9 ) {
V_36 = F_2 ( V_26 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_36 ] ;
V_8 -> V_31 = true ;
}
}
if ( ! V_26 -> V_9 ) {
F_8 ( L_4 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
V_26 -> V_23 = NULL ;
return 0 ;
}
V_34 = V_21 -> V_39 ;
V_35 = V_34 -> V_23 ( V_21 ) ;
if ( ! V_35 ) {
F_8 ( L_5 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
return - V_40 ;
}
if ( V_35 == V_26 -> V_23 ) {
F_8 ( L_6 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ,
V_35 -> V_28 . V_29 ,
V_35 -> V_30 ,
V_26 -> V_9 -> V_28 . V_29 ) ;
return 0 ;
}
V_24 = F_4 ( V_2 -> V_14 ,
V_35 ) ;
if ( V_24 ) {
V_27 = F_7 ( V_2 , V_35 , V_24 ) ;
if ( V_27 ) {
F_8 ( L_7 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ) ;
return V_27 ;
}
}
V_26 -> V_23 = V_35 ;
V_36 = F_2 ( V_26 -> V_9 ) ;
V_8 = V_2 -> V_10 [ V_36 ] ;
V_8 -> V_31 = true ;
F_8 ( L_8 ,
V_21 -> V_28 . V_29 ,
V_21 -> V_30 ,
V_35 -> V_28 . V_29 ,
V_35 -> V_30 ,
V_26 -> V_9 -> V_28 . V_29 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 )
{
int V_41 = V_2 -> V_14 -> V_19 . V_42 ;
struct V_7 * V_8 ;
struct V_25 * V_43 ;
int V_44 ;
bool V_27 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_8 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_8 || ! V_8 -> V_31 )
continue;
F_16 ( & V_8 -> V_45 , & V_8 -> V_46 ) ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_47 ; V_44 ++ ) {
struct V_48 * V_34 ;
struct V_15 * V_16 ;
V_43 = V_2 -> V_38 [ V_44 ] ;
if ( ! V_43 )
continue;
F_3 ( ! ! V_43 -> V_23 != ! ! V_43 -> V_9 ) ;
if ( ! V_43 -> V_9 || ! V_43 -> V_23 )
continue;
V_8 =
V_2 -> V_10 [ F_2 ( V_43 -> V_9 ) ] ;
V_16 = V_43 -> V_23 ;
V_34 = V_16 -> V_39 ;
if ( V_16 -> V_49 && V_16 -> V_49 -> V_34 -> F_15 ) {
V_27 = V_16 -> V_49 -> V_34 -> F_15 (
V_16 -> V_49 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_27 ) {
F_8 ( L_9 ) ;
return - V_40 ;
}
}
V_27 = V_34 -> F_15 ( V_16 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_27 ) {
F_8 ( L_10 ,
V_16 -> V_28 . V_29 , V_16 -> V_30 ) ;
return - V_40 ;
}
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_50 * V_34 ;
struct V_12 * V_9 ;
V_8 = V_2 -> V_10 [ V_44 ] ;
V_9 = V_2 -> V_51 [ V_44 ] ;
if ( ! V_8 || ! V_8 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
V_27 = V_34 -> F_15 ( V_9 , & V_8 -> V_46 ,
& V_8 -> V_45 ) ;
if ( ! V_27 ) {
F_8 ( L_11 ,
V_9 -> V_28 . V_29 ) ;
return - V_40 ;
}
}
return 0 ;
}
static int
F_17 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_41 = V_14 -> V_19 . V_42 ;
struct V_12 * V_9 ;
struct V_7 * V_8 ;
int V_44 , V_27 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_9 = V_2 -> V_51 [ V_44 ] ;
V_8 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_9 )
continue;
if ( ! F_18 ( & V_9 -> V_2 -> V_46 , & V_8 -> V_46 ) ) {
F_8 ( L_12 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_31 = true ;
}
if ( V_9 -> V_2 -> V_52 != V_8 -> V_52 ) {
F_8 ( L_13 ,
V_9 -> V_28 . V_29 ) ;
V_8 -> V_31 = true ;
}
}
for ( V_44 = 0 ; V_44 < V_2 -> V_47 ; V_44 ++ ) {
V_27 = F_14 ( V_2 , V_44 ) ;
if ( V_27 )
return V_27 ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
int V_53 ;
V_9 = V_2 -> V_51 [ V_44 ] ;
V_8 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_9 || ! V_8 -> V_31 )
continue;
F_8 ( L_14 ,
V_9 -> V_28 . V_29 ,
V_8 -> V_52 ? 'y' : 'n' ) ;
V_27 = F_19 ( V_2 , V_9 ) ;
if ( V_27 != 0 )
return V_27 ;
V_53 = F_20 ( V_2 ,
V_9 ) ;
if ( V_8 -> V_52 != ! ! V_53 ) {
F_8 ( L_15 ,
V_9 -> V_28 . V_29 ) ;
return - V_40 ;
}
}
return F_15 ( V_2 ) ;
}
int F_21 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_54 = V_14 -> V_19 . V_55 ;
int V_41 = V_14 -> V_19 . V_42 ;
int V_44 , V_27 = 0 ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
struct V_56 * V_34 ;
struct V_5 * V_6 = V_2 -> V_57 [ V_44 ] ;
struct V_3 * V_4 = V_2 -> V_58 [ V_44 ] ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
F_1 ( V_2 , V_4 , V_6 ) ;
if ( ! V_34 || ! V_34 -> V_59 )
continue;
V_27 = V_34 -> V_59 ( V_6 , V_4 ) ;
if ( V_27 ) {
F_8 ( L_16 ,
V_6 -> V_28 . V_29 ) ;
return V_27 ;
}
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_50 * V_34 ;
struct V_12 * V_9 = V_2 -> V_51 [ V_44 ] ;
if ( ! V_9 )
continue;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_59 )
continue;
V_27 = V_34 -> V_59 ( V_9 , V_2 -> V_10 [ V_44 ] ) ;
if ( V_27 ) {
F_8 ( L_17 ,
V_9 -> V_28 . V_29 ) ;
return V_27 ;
}
}
V_27 = F_17 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
return V_27 ;
}
static void
F_22 ( struct V_13 * V_14 , struct V_1 * V_60 )
{
int V_41 = V_60 -> V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_60 -> V_47 ; V_44 ++ ) {
struct V_25 * V_61 ;
struct V_20 * V_21 ;
struct V_48 * V_34 ;
struct V_15 * V_16 ;
V_61 = V_60 -> V_38 [ V_44 ] ;
V_21 = V_60 -> V_37 [ V_44 ] ;
if ( ! V_61 || ! V_61 -> V_9 )
continue;
V_16 = V_61 -> V_23 ;
if ( F_3 ( ! V_16 ) )
continue;
V_34 = V_16 -> V_39 ;
if ( V_16 -> V_49 )
V_16 -> V_49 -> V_34 -> V_62 ( V_16 -> V_49 ) ;
if ( V_21 -> V_2 -> V_9 )
V_34 -> V_63 ( V_16 ) ;
else if ( V_34 -> V_62 )
V_34 -> V_62 ( V_16 ) ;
else
V_34 -> V_64 ( V_16 , V_65 ) ;
if ( V_16 -> V_49 )
V_16 -> V_49 -> V_34 -> V_66 ( V_16 -> V_49 ) ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_50 * V_34 ;
struct V_12 * V_9 ;
V_9 = V_60 -> V_51 [ V_44 ] ;
if ( ! V_9 || ! V_9 -> V_2 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_52 )
V_34 -> V_63 ( V_9 ) ;
else if ( V_34 -> V_62 )
V_34 -> V_62 ( V_9 ) ;
else
V_34 -> V_64 ( V_9 , V_65 ) ;
}
}
static void
F_23 ( struct V_13 * V_14 , struct V_1 * V_60 )
{
int V_41 = V_60 -> V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_60 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
V_21 = V_60 -> V_37 [ V_44 ] ;
if ( ! V_21 || ! V_21 -> V_16 )
continue;
F_3 ( ! V_21 -> V_16 -> V_9 ) ;
V_21 -> V_16 -> V_9 = NULL ;
V_21 -> V_16 = NULL ;
}
for ( V_44 = 0 ; V_44 < V_60 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
V_21 = V_60 -> V_37 [ V_44 ] ;
if ( ! V_21 || ! V_21 -> V_2 -> V_9 )
continue;
if ( F_3 ( ! V_21 -> V_2 -> V_23 ) )
continue;
V_21 -> V_16 = V_21 -> V_2 -> V_23 ;
V_21 -> V_16 -> V_9 = V_21 -> V_2 -> V_9 ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_12 * V_9 ;
V_9 = V_60 -> V_51 [ V_44 ] ;
if ( ! V_9 )
continue;
V_9 -> V_46 = V_9 -> V_2 -> V_46 ;
V_9 -> V_67 = V_9 -> V_2 -> V_52 ;
V_9 -> V_68 = V_9 -> V_69 -> V_2 -> V_70 >> 16 ;
V_9 -> V_71 = V_9 -> V_69 -> V_2 -> V_72 >> 16 ;
}
}
static void
F_24 ( struct V_13 * V_14 , struct V_1 * V_60 )
{
int V_41 = V_60 -> V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_50 * V_34 ;
struct V_12 * V_9 ;
V_9 = V_60 -> V_51 [ V_44 ] ;
if ( ! V_9 || ! V_9 -> V_2 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_52 )
V_34 -> V_73 ( V_9 ) ;
}
for ( V_44 = 0 ; V_44 < V_60 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
struct V_7 * V_74 ;
struct V_48 * V_34 ;
struct V_15 * V_16 ;
struct V_75 * V_46 , * V_45 ;
V_21 = V_60 -> V_37 [ V_44 ] ;
if ( ! V_21 || ! V_21 -> V_2 -> V_23 )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
V_74 = V_21 -> V_2 -> V_9 -> V_2 ;
V_46 = & V_74 -> V_46 ;
V_45 = & V_74 -> V_45 ;
V_34 -> V_76 ( V_16 , V_46 , V_45 ) ;
if ( V_16 -> V_49 && V_16 -> V_49 -> V_34 -> V_76 )
V_16 -> V_49 -> V_34 -> V_76 ( V_16 -> V_49 ,
V_46 , V_45 ) ;
}
}
void F_25 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
F_22 ( V_14 , V_2 ) ;
F_23 ( V_14 , V_2 ) ;
F_24 ( V_14 , V_2 ) ;
}
void F_26 ( struct V_13 * V_14 ,
struct V_1 * V_60 )
{
int V_41 = V_60 -> V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_50 * V_34 ;
struct V_12 * V_9 ;
V_9 = V_60 -> V_51 [ V_44 ] ;
if ( ! V_9 || ! V_9 -> V_2 -> V_31 )
continue;
V_34 = V_9 -> V_39 ;
if ( V_9 -> V_2 -> V_52 )
V_34 -> V_77 ( V_9 ) ;
}
for ( V_44 = 0 ; V_44 < V_60 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
struct V_48 * V_34 ;
struct V_15 * V_16 ;
V_21 = V_60 -> V_37 [ V_44 ] ;
if ( ! V_21 || ! V_21 -> V_2 -> V_23 )
continue;
V_16 = V_21 -> V_2 -> V_23 ;
V_34 = V_16 -> V_39 ;
if ( V_16 -> V_49 )
V_16 -> V_49 -> V_34 -> V_78 ( V_16 -> V_49 ) ;
V_34 -> V_77 ( V_16 ) ;
if ( V_16 -> V_49 )
V_16 -> V_49 -> V_34 -> V_52 ( V_16 -> V_49 ) ;
}
}
static void F_27 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_54 = V_14 -> V_19 . V_55 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
struct V_5 * V_6 = V_2 -> V_57 [ V_44 ] ;
if ( ! V_6 || ! V_6 -> V_2 -> V_79 )
continue;
F_3 ( ! V_6 -> V_2 -> V_80 ) ;
F_28 ( V_6 -> V_2 -> V_79 , false ) ;
F_29 ( V_6 -> V_2 -> V_79 ) ;
V_6 -> V_2 -> V_79 = NULL ;
}
}
static bool F_30 ( struct V_13 * V_14 ,
struct V_1 * V_60 ,
struct V_12 * V_9 )
{
struct V_5 * V_6 ;
struct V_3 * V_81 ;
int V_54 = V_60 -> V_14 -> V_19 . V_55 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
V_6 = V_60 -> V_57 [ V_44 ] ;
V_81 = V_60 -> V_58 [ V_44 ] ;
if ( ! V_6 )
continue;
if ( V_6 -> V_2 -> V_9 != V_9 &&
V_81 -> V_9 != V_9 )
continue;
if ( V_6 -> V_2 -> V_80 != V_81 -> V_80 )
return true ;
}
return false ;
}
void
F_31 ( struct V_13 * V_14 ,
struct V_1 * V_60 )
{
struct V_12 * V_9 ;
struct V_7 * V_82 ;
int V_41 = V_60 -> V_14 -> V_19 . V_42 ;
int V_44 , V_27 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_9 = V_60 -> V_51 [ V_44 ] ;
V_82 = V_60 -> V_10 [ V_44 ] ;
if ( ! V_9 )
continue;
V_82 -> V_52 = false ;
if ( ! V_9 -> V_2 -> V_52 )
continue;
if ( ! F_30 ( V_14 , V_60 , V_9 ) )
continue;
V_27 = F_32 ( V_9 ) ;
if ( V_27 != 0 )
continue;
V_82 -> V_52 = true ;
V_82 -> V_83 = F_33 ( V_14 , V_44 ) ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
V_9 = V_60 -> V_51 [ V_44 ] ;
V_82 = V_60 -> V_10 [ V_44 ] ;
if ( ! V_9 || ! V_82 -> V_52 )
continue;
V_27 = F_34 ( V_14 -> V_84 [ V_44 ] . V_85 ,
V_82 -> V_83 !=
F_33 ( V_14 , V_44 ) ,
F_35 ( 50 ) ) ;
F_36 ( V_9 ) ;
}
}
int F_37 ( struct V_13 * V_14 ,
struct V_1 * V_2 ,
bool V_86 )
{
int V_27 ;
if ( V_86 )
return - V_87 ;
V_27 = F_38 ( V_14 , V_2 ) ;
if ( V_27 )
return V_27 ;
F_39 ( V_14 , V_2 ) ;
F_27 ( V_14 , V_2 ) ;
F_25 ( V_14 , V_2 ) ;
F_40 ( V_14 , V_2 ) ;
F_26 ( V_14 , V_2 ) ;
F_31 ( V_14 , V_2 ) ;
F_41 ( V_14 , V_2 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
int F_38 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_54 = V_14 -> V_19 . V_55 ;
int V_27 , V_44 ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
struct V_56 * V_34 ;
struct V_5 * V_6 = V_2 -> V_57 [ V_44 ] ;
struct V_88 * V_80 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_80 = V_2 -> V_58 [ V_44 ] -> V_80 ;
if ( V_80 && V_34 -> V_89 ) {
V_27 = V_34 -> V_89 ( V_6 , V_80 ) ;
if ( V_27 )
goto V_90;
}
}
return 0 ;
V_90:
for ( V_44 -- ; V_44 >= 0 ; V_44 -- ) {
struct V_56 * V_34 ;
struct V_5 * V_6 = V_2 -> V_57 [ V_44 ] ;
struct V_88 * V_80 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_80 = V_2 -> V_58 [ V_44 ] -> V_80 ;
if ( V_80 && V_34 -> V_91 )
V_34 -> V_91 ( V_6 , V_80 ) ;
}
return V_27 ;
}
void F_40 ( struct V_13 * V_14 ,
struct V_1 * V_60 )
{
int V_54 = V_14 -> V_19 . V_55 ;
int V_41 = V_14 -> V_19 . V_42 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_50 * V_34 ;
struct V_12 * V_9 = V_60 -> V_51 [ V_44 ] ;
if ( ! V_9 )
continue;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_92 )
continue;
V_34 -> V_92 ( V_9 ) ;
}
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
struct V_56 * V_34 ;
struct V_5 * V_6 = V_60 -> V_57 [ V_44 ] ;
struct V_3 * V_81 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_93 )
continue;
V_81 = V_60 -> V_58 [ V_44 ] ;
V_34 -> V_93 ( V_6 , V_81 ) ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_50 * V_34 ;
struct V_12 * V_9 = V_60 -> V_51 [ V_44 ] ;
if ( ! V_9 )
continue;
V_34 = V_9 -> V_39 ;
if ( ! V_34 || ! V_34 -> V_94 )
continue;
V_34 -> V_94 ( V_9 ) ;
}
}
void F_41 ( struct V_13 * V_14 ,
struct V_1 * V_60 )
{
int V_54 = V_14 -> V_19 . V_55 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
struct V_56 * V_34 ;
struct V_5 * V_6 = V_60 -> V_57 [ V_44 ] ;
struct V_88 * V_95 ;
if ( ! V_6 )
continue;
V_34 = V_6 -> V_39 ;
V_95 = V_60 -> V_58 [ V_44 ] -> V_80 ;
if ( V_95 && V_34 -> V_91 )
V_34 -> V_91 ( V_6 , V_95 ) ;
}
}
void F_39 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_14 -> V_19 . V_47 ; V_44 ++ ) {
struct V_20 * V_21 = V_2 -> V_37 [ V_44 ] ;
if ( ! V_21 )
continue;
V_21 -> V_2 -> V_2 = V_2 ;
F_43 ( V_2 -> V_38 [ V_44 ] , V_21 -> V_2 ) ;
V_21 -> V_2 -> V_2 = NULL ;
}
for ( V_44 = 0 ; V_44 < V_14 -> V_19 . V_42 ; V_44 ++ ) {
struct V_12 * V_9 = V_2 -> V_51 [ V_44 ] ;
if ( ! V_9 )
continue;
V_9 -> V_2 -> V_2 = V_2 ;
F_43 ( V_2 -> V_10 [ V_44 ] , V_9 -> V_2 ) ;
V_9 -> V_2 -> V_2 = NULL ;
}
for ( V_44 = 0 ; V_44 < V_14 -> V_19 . V_55 ; V_44 ++ ) {
struct V_5 * V_6 = V_2 -> V_57 [ V_44 ] ;
if ( ! V_6 )
continue;
V_6 -> V_2 -> V_2 = V_2 ;
F_43 ( V_2 -> V_58 [ V_44 ] , V_6 -> V_2 ) ;
V_6 -> V_2 -> V_2 = NULL ;
}
}
int F_44 ( struct V_5 * V_6 ,
struct V_12 * V_9 ,
struct V_88 * V_80 ,
int V_96 , int V_97 ,
unsigned int V_98 , unsigned int V_99 ,
T_1 V_70 , T_1 V_72 ,
T_1 V_100 , T_1 V_101 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_45 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_103 = F_46 ( V_9 ) ;
V_104:
V_4 = F_47 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_90;
}
V_27 = F_48 ( V_2 , V_6 , V_9 ) ;
if ( V_27 != 0 )
goto V_90;
F_49 ( V_4 , V_80 ) ;
V_4 -> V_96 = V_96 ;
V_4 -> V_97 = V_97 ;
V_4 -> V_99 = V_99 ;
V_4 -> V_98 = V_98 ;
V_4 -> V_70 = V_70 ;
V_4 -> V_72 = V_72 ;
V_4 -> V_101 = V_101 ;
V_4 -> V_100 = V_100 ;
V_27 = F_50 ( V_2 ) ;
if ( V_27 != 0 )
goto V_90;
return 0 ;
V_90:
if ( V_27 == - V_105 )
goto V_106;
F_42 ( V_2 ) ;
return V_27 ;
V_106:
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_6 -> V_95 = V_6 -> V_80 ;
goto V_104;
}
int F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
if ( ! V_6 -> V_9 )
return 0 ;
V_2 = F_45 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_103 = F_46 ( V_6 -> V_9 ) ;
V_104:
V_4 = F_47 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_90;
}
V_27 = F_48 ( V_2 , V_6 , NULL ) ;
if ( V_27 != 0 )
goto V_90;
F_49 ( V_4 , NULL ) ;
V_4 -> V_96 = 0 ;
V_4 -> V_97 = 0 ;
V_4 -> V_99 = 0 ;
V_4 -> V_98 = 0 ;
V_4 -> V_70 = 0 ;
V_4 -> V_72 = 0 ;
V_4 -> V_101 = 0 ;
V_4 -> V_100 = 0 ;
V_27 = F_50 ( V_2 ) ;
if ( V_27 != 0 )
goto V_90;
return 0 ;
V_90:
if ( V_27 == - V_105 )
goto V_106;
F_42 ( V_2 ) ;
return V_27 ;
V_106:
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_6 -> V_95 = V_6 -> V_80 ;
goto V_104;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
struct V_13 * V_14 = V_108 -> V_9 -> V_14 ;
struct V_25 * V_43 ;
int V_41 = V_2 -> V_14 -> V_19 . V_42 ;
int V_27 , V_44 , V_109 ;
V_27 = F_55 ( & V_14 -> V_19 . V_22 ,
V_2 -> V_103 ) ;
if ( V_27 )
return V_27 ;
for ( V_44 = 0 ; V_44 < V_108 -> V_53 ; V_44 ++ ) {
V_43 = F_12 ( V_2 ,
V_108 -> V_37 [ V_44 ] ) ;
if ( F_10 ( V_43 ) )
return F_11 ( V_43 ) ;
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_12 * V_9 = V_2 -> V_51 [ V_44 ] ;
if ( ! V_9 )
continue;
V_27 = F_19 ( V_2 , V_9 ) ;
if ( V_27 )
return V_27 ;
}
for ( V_44 = 0 ; V_44 < V_2 -> V_47 ; V_44 ++ ) {
struct V_20 * V_21 ;
V_21 = V_2 -> V_37 [ V_44 ] ;
V_43 = V_2 -> V_38 [ V_44 ] ;
if ( ! V_21 )
continue;
if ( V_43 -> V_9 == V_108 -> V_9 ) {
V_27 = F_13 ( V_43 ,
NULL ) ;
if ( V_27 )
return V_27 ;
}
for ( V_109 = 0 ; V_109 < V_108 -> V_53 ; V_109 ++ ) {
if ( V_108 -> V_37 [ V_109 ] == V_21 ) {
V_27 = F_13 ( V_43 ,
V_108 -> V_9 ) ;
if ( V_27 )
return V_27 ;
break;
}
}
}
for ( V_44 = 0 ; V_44 < V_41 ; V_44 ++ ) {
struct V_12 * V_9 = V_2 -> V_51 [ V_44 ] ;
struct V_7 * V_8 = V_2 -> V_10 [ V_44 ] ;
if ( ! V_9 )
continue;
if ( V_9 == V_108 -> V_9 )
continue;
V_8 -> V_52 =
F_20 ( V_2 , V_9 ) ;
}
return 0 ;
}
int F_56 ( struct V_107 * V_108 )
{
struct V_1 * V_2 ;
struct V_12 * V_9 = V_108 -> V_9 ;
struct V_7 * V_8 ;
struct V_3 * V_110 ;
int V_27 = 0 ;
V_2 = F_45 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_103 = F_46 ( V_9 ) ;
V_104:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_90;
}
V_110 = F_47 ( V_2 , V_9 -> V_69 ) ;
if ( F_10 ( V_110 ) ) {
V_27 = F_11 ( V_110 ) ;
goto V_90;
}
if ( ! V_108 -> V_46 ) {
F_3 ( V_108 -> V_80 ) ;
F_3 ( V_108 -> V_53 ) ;
V_8 -> V_52 = false ;
V_27 = F_48 ( V_2 , V_9 -> V_69 , NULL ) ;
if ( V_27 != 0 )
goto V_90;
F_49 ( V_110 , NULL ) ;
goto V_77;
}
F_3 ( ! V_108 -> V_80 ) ;
F_3 ( ! V_108 -> V_53 ) ;
V_8 -> V_52 = true ;
F_16 ( & V_8 -> V_46 , V_108 -> V_46 ) ;
V_27 = F_48 ( V_2 , V_9 -> V_69 , V_9 ) ;
if ( V_27 != 0 )
goto V_90;
F_49 ( V_110 , V_108 -> V_80 ) ;
V_110 -> V_96 = 0 ;
V_110 -> V_97 = 0 ;
V_110 -> V_99 = V_108 -> V_46 -> V_111 ;
V_110 -> V_98 = V_108 -> V_46 -> V_112 ;
V_110 -> V_70 = V_108 -> V_68 << 16 ;
V_110 -> V_72 = V_108 -> V_71 << 16 ;
V_110 -> V_101 = V_108 -> V_46 -> V_111 << 16 ;
V_110 -> V_100 = V_108 -> V_46 -> V_112 << 16 ;
V_77:
V_27 = F_54 ( V_2 , V_108 ) ;
if ( V_27 )
goto V_90;
V_27 = F_50 ( V_2 ) ;
if ( V_27 != 0 )
goto V_90;
return 0 ;
V_90:
if ( V_27 == - V_105 )
goto V_106;
F_42 ( V_2 ) ;
return V_27 ;
V_106:
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_9 -> V_69 -> V_95 = V_9 -> V_69 -> V_80 ;
goto V_104;
}
int
F_57 ( struct V_12 * V_9 ,
struct V_113 * V_114 ,
T_2 V_115 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
V_2 = F_45 ( V_9 -> V_14 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_103 = V_9 -> V_14 -> V_19 . V_103 ;
V_104:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_90;
}
V_27 = V_9 -> V_34 -> V_116 ( V_9 , V_8 ,
V_114 , V_115 ) ;
if ( V_27 )
goto V_90;
V_27 = F_50 ( V_2 ) ;
if ( V_27 != 0 )
goto V_90;
return 0 ;
V_90:
if ( V_27 == - V_105 )
goto V_106;
F_42 ( V_2 ) ;
return V_27 ;
V_106:
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
goto V_104;
}
int
F_58 ( struct V_5 * V_6 ,
struct V_113 * V_114 ,
T_2 V_115 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_27 = 0 ;
V_2 = F_45 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_103 = V_6 -> V_14 -> V_19 . V_103 ;
V_104:
V_4 = F_47 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_90;
}
V_27 = V_6 -> V_34 -> V_116 ( V_6 , V_4 ,
V_114 , V_115 ) ;
if ( V_27 )
goto V_90;
V_27 = F_50 ( V_2 ) ;
if ( V_27 != 0 )
goto V_90;
return 0 ;
V_90:
if ( V_27 == - V_105 )
goto V_106;
F_42 ( V_2 ) ;
return V_27 ;
V_106:
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
goto V_104;
}
int
F_59 ( struct V_20 * V_21 ,
struct V_113 * V_114 ,
T_2 V_115 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
int V_27 = 0 ;
V_2 = F_45 ( V_21 -> V_14 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_103 = V_21 -> V_14 -> V_19 . V_103 ;
V_104:
V_26 = F_12 ( V_2 , V_21 ) ;
if ( F_10 ( V_26 ) ) {
V_27 = F_11 ( V_26 ) ;
goto V_90;
}
V_27 = V_21 -> V_34 -> V_116 ( V_21 , V_26 ,
V_114 , V_115 ) ;
if ( V_27 )
goto V_90;
V_27 = F_50 ( V_2 ) ;
if ( V_27 != 0 )
goto V_90;
return 0 ;
V_90:
if ( V_27 == - V_105 )
goto V_106;
F_42 ( V_2 ) ;
return V_27 ;
V_106:
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
goto V_104;
}
int F_60 ( struct V_12 * V_9 ,
struct V_88 * V_80 ,
struct V_117 * V_118 ,
T_1 V_119 )
{
struct V_5 * V_6 = V_9 -> V_69 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_7 * V_8 ;
int V_27 = 0 ;
if ( V_119 & V_120 )
return - V_40 ;
V_2 = F_45 ( V_6 -> V_14 ) ;
if ( ! V_2 )
return - V_102 ;
V_2 -> V_103 = F_46 ( V_9 ) ;
V_104:
V_8 = F_9 ( V_2 , V_9 ) ;
if ( F_10 ( V_8 ) ) {
V_27 = F_11 ( V_8 ) ;
goto V_90;
}
V_8 -> V_118 = V_118 ;
V_4 = F_47 ( V_2 , V_6 ) ;
if ( F_10 ( V_4 ) ) {
V_27 = F_11 ( V_4 ) ;
goto V_90;
}
V_27 = F_48 ( V_2 , V_6 , V_9 ) ;
if ( V_27 != 0 )
goto V_90;
F_49 ( V_4 , V_80 ) ;
V_27 = F_61 ( V_2 ) ;
if ( V_27 != 0 )
goto V_90;
V_6 -> V_80 = V_6 -> V_2 -> V_80 ;
return 0 ;
V_90:
if ( V_27 == - V_105 )
goto V_106;
F_42 ( V_2 ) ;
return V_27 ;
V_106:
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_6 -> V_95 = V_6 -> V_80 ;
goto V_104;
}
void F_62 ( struct V_12 * V_9 )
{
F_63 ( V_9 -> V_2 ) ;
V_9 -> V_2 = F_64 ( sizeof( * V_9 -> V_2 ) , V_121 ) ;
}
struct V_7 *
F_65 ( struct V_12 * V_9 )
{
struct V_7 * V_2 ;
if ( F_3 ( ! V_9 -> V_2 ) )
return NULL ;
V_2 = F_66 ( V_9 -> V_2 , sizeof( * V_9 -> V_2 ) , V_121 ) ;
if ( V_2 ) {
V_2 -> V_31 = false ;
V_2 -> V_11 = false ;
V_2 -> V_118 = NULL ;
}
return V_2 ;
}
void F_67 ( struct V_12 * V_9 ,
struct V_7 * V_2 )
{
F_63 ( V_2 ) ;
}
void F_68 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 && V_6 -> V_2 -> V_80 )
F_69 ( V_6 -> V_2 -> V_80 ) ;
F_63 ( V_6 -> V_2 ) ;
V_6 -> V_2 = F_64 ( sizeof( * V_6 -> V_2 ) , V_121 ) ;
}
struct V_3 *
F_70 ( struct V_5 * V_6 )
{
struct V_3 * V_2 ;
if ( F_3 ( ! V_6 -> V_2 ) )
return NULL ;
V_2 = F_66 ( V_6 -> V_2 , sizeof( * V_6 -> V_2 ) , V_121 ) ;
if ( V_2 && V_2 -> V_80 )
F_71 ( V_2 -> V_80 ) ;
return V_2 ;
}
void F_72 ( struct V_5 * V_6 ,
struct V_3 * V_2 )
{
if ( V_2 -> V_80 )
F_69 ( V_2 -> V_80 ) ;
F_63 ( V_2 ) ;
}
void F_73 ( struct V_20 * V_21 )
{
F_63 ( V_21 -> V_2 ) ;
V_21 -> V_2 = F_64 ( sizeof( * V_21 -> V_2 ) , V_121 ) ;
}
struct V_25 *
F_74 ( struct V_20 * V_21 )
{
if ( F_3 ( ! V_21 -> V_2 ) )
return NULL ;
return F_66 ( V_21 -> V_2 , sizeof( * V_21 -> V_2 ) , V_121 ) ;
}
void F_75 ( struct V_20 * V_21 ,
struct V_25 * V_2 )
{
F_63 ( V_2 ) ;
}
